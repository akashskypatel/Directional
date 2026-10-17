# Architecture M6 CP3 TB1 Entry R1 Artifact-Only Test + Benchmark Report

**Turn:** `M6-CP3-TB1-ENTRY-R1-EXEC`
**Disposition:** execution mechanically complete; semantic candidate remains unpromoted; mandatory Review next.

## Immutable authority and execution

- Durable-dispatch run/job: `37645974118 / 112876903729`.
- Dispatcher request/event SHA: `801ca2c70ed172c9d4e758833db411514cc5cd78`.
- Exact executor/harness commit: `0a402104d7d82166fbf451ae8df44301f46f31b3`; harness SHA-256 `947a95ee4f684143a0f8d7c768a39253ab893d921da488802b45fb6ed58879dd`.
- Semantic source/package: `68000a95a94b1d95f22694dc093dc6a538e1b7b4` / compile artifact `11488700954`.
- TB result/log artifacts: `11495166428 / 11495391140`; provider digests `5ee8380ee7bb557a58274ef0b7cefa47e1abf1ef549650afcb7fff1330f161a6` / `4feb512e507caa9236c4250b8e400b116db98ab930ebf2241385d7c78f10311d`. Wrapper log artifact `11495850652`, digest `9c7ecb48f4696baa573f49dee0a36ee56e5b6350be6230174ff60cb0d96baffc`.
- Result self-manifest verifies **1019/1019**; candidate package root manifest verifies **28/28** before and after execution.
- Immutable postflight: package/source/execution-view censuses equal; focused30/focused12/selector449/routing449 hashes unchanged.
- Boundary: exactly **497** fresh exact-filter processes; exact-one selection preserved; zero skips; benchmark 0; no configure/compile/relink/generated discovery/package repair/mode repair/source-test-fixture-selector mutation/runtime retry.

## Mechanical result

- focused30: **23/30 PASS**, RED ordinals `6,20,24,25,26,27,28`.
- focused12: **12/12 PASS**.
- selector449: **446/449 PASS**, RED ordinals `444,446,448`.
- CP3-entry: **1/6 PASS**, RED ordinals `1,2,3,4,5`; identity 6 passes.
- Aggregate: **482 PASS / 15 RED**.

RA-31a pre-registered only identity 2 as RED, and only after its non-vacuity premise and A5 production pass with failure confined to the withdrawn certificate assertions. This execution therefore does **not** satisfy the 496+1 acceptance shape. Identity 2 fails earlier because no required produced HardRail witness is found.

## EXEC candidate classification — non-stable until Review

Every RED is assigned exactly once; EXEC does not reprice stable accounting.

1. **R1-CAND-01 — carried A6/D7 OrdinaryFront isolation-side evidence recovery incomplete (10 rows).** focused30 `6,20,24,25,26,27,28` plus selector449 `444,446,448`. Five rows explicitly stop at `MissingIsolationSeamEquivalenceAuthority:a6-side-evidence`; the remaining five lose their A6/arrangement/view product downstream on the same produced-torus chain. This is candidate evidence that P2 did not fully recover the already-stable `RP-01 AUTHORITY_DOMAIN_CONFLATION` recurrence; mandatory Review must independently confirm whether all ten rows share that root.
2. **R1-CAND-02 — D1 produced witness non-vacuity still absent (1 row).** CP3-entry identity 1 fails its required 90/270-degree face-gauge delta assertion before the authority/tamper checks. This is non-stable test/witness authority pending Review.
3. **R1-CAND-03 — D2 produced HardRail witness non-vacuity still absent (1 row).** CP3-entry identity 2 cannot find the required produced cross-region HardRail with a 90/270-degree endpoint gauge difference. This is earlier than the RA-31a pre-registered certificate RED and therefore is **not** the expected acceptance RED. Non-stable witness/certificate-definition authority pending Review.
4. **R1-CAND-04 — D3 real-tracer seam-collinear OrdinaryFront reachability gap (1 row).** CP3-entry identity 3 cannot obtain the required relation (`relation == nullptr`) before seam-transition assertions. Non-stable produced-witness authority pending Review.
5. **R1-CAND-05 — D4 typed hard-feature barrier witness/oracle remains unsatisfied (1 row).** CP3-entry identity 4 observes the selected ordinary carrier route empty where the test requires a governed transition/barrier path. Non-stable oracle/reachability authority pending Review.
6. **R1-CAND-06 — D7 produced seam-collinear relation reachability gap (1 row).** CP3-entry identity 5 cannot obtain the required produced relation (`relation == nullptr`). Non-stable produced-witness authority pending Review.

Stable accounting remains **63 events / 17 categories / 46 recurrences**, debt **1**, until mandatory R1 Review. No runtime retry, test weakening, or source repair is authorized in EXEC.

## Next

Mandatory `M6-CP3-TB1-ENTRY-R1-REV` independently re-derives the result, adjudicates all six candidate groups/15 rows, and decides recovery versus a bounded successor. CP3 exit remains held.
