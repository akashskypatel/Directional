# Architecture Review Decision — `M6-CP3-DEFN-R4-ENDPOINT-AUTHORITY-SPEC-REV`

**Date:** 2026-10-15 · **Reviewer turn:** `M6-CP3-DEFN-R4-ENDPOINT-AUTHORITY-SPEC-REV`
**Adjudicates:** `M6-CP3-DEFN-R4-ENDPOINT-AUTHORITY-SPEC` (commits `db0b44a25`, `e87b7a3ad`,
`fbbbbf972`, `f3a9f38f2`, `11a601e76`)
**Subject document:** `.agents/Directional/Architecture_M6_CP3_R4_Endpoint_Authority_Specification_20261015.md`
**Verdict:** **ACCEPTED WITH AMENDMENT.** Gate C suspended; gate A's reciprocity conjunct struck;
**RA-64.6 withdrawn in full**; RA-64.4's illustration withdrawn, its conclusion retained.
No open REVIEW_BLOCKER. No promotion, no stable event, no regression recurrence, no gate credit.

---

## RA-65.1 — Authority re-derived from the provider and from tree objects, not accepted

Run `38765685488` (`Agent Source Snapshot`) is `success` with `headSha e87b7a3ad7a31577bfe758f6b00f3cdcd4f8ab3e`,
matching the spec's cited snapshot commit exactly. Artifact `11989475541`
(`agent-source-snapshot-38765685488`) is present at 24,087,190 bytes and unexpired. The snapshot log
(artifact `11989755474`) records `event_sha = snapshot_sha = final_sha = e87b7a3ad…`,
`snapshot_file_count=5640`, `snapshot_byte_count=102008557`,
`archive_sha256=5195b468af2fe726f3f526d73a831d3d20813bd52b5635dda5ec7a972d0aaf8b`.

**Tree identity — the decisive check.** `src` `76a12d4053a5c0798adcb0dce6d5eb8bf4e29623`, `include`
`790328c2bcffe29db5366ea1193cf0ab6d8cba58`, `tests` `cbef8d5ec448edb4c048b9058c7a0bd10a32b8af`, and the
decisive blob `src/geometry/SurfaceCellTracing.cpp` `6605c9f9ee8d7fc7859260b389f7fa2de755306f`, are
**byte-identical at the packaged semantic source `16c3134c0`, at the snapshot `e87b7a3ad`, and at HEAD**.
The specification therefore read exactly the bytes that were compiled into package `11976790988` and
measured by the 44-identity harvest. Every line citation below applies to the measured package.

Two files changed across the whole turn — the specification document and `STATUS`. No source, test,
selector, binary, harness, workflow, benchmark or ledger-count change; no Directional binary executed.

**Minor correction, charged under RA-61.5.** The spec's evidence line reads "**5640/5640 source
hashes**". The log records `snapshot_file_count=5640` — a **file count** — and verifies **no hashes at
all**. A count was dressed as a verification ratio in the one line that establishes the turn's
authority. The count itself is real and confirmed.

## RA-65.2 — ACCEPTED: the RA-64.6 answer is correct, and the bytes say it more strongly than the spec does

The spec's central publisher claim — that `assign_open_front_boundary_authority` cannot silently omit a
carrier — is **CONFIRMED** from `src/geometry/SurfaceCellTracing.cpp`:

- `:12570` iterates **every** segment of the supplied `path`;
- `:12576-12591` derives the carrier topology from that segment's own face and its unsupported corner;
- `:12594-12597` **requires the segment's face to be one of that carrier's two incident faces**;
- `:12641-12644` flushes the open run the moment the carrier topology changes;
- `:12645-12647` rejects a nonconsecutive repetition of a carrier already seen;
- `:12669` flushes the tail run after the loop;
- and **every** failure path returns `SurfacePhaseFrontFailureReason::InvalidFrontBoundaryAuthority`.

