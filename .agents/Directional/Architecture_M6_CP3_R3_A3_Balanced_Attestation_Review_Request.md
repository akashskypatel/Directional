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
