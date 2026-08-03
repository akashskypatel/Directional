# Milestone G P5 — Successful Subdivision Identity Code + Build Plan

**Next turn:** P5-CB67 through P5-CB74 code changes + compile-only build  
**Input artifact:** P5-TB13 artifact `8860409984`  
**Exact tested source:** `074ec5d125b531db03fcfbda9d6d3654bfc696b7`  
**Review policy:** `never`

## Objective

Restore valid canonical domain identity after successful side subdivision, complete exact reusable-product lookup, restore simplification and rail contracts, correct invalid Milestone D fixtures, eliminate the random-bunny returned-result crashes, and produce the next compile-only artifact without executing any binary.

This is a code changes + compile-only build turn. Compile only the four required targets.

## P5-CB67 — Validate and repair successful subdivision identity

P5-TB13 proves that the production path does not enter failed side-repair rollback. Side repair succeeds:

- infeasible cells `918 -> 0`;
- inserted vertices `8,074`;
- parity odd cells `1,860 -> 0`.

Descriptor derivation then fails on cell `2` with an invalid `SurfaceCellDomainIdentity`.

Implement a typed successful-transaction identity audit immediately after subdivision and before descriptor derivation.

For every affected cell and replacement halfedge, validate:

- nonempty closed boundary;
- valid halfedge, twin, next, from, to, and cell references;
- valid endpoint nodes;
- at least one valid source occurrence per endpoint;
- source-face barycentric finiteness and simplex bounds;
- source component and sheet consistency;
- canonical rail, curve, proposal, family, and provenance continuity;
- valid source support for the owning cell;
- deterministic oriented and undirected boundary identity.

Diagnostics must identify the first invalid:

- cell ID;
- halfedge ID;
- endpoint node ID;
- source face;
- component and sheet;
- identity subkind;
- typed failure reason.

Correct the producer, not the validator. Likely repair areas are inserted-node occurrence construction, replacement-halfedge source chart selection, or cell source-support propagation. Do not reconstruct identity from geometric proximity, local IDs, final faces, or source-triangle pairing.

Add regression sources that:

1. perform a successful coupled side repair with inserted vertices;
2. require every resulting interior cell to have a valid exact domain identity;
3. preserve rail/component/sheet/source support;
4. derive nonempty authoritative descriptors;
5. remain deterministic under source-face row and patch order.

## P5-CB68 — Add a real failed side-repair rollback regression

The current new rollback regression only exercises `subdivide_surface_cell_complex_edges` directly. It does not force a permitted failure through `repair_surface_cell_side_subdivisions`.

Add a fixture that:

- begins from a valid canonical parity-repaired complex;
- performs at least one tentative coupled insertion;
- reaches one permitted side-repair failure condition;
- returns the exact committed pre-transaction complex;
- reports `rollbackEquivalent == true`;
- reports equal before/after exact identity hashes;
- continues through the general completion backend only after that proof;
- derives valid descriptors or a truthful typed downstream failure unrelated to rollback corruption.

Keep one committed complex and one mutable transaction. Do not reintroduce two complete complexes.

## P5-CB69 — Key reusable products by semantic dependency identity

P5-TB13 still reports zero reuse because the cache lookup begins with allocation-local `descriptor.cellId`.

Replace cell-ID lookup with a deterministic semantic index using:

- arrangement-domain identity;
- canonical oriented and undirected boundary identity;
- exact rail and source support;
- component and sheet;
- logical-side counts and turns;
- completion backend and variant.

Requirements:

- use hashes only as an index;
- require exact collision-safe equality;
- support multiple entries with the same hash;
- consume or retain ownership without moving data out of unmatched products;
- reuse every genuinely unaffected patch exactly once;
- recompute every affected patch exactly once;
- record mismatch reasons for test/debug diagnostics;
- keep product-cache memory bounded and release superseded entries after commit or rejection.

The following must pass without changing expectations:

- `WholeComplexParallelRouteRepairCompletesWithinOneGlobalLedger`;
- `OneCandidateBudgetIsExactAndDoesNotRecurse`.

## P5-CB70 — Restore simplification fixed-point API semantics

P5-CB63 disabled candidate refresh for explicit candidate calls, breaking two established Phase 17 contracts.

Restore dependency-bounded candidate recomputation after every committed edit for the default API.

If a caller needs exactly one supplied transaction, add an explicit option such as `refreshCandidatesAfterCommit = false` or `maxCommittedTransactions = 1`. The default must preserve the current fixed-point behavior.

Requirements:

- recompute only candidates affected by changed nodes, strands, cells, or interfaces when possible;
- invalidate stale queued candidates deterministically;
- preserve topology, Euler characteristic, protected rails, and transaction rollback;
- keep production topology-healing mode as a live fixed point;
- avoid unbounded duplicate queue growth;
- report accurate recomputed and invalidated candidate counts.

Restore:

