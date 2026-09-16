# M4-CP-SCALE-TB10 Review Record

**Turn:** `M4-CP-SCALE-TB10-REV`
**Boundary:** runtime-free independent Review; no product/test/fixture/selector/build-source mutation
**Reviewed candidate:** package `10461816370` / semantic source `2adb7b8169a387fcb6db6487768d7bd3d678265c`
**Reviewed runtime:** `35135187381 / 104925730218`
**Verdict:** **ACCEPT / PROMOTE PACKAGE / S4 FOCUSED PRODUCT ACCEPTED FOR PUBLICATION / CUMULATIVE S4 SELECTOR CREDIT WITHHELD**
**Exact successor:** `M4-CP-SCALE-CB12`

## 1. Decision

Review promotes CB11 package `10461816370` / source `2adb7b8169a387fcb6db6487768d7bd3d678265c` as the current M4 runtime authority under the unchanged accepted selector425. The focused product identity `M4CPScaleS4.IncrementalTopologyRejectorNeverDisagreesWithFinalDiscCertificate` is accepted as a non-vacuous, one-way-safe S4 product witness and is authorized for append-only selector publication.

This Review does **not** count the focused identity as cumulative S4 selector credit. Selector425 remains the accepted required-green selector. Publication is a separate bounded Code + Build step because the accepted selector is append-only and byte-frozen. `M4-CP-SCALE-TB10-REV-OBS-01` therefore remains open until selector426 is published, freshly executed, and reviewed.

CP-SCALE remains OPEN. S1 remains diagnostic/non-gating, the S2 arrival comparator remains blocked on an exact fallback owner, S4 cumulative selector acceptance remains owed, and S5 still requires a retained genus>=2 produced witness.

## 2. Exact evidence independently reopened

Review independently reopened and reverified:

- CB11 candidate artifact `10461816370`, provider SHA-256 `93f47702e3919eff0b5503acd7506fbdf661477b6b55b91a0f29fc5a98be2358`;
- semantic source `2adb7b8169a387fcb6db6487768d7bd3d678265c`;
- packaged source archive SHA-256 `79ea26c2f9faf9499e33db02c65cba04b47f3a64eeb35b0c4c421fcf45c50afe`;
- package `SHA256SUMS`: 28 entries, manifest SHA-256 `ef128c01e17db2eebb78e7e92722f732af040d8a6862cda9b24f9e5969ca6dbf`, all 28 entries verified;
- exact GMP/GMPXX linkage and required executable modes;
- TB10 run/job `35135187381 / 104925730218`;
- result artifact `10463670805`, provider SHA-256 `a74e65ef4040d1889212c31da997f0b629d1279913e5ae358ed4846e587e83f9`;
- log artifact `10464360210`, provider SHA-256 `09d2e92e649ec7e4dfd868cedeeb0066fa4443cc54fe39400ecc9592a7a38bea`;
- nested evidence ZIP SHA-256 `b17c2956d5e6735098a772465922f4d0d620c1c8ddbbbbe1527800a2bf188133`;
- nested 1304-entry self-manifest SHA-256 `b7170097b5e665f7228dc23587ac3abe4e05f8a5e584b22c89b8681d6a22e7cb`, all 1304 entries verified.

The runtime package was not rebuilt or repaired. The Review itself executed no Directional binary.

## 3. Accepted selector and runtime ledger re-derived

Review re-hashed `Architecture_M4_CP_SCALE_CB8_Required_Green_Selector_425.txt` independently:

- 425 LF-terminated rows;
- 425 unique identities;
- SHA-256 `e0e0f394faae536ac257ec5409653a34755a8afe0ca437562eb44c9895790e0b`;
- exact first424 prefix SHA-256 `f202a1720c0a5288471d04836402b8432eb6f4f788da68a12e70dacb875466ca`.

The TB10 selector-process ledger contains exactly contiguous ordinals 1-425 in selector order. Every row has one exact identity, exit `0`, selected/executed/passed `1/1/1`, skipped `0`, outcome PASS. The owner census independently sums to **30 authority-kernel / 279 producer / 75 completion / 41 validation**. No selector row is missing, duplicated, reordered, skipped, timed out, crashed or selection-mismatched.

