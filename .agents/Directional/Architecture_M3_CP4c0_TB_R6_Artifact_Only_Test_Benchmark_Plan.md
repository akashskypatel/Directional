# M3-CP4c-0-TB-R6 — Artifact-Only Test + Benchmark Plan

**Status:** EXACT NEXT. `M3-CP4c-0-CB6` is COMPLETE / BUILD GREEN.
**Turn boundary:** Test + Benchmark only; immutable artifact execution, no rebuild and no repair.
**Purpose:** execute the J-series diagnostics that decompose the H1 lift and independently audit declared matching against geometry. This turn is **not** a Q8-closure attempt; Q8 is expected to remain red at criterion 2 unless the diagnostic evidence itself contradicts the current state.

## 1. Frozen authority and prohibited actions

Frozen CB6 authority:

- semantic source: `8b8d189758d55d9f93ae595fbbe5d9fde0b4aee6`;
- authoritative compile-only run/job: `33002848081 / 98288918300`;
- immutable result/package artifact: `9619352525`;
- package GitHub ZIP SHA-256: `b45306c3c5b3b9ff094131be8073aed5c6180533fdbe0b04f220ca929b4dd672`;
- packaged source archive SHA-256: `308e02580033b5a319e08d7916afc921693d2b15f645813c2cdbaed336320093`;
- compile-log artifact: `9619353059` / `1b2a0ffc9889305ca6a2efa847a2442c941583df01ad94c4c12226aea47be4c4`.

Consume **only** package `9619352525`. Before any generated Directional binary runs, verify:

1. package outer SHA-256 and recursive `SHA256SUMS`;
2. exact packaged semantic source SHA;
3. compile/preflight exit `0`, all required source-status snapshots empty, and `runtimeExecution=false`;
4. packaged `.agents/Directional/Architecture_M3_CP4c0_Required_Green_Selector.txt` is exactly **338 identities** with SHA-256 `d588cae09067de6914aa1cb917716b11bae01e9f3b45910dbe0faa7d0c7a8116`;
5. its first 316 identities hash to `601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c`;
6. its first 328 identities hash to `cf93622ea8807b26037d2fb6305adf721a23724bc519886c455e98c49c5f3600`;
7. packaged fixtures, selectors, source archive, and executable inventory are immutable throughout the turn.

Do **not** configure, compile, link, rebuild, repair, edit a fixture, edit a selector, change an expectation, alter package bytes, execute a performance benchmark, or invoke legacy/source-grid recovery. Do not enter CP4c-1/2/3.

## 2. TB-EXEC — runtime execution only

Execute the following in order. Every named GoogleTest identity is one fresh process. Continue through the complete 338 gate after a red, preserving `first_red_ordinal`; a red withholds acceptance credit but does not authorize repair in TB-EXEC.

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

Report its complete diagnostic string. It receives **no gate credit**.

### Phase D — J1/H1 decomposed flow-agreement census, uncredited

Run in one fresh producer-test process:

- `ResolvedBranchCorrection.CrossFaceFlowAgreementCensusIsPublishedNonGating`

Preserve each witness line verbatim. For every witness report and review:

- matching provenance and exact code path;
- population status/classification;
- pairs checked and directed violation count;
- **distinct `(edge, canonical-first-face branch)` disagreement count**;
- matching histogram over directed violations;
- count of violations incident to a declared singular vertex;
- every violation's edge, source/target face, source/target branch, `matching`, `rawGaugeSource`, `rawGaugeTarget`, published `signedLift`, singular incidence, and lossless exact source/target `d[opp]` values.

The four-triangle fan remains in the diagnostic output only as an explicitly **excluded fixture artifact**. Do not include it in production-reasoning population totals and do not edit its field.

Current falsifiable predictions from the independent review:

- fan: 2 directed / 1 distinct disagreement, with the distinct forward decomposition `matching=+1`, `rawGaugeSource=0`, `rawGaugeTarget=1`, published lift congruent to zero;
- legitimate population: 388 directed / 194 distinct disagreements over two-ring + prescribed sphere + torus;
- distinct per-witness counts: two-ring 2, sphere 72, torus 120.

A prediction mismatch is evidence for TB-REV; it is not a TB-EXEC repair instruction.

### Phase E — J3 matching-versus-geometry census, uncredited

