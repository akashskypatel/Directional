# M3-CP4c-3-TB35 Independent Review Record

## Status

**COMPLETE / STATIC / NO RUNTIME / NO COMPILE / NON-STABLE / ACCEPTED PREFIX RESTORED / FRONTIER PROVED FROM SOURCE.**

`M3-CP4c-3-TB35-REV` is evidence-only review. It executed no Directional runtime, no compile, no package operation,
and mutated no product, test, fixture, benchmark, build or selector byte.

**TB35 is promoted to current valid semantic runtime authority**: selector **409**, **402 PASS / 7 RED**, accepted
**1–365 = 365/365**, RED `[366, 367, 368, 369, 370, 374, 398]`. All 409 rows selected exactly one test, zero
timeouts, all three byte+mode censuses identical pre/post.

**The accepted prefix is restored.** Ordinal **312 PASS**, and ordinal **409 PASS** — reaching and satisfying its
re-aimed oracle. CV2 and CV3 are both discharged.

**And the frontier is now proved from source, not derived.** A plan region's boundary **is a face-walk orbit**, an
ordered single closed walk by construction. `ClosedBeforeEnd` therefore **cannot** be detecting a genuine
multi-walk on a plan region — while it **is** a valid rejection for a synthetically assembled region, which is
exactly what ordinal 312 constructs. §2 proves both halves, and they reconcile TB33-REV and TB34-REV instead of
choosing between them.

`review_check.py authority 23a753a83f0eda0447172ce96bcd3180bf95ae8a` — **ALL CHECKS PASSED**.

---

## 1. CW0 — CV2 and CV3 discharged

| Frozen check | Outcome |
|---|---|
| **CV2** — ordinal 312 PASS, accepted prefix 365/365 | **HELD.** The rejection is restored and now raises `RegionBoundaryNotSingleWalk` **with** `regionBoundaryWalkReason = ClosedBeforeEnd`, so the accepted witness is satisfied *and* the reason is named. |
| **CV3** — ordinal 409 reaches its re-aimed oracle | **HELD.** 409 PASS. Its body requires `RegionBoundaryNotSingleWalk`, typed `ClosedBeforeEnd`, the **second-loop first arc locus**, and projected `ClosedBeforeEnd`. Its PASS proves the **shared-start multi-walk shape is constructible and reaches the oracle** — the reachable negative CV3 asked for. |
| 390/393/404/406/407/408 PASS | **HELD**, all six. |
| retired-code silence | **HELD.** Zero `TraceArcDoesNotSeparateItsSides`, zero `UncutFaceComponentOrbitSeedNotUnique`. |
| ownership when published | **HELD.** `sourceFaceCount=300; established=300; unavailable=0; conflicting=0`. |
| 366/367 discriminator | **CV6's first branch.** Both RED at `RegionBoundaryNotSingleWalk`, `regionFrontierFailureStage=RegionCertification`, `regionBoundaryWalkReason=ClosedBeforeEnd`, arc **3** — **not** `ArcChainBroken`. |

**CV6's falsifier is settled: the pinch reading is confirmed and the chain reading is refuted.** The mechanical
fixture's boundary closes before its arcs are consumed; it does not fail to chain.

The **stable event recorded at TB34 stands.** Repairing a regression does not erase the incidence, and this record
does not decrement it.

---

## 2. CW1 — the frontier, proved from source

TB33-REV derived that the removed disjunct rejected a legitimate configuration; TB34-REV proved from an accepted
witness that the rejection is load-bearing. **Both are correct, about different inputs**, and the missing fact is
now established.

### 2.1 A plan region's boundary is a face-walk orbit, and a face-walk orbit is a single closed walk by construction

`build_regions` creates each draft as

```cpp
drafts.push_back(RegionDraft{orbit, walk.orbits[orbit]});          // :986
```

and the draft's boundary is moved into the region unmodified (`:1450`). Elsewhere the code even *identifies* a
region by that equality — `if (walk.orbits[orbit] != region.boundary) continue;` (`:379`) — so the invariant is
already relied upon.

