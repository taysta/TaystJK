# JKBot engine code

Simulator support for JKBot (an imitation-plus-RL bot): lockstep mode, agent clients and
input injection, the Python bridge, state export and rule-detector signals.

Rules:

- **Agent and bridge code** (`codemp/jkbot/*`) compiles only when CMake's `JKBOT_AGENT` option is
  on (default `OFF`). Every source file here is wrapped in `#ifdef JKBOT_AGENT` from its first
  directive to its last, and any hook added elsewhere in the engine sits inside an
  `#ifdef JKBOT_AGENT` block. Release builds never set the option: an input-injection endpoint in
  a FACEIT client would fall under FACEIT rule §4.3.3.
- **Recording code** (`codemp/jkbot/record/`, e.g. the usercmd logger) records only and has no
  input endpoint, so it is allowed in release builds.
- Nothing here changes player physics, saber combat or anything else that affects gameplay.

The JKBot repo checks these rules in `training/tests/test_engine_guard.py`.