- `ComplexCandidateRecomputationCreatesRealQueuedCandidates`;
- `TransactionalMutationCommitsExtractedOversampledCandidate`.

## P5-CB71 — Correct Milestone D fixtures before production changes

P5-TB13 shows that three Milestone D tests do not reach their intended scenarios:

- the two-interface fixture has zero shared multi-edge interface halfedges;
- the cylinder input complex is topology-invalid before simplification.

Correct the tests, not production validation.

### Multi-edge interface fixtures

Construct a valid canonical arrangement with:

- two distinct interior cells;
- one shared interface containing at least two canonical undirected halfedges;
- valid twins and cell incidence;
- deterministic source support;
- one partial-removal case that must fail closed;
- one complete-interface transaction that may commit while preserving a separate protected rail.

Add explicit preconditions for topology validity, interface size, twin symmetry, and protected support.

### Cylindrical fixture

Construct a valid open-cylinder arrangement before simplification:

- Euler characteristic `0`;
- one connected component;
- exactly two boundary loops;
- valid embedding and incidence;
- an actual removable open strand that does not touch boundary, singularity, or protected support.

Only after the fixture is valid should production simplification behavior be changed if a real failure remains.

## P5-CB72 — Propagate authoritative rail identity to arrangement halfedges

`LiveTracingConsumesAuthoritativeBoundaryAndHardFeatureRails` shows:

- authoritative rails are present;
- rail seeds are present;
- FlowRep rail arcs are present;
- embedded arrangement arcs carry rail identity;
- final arrangement halfedges do not.

Audit arc splitting, stitching, provenance expansion, and halfedge construction.

Each halfedge derived from a rail arc must retain:

- `railId`;
- `curveId`;
- normalized `railT0` and `railT1`;
- hard/boundary rail classification;
- component and sheet;
- exact provenance entries.

When a halfedge combines multiple provenance intervals, expose a deterministic primary interval and retain the complete canonical provenance vector. Do not infer rails later from geometry.

Preserve compact rail proof after production intermediate release.

## P5-CB73 — Eliminate random-bunny returned-result lifetime crashes

Three tests terminate with signal 11 on `bunny_1k_random__surface_cells`:

- GP26 aggregate matrix;
- GP27 aggregate matrix;
- parameterized GP27 lifetime case `/7`.

Other parameterized cases pass. The benchmark executable completes and writes a fail-closed JSON record, which strongly narrows the crash to result/context ownership or destruction/readback behavior in the test path.

Add compile-time instrumentation and ownership corrections around:

- return from `remesh_from_mesh` / `remesh_from_raw_cross_field`;
- move construction and assignment of `RemeshResult`;
- destruction of mesh, field, options, and temporary pipeline state;
- access to diagnostic strings, vectors, descriptors, ownership conflicts, lineage, debug artifacts, and completion products;
- destruction of the returned result.

Requirements:

- no public result member may be a pointer, span, string view, Eigen map, or reference into temporary source/context storage;
- moved-from containers must not remain referenced;
- debug artifacts must own their payload when retention is requested;
- failure and success results must be independently destructible;
- keep every manifest case independently runnable;
- retain aggregate matrix coverage;
- do not suppress, skip, catch, or translate the access violation.

Add markers before pipeline call, after return, after input destruction, after diagnostic reads, and before result destruction so the next artifact isolates any remaining fault precisely.

## P5-CB74 — Successful-path resource and compile-only gate

After correctness changes:

- preserve `retainIntermediateGeometry = false` for production;
- retain one committed complex and at most one mutable candidate;
- retain compact semantic product-cache keys;
- release obsolete descriptors/products incrementally;
- keep deferred final output allocation;
- preserve stage-owned byte diagnostics;
- avoid optimizing by weakening diagnostics or validation.

Compile only:

- `directional_core`;
- `directional_pipeline`;
- `directional_phase1_tests`;
- `directional_benchmarks`.

Use a clean optimized static Ninja build with shallow submodules. Package exact source, empty source status, both executables, both libraries, fixture closure, logs, recursive submodule state, and checksums.

Execute no test, benchmark, custom mesh, compiled binary, help/list command, or test discovery.

## Following artifact-only gates

P5-TB14 must require:

- all eight P5-TB13 assertion failures pass;
- all three former signal-11 tests pass independently and in the full binary;
- full packaged binary completes from an arbitrary path;
- successful side subdivision produces valid domain identities and nonempty descriptors;
- failed side repair proves exact rollback equivalence;
- unaffected completion products report positive exact reuse;
- four random-bunny processes produce deterministic nonempty pure-quad output with zero ownership conflicts;
- no fallback or recovery;
- wall `<= 39.228299 s` in every process;
- peak RSS `<= 1,115,394,560 B` in every process;
- successful-path RSS is compared with P5-TB11 `936,484,864 B` and P5-TB12 early-failure `158,949,376 B`;
- process RSS is reconciled with owned-byte diagnostics.

P5 remains open until every gate passes without synthetic tests or prohibited recovery behavior.
