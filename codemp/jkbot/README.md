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
over a playerState and the map's BSP bytes, meant for the client dump too (P2-DM-05); the agent
server builds it, and so does the agent client's cgame for the visibility probe.

Visibility probe (`visprobe.c`, P1-M-21): measures the model against renders. It compiles into the
cgame only with `JKBOT_AGENT` (`scripts/build_client.sh --agent`, a measurement build never
shipped), with its cgame hooks inside `#ifdef JKBOT_AGENT`, and acts only during demo playback:
it draws the other player in a flat colour, leaves translucent overlays (saber blades, player
spheres) undrawn, runs the model on each rendered frame and prints the result for the engine's
pixel probe (`record/probe.cpp`) to compare with the frame's pixels.
