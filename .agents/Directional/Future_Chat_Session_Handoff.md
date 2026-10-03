## Resume-critical update — `M6-DEFN-R4-REV` COMPLETE: R4 accepted with RA-18 – RA-21; exact next `M6-CP1-CB9-A7` (2026-10-03)

**Start `M6-CP1-CB9-A7` as a new runtime-free Code + Build turn.** Follow `Architecture_M6_CP1_CB9_A7_Code_Build_Plan.md`; its **RA-18 block at the top overrides the body**.

Review accepts R4's D4 census, D1 projection and transport guard, D2 partition, and D5 sequencing. It verified the D2 pinned-literal claim independently: only rows 212, 227/230 and 139/140/142 pin adapter literals. It also freezes four amendments:

1. **RA-18 (D1).** The adapter's `1e-9` check is the only place anything verifies that relation-united occurrences are the same source point; A4/A5/A6 never compare them. Equal edge or face support does not imply the same point. So A7's support certificate becomes:
   - typed exact common support, from A5 `occurrence.support` only, **plus**
   - a reject-only same-simplex point-coincidence guard: edge parameter `t`, or face barycentrics, within the A5 resolver tolerance (`SourceSupportPointMismatch`).

   Identity 15 is renamed to `M6CP1.A7RejectsSupportKindIdentityAndSameSimplexPointMismatches`. My earlier R4 plan / RA-17 wording ("diagnostic only") caused this gap.
2. **RA-19 (D2, for CB10).** Moved A5 checks go after every existing A5 check. Identity 24 becomes `M6CP1.ThinAdapterOutputIsPureProjectionOfStageProducts`; the source rule becomes a static check.
3. **RA-20 (D3, for CB11).** Candidate protection comes from the source hard-feature edge set, not relation kind. The torus's 18 user hard edges are PeriodicCut carriers, not A5 HardRail relations, so R4's rule would have left them unprotected.
4. **RA-21 (D3, for CB11).** The equivalence oracle's key path is `(proposalId, proposalSide)` → A4 `CellId`/side, with a stop rule. Arrangement nodes carry no occurrence members.

Gates are unchanged: CB9 **20+449 = 469** → TB9 → mandatory TB9 Review. Accounting **60 / 16 / 44**, debt 1. R5 remains a CP3-entry gate.

## Superseded — `M6-DEFN-R4` completion note


`M6-DEFN-R4` is durably complete. Do not resume the Definition turn and do not start CB9. Start mandatory runtime-free `M6-DEFN-R4-REV` and review the frozen R4 A7 / thin-adapter / `G4-B002` boundary before any implementation.

Completed in the verified exact snapshot (`c7deb092e86f0912a304397e364d47dc94587a5a`):
- D4: complete 1,189-site consumer/frozen assertion census.
- D1: A7 product, exact typed SourceSupport certificate, deterministic representation-only representative, complete lineage projection, RA-17 transport guard, typed failures and hash disposition.
- D2: all 55 direct adapter failure sites classified 31/4/19/1 across A5/A6 projection/A7/serialization; thin predicate and failure precedence frozen.
- D3: A6 `SurfaceQuotientClosedComplexView`; side-incidence multigraph identity; exact HardRail/Periodic labels; opposite-edge strip identity; produced closed torus labeled combinatorial-isomorphism migration proof; independent candidate mechanism oracle; CP3 direct-production debt unchanged.
- D5: CB9 A7 focused 13-20 -> 469 gate; CB10 A5V focused 21-24 -> 473; CB11 G4 focused 25-28 -> 477; each CB -> immutable TB -> mandatory Review; then CP1 close Review. First A7 CB includes the real production completion-ownership witness.
- Three held Code + Build plans are written. R5 gauge obligations remain CP3-entry only.

Accounting stays **60 / 16 / 44**, debt 1. No source/test/fixture/selector/build/runtime implementation occurred in R4. The exact R4 documentation patch was applied by Actions run `37144877459` as commit `0f3024732e2f16b35c8c2a787a519378af2b9591`; the workload recorded `runtimeExecution=false`. Mandatory successor is `M6-DEFN-R4-REV`; CB9 remains held until that Review accepts or amends the definitions.

## Resume-critical update — `M6-CP1-TB8-A6-REV` review-agent addendum: promotion confirmed; R4 bounded by plan + RA-17 (2026-10-03)

**Start `M6-DEFN-R4` as a new runtime-free Definition turn.** Follow `Architecture_M6_DEFN_R4_CP1_A7_Thin_Adapter_G4B002_Definition_Plan.md`. Do the D4 consumer census FIRST.

The addendum confirms TB8 (461/461) and the promotion of `11265967968 / 8e0818b1...`. Focused 1-12 (`Architecture_M6_CP1_Required_Green_Focused_12.txt`) is now a required-green prefix of every M6 gate.

RA-17 makes three changes:
1. **Transport guard.** A6 placement transport is consumed only by the strict cycle rule. A7, the adapter, lineage and completion never consume it.
2. **R4 is bounded to CP1 exit:**
   - A7 representation, with an exact `SourceSupport` incidence predicate replacing the adapter's `1e-9` position check;
   - classification of the adapter's 55 failure sites;
   - the `G4-B002` A6 boundary and its equivalence demonstration;
   - CB sequencing;
   - the witness production-completion identity for the first A7 CB.
3. **The three gauge obligations move to `M6-DEFN-R5`** (CP3-entry gate, not CP1): the periodic face-gauge witness, HardRail branch certification, and OrdinaryFront identity across isolation seams.

Correction: TB8-REV §3's claim that 446 proves production-completion compatibility is an inference. The witness has never run through `validate_materialized_completion_domain_ownership`.

Accounting is **60 / 16 / 44**, debt 1. No A7/G4 implementation before `M6-DEFN-R4-REV`.

## Superseded — `M6-CP1-TB8-A6-REV` pre-addendum resume note (R4 scope replaced by the R4 plan and RA-17)


**Start `M6-DEFN-R4` as a new runtime-free Definition turn. Do not rerun TB8 and do not begin A7/G4 implementation before R4 Review.**

Independent Review re-opened candidate `11265967968 / 8e0818b1e2f8d12b86c64d8774a3572c5ed5266c` and TB8 result `11273611682` directly. Candidate ZIP/root manifest/source archive, selector449/routing449, 954/954 result manifest, all 461 ledgers, exact-one/zero-skip boundary, critical controls and immutable postflight verify. TB8 is authoritative **461/461 PASS**. The prior TB7 HardRail placement, route-validation-order and lineage-value stable events are **RECOVERY PROVED**; append-only accounting remains **60 / 16 / 44**, debt 1.

Candidate `11265967968 / 8e0818b1...` is now the **current reviewed M6 runtime authority**, selector449 449/449. CP1 remains open on the deliberately deferred A7 product/thin adapter and `G4-B002` A6-derived stage boundary.

Exact next `M6-DEFN-R4` must freeze A7 representation/certificates, the `G4-B002` boundary representation/equivalence proof, the carried unequal-face-gauge periodic witness + coordinate/relation-gauge rule, HardRail cross-region branch certification, OrdinaryFront coordinate identity across isolation seams, and the bounded implementation/gate sequence. Full Review authority: `Architecture_M6_CP1_TB8_A6_Review_Record.md`.

## Resume-critical update — `M6-CP1-TB8-A6-EXEC` COMPLETE / 461/461 mechanically GREEN / mandatory Review next (2026-10-03)

**Start `M6-CP1-TB8-A6-REV` as a new runtime-free Review turn. Do not rerun TB8, modify the candidate, or begin R4/A7/G4 first.**

TB8 consumed CB8 candidate `11265967968 / 8e0818b1e2f8d12b86c64d8774a3572c5ed5266c` immutably. Runtime run/job `37121395619 / 111198068572` completed exactly **12 focused + selector449 = 461** fresh exact-filter processes: focused **12/12**, selector **449/449**, aggregate **461/461 PASS**, exact-one selection, zero skips, benchmark 0. Result/log artifacts `11273611682 / 11274345428` have digests `sha256:55647d752e97cb71062c23475fe76bb870d0329c5f957ca819ccebc809e6ad05` / `sha256:36f674b7dd8eab84b1ad3c9c2486ce94f8a369f81994da3418b1c41fcb34d98e`; result self-manifest verifies **954/954**.

