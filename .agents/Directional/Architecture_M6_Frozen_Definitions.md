## RA-43 — producer locus for terminal contact, germ and face gauge **FROZEN at M6-DEFN-R5-R4-REV** (2026-10-10)

Discharges `R4-REV-01A`, `R4-REV-01B`, `R4-REV-02A`. Basis:
`Architecture_M6_CP3_R4_Producer_Locus_Review_Decision.md`. All three independent findings are ACCEPTED;
the producer-proof remedy they demand is discharged by exact symbol and line below. No runtime credit.
RA-34.3, RA-36.4/.5/.6, RA-38, RA-39, RA-40 and RA-42 (as corrected) stand.

- **RA-43.1 — the vertex-star producer, named.** `resolve_field_vertex_transit`
  (`src/geometry/SurfaceCellTracing.cpp:1257`). Its star loop at `:1452-1476` iterates
  `topology.transports()` filtered to adjacencies **incident to `sourceVertex`** (`:1453-1454`), steps
  face->face across `adjacency.sourceEdge` (`:1456-1462`), and accumulates a typed `transportPath` of
  `SourceEdgeTopologyKey` plus `composedSignedLift` = tau mod 4 (`:1473-1476`); frontier at `:1376`,
  `:1382`, `:1516`. Per-face sectors come from `vertex_star_sector` (`:1053`) returning `VertexStarSector`
  (`:1042-1051`) with typed `sourceFace`, `nextRadialVertex`, `previousRadialVertex`. **`railFanPotentials`
  is STRUCK: it never existed in `src/` or `include/`.** RA-38.5's and RA-42.4's substance is restored
  against this citation — only the carrier **cut** is missing, and it is a `continue` on carrier membership
  inside the `:1452` loop: no new state, no new tau definition, no A5-side search.
- **RA-43.2 — the terminal contact owner is the pipeline curve-network producer, not A4.**
  `SurfaceCellRail::sourceVertices` is authored at `src/pipeline/RemeshPipeline.cpp:9328-9356` from
  `OrderedCurveEdge::startVertex`/`endVertex` (`:9306`, assigned `:9401`), with continuity enforced at
  `:9335` and closure at `:9353`; single-edge rails at `:9491`. The chain is therefore **exact, not
  epsilon-derived**. Because it is authored in the pipeline stage, A4 **cannot reach it**: RA-42.1 is
  **relocated** — the typed terminal contact is a **required input bound at the A4 factory boundary** on the
  RA-40 precedent, fail-closed when absent or ambiguous. A4 may not derive it, and the endpoint certificate
  still stops reading `from.face`/`to.face` for contact purposes.
- **RA-43.3 — four namespaces, none interchangeable.** `SurfaceTracePoint::face` is a raw source-face row
  (header `:90-93`); `SurfaceCellRailSample::sourceEdge` is a **local corner index in [0,3)** (proved by its
  own guards at `src/geometry/SurfaceCellTracing.cpp:5824` and `:5841`); `SurfaceCellRail::sourceEdges`
  holds **feature-edge indices into `featureMap.edges`** (`RemeshPipeline.cpp:9348`); component meshes carry
  component-local renumbering (`MeshComponents.cpp:72-116`). Every binding states and converts its
  namespace explicitly. A raw `int` equality across two of these is **not** a topological claim.
- **RA-43.4 — `rail_sample_source_vertex` is an existing defect.**
  `src/geometry/SurfaceCellTracing.cpp:5820-5844` attributes a source vertex by
  `std::abs(value - 1.0) <= 1.0e-8` on barycentric coordinates and is live at `:5868` and `:5937-5938`.
  Under RA-42.2 this is prohibited. It is **replaced** by the exact chain of RA-43.2, never wrapped,
  tightened or re-toleranced. Scheduled for Code + Build; not implemented in a review turn.
- **RA-43.5 — face-gauge authentication, constructible inside the RA-40.1 boundary.** `make` at
  `src/geometry/SurfaceCellTracing.cpp:8015-8020` checks only cardinality against `face_count()` and values
  in `[0,4)`; its leading `!sourceFaceBranchRotations.empty() &&` lets an **absent** gauge pass unchecked -
  the same optionality RA-40.1 removed for the atlas. Required: presence is **mandatory** whenever A6 seam
  logic consumes it, and each value is authenticated **per face** against
  `fieldTransportAtlas->branch_topology().find_frame(face)`
  (`include/directional/authority/FieldTransportAtlas.h:874`, `:800`, semantics `:52`) using the
  `matchesA3` shape already written at `:7996-8009`. **A caller's own gauge is never its own oracle.**
  Sixth occurrence of publish/reach after RA-34.3, RA-35, RA-38, RA-40 and RA-42.
- **RA-43.6 — RA-41 freezes, restricted.** The RA-41 review gate asked Review to accept a source-exact
  implementable authority path or return the candidate as an architectural blocker. RA-41.1 is satisfied by
  RA-43.5 and RA-41.2 by RA-43.1/.2, so **RA-41 is FROZEN scoped to the singleton terminal contact**. Its
  junction and sector clauses are frozen as **UNEXERCISED**: 38 printed rows are one physical singleton
  carrier and the 39th is receiptless, so they may not be cited as validated and R4's multi-carrier STOP
  stands undischarged.
- **RA-43.7 — no credit.** Review-evidence defects in architecture documents are not runtime regressions.
  Ledger **66 events / 17 categories / 49 recurrences**, M6 debt **1**, unchanged. Selector 497 untouched;
  CP2 491/491 accepted; R3 403/497 rejected with 94 RED and 88 accepted CP2 losses. No promotion.

---

## RA-42 — terminal contact ownership and the A3/gauge trust boundary **ACCEPTED at independent R4-REV Design Review** (2026-10-10)

Resolves `R4-REV-01` and `R4-REV-02`. Basis:
`Architecture_M6_CP3_R4_Terminal_Contact_And_Gauge_Review_Decision.md`. No runtime credit; RA-34.3,
RA-36.4/.5/.6, RA-38, RA-39 and RA-40 stand.

**Decisive fact.** `SurfaceTracePoint` is `{int face; Eigen::RowVector3d barycentric;}` — **no source vertex, no
source edge**, and `face` is a **raw row index**, not a `SourceFaceTopologyKey`. The witness RA-41.2 requires
therefore cannot be authored from a trace point. Meanwhile `SurfaceCellRail` publishes ordered `sourceVertices`
and `SurfaceCellRailSample` publishes `sourceFace`/`sourceEdge`: the raw source-index provenance exists one structure
away, but its typed mapping to an oriented front terminal contact remains unproven — the **fifth** occurrence of the publish/reach pattern after RA-34.3,
RA-35, RA-38 and RA-40.

- **RA-42.1 — terminal contact ownership.** The terminal rail contact witness is authored by the **rail/front
  producer** from `SurfaceCellRail::sourceVertices` and the rail samples' raw `sourceFace`/`sourceEdge` after independently checked conversion to typed source entities and a unique front-contact association, and
  published as typed authority on the endpoint certificate. **Owner relocated by RA-43.2:** that chain is
  authored in the pipeline stage (`RemeshPipeline.cpp:9328-9356`), so A4 receives the contact as a required
  factory-boundary input rather than reaching for the rail. The endpoint certificate **stops reading**
  `from.face`/`to.face` for contact purposes.
- **RA-42.2 — no incidence from geometry.** Deriving source-vertex or source-edge incidence from
  `SurfaceTracePoint::barycentric`, or any floating-point predicate, is **prohibited** — it is RP-01
  authority-domain conflation, typed authority from a non-authoritative representation, in a pipeline that
  exactifies binary64 bit-for-bit. Absent typed incidence, fail closed with a code naming that absence.
- **RA-42.3 — typed diagnostics.** Carrier, face and endpoint diagnostics are emitted as typed
  `SourceFaceTopologyKey`, never bare row indices. A raw-row record is not evidence of a topological claim.
- **RA-42.4 — germ derivation.** The germ is the arc of the A2b vertex star at the terminal vertex after cutting
  the incident hard rails, from the traversal named in **RA-43.1** with the incident carriers cut. The formerly cited
  `src/geometry/SurfaceCellTracing.cpp:18120-18206` does **not** implement that construction: it contains
  isolation-seam certificate handling/diagnostics. The symbol `railFanPotentials` never existed in `src/` or
  `include/`; **RA-43.1** supplies the exact symbol, line range and typed source-entity linkage this clause
  required, so the obligation is discharged rather than outstanding. Equality with the carrier's incident pair holds **at the
  contacts**, never at the trace endpoints — the exact locus of RA-39.1's error.
- **RA-42.5 — RA-40.1 is unconditional.** The atlas mandate is **not** scoped. The earlier conditional
  pre-commitment is **withdrawn**: its premise that a rail-free product carries nothing A3-derived is refuted by
  `sourceFaceBranchRotations`, a raw unauthenticated gauge vector, and a conditional exception would preserve the
  production `CrossFieldResult` null-atlas ingress that RA-40 exists to close. Legacy callers **migrate**; the
  seven DCEL failures are **fixture defects to fix, not cases to exempt**.
- **RA-42.6 — gauge inside the boundary.** `sourceFaceBranchRotations` must be validated against published
  source authority — at minimum cardinality equal to the source face count and values matching what the
  authority publishes — and may not remain unchecked.
- **RA-42.7 — RA-38.3 scope.** RA-38.3's boundary-vertex and singleton STOP governs **multi-carrier
  through-junction sector transport** only and does **not** fire at a terminal contact vertex.
- **RA-42.8 — no runtime credit.** The 39-row family remains one carrier configuration with **zero**
  multi-carrier instances; RA-41.2's junction clauses stay unexercised and R4's multi-carrier STOP is
  undischarged.

**RA-42 independent re-review correction (M6-DEFN-R5-R4-REV):** RA-42 describes required future producer behavior,
not proof that this behavior already exists. `SurfaceCellRailSample::{sourceFace,sourceEdge}` are raw `int` values
(`sourceEdge` is local); the current front has no published typed terminal contact. Reject missing or ambiguous
producer-owned incidence rather than deriving it from barycentric epsilon predicates. The held R4 Code+Build plan
must retain the unconditional RA-40.1 atlas mandate. No runtime credit or implementation release; see
`Architecture_M6_DEFN_R5_R4_Independent_Review_Record.md`.

---

## RA-40 — A3 trust, CB/TB sequencing and excluded-test status **ACCEPTED at independent R3 A/B/C Review** (2026-10-10)

Resolves the `M6-CP3-CB1-ENTRY-R3` A/B/C block. Basis:
`Architecture_M6_CP3_R3_ABC_Review_Decision.md`. No runtime credit; RA-34.3, RA-36.4/.5/.6, RA-38 and RA-39
stand unchanged.

- **RA-40.1 — Decision A: factory-bound atlas re-derivation (A2 minimal). A1 rejected.** `make`
  (`src/geometry/SurfaceCellTracing.cpp:7969-7982`) currently accepts `hardRailFieldTransitions` and
  `hardRailRouteCertificates` as unauthenticated **data**. A balanced `+1 mod 4` on both paths leaves
  `χ_next ∘ φ_A == φ_B ∘ χ_prev` satisfied, because a consistency relation is gauge-invariant — so consistency
  can never substitute for authenticating values. `make` must therefore take an atlas bound by
  `FieldTransportAtlas::matches_source_faces` (`include/directional/authority/FieldTransportAtlas.h:893`) to the
  same source matrix, authority and vertex count, and **re-derive every A3-sourced value it is handed — each
  nonrail φ and each carrier χ — via `transition_value`, requiring exact equality including reverse orientation
  and reciprocity.** No new attestation schema is authorized or needed: the atlas is already
  `const authority::FieldTransportAtlas *` in options (`include/directional/geometry/SurfaceCellTracing.h:2186`)
  and A4 already derives through it; only the factory boundary lacks the binding. **Absent atlas → typed
  fail-closed**; there is no unauthenticated-but-accepted mode. A global per-face branch-gauge difference may not
  substitute for true A3 values (RA-31a). All twelve public factory call sites migrate explicitly — one
  production at `:12195`, eleven tests — with **no** default-null convenience overload. RA-39 endpoint-local
  single-terminal-carrier χ is unchanged and this is not a licence to reintroduce RA-37a fan detours.
- **RA-40.2 — Decision B: CB may close on authoring plus compile.** The binding plan forbids running Directional
  binaries in CB and places the **497** execution in a distinct TB, so a CB gate demanding produced runtime
  witnesses or the 47 accepted→RED recoveries is **unsatisfiable**. CB closes on complete source/test authoring
  and exact eight-target GMP/GMPXX compile/package evidence, with **nonvacuity enforced in compiled assertions**,
  claiming **no** produced positive. The authorized TB successor is named **before** root `STATUS` becomes
  `COMPLETE`. The 497 gate, all organic D1/D2/D3/D5 and A6/A7 witnesses, the odd-τ witness and the 47
  accepted→RED recoveries remain **TB** obligations; each TB RED is investigated individually and returned to a
  **new** authorized repair turn. Tool or time exhaustion is **not** `BLOCKED`.
- **RA-40.3 — Decision C: separately authorized, separately counted, diagnostic weight only.** The four excluded
  source-defined tests
  (`SurfacePhaseFrontProductFactoryAuthority.HardRailTransitionNeedsExactlyTwoSourceFaceIncidences`,
  `M6CP3.HardRailPublishedTauRequiresIncidentSourceFaces`,
  `M6CP3.A6SeamDirectionRejectsForeignFaceAndWedgeBindings`,
  `M6CP3.A7TypedWedgeSheetMismatchRejectsCachedMembership`) must **not** be folded into the frozen 497, which
  would mutate a single-owned gate and imply they had run; nor left unrun, which makes four authored contract
  tests zero-evidence (`LESSONS.md` 171). They run in a **separate** artifact-only focused diagnostic turn,
  **counted separately**, with results carrying **diagnostic weight only and no acceptance credit**, until a
  Review folds them into a successor gate under the pre-commitment discipline.

---

## RA-39 — P0/P1 endpoint-local attachment and transport **ACCEPTED at independent R3 producer Design Review** (2026-10-08)

Resolves the remaining `M6-CP3-CB1-ENTRY-R3` STOP. Completes RA-37a's P0/P1 obligation; **RA-37a and RA-38 are
not replaced.** Basis: `Architecture_M6_CP3_R3_Endpoint_Attachment_Review_Decision.md`. No runtime credit.

**Key fact.** `src/geometry/SurfaceCellTracing.cpp:18271-18285` requires `first.route == second.route.reversed()`,
so `first.from`/`second.to` lie at the **same spatial end** and `first.to`/`second.from` at the other. Each
endpoint certificate is therefore a **cross-rail pair at one spatial end**, one face per side — not a traversal
of the polyline. The current walk-all-carriers accumulation at `:18297-18330` is the superseded RA-36.1
end-to-end shape reappearing at endpoint level.

- **RA-39.1 — attachment, no new authority.** For endpoint pair `j` the terminal carrier `C_j` is the route's
  first (`j=0`) or last (`j=1`) oriented step. The certificate is valid only if `{from_j, to_j}` equals
  `{C_j.firstFace, C_j.secondFace}` as an **unordered pair**, with `χ_j = C_j.firstToSecond` oriented by which
  face is `from_j`, read from the already-published `SurfaceHardRailFieldTransition`. Any other pair → typed
  fail-closed **no local attachment**. **No path walk at an endpoint.**
- **RA-39.2 — sector agreement.** Each endpoint pair must hold exactly **one face per RA-38 sector**. Both faces
  in one sector, or a face outside the junction star where a junction exists, fails closed.
- **RA-39.3 — transport belongs to the square.** A4 publishes, per junction and per sector, the **ordered
  non-rail A2b source-edge witnesses** of the within-sector radial chain joining consecutive carriers' same-side
  faces. They serve the square only and are never an endpoint crossing. On the reviewed fixture
  `φ_A : 0 → 1 → 4`, `φ_B : 3 → 6 → 7`. Path-independence and holonomy rejection carry over from RA-38.
- **RA-39.4 — the square compares, it does not compose.** Validation applies `χ_1 ∘ φ_A = φ_B ∘ χ_0` as a
  comparison **after explicit transport**. Blind composition of χ across carriers and any end-to-end
  `composedTurn` remain prohibited.
- **RA-39.5 — schema.** Replace `SurfaceHardRailRouteEndpointCertificate`'s `orientedSteps`/`composedTurn`
  (`include/directional/geometry/SurfaceCellTracing.h:1488-1493`) with the single terminal carrier and its
  oriented `χ_j` — the correction **removes** state — and add the RA-39.3 radial witnesses, for which the struct
  currently has no field. A5 consumes only this published immutable certificate: no path search, no sheet/region
  label inference, no first-step selection.
- **RA-39.6 — singleton degenerates correctly.** For a one-carrier route both endpoint pairs share that carrier,
  there is no junction, `φ_A`/`φ_B` are identity, and the square reduces to the reciprocity already required.
  Existing singleton behaviour must not change.
- **RA-39.7 — no runtime credit.** Existence of a produced multi-carrier paired front is **not** established; a
  hand-authored input fixture is not a produced certificate. All RA-34.3 R2-P3 stop gates and RA-36.4/.5/.6
  stand, and an empty bounded search stops for Review.

---

## RA-38 — constructive sector derivation **ACCEPTED at independent R3 producer Design Review** (2026-10-08)

Resolves the `M6-CP3-CB1-ENTRY-R3` preflight STOP. **Implements RA-37a correction (1); RA-37a is not replaced.**
Basis: `Architecture_M6_CP3_R3_Sector_Derivation_Review_Decision.md`. No runtime credit.

- **RA-38.1 — the sectors are the cut star arcs.** At a rail junction vertex `v` on an interior orientable
  manifold link, the faces of `v`'s star form a cycle under "share a spoke edge at `v`". **Cutting that cycle at
  the two incident hard carriers yields exactly two arcs — the two unique oriented sectors — and each incident
  carrier contributes exactly one face to each arc.** Mechanically verified on the reviewed 3×3 fixture: star
  cycle `0 → 1 → 4 → 7 → 6 → 3 → 0`; carriers `(1,4)`,`(4,7)`; sectors `{0,1,4}` and `{3,6,7}`; carrier `(1,4)`
  faces `{0,3}` split `0∈A / 3∈B`; carrier `(4,7)` faces `{4,7}` split `4∈A / 7∈B`.
- **RA-38.2 — φ is within-sector radial transport.** The endpoint-local path from one carrier's face to the next
  runs **inside one sector** along **non-rail** A3 transitions. A4 publishes, per endpoint pair and per junction,
  the ordered non-rail A2b source-edge witnesses of that chain. Carrier-to-carrier face identity is neither
  required nor permitted.
- **RA-38.3 — fail closed, matching RA-37a's domain.** STOP on: boundary vertex (star is a path; cutting yields
  three arcs); more than two incident hard carriers (branch junction; no unique pair); exactly one incident
  carrier (rail terminates — no through-transport); non-manifold or singular star; foreign barrier inside an arc.
- **RA-38.4 — two distinct validators must be corrected together.** In
  `src/geometry/SurfaceCellTracing.cpp:8019-8118`: (i) `previous.secondFace != transition.firstFace` is the
  superseded RA-36.1 category error at a second site and must become within-sector radial chaining; (ii)
  `endpoint.orientedSteps.size() != expectedSteps.size()` unsoundly ties endpoint-path length to carrier count,
  when the real length is set by **fan valence per junction**. The reviewed 3×3 fixture satisfies (ii) only by
  coincidence (two carriers, chain length two), so a correction that fixes only (i) and validates on 3×3 will
  pass while (ii) stays wrong. Additionally the A4-side gate at `:18312-18330` must not precede the
  sector/junction logic, or the corrected path stays unreachable.
- **RA-38.5 — publish, do not invent.** The original assertion that `railFanPotentials` traverses the whole star at
  `SurfaceCellTracing.cpp:18120-18206` is unsupported (that range handles isolation-seam certificates and
  diagnostics). The real producer is named by **RA-43.1** (`resolve_field_vertex_transit`, `SurfaceCellTracing.cpp:1257`, star loop `:1452-1476`), which restores this clause's substance; A4 already knows the hard carriers (it builds `hardRailFieldTransitions`); only the carrier **cut** is missing,
  and it is a local derivation over data A4 already owns. Forbidden: guessed sectors; a global face-star
  potential used as ownership rather than post-ownership cross-check; first-by-row face selection; a new τ
  definition; any A5-side path search or inference from sheet/region labels.
- **RA-38.6 — no runtime credit.** Existence of a real A4-produced multi-carrier paired HardRail front is **not**
  established; a hand-authored input fixture is not a produced certificate. If the bounded search finds none, the
  multi-carrier path is unexercised and must not be cited as validated. All RA-34.3 R2-P3 stop gates and
  RA-36.4/.5/.6 stand.

---

## RA-37a — ACCEPTED by `M6-DEFN-R5-R3-REV` with binding amendment (2026-10-08)

**`M6-DEFN-R5-R3-REV` ACCEPTS RA-37a as a *bounded, fail-closed source-topology contract*; this is not any new runtime promotion. Exact successor after final beacon: `M6-CP3-CB1-ENTRY-R3` Code + Build only, with mandatory source A4 two-sector and both endpoint-local path STOPs.** CP2 491/491 remains accepted; R2 rejected 444/497; 47 accepted-green losses; 64/17/47, debt 1. See `Architecture_M6_DEFN_R5_R3_Review_Record.md`. No organic D1/D2/D3/D5 positives or A6 recovery accepted.

**Normative corrections:** (1) oriented A2b topology and A4 hard-feature owner determine the unique two source-vertex fan sectors only for connected orientable two-manifold links, without foreign barriers; otherwise fail closed/STOP; (2) source-keyed nonrail radial A3 side paths and owner-rail crossings must prove reciprocity and a typed commuting square; (3) for each of the two distinct **spatial endpoint pairs** A4 publishes its own locally anchored cross-rail path and `τ_j` from trace-selected source faces, and the along-rail square **only compares** the two endpoint mappings after explicit transport. Do not blindly compose χ values across distinct carriers or treat a path reaching the opposite spatial endpoint as a local attachment. A5 consumes only this immutable certificate. All RA-36.4/.5/.6 singleton/fail-closed/noncredit obligations remain. Full proof boundary, falsifiers and no-implementation evidence in `Architecture_M6_DEFN_R5_R3_Review_Record.md`. Earlier candidate RA-37 section below is historical and superseded by this binding amendment; it is not a second active contract.

---

## RA-37 — proposed M6-DEFN-R5-R3 amendment (**CANDIDATE ONLY; NOT FROZEN**, 2026-10-08)

The independent `M6-CP3-TB1-ENTRY-R2-REV` rejected 444/497 R2 and established that RA-36.1's requirement for consecutive HardRail carrier edges to share an incident face is unsound for legal source feature paths. The earlier RA-36 text below remains historical frozen authority **under explicit architectural challenge**, not silently overwritten. The proposed replacement in `Architecture_M6_DEFN_R5_R3_CP3_Entry_Recovery_Definition_Record.md` requires (1) A2b/A4-proven unique oriented left/right vertex-fan side sectors for each carrier junction, independent of face-row order, global sheet and Z4 potential; (2) directed, typed A3 transitions on every admissible side edge; (3) commuting square `χ_(i+1) ∘ φ_left = φ_right ∘ χ_i` with common source/target; (4) two separately well-typed A4 endpoint-pair certificates consumed, not inferred, by A5; (5) reciprocal/owner/fan/holonomy/missing-authority fail-closed behavior and unchanged singleton. **STOP if producer topology cannot establish unique side paths.** The concrete 3×3 input `(1,4),(4,7)` proves a source-topology counterexample, not produced A4 multi-edge success. No organic D1/D2/D3/D5 or A6 success is claimed. Frozen future TB unchanged 497=30+12+449+6; 47 formerly accepted CP2 identities must recover. Stable ledger **64/17/47**, debt 1. **Only `M6-DEFN-R5-R3-REV` may accept/amend this candidate and release the held R3 Code+Build plan.**

