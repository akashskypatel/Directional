# Directional Surface-Cell Reorientation Plan

**Status:** authoritative architecture-migration roadmap  
**Reviewed implementation:** `6af23d9aeca29e63aa13c4ae49f50d1748939c49`  
**Architecture-review planning baseline:** `dfa77fa6bda44b51454f0189d65a97086aaba049`  
**Decision:** **changes required before architecture expansion**  
**Last updated:** 2026-08-10 UTC

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
| Current turn / exact next action | `TODO`, `MILESTONE_G_TODO.md`, `.agents/Directional/Future_Chat_Session_Handoff.md` |
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

Architecture:
M0 preserve immutable evidence [complete]
-> M1 authority kernel and staged production adoption [active]
   M1a authority kernel [accepted]
   M1b first source/provenance consumer [accepted]
   M1c field-transition consumer [accepted]
   M1d phase-front route identity consumer [accepted]
   M1e segment route transport consumer [accepted]
   M1f vertex continuation route transport consumer [accepted]
   M1g periodic holonomy route transport consumer [accepted]
   M1h phase-front field-chart consumer [test-authority remediation compile/package complete; immutable runtime next]
   later bounded M1 consumers [pending]
-> M2 closed outcomes and single-writer snapshots
-> M3 global conformity plan
-> M4 certificate-carrying chart and quotient relations
-> M5 occurrence, embedding, and independent verification split
-> M6 retire legacy representations and decompose ownership modules

