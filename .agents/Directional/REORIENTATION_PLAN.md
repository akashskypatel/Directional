# Directional Surface-Cell Reorientation Plan

**Status:** authoritative architecture-migration roadmap  
**Reviewed implementation:** `6af23d9aeca29e63aa13c4ae49f50d1748939c49`  
**Architecture-review planning baseline:** `dfa77fa6bda44b51454f0189d65a97086aaba049`  
**Decision:** **changes required before architecture expansion**  
**Last updated:** 2026-08-10 UTC

Repository authority: `akashskypatel/Directional`, branch `agent/surface_cell_quad/p5-recover-bridge-healing`, draft PR #8. Keep the PR open, draft, and unmerged.

## Architecture/product axes

```text
Product: G0 [accepted] -> G1 [accepted] -> G2 [accepted] -> G3 [accepted]
         -> G4 topology-distinct completion/singularities [active]
         -> G5 adaptivity/features -> G6 Bunny/Vase -> G7 hardening

Architecture: M0 evidence [complete]
 -> M1 typed authority adoption [active]
    M1a [accepted] -> M1b [accepted] -> M1c [accepted] -> M1d [accepted]
    -> M1e segment route transport [compile/package complete; immutable runtime next]
    -> later bounded M1 consumers
 -> M2 closed outcomes/single-writer snapshots
 -> M3 global conformity
 -> M4 certificate-carrying relations
 -> M5 occurrence/embedding/independent verification
 -> M6 retire legacy representations/decompose ownership

Testing: T0 audit [complete] -> T1 independent oracle/package [accepted]
         -> T2 direct semantic corpus -> T3 property/shrinking
         -> T4 sanitizer fuzz/replay -> T5 calibrated quality
         -> T6 CI/resource/oracle hardening
```

Product and architecture progress remain separate: an architecture slice does not close G4, and one product fixture does not close structural findings.

## Current M1e checkpoint

Selected consumer: `surface_cell_tracing_detail::segment_on_source -> ordered transition route between consecutive SurfaceTraceSegment attachments`.

M1e compile/package authority:

- implementation `bb9cb63a36b64fe2f7c462ad864492c8352b65e8`;
- result artifact `9047295489`, SHA-256 `74e5a1abe37d14c5cdf8a13b753b3f70b80b6a61d83ec051d3b8e4d44b8b8e9f`;
- logs `9047295703`, SHA-256 `9df806949994145dba689b58afcc49106cedd1aadafbff409d70705188400f52`;
- manifest **61/61**, SHA-256 `ae82db8c02575926fe28ede2cbd6a4738cf7ed4e7ae1576ce8778970c532bc8e`;
- Release/static/Ninja **120/120**, 8:08.51 wall, 1,848,636 KiB peak RSS;
- `runtimeExecution=false`;
- six route-composition contracts compiled;
- expected immutable producer discovery **184**, required-green **169**.

Current report: `.agents/Directional/Architecture_M1e_Segment_Route_Transport_Consumer_Code_Build_Report.md`.
Next turn: `.agents/Directional/Architecture_M1e_Segment_Route_Transport_Consumer_Artifact_Only_Test_Benchmark_Plan.md`.

M1e replaces raw cumulative signed matching at a genuine transport owner with checked source/transition IDs, canonical source-edge identity, per-step `QuarterTurn` + zero-shift `GridAutomorphism`, `TransitionStep`, `CanonicalRoute`, observed-direction recovery through `oriented_steps()`, typed composition, and raw matching only at the final compatibility boundary.

It does not migrate periodic holonomy accumulation, production `FieldChartId`, public schemas, topology/conformity/quotient ownership, validators, fallback/recovery, optimization or G4 behavior.

The first implementation attempt was compile-red due to incorrect grid-automorphism API use and was corrected before runtime. Two temporary v2 workflow attempts produced no jobs. These are not stable runtime regression events.

## Migration execution rules

1. Execute M1–M6 in order using bounded Code + Build / immutable Test + Benchmark pairs.
2. Code + Build may edit/configure/compile/package but may not execute generated Directional binaries; TB may not edit/rebuild the artifact.
3. Record exact source/artifact authority and changed ownership boundary for every slice.
4. Compatibility adapters are one-way boundaries; raw integers/hashes/row positions cannot become new semantic authority.
5. Adopt semantic types only at consumers that own the fact.
6. A stage returns a complete semantic product or typed failure; debug partial state is not product authority.
7. Aggregation may remap representation handles only, not rewrite semantic scope.
8. Validators verify elementary incidence/certificates; they do not synthesize missing producer semantics.
9. Touched recursive/retrying work needs one global monotone work ledger.
10. Any required-green regression blocks advancement.
11. No validator weakening, synthetic output, fixture-specific branch, generic recovery, or predicted count may satisfy acceptance.
12. Stale per-turn evidence is cleaned under the durable handoff policy after necessary facts are folded into durable/live authority.

## Remaining target corrections

- **M1:** finish bounded typed authority consumers; no next consumer selected until M1e immutable acceptance.
- **M2:** closed producer outcomes, immutable source/topology/region snapshots, remove semantic scope rewriting.
- **M3:** one exact global hard-rail/conformity schedule before regional production.
- **M4:** producer-owned certificate-carrying chart/quotient relation registry; validator verifies, does not reconstruct.
- **M5:** explicit occurrences, exact source support, certificate-driven materialization and independent incidence verification.
- **M6:** retire obsolete raw parallel authority and decompose ownership modules only after typed replacement evidence.

Possible later M1 candidates include the real periodic-holonomy transport owner and production `FieldChartId`, but neither is pre-approved merely because the type exists.

## Test interlock

T1 is a mandatory preservation authority. The M1e immutable turn must require producer **184**, required-green **169/169**, M1e **6/6**, vertex-fan **2/2**, M1d/M1c/M1b/M1a/T1 preservation, four direct independent-oracle cases, nine explicit historical/deferred reds, Bunny known-red, Vase bounded safety-only and exact postflight.

T2–T6 remain pending broader corpus/property/fuzz/quality/CI work.

## Product blockers remain separate

M1 migration does not reinterpret or close:

- `PR8-R034 / G4-R007` direct torus `LocalSheetMismatch`;
- `G4-B002` shared hard-rail scheduling / historical `InvalidHardRailPairing`;
- `G4-B003` nonzero periodic Z4 production capability;
- `G4-B004` positive multi-isolation quotient witness.

Bunny production completion, Vase production success, prescribed sphere, G5/G6, fallback/recovery and optimization remain deferred behind prerequisite gates.

## Resume rule

Read `.agents/Directional/Future_Chat_Session_Handoff.md` first. It owns the exact current turn, artifact, cleanup policy and next plan. If a newer authoritative current report/plan conflicts with this roadmap, the newer current evidence governs execution and this roadmap must be corrected before architecture expansion.
