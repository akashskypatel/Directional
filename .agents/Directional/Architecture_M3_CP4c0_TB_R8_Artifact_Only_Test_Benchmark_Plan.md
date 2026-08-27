# M3-CP4c-0-TB-R8 Artifact-Only Test + Benchmark Plan

## Turn boundary

`M3-CP4c-0-TB-R8` is **Test + Benchmark only**. It consumes the immutable CB8 package and executes the pre-authored semantic plan. It must not configure, compile, relink, regenerate, patch, chmod/repair packaged executables, edit product/test/fixture/selector/build logic, or enter CP4c-1/2/3.

TB is split operationally into **TB-EXEC** and **TB-REV**. TB-EXEC performs only the commands frozen below and preserves raw evidence. TB-REV interprets only that evidence, updates the regression/root-cause record, and freezes the next disposition. If an independent Review + Plan boundary is reached, orchestration stops there.

## Immutable CB8 authority

- semantic source: `19ba8e9c5e58f9c33c14b309841165d3f0401db5`
- package artifact: `9628445643`
- package ZIP SHA-256: `869e06a3524ecdb7fd901e2583d5ba5c60309cce3085e2e1996a37ddd780bce6`
- packaged source archive SHA-256: `98e7db71647a54f41edfd93aea56ef7f50e014989bbc3c617edc179791380d5d`
- compile run/jobs: `33025705457 / 98366398970 / 98367264215`
- compile diagnostic artifact: `9628446136` / `562bb275fccb61629a3a60bfd1f71c3cb8332a239674dab660ebcd1626f33d27`
- CP4c-0 selector: 343 identities / `63ca177e8c0f22a83085cfb1028915b444db67bf2bb3da79555e4a3033a74d09`
- accepted first-316 hash: `601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c`
- prior first-328 hash: `cf93622ea8807b26037d2fb6305adf721a23724bc519886c455e98c49c5f3600`

## TB-EXEC — ordered artifact-only execution

### P0 — package and extraction preflight

1. Download package artifact `9628445643` once.
2. Verify outer ZIP SHA-256 `869e06a3524ecdb7fd901e2583d5ba5c60309cce3085e2e1996a37ddd780bce6`.
3. Extract using an ordinary mode-preserving archive path (`unzip`/`tar` as packaged). Do not use Python ZIP extraction, `chmod`, permission repair, relinking, or package mutation.
4. Verify recursive packaged `SHA256SUMS` before execution.
5. Verify metadata:
   - semantic source `19ba8e9c5e58f9c33c14b309841165d3f0401db5`;
   - preflight/build exit codes `0`;
   - `runtimeExecution=false` and `turnBoundary=Code+Build-only`;
   - empty source-status snapshots;
   - packaged source archive SHA-256 `98e7db71647a54f41edfd93aea56ef7f50e014989bbc3c617edc179791380d5d`;
   - required executables exist with their packaged executable modes.
6. Recompute selector authority from packaged source: 343 identities, full SHA-256 `63ca177e8c0f22a83085cfb1028915b444db67bf2bb3da79555e4a3033a74d09`, first-316 `601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c`, first-328 `cf93622ea8807b26037d2fb6305adf721a23724bc519886c455e98c49c5f3600`.
7. Record immutable preflight inventories for package files, semantic source archive, fixtures, selector, and executable hashes/modes. These become the postflight comparison baseline.

Any mismatch is **orchestration/integrity failure**, not semantic red/pass. Stop without executing Directional binaries.

### P1 — required-green gate, 343 fresh processes

Use the packaged test-dispatch mapping owned by `cmake/DirectionalTests.cmake`. Execute each of the 343 selector identities as its own fresh GoogleTest process, in selector order. A zero-selected identity is orchestration failure.

Record per identity: ordinal, full identity, owning binary, exact filter, exit code, pass/fail, elapsed time, and raw stdout/stderr. Continue through the complete 343-gate after a semantic red so the full vector is preserved; record `first_red_ordinal` and every red identity.

Required observations:

- accepted first 316: **316/316 PASS**;
- prior first 328: **328/328 PASS**;
- complete CB8 gate: **343/343 PASS**.

Do not change expectations or selector membership in TB.

### P2 — F3 controls

Execute as two fresh processes:

- `ResolvedBranchCorrection.NetworkDiagnosticsContainNoControlCharactersForAnyCode`
- `ResolvedBranchCorrection.TracingPathNeverPublishesSeedIdentityAsFailureLocus`

Required: **2/2 PASS**.

### P3 — L2/K1 grazing-classification census, non-gating

Execute `ResolvedBranchCorrection.CrossFaceFlowAgreementCensusIsPublishedNonGating` and preserve its complete deterministic census output, including witness classification and raw loci.

Frozen DEFN-2 predictions to compare, not to retrofit:

- prescribed sphere: **72 distinct grazing configurations / 72 distinct edges / 0 slide-sign disagreements / 0 zero-rates**;
- torus: **120 / 120 / 0 / 0**;
- two-ring: **2** grazing configurations;
- four-triangle fan: **1** synthetic fixture case, excluded from legitimate production totals.

Any legitimate slide-direction disagreement or zero-rate is material contradictory evidence and routes to Review. No tie-break may be invented in TB.

### P4 — L5 grazing-edge trace multiplicity, non-gating

Execute `ResolvedBranchCorrection.GrazingEdgeTraceMultiplicityIsPublishedNonGating` and preserve the per-witness maximum and all violating loci.

Frozen expected bound: **at most one trace per grazing edge** on every measured witness. Any `>1` result is material evidence for Review; do not merge, deduplicate, or repair traces.

