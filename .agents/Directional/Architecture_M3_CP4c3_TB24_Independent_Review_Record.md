# M3-CP4c-3-TB24 Independent Review Record

## Status

**COMPLETE / STATIC / NO RUNTIME / NO COMPILE / NON-STABLE / SUCCESSOR FROZEN.**

`M3-CP4c-3-TB24-REV` is independent REVIEW + PLAN only. It executed no Directional runtime, no compile, no
package operation, and mutated no product, test, fixture, benchmark, build or selector byte. Accepted authority
remains **365/365**; the current semantic runtime authority remains `M3-CP4c-3-TB24-EXEC` (**389 PASS / 12 RED**
on selector 401). CP4c-3 remains **OPEN**. Measures **CH0–CH9** freeze the exact successor
**`M3-CP4c-3-CB28`**.

## Authority licensing this review

`review_check.py authority 9c72fea8b666534b9e52fa42bbe8cbf8ae68ffe5` — **ALL CHECKS PASSED**: the semantic
source exists, is an ancestor of HEAD, and no code surface drifted between it and HEAD. Static review of the
working tree is therefore valid evidence about immutable package `9935929108`.

Evidence consumed: `Architecture_M3_CP4c3_TB24_Artifact_Only_Test_Benchmark_Report.md` (runtime facts),
`Architecture_M3_CP4c3_TB24_Artifact_Only_Test_Benchmark_Plan.md` (the frozen contract, folded into
`M3_CP4c_Consolidated_Record.md` by §9 of this record),
`Architecture_M3_CP4c3_CB27_Code_Build_Report.md`, `M3_CP4c_Frozen_Definitions.md` Part VII, and the exact
source at HEAD.

---

## 1. CH0 — the finding: one cause, seven surfaces

**Every semantically new RED in TB24 is one defect.** It is not a geometry finding and it is not seven
independent regressions.

`certify_actual_embedded_graph` (`src/geometry/SurfaceCutGraph.cpp:604–615`) calls
`build_source_face_ownership` and, when that derivation cannot establish ownership, **returns a
`SurfaceCutGraphError` instead of a certificate**:

```cpp
const auto ownershipBuild = build_source_face_ownership(embedded, network, cutEdges, certificateFaceOrbits);
if (const auto *failure = std::get_if<SurfaceCutGraphError>(&ownershipBuild))
  return *failure;                       // <- no SurfaceCutGraph is ever constructed
```

Consequently `mechanical.cutGraph.has_value() == false`, and **every witness downstream of the certificate
loses its subject**. On the single mechanical fixture this accounts for ordinals **366, 384, 385, 389, 390,
393 and 398** — seven of the twelve RED ordinals — and for the unavailability of discriminator **D3**.

The proof that these are one cause and not seven is in the report itself: each of 384/385/389/390 "reaches
`mechanical.cutGraph.has_value() == false` and reports `NotProductionReady` **before its later evidence
assertion**". They never got to disagree with anything.

### 1.1 The evidence the plan was built to publish is complete, correct, and unreachable

This is the sharp edge of the finding. CB27's plan-side relocation is **fully implemented**.
`GlobalTopologyPlan.cpp:1122–1170` builds the component partition, calls
`detail::check_certified_source_face_owner_consistency`, populates the `ownerEvidence` census with component
id, face count, owner count, typed `seedState` and the untruncated owner-orbit ids, and then fails through
`UncutFaceComponentOrbitSeedNotUnique` naming the component and the conflicting owners — exactly what
**DEFN-R3.2** required and exactly what **D4** demanded.

None of it runs. `certify_actual_embedded_graph` fails first, so no `SurfaceCutGraph` exists to look an owner
up in.

**CB27 moved the failure upstream of every witness built to observe it.** That single ordering decision, not
any change in the geometry, produced the TB24 ledger.

### 1.2 The relocated failure carries strictly less evidence than the one it replaced

`SurfaceCutGraphError` (`include/directional/geometry/SurfaceCutGraph.h`) has fifty-odd diagnostic fields and
**not one of them is an uncut-component identity or an owner multiset**. `build_source_face_ownership` sets
only `failure.sourceFace`. The pre-CB27 `UncutFaceComponentOrbitSeedNotUnique` carried
`uncutFaceComponent`, `uncutFaceComponentSeedCount`, typed `uncutFaceComponentSeedState`, the untruncated
orbit ids, the component face census and the boundary attribution.

