# TB27 — A7 certified-seam cross-sheet verification (2026-10-22)

**Turn:** `M6-CP3-TB27-RP01-A7-CERTIFIED-SEAM-CROSS-SHEET-VERIFICATION`. **Boundary:** artifact-only Test + Benchmark, strictly scoped to 21 prescribed identities (the unchanged 18 TB26 cases plus three RA-130.9 A7 guards). No tests, fixtures, production source, frozen selector, build/compile/relink, or benchmark were modified/executed in this workload.

## Immutable authority and procedure

- Exact CB26 semantic source `e3d60337ed34538547d3a6d519bafae5b184330e`, eight-target GMP/GMPXX compiled artifact **12409939859**, ZIP SHA-256 `ee08279e537af4e99f287d28595df0ef639e632aa345bc0b1986bbb361ee86fa`, compiled with `runtimeExecution=false`; package **28/28** internal hashes.
- Initial harness source commit `b6f2e16b56b3a12a4eecec4ac2d6507a8f06e88b`, [run 39761406833](https://github.com/akashskypatel/Directional/actions/runs/39761406833), result **12419380993**, ZIP SHA-256 `7b64a79c3a3a26eeac77862e88884c91bbddfceaef5e369134aaf53ea49d1e46`: 21/21 PASS, but Python ZIP extraction followed by `chmod` violated immutable executable-mode extraction policy. Diagnostic evidence only; **not** the procedure-accepted run.
- Corrected harness commit `60414d738eb61a8aa747ba15e9fd65a61071b769`, SHA-256 `5e3ca0a7c513d5373ee200b2442af315d7845d2dce81c6ea71b971ccbff2fe1f`: uses `unzip -q` to retain archive modes, verifies executable mode rather than repairing it. No test-selection, assertion, package, or runtime semantic change. Re-dispatched at `24ed359dd675e52265d08ee1144917a6c90c17d6`.
- **Authoritative compliant run:** [39764327506](https://github.com/akashskypatel/Directional/actions/runs/39764327506), result artifact **12420676412** (ZIP SHA-256 `33dc0878cd4dd0592b1ad2ae0b436b2606c7a59e45cbc0e929358d6213f7babb`), log artifact **12420586601** (`60dd152a5b404c5ffedb50c6f46e2a12758c249bae00763180d96749e59f55de`). Result: **24/24** manifest entries verified. Runtime and mailbox jobs completed successfully, result `exit=0`.
- Twenty-one separate raw logs independently contain exactly one `[ RUN ]` and one `[ OK ]` each. Ledger: **21/21 executed/PASS**, zero RED, zero missing/skip, zero duplicate selection; 10 A5, 2 D3, 1 prior guard + 5 controls, 3 new A7 guards. Package and source pre/post verified unchanged (`postflight=true`), with `compile=false`, `relink=false`, `benchmarks=false`, `selector497=false`. Runtime links `libgmpxx.so.4` and `libgmp.so.10`.

## Measured A7 gates (targeted, not full acceptance)

- All ten A5 torus/adapter cases (`focused30:6,20,24,25,26,27,28`; `selector:444,446,448`) PASS. Prior TB26 nine-RED seam-family census is absent in these focused test runs; the ledger has no first-failure site for these tests.
- D3 `cp3entry:3` and D7 `cp3entry:5` PASS their existing assertions, including the quarter-turn/evidence-tamper guards specified by RA-131; each case is independently selected, not inferred from a downstream pass.
- Previously frozen controls/guard `selector:447`, `cp3entry:6`, `selector:217`, TB18 A#14, `selector:443`, `focused30:7` all PASS. Three new guards PASS: `M6CP1.A7CrossSheetBindingRequiresConnectingIsolationTransition`, `M6CP2.A7WedgeTransitionWrongRegionRejects`, `M6CP2.A7WedgeTransitionTouchWithoutConnectivityRejects`.
- No logged `cross-sheet:seam-direction` in the A5/D3 targets; `seam_direction_bad=0`, `periodic_bad=0`, `site_bad=0`, `control_bad=0`. The harness checked for these sites, but **does not** prove general Periodic correctness. The original targeted falsifiers did not fire.

## Regression disposition and boundaries

- **Targeted candidate improvement only**, relative to TB26 18/18 executed, 9 PASS/9 RED. No new stable regression event or category is established, and TB27 alone cannot promote or delete an existing stable event. Totals remain **66 events / 17 categories / 49 recurrences**, produced-witness debt **1**. CP2 accepted **491/491**; rejected R3 **403/497**, TB21 candidate **449/497**, selector **497** byte-frozen. RP-01 OPEN, RP-02 UNREACHED, Gate C suspended.
- TB27 executed 21 prescribed identities **only**; neither full selector-497 nor full-suite acceptance was attempted. Periodic positive and nonzero-turn seam witnesses remain unmeasured; RA-127.4b / RA-130.7 negatives and separate `DIAG-RETAIN` work remain deferred.
- **Independent TB27 Review is mandatory** before promoting any runtime acceptance or authorizing CB27. The exact canonical Review ID is not assigned by current handoff/RA-131; leave successor `UNKNOWN` and STOP instead of inventing it. Source, package, result and immutable raw logs are available for independent review.
