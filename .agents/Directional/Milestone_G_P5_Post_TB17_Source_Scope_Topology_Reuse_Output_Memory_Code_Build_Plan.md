# Milestone G P5 Post-TB17 Source-Scope, Topology, Reuse, Output, and Memory Code/Build Plan

**Authority:** P5-TB17 report and artifact `8875627676`  
**Turn type:** code changes + compile-only build  
**Review policy:** `never`

## Non-negotiable rules

1. Do not weaken any topology, embedding, provenance, rail, output, or source-authority validator.
2. Do not restore the removed frequency-vote scope heuristic or select a sheet by count/order.
3. Do not merge by position, pair source triangles, search arbitrary subsets, special-case fixture IDs, synthesize reuse/memory counters, or substitute fallback/recovery output.
4. Fix the earliest invalid producer. A test fixture may change only when its current construction cannot reach the contract it claims to test.
5. This is a compile-only turn. Execute no test, benchmark, custom mesh, compiled binary, help/list, or discovery command.
6. Compile exactly `directional_core`, `directional_pipeline`, `directional_phase1_tests`, and `directional_benchmarks`.
7. Any GitHub workflow used must follow `.agents/Directional/GitHub_Workflow_Policy.md` and always upload detailed logs on success or failure.

## P5-CB99 — correct the cell ownership model across local sheet charts

The P5-CB91 arrangement change requires one raw `(component, localSheetByFace)` pair to occur on every oriented boundary edge. This is incompatible with the established tracing contract: a valid topological trace may cross adjacent local sheet-chart boundaries through source adjacency while remaining in one connected component.

Implement an authoritative cell ownership representation that distinguishes:

- connected source component identity;
- a canonical cell-side/sheet equivalence class;
- the per-source-face local sheet chart used by each oriented halfedge and node occurrence.

Requirements:

- derive the canonical cell-side class from source adjacency and oriented DCEL incidence, not frequency voting;
- permit a cell to span adjacent local sheet chart IDs that are proven connected through the cell interior;
- reject close/opposing physical sheets that lack that intrinsic adjacency proof;
- preserve each oriented halfedge's exact source-face chart;
- preserve rail lineage independently when a rail record originates from the opposite incident chart;
- persist the canonical ownership class before simplification or parity repair;
- make cell structural hashes include the canonical class and the complete deterministic per-face chart map.

Direct regressions must include:

- a single disk spanning adjacent local sheet charts;
- disconnected source components;
- connected close/opposing sheets that must remain distinct;
- a hard rail whose stored provenance chart is opposite the incident cell chart;
- source-face row and halfedge insertion-order invariance.

This task must restore the four Phase 16 and two Milestone D regressions without reducing validation coverage.

## P5-CB100 — propagate canonical ownership through simplification

Every simplification transaction must preserve the canonical cell-side class and per-face chart map.

Requirements:

- candidate extraction compares canonical ownership classes, not raw local sheet integers;
- a merge is valid only when all source cells belong to one compatible canonical class;
- rebuilt halfedges, twins, nodes, occurrences, provenance, and cells retain exact oriented chart records;
- optional bridge healing and strip removal preserve incidence, embedding, orientation, disk cells, Euler characteristic, and protected rails;
- rejected transactions roll back bit-exactly, including ownership class and chart-map hashes.

Restore all six Phase 17 regressions before any production-output work continues.

## P5-CB101 — make parity preflight consume committed canonical ownership

Replace the current raw scope intersection in `SurfaceCellFeasibilityRepair` with validation against the committed canonical ownership class.

Requirements:

- accept boundary records on different local chart IDs only when each maps to the same canonical cell-side class;
- reject a boundary record from another component or unconnected physical sheet before mutation;
- keep typed first-invalid evidence, adding canonical class, source face, local chart, and failed equivalence edge;
- stamp replacement cells, halfedges, twins, node occurrences, and provenance before post-mutation validation;
- preserve exact rollback identity;
- retain the direct multi-scope fail-closed test for genuinely incompatible sheets.

Required runtime target for the next test turn:

- face-edge cell 19 and smooth-field cell 45 resolve a valid canonical class instead of selected scope `-1/-1`;
- neither benchmark stops at `BoundaryParityRepair:MixedCellSourceScope`.

## P5-CB102 — repair exact completion reuse and route validation

Two guaranteed reuse tests still observe zero reuse.

Requirements:

- diagnose why the one-candidate transaction records zero incremental recomputation and never reaches cache lookup;
- ensure the accepted candidate's affected-patch set is complete and deterministic;
- resolve the `same-corner-distinct-boundary` route-validation failure at the responsible ownership/route producer;
- perform cache lookup before regenerated IDs are assigned;
- compare canonical source-domain, boundary subdivision, source coordinates, rail/curve, singularity, backend/variant, and topology-template dependencies;
- rebind and revalidate cached products transactionally;
- record a field-level mismatch only for a real dependency difference;
- both positive fixtures must report `reused > 0` and `recomputed > 0` without synthetic counters.