TB24 records the consequence factually: ordinal 366's exception is
`SourceFaceOwnershipNotEstablished;detailCode=SourceFaceOwnershipNotEstablished;sourceFace=0,1,2` and
"**no component/conflicting-owner relocated-guard diagnostic is emitted in the authoritative raw log**".

**D4 is therefore not merely RED — its contract is unmet.** The relocated guard was required to name the
component and the conflicting owners. The guard that actually fires is a different, poorer one, sitting one
stage upstream.

### 1.3 The failure is the same failure, at the same locus

Pre-CB27: `UncutFaceComponentOrbitSeedNotUnique`, component **0**, **191** faces, `seedState=Multiple`, seed
orbits **`[0,1,3]`**, iteration-order locus source face **`(0,1,2)`**.

Post-CB27: `SourceFaceOwnershipNotEstablished`, source face **`(0,1,2)`**.

Same fixture, same locus, same arithmetic. `build_source_face_ownership` seeds from
`embedded.faceWalk.orbitByDart[interiorDart]` at mandatory/cut arcs and from the corner-turn rule at trace
segments, unions across non-barrier edges through `build_source_face_component_partition`, and rejects any
component whose owner set is not a singleton (`SurfaceCutGraph.cpp:508–541`). That is the pre-CB27 seeding
algorithm, transcribed. Nothing about the relocation gave it new information, and it returned the same answer.

---

## 2. CH1 — classification of the 12 RED ordinals

| Ordinal | Identity | Classification |
|---|---|---|
| 366 | `GlobalTopologyPlan.MechanicalFeatureWitnessDerivesRegionsThroughProductionEntryPath` | **carried frontier, evidence regressed.** Same locus `(0,1,2)`; the typed failure now carries less than the one it replaced. Owner: `M3-CP4c3-TB21-CAND-01` + new `M3-CP4c3-TB24-REV-CAND-01`. |
| 367 | `GlobalTopologyPlan.RotationSystemAndFaceWalkAgreeOnProducedWitnesses` | **unchanged carried surface.** No change from TB23-R1. |
| 368 | `GlobalTopologyPlan.PrescribedSphereWitnessDerivesRegionsThroughProductionEntryPath` | **unchanged carried surface**, `CellularityNotEstablished/origin=RotationSystemInconsistent`. Owner: `M3-CP4c2-TB-X2-CAND-04`. Untouched. |
| 369 | `SurfaceCutGraph.OrdinaryProposalSelectsTraceCrossedEdgeWithoutSaturation` | **unchanged carried surface**, `saturationUsed=true`. Owner: `M3-CP4c2-TB-X2-R10-CAND-01`. |
| 370 | `SurfaceCutGraph.EmptyNetworkOnClosedSurfaceIsRejectedWithTypedError` | **unchanged carried surface.** Owner: `M3-CP4c2-TB-X2-R8-CAND-02`. **No correction authorized.** |
| 374 | `ResolvedBranchCorrection.FoldedConeArrivalRayElectsOneOwner…` | **unchanged carried surface**, `atlasBuild=false`. Owner: `M3-CP4c3-TB7-CAND-02`, deferred. |
| 384 | `GlobalTopologyPlan.FragmentOwnerDeficitPublishesCorrectionEvidenceThroughProductionPath` | **PASS → RED. Evidence-subject loss, §1.** Not a geometry regression. |
| 385 | `GlobalTopologyPlan.UncutFaceComponentSeedFailurePublishesProductionDecisionEvidence` | **PASS → RED. Evidence-subject loss, §1**, and additionally **contract-obsolete**: the seed it witnesses was deliberately deleted by DEFN-R3.2. Assertions must be replaced in place. |
| 389 | `GlobalTopologyPlan.EmbeddedGraphEulerCensusPublishesThroughMechanicalProductionFailure` | **PASS → RED. Evidence-subject loss, §1.** |
| 390 | `GlobalTopologyPlan.UncutFaceComponentBoundaryOrbitAttributionPublishesThroughMechanicalProductionFailure` | **PASS → RED. Evidence-subject loss, §1.** |
| 393 | `GlobalTopologyPlan.MechanicalProjectionEvidencePublishesMinorityRowsAndFaithfulnessResidual` | **RED. Evidence-subject loss, §1.** CG5 replaced its assertions in place as required; the replacement is untested because the subject is absent. |
| 398 | `SurfaceCutGraph.CellularityCertificatePublishesTotalSourceFaceOwnershipOnProductionFixtures` | **RED — the honest gate.** This is the one RED that states the real open problem: ownership is not established on the production fixture. It stays gating and stays RED until the derivation is correct. |

