# M6-CP3-R4 — oriented terminal source-face germ and front-filled-side ownership: REVIEW DECISION

**Adjudicates:** `Architecture_M6_CP3_R4_RA432_Oriented_Germ_Producer_Boundary_Review_Request_20261013.md`
(and the earlier `Architecture_M6_CP3_R4_RA432_Terminal_Attachment_Source_Audit_20261012.md` it supersedes).

**Disposition: the REVIEW_BLOCKER is DISSOLVED. RA-43.2 is DISCHARGED. The requested producer receipt is
REFUSED as a namespace category error.** No runtime credit. Ledger **66 / 17 / 49**, M6 debt **1**, unchanged.
Selector **497 = 30 + 12 + 449 + 6** untouched; CP2 **491/491** accepted; R3 **403/497** rejected with 94 RED
and 88 accepted CP2 losses.

---

## 1. The request answers a question RA-43.2 does not ask

RA-43.2 (`Architecture_M6_Frozen_Definitions.md:440-447`) has exactly two operative sentences. It names the
owner of `SurfaceCellRail::sourceVertices` (the pipeline curve-network producer), relocates RA-42.1 so that
**the typed terminal contact is a required input bound at the A4 factory boundary**, and closes with the
scope limit, quoted verbatim:

> the endpoint certificate still stops reading `from.face`/`to.face` **for contact purposes**.

"For contact purposes" is the clause's own boundary. The *contact* is the typed terminal **vertex pair**. The
request's subject — an *oriented source-face germ pair* plus a *front-filled-side owner* — appears nowhere in
RA-43.2, nowhere in RA-43.1/.3/.4/.6/.7, and nowhere in RA-44, RA-45, RA-46, RA-47, RA-48 or RA-49. RA-45.7
states the residue precisely: "the endpoint-certificate **consumption** (RA-43.2) … remain[s] open." Not a
new publisher. A consumption.

**That consumption has landed.** `src/geometry/SurfaceCellTracing.cpp:19013-19014` looks the contact up by
`*first.railId`; `:19064-19069` iterates `contact->second.endpoints` and selects the terminal vertex from the
producer's typed pair; `from.face`/`to.face` no longer reach any contact decision. Absence is fail-closed at
`:19038-19043` (`missing-terminal-or-closed-rail-provenance`, with a typed closed chain as the only
contact-free route) and ambiguity at `:19068`. The factory re-validates the same contact at `:8308-8325`
(component against `SourceTopologyRegions`) and `:8474-8497` (endpoints against the carrier's first/last
vertex). RA-43.2 is **DISCHARGED** by these bytes.

The request therefore inflated a frozen clause's scope, declared the inflated version unsatisfiable, and
stopped the turn on it. The scope inflation is the blocker; removing it removes the blocker.

## 2. The requested receipt cannot exist, and the reason is RA-43.3

The request asks for a source-authored receipt binding
`(rail, terminal, source interval, oriented source-face germ, **filled-side owner**)`.

`filledCell` is an `authority::CellId` and `filledSide` is "counter-clockwise side of `filledCell`"
(`include/directional/geometry/SurfaceCellTracing.h:1555-1557`), a side index in `[0,4)` of an **A4 quad
cell**. Quad cells do not exist in the source domain; they are minted by A4's own tracing. A source-domain
producer asked to attest a `CellId` must therefore **invent** the right-hand side of the binding — which is
the prohibition the whole publish/don't-invent family exists to enforce, and it is the **fifth namespace**
alongside RA-43.3's four. The request half-sees this when it concedes "triangle winding cannot by itself
attest which A4 `filledCell/filledSide` is bound to which producer-side germ." Correct — and no producer
output repairs it, because the deficiency is not missing data upstream. **The named entity is created
downstream.** `REFUSED`; a "minimal new producer output" may not be specified, because any such output would
be fabricated authority.

## 3. The authority the request says is missing is already implemented, in three stages

The request's decisive factual claim is:

> `SurfacePhaseFrontProduct::make` checks certificate attachments against the **same** front trace-face rows.
> This does not create independent side authority.

That describes `src/geometry/SurfaceCellTracing.cpp:8450-8467` **and stops there**. `make` continues at
`:8588-8634`, under a comment that states the opposite of the request's conclusion: *"A2b uniqueness is
checked from source topology, not asserted by the paths in the certificate being validated."* The omitted
block re-derives, inside the factory, from source topology and A3 only:

- `unique_terminal_star_path(*vertex, endpoint.firstAttachment, carrier.firstFace)` and the same for
  `secondAttachment`/`carrier.secondFace`, each required **Unique** (`:8596-8608`), with typed
  `MissingTerminalA3Path` / `AmbiguousTerminalA3Path` detail;
- every `contactPaths[side]` step re-validated (`:8613-8626`): not in `hardFeatureEdges`, incident to the
  terminal vertex, chained (`step.firstFace != at` rejects), both faces incident to the edge, `matchesA3`
  against the atlas, and no repeated face;
- each walk required to **terminate** exactly at `carrier.firstFace` / `carrier.secondFace` (`:8628-8632`);
- the two sectors required **disjoint** (`:8632-8637`).

