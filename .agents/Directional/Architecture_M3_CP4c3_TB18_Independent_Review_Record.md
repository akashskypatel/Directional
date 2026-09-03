# M3 CP4c-3 TB18 — Independent Review + Plan Record

Date: 2026-09-03 UTC
Turn: `M3-CP4c-3-TB18-REV`
Type: **independent REVIEW + PLAN — STATIC ONLY**
Status: **COMPLETE / INVARIANT FALSIFIED WITH MEASURED MECHANISM / PRODUCT CORRECTION AUTHORIZED / NON-STABLE**

No Directional runtime, configure, compile, link, package, benchmark, or product/test/fixture/selector mutation
occurred in this turn. Every claim below is derived from committed bytes, from the immutable TB18 evidence, or from a
stated theorem about the construction the code performs.

Measures discharged: **BT0–BT9**. Successor frozen: exactly one — **`M3-CP4c-3-CB21`** under **BU0–BU9**.

---

## 1. BT0 — evidence authority and immutability

| Check | Result |
|---|---|
| Semantic/evidence source `57635e87306a416daabb8321e1f36fa9c788d208` exists | **PASS** |
| Source is an ancestor of branch HEAD | **PASS** |
| No code drift `source..HEAD` | **PASS** — static review of the working tree is valid evidence about the package |
| Selector 383 recomputes to `a7fe57cc47c5035414a82f02f044a911f9c430f90d11f1bd3ef1bca76f3a4b2c` | **PASS**, 383 identities |
| Selector 382 is an exact 382-line prefix of 383 | **PASS**, prefix digest `f30d5d56…50d665a1a` |
| Selector 383 appends exactly one identity | **PASS** — ordinal 383 `GlobalTopologyPlan.TraceCutFaceFragmentMismatchDiagnosticsSurviveProductionFailureProjection` |
| Accepted 365-prefix authority | **PASS** — `6b5b6555…cfc14b8a1`, unchanged |
| Pre/post package byte+mode census | **IDENTICAL**, `5fb1dcf5…bbedb350eb8` |

Verified with `.agents/Directional/tools/review_check.py authority` and `selector_probe.py {hash,prefix,ordinal}`
against LF-normalized bytes.

**Attempt-1 orchestration revision is accepted as an orchestration event, not a semantic one.** Run
`33784755615 / 100746771952` executed ordinals 1–39 PASS and stopped before ordinal 40 on a temporary owner-map
omission. The corrected runner verified attempt 1's artifact and per-ordinal log hashes, copied the completed
results forward, resumed at ordinal 40, and recorded `rerun_completed_ordinals=false`. **No completed identity was
re-executed in search of a different result.** That is the correct handling under the turn workflow's orchestration
clause, and it is the second consecutive turn where an orchestration defect was disclosed rather than absorbed.

**No rerun is authorized by this review.**

---

## 2. BT1 — independently owned facts preserved

Carried forward unchanged, each owned by a prior turn and not reopened here:

- **CB19:** the `(9,11,17)` `RegionTraceSourcePortCarrierNotAdmissible` stop is cleared; **48** non-first
  carrier-less segments exist and all 48 have entry support distinct from the trace origin; the positive witness
  uses `SegmentEntrySupport`; there are **10 terminal slits**; the retained terminal witness has
  `realChordContribution = 0`.
- **Terminal slits contribute zero to `k`** and publish no orbit evidence — excluded consistently from both sides of
  the fragment comparison.
- **CB12 / CB14 / CB15 / CB16 / CB17 / CB18 / CB19 / CB20 corrections stand.** No successor may revert them.
- Carried red surfaces are unchanged and independently owned: **368** prescribed sphere
  (`RotationSystemInconsistent → TraceEventPositionInvalid`, trace 2 / event 30, `NoCarrierMatch /
  SourceEdgeUnavailable`), **369** saturation, **370** `CellularityNotEstablished` with no source-face locus,
  **374** folded-cone `atlasBuild=false`. **367 / 371 / 372** co-reach the fragment mismatch.
