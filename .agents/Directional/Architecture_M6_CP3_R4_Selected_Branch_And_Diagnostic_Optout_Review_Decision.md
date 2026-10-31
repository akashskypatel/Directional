# M6-CP3-R4 — selected-branch / filled-side provenance and the RA-43.4 opt-out policy

**Review Agent decision.** Adjudicates `Architecture_M6_CP3_R4_Source_Current_Review_Gate_20261014.md`.
Snapshot: `cddb0b8f8` (`STATUS` BLOCKED). No runtime credit. No ledger movement. R3 stays rejected
403/497; CP2 stays accepted 491/491; ledger 66/17/49; M6 debt 1.

**Verdict: the REVIEW_BLOCKER is DISSOLVED. Both offered options are REFUSED.** The stop asks Review to
decide two questions that are already frozen-decided and one whose only outstanding element has already
landed. One genuine, bounded finding is recorded (`R4-SID-02`), one comment correction, and one policy
disposition (RA-43.4: PRESERVE, scoped).

---

## 1. What the stop asked, and its vintage

The gate demands "Independent RA-43.1 / RA-43.2 Review must decide either **(A)** a source-checked existing
join from one exact A4 directed occurrence and front-side to the uniquely selected A1 `FieldBranch`/arrival
mode and source chart, or **(B)** authorize a minimal typed upstream producer receipt `(HardRailId, directed
occurrence, junction SourceVertexId, source face/chart, FieldBranch, arrival mode, filled cell/side)` with
first-consumer checks."

Three facts about the state it adjudicates against:

- **RA-43.2 is DISCHARGED.** RA-50.1 discharged it by bytes on 2026-10-13 (`SurfaceCellTracing.cpp`
  `:19013-19014`, `:19064-19069`, fail-closed `:19038-19043` / `:19068`; factory re-validation `:8308-8325`,
  `:8474-8497`). The gate neither cites RA-50 nor argues against it.
- **Option (B) ends in `filled cell/side`** — the exact object RA-50.2 **REFUSED** as a fifth-namespace
  category error, on the ground that a source-authored receipt naming an A4 quad-cell side must invent the
  right-hand side of its own binding. Re-proposing a refused construction verbatim, without engaging the
  refusal, is not an architectural question.
- **RA-43.1's only outstanding element has landed.** RA-43.1 states "only the carrier **cut** is missing,
  and it is a `continue` on carrier membership inside the `:1452` loop: no new state, no new tau definition,
  no A5-side search." That `continue` is present at `src/geometry/SurfaceCellTracing.cpp:1457-1467`, inside
  the `topology.transports()` loop at `:1454-1456`, cutting `FieldTransportBarrierKind::HardFeature` and
  explicitly distinguishing `SourceBoundary`. It carries the comment "RA-43.1: the terminal germ is a
  connected component of the vertex star after cutting certified incident hard-rail carriers."

### R4-VIN-01 / STALE_FROZEN_VINTAGE — the third graded failure of a feasibility STOP

The family now reads: **RA-49.0 — wrong stage** (a guard cited as protecting a predicate that executes
before it); **RA-50.0 — wrong extent** (a frozen clause read past its own stated limit); **RA-51.0 —
neither**, the reusable correct shape; and now **RA-52.0 — wrong vintage**: a stop adjudicated against a
frozen state that has since moved, re-opening a discharged clause without citing its discharge and
re-proposing a refused construction without engaging the refusal. The diagnostic is cheap and belongs in
every future stop: **before raising RA-N as a blocker, cite RA-N's most recent disposition and say why it
does not apply.**

---

## 2. Review A — answered: the join does not exist because no consumer needs it

The stop's factual claims about the two structures are **correct** and independently re-derived:

- A2a `FieldAlignedCandidateTraceSegment` (`include/directional/geometry/SurfaceCellTracing.h:401-423`)
  carries `authority::FieldBranch branch` — a gauge-invariant Z4 value in a canonical source-face frame
  (`include/directional/authority/FieldTransportAtlas.h:51-74`).
- A4 `SurfaceTraceSegment` (`:1211-1233`) carries `int family` / `int sign`, minted inside A4's own tracing
  from the supplied face frame (`src/geometry/SurfaceCellTracing.cpp:10805`, `:12120`, `:13398`, `:13525`),
  plus `sourceChart`, `entryRoute`, `railId`, interval fields. There is no `FieldBranch` member.

