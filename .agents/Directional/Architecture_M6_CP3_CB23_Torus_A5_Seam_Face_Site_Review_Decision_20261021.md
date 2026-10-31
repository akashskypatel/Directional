# RA-122 — CB23 diagnostic-only seam-face review (2026-10-21)

**Turn:** `M6-CP3-CB23-RP01-TORUS-A5-SEAM-FACE-SITE-REV`. **Verdict:** ACCEPT CB23 for its narrow diagnostic-only, compile-verified scope; **no runtime acceptance**. Exact semantic source `e859175333f879273a75e3bfc321600e451048aa`, parent-scope baseline `c6e90916eb90bfd33bc8a38c5ece7def15dcc766`; reviewed GitHub CB23 commit diff and the immutable package. No A5 isolation design decision is authorized by this result.

## Independent source and package evidence

- Commit `e859175333f` changes only `src/pipeline/RemeshPipeline.cpp`, +68/−0, in the `relation-collinear-seam` rejection block (RP:5343–5410). All 68 added lines are at most 90 columns. The prior `site` prefix and `certN` diagnostic remain intact; `;sel`, `;support`, `;wedge`, and `;spanOnlyN` are appended in RA-121.5 order before `error.isolationSite` and `return error`. No admission, return, error enum, header, fixture or test logic is changed by the semantic commit.
- `sel`: canonical occurrences' `placement.selectedFace` mapped with `row_for_topology`, `sheet_for_row`; unavailable row is `none`. `support`: actual `authority::support_kind` enumerations. `wedge`: ordered `cornerWedgeBindings` as row/sheet joined with `+`. `spanOnlyN`: same collinearity, region, same-sheet and side classification as existing `certN`, deliberately omitting only the first/second selected-face equality clauses, reporting `forward`/`reverse` on opposing certified sides. Certificate filtering and order are identical for `certN` and `spanOnlyN`.
- CB23 package `12355892070`, run [39623185718](https://github.com/akashskypatel/Directional/actions/runs/39623185718), outer ZIP SHA-256 independently calculated as `5215e5c216cde5cd45d851d36c9aa9b2a62de496aa78db2aac54d828996af91f`; **28/28** root manifest file digests verified. Source tar SHA-256 `b570e9815e8f6b438f3356970f79b80557f4e07941e5501517eb941644222281`, source commit metadata exactly `e859175333f879273a75e3bfc321600e451048aa`. Packaged RP source bytes independently match the separate verified source snapshot's RP source (SHA-256 `9d8990493f8d655742fe44cae84a08fd9c6577d7244070d859f3d5b46d146c26`).
- Eight named compiled targets (two static libraries and six executables); configure preflight and build exit `0`; CMake `DIRECTIONAL_ENABLE_GMP=ON`; linker evidence contains both `libgmpxx.so` and `libgmp.so`. All five source-status records are empty. `command-boundary.txt`: `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `exactArithmeticBackend=GMP`. No executable was launched during this Review.
- The exact source snapshot was materialized for independent static checks. Its archive does **not** carry Git history; therefore `review_check.py boundary` on the extracted, non-Git snapshot is not a history-backed boundary proof. GitHub's one-commit changed-file inventory independently establishes the production/test/selector scope, and the exact packaged source establishes the compiled content. No false history-backed pass is claimed.

## Disposition and obligations

- **RA-121.5 discharged:** fields and source scope exactly match authorized diagnostic design; compile package is valid. This review does not establish that a runtime failure will emit the fields or which B-across/B-fan hypothesis owns it.
- **RA-121.4 and RA-121.6 carried:** harvest three A5-ISO rows, one atlas guard and five unchanged controls on the exact CB23 package; route `sel`/`support`/`wedge`/`spanOnlyN` under the pre-registered branches. Explicit plan: `Architecture_M6_CP3_TB24_Torus_A5_Seam_Face_Harvest_Plan_20261021.md`. No relaxation of the `first-face` A5 guard; no return to the CP2 silent same-sheet fallback.
- **Non-vacuity:** the new fields lie on a diagnosed rejection branch from TB23 but were not observed at runtime. TB24 must independently show the same exact site prefix with the appended values on three distinct identities, and its guard/controls must select and pass; otherwise the diagnostic remains unproven and DEFN-ISO is not reached.
- **Accounting:** unchanged stable 66 events / 17 categories / 49 recurrences, debt 1, CP2 accepted 491/491, R3 403/497 rejected, TB21 candidate 449/497; selector 497 frozen, RP-01 open, RP-02 unreached, Gate C suspended. CB23 remains compile-accepted only.

**Authorized successor:** `M6-CP3-TB24-RP01-TORUS-A5-SEAM-FACE-HARVEST` (artifact-only Test + Benchmark), after this Review closes. No TB24 runtime is included in this Review.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | n/a: no selector addition/acceptance or changed selector prefix; accepted CP2 491 and frozen entry 497 remain authoritative |
| Decisive claims independently re-derived | CB23 one-commit +68/−0 scope; 68 line widths ≤90; 28/28 file checksums, full ZIP/source tar digests, RP source equivalence, eight targets, GMP/GMPXX, five empty source statuses and runtime boundary |
| Non-vacuity checked | Source reject-only reachability verified; runtime emission is unproved and explicitly falsified/confirmed by TB24's A5 rows and six PASS controls |
| Prior obligations discharged/carried | RA-121.5 discharged; RA-121.4 B-across/B-fan and RA-121.6 nine-row harvest carried to TB24/TB24-REV |
| Stable accounting | 66/17/49, debt 1; CP2 491/491; candidate TB21 449/497, R3 403/497 rejected; unchanged selector 497 |
| New candidates/obligations recorded | No new regression; A5-ISO pending TB24 with owner and falsifiers in TB24 plan; tracker unchanged |
| ORIENTATION currency line | Updated 2026-10-21 for RA-122, TB24 next |
| ORIENTATION §3 / §4 / §7 / §8 | §3 and §7 updated for compile-only Review disposition; §4 n/a no witness state change; §8 n/a no new pattern |
| CHANGELOG | RA-122 entry added |
| ROADMAP | n/a M6-CP3 remains active/not accepted; no checkpoint transition |
| Selector manifest | n/a no selector created or accepted |
| LESSONS | Existing diagnostics, reviews, artifact, and causal-identification rules §§5–7 cited; no new reusable pattern |
| Consolidation under CLEAN_UP_POLICY | No redundant historical files safe to delete from this independent Review; retained RA-121 and CB23 evidence are still authoritative |
| Successor frozen | `M6-CP3-TB24-RP01-TORUS-A5-SEAM-FACE-HARVEST`; nine identities, predictions, falsifiers and stop rules in `Architecture_M6_CP3_TB24_Torus_A5_Seam_Face_Harvest_Plan_20261021.md` |
| Turn boundary held | Review-only static/package inspection; no product/test/fixture/selector/build changes or runtime |
| review_check.py boundary | Source snapshot lacked `.git`; history-backed check unavailable, explicit gap recorded; one-commit changed-file scope independently checked |
| `STATUS` lifecycle maintained | Same canonical Review; original start preserved and resumed timestamp updated; final COMPLETE beacon only after document push |
| Pushed to origin, branch in sync | Verified remote working-branch commit acknowledgement and fresh head after documentation push; no local clone/history-backed `git status -sb` claim |
