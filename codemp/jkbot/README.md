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
