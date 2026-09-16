# M4-CP-SCALE-TB7 Artifact-Only Test + Benchmark Report

**Turn:** `M4-CP-SCALE-TB7-EXEC`
**Disposition:** **COMPLETE / MECHANICALLY GREEN / SEMANTICALLY UNADJUDICATED / REVIEW REQUIRED**
**Authoritative execution run/job:** `35045130314 / 104633231692`
**Control/event SHA:** `079ad08cd381ce7f8f36dd8432c3f15ccecf1f17`
**Immutable candidate artifact:** `10425344367` (`1e29c9f3348b2e153d563c7e94acdaea52be8f16f6520fa8603fa084bba734bc`)
**Semantic source:** `01b1124af094044e32d6887ff0615881333d12ce`
**Selector under test:** `Architecture_M4_CP_SCALE_CB8_Required_Green_Selector_425.txt`, 425 rows, SHA-256 `e0e0f394faae536ac257ec5409653a34755a8afe0ca437562eb44c9895790e0b`
**Mandatory successor:** `M4-CP-SCALE-TB7-REV`

## 1. Boundary and immutable provenance

TB7 stayed within the artifact-only Test + Benchmark boundary. It consumed exact CB8 candidate artifact `10425344367` and did not configure, compile, relink, repair, regenerate discovery, mutate package/source/test/fixture/selector bytes, or execute benchmarks. The package entered TB with `runtimeExecution=false`; runtime began only after immutable preflight completed.

Preflight independently re-verified:

- provider artifact SHA-256 `1e29c9f3348b2e153d563c7e94acdaea52be8f16f6520fa8603fa084bba734bc`;
- semantic source `01b1124af094044e32d6887ff0615881333d12ce` and packaged source archive SHA-256 `32dadccc50a33a40e24f3f47f412203bd4b8f64fe8c87a72f066328c8f49fbb2`;
- package `SHA256SUMS` SHA-256 `9d91ff51fce9133b25c970eeab68e9a30ec7c449498ad387497e4fc74834d144`, **28/28** entries;
- selector425 exactly **425 unique LF rows**, SHA-256 `e0e0f394faae536ac257ec5409653a34755a8afe0ca437562eb44c9895790e0b`;
- first424 selector prefix SHA-256 `f202a1720c0a5288471d04836402b8432eb6f4f788da68a12e70dacb875466ca` and row425 exactly `M4CPScaleS3.ExactTraversalStateRepeatPublishesLimitCycleTermination`;
- owner census **30 authority-kernel / 279 producer / 75 completion / 41 validation**;
- GMP/GMPXX build evidence and executable-mode/loadability checks for all four owner binaries.

## 2. Pre-runtime orchestration correction provenance

Initial attempt run/job `35044943849 / 104632684747` failed before any Directional executable ran. The temporary execution workflow invoked `.agents/Directional/turn-payloads/m4-cp-scale-tb7-exec.sh` without first checking out the orchestration source, so Bash exited `127` with `No such file or directory`. The result upload then had no `tb7-result` directory; the diagnostic-log artifact `10426379208` was retained with provider SHA-256 `9f4c95dfa152b2d1449d3ac5fd1a573629d64ef8afdcc26d8a821fe467fb4e81`. No selector process executed and no semantic ledger exists for that attempt.

The bounded correction changed only temporary orchestration: initialize a blocked pre-runtime result and checkout the exact event SHA before invoking the existing harness. Candidate artifact/source/test/fixture/selector bytes were not rebuilt or mutated. The corrected workflow was schema-validated before fresh retry. Fresh retry `35045130314` is therefore the only TB7 runtime authority.

## 3. Selector425 cumulative runtime result

Selector425 executed in exact file order as **425 fresh exact-filter processes**. Every row selected exactly one test, executed exactly one test, exited zero, passed, and skipped zero.

| Measure | Result |
|---|---:|
| Executed | **425 / 425** |
| PASS | **425** |
| RED | **0** |
| SKIP | **0** |
| Crash | **0** |
| Timeout | **0** |
| Selection mismatch | **0** |
| Unexecuted | **0** |
| Authority-kernel | **30 / 30** |
| Producer | **279 / 279** |
| Completion | **75 / 75** |
| Validation | **41 / 41** |