## P5-CB103 — reach the intended invalid-midpoint contract

The invalid-midpoint fixture still fails at `MissingCommonSourceChart`.

Inspect the fixture and subdivision chart resolver together.

Requirements:

- preserve the separate missing-chart test;
- provide explicit compatible endpoint occurrences for the exact oriented edge scope and source faces consumed by the resolver;
- use finite endpoint barycentrics whose midpoint is non-normalizable only after temporary subdivision state exists;
- prove the precondition has one valid common source chart before mutation;
- require `InvalidMidpointEmbedding` after mutation begins;
- require bit-exact rollback of counts, occurrence/provenance records, structural hash, and ownership class.

If the current fixture is structurally incapable of that sequence, correct the fixture rather than weakening the resolver.

## P5-CB104 — rebuild the canonical cylinder DCEL fixture

The revised cylinder fixture fails incidence validation before candidate extraction.

Requirements:

- create one canonical intrinsic entity per source-edge or face-interior crossing;
- include all incident source-face occurrences on that entity;
- stitch chart-local segments by exact source-edge parameter;
- avoid duplicate coincident arcs and avoid leaving an incomplete periodic grid;
- create valid twin, next, cell, and orientation relationships for the complete open cylinder;
- assert incidence, embedding, orientation, disk cells, Euler characteristic 0, one connected component, and two boundary loops before candidate extraction;
- ensure the intended open strand exists and can commit while preserving topology.

Do not special-case the cylinder in production code.

## P5-CB105 — repair production output at the earliest invalid producer

After ownership and topology are restored, capture the earliest invalid stage/entity for plane, cylinder, multi-face seam, torus, mechanical feature, close sheets, prescribed sphere, thin bent tube, and bunny.

Requirements:

- distinguish completion failure from optimizer-created invalidity;
- preserve component, canonical sheet class, per-face chart, source-face support, provenance, rail, and boundary lineage;
- reject degenerate, inverted, self-overlapping, and non-convex templates before optimization;
- ensure optimizer rollback returns the completed valid surface-cell mesh when optimization worsens validity;
- never report completed surface cells when the completed mesh itself is invalid;
- output must be nonempty, manifold, source-valid, and pure quad without fallback/recovery.

## P5-CB106 — reconcile stage ownership with peak RSS

TB17 reports deterministic timelines but only 28.0–33.6% peak-RSS coverage.

Extend accounting to include:

- Eigen matrix/vector allocated capacity and alignment overhead;
- associative node/bucket allocation overhead;
- nested provenance and occurrence vector capacities;
- retained source mesh, cross field, feature, metric, relief, and diagnostics products;
- FlowRep selection and endpoint maps/queues;
- simplification queues, transaction copies, rollback logs, and allocator-retained capacity;
- completed-patch caches, ownership inventories, assembly buffers, and output validation copies;
- benchmark JSON/result serialization and review-image buffers when live concurrently.

Requirements:

- report logical payload, allocated/retained capacity, stage peak, and simultaneous ownership separately;
- use an acquire/release timeline covering every dominant owner;
- a release flag may be true only when retained capacity is zero or the retained bytes are explicitly reported;
- calculate reconciliation against the same RSS sample used by the benchmark;
- next runtime gate: estimated simultaneous ownership explains at least 75% of peak RSS, with remaining bytes categorized rather than silently unexplained.

## P5-CB107 — regression source and compile/package gate

Add or update regressions for every corrected contract:

- canonical ownership across adjacent local charts;
- physical close-sheet separation;
- Phase 16 and Phase 17 topology closure;
- parity preflight compatibility and fail-closed incompatibility;
- both positive reuse paths;
- invalid midpoint after valid common-chart precondition;
- valid canonical cylinder DCEL;
- first-invalid production output evidence;
- complete memory ownership timeline and reconciliation.

Compile-only gate:

- clean configure with Ninja, Release `-O2 -DNDEBUG`, static libraries, CLI/GUI off;
- compile exactly the four required targets;
- execute no binary;
- package exact source commit, empty source status, pinned submodule status, binaries/libraries, 26-fixture closure, source archive, configure/build logs, and recursive checksums;
- upload a separate detailed workflow log artifact under `if: always()`.

## Next test-turn acceptance criteria

The subsequent artifact-only test/benchmark turn must require:

- Phase 14–18 returns to 230/230 or higher with all intended new tests passing;
- Milestone D returns to 7/7;
- all 22 TB17 failures pass for their intended reasons;
- both reuse fixtures report positive real reuse;
- invalid midpoint and exact rollback pass;
- cylinder topology and production output pass;
- complete suite has no unexpected failure or abnormal termination;
- four face-edge and four smooth runs are deterministic and produce nonempty valid pure-quad output;
- no fallback or source-grid recovery;
- wall/memory limits pass;
- peak-RSS reconciliation reaches the quantitative gate.