A path carrying two carriers therefore yields **two** observed steps or **no front at all**. There is no
code path that shortens a route. `routeLength = 1` does mean this front side's supplied segment path has
one carrier run, and the spec's refusal to settle whether the *path itself* was complete — "static
inspection of this loop does not prove the preceding chart-path producer generated every intended
segment" — is the correct residue to leave open.

**Credit:** the spec answered the half the bytes decide and declined the half they do not, and it did so
without reclassifying a single RED.

## RA-65.3 (PRINCIPAL) — the endpoint faces `{0,7}` were never measured; RA-64.6 is withdrawn in full

The probe emits exactly these scalar families, and no other:
`a2bProbeCarrierPresent`, `a2bProbeFailure`, `a2bProbeFirstFailedCondition`,
`a2bProbeFromSourceVertex`, `a2bProbeToSourceVertex`, plus the two `append_interval` blocks.
**No face is emitted anywhere in the diagnostic block at `:19395-19477`.**

`{0,7}` was the reviewer's inference, not a measurement. In the fixture, source vertex 4 belongs to
**six** faces — `0=(0,1,4)`, `1=(0,4,3)`, `3=(1,5,4)`, `4=(3,4,7)`, `6=(4,5,8)`, `7=(4,8,7)` — and
`carrier-orientation` fails for **any** attachment pair other than `(0,3)` or `(3,0)`. `{0,7}` was one
admissible reading among many, selected without warrant and then reported as measured.

Consequences, stated exactly:

- **RA-64.6 is WITHDRAWN in full.** "The route under-reports the front's extent" rested entirely on the
  invented pair: with the faces unknown, nothing says two carrier edges are required. Both of its
  readings (i) and (ii) are vacated along with the question itself.
- **RA-64.4's conclusion survives; its illustration does not.** That a face-pair mismatch fires first
  for all 21 is not an inference — it is what `carrier-orientation` *means*, and it was measured. The
  narrative that face 7 belongs to the rail's other edge and that "the geometry already spans the
  junction" is withdrawn.
- **The spec caught this and said so** at its line 15: *"the two-carrier inference drawn in RA-64.6
  solely from endpoint faces `{0,7}` and a one-step carrier `(1,4)` is unsound… No additional route step
  may be invented from endpoint face IDs alone."* Correct, and credited. This is the second consecutive
  turn to correct the reviewer on the record.

## RA-65.4 (new lesson) — an explanatory instance is not a measurement

**A mechanism that *would* produce the observed value is not the mechanism that *did*.** Fifth member of
the family: provenance (RA-61.5), satisfiability (RA-61.7), event counting (RA-63.10), reachability
(RA-64.12), and now **uniqueness**. RA-61.5 required a prediction to state where its value came from;
this requires an explanation to state that **no other explanation fits the same evidence**, and to name
the measurement that would separate them when others do.

## RA-65.5 (DEFECT) — gate C names a witness that no producer publishes

Gate C admits a chart not incident to the carrier edge "only through a **source-attested, uniquely
admissible vertex-star route** at that same vertex." The A3 authority product is
`SurfaceHardRailFieldTransition` (`include/directional/geometry/SurfaceCellTracing.h:1482-1489`):

```cpp
struct SurfaceHardRailFieldTransition {
  authority::SourceEdgeTopologyKey edge;
  authority::SourceFaceTopologyKey firstFace;
  authority::SourceFaceTopologyKey secondFace;
  authority::QuarterTurn firstToSecond;
  auto operator<=>(const SurfaceHardRailFieldTransition &) const = default;
};
```

One source **edge**, its two faces, one quarter turn. There is **no vertex-keyed transition record
anywhere in `include/` or `src/`**: every `vertexStar*` symbol in the tree is a *diagnostics* field
(`include/directional/diagnostics/RemeshDiagnostics.h:459-477`), never an authority product.

Gate C therefore proposes a predicate whose attesting producer does not exist — the RA-61.7
satisfiability failure one level up, and precisely what RA-64.11 bound this rung to avoid. **Gate C is
SUSPENDED** until a successor either names the producer that would publish such a route or withdraws the
gate. **Gates A, B and D stand.**

