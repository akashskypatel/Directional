# O32a source-row permutation seed Review — work preservation (IN PROGRESS)

**Canonical turn:** `M6-CP3-DEFN-P13-ROW-PERMUTATION-SEEDS` (Review/Definition). **Not an adjudication or authorization to change product source.**

## Exact authority and evidence boundary

- Verified source snapshot: GitHub Actions run `41990654900`, artifact `13397722388`, source/event SHA `4e151e5c139d09ecabca663ea1125d0544c32abb`. Artifact ZIP SHA-256 `a1abc5d44ad7a0aa53bb6b45b7c754b1ae1301438423e091e65831e046e2abeb`; extracted `source.tar.gz` and all internal `SHA256SUMS` PASS. Snapshot derived from the current branch after STATUS bootstrap and a snapshot-only trigger.
- Immediate predecessor: TB81 COMPLETE/MATCH, immutable CB91 gate 899/899 as reported in the authoritative handoff. No new gate was run in this Review.
- Continuation process correction: after the entry STATUS write, the already-verified prior-turn snapshot was locally inspected before the mandatory new-turn full policy read and explicit `READ_MODE=snapshot` selection. This is a start-order violation; further source inspection was from the reused exact snapshot, not piecemeal connector reads. No test/build source or product files were written.
- Exact turn-local tool invocation accounting was not maintained from the first invocation, so the ledger remains partial/unknown; no precise total is claimed.
- No repository product/test/fixture/selector/build edits. No local compilation or Directional runtime execution. This Review remains unfinished because the prescribed independently controlled Vase experiment is not yet reproduced.

## Source-level mechanism — concrete counterexample

`SurfaceCellTracing.cpp:5640–5658` (`initialize_seed`) de-duplicates by `(point.face, round(barycentric[0]*1e15), round(barycentric[1]*1e15), round(barycentric[2]*1e15))`, disregarding semantic vertex/rail identity. `SurfaceCellTracing.cpp:5584–5603` builds each vertex's incident face list in **source row order**; `vertex_point` at 5607–5619 chooses `.front()`. Seed construction at 10314–10427 appends rail seeds *before* vertex seeds and uses the same `seen` set. Consequently, a vertex seed at the same geometric source vertex as a rail sample may be suppressed or retained depending only on which incident source face happens to appear first.

A separate Python reconstruction of **only those source-level branches** used three incident triangles `A=(0,1,2), B=(0,2,3), C=(0,3,4)`, a rail sample at source vertex 0 in semantic face A, and an anchor at the same vertex. Four source-face orders yielded:

| Semantic face order | Rail face row | Chosen vertex chart row | Seeds | Anchor appended |
|---|---:|---:|---:|---|
| A,B,C | 0 | 0 | 1 | no |
| B,A,C | 1 | 0 | 2 | yes |
| C,B,A | 2 | 0 | 2 | yes |
| B,C,A | 2 | 0 | 2 | yes |

Sorted `(position,provenance)` SHA-256 digests differ: the one-seed case is `e110b05e3cd83cbf914aefe47f73797679b629d8c7806929d373a2f6400816cf`, the two-seed cases `3cea4a069406ce78193b7adf76966e48955c7b6b771a51b7fe9b60fbd688b6fc`. The proposed *scratch-only* change to choose the incident source face by the semantic sorted triangle-vertex tuple instead of face row selects A under all four permutations and removes this particular discrepancy. This is a logical reconstruction, **not compiled Directional proof**, and does not establish a sufficient production fix.

## Continuation probe: actual Vase boundary incidence (2026-11-05, scratch only)

A separate, directly executable Python scratch probe (`vase_boundary_seed_probe.py` + JSON report) parsed the immutable `benchmarks/fixtures/milestone-g/vase.off` from the verified source snapshot: **1,274 vertices, 2,404 triangles, 142 boundary edges, 142 distinct boundary vertices**. It reconstructed only the existing `initialize_seed` key, an endpoint sample on each boundary edge, and the `vertex_point`/anchor insertion. This synthetic choice of anchor set (all boundary vertices) is **not the actual production relief-root/anchor set**; the full Vase-generated field, authoritative rails, graph-distance and adaptive seeding were not executed. The seed counts below are *not* the RA-205 production numbers.

