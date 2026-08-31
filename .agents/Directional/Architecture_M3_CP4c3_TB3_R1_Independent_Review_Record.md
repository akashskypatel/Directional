# M3-CP4c-3 TB3-R1 Independent Review Record

## Status

**REVIEW COMPLETE / TB3-R1 EXECUTION VALID / AMENDMENT 16 CONFIRMED EFFECTIVE AT RUNTIME /
CAUSE NOT ESTABLISHED — THREE MECHANISMS ENUMERATED, ONE MEASUREMENT DISCRIMINATES ALL THREE /
DIAGNOSTIC-ONLY SUCCESSOR / MEASURES AP0–AP9**

This record executes `Architecture_M3_CP4c3_TB3_R1_Independent_Review_Plan.md` (**AR0–AR7**) against
`M3-CP4c-3-TB3-R1` (run/job `33416686424 / 99568970224`, immutable package **72** artifact `9765247195`,
semantic source `93ed2ff50ddad96c9a6aa93f327b3e4d9d93a9b4`, frozen gate selector **373**).

Review and planning only: nothing executed, compiled, packaged or benchmarked, no gate selected or run, and **no
product, test, fixture, selector or build-logic byte changed**. Measures issued here are **AP0–AP9**.

---

## AR0 — the evidence boundary, re-verified rather than accepted

The working tree is byte-identical to the packaged semantic source:

```
git diff --stat 93ed2ff50ddad96c9a6aa93f327b3e4d9d93a9b4 HEAD -- src/ include/ tests/ benchmarks/ cmake/   →  empty
```

so every source claim below describes exactly the binary that ran.

Selector **373** was recomputed from committed bytes — `b47c269851fad1384b5dc9baaf674b3d4ad80ec6c2b40f7f8eda2055c6f44834`
— and **all six** predecessor prefixes reproduce exactly from `head -n` of that file: 355
`e9d88f11…`, 357 `b896d0db…`, 361 `61918d9f…`, 365 `6b5b6555…`, 367 `ef9d082f…`, 370 `9160ea61…`.
`first_red_ordinal` therefore remains comparable across the whole CP4c arc.

Execution: immutable package consumed directly; 55-entry self-excluding `SHA256SUMS` PASS; 27 package-relative
fixtures present; six executables reproduced their digests **and mode `0755` without repair**; static ownership
mapped all 373 identities exactly once; one identity per fresh process from ordinal 1 with a first-red hard stop;
postflight `productMutation/testMutation/fixtureMutation/selectorMutation/configure/compile/relink/packageRepair/
generatedDiscovery/benchmarkExecution` all false.

**TB3-R1 is admissible semantic evidence and a valid semantic red at ordinal 366.** The accepted **365 prefix is
green**, so nothing here disturbs CP4c-2.

---

## 1. The result that must be reported as a finding: Amendment 16 works

`MissingSingularityBranchTransport` is **gone**. The mechanical witness now clears A1 entirely — cut transport
domain, tangent bundle, cycle basis, index accounting, *and* singularity port attachment — and fails for the first
time in **A2a**, `field-aligned-network`. Its atlas partition diagnostics are emitted for the four non-barrier
prescribed singularities at source vertices **10, 35, 47, 71**, each with the expected three branch classes.

Two stages have now been cleared by the Amendment 15 → 16 line of reasoning, and **ordinals 1–365 stayed green
through both**. That is the second consecutive invasive A1 change with zero regression to accepted authority.

CB3's AN1 census also **statically confirms DEFN-R1's Theorem 2 prediction**: the mechanical barrier graph is a
four-component forest, `n=16`, `m=12`, `c=4`, `χ(B)=4`, **no cycles** — exactly what "every component of `B(R)` is
a tree on a `χ=2, b=0` region" requires. Each component is a 4-vertex path (2 interior, 2 tips), and 4 of the 8
interior barrier vertices carry a prescribed singularity, all `InteriorArc`, `d_B(v)=2`, star splitting into 2
components. That is a static confirmation, not a runtime one: ordinals **371–373 have still never executed**, so
the Euler-cut identity, barrier exclusion and unbound-singularity count remain runtime-unproved.

---

## AR1 — the failing invariant and the complete candidate-selection path

`resolve_field_vertex_transit` (`src/geometry/SurfaceCellTracing.cpp:557-640`) answers: *a trace has arrived at
source vertex `v` in face `F` carrying branch `b`; which single `(face, branch)` does it continue into?*