## RA-65.6 (DEFECT) — two vacuous conjuncts, immediately after RA-64.5 condemned exactly that pattern

**(a) Gate A's "exactly reciprocal endpoint ordinals" cannot be false.** The ordinals are *minted, not
measured*. `:17073-17079` writes the forward interval as
`from_integer(ordinal)` / `from_integer(ordinal + 1U)`; `:17095-17101` writes the reverse interval as
`from_integer(ordinal)` / `from_integer(ordinal - 1U)`. Reciprocity between a paired forward and reverse
arc is a **construction identity**. This is strictly stronger than RA-64.5, which found the conjunct
satisfied 44/44 by measurement: it is satisfied 44/44 **by construction**, and would be satisfied by any
population whatever.

**(b) "Identical … support piece" (spec line 28) carries no information.** `:17051` rejects outright any
`location->supportPieceIndex != 0U`. The support piece is therefore **0 in every record that survives to
be compared**.

The spec warns against this at line 28 — *"This is not withdrawn RA-61.9 under a new label"* — and then
commits it twice. The **one** conjunct that does work is independent per-endpoint exact parameter
resolution, which is genuinely new and is exactly what RA-63.5 showed the per-edge interval cannot do.
Keep it; strike the two decorations. A conjunct that cannot be false is not a gate.

## RA-65.7 — the "exposure" the contract asks for is a type change, and no published type can receive it

The producer computes precisely the product the contract wants. At `:17047-17060`, `location_parameter`
resolves an exact `authority::FieldExactRational` edge parameter from
`baseline.breakpoint_location(span, exactOrdinal)` — and the spec's citation of
`GlobalConformityBaselinePlan::breakpoint_location` is **accurate**
(`include/directional/geometry/GlobalConformityBaseline.h:181` and `:216`).

That exact value is then destroyed twice:

1. `:16791-16792` — `boundary_trace_point` casts it: `const double canonical = static_cast<double>(canonicalParameter.to_double());`
   Its destination `SurfaceTracePoint` is, in its entirety,
   `{ int face = -1; Eigen::RowVector3d barycentric = …; }` (`SurfaceCellTracing.h:90-93`) and
   **structurally cannot hold an exact parameter**.
2. The published `SurfaceSharedBoundaryInterval` (`SurfaceCellTracing.h:1418-1428`) carries `span`,
   `firstOrdinal`, `secondOrdinal`, `orientation`, `boundaryOccurrence` — the **breakpoint index**,
   never the parameter.

So "a later implementation should expose **that same checked producer product**" (spec line 26) is not
an exposure: **no published type has a field that can receive it.** Recorded, not escalated — the spec's
line 19 deliberately declines to name a new type in a DEFN turn, and that restraint was correct. The
successor that implements this must budget for the type change as the substance of the work, not as
incidental plumbing.

## RA-65.8 — reopened: the spec read past a truncation mechanism inside the range it cited

The spec declared interpretation (i) "not established" and required a future claim to exhibit a specific
missing segment carrier. A **mechanism** exists, in the very range the spec cites (16990–17120):

```cpp
if (!subdivision.points.empty() &&
    (subdivision.uv.back() - uv).norm() <=
        1.0e-10 * std::max({1.0, width, height})) {
  return true;                                          // :17032-17036 — point dropped, success returned
}
```

`append_point` **silently drops** a point on a `1e-10` UV-proximity test and returns `true`, while the
interval for that ordinal is pushed **unconditionally** (`:17081`, `:17103`). Points and intervals can
therefore desynchronize, and a dropped breakpoint can collapse a carrier run out of the path **before**
`assign_open_front_boundary_authority` ever sees it — upstream of the publisher RA-65.2 cleared.

**Not demonstrated for the measured 44**: their ordinals are exact integers on a unit grid, where a
sub-1e-10 UV coincidence between distinct breakpoints is implausible. The spec's conclusion for the 44
therefore stands. Its *general* claim that a second carrier "cannot be silently omitted" is correct only
of the A4 publisher, not of the pipeline. Backlog locus, not this rung's work.

## RA-65.9 (scoped correction) — `routeLength = 1` is exact only up to 1e-9