Focused12 passes; all prior TB7 RED rows `115,116,122,130,132,134,137,141,143,150,176,201,217,227,230,231,446` recover. Focused6/10/11 and selectors139/140/142/232/444/446/448/449 all PASS. Raw diagnostic census is zero for `QuotientHolonomyConflict`, `OccurrenceInvalidCornerAuthority`, `InvalidHardRailTransport` and `RelationCertificateConflict`. Package/source/execution-view/fixture postflight is immutable and selector/routing bytes remain unchanged.

EXEC records no new candidate and does not reprice stable history: **60 / 16 / 44**, debt 1. Candidate remains unpromoted until Review; reviewed runtime authority remains TB5 `10879581622 / 82b86a28...`. Full evidence: `Architecture_M6_CP1_TB8_A6_Artifact_Only_Test_Benchmark_Report.md`.

**Exact next:** mandatory runtime-free `M6-CP1-TB8-A6-REV`; adjudicate recovery/promotion and authorize the next M6 turn. R4/A7/G4 remain held.

## Resume-critical update — `M6-CP1-CB8-A6` COMPLETE / compile-package GREEN / exact next `M6-CP1-TB8-A6-EXEC` (2026-10-03)

**Start `M6-CP1-TB8-A6-EXEC` as a new artifact-only Test + Benchmark turn. Do not resume CB8 and do not begin R4/A7/G4 first.**

CB8 implements normative RA-16 and closes runtime-free at repaired semantic source `8e0818b1e2f8d12b86c64d8774a3572c5ed5266c`. The source separates A6 placement transport from the M5 lineage relation value, derives HardRail placement transport from occurrence-placement coordinates with no branch comparison, moves exact route validity into A5, strengthens focused 3 and adds focused 12. `PureQuadCompletion.cpp`, selector/routing bytes, fixtures and A7/R4/G4 remain unchanged.

The initial compile on semantic commit `2b182f1c...` failed only because new focused-test code referenced `first_edge_of_kind` before its later declaration. A bounded test-local declaration-order repair produced exact source `8e0818b1...`. Authoritative compile retry `37101997642 / 111143233041` is GREEN for all eight standard GMP/GMPXX targets with `runtimeExecution=false`. Candidate/result artifact `11265967968` has digest `sha256:022a35378a58463b892f1bf1d5113f726c2cc7cb8939892b24acd1da62259c4b`; compile log `11266127622` has digest `sha256:a435590a67884432e848298ab064934b04d39674831340854bfbc2c1bcf474cd`.

Full Code + Build evidence and the required pre-CB7 lineage proof are in `Architecture_M6_CP1_CB8_A6_Code_Build_Report.md`.

**Exact TB8 gate:** focused 1-12 in order, then selector449 in file order with routing449 = **461 fresh exact-filter processes**, benchmark 0. Recovery-green is **461/461**. Mandatory successor is `M6-CP1-TB8-A6-REV`. Stable accounting remains **60 / 16 / 44**, debt 1; reviewed runtime authority remains TB5 `10879581622 / 82b86a28...` until Review. R4/A7/G4 remain held.

## Resume-critical update — `M6-CP1-TB7-A6-REV` review-agent addendum: RA-16; CB8 plan amended; TB8 = 12+449=461 (2026-10-03)

**Start `M6-CP1-CB8-A6` as a new runtime-free Code + Build turn.** Follow the **review-agent amendment block** at the top of `Architecture_M6_CP1_CB8_A6_HardRail_Placement_Transport_Recovery_Code_Build_Plan.md`. It overrides the plan body.

The addendum confirms TB7's evidence and the diagnoses of Findings A and B. It changes the following:

1. **Selector446 is not stale.** CB7 coupled the M5 lineage `SelectedRelationStep.appliedTransport` to the A6 placement transport (`RemeshPipeline.cpp:4357`, `:4723`, `:4749`).
   - Production completion (`PureQuadCompletion.cpp:1086-1132`, run at `RemeshPipeline.cpp:10705-10719`) compares that step with the relation value. So would every Q≠0 periodic relation fail in production.
   - 446 restates that check. CAND-03 is now a stable RP-01 recurrence → **60 / 16 / 44**, debt 1.
   - Fix: A5 publishes `canonicalRelationValue` (the M5 value) separately from `canonicalTransport` (placement, A6 only).
   - Do **not** edit selector446 or `PureQuadCompletion.cpp`.
2. **The RA-14 HardRail derivation is face-gauge dependent.** `branchRotation` carries the per-face, per-region `faceBranchRotation`, so a branch difference across a rail includes the field matching.
   - Replacement (RA-16 §2): a coordinate-rigid derivation from the endpoint occurrences' `placement.lattice`, with no branch comparison.
3. **Route validity is A5-owned** (RA-16 §5): one extracted predicate, applied to both HardRail sides before any pair predicate.
4. **The gate gains focused identity 12**, `M6CP1.RelationPlacementTransportIsCoordinateRigidAndFaceGaugeInvariant`, which includes a branch-relabel invariance check. TB8 = **12+449 = 461**.

Load:
- the CB8 plan (amendment block first);
- `Architecture_M6_Frozen_Definitions.md` RA-16 (end of file);
- `Architecture_M6_CP1_TB7_A6_Review_Record.md` addendum §G1-§G7;
- the tracker head entry;
- `CODE_BUILD.md`, the workflow policy and the tool-use conservation policy.

R4/A7/G4 remain held.

## Superseded — `M6-CP1-TB7-A6-REV` pre-addendum resume note (its CB8 scope is replaced by RA-16; do not act on it)

TB7 runtime is authoritative semantic RED at **443/460** (11/11 focused + 432/449 selector). Review prices two stable recurrences: HardRail route-carrier vs placement transport (`RP-01`) and route-validation precedence (`VALIDATION_ORDER_SHADOWING`). Selector446 is closed non-stable test authority. Stable accounting is **59 / 16 / 43**, debt 1. Candidate `11257522199 / 40842caa...` is rejected/unpromoted; reviewed runtime stays TB5 `10879581622 / 82b86a28...`, selector449 449/449.

RA-14 freezes HardRail carrier/placement separation and RA-15 freezes individual-route-before-pair validation. Exact next is `M6-CP1-CB8-A6`, bounded to those two repairs plus selector446's gauge-aware assertion migration. Compile/package green -> `M6-CP1-TB8-A6-EXEC` exact **11+449=460** -> mandatory `M6-CP1-TB8-A6-REV`. R4/A7/G4 remain held.

Load `Architecture_M6_CP1_TB7_A6_Review_Record.md`, `Architecture_M6_CP1_CB8_A6_HardRail_Placement_Transport_Recovery_Code_Build_Plan.md`, `Architecture_M6_Frozen_Definitions.md` (RA-14/RA-15), TB7 report, tracker, `CODE_BUILD.md`, workflow policy and tool-use conservation policy.

### Superseded resume note
## Resume-critical update — `M6-CP1-TB7-A6-EXEC` COMPLETE / mechanically valid 443/460 RED; exact next `M6-CP1-TB7-A6-REV` (2026-10-03)

**Start `M6-CP1-TB7-A6-REV` as a new runtime-free Review turn.** Do not rerun or repair TB7-A6 and do not begin `M6-DEFN-R4`, A7, `G4-B002`, `G4-B004` representative-consumption, or direct-torus work.

TB7-A6 consumed CB7 candidate `11257522199 / 40842caa88f8d7a08a38c91273ace77ebd7c0676` immutably. Runtime run/job `37090507571 / 111109661723` completed the exact **11 focused + selector449 = 460** fresh exact-filter processes with exact-one selection, zero skips, benchmark 0 and clean immutable postflight. Result/log artifacts are `11262587435 / 11262387973`, digests `sha256:87cfcda2502f10cfc74e04aecd6e32aaca629928dff966988f52751f59e44575` / `sha256:99008db67dd27e673f642ce341dfb93278674b768df709a593de7a77bcdfe92a`.

