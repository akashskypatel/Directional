# Milestone G P5 — Successful Subdivision Identity Code + Build Report

**Turn:** P5-CB67 through P5-CB74 code changes + compile-only build  
**Review policy:** `never`  
**Runtime status:** unverified; P5 remains open

## Exact checkpoint

- Implementation commit: `9a5c97e7bdb0d11e4cac04bfbe519fb1975d4acd`.
- Exact compiled source: `188baf35a13c02b20424cd72fb9c6d8fe81ec9fc`.
- Compile-only run / job: `30834563914` / `91756464993` — **success**.
- Artifact: `8864496877` (`surface-cell-p5-cb74-successful-identity-linux-release`).
- Artifact digest: `sha256:5629045697a3819f3caeb9416d0d4bbe941d6981d6e226420c5899062378a088`.
- Artifact size: `11,370,618 B`.
- Build: **131/131 steps completed**.
- Source status: empty.
- Packaged checksums: **36/36 verified** after normalizing the archive-time `artifact/` prefix.
- Packaged benchmark fixture files: **26**.
- Packaged `bunny_1k_random.obj`: **1,000 faces**.
- Tests, benchmarks, custom meshes, help/list commands, discovery commands, and compiled binaries executed: **none**.

The temporary source-transfer workflow and all transfer payloads were removed before compilation. The packaged source archive contains the final compile-only workflow and no P5-CB74 transfer workflow or staging path.

## Implemented scope

### P5-CB67 — successful-subdivision identity

- Added typed `SurfaceCellDomainIdentityAudit` results with exact failure kinds for empty/open boundaries, invalid halfedge/twin/next/cell incidence, invalid endpoints, missing or invalid source occurrences, mixed component/sheet identity, invalid source support, and invalid oriented/undirected boundary identities.
- Added first-failure cell, halfedge, node, source face, component, and sheet diagnostics through completion, pipeline context, and benchmark JSON.
- Audited every successful subdivision result before descriptor acceptance and fail closed at the producer boundary.
- Reconstructed inserted-node source charts from both endpoints, both halfedge directions, and canonical provenance instead of relying on one local source face.
- Preserved source component, source sheet, hard-barrier state, rail support, and valid barycentric source occurrences.
- Recomputed cell source support and restored all affected cell fields in the compact undo transaction.

### P5-CB68 — real side-repair rollback path

- Added side-repair options to the full completion options so tests can force a permitted coupled side-repair failure through the production completion call.
- Added regression source requiring exact rollback equivalence and matching before/after identity hashes before any general-completion handoff.
- Preserved one committed complex and one mutable transaction; no duplicate full rollback complex was introduced.

### P5-CB69 — semantic reusable-product lookup

- Replaced allocation-local `cellId` lookup with a semantic dependency hash index.
- Kept hashes as an index only and retained exact collision-safe dependency equality.
- Supported multiple products under one hash and recorded hash-miss and exact-mismatch diagnostics.
- Retargeted reused patch mesh and lineage ownership to the current descriptor without moving unmatched products.
- Removed `cellId` from semantic exact-dependency equality while retaining domain, oriented/undirected boundary, rail, source support, component/sheet, logical-side, backend, and variant dependencies.

Actual positive reuse remains a P5-TB14 runtime gate.

### P5-CB70 — simplification fixed-point contract

- Restored post-commit candidate refresh as the default API behavior.
- Added explicit `refreshCandidatesAfterCommit` and `maxCommittedTransactions` controls for bounded diagnostic transactions.
- Kept production topology healing as a live deterministic fixed point.
- Updated one-transaction fixtures to request bounded behavior explicitly rather than changing the default contract.

### P5-CB71 — Milestone D fixtures

- Rebuilt the multi-edge interface fixture with a real shared canonical interface, twin symmetry, valid incidence, and separate protected-rail support.
- Corrected the cylindrical fixture construction to avoid duplicate desired edges and require a topology-valid starting complex.
- Retained fail-fast fixture preconditions; production validation was not weakened.

### P5-CB72 — authoritative rail propagation

- Propagated canonical rail, curve, parameter, component, sheet, hard-feature, and provenance metadata through arrangement halfedge construction.
- Selected a deterministic primary rail interval while retaining the complete canonical provenance vector.

### P5-CB73 — returned-result lifetime path

- Prevented source-grid recovery from reading completion state unless completion succeeded and before heavy completion storage is released.
- Retained per-case lifecycle markers around pipeline return, input destruction, diagnostic readback, and result destruction for the random-bunny matrix cases.
- Kept all public result diagnostics as owned values.

Elimination of the three prior signal-11 failures is not claimed until P5-TB14 executes the artifact.

### P5-CB74 — compile-only gate

The clean optimized static build compiled and linked only:

- `directional_core`;
- `directional_pipeline`;
- `directional_phase1_tests`;
- `directional_benchmarks`.

Artifact inspection identified both expected x86-64 ELF executables and both static archives without executing either binary. The exact source archive, empty source-status record, recursive submodule status, configure/build logs, complete executable-relative fixture closure, and checksum manifest are present.

## Disposition

Compilation establishes source validity and package completeness only. It does not establish:

- valid production subdivision identity;
- descriptor acceptance or nonempty pure-quad output;
- positive exact reusable-product reuse;
- restored simplification and rail test behavior;
- corrected Milestone D runtime scenarios;
- elimination of the three random-bunny signal-11 failures;
- wall-time compliance;
- successful-path peak memory.

The next authoritative turn is **P5-TB14 artifact-only test and benchmark** using artifact `8864496877` directly without rebuilding.

PR #8 remains open, draft, and unmerged. P5 remains open.
