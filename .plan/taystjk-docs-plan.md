# TaystJK wiki — build plan and harvested inventory

Sources: rendered site, `gh-pages` source, `master` history (full fork delta
`eternal/master..HEAD` = 2,271 commits, 1,957 non-merge), the issue tracker (72 issues),
and `_data/cvars.json` / `_data/commands.json`.

> **Re-measured 2026-09-13 against `source_commit` `6ff04c0`** — the same commit the
> original figures were taken from, so nothing had been regenerated in between.
>
> Verified unchanged: 2,014 entries (1,441 cvars / 573 commands); 361 `documented` and
> 1,653 `needs-review`; 16 entries with a populated `range`; 775 provenance `medium`;
> the `origin.source` distribution (basejka 1024, japro 458, openjk 167, eternaljk 148,
> rend2 90, taystjk 79, vulkan 24, jk2mv 14, newjk 10); the 217 / 823 / 990 baseline
> buckets; and the changelog gap of 22 covered out of 79 TaystJK-origin entries.
>
> Two corrections applied to this document and the implementation plan:
>
> 1. **Placeholder summaries were stated as 1,029. The actual count is 1,135** — 927 cvars
>    plus 208 commands. 1,029 matches no definition tried (cvars only, all entries, either
>    restricted by status, xdocs coverage, or confidence), so it appears to be a miscount
>    rather than a different measure. Affects Phase 1's triage work item.
> 2. **The 17 macro-valued defaults were enumerated as only 15.** `ui_redteam`
>    (`DEFAULT_REDTEAM_NAME`) and `ui_saber` (`DEFAULT_SABER`) were missing from the lists
>    in Phase 1 and Prompt 1.1, which would have silently dropped two entries from that
>    prompt's before/after table. The count of 17 was right.

---

## 1. Proposed information architecture

Current top nav: Install · Host · Develop · Reference.

Proposed:

```
Install          (unchanged)
Host             (unchanged)
Features         NEW — the "hardcoded changes" replacement
  ├─ What's new in TaystJK      (the "new in this fork" page)
  ├─ Client behaviour changes   (binds, console, shader loading, levelshots)
  ├─ Cosmetics                  (command, adding new ones, custom offsets)
  ├─ HUD and movement tools     (killfeed, overlays, strafe helper, SnapHUD, PitchHUD)
  ├─ Renderers                  (what each backend is for, switching, differences)
  ├─ Movement modes             (the 19 jaPRO styles; Tribes gets its own page)
  └─ Shipped configs and assets (presets that ship in the release)
Develop          (unchanged + new pages below)
  ├─ Documentation system       (how the reference is generated, how to add a page)
  ├─ In-game docs (xdocs)       (how to document a cvar in-client)
  └─ Contributing               (PR flow, testing artifacts, where to report what)
Reference        (unchanged)
Devlog           NEW — dated posts
```

Naming note: "Features" reads better than "Hardcoded Changes" for the top-level
section, since a lot of it is configurable. "Client behaviour changes" can keep the
old hardcoded-changes framing for the genuinely non-configurable items.

---

## 2. Feature inventory harvested from the fork history

Everything below is present in the code but not on the wiki. Grouped for page assignment.
Counts in brackets are related commits found in the fork delta.

### 2.1 Shader and asset loading

- **`.oshader` override shaders.** `FS_ListFiles("shaders", ".oshader")`, parsed after
  all `.shader` files, takes final precedence when building the shader list. Present in
  all three renderers (`codemp/rd-vanilla/tr_shader.cpp`, `shared/rd-rend2/tr_shader.cpp`,
  `codemp/rd-vulkan/tr_shader.cpp`). Ported from JK2MV's `ScanAndLoadShaderFiles` ordering.
  jaPRO's own shader fixes were converted to `.oshader`.
- **Phone-book shader precedence** (already in the old hardcoded-changes text, still true).
- **Widescreen levelshots** — `levelshots_16_9/<map_name>`, plus `menu/splash_16_9`
  for ultrawide. The splash part is not in CHANGELOG.
- **Sharper fonts** — `r_fontSharpness`, requires new assets (Daggolin).

### 2.2 Cosmetics [12]

