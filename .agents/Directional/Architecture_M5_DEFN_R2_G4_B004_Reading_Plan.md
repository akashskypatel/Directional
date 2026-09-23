# M5-DEFN-R2 — `G4-B004` M5-Half Reading Re-adjudication Plan

**Turn:** `M5-DEFN-R2`
**Boundary:** runtime-free definition only. No product/test/fixture/selector/CMake/benchmark mutation, compile or Directional runtime.
**Predecessor:** `M5-DEFN-R1-REV`, which did **not** accept DEFN-R1's disposition A (`Architecture_M5_DEFN_R1_G4_B004_Review_Record.md`). M5 closure is held. Selector448, package `10771899191 / cef1c6ee…`, §13.1 conjuncts 1-7, accounting 51/14/37 and debt 1 are unaffected.
**Carried obligations:** `M5-CP3-TB2-REV-OBS-01` with the merged `M5-DEFN-REV-OBS-01` remainder.

## 1. Facts this turn starts from (re-verify; do not trust)

- **The obligation.** `Architecture_M4_DEFN_Frozen_Definitions.md` §11.2 says: "M5 owns the focused positive multi-isolation quotient relation/certificate witness. It must prove the relation producer emits positive multi-isolation authority with explicit owners/certificate". M6 owns representative consumption. `REORIENTATION_PLAN.md` §9 restates this.
- **Chronology.** Selector448 rows 186 (`ReciprocalIsolationSeamCertificateMaterializes`), 188 and 239 (`ExactReciprocalTransportCrossesSourceAdjacentIsolationSeam`) are in `M1_Full_Required_Green_Selector.txt`, so they were accepted at **M1**. `G4-B004` nevertheless stayed a persistent blocker after M1, and M4-DEFN assigned its M5 half as future work.
- **Family context.** All four `G4-B` blockers belong to the torus-production campaign: B001 torus `LocalSheetMismatch`, B002 torus rail pairing, B003 torus nonzero-Z4.
- **Census.**
  - Gated positive isolation rows: 186 and 239, both a single seam joining two test-labelled sheets.
  - Gated tamper family: 183-185 and 187-188.
  - Gated classification rows: 237, 240, 242, 253 and 254.
  - **Never executed:** `SurfaceCellTransitionQuotient.MultiIsolationMaterializationRetainsAllLocalSheets` (reads "multi-isolation" as ≥2 sheets in lineage on the single-seam fixture), and `SurfaceCellsPhase10.ExactCommittedTorusDoesNotTreatIsolationSeamAsBoundedDiskBoundary` (a pipeline torus with isolation seams in a multi-sheet region, plus consumed periodic relations).
- **No record** was found that states the original intent of `G4-B004` beyond its name. The search covered the durable set, the restored ledgers, the root squash and PR #8.

## 2. Required outputs

1. **Candidate readings.** Enumerate them and argue each from primary authority. At minimum:
   - **(a)** ≥2 isolation *sheets* on the M1 isolation-seam certificate surface. This is DEFN-R1's A, already satisfied at M1.
   - **(b)** Multi-sheet isolation authority *derived by the pipeline* rather than supplied by the test.
   - **(c)** Quotient (periodic) relations produced and consumed *inside a multi-isolation-sheet region*, fitting the torus family.
   - **(d)** ≥2 distinct isolation seams/relations.
2. **Freeze exactly one reading** with cited authority. It must survive both falsifiers in §3.
3. **Census** accepted and never-executed evidence under that reading, then choose exactly one disposition:
   - **A** — satisfied by named accepted rows.
   - **B** — a bounded `M5-CP4`. Gating an existing never-executed test counts as B: it needs its own selector precommit → publication → fresh execution → Review (§13.3 pattern), and any test sharpening needed for the reading is Code + Build work.
   - **C** — re-home to M6 with a concrete missing-stage-authority reason. Amend M4-DEFN §11.2 in place and price the debt 1 → 2.
4. **Amend `Architecture_M5_Frozen_Definitions.md`**: §13.1 conjunct 8 and §18. Align item 7 of the M6-DEFN plan.

## 3. Falsifiers (stated before the turn)

1. **Chronology.** A reading satisfied by evidence already accepted at M1 falsifies the definition. It survives only if a *primary record* explains why `G4-B004` remained a blocker, and was assigned to M5, after that evidence was accepted. Inference or plausibility is not a record.
2. **Non-redundancy.** A reading under which "multi-isolation" adds nothing to "positive isolation-seam certificate witness" falsifies the definition.
3. Crediting a never-executed identity as accepted evidence. Under B it may only be routed to a gating turn.
4. Crediting a direct/helper product, or treating M6 representative obligations as M5 credit.
5. A re-home without a named missing M6 stage authority.
6. Any product/test/fixture/selector/CMake/benchmark mutation, compile or runtime.

## 4. Stop rules

If no reading can be frozen that survives §3 on primary authority, **stop BLOCKED**. Publish `Status: BLOCKED` and state this exact question for the user:

> "What did `G4-B004` 'positive multi-isolation quotient witness' mean when it was recorded: (a) the M1 isolation-seam certificate family (already accepted at M1), (b) pipeline-derived multi-sheet isolation authority, (c) quotient/periodic relations produced and consumed inside a multi-isolation-sheet region (for example the committed torus), (d) two or more distinct isolation seams, or something else?"

Do not bundle `M6-DEFN` work (`LESSONS.md` 170).

## 5. Completion evidence and closeout discipline

- The Definition record must carry the `REVIEW_TURN_POLICY.md` §5 block, with `review_check.py boundary` and `review_check.py ledgers --base <turn start HEAD>` both PASS.
- **Publish COMPLETE only after every durable document is on the branch.** The COMPLETE beacon is the turn's final write, and no caller/trigger retirement or STATUS rewrite may follow it (`M5-DEFN-R1-REV-OBS-01`).
- The tracker and changelogs are append-only: edit them, and never drop facts from an existing entry (`LESSONS.md` 176).
