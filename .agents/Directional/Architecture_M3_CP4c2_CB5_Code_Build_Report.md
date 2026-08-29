# M3-CP4c-2-CB5 Code + Build Report

## Status

**COMPLETE / BUILD GREEN / RUNTIME-FREE / NOT SEMANTICALLY ACCEPTED**

`M3-CP4c-2-CB5` implements R6-REV measures **AD0–AD9** at semantic/test source
`755485865a7cf9c485d754f22b82a41ee151824b`. No Directional runtime, test, benchmark, CLI, discovery/list/help/version command,
fuzzer, or custom runtime input executed. Accepted runtime authority therefore remains CP4c-1 **355/355**; CP4c-2
remains runtime-unaccepted until artifact-only R7 evidence is reviewed.

## Exact source and preservation

The implementation was preserved before remote application as
`Directional__M3-CP4c-2-CB5-SOURCE__base-0050b931ec1a__work-preservation.patch`, SHA-256
`3106b52029f546262e86e734a430e3c31ad213139bfb0d358e5af31f88e6a8c1`, diff-body SHA-256 `40a9eec971fe17691577159c0f876409a26f472dcdbd2e26baa8a3578f94c008`, against exact base
`0050b931ec1a3a62c87b7c8b2c87dd88246fd74e`. Exact-base `git apply --check`, `git diff --check`, and the
frozen-selector guard passed before orchestration.

Those exact bytes were staged through `My Drive/Directional-CI` and applied by durable
`agent-google-drive-reusable.yml`; run/job `33267545221 / 99140191320` was GREEN with `runtimeExecution=false`
and pushed `755485865a7cf9c485d754f22b82a41ee151824b`. Result artifact `9719098241` /
`sha256:26b95e707a4e8c5f0669826aacce5cc0c029bb5117236f50e59493086c6befcd`; log artifact `9719098425` /
`sha256:15c55fadd43a276960d2b90999a5eb311980e937ac556305ce716b1b020cf48a`. The transient Drive staging object
was permanently retired through the owner-authorized Drive control plane after the successful push.

Semantic changed paths are exactly:

1. `include/directional/geometry/SurfaceCutGraph.h`
2. `src/geometry/SurfaceCutGraph.cpp`
3. `src/geometry/GlobalTopologyPlan.cpp`
4. `tests/FieldAlignedCurveNetworkTests.cpp`

No selector, fixture asset, build configuration, `EmbeddedGraphTopology`, actual-complex certificate, AA1 placement,
or unconditional postflight logic changed.

## AD0–AD9 implementation audit

- **AD0 — preserved preconditions.** Frozen selector identities remain byte-identical: 316
  `601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c`, 346
  `20d3b0b1400d5cab6af4a339a858c56fb7fd0359fb995a395dad215b20f3e46a`, 353
  `51ff96d72e1c2c88e9407e99737e42ec9093ea238aaf8b1e45ff2559f71ac6a5`, 355
  `e9d88f1196e412e06424294d6be22b32f01c9671ec5e4de119abd3f2fb5afeaa`, 357
  `b896d0db7f26aeb0f3513418405efdeccbcf84fb6dc971500c6ddac9e364dc70`, and 358
  `6eda3aad83de81fc55d5cd446f80704d604a842f10995789b483291bb64fbe62`.
  `selected_r2_branch=NONE`, `selected_gate=NONE`, `gate_execution_authorized=false`.
- **AD1 — semantic/provenance split.** `SurfaceCutGraph` now publishes `semantic_digest()` separately from
  provenance. `candidate_hash` is unchanged and still consumes `atlasDigest` and `networkDigest`; therefore
  `make_from_candidate` retains the same foreign/tampered-atlas binding strength.
- **AD2 — semantic consumer corrected.** `GlobalTopologyPlan::candidate_semantic_digest` consumes
  `cutGraph.semantic_digest()`. The provenance path continues to consume the full cut-graph provenance hash, and
  the nearby invariant comment now covers both network and cut-graph consumption sites.
- **AD3 — orbit index discharged by proof, not replacement.** `EmbeddedGraphTopology` constructs arc drafts from
  semantic descriptors, totally sorts them, assigns `NetworkArcId` by that sorted rank, and face walking visits
  darts in canonical ID/orientation order. `certificate.faces[*].orbit` is therefore a content-derived canonical
  rank rather than source-row, container, or gauge enumeration. The semantic digest records that proof adjacent
  to the term; no second arc/orbit implementation was introduced.