---

## Current independent Review HOLD — RA-36 face-sharing premise disputed (2026-10-08)

R2 runtime Review `M6-CP3-TB1-ENTRY-R2-REV` **REJECTS R2 444/497** and records an accepted-green A4 HardRail producer false rejection. Existing frozen RA-36.1 says consecutive rail edge carriers share a typed source face; legal fixture edges `(1,4)` and `(4,7)` meet at vertex 4 but have disjoint incident source-face sets `{0,3}` and `{4,7}`. This is a static topology counterexample to an assumed universal invariant, **not evidence that a two-edge route was produced in the R2 runtime**. RA-36 text below is preserved unchanged as historical frozen authority; **do not implement a silent weakening or regard the disputed premise as sufficient for a new CB**. Exact next: `M6-DEFN-R5-R3` proposes candidate RA-37 typed A3-side fan transport contract, then mandatory independent `M6-DEFN-R5-R3-REV` to freeze/reject an amendment. R2 candidate unpromoted. Full review `Architecture_M6_CP3_TB1_Entry_R2_Review_Record.md`.

---

# M6 Frozen Definitions — Occurrence, Quotient, Embedding, Independent Verification

**Status:** FROZEN / M6-CP1 and M6-CP2 CLOSED / ACCEPTED. CP3 entry R1 candidate `11488700954 / 68000a95` **REJECTED** at 482/497 by RA-32; predecessor P1/T1 regressions recovered, prior `RP-01` seam-domain event remains open. Stable accounting **63 / 17 / 46**, debt 1. **EXACT NEXT = `M6-CP3-CB1-ENTRY-R2`** after independent `M6-DEFN-R5-R2-REV` accepted RA-34 as bounded Definition. R2 compile-only is released with strict A4 typed incidence and organic-witness stop gates; CB2/CP3 exit held. RA-1 – RA-32 normative as annotated, RA-34 accepted amendment supersedes RA-33.1/.3 only.
**Date:** 2026-09-25
**Definition authority:** this record is the normative M6 contract for A5 occurrence creation, A6 quotient construction/materialization, A7 source-attached geometry embedding, and the M6 structural portion of A8 independent verification. It refines `DESIGN.md` §14 M6 without changing accepted M5 producer semantics or pulling M7 disposition/degradation work forward.

This definition turn changes documentation/planning only. It changes no product source, test, fixture, selector, benchmark, or build source and executes no generated Directional runtime.

## 1. Entering authority

M6 enters only after final `M5-CP4-TB2-REV` acceptance:

- accepted package/source `10814505512 / e284fea7c101eb86650d1c87c92d0fefa66050e7`;
- accepted selector449: **449/449 PASS**, LF SHA-256 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`;
- routing449 SHA-256 prefix `9c88a5ed...c5707`, owner census **32 / 301 / 75 / 41**;
- stable accounting **51 events / 14 categories / 37 recurrences**;
- produced-witness debt **1**, the M6-owned closed-complex `G4-B002` subject.

The Definition audit used exact source snapshot run/artifact `36026363482 / 10819439146` at source SHA `c9be476d75e6f5d6df11304ad6b926b27b36430f`; provider artifact SHA-256 `6331c1189591e0429128495719d6168c92827c9024175b2d121387706519d762`, embedded source archive SHA-256 `b57fe2df11bd0d988196b45dee8855581bff8cce942ce66c20b68ac8ee1b1b2e`, and all **5305/5305** source manifest rows verified. No generated Directional runtime executed.

**Process-only observation (`M6-DEFN-OBS-01`, +0):** several small repository documents were fetched directly before the turn fixed the mandatory `READ_MODE`. No semantic conclusion or mutation was accepted from that pre-snapshot inspection. The turn then froze `READ_MODE=snapshot`, acquired and verified the exact source authority above, and all decisive static adjudication used those verified bytes. Existing tool-conservation guidance already covers the pattern, so no new `LESSONS.md` rule is created.

The M5 `G4-B004` half is accepted and immutable: one **pipeline-produced** topology region is multi-isolation, owns a checked internal isolation-seam certificate, and owns a canonical periodic relation explicitly named by reciprocal `PeriodicCut` edges. M6 consumes that fact; it does not reconstruct, weaken, or reinterpret it.

## 2. Current implementation diagnosis

The current transitional function `build_authoritative_phase_front_mesh(...)` performs several future stages inline: it allocates corner occurrences, verifies relation ownership, performs quotient union, chooses quotient representatives, writes geometry, and publishes lineage into `PureQuadMesh`. This is precisely the stage coupling M6 must remove.

Two source facts constrain the cutover:

1. the production classifier now passes an explicit **empty isolation-barrier set** to `classify_source_surface_labels(...)`; hard-feature rails remain topology-region/chart/rail barriers and are not automatically `IsolationSheetId` barriers;
2. the transitional materializer still contains geometric representative consistency and output-lineage publication in the same procedure as quotient construction.

M6 therefore separates products rather than adding another downstream repair layer.

## 3. Stage A5 — `SurfaceOccurrenceComplex`

### 3.1 Sole producer and inputs

**Sole producer:** `SurfaceOccurrenceComplexProducer` (M6 A5).

**Typed inputs:** the complete immutable set of accepted A4 `RegionCellComplex` products plus the already-accepted M5 relation/certificate authority carried by those products. A5 does not consume output vertex rows, `PureQuadMesh`, world-space weld results, `SurfaceCellPipelineContext`, or diagnostic hashes as semantic authority.

### 3.2 Immutable output

```text
SurfaceOccurrenceComplex
  cells[]
    CellId
    cornerOccurrences[4] : OccurrenceId
    directedSides[4]
      from / to OccurrenceId
      exact incident-cell interior-side source authority
      ordered DirectedSideIsolationEvidence
  occurrences[]
    OccurrenceId
    CellId owner
    canonicalCornerRole
    exact SourceSupport
    TopologyRegionId
    CornerWedgeSheetSet              // sorted, unique, non-empty
    CornerWedgeFaceBindings[]        // ordered contiguous fan; per-face (face, sheet, chart); no branch (RA-11)
    CornerPlacementProvenance        // A4 corner LocalLatticeState verbatim + its selected-face label; placement only (RA-11)
    CornerWedgeIsolationEvidence[]   // exact (region,seam-edge) refs + traversal orientation
    face-independent lattice phase / coordinate / scale provenance
  ownedRelations[]
    OccurrenceRelationId
    relationKind          // OrdinaryFront | HardRail | Periodic | SingularityPort
    firstOccurrence
    secondOccurrence
    kind-specific owner   // none for OrdinaryFront; existing HardRail/Periodic authority unchanged
  OccurrenceComplexCertificate
```

Every accepted A4 cell appears exactly once and owns exactly four distinct corner occurrences and four directed sides. Every relation endpoint names an occurrence that exists in this product. A5 **does not union occurrences** and does not choose an output representative.

For a seam-incident corner, `CornerWedgeSheetSet` is the sheet set of the contiguous source-face fan arc covered by the cell interior between the last positive-length incoming side segment and first positive-length outgoing side segment. Edge support spans at most its incident faces; vertex support spans the exact contiguous fan arc. The corresponding wedge certificate references are exactly the checked seam edges crossed by that fan. At a non-seam corner the set is a singleton.

A seam-collinear directed side derives its incident-cell interior source face by exact chart orientation and canonical cell interior, never by source-face row or lexicographic triangle selection. Its side evidence names the exact checked seam certificate. Mid-side seam crossings are likewise published on the directed side.

Face-dependent field chart, branch rotation, and sheet provenance are per wedge binding/side. A seam occurrence must not combine sheet/support selected from one face with chart/branch selected from another. Face-independent lattice phase, coordinate, and scale remain value/provenance and are not identity.


**R2 exact side/binding law.** A directed side is partitioned in traversal order into maximal positive-length exact `SourceSupport` spans. A span is source-edge-collinear exactly when its open interior support is that `SourceEdgeSupport`. For an accepted `orientationValidated` A4 cell, the semantic incident-cell interior face of such a span is the unique incident source face selected by canonical directed-edge winding and the accepted cell-interior side; builder-local row/lexicographic representative-face tie-breaks are non-authoritative. The rule applies identically to uniform, periodic-chart, and bounded-disk builders. An occurrence's canonical binding signature is the complete ordered tuple set `(sourceFaceTopology, IsolationSheetId, SourceProjectionChart, branchRotation)`. Every admissible wedge stays within one topology region and one chart component and stops at source/region/hard-rail boundaries.

**R2 lineage evidence carrier.** Complete wedge/side isolation evidence is additionally projectable as lineage equivalence kind `CornerWedgeIsolation` with one or more ordered semantic transitions `(TopologyRegionId, SourceEdgeTopologyKey, fromSheet, toSheet)`. That kind is evidence-only: it is not an A5 `ownedRelation`, carries no HardRail/Periodic owner, selects no relation path, and never creates quotient equality.

### 3.3 Occurrence identity

`OccurrenceId` is the semantic pair:

```text
(CellId, canonicalCornerRole)
```

where `canonicalCornerRole` is the corner between two adjacent directed sides in the A4 cell's immutable canonical cycle. The cycle's orientation/rotation is fixed by A4 semantic authority before A5; storage row, vector position, scheduler order, output row, world-space position, lattice coordinate, representative face/sheet, hash, and cache index are excluded.

Two occurrences remain distinct even when all of these coincide:

- lattice coordinate;
- exact source support;
- chart-local coordinate;
- 3D position.

Only A6 may equate them, and only through a verified A5 owned relation.

**`CellId` basis (reviewing-agent note; the definition is unchanged).**
- **What `CellId` is today.** The accepted A4 `CellId` is `from_index(rank)` over the sorted set of `(TopologyRegionId, region-chart grid ordinal v*width+u)` (`SurfaceCellTracing.cpp:17060-17075`, `:7785-7793`). `TopologyRegionId` is itself a rank over regions sorted by `canonicalFaceTopology`, a key built from source-vertex IDs (`:8520-8575`, `:8687`). Its semantic content is therefore (region canonical face topology, canonical chart cell coordinate). The chart position is legitimate *cell* identity, and the §3.3 lattice-coordinate exclusion concerns equality **between** occurrences.
- **Invariance evidence.** Face-row invariance of region, chart and periodic-cut identity is already accepted: selector449 rows 129, 196, 213, 245 and 254.
- **Known limit.** Rank-based IDs **renumber when a cell is inserted or omitted anywhere**. M6 does not rely on stability across differing cell sets, but M7 omission bookkeeping will, and `M7-DEFN` must decide whether a content-keyed `CellId` is required then.
- **Consequence for CB1.** The A5 permutation test must permute **source face rows**, not only cell storage (row 213 already covers storage). If face-row permutation renames `OccurrenceId`s because of A4 `CellId`, that is the CB1 stop rule "changing A4 `CellId` semantics". It routes to Review/Definition and must not be satisfied by a storage-only test.

### 3.4 A5 certificate and failures

`OccurrenceComplexCertificate` proves:

- one A5 cell record per accepted A4 `CellId`;
- exactly four unique occurrence IDs per cell;
- the four directed sides form the cell's exact ordered cycle;
- every occurrence has exactly one cell/corner owner and one complete contiguous wedge authority;
- every required seam crossing on a wedge or directed side names exactly one matching checked `(TopologyRegionId, SourceEdgeTopologyKey)` certificate;
- every relation has two existing, distinct typed endpoints and satisfies its **kind-specific** owner contract: `OrdinaryFront` has no owner, HardRail/Periodic keep their accepted typed owners;
- no occurrence, wedge, side, or relation authority was inferred from geometric coincidence or global certificate search.

A5 owns fail-closed `OccurrenceConstructionFailure` codes for missing/duplicate cell ownership, missing/duplicate corner occurrence, invalid directed-side cycle, invalid/noncontiguous wedge authority, missing/duplicate/mismatched wedge-or-side isolation evidence, relation endpoint missing, duplicate relation declaration, unsupported singular/nonmanifold wedge, unsupported SingularityPort corner, unsupported hard-rail/seam wedge, and source-authority mismatch. Relation failures are **not** many-to-one: `OccurrenceHardRailOwnerMissing`, `OccurrenceHardRailOwnerMismatch`, `OccurrencePeriodicOwnerMismatch`, `OccurrenceRelationKindMismatch`, and `OccurrenceUnownedRelation` (genuinely unowned cases only) are distinct. The transitional compatibility adapter alone maps them respectively to the frozen M5-compatible names `MissingHardRailRelationOwner`, `InvalidHardRailTransport`, `InvalidPeriodicRelationOwner`, `IncompatibleAuthoritativeFrontPair`, and `UnownedRelation`. Structural endpoint/range defects remain structural failures rather than `UnownedRelation`. A rejected A5 product is not consumable.

## 4. Stage A6 — `SurfaceQuotientProduct`

### 4.1 Sole producer and inputs

**Sole producer:** `SurfaceQuotientProducer` (M6 A6).

**Typed inputs:** immutable A0 source authority plus exactly one complete `SurfaceOccurrenceComplex`. A6 may verify only typed M5 values referenced by A5 wedge/side evidence or by the existing kind-specific HardRail/Periodic relation owners. It may not search global certificate inventory, choose an alternative certificate, reconstruct semantic authority from raw boundary paths, or synthesize a missing one.

### 4.2 Immutable output

```text
SurfaceQuotientProduct
  classes[]
    QuotientClassId
    sorted member OccurrenceId set
  relationCertificates[] : QuotientRelationCertificate
  consumptionLedger[]
    OccurrenceRelationId
    firstOccurrence
    secondOccurrence
    exactlyOneConsumption
  topology
    quotient vertices identified by QuotientClassId
    one ordered quad per accepted CellId
  MaterializationCertificate
  QuotientCertificate
```

A6 is **topological**. It creates no source-attached 3D vertex representative and no geometric weld. One accepted A5 cell maps to exactly one output quad. An A5 relation becomes quotient authority only after the producer verifies that exact declared relation; an unrelated valid M5 relation remains decision-neutral.

### 4.3 Quotient identity and equality

`QuotientClassId` is the canonical, sorted, non-empty **set of member `OccurrenceId` values**. It is not the smallest member, a sequential class row, the union-find root, a representative sheet, a coordinate, or a hash.

Two classes are equal if and only if their complete member sets are equal. Relation application is deterministic over canonical relation identity, but union-find roots and traversal order are representation leaves only.

### 4.4 Exact-once relation ownership

The phrase **owned relation** means an `OccurrenceRelationId` explicitly published in A5 `ownedRelations`. Available but unreferenced M5 relation-table entries are not A5-owned relations and remain decision-neutral.

For every A5 owned relation, A6 must record exactly one `QuotientRelationCertificate` and exactly one consumption-ledger row. Zero consumption, duplicate consumption, conflicting endpoint use, relation substitution, or consumption by an unowned relation is typed failure. This is the M6 meaning of "every owned relation is consumed exactly once" and is consistent with M5's accepted unused-valid-relation contract.


### 4.5 Ordinary-front sheet/evidence validation

`OrdinaryFront` remains owner-less and `OccurrenceRelationId` is unchanged. Side validation is performed over the ordered maximal positive-length exact-support spans frozen by A5. For a non-seam-collinear near-endpoint span, reciprocal records must agree on the mapped incident-cell interior sheet and that sheet must belong to both endpoint `CornerWedgeSheetSet` values. Side-interior seam crossings are accepted only through the ordered `DirectedSideIsolationEvidence` published by A5 and exact verification of those checked certificates.

For a seam-collinear near-endpoint span, both reciprocal side records must name the same checked seam certificate/span; their exact incident-cell interior faces are the two incident source faces; their sheets are the certificate's two opposite incident sheets; and the ordered evidence lists are reverse-compatible with every sheet transition inverted. Disjoint singleton endpoint wedge sets are legal only in this explicit collinear case. Any disagreement is typed `QuotientReciprocalSideAuthorityMismatch`.

A6 records in its quotient relation certificate which wedge/side certificate references were actually verified. It never infers equality from a representative sheet. For selected HardRail/Periodic path steps, endpoint charts/chart-components come from the relation-side interior-face bindings; path start/end charts come from the first/last selected steps, never from a quotient representative face. `CornerWedgeIsolation` lineage evidence does not create a selected relation path.

### 4.6 A6 certificate and failures

`QuotientCertificate` proves the class partition is exactly the transitive closure of **verified A5 owned relations** and nothing else. `MaterializationCertificate` proves:

- every `CellId` maps to one and only one output quad;
- every output quad corner maps to the `QuotientClassId` containing that cell's corresponding `OccurrenceId`;
- every quotient class is non-empty;
- no class arose from coordinate/position equality;
- every A5 owned relation appears exactly once in the relation-consumption ledger;
- every cross-sheet union step has the exact A5-published wedge/side certificate evidence required by §4.5.

A6 owns fail-closed `QuotientConstructionFailure` codes for missing/duplicate/conflicting/nonreciprocal relation authority, invalid wedge/side sheet membership, missing/invalid seam-collinear certificate evidence, unowned relation use, zero/duplicate relation consumption, invalid class partition, missing occurrence member, degenerate classed quad, and non-bijective cell-to-quad materialization. M5's accepted typed relation failures remain unweakened. A5 owns the one-to-one semantic relation-failure vocabulary frozen in §3.4 and the compatibility adapter owns the legacy-name mapping. Once A5 certifies owner presence/equality and relation-kind compatibility, only those duplicate structural predicates may disappear from the transitional materializer; route reversal/content, periodic shift, exact relation value, exact transport application, source-support, and other M5 semantic checks remain live. M6 does not rename a valid M5 failure into success or an unrelated generic failure.

## 5. Stage A7 — `SourceAttachedGeometryProduct`

### 5.1 Sole producer and inputs

**Sole producer:** `SourceAttachedGeometryProducer` (M6 A7).

**Typed inputs:** immutable A0 source authority and one complete `SurfaceQuotientProduct`, with the A5 occurrence/source-support evidence referenced by the quotient certificates. A7 may not change A6 topology or quotient membership.

### 5.2 Immutable output

```text
SourceAttachedGeometryProduct
  topology                 // identical semantic A6 topology
  vertices[]
    QuotientClassId
    exact SourceSupport
    source-attached coordinates / barycentric representation
    intended component / isolation-sheet authority
  SourceSupportCertificate[]
  GeometryEmbeddingCertificate
```

The vertex's semantic identity remains its `QuotientClassId`. Position is a value derived from exact source support and cannot merge, split, or rename a quotient class.

A quotient class spanning multiple certified chart/sheet representations is legal only when A6's verified A5-published wedge/side evidence establishes every cross-sheet step that requires certification. `sourceIsolationSheets` is the sorted unique union of every member occurrence's `CornerWedgeSheetSet`. `sourceCharts` is the sorted unique union of every member `CornerWedgeFaceBinding.chart`. Component remapping first remaps complete binding tuples and ordered `CornerWedgeIsolation` transition tuples, and only then derives legacy region/sheet/chart projections; independent-set or cross-product validation is not semantic authority. A7 records the complete compatible source authority and the wedge/side certificate evidence referenced by the quotient certificates; it never selects a representative sheet/chart and silently discards the others.

### 5.3 A7 certificate and failures

For each quotient class, `SourceSupportCertificate` proves that every contributing occurrence is incident to the published exact support under the already-certified relation path and that the embedded value remains on the intended source component/sheet authority. `GeometryEmbeddingCertificate` proves topology is unchanged from A6 and every quotient vertex is embedded exactly once.

A7 owns fail-closed `GeometryEmbeddingFailure` codes for missing/ambiguous source support, support/certificate mismatch, cross-component or uncertified cross-sheet binding, missing quotient vertex embedding, duplicate embedding, non-finite geometry, and topology mutation. Nearest-position coincidence and epsilon welding are forbidden recovery mechanisms.

## 6. Stage A8-M6 — `VerificationReport`

### 6.1 M6 scope and M7 boundary

**Sole producer:** `SurfaceProductVerifier` (M6 structural A8).

**Typed inputs:** immutable A0, A5, A6, and A7 products and their certificates. The verifier outputs immutable `VerificationReport` only.

`OutputDisposition`, `DegradationCertificate`, tier assignment, omission, and degraded production remain **M7**. The full DESIGN A8 contract is completed in M7; M6 must not pull disposition/degradation forward merely because the verifier exists first.

### 6.2 What the verifier may recompute

The verifier may independently recompute only elementary facts from immutable inputs:

- source face/edge/vertex incidence and component adjacency from A0;
- exact incidence of a published `SourceSupport` using the shared source-support kernel;
- occurrence ownership counts and directed-side cycle incidence from A5;
- output quad incidence, edge incidence, connected components, boundary loops, Euler characteristic, and manifoldness from A6 topology;
- cell-to-quad and occurrence-to-class membership by reading the published A5/A6 IDs;
- exact composition/inversion of a **named** relation certificate's recorded transport;
- source-support incidence of an A7 embedded vertex;
- deterministic equality of immutable certificate payloads under semantic ordering.

Shared primitive value types and exact algebra are allowed. Reusing a producer's **decision procedure** is not independent verification.

### 6.3 What the verifier may never do

The verifier may never:

- create or renumber an `OccurrenceId` or `QuotientClassId`;
- union occurrences or choose a quotient representative;
- search a relation graph for a replacement route/path;
- infer a missing endpoint, route, owner, chart, sheet, source support, or relation;
- canonicalize malformed producer state into an acceptable form;
- substitute an equivalent relation or reverse relation not explicitly certified by the producer;
- weld by lattice coordinate, barycentric tolerance, 3D position, or proximity;
- repair a directed-side cycle, quad incidence, source attachment, or certificate;
- mutate A5/A6/A7 or emit a corrected product;
- invoke fallback/recovery or convert a producer rejection into a verified product.

On any violation it emits a typed `VerificationFailure` in the report. A report is successful only when the original immutable products verify as published.

### 6.4 Verification report identity

Findings are keyed and ordered by semantic stage/locus IDs, never by discovery order. The report may include representation indices as diagnostics, but changing source-row, output-row, or scheduler order cannot change the semantic finding set.

## 7. Product dependency and mutation law

The only M6 authority flow is:

```text
A4 RegionCellComplex set
  -> A5 SurfaceOccurrenceComplex
  -> A6 SurfaceQuotientProduct
  -> A7 SourceAttachedGeometryProduct
  -> A8-M6 VerificationReport
