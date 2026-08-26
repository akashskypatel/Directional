# M3-CP4c-0-CB4 Code + Build Report

## Status

**COMPLETE / BUILD GREEN.** This was a Code + Build turn only. No generated Directional executable, runtime test, benchmark, discovery/listing command, `ctest`, CLI/GUI entry point, fuzzer, help/version command, or custom runtime input was executed.

The independent TB-R3 review adjudicated both reds as **test-side defects** and authorized **no production-source change**. CB4 implements measures G0–G8 on test/oracle/diagnostic surfaces only.

## Exact authority and evidence — G7

- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`
- Final semantic source SHA: `de291a17d5e9bfb6f54918660320ecfa1d521be4`
- Initial CB4 test commit: `76c38686f6f79617477dd39b5f70e330143ed47f`
- Surgical compile-fix commit: `de291a17d5e9bfb6f54918660320ecfa1d521be4`
- Authoritative compile workflow event/control SHA: `baf7ed2ea9381ad47b3ae807d00d61bee0f0dcfe`
- Authoritative compile run/job: `32926004147 / 98048909565` — **GREEN**
- Immutable result artifact: `9591540182`
- Artifact ZIP SHA-256: `8a93b553df337bc8ad952e6a5b348a3eaac8b2304b50c1402f5184a8ce4c561f`
- Diagnostic/activity artifact: `9591540458`, ZIP SHA-256 `c8dbd669318a365db260c2081bba5eeca3b6b297694f6c74800d145901f38755`
- Internal self-excluding `SHA256SUMS`: **27/27 PASS**
- Embedded semantic source archive: `source-de291a17d5e9bfb6f54918660320ecfa1d521be4.tar.gz`, SHA-256 `6077902a83b88d1ef839ab6d2bc285050f0c059511a71c9125b0324383d69a32`
- `runtimeExecution=false`; all packaged source-status records are empty/clean.

All eight standard targets compiled and linked: `directional_core`, `directional_pipeline`, authority-kernel tests, producer tests, completion tests, validation tests, compiled-API tests, and benchmarks.

An earlier compile-only run `32925647275 / 98047893444` exposed one mechanical test-helper error: `SourceEdgeTopologyKey::from_indices` returns `DomainResult<T>`, so two `*edge` uses did not compile. The correction changed only those accesses to `edge.value()`. No semantic production/test expectation was weakened, and the authoritative run above is the corrected build evidence.

## G0 — frozen authority preserved

The CP4c-0 selector is byte-for-byte unchanged at **338 unique, non-empty identities**:

- full 338 SHA-256: `d588cae09067de6914aa1cb917716b11bae01e9f3b45910dbe0faa7d0c7a8116`
- accepted first-316 prefix: `601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c`
- prior first-328 prefix: `cf93622ea8807b26037d2fb6305adf721a23724bc519886c455e98c49c5f3600`

No selector identity was reordered, replaced, appended, or normalized. T6, Q8, accepted expectations, the prescribed-sphere fixture, `kBranchTopologyTolerance`, and E2–E6 semantics remain unchanged. No `src/` or `include/` file changed in CB4.

## G1 — ordinal 333 reaches a DCEL-valid witness

`ExactVertexSectorUsesPublishedDirectionAcrossLossyRoundTrip` now screens the Gram determinant **before** mesh construction and constructs two triangles sharing an interior edge instead of a single pure-boundary triangle. The original falsification remains intact: a witness is required where the lossy `double` round trip recovers `beta > 0` while the published exact direction has the opposite sign, and the test still requires `direction_in_vertex_sector(...) == false`. No exception catch, tolerance, or expectation weakening was added.

## G2/G6 — ordinal 334 uses transported branch authority

`ExactVertexSectorPartitionsAcceptedInteriorFans` now walks a complete oriented vertex fan and carries each starting branch through the atlas-published `signedLift`. Each face is tested against its **corresponding transported branch**, and all four starting branches must admit exactly one face. The test also requires the transported branch to close after the regular fan circuit. A local comment records the retired premise: `FieldBranch` is per-face gauged and its numeric value cannot be reused across faces.

## G3 — independent local-holonomy coverage

`ResolvedBranchCorrection.FieldBranchTransportLocalHolonomyMatchesVertexIndex` was added as an independent gauge check. It requires composed `signedLift == 0 (mod 4)` around the regular four-triangle fan and `signedLift == stored index (mod 4)` around each of the prescribed sphere's eight index-1 singularities. This compiles independently of ordinal 334's sector-admission oracle.

## G4 — supplemental seed-provenance falsifier de-encoded

`TracingPathNeverPublishesSeedIdentityAsFailureLocus` no longer asserts that the prescribed sphere must fail. It first constructs an `InvalidNetworkTerminalOwnership` failure whose existence is controlled by the test and unconditionally checks that seed vertex/singularity stay in `traceSeed*` provenance rather than failure-locus fields. The live sphere branch is now conditional: if a failure exists, it checks the same provenance property without encoding failure existence as expected output.

## G5 — sphere A2a outcome is always observable, non-gating

Added `ResolvedBranchCorrection.PrescribedSphereA2aOutcomeIsAlwaysPublishedNonGating`. It always emits a record carrying `credit=none` and `owningMeasure=G5`. On rejection it prints `network_error_locus(error)`; on success it prints trace count and terminal-event counts by kind. It contains no unconditional `FAIL()` and is deliberately outside the frozen 338 selector.

## G8 — successor TB-R4 plan

The durable successor plan is `Architecture_M3_CP4c0_CB4_Artifact_Only_Test_Benchmark_Plan.md`. It preserves F6 continue-and-observe and follows the independent review's sequence: unchanged 338 selector, the two mandatory F3 supplemental falsifiers, then the G5 non-gating diagnostic. Q8 is creditable only after exact package integrity, **338/338**, and supplemental **2/2**. The plan records P4 explicitly: **Q8 is expected to fail** because the TB-R3 sphere did not publish a network; the G5 rejection/outcome record is therefore a required diagnostic value of this cycle, not gate credit.

## Disposition

`M3-CP4c-0-CB4` is **COMPLETE / BUILD GREEN**. This turn claims compile/package evidence only. Latest accepted runtime remains CP4ab **316/316**; CP4c-0 remains open until artifact-only TB-R4 consumes immutable package `9591540182` under the frozen gate and Q8 rules.

**Exact next:** `M3-CP4c-0-TB-R4` — artifact-only Test + Benchmark. No implementation repair or later-checkpoint work is authorized before that evidence is interpreted.