**Mechanical outcome:** focused **11/11 PASS**, selector **432/449 PASS**, aggregate **443/460 PASS / 17 RED**. RED selector ordinals are `115,116,122,130,132,134,137,141,143,150,176,201,217,227,230,231,446`. There are zero raw `QuotientHolonomyConflict` and zero `OccurrenceInvalidCornerAuthority`. Focused6/10/11 and selectors139/140/142/232/444/448/449 PASS. Relative to TB6, focused6 and rows139/142 recover; row446 remains RED with a different first failure; 16 accepted-green selector identities newly turn RED.

Three non-stable Review-owned candidates are recorded in the TB7 report/tracker:
- `...CAND-01`: HardRail `route.composed_transport()` is being treated as a placement-gauge map even though exact source builds retained HardRail transition steps with identity transport; direct valid rows reject `InvalidHardRailTransport` and downstream feature-chain rows become unreachable. Candidate category `RP-01 / AUTHORITY_DOMAIN_CONFLATION`.
- `...CAND-02`: rows227/230 still fail closed, but CB7's earlier reciprocal-route check returns `InvalidHardRailTransport` before their accepted `InvalidHardRailAuthority` route-topology failure. Candidate `VALIDATION_ORDER_SHADOWING`.
- `...CAND-03`: row446 now materializes successfully and no longer produces `QuotientHolonomyConflict`; only its selected-certificate assertion remains RED because it compares RA-13 placement-gauge `appliedTransport` against the relation-endpoint/stored `SurfacePeriodicHolonomy::action()`. Candidate `RP-05 / REPRESENTATION_DEPENDENT_IDENTITY` / test-authority.

EXEC performs no stable repricing: accounting remains **57 / 16 / 41**, debt 1. Candidate stays unpromoted; reviewed runtime authority remains `10879581622 / 82b86a28...`, selector449 **449/449**.

Historical TB7-EXEC resume set is now resolved by the retained TB7 report plus `M6_Consolidated_Record.md` §§25-27/folded index and `Architecture_M6_Frozen_Definitions.md` RA-13.

### Superseded by the 2026-10-02 review-agent addendum — `M6-CP1-TB6-A6-REV` COMPLETE / candidate rejected; exact next `M6-CP1-CB7-A6` (2026-09-29 UTC)

**Do not resume TB6-A6 and do not start R4/A7/`G4-B002`.** The mandatory Review found a mechanically valid authoritative TB6-A6 run and rejected candidate `10896307843 / a532f803...`.

- Authoritative TB6-A6 run/job: `36362570974 / 108742561290`; result/log artifacts `10947080007 / 10946089412`; result manifest **946/946**. Frozen gate executed exactly **11 focused + selector449 = 460** fresh exact-filter processes, exact-one selection and zero skips; outcome **456/460 PASS**.
- The earlier failed run `36362470435` is orchestration-invalid/no-credit. The prior EXEC report's statement that no authoritative runtime existed is superseded by Review reconciliation.
- Exact RED set: focused6 and selector446 first-fail `QuotientHolonomyConflict`; selector139 and 142 unexpectedly succeed instead of the accepted `InvalidHardRailTransport` rejection. All four new A6 focused identities 8-11 PASS; controls 140/232/444/448/449 and focused5/7 PASS.
- Review invokes the frozen R3 residual-holonomy fallback. For direct canonical transport `D:a->b` and selected-forest path transport `P:a->b`, cycle-closing A6 evidence publishes `H=compose(P.inverse(),D)`. Nonidentity `H` is exact evidence, not automatic rejection absent an explicit zero-holonomy contract. Frozen definitions are amended accordingly.
- HardRail root is separate: the A5 cutover retained common `HardRailId` ownership but dropped the accepted reciprocal checks `first.sourceTopologyRegion != second.sourceTopologyRegion` and `first.route == second.route.reversed()`. Restore them at A5 publication before evidence becomes immutable.
- Stable accounting is now **57 / 16 / 41**, debt 1. Selector446 is one existing `RP-07 / CYCLIC_TOPOLOGY_LINEARIZATION` recurrence; rows139+142 share one existing `VALIDATION_ORDER_SHADOWING` recurrence.
- Candidate `10896307843` is rejected/unpromoted. Current reviewed runtime authority remains `10879581622 / 82b86a28...`, selector449 **449/449**.

**Historical exact next was `M6-CP1-CB7-A6`.** Its consumed plan is folded into `M6_Consolidated_Record.md` §§25-26 and the folded-document index; CB7/TB7 are now superseded by the current Review authority below.

Historical CB7 implementation authority is preserved in `Architecture_M6_Frozen_Definitions.md` RA-13 and `M6_Consolidated_Record.md` §§25-26/folded index.

## Superseded EXEC-only handoff — `M6-CP1-TB6-A6-EXEC` report was incomplete; Review found an authoritative second run

**Do not rerun TB6-A6 inside EXEC and do not promote candidate `10896307843`.** The frozen 460-process gate did not obtain valid runtime evidence.

- Immutable candidate authority still verifies: artifact/source `10896307843 / a532f803bd2f0ef92342652ea3f1a9b64945ba69`, ZIP `54eb7708...56b7e`, source archive `e48ad4a9...9a45`, root manifest 28/28, selector449 `d4a0d1b7...d6414`, routing449 `9c88a5ed...c5707`, owner census 32/301/75/41.
- The local EXEC attempt failed at the **execution-view orchestration layer**. It ran package binaries directly instead of constructing the standard separate view with packaged-source `benchmarks/fixtures` at adjacent `test-data/benchmarks/fixtures`. Focused row6 and selector ordinals 41/42/43/44/46 all threw the same missing-test-data exception.
- The invalid attempt was stopped after **149 completed processes**: focused 11 and selector ordinals1-138, with 143 process PASS exits and 6 fixture-root failures. Selector139 was in flight. Row140 and holonomy falsifiers 232/444/446/448/449 were not reached. No partial result receives semantic credit.
- Package and packaged-source byte/mode censuses remained unchanged; post-abort root manifest is still 28/28. No configure, compile, relink, fixture/package repair, permission repair, benchmark, or retry occurred.
- Frozen plan says no retry after runtime starts. The turn therefore closes invalid rather than silently re-executing. This superseded EXEC-only interpretation and its correcting TB6 Review are folded into `M6_Consolidated_Record.md` §§24-25 and its folded-document index.
- Stable accounting remains **55 / 16 / 39**, debt 1. Candidate `10896307843` stays unpromoted; reviewed runtime authority remains `10879581622 / 82b86a28...`, selector449 449/449.

**Exact next:** mandatory runtime-free `M6-CP1-TB6-A6-REV`. Review must adjudicate zero semantic credit and explicitly authorize/name any distinct fresh retry turn. Do not begin `M6-DEFN-R4`, A7, or `G4-B002` first.

## Superseded pre-EXEC handoff — `M6-CP1-CB6-A6` COMPLETE; TB6-A6 gate had not yet run

**Do not resume CB6-A6. Do not rebuild or repair candidate `10896307843`.** The Code + Build turn is complete, compile/package green, runtime-free and unpromoted.

