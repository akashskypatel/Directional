# Gate 1 Producer Architecture — Mandatory Design Review Plan

## Turn type

This is the mandatory **Review turn** triggered by the no-progress stop rule after two bounded Gate 1 Code + Build attempts failed to materially advance the production plane.

Do not make production source, test, fixture, manifest, validator, fallback, recovery, or build-system changes during the review. The review may update the next Code + Build action plan and design/handoff documentation only.

GitHub workflow operations are available again. A later authorized Code + Build turn may use GitHub Actions for normal compilation/artifact production, subject to the existing workflow/payload hygiene rules. The review itself does not need a build.

## Review declaration

```text
Active design gate: Gate 1 — uniform phase-front plane
Earliest failing fixture: plane__surface_cells
Missing design contract: one production authority path from finalized cross field + production target/labels into authoritative phase-front cells, with no silent substitution by generic tracing/completion when that authority is applicable
Smallest review objective: prove the exact production-plane divergence from the last successful Gate 1 source and choose one bounded architectural correction or producer replacement proof
Observable review completion: one evidence-backed execution model explains why the exact committed plane no longer enters direct phase-front output and yields a single implementable next Code + Build plan with explicit success/failure criteria
Explicitly deferred work: close sheets, cylinder holonomy, bunny/vase completion, performance, cache/memory, validator timing, historical completion failures
```

## Exact evidence authority

- last successful Gate 1 comparison source: `aea10409c73c490b92f78760b73191641ef823c6`;
- Gate 2 source introducing chart transport: `21f081b330418a0f34709f61d857f54a03d2fd48`;
- first rejected restoration source: `a90f6b9de83dba4aeac359b2f63d735e2049b54e`;
- second bounded source: `364a20e12165af7dbfe213bb6d075e3fe25b1574`;
- tested artifact SHA-256: `922be37c4ee849152dee40168e3e8604357af46189d6491124b7b83dce7ca741`;
- test evidence SHA-256: `99a4922767d567830f202b440504f2b48d07fdb02bb117668baf846e7eeb9b64`;
- current plane runtime: deterministic 106 traces / 9 arrangement cells / 12 completion candidates / 15 validation failures / no output;
- retained seam runtime: deterministic 81 vertices / 64 pure quads / `CompletedSurfaceCells` / hash `a8972efd7c4900a4`.

## Required architectural review

### 1. Reconstruct the exact production authority path

Trace the committed `plane.obj` + `plane.rawfield` through the actual pipeline, not a reconstructed test mesh:

1. benchmark/test manifest loading;
2. `remesh_from_raw_cross_field`;
3. `finalize_surface_cell_raw_cross_field`;
4. generated matching, effort, and edge transitions;
5. source component/local-sheet classification;
6. adaptive/production target-size computation;
7. all `SurfaceCellTracingOptions` values used by the pipeline;
8. `build_surface_cell_network`;
9. `build_uniform_phase_front`;
10. direct materialization versus generic tracing/arrangement/completion selection.

Record the exact values that differ from the passing isolated contract test: mesh indexing, field metadata, target size, source labels, feature/barrier state, tracing options, and any other input consumed before `phaseFront.succeeded` is decided.

Do not assume geometrically equivalent reconstructed meshes are execution-equivalent. Vertex/face ordering, source labels, target-size values, and metadata identity must be treated as first-class until proven invariant.

### 2. Compare the successful and regressed architectures

Compare `aea10409...` → `21f081b...` → `a90f6b...` → `364a20e...` with emphasis on semantic control flow rather than line count.

Identify exactly:

- when the successful parent chose direct phase-front materialization;
- which Gate 2 change caused the plane to stop producing the 64-cell direct result;
- whether the regression is caused by producer input construction, phase-frame admissibility, transition transport, target/label state, or control-flow substitution after phase-front non-success;
- why the seam benefits from the new path while the plane does not.

The review must distinguish a proven cause from a candidate.

### 3. Audit producer failure authority

The current pipeline writes typed `tracing/phase-front` first-invalid state, then downstream completion paths overwrite the same diagnostic fields. Determine whether the authoritative phase-front result itself is retained anywhere after generic tracing begins.

Review the semantic question, not just diagnostics:

- For a domain where uniform phase-front paving is applicable, is `phaseFront.succeeded == false` allowed to silently continue into the generic tracing/completion producer?
- If yes, define the exact general applicability boundary and why substitution remains source-authoritative.
- If no, specify a bounded architecture in which authoritative phase-front attempt/success/failure is a first-class producer outcome and cannot be replaced by an unrelated generic path.

Do not use fallback/recovery terminology to disguise internal producer substitution.

### 4. Review test validity

The new fan tests pass, but `make_vertex_fan_plane_mesh()` is a reconstructed synthetic plane with different indexing and a directly injected constant target size. It does not prove the exact production fixture route.

The next Code + Build plan must require, without weakening existing tests:

- a producer-level regression that loads the exact committed `plane.obj` and `plane.rawfield`;
- the same production cross-field finalization, target-size computation, source labels, and tracing options used by the pipeline;
- assertion of the authoritative phase-front outcome before generic downstream stages;
- retention of the isolated vertex-fan tests as narrow contract tests;
- continued mandatory bunny/vase topology and direct acceptance coverage.

A test that duplicates expected 64-quad output by directly injecting a convenient target or preconstructed state is insufficient.

### 5. Choose one bounded next implementation strategy

The review must choose exactly one of these evidence-backed outcomes:

**A. Bounded architectural correction** — when the successful direct producer remains structurally sound and the regression is a clearly isolated production-input/control-flow error. Produce one Code + Build plan that fixes that general contract and preserves the seam.

**B. Bounded producer replacement proof** — when repeated local patches show the current mixed phase-front/generic producer architecture cannot express one coherent authority path. Define the smallest replacement boundary, inputs/outputs, invariants, migration sequence, and tests needed to replace the problematic producer segment without rewriting unrelated downstream stages.

Do not authorize another isolated predicate patch as outcome C.

## Replacement-proof requirements if selected

A replacement proof must define:

- exact producer boundary and API;
- first-class inputs: source topology, finalized cross field, target size, source component/sheet labels, feature/barrier state;
- first-class outputs: ordered phase/front cells or typed fail-closed reason, complete provenance, deterministic structural hash;
- direct one-cell-to-one-quad materialization contract;
- no generic completion substitution for a producer result represented as authoritative;
- ordinary edge, source-vertex fan, reciprocal quarter-turn, boundary, and later periodic extension points;
- how close-sheet and future periodic topology can extend the representation without positional merging or post-hoc topology inference;
- bounded migration path preserving existing seam success;
- exact tests that gate each migration step.

## Review exit products

- `.agents/Directional/Gate_1_Producer_Architecture_Design_Review_Report.md`;
- exactly one next Code + Build plan based on outcome A or B;
- updated `DESIGN.md`, remediation/reorientation authority, TODOs, handoff, and PR metadata;
- no production code/test/fixture changes;
- repository workflow/payload hygiene checked at start and end;
- final top-level PR #8 comment as the last repository write.

## Stop condition

The review is incomplete if it merely identifies another failing Boolean predicate. It must explain the production-plane/synthetic-contract divergence and the producer authority/control-flow architecture well enough that a new coding agent can implement one bounded next strategy without another exploratory repair cycle.
