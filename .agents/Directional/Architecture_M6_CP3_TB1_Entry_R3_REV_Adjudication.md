# M6-CP3-TB1-ENTRY-R3-REV — independent adjudication

**Verdict: the review is ACCEPTED — complete, accurate, and correct in its verdict, classification and
accounting.** `REJECT R3 / UNPROMOTED` stands; ledger **66 / 17 / 49**, debt 1, stands. Two findings are added
below, one of which exposes an unverified premise in **my own frozen RA-39.1** and is remitted to the chartered
`M6-DEFN-R5-R4`.

## 1. What I re-derived rather than accepted

- **Stable-event grouping (41 rows → 2 events).** Challenged and withdrawn. The tracker's own precedent is
  explicit that the unit is the **root cause**, not the ordinal: "do not call cascades new stable events"
  (line 20) and "R1-CAND-01's ten A6/D7 rows are **not** a new stable event" (line 43); confirmed events are
  named candidates (line 57). Grouping is correct.
- **Ledger arithmetic.** `64 / 17 / 47 → 66 / 17 / 49` is internally coherent: two new causes in **existing**
  categories, so events `+2`, categories `+0`, recurrences `+2` — the same shape as the accepted increments at
  `M5-CP3-TB1-R1-REV` and `-R13-REV`.
- **The 47-versus-41 correction is right and material.** 47 was the count *already lost in R2*, not the count of
  accepted CP2 cases RED in R3; the four-archive identity comparison yielding 53 carried + 41 new is the correct
  frame, and recovery scope correctly widens to **88** CP2 cases.
- **RA-40.1 is implemented soundly.** `make` binds the atlas, fails closed on null or source mismatch, and
  `matchesA3` re-derives through `transition_value` at **all three** sites — published rail transitions
  (`:8074`), the terminal carrier (`:8147`) and the radial witnesses (`:8232`) — checking forward **and**
  `reverse->transport == expected.inverse()`. Both χ and φ are covered, as RA-40 required.
- **The carrier-edge concern is answered by the source.** `matchesA3` is applied to hard-feature edges, so I
  checked whether A3 serves them: `transitionValues.push_back(...)` precedes the `hardFeatureEdges` →
  `nontraversableEdges` `continue` (`src/authority/FieldTransportAtlas.cpp:2041-2048`). RA-34.3 is correctly
  implemented and carriers do carry retained τ. No defect.
- **The review's epistemic discipline is correct and worth keeping.** Refusing to attribute all 34 to the
  factory check while "22 lack typed diagnostic and 12 expose only generic failure" is the right call, and
  generic `InvalidFinalCellState` collapse at `publish_phase_front_result` is correctly named as the reason
  attribution is not yet possible.

## 2. Finding 1 — the singleton signature is falsifiable now, and the observed one fails

D2 asks R4 to "independently trace" the `routeLength=1` misattachment but does not state what a **correct**
singleton looks like. It is determined, and stating it converts D2 from an investigation into a test.

By **RA-39.6**, a one-carrier route has both endpoint pairs on the *same* carrier, no junction, `φ` identity.
With carrier `(1,4)` owning `{0,3}`, RA-39.1 therefore requires **both** pairs to equal `{0,3}`:

```text
expected faceEnds for routeLength=1 on carrier (1,4) : 0,0 | 3,3
  (each front lies on ONE side, so its two trace endpoints share that side's face)
observed                                             : 0,2 | 0,3
```

Under **either** reading of the abbreviated record — pairs `(0,3)` and `(2,0)`, or the review's stated
`first.from=0 / second.to=2` — at least one pair is not `{0,3}`, and face `2` is not a carrier face at all.
Both fronts also touch face `0`, so they are not cleanly separated onto opposite sides. **No correct reciprocal
singleton pair can produce `0,2|0,3`.** This is a pre-committed falsifier for R4: if the front pairing is sound,
it must explain `faceEnds=0,2|0,3`; if it cannot, the defect is in front construction or side assignment,
upstream of RA-39 entirely.

## 3. Finding 2 — RA-39.1 rests on a semantics I never verified (my error)

