# M5-DEFN-R2 — `G4-B004` M5-Half Reading Re-adjudication Record

**Turn:** `M5-DEFN-R2`
**Date:** 2026-09-23 UTC
**Boundary:** runtime-free definition only. No product/test/fixture/selector/CMake/benchmark mutation, compile, or Directional runtime.
**Predecessor:** `M5-DEFN-R1-REV` — disposition A not accepted; M5 closure held.
**Disposition:** **B — freeze one bounded `M5-CP4` producer-witness checkpoint.**
**Frozen successor:** **`M5-CP4-CB1`** under `Architecture_M5_CP4_CB1_Multi_Isolation_Quotient_Witness_Plan.md`.

## 1. Re-derived authority

`Architecture_M4_DEFN_Frozen_Definitions.md` §11.2 deliberately splits `G4-B004` across stages:

- M5 must prove a **focused positive multi-isolation quotient relation/certificate producer witness** with explicit owner/certificate authority.
- M6 must later prove representative occurrence/embedding/verifier materialization and exact-once consumption of the M5-produced authority.

`REORIENTATION_PLAN.md` §9 independently places certificate-carrying chart/quotient relations, nonzero periodic Z4 authority, and positive multi-isolation quotient evidence in M5. `tests/TESTING_STRATEGY.md` §§8.2 and 8.4 distinguish a topology region from its local isolation sheets and place general multi-isolation relation-graph consumption at the later occurrence/materialization layer.

The accepted M1 rows therefore cannot be allowed to define away the word **quotient**. Rows 186/188/239 prove checked isolation-seam authority, but they use the split-square subject, whose sheet labels are test inputs and whose positive witness has one isolation seam and no same-subject periodic quotient owner.

## 2. Candidate readings and falsifier results

### (a) At least two isolation sheets on the M1 isolation-seam certificate surface — rejected

This is DEFN-R1's reading. It fails both pre-stated falsifiers:

1. **Chronology:** rows 186/188/239 were already accepted in M1, yet `G4-B004` remained open and M4-DEFN §11.2 later assigned its M5 half as future work. No primary record explains that persistence under this reading.
2. **Non-redundancy:** `SurfaceIsolationSeamTransportCertificate` rejects `SameSheet`, so every positive seam certificate already relates distinct sheets. Under this reading, “multi-isolation” adds no semantic requirement beyond the ordinary positive seam-certificate contract.

### (b) Pipeline-derived multi-sheet authority rather than test-supplied sheets — rejected as incomplete

This survives the chronology problem, because the M1 split fixture supplies `sourceFaceSheets={0,1}` rather than deriving them through the representative pipeline. However, primary authority does not say that provenance of sheet labels alone is the missing M5 obligation, and this reading still leaves **quotient relation/certificate** semantically unused. It is therefore too weak to freeze as `G4-B004`.

### (c) A pipeline-produced multi-isolation region that also owns quotient/periodic relation authority — selected, with the M5/M6 boundary made explicit

This reading fits all primary authority and survives both falsifiers when stated at the producer boundary:

> **A positive multi-isolation quotient relation/certificate witness is a pipeline-produced phase-front/A4 product in which one authoritative `SourceTopologyRegion` spans at least two distinct `IsolationSheetId` values and carries an internal isolation seam with a checked `SurfaceIsolationSeamTransportCertificate`, while that same topology region also owns at least one canonical periodic quotient relation (`SurfacePeriodicHolonomy`) and a `PeriodicCut` edge explicitly names that relation owner. M5 credit stops at production of this joined authority. Exact-once materialization, occurrence, embedding, and independent verifier consumption remain M6.**

The “same topology region” join is load-bearing. Independent facts from different subjects, regions, or stages do not satisfy it.

This reading survives:

- **Chronology:** the accepted M1 rows do not contain a same-subject periodic quotient owner and therefore never satisfied it.
- **Non-redundancy:** a positive isolation seam alone is insufficient; the region must also carry an explicitly owned quotient/periodic relation.
- **Stage ownership:** the required evidence is producer authority only. Materializer/occurrence/embedding/verifier acceptance is not pulled backward from M6.

### (d) Two or more isolation seams/relations — rejected as over-specific

No primary authority says “multi-isolation” means cardinality >=2 seams. `tests/TESTING_STRATEGY.md` places general multi-isolation relation graphs in occurrence/materialization testing, which supports keeping graph multiplicity out of the focused M5 minimum unless a later definition explicitly needs it. Requiring two seams would invent a count not stated by M4-DEFN or the M5 reorientation contract.

## 3. Evidence census under the selected reading

### 3.1 Accepted evidence — necessary but not sufficient

Accepted selector448 contains strong pieces of the selected contract, but no accepted identity joins them on one subject:

- rows 186/239 prove checked positive isolation-seam authority on the split-square producer subject;
- row 443 (`M5CP3.ProducedTorusPublishesTwoCanonicalPeriodicRelationsAndOwnedEdges`) proves the committed torus pipeline produces at least two canonical periodic relations and at least two `PeriodicCut` edges that name relation owners in their topology regions;
- rows 446/447 prove the produced torus nonzero-Z4 relation is consumable and typed-transform tamper rejects.

None of those accepted rows proves that **the same torus topology region** is both multi-isolation-with-checked-seam-certificate and the owner of a periodic quotient relation. Conjunct 8 is therefore not accepted by selector448.

### 3.2 Never-executed evidence — useful only as census

Two existing identities receive zero acceptance credit:

- `SurfaceCellTransitionQuotient.MultiIsolationMaterializationRetainsAllLocalSheets` uses the split-square fixture and proves multi-sheet output lineage, but it is a materialization-side identity with test-supplied sheets and no periodic quotient owner.
- `SurfaceCellsPhase10.ExactCommittedTorusDoesNotTreatIsolationSeamAsBoundedDiskBoundary` is much closer: it runs the committed torus pipeline, sees a multi-sheet topology region with an internal isolation seam, sees isolation certificates, and sees periodic holonomies. But it also asserts final materialization/output facts that belong to M6, and it does **not** explicitly bind a named periodic relation owner to the same multi-isolation topology region. *[Reviewing-agent precision note: this test has never been executed, and it runs the committed torus **without** the 18 row408 hard edges. It shows what the test would **assert**, not an observed fact about `torus_fixture()`, the CB1 subject. Feasibility of the join on that subject is unestablished until TB1; see the CB1 plan §7.2.]*

Gating either identity unchanged would therefore not be a truthful proof of the frozen M5 contract. The correct action is a bounded Code + Build test-authority turn that authors one focused producer-only identity.

## 4. Frozen disposition B — bounded `M5-CP4`

`M5-CP4` exists only to make conjunct 8 gate-enforced. It does not reopen accepted selector448 semantics, re-price debt, or authorize product correction.

The sequence is frozen:

1. **`M5-CP4-CB1`** — author exactly one focused producer-boundary test on the committed torus pipeline; compile/package only; selector448 unchanged; no Directional runtime.
2. **`M5-CP4-TB1-EXEC`** — artifact-only prepublication gate: selector448 plus the one new identity as 449 fresh exact-filter processes; no benchmark.
3. **`M5-CP4-TB1-REV`** — independent review. Only a green non-vacuous result may precommit exact selector449 bytes/order/hash with selector448 as an exact prefix.
4. **`M5-CP4-CB2`** — publish only the precommitted selector449 and compile/package unchanged reviewed semantics; no runtime.
5. **`M5-CP4-TB2-EXEC`** — execute published selector449 freshly, artifact-only, 449 exact-filter processes.
6. **`M5-CP4-TB2-REV`** — final independent acceptance. Only this Review may accept §13.1 conjunct 8 and close M5, then route to `M6-DEFN`.