### P5 — L8 corrected K2 prescribed-sphere traversal, non-gating

Execute `ResolvedBranchCorrection.PrescribedSphereGrazingCostCensusIsPublishedNonGating`. Preserve the complete `m3Cp4c0K2` line and per-trace evidence needed to identify transit count, traversed edges, terminal kind, terminal vertex, and the live `6-8` locus.

Frozen predictions:

- every prescribed-sphere trace traverses **more than one** edge;
- the trace seeded at source vertex `0` reaches grazing edge `6-8` at **step 7**;
- edge `6-8` transits to source vertex `8`, then terminates by the existing singularity path.

A prediction failure is review evidence. TB must not patch the walker or substitute a new measurement route.

### P6 — G5 prescribed-sphere network publication, non-gating

Execute `ResolvedBranchCorrection.PrescribedSphereA2aOutcomeIsAlwaysPublishedNonGating`. Preserve the complete terminal-event summary and network diagnostics.

Frozen Q8 criterion-2 observation: `fieldAlignedCurveNetwork=true` and **24 traces** (eight prescribed index-1 singularities × three ports). This is an observation target, not a license to weaken any other criterion.

### P7 — J3/K3 diagnostic controls, non-gating

Execute separately:

- `ResolvedBranchCorrection.MatchingVersusGeometryCensusIsPublishedNonGating`
- `ResolvedBranchCorrection.VertexFanHolonomyCensusIsPublishedNonGating`

Preserve complete census output. The retained pre-CB8 controls are **524/524 legitimate interior matching-versus-geometry agreements** and **176/176 complete vertex fans / 0 holonomy mismatches**. If CB8 changes only incidental wording, semantic totals should remain unchanged. Any semantic mismatch routes to Review.

### P8 — binding Q8, unchanged

Evaluate the frozen Q8 criteria exactly as written in `Architecture_M3_CP4c0_DEFN_Frozen_Definitions.md`; CB8 did not amend them.

1. accepted 316 remain green with zero expectation edits;
2. prescribed sphere reaches A2a and publishes **24 traces**;
3. at least one prescribed-sphere trace terminates on trace/trace contact with terminal `TraceIntersection`;
4. the face `1-2-5` / incoming `1-2` crossover witness resolves exactly one of `{1-5, 2-5}` and flips across the frozen crossover parameter;
5. torus remains 0 traces and mechanical remains A1 fail.

Q8 is creditable only when package integrity, **343/343**, and F3 **2/2** are green.

DEFN-2 pre-commits the expected interpretation: criterion 2 is expected to become green, while criterion 3 is predicted not satisfiable on this cube-field sphere because separatrices pair singularities. If criterion 2 passes and criterion 3 remains red, **do not weaken criterion 3, relabel singularity termination as contact, or add a new CP4c-0 witness**. Route to independent Review + Plan to adjudicate/re-home criterion 3 to CP4c-1.

### P9 — immutable postflight

After all planned runtime commands:

1. recompute package/source/fixture/selector/executable inventories and compare byte-for-byte/mode-for-mode with P0;
2. record `buildExecuted=false`, `configureExecuted=false`, `relinkExecuted=false`, `repairExecuted=false`, `performanceBenchmarkExecuted=false`;
3. record source/test/fixture/selector/build-configuration mutation flags, all false;
4. preserve the exact commands, exit codes, full raw logs, result summary, and postflight integrity report as immutable artifacts.

Postflight mismatch invalidates acceptance regardless of semantic results.

## TB-REV — evidence review and disposition

TB-REV consumes only the TB-EXEC result/log artifacts. It must not execute new unplanned runtime work, compile, or edit product/test/fixture/selector/build logic.

1. Verify TB-EXEC package/run/job/artifact provenance and postflight integrity.
2. Review every gate red and every non-gating diagnostic mismatch from P3–P7.
3. Update `.agents/Directional/Regression_Root_Cause_Tracker.md` for **every observed regression**. If evidence does not justify a stable identity/count change, update/create a candidate and state explicitly why stable totals remain unchanged.
4. Produce the semantic disposition using this table:

| Evidence | Disposition |
|---|---|
| package/integrity/F3 failure | invalid/orchestration failure or hard semantic stop as applicable; no acceptance |
| any required-green identity red | valid semantic red; Review + Plan required |
| legitimate L2 ambiguity/zero-rate | material model contradiction; Review + Plan, no tie-break |
| L5 multiplicity `>1` | material topology evidence; Review + Plan, no merge heuristic |
| corrected K2 prediction fails | diagnostic contradiction; Review + Plan, no test-side repair in TB |
| G5 does not publish 24 traces | Q8 criterion 2 remains red; Review + Plan |
| criterion 2 green, criterion 3 red | expected DEFN-2 assignment result; independent Review + Plan must adjudicate/re-home criterion 3 to CP4c-1; do not amend Q8 in TB |
| Q8 fully green or unexpected prescribed-sphere `TraceIntersection` | material evidence contradicting DEFN-2 prediction; Review + Plan before checkpoint closure |

Stable accounting entering TB-R8 is **42 / 14 / 28**, produced-witness debt **5**, and M3 packages **47**. Change those values only when TB evidence and the regression tracker justify it.

## Exit gate and stop rule

TB-R8 can close CP4c-0 only if the complete frozen semantic gate and binding Q8 are green, integrity is clean, regression documentation is current, and no review boundary remains. Otherwise a valid red routes to **independent Review + Plan**, where orchestration stops completely.

No performance benchmark is scheduled in TB-R8. Do not enter CP4c-1/2/3 from TB-EXEC or TB-REV.
