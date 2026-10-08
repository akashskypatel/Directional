# M6-DEFN-R5-R1 — CP3 Entry Recovery Definition Record

**Type:** runtime-free Definition; **status:** candidate for mandatory `M6-DEFN-R5-R1-REV`, not implementation authority until accepted. **Source snapshot:** `46717738454a96ab9a379a995eb903939e7a9413` (`37711596951`, artifact `11521898273`, verified SHA-256 `7eb49a71de37808918309fc79ca810d4c471862a5d9119554f43a3a0d3adb187`). **Predecessor:** RA-32, `M6-CP3-TB1-ENTRY-R1-REV` rejected `482/497`; stable **63 / 17 / 46**, debt **1**. This is source inspection, **not** a new runtime or a claim of a proven organic witness.

## 0. Evidence and non-negotiable boundary

`Architecture_M6_CP3_TB1_Entry_R1_Review_Record.md:25-45` classifies the five Definition obligations; `:53-63` holds R2/CB2 until Review. All source locations below refer to the **exact** source snapshot above. Do not edit any source, test, fixture, frozen selector, build, reusable workflow, optimizer or final validator in this Definition turn. No recovery, fallback, tolerance relaxation or hand-built relation record may establish a positive witness. Frozen entry gate remains **30 + 12 + 449 + 6 = 497** fresh exact-filter processes, zero skips and zero benchmark runs; identity names/order unchanged.

## D1 — certified OrdinaryFront isolation-seam discriminator (R1 P2)

**Evidence.** `src/pipeline/RemeshPipeline.cpp:5391-5434` currently chooses `crossSheetSeam` from equal `collinearEdge` and *unequal* `interiorBinding.sheet` **before** seeing certificate authority. This is the RA-32 domain conflation. A5 evidence is assembled at `RemeshPipeline.cpp:4999-5054`; `seam_transport_certificate()` at `:4520-4551` already matches region, carrier, endpoint selected faces and sheets. A6 checks reciprocal isolation evidence, both directed span transitions and face-gauge/transport consistency only later (`:5435-5509`).

**Candidate rule (RA-33.1).** For `SurfaceOccurrenceRelationKind::OrdinaryFront`, take the **certified special path** iff the relation's own two A5-published side spans name one identical source-edge carrier and its relation-owned isolation certificate: (i) is present, (ii) matches that carrier and both endpoint source faces, topology region and ordered endpoint sheets in either forward or reverse orientation, (iii) names distinct endpoint sheets, and (iv) is accompanied by both reciprocal side isolation evidence and directed `CornerWedgeIsolationTransition` in the two spans. Require the exact quarter-turn and coordinate/scale/phase checks already applicable; branch stripping must equal the oriented certificate's `forward()` or `reverse()`. Disjoint endpoint wedge-sheet sets remain independently required by A7. **No global sheet-ID comparison may grant the special case.** Use the product's typed relation+certificate instead of recomputing cross-sheet status from arbitrary global labels. A candidate claiming only *some* special-path evidence (unequal sheets or explicit seam transition, but absent/wrong certificate) must fail closed as missing/invalid authority: never reinterpret it as a non-seam relation to bypass a certificate requirement. A relation with no certified special-path claim takes the ordinary path and must meet the existing *full* `sourceChart`, branch, phase, scale, sheet/wedge equality. Do not change ordinary Periodic/HardRail dispositions.

**Worked positive (conceptual tuple, not a produced fixture).** A4 fronts on seam carrier `(1,4)`, selected faces `fL/fR`, reciprocal span transitions `(sheet0→sheet1)` and `(sheet1→sheet0)`, and certificate `(region r,edge(1,4),fL,fR,sheet0,sheet1,quarterTurn +1)` select the special branch only when the A6 stripped branch delta is `+1 mod 4`, both sides are reciprocal and endpoint coordinates/scale/phase satisfy existing exact requirements. **Near miss:** same collinear edge and unequal global sheets but certificate belongs to a different face pair; reject, not special and not ordinary-success. **Ordinary negative:** equal/unequal global labels without certified seam cannot waive full branch/chart equality.

## D2 — organic reciprocal exact-A3 non-self-inverse periodic gauge witness