`assign_open_front_boundary_authority` carries `constexpr double tolerance = 1.0e-9` (`:12507`) and
decides, entirely in doubles: which corner is unsupported and hence **which edge is the carrier**
(`:12578-12579`); whether a run's parameter delta is large enough to publish at all (`:12539`); and
whether consecutive segments connect (`:12655`). `canonical_retained_edge_parameter` (`:12509-12531`)
returns a clamped `double`. The spec's "**precisely**" at line 9 should read "up to that tolerance".

Harmless for the measured 44 — their barycentrics are exact 0/1 — but it undercuts the document's
framing, in which the route is treated as reliable exact authority while only the endpoint half needs
exactness. Recorded as a backlog locus.

## RA-65.10 (NEW structural locus) — the endpoint points are not drawn from the front's own path

```cpp
edge.from = cell.corners[static_cast<std::size_t>(side)];
edge.to   = cell.corners[static_cast<std::size_t>((side + 1) % 4)];
```

at `:13034-13035`, `:14774-14775` and `:17345-17346`. The certificate's endpoint trace points come from
the **cell corner array**; the route comes from `cell.boundaryPaths[side]`. Every path segment is forced
incident to its carrier at `:12594-12597`. **Nothing anywhere reconciles the corner array against the
path's face set.** That absent invariant — not the terminal-contact vocabulary — is where gate D's phrase
"endpoint incidence" must actually bite: at **corner-to-path** incidence.

## RA-65.11 — the decisive measurement costs five integers, and it now outranks the RA-63.11 deferral

Whether `oriented_carrier`'s refusal is a granularity defect or a **correct refusal** turns on *which*
faces the two corners are charted in — the one fact never measured. Both outcomes are live:

- if the two charts lie in the **same** rail sector of the shared vertex, gate C has something it could
  admit and `RP-01`'s third expression is real;
- if they lie in **opposite** sectors, the endpoint is charted across the very feature the rail protects,
  `oriented_carrier` was right all along, and the defect is **chart selection**, not vocabulary.

Every value needed is already in scope inside the existing post-decision block: `fromPoint`, `toPoint`,
`probeCarrier`, and the two derived attachment keys the predicate actually compares. The RA-63.11 ladder
reorder was deferred to avoid invalidating the packaged compile at `16c3134c0`; that package's central
narrative has just been withdrawn, so the preservation argument no longer outweighs the measurement.

## RA-65.12 — beacon

`Status: COMPLETE`, all six fields present, `Ended at:` populated, `Successor: UNKNOWN` **with reasoning
carried in the document**: *"An implementation or independent Review successor requires separate explicit
turn authority; no successor ID is invented here."* That is the RA-63.13 shape, not the RA-64.10
self-reference. **No defect.**

## RA-65 — accounting

Ledger **66/17/49**, debt **1**, CP2 **491/491** accepted, R3 **403/497** rejected (94 RED, 88 carried
CP2 losses), frozen selector **30+12+449+6 = 497** — unchanged. The 44 RED remain the `R4-VIN-01`
baseline for `16c3134c0`, never a comparand against `11967601999`. No accepted-green loss, no ledger
credit, no promotion, no stable event, no regression recurrence, no 497 execution, no gate credit.
PR #8 draft/open.

`RP-01` **located, three expressions, one of them now in question** (RA-65.11) — not repaired;
specification delivered and amended; **code still not authorized beyond the diagnostic probe**.
`RP-02` **UNREACHED**. `RP-03` satisfied and exemplified a second consecutive turn.
`PROCESS-01` tooling residual discharged for every observed failure mode.
**RA-61.9 WITHDRAWN, final. RA-64.6 WITHDRAWN, final.**

Both gates run and reported: `review_check.py boundary` → ALL CHECKS PASSED (0 documents changed by the
adjudicated turn); `review_check.py ledgers --base 0cabf1ebd` → ALL CHECKS PASSED.

Successor: **`M6-CP3-CB4-R4-ENDPOINT-CHART-PROBE`**.
