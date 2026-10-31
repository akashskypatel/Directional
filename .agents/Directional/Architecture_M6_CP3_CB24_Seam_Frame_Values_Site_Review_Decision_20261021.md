# RA-125 — independent CB24 seam-frame diagnostic review (2026-10-21)

**Turn:** `M6-CP3-CB24-RP01-SEAM-FRAME-VALUES-SITE-REV`. **Decision: ACCEPT** CB24 for its exactly scoped diagnostic-only change and immutable compile package; no runtime or seam-contract correctness acceptance. **Successor:** `M6-CP3-TB25-RP01-SEAM-FRAME-VALUES-HARVEST`, with exact 11-row artifact-only plan `Architecture_M6_CP3_TB25_Seam_Frame_Values_Harvest_Plan_20261021.md`. The disputed frozen D3 and A5 contract are unchanged.

## Independently re-derived source evidence

- GitHub semantic commit `dae267a82fb884ff9eba4fd0122ad61750d0c924`, parent `5b56833a511ae73f95c818cc8921c9617eb930f2`, changes exactly `src/pipeline/RemeshPipeline.cpp` (+28/−0, one hunk) and `tests/SurfaceCellTransitionQuotientTests.cpp` (+1/−6, one hunk). GitHub's commit patch was inspected rather than copied from the CB24 record.
- RP appends after the existing `spanOnlyN` loop: `branch` reads the two canonical occurrences' `lattice.branchRotation`; `gaugeSel` and `gaugeSpan` resolve the selected and bound source faces through the topology-row lookup and the authoritative face-gauge table, returning `none` when unavailable; `turnN` iterates certificates matching this region/seam and emits their forward/reverse values. Original site prefix, admission/return/error path and diagnostic ordering are preserved. TQ replaces the narrow A5 error-name wrapper with the existing full `a5_rejection_message` function; no assertion changes. Added RP lines have maximum width **91**, none exceed 100.
- The independently verified source snapshot at commit `40bf38126cc70713422cbdb2e38364e294fa1253` is [run 39671021648](https://github.com/akashskypatel/Directional/actions/runs/39671021648), artifact `12380021596`, ZIP SHA-256 `164b8fb77517ddf2aa0ad29e92d5d73bb8523459ce18941f601746f1efad0832`; its 5,743 source hashes match. Its difference from CB24 semantic commit includes control/documentation only, not source, test, selector or build code. No checkout clone was used.

## Independent compile-package evidence

- Workflow [39667030493](https://github.com/akashskypatel/Directional/actions/runs/39667030493) completed successfully. Result `12378590512` has outer ZIP SHA-256 `bbaaa3853e4a0d3cef13d327fefa10676ab0d10108213964772215ec79d630b4`. Recomputed **28/28** root SHA256SUMS digests after normalizing manifest's `./` path prefix. Embedded source tar SHA-256 `21b47d49d6059f946c4112231691fdd0972625552a4bb2fcd5251568c8e9dba0`, exact source metadata `dae267a82fb884ff9eba4fd0122ad61750d0c924`.
- Preflight/build exit 0/0. Eight recorded targets are `directional_core`, `directional_pipeline`, four surface-cell authority/producer/completion/validation test binaries, `directional_compiled_api_tests`, `directional_benchmarks`. GMP evidence includes both `libgmpxx.so` and `libgmp.so`; command boundary declares `exactArithmeticBackend=GMP`, `turnBoundary=Code+Build-only`, `runtimeExecution=false`. Five source-status records empty. These are compile/package facts, not test execution.
- **Non-vacuity:** instrumentation is in an existing rejection branch, but no CB24 runtime executed; field emission and the gauge/turn relationship remain unproved. TB25 rows 1–3 must independently reproduce it; D3 witnesses 4–5 and six guards/controls distinguish attribution and unrelated regression. A missing field or unexpected stage falsifies the plan instead of establishing a pass.
- **RA-124.5 discharged** for static two-hunk source and compile package. **RA-124.6 discharged as a frozen plan**, not runtime evidence. **RA-124.3–.4 carried** to TB25-REV/DEFN-SEAM; `cp3entry:3/5` contested, not reclassified. No new stable regression candidate. Stable **66/17/49**, debt **1**; CP2 **491/491** accepted; R3 **403/497** rejected, TB21 **449/497** candidate; 497 entry identities frozen. RP-01 open, RP-02 unreached, Gate C suspended.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | n/a: no selector was added or promoted; unchanged selector authority supported by exact semantic changed-file inventory |
| Decisive claims independently re-derived | GitHub two-file commit patch and post-source compare; outer ZIP/source hashes, 28/28 member hashes, 8 targets, GMP/GMPXX, five clean statuses, no runtime |
| Non-vacuity checked | Rejection-only site not runtime-proven; TB25 3 A5 rows + 2 D3 witnesses + 6 PASS guards/controls |
| Prior obligations discharged/carried | RA-124.5 reviewed/accepted; RA-124.6 frozen; RA-124.3–.4 seam-contract question carried to TB25-REV/DEFN-SEAM |
| Stable accounting | 66/17/49, debt 1, CP2 491/491 accepted; CP3 candidate unpromoted; selector 497 unchanged |
| New candidates/obligations recorded | No new candidate; existing A5-ISO/D3 obligation retained in tracker, plan defines falsifiers and owner |
| ORIENTATION currency line | Updated to RA-125 and TB25 next (2026-10-21) |
| ORIENTATION §3 / §4 / §7 / §8 | §3 and §7 updated; §4 n/a no new runtime witness; §8 n/a no new defect class |
| CHANGELOG | RA-125 single entry added |
| ROADMAP | n/a M6 CP3 remains active with no evidence promotion |
| Selector manifest | n/a no frozen selector bytes changed |
| LESSONS | Existing §§5–7 diagnostic, evidence, and review guidance applies; no new durable pattern |
| Consolidation under CLEAN_UP_POLICY | No per-turn documents folded: CB24 build record is still current immutable compile authority; RA-124 and TB24 are necessary for TB25 routing |
| Successor frozen | `M6-CP3-TB25-RP01-SEAM-FRAME-VALUES-HARVEST`; 11 exact identities, pre-registered routing, falsifiers and stop rules in `Architecture_M6_CP3_TB25_Seam_Frame_Values_Harvest_Plan_20261021.md` |
| Turn boundary held | Review only; no product/test/selector/fixture source mutation; no Directional runtime |
| review_check.py boundary | Ran on verified source snapshot; history-dependent baseline checks fail because snapshots intentionally exclude `.git`. GitHub commit/compare independently verify two-hunk semantic scope; no fabricated history-backed PASS claimed |
| `STATUS` lifecycle maintained | Entry beacon published, final beacon after documentation push |
| Pushed to origin, branch in sync | Must be verified after application: no local Git history or `git status -sb` claimed |