The focused S4 process is separate from those 425 selector processes, so TB10 executed 426 Directional processes total: one focused S4 process plus 425 accepted-selector processes.

## 4. S4 counting domain is structurally independent

The production S4 helper does not read `proposal_components`, final-certificate face fields, or product face-walk orbit count as its complement authority. `actual_complement_component_count(const EmbeddedGraphTopology&)` reconstructs the connected complement from exact arc `sourcePath` pieces and exact local planar subdivision:

1. exact graph barrier intervals are recorded on source edges;
2. exact rational barycentric coordinates place graph pieces within each source triangle;
3. local planar fragments are constructed from graph pieces plus source-edge seam segments;
4. ambiguous/non-planar/intersecting/collinear arrangements fail closed to `nullopt` rather than early-reject;
5. fragments are stitched across only non-barrier source-edge intervals;
6. a DSU count yields connected actual-complement components.

`fixed_candidate_topology_invariant` then derives `V`, `E`, graph components `c`, source components `s`, first Betti number `b1=E-V+c`, source Euler characteristic `chi`, required face count `F_required=chi-s+b1`, and observes `F_observed` from the independently reconstructed connected complement. S4 rejects only when the observed and required counts differ. If the count is unavailable, production falls through to unchanged final certification.

The focused test uses a structurally separate independent actual-embedded-graph oracle, not the product helper, for the negative/positive/adversarial comparisons. That separation is sufficient to adjudicate the counting domain rather than merely compare a function to itself.

## 5. Earlier-never-different safety independently re-derived

The one-way S4 safety obligation follows from the unchanged final certificate authority.

The final certificate can prove embedded cellularity only when graph-component count equals source-component count (`c=s`). If `c!=s`, final certification already fails, so an S4 rejection cannot disagree with a successful final certificate.

If `c=s`, then

`b1 = E - V + s`

and therefore

`F_required = chi - s + b1 = chi + E - V`.

If the unchanged final certificate could succeed, every connected complement component is a disc. Euler's formula for that cellular embedding then requires

`F_observed = chi + E - V = F_required`.

Therefore `F_observed != F_required` is a necessary-condition failure: **S4 reject implies the unchanged final certificate cannot succeed**. The converse is neither required nor claimed. A non-rejected candidate still runs the unchanged final certificate, which remains the only acceptance authority.

The production canonical loop respects that proof boundary. It builds the fixed candidate topology once, may skip only that candidate's doomed final-certification attempt after an S4 reject, and then enters the existing proposal/saturation path. It does not add/remove/reorder cuts, backtrack, repair topology, create acceptance, or weaken `SurfaceCutGraphCellularityCertificate::proves_embedded_cellularity()` plus per-face disc topology.

## 6. Focused runtime is non-vacuous

The focused identity passed **1/1** and emitted one `m4CpScaleS4Product` receipt. Review re-derived the decisive cases:

- negative: `V=48,E=48,Fobs=4,c=4,s=1,chi=0`, so `b1=4`, `F_required=3`, reject `true`;
- positive: `V=72,E=76,Fobs=4,c=1,s=1,chi=0`, so `b1=5`, `F_required=4`, reject `false`;
- the one-edge adversarial state satisfies the required implication `product reject => unchanged final certificate non-cellular`;
- reversed cut enumeration leaves the product invariant unchanged;
- accelerated and S4-disabled reference executions publish the same accepted cuts, pre-existing certificate fields, bindings, semantic digest and provenance digest.

The deletion discriminator is also live. Product diagnostics record `candidateEvaluations=2`, `earlyRejects=1`, `fullCertificationAttempts=1`; the S4-disabled reference records `fullCertificationAttempts=2`; `bypassedFinalCertificationAttempts=1`. Thus one candidate genuinely bypasses final certification, and removing the accelerator would increase full-certification attempts from one to two. The focused green result is not a vacuous branch.

## 7. Immutable postflight and regression disposition

TB10 independently records and Review rechecks:

- `package_census_equal=true`;
- `source_census_equal=true`;
- `execution_view_census_equal=true`;
- `fixtures_equal=true`;
- `postflightComplete=true`.