- **AD4 — term partition audited.** Semantic identity contains source identity, gauge-invariant network semantic
  identity, cut-edge set, and actual-embedded-graph certificate/cut-candidate terms. Atlas identity remains
  provenance-only. No term lacking an invariance argument was newly promoted into semantic identity.
- **AD5 — boundary diagnostics added.** Two non-gating diagnostics exercise the split directly at
  `SurfaceCutGraph`: `SurfaceCutGraph.SemanticDigestIgnoresGaugeRelabelingForTwoRingWitness` and
  `SurfaceCutGraph.SemanticDigestIgnoresGaugeRelabelingForTorusWitness`. Each requires equal semantic digests and
  unequal provenance digests for gauge-equivalent inputs. They were compiled only; R7 owns execution.
- **AD6 — existing authorities preserved.** `EmbeddedGraphTopology`, the actual-complex certificate,
  unconditional immutable postflight, and AA1 snapshot placement are untouched.
- **AD7 — no witness answers encoded.** No witness-name branch, expected-digest table, product constant, or
  fixture-specific success path was added.
- **AD8 — closure deferred to full runtime re-proof.** Compile success grants no closure. R7 must run the full
  accepted 355; R043 requires ordinal 305 green in that run and R044 requires ordinal 310 green in the same run.
- **AD9 — prohibitions respected.** No tamper weakening, selector invention/change, cumulative gate, 357/358,
  D2 runtime, certificate relaxation, barrier/cellularity conflation, immutable-trace subdivision, A2a′ back-read,
  mechanical/C2, or CP4c-3 work occurred.

## Compile/package evidence

Authoritative compile/package run `33267732093` compiled exact source `755485865a7cf9c485d754f22b82a41ee151824b` through the mandatory
GMP reusable and completed GREEN.

### Changed-owner prepackage

- job `99140688058`
- target `directional_surface_cell_producer_tests`
- PASS, `runtimeExecution=false`
- GMP/GMPXX link evidence present; source status clean

### Fresh eight-target package

- job `99141185197`
- package artifact `9719216316` / `sha256:acb43cf0ec79437408c782193ece354eb790d9ae2159eaeb42546546ea20c3fc`
- diagnostic log `9719216455` / `sha256:af03c536bc55f37be90f6f654bb2e944c66a15036920e536a97cb5523b00f7c4`
- packaged source archive `sha256:78ca517ac7b96ee3737d6ae5b277fc4d06e7393c460f4c9585eb35b2541d84cf`
- internal `SHA256SUMS` **28/28 PASS**
- preflight/build exit `0 / 0`; source status clean
- `runtimeExecution=false`, `turnBoundary=Code+Build-only`
- `exactArithmeticBackend=GMP`, `DIRECTIONAL_ENABLE_GMP=ON`
- authoritative generated link command contains both `libgmpxx` and `libgmp`

All eight required targets compiled: `directional_core`, `directional_pipeline`,
`directional_surface_cell_authority_kernel_tests`, `directional_surface_cell_producer_tests`,
`directional_surface_cell_completion_tests`, `directional_surface_cell_validation_tests`,
`directional_compiled_api_tests`, and `directional_benchmarks`.

No produced binary was executed. Packaging only copied binaries/libraries and verified their bytes.

## Accounting and successor

No runtime regression was observed because no runtime was executed; `Regression_Root_Cause_Tracker.md` is unchanged.

- stable accounting **44 events / 14 categories / 30 recurrences**
- `PR8-R043 / M3-CP4c2-R001`: resolved at its former locus; closure pending full 355
- `PR8-R044 / M3-CP4c2-R002`: corrective implementation compiled; runtime closure pending ordinal 310 within full 355
- produced-witness debt **5**
- authoritative M3 packages **64**
- `selected_r2_branch=NONE`, `selected_gate=NONE`, `gate_execution_authorized=false`

Exact successor is artifact-only **`M3-CP4c-2-TB-X2-R7-EXEC`** using immutable package `9719216316`. Its executable
plan is `Architecture_M3_CP4c2_TB_X2_R7_Artifact_Only_Test_Plan.md`. R7 may not rebuild, mutate, repair, run
357/358, run a cumulative gate, benchmark, touch mechanical/C2, or begin CP4c-3.
