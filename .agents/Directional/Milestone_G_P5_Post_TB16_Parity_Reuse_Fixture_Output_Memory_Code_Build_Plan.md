# Milestone G P5 — Post-TB16 Parity, Reuse, Fixture, Output, and Memory Code + Build Plan

**Next turn:** P5-CB91 through P5-CB98 code changes + compile-only build  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Authority

Read first:

1. `.agents/Directional/Milestone_G_P5_TB16_FlowRep_Parity_Reuse_Rail_Output_Memory_Test_Benchmark_Report.md`;
2. `benchmark-results/p5-tb16-summary.json`;
3. `TODO`;
4. `MILESTONE_G_TODO.md`;
5. `.agents/Directional/Future_Chat_Session_Handoff.md`.

P5-TB16 closed the high-cardinality FlowRep signal-11 fault and the focused final-rail propagation gate. It did not close parity scope, exact reuse, the invalid-midpoint fixture, the cylinder simplification fixture, production outputs, or full memory reconciliation.

## Prohibitions

Do not:

- weaken topology, source-lineage, manifold, orientation, or pure-quad validation;
- convert failed direct `SurfaceCells` output into fallback or recovery success;
- deduplicate final faces by position or unordered vertex set;
- pair source triangles into output quads;
- add fixture-, case-, face-, edge-, or ID-specific production branches;
- synthetically increment reuse or memory counters;
- suppress failing production cases;
- use arbitrary subset search or timeout as a correctness mechanism;
- execute tests, benchmarks, custom meshes, help/list commands, or discovery commands during the code/build turn.

## P5-CB91 — Authoritative parity scope and typed failure proof

The runtime still reports `BoundaryParityRepair:MixedCellSourceScope` on both bunny field paths after odd cells reach zero inside the rejected transaction.

Required work:

1. Derive the replacement scope from the exact pre-transaction cell ownership record, not from post-mutation boundary voting.
2. Fail before mutation when a source cell itself has no single authoritative component/sheet scope.
3. Stamp every new cell, oriented halfedge, twin, node occurrence, and provenance record with the inherited scope before validation.
4. Preserve source face identity independently from component/sheet scope.
5. Add typed diagnostics containing:
   - original cell;
   - replacement cell;
   - halfedge and twin;
   - selected component/sheet;
   - available provenance scopes;
   - mutation phase.
6. Require exact rollback when any replacement record cannot accept the inherited scope.
7. Add a direct regression that reproduces a multi-scope boundary but has one authoritative pre-transaction cell scope and proves successful commit.

## P5-CB92 — Exact reusable-product dependency identity

Both positive reuse regressions remain at zero.

Required work:

1. Record a field-level mismatch vector for every cache miss:
   - authoritative source-domain identity;
   - canonical side subdivision;
   - boundary source coordinates;
   - rail/curve support;
   - singularity requirements;
   - completion backend and variant;
   - topology template.
2. Remove allocation-local cell IDs, transient arrangement indices, regenerated positions, and order-sensitive derived lists from the reusable identity.
3. Canonicalize cyclic and reversed boundary dependencies without discarding orientation-sensitive source intervals.
4. Perform cache lookup before assigning regenerated cell-local identifiers.
5. Verify reused completed products are rebound transactionally to the new arrangement and revalidated before commit.
6. Require both existing positive regressions to observe `reused > 0` and preserve bit-exact output identity.

## P5-CB93 — Valid invalid-midpoint transaction fixture

The current fixture still reaches `MissingCommonSourceChart`.

Required work:

1. Keep `SubdivisionWithoutCommonSourceChartFailsBeforeMutation` unchanged as the missing-chart contract.
2. Populate both endpoint nodes with explicit compatible `SurfacePointOccurrence` records for the same face, component, and sheet.
3. Use finite occurrence barycentrics whose interpolated midpoint cannot normalize.
4. Ensure an earlier requested split mutates temporary state before the invalid midpoint is encountered.
5. Require:
   - `InvalidMidpointEmbedding`;
   - exact rollback identity hash;
   - original node, halfedge, cell, occurrence, and provenance counts.

Do not bypass the occurrence-based common-chart lookup by assigning only node-level convenience fields.