Both namespaces exist. The stop then concludes that a join is owed. **It is not**, for a reason neither
option contemplates.

### 2.1 `family`/`sign` is consumed relationally and as digest material only

Every use of `.family` in `src/pipeline/RemeshPipeline.cpp` is enumerable and was enumerated:

| site | use |
| --- | --- |
| `:1989`, `:2204`, `:2264`, `:2350`, `:2473`, `:2574`, `:2631` | `hash_combine_i64` — digest input |
| `:10749` | `arrangementArc.family = arc.family` — copy-through |

**Seven digest inputs and one copy. Not one decision.** Inside A4 the only reads that gate anything are
run-merge tests in a single frame — `segments.back().family == family && segments.back().sign == sign`
(`src/geometry/SurfaceCellTracing.cpp:12111`, `:13533`) — i.e. equality against the immediately preceding
segment, never against a source authority.

A digest cannot separate a correct branch selection from an incorrect one: a wrong-but-consistent `family`
hashes consistently. Any regression that asserted "the digest pins the selected branch" would be **vacuous**
in the LESSONS 171 sense — structural presence, not behavioural coverage.

### 2.2 This is RA-45.2's category error, third instance

RA-45.2 withdrew RA-44.2 because it "demanded absolute authentication of a relationally-consumed quantity."
RA-50.2 refused the oriented-germ receipt for the adjacent reason. The present request demands absolute
authentication of `FieldBranch` at an A4 occurrence, where the A4-side quantity is consumed only as digest
material and same-frame run continuity. **Option (A) is REFUSED** — the join it asks Review to find would
have no consumer, so finding it would prove nothing and constraining it would constrain nothing.
**Option (B) is REFUSED** — minting the receipt would *manufacture* the consumer, creating a fresh
unsatisfiable obligation of exactly the kind RA-45, RA-50 and RA-51 have now retired three times.

The discriminating question stands unchanged: **what can this predicate actually separate — on the path it
actually sits on?** Here: nothing, because there is no path.

### 2.3 A4 never consumes A2a trace segments at all — the sixth namespace

The census of `options.fieldAlignedNetwork` in `src/geometry/SurfaceCellTracing.cpp` is complete:
singularity ports / vertices / index / port count (`:5374-5375`, `:5382-5387`, `:5393-5399`, `:9955-9957`);
mandatory edges (`:6137-6139`, `:6230-6232`); and the newly landed digest binding (`:5668-5674`).
`FieldAlignedCandidateTraceSegment` — the sole carrier of `FieldBranch` on the A2a side — is **never read by
A4**. The A2a network's authority over A4 is *mandatory edges and singularities*; trace identity is not part
of that contract and never was.

So the proposed join is between an A2a object A4 does not read and an A4 field A4 mints itself. Freeze as the
**sixth namespace**, beside RA-43.3's four and RA-50.2's fifth: *A2a candidate trace identity is not an A4
segment identity, and no stage converts one into the other.*

Tenth instance of the publish/don't-invent family, and its third structural variant: **do not demand a join
between two namespaces that have no data path, when neither side's consumer reads the quantity absolutely.**

---

## 3. Review B — filled-side provenance has a second, independent closure

RA-50.4 closed the filled side at `src/pipeline/RemeshPipeline.cpp:5003-5004` / `:5008-5012`. There is a
**separate and stronger** closure the stop does not cite, at `:3562-3596`:

- `edge.filledCell` must resolve in `cellById`, `edge.filledSide ∈ [0,4)`, `edge.unfilledSide == 0`;
- `(filledCell, filledSide)` must be **unique** across all front edges (`edgeByCellSide`);
- `edge.sourceTopologyRegion == owner.sourceTopologyRegion`, region resolvable;
- `trace_equal(edge.from, owner.corners[filledSide])` **and** `trace_equal(edge.to,
  owner.corners[(filledSide+1)%4])`;
- `lattice_equal(edge.fromLattice, owner.lattice[filledSide])` **and** the same for `toLattice`;
- `isolation_sheets_connected(...)`.

A wrong `filledSide` cannot survive this: it must index the corner pair whose trace points and lattice states
are bit-equal to the edge's own. **Two independent closures now stand** where the stop asserts none, and
neither is a producer receipt. RA-50.4's "there is no seam" is re-confirmed on bytes RA-50 did not read.

