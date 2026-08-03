# Milestone G P5 — Assembly Conflict Test + Benchmark Report

**Turn type:** Test and benchmark only  
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Artifact:** `8841726806`, `surface-cell-p5-branch-linux-release`  
**Exact compiled source:** `053fe3816f585320e65526824f1107b8ccb1332d`  
**Artifact digest:** `sha256:9b9bf5ad23640dfe049d416a0b81649c2e8a3d0353e1bff475fa6ea58155a681`  
**Rebuild performed:** No  
**Review policy:** `never`

## 1. Artifact validation

- `source-commit.txt` is exactly `053fe3816f585320e65526824f1107b8ccb1332d`.
- `source-status.txt` is empty.
- All ten packaged checksums pass after normalizing the upload-root prefix used by the workflow manifest.
- The packaged test and benchmark executables are Linux x86-64 ELF binaries.
- The core and pipeline libraries are valid static archives.
- The exact source archive, configure/build logs, and recursive submodule revisions are present.
- No source, test, benchmark, or build configuration was edited during execution.

## 2. Test results

| Scope | Passed | Failed | Result |
|---|---:|---:|---|
| Focused intrinsic-support, canonical-diagnostic, and parity subset | 5 | 2 | Failed |
| `PatchDescriptorMilestoneE.*` | 14 | 1 | Failed |
| `SurfaceArrangementPhase16.*` + `PureQuadCompletionPhase18.*` | 86 | 1 | Failed |
| Phase 14–18 aggregate | 226 | 1 | Failed |
| Milestone G P23 + Phase 20 | 52 | 0 | Passed |

The non-overlapping authoritative scopes contain **294 executions: 292 passed and 2 failed**.

### Passing remediation contracts

The following source-support and ownership changes passed for their intended reasons:

- intrinsic source-edge and source-vertex incidence resolution;
- boundary vertex and edge chart aliases;
- face-interior support escape rejection;
- component/sheet mismatch rejection at a shared source entity;
- canonical completed-face diagnostics under cyclic rotation and reversal;
- all 52 Milestone G P23 and Phase 20 fail-closed tests.

### Failure 1 — generated-interior escape test is incorrectly constructed

`PureQuadCompletionPhase18.CompletionRejectsGeneratedInteriorOutsidePatchSupport`

The fixture defines:

```text
patch.sourceFaces = {0, 1}
```

The test then changes the generated interior provenance to `face = 1`. Face 1 is still inside the patch's authoritative support, so `validate_completion_domain_ownership()` correctly accepts it. The test does not create the scenario named by its contract.

The next code turn must correct the fixture by providing a valid source face outside the patch support—preferably a third source triangle with valid barycentric provenance—and must continue to expect `CompletionOwnershipSourceSupportEscape`. Production validation must not be weakened to satisfy the current invalid input.

### Failure 2 — parity fixture has valid incidence but incomplete topology evidence

`PatchDescriptorMilestoneE.SharedEdgeParityRepairConforminglyCompletesTwoOddCells`

`validate_complex_incidence(complex)` passes, proving the explicit twin/next/cell DCEL is internally consistent. `complex.diagnostics.topologyValid` remains false because `recompute_rebuilt_diagnostics()` also requires authoritative embedding, orientation, source Euler characteristic, connected-component count, boundary-loop count, and area evidence. The fixture constructs the DCEL but does not initialize the required geometric/source diagnostic baseline.

The next code turn must construct this fixture through the real arrangement path or populate all authoritative geometry and source-topology inputs before recomputation. It must not assign `topologyValid = true` synthetically.

## 3. Direct random-bunny result

Two independent processes used:

- case `bunny_1k_random__surface_cells`;
- backend `SurfaceCells`;
- fallback policy `Fail`;
- source-grid recovery disabled;
- zero warmups and one measured run per process.

Both runs reached global assembly and failed deterministically with the same conflict:

```text
DuplicateStitchedQuad:firstPatch=8595;firstLocalQuad=0;
secondPatch=8573;secondLocalQuad=2;
globalVertices=10764,16938,27456,27459;
classification=completion-template
```

Additional authoritative conflict evidence:

- both owners use backend `closed-form`, variant `0`;
- domain hashes differ;
- oriented boundary-node hashes differ;
- undirected boundary-halfedge hashes differ;
- source-support hashes are equal;
- component and sheet are both `0` for both owners;
- all four canonical stitch identities match;
- all four canonical authoritative corner identities match;
- `completionOwnershipRepairAttempts = 4` before the terminal conflict.

The previous `CompletionOwnershipSourceSupportEscape` blocker is resolved. The pipeline now completes all descriptors and reaches assembly. The earlier patches `378/394` conflict was not reproduced; a later deterministic completion-template conflict at patches `8595/8573` remains.

| Metric | Run 1 | Run 2 |
|---|---:|---:|
| Wall time | 26.976277 s | 25.328120 s |
| Peak working set | 892,391,424 B | 892,239,872 B |
| Arrangement cells | 21,298 | 21,298 |
| Descriptors attempted | 21,297 | 21,297 |
| Descriptors completed | 21,297 | 21,297 |
| Descriptors failed | 0 | 0 |
| Ownership repair attempts | 4 | 4 |
| Required unresolved endpoints | 0 | 0 |
| Accepted output quads | 0 | 0 |
| Completion stage | 6.949674 s | 6.000932 s |
| Output origin | `None` | `None` |

The fixture hash, terminal failure, conflict payload, counts, context-product structural hashes, and every stage input/output structural hash match across both runs. No recovery or legacy fallback occurred. Assembly remains transactional, so no partial quad output was accepted.

## 4. Root-cause classification for the next turn

The remaining conflict is not a false positional merge:

- the canonical stitch cycles match;
- the exact authoritative corner cycles also match;
- the two domains have different full boundary identities but the same source support.

This evidence is consistent with **distinct arrangement domains collapsing to the same four arrangement-node output face**, likely through different authoritative boundary-halfedge routes with identical corner nodes. Both terminal owners are closed-form patches, for which the current completion variant count is one; rotation-based variant repair cannot alter them.

The repair must occur before final-face acceptance and must use the complete arrangement-domain and boundary-halfedge evidence. Final-face deletion, deduplication, positional splitting, patch-ID special cases, source-triangle pairing, recovery, or fallback are prohibited.

## 5. Performance

Current two-run means:

- wall time: **26.152199 s**;
- peak working set: **892,315,648 B**;
- completion stage: **6.475303 s**.

| Comparison | Wall | Peak memory | Completion |
|---|---:|---:|---:|
| Baseline artifact `8838467442` | +13.80% | +19.07% | +55.32% |
| Ownership artifact `8840174777` | -2.33% | -47.39% | +2.48% |
| Previous artifact `8840866875` | +5.30% | +2.24% | +25.09% |

Memory remains substantially improved relative to the first ownership artifact, but the new source-support and four repair attempts increase completion time materially relative to the previous checkpoint and baseline.

## 6. Disposition

P5 remains open. PR #8 must stay draft and unmerged.

The next authoritative turn is **code changes + compile-only build** using:

- `.agents/Directional/Milestone_G_P5_Assembly_Conflict_Code_Build_Plan.md`;
- this report;
- `benchmark-results/p5-tb7-summary.json`.

That turn must correct the two invalid test fixtures, implement an upstream transactional repair or fail-closed classification for same-corner/distinct-boundary completion claims, preserve exact ownership and validators, compile the four required targets, and execute no tests, benchmarks, or custom meshes.
