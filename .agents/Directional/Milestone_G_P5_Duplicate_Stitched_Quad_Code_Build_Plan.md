# Milestone G P5 — Duplicate Stitched-Quad Remediation

**Authority:** Next code + build turn for `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Prepared:** 2026-08-02 13:29 PDT  
**Baseline source checkpoint:** `c84e2e1d64e867e5975f414780f9c81e649612fb`  
**Turn type:** Code changes + compile-only build. Do not execute tests or benchmarks.  
**Production disposition:** `SurfaceCells` remains experimental, default-off, and fail-closed.

## 1. Objective

Remove the remaining P5 completion blocker by correcting the authoritative topology or vertex-ownership rule that allows two completed arrangement patches to assemble into the same global quad.

The next implementation checkpoint must preserve transactional duplicate detection. It must not discard an output face because its vertex set matches another face, suppress the `DuplicateStitchedQuad` failure, special-case sparse patch IDs, or use `SourceGridRecovery`.

## 2. Verified entry state

The preceding test-and-benchmark turn established this exact baseline:

- Focused intrinsic-fan and duplicate-diagnostic regressions: **2/2 passed**.
- Phase 14–18 tests: **216/216 passed**.
- Milestone G P23 and Phase 20 fail-closed tests: **52/52 passed**.
- Direct `bunny_1k_random.obj` execution used `SurfaceCells`, `Fail`, and source-grid recovery disabled.
- Both measured runs failed deterministically at completion with:

```text
DuplicateStitchedQuad:firstPatch=241;firstLocalQuad=0;
secondPatch=255;secondLocalQuad=1;globalVertices=860,861,862,863
```

- Arrangement cells: **21,298**.
- Patch descriptors attempted/completed/failed: **21,297 / 21,297 / 0**.
- Required unresolved endpoints: **0**.
- Completion emitted no accepted output because global assembly rejected the duplicate transactionally.

This narrows the remaining defect to ownership or identity reconciliation after every individual descriptor has completed successfully.

## 3. Non-negotiable correctness rules

1. **Do not deduplicate final quads.** A repeated global quad is evidence of an upstream topology or identity defect, not an output-cleanup opportunity.
2. **Do not branch on fixture names or sparse IDs.** Patches `241` and `255`, local quad IDs, global vertex IDs, coordinates, cell counts, and expected output counts are diagnostic evidence only.
3. **Do not weaken assembly validation.** `DuplicateStitchedQuad` remains fail-closed and continues to report both authoritative sources.
4. **Do not merge by position alone.** Coincident vertices on different source sheets, components, patch interiors, or unrelated feature intervals remain distinct.
5. **Do not remove required singular support or alter endpoint truthfulness.** The zero-required-unresolved-endpoint result must remain structurally possible.
6. **Do not use recovery or fallback as a repair.** `SourceGridRecovery`, legacy meshing, source-triangle pairing, malformed-cell triangulation, and input-mesh fallback are prohibited.
7. **Preserve deterministic behavior.** Canonical ownership must be independent of descriptor insertion order, patch vector order, source-face row order, and incidental container iteration order.

## 4. Root-cause classification contract

Before changing ownership, represent the duplicate pair using authoritative data rather than assembled coordinates. For each conflicting local quad, recover:

- source arrangement cell ID;
- canonical ordered boundary-node cycle;
- canonical ordered boundary-halfedge identities;
- retained-arc provenance intervals and direction;
- source component and local sheet ownership;
- sorted source-face support;
- rail/curve interval ownership;
- completion backend and local quad lineage;
- local-to-global vertex identity keys;
- source-point or generated-vertex lineage for every corner.

Classify the conflict into exactly one of these cases:

### A. Duplicate arrangement-domain ownership

Both patches describe the same oriented source-side disk: equivalent canonical boundary cycle, source support, component, sheet, and feature ownership.

**Required repair:** eliminate the duplicate domain before patch completion by fixing cell extraction or canonical cell ownership. Rebuild incidence/ownership consistently; do not merely skip the second descriptor.

### B. False vertex equivalence during stitching

The patches are distinct authoritative domains, but position-based or under-qualified identity merging collapses their corners to the same global vertices.

**Required repair:** replace the faulty equivalence rule with source-authoritative vertex keys. Position tolerance may validate geometry after identities match; it may not create identity.

### C. Distinct arrangement cells with overlapping retained boundaries

The cells are not identical, but duplicated/overlapping retained arcs produce coincident closed cycles.

**Required repair:** normalize retained arcs and ownership before cell extraction. Split or merge intervals only when source arc, parameter range, side, family, component, sheet, and feature semantics prove equivalence.

### D. Completion-template ownership defect

The authoritative domains are distinct and vertex identities are correct, but a completion template emits a quad outside its source patch or maps two local regions to the same boundary cycle.

**Required repair:** constrain the completion template to the patch domain and correct its local lineage. Do not compensate in global assembly.

The implementation may support more than one class where the source reveals independent correctness defects, but every mutation must be justified by one of these contracts.

## 5. Implementation work packages

### P5-CB1 — Add canonical topology and ownership identities

Implement reusable, deterministic keys for diagnosis and enforcement:

- **Arrangement cell domain key**
  - orientation-aware canonical rotation of directed boundary-halfedge keys;
  - source component and sheet;
  - boundary/interior classification;
  - canonical source-face support;
  - rail, curve, family, side, and retained-provenance semantics.
- **Stitch vertex identity key**
  - authoritative arrangement-node identity for shared patch boundaries;
  - canonical source vertex or source-face/barycentric identity for source points;
  - ordered feature-interval identity for rail vertices;
  - patch-qualified identity for generated interior vertices;
  - explicit component/sheet qualification where identity could otherwise cross sheets.
- **Completed face ownership record**
  - source patch/cell;
  - completion backend;
  - operation-local quad;
  - canonical local corner identities;
  - resulting global corner identities.

Canonicalization must use exact topology and quantized source parameters already governed by existing tolerances. It must not use world-space coordinate sorting as the primary identity.

### P5-CB2 — Enforce unique arrangement-domain ownership

At the last stage where the complete arrangement topology is still available:

1. Build the canonical domain key for every non-boundary cell eligible for a patch descriptor.
2. Detect repeated ownership keys deterministically.
3. For a proven duplicate domain, repair the arrangement construction or retained-arc ownership so exactly one valid cell owns each oriented domain.
4. Recompute or validate:
   - directed-halfedge ownership;
   - twin relationships;
   - cell boundary cycles;
   - disk status;
   - component, boundary-loop, and Euler diagnostics;
   - source-face and provenance coverage.
5. Fail closed with a typed diagnostic when two cells overlap but cannot be proven equivalent.

A map-level “keep the smaller cell ID” filter is prohibited unless the topology itself is normalized and all ownership/incidence invariants are re-established.

### P5-CB3 — Harden patch stitching identity

Update stitching so union operations occur only for vertices with equal authoritative identity:

- Shared arrangement boundary nodes may merge.
- Equivalent source-vertex representations across incident source faces may merge after canonical source-vertex resolution.
- Equivalent points on the same ordered feature interval may merge when interval identity and parameter agree.
- Generated interior vertices remain unique to `(sourcePatch, localVertex)` unless an explicit topology record proves shared ownership.
- Vertices on different components or local sheets never merge solely because positions are coincident.
- Position tolerance checks consistency after an identity match and continues to reject inconsistent shared-boundary geometry.

Retain final canonical-quad duplicate detection after stitching. It remains a validator, not a repair mechanism.

### P5-CB4 — Improve conflict diagnostics without fixture coupling

When duplicate global quads remain, report enough authoritative evidence to select the next repair without rebuilding a custom binary:

- both source patch/cell IDs and local quad IDs;
- canonical arrangement-domain hashes;
- canonical boundary-node and boundary-halfedge hashes;
- component/sheet ownership;
- source-face-support hashes/counts;
- per-corner stitch identity kind and canonical identity hash;
- whether the pair is classified as same-domain, false-merge, overlapping-boundary, or unclassified.

Keep the existing stable failure prefix and both-source reporting so current diagnostics remain compatible.

### P5-CB5 — Add generalized regression sources

Add tests, but compile them only in this turn. Tests must be independent of bunny IDs and insertion order.

Required regression cases:

1. **Equivalent domain, reordered IDs** — two topologically equivalent arrangement cells with different sparse IDs and reversed insertion order produce one canonical owner or a typed pre-completion topology failure, never duplicate output faces.
2. **Distinct sheets, coincident positions** — identical coordinates on separate local sheets do not merge during stitching.
3. **Generated interiors are patch-local** — coincident generated interior vertices from distinct patches remain distinct without explicit shared topology.
4. **Authoritative shared boundary merges** — adjacent patches sharing the same arrangement nodes still stitch conformingly.
5. **Order invariance** — patch vector order, descriptor insertion order, and source-face row order do not change ownership keys, assembled topology, or failure classification.
6. **Duplicate detector remains active** — deliberately duplicated authoritative meshes still fail and report both source patches.
7. **Inconsistent shared geometry remains rejected** — the existing position-consistency guard continues to fail closed.

Prefer minimized analytic fixtures that encode the invariant. Do not copy bunny coordinates, patch IDs, or expected counts into tests.

### P5-CB6 — Pipeline and lineage integration

Propagate any new typed ownership diagnostics through completion and pipeline diagnostics without changing success semantics:

- success remains possible only from completed surface cells followed by optimization and strict validation;
- any unresolved ownership conflict terminates at `completion` with output origin `None`;
- no partial quad mesh escapes a failed transaction;
- structural hashes include the new ownership semantics so mutations are observable;
- diagnostics remain deterministic across equivalent ordering changes.

## 6. Expected source scope

Likely implementation files:

- `include/directional/geometry/SurfaceArrangement.h`
- `include/directional/geometry/PatchDescriptor.h`
- `include/directional/geometry/PureQuadCompletion.h`
- `include/directional/pipeline/RemeshPipeline.h`
- `include/directional/diagnostics/RemeshDiagnostics.h` when typed diagnostic fields are added

Likely regression files:

- `tests/SurfaceArrangementPhase16Tests.cpp`
- `tests/PatchDescriptorMilestoneETests.cpp`
- `tests/PureQuadCompletionPhase18Tests.cpp`
- `tests/SurfaceCellPipelinePhase20Tests.cpp`
- `tests/DiagnosticsTests.cpp` when serialization changes

The exact file set may be smaller after source inspection. Do not edit unrelated feature, tracing, optimization, validation-threshold, or fallback code.

## 7. Compile-only build procedure

The code/build turn must not execute `ctest`, GoogleTest binaries, benchmark binaries, or custom mesh runs.

1. Start from the current active branch and synchronize it with `surface_cell_quad` without rewriting history.
2. Fetch required submodules recursively with shallow history.
3. Implement P5-CB1 through the applicable repair path in P5-CB2/P5-CB3, plus diagnostics and regression sources.
4. Configure a clean Release build.
5. Compile only:
   - `directional_core`;
   - `directional_pipeline`;
   - `directional_phase1_tests`;
   - `directional_benchmarks`.
6. Do not run any compiled executable.
7. Commit ordinary source files directly to the active branch.
8. Produce an artifact containing:
   - compiled test and benchmark binaries;
   - required shared/static libraries;
   - exact source snapshot needed by the next test turn;
   - `source-commit.txt`;
   - `source-status.txt`;
   - build/configuration logs.
9. Verify `source-commit.txt` equals the exact implementation commit used by the build.
10. Update the root `TODO`, this plan, and draft PR with the implementation classification, changed invariants, build run, artifact ID, digest, and explicit statement that no tests or benchmarks ran.

## 8. Code/build turn acceptance gate

The next turn is complete only when all of the following are true:

- [ ] The source-level root cause is classified under A, B, C, or D with evidence from authoritative data structures.
- [ ] The repair enforces a general topology/ownership invariant rather than suppressing duplicate output.
- [ ] Final duplicate-quad detection remains fail-closed.
- [ ] New generalized regression sources compile.
- [ ] Existing test and benchmark targets compile in a clean Release build.
- [ ] No test or benchmark executable was run.
- [ ] The exact implementation commit and build artifact are recorded.
- [ ] The branch remains unmerged and P5 remains open pending the next test-and-benchmark turn.

A successful compile is not evidence that the bunny failure is fixed. The fix is accepted only in the following test turn.

## 9. Required handoff to the following test-and-benchmark turn

The build artifact must allow the next turn to execute, without rebuilding:

1. new minimized ownership/identity regressions;
2. `SurfaceArrangementPhase16.*`;
3. `PatchDescriptorMilestoneE.*`;
4. `PureQuadCompletionPhase18.*`;
5. Phase 14–18 aggregate suites;
6. Milestone G P23 and Phase 20 fail-closed suites;
7. direct `bunny_1k_random.obj` with source-grid recovery disabled, repeated for determinism.

The next benchmark must confirm either:

- successful global assembly with no duplicate quad and no required unresolved endpoints; or
- a new, more authoritative fail-closed diagnostic identifying the remaining topology defect.

P5 closes only after direct completion proceeds past assembly without duplicate ownership, `SourceGridRecovery`, legacy fallback, or validator weakening.