### R4-SID-02 / LATE_DEGENERACY_LOCUS — one real, bounded residue

`:3562-3596` is blind to exactly one configuration: a cell with `corners[0] == corners[2]` **and**
`corners[1] == corners[3]`, where sides 0 and 2 present the identical corner pair. A6's collapsed-edge guard
tests **adjacent** corners only (`:8446-8449`, `a6:collapsed-edge`), so it does not catch it. The case does
die — at A7 materialization, `:7482-7486`, `std::set<int>(certified.vertices).size() != 4U` →
`quad-degenerate`.

So the configuration is **closed, but at the wrong locus**: a side-authority defect surfaces as an A7
geometry degeneracy, three stages downstream of the authority it violates. This is a **diagnostic-locus
finding, not a correctness hole**, and it is not the blocker. A narrow turn may add the opposite-corner
distinctness test at the A5 locus so the first rejection names the right authority. **No new producer, no new
receipt, no new namespace.** If the implementation agent cannot construct a produced cell with equal opposite
corners, it must say so and the finding is recorded as unreachable rather than fixed — the RA-51 discipline.

---

## 4. RA-43.4 — the opt-out is PRESERVED, scoped and census-bound

### 4.1 The census

`rail_interval_refs` has exactly three non-test callers, and **all three pass `RequireTypedSource`
explicitly**:

| caller | network argument | mode |
| --- | --- | --- |
| `src/geometry/SurfaceCellTracing.cpp:10498-10502` | `options.fieldAlignedNetwork` | `RequireTypedSource` |
| `src/geometry/SurfaceCellTracing.cpp:12426-12428` | `options.fieldAlignedNetwork` | `RequireTypedSource` |
| `src/pipeline/RemeshPipeline.cpp:9630-9634` | `nullptr` | `RequireTypedSource` |

The declared default is also `RequireTypedSource`
(`include/directional/geometry/SurfaceCellTracing.h:2497-2510`), so **omission is safe** and the exception
must be *named* to be taken. Inside the function, `fieldAlignedNetwork != nullptr` forces typed vertices and
a published edge list regardless of mode (`:5975-5985`), and `:6137-6147` independently checks mandatory
edge / rail / kind / **component** against the network record.

### 4.2 The decision: keep it

