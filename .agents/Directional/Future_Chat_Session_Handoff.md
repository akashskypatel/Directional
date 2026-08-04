# Directional Surface-Cell Quadrangulation — Session Handoff

**Updated:** 2026-08-04  
**Repository:** `akashskypatel/Directional`  
**Base:** `surface_cell_quad`  
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Current checkpoint

P5-CB126 through P5-CB134 code changes and the exact compile-only gate are complete. P5 remains open.

Compiled checkpoint:

- implementation commit `01788193457e60bb8817a40b2c1551e672c4de5c`;
- exact compiled source after a test-only namespace fix:
  `247061bbaa835e5e5bf9298cc5e2c4dd25d5c74f`;
- successful run `30903283158`, job `91972369451`;
- artifact `8890167812`,
  `surface-cell-p5-cb134-github-source-linux-release`;
- artifact SHA-256
  `34a4da9a9c9e3374ed861c41b72493beefc90afbc85743fd25979484f3222bf1`;
- workflow-log artifact `8890168646`, SHA-256
  `34da4a27f77c8e55e8a1369b535cf5230b8d3879dfa1da8f3768226943034191`;
- empty source status;
- checksums **41/41**;
- fixture files **26**;
- recursive submodule records **9**;
- all 131 Ninja actions complete.

The build compiled exactly `directional_core`, `directional_pipeline`,
`directional_phase1_tests`, and `directional_benchmarks`. No project binary,
test, benchmark, custom mesh, help/list, or discovery command executed.

The next turn is **P5-TB21 artifact-only test and benchmark**. Execute artifact
`8890167812` directly. Do not configure, rebuild, relink, patch, regenerate, or
modify source.

## Read first

1. `TODO`
2. `MILESTONE_G_TODO.md`
3. `.agents/Directional/Milestone_G_P5_CB126_CB134_Code_Build_Report.md`
4. `.agents/Directional/Milestone_G_P5_CB134_Test_Benchmark_Plan.md`
5. `.agents/Directional/Milestone_G_P5_TB20_Topology_Route_Completion_Test_Benchmark_Report.md`
6. `benchmark-results/p5-tb20-summary.json`
7. `.agents/Directional/GitHub_Workflow_Policy.md`

## Implemented in P5-CB126–P5-CB134

### Provenance and local embedding

- The positive provenance test now uses a simple regular polygon on `z=1` while
  retaining component, sheet, face, barycentric, and position assertions.
- The former zig-zag geometry is preserved as a separate negative embedding
  regression.
- Local completion failures now report a typed classification, owning patch and
  cell, backend, bounded variant, local quad and corners, component/sheet, and
  source faces.

### Parity, cylinder topology, and bounded alternatives

- The shared-parity fixture has explicit node-occurrence and cell chart
  ownership plus a typed incidence assertion before repair.
- Parity cost deterministically favors bounded-to-bounded interfaces while
  preserving hard-feature penalties.
- Arrangement construction decomposes pinched successor cycles into
  edge-disjoint simple directed cycles before cell assignment.
- Parity/replacement repair may evaluate bounded single-edge exclusions incident
  to the typed failing cell, recomputing and validating each alternative before
  commit.

These source changes are compile-valid, but shared-parity success, cylinder
closure, and production alternatives remain runtime-open.

### Same-corner ownership and reuse

Routes with equal embedded geometric/source-route identity now count as semantic
overlap even when raw rail/curve IDs differ. A genuinely distinct route uses
canonical boundary and source-route identity, and one canonical route is refined
to preserve unaffected completion-cache entries.

Runtime must still prove renamed duplicate rejection, valid annular completion,
no duplicate stitched output, and genuine `reused > 0` plus `recomputed > 0`.
Counters were not synthesized.

### Pipeline lineage

`fail_surface_cells` preserves an already-recorded original surface-cell failure
instead of overwriting it during later failure propagation. Completion
validation was not bypassed. GP23/GP24/Phase20 stage and fallback lineage remain
runtime-open.

### Source-sheet ownership and incomplete inventory

Completion ownership validation now receives the source face matrix and can
rebind source-vertex/source-edge barycentric support to a compatible owning
component/sheet chart using intrinsic source-vertex identity. Incomplete-complex
diagnostics now report descriptor, cell, reason, and attempted/failed/total
inventory counts.

Runtime must establish whether `LocalSheetMismatch`, invalid global output,
torus incompleteness, and thin-tube completion are resolved.

### Telemetry

Benchmark JSON now distinguishes categorized peak owned bytes, whether a
same-sample measurement is available, and explicit reconciliation remainder. A
false availability flag is an honest open gate. Do not infer 75% coverage from
phase maxima.

## Compile incident

Run `30902693111` applied and pushed the implementation commit, then failed only
while compiling `PatchDescriptorMilestoneETests.cpp`: the typed incidence audit
was qualified from `directional::geometry` instead of
`directional::geometry::surface_simplification_detail`.

Failure-log artifact `8889884342` has SHA-256
`b3f41643b614ff4caaf3f5973524663ea7f2c1933fe0518c0f4c891f00a71171`.
The follow-up commit `247061b...` corrects only those two test qualifications.
Run `30903283158` then compiled and packaged successfully. No project binary ran
in either workflow.

## Last runtime authority: P5-TB20

Closed or preserved:

- package integrity;
- Phase 16 **39/39** and Phase 17 **26/26**;
- canonical rollback baseline;
- typed incidence/domain evidence;
- invalid repeated-node/halfedge/non-simple commits reject and roll back;
- full-suite termination;
- no fallback or source-grid recovery;
- four face-edge failed runs within wall/RSS limits.

Open or regressed:

- Phase 14–18 **234/235**;
- full suite **581/599**;
- shared-edge parity baseline/transaction;
- cylinder non-disk cell;
- valid replacement after repeated-node rejection;
- same-corner route correctness and reuse `0/0`;
- pipeline injection/fallback/original-failure lineage;
- all eight production fixtures;
- smooth wall repeat and four-run determinism;
- at least 75% same-sample memory reconciliation.

Do not claim any P5-CB134 runtime closure before P5-TB21.

## P5-TB21 execution order

Follow the artifact-only test plan:

1. package authority and hashes;
2. focused provenance/embedding tests;
3. shared parity and rollback;
4. cylinder topology;
5. bounded replacement alternatives;
6. semantic duplicate, annular route, duplicate output, and real reuse;
7. GP23/GP24/Phase20 pipeline lineage;
8. typed local embedding and source-sheet stitching;
9. Phase 14–18, D, E, GP23/24, Phase20, full suite;
10. eight direct production fixtures;
11. resource-gated face-edge and smooth bunny processes;
12. same-sample memory availability/reconciliation disposition.

Start one bunny process per field. Continue repetition only after each preceding
run stays within the established 39.228299 s wall and 1,115,394,560 B peak
working-set limits. Stop smooth repetition after the first limit violation.

## Preserved prohibitions

- no validator weakening;
- no frequency/count/order ownership selection;
- no fallback/recovery substitution;
- no synthetic counters;
- no positional merging or source-triangle pairing;
- no arbitrary subset search;
- no fixture/ID special cases;
- no timeout-as-correctness.

## Key lessons

- A test intended to prove provenance must use valid geometry; preserve malformed
  geometry as a separate negative contract.
- Typed rejection must be followed by a bounded, topologically justified valid
  alternative; rejection alone is not completion.
- Route identity requires both canonical boundary occurrence and embedded source
  ownership; raw names and geometric position are insufficient.
- Source-chart rebinding must preserve intrinsic geometry and lineage.
- Compile-only success establishes build validity, not production
  quadrangulation.