```

A later stage may reference earlier immutable IDs/certificates; it may not write into them. Aggregation is a new immutable output, never in-place normalization. `PureQuadVertexLineage`, `SurfaceCellPipelineContext`, diagnostics, hashes, output row numbers, and existing transitional materializer locals may be retained temporarily as compatibility/diagnostic surfaces, but none may become semantic stage authority.

## 8. M6 debt and blocker ownership

### 8.1 `G4-B002` closed-complex produced witness

The original contract remains unchanged: fail-closed `SurfaceCells`, recovery/fallback disabled, closed source, independently validated candidate eligibility, and a discriminating hard-feature/protection tamper. Synthetic/direct arrangement authority receives zero credit.

- **M6-CP1 mechanism owner:** establish the real A5 occurrence product and A6 stage boundary from which candidate extraction can consume closed-complex authority without `SurfaceCellPipelineContext::hasArrangement`.
- **M6-CP3 evidence owner:** re-prove the unchanged candidate-extraction eligibility oracle and hard-feature tamper on direct production after A5-A8 are complete.

CP1 mechanism evidence cannot close the production debt.

### 8.2 `G4-B001 / PR8-R034 / G4-R007`

**Disposition: not a currently demonstrated M6 implementation defect; carry as a direct-production evidence debt to `M6-CP3`.**

The historical root was a hard feature being promoted into `IsolationSheetId` authority, after which strict closure reported `LocalSheetMismatch`. Current production source explicitly separates those domains: `hardFeatureRailEdges` remain topology-region/chart/rail barriers while `classify_source_surface_labels(...)` receives an empty `sourceIsolationBarrierEdges` set. The original root condition is therefore not present at the current source boundary.

M6 must nevertheless preserve this separation:

- CP1/A5-A7 must not derive an isolation sheet from hard-rail membership;
- A7 may cross a chart/region boundary only under certified quotient relation authority and must preserve complete sheet evidence;
- CP3 owns the historical strict-valid torus **3/3** direct-production re-proof.

If CP3 reproduces `LocalSheetMismatch`, the new failure must be classified against the frozen A7 source-support/embedding contract; validators or sheet authority may not be weakened to obtain green output.

### 8.3 `G4-B004` M6 representative-consumption half

M6 closure requires the **same direct produced torus authority** accepted by M5-CP4, not a synthetic substitute. The proof chain is:

1. retain the accepted M5 same-region producer fact unchanged;
2. A5 materializes four explicit occurrences per cell and relation endpoints by occurrence ID;
3. A6 consumes every A5-owned relation exactly once and publishes quotient/materialization certificates;
4. A7 embeds the resulting quotient classes with complete source-support and multi-isolation evidence;
5. A8 independently verifies the same immutable A5-A7 products without reconstructing the M5 relation or isolation-seam fact.

Existing never-gated identities are disposed as follows:

- `SurfaceCellTransitionQuotient.MultiIsolationMaterializationRetainsAllLocalSheets` — **retain and gate during M6-CP1** as focused mechanism preservation only. It is not representative direct-production credit by itself.
- `SurfaceCellsPhase10.ExactCommittedTorusDoesNotTreatIsolationSeamAsBoundedDiskBoundary` — **retain and gate during M6-CP3** as direct torus preservation. It is necessary but insufficient by itself for M6 closure because it does not independently prove the new A5/A6 exact-once ledger and A8 verification.

M6-CP3 must therefore add/use a dedicated representative M6 identity that binds the accepted M5 producer fact to A5 occurrence ownership, A6 exact-once consumption, A7 embedding, and A8 independent verification in one direct production result. No M6 evidence grants retroactive M5 credit.

## 9. Dormant CB14 identity disposition

`M5-CP3-TB1-R16-REV-OBS-01` is now fully resolved with **no M5 credit**: one deletion, and one retention with a named gating owner (see the re-adjudication below the table).

| Dormant identity | Disposition | Existing accepted replacement authority | First action owner |
|---|---|---|---|
| `M5CP3.PeriodicRelationEndpointGaugeIsIndependentAndExact` | **DELETE as superseded/redundant** | accepted `M5CP3.PeriodicRelationRotationUsesBothAcceptedOccurrenceGauges` covers the exact occurrence-gauge/branch rotation seam; accepted nonzero-Z4 production identities cover nonzero translation/materialization | `M6-CP1-CB1` test-source cleanup only |
| `M5CP3.ProducedTorusPeriodicPairStorageSwapPreservesSemanticDirection` | ~~DELETE as superseded/redundant~~ → **RETAIN AND GATE in the first M6-CP1 prepublication gate** *(deletion stopped by the §9 precondition; see note below)* | ~~row 444 covers storage permutation~~. Row 444 reverses the **relation container** and row 432 resolves semantic direction. Neither permutes **edge storage**, and no selector449 row does. | `M6-CP1` prepublication gate (vector frozen by the CB1 report / TB1 plan) |

Deletion removes dormant, never-gated duplicate authority; it does not modify an accepted selector and cannot be cited as evidence for M5 or M6. If either accepted replacement ceases to cover the stated property, deletion must stop and be re-adjudicated before test source changes.

**Reviewing-agent re-adjudication of row 2.** The pair-swap identity swaps the reciprocal `PeriodicCut` edge pair **in `edges` storage**, remaps events and compares selected certificates after materialization, all on the nonzero-Z4 witness. Front-edge indices are a DESIGN §6.2 representation handle, and the A5 cutover must not depend on them. No accepted identity covers this permutation, so the precondition above fires. The identity is **retained untouched** and becomes a candidate in the M6-CP1 prepublication gate. Classification rules if it runs RED:
- if it is RED on the CB1 candidate, that is an edge-storage-order dependence, a §11 falsifier-1-class finding;
- its pre-cutover status is unknown, so Review must determine whether CB1 introduced the dependence.

It still carries **no M5 credit**. Row 1's deletion is upheld, because accepted row 446 checks `make_periodic_relation_endpoint_state` outputs against produced edges.

## 10. M6 checkpoint split

### M6-CP1 — product separation

Establish complete A5 occurrence, A6 quotient, and A7 geometry products in bounded Code + Build / artifact-only TB steps. Transitional `build_authoritative_phase_front_mesh(...)` may remain as a thin adapter during the cutover, but semantic occurrence/quotient/embedding decisions must move behind the stage-product APIs. CP1 also gates the focused multi-isolation mechanism identity and proves no coordinate/position weld.

### M6-CP2 — independent verifier

Introduce `SurfaceProductVerifier` consuming immutable A0/A5/A6/A7 products and certificates. It independently recomputes only §6.2 elementary facts and fails typed on every §6.3 malformed-authority class. It never calls producer repair/canonicalization/search routines.

### M6-CP3 — direct production exit

Fresh direct-production evidence must prove:

- equal coordinates/positions without a certified relation remain distinct;
- every A5-owned relation is consumed exactly once;
- source support is exact/shared, with no consumer-specific quantized identity;
- source-row, output-row, and scheduler permutation invariance;
- the unchanged `G4-B002` candidate-extraction + hard-feature tamper contract;
- `G4-B001` strict torus 3/3 re-proof;
- `G4-B004` representative same-produced-authority occurrence/quotient/embedding/verifier chain.

## 11. Frozen falsifiers

The M6 definition is falsified by any implementation that:

1. uses world-space position, lattice coordinate, vector row, output row, scheduler order, representative sheet, hash, or cache index as `OccurrenceId`/`QuotientClassId` equality;
2. lets A5 union occurrences or A7 change A6 quotient/topology;
3. consumes an A5 owned relation zero or more than once, or lets an unrelated valid relation affect the selected quotient;
4. lets the verifier search, infer, repair, substitute, canonicalize, weld, or mutate producer state;
5. credits CP1 mechanism evidence as the direct `G4-B002` or `G4-B004` production proof;
6. treats dormant CB14 identities as M5 evidence or deletes them without the replacement-authority precondition in §9;
7. re-promotes hard features into isolation-sheet authority or weakens `LocalSheetMismatch` to close `G4-B001`;
8. implements `OutputDisposition`/degradation before M7.

Any such result halts the current M6 checkpoint and returns to definition/review rather than being patched downstream.

## 12. Original `M6-DEFN` bounded successor (historical)

The original `M6-DEFN` authorized exactly one successor: **`M6-CP1-CB1`**. That consumed per-turn plan is now folded under `M6_Consolidated_Record.md` §2 and its folded-document index; the semantic CB1 boundary below remains the historical frozen authorization.

CB1 is intentionally limited to the first A5 seam: introduce content-semantic occurrence identity and a complete immutable `SurfaceOccurrenceComplex` producer, make the existing transitional materializer consume that product instead of allocating A5 occurrence authority inline, and perform the two §9 dormant-test deletions. It does **not** implement A6 quotient extraction as a new product, A7 embedding, A8 verifier, selector publication, runtime execution, or any G4 debt closure.

**Current amendment authority:** §M6-DEFN-R1 below supersedes only the seam-incident sheet/certificate portions of §§3–5 and freezes exact successor `M6-DEFN-R1-REV`; the historical CB1 authorization remains provenance only.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | selector449 LF SHA-256 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`; unchanged |
| Decisive claims independently re-derived | current hard-rail/isolation classifier separation; current inline occurrence/quotient/geometry coupling; dormant CB14 selector absence and accepted replacement identities; M6/M7 sequencing |
| Non-vacuity checked | coordinate/position coincidence is explicitly excluded from identity; exact-once ledger can fail at zero/duplicate consumption; verifier repair/search/substitution are explicit falsifiers; direct production remains distinct from mechanism evidence |
| Prior obligations discharged/carried | `M5-CP3-TB1-R16-REV-OBS-01` discharged by §9 no-credit deletion disposition; M6 `G4-B002`, `G4-B001`, and `G4-B004` carried with checkpoint owners in §8 |
| Stable accounting | `51 / 14 / 37`; debt `1`; accepted package/source `10814505512 / e284fea7...`; selector449 accepted |
| New candidates/obligations recorded | M6 A5-A8 stage contract, `G4-B001` CP3 evidence owner, `G4-B004` CP1/CP3 gate split; tracker updated |
| ORIENTATION currency line | `M6-DEFN`, 2026-09-24 |
| ORIENTATION §3 / §4 / §7 / §8 | §3 and §7 updated for M6; §4 unchanged because no witness ran; §8 no new recurring defect pattern |
| CHANGELOG | root and agent changelogs updated for `M6-DEFN` |
| ROADMAP | M6-DEFN marked complete; exact next `M6-CP1-CB1` |
| Selector manifest | n/a — no selector byte added, changed, published, or accepted |
| LESSONS | n/a — no genuinely new recurring process/product pattern; existing identity/authority and no-synthetic-success rules apply |
| Consolidation under CLEAN_UP_POLICY | consumed `Architecture_M6_DEFN_Occurrence_Embedding_Verifier_Plan.md` folded into the new M6 consolidated record/index; frozen definitions and one next-turn plan retained |
| Successor frozen | exactly `M6-CP1-CB1`; falsifiers in this record §11 and successor plan |
| Turn boundary held | runtime-free; no product/test/fixture/selector/benchmark/build mutation; no generated Directional runtime |
| review_check.py boundary | **PASS** — `review_check.py boundary --expect-selector 449=d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`; no product/test/fixture/build or selector mutation; durable markers preserved |
| `STATUS` lifecycle maintained | `M6-DEFN / IN_PROGRESS` at entry; final COMPLETE beacon is the required last repository write |
| Pushed to origin, branch in sync | **CONFIRMED.** Verified Drive patch transport run/job `36028759747 / 107731931289` pushed exact patch SHA-256 `f8429d1f49adf9945b58ed2cf506f4477a5b9ef5872f0b49e3d1c8f7b9f8aab7` with schema validation PASS and `runtimeExecution=false`; owner-side Drive retirement succeeded. Turn-cleanup run/job `36028922947 / 107732420524` removed both M6-DEFN trigger markers; recursive tree verification at cleanup head found exactly the seven durable workflows and no connector-trigger/workflow-observation/turn-payload state. This isolated closeout-row update is applied against the current blob by exact SHA before the final STATUS beacon. |

---

## Independent verification addendum (reviewing agent)

Runtime-free. **UPHELD WITH AMENDMENTS.** The A5/A6/A7/A8-M6 product split, the exact-once owned-relation ledger, the verifier's recompute-only / never-repair boundary, the CP1/CP2/CP3 split, the M7 disposition boundary and the successor `M6-CP1-CB1` all stand.

**Verified:**
- **Clean process.** Docs landed (16:38Z) before the COMPLETE beacon (16:41:45Z), and nothing was written after it. `review_check.py ledgers --base 62b5ed26` PASSes, and no code surface changed.
- **§2/§8.2 `G4-B001` basis.** `RemeshPipeline.cpp:7862-7865` constructs an empty `sourceIsolationBarrierEdges` set and passes it to `classify_source_surface_labels`, as claimed. The last measurement of `G4-B001` is still pre-M1 (0/3 at artifact `9031804178`), so the CP3 re-proof is its first fresh measurement.
- **The `DESIGN.md` A8 row edit** is consistent with DESIGN §14 M7, which already introduces `OutputDisposition`. The dropped "computed, not asserted" wording survives as M7's "labeled by the verifier, never by a producer".

**Amendments:**
1. **§3.3 `CellId` basis was unstated.** `OccurrenceId = (CellId, role)` was declared free of representation handles without examining `CellId`. `CellId` is a canonical rank of (region canonical-face-topology rank, region-chart grid ordinal). Face-row invariance is accepted (selector449 rows 129, 196, 213, 245 and 254), so M6's permutation exclusions hold. The rank renumbers on insertion or omission, which is flagged for `M7-DEFN`. The CB1 permutation test must permute face rows. A note is added in §3.3, with the definition unchanged.
2. **§9 row 2 deletion stopped.** `ProducedTorusPeriodicPairStorageSwapPreservesSemanticDirection` permutes **edge storage** on the nonzero witness. Its named replacement, row 444, permutes the relation container, and no selector449 row permutes edge storage. Front-edge indices are a DESIGN §6.2 representation handle that A5 must not depend on. Under §9's own precondition the identity is retained and proposed for the CP1 prepublication gate. The row-1 deletion stands.
3. **Tracker entries were buried.** This turn appended them at the end of `Regression_Root_Cause_Tracker.md`, below the 9,800-line restored history. They are moved above it, and a placement rule is added at the boundary. This is the third "append at end of a newest-first ledger" instance.
4. **Stale text.** The closed M5 frozen header still said "EXACT NEXT = `M6-DEFN`", and the TODO `G4-B001` item was stale. Both are fixed.

### Review closeout — reviewing-agent addendum

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | selector449 `d4a0d1b7…`, 448 `70ff0860…`, 430 `1c412850…` via `boundary --expect-selector` |
| Decisive claims independently re-derived | `CellId` and `TopologyRegionId` construction from source; face-row invariance rows; the `G4-B001` classifier input; each dormant test against its named replacement's actual permutation; DESIGN M7 ownership of `OutputDisposition`; turn write ordering; `ledgers` |
| Non-vacuity checked | The CB1 permutation test is now required to permute face rows, because storage-only is row 213. The edge-storage witness is retained rather than deleted. |
| Prior obligations discharged/carried | R16 OBS-01 resolved: one deletion, plus one retention with a named gate owner. `G4-B002`, `G4-B001` and `G4-B004` are carried as frozen in §8. |
| Stable accounting | 51 / 14 / 37; debt 1 (M6); entry package `10814505512 / e284fea7…`; selector449 |
| New candidates/obligations recorded | Tracker addendum entry (moved M6-DEFN entries plus a placement rule) |
| ORIENTATION currency line | `M6-DEFN` (incl. reviewing-agent addendum), 2026-09-24 UTC |
| ORIENTATION §3 / §4 / §7 / §8 | §7 items 1 and 5 amended. §3, §4 and §8 are unchanged and correct. |
| CHANGELOG | Agent and root entries amended |
| ROADMAP | n/a — correct |
| Selector manifest | n/a |
| LESSONS | 176 and 178 cited; no new lesson |
| Consolidation under CLEAN_UP_POLICY | n/a — the M6 consolidated record exists and the DEFN plan is indexed |
| Successor frozen | `M6-CP1-CB1`, per its plan plus the binding reviewing-agent amendment |
| Turn boundary held | Runtime-free; no product/test/selector change |
| review_check.py | `boundary --expect-selector 449=d4a0d1b7… 448=70ff0860… 430=1c412850…`: **ALL CHECKS PASSED**. No product/test/build or selector mutation; durable markers 1→1, 3→3, 13→13. `ledgers --base 62b5ed26`: **ALL CHECKS PASSED**. |
| `STATUS` lifecycle | Resume beacon first; final `COMPLETE → M6-CP1-CB1` last |
| Pushed, in sync | Confirmed by `git status -sb` after the final push |
## M6-DEFN-R1 seam-incident authority amendment (2026-09-25, runtime-free)

This amendment supersedes only the earlier singular-sheet/relation-certificate wording described in §§3–5. It freezes the eight decisions in `Architecture_M6_DEFN_R1_Seam_Incident_Occurrence_Sheet_Authority_Definition_Record.md`: corner-wedge sheet sets; wedge/side certificate carriers; owner-less OrdinaryFront membership validation; exact seam-collinear side authority; A7 union completeness; per-wedge face/chart/branch provenance; row140 adapter placement plus duplicate-check removal; and the re-scoped CB4/TB4 7+449 gate. Identity, accepted M5 authority, selector/routing bytes, HardRail/Periodic semantic owners, stable accounting **54 / 16 / 38**, and debt 1 are unchanged. Exact successor is mandatory `M6-DEFN-R1-REV`.

## M6-DEFN-R1-REV review note (2026-09-25, runtime-free)

**Core upheld; not accepted as frozen.** The amendment above is correct in model but incomplete in four blocking respects (`Architecture_M6_DEFN_R1_Review_Record.md` §3):

- **B1.** §5's union makes relation-free seam singletons multi-sheet, which violates frozen focused row5's non-empty-`equivalences` assertion unless wedge evidence is represented in lineage `equivalences`.
- **B2.** The per-binding provenance of §3.2 lacks a selection rule for each transitional consumer.
- **B3.** The §3.2 wedge endpoints must not come from tie-broken segment faces in any of the three side builders.
- **B4.** §3.4/D7 must be reconciled with §4.6.

CB4 must not start until `M6-DEFN-R2` resolves these and `M6-DEFN-R2-REV` accepts.

## M6-DEFN-R2 seam-incident authority amendment (2026-09-25, runtime-free)

`M6-DEFN-R2` resolves the four blockers and four precision items from `M6-DEFN-R1-REV`; normative detail is in `Architecture_M6_DEFN_R2_Seam_Incident_Authority_Amendment_Definition_Record.md`.

- **B1:** lineage now has evidence-only `CornerWedgeIsolation` equivalences carrying ordered exact `(region,seam,fromSheet,toSheet)` transitions. They neither own nor select quotient relations. Split-square v0/center/v2 are therefore multi-sheet with non-empty lineage evidence without inventing v0/v2 relations.
- **B2:** every semantic consumer uses complete per-face wedge binding signatures. Transitional class keys cannot collapse to one sheet/chart; representatives are representation-only; HardRail/Periodic path charts are relation-side bindings; A7 chart/sheet/region projections derive from full binding tuples; remap preserves tuples before projection.
- **B3:** edge collinearity is exact `SourceSupport`, and the semantic incident-cell interior face is selected from canonical accepted cell orientation plus source-edge winding. Uniform, periodic and bounded-disk builders all establish the required orientation premise before A4 acceptance.
- **B4:** A5 relation failures are one-to-one and adapter-mapped to the frozen M5 names. Only duplicate owner/kind structural checks may move earlier; relation content/transport/support falsifiers stay live.
- **P1-P4:** ordered maximal support spans, reciprocal near-endpoint agreement, fail-closed unsupported singular/SingularityPort corners, and hard-rail/region wedge boundaries are explicit. HardRail-adjacent no-seam corners remain single-sheet.

The frozen-test audit covers focused rows 5/6, selector rows 186/214/239/444/446/448 and the Phase10 HardRail single-sheet assertions. No test/selector/routing byte changes. Stable accounting remains **54 / 16 / 38**, debt 1, +0. CB4 remains HELD pending mandatory independent `M6-DEFN-R2-REV`; if accepted, TB4 remains **7 + 449 = 456** fresh exact-filter processes.

## M6-DEFN-R2-REV review amendments RA-1 – RA-10 (normative, 2026-09-25, runtime-free)

`M6-DEFN-R2` is **accepted with the following amendments**. Where they conflict with earlier text in §§3–5, the DEFN-R1 record or the DEFN-R2 record, these govern. Rationale and evidence: `Architecture_M6_DEFN_R2_Review_Record.md` §3.

- **RA-1 — collinear-span interior face.**
  - Internal edge: the incident face whose source winding contains the side's directed edge.
  - Source boundary edge: the single incident face, which must satisfy the same winding test.
  - Hard-rail or topology-region-boundary edge: the winding-selected face, which must also lie in the cell's `TopologyRegionId`.

  Any failed test is a typed A5 failure.
- **RA-2 — `OccurrenceUnsupportedSingularWedge`.** Fires only when the RA-8 fan arc cannot be computed (nonmanifold vertex fan, or an arc not contained in one `TopologyRegionId` and one chart component). It never fires because of a vertex category (boundary, barrier, hard-rail or "excluded" support vertex). `OccurrenceUnsupportedSingularityPort` fires only for a corner that participates in a SingularityPort relation.
- **RA-3 — `OccurrenceUnsupportedHardRailSeamWedge`.** Fires exactly when the RA-8 arc would have to cross a hard-rail edge. For a validated cell this is a fail-closed assertion. A seam edge ending at a rail vertex inside an admissible arc is ordinary wedge evidence.
- **RA-4 — permutation checks in the seventh identity.** These compare only row-invariant semantic data:
  - `OccurrenceId`s;
  - per-occurrence `CornerWedgeSheetSet` and ordered `CornerWedgeIsolation` transitions;
  - per class (keyed by sorted member `OccurrenceId`s): lineage sheets and transitions.

  They never compare `hash_completion`, which hashes source-face rows and front-edge indices. One test-local split-square fixture helper with reversed face rows is permitted for this identity only.
- **RA-5 — `OccurrenceUnownedRelation` and enum `UnownedRelation`.** `OccurrenceUnownedRelation` keeps its current external name, with no legacy remap. The enum `UnownedRelation` continues to cover relation-identity/owner-encoding mismatch in `publish_records_for_validation`, as frozen focused row3 requires. The new owner/kind codes apply to the producer-side conditions only. An out-of-range opposite edge is `RelationEndpointMissing`.
- **RA-6 — lineage sheets.** `sourceIsolationSheets` is exactly the union of member `CornerWedgeSheetSet`s. Directed-side transitions are `equivalences` evidence only and add no sheets.
- **RA-7 — retire the endpoint-equality guard.** The transitional endpoint-sheet-equality guard (`crossesSheets` → `MissingIsolationSeamEquivalenceAuthority`) is removed and replaced by span-membership validation. At the adapter, missing seam evidence for a cross-sheet step maps to `MissingIsolationSeamEquivalenceAuthority`, and an absent or wrong named certificate maps to `InvalidIsolationSeamEquivalenceAuthority`. `QuotientReciprocalSideAuthorityMismatch` keeps its new name.
- **RA-8 — wedge arc.** The arc endpoints are the interior faces of the incoming side's last support span and the outgoing side's first support span: RA-1 for collinear spans, otherwise the face containing the span's open interior. The arc runs counter-clockwise in source winding from the outgoing face to the incoming face around the corner support. Recorded transition orientation stays incoming → outgoing (v0 `1→0`, v2 `0→1`).
- **RA-9 — span support.** Span support is defined by `SurfacePointSourceSupportResolver` (barycentric tolerance `1e-8`) applied to the span's open-interior midpoint and both endpoints. The span is collinear with an edge iff the midpoint resolves to that `SourceEdgeSupport` and the endpoints resolve within that edge's closure. The builder tie-break tolerance plays no part.
- **RA-10 — transitional `QuotientClassId`.** CB4 keeps the transitional ordinal in `lineage.quotientClass` and its hash unchanged in representation. Only the class-key tuple feeding it changes (complete binding signatures). The member-set `QuotientClassId` (§4.3) is realized at A6 extraction, not in CB4.

## RA-11 — per-face branch authority (normative, 2026-09-25, review-agent resolution of the CB4 blocker)

Rationale and evidence: folded RA-11 blocker authority in `M6_Consolidated_Record.md` §16 and git history. This amends D6, R2 §4.1-§4.3 and RA-10's class-key tuple.

1. `CornerWedgeFaceBinding` = `(sourceFaceTopology, IsolationSheetId, SourceProjectionChart)`. It has **no `branchRotation`**.
2. Each occurrence publishes `CornerPlacementProvenance`: the A4 corner `LocalLatticeState` verbatim (phase, coordinate, `branchRotation`, scale, `sourceChart`), labelled with the A4 selected corner face (`cell.corners[c].face` topology key).
   - It is placement provenance only, with builder-specific branch meaning; the periodic builder leaves it `0`.
   - No A5/A6/A7 rule may read it as the branch of any wedge face.
