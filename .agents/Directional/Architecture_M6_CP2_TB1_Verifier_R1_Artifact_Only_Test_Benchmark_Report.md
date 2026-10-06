# M6-CP2-TB1-VERIFIER-R1-EXEC — Artifact-Only Test + Benchmark Report

**Disposition:** COMPLETE / VALID SEMANTIC RED / **462/491** / RUNTIME EVIDENCE-UPLOAD DEFECT / CANDIDATE UNPROMOTED.

This turn consumed immutable package `11382000465` / semantic source `9c8478aec40bf07144ca7372c2aa58293cd42f5e` without rebuild, relink, configure, package repair, generated discovery, or source/test/fixture/selector mutation. The frozen gate was exactly focused30 + CP2-focused12 + selector449 = **491 fresh exact-filter processes**.

## Immutable candidate authority

- compile/result artifact: `11382000465`;
- semantic source: `9c8478aec40bf07144ca7372c2aa58293cd42f5e`;
- candidate ZIP SHA-256: `e02e393375de3004beaf725cb859c7ad32e04456df56eb0c2c2239ad5deed4c1`;
- candidate root `SHA256SUMS` SHA-256: `8f3802506f108cc4003a620e322d012463d65ec7aece1bab37bce2e2ccecdc04`;
- source archive SHA-256: `a0bf6c0e87731843c704290aa8854a6adf9cf13f64a66252a2c658a20d51cf6d`;
- package root manifest: **28/28** before execution and again during postflight;
- exact arithmetic: GMP/GMPXX;
- entering Code + Build boundary: `runtimeExecution=false`.

Frozen gate hashes were unchanged:
- focused30: `1e815443a03c7ef4a1b095e6ea973efa9c74bb0eae4e2f872510c97d057ea1d6`;
- CP2-focused12: `2aa57aac48ac8c41ea86ed459cdd1acd27eb17c8d3dbe1b4ac7b9c54c67374ed`;
- selector449: `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`;
- routing449: `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707`.

## Runtime authority

Workflow run `37393554373`, trigger SHA `f2b595d3a3249183be0ebba2c39465067f4547f9`:
- schema validation job `112044038422`: SUCCESS;
- runtime job `112044082007`: workflow job FAILURE only because the two post-runtime upload steps referenced stale output paths;
- mailbox job `112045089158`: SUCCESS;
- authoritative mailbox: `.workflow-mailbox/m6-cp2-tb1-verifier-r1-exec/latest.json`.

The runtime harness itself exited **0** and printed
`M6-CP2-TB1-VERIFIER-R1-EXEC_COMPLETE: 491 fresh exact-filter artifact-only processes complete; semantic interpretation deferred to Review.`

The harness therefore completed all 491 executions and its package/source/execution-view postflight. The workflow then attempted to upload:
- `${RUNNER_TEMP}/M6-CP2-TB1-VERIFIER-EXEC-result`;
- `${RUNNER_TEMP}/M6-CP2-TB1-VERIFIER-EXEC.log`.

Those are the predecessor turn's hard-coded paths. The R1 harness wrote under `M6-CP2-TB1-VERIFIER-R1-EXEC`, so both `actions/upload-artifact` steps failed with "No files were found". This occurred **after runtime completed**. No duplicate runtime retry is authorized. Consequently there is no R1 runtime result/log artifact; the GitHub job log is the durable execution evidence and the mailbox correctly records run-level failure.

## Mechanical gate re-derived from the GitHub runtime log

Every enumerated row appears exactly once with one `[ RUN ]`, zero skips, and a terminal PASS/RED result.

- focused30: **26/30 PASS**, RED ordinals **6, 20, 24, 25**;
- CP2-focused12: **11/12 PASS**, RED ordinal **6**;
- selector449: **425/449 PASS**, RED ordinals **115, 116, 122, 130, 132, 134, 137, 141, 143, 144, 150, 176, 201, 217, 218, 231, 232, 246, 436, 437, 438, 444, 446, 448**;
- aggregate: **462/491 PASS**;
- exact-one selection: **491/491**;
- skips: **0**;
- benchmark executions: **0**.

