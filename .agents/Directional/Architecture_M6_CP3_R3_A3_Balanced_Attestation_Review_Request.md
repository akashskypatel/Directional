# Directional R3 — A3 balanced-transport attestation decision request

**Scope:** Same active `M6-CP3-CB1-ENTRY-R3` Code + Build turn. **Source:** immutable compiled semantic commit `2b7997b80114be1ff270c3e9fada71aa075b0e95`; compile/package run `37837678896`, package artifact `11575903942` SHA-256 `5ab7d05b4ac58561e883fc73948396c0848f2d02adf365e4361857792aa6cad4`. The 28 package manifest entries were independently checked against this package; no Directional executable was run.

## Decisive static observation

`src/geometry/SurfaceCellTracing.cpp`:

- A4-produced HardRail junction authoring, approximately lines **18450–18560**: obtains each nonrail radial A3 step via `FieldTransportAtlas::transition_value(edge, sourceFace, targetFace)`, checks the reverse/inverse, and enforces the typed square `chi_next ∘ phi_A = phi_B ∘ chi_previous`.
- Public `SurfacePhaseFrontProduct::make` validation, approximately lines **7970–8210**: accepts `SourceTopologyRegions`, per-face branch rotations, the independently published hard-*rail* field transitions, and HardRail *route* certificates; **it has no `FieldTransportAtlas` or other independently supplied nonrail A3 edge-transport table.** In its junction loop it validates the star, both chains' edge/face incidence, sector coverage and disjointness, then composes **only the step `firstToSecond` values carried inside the same mutable route certificate** to check the commuting square. It does not compare those nonrail step turns with an independently obtained A3 value.
- Existing focused D2 test `M6CP3.HardRailCrossRegionBranchCertificateStripsEndpointFaceGauge` in `tests/SurfaceCellTransitionQuotientTests.cpp` (~2468 onward) has a **single-step** tamper of one side's `firstToSecond`, checking that `SurfacePhaseFrontProduct::make` rejects. Both of the 3×3 midline source-face radial paths are designed to have at least one step (0→1→4, 3→6→7) if A4 actually produces the route.

## Balanced mutation falsifier (source-level prediction, **not executed**)

Take an otherwise produced D2 route that contains both nonempty side paths. Make an independent `PhaseFrontDraft`, keep all source faces, edge keys, endpoint χ carriers, route identity, and path ordering unchanged. On the first nonrail step in **both** side paths, compose `QuarterTurn::from_integer(1)` into each `firstToSecond`:

```cpp
auto &a = mutatedRoute.junctions.front().sectorPaths[0].front();
auto &b = mutatedRoute.junctions.front().sectorPaths[1].front();
const auto one = authority::QuarterTurn::from_integer(1);
a.firstToSecond = compose(one, a.firstToSecond);
b.firstToSecond = compose(one, b.firstToSecond);
```

Because the turn group is Z4, the two complete side transports become `phi_A + 1` and `phi_B + 1`, and `chi_next + phi_A + 1 == phi_B + 1 + chi_previous` remains true. Structural topology, endpoints and disjoint sectors are identical. There is no independent A3 step comparison in `make` to distinguish this balanced modification from the A4 atlas-derived original. **The expected acceptance is a source-based prediction, not a runtime or static-compiler test verdict.** If rejected by an unobserved elsewhere-enforced invariant, record that counterevidence.

## Why review is needed

RA-37a's reviewed A2 obligation requires every nonrail step to be validated against `FieldTransportAtlas::transition_value` and reverse reciprocity. The **producer A4** already does this. It is not yet explicit whether `SurfacePhaseFrontProduct::make` is required to attest every A3 step *independently of the supplied certificate*, or whether that factory may trust A4-issued values and enforce only self-consistency. The distinction affects how far test drafts and copied/re-published products can be treated as adversarial input. Do **not** silently treat the factory's commuting-square equality as independent A3 attestation, and do **not** strengthen it with global face-gauge equality without reviewed source-domain justification (holonomy/region cuts may make it unsound).

## Required independent decision

1. Confirm the intended trust boundary of `SurfacePhaseFrontProduct::make` for certificates republished from copied/test draft inputs. Is balanced paired-phi tamper required to reject there, or is authoritative A4-only issuance the sole nonforgery guarantee?
2. If the factory **must** reject: define the independent per-nonrail-edge A3 proof input or atlas-bound source authority that `make` can legally consume, and how this survives all `SurfacePhaseFrontProduct::make` copy sites; forbid comparing to a second untrusted copy of the same mutable values as fake independence. Require negative tests for balanced mutation, reversed orientation, and typed source-face-row permutation. Review must authorize schema/interface changes.
3. If the factory **may** trust A4: explicitly document that its sector-square validation proves internal consistency but **not independent A3-value provenance**; adjust the test contract accordingly. A4 `FieldTransportAtlas` equality and reciprocal validation must remain mandatory before publication, including the fail-closed no-transport path.
4. In either case retain the RA-39 endpoint-local χ requirement, nonrail A3 φ sectors and the frozen 497-process Test+Benchmark boundary; do not claim organic D2, D1, D3/D7 or D5 runtime witnesses.