Row424 `M4CPScaleS2.VertexStarCertifiedFilterMatchesIndependentExactOracle` ran freshly as process 424 and PASSed. Row425 `M4CPScaleS3.ExactTraversalStateRepeatPublishesLimitCycleTermination` ran freshly as process 425 and PASSed **1/1**; no TB6 focused runtime was imported as cumulative credit. Row425's raw stdout contains the expected structured receipt:

`m4CpScaleS3;exactRepeat=LimitCycleTermination;differentExactEntry=Advanced;loadBearingTamperCount=4;combinatorialRecurrence=TraceCombinatorialRecurrenceExceeded;stepBudget=TraceStepBudgetExhausted`

EXEC records this mechanically; semantic interpretation and cumulative promotion remain Review-only.

## 4. Immutable postflight

Postflight completed successfully:

- package census equal before/after;
- semantic-source census equal before/after;
- execution-view census equal before/after;
- package manifest re-verified **28/28**;
- selector425 re-hashed to `e0e0f394faae536ac257ec5409653a34755a8afe0ca437562eb44c9895790e0b`;
- first424 prefix re-hashed to `f202a1720c0a5288471d04836402b8432eb6f4f788da68a12e70dacb875466ca`.

The prohibition receipt records `configureExecution=false`, `compileExecution=false`, `relinkExecution=false`, `repairExecution=false`, `generatedDiscovery=false`, `mutationExecution=false`, and `benchmarkExecution=false`.

## 5. Evidence package

- result artifact `10426872680`, provider SHA-256 `676f6f5adab0992a8d334c5952fc133c3d0b3fa4eb93dd5128180ee4705f02b2`;
- detailed log artifact `10427326246`, provider SHA-256 `b8374c33152362ab2feab31b4b2ab87f8118e7ed9b5b2fe275669bcbff60ca4f`;
- nested evidence ZIP SHA-256 `436ef2722c176e92aca64c4d052d7953b979ead0e23bda33e16eb5d317a41c4d`;
- nested non-self-referential evidence manifest SHA-256 `5639b84372c453ee42b8c3fbf0d09425ca0a34da72dd0629ceb2769982f14622`, **1298/1298** entries verified;
- process ledger exactly 425 data rows plus header, owner census **30/279/75/41**, all PASS;
- per-process raw stdout/stderr, resource receipts, package/source/execution censuses and checksum receipts retained in the nested evidence ZIP.

Final status is `status=MECHANICALLY_GREEN`, `selector425=425/425`, `runtime_processes_actual=425`, `postflightComplete=true`, `runtimeStarted=true`, `runtimeCompleted=true`.

## 6. Regression/accounting disposition

`M4-CP-SCALE-TB7-EXEC-CAND-01` is **CLOSED / ORCHESTRATION FALSIFIER PASSED / NON-STABLE**: the first attempt omitted repository checkout and stopped before runtime; the corrected fresh retry completed all preflight/runtime/postflight gates without candidate mutation.

TB7 observed **no product-semantic regression and no accepted-green loss**. Stable accounting remains **49 events / 14 categories / 35 recurrences**; produced-witness debt remains **5**. `M4-CP-SCALE-TB6-REV-OBS-01` advances to **PUBLICATION + CUMULATIVE RUNTIME SATISFIED / REVIEW OWED / NON-STABLE**; EXEC does not discharge it.

## 7. Mandatory Review boundary

TB7-EXEC makes no promotion claim. Accepted runtime authority remains TB6-reviewed package `10418328122` / source `153047c3f92e9b9b784e11eaee1ede2de5628470` under selector424 **424/424** until mandatory `M4-CP-SCALE-TB7-REV` independently reopens the CB8 package and TB7 evidence, re-derives selector/prefix/ownership/process outcomes and immutability, and decides whether selector425 becomes accepted cumulative M4 authority and whether `M4-CP-SCALE-TB6-REV-OBS-01` is discharged.