**Evidence.** `tests/SurfaceCellTransitionQuotientTests.cpp:1466-1545` constructs a *real* nonzero-Z4 torus `torus.obj`, finalized raw field, row408 hard rails, A3/region plan and A4; however its `select_torus_source_witness()` selects only one generator. `:1998-2045` finds produced reciprocal forward/reverse A4 edges for that one witness. Identity `M6CP3.PeriodicExactA3UnequalFaceGaugeUsesRelationAndOccurrenceAuthority` at `:2121-2136` asserts its selected endpoints differ by odd quarter turn; R1 Review `:31-33` proves this assertion **fails**, not that no such pair exists.

**Candidate search (RA-33.2).** Construct the existing produced torus fixture without hand-edited relation records. Enumerate **all** produced `SurfacePeriodicHolonomy` relations and all their exact A3 source-generator candidates in stable canonical IDs, rather than select only the first. For each candidate, (1) require source CrossField transition matches A3 `FieldTransportAtlas::transition_value` in orientation, carrier and selected face pair; (2) require exactly one real A4 front edge in each reciprocal orientation, sharing the same source interval and reciprocal periodic relation ID, as in `produced_semantic_relation_for_witness`; (3) resolve semantic action and require correct forward/inverse route matching; (4) obtain each selected-face gauge from `SurfacePhaseFrontProduct::sourceFaceBranchRotations` and retain only `(F_b-F_a) mod 4 ∈ {1,3}`. Reject duplicates, synthetic endpoints and non-exact A3. Deterministically pick the smallest full source/occurrence/relation key, **after** all preconditions hold. Enforce non-vacuity before the identity's equality assertion. If the finite produced torus search has no qualifying pair, **stop for Review; do not weaken the 90°/270° premise, modify frozen identity count or synthesize a pair.**

**Worked comparison (illustrative, not yet observed).** Two reciprocal A4 edges with equal canonical interval `S`, source faces `(f7,f12)`, exact A3 transport and face gauges `(F7,F12)=(0,1)` qualify; gauges `(0,2)` do not (180° is self-inverse), even when both are actual periodic relations. **Outstanding proof:** existence of a qualifying organic pair has *not* been established by static inspection. Required R2 preflight checkpoint is this bounded enumeration; if empty return to Review without implementing the identity as if green.

## D3 — HardRail branch certificate in the field-crossing τ domain

**Evidence.** RA-31a in `Architecture_M6_Frozen_Definitions.md` withdraws `C=F⁻¹◦B` because regional `F_b−F_a` is not generally field crossing `τ`; `src/pipeline/RemeshPipeline.cpp:5514-5537` presently uses rigid `canonicalTransport` for HardRail. `src/authority/FieldTransportAtlas.cpp:2020-2047` reads authoritative `CrossFieldEdgeTransition.matching`, forms forward quarter-turn and inverse, adds `FieldTransportTransitionValue` **before** marking the hard-feature carrier nontraversable. `include/directional/authority/FieldTransportAtlas.h:889-891` exposes `transition_value()` for an oriented face pair, while the A4 `SurfacePhaseFrontProduct::make()` API (`include/directional/geometry/SurfaceCellTracing.h:1783-1800`) currently publishes face gauges and hard-feature edges but not τ. A5 consumes that A4 product, not the raw A1/A3 atlas. Do not pretend A5 can infer τ from its regional gauges.

**Candidate rule (RA-33.3).** Work in the orientation of the stored A5 occurrence relation `a→b` and its `canonicalTransport`. Let `B_a,B_b ∈ Z4` be A4-published endpoint branch rotations in their *selected source faces*, `R_coord ∈ Z4` be the rotation component of A5's coordinate-rigid HardRail `canonicalTransport`, and `τ_ab ∈ Z4` be the **oriented raw cross-field matching between selected faces** along the certified HardRail source carrier or certified source-face route, with inverse `τ_ba=-τ_ab mod4`. Compose transforms right-to-left and use `R_coord ∘ τ_ab` (in `Z4`, addition). Require for **each endpoint pair**:

`B_b ∘ B_a⁻¹ = R_coord ∘ τ_ab`  (equivalently `(B_b - B_a - τ_ab - R_coord) mod 4 = 0`).

