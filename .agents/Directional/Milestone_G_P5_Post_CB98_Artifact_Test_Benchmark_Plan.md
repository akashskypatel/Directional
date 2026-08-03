# Milestone G P5 Post-CB98 Artifact Test and Benchmark Plan

**Authority:** source commit `34edce9e508fd81e28bbd6b68a064a2a57bacf03`  
**Turn type:** artifact-only test and benchmark  
**Review policy:** `never`

## Non-negotiable execution rules

1. Download and inspect the P5-CB98 package; do not configure, compile, relink,
   patch, or regenerate code.
2. Verify package digest, recursive checksum manifest, source archive commit,
   source status, dependency revisions, and fixture closure before running a
   binary.
3. Run packaged executables directly from an arbitrary extraction directory.
4. Do not weaken validators, substitute fallback/recovery output, synthesize
   counters, merge by position, pair source triangles, search arbitrary subsets,
   special-case fixture IDs, or classify a timeout as correctness.
5. Preserve every raw log and JSON result.

## TB17-A — package integrity

- Check every checksum.
- Confirm exact implementation commit and clean archived source.
- Confirm both static libraries and both executables are present.
- Confirm executable-relative fixture closure and the 502-vertex/1,000-face
  `bunny_1k_random.obj` fixture.
- Confirm Eigen, googletest, and polyscope revision records.

## TB17-B — focused regression gates

Run the ten P5-TB16 failures first, plus the new focused regressions for:

- exact authoritative parity scope and typed first-invalid evidence;
- both positive completion-reuse scenarios (`reused > 0`);
- separate missing-common-chart and `InvalidMidpointEmbedding` outcomes;
- exact rollback after invalid midpoint;
- canonical cylinder incidence/topology before candidate extraction;
- first-invalid output producer evidence;
- populated memory ownership timeline and retained-capacity fields.

Record assertion-level output. A newly passing assertion must reflect the real
contract; do not alter the test during this turn.

## TB17-C — milestone scopes

Run independently:

- Phase 14–18 aggregate;
- `PatchDescriptorMilestoneE.*`;
- Milestone D closure;
- Milestone G P23/P26/P27 and Phase 20 production scopes;
- the three former signal-11 production cases individually;
- the complete packaged suite.

Report passed/failed totals, process exit type, duration, and the first failure
for each scope.

## TB17-D — random-bunny benchmarks

Run four independent processes for each generated-field path with zero warmups
and one measured run:

1. face-edge field using `repo_regressions.json` / `bunny_1k_random_medium`;
2. smooth field using `milestone_g_manifest.json` /
   `bunny_1k_random__surface_cells`.

Keep source-grid recovery disabled and fallback policy `Fail`.

For each process record:

- exit status and wall time;
- peak working set/RSS;
- normalized structural digest excluding timing/process-local data;
- stage hashes and counts;
- output origin and fallback/recovery flags;
- output vertices/quads and pure-quad validation;
- exact reused/recomputed completion counts and mismatch vector;
- current, retained, peak, and simultaneous bytes for every stage;
- ownership acquire/release timeline;
- peak-RSS reconciliation ratio and unexplained bytes.

## Required closure gates

P5 can advance only when all are true:

- all focused failures pass for their intended reasons;
- former signal-11 cases terminate normally;
- complete suite has no unexpected failure;
- four face-edge and four smooth-field runs are deterministic;
- both paths return valid nonempty pure-quad surface-cell output without
  fallback or source-grid recovery;
- positive exact reuse is observed where the fixture guarantees unchanged
  dependencies;
- invalid midpoint is reached only after a valid common-chart precondition and
  rollback is bit-exact;
- cylinder fixture topology and production output pass;
- plane, seam, torus, and mechanical-feature output contracts pass;
- stage memory telemetry is populated, internally consistent, and explains the
  dominant peak RSS ownership rather than only logical payload.

## Deliverables

- `.agents/Directional/Milestone_G_P5_TB17_Parity_Reuse_Output_Memory_Test_Benchmark_Report.md`
- `benchmark-results/p5-tb17-summary.json`
- updated `TODO`, `MILESTONE_G_TODO.md`, and session handoff;
- one next code/build plan only if a runtime gate remains open.
