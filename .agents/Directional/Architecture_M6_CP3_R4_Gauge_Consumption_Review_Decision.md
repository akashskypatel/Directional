# M6-CP3-CB1-ENTRY-R4 — the +U gauge has no absolute consumer: Review decision

**Type:** runtime-free independent Review of the RA-44.2 producer-compatibility STOP.
**Disposition:** the STOP is **ACCEPTED and upheld on its facts**, and it is resolved by **withdrawing the
requirement**, not by constructing a pin. **RA-44.2's absolute geometric pin is WITHDRAWN.** Frozen as
**RA-45**. The R4 Code + Build turn is released to continue; the three producers are all admissible.

Read at HEAD `7f4a643d2`. Every claim is a direct byte read re-derived in this turn.

---

## 1. The STOP's facts are correct

Three gauge producers reach one checked factory, and only one of them has the structure RA-44.2 assumed:

- **Planar** — `build_planar_phase_frame` (`src/geometry/SurfaceCellTracing.cpp:11143-11260`) builds
  `frame.axisU`/`axisV` and selects per face under `bestAlignment >= 1 - 1e-8`, with the `axisV` cross-check.
  RA-44.2's axes and predicate exist here.
- **Annular** — `score_ring_candidate` (`:13510-13691`) scores candidate seeds by averaging squared
  `acos(clamp(dot))`, selects the lowest finite score (`:13694-13704`) and publishes transported per-face
  branches (`:13804-13832`). A **best-fit minimisation**, not a zero-angle gate. No global `axisU`/`axisV`.
- **Curved bounded disk** — a deterministic face is chosen (`:15392-15433`), initialised to branch **0**
  (`:15488-15494`), and branches propagate by field-transport BFS (`:15495-15556`). No geometric gate at all;
  the root value is a **convention**.

The STOP is also right on the two traps it refuses to walk into: constructing `axisU` from the asserted
branch would pass trivially — the exact reason RA-43.5 was withdrawn — and the relational pin alone does not
reject a balanced global `+1`.

## 2. Why no construction exists: the requirement was a category error

I looked for what consumes the gauge. **Nothing consumes it absolutely.**

- `RemeshPipeline.cpp:4605-4622` reads the gauge at an occurrence's `placement.selectedFace` and wraps it as
  `SurfaceOccurrenceEndpointFaceGaugeAuthority{face, QuarterTurn::from_integer(gauge)}`.
- It is stored only as a **pair** on `SurfaceOccurrenceRelationEvidence`
  (`include/directional/pipeline/RemeshPipeline.h:865-869`), assigned at `RemeshPipeline.cpp:5172-5173`.
- `:7300-7301` reads **presence only** (`has_value()`), never the value.
- `:5613-5630` reads presence and the **face identity** (`firstGauge.face != ...placement.selectedFace`),
  never the rotation against anything absolute.
- The only use of the value is the **difference**:
  `compose(second->localFaceBranchRotation, first->localFaceBranchRotation.inverse())`
  (`tests/SurfaceCellTransitionQuotientTests.cpp:3152-3153`).

`QuarterTurn` is Z4 and Z4 is abelian, so a uniform `+1 mod 4` on every face cancels in every such
difference: `(g+1) ∘ (g'+1)^-1 = g ∘ g'^-1`. **A balanced global rotation changes no consumer's decision.**

So RA-44.2 demanded absolute authentication of a quantity that is only ever consumed relationally. That is
why no construction exists for the annular and curved producers: there is nothing absolute there to
authenticate. The planar producer's `axisU` gate is *that producer's own convention-selection rule* — an
artifact of how it picks a gauge, not a property the gauge is required to have. Freezing one producer's
selection rule as a universal authentication requirement was my error. Withdrawn.

## 3. What the authentication actually is

The relational A3 pin, **already implemented and compiled green** at `src/geometry/SurfaceCellTracing.cpp:8038-8080`:
it builds typed `SourceEdgeTopologyKey` incidence from `topology_for_row`, skips single-incidence open
boundary, and rejects unless `reverse->transport == forward->transport.inverse()` **and**
`compose(forward->transport, first) == second`. Together with mandatory presence (`:8020`) and
`SourceFaceTopologyKey`-derived keying, this rejects **every alteration a consumer could observe**:

| Perturbation | Outcome | Why |
|---|---|---|
| one face changed | **REJECT** | breaks the relation on that face's edges |
| any subset changed | **REJECT** | breaks the relation at the subset boundary |
| gauge vector permuted | **REJECT** | the relation is checked against `topology_for_row`, not the vector's order |
| A3 transport mismatch | **REJECT** | `compose(forward->transport, first) != second` |
| gauge absent while consumed | **REJECT** | the presence gate at `:8020` |
| **uniform `+1 mod 4` on every face** | **ACCEPT** | a gauge transformation, inert in every difference |

The last row is the reclassification. My pre-committed negative — "a balanced `+1 mod 4` on every face must be
REJECTED" — is **withdrawn**. Rejecting it would reject a legitimate convention, and it is unimplementable
without a pin that does not exist. Its replacement is a strictly stronger **positive** obligation: a uniform
rotation must be **accepted** and must produce a **bit-identical A6 relation outcome**. That tests
gauge-invariance as a property rather than asserting a value no one reads.

## 4. One real constraint this exposes: do not normalise

`RemeshPipeline.cpp:2134-2144` folds the gauge into a provenance digest. So a uniform rotation is
**semantically inert but not digest-inert**. The factory must therefore **validate and never rewrite** — it
may not canonicalise the gauge (for instance by rotating it so some root face reads 0), because that would
change accepted CP2 provenance digests. Accept as produced.

This also dissolves RA-44.5's residual for authentication purposes: A4's floating-point alignment predicate is
no longer load-bearing for any check. It remains the planar producer's own selection rule and stays untouched.

## 5. Answers to the STOP's three questions

1. **No** chart-U/V derivation for all three producers is required, because none is needed. Question 1 is
   moot.
2. **No** producer-specific absolute pin is authorised, and none is needed. RA-44.2 **is** formally amended —
   by this decision, which is the Review verdict the STOP correctly declined to make itself.
3. The witness schema is frozen in RA-45.3/.4/.5 below, with its coverage matrix in §3.

## 6. Disposition

R4 Code + Build continues. RA-44.1's terminal-contact binding has landed
(`SurfaceHardRailTerminalContacts` as `std::map<HardRailId, SurfaceHardRailTerminalContact>`, header `:1512-1517`,
threaded into `make` at `:1882`) and is **accepted in shape**; its germ and endpoint duties remain open. No
runtime ran. Selector 497 untouched. CP2 491/491 accepted; R3 403/497 rejected, 94 RED, 88 accepted CP2
losses. Stable ledger **66 / 17 / 49**, debt **1** — unchanged: an over-strong requirement frozen in a review
document is a review defect, not a runtime regression. RA-41's junction/sector clauses remain frozen
**UNEXERCISED** and the multi-carrier STOP stands.
