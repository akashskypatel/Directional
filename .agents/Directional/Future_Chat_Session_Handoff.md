# Directional Surface-Cell Quadrangulation — Session Handoff

**Updated:** 2026-08-03  
**Repository:** `akashskypatel/Directional`  
**Base:** `surface_cell_quad`  
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Current checkpoint

P5-TB18 artifact-only runtime validation is complete. P5 remains open.

Tested checkpoint:

- source `94bf8347b10eebcd8d3e777c6f5f0a2227283a2e`;
- artifact `8876934846`;
- SHA-256 `ba06737ab313f30e23c74f402114649ee2c9f9d7c3a7177c7e0ba3328749df47`;
- empty source status;
- checksums **39/39**;
- fixture files **26**.

No configure, build, relink, patch, regeneration, or source modification
occurred during P5-TB18.

The next turn is **P5-CB108 through P5-CB116 code changes + compile-only
build**. Execute no test, benchmark, custom mesh, compiled binary, help/list, or
discovery command in that turn.

## Read first

1. `TODO`
2. `MILESTONE_G_TODO.md`
3. `.agents/Directional/Milestone_G_P5_TB18_Canonical_Ownership_Output_Memory_Test_Benchmark_Report.md`
4. `benchmark-results/p5-tb18-summary.json`
5. `.agents/Directional/Milestone_G_P5_Post_TB18_Ownership_Compaction_Topology_Output_Code_Build_Plan.md`
6. `.agents/Directional/GitHub_Workflow_Policy.md`

## Runtime result

- Phase 14–18: **223/232**;
- Milestone D: **4/7**;
- Milestone E: **23/26**;
- Phase 20: **47/48**;
- complete-minus-three-heavy-blockers: **573/593**;
- the full 596-test binary cannot complete because the smooth bunny path is
  killed at 3.80 GB RSS;
- all eight direct production cases fail;
- exact reuse/recompute remains `0/0`;
- invalid midpoint still returns `MissingCommonSourceChart`;
- no fallback or source-grid recovery was used.

Face-edge bunny now passes parity scope but fails at
`InvalidArrangementDomainIdentity;firstPatch=2` after 98.613553 s and
2,513,285,120 B peak RSS. Smooth bunny is SIGKILL/137 after 65.60 s with
3,801,161,728 B maximum RSS and no JSON output.

## Earliest implementation defects

### Expanded ownership class on every cell

`SurfaceArrangement.cpp::ownershipIdentity(root)` emits the complete sorted
class membership into every `cell.sourceOwnershipClass`. For connected bunny
components this duplicates roughly the whole source chart set across thousands
of cells. The same data is copied into rollback/prepared/descriptor products,
and patch compaction does not intern `sourceOwnershipClass` or
`sourceChartMap`.

Fix this first with one exact registry per complex and fixed-size deterministic
per-cell keys. Do not replace exact equality with a bare hash.

### No-label arrangement path

When `sourceFaceComponents/sourceFaceSheets` are absent and arcs carry no
scope, `allCharts` is empty, `selectedRoot` is `-1`, and embedding/topology is
invalid. Derive intrinsic connected components and deterministic default charts
from the source mesh. Do not skip ownership validation.

### Lost prepared-domain diagnostics

A descriptor can return before creating `domainIdentityAudit`, leaving failure
`None` and producing an untyped `InvalidArrangementDomainIdentity`. Add typed
simple-boundary failures and run them before descriptor construction.

### Remaining independent blockers

- same-corner route validation prevents both positive reuse paths;
- the midpoint fixture clears unrelated shared-node chart occurrences;
- the cylinder fixture fails incidence before extraction;
- four fixtures produce completed quads then become self-intersecting in
  optimization/output validation without valid rollback;
- torus/thin tube remain incomplete; sphere/mechanical fail domain identity.

## Required next work

Follow the P5-CB108–P5-CB116 plan exactly. The order matters:

1. compact ownership registry and memory lifecycle;
2. restore unlabeled ownership/topology;
3. propagate through simplification;
4. repair prepared-domain/parity producer with typed evidence;
5. route/reuse;
6. midpoint fixture;
7. cylinder DCEL;
8. completion/optimizer/output rollback;
9. compile-only regression/package gate.

## Preserved prohibitions

- no validator weakening;
- no frequency/count/order ownership selection;
- no fallback/recovery substitution;
- no synthetic counters;
- no positional merging or source-triangle pairing;
- no arbitrary subset search;
- no fixture/ID special cases;
- no timeout-as-correctness.

## Workflow policy

Any GitHub workflow must initialize detailed logging before fallible work,
always upload a separate log artifact under `if: always()`, avoid secret
exposure, and preserve the compile-only turn boundary.

## Key lessons

- A correct semantic model can still be unusable if its exact identity is
  duplicated at the wrong ownership granularity.
- Canonical class membership belongs in one registry; cells should reference it
  and carry only their own incident charts.
- New explicit-label regressions do not cover the no-label production and legacy
  paths.
- A typed validator must set a failure kind on every early return.
- Stop repeated benchmark runs after a catastrophic OOM/resource failure; a
  timeout or kill is evidence of failure, never a pass.
