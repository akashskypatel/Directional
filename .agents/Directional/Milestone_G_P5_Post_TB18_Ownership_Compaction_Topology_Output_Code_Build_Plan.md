# Milestone G P5 Post-TB18 Ownership Compaction, Topology, Output, and Memory Code/Build Plan

**Authority:** P5-TB18 report and artifact `8876934846`  
**Turn type:** code changes + compile-only build  
**Review policy:** `never`

## Non-negotiable rules

1. Do not weaken topology, embedding, provenance, rail, ownership, output, or source-authority validation.
2. Do not restore frequency voting, count/order selection, positional merging, source-triangle pairing, arbitrary subset search, fixture IDs, synthetic counters, fallback/recovery output, or timeout-as-correctness.
3. Fix the earliest invalid producer. Correct a fixture only when its current construction cannot reach its stated contract.
4. This is a compile-only turn. Execute no test, benchmark, custom mesh, compiled project binary, help/list, or discovery command.
5. Compile exactly `directional_core`, `directional_pipeline`, `directional_phase1_tests`, and `directional_benchmarks`.
6. Any workflow must follow `.agents/Directional/GitHub_Workflow_Policy.md` and always upload detailed success/failure logs.

## P5-CB108 — replace expanded per-cell ownership with a compact exact registry

The current `sourceOwnershipClass.values` stores the complete union-find class
membership on every cell. This is the primary multi-gigabyte bunny regression.

Requirements:

- introduce one exact ownership-class registry per `SurfaceCellComplex`;
- store the sorted exact class membership once;
- give each cell a fixed-size deterministic class key/ordinal plus component;
- derive ordinals from sorted canonical membership signatures based on intrinsic
  source topology, not face-row or insertion order;
- retain each cell's exact incident `(component, sourceFace, localSheet)` chart
  map separately;
- include the registry and compact key in structural/rollback/domain hashes;
- make copies, moves, rollback logs, completion caches, and diagnostics account
  the registry once rather than once per cell;
- compact/intern `sourceOwnershipClass` and `sourceChartMap` dependencies before
  product-cache storage;
- preserve collision-free exact comparisons; a bare hash is insufficient.

Compile-valid regressions must establish linear ownership storage under repeated
cells and source-face row/halfedge insertion-order invariance.

## P5-CB109 — derive canonical ownership when explicit labels are absent

Topology-only and legacy calls currently produce no charts and invalidate
embedding.

Requirements:

- compute intrinsic source-face connected components from the source mesh;
- when explicit classifier labels are absent, assign each face its intrinsic
  component and a deterministic default local chart;
- stamp inserted boundary rails, nodes, occurrences, halfedges, provenance, and
  cells before canonical-class construction;
- preserve explicit classifier labels when supplied;
- keep disconnected and close/opposing sheets distinct;
- never bypass ownership validation merely because labels were omitted.

This must restore the three remaining Phase 16 regressions and the first two
Milestone D failures.

## P5-CB110 — centralize ownership canonicalization through simplification

Remove ad-hoc `{component,sheet}` fallbacks from simplification transactions.

Requirements:

- use one canonicalization utility shared by arrangement, simplification,
  parity/subdivision, and descriptor code;
- canonicalize valid legacy/manual complexes at the transaction boundary;
- require merges to share one compact canonical class;
- union only exact incident chart maps;
- preserve hard-rail lineage independently;
- include the registry and chart maps in exact rollback identity;
- restore all six Phase 17 regressions without special-casing fixtures.

## P5-CB111 — validate prepared disk boundaries before descriptor construction

Face-edge bunny reaches `InvalidArrangementDomainIdentity;firstPatch=2` without
typed evidence.

Requirements:

- add explicit domain failure kinds for repeated boundary node, repeated
  halfedge, non-simple boundary, missing chart, and registry mismatch;
- run the same ordered simple-boundary audit on every parity/side-repaired cell
  before descriptor construction;
- populate `firstInvalidDomain` on every early descriptor return;
- identify and fix the parity/subdivision producer that creates the first invalid
  prepared cell;
