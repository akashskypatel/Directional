# Directional Surface-Cell Reorientation Plan

**Status:** authoritative architecture-migration roadmap  
**Reviewed implementation:** `6af23d9aeca29e63aa13c4ae49f50d1748939c49`  
**Architecture-review planning baseline:** `dfa77fa6bda44b51454f0189d65a97086aaba049`  
**Decision:** **finish one single-authority cutover, validate it immutably, then resume G4 production work**  
**Last updated:** 2026-08-11 UTC

Repository authority: `akashskypatel/Directional`, branch `agent/surface_cell_quad/p5-recover-bridge-healing`, draft PR #8. Keep the PR open, draft, and unmerged throughout this migration.

## 1. Purpose and authority

This plan converts the independent architecture review into an ordered, verifiable migration from the behavioral implementation to the normative architecture in `.agents/Directional/DESIGN.md`.

It owns migration order, dependencies, stop conditions, and acceptance gates. It does not redefine architecture or runtime evidence:

| Concern | Authority |
|---|---|
| Normative product, domains, stages, invariants | `.agents/Directional/DESIGN.md` |
| Findings and scientific comparison | `.agents/Directional/Surface_Cell_Architecture_Independent_Design_Review_Report.md` |
| Normative testing policy | `tests/TESTING_STRATEGY.md` |
| Test audit and T0–T6 redesign | `.agents/Directional/Surface_Cell_Test_Suite_Independent_Audit_And_Redesign_Plan.md` |
| Current turn / exact next action | `TODO.md`, `.agents/Directional/Future_Chat_Session_Handoff.md` |
| Regression history / repeated code shapes | `.agents/Directional/Regression_Root_Cause_Tracker.md` |
| Current immutable evidence | current retained per-turn report |

If this roadmap conflicts with `DESIGN.md`, the design wins and this file must be corrected before implementation. A runtime report may update current status but cannot waive a migration invariant.

## 2. Corrected orientation

Product gates and architecture migration are separate progress axes. Passing a fixture does not close structural debt, and completing a migration slice does not itself pass a product gate.

```text
Product:
G0 truthful authority [accepted baseline]
-> G1 uniform phase-front plane [accepted baseline]
-> G2 cross-chart / close-sheet isolation [accepted baseline]
-> G3 periodic holonomy [accepted baseline]
-> G4 topology-distinct completion and singularities [active]
-> G5 adaptivity and hard features [blocked]
-> G6 bunny and vase production success [blocked]
-> G7 hardening/default-on [blocked]

Architecture transition:
M0 preserve immutable evidence [complete]
-> M1 partial authority slices [accepted evidence]
   M1a authority kernel [accepted]
   M1b first source/provenance consumer [accepted]
   M1c field-transition consumer [accepted]
   M1d phase-front route identity consumer [accepted]
   M1e segment route transport consumer [accepted]
   M1f vertex continuation route transport consumer [accepted]
   M1g periodic holonomy route transport consumer [accepted]
   M1h phase-front field-chart consumer [accepted]
   M1i phase-front cell source-scope consumer [accepted]
   M1j phase-front edge source-scope consumer [accepted]
   M1k phase-front edge topology-region consumer [accepted]
   M1l phase-front cell topology-region consumer [accepted]
-> M1 single-authority contract cutover [selected; Code + Build next]
-> immutable artifact-only M1 validation
-> resume G4 production work
   M2 closed stage products when required by the active product contract
   M3 global conformity plan for shared hard rails
   M4 certificate-carrying chart and quotient relations
   M5 occurrence, embedding, and independent verification
   M6 module boundaries and operational hardening

Testing:
T0 independent audit and authority separation [complete]
-> T1 independent oracle/package foundation [accepted]
-> T2 complete direct corpus and semantic manifest
-> T3 property/metamorphic generation and shrinking
-> T4 sanitizer fuzzing and minimized replay
-> T5 calibrated representative quality/corpus gates
-> T6 CI, resource, and oracle-adequacy hardening
```

