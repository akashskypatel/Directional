# M5-DEFN-R1 — `G4-B004` M5-Half Exit Reconciliation Definition Plan

**Turn:** `M5-DEFN-R1`
**Boundary:** runtime-free definition only. No product/test/fixture/selector/CMake/benchmark mutation, compile or Directional runtime.
**Predecessor:** `M5-CP3-TB2-REV` plus reviewing-agent addendum. Selector448 is ACCEPTED, the CB20 package is promoted and §13.1 conjuncts 1-7 are accepted. **M5 closure is HELD.**
**Carried obligation:** `M5-CP3-TB2-REV-OBS-01` (tracker).

## 1. Why this turn exists

A frozen normative record assigns M5 an obligation that no M5 record ever absorbed:

- `Architecture_M4_DEFN_Frozen_Definitions.md` §11.2: "**M5 owns the focused positive multi-isolation quotient relation/certificate witness.** It must prove the relation producer emits positive multi-isolation authority with explicit owners/certificate, matching `REORIENTATION_PLAN.md` §9." The same section gives M6 the other half: prove "the M5-produced authority is materialized/consumed exactly once and independently verified".
- `REORIENTATION_PLAN.md` §9 (durable): "Produce positive multi-isolation quotient evidence where required", and "**M5 owns the focused positive multi-isolation quotient relation/certificate production witness.**"
- `ROADMAP.md` `G4-B004` row: "M5 focused production + M6 representative consumption".

`Architecture_M5_Frozen_Definitions.md` never mentions `G4-B004` or multi-isolation. The §13.1 exit theorem omits it. `M5-CP3-TB2-REV` closed M5 without adjudicating it and discharged `M5-DEFN-REV-OBS-01`, the observation created precisely because M5's exit was "stated in several places and nowhere in full". The M6-DEFN plan also omitted the M6 half. Meanwhile ORIENTATION §7 and TODO still showed the M5 half as M5-owned and open after the "M5 CLOSED" verdict.

**Reviewing-agent evidence census, corrected at the second reviewing-agent pass. Confirm or refute it from bytes; do not trust it.** The first pass called ordinal 186 "the only positive isolation row", "single-isolation", and ineligible for credit. That prejudged the semantic question this turn exists to settle, and it was also incomplete. The facts are:

- **Gated, producer-built, positive:**
  - Ordinal 186 `SurfaceCellIsolationSeamCertificateAuthority.ReciprocalIsolationSeamCertificateMaterializes` (`tests/SurfaceCellTransitionQuotientTests.cpp:2288`) runs on `split_isolation_fixture()`. That fixture is `build_surface_cell_network` plus `require_produced`, on a 2-face square with **test-supplied** sheet labels `{0,1}`. It asserts one certificate joining two **different** sheets (`firstSheet != secondSheet`), materialization success, and `consumedInternalIsolationSeams == 1`.
  - Ordinal 239 `SurfaceCellsPhase10.ExactReciprocalTransportCrossesSourceAdjacentIsolationSeam` is also producer-built and materialized. It is also one certificate across two sheets, with consumed count equal to the certificate count.
- **Gated, producer-built, typed rejections on the same fixture:** ordinals 183-185 and 187-188 (duplicate, missing, nonreciprocal, wrong-owner and wrong-sheet certificate).
- **Compiled but never executed in any gate or record (no credit until gated):**
  - `SurfaceCellTransitionQuotient.MultiIsolationMaterializationRetainsAllLocalSheets` (`:2414`). It uses **"multi-isolation" to mean a lineage vertex retaining ≥2 isolation sheets**, on the same single-seam fixture.
  - `SurfaceCellsPhase10.ExactCommittedTorusDoesNotTreatIsolationSeamAsBoundedDiskBoundary` (`tests/SurfaceCellsPhase10Tests.cpp:4436`). It is a produced pipeline torus asserting `InternalIsolationSeamCount > 0`, a multi-sheet region with an internal seam, every certificate and periodic relation consumed, and isolation-sheet lineage on every output vertex.
- `tests/TESTING_STRATEGY.md` §8.4 lists "multi-isolation relation graphs" under occurrence quotient, which is M6 scope.

