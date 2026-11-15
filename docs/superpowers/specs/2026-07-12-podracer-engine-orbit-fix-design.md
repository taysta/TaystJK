# Podracer engine counter-orbit fix (2026-07-12)

## Problem

When the pod banks (manual A/D roll, up to ±65°), the whole GLM renders rolled as a
rigid unit. The two engines sit out at ±X, so the roll *orbits* them about the pod
centre — one engine swings up, the other down toward/into the ground. The user wants
the engines to **not orbit as far** (cancel ~60% of the orbit), keeping them closer to
world-level, without diving into the terrain.

This is a POSITION effect (engine height under bank), not each engine's own roll angle.

## Root cause (confirmed by live measurement, not theory)

Two things were previously conflated and both are now settled by the in-game
`MEASURE engine dZ` HUD instrument (reads each engine's true posed world-Z via the
bolt matrix):

1. **The arms are mirror-posed.** The same signed arm rotation lifts one engine and
   pushes the other the *wrong* way. Live proof (hard right bank, ±65°, gain 6):
   - `Rsign=+1` (both arms same command −261°): dZ L=−80.9 R=−99.0, spread **+18.1**
     (the spread *inverted* — right engine slammed down past level).
   - `Rsign=−1` (arms opposite, L −261 / R +261): dZ L=−81.6 R=−52.4, spread **−29.2**
     (spread shrank toward 0 — both engines corrected toward level).
   - Baseline (gain 0, no correction): dZ L=−111.8 R=−16.7, spread **−95.1**.

   → **The right arm must use the opposite sign of the left.** `Rsign = −1` is correct
   and must be baked in. The earlier "right engine never gets constrained" was because
   at the shipping scale the same-sign command was cancelling the wrong side.

2. **The magnitude was ~10× too hot and mis-scaled.** The applied angle is
   `sin(roll) · (1−ROLL_FOLLOW) · ORBIT_LEVER · cg_podEngineSway · gain · sign`.
   During testing `cg_podEngineSway` was **4** (ships as **1**) and gain was **6**,
   producing applied = 10.88 · 4 · 6 = **−261°** — a meaningless rotation that flings
   the engine bodies to garbage angles (visible in the test screenshots). At the
   shipping scale of 1 and gain 1 the per-side angle is only ~11° (≈20% cancellation),
   far short of the 60% target.

The earlier "engines yaw into the ground" dead end was `cg_podOrbitSlot 0` (model-Y =
yaw). **Slot 2 is the correct lift slot** on the current v2 rig — verified live: slot 2
raises the low engine without ground-clipping. No rig rebuild is required.

## G2 constraint (why the lever can only rotate, and it's in model space)

`G2_Generate_Matrix` (rd-vanilla/G2_bones.cpp:328-329) builds the override as
`M = BasePoseMat · R · BasePoseMatInv`, applied as `childWorld = parentWorld · M`
(tr_ghoul2.cpp:1925). A POSTMULT bone angle is therefore a **pure rotation about the
bone's base-pose origin, around MODEL-space axes** — it cannot translate, and its axes
live in the rolled model frame. Consequence: as bank grows, model-up diverges from
world-up, so a fixed lift angle over-corrects less in world-Z at extreme bank. Handled
by the cos(bank) fade below.

## Design

Cgame-only. No engine/trap changes, no rig rebuild. All edits in
`CG_PodEngineSway` (codemp/cgame/cg_players.c) plus one cvar default.

### 1. Bake the mirror sign (values confirmed by eye)
The two arm commands compose as: left = `orbitBase·scale·Sign·gain`, right =
`left·RightSign`. The user tuned live and confirmed **`cg_podOrbitSign = −1`** and
**`cg_podOrbitRightSign = −1`**. Net per-arm signs: left = −1, right = (−1·−1) = +1 —
i.e. the arms end up **opposite**, the mirror correction, and the whole assembly's
baseline polarity is flipped (model faces −Y, so positive roll read reversed). Bake both
defaults to −1.

### 2. Lock the slot
`orbitSlot` = 2 (model-space axis that lifts the engine vertically on the v2 arm base
pose). Bake `cg_podOrbitSlot` default 2; keep the probe live for now.

### 3. Gain (starting point, re-tuned after the fade)
User confirmed **`cg_podOrbitGain = 4`** looks right *without* the cos(bank) fade. At
shipping `cg_podEngineSway = 1`, `ROLL_FOLLOW = 0.4`, `ORBIT_LEVER = 20`, that is per-side
applied ≈ `10.88 · 1 · 4` ≈ **43.5°** at max bank (±65°). Because the fade (step 4)
reduces peak correction, gain 4 is the **starting point**, not the final value: after the
fade is in, the user re-drives and re-picks the gain by eye (likely a bit above 4 to
compensate). Once confirmed, fold the final gain into `ORBIT_LEVER` (e.g. 20·4 = 80) so
the shipped `cg_podOrbitGain = 1` reproduces the tuned look, keeping the cvar live only
for final nudging before the scaffolding is stripped.

### 4. cos(bank) fade
Multiply the counter-lift by `cos(roll)` so the correction is full near level and eases
off at extreme bank where model-up and world-up diverge (avoids over-rotating the engine
body into wrong angles at ±65°). `lift = orbitBase · gain · cos(roll) · sign`.
Note: `orbitBase` already carries `sin(roll)`, so the net per-side term is
`∝ sin(roll)·cos(roll)` — peaks near 45° bank and softens toward the ±65° extreme, which
is the desired shape. **Re-verify the gain after adding the fade** — the user tuned
gain=4 *without* the cos(roll) term, so the fade will reduce peak correction; the final
baked gain is confirmed by eye once the fade is in.

### 5. Restore the dropped lat-sway term
The handoff notes the lateral sway term was temporarily removed from the arm command to
make room for the orbit probe. Once orbit is on slot 2, restore the lat/vert sway on its
own slots so the engines still swing wide of turns and float with thrust.

## What stays untouched
Engine sway (yaw/roll/nose-up), translation lat/vert springs, elastic cables, cockpit
dip/twist — all working and tuned. Only the orbit-counter sign, slot, gain, and fade
change.

## Verification (instrument already exists)
Drive a sustained ±65° bank with `cg_drawPodPhysics 1` and read `MEASURE engine dZ`:
- **Success:** |L−R| spread drops from ~95 to ~40 (≈60% cancelled), and neither engine
  clips terrain, at the shipping `cg_podEngineSway 1`.
- Check both bank directions (hold A and hold D) — the mirror sign must correct both.
- Confirm at gain 1 (not 6) and scale 1 (not 4): the shipped defaults, not test values.

## Cleanup (tracked, not this change)
The debug HUD block and the `cg_podOrbit*` probe cvars are scaffolding — strip before
ship once the final gain/sign/slot are baked into the `#define`s.