Configure, compile, relink, code generation, chmod, repair, discovery/list/help/version, benchmark execution, source/test/fixture mutation and selector mutation all remained false. No accepted PASS-to-RED transition, RED, SKIP, crash, timeout, selection mismatch, orchestration failure or new defect candidate occurred.

Stable accounting therefore remains **49 events / 14 categories / 35 recurrences** and produced-witness debt remains **5**.

## 8. Promotion and publication boundary

Package `10461816370` / source `2adb7b8169a387fcb6db6487768d7bd3d678265c` is promoted as current M4 runtime authority under selector425 **425/425**.

The focused S4 product identity is accepted **for publication**, not yet as cumulative selector credit. The append-only publication bytes are frozen in advance for CB12:

- selector426 = exact selector425 bytes + one LF-terminated row `M4CPScaleS4.IncrementalTopologyRejectorNeverDisagreesWithFinalDiscCertificate`;
- 426 rows / 426 unique identities;
- exact selector425 prefix SHA-256 `e0e0f394faae536ac257ec5409653a34755a8afe0ca437562eb44c9895790e0b`;
- expected selector426 SHA-256 `41f4d559211375c11c8d1f8c9ccde2581db75819d9409366e8f2695b008b5114`;
- expected owner census **30 authority-kernel / 280 producer / 75 completion / 41 validation**.

`M4-CP-SCALE-TB10-REV-OBS-01` — **OPEN / SELECTOR426 PUBLICATION + FRESH CUMULATIVE RUNTIME + REVIEW / NON-DEFECT**. Root cause is evidentiary, not semantic: the S4 product identity is accepted by focused runtime and Review but is outside the current byte-frozen selector425. Owner chain is `M4-CP-SCALE-CB12 -> M4-CP-SCALE-TB11-EXEC -> M4-CP-SCALE-TB11-REV`. Cumulative S4 credit is prohibited until that chain succeeds.

## 9. Prior obligations

- `M4-CP-SCALE-TB1-REV-OBS-01` — **CARRIED**; S1 representative/stress calibration before any numeric gate.
- `M4-CP-SCALE-TB2-REV-OBS-02` — **CARRIED**; dedicated audit of remaining `make_zero_transport_field` callers.
- `M4-CP-SCALE-DEFN-OBS-01` — **CARRIED**; S2 arrival-order exact fallback owner not frozen.
- `M4-CP-SCALE-DEFN-OBS-02` — **DISCHARGED by TB6 Review**.
- `M4-CP-SCALE-DEFN-OBS-03` — **DISCHARGED by TB9 Review**.
- `M4-CP-SCALE-DEFN-OBS-04` — **CARRIED**; genus>=2 construction/reachability owed.
- `M4-CP-SCALE-TB4-REV-OBS-01` — **DISCHARGED by TB5 Review**.
- `M4-CP-SCALE-TB6-REV-OBS-01` — **DISCHARGED by TB7 Review**.
- `M4-CP3-TB1-R1-REV-OBS-01` — **CARRIED to M4-CP4**.
- `M4-CP3-CB4-REV-OBS-02` — **CARRIED to next legitimate row399 touch**.
- `G4-B002` produced-witness debt — **CARRIED**, three M4-CP4-owned debts.
- `G4-B003` produced-witness debt — **CARRIED**, two M5-owned debts.
- `M4-CP-SCALE-TB10-REV-OBS-01` — **NEW / OPEN**, selector426 publication and cumulative acceptance chain.

## 10. Exact bounded successor

Exact next is `M4-CP-SCALE-CB12` under `Architecture_M4_CP_SCALE_CB12_Selector426_Publication_Code_Build_Plan.md`.

CB12 is publication-only Code + Build. It may create the exact selector426 bytes above and update selector lineage/manifest plus required control documentation. It may not modify product/test/fixture/CMake/benchmark semantics. It must compile/package the unchanged promoted semantic source under mandatory GMP/GMPXX with `runtimeExecution=false`. It stops if the selector425 prefix changes, row426 is not the exact accepted S4 identity, the expected selector426 digest/owner census does not match, any forbidden semantic path changes, or compile/package authority is not exact.

