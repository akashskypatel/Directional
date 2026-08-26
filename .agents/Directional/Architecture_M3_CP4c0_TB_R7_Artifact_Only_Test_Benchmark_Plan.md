# M3-CP4c-0-TB-R7 — Artifact-Only Test + Benchmark Plan

**Status:** FROZEN BY `M3-CP4c-0-CB7`; execute only after the CB7 compile-only package is verified.
**Turn boundary:** Test + Benchmark only; immutable artifact execution, no rebuild and no repair.
**Purpose:** measure K1–K3 from the TB-R6 independent review, confirm K4/K5 diagnostic interpretation, and deliver evidence for `M3-CP4c-0-DEFN-2`. This is **not** a Q8-closure attempt. Q8 is expected to remain red at criterion 2 because CB7 changes no production semantics.

## 1. Frozen authority and prohibited actions

Before TB-R7 execution, copy the exact successful CB7 compile authority from the CB7 closeout report into the execution record:

- semantic source SHA;
- authoritative compile-only run/job;
- immutable result/package artifact ID and GitHub ZIP SHA-256;
- packaged source-archive SHA-256;
- compile-log artifact ID and SHA-256.

Consume **only** that immutable CB7 package. Before any generated Directional binary runs, verify:

1. package outer SHA-256 and recursive `SHA256SUMS`;
2. exact packaged semantic source SHA;
3. compile/preflight exit `0`, all required source-status snapshots empty, and `runtimeExecution=false`;
4. packaged `.agents/Directional/Architecture_M3_CP4c0_Required_Green_Selector.txt` is exactly **338 identities** with SHA-256 `d588cae09067de6914aa1cb917716b11bae01e9f3b45910dbe0faa7d0c7a8116`;
5. its first 316 identities hash to `601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c`;
6. its first 328 identities hash to `cf93622ea8807b26037d2fb6305adf721a23724bc519886c455e98c49c5f3600`;
7. packaged fixtures, selectors, source archive, and executable inventory are immutable throughout the turn.

### Archive extraction requirement — K6

Extract the GitHub artifact and the packaged source/archive payload with a mode-preserving tool such as ordinary `unzip`/`tar`. **Do not use Python `zipfile.extractall` for executable payloads.** Before runtime, prove that each packaged Directional executable has the executable mode expected by the package inventory. Missing mode bits are an orchestration failure: do **not** `chmod`, repair, rebuild, or otherwise mutate the package. This requirement is part of the TB payload and must be preserved in any turn-specific workflow/script.

Do **not** configure, compile, link, rebuild, repair, edit a fixture, edit a selector, change an expectation, alter package bytes, execute a performance benchmark, or invoke legacy/source-grid recovery. Do not enter CP4c-1/2/3.

## 2. TB-EXEC — runtime execution only

TB-EXEC performs only the predefined immutable-artifact runtime work below. It does not diagnose or plan fixes. Every named GoogleTest identity runs in one fresh process. Continue through the complete 338 gate after a red while preserving `first_red_ordinal`; a red withholds acceptance credit but never authorizes repair in TB-EXEC.

### Phase A — frozen gate

Run all **338** identities from `Architecture_M3_CP4c0_Required_Green_Selector.txt` in exact order, statically dispatching each identity to its owning packaged test executable through `cmake/DirectionalTests.cmake`.

Record for every process: ordinal, exact identity, owning executable, exit code, elapsed time, and complete stdout/stderr.

Required re-proof before diagnostics can be interpreted:

- accepted prefix: **316/316**;
- prior CP4c-0 prefix: **328/328**;
- complete frozen gate: **338/338**.

### Phase B — F3 supplemental formatting/identity checks

Run, in fresh producer-test processes:

1. `ResolvedBranchCorrection.NetworkDiagnosticsContainNoControlCharactersForAnyCode`
2. `ResolvedBranchCorrection.TracingPathNeverPublishesSeedIdentityAsFailureLocus`

Required: **2/2 PASS**. These remain supplemental and do not change the 338 selector.

### Phase C — G5 current sphere outcome, uncredited

Run in one fresh producer-test process:

- `ResolvedBranchCorrection.PrescribedSphereA2aOutcomeIsAlwaysPublishedNonGating`

Preserve its complete diagnostic string. It receives **no gate credit**.

### Phase D — K1/H1 tangency census, uncredited

Run in one fresh producer-test process:

- `ResolvedBranchCorrection.CrossFaceFlowAgreementCensusIsPublishedNonGating`

Preserve each witness line verbatim. For every witness record:

- matching provenance/code path and population classification;
- pairs checked, directed observations, distinct `(edge, canonical-first-face branch)` observations, matching histogram, and singular incidence;
- `discretizationAssumption=piecewise-constant-face-field`;
- the full **disagreeing** and **agreeing** tangency distributions;
- for every sample: exact `sourceRatio`, exact `targetRatio`, exact `minRatio`, losslessly serialized `transportAngleProxy`, and source/target opposite-coordinate rank (`smallest`, `middle`, `largest`);
- for every disagreement: the existing exact edge/face/branch/lift/derivative loci plus `classification=piecewise-constant-grazing-observation`.

The angle proxy is diagnostic evidence only: it is the lossless exact-rational serialization of the independent unfolded cross-field transport effort computed from the input doubles. It is **not** an exact transcendental angle and must not become a topological threshold or ownership predicate.

The rank is the deterministic rank by **strictly smaller absolute barycentric derivative coordinates**; ties remain at the lower rank. Rank is descriptive only and must not become a threshold.

TB-EXEC must emit the raw exact values. TB-REV may compute descriptive medians/ranges without changing authority.

Falsifiable K1 predictions from the independent review:

- prescribed sphere: disagreeing `minRatio` median approximately **0.0218**; agreeing median approximately **0.9233**; every disagreement at or below approximately **0.2004**;
- the same qualitative separation should occur on torus and two-ring;
- the four-triangle fan remains diagnostic output only and **excluded** from legitimate production-reasoning totals because its matching is fixture-imposed in contradiction with its constant geometry.

Prediction mismatch is review evidence, not a TB-EXEC repair instruction. No cutoff is authorized even if the distributions separate strongly.

### Phase E — K2 prescribed-sphere grazing cost, uncredited

Run in one fresh producer-test process:

- `ResolvedBranchCorrection.PrescribedSphereGrazingCostCensusIsPublishedNonGating`

Preserve the complete `m3Cp4c0K2` line. It must publish exactly the existing prescribed-sphere singularity-port population and, per trace:

- singularity/source-vertex/local-slot identity;
- number of traversed cross-face edges;
- first grazing step or `none`;
- total grazing-edge observations;
- maximum consecutive grazing observations under the **diagnostic counterfactual** that keeps following the already-published cross-face A1 transport after the observation.

Also report aggregate `traceCount` and `tracesReachingGrazing`.

This is a **continuation-cost proxy only**. CB7 does not implement the §6 tangential-continuation model and therefore cannot truthfully publish an authoritative edge-following path. TB-REV must use the consecutive-grazing proxy as evidence about likely continuation burden, alongside the exact first-grazing locations, without treating it as selection of tangential continuation.

Falsifiable prediction P3: the sphere's first affected trace reaches a grazing observation within its first ten cross-face steps; prior G5 evidence reached edge `6-8` after seven steps.

### Phase F — J3 relabel + K3 independent holonomy oracle, uncredited

Run, each in a fresh producer-test process:

1. `ResolvedBranchCorrection.MatchingVersusGeometryCensusIsPublishedNonGating`
2. `ResolvedBranchCorrection.VertexFanHolonomyCensusIsPublishedNonGating`

For J3, require the output to say explicitly:

- `oracleKind=principal-matching-implementation-cross-check`;
- `canDetectMatchingAliasing=false`.

J3 remains useful only as an implementation cross-check. Do not cite it as an aliasing oracle.

For K3 holonomy, preserve each legitimate witness line verbatim and record:

- `oracleKind=vertex-fan-holonomy`;
- `usesPrincipalMatchingMinimizer=false`;
- interior vertex count;
- complete intrinsic fan count;
- mismatch count and every mismatch's source vertex, declared singularity index numerator modulo 4, and composed fan lift modulo 4.