A red prepublication gate does not authorize immediate product correction. Mandatory Review owns the diagnosis and any later correction turn.

## 5. Unchanged accepted authority and accounting

This definition changes no accepted runtime facts:

- selector448 remains 448 rows, SHA-256 `70ff08601bf244fcb4883e5d0601d5e7a3a44f52a8e855544a065c6ca5c75789`;
- accepted package/source remains `10771899191 / cef1c6ee26ca6fb6791f0e80a66f9b0dc441e0f1`;
- §13.1 conjuncts 1-7 remain accepted;
- stable accounting remains **51 events / 14 categories / 37 recurrences**;
- project produced-witness debt remains **1**, M6-owned. `M5-CP4` is a closure gate, not a new produced-witness debt.

## 6. Process observation

The turn selected `READ_MODE=snapshot` only after several repository-document reads had already been made through the connector. That violated `TOOL_USE_CONSERVATION_POLICY.md`'s pre-read gate. Once detected, piecemeal source/document inspection stopped and all substantive cross-file work proceeded from verified source-snapshot run `35929006744`, artifact `10780133120`, exact snapshot SHA `07a4ab641910a366068c6c4fc27c2b42591f7871`, with archive/file hashes verified locally. No semantic acceptance claim depends on the early reads. This is recorded as `M5-DEFN-R2-OBS-01`, a process-only non-stable observation and another instance of the existing setup-order/snapshot-threshold pattern; no new `LESSONS.md` number is created.

