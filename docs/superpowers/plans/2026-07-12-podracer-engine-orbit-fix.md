# Podracer Engine Counter-Orbit Fix Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Make the podracer engines cancel ~60% of their roll-induced orbit so the low engine stops diving into the ground under bank, and bake the tuned values so the shipped defaults reproduce the look.

**Architecture:** Cgame-only. The counter-orbit already exists in `CG_PodEngineSway` (codemp/cgame/cg_players.c) driven by live probe cvars. The mirror-posed arms need opposite signs and the vertical-lift slot is 2. The user has **already tuned and confirmed the look by eye** (Sign=−1, RightSign=−1, Slot=2, Gain=4, NO fade — the cos(bank) fade was considered and rejected because it reduces correction exactly at max bank where clipping is worst). This plan bakes those confirmed values into `#define`s / cvar defaults so it ships out-of-the-box, and restores one dropped sway term. Verification is in-game via the existing `MEASURE engine dZ` HUD readout (there is no unit-test harness for G2 bone poses — the HUD is the instrument).

**Tech Stack:** C (JKA cgame DLL), CMake/MSVC build, GHOUL2 `G2API_SetBoneAngles` POSTMULT bone overrides.

## Global Constraints

- **Cgame-only. NO engine/trap/server changes.** (user, repeated) — every edit is in `codemp/cgame/cg_players.c` and `codemp/cgame/cg_xcvar.h`.
- **No rig rebuild.** The v2 rig is correct; slot 2 lifts vertically (verified live).
- Build target: `cmake --build build/msvc16_x64 --config Release --target cgame`. **The user builds and tests themselves — do not launch the game.**
- Test at shipping scale `cg_podEngineSway 1` and `cg_podOrbitGain 1` for final verification, NOT the 4/4 test values.
- Confirmed tuning (pre-fade, by eye): `cg_podOrbitSign = −1`, `cg_podOrbitRightSign = −1`, `cg_podOrbitSlot = 2`, `cg_podOrbitGain = 4`. Net arm signs: left = −1, right = +1 (opposite = mirror correction).
- The debug HUD block and `cg_podOrbit*` probe cvars are scaffolding — a later, separate change strips them. This plan does NOT strip them (they're the verification instrument).

---

## File Structure

- `codemp/cgame/cg_players.c` — `CG_PodEngineSway` orbit block (lines ~9905-9950): add cos(bank) fade to the orbit term. Header `#define`s (lines 9699-9705): fold the tuned gain into `POD_ENGINE_ORBIT_LEVER`.
- `codemp/cgame/cg_xcvar.h` — orbit probe cvar defaults (lines 357-360): bake `Sign=-1`, `RightSign=-1`, `Slot=2`, `Gain=1`.

---

### Task 1: Add the cos(bank) fade to the orbit term

**Files:**
- Modify: `codemp/cgame/cg_players.c:9705` (`POD_ENGINE_ORBIT_LEVER`)

**Interfaces:**
- Consumes: the user's confirmed `cg_podOrbitGain = 4` (tuned by eye at `cg_podEngineSway 1`, NO fade).
- Produces: `POD_ENGINE_ORBIT_LEVER` folded so shipping `cg_podOrbitGain 1` reproduces the tuned look. No change to the `orbitBase`/`orbit` computation (no fade).

- [ ] **Step 1: Fold gain 4 into the lever constant**

In `codemp/cgame/cg_players.c`, replace lines 9701-9705:

```c
// Legacy orbit-command gain retained while the live slot/sign probe is running.
// The current v2 arm is a ~49-unit lateral lever, so the old v1 400-unit-lever
// calibration does not describe its motion; replace this with direct follow-angle
// math once the measured slot/sign result is known.
#define POD_ENGINE_ORBIT_LEVER 20.0f
```

with (20 base × the tuned gain 4 = 80, so shipping `cg_podOrbitGain 1` reproduces the
by-eye look):

```c
// Counter-orbit lever gain.  20 was the raw base; the in-game tuned factor of 4
// (confirmed by eye via MEASURE engine dZ at cg_podEngineSway 1, both bank directions,
// no cos-fade) is folded in so the shipped cg_podOrbitGain 1 reproduces the look.
#define POD_ENGINE_ORBIT_LEVER 80.0f
```

- [ ] **Step 2: Build cgame**

Run: `cmake --build build/msvc16_x64 --config Release --target cgame`
Expected: builds clean.

- [ ] **Step 3: Commit**

```bash
git add codemp/cgame/cg_players.c
git commit -m "Podracer: bake tuned counter-orbit gain into lever constant"
```

Note: full in-game verification happens after Task 2 (defaults baked) so the user can
confirm the whole thing works with zero manual cvars in one pass.

---

### Task 2: Bake the sign/slot cvar defaults

**Files:**
- Modify: `codemp/cgame/cg_xcvar.h:357-360`

**Interfaces:**
- Consumes: confirmed `Sign=-1`, `RightSign=-1`, `Slot=2` (and `Gain=1`, already the default, now correct since gain is folded into the lever).
- Produces: shipped defaults that reproduce the tuned look with no manual cvar setup.

- [ ] **Step 1: Update the four cvar defaults**

In `codemp/cgame/cg_xcvar.h`, replace lines 357-360:

```c
XCVAR_DEF( cg_podOrbitGain,					"1",					NULL,					CVAR_NONE )
XCVAR_DEF( cg_podOrbitRightSign,				"1",					NULL,					CVAR_NONE )
XCVAR_DEF( cg_podOrbitSign,					"1",					NULL,					CVAR_NONE )
XCVAR_DEF( cg_podOrbitSlot,					"0",					NULL,					CVAR_NONE )
```

with (Gain stays "1" since the gain is now folded into the lever constant; Sign and
RightSign become −1 for the mirror correction; Slot becomes 2 for the vertical-lift axis):

```c
XCVAR_DEF( cg_podOrbitGain,					"1",					NULL,					CVAR_NONE )
XCVAR_DEF( cg_podOrbitRightSign,				"-1",					NULL,					CVAR_NONE )
XCVAR_DEF( cg_podOrbitSign,					"-1",					NULL,					CVAR_NONE )
XCVAR_DEF( cg_podOrbitSlot,					"2",					NULL,					CVAR_NONE )
```

- [ ] **Step 2: Build cgame**

Run: `cmake --build build/msvc16_x64 --config Release --target cgame`
Expected: builds clean.

- [ ] **Step 3: User verifies fresh defaults (no manual cvars)**

Ask the user to restart the client (or `vid_restart` / reconnect so the new cvar defaults take) WITHOUT setting any `cg_podOrbit*` cvars, spawn the pod, and drive. Only `cg_drawPodPhysics 1` for the HUD.
Expected: engines counter-orbit correctly out of the box in both turn directions; `MEASURE engine dZ` spread ~40 at max bank; no ground clipping. This confirms the baked defaults reproduce the tuned look with zero manual setup.

- [ ] **Step 4: Commit**

```bash
git add codemp/cgame/cg_xcvar.h
git commit -m "Podracer: bake counter-orbit sign/slot cvar defaults"
```

---

### Task 4: Restore the lateral sway term (engines swing wide of turns)

**Files:**
- Modify: `codemp/cgame/cg_players.c:9923` and `:9937` (the two arm `VectorSet` calls)

**Interfaces:**
- Consumes: `pVehNPC->m_fPodArmLat` — already computed by the spring at line 9887-9888 but currently DROPPED (never applied to any angle slot). Both arms share the same value.
- Produces: the lateral swing restored on a slot that does NOT collide with the orbit lift (slot 2 / Z) or the vert term (also slot 2 / Z).

**Context:** `m_fPodArmLat` is computed every frame but never written into `angles`, so the "engines swing wide of the turn" sway is currently dead. Orbit + vert both live on slot 2 (Z). The lateral term must go on a different slot. Which slot yaws/swings the engine laterally is NOT assumed here — it is confirmed live with the same `MEASURE engine dZ` + POSEDBG HUD used for orbit, before baking.

- [ ] **Step 1: Apply the lat term on a probe slot for both arms**

In `codemp/cgame/cg_players.c`, the left-arm `VectorSet` at line 9923 currently reads:

```c
			VectorSet( angles, 0.0f, 0.0f, pVehNPC->m_fPodArmVert * scale );
			angles[orbitSlot] += orbit;
```

Change to add the lat term on a live-selectable slot (reuse a temporary probe: read `cg_podOrbitSlot`+? — simpler: put lat on slot 0 (model-Y, the pre-orbit home of the lat sway per the handoff) and confirm it reads as lateral, not vertical):

```c
			VectorSet( angles, 0.0f, 0.0f, pVehNPC->m_fPodArmVert * scale );
			angles[0] += pVehNPC->m_fPodArmLat * scale;   // lateral swing (slot 0, model-Y)
			angles[orbitSlot] += orbit;
```

And the right-arm `VectorSet` at line 9937 currently reads:

```c
				VectorSet( angles, 0.0f, 0.0f, pVehNPC->m_fPodArmVert * scale );
				angles[orbitSlot] += orbit * cg_podOrbitRightSign.value;
```

Change to (lat is the SAME sign both arms — both engines swing the same lateral
direction into a turn, unlike orbit which is mirrored):

```c
				VectorSet( angles, 0.0f, 0.0f, pVehNPC->m_fPodArmVert * scale );
				angles[0] += pVehNPC->m_fPodArmLat * scale;   // lateral swing (slot 0, model-Y)
				angles[orbitSlot] += orbit * cg_podOrbitRightSign.value;
```

- [ ] **Step 2: Build cgame**

Run: `cmake --build build/msvc16_x64 --config Release --target cgame`
Expected: builds clean.

- [ ] **Step 3: User confirms lateral swing, no orbit interference**

Ask the user to drive turns (not just bank) and watch whether the engines now swing wide/lateral with the turn WITHOUT re-introducing the yaw-into-ground behaviour. Slot 0 was the yaw slot that caused the original problem, so this must be checked: if the lat term on slot 0 makes engines yaw badly again, the fix is to move `m_fPodArmLat` to a different slot (try slot 1) — confirm via the HUD which slot gives a clean lateral swing.
Expected: engines swing wide of turns; orbit counter still works; no ground clipping. If slot 0 misbehaves, re-pick the lat slot and note the final choice in a comment.

- [ ] **Step 4: Commit**

```bash
git add codemp/cgame/cg_players.c
git commit -m "Podracer: restore lateral engine sway on the arm lever"
```

---

## Notes for the implementer

- **Both bank directions matter.** The mirror sign must correct the low engine whether the user holds A or D. If one direction corrects and the other worsens, the sign composition is wrong — re-check Sign vs RightSign, do not just flip gain.
- **`lerpAngles[ROLL]` is the rendered bank** (−65..+65), NOT `m_vOrientation[ROLL]` (stays 0 for the ridden pod). This is already correct in the current code; do not "fix" it to read m_vOrientation.
- **The verification IS the HUD**, not a test file. `MEASURE engine dZ` reads the true posed bolt matrix world-Z; trust it over the angle command.
- Scaffolding (debug HUD + probe cvars) is intentionally left in place by this plan; a separate cleanup pass strips it once the feature ships.
```