Keep existing coordinate, scale, relation-kind, rail ID, source-route and reciprocal requirements. Do **not** substitute region-relative `F` for τ; retain `firstEndpointFaceGauge`/`secondEndpointFaceGauge` as verified provenance only. Reverse relation must invert all three relevant transports; do not mix orientations. A4 is the authoritative publication owner: extend its immutable product contract with oriented `(sourceEdge,fromFace,toFace,matching)` records copied/validated against the exact A3 `FieldTransportAtlas::transition_value` (including the matching values stored even on *nontraversable* hard rails). A5 must consume only this published evidence; missing, contradictory, nonreciprocal or ambiguous matching rejects by typed, relation/site-specific fail-closed error. No unrelated producer or validator edits.

**Rail vertex path-independence.** For face fan at a shared rail vertex, derive every admissible source-chart path from selected `f_a` to `f_b`; compose each oriented τ along the path, reversing sign for reversed edges. Require equality of composed τ across **all** admissible paths, equivalently zero quarter-turn holonomy around each allowed contractible fan cycle. Do not cross source boundaries, source-component/sheet barriers, unrelated hard-feature branches or unsupported topology; if path crosses a field singularity or has nonzero/ambiguous holonomy, **reject the HardRail certificate for that pair**, do not choose the shortest path or take a mean. A certified path of multiple adjacent faces is legitimate; a missing directly adjacent face transition is not grounds for inventing a τ. At a singular rail vertex an ambiguous τ remains typed fail-closed until additional owner-reviewed path authority is defined.

**Algebraic counterexample (not yet produced):** `F_a=0, F_b=1; τ_ab=0; R_coord=1; B_a=0, B_b=1`. The τ rule accepts (`1=1+0`), but withdrawn regional strip `C_b-C_a=(B_b-F_b)-(B_a-F_a)=0` incorrectly rejects against `R_coord=1`. A real discriminating fixture must produce **exactly this structural inequality** (`F_b−F_a != τ`, though numerical values can differ): extend the already real-produced `make_nonconstant_hard_rail_fixture` (3×3 vertices, two midline user hard edges, nonconstant XY/90° field; `tests/SurfaceCellTransitionQuotientTests.cpp:684-749`) with a *finite deterministically ordered* set of rail locations, face-gauge roots, and raw-field rotations. Build through `remesh_from_raw_cross_field` using fail-closed/no recovery, require green real A4 and A5, and select a real cross-region HardRail with unequal published `F` and τ, existing coordinate-rigid relation, and rule satisfied for both endpoints. **Outstanding proof:** the R1 run could not find even an odd F-pair (`R1 Review:35-37`), so the discriminating produced witness is *not yet established*; stop for Review if bounded real production yields none.

## D4 — tracer-produced seam-collinear OrdinaryFront for D3/D7

**Evidence.** The present `split_isolation_fixture()` (`tests/SurfaceCellTransitionQuotientTests.cpp:393-418`) uses a two-triangle square split on the diagonal `(0,2)` but a constant XY cross; the special OrdinaryFront helper at `:2100-2116` finds none. R1 review `:39-41` records D3 and D7 non-vacuity failures. An isolation certificate alone is not proof of seam-aligned traced cells. D7 test at `:2549-2610` additionally requires disjoint `cornerWedgeSheets` and an A6-selected relation followed by valid A7; it removes certified isolation evidence to verify `UncertifiedCrossSheetBinding`.

**Candidate real-tracer construction (RA-33.4).** Replace the D3/D7 witness search with a bounded family of **axis-aligned internal seam** planar rectangles whose front direction can actually follow the seam. Representative 2×1 strip: vertices `(0,0),(1,0),(2,0),(0,1),(1,1),(2,1)` (IDs 0–5), CCW triangles `(0,1,4),(0,4,3),(1,2,5),(1,5,4)`, left/right face sheets `0/1`, one connected component; seam carrier `(1,4)` vertical; normal XY cross arms, target sizing candidate set `{0.25, 0.5, 1.0}`; vary only documented, deterministic seeding and source-face order if needed. For every **real `build_surface_cell_network` product**, run **real** A5 and enumerate reciprocal `OrdinaryFront` relations. Accept a fixture only if both endpoint source spans name `(1,4)`, an A4-supplied exact isolation-seam certificate matches selected source faces/sheets, both reciprocal side isolation transitions exist, the relation is actually used by A6 and D7's endpoint wedge-sheet sets have empty intersection, and real A7 completes with no uncertified cross-sheet binding. Do not make a synthetic relation, manually change a source span, or declare success merely because a seam was added. Record the exact fixture rows, source face IDs, span, quarter-turn and relation IDs in the later R2 report.