`walk.orbits[orbit]` is produced by the face walk (`EmbeddedGraphTopology.cpp:1746–1774`): starting from a dart, it
follows `successor[current]` and appends each dart until it returns to `start`, then applies `canonicalize_cycle`,
which only **rotates** the cycle to its lexicographically least starting position. The result is therefore an
**ordered traversal of exactly one closed walk**.

**Consequence:** for a region built this way, `region.boundary` cannot be two closed walks. `ClosedBeforeEnd` — the
walk reaching its start node while arcs remain — is exactly what a face-walk orbit does whenever its boundary
passes through a node more than once, which bridges, cut vertices and this fixture's **ten terminal slits**
routinely produce. **On a plan region, `ClosedBeforeEnd` is always a false rejection.**

### 2.2 And it is a true rejection for a synthetic region

Ordinal 312 constructs a region directly, not from a face walk, and its boundary genuinely is two loops. Ordinal
409 — now PASSing — constructs the *shared-start* variant and requires the same rejection with the same typed
reason. **For a boundary that did not come from a face-walk orbit, nothing guarantees single-walk-ness and the
check is the only thing that catches it.**

### 2.3 The defect is that the predicate cannot see provenance

`validate_single_boundary_walk` treats both inputs identically. It has no way to know whether the boundary it is
handed carries the face-walk guarantee. **That is the defect** — not the presence of the check, and not its
absence.

`ArcChainBroken` and `WalkNotClosed` are unaffected: they are meaningful integrity checks on **any** boundary, and
a face-walk orbit satisfies both by construction, so keeping them costs nothing and guards against corruption.

### 2.4 What remains genuinely unknown

TB34 showed that when the rejection was bypassed, the mechanical plan reached **`RegionEulerCharacteristicNotOne`**.
If §2.1 is right, that is a **second, independent** finding and not a restatement of the first: χ must be computed
over a boundary walk that may revisit nodes, and a computation that counts boundary vertices or edges without
multiplicity will get it wrong.

**I do not know which it is**, and this review does not decide it. `M3-CP4c3-TB34-REV-CAND-03` stays open with its
scope now split: the boundary-walk rejection is explained; the Euler result is not.

---

## 3. CW2 — classification of the 7 RED ordinals

| Ordinal | Classification |
|---|---|
| 366, 367 | **The frontier.** `RegionBoundaryNotSingleWalk` / `ClosedBeforeEnd` at arc 3 — a **false rejection** of a face-walk orbit, per §2.1. Owner: **DEFN-R5**. |
| 398 | **Carried sphere surface.** Not an ownership gate. Owner: `M3-CP4c2-TB-X2-CAND-04`. Untouched. |
| 368, 369, 370, 374 | **Unchanged carried surfaces** with separate owners. Untouched. |

Accepted **1–365 = 365/365**; ordinals **312, 390, 393, 404, 406, 407, 408, 409** all PASS.

---

## 4. CW3 — stable accounting

**No stable event, category, or recurrence is added, and none is removed.** Totals remain **45 events / 14
categories / 31 recurrences**, produced-witness debt **5**, semantic M3 package count **100**.

1. accepted **365/365** restored; ordinal 312 recovered. **Recovery does not decrement the TB34 incidence** — the
   historical event stands, as this project has held since the M1 closure records;
2. ordinal 409 recovered by re-aiming its fixture at the reachable shape; its assertions were replaced in place and
   nothing it legitimately owns was relaxed;
3. 366/367's change from `RegionEulerCharacteristicNotOne` back to `RegionBoundaryNotSingleWalk` is the expected
   consequence of the CV2 restore, not a regression;
4. 368/369/370/374/398 are already-counted carried surfaces.

---

## 5. CW4 — candidates

**Closing, runtime-proved.**

- `M3-CP4c3-TB34-REV-CAND-01` — the boundary-walk rejection is load-bearing. **CLOSED.** Restored; ordinal 312 PASS
  and the accepted prefix is 365/365.
- `M3-CP4c3-TB34-REV-CAND-02` — ordinal 409 asserted an unconstructible fixture. **CLOSED.** Re-aimed at the
  shared-start shape, which is constructible, and it PASSes.