3. Transitional class key = region + complete ordered binding signatures + lattice coordinate + scale + labelled placement provenance `(selected-face topology, branchRotation, sourceChart)`. Representative key = exact support + binding signatures + `OccurrenceId`.
4. "No mixed-face record" means every face-dependent value is published together with the face it is expressed in. Pairing the selected face's `sourceChart` with another face's topology is forbidden.
5. Stop rule: any A5/A6/A7 consumer needing a wedge-face branch returns CB4 to Review. That consumer would trigger an A4 product amendment to publish per-face branch authority. That amendment is rejected for now: no consumer needs it, and the builders have no uniform meaning for the branch.

## RA-12 — site-qualified isolation-failure diagnostics (normative, 2026-09-25, `M6-CP1-TB4-REV` review-agent addendum)

This amends RA-7. The legacy M5 names `MissingIsolationSeamEquivalenceAuthority` and `InvalidIsolationSeamEquivalenceAuthority` are kept as **prefixes**, and each emission site appends a stable suffix:
- `:a5-wedge` / `:a5-side` — A5 `MissingIsolationEvidence` / `MismatchedIsolationEvidence`, raised during wedge-fan or side traversal;
- `:a6-side-evidence` — ordered whole-side evidence certificate lookup;
- `:a6-collinear-span` — collinear endpoint span with no certificate;
- `:a6-seam-span-transition` — seam branch missing the reciprocal span transition;
- `:a6-seam-faces` — certificate faces or sheets mismatch.

Diagnostic only: predicates, ordering and outcomes are unchanged. No test or production code compares these strings exactly (verified at `M6-CP1-TB4-REV`). Rationale: `M6_Consolidated_Record.md` §§19-20; full retired Review text is resolved by that record's folded-document index.

**RA-12 annotation (`M6-CP1-TB5-REV` review-agent addendum):** after CB5, an uncertified collinear span runs the non-seam P2 rule and fails as `QuotientReciprocalSideAuthorityMismatch`. The `:a6-collinear-span` suffix is therefore never emitted. The other suffixes are live.

## CP1 exit scope — restated (`M6-CP1-TB5-REV` review-agent addendum; no new semantics)

M6-CP1 cannot close until, on exact source plus a fresh green gate, all of the following hold:
1. The A5 product is conformant (§3), including retirement of the unread legacy `SurfaceOccurrence` `isolationSheet` / `chart` / `lattice`.
2. The A6 `SurfaceQuotientProduct` exists with member-set `QuotientClassId` (§4.3), one `QuotientRelationCertificate` and one ledger row per owned relation (§4.4), and `QuotientCertificate` / `MaterializationCertificate` (§4.6).
3. The A7 `SourceAttachedGeometryProduct` exists with its certificates (§5).
4. `build_authoritative_phase_front_mesh` is a thin adapter with no semantic decision (§10).
5. The `G4-B002` A6 stage boundary exists (§8.1).
6. There is no coordinate/position weld, and the focused multi-isolation identity is green (§10).

`M6-DEFN-R3` freezes the representation and sequencing decisions for items 2-5.

## M6-DEFN-R3 A6 quotient-product amendment (2026-09-25, runtime-free)

`M6-DEFN-R3` completes the bounded A6 decisions required before quotient extraction. Normative detail and rationale are in `Architecture_M6_DEFN_R3_A6_Product_Separation_Definition_Record.md`; where the points below conflict with the earlier conceptual A6 wording or RA-10, these govern.

- **CP1 exit checklist:** CP1 requires conformant A5 (including retirement of unread `chart/lattice/isolationSheet`), a complete immutable A6 product, later A7 product, thin adapter, no coordinate/position weld, the later `G4-B002` A6 boundary, focused multi-isolation preservation, and a fresh selector449 449/449 gate.
- **Semantic class identity:** A6 uses `pipeline::SurfaceQuotientClassId`, exactly the sorted unique non-empty member `OccurrenceId` vector. Equality and order are member-set semantic; no root/hash/support/lattice/chart/row/position/representative participates. `authority::QuotientClassId` remains an adapter-only ordinal assigned after lexicographic member-set sorting for legacy lineage projection.
- **Exact-once:** every A5-owned relation produces exactly one `QuotientRelationCertificate` and one `QuotientRelationConsumption` row. Disposition is `Joining` or `CycleClosing`; already-connected relations are never skipped.
- **[SUPERSEDED by RA-13 (2026-10-02 review-agent addendum; see end of document) — the residual fallback is revoked and the strict rule restored]** **Transport consistency (amended by TB6-A6 Review):** relation certificates carry one exact relation-oriented `GridAutomorphism`. Joining relations form the deterministic selected relation forest. For a cycle-closing relation, let direct canonical transport be `D : a -> b` and the exact composed selected-forest path transport be `P : a -> b`; publish the exact residual `H = compose(P.inverse(), D)`. `H == identity` is a valid observed case, **not** a universal acceptance precondition. A non-identity residual is exact holonomy evidence unless an independently frozen contract for that relation requires zero residual. `QuotientHolonomyConflict` is reserved for algebraically inconsistent direct/path/residual evidence or violation of such an explicit zero-residual obligation.
- **[SUPERSEDED by RA-13 (2026-10-02 review-agent addendum; see end of document) — the residual fallback is revoked and the strict rule restored]** **Analytical/runtime scope:** the split square, uniform hard-rail rectangle and ordinary-identity classes remain analytically identity-residual cases. Produced cylinder row232 and torus rows444/446/448/449 were pre-registered TB falsifiers. TB6-A6 selector446 plus focused pair-swap row6 triggered the documented fallback while 232/444/448/449 stayed green, proving the universal equality rule too strict for the accepted nonzero-Z4 periodic witness. This Review-authorized amendment preserves exact relation authority and changes only the treatment of cycle residual holonomy.
- **Selected paths:** selection is A6 authority. Each class roots evidence at its smallest semantic member; unique forest paths store ordered relation certificates, orientation, relation-local binding evidence and composed transport. A7 may project but not reselect. Legacy `selectedRelationPaths` projection remains limited to paths containing HardRail/Periodic selected steps, preserving split-square emptiness.
- **A6 errors:** semantic enum names are `SourceAuthorityMismatch`, `RelationEndpointMissing`, `RelationAuthorityConflict`, `RelationCertificateMissing`, `RelationCertificateDuplicate`, `RelationCertificateConflict`, `ReciprocalSideAuthorityMismatch`, `MissingIsolationEvidence`, `InvalidIsolationEvidence`, `InvalidHardRailTransport`, `InvalidPeriodicTransport`, `UnsupportedSingularityPort`, `UnownedRelationUse`, `RelationConsumptionMissing`, `RelationConsumptionDuplicate`, `RelationConsumptionConflict`, `HolonomyConflict`, `InvalidClassPartition`, `MissingOccurrenceMember`, `DegenerateClassedQuad`, `NonBijectiveMaterialization`. External A6 diagnostics use `Quotient` prefix; legacy-name mapping is adapter-only where frozen accepted behavior requires it, including RA-12 isolation prefixes.
- **First A6 CB:** after mandatory `M6-DEFN-R3-REV`, `M6-CP1-CB6-A6` extracts A6 and folds in the legacy A5 field retirement. Four new focused identities are frozen in its plan. Compile-green advances to an immutable gate of **11 focused + selector449 = 460** processes. The previous standalone legacy-field CB6 plan is superseded/held.
- **Deferred:** A7 product representation and the exact `G4-B002` A6 stage-boundary representation are owned by later `M6-DEFN-R4`; R3 records intent only and grants no implementation authorization for them.

Stable accounting remains **55 / 16 / 39**, produced-witness debt **1**, selector449/routing449 bytes unchanged. Exact successor is mandatory `M6-DEFN-R3-REV`; the A6 Code + Build remains held until Review.

## M6-DEFN-R3-REV A6 quotient-product review amendment (normative, 2026-09-25, runtime-free)

`M6-DEFN-R3` is **accepted with RA-1 – RA-4**. Where the R3 definition record or held A6 CB plan conflicts with these rules, these govern. Full evidence and rationale: `Architecture_M6_DEFN_R3_Review_Record.md`.

- **RA-1 — canonical relation-certificate direction.** Every `QuotientRelationCertificate` is oriented `relation.id.first -> relation.id.second`. The separately stored `relation.firstOccurrence` / `secondOccurrence` and `firstFrontEdge` / `secondFrontEdge` are representation provenance only and cannot determine semantic certificate direction. Any exact evidence obtained opposite the canonical direction is inverted before publication.
- **RA-2 — OrdinaryFront quotient transport.** Every accepted `OrdinaryFront` certificate has `GridAutomorphism::identity()` as its quotient relation transport. Checked isolation-seam quarter-turns remain source-chart/sheet validation evidence and are never reapplied as quotient transport.
- **RA-3 — A5 relation evidence completeness.** Frozen A6 still consumes A0 source authority plus one complete A5 occurrence complex. Therefore each A5-owned relation must carry/reference the immutable kind-specific evidence required to validate its RA-1 canonical transport without dereferencing representation-owned front-edge/global arrays. OrdinaryFront transport is identity; HardRail carries its exact accepted owner/route/transport; Periodic carries its exact semantic action plus required route/cut evidence; all non-identity evidence is normalized to canonical endpoint direction. This may enrich A5 relation evidence but may not change relation identity/equality/owner selection or the accepted relation set.
- **[SUPERSEDED by RA-13 (2026-10-02 review-agent addendum; see end of document) — the residual fallback is revoked and the strict rule restored]** **RA-4 — exact path-composition recurrence, with residual amendment.** Traverse from `a` to `b` with `path=identity`; for each certificate edge in traversal order choose its canonical transport or exact inverse according to traversal direction, then set `path=compose(T,path)`. For a cycle-closing relation publish that exact path transport together with the direct canonical transport and residual `H = compose(path.inverse(), direct)`. The path recurrence itself is unchanged.

### M6-CP1-TB6-A6-REV residual-holonomy and HardRail amendment (2026-09-29, runtime-free Review)

> **Residual-holonomy part SUPERSEDED by RA-13 (2026-10-02).** The HardRail reciprocity part below remains in force.

The pre-registered runtime falsifier fired. Mechanically valid TB6-A6 run `36362570974` executes all **11 + 449 = 460** processes and produces exactly four RED identities. Accepted selector446 plus focused pair-swap row6 fail only at `QuotientHolonomyConflict`, while cylinder232 and torus444/448/449 remain green. Review therefore invokes R3's evidence-only fallback: nonidentity `H` is preserved as exact cycle evidence rather than rejected merely for being nonidentity. A7 may later project this evidence but may not use it to change A6 quotient identity/topology. A6 must still prove every constituent certificate exactly matches immutable A5 relation authority in canonical relation direction; certificate tamper is not legitimized as residual holonomy.

The same gate exposes a separate accepted HardRail regression: selector139/142 unexpectedly succeed because A5 HardRail relation publication dropped the accepted reciprocal requirements `first.sourceTopologyRegion != second.sourceTopologyRegion` and `first.route == second.route.reversed()`. **That semantic guard remains frozen.** It belongs at A5 publication before relation evidence becomes immutable and continues to map to accepted `InvalidHardRailTransport`. A6 validates the published certificate against A5 authority; it does not become a duplicate relation-owner.

`M6-CP1-TB6-A6-REV` classifies selector446 as one stable `RP-07 / CYCLIC_TOPOLOGY_LINEARIZATION` recurrence and rows139+142 as one stable `VALIDATION_ORDER_SHADOWING` recurrence. Stable accounting is now **57 / 16 / 41**, debt **1**. Candidate `10896307843 / a532f803...` is rejected/unpromoted; reviewed runtime authority remains `10879581622 / 82b86a28...` under selector449 449/449. Exact next is bounded `M6-CP1-CB7-A6`, then a fresh **11 + 449 = 460** `M6-CP1-TB7-A6-EXEC` and mandatory Review. `M6-DEFN-R4`, A7 and `G4-B002` remain held.

## RA-13 — single-gauge relation transport; strict cycle rule restored (normative, 2026-10-02, `M6-CP1-TB6-A6-REV` review-agent addendum)

This supersedes the TB6-A6-REV residual-holonomy fallback. Rationale is preserved in `M6_Consolidated_Record.md` §§25/28 and lesson 184; the full retired Review text is resolved by the folded-document index.

1. **[Branch-matching mandate WITHDRAWN by RA-16 §1. `LocalLatticeState.branchRotation` is face-gauged, so cross-face branch comparison is valid only in a gauge A4 certifies.]** Every `QuotientRelationCertificate.relationTransport` is the transport between the endpoint occurrences' **placement (cut-domain `LocalLatticeState`) states**, in canonical `relation.id.first → second` direction. A5 publishes it in that gauge and verifies `action_matches(placement(first), placement(second), T)` (coordinate, branch, scale) before freezing the evidence. A mismatch fails closed with `InvalidPeriodicFrontTransport` or `InvalidHardRailTransport`.
2. **OrdinaryFront:** identity (RA-2).
   **Periodic, exact-A3:** `T = Γ_to⁻¹ ∘ g ∘ Γ_from`, with Γ derived from `make_periodic_relation_endpoint_state` as the single authority (Forward: identity in coordinates; Reverse: relation turn Q; branch normalization by `localFaceBranchRotation`). The semantic action `g` is in the PeriodicCut relation-endpoint gauge (`SurfaceCellTracing.h`, the note on `SurfacePeriodicRelationEndpointState`), which is a different authority domain from cut-domain placement (lesson 175).
   **Periodic, non-A3:** the existing cut-gauge action.
   **HardRail:** **[SUPERSEDED by RA-14 below]** the route composed transport, under the same placement check. The TB7 stop condition fired: the carrier route is not the placement-gauge authority.
3. **Strict cycle rule (RA-4):** a cycle-closing relation requires `relationTransport == pathTransport`, else `QuotientHolonomyConflict`. The failure string may carry the residual for diagnosis (`QuotientHolonomyConflict:residual=Q<k>,t=(x,y)`). Non-identity residuals are never accepted as evidence in CP1. A vertex-class cycle is a contractible vertex link, and the legitimate exception (cone singularity at a lattice node) is excluded because A5 fails closed on SingularityPort corners.
4. **[Selector446 prediction corrected by RA-16 §3: 446 also pins the M5 lineage relation value, which RA-13 never authorized changing.]** **Falsifiers (TB7):** selector 446 and focused 6 (nonzero-Z4 witness) PASS under the strict rule; rows 232/444/448/449 stay green. A remaining conflict is classified from its residual suffix by Review. The fallback may return only with a proof of genuine vertex cone holonomy.



## RA-14 — HardRail carrier route and placement transport are separate authorities (normative, 2026-10-03, `M6-CP1-TB7-A6-REV`)

This supersedes only RA-13 item 2's HardRail transport sentence. OrdinaryFront, exact-A3/non-A3 Periodic transport and RA-13 strict cycle equality remain unchanged. Rationale: `Architecture_M6_CP1_TB7_A6_Review_Record.md` §§3-3.3.

1. `PureQuadEquivalenceProvenance.route` is HardRail carrier/topology/transition provenance. Its structural validity, hard-feature ownership and exact reciprocal reversal remain required, but `route.composed_transport()` is not quotient placement authority merely because the route owns the carrier.
**[Items 2-5 SUPERSEDED by RA-16 §2-§3 (review-agent addendum). The branch-derived `R` is face-gauge dependent; publishing the placement map in `equivalence.action` or the selected step rewrites the M5 lineage contract. Items 1 and 6 stand.]**

2. HardRail `canonicalTransport` is the unique cut-domain `LocalLatticeState` transform in canonical relation direction. For placement states `a -> b`, require equal scale, derive `R = branch(b) ∘ branch(a)^-1`, `t = b.coord - rotate(R,a.coord)`, construct `T={R,t}`, and verify the existing exact `action_matches(a,b,T)`.
3. A HardRail relation independently derives this transform for both cross-endpoint pairs (`first.from -> second.to` and `first.to -> second.from`) and requires the two exact transforms to be equal. Any missing/unequal value rejects `InvalidHardRailTransport`.
4. A5 publishes that placement transform in `equivalence.action`, `canonicalTransport` and the canonical selected step while retaining `equivalence.route` separately. A6 consumes that A5 placement transform unchanged.
5. Completion/lineage validates HardRail selected-step transport against orientation-adjusted `equivalence.action`; it continues to validate the retained route independently for source hard-feature topology/components. A consumer may not substitute route-composed carrier transport for placement transport.
6. **Stop rule:** if the two endpoint pairs do not define one unique placement transform, or another current consumer requires route-composed transport to remain quotient placement authority, stop for Review rather than relaxing the endpoint check.

## RA-15 — individual route authority precedes relation-pair reciprocity (normative, 2026-10-03, `M6-CP1-TB7-A6-REV`)

Rows227/230 prove that a malformed individual HardRail route must retain its accepted `InvalidHardRailAuthority` diagnostic instead of being pre-empted by pair-level `InvalidHardRailTransport`.

1. The existing exact individual interior-route/source-transition validator is a single shared predicate and runs before A5 relation-pair publication. **[Location pinned by RA-16 §5: inside A5, not an adapter preflight.]**
2. Malformed HardRail route authority preserves `InvalidHardRailAuthority`; malformed Periodic route/cut authority preserves its existing `InvalidPeriodicCutAuthority` path.
3. Only individually valid routes reach A5 pair-level owner/region/reversed-route checks. Those pair-level failures remain `InvalidHardRailTransport` (including selector139/142).
4. Do not duplicate divergent route-validity semantics downstream; move/extract/reuse the existing predicate and remove or mechanically reuse the later copy.

**[Superseded by the RA-16 accounting line below.]** Stable accounting after TB7 Review is **59 / 16 / 43**, debt **1**. Candidate `11257522199 / 40842caa...` is rejected/unpromoted. Exact successor is `M6-CP1-CB8-A6`, then immutable `M6-CP1-TB8-A6-EXEC` **11+449=460** and mandatory Review.

## RA-16 — placement transport is a lattice-coordinate automorphism; the lineage relation value is a separate authority (normative, 2026-10-03, `M6-CP1-TB7-A6-REV` review-agent addendum)

**What this changes.**
- Supersedes RA-14 items 2-5.
- Withdraws the branch-matching mandate in RA-13 item 1.
- Locates RA-15 item 1.
- Still stand: RA-13 items 2 (OrdinaryFront, Periodic) and 3 (strict cycle rule); RA-14 items 1 and 6; RA-15 items 2-4.
- Rationale: `Architecture_M6_CP1_TB7_A6_Review_Record.md`, review-agent addendum §G2-§G6.