The algorithm is a breadth-first walk over `(face, branch)` states seeded at `(currentFace, currentBranch)`:

1. **Region/component gate** (`:575-579`) — a state whose frame is missing, or whose `sourceComponent` /
   `topologyRegion` differs from the arrival's, is skipped.
2. **Unique-pairing gate** (`:580-590`) — the frame must contain **exactly one** `FieldBranchBoundaryPairing` for
   that branch; two matches set `pairing = nullptr` and the state is skipped, as is a missing face row.
3. **Candidacy test** (`:592-598`) — if `arrivalMode == EdgeTransit` **or** the state's face differs from the
   arrival face, the state is a candidate iff
   `direction_in_vertex_sector(sourceMesh, row, sourceVertex, pairing->direction)`. On `FaceInterior` arrival the
   arrival face itself is excluded, so the trace must leave the face it is in.
4. **Expansion** (`:600-619`) — for every `FieldBranchTransportAdjacency` in **`topology.transports()`** incident
   to `v`, the opposite face is enqueued with the branch **rotated by the directed transport's `signedLift`**.
5. **Election** (`:622-639`) — candidates are sorted and deduplicated on `(nextFace, nextBranch)`, and
   `if (candidates.size() != 1U)` returns `VertexTransitSectorUnresolved` with the candidate faces in
   `error.publishedFaces`.

**The sector predicate is exact.** `direction_in_vertex_sector` (`FieldTransportAtlas.cpp:1623-1654`) delegates to
`direction_in_incident_vertex_sector` (`:404-426`), which requires `direction.is_barycentric()` and then compares
**`FieldExactRational`** values: `direction[next] > 0 && direction[previous] >= 0` — a **half-open** fan partition
that includes the next-vertex ray and excludes the previous-vertex ray. There is **no tolerance** here, so the
candidate cardinality is a topological fact about the traversed set, not a numerical accident. (The
`kBranchTopologyTolerance` concern recorded in `TODO.md` belongs to `counter_clockwise_sector_angle`, a different
function, not to this predicate.)

**Every condition that can reduce the candidate set to zero:** the branch direction is not barycentric; the arrival
face is the only reachable face on a `FaceInterior` arrival; the region/component gate prunes the walk; a frame
carries two pairings for one branch; or — the structurally interesting one — **the expansion is truncated**,
because `topology.transports()` is the `FieldBranchTransportAdjacency` set built from `adjacencies`, which
**excludes every `SourceBoundary`, `HardFeature` and `NonTraversable` edge by construction**.

**Every condition that can multiply it past one:** more than one reachable `(face, branch)` state passes the exact
half-open test. Over a **closed** fan around a **regular** vertex this cannot happen — holonomy is trivial, the
transported direction rotates consistently, and a half-open partition of a full turn admits exactly one sector.
Around a **singular** vertex it *can*: the holonomy is a non-trivial quarter-turn, so the same face is reachable
with **different branches**, dedup is on `(face, branch)` and keeps them distinct, and two such states can each
satisfy the predicate. **Multiplicity is therefore a structural property of transiting a singular vertex**, not a
defect of the predicate.

---

## AR3 — the cut-domain audit, by assumption rather than by symbol

Question: is vertex transit *supposed* to walk one connected component of `star(v) ∖ B(R)`, and does the current
traversal already enforce it?

**Yes to both, and this is the finding that constrains every candidate correction.** Because expansion draws only
from `topology.transports()`, the walk is already confined to the connected component of `star(v) ∖ B(R)`
containing the arrival face. `resolve_field_vertex_transit` is therefore **already Amendment-16-compliant** — it
does not cross a barrier and does not close an open fan by branch transport.

**So this is not a violation of Amendment 16; it is a missing case.** The function has no barrier-aware branch at
all: when the walk is truncated by a barrier it reports "the sector is unresolved" rather than "the continuation is
blocked by a barrier". The network already models the latter — `MandatoryBarrierTermination` is a frozen terminal
event kind and appears in the observed terminal union `{2, 3, 4}` — so a sibling case exists elsewhere in the same
producer and this path does not consult it. That is `LESSONS.md` 51 exactly: *when a producer handles N sibling
cases and one takes a shortcut, read the siblings before believing the shortcut is a design.*

