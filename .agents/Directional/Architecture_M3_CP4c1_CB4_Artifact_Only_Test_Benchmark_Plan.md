# M3-CP4c-1 CB4 Artifact-Only Test + Benchmark Plan

## Validation Identity

- Phase: `M3-CP4c-1-TB-R5`
- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`
- Evidence commit to validate: `b1ce8ad65952bd2bd76238f6dfc55523f6a24747`
- Build artifact: `9675666067` (`m3-cp4c1-cb4-compile-result-33145657048`)
- GitHub artifact/ZIP digest: `sha256:63b66788e724f7f22acc5f3bd204a1eb666a779ced96d1373f320e00cd45ec17`
- Compile log artifact: `9675666340`, digest `sha256:582791557b87d2be9ffcaf99fcca928a55b6aaf177de44654a235e05f58070c2`
- Packaged source archive SHA-256: `baead768e6f05acc7b09177a1571139262a514056cfc4fa281b8933135b6fc84`
- Exact arithmetic backend: GMP
- Required selector: `.agents/Directional/Architecture_M3_CP4c1_Required_Green_Selector.txt`, **355**, SHA-256 `e9d88f1196e412e06424294d6be22b32f01c9671ec5e4de119abd3f2fb5afeaa`
- Non-gating selector: `.agents/Directional/Architecture_M3_CP4c1_Non_Gating_Diagnostic_Selector.txt`, **3**, SHA-256 `537a8010033452a16be5f6a80926ea61c065f7f7f443b5b2950f73c8b8ffcd6a`
- Planned environment/platform: GitHub-hosted Ubuntu runner, immutable artifact-only execution; no configure/build/relink/repair

## Validation Objective

Prove or falsify the independent review's CB4 prediction without changing source, tests, fixtures, selectors, or build semantics.

TB-R5 must establish in one immutable authority that:

1. the accepted predecessor remains an exact ordered **353/353 green prefix**;
2. C4 ordinal 354 and corrected C5 ordinal 355 are both green;
3. C5's two named-kind checks execute and pass individually, rather than being hidden by a prior fatal assertion;
4. the observed terminal-kind union and contributor map are exactly the review prediction;
5. the three remaining historical diagnostics remain report-only with zero gate credit;
6. the two retired W5 identities do not survive as unexplained reds; and
7. the package and extracted source remain byte/mode immutable before and after runtime.

The falsifiable semantic prediction from `Architecture_M3_CP4c1_TB_R4_Independent_Review_Record.md` §8 is:

- full gate **355/355 PASS**;
- terminal-kind union exactly `{TraceIntersection(2), MandatoryBarrierTermination(3), SingularityTermination(4)}`;
- `TraceIntersection` contributor = prescribed sphere;
- `MandatoryBarrierTermination` contributor = two-ring;
- `SingularityTermination` contributor = prescribed sphere;
- torus contributes zero kinds and passes vacuously;
- mechanical witness remains guarded out at A1 with `IncompleteCycleBasis`;
- accepted prefixes 316/316, 346/346, 353/353 PASS; C4 PASS.

Any semantic deviation is new evidence and routes back to independent review. It is not authorization for an in-TB correction or unchanged deterministic retry.

## Preconditions

Before executing any Directional binary:

- download exact artifact `9675666067` and verify GitHub's digest is `sha256:63b66788e724f7f22acc5f3bd204a1eb666a779ced96d1373f320e00cd45ec17`;
- verify all **28** entries in packaged `SHA256SUMS`;
- verify `metadata/source-commit.txt` is `b1ce8ad65952bd2bd76238f6dfc55523f6a24747`;
- verify `metadata/preflight-exit-code.txt == 0` and `metadata/build-exit-code.txt == 0`;
- verify every packaged source-status snapshot is empty;
- verify `metadata/command-boundary.txt` records `runtimeExecution=false`, `turnBoundary=Code+Build-only`, and `exactArithmeticBackend=GMP`;
- verify GMP/GMPXX runtime dependencies required by the packaged binaries are present;
- extract `source/source-b1ce8ad65952bd2bd76238f6dfc55523f6a24747.tar.gz` and verify SHA-256 `baead768e6f05acc7b09177a1571139262a514056cfc4fa281b8933135b6fc84`;
- verify required selector count/hash **355 / `e9d88f1196e412e06424294d6be22b32f01c9671ec5e4de119abd3f2fb5afeaa`**;
- verify first-353 hash `51ff96d72e1c2c88e9407e99737e42ec9093ea238aaf8b1e45ff2559f71ac6a5`;
- verify first-346 hash `20d3b0b1400d5cab6af4a339a858c56fb7fd0359fb995a395dad215b20f3e46a`;
- verify first-316 hash `601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c`;
- verify ordinal 354 is `FieldAlignedCurveNetwork.RejectsTamperedTraceIntersectionCrossing` and ordinal 355 is `FieldAlignedCurveNetwork.EveryTraceTerminatesAtATypedEventKindThatIsActuallyProduced`;
- verify non-gating selector count/hash **3 / `537a8010033452a16be5f6a80926ea61c065f7f7f443b5b2950f73c8b8ffcd6a`** and that the two retired W5 identities are absent;
- capture a pre-runtime byte-and-mode inventory of package, extracted source, fixtures, selectors, and executables.

Any mismatch is a blocker. Do not rebuild or repair the package in TB.

## Ordered Execution Plan

### 1. Required 355-identity gate

Execute the required selector in exact file order, **one identity per fresh process** against the packaged binaries. The selector is routing authority; do not use generated discovery to choose the test set.

For every ordinal record: identity, owning executable, selected count, exit code, elapsed time, PASS/RED, stdout/stderr, and whether an escaping `C++ exception with description` occurred.

Acceptance:

- ordinals 1-316: **316/316 PASS**;
- ordinals 1-346: **346/346 PASS**;
- ordinals 1-353: **353/353 PASS**;
- ordinal 354 C4: **PASS**;
- ordinal 355 C5: **PASS**;
- full selector: **355/355 PASS**;
- `zeroSelected=0`;
- escaping C++ exceptions: **0**;
- first red ordinal: **none**.

If a required identity executes and returns semantic red, preserve the exact first-red evidence. Do not edit code, test expectations, fixtures, or selectors.

### 2. W3 proof for C5's previously masked checks

C5 PASS alone is not sufficient reporting. The TB report must name and report each of these assertions separately:

- `producedTerminalKinds.count(FieldAlignedNetworkEventKind::TraceIntersection) == 1U` — current packaged-source `EXPECT_EQ` begins around `tests/FieldAlignedCurveNetworkTests.cpp:6345`;
- `producedTerminalKinds.count(FieldAlignedNetworkEventKind::MandatoryBarrierTermination) == 1U` — current packaged-source `EXPECT_EQ` begins around `:6350`.

These checks are unconditional after the corrected non-empty assertion. Therefore a trustworthy C5 PASS proves both were reached and passed; the TB report must still state that proof explicitly rather than collapsing it into “C5 green.”

Publish the observed terminal-kind union and contributor map. Use immutable runtime reports rather than deriving the answer from the review prediction:

- sphere/torus stage-reachability publisher output carries `producedTerminalEventKinds=` and `terminalEventTraceIds=`;
- run `ResolvedBranchCorrection.TwoRingContactPairingCensusIsPublishedNonGating` exactly once as an **additional W3 report-only diagnostic with zero gate credit** to publish the two-ring event-kind census/contribution needed to reconstruct the full contributor map.

The reconstructed union/contributor map must then be compared against the §8 prediction `{2,3,4}` / sphere, two-ring, sphere. This extra report-only identity is evidence instrumentation only; it is not added to either selector and grants no acceptance credit.

### 3. Three frozen non-gating CP4c-1 diagnostics

Execute each of the three identities in `.agents/Directional/Architecture_M3_CP4c1_Non_Gating_Diagnostic_Selector.txt` exactly once in a fresh process:

- `GlobalTopologyPlan.TorusWitnessStageReachabilityIsObservable`
- `GlobalTopologyPlan.MechanicalWitnessStageReachabilityIsObservable`
- `GlobalTopologyPlan.SpherePrescribedWitnessStageReachabilityIsObservable`

They intentionally use failure output as a historical report channel. For each, preserve selected count, exit code, elapsed time, and complete report text. They contribute **zero gate credit** whether PASS or RED.

Use the reports to verify the §8 reachability/contributor prediction, including torus zero contribution and mechanical A1 `IncompleteCycleBasis`. Do not rewrite these diagnostics in TB.

### 4. W5 retirement confirmation / candidate disposition

Confirm both retired identities are absent from the current non-gating selector and are not executed as unexplained reds:

- `FieldAlignedCurveNetwork.BranchBoundaryPairingContinuationIsUnique`
- `FieldAlignedCurveNetwork.PrescribedSphereCandidateTraceTransportFailureSiteIsObservable`

If that confirmation holds, record `M3-CP4c1-TB-R4-CAND-03` **RESOLVED / TEST-SIDE INVERTED PRECONDITION / NON-STABLE**, `+0` events and `+0` recurrences. If either identity unexpectedly survives as active test authority or produces unexplained runtime evidence, stop and route to review.

### 5. Immutable postflight

After all planned runtime:

- recompute package and extracted-source byte-and-mode inventories;
- verify packaged `SHA256SUMS` remains 28/28;
- verify required/non-gating selector bytes and hashes are unchanged;
- verify fixtures and executable bytes/modes are unchanged;
- record `configure=false`, `compile=false`, `relink=false`, `repair=false`, `generatedDiscovery=false`, and `mutationOccurred=false`.

A postflight mismatch invalidates acceptance.

## Benchmark Plan

- Applicable: **no performance acceptance benchmark**.
- Preserve per-identity elapsed times only as evidence, especially for prior termination regressions.
- Do not use a repository/job timeout to manufacture a semantic result for the required gate.
- Do not split/stitch partial required-gate executions into one acceptance result.

## Unit-Test Design Check

The unit-test correction was independently reviewed before CB4 and is frozen for TB-R5.

- Contract under test: every produced trace terminates at exactly one actually produced typed terminal event kind; the produced union is non-empty across productive witnesses; both `TraceIntersection` and `MandatoryBarrierTermination` are represented.
- Scenario/boundary represented: includes a legitimate zero-trace torus witness, productive two-ring and prescribed-sphere witnesses, and a guarded mechanical witness.
- Why fixture values expose plausible broken behavior: the witnesses jointly distinguish zero-productivity validity, barrier termination, trace intersection, and singularity termination without encoding an observed cardinality.
- Assertion semantics: per-trace terminal contract remains unchanged; non-vacuity replaces hard-coded count; two named-kind membership checks remain explicit.

No unit-test source may be edited inside TB-R5.

## Stop and Blocker Conditions

Stop execution and preserve evidence when:

- artifact/source identity or any frozen checksum/prefix hash is wrong;
- GMP/GMPXX runtime support is unavailable;
- a planned identity selects zero tests;
- package/source/fixture/selector inventory changes;
- workflow attempts configure, compile, relink, regeneration, repair, or semantic mutation;
- infrastructure failure prevents a trustworthy planned result.

Project-specific semantic stop rule: **any deviation from the independent review's §8 prediction is material and routes back to independent review.** Do not “correct” the test in TB and do not retry an unchanged deterministic semantic red.

## Plan-Defined Reruns

- No rerun for an unchanged deterministic semantic red.
- An orchestration-only retry is allowed only after diagnosing and correcting the control-plane defect while package/source/selectors remain byte-identical.
- If runtime began before an orchestration failure, retain that attempt as control evidence and identify exactly what executed.
- Never compile a replacement revision in TB.

## Completion Criteria

TB-R5 is complete when:

- exact immutable preflight is green;
- every one of 355 required identities has one trustworthy result;
- the full required gate is **355/355 PASS** to close CP4c-1;
- W3's two named-kind checks are individually reported as executed/passed;
- the observed terminal-kind union/contributor map is published and matches the §8 prediction;
- all three selector diagnostics plus the one W3-specific two-ring report identity have trustworthy report-only evidence with zero gate credit;
- `M3-CP4c1-TB-R4-CAND-03` is confirmed resolved or a deviation is routed to review;
- immutable postflight is green;
- raw result/log artifacts and exact run/job/artifact IDs/digests are preserved;
- every observed regression/candidate is classified in `Regression_Root_Cause_Tracker.md` before closeout.

On 355/355 with the full §8 prediction met, CP4c-1 may close and the following planning checkpoint is `M3-CP4c-2-DEFN`. Any valid semantic deviation leaves CP4c-1 open and routes to independent review.
