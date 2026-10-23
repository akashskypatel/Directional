## TB29 — 44-case typed factory cause harvest (2026-10-23)

**Candidate/non-stable diagnostic census; no established new product regression.** Artifact-only [run 39906802267](https://github.com/akashskypatel/Directional/actions/runs/39906802267), result `12481556884` (ZIP SHA-256 `4e639a633a64df419f1891083911506679c6c4848f1ecbce7b206c4f5d653ae1`), immutable CB28A package `12465330920` / source `4473e41e94a35f1bf189fa046e86bac92c7391fb`. **44/44** separately executed, **9 PASS / 35 RED**, zero invalid/missing/duplicate/skipped, zero bad controls/unexpected PASS, postflight true; 92/92 packaged hash checks plus 44/44 raw-log SHA and manifest identity match. No runtime rebuild, relink, configure, benchmark, or source/test/selector modification. All 35 are inherited TB28 RED identities (not new failures). Observed first-failure groups: checked phase-front factory **13** (certificate-pair-binding 6, face-gauge-missing 6, open-rail-chain 1), A3 atlas **8** (`CycleTransportMismatch` 7, `SingularityMismatch` 1), A5 **1** (`OccurrenceHardRailTransportMismatch`), and **13 insufficiently typed** (`reason-not-observed` with exact first failure retained). This grouping is diagnostic, not root-cause proof; unresolved 13 and factory `code=0` remain Review-owned. **No count change**: stable **66/17/49**, debt **1**, accepted CP2 **491/491**, rejected R3 **403/497**, TB28 **462/497 candidate only**, RP-01 open / RP-02 UNREACHED / Gate C suspended. Owner: mandatory TB29-REV for typed-failure attribution and DEFN-M1 scoping. Falsifier: an identity/hash mismatch, control invalidity, or a reviewed causal finding inconsistent with raw first failures. Full evidence: `Architecture_M6_CP3_TB29_Typed_Factory_Cause_Harvest_Report_20261023.md` and artifact `12481556884`.

## RA-140 — audit of the RP02 harness review (2026-10-23)

Harness acceptance upheld and validated on real GoogleTest logs (TB28 35/35 RED, TB27 21/21 PASS). TB29 is released with complete inputs and must run before 2026-10-29T22:54:39Z. No count changes. Record: `Architecture_M6_CP3_TB29H_RP02_Review_Audit_Decision_20261023.md`.

## TB29H RP02-REV — targeted harness static review accepted (2026-10-23)

Independent static review discharged RA-138-H1–H3 and RA-139-H4–H6 for TB29-specific harness use: exact SHA `436f5fff9c3b`, 12/12 built-in synthetic cases, 44-case manifest and four independent invalid manifests. **Not a product regression or runtime promotion.** RA-139.5 remains open: the separate 497-case census harness still treats abnormal termination as semantic RED and must be replaced or independently corrected before the next full census. Owner: the Review that schedules that census. Falsifier: any crash, timeout, missing terminal result or multi-run accepted as a completed RED. Forbidden: performing the next census on unreviewed unsafe classifier or treating TB29 focused cases as CP3 acceptance. Stable 66/17/49, debt 1, CP2 491/491, TB28 462/497 candidate unchanged. See `Architecture_M6_CP3_TB29H_RP02_Harness_Correction_Review_Decision_20261023.md`.

## RA-139 — audit of the TB29H review (2026-10-23)

RA-138's H1–H3 upheld. Added three harness defects:
- H4: on timeout the test process survives and can append to its hashed log;
- H5: timing output is merged into the test log;
- H6: reasons are read from the whole log rather than the failure block.

A built-in `--self-test` and a count gate are now required. The census harness shares H1 (carried to the next census). No count changes. Record: `Architecture_M6_CP3_TB29H_Review_Audit_Decision_20261023.md`.

## RA-138 — TB29H harness runtime authorization rejected (2026-10-23)

**Candidate/non-stable control-plane evidence defect, not a product regression.** RA-138-H1: timeout/crash with one `[ RUN ]` is misclassified `RED`, which can produce successful harness exit for a RED-kind case without a terminal GoogleTest result. RA-138-H2: one-row self-check passes despite RA-137 required count check. RA-138-H3: A5 hyphenated reasons are truncated. Owner: `M6-CP3-TB29H-RP02-TARGETED-ARTIFACT-HARNESS-CORRECTION`, independent RP02-REV. Falsifiers: timeout/crash/truncated RED => INVALID + nonzero; declared case count enforced for 44 and future manifests; full A5 code/site preserved. **Forbidden:** TB29 execution or attribution of typed causes from this unaccepted harness, changing frozen manifest/selector or product tests. Accepted 66/17/49, debt 1, CP2 491/491, TB28 462/497 candidate unchanged. Review: `Architecture_M6_CP3_TB29H_Targeted_Harness_Review_Decision_20261023.md`.

## RA-137 — TB29 block resolved (2026-10-23)

TB29 stopped before any execution because no authorized 44-identity harness existed. Review now owns the case manifest (`Architecture_M6_CP3_TB29_Targeted_Case_Manifest.tsv`, 44 rows); TB29H builds one reusable input-driven harness, then TB29 resumes on the CB28A package. Guard trio corrected to RA-130.9's. No count changes. Record: `Architecture_M6_CP3_TB29_Harness_Authorization_Design_Review_Decision_20261023.md`.

## RA-136 — CB28 reviewed (2026-10-22)

CB28 diagnostics are message-only and accepted. 18 of the 21 silent REDs now report a typed reason. `focused30:12` and `focused30:22/23` (the M1 precedence tests) are still silent; CB28A adds those messages before TB29. TB29 will measure all 35 REDs. No count changes. Record: `Architecture_M6_CP3_CB28_Factory_Error_Diagnostics_Review_Decision_20261022.md`.

## CB27A-REV — independent static non-vacuity accepted (2026-10-22)

The prior outside-wedge oracle was masked by same-side classification. RA-135's repaired test removes authentic `3/1` from D7's two-binding second wedge while leaving `2/1`, sheet set, certificate transition and both endpoint placements intact; P1–P6 independently isolate A7 wedge membership. CB27A-REV accepts this as a **static negative oracle**, not a runtime PASS or CP3 promotion. Counterfactual removal of only the membership guard admits the tamper. The next owner is `M6-CP3-CB28-RP01-FACTORY-ERROR-DIAGNOSTICS` (RA-134.5 test-only factory diagnostic reasons), followed by independent CB28-REV/TB29. Falsifier: any earlier rejection with the membership guard removed or violation of the P1–P6 guards; stop rather than adapting expectations. Selector 497 frozen; stable 66/17/49, debt 1; TB28 462/497 candidate; RP-01 open, RP-02 UNREACHED. Detail: `Architecture_M6_CP3_CB27A_Wedge_Membership_Oracle_Review_Decision_20261022.md`.

## RA-135 — CB27A design block resolved (2026-10-22)

CB27A could not isolate wedge membership on the first endpoint: D7's first wedge has a single binding. Membership is checked for both endpoints, so the resumed CB27A withdraws the second span's real binding `3/1` from the two-binding second wedge, with preconditions P1–P6. No count changes. Record: `Architecture_M6_CP3_CB27A_Wedge_Membership_Witness_Design_Review_Decision_20261022.md`.

## CB27-REV — test-authority non-vacuity defect (2026-10-22)

Independent static review of CB27 source `175c70e44d2c162d72812c842149f30c53c1fa25` and GMP compile package `12443015113` (28/28 hashes) found the outside-wedge A7 negative non-discriminating: copying the second span's entire interior binding into the first gives both endpoints the same certificate side, so the independent side-opposition guard rejects even with the wedge-membership predicate removed. This is **not** an accepted-green loss or stable product regression. Falsifier for corrected oracle: removing only membership must admit the otherwise valid source-produced mutation; a rejection due to opposite-side mismatch or earlier A5/A6 guard does not count. Owner: `M6-CP3-CB27A-RP01-A7-WEDGE-MEMBERSHIP-ORACLE-CORRECTION` and mandatory CB27A-REV before CB28/TB29. Prohibited: synthetic success, tamper that changes multiple independent predicates, test assertion weakening, product changes in test-only CB. Three other negatives await runtime. Stable counts **66/17/49**, debt **1**, CP2 **491/491**, TB28 **462/497 candidate only**; RP-01 open. Record: `Architecture_M6_CP3_CB27_A7_Certified_Seam_Negative_Oracles_Review_Decision_20261022.md`.

## RA-134 audit of the TB28 review (2026-10-22)

TB28 re-derived: 462/497, 13 RED→PASS, 0 PASS→RED. RA-133's RED partition is corrected to group by first failing component:
- checked phase-front factory: 17 (13 silent, 4 wrong code);
- A3 atlas: 8;
- A5: 1;
- producer disposition or oracle: 7;
- witness absence: 2.

21 REDs have no typed reason. CB28 (test-only messages) and TB29 run before DEFN-M1. No count changes. Record: `Architecture_M6_CP3_TB28_Census_Review_Audit_Decision_20261022.md`.

## RA-133 — independent TB28 census Review (2026-10-22)

Independently verified [run 39772864202](https://github.com/akashskypatel/Directional/actions/runs/39772864202), result `12424484672`: 1019/1019 checksums, 497 one-RUN records with matching log SHA, 462 PASS/35 RED, 13 RED→PASS, zero PASS→RED vs TB21. All 35 RED identities are inherited and partitioned in `Architecture_M6_CP3_TB28_Selector_497_Census_Review_Decision_20261022.md`: M1 10, neighboring hard-rail/A5 2, D2 1, periodic product/fixture 13, typed hard-feature front 1, other independent producer/test oracles 8. **Candidate/non-stable only**, no accepted-green regression or new event; no established single cause for the remaining 35. Falsifiers: future individually reproducible accepted-green loss, proved product origin for a failure currently attributed to missing fixture, or a new distinct RED identity. Owners: CB27 A7 negative tests under RA-132.6; DEFN-M1, DEFN-T1 and fixture-debt review afterward. Prohibited: force green, change selector/test oracle to erase RED, infer causal equivalence from shared RED status. Stable **66/17/49**, debt **1**, CP2 **491/491**, R3 **403/497** rejected; TB28 candidate **462/497**, RP-01 OPEN, RP-02 UNREACHED.

## TB28 — full frozen selector-497 census, candidate/non-stable (2026-10-22)

Artifact-only [run 39772864202](https://github.com/akashskypatel/Directional/actions/runs/39772864202), result `12424484672` (ZIP SHA-256 `a54110dbb5475b76e6b6a6baa8fc1b7dcabd7aa50c95c5b390532509d1c656e6`), exact CB26 source `e3d60337ed34538547d3a6d519bafae5b184330e` and immutable package `12409939859`: **462/497 PASS, 35/497 RED**, every case separately executed once, 1019/1019 checksums, identical pre/post package/source/execution-view and no build, relink, benchmark, fixture, test or selector mutation. Against TB21 **449/497**, **13 RED→PASS** (focused30 6,20,24–28; selector 444,446,447,448; cp3entry 3,5), **0 PASS→RED**. All 12 known seam-family rows pass; no surviving RED emits `UncertifiedCrossSheetBinding`, `cross-sheet:seam-direction` or `cross-sheet:periodic`. The **35 remaining REDs are inherited** from TB21; each has precise first failure, test identity, binary, exit, raw log hash and TB18/TB21 baseline in `Architecture_M6_CP3_TB28_Selector_497_Red_Inventory.tsv`; the full 497 rows are retained in `Architecture_M6_CP3_TB28_Selector_497_Full_Ledger.tsv`. **Root-cause classification:** candidate/non-stable improvement consistent with certified seam A5/A7 repair; there is **no observed new regression**, and individual inherited RED causes remain unadjudicated for TB28-REV (M1, D2 and fixture debt), not presumed fixed or newly introduced. No change to accepted **66/17/49**, debt **1**, CP2 **491/491**, rejected R3 **403/497**; RP-01 open, RP-02 UNREACHED, Gate C suspended. The untested three A7 sites, B4 precision and RA-127.4b remain for review-authorized CB27. Evidence: `Architecture_M6_CP3_TB28_Selector_497_Census_Report_20261022.md`. Independent Review `M6-CP3-TB28-RP01-SELECTOR-497-CENSUS-REV` is next.

## TB27 Review (RA-132, 2026-10-22)

TB27 verified 21/21: the 12 seam-family rows, the D3 gauge tamper, the D7 evidence tamper, and all guards and controls PASS. These are targeted, candidate results. Three new A7 rejection paths and the B4 precision case are untested (CB27). The selector-497 census (TB28) runs next, on the unchanged CB26 package. No count changes. Record: `Architecture_M6_CP3_TB27_A7_Certified_Seam_Cross_Sheet_Verification_Review_Decision_20261022.md`.

## TB27 — A7 certified-seam verification, targeted candidate (2026-10-22)

Corrected immutable artifact-only [run 39764327506](https://github.com/akashskypatel/Directional/actions/runs/39764327506), result **12420676412** (ZIP SHA-256 `33dc0878cd4dd0592b1ad2ae0b436b2606c7a59e45cbc0e929358d6213f7babb`), original CB26 semantic source `e3d60337ed34538547d3a6d519bafae5b184330e` / GMP package **12409939859**: **21/21 executed/PASS**, zero RED/skip/missing; 24/24 result manifest, 21 single-RUN/single-OK logs, immutable postflight, no compile/relink/benchmark/selector change. All 10 A5 cases, D3 `cp3entry:3`, D7 `cp3entry:5`, six former controls and three new A7 guards PASS. No `cross-sheet:seam-direction`, `cross-sheet:periodic`, site/guard falsifier. Initial [run 39761406833](https://github.com/akashskypatel/Directional/actions/runs/39761406833) independently produced 21 PASS but violated archive executable-mode handling (extract+chmod); it is diagnostic, not procedural acceptance. Corrected harness preserves modes via `unzip`, with no test/package semantic change.

**Root-cause classification:** prior TB26 nine target RED rows stopped at A7's incorrect OrdinaryFront cross-sheet rule, ignoring the certified A5/A6 seam evidence (RA-129); CB26 implements RA-130.8's certificate-bound A7 transition and is now verified by this targeted matrix. No claim of full selector-497, Periodic, nonzero-turn seam or RP-01 acceptance; independent TB27 Review must adjudicate before promotion. Candidate/non-stable **resolved-on-targeted-scope only**; no new stable event or historical-count mutation. **66 events / 17 categories / 49 recurrences**, produced-witness debt **1**, CP2 accepted **491/491**, rejected R3 **403/497**, TB21 candidate **449/497**, selector **497** frozen; RP-01 OPEN, RP-02 UNREACHED, Gate C suspended. Owning report: `Architecture_M6_CP3_TB27_A7_Certified_Seam_Cross_Sheet_Verification_Report_20261022.md`.

## DEFN-SEAM-A7 Review (RA-130, 2026-10-22)

> 2026-10-22 RA-131: CB26 was independently accepted as compile-only; no TB27 run or regression promotion yet. Certified-seam A7 D3/D7 positive/tamper, Periodic B6 and three A7 guard obligations transfer unchanged to `M6-CP3-TB27-RP01-A7-CERTIFIED-SEAM-CROSS-SHEET-VERIFICATION`. See `Architecture_M6_CP3_CB26_A7_Certified_Seam_Cross_Sheet_Authority_Review_Decision_20261022.md`.

Contract accepted with amendments B1–B6:
- the frozen D7 test `cp3entry:5` already pins A7's acceptance and its `cross-sheet` evidence tamper;
- spans are bound to canonical endpoints, and the duplicate pair check is dropped;
- the evidence check must find the certificate's own transition;
- each cross-sheet rejection gets a distinct site;
- Periodic is recorded as latent.

No count changes. Record: `Architecture_M6_CP3_DEFN_SEAM_A7_Certified_Seam_Cross_Sheet_Authority_Review_Decision_20261022.md`.

## TB26 Review (RA-129, 2026-10-22)

TB26 verified. CB25 opened A5; A6 admits and selects the untampered certified seam relation (TB26's report wrongly said A6 was not reached). All nine RED rows now stop in A7, whose OrdinaryFront cross-sheet rule can never pass when the endpoints share no sheet. `focused30:26–28` PASS individually. D3 tamper still unmeasured. No count changes. Record: `Architecture_M6_CP3_TB26_Shared_Node_Seam_Witness_Harvest_Review_Decision_20261022.md`.

## TB26 — A5 shared-node seam witness harvest, candidate/non-stable (2026-10-22)

Artifact-only [run 39727886868](https://github.com/akashskypatel/Directional/actions/runs/39727886868), result **12403479548** (ZIP SHA-256 `3f7df8c2ecbd9587127c4621feb3965abe383df31deae57bd48cf0283080ac2d`), on immutable CB25 package **12399179446**, semantic source `c5e0b242f3c3015f1f4f5f886058f0086fe1f679`: **18/18 selected/executed, 9 PASS / 9 RED, zero skips**, 21/21 manifest hashes, immutable postflight and no compile/relink/benchmark. All six guard/controls PASS; 12 A5-ISO = 3 PASS (`focused30:26/27/28`) and 9 RED. Initial run 39726328838 selected 0/18 owing solely to missing executable mode in staged copies; it supplies no product evidence. Harness was corrected without altering packaged binaries or test source.

**First-failure census and causal uncertainty:** six A5-ISO cases (`focused30:6,20,25`, `selector:444,446,448`) reject `UncertifiedCrossSheetBinding`; `focused30:24` asserts absent A7 output but does not reveal a decisive upstream cause; `cp3entry:3/5` fail at every bounded size candidate (`0.25`, `0.5`, `1.0`) with `A7:rejected-certified-seam`, before constructing the required certified reciprocal OrdinaryFront relation. The untampered A6 decision, stripped/expected turn and `cp3entry:3` D3 quarter-turn tamper were **not reached**, so RA-128 §3's missing-certificate falsifier applies. No earlier `first-face`/`second-face` first-failure site recurred, but this does not prove coverage of the amended A5 predicate. Whether the producer failures and fixture construction gaps share a root cause with CB25 remains **unproven**; independent Review must determine the causal repair/fixture disposition. This is candidate/non-stable evidence, **not** a newly established stable event or accepted regression repair. Stable accounting **66 events / 17 categories / 49 recurrences**, produced-witness debt **1**, accepted CP2 **491/491**, rejected R3 **403/497**, TB21 candidate **449/497**, selector 497 frozen. RP-01 open; RP-02 unreached; Gate C suspended. Evidence owner: `Architecture_M6_CP3_TB26_Shared_Node_Seam_Witness_Harvest_Report_20261022.md`.

## CB25 Review (RA-128, 2026-10-22)

Single-file shared-node A5 corrective source and compile evidence accepted, no runtime yet. A3 obligation: TB26 must independently observe all 12 A5-ISO identities including certified reciprocal A6 and D3 tamper at `cp3entry:3/5`; falsifier is a recurring exempted face rejection, control regression, or a successful D3 tamper. A4 obligation: later CB26 must add focused negative tests for invalid wedge, same certified side and edge/face support with unequal lattice coordinate. No new stable or candidate evidence and no count change. Source review `Architecture_M6_CP3_CB25_A5_Shared_Node_Side_Authority_Review_Decision_20261022.md`.

## DEFN-SEAM Review (RA-127, 2026-10-22)

Contract accepted with amendments A1–A4. The shared-node predicate gains lattice-coordinate equality, the rejection-site classifier mirrors the rule, TB26 reports the A6 seam branch and D3 tamper for `cp3entry:3/5`, and negative tests follow in CB26. No count changes. Record: `Architecture_M6_CP3_DEFN_SEAM_A5_Shared_Node_Side_Authority_Review_Decision_20261022.md`.

## TB25 Review (RA-126, 2026-10-22)

TB25 verified: on every measured seam the turn is identity (torus curved, D3 grid uniform; d = F = 0). `cp3entry:3/5` join A5-ISO (12 rows); RA-124's adjacent-sheet filing corrected. No count changes. Record: `Architecture_M6_CP3_TB25_Seam_Frame_Values_Harvest_Review_Decision_20261022.md`.

## TB25 — seam frame and D3 witnesses, candidate/non-stable (2026-10-21)

Immutable artifact-only [run 39682528031](https://github.com/akashskypatel/Directional/actions/runs/39682528031), result `12384333036` (ZIP SHA-256 `f10ef7786ca2af1f9e2cfa8cc0dfdf0b889c03b2adb54c9f8a5e87de1be6ccbc`), exact CB24 semantic source `dae267a82fb884ff9eba4fd0122ad61750d0c924`: 11/11 individual tests, 6 PASS controls, 5 semantic RED (three A5 torus, two D3), 0 skips, 16/16 result digests and immutable postflight. No source, fixture, selector, compile, relink or benchmark mutation. **Candidate only; independent TB25 Review required.**

A5 torus's three sites are byte-identical (`seam=60,61`; `branch=3,3`, `gaugeSel=0,0`, `gaugeSpan=0,0`, `turn0=0,0`): curved signature, gauge jump `d=0` equals certificate forward turn `F=0`; the identity-certificate A5-side-authority branch applies, **not** a nonzero D3 transform or gauge-table mismatch. The original A5 face clauses reject. D3 `cp3entry:3/5` both fail at their earliest bounded reciprocal-front candidates and each records three `relation-collinear-seam` candidate sites (`seam=1,4`), all uniform identity (`branch=0,0`, gauges 0, `turn0=0,0`, `d=F=0`); candidate cause `OccurrenceMismatchedIsolationEvidence`. These join the observed seam-contract family, but fixture reclassification and normative changes remain for independent Review. No new stable regression ID or promotion: totals **66 events / 17 categories / 49 recurrences**, produced-witness debt **1**, CP2 **491/491** accepted; CP3 R3 **403/497** rejected, TB21 **449/497** candidate, selector 497 frozen. RP-01 open, RP-02 unreached, Gate C suspended. Full raw sites, bounded routing, logs and postflight: [Architecture_M6_CP3_TB25_Seam_Frame_Values_Harvest_Report_20261021.md](Architecture_M6_CP3_TB25_Seam_Frame_Values_Harvest_Report_20261021.md).

## TB24 — torus A5 seam-face fields, candidate/non-stable (2026-10-21)

Immutable artifact-only [run 39641426480](https://github.com/akashskypatel/Directional/actions/runs/39641426480), result `12364838156` (ZIP SHA-256 `dcf42df92170fa82d1adca54b5fc480ad7f22c6ae45f1835ebde3d9c037220d3`), CB23 package `12355892070`, semantic source `e859175333`: 9/9 selected/executed, 3 A5 RED / 6 PASS, no skips, immutable postflight; no compile or relink. `focused30:20`, `selector:444` and `focused30:28` emit one byte-identical site: the TB23 prefix plus `;sel=121/0,121/0;support=vertex,vertex;wedge=120/0+121/0,97/2;spanOnly0=forward`. Guard `selector:447` and five controls PASS with no site. No count changes. Report: `Architecture_M6_CP3_TB24_Torus_A5_Seam_Face_Harvest_Report_20261021.md`.

**Review (RA-123, 2026-10-21):** harvest verified; P1/P2 held. Both occurrences are one vertex-61 node carrying one per-node representative `121/0`, inside (0,1)'s wedge and outside (1,0)'s (`97/2`, other sheet): neither B-across nor B-fan. The A5-ISO row below is updated. Record: `Architecture_M6_CP3_TB24_Torus_A5_Seam_Face_Harvest_Review_Decision_20261021.md`.

**Review (RA-124, 2026-10-21, static):** an OrdinaryFront relation's two occurrences share one producer node, so the A5 certified-seam face clauses cannot hold, and A6's gauge-stripped turn is identity by construction (uniform/curved; annulus never writes `branchRotation`). Frozen D3 (RA-30a.3) is satisfiable only for an identity turn. `cp3entry:3/5` (filed as adjacent-sheet fixture debt) are contested. No count changes. Record: `Architecture_M6_CP3_DEFN_ISO_A_Seam_Node_Representative_Census_Review_Decision_20261021.md`.

## TB23 — torus A5 isolation site, candidate/non-stable (2026-10-21)

Immutable artifact-only [run 39609365590](https://github.com/akashskypatel/Directional/actions/runs/39609365590), result `12348649684` (ZIP SHA-256 `5ce737452a23637e74f0241f5f8a9a0ebe34b874b83ad1ff2d0d6f4456ee34d6`), CB22B package `12341307713`, semantic source `c6e90916e`: 16/16 selected/executed, 6 PASS / 10 RED, no skips, 20/20 result hashes, unchanged package/source/view after execution; no compile or relink. All nine A5-ISO rows and F `focused30:6` report the same `relation-collinear-seam;region=0;seam=60,61;certs=1;cert0=120/0->97/2:first-face` site. F `selector:447` PASS; all five controls PASS. P1–P5 observed, no `valid` clause. **Candidate only:** the specific `first-face` certificate mismatch is evidence for TB23-REV to adjudicate under H-ISO-2, not a proven root cause or stable regression event. Stable **66/17/49**, debt **1**, accepted CP2 **491/491**, rejected R3 **403/497**, TB21 candidate **449/497**, selector497 unchanged. Full evidence: `Architecture_M6_CP3_TB23_Torus_A5_Site_Harvest_Report_20261021.md`.

**Review (RA-121, 2026-10-21):** harvest verified; P1–P5 held. The site is decoded in RA-121.3, and the F and A5-ISO family rows below are updated. No count changes. Record: `Architecture_M6_CP3_TB23_Torus_A5_Site_Harvest_Review_Decision.md`.

## TB22 — torus witness harvest, candidate/non-stable (2026-10-21)

Immutable artifact-only [run 39549820087](https://github.com/akashskypatel/Directional/actions/runs/39549820087), result `12323004201` (ZIP SHA-256 `71569a41315a727da3b1285cbdc94ffa360c366074fdecc3729ef0ed0b058c87`), CB21 package `12318897957`, source `8453e19e6ac7d976a9cac45978ad31104a52f034`: 11 selected/executed, 4 PASS, 7 RED, zero skips, immutable postflight. Five formerly CP2-GREEN torus identities pass shared fixture selection but RED downstream at TQ:8387, 5831, 6007, 8324, 1913 (distinct first sites; do not equate to five newly proven stable regressions). `cp3entry:1` reaches D2 assertion TQ:2827; receipt is reciprocal=5, holonomy=5, oddFaceGaugePairs=0, all candidate deltas 0. `focused30:12` unchanged A5 failure TQ:5147. Four controls PASS. **Candidate only:** TB22 Review owns causal/regression adjudication; no stable event added or historical counter changed: 66/17/49, debt 1, CP2 491/491, R3 rejected 403/497, selector497 frozen. Report: `Architecture_M6_CP3_TB22_Torus_Witness_Harvest_Report_20261021.md`.

**Review (RA-117, 2026-10-21):** the five CP2 rows have two causes. The candidate attributions below change no counts:

| Family | Identities | Locus / origin | Status |
|---|---|---|---|
| F: torus witness fixture lacks `fieldTransportAtlas` | `focused30:6`, `selector:447` | TQ:1607–1796; factory `atlas-binding` S:8462; `7de636c88` added the binding to the other pipeline fixtures (TQ:649, 757, 861) while this one was masked by `88aa8eae0` | **Closed at candidate level (RA-121):** TB23 `selector:447` PASS; `focused30:6` passes the atlas and moves to A5-ISO |
| A5-ISO: A5 `MismatchedIsolationEvidence` on certified collinear seams | `focused30:6, 20, 24, 25, 26, 27, 28`; `selector:444, 446, 448`; `cp3entry:3, 5` | One mechanism (TB23–TB25): the A5 face clauses (RP:3891–3892) on shared-node OrdinaryFront relations (RA-124.3). Torus seam 60–61 (curved) and D3 grid seam 1–4 (uniform) both have identity turn (d = F = 0, RA-126.2), so frozen D3 holds and A5 is the only blocker | CB25 (A5) + CB26 (A7). TB27 (RA-132): all 12 PASS targeted; D3 and D7 tampers reject. TB28 census (RA-133, audited RA-134): all 12 PASS, 0 PASS→RED. Negative tests in CB27 |

Record: `Architecture_M6_CP3_TB22_Torus_Witness_Harvest_Review_Decision.md`.

## TB21 — selector-497 census on CB20A; candidate/non-stable (2026-10-21)

Artifact-only [run 39533914719](https://github.com/akashskypatel/Directional/actions/runs/39533914719), result `12317287104` (ZIP SHA-256 `12279a26fbe8d2f9d2c4bae6b0317b46b9fb6480212127a59e415fb46f089c8d`), semantic source `e22c5da5f`, package `12310848591`. **449/497 PASS, 48 RED; 0 PASS→RED; RED→PASS `cp3entry:6`.** Every other RED keeps its TB18 first failure, except the eight M2 rows, which keep their TB20 failures. Inventory `.agents/Directional/Architecture_M6_CP3_TB21_Selector_497_Red_Inventory.tsv`. Reviewed by RA-115; no stable count changes.

## TB19A — torus rejection-site harvest; candidate/non-stable (2026-10-20)

Artifact-only [run 39484475466](https://github.com/akashskypatel/Directional/actions/runs/39484475466), result artifact `12292268624` (ZIP SHA-256 `25d48ed757a54ba77b7876ff0d3b833673cd57dab151f1e9632fcfcb7a8efa7c`), semantic source `d2c7483cde8e65d6c35c5df06fa880465a4da46c`, immutable compiled artifact `12275794192` (28/28 checksum entries verified). All 7 selected; positive fixture-loaded control `selector:443` PASS, 6 RED at `PublishedProductRejected product=0 detail=none site=gauge-pin-consistency;edge=0,3`. G1–G4 HELD. Source hard-rail edge `{0,3}` belongs to the minor torus cycle 0–3–25–37–49–61–0, not the major cycle. This restores measurement of TB19's six fixture-staging-invalid cases without changing source, tests, selectors, fixtures, or compiled package. The observation does **not** prove an H-pin root cause or stable regression; mandatory TB19-REV must adjudicate hard-rail carriers versus periodic cuts and record the R-route as NOT REACHED. Stable counts unchanged: **66/17/49**, debt **1**, CP2 491/491, R3 403/497 rejected, TB18 candidate 448/497, selector497 frozen, RP-01 open, RP-02 UNREACHED. Full evidence: `Architecture_M6_CP3_TB19A_Torus_Rejection_Site_Harvest_Report_20261020.md`.

## TB18 — rail-vertex consumer census; candidate/non-stable (2026-10-20)

Runs [Part A 39349041417](https://github.com/akashskypatel/Directional/actions/runs/39349041417) and [Part B 39349459268](https://github.com/akashskypatel/Directional/actions/runs/39349459268), artifacts `12231529583` / `12232299548`, immutable source `3bd24682c`, packages 18/18 and 1019/1019. Part A 12/14 PASS: the two cross-region diagnostics now fail earlier in the producer with `PublishedProductRejected`, while the R-route forged-tag test PASSes. Part B 448/497 PASS vs TB16C 425/497, 23 RED→PASS and zero PASS→RED; all 30 former B2 identities exited B2 (16 PASS, 14 RED/other), leaving 49 RED/other. These are **non-stable candidate outcomes**: first-failure migrations are not proven production regressions, and their causal source is not established by the artifact; TB18-REV owns adjudication and fixture debt. Falsifier: independent review discovers a B1/B3/U6 or a PASS→RED, or validates a factory `InvalidSourceAuthority` on an R-certified route. No stable identifier, total or selector changed: **66/17/49**, debt **1**, CP2 491/491, R3 403/497 rejected; RP-01 still open, RP-02 UNREACHED. Inventory `Architecture_M6_CP3_TB18_Selector_497_Red_Inventory.tsv` SHA-256 `36cc9682cab7ceac02beca2a8ee25b2231bc3f33ffa768d03e1ade3dc142b9ca`; report `Architecture_M6_CP3_TB18_Rail_Vertex_Endpoint_Harvest_Report_20261020.md`.

**Independent TB18-REV (RA-104, 2026-10-20):** primary manifests/497 logs/49 RED/30 B2/Part A 14 re-derived; no new B1/B2/B3/U6 or PASS→RED. Full-history authority, boundary and ledgers PASS (run `39380260884`). Existing candidate is independently adjudicated **non-stable**, never promoted to CP3 acceptance; stable 66/17/49 and debt 1 unchanged. #10/#11 `PublishedProductRejected` occur in producer fixture before a certified-route checked-factory oracle, so root cause and universal R factory admissibility are **undetermined**, carried after bounded fixture-debt work. **First assigned correction:** selector242 is a test-authority defect (modified crossField but atlas from original field); owner CB19 test-only, falsifier: mutated atlas cannot be constructed or the typed negative oracle cannot be preserved; prohibited: production edits, removing rejection assertions, or inferring a stable fail-open. Plan `Architecture_M6_CP3_CB19_Selector242_Atlas_Authority_Test_Plan_20261020.md`.

**Review of TB18-REV (RA-105, 2026-10-20):** the measurements are confirmed. The candidate attributions below change no counts:

| Mechanism | Identities | Locus / origin | Status |
|---|---|---|---|
| M1: certificate binding shadows frozen precedence (`VALIDATION_ORDER_SHADOWING` candidate) | `focused30:3, 22, 23`; `selector:139, 140, 142, 211, 219, 227, 230` | S:8755–8775, `80fc1688f` (R2). The first `make` clause to read `edges`; code 0 replaces 7 at 211/219 | Static proof; ownership decided by a DEFN after TB19-REV |
| M2: the RA-45.3 gauge pin spans rail carriers and periodic cuts (H-pin) | `focused30:12` (proved); `cp3entry:1`, `focused30:6, 20, 24`, `selector:446, 447` (nonzero-holonomy torus) | S:8510–8550, `1eaea310f`; the torus first observable changed between R3 and CB13A | TB19 site labels confirm or refute it |
| Unlocated checked-factory rejection | `cp3entry:2, 6` (Part A #10/#11) | S:13097, clause not logged | TB19; decides the RA-103.5 R-route falsifier |

RA-106/RA-107 (2026-10-20): the site labels compiled in CB19A (`d2c7483cd`, package `12275794192`), which RA-107 accepted. RA-108 (TB19 run `39464430751`): `cp3entry:2/6` and `focused30:12` reject at `gauge-pin-consistency;edge=1,4`, so the `cp3entry:2/6` clause is the gauge pin. The six torus rows were not measured (fixture staging) and TB19A reruns them. RA-109 accepted the TB19 report (`Architecture_M6_CP3_TB19_Factory_Rejection_Site_Harvest_Report_20261020.md`). RA-110 (TB19-REV): TB19A accepted; all nine M2 identities stop at the pin, and H-pin is CONFIRMED as a producer/factory gauge-domain mismatch (`Architecture_M6_CP3_TB19_REV_Gauge_Pin_Domain_Review_Decision.md`). M2 is attributed to the checked factory's pin domain, not fixture debt. RA-111 (DEFN-P1-REV) freezes the corrected domain, same-region non-hard two-face edges with a span guard, for CB20 (`Architecture_M6_CP3_DEFN_P1_Gauge_Pin_Domain_Review_Decision.md`). RA-112 (CB20-REV): the CB20 source `7dc9b89ec` matches that domain statically; the compile failed only on a test accessor, corrected by CB20A (`Architecture_M6_CP3_CB20_Gauge_Pin_Domain_Compile_Stop_Review_Decision.md`). RA-113 (CB20A-REV) accepts the compiled package `12310848591` (source `e22c5da5f`) and authorizes TB20, whose rows separate the pin from the RA-103.5 R-route (`Architecture_M6_CP3_CB20A_Gauge_Pin_Domain_Review_Decision.md`). RA-114 (TB20-REV): the pin is no longer the first failure of any M2 identity and the R-route falsifier is not observed; `cp3entry:6` passes, six torus rows stop at the test-fixture odd-gauge filter (TQ:1697, added after CP2 in `88aa8eae0`), and `cp3entry:2` and `focused30:12` stop in the hard-rail certificate/A5 area. M1 is unchanged (`Architecture_M6_CP3_TB20_Gauge_Pin_Domain_Review_Decision.md`). RA-115 (TB21-REV): no PASS→RED on the 497 selector; the torus filter is D2 / RA-33.2, inherited through a fixture shared with six CP2-GREEN rows, so the six torus rows are a test-scope defect, not a producer regression (`Architecture_M6_CP3_TB21_Selector_497_Census_Review_Decision.md`). No stable count changes.

## TB17 — focused artifact-only gate, no new stable regression — adjudicated by RA-103 (2026-10-19)

[Run 39313027637](https://github.com/akashskypatel/Directional/actions/runs/39313027637), result `12215967774` (ZIP SHA-256 `b32366a1b4f102a2c09388bd5debb34bbbb6b6ff9d71931f8e0a06e700ea2ace`) on immutable CB17 package `12214741070`/source `ccc0b00ab6a94d0889ed7c60e4532b6c985ce03e`. 13/13 exact-filter processes: #1–#7 and #13 PASS; five previously RED diagnostic identities #8–#12 remain RED and each `first_failure` is byte-identical to TB16A. These are existing candidate/non-stable `endpoint-1` route-certificate failures: CB17 changes only the factory R rule while the consumer still does not emit R. No new regression identity or root cause is evidenced. Immutable postflight; no compile/relink/benchmarks or selector-497 census. **Stable accounting 66/17/49, debt 1, candidate census 425/497 unchanged.** `RP-01` open, `RP-02` UNREACHED. Owning report `Architecture_M6_CP3_TB17_Factory_Rail_Vertex_Endpoint_Harvest_Report_20261019.md`; independent TB17-REV next.

## TB16C selector-497 census — adjudicated by RA-102 (2026-10-19)

[Run 39295624822](https://github.com/akashskypatel/Directional/actions/runs/39295624822), result `12207970911`, ZIP SHA-256 `d10553f037a4ae92913db3c07b325636fe221335f79d955258d16b4671874fcb`; immutable CB16A package `12193816372`/source `7cfa5b46`. 497 exact processes, package manifest 28/28 and immutable postflight; 425 PASS / 72 RED, identical in disposition to TB14A, with no new PASS→RED/RED→PASS identities. Under RA-90.4 with RA-91.2, B1=0, B2=30, B3=0, U6=0, other=42. All 19 previously B3 identities now B2. Candidate/non-stable classification is retained because this is a mechanistic blocker migration, not a newly demonstrated production regression; no stable ID or count change. **66/17/49**, debt **1** unchanged. Owning evidence `Architecture_M6_CP3_TB16C_Selector_497_Red_Inventory.tsv` (SHA-256 `9ea7c62ec4bbc1c9d703f121429827f2d077c25f643d9a314b641186bebb4acf`) and `Architecture_M6_CP3_TB16C_Selector_497_Census_Report_20261019.md`; TB16C-REV mandatory before CB17.


**Adjudicated by RA-102:** independently re-verified (1019/1019; the 72 REDs reclassified from raw logs as B2 30 and other 42, agreeing 72/72). Outside the B3 set, no first failure changed in substance; 10 differ only by the P10:12 `#include <bit>` line shift. U6 is complete. All 30 B2 records are one I–R shape at rail vertex 4, which the R rule satisfies. CB17 (U4) is specified. No new regression.
---

## TB16A exact-I checker harvest — predictions confirmed; adjudicated by RA-101 (2026-10-19)

[Run 39277232731](https://github.com/akashskypatel/Directional/actions/runs/39277232731), result `12198063461` (ZIP SHA-256 `7f8769edbddc8439662526ca9520919ad78888b31a12abdd9548d476edd06cba`), source `7cfa5b46`, CB16A package `12193816372`. Full 12/12 immutable selection: **7 PASS / 5 expected diagnostic RED**, 0 missing, no rebuild or selector-497 run. Corrected independent oracle #3 goes RED → PASS; #8–#12 remain RED with `first_failure` byte-identical to TB16 artifact `12183498229`. No new stable production regression established, and no promotion of the B2 diagnostics to accepted production. Stable **66/17/49**, debt **1**, CP2 **491/491**, rejected R3 **403/497**, last full census TB14A **425/497**; RP-01 open, RP-02 UNREACHED, Gate C suspended. All RA-100.3 predictions hold. Conditional TB16C 497 census now authorized; do not ascribe an unmeasured outcome to its remaining B3 identities. Report: `Architecture_M6_CP3_TB16A_Exact_I_Witness_Checkers_Harvest_Report_20261019.md`.


**Adjudicated by RA-101:** independently re-verified (manifest 16/16; the harness diff is lines 7–9 and the labels only). The full #8–#12 predicate lines, not only the 600-character ledger field, are byte-identical to TB16. The U6 gates are closed. The TB16C deliverables are pinned (RA-101.4).
---

## TB16 exact-I checker harvest — adjudicated by RA-98 (2026-10-19)

[Run 39246335010](https://github.com/akashskypatel/Directional/actions/runs/39246335010), artifact `12183498229`, ZIP `8a329317a610a014cb834947d841fac788ffa55813519dc5259c342a3b62dc32`, CB16 `1c45e89a`: **12/12 selected; 6 PASS, 6 RED; immutable postflight**. Ordinal 3 is a **candidate test-oracle defect**: nextafter on reverse bary[2] yields the other legitimately reconstructed canonical rounding, so bound witness remains true. Ordinals 8–9 unchanged relative to TB15 #5/#6; ordinals 10–12 advance from front 17/203 to 97/283 but remain RED. RA-97.5 falsifier triggers independent Review; TB16C held. **Not a demonstrated new production regression**; stable **66/17/49**, debt 1, CP2 491/491, rejected R3 403/497, TB14A census 425/497 unchanged. Report: `Architecture_M6_CP3_TB16_Exact_I_Witness_Checkers_Harvest_Report_20261019.md`. **Adjudicated by RA-98:** independently re-verified.
- #3 is a Review spec defect: the mutation produced the other valid orientation image, so the checker is correct.
- #10–#12 are now B2 (front 97/283, vertex 4), so B3 is cleared on these identities.
- No regression.

---

## TB15 exact I-endpoint witness harvest — adjudicated by RA-97 (2026-10-18)

[Run 39170298228](https://github.com/akashskypatel/Directional/actions/runs/39170298228), result `12152685129` (ZIP SHA-256 `2536c38b958f76cfef6c5e0ef951e902e958d2cdb863e650e2b8b4002a50f748`), immutable CB15 semantic source `e4785d734e35d2f01ca3ee8099772f6ab5257f4c`, package `12150973440`. All nine exact tests selected and postflight-immutable: 4 PASS gates, 5 expected RED diagnostics. Two B2 tests retain no exact witness and binds 0; three B3 tests show matching bound `1,4@1/5` witnesses on both sides. Removing precisely the four new exact-witness fields makes all five first-failure records byte-equal to TB13A (#3–6) or TB14A (selector 217) baselines. **Classification:** existing `RP-01` B2/B3 causes, not newly introduced stable or candidate regressions; no early-admission behavioral change. **66/17/49**, debt **1**, CP2 **491/491**, rejected R3 **403/497**, latest full census **425/497** unchanged. Required independent TB15 Review before CB16. Owning report: `Architecture_M6_CP3_TB15_Exact_I_Witness_Harvest_Report_20261018.md`. **Adjudicated by RA-97:** independently re-verified; classification confirmed. The witness is exactly 1/5. RA-95.3's "p ≠ 1/5" is withdrawn. CB16 specified.

---

## TB14A curved-disk control census — adjudicated by RA-94 (2026-10-18)

[Run 39143325285](https://github.com/akashskypatel/Directional/actions/runs/39143325285), result `12141843937` (`1b06e43e…d455`), on CB14A package `12140756646` (source `2ee499a3`): **425 PASS / 72 RED**.
- Against TB13C, exactly five identities went RED → PASS (199/235/236/294/299) and none went PASS → RED. The 72 REDs are unchanged in substance (RA-94.2).
- 235/236/294/299 are restored curved-disk controls.
- 199 falsified RA-93.4. Its cylinder half was repaired after R3 by `2be228d96` (source A3 supplied, assertions unchanged), and the stale disk half hid that at TB13C. It is a valid control.
- 425 = R3 403 + 26 RED → PASS − 4 test-debt REDs (174, 191, 242, 442).
- No production regression; **66/17/49**, debt **1** unchanged.

---

## TB13D bisect — TB13C candidates resolved: test debt, no production regression (2026-10-18)

P1 [run 39132801755](https://github.com/akashskypatel/Directional/actions/runs/39132801755), result `12138931233`, source `007585f8e` (+32): 422/497. P4 [run 39132921344](https://github.com/akashskypatel/Directional/actions/runs/39132921344), result `12138633102`, CB12 `b1b02d5be`: 420/497, identical to CB13A on all 497. P2 and P3 were cancelled while pending (dispatcher concurrency) and are not needed.

**Classification (RA-92):** none of the 8 is a production regression, and none receives a stable ID.

| Ordinal | First RED | Cause | Class |
|---|---|---|---|
| 235/236/294/299 | by P1 | `make_curved_disk_fixture` lacks the rail provenance required since `c7cb5d68b`/`715fe2d66` | stale fixture (repair CB14A) |
| 242 | by P1 | `8df105b56` | test-spec defect |
| 191 | by P1 | `7ccdcd527`: the atlas build fails in the fixture and its error is dropped | fixture |
| 174 | after P1 | `18357617a`: non-manifold three-face TriMesh | fixture |
| 442 | after P1 | `b9f70f3fe`: seam assertion never run, `SingularityMismatch` | assertion never run |

This corrects RA-91's "production regression" label for the curved disk. **66/17/49**, debt **1** unchanged. Record: `Architecture_M6_CP3_TB13D_Bisect_Review_Decision.md`.

---

## CANDIDATE / NON-STABLE — TB13C census: 8 identities PASS at R3 are RED on CB13A (2026-10-18)

[Run 39127652521](https://github.com/akashskypatel/Directional/actions/runs/39127652521), result `12136761296` (ZIP SHA-256 `92d9c9bd…f545`), CB13A package `12132184878`: 497 executed, **420 PASS / 77 RED**, no orchestration failure. Inventory: `Architecture_M6_CP3_TB13C_Selector_497_Red_Inventory.tsv`.

The 8 identities that were PASS at R3 (`d82e34427`) and are RED now are all in selector449:

| Ordinal | First failure | Status |
|---|---|---|
| 235, 236, 294, 299 | Curved bounded disk: the pipeline returns `PublishedProductRejected`. Fixture and failing lines unchanged since R3. | Production regression, commit unknown |
| 242 | The must-reject seam test now produces. | Test-specification defect from `8df105b56`. Transport reads only the A3 atlas (S:5389-5397), so the tampered raw transitions are never consumed. |
| 174 | DCEL consistency exception | Unattributed |
| 191 | Periodic-route fixture A3 unavailable | Unattributed |
| 442 | FTA:2856 `seamBuilt` false | Unattributed |

**Classification (RA-91):** these are candidates, not stable IDs, until TB13D's retained-package bisect attributes them. The stable counts stay **66/17/49**, debt **1**. The 30 RP-01 identities (B2 11, B3 19) were RED at R3 and are not regressions. The 25 that were R3 RED and now pass are accepted as measured controls; no assertion was removed. Record: `Architecture_M6_CP3_TB13C_Census_Review_Decision.md`.

---

## TB13A — U3 scoped closure, no new stable regression (2026-10-18)

[Run 39121449664](https://github.com/akashskypatel/Directional/actions/runs/39121449664), result 12134411966, CB13A package 12132184878: two PASS gates; B2 (#3/#4) and B3 (#5/#6) expected RED byte-identical to TB13. No `open-rail-chain-interval` falsifier. U3 closed, B2 U4/U5 and B3 U6 still open. No new stable ID or historical-count change: 66 events / 17 categories / 49 recurrences; debt 1. See `Architecture_M6_CP3_TB13A_Truth_Table_Harvest_Report_20261018.md`.

**Classification (RA-90):** confirmed by independent re-verification, with #3–#6 compared directly against TB13. U3 is closed and B1 is cleared on the RP-01 fixtures. RP-01 stays open on B2 (U4/U5) and B3 (U6). The TB13C census measures how many of the frozen 497 each shape owns.

---

## CANDIDATE / NON-STABLE — TB13 reversed-route truth-table discrepancy (2026-10-18)

[TB13 run 39112131501](https://github.com/akashskypatel/Directional/actions/runs/39112131501), source `70217cc2`, package `12130290543`, result `12130683535` (ZIP SHA-256 `43505af2912b840262307db96865c5e7f9e2af8ca3b9cbe5426f0b18e87f4885`): six exact identities, **1 PASS / 5 RED / 0 missing**, immutable postflight. The required truth table expects `check({{4,7},{1,4}}, nullopt, nullopt, [1,4,7])` false, but its implementation returns true, consistent with RA-87.4's allowance of a reverse chain walk. **Candidate specification/test contradiction, not a demonstrated stable regression.** Independent Review must determine required semantics; do not change a test to obtain green. The two P10 diagnostics move from `open-rail-route-anchor` front 29/147 to `endpoint-1` front 61/179 (B2 rail-interior vertex 4). Both pipeline B3 raw 9,180-character first failures remain byte-identical to TB12 at `endpoint-1` front 17/203. RP-01 open, RP-02 UNREACHED; no direct production accepted or selector497 executed. Frozen totals **66/17/49**, debt1, CP2 491/491, R3 403/497, selector497, Gate C suspended. Owner: `Architecture_M6_CP3_TB13_Open_Rail_Chain_Interval_Harvest_Report_20261018.md`. Conditional TB13C held pending independent Review.

**Classification (RA-88):** not a regression and not a code defect. The false row in RA-87.4.7 contradicted RA-87.4.1's own either-direction rule: `[4-7, 1-4]` is the valid reverse walk 7→4→1. This is an owned Review specification defect. The helper is correct, and the RA-87.5 predictions for #2–#6 all held. Front 29/147 now passes the consumer interval rule on real data, which is the rule's first real-data coverage. CB13A corrects the row and adds three discriminating rows. **Falsifier:** at TB13A, #1 is still RED, or any #3–#6 `first_failure` differs from TB13.

---

## CANDIDATE / NON-STABLE — TB12: chain provenance gates pass; RP-01 diagnostics remain RED (2026-10-18)

[TB12 run 39103358061](https://github.com/akashskypatel/Directional/actions/runs/39103358061), immutable CB12 source `b1b02d5bed43898af0708d76dcd70ada96aeecc9`, compile artifact `12125223513`, result `12127706461` (ZIP SHA-256 `1b6c3babd942cfc7fc7bbeff94774bf719297fdb9bc7ca3c0088e40110f2dfee`). Exactly 6 selected / 0 missing, two focused gates PASS and four non-gating RP-01 diagnostics RED. #3/#4 retain the byte-identical TB11 `open-rail-route-anchor` predicate for front 29/147; #5/#6 reject earlier at `endpoint-1` and both raw first-failure lines contain `firstPredicate=`. **The CB12 publication validator is not reached** on these pipeline witnesses; no claim of production validation. All predictions in RA-86.4 are confirmed in the scope actually measured, and the CB12 falsifier `PublishedProductRejected` without `firstPredicate=` is absent. Existing unresolved `RP-01`, not an independently established new stable regression. The failure root remains the previously reviewed missing open-rail interval/interior-vertex contract (U3–U5), pending independent Review; the two control assertions do not prove the later mutation path. Preserve stable **66/17/49**, debt **1**, CP2 **491/491**, R3 **403/497**, selector **497**, RP-02 UNREACHED, Gate C suspended. Owning report: `Architecture_M6_CP3_TB12_Open_Rail_Chain_Provenance_Harvest_Report_20261018.md`.

**Classification (RA-87):** every prediction held, and U2 is closed. **Correction:** for #5/#6 the root is *not* U3–U5. Their first failure is B3: the face-0 side of the I endpoint at (1, 0.2) has barycentrics summing to exactly 1 + 2⁻⁵⁵, so `interior_carrier_parameter` rejects it. This is the RA-61.6 mechanism, which R9B deliberately left open. It is owned by the new unit U6 (DEFN first). **Falsifier:** at TB13, `cp3entry:2/6`'s first failure changes even though CB13 does not touch endpoint predicates.

---

## CANDIDATE / NON-STABLE — TB11: RP-01 fixture now first fails at an I–I front (2026-10-18, RA-85)

Immutable [TB11 run 39092477302](https://github.com/akashskypatel/Directional/actions/runs/39092477302), result artifact `12123605663` (ZIP SHA-256 `e98acd39a8a72f54118c6e6a66f7ec8346a6dd5d1043db06f1b12ad5298d9a65`), CB11 semantic source `9432aa05ef4719cbea912ae0feb2c5508c4e497a`. Exact 3/3 tests selected: **1 PASS, 2 RED**. Both RED tests abort at initial expected `Produced` fixture state, receiving `Rejected` from `open-rail-route-anchor` at locus 9 (rail 2, front 29/147, face 0→3, edge 1–4), **before** cleared-terminal mutation or retained control assertion. The truth-table unit test passed. **Classification (RA-85):** not a U1 regression. The fixture has never been `Produced` (RP-01 family, `no-exact-terminal-corner` since the R4 interior-witness TB of 2026-10-15). Front 29/147 is an I–I middle segment of rail 1–4–7. The consumer pushed it before CB11 and failed later at vertex 4; U1 now rejects it first. The "I–I rejected" rule (RA-84.1) is withdrawn; the open-chain interval route rule (RA-85.4) admits it. **Falsifier:** at TB13, front 29/147 still fails at the route layer.

---

## CURRENT CANDIDATE / NON-STABLE — RP-01: endpoint at an open-rail interior vertex has no admitting branch (TB10, reviewed RA-81 2026-10-17)

TB10 immutable run [38941839640](https://github.com/akashskypatel/Directional/actions/runs/38941839640), result `12062873272` ZIP SHA-256 `4db22a924f31a7bc6fdf1575a66849a2f660a760003e03e26e7f9277ac200513`; compiled source `d938ecb57e1040c2a73d5d25c4a613414556cb18`, artifact `12062565622`. 44/44 selected, 44 RED, 0 missing, 48 A3 observations, 21 exact-one-hot vertices: **contact-endpoint membership 0/21; carrier-edge membership 21/21; composite 0/21**. Example decoded vertex 4, published contact endpoints {1,7}, carrier edge {1,4}, certificate rail 2. Immutable postflight passed, 28/28 package hashes, compile/relink/benchmarks/selector497 not executed. Evidence is candidate/non-stable and does not modify 66/17/49, debt1, CP2 491/491, R3 403/497, selector497; RP-01 open, RP-02 UNREACHED. Independent Review next (ID UNKNOWN); no repair authorized.

The published-contact endpoint mismatch is newly isolated on 21 exact-vertex records; this is a diagnostic candidate, not a new stable regression event or ledger credit.

**Classification (RA-81):** owner — consumer endpoint contract (RA-79 V/I/C), not a producer. The other six records are the same phenomenon in the compacted numbering (vertex `2`, contact `{1,6}`, carrier `{1,2}`). Vertex `4` is the interior vertex of the open rail `1–4–7`; V admits rail terminals, I strictly interior edge points (`0 < t < 1`), C closed rails, so the case is uncovered. **Falsifier:** a source path that admits an interior-rail-vertex endpoint in either checker (`SurfaceCellTracing.cpp:19265-19544` or `:8528-8870`). **RA-83 (R10A reviewed):** confirmed in two verifier layers — per endpoint (`:8699-8721`) and route level (`:8597-8614`, an open-rail front needs a published terminal end); star incidence is seeded only for published terminals (`:8495-8519`). The consumer has no route-level requirement, so I–I fronts it certifies are rejected at publication (`:12858`). The ordered open-rail chain reaches the consumer (`SurfaceCellTracingOptions::authoritativeRails`) but not the verifier.

**RA-84 (R10B reviewed):** rule accepted with amendments. R is admitted only as a strictly interior vertex of the named open rail's ordered chain, carried to the factory next to the terminal pair (same trust root as T, RA-84.2). It needs exactly two hard spokes, unique disjoint per-side A3 paths, and must be the outer vertex of its end step. **RA-85:** the route rule is now an open-chain interval, which admits I–I middle fronts (RA-85.4). Units are realigned to U2–U5; next `M6-CP3-CB12-R10-OPEN-RAIL-CHAIN-PROVENANCE`. **RA-87:** RP-01 has three blocker shapes: B1 I–I anchor (U3), B2 R endpoint (U4/U5), and B3 inexact I parameter (U6, new; `cp3entry:2/6`, front 17/203). **RA-95:** all 19 B3 identities are one template (front 17/203, span 3, ordinal 1). Both sides share one exact `location_parameter`; `boundary_trace_point` rounds it differently per orientation, which gives the one-ULP pair. **RA-96:** U6A verified this trace. The fix is a canonical exact witness, bound bit for bit to the doubles, first measured with no admission change (CB15/TB15). No runtime pass is claimed; `RP-01` stays open until all three are cleared and reviewed.

---