- **There is still no vertex-30 discriminator.** Vertex 30 is still not reached.
- The finalize/contact fall-through (`terminalContact` never read in `finalize_field_aligned_events`) remains open
  under its own owner.

---

## 3. BT2 — what TB18 actually measured

CB20 discharged BS1–BS4 as specified and TB18 executed the frozen plan. Ordinal 366 is unmoved —
`TraceCutFaceFragmentCountMismatch` at source face `(0,1,102)` — which is the required proof that CB20's BS7
no-semantic-change boundary held. The retained typed failure now carries the deciding values:

| Quantity | Value |
|---|---|
| `fragmentOrbitCount` (actual) | **1** |
| `tracePieceCount` (`k`) | **1** |
| `expectedFragmentCount` (`k+1`) | **2** |
| Direction | **`actual < expected`, low by exactly 1** |
| `fragmentIncidenceCount` | **1**, `fragmentIncidencesTruncated = false` |

The single retained incidence, complete:

```
trace=1  arc=15  segment=4  orientation=Forward
incomingCarrier=none   outgoingCarrier=0-102
forwardOrbit=0         reverseOrbit=0
forwardExteriorDropped=false   reverseExteriorDropped=false
```

Edge-orbit evidence for the failing face, all three rows present and untruncated: edges `1-102`, `0-1` and `0-102`
each have `totalOrbitCount = 1`, `orbits = [0]`.

**Of the three mechanisms TB17-REV enumerated, TB18 selects one and eliminates one.**

- **Exterior filtering: ELIMINATED for this witness.** Both drop flags are `false`. `add_fragment_orbit` discarded
  nothing here.
- **High side (non-collapsing sides / duplicated orbit evidence): ELIMINATED for this witness.** The failure is low,
  not high.
- **Shared global owner: SELECTED.** The two oriented sides of one real chord carry the same global face-walk orbit
  id `0`.

TB17-REV rated shared-global-owner the *least* likely of the three. That estimate was wrong, and the estimate was
never load-bearing: the turn was correctly frozen as diagnostic-only precisely because the mechanism could not be
ranked from committed bytes. **Recorded as a calibration fact, not as a defect in that adjudication.**

---

## 4. BT3 — the incidence is a vertex transit through a regular vertex

Two facts pin what the incidence is, without any runtime.

1. **It is not the trace's origin.** `arc.firstSegment … arc.onePastLastSegment` index directly into
   `trace->segments`, so `segment = 4` is the trace's global segment index. A trace's port origin is segment 0.
   Segment 4 is therefore one of the **48 non-first carrier-less segments** CB19 classified — an Amendment 3
   `VertexHit` transit, entering the face at a corner rather than across an edge.
2. **The corner is vertex 1, and vertex 1 is regular.** The carrier-less branch of the region loop
   (`GlobalTopologyPlan.cpp:740–765`) requires `outgoing == (sourceCorner + 1) % 3`, the edge **opposite** the bound
   corner. The outgoing carrier is `0-102`; the corner of face `(0,1,102)` not on `0-102` is **vertex 1**.
   `fixture_probe.py vertex 1` on `mechanical_feature` gives degree **6**, angle defect **−0.000000000** — a flat,
   regular vertex carrying two 90° sharp edges (`0-1` shared by rows 0/259, `1-4` shared by rows 2/269).

So the chord runs corner-to-opposite-edge across the triangle. **Locally it separates the triangle into two
pieces.** Those two pieces are nevertheless owned by one global orbit. That is the whole finding.

---

## 5. BT4 — the shared owner is correct, and the check is unsound by construction

This is the adjudication the turn exists to make: is the shared owner a *defect in orbit construction*, or a
*legitimate configuration the check cannot represent*?

**The face-walk is the standard face permutation of the rotation system.**
`EmbeddedGraphTopology.cpp:1698–1775` builds `successor[dart_index(reversed(incidence))] =
dart_index(rotation.counterClockwise[(index + count − 1) % count])` — the canonical `φ = σ⁻¹ ∘ α` construction —
and then validates it hard before use: every dart has incidence count exactly 1, every successor is assigned, every
orbit closes within the dart budget, and no orbit is re-entered at a dart other than its start
(`FaceWalkOrbitReenteredAtDifferentStart`). It is a total permutation of darts and its cycles are its orbits.