- `cosmetics` console command; individual cosmetics enabled with `cg_forceCosmetics -1`.
- Adding a cosmetic: drop the `.md3` in `models/cosmetics/hats` or `models/cosmetics/capes`.
- **Custom offsets**: optional JSON per cosmetic at `cosmetics/{hats,capes}/<name>.cosmetic`.
  Per-model and per-skin `xOffset`/`yOffset`/`zOffset`, wildcard skin keys (`de*`, longest
  match wins), and `modelFallback` true/false to control what happens when a skin has no
  entry. Shipped example: `assets/settings/cosmetics/example.cosmetic`.
- Seasonal cosmetics, `/styleplayer` integration on non-jaPRO servers, hardcoded seasonal
  dates (Halloween date is set in code).
- Covid mask / pumpkin mask from MB2; dynamic format tables used to print the list.

### 2.3 Renderers

- Three backends: `rd-vanilla`, `rd-rend2`, `rd-vulkan`. Switch with
  `cl_renderer <name>; vid_restart`. UI cvars exist for `cl_renderer` and rend2 options;
  rend2 options are hidden when another backend is selected.
- Documentable differences: rend2 memory pressure on 32-bit (already in Install), Vulkan
  is maintained downstream by JKSunny (report bugs there), bloom path is Vulkan/FBO,
  `.oshader` support is in all three.