RA-39.1 requires `{from_j, to_j} == {C_j.firstFace, C_j.secondFace}`. That presumes a front's `from`/`to` faces
**are** the rail's two side faces. But `SurfaceFrontEdge::from` and `::to` are `SurfaceTracePoint`
(`include/directional/geometry/SurfaceCellTracing.h:1514-1515`) — **endpoints of a traced curve**, which lie in
whatever face the curve happens to end in. They are not side labels, and **nothing in RA-37a, RA-38, RA-39 or
RA-40 defines their relation to a rail's sides.**

So there are two live readings of the 39-row family and the evidence does not yet separate them:

- **(a) RA-39.1 is right and front construction is at fault** — a front paired across a rail should be clipped to
  its side-local face, and endpoints wandering to face `2` are the defect.
- **(b) RA-39.1 is too strict** — endpoints may legitimately lie in any face on the correct *side*, in which case
  the local-attachment test must be **side membership** (connectivity without crossing the rail), not face
  identity.

This is the same class of error as superseded RA-36.1: taking an **identity** that holds in a degenerate case and
freezing it where only **connectivity** is warranted. I record it as my own exposure rather than let R4 verify my
premise as if it were given. For a singleton the sides are not globally well-defined (one interior edge cannot
separate a surface), which is why I chose identity — that reasoning is not wrong, but it was never checked
against `SurfaceTracePoint` semantics, and it must be.

**Remitted, not amended.** Consistent with how superseded RA-36.1 was handled, I do not amend my own frozen rule
outside a chartered Definition turn. `M6-DEFN-R5-R4` is that turn and already owns this as D2; it must now
resolve **(a) versus (b) explicitly** and freeze the front-endpoint-to-side contract, rather than only tracing
the instance.

## 4. Finding 3 — RA-40's blanket mandate is an authority-domain conflation

The review observes, correctly, that `make` "rejects a null/mismatched A3 atlas **even if no actual
nonrail/carrier witness needs checking**," then declines to downgrade RA-40. **Declining was right; the
observation is also right**, and it is my rule to answer.

A product carrying **zero** `hardRailFieldTransitions` and **zero** `hardRailRouteCertificates` has nothing
A3-derived to authenticate. Demanding a full source-bound atlas before it can be constructed couples an
unrelated stage to A3 — the **RP-01 AUTHORITY_DOMAIN_CONFLATION** pattern — and it is what turned a rail-specific
anti-tamper gate into a blanket product-construction gate, plausibly contributing to both new families (the 7 are
tests forced to fabricate real `TriMesh` A3 fixtures they never needed).

Scoping the mandate to products that carry A3-derived values preserves the **entire** anti-tamper property: every
φ and χ handed to `make` is still re-derived against ground truth, and there is still no
"unauthenticated-but-accepted" mode, because where no A3-derived value exists there is nothing unauthenticated.

**This is a conditional pre-commitment, not a downgrade.** It may be applied only after typed stage/error
propagation shows which of the 34 actually reach the factory check — the review's own precondition, which I
endorse. Null-atlas acceptance for a product that **does** carry rails or route certificates remains prohibited
under all circumstances. R4 must also treat `sourceFaceBranchRotations` explicitly: it is caller-supplied and
currently unauthenticated, and must not be silently exempted by any scoping rule.

## 5. Corrections to the review: none

I checked two suspicions and both failed against the source. The R4 plan's D2 **does** cover the carried 39
(`routeLength=1` endpoint-0 misattachment), so the charter is not under-scoped. And `matchesA3` on carrier edges
is **not** broken by hard-feature exclusion, because τ is retained first. Both are recorded here so neither is
re-raised.

## 6. Verification limits

Re-derived from bytes: the tracker's stable-event precedent; the ledger arithmetic; the RA-40.1 factory diff at
all three call sites; `FieldTransportAtlas.cpp:2041-2048` ordering; `transition_value` /
`matches_source_faces`; `SurfaceFrontEdge::from`/`::to` as `SurfaceTracePoint`; the R4 plan's D2 scope. Accepted
as reported: the artifact hashes, the four-archive identity comparison, the 403/94 split and the per-row overlay.
No runtime was executed in this adjudication.