**Both prohibited interpretations are explicitly rejected here.** Giving a barrier edge a `FieldBranchTransportAdjacency`
so the fan closes, or otherwise manufacturing uniqueness by crossing a hard feature, is Amendment 15's option C in
its third costume and stays **prohibited** (AP9). A correction that makes `candidates.size() == 1` by widening the
traversal is wrong even if it turns ordinal 366 green.

**One scope correction is owed.** Amendment 16 is written as *"every **A1** derivation that walks transport is a
transport-domain operation."* `resolve_field_vertex_transit` is **A2a**. Its compliance is currently an accident of
consuming the atlas's transport set rather than a stated obligation, and a future CB could "fix" this red by
widening the traversal without violating the amendment as written. §5 widens the text to every stage; this is a
clarification of scope, not a new normative decision, because the amendment's own reasoning already covers it.

---

## AR2 — the locus is recoverable, and the reason it was lost is one line, three turns old

**The discriminator already exists in the product.** `error.publishedFaces` is populated with the candidate faces
(`:633-636`), so **zero versus multiple is exactly the difference between an empty and a non-empty
`publishedFaces`** — and `continuation_error` also carries `sourceVertex`, `sourceFace` and `branch`. Every fact
this review needs was constructed at the failure site and then discarded.

Where it was discarded is precise and, this time, structural rather than local:

```cpp
// src/pipeline/RemeshPipeline.cpp:6673-6678
if (!fieldAlignedBuild) {
  return fail_surface_cells(
      SurfaceCellFailureCode::NotProductionReady,
      std::string("field-aligned-network/") +
          geometry::field_aligned_curve_network_error_code_name(fieldAlignedBuild.error().code));
}
```

`fieldAlignedBuild.error()` is a fully populated `FieldAlignedCurveNetworkError` in hand, and **only `.code` is
read**; the object dies at the `return`. And `fail_surface_cells` (`:6146-6163`) takes only
`(SurfaceCellFailureCode, const std::string &stage)` and stores `terminalFailureCode` / `terminalFailureStage` —
**it has no parameter for a locus at all**. Every stage funnels through it, so every stage's typed error loses
everything but its name.

**This is the third consecutive review turn that has had to recover a locus by elimination**: TB1
(`IncompleteCycleBasis`), TB2 (`MissingSingularityBranchTransport`), and now TB3-R1. Each turn the response was a
*bespoke* channel for the one failing code — AK1/AK2 added region diagnostics, AN1 added atlas locus fields, and
the A2a path had already been widened by string concatenation (`"field-aligned-network/" + code`, which is
literally a hand-rolled locus channel with room for one field). The project has been re-implementing the same
channel once per stage, at the call site, while the structured object with all the fields is dropped one line
later.

**Corrective (AP1): fix the funnel, not the code.** Give the surface-cell failure path a typed locus payload —
optional source vertex / face / edge / branch / region plus a small published-face list — populated from whichever
stage error is in hand, and surface it in `RemeshDiagnostics` alongside `terminalFailureCode`. One change covers
A1, A2a, A2a′ and A2b at once, and it retires a defect that has cost three turns.

**Consequently the successor is diagnostic-only.** Per AR7's own rule — *if the exact runtime locus/cardinality
remains unknown, issue diagnostic-only Code + Build instrumentation first* — no semantic correction is authorized
in the next turn.

---

## AR4 — causality: NOT established, and deliberately so

**The code did not change.** CB3's entire diff to `src/geometry/SurfaceCellTracing.cpp` is **8 insertions and 1
deletion in two hunks at old lines 3069 and 3113**, both inside `canonical_field_aligned_candidate`.
`resolve_field_vertex_transit` (`:557-640`) is **untouched**, as are `direction_in_vertex_sector` and the sector
predicate.

**But "the code is untouched" is not "the failure is pre-existing", and this is the distinction the plan asks for.**
CB3 implemented Amendment 16 policy **P2**: `FieldSingularityFact` gained a `PortPolicy`, and the two hunks make
the network neither count nor emit ports for `BarrierAbsorbed` singularities. The mechanical witness has 8
prescribed singularities, **4 of them barrier-incident and now port-less**. So the *inputs* to the transit —
which traces exist and where they start — changed even though the transit itself did not. Unchanged code reached
with a changed trace set can fail for a genuinely new reason.

Three mechanisms remain live. They are enumerated, **none is promoted**, and each is falsified or confirmed by the
same single measurement:

