# Milestone G P5-CB134 Test and Benchmark Plan

**Date:** 2026-08-04  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`  
**Next turn:** P5-TB21 artifact-only test and benchmark

## Authority

Execute artifact `8890167812`, `surface-cell-p5-cb134-github-source-linux-release`, directly.

- exact compiled source: `247061bbaa835e5e5bf9298cc5e2c4dd25d5c74f`;
- implementation commit: `01788193457e60bb8817a40b2c1551e672c4de5c`;
- artifact SHA-256: `34a4da9a9c9e3374ed861c41b72493beefc90afbc85743fd25979484f3222bf1`;
- reviewed patch SHA-256: `cb6b02838c08f68bb272b14a13b218572fcae88a58c9d3a73badbafd26b5421f`;
- compile-fix SHA-256: `49ee91640fced0bf21a50fd614a40937ff5b261d4adee8e828262ba2d3e2dd29`.

Do not configure, build, relink, patch, regenerate, or modify source in P5-TB21.

## 1. Package authority

Before executing either packaged binary, verify:

- archive SHA-256;
- exact source commit and implementation ancestry;
- empty source status;
- **41/41** recursive checksums;
- **26** fixture files;
- **9** recursive submodule records;
- packaged target hashes;
- source archive contains the typed embedding, route, parity, arrangement, provenance, pipeline, and telemetry changes.

Any authority mismatch terminates the turn before runtime execution.

## 2. Focused contract tests

Run the smallest directly named regressions first.

### P5-CB126 provenance and embedding

- valid completion provenance fixture;
- negative zig-zag embedding fixture;
- existing malformed local-quad embedding regressions.

Require the positive fixture to preserve component, sheet, source face, barycentric coordinates, and position. Require the negative fixture to fail for typed embedding reasons without weakening validation.

### P5-CB127 shared parity

Run:

- shared-edge two-odd-cell baseline audit;
- conforming shared-interface parity repair;
- exact rollback after rejected parity mutation;
- hard-feature and exterior-cycle preservation.

Record the first typed node/halfedge/twin/next/cell failure if the baseline or transaction remains invalid.

### P5-CB128 cylinder topology

Run the open-cylinder closure test plus seam-start, face-row, and orientation permutations already present in the binary.

Require:

- valid incidence;
- disk interior cells;
- Euler characteristic 0;
- two boundary loops;
- consistent orientation;
- protected rail/strand preservation.

### P5-CB129 bounded alternatives

Run mechanical/sphere/repeated-node focused regressions and parity alternative/rollback contracts. Record:

- initial typed rejection;
- each bounded alternative class attempted;
- selected topological key;
- final incidence/domain/ownership disposition;
- exact rollback if all alternatives fail.

Do not interpret rejection alone as completion success.

### P5-CB130 route ownership and reuse

Run:

- renamed semantic duplicate rejection;
- valid annular parallel route;
- whole-complex parallel-route completion;
- guaranteed reuse/recompute tests;
- duplicate stitched output regressions.

Require semantic duplicates to reject before candidate expansion, valid distinct routes to reach completion, and genuine validated `reused > 0` plus `recomputed > 0`. Counters must derive from actual cache operations.

### P5-CB131 pipeline lineage

Run focused GP23, GP24, and Phase20 contracts covering:

- declared optimization injection;
- declared validation injection;
- earliest genuine completion producer failure;
- original failure preservation;
- last-valid-stage artifacts;
- `Fail`, `ReturnInputMesh`, and legacy fallback behavior;
- `CompletedSurfaceCells` only for a valid selected checkpoint.

### P5-CB132 typed local embedding

Run local completion tests that cover each typed failure class and verify owning patch/cell, backend, variant, local quad, corner identities, component/sheet, and source faces.

Then run focused cylinder, thin tube, general fallback, and smooth completion cases to determine whether a valid bounded variant is selected or a typed producer remains.

### P5-CB133 source-sheet stitching and inventory

Run focused output-validation contracts for plane, seam, close sheets, duplicate/reversed faces, source-face leakage, source-sheet mismatch, transverse intersections, and incomplete inventory.

Require invalid patch output to reject before global insertion. Record exact first unresolved torus patch/cell/reason and attempted/failed/total inventory.

### P5-CB134 telemetry

Verify JSON field presence and invariants for:

- categorized peak owned bytes;
- same-sample measurement availability;
- peak reconciliation remainder;
- unexplained bytes and ratio.

A false availability flag is an honest open gate, not a pass. Do not derive 75% coverage from phase maxima.

## 3. Broader test scopes

After focused contracts, run in this order:

1. Phase 14–18 aggregate;
2. Phase 16;
3. Phase 17;
4. Milestone D;
5. Milestone E;
6. GP23 + GP24;
7. Phase 20;
8. complete 599-test binary.

Record pass/fail counts, elapsed time, peak working set, and exact failed test names. Compare against P5-TB20:

- Phase 14–18: **234/235**;
- Milestone D: **6/7**;
- Milestone E: **21/26**;
- GP23 + GP24: **10/14**;
- Phase 20: **46/48**;
- full suite: **581/599**, 103.05 s, 529,739,776 B maximum RSS.

## 4. Direct production fixture matrix

Execute all eight direct production fixtures with:

- backend `SurfaceCells`;
- fallback `Fail`;
- source-grid recovery disabled.

Cases:

- plane;
- cylinder;
- multi-face seam;
- close sheets;
- mechanical feature;
- prescribed sphere;
- torus;
- thin bent tube.

For every case record success, output vertices/quads, manifold/pure-quad/source validity, output origin, terminal/original failure, first typed incidence/domain/embedding/inventory failure, fallback/recovery use, and memory categories.

A nonempty buffer is not a pass unless it is source-valid, manifold, pure quad, and selected as `CompletedSurfaceCells`.

## 5. Random bunny resource and determinism gate

Use `bunny_1k_random.obj` with fallback `Fail` and source-grid recovery disabled.

### Face-edge field

Run one independent process first. Continue to four total only when the first run remains within established limits:

- wall time at most 39.228299 s;
- peak working set at most 1,115,394,560 B.

P5-TB20 reference: 19.124–22.821 s and approximately 141.35–141.70 MB.

### Smooth field

Run one independent process first. Start each subsequent process only after the preceding process satisfies the same wall/RSS limits. Stop repetition immediately after a limit violation.

P5-TB20 reference: 31.545 s and 45.549 s; the second exceeded the wall limit, so only two runs completed.

For each path record deterministic success or failed-result signature, earliest typed failure, stage counts/hashes, output counts, reuse/recompute, wall time, peak working set, categorized same-sample bytes, availability flag, and reconciliation remainder.

Four matching failed signatures establish only deterministic failure, not successful quadrangulation.

## 6. Disposition and handoff

At the end of P5-TB21:

- write a grounded artifact-only runtime report;
- write machine-readable summary JSON;
- update `TODO`, `MILESTONE_G_TODO.md`, handoff, and PR #8;
- preserve the earliest typed producer for each remaining class;
- create the next focused code/build plan only from observed runtime evidence;
- keep PR #8 open, draft, and unmerged.

## Preserved prohibitions

- no validator weakening;
- no frequency/count/order ownership selection;
- no fallback/recovery substitution;
- no synthetic counters;
- no positional merging or source-triangle pairing;
- no arbitrary subset search;
- no fixture/ID special cases;
- no timeout-as-correctness.
