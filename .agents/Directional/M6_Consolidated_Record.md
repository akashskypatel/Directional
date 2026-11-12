## 2026-10-25 — TB38 independent census Review / current authority index

### Folded historical document (2026-10-25 Review closeout)

- **`Architecture_M6_CP3_TB36_Baseline_Orchestration_Attempt_20261025.md`** — 32-line invalid TB36 orchestration attempt; no semantic runtime outcome, cardinality/regex harness defect, immutable source/package/run/artifact identities and authorized successor preserved verbatim below. This record is superseded by the successful TB36-R1 report and subsequent independent decisions. No live references to the removed filename existed before this fold. The original file remains accessible at earlier Git commits.

<details><summary>Verbatim original record — invalid TB36 orchestration attempt</summary>

# TB36 immutable baseline — invalid orchestration attempt (2026-10-25)

**Canonical attempted turn:** `M6-CP3-TB36-RP01-PERIODIC-MONODROMY-BASELINE`.

**Outcome:** orchestration failure before the immutable package was downloaded or any selected test was executed. **No semantic RED, GREEN, regression, or first rejecting producer is established.** Do not promote this attempt to TB36 evidence and do not start the CB36 production repair.

## Exact authority

- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 (draft).
- Immutable semantic source: `7de805c487fa66bcb96744f51b8bfbe7210ee8dc`.
- CB35-R2 package: GitHub Actions artifact `12580989509`, SHA-256 `a594b8617493087ff9ab50391e30cc7a8870f2dcf92427c03899b076e344bb54`; previously reviewed 28/28 internal hashes, 8 GMP/GMPXX compilation targets and `runtimeExecution=false`.
- Frozen TB36 five-row manifest: `Architecture_M6_CP3_TB36_Periodic_Monodromy_Baseline_Case_Manifest.tsv`, SHA-256 `ab2711b2efc64103a9106b9a63f03064c63dc6e93a16c0602f3c6b3f866c1d0c`.
- Source snapshot: `e2f3f19ba3573a70cbeda3761d8b8ee51d9a2985`; run `40155167844`, artifact `12583269882`, ZIP SHA-256 `230cae19c6d6e81d23b4eb3ef2907cbe3191b354e944ab398d45dec6aa6dba9d`; internal archive and file manifest verified locally.
- Runner harness commit `e9850781601e579c7332683a207a70034bae3f0e`, `.agents/Directional/tools/m6_cp3_tb36_periodic_monodromy_baseline_harness.sh`, SHA-256 `99eb3f4bbdaab1c5e5c7cd385738f8349c4fbfbbb96edb34719518423cbcf0f7`.
- Dispatcher request commit `1e4d0d9e0b8fbed72e57ab2694582cb0eda8b5e5`.
- Failed run `40155549123`; `test_benchmark / runtime` job `121056134755`, harness exit `90`. Result artifact `12584118434`, SHA-256 `35184c73ecaed4089ba8a9891d1dfcb4a4ed5fc36bcb3ca236542de23189a8f9`; log artifact `12584298170`, SHA-256 `c646e1480f87f22705dbbe433a63f98e070b35d033fc6a1534ff651c74398f93`.

## Failure and corrective scope

The harness was derived from the TB35 artifact-only runner, but its case uniqueness preflight retains `== 13` for both case-name and identity cardinality even though TB36 deliberately has five rows. The runner exits before fetching the package:

`TB36_HARNESS_FAILURE RuntimeError('duplicate case')`

This error text is misleading: the five-row TB36 manifest is independently unique. Correct both cardinality comparisons to **5**. Separately, the newly introduced source-location regex is overescaped inside a Python raw string; use the intended single regex backslashes for `\.cpp` and `\d+` (or an equivalent correct parser). Independently verify both with the manifest and representative raw GTest text without executing any Directional binary.

**Required next action:** route to a bounded **control-plane-only Code + Build orchestration correction** under `Turn_Cadence.md` §5. Correct the harness only; do not change immutable package, semantic tests, frozen selectors, fixtures, production implementation, or required workflow permissions. Author an explicit successor turn and fresh executor SHA, then rerun all five frozen identities through a new TB attempt. The invalid attempt must remain retained as provenance, never as semantic outcome. A semantic TB36-REV is authorized only after a valid TB36 execution.

Stable accounting remains **66 events / 17 categories / 49 recurrences**, produced witness debt **1**. CP2 accepted **491/491**; TB32 candidate **481/500**; TB35 **11 PASS / 2 RED**; frozen selector497 unchanged; RA-152 F1 unresolved.

## Local turn observations

The initial source-inspection access preceded the mandatory `READ_MODE=snapshot` choice, contrary to the tool conservation policy. Inspection thereafter used the verified snapshot. No local builds or Directional binaries were executed, and no test bodies or fixtures were modified.

</details>



`Architecture_M6_CP3_TB38_Periodic_Route_Atlas_Census_Report_20261025.md` remains the current **runtime evidence report**; `Architecture_M6_CP3_TB38_Periodic_Route_Atlas_Census_Independent_Review_Decision_20261025.md` is the current **independent candidate Review**. The 504-row manifest is retained unchanged. No per-turn evidence file was folded/deleted in this step because those predecessors are still cited as independent baselines or retained proof; before retiring any, index exact names and adjudications and preserve their facts. Reviewed 490/504 candidate, 14 inherited RED; no CP3/selector promotion; successor atlas-ingress tamper-oracle DEFN.

## 2026-10-25 — CB36 periodic atlas transport Review / current authority index

`Architecture_M6_CP3_CB36_Periodic_Route_Atlas_Transport_Independent_Review_Decision_20261025.md` is the current independent static Review; `Architecture_M6_CP3_TB37_Periodic_Route_Atlas_Verification_Case_Manifest.tsv` is the current 16-row future TB37 gate; `Architecture_M6_CP3_CB36_Periodic_Route_Atlas_Transport_Code_Build_Record_20261025.md` and `Architecture_M6_CP3_TB36_REV_Audit_Periodic_Route_Atlas_Transport_Decision_20261025.md` remain live causal/compile authority and are **not folded**. No superseded, uniquely indexed document was safely retired in this Review. Exact source `038ae7fd7c290731c28225d2693a3e13866e325a`, compile artifact `12590917524`, 28/28 GMP, no runtime or acceptance.

## 2026-10-24 — CB33 independent diagnostic Review index

Current CB33 code/build report `Architecture_M6_CP3_CB33_A3_Cycle_Mismatch_Locus_Diagnostic_Code_Build_Record_20261024.md` and current Review `Architecture_M6_CP3_CB33_A3_Cycle_Mismatch_Locus_Diagnostic_Review_Decision_20261024.md` retained as live authorities, **not folded**. CB33-REV accepts static compile fidelity, corrects the RA-149.3 S2 reachability premise and freezes the 12-case TB34 manifest `Architecture_M6_CP3_TB34_A3_Cycle_Locus_Cases.tsv`. No older per-turn document retired by this Review; folded index unchanged.

## 2026-10-08 — R2 independent Review rejects immutable 444/497 candidate; R3 Definition next

R2 (`M6-CP3-TB1-ENTRY-R2-REV`) mechanically verifies 497 fresh processes, 444 PASS/53 RED on source `80fc1688...`, artifact `11545716507`; 47 previously accepted CP2 identities RED; R1→R2 38 new RED and zero recoveries. One new stable RP-01 A4 HardRail route-certificate false rejection on accepted fixtures: accounting **64/17/47**, debt 1; old A6 RP-01 remains open. Static face-star counterexample: consecutive supported hard edges (1,4),(4,7) have disjoint incident-face sets. RA-36.1 face-sharing premise under Review HOLD; do not infer actual produced two-edge route. Exact next `M6-DEFN-R5-R3` runtime-free Definition then `M6-DEFN-R5-R3-REV`; CB2, CP3 exit, optimizer held. Full independent verdict `Architecture_M6_CP3_TB1_Entry_R2_Review_Record.md`, 53-row file `Architecture_M6_CP3_TB1_Entry_R2_Red_Classification.tsv`, prescriptive plan `Architecture_M6_DEFN_R5_R3_CP3_Entry_Recovery_Definition_Plan.md`.

---

## 2026-10-06 — Current authority after the `M6-CP3-TB1-ENTRY-REV` addendum

The CP3 entry candidate is rejected (373/497). RA-31 and RA-31a apply (§58). Exact next: `M6-CP3-CB1-ENTRY-R1` → TB1-R1 (497) → Review → `M6-DEFN-R5-R1`. Accounting **63 / 17 / 46**, debt 1.

## 2026-10-06 — Current authority after `M6-CP3-TB1-ENTRY-REV`

Entry candidate `11411137781 / 912760f1...` is **REJECTED / UNPROMOTED** after immutable 497-process TB returns 373 PASS / 124 RED. Review resolves every row: production CAND-01 110 and CAND-02 9; stable focused30 test-authority CAND-07 1; non-stable entry CAND-04 1 / CAND-05 2 / CAND-06 1. Stable totals are **63 / 17 / 46**, debt 1. RA-31 freezes one bounded recovery: `M6-CP3-CB1-ENTRY-R1` → R1 TB **497** → mandatory R1 Review. CP3 exit remains held. Full authority: `Architecture_M6_CP3_TB1_Entry_Review_Record.md`; next plan: `Architecture_M6_CP3_CB1_Entry_R1_Recovery_Code_Build_Plan.md`.

## 2026-10-06 — Current authority after `M6-DEFN-R5-REV`

The CP3 entry Definition is accepted with RA-30a (§57). Exact next: `M6-CP3-CB1-ENTRY` → TB1-ENTRY (497) → Review. Reviewed runtime `11391685901 / 5ce3132e` (491/491). Accounting **60 / 16 / 44**, debt 1.

## 2026-10-06 — Current authority after `M6-CP2-CLOSE-REV`

M6 CP2 is **CLOSED / ACCEPTED**. Independent Close Review promotes `11391685901 / 5ce3132ec01748eff5b15f82be07a1abe2bd1af6`; TB2 is independently re-derived at **491/491**, exact-one 491/491, zero skips/RED/benchmarks, result manifest 1005/1005 and immutable postflight. RA-29d OBS-01/02/03 are recovery-proved and OBS-04 is closed by `M6_CP2_Closure_Record.md`. Accounting remains **60 / 16 / 44**, debt 1. Exact next: `M6-DEFN-R5`.

## 2026-10-06 — Current authority after `M6-CP2-TB2-COVERAGE-EXEC`

M6 CP2 remains **ACTIVE pending mandatory Close Review**. Coverage candidate `11391685901 / 5ce3132ec01748eff5b15f82be07a1abe2bd1af6` is mechanically GREEN at **491/491** in run/job `37419256039 / 112124748161` (30 + 12 + 449, exact-one 491/491, zero skips, benchmark 0, immutable postflight). Result/log are `11393198123 / 11393312986`; no regression candidate, accounting **60 / 16 / 44**, debt 1. Exact next: `M6-CP2-CLOSE-REV`; `M6-DEFN-R5` remains held until accepted closure.

## 2026-10-06 — Current authority after the `M6-CP2-TB1-VERIFIER-R2-REV` review-agent addendum (RA-29d)

**M6 CP2 is ACTIVE; its closure is revoked** (§56). The R3 verifier `11385836615 / c64baacd` (491/491) stays promoted as reviewed runtime authority. Exact next: `M6-CP2-CB2-COVERAGE` → TB (491) → `M6-CP2-CLOSE-REV` → `M6-DEFN-R5`. Accounting **60 / 16 / 44**, debt 1.

## 2026-10-06 — M6-CP2 final verifier Review: ACCEPTED / PROMOTED (closure claim revoked by RA-29d; see §56)

`M6-CP2-TB1-VERIFIER-R2-REV` promotes `11385836615 / c64baacd6c767c4ba053b6963651c0aa6eceed20`. Runtime `37403703032 / 112076464024` re-derives **491/491** (30 + 12 + 449), exact-one 491/491, zero skips, benchmark 0, immutable postflight. Static review accepts RA-29c's exact relation→path→vertex binding, removal of invalid component/reverse-lookup rules, bounded grouping complexity, and behavioral token ownership. R1 recovery findings close non-stably; accounting remains **60 / 16 / 44**, debt 1. M6-CP2 is closed. Exact next: `M6-DEFN-R5`. See `Architecture_M6_CP2_TB1_Verifier_R2_Review_Record.md`.

## 2026-10-06 — M6 CP2 verifier R3 compile/package closure

**Current authority after `M6-CP2-CB1-VERIFIER-R3`:** M6 CP1 remains CLOSED / ACCEPTED, mechanism-only; CP2 verifier candidates R1/R2 remain rejected; RA-29c is implemented at exact semantic source `c64baacd6c767c4ba053b6963651c0aa6eceed20`. Candidate package `11385836615` is compile/package GREEN and **unpromoted**. Reviewed runtime remains `11330703256 / 3f40f04a...` (479/479). Accounting **60 / 16 / 44**, debt 1. Exact next: immutable `M6-CP2-TB1-VERIFIER-R2-EXEC` (**491**) → mandatory Review.

R3 replaces the rejected reverse-lookup logic with RA-29c's exact A5 selected-step/value, A6 legacy-projection reconstruction, and A7 class-local sorted-unique projection checks; removes only the invalid A0 raw-connectivity component rule/sub-witness; and replaces the vacuous `owns_products` declaration with behavioral ownership evidence. Compile run/job `37401647591 / 112069997705` is GREEN on all eight standard GMP/GMPXX targets. Result/log artifacts `11385836615 / 11385671776` hash `40ea2966011865090ce49382300885ee132e82655fba4f98575f326b53ca2ea4 / 97a7aee4888c938d356894c6f661ad8a0a00f526eb87e9d8f88c7fa132a3f675`; manifest **28/28**, clean source receipts, `exactArithmeticBackend=GMP`, `runtimeExecution=false`. Frozen focused30 / focused12 / selector449 / routing449 hashes remain `1e815443... / 2aa57aac... / d4a0d1b7... / 9c88a5ed...`. Full evidence: `Architecture_M6_CP2_CB1_Verifier_R3_Recovery_Code_Build_Report.md`.

## 2026-10-06 — M6 CP2 verifier R1 Review: RA-29b

## 2026-10-06 — M6 CP2 verifier R1 runtime: 462/491, Review required

Immutable R2 candidate `11382000465 / 9c8478aec40bf07144ca7372c2aa58293cd42f5e` completed the full **491**-process artifact-only gate in run/job `37393554373 / 112044082007`: focused30 **26/30**, CP2-focused12 **11/12**, selector449 **425/449**, aggregate **462/491**, exact-one 491/491, zero skips, benchmark 0. The dominant visible rejection is `MissingPublishedAuthority:a7:a5-relation-step`; selector144 separately reports `SourceIncidenceMismatch:a0:component-adjacency`; focused12 ordinal6's strengthened baseline does not verify.

The harness exited 0 after immutable postflight. The caller then failed its two upload steps because they still referenced the predecessor turn's output paths, so no R1 runtime result/log artifact exists. Runtime must not be repeated merely to recreate evidence. Mailbox and GitHub job log remain authoritative for the executed gate. Candidate is unpromoted; stable accounting remains **60 / 16 / 44**, debt 1. Exact next is mandatory `M6-CP2-TB1-VERIFIER-R1-REV`.

## 2026-10-06 — M6 CP2 verifier R2 compile/package closure

`M6-CP2-CB1-VERIFIER-R2` is COMPLETE at semantic source `9c8478aec40bf07144ca7372c2aa58293cd42f5e`. RA-29/RA-29a recovery added the missing A0 component-adjacency check, shared source-support recomputation, relation-class and exact selected-forest/path binding, linear-time topology inventories, content-owning verified products, carried verification report, verified-token counter reads, and non-vacuous repairs for the existing CP2 focused identities without changing optimizer source or gate ordering.

Compile/package run/job `37391389044 / 112037085233` is GREEN on all eight standard GMP/GMPXX targets. Immutable result/log artifacts are `11382000465 / 11381555970` with digests `e02e393375de3004beaf725cb859c7ad32e04456df56eb0c2c2239ad5deed4c1` / `3b2fd466c7d55695c31095239021b19696031e4bf263bbf72ccb8ec2b8743888`; package manifest is **28/28**, source status is clean, and `runtimeExecution=false`.

Frozen authorities remain focused30 `1e815443a03c7ef4a1b095e6ea973efa9c74bb0eae4e2f872510c97d057ea1d6`, CP2-focused12 `2aa57aac48ac8c41ea86ed459cdd1acd27eb17c8d3dbe1b4ac7b9c54c67374ed`, selector449 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`, and routing449 `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707`. Stable accounting remains **60 / 16 / 44**, debt 1. Exact next is immutable `M6-CP2-TB1-VERIFIER-R1-EXEC` at **491** fresh exact-filter processes, then mandatory Review.

**Current authority after `M6-CP2-TB1-VERIFIER-REV` (2026-10-05):** first CP2 verifier candidate `11365308211 / 265c8fbb...` is **REJECTED FOR BOUNDED RECOVERY / UNPROMOTED**. Runtime mechanics are 488/491 (focused30 30/30, focused12 9/12, selector449 449/449). CAND-01/02/03 are non-stable false-rejection witnesses; REV-OBS-01..04 freeze the missing carried pipeline report, A0-valid wrong-region witness, shared support-resolver check and exact selected-forest path identity. RA-29 governs. Exact next: `M6-CP2-CB1-VERIFIER-R2` → fresh `M6-CP2-TB1-VERIFIER-R1-EXEC` (491) → mandatory R1 Review. Accounting **60 / 16 / 44**, debt 1.

**Current authority after the `M6-CP2-TB1-VERIFIER-REV` addendum (2026-10-05):** M6 CP1 CLOSED / ACCEPTED, mechanism-only; the first CP2 verifier candidate is rejected (RA-29) and amended by RA-29a (§54); reviewed runtime `11330703256 / 3f40f04a...` (479/479). Accounting **60 / 16 / 44**, debt 1. Exact next: `M6-CP2-CB1-VERIFIER-R2` → TB1-R1 (491) → Review.

**Current authority after `M6-CP2-CB1-VERIFIER-REV` (2026-10-05):** M6 CP1 CLOSED / ACCEPTED, mechanism-only; CP2 Definition accepted with RA-28a, amended by RA-28b (§52); reviewed runtime `11330703256 / 3f40f04a...` (479/479). Accounting **60 / 16 / 44**, debt 1. Exact next: `M6-CP2-CB1-VERIFIER-R1` → TB1 (491) → Review.

**Current authority after `M6-CP1-TB12-CLOSE-REV` (2026-10-05):** TB12 candidate `11324028392 / 02149f15...` remains unpromoted after 478/479. CAND-01 is adjudicated **FALSE REJECTION / TEST-FIXTURE WITNESS DEFECT / RECOVERY REQUIRED / NON-STABLE**; RA-27 authorizes test-only `M6-CP1-CB12-CLOSE-R2`, then a fresh 479-process R1 gate and mandatory Review. Reviewed runtime remains `11316716869 / 8dd95821...`; accounting **60 / 16 / 44**, debt 1.

**Current authority after the `M6-CP1-TB12-CLOSE-R1-REV` addendum (2026-10-05):** reviewed runtime `11330703256 / 3f40f04a...` (focused-30 + selector449 = 479/479). RA-27b applies (§49). Accounting **60 / 16 / 44**, debt 1. Exact next: `M6-CP1-CLOSE-REV`; if CP1 closes → `M6-CP2-DEFN`.

**Current authority after `M6-CP1-CB11-G4` (2026-10-04):** CB11 is COMPLETE / COMPILE+PACKAGE GREEN / RUNTIME-FREE at semantic source `582da20a925ba920c923bf5aacb9e0e56ef0723d`. Candidate result artifact `11308472138` is unpromoted. Reviewed runtime remains `11299078582 / 96b456f9...` at 473/473. Stable accounting remains **60 / 16 / 44**, debt 1. Exact next: immutable `M6-CP1-TB11-G4-EXEC`, focused28+selector449 = **477**, then mandatory Review; CP1 close remains held.

**Current authority after `M6-CP1-CB12-CLOSE-R1` (2026-10-05):** reviewed runtime remains `11316716869 / 8dd95821...` (477/477); unpromoted compile candidate is `11324028392 / 02149f15...`. C1–C4 and focused-30 are compile-valid; C5 remains discharged by RA-26 (§44). Accounting **60 / 16 / 44**, debt 1. Exact next: `M6-CP1-TB12-CLOSE-EXEC` (479) → Review → `M6-CP1-CLOSE-REV`.

CB11 implements the accepted R4 D3 / RA-20 / RA-21 / RA-21b boundary: A6-owned closed-complex vertices/quads/side-incidence edges, independent relation-kind and typed-source hard-feature protection, strip ordinals from opposite-edge closure, and A6-view candidate extraction without arrangement authority. Focused identities 25-28 extend focused24 exactly; focused28 SHA-256 is `9154a986ce005c53f99faad3551989b05516abe9e4fd02dce585a645d70a011d`.

The first compile attempt exposed only compile-contract defects. The bounded correction at `582da20a...` retained the public materializer API and changed identity25 to explicit exact field comparisons. Final compile run/job `37216400150 / 111477707423` is GREEN for all eight standard GMP/GMPXX targets. Result/log artifacts `11308472138 / 11308317584` have outer SHA-256 `a4d17867...d04d / c93259fd...2b76`; package manifest 28/28, source receipts clean, `runtimeExecution=false`. No runtime acceptance or debt/`G4-B002` closure is claimed. TB11 owns the 477-process runtime gate and mandatory Review.

**Current authority after `M6-CP1-CB9-A7-R1` (2026-10-04):** R1 is COMPLETE / COMPILE+PACKAGE GREEN / RUNTIME-FREE. RA-22/RA-22a completion-consumer recovery is compiled at source `584f80fe27fe3fbe482f3b6db035651a3083257c`; candidate artifact `11292072930` is unpromoted. Reviewed runtime remains TB8 `11265967968 / 8e0818b1...` at 461/461. Stable accounting remains **60 / 16 / 44**, debt 1. Exact next: immutable `M6-CP1-TB9-A7-R1-EXEC` focused20+selector449 = **469** -> mandatory Review; CB10 held. Full build evidence: `Architecture_M6_CP1_CB9_A7_R1_Code_Build_Report.md`.

**Current authority after the `M6-CP1-TB10-A5V-R1-REV` addendum (2026-10-04):** reviewed runtime `11299078582 / 96b456f9...` (473/473). RA-21b readies CB11 (§39). Accounting **60 / 16 / 44**, debt 1. Exact next: `M6-CP1-CB11-G4` → TB11 (477) → Review → `M6-CP1-CLOSE-REV`.

**Current authority after the `M6-CP1-TB9-A7-REV` addendum (2026-10-04):** reviewed runtime `11265967968 / 8e0818b1...` (461/461). The CB9 candidate is rejected at 468/469, with the A7 producer upheld. RA-22/RA-22a recovery is next (§33). Accounting **60 / 16 / 44**, debt 1. Exact next: `M6-CP1-CB9-A7-R1` → TB9-R1 (469) → Review.

# M6 consolidated record

**Current authority after `M6-CP1-CB9-A7` (2026-10-03):** reviewed runtime remains `11265967968 / 8e0818b1...` (461/461). CB9 candidate `11287202960 / b8d27b63425c11c27c45a1e7b9e2b866b0e1e8b8` is compile/package GREEN and unpromoted; focused-20 SHA-256 `15d04a2a09eeb678923b0bfcf70bf9c07b79e7ff343ec468316f6510b16827d2`. Stable accounting **60 / 16 / 44**, debt 1. Exact next: `M6-CP1-TB9-A7-EXEC` (469) → mandatory Review.


## 32. `M6-CP1-CB9-A7` — A7 product implemented; compile/package GREEN

CB9 implements the accepted R4/RA-18 A7 boundary at exact semantic source `b8d27b63425c11c27c45a1e7b9e2b866b0e1e8b8`: immutable source-attached geometry over A6 classes, typed common support from A5 only, the reject-only `1e-8` same-simplex point guard with `SourceSupportPointMismatch`, deterministic representation-only representatives, complete lineage projection without placement-transport consumption, topology copying without class mutation, and the production-completion ownership witness.

Focused identities 13-20 extend the frozen focused-12 prefix; `Architecture_M6_CP1_Required_Green_Focused_20.txt` is 20 rows and SHA-256 `15d04a2a09eeb678923b0bfcf70bf9c07b79e7ff343ec468316f6510b16827d2`.

Two compile-only defects were repaired without executing runtime: non-default aggregate construction, then test-local `DomainResult` access. The authoritative third compile run/job `37160018910 / 111311373537` is GREEN for all eight standard GMP/GMPXX targets. Result artifact `11287202960` (`sha256:9bd87689c0155c3544de83159bd00169a4c8f932be4e878dbdd3dc7e7b5a179c`) and log artifact `11287377799` (`sha256:f3ebe94b0ce58abdd3a5f1376de5c222da6d9a600e9cb3e74dd5f6768c905ce5`) record `runtimeExecution=false`.

The candidate remains unpromoted. Reviewed runtime stays TB8 `11265967968 / 8e0818b1...`; accounting remains 60/16/44, debt 1. Exact next is immutable `M6-CP1-TB9-A7-EXEC`, **20+449=469**, then mandatory `M6-CP1-TB9-A7-REV`. CB10 remains held behind that Review.


## 30. `M6-CP1-TB8-A6-REV` — 461/461 recovery accepted; candidate promoted

Independent runtime-free Review re-hashes candidate `11265967968 / 8e0818b1...`, verifies its 28/28 package manifest and frozen selector/routing authority, then independently verifies TB8 result `11273611682` at 954/954 with the exact 12+449 order, exact-one selection, zero skips, empty RED ledger and immutable postflight. All TB7 recovery populations and critical controls are green; the three TB7 stable events are formally recovery-proved without changing append-only history. `11265967968 / 8e0818b1...` is promoted as current reviewed M6 runtime authority. Stable accounting remains 60/16/44, debt 1. CP1 remains open because A7, the thin adapter and `G4-B002` A6-derived stage boundary were deferred. Exact next is runtime-free `M6-DEFN-R4`, followed by mandatory Review before implementation.

## 0. `M6-DEFN-R3-REV` — R3 accepted with four binding A6 precision amendments

Independent runtime-free Review accepts the R3 A6 product separation while correcting four implementation-critical ambiguities: certificates are oriented by canonical `SurfaceOccurrenceRelationId.first -> second`, accepted OrdinaryFront quotient transport is identity even when seam evidence is present, A5 relation publication must carry enough canonical HardRail/Periodic evidence for A6 to avoid representation/global-array lookups, and selected-path `GridAutomorphism` composition order is frozen explicitly. The strict direct-vs-path holonomy rule and its cylinder/torus runtime falsifier remain unchanged. The same four new focused identities remain; later gate stays **11 + 449 = 460**.

Review source snapshot run/artifact `36207017645 / 10894735898` is static/runtime-free and contains no source/test delta from reviewed runtime semantic source `82b86a28...`; selector/routing449 remain unchanged. Stable accounting remains **55/16/39**, debt 1. `M6-CP1-CB6-A6` is now authorized; exact next is that compile-only Code + Build turn, followed by immutable `M6-CP1-TB6-A6-EXEC` and mandatory Review. Full authority: `Architecture_M6_DEFN_R3_Review_Record.md` plus the R3-REV amendment in `Architecture_M6_Frozen_Definitions.md`.

## 0.1. `M6-DEFN-R3` — bounded A6 quotient-product definition complete

Runtime-free R3 freezes `pipeline::SurfaceQuotientClassId` as the exact sorted member-occurrence set; exact one certificate + ledger row per A5-owned relation; `Joining` versus `CycleClosing` dispositions; a deterministic selected relation forest; exact direct-relation versus unique-path `GridAutomorphism` equality with `QuotientHolonomyConflict` on mismatch; A6-owned selected paths; and the stable A6 error vocabulary. Split square/uniform planar hard-rail/ordinary-identity cases are analytically consistent; produced cylinder row232 and torus rows444/446/448/449 are TB falsifiers. A7 representation and the exact `G4-B002` boundary move to R4. Held `M6-CP1-CB6-A6` absorbs legacy A5 field retirement and adds four focused identities; later TB shape is 11 + selector449 = 460. Exact next is `M6-DEFN-R3-REV`. Stable accounting 55/16/39, debt 1; no runtime/compile in R3.

Closeout authority: source snapshot run/artifact `36199074014 / 10890838063` verified 5,317/5,317 files with `runtimeExecution=false`. Caller schema validation run `36200248982` passed. Drive apply retry 1 (`36200336205`) stopped before apply because the transport header omitted required `intended_paths`; this was a control-plane packaging defect only. Corrected patch SHA-256 `e25796750cd5515fd99e57b9799bef6ec635ff332cef0c850b3f23ff492bbda9` applied successfully in retry 2 run/job `36200505422 / 108285917479`, producing documentation commit `b2ec0d60b771281f867e17d0911bd0b3f6c79e30`; no Directional runtime executed. The workflow Drive identity could not trash the staged file, and owner-authorized Drive deletion then succeeded. Temporary caller/marker/payload/source-snapshot state was batch-cleaned by run `36200633811`, cleanup commit `25a748d7d856c1fc9bf21c5f046469d594980e07`.

# M6 Consolidated Record

**Status:** M6 ACTIVE / `M6-CP1-TB11-G4-REV` COMPLETE / CB11 candidate rejected and unpromoted / RA-21c + RA-23 frozen / exact next `M6-CP1-CB11-G4-R1` -> TB11-R1 477 -> mandatory Review / stable 60/16/44, debt 1
**Last updated:** 2026-10-04

Normative M6 semantics live in `Architecture_M6_Frozen_Definitions.md`. Entering accepted authority is M5 package/source `10814505512 / e284fea7c101eb86650d1c87c92d0fefa66050e7` under selector449 **449/449 PASS**, SHA-256 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`. TB1's accepted-prefix event remains independently classified as singleton `CROSS_TEMPORARY_ITERATOR_RANGE`; TB2 row140 `VALIDATION_ORDER_SHADOWING` is recovery-proved closed but remains historical; TB3 Review adds one accepted-prefix event as an existing `RP-01 / AUTHORITY_DOMAIN_CONFLATION` recurrence. TB4 Review adds one accepted-prefix event as another existing `RP-01 / AUTHORITY_DOMAIN_CONFLATION` recurrence. Stable accounting is **60 / 16 / 44** and produced-witness debt is **1**, M6-owned.

## 41. `M6-CP1-TB11-G4-REV` — TB11 RED reclassified; bounded oracle recovery required

Review accepts TB11 as mechanically valid at focused **26/28** + selector449 **449/449** = **475/477** with immutable postflight, but rejects promotion of candidate `11308472138 / 582da20a...`. Ordinal25 is a false rejection from RA-21b: quotient relations identify distinct cut occurrences but the arrangement does not physically merge their nodes/chains. RA-21c therefore keeps one degree-2 arrangement witness per proposal side and one node witness per A4 corner occurrence, while quotient edge equivalence comes from reciprocal A4 sides plus A5/A6 relation authority. Ordinal28 exposes a separate definition/fixture gap: the accepted arrangement `(family,strand)` candidate never established non-vacuity for R4's quotient opposite-edge strip model. RA-23 keeps produced-torus strip/candidate universal checks and proves CP1 mechanism-only non-vacuity/tamper on a canonical closed 4x4 toroidal A6 test view, without CP3 debt credit.

CAND-01 closes as false-rejection/non-stable; CAND-02 is reclassified as non-stable definition-witness recovery. Stable accounting remains **60 / 16 / 44**, debt 1. Reviewed runtime remains `11299078582 / 96b456f9...`. Exact next is test-authority-only `M6-CP1-CB11-G4-R1`; any semantic production A5/A6 change is STOP -> Review. Compile-green routes to unchanged focused28 + selector449 = **477**, then mandatory `M6-CP1-TB11-G4-R1-REV`.

## 1. `M6-DEFN` — four products and verifier boundary frozen

`M6-DEFN` is COMPLETE / runtime-free. It freezes complete immutable products for A5 occurrence creation, A6 quotient construction/materialization, A7 source-attached embedding, and the M6 structural portion of A8 independent verification. Occurrence identity is `(CellId, canonicalCornerRole)`; quotient-class identity is the complete canonical member-occurrence set. Coordinate/position coincidence never establishes equality. Every A5-owned relation must be certified and consumed exactly once by A6. A7 cannot alter A6 topology. The A8 verifier may recompute elementary source/output incidence but may not infer, search, repair, substitute, canonicalize, weld, or mutate producer state. M7 retains `OutputDisposition` and degradation.

`G4-B002` remains split: CP1 mechanism/stage separation, CP3 direct production. `G4-B001 / PR8-R034 / G4-R007` is adjudicated as a direct-production evidence debt rather than a currently demonstrated source defect because current classification explicitly keeps hard-feature rails out of isolation-sheet barriers; CP1 must preserve that separation and CP3 owns strict torus 3/3 re-proof. `G4-B004` requires the same M5-accepted direct torus authority through A5 exact occurrences, A6 exact-once consumption, A7 embedding, and A8 independent verification.

The two dormant CB14 identities receive no M5 credit. At `M6-CP1-CB1` the endpoint-gauge identity is deleted. The pair-swap identity is **retained for the CP1 prepublication gate**: the reviewing agent stopped its deletion because its claimed replacement, row 444, permutes the relation container, not edge storage. The never-gated focused multi-isolation materialization identity is retained for CP1 mechanism gating; the never-gated committed-torus identity is retained for CP3 direct-production preservation but is insufficient alone for G4-B004 closure.

**`M6-DEFN` reviewing-agent addendum — UPHELD WITH AMENDMENTS.**
- **Clean closeout.** COMPLETE was the last write, `ledgers` PASSes, and no code changed.
- **Confirmed.** The `G4-B001` static basis (an empty isolation-barrier set) holds, and the DESIGN A8 edit is consistent with DESIGN §14 M7.

Amendments:
1. **`CellId` basis stated.** It is a canonical rank of (region `canonicalFaceTopology` rank, chart grid ordinal), with face-row invariance accepted in rows 129, 196, 213, 245 and 254. It renumbers on insertion or omission, which `M7-DEFN` must revisit. The CB1 permutation test must permute face rows.
2. **Pair-swap deletion stopped.** No accepted row permutes edge storage. The identity is retained for the CP1 gate.
3. **Tracker entries moved.** They had been buried below restored history; they are moved above it and a placement rule is added.
4. **Stale text fixed.** The closed M5 frozen header and the TODO `G4-B001` item are updated.

## 2. `M6-CP1-CB1` — A5 occurrence product candidate compiled

CB1 extracts only the frozen A5 seam. Exact source `ee8b8ac20571df5773f5f94bf9b382161f37a893` makes `OccurrenceId` semantic as `(CellId, canonicalCornerRole)`, publishes immutable `SurfaceOccurrenceComplex`/`OccurrenceComplexCertificate`, moves A5 occurrence/cell/side/relation publication behind `SurfaceOccurrenceComplexProducer`, and changes the transitional materializer only enough to consume that product. A6/A7 remain inline and A8 remains unimplemented.

Four new compile-visible `M6CP1` identities plus the retained multi-isolation and edge-storage pair-swap identities form the six-test CP1 prepublication vector. The endpoint-gauge dormant identity is deleted; pair-swap is retained; selector449 remains exact `d4a0d1b7...d6414`. Final run/job `36038472933 / 107764451786` packages all eight standard targets with GMP/GMPXX as artifact `10826090221`, manifest 28/28, clean source receipts and `runtimeExecution=false`. CB1 grants no semantic credit; exact next is artifact-only `M6-CP1-TB1-EXEC`, then mandatory Review.

The two compile-only integration corrections (`OccurrenceId` semantic hash and benchmark serialization) are recorded as non-stable `M6-CP1-CB1-OBS-01`; accounting remains 51/14/37 and debt 1.

## 3. `M6-CP1-TB1-EXEC` — A5 candidate runtime exposes accepted-prefix loss

TB1 consumed artifact/source `10826090221 / ee8b8ac...` immutably. Authoritative run/job `36045055975 / 107786525272` executes the frozen six focused identities plus all 449 accepted selector identities as **455** fresh exact-filter processes with exact-one/zero-skip discipline. Outcome is **3/6 focused PASS + 437/449 selector PASS = 440/455 PASS**, 15 semantic RED, zero crashes/selection mismatches, benchmark 0, and exact immutable postflight. Result/log authority is `10828084810 / 10827949954`; result manifest is 933/933.

The twelve accepted selector losses are ordinals 115, 116, 139, 140, 141, 143, 186, 225, 239, 444, 446 and 448. All stop at `OccurrenceInvalidCornerAuthority` after the new A5 cutover. Focused rows2/5/6 stop at the same A5 surface. Static source bounds the defect to corner-authority publication and exposes existing `RP-01` authority-domain conflation: a projection-chart face/row is consumed as occurrence ownership authority even though canonical source-support semantics permit edge/vertex points to use any incident projection face. The exact failing sub-predicate remains mandatory-Review work.

This is **one new stable event / one recurrence in existing RP-01**, not twelve independent events: totals advance to **52 / 14 / 38**. Candidate remains unpromoted, accepted M5 package/selector449 authority remains unchanged, debt stays 1, and no M6 credit is granted. Exact next is runtime-free `M6-CP1-TB1-REV`.

## 4. `M6-CP1-TB1-REV` — accepted-prefix loss cause proved; bounded recovery frozen

Review independently re-verifies candidate `10826090221` (28/28; source `ee8b8ac...`), TB1 result `10828084810` (933/933; 455 processes), accepted predecessor `10814505512 / e284fea7...`, selector449/routing449 bytes and the complete seven-run TB1 Actions window. The 440/455 outcome and one-event grouping are upheld.

The EXEC `RP-01` attribution is corrected. `SurfaceTopologyRegion::isolation_sheets()` returns a vector by value, but A5 calls it separately for the `begin()` and `end()` passed to `std::binary_search`, producing an invalid cross-temporary iterator range. Accepted M5 performed the same semantic region/component/sheet validation using one materialized `regionSheetsById` vector and passed selector449 449/449; current source-support/projection-chart semantics therefore do not explain the transition. This is one stable event in new singleton `CROSS_TEMPORARY_ITERATOR_RANGE`: totals **52 / 15 / 37**, debt 1.

Candidate remains unpromoted. Exactly `M6-CP1-CB2` is authorized to materialize/reuse one stable sheet vector while preserving every semantic check and changing no tests/selectors/later-stage authority. Compile/package is runtime-free. Fresh `M6-CP1-TB2-EXEC` must rerun the unchanged six focused + selector449 as 455 processes, then mandatory `M6-CP1-TB2-REV`.

**`M6-CP1-TB1-REV` reviewing-agent addendum — UPHELD.**

Re-verified:
- artifacts: 933/933, the 455-row ledger, all raw hashes, and `OccurrenceInvalidCornerAuthority` on every A5-seam RED;
- the by-value split range;
- the M5 differential: the same `trace.face` predicates through a stable vector.

A repo-wide scan finds no other split range over by-value accessors. TB1 focused PASSes carry no credit, because they ran under UB. TB2 classification is pre-registered in the CB2 plan: recovery means no `OccurrenceInvalidCornerAuthority` plus selector449 at 449/449, and a different-first-failure focused RED is a new candidate. The benchmark digest adaptation is accepted, and the M6 frozen header is corrected.

## 5. `M6-CP1-CB2` — cross-temporary sheet range corrected; candidate compiled

CB2 corrects only the Review-proved A5 iterator-range defect. Exact semantic source `724316a5b3f49e33dc8e649989bb413b3dc6b7c9` materializes `region->second->isolation_sheets()` once and searches one stable vector; region, component, typed sheet membership, source-support and chart checks are otherwise unchanged. A whole-tree scan finds no remaining split `begin()/end()` range over the known by-value accessors. Selector449/routing449 and all six focused identities remain unchanged.

Remote patch application run/job `36060679446 / 107838640414` produced the exact semantic source. Mandatory GMP/GMPXX compile run/job `36061049526 / 107839861958` then compiled the standard eight targets and packaged candidate `10834642074` (SHA-256 `754cfeae794da3304b39a572ef6feb6250709f908d5688dcd21f387a071d0cb8`) with root manifest **28/28**, manifest SHA `a0fffc173149d1917ed6ab6a7dbb3c70335dee0b0e4ecb6ce652438d02037c9e`, source archive `eaf577ccdc534c2e9e48b8b8fed31079849b268c4a6c1b47b0f253ff3ad6034b`, clean source receipts and `runtimeExecution=false`. Compile log artifact `10834671954` hashes to `9395b4bdaad33c6805779035a418a4f29c80561880f2a870e0d45b2bff0cb5e4`.

No generated Directional runtime executed and no stable semantic accounting changes: **52 / 15 / 37**, debt 1. Candidate remains unpromoted. Exact next is immutable `M6-CP1-TB2-EXEC`, rerunning the unchanged six focused + selector449 as 455 fresh exact-filter processes under the pre-registered recovery rule, followed by mandatory `M6-CP1-TB2-REV`.

## 6. `M6-CP1-TB2-EXEC` — iterator-range symptom clears; two new candidate surfaces remain

TB2 consumed candidate artifact/source `10834642074 / 724316a5...` immutably. Authoritative run/job `36063687138 / 107848407035` executes the frozen six focused identities plus all 449 accepted selector identities as exactly **455** fresh exact-filter processes with exact-one/zero-skip discipline. Outcome is **5/6 focused PASS + 448/449 selector PASS = 453/455 PASS**, zero crashes/selection mismatches, benchmark 0, and exact immutable postflight. Result/log authority is `10835579933 / 10836175636`; the result manifest verifies 933/933.

No process reports `OccurrenceInvalidCornerAuthority`, and the retained pair-swap identity PASSes. The two REDs are different-first-failure surfaces: focused row5 `MultiIsolationMaterializationRetainsAllLocalSheets` fails `foundMultiIsolationLineage=false`; selector449 ordinal140 `HardRailPairExplicitRailIdMismatchRejectsStrictTransport` returns `OccurrenceUnownedRelation` instead of expected `InvalidHardRailTransport`. Under the frozen TB2 classification they are recorded as new non-stable candidates for Review. Because the recovery pre-registration also requires selector449 449/449, EXEC does not itself close/recover TB1 CAND-01 despite disappearance of its original symptom.

Stable accounting remains **52 / 15 / 37** pending Review, debt 1 M6-owned. Accepted M5 package/source and selector449 authority remain unchanged; candidate `10834642074` is unpromoted. Exact next is mandatory runtime-free `M6-CP1-TB2-REV`.

## 7. `M6-CP1-TB2-REV` — iterator symptom cleared; validation precedence and multi-isolation recovery frozen

Review independently re-opens candidate `10834642074`, TB2 result/log `10835579933 / 10836175636`, accepted M5 authority and the frozen TB2 pre-registration. TB2 mechanics are upheld at **5/6 focused + 448/449 selector = 453/455 PASS**, 0 skips/crashes/selection mismatches and exact immutable postflight. `OccurrenceInvalidCornerAuthority` is absent from all 455 and pair-swap PASSes, but the frozen CAND-01 recovery clause also requires selector449 449/449, so the cross-temporary event is mechanism-cleared but not formally closed.

Accepted selector row140 is a new stable event: A5 now rejects an explicit mismatched HardRail pair as generic `UnownedRelation` before the long-standing materializer guard can return `InvalidHardRailTransport`. The unchanged accepted negative is valid; this is new singleton **`VALIDATION_ORDER_SHADOWING`**, not test-authority drift. Accounting becomes **53 / 16 / 37**. Existing `LESSONS.md` §4 lesson 22f supplies the governing rule: restore the shadowed specific validation precedence without weakening the negative.

Focused `MultiIsolationMaterializationRetainsAllLocalSheets` is a valid but non-stable CP1 mechanism RED. Its split fixture does publish a checked two-sheet seam certificate and accepted row186 remains green, but the legacy `consumedInternalIsolationSeams` field counts certificate-map entries rather than quotient consumption. No output lineage spans both sheets. Review bounds the gap to A5 occurrence-sheet -> owned-relation endpoint -> quotient union -> lineage propagation, does not claim when it was introduced, and assumes no shared cause with row140.

Candidate remains unpromoted, accepted M5 authority remains `10814505512 / e284fea7...` under selector449 449/449, and debt remains 1. Exact next is bounded runtime-free **`M6-CP1-CB3`**, owning only HardRail diagnostic precedence and the first proved multi-isolation propagation loss. If compile-green, fresh TB3 reruns unchanged 6+449=455 and then mandatory Review.


## 8. `M6-CP1-CB3` — HardRail precedence and split-isolation occurrence authority corrected; candidate compiled

CB3 restores the accepted HardRail-specific failure precedence without weakening A5 relation ownership, and corrects the first proved split-isolation authority-loss locus without extracting A6/A7. The final semantic source is `660015f2f15359fd426e2c855aea9f4201c70216`. Explicit reciprocal HardRail-ID mismatch remains fail-closed at A5 through `HardRailOwnerMismatch`, externally preserving `InvalidHardRailTransport`; the later materializer no longer duplicates that mismatch predicate. For split-isolation occurrences, semantic identity and frozen lattice state remain unchanged while the authoritative outgoing directed-side start selects the projection face/sheet. Canonical-corner and side-attached representations must resolve to the same exact source support or A5 fails closed. Quotient union remains relation-owned only, and lineage sheet sets remain derived from actual quotient members; certificate inventory is not substituted for quotient consumption.

The frozen runtime surface is unchanged: selector449 is exactly 449 LF rows at `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`, routing449 remains `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707`, all six focused identities are unchanged, and the known by-value accessor split-range scan is clean.

Mandatory GMP/GMPXX compile run/job `36077715921 / 107892575831` compiles and links all eight standard targets from exact source `660015f2...` and packages candidate artifact `10840014758` (`sha256:b1117c6efe2cdc8a04e46647fd1bb5af79094234a03348df8ffd6e6ae5ed5c66`). Root manifest verifies **28/28**, generated link authority contains both `gmpxx` and `gmp`, `exactArithmeticBackend=GMP`, source receipts are clean, packaged source archive SHA-256 is `90c6305132ceca1bcd5f12dfd03a7a3b818fe3e9462128dedb5c3f5788f67ecc`, and `runtimeExecution=false`. Compile log artifact `10840034587` has provider digest `sha256:eb2504f3824c6626ab37f2cc5e5e39c869187b93615e7f94346e7a7124ace077`.

Two pre-compile orchestration attempts were rejected rather than normalized: one stale-base apply detected changed intended source paths, and one reconciliation patch declared an unchanged header in its intended-path set and failed exact path-set comparison. The corrected one-path patch was then applied and compiled. These rejected attempts grant no evidence.

CB3 grants no runtime credit, promotion, CP1 closure or debt discharge. Stable accounting remains **53 / 16 / 37** and produced-witness debt remains **1**, M6-owned. Exact next is immutable **`M6-CP1-TB3-EXEC`** over the unchanged six focused identities plus selector449 as 455 fresh exact-filter processes, followed by mandatory `M6-CP1-TB3-REV`.

## 9. `M6-CP1-TB3-EXEC` — HardRail recovery holds; relation-equivalence guard exposes eight REDs

TB3 consumed candidate artifact/source `10840014758 / 660015f2...` immutably. Authoritative run/job `36084948588 / 107914657100` executed the frozen six focused identities followed by selector449 as exactly **455 fresh exact-filter processes** with exact-one selection and zero skips. Outcome is **4/6 focused + 443/449 selector = 447/455 PASS**, benchmark 0, and exact immutable postflight. Result/log authority is `10844285398 / 10844020833`; result evidence verifies **929/929**.

Accepted selector row140 is restored and `OccurrenceInvalidCornerAuthority` is absent from all 455. The remaining eight REDs share one earlier first-failure surface: `MissingIsolationSeamEquivalenceAuthority`. Affected focused identities are multi-isolation and retained pair-swap; accepted selector losses are ordinals 186, 214, 239, 444, 446 and 448. Static source bounds the activation chain to CB3's corrected outgoing-side occurrence sheet authority making relations cross sheets while the existing materializer requires relation-owned `equivalence.isolationSeams`; certificate inventory is deliberately not substituted for that authority. Final ownership and stable classification remain Review-owned.

EXEC records one non-stable candidate family, `M6-CP1-TB3-EXEC-CAND-01`, and makes no stable-accounting change: **53 / 16 / 37**, debt 1. Candidate remains unpromoted, accepted M5 authority remains unchanged, and the TB1 formal recovery precondition is still unmet because selector449 is not 449/449. Exact successor is mandatory runtime-free **`M6-CP1-TB3-REV`**.

## 10. `M6-CP1-TB3-REV` — relation-owned isolation equivalence gap proved; CB4 frozen

Review independently re-opens candidate `10840014758`, TB3 result `10844285398`, accepted M5 result `10815911956`, selector449/routing449, frozen M6 definitions and exact semantic source. Candidate package is 28/28; TB3 evidence is 929/929 and exactly 455 processes; accepted M5 evidence is 911/911 and 449/449 PASS. The six TB3 selector REDs are therefore confirmed accepted-prefix losses. Semantic source `660015f2...` is an ancestor of current Review authority with no code/test/build drift.

All eight TB3 REDs stop at `MissingIsolationSeamEquivalenceAuthority`. CB3's outgoing-side occurrence sheet correction is upheld: the A5 occurrence now carries the local directed-side sheet while preserving exact support. The newly exposed defect is one stage later. Frozen A5 says every owned relation publishes a typed relation owner/certificate reference and A6 may not synthesize a missing one. Current ordinary `SurfaceOccurrenceRelation` carries endpoints plus representation front-edge indices only; the transitional consumer reconstructs `equivalence.isolationSeams` from cell-side boundary-path entry routes. That representation domain is not relation-certificate ownership and can be empty for a legitimate cross-sheet relation.

`M6-CP1-TB3-EXEC-CAND-01` is therefore one stable accepted-prefix event in existing `RP-01 / AUTHORITY_DOMAIN_CONFLATION`: events **53 -> 54**, categories remain **16**, recurrences **37 -> 38**. Row140 recovery proves the TB2 `VALIDATION_ORDER_SHADOWING` event closed while retaining its history. TB2 focused multi-isolation merges into the new relation-owner event. TB1's iterator mechanism stays cleared but its formal recovery remains open because selector449 is not yet 449/449. Candidate remains unpromoted; accepted M5 authority and debt 1 remain unchanged.

Exact next is runtime-free `M6-CP1-CB4`. It may implement only the already-frozen A5 relation-owned isolation certificate reference and make the transitional A6/materializer consume it. It must not restore global certificate-inventory augmentation, change occurrence identity/sheet/support, change tests/fixtures/selectors, or infer equality from geometry/lattice coincidence. If the certificate owner cannot be derived uniquely from accepted A4/M5 typed authority without new semantics, stop for Review/Definition. Compile-green advances to immutable `M6-CP1-TB4-EXEC` over unchanged six focused + selector449 = 455 processes, then mandatory Review.

## 11. `M6-CP1-TB3-REV` review-agent addendum — root cause corrected; CB4 held; `M6-DEFN-R1` next

TB3 mechanics, the accepted-prefix differential (`10815911956`, 449/449), accounting **54 / 16 / 38**, debt 1 and the prior-candidate dispositions are independently re-derived and upheld.

- **Seam nodes.** The eight `MissingIsolationSeamEquivalenceAuthority` REDs can only arise at lattice nodes on seams. There the cell's corner wedge spans two sheets, so CB3's outgoing-side occurrence sheet is a representative choice. The pre-CB3 shared-node rule, identical in accepted M5, made multi-sheet classes impossible, so the TB2 focused RED was never green.
- **A7 conflict.** In the split-square witness, vertices v0 and v2 record one sheet each although both sheets meet there.
- **Wrong carrier.** A cross-sheet A5 endpoint pair reflects the neighbouring cell's wedge crossing the seam, not the relation. The relation-owned CB4 plan therefore:
  - needs a new `OrdinaryFront` owner type, a definition change;
  - is ambiguous at seam vertices, since certificates are per seam edge and seams are edge chains;
  - misdescribes 3feb24ef, whose keyed `(region, shared SourceEdgeSupport)` lookup is the only typed derivation that model has.
- **Mixed-face record.** At `660015f2` each occurrence record is built from two faces: sheet and support from the outgoing face; lattice chart and branch rotation from the node face.
- **Row140 notes.** The M5 failure-string mapping belongs in the adapter, and three M5 duplicate checks are now unreachable.

Exact next is runtime-free `M6-DEFN-R1` (TB3 Review addendum A7), then `M6-DEFN-R1-REV`, then the re-scoped `M6-CP1-CB4`.

## 23. `M6-CP1-CB6-A6` — A6 product extracted and compile/package green

CB6-A6 extracts the immutable `SurfaceQuotientProduct`, retires legacy A5 `chart/lattice/isolationSheet`, implements member-set quotient IDs, exact-one relation certificates/consumption, deterministic selected forest/path evidence and the initial strict cycle transport rule. Exact semantic source is `a532f803bd2f0ef92342652ea3f1a9b64945ba69`; Compile R1 run/job `36212725707 / 108322509801` packages candidate `10896307843` with root manifest **28/28**, all eight GMP/GMPXX targets, clean source receipts and `runtimeExecution=false`. The first compile failed only on declaration clashes and was superseded by the bounded compile repair.

Candidate remained unpromoted pending TB6-A6. Selector449/routing449 stayed byte-identical. Focused row4's test-only `lattice -> placement.lattice` access change is value-identical by construction and later runtime-green in TB6-A6.

## 24. `M6-CP1-TB6-A6-EXEC` — authoritative second run exists; four semantic REDs

The first executor run `36362470435 / 108742278782` is orchestration-invalid and receives no semantic credit. A second executor run `36362570974 / 108742561290` is mechanically valid and authoritative. Result/log artifacts `10947080007 / 10946089412` verify a **946/946** result manifest and exact **11 focused + selector449 = 460** fresh exact-filter processes with exact-one selection, zero skips, benchmark 0 and immutable postflight.

Outcome is **10/11 focused + 446/449 selector = 456/460 PASS**. Exact RED identities are focused6 and selector446 at `QuotientHolonomyConflict`, plus selector139/142 unexpectedly succeeding instead of accepted `InvalidHardRailTransport`. All four new A6 focused identities 8-11 PASS; selector140/232/444/448/449 and focused5/7 PASS. The prior EXEC report's statement that no authoritative runtime existed is superseded by this reconciled Actions evidence.

## 25. `M6-CP1-TB6-A6-REV` — two stable recurrences; R3 fallback invoked; CB7-A6 frozen

Independent Review re-hashes selector449/448 and routing449, re-opens accepted TB5 runtime, and source-audits both TB6 loss mechanisms. Selector446 is one stable recurrence of existing `RP-07 / CYCLIC_TOPOLOGY_LINEARIZATION`: the accepted nonzero-Z4 torus relation legitimately carries nonidentity residual holonomy relative to a deterministic selected forest. R3's pre-registered fallback is invoked. For direct `D:a->b` and selected path `P:a->b`, A6 publishes exact residual `H=compose(P.inverse(),D)`; nonidentity `H` is evidence absent a separately frozen zero-holonomy obligation.

Selector139/142 share one stable recurrence of existing `VALIDATION_ORDER_SHADOWING`: accepted pre-A6 materialization required different source topology regions plus exact reversed HardRail routes, while CB6-A6 A5 relation publication kept only the common `HardRailId` owner check before freezing relation evidence. The guard must be restored at A5 publication; A6 must validate certificates against immutable A5 authority rather than duplicate relation semantics.

Stable accounting advances **55/16/39 -> 57/16/41**, debt remains 1. Candidate `10896307843 / a532f803...` is rejected/unpromoted; reviewed runtime stays `10879581622 / 82b86a28...`, selector449 449/449. Exact next is `M6-CP1-CB7-A6`, limited to those two relation-validation corrections plus the existing focused-test assertions required to falsify them. Compile-green -> fresh `M6-CP1-TB7-A6-EXEC` **11+449=460** -> mandatory Review. R4/A7/G4 remain held. Full authority is `Architecture_M6_CP1_TB6_A6_Review_Record.md` and the TB6-A6-REV amendment in `Architecture_M6_Frozen_Definitions.md`.

**2026-10-02 review-agent correction to Finding B:** the residual-holonomy interpretation above is historical and superseded. The conflicting torus rows mixed cut-domain placement gauge with exact-A3 Periodic relation-endpoint gauge. RA-13 requires placement-gauge transport `Γ_to⁻¹ ∘ g ∘ Γ_from`, restores strict cycle equality, and permits the residual only as a diagnostic suffix on `QuotientHolonomyConflict`. The re-attribution changes no stable totals.

## 26. `M6-CP1-CB7-A6` — relation validation recovered and compile/package green

CB7-A6 restores the two TB6 Review obligations without widening the product boundary. A5 HardRail publication now requires the accepted owner, different-region, reversed-route, and route-composed placement-transport predicates. Exact-A3 Periodic authority is converted from relation-endpoint gauge to placement gauge using the published endpoint state, and both endpoints must be acted on exactly. A6 retains strict direct-versus-selected-path equality; a conflict now reports the exact residual but still rejects. Before quotient-product acceptance, A6 relation certificates are rechecked against immutable A5 canonical transport, equivalence evidence, and selected-step authority. Focused identity 10 gains a tamper-away-from-A5 branch; focused identity 11 is unchanged.

Exact semantic source `40842caa88f8d7a08a38c91273ace77ebd7c0676` compiled all eight standard GMP/GMPXX targets in run/job `37078118843 / 111072482082`. Result artifact `11257522199` (`sha256:bbb18e89f41b959aa82e285c20b543ac9fea9f65fad6a07b0e6cfb1d989f10fd`) and log artifact `11257522202` (`sha256:a25f02b42ed950336eda2924c3345c10facf451260395af471838b087a37bef6`) are runtime-free, root manifest **28/28**, preflight/build `0/0`, with empty source-status receipts and source archive SHA-256 `2c8981c6da6e9e72b4977f2879a687e2ba1c6c042591bd82720936f69888d27f`. Selector449/routing449 remain byte-identical at `d4a0d1b7...d6414` / `9c88a5ed...c5707`, owners 32/301/75/41.

Candidate `11257522199 / 40842caa...` remains unpromoted. Reviewed runtime remains `10879581622 / 82b86a28...`; stable accounting stays **57/16/41**, debt 1. Exact next is `M6-CP1-TB7-A6-EXEC`, exact **11+449=460** fresh artifact-only processes using the packaged-fixture execution view, then mandatory `M6-CP1-TB7-A6-REV`. R4/A7/G4 remain held.

## 27. `M6-CP1-TB7-A6-EXEC` — complete 460-process gate is mechanically valid and semantic RED

TB7-A6 consumes CB7 package/source `11257522199 / 40842caa88f8d7a08a38c91273ace77ebd7c0676` immutably. Run/job `37090507571 / 111109661723` executes exactly 11 focused identities followed by selector449 as **460 fresh exact-filter processes**. Result/log artifacts are `11262587435 / 11262387973`; result self-manifest verifies **953/953**. Exact-one selection and zero skips hold; benchmark/configure/compile/relink/discovery/repair/mutation/retry are all absent; package/source/execution-view postflight is unchanged.

Outcome is focused **11/11 PASS**, selector **432/449 PASS**, aggregate **443/460 PASS / 17 RED**. Exact RED selector ordinals are `115,116,122,130,132,134,137,141,143,150,176,201,217,227,230,231,446`. Relative to TB6, focused6 and rows139/142 recover. Row446 remains RED under a new post-materialization assertion, and 16 accepted-green selector rows newly turn RED. No raw log contains `QuotientHolonomyConflict` or `OccurrenceInvalidCornerAuthority`; selectors140/232/444/448/449 and focused10/11 remain green.

EXEC records three non-stable Review-owned candidates: (1) HardRail canonical route transport is carrier/transition authority, not a cross-region placement-gauge map, so CB7's new `action_matches` gate falsely rejects established valid HardRail paths and makes downstream feature-chain seams unreachable (`RP-01` candidate); (2) rows227/230 are still rejected but the restored early reciprocal-route check shadows their accepted `InvalidHardRailAuthority` typed route-topology failure (`VALIDATION_ORDER_SHADOWING` candidate); (3) row446 now materializes and has no holonomy conflict, but its selector assertion still compares RA-13 placement-gauge `appliedTransport` with the relation-endpoint/stored action (`RP-05` test-authority candidate).

Stable accounting remains **57 / 16 / 41**, debt 1. Candidate remains unpromoted and reviewed runtime remains TB5 `10879581622 / 82b86a28...`, selector449 449/449. Exact next is mandatory runtime-free `M6-CP1-TB7-A6-REV`; R4/A7/G4 remain held.

## 28. `M6-CP1-TB7-A6-REV` — HardRail authority-domain split proved; CB8-A6 frozen

Runtime-free Review independently verifies TB7 result `11262587435` (953/953 self-manifest) and exact semantic source, rejects candidate `11257522199 / 40842caa...`, and retains TB5 `10879581622 / 82b86a28...` as reviewed runtime authority. TB7's **443/460** RED is adjudicated into two stable existing-pattern recurrences plus one non-stable test-authority defect.

CAND-01 is one `RP-01 / AUTHORITY_DOMAIN_CONFLATION` recurrence: HardRail `CanonicalRoute` is carrier/topology/transition evidence and cannot be used as the quotient placement map. RA-14 derives one exact placement `GridAutomorphism` independently from both paired endpoint `LocalLatticeState`s, stores it in HardRail `equivalence.action`/canonical transport, preserves route separately, and requires completion selected-step transport validation to consume action rather than route composition. The direct failures 115/116/141/143/150/217/231 and downstream reachability losses 122/130/132/134/137/176/201 share this first mechanism.

CAND-02 is one `VALIDATION_ORDER_SHADOWING` recurrence: rows227/230 still fail closed, but pair reciprocity pre-empts their accepted `InvalidHardRailAuthority`. RA-15 moves/extracts the existing individual route validator before A5 pair publication while preserving valid-route pair mismatches 139/142 as `InvalidHardRailTransport`.

CAND-03 (selector446) is closed non-stable test authority. Production now materializes, focused6 and periodic controls pass, and raw holonomy conflicts are zero; the only stale assertion compares placement-gauge selected transport with relation-endpoint `SurfacePeriodicHolonomy::action()`. CB8 may migrate only that assertion body to an independent direct-placement plus gauge-conjugation oracle.

Stable accounting becomes **59 / 16 / 43**, debt 1. Exact successor is bounded runtime-free `M6-CP1-CB8-A6`; compile/package green -> fresh `M6-CP1-TB8-A6-EXEC` **11+449=460** -> mandatory Review. R4/A7/G4 remain held. Full current authority is `Architecture_M6_CP1_TB7_A6_Review_Record.md`; normative amendments are RA-14/RA-15 at the end of `Architecture_M6_Frozen_Definitions.md`.

## 29. `M6-CP1-TB7-A6-REV` review-agent addendum — RA-16; Finding C overturned; CB8 amended

The review agent re-derives the TB7 evidence: digest, 953/953 manifest, ledgers, selector order and raw logs. It verifies the downstream-row grouping in code, since component products are published only on success (`RemeshPipeline.cpp:11912`, `:14302`).

**Finding A.** The diagnosis is confirmed: HardRail route steps carry identity transport (`SurfaceCellTracing.cpp:11670-11672`). The remedy is corrected.
- `LocalLatticeState.branchRotation` is face-gauged: `faceBranchRotation` is propagated per region (`:12094`, `:16324`, `:14920-14985`).
- So RA-14's `R = branch(b) ∘ branch(a)⁻¹` is off by the field matching across the rail.
- Every gate HardRail fixture has a constant field, so the gate cannot see this. Real fields fail closed.
- RA-16 §2 replaces it with a coordinate-rigid derivation from occurrence placements, with no branch comparison.

**Finding B.** Confirmed. Route validity is pinned to A5 (RA-16 §5).

**Finding C, overturned.**
- CB7's A5 sets the M5 lineage `SelectedRelationStep.appliedTransport` from `canonicalTransport` (`:4357`), and A6 enforces that equality (`:4723`, `:4749`).
- RA-13 moved that field to the placement gauge.
- Production completion (`PureQuadCompletion.cpp:1086-1132`, run at `RemeshPipeline.cpp:10705-10719`) and selector446 both validate the step against the relation value.
- CAND-03 is therefore a stable `RP-01` recurrence.
- RA-16 §3 decouples the two values: `canonicalRelationValue` feeds the lineage, `canonicalTransport` feeds A6. Selector446 and completion stay unchanged.

**Latent periodic issue.** CB7's exact-A3 Γ is face-gauged. It is provably correct whenever it accepts, so it is carried to `M6-DEFN-R4` with a witness obligation.

**Gate.** The CB8 plan gains an amendment block: decoupling, coordinate-rigid HardRail, A5 route validity, focused 3 strengthened, and new focused 12 (`M6CP1.RelationPlacementTransportIsCoordinateRigidAndFaceGaugeInvariant`). TB8 = **12+449 = 461**.

**Accounting.** **60 / 16 / 44**, debt 1. Lessons 186-187. Full text: `Architecture_M6_CP1_TB7_A6_Review_Record.md`, addendum §G1-§G7.

## 30. `M6-CP1-CB8-A6` — RA-16 implemented; compile/package GREEN

CB8 implements only the RA-16 amendment. HardRail placement transport is now one coordinate-rigid `GridAutomorphism` derived from the two occurrence-placement coordinate pairs at equal scale, independent of branch rotations. Carrier/topology authority remains `equivalence.route` and `equivalence.action = route.composed_transport()`. A5 evidence gains independent `canonicalRelationValue`; selected lineage steps consume that value, while `canonicalTransport` remains A6 placement/certificate authority. Exact HardRail route validity is A5-owned through one shared `exact_interior_route_valid` helper, with the new typed A5 failure mapped back to legacy `InvalidHardRailAuthority`. Focused 3 is strengthened and focused 12 adds coordinate-rigid / face-gauge-invariance coverage.

The required lineage proof re-opens pre-CB7 source `a532f803...`: OrdinaryFront identity (`:4117`), HardRail route action (`:4122-4123`), exact-A3 orientation-correct semantic action (`:4160-4165`) and non-A3 chosen action/inverse (`:4169-4182`) are reproduced by CB8 `storageRelationValue` at `:4265`, `:4270-4271`, `:4374-4379`, `:4403-4404`, then canonically inverted under the same storage direction at `:4452-4456`. `SelectedRelationStep.appliedTransport` consumes it at `:4475`. `PureQuadCompletion.cpp` and selector446 remain unchanged.

Static closeout changed only `include/directional/pipeline/RemeshPipeline.h`, `src/pipeline/RemeshPipeline.cpp` and `tests/SurfaceCellTransitionQuotientTests.cpp`; `git diff --check` passed. Selector449 remains `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`, selector448 prefix `70ff08601bf244fcb4883e5d0601d5e7a3a44f52a8e855544a065c6ca5c75789`, routing449 `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707` with owner census 32/301/75/41. No A7/R4/G4 implementation appears.

The main patch applied in run/job `37101412649 / 111141538493` as semantic commit `2b182f1c...`. Initial compile `37101508913 / 111141817614` configured/preflighted but exposed a declaration-order-only test compile defect: new focused-test bodies referenced `first_edge_of_kind` before its later declaration. A bounded body-local test-helper repair applied in `37101918608 / 111142995689`, yielding exact source `8e0818b1e2f8d12b86c64d8774a3572c5ed5266c`.

Mandatory compile retry `37101997642 / 111143233041` is GREEN: all eight standard targets compile, preflight/build status is 0/0, GMP/GMPXX are discovered and present on the authoritative generated link command, clean source-status receipts hold, the self-excluding package manifest verifies, and `runtimeExecution=false`. Candidate artifact `11265967968` hashes `022a35378a58463b892f1bf1d5113f726c2cc7cb8939892b24acd1da62259c4b`; log artifact `11266127622` hashes `a435590a67884432e848298ab064934b04d39674831340854bfbc2c1bcf474cd`.

CB8 grants compile/package evidence only. Candidate remains unpromoted; reviewed runtime remains TB5 `10879581622 / 82b86a28...`; stable accounting remains **60 / 16 / 44**, debt 1. Exact next is artifact-only `M6-CP1-TB8-A6-EXEC`: focused 1-12 in order then selector449 in file order with routing449, **461 fresh exact-filter processes**, benchmark 0, recovery-green **461/461**, then mandatory Review. Full CB8 evidence: `Architecture_M6_CP1_CB8_A6_Code_Build_Report.md`.

## 31. `M6-CP1-TB8-A6-EXEC` — complete 461-process recovery gate is mechanically GREEN

TB8 consumes CB8 candidate `11265967968 / 8e0818b1e2f8d12b86c64d8774a3572c5ed5266c` immutably. Run/job `37121395619 / 111198068572` executes exactly 12 focused identities followed by selector449 as **461 fresh exact-filter processes**. Result/log artifacts are `11273611682 / 11274345428`; result digest `55647d752e97cb71062c23475fe76bb870d0329c5f957ca819ccebc809e6ad05`; self-manifest **954/954**.

Outcome is focused **12/12**, selector **449/449**, aggregate **461/461 PASS**, exact-one, zero skips, benchmark 0. Focused12 and every prior TB7 RED row recover; critical controls pass; raw diagnostic census is zero. Package/source/execution-view/fixture postflight is unchanged; selector/routing are unchanged; candidate root manifest remains 28/28. EXEC creates no new candidate and does not reprice stable history: **60 / 16 / 44**, debt 1. Candidate remains unpromoted pending mandatory runtime-free `M6-CP1-TB8-A6-REV`; R4/A7/G4 remain held.

## 30. `M6-CP1-TB8-A6-REV` (+ review-agent addendum) — RA-16 recovery proved; runtime promoted; R4 bounded (RA-17)

**Evidence.** `M6-CP1-CB8-A6` implements RA-16 at `8e0818b1`:
- coordinate-rigid HardRail `canonicalTransport` from occurrence placements;
- `canonicalRelationValue` feeding the lineage step and the A6 step checks;
- A5-owned route predicate;
- focused 3 strengthened; new focused 12.

`M6-CP1-TB8-A6-EXEC` passes **461/461** (run `37121395619`, result `11273611682`, 954/954). Review promotes `11265967968 / 8e0818b1...`.

**Review-agent addendum.**
- Re-derives the evidence and confirms promotion.
- Corrects TB8-REV §3: selector446 replicates the production completion comparator rather than executing it. A witness production-completion identity is pre-registered for the first A7 CB.
- Freezes `Architecture_M6_CP1_Required_Green_Focused_12.txt` (SHA-256 `59a523ae...3d571c`) as a required-green prefix.
- Freezes **RA-17**:
  - transport guard: A6 placement transport's only consumer is the strict cycle rule;
  - R4 bounded to CP1 exit;
  - gauge obligations → `M6-DEFN-R5` (CP3-entry).
- Writes `Architecture_M6_DEFN_R4_CP1_A7_Thin_Adapter_G4B002_Definition_Plan.md` (D4 census first; D1 A7 with exact-support certificate; D2 adapter 55-site classification; D3 `G4-B002`; D5 CBs).
- Records lesson 188.

**Accounting.** 60 / 16 / 44, debt 1.

## 31. `M6-DEFN-R4` and `M6-DEFN-R4-REV` — A7 / thin adapter / `G4-B002` defined; accepted with RA-18 – RA-21

**R4 deliverables:**
- D4 census: 1,189 exact sites.
- D1: A7 `SourceAttachedGeometryProduct`, with typed support certificate, frozen representative key, class-wide lineage, RA-17 guard, typed failures and no new hash fields.
- D2: 55 adapter sites partitioned 31 / 4 / 19 / 1; thin predicate.
- D3: A6 `SurfaceQuotientClosedComplexView`, with side-incidence edges, labels and strip closure, plus a torus migration oracle.
- D5: CB9 (469) → CB10 (473) → CB11 (477) → `M6-CP1-CLOSE-REV`.

**Review** verified the pinned-literal claim (rows 212, 227/230, 139/140/142) and froze four amendments:
- **RA-18:** a reject-only same-simplex point guard. The `1e-9` check was the only cross-relation point-coincidence detector. Support comes from A5 only.
- **RA-19:** A5 placement after existing checks; behavioral identity 24.
- **RA-20:** protection from source hard-feature authority. The torus's 18 hard edges are PeriodicCut carriers.
- **RA-21:** oracle key path `(proposalId, proposalSide)` → `CellId`/side, with a stop rule.

Lessons 189-190. Accounting 60 / 16 / 44. Exact next: `M6-CP1-CB9-A7`.

## 33. `M6-CP1-TB9-A7-REV` review-agent addendum — failing clause deduced; RA-22a

The review agent re-derives TB9 (468/469; sole RED focused 20) and upholds the CB9 A7 producer against RA-18.

**Failing clause.** The false clause in the completion destination predicate is deduced statically: destination sheet ≠ representative sheet.
- End-chart resolution, region membership and component equality are all enforced earlier.
- A6 paths run root → target, and the A7 representative is not the root.
- So RA-22's sheet membership is the operative fix.

**RA-22a** adds the `:dest-unresolved` / `:dest-region` / `:dest-sheet` / `:dest-component` and `:component-singleton` suffixes.

**Recorded:**
- the A7 cross-sheet certification proxy (owner: `M6-CP1-CLOSE-REV`);
- `τ` single-sourcing (owner: CB10);
- the promoted runtime is production-latent on these classes.

Lesson 191. Accounting 60 / 16 / 44. Exact next: `M6-CP1-CB9-A7-R1`.

## 35. `M6-CP1-TB9-A7-R1-REV` review-agent addendum — promotion confirmed; RA-22b

The review agent re-derives TB9-R1 (469/469; focused 20 green) and confirms the promotion of `11292072930 / 584f80fe...`.

**Finding.** Besides the authorized destination repair, R1 deleted the A7-branch reject-only guard that required the representative face's region and sheet to be in the retained class sets. RA-22 forbade only destination authority from the representative.

**Fix.** RA-22b restores the guard (`:representative-face`) in CB10 Goal T2, with a focused-20 negative. This is provably gate-neutral, because all pre-R1 TB9 processes passed that preflight.

**Recorded.** `M6-CP1-CLOSE-REV` must classify the remaining `sourcePoint`/provenance-face consumers.

Lesson 192. Accounting 60 / 16 / 44. Exact next: `M6-CP1-CB10-A5V` (473).

## 37. `M6-CP1-TB10-A5V-REV` review-agent addendum — move fidelity verified; RA-19a

The review agent re-derives TB10 (473/473 mechanical) and confirms the rejection: F1 (moved validation before `publish_records_for_validation`) and F2 (identity-24 under-coverage).

**Move fidelity.** A normalized predicate diff of the old adapter against the new A5 helper shows:
- 28 predicates identical;
- the side-count check re-bound from `occurrenceComplex->certificate().directedSideCount` to `phaseFront.cells().size()*4`;
- `MissingAuthoritativePhaseFront` / `InvalidAuthoritativePhaseFrontSource` / `InvalidAuthoritativeSourceChartTransitions` merged into the A5 codes `SourceAuthorityMismatch` / `InvalidChartAuthority`. They are unpinned and still fail-closed, but two causes now share one name.

**RA-19a:**
- the helper validates the published complex after the reorder;
- identity 24 gets an exact field oracle (TB10 record §J3);
- the merged-diagnostics item goes to CP1 close.

Lesson 194. Accounting 60 / 16 / 44. Exact next: `M6-CP1-CB10-A5V-R1` (473).

## 39. `M6-CP1-TB10-A5V-R1-REV` review-agent addendum — promotion confirmed; RA-21b readies CB11

The review agent re-derives TB10-R1 (473/473) and confirms the F1 reorder (publish first, then the moved checks on the published complex) and the F2 oracle (full struct-field census).

**CB11 pre-analysis** (`SurfaceCellTracing.cpp:17901-17916`; `SurfaceArrangement.cpp:2426`, `:2701-2709`):
- proposals map positionally to `phaseFront.cells()` and carry no `CellId`;
- `halfedge.proposalId` is only the primary provenance entry;
- cell sides are per-source-face polylines.

So RA-21's strict isomorphism cannot hold. **RA-21b** replaces it with positional preconditions, provenance-entry side chains, degree-2 contraction, and chain `hardFeature` == `hardFeatureProtected`, keeping the stop rule for every other kind of subdivision.

Lesson 195. Accounting 60 / 16 / 44. Exact next: `M6-CP1-CB11-G4` (477).

## 41. `M6-CP1-TB11-G4-REV` review-agent addendum — F2 overturned; RA-24; RA-21d

TB11 re-derived: 475/477, RED at focused 25 and 28. Ordinal 28's log shows an **empty** candidate vector.

**Cause.**
- R4 D3 §4.3 rule 7 unites quad-opposite edges (`RemeshPipeline.cpp:6289-6291`). That produces the strip's rung set, a matching.
- The extractor's path-degree classifier (`:6343-6436`, copied from the retired strand extractor `SurfaceComplexSimplification.cpp:1684-1740`, which split `(family, strand)` curves into connected edge chains) skips every rung set with two or more rungs.
- So no candidate is ever emitted on a closed quad complex, and RA-23's synthetic torus would fail too.

**Fixes.**
- **RA-24:** strip identity is edge-loop closure (the vertex-opposite edge at interior valence-4 vertices). The produced torus is expected to have eligible loops parallel to its hard cycles.
- **RA-21d:** per-side arrangement relaxation applies only across barrier seams; Ordinary non-isolation edges keep chain and node equality.
- **R1 re-scoped:** one production change (the strip relation) plus the oracles.

Lesson 196. Accounting 60 / 16 / 44. Exact next: `M6-CP1-CB11-G4-R1` (477).

## 43. `M6-CP1-TB11-G4-R1-REV` review-agent addendum — promotion confirmed; RA-25; CP1 close-out routing

The review agent re-derives TB11-R1 (477/477) and confirms the bounded RA-24 production change and the identity 25/28 oracles.

**M1.** The RA-24 continuation silently skips non-unique opposites (`RemeshPipeline.cpp:6305`). RA-25 makes it fail closed with `ClosedComplexStripContinuationMismatch`.

**Re-routing.** The CP1 carried obligations need code, so the successor moves from the runtime-free `M6-CP1-CLOSE-REV` to `M6-CP1-CB12-CLOSE`:
- C1: exact cross-sheet certification through `CornerWedgeIsolationTransition.fromSheet/toSheet`;
- C2: distinct A5 diagnostics;
- C3: A5-sourced isolation counter;
- C4: RA-25;
- C5: provenance-face consumer audit; `project_surface_cell_vertex_chart_authority` is pre-audited as class-wide.

Gate 30+449 = 479 → TB12 → Review → `M6-CP1-CLOSE-REV`.

Lesson 197. Accounting 60 / 16 / 44.

## 44. `M6-CP1-CB12-CLOSE-REV` — C5 stop discharged; RA-26

CB12 stopped on C5 because it judged the optimizer site `:3015-3031` anchor-assuming.

Review findings:
- The site reads only source-mesh incidence, inside `make_surface_optimization_overlay`, which has no production caller. This becomes OBS-01, owner M8-CP2.
- A full audit of 12 optimizer and validation sites found **no authority-deciding** consumer.
- The production optimizer energy/gradient (normal and field from corner 0's representative face) and the final-validation field-metric fallback are **reference-selecting**. They predate CP1. RA-26 §5 re-homes them to `M6-DEFN-R5` / `M6-CP3`, with a representative-permutation falsifier.

Owned review-agent errors: wrong C5 line anchors, and the RA-22b §5 class conflation (lesson 198).

Exact next: `M6-CP1-CB12-CLOSE-R1` (C1–C4, identities 29/30, gate 479). Accounting 60 / 16 / 44.

## 47. `M6-CP1-TB12-CLOSE-REV` review-agent addendum — RA-27 withdrawn; RA-27a

TB12 is re-derived at 478/479 and stays unpromoted. C2 and C3 are accepted. C4 fails closed, but its name string lacks the `Quotient` prefix and the branch has no executed falsifier.

**CAND-01.** The real cause is that the fixture has no disjoint-sheet relation: its diagonal seam crosses cell interiors, so crossings happen inside bridge corners. Disjoint-sheet relations require front edges collinear with a seam, which A6 already certifies exactly.

**C1 is incomplete.** The reachable per-occurrence wedge check is still the "any transition" proxy, and it fails open on a consistent chain.

**RA-27a** re-scopes R2:
- an exact wedge rule (site `cross-sheet:wedge`);
- the C4 name fix;
- identity 29 on a bridge-member tamper with A6 re-produced (the consistent-chain rule).

The edge-rule falsifier is deferred to the first produced seam-collinear fixture. OBS-01 (A6 → A5 binding) and OBS-02 (relation-kind-agnostic edge rule) are recorded. Lesson 199. Accounting 60 / 16 / 44.

## 48. `M6-CP1-TB12-CLOSE-R1-REV` — RA-27a recovery accepted; 479/479 runtime promoted

Independent Review re-derives R1 runtime `37280517630 / 111667316992` from result/log `11333591947 / 11333547162`: self-manifest **497/497**, focused30 **30/30**, selector449 **449/449**, aggregate **479/479 PASS**, exact-one, zero skips, benchmark 0 and immutable postflight. Focused28 remains the exact prefix of focused30; selector449/routing449 remain byte-identical.

RA-27a is accepted. A7's member-local wedge graph exactly matches the frozen region/sheet connectivity rule; C4's diagnostic carries the required `Quotient` prefix; focused ordinal29 non-vacuously keeps the wedge-transition vector non-empty, republishes A5, re-produces A6 successfully and reaches the exact A7 `cross-sheet:wedge` rejection. The old non-empty proxy would accept that tamper, so the test discriminates. `M6-CP1-TB12-CLOSE-EXEC-CAND-01` is **CLOSED / RECOVERY PROVED / NON-STABLE** and does not affect stable totals.

Package/source `11330703256 / 3f40f04a0e9d382b2ec82cf37a03c18ad405eb05` is promoted as current reviewed M6 runtime authority. Accounting stays **60 / 16 / 44**, debt 1. C1 wedge completion and C4 name are discharged. RA-27a §6 edge-rule falsifier, OBS-01/02 and RA-26 §5 remain with their later frozen owners. CP1 remains ACTIVE; exact next is runtime-free `M6-CP1-CLOSE-REV` under `Architecture_M6_CP1_Close_Review_Plan.md`.

## 49. `M6-CP1-TB12-CLOSE-R1-REV` review-agent addendum — promotion confirmed; RA-27b

The review agent re-derives R1 at 479/479, with all raw-log hashes matching, and confirms:
- the RA-27a wedge rule (exact, and fail-closed on malformed membership input);
- the C4 name fix, which DEFN-R3's `Quotient` prefix rule required;
- identity 29 on a consistent chain.

**Corrections:**
- Identity 29 runtime-proves one dimension of the rule. The region filter and connectivity versus "touches" are static (OBS-01, first CP2 CB).
- C4 has no executed falsifier (→ `M6-CP2-DEFN` weld witness). C2's empty-front branch is accepted as defensive.

**RA-27b** amends the close plan:
- verbatim exit items;
- defensive-branch classification;
- `G4-B002` stays open;
- post-closure successor `M6-CP2-DEFN`, which absorbs the A6 → A5 / A7 → A6 certificate binding and RA-26 §5(iii). `M6-DEFN-R5` follows CP2.

Lesson 200. Accounting 60 / 16 / 44.

## 51. `M6-CP2-DEFN-REV` — CP2 verifier Definition accepted with RA-28a

**Accepted architecture:**
- copy-by-value record views as the negative seam, with no unchecked factory;
- C4 accepted-defensive, with verifier manifoldness as its falsifier;
- three wedge tampers;
- A8 after A7 and before projection;
- gate 30 + 12 + 449 = 491.

**RA-28a amends:**
- §1: exact-once bijection, forest = Joining, published-forest spanning, strict cycle closure;
- §2: an exact field table (A6 copies A5 `id`, endpoints, `equivalence`, `canonicalSelectedStep` and `canonicalTransport` verbatim), with a stop rule if a producer transforms;
- §3: A5 wedge, binding, sheet, seam and support checks against A0;
- §4: dependency gating;
- §5: drop `ForbiddenGeometricWeld` / `UpstreamFailureSubstitution`;
- §6: a `VerifiedSurfaceProducts` type invariant and a stage function;
- §7: the optimizer check gated on `retained`, plus the representative-face precondition;
- §8: tamper precision;
- §9: the A0 tuple and `VerificationFailed:<code>:<site>`.

No new identities. Lesson 201. Exact next `M6-CP2-CB1-VERIFIER`.

## 52. `M6-CP2-CB1-VERIFIER-REV` — RA-28a §7 stop discharged; RA-28b

CB1 stopped because RA-28a §7 required a fact that A5/A7 do not publish: that `selectedFace` belongs to `cornerWedgeBindings`. Review confirms that, and traces the cause to RA-28a §7 itself. It had over-tightened RA-26 §5(iii) from sheet membership to face membership (review-agent error).

**Adjudication:**
- No A5 invariant: the representative face stays representation-only (RA-22b §2).
- No optimizer check. Authoritative `project_vertices` confines projections to the seed's own face or scope, so any optimizer check re-tests a static property that is certified by the completion guard and the verifier before movement, and by final validation after.
- The self-check is retained as non-authoritative.
- Identity 12 is re-specified as a confinement falsifier. Gate 491.
- Note for `M6-DEFN-R5`'s reference work.

Lesson 202. Exact next `M6-CP2-CB1-VERIFIER-R1`.

## 53. `M6-CP2-TB1-VERIFIER-REV` — first verifier candidate rejected; RA-29 recovery

Independent Review re-derived the 491-process evidence at **488/491** and confirms that focused12 ordinals 2/6/7 are false-rejection witnesses rather than accepted-green regressions: the source-face permutation canonicalizes to the same topology key, the `OrdinaryFront` selected-step reset is already empty, and the square fixture cannot construct the intended disjoint-cell pinch.

Static review additionally finds four RA-28a gaps: the successful full pipeline result does not carry its A8 `VerificationReport`; identity 8's alternate region is not proved to be an A0 region; verifier support incidence duplicates local logic rather than cross-checking the published point with `SurfacePointSourceSupportResolver`; and selected-path verification composes the self-declared path without first proving it is the unique traversal of the published selected forest.

RA-29 limits recovery to those seven surfaces. No optimizer source change, A5 semantic expansion, selector/focused reordering, or gate reduction is authorized. Candidate `11365308211 / 265c8fbb...` stays unpromoted. Stable accounting remains **60 / 16 / 44**, debt 1. Exact successor is `M6-CP2-CB1-VERIFIER-R2`, then a fresh 491-process R1 EXEC and mandatory R1 Review.

## 54. `M6-CP2-TB1-VERIFIER-REV` review-agent addendum — RA-29a

The review agent re-derives TB1 at 488/491, with all raw hashes matching. It confirms CAND-01..03 and REV-OBS-01/03/04, extends REV-OBS-03 to A7, and withdraws REV-OBS-02: identity 8's site assertion already pins the region filter, so an A0-valid region adds only fixture risk.

**New defects, all fixed in R2 under RA-29a:**
- a class split along a `Joining` forest edge passes (→ `a6:relation-class`, plus |forest| = Σ(|members| − 1));
- quadratic topology loops in a production stage;
- first-match A7 step binding (→ exact citation via the A6 path `orderedRelations`);
- no A0 component-adjacency recompute;
- an address-bound `VerifiedSurfaceProducts`.

Plus precision for identities 6 and 7. Gate 491. Lesson 203.

## 55. `M6-CP2-TB1-VERIFIER-R1-REV` review-agent addendum — RA-29c

R1 (462/491) is re-derived from the job log, and the clustering is confirmed:
- 19 failures at `a7:a5-relation-step`;
- 1 at `a0:component-adjacency` (selector 144);
- 9 downstream reachability failures.

Both causes trace to RA-29a §3/§4 (review-agent errors, owned).

RA-29b's same-owner-ID fallback would falsely reject. A5 inverts `canonicalRelationValue` on non-canonical storage, so same-ID relations can carry inverse values (nonzero-Z4 torus). **RA-29c** binds exactly in three hops, mirroring the producer construction chain:
- A5 `canonicalSelectedStep.appliedTransport == canonicalRelationValue`;
- each A6 path's `legacyProjection` equals the oriented step subsequence along its own `orderedRelations`;
- A7 `selectedRelationPaths` equals the sorted-unique set of the class's A6 projections.

This needs no ambiguity witness and is O(P log P). Identity 11's ownership check becomes behavioral. Lesson 204.

## 56. `M6-CP2-TB1-VERIFIER-R2-REV` review-agent addendum — CP2 closure revoked; RA-29d

The review agent re-derives R2 TB at 491/491, with all raw hashes matching, and confirms RA-29c and the promotion of `c64baacd`.

**CP2 closure is revoked:**
- U1: the RA-28a §2 A7 vertex binding is unimplemented (a moved, self-consistent vertex verifies);
- U2: most verifier predicates have no executed negative witness, and identity 5 covers one of ten §6.3 classes;
- U3: two dead failure codes;
- U4: no closure record.

**RA-29d** routes `M6-CP2-CB2-COVERAGE`:
- G1 `a7:vertex-binding`;
- G2 dead codes;
- G3 coverage folded into identities 2–5;
- G4 coverage table.

Gate 491. Then TB → `M6-CP2-CLOSE-REV` → `M6-DEFN-R5`. Lesson 205.

## 57. `M6-DEFN-R5-REV` — CP3-entry Definition accepted with RA-30a

D1–D9 are reviewed against source and gates, and the 497 entry / 507 final arithmetic is verified.

**RA-30a:**
- A4 publishes the typed hard-feature set for A5 (no A5 signature change);
- D2 needs a produced two-region, non-constant-field HardRail fixture with a 90° or 270° gauge difference;
- D3 certifies the branch across a seam with the validated seam quarter-turn, and keeps full equality including phase off seams;
- CB2 builds the historical target for GP26/GP27, and stops if it fails;
- D6 needs canonical accumulation order or a Review-approved relaxed equality;
- the scheduler permutation is defined (A4 containers + A5 relation order);
- the D1 witness is the produced nonzero-Z4 torus with a non-involutive gauge difference;
- D2 site `:branch-certificate`.

CB1 is released. Lesson 206.

## 58. `M6-CP3-TB1-ENTRY-REV` review-agent addendum — RA-31 published; RA-31a

The review agent re-derives 373/497 and confirms the exact 124-row partition, CAND-01/02/04/06/07 and accounting 63 / 17 / 46.

**CAND-05 is re-adjudicated.** The RA-30 §2 HardRail certificate strips each endpoint's region-relative face gauge, while TB7 §G2's derivation requires stripping the cross-rail field matching τ. The rule holds only if `F_b − F_a = τ`, which is unproven, and A5 rejects the only nonzero-gauge HardRail fixture.

**RA-31a:**
- withdraw the certificate rejection, keeping coordinate-rigid transport and the gauge evidence;
- identity 2 pre-registered RED, with A5 error printing;
- identity 6 must pass;
- a T2 stop rule;
- `M6-DEFN-R5-R1` redefines D2 via τ with a discriminating produced witness.

Lesson 207.

## 59. `M6-CP3-TB1-ENTRY-R1-REV` — R1 rejected; RA-32 Definition repair

R1 execution `37645974118 / 112876903729` on `11488700954 / 68000a95...` is mechanically valid at **482/497**, exact-one 497/497, zero skips, benchmark 0 and immutable postflight. Review rejects/unpromotes it. Ten A6/D7 REDs are failed recovery of predecessor CAND-02 (`RP-01 / AUTHORITY_DOMAIN_CONFLATION`): the special seam branch still depends on raw global sheet inequality before certificate-owned seam authority is established. Predecessor incomplete-publication and focused-relabel stable regressions are recovery-proved; the `RP-01` event remains open.

D1 lacks an organic exact-A3 90°/270° witness; D3/D7 lack a real-produced seam-collinear OrdinaryFront; D4 selects an ordinary edge without proving a route; D2 returns to RA-31a's `τ`-based definition owner. These are non-stable. Stable totals remain **63 / 17 / 46**, debt 1. RA-32 routes exact next to runtime-free `M6-DEFN-R5-R1`, then mandatory Definition Review. R2 implementation and CB2 remain held.

## Folded document index
| `Architecture_M6_CP3_TB1_Entry_Review_Record.md` | **SUPERSEDED PREDECESSOR ENTRY REVIEW / FOLDED BY R1 REVIEW.** RA-31/RA-31a, predecessor 373/497 partition and stable accounting are preserved in §58, frozen definitions, tracker and git history. |
| `Architecture_M6_CP3_CB1_Entry_R1_Recovery_Code_Build_Plan.md` | **CONSUMED R1 RECOVERY PLAN / FOLDED BY R1 REVIEW.** P1/P2/T1/T2/T4 scope and RA-31a amendments are preserved in §§58-59, RA-31/31a/32 and git history. |
| `Architecture_M6_CP3_CB1_Entry_R1_WIP_Handoff.md` | **SUPERSEDED R1 CB WIP / FOLDED BY R1 REVIEW.** Compile/package identity and recovery execution facts survive in the retained R1 TB report, changelog and git history. |
| `Architecture_M6_CP3_TB1_Entry_R1_Exec_WIP_Handoff.md` | **SUPERSEDED R1 EXEC WIP / FOLDED BY R1 REVIEW.** Dispatcher/run/artifact and cleanup recovery facts are preserved in the retained R1 TB report, §59 and git history. |
| `Architecture_M6_CP3_TB1_Entry_R1_Review_WIP.md` | **SUPERSEDED R1 REVIEW ANALYSIS WIP / FOLDED BY R1 REVIEW CLOSEOUT.** Independent candidate adjudication is preserved in the retained R1 Review record, RA-32, tracker and §59; full text remains in git history. |
| `Architecture_M6_CP3_TB1_Entry_R1_Review_WIP_Handoff.md` | **SUPERSEDED R1 REVIEW CLOSEOUT WIP / FOLDED BY R1 REVIEW CLOSEOUT.** Patch/run/resume facts are superseded by the retained R1 Review record, current handoff/changelog, workflow mailbox and git history. |
| `Architecture_M6_CP3_TB1_Entry_Artifact_Only_Test_Benchmark_Report.md` | **SUPERSEDED PREDECESSOR TB REPORT / FOLDED BY R1 REVIEW.** 373/497 mechanics and candidate evidence are preserved in §58, tracker and git history; the R1 runtime report is current. |
| `Architecture_M6_CP3_TB1_Entry_Red_Classification.tsv` | **SUPERSEDED PREDECESSOR ROW CLASSIFICATION / FOLDED BY R1 REVIEW.** Exact predecessor partition is preserved in §58, prior review facts, tracker and git history. |

| `Architecture_M6_CP3_CB1_Entry_Authority_Code_Build_Plan.md` | **CONSUMED CP3 ENTRY CB PLAN / RETIRED BETWEEN REVIEWS.** RA-30/RA-30a entry scope, stop rules and 497-process successor are preserved in §57, the current Review/RA-31 plan and git history. Historical resolver commit: `4eae760859ed48a7898d9383e583681111fe9023`. |
| `Architecture_M6_CP3_CB1_Entry_Authority_Code_Build_Report.md` | **SUPERSEDED CP3 ENTRY COMPILE REPORT / RETIRED BETWEEN REVIEWS.** Exact source/package/compile evidence is preserved in the retained TB report, current Review, changelog and git history. Historical resolver commit: `4eae760859ed48a7898d9383e583681111fe9023`. |
| `Architecture_M6_CP3_TB1_Entry_Exec_WIP_Handoff.md` | **SUPERSEDED EXEC WIP HANDOFF / RETIRED BETWEEN REVIEWS.** Active-run identifiers and resume facts are superseded by the retained TB report and current Review. Historical resolver commit: `4eae760859ed48a7898d9383e583681111fe9023`. |

| Retired filename | Disposition |
|---|---|
| `Architecture_M6_CP2_Definition_Plan.md` (86 lines) | **CONSUMED CP2 DEFINITION PLAN / FOLDED BY M6-CP2-TB1-VERIFIER-REV.** D1-D6 scope, runtime-free boundary and successor chain are preserved in §51, frozen definitions, current Review and git history. |
| `Architecture_M6_CP2_Definition_Record.md` (195 lines) | **SUPERSEDED CP2 DEFINITION RECORD / FOLDED BY M6-CP2-TB1-VERIFIER-REV.** Accepted definition substance and focused-12 architecture are preserved in §51, RA-28/RA-28a, current Review and git history. |
| `Architecture_M6_CP2_DEFN_Review_Record.md` (141 lines) | **SUPERSEDED CP2 DEFINITION REVIEW / FOLDED BY M6-CP2-TB1-VERIFIER-REV.** RA-28a adjudication and obligations are preserved in §51, frozen definitions, tracker and git history. |
| `Architecture_M6_CP2_CB1_Verifier_Code_Build_Plan.md` (59 lines) | **CONSUMED/SUPERSEDED CB1 VERIFIER PLAN / FOLDED BY M6-CP2-TB1-VERIFIER-REV.** RA-28a/RA-28b implementation boundary and gate are preserved in §§51-53, frozen definitions, current Review/R2 plan and git history. |
| `Architecture_M6_CP2_CB1_Stop_Review_Record.md` (100 lines) | **SUPERSEDED CB1 STOP REVIEW / FOLDED BY M6-CP2-TB1-VERIFIER-REV.** RA-28b correction and no-optimizer ruling are preserved in §52, frozen definitions, current Review and git history. |
| `Architecture_M6_CP2_CB1_Verifier_Code_Build_Report.md` (74 lines) | **SUPERSEDED CB1/R1 COMPILE REPORT / FOLDED BY M6-CP2-TB1-VERIFIER-REV.** Candidate source/package/compile authority is retained in the current TB report, §53, changelog and git history. |
| `Architecture_M6_CP1_CB12_Close_R2_Oracle_Recovery_Code_Build_Plan.md` (56 lines) | **CONSUMED R2 PLAN / FOLDED BY TB12-CLOSE-R1-REV.** RA-27a implementation scope, stop rules and 479-process recovery gate are preserved in §47-§48, frozen definitions, current Review and git history. |
| `Architecture_M6_CP1_CB12_Close_R2_Code_Build_Report.md` (51 lines) | **SUPERSEDED R2 COMPILE REPORT / FOLDED BY TB12-CLOSE-R1-REV.** Exact source `3f40f04a...`, compile run/job/artifacts, 28/28 GMP package and runtime-free evidence are preserved in §48, changelogs and current runtime report. |
| `Architecture_M6_CP1_TB12_Close_Artifact_Only_Test_Benchmark_Plan.md` (39 lines) | **CONSUMED ORIGINAL TB12 PLAN / FOLDED BY TB12-CLOSE-R1-REV.** The original 479-process immutable gate and preflight are preserved in §§45-47 and git history. |
| `Architecture_M6_CP1_TB12_Close_Artifact_Only_Test_Benchmark_Report.md` (45 lines) | **SUPERSEDED ORIGINAL TB12 REPORT / FOLDED BY TB12-CLOSE-R1-REV.** The 478/479 mechanics and ordinal29 false-rejection evidence are preserved in §§46-47, tracker and git history. |
| `Architecture_M6_CP1_TB12_Close_Review_Record.md` (181 lines) | **SUPERSEDED TB12 REVIEW + RA-27a ADDENDUM / FOLDED BY TB12-CLOSE-R1-REV.** CAND-01 adjudication, RA-27a, observations and routing are preserved in §§46-48, frozen definitions, tracker and git history. |
| `Architecture_M6_CP1_TB12_Close_R1_Artifact_Only_Test_Benchmark_Plan.md` (39 lines) | **CONSUMED R1 EXEC PLAN / FOLDED BY TB12-CLOSE-R1-REV.** Exact artifact/source/digests, 30+449 execution contract and immutable postflight are preserved in current R1 runtime report, §48 and git history. |
| `Architecture_M6_CP1_CB5_Ordinary_Front_Seam_Classification_Recovery_Code_Build_Plan.md` (94 lines) | **CONSUMED CB5 PLAN / FOLDED BY TB7-A6-REV.** Ordinary-front recovery scope and accepted TB5 outcome are preserved in §§20-22, tracker, frozen definitions and git history. |
| `Architecture_M6_CP1_CB7_A6_Code_Build_Report.md` (107 lines) | **SUPERSEDED CB7 COMPILE REPORT / FOLDED BY TB7-A6-REV.** Source `40842caa...`, compile run/job `37078118843 / 111072482082`, candidate artifact `11257522199`, 28/28 package and runtime-free evidence are preserved in §§26-28, TB7 report/current Review and changelog. |
| `Architecture_M6_CP1_CB7_A6_Relation_Validation_Recovery_Code_Build_Plan.md` (138 lines) | **CONSUMED CB7 PLAN / FOLDED BY TB7-A6-REV.** RA-13 periodic recovery, HardRail stop rule and 460-process successor are preserved in §§25-28, frozen definitions and current Review. |
| `Architecture_M6_CP1_TB4_Artifact_Only_Test_Benchmark_Report.md` (60 lines) | **SUPERSEDED TB4 REPORT / FOLDED BY TB7-A6-REV.** Runtime mechanics/findings are preserved in §§18-20, tracker and git history. |
| `Architecture_M6_CP1_TB4_Review_Record.md` (224 lines) | **SUPERSEDED TB4 REVIEW / FOLDED BY TB7-A6-REV.** RP-01 adjudication, RA-12 and recovery scope are preserved in §§19-20, frozen definitions, tracker, lessons and git history. |
| `Architecture_M6_CP1_TB5_Artifact_Only_Test_Benchmark_Report.md` (62 lines) | **SUPERSEDED PER-TURN TB5 REPORT / FOLDED BY TB7-A6-REV.** Accepted 456/456 runtime authority `10879581622 / 82b86a28...` remains explicitly preserved in §§21-22, current Review, tracker/changelog and git history. |
| `Architecture_M6_CP1_TB5_Review_Record.md` (158 lines) | **SUPERSEDED TB5 REVIEW / FOLDED BY TB7-A6-REV.** Runtime promotion, CP1 scope correction and carried A6/A7 obligations are preserved in §§22-23, frozen definitions, orientation/roadmap and git history. |
| `Architecture_M6_CP1_TB6_A6_Review_Record.md` (263 lines) | **SUPERSEDED TB6 REVIEW / FOLDED BY TB7-A6-REV.** Authoritative second TB6 run, HardRail reciprocity recovery and corrected RA-13 gauge analysis are preserved in §§24-28, frozen definitions, tracker/lesson184 and git history. |
| `Architecture_M6_CP1_TB7_A6_Artifact_Only_Test_Benchmark_Plan.md` (90 lines) | **CONSUMED TB7 PLAN / FOLDED BY TB7-A6-REV.** Immutable candidate, 11+449 process contract, recovery falsifiers and no-retry boundary are preserved in §§26-28, current TB7 report/Review and git history. |
| `Architecture_M6_CP1_CB6_A6_Quotient_Product_Extraction_Code_Build_Plan.md` | **CONSUMED CB6-A6 PLAN / FOLDED BY TB6-A6-REV.** Scope, RA-1-RA-4 implementation obligations, four focused identities, compile boundary and 460-process successor are preserved in §§23-25, frozen definitions, current Review/CB7 plan and git history. |
| `Architecture_M6_CP1_CB6_A6_Code_Build_Report.md` | **SUPERSEDED CB6-A6 COMPILE REPORT / FOLDED BY TB6-A6-REV.** Exact source, compile run/job/artifacts, 28/28 GMP package and runtime-free authority are preserved in §23, changelog, handoff and git history. |
| `Architecture_M6_CP1_TB6_A6_Artifact_Only_Test_Benchmark_Plan.md` | **CONSUMED TB6-A6 PLAN / FOLDED BY TB6-A6-REV.** Candidate, exact 11+449 order, immutable process boundary and pre-registered holonomy falsifier are preserved in §§24-25, current Review and git history. |
| `Architecture_M6_CP1_TB6_A6_Artifact_Only_Test_Benchmark_Report.md` | **SUPERSEDED/INCOMPLETE EXEC REPORT / FOLDED BY TB6-A6-REV.** Its first-run orchestration evidence is preserved, while §24 and current Review record the authoritative second run that the report omitted. Full text remains in git history. |
| `Architecture_M6_CP1_CB6_Legacy_Occurrence_Field_Retirement_Code_Build_Plan.md` | **SUPERSEDED STANDALONE CB6 PLAN / FOLDED BY TB6-A6-REV.** Legacy-field retirement was absorbed into CB6-A6 and compiled; retained facts are preserved in §§22-23 and frozen CP1 exit scope. |
| `Architecture_M6_CP1_TB3_Artifact_Only_Test_Benchmark_Report.md` (64 lines) | **SUPERSEDED TB3 RUNTIME REPORT / FOLDED BY M6-CP1-TB4-REV.** TB3 447/455 mechanics, eight `MissingIsolationSeamEquivalenceAuthority` outcomes and immutable artifact authority are preserved in §§9-11, tracker, current TB4 Review and git history. |
| `Architecture_M6_CP1_TB3_Review_Record.md` (181 lines) | **SUPERSEDED TB3 REVIEW / FOLDED BY M6-CP1-TB4-REV.** The stable RP-01 event, definition-chain handoff and carried recovery obligations are preserved in §§10-16, tracker, current TB4 Review and git history. |
| `Architecture_M6_CP1_CB4_Code_Build_Report.md` (104 lines) | **SUPERSEDED CB4 COMPILE REPORT / FOLDED BY M6-CP1-TB4-REV.** Exact source `20f60bb...`, compile run/artifacts, eight-target GMP/GMPXX and runtime-free authority are preserved in §§17-19, changelogs, current TB4 report/Review and git history. |
| `Architecture_M6_CP1_CB4_Per_Face_Branch_Authority_Blocker.md` (113 lines) | **RESOLVED CB4 STATIC BLOCKER / FOLDED BY M6-CP1-TB4-REV.** RA-11 facts/resolution are preserved in frozen definitions, §16, tracker/changelogs and git history. |
| `Architecture_M6_CP1_CB4_Relation_Owned_Isolation_Equivalence_Code_Build_Plan.md` (177 lines) | **CONSUMED CB4 PLAN / FOLDED BY M6-CP1-TB4-REV.** R2+RA scope, stop rules and 456-process gate are preserved in §§12-18, normative definition records, TB4 report/current Review and git history. |
| `Architecture_M6_CP1_CB3_Authority_And_Multi_Isolation_Recovery_Code_Build_Plan.md` (100 lines) | **CONSUMED CB3 PLAN / FOLDED BY M6-CP1-TB3-REV.** HardRail recovery, multi-isolation first-loss scope, frozen six+449 runtime surface and stop rules are preserved in §8-§10, the TB3 report/Review and current CB4 plan; full text remains in git history. |
| `Architecture_M6_CP1_CB3_Authority_And_Multi_Isolation_Recovery_Code_Build_Report.md` (62 lines) | **SUPERSEDED CB3 COMPILE REPORT / FOLDED BY M6-CP1-TB3-REV.** Exact source, compile run/job, artifact/digests, HardRail/outgoing-side changes and runtime-free package authority are preserved in §8-§10, changelogs and the retained TB3 Review; full text remains in git history. |
| `Architecture_M6_CP1_TB2_Artifact_Only_Test_Benchmark_Report.md` (70 lines) | **SUPERSEDED TB2 RUNTIME REPORT / FOLDED BY M6-CP1-TB3-REV.** TB2 453/455 mechanics, row140/multi-isolation candidates and immutable authority are preserved in §6-§7, tracker and TB3 Review prior-candidate dispositions; full text remains in git history. |
| `Architecture_M6_CP1_TB2_Review_Record.md` (93 lines) | **SUPERSEDED TB2 REVIEW / FOLDED BY M6-CP1-TB3-REV.** Validation-order event, multi-isolation recovery bound, TB1 carried clause and CB3 falsifiers are preserved in §7-§10, tracker and current Review; full text remains in git history. |
| `Architecture_M6_CP1_TB3_Artifact_Only_Test_Benchmark_Plan.md` (54 lines) | **CONSUMED TB3 EXEC PLAN / FOLDED BY M6-CP1-TB3-REV.** Candidate identity, six+449 exact-process contract, immutable pre/postflight, recovery-green shape and mandatory Review successor are preserved in §9-§10, the retained TB3 report and Review; full text remains in git history. |
| `Architecture_M6_DEFN_Occurrence_Embedding_Verifier_Plan.md` | **CONSUMED M6-DEFN PLAN / FOLDED BY M6-DEFN.** All required outputs, falsifiers, blocker/debt ownership, dormant-test dispositions and successor constraints are preserved in `Architecture_M6_Frozen_Definitions.md` and this record; full text remains in git history. |
| `Architecture_M6_CP1_CB1_Occurrence_Product_Code_Build_Plan.md` (78 lines) | **CONSUMED CB1 PLAN / FOLDED BY M6-CP1-TB1-REV.** Its A5-only scope, semantic `OccurrenceId`, retained/deleted focused-test dispositions, GMP compile boundary and no-runtime constraints are preserved in §2, the frozen definitions and the TB1 Review record; full text remains in git history. |
| `Architecture_M6_CP1_CB1_Occurrence_Product_Code_Build_Report.md` (94 lines) | **SUPERSEDED CB1 COMPILE REPORT / FOLDED BY M6-CP1-TB1-REV.** Exact source/package/run identities, eight-target GMP/GMPXX compile evidence, selector449 preservation and compile-only observations are preserved in §2, changelogs and the TB1 Review record; full text remains in git history. |
| `Architecture_M6_CP1_TB1_Artifact_Only_Test_Benchmark_Plan.md` (66 lines) | **CONSUMED TB1 EXEC PLAN / FOLDED BY M6-CP1-TB1-REV.** Immutable artifact identity, six-focused-plus-selector449 process contract, no-benchmark boundary and Review successor are preserved in §3, the retained TB1 report and TB1 Review record; full text remains in git history. |
| `Architecture_M6_CP1_CB2_Corner_Authority_Range_Correction_Code_Build_Plan.md` (94 lines) | **CONSUMED CB2 PLAN / FOLDED BY M6-CP1-TB2-REV.** One-variable stable-vector correction, frozen selector/static checks, GMP compile boundary and TB2 pre-registration are preserved in §5, the retained TB2 report and current Review; full text remains in git history. |
| `Architecture_M6_CP1_CB2_Corner_Authority_Range_Correction_Code_Build_Report.md` (81 lines) | **SUPERSEDED CB2 COMPILE REPORT / FOLDED BY M6-CP1-TB2-REV.** Exact semantic source, compile run/job, candidate artifact/digests, eight-target GMP evidence and runtime-free boundary are preserved in §5 and retained current evidence records; full text remains in git history. |
| `Architecture_M6_CP1_TB1_Artifact_Only_Test_Benchmark_Report.md` (64 lines) | **SUPERSEDED TB1 RUNTIME REPORT / FOLDED BY M6-CP1-TB2-REV.** TB1 mechanics, accepted-prefix RED set and Review-corrected root are preserved in §3-§4, tracker and current Review; full text remains in git history. |
| `Architecture_M6_CP1_TB1_Review_Record.md` (191 lines) | **SUPERSEDED TB1 REVIEW / FOLDED BY M6-CP1-TB2-REV.** Cross-temporary root proof, corrected accounting, whole-tree scan, recovery rule and carried obligations are preserved in §4, tracker, frozen definitions and current Review; full text remains in git history. |
| `Architecture_M6_CP1_TB2_Artifact_Only_Test_Benchmark_Plan.md` (88 lines) | **CONSUMED TB2 EXEC PLAN / FOLDED BY M6-CP1-TB2-REV.** Candidate identity, six+449 exact-process gate, immutable boundary, recovery pre-registration and Review successor are preserved in §6-§7, retained TB2 report and current Review; full text remains in git history. |
| `Architecture_M6_DEFN_R1_Seam_Incident_Occurrence_Sheet_Authority_Plan.md` (67 lines) | **CONSUMED DEFN-R1 PLAN (review-authored) / FOLDED BY M6-DEFN-R1-REV.** Its eight decisions and split-square worked example are preserved in the DEFN-R1 definition record and in §12-§13; full text remains in git history. |
| `Architecture_M6_DEFN_R1_Review_Plan.md` (32 lines) | **CONSUMED DEFN-R1 SELF-AUTHORED REVIEW PLAN / FOLDED BY M6-DEFN-R1-REV.** Its ten checks were executed. It lacked a check that existing frozen assertions stay satisfiable, which is how B1 went unseen (lesson 180). Full text remains in git history. |
| `Architecture_M6_DEFN_R2_Amendment_Plan.md` | **CONSUMED DEFN-R2 PLAN (review-authored) / FOLDED BY M6-DEFN-R2-REV.** Its A1-A4/P1-P4 scope and frozen-test audit requirement were executed by the DEFN-R2 record and extended by RA-1 – RA-10; full text remains in git history. |
| `Architecture_M6_CP3_R9_Rung_Rescope_Review_Decision.md` (103 lines) | **SUPERSEDED REVIEW RECORD (RA-77) / FOLDED BY M6-CP3-R9-CARRIER-ENDPOINT-SUBCONDITION-REV.** Rung 19 returned no deliverable and was split into R9A/R9B; preserved in frozen definitions RA-77 and git history. |
| `Architecture_M6_CP3_R9A_Endpoint_Face_Comparison_Census_Review_Decision.md` (232 lines) | **SUPERSEDED REVIEW RECORD (RA-78) / FOLDED BY M6-CP3-R9-CARRIER-ENDPOINT-SUBCONDITION-REV.** Accepted the R9A census; second active admission path at `:8621-8736`; preserved in RA-78 and git history. The R9A census itself is retained as current input. |
| `Architecture_M6_CP3_R9B_Endpoint_Equivalence_Contract_Review_Decision.md` (206 lines) | **SUPERSEDED REVIEW RECORD (RA-79) / FOLDED BY M6-CP3-R9-CARRIER-ENDPOINT-SUBCONDITION-REV.** Accepted the V/I/C contract shape, later found incomplete (RA-81.1); preserved in RA-79 and git history. The R9B specification is retained as current input. |
| `Architecture_M6_CP3_R9_Terminal_Star_Path_Review_Decision.md` (209 lines) | **SUPERSEDED REVIEW RECORD (RA-80) / FOLDED BY M6-CP3-R9-CARRIER-ENDPOINT-SUBCONDITION-REV.** Branch V not applicable 0/21; star path passes; hoist verified semantics-preserving; preserved in RA-80 and git history. |
| `Architecture_M6_CP3_CB9_Terminal_Star_Path_Probe_Code_Build_Record_20261016.md` (28 lines) | **SUPERSEDED CB9 COMPILE RECORD / FOLDED BY M6-CP3-R9-CARRIER-ENDPOINT-SUBCONDITION-REV.** Package `12052388003` at `18cc4da5e`, superseded by CB10; identities preserved in RA-80.2/RA-80.4, `CHANGELOG.md` and git history. |
| `Architecture_M6_CP3_TB9_Terminal_Star_Path_Harvest_Report_20261016.md` (24 lines) | **SUPERSEDED TB9 RUNTIME REPORT / FOLDED BY M6-CP3-R9-CARRIER-ENDPOINT-SUBCONDITION-REV.** Result `12055460315`, 0/21 branch-V conjunction; superseded by TB10; preserved in RA-80.1 and git history. |
| `Architecture_M6_CP3_R9_Carrier_Endpoint_Subcondition_Review_Decision.md` (61 lines) | **SUPERSEDED REVIEW RECORD (RA-81) / FOLDED BY M6-CP3-DEFN-R10A-RAIL-INTERIOR-VERTEX-WITNESS-CENSUS-REV.** TB10 accepted as diagnostic evidence; carrier membership 21/21, contact membership 0/21; vertex 4 interior to open rail 1–4–7; V/I/C contract incomplete. Preserved in RA-81 and git history. |
| `Architecture_M6_CP3_R10_Prework_Verification_Review_Decision.md` (96 lines) | **SUPERSEDED REVIEW RECORD (RA-82) / FOLDED BY M6-CP3-DEFN-R10A-RAIL-INTERIOR-VERTEX-WITNESS-CENSUS-REV.** Pre-work `0660af9d1` verified on full history (433/433 changelog identifiers); history gates are Review gates; two-layer verifier rejection, confirmed by R10A (RA-83.1). Preserved in RA-82 and git history. |
| `Architecture_M6_CP3_R10A_Witness_Census_Review_Decision.md` (78 lines) | **SUPERSEDED REVIEW RECORD (RA-83) / FOLDED BY M6-CP3-DEFN-R10B-RAIL-INTERIOR-VERTEX-ENDPOINT-RULE-REV.** R10A census accepted; consumer certifies I–I fronts that publication rejects; ordered open-rail chain reaches the consumer but not the factory; R10B constraints. Preserved in RA-83 and git history. |
| `Architecture_M6_CP3_TB12_Harness_Authority_Review_Decision.md` (55 lines) | **SUPERSEDED REVIEW RECORD (RA-86) / FOLDED BY M6-CP3-TB12-R10-OPEN-RAIL-CHAIN-PROVENANCE-REV.** TB12 block was a handoff defect, not orchestration; TB12 authorized to author one harness; CB12 package verified; full-pipeline RP-01 diagnostics added; U3 constraints carried into RA-87.4. Preserved in RA-86 and git history. |
| `Architecture_M6_CP3_DEFN_RP01_Off_Selector_Review_Continuation_20261029.md` (200 lines) | **SUPERSEDED DEFN WIP LOG / FOLDED BY M6-CP3-DEFN-RP01-OFF-SELECTOR-COVERAGE-DISPOSITION (RA-172).** Chronological P01–P14 audit log; its findings are in the retained working inventory and the RA-172.4 dispositions. Last text at `a5e915afa`. |
| `Architecture_M6_CP3_TB51_Proposed_916_Case_Manifest.tsv` (917 lines) | **WITHDRAWN NON-EXECUTABLE PROPOSAL / FOLDED BY RA-172.** All 408 census rows as GUARD/PASS, so it would fail on 85 rows. Replaced by the frozen 831-row TB51 manifest plus the 85-row deferred ledger (RA-172.6). Last text at `a5e915afa`. |

## 12. `M6-DEFN-R1` — seam-incident occurrence authority frozen; CB4 re-scoped and held

Runtime-free Definition resolves the TB3 Review addendum's semantic gap. Occurrence isolation authority is the complete cell corner wedge: sorted sheet set, contiguous per-face bindings, and exact seam-edge certificate references. Directed sides carry mid-side and seam-collinear seam evidence; OrdinaryFront remains owner-less. Seam-collinear side sheet authority comes from the incident cell interior side under exact chart orientation rather than the tracer's lexicographic representative. A7 lineage unions all member wedge sheets. Row140 legacy naming is adapter-only and duplicate downstream structural owner checks are designated for removal without weakening transport/content validation.

The split-square analytic derivation confirms v0 and v2 each require `{0,1}` despite being single-occurrence quotient classes, and the center's four occurrences collectively cover both sheets. At a source seam vertex where two seam edges share a sheet pair, edge-keyed certificate identity remains unique whether the wedge crosses one or both edges.

CB4 is rewritten to implement these semantics only and stays HELD until mandatory `M6-DEFN-R1-REV`. One new focused identity is pre-registered, making TB4 **7 + 449 = 456** processes. Accepted runtime authority, selector/routing bytes, stable accounting **54 / 16 / 38**, and debt 1 are unchanged. No generated runtime or compile occurred.

## 13. `M6-DEFN-R1-REV` — core model upheld; four blocking amendments; `M6-DEFN-R2` next

The review agent independently re-verified snapshot `10846121134` (source byte-identical to `660015f2`), the split-square table, the eight endpoint memberships and the seam-vertex chain. The corner-wedge sheet set, the wedge/side certificate carriers, owner-less `OrdinaryFront`, A6 membership validation and the A7 union are **upheld**. The definition is **not accepted as frozen**:

- **B1 — decisive.** Frozen focused row5 requires non-empty `equivalences` for every multi-sheet lineage. Lineage equivalences come only from relation unions, so under D5 the relation-free singleton classes at v0 and v2 become `{0,1}` with no equivalences, and TB4 is RED by construction. Fix: represent wedge evidence in `equivalences`, and have the seventh identity assert lineage.
- **B2.** D6 leaves the binding selection undefined for the transitional class key/`QuotientClassId` ordinal, `representative_key`, the selected relation path certificates and chart components (torus rows 444/448), and lineage `sourceCharts`.
- **B3.** Wedge endpoints still use tie-broken segment faces for sides collinear with any source edge. There are three side builders; the split square uses `segment_on_source`, whose tie-break is by source-face row. The fix is one exact collinearity/interior-face rule, with the orientation premise proved per builder.
- **B4.** D7 contradicts frozen §4.6: A5's many-to-one `UnownedRelation` lets the specific M5 codes become generic. Fix: split the A5 codes 1:1 and map them at the adapter.

Precision items P1-P4 are also carried. Accounting **54 / 16 / 38**, debt 1, +0. Exact next is runtime-free `M6-DEFN-R2` (`Architecture_M6_DEFN_R2_Amendment_Plan.md`), then `M6-DEFN-R2-REV`, then the re-scoped CB4.

## 14. `M6-DEFN-R2` — four blockers resolved in runtime-free Definition; CB4 still held

`M6-DEFN-R2` retains the DEFN-R1 corner-wedge model and resolves the independent Review's B1-B4/P1-P4 amendments. Lineage receives evidence-only `CornerWedgeIsolation` transitions; semantic consumers operate on complete wedge binding tuples; seam-collinear authority uses exact source support and canonical cell-interior winding rather than builder tie-break faces; A5 relation failures are one-to-one with legacy naming confined to the adapter; and ordered-span/reciprocal/singular/hard-rail precision rules are explicit.

The frozen-test audit covers focused rows 5/6, selector rows 186/214/239/444/446/448 and HardRail single-sheet assertions. The split-square v0/center/v2 materialized lineage is now definitionally satisfiable without invented relations. CB4 is rewritten around these rules and remains HELD until mandatory `M6-DEFN-R2-REV`. TB4 remains **7+449=456** if later authorized. No source/test/fixture/selector/build bytes or runtime were changed/executed. Accounting remains **54 / 16 / 38**, debt 1, +0.

New retained authority: `Architecture_M6_DEFN_R2_Seam_Incident_Authority_Amendment_Definition_Record.md`.

## 15. `M6-DEFN-R2-REV` — R2 accepted with review amendments RA-1 – RA-10; CB4 authorized

The review agent independently re-verified snapshot `10847467936` (byte-identical to `660015f2` on the decisive files). It upheld:
- B1: `CornerWedgeIsolation` is evidence-only, and existing consumers are kind-gated with front-edge guards;
- B2: the binding rules;
- B3: the orientation premise, proved in the uniform (reference-face normal), periodic and bounded-disk (corner-face normals) builders;
- B4 and P1/P2.

Ten amendments close places where a literal CB4 implementation would fail a frozen gate:
- **RA-1:** boundary-collinear sides; all eight split-square perimeter sides are boundary-collinear.
- **RA-2/3:** P3/P4 must not key on vertex category; torus rail vertices ("excluded", 72 − 55 = 17) are lattice nodes.
- **RA-4:** row-invariant permutation checks; `hash_completion` hashes face rows and front-edge indices.
- **RA-5:** `OccurrenceUnownedRelation` keeps its name, and focused row3 keeps enum `UnownedRelation`.
- **RA-6:** lineage sheets = wedge union only.
- **RA-7:** retire `crossesSheets` and map its replacements at the adapter.
- **RA-8:** wedge-arc endpoints and direction.
- **RA-9:** resolver-defined span support.
- **RA-10:** CB4 keeps the transitional `quotientClass`.

Accounting 54/16/38, debt 1, +0. Exact next `M6-CP1-CB4` (amended plan) → TB4 456 → Review.

## 16. `M6-CP1-CB4` blocker and RA-11 resolution

CB4 stopped before any production or test change. A static proof on snapshot `10850013454` (source equivalent to `660015f2`) showed that D6/R2's per-face `CornerWedgeFaceBinding.branchRotation` cannot be supplied for corner-fan faces that no side traverses:
- A4 publishes one selected-face `LocalLatticeState` per corner;
- the edge transition map carries indices, not quarter-turns;
- branch meaning differs by builder, and the periodic builder leaves it `0`.

The review agent upheld these facts but resolved the block by narrowing D6 (**RA-11**). The only A5-A7 reader of an occurrence branch is the transitional class key; transport checks use A4 edge and endpoint states, and no test asserts an occurrence branch.
- Wedge bindings are `(face, sheet, chart)`.
- The A4 corner lattice state is published verbatim as face-labelled `CornerPlacementProvenance`, which feeds the class key only.
- The representative key has no branch.
- Rejected: an A4 per-face branch table (no consumer, and no uniform meaning across builders), derivation (impossible), and a repeated corner branch (face mixing).

CB4 resumes the same turn; TB4 stays 456. Accounting 54/16/38, debt 1, +0.

## 17. `M6-CP1-CB4` — complete seam-incident authority implemented; candidate compiled

CB4 resumes after RA-11 and completes the accepted R2 + RA-1 – RA-11 scope at exact semantic source `20f60bb1412424a6f1093fc8076884d1ea23f1c5`. A5 now publishes complete `(face,sheet,chart)` corner-wedge bindings, RA-11 labelled corner placement provenance, exact ordered isolation transition evidence and one-to-one typed failures. A6 carries `CornerWedgeIsolation` as evidence-only lineage, uses complete binding signatures for the transitional class key, derives selected relation path charts/components from the selected relation sides, and validates reciprocal ordinary/seam-collinear side authority without representative-sheet fallback. Component aggregation remaps exact binding/isolation tuples before legacy projections. A7 lineage takes charts/sheets from the complete member bindings. The strengthened split-square identity compiles.

The frozen static audit leaves focused rows1-4 unchanged; preserves row140 externally as `InvalidHardRailTransport` via the adapter; preserves row5 multi-isolation wedge-union evidence, row6 semantic periodic direction, rows186/214/239 isolation/remap/reciprocal semantics and rows444/446/448 selected Periodic relation semantics. Selector449 is byte-identical `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414` (449 LF rows) and routing449 is `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707`.

Patch application run/job `36150018237 / 108120755401` commits the exact six-file semantic patch. Mandatory compile run/job `36150253128 / 108121497728` packages all eight standard targets as artifact `10871935178` (`sha256:dc6e979ac62b4599c2c8b15528524513f3bc5b45eb9068ed508fd3d08ccf7998`) with log artifact `10871960013` (`sha256:bbdfe584c0aefa433f614f699c28686ab83c9bc8194b3f868c1db96589c2eabf`), 28/28 root manifest, clean source receipts, GMP/GMPXX link evidence and `runtimeExecution=false`.

CB4 grants no runtime credit, promotion, debt discharge or CP1 closure. Stable accounting remains **54 / 16 / 38**, debt 1. Accepted runtime authority remains M5 package `10814505512` / selector449 449/449. Exact next is immutable artifact-only `M6-CP1-TB4-EXEC` over **7 focused + 449 = 456** fresh exact-filter processes, then mandatory `M6-CP1-TB4-REV`.
## 18. `M6-CP1-TB4-EXEC` — complete 456-process gate is mechanically valid and semantic RED

TB4 consumes CB4 artifact/source `10871935178 / 20f60bb1412424a6f1093fc8076884d1ea23f1c5` immutably. Run/job `36157505252 / 108145613689` executes exactly seven focused identities followed by selector449, one fresh exact-filter process per identity, with zero skips/selection mismatches, no watchdog, benchmark 0 and no configure/compile/relink/discovery/repair/mutation. Result/log authority is `10874311495 / 10873574681`; result evidence is **932/932**, and package/source/execution-view censuses are byte-and-mode identical pre/post.

Runtime outcome is focused **6/7 PASS** plus selector449 **425/449 PASS**, aggregate **431/456 PASS / 25 RED**. Relative to TB3, focused multi-isolation row5 and selector 186/214/239 recover; the strengthened seventh seam-endpoint/wedge-lineage identity PASSes. Focused pair-swap row6 and selector 444/446/448 remain RED. Twenty-one accepted selector identities newly turn RED: 115, 116, 122, 130, 132, 134, 137, 141, 143, 150, 176, 201, 217, 218, 231, 232, 238, 246, 436, 437, 438.

EXEC records `M6-CP1-TB4-EXEC-CAND-01` as a non-stable Review-owned envelope and does not group, classify, reprice or authorize correction. Stable accounting remains **54 / 16 / 38**, debt 1. Candidate remains unpromoted and accepted M5 package/source `10814505512 / e284fea7...` under selector449 449/449 remains runtime authority. Exact next is mandatory runtime-free `M6-CP1-TB4-REV`.


## 19. `M6-CP1-TB4-REV` — source-edge support / isolation-seam domain conflation proved; CB5 frozen

Independent Review upholds TB4 mechanics at **431/456 PASS** and reopens accepted M5 selector449 **449/449** as the differential control. Twenty-one selector identities are newly accepted-green losses; carried pair-swap + 444/446/448 remain RED. The new direct family is not an A5 evidence omission: A5 deliberately publishes generic source-edge-collinear same-sheet spans without a seam certificate. A6 then treats every `collinearEdge` as an isolation seam and requires a certificate. R2 P2 explicitly distinguishes non-seam from seam-collinear spans.

`M6-CP1-TB4-EXEC-CAND-01` is therefore one new stable event / existing `RP-01 AUTHORITY_DOMAIN_CONFLATION` recurrence. Stable accounting is **55 / 16 / 39**, debt 1. TB3 formal recovery remains open despite row5 + 186/214/239 recovering; TB1 formal 449/449 recovery remains open; TB2 validation-order recovery remains closed. Candidate `10871935178` remains unpromoted and accepted M5 package/source `10814505512 / e284fea7...` remains runtime authority.

Exact next is bounded runtime-free `M6-CP1-CB5`: only correct A6 OrdinaryFront P2 so generic source-edge-collinear/no-certificate spans use the non-seam same-sheet/wedge-membership rule, while certificate-backed spans retain the exact seam face/sheet/reciprocal-evidence rule. Compile-green advances to unchanged **7 + 449 = 456** `M6-CP1-TB5-EXEC`, then mandatory Review.

## `M6-CP1-TB4-REV` review-agent addendum

The review agent upheld TB4-REV's root cause (A6 `:4908-4914` treats generic source-edge collinearity as seam authority), the one-`RP-01` classification and 55/16/39.

It proved the attribution of the 21 new losses by single-sheet exclusivity. There are four `MissingIsolationSeamEquivalenceAuthority` emission sites: A5 adapter, A6 side evidence, A6 collinear span and A6 seam-span transition. On a single-sheet fixture only the collinear branch can fire, and all 21 losses use single-sheet fixtures.

Corrections and additions:
- The carried torus REDs (multi-sheet) are not proved to be the same site; their recovery is a TB5 prediction with a falsifier.
- RA-12 (required in CB5) turns legacy names into prefixes with site suffixes.
- Verified that A5's collinear seam-span transitions agree with CB5's seam branch.
- Debts: dead legacy single-valued `SurfaceOccurrence` fields (CP1-acceptance precondition); unsorted aggregated `equivalences`.

### Second review-agent pass

The first addendum overclaimed in two places, now corrected:
- Single-sheet exclusivity proves the site only for the 13 rows that print the string. The 8 downstream rows are bound by fixture sharing and stage-product export timing, not proved; the downstream falsifier stays in force.
- The legacy-field debt is narrowed to `isolationSheet`, `chart` and `lattice`. `point` is live, and `chartComponent` is legitimate.

Verified with no defect: the R2 §4.4 selected-path charts are re-anchored by completion validation, and validator chart authority is satisfied by the wedge-chart union.

## 20. `M6-CP1-CB5` — ordinary-front seam classification corrected; candidate compiled

CB5 implements the bounded correction frozen by TB4 Review. In A6 reciprocal `OrdinaryFront` near-endpoint validation, source-edge-collinear spans no longer imply isolation-seam authority. If `isolationCertificateBySeam[(region,edge)]` is absent, the pair is classified as a generic non-seam and must satisfy exactly the existing non-seam P2 predicate: equal `interiorBinding.sheet`, with that sheet present in both endpoint `cornerWedgeSheets`. If a checked isolation certificate exists, the prior exact seam face/sheet and reciprocal `CornerWedgeIsolationTransition` validation remains authoritative. No A5 product/schema/support rule, test, fixture, selector, HardRail, Periodic, or frozen-definition byte changed.

RA-12 diagnostic attribution is compiled into the legacy isolation-failure vocabulary. A5 distinguishes `:a5-wedge` and `:a5-side`; A6 distinguishes `:a6-side-evidence`, `:a6-seam-span-transition`, and `:a6-seam-faces`. The former uncertified-collinear seam failure site is eliminated by the semantic correction; failure of the generic non-seam predicate remains `QuotientReciprocalSideAuthorityMismatch`.

Static verification on the exact source snapshot changed only `src/pipeline/RemeshPipeline.cpp`, passed `git diff --check`, and re-hashed selector449/routing449 unchanged at `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414` / `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707`. Patch application run/job `36168631350 / 108182514195` applied exact patch SHA-256 `c4789d192ab48dd5137fd2de7121d85538635f5156e3f23a058423a949a79324` as semantic commit `2ec8c7358858f0b74ce6fc2a30c55d366b53ba71`.

Mandatory compile run/job `36168827294 / 108183151046` compiled and linked all eight standard targets from exact source `82b86a285292379cfd92cdc4e10d74181b38f1e8`. Result artifact `10879581622` hashes `578845a2135ef2296e982e8bac9a378b7659d2968aa9ab5b2702f841288d57c6`; log artifact `10879491574` hashes `a67873ca9bb8ef0e447ed16badff37bcd602a4aad363ed31f9c42ca9c7af516c`. The root self-excluding package manifest verifies **28/28**; preflight/build exits are `0/0`; all source-status receipts are empty; GMP/GMPXX are present on the authoritative generated link command; `exactArithmeticBackend=GMP`; `runtimeExecution=false`. No generated Directional binary executed.

CB5 therefore grants compile/package evidence only. Candidate `10879581622` is unpromoted; accepted runtime authority remains M5 package/source `10814505512 / e284fea7...` under selector449 449/449. Stable accounting stays **55 / 16 / 39**, debt 1. Exact next is immutable `M6-CP1-TB5-EXEC`: seven focused identities + selector449 = **456** fresh exact-filter processes, followed by mandatory `M6-CP1-TB5-REV`. Recovery of the multi-sheet torus rows remains a falsifiable TB5 prediction.

## 21. `M6-CP1-TB5-EXEC` — complete 456-process gate returns mechanically green

TB5 consumes CB5 artifact/source `10879581622 / 82b86a285292379cfd92cdc4e10d74181b38f1e8` immutably. Run/job `36172157965 / 108194136911` executes exactly seven focused identities followed by selector449 as **456 fresh exact-filter processes**. Every process selects exactly one test; zero skips, crashes or selection mismatches occur; benchmark 0; no configure/compile/relink/discovery/repair/mutation or watchdog occurs.

Runtime outcome is **7/7 focused + 449/449 selector = 456/456 PASS**. All 21 TB4 newly lost accepted selector identities recover. The carried multi-sheet torus falsifier also recovers: focused pair-swap row6 and selector 444/446/448 PASS. Focused multi-isolation row5, the seam-endpoint/wedge-lineage row7 and row140 remain PASS. No raw gate log contains `OccurrenceInvalidCornerAuthority`, `MissingIsolationSeamEquivalenceAuthority`, `InvalidIsolationSeamEquivalenceAuthority`, or `QuotientReciprocalSideAuthorityMismatch`.

Result/log artifacts are `10880392759 / 10880502706` with SHA-256 `71095935dedf52277df946e05cf181713ecb0ebe0842aa91f35ab9b65dd91216 / 0a41be59d2c31138623e770eb6fb30202fa6e511aad691343f40cfee5e3e29df`. Result self-manifest verifies **933/933** and execution-ledger SHA-256 is `06c1d0166ac0165d4a931c10d2aa4f95b433b05f7a40217f7c8003de3d460a11`. Package/source/execution-view censuses and pre/post hashes are identical; selector/routing/source archive are unchanged; package manifest remains 28/28.

TB5 EXEC records no new regression candidate and performs no stable repricing. Stable accounting remains **55 / 16 / 39**, debt 1. Candidate remains unpromoted and accepted M5 package/source `10814505512 / e284fea7...` under selector449 449/449 remains runtime authority. Mandatory runtime-free `M6-CP1-TB5-REV` owns formal recovery of prior events, candidate promotion, CP1 acceptance, and any accounting/debt disposition. The legacy `SurfaceOccurrence.isolationSheet/chart/lattice` acceptance precondition remains open.

## 22. `M6-CP1-TB5-REV` — recovery accepted; runtime promoted; CP1 held only by static A5 product cleanup

Independent Review re-opens candidate `10879581622 / 82b86a285292379cfd92cdc4e10d74181b38f1e8`, TB5 run/job `36172157965 / 108194136911`, result/log `10880392759 / 10880502706`, and exact current source. Package 28/28, result 933/933, source archive/selector/routing hashes, GMP boundary and immutable postflight all independently verify. The complete gate is upheld at **456/456 PASS**.

TB1 `CROSS_TEMPORARY_ITERATOR_RANGE`, TB3 RP-01 and TB4 RP-01 are formally **RECOVERY PROVED**; TB2 validation-order remains recovery-proved. Historical counts remain **55/16/39** and project debt remains 1. CB5/TB5 is promoted as current reviewed runtime authority under unchanged selector449.

CP1 remains open because public `SurfaceOccurrence` still contains unread `chart`, `lattice`, `isolationSheet` representative fields excluded by frozen §3.2/RA-11. Exact C++ reader search finds none; `point` is live and `chartComponent` remains legitimate. The TB4-REV aggregated-`equivalences` sorting debt is withdrawn because exact candidate source already sorts/de-duplicates after tuple remap.

Exact successor `M6-CP1-CB6` retires only those three dead fields, compile/packages without runtime, then hands an immutable candidate to unchanged TB6 7+449=456 and mandatory Review. Full authority: `Architecture_M6_CP1_TB5_Review_Record.md`; plan: `Architecture_M6_CP1_CB6_Legacy_Occurrence_Field_Retirement_Code_Build_Plan.md`.

## `M6-CP1-TB5-REV` review-agent addendum — CP1 scope corrected

Upheld: TB5 456/456 (independently re-derived), the TB1/TB3/TB4 recovery, the promotion, 55/16/39 with debt 1, and the B6.2 withdrawal (the review agent's own earlier finding was wrong).

Corrected: TB5-REV said CP1 was held only by three legacy A5 fields. Frozen §10/§8.1 require A6 and A7 products behind stage APIs, a thin adapter and the `G4-B002` A6 boundary. The source shows none of this:
- 0 A6/A7 product types;
- a 1,768-line materializer;
- §4.4 exact-once consumption unimplemented (`:5179` skips cycle-closing relations, with no holonomy check);
- §4.3 member-set identity deferred;
- candidate extraction still on `SurfaceCellComplex`.

CB6 is HELD and folded into the A6 CB. The CP1 exit scope is restated in the frozen definitions. Exact next is `M6-DEFN-R3` (`Architecture_M6_DEFN_R3_CP1_Product_Separation_Plan.md`). Lesson 183.

## `M6-CP1-TB6-A6-REV` review-agent addendum — Finding B corrected (RA-13)

TB6 runtime evidence re-verified (946/946; RED focused 6 and selectors 139/142/446). Finding A upheld; it is a fail-open guard loss at the A5 cutover rather than shadowing.

Finding B was mis-diagnosed as legitimate noncontractible residual holonomy:
- vertex-class cycles are contractible links;
- A6 composed OrdinaryFront identity (cut-domain placement gauge) with exact-A3 Periodic `g` (relation-endpoint gauge, Reverse side rotated by Q);
- the conflicts occur only on the nonzero-Z4 witness, while the Q=0 torus rows are green.

The residual fallback is revoked. RA-13 (single-gauge transport, strict rule restored, diagnostic residual suffix) is frozen, and the CB7-A6 plan is amended. Category RP-07 → RP-01; totals 57/16/41 unchanged. Lesson 184.



## 45. `M6-CP1-CB12-CLOSE-R1` — close-out implementation compile-valid

RA-26 discharged C5 before R1. R1 therefore implemented only C1–C4: exact A7 sheet-connecting isolation certification; distinct A5 source diagnostics; A5-owned `validatedIsolationCertificateCount` projected through the thin adapter; and RA-25 fail-closed strip-continuation ambiguity. Identities 29/30 extend focused-28 to focused-30 (`1e815443a03c7ef4a1b095e6ea973efa9c74bb0eae4e2f872510c97d057ea1d6`). Optimizer and final-validator code were unchanged.

The first compile-only run `37259162318` found one pointer member-access typo; a one-line bounded correction produced exact source `02149f1518fc6a753acf3235f7dcdc6fcdf59f24`. Retry run/job `37259524323 / 111603703243` compiled and linked all eight standard GMP/GMPXX targets. Result/log artifacts `11324028392 / 11323679468`; outer digests `4e6b208a...afba1 / 82adb1a6...c7766`; packaged manifest 28/28, clean source, `runtimeExecution=false`. No runtime acceptance is claimed.

Exact next is immutable `M6-CP1-TB12-CLOSE-EXEC`: focused30 + selector449 = **479**, then mandatory Review and CP1 close Review. Stable accounting remains **60 / 16 / 44**, debt 1.


## 46. `M6-CP1-TB12-CLOSE-REV` — identity29 false rejection; RA-27 recovery

Independent Review re-derives TB12 at 478/479 and confirms ordinal29 fails at witness non-vacuity before any transition tamper. CB12 C1 is specifically about selected-forest edges with disjoint endpoint wedge-sheet sets. A6 constructs a deterministic spanning forest and does not owe a cross-sheet selected edge for every split-isolation fixture. The split-square assumption in identity29 is therefore invalid; no production-selection defect is established.

CAND-01 is **FALSE REJECTION / TEST-FIXTURE WITNESS DEFECT / RECOVERY REQUIRED / NON-STABLE**. Production C1 is statically consistent with the exact endpoint-sheet transition rule, but the negative falsifier remains runtime-unproved, so candidate `11324028392 / 02149f15...` is not promoted. RA-27 freezes test-only recovery in `M6-CP1-CB12-CLOSE-R2`, then a fresh 479-process `M6-CP1-TB12-CLOSE-R1-EXEC` and mandatory R1 Review. Stable accounting remains 60/16/44, debt 1.


## 50. `M6-CP1-CLOSE-REV` — CP1 CLOSED / ACCEPTED, mechanism-only

The final runtime-free closure Review re-opened current semantic source and found no drift from promoted `3f40f04a`. It checked the frozen six-item CP1 exit list verbatim, with focused-30 evidence mapped as: item 1 → 1,2,3,7,21,22,23,30; item 2 → 8–12; item 3 → 13–20,29; item 4 → 24; item 5 → 25–28; item 6 → 4,15,5. All pass.

RA-26 was re-audited at current HEAD: A7 representative-face uses are common-support reconstruction/reference, the adapter is projection-only, class-wide chart authority drives semantic sheet/chart validation, and optimizer/final-validation anchor dependence remains reference-selecting only. No authority-deciding provenance-face consumer exists. RA-26 §5(iii) moves to CP2; §5(i)(ii)(iv) remain DEFN-R5/CP3.

RA-27b branch routing is explicit: C2 empty-front accepted defensive; C4 → CP2 Definition; region/touches/three-sheet wedge tampers → first CP2 CB; seam-collinear edge falsifier → DEFN-R5/CP3; adapter cross-sheet site-loss → M8-CP2. `G4-B002` stays open, so debt remains 1. Stable accounting is unchanged at **60 / 16 / 44**. Exact successor: **`M6-CP2-DEFN`**.


## M6-DEFN-R5-R2-REV — RA-34 accepted Definition-only (2026-10-08)

Independent source-only Review accepts RA-34.1 bound oriented seam certificate / no raw-global label grant or denial and RA-34.3 exact A3-oriented cross-rail τ with odd-produced discriminator and F/τ inequality. A4 typed wedge/certificate sheet proof is a hard preflight, D2/D3/D4/D5 organic positives still unproven. R1 OBS-01/02 discharged at Definition only, RP-01 open; stable 63/17/46, debt 1. Rejected R1 482/497, accepted CP2 491/491; selector449 unchanged. Exact successor M6-CP3-CB1-ENTRY-R2 compile-only, then immutable 497 TB and mandatory Review. CB2 held. Full record `Architecture_M6_DEFN_R5_R2_Review_Record.md`.

## M6-DEFN-R5-R4-REV independent review disposition (2026-10-10)

RA-41 was **not frozen**. Static 3×3 source-star re-derivation proves one nonrail candidate face `2 -> 3` at terminal rail vertex 1 and two opposite source germs, but does not prove producer-owned contact/gauge; source-matched A3 is still unconditionally required by frozen RA-40.1. R4-REV-01/02 are architecture STOPs; held Code + Build remains HELD. Exact review record: `Architecture_M6_DEFN_R5_R4_Independent_Review_Record.md`. DIAG's exact 39-row inventory and the active candidate record/plan are retained, **not** folded due current unresolved authority. No additional runtime evidence; CP2 491/491, rejected R3 403/497, ledger 66/17/49 and debt 1 unchanged.

## TB29 historical plan consolidation — RA-141 (2026-10-23)

**Folded document index (exact original basename and verdict):**

- `Architecture_M6_CP3_TB29_Typed_Factory_Cause_Harvest_Plan_20261022.md` — consumed 44-case artifact-only Test + Benchmark plan; superseded by independently verified TB29 report (`Architecture_M6_CP3_TB29_Typed_Factory_Cause_Harvest_Report_20261023.md`) and RA-141 Review (`Architecture_M6_CP3_TB29_Typed_Factory_Cause_Harvest_Review_Decision_20261023.md`). Full plan verbatim below; original also recoverable from Git history prior to this fold. Existing historical references in earlier decisions and TODO/CHANGELOG are provenance and resolve through this index. No current selector, runtime or successor authority derives from this consumed plan.

### Folded TB29 plan — verbatim historical text

# TB29 — targeted artifact-only typed-cause harvest (2026-10-22)

**Canonical successor:** `M6-CP3-TB29-RP01-TYPED-FACTORY-CAUSE-HARVEST`. **Boundary:** Test + Benchmark only; separate independent TB29-REV afterward. Authority: RA-136.4 and CB28A independent review; exact compiled semantic source `4473e41e94a35f1bf189fa046e86bac92c7391fb`, immutable compile artifact **12465330920** from [run 39867988763](https://github.com/akashskypatel/Directional/actions/runs/39867988763), SHA-256 `da56650a18f99443abf5f721620bb00fd5701dd1e660741da9aafb924a6dfbf5`, 28/28 package entries. Do not rebuild, reconfigure, relink, regenerate, repair, or change the package.

## Exact targeted identity contract — 44 executions

1. **Four new A7 negatives, source-defined test identities:** `M6CP3.CertifiedSeamRejectsConnectingEvidenceOnUnrelatedSeam`; `M6CP3.CertifiedSeamRejectsMissingCertificate`; `M6CP3.CertifiedSeamSharedNodeRequiresSameLatticeCoordinate`; `M6CP3.CertifiedSeamRejectsSpanBindingWithdrawnFromEndpointWedge`. Require each to pass by reaching its specified A7 site; a PASS from an earlier unrelated failure is not accepted.
2. **Two source-produced positive controls:** frozen `cp3entry:3` (D3) and `cp3entry:5` (D7), with their original identity and exact owning executable.
3. **Three existing A7 site-guard controls:** `M6CP2.A7WedgeTransitionWrongRegionRejects`, `M6CP2.A7WedgeTransitionTouchWithoutConnectivityRejects`, `M6CP2.A7ThreeSheetPartialConnectivityRejects`; before dispatch, establish against the immutable prior guard list that these are the intended three; stop for Review rather than substitute different identities if that cannot be proved.
4. **All 35 inherited TB28 RED rows, without omissions, duplicates or substitutions:** take their exact `phase`, `ordinal`, `identity` and `owner` from `.agents/Directional/Architecture_M6_CP3_TB28_Selector_497_Red_Inventory.tsv` (35 data rows; source SHA-256 `66c0ba377c834a969d481cf1ee2253688fa12b7686a0ced6d9da9695e01eb3da`). This includes `focused30:12,22,23`, the full factory, A3, A5, producer/oracle and D2 groups. Use the exact frozen mapping rather than regenerating case ordinals.

The harness must enumerate exactly **44 distinct test identities**, resolve each to an already packaged binary, and reject any name collision, nonexistent test, skipped case or execution beyond this whitelist. Construct one bounded artifact-only harness under `.agents/Directional/tools/`, checked and hashed in its separate Code + Build authorization **only if** the current TB boundary permits harness preparation; otherwise stop and request the prescribed predecessor authorization. Use the durable `test_benchmark` dispatcher with an exact harness SHA-256 and immutable package. No locally executed Directional binaries.

## Outputs and independent checks

- For all 44: original phase/ordinal, exact test name, binary, single `[ RUN ]`, verdict, exit code, raw log SHA-256, first failure and authentic error/site; no synthetic PASS, suppression, retry after start, or assertion changes.
- Four A7 negatives: compare the reached first failure/site to each preserved oracle expectation, inspect D3/D7 positive preconditions, and report false guards separately.
- Each of the **35 REDs**: extract the typed factory `code`, `sourceAuthoritySite`, relevant carriers, typed A3 atlas code/locus, or typed A5 code/site, or explicitly `reason-not-observed`. Categorize by **first observed failing condition**, not test topic; prove category counts sum to 35 and that all identities are disjoint.
- Preserve prior 462/497 TB28 as **candidate** until a separate census Review authorizes promotion; TB29's targeted run is not an accepted 497/497 replay. Stable 66/17/49, debt 1, CP2 491/491; RP-01 open, RP-02 unreached, Gate C suspended.
- Verify immutable ZIP and internal manifests before and after; certify `compile_execution=false`, `relink_execution=false`, `configure_execution=false`, `benchmark_execution=false`, `package_repair=false`, `source_test_fixture_selector_mutation=false`, `retry_after_runtime_start=false`.

**Falsifiers and stop rules:** any missing/duplicate identity, mismatched binary, unverified source/package/harness SHA, unexpected A7 site, control failure, absent diagnostic reason where the expected new assertion was reached, altered test logic, or a required compiler/rebuild action. Retain raw evidence and return to the independent TB29-REV; do not silently change predicates, names, fixtures, package, selector or production code.

**Next:** `M6-CP3-TB29-RP01-TYPED-FACTORY-CAUSE-HARVEST-REV` only after an immutable complete TB29 report exists; that Review decides DEFN-M1 and D2/fixture-debt disposition from observed clauses, not prior assumptions.

## M6 folded document index (2026-11-09) — DURABLE, DO NOT DELETE

**Authority.** The user instructed this consolidation on 2026-11-09 ("review what needs to be retained, move it to consolidated record and prune stale, superseded files"). It follows `CLEAN_UP_POLICY.md` § Document consolidation.

**Recovering a folded file.** Each file below existed at commit `f452a90dc446eb4bf4720ce43327b61d54fbf7c4`. Recover its full text with:

    git show f452a90dc446eb4bf4720ce43327b61d54fbf7c4:.agents/Directional/<name>

`git log --diff-filter=D -- .agents/Directional/<name>` also finds it. Links elsewhere to a folded file now point here, and the link title names the file.

**What was kept** (306 `Architecture_M*` files). A file stayed if any of these applies:
- policy protects it: selector, focused-selector and selector-routing files (`RETENTION_POLICY.md` § Selector files), and `Architecture_M6_Frozen_Definitions.md`;
- a tracked tool, workflow or source file reads it;
- it is current authority or the next-turn plan: RA-218, CB110 diff, TB93 and TB92 manifests, TB92 report, CB109 record, deferred ledger v5, TB63 census manifest;
- a live or normative location cites it: `DESIGN.md`, the frozen definitions, the deferred ledger, the selector manifest, ORIENTATION §3/§4/§7, the handoff's current-authority section and open sequence rows, the handoff "Read first" list (Review records only), or an open TODO item;
- it is a working record whose facts could not be verified elsewhere (34 files). These are kept pending a Review.

**What was folded** (670 files): superseded per-turn Code + Build and Test + Benchmark records and plans, applied or superseded exact patches, superseded case manifests and ledgers, working records, and Review, definition and audit records that are not cited live. For each file, the turn or verdict was found recorded in the retained home named in the last column before it was removed.

| Folded filename | Lines | Role | Verdict / title | Retained home |
|---|---:|---|---|---|
| `Architecture_M6_CB58_Diag_Retain_A5_A7_Snapshots_Code_Build_Record_20261031.md` | 15 | Code + Build record/plan | CB58 — DIAG-RETAIN A5–A7 snapshots (2026-10-31) | CHANGELOG |
| `Architecture_M6_CB59_Diag_Retain_Materialization_Display_Code_Build_Record_20261031.md` | 15 | Code + Build record/plan | CB59 — DIAG-RETAIN materialization display adapter (2026-10-31) | CHANGELOG |
| `Architecture_M6_CB60_Diag_Retain_CLI_Sidecar_Code_Build_Record_20261031.md` | 15 | Code + Build record/plan | CB60 — DIAG-RETAIN CLI materialization sidecar (2026-10-31) | CHANGELOG |
| `Architecture_M6_CB61_Diag_Retain_GUI_Layers_Code_Build_Record_20261031.md` | 16 | Code + Build record/plan | CB61 — DIAG-RETAIN GUI layers (2026-10-31) | CHANGELOG; retained Review records |
| `Architecture_M6_CB62_Diag_Retain_Linux_Package_Code_Build_Record_20261031.md` | 9 | Code + Build record/plan | CB62 — DIAG-RETAIN Linux eight-target package (2026-10-31) | CHANGELOG; TODO |
| `Architecture_M6_CB63_Linux_CLI_GUI_Code_Build_Report_20261031.md` | 24 | Code + Build record/plan | CB63 — Linux CLI and GUI ten-target compile evidence (2026-10-31) | CHANGELOG; TODO |
| `Architecture_M6_CB63_Linux_CLI_GUI_Compile_Plan_20261031.md` | 20 | Code + Build record/plan | Linux CLI/GUI compilation evidence — bounded Code + Build plan (2026-10-31) | TODO |
| `Architecture_M6_CB64_Chart_Binding_Code_Build_Continuation_20261031.md` | 25 | working record | Chart-binding cache Code + Build continuation (2026-10-31) | CHANGELOG; TODO |
| `Architecture_M6_CP1_CB10_A5V_R1_Code_Build_Plan.md` | 69 | Code + Build record/plan | M6-CP1-CB10-A5V-R1 — RA-19 ordering / pure-projection recovery Code + Build plan | retained Review records |
| `Architecture_M6_CP1_CB10_A5V_R1_Code_Build_Report.md` | 60 | Code + Build record/plan | M6-CP1-CB10-A5V-R1 Code + Build Report | CHANGELOG; M6_Consolidated_Record; retained Review records |
| `Architecture_M6_CP1_CB10_A5_Validation_Code_Build_Plan.md` | 74 | Code + Build record/plan | M6-CP1-CB10-A5V — A5 validation migration / thin-adapter Code + Build plan | retained Review records |
| `Architecture_M6_CP1_CB10_A5_Validation_Code_Build_Report.md` | 78 | Code + Build record/plan | M6-CP1-CB10-A5V Code + Build Report | CHANGELOG; M6_Consolidated_Record; retained Review records |
| `Architecture_M6_CP1_CB11_G4_B002_Boundary_Code_Build_Plan.md` | 68 | Code + Build record/plan | M6-CP1-CB11-G4 — A6 closed-complex boundary / `G4-B002` mechanism Code + Build plan | retained Review records |
| `Architecture_M6_CP1_CB11_G4_B002_Boundary_Code_Build_Report.md` | 73 | Code + Build record/plan | M6-CP1-CB11-G4 — A6 closed-complex boundary Code + Build report | CHANGELOG; M6_Consolidated_Record; retained Review records |
| `Architecture_M6_CP1_CB11_G4_R1_Code_Build_Report.md` | 63 | Code + Build record/plan | `M6-CP1-CB11-G4-R1` — Recovery Code + Build Report | CHANGELOG; M6_Consolidated_Record; retained Review records |
| `Architecture_M6_CP1_CB11_G4_R1_Recovery_Code_Build_Plan.md` | 94 | Code + Build record/plan | `M6-CP1-CB11-G4-R1` — Oracle Recovery Code + Build Plan | CHANGELOG; M6_Consolidated_Record; retained Review records |
| `Architecture_M6_CP1_CB11_G4_R1_WIP_Handoff.md` | 53 | working record | M6-CP1-CB11-G4-R1 WIP handoff | CHANGELOG; M6_Consolidated_Record; retained Review records |
| `Architecture_M6_CP1_CB12_Close_Out_Code_Build_Report.md` | 73 | Code + Build record/plan | `M6-CP1-CB12-CLOSE-R1` — CP1 Close-Out Code + Build Report | retained Review records |
| `Architecture_M6_CP1_CB8_A6_Code_Build_Report.md` | 105 | Code + Build record/plan | M6-CP1-CB8-A6 Code + Build Report | M6_Consolidated_Record |
| `Architecture_M6_CP1_CB8_A6_HardRail_Placement_Transport_Recovery_Code_Build_Plan.md` | 232 | Code + Build record/plan | M6-CP1-CB8-A6 HardRail Placement-Transport Recovery — Code + Build Plan | retained Review records |
| `Architecture_M6_CP1_CB9_A7_Code_Build_Plan.md` | 69 | Code + Build record/plan | M6-CP1-CB9-A7 — A7 extraction and thin-adapter Code + Build plan | CHANGELOG; M6_Consolidated_Record; retained Review records |
| `Architecture_M6_CP1_CB9_A7_Code_Build_Report.md` | 88 | Code + Build record/plan | M6-CP1-CB9-A7 Code + Build Report | CHANGELOG; M6_Consolidated_Record; retained Review records |
| `Architecture_M6_CP1_CB9_A7_R1_Code_Build_Report.md` | 74 | Code + Build record/plan | M6-CP1-CB9-A7-R1 Code + Build Report | M6_Consolidated_Record |
| `Architecture_M6_CP1_CB9_A7_R1_Completion_Ownership_Code_Build_Plan.md` | 97 | Code + Build record/plan | `M6-CP1-CB9-A7-R1` — Completion Ownership Authority Recovery Code + Build Plan | retained Review records |
| `Architecture_M6_CP1_Close_Review_Plan.md` | 42 | consumed plan | `M6-CP1-CLOSE-REV` — CP1 Closure Review Plan | M6_Consolidated_Record; retained Review records |
| `Architecture_M6_CP1_Close_Review_Record.md` | 110 | Review/definition/audit record | `M6-CP1-CLOSE-REV` — CP1 Closure Review Record | CHANGELOG |
| `Architecture_M6_CP1_TB10_A5V_Artifact_Only_Test_Benchmark_Report.md` | 57 | Test + Benchmark record/plan | `M6-CP1-TB10-A5V-EXEC` — Artifact-Only Test + Benchmark Report | CHANGELOG; M6_Consolidated_Record; retained Review records |
| `Architecture_M6_CP1_TB10_A5V_R1_Artifact_Only_Test_Benchmark_Plan.md` | 39 | Test + Benchmark record/plan | M6-CP1-TB10-A5V-R1-EXEC — Artifact-Only Test + Benchmark Plan | CHANGELOG; M6_Consolidated_Record; retained Review records |
| `Architecture_M6_CP1_TB10_A5V_R1_Artifact_Only_Test_Benchmark_Report.md` | 36 | Test + Benchmark record/plan | `M6-CP1-TB10-A5V-R1-EXEC` — Artifact-Only Test + Benchmark Report | CHANGELOG; M6_Consolidated_Record; retained Review records |
| `Architecture_M6_CP1_TB11_G4_Artifact_Only_Test_Benchmark_Plan.md` | 79 | Test + Benchmark record/plan | M6-CP1-TB11-G4-EXEC — Artifact-Only Test + Benchmark Plan | CHANGELOG; M6_Consolidated_Record; retained Review records |
| `Architecture_M6_CP1_TB11_G4_Artifact_Only_Test_Benchmark_Report.md` | 49 | Test + Benchmark record/plan | `M6-CP1-TB11-G4-EXEC` — Artifact-Only Test + Benchmark Report | CHANGELOG; M6_Consolidated_Record; retained Review records |
| `Architecture_M6_CP1_TB11_G4_R1_Artifact_Only_Test_Benchmark_Report.md` | 47 | Test + Benchmark record/plan | `M6-CP1-TB11-G4-R1-EXEC` — Artifact-Only Test + Benchmark Report | CHANGELOG; M6_Consolidated_Record; retained Review records |
| `Architecture_M6_CP1_TB12_Close_R1_Artifact_Only_Test_Benchmark_Report.md` | 47 | Test + Benchmark record/plan | `M6-CP1-TB12-CLOSE-R1-EXEC` — Artifact-Only Test + Benchmark Report | CHANGELOG; TODO; M6_Consolidated_Record; retained Review records |
| `Architecture_M6_CP1_TB7_A6_Artifact_Only_Test_Benchmark_Report.md` | 105 | Test + Benchmark record/plan | `M6-CP1-TB7-A6-EXEC` — Artifact-Only Test + Benchmark Report | CHANGELOG; M6_Consolidated_Record; retained Review records |
| `Architecture_M6_CP1_TB8_A6_Artifact_Only_Test_Benchmark_Report.md` | 63 | Test + Benchmark record/plan | `M6-CP1-TB8-A6-EXEC` — Artifact-Only Test + Benchmark Report | CHANGELOG; M6_Consolidated_Record; retained Review records |
| `Architecture_M6_CP1_TB9_A7_Artifact_Only_Test_Benchmark_Report.md` | 83 | Test + Benchmark record/plan | `M6-CP1-TB9-A7-EXEC` — Artifact-Only Test + Benchmark Report | CHANGELOG; M6_Consolidated_Record; retained Review records |
| `Architecture_M6_CP1_TB9_A7_R1_Artifact_Only_Test_Benchmark_Report.md` | 73 | Test + Benchmark record/plan | `M6-CP1-TB9-A7-R1-EXEC` — Artifact-Only Test + Benchmark Report | CHANGELOG; M6_Consolidated_Record; retained Review records |
| `Architecture_M6_CP2_CB1_Verifier_R2_Recovery_Code_Build_Plan.md` | 53 | Code + Build record/plan | Architecture M6 CP2 CB1 Verifier R2 Recovery Code + Build Plan | retained Review records |
| `Architecture_M6_CP2_CB1_Verifier_R2_Recovery_Code_Build_Report.md` | 66 | Code + Build record/plan | Architecture M6 CP2 CB1 Verifier R2 Recovery Code + Build Report | CHANGELOG; M6_Consolidated_Record; retained Review records |
| `Architecture_M6_CP2_CB1_Verifier_R3_Recovery_Code_Build_Plan.md` | 87 | Code + Build record/plan | Architecture M6 CP2 CB1 Verifier R3 Recovery Code + Build Plan | CHANGELOG; M6_Consolidated_Record; retained Review records |
| `Architecture_M6_CP2_CB1_Verifier_R3_Recovery_Code_Build_Report.md` | 66 | Code + Build record/plan | Architecture M6 CP2 CB1 Verifier R3 Recovery Code + Build Report | M6_Consolidated_Record |
| `Architecture_M6_CP2_CB2_Coverage_Code_Build_Report.md` | 133 | Code + Build record/plan | Architecture M6 CP2 CB2 Coverage Code + Build Report | CHANGELOG |
| `Architecture_M6_CP2_CB2_Coverage_WIP_Handoff.md` | 96 | working record | M6-CP2-CB2-COVERAGE WIP handoff | CHANGELOG; M6_Consolidated_Record; retained Review records |
| `Architecture_M6_CP2_TB1_Verifier_Artifact_Only_Test_Benchmark_Report.md` | 101 | Test + Benchmark record/plan | `M6-CP2-TB1-VERIFIER-EXEC` — Artifact-Only Test + Benchmark Report | CHANGELOG; M6_Consolidated_Record; retained Review records |
| `Architecture_M6_CP2_TB1_Verifier_R1_Artifact_Only_Test_Benchmark_Report.md` | 93 | Test + Benchmark record/plan | M6-CP2-TB1-VERIFIER-R1-EXEC — Artifact-Only Test + Benchmark Report | CHANGELOG; M6_Consolidated_Record; retained Review records |
| `Architecture_M6_CP2_TB1_Verifier_R2_Artifact_Only_Test_Benchmark_Report.md` | 69 | Test + Benchmark record/plan | M6-CP2-TB1-VERIFIER-R2-EXEC — Artifact-Only Test + Benchmark Report | CHANGELOG; M6_Consolidated_Record; retained Review records |
| `Architecture_M6_CP2_TB2_Coverage_Artifact_Only_Test_Benchmark_Report.md` | 69 | Test + Benchmark record/plan | M6-CP2-TB2-COVERAGE-EXEC — Artifact-Only Test + Benchmark Report | CHANGELOG; M6_Consolidated_Record; retained Review records |
| `Architecture_M6_CP2_TB2_Coverage_Exec_WIP_Handoff.md` | 43 | working record | M6-CP2-TB2-COVERAGE-EXEC WIP handoff | CHANGELOG; M6_Consolidated_Record; retained Review records |
| `Architecture_M6_CP3_CB100_P13_Evaluator_Concave_Quad_Metrics.diff` | 114 | exact patch (applied or superseded; landed source is in git history) | 2 files, +68 −2 | TODO; handoff; retained Review records |
| `Architecture_M6_CP3_CB100_P13_Evaluator_Concave_Quad_Metrics_Code_Build_Record_20261108.md` | 10 | Code + Build record/plan | CB100 evaluator concave-quad metrics — Code + Build (2026-11-08 UTC) | CHANGELOG; TODO |
| `Architecture_M6_CP3_CB101_P13_Evaluator_Quad_Normal_Own_Plane.diff` | 56 | exact patch (applied or superseded; landed source is in git history) | 2 files, +25 −2 | TODO; handoff; retained Review records |
| `Architecture_M6_CP3_CB101_P13_Evaluator_Quad_Normal_Own_Plane_Code_Build_Record_20261108.md` | 9 | Code + Build record/plan | CB101 evaluator quad-normal own-plane — Code + Build (2026-11-08 UTC) | CHANGELOG; TODO; handoff |
| `Architecture_M6_CP3_CB103_P13_A3_Span_Coverage_Receipt.diff` | 292 | exact patch (applied or superseded; landed source is in git history) | 6 files, +211 −1 | CHANGELOG; TODO; retained Review records |
| `Architecture_M6_CP3_CB103_P13_A3_Span_Coverage_Receipt_Code_Build_Record_20261108.md` | 26 | Code + Build record/plan | CB103 — A3 span-coverage receipt (Code + Build, 2026-11-08 UTC) | CHANGELOG; TODO |
| `Architecture_M6_CP3_CB104_P13_A3_Recorded_Boundary_Intervals_Core.diff` | 67 | exact patch (applied or superseded; landed source is in git history) | 0 files, +13 −8 | CHANGELOG |
| `Architecture_M6_CP3_CB104_P13_A3_Source_Rim_Intervals_Code_Build_Record_20261108.md` | 11 | Code + Build record/plan | M6-CP3 CB104 — A3 recorded source-rim intervals (Code + Build) | CHANGELOG; tracker; TODO |
| `Architecture_M6_CP3_CB104_P13_A3_Source_Rim_Intervals_Exact.diff` | 227 | exact patch (applied or superseded; landed source is in git history) | 3 files, +160 −6 | CHANGELOG; TODO; retained Review records |
| `Architecture_M6_CP3_CB105_P13_A3_Observed_Route_Orientation_Oracle_Code_Build_Record_20261108.md` | 11 | Code + Build record/plan | M6-CP3 CB105 — observed route orientation oracle (Code + Build) | CHANGELOG; TODO |
| `Architecture_M6_CP3_CB106_P13_A3_Partition_Stable_Count_Code_Build_Record_20261108.md` | 9 | Code + Build record/plan | CB106 — exact A3 partition-stable count (Code + Build, compile-only) | CHANGELOG |
| `Architecture_M6_CP3_CB106_P13_A3_Partition_Stable_Count_Exact.diff` | 382 | exact patch (applied or superseded; landed source is in git history) | 3 files, +331 −0 | CHANGELOG; TODO; retained Review records |
| `Architecture_M6_CP3_CB107_P13_A3_Partition_Stable_Count_Switch_Code_Build_Record_20261108.md` | 9 | Code + Build record/plan | CB107 — partition-stable preferred-count scheduler switch (Code + Build, compile-only) | CHANGELOG |
| `Architecture_M6_CP3_CB107_P13_A3_Partition_Stable_Count_Switch_Exact.diff` | 217 | exact patch (applied or superseded; landed source is in git history) | 3 files, +55 −79 | CHANGELOG; TODO; retained Review records |
| `Architecture_M6_CP3_CB108_P13_A3_Metric_Breakpoint_Placement_Code_Build_Record_20261108.md` | 11 | Code + Build record/plan | CB108 — metric breakpoint run-profile placement (Code + Build, compile-only) | CHANGELOG; TODO; handoff |
| `Architecture_M6_CP3_CB108_P13_A3_Metric_Breakpoint_Placement_Exact.diff` | 532 | exact patch (applied or superseded; landed source is in git history) | 4 files, +423 −13 | CHANGELOG; TODO; retained Review records |
| `Architecture_M6_CP3_CB109_P13_A3_Metric_Breakpoint_Placement_Switch_Exact.diff` | 377 | exact patch (applied or superseded; landed source is in git history) | 6 files, +130 −77 | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_CB10_Carrier_Endpoint_Subcondition_Probe_Code_Build_Record_20261016.md` | 17 | Code + Build record/plan | M6 CP3 CB10 — carrier endpoint subcondition probe (Code + Build) | CHANGELOG |
| `Architecture_M6_CP3_CB11_R10_Open_Rail_Route_Anchor_Code_Build_Record_20261018.md` | 23 | Code + Build record/plan | CB11 — shared open-rail route anchor, Code + Build | CHANGELOG |
| `Architecture_M6_CP3_CB12_R10_Open_Rail_Chain_Provenance_Code_Build_Record_20261018.md` | 21 | Code + Build record/plan | CB12 — open hard-rail chain provenance, Code + Build | CHANGELOG |
| `Architecture_M6_CP3_CB13A_Chain_Interval_Truth_Table_Code_Build_Record_20261018.md` | 16 | Code + Build record/plan | CB13A — Open-rail chain interval truth table | retained Review records |
| `Architecture_M6_CP3_CB13_R10_Open_Rail_Chain_Interval_Route_Code_Build_Record_20261018.md` | 26 | Code + Build record/plan | CB13 — open-rail chain interval, Code + Build | CHANGELOG |
| `Architecture_M6_CP3_CB14A_Curved_Disk_Rail_Provenance_Code_Build_Record_20261018.md` | 12 | Code + Build record/plan | CB14A — curved-disk rail provenance (Code + Build; 2026-10-18) | retained Review records |
| `Architecture_M6_CP3_CB15_Exact_I_Witness_Code_Build_Record_20261018.md` | 14 | Code + Build record/plan | CB15 exact interior source-edge witness — Code + Build | CHANGELOG |
| `Architecture_M6_CP3_CB16A_Exact_I_Witness_Unbound_Row_Code_Build_Record_20261019.md` | 10 | Code + Build record/plan | CB16A exact I witness unbound row — Code + Build | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_CB16_Exact_I_Witness_Checkers_Code_Build_Record_20261018.md` | 13 | Code + Build record/plan | CB16 exact I endpoint witness checkers — Code + Build | retained Review records |
| `Architecture_M6_CP3_CB17_R10_Factory_Rail_Vertex_Endpoint_Code_Build_Record_20261019.md` | 11 | Code + Build record/plan | CB17 — factory rail-vertex endpoint, compile-only (2026-10-19) | CHANGELOG |
| `Architecture_M6_CP3_CB18_R10_Consumer_Rail_Vertex_Endpoint_Code_Build_Record_20261019.md` | 11 | Code + Build record/plan | CB18 — consumer R endpoint Code + Build (2026-10-19) | CHANGELOG |
| `Architecture_M6_CP3_CB19_Selector242_Atlas_Authority_Test_Plan_20261020.md` | 23 | consumed plan | CB19 test-only plan — selector242 atlas authority (RA-104, 2026-10-20) | tracker; retained Review records |
| `Architecture_M6_CP3_CB1_Entry_R2_A4_Preflight_Stop_Record.md` | 37 | working record | M6-CP3-CB1-ENTRY-R2 — A4 authority preflight stop | CHANGELOG; tracker; TODO; M6_Consolidated_Record; handoff; retained Review records |
| `Architecture_M6_CP3_CB1_Entry_R2_Code_Build_Closeout_Report.md` | 30 | Code + Build record/plan | M6-CP3-CB1-ENTRY-R2 — Code + Build closeout (2026-10-08 UTC) | CHANGELOG; tracker; TODO; M6_Consolidated_Record; handoff; retained Review records |
| `Architecture_M6_CP3_CB1_Entry_R2_WIP_Handoff.md` | 92 | working record | M6-CP3-CB1-ENTRY-R2 — WIP continuation (2026-10-08 UTC) | CHANGELOG; tracker; TODO; M6_Consolidated_Record; handoff; retained Review records |
| `Architecture_M6_CP3_CB1_Entry_R3_RA40_Code_Build_Report.md` | 37 | Code + Build record/plan | CURRENT authoritative RA-40 Code + Build result — 2026-10-10 06:02Z | CHANGELOG; tracker; TODO; M6_Consolidated_Record; handoff; retained Review records |
| `Architecture_M6_CP3_CB1_Entry_R3_RA40_Factory_WIP_20261010.md` | 35 | working record | M6-CP3-CB1-ENTRY-R3 — RA-40 source-bound factory WIP (2026-10-10) | CHANGELOG; tracker; TODO; M6_Consolidated_Record; handoff; retained Review records |
| `Architecture_M6_CP3_CB1_Entry_R3_Recovery_Code_Build_Plan.md` | 21 | Code + Build record/plan | M6-CP3-CB1-ENTRY-R3 — RA-37a ACCEPTED / bounded Code + Build plan | retained Review records |
| `Architecture_M6_CP3_CB1_Entry_R3_Source_Preflight_Stop_Record.md` | 86 | working record | M6-CP3-CB1-ENTRY-R3 — mandatory source-producer preflight STOP (2026-10-08) | CHANGELOG; tracker; TODO; M6_Consolidated_Record; handoff; retained Review records |
| `Architecture_M6_CP3_CB1_Entry_R3_WIP_Continuation.md` | 473 | working record | CURRENT authoritative RA-40 Code + Build result — 2026-10-10 06:02Z | CHANGELOG; tracker; TODO; M6_Consolidated_Record; handoff; retained Review records |
| `Architecture_M6_CP3_CB1_Entry_R4_Recovery_Code_Build_Plan.md` | 163 | Code + Build record/plan | CURRENT — R4 verified current source; independent selected-branch Review prerequisite (2026-10-14 18:30 UTC) | CHANGELOG; tracker; TODO; M6_Consolidated_Record; handoff; retained Review records |
| `Architecture_M6_CP3_CB1_Entry_R4_WIP_Continuation.md` | 169 | working record | M6-CP3-CB1-ENTRY-R4 — Code + Build WIP continuation | CHANGELOG; tracker; TODO; M6_Consolidated_Record; handoff; retained Review records |
| `Architecture_M6_CP3_CB21_Torus_Witness_Scope_Code_Build_Record_20261021.md` | 17 | Code + Build record/plan | CB21 — Torus witness scope: Code + Build | retained Review records |
| `Architecture_M6_CP3_CB22B_Torus_A5_Site_Test_Messages_Code_Build_Record_20261021.md` | 12 | Code + Build record/plan | M6 CP3 CB22B — A5 isolation-site test-message compile record (2026-10-21) | retained Review records |
| `Architecture_M6_CP3_CB22_Torus_A5_Isolation_Site_Code_Build_Stop_Record_20261021.md` | 14 | Code + Build record/plan | CB22 — compile stop (2026-10-21) | retained Review records |
| `Architecture_M6_CP3_CB23_Torus_A5_Seam_Face_Site_Code_Build_Record_20261021.md` | 16 | Code + Build record/plan | CB23 — Torus A5 seam-face rejection-site Code + Build (2026-10-21) | retained Review records |
| `Architecture_M6_CP3_CB23_Torus_A5_Seam_Face_Site_Review_Decision_20261021.md` | 43 | Review/definition/audit record | RA-122 — CB23 diagnostic-only seam-face review (2026-10-21) | CHANGELOG |
| `Architecture_M6_CP3_CB24_Seam_Frame_Values_Site_Code_Build_Record_20261021.md` | 15 | Code + Build record/plan | CB24 — Seam frame values Code + Build record (2026-10-21) | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_CB24_Seam_Frame_Values_Site_Review_Decision_20261021.md` | 39 | Review/definition/audit record | RA-125 — independent CB24 seam-frame diagnostic review (2026-10-21) | CHANGELOG |
| `Architecture_M6_CP3_CB25_A5_Shared_Node_Side_Authority_Code_Build_Record_20261022.md` | 12 | Code + Build record/plan | CB25 — A5 shared-node side authority: Code + Build (2026-10-22) | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_CB25_A5_Shared_Node_Side_Authority_Review_Decision_20261022.md` | 53 | Review/definition/audit record | RA-128 — CB25 independent Review: scoped acceptance (2026-10-22) | CHANGELOG; tracker |
| `Architecture_M6_CP3_CB26_A7_Certified_Seam_Cross_Sheet_Authority_Code_Build_Record_20261022.md` | 13 | Code + Build record/plan | CB26 — A7 certified-seam cross-sheet authority: Code + Build (2026-10-22) | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_CB26_A7_Certified_Seam_Cross_Sheet_Authority_Review_Decision_20261022.md` | 50 | Review/definition/audit record | RA-131 — CB26 A7 certified cross-sheet independent Review (2026-10-22) | CHANGELOG; tracker |
| `Architecture_M6_CP3_CB27A_Wedge_Membership_Oracle_Code_Build_Record_20261022.md` | 12 | Code + Build record/plan | CB27A — certified-seam wedge-membership negative oracle: Code + Build (2026-10-22) | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_CB27A_Wedge_Membership_Oracle_Review_Decision_20261022.md` | 40 | Review/definition/audit record | CB27A certified-seam wedge-membership oracle — independent Review (2026-10-22) | CHANGELOG; tracker |
| `Architecture_M6_CP3_CB27_A7_Certified_Seam_Negative_Oracles_Code_Build_Record_20261022.md` | 13 | Code + Build record/plan | CB27 — A7 certified seam negative oracles: Code + Build (2026-10-22) | CHANGELOG |
| `Architecture_M6_CP3_CB28A_M1_Precedence_Assert_Diagnostics_Code_Build_Record_20261022.md` | 12 | Code + Build record/plan | CB28A — three M1/A5 rejection messages, code/build (2026-10-22) | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_CB28A_M1_Precedence_Assert_Diagnostics_Review_Decision_20261022.md` | 41 | Review/definition/audit record | CB28A independent review — three M1/A5 rejection diagnostics (2026-10-22) | CHANGELOG |
| `Architecture_M6_CP3_CB28_Factory_Error_Diagnostics_Code_Build_Record_20261022.md` | 11 | Code + Build record/plan | CB28 — factory rejection diagnostics: Code + Build (2026-10-22) | CHANGELOG |
| `Architecture_M6_CP3_CB29_A4_Certificate_Association_Ownership_Code_Build_Record_20261023.md` | 21 | Code + Build record/plan | CB29 — A4 certificate association ownership (Code + Build; COMPLETE) | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_CB29_A4_Certificate_Association_Ownership_Review_Decision_20261023.md` | 53 | Review/definition/audit record | CB29 independent review — A4 certificate / A5 association ownership (2026-10-23) | CHANGELOG |
| `Architecture_M6_CP3_CB30_Periodic_Owner_Fixture_Gauge_Code_Build_Record_20261023.md` | 13 | Code + Build record/plan | CB30 periodic-owner fixture gauge — Code + Build, 2026-10-23 | CHANGELOG |
| `Architecture_M6_CP3_CB30_Periodic_Owner_Fixture_Gauge_Review_Decision_20261023.md` | 41 | Review/definition/audit record | RA-147 — CB30 periodic-owner gauge independent Code + Build Review (2026-10-23) | CHANGELOG |
| `Architecture_M6_CP3_CB31_Odd_Atlas_Transport_Permutation_Code_Build_Plan_20261023.md` | 26 | Code + Build record/plan | CB31 — odd atlas transport and topology-keyed permutation witness (2026-10-23) | CHANGELOG; tracker |
| `Architecture_M6_CP3_CB31_Odd_Atlas_Transport_Permutation_Code_Build_Record_20261023.md` | 10 | Code + Build record/plan | CB31 odd atlas transport/permutation — Code + Build, 2026-10-23 | CHANGELOG |
| `Architecture_M6_CP3_CB31_Odd_Atlas_Transport_Permutation_Review_Decision_20261023.md` | 49 | Review/definition/audit record | CB31 independent static review — odd atlas transport and permutation (2026-10-23) | CHANGELOG; tracker |
| `Architecture_M6_CP3_CB32_Odd_Transport_Oracle_Correction_Code_Build_Plan_20261023.md` | 19 | Code + Build record/plan | CB32 — independent odd-transport and inverse-oracle correction (2026-10-23) | CHANGELOG; tracker |
| `Architecture_M6_CP3_CB32_Odd_Transport_Oracle_Correction_Code_Build_Record_20261024.md` | 8 | Code + Build record/plan | CB32 independent signed raw-transport oracle — Code + Build, 2026-10-24 | CHANGELOG |
| `Architecture_M6_CP3_CB32_Odd_Transport_Oracle_Correction_Review_Decision_20261024.md` | 48 | Review/definition/audit record | CB32 independent static Review — odd signed raw-source transport (2026-10-24) | CHANGELOG; tracker |
| `Architecture_M6_CP3_CB33_A3_Cycle_Mismatch_Locus_Diagnostic_Code_Build_Record_20261024.md` | 13 | Code + Build record/plan | CB33 — A3 cycle-mismatch locus diagnostic (Code + Build, 2026-10-24) | CHANGELOG; M6_Consolidated_Record; retained Review records |
| `Architecture_M6_CP3_CB33_A3_Cycle_Mismatch_Locus_Diagnostic_Review_Decision_20261024.md` | 46 | Review/definition/audit record | CB33-REV — A3 cycle-mismatch diagnostic independent Review (2026-10-24) | CHANGELOG; M6_Consolidated_Record |
| `Architecture_M6_CP3_CB34_Periodic_Route_Face_Gauge_Code_Build_Plan_20261024.md` | 28 | Code + Build record/plan | CB34 plan — restore valid periodic-route face gauge (2026-10-24; amended by RA-150) | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_CB34_Periodic_Route_Face_Gauge_Code_Build_Record_20261024.md` | 13 | Code + Build record/plan | CB34 test-only gauge repair: code and build record (2026-10-24) | CHANGELOG |
| `Architecture_M6_CP3_CB34_Periodic_Route_Face_Gauge_Review_Decision_20261024.md` | 45 | Review/definition/audit record | CB34-REV — independent face-gauge source and compile review (2026-10-24) | CHANGELOG |
| `Architecture_M6_CP3_CB35_Periodic_Monodromy_Witness_Code_Build_Plan_20261024.md` | 31 | Code + Build record/plan | CB35 plan — authoritative periodic monodromy witnesses (test-only, compile-only) (2026-10-24) | retained Review records |
| `Architecture_M6_CP3_CB35_Periodic_Monodromy_Witness_Code_Build_Record_20261024.md` | 14 | Code + Build record/plan | CB35 periodic monodromy witness — code and build record (2026-10-24) | CHANGELOG |
| `Architecture_M6_CP3_CB35_Periodic_Monodromy_Witness_Independent_Review_20261024.md` | 60 | Review/definition/audit record | CB35 periodic-monodromy witnesses — independent static Review (2026-10-24) | CHANGELOG; tracker |
| `Architecture_M6_CP3_CB35_R1_Published_Route_Oracle_Correction_Code_Build_Record_20261024.md` | 11 | Code + Build record/plan | CB35-R1 published-route oracle correction — Code + Build (2026-10-24) | CHANGELOG |
| `Architecture_M6_CP3_CB35_R1_Published_Route_Oracle_Correction_Plan_20261024.md` | 11 | consumed plan | CB35 R1 test-only correction plan — complete published-route oracle (2026-10-24) | CHANGELOG |
| `Architecture_M6_CP3_CB35_R1_Published_Route_Oracle_Independent_Review_20261024.md` | 52 | Review/definition/audit record | CB35-R1 published-route oracle — independent static Review (2026-10-24) | CHANGELOG; tracker |
| `Architecture_M6_CP3_CB35_R2_Oriented_Route_Identity_Oracle_Code_Build_Record_20261025.md` | 11 | Code + Build record/plan | CB35-R2 oriented route identity oracle — Code + Build (2026-10-25) | CHANGELOG |
| `Architecture_M6_CP3_CB35_R2_Oriented_Route_Identity_Oracle_Independent_Review_20261025.md` | 57 | Review/definition/audit record | CB35-R2 oriented published-route oracle — independent review (2026-10-25) | CHANGELOG; tracker |
| `Architecture_M6_CP3_CB35_R2_Oriented_Route_Identity_Oracle_Plan_20261024.md` | 11 | consumed plan | CB35 R2 oriented published-route oracle — test-only Code + Build plan (2026-10-24) | CHANGELOG |
| `Architecture_M6_CP3_CB36_Periodic_Route_Atlas_Transport_Code_Build_Plan_20261025.md` | 34 | Code + Build record/plan | CB36 plan — periodic observed steps read A3 transport (production, compile-only) (2026-10-25) | retained Review records |
| `Architecture_M6_CP3_CB36_Periodic_Route_Atlas_Transport_Code_Build_Record_20261025.md` | 11 | Code + Build record/plan | CB36 periodic route atlas transport — Code + Build (2026-10-25) | CHANGELOG; M6_Consolidated_Record |
| `Architecture_M6_CP3_CB36_Periodic_Route_Atlas_Transport_Independent_Review_Decision_20261025.md` | 56 | Review/definition/audit record | CB36 periodic route atlas transport — independent static Review (2026-10-25) | CHANGELOG; tracker; M6_Consolidated_Record |
| `Architecture_M6_CP3_CB36_TB36_Harness_Orchestration_Correction_Record_20261025.md` | 26 | Test + Benchmark record/plan | CB36 — TB36 harness orchestration correction (2026-10-25) | CHANGELOG |
| `Architecture_M6_CP3_CB37_Selector250_Factory_Site_Independent_Review_20261025.md` | 43 | Review/definition/audit record | CB37-REV — independent static selector250 factory-site review (2026-10-25) | CHANGELOG |
| `Architecture_M6_CP3_CB37_Selector250_Factory_Site_Message_Prepared_Patch_Record_20261025.md` | 23 | Review/definition/audit record | CB37 — selector 250 factory-site message (Code + Build, 2026-10-25) | CHANGELOG |
| `Architecture_M6_CP3_CB38_Selector250_Rail_Authority_Code_Build_Record_20261025.md` | 15 | Code + Build record/plan | M6-CP3-CB38 — selector 250 hard-rail authority (Code + Build) | tracker; retained Review records |
| `Architecture_M6_CP3_CB38_Selector250_Rail_Authority_Independent_Review_Decision_20261025.md` | 47 | Review/definition/audit record | CB38 selector-250 rail authority — independent static review (2026-10-25) | CHANGELOG; tracker |
| `Architecture_M6_CP3_CB39_A3_Source_Edge_Tamper_Independent_Review_Decision_20261026.md` | 48 | Review/definition/audit record | CB39 A3 source-edge tamper — independent static Review (2026-10-26) | CHANGELOG |
| `Architecture_M6_CP3_CB39_A3_Source_Edge_Tamper_Rehome_Code_Build_Record_20261026.md` | 16 | Code + Build record/plan | M6-CP3-CB39 — A3 source-edge tamper oracle re-home (Code + Build) | CHANGELOG |
| `Architecture_M6_CP3_CB40_Turning_Field_Monodromy_Rehome_Code_Build_Record_20261026.md` | 12 | Code + Build record/plan | CB40 — turning-field monodromy oracle re-home (Code + Build) | CHANGELOG |
| `Architecture_M6_CP3_CB40_Turning_Field_Monodromy_Rehome_Independent_Review_Decision_20261026.md` | 55 | Review/definition/audit record | CB40 independent review — selector 192/247 turning-field monodromy (2026-10-26) | CHANGELOG |
| `Architecture_M6_CP3_CB41_Equivalent_Lift_A3_Ingress_Rehome_Code_Build_Record_20261026.md` | 12 | Code + Build record/plan | CB41 — equivalent-lift A3 ingress re-home (Code + Build) | CHANGELOG |
| `Architecture_M6_CP3_CB41_Equivalent_Lift_A3_Ingress_Rehome_Independent_Review_Decision_20261026.md` | 51 | Review/definition/audit record | CB41 independent review — selector189 equivalent signed-lift A3 ingress (2026-10-26) | CHANGELOG |
| `Architecture_M6_CP3_CB42_Polygonal_Disk_Locus_Pin_Code_Build_Record_20261026.md` | 11 | Code + Build record/plan | CB42 — polygonal-disk rejection locus pin (Code + Build) | CHANGELOG |
| `Architecture_M6_CP3_CB42_Polygonal_Disk_Locus_Pin_Independent_Review_Decision_20261026.md` | 44 | Review/definition/audit record | CB42 independent review — polygonal-disk first-rejection locus (2026-10-26) | CHANGELOG |
| `Architecture_M6_CP3_CB43_Selector190_Legacy_Ingress_Rehome_Code_Build_Record_20261026.md` | 13 | Code + Build record/plan | M6 CP3 CB43 — selector190 legacy ingress re-home (Code + Build, 2026-10-26) | CHANGELOG |
| `Architecture_M6_CP3_CB43_Selector190_Legacy_Ingress_Rehome_Independent_Review_Decision_20261026.md` | 48 | Review/definition/audit record | CB43 independent Review — RA-160.3 selector190 ingress re-home (2026-10-26) | CHANGELOG |
| `Architecture_M6_CP3_CB44_Selector405_Fixed_Plan_Rail_Provenance_Code_Build_Record_20261026.md` | 13 | Code + Build record/plan | CB44 — selector405 fixed-plan rail provenance (Code + Build) | CHANGELOG |
| `Architecture_M6_CP3_CB44_Selector405_Rail_Provenance_Independent_Review_Decision_20261026.md` | 42 | Review/definition/audit record | Independent CB44 Review — selector405 fixed-plan rail provenance (2026-10-26) | CHANGELOG |
| `Architecture_M6_CP3_CB45_Selector242_Seam_Rehome_Code_Build_Record_20261026.md` | 10 | Code + Build record/plan | CB45 — selector242 seam-consumer re-home (Code + Build) | CHANGELOG |
| `Architecture_M6_CP3_CB45_Selector242_Seam_Rehome_Independent_Review_Decision_20261027.md` | 46 | Review/definition/audit record | CB45 independent static Review — selector242 source-adjacent isolation seam (2026-10-27) | CHANGELOG |
| `Architecture_M6_CP3_CB45_Selector242_Seam_Rehome_Specification_20261026.md` | 25 | Review/definition/audit record | CB45 specification — selector242 seam-consumer re-home (definition-stage draft, 2026-10-26) | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_CB46B_Selector174_Manifold_Fixture_Code_Build_Record_20261027.md` | 16 | Code + Build record/plan | CB46B selector174 manifold fixture — Code + Build (2026-10-27) | CHANGELOG |
| `Architecture_M6_CP3_CB46_Rail_Oracle_Rehome_And_Endpoint_Diagnostics_Code_Build_Record_20261027.md` | 13 | Code + Build record/plan | CB46 — rail-oracle re-home and endpoint diagnostics (Code + Build) | CHANGELOG |
| `Architecture_M6_CP3_CB47A_Harness_Manifest_Pins_Code_Record_20261027.md` | 16 | Review/definition/audit record | CB47A — harness manifest pin migration, tool-only Code + Build (2026-10-27) | CHANGELOG |
| `Architecture_M6_CP3_CB47_Endpoint_Witnesses_Interim_Investigation_20261027.md` | 30 | Review/definition/audit record | CB47 endpoint witness interim investigation — 2026-10-27 | CHANGELOG |
| `Architecture_M6_CP3_CB47_REV_Endpoint_Witness_Contract_Rehome_Decision_20261027.md` | 259 | Review/definition/audit record | RA-166 — CB47 E3 block resolved: D5 and D2 witnesses re-homed to A4's real representation; E1 defect fixed; exact CB47 patch (2026-10-27) | CHANGELOG; tracker |
| `Architecture_M6_CP3_CB47_RP01_Endpoint_Witnesses_Code_Build_Record_20261027.md` | 14 | Code + Build record/plan | CB47 RP-01 — exact RA-166 endpoint witness corrections (2026-10-27) | CHANGELOG |
| `Architecture_M6_CP3_CB48_RP01_Gauge_Cluster_Tests_Code_Build_Record_20261028.md` | 14 | Code + Build record/plan | CB48 RP-01 — RA-167 gauge-cluster test corrections (2026-10-28) | CHANGELOG |
| `Architecture_M6_CP3_CB49E_RP01_E2_Rail_Vertex_Adjacency_Code_Build_Record_20261028.md` | 14 | Code + Build record/plan | CB49E RP-01 — E2 rail vertex adjacency (2026-10-28) | CHANGELOG |
| `Architecture_M6_CP3_CB49_RP01_G3_A5_Periodic_Placement_Gauge_Code_Build_Record_20261028.md` | 13 | Code + Build record/plan | CB49 RP-01 — G3 A5 periodic placement gauge (2026-10-28) | CHANGELOG |
| `Architecture_M6_CP3_CB50A_RP01_Orchestration_Correction_Record_20261029.md` | 30 | Test + Benchmark record/plan | CB50A — TB50 asserted-site preflight contract correction (orchestration only) | CHANGELOG |
| `Architecture_M6_CP3_CB50C_RP01_Census_Harness_Orchestration_Record_20261029.md` | 17 | Test + Benchmark record/plan | CB50C — exact P7 census harness orchestration correction (2026-10-29) | CHANGELOG |
| `Architecture_M6_CP3_CB50F_RP01_C1_Factory_Rail_Cover_Code_Build_Record_20261029.md` | 12 | Code + Build record/plan | CB50F RP-01 — C1 factory hard-rail cover (2026-10-29) | CHANGELOG |
| `Architecture_M6_CP3_CB50_RP01_C1_Ingress_Orphan_Hard_Edge_Code_Build_Record_20261029.md` | 12 | Code + Build record/plan | CB50 RP-01 — C1 ingress orphan hard-edge guard (2026-10-29) | CHANGELOG |
| `Architecture_M6_CP3_CB51_RP01_P1B_Network_Owner_Witness_Code_Build_Record_20261029.md` | 12 | Code + Build record/plan | CB51 RP-01 — P1-b network owner witness (2026-10-29) | CHANGELOG |
| `Architecture_M6_CP3_CB52_RP01_E2_Factory_Site_Pins_Code_Build_Record_20261029.md` | 12 | Code + Build record/plan | CB52 RP-01 — E2 factory rejection site pins (2026-10-29) | CHANGELOG |
| `Architecture_M6_CP3_CB53_RP01_Gate_Membership_Preflight_Code_Build_Record_20261030.md` | 12 | working record | CB53 — gate-membership preflight harness (2026-10-30) | CHANGELOG |
| `Architecture_M6_CP3_CB54_RP01_Terminal_Path_Witnesses_Code_Build_Record_20261030.md` | 22 | Code + Build record/plan | CB54 RP-01 — terminal-path witnesses (2026-10-30) | CHANGELOG |
| `Architecture_M6_CP3_CB55_A3_Exact_Branch_Topology_Code_Build_Record_20261030.md` | 18 | Code + Build record/plan | CB55 — A3 exact branch topology (O15) (2026-10-30) | CHANGELOG |
| `Architecture_M6_CP3_CB56_API_Display_Vertex_Stop_Witness_Code_Build_Record_20261031.md` | 14 | Code + Build record/plan | CB56 — API display vertex-stop witness (row 935) (2026-10-31) | CHANGELOG |
| `Architecture_M6_CP3_CB57_O2_No_Atlas_Entry_Gate_Code_Build_Record_20261031.md` | 15 | Code + Build record/plan | CB57 — O2 no-atlas entry gate (2026-10-31) | CHANGELOG |
| `Architecture_M6_CP3_CB65_P13_Canonical_Dyadic_Trace_Exit_Code_Build_Report_20261031.md` | 20 | Code + Build record/plan | CB65 canonical dyadic trace exit — Code + Build (2026-10-31) | CHANGELOG; TODO |
| `Architecture_M6_CP3_CB66_P13_Slit_Cycle_Basis_Code_Build_Report_20261101.md` | 17 | Code + Build record/plan | CB66 slit-cycle-basis adapter — Code + Build (2026-11-01) | CHANGELOG; TODO |
| `Architecture_M6_CP3_CB69_Arrangement_Incidence_Terminal_Code_Build_Record_20261101.md` | 9 | Code + Build record/plan | CB69 — Arrangement incidence terminal, Code + Build (2026-11-01) | CHANGELOG; TODO |
| `Architecture_M6_CP3_CB70_Arrangement_Wedge_Rotation_Code_Build_Record_20261101.md` | 9 | Code + Build record/plan | CB70 — Arrangement wedge rotation, Code + Build (2026-11-01) | CHANGELOG; handoff |
| `Architecture_M6_CP3_CB71_Completion_Chart_Graph_Reuse_Code_Build_Record_20261101.md` | 9 | Code + Build record/plan | CB71 — Completion chart graph reuse, Code + Build (2026-11-01) | CHANGELOG; TODO; handoff |
| `Architecture_M6_CP3_CB71_P13_Completion_Chart_Graph_Reuse_Code_Build_Plan_20261101.md` | 15 | Code + Build record/plan | CB71 — Completion source-chart reuse, compile-only plan | CHANGELOG; TODO; retained Review records |
| `Architecture_M6_CP3_CB72_Completion_Pass_Graph_Code_Build_Record_20261101.md` | 8 | Code + Build record/plan | CB72 — Completion-pass source-chart graph reuse, Code + Build (2026-11-01) | CHANGELOG; TODO; handoff |
| `Architecture_M6_CP3_CB73_P13_Completion_Embedding_Code_Build_Record_20261101.md` | 7 | Code + Build record/plan | CB73 — Exact source-orientation embedding guard, Code + Build (2026-11-01) | CHANGELOG; TODO |
| `Architecture_M6_CP3_CB74_P13_Completion_Quadrangulation_Search_Code_Build_Record_20261101.md` | 8 | Code + Build record/plan | CB74 — Embedded boundary quadrangulation search, Code + Build (2026-11-01) | CHANGELOG; TODO |
| `Architecture_M6_CP3_CB75_P13_Completion_Terminal_Detail_Code_Build_Record_20261102.md` | 10 | Code + Build record/plan | CB75 — Typed completion terminal detail, Code + Build (2026-11-02) | CHANGELOG; TODO |
| `Architecture_M6_CP3_CB76_P13_Patch_Boundary_Side_Start_Code_Build_Record_20261102.md` | 9 | Code + Build record/plan | CB76 — Patch boundary side-zero start, Code + Build (2026-11-02) | CHANGELOG; TODO |
| `Architecture_M6_CP3_CB77_P13_Needle_Grid_Boundary_Search_Code_Build_Record_20261102.md` | 9 | Code + Build record/plan | CB77 needle-grid boundary-search — Code + Build record (2026-11-02) | CHANGELOG; TODO |
| `Architecture_M6_CP3_CB78_P13_Support_Chord_Admission_Code_Build_Record_20261102.md` | 24 | Code + Build record/plan | M6-CP3-CB78 P13 support-chord admission — Code + Build record (2026-11-02) | TODO; handoff |
| `Architecture_M6_CP3_CB79_P13_Node_Stitch_Key_Code_Build_Record_20261103.md` | 15 | Code + Build record/plan | M6-CP3-CB79 P13 arrangement-node stitch key — Code + Build (2026-11-03) | CHANGELOG; TODO; handoff |
| `Architecture_M6_CP3_CB80_P13_Rail_Binding_Once.diff` | 281 | exact patch (applied or superseded; landed source is in git history) | 3 files, +174 −31 | TODO; handoff; retained Review records |
| `Architecture_M6_CP3_CB80_P13_Rail_Binding_Once_Code_Build_Record_20261103.md` | 13 | Code + Build record/plan | M6-CP3-CB80 P13 rail source binding once — Code + Build (2026-11-03) | CHANGELOG; TODO |
| `Architecture_M6_CP3_CB81_P13_Lent_Projection_Cache.diff` | 169 | exact patch (applied or superseded; landed source is in git history) | 3 files, +94 −12 | retained Review records |
| `Architecture_M6_CP3_CB81_P13_Lent_Projection_Cache_Code_Build_Record_20261104.md` | 9 | Code + Build record/plan | M6-CP3-CB81 P13 lent projection cache — Code + Build (2026-11-04) | CHANGELOG; TODO |
| `Architecture_M6_CP3_CB82_P13_Lent_Label_Support.diff` | 349 | exact patch (applied or superseded; landed source is in git history) | 4 files, +198 −20 | retained Review records |
| `Architecture_M6_CP3_CB82_P13_Lent_Label_Support_Code_Build_Record_20261104.md` | 9 | Code + Build record/plan | M6-CP3-CB82 P13 lent label support — Code + Build (2026-11-04) | CHANGELOG; TODO |
| `Architecture_M6_CP3_CB83_P13_Output_Validation_Terminal_Detail.diff` | 16 | exact patch (applied or superseded; landed source is in git history) | 1 files, +4 −1 | retained Review records |
| `Architecture_M6_CP3_CB83_P13_Output_Validation_Terminal_Detail_Code_Build_Record_20261104.md` | 11 | Code + Build record/plan | CB83 output-validation terminal detail — Code + Build record (2026-11-04) | CHANGELOG; TODO |
| `Architecture_M6_CP3_CB84_P13_Linux_Vase_Diagnostic_Timing_Work_Preservation_20261104.md` | 22 | working record | CB84 Linux Vase diagnostic timing — work preservation (2026-11-04) | TODO; retained Review records |
| `Architecture_M6_CP3_CB85_P13_Arrangement_TJunction_Face_Scan.diff` | 178 | exact patch (applied or superseded; landed source is in git history) | 3 files, +124 −11 | TODO; handoff; retained Review records |
| `Architecture_M6_CP3_CB85_P13_Arrangement_TJunction_Face_Scan_Code_Build_Record_20261104.md` | 10 | Code + Build record/plan | CB85 arrangement T-junction source-face scan — Code + Build (2026-11-04) | CHANGELOG; TODO |
| `Architecture_M6_CP3_CB86_P13_Selection_Endpoint_Net_Change.diff` | 167 | exact patch (applied or superseded; landed source is in git history) | 3 files, +91 −17 | retained Review records |
| `Architecture_M6_CP3_CB86_P13_Selection_Endpoint_Net_Change_Code_Build_Record_20261104.md` | 11 | Code + Build record/plan | CB86 selection endpoint net-change — Code + Build (2026-11-04) | CHANGELOG; TODO; handoff |
| `Architecture_M6_CP3_CB87_P13_Bow_Tie_Vertex_Edges.diff` | 134 | exact patch (applied or superseded; landed source is in git history) | 2 files, +96 −7 | retained Review records |
| `Architecture_M6_CP3_CB87_P13_Bow_Tie_Vertex_Edges_Code_Build_Record_20261104.md` | 11 | Code + Build record/plan | CB87 bow-tie vertex-edge indexing — Code + Build (2026-11-04) | CHANGELOG; TODO; handoff |
| `Architecture_M6_CP3_CB88_P13_Final_Validation_Row_Labels.diff` | 72 | exact patch (applied or superseded; landed source is in git history) | 2 files, +45 −2 | retained Review records |
| `Architecture_M6_CP3_CB88_P13_Final_Validation_Row_Labels_Code_Build_Record_20261104.md` | 10 | Code + Build record/plan | CB88 final-validation row-label lookup — Code + Build (2026-11-04) | CHANGELOG; TODO |
| `Architecture_M6_CP3_CB89_P13_Census_Platform_Digest.diff` | 68 | exact patch (applied or superseded; landed source is in git history) | 1 files, +45 −0 | CHANGELOG; TODO; handoff; retained Review records |
| `Architecture_M6_CP3_CB89_P13_Census_Platform_Digest_Code_Build_Record_20261104.md` | 11 | Code + Build record/plan | CB89 — Census Platform Digest, Code + Build (2026-11-04) | TODO; ORIENTATION |
| `Architecture_M6_CP3_CB89_P13_Platform_Digest_macOS_Reference.tsv` | 130 | per-turn data/receipt | 129 data rows | CHANGELOG; TODO; handoff; retained Review records |
| `Architecture_M6_CP3_CB90_P13_Arrangement_Cell_Order_Tiebreak.diff` | 36 | exact patch (applied or superseded; landed source is in git history) | 2 files, +12 −2 | TODO; handoff; retained Review records |
| `Architecture_M6_CP3_CB90_P13_Arrangement_Cell_Order_Tiebreak_Code_Build_Record_20261105.md` | 10 | Code + Build record/plan | CB90 — Arrangement cell order tie-break, Code + Build (2026-11-05) | CHANGELOG; tracker; TODO |
| `Architecture_M6_CP3_CB90_P13_Platform_Digest_macOS_FMAoff_Reference.tsv` | 130 | per-turn data/receipt | 129 data rows | TODO; handoff; retained Review records |
| `Architecture_M6_CP3_CB91_P13_Final_Validation_Binding_Code_Build_Record_20261105.md` | 8 | Code + Build record/plan | CB91 — Final source-binding check once: Code + Build (2026-11-05) | CHANGELOG; TODO; handoff; ORIENTATION |
| `Architecture_M6_CP3_CB91_P13_Final_Validation_Binding_Once.diff` | 177 | exact patch (applied or superseded; landed source is in git history) | 3 files, +73 −40 | TODO; handoff; retained Review records |
| `Architecture_M6_CP3_CB92_P13_Source_Vertex_Fan_Identity_WIP_20261105.md` | 13 | working record | CB92 — source-vertex fan seed identity: Code + Build complete (2026-11-05) | CHANGELOG |
| `Architecture_M6_CP3_CB92_P13_Source_Vertex_Fan_Seed_Identity.diff` | 285 | exact patch (applied or superseded; landed source is in git history) | 2 files, +218 −15 | TODO; handoff; retained Review records |
| `Architecture_M6_CP3_CB93_P13_Orientation_Whole_Quad_Normal.diff` | 94 | exact patch (applied or superseded; landed source is in git history) | 3 files, +59 −4 | handoff; retained Review records |
| `Architecture_M6_CP3_CB93_P13_Whole_Quad_Normal_Code_Build_Record_20261105.md` | 8 | Code + Build record/plan | CB93 — whole-quad orientation Code + Build record (2026-11-05) | TODO; handoff; retained Review records |
| `Architecture_M6_CP3_CB94_P13_Orientation_Single_Writer.diff` | 183 | exact patch (applied or superseded; landed source is in git history) | 3 files, +3 −142 | TODO; handoff; retained Review records |
| `Architecture_M6_CP3_CB94_P13_Orientation_Single_Writer_Code_Build_Record_20261105.md` | 10 | Code + Build record/plan | CB94 — single-writer orientation Code + Build record (COMPLETE / compile-green; 2026-11-05) | CHANGELOG; TODO |
| `Architecture_M6_CP3_CB95_P13_Quad_Self_Intersection_Own_Plane.diff` | 158 | exact patch (applied or superseded; landed source is in git history) | 2 files, +89 −35 | TODO; handoff; retained Review records |
| `Architecture_M6_CP3_CB95_P13_Quad_Self_Intersection_Own_Plane_Code_Build_Record_20261105.md` | 8 | Code + Build record/plan | CB95 — own-plane quad self-intersection Code + Build record (COMPLETE / compile GREEN; 2026-11-05) | CHANGELOG; TODO |
| `Architecture_M6_CP3_CB96_P13_Completion_Embedding_Own_Plane.diff` | 74 | exact patch (applied or superseded; landed source is in git history) | 2 files, +40 −12 | TODO; handoff; retained Review records |
| `Architecture_M6_CP3_CB96_P13_Completion_Embedding_Own_Plane_Code_Build_Record_20261105.md` | 7 | Code + Build record/plan | CB96 — completion own-plane embedding Code + Build record (COMPLETE / compile GREEN; 2026-11-05) | CHANGELOG; TODO |
| `Architecture_M6_CP3_CB97_P13_Validator_Contact_Length_Units.diff` | 114 | exact patch (applied or superseded; landed source is in git history) | 3 files, +51 −9 | TODO; retained Review records |
| `Architecture_M6_CP3_CB97_P13_Validator_Contact_Length_Units_Code_Build_Record_20261107.md` | 11 | Code + Build record/plan | CB97 — validator contact length units (Code + Build; 2026-11-07 UTC) | CHANGELOG; TODO; handoff |
| `Architecture_M6_CP3_CB98_P13_Validator_Concave_Quad_Triangles.diff` | 113 | exact patch (applied or superseded; landed source is in git history) | 3 files, +70 −2 | TODO; retained Review records |
| `Architecture_M6_CP3_CB98_P13_Validator_Concave_Quad_Triangles_Code_Build_Record_20261107.md` | 12 | Code + Build record/plan | CB98 — validator concave-quad triangle fan (Code + Build; 2026-11-07 UTC) | CHANGELOG; TODO; handoff |
| `Architecture_M6_CP3_CB99_P13_Completion_Corner_On_Opposite_Edge.diff` | 344 | exact patch (applied or superseded; landed source is in git history) | 6 files, +119 −29 | TODO; retained Review records |
| `Architecture_M6_CP3_CB99_P13_Completion_Corner_On_Opposite_Edge_Code_Build_Record_20261107.md` | 15 | Code + Build record/plan | CB99 — completion corner on opposite edge (Code + Build; 2026-11-07 UTC) | CHANGELOG; TODO; handoff |
| `Architecture_M6_CP3_DEFN_A3_Exact_Branch_Topology_Predicates_20261030.md` | 495 | Review/definition/audit record | RA-180 — O15: exact A3 branch-topology predicates (2026-10-30) | CHANGELOG; tracker |
| `Architecture_M6_CP3_DEFN_API_Display_Vertex_Stop_Witness_20261031.md` | 170 | Review/definition/audit record | RA-182 — Row 935 display witness: a legitimate source-vertex stop (2026-10-31) | CHANGELOG; tracker |
| `Architecture_M6_CP3_DEFN_FG01_Periodic_Face_Gauge_Factory_Contract_20261023.md` | 37 | Review/definition/audit record | FG01 — direct periodic-owner face-gauge factory contract (2026-10-23) | CHANGELOG |
| `Architecture_M6_CP3_DEFN_FG01_Periodic_Face_Gauge_Factory_Contract_Review_Decision_20261023.md` | 110 | Review/definition/audit record | RA-146 — FG01 independent factory-contract review (2026-10-23) | CHANGELOG; tracker |
| `Architecture_M6_CP3_DEFN_ISO_A_Seam_Node_Representative_Census_20261021.md` | 49 | Review/definition/audit record | RA-123.7 — DEFN-ISO-A seam-node representative census (2026-10-21) | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_DEFN_Legacy_Matching_Path_Disposition_20261026.md` | 43 | Review/definition/audit record | M6-CP3 DEFN — legacy matching-path disposition (2026-10-26) | CHANGELOG; tracker; retained Review records |
| `Architecture_M6_CP3_DEFN_M1_Certificate_Pair_Binding_Precedence_Plan_20261023.md` | 12 | consumed plan | DEFN-M1 — certificate-pair binding validation precedence (2026-10-23) | consumed plan; executed definition retained in `Architecture_M6_CP3_DEFN_M1_Certificate_Pair_Binding_Precedence_20261023.md` and its Review decision |
| `Architecture_M6_CP3_DEFN_P13_A3_Chain_Scheduling_Identity_Migration_WIP_20261109.md` | 48 | working record | Mandatory-chain A3 identity and consumer migration — source-derived D5 Review WIP | superseded D5 WIP; verdict and carried facts in retained RA-218 `Architecture_M6_CP3_DEFN_P13_A3_Mandatory_Chain_Scheduling_Takeover_Review_20261109.md` §1 |
| `Architecture_M6_CP3_DEFN_P13_A3_Mandatory_Chain_Coverage_Patch_WIP_20261109.md` | 49 | working record | Mandatory original-arc coverage precondition — local source/test patch WIP | superseded D5 WIP; verdict and carried facts in retained RA-218 `Architecture_M6_CP3_DEFN_P13_A3_Mandatory_Chain_Scheduling_Takeover_Review_20261109.md` §1 |
| `Architecture_M6_CP3_DEFN_P13_A3_Mandatory_Chain_Cut_Closed_Rail_Proof_WIP_20261109.md` | 48 | working record | D5: a closed rail cut by A2b Trace terminals can yield open Mandatory chains | superseded D5 WIP; verdict and carried facts in retained RA-218 `Architecture_M6_CP3_DEFN_P13_A3_Mandatory_Chain_Scheduling_Takeover_Review_20261109.md` §1 |
| `Architecture_M6_CP3_DEFN_P13_A3_Mandatory_Chain_Evidence_Recovery_20261109.md` | 45 | Review/definition/audit record | D5 production-incidence evidence recovery — runtime-free Review finding (2026-11-09) | superseded D5 WIP; verdict and carried facts in retained RA-218 `Architecture_M6_CP3_DEFN_P13_A3_Mandatory_Chain_Scheduling_Takeover_Review_20261109.md` §1 |
| `Architecture_M6_CP3_DEFN_P13_A3_Mandatory_Chain_Existing_Fixture_Preflight_20261109.md` | 46 | working record | D5 prospective non-vacuous positive fixture — static source preflight (2026-11-09) | superseded D5 WIP; verdict and carried facts in retained RA-218 `Architecture_M6_CP3_DEFN_P13_A3_Mandatory_Chain_Scheduling_Takeover_Review_20261109.md` §1 |
| `Architecture_M6_CP3_DEFN_P13_A3_Mandatory_Chain_Incidence_Proof_Gates_20261109.md` | 46 | Review/definition/audit record | D5 mandatory-chain scheduling: exact incidence proof gate | superseded D5 WIP; verdict and carried facts in retained RA-218 `Architecture_M6_CP3_DEFN_P13_A3_Mandatory_Chain_Scheduling_Takeover_Review_20261109.md` §1 |
| `Architecture_M6_CP3_DEFN_P13_A3_Mandatory_Chain_Independent_TB_Contract_WIP_20261109.md` | 51 | working record | D5 independent retained-partition TB contract — Review WIP (2026-11-09) | superseded D5 WIP; verdict and carried facts in retained RA-218 `Architecture_M6_CP3_DEFN_P13_A3_Mandatory_Chain_Scheduling_Takeover_Review_20261109.md` §1 |
| `Architecture_M6_CP3_DEFN_P13_A3_Mandatory_Chain_Protected_Corner_Binding_WIP_20261109.md` | 43 | working record | D5 mandatory-chain protected-corner and retention binding — source-derived WIP | superseded D5 WIP; verdict and carried facts in retained RA-218 `Architecture_M6_CP3_DEFN_P13_A3_Mandatory_Chain_Scheduling_Takeover_Review_20261109.md` §1 |
| `Architecture_M6_CP3_DEFN_P13_A3_Mandatory_Chain_Retained_Product_Seam_WIP_20261109.md` | 46 | working record | Mandatory-arc chain product: retained producer/validator seam (D5 WIP, 2026-11-09) | superseded D5 WIP; verdict and carried facts in retained RA-218 `Architecture_M6_CP3_DEFN_P13_A3_Mandatory_Chain_Scheduling_Takeover_Review_20261109.md` §1 |
| `Architecture_M6_CP3_DEFN_P13_A3_Mandatory_Chain_Scheduling_Review_WIP_20261109.md` | 72 | working record | Mandatory boundary-chain scheduling — D5 Review/Definition WIP (2026-11-09) | superseded D5 WIP; verdict and carried facts in retained RA-218 `Architecture_M6_CP3_DEFN_P13_A3_Mandatory_Chain_Scheduling_Takeover_Review_20261109.md` §1 |
| `Architecture_M6_CP3_DEFN_P13_A3_Mandatory_Chain_Side_Walk_Oracle_WIP_20261109.md` | 44 | working record | D5 mandatory-chain side-walk proof — source-derived Review WIP | superseded D5 WIP; verdict and carried facts in retained RA-218 `Architecture_M6_CP3_DEFN_P13_A3_Mandatory_Chain_Scheduling_Takeover_Review_20261109.md` §1 |
| `Architecture_M6_CP3_DEFN_P13_A3_Recorded_Boundary_Intervals_Review_20261108.md` | 87 | Review/definition/audit record | M6-CP3 step 61 — Recorded A3 source-boundary intervals (runtime-free Review, final decision) | CHANGELOG; tracker; TODO; handoff; retained Review records |
| `Architecture_M6_CP3_DEFN_P13_A4_A2b_Disc_Producer_Review_WIP_20261108.md` | 43 | working record | A4 per-A2b-disc review — unfinished source-backed memo (2026-11-08) | handoff; retained Review records |
| `Architecture_M6_CP3_DEFN_P13_A4_A2b_Exact_Support_Export_Execution_Authority_Review_20261108.md` | 41 | Test + Benchmark record/plan | M6-CP3 P13 A4/A2b — exact source-support export correction and Review execution gate (2026-11-08) | retained Review records |
| `Architecture_M6_CP3_DEFN_P13_A4_A2b_Source_Attached_Surrogate_Review_20261108.md` | 54 | Review/definition/audit record | A4/A2b Review — Source-attached Vase quad geometry and surrogate-disc ownership probe | superseded working review; adjudicated by retained RA-213 `Architecture_M6_CP3_DEFN_P13_Vase_Producer_Path_Adversarial_Review_A2b_Disc_Construction_20261108.md` |
| `Architecture_M6_CP3_DEFN_P13_Arrangement_Sliver_Cells_Review_WIP_20261102.md` | 97 | working record | P13 arrangement sliver cells — canonical Review WIP (2026-11-02) | TODO; retained Review records |
| `Architecture_M6_CP3_DEFN_P13_Assembler_Typed_Intersection_Adjudication_20261103.md` | 43 | Review/definition/audit record | P13-j: typed authority intersection is an independent assembly gate (2026-11-03) | tracker |
| `Architecture_M6_CP3_DEFN_P13_Assembly_Ring_Nonvacuity_20261103.md` | 39 | Review/definition/audit record | P13-j four-cell ring non-vacuity (same Review, 2026-11-03) | CHANGELOG; tracker |
| `Architecture_M6_CP3_DEFN_P13_Completed_Mesh_Orientation_Review_WIP_20261105.md` | 93 | working record | P13-l: completed-mesh orientation — independent Review WIP | TODO; handoff; retained Review records |
| `Architecture_M6_CP3_DEFN_P13_Completed_Mesh_Stitch_Overlap_Review_WIP_20261106.md` | 154 | working record | Completed mesh stitch and overlap — independent review WIP (2026-11-06) | handoff; retained Review records |
| `Architecture_M6_CP3_DEFN_P13_Completion_Grid_Embedding_Review_WIP_20261102.md` | 41 | working record | P13-h / P13-i grid-embedding definition — in-progress independent review (2026-11-02) | TODO; retained Review records |
| `Architecture_M6_CP3_DEFN_P13_Completion_Ownership_Cost_Review_Decision_20261101.md` | 54 | Review/definition/audit record | P13-f completion source-chart ownership-cost Review / Definition — 2026-11-01 | CHANGELOG; tracker; TODO; retained Review records |
| `Architecture_M6_CP3_DEFN_P13_Completion_Quad_Embedding_Review_Decision_20261101.md` | 50 | Review/definition/audit record | P13-g — bounded completion quad embedding: independent definition and corrective boundary (2026-11-01) | CHANGELOG; tracker; TODO; retained Review records |
| `Architecture_M6_CP3_DEFN_P13_Design_Acceptance_Decision_20261031.md` | 66 | Review/definition/audit record | P13 — independent design-acceptance review and runtime-probe separation (2026-10-31) | CHANGELOG; TODO; retained Review records |
| `Architecture_M6_CP3_DEFN_P13_FlowRep_Selection_Invariants_Review_20261102.md` | 35 | Review/definition/audit record | P13 FlowRep selected-network invariants — independent static Review (2026-11-02) | retained Review records |
| `Architecture_M6_CP3_DEFN_P13_FlowRep_Selection_Probe_Preflight_20261102.md` | 55 | working record | P13 FlowRep selection — source-verified probe preflight (2026-11-02) | TODO; retained Review records |
| `Architecture_M6_CP3_DEFN_P13_O15C_Continuation_Width_Review_20261031.md` | 69 | working record | RA-189 — bounded A4 continuation and Cylinder gate membership (2026-10-31) | CHANGELOG; TODO |
| `Architecture_M6_CP3_DEFN_P13_Platform_Split_Digest_Adjudication_20261105.md` | 66 | Review/definition/audit record | O30 Review/Definition — first cross-platform divergence adjudication (2026-11-05) | CHANGELOG; tracker; TODO; handoff; retained Review records |
| `Architecture_M6_CP3_DEFN_P13_PreStitch_Vector_ABI_Probe_Review_20261106.md` | 73 | Review/definition/audit record | P13-l2 pre-stitch vector ABI: same-turn Review evidence (2026-11-06) | tracker; TODO; handoff; retained Review records |
| `Architecture_M6_CP3_DEFN_P13_Representation_Breakpoint_Prototype_FALSIFIED.diff` | 256 | exact patch (applied or superseded; landed source is in git history) | 5 files, +160 −11 | TODO; retained Review records |
| `Architecture_M6_CP3_DEFN_P13_Row_Permutation_Seeds_WIP_20261105.md` | 118 | working record | O32a source-row permutation seed Review — work preservation (IN PROGRESS) | retained Review records |
| `Architecture_M6_CP3_DEFN_P13_Side_Subdivision_Quality_Review_WIP_20261108.md` | 47 | working record | P13-n Side-Subdivision Quality — Review WIP (2026-11-08) | handoff; retained Review records |
| `Architecture_M6_CP3_DEFN_P13_Stitch_Overlap_Geometric_Predicate_Review_20261106.md` | 99 | Review/definition/audit record | P13-l2 — post-CB96 geometric-predicate review (scratch evidence, 2026-11-06) | tracker; handoff |
| `Architecture_M6_CP3_DEFN_P13_Stitch_Owner_Cache_Preflight_20261103.md` | 51 | working record | P13-j stitched-boundary owner and reuse preflight — 2026-11-03 | CHANGELOG; tracker |
| `Architecture_M6_CP3_DEFN_P13_Vase_Completion_Incidence_Review_Decision_20261101.md` | 62 | Review/definition/audit record | P13-d / O18 — Vase completion incidence Review/Definition (2026-11-01) | CHANGELOG; tracker; TODO; retained Review records |
| `Architecture_M6_CP3_DEFN_P13_Vase_Phase_Front_Producer_Path_Review_20261108.md` | 95 | Review/definition/audit record | Vase A4 phase-front producer path — independent Review (2026-11-08) | CHANGELOG; tracker; TODO; handoff; retained Review records |
| `Architecture_M6_CP3_DEFN_RP01_Off_Selector_Coverage_Disposition_20261030.md` | 110 | Review/definition/audit record | RA-172 — Off-selector coverage disposition; TB51 gate frozen (2026-10-30) | CHANGELOG; tracker |
| `Architecture_M6_CP3_DEFN_RP01_Terminal_Path_Witnesses_TB52_REV_Audit_20261030.md` | 316 | Review/definition/audit record | RA-178 — TB52-REV audit and RP-01 terminal-path witness definition (2026-10-30) | CHANGELOG; tracker |
| `Architecture_M6_CP3_DEFN_Selector242_Cross_Region_Seam_Consumer_Decision_20261026.md` | 30 | Review/definition/audit record | M6-CP3 DEFN — selector242 source-adjacent isolation seam consumer (2026-10-26) | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_DEFN_TB46_Endpoint_Cluster_Review_Decision_20261027.md` | 59 | Review/definition/audit record | DEFN-E — TB46 endpoint cluster independent review and CB47 authorization (2026-10-27) | CHANGELOG; tracker |
| `Architecture_M6_CP3_DEFN_TB47_Gauge_Cluster_Independent_Review_20261027.md` | 591 | Review/definition/audit record | TB47 gauge-cluster independent review — INCOMPLETE (2026-10-27) | CHANGELOG; tracker |
| `Architecture_M6_CP3_DEFN_TB47_R52_Compiled_Unselected_Cases_Evidence.md` | 31 | Code + Build record/plan | TB47 same-turn R52 — compiled but unselected hard-rail controls (2026-10-28) | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_DEFN_TB47_R53_Torus_Cut_Gauge_Coboundary_Review_20261028.md` | 49 | Review/definition/audit record | TB47 same-turn R53 — torus face-gauge cut-domain preflight (2026-10-28) | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_DEFN_TB47_R54_Torus_Hard_Carrier_Relabel_Eligibility_Review_20261028.md` | 46 | Review/definition/audit record | TB47 same-turn R54 — torus hard-carrier survival under one-face cyclic arm relabel | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_DEFN_TB47_R58_Corrective_Gate_Decision_Matrix_20261028.md` | 26 | Review/definition/audit record | TB47 — independent review R58: corrective gate matrix | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_DEFN_TB47_R60_Frozen_Manifest_And_Ledger_Checker_Review_20261028.md` | 24 | Review/definition/audit record | TB47 same-turn R60 — frozen-case manifest and full-DAG ledger checker preview (2026-10-28) | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_DEFN_TB47_R61_Selector_Discovery_And_Review_Control_Audit_20261028.md` | 56 | Review/definition/audit record | TB47 same-turn R61 — selector discovery and review-control boundary audit (2026-10-28) | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_DEFN_U6A_I_Endpoint_Exact_Origin_Trace_20261018.md` | 38 | Review/definition/audit record | M6 CP3 DEFN-U6A — exact open-rail I-endpoint origin trace (2026-10-18) | retained Review records |
| `Architecture_M6_CP3_PLAN_A3_Atlas_Exactness_TB52C_REV_Audit_20261030.md` | 59 | Review/definition/audit record | RA-176 — TB52C-REV audit and A3 atlas exactness (O15) (2026-10-30) | CHANGELOG; tracker |
| `Architecture_M6_CP3_PLAN_RP01_Closure_TB51_REV_Audit_Membership_Harness_20261030.md` | 350 | Review/definition/audit record | RA-174 — TB51-REV audit; RP-01 closure plan; gate membership harness P8 (2026-10-30) | CHANGELOG; tracker |
| `Architecture_M6_CP3_R10A_Rail_Interior_Vertex_Witness_Census_20261017.md` | 42 | Review/definition/audit record | R10A — rail-interior-vertex witness census (facts only) | CHANGELOG |
| `Architecture_M6_CP3_R10B_Rail_Interior_Vertex_Endpoint_Rule_20261017.md` | 67 | Review/definition/audit record | R10B — open-rail interior-vertex endpoint admission rule (Definition) | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R2P1_Wedge_Certificate_Binding_Resolution_Record.md` | 120 | Review/definition/audit record | M6-CP3 R2-P1 — oriented wedge-to-isolation-certificate binding: architectural resolution | CHANGELOG |
| `Architecture_M6_CP3_R2P3_MultiEdge_HardRail_Transport_Review_Request.md` | 44 | Review/definition/audit record | M6-CP3 R2-P3 — Producer-owned multi-edge HardRail τ Review request (non-normative) | CHANGELOG |
| `Architecture_M6_CP3_R3_089_Exact_Source_Static_Census_20261010.md` | 44 | Review/definition/audit record | Directional R3 — exact-source compile and 497-identity static census | CHANGELOG |
| `Architecture_M6_CP3_R3_14_Organic_Downstream_R2_Static_Provenance_20261009.md` | 81 | Review/definition/audit record | Directional M6-CP3-CB1-ENTRY-R3 — source-only audit of 14 historical organic/downstream R2 failures | CHANGELOG |
| `Architecture_M6_CP3_R3_39_First_Failure_Compiled_Diagnostic_Coverage_20261009.md` | 48 | Code + Build record/plan | M6-CP3-CB1-ENTRY-R3 — compiled first-failure evidence and independent review gate | CHANGELOG |
| `Architecture_M6_CP3_R3_A3_Balanced_Attestation_Review_Request.md` | 57 | Review/definition/audit record | Directional R3 — A3 balanced-transport attestation decision request | CHANGELOG |
| `Architecture_M6_CP3_R3_A3_Factory_Callsite_Migration_Impact_20261010.md` | 47 | Review/definition/audit record | Directional — R3 A3 factory attestation: exact-source call-site and authority migration impact | CHANGELOG |
| `Architecture_M6_CP3_R3_A3_Trust_CB_TB_Gate_Review_Request.md` | 85 | Review/definition/audit record | CURRENT evidence authority — 2026-10-10T00:54Z (NOT an independent verdict) | retained Review records |
| `Architecture_M6_CP3_R3_Frozen_497_Supplemental_Test_Coverage_Audit.md` | 55 | Review/definition/audit record | Latest source static recheck — 2026-10-09T21:48Z (C still needs Review) | CHANGELOG |
| `Architecture_M6_CP3_R3_Nonrail_Factory_Star_Static_Audit_20261009.md` | 23 | Review/definition/audit record | R3 — checked factory nonrail star-manifoldness static audit (2026-10-09) | CHANGELOG |
| `Architecture_M6_CP3_R3_R2_Direct_A4_25_First_Locus_Triage.md` | 54 | Review/definition/audit record | R3: R2 direct-A4 25-case first-observable-locus triage (static; not runtime R3 evidence) | CHANGELOG |
| `Architecture_M6_CP3_R3_Verified_Compile_and_CP3_Evidence_Reconciliation_20261009.md` | 39 | Code + Build record/plan | Directional M6-CP3-CB1-ENTRY-R3 — verified current-source reconciliation and CP3 runtime evidence matrix | CHANGELOG |
| `Architecture_M6_CP3_R4_A2b_Endpoint_First_Predicate_Code_Build_Record_20261011.md` | 22 | Code + Build record/plan | M6-CP3-CB1-ENTRY-R4 — actual source-owned A2b terminal rejection predicate (2026-10-11) | CHANGELOG |
| `Architecture_M6_CP3_R4_A2b_Raw_Barycentric_Diagnostic_Code_Build_Record_20261011.md` | 21 | Code + Build record/plan | R4 source-owned A2b rejected endpoint barycentric observability — Code + Build record (2026-10-11) | CHANGELOG |
| `Architecture_M6_CP3_R4_A2b_Terminal_Contact_Negative_Code_Build_Record_20261011.md` | 17 | Code + Build record/plan | R4 A2b missing/foreign terminal contact factory negatives — Code + Build record (2026-10-11) | CHANGELOG |
| `Architecture_M6_CP3_R4_A5_Reachable_Lattice_Branch_Negative_Code_Build_Record.md` | 18 | Code + Build record/plan | M6-CP3-CB1-ENTRY-R4 — A5-reachable lattice-only hard-rail negative (Code + Build) | CHANGELOG |
| `Architecture_M6_CP3_R4_Absolute_Gauge_Producer_Compatibility_Stop_Record.md` | 29 | Review/definition/audit record | M6-CP3-CB1-ENTRY-R4 — RA-44.2 geometric gauge producer-compatibility STOP | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_Boundary_Class_Source_Incidence_20261014.md` | 24 | Review/definition/audit record | M6 CP3 R4 — source-boundary class incidence (2026-10-14) | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_Canonical_Source_Rail_Uniqueness_20261014.md` | 23 | Review/definition/audit record | M6-CP3-CB1-ENTRY-R4 — canonical source-rail edge uniqueness (2026-10-14) | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_Carried_39_Endpoint_Fingerprint_Source_Star_Triage_20261011.md` | 46 | Review/definition/audit record | M6-CP3-CB1-ENTRY-R4 — 39 historical carried endpoint failures: fingerprint and source-star triage | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_Closed_Curve_Source_Claim_Code_Build_20261014.md` | 21 | Code + Build record/plan | M6-CP3-CB1-ENTRY-R4 — closed feature-curve source-claim guard (2026-10-14 UTC) | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_Closed_Rail_Component_Code_Build_Record_20261014.md` | 27 | Code + Build record/plan | M6-CP3-CB1-ENTRY-R4 — closed-rail source-component first-consumer guard | CHANGELOG |
| `Architecture_M6_CP3_R4_Closed_Rail_Provenance_Producer_Guard_Code_Build_Record_20261011.md` | 25 | Code + Build record/plan | M6-CP3-CB1-ENTRY-R4 — distinguish absent open-rail contact from closed-chain authority (2026-10-11) | CHANGELOG |
| `Architecture_M6_CP3_R4_Closed_Rail_Wraparound_Index_Oracle_Code_Build_Record_20261012.md` | 10 | Code + Build record/plan | M6-CP3-CB1-ENTRY-R4 — closed hard/boundary rail wraparound raw-index oracle (Code + Build) | CHANGELOG |
| `Architecture_M6_CP3_R4_Composite_Bounded_Reject_A3_Code_Build_Record_20261012.md` | 21 | Code + Build record/plan | R4 composite periodic/bounded-disk source-A3 ingress — Code + Build evidence (2026-10-12) | CHANGELOG |
| `Architecture_M6_CP3_R4_Curve_Edge_Uniqueness_Code_Build_20261014.md` | 19 | Code + Build record/plan | M6-CP3-CB1-ENTRY-R4 — unique curve-edge source ownership (2026-10-14) | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_Curved_Disk_Full_A4_Factory_Negatives_Code_Build_Record.md` | 19 | Code + Build record/plan | M6-CP3 R4 — Curved-disk full-authority A4 bounded-disk negatives | CHANGELOG |
| `Architecture_M6_CP3_R4_D2_A2b_Endpoint_Regression_Code_Build_Record.md` | 12 | Code + Build record/plan | M6-CP3-CB1-ENTRY-R4 — D2 multi-carrier terminal A2b ingress correction | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_D2_Attached_Tau_Witness_Code_Build_Record.md` | 22 | Code + Build record/plan | M6-CP3-CB1-ENTRY-R4 — D2 odd-carrier versus complete A2b attached transport | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_D2_Terminal_A3_Attestation_Code_Build_Record.md` | 10 | Code + Build record/plan | M6-CP3-CB1-ENTRY-R4 — terminal A2b/A3 typed source-row transport attestation | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_Duplicate_Curve_Owner_Guard_20261014.md` | 33 | Review/definition/audit record | R4 duplicate feature curve-owner guard — Code + Build evidence (2026-10-14) | CHANGELOG |
| `Architecture_M6_CP3_R4_Durable_Handoff_Transport_Recovery_20261012.md` | 22 | Review/definition/audit record | M6-CP3-CB1-ENTRY-R4 — 2026-10-12 bounded continuation recovery | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_Eigen_Mirror_Compile_Record_20261011.md` | 25 | Code + Build record/plan | R4 Eigen mirror dependency blocker remediation (2026-10-11) | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_Endpoint39_Census_Artifact_Only_TB_Report_20261015.md` | 45 | Test + Benchmark record/plan | M6-CP3-TB1-R4-ENDPOINT39-CENSUS — artifact-only execution report | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_Endpoint39_Census_Measured_Identities_20261015.tsv` | 40 | per-turn data/receipt | 39 data rows | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_Endpoint_Authority_Specification_20261015.md` | 61 | Review/definition/audit record | Endpoint authority specification — hard-rail front sides | retained Review records |
| `Architecture_M6_CP3_R4_Endpoint_Chart_Harvest_Artifact_Only_TB_Report_20261015.md` | 45 | Test + Benchmark record/plan | Endpoint-chart probe — immutable artifact-only Test + Benchmark harvest | CHANGELOG |
| `Architecture_M6_CP3_R4_Endpoint_Chart_Probe_Code_Build_Record_20261015.md` | 32 | Code + Build record/plan | Endpoint chart diagnostic — Code + Build record | retained Review records |
| `Architecture_M6_CP3_R4_Endpoint_Failure_Probe_Code_Build_Record_20261011.md` | 16 | Code + Build record/plan | M6-CP3-CB1-ENTRY-R4 — rejected hard-rail A2b terminal diagnostic (2026-10-11) | CHANGELOG |
| `Architecture_M6_CP3_R4_Factory_Unique_Compile_Closeout.md` | 12 | Code + Build record/plan | M6-CP3-CB1-ENTRY-R4 — factory terminal-star uniqueness compile-only closeout | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_False_Open_Curve_Source_Claim_Code_Build_20261014.md` | 21 | Code + Build record/plan | M6-CP3-CB1-ENTRY-R4 — symmetric source-curve closure authority (2026-10-14) | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_Feature_Curve_Edge_Owner_Consistency_20261014.md` | 34 | Review/definition/audit record | M6-CP3-CB1-ENTRY-R4 — feature-curve-to-rail source owner integrity (2026-10-14) | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_Feature_Edge_Incidence_Provenance_20261014.md` | 33 | Review/definition/audit record | M6 CP3 R4 — Exact source-edge incident-face provenance (2026-10-14) | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_Feature_Rail_Source_Component_Provenance_20261014.md` | 28 | Review/definition/audit record | M6-CP3-CB1-ENTRY-R4 — Source-connected component binding for feature rails (2026-10-14) | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_FieldTransportAtlas_Validation_Seam_Comment_Review_20261014.md` | 14 | Review/definition/audit record | R4 atlas source-validation comment review — 2026-10-14 UTC | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_Five_Periodic_Route_Source_A3_Ingress_Code_Build_Record.md` | 19 | Code + Build record/plan | M6-CP3-CB1-ENTRY-R4 — five periodic route source-owned A3 fixture candidates | CHANGELOG |
| `Architecture_M6_CP3_R4_FlowRep_Singularity_TwoFace_Source_Fixture_Code_Build_Record_20261011.md` | 20 | Code + Build record/plan | M6-CP3-CB1-ENTRY-R4 — FlowRep singularity-support source/DCEL fixture correction (Code + Build) | CHANGELOG |
| `Architecture_M6_CP3_R4_Four_Phase10_A3_Atlas_Ingress_Code_Build_Record.md` | 28 | Code + Build record/plan | M6-CP3-CB1-ENTRY-R4 — four Phase10 source-A3 fixture ingress corrections (2026-10-11) | CHANGELOG |
| `Architecture_M6_CP3_R4_Four_Positive_A3_Atlas_Ingress_Code_Build_Record_20261011.md` | 18 | Code + Build record/plan | M6-CP3-CB1-ENTRY-R4 — four Phase10 original-source A3 positive ingress corrections (2026-10-11) | CHANGELOG |
| `Architecture_M6_CP3_R4_Full_A4_Region_Reference_Negatives_Code_Build_Record.md` | 20 | Code + Build record/plan | M6 CP3 R4 — complete A4 source authority for region-reference negatives (Code + Build) | CHANGELOG |
| `Architecture_M6_CP3_R4_Full_PhaseFront_Draft_A3_Oracle_Code_Build_Record.md` | 22 | Code + Build record/plan | M6-CP3-CB1-ENTRY-R4 — complete PhaseFrontDraft factory authority and A3 rejection oracle | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_HardRail_Incidence_Open_Contact_Code_Build_Record_20261011.md` | 22 | Code + Build record/plan | M6-CP3-CB1-ENTRY-R4 — supplemental hard-rail incidence contact preflight (2026-10-11) | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_Historical_R3_A4_39_Current_Source_Inventory_20261013.md` | 38 | Review/definition/audit record | M6-CP3-CB1-ENTRY-R4 — R3 A4 route-rejection identity-to-source inventory | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_Historical_Target_Compile_Coverage_Audit_20261012.md` | 10 | Code + Build record/plan | M6-CP3-CB1-ENTRY-R4 — historical-target compile-coverage audit (2026-10-12) | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_Incidence_A3_Positive_Control_Nonvacuity_Code_Build_Record_20261011.md` | 21 | Code + Build record/plan | M6-CP3-CB1-ENTRY-R4 — supplemental hard-rail A3 positive-control non-vacuity (Code + Build) | CHANGELOG |
| `Architecture_M6_CP3_R4_Interior_Witness_Artifact_Only_TB_Report_20261015.md` | 24 | Test + Benchmark record/plan | R4 interior carrier witness — immutable artifact-only TB report (2026-10-15) | CHANGELOG |
| `Architecture_M6_CP3_R4_Ledger_Content_Floor_20261015.md` | 9 | Review/definition/audit record | R4 durable ledger content-floor correction (2026-10-15) | CHANGELOG |
| `Architecture_M6_CP3_R4_Nonrail_Curve_Source_Authority_20261014.md` | 24 | Review/definition/audit record | M6 CP3 R4 — non-rail feature-curve source authority (2026-10-14) | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_OHF01_Overfull_Hard_Feature_Reachability_Probe_20261015.md` | 25 | Review/definition/audit record | M6-CP3-CB1-R4-OHF01-PROBE — source-only overfull hard-feature incidence reachability | CHANGELOG |
| `Architecture_M6_CP3_R4_Open_Rail_Component_First_A4_Consumer_20261014.md` | 23 | Review/definition/audit record | M6-CP3-CB1-ENTRY-R4 — open-rail first A4 component authority (2026-10-14 UTC) | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_Orphan_Curve_Membership_Source_Guard_20261014.md` | 35 | Review/definition/audit record | R4 orphan curve-membership guard — Code + Build record (2026-10-14) | CHANGELOG |
| `Architecture_M6_CP3_R4_Overfull_A3_Feasibility_Review_Request_20261012.md` | 35 | Review/definition/audit record | M6-CP3-CB1-ENTRY-R4 — overfull hard-rail/A3 feasibility: independent Review request | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_Overfull_Rail_Incidence_Code_Build_20261014.md` | 19 | Code + Build record/plan | M6-CP3-CB1-ENTRY-R4 — overfull authoritative rail source incidence (2026-10-14) | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_Periodic_192_Chart_199_A3_Ingress_Code_Build_Record.md` | 21 | Code + Build record/plan | M6-CP3-CB1-ENTRY-R4 — periodic negative / chart-zero source A3 ingress (compile-only) | CHANGELOG |
| `Architecture_M6_CP3_R4_Periodic_247_Original_Source_A3_Ingress_Code_Build_Record.md` | 21 | Code + Build record/plan | M6-CP3-CB1-ENTRY-R4 — malformed periodic cylinder original-source A3 ingress (compile-only) | CHANGELOG |
| `Architecture_M6_CP3_R4_Periodic_Crossing_A3_Source_Authority_Code_Build_Record_20261011.md` | 23 | Code + Build record/plan | M6-CP3-CB1-ENTRY-R4 — Periodic crossing source-A3 negative preflight | CHANGELOG |
| `Architecture_M6_CP3_R4_Phase10_R3_RED_Source_Atlas_Static_Census_20261011.md` | 26 | Review/definition/audit record | M6-CP3-CB1-ENTRY-R4 — frozen R3 RED Phase10 ingress census (static, 2026-10-11) | CHANGELOG |
| `Architecture_M6_CP3_R4_Phase10_Source_Atlas_Fixture_Recovery_Code_Build_Record.md` | 20 | Code + Build record/plan | M6-CP3-CB1-ENTRY-R4 — Phase10 source-owned A2/A3 fixture recovery (Code + Build) | CHANGELOG |
| `Architecture_M6_CP3_R4_Phase10_Three_RowOrder_Source_Atlas_Code_Build_Record.md` | 17 | Code + Build record/plan | M6-CP3-CB1-ENTRY-R4 — Three Phase10 row-order A2/A3 test-source migrations | CHANGELOG |
| `Architecture_M6_CP3_R4_Phase14_First_Rejection_Typed_Rail_Code_Build_Record_20261012.md` | 32 | Code + Build record/plan | M6-CP3-CB1-ENTRY-R4 — Phase14 typed-rail negative first-rejection incremental Code + Build (2026-10-12) | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_Phase14_Foreign_Local_Edge_Oracle_Code_Build_Record_20261012.md` | 17 | Code + Build record/plan | M6-CP3-CB1-ENTRY-R4 — Phase14 valid foreign local edge typed-rail negative | CHANGELOG |
| `Architecture_M6_CP3_R4_Phase14_Incident_Barrier_Typed_Rail_Code_Build_Record_20261012.md` | 11 | Code + Build record/plan | M6-CP3-CB1-ENTRY-R4 — Phase14 incident-order and barrier rail fixtures (2026-10-12) | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_Phase14_Positive_Rail_Source_Vertex_Migration_Code_Build_Record_20261012.md` | 31 | Code + Build record/plan | M6-CP3-CB1-ENTRY-R4 — Phase14 remaining positive rail source-vertex migration | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_Phase14_Typed_Rail_Fixture_Code_Build_Record_20261012.md` | 30 | Code + Build record/plan | M6-CP3-CB1-ENTRY-R4 — Phase14 typed valid-rail fixture (incremental) | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_Producer_Rail_Chain_Oracle_Code_Build_Record_20261012.md` | 20 | Code + Build record/plan | M6-CP3-CB1-ENTRY-R4 — source-exact producer rail chain oracle, compile-only (2026-10-12) | CHANGELOG |
| `Architecture_M6_CP3_R4_Producer_Raw_Edge_Index_Positive_Code_Build_Record_20261012.md` | 12 | Code + Build record/plan | M6-CP3-CB1-ENTRY-R4 — produced raw rail source-edge index positive oracle | CHANGELOG |
| `Architecture_M6_CP3_R4_Public_Trace_Foreign_Edge_Oracle_Compile_Record_20261013.md` | 19 | Code + Build record/plan | M6-CP3-CB1-ENTRY-R4 — public strict trace foreign-edge oracle Code + Build receipt | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_Public_Trace_Foreign_Edge_Oracle_Transport_Handoff_20261013.md` | 18 | Review/definition/audit record | M6-CP3-CB1-ENTRY-R4 — public strict trace foreign-edge oracle transport handoff (2026-10-13 UTC) | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_RA431_A1_A4_Branch_Coupling_Census_20261014.md` | 49 | Review/definition/audit record | M6-CP3-CB1-ENTRY-R4 — RA-43.1 A1/A4 produced-branch coupling census (2026-10-14 UTC) | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_RA431_Admissible_Transit_Compile_Record_20261013.md` | 18 | Code + Build record/plan | M6-CP3-CB1-ENTRY-R4 — RA-43.1 complete admissible transit source oracle (2026-10-13) | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_RA431_Borrowed_Barrier_Differential_Oracle_20261013.md` | 13 | Review/definition/audit record | M6-CP3-CB1-ENTRY-R4 — RA-43.1 borrowed barrier differential (2026-10-13) | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_RA431_Certified_Hard_Carrier_Cut_Code_Build_Record_20261012.md` | 11 | Code + Build record/plan | M6-CP3-CB1-ENTRY-R4 — RA-43.1 certified hard-carrier cut (2026-10-12) | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_RA431_Directed_Seam_Row_Permutation_20261014.md` | 18 | Review/definition/audit record | R4 RA-43.1 / RA-51 — A1 directed seam identity under face-row permutation | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_RA431_Nonhard_Produced_Directed_A3_Code_Build_Record_20261014.md` | 24 | Code + Build record/plan | R4 RA-43.1 — produced nonhard A3 directed-transition parity (2026-10-14 UTC) | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_RA431_Organic_Producer_Vertex_Germ_Code_Build_20261014.md` | 27 | Code + Build record/plan | R4 RA-43.1 — genuine multi-carrier A1 vertex-germ source oracle (2026-10-14 UTC) | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_RA431_Paired_Endpoint_Germ_Seed_Source_Oracle_20261014.md` | 30 | Review/definition/audit record | R4 RA-43.1 / D2 — paired terminal identities and A1 germ seed (2026-10-14 UTC) | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_RA431_Produced_Hard_Barrier_Authority_Oracle_20261013.md` | 63 | Review/definition/audit record | M6-CP3-CB1-ENTRY-R4 — RA-43.1 producer-classified hard carrier oracle (2026-10-13) | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_RA431_Produced_OddTau_Multicarrier_Germ_20261014.md` | 67 | Review/definition/audit record | R4 — A1 admitted producer-germ fan, barrier and directed branch lift independently authenticated (2026-10-14 06:57Z) | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_RA431_Producer_Directed_A3_Code_Build_Record_20261014.md` | 17 | Code + Build record/plan | R4 RA-43.1 — producer-backed hard-carrier directed A3 values | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_RA431_Production_Vertex_Star_Callsite_Census_20261014.md` | 27 | Review/definition/audit record | M6-CP3-CB1-ENTRY-R4 — RA-43.1 production vertex-star barrier wiring, source-only (2026-10-14) | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_RA432_Open_Terminal_Contact_First_Rejection_Code_Build_Record_20261012.md` | 23 | Code + Build record/plan | M6-CP3-CB1-ENTRY-R4 — RA-43.2 open-rail terminal provenance first-rejection regression | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_RA432_Terminal_Attachment_Source_Audit_20261012.md` | 17 | Review/definition/audit record | M6-CP3-CB1-ENTRY-R4 — RA-43.2 terminal-attachment source audit (2026-10-12) | retained Review records |
| `Architecture_M6_CP3_R4_RA434_Consumer_Foreign_Edge_Key_Regression_20261013.md` | 30 | Review/definition/audit record | R4 RA-43.4 — independent network-bound consumer foreign-edge-key regression | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_RA434_Default_Strict_Source_Vertex_Contract_20261012.md` | 21 | Review/definition/audit record | M6-CP3-CB1-ENTRY-R4 — RA-43.4 strict default for typed rail incidence | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_RA434_Explicit_Standalone_Diagnostic_Optout_Code_Build_Record_20261013.md` | 50 | Code + Build record/plan | M6-CP3-CB1-ENTRY-R4 — RA-43.4 typed diagnostic opt-out hardening | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_RA434_Malformed_Rail_Fixture_Migration_20261012.md` | 23 | Review/definition/audit record | M6-CP3-CB1-ENTRY-R4 — RA-43.4 strict malformed-interval test fixture migration | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_RA434_Network_Atlas_Provenance_20261014.md` | 39 | Review/definition/audit record | M6-CP3-CB1-ENTRY-R4 — A2a/A3 network/atlas provenance first-ingress code+build record (2026-10-14) | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_RA434_Network_Bound_Typed_Rail_Edge_Key_Code_Build_Record_20261013.md` | 25 | Code + Build record/plan | M6-CP3-CB1-ENTRY-R4 — RA-43.4 network-bound typed rail edge-key ingress | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_RA434_Network_Component_First_Consumer_20261014.md` | 36 | Review/definition/audit record | M6-CP3-CB1-ENTRY-R4 — RA-43.4 network-bound rail component first consumer (2026-10-14) | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_RA434_Standalone_Geometry_Diagnostic_Census_20261014.md` | 35 | Review/definition/audit record | RA-43.4 — standalone geometry diagnostic census (source-only) | CHANGELOG |
| `Architecture_M6_CP3_R4_RA434_Standalone_Geometry_Helper_Disposition_20261014.md` | 27 | Review/definition/audit record | RA-43.4 — standalone geometry helper disposition (source-only) | CHANGELOG |
| `Architecture_M6_CP3_R4_RA434_Static_Ingress_Census_20261014.md` | 37 | Review/definition/audit record | M6-CP3-CB1-ENTRY-R4 — RA-43.4 static ingress census | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_RA434_Strict_NoNetwork_Published_Edge_Keys_Code_Build_Record_20261013.md` | 29 | Code + Build record/plan | M6 CP3 R4 — RA-43.4 strict no-network source edge-key obligation (2026-10-13 UTC) | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_RA434_Strict_Production_Rail_Interval_Compile_Record_20261012.md` | 19 | Code + Build record/plan | M6-CP3-CB1-ENTRY-R4 — RA-43.4 production rail interval typed boundary | CHANGELOG |
| `Architecture_M6_CP3_R4_RA434_Strict_Trace_Entry_Missing_Edge_Oracle_20261013.md` | 27 | Review/definition/audit record | M6 CP3 R4 — RA-43.4 strict default trace ingress edge-key oracle (2026-10-13 UTC) | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_RA434_Typed_Rail_Corner_Confirmation_Code_Build_Record_20261012.md` | 19 | Code + Build record/plan | M6-CP3-CB1-ENTRY-R4 — typed rail corner confirmation checkpoint | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_RA434_Typed_Sample_Identity_Code_Build_Record_20261012.md` | 17 | Code + Build record/plan | R4 Code + Build — RA-43.4 typed rail sample source-identity boundary (2026-10-12) | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_RA45_A6_Incremental_Code_Build_Record.md` | 27 | Code + Build record/plan | M6-CP3-CB1-ENTRY-R4 — RA-45 A6 incremental Code + Build record (2026-10-10) | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_RA465_A4_Missing_Terminal_A3_Consumer_Oracle_20261013.md` | 11 | Review/definition/audit record | R4 RA-46.5 A4 missing terminal A3 path source regression (2026-10-13) | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_RA465_RA434_Static_Coverage_Census_20261014.md` | 33 | Review/definition/audit record | M6-CP3-CB1-ENTRY-R4 — terminal A3 negatives and typed-rail source census (2026-10-14) | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_RA466_Typed_Factory_Subcodes_NoOp_20261014.md` | 31 | Review/definition/audit record | RA-46.6 — Checked-factory typed subcodes already implemented | CHANGELOG |
| `Architecture_M6_CP3_R4_RA469_Source_Incidence_Lookup_Hardening_20261012.md` | 20 | Review/definition/audit record | M6-CP3-CB1-ENTRY-R4 — RA-46.9 incidence-map checked lookups | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_RA4710_Lexical_DCEL_Positive_Code_Build_Record_20261013.md` | 21 | Code + Build record/plan | M6-CP3-CB1-ENTRY-R4 — RA-47.10 lexical/DCEL typed rail positive (2026-10-13 UTC) | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_RA4711_Migration_NoOp_20261014.md` | 29 | Review/definition/audit record | RA-47.11 — Migration disposition: no change required | CHANGELOG |
| `Architecture_M6_CP3_R4_RA4711_Seven_Source_Edge_Index_Census_20261014.md` | 21 | Review/definition/audit record | RA-47.11 — Seven surviving source-edge-index sites: source-only census | CHANGELOG |
| `Architecture_M6_CP3_R4_RA4711_Test_EV_Row_Disposition_20261013.md` | 26 | Review/definition/audit record | M6-CP3 R4 — RA-47.11 test-only EV-row lookup disposition | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_RA4712_Default_Path_Typed_Interval_Liveness_Census_20261014.md` | 26 | Review/definition/audit record | RA-47.12 — default-path typed-interval liveness census | CHANGELOG |
| `Architecture_M6_CP3_R4_RA4712_Default_Producer_Rail_Liveness_Code_Build_Record_20261012.md` | 21 | Code + Build record/plan | M6-CP3-CB1-ENTRY-R4 — RA-47.12 default pipeline typed-rail liveness regression | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_RA4712_Uninjected_Pipeline_Rail_Liveness_Source_Oracle_20261013.md` | 11 | Review/definition/audit record | M6-CP3-CB1-ENTRY-R4 — RA-47.12 uninjected field-aligned producer liveness source oracle (2026-10-13) | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_RA477_Component_Aggregation_Independent_Rail_Key_Oracle_20261013.md` | 21 | Review/definition/audit record | R4 RA-47.7 — component aggregation vs independent typed rail producer keys (2026-10-13 UTC) | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_RA477_Component_Keys_Platform_Blocked_Handoff_20261013.md` | 11 | Review/definition/audit record | M6-CP3-CB1-ENTRY-R4 — RA-47.7 patch transport blocked (2026-10-13 UTC) | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_RA47_Typed_Rail_Code_Build_Record_20261012.md` | 70 | Code + Build record/plan | M6-CP3-CB1-ENTRY-R4 — RA-47 typed rail source-edge implementation WIP (2026-10-12) | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_RA49_Ambiguous_Terminal_Contact_Code_Build_Record_20261012.md` | 31 | Code + Build record/plan | M6-CP3-CB1-ENTRY-R4 — RA-49.2 duplicate terminal first-rejection regression | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_RA50_Closed_Chain_All_Edges_First_A4_Consumer_20261013.md` | 25 | Review/definition/audit record | M6-CP3-CB1-ENTRY-R4 — closed rail cyclic edge first-consumer validation | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_RA50_Closed_Chain_First_A4_Consumer_Guard_20261013.md` | 18 | Review/definition/audit record | R4 Code+Build continuation: first A4 closed-chain endpoint ownership | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_RA516_Injection_Guard_Compile_Record_20261013.md` | 46 | Code + Build record/plan | M6-CP3-CB1-ENTRY-R4 — RA-51.6 injected edge-table guard regression | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_RP02_Network_Bound_Consumer_Witness_20261015.md` | 25 | Review/definition/audit record | RP-02 network-bound open-front rail consumer witness (2026-10-15) | CHANGELOG |
| `Architecture_M6_CP3_R4_Raw_Edge_Index_Bounds_Code_Build_Record_20261012.md` | 12 | Code + Build record/plan | M6-CP3-CB1-ENTRY-R4 — raw source-edge index bounds regression | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_Region_Negatives_Initial_A3_Ingress_Code_Build_Record.md` | 20 | Code + Build record/plan | M6-CP3 R4 — Region-reference positive A3 ingress Code + Build record | CHANGELOG |
| `Architecture_M6_CP3_R4_Relief_Guidance_Atlas_Compile_Blocker_Record_20261011.md` | 19 | Code + Build record/plan | M6-CP3-CB1-ENTRY-R4 — relief guidance original-source A3 ingress (2026-10-11) | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_SID01_A5_Selected_Face_Pin_Code_Build_Record_20261013.md` | 31 | Code + Build record/plan | M6-CP3-CB1-ENTRY-R4 — R4-SID-01 independent A5 selected-face pin | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_SID01_SelfInverse_Side_Pin_Code_Build_Record_20261013.md` | 22 | Code + Build record/plan | M6-CP3-CB1-ENTRY-R4 — RA-50 R4-SID-01 A4 side pin regression | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_Seam_Witness_Original_Source_A3_Code_Build_Record_20261012.md` | 23 | Code + Build record/plan | M6-CP3-CB1-ENTRY-R4 — CP3 source-owned A3 seam witness ingress (2026-10-12) | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_Segment_Route_Atlas_Ingress_Code_Build_Record.md` | 26 | Code + Build record/plan | R4 Code + Build — six segment-route fixtures with independently source-owned A3 (2026-10-11) | CHANGELOG |
| `Architecture_M6_CP3_R4_Seven_DCEL_Fixture_Static_Census_20261014.md` | 25 | Review/definition/audit record | M6-CP3-CB1-ENTRY-R4 — seven historical DCEL fixture failures: exact-source static census | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_Seven_DCEL_Fixture_Static_Source_Census_20261012.md` | 29 | Review/definition/audit record | M6-CP3-CB1-ENTRY-R4 — independent static census of seven historical DCEL fixture losses | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_Seven_Phase10_Source_Atlas_Ingress_Code_Build_Record.md` | 33 | Code + Build record/plan | M6-CP3-CB1-ENTRY-R4 — Seven Phase10 source A2/A3 ingress candidate repairs (2026-10-11) | CHANGELOG |
| `Architecture_M6_CP3_R4_Shared_Boundary_A4_Negative_Authority_Code_Build_Record.md` | 25 | Code + Build record/plan | M6-CP3 R4 — Phase10 shared-boundary negative retains complete A4 source authority | CHANGELOG |
| `Architecture_M6_CP3_R4_Source_Authority_Binding_Stop_Record.md` | 40 | Review/definition/audit record | M6-CP3-CB1-ENTRY-R4 — source-authority binding stop record (2026-10-10) | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_Standalone_Negative_Curve_Owner_Guard_20261014.md` | 25 | Review/definition/audit record | M6-CP3-CB1-ENTRY-R4 — standalone negative curve-owner correction (2026-10-14) | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_Supplemental_Witness_TB_Report_20261015.md` | 33 | Test + Benchmark record/plan | M6-CP3-TB1-R4-WITNESS-EXEC — supplemental immutable-artifact Test + Benchmark | CHANGELOG |
| `Architecture_M6_CP3_R4_Terminal_A3U01_Typed_Reject_Code_Build_Record_20261012.md` | 31 | Code + Build record/plan | M6-CP3-CB1-ENTRY-R4 — RA-46 R4-A3U-01 checked-factory typed terminal-path rejection | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_Terminal_A3_Path_Count_Diagnostic_Code_Build_Record_20261011.md` | 19 | Code + Build record/plan | M6-CP3-CB1-ENTRY-R4 — A2b terminal source-star path-count rejection diagnostic (2026-10-11) | CHANGELOG |
| `Architecture_M6_CP3_R4_Terminal_Conjunct_Artifact_Extraction_20261015.md` | 46 | Review/definition/audit record | R4 terminal-conjunct artifact extraction — 2026-10-15 | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_Terminal_Germ_Forgery_Negatives_Code_Build_Record.md` | 10 | Code + Build record/plan | R4 A2b terminal side-germ forgery negative — incremental Code + Build | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_Terminal_Germ_Incremental_Code_Build_Record.md` | 117 | Code + Build record/plan | M6-CP3-CB1-ENTRY-R4 — produced terminal A2b source-star germ (incremental) | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_Three_Phase10_A3_Ingress_Code_Build_Record_20261012.md` | 21 | Code + Build record/plan | M6-CP3-CB1-ENTRY-R4 — three Phase10 source-A3 fixture ingresses (2026-10-12) | CHANGELOG |
| `Architecture_M6_CP3_R4_True_Control_Artifact_Only_TB_Report_20261015.md` | 36 | Test + Benchmark record/plan | R4 true-control — artifact-only Test + Benchmark report (2026-10-15) | CHANGELOG |
| `Architecture_M6_CP3_R4_True_Control_Ledger_20261015.tsv` | 5 | superseded ledger | 4 data rows | retained Review records |
| `Architecture_M6_CP3_R4_True_Control_Measured_Loci_20261015.tsv` | 5 | per-turn data/receipt | 4 data rows | retained Review records |
| `Architecture_M6_CP3_R4_Two_Composite_A3_Atlas_Ingress_Code_Build_Record.md` | 25 | Code + Build record/plan | R4 Code + Build — two Phase10 composite A2/A3 fixture ingress candidates (2026-10-11) | CHANGELOG |
| `Architecture_M6_CP3_R4_Two_Phase10_Negative_A3_Code_Build_Record_20261012.md` | 20 | Code + Build record/plan | M6-CP3-CB1-ENTRY-R4 — two Phase10 independently source-bound A3 negative fixtures (2026-10-12) | CHANGELOG |
| `Architecture_M6_CP3_R4_Typed_Rail_Incremental_Code_Build_Record.md` | 42 | Code + Build record/plan | M6-CP3-CB1-ENTRY-R4 — typed rail source-incidence incremental Code + Build | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_Typed_Rail_Source_Edge_Index_Code_Build_Closeout_20261012.md` | 29 | Code + Build record/plan | M6-CP3-CB1-ENTRY-R4 — typed producer rail-edge binding / compile-failure continuation (2026-10-12) | CHANGELOG |
| `Architecture_M6_CP3_R4_Typed_Raw_Edge_Cardinality_Code_Build_Record_20261012.md` | 17 | Code + Build record/plan | M6-CP3-CB1-ENTRY-R4 — optional raw rail sidecar cardinality guard | CHANGELOG |
| `Architecture_M6_CP3_R4_Unsupported_Sheet_Original_A3_Code_Build_Record_20261012.md` | 23 | Code + Build record/plan | M6-CP3-CB1-ENTRY-R4 — unsupported-sheet source A3 first-rejection candidate (2026-10-12) | CHANGELOG |
| `Architecture_M6_CP3_R4_Witness_Breadth_Execution_Boundary_20261015.txt` | 11 | per-turn data/receipt | 10 data rows | retained Review records |
| `Architecture_M6_CP3_R4_Witness_Breadth_Ledger_20261015.tsv` | 5 | superseded ledger | 4 data rows | retained Review records |
| `Architecture_M6_CP3_R4_Witness_First_RED_Independent_Review_Decision_20261015.md` | 58 | Review/definition/audit record | Independent Review — first executed supplemental RP-02 RED (2026-10-15) | CHANGELOG |
| `Architecture_M6_CP3_R4_Witness_Interval_Terminal_Recovery_Code_Build_Plan.md` | 23 | Code + Build record/plan | R4 supplemental witness — interior rail interval / terminal certificate recovery (Code + Build) | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R4_Witness_Repair_Code_Build_Record_20261015.md` | 26 | Code + Build record/plan | R4 open-hard-rail interior endpoint witness repair — compile checkpoint | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R5_Junction_Carrier_Authority_Specification_20261015.md` | 60 | Review/definition/audit record | M6-CP3 R5 — Junction/carrier authority specification (definition only) | CHANGELOG |
| `Architecture_M6_CP3_R5_Route_Path_Reconciliation_Harvest_Artifact_Only_TB_Report_20261016.md` | 30 | Test + Benchmark record/plan | M6 CP3 R5 — route/path reconciliation: artifact-only TB5 harvest | CHANGELOG |
| `Architecture_M6_CP3_R5_Route_Path_Reconciliation_Probe_Code_Build_Record_20261016.md` | 23 | Code + Build record/plan | R5 route/path reconciliation probe — Code + Build record | CHANGELOG |
| `Architecture_M6_CP3_R6_Corner_Assignment_Authority_Specification_20261016.md` | 51 | Review/definition/audit record | M6 CP3 R6 — corner-assignment authority: source-static definition | CHANGELOG |
| `Architecture_M6_CP3_R7_Corner_Face_Selection_Repair_Specification_20261016.md` | 59 | Review/definition/audit record | M6 CP3 R7 — source-attested, side-specific corner-face repair specification | CHANGELOG |
| `Architecture_M6_CP3_R7_Lattice_UV_Candidate_Harvest_TB_Report_20261016.md` | 27 | Test + Benchmark record/plan | M6 CP3 R7 — pre-snap candidate harvest (artifact-only TB7) | CHANGELOG |
| `Architecture_M6_CP3_R7_Lattice_UV_Candidate_Probe_Code_Build_Record_20261016.md` | 19 | Code + Build record/plan | R7 pre-snap lattice-UV candidate probe — Code + Build record | CHANGELOG |
| `Architecture_M6_CP3_R7_Node_Admissible_Face_Set_Harvest_TB_Report_20261016.md` | 31 | Test + Benchmark record/plan | M6 CP3 R7 — admissible-face-set harvest (artifact-only TB6) | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_R8_Boundary_Override_Authority_Specification_20261016.md` | 34 | Review/definition/audit record | M6 CP3 R8 — accepted-boundary / chart-face authority specification | CHANGELOG |
| `Architecture_M6_CP3_R8_Source_Entity_Equivalence_Probe_Code_Build_Record_20261016.md` | 13 | Code + Build record/plan | M6 CP3 CB8 — rejection-only boundary source-entity diagnostic | CHANGELOG |
| `Architecture_M6_CP3_R9A_Endpoint_Face_Comparison_Census_20261016.md` | 51 | Review/definition/audit record | M6 CP3 R9A — endpoint face-comparison census (Definition) | CHANGELOG |
| `Architecture_M6_CP3_R9B_Endpoint_Equivalence_Contract_Specification_20261016.md` | 82 | Review/definition/audit record | M6 CP3 R9B — endpoint equivalence contract (Definition) | CHANGELOG |
| `Architecture_M6_CP3_RP01_Off_Gate_Deferred_Ledger.tsv` | 86 | superseded ledger | 85 data rows | CHANGELOG; tracker |
| `Architecture_M6_CP3_RP01_Off_Gate_Deferred_Ledger_v2.tsv` | 87 | superseded ledger | 86 data rows | superseded deferred ledger; current `Architecture_M6_CP3_RP01_Off_Gate_Deferred_Ledger_v5.tsv` |
| `Architecture_M6_CP3_RP01_Off_Gate_Deferred_Ledger_v3.tsv` | 84 | superseded ledger | 83 data rows | superseded deferred ledger; current `Architecture_M6_CP3_RP01_Off_Gate_Deferred_Ledger_v5.tsv` |
| `Architecture_M6_CP3_RP01_Off_Gate_Deferred_Ledger_v4.tsv` | 83 | superseded ledger | 82 data rows | retained Review records |
| `Architecture_M6_CP3_TB10_Carrier_Endpoint_Subcondition_Harvest_Report_20261016.md` | 7 | Test + Benchmark record/plan | TB10 — Carrier Endpoint Subcondition Harvest (2026-10-16) | CHANGELOG |
| `Architecture_M6_CP3_TB11_Open_Rail_Route_Anchor_Harvest_Report_20261018.md` | 8 | Test + Benchmark record/plan | TB11 — Immutable R10 route-anchor harvest (2026-10-18) | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_TB12_Open_Rail_Chain_Provenance_Harvest_Report_20261018.md` | 23 | Test + Benchmark record/plan | TB12 — Immutable open-rail chain provenance harvest (2026-10-18) | CHANGELOG; tracker |
| `Architecture_M6_CP3_TB13A_Truth_Table_Harvest_Report_20261018.md` | 14 | Test + Benchmark record/plan | M6 CP3 TB13A — immutable truth-table harvest, 2026-10-18 | tracker |
| `Architecture_M6_CP3_TB13_Open_Rail_Chain_Interval_Harvest_Report_20261018.md` | 20 | Test + Benchmark record/plan | TB13 — Immutable open-rail chain-interval harvest (2026-10-18) | tracker |
| `Architecture_M6_CP3_TB14A_Curved_Disk_Control_Census_Report_20261018.md` | 16 | Review/definition/audit record | M6-CP3 TB14A — curved-disk control census (2026-10-18) | retained Review records |
| `Architecture_M6_CP3_TB15_Exact_I_Witness_Harvest_Report_20261018.md` | 27 | Test + Benchmark record/plan | M6 CP3 TB15 — exact interior-endpoint witness harvest (2026-10-18) | CHANGELOG; tracker |
| `Architecture_M6_CP3_TB16A_Exact_I_Witness_Checkers_Harvest_Report_20261019.md` | 21 | Test + Benchmark record/plan | M6 CP3 TB16A — exact-I endpoint witness checker harvest (2026-10-19) | CHANGELOG; tracker; retained Review records |
| `Architecture_M6_CP3_TB16C_Selector_497_Census_Report_20261019.md` | 30 | Review/definition/audit record | M6 CP3 TB16C immutable selector-497 census | tracker |
| `Architecture_M6_CP3_TB16_Exact_I_Witness_Checkers_Harvest_Report_20261019.md` | 20 | Test + Benchmark record/plan | M6 CP3 TB16 — exact-I witness checker harvest (2026-10-19) | CHANGELOG; tracker |
| `Architecture_M6_CP3_TB17_Factory_Rail_Vertex_Endpoint_Harvest_Report_20261019.md` | 14 | Test + Benchmark record/plan | TB17 — factory rail-interior-vertex verification (2026-10-19) | CHANGELOG; tracker |
| `Architecture_M6_CP3_TB18_Rail_Vertex_Endpoint_Harvest_Report_20261020.md` | 27 | Test + Benchmark record/plan | TB18 — immutable R10 rail-vertex endpoint harvest (2026-10-20) | tracker |
| `Architecture_M6_CP3_TB18_Selector_497_Red_Inventory.tsv` | 50 | per-turn data/receipt | 49 data rows | tracker; retained Review records |
| `Architecture_M6_CP3_TB1_Entry_R1_Artifact_Only_Test_Benchmark_Report.md` | 42 | Test + Benchmark record/plan | Architecture M6 CP3 TB1 Entry R1 Artifact-Only Test + Benchmark Report | CHANGELOG; M6_Consolidated_Record; retained Review records |
| `Architecture_M6_CP3_TB1_Entry_R2_Execution_Record.md` | 76 | Test + Benchmark record/plan | Post-execution independent Review verdict (2026-10-08) | CHANGELOG; M6_Consolidated_Record; retained Review records |
| `Architecture_M6_CP3_TB1_Entry_R2_Red_Classification.tsv` | 54 | per-turn data/receipt | 53 data rows | CHANGELOG; M6_Consolidated_Record; retained Review records |
| `Architecture_M6_CP3_TB1_Entry_R3_Artifact_Only_Test_Benchmark_Plan.md` | 34 | Test + Benchmark record/plan | CURRENT authoritative RA-40 Code + Build result — 2026-10-10 06:02Z | CHANGELOG; M6_Consolidated_Record; retained Review records |
| `Architecture_M6_CP3_TB1_Entry_R3_Execution_Record.md` | 42 | Test + Benchmark record/plan | M6-CP3-TB1-ENTRY-R3-EXEC — artifact-only frozen 497 execution record | CHANGELOG; M6_Consolidated_Record; retained Review records |
| `Architecture_M6_CP3_TB1_Entry_R3_Independent_94_Review_Overlay.tsv` | 95 | per-turn data/receipt | 94 data rows | CHANGELOG |
| `Architecture_M6_CP3_TB1_Entry_R3_Independent_Review_Record.md` | 71 | Review/definition/audit record | M6-CP3-TB1-ENTRY-R3-REV — Independent Review of Frozen 497 TB | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_TB1_Entry_R3_R2_Identity_Comparison.tsv` | 54 | per-turn data/receipt | 53 data rows | CHANGELOG; M6_Consolidated_Record; retained Review records |
| `Architecture_M6_CP3_TB1_Entry_R3_REV_Adjudication.md` | 116 | Review/definition/audit record | M6-CP3-TB1-ENTRY-R3-REV — independent adjudication | CHANGELOG; M6_Consolidated_Record; retained Review records |
| `Architecture_M6_CP3_TB22_Torus_Witness_Harvest_Report_20261021.md` | 11 | Test + Benchmark record/plan | TB22 — Immutable torus witness harvest (2026-10-21) | CHANGELOG; tracker; retained Review records |
| `Architecture_M6_CP3_TB23_Torus_A5_Site_Harvest_Report_20261021.md` | 32 | Test + Benchmark record/plan | TB23 — Torus A5 isolation-site harvest (2026-10-21) | CHANGELOG; tracker; retained Review records |
| `Architecture_M6_CP3_TB24_Torus_A5_Seam_Face_Harvest_Plan_20261021.md` | 35 | consumed plan | TB24 — torus A5 seam-face diagnostic harvest (2026-10-21) | CHANGELOG |
| `Architecture_M6_CP3_TB24_Torus_A5_Seam_Face_Harvest_Report_20261021.md` | 35 | Test + Benchmark record/plan | TB24 — Torus A5 seam-face diagnostic harvest (2026-10-21) | tracker |
| `Architecture_M6_CP3_TB25_Seam_Frame_Values_Harvest_Plan_20261021.md` | 32 | consumed plan | TB25 — immutable seam frame values harvest (frozen by RA-125, 2026-10-21) | CHANGELOG |
| `Architecture_M6_CP3_TB25_Seam_Frame_Values_Harvest_Report_20261021.md` | 24 | Test + Benchmark record/plan | TB25 — immutable seam frame-values harvest (2026-10-21) | CHANGELOG; tracker |
| `Architecture_M6_CP3_TB26_Shared_Node_Seam_Witness_Harvest_Report_20261022.md` | 36 | Test + Benchmark record/plan | TB26 — immutable shared-node seam witness harvest (2026-10-22) | CHANGELOG; tracker |
| `Architecture_M6_CP3_TB27_A7_Certified_Seam_Cross_Sheet_Verification_Report_20261022.md` | 24 | Review/definition/audit record | TB27 — A7 certified-seam cross-sheet verification (2026-10-22) | CHANGELOG; tracker |
| `Architecture_M6_CP3_TB28_Selector_497_Census_Report_20261022.md` | 39 | Review/definition/audit record | TB28 — selector-497 artifact-only census (2026-10-22) | tracker |
| `Architecture_M6_CP3_TB28_Selector_497_Full_Ledger.tsv` | 498 | superseded ledger | 497 data rows | tracker |
| `Architecture_M6_CP3_TB28_Selector_497_Red_Inventory.tsv` | 36 | per-turn data/receipt | 35 data rows | tracker; M6_Consolidated_Record; retained Review records |
| `Architecture_M6_CP3_TB29H_RP02_Harness_Correction_Code_Build_Record_20261023.md` | 19 | Code + Build record/plan | TB29H RP02 harness correction — Code + Build record (2026-10-23) | CHANGELOG |
| `Architecture_M6_CP3_TB29H_RP02_Harness_Correction_Review_Decision_20261023.md` | 52 | Review/definition/audit record | TB29H-RP02 — Independent corrected-harness review (2026-10-23) | CHANGELOG; tracker; retained Review records |
| `Architecture_M6_CP3_TB29H_Targeted_Harness_Code_Build_Record_20261023.md` | 10 | Code + Build record/plan | TB29H — reusable targeted artifact harness (2026-10-23) | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_TB29_Prerequisite_Stop_20261023.md` | 18 | Review/definition/audit record | TB29 prerequisite stop — 2026-10-23 | retained Review records |
| `Architecture_M6_CP3_TB29_Typed_Factory_Cause_Harvest_Report_20261023.md` | 99 | Test + Benchmark record/plan | TB29 — artifact-only targeted typed factory cause harvest (2026-10-23) | CHANGELOG; tracker; M6_Consolidated_Record; retained Review records |
| `Architecture_M6_CP3_TB30_Certificate_Association_Ownership_Verification_Report_20261023.md` | 66 | Review/definition/audit record | TB30 — targeted certificate-association ownership verification (2026-10-23) | CHANGELOG; tracker |
| `Architecture_M6_CP3_TB30_Targeted_Case_Manifest.tsv` | 30 | superseded per-turn case manifest | 29 data rows | CHANGELOG |
| `Architecture_M6_CP3_TB31_Selector_497_Census_Report_20261023.md` | 66 | Review/definition/audit record | TB31 — 497-case immutable census (2026-10-23) | CHANGELOG; tracker; retained Review records |
| `Architecture_M6_CP3_TB31_Selector_497_Census_Review_Decision_20261023.md` | 54 | Review/definition/audit record | RA-145 — TB31 independent selector-497 census Review (2026-10-23) | CHANGELOG; tracker |
| `Architecture_M6_CP3_TB31_Selector_497_Red_Inventory.tsv` | 26 | per-turn data/receipt | 25 data rows | CHANGELOG; tracker |
| `Architecture_M6_CP3_TB32_Periodic_Owner_Gauge_Case_Manifest.tsv` | 501 | superseded per-turn case manifest | 500 data rows | CHANGELOG; tracker |
| `Architecture_M6_CP3_TB32_Periodic_Owner_Gauge_Verification_Plan_20261023.md` | 20 | consumed plan | TB32 — immutable periodic-owner gauge verification plan (RA-147, 2026-10-23) | CHANGELOG; tracker |
| `Architecture_M6_CP3_TB32_Periodic_Owner_Gauge_Verification_Report_20261023.md` | 40 | Review/definition/audit record | TB32 — immutable periodic-owner gauge verification (2026-10-23) | tracker |
| `Architecture_M6_CP3_TB32_Periodic_Owner_Gauge_Verification_Review_Decision_20261023.md` | 55 | Review/definition/audit record | RA-148 — Independent TB32 evidence Review (2026-10-23) | CHANGELOG; tracker |
| `Architecture_M6_CP3_TB32_Residual_Red_Inventory.tsv` | 20 | per-turn data/receipt | 19 data rows | tracker |
| `Architecture_M6_CP3_TB33_Odd_Atlas_Oracle_Cases.tsv` | 7 | superseded per-turn case manifest | 6 data rows | retained Review records |
| `Architecture_M6_CP3_TB33_Odd_Atlas_Oracle_Verification_Report_20261024.md` | 37 | Review/definition/audit record | M6 CP3 TB33 — immutable odd-atlas oracle verification (2026-10-24) | CHANGELOG; tracker |
| `Architecture_M6_CP3_TB34_A3_Cycle_Locus_Harvest_Report_20261024.md` | 12 | Test + Benchmark record/plan | TB34 — immutable A3 cycle-locus harvest (2026-10-24) | CHANGELOG; tracker |
| `Architecture_M6_CP3_TB34_A3_Cycle_Locus_Harvest_Review_Decision_20261024.md` | 60 | Review/definition/audit record | TB34-REV — independent cycle-transport locus and fixture ownership decision (2026-10-24) | CHANGELOG; tracker; retained Review records |
| `Architecture_M6_CP3_TB35_Periodic_Route_Gauge_Independent_Review_Decision_20261024.md` | 55 | Review/definition/audit record | TB35-REV — periodic negative ingress authority (2026-10-24) | CHANGELOG; tracker; retained Review records |
| `Architecture_M6_CP3_TB35_Periodic_Route_Gauge_Verification_Report_20261024.md` | 25 | Review/definition/audit record | TB35 — immutable periodic route gauge verification (2026-10-24) | CHANGELOG; tracker |
| `Architecture_M6_CP3_TB36_R1_Periodic_Monodromy_Baseline_Independent_Review_Decision_20261025.md` | 50 | Review/definition/audit record | TB36-R1 periodic monodromy baseline — independent review (2026-10-25) | CHANGELOG; tracker; retained Review records |
| `Architecture_M6_CP3_TB36_R1_Periodic_Monodromy_Baseline_Report_20261025.md` | 27 | Review/definition/audit record | M6-CP3 TB36-R1 — periodic monodromy immutable baseline (2026-10-25) | CHANGELOG; tracker |
| `Architecture_M6_CP3_TB37_Periodic_Route_Atlas_Verification_Independent_Review_Decision_20261025.md` | 47 | Review/definition/audit record | TB37-REV — independent periodic-route atlas verification (2026-10-25) | CHANGELOG; tracker |
| `Architecture_M6_CP3_TB37_Periodic_Route_Atlas_Verification_Report_20261025.md` | 33 | Review/definition/audit record | TB37 periodic-route atlas verification — artifact-only execution (2026-10-25) | CHANGELOG |
| `Architecture_M6_CP3_TB38_Periodic_Route_Atlas_Census_Case_Manifest.tsv` | 505 | superseded per-turn case manifest | 504 data rows | retained Review records |
| `Architecture_M6_CP3_TB38_Periodic_Route_Atlas_Census_Independent_Review_Decision_20261025.md` | 65 | Review/definition/audit record | TB38 periodic route atlas census — independent evidence Review (2026-10-25) | CHANGELOG; tracker; M6_Consolidated_Record |
| `Architecture_M6_CP3_TB38_Periodic_Route_Atlas_Census_Report_20261025.md` | 24 | Review/definition/audit record | TB38 — periodic route atlas census, artifact-only (2026-10-25) | CHANGELOG; tracker; M6_Consolidated_Record |
| `Architecture_M6_CP3_TB39_Selector250_Factory_Site_Harvest_Case_Manifest.tsv` | 8 | superseded per-turn case manifest | 7 data rows | tracker; retained Review records |
| `Architecture_M6_CP3_TB39_Selector250_Factory_Site_Harvest_Report_20261025.md` | 30 | Test + Benchmark record/plan | TB39 — selector250 checked-factory site harvest (2026-10-25) | CHANGELOG; tracker |
| `Architecture_M6_CP3_TB39_Selector250_Factory_Site_Independent_Review_20261025.md` | 44 | Review/definition/audit record | TB39-REV — selector250 checked-factory site independent adjudication (2026-10-25) | CHANGELOG; tracker |
| `Architecture_M6_CP3_TB3_R4_Probe_Harvest_Report_20261015.md` | 18 | Test + Benchmark record/plan | M6 CP3 R4 — immutable probe harvest (2026-10-15) | CHANGELOG; tracker; M6_Consolidated_Record; retained Review records |
| `Architecture_M6_CP3_TB40_Selector250_Rail_Authority_Independent_Review_20261025.md` | 45 | Review/definition/audit record | TB40 selector-250 rail-authority — independent static review (2026-10-25) | CHANGELOG; tracker |
| `Architecture_M6_CP3_TB40_Selector250_Rail_Authority_Verification_Case_Manifest.tsv` | 14 | superseded per-turn case manifest | 13 data rows | retained Review records |
| `Architecture_M6_CP3_TB40_Selector250_Rail_Authority_Verification_Report_20261025.md` | 18 | Review/definition/audit record | TB40 — immutable selector-250 rail-authority verification (2026-10-25) | CHANGELOG; tracker |
| `Architecture_M6_CP3_TB41_Rehomed_Oracle_Independent_Review_Decision_20261026.md` | 50 | Review/definition/audit record | TB41 independent runtime-evidence review — 2026-10-26 | CHANGELOG |
| `Architecture_M6_CP3_TB41_Rehomed_Oracle_Verification_Case_Manifest.tsv` | 19 | superseded per-turn case manifest | 18 data rows | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_TB41_Rehomed_Oracle_Verification_Report_20261026.md` | 13 | Review/definition/audit record | TB41 — re-homed oracle verification (2026-10-26) | CHANGELOG |
| `Architecture_M6_CP3_TB42_O3_Off_Selector_Locus_Case_Manifest.tsv` | 2 | superseded per-turn case manifest | 1 data rows | retained Review records |
| `Architecture_M6_CP3_TB42_O3_Off_Selector_Locus_Independent_Review_Decision_20261026.md` | 42 | Review/definition/audit record | TB42-REV — independent O3 off-selector locus decision (2026-10-26) | CHANGELOG; tracker |
| `Architecture_M6_CP3_TB42_O3_Off_Selector_Locus_Verification_Report_20261026.md` | 11 | Review/definition/audit record | TB42 — O3 off-selector polygonal-disk locus verification (2026-10-26) | CHANGELOG |
| `Architecture_M6_CP3_TB43_Selector190_Rehome_Independent_Review_Decision_20261026.md` | 52 | Review/definition/audit record | TB43 independent Review — selector190 A3/A4 ingress evidence (2026-10-26) | CHANGELOG |
| `Architecture_M6_CP3_TB43_Selector190_Rehome_Verification_Case_Manifest.tsv` | 5 | superseded per-turn case manifest | 4 data rows | CHANGELOG |
| `Architecture_M6_CP3_TB43_Selector190_Rehome_Verification_Report_20261026.md` | 28 | Review/definition/audit record | TB43 — selector190 artifact-only verification (2026-10-26) | CHANGELOG |
| `Architecture_M6_CP3_TB44_Selector405_Fixed_Plan_Independent_Review_Decision_20261026.md` | 50 | consumed plan | TB44 independent Review — selector405 focused plan and RA-161 P1 (2026-10-26) | CHANGELOG; tracker |
| `Architecture_M6_CP3_TB44_Selector405_Fixed_Plan_Verification_Case_Manifest.tsv` | 5 | superseded per-turn case manifest | 4 data rows | CHANGELOG |
| `Architecture_M6_CP3_TB44_Selector405_Fixed_Plan_Verification_Report_20261026.md` | 30 | consumed plan | TB44 — selector405 fixed-plan verification (2026-10-26) | CHANGELOG; tracker |
| `Architecture_M6_CP3_TB45_Selector242_Seam_Rehome_Independent_Review_Decision_20261027.md` | 45 | Review/definition/audit record | TB45 independent Review — selector242 source-adjacent isolation seam (2026-10-27) | CHANGELOG |
| `Architecture_M6_CP3_TB45_Selector242_Seam_Rehome_Verification_Case_Manifest.tsv` | 4 | superseded per-turn case manifest | 3 data rows | CHANGELOG |
| `Architecture_M6_CP3_TB45_Selector242_Seam_Rehome_Verification_Report_20261027.md` | 27 | Review/definition/audit record | TB45 — selector242 seam re-home immutable artifact-only verification (2026-10-27) | CHANGELOG |
| `Architecture_M6_CP3_TB46A_Orchestration_Correction_Compile_Record_20261027.md` | 27 | Code + Build record/plan | TB46A orchestration correction — compile-only evidence and review prerequisite (2026-10-27) | CHANGELOG; tracker |
| `Architecture_M6_CP3_TB46A_Orchestration_Correction_Continuation_20261027.md` | 24 | working record | TB46A orchestration correction — bounded continuation (2026-10-27) | CHANGELOG; tracker |
| `Architecture_M6_CP3_TB46A_REV_Selector174_Manifold_Fixture_Authorization_Decision_20261027.md` | 128 | Review/definition/audit record | RA-165 — TB46A-REV: selector174 has two invalid fixtures; line-neutral fix authorized; RA-164 H1 corrected (2026-10-27) | CHANGELOG; tracker |
| `Architecture_M6_CP3_TB46_Full_Gate_Case_Manifest.tsv` | 505 | superseded per-turn case manifest | 504 data rows | retained Review records |
| `Architecture_M6_CP3_TB46_Full_Gate_Test_Benchmark_Report_20261027.md` | 45 | Test + Benchmark record/plan | M6-CP3-TB46 full-gate artifact-only test/benchmark record — 2026-10-27 | CHANGELOG; tracker |
| `Architecture_M6_CP3_TB46_RP01_Full_Gate_Rerun_Report_20261027.md` | 39 | Review/definition/audit record | TB46 RP-01 full-gate rerun — immutable 504-case evidence (2026-10-27) | CHANGELOG; tracker |
| `Architecture_M6_CP3_TB47_Full_Gate_Case_Manifest.tsv` | 505 | superseded per-turn case manifest | 504 data rows | CHANGELOG; tracker |
| `Architecture_M6_CP3_TB47_REV_Gauge_Cluster_Decision_And_Canonical_Turn_Sequence_20261028.md` | 319 | Review/definition/audit record | RA-167 — TB47-REV: gauge cluster decided by probes; canonical turn sequence; stalled DEFN closed (2026-10-28) | CHANGELOG; tracker |
| `Architecture_M6_CP3_TB47_RP01_Full_Gate_Test_Benchmark_Report_20261027.md` | 29 | Test + Benchmark record/plan | TB47 RP-01 immutable full gate — verified 500/4 (2026-10-27) | CHANGELOG; tracker |
| `Architecture_M6_CP3_TB48_Full_Gate_Case_Manifest.tsv` | 505 | superseded per-turn case manifest | 504 data rows | retained Review records |
| `Architecture_M6_CP3_TB48_REV_Audit_G3_A5_Gauge_And_E2_Rail_Vertex_Patches_20261028.md` | 771 | Review/definition/audit record | RA-168 — TB48-REV audit: P-G3 is an A5 defect, E2 is a stale oracle; exact CB49 and CB49E patches (2026-10-28) | CHANGELOG; tracker |
| `Architecture_M6_CP3_TB48_RP01_Full_Gate_Independent_Review_Decision_20261028.md` | 46 | Review/definition/audit record | TB48 RP-01 independent full-gate Review — 2026-10-28 | CHANGELOG; tracker |
| `Architecture_M6_CP3_TB48_RP01_Full_Gate_Test_Benchmark_Report_20261028.md` | 26 | Test + Benchmark record/plan | TB48 RP-01 — immutable 504-case full gate (2026-10-28) | CHANGELOG; tracker |
| `Architecture_M6_CP3_TB49_Full_Gate_Case_Manifest.tsv` | 505 | superseded per-turn case manifest | 504 data rows | CHANGELOG; tracker |
| `Architecture_M6_CP3_TB49_REV_Closeout_C1_Rail_Cover_DEFN_Patches_20261028.md` | 338 | Review/definition/audit record | RA-169 — TB49-REV closed on authentic history; C1 rail-cover DEFN with exact CB50/CB50F patches; O4/O5 DEFN split (2026-10-28) | CHANGELOG; tracker |
| `Architecture_M6_CP3_TB49_REV_Reaudit_P1_O4_DEFNs_E2_Site_Pins_OffGate_Census_20261028.md` | 287 | Review/definition/audit record | RA-170 — TB49-REV re-audit; P1-a, P1-b, O4 DEFNs closed; E2 site pins; off-gate RED census (2026-10-28) | CHANGELOG; tracker |
| `Architecture_M6_CP3_TB49_RP01_Full_Gate_Independent_Review_Decision_20261028.md` | 63 | Review/definition/audit record | TB49 RP-01 — independent full-gate review (2026-10-28) | CHANGELOG; tracker |
| `Architecture_M6_CP3_TB49_RP01_Full_Gate_Test_Benchmark_Report_20261028.md` | 21 | Test + Benchmark record/plan | TB49 RP-01 — immutable 504-case full gate (2026-10-28) | CHANGELOG; tracker |
| `Architecture_M6_CP3_TB50C_Off_Gate_Census_Case_Manifest.tsv` | 409 | superseded per-turn case manifest | 408 data rows | CHANGELOG; tracker |
| `Architecture_M6_CP3_TB50C_Off_Gate_Census_Orchestration_Failure_Report_20261029.md` | 15 | Test + Benchmark record/plan | M6-CP3-TB50C — off-gate census orchestration S5 (2026-10-29) | CHANGELOG; tracker |
| `Architecture_M6_CP3_TB50C_RP01_Off_Gate_Census_R2_Test_Benchmark_Report_20261029.md` | 164 | Test + Benchmark record/plan | M6-CP3-TB50C-RP01-OFF-GATE-CENSUS-EXEC-R2 — Test + Benchmark complete (2026-10-29) | CHANGELOG; tracker |
| `Architecture_M6_CP3_TB50_Full_Gate_Case_Manifest.tsv` | 509 | superseded per-turn case manifest | 508 data rows | CHANGELOG; tracker |
| `Architecture_M6_CP3_TB50_REV_Gate_Closeout_Census_Observe_Harness_20261029.md` | 230 | Review/definition/audit record | RA-171 — TB50-REV gate closeout; TB50C census observe contract (2026-10-29) | CHANGELOG; tracker |
| `Architecture_M6_CP3_TB50_RP01_Full_Gate_Orchestration_Failure_Report_20261029.md` | 32 | Test + Benchmark record/plan | TB50 frozen 508-case preflight — deterministic harness/manifest mismatch | CHANGELOG; tracker |
| `Architecture_M6_CP3_TB50_RP01_Full_Gate_R2_Test_Benchmark_Report_20261029.md` | 23 | Test + Benchmark record/plan | M6-CP3-TB50-RP01-FULL-GATE-EXEC-R2 — native full-gate report (2026-10-29) | CHANGELOG; tracker |
| `Architecture_M6_CP3_TB51_Full_Gate_Case_Manifest.tsv` | 832 | superseded per-turn case manifest | 831 data rows | CHANGELOG; tracker |
| `Architecture_M6_CP3_TB51_REV_Independent_Full_Gate_Review_20261030.md` | 47 | Review/definition/audit record | RA-173 — M6-CP3-TB51-RP01-FULL-GATE-REV (2026-10-30) | CHANGELOG; tracker |
| `Architecture_M6_CP3_TB51_RP01_Full_Gate_Artifact_Only_Test_Benchmark_Report_20261030.md` | 39 | Test + Benchmark record/plan | M6-CP3-TB51-RP01-FULL-GATE-EXEC — immutable full-gate evidence (2026-10-30) | CHANGELOG; tracker |
| `Architecture_M6_CP3_TB52C_API_Binary_Census_Case_Manifest.tsv` | 24 | superseded per-turn case manifest | 23 data rows | CHANGELOG |
| `Architecture_M6_CP3_TB52C_REV_API_Binary_Census_Independent_Disposition_20261030.md` | 56 | Review/definition/audit record | TB52C independent API-binary census Review — RA-175 (2026-10-30) | CHANGELOG; tracker |
| `Architecture_M6_CP3_TB52C_RP01_API_Binary_Census_Artifact_Only_Report_20261030.md` | 26 | Review/definition/audit record | TB52C — API binary census execution (2026-10-30) | CHANGELOG; tracker |
| `Architecture_M6_CP3_TB52_REV_Independent_Five_Binary_Gate_Review_20261030.md` | 57 | Review/definition/audit record | RA-177 — TB52 independent five-binary full-gate Review (2026-10-30) | CHANGELOG; tracker |
| `Architecture_M6_CP3_TB52_RP01_Full_Gate_Artifact_Only_Test_Benchmark_Report_20261030.md` | 37 | Test + Benchmark record/plan | M6-CP3-TB52-RP01-FULL-GATE-EXEC — immutable five-binary gate evidence (2026-10-30) | CHANGELOG; tracker |
| `Architecture_M6_CP3_TB52_RP01_Full_Gate_Case_Manifest.tsv` | 854 | superseded per-turn case manifest | 853 data rows | CHANGELOG; tracker |
| `Architecture_M6_CP3_TB53_RP01_Full_Gate_Case_Manifest.tsv` | 856 | superseded per-turn case manifest | 855 data rows | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_TB53_RP01_Full_Gate_Local_Test_Report_20261030.md` | 63 | Test + Benchmark record/plan | M6-CP3-TB53-RP01-FULL-GATE-EXEC — local five-binary gate on the CB54 package (2026-10-30) | CHANGELOG; tracker |
| `Architecture_M6_CP3_TB54_O15_Full_Gate_Case_Manifest.tsv` | 858 | superseded per-turn case manifest | 857 data rows | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_TB54_O15_Full_Gate_Local_Test_Report_20261031.md` | 37 | Test + Benchmark record/plan | M6-CP3-TB54-O15-FULL-GATE-EXEC — local five-binary gate on the CB55 package (2026-10-31) | CHANGELOG; tracker; retained Review records |
| `Architecture_M6_CP3_TB55_API_Display_Full_Gate_Case_Manifest.tsv` | 859 | superseded per-turn case manifest | 858 data rows | CHANGELOG |
| `Architecture_M6_CP3_TB55_API_Display_Full_Gate_Local_Test_Report_20261031.md` | 35 | Test + Benchmark record/plan | M6-CP3-TB55-API-DISPLAY-FULL-GATE-EXEC — local five-binary gate on the CB56 package (2026-10-31) | CHANGELOG; tracker |
| `Architecture_M6_CP3_TB56_O2_Full_Gate_Case_Manifest.tsv` | 860 | superseded per-turn case manifest | 859 data rows | retained Review records |
| `Architecture_M6_CP3_TB56_O2_Full_Gate_Local_Test_Report_20261031.md` | 34 | Test + Benchmark record/plan | M6-CP3-TB56-O2-FULL-GATE-EXEC — local five-binary gate on the CB57 package (2026-10-31) | CHANGELOG; tracker |
| `Architecture_M6_CP3_TB57_Diag_Retain_Full_Gate_Case_Manifest.tsv` | 862 | superseded per-turn case manifest | 861 data rows | retained Review records |
| `Architecture_M6_CP3_TB63_P13_Census_Full_Gate_Execution_Report_20261031.md` | 33 | Test + Benchmark record/plan | TB63 — CB64 Linux full gate and P13 census (2026-10-31) | CHANGELOG; tracker; TODO |
| `Architecture_M6_CP3_TB64_P13_Canonical_Dyadic_Full_Gate_Execution_Report_20261101.md` | 43 | Test + Benchmark record/plan | TB64 — CB65 immutable Linux full gate and P13 census (2026-11-01) | CHANGELOG; tracker; TODO; retained Review records |
| `Architecture_M6_CP3_TB65_P13_Slit_Full_Gate_Execution_Report_20261101.md` | 47 | Test + Benchmark record/plan | TB65 — slit-cycle-basis immutable Linux full gate and P13 census (2026-11-01) | CHANGELOG; tracker; TODO |
| `Architecture_M6_CP3_TB66_P13_Arrangement_Terminal_Full_Gate_Execution_Report_20261101.md` | 38 | Test + Benchmark record/plan | TB66 — arrangement-terminal immutable Linux full gate and P13 census (2026-11-01) | CHANGELOG; tracker; TODO; handoff |
| `Architecture_M6_CP3_TB67_P13_Arrangement_Wedge_Full_Gate_Execution_Report_20261101.md` | 36 | Test + Benchmark record/plan | TB67 — immutable arrangement-wedge full gate and production census (2026-11-01) | CHANGELOG; tracker; TODO; handoff |
| `Architecture_M6_CP3_TB68_P13_Completion_Graph_Full_Gate_Execution_Report_20261101.md` | 16 | Test + Benchmark record/plan | TB68 — immutable completion-graph full gate and independent production census (2026-11-01) | CHANGELOG; tracker; TODO; handoff |
| `Architecture_M6_CP3_TB69_P13_Completion_Embedding_Full_Gate_Execution_Report_20261102.md` | 19 | Test + Benchmark record/plan | TB69 — immutable completion embedding full gate and production census (2026-11-02) | CHANGELOG; tracker; TODO; handoff |
| `Architecture_M6_CP3_TB70_P13_Patch_Side_Start_Full_Gate_Execution_Report_20261102.md` | 22 | Test + Benchmark record/plan | TB70 — patch side-zero start full gate and direct-production census (2026-11-02) | CHANGELOG; tracker; TODO; handoff |
| `Architecture_M6_CP3_TB71_P13_Needle_Grid_Full_Gate_Execution_Report_20261102.md` | 23 | Test + Benchmark record/plan | TB71 — needle-grid boundary-search full gate and production census (2026-11-02) | CHANGELOG; tracker; TODO; handoff |
| `Architecture_M6_CP3_TB72A_Orchestration_Record_20261102.md` | 15 | Test + Benchmark record/plan | M6-CP3 TB72A — corrected full-gate dispatch (2026-11-02) | CHANGELOG; TODO; handoff |
| `Architecture_M6_CP3_TB72_Orchestration_Failure_Report_20261102.md` | 44 | Test + Benchmark record/plan | M6-CP3 TB72 — immutable gate orchestration failure (2026-11-02) | CHANGELOG; tracker; TODO; handoff |
| `Architecture_M6_CP3_TB73_P13_Node_Stitch_Key_Full_Gate_Execution_Report_20261103.md` | 11 | Test + Benchmark record/plan | TB73 immutable CB79 full gate — gate and census verified (2026-11-03) | CHANGELOG; tracker; TODO; handoff |
| `Architecture_M6_CP3_TB74_P13_Rail_Binding_Once_Full_Gate_Execution_Report_20261103.md` | 13 | Test + Benchmark record/plan | TB74 immutable CB80 full gate — independent execution report (2026-11-03) | CHANGELOG; tracker; TODO |
| `Architecture_M6_CP3_TB75_P13_Lent_Projection_Cache_Full_Gate_Execution_Report_20261104.md` | 13 | Test + Benchmark record/plan | TB75 immutable CB81 full gate — independent execution report (2026-11-04) | CHANGELOG; tracker; TODO |
| `Architecture_M6_CP3_TB76_P13_Linux_Vase_Independent_Review_Decision_20261104.md` | 46 | Review/definition/audit record | TB76 independent review — Linux Vase census mismatch (2026-11-04) | CHANGELOG; tracker; TODO; handoff; retained Review records |
| `Architecture_M6_CP3_TB76_P13_Optimizer_Source_Query_Full_Gate_Execution_Report_20261104.md` | 20 | Test + Benchmark record/plan | TB76 CB83 immutable full-gate and production census — independent execution report (2026-11-04) | CHANGELOG; tracker; TODO; handoff |
| `Architecture_M6_CP3_TB77_P13_Pre_Assembly_Cost_Full_Gate_Execution_Report_20261104.md` | 27 | Test + Benchmark record/plan | TB77 — CB86 immutable full gate and production census (2026-11-04) | CHANGELOG; tracker; TODO; handoff |
| `Architecture_M6_CP3_TB78_P13_Census_Path_Cost_Full_Gate_Execution_Report_20261104.md` | 33 | Test + Benchmark record/plan | TB78 — CB88 immutable full gate and production census (2026-11-04) | CHANGELOG; tracker; TODO; handoff |
| `Architecture_M6_CP3_TB78_REV_P13_Census_Count_Review_WIP_20261104.md` | 54 | working record | TB78 census-count discrepancy — independent Review work in progress (2026-11-04) | TODO; handoff; retained Review records |
| `Architecture_M6_CP3_TB79_P13_Platform_Digest_Full_Gate_Execution_Report_20261105.md` | 44 | Test + Benchmark record/plan | TB79 — immutable platform-digest full gate and production census (2026-11-05 UTC) | CHANGELOG; tracker; TODO; handoff; ORIENTATION |
| `Architecture_M6_CP3_TB80_P13_Arrangement_Cell_Order_Full_Gate_Execution_Report_20261105.md` | 68 | Test + Benchmark record/plan | TB80 — CB90 immutable full gate and cross-platform census (2026-11-05 UTC) | CHANGELOG; tracker; TODO; handoff; retained Review records |
| `Architecture_M6_CP3_TB80_REV_Final_Validation_Cost_Gate_Adjudication_20261105.md` | 54 | Review/definition/audit record | TB80 independent Review — final validation cost gate (2026-11-05) | CHANGELOG; tracker; TODO; handoff; retained Review records |
| `Architecture_M6_CP3_TB82_P13_Source_Vertex_Fan_Seed_Full_Gate_Execution_Report_20261105.md` | 46 | Test + Benchmark record/plan | TB82 — Source-vertex fan-seed immutable full gate and census (2026-11-05) | CHANGELOG; tracker; TODO |
| `Architecture_M6_CP3_TB82_P13_Source_Vertex_Fan_Seed_Full_Gate_Execution_WIP_20261105.md` | 36 | working record | TB82 — immutable full-gate execution launch record (historical; closed 2026-11-05) | CHANGELOG; TODO; handoff; retained Review records |
| `Architecture_M6_CP3_TB83_P13_Embedding_Predicate_Full_Gate_Execution_Report_20261106.md` | 31 | Test + Benchmark record/plan | TB83 — Own-plane embedding predicate immutable full gate and census (2026-11-06 UTC) | CHANGELOG; tracker; TODO; handoff |
| `Architecture_M6_CP3_TB83_P13_Embedding_Predicate_Full_Gate_Execution_WIP_20261105.md` | 26 | working record | TB83 — immutable execution continuation (2026-11-05) | CHANGELOG; TODO; handoff; retained Review records |
| `Architecture_M6_CP3_TB84_P13_Contact_Predicates_Full_Gate_Execution_Report_20261108.md` | 28 | Test + Benchmark record/plan | TB84 — Contact predicates immutable gate and production census (2026-11-08 UTC) | CHANGELOG; tracker; TODO; handoff |
| `Architecture_M6_CP3_TB85_P13_Concave_Quality_Metrics_Full_Gate_Execution_Report_20261108.md` | 29 | Test + Benchmark record/plan | TB85 — concave-quality evaluator immutable gate and production census (2026-11-08 UTC) | CHANGELOG; tracker; TODO; handoff |
| `Architecture_M6_CP3_TB86_P13_A3_Span_Coverage_Full_Gate_Execution_Report_20261108.md` | 34 | Test + Benchmark record/plan | TB86 — A3 span-coverage receipt full-gate and census (2026-11-08 UTC) | CHANGELOG; tracker; TODO; handoff |
| `Architecture_M6_CP3_TB86_P13_A3_Span_Coverage_Full_Gate_Execution_WIP_20261108.md` | 31 | working record | TB86 — immutable full-gate execution continuation (2026-11-08 UTC) | CHANGELOG; TODO; handoff; retained Review records |
| `Architecture_M6_CP3_TB87_P13_A3_Source_Rim_Intervals_Full_Gate_Execution_Report_20261108.md` | 31 | Test + Benchmark record/plan | TB87 — A3 source-rim intervals, immutable full-gate and census (2026-11-08 UTC) | CHANGELOG; tracker; TODO; handoff |
| `Architecture_M6_CP3_TB87_P13_A3_Source_Rim_Intervals_Full_Gate_Execution_WIP_20261108.md` | 40 | working record | TB87 — immutable full-gate/census execution continuation (2026-11-08 UTC) | CHANGELOG; tracker; TODO; handoff; retained Review records |
| `Architecture_M6_CP3_TB87_REV_P13_A3_Observed_Route_Oracle_Exact.diff` | 15 | exact patch (applied or superseded; landed source is in git history) | 1 files, +3 −1 | CHANGELOG; TODO; retained Review records |
| `Architecture_M6_CP3_TB88_P13_A3_Observed_Route_Orientation_Full_Gate_Execution_Report_20261108.md` | 28 | Test + Benchmark record/plan | TB88 — observed-route orientation immutable full gate and census (2026-11-08 UTC) | CHANGELOG; tracker; TODO |
| `Architecture_M6_CP3_TB88_P13_A3_Observed_Route_Orientation_Full_Gate_Execution_WIP_20261108.md` | 25 | working record | TB88 — artifact-only gate and census execution (WIP; 2026-11-08 UTC) | CHANGELOG; retained Review records |
| `Architecture_M6_CP3_TB89_P13_A3_Partition_Stable_Metric_Full_Gate_Execution_Report_20261108.md` | 28 | Test + Benchmark record/plan | TB89 — exact partition-stable metric immutable full gate and census (2026-11-08 UTC) | CHANGELOG; tracker; TODO |
| `Architecture_M6_CP3_TB8_Source_Entity_Equivalence_Harvest_Record_20261016.md` | 9 | Review/definition/audit record | TB8 source-entity equivalence harvest — 2026-10-16 | CHANGELOG; tracker; TODO; handoff; retained Review records |
| `Architecture_M6_CP3_TB90_P13_A3_Partition_Stable_Count_Switch_Full_Gate_Execution_Report_20261108.md` | 35 | Test + Benchmark record/plan | TB90 — partition-stable D7 scheduler count switch immutable full gate and census (2026-11-08 UTC) | CHANGELOG; tracker; TODO |
| `Architecture_M6_CP3_TB91_P13_A3_Metric_Breakpoint_Placement_Full_Gate_Execution_Report_20261109.md` | 30 | Test + Benchmark record/plan | TB91 — immutable metric-breakpoint placement full gate and production census (2026-11-09 UTC) | CHANGELOG; tracker; TODO; retained Review records |
| `Architecture_M6_DEFN_R3_CP1_Product_Separation_Plan.md` | 110 | consumed plan | M6-DEFN-R3 — CP1 A6/A7 Product Separation — Definition Plan | M6_Consolidated_Record; retained Review records |
| `Architecture_M6_DEFN_R4_CP1_A7_Thin_Adapter_G4B002_Definition_Plan.md` | 132 | consumed plan | M6-DEFN-R4 — A7 Product, Thin Adapter, and the `G4-B002` A6 Boundary — Definition Plan | M6_Consolidated_Record; retained Review records |
| `Architecture_M6_DEFN_R4_D4_Consumer_Census.md` | 1214 | Review/definition/audit record | D4 Consumer and Frozen-Assertion Census | retained Review records |
| `Architecture_M6_DEFN_R5_CP3_Entry_Definition_Plan.md` | 64 | consumed plan | `M6-DEFN-R5` — CP3-Entry Definition Plan | CHANGELOG; retained Review records |
| `Architecture_M6_DEFN_R5_R1_CP3_Entry_Recovery_Definition_Plan.md` | 42 | consumed plan | `M6-DEFN-R5-R1` — CP3 Entry Recovery Definition Plan | retained Review records |
| `Architecture_M6_DEFN_R5_R3_CP3_Entry_Recovery_Definition_Plan.md` | 13 | consumed plan | M6-DEFN-R5-R3 — R2 Recovery Definition Plan (HELD implementation) | CHANGELOG; M6_Consolidated_Record; retained Review records |
| `Architecture_M6_DEFN_R5_R4_CP3_Entry_Recovery_Definition_Record.md` | 114 | Review/definition/audit record | M6-DEFN-R5-R4 — RA-41 candidate, recovery Definition (runtime-free) | CHANGELOG; retained Review records |
| `Architecture_M6_DEFN_R5_R4_DIAG_Failure_Carrier_Inventory.tsv` | 40 | per-turn data/receipt | 39 data rows | retained Review records |
| `Architecture_M6_DEFN_R5_R4_Recovery_Definition_Plan.md` | 36 | consumed plan | M6-DEFN-R5-R4 — RA-41 candidate Definition plan (runtime-free) | CHANGELOG |
| `Architecture_M6_TB57_Diag_Retain_Full_Gate_Local_Test_Report_20261031.md` | 45 | Test + Benchmark record/plan | M6-TB57-DIAG-RETAIN-FULL-GATE-EXEC — local five-binary gate on the CB58 package (2026-10-31) | CHANGELOG; tracker; retained Review records |
| `Architecture_M6_TB58_Diag_Retain_Display_Full_Gate_Case_Manifest.tsv` | 864 | superseded per-turn case manifest | 863 data rows | retained Review records |
| `Architecture_M6_TB58_Diag_Retain_Display_Full_Gate_Local_Test_Report_20261031.md` | 34 | Test + Benchmark record/plan | M6-TB58-DIAG-RETAIN-DISPLAY-FULL-GATE-EXEC — local five-binary gate on the CB59 package (2026-10-31) | CHANGELOG; tracker |
| `Architecture_M6_TB59_Diag_Retain_CLI_Sidecar_Local_Test_Report_20261031.md` | 27 | Test + Benchmark record/plan | M6-TB59-DIAG-RETAIN-CLI-EXEC — CLI sidecar check runs on the CB60 package (2026-10-31) | CHANGELOG; tracker |
| `Architecture_M6_TB61_Diag_Retain_Linux_Full_Gate_Execution_Report_20261031.md` | 48 | Test + Benchmark record/plan | M6 TB61 — DIAG-RETAIN Linux full-gate execution (2026-10-31) | CHANGELOG; TODO |
| `Architecture_M6_TB61_Linux_Full_Gate_Independent_Review_20261031.md` | 51 | Review/definition/audit record | TB61 — Independent Linux full-gate review (2026-10-31) | CHANGELOG; TODO |
| `Architecture_M6_TB62_Execution_Continuation_20261031.md` | 11 | working record | TB62 Linux CLI/GUI full-gate — closed continuation pointer (2026-10-31) | CHANGELOG; TODO |
| `Architecture_M6_TB62_Linux_CLI_GUI_Full_Gate_Execution_Plan_20261031.md` | 20 | Test + Benchmark record/plan | TB62 — Linux CLI/GUI immutable full-gate execution plan (2026-10-31) | CHANGELOG |
| `Architecture_M6_TB62_Linux_CLI_GUI_Full_Gate_Execution_Report_20261031.md` | 30 | Test + Benchmark record/plan | TB62 — immutable Linux CLI/GUI full-gate execution and evidence adjudication (2026-10-31) | CHANGELOG; TODO |
| `Architecture_M6_TB64_P13_Cylinder_Promoted_Full_Gate_Case_Manifest.tsv` | 865 | superseded per-turn case manifest | 864 data rows | superseded per-turn gate manifest; TB64 outcome in CHANGELOG/tracker |
| `Architecture_M6_TB64_P13_Dyadic_Exit_Full_Gate_Case_Manifest.tsv` | 867 | superseded per-turn case manifest | 866 data rows | retained Review records |
| `Architecture_M6_TB65_P13_Slit_Cycle_Basis_Full_Gate_Case_Manifest.tsv` | 870 | superseded per-turn case manifest | 869 data rows | retained Review records |
| `Architecture_M6_TB67_P13_Arrangement_Wedge_Full_Gate_Case_Manifest.tsv` | 872 | superseded per-turn case manifest | 871 data rows | handoff; retained Review records |
| `Architecture_M6_TB68_P13_Completion_Graph_Reuse_Full_Gate_Case_Manifest.tsv` | 874 | superseded per-turn case manifest | 873 data rows | handoff; retained Review records |
| `Architecture_M6_TB69_P13_Completion_Embedding_Full_Gate_Case_Manifest.tsv` | 879 | superseded per-turn case manifest | 878 data rows | handoff; retained Review records |
| `Architecture_M6_TB70_P13_Patch_Side_Start_Full_Gate_Case_Manifest.tsv` | 881 | superseded per-turn case manifest | 880 data rows | handoff; retained Review records |
| `Architecture_M6_TB71_P13_Needle_Grid_Full_Gate_Case_Manifest.tsv` | 882 | superseded per-turn case manifest | 881 data rows | handoff; retained Review records |
| `Architecture_M6_TB72_P13_Support_Chord_Full_Gate_Case_Manifest.tsv` | 884 | superseded per-turn case manifest | 883 data rows | handoff; retained Review records |
| `Architecture_M6_TB73_P13_Node_Stitch_Key_Full_Gate_Case_Manifest.tsv` | 887 | superseded per-turn case manifest | 886 data rows | handoff; retained Review records |
| `Architecture_M6_TB74_P13_Rail_Binding_Once_Full_Gate_Case_Manifest.tsv` | 889 | superseded per-turn case manifest | 888 data rows | handoff; retained Review records |
| `Architecture_M6_TB75_P13_Lent_Projection_Cache_Full_Gate_Case_Manifest.tsv` | 891 | superseded per-turn case manifest | 890 data rows | handoff; retained Review records |
| `Architecture_M6_TB76_P13_Optimizer_Source_Query_Full_Gate_Case_Manifest.tsv` | 894 | superseded per-turn case manifest | 893 data rows | handoff; retained Review records |
| `Architecture_M6_TB77_P13_Pre_Assembly_Cost_Full_Gate_Case_Manifest.tsv` | 897 | superseded per-turn case manifest | 896 data rows | handoff; retained Review records |
| `Architecture_M6_TB78_P13_Census_Path_Cost_Full_Gate_Case_Manifest.tsv` | 900 | superseded per-turn case manifest | 899 data rows | handoff; retained Review records |
| `Architecture_M6_TB82_P13_Vertex_Fan_Seeds_Full_Gate_Case_Manifest.tsv` | 902 | superseded per-turn case manifest | 901 data rows | TODO; handoff; retained Review records |
| `Architecture_M6_TB83_P13_Embedding_Predicate_Full_Gate_Case_Manifest.tsv` | 904 | superseded per-turn case manifest | 903 data rows | TODO; handoff; retained Review records |
| `Architecture_M6_TB84_P13_Contact_Predicates_Full_Gate_Case_Manifest.tsv` | 907 | superseded per-turn case manifest | 906 data rows | TODO; handoff; retained Review records |
| `Architecture_M6_TB85_P13_Concave_Quality_Metrics_Full_Gate_Case_Manifest.tsv` | 909 | superseded per-turn case manifest | 908 data rows | TODO; handoff; retained Review records |
| `Architecture_M6_TB86_P13_A3_Span_Coverage_Full_Gate_Case_Manifest.tsv` | 910 | superseded per-turn case manifest | 909 data rows | CHANGELOG; TODO; retained Review records |
| `Architecture_M6_TB87_P13_A3_Source_Rim_Intervals_Full_Gate_Case_Manifest.tsv` | 911 | superseded per-turn case manifest | 910 data rows | CHANGELOG; TODO; retained Review records |
| `Architecture_M6_TB89_P13_A3_Partition_Stable_Count_Full_Gate_Case_Manifest.tsv` | 914 | superseded per-turn case manifest | 913 data rows | TODO; retained Review records |
| `Architecture_M6_TB90_P13_A3_Partition_Stable_Count_Switch_Full_Gate_Case_Manifest.tsv` | 915 | superseded per-turn case manifest | 914 data rows | TODO; retained Review records |
| `Architecture_M6_TB91_P13_A3_Metric_Breakpoint_Placement_Full_Gate_Case_Manifest.tsv` | 918 | superseded per-turn case manifest | 917 data rows | TODO; retained Review records |
| `Architecture_M6_TOOL_VIS_Field_Network_GUI_Layer_Record_20261021.md` | 31 | Review/definition/audit record | Interim tooling turn — A2a field-aligned network in the GUI (2026-10-21) | CHANGELOG |

**Retired earlier without an index entry** (indexed here per `CLEAN_UP_POLICY.md` step 3; recover with `git show 9ca6aaa7d^:.agents/Directional/<name>`):

| Folded filename | Lines | Role | Verdict / title | Retained home |
|---|---:|---|---|---|
| `Architecture_M6_CP3_CB94_P13_Quad_Self_Intersection_Corner_Order.diff` | 88 | superseded exact patch, removed at `9ca6aaa7d` | RA-208's CB94; replaced by RA-209's CB94 single-writer patch | `Architecture_M6_CP3_DEFN_P13_Completed_Mesh_Orientation_Review_Single_Writer_Own_Plane_20261105.md` (RA-209) |
| `Architecture_M6_TB83_P13_Orientation_Predicate_Full_Gate_Case_Manifest.tsv` | 904 | superseded case manifest, removed at `9ca6aaa7d` | RA-208's TB83 manifest; replaced by RA-209's TB83 | RA-209; CHANGELOG |

## M6 moved-record map (2026-11-09)

By user instruction, the 231 remaining standalone `Architecture_M6*` Review, definition and audit records were consolidated into five volumes. Each is kept verbatim as one section; only heading levels and links to other moved records changed. None was pruned, because none was already documented elsewhere (verbatim-line coverage at most 27%). Standalone files that remain: `Architecture_M6_Frozen_Definitions.md` (normative), the current authority (RA-218, TB92 report, CB109 record), the next-turn patches, and the data files (case manifests, deferred ledger, census manifest, tool-read and evidence TSVs). Volumes: [M6_Consolidated_Record_Vol_A_Definitions_CP1_CP2.md](M6_Consolidated_Record_Vol_A_Definitions_CP1_CP2.md), [M6_Consolidated_Record_Vol_B_CP3_R_Series.md](M6_Consolidated_Record_Vol_B_CP3_R_Series.md), [M6_Consolidated_Record_Vol_C_CP3_Gate_Turns.md](M6_Consolidated_Record_Vol_C_CP3_Gate_Turns.md), [M6_Consolidated_Record_Vol_D1_CP3_P13_to_20261103.md](M6_Consolidated_Record_Vol_D1_CP3_P13_to_20261103.md), [M6_Consolidated_Record_Vol_D2_CP3_P13_from_20261104.md](M6_Consolidated_Record_Vol_D2_CP3_P13_from_20261104.md).

| Former file | Volume section |
|---|---|
| `Architecture_M6_CP1_CB12_Close_Out_Code_Build_Plan.md` | [Vol_A_Definitions_CP1_CP2](M6_Consolidated_Record_Vol_A_Definitions_CP1_CP2.md#architecture_m6_cp1_cb12_close_out_code_build_planmd) |
| `Architecture_M6_CP1_CB12_Close_Stop_Review_Record.md` | [Vol_A_Definitions_CP1_CP2](M6_Consolidated_Record_Vol_A_Definitions_CP1_CP2.md#architecture_m6_cp1_cb12_close_stop_review_recordmd) |
| `Architecture_M6_CP1_TB10_A5V_R1_Review_Record.md` | [Vol_A_Definitions_CP1_CP2](M6_Consolidated_Record_Vol_A_Definitions_CP1_CP2.md#architecture_m6_cp1_tb10_a5v_r1_review_recordmd) |
| `Architecture_M6_CP1_TB10_A5V_Review_Record.md` | [Vol_A_Definitions_CP1_CP2](M6_Consolidated_Record_Vol_A_Definitions_CP1_CP2.md#architecture_m6_cp1_tb10_a5v_review_recordmd) |
| `Architecture_M6_CP1_TB11_G4_R1_Review_Record.md` | [Vol_A_Definitions_CP1_CP2](M6_Consolidated_Record_Vol_A_Definitions_CP1_CP2.md#architecture_m6_cp1_tb11_g4_r1_review_recordmd) |
| `Architecture_M6_CP1_TB11_G4_Review_Record.md` | [Vol_A_Definitions_CP1_CP2](M6_Consolidated_Record_Vol_A_Definitions_CP1_CP2.md#architecture_m6_cp1_tb11_g4_review_recordmd) |
| `Architecture_M6_CP1_TB12_Close_R1_Review_Record.md` | [Vol_A_Definitions_CP1_CP2](M6_Consolidated_Record_Vol_A_Definitions_CP1_CP2.md#architecture_m6_cp1_tb12_close_r1_review_recordmd) |
| `Architecture_M6_CP1_TB7_A6_Review_Record.md` | [Vol_A_Definitions_CP1_CP2](M6_Consolidated_Record_Vol_A_Definitions_CP1_CP2.md#architecture_m6_cp1_tb7_a6_review_recordmd) |
| `Architecture_M6_CP1_TB8_A6_Review_Record.md` | [Vol_A_Definitions_CP1_CP2](M6_Consolidated_Record_Vol_A_Definitions_CP1_CP2.md#architecture_m6_cp1_tb8_a6_review_recordmd) |
| `Architecture_M6_CP1_TB9_A7_R1_Review_Record.md` | [Vol_A_Definitions_CP1_CP2](M6_Consolidated_Record_Vol_A_Definitions_CP1_CP2.md#architecture_m6_cp1_tb9_a7_r1_review_recordmd) |
| `Architecture_M6_CP1_TB9_A7_Review_Record.md` | [Vol_A_Definitions_CP1_CP2](M6_Consolidated_Record_Vol_A_Definitions_CP1_CP2.md#architecture_m6_cp1_tb9_a7_review_recordmd) |
| `Architecture_M6_CP2_CB2_Coverage_Code_Build_Plan.md` | [Vol_A_Definitions_CP1_CP2](M6_Consolidated_Record_Vol_A_Definitions_CP1_CP2.md#architecture_m6_cp2_cb2_coverage_code_build_planmd) |
| `Architecture_M6_CP2_Close_Review_Record.md` | [Vol_A_Definitions_CP1_CP2](M6_Consolidated_Record_Vol_A_Definitions_CP1_CP2.md#architecture_m6_cp2_close_review_recordmd) |
| `Architecture_M6_CP2_TB1_Verifier_R1_Review_Record.md` | [Vol_A_Definitions_CP1_CP2](M6_Consolidated_Record_Vol_A_Definitions_CP1_CP2.md#architecture_m6_cp2_tb1_verifier_r1_review_recordmd) |
| `Architecture_M6_CP2_TB1_Verifier_R2_Review_Record.md` | [Vol_A_Definitions_CP1_CP2](M6_Consolidated_Record_Vol_A_Definitions_CP1_CP2.md#architecture_m6_cp2_tb1_verifier_r2_review_recordmd) |
| `Architecture_M6_CP2_TB1_Verifier_Review_Record.md` | [Vol_A_Definitions_CP1_CP2](M6_Consolidated_Record_Vol_A_Definitions_CP1_CP2.md#architecture_m6_cp2_tb1_verifier_review_recordmd) |
| `Architecture_M6_CP3_CB19A_Factory_Rejection_Site_Code_Build_Record_20261020.md` | [Vol_C_CP3_Gate_Turns](M6_Consolidated_Record_Vol_C_CP3_Gate_Turns.md#architecture_m6_cp3_cb19a_factory_rejection_site_code_build_record_20261020md) |
| `Architecture_M6_CP3_CB19A_Factory_Rejection_Site_Review_Decision.md` | [Vol_C_CP3_Gate_Turns](M6_Consolidated_Record_Vol_C_CP3_Gate_Turns.md#architecture_m6_cp3_cb19a_factory_rejection_site_review_decisionmd) |
| `Architecture_M6_CP3_CB19_Factory_Rejection_Site_Compile_Failure_20261020.md` | [Vol_C_CP3_Gate_Turns](M6_Consolidated_Record_Vol_C_CP3_Gate_Turns.md#architecture_m6_cp3_cb19_factory_rejection_site_compile_failure_20261020md) |
| `Architecture_M6_CP3_CB19_Factory_Rejection_Site_Compile_Review_Decision.md` | [Vol_C_CP3_Gate_Turns](M6_Consolidated_Record_Vol_C_CP3_Gate_Turns.md#architecture_m6_cp3_cb19_factory_rejection_site_compile_review_decisionmd) |
| `Architecture_M6_CP3_CB1_Entry_R2_Recovery_Code_Build_Plan.md` | [Vol_C_CP3_Gate_Turns](M6_Consolidated_Record_Vol_C_CP3_Gate_Turns.md#architecture_m6_cp3_cb1_entry_r2_recovery_code_build_planmd) |
| `Architecture_M6_CP3_CB20A_Gauge_Pin_Domain_Review_Decision.md` | [Vol_C_CP3_Gate_Turns](M6_Consolidated_Record_Vol_C_CP3_Gate_Turns.md#architecture_m6_cp3_cb20a_gauge_pin_domain_review_decisionmd) |
| `Architecture_M6_CP3_CB20_Gauge_Pin_Domain_Code_Build_Stop_Record_20261020.md` | [Vol_C_CP3_Gate_Turns](M6_Consolidated_Record_Vol_C_CP3_Gate_Turns.md#architecture_m6_cp3_cb20_gauge_pin_domain_code_build_stop_record_20261020md) |
| `Architecture_M6_CP3_CB20_Gauge_Pin_Domain_Compile_Stop_Review_Decision.md` | [Vol_C_CP3_Gate_Turns](M6_Consolidated_Record_Vol_C_CP3_Gate_Turns.md#architecture_m6_cp3_cb20_gauge_pin_domain_compile_stop_review_decisionmd) |
| `Architecture_M6_CP3_CB21_Torus_Witness_Scope_Review_Decision_20261021.md` | [Vol_C_CP3_Gate_Turns](M6_Consolidated_Record_Vol_C_CP3_Gate_Turns.md#architecture_m6_cp3_cb21_torus_witness_scope_review_decision_20261021md) |
| `Architecture_M6_CP3_CB22A_Torus_A5_Isolation_Site_Formatter_Review_Decision.md` | [Vol_C_CP3_Gate_Turns](M6_Consolidated_Record_Vol_C_CP3_Gate_Turns.md#architecture_m6_cp3_cb22a_torus_a5_isolation_site_formatter_review_decisionmd) |
| `Architecture_M6_CP3_CB22B_Torus_A5_Site_Test_Messages_Review_Decision.md` | [Vol_C_CP3_Gate_Turns](M6_Consolidated_Record_Vol_C_CP3_Gate_Turns.md#architecture_m6_cp3_cb22b_torus_a5_site_test_messages_review_decisionmd) |
| `Architecture_M6_CP3_CB22_Torus_A5_Isolation_Site_Compile_Stop_Review_Decision.md` | [Vol_C_CP3_Gate_Turns](M6_Consolidated_Record_Vol_C_CP3_Gate_Turns.md#architecture_m6_cp3_cb22_torus_a5_isolation_site_compile_stop_review_decisionmd) |
| `Architecture_M6_CP3_CB27A_Wedge_Membership_Witness_Design_Review_Decision_20261022.md` | [Vol_C_CP3_Gate_Turns](M6_Consolidated_Record_Vol_C_CP3_Gate_Turns.md#architecture_m6_cp3_cb27a_wedge_membership_witness_design_review_decision_20261022md) |
| `Architecture_M6_CP3_CB27_A7_Certified_Seam_Negative_Oracles_Review_Decision_20261022.md` | [Vol_C_CP3_Gate_Turns](M6_Consolidated_Record_Vol_C_CP3_Gate_Turns.md#architecture_m6_cp3_cb27_a7_certified_seam_negative_oracles_review_decision_20261022md) |
| `Architecture_M6_CP3_CB28_Factory_Error_Diagnostics_Review_Decision_20261022.md` | [Vol_C_CP3_Gate_Turns](M6_Consolidated_Record_Vol_C_CP3_Gate_Turns.md#architecture_m6_cp3_cb28_factory_error_diagnostics_review_decision_20261022md) |
| `Architecture_M6_CP3_CB92_P13_Source_Vertex_Fan_Seed_Identity_Plan_20261105.md` | [Vol_D2_CP3_P13_from_20261104](M6_Consolidated_Record_Vol_D2_CP3_P13_from_20261104.md#architecture_m6_cp3_cb92_p13_source_vertex_fan_seed_identity_plan_20261105md) |
| `Architecture_M6_CP3_DEFN_ISO_A_Seam_Node_Representative_Census_Review_Decision_20261021.md` | [Vol_C_CP3_Gate_Turns](M6_Consolidated_Record_Vol_C_CP3_Gate_Turns.md#architecture_m6_cp3_defn_iso_a_seam_node_representative_census_review_decision_20261021md) |
| `Architecture_M6_CP3_DEFN_Legacy_Matching_Path_Disposition_Review_Decision_20261026.md` | [Vol_C_CP3_Gate_Turns](M6_Consolidated_Record_Vol_C_CP3_Gate_Turns.md#architecture_m6_cp3_defn_legacy_matching_path_disposition_review_decision_20261026md) |
| `Architecture_M6_CP3_DEFN_M1_Certificate_Pair_Binding_Precedence_20261023.md` | [Vol_C_CP3_Gate_Turns](M6_Consolidated_Record_Vol_C_CP3_Gate_Turns.md#architecture_m6_cp3_defn_m1_certificate_pair_binding_precedence_20261023md) |
| `Architecture_M6_CP3_DEFN_M1_Certificate_Pair_Binding_Precedence_Review_Decision_20261023.md` | [Vol_C_CP3_Gate_Turns](M6_Consolidated_Record_Vol_C_CP3_Gate_Turns.md#architecture_m6_cp3_defn_m1_certificate_pair_binding_precedence_review_decision_20261023md) |
| `Architecture_M6_CP3_DEFN_O2_No_Atlas_Entry_Gate_20261031.md` | [Vol_C_CP3_Gate_Turns](M6_Consolidated_Record_Vol_C_CP3_Gate_Turns.md#architecture_m6_cp3_defn_o2_no_atlas_entry_gate_20261031md) |
| `Architecture_M6_CP3_DEFN_P13_A3_Metric_Breakpoint_Placement_Adversarial_Review_20261108.md` | [Vol_D2_CP3_P13_from_20261104](M6_Consolidated_Record_Vol_D2_CP3_P13_from_20261104.md#architecture_m6_cp3_defn_p13_a3_metric_breakpoint_placement_adversarial_review_20261108md) |
| `Architecture_M6_CP3_DEFN_P13_A3_Metric_Breakpoint_Placement_Review_20261108.md` | [Vol_D2_CP3_P13_from_20261104](M6_Consolidated_Record_Vol_D2_CP3_P13_from_20261104.md#architecture_m6_cp3_defn_p13_a3_metric_breakpoint_placement_review_20261108md) |
| `Architecture_M6_CP3_DEFN_P13_A3_Partition_Stable_Metric_Adversarial_Review_20261108.md` | [Vol_D2_CP3_P13_from_20261104](M6_Consolidated_Record_Vol_D2_CP3_P13_from_20261104.md#architecture_m6_cp3_defn_p13_a3_partition_stable_metric_adversarial_review_20261108md) |
| `Architecture_M6_CP3_DEFN_P13_A3_Partition_Stable_Metric_Review_20261108.md` | [Vol_D2_CP3_P13_from_20261104](M6_Consolidated_Record_Vol_D2_CP3_P13_from_20261104.md#architecture_m6_cp3_defn_p13_a3_partition_stable_metric_review_20261108md) |
| `Architecture_M6_CP3_DEFN_P13_A3_Recorded_Boundary_Intervals_Adversarial_Review_20261108.md` | [Vol_D2_CP3_P13_from_20261104](M6_Consolidated_Record_Vol_D2_CP3_P13_from_20261104.md#architecture_m6_cp3_defn_p13_a3_recorded_boundary_intervals_adversarial_review_20261108md) |
| `Architecture_M6_CP3_DEFN_P13_A4_A2b_Chain_Segmentation_Falsifier_20261108.md` | [Vol_D2_CP3_P13_from_20261104](M6_Consolidated_Record_Vol_D2_CP3_P13_from_20261104.md#architecture_m6_cp3_defn_p13_a4_a2b_chain_segmentation_falsifier_20261108md) |
| `Architecture_M6_CP3_DEFN_P13_A4_A2b_Disc_Producer_Runtime_Free_Resolution_20261108.md` | [Vol_D2_CP3_P13_from_20261104](M6_Consolidated_Record_Vol_D2_CP3_P13_from_20261104.md#architecture_m6_cp3_defn_p13_a4_a2b_disc_producer_runtime_free_resolution_20261108md) |
| `Architecture_M6_CP3_DEFN_P13_A4_A2b_Production_Contract_Audit_20261108.md` | [Vol_D2_CP3_P13_from_20261104](M6_Consolidated_Record_Vol_D2_CP3_P13_from_20261104.md#architecture_m6_cp3_defn_p13_a4_a2b_production_contract_audit_20261108md) |
| `Architecture_M6_CP3_DEFN_P13_A4_A2b_Readonly_Authority_Extraction_Review_20261108.md` | [Vol_D2_CP3_P13_from_20261104](M6_Consolidated_Record_Vol_D2_CP3_P13_from_20261104.md#architecture_m6_cp3_defn_p13_a4_a2b_readonly_authority_extraction_review_20261108md) |
| `Architecture_M6_CP3_DEFN_P13_A4_A2b_Three_Side_Feasibility_Continuation_20261108.md` | [Vol_D2_CP3_P13_from_20261104](M6_Consolidated_Record_Vol_D2_CP3_P13_from_20261104.md#architecture_m6_cp3_defn_p13_a4_a2b_three_side_feasibility_continuation_20261108md) |
| `Architecture_M6_CP3_DEFN_P13_A4_A2b_Topology_Only_Scratch_Review_20261108.md` | [Vol_D2_CP3_P13_from_20261104](M6_Consolidated_Record_Vol_D2_CP3_P13_from_20261104.md#architecture_m6_cp3_defn_p13_a4_a2b_topology_only_scratch_review_20261108md) |
| `Architecture_M6_CP3_DEFN_P13_Arrangement_Sliver_Cells_Probe_Adjudication_20261102.md` | [Vol_D1_CP3_P13_to_20261103](M6_Consolidated_Record_Vol_D1_CP3_P13_to_20261103.md#architecture_m6_cp3_defn_p13_arrangement_sliver_cells_probe_adjudication_20261102md) |
| `Architecture_M6_CP3_DEFN_P13_Assembly_Dual_Boundary_Scope_Witness_20261103.md` | [Vol_D1_CP3_P13_to_20261103](M6_Consolidated_Record_Vol_D1_CP3_P13_to_20261103.md#architecture_m6_cp3_defn_p13_assembly_dual_boundary_scope_witness_20261103md) |
| `Architecture_M6_CP3_DEFN_P13_Assembly_Node5355_Prepared_Ring_Comparison_20261103.md` | [Vol_D1_CP3_P13_to_20261103](M6_Consolidated_Record_Vol_D1_CP3_P13_to_20261103.md#architecture_m6_cp3_defn_p13_assembly_node5355_prepared_ring_comparison_20261103md) |
| `Architecture_M6_CP3_DEFN_P13_Assembly_Stitched_Vertex_Breakpoint_Witness_20261103.md` | [Vol_D1_CP3_P13_to_20261103](M6_Consolidated_Record_Vol_D1_CP3_P13_to_20261103.md#architecture_m6_cp3_defn_p13_assembly_stitched_vertex_breakpoint_witness_20261103md) |
| `Architecture_M6_CP3_DEFN_P13_Assembly_Stitched_Vertex_Preflight_20261102.md` | [Vol_D1_CP3_P13_to_20261103](M6_Consolidated_Record_Vol_D1_CP3_P13_to_20261103.md#architecture_m6_cp3_defn_p13_assembly_stitched_vertex_preflight_20261102md) |
| `Architecture_M6_CP3_DEFN_P13_Assembly_Stitched_Vertex_Probe_Adjudication_20261103.md` | [Vol_D1_CP3_P13_to_20261103](M6_Consolidated_Record_Vol_D1_CP3_P13_to_20261103.md#architecture_m6_cp3_defn_p13_assembly_stitched_vertex_probe_adjudication_20261103md) |
| `Architecture_M6_CP3_DEFN_P13_Assembly_Stitched_Vertex_Three_Fan_Witness_20261103.md` | [Vol_D1_CP3_P13_to_20261103](M6_Consolidated_Record_Vol_D1_CP3_P13_to_20261103.md#architecture_m6_cp3_defn_p13_assembly_stitched_vertex_three_fan_witness_20261103md) |
| `Architecture_M6_CP3_DEFN_P13_Assembly_Typed_Source_Transition_Adjudication_20261103.md` | [Vol_D1_CP3_P13_to_20261103](M6_Consolidated_Record_Vol_D1_CP3_P13_to_20261103.md#architecture_m6_cp3_defn_p13_assembly_typed_source_transition_adjudication_20261103md) |
| `Architecture_M6_CP3_DEFN_P13_Boundary_Only_Completion_Variant_Review_20261102.md` | [Vol_D1_CP3_P13_to_20261103](M6_Consolidated_Record_Vol_D1_CP3_P13_to_20261103.md#architecture_m6_cp3_defn_p13_boundary_only_completion_variant_review_20261102md) |
| `Architecture_M6_CP3_DEFN_P13_Compatible_Occurrence_Key_V2_Scratch_Verification_20261103.md` | [Vol_D1_CP3_P13_to_20261103](M6_Consolidated_Record_Vol_D1_CP3_P13_to_20261103.md#architecture_m6_cp3_defn_p13_compatible_occurrence_key_v2_scratch_verification_20261103md) |
| `Architecture_M6_CP3_DEFN_P13_Completed_Lineage_Discriminator_Gate_20261103.md` | [Vol_D1_CP3_P13_to_20261103](M6_Consolidated_Record_Vol_D1_CP3_P13_to_20261103.md#architecture_m6_cp3_defn_p13_completed_lineage_discriminator_gate_20261103md) |
| `Architecture_M6_CP3_DEFN_P13_Completed_Mesh_Orientation_Probe_Adjudication_20261105.md` | [Vol_D2_CP3_P13_from_20261104](M6_Consolidated_Record_Vol_D2_CP3_P13_from_20261104.md#architecture_m6_cp3_defn_p13_completed_mesh_orientation_probe_adjudication_20261105md) |
| `Architecture_M6_CP3_DEFN_P13_Completed_Mesh_Orientation_Review_Single_Writer_Own_Plane_20261105.md` | [Vol_D2_CP3_P13_from_20261104](M6_Consolidated_Record_Vol_D2_CP3_P13_from_20261104.md#architecture_m6_cp3_defn_p13_completed_mesh_orientation_review_single_writer_own_plane_20261105md) |
| `Architecture_M6_CP3_DEFN_P13_Completion_Dispatch_Source_Review_20261102.md` | [Vol_D1_CP3_P13_to_20261103](M6_Consolidated_Record_Vol_D1_CP3_P13_to_20261103.md#architecture_m6_cp3_defn_p13_completion_dispatch_source_review_20261102md) |
| `Architecture_M6_CP3_DEFN_P13_Completion_Grid_Embedding_Probe_Adjudication_20261102.md` | [Vol_D1_CP3_P13_to_20261103](M6_Consolidated_Record_Vol_D1_CP3_P13_to_20261103.md#architecture_m6_cp3_defn_p13_completion_grid_embedding_probe_adjudication_20261102md) |
| `Architecture_M6_CP3_DEFN_P13_Completion_Ownership_Cost_Probe_Adjudication_20261101.md` | [Vol_D1_CP3_P13_to_20261103](M6_Consolidated_Record_Vol_D1_CP3_P13_to_20261103.md#architecture_m6_cp3_defn_p13_completion_ownership_cost_probe_adjudication_20261101md) |
| `Architecture_M6_CP3_DEFN_P13_Completion_Quad_Embedding_Probe_Adjudication_20261101.md` | [Vol_D1_CP3_P13_to_20261103](M6_Consolidated_Record_Vol_D1_CP3_P13_to_20261103.md#architecture_m6_cp3_defn_p13_completion_quad_embedding_probe_adjudication_20261101md) |
| `Architecture_M6_CP3_DEFN_P13_Cross_Stage_Evidence_Contract_20261102.md` | [Vol_D1_CP3_P13_to_20261103](M6_Consolidated_Record_Vol_D1_CP3_P13_to_20261103.md#architecture_m6_cp3_defn_p13_cross_stage_evidence_contract_20261102md) |
| `Architecture_M6_CP3_DEFN_P13_Cyclic_Side_Corrective_Audit_20261102.md` | [Vol_D1_CP3_P13_to_20261103](M6_Consolidated_Record_Vol_D1_CP3_P13_to_20261103.md#architecture_m6_cp3_defn_p13_cyclic_side_corrective_audit_20261102md) |
| `Architecture_M6_CP3_DEFN_P13_Design_Acceptance_Review_Working_Evidence_20261031.md` | [Vol_D1_CP3_P13_to_20261103](M6_Consolidated_Record_Vol_D1_CP3_P13_to_20261103.md#architecture_m6_cp3_defn_p13_design_acceptance_review_working_evidence_20261031md) |
| `Architecture_M6_CP3_DEFN_P13_Directed_Wedge_Scratch_Review_20261102.md` | [Vol_D1_CP3_P13_to_20261103](M6_Consolidated_Record_Vol_D1_CP3_P13_to_20261103.md#architecture_m6_cp3_defn_p13_directed_wedge_scratch_review_20261102md) |
| `Architecture_M6_CP3_DEFN_P13_Fallback_Source_Path_Review_20261102.md` | [Vol_D1_CP3_P13_to_20261103](M6_Consolidated_Record_Vol_D1_CP3_P13_to_20261103.md#architecture_m6_cp3_defn_p13_fallback_source_path_review_20261102md) |
| `Architecture_M6_CP3_DEFN_P13_FlowRep_Selection_Probe_Adjudication_20261102.md` | [Vol_D1_CP3_P13_to_20261103](M6_Consolidated_Record_Vol_D1_CP3_P13_to_20261103.md#architecture_m6_cp3_defn_p13_flowrep_selection_probe_adjudication_20261102md) |
| `Architecture_M6_CP3_DEFN_P13_Needle_Intrinsic_Provenance_Review_20261102.md` | [Vol_D1_CP3_P13_to_20261103](M6_Consolidated_Record_Vol_D1_CP3_P13_to_20261103.md#architecture_m6_cp3_defn_p13_needle_intrinsic_provenance_review_20261102md) |
| `Architecture_M6_CP3_DEFN_P13_O15C_Dyadic_Exit_Probe_Adjudication_20261031.md` | [Vol_D1_CP3_P13_to_20261103](M6_Consolidated_Record_Vol_D1_CP3_P13_to_20261103.md#architecture_m6_cp3_defn_p13_o15c_dyadic_exit_probe_adjudication_20261031md) |
| `Architecture_M6_CP3_DEFN_P13_O32a_Vase_Producer_Scratch_Result_20261105.md` | [Vol_D2_CP3_P13_from_20261104](M6_Consolidated_Record_Vol_D2_CP3_P13_from_20261104.md#architecture_m6_cp3_defn_p13_o32a_vase_producer_scratch_result_20261105md) |
| `Architecture_M6_CP3_DEFN_P13_Optimizer_Source_Query_Cost_Probe_Adjudication_20261103.md` | [Vol_D1_CP3_P13_to_20261103](M6_Consolidated_Record_Vol_D1_CP3_P13_to_20261103.md#architecture_m6_cp3_defn_p13_optimizer_source_query_cost_probe_adjudication_20261103md) |
| `Architecture_M6_CP3_DEFN_P13_Optimizer_Source_Query_Cost_Static_Preflight_20261103.md` | [Vol_D1_CP3_P13_to_20261103](M6_Consolidated_Record_Vol_D1_CP3_P13_to_20261103.md#architecture_m6_cp3_defn_p13_optimizer_source_query_cost_static_preflight_20261103md) |
| `Architecture_M6_CP3_DEFN_P13_Optional_Trace_Same_Rail_Return_Review_20261102.md` | [Vol_D1_CP3_P13_to_20261103](M6_Consolidated_Record_Vol_D1_CP3_P13_to_20261103.md#architecture_m6_cp3_defn_p13_optional_trace_same_rail_return_review_20261102md) |
| `Architecture_M6_CP3_DEFN_P13_Platform_Split_Review_Arrangement_Cell_Order_20261105.md` | [Vol_D2_CP3_P13_from_20261104](M6_Consolidated_Record_Vol_D2_CP3_P13_from_20261104.md#architecture_m6_cp3_defn_p13_platform_split_review_arrangement_cell_order_20261105md) |
| `Architecture_M6_CP3_DEFN_P13_Probe_Adjudication_20261031.md` | [Vol_D1_CP3_P13_to_20261103](M6_Consolidated_Record_Vol_D1_CP3_P13_to_20261103.md#architecture_m6_cp3_defn_p13_probe_adjudication_20261031md) |
| `Architecture_M6_CP3_DEFN_P13_Protected_Endpoint_Degree_Veto_Review_20261102.md` | [Vol_D1_CP3_P13_to_20261103](M6_Consolidated_Record_Vol_D1_CP3_P13_to_20261103.md#architecture_m6_cp3_defn_p13_protected_endpoint_degree_veto_review_20261102md) |
| `Architecture_M6_CP3_DEFN_P13_RepeatedState_Anchor_Admissibility_Review_20261102.md` | [Vol_D1_CP3_P13_to_20261103](M6_Consolidated_Record_Vol_D1_CP3_P13_to_20261103.md#architecture_m6_cp3_defn_p13_repeatedstate_anchor_admissibility_review_20261102md) |
| `Architecture_M6_CP3_DEFN_P13_Row_Permutation_Seeds_Review_Fan_Seeding_20261105.md` | [Vol_D2_CP3_P13_from_20261104](M6_Consolidated_Record_Vol_D2_CP3_P13_from_20261104.md#architecture_m6_cp3_defn_p13_row_permutation_seeds_review_fan_seeding_20261105md) |
| `Architecture_M6_CP3_DEFN_P13_Row_Ranked_Provenance_Corner_Key_Counterexample_20261103.md` | [Vol_D1_CP3_P13_to_20261103](M6_Consolidated_Record_Vol_D1_CP3_P13_to_20261103.md#architecture_m6_cp3_defn_p13_row_ranked_provenance_corner_key_counterexample_20261103md) |
| `Architecture_M6_CP3_DEFN_P13_Seed_Capture_Analyzer_Correction_WIP_20261105.md` | [Vol_D2_CP3_P13_from_20261104](M6_Consolidated_Record_Vol_D2_CP3_P13_from_20261104.md#architecture_m6_cp3_defn_p13_seed_capture_analyzer_correction_wip_20261105md) |
| `Architecture_M6_CP3_DEFN_P13_Side_Subdivision_Quality_Census_Adjudication_20261108.md` | [Vol_D2_CP3_P13_from_20261104](M6_Consolidated_Record_Vol_D2_CP3_P13_from_20261104.md#architecture_m6_cp3_defn_p13_side_subdivision_quality_census_adjudication_20261108md) |
| `Architecture_M6_CP3_DEFN_P13_Side_Subdivision_Quality_Review_Legacy_Fallback_Density_20261108.md` | [Vol_D2_CP3_P13_from_20261104](M6_Consolidated_Record_Vol_D2_CP3_P13_from_20261104.md#architecture_m6_cp3_defn_p13_side_subdivision_quality_review_legacy_fallback_density_20261108md) |
| `Architecture_M6_CP3_DEFN_P13_Single_Edge_Barrier_Slit_Review_Decision_20261101.md` | [Vol_D1_CP3_P13_to_20261103](M6_Consolidated_Record_Vol_D1_CP3_P13_to_20261103.md#architecture_m6_cp3_defn_p13_single_edge_barrier_slit_review_decision_20261101md) |
| `Architecture_M6_CP3_DEFN_P13_Slit_Cycle_Basis_Probe_Adjudication_20261101.md` | [Vol_D1_CP3_P13_to_20261103](M6_Consolidated_Record_Vol_D1_CP3_P13_to_20261103.md#architecture_m6_cp3_defn_p13_slit_cycle_basis_probe_adjudication_20261101md) |
| `Architecture_M6_CP3_DEFN_P13_Sliver_Review_Scratch_Execution_20261102.md` | [Vol_D1_CP3_P13_to_20261103](M6_Consolidated_Record_Vol_D1_CP3_P13_to_20261103.md#architecture_m6_cp3_defn_p13_sliver_review_scratch_execution_20261102md) |
| `Architecture_M6_CP3_DEFN_P13_Smooth_Field_Portability_Review_Row_Permutation_20261105.md` | [Vol_D2_CP3_P13_from_20261104](M6_Consolidated_Record_Vol_D2_CP3_P13_from_20261104.md#architecture_m6_cp3_defn_p13_smooth_field_portability_review_row_permutation_20261105md) |
| `Architecture_M6_CP3_DEFN_P13_Source_Microedge_Provenance_Review_WIP_20261106.md` | [Vol_D2_CP3_P13_from_20261104](M6_Consolidated_Record_Vol_D2_CP3_P13_from_20261104.md#architecture_m6_cp3_defn_p13_source_microedge_provenance_review_wip_20261106md) |
| `Architecture_M6_CP3_DEFN_P13_Stitch_Key_Dataflow_Readonly_Review_20261103.md` | [Vol_D1_CP3_P13_to_20261103](M6_Consolidated_Record_Vol_D1_CP3_P13_to_20261103.md#architecture_m6_cp3_defn_p13_stitch_key_dataflow_readonly_review_20261103md) |
| `Architecture_M6_CP3_DEFN_P13_Stitch_Overlap_Provenance_Probe_Adjudication_20261106.md` | [Vol_D2_CP3_P13_from_20261104](M6_Consolidated_Record_Vol_D2_CP3_P13_from_20261104.md#architecture_m6_cp3_defn_p13_stitch_overlap_provenance_probe_adjudication_20261106md) |
| `Architecture_M6_CP3_DEFN_P13_Stitch_Overlap_Scratch_Recovery_20261106.md` | [Vol_D2_CP3_P13_from_20261104](M6_Consolidated_Record_Vol_D2_CP3_P13_from_20261104.md#architecture_m6_cp3_defn_p13_stitch_overlap_scratch_recovery_20261106md) |
| `Architecture_M6_CP3_DEFN_P13_Trace_Termination_Anchor_Source_Review_20261102.md` | [Vol_D1_CP3_P13_to_20261103](M6_Consolidated_Record_Vol_D1_CP3_P13_to_20261103.md#architecture_m6_cp3_defn_p13_trace_termination_anchor_source_review_20261102md) |
| `Architecture_M6_CP3_DEFN_P13_V2_Readonly_Sampling_Control_Evidence_20261103.md` | [Vol_D1_CP3_P13_to_20261103](M6_Consolidated_Record_Vol_D1_CP3_P13_to_20261103.md#architecture_m6_cp3_defn_p13_v2_readonly_sampling_control_evidence_20261103md) |
| `Architecture_M6_CP3_DEFN_P13_Vase_Arrangement_Rotation_Probe_Adjudication_20261101.md` | [Vol_D1_CP3_P13_to_20261103](M6_Consolidated_Record_Vol_D1_CP3_P13_to_20261103.md#architecture_m6_cp3_defn_p13_vase_arrangement_rotation_probe_adjudication_20261101md) |
| `Architecture_M6_CP3_DEFN_P13_Vase_Landed_Incidence_Probe_Revert_20261101.md` | [Vol_D1_CP3_P13_to_20261103](M6_Consolidated_Record_Vol_D1_CP3_P13_to_20261103.md#architecture_m6_cp3_defn_p13_vase_landed_incidence_probe_revert_20261101md) |
| `Architecture_M6_CP3_DEFN_P13_Vase_Producer_Path_Adversarial_Review_A2b_Disc_Construction_20261108.md` | [Vol_D2_CP3_P13_from_20261104](M6_Consolidated_Record_Vol_D2_CP3_P13_from_20261104.md#architecture_m6_cp3_defn_p13_vase_producer_path_adversarial_review_a2b_disc_construction_20261108md) |
| `Architecture_M6_CP3_DEFN_P1_Gauge_Pin_Domain_Definition_Record_20261020.md` | [Vol_C_CP3_Gate_Turns](M6_Consolidated_Record_Vol_C_CP3_Gate_Turns.md#architecture_m6_cp3_defn_p1_gauge_pin_domain_definition_record_20261020md) |
| `Architecture_M6_CP3_DEFN_P1_Gauge_Pin_Domain_Review_Decision.md` | [Vol_C_CP3_Gate_Turns](M6_Consolidated_Record_Vol_C_CP3_Gate_Turns.md#architecture_m6_cp3_defn_p1_gauge_pin_domain_review_decisionmd) |
| `Architecture_M6_CP3_DEFN_RP01_Off_Selector_Coverage_Working_Inventory_20261029.md` | [Vol_C_CP3_Gate_Turns](M6_Consolidated_Record_Vol_C_CP3_Gate_Turns.md#architecture_m6_cp3_defn_rp01_off_selector_coverage_working_inventory_20261029md) |
| `Architecture_M6_CP3_DEFN_SEAM_A5_Shared_Node_Side_Authority_20261022.md` | [Vol_C_CP3_Gate_Turns](M6_Consolidated_Record_Vol_C_CP3_Gate_Turns.md#architecture_m6_cp3_defn_seam_a5_shared_node_side_authority_20261022md) |
| `Architecture_M6_CP3_DEFN_SEAM_A5_Shared_Node_Side_Authority_Review_Decision_20261022.md` | [Vol_C_CP3_Gate_Turns](M6_Consolidated_Record_Vol_C_CP3_Gate_Turns.md#architecture_m6_cp3_defn_seam_a5_shared_node_side_authority_review_decision_20261022md) |
| `Architecture_M6_CP3_DEFN_SEAM_A7_Certified_Seam_Cross_Sheet_Authority_20261022.md` | [Vol_C_CP3_Gate_Turns](M6_Consolidated_Record_Vol_C_CP3_Gate_Turns.md#architecture_m6_cp3_defn_seam_a7_certified_seam_cross_sheet_authority_20261022md) |
| `Architecture_M6_CP3_DEFN_SEAM_A7_Certified_Seam_Cross_Sheet_Authority_Review_Decision_20261022.md` | [Vol_C_CP3_Gate_Turns](M6_Consolidated_Record_Vol_C_CP3_Gate_Turns.md#architecture_m6_cp3_defn_seam_a7_certified_seam_cross_sheet_authority_review_decision_20261022md) |
| `Architecture_M6_CP3_DEFN_Selector242_Seam_Consumer_Review_Decision_20261026.md` | [Vol_C_CP3_Gate_Turns](M6_Consolidated_Record_Vol_C_CP3_Gate_Turns.md#architecture_m6_cp3_defn_selector242_seam_consumer_review_decision_20261026md) |
| `Architecture_M6_CP3_DEFN_U6_Exact_I_Origin_Review_Decision.md` | [Vol_C_CP3_Gate_Turns](M6_Consolidated_Record_Vol_C_CP3_Gate_Turns.md#architecture_m6_cp3_defn_u6_exact_i_origin_review_decisionmd) |
| `Architecture_M6_CP3_R10B_Endpoint_Rule_Review_Decision.md` | [Vol_B_CP3_R_Series](M6_Consolidated_Record_Vol_B_CP3_R_Series.md#architecture_m6_cp3_r10b_endpoint_rule_review_decisionmd) |
| `Architecture_M6_CP3_R2P3_HardRail_Route_Transport_Review_Decision.md` | [Vol_B_CP3_R_Series](M6_Consolidated_Record_Vol_B_CP3_R_Series.md#architecture_m6_cp3_r2p3_hardrail_route_transport_review_decisionmd) |
| `Architecture_M6_CP3_R3_ABC_Review_Decision.md` | [Vol_B_CP3_R_Series](M6_Consolidated_Record_Vol_B_CP3_R_Series.md#architecture_m6_cp3_r3_abc_review_decisionmd) |
| `Architecture_M6_CP3_R3_Endpoint_Attachment_Review_Decision.md` | [Vol_B_CP3_R_Series](M6_Consolidated_Record_Vol_B_CP3_R_Series.md#architecture_m6_cp3_r3_endpoint_attachment_review_decisionmd) |
| `Architecture_M6_CP3_R3_Sector_Derivation_Review_Decision.md` | [Vol_B_CP3_R_Series](M6_Consolidated_Record_Vol_B_CP3_R_Series.md#architecture_m6_cp3_r3_sector_derivation_review_decisionmd) |
| `Architecture_M6_CP3_R4_Ambiguous_Terminal_Contact_Feasibility_Review_Decision.md` | [Vol_B_CP3_R_Series](M6_Consolidated_Record_Vol_B_CP3_R_Series.md#architecture_m6_cp3_r4_ambiguous_terminal_contact_feasibility_review_decisionmd) |
| `Architecture_M6_CP3_R4_Authoring_Closeout_And_TB_Authorization_Review_Decision.md` | [Vol_B_CP3_R_Series](M6_Consolidated_Record_Vol_B_CP3_R_Series.md#architecture_m6_cp3_r4_authoring_closeout_and_tb_authorization_review_decisionmd) |
| `Architecture_M6_CP3_R4_Carrier_Review_Decision.md` | [Vol_B_CP3_R_Series](M6_Consolidated_Record_Vol_B_CP3_R_Series.md#architecture_m6_cp3_r4_carrier_review_decisionmd) |
| `Architecture_M6_CP3_R4_Contact_Binding_And_Gauge_Witness_Review_Decision.md` | [Vol_B_CP3_R_Series](M6_Consolidated_Record_Vol_B_CP3_R_Series.md#architecture_m6_cp3_r4_contact_binding_and_gauge_witness_review_decisionmd) |
| `Architecture_M6_CP3_R4_Edge_Index_Namespace_Conflict_Review_Stop_20261012.md` | [Vol_B_CP3_R_Series](M6_Consolidated_Record_Vol_B_CP3_R_Series.md#architecture_m6_cp3_r4_edge_index_namespace_conflict_review_stop_20261012md) |
| `Architecture_M6_CP3_R4_Edge_Index_Namespace_Review_Decision.md` | [Vol_B_CP3_R_Series](M6_Consolidated_Record_Vol_B_CP3_R_Series.md#architecture_m6_cp3_r4_edge_index_namespace_review_decisionmd) |
| `Architecture_M6_CP3_R4_Endpoint_Authority_Spec_Review_Decision.md` | [Vol_B_CP3_R_Series](M6_Consolidated_Record_Vol_B_CP3_R_Series.md#architecture_m6_cp3_r4_endpoint_authority_spec_review_decisionmd) |
| `Architecture_M6_CP3_R4_Endpoint_Chart_Harvest_Review_Decision.md` | [Vol_B_CP3_R_Series](M6_Consolidated_Record_Vol_B_CP3_R_Series.md#architecture_m6_cp3_r4_endpoint_chart_harvest_review_decisionmd) |
| `Architecture_M6_CP3_R4_Endpoint_Chart_Probe_Review_Decision.md` | [Vol_B_CP3_R_Series](M6_Consolidated_Record_Vol_B_CP3_R_Series.md#architecture_m6_cp3_r4_endpoint_chart_probe_review_decisionmd) |
| `Architecture_M6_CP3_R4_Factory_Incidence_Oracle_Source_Validity_Static_Audit_20261011.md` | [Vol_B_CP3_R_Series](M6_Consolidated_Record_Vol_B_CP3_R_Series.md#architecture_m6_cp3_r4_factory_incidence_oracle_source_validity_static_audit_20261011md) |
| `Architecture_M6_CP3_R4_First_RED_Carrier_Reclassification_Review_Decision.md` | [Vol_B_CP3_R_Series](M6_Consolidated_Record_Vol_B_CP3_R_Series.md#architecture_m6_cp3_r4_first_red_carrier_reclassification_review_decisionmd) |
| `Architecture_M6_CP3_R4_Gauge_Consumption_Review_Decision.md` | [Vol_B_CP3_R_Series](M6_Consolidated_Record_Vol_B_CP3_R_Series.md#architecture_m6_cp3_r4_gauge_consumption_review_decisionmd) |
| `Architecture_M6_CP3_R4_Interior_Endpoint_Repair_Review_Decision.md` | [Vol_B_CP3_R_Series](M6_Consolidated_Record_Vol_B_CP3_R_Series.md#architecture_m6_cp3_r4_interior_endpoint_repair_review_decisionmd) |
| `Architecture_M6_CP3_R4_Interior_Witness_Measurement_Review_Decision.md` | [Vol_B_CP3_R_Series](M6_Consolidated_Record_Vol_B_CP3_R_Series.md#architecture_m6_cp3_r4_interior_witness_measurement_review_decisionmd) |
| `Architecture_M6_CP3_R4_Oriented_Terminal_Side_Authority_Review_Decision.md` | [Vol_B_CP3_R_Series](M6_Consolidated_Record_Vol_B_CP3_R_Series.md#architecture_m6_cp3_r4_oriented_terminal_side_authority_review_decisionmd) |
| `Architecture_M6_CP3_R4_Overfull_A3_Feasibility_Review_Decision.md` | [Vol_B_CP3_R_Series](M6_Consolidated_Record_Vol_B_CP3_R_Series.md#architecture_m6_cp3_r4_overfull_a3_feasibility_review_decisionmd) |
| `Architecture_M6_CP3_R4_Predicate_Separation_Review_Decision.md` | [Vol_B_CP3_R_Series](M6_Consolidated_Record_Vol_B_CP3_R_Series.md#architecture_m6_cp3_r4_predicate_separation_review_decisionmd) |
| `Architecture_M6_CP3_R4_Probe_Harvest_Review_Decision.md` | [Vol_B_CP3_R_Series](M6_Consolidated_Record_Vol_B_CP3_R_Series.md#architecture_m6_cp3_r4_probe_harvest_review_decisionmd) |
| `Architecture_M6_CP3_R4_Producer_Locus_Review_Decision.md` | [Vol_B_CP3_R_Series](M6_Consolidated_Record_Vol_B_CP3_R_Series.md#architecture_m6_cp3_r4_producer_locus_review_decisionmd) |
| `Architecture_M6_CP3_R4_RA432_Oriented_Germ_Producer_Boundary_Review_Request_20261013.md` | [Vol_B_CP3_R_Series](M6_Consolidated_Record_Vol_B_CP3_R_Series.md#architecture_m6_cp3_r4_ra432_oriented_germ_producer_boundary_review_request_20261013md) |
| `Architecture_M6_CP3_R4_RA465_Ambiguous_Terminal_Contact_Review_Stop_20261012.md` | [Vol_B_CP3_R_Series](M6_Consolidated_Record_Vol_B_CP3_R_Series.md#architecture_m6_cp3_r4_ra465_ambiguous_terminal_contact_review_stop_20261012md) |
| `Architecture_M6_CP3_R4_RA465_Terminal_A3_First_Rejection_Review_Stop_20261013.md` | [Vol_B_CP3_R_Series](M6_Consolidated_Record_Vol_B_CP3_R_Series.md#architecture_m6_cp3_r4_ra465_terminal_a3_first_rejection_review_stop_20261013md) |
| `Architecture_M6_CP3_R4_SID02_Produced_Cell_Reachability_Probe_20261014.md` | [Vol_B_CP3_R_Series](M6_Consolidated_Record_Vol_B_CP3_R_Series.md#architecture_m6_cp3_r4_sid02_produced_cell_reachability_probe_20261014md) |
| `Architecture_M6_CP3_R4_Selected_Branch_And_Diagnostic_Optout_Review_Decision.md` | [Vol_B_CP3_R_Series](M6_Consolidated_Record_Vol_B_CP3_R_Series.md#architecture_m6_cp3_r4_selected_branch_and_diagnostic_optout_review_decisionmd) |
| `Architecture_M6_CP3_R4_Source_Current_Review_Gate_20261014.md` | [Vol_B_CP3_R_Series](M6_Consolidated_Record_Vol_B_CP3_R_Series.md#architecture_m6_cp3_r4_source_current_review_gate_20261014md) |
| `Architecture_M6_CP3_R4_Terminal_A3_First_Rejection_Review_Decision.md` | [Vol_B_CP3_R_Series](M6_Consolidated_Record_Vol_B_CP3_R_Series.md#architecture_m6_cp3_r4_terminal_a3_first_rejection_review_decisionmd) |
| `Architecture_M6_CP3_R4_Terminal_A3_Uniqueness_Design_Review_Request_20261011.md` | [Vol_B_CP3_R_Series](M6_Consolidated_Record_Vol_B_CP3_R_Series.md#architecture_m6_cp3_r4_terminal_a3_uniqueness_design_review_request_20261011md) |
| `Architecture_M6_CP3_R4_Terminal_A3_Uniqueness_Review_Decision.md` | [Vol_B_CP3_R_Series](M6_Consolidated_Record_Vol_B_CP3_R_Series.md#architecture_m6_cp3_r4_terminal_a3_uniqueness_review_decisionmd) |
| `Architecture_M6_CP3_R4_Terminal_Conjunct_Extraction_Review_Decision.md` | [Vol_B_CP3_R_Series](M6_Consolidated_Record_Vol_B_CP3_R_Series.md#architecture_m6_cp3_r4_terminal_conjunct_extraction_review_decisionmd) |
| `Architecture_M6_CP3_R4_Terminal_Contact_And_Gauge_Review_Decision.md` | [Vol_B_CP3_R_Series](M6_Consolidated_Record_Vol_B_CP3_R_Series.md#architecture_m6_cp3_r4_terminal_contact_and_gauge_review_decisionmd) |
| `Architecture_M6_CP3_R4_True_Control_Review_Decision.md` | [Vol_B_CP3_R_Series](M6_Consolidated_Record_Vol_B_CP3_R_Series.md#architecture_m6_cp3_r4_true_control_review_decisionmd) |
| `Architecture_M6_CP3_R4_Witness_Breadth_Measurement_Review_Decision.md` | [Vol_B_CP3_R_Series](M6_Consolidated_Record_Vol_B_CP3_R_Series.md#architecture_m6_cp3_r4_witness_breadth_measurement_review_decisionmd) |
| `Architecture_M6_CP3_R5_Junction_Carrier_Authority_Spec_Review_Decision.md` | [Vol_B_CP3_R_Series](M6_Consolidated_Record_Vol_B_CP3_R_Series.md#architecture_m6_cp3_r5_junction_carrier_authority_spec_review_decisionmd) |
| `Architecture_M6_CP3_R5_Route_Path_Reconciliation_Review_Decision.md` | [Vol_B_CP3_R_Series](M6_Consolidated_Record_Vol_B_CP3_R_Series.md#architecture_m6_cp3_r5_route_path_reconciliation_review_decisionmd) |
| `Architecture_M6_CP3_R6_Corner_Assignment_Authority_Spec_Review_Decision.md` | [Vol_B_CP3_R_Series](M6_Consolidated_Record_Vol_B_CP3_R_Series.md#architecture_m6_cp3_r6_corner_assignment_authority_spec_review_decisionmd) |
| `Architecture_M6_CP3_R7_Corner_Face_Selection_Repair_Spec_Review_Decision.md` | [Vol_B_CP3_R_Series](M6_Consolidated_Record_Vol_B_CP3_R_Series.md#architecture_m6_cp3_r7_corner_face_selection_repair_spec_review_decisionmd) |
| `Architecture_M6_CP3_R7_Lattice_UV_Candidate_Review_Decision.md` | [Vol_B_CP3_R_Series](M6_Consolidated_Record_Vol_B_CP3_R_Series.md#architecture_m6_cp3_r7_lattice_uv_candidate_review_decisionmd) |
| `Architecture_M6_CP3_R7_Node_Admissible_Face_Set_Review_Decision.md` | [Vol_B_CP3_R_Series](M6_Consolidated_Record_Vol_B_CP3_R_Series.md#architecture_m6_cp3_r7_node_admissible_face_set_review_decisionmd) |
| `Architecture_M6_CP3_R8_Boundary_Override_Authority_Spec_Review_Decision.md` | [Vol_B_CP3_R_Series](M6_Consolidated_Record_Vol_B_CP3_R_Series.md#architecture_m6_cp3_r8_boundary_override_authority_spec_review_decisionmd) |
| `Architecture_M6_CP3_R8_Source_Entity_Equivalence_Review_Decision.md` | [Vol_B_CP3_R_Series](M6_Consolidated_Record_Vol_B_CP3_R_Series.md#architecture_m6_cp3_r8_source_entity_equivalence_review_decisionmd) |
| `Architecture_M6_CP3_TB11_Route_Anchor_Review_Decision.md` | [Vol_C_CP3_Gate_Turns](M6_Consolidated_Record_Vol_C_CP3_Gate_Turns.md#architecture_m6_cp3_tb11_route_anchor_review_decisionmd) |
| `Architecture_M6_CP3_TB12_Chain_Provenance_Review_Decision.md` | [Vol_C_CP3_Gate_Turns](M6_Consolidated_Record_Vol_C_CP3_Gate_Turns.md#architecture_m6_cp3_tb12_chain_provenance_review_decisionmd) |
| `Architecture_M6_CP3_TB13C_Census_Review_Decision.md` | [Vol_C_CP3_Gate_Turns](M6_Consolidated_Record_Vol_C_CP3_Gate_Turns.md#architecture_m6_cp3_tb13c_census_review_decisionmd) |
| `Architecture_M6_CP3_TB13D_Bisect_Review_Decision.md` | [Vol_C_CP3_Gate_Turns](M6_Consolidated_Record_Vol_C_CP3_Gate_Turns.md#architecture_m6_cp3_tb13d_bisect_review_decisionmd) |
| `Architecture_M6_CP3_TB13_Chain_Interval_Review_Decision.md` | [Vol_C_CP3_Gate_Turns](M6_Consolidated_Record_Vol_C_CP3_Gate_Turns.md#architecture_m6_cp3_tb13_chain_interval_review_decisionmd) |
| `Architecture_M6_CP3_TB14A_Curved_Disk_Control_Review_Decision.md` | [Vol_C_CP3_Gate_Turns](M6_Consolidated_Record_Vol_C_CP3_Gate_Turns.md#architecture_m6_cp3_tb14a_curved_disk_control_review_decisionmd) |
| `Architecture_M6_CP3_TB16C_Census_U4_Review_Decision.md` | [Vol_C_CP3_Gate_Turns](M6_Consolidated_Record_Vol_C_CP3_Gate_Turns.md#architecture_m6_cp3_tb16c_census_u4_review_decisionmd) |
| `Architecture_M6_CP3_TB17_Rail_Vertex_U5_Review_Decision.md` | [Vol_C_CP3_Gate_Turns](M6_Consolidated_Record_Vol_C_CP3_Gate_Turns.md#architecture_m6_cp3_tb17_rail_vertex_u5_review_decisionmd) |
| `Architecture_M6_CP3_TB18_REV_Factory_Rejection_Review_Decision.md` | [Vol_C_CP3_Gate_Turns](M6_Consolidated_Record_Vol_C_CP3_Gate_Turns.md#architecture_m6_cp3_tb18_rev_factory_rejection_review_decisionmd) |
| `Architecture_M6_CP3_TB18_Rail_Vertex_Endpoint_Independent_Review_20261020.md` | [Vol_C_CP3_Gate_Turns](M6_Consolidated_Record_Vol_C_CP3_Gate_Turns.md#architecture_m6_cp3_tb18_rail_vertex_endpoint_independent_review_20261020md) |
| `Architecture_M6_CP3_TB19A_Torus_Rejection_Site_Harvest_Report_20261020.md` | [Vol_C_CP3_Gate_Turns](M6_Consolidated_Record_Vol_C_CP3_Gate_Turns.md#architecture_m6_cp3_tb19a_torus_rejection_site_harvest_report_20261020md) |
| `Architecture_M6_CP3_TB19_Closeout_Review_Decision.md` | [Vol_C_CP3_Gate_Turns](M6_Consolidated_Record_Vol_C_CP3_Gate_Turns.md#architecture_m6_cp3_tb19_closeout_review_decisionmd) |
| `Architecture_M6_CP3_TB19_Factory_Rejection_Site_Harvest_Report_20261020.md` | [Vol_C_CP3_Gate_Turns](M6_Consolidated_Record_Vol_C_CP3_Gate_Turns.md#architecture_m6_cp3_tb19_factory_rejection_site_harvest_report_20261020md) |
| `Architecture_M6_CP3_TB19_REV_Gauge_Pin_Domain_Review_Decision.md` | [Vol_C_CP3_Gate_Turns](M6_Consolidated_Record_Vol_C_CP3_Gate_Turns.md#architecture_m6_cp3_tb19_rev_gauge_pin_domain_review_decisionmd) |
| `Architecture_M6_CP3_TB19_Torus_Staging_Review_Decision.md` | [Vol_C_CP3_Gate_Turns](M6_Consolidated_Record_Vol_C_CP3_Gate_Turns.md#architecture_m6_cp3_tb19_torus_staging_review_decisionmd) |
| `Architecture_M6_CP3_TB1_Entry_R1_Review_Record.md` | [Vol_C_CP3_Gate_Turns](M6_Consolidated_Record_Vol_C_CP3_Gate_Turns.md#architecture_m6_cp3_tb1_entry_r1_review_recordmd) |
| `Architecture_M6_CP3_TB1_Entry_R2_Review_Record.md` | [Vol_C_CP3_Gate_Turns](M6_Consolidated_Record_Vol_C_CP3_Gate_Turns.md#architecture_m6_cp3_tb1_entry_r2_review_recordmd) |
| `Architecture_M6_CP3_TB20_Gauge_Pin_Domain_Review_Decision.md` | [Vol_C_CP3_Gate_Turns](M6_Consolidated_Record_Vol_C_CP3_Gate_Turns.md#architecture_m6_cp3_tb20_gauge_pin_domain_review_decisionmd) |
| `Architecture_M6_CP3_TB21_Selector_497_Census_Review_Decision.md` | [Vol_C_CP3_Gate_Turns](M6_Consolidated_Record_Vol_C_CP3_Gate_Turns.md#architecture_m6_cp3_tb21_selector_497_census_review_decisionmd) |
| `Architecture_M6_CP3_TB22_Torus_Witness_Harvest_Plan_20261021.md` | [Vol_C_CP3_Gate_Turns](M6_Consolidated_Record_Vol_C_CP3_Gate_Turns.md#architecture_m6_cp3_tb22_torus_witness_harvest_plan_20261021md) |
| `Architecture_M6_CP3_TB22_Torus_Witness_Harvest_Review_Decision.md` | [Vol_C_CP3_Gate_Turns](M6_Consolidated_Record_Vol_C_CP3_Gate_Turns.md#architecture_m6_cp3_tb22_torus_witness_harvest_review_decisionmd) |
| `Architecture_M6_CP3_TB23_Torus_A5_Site_Harvest_Plan_20261021.md` | [Vol_C_CP3_Gate_Turns](M6_Consolidated_Record_Vol_C_CP3_Gate_Turns.md#architecture_m6_cp3_tb23_torus_a5_site_harvest_plan_20261021md) |
| `Architecture_M6_CP3_TB23_Torus_A5_Site_Harvest_Review_Decision.md` | [Vol_C_CP3_Gate_Turns](M6_Consolidated_Record_Vol_C_CP3_Gate_Turns.md#architecture_m6_cp3_tb23_torus_a5_site_harvest_review_decisionmd) |
| `Architecture_M6_CP3_TB24_Torus_A5_Seam_Face_Harvest_Review_Decision_20261021.md` | [Vol_C_CP3_Gate_Turns](M6_Consolidated_Record_Vol_C_CP3_Gate_Turns.md#architecture_m6_cp3_tb24_torus_a5_seam_face_harvest_review_decision_20261021md) |
| `Architecture_M6_CP3_TB25_Seam_Frame_Values_Harvest_Review_Decision_20261022.md` | [Vol_C_CP3_Gate_Turns](M6_Consolidated_Record_Vol_C_CP3_Gate_Turns.md#architecture_m6_cp3_tb25_seam_frame_values_harvest_review_decision_20261022md) |
| `Architecture_M6_CP3_TB26_Shared_Node_Seam_Witness_Harvest_Review_Decision_20261022.md` | [Vol_C_CP3_Gate_Turns](M6_Consolidated_Record_Vol_C_CP3_Gate_Turns.md#architecture_m6_cp3_tb26_shared_node_seam_witness_harvest_review_decision_20261022md) |
| `Architecture_M6_CP3_TB27_A7_Certified_Seam_Cross_Sheet_Verification_Review_Decision_20261022.md` | [Vol_C_CP3_Gate_Turns](M6_Consolidated_Record_Vol_C_CP3_Gate_Turns.md#architecture_m6_cp3_tb27_a7_certified_seam_cross_sheet_verification_review_decision_20261022md) |
| `Architecture_M6_CP3_TB28_Census_Review_Audit_Decision_20261022.md` | [Vol_C_CP3_Gate_Turns](M6_Consolidated_Record_Vol_C_CP3_Gate_Turns.md#architecture_m6_cp3_tb28_census_review_audit_decision_20261022md) |
| `Architecture_M6_CP3_TB28_Selector_497_Census_Review_Decision_20261022.md` | [Vol_C_CP3_Gate_Turns](M6_Consolidated_Record_Vol_C_CP3_Gate_Turns.md#architecture_m6_cp3_tb28_selector_497_census_review_decision_20261022md) |
| `Architecture_M6_CP3_TB29H_RP02_Review_Audit_Decision_20261023.md` | [Vol_C_CP3_Gate_Turns](M6_Consolidated_Record_Vol_C_CP3_Gate_Turns.md#architecture_m6_cp3_tb29h_rp02_review_audit_decision_20261023md) |
| `Architecture_M6_CP3_TB29H_Review_Audit_Decision_20261023.md` | [Vol_C_CP3_Gate_Turns](M6_Consolidated_Record_Vol_C_CP3_Gate_Turns.md#architecture_m6_cp3_tb29h_review_audit_decision_20261023md) |
| `Architecture_M6_CP3_TB29H_Targeted_Harness_Review_Decision_20261023.md` | [Vol_C_CP3_Gate_Turns](M6_Consolidated_Record_Vol_C_CP3_Gate_Turns.md#architecture_m6_cp3_tb29h_targeted_harness_review_decision_20261023md) |
| `Architecture_M6_CP3_TB29_Harness_Authorization_Design_Review_Decision_20261023.md` | [Vol_C_CP3_Gate_Turns](M6_Consolidated_Record_Vol_C_CP3_Gate_Turns.md#architecture_m6_cp3_tb29_harness_authorization_design_review_decision_20261023md) |
| `Architecture_M6_CP3_TB29_Review_Audit_Decision_20261023.md` | [Vol_C_CP3_Gate_Turns](M6_Consolidated_Record_Vol_C_CP3_Gate_Turns.md#architecture_m6_cp3_tb29_review_audit_decision_20261023md) |
| `Architecture_M6_CP3_TB29_Typed_Factory_Cause_Harvest_Review_Decision_20261023.md` | [Vol_C_CP3_Gate_Turns](M6_Consolidated_Record_Vol_C_CP3_Gate_Turns.md#architecture_m6_cp3_tb29_typed_factory_cause_harvest_review_decision_20261023md) |
| `Architecture_M6_CP3_TB30_Certificate_Association_Ownership_Verification_Review_Decision_20261023.md` | [Vol_C_CP3_Gate_Turns](M6_Consolidated_Record_Vol_C_CP3_Gate_Turns.md#architecture_m6_cp3_tb30_certificate_association_ownership_verification_review_decision_20261023md) |
| `Architecture_M6_CP3_TB33_Odd_Atlas_Oracle_Verification_Review_Decision_20261024.md` | [Vol_C_CP3_Gate_Turns](M6_Consolidated_Record_Vol_C_CP3_Gate_Turns.md#architecture_m6_cp3_tb33_odd_atlas_oracle_verification_review_decision_20261024md) |
| `Architecture_M6_CP3_TB34_REV_Audit_Face_Gauge_Representation_Decision_20261024.md` | [Vol_C_CP3_Gate_Turns](M6_Consolidated_Record_Vol_C_CP3_Gate_Turns.md#architecture_m6_cp3_tb34_rev_audit_face_gauge_representation_decision_20261024md) |
| `Architecture_M6_CP3_TB35_REV_Audit_Periodic_Route_Transport_Decision_20261024.md` | [Vol_C_CP3_Gate_Turns](M6_Consolidated_Record_Vol_C_CP3_Gate_Turns.md#architecture_m6_cp3_tb35_rev_audit_periodic_route_transport_decision_20261024md) |
| `Architecture_M6_CP3_TB36_REV_Audit_Periodic_Route_Atlas_Transport_Decision_20261025.md` | [Vol_C_CP3_Gate_Turns](M6_Consolidated_Record_Vol_C_CP3_Gate_Turns.md#architecture_m6_cp3_tb36_rev_audit_periodic_route_atlas_transport_decision_20261025md) |
| `Architecture_M6_CP3_TB37_REV_Audit_Periodic_Census_Manifest_Decision_20261025.md` | [Vol_C_CP3_Gate_Turns](M6_Consolidated_Record_Vol_C_CP3_Gate_Turns.md#architecture_m6_cp3_tb37_rev_audit_periodic_census_manifest_decision_20261025md) |
| `Architecture_M6_CP3_TB38_REV_Audit_Tamper_Oracle_Homes_Decision_20261025.md` | [Vol_C_CP3_Gate_Turns](M6_Consolidated_Record_Vol_C_CP3_Gate_Turns.md#architecture_m6_cp3_tb38_rev_audit_tamper_oracle_homes_decision_20261025md) |
| `Architecture_M6_CP3_TB39_REV_Audit_Selector250_Rail_Provenance_Decision_20261025.md` | [Vol_C_CP3_Gate_Turns](M6_Consolidated_Record_Vol_C_CP3_Gate_Turns.md#architecture_m6_cp3_tb39_rev_audit_selector250_rail_provenance_decision_20261025md) |
| `Architecture_M6_CP3_TB40_REV_Audit_CB39_A3_Tamper_Spec_Decision_20261025.md` | [Vol_C_CP3_Gate_Turns](M6_Consolidated_Record_Vol_C_CP3_Gate_Turns.md#architecture_m6_cp3_tb40_rev_audit_cb39_a3_tamper_spec_decision_20261025md) |
| `Architecture_M6_CP3_TB41_REV_Audit_O3_Owner_And_DEFN_Split_Decision_20261026.md` | [Vol_C_CP3_Gate_Turns](M6_Consolidated_Record_Vol_C_CP3_Gate_Turns.md#architecture_m6_cp3_tb41_rev_audit_o3_owner_and_defn_split_decision_20261026md) |
| `Architecture_M6_CP3_TB42_REV_Audit_Selector190_Vacuity_And_DEFN_Spec_Decision_20261026.md` | [Vol_C_CP3_Gate_Turns](M6_Consolidated_Record_Vol_C_CP3_Gate_Turns.md#architecture_m6_cp3_tb42_rev_audit_selector190_vacuity_and_defn_spec_decision_20261026md) |
| `Architecture_M6_CP3_TB43_REV_Audit_Selector405_Fixture_Provenance_Decision_20261026.md` | [Vol_C_CP3_Gate_Turns](M6_Consolidated_Record_Vol_C_CP3_Gate_Turns.md#architecture_m6_cp3_tb43_rev_audit_selector405_fixture_provenance_decision_20261026md) |
| `Architecture_M6_CP3_TB44_REV_Audit_P1_Torn_Input_Selector242_Scope_Decision_20261026.md` | [Vol_C_CP3_Gate_Turns](M6_Consolidated_Record_Vol_C_CP3_Gate_Turns.md#architecture_m6_cp3_tb44_rev_audit_p1_torn_input_selector242_scope_decision_20261026md) |
| `Architecture_M6_CP3_TB45_REV_Audit_Rail_Oracle_Triage_Cadence_Realignment_Decision_20261027.md` | [Vol_C_CP3_Gate_Turns](M6_Consolidated_Record_Vol_C_CP3_Gate_Turns.md#architecture_m6_cp3_tb45_rev_audit_rail_oracle_triage_cadence_realignment_decision_20261027md) |
| `Architecture_M6_CP3_TB53_REV_Local_Gate_Platform_Attribution_RP01_Closure_20261030.md` | [Vol_C_CP3_Gate_Turns](M6_Consolidated_Record_Vol_C_CP3_Gate_Turns.md#architecture_m6_cp3_tb53_rev_local_gate_platform_attribution_rp01_closure_20261030md) |
| `Architecture_M6_CP3_TB54_REV_O15_Discharge_20261031.md` | [Vol_C_CP3_Gate_Turns](M6_Consolidated_Record_Vol_C_CP3_Gate_Turns.md#architecture_m6_cp3_tb54_rev_o15_discharge_20261031md) |
| `Architecture_M6_CP3_TB76_REV_P13_Census_Path_Cost_Probe_Adjudication_20261104.md` | [Vol_D2_CP3_P13_from_20261104](M6_Consolidated_Record_Vol_D2_CP3_P13_from_20261104.md#architecture_m6_cp3_tb76_rev_p13_census_path_cost_probe_adjudication_20261104md) |
| `Architecture_M6_CP3_TB78_REV_P13_Platform_Split_Adjudication_20261104.md` | [Vol_D2_CP3_P13_from_20261104](M6_Consolidated_Record_Vol_D2_CP3_P13_from_20261104.md#architecture_m6_cp3_tb78_rev_p13_platform_split_adjudication_20261104md) |
| `Architecture_M6_CP3_TB80_REV_Review_Final_Validation_Binding_Per_Vertex_20261105.md` | [Vol_D2_CP3_P13_from_20261104](M6_Consolidated_Record_Vol_D2_CP3_P13_from_20261104.md#architecture_m6_cp3_tb80_rev_review_final_validation_binding_per_vertex_20261105md) |
| `Architecture_M6_CP3_TB81_P13_Final_Validation_Binding_Full_Gate_Execution_Report_20261105.md` | [Vol_D2_CP3_P13_from_20261104](M6_Consolidated_Record_Vol_D2_CP3_P13_from_20261104.md#architecture_m6_cp3_tb81_p13_final_validation_binding_full_gate_execution_report_20261105md) |
| `Architecture_M6_CP3_TB87_REV_P13_A3_Observed_Route_Orientation_Adjudication_20261108.md` | [Vol_D2_CP3_P13_from_20261104](M6_Consolidated_Record_Vol_D2_CP3_P13_from_20261104.md#architecture_m6_cp3_tb87_rev_p13_a3_observed_route_orientation_adjudication_20261108md) |
| `Architecture_M6_DEFN_Diag_Retain_A5_A7_Snapshots_20261031.md` | [Vol_A_Definitions_CP1_CP2](M6_Consolidated_Record_Vol_A_Definitions_CP1_CP2.md#architecture_m6_defn_diag_retain_a5_a7_snapshots_20261031md) |
| `Architecture_M6_DEFN_Diag_Retain_CLI_Materialization_Sidecar_20261031.md` | [Vol_A_Definitions_CP1_CP2](M6_Consolidated_Record_Vol_A_Definitions_CP1_CP2.md#architecture_m6_defn_diag_retain_cli_materialization_sidecar_20261031md) |
| `Architecture_M6_DEFN_Diag_Retain_GUI_Layers_20261031.md` | [Vol_A_Definitions_CP1_CP2](M6_Consolidated_Record_Vol_A_Definitions_CP1_CP2.md#architecture_m6_defn_diag_retain_gui_layers_20261031md) |
| `Architecture_M6_DEFN_Diag_Retain_Materialization_Display_20261031.md` | [Vol_A_Definitions_CP1_CP2](M6_Consolidated_Record_Vol_A_Definitions_CP1_CP2.md#architecture_m6_defn_diag_retain_materialization_display_20261031md) |
| `Architecture_M6_DEFN_R1_Review_Record.md` | [Vol_A_Definitions_CP1_CP2](M6_Consolidated_Record_Vol_A_Definitions_CP1_CP2.md#architecture_m6_defn_r1_review_recordmd) |
| `Architecture_M6_DEFN_R1_Seam_Incident_Occurrence_Sheet_Authority_Definition_Record.md` | [Vol_A_Definitions_CP1_CP2](M6_Consolidated_Record_Vol_A_Definitions_CP1_CP2.md#architecture_m6_defn_r1_seam_incident_occurrence_sheet_authority_definition_recordmd) |
| `Architecture_M6_DEFN_R2_Review_Record.md` | [Vol_A_Definitions_CP1_CP2](M6_Consolidated_Record_Vol_A_Definitions_CP1_CP2.md#architecture_m6_defn_r2_review_recordmd) |
| `Architecture_M6_DEFN_R2_Seam_Incident_Authority_Amendment_Definition_Record.md` | [Vol_A_Definitions_CP1_CP2](M6_Consolidated_Record_Vol_A_Definitions_CP1_CP2.md#architecture_m6_defn_r2_seam_incident_authority_amendment_definition_recordmd) |
| `Architecture_M6_DEFN_R3_A6_Product_Separation_Definition_Record.md` | [Vol_A_Definitions_CP1_CP2](M6_Consolidated_Record_Vol_A_Definitions_CP1_CP2.md#architecture_m6_defn_r3_a6_product_separation_definition_recordmd) |
| `Architecture_M6_DEFN_R3_Review_Record.md` | [Vol_A_Definitions_CP1_CP2](M6_Consolidated_Record_Vol_A_Definitions_CP1_CP2.md#architecture_m6_defn_r3_review_recordmd) |
| `Architecture_M6_DEFN_R4_A7_Boundary_Definition_Record.md` | [Vol_A_Definitions_CP1_CP2](M6_Consolidated_Record_Vol_A_Definitions_CP1_CP2.md#architecture_m6_defn_r4_a7_boundary_definition_recordmd) |
| `Architecture_M6_DEFN_R4_Review_Record.md` | [Vol_A_Definitions_CP1_CP2](M6_Consolidated_Record_Vol_A_Definitions_CP1_CP2.md#architecture_m6_defn_r4_review_recordmd) |
| `Architecture_M6_DEFN_R5_CP3_Entry_Definition_Record.md` | [Vol_A_Definitions_CP1_CP2](M6_Consolidated_Record_Vol_A_Definitions_CP1_CP2.md#architecture_m6_defn_r5_cp3_entry_definition_recordmd) |
| `Architecture_M6_DEFN_R5_R1_CP3_Entry_Recovery_Definition_Record.md` | [Vol_A_Definitions_CP1_CP2](M6_Consolidated_Record_Vol_A_Definitions_CP1_CP2.md#architecture_m6_defn_r5_r1_cp3_entry_recovery_definition_recordmd) |
| `Architecture_M6_DEFN_R5_R2_CP3_Entry_Recovery_Definition_Record.md` | [Vol_A_Definitions_CP1_CP2](M6_Consolidated_Record_Vol_A_Definitions_CP1_CP2.md#architecture_m6_defn_r5_r2_cp3_entry_recovery_definition_recordmd) |
| `Architecture_M6_DEFN_R5_R2_Review_Record.md` | [Vol_A_Definitions_CP1_CP2](M6_Consolidated_Record_Vol_A_Definitions_CP1_CP2.md#architecture_m6_defn_r5_r2_review_recordmd) |
| `Architecture_M6_DEFN_R5_R3_CP3_Entry_Recovery_Definition_Record.md` | [Vol_A_Definitions_CP1_CP2](M6_Consolidated_Record_Vol_A_Definitions_CP1_CP2.md#architecture_m6_defn_r5_r3_cp3_entry_recovery_definition_recordmd) |
| `Architecture_M6_DEFN_R5_R3_Review_Record.md` | [Vol_A_Definitions_CP1_CP2](M6_Consolidated_Record_Vol_A_Definitions_CP1_CP2.md#architecture_m6_defn_r5_r3_review_recordmd) |
| `Architecture_M6_DEFN_R5_R4_DIAG_Diagnostic_Fidelity_Audit.md` | [Vol_A_Definitions_CP1_CP2](M6_Consolidated_Record_Vol_A_Definitions_CP1_CP2.md#architecture_m6_defn_r5_r4_diag_diagnostic_fidelity_auditmd) |
| `Architecture_M6_DEFN_R5_R4_Independent_Review_Record.md` | [Vol_A_Definitions_CP1_CP2](M6_Consolidated_Record_Vol_A_Definitions_CP1_CP2.md#architecture_m6_defn_r5_r4_independent_review_recordmd) |
| `Architecture_M6_DEFN_R5_Review_Record.md` | [Vol_A_Definitions_CP1_CP2](M6_Consolidated_Record_Vol_A_Definitions_CP1_CP2.md#architecture_m6_defn_r5_review_recordmd) |
| `Architecture_M6_TB60_Diag_Retain_GUI_Full_Gate_Local_Test_Report_20261031.md` | [Vol_A_Definitions_CP1_CP2](M6_Consolidated_Record_Vol_A_Definitions_CP1_CP2.md#architecture_m6_tb60_diag_retain_gui_full_gate_local_test_report_20261031md) |