The M1l implementation and artifacts remain comparison evidence and the source starting point. They are not a contract to reproduce internal numbering, hashes, row order, or known-incomplete output. After the final cutover passes immutable semantic validation, G4 again becomes the primary work queue.

## 3. Current M1 checkpoint

M1d is immutable accepted at:

`pipeline::build_authoritative_phase_front_mesh -> exact_interior_route_valid`.

Accepted M1d authority:

- implementation `9446fc82d98d336d3bd59c190dd2bbbe94bd2e25`;
- result artifact `9046308272`, SHA-256 `6a9dd880e2e7548b8afc88da48e7ed49935e6ce672ba1af208eee8f84678152c`;
- manifest **59/59**, SHA-256 `e9859b25bd6d3a721484abdae679fcf898a85e1903b176192696d4b6b9e7eef0`;
- producer discovery **178** / required-green **163/163**;
- M1d **6/6**, route witnesses **3/3**;
- M1c **6/6** + transition counterexamples **3/3**;
- M1b **6/6** + validation **77/77**;
- M1a **14/14**, T1 **29/29**;
- Plane/MultiFaceSeam/CloseSheets/Cylinder green and independent-oracle clean;
- Bunny known-red preserved, Vase bounded safety-only;
- exact package postflight preserved.

Accepted M1d evidence remains folded into `.agents/Directional/CHANGELOG.md` and the regression tracker.

M1e is immutable accepted at:

`surface_cell_tracing_detail::segment_on_source -> ordered transition route between consecutive SurfaceTraceSegment attachments`.

Immutable M1e authority:

- implementation `a0330d0107f7d7340e9f8644d26dd6c8b753ff10`;
- build/event `34036600128262e909c377006a056a2b9976f986`;
- build run/job `31351113129 / 93341993183`, **120/120**;
- result artifact `9049125645`, SHA-256 `d16222c62f6f7491eaa830fe22ac4f768b6f426646639f155ccfd8feb9d378f7`;
- log artifact `9049125905`, SHA-256 `fd1d816fd4265f803f6be278941eb7647d056eb6336d05fe98e865621fd5e7be`;
- manifest **61/61**, SHA-256 `36a6377350aa4b58205ccd881a7ee34156800d28e3c5edecf634769289d9e7e5`;
- final product/test scope exactly two paths;
- Code + Build executed no generated Directional binary, discovery, test, or benchmark; immutable runtime subsequently passed M1e **6/6**, producer required-green **169/169**, validation **77/77**, M1a **14/14**, T1 **29/29**, and all four direct required-green products.

M1e is accepted. Its facts remain folded into `.agents/Directional/CHANGELOG.md` and the regression tracker.

M1h is immutable accepted from remediation implementation `32b22d3ee8aa46ba2d1fd149ce04204a4206d0c0` and artifacts `9069186973 / 9069187317`: producer discovery **202**, focused **6/6**, required-green **187/187**, validation **77/77**, M1a **14/14**, T1 **29/29**, four direct products independent-oracle clean, unchanged historical-red classes, Bunny known-red, Vase bounded safety-only, and exact **72/72** postflight. No new stable product regression or recurrence was created.

M1i implementation `b037157921094604f1b0c17f9c8b7076c7604b3b` is immutable accepted at `phase_front_cell_source_scope -> SurfacePhaseFrontCell::{sourceComponent, sourceSheet, sourceIsolationSheets}` from exact artifacts `9072101943 / 9072102331`: producer discovery **208**, focused **6/6**, required-green **193/193**, full M1h-M1b/validation/M1a/T1/direct-product preservation, unchanged historical-red classes, Bunny known-red, Vase bounded safety-only, and exact **72/72** postflight. No new stable product regression or recurrence was created.

Accepted-source inspection selected M1j at `SurfacePhaseFrontCell typed source scope -> SurfaceFrontEdge::{sourceComponent, sourceSheet, sourceIsolationSheets}`. M1j migrated only edge-owned component/sheet authority, kept raw `sourceTopologyRegion` out of scope, and required aggregators to verify rather than recreate semantic source scope. Its consumed per-turn plans/reports were retired under `CLEAN_UP_POLICY.md`; durable implementation, acceptance, and failed-attempt facts are retained in `.agents/Directional/CHANGELOG.md` and the regression tracker.