**Consequence.** For a graph embedded by a rotation system, the two darts of one arc lie in the same face orbit
exactly when that arc lies on no cycle of the graph (a bridge) **or** the arc is non-separating in the embedding —
the ordinary torus loop being the standard example of the second case. Both cases are legitimate. Neither is
reachable by a "merge" error: `orbitByDart` cannot fuse two darts that a valid rotation system separates, because
the orbits are the cycles of a validated permutation.

**Therefore `|owners| = k + 1` is not an invariant of any valid input.** The correct relation is

> `|distinct global orbit owners of a face's fragments| ≤ (local fragment count)`,

with strict inequality whenever any incident chord is a bridge or non-separating, and further strictness whenever
`add_fragment_orbit` drops an exterior orbit. `k + 1` is a statement about the *interior of one triangle*;
`|std::set<orbit id>|` is a statement about the *whole surface*. The code equates them, and nothing anywhere
establishes the injectivity that equation requires.

**The residual reading is eliminated, not merely disfavoured.** The only surviving way the shared owner could be a
defect is that the *rotation system itself* is wrong at this arc's endpoints. That reading is unsupported — the
rotation system is exercised by all 365 accepted identities and by every upstream validation in the same
function — but more decisively, **it is irrelevant to this check's disposition**: a validation that cannot
distinguish a legitimate topology from a defective one has no diagnostic value at either outcome. It is replaced,
not tuned. If a rotation defect exists it must be detected by a check that can actually name it, and CB21 retains
the evidence that would name it.

**This closes `M3-CP4c3-TB17-CAND-01`'s owner question.** The owner is the check itself: a **local-fragment versus
global-owner representation defect** in `build_regions`, at the comparison and nowhere else.

### Why the deficit is exactly 1 here, and what that predicts

A pendant end anywhere on a trace makes every arc of that trace's path a bridge, and therefore makes both sides of
every chord that trace cuts share one owner. The mechanical witness has **10 terminal slits** — 10 pendant ends. The
observed face has one chord and a deficit of exactly one. **Prediction, to be confirmed by CB21's census and not
relied on before it: the per-face deficit equals the number of that face's chords lying on pendant or
non-separating arcs.** No corrective measure below depends on this prediction being true.

### The recurring class, fifth instance

The terminal-slit exclusion at `GlobalTopologyPlan.cpp:688–695` is *correct*: the last segment of a trace
materializes no chord. Its own comment then generalizes that local fact into a global one — "A face with k real
trace chords has exactly k+1 fragments." What the terminal slit actually establishes is a property of the **whole
trace** (it has a free end, so it separates nothing globally), not a property of the **one segment** that was
skipped. The exclusion removes the last segment from `k` and leaves the preceding chords of the same dangling trace
counted as if they separated. This is the same defect class as lessons 85, 87, 93 and 96: **a value correct in the
scope that produced it, used in a scope that does not make it valid.**

---

## 6. BT5 — disposition of BS9-5, the missing `fragment_reconciliation` record

TB18 correctly reported BS9-5 as **FAIL / diagnostic insufficiency** and correctly refused to rerun with a changed
environment. This review determines the cause and disposes of the measure.

**Cause, proved statically.** CB20 implemented BS4 exactly as BS4 was written — the record is emitted before the
early return *"when diagnostics are enabled."* Diagnostics are enabled by
`GlobalTopologyPlan.cpp:81–84`:

```cpp
bool fragment_diagnostics_enabled() noexcept {
  const char *value = std::getenv("DIRECTIONAL_CP4AB_FRAGMENT_DIAGNOSTICS");
  return value != nullptr && std::strcmp(value, "1") == 0;
}
```

and the pointer is null otherwise (`:1814–1816`). The artifact-only selector runner sets no such variable and is
forbidden from setting one. **The record was unreachable in TB18 by construction, and no turn between BS4 and BS9-5
was ever asked to make it reachable.**

