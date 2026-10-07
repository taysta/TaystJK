# Recording

Recording-only code (no input endpoint) lives here and may ship in release builds, e.g. the
usercmd logger hooked after `CL_FinishMove`. See `../README.md`.

- `selftest.cpp`: `+set jkbot_selftest 1` checks that the stock assets load (assets0–3 from
  fs_basepath, two stock files, a model and a shader in the renderer, a sound, the UI module),
  prints "selftest ok" and quits with status 0, or "selftest failed" with status 1. Called at the
  end of Com_Init as `CL_SelfTest` (a no-op stub in the dedicated server).
