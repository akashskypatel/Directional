# Directional Reorientation Plan

## Current orientation

```text
G0 truthful authority [passed]
→ G1 uniform authoritative phase-front plane [passed]
→ G2 cross-chart / close-sheet isolation [passed]
→ G3 periodic holonomy [ACTIVE; compile-valid, runtime verification pending]
→ G4 topology and singularities
→ G5 adaptivity and hard features
→ G6 bunny and vase production success
→ G7 hardening/default-on
```

## Current disposition

The bounded authoritative producer is runtime-proven on three progressively stronger domains:

1. plane — connected planar uniform phase/front;
2. multi-face seam — reciprocal cross-chart transport;
3. close sheets — independent disconnected spatially close source sheets.

The G3 periodic-annulus extension is implemented and compile-valid at source `56f823273cad041a01ebb4d0772c3265ff248f4a`. It derives annular topology and a deterministic cut-open intrinsic chart, records first-class periodic holonomy, pairs artificial-cut fronts through periodic lattice identity, and materializes the quotient without Euclidean seam welding. Runtime evidence for this new path does not yet exist.

The current implementation is a bounded canonical-ring annulus proof rather than a general arbitrary-annulus/genus solver. Exact artifact execution must determine whether the committed cylinder satisfies the intended domain assumptions. Do not expand scope before that evidence exists.

## Passed-gate authority

Tested G0–G2 artifact:

- source commit `218dd3ec3f6399dc82183390720a4ba4d3a70b42`;
- artifact `8994541137`;
- SHA-256 `f1efaeec80ede729439a1a16e0cadf56db2a1dee2c3380b2ffb4d2da8211f791`;
- recursive checksums **45/45**;
- focused contracts **7/7 passed**.

Direct proven regressions:

- plane: `Produced`, 81 vertices, 64 pure quads, zero validation failures, hash `730caeae49ec872c`;
- seam: `Produced`, 81 vertices, 64 pure quads, zero validation failures, hash `5bdf34d7802e9fb0`;
- close sheets: `Produced`, 242 vertices, 200 pure quads, exactly two connected components, zero validation failures, hash `89b052762f52a5af`.

All three are deterministic across three independent processes and use no fallback/recovery.

## G3 compile-valid checkpoint

Source authority:

- source commit `56f823273cad041a01ebb4d0772c3265ff248f4a`;
- patch SHA-256 `d93cc65f86ea402111af3b409e73d08c72be37fdee1f2758538033fc7525802f`.

Build authority:

- run/job `31196268841` / `92925122791`;
- build artifact `9001168379`, SHA-256 `0b4ef04bd7d9641588a6f9d23882501d551367fdee56b9b99954becc19780b8c`;
- detailed log artifact `9001167184`, SHA-256 `fdd873fe4e0980ddf8613bd04b3be8f795730928bd73844cd92aec75c41031a4`;
- recursive checksums **44/44**;
- compile/link **111/111** across seven approved targets;
- no generated project binary executed.

Implemented bounded periodic contract:

1. topology-derived singularity-free annulus applicability;
2. deterministic source-topology boundary/ring ordering and intrinsic cut-open chart;
3. first-class holonomy `(Z4 rotation, Z2 lattice translation, ordered source route)` plus explicit cut route;
4. typed periodic topology/chart/holonomy/front rejection;
5. exact artificial-cut pairing through `PeriodicFrontMerge` ownership;
6. periodic quotient materialization without nearest-point/Euclidean seam welding;
7. holonomy structural hashing and diagnostics;
8. compile-only focused regressions for annulus applicability, ordering invariance, cut pairing, malformed holonomy, and exact production cylinder authority.

The latest **executed** cylinder remains the prior `NotApplicable` / 732 generic traces / zero arrangement-completion result. Compilation cannot replace runtime evidence.

## Immediate objective — artifact-only G3 verification

Execute `.agents/Directional/Gate_3_Periodic_Cylinder_Artifact_Only_Test_Benchmark_Plan.md` against exact artifact `9001168379`.

Validation priority:

1. artifact/source/patch/blob integrity;
2. five new periodic producer contracts;
3. mandatory plane/seam/close-sheet regressions;
4. exact production cylinder acceptance;
5. periodic holonomy and artificial-cut pairing evidence;
6. bounded determinism and non-overlapping default suites;
7. bunny/vase only as later observations after the G3 decision.

### Material-progress condition

G3 closes only if cylinder becomes direct deterministic strict-valid `Produced` output with correct periodic quotient/holonomy while G0–G2 remain green. A new exact typed periodic `Rejected` state with zero generic substitution is material progress but leaves G3 active. If G3 closes, the next implementation gate is G4 topology-distinct completion and singularities.

## Explicitly deferred work

Until G3 passes, do not prioritize:

- torus/general-genus periodic topology;
- singularity topology or topology-distinct patch completion;
- adaptive 2:1 transitions and hard-feature expansion;
- bunny/vase production or performance remediation;
- scheduler-sensitive timing ratios;
- the ten existing downstream completion/simplification failures;
- cache, memory, ownership compaction, or broad diagnostics unless essential to G3 correctness.

## Evidence discipline

- Direct mandatory fixtures outrank aggregate totals.
- Passed earlier gates are mandatory regressions.
- Narrow contract fixtures isolate algorithms but exact production-route acceptance decides gate closure.
- Bunny and vase remain mandatory production observations and may not be simplified, bypassed, or special-cased.
- Test turns remain artifact-only; Code + Build turns may use GitHub workflow compilation under the workflow policy.
- Timeout is failure only and never correctness evidence.