**The measure was defective, and its failure is evidentially vacuous.** The record prints exactly three fields —
`fragment_orbit_count`, `trace_piece_count`, `expected_fragment_count`. All three are precisely the typed values
BS1 retained and TB18 published (**1 / 1 / 2**). BS9-5 required a text duplicate, in a stream gated by an
environment condition, of data already carried in the typed failure envelope through the production path.

**Disposition: BS9-5 is DISCHARGED AS SATISFIED IN SUBSTANCE and RETIRED.** Nothing is owed. CB21 does not restore
it, and no successor may treat the missing line as unresolved evidence.

**BS4 is closed as correctly implemented.** The defect is in the *discriminator*, not in the build.

This is the second failure of its exact kind — TB17-REV's finding was that the reconciliation record sat below the
early return that needed it; the fix moved it above the return but left it behind an environment gate the gate
runner never opens. **A diagnostic is reachable only when both its position and its enabling condition hold on the
failing path.** Recorded as lesson 97.

---

## 7. BT6 — accepted-boundary safety, proved by construction

The correction authorized below changes one comparison from `!=` to `>`. Safety is provable without runtime:

1. The fragment validation loop is **pure validation**. Each iteration either constructs and returns a
   `GlobalTopologyPlanError` or falls through. It mutates no count, no orbit set, no region, and no plan state. The
   evidence-gathering block added by CB20 writes only into the local `failure` object on the returning path.
2. `size > expected` is true on a **strict subset** of the inputs on which `size != expected` is true.
3. Therefore the set of inputs that fail at this site strictly shrinks, and every input that previously fell through
   still falls through with byte-identical `fragmentOrbits`, `tracePieceCount` and `edgeOrbitEvidence` state.
4. Ordinals **1–365 are 365/365 PASS at TB18**, so none of them currently returns from this site. By (3) their
   behaviour is unchanged. **The accepted boundary cannot move.**

Downstream consistency was checked as well: after validation, `fragmentOrbits[face]` is consumed at
`GlobalTopologyPlan.cpp:925–945` only to register each face with the region draft of each owning orbit. A face whose
two local sides share one owner is registered once, with the single region that genuinely contains both sides. That
is the correct membership under the shared-owner reading, so loosening the check introduces no downstream
inconsistency and no new failure mode.

**Every strengthening is withheld.** The sound local-fragment assertion is introduced as retained evidence only, not
as a failure, because a *new* fatal condition would not enjoy the proof above. It is promoted to fatal only after
TB19 demonstrates it holds across 1–365 and all four witnesses. This is the whole reason CB21 is a loosening plus
evidence rather than a replacement invariant.

---

## 8. BT7 — candidates and accounting

| Candidate | Transition |
|---|---|
| `M3-CP4c3-TB17-CAND-01` | **ACTIVE / GATING → OWNER PROVED, CORRECTIVE CONTRACT FROZEN.** Owner: the equality at `GlobalTopologyPlan.cpp:777–779` in `build_regions`. Mechanism measured (shared global owner), legitimacy proved (§5), correction authorized under BU1–BU2. Closes when TB19 shows ordinal 366 past this site. |
| `M3-CP4c3-TB18-REV-CAND-01` | **NEW / ACTIVE / EVIDENCE.** The sound local-fragment invariant is not yet established: local fragment enumeration on a triangle is `k+1` only if no two chords cross inside the face, and nothing yet proves non-crossing. Owner: BU3 evidence, then TB19-REV. |
| `M3-CP4c3-TB10-REV-CAND-01` | **ACTIVE / TEST-COUPLING / DEFERRED** — 371/372 blocked by a shared fixture precondition. Both co-reach the fragment mismatch and are expected to move with it. |
| `M3-CP4c3-TB7-CAND-02` | **ACTIVE / DEFERRED** — folded-cone witness, ordinal 374. No atlas invariant may be weakened for it. |
| `M3-CP4c3-DEFN-R2-CAND-01` | **ACTIVE / ARCHITECTURAL CLASS** — an exact decision with no declared bound on its input size. |
| `M3-CP4c3-TB6-CAND-01` | **ACTIVE** — vertex-30 evidence contract. **Still no vertex-30 discriminator.** |
| `M3-CP4c2-TB-X2-CAND-04` | **ACTIVE** — prescribed sphere 368. |
| `M3-CP4c2-TB-X2-R10-CAND-01` | **ACTIVE / QUALITY / COVERAGE** — saturation, ordinal 369. |
| `M3-CP4c2-TB-X2-R8-CAND-02` | **ACTIVE / PRODUCT** — zero-node/zero-arc closed-surface cut-graph behaviour, ordinal 370. **No correction authorized.** |
| finalize/contact fall-through | **ACTIVE** — separate owner, documented at TB8-REV. |