**Distinct falsifiers:** D3 tamper only one direction's seam quarter-turn or reciprocal side transition and require an exact A6 certificate error while original produced positive remains green; D7 leave A6 selection unchanged, remove the A5-owned side isolation evidence, require A7 `UncertifiedCrossSheetBinding` at `cross-sheet`. Additional near miss: same mesh and seam but a front edge not collinear must retain strict ordinary equality. **Outstanding proof:** no such organic seam-collinear produced witness exists in the currently reviewed R1 evidence; an axis-aligned *input* is an explicit search proposal, not a proven positive. If candidate family produces no exact positive, stop for Review.

## D5 — ordinary hard-feature barrier falsifier on an actual A4 route

**Evidence.** Current identity 4 selects first `OrdinaryInterior` edge and *then* asserts non-empty route (`tests/SurfaceCellTransitionQuotientTests.cpp:2521-2544`), which R1 Review `:43-45` disproves. `SourceChartTransitionGraph` must consume typed protected source carriers rather than global component IDs.

**Candidate oracle (RA-33.5).** In an actually produced A4 `SurfacePhaseFrontProduct`, enumerate `edges()` sorted by stable IDs. Select an edge only when: (i) `boundaryKind==OrdinaryInterior`, (ii) `route` is present and nonempty, (iii) `route.steps().front().topology()` resolves to a genuine interior source carrier with two faces and a legal source-chart transition, (iv) the carrier is not already in `hardFeatureEdges`, and (v) its transition exists in the baseline `SourceChartTransitionGraph` at that exact typed source pair. Then add *only* this carrier to the A4 draft's typed hard-feature set and reconstruct the graph. Require that exact carrier transition absent/nontraversable while an unrelated unmarked carrier remains, without accepting mere component-label coincidence. In a separate source-preserving negative, remove a **real** required HardRail hard-feature carrier and expect `InvalidHardRailAuthority`; retain the genuine PeriodicCut hard-feature barriers and source-chart checks. If no route-bearing ordinary carrier exists, produce a real traced fixture by finite bounded input/seeding variation; **stop for Review** if still none.

**Worked example (illustrative only):** produced edge `OrdinaryInterior` with `route=[(sourceEdge 1–4, forward)]`, chart transition `(fL→fR)` and no hard feature at `1–4` permits baseline traversal; after adding exactly `1–4`, the chart transition must be blocked. A produced `OrdinaryInterior` with `route=[]` is **not** a candidate and cannot satisfy D4. Do not modify A5 hard-feature authority itself to manufacture coverage.

## Decisions, stop gates and handoff

All five rules are **defined**, but source inspection establishes **none** of the new organic D2/D3/D4 positive witnesses; exact replay of the reviewed 482/497 is not a proof of their existence. Therefore this is a **conditional RA-33 candidate**, not an accepted Definition or authorized R2 launch. The independent `M6-DEFN-R5-R1-REV` must determine whether the explicit bounded fixture/search recipes discharge RA-32's proof requirements or issue a stop/return with additional producer authority. If Review insists on already-produced positive witnesses, **do not release R2**. No source/fixture/test edits or runtime execution were performed in this Definition.

Only after Review explicitly approves all five semantic contracts and the bounded real-producer witness policy may it release **one** held plan: `Architecture_M6_CP3_CB1_Entry_R2_Recovery_Code_Build_Plan.md`. Then one compile-only all-eight GMP/GMPXX run, exactly one immutable 497-process artifact-only gate, and mandatory R2 Review; no CB2 or direct-production gates before acceptance. Stable accounting remains **63 / 17 / 46**, produced-witness debt **1**.

---

## Independent verification addendum (reviewing agent)

Runtime-free architecture review. **Not accepted as written. D2, D4 and D5 are sound; D3 is architecturally
right with one gap in its discriminating structure; D1 has a concrete orientation hole and an unaddressed
inverse conflation.** Three findings, all re-derived from source.