Testing:
T0 independent audit and authority separation [complete]
-> T1 independent oracle/package foundation [accepted]
-> T2 complete direct corpus and semantic manifest
-> T3 property/metamorphic generation and shrinking
-> T4 sanitizer fuzzing and minimized replay
-> T5 calibrated representative quality/corpus gates
-> T6 CI, resource, and oracle-adequacy hardening
```

The current implementation remains behavioral comparison authority and migration input only. It is not an approved foundation for feature expansion without the ordered architecture/test gates.

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

Accepted M1d evidence remains folded into the durable handoff and regression tracker.

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

M1e is accepted. Its facts remain folded into the durable handoff and regression tracker.

Authoritative next immutable Test + Benchmark plan:
`.agents/Directional/Architecture_M1h_Phase_Front_Field_Chart_Test_Authority_Remediation_Artifact_Only_Test_Benchmark_Plan.md`.

M1h remediation implementation `32b22d3ee8aa46ba2d1fd149ce04204a4206d0c0` changes only the focused test witness; production remains `de4e2ba7c19d2e49931655dc22d758f50656d054`. Build `31404102605 / 93506073062` is **120/120** with artifacts `9069186973 / 9069187317`, manifest **72/72**, and no runtime execution. Semantic acceptance remains pending.

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

The accepted implementation preserves existing public/raw provenance and matching storage and excludes the separate periodic-holonomy loop, field-chart production, public schema retirement, topology/conformity/quotient work, validation, fallback/recovery expansion, optimization, and G4 repair. Immutable semantic acceptance passed.

### M1f immutable acceptance and M1g selection

M1f selects the next real cumulative transport owner:

`surface_cell_tracing_detail::resolve_vertex_continuation -> ordered source-vertex continuation route`.

Implementation `baed0f24831c476f45a1b742c12314e3fb03e10e` replaces `PathState::matching` unrestricted signed accumulation with checked step authority, `TransitionStep`, `CanonicalRoute`, and typed `GridAutomorphism` composition while preserving route search/ranking and compatibility output. Exact artifact-only validation accepted M1f: producer **190**, focused **6/6**, required-green **175/175**, validation **77/77**, M1a **14/14**, T1 **29/29**, direct products oracle-clean, Bunny known-red preserved, Vase bounded safety-only, and exact postflight clean. Accepted evidence remains in the durable handoff and regression tracker.

The first compile attempt surfaced a namespace-ownership mistake in a new provenance forward declaration. The correction kept the existing anonymous helper untouched and introduced a narrow continuation-owned provenance helper, avoiding unrelated ownership refactoring. Fresh accepted-source inspection selects the separate periodic face-cycle `totalMatching` accumulator as M1g. M1g is representation-only and must preserve current nonzero-rotation `PeriodicHolonomyMismatch` rejection so `G4-B003` remains unresolved.

### M1g immutable acceptance and M1h runtime block

M1g implementation `ee1abbd91d8ab39b84b107bba73ebf7aa0acceb2` remains immutable accepted. M1h production implementation `de4e2ba7c19d2e49931655dc22d758f50656d054` compiled/package successfully at `build_planar_phase_frame -> UniformPhaseFrame::faceChart -> LocalLatticeState::sourceChart`, including the sibling `../test-data` package lookup correction.

Exact M1h runtime from artifact `9066967620` discovered **202** producer tests. Five of six M1h focused contracts passed; all M1g–M1b focused preservation, validation **77/77**, M1a **14/14**, T1 **29/29**, four direct products, package portability, and eight historical/deferred red classes were preserved. Required-green was **186/187** with the same sole M1h failure.

The failure is test-authority, not production behavior: `MultipleOrientationChartsPreserveEstablishedNumbering` assumes all producer charts must appear among accepted lattice-corner occurrences. The fixture independently retains chart domain `{0,1,2}` but samples lattice corners only on `{0,2}`. M1h `RP-01 / RP-05` therefore remains runtime pending until the witness is corrected and a fresh immutable package passes all six contracts.

Current evidence: `.agents/Directional/Architecture_M1h_Phase_Front_Field_Chart_Consumer_Artifact_Only_Test_Benchmark_Report.md`.

Next plan: `.agents/Directional/Architecture_M1h_Phase_Front_Field_Chart_Test_Authority_Remediation_Code_Build_Plan.md`.

Do not advance to another M1 consumer, M2, or G4 repair before corrected M1h immutable acceptance.

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

1. Execute M1 through M6 in order using bounded Code + Build / immutable Test + Benchmark pairs.
2. Code + Build may edit/configure/compile/package but may not execute generated Directional binaries. Test + Benchmark consumes exact artifacts and may not edit source/tests/build/fixtures.
3. Record exact source commit, artifact identity, changed ownership boundary, intended behavior delta, and rollback boundary for every slice.
4. Compatibility adapters are one-way boundaries; new semantic decisions cannot depend on raw legacy integers, hashes, row positions, or copied authority tables.
5. Adopt semantic types only at consumers that own the semantic fact. M1e is the first selected consumer that genuinely owns ordered per-step route transport.
6. A stage either returns its complete semantic product or a typed failure; partial/debug state is not authority.
7. Aggregation may remap representation handles only, never semantic component/region/sheet/route/ownership facts.
8. Validators independently recompute elementary incidence/materialized topology but do not synthesize missing producer certificates.
9. Recursive/retrying/combinatorial paths touched by a slice require one shared work ledger and monotone progress measure.
10. Any regression blocks the next migration slice; diagnose within the current ownership boundary rather than bypassing with fallback or feature work.
11. No validator weakening, expected-output synthesis, fixture-specific branch, proximity weld, recovery substitution, or predicted topology count may satisfy acceptance.
12. Stale per-turn evidence is cleaned under the mandatory handoff policy after its accepted facts are folded into durable/live authority. Durable design/audit/regression documents remain.

## 7. Test interlock

T1 independent oracle/package authority is accepted and is a preservation prerequisite for M1. M1d preserved it exactly. M1e focused transport contracts are accepted and supplemented, rather than replaced, producer accounting, M1d/M1c/M1b/M1a/T1 preservation, direct product oracles, known-red classification, and immutable package postflight. The exact producer accounting is 184 with required-green 169/169.

Later testing work remains T2–T6: direct semantic corpus, property/metamorphic generation, fuzz replay, calibrated quality/corpus gates, and CI/resource/oracle hardening.

## 8. Remaining migration milestones

### M1 — authority kernel and compatibility boundaries

Continue bounded consumers only. M1g periodic-holonomy route transport is immutable accepted without changing cycle discovery, output, or rejection behavior. Fresh accepted-source inspection selects M1h production `FieldChartId` adoption at `build_planar_phase_frame -> UniformPhaseFrame::faceChart -> LocalLatticeState::sourceChart`. M1h remains representation-only; later M1 consumers remain unselected until immutable M1h acceptance.

### M2 — closed producer outcomes and single-writer scope

Replace overlapping attempted/succeeded/disposition state with exhaustive outcomes; introduce immutable source/topology/region authority products; remove consumer-side scope rewriting; separate temporary/public/diagnostic retention.

### M3 — global conformity before regional production

Compute one exact hard-rail breakpoint schedule and certificate before local regions commit cells. Both sides consume the identical ordered schedule; remove post-hoc local pairing as authority.

### M4 — certificate-carrying chart and quotient relations

Publish explicit directed occurrence/transport/quotient relations with verifiable certificates. Validators verify rather than reconstruct them. This owns remaining global-local relation debt behind periodic/G4 capability.

### M5 — occurrence, embedding, and independent verification split

Use explicit occurrences, exact source support, certificate-driven quotient materialization, and independently recomputed elementary source/output incidence.

### M6 — retire legacy representations and decompose ownership modules

After consumers have typed replacements and immutable evidence, retire obsolete parallel raw authority, split oversized ownership modules, and harden diagnostics/resource/CI behavior.

## 9. Product blockers remain separate

Architecture migration does not reinterpret:

- `PR8-R034 / G4-R007` active direct-torus `LocalSheetMismatch`;
- `G4-B002` shared hard-rail scheduling / historical `InvalidHardRailPairing`;
- `G4-B003` nonzero periodic Z4 product capability;
- `G4-B004` positive multi-isolation quotient witness.

Bunny production completion, Vase bounded runtime, prescribed sphere, G5/G6, fallback/recovery, and optimization remain deferred behind prerequisite gates.

## 10. Resume rule

Always read `.agents/Directional/Future_Chat_Session_Handoff.md` first. It owns the exact current turn, artifact, current retained report, cleanup policy, and next plan. If this roadmap conflicts with a newer committed authoritative plan/report, the newer plan/report governs current execution and this roadmap must be corrected before architecture expansion.
