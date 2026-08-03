# Milestone G P5 — Same-Corner Assembly Conflict Code + Build Plan

**Turn type:** Code changes + compile-only build  
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Base branch:** `surface_cell_quad`  
**Input artifact:** `8841726806`  
**Review policy:** `never`

## 1. Authoritative evidence

Artifact `8841726806` removed the earlier source-support gate and reached assembly deterministically. Both random-bunny runs completed all 21,297 descriptors and failed with the same terminal conflict:

```text
DuplicateStitchedQuad:firstPatch=8595;firstLocalQuad=0;
secondPatch=8573;secondLocalQuad=2;
classification=completion-template
```

The owners have different domain and boundary identities, equal source support, equal canonical stitch corners, equal canonical authoritative corners, the same component/sheet, and closed-form backend variant zero. Four earlier completion ownership repair attempts did not prevent the terminal conflict.

Two regression inputs are also invalid and must be corrected without weakening production logic:

1. the generated-interior escape test changes provenance to a face already contained in `patch.sourceFaces`;
2. the parity fixture has valid DCEL incidence but omits the authoritative geometry/source diagnostics required for `topologyValid`.

## 2. Non-negotiable constraints

- Do not delete or deduplicate final faces.
- Do not merge vertices by position.
- Do not special-case patch IDs `8595`, `8573`, `378`, or `394`.
- Do not use source-triangle pairing, source-grid recovery, legacy fallback, or validator weakening.
- Preserve transactional assembly: failure returns no accepted partial mesh.
- Preserve exact domain, boundary, source-support, component, sheet, and lineage identities.
- Correct invalid tests so they exercise their stated contracts; do not make them pass synthetically.
- This turn may configure and compile only. It must not execute tests, benchmarks, or custom meshes.

## 3. Work packages

### P5-CB21 — Correct the two invalid regression fixtures

#### Generated interior source-support escape

- Extend the fixture with a valid source triangle that is not included in the patch's `sourceFaces`.
- Mutate the generated interior provenance to that outside face with finite barycentrics and matching position/lineage.
- Retain the expected typed failure `CompletionOwnershipSourceSupportEscape` and `boundaryVertex == false`.
- Add a paired positive control proving a generated interior on either allowed patch face remains valid.

#### Shared-edge parity fixture

- Keep the explicit two bounded odd cells and real shared interface.
- Populate node positions and cell area/signed-area evidence from the source triangles.
- Populate source Euler characteristic, connected-component count, boundary-loop count, supported area, embedding validity, and other inputs consumed by `recompute_rebuilt_diagnostics()`.
- Prefer constructing the complex through the production arrangement helper when feasible.
- Require `validate_complex_incidence()` and recomputed `topologyValid` to succeed naturally; never assign the final validity flag directly.

### P5-CB22 — Add exact same-corner claim evidence before repair

Create a compact deterministic claim record for every completed quad containing:

- canonical stitch and authoritative corner cycles;
- source patch, local quad, backend, and variant;
- complete domain identity;
- oriented boundary-node identity;
- undirected boundary-halfedge identity;
- source support, component, and sheet;
- patch side count, side subdivisions, boundary vertex count, and boundary halfedge count.

When two claims have equal authoritative corner cycles but different domain boundaries, classify them separately from generic completion-template ownership, for example as `SameCornerDistinctBoundaryClaim`.

Record a bounded repair-attempt ledger containing the conflict class, selected owner, old/new variant or structural repair, and resulting conflict. Hashes remain diagnostics; exact identities decide equality.

### P5-CB23 — Repair same-corner/distinct-boundary claims upstream

Use the complete boundary-halfedge identities to distinguish two cases before accepting any global face:

1. **Invalid overlapping arrangement ownership**  
   If the embedded domains overlap or duplicate source-area ownership despite different serialized boundaries, fail closed before completion with a typed arrangement-domain error and complete evidence.

2. **Valid distinct parallel boundary routes with the same corner nodes**  
   Apply a bounded, deterministic, transactional boundary-sector subdivision before completion:
   - choose the lowest canonical differing authoritative boundary interval;
   - split the complete undirected interval, including its twin, through the existing complex edge-subdivision machinery;
   - rerun parity repair, coupled side-subdivision repair, descriptor derivation, and completion for the affected connected patch neighborhood;
   - require exact source provenance, component/sheet consistency, disk topology, and conforming neighbor boundaries;
   - commit only if the repaired neighborhood removes the same-corner claim and passes all existing local ownership/lineage validators.

Closed-form patches have no rotational variants. Do not count unavailable closed-form variants as repair attempts. Structural repair must be bounded by an explicit option and deterministic ordering.

If neither ownership overlap nor a valid conforming subdivision can be proven, fail closed with `SameCornerDistinctBoundaryUnresolved` rather than emitting duplicate faces.

### P5-CB24 — Generalized regression sources

Add or correct compiled test sources for:

- generated interior outside-source-support rejection using a genuinely outside face;
- generated interior positive control on both allowed patch faces;
- topology-valid two-odd-cell parity repair;
- two valid parallel boundary routes with the same four corner nodes requiring conforming subdivision;
- overlapping same-corner domains failing before final assembly;
- patch and insertion-order invariance;
- repeated-run structural hash stability;
- closed-form conflict routing that does not pretend a rotation variant exists;
- final `DuplicateStitchedQuad` validation remaining active after repair.

### P5-CB25 — Preserve performance and bounded memory

- Reuse compact identity IDs and exact interned records.
- Do not retain full per-quad variable-length boundary data after conflict resolution unless diagnostics request it.
- Restrict structural repair and re-completion to the affected patch neighborhood.
- Release superseded meshes and descriptor capacity after each committed repair.
- Keep deterministic hard limits for structural attempts and inserted boundary vertices.

## 4. Compile-only gate

Configure a clean optimized static Release build and compile only:

- `directional_core`;
- `directional_pipeline`;
- `directional_phase1_tests`;
- `directional_benchmarks`.

Required evidence:

- exact pushed source commit;
- empty source status before packaging;
- configure and build logs;
- exact source archive and recursive submodule revisions;
- checksums for all packaged files;
- explicit confirmation that no test, benchmark, or custom mesh executable ran.

## 5. Acceptance checklist for this turn

- [ ] Both invalid test fixtures are corrected for their intended scenarios.
- [ ] Same-corner/distinct-boundary claims have an exact typed classification.
- [ ] Attempt diagnostics identify every variant or structural repair decision.
- [ ] Valid parallel-route claims receive bounded conforming upstream repair.
- [ ] Invalid overlapping claims fail before final face assembly.
- [ ] Closed-form patches do not consume nonexistent rotation variants.
- [ ] No prohibited recovery, fallback, deduplication, positional ownership, or ID special case is introduced.
- [ ] All four required targets compile from the exact pushed source.
- [ ] No tests or benchmarks execute.

## 6. Handoff

P5 remains open after compilation. The following authoritative turn must use the packaged artifact without rebuilding and rerun the focused regressions, PatchDescriptor suite, Phase 14–18 aggregate, Milestone G P23/Phase 20, and at least two direct random-bunny processes. It must determine whether the `8595/8573` claim is resolved, reclassified upstream, or remains fail-closed, and must measure repair count, runtime, and peak memory.
