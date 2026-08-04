# Milestone G P5 Post-TB21 Production and Termination Code/Build Plan

**Date:** 2026-08-04  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`  
**Turn type:** code changes plus compile-only build  
**Scope:** P5-CB135 through P5-CB142

## Objective

Restore bounded deterministic termination and close the earliest remaining production producers exposed by P5-TB21 without weakening validation, adding fallbacks, synthesizing counters, or selecting by input order.

P5-TB21 authority:

- exact tested source: `247061bbaa835e5e5bf9298cc5e2c4dd25d5c74f`;
- artifact `8890167812`;
- Phase 14–18 **236/236**;
- Milestone E **23/26**;
- GP23 + GP24 **10/14**;
- Phase 20 **46/48**;
- direct production **0/8**;
- full suite does not terminate on bunny aggregate cases;
- face-edge repeated-node failure persists;
- positive reuse remains `0/0`;
- same-sample memory measurement remains unavailable.

## P5-CB135 — restore deterministic bounded termination

The new bounded alternative path is not operationally bounded on bunny aggregate cases. Three direct face-edge runs finish in 20–22 seconds, while a fourth repetition does not complete in the remaining approximately 257 seconds of a 300-second batch. Full-suite bunny aggregate cases also fail to terminate.

Implement a topology-derived operation budget, not a wall-clock timeout:

1. Canonically hash every attempted parity/T-join state from the odd-cell set, excluded interface set, affected domain identities, and replacement-cycle identity.
2. Reject repeated states before recomputation.
3. Bound work by the number of unique incident candidate interfaces of the typed failing cell, with each interface attempted at most once.
4. Cache T-join and replacement-boundary validation results by canonical state.
5. Return typed `AlternativeRepairBudgetExhausted` or `AlternativeRepairCycleDetected` evidence with attempted-state count and earliest failing entity.
6. Preserve exact rollback and the first typed domain failure.

Do not use elapsed time, arbitrary subset search, fixture IDs, or input order as correctness criteria.

Required tests:

- repeated calls use the same bounded state sequence and hash;
- face-row and insertion permutations preserve state order;
- a valid one-exclusion alternative still commits;
- exhaustion returns exact rollback.

## P5-CB136 — produce a valid repeated-node alternative

Sphere, mechanical, and face-edge bunny still reject the initial replacement cycle at a repeated boundary node.

Repair the producer rather than only rejecting it:

1. Split the affected dual repair path at the typed repeated node.
2. Derive admissible replacement arcs from canonical DCEL incidence.
3. Permit only edge-disjoint simple replacement cycles preserving protected rails, source component/sheet, parity, disk topology, and canonical domain identity.
4. Evaluate only the bounded alternatives defined by P5-CB135.
5. Commit only after incidence, domain, ownership, and rollback audits pass.

Required generalized sources must cover:

- sphere cell 2 / halfedge 37 / node 13;
- mechanical cell 2 / halfedge 719 / node 65;
- face-edge-derived cell 2 / halfedge 45 / node 20.

No fixture-specific IDs may appear in production logic.

## P5-CB137 — repair the canonical cylinder DCEL producer

`CylindricalOpenStrandCommitsWithTopologyPreserved` still reports `non-disk-cell cell=0 halfedge=43 twin=42 next=29`.

Implement:

1. Audit the successor graph before cell assignment.
2. Reconstruct each periodic interior cell from directed halfedge adjacency and twin-side ownership.
3. Separate the two boundary loops from interior disk cycles.
4. Recompute `next`, predecessor multiplicity, cell halfedge lists, signed area, boundary component count, and Euler characteristic transactionally.
5. Validate protected rail/strand continuation before commit.
6. Require invariance to seam start, face-row order, halfedge insertion order, and orientation reversal.

Do not relabel a non-disk cycle as disk; repair the incidence.

## P5-CB138 — repair invalid local completion variants

Typed failures identify four concrete producer classes:

- focused fallback: patch 0, bounded-combinatorial variant 23, `degenerate-normal`;
- cylinder: patch 10, pattern variant 25, local quad 1, `bow-tie-intersection`;
- thin tube: patch 108, bounded-combinatorial variant 21, `degenerate-normal`;
- smooth bunny: patch 9181, closed-form variant 0, `degenerate-normal`.

Implement candidate-local validity before a variant becomes authoritative:

1. Validate every generated local quad immediately after template generation.
2. Reject a candidate variant transactionally on the first typed embedding failure.
3. Enumerate only the existing bounded deterministic variant catalog.
4. Select by canonical template key and topological constraints, never input order or geometric score alone.
5. Preserve the earliest typed failure when no valid variant exists.
6. Record exact source-chart and corner-identity evidence for rejected variants.

Tests must use generalized reduced sources, not fixture-number branches.

## P5-CB139 — distinguish valid parallel routes and realize cache reuse

Semantic-only renamed duplicates reject, but the valid annular/parallel route still fails with `same-corner-distinct-boundary`, and the one-candidate budget test still reports reuse/recompute `0/0`.

Implement two independent identities:

1. semantic overlap identity: canonical embedded source-route sequence plus domain ownership;
2. stitch separation identity: canonical boundary occurrences and directed route interval sequence.

A route is a duplicate only when semantic overlap identity matches. Equal source support alone is insufficient for annular parallel routes.

After selecting one structural repair:

- invalidate only completions whose exact route/domain dependencies changed;
- retarget and validate unchanged cached completions;
- increment reuse only after successful retarget validation;
- increment recompute only after actual completion execution;
- preserve patch-order invariance.

Acceptance:

- renamed semantic duplicate rejects before candidate expansion;
- valid annular route completes;
- `reused > 0` and `recomputed > 0` derive from real operations;
- duplicate stitched output remains impossible.

## P5-CB140 — make source-sheet chart agreement global

Plane, multi-face seam, and close sheets still produce 12, 24, and 34 quads before `LocalSheetMismatch`.

Implement:

1. Build a canonical source-chart equivalence graph from source vertices, source edges, component, sheet, and incident source faces.
2. For every shared completed vertex, intersect compatible chart sets from all owning patches.
3. Choose the canonical common chart by intrinsic source entity identity, not position or face-row order.
4. Rebind barycentric coordinates only when exact source-entity equivalence is proven.
5. Fail before global quad commit when the intersection is empty.
6. Validate global shared-edge chart agreement after stitching.

Required cases:

- plane cell 4 / face 7;
- seam cell 2 / face 15;
- close-sheets cell 3 / face 13;
- close but disconnected sheets remain distinct.

No positional merging or source-triangle pairing.

## P5-CB141 — restore stage-injection and validation lineage

GP23, GP24, and Phase 20 still encounter real completion failure before intended optimization or validation checkpoints.

Do not bypass completion or reorder production stages merely to satisfy tests.

For every lineage fixture:

1. Ensure preceding-stage input is production-valid.
2. Inject the declared failure only after the declared stage is entered.
3. Preserve original failure code/stage, terminal failure code/stage, fallback cause, last valid artifacts, and debug lineage.
4. Correct invalid fixture geometry when it cannot reach the intended stage while preserving its contract.
5. Keep completion validation authoritative for real invalid output.

Acceptance:

- GP23 **6/6**;
- GP24 **8/8**;
- Phase 20 validation-lineage contracts reach the intended stage;
- no fallback or legacy execution occurs with policy `Fail`.

## P5-CB142 — torus inventory, memory sampling, and compile gate

### Torus inventory

Resolve `IncompleteSurfaceCellComplex;descriptor=22;cell=23;reason=3;attempted=41;failed=2;total=43`.

Replace numeric `reason=3` in public diagnostics with a stable typed reason name. Determine whether the descriptor is infeasible, skipped, or lacks a supported bounded template, then repair the actual producer.

### Same-sample memory measurement

Implement actual same-sample measurement:

1. Sample process working set and stage-owned bytes at the same timestamp.
2. Record sampled category total and reconciliation remainder.
3. Never sum unrelated phase maxima.
4. Expose sample availability and timestamp/sequence identity.
5. Require at least 75% categorized coverage on the same sample for established bunny cases, or report a typed gate failure.

### Compile/package gate

Compile exactly:

- `directional_core`;
- `directional_pipeline`;
- `directional_phase1_tests`;
- `directional_benchmarks`.

Use a clean Ninja Release build with shallow recursive submodules. Package exact source commit, empty status, recursive checksums, 26 fixtures, nine recursive submodule records, built target hashes, and complete configure/build/activity logs.

Execute no project binary, test, benchmark, custom mesh, help/list, or discovery command during the code/build turn.

## Runtime acceptance boundary

Compilation does not close runtime acceptance. P5-TB22 must still establish:

- terminating full suite;
- clean focused and aggregate scopes;
- production **8/8**;
- valid cylinder topology;
- valid repeated-node alternatives;
- annular route completion and real reuse;
- source-sheet-consistent global output;
- valid local variants;
- torus completion;
- bunny determinism/resource limits;
- 75% same-sample memory reconciliation.

## Preserved prohibitions

- no validator weakening;
- no frequency/count/order ownership selection;
- no fallback/recovery substitution;
- no synthetic counters;
- no positional merging or source-triangle pairing;
- no arbitrary subset search;
- no fixture/ID special cases;
- no timeout-as-correctness.