So "multi-isolation" has at least two live readings: **≥2 isolation sheets** joined by certified isolation relations, or **≥2 distinct isolation seams/relations** in one quotient. Under the first, rows 183-188 may already be the focused positive-plus-tamper witness (disposition A). Under the second, no gated row qualifies.

## 2. Required definition outputs

1. **Exact meaning.** State, in current product vocabulary, what "positive multi-isolation quotient relation/certificate witness" requires. The vocabulary includes `SurfaceIsolationSeamTransportCertificate`, isolation sheets, `SourceTopologyRegions`, periodic relations, `SelectedRelationPathCertificate` and `consumedInternalIsolationSeams`. Derive the meaning from M4-DEFN §11.2, REORIENTATION §9, `DESIGN.md` §14 M5/M6, AR-06 and the current headers. Choose between the readings in §1, or state a better one, **with cited authority**, and freeze the minimum discriminator for it. Decide explicitly whether a producer-built fixture with test-supplied sheet labels counts as "the relation producer emits" for a *focused* witness. M4-DEFN §11.2 says "focused" and gives *representative* evidence to M6.
2. **Census.** Classify every candidate selector448 row and any relevant unexecuted source test as produced or direct, single or multi, positive or negative. Conclude whether accepted evidence already satisfies item 1.
3. **Exactly one disposition:**
   - **A — already satisfied.** Name the accepted rows. Freeze them as §13.1 conjunct 8. The successor Review may then finalize M5 closure, and `M6-DEFN` follows.
   - **B — M5-producible, not yet proved.** Freeze a bounded `M5-CP4` focused-production contract. It must cover the witness and its independent selection authority, the produced-not-direct precondition, and discriminators including an owner-removal or misassignment tamper that rejects typed. Selector growth follows the §13.3 precommit → publication → fresh execution → Review sequence. The successor is the first `M5-CP4` Code + Build.
   - **C — not M5-producible.** Re-home the obligation only with a **concrete stage-dependency reason**: which M6 stage authority the M5 relation producer lacks, and why. Follow the precedent of DEFN-R2's closed-complex re-homing, which arrived "with a concrete mechanism and a checkpoint". Amend M4-DEFN §11.2 in place, striking and citing. Record it as a priced produced-witness debt (project debt 1 → 2) owned by named M6 checkpoints. Amend the M6-DEFN plan so M6 owns both halves.
4. **Amend `Architecture_M5_Frozen_Definitions.md` §13.1** to match the disposition, and state M5's closure status explicitly.
5. **Re-adjudicate `M5-DEFN-REV-OBS-01`**, whose TB2-REV discharge is withdrawn in part. Under A or C it may be discharged with the full exit. Under B it stays open with `M5-CP4`.

## 3. Falsifiers

- Crediting any row under a reading this turn has not frozen with cited authority, whichever way the reading goes.
- Crediting a never-executed identity (the two ungated tests in §1, or the dormant CB14 identities) as accepted evidence. Under disposition A they may only be *routed* to a gating turn.
- Crediting a direct/draft/helper product row as production evidence.
- Treating the torus's two same-region periodic relations as "multi-isolation" without showing isolation-seam authority.
- A re-home that names no specific missing M6 stage authority. That is deferral, not ownership.
- Declaring the obligation void because `DESIGN.md` §14 M5 does not list it, without amending M4-DEFN §11.2 and REORIENTATION §9 where it is stated.
- Any product/test/fixture/selector/CMake/benchmark mutation, compile or runtime.

## 4. Stop rules

- If "multi-isolation" cannot be given one exact meaning from primary authority, stop **BLOCKED** and state the precise question for the user.
- If disposition B needs a new fixture or field whose admissibility cannot be independently validated before implementation, stop and say so.
- Do not bundle `M6-DEFN` work, the dormant CB14 identities, or any other M6 item into this turn (`LESSONS.md` 170).

## 5. Completion evidence

The Definition record must cover items 1-5 and include the `REVIEW_TURN_POLICY.md` §5 closeout block, which applies to DEFN turns. `review_check.py boundary` must PASS, and so must `review_check.py ledgers --base <this turn's starting HEAD>`. The tracker and CHANGELOG are append-only: edit them, never write the whole file (`LESSONS.md` 176). The record must name exactly one successor with its own falsifiers, and set the `STATUS` beacon per `Durable_Handoff_Policy.md` item 15.