Fresh artifact-only `M4-CP-SCALE-TB11-EXEC` and mandatory `M4-CP-SCALE-TB11-REV` remain required before S4 cumulative selector credit.

## 11. Consolidation

This Review folds superseded/consumed CP-SCALE per-turn documents into `M4_Consolidated_Record.md` §2.58 and its folded-document index:

- `Architecture_M4_CP_SCALE_CB11_S4_Product_Activation_Code_Build_Plan.md` — consumed;
- `Architecture_M4_CP_SCALE_CB11_Code_Build_Report.md` — superseded;
- `Architecture_M4_CP_SCALE_TB10_Artifact_Only_Test_Benchmark_Plan.md` — consumed;
- `Architecture_M4_CP_SCALE_TB9_Artifact_Only_Test_Benchmark_Report.md` — superseded runtime authority;
- `Architecture_M4_CP_SCALE_TB9_Review_Record.md` — superseded Review authority.

The current role set retains this Review record, the current TB10 runtime report, frozen definitions, all selectors, the consolidated record, and exactly one next-turn CB12 plan. No selector, policy, frozen definition, closure record, stable ID, unresolved blocker or durable project authority is folded.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | selector425 = `e0e0f394faae536ac257ec5409653a34755a8afe0ca437562eb44c9895790e0b`; exact first424 = `f202a1720c0a5288471d04836402b8432eb6f4f788da68a12e70dacb875466ca` |
| Decisive claims independently re-derived | package/evidence manifests; 425-row process/owner ledger; exact complement-count domain; `F_required=chi-s+b1`; one-way safety proof; focus counts/bypass; immutable postflight |
| Non-vacuity checked | real early reject/bypass: accelerated full-cert attempts `1`, reference `2`, bypassed `1`; negative/positive/adversarial/enumeration and decision-neutral controls execute |
| Prior obligations discharged/carried | §9 lists every CP-SCALE and inherited obligation; new `M4-CP-SCALE-TB10-REV-OBS-01` is carried to CB12/TB11/Review |
| Stable accounting | **49 events / 14 categories / 35 recurrences**, debt **5**; promoted package `10461816370` / source `2adb7b...265c` under selector425 **425/425** |
| New candidates/obligations recorded | `M4-CP-SCALE-TB10-REV-OBS-01` — publication/cumulative-selector obligation, non-defect; tracker updated |
| ORIENTATION currency line | `M4-CP-SCALE-TB10-REV`, 2026-09-16 UTC |
| ORIENTATION §3 / §4 / §7 / §8 | §3 updated to promoted package and S4 publication state; §4 torus state updated; §7 reprioritized with CB12 next; §8 n/a — no new recurring defect pattern found by this Review |
| CHANGELOG | TB10 Review promotion/publication entry added |
| ROADMAP | CP-SCALE status updated: S4 focus accepted for publication, cumulative S4 still owed, exact next CB12 |
| Selector manifest | n/a — selector425 remains unchanged; selector426 is not published in a Review turn and is owned by CB12 |
| LESSONS | n/a — no new recurring pattern; existing review non-vacuity and turn-boundary rules were sufficient |
| Consolidation under CLEAN_UP_POLICY | CB11 plan/report, TB10 consumed plan, TB9 runtime report and TB9 Review folded into `M4_Consolidated_Record.md` §2.58/index; current TB10 report retained |
| Successor frozen | exactly `M4-CP-SCALE-CB12`; falsifiers/STOP rules in `Architecture_M4_CP_SCALE_CB12_Selector426_Publication_Code_Build_Plan.md` |
| Turn boundary held | yes — Review runtime-free; no product/test/fixture/selector/build-source mutation |
| review_check.py boundary | PASS; no forbidden Review-turn source/test/fixture/selector/build mutation in the closeout diff |
| `STATUS` lifecycle maintained | `M4-CP-SCALE-TB10-REV`; `Started at` preserved `2026-09-16T20:18:14Z`; latest `Resumed at` maintained on continuation; final COMPLETE beacon sets exact successor and `Ended at` after all docs/cleanup |
| Pushed to origin, branch in sync | final closeout verifies working-branch push/head before COMPLETE beacon; no alternate ref or force push is used |
