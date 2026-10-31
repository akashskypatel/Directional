# TB63 — CB64 Linux full gate and P13 census (2026-10-31)

**Turn:** `M6-CP3-TB63-P13-CENSUS-FULL-GATE-EXEC` (TB-EXEC). **Registered outcomes met:** immutable Linux full gate **863/863 PASS** (854 GUARD, 9 POSITIVE); separate three-row OBSERVE census **Cylinder PASS, BunnyRandom RED, Vase RED** at the pre-registered signatures. No independent Review, CP3/selector497 promotion, or source/test/build modification is claimed.

## Frozen inputs and provenance

- CB64 Linux Release/static eight-target GMP/GMPXX compile: [run 41221202501](https://github.com/akashskypatel/Directional/actions/runs/41221202501), package `13050072901`, semantic source `d56d990580163f4fd0ceda4137f7ecd16ceb6027`. Package ZIP SHA-256 `5ef36429396d3d21e9c7b184cd10cd3ef6bdcfc3333d55415a0440631aebad00`; **28/28** package hashes; generated links include GMPXX and GMP; compile metadata `runtimeExecution=false`. Package reused unmodified for both TB runs.
- Verified executor snapshot `f5b3aa8232327f296917409e88ad84cbcf76504a`, [run 41224062692](https://github.com/akashskypatel/Directional/actions/runs/41224062692), artifact `13051346095`: **6051/6051** source hashes and inner source archive hash verified. P8 artifact-only harness SHA-256 `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94`; prior `--self-test` 30 PASS; preflight both manifests passed.
- Full-gate manifest **863** rows SHA-256 `31c1360ab5738cab682e628304914af4a3f7ad4dd077a8f688e79536bf371341`, ledger v4 **82** deferred SHA-256 `36241caa61d3d27aa062fee05cf3af12a62a81a5a11a42e3ea75e46b0590139d`. Census manifest **3 OBSERVE** SHA-256 `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793`; no census membership ledger.

## Immutable artifact-only executions

| Evidence | Full 863-case gate | P13 three-case census |
|---|---|---|
| Event SHA | `14c1da0b85846fca80ad0b4a70c93437659a214f` | `e610201bc564f199304627a17ccaf8811b51e90b` |
| GitHub Actions run | [41224438897](https://github.com/akashskypatel/Directional/actions/runs/41224438897) `success` | [41224395380](https://github.com/akashskypatel/Directional/actions/runs/41224395380) `success` |
| Result artifact | `13051413577` | `13051470763` |
| ZIP SHA-256 | `b0ca28687f9b1c13e0ae65682d8815c59e69a76f500acef81ee3c6609513f12e` | `e672b76e8962d681d1cf79f91aa755599b809f1c1dd5f2212b9218b117bf15aa` |
| Internal SHA-256 receipts | **1734/1734** correct | **9/9** correct |
| Result | 863 PASS, 0 RED, 0 abnormal | 1 PASS, 2 expected RED, 0 abnormal |
| Boundary | `postflight=true`, `exit=0`, membership 945 | `postflight=true`, `exit=0`, membership 0 |

Both result `execution-boundary.json` files identify the exact source and package, `compile=false`, `relink=false`, `configure=false`, `benchmark=false`; no source, fixture, selector, manifest, deferred ledger or build changes occurred inside either workload. Dispatcher schema validation, parse, runtime and orphan-mailbox publication succeeded; compile and Drive-apply jobs were skipped. Both mailbox records on `workflow-mailbox` match their event and semantic source SHAs.

**Independent audit:** Exact ordered manifest ↔ result joins for all **863** `(row,kind,identity,test,binary)` tuples. All 863 expected PASS verdicts and fresh-process exit/one run/one pass/zero skip checked; all **863** raw logs independently rehashed against ledger digests and independently parsed for exactly one native GTest `[ RUN ]` and `[ OK ]`. Resource receipts 863/863. Exact membership set equals **863 GATED + 82 DEFERRED = 945**, with no duplicates or extraneous identities; deferred classes **47 FIXTURE, 7 PRODUCT, 23 OPEN, 5 RETIRE**. No result was inferred from the workflow success badge alone.

**Census raw-log confirmation:** `offgate:362` Cylinder PASS, independent GTest oracle, **16.419 s** in its single Linux process; `offgate:360` BunnyRandom expected RED `CutTransportDomainIdentityMismatch` and `cutChi=-3`; `offgate:365` Vase expected RED `detail=BranchContinuationExactMagnitudeExceeded`. Exact three-row identity/manifest joins, raw-log hashes and exit codes verified. Both REDs were explicitly pre-registered **OBSERVE**, not new gated regressions, and do not increase gate membership. Cylinder success is not a promoted 864th gate test; separate Review must make that decision.

## Classification and closeout boundary

No new accepted-green loss or unexpected Linux regression was observed. BunnyRandom's A3 tip–tip single-edge barrier slit and Vase's A4 exact continuation-width growth are existing RA-188 P13-c/P13-b architectural obligations, not regressions introduced by CB64. Stable regression accounting **66 events / 17 categories / 49 recurrences**, produced-witness debt **1**; accepted CP2 **491/491** unchanged. Row 283's Linux PASS does not discharge independently carried macOS O16. CP3 is not accepted; selector497 unpromoted; the 82 deferred cases remain unresolved.

**Authorized next turn under RA-188.5:** `M6-CP3-DEFN-P13-O15C-CONTINUATION-WIDTH` (Review/Definition), to choose the bounded Vase continuation policy and adjudicate Cylinder's gate promotion. No TB63-REV is required because both frozen executions matched. Separate BunnyRandom slit DEFN remains pending. No successor work is performed in this TB-EXEC turn.