| # | mechanism | signature under AP1's diagnostic |
|---|---|---|
| **M1** | **Barrier truncation, zero candidates.** The trace arrived at a barrier-incident vertex; expansion cannot cross `B(R)`; no admissible sector survives in the arriving star component. The trace should arguably have *terminated* at the barrier (§AR3). | `publishedFaces` **empty** |
| **M2** | **Singular-vertex multiplicity.** The trace arrived at a singular vertex; non-trivial holonomy makes the same face reachable with different branches, and two `(face, branch)` states pass the exact half-open test. Transiting a singular vertex may itself be the wrong operation. | `publishedFaces` **size ≥ 2** |
| **M3** | **P2 consumer mismatch.** A vertex that is a singularity in A1's facts but has **no port** in A2a is invisible to every A2a path keyed on ports, so a trace passes through it as ordinary and attempts a transit. Terminal ownership *is* port-keyed — `:832-839` searches `candidate.singularityPorts` and raises `InvalidNetworkTerminalOwnership` when no port matches — which establishes that ports are load-bearing for singularity semantics in A2a, and P2 removed four of them. | failing vertex ∈ the 4 `BarrierAbsorbed` vertices |

M1 and M3 are not exclusive: the same vertex can be both barrier-incident and port-less, which is precisely the
class P2 created. **M3 is the mechanism this review would investigate first**, because it is the only one that is a
consequence of the change under test — but it is a **suspicion, not a finding**, and AP4 forbids designing against
it. That discipline is why the last five turns have each advanced a stage rather than re-litigating one.

**The red is not labelled a regression merely because it follows CB3**, as AR4 requires. Nor is it labelled
pre-existing merely because the function is untouched — which would be the symmetric error, and is the one this
review declines to make.

---

## AR5 — accepted behaviour and frozen authority preserved

Ordinals **1–365** are green in this run and are not touched by any measure below. Selector **373** stays
byte-identical and unselected; `selected_gate=NONE`, `gate_execution_authorized=false`. Barrier transport stays
prohibited. **The P2 decision stands** — no measured evidence falsifies its premises, and CB3's census (4
`InteriorArc`, `d_B=2`, 2-component-star, `BarrierAbsorbed` rows) is exactly the evidence AN1 required before the
policy could be chosen. The ordinal-366 contract and the first-red rule are unchanged.

---

## AR6 — carried candidates, adjudicated

- **`M3-CP4c3-TB3-R1-CAND-01`** — remains **ACTIVE / CAUSE NOT ESTABLISHED / GATING / NON-STABLE**. §AR1 fixes the
  invariant and §AR4 enumerates three mechanisms with a single discriminating measurement. Owner: **AP1** for the
  measurement, **AP5** for the correction once the measurement chooses.
- **`M3-CP4c3-TB2-CAND-01`** — **prior failure locus CLEARED at runtime**; `MissingSingularityBranchTransport` no
  longer occurs and Amendment 16/P2 is confirmed effective. Retained open **only** because the gating identity at
  ordinal 366 is still red for a downstream reason.
- **`M3-CP4c3-TB2-ORCH-01`** — **RESOLVED / RUNTIME-PROVED.** Package-relative fixture authority and removal of the
  absolute compile-time source-root fallback survived package-72 preflight and executed past the former stop; 27
  package-relative fixtures were verified and all six executables held mode `0755` **without repair**. The
  reclassification this reviewer made at TB2-REV — a build/packaging contract defect owned by a CB, not an
  orchestration mishap — is discharged exactly as specified.
- **`M3-CP4c3-TB2-REV-CAND-01`** — **RESOLVED.** CB3 independently compared the package 69/70 binary digests, which
  is what AN2 required; the executor is no longer the sole witness to its own immutability.
- **`M3-CP4c3-DEFN-R1-CAND-01`** and the inherited ordinal 368–370 candidates
  (`M3-CP4c2-TB-X2-CAND-04`, `R10-CAND-01`, `R8-CAND-02`) — **unchanged and still runtime-unproved**, because
  first-red at 366 again prevented 367–373 from executing. Amendment 15's three self-checks have now been blocked by
  a first red **three times running**; §AP6 addresses that directly.
- **New: `M3-CP4c3-TB3-R1-REV-CAND-01`** — the pipeline failure funnel discards every stage's typed error locus
  (§AR2). Owned by **AP1**.