**Carried, re-scoped.**

- `M3-CP4c3-TB34-REV-CAND-03` — **ACTIVE / GATING / PRODUCT**, now **split**: the `ClosedBeforeEnd` rejection on
  the mechanical fixture is **explained** by §2.1 as a false rejection of a face-walk orbit; the
  `RegionEulerCharacteristicNotOne` result seen at TB34 is **not yet explained** and stays open. Owner:
  **DEFN-R5**.
- `M3-CP4c3-TB33-REV-CAND-01` — **RESOLVED AS RECONCILED, not refuted.** TB34-REV recorded it refuted; that was
  right about ordinal 312's synthetic region and wrong as a general statement. §2 supplies the missing
  distinction. This record supersedes both readings.

**Unchanged.** `M3-CP4c3-TB26-REV-CAND-04` / `M3-CP4c3-DEFN-R3-CAND-01`, `M3-CP4c3-TB30-REV-CAND-02`,
`M3-CP4c3-TB27-REV-CAND-02`, `M3-CP4c3-TB22-REV-CAND-01`, `M3-CP4c3-TB18-REV-CAND-01`, `M3-CP4c3-TB7-CAND-02`,
`M3-CP4c3-DEFN-R2-CAND-01`, `M3-CP4c3-TB6-CAND-01`, `M3-CP4c2-TB-X2-CAND-04` (also 398),
`M3-CP4c2-TB-X2-R10-CAND-01`, `M3-CP4c2-TB-X2-R8-CAND-02`, finalize/contact fall-through.

**New.**

- `M3-CP4c3-TB35-REV-CAND-01` — **NEW / ACTIVE / GATING / ARCHITECTURAL.** `validate_single_boundary_walk` cannot
  distinguish a boundary that carries the face-walk single-walk guarantee from one that does not, and applies the
  same `ClosedBeforeEnd` rejection to both. Owner: **DEFN-R5**.

---

## 6. CW5 — frozen successor: `M3-CP4c-3-DEFN-R5`

**A definition turn, not a Code + Build turn**, and deliberately so. The question is *what guarantees a region
boundary carries and who may assume them* — a contract between the face walk that produces boundaries and the
validator that checks them. That is the kind of decision Part VIII's chain exists for, and `DEFN` absorbs
REVIEW + PLAN so the same turn can freeze the implementing measures.

**It is also the safeguard this frontier has earned.** Two Code + Build turns have now flipped this one predicate
in opposite directions, and one of them cost an accepted-green regression. The next change to it will be made by a
turn whose job is to write down the contract first.

### What DEFN-R5 must decide

1. **The face-walk guarantee.** Record as normative that `walk.orbits[orbit]` is an **ordered single closed walk**
   — `successor` traversal to closure, then rotation-only canonicalization — and that a plan region built from one
   inherits that guarantee. Cite `EmbeddedGraphTopology.cpp:1746–1774`, `GlobalTopologyPlan.cpp:986`, `:1450`, and
   the existing reliance at `:379`.
2. **Provenance on the boundary.** Decide how a region declares whether its boundary came from a face-walk orbit.
   The validator must be able to see it; today it cannot, which is `M3-CP4c3-TB35-REV-CAND-01`.
3. **The scope of each reason.** `ClosedBeforeEnd` rejects **only** a boundary without the guarantee.
   `ArcChainBroken` and `WalkNotClosed` remain in force for **all** boundaries — a face-walk orbit satisfies both
   by construction, so retaining them costs nothing and still catches corruption.
4. **What must not change.** Ordinal **312** keeps its contract — a synthetic multi-walk region is still rejected
   with `ClosedBeforeEnd` — and ordinal **409** keeps its shared-start oracle. Neither may be weakened, re-scoped,
   or made conditional on the fixture.
5. **The Euler question is separate.** `RegionEulerCharacteristicNotOne`, seen at TB34 once the rejection was
   bypassed, is **not** decided here. DEFN-R5 states whether χ is computed over a walk that may revisit nodes and,
   if the answer is not established, freezes a measurement rather than a correction.

