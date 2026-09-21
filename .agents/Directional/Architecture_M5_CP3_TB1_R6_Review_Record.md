# M5-CP3-TB1-R6 Independent Review Record

**Turn:** `M5-CP3-TB1-R6-REV`
**Boundary:** **runtime-free independent Review**
**Verdict:** **R6 EVIDENCE UPHELD / CAUSE PROVED / EXISTING `RP-01` RECURRENCE / CB8 CORRECTION FROZEN**
**Exact successor:** `M5-CP3-CB8`

## 1. Reviewed authority and independent evidence

Review re-opened the R6 execution authority rather than accepting the execution report as self-proving.
The immutable runtime subject is CB7 candidate artifact `10637998372` / packaged source
`8f77ec403f16930145bba5bfc526a5b881b9f166`. Its package ZIP SHA-256 is
`1c92e42939081ec9f041f72e916c99d80a700b39a61e3917e8cf8830c5a3f98f`; root `SHA256SUMS` is 28 rows at
`1b0bc0b8ce4ff0c339659c7f7c5c3c4e9e26143d352424f7aecf1a2b8f91f737` and verifies **28/28**; packaged source
archive SHA-256 is `dbc083059b4dbd8ea7b429ca32819ce8a91b179b5e2cbd6201a66113d37a9163`.

R6 run/job `35606326632 / 106354249393` published result/log artifacts `10642347642 / 10642362744` at exact
SHA-256 `d23863aa7725b4f82e5a3ee7992c910a2f24bf32252b05260046836ca0470bfc /
6f02d669521bf5c0d1821e656948950b549c6c697ea1a28325cbee1d20f9dcff`. Review independently verifies the
result self-manifest at SHA-256 `2130e816714231ea5dfe8cae74f297d0d9ad5b6e21f91c5ce600bf46d4fecb15`, **914/914** entries.

The complete ledger is re-derived as **446/446** exact-filter processes with selected count exactly one and
skip count zero for every row:

| Gate | PASS | RED | Review result |
|---|---:|---:|---|
| reviewed mechanism | 9/9 | 0 | upheld |
| focused atlas | 1/1 | 0 | upheld |
| produced torus | 0/6 | 6 | upheld |
| selector430 | 429/430 | 1 | sole RED ordinal408 |

Benchmark/configure/compile/relink/generated-discovery/package-repair/mode-repair/source-test-fixture-selector-
mutation counters are all zero. Package, packaged-source and execution-view byte+mode censuses are identical
before/after. Selector430 remains 430 LF rows at
`1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`; exact first427 remains
`f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`. Accepted routing identity map remains
`7a92e7a3b8a69466423c4a0d2ad5ece2dcd4912f04eeb99e1f32fa70b4a5cf6c`.

The Review's repository/source snapshot is run/job `35609898844 / 106366168569`, artifact `10643362315`, exact
snapshot/event source `5461c0d4bacf038591f6f28bbaba61dbb7054f5b`, artifact SHA-256
`6204d493b3628f14361f9b2db1152d4df2fe6581cc033a2706cb1addcf9a3d3c`, source-archive SHA-256
`0499fefe092d89d3c89206e26847e29b534de6b183977eed263baf7c2eb13dce`, `runtimeExecution=false`.

## 2. R6 branch localization is exact and non-vacuous

Every one of the six produced rows is a real RED with exact phase-front reason
`PeriodicGeneratorRouteUnavailable`. None reports `PeriodicActionCorrespondenceMismatch`,
`PeriodicHolonomyZeroTranslation`, `PeriodicHolonomyMissingGeneratorRoute`,
`PeriodicHolonomyMissingCutRoute`, or `PeriodicHolonomyInvalidRelationIdentity`. Thus the CB7 diagnostic split
actually distinguishes the pre-committed alternatives: deleting or bypassing the generator-route guard would
change the observed branch. This is not a vacuous label-only result.

The R5 accepted-row hazard is independently falsified. Selector ordinals **191, 192 and 247** all remain PASS
under their byte-frozen generic `PeriodicHolonomyMismatch` expectations. No additional accepted selector row
regresses beyond the already-open ordinal408 event. `M5-CP3-TB1-R5-REV-OBS-01-A` therefore closes
**RUNTIME GREEN / NON-STABLE / +0**.

## 3. Independent source-authority proof

