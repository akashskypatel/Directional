# Milestone G P5 — Completion Ownership Classification and Repair

**Authority:** Next code + build turn for `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Validated source:** `d4c1bce4338b7f2e91264c349a73b6b260e80f54`  
**Validation artifact:** `8840174777`  
**Turn type:** Code changes + compile-only build. Do not execute tests or benchmarks.  
**Review policy:** Never; this plan is authoritative immediately.

## 1. Validated failure

Two independent direct random-bunny runs, with `SurfaceCells`, fallback `Fail`, and source-grid recovery disabled, failed identically at completion:

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

Every one of 21,297 descriptors completed, zero descriptors failed, and zero required endpoints remained unresolved. The distinct domain, boundary, and source-support hashes rule out duplicate oriented-domain ownership and overlapping undirected-boundary ownership.

## 2. Classification caveat

The runtime selected `completion-template`, but the B-vs-D decision is not fully authoritative:

- per-corner identity hashes are compared in operation-local order rather than as a canonical cyclic/reversed face cycle;
- identity kinds and hashes are not serialized in the benchmark diagnostic;
- completion backend and operation-local region lineage are not reported.

A rotated or reversed equivalent identity cycle can therefore miss the `false-merge` equality branch. Correct the diagnostic contract before changing ownership behavior.

## 3. Work packages

### P5-CB7 — Canonical completed-face ownership

1. Represent every completed quad by an orientation-aware canonical cycle of stitch identities.
2. Canonicalize cyclic rotation deterministically and compare reversed cycles explicitly.
3. Record each corner's identity kind, collision-safe identity record or interned ID, diagnostic hash, source component/sheet, and local/global vertex IDs.
4. Record source patch/domain, completion backend, and operation-local quad/region.
5. Include these semantics in structural hashes.

Hashes are diagnostic accelerators only. Equality must compare canonical identity records.

### P5-CB8 — Reclassify patches 378/394

- **Case B — false stitch equivalence:** if distinct source-authoritative corner identities collapse to one stitch key, strengthen the key at its construction point while preserving valid shared-node and feature-interval merges.
- **Case D — completion-template ownership:** if identities are correctly shared but two distinct domains emit the same face, constrain the responsible completion backend to its patch-local region and source support.

Do not discard a final face, weaken `DuplicateStitchedQuad`, branch on observed IDs, or enable recovery/fallback.

### P5-CB9 — Completion-domain proof

Before assembly, prove for every local quad that:

1. generated interior corners belong to the source patch;
2. boundary corners belong to that patch's canonical boundary;
3. source-point support is contained in the descriptor's source-face support;
4. the face has exactly one operation-local region owner;
5. no template emits a boundary-only face belonging wholly to an adjacent patch without explicit shared-face topology.

Fail closed with a typed completion-ownership diagnostic when proof is unavailable.

### P5-CB10 — Generalized discriminator regressions

Add minimized tests for:

1. canonical equality under cyclic and reversed corner order;
2. an under-qualified stitch key classified as false merge;
3. distinct domains whose templates emit one shared-boundary face classified as completion-template ownership;
4. valid adjacent patches sharing only an edge;
5. patch-order and source-face-row-order invariance.

### P5-CB11 — Correct invalid Milestone E fixtures

Correct fixture construction only; preserve or strengthen intended assertions:

1. `SharedEdgeParityRepairConforminglyCompletesTwoOddCells`: create a topology-valid two-cell odd arrangement with a real shared interior interface. The current fixture fails before parity repair on both baseline and current artifacts.
2. `GlobalDescriptorAssignmentRejectsAmbiguousInteriorSingularity`: use distinct domains incident to the same singular source vertex rather than duplicating one domain.
3. `ComplexCompletionFailsClosedInsteadOfReturningPartialOutput`: use distinct source support for the valid and non-disk patches.

### P5-CB12 — Ownership memory and runtime remediation

Same-machine validation regressed from:

- 22.981569 s to a 26.775241 s mean (+16.51%);
- 749,375,488 bytes to a 1,696,000,000-byte mean peak (+126.32%);
- 4.168940 s to a 6.318718 s completion mean (+51.57%).

Use collision-safe interned identity records or compact stable IDs instead of repeated variable-length vectors. Preserve exact equality, deterministic ordering, and complete diagnostics.

## 4. Compile-only gate

The next turn must:

1. modify only ownership, completion, diagnostics, relevant regression fixtures, trackers, and exact artifact packaging;
2. configure a clean Release build;
3. compile `directional_core`, `directional_pipeline`, `directional_phase1_tests`, and `directional_benchmarks`;
4. run no test, benchmark, or custom mesh executable;
5. package exact source, binaries, libraries, logs, source commit/status, and checksums;
6. update TODO, milestone tracker, this plan, and draft PR;
7. leave P5 open and the PR unmerged.

## 5. Following validation turn

Without rebuilding, run:

- canonical face-ownership discriminator regressions;
- corrected `PatchDescriptorMilestoneE.*`;
- `SurfaceArrangementPhase16.*` and `PureQuadCompletionPhase18.*`;
- Phase 14–18 aggregate;
- Milestone G P23 and Phase 20;
- direct random bunny at least twice with recovery disabled;
- same-machine performance comparison.

P5 closes only when direct completion proceeds beyond assembly without duplicate ownership, fallback, recovery, or validator weakening, and ownership overhead is acceptable.