## 7. Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | n/a — Definition is runtime-free and selector448 is unchanged; accepted SHA remains `70ff08601bf244fcb4883e5d0601d5e7a3a44f52a8e855544a065c6ca5c75789`. |
| Decisive claims independently re-derived | M4-DEFN §11.2 stage split, REORIENTATION §9 M5 ownership, M1 chronology, split-square source, torus pipeline fixture, accepted row443 producer assertions, and the two never-gated candidate bodies were re-read from verified snapshot bytes. |
| Non-vacuity checked | Selected reading requires a same-region join between multi-isolation checked-seam authority and an explicitly owned periodic quotient relation; neither accepted M1 seam rows nor accepted torus quotient rows alone can satisfy it. |
| Prior obligations discharged/carried | `M5-CP3-TB2-REV-OBS-01`: definition frozen but closure gate still open; owner moves to `M5-CP4`. `M5-DEFN-R1-REV-OBS-01` remains recorded process history. |
| Stable accounting | 51 / 14 / 37; debt 1 M6-owned; accepted package/source `10771899191 / cef1c6ee...`; selector448 accepted, conjunct 8 not yet accepted. |
| New candidates/obligations recorded | `M5-DEFN-R2-OBS-01` process-only READ_MODE miss; `M5-CP4` closure gate frozen. Tracker updated; stable totals unchanged. |
| ORIENTATION currency line | `M5-DEFN-R2`, 2026-09-23 UTC. |
| ORIENTATION §3 / §4 / §7 / §8 | §3, torus witness, and §7 updated for frozen reading/CP4; §8 records the existing snapshot-threshold pattern instance, no new category. |
| CHANGELOG | Agent and root entries added. |
| ROADMAP | M5 updated to CP4 pending; exact next `M5-CP4-CB1`. |
| Selector manifest | n/a — no selector bytes/count/acceptance changed. |
| LESSONS | Existing lessons 152 (snapshot-threshold/setup order), 170 (do not bundle variables), 176 (durable ledgers), and 177 (chronology/non-redundancy definition review) cited; no new pattern. |
| Consolidation under CLEAN_UP_POLICY | n/a — no superseded per-turn current authority is eligible to fold in this Definition turn; the R2 record and CP4 plan are current. |
| Successor frozen | `M5-CP4-CB1`; falsifiers and stop rules are in `Architecture_M5_CP4_CB1_Multi_Isolation_Quotient_Witness_Plan.md`. |
| Turn boundary held | **PASS.** Runtime-free throughout; no product/test/fixture/selector/CMake/benchmark mutation, compile, or Directional runtime. Static run `35931631220` audited committed turn paths from `87d1a472...` and found no product/test/build or selector path. |
| review_check.py boundary | **PASS.** The exact snapshot-derived prepared delta passed before preservation/application. Remote static run `35931631220` then repeated the clean-checkout boundary gate after application; selector448 remained `70ff0860...c75789`. |
| review_check.py ledgers | **PASS** in remote static run `35931631220` with base `87d1a4725e0d35cc142755e7d30942f23b81afb2`; all four append-only ledgers had no >10% shrink. Result artifact `10781134166`, `runtimeExecution=false`. |
| Work preservation/application | Patch `Directional__M5-DEFN-R2__base-07a4ab641910__work-preservation.patch`, SHA-256 `534bd493324dd845c06b87358d9635c42abed27632671b01d09cc546a7279fd9`, was emitted before remote orchestration and applied by validated run `35931346607`; result artifact `10781496463` records applied commit `0eee93f88c151c916cefb307b5d11912e34e28b0`, exact patch/base verification, and `runtimeExecution=false`. The staged Drive file required owner cleanup and was permanently deleted through the connected Drive account. |
| Temporary-state cleanup | **PASS.** Required cleanup run `35931880115`, result artifact `10780938308`, produced cleanup commit `1667402564ffb0817473b2b8352ad85b20829d10` and removed the source-snapshot, patch-apply, and static-review trigger markers after both temporary workflow callers had already been deleted. |
| Tool-use ledger | **Partial/unknown after context compaction, reported rather than reconstructed.** Known categories: Files/start-file retrieval; GitHub connector status/orientation, source snapshot, caller/marker control, run/artifact evidence and cleanup; local container diff/hash checks; connected Drive staging/retirement; user-visible patch emission. |
| `STATUS` lifecycle maintained | `Turn=M5-DEFN-R2`; entry `IN_PROGRESS` at `2026-09-23T22:32:05Z`; final `COMPLETE -> M5-CP4-CB1` is reserved as the final repository write. |
| Pushed to origin, branch in sync | Documentation is on origin. Static run `35931631220` proved its trigger head equaled the remote branch; cleanup run `35931880115` then completed successfully and pushed cleanup commit `1667402564ffb0817473b2b8352ad85b20829d10`. After this closeout-evidence write, the only permitted repository mutation is the final `STATUS` COMPLETE beacon. |

---

## Independent verification addendum (reviewing agent)

Runtime-free. **UPHELD: reading (c) and disposition B stand. The successor `M5-CP4-CB1` is unchanged.** I made four corrections, listed at the end.

**The chronology and non-redundancy falsifiers pass on independent grounds.** Before M5, the committed torus produced **zero** periodic holonomies (frozen §8.1, M4 R3). No evidence accepted before M5 could therefore contain a periodic relation owned by a multi-isolation region, which is consistent with `G4-B004` staying open and being assigned to M5. The same-region join also gives "multi-isolation quotient" content that a bare seam certificate lacks.

**B over A is confirmed from test bodies, not names.** I scanned the bodies of all 448 selector448 identities. Only five touch both isolation certificates and periodic relations: 123, 124, 294, 299 and 406. All five are negative factory tests that pass `product.isolationSeamTransportCertificates()` and `product.periodicHolonomies()` through to `make`. None of the twelve torus rows (408, 443-448 and others) asserts isolation seams. So no accepted row proves the join.

**DEFN-R2's process met the rules that R1 broke.** The docs landed (23:01-23:08Z) before the COMPLETE beacon (23:09:03Z). The tracker entry was appended, not rewritten. My own `review_check.py ledgers --base 87d1a472` PASSes. The READ_MODE miss is correctly recorded as an existing-pattern instance.

**Corrections:**