**Stable accounting is unchanged: 44 events / 14 categories / 30 recurrences**, produced-witness debt **5**,
semantic M3 packages **70**. Ordinal 366 belongs to a gate that has never been accepted and the accepted 365 prefix
is green in this very run: **+0 events / +0 recurrences.**

---

## 5. Amendment 16 — scope widened to every stage

Recorded normatively in `DESIGN.md` §7.2.1. The amendment's text said *"every **A1** derivation that walks
transport."* Its reasoning was never A1-specific, and A2a's `resolve_field_vertex_transit` already complies. The
text is widened to **every stage** so that compliance is an obligation rather than an accident, and so that no
future turn can close this red by widening a traversal across a barrier without violating the amendment as
written.

Nothing else about Amendment 16 changes. This is the third consecutive turn in which a measure of mine was scoped
one level too narrowly — by **symbol** at AM2, by **enum** at AN1, by **stage** in Amendment 16's own text — and
§7 records the general form.

---

## AR7 — measures **AP0–AP9**, one bounded successor

The next turn is **`M3-CP4c-3-CB5`** — Code + Build, **diagnostic-only**, runtime-free, GMP/GMPXX linked. No
semantic correction is authorized in it.

**AP0 — preconditions and frozen authority.** Accepted runtime predecessor remains CP4c-2 at **365/365**. CP4c-3's
gate is **373**, `b47c269851fad1384b5dc9baaf674b3d4ad80ec6c2b40f7f8eda2055c6f44834`; recompute it and **all six**
predecessor prefixes from committed bytes at authoring and preflight, validating each as exactly 64 lowercase hex.
Never transcribe a digest. No existing selector byte may change. `selected_gate=NONE`,
`gate_execution_authorized=false`.

**AP1 — fix the failure funnel, not the failing code.** Give the surface-cell failure path a **typed locus
payload** — optional source vertex, face, edge, branch and topology region, plus a bounded published-face list —
populated from whichever stage error is in hand at the call site, and surfaced in `RemeshDiagnostics` beside
`terminalFailureCode`. Convert **all four** stage call sites in one change (A1 `field-transport-atlas`, A2a
`field-aligned-network`, A2a′ `surface-cut-graph`, A2b `global-topology-plan`), not just the one that is failing.
Retire the string-concatenation locus channel (`"field-aligned-network/" + code`) in the same change rather than
leaving two mechanisms. Additive only: no existing error code, mapping or enum value may change.

**AP2 — publish what discriminates M1/M2/M3.** For the mechanical witness's ordinal-366 path specifically, the
report must name: the failing **source vertex**, **arrival face** and **branch**; the **arrival mode**
(`FaceInterior` vs `EdgeTransit`); `publishedFaces` with its **cardinality** — the zero-versus-multiple answer;
whether the failing vertex is one of the four `BarrierAbsorbed` vertices from CB3's census; whether it is
barrier-incident at all and with what `d_B(v)`; and the number of star components reachable through
`topology.transports()` from the arrival face. Nothing here changes behaviour; all of it already exists in the
error object or in CB3's census.

**AP3 — no semantic correction in CB5.** The plan's own rule: diagnostic-only instrumentation first when the
locus and cardinality are unknown. A CB that also changes transit behaviour is out of scope and must be rejected at
review even if ordinal 366 turns green.

**AP4 — do not design against M3.** The P2 consumer-mismatch mechanism is the most plausible and is therefore the
most dangerous to assume. A correction whose report cannot name the measured cardinality and the measured vertex
class is not authorized. Same rule as AK6, AL4, AM7 and AN4, restated because it has been the single
highest-value control in this checkpoint.

**AP5 — the correction, once AP2 reports.** Sketched only, and explicitly not decided here: if **M1**, the
corrective is a barrier-aware termination case consistent with `MandatoryBarrierTermination`, whose sibling
handling must be read before it is written (`LESSONS.md` 51); if **M2**, transiting a singular vertex is the wrong
operation and the corrective belongs to arrival/termination, not to election; if **M3**, A2a's port-keyed paths
must be reconciled with A1's singularity facts so a `BarrierAbsorbed` singularity is not silently ordinary. The CB
report must name which measured fact chose the branch.

