# TB76 independent review — Linux Vase census mismatch (2026-11-04)

**Canonical turn:** `M6-CP3-TB76-P13-OPTIMIZER-SOURCE-QUERY-FULL-GATE-REV`. **Verdict: execution evidence valid; registered Vase outcome NOT MET; no CP3 promotion.** Review is runtime-free; source, tests, fixtures, benchmarks, selectors and build configuration remain unchanged.

## Independently reopened evidence

- Exact compiled semantic source `2278b8b649b4262fb70a522371ed282655383af5`, CB83 immutable package `13289188434`; gate [41762112729](https://github.com/akashskypatel/Directional/actions/runs/41762112729), result `13290723379`; census [41762169855](https://github.com/akashskypatel/Directional/actions/runs/41762169855), result `13291024099`. Verified current source snapshot at `d0552e7bfd0233baae28a4d62040edb2bfa24cce` (run `41766563493`), archive digest `ebabd695b6a3a3eb5753dd6201426efbaecbd3d5aae154a137e9cebbe75b28b1`.
- Rehashed TB76 manifest **`3b72716137800726f9ce46a7ea6aee1f8a7db0122be29df97c359ea098545bf8`**, 893 entries. First 890 records are *byte identical* to TB75 manifest, SHA-256 **`a134d9411bd5885fa85d7405e2a733da7cd4d5899d17a83f6dbcb501d18326c6`**. TB76 adds exactly GUARD rows 891–893.
- Independently verified gate artifact **1794/1794** SHA256SUMS and all **893/893** ledger→raw-log hashes; gate boundary 893 planned/executed/passed, 0 RED/ABNORMAL, membership **974**, 81 deferred (974−893), postflight true, no configure/compile/relink/benchmark.
- Independently verified census artifact **9/9** SHA256SUMS and **3/3** ledger→raw-log hashes. Counts **one PASS, one RED, one ABNORMAL**, 3/3 executed, postflight true. Cylinder PASS (6.33 s); BunnyRandom RED (`SingularityPortClassCountMismatch;sourceVertex=49`, 0.589 s); Vase **ABNORMAL exit 124** / `HARNESS_TIMEOUT 600s`.
- Vase raw log contains source-field partition and two sets of three `region_support_projection` diagnostics. It has **no completed terminal, output-quad count, or stage-duration receipt**. The Linux package has not independently produced `SelfIntersectingFace` / 67,829 quads. Neither the location of the 600 s cost nor effectiveness of CB82 on Linux can be inferred from these logs alone.

## Assessment and falsifiers

1. The 893 passing gates exercise scoped contracts but do not establish direct Vase D0 acceptance: the census is an off-gate production-path witness and its registered RED did not occur. The three new GUARD checks are non-vacuous with respect to their observed paths (their named tests executed and passed), but the macOS mutants reported in RA-201.12 are not independent Linux mutant results.
2. RA-201 macOS scratch timing (approximately 246–252 s uncontended, 428 s concurrent) is **competing evidence**, not a Linux guarantee. The hypothesis that repeated source-binding checks or construction remain hot is plausible from static source and prior samples, not measured in the failed Linux process. The final log marker does not identify the active stack or stage after it.
3. **Do not promote** selector497, CP3, CB83 Vase acceptance, or claim a new stable regression. Accepted CP2 **491/491**, stable events/categories/recurrences **66/17/49**, produced debt **1**, deferred ledger **81** remain unchanged. Keep P13-l completed-mesh orientation and P13-e BunnyRandom port-count Reviews independent.

## Exactly one successor: `M6-CP3-CB84-P13-LINUX-VASE-DIAGNOSTIC-TIMING` (Code + Build, compile-only)

**Owner:** Linux execution observability at source-cell stage boundaries. Before changing cost logic, introduce the smallest diagnostic-only, source-authoritative stage timing/progress surface that reports entering and leaving all stage boundaries through completion and pre-optimization validation on stderr, with monotonic elapsed times and immutable stage names. Prefer existing stage timers; do not add per-element logging or expensive global checks. Preserve failure/geometry behavior, existing timed GUARD contracts, and source/selector/fixture data. Compile/package with GMP/GMPXX only; **no runtime in CB84**.

**Next separate TB (not authorized in this turn):** run the frozen CB84 package on the same Linux Vase census input with identical 600 s ceiling and passive log capture. A completed validated terminal with 67,829 quads, `SelfIntersectingFace` and bounded wall time would falsify the continuing Linux timeout. A timeout with stage-entry but no stage-exit identifies only the *stalled stage*, not yet the inner hot function; if so, use bounded stack sampling in a later separate diagnostic step. If the diagnostic changes stage output, geometry or verdict, reject it as an observer effect; no test expectation edits, retry of TB76, fallback/recovery, or registration weakening. Required supporting checks: prior gate unchanged, existing stage receipt still reaches Cylinder, and instrumentation does not cause a new timeout in the short fixture.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | TB76's 890-record predecessor byte-identical, hashes above. Accepted CP2 selector unchanged; no promotion. |
| Decisive claims independently re-derived | Gate 893 logs/1794 hashes; census three logs/9 hashes; boundary arithmetic and raw Vase timeout verified. |
| Non-vacuity checked | 891–893 executable GUARDs passed; production Vase off-gate still ABNORMAL; macOS mutants not counted as Linux proof. |
| Prior obligations discharged/carried | RA-201.10 TB76 EXEC rechecked; P13-k Linux cost locus carried to CB84; P13-l and P13-e remain independent. |
| Stable accounting | 66/17/49; debt 1; accepted CP2 491/491; selector497/CP3 not promoted. |
| New candidates/obligations recorded | Linux Vase diagnostic-cost obligation carried; no new stable event. |
| ORIENTATION currency line | TB76 REV 2026-11-04 updated. |
| ORIENTATION §3 / §4 / §7 / §8 | §3 and §7 updated; §4 unchanged because no witness state changed; §8 cites existing RA-200/RA-201 cost lesson. |
| CHANGELOG | Review entry added. |
| ROADMAP | No checkpoint promotion; no status movement. |
| Selector manifest | No selector acceptance/addition; no update. |
| LESSONS | Existing RA-200/RA-201 performance-location and evidence lessons cited; no new general lesson. |
| Consolidation under CLEAN_UP_POLICY | Current review references existing retained TB76/RA-201 reports without deleting evidence. No superseded report safe to fold in this bounded turn. |
| Successor frozen | `M6-CP3-CB84-P13-LINUX-VASE-DIAGNOSTIC-TIMING`; bounded instrumentation and falsifiers above. |
| Turn boundary held | Static artifact review only; no program/bench/build execution. |
| review_check.py boundary | Local snapshot has no `.git` history; cannot run authoritative boundary/ancestry subcommand here; intended-path diff and patch checks are separate verification, not a substitute. |
| `STATUS` lifecycle maintained | Initial review beacon written; final status follows only after durable commit. |
| Pushed to origin, branch in sync | Pending durable Drive patch application and readback; do not claim until verified. |