- Known instability worth naming: #363, crash when switching away from Vulkan, still open.
  [Corrected 2026-09-13: #73 and #107 are not switching crashes. Both are Vulkan rendering
  faults that were routed to JKSunny/EternalJK. #343, a macOS `vid_restart` freeze, was
  fixed by #367 — the commit this reference is pinned to.]
  [2026-09-13: issue numbers in this file are a guide to which problems recur and are worth
  a page. They are not citations — none of them belongs on the site. See "Do not cite issue
  or PR numbers" in `CONVENTIONS.md`. Several were published as citations and have been
  removed.]

### 2.4 HUD and movement tools

- **Killfeed** [8] — ported from q3 bloodrun champions, icons from Circa. Enable/move/resize,
  text and icon size, colour toggle, alignment, `cg_killfeedReverse`.
- **Team overlay** [12] — styles 3 and 4, spectator/broadcast style, moveable, weapon icons,
  force-power column toggle on jaPRO servers, scale, max-HP display.
- **SnapHUD** and **PitchHUD** — snap zones and pitch angle display, each with their own
  cvar families. Neither is in the CHANGELOG at all.
- **Strafe helper / CGAZ** [37] — per-style physics constants (surf, Tribes, OCPM, QW, CPM,
  RJQ3, slick), stopspeed floor, command scale, ground detection on movers, frametime
  handling with `cg_strafeHelperFPS`. This is the single most-edited subsystem in the fork.
- **Speedometer** [10] — jumps tracker, `%J%` chat token, XYZ velocity option, KPH/MPH,
  race start speed split from the race timer.
- **Movement keys display** — styles 2 and 3, walk input (`cg_movementKeysWalk`),
  attack/altattack inputs, fixed assets by TriForceX.
- `cg_drawStatus` 2 and 3 (CTF flag status styles designed to pair with `cg_drawTimer 7`
  and `cg_drawScores 3`), `cg_drawScoreX/Y`, `cg_vehicleRange`, crosshair name colours
  and opacity, `cg_crossHairScope`.

### 2.5 Movement modes and Tribes [48]

- jaPRO movement styles (19 of them) — siege, jka, qw, cpm, q3, plus OCPM and Tribes added
  later. `docs/Defrag Mapping Guide.md` in `master` already describes several; nothing is
  on the wiki.
- **Tribes mode** (its own page): skiing with a speed-based sound effect, jetpack fuel bar,
  class and pack selection menu, IFF with distance-based scaling, `invfree` command with a
  HUD keybind prompt, shots-remaining display, single-fire/select-fire mode, mortar
  projectile effects, midair/frag sounds, `japro_tribes.cfg` and `japro_tribes_server.cfg`.
  Experimental — few players have used it.
- **Filing note, done — do not write this up as page content.** `MV_WSW` is a separate
  Warsow-inspired strafe style in the CPM family, not part of Tribes; the only overlap is
  the dash button (`BUTTON_DASH` / `STAT_DASHTIME`), which Tribes also gates its
  slick-friction path on. This corrects the nav sketch in section 1, which had grouped
  "Tribes/WSW". It says where the style goes — one row in the movement styles table with
  the other eighteen — and nothing more.
  [2026-09-13: this was published as a section titled "WSW is a CPM-family style, not part
  of Tribes", which argued against a misconception only this document held and gave one of
  nineteen styles a whole H2. Removed. The style's behaviour now sits in its table row,
  taken from the maintainer's own `Defrag Mapping Guide.md` line like every other row.
  General lesson for the rest of this file: a note here saying "X is not Y" is usually an
  instruction about where content goes, not a claim the reader needs to see rebutted.]
- Knockback prediction for racemode; Lugormod jump prediction (lumayaa).

### 2.6 Console, binds, client behaviour

- Modifier binds (`ctrl+x`), separate `rctrl`/`ralt`/`rshift`, nested quotes — from the old
  hardcoded-changes page, still accurate, currently homeless.
- `waitf`, `delay`, `ifCvar`, `strSub` from NewMod.
  [Corrected 2026-09-13: this line also claimed music commands were Windows-only. They are
  not. `music`, `stopmusic`, `soundlist`, `soundstop` and `s_dynamic` are registered
  unconditionally in `S_Init` (`codemp/client/snd_dma.cpp:492-499`). The only `_WIN32` guard
  nearby is `timeGetTime` for lip-sync timing, which is a different subject and is worth
  checking on its own: outside Windows that clock is hardcoded to 0 behind a FIXME.]
- `con_datetime`, `con_height`, `cl_exitCommand`, `cl_chatBubbleUnfocused`,
  `cl_chatBubbleSelf`, `cl_filterGames`, `slot` / `slotnext` / `slotprev`.
- Chat emojis — shipped emoji set under `assets/japro/gfx/emoji/`, buffer raised to 8 KB
  (~146 emoji cap before). Emoji list itself is undocumented.
- `cl_jk2FX` / `fx_jk2` — restored "broken" JK2 effects from NewJK.
- Disruptor effects from jaMME: spiral, custom and team colours, primary/alt fire times.

### 2.7 Filesystem, downloads, server behaviour (mostly Daggolin)

- Reflists and adjusted reference conditions (ported from JK2MV) — on the wiki already.
- `dl_` prefix for downloaded pk3s, download overlay, `cl_downloadPrompt`,
  `cl_allowDownload` defaulting to 1, downloads skipped when `sv_allowDownload` is 0.
- `fs_forcegame` — on the wiki already.
- `fs_restart` command; the 1024-pk3 limit removed with `-maxfds` launch override;
  native libraries not unpacked from pk3s by default; high-kernel-load workaround for
  large pk3 counts. None of this is documented.
- `MAX_PATCH_PLANES` raised to 4096; JK2 model bone conversion on dedicated servers.
- **Serverside demo pre-recording** (Tom Arrow): `sv_demoPreRecord`, `sv_demoPreRecordTime`,
  `sv_demoPreRecordKeyframeDistance`, `sv_demoPreRecordBots`, `sv_demoWriteMeta`, demo
  metadata using the JK2DemoCutter method, plus game commands for clearing buffers and
  setting metadata. A partial doc exists in-repo only.
- Feature flags — `taystJKinfo` serverinfo key, bits: 1 RGB sabers, 2 black sabers,
  4 flipkick, 8 grapple, 16/32/64 fixroll 1/2/3 (`codemp/game/bg_public.h:550-556`).

### 2.8 Build, release, integration

- Portable builds (`BuildPortableVersion`), short-hash versioning in `/modversion`,
  git tag and commit hash injected at build time, homepath fallback to install path on
  portable builds.
- Discord Rich Presence: 64-bit support, app ID history, join secret with IP validation and
  password sanitising, disabled on arm64 macOS (prebuilt lib is Intel-only), disabled under
  ASan on MSVC.
- Steam: 64-bit steamworks library lookup (#117/#119).
- Windows build scripts with interactive configuration; macOS `moveandsign.sh`;
  Docker image and Compose; Coverity scan; Windows ASan artifact.

### 2.9 Mod compatibility (worth its own page)

- Server-mod detection: `SVMOD_JAPLUS`, `SVMOD_JAPRO`, `SVMOD_LMD`, and the `< SVMOD_*`
  comparison bugs that enum ordering caused.
- Lugormod-specific fixes [10+] — `STAT_EXTRA_FORCE_BITS` collisions breaking the strafe
  helper, Ysalamari sphere, `/do`, screenshake, race-demo recording; Lugormod `help` command.
- JA+ animations and eFlags for client prediction; JA+ roll variants behind feature flags.
- Which client features silently turn off on which server mod — this is the question users
  actually ask, and the data is all in the `serverMod` / feature-flag checks.

---

## 3. CHANGELOG coverage gap

Method: `_data` reference entries whose resolved origin is `taystjk`, checked for a
name match anywhere in `CHANGELOG.md`.

- **79** cvars/commands originate in TaystJK. **22** appear in the CHANGELOG. **57 do not:**

```
cg_ambientSounds            cg_killfeedX               cg_snapHudRgba2
cg_disruptorAltTime         cg_killfeedY               cg_snapHudSpeed
cg_disruptorCoreColor       cg_movementKeysWalk        cg_snapHudY
cg_disruptorMainTime        cg_pitchHud                cg_vehicleRange
cg_disruptorNew             cg_pitchHudAngle           cl_chatBubbleSelf
cg_disruptorSpiral          cg_pitchHudRgba            cl_chatBubbleUnfocused
cg_disruptorSpiralColor     cg_pitchHudThickness       cl_exitCommand
cg_disruptorTeamColor       cg_pitchHudWidth           cl_filterGames
cg_drawScoreX               cg_pitchHudX               com_waitingForKey
cg_drawScoreY               cg_scoreboardTime          con_datetime
cg_drawTeamOverlayForce     cg_snapHud                 con_height
cg_drawTeamOverlayMaxHP     cg_snapHudAuto             fx_jk2
cg_drawTeamOverlayScale     cg_snapHudDef              g_fixSaberDisarmBonus
cg_drawTeamOverlayWeapons   cg_snapHudFps              g_fixSaberMoveData
cg_killfeed                 cg_snapHudHeight           r_renderClipBrushesShader
cg_killfeedAlignment        cg_snapHudRgba1            r_renderSlickSurfacesShader
cg_killfeedColors                                      r_renderTriggerBrushesShader
cg_killfeedIconSize                                    slot
cg_killfeedTextSize                                    slotnext
cg_killfeedReverse                                     slotprev
                                                       sv_demoPreRecordBots
```

- For a "new versus base JKA" page rather than "new versus EternalJK", the gap is much
  larger: 141 of 148 EternalJK-origin entries, all 14 JK2MV-origin, and 8 of 10
  NewJK-origin entries have no CHANGELOG line either.
- The CHANGELOG's non-TaystJK sections are inherited OpenJK text and describe SP as well
  as MP, which does not match this project's audience.

**Suggestion:** stop maintaining the prose CHANGELOG by hand for cvars. Generate the
"What's new" page from the reference data (origin + first-seen date), and keep a hand-written
changelog only for non-cvar changes. That also fixes the gap permanently.

---

## 4. Docs that exist in `master` but not on the wiki

| Path | Lines | Notes |
|:--|--:|:--|
| `docs/japro_docs.md` | 647 | Full jaPRO server/client cvar and command reference: CTF, saber, force, guns, movement, duel, admin, race/accounts, bots, elo, emote bit values, RCON commands, serverside demo recording |
| `docs/Defrag Mapping Guide.md` | 73 | Movement styles explained, course/start/finish concepts, leaderboards |
| `docs/developer/sound-code-declutter.md` | 764 | Sound subsystem notes |
| `docs/developer/renderer-architecture.md` | 11 | Front end / back end split |
| `docs/developer/libraries.md` | 33 | Overlaps the wiki's libraries page |
| `docs/developer/language strings.md` | 35 | Localisation |

Decision needed: mirror these into the wiki, link to them in-repo, or move them wholesale
to `gh-pages` and delete from `master`.

Shipped configs that no page mentions: `hud_tayst.cfg`, `japro_default.cfg`,
`japro_loda.cfg`, `japro_tribes.cfg`, `japro_tribes_server.cfg`, `noMotion.cfg`,
`restoreMotion.cfg`, `strafehelper.cfg`, `strafehelper_jk2.cfg`, `strafehelper_loda.cfg`,
`strafehelper_off.cfg`, `strafehelper_source.cfg`, `strafehelper_tayst.cfg`,
`strafehelper_tayst2.cfg`.

---

## 5. Documentation maintenance process

What exists: `.github/workflows/reference-drift.yml` on `gh-pages` runs extractor tests,
provenance chronology tests, the search-app test, record validation, generated-page
validation, and `check_drift.py --ref origin/master`.

Gaps:

1. It triggers on `gh-pages` push/PR and `workflow_dispatch` only. A cvar added on `master`
   never triggers anything, so drift is only caught the next time the docs branch is touched.
2. No scheduled run.
3. No feedback on the `master` side — a PR that registers a new cvar gets no signal.
4. `reference-meta.json` pins `source_commit`; nothing on the site states how stale that is.

Proposed process:

- Add a nightly or weekly `schedule:` trigger to the drift workflow, and have it open an
  issue when drift is detected instead of only failing.
- Add a light `master`-side PR check that greps the diff for `Cvar_Get` / `AddCommand` and
  comments a reminder with links to the xdocs macros and the reference pipeline.
- Add a PR checklist item: new cvar → xdocs entry → menu entry if user-facing → overrides
  entry if the auto-summary is a placeholder.
- Render `source_commit` and its date on the reference landing page so staleness is visible.
- Release cadence: regenerate the reference as part of the release workflow rather than ad hoc.

---

## 6. Devlog

Just-the-Docs has no blog support, so options are:

- A `devlog/` collection with a `_posts`-style layout and a simple index page. Stays on
  `gh-pages`, no extra toolchain, ~30 lines of Liquid.
- Or GitHub Discussions in the Announcements category, embedded or linked. Zero site work,
  gets comments for free, but posts live outside the docs.

Recommend the collection, with an Atom feed so it can be syndicated to Discord.

---

## 7. Audit findings (carried forward and extended)

1. `hardcoded-changes.md` plus four child stubs still carry Just-the-Docs front matter
   (`has_children`, `nav_order`, `permalink` pointing at anchors) and nothing links to them.
2. `cvars/` and `commands/` legacy pages are `nav_exclude`d but still built. Content is
   stale — e.g. the `cg_drawTeamOverlay 3` / `4` description predates the overlay overhaul.
   Typo filename: `cvars/miscellanous.md`.
3. Reference status: 1,653 of 2,014 entries `needs-review`, 361 `documented`. 1,135 have
   placeholder summaries — 927 cvars in the "Controls … in the … module" form and 208
   commands in the equivalent command form. 775 are provenance `medium`.
   [Corrected 2026-09-13: was stated as 1,029, which matches no definition of "placeholder"
   against the data at `6ff04c0`. See the re-measurement note at the top of this file.]
4. 17 defaults are unresolved C macros, several user-facing: `sv_master1` shows
   `MASTER_SERVER_NAME` rather than `masterjk3.ravensoft.com`, `cl_renderer` shows
   `DEFAULT_RENDER_LIBRARY`, plus `model`, `saber1`, `r_textureMode`, `r_drawBuffer`,
   `ui_redteam`, and `ui_saber`. The full list of 17 is in the implementation plan's
   Prompt 1.1.
5. Only 16 entries carry a `range`; 564 carry a values enum.
6. Every blame link pins `6ff04c0`; no stated regeneration cadence.
7. No changelog, contributing, troubleshooting, or "where to report what" page.
8. Install covers first install only, not updating over an existing build.
9. Internal link check across the guide pages: clean (one false positive on a query-string link).

---

## 8. Open questions

1. Baseline for "What's new": versus base JKA, or versus EternalJK? Versus base JKA is what
   most readers want and is roughly four times the content.
2. Does `docs/` in `master` stay, move, or get mirrored?
3. Generate the "What's new" page from reference data, or keep it hand-written?
4. Is Tribes considered a supported, documented feature or still experimental? (WSW is not
   part of this question — it is an ordinary movement style; see section 2.5.)