**Closed CB6-A6 authority:**
- Semantic source `a532f803bd2f0ef92342652ea3f1a9b64945ba69` = A6 extraction `faca79e3` plus the bounded compile fix. The first compile run/job `36212343902 / 108321392040` failed on declaration clashes; no runtime executed.
- Authoritative Compile R1 run/job `36212725707 / 108322509801` is green. Result artifact `10896307843` has digest `sha256:54eb770889822ef265053494e55e25af79616f77305d1ac6900f2f8969f56b7e`; log artifact `10896347611` has digest `sha256:d0d70351dff0197182a28449361127862d6df404cc6a35d42ace519a9817c98b`. Root manifest is **28/28**; source archive `source-a532f803bd2f0ef92342652ea3f1a9b64945ba69.tar.gz` hashes to `e48ad4a919e450ccd9809083af0c02e2260b7c040d40ee94741aa79428fc9a45`.
- All eight standard GMP/GMPXX targets compiled; preflight/build exit `0/0`; all five source-status receipts are empty; `runtimeExecution=false`, `turnBoundary=Code+Build-only`.
- Static closeout confirms RA-1 – RA-4: certificates use canonical `relation.id.first -> relation.id.second`; OrdinaryFront quotient transport is identity; A6 consumes A5 canonical evidence without dereferencing `firstFrontEdge`/`secondFrontEdge`; selected-path composition uses `path=compose(T,path)` with reverse inversion and cycle-closing mismatch typed as `HolonomyConflict`.
- `SurfaceOccurrence::{chart,lattice,isolationSheet}` are retired; the old cycle-closing skip is gone; exactly four pre-registered A6 focused identities exist; selector449 `d4a0d1b7...d6414` and routing449 `9c88a5ed...c5707` are unchanged.
- Focused row4 `M6CP1.CoincidentUnrelatedOccurrencesRemainDistinct` was mechanically migrated from `a.lattice.latticeCoordinate` to `a.placement.lattice.latticeCoordinate`. The values are identical by construction because both originate from the same `cell.lattice[cornerIndex]`. TB6-A6-REV must explicitly confirm the test meaning is unchanged.
- Prior CB6-A6 compile/snapshot temporary state was retired through cleanup run `36358568335`. Closeout source inspection used verified runtime-free snapshot `36358391103 / 10944138788`; a process-only READ_MODE declaration lag is recorded at +0.
- Durable closeout documentation was applied by Drive run `36359008725` at commit `92c6f75301ead3724fcf2b395676a601128b154f`. The workflow reported owner cleanup required for the staged Drive patch; the user-authorized Drive control plane permanently deleted it. The temporary docs caller was retired first, final cleanup run `36359091897` removed its marker, and end-of-turn inspection shows only the seven durable workflows with trigger/observation/turn-payload directories absent.
- Folded CB6-A6 compile authority: `M6_Consolidated_Record.md` §23; the consumed standalone report remains in git history.

**Exact next:** `M6-CP1-TB6-A6-EXEC` consumes candidate `10896307843` **immutably**. Execute **11 focused + selector449 = 460** fresh exact-filter processes, benchmark 0. Row232 and torus rows444/446/448/449 are the pre-registered holonomy falsifiers. Preserve artifact-only rules: no configure, compile, relink, fixture repair, manifest repair or binary permission repair. Mandatory `M6-CP1-TB6-A6-REV` follows. Do not begin `M6-DEFN-R4`, A7 or `G4-B002` before that Review.

Reviewed runtime authority remains `10879581622 / 82b86a28...`, selector449 449/449. Stable accounting remains **55 / 16 / 39**, debt **1**.

**Frozen gate (review-agent reconciliation, 2026-09-28):** folded authority `M6_Consolidated_Record.md` §24 preserves the exact 460-process order from the consumed TB6-A6 plan.
- Focused 1-7 run in TB5 order, then the four new A6 identities 8-11 in CB6-A6 plan §6 order. All route to `directional_surface_cell_producer_tests`.
- Selector449 follows in file order with routing449.
- Recovery-green also requires no `QuotientHolonomyConflict` anywhere and rows 232/444/446/448/449 PASS.
- Do not improvise the order. Enter TB6-A6-EXEC as a **new** turn: `IN_PROGRESS`, `Successor: UNKNOWN`, new `Started at`, empty `Resumed at` / `Ended at`.

## Superseded resume notes (historical — do not act on)

### `M6-DEFN-R3-REV` accepted R3 with RA-1 – RA-4; A6 CB authorized (2026-09-25)

**Exact next: `M6-CP1-CB6-A6` — Code + Build, compile/package only. Do not start `M6-DEFN-R4`, A7, `G4-B002`, or runtime TB first.**

Independent runtime-free Review accepts the R3 A6 quotient-product design with four binding amendments:
- certificate direction is canonical `relation.id.first -> relation.id.second`; storage-oriented occurrence/front-edge fields are representation provenance only;
- every accepted OrdinaryFront quotient relation transport is identity; isolation-seam quarter-turn remains validating evidence only;
- A5 owned relations must publish enough canonical HardRail/Periodic owner/route/transport evidence for A6 to consume only A0+A5 without representation/global-array lookup; this enriches evidence only and may not change relation identity/equality/owner selection;
- selected-forest path composition is exactly `path=compose(T,path)` in traversal order, using `T.inverse()` for reverse traversal.

The strict direct-vs-path holonomy rule remains binding and the produced cylinder row232 plus torus rows444/446/448/449 remain TB falsifiers. The four new A6 focused identities are unchanged in count; focused storage invariance now also covers canonical certificate direction/transport. Compile-green advances to immutable `M6-CP1-TB6-A6-EXEC`: **11 focused + selector449 = 460** fresh exact-filter processes, then mandatory `M6-CP1-TB6-A6-REV`.

Review snapshot run/artifact `36207017645 / 10894735898` was static/runtime-free; no `src/`, `include/`, or `tests/` file changed relative to current reviewed runtime semantic source `82b86a28...`. Runtime authority remains package/source `10879581622 / 82b86a28...`, selector449 449/449. Stable accounting remains **55 / 16 / 39**, debt **1**. Full Review authority: `Architecture_M6_DEFN_R3_Review_Record.md` and the appended R3-REV amendment in `Architecture_M6_Frozen_Definitions.md`.

### Superseded recovery note — do not resume R3 Review

### `M6-DEFN-R3` bounded definition complete; mandatory Review next (2026-09-25)

**Exact next: `M6-DEFN-R3-REV` — independent runtime-free Review. Do not start `M6-CP1-CB6-A6` first.**

`M6-DEFN-R3` completed the bounded recovery scope from `Architecture_M6_DEFN_R3_CP1_Product_Separation_Plan.md` §5. Normative decisions are in `Architecture_M6_DEFN_R3_A6_Product_Separation_Definition_Record.md` and the appended `M6-DEFN-R3 A6 quotient-product amendment` in `Architecture_M6_Frozen_Definitions.md`.

Frozen for Review:
- CP1 exit checklist keeps A5 + A6 + later A7 + thin adapter + no weld + later `G4-B002` A6 boundary + fresh preservation gate.
- A6 semantic class identity is `pipeline::SurfaceQuotientClassId` = exact sorted unique non-empty member `OccurrenceId` set. The current `authority::QuotientClassId` remains adapter-only lineage ordinal, assigned after lexicographic member-set sorting.
- Every A5-owned relation gets exactly one `QuotientRelationCertificate` and one consumption row. Disposition is `Joining` or `CycleClosing`; cycle-closing relations are no longer skipped.
- Joining relations form a deterministic selected forest. A cycle-closing relation's exact relation-oriented `GridAutomorphism` must equal the exact composed transport of the unique existing forest path, else `QuotientHolonomyConflict`. Non-identity Periodic actions are allowed; direct/path equality is the rule.
- Split square, planar uniform hard-rail rectangle and ordinary-identity classes satisfy the rule analytically. Produced cylinder selector row232 and torus rows444/446/448/449 are TB falsifiers. A documented evidence-only fallback is Review-only; CB/TB may not weaken the rule.
- Selected relation paths are A6 authority. A7 only projects them; legacy lineage `selectedRelationPaths` remains HardRail/Periodic-only, preserving split-square emptiness and current relation-local chart/component semantics.
- A6 typed failure vocabulary and adapter-only legacy mappings are frozen.
- First implementation plan was the now-consumed CB6-A6 plan, folded into `M6_Consolidated_Record.md` §§23-25; it absorbed legacy-field retirement and pre-registered four new focused identities. Compile-green would later advance to **11 focused + selector449 = 460** immutable processes.
- A7 product representation and the exact `G4-B002` stage-boundary representation are deferred to `M6-DEFN-R4`; R3 records intent only.

Source inspection was from snapshot run/artifact `36199074014 / 10890838063`; no Directional runtime or compile occurred. Stable accounting remains **55 / 16 / 39**, produced-witness debt **1**, current reviewed runtime authority remains `10879581622 / 82b86a28...`, selector449 remains 449/449.

### Superseded recovery note — do not resume R3

#### Historical recovery instruction — R3 was incomplete at 2026-09-25T21:13:47Z