R6 supplies the dynamic branch. Repository bytes then make the authority mismatch causal rather than merely
plausible.

### 3.1 The A3 accepted cut already owns the exact incident source face

`SurfaceCellTracing.cpp` constructs `AcceptedCutBoundarySegment` with an exact `SourceFaceId sourceFace`. For
each oriented `GlobalTopologyArc` source piece it resolves the exact `SourceEdgeSupport`, scans only the
carrier edge's incident active faces, requires the triangle edge orientation to match the oriented source-path
vertices, rejects ambiguity, and records the unique `owningFace` (`AcceptedCutBoundarySegment` construction,
roughly lines 13780 and 13871-13980 in the reviewed snapshot).

The accepted segment is preserved into `boundaryAcceptedSegments` and `runAcceptedSegments`. Its exact
conformity incidence becomes `SurfaceBoundaryOccurrenceId{region, canonicalBoundaryOccurrenceOrdinal}` before
A4 boundary subdivision. Therefore the producer already has a checked mapping from an exact A3 boundary
occurrence and carrier to the source face that owns that oriented occurrence.

### 3.2 `SurfaceSharedBoundaryInterval` preserves the occurrence but drops that face authority

When A4 subdivides an accepted hard-feature boundary it publishes `SurfaceSharedBoundaryInterval` containing
span, exact ordinal endpoints, orientation and `boundaryOccurrence`, but not the accepted segment's
`sourceFace`. Meanwhile `append_point(parameter, run.sourceFaces[edgeIndex])` creates `SurfaceTracePoint`
representation geometry. If the next point lands at the same UV as the previously emitted endpoint,
`append_point` returns without replacing the existing point. The surviving `.face` is consequently the face of
whichever segment inserted that representation point first, not an exact statement that the point's face owns
every later incident carrier.

This distinction matters precisely at a cut/boundary junction: a geometric endpoint may be shared by adjacent
source-edge segments while each segment has its own checked owning face. `SurfaceTracePoint::face` is valid
representation provenance but not stable carrier-incidence authority for a different edge.

### 3.3 Same-region promotion substitutes A4 endpoint provenance for A3 carrier incidence

The same-region pairing gate correctly requires two distinct exact `boundaryOccurrence` values and reciprocal
interval/span/ordinal/orientation/route conditions. It then calls:

`generator_route_for_span(first.sharedBoundaryInterval->span, first.from.face, second.to.face)`.

`generator_route_for_span` correctly resolves the exact `Mandatory` `GlobalTopologyArc::sourcePath`, requires one
canonical source piece, recovers its `SourceEdgeSupport`, exact edge parameters and interior transition identity.
But it passes those A4 endpoint face integers to `FieldTransportAtlas::transition_value(carrier->edge, from, to)`.
The exact occurrence authority established above is no longer used.

### 3.4 The atlas query is deliberately exact about the face pair

`FieldTransportAtlas::make` validates the raw interior-edge transition and publishes one
`FieldTransportTransitionValue` **before** hard-feature/nontraversable classification. A hard-feature edge retains
that semantic transition value and is then omitted from traversal adjacency, preserving frozen §15.
`FieldTransportAtlas::transition_value` finds the exact carrier edge and returns a directed value only when the
supplied two `SourceFaceId`s equal the value's exact `firstFace/secondFace` pair in forward or reverse order.
Any unrelated A4 endpoint provenance therefore returns `nullopt` by design.

This proves the failure is not missing atlas semantic value and does not justify making the hard feature
traversable.

## 4. Causal adjudication

`M5-CP3-TB1-R5-REV-OBS-01` is **CAUSE PROVED / IMPLEMENTATION AUTHORITY / EXISTING `RP-01
AUTHORITY_DOMAIN_CONFLATION` CONTINUATION / +0**.

The causal chain is bounded by facts already established before the failing call:

1. R6 dynamically proves all six witnesses stop at generator-route unavailability before action correspondence
   or holonomy construction.
2. The exact span is `Mandatory`, canonical and single-piece on this path; the current helper gets far enough to
   request atlas transition value only after validating those properties, carrier edge parameters and transition
   identity.
3. The accepted A3 cut construction already derives a unique directed occurrence-owning source face for the exact
   carrier and fails closed on absence/ambiguity.