### A1 — D1: the certificate lookup discards which orientation matched, so the rule's two disjunctions can be satisfied inconsistently

D1 requires (ii) the certificate match carrier, both endpoint source faces, region and ordered endpoint sheets
"**in either forward or reverse orientation**", and separately that "branch stripping must equal the oriented
certificate's `forward()` or `reverse()`". Those are two independent disjunctions, and the code makes the
independence real rather than theoretical.

`seam_transport_certificate(...)` (`src/pipeline/RemeshPipeline.cpp:4520-4551`) computes

```cpp
const bool forward = certificate.firstFace() == firstOccurrence.placement.selectedFace && …;
const bool reverse = certificate.secondFace() == firstOccurrence.placement.selectedFace && …;
if (forward || reverse) return certificate;
```

It returns **only the certificate**, discarding the orientation that satisfied the identity match. A caller
therefore cannot know whether it matched forward or reverse, and D1's branch-strip clause is free to succeed
against the *other* orientation. A relation whose faces and sheets match reversed while its transport matches
`forward()` satisfies both clauses and is granted the certified special path — on an inconsistent orientation
pairing that waives full `sourceChart`/`branchRotation` equality.

This is the same conflation class that cost M5-CP3 fifteen turns, and **D3 already states the guard**: "Reverse
relation must invert all three relevant transports; do not mix orientations." D1 omits it while carrying the same
hazard.

**Required before acceptance:** D1 must bind one orientation. `seam_transport_certificate` returns the matched
orientation alongside the certificate (or two typed accessors), and the branch-strip, quarter-turn, coordinate,
scale and phase checks are evaluated against **that** orientation only. A certificate matching in one orientation
whose transport matches the other is missing/invalid authority and fails closed under D1's own clause.

### A2 — D1: global sheet labels are forbidden from granting the special case but still gate its discovery

D1's diagnosis is correct and I confirmed it at the decision site (`:5400-5403`):

```cpp
const bool crossSheetSeam =
    firstSpan.collinearEdge.has_value() &&
    firstSpan.collinearEdge == secondSpan.collinearEdge &&
    firstSpan.interiorBinding.sheet != secondSpan.interiorBinding.sheet;
if (!crossSheetSeam) { /* only here is full sourceChart + branchRotation equality required */ }
```

No certificate is consulted; arbitrary global label inequality alone waives full representation equality. That is
RA-32 exactly.

But the same unsound proxy appears a second time, in the helper D1 cites approvingly. `seam_transport_certificate`
opens with `firstSpan.interiorBinding.sheet == secondSpan.interiorBinding.sheet → return std::nullopt` — label
inequality is a **precondition on even looking for a certificate**. D1 forbids global sheet comparison from
*granting* the special case and says nothing about it *denying* one. If global labels are not a sound proxy for
cross-sheet status — which is RA-32's whole premise — then a genuinely certified seam whose two spans happen to
carry equal labels is never discovered, and the relation silently takes the ordinary path. Removing the
conflation in the granting direction while leaving it in the denying direction converts a false positive into a
false negative built on the same error.

Note the asymmetry is also a correctness question for D1's own condition (iii): "names distinct endpoint sheets"
is a property of the **certificate's** `firstSheet()/secondSheet()`, not of the spans' global labels. Those are
different claims and D1 should say which one governs. Recorded as `M6-DEFN-R5-R1-REV-OBS-01`.

### A3 — D3 is the right architectural call, but its single discriminating structure cannot falsify τ's orientation

The core decision is correct and worth stating plainly: A5 must **not** infer τ from its regional gauges, and A4
becomes the publication owner for oriented `(sourceEdge, fromFace, toFace, matching)` validated against exact A3
`transition_value`. That is sound because the data provably exists before exclusion —
`src/authority/FieldTransportAtlas.cpp:2020-2047` adds the `FieldTransportTransitionValue` *before* marking the
hard-feature carrier nontraversable — the same retain-then-exclude structure established at M5-CP3 §15. Refusing
to let a consumer re-derive a quantity it does not own is the correct reading of RA-31a's withdrawal of
`C = F⁻¹∘B`.