M1j is immutable accepted. M1k implementation `b9181364926cea840e9cb50da21fe721f33fd874` is likewise immutable accepted from artifact `9079318682` and runtime evidence `9080245848`: producer **220**, focused **6/6**, required-green **205/205**, validation **77/77**, M1a **14/14**, T1 **29/29**, four direct products oracle-clean, historical-red classes unchanged, and exact **68/68** postflight.

M1l implementation `bd140cff4572412e6f4ecd70a6ce0fe85310932c` is immutable accepted at `SurfaceTopologyRegion::id / normalize_scope -> SurfacePhaseFrontCell::sourceTopologyRegion`, with numeric materializer consumers still present at that checkpoint. Exact runtime authority is run/job `31444022339 / 93634344918` from Code + Build artifacts `9083262395 / 9083262833`: producer **226**, M1l **6/6**, required-green **211/211**, validation **77/77**, M1a **14/14**, T1 **29/29**, M1k-M1b preservation green, four direct products independent-oracle clean, eight historical/deferred red classes unchanged, Bunny/Vase dispositions preserved, strict timing truthfully sampled **10/10** while remaining deferred, and exact **56/56** postflight. No new stable product regression or recurrence was created.

The user-authorized architecture review rejects the unimplemented one-field plan. The next turn replaces the complete affected producer-to-consumer authority contracts, deletes the displaced representations in the same turn, validates by compile/package only, and leaves semantic runtime acceptance to the following immutable artifact-only turn.

Current immutable report:
`.agents/Directional/Architecture_M1l_Phase_Front_Cell_Topology_Region_Consumer_Artifact_Only_Test_Benchmark_Report.md`.

Authoritative next Code + Build plan:
`.agents/Directional/Architecture_M1_Single_Authority_Cutover_Code_Build_Plan.md`.

## 4. M1e accepted boundary and M1f selection

M1d intentionally did not introduce `TransitionStep` / `CanonicalRoute` because its consumer validated route identity but did not own per-step transport.

M1e selects a real transport-owning seam:

`surface_cell_tracing_detail::segment_on_source -> ordered transition route between consecutive SurfaceTraceSegment attachments`.

The current code owns an ordered `VertexPathStep` sequence and performs raw:

```text
totalMatching += transition.matching
current.matching = normalized_branch(totalMatching)
```

M1e implementation `a0330d0...` adopts:

- checked `SourceVertexId` / `InteriorTransitionId` step identity;
- canonical `SourceEdgeTopologyKey`;
- `QuarterTurn` + zero-shift `GridAutomorphism` per directed step;
- `TransitionStep` for each observed crossing;
- `CanonicalRoute` for canonical storage while consuming `oriented_steps()` to preserve behaviorally observed order;
- algebraic composition/inverse instead of unrestricted signed matching accumulation.

The accepted implementation preserved the then-existing provenance and matching storage and excluded the separate periodic-holonomy loop, field-chart production, schema replacement, topology/conformity/quotient work, validation, fallback/recovery expansion, optimization, and G4 repair. Immutable semantic acceptance passed. Those exclusions describe the historical slice; they do not constrain the final cutover.

### M1f immutable acceptance and M1g selection

M1f selects the next real cumulative transport owner:

`surface_cell_tracing_detail::resolve_vertex_continuation -> ordered source-vertex continuation route`.

Implementation `baed0f24831c476f45a1b742c12314e3fb03e10e` replaces `PathState::matching` unrestricted signed accumulation with checked step authority, `TransitionStep`, `CanonicalRoute`, and typed `GridAutomorphism` composition while preserving route search/ranking and the then-existing numeric output. Exact artifact-only validation accepted M1f: producer **190**, focused **6/6**, required-green **175/175**, validation **77/77**, M1a **14/14**, T1 **29/29**, direct products oracle-clean, Bunny known-red preserved, Vase bounded safety-only, and exact postflight clean. Accepted evidence remains in `.agents/Directional/CHANGELOG.md` and the regression tracker.

