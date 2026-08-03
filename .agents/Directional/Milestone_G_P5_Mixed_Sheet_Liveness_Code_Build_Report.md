# Milestone G P5 — Mixed-Sheet Identity and Pipeline Liveness Code + Build Report

**Turn:** P5-CB75 through P5-CB82 code changes + compile-only build  
**Review policy:** `never`  
**Runtime status:** unverified; P5 remains open

## Exact checkpoint

- Implementation commit: `1dab9a0e8915e7d9641c9b005bfa57eaefb4a8cc`.
- Exact compiled source: `f4a6a392dc3d490efca4f94bd613aadaad2c1b01`.
- Compile-only run / job: `30839059634` / `91771355792` — **success**.
- Artifact: `8866222973` (`surface-cell-p5-cb82-mixed-sheet-liveness-linux-release`).
- Artifact digest: `sha256:c38649208b1586094f804895c39c1319b71eb0c5220e84d1d2514b04954c63fe`.
- Build: **131/131 steps completed**.
- Source status: empty.
- Packaged checksums: **36/36 verified** after normalizing the archive-time `artifact/` prefix.
- Packaged fixture files: **26**.
- Packaged random bunny: **502 vertices / 1,000 triangle faces**.
- Tests, benchmarks, custom meshes, help/list commands, discovery commands, and compiled binaries executed: **none**.

## Implemented scope

### P5-CB75 — exact oriented source-sheet identity

- Extended arrangement-node occurrences from `(face, barycentric)` to exact source-chart records containing component, sheet, arc/provenance identity, source interval, rail/curve identity, and oriented rail interval.
- Added component/sheet-scoped node chart lookup.
- Arrangement node creation records exact occurrence scope and provenance at each segment parameter.
- After cell construction, each oriented halfedge selects a deterministic compatible provenance record; twin directions are rebound independently rather than sharing one primary chart.
- Subdivision creates forward and reverse occurrence scopes independently, preserves component/sheet and source intervals, and reconstructs each affected cell from one deterministic exact boundary scope.
- Successful subdivision fails closed when a rebuilt cell has missing or mixed component/sheet support.
- Structural and pipeline hashes include the extended occurrence identity.

### P5-CB76 — exact rollback and undo ownership

- Rollback identity now covers the extended occurrence scope and provenance fields.
- Side-repair rollback captures committed identity before logical-side canonicalization and restores logical-side metadata before proving equivalence.
- Subdivision retains committed halfedges, restores changed cells from compact undo records, and truncates appended nodes on rejection.
- Added separately reported rollback undo-owned bytes through subdivision, completion, pipeline diagnostics, and benchmark JSON.
- Common-chart membership and malformed midpoint embedding remain separate typed contracts, allowing the direct rollback regression to reach `InvalidMidpointEmbedding` after a declared common chart is found.

### P5-CB77 — reusable-product consumption semantics

- Reusable completion products are paired with descriptors without collapsing duplicate/local patch identifiers into a lossy map.
- Semantic hash buckets may retain multiple products.
- Exact lookup ignores consumed entries, marks the chosen exact product consumed, and leaves unmatched products intact.
- Reused meshes are retargeted only after collision-safe exact dependency equality.

Positive runtime reuse is not claimed until P5-TB15.

### P5-CB78 — rail and provenance preservation

- Arrangement occurrences and halfedges retain authoritative rail/curve identity, oriented parameters, source scope, classification, and complete provenance.
- The post-stitch cell rebind prioritizes hard-feature and authoritative-rail provenance deterministically instead of inferring rail identity from geometry.

### P5-CB79 — valid Milestone D fixture construction

- Replaced the invalid multi-edge-interface fixture with an explicit valid DCEL: two interior cells, one exterior cycle, two canonical shared interface edges, valid twins/next/cell incidence, exact source scope, and deterministic topology diagnostics.
- Cylinder source-edge arcs are now emitted in every incident source triangle chart instead of only the first matching face.

### P5-CB80 — generation-bounded simplification frontier

- Every candidate carries a generation and semantic identity hash.
- Each generation is semantically deduplicated before queue insertion.
- Stale generations are discarded before evaluation.
- A committed edit must monotonically reduce undirected-edge count.
- Candidate refresh replaces the superseded queue and candidate storage with one new generation rather than appending to stale frontier state.
- Added generated, deduplicated, invalidated, stale, generation-count, peak-live, and evaluated-candidate diagnostics through the pipeline and benchmark JSON.

### P5-CB81–P5-CB82 — lifetime and memory contracts

- Scoped node occurrences remove reliance on one mutable node-level primary chart across close sheets.
- Reusable product payloads are not moved from unmatched entries and are consumed once.
- Candidate references are not retained across generation replacement.
- Rollback undo ownership is reported separately from current structural ownership.
- Temporary source-transfer workflow and payloads were removed before the compiled checkpoint.

## Compile and artifact evidence

The clean optimized static Ninja build compiled and linked only:

- `directional_core`;
- `directional_pipeline`;
- `directional_phase1_tests`;
- `directional_benchmarks`.

The artifact contains both expected x86-64 ELF executables, both static libraries, complete executable-relative fixtures, exact source archive, empty source-status record, recursive submodule revisions, configure/build logs, and checksum manifest. The source archive contains no P5-CB82 staging payload or temporary source-transfer workflow.

## Disposition

Compilation establishes source validity and package completeness only. It does not establish mixed-sheet correction, rollback equality, positive exact reuse, rail survival, fixture validity, simplification convergence, signal-11 elimination, random-bunny output, timing, or successful-path memory.

The next authoritative turn is **P5-TB15 artifact-only test and benchmark** using artifact `8866222973` directly without rebuilding.

PR #8 remains open, draft, and unmerged. P5 remains open.