4. The atlas has a validated transition value for every interior edge, including hard-feature edges, before it
   withholds traversal adjacency; R5's focused value-without-adjacency control is green.
5. The remaining query input is the directed face pair. Current code sources it from A4 endpoint points whose
   deduplication contract does not preserve per-carrier ownership; atlas lookup requires the exact carrier incident
   pair. That domain substitution is sufficient to explain the observed `nullopt` and is the only surviving
   authority mismatch at the active first-failure boundary.

The correction must therefore restore the already-owned occurrence/carrier incidence authority. It must **not**
choose `sourceEdgeFaces[edge][0/1]` as a directed order: that container proves membership of the two incident
faces but its storage ordering is not the semantic direction of the selected reciprocal occurrences.

## 5. Bounded correction frozen for `M5-CP3-CB8`

Exactly one runtime-free Code + Build correction is authorized by
`Architecture_M5_CP3_CB8_Source_Face_Incidence_Authority_Correction_Plan.md`.

The only semantic source path is `src/geometry/SurfaceCellTracing.cpp`. Reuse the accepted-cut facts already
computed there to resolve each reciprocal interval's exact occurrence-owning `SourceFaceId`; bind that resolution
to the interval's exact span and generator carrier; prove the two directed faces are distinct and exactly the
carrier edge's two incident source faces; then pass that directed pair to atlas `transition_value(...)`.
`sourceEdgeFaces` may validate set membership only. The generator route must no longer use
`SurfaceTracePoint::face` / `first.from.face` / `second.to.face` as transition-incidence authority.

No change is authorized to tests, fixtures, selector430, frozen definitions, `FieldTransportAtlas` API or
implementation, traversability/barriers, generator path identity, action correspondence mathematics, checked
relation construction, diagnostic reason values, or publication/debt semantics.

A successful compile/package routes to fresh artifact-only `M5-CP3-TB1-R7-EXEC` on the unchanged **446-process**
gate. Its pre-committed primary falsifier is exact: **none of the six produced rows may still report
`PeriodicGeneratorRouteUnavailable`**. Any later typed RED is evidence for mandatory Review, not permission for a
same-turn repair. Full recovery requires 9/9 mechanism, 1/1 focused atlas, 6/6 produced and selector430 430/430
with immutable postflight; even that remains unpromoted until R7 Review.

## 6. Accounting, promotion and carried observations

R6 does not create a new accepted-green loss. Ordinal408 is the same accepted-prefix PASS→RED event recorded at
R1 and has not recovered on a promoted candidate. Classification stays within existing stable
`RP-01 / AUTHORITY_DOMAIN_CONFLATION`: **+0 events / +0 categories / +0 recurrences**. Stable totals remain
**50 events / 14 categories / 36 recurrences**, produced-witness debt **5**.

Candidate `10637998372` remains unpromoted. Accepted runtime authority remains package/source
`10601978228 / 0798547dedd8be05f9cd7a096b07e6bd94755316` under selector430 **430/430**. All four M5 produced debts
remain open and selector publication remains prohibited.

Prior obligations:

- `M5-CP3-TB1-R5-REV-OBS-01` — **DISCHARGED AS OBSERVATION / CAUSE PROVED**, correction owner CB8.
- `M5-CP3-TB1-R5-REV-OBS-01-A` — **CLOSED / RUNTIME GREEN / NON-STABLE / +0**; ordinals 191/192/247 remain green.
- `M5-CP3-TB1-R2-REV-OBS-01` — **CARRIED** to the first corrected green post-CB8 Review. R6 proves the consumer
  reaches atlas transition-value lookup, but successful consumption and produced relation publication remain
  unproved until the corrected path is green.
- `M5-CP2-TB1-REV-OBS-01` — **CARRIED** to the first independently green corrected CP3 pre-publication Review.
- `M5-CP3-TB1-REV-OBS-01` — standing exact digest/provenance process rule, satisfied here.
- `M5-CP3-TB1-R3-REV-OBS-01` and `M5-CP3-TB1-R4-REV-OBS-01` remain discharged by frozen §15 / R5 recovery.

Frozen §§14-15 already require exact A3 carrier authority, distinguish semantic transition value from traversal
adjacency, and preserve hard-feature barriers. The R6 finding is an implementation consumption error, not a false
normative definition. **No frozen-definition amendment is required.** No selector manifest change is required
because no selector is added or accepted. No new `LESSONS.md` item is required; this is another concrete instance
of existing single-authority / `RP-01` guidance.