- preserve exact rollback and do not accept a non-simple disk.

Required next-runtime evidence: face-edge cell/patch 2 reports a concrete typed
producer or proceeds past descriptor derivation.

## P5-CB112 — finish route validation and real exact reuse

Requirements:

- resolve the unchanged `same-corner-distinct-boundary` route-validation failure
  at its route/ownership producer;
- ensure the accepted candidate has a complete deterministic affected-patch set;
- perform cache lookup before regenerated IDs;
- compare compact canonical class, exact incident chart map, boundary
  subdivision, source coordinates, rail/curve, singularity, backend/variant,
  and topology-template dependencies;
- rebind and validate cached products transactionally;
- both positive fixtures must later report genuine `reused > 0` and
  `recomputed > 0`.

## P5-CB113 — repair the invalid-midpoint fixture precondition

Requirements:

- preserve the separate missing-common-chart test;
- do not clear unrelated occurrence charts on shared nodes;
- replace only the target edge chart coordinates with finite endpoint values
  whose midpoint is non-normalizable;
- prove every earlier canonical edge remains chart-valid;
- require temporary mutation before `InvalidMidpointEmbedding`;
- retain bit-exact rollback of topology, occurrences, provenance, ownership
  registry, and chart maps.

## P5-CB114 — rebuild and validate the canonical cylinder DCEL

Requirements:

- create one intrinsic entity per source-edge or face-interior crossing;
- attach every incident face occurrence;
- stitch by exact source-edge parameter;
- remove duplicate coincident arcs and incomplete periodic rows;
- establish valid twin, next, cell, orientation, disk, Euler 0, one component,
  and two boundary loops before candidate extraction;
- preserve the intended open strand and protected rails through commit.

Do not special-case cylinders in production code.

## P5-CB115 — preserve valid completion through optimization/output

Plane, cylinder, seam, and close-sheets produce nonempty completed quad buffers
then fail with `optimization/output-validation:SelfIntersectingFace`.

Requirements:

- validate the completed mesh before optimization and retain that exact
  checkpoint when valid;
- reject invalid completion templates before optimization with a typed patch and
  local-quad identity;
- validate every accepted optimizer step for orientation, convexity,
  self-intersection, manifoldness, source support, provenance, and rail lineage;
- roll back to the last valid completed/optimized checkpoint when a step worsens
  validity;
- report completed surface cells only when the returned mesh itself is valid;
- repair `IncompleteSurfaceCellComplex` producers for torus and thin tube and
  invalid-domain producers for sphere and mechanical feature at their earliest
  stage.

## P5-CB116 — regression, memory, and compile/package gate

Add/update regressions for:

- compact exact ownership registry and linear memory scaling;
- unlabeled topology ownership derivation;
- Phase 16, Phase 17, and Milestone D closure;
- typed prepared-domain failures and valid parity output;
- both positive reuse paths;
- invalid midpoint after valid common-chart setup;
- canonical cylinder DCEL;
- optimizer rollback to valid completed output;
- random-bunny ownership capacity and stage-lifetime bounds.

Compile-only gate:

- clean Ninja Release `-O2 -DNDEBUG`, static libraries, CLI/GUI off;
- compile exactly the four required targets;
- execute no binary;
- package exact source commit, empty status, pinned recursive submodules, 26
  fixtures, source archive, configure/build logs, and recursive checksums;
- always upload a separate detailed workflow-log artifact.

## Next test-turn acceptance criteria

- Phase 14–18: all 232 or more intended tests pass;
- Milestone D: 7/7;
- all 596 or more tests terminate normally with no unexpected failure;
- both reuse fixtures report real reuse and recomputation;
- invalid midpoint and exact rollback pass;
- cylinder topology passes before simplification;
- every supported production case emits nonempty valid manifold pure quads
  without fallback/recovery;
- four face-edge and four smooth bunny runs complete deterministically;
- established wall/memory limits pass;
- simultaneous ownership explains at least 75% of the same RSS sample with the
  remainder categorized;
- ownership storage scales linearly rather than by cells × component faces.