**Resume `M6-DEFN-R3` — the same incomplete turn.** Keep `Started at 2026-09-25T20:10:00Z`, set a new `Resumed at`, and keep `Status: IN_PROGRESS`, `Successor: UNKNOWN` and an empty `Ended at`. Never write the literal `NONE`.

**Recovery facts** (verified by the review agent at 2026-09-25T21:13:47Z):
- The first R3 session wrote only a start beacon (`cd084a0d`, 20:41:49Z), and that beacon was non-canonical (`NONE` values).
- There is no definition record, no source snapshot (no Actions run after 19:07Z) and no Drive patch.
- The operator loop then recorded `CHAT_UNKNOWN` twice.
- The beacon has been repaired to canonical form.

**Scope is now bounded** (`Architecture_M6_DEFN_R3_CP1_Product_Separation_Plan.md` §5 overrides §2). R3 decides only what the first A6 extraction CB needs:
- the CP1 exit checklist;
- A6 class identity (member set vs the RA-10 ordinal);
- exact-once ledger and cycle-closing holonomy rule;
- selected-path ownership;
- A6 failure names;
- the A6 CB plan with pre-registered focused identities;
- its frozen-test audit.

The A7 product and the `G4-B002` boundary are deferred to `M6-DEFN-R4`. The holonomy rule is proved **analytically only** (split square, uniform rectangles, ordinary-only classes). For produced torus and cylinder fixtures it is pre-registered as a TB falsifier with a documented evidence-only fallback, because no runtime-free static proof is possible there.

Work incrementally: preserve each decided item to Drive or the branch.

### `M6-CP1-TB5-REV` review-agent addendum: CP1 scope corrected; CB6 HELD; exact next `M6-DEFN-R3` (2026-09-25)

**Start runtime-free `M6-DEFN-R3` as a new turn** (Definition amendment and CP1 sequencing). **Do not start CB6 as planned, and do not close CP1.**

The review agent upheld TB5 (456/456), the TB1/TB3/TB4 formal recovery, accounting 55/16/39 with debt 1, the runtime promotion of `10879581622 / 82b86a28...`, and the withdrawal of the B6.2 sort debt.

It **corrected the CP1 scope.** TB5-REV said CP1 was held "only" by three legacy A5 fields. Frozen §10 requires complete **A6 quotient and A7 geometry products** behind stage APIs, with a thin adapter, and §8.1 requires the `G4-B002` A6 stage boundary. None exists:
- 0 A6/A7 product types in source;
- a 1,768-line transitional materializer still owns every quotient and embedding decision;
- §4.4 exact-once consumption is unimplemented (`:5179` skips cycle-closing relations with no certificate or holonomy check);
- the §4.3 member-set `QuotientClassId` is deferred (RA-10);
- candidate extraction still consumes `SurfaceCellComplex`.

CB6 (field retirement) is folded into the first A6 extraction CB. See `M6_Consolidated_Record.md` §§22-23 and `Architecture_M6_DEFN_R3_CP1_Product_Separation_Plan.md`.

### `M6-CP1-TB5-REV` COMPLETE / runtime recovery accepted / CP1 held only by legacy A5 fields / exact next `M6-CP1-CB6` (2026-09-25)

**Start bounded runtime-free `M6-CP1-CB6`; do not rerun TB5, reopen CB5, start CP2, or close CP1 first.**

Independent TB5 Review re-opened CB5 package `10879581622 / 82b86a285292379cfd92cdc4e10d74181b38f1e8`, TB5 run/job `36172157965 / 108194136911`, result/log `10880392759 / 10880502706`, and exact current source. TB5 is upheld at **7/7 focused + 449/449 selector = 456/456 PASS**, exact-one, zero skips/crashes/mismatches, benchmark 0 and immutable postflight. The complete TB4 21-row loss set and the torus pair-swap/444/446/448 falsifier recover.

Review formally marks the TB1 `CROSS_TEMPORARY_ITERATOR_RANGE` event and the TB3/TB4 `RP-01 / AUTHORITY_DOMAIN_CONFLATION` recurrences **RECOVERY PROVED**; TB2 validation-order recovery remains proved. Historical stable accounting does not shrink: **55 events / 16 categories / 39 recurrences**. Produced-witness debt remains **1**, owned by M6-CP3 direct-production proof.

CB5/TB5 artifact/source `10879581622 / 82b86a28...` is promoted as the **current reviewed runtime authority under unchanged selector449 449/449**. `M6-CP1` nevertheless remains **OPEN** because the public A5 `SurfaceOccurrence` still exposes unread representative fields `chart`, `lattice`, and `isolationSheet`, contrary to frozen §3.2/RA-11. Exact source has zero C++ readers for all three; `point` is live and `chartComponent` is legitimate. The old TB4-REV “unsorted aggregated equivalences” debt is withdrawn: exact candidate source already sorts and de-duplicates `lineage.equivalences` after tuple remap.

`M6-CP1-CB6` removes only those three dead members plus their constructor/call-site arguments, changes no tests/fixtures/selectors/semantic relation authority, and compile/packages the standard eight GMP/GMPXX targets with no runtime. Compile-green advances to immutable `M6-CP1-TB6-EXEC`, unchanged **7 + 449 = 456**, then mandatory `M6-CP1-TB6-REV`. Full TB5 Review authority is folded into `M6_Consolidated_Record.md` §§22-23; the retired per-turn text is resolved by its folded-document index.

### `M6-CP1-TB5-EXEC` COMPLETE / 456/456 mechanically green / exact next `M6-CP1-TB5-REV` (2026-09-25)

**Start mandatory runtime-free `M6-CP1-TB5-REV`; do not rerun TB5, resume CB5, promote the candidate, or start another Code + Build turn first.**

TB5 consumed CB5 candidate artifact/source `10879581622 / 82b86a285292379cfd92cdc4e10d74181b38f1e8` immutably and executed the complete frozen gate in run/job `36172157965 / 108194136911`: **7/7 focused + 449/449 selector = 456/456 PASS**. Every process selected exactly one test with zero skips/crashes/selection mismatches; benchmark 0; no timeout/watchdog; exact package/source/execution-view postflight is unchanged.

Recovery evidence is complete at EXEC mechanics:
- all **21** TB4 newly-lost accepted selector identities recover;
- focused pair-swap row6 and torus selector **444/446/448** recover;
- focused multi-isolation row5 and new seam-endpoint/wedge-lineage row7 remain PASS;
- row140 remains PASS and selector449 is restored to **449/449**;
- no raw gate log contains `OccurrenceInvalidCornerAuthority` or any RA-12 legacy isolation-failure prefix.

Result/log authority is `10880392759 / 10880502706`; provider/download SHA-256 values are `71095935dedf52277df946e05cf181713ecb0ebe0842aa91f35ab9b65dd91216 / 0a41be59d2c31138623e770eb6fb30202fa6e511aad691343f40cfee5e3e29df`. Result self-manifest verifies **933/933** and the complete execution ledger hashes `06c1d0166ac0165d4a931c10d2aa4f95b433b05f7a40217f7c8003de3d460a11`.

EXEC records **no new regression candidate** and performs no stable repricing. Stable accounting remains **55 / 16 / 39**, debt **1**. Candidate `10879581622` remains unpromoted and accepted runtime authority remains M5 package/source `10814505512 / e284fea7c101eb86650d1c87c92d0fefa66050e7` under selector449 449/449 until Review. Formal closure/recovery of TB1/TB3/TB4 events, candidate promotion, CP1 acceptance, and any debt/accounting effect belong to Review.

The historical TB5 execution and then-open CP1 acceptance preconditions are preserved in `M6_Consolidated_Record.md` §§21-23; retired report text is resolved by the folded-document index.

### Superseded live note — `M6-CP1-CB5` COMPLETE / compile-green candidate / exact next `M6-CP1-TB5-EXEC` (2026-09-25)

**Start immutable artifact-only `M6-CP1-TB5-EXEC`; do not resume CB5 and do not rebuild the candidate.** TB5 executes the unchanged frozen surface: **7 focused + selector449 = 456** fresh exact-filter processes, then mandatory `M6-CP1-TB5-REV`.