| Consistent source-face row order | Rail-endpoint seeds | Additional boundary-vertex anchors (existing first-row chart) | Total | Candidate using lowest semantic triangle face | Candidate content digest |
|---|---:|---:|---:|---:|---|
| Base | 284 | 40 | 324 | 286 | `b8f01d28b128c0b92d6c6914338dfd8d2feea69c453f2146e06fd0b5036d6778` |
| Permutation 1 | 284 | 53 | 337 | 286 | same |
| Permutation 2 | 284 | 41 | 325 | 286 | same |
| Permutation 3 | 284 | 39 | 323 | 286 | same |
| Permutation 4 | 284 | 50 | 334 | 286 | same |

The original form produced **five distinct** semantic `(sourceVertex, seedProvenance)` SHA-256 digests. The candidate form produced one digest, and scratch assertions verify both discrimination and invariance. This is direct evidence that the observed algorithm can change **before adaptive coverage** on the real Vase topology, not proof that it does so with production options. It is a stricter, real-mesh corroboration of the earlier three-triangle counterexample, and it identifies `vertex_point` plus face-local dedup as a plausible shared first owner. It does not localize the *actual* RA-205 1,456→1,461 count change.

**Safety caveat:** the modeled 284 boundary-endpoint seeds project to only 142 distinct source vertices; a world-position/source-vertex-only dedup would erase chart/rail representations, not repair them. `initialize_seed` also discards the second `HardRailId` if two distinct authoritative rail samples share one face/barycentric key. Neither a universal position dedup nor global lexical-face replacement is authorized without independently proving the correct component, local-sheet, and protected rail-side scope. A candidate may choose a source-row-independent representative *within* its authoritative fan/side class, and must preserve both sides of hard features.

**Next decisive controlled experiment:** instrument the actual scratch Vase producer to emit per-phase row-invariant content digests and seed count (authoritative rail samples; singularity/relief roots; optional anchors/separatrices; coverage) across base and ≥3 consistent face-row permutations. Include canonical source-entity/rail-side key and logged reason for insertion or suppression. If the first difference occurs before coverage, test a semantic fan-aware representative there. If the prefix is identical and coverage diverges, test Dijkstra/face-corner equivalence and centroid placement, not rail dedup. Then repeat actual tracing and strand counts. No C++ scratch build or product runtime has been performed in this continuation.

## Hypothesis and checks before freezing a Code + Build successor

1. Reproduce the RA-205 Vase base + at least three source-face row permutations on a **separate scratch artifact**, keeping field/rails/geometry/target size fixed and remapping all face-indexed inputs. Count and digest the produced seeds after each insertion phase, not just at exit.
2. Isolate the earliest differing phase: authoritative rail samples; singularity/relief/anchor vertex points; or adaptive farthest coverage. Log the canonical source vertex/edge/face identity and rail side/fan, original and new face rows, and exact `seen` suppression reason. Do not infer the Vase cause from the focused counterexample.
3. For `vertex_point`, try a source-row-independent canonical face selection in scratch while preserving sheet, component, protected hard-rail-side ownership and source-chart provenance. Avoid a global world-position deduplication: different local sheets and hard-rail sides may intentionally share positions. Do not change the refuted `AdaptiveSeedCandidate` tie as the proposed primary remedy.
4. Require **seed count and row-invariant sorted position+provenance digest equality under >=3 permutations**, including the original, together with a negative hard-rail-side/same-position-different-sheet guard. Verify the change truly alters the failing precondition; no vacuous check.
5. Only when the true earliest owner is established, freeze one minimal bounded Code + Build successor and a separate immutable Test + Benchmark gate with explicit predictions/falsifiers. Then remeasure tracing and strands to assign O32b/c. Carry O30b, O31, O32d/e, O33, P13-l/e, O27–O29, DR1/DR3 without claiming closure.

This does not change the RA-205 measured 1,456 vs 1,461 Vase observation, 66/17/49 stable accounting, CP2 491/491 accepted, or the unpromoted selector497/CP3 boundary.

## Continuation 3: production-ingress reachability and upstream control gap (2026-11-05)