Required prediction P4: every legitimate witness has complete fan coverage and **zero holonomy mismatches**. Any K3 mismatch is materially different evidence from a grazing observation and takes priority in TB-REV.

### Phase G — Q8 binding probe

Q8 is creditable only if package integrity is exact, Phase A is **338/338**, and Phase B is **2/2**. Execute the existing binding Q8 exactly as frozen. Do not change its four criteria.

**Expected current outcome:** RED at criterion 2 because CB7 is diagnostic-only and K0 forbids a production semantic fix. A green Q8 is material contradictory evidence and must be reviewed, not silently promoted.

### Phase H — postflight immutability

Re-hash package/source archive, selectors, fixtures, executable inventory, and all package bytes examined before runtime. Prove no mutation. Record `buildExecuted=false`, `sourceChanged=false`, `testSourceChanged=false`, `fixtureChanged=false`, `selectorChanged=false`, `performanceBenchmarkExecuted=false`, and whether any extraction repair was attempted (**must be false**).

## 3. TB-REV — diagnostics and bounded successor decision

TB-REV consumes only TB-EXEC evidence. It must first satisfy the Test + Benchmark regression-documentation gate by categorizing every observed regression/candidate in `.agents/Directional/Regression_Root_Cause_Tracker.md`. If the evidence does not justify a stable-ID or historical-count change, record the candidate/non-stable disposition and state why **42 events / 14 categories / 28 recurrences** remains unchanged.

### Corrected K4 decision table

The old owner-labelled TB-R6 rows are retired. Use this table instead:

| Observed evidence | Interpretation / next action |
|---|---|
| H1 disagreement with K1 near-grazing decomposition, whether gauges are equal or unequal | **`piecewise-constant-grazing-observation`**. Do not name `build_branch_transports` or `build_boundary_pairing` as owner; do not authorize a production fix from H1. |
| K3 holonomy mismatch on a legitimate witness | Genuine period/transport consistency defect not detectable by the J3 minimizer cross-check; localize that defect before DEFN-2. |
| K3 holonomy clean, J3 implementation cross-check clean, and K1 reproduces the predicted tangency separation | Evidence supports the known **tracing-model definition gap**. Proceed to `M3-CP4c-0-DEFN-2`; do not patch continuation semantics in TB-REV. |
| K1 materially falsifies the tangency prediction while K3 is clean | Return to independent review of the diagnostic model; do not choose a grazing continuation and do not infer an innocent implementation owner. |
| Frozen gate/F3 regression or immutable-package failure | Stop; no semantic interpretation of K1–K3 is accepted until the regression/orchestration defect is resolved. |

TB-REV must compare K2's `tracesReachingGrazing`, first-step distribution, and consecutive-grazing proxy with the four model options framed in the TB-R6 independent review, but **must not choose one**. That choice belongs to `M3-CP4c-0-DEFN-2`.

## 4. Acceptance and hard stop

TB-R7 is complete when all immutable-artifact checks, the 338 ordered processes, F3, G5, K1, K2, J3/K3, conditional Q8, and postflight immutability are recorded and TB-REV has updated the regression tracker and classified the evidence using the corrected table.

Stop rather than repairing in place if:

- package/source/selector/fixture identity differs from CB7 authority;
- any accepted-prefix identity is red;
- a required K1/K2/K3 locus cannot be published losslessly;
- K3 has incomplete intrinsic fan coverage;
- archive extraction loses executable mode bits;
- any result would require weakening T6/Q8, altering the prescribed sphere fixture, retuning a tolerance, introducing a grazing threshold, or changing the frozen selector.

**Hard successor boundary:** after a valid TB-R7 diagnostic review, the next semantic turn is **independent `M3-CP4c-0-DEFN-2`**. Do not enter CP4c-1/2/3 and do not begin a production-fix CB turn from TB-R7. The independent planning/review boundary is a complete orchestration stop.

This plan consumes **no performance benchmark** despite the historical `Test + Benchmark` name; the checkpoint question is semantic diagnostics only.
