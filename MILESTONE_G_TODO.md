# Milestone G Production Readiness TODO

Last updated: 2026-08-02
Base branch: `surface_cell_quad`
Target fixture: `benchmarks/fixtures/milestone-g/bunny_1k_random.obj`

## Active implementation branch

- Phase: P5 — resolve duplicate authoritative patch ownership during direct completion.
- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`.
- Draft PR: `#8`.
- Validated source checkpoint: `d4c1bce4338b7f2e91264c349a73b6b260e80f54`.
- Build artifact: `8840174777`, digest `sha256:a5659e86e0f1e90129d1b085e25ed0f2afff0ea882a43304fae15a5f18b9970a`.
- Completed turn: **test and benchmark** using exact artifact binaries without rebuilding.
- Next authoritative turn: **code changes + compile-only build**.
- Review policy: `never`.

## Work phases

- [x] P0 — Establish reproducible local source and dependency snapshot.
- [x] P1 — Review plans, diagnostics, and benchmark/test harness.
- [x] P2 — Reproduce and preserve the direct bunny failure.
- [x] P3 — Restore required nonempty singular separatrix prefixes.
- [x] P4 — Implement balanced regular-disk quadrangulation.
- [ ] P5 — Resolve remaining direct-completion ownership failures. **In progress**
- [x] P5A — Fail closed without legacy integration or meshing.
- [x] P5-CB1 — Add canonical domain and stitch-vertex identities.
- [x] P5-CB2 — Detect duplicate/overlapping arrangement ownership before completion.
- [x] P5-CB3 — Stitch only equal authoritative identities and keep interiors patch-local.
- [x] P5-CB4 — Preserve duplicate validation and add typed ownership hashes.
- [x] P5-CB5 — Add generalized ownership/ordering regression sources.
- [x] P5-TB1 — Validate artifact `8840174777` without rebuilding.
- [x] P5-TB2 — Run ownership regressions: 8/8 passed.
- [x] P5-TB3 — Run Phase 14–18 aggregate: 219/219 passed.
- [x] P5-TB4 — Run Milestone G P23 and Phase 20: 52/52 passed.
- [x] P5-TB5 — Repeat direct bunny twice and classify the new conflict.
- [ ] P5-CB7 — Canonicalize completed-face identity cycles and serialize corner/backend lineage.
- [ ] P5-CB8 — Reclassify and repair case B or case D generally.
- [ ] P5-CB9 — Enforce per-face completion-domain ownership proof.
- [ ] P5-CB10 — Add false-merge versus completion-template discriminator regressions.
- [ ] P5-CB11 — Correct three structurally invalid Milestone E fixtures.
- [ ] P5-CB12 — Reduce ownership memory and completion-time overhead.
- [ ] P6 — Validate topology, provenance, projection, alignment, determinism, and quality.
- [ ] P7 — Focused and full regression closure.
- [ ] P8 — Final bunny benchmark and production disposition.

## Validated test evidence

- New ownership/identity regressions: **8/8 passed**.
- Phase 14–18 aggregate: **219/219 passed**.
- Milestone G P23 and Phase 20: **52/52 passed** after recreating the artifact's baked absolute source path with a symlink.
- `PatchDescriptorMilestoneE.*`: **12/15 passed**.
  - Shared-edge parity fixture is pre-existing and topology-invalid before parity repair on both baseline and current artifacts.
  - Ambiguous-singularity fixture duplicates an entire canonical domain and is preempted by correct unique-domain validation.
  - Partial-output fixture also duplicates the valid domain and is preempted by correct unique-domain validation.
- Full-suite status remains unclaimed because an optional attempt was interrupted by the execution environment timeout during the P26 production matrix.

## Direct random-bunny evidence

Two independent runs, with `SurfaceCells`, fallback `Fail`, and source-grid recovery disabled, failed identically:

```text
DuplicateStitchedQuad:firstPatch=378;firstLocalQuad=1;
secondPatch=394;secondLocalQuad=4;
globalVertices=7643,7644,7647,7648;
classification=completion-template;
firstDomainHash=1626132098604174973;
secondDomainHash=12830489233532523937;
firstBoundaryNodeHash=9853059121513979599;
secondBoundaryNodeHash=6530130091133399252;
firstBoundaryHalfedgeHash=11019542682270369445;
secondBoundaryHalfedgeHash=4213466302263896358;
firstSourceSupportHash=9777327708078931779;
secondSourceSupportHash=17251474233191701613
```

- Arrangement cells: **21,298**.
- Descriptors attempted/completed/failed: **21,297 / 21,297 / 0**.
- Required unresolved endpoints: **0**.
- Accepted output quads: **0**.
- Failure text and all stage structural hashes were deterministic.

The distinct domain, boundary, and source-support hashes rule out duplicate-domain and overlapping-boundary ownership. The artifact selected completion-template ownership. This remains provisional until per-corner identities are canonicalized across cyclic/reversed local order and serialized with backend/region lineage.

## Performance evidence

Same-machine baseline artifact `8838467442`, commit `c84e2e1d64e867e5975f414780f9c81e649612fb`:

- Wall time: **22.981569 s** baseline vs **26.775241 s** current mean (**+16.51%**).
- Peak working set: **749,375,488 bytes** baseline vs **1,696,000,000 bytes** current mean (**+126.32%**).
- Completion stage: **4.168940 s** baseline vs **6.318718 s** current mean (**+51.57%**).

## Next turn authority

- Validation report: `.agents/Directional/Milestone_G_P5_Test_Benchmark_Report.md`.
- Authoritative code/build plan: `.agents/Directional/Milestone_G_P5_Completion_Template_Code_Build_Plan.md`.
- The next turn must compile only and run no tests, benchmarks, or custom mesh executions.
- P5 remains open and PR #8 remains draft/unmerged.
