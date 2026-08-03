# Milestone G Production Readiness TODO

Last updated: 2026-08-02
Base branch: `surface_cell_quad`
Target fixture: `benchmarks/fixtures/milestone-g/bunny_1k_random.obj`

## Active implementation branch

- Phase: P5 — resolve remaining direct-completion ownership failures.
- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`.
- Draft PR: `#8`.
- Validated artifact: `8841726806`.
- Exact compiled source: `053fe3816f585320e65526824f1107b8ccb1332d`.
- Artifact digest: `sha256:9b9bf5ad23640dfe049d416a0b81649c2e8a3d0353e1bff475fa6ea58155a681`.
- Completed turn: **test and benchmark without rebuilding**.
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
- [x] P5-CB1 through P5-CB5 — Canonical domain/stitch ownership and initial generalized regressions.
- [x] P5-TB1 through P5-TB5 — Validate initial ownership implementation and expose deterministic completion conflict.
- [x] P5-CB7 through P5-CB13 — Canonical completed-face ownership, classification, bounded variants, compaction, and artifact `8840866875`.
- [x] P5-TB6 — Identify intrinsic source-support rejection and five regression failures.
- [x] P5-CB14 — Replace literal boundary-face membership with intrinsic source-entity support.
- [x] P5-CB15 — Canonicalize serialized conflict corners under reversal.
- [x] P5-CB16 — Add an explicit two-odd-cell parity fixture source.
- [x] P5-CB17 — Add chart-alias and strict support-escape regression sources.
- [x] P5-CB18 — Propagate ownership repair attempts and typed support diagnostics.
- [x] P5-CB19 — Reuse source incidence and preserve compact identities.
- [x] P5-CB20 — Compile and package artifact `8841726806`.
- [x] P5-TB7 — Execute artifact `8841726806`; reach assembly and classify the deterministic same-corner conflict.
- [ ] P5-CB21 — Correct the generated-interior escape and parity fixture inputs.
- [ ] P5-CB22 — Add exact same-corner/distinct-boundary claim and repair-attempt evidence.
- [ ] P5-CB23 — Repair valid parallel boundary routes upstream or fail invalid overlap before assembly.
- [ ] P5-CB24 — Add generalized same-corner, overlap, order, and closed-form routing regression sources.
- [ ] P5-CB25 — Preserve bounded runtime and compact memory during structural repair.
- [ ] P5-CB26 — Compile the exact repaired checkpoint and package the next artifact.
- [ ] P6 — Validate topology, provenance, projection, alignment, determinism, and quality.
- [ ] P7 — Focused and full regression closure.
- [ ] P8 — Final bunny benchmark and production disposition.

## P5-TB7 test evidence

| Scope | Passed | Failed |
|---|---:|---:|
| Focused intrinsic-support/canonical/parity subset | 5 | 2 |
| `PatchDescriptorMilestoneE.*` | 14 | 1 |
| Phase 16 + Phase 18 | 86 | 1 |
| Phase 14–18 aggregate | 226 | 1 |
| Milestone G P23 + Phase 20 | 52 | 0 |

Authoritative non-overlapping total: **292 passed, 2 failed**.

### Required test corrections

1. `CompletionRejectsGeneratedInteriorOutsidePatchSupport` mutates provenance to face 1 while the patch supports faces `{0,1}`. Add a genuinely outside valid source face.
2. `SharedEdgeParityRepairConforminglyCompletesTwoOddCells` has valid incidence but incomplete embedding/orientation/source-topology/area evidence. Populate authoritative inputs and recompute; never set final validity synthetically.

## Direct random-bunny evidence

Two independent direct processes completed all descriptors and reached assembly. Both failed identically:

```text
DuplicateStitchedQuad:firstPatch=8595;firstLocalQuad=0;
secondPatch=8573;secondLocalQuad=2;
globalVertices=10764,16938,27456,27459;
classification=completion-template
```

- Arrangement cells: 21,298.
- Descriptors attempted/completed/failed: 21,297 / 21,297 / 0.
- Ownership repair attempts: 4.
- Required unresolved endpoints: 0.
- Accepted output quads: 0.
- Output origin: `None`.
- Both claims are closed-form variant 0.
- Domain and boundary identities differ.
- Source support and canonical stitch/authoritative corner identities match.
- All required structural hashes and counts match across runs.
- No source-grid recovery or legacy fallback occurred.

The source-support blocker is resolved. The earlier `378/394` conflict was not reproduced; a later deterministic same-corner/distinct-boundary claim at `8595/8573` is now authoritative.

## Performance evidence

Current means:

- wall: 26.152199 s;
- peak working set: 892,315,648 B;
- completion: 6.475303 s.

Compared with baseline `8838467442`: +13.80% wall, +19.07% memory, +55.32% completion.

Compared with artifact `8840174777`: -2.33% wall, -47.39% memory, +2.48% completion.

Compared with artifact `8840866875`: +5.30% wall, +2.24% memory, +25.09% completion.

## Next code/build authority

Use `.agents/Directional/Milestone_G_P5_Assembly_Conflict_Code_Build_Plan.md`.

The next turn must:

1. correct both invalid test fixtures without weakening production behavior;
2. classify equal authoritative corner cycles with distinct domain boundaries exactly;
3. retain a bounded deterministic repair-attempt ledger;
4. distinguish invalid overlapping ownership from valid parallel boundary routes;
5. apply conforming transactional boundary-sector subdivision upstream for provably valid parallel routes;
6. fail closed before final assembly when overlap or repair cannot be proven;
7. avoid nonexistent closed-form rotation attempts;
8. preserve exact ownership, provenance, component/sheet, geometry, and final duplicate validation;
9. compile only the four required targets;
10. run no tests, benchmarks, or custom meshes.

## Closure rules

P5 remains open until direct completion passes assembly without duplicate ownership, recovery, fallback, final-face deduplication, positional ownership, source-triangle pairing, or patch-ID special cases. Correctness, determinism, and acceptable runtime/memory must be demonstrated by execution.

## Evidence files

- `.agents/Directional/Milestone_G_P5_Assembly_Conflict_Test_Benchmark_Report.md`
- `.agents/Directional/Milestone_G_P5_Assembly_Conflict_Code_Build_Plan.md`
- `benchmark-results/p5-tb7-summary.json`
- `.agents/Directional/Milestone_G_P5_Source_Support_Test_Benchmark_Report.md`

PR #8 remains draft and unmerged.
