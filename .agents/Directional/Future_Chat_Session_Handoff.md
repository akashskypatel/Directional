# Directional Surface-Cell Quadrangulation — Session Handoff

**Updated:** 2026-08-03  
**Repository:** `akashskypatel/Directional`  
**Base:** `surface_cell_quad`  
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Current checkpoint

P5-CB91 through P5-CB98 are implemented in source commit
`34edce9e508fd81e28bbd6b68a064a2a57bacf03` and passed the compile-only gate.
P5 remains open because the new runtime contracts have not been executed.

Last runtime evidence is P5-TB16 on exact source
`d268ca00014935770f3b7fd74c5186c3d9ef3ddf`:

- complete suite **583/593**, ten assertion failures, zero signal 11;
- all three prior crash cases terminate normally;
- four face-edge and four smooth-field random-bunny processes are deterministic
  and within wall/memory limits;
- both field paths still fail closed at
  `BoundaryParityRepair:MixedCellSourceScope` and emit no output;
- exact reuse, intended invalid midpoint, cylinder topology/output, remaining
  production outputs, and RSS reconciliation remained open.

The next turn is **P5-TB17 artifact-only test and benchmark**. Do not rebuild.

## Read first

1. `TODO`
2. `MILESTONE_G_TODO.md`
3. `.agents/Directional/Milestone_G_P5_TB16_FlowRep_Parity_Reuse_Rail_Output_Memory_Test_Benchmark_Report.md`
4. `benchmark-results/p5-tb16-summary.json`
5. `.agents/Directional/Milestone_G_P5_CB91_CB98_Parity_Reuse_Fixture_Output_Memory_Code_Build_Report.md`
6. `benchmark-results/p5-cb98-summary.json`
7. `.agents/Directional/Milestone_G_P5_Post_CB98_Artifact_Test_Benchmark_Plan.md`

## Implemented in P5-CB91–P5-CB98

- Exact authoritative cell component/sheet scope is captured from committed
  state before parity subdivision.
- Mixed/missing scope fails before mutation with typed original/replacement
  cell, halfedge/twin, selected/available scope, and mutation-phase evidence.
- Replacement halfedges, twins, node occurrences, provenance, and cells inherit
  the authoritative scope before validation.
- Completion reuse identity covers source domain, subdivision, source
  coordinates, rail/curve support, singularities, backend/variant, and topology
  template; local allocation IDs and transient ordering are excluded.
- Cache mismatch vector and transactional rebind validation are available;
  reuse/recompute counters represent actual product reuse.
- Missing-chart and invalid-midpoint fixtures are separate; invalid midpoint has
  compatible endpoint occurrences and requires exact rollback.
- Cylinder fixture uses one canonical intrinsic entity per crossing and asserts
  incidence, embedding, orientation, disk cells, Euler 0, one component, and
  two boundary loops before simplification.
- Source-chart/output ownership is derived from authoritative provenance;
  invalid optimized output returns to the completed mesh, not fallback.
- First-invalid producer diagnostics identify stage and entity.
- Stage memory evidence separates logical payload, retained capacity, peak,
  simultaneous ownership, and acquire/release events; benchmark JSON emits it.

## Compile-only evidence

Clang 17 + Ninja + Release `-O2 -DNDEBUG` compiled and linked exactly:

- `directional_core`
- `directional_pipeline`
- `directional_phase1_tests`
- `directional_benchmarks`

No binary, test, benchmark, custom mesh, help/list, or discovery command was
executed. Test and benchmark targets temporarily used unity batch 1 to avoid
pre-existing anonymous-namespace collisions; the CMake edit was removed.

## Required next turn

Follow the post-CB98 artifact plan exactly:

1. Validate package digest, checksums, source commit/status, dependency records,
   binaries/libraries, and executable-relative fixture closure.
2. Run the ten P5-TB16 failures plus focused parity/reuse/midpoint/cylinder/
   output/memory regressions.
3. Run Phase 14–18, Milestone E, Milestone D, P23/P26/P27/Phase 20, the three
   former crash cases, and the complete suite.
4. Run four face-edge and four smooth-field random-bunny processes with zero
   warmups, one measured run, fallback `Fail`, and source-grid recovery off.
5. Require deterministic valid nonempty pure-quad output, positive exact reuse,
   intended invalid-midpoint rollback, valid cylinder and production outputs,
   and meaningful peak-RSS reconciliation.

Preserve all prohibitions: no validator weakening, fallback/recovery
substitution, synthetic counters, positional merging, source-triangle pairing,
arbitrary subset search, fixture/ID special case, or timeout-as-correctness.

If any gate remains open, the TB17 report must identify the first invalid
producer/entity and provide one bounded next code/build plan. Otherwise advance
to final P5 closeout.