**Removing the opt-out would make the network-override claim vacuous.** The Phase10 negative
(`tests/SurfaceCellsPhase10Tests.cpp:6502-6595`,
`StandaloneRailDiagnosticModeCannotBypassProducedNetworkTypedIngress`) is the only artifact that shows the
override is load-bearing, and it can only be authored *through* the opt-out: a guard is demonstrably live
only if something can attempt the bypass it refuses. This is the guard-coupled-retirement principle
(RA-46.3, RA-48.1's G1–G4, RA-49.6, RA-51.3's H1–H6, RA-51.4's K1–K5) read **forward**: a retained guard
needs a retained attempt.

**Add no machinery.** No tag type, no builder, no attribute, no separate header. The named-mode migration
already converted the hazard from an unnamed trailing `false` into an exception that announces itself in
source, which was RA-43.4's entire purpose. Adding confinement scaffolding now would be speculative
hardening against a bypass nobody has exhibited — the stop itself says so, and it is right.

**The standing obligation is a one-line census, not code:** whenever a `rail_interval_refs` caller is added,
removed or has its mode changed, the turn's record must restate the table in §4.1. If a production caller
ever appears with `LegacyStandaloneDiagnostic`, that is a REVIEW_BLOCKER on sight.

**RA-43.4 is now narrowed to its true residue:** the *other* untyped standalone geometry diagnostics beyond
`rail_interval_refs`. The mode migration did not dispose of those and did not claim to.

---

## 5. Comment / code scope mismatch at the landed carrier cut

`src/geometry/SurfaceCellTracing.cpp:1457-1459` reads "the terminal germ is a connected component of the
vertex star after cutting **certified incident hard-rail carriers**." The code at `:1460-1467` cuts **every**
`FieldTransportBarrierKind::HardFeature` barrier incident to the vertex, whether or not it carries the route
under construction.

**The code is correct and the comment is narrower than it.** A3 transport cannot cross a hard feature at all,
so every hard feature is a genuine barrier to the germ; cutting only the route's own carriers would produce a
germ the field cannot actually traverse. The hazard is that a future reader "repairs" the code to match the
comment and silently widens the germ. One-line comment correction; **no behaviour change**, and the fix must
not touch the `continue`.

---

## 6. Credit: what landed and verified since RA-51

Verified against bytes, not against the agent's reports:

- **RA-49.2's duplicated-endpoint witness is AUTHORED and correctly shaped.**
  `tests/SurfaceCellsPhase10Tests.cpp:7061-7095`
  (`DuplicateSourceTerminalContactRejectsAtFirstA4ConsumerPredicate`) takes the **actual** produced
  `firstRoute.endpoints[0].terminalVertex`, asserts it is genuinely one of the contact endpoints, sets
  `contact->second.endpoints = {vertex, vertex}`, and requires rejection at
  `a2bProbeFailure=ambiguous-terminal-contact` with an `EXPECT_EQ(npos, ...)` excluding
  `no-exact-terminal-corner`. That is exactly the specified shape, including the negative anti-assertion.
  **Compiled, not executed.**
- **RA-46.9 landed:** `src/geometry/SurfaceCellTracing.cpp:18848-18857` fails closed with
  `firstPredicate=missing-hard-feature-source-incidence` instead of throwing.
- **RA-43.1's carrier cut landed** (§1).
- **Two new first-consumer component guards landed**, both correctly placed *before* the checked factory:
  `closed-rail-component-mismatch` and `terminal-contact-component-mismatch`, each requiring the claimed
  component to equal `component_for_row` of **both** actual attachments; plus closed-chain simplicity
  (`closed-rail-chain-not-simple`), carrier ownership (`closed-rail-endpoint-edge-not-owned`) and all-hard
  cyclic edges (`closed-rail-chain-non-hard-edge`). These close a real gap: a closed-chain token previously
  substituted for a terminal contact without proving the chain owns the endpoint carrier.
- **`field_aligned_network_binding_valid` landed** (`:5666-5676`, gated at `:18800-18807`): the network's
  `source_digest`/`atlas_digest` must match the supplied atlas. The comment is right that equal network
  semantics do not imply equal atlas provenance.
- **`append_edge_interval` is no longer architecturally inert.** `src/pipeline/RemeshPipeline.cpp` now
  re-derives source components from shared-edge face connectivity independently of all feature-map metadata,
  and rejects alias records, nonmanifold (`>2`) claimed incidence and boundary-class edges with other than
  one face. Previously it took the first in-range `incidentFaces` row on trust.

### R4-JCT-01 — the multi-carrier junction witness is AUTHORED, not executed

`tests/SurfaceCellREPackageTests.cpp` now asserts `EXPECT_GT(authenticatedJunctions, 0U)` with
"this fixture must reach an actual produced multi-carrier junction", alongside
`EXPECT_GT(authenticatedContactSteps, 0U)` and `EXPECT_GT(authenticatedJunctionSteps, 0U)`, over
`certificate.junctions` of a **produced** phase front, and checks A1's commuting square on each junction
step. These are real non-vacuity guards on the previously-empty loop.

**Status moves from UNEXERCISED to AUTHORED / COMPILED / NOT EXECUTED.** RA-41's junction and sector clauses
stay **frozen UNEXERCISED** at runtime. No runtime credit accrues from a compile (LESSONS 160). The witness
is only discharged when that `EXPECT_GT` is **observed** to pass in an authorized Test + Benchmark turn.

The stop's own evidentiary reading of `:736-766` is **accurate**: the loop over `frame->branches` establishes
*existence* of an admitting germ, not *selection*. That reading is correct and is the reason it cannot be
used as a selected-branch join — but per §2 no such join is owed, so the observation closes the question
rather than opening one.

---

## 7. Disposition

- **REVIEW_BLOCKER DISSOLVED.** Options (A) and (B) both REFUSED. RA-43.2 stays DISCHARGED; RA-43.1's carrier
  cut is LANDED; no selected-branch receipt is owed or permitted.
- **RA-43.4: opt-out PRESERVED, scoped, census-bound.** Residue narrowed to the non-`rail_interval_refs`
  standalone geometry diagnostics.
- **One new bounded finding:** `R4-SID-02 / LATE_DEGENERACY_LOCUS`, A5 locus repair, reachability to be
  established first.
- **One comment correction** at `:1457-1459`.
- **No credit.** No runtime. No ledger movement. No selector mutation. `review_check.py boundary` must pass.
