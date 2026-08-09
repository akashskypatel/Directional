# Directional Surface-Cell Reorientation Plan

**Status:** authoritative architecture-migration roadmap  
**Reviewed implementation:** `6af23d9aeca29e63aa13c4ae49f50d1748939c49`  
**Architecture-review planning baseline:** `dfa77fa6bda44b51454f0189d65a97086aaba049`  
**Decision:** **changes required before architecture expansion**  
**Last updated:** 2026-08-09 UTC

Repository authority: `akashskypatel/Directional`, branch `agent/surface_cell_quad/p5-recover-bridge-healing`, draft PR #8. Keep the PR open, draft, and unmerged throughout this migration.

## 1. Purpose and authority

This plan converts the independent architecture review into an ordered, verifiable migration from the current behavioral implementation to the normative architecture in `.agents/Directional/DESIGN.md`.

It owns migration order, dependencies, stop conditions, and acceptance gates. It does not redefine architecture or runtime evidence:

| Concern | Authority |
|---|---|
| Normative product, domains, stages, and invariants | `.agents/Directional/DESIGN.md` |
| Findings and scientific comparison | `.agents/Directional/Surface_Cell_Architecture_Independent_Design_Review_Report.md` |
| Normative testing policy | `tests/TESTING_STRATEGY.md` |
| Test-audit findings and T0–T6 redesign | `.agents/Directional/Surface_Cell_Test_Suite_Independent_Audit_And_Redesign_Plan.md` |
| Current turn and exact next action | `TODO`, `MILESTONE_G_TODO.md`, and `.agents/Directional/Future_Chat_Session_Handoff.md` |
| Regression history and repeated code shapes | `.agents/Directional/Regression_Root_Cause_Tracker.md` |
| Immutable build/runtime evidence | the applicable dated plan and report |

If this roadmap conflicts with `DESIGN.md`, the design wins and this file must be corrected before implementation. A dated runtime report may update current status, but it cannot waive a migration invariant.

## 2. Corrected orientation

Product gates and architecture migration are separate progress axes. Passing a fixture does not close structural debt, and completing a migration slice does not by itself pass a product gate.

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
   M1d phase-front route identity consumer [Code + Build complete; immutable runtime pending]
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

The current implementation is behavioral comparison authority and migration input only. It is not an approved foundation for feature expansion without the ordered architecture/test gates.

## 3. Current M1d checkpoint

The authoritative next turn is:

`.agents/Directional/Architecture_M1d_Phase_Front_Route_Identity_Consumer_Artifact_Only_Test_Benchmark_Plan.md`.

M1d implementation `9446fc82d98d336d3bd59c190dd2bbbe94bd2e25` migrates only:

`pipeline::build_authoritative_phase_front_mesh -> exact_interior_route_valid`

The consumer now establishes existing route identity through checked `SourceVertexId`, canonical `SourceEdgeTopologyKey`, and checked `InteriorTransitionId` while preserving the public packed route representation. It deliberately does not manufacture `TransitionStep`/`CanonicalRoute` because it does not own per-step transport.

Immutable build authority:

- result artifact `9046308272`, SHA-256 `6a9dd880e2e7548b8afc88da48e7ed49935e6ce672ba1af208eee8f84678152c`;
- log artifact `9046308461`, SHA-256 `4813676a45370644fce64854d430822b86a0e406e9446a7ea3159c8fb23d315c`;
- recursive manifest **59/59**, SHA-256 `e9859b25bd6d3a721484abdae679fcf898a85e1903b176192696d4b6b9e7eef0`;
- Release/static/Ninja compile **120/120**;
- generated runtime execution **false**.

M1d remains unaccepted until the exact artifact proves focused route semantics, existing counterexamples, producer discovery/accounting, M1c/M1b/M1a/T1 preservation, direct required-green products, explicit known-red dispositions, and postflight package immutability.

## 4. Required target-stage corrections

The migration must reverse consumer reconstruction: each stage writes one immutable semantic product; later stages consume or verify it without repairing, overwriting, or rediscovering its meaning.

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

## 5. Migration execution rules

1. Execute M1 through M6 in order using bounded Code + Build / immutable Test + Benchmark pairs.
2. Code + Build may edit/configure/compile/package but may not execute generated Directional binaries. Test + Benchmark consumes exact artifacts and may not edit source/tests/build/fixtures.
3. Record exact source commit, artifact identity, changed ownership boundary, intended behavior delta, and rollback boundary for every slice.
4. Compatibility adapters are one-way boundaries; new semantic decisions cannot depend on raw legacy integers, hashes, row positions, or copied authority tables.
5. Do not invent semantic facts merely to adopt a target type. `TransitionStep`/`CanonicalRoute` belong only at consumers that own per-step transport.
6. A stage either returns its complete semantic product or a typed failure; partial/debug state is not authority.
7. Aggregation may remap representation handles only, never semantic component/region/sheet/route/ownership facts.
8. Validators independently recompute elementary incidence/materialized topology but do not synthesize missing producer certificates.
9. Recursive/retrying/combinatorial paths touched by a slice require one shared work ledger and monotone progress measure.
10. Any regression blocks the next migration slice; diagnose within the current ownership boundary rather than bypassing with fallback or feature work.
11. No validator weakening, expected-output synthesis, fixture-specific branch, proximity weld, recovery substitution, or predicted topology count may satisfy acceptance.

## 6. Test interlock

T1 independent oracle/package authority is accepted and is a preservation prerequisite for M1. Later testing work remains:

- T2 complete direct corpus/semantic manifest;
- T3 property/metamorphic generation and shrinking;
- T4 sanitizer fuzzing/minimized replay;
- T5 calibrated quality/corpus gates;
- T6 CI/resource/oracle-adequacy hardening.

Known-red direct intent remains visible and cannot be counted as accepted regression-preservation evidence.

## 7. Remaining migration milestones

### M1 — authority kernel and compatibility boundaries

Continue with bounded consumers only. Each adoption must type authority actually owned by that consumer and preserve legacy public representation until immutable evidence supports retirement.

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

## 8. Product blockers remain separate

Architecture migration does not reinterpret:

- `PR8-R034 / G4-R007` active direct-torus `LocalSheetMismatch`;
- `G4-B002` shared hard-rail scheduling / historical `InvalidHardRailPairing`;
- `G4-B003` nonzero periodic Z4 product capability;
- `G4-B004` positive multi-isolation quotient witness.

Bunny production completion, Vase bounded runtime, prescribed sphere, G5/G6, fallback/recovery, and optimization remain deferred behind their prerequisite gates.

## 9. Resume rule

Always read `.agents/Directional/Future_Chat_Session_Handoff.md` first. It owns the exact current turn, commit, artifact, plan, and procedure. If this roadmap conflicts with a newer committed authoritative plan/report, the newer plan/report governs current execution and this roadmap must be corrected before architecture expansion.