**367/368/369/370/374 are untouched.** They have separate owners, no measure below addresses them, and their
presence in the ledger is not evidence about CB27.

**371/372/391/392 remain PASS**, unchanged from prior authority. **399/400/401 PASS** — the three new
falsifiability/infrastructure witnesses all hold, including ordinal 400, which proves the relocated consistency
rule *can* reject conflicting certified owners. That is worth stating precisely: **ordinal 400 proves the
relocated guard works; ordinal 366 proves it is never reached.**

---

## 3. CH2 — discriminator adjudication

| Discriminator | Frozen requirement | Outcome |
|---|---|---|
| **D1** accepted prefix | 365/365 | **MET.** No accepted regression. The turn is prefix-safe. |
| **D2** owner-map totality | publish count, totality, orbit membership | **NOT MET.** 300 source faces, published owner-entry count `unavailable`. The map is not published at all, so its totality was never tested. |
| **D3** component-0 owner multiset | 191 owners, all-equal vs not-all-equal | **NOT MEASURABLE.** 0 observed / 191 unavailable. |
| **D4** relocated ordinal-366 guard | must name component and conflicting owners | **CONTRACT UNMET**, §1.2. |
| **D5** ordinals 393 and 397 | both PASS | **393 RED / 397 PASS.** The conjunction fails, but 397 — the byte-frozen unrelated-locus witness — is **fixed, not relaxed**, exactly as DEFN-R3.6 required. That measure is discharged. |
| **D6** carried surfaces | report only | **MET.** 367/368/369/370/374 RED and 371/372/391/392 PASS as expected. |

### 3.1 Why D3 was unmeasurable — and why that was foreseeable

D3 was defined to read the published owner map. CG1 made publication conditional on the ownership derivation
succeeding. **A discriminator gated on the success of the thing it discriminates can never fire on the case it
was built for.** The only executions in which D3 could have reported are the ones in which there was nothing
to decide.

This review takes that as its own error to own: **DEFN-R3.5 defined the discriminator without checking that
its input survives the failure it was meant to diagnose.** It is the fifth consecutive attempt to measure
certified source-face ownership, and the fourth to be defeated by the measurement's own preconditions
(`LESSONS.md` 115). Measure CH5 below is written to be immune to this specific failure: it publishes on the
failure path, not on the success path.

### 3.2 `M3-CP4c3-TB21-CAND-01` remains **UNADJUDICATED**

Neither branch is selected. It is not weakened, not strengthened, and not closed. What TB24 adds is negative
information of real value: the ambiguity is **not** an artefact of where the derivation lives. Moving it from
`GlobalTopologyPlan` into `SurfaceCutGraph` reproduced `[0,1,3]`-at-`(0,1,2)` exactly.

---

## 4. CH3 — what DEFN-R3 got right, and the one clause this review withdraws

**Upheld without qualification:**

- **DEFN-R3.1's decision** — the certifier, not the consumer, must be the authority on source-face ownership.
  Correct, and CB27 implemented it.
- **DEFN-R3.2** — ownership is read, not seeded, in the consumer. Correct, implemented, and *proved to work*
  by ordinal 400.
- **DEFN-R3.3** — the full barrier set. `build_source_face_ownership` builds
  `cutEdges ∪ mandatory/cut arc source edges ∪ trace incoming/outgoing carriers`. Conformant.
- **DEFN-R3.4** — the fragment-count prohibition stays lifted; nothing in TB24 disturbs it.
- **DEFN-R3.6** — ordinal 397 fixed, not relaxed. **Runtime-proved: 397 PASS.** Discharged.
- **DEFN-R3.7** — ordinal 393's assertions replaced in place, ordinal retained and gating. Conformant.