CB5 made only the bounded A6 reciprocal `OrdinaryFront` correction authorized by TB4 Review. Matching source-edge-collinear spans with **no exact isolation certificate** now use the same non-seam P2 predicate as ordinary spans: exact interior-sheet equality plus membership of that sheet in both endpoint wedge sets. Certificate-backed spans retain the prior exact seam face/sheet/reciprocal-transition validation. No A5 product/schema/support rule, test, fixture, selector, HardRail, Periodic, or frozen-definition byte changed.

RA-12 diagnostics are also implemented: legacy `Missing/InvalidIsolationSeamEquivalenceAuthority` names remain prefixes and every remaining emission is site-qualified (`:a5-wedge`, `:a5-side`, `:a6-side-evidence`, `:a6-seam-span-transition`, `:a6-seam-faces`). The former no-certificate collinear-span failure site is removed by the semantic correction; a failed non-seam predicate is `QuotientReciprocalSideAuthorityMismatch`.

Authority/evidence:
- semantic patch commit: `2ec8c7358858f0b74ce6fc2a30c55d366b53ba71`; compile source: `82b86a285292379cfd92cdc4e10d74181b38f1e8`;
- patch apply run/job `36168631350 / 108182514195`; exact patch SHA-256 `c4789d192ab48dd5137fd2de7121d85538635f5156e3f23a058423a949a79324`;
- mandatory compile run/job `36168827294 / 108183151046`; result artifact `10879581622`, SHA-256 `578845a2135ef2296e982e8bac9a378b7659d2968aa9ab5b2702f841288d57c6`; log artifact `10879491574`, SHA-256 `a67873ca9bb8ef0e447ed16badff37bcd602a4aad363ed31f9c42ca9c7af516c`;
- all eight standard targets compiled/linked; mandatory GMP/GMPXX evidence is present; root package manifest **28/28** verifies; all packaged source-status receipts are empty; `preflight=0`, `build=0`, `runtimeExecution=false`;
- selector449 remains byte-identical at `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`; routing449 remains `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707`.

CB5 grants **no runtime credit or promotion**. Stable accounting remains **55 / 16 / 39**, debt **1**. Accepted runtime authority remains M5 package/source `10814505512 / e284fea7c101eb86650d1c87c92d0fefa66050e7` under selector449 **449/449**. The CB5 candidate is unpromoted until TB5 + Review.

TB5 recovery remains a falsifiable prediction, not a CB5 claim: the 21 TB4 newly-lost accepted rows should recover; the multi-sheet torus rows (focused 6, selectors 444/446/448) may expose another RA-12-qualified site. Any RED is Review-owned and must not be repaired inside TB5. The CP1-acceptance debt for legacy `SurfaceOccurrence.isolationSheet/chart/lattice` remains open.

Full implementation and consumed CB5 plan authority are folded into `M6_Consolidated_Record.md` §§20-21 and its folded-document index.


### `M6-CP1-TB4-REV` COMPLETE; exact next `M6-CP1-CB5` (2026-09-25)

**Do not rerun TB4 and do not resume CB4. Start bounded runtime-free `M6-CP1-CB5`, then immutable `M6-CP1-TB5-EXEC`, then mandatory `M6-CP1-TB5-REV`.**

Independent Review upholds TB4 mechanics at focused **6/7** + selector449 **425/449** = **431/456 PASS**, but adjudicates `M6-CP1-TB4-EXEC-CAND-01` as **one new stable `RP-01 / AUTHORITY_DOMAIN_CONFLATION` recurrence**. A5 `collinearEdge` is generic exact source-edge support and permits same-sheet/no-certificate spans; A6 OrdinaryFront P2 incorrectly treats every such span as an isolation seam and requires `isolationCertificateBySeam[(region,edge)]`. R2 P2 separates these domains.

Stable accounting is now **55 events / 16 categories / 39 recurrences**, debt **1**, M6-owned. Candidate `10871935178 / 20f60bb1412424a6f1093fc8076884d1ea23f1c5` remains unpromoted. Accepted runtime authority remains M5 package/source `10814505512 / e284fea7c101eb86650d1c87c92d0fefa66050e7` under selector449 **449/449**.

`M6-CP1-CB5` changes only A6 reciprocal `OrdinaryFront` near-endpoint classification: matching source-edge-collinear spans with **no exact isolation certificate** use the non-seam same-sheet + both-wedges rule; certificate-backed spans retain the existing exact seam face/sheet/reciprocal-transition rule. No A5/schema/support/test/fixture/selector/HardRail/Periodic change is authorized. Stop if existing certificate authority cannot make this distinction without a definition/product change.

Compile-green TB5 reruns the same **7 focused + selector449 = 456** processes. Recovery-green is 7/7 + 449/449 with all 21 new TB4 losses and carried pair-swap/444/446/448 recovered, row140/rows5/7 still PASS, no `OccurrenceInvalidCornerAuthority`, exact-one/zero-skip and immutable postflight. Any RED is Review-owned.

Historical TB4 adjudication and consumed CB5 plan are folded into `M6_Consolidated_Record.md` §§19-20 and its folded-document index.

### `M6-CP1-TB4-EXEC` COMPLETE; exact next `M6-CP1-TB4-REV` (2026-09-25)

**Do not rerun TB4 or start corrective implementation. Start mandatory runtime-free `M6-CP1-TB4-REV`.**

TB4 consumed CB4 candidate artifact/source `10871935178 / 20f60bb1412424a6f1093fc8076884d1ea23f1c5` immutably and executed the entire frozen gate in run/job `36157505252 / 108145613689`: **7 focused + selector449 = 456 fresh exact-filter processes**, exact-one selection, zero skips/selection mismatches, no watchdog, benchmark 0, and exact immutable postflight. Result/log artifacts are `10874311495 / 10873574681`.

- focused: **6/7 PASS**; only retained pair-swap row6 is RED at `MissingIsolationSeamEquivalenceAuthority`; multi-isolation row5 and the new seventh seam-endpoint/wedge-lineage identity PASS;
- selector449: **425/449 PASS / 24 RED**; RED ordinals `115,116,122,130,132,134,137,141,143,150,176,201,217,218,231,232,238,246,436,437,438,444,446,448`;
- relative to TB3, focused row5 and selector 186/214/239 recover, while row6 + 444/446/448 remain RED and **21 accepted selector identities newly turn RED**;
- result SHA-256 `32dca965d68d060c32e1e8f79ac146cf6381eb6cf5762c0854c5d792ae693e24`, evidence manifest **932/932**; log SHA-256 `9d50f4e6adb6e17a20bc13071107b41ea8113b55854a7b8dd1f2cafe8d9b4757`;
- EXEC records non-stable `M6-CP1-TB4-EXEC-CAND-01` and makes **no stable repricing**. Stable accounting remains **54 / 16 / 38**, debt **1**. Candidate remains unpromoted; accepted runtime authority remains M5 package/source `10814505512 / e284fea7c101eb86650d1c87c92d0fefa66050e7` under selector449 449/449.

Historical TB4 execution/review requirements and result authority are folded into `M6_Consolidated_Record.md` §§18-20 and its folded-document index.

### `M6-CP1-CB4` COMPLETE; exact next `M6-CP1-TB4-EXEC` (2026-09-25)

**Do not resume CB4. Start immutable artifact-only `M6-CP1-TB4-EXEC`, then mandatory `M6-CP1-TB4-REV`.**

CB4 implemented the accepted R2 + RA-1 – RA-11 seam-incident occurrence/lineage authority at exact semantic source `20f60bb1412424a6f1093fc8076884d1ea23f1c5`. The candidate is compile/package green and **unpromoted**. No generated Directional runtime executed.

- patch apply run/job `36150018237 / 108120755401`; exact patch SHA-256 `1be2b2b3785d46bdde23cd3d24af4346a649591a430595960e44a557b279235b`; applied source `20f60bb1...`;
- compile run/job `36150253128 / 108121497728`; result artifact `10871935178`, SHA-256 `dc6e979ac62b4599c2c8b15528524513f3bc5b45eb9068ed508fd3d08ccf7998`; log artifact `10871960013`, SHA-256 `bbdfe584c0aefa433f614f699c28686ab83c9bc8194b3f868c1db96589c2eabf`;
- all eight standard targets compiled/linked with GMP/GMPXX; root manifest 28/28; source clean; `runtimeExecution=false`;
- selector449 remains 449 LF rows at `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`; routing449 remains `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707`;
- strengthened focused identity `M6CP1.SeamEndpointOccurrencesPublishCompleteCornerWedgeSheetAuthority` compiles; no runtime result is claimed.