1. **A never-executed test was presented as evidence.** §3.2 above and frozen §18 said the never-executed `ExactCommittedTorusDoesNotTreatIsolationSeamAsBoundedDiskBoundary` "sees" or "demonstrates" a multi-sheet region. It has never run, and it builds the committed torus **without** the 18 row408 hard edges. The CB1 subject, `torus_fixture()`, **includes** them. Sheets come from a flood-fill (`SurfaceCellTracing.cpp:7569-7632`) stopped by barriers, components, sharp bends and close-sheet conflicts. Row 240 forbids treating a hard feature as an isolation seam. Nothing observed shows that `torus_fixture()`'s single region spans ≥2 sheets with a non-hard-feature seam. A TB1 RED is a real outcome, not a remote one. Both passages are annotated in place.
2. **The CB1 plan was inconsistent with a compile-only turn.** Its stop rules 1 and 4 are runtime facts that CB1 cannot evaluate. Plan §7 now:
   - moves those rules to TB1/TB1-REV;
   - fixes the subject and prohibits a post-runtime switch (`LESSONS.md` 170, 177);
   - requires ordered, fact-naming asserts, so a RED localizes without another diagnostic CB;
   - requires a row-449 static owner and routing record for TB1.
3. **Frozen §11 was stale.** It still named `M5-DEFN-R2` as the current successor and cited a "§18 note" that this turn deleted. It is corrected to `M5-CP4-CB1`. This is the third time §11 or the header has gone stale.
4. **Consolidation was skipped.** The consumed `Architecture_M5_DEFN_R2_G4_B004_Reading_Plan.md` is folded. The closeout had said "n/a" and left two plans live.

### Review closeout — reviewing-agent addendum

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | `boundary --expect-selector 448=70ff0860… 430=1c412850…` at commit |
| Decisive claims independently re-derived | Pre-M5 torus periodic count (§8.1); a body scan of all 448 identities for the isolation+periodic join; torus-row assertions; `torus_fixture()` construction (18 user hard edges) against the no-hard-edge ungated test; sheet flood-fill rules; DEFN-R2 write ordering; `ledgers` from `87d1a472` |
| Non-vacuity checked | The planned test is non-vacuous only if all six facts are asserted on one region. The new ordered asserts make a RED diagnosable. Feasibility on the chosen subject is explicitly unestablished. |
| Prior obligations discharged/carried | `M5-CP3-TB2-REV-OBS-01` is carried to `M5-CP4`, unchanged. The new CB1 §7 obligations fall on CB1 and TB1-REV. |
| Stable accounting | 51 / 14 / 37; debt 1 (M6); package `10771899191 / cef1c6ee…`; selector448 |
| New candidates/obligations recorded | Tracker addendum entry; no new stable candidate |
| ORIENTATION currency line | `M5-DEFN-R2` (incl. reviewing-agent addendum), 2026-09-23 UTC |
| ORIENTATION §3 / §4 / §7 / §8 | §7 item 1 gains the §7 clarifications. §3/§4/§8 are unchanged and correct. |
| CHANGELOG | Agent entry amended |
| ROADMAP | n/a — its status is correct |
| Selector manifest | n/a |
| LESSONS | 170 and 177 cited; no new lesson |
| Consolidation under CLEAN_UP_POLICY | Consumed R2 plan folded |
| Successor frozen | `M5-CP4-CB1`, per plan §§5 and 7 |
| Turn boundary held | Runtime-free; no product/test/fixture/selector/CMake/benchmark change |
| review_check.py | `boundary --expect-selector 448=70ff0860… 430=1c412850…`: **ALL CHECKS PASSED**. No product/test/build or selector mutation; durable markers 1→1, 3→3, 13→13. `ledgers --base 87d1a472`: **ALL CHECKS PASSED**. |
| `STATUS` lifecycle | Resume beacon first; final `COMPLETE → M5-CP4-CB1` last |
| Pushed, in sync | Confirmed by `git status -sb` after the final push |