1. **Gauge rule.**
   - `LocalLatticeState.branchRotation` is face-gauged. It equals `faceBranchRotation[selected source face]` (propagated per region from that region's own root) plus the region chart branch (`SurfaceCellTracing.cpp:12094`, `:16324`, `:14920-14985`).
   - A5 must never derive or check a lattice rotation from the branch difference of two states whose selected source faces may differ, unless the comparison is in a gauge A4 certifies:
     - exact-A3 Periodic → the relation-endpoint gauge (published `SurfacePeriodicRelationEndpointState`);
     - non-A3 Periodic → the legacy A4 placement check;
     - HardRail → none in CP1, because A4 certifies no lattice relation across a rail.
2. **HardRail placement transport is coordinate-rigid.**
   - Source states: use the endpoint occurrences' `placement.lattice`, i.e. the cell corner states the relation unites. Do not use the `SurfaceFrontEdge` copies.
   - Pairing: `first.from → second.to` and `first.to → second.from`. Write `c(·)` for a lattice coordinate.
   - Checks and derivation:
     - all four `scaleLevel`s are equal;
     - `e = c(first.to) − c(first.from)` is nonzero;
     - `e' = c(second.from) − c(second.to)`;
     - `R` is the unique `QuarterTurn` with `rotate(R, e) == e'`. If none exists, fail `HardRailTransportMismatch` → `InvalidHardRailTransport`;
     - `t = c(second.to) − rotate(R, c(first.from))`;
     - `T = {R, t}`; verify `T` maps both coordinate pairs.
   - No branch comparison.
   - Publish `T`, in canonical direction, **only** as `canonicalTransport`. On every constant-field fixture this equals RA-14's map, since `τ = 0` and both are the unique rigid map.
3. **The lineage relation value is decoupled.**
   - A5 publishes `canonicalRelationValue` for each relation, in canonical direction:
     - OrdinaryFront: identity;
     - HardRail: `route.composed_transport()`;
     - exact-A3 Periodic: the semantic `g`, oriented `firstIsForward ? g : g⁻¹`;
     - non-A3 Periodic: the existing selected action.
   - `canonicalSelectedStep.appliedTransport = canonicalRelationValue`.
   - `equivalence.action`, `route` and `cutRoute` stay as in M5.
   - A6's HardRail/Periodic certificate checks compare the step's `appliedTransport` with `canonicalRelationValue`. `relationTransport = canonicalTransport`, which keeps the RA-13 strict cycle rule in the placement gauge.
   - The lineage selected-path projection must equal the pre-RA-13 projection on every accepted row.
   - The `PureQuadCompletion` relation-value checks (`:1086-1132`) and selector446 stay unchanged and must PASS.
4. **Exact-A3 Periodic stays as CB7 built it in CP1.**
   - CB7's derivation equals `rot(Q)⁻¹ ∘ g`, with `Q = g.rotation` by A4 convention, whenever it accepts.
   - Replacing its face-gauged final check with coordinate plus relation-gauge checks is an **[owner moved by RA-17 to `M6-DEFN-R5`]** obligation. It requires a witness whose corresponding corners have unequal face gauges.
5. **Location of route validity (RA-15 item 1).**
   - One extracted free predicate, derived from `exact_interior_route_valid`.
   - A5 applies it to both HardRail sides before any pair predicate. Failure code: `HardRailRouteAuthorityInvalid` → `InvalidHardRailAuthority`.
   - The adapter reuses the same function for unpaired and exterior edges. No adapter-wide preflight.
   - Exact-A3 periodic routes are already rejected upstream by A4 (`SurfaceCellTracing.cpp:8218-8225`).
6. **Falsifiers.**
   - Selector446 unchanged, PASS.
   - Selector115 (production completion-ownership check on a HardRail fixture), PASS.
   - New focused identity 12, `M6CP1.RelationPlacementTransportIsCoordinateRigidAndFaceGaugeInvariant` (CB8 plan amendment).
   - TB8 gate: **12 + 449 = 461**.
7. **Stop rules.** Stop for Review if:
   - an accepted fixture pair has no unique `R`;
   - decoupling would require changing `PureQuadCompletion.cpp`, selector446, `equivalence.action`/`route`, or the lineage relation values;
   - A4 visibly rejects the focused-12 relabelled draft.

Stable accounting after the TB7 Review addendum is **60 / 16 / 44**, debt **1**. The extra event is TB7 CAND-03, reclassified as a stable `RP-01` lineage-contract regression. Exact successor: `M6-CP1-CB8-A6` as amended → `M6-CP1-TB8-A6-EXEC` (**12+449=461**) → mandatory `M6-CP1-TB8-A6-REV`.

## RA-17 — transport guard; bounded R4; gauge obligations owned by `M6-DEFN-R5` (normative, 2026-10-03, `M6-CP1-TB8-A6-REV` review-agent addendum)

Rationale: `Architecture_M6_CP1_TB8_A6_Review_Record.md`, addendum §H2-§H3.

1. **Promotion.**
   - `M6-CP1-TB8-A6-EXEC` proves RA-16 recovery at **461/461**: focused 1-12 + selector449.
   - Candidate `11265967968 / 8e0818b1e2f8d12b86c64d8774a3572c5ed5266c` is the reviewed M6 runtime authority.
   - `Architecture_M6_CP1_Required_Green_Focused_12.txt` (SHA-256 `59a523ae2039e0cb537cee550aab6e54936353b8a60234a3915049dc0c3d571c`) becomes a required-green prefix of every later M6 gate, alongside selector449.
2. **Transport guard.**
   - A6 `canonicalTransport` / `QuotientRelationCertificate.relationTransport` has exactly one consumer: the strict cycle rule.
   - A7, the adapter, lineage, chart re-anchoring and completion must not consume it.
   - Lineage selected steps carry `canonicalRelationValue` (RA-16 §3).
   - A7 embeds from exact A5 source support only (§5).
   - A future consumer of placement transport requires a Definition amendment that first discharges item 4's obligations.
3. **Bounded R4.** `M6-DEFN-R4` decides only:
   - A7 representation and certificates, including an exact `SourceSupport` incidence predicate that replaces the adapter's epsilon position check as authority;
   - the thin-adapter classification of all 55 failure sites;
   - the `G4-B002` A6 boundary and its CP1 equivalence demonstration;
   - the consumer/frozen-assertion census;
   - CB sequencing.

   The full scope is in the R4 plan. The first A7 CB must register `M6CP1.NonzeroZ4WitnessPassesProductionCompletionOwnership`.
4. **`M6-DEFN-R5` (CP3-entry gate) owns RA-16 §4 and the TB7 addendum §G5:**
   - the periodic unequal-face-gauge witness, plus the coordinate / relation-gauge rule;
   - HardRail cross-region branch certification;
   - OrdinaryFront coordinate identity across isolation seams.

   These do not block CP1 closure, because item 2's guard keeps them away from geometry. They must close before any CP3 direct-production TB.

Stable accounting **60 / 16 / 44**, debt 1. Exact next: `M6-DEFN-R4` → mandatory `M6-DEFN-R4-REV`.

## M6-DEFN-R4 A7 / thin-adapter / `G4-B002` boundary amendment (2026-10-03, runtime-free; **REVIEWED by `M6-DEFN-R4-REV`: accepted with RA-18 – RA-21, below**)

`M6-DEFN-R4` freezes the remaining CP1 product-boundary definitions. Full normative detail and rationale are in `Architecture_M6_DEFN_R4_A7_Boundary_Definition_Record.md`. This amendment is Definition authority but remains **HELD FOR `M6-DEFN-R4-REV`** before implementation.

1. **[Amended by RA-18: the support certificate adds a fail-closed same-simplex point-coincidence validation.]** **A7 is an immutable stage product.** `SourceAttachedGeometryProduct` publishes exactly one source-attached vertex per A6 `SurfaceQuotientClassId`, copies A6 classed-cell topology unchanged, and certifies class bijection, topology copy, complete support and no placement-transport consumption. Exact `SourceSupport` typed identity + source-face incidence replaces the adapter's `1e-9` position comparison as semantic authority. Cross-kind coercion is forbidden. The deterministic representation-only representative remains the lexicographic minimum of `(support, cornerWedgeBindings, OccurrenceId)`; it supplies compatibility point/position only, never semantic quotient identity.
2. **A7 lineage is class-wide A5/A6 authority.** Occurrence members, charts, wedge-union isolation sheets, topology regions, equivalences and selected paths are projected from immutable A5/A6 evidence. Selected relation steps retain `canonicalRelationValue`; A7 never consumes `canonicalTransport` / `relationTransport` for geometry, lineage, chart re-anchoring or completion input. No new A7 metadata enters existing completion/quality hashes.
3. **[Amended by RA-19: placement of moved checks inside A5; identity 24 made behavioral.]** **The legacy materializer becomes thin.** `build_authoritative_phase_front_mesh` may invoke A5/A6/A7, map already-produced typed errors and serialize immutable products. It may not perform semantic predicates, topology/quotient/support/representative selection, relation search, floating tolerance checks, welds or repair. The current 55 literal failure sites are partitioned **31 A5 + 4 A6 projection + 19 A7 + 1 serialization**; stage precedence is A5 -> A6 -> A7 -> serialization, preserving frozen `FalseAuthoritativeSourceBoundary`, `InvalidHardRailAuthority` and `InvalidHardRailTransport` behavior.
4. **[Amended by RA-20: protection comes from source hard-feature authority, not relation kind.]** **A6 owns a closed-complex candidate boundary.** `SurfaceQuotientClosedComplexView` is derived during A6 from A5/A6 authority, with member-set quotient vertices, classed quads, side-incidence edge identity, exact HardRail/Periodic owner labels and topology-derived opposite-edge strip identity. Candidate extraction consumes this boundary without `SurfaceCellPipelineContext::hasArrangement`; HardRail is protected, Periodic is an interior quotient seam, and no coordinate/hash equality defines identity.
5. **[Amended by RA-21: executable key path and stop rule. The torus's 18 user hard edges are carried by PeriodicCut relations, not A5 `HardRail` relations.]** **`G4-B002` CP1 mechanism proof.** On the existing produced closed torus fixture (`milestone-g/torus.obj` + `.rawfield`, same 18 HardRails), CB11 proves labeled combinatorial isomorphism to retained comparison authority: quad/edge incidence, exact HardRail/Periodic labels and sorted occurrence-member vertex lineage, all without positional matching. An independent candidate oracle proves one eligible path/loop candidate and a mechanism-only HardRail tamper removes that exact candidate. This **does not close the debt**; M6-CP3 retains the unchanged direct-production eligibility + hard-feature tamper proof.
6. **Frozen implementation sequence after R4 Review:** CB9 A7 (focused 13-20; gate **20+449=469**), TB9 + Review; CB10 A5-validation migration (focused 21-24; **24+449=473**), TB10 + Review; CB11 G4 boundary (focused 25-28; **28+449=477**), TB11 + Review; then `M6-CP1-CLOSE-REV`. The first A7 CB includes `M6CP1.NonzeroZ4WitnessPassesProductionCompletionOwnership` executing the real production completion-ownership validator. Each successor focused list preserves the frozen focused-12 bytes and preceding list as an exact prefix; selector449 remains unchanged.
7. **R5 remains separate.** Unequal-face-gauge exact-A3 Periodic authority, HardRail cross-region branch certification and OrdinaryFront isolation-seam coordinate identity remain owned by `M6-DEFN-R5` as a CP3-entry gate. The RA-17 transport guard keeps them out of CP1 A7 geometry and the A6 closed-complex boundary.

Stable accounting remains **60 / 16 / 44**, produced-witness debt **1**. Exact successor from this Definition is mandatory `M6-DEFN-R4-REV`; no CB is authorized until that Review accepts or amends this record.

## RA-18 – RA-21 — `M6-DEFN-R4-REV` binding amendments (normative, 2026-10-03)

Rationale: `Architecture_M6_DEFN_R4_Review_Record.md` §2 (F1–F5).

### RA-18 — support authority and a reject-only point-coincidence guard (amends R4 D1 §2.2; supersedes RA-17 §3's "diagnostic only" wording for the old check)

1. **Authority.**
   - `SourceSupportCertificate.publishedSupport` and every member comparison use the A5 value `SurfaceOccurrence::support` only.
   - A7 never re-resolves support from a point.
   - A5's resolver barycentric tolerance (`SurfacePointSourceSupportResolver`, `1e-8`) is the single floating classification in the support chain, and it is A5-owned.
   - Typed equality and face incidence are exactly as R4 D1 §2.2 states, with no cross-kind coercion.
2. **Reject-only coincidence guard.** After typed equality holds, A7 checks that every member denotes the same point **in that simplex's own coordinates**:
   - vertex support: trivially the same point;
   - edge support `{a,b}` with canonical `a < b`: `t(o) = β_b / (β_a + β_b)`, computed from the member's own face barycentrics. All members must satisfy `|t(o) − t(rep)| ≤ τ`;
   - face-interior support `{f}`: the members' barycentrics in face `f` must agree per component within `τ`.

   `τ` is the A5 resolver barycentric tolerance (dimensionless). A violation fails closed with `SourceSupportPointMismatch` (`:support-point`).
3. **What the guard may do.** It may only **reject**. It never accepts, merges, splits, selects a representative or support, alters lineage, or sets a positive certificate bit. This is validation, not the recovery that §5.3 forbids.
4. **Replacement.** It replaces the adapter's `1e-9` relative position check (`QuotientGeometryConsistencyFailure`). The old check is removed only in the same Code + Build that installs this guard.
5. **Test identity.** Identity 15 becomes `M6CP1.A7RejectsSupportKindIdentityAndSameSimplexPointMismatches`. It adds two negatives that the typed rule alone would accept:
   - same edge support at different parameters;
   - same face support at different barycentrics.

### RA-19 — where moved validation goes inside A5, and identity 24 (amends R4 D2 §3.4 and D5 §5.2)

1. **Placement.** Category-(a) checks moved into A5 run **after every check A5 performs today**, in their current relative order, including the per-edge loop order. This preserves the observable precedence for rows 212, 227/230 and 139/140/142.
2. **Placement exception.** A moved check may run earlier only if the CB10 report shows, for each required test that can reach both checks, that the outcome is unchanged.
3. **Identity 24** becomes `M6CP1.ThinAdapterOutputIsPureProjectionOfStageProducts`.
   - On at least the hard-rail, split-isolation and produced-torus fixtures, the adapter's mesh, provenance and lineage must equal an independent test-side serialization of the A5/A6/A7 products.
   - A stage-valid input must never be rejected by the adapter.
4. **Static check, not a test.** The rule "no semantic literal or tolerance in the adapter" is a static Code + Build / Review check recorded in the CB10 report: failure assignments only inside typed-error mapping, and no floating-point literal comparison. It is not a gtest that reads source text.

### RA-20 — candidate protection comes from source hard-feature authority (amends R4 D3 §4.1–§4.3)

1. **Two independent attributes per quotient edge.**
   - (i) `relationKind`, which is Ordinary / HardRail / Periodic, derived from A6 certificates exactly as R4 §4.2 states.
   - (ii) `hardFeatureProtected`, derived from **typed source hard-feature authority**: the authoritative HardFeature rail-edge set that production passes to completion as `hardFeatureRailEdges`. It must be supplied to A6 boundary construction as an explicit typed input.
   - An edge is protected iff every carrier route step lies in that set.
2. **Consistency.** A `HardRail` edge must be protected; a mismatch fails closed. A `Periodic` edge whose cut carrier lies on hard-feature edges **is protected**.
3. **Candidate extraction** maps `hardFeatureProtected` to `touchesHardFeature`, never `relationKind`.
4. **Barrier set.** The boundary must not reuse A5's chart-barrier set. That set is built from HardRail front routes only (`RemeshPipeline.cpp:3323-3331`). Whether that asymmetry matters for A5 charts is a recorded `M6-DEFN-R5` census item.
5. **Fixture correction.** On the produced torus, all 18 user hard edges are carried by PeriodicCut relations, because the torus is one region and A5 HardRail requires distinct regions. They must come out protected.

### RA-21 — an executable equivalence oracle, with a stop rule (amends R4 D3 §4.4)

1. **Key path.** Before writing identity 25, the CB11 author must establish statically, and record in the CB11 report, the map from arrangement halfedge `(proposalId, proposalSide)` via `network.proposals[proposalId]` to A4 `CellId` and side.
   - Arrangement nodes carry no occurrence members.
   - The vertex bijection is therefore induced from quad and side incidence through that map. A6-side member-set lineage is checked only on the A6 side (identity 27).
2. **Labels.** Compare `hardFeatureProtected` with the arrangement's `hardFeature`, and HardRail/Periodic owners where both sides publish them.
3. **Stop rule.** Stop for Review instead of weakening the oracle if any of these hold:
   - the map does not exist or is not injective;
   - the arrangement subdivides proposal cells (traced, non-proposal arcs);
   - the two complexes are not isomorphic.

   Review then chooses between a subdivision-equivalence oracle and a different comparison authority.
4. **No proximity matching.** Positions, epsilons and hashes still may not establish any bijection.

Gate sizes are unchanged: CB9 **20+449=469**, CB10 **24+449=473**, CB11 **28+449=477**. Stable accounting **60 / 16 / 44**, debt 1. Exact next: `M6-CP1-CB9-A7`.

## RA-22 — class-wide A7 completion destination authority (normative, `M6-CP1-TB9-A7-REV`, 2026-10-04)

Rationale and independent evidence: `Architecture_M6_CP1_TB9_A7_Review_Record.md`.

1. **Representative is not semantic destination authority.** When `PureQuadVertexLineage::sourceOccurrences` is nonempty, the lineage came from A7 occurrence-binding authority. `sourcePoint` remains compatibility/representation data only. Its face's topology region, isolation sheet and source component may not select or narrow relation-destination authority.
2. **Retained A7 sets are semantic authority.** `sourceCharts`, `sourceTopologyRegions` and `sourceIsolationSheets` are the complete class-wide A7 projections. A selected relation endpoint chart must be an exact retained chart; its region must be a retained region and its sheet must be a retained sheet. In particular, a destination sheet is **not** required to equal the representative face's sheet.
3. **Component is class-wide and singleton.** Completion derives the component set by resolving every retained A7 chart through `SourceChartTransitionGraph::source_component`. Every chart must resolve and the unique set must contain exactly one component; otherwise completion fails closed. A selected relation destination must belong to that singleton component.
4. **No semantic widening.** RA-22 authorizes no relation search, alternate path, endpoint substitution, chart rebind, tolerance weld, topology mutation or placement-transport consumption. Existing exact support, selected-path endpoint, path-continuity, relation-value and composed-transport checks remain unchanged.
5. **Legacy isolation.** Lineage with no A7 occurrence-binding authority (`sourceOccurrences.empty()`) keeps the established selected-face singleton closure. RA-22 changes only A7-lineage consumption.
6. **Recovery gate.** `M6-CP1-CB9-A7-R1` is limited to this completion integration seam. Its compile-green candidate must rerun the unchanged focused20 + selector449 = **469** artifact-only gate, then mandatory `M6-CP1-TB9-A7-R1-REV`. Focused-20, selector449, fixtures, A7 producer semantics and CB10/CB11 reserved identities remain frozen.

Stable accounting remains **60 / 16 / 44**, produced-witness debt **1**. CB9 candidate `11287202960 / b8d27b63...` is rejected/unpromoted; reviewed runtime remains TB8 `11265967968 / 8e0818b1...` until recovery Review.

## RA-22a — site-qualified completion diagnostics, and A7 gaps recorded (normative, 2026-10-04, `M6-CP1-TB9-A7-REV` review-agent addendum)

Rationale: `Architecture_M6_CP1_TB9_A7_Review_Record.md`, addendum §H2–§H4.

1. **Operative clause.** The TB9 failure is deduced statically: on the witness, the false clause is `candidateSheet != selectedSheet`. The end chart's resolution, region membership and component equality are all already enforced before the predicate.
   - RA-22 item 4 (sheet membership in the retained A7 sheets) is the operative repair.
   - Items 3 and 5 are kept as fail-closed restatements.
2. **Diagnostics.** R1 must suffix `CompletionOwnershipInvalidSelectedRelationDestination` by subclause: `:dest-unresolved`, `:dest-region`, `:dest-sheet` or `:dest-component`. The RA-22 item 5 failure is emitted as `CompletionOwnershipInvalidRetainedSourceAuthority:component-singleton`. No test or production code compares these strings exactly. No predicate changes.
3. **Recorded A7 gap — cross-sheet proxy (owner: `M6-CP1-CLOSE-REV`).**
   - A7's `UncertifiedCrossSheetBinding` accepts a crossing if *any* isolation evidence exists on the relation, or *any* `cornerWedgeIsolation` exists on either occurrence. It does not check that the evidence connects the two sheets crossed.
   - Before CP1 closes, the check must either become exact, or be removed with the certificate stating that A6 is the cross-sheet certifier. `relationEvidenceSufficient` must not claim more than is checked.
4. **Recorded A7 gap — `τ` single-sourced (owner: `M6-CP1-CB10-A5V`).** A5 support classification and the A7 point guard must read one shared tolerance constant or accessor. Today each builds its own default resolver.

Accounting **60 / 16 / 44**, debt 1. Exact next: `M6-CP1-CB9-A7-R1`.

## RA-22b — the representative-face consistency guard stays, reject-only (normative, 2026-10-04, `M6-CP1-TB9-A7-R1-REV` review-agent addendum)

Rationale: `Architecture_M6_CP1_TB9_A7_R1_Review_Record.md`, addendum §I2–§I4.

1. **Restore the guard.** For A7 lineage (`sourceOccurrences` non-empty), completion requires `region_for_row(sourcePoint.face) ∈ sourceTopologyRegions` and `sheet_for_row(sourcePoint.face) ∈ sourceIsolationSheets`. Failure is `CompletionOwnershipInvalidRetainedSourceAuthority:representative-face`.
2. **It only rejects.** It never decides destination, component, chart or lineage; RA-22 item 1 is unchanged. R1 (`584f80fe`) removed it without authorization.
3. **Why this is safe.** All 469 TB9 processes on pre-R1 source satisfied it, so restoring it is gate-neutral.
4. **Owner and test.** Owner: `M6-CP1-CB10-A5V` Goal T2. Focused 20's body gains a negative: drop the representative face's sheet from a multi-sheet A7 vertex's `sourceIsolationSheets` and expect the `:representative-face` code. The identity name and the focused-20 list are unchanged.
5. **Audit obligation (owner: `M6-CP1-CLOSE-REV`).** Every remaining consumer that reads a `sourcePoint` or `vertexProvenance` face is classified as class-wide, representation-only or anchor-assuming:
   - final validator `resolve_compatible_chart`;
   - `project_surface_cell_vertex_chart_authority`;
   - optimizer source-point rebinding;
   - `BenchmarkQuality`.

   Any anchor-assuming consumer blocks CP1 closure.

Accounting **60 / 16 / 44**, debt 1. Exact next: `M6-CP1-CB10-A5V`.

## RA-19a — after the reorder, moved checks bind to the published A5 complex; identity 24's exact oracle (normative, 2026-10-04, `M6-CP1-TB10-A5V-REV` review-agent addendum)

Rationale: `Architecture_M6_CP1_TB10_A5V_Review_Record.md`, addendum §J2–§J3.

1. **Binding.**
   - The category-(a) helper runs only after `publish_records_for_validation` has returned a valid `SurfaceOccurrenceComplex`, and it validates against that published complex.
   - The side-count predicate is `edgeByCellSide.size() == complex.certificate().directedSideCount`, with every `complex.cells()` side mapped, as before CB10.
   - The 28 other moved predicates stay verbatim; the normalized-diff verification is in §J2.
2. **Identity 24's oracle** is the exact field table in §J3.
   - In-contract fields are compared exactly against values derived from the stage products, or against fixed compatibility constants.
   - All other fields are compared against their defaults.
   - Discovering any other adapter-written field is a stop for Review.
3. **Recorded for `M6-CP1-CLOSE-REV` (not blocking).** CB10 merged three unpinned legacy literals into existing A5 codes (§J2 item 3). Two distinct causes now share `OccurrenceSourceAuthorityMismatch`; this is a lesson-181 diagnosability loss to resolve at CP1 close.

Accounting **60 / 16 / 44**, debt 1. Exact next: `M6-CP1-CB10-A5V-R1`.

## RA-21b — the CB11 migration oracle is a provenance-chain, subdivision-equivalence check (normative, 2026-10-04, `M6-CP1-TB10-A5V-R1-REV` review-agent addendum; amends RA-21 items 1 and 3)

Rationale: `Architecture_M6_CP1_TB10_A5V_R1_Review_Record.md`, addendum §K3.

1. **Positional preconditions.** These must be asserted in the test before any use:
   - `network.proposals.size() == phaseFront.cells().size()`;
   - for every row `r`: `proposals[r].corners == cells[r].corners` and `proposals[r].boundaryPaths == cells[r].boundaryPaths`.

   Then the key is `proposalId r` → `phaseFront.cells()[r].id`. The proposal carries no `CellId` by design, so the positional map is valid only under these preconditions.
2. **Key: provenance entries, not `halfedge.proposalId`.**
   - For each A4 cell row `r` and side `s`, the **side chain** is every arrangement halfedge whose `provenance` contains an entry `(proposalId=r, proposalSide=s)`, ordered by `(proposalBoundarySegment, sourceT0)`.
   - `halfedge.proposalId` holds only the primary entry and must not be used as the key.
3. **Equivalence up to degree-2 contraction.**
   - Every interior node of a side chain must have exactly two distinct incident undirected edges, both in that same chain.
   - Contracting each chain to a single edge must give a labelled combinatorial isomorphism with the A6 closed-complex view. Its vertices are the chain end nodes ↔ the A6 classes of the cell's corner occurrences, its quads are the proposal cycles ↔ the A6 classed quads, and its edges are the chains ↔ `SurfaceQuotientEdgeId`.
   - The two cells sharing an edge must contribute the same chain, in opposite orientation, through two provenance entries.
4. **Labels.** Every halfedge in a chain must carry the same `hardFeature` value, equal to the quotient edge's `hardFeatureProtected` (RA-20). Disagreement within a chain is a stop.
5. **Stop rule (RA-21 item 3, narrowed).** Stop for Review instead of weakening the oracle if any of these hold:
   - a positional precondition fails;
   - an arrangement halfedge has no proposal provenance (a seed trace, separatrix or inserted rail arc);
   - an interior chain node has degree other than 2;
   - two cells' chains for a shared edge differ;
   - a sliver or extra cell exists;
   - the contracted complexes are not isomorphic.
6. **Unchanged.** Positions, epsilons and hashes still establish no bijection. Production candidate extraction still consumes the A6 view directly, never the arrangement.

Accounting **60 / 16 / 44**, debt 1. Exact next: `M6-CP1-CB11-G4`.

## RA-21c / RA-23 — TB11 Review corrections to the CB11 migration oracle and CP1 mechanism witness (normative, 2026-10-04)

Rationale: `Architecture_M6_CP1_TB11_G4_Review_Record.md` §§2-4. TB11 ordinal25 proved RA-21b wrongly equated quotient identity with physical arrangement identity across relation seams; ordinal28 proved the old arrangement `(family,strand)` non-vacuity result did not transfer to the new quotient opposite-edge strip model.

### RA-21c — per-occurrence/per-side subdivision witness

RA-21b items 2-5 are amended. The arrangement comparison is a per-proposal-side subdivision witness only. Each `(proposalId, proposalSide)` provenance chain must be degree-2 and each A4 corner occurrence must be the unique node intersection of its adjacent side chains. A6 edge pairing is then verified from exact phase-front `(filledCell,filledSide)` reciprocal `oppositeEdge` authority plus A5/A6 endpoint relations and typed owners. Occurrences in one quotient class need not map to one arrangement node, and the two incident sides of one quotient edge need not be the same arrangement chain. Each side's chain endpoints must match its own occurrence-node witnesses. Per-chain hard-feature consistency remains exact. Position/epsilon/hash matching remains forbidden. Any missing provenance, non-degree-2 chain, non-unique occurrence intersection, non-reciprocal side ownership, relation/owner disagreement, per-side endpoint disagreement, or extra/sliver cell is a stop for Review.

### RA-23 — CP1 produced-boundary checks versus mechanism non-vacuity

**[Amended by RA-24 (review-agent addendum). Item 2's synthetic torus is WITHDRAWN as the non-vacuity requirement, because the CB11 extractor emits nothing on any closed quad complex under rule 7. Identity 28's non-vacuity and tamper return to the produced torus under edge-loop strips. Item 1's universal checks stay, applied to the edge-loop reconstruction.]**

R4 §4.4 no longer infers quotient-strip non-vacuity from the retained arrangement candidate test. On the produced torus, identity28 independently reconstructs opposite-edge strip closure and validates every emitted candidate, but an empty candidate set is not itself a CP1 failure. Mechanism-only non-vacuity and hard-feature filtering are proved on a canonical test-side closed `4 x 4` toroidal A6 view with two-sided edges, valence-four vertices and independently derived strip ordinals. It must emit an independently eligible closed-loop candidate, and marking one exact candidate edge `hardFeatureProtected=true` must remove that exact candidate. This synthetic mechanism witness grants zero `G4-B002` debt credit; M6-CP3 retains the unchanged direct-production non-vacuity + hard-feature-tamper obligation. Focused identity names/order and focused28 list bytes remain unchanged.

**[R1 scope superseded by RA-24: one bounded production change to the A6 strip relation is authorized.]** Exact next after this Review is `M6-CP1-CB11-G4-R1`, test-authority recovery only; semantic A5/A6 product changes are not authorized. Compile-green R1 -> `M6-CP1-TB11-G4-R1-EXEC` 28+449=477 -> mandatory `M6-CP1-TB11-G4-R1-REV`. Accounting remains **60 / 16 / 44**, debt 1.

## RA-21d and RA-24 — `M6-CP1-TB11-G4-REV` review-agent corrections (normative, 2026-10-04)

Rationale: `Architecture_M6_CP1_TB11_G4_Review_Record.md`, addendum §L2–§L4.

### RA-24 — quotient strip identity is edge-loop (strand) closure (supersedes R4 D3 §4.3 rule 7)

1. **Continuation rule.** At every quotient vertex `v` that is interior (all incident edges two-sided) and has quotient valence 4, each incident edge `e` continues to `opposite_v(e)`: the unique other incident edge at `v` that shares no classed quad with `e`. Union `e` with `opposite_v(e)`.
   - Boundary vertices and vertices of valence other than 4 continue nothing; chains terminate there.
   - The rule is derived only from the view's quads and side incidence. No geometry, position or hash is used.
2. **`stripOrdinal`.** Each resulting class is an edge loop or edge path. `stripOrdinal` is its deterministic ordinal, ordered by smallest `SurfaceQuotientEdgeId` as before.
3. **Unchanged.** Candidate classification (path degree), protection (`hardFeatureProtected` / boundary / valence-singularity), side feasibility, labels and every A5/A6/A7 rule.
4. **Why.** The quad-opposite relation of rule 7 yields rung sets (matchings), so every strip with two or more rungs has all vertices at degree 1, and the classifier rejects it. The retired arrangement extractor used `(family, strand)` curves split into connected components, i.e. edge chains. Edge-loop closure is the topology-derived analogue it intended.
5. **Witness.** Identity 28 uses the produced torus:
   - **Non-vacuity:** require at least one independently eligible `ClosedLoop`. Expected: loops parallel to, but not on, the two hard cycles.
   - **Tamper:** mark one edge of that exact candidate `hardFeatureProtected=true`. It must become independently ineligible and absent from extraction.
   - **Universal checks:** independently reconstruct the edge-loop partition from `view.quads` and side incidence, require every `stripOrdinal` to match it, and independently validate every emitted candidate.
   - If the produced torus still has no eligible candidate under RA-24, stop for Review.
   - This is still CP1 mechanism evidence and grants zero `G4-B002` debt credit; CP3 keeps the direct-production requirement.
6. **Production scope.** Only the strip relation inside `build_surface_quotient_closed_complex_view` changes. The extractor and everything else stay as they are.

### RA-21d — keep physical identity where no barrier exists (amends RA-21c items 3 and 5)

1. **Ordinary edges.** For a quotient edge with `relationKind == Ordinary` whose endpoint relations carry no isolation transition, the two incident sides' chains must be the **same undirected arrangement edge set**, holding two opposite-orientation provenance entries.
2. **Ordinary-linked occurrences.** Two occurrences joined by such an `OrdinaryFront` relation must have the **same** occurrence-node witness.
3. **Where relaxation applies.** The RA-21c per-side relaxation applies only to HardRail edges, Periodic edges, and Ordinary edges carrying isolation transitions, and to occurrence pairs joined through them.
4. **Stop rule.** Any Ordinary non-isolation disagreement is a stop for Review. It would mean the arrangement splits outside barriers.

Accounting **60 / 16 / 44**, debt 1. Exact next: `M6-CP1-CB11-G4-R1`, re-scoped.

## RA-25 — fail-closed strip continuation and CP1 close-out routing (normative, 2026-10-05, `M6-CP1-TB11-G4-R1-REV` review-agent addendum)

Rationale: `Architecture_M6_CP1_TB11_G4_R1_Review_Record.md`, addendum §N2–§N3.

1. **Fail-closed continuation.** At an interior valence-4 quotient vertex, if an incident edge does not have exactly one incident edge sharing no classed quad with it, `build_surface_quotient_closed_complex_view` fails closed with `ClosedComplexStripContinuationMismatch`. A silent skip is not permitted. This refines RA-24 item 1.
2. **Close-out routing.** The CP1 carried obligations are executed in `M6-CP1-CB12-CLOSE` (`Architecture_M6_CP1_CB12_Close_Out_Code_Build_Plan.md`), not in a runtime-free close Review:
   - exact A7 cross-sheet certification through `CornerWedgeIsolationTransition.fromSheet/toSheet`;
   - distinct A5 phase-front source diagnostics;
   - the `consumedInternalIsolationSeams` counter sourced from A5;
   - item 1;
   - the provenance-face consumer audit.
3. **Gate and sequence.** `M6-CP1-TB12-CLOSE-EXEC` runs focused-30 + selector449 = **479**, followed by `M6-CP1-TB12-CLOSE-REV`. Then `M6-CP1-CLOSE-REV` verifies the six CP1 exit items against exact source and that fresh gate, and that every RA-19a/RA-22a/RA-22b/RA-25 obligation is discharged.
4. **Stop rule.** Any anchor-assuming consumer found by the audit, or any C1 rejection of a previously accepted row, is a stop for Review.

Accounting **60 / 16 / 44**, debt 1. Exact next: `M6-CP1-CB12-CLOSE`.

## RA-26 — provenance-face consumer classes; CB12 C5 stop discharged (normative, 2026-10-05, `M6-CP1-CB12-CLOSE-REV`; amends RA-22b §5 and RA-25 §2)

Rationale: `Architecture_M6_CP1_CB12_Close_Stop_Review_Record.md` §2–§4.

1. **Subject.** A provenance-face consumer reads the face of an A7 representative point: `PureQuadVertexLineage::sourcePoint.face`, `vertexProvenance[v].face`, or optimizer `provenance[v].face` derived from them. A site that reads only source-mesh incidence is not one.
   - So `make_surface_optimization_overlay` (`SurfaceMeshOptimizer.cpp:3015-3031`, test-only) is outside RA-22b §5. Its source-row-order scope choice is `M6-CP1-CB12-REV-OBS-01`, owner M8-CP2.
2. **Classes** (replaces "anchor-assuming" in RA-22b §5):
   - **Authority-deciding:** the anchor face decides destination, component, sheet or chart membership, lineage, topology, certificate content, or a membership/consistency verdict. **This class blocks CP1 closure.**
   - **Reference-selecting:** the anchor face selects a continuous reference (normal, field, projection scope) for an energy or a quality metric. Positions stay on the class-common support and no certificate changes. **This class does not block CP1.** It is owned by item 5.
3. **Binding C5 record.** Review record §3, 12 sites. No authority-deciding consumer exists. The reference-selecting sites are:
   - optimizer energy (`:1470-1485`, `:1505`) and gradient (`:1957-1965`, `:2001`, `:2124`), which take their normal/field reference from quad corner 0's representative face;
   - the final-validation field metric's empty-common-chart fallback (`:2675`), which projects within the first endpoint's anchor scope.
4. **CB12 routing.** C5 is discharged by item 3.
   - `M6-CP1-CB12-CLOSE-R1` (a new turn) executes CB12 plan C1–C4 and identities 29/30 unchanged.
   - It makes **no optimizer or final-validation change**.
   - Gate: focused-30 + selector449 = 479.
   - `M6-CP1-CLOSE-REV` re-verifies at its HEAD that no authority-deciding provenance-face consumer exists.
5. **Re-homed obligations** (owner `M6-DEFN-R5` to define; `M6-CP3` to discharge under its permutation-invariance exit):
   1. a class-wide quad reference for optimizer energy/gradient normal and field, for example the `resolve_compatible_chart` chart used by `quad_reference_surface_point`, with a cost bound under finite differences and line search;
   2. a class-wide fallback for the final-validation field metric (the quad's resolved chart faces instead of the first endpoint's anchor scope);
   3. replace the vacuous `project_vertices` component/sheet checks (`:820-:880`, which compare the anchor with itself on the authoritative path) with membership in the class's `vertexChartAuthority` sheets, or retire them to the M6-CP2 verifier;
   4. falsifier: one produced fixture under a source-face row permutation **and** an output quad corner rotation that changes at least one multi-sheet class's representative face and at least one quad's corner 0. Optimized positions, all validation metrics and acceptance must be invariant, under the equality DEFN-R5 freezes.

Accounting **60 / 16 / 44**, debt 1. Exact next: `M6-CP1-CB12-CLOSE-R1`.

## RA-27 — selected-cross-sheet witness recovery (normative, 2026-10-05, `M6-CP1-TB12-CLOSE-REV`)

Rationale: `Architecture_M6_CP1_TB12_Close_Review_Record.md`.

1. **CAND-01 classification.** Identity29's TB12 RED is a false rejection caused by a fixture-witness assumption. `split_isolation_fixture()` is not required to place a cross-sheet relation in A6's selected spanning forest. The absence of such an edge is not a production-selection defect.
2. **C1 remains exact.** For every selected-forest edge whose endpoint wedge-sheet sets are disjoint, A7 requires a relation/endpoint `CornerWedgeIsolationTransition` whose `fromSheet/toSheet` connects the two endpoint sets. Otherwise it fails `UncertifiedCrossSheetBinding` at `cross-sheet`. No production amendment is authorized.
3. **Recovery witness.** Identity29 must use a valid production-derived A6 product with a non-vacuous selected cross-sheet edge, prove baseline A7 acceptance, then disconnect all relevant transition sheet endpoints and prove the exact C1 rejection. A fabricated invalid quotient product or a test that never reaches the tamper is forbidden.
4. **Routing.** Exact next `M6-CP1-CB12-CLOSE-R2`, test-authority recovery only. Compile-green -> immutable `M6-CP1-TB12-CLOSE-R1-EXEC`, focused30 + selector449 = 479 -> mandatory `M6-CP1-TB12-CLOSE-R1-REV`. Only that Review may promote and release `M6-CP1-CLOSE-REV`.
5. **Stop rule.** Any required production semantic change, C1 weakening, selected-forest algorithm change, selector/routing change, or inability to construct a valid production-derived witness stops for Review.

Accounting remains **60 / 16 / 44**, debt 1.

## RA-27a — the reachable cross-sheet path is wedge-level; RA-27 §2–§3 withdrawn (normative, 2026-10-05, `M6-CP1-TB12-CLOSE-REV` review-agent addendum)

Rationale: `Architecture_M6_CP1_TB12_Close_Review_Record.md`, addendum §P3–§P7.

1. **CAND-01 cause (replaces RA-27 §1's reason).** `split_isolation_fixture()` has **no** relation with disjoint endpoint wedge-sheet sets. Its diagonal seam crosses cell interiors, so every sheet crossing happens inside a bridge occurrence (`|cornerWedgeSheets| = 2`). A disjoint-sheet relation can arise only from a front edge collinear with an isolation seam, and A6 already certifies that case exactly (`RemeshPipeline.cpp:5292-5310`). CAND-01 stays non-stable (+0).
2. **Exact wedge rule (production; completes RA-22a §3 / C1).** A7 certifies a class member with `|cornerWedgeSheets| > 1` only if this graph is connected:
   - vertices: the member's `cornerWedgeSheets`;
   - edges: `{fromSheet, toSheet}` from its own `cornerWedgeIsolation`, keeping only transitions with `region == topologyRegion` and both sheets in the set.

   Otherwise it fails `UncertifiedCrossSheetBinding` at site `cross-sheet:wedge`. This replaces the non-empty proxy (`:6884-6895`). The edge rule (site `cross-sheet`) is unchanged.
3. **C4 name.** `surface_quotient_product_error_name(ClosedComplexStripContinuationMismatch)` returns `"QuotientClosedComplexStripContinuationMismatch"`.
4. **Identity 29** (name and focused-30 position unchanged). On `split_isolation_fixture()`:
   1. assert a class member with ≥ 2 wedge sheets exists;
   2. baseline A7 accepts;
   3. rewrite only that member's `cornerWedgeIsolation` sheets to a pair that does not connect its set (keep the transitions non-empty);
   4. republish through `publish_records_for_validation`, then **re-produce A6 from the tampered A5** with `SurfaceQuotientProducer::produce` and assert success;
   5. assert that A7 on (tampered A5, re-produced A6) returns `UncertifiedCrossSheetBinding` at `cross-sheet:wedge`.
5. **Consistent-chain rule.** Every stage-level negative feeds downstream stages products re-produced from the tampered upstream records. A stale downstream product is forbidden.
6. **Deferred.** The edge rule's executed falsifier waits for the first produced seam-collinear fixture (owner `M6-DEFN-R5` → `M6-CP3`). Hand-built relation records are forbidden.
7. **Observations.**
   - `M6-CP1-TB12-REV-OBS-01`: A6 → A5 certificate binding is missing; owner `M6-CP2` via `M6-DEFN-R5`.
   - `M6-CP1-TB12-REV-OBS-02`: the edge rule ignores relation kind while sheet IDs are global labels; owner `M6-DEFN-R5`.
8. **Stop rules.** Stop for Review if:
   - any previously accepted row fails;
   - A6 rejects the item 4 tamper;
   - item 2 needs any change beyond its text;
   - any selector449 / routing449 / focused-list byte changes.

Gate: focused-30 + selector449 = **479** → `M6-CP1-TB12-CLOSE-R1-EXEC` → `M6-CP1-TB12-CLOSE-R1-REV` → `M6-CP1-CLOSE-REV`. Accounting **60 / 16 / 44**, debt 1.

## RA-27b — runtime-proof scope, defensive-branch owners, CP1 close-plan amendments (normative, 2026-10-05, `M6-CP1-TB12-CLOSE-R1-REV` review-agent addendum)

Rationale: `Architecture_M6_CP1_TB12_Close_R1_Review_Record.md`, addendum §Q2–§Q6.

1. **Runtime-proof scope.** Identity 29 runtime-proves one dimension of the RA-27a wedge rule: transitions entirely outside the sheet set are rejected while the list stays non-empty. These conjuncts are **static-only**: the region filter, connectivity versus "touches the set", and multi-sheet partial connectivity. Records must not claim them as runtime-proved.
   - Owner of the missing tampers: the first `M6-CP2` Code + Build, as new appended identities. Identity 29 stays unchanged. Tracked as `M6-CP1-TB12-R1-REV-OBS-01`.
2. **Defensive branches.**
   - C4 `ClosedComplexStripContinuationMismatch` is reachable only through a weld-pinched vertex. Its executed falsifier is owned by `M6-CP2-DEFN`: a weld-constructed malformed-authority witness, with the verifier's manifoldness recompute.
   - C2's empty-front A5 branch is accepted as defensive and unreachable (A4 rejects empty fronts first).

   Neither blocks CP1, because both fail closed.
3. **CP1 close-plan amendments** (binding on `M6-CP1-CLOSE-REV`):
   1. Check the six exit items against the frozen text verbatim ("CP1 exit scope — restated", this document §CP1 exit scope), on exact HEAD source and the promoted 479/479 evidence.
   2. Classify every defensive or static-only branch introduced in CP1 (C2 empty-front, C4, RA-27a static conjuncts, RA-27a §6 edge rule) as accepted-defensive with a named later owner, or as CP1-blocking.
   3. `G4-B002` debt stays **open**. CP1 closure is mechanism-only, and debt stays 1.
   4. If CP1 closes, the exact successor is **`M6-CP2-DEFN`**. If it does not, route to the smallest Definition or Code + Build owner.
4. **`M6-CP2-DEFN` scope** (bounded, runtime-free; CP2 entry):
   - the `SurfaceProductVerifier` contract (frozen §6, §10): its typed failure matrix for the §6.3 malformed-authority classes, its §6.2 recompute set, and its identity/gate plan;
   - **OBS-01** (`M6-CP1-TB12-REV-OBS-01`): a certificate chain binding A6 → A5 and A7 → A6/A5, verified by payload equality;
   - **RA-26 §5(iii)**: retire or replace the vacuous `project_vertices` sheet check;
   - item 2's C4 witness and item 1's appended tampers.

   **`M6-DEFN-R5` stays the CP3-entry gate** and follows CP2. It keeps: the gauge obligations, the A5 barrier-set census, RA-26 §5(i)(ii)(iv), RA-27a §6 and `M6-CP1-TB12-REV-OBS-02`.
5. **Observation.** `M6-CP1-TB12-R1-REV-OBS-02`: the adapter drops A7's cross-sheet site (`RemeshPipeline.cpp:7462`); owner M8-CP2.

Accounting **60 / 16 / 44**, debt 1. Exact next: `M6-CP1-CLOSE-REV`.

## RA-28 — `M6-CP2-DEFN` independent verifier candidate freeze (2026-10-05; pending mandatory Review)

`M6_Consolidated_Record.md` §51 preserves the reviewed CP2 Definition contract (historical source filenames resolve through its folded-document index):

1. malformed verifier witnesses use copy-by-value A5/A6/A7 **verification record views**; no unchecked product factory exists;
2. findings are typed and ordered by semantic stage/locus, never discovery/vector/output order;
3. the recompute surface is exactly §6.2; every §6.3 forbidden class rejects or is API-shape defensive, with no repair/search/substitution/mutation;
4. A6 certificates/consumptions bind byte-semantically to their exact A5-owned relation/evidence and A7 binds to exact A6 class/topology plus cited A5 evidence; equivalent unreferenced authority is not a substitute;
5. C4 remains accepted-defensive because no permitted production-derived A5 witness reaches it without forging relation authority; the executed pinched-topology falsifier is the verifier's independent manifoldness recompute over a tampered A6 record view;
6. the three RA-27a static-only tampers are wrong-region, one-endpoint-touches-without-connectivity, and three-sheet partial connectivity, with identity29 unchanged;
7. production A8 runs immediately after A7 and before adapter projection; any accepted focused30/selector449 rejection is a mandatory Review stop;
8. RA-26 §5(iii) remains an optimizer reject-only reference-safety obligation and switches to class-wide `vertexChartAuthority` membership; it is not semantic product authority;
9. CP2 gate architecture is focused30 + new CP2-focused12 + selector449 = **491** fresh exact-filter processes. Existing focused30, selector449 and routing449 bytes stay unchanged;
10. successor chain is `M6-CP2-DEFN-REV` → `M6-CP2-CB1-VERIFIER` → TB1 → Review. `M6-DEFN-R5` remains after CP2; `G4-B002` debt remains 1; M7 semantics remain forbidden.

Until `M6-CP2-DEFN-REV` accepts this candidate, RA-28 authorizes **no implementation**.

## RA-28a — CP2 verifier Definition accepted with binding amendments (normative, 2026-10-05, `M6-CP2-DEFN-REV`)

Rationale: `M6_Consolidated_Record.md` §51 (historical `Architecture_M6_CP2_DEFN_Review_Record.md` is indexed there). RA-28 is accepted as amended here; where they conflict, RA-28a governs. No new identities are added: each item is carried by the named identity from the CP2 focused-12 list, and the gate stays **491**.

1. **Exact-once, forest, spanning and cycle checks** (identities 3 and 6). Over published record views only, with no search:
   1. the A5-owned relation IDs, the A6 certificate relation IDs and the A6 consumption relation IDs are equal sets, each ID occurring **exactly once** in each;
   2. the `selectedForest` relation IDs equal the IDs of the `Joining` consumptions, and each forest edge's endpoints equal its certificate's `first`/`second`;
   3. for every class, its published forest edges have both endpoints in the class, number exactly `|members| − 1`, and connect all members (traversal over the *published* edges is a check, not producer union-find);
   4. every `CycleClosing` consumption has both endpoints in one class, and its certificate `relationTransport` equals the exact composition, along the class's published selected path, of the named certificates' transports with their orientations (RA-13 strict rule).

   Failures: `QuotientMembershipMismatch` for 1–3, `NamedTransportMismatch` for 4.
2. **Field-correspondence table for A6 → A5 binding** (identity 6). For certificate `c` citing A5 relation `r`:

   | A6 field | must equal |
   |---|---|
   | `c.relation` | `r.id` |
   | `c.first` / `c.second` | `r.id.first` / `r.id.second` |
   | `c.relationTransport` | `r.evidence.canonicalTransport.value()` (`MissingPublishedAuthority` if absent) |
   | `c.evidence` | `r.evidence.equivalence` |
   | `c.selectedRelationStep` | `r.evidence.canonicalSelectedStep` |

   - `r.firstFrontEdge` / `r.secondFrontEdge` are representation-only and are not compared.
   - **A7 → A6/A5:**
     - each A7 vertex's class equals one published A6 class (ID and member set);
     - its support equals the common A5 member support (RA-18);
     - A7 topology equals the A6 classed cells by IDs;
     - every A7 selected step's applied value equals the cited A5 relation's `canonicalRelationValue` (RA-16 §3).
   - No A6/A7 producer routine is called to derive an expected value.
   - **Stop for Review** if any A6/A7 field differs from its table entry on any accepted row, i.e. if a producer transforms rather than copies. Do not encode a transformation.
3. **A5 wedge and support evidence against A0** (identity 2). For every occurrence:
   - every `cornerWedgeBinding` face is incident to the occurrence's support;
   - `binding.sheet` equals A0's sheet for `binding.face`;
   - `cornerWedgeSheets` equals the sorted, unique set of binding sheets;
   - every `cornerWedgeIsolation` transition has `region == topologyRegion`, its `seam` is an A0 isolation seam of that region incident to the support, and its `{fromSheet, toSheet}` are A0's sheets of the seam's two faces;
   - the A5 occurrence support has exact A0 incidence through the shared source-support kernel (frozen §6.2).

   Failures: `SourceIncidenceMismatch` / `SourceSupportIncidenceMismatch`.
4. **Dependency gating** (identities 1 and 5). Checks are partitioned in the order A0 → A5 identity/indexing → A5 incidence → A6 identity/indexing → A6 ledger/forest/topology → A7 → cross-stage. A check runs only if every prerequisite partition produced no findings; skipped checks emit nothing. The finding set is therefore a function of the input records alone, and identity 1 asserts its invariance under record-order permutation.
5. **Code set** (identity 5). Remove `ForbiddenGeometricWeld` and `UpstreamFailureSubstitution` from the runtime `VerificationFailureCode`:
   - welds are detected combinatorially (item 1.3 → `QuotientMembershipMismatch`, or `NonManifoldTopology`);
   - upstream-failure substitution is excluded by API shape and pinned by a compile-time trait (no verifier overload accepts a producer error variant).

   No runtime code may be emitted without a frozen predicate.
6. **Order as a type invariant** (identity 11).
   - `SurfaceProductVerifier` returns `VerifiedSurfaceProducts`, which only the verifier can construct and only when there are no findings.
   - The adapter's projection entry accepts only `const VerifiedSurfaceProducts&`.
   - A8 runs in a stage function (`produce_verified_surface_products`, name frozen by CB1) called by the adapter, not inlined in the adapter body.
   - Identity 11 asserts:
     - a compile-time trait that projection is not invocable with raw A5/A6/A7 products;
     - behaviorally, that a pipeline result carries a verified report;
     - that a record-view failure maps to the frozen adapter failure string (item 9).
7. **Optimizer reference-safety gating** (identity 12). The class-wide membership check, "projected face ∈ faces of `vertexChartAuthority[v].sourceCharts`", applies **only when `vertexChartAuthority[v].retained`** (authoritative path, `RemeshPipeline.cpp:12868-12872`). Otherwise current behavior is unchanged. It only rejects.
   - **Precondition to prove in the CB1 report:** the representative `sourcePoint.face` belongs to the class's `sourceCharts` faces. Cite the `CornerPlacementProvenance.selectedFace` ∈ wedge-bindings derivation; if unprovable, stop for Review.
   - Identity 12 covers: accept for an in-class face; reject for an out-of-class face; non-authoritative path unchanged.
   - **Stop for Review** if any selector449 optimizer row changes outcome.
8. **Tamper precision** (identities 8–10). Each tamper republishes A5, re-produces A6 (asserting success), then runs A7, and asserts `UncertifiedCrossSheetBinding` at `cross-sheet:wedge`.
   - **Wrong-region:** a valid `TopologyRegionId` ≠ `topologyRegion`, with both sheets kept in the set.
   - **Touches:** **every** bridge transition becomes (in-set, out-of-set).
   - **Three-sheet:** insert a phantom sheet ID, not otherwise used, **in sorted position** in `cornerWedgeSheets`; the transitions still connect only the original two.
9. **A0 and the failure string** (identities 2 and 11).
   - A0 is the tuple (source vertices, source faces, `SourceTopologyRegions` (regions, components, sheets, isolation seams), source hard-feature edges).
   - The adapter maps a verifier rejection to `VerificationFailed:<code>:<site>` from the first finding in semantic order, preserving the site.

Successor: `M6-CP2-CB1-VERIFIER` (Code + Build; compile/package only) → `M6-CP2-TB1-VERIFIER-EXEC` (**491**) → `M6-CP2-TB1-VERIFIER-REV`. `M6-DEFN-R5` follows CP2. `G4-B002` stays open (debt 1). Accounting **60 / 16 / 44**.

## RA-28b — RA-28a §7 withdrawn; optimizer check retained as non-authoritative; identity 12 re-specified (normative, 2026-10-05, `M6-CP2-CB1-VERIFIER-REV`)

Rationale: `M6_Consolidated_Record.md` §52 (historical `Architecture_M6_CP2_CB1_Stop_Review_Record.md` is indexed there).

1. **Withdrawal.** RA-28a §7 is withdrawn: its face-membership predicate and its `selectedFace ∈ cornerWedgeBindings` precondition. A5/A7 do not publish that precondition, and RA-22b §2 keeps the representative face representation-only. **No A5 invariant is added.**
2. **RA-26 §5(iii) resolution.** The existing optimizer component/sheet self-check stays **unchanged**, classified as non-authoritative. On the authoritative path, `project_vertices` confines every projected provenance to its seed's own face (vertex/edge/face-interior supports) or scope (degenerate fallback), at `SurfaceMeshOptimizer.cpp:706-750` and `:786-797`. So an optimizer-side check can only re-test a static lineage property, and that property is certified elsewhere:
   - **before movement:** the frozen completion guard (`PureQuadCompletion.cpp:895-941`) and the CP2 verifier (RA-28a §3);
   - **after movement:** final validation (`SourceAuthoritativeMeshValidator.cpp:1232-1262`).

   **No `SurfaceMeshOptimizer` source change in CP2.**
3. **Identity 12.** `M6CP2.AuthoritativeOptimizerProjectionStaysOnRepresentativeScope` replaces `M6CP2.OptimizerProjectionUsesClassWideChartAuthority` at position 12.
   - **Setup:** authoritative-path constraints from a produced fixture. Non-vacuity requires at least one vertex-support and one edge-support seed. Those are the only kinds whose representative face can lie outside the wedge bindings. Face-interior seeds are asserted if present but not required.
   - **Action:** call `surface_optimizer_detail::project_vertices` with perturbed candidates.
   - **Assertions:**
     1. the projected `face` equals the seed `face` for every valid seed;
     2. `componentsOk` and `sheetsOk` are true;
     3. `sheet_for_row(seed.face)` ∈ the sheets of the `vertexChartAuthority[v].sourceCharts` faces for every retained `v`.
   - The identity count, order and gate (**491**) are unchanged.
4. **Later-owner note.** Representative faces can lie outside the wedge bindings for edge and vertex supports. `M6-DEFN-R5`'s RA-26 §5(i)/(ii) class-wide reference must not assume `selectedFace` ∈ the class's chart faces.
5. **Void.** The exploratory CB1 WIP's optimizer membership change is void. All other RA-28a sections are unchanged.

Successor: `M6-CP2-CB1-VERIFIER-R1` (new turn; Code + Build) → `M6-CP2-TB1-VERIFIER-EXEC` (491) → `M6-CP2-TB1-VERIFIER-REV`. Accounting **60 / 16 / 44**, debt 1.


## RA-29 — CP2 TB1 verifier recovery after independent Review (normative, 2026-10-05, `M6-CP2-TB1-VERIFIER-REV`)

`M6-CP2-TB1-VERIFIER-REV` rejects the `265c8fbb...` candidate for bounded recovery. The three runtime REDs are non-stable witness defects, but Review also finds four static RA-28a implementation gaps. Recovery is limited to the following:

1. identity 2 must create a real canonical source-face mismatch and must verify published occurrence support against A0 with the shared `SurfacePointSourceSupportResolver`;
2. identity 6 must use a non-vacuous always-bound A6→A5 payload tamper and the verifier must independently require every published selected path to equal the unique traversal of the published selected forest before transport composition;
3. identity 7 must construct a real weld-pinched record view from disjoint produced quotient-cell components and reach `NonManifoldTopology / a6:vertex-link`;
4. identity 8's wrong-region replacement must be an actual A0 region distinct from the occurrence region;
5. identity 11/full pipeline must carry the exact verified A8 report in the successful `AuthoritativePhaseFrontMeshResult`; projection remains gated by `VerifiedSurfaceProducts`;
6. no optimizer source change, no A5 semantic expansion, no selector/focused order change, and no reduction of the 491-process gate.

The three EXEC candidates are **FALSE REJECTION / NON-STABLE** and remain +0 to stable accounting. REV-OBS-01/03/04 are production/API verifier contract omissions; REV-OBS-02 is a latent test-witness authority defect. Candidate `11365308211 / 265c8fbb...` is not promoted.

Successor chain is frozen: `M6-CP2-CB1-VERIFIER-R2` → `M6-CP2-TB1-VERIFIER-R1-EXEC` (**491**) → `M6-CP2-TB1-VERIFIER-R1-REV`. `M6-DEFN-R5` remains after CP2. Stable accounting remains **60 / 16 / 44**, debt 1.

## RA-29a — verifier recovery amendments (normative, 2026-10-05, `M6-CP2-TB1-VERIFIER-REV` review-agent addendum; amends RA-29 and RA-28a §1.3/§8)

Rationale: `Architecture_M6_CP2_TB1_Verifier_Review_Record.md`, addendum §S1–§S3. RA-29 items 1–3, 5 and 6 stand. RA-29 item 4 is replaced by item 6 below. The following are added to `M6-CP2-CB1-VERIFIER-R2`. The identities, their order and the gate (**491**) are unchanged.

1. **Every relation is intra-class** (identity 3; amends RA-28a §1.3). Every A5-owned relation, whatever its disposition, must have both endpoints in one published class (`QuotientMembershipMismatch`, `a6:relation-class`). Also |`selectedForest`| = Σ over classes of (|members| − 1).
   - Identity 3 adds this witness: split a produced class at one forest edge into two classes, each still spanned by its own edges, and require `a6:relation-class`.
2. **Linear-time topology** (static; no identity). Edge → owning-cells and vertex → incident-edge maps are built in one pass. No per-edge cell scan, no per-vertex edge scan. The verifier's A6 topology partition must be O(n log n) in cells + edges. The R2 report states the complexity, with `file:line` evidence.
3. **Exact A7 step citation** (identity 6). Each A7 HardRail/Periodic selected step binds to the relation ID at the same position of the HardRail/Periodic subsequence of the class's A6 `QuotientSelectedPathCertificate.orderedRelations`. Its applied value must equal that exact relation's `canonicalRelationValue`, inverted for `Reverse`.
   - If R2 cannot establish that positional correspondence from the published records, it must instead require that every A5 relation sharing the step's rail or periodic ID carries an identical `canonicalRelationValue`, and record why the positional binding is unavailable.
   - First-match lookup is forbidden.
4. **A0 component adjacency** (identity 2; frozen §6.2). Recompute the connected components of A0 face edge-adjacency, and require `component_for_row` to induce exactly that partition (labels up to renaming). Failure: `SourceIncidenceMismatch`, site `a0:component-adjacency`.
5. **The token binds contents** (identity 11). `VerifiedSurfaceProducts` either **owns** the verified A5/A6/A7 products (moved in, or `shared_ptr<const>`) or is non-copyable and confined to the stage function's scope. Post-projection adapter counters read through the token, never through raw product pointers. Identity 11 adds a compile-time trait that pins the chosen property.
6. **Wrong-region witness** (identity 8; replaces RA-29 item 4; amends RA-28a §8). The replacement `TopologyRegionId` need only differ from `occurrence.topologyRegion`; A0 validity is **not** required, because the asserted site `cross-sheet:wedge` pins the region filter and nothing upstream checks region validity. Identity 8 adds an explicit inequality assertion. **No new fixture is required.**
7. **Precision.**
   - **Shared kernel coverage** (RA-29 item 1 / REV-OBS-03): the shared-kernel point ↔ support equality also applies to A7's class binding (`a7:class-binding`).
   - **Identity 7** changes **only** `classedCells` corner class IDs. It must assert pre-tamper disjointness and that the A6 ledger partition produces no findings; a class merge would trip gating before `a6:vertex-link`.
   - **Identity 6's path-structure tamper** uses a produced class with a ≥2-step selected path, with non-commuting transports where available.

Successor: `M6-CP2-CB1-VERIFIER-R2` → `M6-CP2-TB1-VERIFIER-R1-EXEC` (**491**) → `M6-CP2-TB1-VERIFIER-R1-REV`. Accounting **60 / 16 / 44**, debt 1.

## RA-29b — `M6-CP2-TB1-VERIFIER-R1-REV` bounded recovery amendment (normative, 2026-10-06)

R1 runtime (`37393554373 / 112044082007`) rejects the R2 candidate at **462/491**. Independent Review finds two bounded verifier-authority errors; candidate `11382000465 / 9c8478ae...` is not promoted.

1. **A7 legacy projection is not an A6 path identity.** A6 publishes root/target and exact relation paths; A7 intentionally projects only HardRail/Periodic legacy certificates and deduplicates equal values. Therefore multiple A6 root→target paths may lawfully map to one A7 legacy path. RA-29a §3's positional rule applies only when one published A6 path is identifiable from A7 data. When multiple A6 paths have the same legacy projection, R3 must use RA-29a's fallback: for each A7 step, every A5 relation in the class sharing that step's rail/periodic owner ID must publish the same `canonicalRelationValue`, and the A7 applied value must equal that common value after orientation. Ambiguity itself is **not** `MissingPublishedAuthority`. Zero matching A6 legacy projections still is. First-match selection remains forbidden.
2. **RA-29a §4 exact component partition is withdrawn as a review-agent error.** `SourceComponentId` is ingress authority and is not independently derivable from raw triangle connectivity in the current verifier API. `build_source_topology_regions` accepts published component labels and can publish multiple disconnected topology regions with the same component label. Accepted selector449 ordinal144 intentionally exercises this (`sourceFaceComponents` all zero on a disconnected square pair) and must remain green. Remove `a0:component-adjacency` raw-connectivity equality and the identity-2 component-merge sub-witness. Keep all other A0/A5 elementary incidence and shared-support checks. A future stronger component-label check requires independently published ingress-label evidence rather than inference from mesh connectivity.
3. **Focused12 identity 6** keeps its name/order and its >=2-step path tamper, but its baseline must be green. The identity must additionally prove a produced ambiguity witness (two or more A6 selected paths collapsing to an equal A7 legacy projection) so the fallback is non-vacuous. No unchecked authority may be forged.
4. **Runtime evidence upload:** the next TB caller must derive upload paths from the same `TURN_ID` used by the harness. R1's stale predecessor path is orchestration-only and does not authorize a duplicate R1 runtime.
5. No optimizer change, no A5/A6/A7 producer semantic change, no focused30/focused12/selector/routing order change, and no gate reduction.

Successor chain: `M6-CP2-CB1-VERIFIER-R3` → `M6-CP2-TB1-VERIFIER-R2-EXEC` (**491**) → mandatory `M6-CP2-TB1-VERIFIER-R2-REV`. Stable accounting remains **60 / 16 / 44**, debt 1.

## RA-29c — exact three-hop A7 relation-step binding (normative, 2026-10-06, `M6-CP2-TB1-VERIFIER-R1-REV` review-agent addendum; replaces RA-29b §1 and §3 and RA-29a §3)

Rationale: `Architecture_M6_CP2_TB1_Verifier_R1_Review_Record.md`, addendum §T3–§T5. RA-29b §2, §4 and §5 stand.

1. **Withdrawn.**
   - RA-29a §3's positional reverse lookup;
   - RA-29b §1's same-owner-ID fallback. It falsely rejects whenever relations sharing a rail or periodic ID carry inverse `canonicalRelationValue`s, which A5 produces whenever storage order is not canonical (`RemeshPipeline.cpp:4917-4921`);
   - RA-29b §3's produced ambiguity witness.

   R2's `a7:a5-relation-step` reverse lookup, including its per-A7-path scan of all A6 paths, is removed.
2. **Hop 1, A5 internal** (identity 6). For every A5 relation with `canonicalSelectedStep`: `canonicalRelationValue` is present, `step.appliedTransport == canonicalRelationValue`, and `step.direction == Forward` (A5 constructs exactly this, `:4936-4941`). Failure: `CertificatePayloadMismatch`, site `a5:selected-step-value`. This check runs in the A5 partition.
3. **Hop 2, A6 legacy projection** (identity 6). For every A6 `QuotientSelectedPathCertificate`, using only its own `orderedRelations` / `traversalOrientations` and the named certificates' `selectedRelationStep`:
   - `legacyProjection.has_value()` ⇔ the oriented step subsequence is non-empty;
   - `orderedSteps` equals that subsequence. A `Reverse` traversal inverts a step: invert `appliedTransport`, swap from/to chart and chart component, flip `direction`;
   - `composedTransport` is the composition of the steps' `appliedTransport`;
   - start/end chart and chart component come from the first/last step.

   Failure: `CertificatePayloadMismatch`, site `a6:legacy-projection`. A6's own publication construction is matched (`:5500-5548`, `:5935-5960`) using only §6.2 named-certificate inversion and composition.
4. **Hop 3, A7 projection** (identity 6). For every class: `vertex.selectedRelationPaths` equals the sorted, deduplicated list of the class's present `legacyProjection`s (A7 construction, `:6962-6970`). Failure: `CertificatePayloadMismatch`, site `a7:selected-paths`. Paths are grouped by class once, so the binding is O(P log P).
5. **Identity 6 witnesses** (same fixture as the ≥2-step path tamper). Keep the clean baseline, the `relationTransport` tamper and the path-structure tamper. Add (a) an A7 step `appliedTransport` tamper → `a7:selected-paths`, (b) an A6 `legacyProjection` step tamper → `a6:legacy-projection`, and (c) a `canonicalRelationValue`-only A5 tamper → `a5:selected-step-value`. Each asserts that its tamper changed the record before the verifier is called. **No ambiguity witness.**
6. **Identity 11.** Replace `static_assert(VerifiedSurfaceProducts::owns_products)`, which is self-declared and vacuous, with a behavioral check: the token's product addresses differ from the originals, and the token's record views equal the originals'. Remove the `owns_products` constant.
7. **Stop rules.**
   - Hop 1 or Hop 2 rejects any accepted focused-30 or selector449 row → stop for Review. Do not weaken the check.
   - Hop 2 needs any transformation other than §6.2 inversion and composition → stop for Review.

Successor: `M6-CP2-CB1-VERIFIER-R3` → `M6-CP2-TB1-VERIFIER-R2-EXEC` (**491**; upload paths derived from the harness `TURN_ID`) → mandatory `M6-CP2-TB1-VERIFIER-R2-REV`. Accounting **60 / 16 / 44**, debt 1.

## RA-29d — CP2 closure revoked; verifier binding and negative-coverage completion (normative, 2026-10-06, `M6-CP2-TB1-VERIFIER-R2-REV` review-agent addendum)

Rationale: `Architecture_M6_CP2_TB1_Verifier_R2_Review_Record.md`, addendum §U1–§U4.

1. **Status.** `11385836615 / c64baacd` remains **promoted** as reviewed runtime authority (491/491). "M6-CP2 CLOSED" is **revoked**: CP2 stays ACTIVE until `M6-CP2-CLOSE-REV`.
2. **A7 vertex binding** (implements RA-28a §2). For every A7 vertex `v` of class `C` with support certificate `s`, require:
   - `v.representative` ∈ `C.members`;
   - `v.sourcePoint` == the representative occurrence's published `point` (exactly);
   - `v.position` == `v.sourcePoint.position`;
   - `v.support == s.publishedSupport`.

   Failure: `SourceSupportIncidenceMismatch`, site `a7:vertex-binding`. A7 copies these fields verbatim (`RemeshPipeline.cpp:6985-6993`), so the check is gate-neutral.
3. **Dead codes.**
   - Remove `UncertifiedAuthoritySubstitution`.
   - `BoundaryOrEulerMismatch` is emitted for the recomputed components, boundary-loop count and Euler characteristic at `a6:components`, `a6:boundary-loops` and `a6:euler`, split out of `certificate:a7`.
4. **Negative coverage** (identities 2–5; names, order and gate **491** unchanged). Execute exact code+site witnesses for:
   - the RA-28a §1 ledger and forest predicates;
   - A5 ownership and directed sides;
   - A0 hard-feature edges;
   - A7 vertex binding, cover and topology copy;
   - the A5/A6 certificates;
   - `BoundaryOrEulerMismatch`.

   Identity 5 becomes a table-driven map with one row per frozen §6.3 class. Each row is either an executed record-view witness or an API-shape compile-time trait. Details: `Architecture_M6_CP2_CB2_Coverage_Code_Build_Plan.md` G3.
5. **Coverage table.** The CB report maps every §6.2 recompute category and every §6.3 class to its predicate (`file:line`) and its executed witness or API-shape classification. A missing row is a stop for Review.
6. **CP2 closure** happens only at `M6-CP2-CLOSE-REV`. It adjudicates frozen §10 M6-CP2 against that table and a fresh 491 gate, and writes `M6_CP2_Closure_Record.md`.
7. **Observations.**
   - `reverse_selected_relation_step` is a shared exact-algebra helper; acceptable under §6.2, recorded.
   - The by-value token copies the products on every run (owner M8-CP2).

Successor: `M6-CP2-CB2-COVERAGE` → `M6-CP2-TB2-COVERAGE-EXEC` (**491**) → `M6-CP2-CLOSE-REV` → `M6-DEFN-R5`. Accounting **60 / 16 / 44**, debt 1.


## RA-30 — CP3 entry authority, class-wide references and direct-exit gate (normative, 2026-10-06, pending `M6-DEFN-R5-REV`)

Rationale: `Architecture_M6_DEFN_R5_CP3_Entry_Definition_Record.md`. This amendment is a Definition candidate until mandatory independent `M6-DEFN-R5-REV` accepts it; it authorizes no implementation before that Review.

1. **Exact-A3 Periodic gauge rule.** Keep semantic periodic relation value in relation-endpoint gauge. Recompute published endpoint state from local placement + interval + relation rotation + face-gauge authority. Derive placement transport by exact conjugation `Γ_to^-1 ∘ g ∘ Γ_from`, require the two endpoint-derived transports equal, and validate canonical occurrence placements. Independently require `g` to map relation-gauge endpoint coordinate+branch states. Never compare face-gauged front-edge branches across unequal face gauges.
2. **HardRail branch certificate.** Coordinate-rigid HardRail `canonicalTransport` remains placement authority. Publish exact endpoint face-gauge evidence; strip it from placement branch labels and require the resulting regional branch difference to equal the coordinate-rigid transport rotation on both endpoint pairs. Different topology regions never compare raw branch labels.
3. **OrdinaryFront isolation seam.** OrdinaryFront quotient transport is always identity. Exact quotient identity requires lattice coordinate + scale equality. Across a collinear isolation seam, source-chart/face-gauge labels may differ only with the exact reciprocal checked isolation transition. Its seam quarter-turn is chart evidence, never extra quotient transport.
4. **A5 chart barriers.** A5 consumes the immutable typed source hard-feature edge authority directly. Barrier membership is not reconstructed from relation kind or HardRail routes. A PeriodicCut carrier is a barrier iff source hard-feature authority marks it; every HardRail carrier must be marked or A5 fails closed.
5. **Class-wide optimizer/final-validation reference.** Resolve one compatible chart from all four quad corners plus all four `vertexChartAuthority` sets. Use that quad-wide chart for optimizer normal/field reference, finite-difference gradient, line search and final edge-field metrics; freeze the resolved face set through one local evaluation. No first-corner/first-endpoint/representative-face narrowing and no assumption that `selectedFace` belongs to every class chart. Missing compatible authority is typed failure. Cost is linear in the four corners' published chart memberships with a fixed number of projections per evaluation.
6. **Permutation falsifier.** A direct-produced torus must be invariant under a consistent source-face-row permutation, output vertex/face-row permutation and deterministic nonzero quad-corner rotation that actually changes at least one class representative and one corner-0. Discrete products/decisions/digests are exact after semantic remap; continuous positions/metrics use `1e-12 * max(1, source_bbox_diagonal)`.
7. **A7 selected-edge sheets dispatch by relation kind.** HardRail cross-region edges validate each endpoint in its own partition plus the RA-30 branch certificate and never compare global sheet IDs. OrdinaryFront within one topology region requires shared sheet or one exact connecting isolation transition. Periodic uses that same rule within one topology region; a produced cross-region Periodic case is a mandatory Review stop. Unsupported kinds fail closed. The seam-collinear positive must be real-tracer produced and must have disjoint endpoint sheet sets.
8. **CP3 direct-exit evidence.** New identities are exactly: `PeriodicExactA3UnequalFaceGaugeUsesRelationAndOccurrenceAuthority`, `HardRailCrossRegionBranchCertificateStripsEndpointFaceGauge`, `OrdinaryFrontIsolationSeamUsesCoordinateIdentityAndCertifiedSheetTransition`, `A5ChartBarriersConsumeTypedHardFeatureAuthorityAcrossRelationKinds`, `ProducedSeamCollinearOrdinaryFrontRequiresExactCrossSheetTransition`, `HardRailCrossRegionBindingDoesNotCompareGlobalSheetLabels`, `ClassWideOptimizerReferencesAreSourceOutputAndCornerPermutationInvariant`, `DirectProductionKeepsCoincidentUnrelatedClassesDistinct`, `DirectProductionConsumesEveryA5RelationExactlyOnce`, `DirectProductionPublishesExactSharedSupportAndA8BindsIt`, `DirectProductionSchedulerPermutationIsSemanticNoOp`, `DirectProducedTorusCandidateEligibilityAndHardFeatureTamper`, and `DirectProducedTorusBindsA5A6A7A8RepresentativeChain`, all under suite prefix `M6CP3`.
9. **G4-B001 strict 3/3.** The CP3 current-source strict direct-torus identities are `SurfaceCellsPhase10.ExactCommittedTorusDoesNotTreatIsolationSeamAsBoundedDiskBoundary`, `MilestoneGP26.TorusCompletesEndToEnd`, and `MilestoneGP27.ProductionSurfaceCellMatrixMatchesSupportedDisposition`. The parameterized P27 diagnostics-ownership row receives no strict-production credit because it does not require success. Historical artifact `9031804178` preserves only aggregate 0/3, not old exact names; do not fabricate historical mapping. No validator or sheet-authority weakening is allowed.
10. **Sequencing/gates.** CB1 owns only items 1-4 and 7 plus the first six identities; compile/package only. Its artifact-only entry gate is inherited `30 + 12 + 449 = 491` plus six = **497** fresh exact-filter processes, followed by mandatory Review. No CP3 direct-production acceptance TB may precede that Review. CB2 then owns items 5-6 plus the remaining seven identities. Final CP3 gate is 491 + 13 + G4-B001 3 = **507** processes. Existing focused30, focused12, selector449 and routing449 bytes remain frozen; do not fold or rewrite them in Definition.
11. **Selector449 stop rule.** If the class-wide optimizer/reference change alters any inherited selector449 optimizer/validator outcome, stop before direct-production TB. Do not edit the accepted expectation, remove the row, or substitute a replacement; return to independent Review with exact ordinals and source cause.
12. **Debt/accounting.** Stable accounting stays **60 / 16 / 44**, debt 1. `G4-B002` closes only on accepted CP3 direct-production evidence; mechanism evidence remains prerequisite only. M8-owned adapter/copy/hardening obligations and all M7 disposition semantics are outside RA-30.

Mandatory chain after acceptance: `M6-DEFN-R5-REV` → `M6-CP3-CB1-ENTRY` (compile/package only) → artifact-only 497-process entry TB → mandatory Review. The CB1 plan is held until Definition Review.

## RA-30a — CP3-entry Definition accepted with binding amendments (normative, 2026-10-06, `M6-DEFN-R5-REV`)

Rationale: `Architecture_M6_DEFN_R5_Review_Record.md` §2. RA-30 is accepted as amended; where they conflict, RA-30a governs. Gate counts are unchanged (497 entry, 507 final).

1. **D4 authority source** (amends RA-30 §4; CB1).
   - `SurfacePhaseFrontProduct` publishes the immutable typed source hard-feature edge set its tracer consumed (`SurfaceCellTracingOptions::hardFeatureEdges`, `SurfaceCellTracing.h:2089`), validated as source edges at A4 construction.
   - A5 builds its chart-barrier set **from that product field**. A5's `produce(V, F, phaseFront)` signature is **unchanged**.
   - The authoritative adapter fails closed if the pipeline's `hardFeatureRailEdges` differ from the A4-published set.
   - **Stop for Review** if any accepted focused-30 or selector449 test body would have to change.
2. **D2 non-trivial gauge witness** (CB1).
   - Identity `HardRailCrossRegionBranchCertificateStripsEndpointFaceGauge` must use a **produced** fixture built through `remesh_from_raw_cross_field` (SurfaceCells backend, fallback `Fail`, no source-grid recovery). The fixture has two topology regions separated by user hard edges, a **non-constant raw cross field**, and at least one cross-region HardRail relation.
   - **Non-vacuity, asserted first:** at least one endpoint pair has `F_a ≠ F_b`, and the difference is 90° or 270°, so that a wrong-direction stripping (`F ∘ B` instead of `F⁻¹ ∘ B`) is rejected.
   - The negative tampers may additionally run on the existing constant-field HardRail fixture.
   - If the produced fixture lacks the property at TB time, that is a test-authority RED for Review, not a production defect. Never hand-build records.
3. **D3 seam branch certification** (amends RA-30 §3; CB1).
   - **Non-seam OrdinaryFront:** keep the current full equality (`sourceChart`, `branchRotation`, coordinate, scale, and the `1e-10` phase check, kept reject-only) at `RemeshPipeline.cpp:5229-5236`.
   - **Across a certified collinear isolation seam:** require all of
     - coordinate and scale equality;
     - the exact reciprocal `CornerWedgeIsolationTransition` pair;
     - **face-gauge-stripped branch difference == the A5-validated `SurfaceIsolationSeamTransportCertificate` quarter-turn** (`forward()` or `reverse()` by direction; `SurfaceCellTracing.h:1341-1365`);
     - the phase check, kept reject-only.

     `sourceChart` may differ only in this case.
   - The quarter-turn is chart evidence, never quotient transport (RA-2).
   - Identity 3 adds a tamper on the stripped branch: rotate one endpoint branch by 90° while the seam evidence stays valid → reject.
4. **G4-B001 rows' build target** (amends RA-30 §9–§10; CB2).
   - CB2 adds `directional_surface_cell_historical_tests` (with `DIRECTIONAL_BUILD_HISTORICAL_TESTS=ON`) to its compile and package set. The TB executes only the two named filters from that target.
   - If the historical target fails to compile, or either filter is not discoverable, **stop for Review**. Do not edit historical tests to make them build, and do not substitute other rows without Review.
   - CB1 and the 497 entry gate are unaffected.
5. **D6 feasible equality** (amends RA-30 §6; CB2).
   - D5's implementation must accumulate optimizer energy, gradient and line-search sums in **canonical semantic order** (by quotient-class and cell identity, not row index). Exact discrete-decision invariance then holds by construction, and the `1e-12 · max(1, bbox)` positional tolerance is achievable.
   - If canonical ordering is not adopted, the equality must be relaxed: accept/reject and discrete validator outcomes stay exact; the continuous tolerance must be justified; iteration and line-search sequences are not required to be exact. **Stop for Review rather than choose silently.**
   - The output-row permutation seam is a test that calls `optimize_source_authoritative_surface_mesh` directly with permuted `(vertices, quads, provenance, vertexChartAuthority)` taken from a produced run. No production hook.
6. **Scheduler permutation defined** (CB2). `DirectProductionSchedulerPermutationIsSemanticNoOp` permutes:
   1. the A4 phase-front cell, edge and event container order, reconstructed through the validating A4 factory;
   2. the A5 owned-relation container order fed to A6.

   A5/A6/A7/A8 semantic products, certificates and decisions must be **exact** after semantic remapping.
7. **D1 witness** (CB1).
   - Candidate fixture: the produced nonzero-Z4 torus (carrier search at `SurfaceCellTransitionQuotientTests.cpp:1351-1363`).
   - **Non-vacuity:** a reciprocal exact-A3 pair whose `localFaceBranchRotation` differs by 90° or 270°, so a mutant using `Γ` instead of `Γ⁻¹` is rejected. A pair differing by 180° does not count.
   - A missing pair is a test-authority RED for Review.
8. **D2 site.** The branch-certificate failure keeps the external `InvalidHardRailTransport` with site suffix `:branch-certificate`.

Successor: `M6-CP3-CB1-ENTRY` (released; compile/package only) → `M6-CP3-TB1-ENTRY-EXEC` (**497**) → mandatory `M6-CP3-TB1-ENTRY-REV`. Accounting **60 / 16 / 44**, debt 1.

## RA-31 — CP3 entry recovery (normative, 2026-10-06, `M6-CP3-TB1-ENTRY-REV`; published by its review-agent addendum)

Rationale: `Architecture_M6_CP3_TB1_Entry_Review_Record.md`. Candidate `11411137781 / 912760f1` is rejected at 373/497. The partition is exact: CAND-01 110, CAND-02 9, CAND-07 1 (stable), and CAND-04 1, CAND-05 2, CAND-06 1 (non-stable). Accounting becomes **63 / 17 / 46**, debt 1.

Recovery `M6-CP3-CB1-ENTRY-R1` covers:
- **P1:** every successful A4 regional producer publishes the face gauge it already computes; no default, fallback or weakened merge check.
- **P2:** reciprocal isolation-side evidence applies only on the certified cross-sheet collinear OrdinaryFront seam path. Non-seam relations keep full equality.
- **T1:** focused-30 ordinal 12 relabels the explicit face gauges consistently.
- **T2:** the D1 produced witness.
- **T3:** the D2 produced witness.
- **T4:** the D4 oracle against typed barrier semantics.

No optimizer, validator, selector, routing or frozen-name change. TB **497**, then mandatory Review.

## RA-31a — HardRail branch certificate withdrawn pending definition; R1 scope amended (normative, 2026-10-06, `M6-CP3-TB1-ENTRY-REV` review-agent addendum; amends RA-30 §2, RA-30a §2 and §8, and RA-31 T2/T3)

Rationale: `Architecture_M6_CP3_TB1_Entry_Review_Record.md`, addendum §X2–§X3.

1. **Withdrawn.** RA-30 §2's certificate (`C = F⁻¹ ∘ B` with each endpoint's own region-relative F, requiring `C_b ∘ C_a⁻¹ = R_coord`) is **withdrawn as unproven**. The published F is region-relative: the planar frame axis (`SurfaceCellTracing.cpp:10723-10760`) or the curved region root (`:14933-14934`). TB7 §G2's derivation gives `C_b − C_a = R_true + τ − (F_b − F_a)`, with τ the cross-rail field matching. The certificate is therefore valid only if `F_b − F_a = τ`, which is not established.
2. **R1 production.**
   - Remove the `HardRailBranchCertificateMismatch` rejection from A5. Coordinate-rigid `canonicalTransport` stays the sole HardRail placement authority, as before CB1.
   - **Keep** publishing per-endpoint face-gauge evidence (`firstEndpointFaceGauge` / `secondEndpointFaceGauge`).
   - Remove the now-unemitted error code and its `:branch-certificate` name mapping (no dead codes).
3. **`M6-DEFN-R5-R1`** (bounded Definition; it follows the R1 Review) must:
   - derive the HardRail branch certificate in terms of the **cross-rail field matching τ(f_a→f_b) between the two selected faces**, with conventions and a path-independence argument at rail vertices (fail closed at field singularities);
   - name the producer that publishes τ (A4 holds the matchings; A5's inputs do not);
   - name a **discriminating produced witness** where `F_b − F_a ≠ τ`, so the withdrawn per-region rule would falsely reject and the τ rule accepts.
4. **Identity 2** (`HardRailCrossRegionBranchCertificateStripsEndpointFaceGauge`).
   - In TB1-R1 it is **pre-registered RED**. Its non-vacuity premise (a produced cross-region HardRail with an endpoint gauge difference of 90° or 270°) and A5 production must pass. Its certificate-rejection assertions are expected to fail.
   - The test must **print the exact A5 error code, site and relation** on any A5 rejection.
   - Do not rename or retire it. It is completed under `M6-DEFN-R5-R1`.
5. **Identity 6** (`HardRailCrossRegionBindingDoesNotCompareGlobalSheetLabels`) must pass on the same produced fixture once the certificate rejection is removed. Any remaining A5 rejection, printed with its code, is a **stop for Review**: for example the RA-30a §1 carrier-membership rule, if the fixture's typed hard-feature set omits its rail.
6. **D1 stop rule (T2).** If no produced nonzero-Z4 torus pair has an endpoint gauge difference of 90° or 270°, **stop for Review**. Never hand-build records.
7. **TB1-R1 acceptance pattern.** 496 PASS, plus identity 2 RED with failures confined to the certificate-rejection assertions after its non-vacuity and A5-production assertions pass. Any other RED goes to Review as usual.

Successor: `M6-CP3-CB1-ENTRY-R1` → `M6-CP3-TB1-ENTRY-R1-EXEC` (**497**) → `M6-CP3-TB1-ENTRY-R1-REV` → `M6-DEFN-R5-R1` (D2) → the D2 CB. CB2 (D5/D6/D8) stays held until the CP3 entry is fully green. Accounting **63 / 17 / 46**, debt 1.

## RA-32 — CP3 entry R1 Review: failed seam-domain recovery and bounded Definition repair (normative, 2026-10-07, `M6-CP3-TB1-ENTRY-R1-REV`)

Rationale: `Architecture_M6_CP3_TB1_Entry_R1_Review_Record.md`. R1 candidate `11488700954 / 68000a95...` is mechanically valid at **482/497** but rejected/unpromoted. Stable accounting remains **63 / 17 / 46**, debt 1.

1. **P2 remains open.** The ten R1 A6/D7 REDs are continuation of the already-counted predecessor `RP-01 / AUTHORITY_DOMAIN_CONFLATION` event. The special OrdinaryFront seam path must be selected by relation/certificate-owned isolation-seam evidence; differing global sheet labels are not authority. Non-seam full representation equality and all certified-seam exact checks remain mandatory.
2. **D1 Definition repair.** Freeze an organic producer/search for a reciprocal exact-A3 90°/270° endpoint-gauge pair and a stop rule if none exists. Never hand-build the production record.
3. **D2 Definition repair.** RA-31a remains governing: derive the HardRail branch rule in the cross-rail field-matching `τ(f_a→f_b)` domain, name its publisher, prove rail-vertex path independence/fail-closed singularity behavior, and name a discriminating produced witness. Identity 2 keeps its name.
4. **D3/D7 witness authority.** The next Definition must specify a real-tracer fixture that actually produces a seam-collinear OrdinaryFront carrying the exact seam certificate; merely containing an isolation seam is insufficient. D3 and D7 keep distinct falsifiers.
5. **D4 witness authority.** The ordinary hard-feature falsifier must select/derive a route-bearing ordinary source carrier; `OrdinaryInterior` kind alone does not prove a non-empty route. Periodic/HardRail typed-source checks remain.
6. **Recovery status.** Predecessor `INCOMPLETE_AUTHORITY_PUBLICATION` and focused-relabel `RP-02` events are recovery-proved. The predecessor `RP-01` event remains open. No new event/category/recurrence is counted for R1.
7. **Routing.** Exact next is runtime-free `M6-DEFN-R5-R1`, followed by mandatory `M6-DEFN-R5-R1-REV`. Only accepted Definition Review may release one bounded R2 Code + Build. CB2 (D5/D6/D8) remains held until CP3 entry is fully green.


## RA-33 — M6-DEFN-R5-R1 CP3-entry Definition candidate (**NOT FROZEN; mandatory Definition Review required**, 2026-10-07)

**Candidate only.** This block is submitted for `M6-DEFN-R5-R1-REV` and has no implementation authority until independently accepted. Detailed formulas, source-line evidence, worked positive/negative examples and unresolved organic witness obligations: `Architecture_M6_DEFN_R5_R1_CP3_Entry_Recovery_Definition_Record.md`. RA-32 remains the accepted routing authority. In particular, a prescribed *search* is **not** proof that an organic witness exists.

1. **RA-33.1 A6 OrdinaryFront:** certified special isolation-seam path iff relation-owned reciprocal collinear side spans, matching region/source-face/sheet certificate, reciprocal side evidence and typed two-way isolation transitions all agree. Sheet ID inequality alone never grants special status. Partial special evidence fails closed; non-seam full chart/branch/phase/scale/sheet equality and all existing certified exact checks remain.
2. **RA-33.2 periodic D1:** select only among actual tracer-produced reciprocal source/A3-exact Periodic pairs from a bounded, deterministically enumerated nonzero-Z4 torus fixture with endpoint face-gauge delta `1` or `3 mod4`. Check source edge, selected faces, orientation, A3 matching, identical interval, reciprocal A4 edge identity and route before assertions. If none exists, return to Review; never fabricate records or accept an even delta.
3. **RA-33.3 HardRail D2:** `B_b ◦ B_a⁻¹ = R_coord ◦ τ(f_a→f_b)` in oriented Z4, where `τ` is an A3-verified cross-rail source-face matching, **not** a difference of region gauges. A4 owns publication of oriented τ into `SurfacePhaseFrontProduct`; A5 consumes the certificate. Check both endpoints, inverse orientation, rail-vertex path-independent composition, fail-closed nonzero singular holonomy and source barriers. Preserve published F as provenance only. Require a real-produced cross-region discriminant with `(F_b−F_a) != τ` before success. Identity 2 retains its existing name.
4. **RA-33.4 seam D3/D7:** prefer a seam-aligned real-tracer rectangle family and require actual OrdinaryFront collinearity, matching certificate, reciprocal side transitions, D7 disjoint endpoint wedge-sheet sets and real A5→A6→A7 positive chain. Distinct A6 branch-tamper and A7 evidence-tamper falsifiers. Input mesh seam alone is insufficient.
5. **RA-33.5 D4:** select only a *real produced* `OrdinaryInterior` A4 edge with nonempty route and an eligible actual source-chart carrier transition; its typed hard-feature injection must block that transition. Preserve independent Periodic/HardRail typed carrier checks. A boundary kind does not imply an A4 route.
6. **Release gate:** This Definition itself changes no production/test/fixture/selector/build/runtime logic. Frozen TB entry selection stays **497 = 30+12+449+6** (no renames). Stable **63/17/46**, debt **1**. `Architecture_M6_CP3_CB1_Entry_R2_Recovery_Code_Build_Plan.md` is **HELD**. Only `M6-DEFN-R5-R1-REV` may accept and release R2; an unresolved organic witness is a **stop for Review**, not permission to weaken assertions.


## RA-34 — M6-DEFN-R5-R2 **ACCEPTED at independent R2 Review** (bounded Definition only; 2026-10-08)

Independent `M6-DEFN-R5-R2-REV` accepts these two narrow Definition corrections to rejected RA-33. No organic produced-witness existence or runtime result is accepted. Full source reasoning, falsifiers and typed producer-authority stop rules: `Architecture_M6_DEFN_R5_R2_CP3_Entry_Recovery_Definition_Record.md`. RA-32 remains accepted routing authority. Amend only RA-33.1 and RA-33.3:

- **RA-34.1:** An A4-certified isolation seam must be found without raw/global sheet-label equality **granting or denying certificate lookup**. Bind selected source-face, A4 typed wedge-to-certificate sheet incidence and certificate orientation to one `Forward|Reverse` match, used consistently for branch quarter-turn, coordinate, phase, scale, source-chart and reciprocal checks. Only the certificate's typed endpoint sheets must be distinct. Missing A4 typed incidence, ambiguity or mixed orientation fails closed. Non-seam OrdinaryFront retains full equality; A7 independently checks its own cross-sheet conditions.
- **RA-34.3:** A4 owns and publishes exact A3-oriented cross-rail `τ_ab`; A5 consumes it and uses `(B_b-B_a-R_coord-τ_ab) mod4=0` with reciprocal inverse and path independence. A real-produced baseline-green HardRail witness must have **both** `(F_b-F_a) mod4 != τ_ab` **and** `τ_ab ∈ {1,3}` and reject τ sign inversion. Algebraic example `F_a=0,F_b=3,τ_ab=1,R_coord=1,B_a=0,B_b=2` is not a produced witness. Z4 commutativity prevents numerical testing of composition order; maintain typed domain semantics.

RA-33.2 periodic odd-gauge, RA-33.4 tracer-produced seam-collinear and RA-33.5 route-bearing organic positives remain unchanged and **unproven**. Entry gate is **497=30+12+449+6**; reviewed rejected run **482/497**, stable accounting **63/17/46**, debt 1. R2 Review releases ONLY bounded compile-only `M6-CP3-CB1-ENTRY-R2`. Independent A4-owned typed wedge-to-certificate sheet incidence is mandatory; if insufficient, STOP for producer-owned A4 contract Review, never manufacture an A6 map. Real-produced D2/D3/D4/D5 positives remain unproven and stop-gated. CB2 and CP3 exit remain HELD. See `Architecture_M6_DEFN_R5_R2_Review_Record.md`.

## RA-36 — HardRail route transport certificate **ACCEPTED at independent R2-P3 Review** (2026-10-08)

Resolves the `M6-CP3-CB1-ENTRY-R2` RA-34.3 stop. Full basis:
`Architecture_M6_CP3_R2P3_HardRail_Route_Transport_Review_Decision.md`.

**Singleton-only route contract is REJECTED.** A4 has no step cap
(`src/geometry/SurfaceCellTracing.cpp:11712`), so no singleton invariant exists to document; adopting one would
narrow a legitimate domain (consecutive hard edges `(1,4)`/`(4,7)` are a real producer input), and it would not
avoid fixing the miscoded failure below.

**Diagnosed error.** A5's `rail_tau` (`src/pipeline/RemeshPipeline.cpp:4916-4957`) requires *every* route step's
`SurfaceHardRailFieldTransition` record to carry the same incident-face pair as the relation's two selected
faces. Because two distinct triangles share at most one edge, any route with ≥2 distinct edges is unsatisfiable
by construction and returns `HardRailTransportMismatch` — asserting a transport disagreement never evaluated. The
rule conflates **endpoint attachment** with **transport agreement** and applies both per step; τ along a path
composes, it does not repeat.

> **RA-36.1 STATUS — PROVEN UNSOUND at `M6-CP3-TB1-ENTRY-R2-REV` (2026-10-08); owner `M6-DEFN-R5-R3`.**
> The path-connectivity clause below (*"consecutive steps share exactly one typed source face"*) is **false for
> every polyline carrier pair**: two collinear feature edges meet at a **vertex**, not a face, since a triangle
> spanning them would be degenerate. Verified counterexample on the supported 3×3 fixture — edge `(1,4)` faces
> `{0,3}`, edge `(4,7)` faces `{4,7}`, intersection empty. Implemented at
> `src/geometry/SurfaceCellTracing.cpp:18312-18321` by threading a single `current` face, it caused **25**
> `InvalidHardRailRouteCertificate` false rejections of previously accepted-green evidence (+1 `RP-01` event,
> accounting now **64 / 17 / 47**) and made A4's already-written vertex-fan junction logic at `:18337-18342`
> **unreachable**.
>
> **SUPERSEDED (2026-10-08, status updated by the reviewing agent):** the reconciliation this annotation awaited
> has completed. **`RA-37a`, accepted by `M6-DEFN-R5-R3-REV`, is the binding contract** and replaces RA-36.1's
> path-connectivity and composition clauses. RA-36.1's text below is retained as **history only** and must not
> be implemented. RA-36.4/.5/.6 remain in force, as RA-37a itself states.
> RA-36's *rejection of the singleton-only contract* is **unaffected and strengthened** — polyline carriers are
> real supported input. RA-36.4/.5/.6 stand.

- **RA-36.1:** A4 publishes, per paired cross-region HardRail route, an ordered oriented certificate: the
  canonical-orientation step sequence; per step both typed incident `SourceFaceTopologyKey` values and the exact
  oriented A3 `firstToSecond` validated against `FieldTransportAtlas::transition_value`; the **endpoint
  attachment** faces for the `a` and `b` ends; and **path connectivity** — consecutive steps share exactly one
  typed source face.
- **RA-36.2:** A5 consumes only that certificate. It composes `τ_ab` as a typed fold along the published path
  (`Z4` addition, reversed steps negate), verifies both `placement.selectedFace` values equal the published
  endpoint attachment faces, and applies the frozen `(B_b − B_a − R_coord − τ_ab) mod 4 = 0` at **both** endpoint
  pairs. The reverse relation inverts coordinate, branch and τ orientations together; orientations may not be
  mixed. A5 may not infer path, attachment or τ from regional `F` gauges, sheet labels, proximity, arbitrary
  traversal, first-step selection, fabricated records or a new unreviewed switch.
- **RA-36.3:** Consecutive side transports come from A3 source-face transition authority and must satisfy the
  cross-rail square `χ_(i+1) ∘ φ_a = φ_b ∘ χ_i`. Compose as a typed path — never average, never demand equal τ
  per carrier. A4 rejects typed fail-closed on absent/ambiguous path, disconnected face star, nontrivial singular
  holonomy, nonreciprocal A3 transitions, or a mismatching hard-feature owner.
- **RA-36.4:** Singleton is the **degenerate case** — path length 1, attachment faces are that edge's two
  incident faces, composed τ is its `firstToSecond` — and existing singleton behaviour must not regress. The
  frozen `497 = 30 + 12 + 449 + 6` gate and all currently green identities are the guard.
- **RA-36.5:** A route A4 cannot certify rejects with a typed code naming *that* cause. Reusing
  `HardRailTransportMismatch` for an uncertifiable or unsupported route is prohibited.
- **RA-36.6:** This decision grants **no runtime credit**. Existence of a produced multi-edge route is not
  established; if the bounded search finds none, the multi-edge path is unexercised and must not be cited as
  validated. All RA-34.3 R2-P3 stop gates stand — odd `τ ∈ {1,3}`, `F_b − F_a ≠ τ`, sign-inversion negative,
  reciprocal/face-permutation invariance — and an empty search **stops for Review**.