The rail-vertex path-independence requirement is also right, and unusually well specified: compose oriented τ
along every admissible source-chart path, require equality across all of them (zero quarter-turn holonomy around
each contractible fan cycle), reject on singularity or ambiguity, and explicitly **"do not choose the shortest
path or take a mean."** Those are the two shortcuts a holonomy condition invites, and both are closed.

The gap is in the witness. The proposed algebraic structure is `F_a=0, F_b=1; τ_ab=0; R_coord=1; B_a=0, B_b=1`.
It discriminates well on two axes — `F_b−F_a = 1 ≠ 0 = τ` proves τ replaced regional `F`, and `R_coord = 1` is
odd so its **sign** is falsifiable. But **τ_ab = 0 is self-inverse**, so this witness cannot distinguish `τ_ab`
from `τ_ba = −τ_ab`. The rule insists in the same paragraph that "reverse relation must invert all three relevant
transports"; the only proposed discriminating structure cannot test that for τ.

**Required:** the bounded fixture family must include at least one qualifying witness with `τ_ab ∈ {1,3}`, so the
τ orientation the rule mandates is falsifiable rather than assumed. A green result on a τ=0 witness proves the
τ-versus-`F` substitution and `R_coord`'s sign, and nothing about τ's direction.

One related note worth recording so it is not later mistaken for validation: because `Z4` is abelian, the stated
convention "compose transforms right-to-left and use `R_coord ∘ τ_ab`" is **numerically inert** — the equation
`(B_b − B_a − τ_ab − R_coord) mod 4 = 0` is symmetric in the two terms. No `Z4` test can falsify the composition
*order*; only the *signs* are testable. The order must therefore rest on domain semantics, and no passing fixture
should be cited as confirming it. Recorded as `M6-DEFN-R5-R1-REV-OBS-02`.

### A4 — D2, D4 and D5 are sound, and their premises are derived rather than asserted

**D2.** The `(F_b − F_a) mod 4 ∈ {1,3}` premise is correctly derived, not arbitrary: a 180° transform is its own
inverse, so a gauge difference of 2 cannot discriminate forward from reverse and is useless for the identity's
purpose. Excluding `{0,2}` is therefore required, and the instruction not to weaken it is right. Enumerating
**all** produced relations instead of the first, requiring the four preconditions, picking the smallest key
**after** preconditions hold, and enforcing non-vacuity before the equality assertion together remove the
select-then-assert ordering defect that made the original identity fail. The admission that a qualifying organic
pair is "**not** established by static inspection", with a stop gate rather than synthesis, is the correct
epistemic posture.

**D4.** I checked the proposed geometry rather than assuming it, because a mis-specified fixture costs a turn.
Vertices `0..5 = (0,0),(1,0),(2,0),(0,1),(1,1),(2,1)` with triangles `(0,1,4),(0,4,3),(1,2,5),(1,5,4)`: the seam
carrier `(1,4)` is the vertical edge at `x=1`, shared by exactly two faces — `(0,1,4)` on the left and `(1,5,4)`
on the right — so it is a genuine interior edge with one face per sheet. All four triangles are counter-clockwise
(signed areas all `+1`). The construction is geometrically valid and the seam is real.

**D5.** This correctly inverts a selection-before-precondition defect: the old identity picked the first
`OrdinaryInterior` edge and *then* asserted a non-empty route. Requiring route presence, a genuine two-face
interior carrier, a legal source-chart transition, absence from `hardFeatureEdges` and existence in the baseline
graph *as selection conditions* is the right ordering. Rejecting "mere component-label coincidence" closes the
same global-ID proxy that A2 above flags elsewhere, and the unrelated-unmarked-carrier control distinguishes
"this carrier became nontraversable" from "the graph broke".

### A5 — verification limits

Re-derived from repository bytes: `seam_transport_certificate`'s forward/reverse computation and its
orientation-discarding return; the `crossSheetSeam` decision site and its label-only waiver; the
`FieldTransportAtlas` retain-before-exclude ordering; D4's fixture coordinates, edge incidence and triangle
winding; and the `Z4` symmetry of D3's equation. Not verified: whether any qualifying organic witness exists for
D2, D3 or D4 — each is an open search by the record's own admission, and all three carry stop gates.
