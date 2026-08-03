# Milestone G P5 — Same-Corner Assembly Conflict Code + Build Report

**Turn type:** Code changes + compile-only build  
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Review policy:** `never`

## 1. Authoritative input

This turn implemented `.agents/Directional/Milestone_G_P5_Assembly_Conflict_Code_Build_Plan.md` against the deterministic P5-TB7 evidence from artifact `8841726806`.

The previous direct random-bunny runs completed all 21,297 patch descriptors and reached assembly, then failed on equal canonical corner ownership claimed by two distinct arrangement domains. Both claims were closed-form variant zero, so rotational completion variants could not resolve the conflict. Two regression fixtures were also invalid for their stated scenarios.

## 2. Implemented production changes

### Exact same-corner/distinct-boundary classification

- Added the explicit `SameCornerDistinctBoundaryClaim` conflict class.
- Classification requires exact equality of canonical stitch and authoritative corner cycles while complete domain or boundary identities differ.
- Extended conflict evidence with completion variants, boundary node/halfedge/vertex counts, side counts, and source-support/component/sheet scope.
- Hashes remain diagnostic only; exact interned identities determine equality.

### Bounded repair-attempt ledger

- Added a typed repair-action enum for completion variants and boundary-sector subdivision.
- Added deterministic attempt records containing conflict class, selected owner, previous/new variant or structural action, candidate boundary interval, and resulting status.
- Propagated attempt counters and records through completion results, pipeline products, diagnostics, semantic hashes, and benchmark JSON.
- Closed-form patches no longer consume nonexistent rotational-variant attempts.

### Upstream transactional boundary repair

- For a proven same-corner/distinct-boundary claim, the implementation computes the canonical symmetric difference of the owners' complete undirected boundary-halfedge identities.
- Candidate intervals are sorted deterministically and bounded by explicit repair and insertion limits.
- Repair uses the existing `subdivide_surface_cell_complex_edges()` machinery, including twin-side subdivision.
- The repaired complex is revalidated and reruns parity repair, coupled side-subdivision repair, descriptor derivation, and completion transactionally.
- A repair is committed only when the original exact ownership claim is removed and all existing topology, source-support, lineage, geometry, component/sheet, and duplicate validators remain satisfied.
- Unproven overlap or exhausted structural repair fails closed before accepting final output.

No final-face deletion or deduplication, positional vertex merge, patch-ID special case, source-triangle pairing, source-grid recovery, legacy fallback, or validator weakening was introduced.

## 3. Regression-source corrections and additions

Compiled but intentionally not executed:

- The generated-interior escape fixture now includes a valid third source triangle outside `patch.sourceFaces`.
- Added positive controls for generated interiors on each allowed patch face.
- The escape case retains the typed `CompletionOwnershipSourceSupportEscape` expectation with non-boundary provenance.
- The two-odd-cell parity fixture now supplies authoritative node geometry, signed/absolute area, Euler characteristic, component count, boundary-loop count, supported area, embedding, and orientation evidence before recomputation.
- Added same-corner/distinct-boundary classification and routing coverage.
- Preserved final `DuplicateStitchedQuad` validation as an active transactional backstop.

## 4. Source checkpoints

- Primary implementation commit: `4b7e02b0e8248a8093959147e27cc1ee9440d35a`.
- Minimal compile correction: `1f4c3c2a014f0bc945b50f1bb5a837c438cec992`.
- Exact compiled source: `1f4c3c2a014f0bc945b50f1bb5a837c438cec992`.

The first clean compilation exposed one stale enum spelling in `PatchDescriptor.cpp`: `PureQuadCompletionBackend::BoundedSearch`. The defined backend is `BoundedCombinatorial`; that single reference was corrected without changing the ownership or repair design.

Transient patch payloads were deleted before the primary source commit. The temporary materialization workflow was restored to the standard compile-only workflow after artifact creation.

## 5. Compile-only evidence

- Workflow run: `30776779114` — **success**.
- Artifact: `8842377256`, `surface-cell-p5-same-corner-linux-release`.
- Artifact digest: `sha256:669bf5d6f3e9b3738298b5985b6bb715668bce0715b0a68d880eb4aa0e80d6bc`.
- Toolchain: GCC 13.3.0, optimized static Release build.
- Build steps: **131/131 completed**.
- Required targets compiled and linked:
  - `directional_core`;
  - `directional_pipeline`;
  - `directional_phase1_tests`;
  - `directional_benchmarks`.

Artifact verification:

- `source-commit.txt` is exactly `1f4c3c2a014f0bc945b50f1bb5a837c438cec992`;
- `source-status.txt` is empty;
- all ten packaged checksums pass;
- test and benchmark binaries are Linux x86-64 ELF executables;
- core and pipeline outputs are valid static archives;
- exact source archive, configure/build logs, and recursive submodule revisions are included.

No test, benchmark, or custom mesh executable ran in this turn.

## 6. Status and handoff

P5 remains open. Compilation establishes source validity only; it does not establish that boundary-sector repair resolves the production bunny claim or that corrected fixtures pass.

The next authoritative turn is **test and benchmark using artifact `8842377256` without rebuilding**. It must:

1. verify artifact source, empty status, and checksums;
2. run corrected generated-interior and parity fixtures;
3. run same-corner classification, overlap, closed-form routing, order-invariance, and repair-attempt regressions;
4. run `PatchDescriptorMilestoneE.*`, Phase 16/18, the Phase 14–18 aggregate, and Milestone G P23/Phase 20;
5. run `bunny_1k_random.obj` in at least two independent processes with `SurfaceCells`, fallback `Fail`, and source-grid recovery disabled;
6. determine whether the previous `8595/8573` ownership claim is removed, reclassified upstream, or remains fail-closed;
7. record variant and structural repair attempts, inserted intervals, descriptor/endpoint counts, output origin, accepted quads, all structural hashes, runtime, and peak memory;
8. compare performance with artifacts `8838467442`, `8840174777`, `8840866875`, and `8841726806` on the same machine.

PR #8 remains draft and unmerged.