Run in one fresh producer-test process:

- `ResolvedBranchCorrection.MatchingVersusGeometryCensusIsPublishedNonGating`

Preserve each witness line verbatim. Report per witness:

- matching provenance/code path and population classification;
- interior edges checked;
- agreement/disagreement counts and exact ratio;
- for each disagreement: source edge, first/second source face rows, source raw index, declared raw target, geometry-implied raw target, declared matching, and independently measured geometry matching.

The J3 oracle unfolds the two incident source triangles about their shared edge and derives raw-index correspondence from the field directions; it does not use tracing, H1 flow classification, or published branch transport to decide agreement.

### Phase F — Q8 binding probe

Q8 is creditable only if package integrity is exact, Phase A is **338/338**, and Phase B is **2/2**. Then execute the existing binding Q8 exactly as frozen. Do not change its criteria:

1. prescribed-sphere direct SurfaceCells path publishes the required field-aligned network;
2. exactly **24 traces**;
3. at least one terminal `TraceIntersection`;
4. the frozen face `1-2-5`, incoming `1-2` crossover to `{1-5, 2-5}` with the existing crossover-flip expectation.

**Expected current outcome:** RED at criterion 2 because CB6 is diagnostic-only and J0 forbids a production semantic fix. A green Q8 would be material contradictory evidence and must be reviewed, not silently promoted.

### Phase G — postflight immutability

Re-hash package/source archive, selectors, fixtures, executable inventory, and all package bytes examined before runtime. Prove no mutation. Record `buildExecuted=false`, `sourceChanged=false`, `testSourceChanged=false`, `fixtureChanged=false`, `selectorChanged=false`, and `performanceBenchmarkExecuted=false`.

## 3. TB-REV — diagnostics and bounded successor decision

TB-REV consumes only the TB-EXEC log/evidence. It must first categorize every observed regression in `.agents/Directional/Regression_Root_Cause_Tracker.md` under the Test + Benchmark documentation gate; if no stable-ID change is justified, record a candidate/non-stable disposition and state why stable totals remain unchanged.

Fill this decision table from J1 + J3 evidence before authorizing any production change:

| Observed J1/J3 concentration | Owner / next interpretation |
|---|---|
| H1 violations concentrated where declared `matching != 0`, and J3 finds declared-vs-geometry raw-index disagreements | **H-B / field matching authority or edge-aliasing path**; localize the matching producer/edge identity before touching A1 composition |
| H1 violations have `matching = 0` with unequal source/target gauges while J3 matching agrees with geometry | **A1 gauge composition** in `build_branch_transports` |
| H1 violations have `matching = 0`, equal gauges, lift 0, and J3 matching agrees with geometry | **A1 flow classification / direction publication** in `build_boundary_pairing` |
| Violations concentrate on singular/cut-seam incidence without J3 mismatch | investigate period-jump/gauge handling; do not call it H-B solely from the H1 lift histogram |
| J3 is clean on legitimate witnesses but H1 remains nonzero | H-B matching aliasing is weakened; use the J1 terms to select the actual A1 owner |

TB-REV must distinguish the synthetic fan from the three legitimate production-reasoning witnesses. It must publish legitimate directed/distinct totals separately from the excluded fan and explain any deviation from P1–P6 in the independent review.

No production fix is authorized until this table has one evidence-supported owner. Freeze **exactly one** bounded successor turn. If the evidence remains ambiguous, the successor is another bounded diagnostic/review measure, not a speculative semantic fix.

## 4. Acceptance and stop conditions

TB-R6 is complete when all immutable-artifact checks, the 338 ordered processes, F3, G5, decomposed H1, J3, conditional Q8, and postflight immutability are recorded, and TB-REV has filled the decision table and updated the regression tracker.

Stop and return to review rather than repairing in-place if:

- package/source/selector/fixture identity differs from CB6 authority;
- any accepted-prefix identity is red;
- instrumentation cannot publish a required J1/J3 locus losslessly;
- J3's oracle population is incomplete;
- the result would require weakening T6/Q8 or altering the prescribed sphere fixture, selector, tolerance, or acceptance expectations.

This plan consumes **no performance benchmark** despite the historical `Test + Benchmark` name; the checkpoint question is semantic diagnostics only.