The first compile attempt surfaced a namespace-ownership mistake in a new provenance forward declaration. The correction kept the existing anonymous helper untouched and introduced a narrow continuation-owned provenance helper, avoiding unrelated ownership refactoring. Fresh accepted-source inspection selected the separate periodic face-cycle `totalMatching` accumulator as M1g. M1g was representation-only and preserved current nonzero-rotation `PeriodicHolonomyMismatch` rejection so `G4-B003` remained unresolved.

### Historical M1g-to-M1h test-authority checkpoint

M1g implementation `ee1abbd91d8ab39b84b107bba73ebf7aa0acceb2` remains immutable accepted. M1h production implementation `de4e2ba7c19d2e49931655dc22d758f50656d054` compiled/package successfully at `build_planar_phase_frame -> UniformPhaseFrame::faceChart -> LocalLatticeState::sourceChart`, including the sibling `../test-data` package lookup correction.

The first M1h runtime from artifact `9066967620` discovered **202** producer tests. Five of six M1h focused contracts passed; all M1g–M1b focused preservation, validation **77/77**, M1a **14/14**, T1 **29/29**, four direct products, package portability, and eight historical/deferred red classes were preserved. Required-green was **186/187** with the same sole M1h failure.

The failure was test-authority, not production behavior: `MultipleOrientationChartsPreserveEstablishedNumbering` assumed all producer charts must appear among accepted lattice-corner occurrences. The fixture independently retained chart domain `{0,1,2}` but sampled lattice corners only on `{0,2}`. M1h was subsequently remediated and immutable accepted without changing the production implementation. The stale per-turn M1h report and following M1i plan were retired under `CLEAN_UP_POLICY.md`; their durable facts are retained in `.agents/Directional/CHANGELOG.md` and the regression tracker. Current execution is the final M1 cutover under the handoff and `TODO.md`.

## 5. Required target-stage corrections

The migration must reverse consumer reconstruction: each stage writes one immutable semantic product; later stages consume or verify it without repairing, overwriting, or rediscovering meaning.

| Target stage | Required correction | Migration |
|---|---|---|
| A0 source authority | one immutable source snapshot and tagged exact source support | M1, M2, M5 |
| A1 field transport | typed chart, grid automorphism, transition, and route authority | M1 |
| A2 topology plan | one global topology plan; no downstream semantic reconstruction | M2, M4 |
| A3 conformity plan | one verified shared hard-rail schedule before regional commits | M3 |
| A4 local construction | immutable region authority; aggregation validates/remaps only | M2, M3 |
| A5 occurrence complex | explicit corner occurrences and directed-side relations | M4, M5 |
| A6 quotient/materialization | verified relation registry and exact-once quotient consumption | M4, M5 |
| A7 embedding | source geometry bound through shared exact support kernel | M5 |
| A8 verification | independent certificate/incidence verification, never topology repair | M4, M5 |
| A9 diagnostics/export | derived non-authoritative diagnostics with explicit retention | M2, M6 |

## 6. Migration execution rules

