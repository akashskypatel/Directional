# Directional Reorientation Plan

## Current orientation

```text
G0 truthful authority [passed]
→ G1 uniform authoritative phase-front plane [passed]
→ G2 cross-chart / close-sheet isolation [ACTIVE; compile-valid, runtime verification pending]
→ G3 periodic holonomy
→ G4 topology and singularities
→ G5 adaptivity and hard features
→ G6 bunny and vase production success
→ G7 hardening/default-on
```

## Current disposition

The Gate 1 bounded producer replacement is runtime-proven. The source distinguishes `NotApplicable / Produced / Rejected`, prevents generic producer substitution after authoritative rejection, and directly produces the exact plane and multi-face seam.

The bounded Gate 2 extension is now implemented and compile-valid. It partitions authoritative phase/front construction by source component/local-sheet and prevents direct materialization from merging equal lattice coordinates across unrelated sheets. Runtime evidence for that change does not yet exist.

## Gate 1 closure authority

Validated artifact:

- source commit `0e96ceb62f85353c9cd8a1eeed7c560babeaa7c3`;
- artifact ID `8984760467`;
- artifact SHA-256 `4dc3ec7d797fae2cebe7040a60712a92bfe63cdfe1052ba74796ef0a6602a031`.

Direct proven regressions:

- plane: `Produced`, 81 provenance vertices, 64 pure quads, zero validation failures, no fallback/recovery, deterministic hash suffix `730caeae49ec872c`;
- seam: `Produced`, 81 vertices, 64 pure quads, zero validation failures, no fallback/recovery, deterministic hash `a8972efd7c4900a4`.

## G2 compile-valid checkpoint

Source commit:

- `218dd3ec3f6399dc82183390720a4ba4d3a70b42`

Implemented bounded changes:

1. partition uniform phase/front input faces by authoritative `(source component, local sheet)` before phase-frame construction;
2. restrict source point lookup, edge incidence, boundary classification, and planar-frame checks to the active sheet;
3. preserve existing reciprocal edge-transition and ordered source-vertex-fan transport independently inside each sheet;
4. concatenate only sheet results that independently reach `Produced`;
5. retain an applicable per-sheet invariant failure as authoritative `Rejected`;
6. keep unsupported/periodic topology `NotApplicable`;
7. key direct output lattice vertices by `(component, sheet, u, v)` and construct source-sheet-local boundary loops;
8. add compile-verified disconnected-sheet and face-row-order regressions.

Successful build evidence:

- run/job/artifact `31179899458` / `92870408341` / `8994541137`;
- artifact SHA-256 `f1efaeec80ede729439a1a16e0cadf56db2a1dee2c3380b2ffb4d2da8211f791`;
- detailed log artifact `8994539982`, SHA-256 `c7d67285ca6b980111a53fe017b3de5800abccb2a3146352135c0d674ca0acc8`;
- recursive checksums 45/45;
- compile/link 111/111 across seven approved targets;
- no generated project binary executed.

A first compile attempt exposed one ordinary syntax error; it was corrected surgically and the same scope then compiled successfully. This is build evidence only, not runtime progress.

## Immediate objective — artifact-only G2 verification

Execute `.agents/Directional/Gate_2_Close_Sheet_Artifact_Only_Test_Benchmark_Plan.md` against exact artifact `8994541137`.

Validation priority:

1. integrity/source/blob verification;
2. two new disconnected-sheet producer contracts;
3. plane and seam mandatory regressions;
4. exact close-sheet production acceptance;
5. proof of source component/local-sheet isolation and no cross-sheet output identity merge;
6. bounded determinism and remaining non-overlapping suites;
7. cylinder/bunny/vase only as later-gate observations after the G2 decision.

### Material-progress condition

G2 closes only if close sheets becomes direct deterministic valid `Produced` pure-quads with zero cross-sheet provenance/merge violations while plane and seam remain valid. If G2 closes, the next implementation objective is G3 periodic cylinder/holonomy. If not, the next Code + Build turn addresses only the exact general G2 failure established by artifact evidence.

## Explicitly deferred work

Until G2 passes, do not prioritize:

- cylinder periodic holonomy;
- singularity topology and topology-distinct completion;
- adaptive 2:1 transitions and hard-feature expansion;
- bunny/vase production or performance remediation;
- scheduler-sensitive timing ratios;
- the existing downstream completion/simplification failures;
- cache, memory, ownership-compaction, or general diagnostics unless essential to G2 correctness.

## Evidence discipline

- Direct mandatory fixtures outrank aggregate totals.
- Passed earlier gates are mandatory regressions.
- Narrow synthetic fixtures isolate contracts but cannot replace exact production-route tests.
- Bunny and vase remain mandatory production observations and may not be simplified, bypassed, or special-cased.
- Test turns remain artifact-only; Code + Build turns may use GitHub workflow compilation under the workflow policy.
- Timeout is failure only and never correctness evidence.