### What DEFN-R5 must not do

1. **Change any product behaviour itself.** It is a definition turn; the implementing Code + Build turn follows.
2. **Weaken or re-scope ordinal 398**, or touch 368/369/370/374.
3. **Re-open source-face ownership** — closed at 300/300 with every component uniquely seeded — or any retired
   guard.
4. **Correct the Euler result** before it is measured against the provenance decision.
5. Change any accepted identity 1–365 or any byte of selector 397–409.

### Falsification, to be carried into the implementing turn

- If, after provenance is honoured, 366/367 still reject at `ClosedBeforeEnd`, §2.1 is wrong and the mechanical
  region's boundary did **not** come from a face-walk orbit.
- If they clear and the plan stops at `RegionEulerCharacteristicNotOne`, §2.4's second finding is confirmed and
  becomes the frontier.
- If ordinal **312** or **409** goes RED, the provenance rule was applied to a synthetic boundary and must be
  narrowed.
- **Accepted prefix 365/365 is a stop condition, not a finding.** Any accepted RED halts the turn.

---

## 7. A note on this frontier's history

One predicate has now been removed, restored, and — pending DEFN-R5 — is about to be scoped. That is not three
opinions; it is a contract that was never written down. TB33-REV read the production input and concluded the check
was wrong; TB34-REV read an accepted witness and concluded it was right; each was reasoning about a different
provenance, and neither could see the other's input from where it stood.

The cost was one accepted-green regression, caught by the accepted prefix on the first runtime after the change.
The remedy is not more caution in reviews — it is writing the guarantee down where the validator can see it, which
is what DEFN-R5 does.

## 8. Consolidation performed

Per `CLEAN_UP_POLICY.md` §"Document consolidation — every REVIEW turn". Durable facts were verified present in this
record, `Regression_Root_Cause_Tracker.md`, `ORIENTATION.md`, `M3_CP4c_Current_And_Forward.md` and `CHANGELOG.md`
before any fold. **Preserved in §§1–2 above:** the restored accepted prefix, ordinal 409's re-aimed oracle, the
`ClosedBeforeEnd` discriminator outcome, the ownership census `300 / 0 / 0`, and the source proof that a region
boundary is a face-walk orbit.

Folded: `Architecture_M3_CP4c3_TB34_EXEC_Report.md` (superseded runtime authority — the run that carried the
accepted-prefix regression), `Architecture_M3_CP4c3_TB34_Artifact_Only_Test_Benchmark_Plan.md` (consumed contract),
`Architecture_M3_CP4c3_TB34_Independent_Review_Record.md` (superseded review authority, CV0–CV6 — **its stable
event stands; its refutation of `TB33-REV-CAND-01` is reconciled here**),
`Architecture_M3_CP4c3_CB40_Code_Build_Report.md` (consumed build report — CV2/CV3 discharged).

Retained as current authority: `Architecture_M3_CP4c3_TB35_EXEC_Report.md` (**the valid semantic runtime
authority**), `Architecture_M3_CP4c3_TB35_Artifact_Only_Test_Benchmark_Plan.md`, this record,
`M3_CP4c_Current_And_Forward.md`, `M3_CP4c_Frozen_Definitions.md` (**Part VIII operative; DEFN-R5 appends as Part
IX**), `Required_Green_Selector_Manifest.md`, `M3_CP4c_Consolidated_Record.md`, and every
`Required_Green_Selector_*.txt`. **Never folded:** `tools/m3_cp4c3_artifact_only_harness.sh`.

## 9. Lessons added

`LESSONS.md` **146** — when a checker flips twice, the missing artefact is the contract, not the verdict.

## 10. Exact successor

**`M3-CP4c-3-DEFN-R5`** — a definition turn appending **Part IX** to `M3_CP4c_Frozen_Definitions.md`: record the
face-walk single-walk guarantee, decide how a region boundary declares its provenance, scope each typed reason to
the provenance it applies to, preserve ordinals 312 and 409 unchanged, and separate the Euler question from the
boundary-walk one.