1. Finish M1 in the single cutover defined by the authoritative next plan. After immutable M1 acceptance, return to G4; implement M2–M5 as complete vertical production contracts when required by the active product blocker.
2. Code + Build may edit/configure/compile/package but may not execute generated Directional binaries. Test + Benchmark consumes exact artifacts and may not edit source/tests/build/fixtures.
3. Record exact source commit, artifact identity, changed ownership boundary, intended behavior delta, and rollback boundary for every slice.
4. Checked construction occurs at raw mesh/container ingress. Numeric projection is permitted only at direct container/Eigen access or derived export encoding and may not feed another semantic decision.
5. A contract replacement migrates its producer, storage, equality/order/hash, verifier, materializer, lineage, and tests together, then deletes the displaced fields and helpers.
6. A stage either returns its complete semantic product or a typed failure; partial/debug state is not authority.
7. Aggregation may remap representation handles only, never semantic component/region/sheet/route/ownership facts.
8. Validators independently recompute elementary incidence/materialized topology but do not synthesize missing producer certificates.
9. Recursive/retrying/combinatorial paths touched by a slice require one shared work ledger and monotone progress measure.
10. Any regression blocks the next migration slice; diagnose within the current ownership boundary rather than bypassing with fallback or feature work.
11. No validator weakening, expected-output synthesis, fixture-specific branch, proximity weld, recovery substitution, or predicted topology count may satisfy acceptance.
12. Stale per-turn evidence is cleaned under `.agents/Directional/CLEAN_UP_POLICY.md` after its necessary facts are folded into the changelog, trackers, current authority, or other retained durable records. Durable design/audit/regression documents remain.

## 7. Test interlock

T1 independent oracle/package authority is accepted and is a preservation prerequisite for the final cutover. The entering M1l artifact discovered producer **226** with required-green **211/211**, validation **77/77**, M1a **14/14**, and T1 **29/29**. The cutover may change representation-facing test names/counts; the following artifact-only turn must discover the actual inventory and preserve semantic authority rather than enforce a predeclared total.

Later testing work remains T2–T6: direct semantic corpus, property/metamorphic generation, fuzz replay, calibrated quality/corpus gates, and CI/resource/oracle hardening.

## 8. Remaining architecture contracts

### M1 — single-authority cutover

M1a through M1l remain immutable accepted evidence. The authoritative next plan finishes the current partial transition in one Code + Build turn: checked ID ingress; one topology-region product; complete certificate typing; single chart/support/route/periodic transport contracts; exhaustive producer outcome; deletion of displaced fields/helpers; compile/package only. M1 closes only after the separate immutable Test + Benchmark turn passes semantic gates and the static duplicate-authority audit.

### M2 — remaining closed stage products and single-writer scope

For any producer outside the M1 cutover that still exposes overlapping state or copied scope, replace the complete stage contract when the active product work reaches it. This is implementation work within the owning product gate, not another representation campaign.

### M3 — global conformity before regional production

Compute one exact hard-rail breakpoint schedule and certificate before local regions commit cells. Both sides consume the identical ordered schedule; remove post-hoc local pairing as authority.

### M4 — certificate-carrying chart and quotient relations

Publish explicit directed occurrence/transport/quotient relations with verifiable certificates. Validators verify rather than reconstruct them. This owns remaining global-local relation debt behind periodic/G4 capability.

### M5 — occurrence, embedding, and independent verification split

Use explicit occurrences, exact source support, certificate-driven quotient materialization, and independently recomputed elementary source/output incidence.

### M6 — module boundaries and operational hardening

Split oversized ownership modules and harden diagnostics, resource accounting, packaging, and CI after the owning product contracts are correct. M6 must not be used to defer deletion required by an earlier contract replacement.

## 9. Product blockers remain separate

Architecture migration does not reinterpret:

- `PR8-R034 / G4-R007` active direct-torus `LocalSheetMismatch`;
- `G4-B002` shared hard-rail scheduling / historical `InvalidHardRailPairing`;
- `G4-B003` nonzero periodic Z4 product capability;
- `G4-B004` positive multi-isolation quotient witness.

Bunny production completion, Vase bounded runtime, prescribed sphere, G5/G6, fallback/recovery, and optimization remain deferred behind prerequisite gates.

## 10. Resume rule

Always read `.agents/Directional/Future_Chat_Session_Handoff.md` first. It owns the exact current turn, current retained report, and next plan. Repository-side cleanup and evidence retirement are governed by `.agents/Directional/CLEAN_UP_POLICY.md` and `.agents/Directional/RETENTION_POLICY.md`. If this roadmap conflicts with a newer committed authoritative plan/report, the newer plan/report governs current execution and this roadmap must be corrected before architecture expansion.
