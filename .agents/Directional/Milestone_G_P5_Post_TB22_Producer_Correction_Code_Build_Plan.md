# Milestone G P5 Post-TB22 Producer-Correction Code/Build Plan

**Date:** 2026-08-04  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`  
**Turn type:** code changes plus compile-only build  
**Scope:** P5-CB143 through P5-CB150

## Objective

Retain the deterministic bounded termination established by P5-TB22 while repairing the actual topology, completion, ownership, chart, lineage, torus, and memory producers. Do not add more rotations/reversals or more single-interface exclusions when those finite catalogs are already proven exhausted.

P5-TB22 authority:

- exact tested source `aa2917e280fabd2272911a39cd0ecc327cce1cf3`;
- artifact `8894034755`;
- full suite terminates: **585/600** in 103.441 s;
- production **0/8**;
- face-edge alternatives deterministically exhaust 14/14 states;
- sphere exhausts 68/68 and mechanical exhausts 104/104;
- reuse/recompute remains `0/0`;
- same-sample coverage is 0% while availability is incorrectly true.

## P5-CB143 — topology-distinct repeated-node splice producer

The single-excluded-interface frontier is bounded and deterministic but cannot create a valid replacement cycle.

Implement a canonical repeated-node wedge decomposition:

1. Identify the two visits to the typed repeated node in the proposed replacement walk.
2. Partition incident directed halfedges into intrinsic DCEL wedges using cyclic source-face incidence, component, sheet, and protected-rail barriers.
3. Construct the finite topology-derived pairings that exchange the two repeated-node continuations across distinct admissible wedges.
4. Emit only edge-disjoint simple cycles whose combined boundary equals the original affected domain boundary modulo the selected internal splice.
5. Validate parity, disk topology, source ownership, protected rails, and exact rollback transactionally.
6. Hash each splice by directed halfedge intervals and wedge identities; visit each once.

This is not arbitrary subset search. The candidate set is the canonical local pairing set at the typed repeated node.

Acceptance:

- at least one generalized sphere/mechanical/face-edge reduced source commits a valid bounded alternative;
- all-invalid cases retain deterministic typed exhaustion;
- face-row, insertion-order, seam-start, and orientation permutations preserve candidate hashes;
- the four-run face-edge termination behavior does not regress.

## P5-CB144 — reconstruct periodic cylinder cells from directed incidence

The occurrence-split heuristic leaves `non-disk-cell cell=0 halfedge=43 twin=42 next=29`.

Replace it with a transaction that:

1. Builds directed successor/predecessor multiplicities from embedded halfedges and twins.
2. Separates periodic exterior boundary loops from bounded interior cycles before assigning cell IDs.
3. Walks every unassigned directed halfedge exactly once into a simple cycle.
4. Rejects any cycle with repeated nodes, repeated edges, invalid predecessor multiplicity, or inconsistent twin-side ownership.
5. Assigns cells only after the complete cycle inventory passes disk/Euler/orientation checks.
6. Preserves protected rail and strand continuation.

Acceptance requires the cylinder closure test and its seam/order/orientation permutations to pass without relabeling invalid topology.

## P5-CB145 — topology-distinct local completion templates

Rotating and reversing the same templates only moves the terminal failure to variants 47, 51, and 43.

Implement topology-distinct candidates derived from the descriptor equations:

1. Classify the first invalid quad by collapsed source support, crossing diagonals, or repeated projected position.
2. For pattern and bounded-combinatorial backends, enumerate the finite diagonal/strip connectivity choices admitted by side subdivisions and singularity placement—not cyclic reorderings of one connectivity.
3. For generated vertices, derive distinct source-supported barycentric locations from the patch chart; do not reuse coincident points with reversed winding.
4. Validate each candidate immediately for finite positions, nonzero normals/area, no bow-tie, disk topology, and boundary preservation.
5. Preserve the first typed failure if no topology-distinct candidate succeeds.

Required reduced sources cover focused variant 47, cylinder variant 51, thin-tube variant 43, and smooth patch 9181.

## P5-CB146 — route separation and real cache reuse

The valid annular route still collides as `same-corner-distinct-boundary`, while semantic duplicate rejection remains correct.

Implement:

1. Semantic-overlap identity from canonical source-route intervals and domain ownership.
2. Stitch-separation identity from ordered boundary occurrences, directed route intervals, and side-of-route ownership.
3. Global vertex keys that retain stitch-separation identity for equal source support on distinct annular routes.
4. Exact dependency invalidation after one route repair.
5. Retarget validation of unaffected completions before counting reuse.
6. Actual completion execution before counting recomputation.

Acceptance:

- semantic aliases still reject before candidate expansion;
- valid annular and whole-complex parallel routes complete;
- no duplicate stitched quad;
- `reused > 0`, `recomputed > 0`, and one incremental pass derive from real work;
- patch and route order permutations preserve results.

## P5-CB147 — source-entity chart transitions, not literal face intersection

Plane, seam, and close sheets retain the exact same `LocalSheetMismatch` locations. Intersecting literal source-face sets is insufficient when equivalent vertex/edge support is represented in adjacent charts.

Implement a source-chart transition graph:

1. Nodes are `(component, sheet, source face)` charts.
2. Edges are exact shared source-vertex or source-edge incidences with orientation-aware barycentric transition maps.
3. For each stitched output vertex/edge, resolve all owning provenance through this graph to a canonical intrinsic source entity.
4. Choose a canonical representative chart only after proving transition consistency around the complete ownership set.
5. Rebind barycentrics through exact vertex/edge transition maps.
6. Keep disconnected close sheets in separate graph components.
7. Fail before committing global quads when transitions conflict.

Do not use position or source-triangle pairing as identity.

Acceptance requires plane, seam, close-sheets, and disconnected-close-sheets production and permutation contracts.

## P5-CB148 — production-valid stage-lineage fixtures

GP23 optimization and GP24/Phase20 validation injections still never reach their declared stages.

For each fixture:

1. Diagnose the real preceding completion failure.
2. Correct fixture geometry/provenance when it cannot produce valid completion while preserving the intended lineage contract.
3. Prefer an existing production-valid reduced completion source as the shared fixture basis.
4. Inject only after the declared stage is entered.
5. Preserve original/terminal code and stage, fallback cause, last-valid artifacts, debug lineage, and policy `Fail` behavior.

Do not bypass completion or reorder stages.

Acceptance: GP23 **6/6**, GP24 **8/8**, and Phase20 validation-lineage tests clean.

## P5-CB149 — support the torus descriptor or repair its decomposition

Torus now reports a stable typed reason:

`IncompleteSurfaceCellComplex;descriptor=22;cell=23;reason=side-count-unsupported;reasonCode=3;attempted=41;failed=2;total=43`

Determine the descriptor side count and topology from runtime-independent reduced construction.

- When the cell is a valid disk with an even boundary, add a bounded descriptor/template supported by the general side equations.
- When the cell should be decomposed, repair the arrangement or parity producer before descriptor authority.
- When genuinely infeasible, prove the infeasibility with a generalized negative test; the supported production torus must still complete.

No fixture-specific descriptor or cell ID branches.

## P5-CB150 — sample memory while categories are live

Current telemetry sets availability true at a sample with zero categorized bytes.

Implement synchronized sampling at ownership transitions:

1. At every memory-ownership acquire/release event, obtain process working set and current categorized owned bytes in the same callback.
2. Store sequence/timestamp, working set, categorized total, category breakdown, and reconciliation remainder atomically.
3. Retain the sample with maximum categorized coverage, with deterministic tie-breaking by sequence.
4. Set availability false when working set is zero, categorized total is zero, or the sample cannot be synchronized.
5. Never substitute phase maxima or a post-release sample.
6. Report a typed coverage-gate failure below 75%.

Add tests proving nonzero synchronized ownership, correct release behavior, and no false availability.

## Compile/package gate

Compile exactly:

- `directional_core`;
- `directional_pipeline`;
- `directional_phase1_tests`;
- `directional_benchmarks`.

Use a clean Ninja Release build with shallow recursive submodules. Package exact source commit, empty status, recursive checksums, 26 fixtures, nine recursive submodule records, built target hashes, and complete configure/build/activity logs.

Execute no project binary, test, benchmark, custom mesh, help/list, or discovery command during the code/build turn.

## Runtime acceptance boundary

Compilation does not close runtime acceptance. P5-TB23 must establish:

- clean terminating full suite;
- production **8/8**;
- a committed repeated-node alternative;
- valid cylinder incidence;
- topology-distinct valid local completions;
- valid annular route and real reuse/recompute;
- global source-chart agreement;
- correct later-stage lineage;
- torus completion;
- bunny valid-output determinism and resource limits;
- truthful nonzero same-sample coverage of at least 75%.
