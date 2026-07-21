# Podracer engine counter-orbit — handoff (2026-07-12)

**Status: SOLVED in-game, NOT yet baked into code.** The user tuned the fix live and it
looks good. Three small cgame-only edits remain to make it ship out-of-the-box. Full
plan: `docs/superpowers/plans/2026-07-12-podracer-engine-orbit-fix.md`.
Spec: `docs/superpowers/specs/2026-07-12-podracer-engine-orbit-fix-design.md`.

## What was wrong and how it was solved

The pod banks up to ±65°; engines sit at ±X, so the roll orbits them — low engine dived
into the ground. Fixed by countering each engine's height via its `engine_arm_*` lever
bone in `CG_PodEngineSway` (codemp/cgame/cg_players.c).

**Root cause was two stacked bugs, confirmed by the live `MEASURE engine dZ` HUD:**
1. Arms are mirror-posed → right arm needs the OPPOSITE sign of the left.
2. The magnitude was mis-scaled.

**Confirmed working cvar values (tuned by eye, `cg_podEngineSway 1`):**
- `cg_podOrbitSign -1`, `cg_podOrbitRightSign -1` (net: left arm −1, right arm +1 = mirror)
- `cg_podOrbitSlot 2` (the model-space vertical-lift slot; slot 0 was the old "yaw into ground" bug)
- `cg_podOrbitGain 4`
- **No cos(bank) fade** — considered and rejected (it reduces correction exactly at max
  bank where clipping is worst). Do NOT add it.

## Remaining work to bake it (3 tiny edits, cgame-only, then commit)

1. **Fold gain into the lever:** `codemp/cgame/cg_players.c:9705`
   `#define POD_ENGINE_ORBIT_LEVER 20.0f` → `80.0f` (20 × tuned gain 4).
2. **Bake cvar defaults:** `codemp/cgame/cg_xcvar.h:357-360`
   `cg_podOrbitRightSign` → `"-1"`, `cg_podOrbitSign` → `"-1"`, `cg_podOrbitSlot` → `"2"`.
   `cg_podOrbitGain` stays `"1"` (gain now lives in the lever constant).
3. **Restore lateral sway (currently dead):** `m_fPodArmLat` is computed by the spring at
   `cg_players.c:9887` but NEVER applied to any angle slot — the "engines swing wide of
   turns" motion is broken. Add `angles[0] += pVehNPC->m_fPodArmLat * scale;` to BOTH arm
   `VectorSet` blocks (lines ~9923 and ~9937), same sign both arms. Slot 0 is the model-Y
   home per the old rig; verify live it reads lateral, not yaw-into-ground (slot 0 was the
   orbit bug slot, so re-check — move to slot 1 if it misbehaves).

Build: `cmake --build build/msvc16_x64 --config Release --target cgame` (cgame only).
Verify: `cg_drawPodPhysics 1`, drive both A and D at max bank, `MEASURE engine dZ` spread
should drop ~95 → ~40 with no clipping, and it should work with ZERO manual cvars after
the bake.

## Still-parked side issues (unchanged, not orbit-related)
- Intermittent rider-seat yaw drift; user leaning toward a hardcoded pilot bolted to
  `*driver` instead of showrider.
- Cosmetic white cable-tip shading seam from the L/R cable split.
- **Debug HUD + `cg_podOrbit*`/probe cvars are scaffolding** — strip before shipping,
  after the bake above is confirmed.

## The G2 fact that cost prior sessions (keep)
POSTMULT bone angles are a pure rotation about the bone's base-pose origin around
MODEL-space axes (`G2_bones.cpp:328-329`, applied `childWorld = parentWorld · M` at
`tr_ghoul2.cpp:1925`). The rendered bank is in `cent->lerpAngles[ROLL]` (±65), NOT
`m_vOrientation[ROLL]` (stays 0 for the ridden pod). The rig is CORRECT — no rebuild.