**Independent source inspection:** the production path at `src/pipeline/RemeshPipeline.cpp:12804–12816` fills `authoritativeRails`, `reliefRootVertices` (from `select_relief_roots`), and `reliefRegionLabels`; later it supplies source labels and field-network authority. It does **not** populate `anchors` or `reliefCriticalVertices` in this path. The previous all-boundary-`Anchor` experiment therefore established a property of a supported entry path, **not direct reachability in the current Vase production path**. The production-reachable analogue to investigate is `ReliefCritical` insertion through `reliefRootVertices`, plus field-network singularities and authoritative rails. This correction supersedes any inference that the anchor-only experiment established the production root cause.

**New controlled scratch probe:** `production_ingress_reachability_probe.py` uses the verified, actual `vase.off` topology but deliberately supplies a *model*, row-invariant relief-root set (every seventh boundary vertex). It models only boundary endpoint rail keys and the production-reachable root insertion path, not `select_relief_roots` itself. Across base + four fixed face-row permutations, the existing first-incident-row representative admitted **8, 9, 8, 5, 6** such model roots; a minimum-semantic-triangle representative admitted **0, 0, 0, 0, 0** in this limited model. The test explicitly asserts that the original diverges and its limited candidate does not. Neither series is the RA-205 **1,456/1,461** production seed count, and zero added modeled roots is *not* a specification of correct production root admission.

**Do not over-attribute to the seed function yet.** RA-205 §3 establishes equal *counts* through `global-conformity-baseline` and a changed seed digest; it does not establish permutation-invariant *semantic contents* of the authoritative rails, root list, region labels, per-vertex target size, source-chart/fan assignments, or field-network singularity list. That leaves a possible upstream-content cause. A production-equivalent experiment must compare those values by canonical source entity rather than using raw face-row-containing structural hashes. Freeze/remap identical semantic upstream inputs when isolating only the seed producer. If upstream content differs, stop and name the earliest owner there instead of using seed deduplication to mask it.

**Negative safety guard:** `SourceChartTransitions.h:690–850` constructs intrinsic vertex fans using source-edge adjacency excluding protected hard-feature edges. Two face charts separated by a protected hard edge can share source vertex 0 and world position while belonging to distinct admissible fans. An unconditional key of source vertex or world position merges distinct topological authorities. Reuse the existing fan/typed-source-identity infrastructure instead of inventing a parallel identity layer. A minimum-semantic-face representative is only a *candidate within an already-authorized fan and rail side*, not a global choice across all incident faces. The current `seen` key also ignores hard-rail identity when two samples share the same chart/barycentric key; preserve named mandatory rail ownership independently from ordinary source-position de-duplication.

**Immutable census cross-check:** the archived TB81 result artifact `13397310703` was independently re-downloaded and its ZIP SHA-256 verified as `ff4a82c31abe97c8ab214182b847652c3c663ee77f9a708ae0c2e63fe2b412c6`; all 9 packaged checksums passed. The result contains outcome logs/ledger and no emitted seed membership or per-phase insertion inventory. It cannot establish the cause without a scratch producer probe; no runtime gate was re-run.

**Next required discriminating scratch proof (still pending):** compare the actual production Vase `authoritativeRails`, `reliefRootVertices`, `reliefRegionLabels`, target size, source labels and field-network singularities under base and >=3 consistent permutations. At the identical semantic-input boundary, inventory `seen` accept/reject decisions separately for authoritative rail samples, singularity vertices, relief roots, region representatives and adaptive coverage; compare seed count and sorted semantic 3D-position+provenance digest at each phase. Classify the *first* mismatch and falsify the smallest fan-aware correction there. Only then remeasure tracing/strands and freeze an exact CB→TB successor. Review source/test/fixture/selector boundaries remain unchanged. This is **still IN PROGRESS**, not a completed DEFN.

## Continuation / closeout pending

The mandated *actual producer* scratch production-equivalent evidence, full formal Review closeout table, review boundary check on a Git-backed working tree, document consolidation, durable `ORIENTATION.md`/`CHANGELOG.md`/tracker refresh, and formal successor freeze are **not completed**. Keep this canonical turn active; do not start its successor. The source snapshot can be reused locally for the unchanged source phase.