Upstream, the consumer does not read a side off the trace either. `:19137-19173` loops over **both** carrier
orientations and keeps the one for which both attachment walks exist with disjoint sectors, rejecting
`ambiguous-carrier-orientation` if both succeed (`:19166`). The oriented side is therefore **selected by
source topology and A3**, not copied from A4.

Downstream, the absolute binding is closed twice:

- `make` pins the attachment pair to the two front edges' own trace points in the pairing order already fixed
  at `:8438-8447` (`:8458-8466`), so swapping the certificate's two attachments is rejected there;
- A5 pins them to occurrence placement: `src/pipeline/RemeshPipeline.cpp:5003-5004` requires
  `from->placement.selectedFace == published.firstAttachment` and
  `to->placement.selectedFace == published.secondAttachment`, and `:5008-5012` requires
  `QuarterTurn::from_integer(toLattice.branchRotation - fromLattice.branchRotation) ==
  compose(*rigidRotation, published.attachmentTransport())`, where `attachmentTransport()` is
  `phi[1]^-1 ∘ carrier ∘ phi[0]` over the **authenticated** star walks
  (`include/directional/geometry/SurfaceCellTracing.h:1501-1509`).

**That is the front-filled-side ownership.** It is established where the filled side exists — at the A5
occurrence — against a certificate whose orientation was chosen in the source domain and whose transport is
A3. The chain is: producer owns the terminal vertex; source topology + A3 own the orientation; the trace owns
the attachment identity; A5 owns the filled side; and all four must agree or the product is rejected. There
is no seam.

## 4. The one real residual, named

**`R4-SID-01 / SIDE_AUTHORITY_LOCUS` (architectural, no runtime credit).** The certificate **alone** does not
pin which side is "first": a simultaneous swap of `firstAttachment`/`secondAttachment` with the carrier
reversed is internally consistent, since the orientation loop at `:19137` accepts whichever orientation the
sectors support. What breaks the symmetry is external — `make :8458-8466` against the fixed front-edge
pairing, and A5 `:5003-5004` against occurrence placement. Note that `attachmentTransport()` inverts under
that swap, so A5's transport check at `:5008-5012` catches it **only when the composed τ is not
self-inverse**; for τ ∈ {0, 2} the inverse equals itself and `:5003-5004` is the sole discriminator. That
check is therefore **load-bearing and must not be weakened or reordered**, and the two sites may not be
described as redundant with each other.

Consequence for test design: **any regression asserting that the certificate by itself determines the filled
side is vacuous** and may not be written or counted. A side negative must tamper at one of the two external
pins and name which one rejected.

## 5. The request's correct points, accepted

1. **The RA-46.5 double-counting warning is correct and is ACCEPTED.**
   `tests/SurfaceCellTransitionQuotientTests.cpp:9052-9071` is a genuine, non-vacuous **factory** negative:
   it takes a real produced non-hard spoke from `contactPaths[side]`, inserts that exact edge into the source
   hard-feature barriers, and asserts the factory's typed `MissingTerminalA3Path` detail. It is **not** the
   A4 **consumer** first-rejection predicate `missing-terminal-A3-path` at `:19175`. The two stages are
   distinct and the factory test may **not** be counted toward consumer first-rejection coverage.
2. **The `append_edge_interval` observation is factually correct and architecturally inert.**
   `src/pipeline/RemeshPipeline.cpp:9289-9295` does take the first in-range `edge.incidentFaces` row, but that
   face is consumed only by `make_surface_cell_rail_sample` for `SurfaceCellRailSample` geometry
   (`:9309-9316`), guarded by the corner-membership check at `:9301-9307`. It is never read as a side
   credential by the certificate, the factory or A5. No repair is owed.
3. **RA-49.5 / `R4-CTC-01` is correctly preserved as a deferred Definition issue.** The consumer reads the
   contact at `:19013` and the factory validates it at `:8308`; validate-after-use stands, both checks stay,
   and its repair is not an R4 change.

## 6. Line-citation drift (procedural hazard, recorded once)

The RA-43.4 named-mode and network-override patches shifted `SurfaceCellTracing.cpp` by roughly +16 lines.
RA-49's frozen citations `:18999`, `:19052`, `:19055`, `:19167`, `:19170`, `:19446` now read `:19015`,
`:19068`, `:19071`, `:19183`, `:19186`, `:19462`. **The ordering RA-49.0 established is unchanged** —
consumer at `:19183`/`:19186`, factory route at `:19462` — and no RA-49 conclusion moves. Future citations
must re-anchor by symbol, not by remembered line.

## 7. What the request got right about method, and what it got wrong

Right: it refused to consume trace-face rows as authority without checking, and it declined to fabricate a
passing route. That instinct is correct and is why this ends in a discharge rather than a defect.

Wrong, twice. It read a frozen clause past its own stated scope limit, and it cited one of two contiguous
blocks of the factory check while concluding from the absence of the other. An unsatisfiability finding must
be derived from the **whole** predicate set on the path, not from a prefix of it — the same discipline RA-49.0
imposed for execution order, applied now to **extent of inspection**.