## P5-CB94 — Topology-valid cylindrical simplification fixture

The cylinder fixture still fails initial incidence validation.

Required work:

1. Build one canonical intrinsic entity per source edge or crossing segment.
2. Attach all incident source-face provenance to that entity rather than creating coincident per-face duplicates.
3. Canonically stitch crossings at source edges by source-edge parameter and incident face identity.
4. Before candidate extraction, assert:
   - twin symmetry;
   - valid incidence;
   - valid embedding and orientation;
   - disk cells;
   - Euler characteristic `0`;
   - one connected component;
   - two boundary loops.
5. Only then identify and commit the intended open-strip candidate.
6. Add diagnostics identifying the first invalid node/halfedge/cell if fixture construction regresses.

## P5-CB95 — Earliest-invalid production producer repair

The remaining output failures are:

- plane and multi-face seam: strict validation;
- cylinder: strict validation and Phase 20 production output;
- torus and mechanical feature: completion;
- additional GP27 production-matrix cases reported unsuccessful output.

Required work:

1. Capture the earliest invalid stage and first invalid entity for every failing case.
2. Repair the producer at that stage; do not defer invalid topology to optimization.
3. Preserve component, sheet, source face, oriented provenance, rail, and boundary identity through completion and assembly.
4. Reject degenerate or nonconvex completion templates before output assembly.
5. Ensure output contains only nondegenerate pure quads with valid source-lineage and manifold incidence.
6. Keep every existing strict validator active.

## P5-CB96 — Stage-memory reconciliation

P5-TB16 telemetry is populated but current stage-owned sums explain only 32.65% of face-edge RSS and 42.70% of smooth-field RSS.

Required work:

1. Account for:
   - Eigen matrix/vector allocated storage;
   - nested associative-container nodes and bucket arrays;
   - retained diagnostics and lineage payloads;
   - node occurrences and provenance nested capacities;
   - endpoint queues, maps, and connector candidates;
   - allocator capacity retained after `clear`;
   - overlapping stage lifetimes.
2. Separate:
   - current logical payload;
   - retained allocator capacity;
   - stage peak;
   - simultaneous live ownership.
3. Record a timeline of large-structure acquire/release events.
4. Ensure release flags correspond to zero retained capacity or explicitly report retained capacity.
5. Avoid summing mutually exclusive peaks as if simultaneous.
6. Add a reconciliation field comparing estimated simultaneous owned bytes with process peak RSS.

## P5-CB97 — Regression sources and invariant strengthening

Add or correct regression sources for:

- authoritative parity-scope commit and typed failure;
- positive exact reuse and mismatch-vector diagnostics;
- explicit occurrence-based invalid midpoint rollback;
- topology-valid cylinder construction and open-strip commit;
- each repaired production-output category;
- memory acquire/release timeline and reconciliation;
- preservation of the already passing FlowRep reallocation and final-rail gates.

Every test must exercise its named contract. Fix invalid inputs rather than weakening production code.

## P5-CB98 — Compile and package gate

Compile only:

- `directional_core`;
- `directional_pipeline`;
- `directional_phase1_tests`;
- `directional_benchmarks`.

Package:

- exact source commit and empty source status;
- test and benchmark binaries;
- static core and pipeline libraries;
- complete executable-relative fixture closure;
- source archive and recursive submodule status;
- configure/build logs;
- checksum manifest.

Execute no compiled binary, test, benchmark, custom mesh, help/list command, or discovery command.

## Subsequent test-turn gates

The subsequent artifact-only turn must require:

1. all current ten assertion failures pass;
2. all 593 or more tests terminate with zero failures;
3. four face-edge and four smooth-field bunny processes produce deterministic valid nonempty pure-quad output;
4. positive exact reuse occurs;
5. parity repair commits without mixed-scope fallback;
6. invalid-midpoint and cylinder fixtures reach their intended scenarios;
7. every process remains within `39.228299 s` and `1,115,394,560 B`;
8. simultaneous owned-byte telemetry materially reconciles process RSS;
9. no fallback or source-grid recovery is used.

P5 remains open until every correctness, output, determinism, timing, and memory gate passes.