**AP6 — stop letting one red hide seven identities.** Ordinals **367–373** have now been blocked by a first red at
366 in **three consecutive TB runs**, so Amendment 15's own self-checks, the prescribed sphere, the ordinary
proposal and the empty-network rejection have never executed even once. Propose — for the next TB plan, not for the
gate — a **frozen non-gating diagnostic pass** that executes ordinals 367–373 report-only after the gate's first
red, with zero gate credit and a written rationale, exactly as the non-gating diagnostic mechanism already allows.
This changes no selector byte and no gate semantics; it converts a three-turn information blackout into evidence.
If it is declined, the declining turn must say why in writing.

**AP7 — carry the unreached items unchanged.** `M3-CP4c3-DEFN-R1-CAND-01`, `M3-CP4c2-TB-X2-CAND-04` (AL4 still
forbids designing the sphere's fix), `R10-CAND-01` and `R8-CAND-02` all stand exactly as compiled at ordinals
367–373.

**AP8 — audit by assumption, and prove the predicate was not a symbol search.** For AP1 the predicate is *"this
call site holds a typed stage error and passes on less than it holds"*; for any AP5 correction it is *"this code
assumes a vertex neighbourhood is fully traversable, or assumes a singularity is represented by a port."* The CB
report must list what the search found and name at least one site that satisfies the predicate **without**
touching the symbols named in this record.

**AP9 — prohibited.** Giving a barrier edge a branch transport, or otherwise crossing/closing a barrier to make
`candidates.size() == 1` — Amendment 15's option C in its third costume. Changing transit behaviour in CB5.
Designing the correction before AP2 reports. Weakening the `candidates.size() != 1U` election into a "pick the
first" heuristic. Introducing any tolerance into the sector predicate, which is exact today. Reopening Amendments
12–16 or the P2 decision. Renumbering or removing any existing error-enum value or changing any existing mapping —
new codes and fields are appended only. Changing accepted selector 365's bytes, or 357 / 358 / 361 / 367 / 370 /
373. Removing any diagnostic surface added by CB1, CB2, CB3 or this line of measures. Retrying the gate from a
review turn, or executing Directional runtime, running a gate, or benchmarking in a CB turn.

---

## 6. Falsifiable predictions

1. **AP2 will report a `publishedFaces` cardinality of either 0 or ≥ 2, and that alone selects M1/M2.** If it
   somehow reports 1, the election is not the failure site and this entire reconstruction is wrong.
2. **The failing vertex will be barrier-incident.** §AR3's truncation argument predicts it; a non-barrier vertex
   falsifies M1 and M3 together and leaves M2.
3. **If the failing vertex is barrier-incident, it will be one of the four `BarrierAbsorbed` census vertices** —
   i.e. M3 and M1 coincide. A barrier-incident vertex *outside* that set would show the failure is independent of
   P2.
4. **Ordinals 1–365 will stay green** through AP1's funnel change, which is additive and touches no product
   decision.
5. **Amendment 15's ordinals 371–373 will remain unmeasured** unless AP6's non-gating diagnostic pass is adopted.

## 7. What this turn owes its own record

Three consecutive measures of mine have been scoped one level too narrowly, and the pattern is now legible enough
to state as a rule rather than as three apologies. **AM2** scoped a consumer audit by **symbol**
(`globalVertexByLocal`) when the thing to audit was an assumption. **AN1** scoped error instrumentation by **enum**
(`FieldAtlasBuildErrorCode`) when the witness was visibly advancing stage by stage — and the very next failure was
in a different stage's enum. **Amendment 16** was written for **A1** when its own reasoning covered every stage.

Each was narrower than the reasoning that produced it, and in each case the narrowing was invisible because the
measure was *satisfied exactly*. The general form, recorded as `LESSONS.md` **68**: **when a witness is advancing
stage by stage, scope the measure to the pipeline, not to the stage that is currently failing** — and prefer a
predicate a reader can apply to code you have not read over an enumeration of the code you have.

## 8. Exact next turn

**`M3-CP4c-3-CB5`** — Code + Build, **diagnostic-only**, runtime-free, GMP/GMPXX linked, under **AP0–AP9**. It
lands AP1's typed locus payload across all four stage call sites, publishes AP2's discriminating facts, and
proposes AP6's non-gating diagnostic pass for the successor TB plan. No semantic correction.

CP4c-2 remains **CLOSED / ACCEPTED at 365/365**. CP4c-3 is **open**; gate **373** stays frozen and unselected.