### focused30 RED identities

1. ordinal 6 — `M5CP3.ProducedTorusPeriodicPairStorageSwapPreservesSemanticDirection`
2. ordinal 20 — `M6CP1.NonzeroZ4WitnessPassesProductionCompletionOwnership`
3. ordinal 24 — `M6CP1.ThinAdapterOutputIsPureProjectionOfStageProducts`
4. ordinal 25 — `M6CP1.A6ClosedComplexBoundaryIsCombinatoriallyEquivalentOnProducedTorus`

Ordinals 6, 20 and 24 visibly fail because production returns `VerificationFailed:MissingPublishedAuthority:a7:a5-relation-step`. Ordinal 25 fails because the expected produced torus no longer reaches `hasArrangement`; Review must determine whether this is the same upstream rejection or a distinct effect.

### CP2-focused12 RED identity

Ordinal 6 — `M6CP2.CertificateChainRequiresExactA5A6A7PayloadBinding`.

The strengthened >=2-step-path witness reaches its new baseline assertion and `verify_m6cp2_records(pathRecords).verified()` is false before the intended tamper assertion. This is Review-owned; EXEC does not decide whether the witness construction is invalid or the verifier over-rejects a valid published path.

### selector449 RED identities

`115, 116, 122, 130, 132, 134, 137, 141, 143, 144, 150, 176, 201, 217, 218, 231, 232, 246, 436, 437, 438, 444, 446, 448`.

At least 18 selector RED rows and three focused30 RED rows visibly report the same new production rejection:
`VerificationFailed:MissingPublishedAuthority:a7:a5-relation-step`.

Selector ordinal 144 separately reports
`VerificationFailed:SourceIncidenceMismatch:a0:component-adjacency`.

Several other selector rows fail downstream reachability/assertions after the authoritative pipeline no longer reaches their expected seam. Review must cluster causal versus secondary REDs before any stable repricing or repair authorization.

## Review-owned candidates

- **CAND-01 — A7/A5 relation-step over-rejection cluster.** A broad previously-green surface now fails at `a7:a5-relation-step`, including accepted focused30 and selector449 rows. This is a candidate production regression until Review checks whether the new exact citation predicate is stronger than the published A5/A6/A7 contract.
- **CAND-02 — focused12 ordinal 6 baseline invalid.** The new >=2-step test record does not verify before its intended tamper; this may be a witness construction defect or evidence of the same exact-citation defect.
- **CAND-03 — A0 component-adjacency rejection.** Selector449 ordinal 144 rejects previously accepted materialization at `a0:component-adjacency`; Review must determine whether the recomputation changed the frozen component equivalence semantics.
- **EXEC-OBS-01 — result/log upload path defect.** Orchestration-only and post-runtime: the caller retained predecessor output paths. It does not change the 491 runtime results, but prevents the normal immutable runtime-evidence artifact from existing. Do not rerun runtime merely to recover those artifacts.

No candidate is promoted or repaired in EXEC. Stable accounting remains **60 events / 16 categories / 44 recurrences**, architecture debt **1**, pending Review adjudication.

## Boundary and mandatory successor

Candidate package `11382000465 / 9c8478aec40bf07144ca7372c2aa58293cd42f5e` remains **unpromoted**. Reviewed runtime authority remains `11330703256 / 3f40f04a0e9d382b2ec82cf37a03c18ad405eb05` (479/479).

The exact next turn is mandatory independent `M6-CP2-TB1-VERIFIER-R1-REV`. It must re-open run/job `37393554373 / 112044082007`, independently adjudicate all 29 RED rows and the missing result/log artifact, cluster causal versus downstream failures, and freeze the smallest bounded recovery. No source/test repair or runtime retry is authorized before that Review.
