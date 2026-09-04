# M3-CP4c-3-CB25 — Code + Build Report

- Phase: `M3-CP4c-3-CB25`
- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`
- Turn type: Code + Build, **diagnostic-only**
- Binding plan: `Architecture_M3_CP4c3_TB22_Independent_Review_Record.md` §8, **CA0–CA9**
- Semantic source/evidence commit: `e12396d471c0754b112a40272a7992020ff49ced`
- Selector 393: **byte-frozen**, 393 identities, LF SHA-256 `ee8cc03360c30b7ef662c3972b852d8b6f17dddbf5abac29a632e02227644c4d`
- Selector 397: **397 identities**, LF SHA-256 `d67e5fb72196313c54fbc21be0b446ab0fba3974c47c02e18c33dfe9b4853ee5`; exact prefix parent: selector 393
- Accepted prefix: selector 365, 365 identities, LF SHA-256 `6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1`
- Runtime execution: **none**

## Result

CB25 implements the review-authorized falsifiable certificate-face diagnostics without changing product topology semantics. The exact semantic source compiled in a mandatory one-target pre-package run and then in the eight-target authoritative package compile under the repository GMP policy.

Compile evidence is filled from the terminal Actions runs below. No Directional binary, test, benchmark, discovery/list/help/version command, `ctest`, CLI/GUI, fuzzer, or custom input executed during CB25.

## CA0–CA9 implementation

### CA0 — frozen authority and compile boundary

- Selector 365 remained byte-identical.
- Selector 393 remained byte-identical at `ee8cc03360c30b7ef662c3972b852d8b6f17dddbf5abac29a632e02227644c4d`.
- The semantic source was built with `DIRECTIONAL_ENABLE_GMP=ON`; authoritative package evidence must record both `gmpxx` and `gmp` on a generated link command and `exactArithmeticBackend=GMP`.
- Runtime execution was prohibited and did not occur.

### CA1 — certified ownership comes from certificate-face authority

A new diagnostic-only certificate projection is built from `SurfaceCutGraph::certificate().faces` plus the actual face-walk/dart-side evidence that reaches those certified faces. It does not derive certified ownership from `edgeOrbitEvidence`, `fragmentOrbits`, `seedOrbits`, or the seed-side lookup. The old misleading `certificate_side_orbit` surface is retired in favor of explicitly named certified-face fields.

### CA2 — independent side measurements

Minority-boundary diagnostics resolve the component and labeled sides independently. Neither side is assigned from the other. An unavailable certified face remains explicit `none` rather than inheriting a seed or opposite-side value.

### CA3 — satisfiable uncut-face pair measurement

The old structural-zero projection residual is removed. The replacement scans adjacent uncut source-triangle pairs whose shared edge is not a component barrier and publishes separately:

- `uncutFaceCertificatePairExaminedCount`;
- `uncutFaceCertificatePairDifferingCount`;
- bounded pair rows and a truncation flag.

The count is satisfiable by construction: eligible non-barrier adjacency is examined independently of whether its certified-face labels agree.

### CA4 — failing-component certified-face multiset

The failing uncut component publishes certified-face observation, unavailable, and distinct counts plus a bounded certified-face multiplicity table and truncation flag. This is the discriminator that can show whether the current seed-conflict component lies inside one certified face or spans several.

### CA5 / CA6 — falsifiable witnesses

CB25 adds four selector identities:

1. `GlobalTopologyPlan.CertificateFaceProjectionDerivesOwnerFromCertifiedFaceWalkSide`
2. `GlobalTopologyPlan.CertificateSideLookupDoesNotAliasOppositeSideOrSeed`
3. `GlobalTopologyPlan.CertificatePairMeasurementCanReportNonZeroDifferingCount`
4. `GlobalTopologyPlan.UnrelatedTopologyErrorLocusRemainsByteIdenticalAfterCertificateDiagnostics`

The retained mechanical production-path identity now requires a non-zero examined-pair count and a non-zero differing-pair count, publishes the independently certified minority-edge sides alongside the seed, requires at least one certified-face/seed disagreement, and checks the failing-component multiset census. The unrelated-error witness protects byte-identical diagnostics outside this surface.

### CA7 — selector append and manifest

Selector 397 appends exactly the four identities above to byte-frozen selector 393. No predecessor identity is reordered or altered. `selector_manifest.py` knows selector 393 is superseded and selector 397 is current; the manifest was regenerated and then repaired to preserve historical first-commit metadata that a synthetic local snapshot Git baseline could not reconstruct.

### CA8 — prohibited semantic surfaces untouched

CB25 does not change the seed rule, uniqueness guard, `componentBarriers`, component partition, `seedOrbits`, `edgeOrbitEvidence`, `add_fragment_orbit`, exterior filtering, `is_terminal_slit`, face walk, rotation system, region drafts, CB21 comparison, `proves_cellularity()`, or certificate semantics. No tolerance, fixture recognition, barrier-set change, fallback, or product correction was added.

### CA9 — TB23 discriminator contract

`M3-CP4c-3-TB23` must execute selector 397 artifact-only and report all six review-frozen discriminators. No additional diagnostic CB is authorized after TB23; the following reasoning boundary is independent `M3-CP4c-3-TB23-REV`.

## Static verification

Before remote application:

- `git diff --check` — PASS.
- selector 365 exact bytes — PASS.
- selector 393 exact bytes — PASS.
- selector 397 cardinality — **397**.
- selector 393 is an exact prefix of selector 397 — PASS.
- appended identities — exactly four, listed above.
- forbidden old diagnostic identifiers (`certificate_side_orbit`, projection-faithfulness residual names) — absent from active implementation/test surface.
- `SurfaceCutGraph.cpp` / `SurfaceCutGraph.h` exact bytes versus the source snapshot — unchanged.
- complete work-preservation patch was generated with full-index binary diff, verified by `git apply --check`, emitted to chat, staged in `My Drive/Directional-CI`, applied through the durable Drive patch reusable, and retired from Drive after the successful push.

## Build evidence

### Required pre-package compile

- Exact source: `e12396d471c0754b112a40272a7992020ff49ced`
- Target: `directional_surface_cell_producer_tests`
- Run/job: `33831440291 / 100895129339`
- Result artifact: `9921874264`, `m3-cp4c3-cb25-preflight-result-33831440291`, Actions digest `sha256:137d7e18c958301a6757e96c903d162ae5932c7a5e5e14ea6af0f113a38426e6`
- Log artifact: `9921874608`, Actions digest `sha256:0e26f89e21a97e210f04b132b5afb8eb2e291601afc24ce07e441991b11a2d56`
- Conclusion: **SUCCESS**; mechanics evidence only, not TB input.

### Eight-target authoritative package compile

- Exact source: `e12396d471c0754b112a40272a7992020ff49ced`
- Targets: `directional_core`, `directional_pipeline`, `directional_surface_cell_authority_kernel_tests`, `directional_surface_cell_producer_tests`, `directional_surface_cell_completion_tests`, `directional_surface_cell_validation_tests`, `directional_compiled_api_tests`, `directional_benchmarks`
- Run/job: `33831662949 / 100895799092`
- Result artifact: `9921914679` (`m3-cp4c3-cb25-package-result-33831662949`), provider/download SHA-256 `db346ad93460a20f12315eea984df3fa5bdd054cf5046fb5756d366f444a4fe7`
- Log artifact: `9921915098` (`m3-cp4c3-cb25-package-log-33831662949`), SHA-256 `7eee7b03e48a2301d9e60235d899a696c731826b4b52bb29230cccd33774e5d6`
- GMP/GMPXX: **PASS** — `DIRECTIONAL_ENABLE_GMP=ON`; `exactArithmeticBackend=GMP`; CMake found GMP/GMPXX and the generated link command contains both `libgmpxx.so` and `libgmp.so`
- Runtime boundary: `runtimeExecution=false`
- Conclusion: **SUCCESS** — all eight required targets compiled/linked with `runtimeExecution=false`; internal `SHA256SUMS` verified

## Orchestration-only correction

The first preflight trigger produced no jobs because the temporary caller used an unquoted YAML plain scalar containing `: ` inside a job `if` expression. This was an orchestration-only invalid-workflow failure: no compile or Directional runtime started. The caller was corrected by quoting the complete `if` scalar, parsed locally, SchemaStore-validated by the next run, and then used unchanged for the successful preflight/package builds. This does not consume or alter semantic evidence.

## Next boundary

After package evidence and closeout are complete, the exact successor is **`M3-CP4c-3-TB23-EXEC`**, artifact-only execution of `Architecture_M3_CP4c3_TB23_Artifact_Only_Test_Benchmark_Plan.md`. CB25 itself claims no runtime acceptance. CP4c-3 remains OPEN.