TB4 is frozen at **7 focused + selector449 = 456 fresh exact-filter processes**. Use artifact `10871935178` immutably; do not rebuild or repair it. The Test + Benchmark turn must obey the artifact-only extraction/mode rules and update `Regression_Root_Cause_Tracker.md` for every observed regression before closeout.

Stable accounting remains **54 / 16 / 38**, debt **1**. Accepted runtime authority remains M5 package/source `10814505512 / e284fea7c101eb86650d1c87c92d0fefa66050e7` under selector449 **449/449**. CB4 grants no runtime credit or promotion.

Full evidence: `M6_Consolidated_Record.md §17 (folded CB4 compile authority)`.

### `M6-CP1-CB4` UNBLOCKED by RA-11: resume the same turn (2026-09-25T09:41:20Z)

**Resume `M6-CP1-CB4`.** This is the same turn: keep `Started at 2026-09-25T06:19:30Z` and set a new `Resumed at`. It is not a new turn, and no Definition turn is pending.

The per-face branch blocker is **resolved by review-agent amendment RA-11**. The blocker's facts are upheld. Its two proposed directions (an A4 product change, or deriving the branch) are unnecessary, because **nothing consumes a per-face branch**. The only A5-A7 reader of an occurrence branch is the transitional class key. Relation transport checks use A4 edge/endpoint lattice states.

RA-11 in brief:
- `CornerWedgeFaceBinding` = `(face, sheet, chart)`, with no branch.
- Each occurrence publishes `CornerPlacementProvenance`: the A4 corner `LocalLatticeState` verbatim, labelled with its A4 selected corner face. This is placement provenance only; the periodic builder leaves its branch at `0`.
- Class key = binding signatures + coordinate + scale + labelled placement provenance.
- Representative key has no branch.
- Stop rule: if CB4 finds another consumer that needs a wedge-face branch, stop and return to Review.

Normative text is at the end of `Architecture_M6_Frozen_Definitions.md`. Evidence is in `M6_Consolidated_Record.md §16 (folded RA-11 blocker authority)`, "Review-agent adjudication". No A4 or test change, and TB4 stays 7 + 449 = 456. Accounting 54/16/38, debt 1.

### `M6-CP1-CB4` BLOCKED on per-face branch authority (2026-09-25) — RESOLVED by RA-11

**Do not continue CB4 implementation or start TB4. No production/test patch or compile candidate was created.**

Static derivation against exact source snapshot run/artifact `36104814370 / 10850013454` proved that accepted D6/R2 requires every `CornerWedgeFaceBinding` to carry the exact `branchRotation` for that source face, but immutable A4 `SurfacePhaseFrontProduct` does not publish a per-face branch table or field-transport authority from which A5 can derive that value for an intermediate corner-wedge face. `SourceChartTransitionGraph` carries chart/simplex connectivity rather than field branch transport, and isolation-seam certificates cover only seam edges, not ordinary same-sheet fan edges. Any CB4 implementation would therefore have to invent a representative value, consume raw field authority outside the frozen A5 input boundary, or change the A4 product. All are outside the authorized plan.

- Blocker record: `.agents/Directional/M6_Consolidated_Record.md §16 (folded RA-11 blocker authority)`.
- Exact snapshot: source/event SHA `a304bd0b36011f2c100b8a6c127d8ba3c11810cf`; provider digest `ff39ad5104fbfadbb245c4e406428588b5c8142d4b84d723c876c2b7704ebb12`; embedded archive SHA-256 `bb5d91e6aca68fd491ad9c643d406e8273a520a96b1f5a814ac8b896baac8d2e`; 5314/5314 manifest rows verified; `runtimeExecution=false`.
- Stable accounting, debt, accepted M5 package/source, selector449 and routing449 are unchanged. This is a static definition/authority gap, not a runtime event.
- Required resolution: a bounded Definition amendment must either preserve A4-computed per-face branch authority in an authorized A4 product field, or redefine the binding branch value so it is derivable from existing A4 products with proofs for uniform, periodic-chart and bounded-disk producers.
- **No authorized successor turn ID is frozen yet.** Repository `STATUS` is BLOCKED with successor `UNKNOWN`; do not invent a Definition turn identifier.

### Recovery reconciliation — CB4 not started (2026-09-25T06:15:13Z)

**Start `M6-CP1-CB4` as a new runtime-free Code + Build turn. Nothing is held; no definition or review turn is pending.**

- **Why this note exists.** An implementation session started at 05:40:26Z. At that moment the review turn was still `IN_PROGRESS`; its COMPLETE beacon landed at 05:42:01Z. The session produced no work, and the loop recorded it as `CHAT_UNKNOWN`.
- **Verified by the review agent at recovery:**
  - no `M6-CP1-CB4` commit exists on any origin ref (head at recovery: `65acce1f`);
  - no GitHub Actions run exists after `36097522915` (05:11:33Z, DEFN-R2 cleanup);
  - no `M6-CP1-CB4` Drive staging or work-preservation patch exists.
- **So CB4 is a fresh turn, not a resume.** The entry beacon is `Turn: M6-CP1-CB4 / IN_PROGRESS / Successor: UNKNOWN`, with a new `Started at`, empty `Resumed at` and empty `Ended at`.
- **Authority chain, all accepted:**
  - DEFN-R1 core;
  - DEFN-R2 amendments;
  - `M6-DEFN-R2-REV` review amendments RA-1 – RA-10, normative at the end of `Architecture_M6_Frozen_Definitions.md`, rationale in `Architecture_M6_DEFN_R2_Review_Record.md` §3.

  The CB4 plan's status is **AUTHORIZED**. Its RA block overrides any older "HELD" wording in that file.
- **Unchanged:** stable accounting **54 / 16 / 38**, debt 1; accepted runtime authority `10814505512 / e284fea7...` under selector449 449/449; candidate `10840014758 / 660015f2...` unpromoted.

### `M6-DEFN-R2` COMPLETE (2026-09-25)

*(Historical; `M6-DEFN-R2-REV` is complete and has authorized CB4.)*

`M6-DEFN-R2` resolved all four DEFN-R1 Review blockers and P1-P4 without touching source/test/selector bytes:

- B1: evidence-only `CornerWedgeIsolation` lineage equivalence with ordered exact `(region,seam,fromSheet,toSheet)` transitions; split-square v0/center/v2 can be `{0,1}` with non-empty lineage evidence without inventing quotient relations.
- B2: complete per-occurrence binding signatures; relation-local HardRail/Periodic selected-path charts/components; A7 lineage charts are union-of-all bindings; component remap preserves exact binding/transition tuples before legacy projections.
- B3: source-edge collinearity is exact `SourceSupport`; cell-interior incident face is selected topologically from accepted canonical cell orientation plus source winding. The orientation premise was re-proved for uniform, periodic-chart and bounded-disk builders.
- B4: A5 relation failures are one-to-one and mapped by the adapter to frozen M5 names; only duplicate structural owner/kind predicates may move earlier, while semantic route/transport/value/support checks stay live.
- P1-P4: ordered maximal support spans, reciprocal near-endpoint agreement, fail-closed singular/SingularityPort exclusions, and hard-rail/region wedge limits are frozen.

Frozen-test audit: focused rows 5/6, selector rows 186/214/239/444/446/448, and HardRail single-sheet assertions remain statically satisfiable. Seventh focused identity is strengthened to materialize/assert v0/center/v2 lineage. TB4 remains 7+449=456 if Review accepts and CB4 later compiles.

Exact source snapshot: run/artifact `36095854118 / 10847467936`, SHA `342a306ebd3ba68cb6e1135cf9e25726bd8ad461`, provider SHA-256 `a19261e06e11293b9240b8a44c24f95042190df1d7154ba330c5e677fb9875c2`, embedded archive SHA-256 `c0ca5581851b76b1a169cdffb4c3b7243070d54225f176e6510ce909b152ab1c`, `runtimeExecution=false`.