## Decision hold / continuation

No additional schema mutation, intentionally-red test, runtime execution, or successor was performed for this question. Other R3 Code+Build work may continue if independent authority finds it separable; do not claim this specific independent A3 attestation verified before decision. Source and test evidence are available from the exact compiled-source artifact above. Preserve this review request and the active R3 beacon.

## Bounded CB addendum — independently retained A3 producer witness (2026-10-08T21:04Z)

An explicitly separate, **test-only** A3 provenance assertion was authored and applied in existing focused `M6CP3.HardRailCrossRegionBranchCertificateStripsEndpointFaceGauge`. The test now retains the pipeline's diagnostic copy of the original `FieldTransportAtlas` alongside the A4-produced phase-front product and independently compares every D2 nonrail `sectorPaths` step's oriented `firstToSecond` value against `atlas.transition_value(edge, firstFaceRow, secondFaceRow)`, plus reverse reciprocity, for both original and face-row-permuted meshes. Source semantic commit **`cd1b46a4f0c82442f94d6e6a7c678cee90dfe85e`**, Drive apply run `37843865182` successful; code patch SHA256 `5c9d871344af95c02059d95a2dab5ec0f8638fcec545e5f5522462068ace17fe`. This is **not** a proof that the organic A4-produced two-carrier D2 front exists or that the test passes; compile-only validation and future TB are separate.

**Review question remains live.** The diagnostic atlas snapshot is available to a focused test for cross-validation but is not part of `SurfacePhaseFrontProduct::make`'s signature or production inputs. This test validates A4 producer-to-atlas consistency; it does not make the public checked factory independently tamper-proof against balanced paired-phi mutation. Do not confuse test-observation provenance with production authority, introduce a second mutable copy of the same certificate as an oracle, or broaden the constructor's API without an independent decision on its trust contract.

## 2026-10-08 R3 negative-control implementation evidence

Code-only D2 balanced two-sided +1 Z4 tamper diagnostic was committed at e49431df81a3e23dc7870a4e409128dea618d378 and compiled via GMP/GMPXX run 37846303377, package 11580420381, internal 28/28 pass, runtimeExecution=false. Its copied certificate is NOT submitted to SurfacePhaseFrontProduct::make; the check relies on the independently retained A3 atlas. Therefore it demonstrates why commuting-square equality alone cannot prove provenance, but does NOT settle whether make must independently attest producer A3 values. Independent review question remains open.


## RA-39 clarification and decision focus — bounded static audit 2026-10-08T22:02Z

**RA-39 is already ACCEPTED** at `.agents/Directional/Architecture_M6_Frozen_Definitions.md` / `Architecture_M6_CP3_R3_Endpoint_Attachment_Review_Decision.md`. Its endpoint-local crossing is **exactly one oriented terminal carrier**, with no fan detour across spatial endpoints; A3 sector φ paths are the **along-rail** commuting-square witnesses. Current source `d56f57adc184d6180fc2c69087a5340b8e97bcc7` statically implements that *shape* at `include/directional/geometry/SurfaceCellTracing.h:1488–1508`, `src/geometry/SurfaceCellTracing.cpp:18379–18421,8041–8205`, and A5 `src/pipeline/RemeshPipeline.cpp:4964–4999`. **Do not label the endpoint shape unresolved.**

Only the **factory's independent A3 transport provenance** remains undecided: A4 checks real nonrail A3 values at `src/geometry/SurfaceCellTracing.cpp:18476–18513`; public factory `make` has no independent A3 atlas and only checks supplied values for typed incidence and commuting-square equality. The compiled D2 balanced +1,+1 copied mutant checks disagreement against a test-retained atlas but is not passed back through `make`. Choose either A4-trusted authority or new independently bound A3 factory authority after independent Design Review. No runtime claim. Exact detailed audit: ChatGPT Library `/Directional/Evidence/Directional__M6-CP3-CB1-ENTRY-R3__RA39-A3-static-audit-and-review-gate-20261008T2202Z.md` (SHA256 `03e0ac9fb72789f10dd1165537031279391bced0f31741afc3859ec934bd228d`).