## 7. Consolidation disposition

This Review retains one current document per M5-CP3 role: the R6 runtime report, this R6 Review, and the CB8 plan.
Superseded R4/R5 reports and reviews plus consumed CB6/CB7/R6 plans/reports are folded into
`M5_Consolidated_Record.md` with exact filenames and line counts before deletion. Durable facts, regression IDs,
artifact identities, open observations and normative §§14-15 remain in retained records. The byte-frozen selector
files and frozen definitions are untouched.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | selector430 `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`; first427 `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f` |
| Decisive claims independently re-derived | R6 result outer hash, 914/914 self-manifest, all 446 exact-one/zero-skip rows, 9/1/0-of-6/429-of-430 vector, six exact generator-route reasons, protected-row results, immutable postflight, and source authority chain |
| Non-vacuity checked | CB7's six alternatives were observable; all six selected generator-route failure while later branches did not; accepted hazard rows could have regressed but 191/192/247 stayed green |
| Prior obligations discharged/carried | R5-REV-OBS-01 cause proved -> CB8; R5-REV-OBS-01-A closed green; R2-REV-OBS-01 and CP2 publication observation carried; R3/R4 observations remain discharged |
| Stable accounting | 50 events / 14 categories / 36 recurrences; debt 5; accepted package `10601978228`, selector430 430/430 |
| New candidates/obligations recorded | R6 Review cause-proof entry recorded in tracker; no new stable event; CB8/R7 falsifier recorded |
| ORIENTATION currency line | `M5-CP3-TB1-R6-REV`, 2026-09-21 UTC |
| ORIENTATION §3 / §4 / §7 / §8 | updated current authority, torus witness, priority list and the point-provenance-vs-carrier-incidence RP-01 instance; superseded R6-next bullets replaced |
| CHANGELOG | R6 Review entry added to durable `.agents/Directional/CHANGELOG.md` |
| ROADMAP | M5-CP3 moved to R6 Review cause-proved / CB8 next |
| Selector manifest | n/a — no selector added, changed or accepted |
| LESSONS | existing single-authority / RP-01 and non-vacuity rules apply; no genuinely new pattern |
| Consolidation under CLEAN_UP_POLICY | eight superseded M5-CP3 per-turn documents folded/indexed; retained R6 runtime report + R6 Review + CB8 plan + consolidated/frozen/selector authority |
| Successor frozen | exactly `M5-CP3-CB8`; falsifiers and stop rules are in `Architecture_M5_CP3_CB8_Source_Face_Incidence_Authority_Correction_Plan.md` |
| Turn boundary held | runtime-free Review; no product/test/fixture/selector/build source mutation |
| review_check.py boundary | must PASS on the final documentation/consolidation worktree before publication |
| `STATUS` lifecycle maintained | entry/resume beacon maintained; terminal COMPLETE beacon with successor `M5-CP3-CB8` is the final repository write after durable docs and cleanup |
| Pushed to origin, branch in sync | closeout patch push and post-push branch authority are verified before terminal beacon; no local semantic branch is retained |

---

## Independent verification addendum (reviewing agent)

Runtime-free. **Upheld.** The branch localization is real, the causal chain re-derives from bytes, and the R5
accepted-row hazard closed cleanly. Accounting holds at **50 events / 14 categories / 36 recurrences**, debt
**5**. One narrow gap in the successor's falsifiers is recorded.

### V1 — the instrumentation strategy is vindicated

Five semantic edits chosen from static plausibility failed dynamically. One turn of diagnostics produced a
dynamically-confirmed root cause. That is the payoff of the rule R5 froze — **no semantic edit without dynamic
branch evidence** — and it repaid the turn it cost.

The result is also non-vacuous, which is the check that matters for instrumentation: §2 establishes that the new
reasons actually discriminate, since bypassing the generator-route guard would change the observed branch. I
confirmed the mechanism at the source: `src/geometry/SurfaceCellTracing.cpp:17170` sets
`SurfacePhaseFrontFailureReason::PeriodicGeneratorRouteUnavailable` on the rejection path, so branch 1 is
identified by a code that only that branch produces — not by a relabelled collapse.

### V2 — the causal chain is exact

All three links verified:

- **The call passes A4 front endpoint faces.** `:17164-17165` reads
  `generator_route_for_span(first.sharedBoundaryInterval->span, first.from.face, second.to.face)`.
- **The interval cannot supply the carrier's faces.** `SurfaceSharedBoundaryInterval`
  (`include/directional/geometry/SurfaceCellTracing.h:1414-1423`) carries `authority::NetworkArcId span` and
  `std::optional<SurfaceBoundaryOccurrenceId> boundaryOccurrence` — and **no face fields at all**. §3.2's reading
  is precisely right: the occurrence is preserved, the face authority is dropped.
- **So the substitution is unavoidable at that call**, and at a cut/boundary junction the A4 front endpoint faces
  need not be the A3 carrier's incident faces. The route lookup then finds nothing and the phase front is
  `Rejected`.

This is the first root cause in six attempts resting on runtime branch evidence rather than static plausibility,
and the static bytes corroborate it rather than merely permitting it.

### V3 — the R5 accepted-row hazard closed exactly as flagged

`M5-CP3-TB1-R5-REV-OBS-01-A` warned that CB7's vocabulary change could break three accepted rows that assert
`PeriodicHolonomyMismatch` verbatim. Verified by ordinal: **191**
`…MalformedAuthoritativeCrossingProvenanceFailsClosed`, **192**
`…NonzeroNetCycleFailsClosedAtPeriodicHolonomyGuard`, **247**
`SurfaceCellsPhase10.PeriodicPhaseFrontMalformedHolonomyFailsClosedWithTypedReason` — exactly the three
identities named at R5, and all three remain **PASS**. selector430 is **429/1** with ordinal 408 the sole RED.
The hazard was real, was flagged before CB7 ran, and was handled; the observation closes.

### V4 — the successor checks membership but not direction

`M5-CP3-CB8`'s plan is unusually well constructed on the point that matters most. It separates the two questions
that the face pair actually poses: it resolves both directed occurrence-owning faces from
`AcceptedCutBoundarySegment::sourceFace` authority derived from the exact oriented A3; forbids reading a directed
face from `SurfaceTracePoint::face`, `SurfaceFrontEdge::{from,to}.face`, insertion order, UV deduplication or
region-wide search; requires the two resolved faces to be distinct and, **as an unordered pair**, to equal exactly
the carrier's two faces; and states plainly that `sourceEdgeFaces[edge][0/1]` storage order must never be used to
invent the directed query order. That is the right decomposition — membership and direction are different
claims — and it forecloses the obvious way this correction could go wrong.

The gap is narrow and worth naming. The plan supplies a **membership** falsifier (unordered-pair equality) but no
**direction** falsifier. Direction is exactly where an error would not announce itself: the transition value is
directed (`FieldDirectedTransitionValue`), so an inverted face order still passes unordered-pair equality, still
resolves a route, and yields a relation whose action is mirrored. That would convert today's clean fail-closed
rejection into a plausible wrong answer — strictly worse than the current state, and the hardest kind of defect
to detect later.

**Required of CB8 and reported by R7:** the produced relation's action must be checked against an expectation
derived independently of the face order that produced it — reciprocity under §14.2's canonical-reverse/opposing-
advance-sign rule is the natural instrument — so that an inverted orientation **fails** rather than silently
producing a mirrored relation. R7 must report, for the six produced identities, that the resolved directed pair
and the resulting action agree with independently derived A3 orientation. Recorded as
`M5-CP3-TB1-R6-REV-OBS-01`.

### V5 — accounting and verification limits

R6 is correctly another continuation of the ordinal-408 event first priced at R1: it has never returned to
accepted green on a promoted candidate, so a further diagnostic turn creates no new event. Selector430 remains
430 LF rows at `1c412850…9db6`; the candidate is unpromoted; all four M5 produced debts remain **OPEN** with zero
credit, and `M5-CP2-TB1-REV-OBS-01` stays carried since no publication identity is green.

Re-derived from repository bytes: the `generator_route_for_span` call arguments, `SurfaceSharedBoundaryInterval`'s
field set, the `PeriodicGeneratorRouteUnavailable` rejection site, selector ordinals 191/192/247 and their PASS
status implied by the sole-RED tally, and selector430's rows and hash. Accepted as reported: R6 artifact hashes,
ledger tallies, raw-log digests and execution-boundary receipts.
