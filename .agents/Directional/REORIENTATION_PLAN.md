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
| Current evidence | current retained per-turn report |

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
   M1e segment route transport consumer [compile/package complete; immutable runtime next]
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

M1d remains immutable accepted. M1e is now compile/package complete at:

`surface_cell_tracing_detail::segment_on_source -> ordered transition route between consecutive SurfaceTraceSegment attachments`.

M1e compile authority:

- final implementation `bb9cb63a36b64fe2f7c462ad864492c8352b65e8`;
- result artifact `9047295489`, SHA-256 `74e5a1abe37d14c5cdf8a13b753b3f70b80b6a61d83ec051d3b8e4d44b8b8e9f`;
- log artifact `9047295703`, SHA-256 `9df806949994145dba689b58afcc49106cedd1aadafbff409d70705188400f52`;
- manifest **61/61**, SHA-256 `ae82db8c02575926fe28ede2cbd6a4738cf7ed4e7ae1576ce8778970c532bc8e`;
- Release/static/Ninja **120/120**;
- build wall **8:08.51**, peak RSS **1,848,636 KiB**;
- `runtimeExecution=false`;
- exactly six M1e route-composition contracts compiled;
- expected following producer discovery **184**, required-green **169**.

Current retained Code + Build evidence:
`.agents/Directional/Architecture_M1e_Segment_Route_Transport_Consumer_Code_Build_Report.md`.

The authoritative next turn is immutable M1e validation under:
`.agents/Directional/Architecture_M1e_Segment_Route_Transport_Consumer_Artifact_Only_Test_Benchmark_Plan.md`.

Compile success does not accept M1e semantics.

## 4. M1e rationale and implemented boundary

M1d intentionally did not introduce `TransitionStep` / `CanonicalRoute` because its consumer validated route identity but did not own per-step transport. M1e selected a real transport-owning seam whose legacy code accumulated raw signed matchings across an ordered `VertexPathStep` sequence.

The compiled M1e correction now adopts:

- checked `SourceVertexId` / `InteriorTransitionId` step identity;
- canonical `SourceEdgeTopologyKey`;
- `QuarterTurn` + zero-shift `GridAutomorphism` per directed step;
- `TransitionStep` for each observed crossing;
- `CanonicalRoute` for canonical storage while consuming `oriented_steps()` to preserve behaviorally observed order;
- algebraic automorphism composition instead of unrestricted signed cumulative matching;
- raw `current.matching` only as final compatibility output.

Existing ordered raw topology/provenance, effort, transition resolution, route discovery and the explicit legacy transition path are preserved. M1e excludes the periodic-holonomy loop, field-chart production, public schema retirement, topology/conformity/quotient work, validation, fallback/recovery expansion, optimization, and G4 repair.

The first implementation attempt was compile-red because it passed `Eigen::Vector2i` where `GridAutomorphism` requires `LatticeTranslation` and qualified a hidden-friend `compose`. That was corrected inside the same Code + Build turn before any generated runtime. Two later v2 workflow syntax attempts created no jobs. None is a stable runtime regression event.

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
12. Stale per-turn evidence is cleaned under the mandatory handoff policy after its necessary facts are folded into durable/live authority.

## 7. Test interlock

T1 independent oracle/package authority is accepted and is a preservation prerequisite for M1. M1d preserved it exactly. M1e compile/package statically preserves the accepted authority files and adds six focused transport contracts, but no runtime claim is accepted yet.

The following immutable turn must require exact producer discovery **184**, required-green **169/169**, M1e **6/6**, ordered vertex-fan **2/2**, M1d/M1c/M1b/M1a/T1 preservation, four direct independent-oracle cases, all nine explicit historical/deferred reds, Bunny known-red, Vase bounded safety-only, and exact package postflight.

Later testing work remains T2–T6: direct semantic corpus, property/metamorphic generation, fuzz replay, calibrated quality/corpus gates, and CI/resource/oracle hardening.

## 8. Remaining migration milestones

### M1 — authority kernel and compatibility boundaries

Do not select another M1 consumer until M1e is immutable accepted. After acceptance, inspect remaining real semantic owners before choosing another bounded slice. The periodic-holonomy transport loop and production `FieldChartId` adoption remain possible later M1 candidates, not pre-approved changes.

### M2 — closed producer outcomes and single-writer scope

Replace overlapping attempted/succeeded/disposition state with exhaustive outcomes; introduce immutable source/topology/region authority products; remove consumer-side scope rewriting; separate temporary/public/diagnostic retention.

### M3 — global conformity before regional production

Compute one exact hard-rail breakpoint schedule and certificate before local regions commit cells. Both sides consume the identical ordered schedule; remove post-hoc local pairing as authority.

### M4 — certificate-carrying chart and quotient relations

Publish explicit directed occurrence/transport/quotient relations with verifiable certificates. Validators verify rather than reconstruct them.

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

Always read `.agents/Directional/Future_Chat_Session_Handoff.md` first. It owns the exact current turn, artifact, retained report, cleanup policy, and next plan. If this roadmap conflicts with a newer committed authoritative plan/report, the newer plan/report governs current execution and this roadmap must be corrected before architecture expansion.
