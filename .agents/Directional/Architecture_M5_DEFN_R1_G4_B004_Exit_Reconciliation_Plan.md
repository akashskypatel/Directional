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

**Reviewing-agent evidence census (to be confirmed or refuted from bytes, not trusted):** the only positive isolation-seam materialization row in selector448 is ordinal 186, `SurfaceCellIsolationSeamCertificateAuthority.ReciprocalIsolationSeamCertificateMaterializes` (`tests/SurfaceCellTransitionQuotientTests.cpp:2288`). It is **single-isolation**: it asserts exactly one `isolationSeamTransportCertificates()` entry and `consumedInternalIsolationSeams == 1`. Ordinals 183-185 and 187-188 are typed-failure rows on the same fixture. 210, 237, 239, 240, 242, 253 and 254 are source-classification and transport rows. The M5 torus witness is one topology region cut by HardFeature edges, not isolation seams. No accepted row is known to prove produced **multi**-isolation authority.

## 2. Required definition outputs

1. **Exact meaning.** State, in current product vocabulary, what "positive multi-isolation quotient relation/certificate witness" requires. The vocabulary includes `SurfaceIsolationSeamTransportCertificate`, isolation sheets, `SourceTopologyRegions`, periodic relations, `SelectedRelationPathCertificate` and `consumedInternalIsolationSeams`. Derive the meaning from M4-DEFN §11.2, REORIENTATION §9, `DESIGN.md` §14 M5/M6, AR-06 and the current headers. Freeze the minimum discriminator: produced by the relation producer (not direct/draft/helper), at least **two** distinct isolation authorities with explicit owners and certificates, and each consumed exactly once.
2. **Census.** Classify every candidate selector448 row and any relevant unexecuted source test as produced or direct, single or multi, positive or negative. Conclude whether accepted evidence already satisfies item 1.
3. **Exactly one disposition:**
   - **A — already satisfied.** Name the accepted rows. Freeze them as §13.1 conjunct 8. The successor Review may then finalize M5 closure, and `M6-DEFN` follows.
   - **B — M5-producible, not yet proved.** Freeze a bounded `M5-CP4` focused-production contract. It must cover the witness and its independent selection authority, the produced-not-direct precondition, and discriminators including an owner-removal or misassignment tamper that rejects typed. Selector growth follows the §13.3 precommit → publication → fresh execution → Review sequence. The successor is the first `M5-CP4` Code + Build.
   - **C — not M5-producible.** Re-home the obligation only with a **concrete stage-dependency reason**: which M6 stage authority the M5 relation producer lacks, and why. Follow the precedent of DEFN-R2's closed-complex re-homing, which arrived "with a concrete mechanism and a checkpoint". Amend M4-DEFN §11.2 in place, striking and citing. Record it as a priced produced-witness debt (project debt 1 → 2) owned by named M6 checkpoints. Amend the M6-DEFN plan so M6 owns both halves.
4. **Amend `Architecture_M5_Frozen_Definitions.md` §13.1** to match the disposition, and state M5's closure status explicitly.
5. **Re-adjudicate `M5-DEFN-REV-OBS-01`**, whose TB2-REV discharge is withdrawn in part. Under A or C it may be discharged with the full exit. Under B it stays open with `M5-CP4`.

## 3. Falsifiers

- Crediting single-isolation ordinal 186, or any direct/draft/helper row, as multi-isolation production evidence.
- Treating the torus's two same-region periodic relations as "multi-isolation" without showing isolation-seam authority.
- A re-home that names no specific missing M6 stage authority. That is deferral, not ownership.
- Declaring the obligation void because `DESIGN.md` §14 M5 does not list it, without amending M4-DEFN §11.2 and REORIENTATION §9 where it is stated.
- Any product/test/fixture/selector/CMake/benchmark mutation, compile or runtime.

## 4. Stop rules

- If "multi-isolation" cannot be given one exact meaning from primary authority, stop **BLOCKED** and state the precise question for the user.
- If disposition B needs a new fixture or field whose admissibility cannot be independently validated before implementation, stop and say so.
- Do not bundle `M6-DEFN` work, the dormant CB14 identities, or any other M6 item into this turn (`LESSONS.md` 170).

## 5. Completion evidence

The Definition record must cover items 1-5 and include the `REVIEW_TURN_POLICY.md` §5 closeout block, which applies to DEFN turns. `review_check.py boundary` must PASS. The record must name exactly one successor with its own falsifiers, and set the `STATUS` beacon per `Durable_Handoff_Policy.md` item 15.