**Accounting.** Static turn on an unaccepted surface; no accepted-green loss. **+0 events / +0 recurrences.** Totals
remain **44 events / 14 categories / 30 recurrences**; produced-witness debt **5**; semantic M3 package count **84**.
Accepted authority remains **365/365**. CP4c-3 remains **OPEN**.

---

## 9. BT8 — lessons recorded

- **97.** A diagnostic is reachable only when both its **position** and its **enabling condition** hold on the
  failing path. Moving a record above the early return that needed it does not help while it stays behind an
  environment variable the frozen gate runner never sets. When freezing a discriminator, name the condition under
  which the evidence is produced, or require evidence that the production path emits unconditionally.
- **98.** Do not freeze a discriminator that requires a *text duplicate* of data already carried in a typed
  envelope. BS9-5 asked for three numbers already retained as three typed fields; its failure carried no
  information and cost a full turn's disposition.
- **99.** The two ends of a curve are not symmetric in the code but are symmetric in the topology. The terminal-slit
  exclusion correctly removes the last segment from the chord count, but a free end is a property of the **whole
  trace**: every chord that trace cuts also fails to separate globally. Fifth instance of "correct in the scope that
  produced it, used in a scope that does not make it valid" (lessons 85, 87, 93, 96).

---

## 10. BT9 — document consolidation (first application of the standing review rule)

Per the user instruction of 2026-09-03, **every REVIEW turn from this one forward performs document
consolidation before closeout.** The rule is codified in `CLEAN_UP_POLICY.md` §"Document consolidation — every
REVIEW turn", cross-referenced from `RETENTION_POLICY.md`, and bound into the handoff's durable policy (item 14)
and end-of-turn checklist (item 10).

Consolidated this turn into `M3_CP4c_Consolidated_Record.md`'s folded document index, their durable facts having
first been carried into this record, the tracker, `ORIENTATION.md`, `LESSONS.md` and `CHANGELOG.md`:

- `Architecture_M3_CP4c3_TB17_Artifact_Only_Test_Benchmark_Report.md` — superseded runtime authority (TB18 report
  is current);
- `Architecture_M3_CP4c3_TB17_Independent_Review_Record.md` — superseded review authority (this record is current);
- `Architecture_M3_CP4c3_CB20_Code_Build_Report.md` — consumed build report, its BS0–BS9 disposition preserved in §6
  above and in the changelog;
- `Architecture_M3_CP4c3_TB18_Artifact_Only_Test_Benchmark_Plan.md` — consumed evidence contract, its BS9
  discriminator dispositions preserved in §3 and §6.

Retained as current authority: `Architecture_M3_CP4c3_TB18_Artifact_Only_Test_Benchmark_Report.md` and this record,
plus the durable set and every byte-frozen selector file. **No selector file, normative definition, policy, lesson,
stable ID, artifact identity or unresolved blocker was removed or weakened.**

---

## 11. Frozen successor — `M3-CP4c-3-CB21`, Code + Build, PRODUCT CORRECTION (loosening + evidence), `BU0–BU9`

Owner: `src/geometry/GlobalTopologyPlan.cpp`, the fragment-count validation loop in `build_regions` and the error it
emits. **This is the first authorized product correction since CB19.**

- **BU0** — accepted 365 untouched; selector **383 byte-frozen** at `a7fe57cc…6f3a4b2c` and republished unchanged;
  the eight standard compile targets with **mandatory GMP/GMPXX linkage**; no runtime; no acceptance claimed.
