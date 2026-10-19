# JKBot engine code

Simulator support for JKBot (an imitation-plus-RL bot): lockstep mode, agent clients and
input injection, the Python bridge, state export and rule-detector signals.

Rules:

- **Agent and bridge code** (`codemp/jkbot/*`) compiles only when CMake's `JKBOT_AGENT` option is
  on (default `OFF`). Every source file here is wrapped in `#ifdef JKBOT_AGENT` from its first
  directive to its last, and any hook added elsewhere in the engine sits inside an
  `#ifdef JKBOT_AGENT` block. Release builds never set the option: an input-injection endpoint in
  a FACEIT client would fall under FACEIT rule §4.3.3.
- **Recording code** (`codemp/jkbot/record/`, e.g. the usercmd logger, and the client self-test)
  records or reports only and has no input endpoint, so it is allowed in release builds. Engine
  hooks into it don't mention jkbot in their names (the guard test flags any jkbot mention outside
  `#ifdef JKBOT_AGENT`, includes of `jkbot/record/` aside).
- Nothing here changes player physics, saber combat or anything else that affects gameplay.

The JKBot repo checks these rules in `training/tests/test_engine_guard.py`.

Own-state prediction (`predict.cpp`, `predict/`): the agent server predicts each agent's
playerState as a human client's cgame does, with the cgame's own `bg_*` movement code built as
the cgame builds it (`_CGAME`, x87 math like Raven's jampgame) into `libjkbpredict.so` next to the
server. The server loads it with `RTLD_LOCAL` and reaches it only through `predict/jkbpredict.h`,
so none of its symbols (Pmove, pm, bgAllAnims...) bind to or from the game module's: the game's
mechanics stay in jampgame. Agent builds only.

Visibility (`visibility.cpp`, `shared/vis.c`): each agent's camera follows its predicted
playerState as the cgame's third-person camera does, and the players in its held snapshot are
tested for visibility (frustum at the rendered FOV, clear sight past MASK_OPAQUE world brushes and
the extra occluding surfaces of measurements/sightsurfaces.json). `shared/` is plain computation
over a playerState and the map's BSP bytes: the agent server builds it, the agent client's cgame
for the visibility probe, and the agent client's demo dump (P2-DM-05).

Client clock and camera in OBS (P1-BR-05): each agent's cl.serverTime (`netsched.cpp`, a port of
CL_SetCGameTime/CL_AdjustTimeDelta at cl_timeNudge 0, equal to the Python reference
`jkbot.features.interp.ClientClock`) is OBS `cg_time`, the time its cgame renders at; the env
interpolates the opponent and picks up sounds there. OBS `view_origin`/`view_angles` are the
agent's camera from the visibility model, where its client hears from (S_Respatialize).

Server commands in OBS (P2-PAR-01, proto 3): the reliable commands each agent's client received
with the snapshot it holds (`netsched.cpp` JKBot_NetCommands), so the env builds match state
(scores, configstrings) from the same inputs as a demo (`training/src/jkbot/features/match.py`).
An agent has no gamestate message, so its link reset captures one: the line `jkbot_gamestate`,
then `cs` lines for serverinfo, CS_LEVEL_START_TIME, CS_CLIENT_DUELISTS and CS_PLAYERS. STEP's
`server_command` runs one console command before the step (the console isn't read in bridge
mode), e.g. `svrecord` for the parity test.

Static-geometry rays (`geometry.cpp`, `shared/rays.c`, P1-ENG-13): after each agent client frame,
rays from the eye of the predicted playerState over a Fibonacci sphere in its yaw frame, each a CM
point trace against the world model only (what blocks movement: solid, playerclip, terrain), so
no player or other entity stops one. Count and length come from config (`jkbot_rays`); the bridge
sends the hit fractions in OBS. `shared/rays.c` takes the trace as a callback, so the client dump
casts the same rays with CM after loading the map's clip model (P2-DM-05).

Demo dump POV (`record/dump.cpp`, P2-DM-05): in the agent client build only (the per-file
`JKBOT_AGENT` define on dump.cpp and the shared sources; the client compiles the server too, so
the macro isn't target-wide), each full-mode snapshot also gets the POV's camera, the players it
sees and the rays, from the snapshot's playerState with the shared code above. A release client's
dump has `"pov":null` in its header.

Throughput timers (`bench.cpp`, P1-BEN-01/02): with `jkbot_bench 1`, each STEP's wall time and
the game frames run are counted, and so is the time spent in Ghoul2: at load the server points
`re` at a copy of the renderer's export table whose `G2API_*` entries time the outermost call and
forward to the renderer's own. Every Ghoul2 call the server makes goes through `re` (the original
module's G_G2_* syscalls, a rebuilt module's import table, SV_Trace's Ghoul2 collision), so the
same timers cover both modules. `jkbot_bench_report` prints and zeroes the counts; the bridge
prints them when the env disconnects.

Visibility probe (`visprobe.c`, P1-M-21): measures the model against renders. It compiles into the
cgame only with `JKBOT_AGENT` (`scripts/build_client.sh --agent`, a measurement build never
shipped), with its cgame hooks inside `#ifdef JKBOT_AGENT`, and acts only during demo playback:
it draws the other player in a flat colour, leaves translucent overlays (saber blades, player
spheres) undrawn, runs the model on each rendered frame and prints the result for the engine's
pixel probe (`record/probe.cpp`) to compare with the frame's pixels.

Think log (`thinklog.cpp`, P2-LBL-01): `jkbot_thinklog <client> <path>` writes every usercmd the
game receives for that client at GAME_CLIENT_THINK, in the client usercmd logger's format
(`record/cmdlog.cpp`), plus a frame record before each GAME_RUN_FRAME: a stock bot's Pmove runs in
the frame on its latest usercmd, an agent's inside GAME_CLIENT_THINK. With it, `svrecord` demos of
stock bots and agents carry exact input labels. In lockstep the server also holds a recorded bot's
next demo snapshot until svs.time moves on (`sv_snapshot.cpp`): SV_Frame runs every STEP there, not
once per server frame as on a dedicated server, which would write each frame's snapshot 4-5 times.
Read only; agent builds only.
