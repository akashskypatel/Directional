# Milestone G P5 Test + Benchmark Turn Report

- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`
- Validated source commit: `d4c1bce4338b7f2e91264c349a73b6b260e80f54`
- Build artifact: `8840174777` (`surface-cell-p5-branch-linux-release`)
- Artifact digest: `sha256:a5659e86e0f1e90129d1b085e25ed0f2afff0ea882a43304fae15a5f18b9970a`
- Build workflow: `30769701224`
- Environment: Linux, GCC 13.3.0, AMD EPYC 9V74
- Turn type: test + benchmark; no source, test, benchmark, or build logic was modified and no rebuild occurred.

## Tests

- New ownership/identity regressions: **8/8 passed**.
- Phase 14–18 aggregate: **219/219 passed**.
- Milestone G P23 plus Phase 20: **52/52 passed** after recreating the artifact's baked source-root path with a filesystem symlink. The first attempt's sole failure was infrastructure-only: the test binary could not open its absolute build-host manifest path.
- `PatchDescriptorMilestoneE.*`: **12/15 passed**.
- A non-authoritative full-suite attempt was interrupted by the execution environment timeout during `MilestoneGP26.ProductionMatrixTerminatesWithoutHiddenFallback`; no full-suite pass/fail claim is made.

## Patch-descriptor failure classification

### `SharedEdgeParityRepairConforminglyCompletesTwoOddCells`

Classification: structurally invalid test scenario, pre-existing at baseline commit `c84e2e1d64e867e5975f414780f9c81e649612fb`.

Both the baseline and current artifacts fail before parity repair because `build_surface_cell_complex` returns `topologyValid == false`. The fixture's two arcs lie exactly on the same shared source edge, so it does not establish the topology-valid two-cell odd arrangement required by the stated test purpose. Replace the fixture with a valid shared-interface odd arrangement while preserving the parity, incidence, and conforming-completion assertions.

### `GlobalDescriptorAssignmentRejectsAmbiguousInteriorSingularity`

Classification: structurally invalid test scenario under the new unique-domain contract.

The fixture duplicates an entire authoritative component over the same source support. Completion therefore correctly fails earlier with `DuplicateArrangementDomain;firstPatch=0;secondPatch=2` instead of reaching singularity ownership. Replace it with two distinct canonical domains incident to the same singular source vertex.

### `ComplexCompletionFailsClosedInsteadOfReturningPartialOutput`

Classification: structurally invalid test scenario under the new unique-domain contract.

The invalid component duplicates the valid component's source domain, so unique-domain validation correctly terminates before patch completion. Use distinct source support for the valid and non-disk patches while preserving the transactional no-partial-output assertions.

## Direct random-bunny result

Two independent runs used `SurfaceCells`, fallback `Fail`, source-grid recovery disabled, no warm-up, and one measured run per process.

Both failed identically:

```text
DuplicateStitchedQuad:firstPatch=378;firstLocalQuad=1;
secondPatch=394;secondLocalQuad=4;
globalVertices=7643,7644,7647,7648;
classification=completion-template;
firstDomainHash=1626132098604174973;
secondDomainHash=12830489233532523937;
firstBoundaryNodeHash=9853059121513979599;
secondBoundaryNodeHash=6530130091133399252;
firstBoundaryHalfedgeHash=11019542682270369445;
secondBoundaryHalfedgeHash=4213466302263896358;
firstSourceSupportHash=9777327708078931779;
secondSourceSupportHash=17251474233191701613
```

Both runs reported:

- arrangement cells: **21,298**;
- descriptors attempted/completed/failed: **21,297 / 21,297 / 0**;
- required unresolved endpoints: **0**;
- accepted output quads: **0**;
- identical failure string and all nine stage structural hashes.

## Conflict classification

The instrumented artifact selected **completion-template ownership**.

The distinct domain, boundary-node, boundary-halfedge, and source-support hashes rule out duplicate oriented-domain ownership and overlapping undirected-boundary ownership. Two distinct patch domains still emit the same assembled global quad.

The B-vs-D result is provisional rather than fully authoritative because the current classifier compares per-corner identity hashes in operation-local order instead of a canonical cyclic/reversed face order, and it does not serialize the corner identity kinds/hashes, component/sheet values, or completion backend. A rotated or reversed identity cycle can therefore miss the `false-merge` equality branch and be labeled `completion-template`. The next implementation turn must canonicalize and serialize the face ownership record before changing ownership behavior.

## Performance comparison

Same-machine baseline: artifact `8838467442`, commit `c84e2e1d64e867e5975f414780f9c81e649612fb`.

- Baseline wall time: **22.981569 s**.
- Current wall times: **26.710283 s**, **26.840198 s**; mean **26.775241 s** (**+16.51%**).
- Baseline peak working set: **749,375,488 bytes**.
- Current peaks: **1,696,071,680** and **1,695,928,320 bytes**; mean **1,696,000,000 bytes** (**+126.32%**).
- Completion stage: **4.168940 s** baseline vs **6.318718 s** current mean (**+51.57%**).

Classification: performance regression. Correctness remains the primary blocker, but ownership identity storage must also be compacted without weakening exact equality.

## Status

P5 is **incomplete** and remains unmerged. The authoritative next turn is code changes + compile-only build using `.agents/Directional/Milestone_G_P5_Completion_Template_Code_Build_Plan.md`. Review is skipped by project policy.