**Withdrawn — DEFN-R3.1's justification clause.** Part VII asserts that publishing the owner map is
"**a publication decision, not a new computation**", because the certifier already calls
`build_embedded_graph_topology` and derives the same face walk.

That is **false for the faces that matter.** The face walk's darts are darts of *network and cut arcs*. A
source face therefore has a directly readable certified orbit **only if it is incident to an arc or crossed by
a trace**. Every other source face — including most of component 0's 191 — has no dart of its own, and its
owner must still be *propagated* across non-barrier edges from a face that does. That propagation is precisely
the seeding algorithm DEFN-R3.2 set out to delete, and it is where the failure lives.

The decision survives; the reason does not. **The certifier is the right authority, but it does not already
know the answer, and moving the derivation to the right side of the boundary gave it no new information.**
This is recorded as `M3-CP4c3-TB24-REV-CAND-02` and as `LESSONS.md` 121.

---

## 5. CH4 — stable accounting

**No stable event, category, or recurrence is added.** Totals remain **44 events / 14 categories / 30
recurrences**, produced-witness debt **5**, semantic M3 package count **89** (CB27's package, now reviewed).

Rationale, under the established rule that a stable event requires accepted-green loss:

1. accepted identities **1–365 are 365/365 PASS**; no accepted behaviour was lost;
2. 384/385/389/390 are CP4c-3 carried witnesses over an open frontier, not accepted authority. Precedent:
   `PR8-R0xx` line — "the identity is red on the previously accepted package and no accepted-green behavior is
   lost; totals unchanged";
3. their RED is **subject loss, not behaviour loss** — no assertion in any of the four was evaluated and found
   wrong;
4. 366/367/368/369/370/374 are carried surfaces already counted;
5. 398 is a new gating witness whose first execution is RED. A witness that has never been green cannot regress.

Per handoff item 8, every observed regression is nonetheless categorised, in §2 and in the tracker, and the
non-stable candidates below carry them.

---

## 6. CH5 — candidates

### `M3-CP4c3-TB24-REV-CAND-01` — the failure was moved upstream of its own witnesses — **NEW / ACTIVE / GATING / PRODUCT + EVIDENCE ORDERING**

`certify_actual_embedded_graph` returns a typed error rather than a certificate when ownership is incomplete,
so the complete and correct plan-side consistency evidence (`GlobalTopologyPlan.cpp:1122–1170`) is unreachable,
D3 is unmeasurable, D4's contract is unmet, and 384/385/389/390/393 lose their subject. Owner: **CH6/CH7**.
Falsified if, after CH6/CH7, ordinals 384/389/390 return to PASS and ordinal 366 emits the component and
conflicting owners.

### `M3-CP4c3-TB24-REV-CAND-02` — ownership of non-incident source faces is a derivation, not a read — **NEW / ACTIVE / ARCHITECTURAL / DEFINITION CORRECTION**

Withdraws DEFN-R3.1's "publication, not computation" clause per §4. The certifier holds a dart only for
arc-incident and trace-crossed faces; all other ownership is propagated. Owner: **CH8** measures the
propagation instead of relocating it again.

### Carried, unchanged

`M3-CP4c3-TB21-CAND-01` **ACTIVE / GATING / UNADJUDICATED** (§3.2, owner CH8);
`M3-CP4c3-TB19-CAND-01` symptom record under it;
`M3-CP4c3-DEFN-R3-CAND-01` **ACTIVE** — two independent constructions of one embedded topology; unresolved and
still not load-bearing;
`M3-CP4c3-TB22-REV-CAND-01` **ACTIVE** — ordinal 393's replacement contract is authored but untested;
`M3-CP4c3-TB18-REV-CAND-01`, `M3-CP4c3-TB7-CAND-02`, `M3-CP4c3-DEFN-R2-CAND-01`, `M3-CP4c3-TB6-CAND-01`,
`M3-CP4c2-TB-X2-CAND-04`, `M3-CP4c2-TB-X2-R10-CAND-01`, `M3-CP4c2-TB-X2-R8-CAND-02`, finalize/contact
fall-through — all unchanged, separate owners.

### Closing now

`M3-CP4c3-TB23-REV-CAND-01` **CLOSES / RUNTIME PROVED** — ordinal 401 PASS; fixture resolution fails closed.
`M3-CP4c3-TB23-REV-CAND-02` **CLOSES / RUNTIME PROVED** — the corrected execution view carried TB24 through
preflight with `execution_view_verified=true` and equal pre/post censuses.
`M3-CP4c3-TB23-R1-REV-CAND-01` **CLOSES / RUNTIME PROVED** — ordinal 397 PASS, byte-identical expectation, no
relaxation.

---

## 7. CH6–CH9 — frozen successor: `M3-CP4c-3-CB28`

Code + Build, runtime-free, GMP/GMPXX linked, `runtimeExecution=false`. It creates no acceptance evidence.
**Scope is the ordering defect and one census. It does not attempt to fix the ownership derivation** — that
correction is not authorized until CH8 has measured which branch is true.

### CH6 — publication must survive failure

`certify_actual_embedded_graph` must **not** return an error when source-face ownership is incomplete. It
publishes the certificate with whatever ownership was established, each entry carrying an explicit status
(`Established` / `Unavailable` / `Conflicting`), and `proves_cellularity()` continues to return **false** in
that case — DEFN-R3.1's proof obligation is **unchanged and not weakened**.

`SourceFaceOwnershipNotEstablished` remains a valid typed certifier error for a certificate that is internally
invalid — an owner orbit outside the certificate's own face set. That is what ordinal **399** tests, and 399
must stay PASS.

### CH7 — the consumer must reach its own census

`GlobalTopologyPlan`'s unlabeled-face loop (`GlobalTopologyPlan.cpp:1111–1120`) must not return
`SourceFaceFragmentOrbitMissing` before the component partition and
`check_certified_source_face_owner_consistency` have run and `ownerEvidence` has been populated. Build the
partition and the census **first**, then fail through `UncutFaceComponentOrbitSeedNotUnique` naming the
component and the conflicting owners.

**Required outcome:** ordinal 366 emits component `0`, its owner multiset and its face census; ordinals
**384, 389, 390 return to PASS** without any change to their assertions. If they do not, CH6/CH7 are wrong and
`M3-CP4c3-TB24-REV-CAND-01` is falsified.

### CH8 — the certified-owner conflict census, with its falsification condition stated first

The certifier publishes, alongside the owner map, a census over **every source edge `e` not in `barriers` with
exactly two incident faces `f`, `g`** where both sides have an established owner and
`owner(f) != owner(g)`. Each row records `e`, `f`, `owner(f)`, `g`, `owner(g)`, and — decisively — **`e`'s
barrier class**: is `e` a trace outgoing carrier, a trace incoming carrier, a mandatory edge, a cut edge, or
**none of these**?

This is not a fifth restatement of the seed. It relates two independent reads to each other, and it decides
`M3-CP4c3-TB21-CAND-01` totally:

- **conflict rows exist and at least one `e` has a barrier class other than `none`** ⇒ that edge should have
  entered `barriers` and did not. **Missing barrier — proven, with the edge named.**
- **conflict rows exist and every `e` has barrier class `none`** ⇒ two certified faces meet across an edge
  with no separator at all. The reads, not the barrier set, are wrong. **Mis-attribution — proven.**
- **no conflict rows, and some component has zero established owners** ⇒ neither branch; the component is
  unreachable from any seed, a third mechanism, and the census names the component.
- **no conflict rows and every component has exactly one owner** ⇒ the derivation succeeds and 398 is green.

Every outcome is informative and the branches are exhaustive. **This is the falsifiability condition
`LESSONS.md` 110 requires, stated before the measurement is built rather than after it fails.**

The census is published on the failure path — it is computed *before* and independently of the singleton check
that rejects — so it cannot be defeated the way D3 was.

### CH9 — witnesses and selector

Selector **403**, with selector **401** as its exact byte-identical 401-line prefix and selector **397** as the
frozen prefix of that. Two new gating identities:

- **402** `SurfaceCutGraph.CertifiedOwnerConflictCensusPublishesOnOwnershipFailure` — on the mechanical
  production fixture, the census is published, its rows carry a barrier class, and the certificate is returned
  rather than replaced by an error. Asserts *publication*, never a particular value.
- **403** `SurfaceCutGraph.CertifiedOwnerConflictCensusNamesANonBarrierEdgeSeparatingCertifiedFaces` — the
  independent falsifiability witness: on a constructed fixture with a known non-barrier edge between two known
  certified faces, that exact edge appears in the census with the expected barrier class. Splits *can* from
  *does* per `LESSONS.md` 116, as ordinals 399/400 did for their rules.

Ordinal **385**'s assertions are **replaced in place** — ordinal retained, gating, name unchanged — to observe
the relocated certified-owner evidence instead of the deleted seed. Its current subject was deliberately
removed by DEFN-R3.2 and cannot be restored; DEFN-R3.7 already set this precedent for ordinal 393.

Ordinal **398** stays gating and is **expected to remain RED**. It states the real open problem and must not be
relaxed, split, or made non-gating to obtain a green turn.

### Prohibited in CB28

1. Changing any accepted identity 1–365, or any byte of selector 397 or the first 401 lines of selector 403.
2. Weakening `proves_cellularity()`. Totality of the owner map remains required.
3. Weakening or relaxing ordinals **397**, **398**, **399** or **400**.
4. "Fixing" the ownership derivation — adding a barrier, changing the attribution rule, or altering
   `build_source_face_component_partition` — before CH8 has measured which branch is true. **CB28 measures;
   it does not correct.**
5. Reverting CB21, CB25, CB26 or CB27. CB27's plan-side relocation is correct and stays.
6. Executing any Directional runtime.

---

## 8. Predictions — recorded as predictions, not authorizations

I predict CH8 will find **conflict rows whose edges have barrier class `none`** — mis-attribution rather than a
missing barrier. Reason: the three seeds `[0,1,3]` are read at *arc* darts and attributed to whole source
faces, and `add_owner` attributes `orbitByDart[2*arc.id.index() + (forward ? 0 : 1)]` to a face on the strength
of `face_orients_edge_forward` alone. That is an orientation convention, and `LESSONS.md` section 5 records
that orientation conventions in this codebase are mesh-owned and have been got wrong before.

**This reverses the prediction I recorded at DEFN-R3**, where I expected the missing-barrier branch. I state
the reversal explicitly rather than quietly: the new reason is the attribution mechanism, which I had not read
at DEFN-R3.

Neither prediction authorizes anything. CH8 reports whichever branch it measures, and only the review that
reads it may freeze a correction.

---

## 9. Consolidation performed

Per `CLEAN_UP_POLICY.md` §"Document consolidation — every REVIEW turn". Durable facts were verified present in
this record, `Regression_Root_Cause_Tracker.md`, `ORIENTATION.md`, `M3_CP4c_Current_And_Forward.md` and
`CHANGELOG.md` **before** any fold. Folded into `M3_CP4c_Consolidated_Record.md` with an index entry each:

- `Architecture_M3_CP4c3_TB23_R1_Artifact_Only_Test_Benchmark_Report.md` — superseded runtime authority;
- `Architecture_M3_CP4c3_TB23_R1_Independent_Review_Record.md` — superseded review authority (CE0–CE8);
- `Architecture_M3_CP4c3_TB24_Artifact_Only_Test_Benchmark_Plan.md` — consumed evidence contract.

Retained as current authority: `Architecture_M3_CP4c3_TB24_Artifact_Only_Test_Benchmark_Report.md`,
`Architecture_M3_CP4c3_CB27_Code_Build_Report.md` (the package under review), this record,
`M3_CP4c_Current_And_Forward.md`, `M3_CP4c_Frozen_Definitions.md`, `Required_Green_Selector_Manifest.md`,
`M3_CP4c_Consolidated_Record.md`, and every `Required_Green_Selector_*.txt`.

## 10. Lessons added

`LESSONS.md` **120** — a diagnostic must not be gated on the success of the thing it diagnoses.
`LESSONS.md` **121** — moving a computation to the correct authority does not give it more information.

## 11. Exact successor

**`M3-CP4c-3-CB28`** under **CH6–CH9**, Code + Build, runtime-free, GMP/GMPXX linked. No runtime, no
package repair, no ownership correction, no accepted-prefix change.
