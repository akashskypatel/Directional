# Milestone G Production Readiness TODO

Last updated: 2026-08-02
Base branch: `surface_cell_quad`
Target fixture: `benchmarks/fixtures/milestone-g/bunny_1k_random.obj`

## Active implementation branch

- Phase: P5 — resolve remaining direct-completion ownership failures.
- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`.
- Draft PR: `#8`.
- Exact validated artifact source: `dcef9fbf65930b20db93128deb193f10702dc9c7`.
- Artifact: `8840866875`, digest `sha256:d67a464b2f2c2f6d58bbb9fa15a0e87009176698f14d19a9054facfbcb97cd90`.
- Completed turn: **test and benchmark** without rebuilding.
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
- [x] P5-TB5 — Repeat direct bunny and expose provisional completion-template conflict.
- [x] P5-CB7 — Canonicalize completed-face cycles and add stronger ownership lineage.
- [x] P5-CB8 — Implement false-merge versus completion-template classification and repair routing.
- [x] P5-CB9 — Add completion-domain ownership proof.
- [x] P5-CB10 — Add discriminator and patch-order regression sources.
- [x] P5-CB11 — Correct two of three invalid Milestone E fixture scenarios.
- [x] P5-CB12 — Compact ownership identities and release superseded capacity.
- [x] P5-CB13 — Build and package artifact `8840866875`.
- [x] P5-TB6 — Execute artifact `8840866875` and collect focused tests, deterministic bunny runs, and performance evidence.
- [ ] P5-CB14 — Replace literal boundary-face membership with intrinsic source-entity support.
- [ ] P5-CB15 — Canonicalize serialized conflict corner order under reversal.
- [ ] P5-CB16 — Construct a topology-valid two-odd-cell parity fixture.
- [ ] P5-CB17 — Add chart-alias and strict source-support escape regressions.
- [ ] P5-CB18 — Propagate ownership repair attempts and typed support diagnostics.
- [ ] P5-CB19 — Preserve compact ownership performance while adding source incidence.
- [ ] P6 — Validate topology, provenance, projection, alignment, determinism, and quality.
- [ ] P7 — Focused and full regression closure.
- [ ] P8 — Final bunny benchmark and production disposition.

## Artifact validation

- All packaged checksums passed.
- `source-commit.txt` matches `dcef9fbf65930b20db93128deb193f10702dc9c7`.
- `source-status.txt` is empty.
- No rebuild was performed during this turn.

## Test evidence

| Scope | Passed | Failed |
|---|---:|---:|
| Ownership discriminator subset | 3 | 1 |
| `PatchDescriptorMilestoneE.*` | 14 | 1 |
| Phase 14–18 aggregate | 218 | 4 |
| Milestone G P23 + Phase 20 | 52 | 0 |

Five unique failures remain:

1. Reversed equivalent face cycles classify correctly, but conflict corner arrays are serialized in different orientations.
2. Three valid periodic-cylinder/stitching tests are preempted because boundary provenance stored in an adjacent incident source-face chart is rejected.
3. The shared-edge parity fixture still has invalid topology before parity repair.

## Direct random-bunny evidence

Two independent runs failed identically before assembly:

```text
CompletionOwnershipSourceSupportEscape
```

- Arrangement cells: **21,298**.
- Descriptors attempted/completed/failed: **21,297 / 21,193 / 104**.
- Required unresolved endpoints: **0**.
- Accepted output quads: **0**.
- All stage structural hashes matched.
- The earlier duplicate pair `378/394` was not reached, so it is neither confirmed fixed nor reclassified.

## Root-cause contract

A boundary `SurfacePoint` stored on a source edge or source vertex may use any incident source-face chart. Literal `point.face ∈ patch.sourceFaces` is not a valid support test for those points.

The repair must use exact source topology:

- face interior → exact face;
- source edge → incident faces of the canonical edge;
- source vertex → incident faces of the canonical vertex;
- generated interior → strict patch face support.

Component/sheet labels and authoritative boundary identity remain enforced. Position must not create ownership.

## Performance evidence

Current means:

- wall time: **24.835062 s**;
- peak working set: **872,785,920 B**;
- completion stage: **5.176516 s**.

Versus baseline `8838467442`: +8.07% wall, +16.47% memory, +24.17% completion.

Versus previous `8840174777`: -7.25% wall, -48.54% memory, -18.08% completion.

## Authoritative next turn

Use `.agents/Directional/Milestone_G_P5_Source_Support_Code_Build_Plan.md`.

The next turn must:

1. implement intrinsic source-entity support and typed rejection diagnostics;
2. canonicalize reversed conflict serialization;
3. fix the parity fixture construction;
4. propagate `completionOwnershipRepairAttempts` and first ownership rejection;
5. preserve compact identity performance;
6. compile the four required targets only;
7. run no tests, benchmarks, or custom mesh executables;
8. keep P5 open and PR #8 draft/unmerged.

## Evidence files

- `.agents/Directional/Milestone_G_P5_Source_Support_Test_Benchmark_Report.md`
- `.agents/Directional/Milestone_G_P5_Source_Support_Code_Build_Plan.md`
- `.agents/Directional/Milestone_G_P5_Completion_Template_Code_Build_Report.md`

PR #8 remains draft and unmerged.