- **BU1** — **the only semantic change:** at `GlobalTopologyPlan.cpp:777–779` replace
  `found->second.size() != expected` with `found->second.size() > expected`. The high side stays fatal and keeps its
  full CB20 evidence payload. The low side stops being an error. Nothing else in the loop changes.
- **BU2** — retain the low-side deficit as **evidence, never as a failure**: per face, the local fragment count, the
  owner count, and `deficit = expected − actual`, alongside the chords whose two sides share one owner.
- **BU3** — compute the local fragment count **locally**, from the face's own chord arrangement (carrier pair or
  corner binding), and retain it. **It must not be fatal in CB21** — the accepted-boundary proof in §7 covers a
  loosening only. Retain also whether any two of the face's chords cross inside the face, which is the open question
  behind `M3-CP4c3-TB18-REV-CAND-01`.
- **BU4** — publish the **bridge / owner census** that would name a rotation defect if one exists: per arc, whether
  its forward and reverse darts share an orbit; per trace, whether it terminates in a terminal slit; and globally
  the total orbit count, the exterior orbit count and the non-exterior orbit count. Evidence only, bounded, with an
  explicit truncation marker.
- **BU5** — one witness per new field through the **production** path, plus a witness pinning that a face with one
  chord and one shared owner now passes the validation site, plus a byte-identical regression witness for the
  high-side failure.
- **BU6** — append **selector 384** with only the BU5 identities; no reordering; selector 383 must remain an exact
  prefix.
- **BU7** — **prohibited:** any change to `tracePieceCount`, `add_fragment_orbit`, the `exteriorOrbits` filter,
  `is_terminal_slit`, `resolve_carrierless_corner_binding`, `build_fragment_corner_incidence`, the face walk, the
  rotation system, or region draft construction; any new fatal condition; any fixture mutation, tolerance,
  float-derived decision or accepted-boundary relaxation; any revert of CB12–CB20; any sphere / saturation /
  ordinal-370 / folded-cone / vertex-30 / finalize-contact work. **BS9-5 is retired — do not restore it.**
- **BU8** — audit by assumption: reproduce the §7 proof against the actual diff. Show the validation loop remains
  pure, that the new predicate is strictly weaker, and that every new computation is observational.
- **BU9** — publish six `M3-CP4c-3-TB19` discriminators:
  1. ordinals **1–365 stay 365/365** — the §7 proof made runtime-visible;
  2. **ordinal 366 no longer reds at `TraceCutFaceFragmentCountMismatch`.** It must move to a different code
     site. *Not moving falsifies BU1; moving to a new red is the expected and successful outcome;*
  3. **367 / 371 / 372 move with it**, consistent with co-reaching;
  4. the retained deficit at `(0,1,102)` is **1**, with the shared-owner chord named;
  5. the global orbit census is published: total, exterior and non-exterior orbit counts, plus whether trace 1
     terminates in a terminal slit — this decides §5's prediction and eliminates or names a rotation defect;
  6. carried surfaces **368, 369, 370, 374** are unchanged.

The successor after TB19 is an independent **`M3-CP4c-3-TB19-REV`**, which owns whether the local-fragment
assertion is promoted to fatal and whether `M3-CP4c3-TB18-REV-CAND-01` (chord crossing) is closed.

**No further diagnostic-only turn is authorized on this surface.** The mechanism is measured, the legitimacy is
proved, and the correction's safety is proved by construction; another observation-only turn would be a third
consecutive one and would add nothing the evidence does not already support.

---

## 12. What a successor must not reopen

- The face-walk permutation is a validated total permutation; its orbits are its cycles. **Shared orbit ownership by
  the two sides of one arc is legitimate topology, not a merge defect** (§5).
- **BS9-5 is retired**; its missing record was an environment-gated text duplicate of retained typed fields (§6).
- The accepted boundary cannot move under BU1 — proved by construction, not argued (§7).
- CB19's facts and the terminal-slit zero-contribution classification (§2).
- Accepted ordinals **1–365** remain the load-bearing boundary. Any future change that those identities exercise
  must demonstrate safety, not argue it.