Stable accounting remains **54 / 16 / 38**, debt 1, +0. Accepted M5 authority remains package/source `10814505512 / e284fea7...` under selector449 449/449. `M6-DEFN-OBS-01` recurred as the already-known pre-READ_MODE process miss; decisive conclusions were re-derived from the verified snapshot and no new lesson/event is created.

### `M6-DEFN-R1-REV` COMPLETE (2026-09-25)

**Exact next turn: `M6-DEFN-R2` (runtime-free Definition amendment). CB4 stays HELD.**

The review agent upheld the DEFN-R1 core model: corner-wedge sheet sets, wedge/side certificate carriers keyed by `(region, seam edge)`, owner-less `OrdinaryFront`, A6 membership validation, the A7 union, and no mixed-face records. The split-square table re-derives exactly. The definition is **not accepted as frozen** because of four blocking findings (`Architecture_M6_DEFN_R1_Review_Record.md`):

- **B1 (decisive).** Frozen focused row5 (`SurfaceCellTransitionQuotientTests.cpp:2639`) requires non-empty `lineage.equivalences` for every multi-sheet lineage, but equivalences come only from relation unions (`RemeshPipeline.cpp:4384-4393`). Under D5, v0 and v2 are relation-free singleton classes with `{0,1}` and no equivalences, so TB4 is RED by construction. Represent wedge evidence in `equivalences`, and have the seventh identity assert lineage.
- **B2.** D6 does not specify which binding each face-dependent consumer uses: the transitional class key and `QuotientClassId` ordinal, `representative_key`, selected relation path charts and components (torus rows 444/448), and lineage `sourceCharts`.
- **B3.** Wedge endpoints still come from tie-broken segment faces. There are three side builders, and the split square uses `segment_on_source`, which breaks ties by source-face row. One exact collinearity/interior-face rule is needed, with the orientation premise proved per builder.
- **B4.** D7 contradicts frozen §4.6. A5's many-to-one `UnownedRelation` lets specific M5 codes become generic; split the A5 codes 1:1 and map them at the adapter.

Accounting stays **54 / 16 / 38**, debt 1. Accepted runtime authority is unchanged.

### `M6-DEFN-R1` COMPLETE (2026-09-25)

*(Historical; its successor `M6-DEFN-R1-REV` is now complete.)*

`M6-DEFN-R1` froze complete corner-wedge sheet authority, wedge/side seam-certificate carriers, exact seam-collinear side semantics, per-wedge face/chart/branch provenance, A6 owner-less OrdinaryFront checks, A7 lineage union semantics, row140 adapter ownership, and the CB4/TB4 re-scope. The new focused identity is `M6CP1.SeamEndpointOccurrencesPublishCompleteCornerWedgeSheetAuthority`; TB4, if later authorized, is 7 focused + selector449 = 456.

Accepted runtime authority remains `10814505512 / e284fea7c101eb86650d1c87c92d0fefa66050e7` with selector449 449/449 PASS. Stable accounting remains **54 / 16 / 38**, debt 1. Candidate `10840014758 / 660015f2...` remains unpromoted. Selector449/routing449 are unchanged.

Review must independently re-open source/evidence and re-derive: split-square v0/center/v2 wedge/certificate orientations; all eight endpoint pair memberships; interior seam vertex crossing one/two seam edges; exact seam-collinear incident-cell side authority; per-wedge provenance; row140 adapter-only compatibility; selector/routing hashes and seven-test pre-registration. If any of those semantics is ambiguous, amend Definition rather than implementing.

# Directional Future Chat Session Handoff

## DURABLE — live resume authority

## Current authority

`M6-DEFN-R4-REV` is **COMPLETE**. R4 is **accepted with binding amendments RA-18 – RA-21**. Record: `Architecture_M6_DEFN_R4_Review_Record.md`; normative text at the end of `Architecture_M6_Frozen_Definitions.md`.
- Reviewed runtime authority: `11265967968 / 8e0818b1e2f8d12b86c64d8774a3572c5ed5266c`.
- Required gate: `Architecture_M6_CP1_Required_Green_Focused_12.txt` + selector449 = **461/461**.
- Stable accounting **60 / 16 / 44**, debt **1**.

CP1 stays **OPEN** until CB9/TB9 (A7), CB10/TB10 (thin adapter / A5 validation) and CB11/TB11 (`G4-B002` A6 boundary) are each Review-accepted, followed by `M6-CP1-CLOSE-REV`. `M6-DEFN-R5` is a CP3-entry gate.

## Exact next turn

**`M6-CP1-CB9-A7` — Code + Build, compile/package only.** Follow `Architecture_M6_CP1_CB9_A7_Code_Build_Plan.md`; its RA-18 block governs.

Implement the A7 `SourceAttachedGeometryProduct` and producer (R4 D1). The support certificate has two parts:
- typed exact common support, from A5 `occurrence.support`;
- RA-18's reject-only same-simplex point guard.

Also:
- remove the adapter's `1e-9` check in the same CB;
- move the D2 category-(c)/(d) checks into A7 or serialization;
- add focused 13-20 (15 renamed per RA-18; 20 runs the real `validate_materialized_completion_domain_ownership`);
- create the focused-20 file with focused-12 as its exact prefix.

Compile-green → `M6-CP1-TB9-A7-EXEC` (**20+449 = 469**) → mandatory `M6-CP1-TB9-A7-REV`.

## Completed predecessor turns (reference only)

- `M6-DEFN-R4-REV` — current Review authority.
- `M6-DEFN-R4` — Definition record and D4 census, accepted with amendments.
- `M6-CP1-TB8-A6-REV`, with its addendum — runtime promotion, RA-17.

## Current files

- `.agents/Directional/Architecture_M6_CP1_CB9_A7_Code_Build_Plan.md` — exact next plan; the RA-18 block governs.
- `.agents/Directional/Architecture_M6_DEFN_R4_A7_Boundary_Definition_Record.md` and `Architecture_M6_DEFN_R4_Review_Record.md` — definition plus review.
- `.agents/Directional/Architecture_M6_Frozen_Definitions.md` — normative; §5, R4 amendment, RA-16 – RA-21.
- `.agents/Directional/Architecture_M6_DEFN_R4_D4_Consumer_Census.md` — reader census.
- `.agents/Directional/Architecture_M6_CP1_CB10_A5_Validation_Code_Build_Plan.md` and `Architecture_M6_CP1_CB11_G4_B002_Boundary_Code_Build_Plan.md` — held, amended.
- `.agents/Directional/Architecture_M6_CP1_Required_Green_Focused_12.txt` and selector449 / routing449 — frozen gate.

## Context Load Plan

```yaml
load_next:
  - turn-based-coding-agent/references/turns/CB.md
  - .agents/Directional/Architecture_M6_CP1_CB9_A7_Code_Build_Plan.md
  - .agents/Directional/Architecture_M6_DEFN_R4_A7_Boundary_Definition_Record.md
  - .agents/Directional/Architecture_M6_DEFN_R4_Review_Record.md
  - .agents/Directional/Architecture_M6_Frozen_Definitions.md
  - .agents/Directional/Architecture_M6_CP1_Required_Green_Focused_12.txt
conditional_modules:
  - trigger: github_connector / GitHub Actions / compile
    path: turn-based-coding-agent/modules/github-connector/MODULE.md
deep_references:
  - .agents/Directional/Architecture_M6_DEFN_R4_D4_Consumer_Census.md
  - src/pipeline/RemeshPipeline.cpp (adapter 5548-6503; A5 3284+; A6 producer)
  - include/directional/geometry/SurfacePointSupport.h (resolver tolerance)
  - src/geometry/PureQuadCompletion.cpp (completion ownership 850-1240)
  - .agents/Directional/GitHub_Workflow_Policy.md
  - .agents/Directional/TOOL_USE_CONSERVATION_POLICY.md
do_not_preload:
  - folded superseded M6 per-turn records
  - research/provenance/examples
```
