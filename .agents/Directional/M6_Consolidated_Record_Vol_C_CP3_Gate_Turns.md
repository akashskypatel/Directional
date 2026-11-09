# M6 consolidated record, volume C: CP3 numbered CB/TB Review decisions and non-P13 definitions, through 2026-10-31

This volume holds **80** former standalone `Architecture_M6*` records, moved here on 2026-11-09 by user instruction ("consolidate these records and prune if the content from each is already documented elsewhere"). No record's content was already documented elsewhere: verbatim-line coverage in the permanent documents was at most 27%. So each record is kept **verbatim** as one section below, and nothing is summarized. Only two things changed: heading levels are demoted by two, and links to other moved records point to their sections. Each original file existed standalone at commit `7a460a5e41c4a77a51b69db672e69f910532718c` (`git show 7a460a5e41c4a77a51b69db672e69f910532718c:.agents/Directional/<name>`). Anchors inside a record (`#…`) may resolve to an earlier record in this volume that has the same heading text. The [moved-record map](M6_Consolidated_Record.md#m6-moved-record-map-2026-11-09) lists every record and its volume.

| Original file | Title |
|---|---|
| [`Architecture_M6_CP3_CB19A_Factory_Rejection_Site_Review_Decision.md`](#architecture_m6_cp3_cb19a_factory_rejection_site_review_decisionmd) | RA-107 — CB19A accepted; TB19 specified exactly (2026-10-20) |
| [`Architecture_M6_CP3_CB19_Factory_Rejection_Site_Compile_Review_Decision.md`](#architecture_m6_cp3_cb19_factory_rejection_site_compile_review_decisionmd) | RA-106 — CB19 compile failure reviewed: diagnostic design stands; corrective CB19A authorized (2026-10-20) |
| [`Architecture_M6_CP3_CB1_Entry_R2_Recovery_Code_Build_Plan.md`](#architecture_m6_cp3_cb1_entry_r2_recovery_code_build_planmd) | M6-CP3-CB1-ENTRY-R2 — Recovery Code + Build Plan (RELEASED by R2 Review with mandatory stop gates) |
| [`Architecture_M6_CP3_CB20A_Gauge_Pin_Domain_Review_Decision.md`](#architecture_m6_cp3_cb20a_gauge_pin_domain_review_decisionmd) | RA-113 — CB20 and CB20A accepted: corrected gauge-pin domain compiled; TB20 authorized (2026-10-21) |
| [`Architecture_M6_CP3_CB20_Gauge_Pin_Domain_Compile_Stop_Review_Decision.md`](#architecture_m6_cp3_cb20_gauge_pin_domain_compile_stop_review_decisionmd) | RA-112 — CB20 compile stop reviewed: source accepted statically; test accessor correction authorized as CB20A  |
| [`Architecture_M6_CP3_CB22A_Torus_A5_Isolation_Site_Formatter_Review_Decision.md`](#architecture_m6_cp3_cb22a_torus_a5_isolation_site_formatter_review_decisionmd) | RA-119 — CB22A harvested and accepted statically; five A5-ISO rows cannot show the site; test-message routing  |
| [`Architecture_M6_CP3_CB22B_Torus_A5_Site_Test_Messages_Review_Decision.md`](#architecture_m6_cp3_cb22b_torus_a5_site_test_messages_review_decisionmd) | RA-120 — CB22B accepted statically; the site reaches all nine A5-ISO rows; TB23 harvest issued (2026-10-21) |
| [`Architecture_M6_CP3_CB22_Torus_A5_Isolation_Site_Compile_Stop_Review_Decision.md`](#architecture_m6_cp3_cb22_torus_a5_isolation_site_compile_stop_review_decisionmd) | RA-118 — CB22 compile stop reviewed: diagnostic accepted statically; occurrence formatter and name correction  |
| [`Architecture_M6_CP3_DEFN_P1_Gauge_Pin_Domain_Review_Decision.md`](#architecture_m6_cp3_defn_p1_gauge_pin_domain_review_decisionmd) | RA-111 — DEFN-P1 reviewed: census accepted; exactness withdrawn for a spanning domain; CB20 authorized (2026-1 |
| [`Architecture_M6_CP3_DEFN_U6_Exact_I_Origin_Review_Decision.md`](#architecture_m6_cp3_defn_u6_exact_i_origin_review_decisionmd) | RA-95 — DEFN-U6 stopped without a deliverable; Review locates the exact I-endpoint origin; DEFN-U6A narrowed ( |
| [`Architecture_M6_CP3_TB11_Route_Anchor_Review_Decision.md`](#architecture_m6_cp3_tb11_route_anchor_review_decisionmd) | RA-85 — TB11 reviewed: the RED is RP-01, not U1; I–I must be admitted; plan realigned |
| [`Architecture_M6_CP3_TB12_Chain_Provenance_Review_Decision.md`](#architecture_m6_cp3_tb12_chain_provenance_review_decisionmd) | RA-87 — TB12 reviewed: U2 closed; a third RP-01 blocker has no unit; CB13 specified; selector census added |
| [`Architecture_M6_CP3_TB13C_Census_Review_Decision.md`](#architecture_m6_cp3_tb13c_census_review_decisionmd) | RA-91 — TB13C census reviewed: RP-01 owns 30 of the 497; 8 new REDs since R3; retained-package bisect next (20 |
| [`Architecture_M6_CP3_TB13D_Bisect_Review_Decision.md`](#architecture_m6_cp3_tb13d_bisect_review_decisionmd) | RA-92 — TB13D bisect reviewed: none of the 8 new REDs is a production regression; curved-disk control restored |
| [`Architecture_M6_CP3_TB13_Chain_Interval_Review_Decision.md`](#architecture_m6_cp3_tb13_chain_interval_review_decisionmd) | RA-88 — TB13 reviewed: the RED truth-table row is a Review specification defect; U3 code accepted; CB13A corre |
| [`Architecture_M6_CP3_TB14A_Curved_Disk_Control_Review_Decision.md`](#architecture_m6_cp3_tb14a_curved_disk_control_review_decisionmd) | RA-94 — TB14A reviewed: curved-disk control restored (425/497); 199 is a hidden fixture repair; DEFN-U6 next ( |
| [`Architecture_M6_CP3_TB16C_Census_U4_Review_Decision.md`](#architecture_m6_cp3_tb16c_census_u4_review_decisionmd) | RA-102 — TB16C reviewed: B3 cleared on all 19; RP-01 has one blocker shape (I–R at rail vertex 4); CB17 (U4) s |
| [`Architecture_M6_CP3_TB17_Rail_Vertex_U5_Review_Decision.md`](#architecture_m6_cp3_tb17_rail_vertex_u5_review_decisionmd) | RA-103 — TB17 reviewed: CB17 (U4) accepted; CB18 (U5, consumer emits R) and TB18 specified (2026-10-19) |
| [`Architecture_M6_CP3_TB18_REV_Factory_Rejection_Review_Decision.md`](#architecture_m6_cp3_tb18_rev_factory_rejection_review_decisionmd) | RA-105 — TB18-REV reviewed: measurements confirmed; RA-104 corrected; RP-01 realigned to the checked-factory r |
| [`Architecture_M6_CP3_TB19_Closeout_Review_Decision.md`](#architecture_m6_cp3_tb19_closeout_review_decisionmd) | RA-109 — TB19 harvest report accepted; TB19 closed by Review; TB19A gains a static edge classification (2026-1 |
| [`Architecture_M6_CP3_TB19_REV_Gauge_Pin_Domain_Review_Decision.md`](#architecture_m6_cp3_tb19_rev_gauge_pin_domain_review_decisionmd) | RA-110 — TB19-REV: TB19A accepted; H-pin confirmed as a producer/factory gauge-domain mismatch; DEFN-P1 ordere |
| [`Architecture_M6_CP3_TB19_Torus_Staging_Review_Decision.md`](#architecture_m6_cp3_tb19_torus_staging_review_decisionmd) | RA-108 — TB19 run read: torus rows unmeasured (fixture staging); TB19 closes on 16 valid rows; TB19A reruns th |
| [`Architecture_M6_CP3_TB1_Entry_R1_Review_Record.md`](#architecture_m6_cp3_tb1_entry_r1_review_recordmd) | M6-CP3-TB1-ENTRY-R1-REV — Independent Review Record |
| [`Architecture_M6_CP3_TB1_Entry_R2_Review_Record.md`](#architecture_m6_cp3_tb1_entry_r2_review_recordmd) | M6-CP3-TB1-ENTRY-R2-REV — Independent Review |
| [`Architecture_M6_CP3_TB20_Gauge_Pin_Domain_Review_Decision.md`](#architecture_m6_cp3_tb20_gauge_pin_domain_review_decisionmd) | RA-114 — TB20 reviewed: corrected pin confirmed at runtime; M2 cleared at the factory; selector-497 census nex |
| [`Architecture_M6_CP3_TB21_Selector_497_Census_Review_Decision.md`](#architecture_m6_cp3_tb21_selector_497_census_review_decisionmd) | RA-115 — TB21 reviewed: CB20/CB20A regression-free on the 497 selector; torus rows reclassified as a fixture-s |
| [`Architecture_M6_CP3_TB22_Torus_Witness_Harvest_Review_Decision.md`](#architecture_m6_cp3_tb22_torus_witness_harvest_review_decisionmd) | RA-117 — TB22 reviewed: fixture selection fixed; five CP2 torus rows split into a fixture atlas defect and an  |
| [`Architecture_M6_CP3_TB23_Torus_A5_Site_Harvest_Review_Decision.md`](#architecture_m6_cp3_tb23_torus_a5_site_harvest_review_decisionmd) | RA-121 — TB23 reviewed: one site owns all ten torus A5 rows; the occurrence chart face disagrees with its own  |
| [`Architecture_M6_CP3_CB19A_Factory_Rejection_Site_Code_Build_Record_20261020.md`](#architecture_m6_cp3_cb19a_factory_rejection_site_code_build_record_20261020md) | M6 CP3 CB19A — factory rejection-site corrective Code + Build (2026-10-20) |
| [`Architecture_M6_CP3_CB19_Factory_Rejection_Site_Compile_Failure_20261020.md`](#architecture_m6_cp3_cb19_factory_rejection_site_compile_failure_20261020md) | CB19 — Factory rejection-site diagnostic: compile failure (2026-10-20) |
| [`Architecture_M6_CP3_CB20_Gauge_Pin_Domain_Code_Build_Stop_Record_20261020.md`](#architecture_m6_cp3_cb20_gauge_pin_domain_code_build_stop_record_20261020md) | M6 CP3 CB20 — gauge-pin domain Code + Build STOP (2026-10-20) |
| [`Architecture_M6_CP3_DEFN_P1_Gauge_Pin_Domain_Definition_Record_20261020.md`](#architecture_m6_cp3_defn_p1_gauge_pin_domain_definition_record_20261020md) | M6 CP3 DEFN-P1 — gauge-pin domain, source-only definition (2026-10-20) |
| [`Architecture_M6_CP3_TB18_Rail_Vertex_Endpoint_Independent_Review_20261020.md`](#architecture_m6_cp3_tb18_rail_vertex_endpoint_independent_review_20261020md) | TB18 independent review — evidence adjudicated with real history (2026-10-20) |
| [`Architecture_M6_CP3_TB19A_Torus_Rejection_Site_Harvest_Report_20261020.md`](#architecture_m6_cp3_tb19a_torus_rejection_site_harvest_report_20261020md) | M6-CP3 TB19A — Torus factory-rejection-site artifact-only harvest (2026-10-20) |
| [`Architecture_M6_CP3_TB19_Factory_Rejection_Site_Harvest_Report_20261020.md`](#architecture_m6_cp3_tb19_factory_rejection_site_harvest_report_20261020md) | M6-CP3-TB19 Factory Rejection-Site Harvest Report (2026-10-20) |
| [`Architecture_M6_CP3_CB21_Torus_Witness_Scope_Review_Decision_20261021.md`](#architecture_m6_cp3_cb21_torus_witness_scope_review_decision_20261021md) | RA-116 — CB21 torus witness scope, independent Review (2026-10-21) |
| [`Architecture_M6_CP3_DEFN_ISO_A_Seam_Node_Representative_Census_Review_Decision_20261021.md`](#architecture_m6_cp3_defn_iso_a_seam_node_representative_census_review_decision_20261021md) | RA-124 — DEFN-ISO-A census review: the seam contract does not fit the shared-node producers (2026-10-21) |
| [`Architecture_M6_CP3_TB22_Torus_Witness_Harvest_Plan_20261021.md`](#architecture_m6_cp3_tb22_torus_witness_harvest_plan_20261021md) | TB22 — Immutable torus witness-scope harvest plan (RA-116) |
| [`Architecture_M6_CP3_TB23_Torus_A5_Site_Harvest_Plan_20261021.md`](#architecture_m6_cp3_tb23_torus_a5_site_harvest_plan_20261021md) | TB23 — Torus A5 isolation-site harvest plan (RA-120) |
| [`Architecture_M6_CP3_TB24_Torus_A5_Seam_Face_Harvest_Review_Decision_20261021.md`](#architecture_m6_cp3_tb24_torus_a5_seam_face_harvest_review_decision_20261021md) | RA-123 — TB24 seam-face harvest review (2026-10-21) |
| [`Architecture_M6_CP3_CB27A_Wedge_Membership_Witness_Design_Review_Decision_20261022.md`](#architecture_m6_cp3_cb27a_wedge_membership_witness_design_review_decision_20261022md) | RA-135 — CB27A design block resolved: isolate wedge membership by withdrawing a real binding from the multi-bi |
| [`Architecture_M6_CP3_CB27_A7_Certified_Seam_Negative_Oracles_Review_Decision_20261022.md`](#architecture_m6_cp3_cb27_a7_certified_seam_negative_oracles_review_decision_20261022md) | CB27-REV — independent A7 certified-seam negative-oracle review (2026-10-22) |
| [`Architecture_M6_CP3_CB28_Factory_Error_Diagnostics_Review_Decision_20261022.md`](#architecture_m6_cp3_cb28_factory_error_diagnostics_review_decision_20261022md) | RA-136 — CB28 review: diagnostics accepted for 18 of 21 silent REDs; three M1/A5 asserts missed; CB28A before  |
| [`Architecture_M6_CP3_DEFN_SEAM_A5_Shared_Node_Side_Authority_20261022.md`](#architecture_m6_cp3_defn_seam_a5_shared_node_side_authority_20261022md) | DEFN-SEAM — A5 certified-seam shared-node side authority (2026-10-22) |
| [`Architecture_M6_CP3_DEFN_SEAM_A5_Shared_Node_Side_Authority_Review_Decision_20261022.md`](#architecture_m6_cp3_defn_seam_a5_shared_node_side_authority_review_decision_20261022md) | RA-127 — DEFN-SEAM review: accepted with two binding amendments; CB25 authorized (2026-10-22) |
| [`Architecture_M6_CP3_DEFN_SEAM_A7_Certified_Seam_Cross_Sheet_Authority_20261022.md`](#architecture_m6_cp3_defn_seam_a7_certified_seam_cross_sheet_authority_20261022md) | DEFN-SEAM-A7 — certified cross-sheet OrdinaryFront authority (2026-10-22) |
| [`Architecture_M6_CP3_DEFN_SEAM_A7_Certified_Seam_Cross_Sheet_Authority_Review_Decision_20261022.md`](#architecture_m6_cp3_defn_seam_a7_certified_seam_cross_sheet_authority_review_decision_20261022md) | RA-130 — DEFN-SEAM-A7 review: accepted with binding amendments; CB26 authorized (2026-10-22) |
| [`Architecture_M6_CP3_TB25_Seam_Frame_Values_Harvest_Review_Decision_20261022.md`](#architecture_m6_cp3_tb25_seam_frame_values_harvest_review_decision_20261022md) | RA-126 — TB25 seam frame-values review: the identity-turn branch; DEFN-SEAM narrowed to A5 shared-node side au |
| [`Architecture_M6_CP3_TB26_Shared_Node_Seam_Witness_Harvest_Review_Decision_20261022.md`](#architecture_m6_cp3_tb26_shared_node_seam_witness_harvest_review_decision_20261022md) | RA-129 — TB26 review: A5 and A6 now admit the shared-node seam; A7's cross-sheet rule is the next blocker (202 |
| [`Architecture_M6_CP3_TB27_A7_Certified_Seam_Cross_Sheet_Verification_Review_Decision_20261022.md`](#architecture_m6_cp3_tb27_a7_certified_seam_cross_sheet_verification_review_decision_20261022md) | RA-132 — TB27 review: the seam family and both tamper falsifiers pass; census next, before more tests (2026-10 |
| [`Architecture_M6_CP3_TB28_Census_Review_Audit_Decision_20261022.md`](#architecture_m6_cp3_tb28_census_review_audit_decision_20261022md) | RA-134 — Audit of the TB28 review (RA-133): evidence and CB27 upheld; RED partition corrected; typed-reason ha |
| [`Architecture_M6_CP3_TB28_Selector_497_Census_Review_Decision_20261022.md`](#architecture_m6_cp3_tb28_selector_497_census_review_decision_20261022md) | TB28 independent Review — RA-133 (2026-10-22) |
| [`Architecture_M6_CP3_DEFN_M1_Certificate_Pair_Binding_Precedence_20261023.md`](#architecture_m6_cp3_defn_m1_certificate_pair_binding_precedence_20261023md) | DEFN-M1 — hard-rail certificate/consumer rejection precedence (2026-10-23) |
| [`Architecture_M6_CP3_DEFN_M1_Certificate_Pair_Binding_Precedence_Review_Decision_20261023.md`](#architecture_m6_cp3_defn_m1_certificate_pair_binding_precedence_review_decision_20261023md) | RA-143 — DEFN-M1 architecture block resolved: A4 authenticates hard-rail certificates; A5 binds edges to them  |
| [`Architecture_M6_CP3_TB29H_RP02_Review_Audit_Decision_20261023.md`](#architecture_m6_cp3_tb29h_rp02_review_audit_decision_20261023md) | RA-140 — Audit of the RP02 harness review: acceptance upheld and validated on real GoogleTest logs; TB29 relea |
| [`Architecture_M6_CP3_TB29H_Review_Audit_Decision_20261023.md`](#architecture_m6_cp3_tb29h_review_audit_decision_20261023md) | RA-139 — Audit of the TB29H review (RA-138): H1–H3 upheld; three further harness defects; built-in self-test r |
| [`Architecture_M6_CP3_TB29H_Targeted_Harness_Review_Decision_20261023.md`](#architecture_m6_cp3_tb29h_targeted_harness_review_decision_20261023md) | RA-138 — TB29H targeted artifact harness independent review (2026-10-23) |
| [`Architecture_M6_CP3_TB29_Harness_Authorization_Design_Review_Decision_20261023.md`](#architecture_m6_cp3_tb29_harness_authorization_design_review_decision_20261023md) | RA-137 — TB29 block resolved: Review owns the case manifest; one reusable targeted harness (TB29H) before TB29 |
| [`Architecture_M6_CP3_TB29_Review_Audit_Decision_20261023.md`](#architecture_m6_cp3_tb29_review_audit_decision_20261023md) | RA-142 — Audit of the TB29 review (RA-141): evidence upheld; M1 is ten rows (six measured, four proven statica |
| [`Architecture_M6_CP3_TB29_Typed_Factory_Cause_Harvest_Review_Decision_20261023.md`](#architecture_m6_cp3_tb29_typed_factory_cause_harvest_review_decision_20261023md) | RA-141 — Independent TB29 typed-failure review (2026-10-23) |
| [`Architecture_M6_CP3_TB30_Certificate_Association_Ownership_Verification_Review_Decision_20261023.md`](#architecture_m6_cp3_tb30_certificate_association_ownership_verification_review_decision_20261023md) | RA-144 — TB30 review: M1 resolved (10/10) on the targeted gate; full census before any further fix (2026-10-23 |
| [`Architecture_M6_CP3_TB33_Odd_Atlas_Oracle_Verification_Review_Decision_20261024.md`](#architecture_m6_cp3_tb33_odd_atlas_oracle_verification_review_decision_20261024md) | RA-149 — TB33 review: odd-atlas oracles accepted (synthetic scope); realign onto the 19 residual REDs, largest |
| [`Architecture_M6_CP3_TB34_REV_Audit_Face_Gauge_Representation_Decision_20261024.md`](#architecture_m6_cp3_tb34_rev_audit_face_gauge_representation_decision_20261024md) | RA-150 — TB34-REV audit: periodic-route fixture is a face gauge, not a transition edit (2026-10-24) |
| [`Architecture_M6_CP3_TB35_REV_Audit_Periodic_Route_Transport_Decision_20261024.md`](#architecture_m6_cp3_tb35_rev_audit_periodic_route_transport_decision_20261024md) | RA-152 — TB35-REV audit: the A4 periodic rotation guard is dead on the atlas path (2026-10-24) |
| [`Architecture_M6_CP3_TB36_REV_Audit_Periodic_Route_Atlas_Transport_Decision_20261025.md`](#architecture_m6_cp3_tb36_rev_audit_periodic_route_atlas_transport_decision_20261025md) | RA-153 — TB36-REV audit: D2 authorized as specified; RA-152 errata; TB37 split (2026-10-25) |
| [`Architecture_M6_CP3_TB37_REV_Audit_Periodic_Census_Manifest_Decision_20261025.md`](#architecture_m6_cp3_tb37_rev_audit_periodic_census_manifest_decision_20261025md) | RA-154 — TB37-REV audit; Review-owned TB38 census manifest (2026-10-25) |
| [`Architecture_M6_CP3_TB38_REV_Audit_Tamper_Oracle_Homes_Decision_20261025.md`](#architecture_m6_cp3_tb38_rev_audit_tamper_oracle_homes_decision_20261025md) | RA-155 — TB38-REV audit; tamper-oracle homes bound; 250 site first (2026-10-25) |
| [`Architecture_M6_CP3_TB39_REV_Audit_Selector250_Rail_Provenance_Decision_20261025.md`](#architecture_m6_cp3_tb39_rev_audit_selector250_rail_provenance_decision_20261025md) | RA-156 — TB39-REV audit: selector250 rail-authority owner bound and promoted (2026-10-25) |
| [`Architecture_M6_CP3_TB40_REV_Audit_CB39_A3_Tamper_Spec_Decision_20261025.md`](#architecture_m6_cp3_tb40_rev_audit_cb39_a3_tamper_spec_decision_20261025md) | RA-157 — TB40-REV audit: 250 discharge confirmed; CB39 spec re-bound (2026-10-25) |
| [`Architecture_M6_CP3_DEFN_Legacy_Matching_Path_Disposition_Review_Decision_20261026.md`](#architecture_m6_cp3_defn_legacy_matching_path_disposition_review_decision_20261026md) | RA-160 — Legacy matching-path DEFN Review: 190 re-home amended; O2 production CB withdrawn (2026-10-26) |
| [`Architecture_M6_CP3_DEFN_Selector242_Seam_Consumer_Review_Decision_20261026.md`](#architecture_m6_cp3_defn_selector242_seam_consumer_review_decision_20261026md) | RA-163 — selector242 DEFN Review: D1 missed the typed owner, D2 decided statically, Branch B rejected (2026-10 |
| [`Architecture_M6_CP3_TB41_REV_Audit_O3_Owner_And_DEFN_Split_Decision_20261026.md`](#architecture_m6_cp3_tb41_rev_audit_o3_owner_and_defn_split_decision_20261026md) | RA-158 — TB41-REV audit: O3 owner, DEFN split, off-selector coverage gap (2026-10-26) |
| [`Architecture_M6_CP3_TB42_REV_Audit_Selector190_Vacuity_And_DEFN_Spec_Decision_20261026.md`](#architecture_m6_cp3_tb42_rev_audit_selector190_vacuity_and_defn_spec_decision_20261026md) | RA-159 — TB42-REV audit: selector190 vacuity, legacy-path DEFN spec, O6 (2026-10-26) |
| [`Architecture_M6_CP3_TB43_REV_Audit_Selector405_Fixture_Provenance_Decision_20261026.md`](#architecture_m6_cp3_tb43_rev_audit_selector405_fixture_provenance_decision_20261026md) | RA-161 — TB43-REV audit; selector405 root-caused to fixture rail provenance; O4 demoted (2026-10-26) |
| [`Architecture_M6_CP3_TB44_REV_Audit_P1_Torn_Input_Selector242_Scope_Decision_20261026.md`](#architecture_m6_cp3_tb44_rev_audit_p1_torn_input_selector242_scope_decision_20261026md) | RA-162 — TB44-REV audit; P1-a remedy corrected (torn input); selector242 DEFN scoped (2026-10-26) |
| [`Architecture_M6_CP3_TB45_REV_Audit_Rail_Oracle_Triage_Cadence_Realignment_Decision_20261027.md`](#architecture_m6_cp3_tb45_rev_audit_rail_oracle_triage_cadence_realignment_decision_20261027md) | RA-164 — TB45-REV audit; 174 and cp3entry:4 decided statically; RED clusters; CP3 cadence realigned (2026-10-2 |
| [`Architecture_M6_CP3_DEFN_RP01_Off_Selector_Coverage_Working_Inventory_20261029.md`](#architecture_m6_cp3_defn_rp01_off_selector_coverage_working_inventory_20261029md) | Off-selector census: independently re-derived first-failure inventory (working DEFN evidence) |
| [`Architecture_M6_CP3_TB53_REV_Local_Gate_Platform_Attribution_RP01_Closure_20261030.md`](#architecture_m6_cp3_tb53_rev_local_gate_platform_attribution_rp01_closure_20261030md) | RA-179 — TB53 review: platform attribution of the local reds and RP-01 closure (2026-10-30) |
| [`Architecture_M6_CP3_DEFN_O2_No_Atlas_Entry_Gate_20261031.md`](#architecture_m6_cp3_defn_o2_no_atlas_entry_gate_20261031md) | RA-183 — O2: no-atlas A4 ingress (2026-10-31) |
| [`Architecture_M6_CP3_TB54_REV_O15_Discharge_20261031.md`](#architecture_m6_cp3_tb54_rev_o15_discharge_20261031md) | RA-181 — TB54 review: O15 discharged (2026-10-31) |

## `Architecture_M6_CP3_CB19A_Factory_Rejection_Site_Review_Decision.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_CB19A_Factory_Rejection_Site_Review_Decision.md`; moved verbatim.

### RA-107 — CB19A accepted; TB19 specified exactly (2026-10-20)

**Turn:** `M6-CP3-CB19A-RP01-FACTORY-REJECTION-SITE-REV`. **Inputs:**
- CB19A source `d2c7483cd`;
- compile run `39446712217` at `513f944c5`, whose src/include/tests/CMake are identical to `d2c7483cd`;
- package `12275794192`;
- record `Architecture_M6_CP3_CB19A_Factory_Rejection_Site_Code_Build_Record_20261020.md`.

**Base:** `3bd24682c`. **TQ** = `tests/SurfaceCellTransitionQuotientTests.cpp`. **Amends:** RA-105.6 and RA-106.5, which this record replaces as the TB19 specification.

#### RA-107.1 CB19A accepted

- **Package.** The provider digest `sha256:e4a39cdb…d723a` matches the record. The run concluded `success`. The package expires **2026-10-27T15:24Z**.
- **Diff against `3bd24682c`:**
  - header +2/−0;
  - S +73/−0, so `make` is insertions only;
  - TQ +60/−1. The one removed line is the authorized TQ:4980 assertion.
- **Labels.**
  - All 47 labels match CB19's, one by one, in both clause name and suffix kind: 19 plain, 2 pin, 9 certificate, 9 endpoint and 8 junction.
  - Every `InvalidSourceAuthority` return is still labelled.
  - The three lambdas are as RA-106.3 gives them.
  - No line of `make` is longer than 100 columns.
- **Test.** The new test now requires both edge vertices to be corners of face 0, as RA-106.4 requires.
- **Not re-derived here.** The 28/28 packaged hashes are the agent's claim. The TB19 harness re-verifies them before it executes anything.

#### RA-107.2 Defects in the TB19 specification, corrected before it runs

1. **Line drift.** Several M1 first failures cite TQ line numbers, and CB19/CB19A shifted TQ. RA-105.6's "byte-identical to TB18" would therefore fire on every one of them.
   - Mapping from a base line L to its CB19A line:

     | Base TQ line L | CB19A line |
     |---|---|
     | ≤ 441 | L |
     | 442–1880 | L + 11 |
     | 1881–4979 | L + 53 |
     | 4980 | the rewritten assertion |
     | ≥ 4981 | L + 59 |

   - First failures that are exception text stay byte-identical.
2. **Duplicate identity.** `selector:217` is the same gtest as TB18 Part A #12. It runs once.
3. **Harness.** The TB18 Part A harness hard-codes its package, source and 14 tests. TB19 authors one new harness derived from it (RA-86 precedent); see RA-107.3.
4. **M1 is a no-regression check, not a site measurement.** The M1 assertions do not stream the site. M1 rests on the RA-105.3 static proof.
5. **`focused30:12` made exact.** `hard_rail_fixture()` has rail carriers (1,4) and (4,7), and these are its only cross-region interior edges. Its relabelled region can fail the pin only there.
6. **Expiry.** TB19 must run before the package expires. If it has expired, STOP; there is no rebuild inside TB19.

#### RA-107.3 TB19 — `M6-CP3-TB19-RP01-FACTORY-REJECTION-SITE` (artifact-only)

##### Harness

> **Amended by RA-108.2 and RA-108.5:** the template stages fixtures one level too high, so the six torus rows were not measured. TB19A reruns them with the staging fixed.

- **File:** new `.agents/Directional/tools/m6_cp3_tb19_factory_rejection_site_harness.sh`, a copy of `open_rail_interior_vertex_harness.sh` changed only as follows:
  - **pinned inputs:**
    - source `d2c7483cde8e65d6c35c5df06fa880465a4da46c`;
    - artifact `12275794192`;
    - digest `e4a39cdb2db5ef9953748cffd3e031e4294ddaf348f4a64fee3b97e08bdd723a`;
  - **test list:** the 22 rows below, with group and identity labels;
  - **extraction:** pull `product=`, `detail=` and `site=` from each raw log into the ledger, alongside the RA-90.4 first failure.
- **Unchanged from the Part A harness:**
  - the package and manifest checks (28);
  - the frozen-selector hashes;
  - the GMP and `runtimeExecution=false` checks;
  - the one-test-per-filter `GTEST_FAIL_IF_NO_TEST_SELECTED=1` execution;
  - the postflight immutability check.
- **Executable:** all 22 run in `directional_surface_cell_producer_tests`, per the selector-449 routing receipt and the TQ/P10 target.

##### Identities

| # | Group | Identity | gtest | TB18 | Prediction |
|---|---|---|---|---|---|
| 1 | M2 | `cp3entry:1` | `M6CP3.PeriodicExactA3UnequalFaceGaugeUsesRelationAndOccurrenceAuthority` | RED | RED; `product=0 detail=none site=gauge-pin-consistency;edge=…` |
| 2 | M2 | `cp3entry:2` | `M6CP3.HardRailCrossRegionBranchCertificateStripsEndpointFaceGauge` | RED | RED; record product, detail and site (no prediction) |
| 3 | M2 | `cp3entry:6` | `M6CP3.HardRailCrossRegionBindingDoesNotCompareGlobalSheetLabels` | RED | RED; record (no prediction) |
| 4 | M2 | `focused30:6` | `M5CP3.ProducedTorusPeriodicPairStorageSwapPreservesSemanticDirection` | RED | RED; as #1 |
| 5 | M2 | `focused30:12` | `M6CP1.RelationPlacementTransportIsCoordinateRigidAndFaceGaugeInvariant` | RED | RED; `product=0 site=gauge-pin-consistency;edge=1,4` or `edge=4,7` |
| 6 | M2 | `focused30:20` | `M6CP1.NonzeroZ4WitnessPassesProductionCompletionOwnership` | RED | RED; as #1 |
| 7 | M2 | `focused30:24` | `M6CP1.ThinAdapterOutputIsPureProjectionOfStageProducts` | RED | RED; as #1 |
| 8 | M2 | `selector:446` | `M5CP3.ProducedTorusNonzeroZ4RotationTranslationMaterializes` | RED | RED; as #1 |
| 9 | M2 | `selector:447` | `M5CP3.ProducedTorusTamperedNonzeroZ4TransformRejectsTyped` | RED | RED; as #1 |
| 10 | M1 | `focused30:3` | `M6CP1.SurfaceOccurrenceComplexRejectsMalformedMissingAndDuplicateRelationEndpoints` | RED | RED; TB18 exception text, identical |
| 11 | M1 | `focused30:22` | `M6CP1.A5OwnsIsolationAndHardRailRouteValidationWithFrozenNames` | RED | RED; TQ:5769 → 5828 |
| 12 | M1 | `focused30:23` | `M6CP1.A5ValidationPrecedencePreservesHardRailAuthorityBeforeTransport` | RED | RED; TQ:5810 → 5869 |
| 13 | M1 | `selector:139` | `SurfaceCellAuthorityContractCutover.HardRailPairChangedRouteContentRejectsStrictTransport` | RED | RED; identical exception |
| 14 | M1 | `selector:140` | `SurfaceCellAuthorityContractCutover.HardRailPairExplicitRailIdMismatchRejectsStrictTransport` | RED | RED; identical exception |
| 15 | M1 | `selector:142` | `SurfaceCellAuthorityContractCutover.HardRailPairSameOrientationRejectsStrictTransport` | RED | RED; identical exception |
| 16 | M1 | `selector:211` | `SurfaceCellTransitionQuotient.AmbiguousHardRailCounterpartIsRejected` | RED | RED; TQ:8541 → 8600 |
| 17 | M1 | `selector:219` | `SurfaceCellTransitionQuotient.MissingHardRailCounterpartIsRejected` | RED | RED; TQ:8520 → 8579 |
| 18 | M1 | `selector:227` | `SurfaceCellTypedTransportAuthority.DuplicateSemanticRouteTopologyFailsClosed` | RED | RED; TQ:9663 → 9722 |
| 19 | M1 | `selector:230` | `SurfaceCellTypedTransportAuthority.RouteTopologyTransitionMismatchFailsClosed` | RED | RED; TQ:9643 → 9702 |
| 20 | control | `selector:217` (= TB18 A#12) | `SurfaceCellTransitionQuotient.ExactHardRailCounterpartsStitchAcrossTopologyRegions` | PASS | PASS |
| 21 | control | TB18 A#14 | `SurfaceCellAuthorityContractCutover.ProducedOpenRailInteriorVertexEndpointRejectsForgedTags` | PASS | PASS |
| 22 | control | new | `SurfaceCellFactoryRejectionSite.OneFaceGaugePinNamesSourceEdge` | — | PASS |

TB18 first failures come from `Architecture_M6_CP3_TB18_Selector_497_Red_Inventory.tsv`.

##### Falsifiers, and what is not one

**Falsifiers.** Report each as held or fired:
- **F1** — any status that differs from the table.
- **F2** — `PublishedProductRejected` with `product=0` and an empty site.
- **F3** — a torus site (#1, #4, #6–#9) that is not `gauge-pin-consistency`. Or `focused30:12` whose site is not that label, or whose edge is not (1,4)/(4,7).
- **F4** — an M1 first failure that differs from TB18 after the RA-107.2 mapping.

**RA-103.5 R-route falsifier.** It fires if `cp3entry:2` or `cp3entry:6` reports an `endpoint-*` site with `kind=R`. Record the site verbatim.

**Not falsifiers:**
- a non-zero `product=` on `cp3entry:2/6`. Record it; TB19-REV decides any follow-up under RA-106.5;
- differences in pointer addresses.

##### Boundary and output

- **Allowed:** the new harness file and its dispatch only.
- **Forbidden:**
  - compiling or relinking;
  - changing source, tests, selectors or fixtures;
  - benchmarks;
  - test discovery beyond the per-filter selection;
  - any repair.
- **Output:** a report `Architecture_M6_CP3_TB19_Factory_Rejection_Site_Harvest_Report_<date>.md` containing:
  - the run, the artifact and the ZIP SHA-256;
  - manifest counts;
  - a 22-row ledger with TB18 status, TB19 status, mapped first failure, product, detail, site and raw-log SHA;
  - a held/fired line for each falsifier.
- **No adjudication.** The report draws no conclusions on H-pin or on the R-route; TB19-REV decides those.
- **STOP:** any harness verification failure, an expired package, or fewer than 22 identities selected. Preserve the evidence and return to Review.

#### RA-107.4 Sequence and accounting

- **Sequence:** TB19 → TB19-REV (mandatory; rules on H-pin, on the `cp3entry:2/6` clause and on the RA-103.5 R-route falsifier, and orders the DEFN) → [DEFN on the gauge-pin domain and the M1 binding owner → corrective CB/TB] → fixture debt → census → RP-01 Review.
- **Accounting is unchanged:**
  - 66/17/49, debt 1;
  - CP2 491/491;
  - R3 403/497 rejected;
  - TB18 candidate 448/497;
  - selector 497.

  `RP-01` is open, `RP-02` is UNREACHED and Gate C is suspended.

## `Architecture_M6_CP3_CB19_Factory_Rejection_Site_Compile_Review_Decision.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_CB19_Factory_Rejection_Site_Compile_Review_Decision.md`; moved verbatim.

### RA-106 — CB19 compile failure reviewed: diagnostic design stands; corrective CB19A authorized (2026-10-20)

**Turn:** `M6-CP3-CB19-RP01-FACTORY-REJECTION-SITE-REV`. **Inputs:**
- CB19 semantic commit `1f73d0abd`;
- compile run `39428435345`, artifact `12265949093`, which failed in the `directional_core` preflight;
- record `Architecture_M6_CP3_CB19_Factory_Rejection_Site_Compile_Failure_20261020.md`.

**Base:** `3bd24682c`, whose src/include/tests are identical to `2a02d3b8e`. S and TQ lines are at HEAD `7c207ea75`. **Amends:** RA-105.6 (one falsifier) and RA-105.5 item 5 (one assertion).

#### RA-106.1 Static verification of the CB19 patch

- **Diff against the base:**
  - header +2/−0;
  - S +49/−0;
  - TQ +59/−1. The one removed line is the authorized TQ:4980 `ASSERT_NE`.
  - No other source path changed.
- **Labels are complete.** All 77 `return error;` in `make` (S:8439–9577) were mapped to their codes:
  - 47 are `InvalidSourceAuthority`, each with exactly one label, and all 47 labels are unique;
  - the other 30 set an explicit non-zero code, so none returns the default code 0 unlabelled;
  - none of the static falsifiers in RA-105.5 item 7 fired.
- **Failure struct.** S:13146 copies the site, and both new members are last. Neither struct has an equality operator or a serializer.
- **Reporting reaches every M2 identity.** All nine fail through a path that now prints the site:
  - `require_produced` at TQ:862 (rectangle: `cp3entry:2/6`);
  - `require_produced` at TQ:1672 (torus: `cp3entry:1`, `focused30:6/20/24`, `selector:446/447`);
  - TQ:4980 (`focused30:12`).
- **Selectors.** No selector file contains a wildcard, so `SurfaceCellFactoryRejectionSite` is outside every frozen selector.

#### RA-106.2 The compile failure: cause, extent, and what it could hide

- **Cause, confirmed.** 28 labels begin `"<literal>" + ";…"`, which is `const char[N] + const char[M]` and is ill-formed. They are 2 pin, 9 certificate, 9 endpoint and 8 junction labels. The other 19 labels are plain literals.
- **No second defect is masked.** Every other name in those expressions resolves (C++20):
  - `endpointIndex` (S:8900) and `junctionIndex` (S:9033);
  - `SemanticId::index()` for `HardRailId` and `SourceVertexId`, and `SourceEdgeTopologyKey::first()/second()`;
  - `std::vector::data()`, `std::optional` in `&&`, and the `const char*` ternary.
- **The TQ changes have never been compiled.** The build stopped before any test target. Their helpers were checked statically:
  - `hard_rail_fixture` TQ:782;
  - `phase_front_draft` TQ:1844;
  - `construct_phase_front_product` TQ:1861;
  - `test_source_edge_topology` TQ:74.

  Only the eight-target build can accept them.
- **Verdict: this is an implementation defect, not a design or architecture block.** The RA-105.5 label set, format and insertion points stand. CB19's diagnostic is still the right next step for RP-01: TB19 cannot rule on H-pin or `cp3entry:2/6` without it.

#### RA-106.3 Required correction: one suffix definition per scope, not 26 copies

The record's proposed fix, a `std::string` leftmost operand on each line, would compile. It is not accepted:
- it keeps 26 copies of an expression up to 412 columns wide that encodes the same certificate, endpoint and junction suffix;
- that breaks the file's wrapping idiom: no line of `make` before CB19 is longer than 100 columns;
- the label format would live in 26 places that can drift apart without any error.

Required instead. Every change below is a new line, so the `make` diff against `3bd24682c` stays insertions-only.

1. Add as the first statement of the certificate loop body (after S:8776):
   ```cpp
       const auto certificate_site = [&](const char *clause) {
         return std::string(clause) + ";certificate=" +
                std::to_string(static_cast<std::size_t>(
                    &certificate - hardRailRouteCertificates.data())) +
                ";rail=" + std::to_string(certificate.rail.index());
       };
   ```
2. Add after `const auto &endpoint = certificate.endpoints[endpointIndex];` (S:8901):
   ```cpp
         const auto endpoint_site = [&](const char *clause) {
           return certificate_site(clause) + ";endpoint=" +
                  std::to_string(endpointIndex) + ";kind=" +
                  (endpoint.terminalVertex && endpoint.railVertex ? "TR"
                   : endpoint.terminalVertex                      ? "T"
                   : endpoint.railVertex                          ? "R"
                                                                  : "I");
         };
   ```
3. Add after `const auto &junction = certificate.junctions[junctionIndex];` (S:9035):
   ```cpp
         const auto junction_site = [&](const char *clause) {
           return certificate_site(clause) + ";junction=" +
                  std::to_string(junctionIndex);
         };
   ```
4. Rewrite each of the 26 scoped labels as `error.sourceAuthoritySite = certificate_site("<clause>");`, using `endpoint_site` or `junction_site` in their scopes, with the same clause strings.
5. The two pin labels become `std::string("gauge-pin-<clause>;edge=") + std::to_string(edge.first().index()) + "," + std::to_string(edge.second().index())`, wrapped to the file's width.
6. The 19 plain labels are unchanged.
7. Every produced label string must be byte-identical to the label CB19 intended.

#### RA-106.4 Test correction (new test, TQ:1892)

- **Weak check.** The incidence check accepts an edge with only one vertex on face 0. For example, edge (1,2) would pass.
- **Required.** Both edge vertices must be corners of `fixture.mesh.F.row(0)`. Nothing else in the test changes.
- **Static basis:**
  - face 0 = (0,1,4) and face 1 = (0,4,3) share the intra-region edge (0,4);
  - (1,4) is the rail carrier between faces 0 and 3;
  - the baseline passes the pin;
  - a +1 (mod 4) change to face 0 alters `compose(T, g_first) == g_second` only on face 0's two-face edges. The first rejected edge must therefore be (0,4) or (1,4), and the stronger assertion is not flaky.

#### RA-106.5 TB19 falsifier amended (RA-105.6)

- **The falsifier is wrong by construction.** RA-105.6 lists "a `PublishedProductRejected` with an empty site" as a falsifier, but only the 47 `InvalidSourceAuthority` returns carry a site.
- **Amended falsifier:** `product=0` with an empty site.
- **A non-zero `product=` is a recorded result,** not a falsifier.
- **Codes with several returns.** Five non-zero codes cannot be told apart by code alone:
  - `NonReciprocalPeriodicRelation` (6 returns);
  - `RepresentationRenumberedPeriodicRelation` (3);
  - `InvalidSharedBoundaryInterval` (3);
  - `MissingPeriodicRelationOwner` (2);
  - `InvalidPeriodicRelationOwner` (2).

  If `cp3entry:2` or `cp3entry:6` reports one of them, TB19-REV orders a separate site follow-up for that code only. Nothing is labelled for them now.

#### RA-106.6 Next unit — `M6-CP3-CB19A-RP01-FACTORY-REJECTION-SITE` (Code + Build, compile only)

- **Scope:** RA-106.3 in S and RA-106.4 in TQ, on top of `1f73d0abd`. Nothing else: no header change, no S:13146 change, no other test, selector, harness, fixture or `RemeshPipeline.cpp` change.
- **Static acceptance:**
  - against `3bd24682c`, the `make` diff is insertions only;
  - 47 labels, unique, byte-identical to CB19's;
  - no single line in `make` is longer than 100 columns.
- **Build:**
  - GMP/GMPXX, eight targets, package, `runtimeExecution=false`;
  - the CB19A record has the label → S-line table and supersedes CB19 as the build record. The CB19 failure record stays as evidence.
- **STOP:** any compile error. Record the first diagnostic of each distinct error and return to Review. There is no second repair inside the turn.
- **Carried:** CB19's staged transport file goes to the CB19A closeout.
- **On success:** TB19 under RA-105.6 as amended by RA-106.5, pinned to the CB19A package. TB19-REV remains mandatory.

#### RA-106.7 Sequence and accounting

> **Amended by RA-110.6 (2026-10-20):** sequence.

- **Sequence:** CB19A → TB19 → TB19-REV (mandatory) → [DEFN on the gauge-pin domain and the M1 binding owner → corrective CB/TB] → fixture debt → census → RP-01 Review.
- **Accounting is unchanged:**
  - 66/17/49, debt 1;
  - CP2 491/491;
  - R3 403/497 rejected;
  - TB18 candidate 448/497;
  - selector 497.

  `RP-01` is open, `RP-02` is UNREACHED and Gate C is suspended.

## `Architecture_M6_CP3_CB1_Entry_R2_Recovery_Code_Build_Plan.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_CB1_Entry_R2_Recovery_Code_Build_Plan.md`; moved verbatim.

### M6-CP3-CB1-ENTRY-R2 — Recovery Code + Build Plan (**RELEASED by R2 Review with mandatory stop gates**)

**Owner:** next Code + Build agent. **Independent `M6-DEFN-R5-R2-REV` accepts RA-34 and releases this plan with mandatory typed A4 and organic-witness preflight stops.** This is the *only* proposed R2 Code+Build plan. Entry reviewed R1 candidate was **482/497** and rejected. Current reviewed runtime baseline remains CP2 `11391685901 / 5ce3132e...`. Stable **63 / 17 / 46**, debt **1**.

> **R2 Review release — RA-34 ACCEPTED for bounded implementation, not runtime acceptance:** R1 Review rejected RA-33. The independent R2 Review releases this plan subject to its documented preflight stops. The implementation must prove one independently A4-certified typed Forward/Reverse match and bind its orientation to every seam conjunct; raw/global sheet labels may neither grant nor deny lookup and A4 must independently publish usable wedge-to-certificate sheet incidence. It must also require a real-produced baseline-green HardRail with both `F_b-F_a != τ_ab` and odd `τ_ab∈{1,3}` plus τ sign tamper. Unproven periodic, tracer-produced seam-collinear, and route-bearing ordinary positives retain stop rules. See `Architecture_M6_DEFN_R5_R2_CP3_Entry_Recovery_Definition_Record.md`. Only R2 Code+Build is released (compile-only), not CB2 or any runtime Test + Benchmark execution in this turn.

#### Preconditions (stop without source changes if false)

1. Read `Architecture_M6_DEFN_R5_R2_Review_Record.md` and accepted RA-34 in `Architecture_M6_Frozen_Definitions.md` (RA-33.2/.4/.5 carried), then this plan and `Architecture_M6_DEFN_R5_R1_CP3_Entry_Recovery_Definition_Record.md`. A Definition candidate alone is *not* release authority.
2. Independently prove the required organic periodic, HardRail and seam-collinear front witnesses, plus a route-bearing ordinary carrier, under Review-approved finite real-producer constructions. If Review did not approve an unresolved witness search, **stop for Review**, do not implement based on speculative positives.
3. Verify exact branch/snapshot authority and frozen selector identities. No unexpected drift of source, test or acceptance authority.

#### Narrow implementation sequence

**R2-P1 — A6 authority-domain fix; STOP before special seam behavior if an independent A4-owned wedge-to-certificate sheet/side mapping is missing or ambiguous.** In `src/pipeline/RemeshPipeline.cpp` OrdinaryFront section currently `:5391-5509`, select the certified seam branch only on full relation-owned matching certificate, reciprocal isolation evidence and source-face/sheet transitions. Global `sheet != sheet` is never a discriminator. Partial seam evidence is a typed rejection. Keep non-seam full equality, reciprocal branch, coordinates, scale, phase, source provenance and A7 strict cross-sheet validation. Negative: same source edge/unequal sheets but certificate for wrong region/face, no bypass; certified reciprocal positive; ordinary mismatch fails.

**R2-P2 — organic periodic D1 witness.** In `tests/SurfaceCellTransitionQuotientTests.cpp`, reuse the real nonzero-Z4 torus A1→A4 pipeline, enumerate canonical exact A3 source generators and every reciprocal tracer-produced Periodic pair instead of first-only `select_torus_source_witness`. Require gauge delta ±1 quarter turn, actual source/A3 face/cross-field transition reciprocity, matching interval and inverse route. Assert independent non-vacuity before original identity1 oracle. If empty, stop; no manual relation synthesis or fixture mutation to force the expected output.

**R2-P3 — publish and validate HardRail τ.** In A4 `SurfacePhaseFrontProduct` and A4 producer, expose minimally necessary oriented source-edge/from-face/to-face transition quarter turns, validated against A3 `FieldTransportAtlas::transition_value`, including hard-feature/nontraversable edges. In A5 consume this *published* evidence, not region-gauge deltas, and verify `B_b ◦ B_a⁻¹ = R_coord ◦ τ` for each endpoint of true HardRail relations, oriented reciprocal and path-independent around rail vertices. Fail typed at singularities/ambiguous paths. Avoid new public API configuration where one internal product field suffices; update direct A4 construction callers only as actually required. Keep existing identity2 name, coordinates, source provenance, typed hard-feature membership and identity6. Include a genuinely produced discriminant where `F_b−F_a != τ`; report all 4 values and compare withdrawn vs corrected predicate.

**R2-P4 — real seam-aligned tracer fixture.** Rework only the focused CP3 identity3/5 fixtures, not frozen selector/routing. Use the bounded axis-aligned seam geometry from RA-33, actual A4 tracer and A5. Verify a single reciprocal OrdinaryFront pair has full matching span/certificate and disjoint D7 sheets, A6 selection and A7 green. Distinct D3 A6 quarter-turn/reciprocal transition tamper and D7 A7 missing isolation evidence tamper; noncollinear control still strict. If no real-produced front aligns in bounded family, stop and report rather than hand-building A5 records.

**R2-P5 — ordinary carrier oracle.** Select actual route-bearing ordinary front (not merely `OrdinaryInterior`) from `A4::edges()` with eligible interior source carrier and live graph transition. Typed insertion of only that hard-feature edge must remove traversal at that carrier, with unrelated transition preserved. Independently retain PeriodicCut and HardRail authority negatives. If none exists in produced fixtures, bounded fixture expansion only with Review authorization; otherwise stop.

#### Verification and closeout

Code+Build turn: preflight tests may be *read/compiled*, not executed. Apply coherent changes as a verified exact-base Git patch using Google Drive File-ID transport; preserve downloadable work patch. Compile/package **eight** standard GMP/GMPXX targets via the durable dispatcher, `runtimeExecution=false`; no test, benchmark, generated discovery or local binary invocation. Do not change reusable workflow permissions. On successful package, hand off immutable exact-source artifact and checksum to one artifact-only `M6-CP3-TB1-ENTRY-R2-EXEC`, then mandatory `M6-CP3-TB1-ENTRY-R2-REV`.

**Frozen execution gate:** 497 processes = focused30 (30) + focused12 (12) + selector449 (449) + six CP3-entry identities (6); exact-one 497/497, no skips, benchmark zero, immutable pre/postflight, full manifest. No silent identity rename/reordering/selector update. Review all REDs; no CB2, optimizer/final-validator or production exit matrix until mandatory acceptance. Only after formal Review decide next successor. Maintain stable regression ledger **63 / 17 / 46**, debt **1** absent newly reviewed evidence.

## `Architecture_M6_CP3_CB20A_Gauge_Pin_Domain_Review_Decision.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_CB20A_Gauge_Pin_Domain_Review_Decision.md`; moved verbatim.

### RA-113 — CB20 and CB20A accepted: corrected gauge-pin domain compiled; TB20 authorized (2026-10-21)

**Turn:** `M6-CP3-CB20A-RP01-GAUGE-PIN-DOMAIN-REV`. **Input:** CB20A source `e22c5da5f8ab86a39650c670340a658847a2ac7e` and compile run [39520787768](https://github.com/akashskypatel/Directional/actions/runs/39520787768). The agent left CB20A `IN_PROGRESS` after a green compile and wrote no record. This decision holds the verified package facts, as RA-109 did for TB19. **Lines:** S = `src/geometry/SurfaceCellTracing.cpp`, TQ = `tests/SurfaceCellTransitionQuotientTests.cpp`, both at `e22c5da5f`; `src`, `include` and `tests` at HEAD are identical to it.

#### RA-113.1 Package verified independently

- **Artifact:** `12310848591`, ZIP SHA-256 `0c9f048e9a67fdaf61231b2ffa6834ee21a48e142f9cdae9e7ab14e015fc3ff5`, which equals the provider digest. It expires 2026-10-28T00:23:30Z.
- **Manifest:** `SHA256SUMS` lists 28 entries, all 28 verify, and the package holds exactly 28 other files.
- **Source and boundary:**
  - `source-commit.txt` is `e22c5da5f`;
  - the tarball's S and TQ are byte-identical to git at that commit;
  - all five `source-status-*` files are empty.
- **Build:**
  - `build-exit-code` is 0, and the build log has no warnings;
  - eight targets were compiled, with `directional_core` as the preflight target;
  - `DIRECTIONAL_ENABLE_GMP=ON`, and GMP and GMPXX are linked;
  - `runtimeExecution=false`, `exactArithmeticBackend=GMP`.
- **Content:** `directional_surface_cell_producer_tests` contains the two new test names, and the site string `gauge-pin-span;region=` is linked from `libdirectional_core.a`.

#### RA-113.2 CB20A diff matches RA-112.5

- **Items 1–2 only.** `git diff 7dc9b89ec e22c5da5f -- src include` is empty, and TQ changes by +9/−12:
  - the five accessor lines (TQ:1941, 1947, 1972, 1978, 1979);
  - `RegionGaugeShiftPassesPin`, which now asserts a `SurfacePhaseFrontProduct` and prints the error site on failure.
- The widest changed line is 89 columns.
- The S patch from CB20 (RA-112.2) is unchanged, so the count of 48 labels stands.
- **CB20 and CB20A are accepted as one compiled unit.** This acceptance is static and covers compilation only. Runtime acceptance belongs to TB20.

#### RA-113.3 TB20 rows (26)

All 26 rows run in `directional_surface_cell_producer_tests`.

**M2 — 9 rows; baseline RED at the pin (TB19/TB19A):**
- `cp3entry:1` `M6CP3.PeriodicExactA3UnequalFaceGaugeUsesRelationAndOccurrenceAuthority`
- `cp3entry:2` `M6CP3.HardRailCrossRegionBranchCertificateStripsEndpointFaceGauge`
- `cp3entry:6` `M6CP3.HardRailCrossRegionBindingDoesNotCompareGlobalSheetLabels`
- `focused30:6` `M5CP3.ProducedTorusPeriodicPairStorageSwapPreservesSemanticDirection`
- `focused30:12` `M6CP1.RelationPlacementTransportIsCoordinateRigidAndFaceGaugeInvariant`
- `focused30:20` `M6CP1.NonzeroZ4WitnessPassesProductionCompletionOwnership`
- `focused30:24` `M6CP1.ThinAdapterOutputIsPureProjectionOfStageProducts`
- `selector:446` `M5CP3.ProducedTorusNonzeroZ4RotationTranslationMaterializes`
- `selector:447` `M5CP3.ProducedTorusTamperedNonzeroZ4TransformRejectsTyped`

**M1 — 10 rows; baseline RED, the TB19 first failures:**
- `focused30:3` `M6CP1.SurfaceOccurrenceComplexRejectsMalformedMissingAndDuplicateRelationEndpoints`
- `focused30:22` `M6CP1.A5OwnsIsolationAndHardRailRouteValidationWithFrozenNames`
- `focused30:23` `M6CP1.A5ValidationPrecedencePreservesHardRailAuthorityBeforeTransport`
- `selector:139` `SurfaceCellAuthorityContractCutover.HardRailPairChangedRouteContentRejectsStrictTransport`
- `selector:140` `SurfaceCellAuthorityContractCutover.HardRailPairExplicitRailIdMismatchRejectsStrictTransport`
- `selector:142` `SurfaceCellAuthorityContractCutover.HardRailPairSameOrientationRejectsStrictTransport`
- `selector:211` `SurfaceCellTransitionQuotient.AmbiguousHardRailCounterpartIsRejected`
- `selector:219` `SurfaceCellTransitionQuotient.MissingHardRailCounterpartIsRejected`
- `selector:227` `SurfaceCellTypedTransportAuthority.DuplicateSemanticRouteTopologyFailsClosed`
- `selector:230` `SurfaceCellTypedTransportAuthority.RouteTopologyTransitionMismatchFailsClosed`

TQ lines in TB19's first failures map to HEAD by +77. Review checked all seven cited lines: 5036→5113, 5828→5905, 5869→5946, 8579→8656, 8600→8677, 9702→9779, 9722→9799.

**Controls — 3 rows; baseline PASS:**
- `selector:217` `SurfaceCellTransitionQuotient.ExactHardRailCounterpartsStitchAcrossTopologyRegions`
- `TB18 A#14` `SurfaceCellAuthorityContractCutover.ProducedOpenRailInteriorVertexEndpointRejectsForgedTags`
- `selector:443` `M5CP3.ProducedTorusPublishesTwoCanonicalPeriodicRelationsAndOwnedEdges`

**Suite — 3 rows; new:**
- `SurfaceCellFactoryRejectionSite.OneFaceGaugePinNamesSourceEdge`
- `SurfaceCellFactoryRejectionSite.RegionGaugeShiftPassesPin`
- `SurfaceCellFactoryRejectionSite.HardEdgeIsolatingFaceRejectsAtSpan`

**Oracle — 1 row; baseline RED in R4 (2026-10-15), outside selector 497; recorded only:**
- `M6CP3.A6UniformFaceGaugeRotationPreservesRelationOutcome` (TQ:2833 at `d2c7483cd`, the RA-111.4 uniform-rotation oracle).

#### RA-113.4 Predictions TB20-REV will adjudicate

- **P1.** All three suite rows PASS (RA-112.4).
- **P2.** No row rejects at `gauge-pin-consistency` on edge `1,4`, `4,7` or `0,3`. Those edges are hard, so they are now outside the domain. Any such site falsifies CB20.
- **P3.** No row's printed site is `gauge-pin-span;…`, because regions are spanned by construction. A span site, or a `gauge-pin-consistency` site on a non-hard edge, would bear on RA-111.5's cut-set question.
- **P4.** The three controls PASS. A control turning RED is a regression.
- **Not predicted:**
  - the new first failure of each M2 row, which determines the RA-103.5 R-route;
  - the M1 rows. Each is compared with its TB19 first failure after the +77 mapping, and any change is recorded for Review to classify;
  - the oracle.

#### RA-113.5 Next unit — `M6-CP3-TB20-RP01-GAUGE-PIN-DOMAIN` (Test + Benchmark, artifact-only)

1. **Harness.** Create `.agents/Directional/tools/m6_cp3_tb20_gauge_pin_domain_harness.sh` from the TB19A harness. Its diff from TB19A is limited to:
   - `sha`, `artifact` and `digest` (RA-113.1);
   - the 26-row table from RA-113.3, whose fourth field is the baseline: TB19 or TB19A status, `R4 RED` for the oracle, `new` for the suite;
   - the count 7→26;
   - the `TB19A` labels and ledger header → `TB20`, and `TB18` → `baseline`.

   Fixture staging, frozen-selector checks, manifest and immutability checks stay as they are.
2. **Run.** Dispatch the harness once against artifact `12310848591` before it expires (2026-10-28T00:23:30Z).
3. **Report.** Write `Architecture_M6_CP3_TB20_Gauge_Pin_Domain_Harvest_Report_20261021.md`. It contains:
   - the run, artifact and digest;
   - the 26-row table: status, first failure, product, detail, site and raw SHA-256;
   - for each M1 row, whether its first failure equals TB19's after the +77 mapping;
   - P1–P4 marked observed or not observed. The report does not interpret the M2 outcomes.

**Out of scope:**
- any source, test, selector or workflow change;
- any repair;
- accounting changes;
- the M1 binding.

**STOP and return to Review** on any of:
- a digest or manifest mismatch;
- a missing fixture;
- a selection count other than 26 single-identity runs;
- a harness failure.

There is no second harness repair inside the turn.

**On success:** `M6-CP3-TB20-RP01-GAUGE-PIN-DOMAIN-REV` (Review). It adjudicates P1–P4, determines the R-route and decides whether a selector-497 regression run must precede the M1 DEFN.

#### RA-113.6 Sequence and accounting

> *Closed by RA-114 (2026-10-21): TB20 confirmed P1–P4; the R-route falsifier is not observed; TB21 (selector-497 census) is next.*

- **Sequence:** CB20 → CB20-REV (RA-112) → CB20A → CB20A-REV (RA-113) → **TB20** → TB20-REV → [selector-497 regression run, if TB20-REV requires it] → DEFN on the M1 binding owner (RA-105.3) → corrective CB/TB → fixture debt → census → RP-01 Review.
- **Accounting is unchanged:** 66/17/49, debt 1, CP2 491/491, R3 403/497 rejected, TB18 candidate 448/497, selector 497. `RP-01` is open, `RP-02` is UNREACHED and Gate C is suspended.

## `Architecture_M6_CP3_CB20_Gauge_Pin_Domain_Compile_Stop_Review_Decision.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_CB20_Gauge_Pin_Domain_Compile_Stop_Review_Decision.md`; moved verbatim.

### RA-112 — CB20 compile stop reviewed: source accepted statically; test accessor correction authorized as CB20A (2026-10-20)

**Turn:** `M6-CP3-CB20-RP01-GAUGE-PIN-DOMAIN-REV`. **Input:** `Architecture_M6_CP3_CB20_Gauge_Pin_Domain_Code_Build_Stop_Record_20261020.md`; source commit `7dc9b89ec`, whose `src`, `include` and `tests` are identical to HEAD `fa1601d5b`. **Lines:** S = `src/geometry/SurfaceCellTracing.cpp`, TQ = `tests/SurfaceCellTransitionQuotientTests.cpp`, both at `7dc9b89ec`. **Amends:** RA-111.6 item 5 (oracle tightened) and RA-111.7 (sequence).

#### RA-112.1 Stop verified

- Workflow [39512680019](https://github.com/akashskypatel/Directional/actions/runs/39512680019): `compile / compile` failed.
- Its log has exactly five errors, all `no match for 'operator*'` on `DomainResult<SourceFaceId>`, at TQ:1941, 1947, 1972, 1978 and 1979. `directional_core`, which contains S, compiled.
- The agent stopped as RA-111.6 requires. No package exists, so CB20 is not complete.

#### RA-112.2 S patch accepted statically against RA-111.4

- **Domain skip** (S:8559–8563): it follows the open-boundary skip and the incidence-size rejection, as specified.
- **Union** (S:8564): it precedes the A3 check. This is harmless, because a failed check returns.
- **Index safety:** `face-gauge-shape` (S:8500–8508) guarantees that the gauge count equals `face_count()`. `from_index(row, size)` therefore yields `index() == row`, so the union-find and the span loop address the same rows.
- **Span guard** (S:8584–8598): a single-face region passes. The region index is bounded by `regions().size()`, because `region()` reads `regions_.at(id.index())`.
- **Comment** (S:8509–8511): three lines. Nothing else in S changes.

This acceptance is static only; runtime acceptance belongs to TB20.

#### RA-112.3 Root cause: wrong accessor, not a design defect

`DomainResult<T>` (`include/directional/authority/AuthorityIds.h:73–93`) offers `has_value()`, an explicit `operator bool` and `value()`. It has no dereference operator. S's own patch uses `faceId.value()`, as does the rest of TQ.

The test logic is sound. The correction replaces `*face0` and `*face` with `face0.value()` and `face.value()` on the five lines. The widest resulting line is 89 columns.

#### RA-112.4 Static walk of the three tests

Fixture `hard_rail_fixture()`:
- 9 vertices and 8 faces, with hard carriers (1,4) and (4,7);
- left region: faces {0,1,4,5}; right region: faces {2,3,6,7}.

**Item 4: `OneFaceGaugePinNamesSourceEdge`.**
- Face 0 = (0,1,4). Edge (0,1) is open boundary and (1,4) is hard.
- (0,4) is therefore face 0's only pinned edge, and the site is exactly `edge=0,4`.

**Item 5: `RegionGaugeShiftPassesPin` — oracle tightened.**
- The right region's pinned edges (1,5), (4,5) and (5,8) keep their gauge differences. Edges (1,4) and (4,7) are hard and are skipped. The old pin rejected at one of those two edges.
- Between the span guard and the product store (S:9629), `make` never reads `sourceFaceBranchRotations` again. The outcome is therefore a product.
- RA-111.6 item 5 also accepted "an error whose site does not begin with `gauge-pin-`". Such an error could only come from a consumer reading a gauge difference across the rail, which is RA-111.2's STOP condition. That condition must turn the test red, not pass it.
- **Amendment:** the test asserts a product. On failure, its message prints `sourceAuthoritySite`.

**Item 6: `HardEdgeIsolatingFaceRejectsAtSpan`.**
- (0,4) is face 0's only non-hard two-face edge.
- The draft copies `sourceTopologyRegions` from the product, so the regions stay as built. Nothing before the pin block (S:8458–8508) reads `hardFeatureEdges`.
- The span guard takes row 0 as the first face of the left region. Row 1, also in the left region, has a different root, so the guard rejects with `gauge-pin-span;region=<left index>`.
- Face 0's region has four faces, so the single-face STOP does not apply.

#### RA-112.5 Next unit — `M6-CP3-CB20A-RP01-GAUGE-PIN-TEST-ACCESSOR` (Code + Build, compile only)

**TQ only:**
1. **Accessors.** On TQ:1941, 1947, 1972, 1978 and 1979, replace `*face0` with `face0.value()` and `*face` with `face.value()`.
2. **Item 5 oracle.** In `RegionGaugeShiftPassesPin`, replace the product-or-other-error branch with one assertion that the result is a `SurfacePhaseFrontProduct`. The failure message prints the error's `sourceAuthoritySite`.

**Constraints:**
- S, `include` and every other file stay byte-identical to `7dc9b89ec`.
- No line is longer than 100 columns.

**Build:** the CB20 procedure — GMP/GMPXX, the eight targets, package, `runtimeExecution=false`. The CB20A record gives the TQ diff against `7dc9b89ec`, the package hashes, and the 48-label count carried from CB20.

**STOP and return to Review** on:
- any compile error (record the first diagnostic of each distinct error);
- any need to change a line outside items 1–2.

There is no second repair inside the turn.

**On success:** `M6-CP3-CB20A-RP01-GAUGE-PIN-DOMAIN-REV` (Review). It accepts CB20 and CB20A together, authorizes TB20 and sets its rows.

#### RA-112.6 Sequence and accounting

> *Closed by RA-113 (2026-10-21): CB20A compiled green; CB20 and CB20A are accepted together and TB20 is authorized.*

- **Sequence:** CB20 (compile RED, stopped) → CB20-REV (RA-112) → **CB20A** → CB20A-REV → [TB20 → TB20-REV] → DEFN on the M1 binding owner (RA-105.3) → corrective CB/TB → fixture debt → census → RP-01 Review.
- **Accounting is unchanged:** 66/17/49, debt 1, CP2 491/491, R3 403/497 rejected, TB18 candidate 448/497, selector 497. `RP-01` is open, `RP-02` is UNREACHED and Gate C is suspended.

## `Architecture_M6_CP3_CB22A_Torus_A5_Isolation_Site_Formatter_Review_Decision.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_CB22A_Torus_A5_Isolation_Site_Formatter_Review_Decision.md`; moved verbatim.

### RA-119 — CB22A harvested and accepted statically; five A5-ISO rows cannot show the site; test-message routing authorized as CB22B (2026-10-21)

**Turn:** `M6-CP3-CB22A-RP01-TORUS-A5-ISOLATION-SITE-FORMATTER-REV`. **Input:** CB22A left STATUS `IN_PROGRESS` while its compile ran, with no record; Review harvests (RA-118.5 closeout clause). Source `f082d9aeb`, compile run `39573431400`. **Lines:** RP = `src/pipeline/RemeshPipeline.cpp`, TQ = `tests/SurfaceCellTransitionQuotientTests.cpp`, both at `f082d9aeb` (TQ is identical to `384961bb4`). **Amends:** RA-118.6 (TB23 frame) and RA-118.7 (sequence).

#### RA-119.1 Harvest: CB22A compile GREEN (this decision is the CB22A record)

- Source `f082d9aebce0ad72906ccbf70c37a4bf90a9ae6f`; run [39573431400](https://github.com/akashskypatel/Directional/actions/runs/39573431400), `compile / compile` success.
- Package artifact `12333216637`, ZIP SHA-256 `ecde506738eae14082e888932fb15bd462ecd9c3ee20cef36e9a66f8805f4066` (recomputed locally), expires 2026-10-28T09:05:23Z.
- 28/28 `SHA256SUMS` entries verify; root manifest SHA-256 `af8e4e421fb54828d3c558d1a0da3e2f8a7ddf3ecac56b7c7f18f9c0bd6cff8b`; source archive `29a16107bf0bfdbf627b11d3ce78ee2755612991e3316bdc54a6b0c42a506527`, whose 350 `src`/`include`/`tests` files match `f082d9aeb` byte for byte.
- Build exit 0; the eight targets; GMP/GMPXX linked; `runtimeExecution=false`; source status clean before configure, after build and final. TQ compiled for the first time with the CB22 atlas line (step 30/53).

#### RA-119.2 CB22A diff accepted statically against RA-118.5

- One file, RP, +29/−23 against `384961bb4`. Every hunk lies in RP:5264–5317 (old numbering), inside the authorized RP:5264–5337. Header, TQ and every other file are identical.
- **Formatter:** each endpoint prints as `<cell>:<corner>` (RA-118.3).
- **Names:** all four inner names carry the `canonical` prefix. No bare `firstSpan`, `secondSpan`, `firstOccurrence` or `secondOccurrence` remains in the block. No added line exceeds 100 columns.
- No A5 predicate, ordering, code or return value changed. CB22 and CB22A are accepted statically as one compiled unit; runtime acceptance belongs to TB23.

#### RA-119.3 Design finding: the site does not reach five A5-ISO rows

RA-117.5 routed `isolationSite` only into the pipeline failure string (RP:9082–9084). It was the reviewer's specification gap, not an implementation defect. Rows that print that string will show the site: `focused30:20` (TQ:5832), `selector:444` (TQ:7951), `selector:446` (TQ:8325) and `selector:448` (TQ:8464). Five rows call A5 directly, or assert without a message:

| Row | Fixture | Failing assertion | Output today |
|---|---|---|---|
| `focused30:24` | nonzero-Z4 witness (TQ:6184) | TQ:6008 `ASSERT_NE(a5, nullptr)` | none |
| `focused30:25` | `run_retained_torus_pipeline()` | TQ:6193 `hasArrangement` | none |
| `focused30:26` | `torus_fixture()` | TQ:6478–6483 | `A5:<code name>` |
| `focused30:27` | `torus_fixture()` | TQ:6550–6555 | `A5:<code name>` |
| `focused30:28` (G4-B002) | `torus_fixture()` via TQ:960 helper | TQ:6587 | `A5:<code name>` |

`focused30:25–28` build from `milestone-g/torus.rawfield`, not the nonzero-Z4 witness, so their site cannot be inferred from the pipeline rows. The M6 exit row G4-B002 is among them. TB23 on the CB22A package would therefore leave the exit row unexplained. The correction is test-only and message-only.

#### RA-119.4 Next unit — `M6-CP3-CB22B-RP01-TORUS-A5-SITE-TEST-MESSAGES` (Code + Build, compile only)

**Base:** `f082d9aeb`. **TQ only:**
1. **Helper.** Immediately before `build_torus_closed_complex_view` (TQ:960), add `std::string a5_rejection_message(const directional::pipeline::SurfaceOccurrenceComplexProducer::ConstructionResult &construction)`. It returns `A5:unexpected-disposition` when the result holds no error; otherwise `A5:` and `surface_occurrence_complex_error_name(error->code)`, followed by `;site=` and `isolationSite` when that is non-empty.
2. **TQ:973–978:** `*firstFailure = a5_rejection_message(a5);` (covers `focused30:28` and the second `focused30:25` assertion).
3. **TQ:6008:** `ASSERT_NE(a5, nullptr) << a5_rejection_message(a5Construction);` (`focused30:24`).
4. **TQ:6193:** append `<< retained_pipeline_first_failure(run)` (`focused30:25`; its first reason is the materialization failure, which carries the site, RP:13179).
5. **TQ:6475–6483 and TQ:6547–6555:** stream `"torus downstream first rejection=" << a5_rejection_message(a5Construction)` and delete the now-unused `a5Error` declarations (`focused30:26`, `focused30:27`).

**Constraints:**
- RP, the header and every file other than TQ stay byte-identical to `f082d9aeb`.
- No assertion condition, fixture, selection or control-flow change. Existing message text is unchanged except for the `;site=` suffix and the two new messages.
- No line is longer than 100 columns.

**Build:** GMP/GMPXX, the eight targets, package, `runtimeExecution=false`. **Record:** `Architecture_M6_CP3_CB22B_Torus_A5_Site_Test_Messages_Code_Build_Record_20261021.md` (≤ 30 lines): source SHA; TQ diff stat and changed ranges against `f082d9aeb`; compile run, package id, ZIP SHA-256, hash count, expiry, root-manifest and source-archive SHA-256.

**STOP and return to Review** on any compile error, or any need to edit outside TQ or to change an assertion.

#### RA-119.5 TB23 frame (amends RA-118.6; CB22B-REV adds the package and issues the plan)

- **Rows (16, unchanged):** A5-ISO `focused30:20`, `24`, `25`, `26`, `27`, `28`, `selector:444`, `446`, `448`; F `focused30:6`, `selector:447`; controls `cp3entry:6`, `selector:217`, TB18 A#14, `selector:443`, `focused30:7`.
- **Measurements per A5-ISO row:** fixture, output path (pipeline or direct), site label, region, seam, `cert=` or certificate clauses.
- **Predictions:**
  - every row that fails with an isolation-evidence code shows `;site=` with one of the five labels, and no clause is `valid`;
  - `focused30:25` (pipeline) and `focused30:26/27/28` (direct) share the torus product, so they are expected to name the same label, region and seam; a disagreement is reported, not reconciled;
  - the F rows pass `atlas-binding`, and any failure is a later site;
  - every control is GREEN, with no `site=` in its output.
- **Falsifier:** an isolation-evidence code without `site=` is an instrumentation gap and a Review stop, not a result.

#### RA-119.6 Unchanged and sequence

- **Accounting:** RA-117.4 unchanged. Frozen: 66/17/49, debt 1, CP2 491/491, R3 403/497 rejected, selector 497, candidate evidence TB21 449/497. `RP-01` open, `RP-02` UNREACHED, Gate C suspended.
- **Sequence:** CB22-REV (RA-118) → CB22A (compile GREEN, harvested) → CB22A-REV (RA-119) → **CB22B** → CB22B-REV → TB23 (torus A5 site harvest) → TB23-REV → DEFN-ISO → corrective CB/TB → DEFN-M1 → corrective CB/TB → DEFN-T1 → fixture debt → census → RP-01 Review.

Closed by RA-120 (`Architecture_M6_CP3_CB22B_Torus_A5_Site_Test_Messages_Review_Decision.md`): CB22B accepted statically; TB23 issued.

## `Architecture_M6_CP3_CB22B_Torus_A5_Site_Test_Messages_Review_Decision.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_CB22B_Torus_A5_Site_Test_Messages_Review_Decision.md`; moved verbatim.

### RA-120 — CB22B accepted statically; the site reaches all nine A5-ISO rows; TB23 harvest issued (2026-10-21)

**Turn:** `M6-CP3-CB22B-RP01-TORUS-A5-SITE-TEST-MESSAGES-REV`. **Input:** CB22B record `Architecture_M6_CP3_CB22B_Torus_A5_Site_Test_Messages_Code_Build_Record_20261021.md`; source `c6e90916e`. **Lines:** TQ = `tests/SurfaceCellTransitionQuotientTests.cpp`, RP = `src/pipeline/RemeshPipeline.cpp`, both at `c6e90916e`.

#### RA-120.1 Package verified independently

- Compile run [39591106454](https://github.com/akashskypatel/Directional/actions/runs/39591106454) success; package `12341307713`, ZIP SHA-256 `b5f9a668…8ad5` (recomputed locally, equal to the provider digest), expires 2026-10-28T11:21:37Z.
- 28/28 `SHA256SUMS`; root manifest `7c396be6…7f11`; source archive `c3779cc9…cd75`: all 1,046 files match `c6e90916e` byte for byte (350 in `src`/`include`/`tests`).
- Build and preflight exit 0; the eight targets; GMP/GMPXX linked; `runtimeExecution=false`; five source-status files empty; zero compiler warnings. The record's figures agree.

#### RA-120.2 Diff accepted statically against RA-119.4

- TQ only, +22/−24; RP, the header and every other source file are identical to `f082d9aeb`. Widest added line 85 columns.
- The helper matches the specification: no error gives `A5:unexpected-disposition`; otherwise `A5:<code name>`, plus `;site=` when the site is non-empty.
- The five sites are exactly as specified; the two removed `a5Error` declarations had no other use. Message text is unchanged apart from the `;site=` suffix and the two new messages (TQ:6017, TQ:6202–6203). No assertion condition, fixture, selection or control flow changed.
- **Coverage now complete.** Every A5 isolation return carries a site: `MismatchedIsolationEvidence` is returned only at RP:4161 (through `transition_between`) and RP:5262, and `MissingIsolationEvidence` only at RP:4149; all three reach the four side sites or the relation site. All nine A5-ISO rows print it: five through the pipeline failure string, four through the CB22B messages.

#### RA-120.3 Residual ambiguity, resolved in the plan rather than by code

`focused30:24` asserts inside a `verify` lambda called for three fixtures (TQ:6191–6193), so one failure line does not name its fixture. The W rows `focused30:20` and `selector:446` build the same witness product through the pipeline path. TB23 P3 therefore predicts exactly one failure carrying the W site, and reports any other count in call order. No CB is warranted: the cross-check is falsifiable without changing a test.

#### RA-120.4 Next unit — `M6-CP3-TB23-RP01-TORUS-A5-SITE-HARVEST` (Test + Benchmark, artifact-only)

Plan: `Architecture_M6_CP3_TB23_Torus_A5_Site_Harvest_Plan_20261021.md`. It holds the package identity, the sixteen rows with fixture and output path, the ledger columns, P1–P5, the falsifiers, and the pre-registered routing to H-ISO-1/2/3 (RA-117.3) for TB23-REV.

#### RA-120.5 Unchanged and sequence

66/17/49, debt 1, CP2 491/491, R3 403/497 rejected, selector 497 frozen, TB21 candidate 449/497; `RP-01` open, `RP-02` UNREACHED, Gate C suspended. CB22 + CB22A + CB22B form one statically accepted diagnostic unit; none of it is runtime evidence until TB23.

Sequence: **TB23** → TB23-REV → DEFN-ISO → corrective CB/TB → DEFN-M1 → corrective CB/TB → DEFN-T1 → fixture debt → census → RP-01 Review.

Closed by RA-121 (`Architecture_M6_CP3_TB23_Torus_A5_Site_Harvest_Review_Decision.md`): TB23 reviewed; CB23 seam-face measurement next.

## `Architecture_M6_CP3_CB22_Torus_A5_Isolation_Site_Compile_Stop_Review_Decision.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_CB22_Torus_A5_Isolation_Site_Compile_Stop_Review_Decision.md`; moved verbatim.

### RA-118 — CB22 compile stop reviewed: diagnostic accepted statically; occurrence formatter and name correction authorized as CB22A (2026-10-21)

**Turn:** `M6-CP3-CB22-RP01-TORUS-A5-ISOLATION-SITE-REV`. **Input:** `Architecture_M6_CP3_CB22_Torus_A5_Isolation_Site_Code_Build_Stop_Record_20261021.md`; CB22 source `384961bb4` against snapshot base `49c982195` (3 files, +122). **Lines:** RP = `src/pipeline/RemeshPipeline.cpp`, TQ = `tests/SurfaceCellTransitionQuotientTests.cpp`, both at `384961bb4`. **Amends:** RA-117.5 (TB23 frame fixed here) and RA-117.6 (sequence).

#### RA-118.1 Stop verified

- Run [39564087707](https://github.com/akashskypatel/Directional/actions/runs/39564087707), log artifact `12329047110`: `directional_core` linked; `RemeshPipeline.cpp.o` failed with exactly two errors, RP:5274:62 and RP:5275:48, `OccurrenceId` has no member `index`. Ninja stopped; TQ was never compiled; no package; `runtimeExecution=false`.
- GCC reports every error in a translation unit, so the rest of RP, including all instantiations of the generic lambdas `isolation_binding_label` (RP:4168) and `isolation_side_site` (RP:4173), type-checks.
- The agent stopped as RA-117.5 requires. CB22 is not complete.

#### RA-118.2 CB22 diff accepted statically against RA-117.5

- **Header:** `isolationSite` is the last member, default-constructed. No code brace-initializes `SurfaceOccurrenceComplexError`.
- **Part A:** TQ:1673 matches TQ:649/861. `PhaseFrontFixture::fieldTransportAtlas` (TQ:372) and the snapshot field are both `std::optional<FieldTransportAtlas>`. Static only: TQ compiles first in CB22A.
- **Side sites:** each of `side-step` (RP:4356), `side-collinear` (RP:4400), `wedge-edge` (RP:4516) and `wedge-fan` (RP:4600) passes exactly the region, seam, from and to of its `transition_between` call (RP:4348, 4392, 4507, 4591). The `cert=` lookup uses the same `isolationCertificateBySeam` key as RP:4143, so it prints the certificate the decision read.
- **Relation site** (RP:5262–5337, inside the RP:5249 reject): the clause classifier mirrors `certified_seam_direction` (RP:3889–3911) clause for clause, in order. The passing count over region/seam-matched certificates equals `seam_transport_certificate`'s (RP:4686) count over all, because the predicate itself requires the region and seam match. `valid` is therefore unreachable when the reject fires; if TB23 prints it, that is a contradiction to report, not a result.
- **Failure string** (RP:9082–9084): appended only when `isolationSite` is non-empty, which happens only on the five isolation-evidence returns. No file under `src`, `tests`, `tools` or `include` compares the `a5-side`/`a5-wedge` names exactly.
- **Invariant holds:** every addition sits after its decision and before an existing `return error;`. No A5 predicate, ordering, code or return value changed.

The clause classifier duplicates the predicate. It is accepted as rejection-only instrumentation; DEFN-ISO decides whether it is retired or folded into the predicate. Refactoring `certified_seam_direction` to return a reason is not authorized, because it is the decision function.

#### RA-118.3 Root cause: wrong identity projection, not a design defect

`OccurrenceId` (`include/directional/authority/AuthorityIds.h:250–289`) is the pair (`cell()`, `canonical_corner_role()`). By design it has no numeric projection, because container position is excluded from occurrence identity. The type-correct formatter follows the existing test idiom (TQ:3454–3468): `<id.cell().index()>:<static_cast<int>(id.canonical_corner_role())>`.

#### RA-118.4 Design finding: canonical names shadow storage-order names

RP:5264–5267 redeclare `firstSpan` and `secondSpan` (outer: storage-order `const SurfaceOccurrenceSideSpan *`, RP:5208/5210), and `firstOccurrence` and `secondOccurrence` (outer: storage-order `OccurrenceId` bindings, RP:5193), as canonical-order references of other types. The binding is correct, because it reads `evidence.*` and `relationId`. But this block diagnoses an order-sensitive family (`focused30:6` is a storage-swap test), and a later edit that means the outer storage-order name would silently bind to the canonical one. **Correction:** rename the four inner names to `canonicalFirstSpan`, `canonicalSecondSpan`, `canonicalFirstOccurrence` and `canonicalSecondOccurrence`, within RP:5264–5337 only.

#### RA-118.5 Next unit — `M6-CP3-CB22A-RP01-TORUS-A5-ISOLATION-SITE-FORMATTER` (Code + Build, compile only)

**Base:** `384961bb4`. **RP only:**
1. **Formatter.** On RP:5274–5275, print each relation endpoint as `<cell>:<corner>` using the RA-118.3 formatter, giving `;relation=<c>:<k>,<c>:<k>`.
2. **Names.** Apply the RA-118.4 rename within RP:5264–5337. No other edit in the block.

**Constraints:**
- The header, TQ and every other file stay byte-identical to `384961bb4`. RP differs only within RP:5264–5337.
- No line is longer than 100 columns. No A5 predicate, ordering, code or return change.

**Build:** the CB22 procedure: GMP/GMPXX, eight targets, package, `runtimeExecution=false`. **Record:** `Architecture_M6_CP3_CB22A_Torus_A5_Isolation_Site_Formatter_Code_Build_Record_20261021.md` (≤ 30 lines): source SHA; RP diff stat and changed line range against `384961bb4`; cumulative per-file stat against `49c982195`; compile run, package id, ZIP SHA-256, hash count, expiry, root-manifest and source-archive SHA-256.

**STOP and return to Review** on any compile error (TQ compiles for the first time), or any need to edit outside RP:5264–5337.

#### RA-118.6 TB23 frame (fixed; CB22A-REV adds the package identity)

- **A5-ISO rows:** `focused30:20`, `24`, `25`, `26`, `27`, `28`; `selector:444`, `446`, `448`.
- **F rows:** `focused30:6`, `selector:447`.
- **Controls:** `cp3entry:6`, `selector:217`, TB18 A#14, `selector:443`, and the certified-seam positive control `focused30:7` (`M6CP1.SeamEndpointOccurrencesPublishCompleteCornerWedgeSheetAuthority`; TQ:4272; it asserts one certificate and cross-sheet transitions on that seam; GREEN in TB21).
- **Predictions:**
  - every A5-ISO row that still fails in A5 prints `;site=` with one of the five labels, and no clause is `valid`;
  - the F rows pass `atlas-binding`, and any failure is a later site;
  - every control is GREEN, with no `site=` in its output.

#### RA-118.7 Unchanged and sequence

- **Accounting:** RA-117.4 unchanged. Frozen: 66/17/49, debt 1, CP2 491/491, R3 403/497 rejected, selector 497, candidate evidence TB21 449/497. `RP-01` open, `RP-02` UNREACHED, Gate C suspended.
- **Sequence:** TB22-REV (RA-117) → CB22 (compile RED) → CB22-REV (RA-118) → **CB22A** → CB22A-REV → TB23 (torus A5 site harvest) → TB23-REV → DEFN-ISO → corrective CB/TB → DEFN-M1 → corrective CB/TB → DEFN-T1 → fixture debt → census → RP-01 Review.

Closed by RA-119 — CB22A harvested and accepted statically; CB22B authorized (`Architecture_M6_CP3_CB22A_Torus_A5_Isolation_Site_Formatter_Review_Decision.md`).

## `Architecture_M6_CP3_DEFN_P1_Gauge_Pin_Domain_Review_Decision.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_DEFN_P1_Gauge_Pin_Domain_Review_Decision.md`; moved verbatim.

### RA-111 — DEFN-P1 reviewed: census accepted; exactness withdrawn for a spanning domain; CB20 authorized (2026-10-20)

**Turn:** `M6-CP3-DEFN-P1-GAUGE-PIN-DOMAIN-REV`. **Input:** `Architecture_M6_CP3_DEFN_P1_Gauge_Pin_Domain_Definition_Record_20261020.md` (`fe07a5e09`). **Lines:** S = `src/geometry/SurfaceCellTracing.cpp`, R = `src/pipeline/RemeshPipeline.cpp`, TQ = `tests/SurfaceCellTransitionQuotientTests.cpp`, all at HEAD `ca9c23e85`, whose `src`, `include` and `tests` are identical to `d2c7483cd`. **Amends:** RA-110.4 item 3 (withdrawn) and RA-110.5's first STOP condition (corrected).

#### RA-111.1 Record verified

- **Producer table (item 1) is confirmed.** The uniform producer (S:13208–13229) and the periodic-annulus producer (S:14019–14039) both decline a region that has a hard feature and a conformity baseline. Only the curved bounded-disk producer runs there, and it excludes `acceptedCutEdges` (S:15333, S:16000, S:16217, S:16346).
- **Torus regions (item 3) are confirmed.** Review recomputed them from the committed `torus.obj`, omitting the 18 hard edges:
  - 144 faces form one region;
  - {0,3} lies between faces 1 and 22;
  - the non-hard dual graph is connected.
- **Consumer census (item 5) is confirmed.** R:4630–4642 reads one face's gauge, and R:5633–5655 compares presence and face identity only. No production consumer reads a gauge difference, which agrees with RA-45.1.
- **Cut-set inclusion (item 2) is accepted as open.** Nothing proves `acceptedCutEdges ⊆ hardFeatureEdges`. RA-111.5 explains why this does not block CB20.
- **The predicate (item 4) is correct under RA-110.4 item 3.** RA-111.3 withdraws that constraint, and RA-111.4 replaces the predicate.

#### RA-111.2 The conditional STOP does not fire

- **Review's wording was wrong.** RA-110.5's first STOP ("a producer whose gauge domain includes a hard-feature carrier") assumed the correction would drop hard edges wholesale.
- **No falsification.** A producer that verifies transport across an intra-region hard edge does not make the pin wrong on that edge, so it does not falsify H-pin. H-pin concerns only edges the pin checks and no producer relates.
- **Corrected STOP:** a production consumer reads a face-gauge difference across an edge outside the pin domain. The census shows none.
- **The agent was right to raise the point.** Returning it to Review rather than resolving it was correct.

#### RA-111.3 Exactness withdrawn; the domain must span each region

**RA-110.4 item 3 is withdrawn.** It required the pin to cover exactly the producer-related edges, which forced DEFN-P1 to ask for a new `make` input. The pin authenticates the gauge, and the gauge has only one degree of freedom per region:
- **Relational and region-relative.** The gauge is consumed only relationally (RA-45.1, census above) and is region-relative (RA-31a.1).
- **A spanning graph fixes the gauge.** Take a connected set G of pinned edges inside a region. The gauges that satisfy `compose(T_e, g_a) == g_b` on every edge of G form at most one orbit of the region's Z4 shift. Any edge beyond a spanning tree adds no constraint on the gauge; it only constrains the atlas's holonomy on a cycle.
- **So any spanning pinned set detects the same tampering as the full producer relation set.** The holonomy checks it leaves out are exactly what H-pin found misplaced in a gauge check.
- **The spanning set already exists.** Regions are the connected components of the graph of two-face, same-component, non-hard edges (S:9670–9727), so restricting the pin to that graph spans every region by construction.
- **No new `make` input or producer change is needed.**

#### RA-111.4 Corrected domain (frozen for CB20)

```
pin(e, a, b)  <=>  two_face(e, a, b)  &&  e not in hardFeatureEdges
                   &&  region_for_row(a) == region_for_row(b)
```

**Span guard.** Within each region, the pinned edges must connect all of its faces. Otherwise `make` returns `InvalidSourceAuthority` with site `gauge-pin-span;region=<index>`. The guard keeps the pin non-vacuous whatever the source of `make`'s `hardFeatureEdges`. It cannot fire for a producer whose regions and hard edges come from the same options.

**Properties:**
- **Monotone.** The new domain is a subset of the current one, so every product the pin accepts today it still accepts. The only new acceptances are:
  - a gauge shift of a whole region (RA-31a.1; RA-45.4 applied per region);
  - fields whose holonomy crosses a hard edge.
- **RA-45.3's rejections still hold:** a one-face change, a change to a proper subset of a region, an A3 mismatch on a pinned edge, and an absent gauge. A3 across carriers stays with `rail-transition-a3` (S:8717–8732).
- **Existing oracles still hold:**
  - TQ:2749–2754 (`cp3entry:1`, one-face torus tamper) still rejects through the face's non-hard edges;
  - TQ:2833 (uniform rotation) is still accepted;
  - TQ:4987–5036 (`focused30:12`, one-region relabel) passes the pin.

#### RA-111.5 Open item, not blocking

A non-hard accepted cut carrier, if one exists, stays pinned exactly as it is today. The result is a fail-closed rejection, never a silent acceptance. If TB20 shows `gauge-pin-consistency` on a non-hard edge, Review opens a follow-up on cut-set inclusion.

#### RA-111.6 Next unit — `M6-CP3-CB20-RP01-GAUGE-PIN-DOMAIN` (Code + Build, compile only)

**S (inside the pin block, S:8509–8567, only):**
1. **Domain skip.** In the incidence loop (S:8538), after the open-boundary skip and the incidence-size rejection, skip the edge (`continue`) when `hardFeatureEdges.contains(edge)` or `sourceTopologyRegions.region_for_row(incident[0]) != sourceTopologyRegions.region_for_row(incident[1])`.
2. **Span guard.** After the loop, union the faces of every pinned edge. Every face must share a root with the first face of its region (`region_for_row`, `TopologyRegionId::index()`). Otherwise return code 0 with site `std::string("gauge-pin-span;region=") + std::to_string(<index>)`.
3. **Comment.** Update the RA-45 comment (S:8509–8513) to state the domain in at most three lines.

**TQ (suite `SurfaceCellFactoryRejectionSite`, outside every frozen selector):**
4. **Tighten** `OneFaceGaugePinNamesSourceEdge`: the site must equal `gauge-pin-consistency;edge=0,4`.
5. **New** `RegionGaugeShiftPassesPin`:
   - the `hard_rail_fixture()` draft, with +1 mod 4 on the gauge of every face in the region that does not contain face 0;
   - assert the result is a product, or an error whose site does not begin with `gauge-pin-`.
   - *Amended by RA-112.4: the test asserts a product only.*
6. **New** `HardEdgeIsolatingFaceRejectsAtSpan`:
   - insert every non-hard two-face edge of face 0 into the draft's `hardFeatureEdges`;
   - expect `InvalidSourceAuthority` with site `gauge-pin-span;region=<face 0's region index>`.

**Static acceptance:**
- the S diff lies only inside S:8509–8567, plus the guard placed directly after the loop;
- no line is longer than 100 columns;
- all 48 `InvalidSourceAuthority` site labels are unique;
- nothing changes in the header, the producers, R, the selectors or any frozen test.

**Build:** GMP/GMPXX, the eight targets, package, `runtimeExecution=false`. The CB20 record gives the diff summary and the label → S-line entry for the new label.

**STOP and return to Review** on:
- a compile error (record the first diagnostic of each distinct error);
- face 0's region having a single face;
- any need to touch code outside the pin block.

**On success:** `M6-CP3-CB20-RP01-GAUGE-PIN-DOMAIN-REV` (Review). The TB20 rows are set there.

#### RA-111.7 Sequence and accounting

> *Amended by RA-112.6: CB20 stopped at compile; CB20A and CB20A-REV follow before TB20.*

- **Sequence:** CB20 → CB20-REV → TB20 (artifact-only: the nine M2, the ten M1 as a no-regression check, the `SurfaceCellFactoryRejectionSite` suite, controls) → TB20-REV → DEFN on the M1 binding owner (RA-105.3) → corrective CB/TB → fixture debt → census → RP-01 Review.
- **Accounting is unchanged:** 66/17/49, debt 1, CP2 491/491, R3 403/497 rejected, TB18 candidate 448/497, selector 497. `RP-01` is open, `RP-02` is UNREACHED and Gate C is suspended.

## `Architecture_M6_CP3_DEFN_U6_Exact_I_Origin_Review_Decision.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_DEFN_U6_Exact_I_Origin_Review_Decision.md`; moved verbatim.

### RA-95 — DEFN-U6 stopped without a deliverable; Review locates the exact I-endpoint origin; DEFN-U6A narrowed (2026-10-18)

**Turn:** `M6-CP3-DEFN-U6-EXACT-I-ENDPOINT-PARAMETER-REV`. **Inputs:** HEAD `73a014c4e`. `src`, `include` and `tests` are identical to CB14A `2ee499a3`, so every `S:` line below is valid there. TB14A result `12141843937` raw logs. **S** = `src/geometry/SurfaceCellTracing.cpp`. **Amends:** RA-94.5 (order) and RA-94.6 (spec). RA-96 (the DEFN-U6A review) is appended and amends RA-95.4/95.6. RA-97 (the TB15 review) is appended and withdraws RA-95.3's "p ≠ 1/5". RA-98 (the TB16 review) is appended and amends RA-97.4 item 5 and RA-97.5/97.6. RA-99 (the CB16A patch review) is appended; it fixes the CB16A compile source. RA-100 (the CB16A review) is appended; it accepts CB16A and pins the TB16A and TB16C inputs. RA-101 (the TB16A review) is appended; it pins the TB16C deliverables. RA-102 (the TB16C review, `Architecture_M6_CP3_TB16C_Census_U4_Review_Decision.md`) closes U6: B3 is cleared on all 19.

#### RA-95.1 Turn state

- DEFN-U6 began (`acba9a334`) and requested a source snapshot (`df3458d23`; run `39148463200` succeeded). It then stopped with STATUS `IN_PROGRESS` and itself named as successor (`73a014c4e`).
- No deliverable and no document change exist, so there is nothing to adjudicate.
- RA-94.6 asked one turn to search a 21k-line file for an unlocalized origin, and to answer six items besides. That was too wide (LESSONS §6). Review localized the origin (RA-95.3) and narrows the turn (RA-95.5).

#### RA-95.2 The 19 B3 identities are one shape (measured)

Every one of the 19 TB14A raw logs (focused30 3/12/14/15/17/18/22/23/24; focused12 5/6; selector 211/217/219/227/230/231; `cp3entry` 2/6) shows the same shape:
- `predicate=endpoint-1`, front 17/203, edge 1–4, faces 0/3, first failed condition `not-same-interior-carrier-point`;
- span 3 on both front records, with reciprocal ordinals `0/1→1/1` and `1/1→0/1`;
- face 0's barycentrics sum to exactly 1 + 2⁻⁵⁵, and face 3's to exactly 1.

Only `chi` differs: 0 in the 17 focused and selector identities, 3 in `cp3entry`. Satisfiability is therefore one template, and per-identity rows add nothing.

#### RA-95.3 Exact origin located (Review trace; U6A verifies)

1. `append_arc_schedule` (S:17020-17046) reads the arc's single source-path piece and computes `first`/`second` with `exact_edge_parameter` (S:44-59), which takes the `ExactSourceEdgePoint::parameter` as a `FieldExactRational`. The span is the arc id (`ConformitySpanId::from_network_arc`), so both sides of span 3 share one arc and one schedule.
2. `location_parameter(ordinal)` (S:17205-17218) returns `first + local·(second − first)`, where `local` is the exact `breakpoint_location(span, ordinal)`. It is exact, computed at one site, keyed by (span, ordinal), and expressed in edge orientation (`edge.first` → `edge.second`).
3. **The exact value is lost here.** `append_point` (S:17177) calls `boundary_trace_point` (S:16944-16972):
   - `canonical = to_double(p)`;
   - `alpha = forward ? canonical : 1.0 − canonical`;
   - `bary[first] = 1 − alpha` and `bary[second] = alpha`.
4. The lattice-boundary override (S:17406-17421) places `acceptedBoundary[side].points[k]` at the boundary node. Cell corners copy `points[nodeIds]` (S:17500-17502), and the front edges copy the corners (S:17589-17590). The links onward to the three checkers are **not traced by Review**.

**Model check.** Take `c = to_double(p) = 0x1.9999999999999p-3`. Face 0, forward, then gives (`0x1.999999999999ap-1`, `0x1.9999999999999p-3`) with sum 1 + 2⁻⁵⁵. Face 3, reversed, gives (`0x1.999999999999ap-1`, `0x1.9999999999998p-3`) with sum exactly 1. Both observed triples match bit for bit. `a2bProbeBoundarySourceEntities` shows the same two parameters at region 0 node (5,1) and region 1 node (0,1). ~~Because `to_double(1/5) = 0x1.999999999999ap-3`, p ≠ 1/5~~ — withdrawn by RA-97.2: the GMP conversion truncates, and TB15 measured p = 1/5. The exact value of p is not logged.

**Consequence:**
- The one-ULP pair is orientation-dependent rounding at a single site, applied to one producer-origin exact rational that both sides share by construction.
- RA-94.6's "no exact origin" branch is answered: an origin exists. It is the "single canonical parameter" that R9B:29 anticipated.
- The rule stays exact equality, never a tolerance.
- **RA-63.5 still binds.** The endpoint's (span, ordinal) is endpoint-level, unlike the record-level conjunct that RA-61.9 used, but it is not bound to geometry. The design must bind p to each side's doubles; otherwise a forged ordinal pairs different points.

#### RA-95.4 Order (amends RA-94.5)

- The DEFN-first rationale (feasibility) is largely discharged by RA-95.3. A narrow documents-only U6A is kept to close link 4 and choose the representation.
- DEFN-U6A-REV then:
  - issues the CB15 (U4) specification;
  - issues the U6 CB specification, or DEFN-U6B if the design is still open;
  - schedules the fixture debt.
- The planned code order U4 → U5 → U6 is unchanged. U6 has no dependency on U4/U5, and DEFN-U6A-REV may reorder them with a reason.

#### RA-95.5 DEFN-U6A — `M6-CP3-DEFN-U6A-I-ENDPOINT-EXACT-ORIGIN-TRACE` (documents only)

Deliverable `Architecture_M6_CP3_DEFN_U6A_I_Endpoint_Exact_Origin_Trace_20261018.md`, 80 lines or fewer, citing `file:line` at `2ee499a3`.

1. **Verify or refute** RA-95.3 steps 1–3. A refutation names the line.
2. **Link 4:** list every writer from `acceptedBoundary[side].points[k]` to the compared points at the factory (S:8750-8773), the consumer (S:19480) and the probe (S:20065). Include the corner copy, `reverse_phase_front_cell_cycle`, and any cross-region pairing. State whether any arithmetic touches the doubles after `boundary_trace_point`.
3. **Endpoint to (span, ordinal):** show how each side's `sharedBoundaryInterval` first/second ordinals and `orientation` map to `from`/`to`, and show that the template resolves to span 3, ordinal 1 on both sides.
4. **p itself:**
   - its formula in terms of the arc's `ExactSourceEdgePoint` and `breakpoint_location`;
   - whether p lies strictly in (0, 1);
   - the existing field that would print it, or else the minimal probe a CB would add (named, not written).
5. **Representation.** Compare these candidates:
   - (a) a per-endpoint exact `ExactSourceEdgePoint` on `SurfaceFrontEdge`, set only by the accepted-boundary producer;
   - (b) recomputing p at the checkers from (span, ordinal), stating whether the baseline plan reaches `make` and the consumer;
   - (c) any other candidate.

   For each, state:
   - what reaches all three checkers;
   - how p binds to the doubles, e.g. bit-equality with `boundary_trace_point(p)` for that face and orientation;
   - that an I endpoint from any other producer carries no exact point and stays rejected (fail closed).

   Recommend one.
6. **CB outline** of 10 lines or fewer, applying RA-94.6 items 3 and 5 (rule and negatives) to the recommendation. Include TB predictions:
   - the 19 move past `endpoint-1` of front 17/203;
   - only those of RA-76's 324 one-ULP pairs that share an exact origin are accepted.

   Include falsifiers. Review writes the CB specification.

**Out of scope:** code, builds, runs, probes, U4/U5, fixture debt, selector or harness. **If RA-95.3 is refuted:** say where and stop. Never a tolerance. **Gates:** `document_drift_audit.py --root .`.

#### RA-95.6 Sequence

DEFN-U6A → DEFN-U6A-REV → CB15/TB15 (U4) → CB16/TB16 (U5) → U6 CB/TB → RP-01 Review. Each CB follows a reviewed TB, and a RED TB goes to Review. Accounting unchanged: 66/17/49, debt 1, CP2 491/491, R3 403/497, census 425/497.

#### RA-96 — DEFN-U6A reviewed: trace accepted; representation amended; U6 first as CB15/CB16 (2026-10-18)

**Turn:** `M6-CP3-DEFN-U6A-I-ENDPOINT-EXACT-ORIGIN-TRACE-REV`. **Subject:** `Architecture_M6_CP3_DEFN_U6A_I_Endpoint_Exact_Origin_Trace_20261018.md` (`636970568`; closeout `e99f49748`). `src`, `include` and `tests` are unchanged since `2ee499a3`. **B** = `src/geometry/GlobalConformityBaseline.cpp`; **H** = `include/directional/geometry/SurfaceCellTracing.h`.

##### RA-96.1 Verification

- **Items 1–3 confirmed independently:**
  - with one support piece, `breakpoint_location` (B:740-766) gives `j/count` for 0 < j < count and `1/1` at j = count;
  - forward and reverse intervals own `from = p(j)` and `to = p(j±1)` (S:17219-17262);
  - `reverse_phase_front_cell_cycle` only permutes corners (S:12535-12546);
  - nothing writes a barycentric between S:17400 and S:20400.
- **Accepted finding:** the UV-proximity dedup (S:17190-17194) is a tolerance merge. The side's own invariant needs it (`intervals + 1 == points`, S:17289-17290), so any witness must pass through it exactly.
- **Item 4 was not delivered:** p cannot be printed from existing data. CB15 measures it instead. The interiority argument also misses j = count (where p is the arc's `second`); A1 makes interiority structural.
- The factory cannot authenticate (span, ordinal) → p, because `make` has no baseline plan. (b) is rejected for that reason, and RA-96.2 A4 states the trust root.

##### RA-96.2 Amendments to representation (a)

- **A1 — canonical form.** The witness is built only through `canonical_exact_source_edge_point(edge, p)` (`ExactSourcePath.h:47-55`). It is kept only when the result is an `ExactSourceEdgePoint`:
  - so 0 < p < 1 holds by construction;
  - p ∈ {0, 1} carries no I witness, because the exact vertex gates already cover it.
- **A2 — the DEFN's dedup rule is defective.** Consecutive edges of one side meet at a shared vertex: p = 1 on edge 1–4, then p = 0 on edge 4–7, at the same chart occurrence (S:17149-17152, S:17185-17189). Applied to every sample, "reject unless edge and p agree" would make the producer reject every multi-edge side.
  - **Replacement:** when the dedup fires and the two witnesses differ (including one present and one absent), clear the kept point's witness.
  - No rejection and no behavior change. The endpoint falls back to the legacy exact gate, so U6 fails closed.
- **A3 — placement.** The witness lives inside `SurfaceTracePoint` (H:90-93) as `std::optional<authority::ExactSourceEdgePoint> exactEdgePoint`, not per endpoint on `SurfaceFrontEdge`.
  - Link 4 shows every hop is a copy of a `SurfaceTracePoint`, so in-point storage reaches every hop unchanged. (a) as written needs parallel arrays in three structures plus the reversal permutation.
  - A stale copy cannot bind (A4).
  - Cost: the type becomes non-trivially copyable. Benchmarks are not a gate (Gate C suspended). If a compile-time constraint forbids the change, CB15 stops and reports.
- **A4 — binding and trust root.** There is one rounding definition: `boundary_trace_point` (S:16944-16972) is moved unchanged into a detail helper that also sets the witness (A1). A witness binds iff:
  - its edge is the carrier edge;
  - the point's face contains both edge vertices;
  - the point's three doubles equal the helper's output, bit for bit, for one of the two orientations.

  The trust root is the producer, as in RA-84.2. The checkers cannot detect a forgery that is equal on both sides and consistent with both sides' doubles, and no stronger claim is made.

##### RA-96.3 Order and renumbering (amends RA-95.4/95.6)

U6 goes first, in two units:
- **CB15** adds the witness with no admission change. Its TB measures satisfiability on real data before any rule changes (RA-61.7).
- **CB16** makes the checkers use the witness.

U4 and U5 follow as CB17 and CB18. Reasons for this order:
- the U6 design is complete and verified now;
- the U4 spec (RA-84, ten rungs old) has to be re-derived against today's factory;
- the units have no dependency on each other.

IDs are renumbered so turn numbers keep increasing.

##### RA-96.4 CB15 — `M6-CP3-CB15-R10-EXACT-I-ENDPOINT-WITNESS-PRODUCER` (compile only; no admission change)

1. **H:** `SurfaceTracePoint` gains `std::optional<authority::ExactSourceEdgePoint> exactEdgePoint;` with a one-line comment: producer-origin provenance, never identity unless bound. Include `ExactSourcePath.h`.
2. **Detail helpers**, declared beside H:1557:
   - `accepted_boundary_trace_point(faces, face, firstVertex, secondVertex, p, edge)`: the S:16944-16972 arithmetic unchanged, plus A1. The lambda becomes a call to it.
   - `exact_interior_witness_binds(point, faces, edge)`: A4.
3. **Dedup** (S:17190-17194): A2.
4. **Probe:** after the `railEnd` loop (S:20092-20100), append `;a2bProbeFromExact=<lo,hi@n/d|none>;a2bProbeFromExactBinds=<0|1>;a2bProbeToExact=…;a2bProbeToExactBinds=…` for `fromPoint` and `toPoint`, formatted like the ordinals (S:19858-19864). Nothing else changes.
5. **Unchanged:** S:64-97, factory S:8773, consumer S:19480, the probe condition at S:20065, and every other producer (no witness).
6. **P10 tests** (compiled, not run). Use p₁ = `from_double_exact(0x1.9999999999999p-3)` on edge (1, 4):
   - `SurfaceCellAuthorityContractCutover.AcceptedBoundaryRoundingReproducesTemplatePair`: the forward and reversed outputs equal TB14A's face-0 and face-3 triples bit for bit and carry equal witnesses; p = 0 and p = 1 carry none.
   - `SurfaceCellAuthorityContractCutover.ExactInteriorWitnessBindsOnlyItsOwnRounding`: both outputs bind. Rejected: a one-ULP barycentric tamper; edge (4, 7); p₂ = `from_double_exact(0x1.9999999999998p-3)` on the face-0 point; a face without the edge; an absent witness.
   - `SurfaceCellAuthorityContractCutover.OneUlpDistinctCrossingsKeepDistinctWitnesses`: p₁ and p₃ = `from_double_exact(0x1.999999999999ap-3)` each bind only to their own output, and the witnesses are unequal.
7. **Build and record:** GMP/GMPXX compile and package. Record of 25 lines or fewer: package ID, ZIP SHA-256, source SHA, `runtimeExecution=false`.

##### RA-96.5 TB15 — `M6-CP3-TB15-R10-EXACT-I-ENDPOINT-WITNESS-PRODUCER`

The harness is derived from `m6_cp3_r10_open_rail_chain_interval_truth_table_harness.sh`, changing only sha, artifact, digest, labels and identities.

| # | Identity | Prediction |
|---|---|---|
| 1–3 | the three CB15 tests | PASS |
| 4 | `SurfaceCellAuthorityContractCutover.OpenRailRouteChainIntervalTruthTable` | PASS (control) |
| 5, 6 | the two P10 midline tests (B2, front 61/179) | RED. First failure identical to TB13A once the four new fields are removed. New fields: `none`, binds 0 (vertex 4). |
| 7, 8 | `cp3entry:2/6` | RED. Identical once the four new fields are removed. `FromExact` = `ToExact` = `1,4@n/d` with the same n/d; both binds 1; 0 < n/d < 1; ~~nearest~~ converted double `0x1.9999999999999p-3` (RA-97.2). |
| 9 | `SurfaceCellTransitionQuotient.ExactHardRailCounterpartsStitchAcrossTopologyRegions` (selector 217, chi 0) | as #7/#8 |

Falsifiers, each sent to Review:
- any byte change outside the four fields (CB15 changed behavior);
- a witness on #7–#9 that is absent, unbound or unequal (the U6 design is wrong).

No census.

##### RA-96.6 Fixture debt and sequence

- **Sequence:** CB15 → TB15 → TB15-REV (issues the CB16 spec) → CB16 → TB16 → TB16-REV (issues the CB17 spec) → CB17 (U4) → TB17 → CB18 (U5) → TB18.
- **Fixture debt** (RA-92.3, RA-93.3) follows TB18. These are test-only CB/TB pairs in the order 242 → 174 → 250 → adjacent-sheet helper → 191 family → 442. Then one census, then the RP-01 Review.
- Accounting unchanged.

---

### RA-97 — TB15 reviewed: the witness is p = 1/5, bound on both sides; CB15 accepted; CB16 rule specified (2026-10-18)

**Turn:** `M6-CP3-TB15-R10-EXACT-I-ENDPOINT-WITNESS-PRODUCER-REV`. **Inputs:**
- CB15 source `e4785d734e35d2f01ca3ee8099772f6ab5257f4c` (HEAD `src/include/tests` identical) and package `12150973440`;
- TB15 result `12152685129`.

`S:` lines below are at `e4785d73`. **Amends:** RA-95.3 (last sentence), RA-96.5 (#7 wording) and RA-96.6 (sequence).

#### RA-97.1 Re-verification

- **CB15 package.** ZIP `7f56c6a5…c073` reproduced; 28/28; build exit 0; source status empty. The packaged S, H and P10 are byte-identical to `e4785d73` and to HEAD.
- **CB15 diff from `2ee499a3`.** H +10, S +138/−27, P10 +119; nothing else under `src/include/tests`.
  - `accepted_boundary_trace_point` is the old lambda body moved verbatim, plus the A1 witness. The lambda now forwards to it.
  - Unchanged: the checkers (S:148-182), the factory call (S:8857) and the consumer call (S:19545).
  - Dedup follows A2. The probe fields follow the `railEnd` loop.
- **TB15.** ZIP `2536c38b…f748` reproduced; 13/13 manifest; 9/9 selected, 0 missing.
  - Harness `b3aa46de…` differs from TB13A's only in the pin and the identity list.
  - #1–#4 PASS.
  - #5/#6: `none`, binds 0.
  - #7–#9: `1,4@1/5` on both sides, binds 1/1.
- **Byte comparison.** With only the four new fields removed, #5–#8 are byte-identical to TB13A cases 3–6, and #9 to TB14A `raw/selector/ordinal-217.log`. Every RA-96.5 prediction held, and no falsifier fired.
- **The B3 record passes every later consumer condition:** A3 present, span 3 on both sides, reciprocal ordinals 0→1 / 1→0, rail 2. The only failing condition at front 17/203 is `same_interior_carrier_point`.

#### RA-97.2 Owned Review error: p = 1/5

- **The error.** RA-95.3 inferred "p ≠ 1/5" from `to_double(1/5) = 0x1.999999999999ap-3`. That premise is false in the GMP build.
  - `FieldExactRational::to_double` calls `mpq_class::get_d()` (`include/directional/numerics/ENumberGMP.h:147`), which truncates toward zero. So `to_double(1/5) = 0x1.9999999999999p-3`.
  - RA-96.5's "nearest double" repeats the error. The agent's wording correction (`c03f31baa`) is accepted.
- **The measured value.** p = 1/5 = j/count, with j = 1 and count = 5.
  - The record's other accepted samples (2/5, 3/5, 4/5) are truncated the same way.
  - Truncation is the source of the 2⁻⁵⁵: face 0 stores trunc(1/5) beside round(1 − trunc(1/5)).
  - The rest of RA-95.3 stands.
- **Consequence for the design.** The bit binding is specific to the backend's conversion.
  - Producer and checkers share one binary and one helper, and the witness is never serialized, so they agree.
  - Any future persistence of the witness must not bind across backends.

#### RA-97.3 CB15 accepted; binding proves consistency, not identity

- **Accepted.** CB15 makes no admission change.
- **Binding proves consistency, not identity.** `to_double` is many-to-one, so two distinct rationals with equal conversions bind the same doubles. One example: 1/5 and `from_double_exact(0x1.9999999999999p-3)`.
  - Identity therefore comes only from comparing the exact witnesses.
  - A bound pair must decide **both ways**. Otherwise the legacy rule, which compares doubles, accepts two distinct crossings whose rounded doubles coincide. That happens in the reversed form, which has an exact unit sum.
- **No later writer to check.**
  - Nothing rewrites a witnessed point: S:13602 is the periodic-chart locator in another producer, and S:20903 seeds streamlines.
  - No product digest covers `SurfaceTracePoint`.
- **One predicate serves all three sites.** `same_interior_carrier_point` (S:175-182) is called by the factory (S:8857), the consumer (S:19545) and the probe (S:20130). Changing it alone keeps all three in lockstep.
- **Limit.** The factory call still has no real-data coverage until a fixture reaches `make`.

#### RA-97.4 CB16 specification — `M6-CP3-CB16-R10-EXACT-I-ENDPOINT-WITNESS-CHECKERS`

1. **Rule.** Change `same_interior_carrier_point` only:
   - (a) If either point carries a witness for which `exact_interior_witness_binds(point, faces, edge)` is false, return false. A witness that contradicts its doubles is corruption, so this fails closed.
   - (b) If both points carry witnesses, which by (a) are bound, return `*first.exactEdgePoint == *second.exactEdgePoint`. The legacy parameter is not consulted.
   - (c) Otherwise (no witness, or exactly one), apply the legacy rule unchanged. Cross-producer and witness-cleared pairs keep today's rule; nothing is weakened.
2. **Declaration.** Declare `same_interior_carrier_point` in H beside the CB15 helpers. Its signature does not change.
3. **Probe label** (S:20130-20133), inside the existing branch only:
   - `exact-witness-unbound` when (a) rejects;
   - `exact-witness-mismatch` when (b) rejects;
   - the existing labels otherwise.
4. **Unchanged:**
   - `interior_carrier_parameter`, the CB15 helpers, dedup and every producer;
   - every other guard at the three sites: orientation, A3, intervals, rail, contact paths and the terminal branches.
5. **Tests** (P10; compiled, not run). Let p = `from_ratio(1,5)` and q = `from_double_exact(double(p.to_double()))`, and assert q ≠ p.
   - `ExactWitnessIdentifiesTemplateInteriorPair`:
     - the face-0 forward point and face-3 reverse point built from p give true;
     - with both witnesses reset they give false, which reproduces B3.
   - `ExactWitnessRejectsDistinctValuesWithEqualDoubles`:
     - face-3 reverse points built from p and from q have bit-equal doubles and both bind, yet give false;
     - with both witnesses reset they give true. This is the hole the rule closes.
   - `ExactWitnessUnboundFailsClosedAndMixedKeepsLegacy`. Each of these gives false:
     - a `nextafter` applied to one witnessed point;
     - a witness on edge 4–7 checked against carrier 1–4;
     - the forward point with its witness against the reverse point without one.

     A pair of identical reverse points with one witness reset gives true.
6. **Build.** GMP/GMPXX compile and package. Record of 25 lines or fewer.

**Out of scope:** U4/U5, fixtures, selector, harness, and running tests.

#### RA-97.5 TB16 and TB16C

**TB16** — `M6-CP3-TB16-R10-EXACT-I-ENDPOINT-WITNESS-CHECKERS`. The harness is the TB15 harness, changing only sha, artifact, digest, labels and identities. Twelve identities, in this order:

| # | Identity | Prediction |
|---|---|---|
| 1–3 | the CB16 tests | PASS |
| 4–6 | the CB15 tests | PASS |
| 7 | `OpenRailRouteChainIntervalTruthTable` | PASS |
| 8, 9 | the P10 midline B2 tests | Byte-identical to TB15 #5/#6. They fail at `carrier-orientation`, before the predicate. |
| 10–12 | `cp3entry:2/6`, selector 217 | The first failure is no longer `endpoint-1` at front 17,203. Record it verbatim and classify it by RA-90.4 with RA-91.2. Expected, not required: B2 at a later front. A PASS is admissible and is recorded. |

Falsifiers, each sent to Review:
- any change in #1–#9;
- any of #10–#12 still failing at `endpoint-1`, front 17,203;
- any `exact-witness-` label;
- `open-rail-chain-interval` anywhere.

**TB16C** — `M6-CP3-TB16C-R10-SELECTOR-497-CENSUS`, run only if TB16 holds.
- **Run:** the unchanged `m6_cp3_entry_497_artifact_only_harness.sh` (`947a95ee…`) on the CB16 package, given only through its environment inputs.
- **Deliverables:** as RA-90.5, compared against TB14A (`12141843937`) instead of R3.
- **Predictions:** every TB14A PASS stays PASS, and each of the 19 B3 identities leaves B3.
- **Falsifiers:** any PASS → RED, any `exact-witness-` label, or any B1. Each goes to Review.
- **Why a census now:**
  - CB16 changes production admission at every I–I endpoint, and RA-61.7 requires a measurement before the next rule change.
  - U4/U5 need their measured population: RA-96.3 found that their spec must be re-derived.

#### RA-97.6 Sequence

CB16 → TB16 → TB16C → TB16C-REV (re-derives and issues the CB17 U4 spec from the census) → CB17 → TB17 → CB18 → TB18 → fixture debt (RA-96.6 order) → census → RP-01 Review. Each CB follows a reviewed TB, and a falsifier goes to Review. Accounting is unchanged.

---

### RA-98 — TB16 reviewed: CB16 code accepted; the #3 falsifier is a Review spec defect; B3 cleared on the measured identities; CB16A corrects one row (2026-10-19)

**Turn:** `M6-CP3-TB16-R10-EXACT-I-ENDPOINT-WITNESS-CHECKERS-REV`. **Inputs:**
- CB16 source `1c45e89ae0ca7a072c5140aea2b95be6387ec078` (HEAD `src/include/tests` identical) and package `12154623660`;
- TB16 result `12183498229`.

**Amends:** RA-97.4 item 5 (one row) and RA-97.5/97.6 (sequence; TB16C runs on the CB16A package).

#### RA-98.1 Re-verification

- **CB16 package.** ZIP `821edfc6…9956` reproduced; 0 manifest mismatches; `source-commit` `1c45e89a`; build exit 0. The packaged S, H and P10 are identical to the commit and to HEAD.
- **CB16 diff from `e4785d73`.** It touches only S, H and P10.
  - The rule (S:175-191) follows RA-97.4 item 1 line for line.
  - The declaration is at H:1565-1568.
  - The two labels sit inside the existing probe branch (S:20139-20153).
  - No other guard or call site changed.
- **TB16.** ZIP `8a329317…2dc32` reproduced; 16/16; 12/12 selected, 0 missing.
  - **#3** fails exactly twice, at P10:9463-9464, on the `corrupted` row. Its other five assertions hold.
  - **#8/#9:** the complete first-failure records are byte-identical to TB15 #5/#6. RA-97.5's "fail at `carrier-orientation`" names `a2bProbeFirstFailedCondition`; the predicate is `endpoint-1`.
  - **#10–#12:** the first failure moved to `endpoint-1` at front 97/283. Both ends are one-hot at vertex 4 (face 0 `(0,0,1)`, face 7 `(1,0,0)`), with `a3ProbeDecodedVertex=4`, `ContactEndpointMember=0` and `ContactPublished=1`. The ordinals on span 3 are 4→5 / 5→4, and there is no witness. That is **B2** by RA-90.4 with RA-91.2, the RA-97.5 expectation.
  - No `exact-witness-` label and no `open-rail-chain-interval` appear.

#### RA-98.2 The #3 falsifier is an owned Review spec defect; the checker is right

- **What the mutation does.** Face 3 is (1, 7, 4). From p = 1/5 the helper gives:
  - reverse image: (`0x1.999999999999ap-1`, 0, `0x1.9999999999998p-3`);
  - forward image: (`0x1.999999999999ap-1`, 0, `0x1.9999999999999p-3`).

  `nextafter(slot 2, 1.0)` turns the reverse image into the forward image exactly.
- **Why the checker is right.** A4 (RA-96.2) binds to "one orientation" on purpose: the producer emits either image, depending on side traversal, and both represent p. The mutated point is therefore a valid image of its own witness, not a corruption, and `binds = true` and `same = true` are both correct.
- **Where the defect is.** RA-97.4 item 5 said "a `nextafter` applied to one witnessed point". It named no point, slot or direction, and Review did not check the mutation against both images. CB15's own row survives only because forward slot 2 toward 1.0 gives `…9ap-3`, which matches neither image. The localization in the TB16 report is confirmed.
- **No code change.** Swapping one valid image for the other changes no identity, because identity is the exact witness (RA-97.3).
- **Not weakening.** The replacement keeps the row's intent with a genuine corruption, and pins the measured image swap as an accepted property.

#### RA-98.3 CB16 accepted; B3 status

- **CB16 accepted.**
- **B3 is cleared on the three measured identities.** They now stop at B2 at vertex 4, the same shape as the P10 midline tests at front 61/179.
- **The other 16 B3 identities** share the template (RA-95.2) and are predicted to move the same way. TB16C measures it.
- **Limit.** The factory call still has no real-data coverage.

#### RA-98.4 CB16A — `M6-CP3-CB16A-R10-EXACT-I-WITNESS-UNBOUND-ROW` (test-only)

In `ExactWitnessUnboundFailsClosedAndMixedKeepsLegacy` (P10:9444; the `corrupted` row is at P10:9461-9464):

1. Let `forwardInFace3 = accepted_boundary_trace_point(faces, 3, 1, 4, *p, edge)`, and assert it is present.
2. Change the mutation to `std::nextafter(corrupted.barycentric[2], 0.0)`, which gives `0x1.9999999999997p-3`. Before the two existing `EXPECT_FALSE` rows, assert that the corrupted slot 2 differs bit for bit from slot 2 of both `*reverse` and `*forwardInFace3`. Keep both `EXPECT_FALSE` rows.
3. Add the accepted property. Let `otherImage = *reverse` with `otherImage.barycentric = forwardInFace3->barycentric`, keeping the witness. Then:
   - `EXPECT_TRUE(exact_interior_witness_binds(otherImage, faces, edge))`;
   - `EXPECT_TRUE(same_interior_carrier_point(*reverse, otherImage, faces, edge))`.

No other row, test or production line changes. GMP/GMPXX compile and package. Record of 25 lines or fewer: package ID, ZIP SHA-256, source SHA, `runtimeExecution=false`.

#### RA-98.5 TB16A and TB16C

**TB16A** — `M6-CP3-TB16A-R10-EXACT-I-ENDPOINT-WITNESS-CHECKERS`.
- **Harness:** the TB16 harness, changing only sha, artifact, digest and labels. The same 12 identities, in the same order.
- **Predictions:** #1–#7 PASS. #8–#12 have first-failure records byte-identical to TB16.
- **Falsifiers:** any other outcome. Each goes to Review.

**TB16C** — `M6-CP3-TB16C-R10-SELECTOR-497-CENSUS`, as RA-97.5 but on the **CB16A** package, and only if TB16A holds.
- **Predictions:**
  - every TB14A PASS stays PASS;
  - all 19 B3 identities leave B3. They are expected, not required, to become B2.
- **Falsifiers:** unchanged from RA-97.5.

#### RA-98.6 Sequence

CB16A → TB16A → TB16C → TB16C-REV (re-derives and issues the CB17 U4 spec from the census) → CB17 → TB17 → CB18 → TB18 → fixture debt (RA-96.6 order) → census → RP-01 Review. Accounting is unchanged.

#### RA-99 — CB16A patch reviewed: it conforms; the compile has not run; resume authorized (2026-10-19)

**Turn:** `M6-CP3-CB16A-R10-EXACT-I-WITNESS-UNBOUND-ROW-PATCH-REV`. **Inputs:** HEAD `0fdc5e9c9`; patch commit `7cfa5b4612ed67ec0bbddb747edbc6c53076b781` (drive-apply [run 39256723348](https://github.com/akashskypatel/Directional/actions/runs/39256723348), patch SHA-256 `437fc495…b74a`). STATUS is CB16A `IN_PROGRESS`, successor itself.

- **RA-99.1 The patch conforms.** `git diff 1c45e89a 7cfa5b46 -- src include tests` touches only P10 (+13/−1), and those lines are exactly RA-98.4 items 1–3. No production line changed. `<bit>` and `<cstdint>` are already included (P10:12, P10:15).
- **RA-99.2 Static evaluation, in exact arithmetic.** This predicts TB16A #3; it is not a runtime claim.
  - `to_double(1/5)` truncates to `…99p-3`. Face 3 reproduces slot 2 as `…98p-3` (reverse) and `…99p-3` (forward). The mutation gives `…97p-3`.
  - The binding compares the three barycentrics with those two reproductions (S:125-143). `SurfaceTracePoint` has only `face`, `barycentric` and the witness (H:91-96), so `otherImage` is the forward image in full.
  - Therefore both `EXPECT_NE` rows hold; `corrupted` binds to neither image, so both `EXPECT_FALSE` rows hold; `otherImage` binds and carries the same witness, so both `EXPECT_TRUE` rows hold.
- **RA-99.3 The turn is incomplete, not failed.** No compile request follows the patch; the latest dispatcher run is the drive-apply. CB16A is not accepted until its package is verified.
- **RA-99.4 Resume, compile only.** Same turn ID. Do not re-apply or edit the patch. The compile request uses `source_sha` `7cfa5b4612ed67ec0bbddb747edbc6c53076b781`, the eight CB16 targets and the prefix `directional-m6-cp3-cb16a`. The record (25 lines or fewer) gives the package ID, ZIP SHA-256, source SHA and `runtimeExecution=false`. TB16A, TB16C and the sequence are unchanged (RA-98.5/98.6).

#### RA-100 — CB16A accepted; TB16A inputs pinned (2026-10-19)

**Turn:** `M6-CP3-CB16A-R10-EXACT-I-WITNESS-UNBOUND-ROW-REV`. **Inputs:** HEAD `abe261709`; compile [run 39266100202](https://github.com/akashskypatel/Directional/actions/runs/39266100202), package `12193816372`; record `Architecture_M6_CP3_CB16A_Exact_I_Witness_Unbound_Row_Code_Build_Record_20261019.md`.

- **RA-100.1 Re-verification.**
  - ZIP SHA-256 `113a5d8d783dc77f6b60a4da7c338478b3bd753a7e342b01169e4115dc77b2a3` matches.
  - Root manifest 28/28 OK (SHA-256 `f5ebf229a8ac9fad6a8797aefb36d8acb34a7e7441bb8dd9edb9858b4dfbf556`). Source archive SHA-256 `85d487e45086eb0a111207f790e67dcf7069517f1f06f3b3620573d56e29106b`. `source-commit` is `7cfa5b46`.
  - Preflight and build exit 0; the eight targets; `DIRECTIONAL_ENABLE_GMP=ON`, gmp/gmpxx linked; `runtimeExecution=false`; all five source-status files empty.
  - The packaged `src`, `include`, `tests` and `CMakeLists.txt` are byte-identical to git `7cfa5b46`. The compile request differs from CB16's only in its id, mailbox, source SHA and prefix.
- **RA-100.2 CB16A is accepted.** No source line changed after the RA-99 review.
- **RA-100.3 TB16A** (`M6-CP3-TB16A-R10-EXACT-I-ENDPOINT-WITNESS-CHECKERS`; refines RA-98.5).
  - **Harness:** the TB16 harness (SHA-256 `f8db713e…769b`), with only lines 7–9 changed (`sha` `7cfa5b4612ed67ec0bbddb747edbc6c53076b781`, `artifact` `12193816372`, `digest` `113a5d8d…b2a3`) and the `TB16_` output labels renamed `TB16A_`. The four pinned selector hashes (lines 49–52) stay unchanged; they still match at `7cfa5b46`. The same 12 identities, in the same order.
  - **Predictions:** #1–#7 PASS. #8–#12 RED, with `first_failure` byte-identical to TB16 result `12183498229`.
  - The 13 inserted P10 lines cannot move that field. It is the first runtime `predicate=` or `producer failed:` line, which carries no `file:line`, and the two P10 diagnostics (P10:7268, P10:7316) sit above the insertion.
  - **Falsifiers:** any other outcome goes to Review. A RED #3 also falsifies RA-99.2.
- **RA-100.4 TB16C**, only if TB16A holds: the unchanged census harness (`947a95ee…79dd`), run with `--execute` and:
  - `CANDIDATE_ARTIFACT_ID=12193816372`;
  - `EXPECTED_SOURCE_SHA=7cfa5b4612ed67ec0bbddb747edbc6c53076b781`;
  - `EXPECTED_CANDIDATE_ZIP_SHA256=113a5d8d783dc77f6b60a4da7c338478b3bd753a7e342b01169e4115dc77b2a3`;
  - `EXPECTED_ROOT_MANIFEST_SHA256=f5ebf229a8ac9fad6a8797aefb36d8acb34a7e7441bb8dd9edb9858b4dfbf556`;
  - `EXPECTED_SOURCE_ARCHIVE_SHA256=85d487e45086eb0a111207f790e67dcf7069517f1f06f3b3620573d56e29106b`.

  Deliverables, classification and predictions are as in RA-97.5/RA-98.5, compared with TB14A.
- **RA-100.5 Sequence** (unchanged): TB16A → TB16C → TB16C-REV (CB17 spec) → CB17 → TB17 → CB18 → TB18 → fixture debt → census → RP-01 Review.

#### RA-101 — TB16A reviewed: every prediction held; the U6 gates are closed; TB16C deliverables pinned (2026-10-19)

**Turn:** `M6-CP3-TB16A-R10-EXACT-I-ENDPOINT-WITNESS-CHECKERS-REV`. **Inputs:** HEAD `28b55522e`; TB16A [run 39277232731](https://github.com/akashskypatel/Directional/actions/runs/39277232731), result `12198063461`; harness `m6_cp3_tb16a_exact_i_endpoint_witness_checkers_harness.sh` (SHA-256 `20b2ebd8…afea`); report `Architecture_M6_CP3_TB16A_Exact_I_Witness_Checkers_Harvest_Report_20261019.md`.

- **RA-101.1 Re-verification.**
  - ZIP SHA-256 `7f8769edbddc8439662526ca9520919ad78888b31a12abdd9548d476edd06cba` matches; manifest 16/16. Immutability: package, source, execution view and frozen selectors all true. 12 planned, 12 executed, 0 missing; compile, relink, benchmarks and selector497 all false.
  - The harness differs from TB16's only in lines 7–9 and the two labels.
  - #1–#7 PASS. The #3 log runs the corrected test, reports `OK`, and has no failure line.
  - #8–#12: the ledger `first_failure` fields match TB16's, but the ledger truncates at 600 characters. The full first predicate lines in the raw logs (6,972–9,565 bytes) are also byte-identical to TB16's.
- **RA-101.2 The U6 gates are closed.** All six U6 tests and the U3 truth table pass on one package. B3 status is unchanged from RA-98.3: cleared on the three measured identities, with 16 left for the census. The factory rule still has no real-data coverage; that needs an open-rail fixture that reaches `make`.
- **RA-101.3 TB16C can run.**
  - No test identity was removed since CB14A (1,231 → 1,237; the six new ones are CB15's and CB16's tests).
  - All 491 selector-file names exist at `7cfa5b46`. The selector files and the census harness are unchanged since TB14A.
  - The baseline is TB14A's `combined-ledger.tsv` in artifact `12141843937` (ZIP `1b06e43e…d455`), which **expires on 2026-11-01**. TB16C therefore commits its comparison as a TSV, so the baseline survives the artifact.
- **RA-101.4 TB16C deliverables** (refines RA-97.5, RA-98.5 and RA-100.4). The run is as RA-100.4.
  1. `Architecture_M6_CP3_TB16C_Selector_497_Red_Inventory.tsv`, one row per TB16C RED, with columns `phase, ordinal, identity, owner, exit, raw_sha256, class, first_failure (≤200 chars), TB14A (PASS/RED), TB14A_first_observable`.
  2. **Classification:** RA-90.4 with RA-91.2, applied to each RED's first `firstPredicate=` text, or its first gtest failure line when there is none. Class **U6** for any `exact-witness-unbound` or `exact-witness-mismatch`.
  3. A report of 30 lines or fewer giving:
     - totals per phase (30/12/449/6) and the count per class;
     - the TB14A PASS → RED list and the TB14A RED → PASS list;
     - the class of each of the 19 RA-95.2 B3 identities, by name;
     - the TSV's SHA-256.

     No interpretation.
  - **Predictions:** every TB14A PASS stays PASS, so there are at least 425 PASS. Each of the 19 leaves B3; becoming B2 is expected, not required.
  - **Falsifiers:** any PASS → RED, any U6 class, any B1, or any of the 19 still in B3. TB16C-REV follows in every case.
- **RA-101.5 Sequence:** TB16C → TB16C-REV (re-derives and issues the CB17 U4 spec from the census) → CB17 → TB17 → CB18 → TB18 → fixture debt → census → RP-01 Review.

## `Architecture_M6_CP3_TB11_Route_Anchor_Review_Decision.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_TB11_Route_Anchor_Review_Decision.md`; moved verbatim.

### RA-85 — TB11 reviewed: the RED is RP-01, not U1; I–I must be admitted; plan realigned

**Turn:** `M6-CP3-TB11-R10-OPEN-RAIL-ROUTE-ANCHOR-REV` (Review + Plan after a red TB, Turn_Cadence rule 4). **Subjects:**
- CB11 source `9432aa05e`, compile artifact `12121016836`;
- TB11 run `39092477302`, result `12123605663`.

**S** = `src/geometry/SurfaceCellTracing.cpp` at HEAD.

#### RA-85.1 U1 implemented to specification

- **Helper equivalence:** `open_rail_route_anchor_valid` is a faithful extraction. The old rejection condition `(both && (!fwd && !rev || !pair)) || (!both && !(single0 || single1))` is the exact negation of the helper's result.
- **Same inputs:** the consumer looks up the same rail key (`*first.railId`) and passes the same two endpoint certificates that it pushes and that `make` re-checks.
- **Test evidence:** the truth table passed at runtime.
- **Factory forgery test:** `CheckedFactoryRejectsOpenRailWithClearedTerminalAnchor` was never reached, so it is not evidence either way.

#### RA-85.2 The RED predates CB11 — Review error owned

The "control" `ProducedOpenRailInteriorEndpointPreservesExactTerminalGuard` has never been `Produced`:
- The R4 interior-witness TB of 2026-10-15 measured its precondition failing upstream with `no-exact-terminal-corner`.
- The midline fixtures are in the RP-01 RED set (e.g. `M6CP3.HardRailCrossRegionBranchCertificateStripsEndpointFaceGauge`, R4 endpoint census row 38).

RA-83.4, R10B §5, RA-84 and the CB11 specification all called it an unchanged `Produced` control without citing a run. That premise was false. TB11 is a valid semantic run that measured an already-RED test; **no regression**.

#### RA-85.3 New finding: the first failure is now an I–I front

TB11 locus: `open-rail-route-anchor`, rail 2, front 29/147, route length 1, edge 1–4, faces 0|3. Deduction:
- Both endpoint certificates exist, otherwise the locus would be the endpoint.
- Vertex 1 is a contact terminal touching edge 1–4, so neither endpoint is T. Vertex 4 is not a contact.
- The consumer's I branch requires a strict interior point.
- Therefore both ends are I.

In the fixture (3×3 grid, rail 1–4–7, edge 1–4 between faces 0 and 3), iso-lines cross the rail part-way along edges. Middle segments of a subdivided rail are therefore **I–I by construction**. Before CB11 the consumer pushed this front and failed later, at vertex 4. U1 now stops at it first.

**Consequence:** RA-84's matrix row "I–I: reject in both" would keep every subdivided open rail RED even with R admitted. RA-84.5 would have ended at a RED TB14. **RA-84.1's I–I clause and R10B §3's I–I rejection are withdrawn.**

#### RA-85.4 Corrected route rule: open-chain interval

The factory's "at least one published terminal" (S:8576-8615, now the helper) was a stand-in for rail membership; the open chain witnesses membership directly. Closed rails already admit local routes without any terminal, by chain contiguity alone (`make`, closed-chain branch). Open rails get the same rule, non-cyclic:
- the route's ordered step edges are a contiguous interval of the named rail's published open chain, in either direction;
- each endpoint passes its own T, R or I predicate;
- a T endpoint is the chain end at its side, and that chain end is the end of the interval.

Effect:
- T–T and T–I fronts that follow the rail are unchanged. The junction check (`hardSpokes == 2`) already confines them to the rail.
- I–I is admitted. T–R, I–R and R–R stay conditional on the RA-84.4 R clauses.
- Shapes that are not a contiguous interval, or that end at a misplaced T, are rejected by both checkers.

Trust root as RA-84.2.

#### RA-85.5 Realigned unit order (supersedes RA-84.5)

| Unit | Turn | Scope |
|---|---|---|
| U1 | CB11/TB11 | Done; kept as the single route-rule site. |
| U2 | `M6-CP3-CB12-R10-OPEN-RAIL-CHAIN-PROVENANCE` | RA-84.5 U2 scope. No `Produced` open-rail fixture exists, so validation is a pure, directly tested helper, and the positive case uses the real rail builder. |
| U3 | `M6-CP3-CB13-R10-OPEN-RAIL-CHAIN-INTERVAL-ROUTE` | RA-85.4 in the shared helper, for both checkers. |
| U4 | `M6-CP3-CB14-R10-FACTORY-RAIL-VERTEX-ENDPOINT` | Was U3. |
| U5 | `M6-CP3-CB15-R10-CONSUMER-RAIL-VERTEX-ENDPOINT` | Was U4. |

Each CB is followed by its TB; a red TB goes to Review.

**Falsifiable predictions:**
- **TB12:** the TB11 locus is unchanged (no behaviour change).
- **TB13:** front 29/147 passes, and the first failure moves to a vertex-4 endpoint (`no-exact-terminal-corner`).
- **Falsifier:** 29/147 still fails, or any T–T/T–I truth-table row changes.

Only U2 is authorized.

#### RA-85.6 Documentation

- The TB11 tracker section's "rejects retained Produced control" is corrected in place.
- One lesson added to `LESSONS.md` §2.
- TB11 left STATUS `IN_PROGRESS`; this Review closes it.

Accounting unchanged: 66/17/49, debt 1, CP2 491/491, R3 403/497, selector 497; `RP-01` open, `RP-02` UNREACHED, Gate C suspended.

## `Architecture_M6_CP3_TB12_Chain_Provenance_Review_Decision.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_TB12_Chain_Provenance_Review_Decision.md`; moved verbatim.

### RA-87 — TB12 reviewed: U2 closed; a third RP-01 blocker has no unit; CB13 specified; selector census added

**Turn:** `M6-CP3-TB12-R10-OPEN-RAIL-CHAIN-PROVENANCE-REV`. **Subjects:** TB12 run `39103358061`, result `12127706461`, on CB12 package `12125223513`. **S** = `src/geometry/SurfaceCellTracing.cpp`, **P10** = `tests/SurfaceCellsPhase10Tests.cpp`, **TQ** = `tests/SurfaceCellTransitionQuotientTests.cpp`.

#### RA-87.1 TB12 adjudicated: every prediction held; U2 is closed

Independently re-verified from the result artifact:
- ZIP SHA-256 `1b6c3babd942cfc7fc7bbeff94774bf719297fdb9bc7ca3c0088e40110f2dfee`; 0 manifest mismatches; 6 executed, 0 missing; postflight passed.
- The harness differs from TB11's only in the RA-86.1 deltas.
- Gates #1 and #2 PASS.
- #3 and #4 are byte-identical to TB11's predicate.
- #5 and #6 carry `firstPredicate=`, and `PublishedProductRejected` occurs 0 times, so the CB12 falsifier is absent.

**Limit:** neither diagnostic reaches `make`, so the CB12 validator still has no runtime coverage on real data. It remains accepted on the construction argument of RA-86.2.

#### RA-87.2 New finding: the full-pipeline RP-01 identities stop at an inexact I endpoint (B3)

#5 and #6 (`cp3entry:2` and `:6`) first fail at `endpoint-1`, locus 3 (`EndpointAttachment`), front 17/203, edge 1–4. The first failed condition is `not-same-interior-carrier-point`.
- The two sides are the same point, (1, 0.2) on edge 1–4.
- **Face 0's barycentric pair sums to exactly 1 + 2⁻⁵⁵** (checked with exact rationals); face 3's sums to exactly 1.
- `interior_carrier_parameter` (S:64-89) requires an exact unit sum, so face 0 is rejected before the two parameters are ever compared.

This is the RA-61.6 mechanism. R9B's I clause deliberately left it open: RA-76 measured 324 same-edge parameter pairs that differ by one ULP, and R9B forbids tolerances and requires "a separate independent exact producer-origin witness". RA-63.5 withdrew interval-only identity, because the interval pins the edge and not the point. **No unit in RA-85.5 addresses B3.**

#### RA-87.3 Realignment

RP-01 has three blocker shapes:

| Shape | What blocks | Unit |
|---|---|---|
| **B1** | I–I fronts rejected by the anchor | U3 |
| **B2** | R endpoint at an interior rail vertex | U4/U5 |
| **B3** | inexact I parameter | none until now |

RA-85.5's end state, a Review after TB15, cannot close RP-01, because `cp3entry:2/6` stay RED at B3. **U6 is added:** an exact I-endpoint parameter, designed first in a documents-only DEFN. U6 constraints:
- no epsilon, rounding, or canonicalization from near-equality (RA-60.11, R9B);
- the parameter must come from producer-origin exact data;
- the rule must be checked for satisfiability against TB12's actual doubles (RA-61.7).

The frozen selector was last measured at R3, source `d82e34427`, 67 source commits ago. None of its 403 PASSes is a measured control today (LESSONS §2). A census follows TB13, on the same package, to give U4–U6 measured controls and to count how many records each blocker shape owns.

#### RA-87.4 CB13 specification — `M6-CP3-CB13-R10-OPEN-RAIL-CHAIN-INTERVAL-ROUTE` (U3)

1. **Helper.** Add a pure helper `surface_cell_tracing_detail::open_rail_route_interval_valid(steps, firstVertex, lastVertex, chain)`, where `steps` is the ordered `SourceEdgeTopologyKey`s and the endpoint vertices are `optional<SourceVertexId>`.
   - It returns true iff some start `s` and direction `d ∈ {+1, −1}` satisfy all of:
     - `e = s + d·|steps|` lies in `[0, n−1]`, with no wrap-around;
     - every `steps[k] = key(chain[s+d·k], chain[s+d·(k+1)])`;
     - `firstVertex` ⇒ `firstVertex == chain[s]` and `s ∈ {0, n−1}`;
     - `lastVertex` ⇒ `lastVertex == chain[e]` and `e ∈ {0, n−1}`.
   - Empty `steps` or `n < 2` returns false.
   - It replaces `open_rail_route_anchor_valid`, which is deleted along with its declaration.
2. **Factory** (S:8667-8679). For an open rail, look up `hardRailOpenChains`. A missing chain or a false result is `InvalidSourceAuthority`.
3. **Consumer** (S:20308-20315). The same helper runs over `routeSteps`. A missing chain or a false result is `invalid_route(TerminalCarrier, -1, -1, "open-rail-chain-interval")`.
4. **Entry validator** (S:8269). Delete the empty-map exemption, so a non-empty contact set requires an exact chain map. Empty contacts with empty chains stays valid.
5. **Comment.** Correct the factory I-branch comment (S:8764-8765): rail membership is witnessed by the chain interval checked above.
6. **Test plumbing** (RA-86.5.2/.3). Every hand-built input that carries terminal contacts must also carry the real open chains:
   - `build_fixed_plan_rectangular_hard_rail_network` (P10:6412-6440): when `contacts` is given, take the chains from `hard_rail_source_provenance_from_rails` over the same rails;
   - the P10:6394 rebuild, `PhaseFrontDraft`/`phase_front_draft()` (TQ:1775-1862), and every other direct `make` call with non-empty contacts (P10 :2542 :7208 :7247 :7432 :7457 :8999; TQ :350 :1991 :2673 :2783 :3105 :8871 :8973 :9120; `FlowRepStrandsPhase15Tests.cpp:103`) pass the chains from the product accessor or that projection;
   - a negative test may tamper only the input it names.
7. **Tests** (compiled, not run).
   - Replace `OpenRailRouteAnchorTruthTable` with `SurfaceCellAuthorityContractCutover.OpenRailRouteChainIntervalTruthTable` over chain `[1,4,7]`. True rows:
     - `[1-4]`: T1–I, I–T1, and I–I;
     - `[1-4, 4-7]`: T1–T7 and I–I;
     - chain `[1,4]`, step `[1-4]`: T1–T4.

     False rows:
     - `[1-4, 4-7]` with T7–T1;
     - ~~`[4-7, 1-4]`~~ — amended by RA-88.2: this is the valid reverse walk 7→4→1, so it is a true row;
     - `[1-4]` with first T7, and with first T4;
     - `[1-7]`;
     - an empty route.
   - In `OpenHardRailChainProvenanceIsSourceValidated`, the "optional legacy input" expectation flips to false, and an empty/empty case is added and expected true.
8. **Out of scope:** R or I admission (U4–U6); probes; selector, harness or workflow changes; running tests. GMP/GMPXX compile and package as before.

#### RA-87.5 TB13 and TB13C

**TB13 (focused).** The harness is derived from TB12's, changing only sha, artifact, digest and identities.

| # | Identity | Role | Prediction |
|---|---|---|---|
| 1 | `OpenRailRouteChainIntervalTruthTable` | gate | PASS |
| 2 | `OpenHardRailChainProvenanceIsSourceValidated` | gate | PASS |
| 3, 4 | the P10 midline tests | diagnostic | RED, and the first failure is no longer front 29/147. Predicted: an endpoint (locus 3) at decoded vertex 4, i.e. B2 (RA-85.5). |
| 5, 6 | `cp3entry:2/6` | diagnostic | `first_failure` byte-identical to TB12's (B3) |

Falsifiers for U3:
- `open-rail-chain-interval` appears anywhere;
- #3 or #4 still names front 29/147.

If the new first failure is B3 rather than B2, U3 still holds and only the U4–U6 order changes.

**TB13C (census) — `M6-CP3-TB13C-R10-SELECTOR-497-CENSUS`.**
- Run the unchanged `m6_cp3_entry_497_artifact_only_harness.sh` (SHA-256 `947a95ee…79dd`) on the CB13 package.
- Report the totals and every RED identity's first `predicate=`/`producer failed:` line, sorted into B1/B2/B3/other.
- List every identity that passed at R3 (result `11661044443`) and is RED now, with its first failure.
- No interpretation; the Review interprets.

#### RA-87.6 Sequence

CB13 → TB13 → TB13C → Review, which orders U4/U5/U6 → `DEFN` U6 → … Each CB follows a reviewed TB. RA-86's record is folded; its live clauses are carried by RA-87.4.

## `Architecture_M6_CP3_TB13C_Census_Review_Decision.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_TB13C_Census_Review_Decision.md`; moved verbatim.

### RA-91 — TB13C census reviewed: RP-01 owns 30 of the 497; 8 new REDs since R3; retained-package bisect next (2026-10-18)

**Turn:** `M6-CP3-TB13C-R10-SELECTOR-497-CENSUS-REV`. **Input:** TB13C run `39127652521`, result `12136761296` (ZIP SHA-256 `92d9c9bd4d05ac7bf4ef06e402fa0b44fbeeb46d27a0b4c0b1994236632bf545`) on CB13A package `12132184878`. **Amends:** RA-90.4 (B2 rule). **Amended by:** RA-92 (`Architecture_M6_CP3_TB13D_Bisect_Review_Decision.md`), covering RA-91.3's curved-disk status and RA-91.4's U4–U6 hold. **S** = `src/geometry/SurfaceCellTracing.cpp`.

#### RA-91.1 Closeout and re-verification

- TB13C stopped after its dispatch, leaving STATUS `IN_PROGRESS` with itself as successor and no inventory, report or docs. The run itself had completed. As in RA-89, Review verifies the run and closes the turn out; no implementation work remains.
- The ZIP hash equals the provider digest; `SHA256SUMS` 1019/1019 OK. The harness was `947a95ee…` with exactly the RA-89 inputs. 497 executed, `orchestration_failure=false`, `selection_integrity=true`, package/source/execution-view censuses unchanged, 28/28 after; compile, relink and benchmarks false.
- Totals: focused30 15/30, focused12 10/12, selector449 395/449, cp3entry 0/6 → **420/497 PASS, 77 RED** (R3: 403/497).

#### RA-91.2 Classification

- Review built `Architecture_M6_CP3_TB13C_Selector_497_Red_Inventory.tsv` from the raw logs (77 rows, SHA-256 `8d2b02b7de6b807784bd42921394e86f6d3b274ac07978e4aa4e937c20afa47d`). Every raw-log hash matched the red ledger.
- **Rule correction (owned Review defect).** RA-90.4's B2 rule also matched selector 405, whose fixture publishes no terminal contact (`a3ProbeContactPublished=0`, `a2bProbeFailure=missing-terminal-or-closed-rail-provenance`). There, "not a contact endpoint" is vacuously true. B2 now also requires `a3ProbeContactPublished=1`, and 405 is `other`.
- Counts:
  - B1 0 (falsifier absent);
  - B2 11, all at front 61/179 with decoded vertex 4;
  - B3 19, all at front 17/203;
  - B2+B3 0;
  - other 47.

  The prediction held: `cp3entry` 2 and 6 are B3.
- **RP-01's measured footprint is 30 identities.** All are on rail 2 of the midline-rectangle family, and all were RED at R3 (`A4_ROUTE_CERTIFICATE_REJECTION`). Each blocker is one shape: U4/U5 (B2) can move 11, and U6 (B3) can move 19. The 19 are 9 in focused30, 2 in focused12, `cp3entry` 2 and 6, and 6 in selector449.

#### RA-91.3 Against R3

- **25 R3 RED → PASS** are accepted as measured PASS controls. Twenty of them had their test bodies edited after R3. The dominant edit is 21 tests switching from `build_surface_cell_network` to `build_phase10_with_source_atlas`, which binds a source A3. No assertion was removed: every count is equal or one higher.
- **8 R3 PASS → RED** are new and are CANDIDATE / NON-STABLE until attributed:

| Sel | Identity (abridged) | First failure | Test changed since R3? | Status |
|---|---|---|---|---|
| 235, 236 | `CurvedBoundedDisk{IsInvariantToFaceRowEnumeration, PreservesAuthoritativeHardBoundary}` | pipeline `Rejected`, `PublishedProductRejected` | No. The bodies, `make_curved_disk_fixture` and `bind_curved_disk_atlas` are unchanged. | ~~Production regression~~. *Amended by RA-92.4: a stale fixture after the deliberate factory contract change in `c7cb5d68b`/`715fe2d66`.* |
| 294, 299 | `{Duplicate,Foreign}BoundedDiskRegionRejectsAtCheckedFactory` | the same, at the first `ASSERT`, before the post-R3 edits run | Only after the failing line | The same regression |
| 242 | `NonReciprocalSourceAdjacentIsolationSeamFailsClosed` | `Produced`; the test expects `Rejected` | Yes. `8df105b56` (2026-10-12) bound an untampered source A3. | **Test-specification defect** (below) |
| 174 | `RailBuildRejectionCarriesFailureWithoutConsumableRails` | `compute_edge_quantities(): DCEL consistency check failed` | Yes, by about ten compile-only R4 CBs | Unattributed |
| 191 | `MalformedAuthoritativeCrossingProvenanceFailsClosed` | `periodic-route fixture source A3 unavailable`, as for its R3-RED siblings 189/190/192–195 | Yes (R4, 2026-10-11) | Unattributed |
| 442 | `FieldTransportAtlas.RetainsDirectedTransitionValueForHardFeature…` | FTA:2856 `seamBuilt` false | Yes, `7e8f7cd93` (2026-10-14) | Unattributed |

- **242 is not a production fail-open.** When an atlas is present, every transport consumer reads transitions only from it:
  - `authoritative_edge_transition_lookup` (S:5389-5397);
  - its call sites at S:11757-11765, S:12310, S:15967 and S:17826.

  The test tampers `crossField.edgeTransitions`, which none of them reads, so the product correctly reflects its authority. The R3 duty, that non-reciprocal transport fails closed, now belongs to A3 construction, and this test no longer measures it. The repair is test-only and waits on attribution.
- **The curved-disk failure is the first real-data run of the checked factory on a hard-feature product, and the factory rejects it.** The typed code is kept in the failure (`publishedProductError`, S:12943-12948), but no test prints it.

#### RA-91.4 Why a bisect comes before U4–U6

- U4–U6 widen acceptance. A fixture that U4 brings to `make` would meet the same unexplained factory rejection, which would confound every TB that follows.
- The 68 source commits since R3 were mostly compile-only R4 turns, so a static trace is impractical. Retained compiled packages allow an artifact-only bisect with the unchanged harness.
- Review verified all four packages below:
  - the ZIP hash equals the provider digest;
  - the root manifest checks 28/28, the backend is GMP, `runtimeExecution=false`, and all six binaries are present;
  - all 497 identities exist exactly once in their routed binaries, and the six `cp3entry` identities exist;
  - the four frozen gate files are byte-identical to HEAD;
  - the benchmark fixture is present.

| Pkg | Artifact | Source (src commits since R3) | ZIP SHA-256 | Root manifest SHA-256 | Source archive SHA-256 | Expires |
|---|---|---|---|---|---|---|
| P1 | `11805220540` | `007585f8eac57a74e89e62a416a844e21c15fe35` (+32) | `e564eed3ea3636f1b36262dc91c29e9a65af6c229efc74e58d7935da0c07ddca` | `9da84df9cbae6152aaa06302f8a849a91bf538d29250a2959bc5be1ca63d706e` | `6519c6d4a886d09bdb915de5de0d94b7cf1edc58bfae430c521b9dea2ea19b1d` | **2026-10-20T10:36Z** |
| P2 | `11939982141` | `953f812ff1f431e3ad3af3b68a92284a7831c94a` (+54) | `2d5d1fc3f75b573307cae8af3c837da3dde2302ffdb4fe0ef3dd34d2aafeed7a` | `6c5938b9bc19377041649ce0546b86b2e6c6e2c9d6969fe01639da7baf4af203` | `3d0bf938f0bf2828ef407ceeb092254b003682336c97e83f88867efa2c3c38e9` | 2026-10-22 |
| P3 | `12121016836` (CB11) | `9432aa05ef4719cbea912ae0feb2c5508c4e497a` (+66) | `e92158729bf4cfc13432678e8a05cffba4d922feca6e902d8154a535ab1f2676` | `2c00fd10667fab2ba54c00b358281e892676cfd05186fa60d45b4fc8c75ee488` | `ed45af9cbba9a07a568f7291bb13663aebed5f333574966633fe9deb08abc64b` | 2026-10-25 |
| P4 | `12125223513` (CB12) | `b1b02d5bed43898af0708d76dcd70ada96aeecc9` (+67) | `c98ed3a509e9d1ccc1df83eaeb6112b8636bc0e7ee63b73140d789c32f38eeb6` | `6f90d5ffbdd4e4dbe1f9c5f8b010666e67a59b49abb0eff71020eef4f06782e0` | `3b131c687171ad336fc1dedb390e358ee5ce081da9107f828f54f4e97b1bffb0` | 2026-10-25 |

How the cut points split the 68 commits:
- P1 is the oldest retained package.
- P2 sits after the 2026-10-13/14 R4 fix wave and before `570c51733` (+55). By title, commits +56 to +65 are diagnostics.
- P3/P4 separate CB12 from CB13. CB13A (+68) is TB13C itself.

#### RA-91.5 TB13D specification — `M6-CP3-TB13D-R10-RETAINED-PACKAGE-BISECT`

- **Run.** Run the unchanged harness `947a95ee…` with `--execute`, four times: one dispatch per package, in the order P1, P2, P3, P4, each with that package's inputs from RA-91.4. In the dispatch request, keep `operation`, `harness_path` and `harness_sha256`. Set `turn_id` to `M6-CP3-TB13D-R10-RETAINED-PACKAGE-BISECT` and `semantic_source_sha` to that package's source. Change `request_id`, `mailbox_key`, `artifact_prefix`, `executor_sha` and `environment` per dispatch.
- **Failures.** Each package run is independent. A run that fails orchestration is recorded, rule 5 applies to that run only, and the next package still runs.
- **Deliver** a report of 25 lines or fewer. For each package, give:
  - the run ID, result artifact ID and ZIP SHA-256;
  - `orchestration_failure`;
  - totals per phase;
  - PASS or RED for each of the eight RA-91.3 identities.

  No inventory, classification or interpretation: Review builds the attribution matrix.
- **Predictions:**
  - 242 is RED at all four, because `8df105b56` and the atlas routing both precede P1;
  - the 30 B2/B3 identities are RED at all four.

  Falsifier: 242 PASS at any package, which reopens the fail-open question.
- **Out of scope:** compile, any source, test, fixture, selector or harness change, and rerunning CB13A.

#### RA-91.6 Sequence

TB13D → TB13D-REV. That Review attributes the eight regressions and specifies narrow repair turns. It then orders U4/U5/U6 using this census (B3 owns 19 and B2 owns 11) and issues DEFN-U6. Each CB follows a reviewed TB.

## `Architecture_M6_CP3_TB13D_Bisect_Review_Decision.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_TB13D_Bisect_Review_Decision.md`; moved verbatim.

### RA-92 — TB13D bisect reviewed: none of the 8 new REDs is a production regression; curved-disk control restored first (2026-10-18)

**Turn:** `M6-CP3-TB13D-R10-RETAINED-PACKAGE-BISECT-REV`. **Inputs:**
- P1 run `39132801755`, result `12138931233` (ZIP `0de1f10c334e6a2a3c1aef8be8b2f87f0b842ccf76426ee7842f260c5b112e03`);
- P4 run `39132921344`, result `12138633102` (ZIP `fba5def74ddbdc87be703d21d62d553888f5b8eb6ac3fd9efeb9903b77d62699`).

**Amends:** RA-91.3 (curved-disk status) and RA-91.4 (U4–U6 hold). RA-93 (the CB14A review) is appended and amends RA-92.7. **S** = `src/geometry/SurfaceCellTracing.cpp`; **P10** = `tests/SurfaceCellsPhase10Tests.cpp`.

#### RA-92.1 Closeout and re-verification

- TB13D dispatched P1–P4 and then stopped with STATUS `IN_PROGRESS` and no report. Review closes it out.
- **P2 (`39132852758`) and P3 (`39132886994`) were cancelled while pending.** The dispatcher's concurrency group (`agent-operation-dispatcher-${ref}`, `cancel-in-progress: false`) holds one pending run, so each later push replaced the queued one. They are not rerun, because RA-92.3 attributes both window cases statically.
- P1 and P4 each verify:
  - `SHA256SUMS` 1019/1019, 497 executed, `orchestration_failure=false`;
  - harness `947a95ee…` with exactly the RA-91.4 inputs.

#### RA-92.2 Results

- P1 (+32) 422/497. P4 (CB12) 420/497. CB13A (TB13C) 420/497.
- **P4 equals CB13A on all 497**, so CB13 (U3) changed no outcome on the frozen selector.
- P1 and P4 differ only at 174 and 442. All 25 R3 RED → PASS already pass at P1.
- Predictions held: 242 and all 30 B2/B3 identities are RED at P1 and P4.

#### RA-92.3 Attribution: test debt, no production regression

| Sel | First RED | Cause | Class |
|---|---|---|---|
| 235, 236, 294, 299 | by P1 | `c7cb5d68b` (commit 2 after R3) made `make` reject hard features that lack producer-owned rail provenance (now S:8479-8483, which fires first here). `715fe2d66` (commit 3) then requires that, when there are no contacts, the closed chains cover every hard edge (S:8529-8534). `make_curved_disk_fixture` (P10:2438) passes 8 bare boundary edges with no rails, contacts or chains. | Stale fixture after a deliberate contract change |
| 242 | by P1 | `8df105b56` tampers raw transitions that no consumer reads once an atlas is bound (RA-91.3) | Test-specification defect |
| 191 | by P1 | `7ccdcd527` (2026-10-11) routes the test through `build_periodic_route_network_with_source_atlas` (P10:4248-4268). That builder throws when `FieldTransportAtlas::make` fails, and drops the build error. The six siblings, RED at R3, fail at the same throw. | Fixture defect; the atlas error code is unknown |
| 174 | after P1, by P4 | `18357617a` (2026-10-14) adds a source mesh where three faces share edge (0,1) and calls `TriMesh::set_mesh`, which throws the DCEL consistency exception | Test-fixture defect |
| 442 | after P1, by P4 | `b9f70f3fe` (2026-10-13) adds a seam block that has never run. It fails at its first `ASSERT` with `SingularityMismatch` at source edge (2,3). `src/authority` is unchanged between P1 and P4. | An assertion added without ever being run; whether the claim is actually required is undecided |

#### RA-92.4 Correction to RA-91.3 (owned)

RA-91.3 called the curved-disk failures a production regression because the test and fixture were unchanged since R3. That inference missed the deliberate contract change: since `c7cb5d68b`/`715fe2d66`, `make` rejects these inputs by design. The class is now *stale fixture*. Confirmation is still pending, because no test prints the typed factory code. CB14A prints it.

#### RA-92.5 Consequences

- RA-91.4's hold on U4–U6 is discharged. The factory rejection is explained, and the RP-01 fixtures already supply rail provenance.
- The curved disk is the only selector coverage of `make` accepting a hard-feature product, and U4 changes `make`. Restoring it as a control is a narrow test-only turn that should come before U4.
- The other repairs (174, the 191 family, 242, 442) are test debt. They are scheduled later, and none blocks U4–U6.

#### RA-92.6 CB14A specification — `M6-CP3-CB14A-R10-CURVED-DISK-RAIL-PROVENANCE` (test-only)

1. **Rails.** In `make_curved_disk_fixture` (P10:2438), after the 8 boundary hard edges are set, build the rails with the producer.
   - Call `pipeline::build_authoritative_surface_cell_rails(TriMesh, AdaptiveFeatureMap)`. The precedent is `OpenHardRailChainProvenanceIsSourceValidated`, REPackage:184-212.
   - Each feature edge carries its actual single incident face from the fixture mesh. Use one closed curve over the 8 edges.
   - Choose the edge class following the REPackage boundary positive in `RailBuildRejectionCarriesFailureWithoutConsumableRails`, and record the choice.
2. **Provenance.** Set `options.authoritativeRails`, `hardRailTerminalContacts`, `hardRailClosedChains` and `hardRailOpenChains` from `pipeline::hard_rail_source_provenance_from_rails(rails, vertexCount)`.
   - Throw if the build is not `Produced`, if the provenance is empty, or if the union of rail edges is not exactly the 8 boundary edges.
   - Hand-built chains, contacts or edge lists are not allowed.
   - The `reverseFaceRows` variant follows the same procedure on its own faces.
3. **Diagnostics.** In 235, 236, 294 and 299, the first `ASSERT_EQ(Produced, …)` message prints:
   - the rejection-reason name;
   - `publishedProductError` and `publishedProductSourceAuthorityDetail`, as integers, when present.

   Use one small helper for this.
4. **Out of scope:** any assertion or production change, other fixtures, selector or harness changes, and running tests. Compile and package with GMP/GMPXX as before. The CB record is 25 lines or fewer.

#### RA-92.7 TB14A specification — `M6-CP3-TB14A-R10-CURVED-DISK-CONTROL-CENSUS`

*The predictions and the report list are replaced by RA-93.4.*

- Run the unchanged census harness `947a95ee…` with `--execute` on the CB14A package. It is one dispatch, and its five inputs come from the CB14A record.
- **Predictions:**
  - 235, 236, 294 and 299 PASS;
  - every other identity keeps its TB13C status, except 199 and 250 (curved-disk users that were RED at R3 and at TB13C), which are observed only.
- **Falsifiers:**
  - any of the four is RED (Review reads the printed code);
  - any other identity changes status.
- **Deliver** a report of 25 lines or fewer: the run and result IDs, ZIP SHA-256, totals per phase, the status of 235/236/294/299/199/250, and every other identity whose status differs from TB13C. Review re-derives the full comparison.

#### RA-92.8 Sequence

CB14A → TB14A → TB14A-REV. That Review adjudicates TB14A, then issues DEFN-U6 and sets the U4/U5 order. The test-debt repairs for 174, the 191 family, 242 and 442 are scheduled separately. Each CB follows a reviewed TB. A turn that dispatches several runs waits for each to start before pushing the next.

#### RA-93 CB14A accepted; TB14A predictions sharpened (2026-10-18)

**Turn:** `M6-CP3-CB14A-R10-CURVED-DISK-RAIL-PROVENANCE-REV`. **Input:** CB14A source `2ee499a3403c07be05e8084a669f30c1c735f04a`, package `12140756646` (run `39138385869`). **Amends:** RA-92.7 (predictions only).

- **RA-93.1 Re-verification.** ZIP `eee92aeb…d906`, 28/28, root manifest `495cf0b5…b2d1`, source archive `f414dce2…45a2`, `source-commit` `2ee499a3`. All 351 `src`/`include`/`tests` files are byte-identical to the commit; only P10 differs from CB13A (+78/−7), and ccache missed exactly 1 of 129 calls. Build and preflight 0, GMP, `runtimeExecution=false`.
- **RA-93.2 Code accepted (RA-92.6).** Class `Hard` is right. The boundary positive in `RailBuildRejectionCarriesFailureWithoutConsumableRails` is itself `Hard` with one incident face. Both projections skip non-`HardFeature` rails (`RemeshPipeline.cpp:9707`, `:9732`), so `Boundary` would yield no chains and hit the guard. Statically, the builder emits one closed rail from this loop (explicit closing vertex, one source face per edge, component 0, one kind; `RemeshPipeline.cpp:9456-9545`). The guard is stricter than specified (non-empty closed chains), which is accepted.
- **RA-93.3 Finding — derived fixture (RA-92.6 omission, owned).** `make_curved_disk_with_adjacent_source_sheet` (P10:2670) starts from the changed fixture, erases edge 0–1 from `hardFeatureEdges` and adds faces that make 0–1 interior. It keeps the 8-edge closed rail and chain, so its rail provenance now contradicts its own hard edges. Its census users 237/253/254 call only `build_source_topology_regions`, `source_faces_compatible` and `source_edge_is_authoritative_local_boundary`, and none of them reads a rail field (S:5733-5807, S:9382-9739). No status change is predicted, but they now run the new guards. No test reaches `make` on this fixture. Recorded as fixture debt: the helper must rebuild or clear provenance before any `make` use.
- **RA-93.4 TB14A predictions (replace RA-92.7's; harness, single dispatch, package and deliverables are unchanged):**
  - 235/236/294/299 PASS;
  - 237/253/254 PASS. RED means a base-fixture guard threw (P10:2531/2541/2552), and Review reads the message;
  - 199 stays RED, and its first failure leaves P10:5395, the bounded disk on the same path as 236. It is expected at P10:5428 (the cylinder half; RED at R3 with `A4_INVALID_FINAL_CELL_STATE`). A first failure still at 5395 alongside a 236 PASS is a falsifier;
  - 250 is unchanged: RED at P10:3597 with `PublishedProductRejected`. Its composite builds its own options with the disk boundary as hard edges and no provenance (P10:3580-3593), the same stale-fixture cause. It was RED at R3 for another reason, so it joins the fixture debt;
  - every other identity keeps its TB13C status.

  The report gives status, and the first failure line and reason for each RED, for these 9 identities, plus every other divergence.
- **RA-93.5 Sequence.** TB14A → TB14A-REV. TB14A-REV adjudicates TB14A, issues DEFN-U6 and sets the U4/U5 order. It also schedules the fixture debt: 174, the 191 family, 242, 442, 250 and the adjacent-sheet helper.

## `Architecture_M6_CP3_TB13_Chain_Interval_Review_Decision.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_TB13_Chain_Interval_Review_Decision.md`; moved verbatim.

### RA-88 — TB13 reviewed: the RED truth-table row is a Review specification defect; U3 code accepted; CB13A corrects the row (2026-10-18)

**Turn:** `M6-CP3-TB13-R10-OPEN-RAIL-CHAIN-INTERVAL-ROUTE-REV` (RA-89, the CB13A closeout, and RA-90, the TB13A review, are appended; RA-90.4 is amended by RA-91.2 in `Architecture_M6_CP3_TB13C_Census_Review_Decision.md`). **Inputs:** CB13 source `70217cc2bf7d257bebd2969e1aa56b5a43326a70`, package `12130290543`; TB13 run `39112131501`, result `12130683535` (ZIP SHA-256 `43505af2…4885`). **Amends:** RA-87.4.7 (one row). RA-87.3 and RA-87.5 (TB13C) stay live.

#### RA-88.1 Re-verification

- The result ZIP hash matches; `SHA256SUMS` has 0 mismatches; 6 executed, 0 missing, 5 RED; postflight true; compile, relink, benchmarks and selector497 all false.
- The harness differs from TB12's only in sha, artifact, digest, the truth-table identity and two output labels.
- #1 has exactly one failure, at P10:7182: `check({{4,7},{1,4}}, nullopt, nullopt, [1,4,7])` returned true and the test expected false. The other eleven rows hold.
- #2 PASS.
- #3/#4: `endpoint-1`, locus 3, front 61/179, `a3ProbeDecodedVertex=4`, contact endpoints `1,7`. This is B2, as RA-87.5 predicted.
- #5/#6: the raw producer-failure line (SHA-256 `142f195a…`) is byte-identical to TB12's. B3 is unchanged, as predicted.
- U3 falsifiers are absent: `open-rail-chain-interval` occurs in no log, and front 29/147 is no longer first.

#### RA-88.2 The RED row is wrong, not the helper (owned Review defect)

- RA-85.4 and RA-87.4.1 admit a chain interval in either direction. On chain `[1,4,7]`, route `[4-7, 1-4]` is the reverse walk 7→4→1 (`s=2`, `d=−1`). With no T endpoint it is valid. RA-87.4.7 listed it as a false row, which contradicts RA-87.4.1. TB13's stop was correct.
- Reverse traversal is the intended semantics. A front's orientation (endpoint 0 → 1) is independent of the order the rail builder gives the chain. The existing I–T1 row (`[1-4]`, last T1) already relies on it.
- The row's intent was order sensitivity. The replacement rows below keep that intent with genuine negatives: terminals that contradict the walk direction, and a backtrack. All 15 rows were evaluated against an executable model of RA-87.4.1, with 0 mismatches.
- This is not a weakening. Under the frozen rule the row was false, and the three added rows add discrimination.

#### RA-88.3 U3 code accepted; closure waits on the corrected gate

- The helper matches RA-87.4.1, including every bound, `n < 2`, an empty route, and the `|steps| ≥ n` early exit.
- The factory (S:8672-8682) and the consumer (S:20311-20324) call it over the certificate's `oriented_steps()`, keyed by the same rail ID as the contact. In the consumer, the walk is bound to both endpoint carriers beforehand (`endpoint-1-terminal-carrier`, S:20305-20310). The empty-map exemption is gone. The plumbing follows RA-87.4.6, and each negative tampers only its named input.
- **First real-data coverage of the consumer rule:** the consumer visits fronts in ascending order (S:19231), so front 29/147 (I–I, rail 2, edge 1-4) passed the interval check before front 61/179 failed. The factory call still has no real-data coverage, because no open-rail fixture reaches `make`.
- U3 closes when TB13A's truth table passes.

#### RA-88.4 CB13A specification — `M6-CP3-CB13A-R10-OPEN-RAIL-CHAIN-INTERVAL-TRUTH-TABLE` (test-only)

In `SurfaceCellAuthorityContractCutover.OpenRailRouteChainIntervalTruthTable` (P10:7152-7187), over chain `[1,4,7]`:

1. Flip `check({{4,7},{1,4}}, nullopt, nullopt, chain)` to `EXPECT_TRUE` (the reverse walk).
2. Add `EXPECT_TRUE(check({{4,7},{1,4}}, t7, t1, chain))` (reverse T–T).
3. Add `EXPECT_FALSE(check({{4,7},{1,4}}, t1, t7, chain))` (the terminals contradict the walk).
4. Add `EXPECT_FALSE(check({{1,4},{1,4}}, nullopt, nullopt, chain))` (a backtrack).

No other row, test or production line changes. GMP/GMPXX compile and package. Record the package ID, ZIP SHA-256 and source SHA, with `runtimeExecution=false`. The CB13A record is 25 lines or fewer.

#### RA-88.5 TB13A and TB13C

**TB13A** — `M6-CP3-TB13A-R10-OPEN-RAIL-CHAIN-INTERVAL-TRUTH-TABLE`. Use the TB13 harness, changing only sha, artifact, digest and labels, with the same six identities in the same order. Predictions:

- #1 and #2 PASS;
- #3/#4 `first_failure` byte-identical to TB13 (B2, front 61/179);
- #5/#6 byte-identical to TB13 (B3).

Falsifiers: #1 RED; any #3–#6 change; `open-rail-chain-interval` anywhere. A RED goes to Review (rule 4).

**TB13C** — `M6-CP3-TB13C-R10-SELECTOR-497-CENSUS`, as RA-87.5, but on the **CB13A** package. Run the unchanged harness `m6_cp3_entry_497_artifact_only_harness.sh` (SHA-256 `947a95ee…79dd`), with the candidate given only through its environment inputs. None of its three selectors names a renamed identity. The census adds one falsifier: any RED whose first predicate is `open-rail-chain-interval` means the U3 rule rejects a real route, and goes to Review.

#### RA-88.6 Sequence

CB13A → TB13A → TB13C → TB13C-REV (orders U4/U5/U6 and issues DEFN-U6). Each CB follows a reviewed TB.

#### RA-89 CB13A accepted; Review completes its closeout; TB13A authorized (2026-10-18)

- CB13A (`M6-CP3-CB13A-R10-OPEN-RAIL-CHAIN-INTERVAL-TRUTH-TABLE`) stopped with STATUS `IN_PROGRESS` after its compile. Only the documentation closeout remained.
- Independent verification:
  - ZIP SHA-256 `36197dffa91b5dbb3a36d589cab314e95e4d7d24e9121617ed17f59256f2b072` (package `12132184878`, run `39117126811`);
  - root manifest 28/28 OK (SHA-256 `bdb4ad988c463f082a1129d17d463da7e3638f24c81396220adb996a328583e1`);
  - source archive SHA-256 `25ec06e748ea29445d50993c0cd0874bb30da7ab030e24a99cff737e70b3e77f`; `source-commit` `e88ac65ffcf87548138d1c56f2cc6ed4a3d8177b`;
  - build exit 0, 8 targets, `DIRECTIONAL_ENABLE_GMP=ON`, gmp/gmpxx linked, `runtimeExecution=false`, all five source-status files empty.
- The packaged P10 test is byte-identical to HEAD. Relative to CB13 (`70217cc2`), `src`, `include` and `tests` differ only by the four RA-88.4 lines. CB13A is accepted, and Review completes the closeout in place, so no semantic work is outstanding.
- **TB13A** runs on this package, as RA-88.5 specifies.
- **TB13C** then uses the same package, through the harness's environment inputs:
  - `CANDIDATE_ARTIFACT_ID=12132184878`;
  - `EXPECTED_SOURCE_SHA=e88ac65f…`;
  - `EXPECTED_CANDIDATE_ZIP_SHA256=36197dff…`;
  - `EXPECTED_ROOT_MANIFEST_SHA256=bdb4ad98…`;
  - `EXPECTED_SOURCE_ARCHIVE_SHA256=25ec06e7…` (full values above).

#### RA-90 TB13A reviewed: U3 closed; TB13C feasibility checked and its classification fixed (2026-10-18)

- **RA-90.1 Re-verification.** TB13A was checked independently.
  - Result `12134411966`: ZIP `17decdbf…`, 0 manifest mismatches, 6 executed, 0 missing.
  - Harness `a42ae6e0…` differs from TB13's only in sha, artifact, digest and labels.
  - #1 and #2 PASS. #3–#6 `first_failure` fields compared directly with TB13: byte-identical. `open-rail-chain-interval` occurs in no log.
  - The report's two hashes (`cbf8bbfe…`, `923d41c5…`) cannot be reproduced from the ledger field or the raw line, and their method is unstated. Identity rests on the direct comparison.
- **RA-90.2 U3 closed.** B1 is cleared on the RP-01 fixtures. The consumer rule has real-data coverage; the factory call gains it only once an open-rail fixture reaches `make`, which requires U4–U6.
- **RA-90.3 TB13C can run.**
  - All 497 identities exist at `e88ac65f` in the binary they are routed to: 30 + 12 + 6 in producer, 449 per the routing receipt; 0 missing and 0 parameterized. The harness's exact-one selection gate therefore should not abort.
  - The R3 artifact `11661044443` expires on 2026-10-24, but the baseline is the in-repo `Architecture_M6_CP3_TB1_Entry_R3_Red_Classification.tsv` (SHA-256 `890a105e…`, 94 RED; any other identity was a PASS at R3). The comparison uses that file, not the artifact.
- **RA-90.4 TB13C classification is mechanical, applied to each RED's first `firstPredicate=` text, or its first gtest failure line when there is none:**
  - **B1:** contains `open-rail-chain-interval`. This is a falsifier and goes to Review.
  - **B2:** `predicate=endpoint-0|endpoint-1` with `a3ProbeDecodedVertex=<integer>` and `a3ProbeContactEndpointMember=0` (a rail vertex that is not a terminal; TB13 #3 is the template). *Amended by RA-91.2: B2 also requires `a3ProbeContactPublished=1`.*
  - **B3:** `a2bProbeFirstFailedCondition=not-same-interior-carrier-point` (TB13 #5 is the template).
  - **B2+B3** if both apply; **other** otherwise, grouped by `predicate=` name or by the first 80 characters of the failure line.
- **RA-90.5 TB13C deliverables:**
  - the unchanged harness `947a95ee…`, run with `--execute` and the five RA-89 inputs;
  - `Architecture_M6_CP3_TB13C_Selector_497_Red_Inventory.tsv`, one row per RED with columns `phase, ordinal, identity, owner, exit, raw_sha256, class, first_failure (≤200 chars), R3 (PASS/RED), R3_first_observable`;
  - a report of 30 lines or fewer giving totals per phase (30/12/449/6), counts per class, the R3 PASS → now RED list, the R3 RED → now PASS list, and the TSV's SHA-256.
  - Prediction: `cp3entry` ordinals 2 and 6 are B3. Nothing else is predicted, so no interpretation is needed. Falsifier: any B1.

## `Architecture_M6_CP3_TB14A_Curved_Disk_Control_Review_Decision.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_TB14A_Curved_Disk_Control_Review_Decision.md`; moved verbatim.

### RA-94 — TB14A reviewed: curved-disk control restored (425/497); 199 is a hidden fixture repair; DEFN-U6 next (2026-10-18)

**Turn:** `M6-CP3-TB14A-R10-CURVED-DISK-CONTROL-CENSUS-REV`. **Input:** TB14A run `39143325285`, result `12141843937`, on CB14A package `12140756646` (source `2ee499a3`). **Amends:** the RA-85.5 turn IDs for U4/U5 (RA-94.5). **S** = `src/geometry/SurfaceCellTracing.cpp`; **P10** = `tests/SurfaceCellsPhase10Tests.cpp`.

#### RA-94.1 Closeout and re-verification

- TB14A committed its report, a tracker row and the handoff. It then stopped with STATUS `IN_PROGRESS`: its `TODO.md`/`CHANGELOG.md` edits were routed through a Google Drive patch it could not reach.
- Review closes the turn out from re-derived facts. The Drive patch is not applied, and the handoff's procedural "incomplete closeout" section is removed.
- Re-verified:
  - result ZIP `1b06e43e…d455`, 1019/1019 checksums;
  - run `success` at executor `4797400a`;
  - candidate digest `eee92aeb…` matches CB14A;
  - every immutability flag true; 497/497 executed.

#### RA-94.2 Comparison with TB13C (all 497)

- **Exactly five status changes, all RED → PASS: 199, 235, 236, 294, 299.**
- 237/253/254 PASS, and 250 is RED at P10:3597 with `PublishedProductRejected`, both as predicted.
- The 72 REDs are unchanged in substance:
  - 8 raw logs are byte-identical;
  - 60 are identical except for source line numbers and timings;
  - 134/137/150 differ only in the interleaving of `M3_CP4AB_FRAGMENT_DIAG` lines (the same records);
  - 242 differs only in a printed pointer address.

#### RA-94.3 Test 199 falsified RA-93.4 (owned prediction error)

- RA-93.4 predicted 199 would fail later, in its cylinder half, because R3 failed there (`InvalidFinalCellState`, R3 P10:5191).
- But `2be228d96` (2026-10-11, after R3) changed only that call to `build_phase10_with_source_atlas`. That supplies the source A3 atlas, which is now mandatory; the chart-zero assertions are unchanged.
- At TB13C that repair was hidden behind the stale disk half. 199 is therefore a valid R3 RED → PASS control, not a weakened test.
- Lesson: a failure hidden behind another one is unmeasured. Check the test's history before predicting it from an old baseline.

#### RA-94.4 Adjudication

- **The curved-disk `make` control is restored.** Four tests pass at the checked factory with a producer-built closed hard rail. RA-92.5's precondition for U4 is met.
- **Census:** 425/497 = R3 403 + 26 that went RED → PASS (RA-91's 25 plus 199) − 4 that went PASS → RED (174, 191, 242, 442).
- **No production regression.** Stable accounting is unchanged: 66/17/49, debt 1, CP2 491/491, selector 497 frozen.
- **RP-01 is unchanged:** B2 owns 11 identities and B3 owns 19, with B3 failing first on `cp3entry:2/6` (front 17/203 is before 61/179).

#### RA-94.5 Order: DEFN-U6 first, then U4 → U5

- **Why DEFN-U6 first:**
  - B3 owns most of RP-01 and has no design.
  - The remaining U4/U5 work has a frozen rule and order (R10B as amended by RA-84/RA-85).
  - If no exact producer-origin parameter exists, RP-01 cannot close by this route, and U4/U5 must be re-assessed before code is spent on them. A DEFN costs no runtime.
- **U4 → U5 is kept.** The factory admits R before any producer emits it, so the pipeline stays fail-closed throughout. Limit: until U5, U4's factory branch has direct-`make` coverage only (RA-90.2), with the curved disk as its factory regression control.
- **Renamed** to stay monotonic after CB14A: U4 = `M6-CP3-CB15-R10-FACTORY-RAIL-VERTEX-ENDPOINT`, U5 = `M6-CP3-CB16-R10-CONSUMER-RAIL-VERTEX-ENDPOINT`. Their scope is unchanged.

#### RA-94.6 DEFN-U6 specification — `M6-CP3-DEFN-U6-EXACT-I-ENDPOINT-PARAMETER` (documents only)

**Deliverable:** `Architecture_M6_CP3_DEFN_U6_Exact_I_Endpoint_Parameter_20261018.md`, 120 lines or fewer, citing `file:line` at `2ee499a3`. Production code has not changed since `70217cc2`.

1. **Producer-origin trace.**
   - Template: `cp3entry:2`, front 17/203, endpoint-1, edge 1–4, faces 0 and 3.
   - From TB14A `raw/cp3entry/ordinal-002.log`: face 0 = (0, `0x1.999999999999ap-1`, `0x1.9999999999999p-3`); face 3 = (`0x1.999999999999ap-1`, 0, `0x1.9999999999998p-3`).
   - For each side, cite every site that writes the barycentric reaching `same_interior_carrier_point` (S:91-97; checks at factory S:8773 and consumer S:19480), back to exact inputs.
   - State whether the two sides share one computed scalar, and which double operation yields the one-ULP difference.
2. **Candidate exact parameter.**
   - Give its exact inputs, its type (prefer the existing `ExactSourceEdgePoint`/`FieldExactRational`, `ExactSourcePath.h:22-26`) and its orientation convention.
   - Give the single site that computes it, and how it reaches both checkers.
   - Compare alternatives and recommend one.
3. **Rule.** I-endpoint identity is exact equality of that parameter, and the doubles become geometry only. The rule must not use an epsilon, rounding, or canonicalization from near-equality (R9B:29, RA-60.11), and must not rest on the interval alone (RA-63.5).
4. **Satisfiability (RA-61.7).**
   - Evaluate the rule as exact rationals on all 19 B3 identities: focused30 3/12/14/15/17/18/22/23/24, focused12 5/6, selector 211/217/219/227/230/231 and `cp3entry` 2/6.
   - Use TB14A raw logs (artifact retained 14 days). Mark each identity equal, unequal, or missing data; for missing data, name the field and the probe that would print it.
   - State what the rule does with RA-76's 324 one-ULP pairs.
5. **Negatives the CB must test:**
   - distinct crossings one ULP apart stay distinct;
   - parameter 0/1 (a vertex masquerade) is rejected;
   - a parameter on a different edge is rejected;
   - the reversed edge orientation compares correctly;
   - a tampered parameter is rejected at the factory.
6. **Units.** Narrow CBs (for example, carry the parameter with no admission change, then switch both checkers), each with TB predictions and falsifiers on the 19 identities and named controls.

If no exact origin exists, the DEFN says so with evidence and proposes alternatives. It never proposes a tolerance. **Out of scope:** code, builds and runs; U4/U5; test debt.

#### RA-94.7 Sequence

DEFN-U6 → DEFN-U6-REV, which accepts or amends the U6 units and authorizes CB15 (U4). After that: CB15/TB15 → CB16/TB16 (U5) → the U6 CB/TB units → an RP-01 Review.

Fixture debt is scheduled by DEFN-U6-REV as narrow test-only CBs, none of which blocks U4–U6. It covers 174, the 191 family, 242, 442, 250 and the adjacent-sheet helper.

## `Architecture_M6_CP3_TB16C_Census_U4_Review_Decision.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_TB16C_Census_U4_Review_Decision.md`; moved verbatim.

### RA-102 — TB16C reviewed: B3 cleared on all 19; RP-01 has one blocker shape (I–R at rail vertex 4); CB17 (U4) specified (2026-10-19)

**Turn:** `M6-CP3-TB16C-R10-SELECTOR-497-CENSUS-REV`. **Inputs:** HEAD `9386a1016`; TB16C [run 39295624822](https://github.com/akashskypatel/Directional/actions/runs/39295624822), result `12207970911` (ZIP SHA-256 `d10553f037a4ae92913db3c07b325636fe221335f79d955258d16b4671874fcb`) on CB16A package `12193816372`; baseline TB14A `12141843937`. **S** = `src/geometry/SurfaceCellTracing.cpp`, **H** = `include/directional/geometry/SurfaceCellTracing.h`, **P** = `src/pipeline/RemeshPipeline.cpp`, **P10** = `tests/SurfaceCellsPhase10Tests.cpp`, **TQ** = `tests/SurfaceCellTransitionQuotientTests.cpp`. Lines are at `7cfa5b46`; HEAD's `src`, `include` and `tests` are identical.

#### RA-102.1 Re-verification

- The ZIP hash matches, and the manifest checks 1019/1019. The dispatch used the unchanged harness `947a95ee…79dd` and exactly the five RA-100.4 inputs.
- 497/497 selected once, 0 skipped: **425 PASS / 72 RED** (focused30 15/30, focused12 10/12, selector449 400/449, cp3entry 0/6).
- Compared with TB14A's `combined-ledger.tsv`, the identities are the same and there are **0 status changes** in either direction.
- Review reclassified every RED from the raw logs: **B2 30, other 42**; B1, B3 and U6 0. This agrees with the agent's TSV (SHA-256 `9ea7c62e…acf`) on 72/72. No log contains `exact-witness-`.
- First failures compared with TB14A, after stripping the CB15/CB16 probe fields:
  - 43 are identical;
  - 19 are the B3 set, which changed by design;
  - 10 differ only by a P10 line number +1, caused by the single `#include <bit>` CB15 added at P10:12.

  Outside the B3 set nothing changed in substance, including selector 405 (`endpoint-0`, contact not published).

#### RA-102.2 B3 is cleared; U6 is complete

All 19 RA-95.2 identities left B3 and are now B2. With RA-101.2, U6 is closed: the witness admits every measured I endpoint and rejects nothing that passed before. The factory's I rule still has no real-data coverage; it gains coverage when an open-rail front reaches `make`.

#### RA-102.3 RP-01 has one blocker shape: an I–R front ending at rail vertex 4

All 30 B2 records follow one of two templates: 19 at front 97/283 (the former B3 set) and 11 at front 61/179. Both templates are:
- `predicate=endpoint-1`, locus 3, rail 2 (open chain [1,4,7]), on the one-step route [1-4];
- **endpoint 0 is I and passes.** It is the last interior sample on span 3, at p = 4/5 or 3/4.
- **endpoint 1 is vertex 4.** Both sides decode to the exact one-hot vertex 4, in faces (0,1,4) and (4,7,8). Vertex 4 is not a contact terminal (`ContactEndpointMember=0`), so the T branch rejects it (`carrier-orientation`, `no-exact-terminal-corner`).
- **the A3 star of vertex 4 has exactly one usable orientation.**
  - Orientation 0 has both side paths Unique and disjoint. Side 1 stays in (0,1,4); side 2 runs (4,7,8) → (4,5,8) → (1,4,5) over the non-hard edges 4–8 and 4–5.
  - Orientation 1 is Missing on both sides, because it would cross a hard spoke.

**Satisfiability (RA-61.7).** The fixture (TQ:585-640) is a 3×3 grid whose only user hard edges are 1–4 and 4–7, and vertex 4 is interior. Every R clause therefore holds on this data:
- R is strictly interior to the named chain;
- R has exactly two hard spokes, and the carrier 1–4 is one of them;
- R is the far vertex of the one-step interval;
- both sides are exact one-hot at R;
- exactly one orientation has Unique, disjoint paths.

These clauses are R10B §2 with RA-84.4 and RA-85.4. U4 and then U5 are the right next units, in the frozen order (factory first).

#### RA-102.4 CB17 specification — `M6-CP3-CB17-R10-FACTORY-RAIL-VERTEX-ENDPOINT` (U4)

The factory admits a typed R endpoint. The consumer emits none until CB18, so no `Produced` result changes.

1. **Field** (H:1495-1513). Append `std::optional<authority::SourceVertexId> railVertex;` as the **last** member of `SurfaceHardRailRouteEndpointCertificate`. Its comment: a strictly interior vertex of this route's published open chain; never a terminal; exclusive with `terminalVertex`. Appending keeps the consumer's positional construction (S:19664-19666) unchanged.
2. **Interval helper** (S:8249-8286; H:1569-1575). Add trailing parameters `firstRailVertex` and `lastRailVertex`, both defaulting to `std::nullopt`.
   - An end carrying both T and R returns false.
   - An R end must equal `vertices[start]` (or `vertices[end]`), and that index must lie strictly between 0 and n−1.
   - Extend the H comment accordingly. Existing callers and rows are unchanged.
3. **R eligibility helper** (new; pure; in `surface_cell_tracing_detail`, declared next to the interval helper). `open_rail_interior_vertex_valid(vertex, chain, hardFeatureEdges)` returns true iff:
   - the vertex occurs exactly once in the chain, at a position 0 < k < n−1; and
   - the hard-feature edges incident to it are exactly its two chain edges (RA-84.4.1).
4. **Factory star incidence** (S:8682-8687). Also seed every strictly interior vertex of every published open chain. The population pass and the evaluator are unchanged.
5. **Factory route check** (S:8764-8775). Pass each endpoint's `railVertex` to the helper.
6. **Factory endpoint branch** (S:8842-8925).
   - Both tags present → `InvalidSourceAuthority`.
   - The vertex is `terminalVertex`, else `railVertex`. With neither, the I branch runs, unchanged.
   - **T only:** the contact-endpoint clause, unchanged.
   - **R only**, all three required:
     - the vertex is not a contact endpoint;
     - `open_rail_interior_vertex_valid` holds against the rail's open chain;
     - the opposite carrier orientation does not also have both sides Unique. Evaluate `unique_terminal_star_path_checked(R, firstAttachment, carrier.secondFace)` and `(R, secondAttachment, carrier.firstFace)`.
   - **Both kinds, unchanged:** the carrier touches the vertex; the attachments are exact one-hot; each side's path is Unique; contact paths validate; the sectors are disjoint.
7. **Closed-rail branch** (S:8926-8932). Also reject `endpoint.railVertex`.
8. **Digest** (P:2123-2124). When `railVertex` is present, hash a distinct tag followed by its index; when absent, hash nothing. Every existing digest is unchanged.
9. **Tests** (compiled, not run).
   - In `OpenRailRouteChainIntervalTruthTable` (P10:7224), add R rows; the existing rows are unchanged. On chain [1,4,7]:
     - **true:** `[1-4]` last R4 (I–R, the measured shape); `[4-7]` first R4 (R–I); `[1-4]` first T1 and last R4 (T–R);
     - **false:**
       - `[1-4]` last R1 (a chain end);
       - `[1-4]` last R7 (not on the step);
       - `[1-4, 4-7]` first R4 (not the outer vertex);
       - `[1-4]` last both T4 and R4.

     On the chain [1,4] (n = 2), `[1-4]` last R4 is **false** (no interior vertex). On a new chain [0,1,4,7], `[1-4]` first R1 and last R4 is **true** (R–R).
   - Add `SurfaceCellAuthorityContractCutover.OpenRailInteriorVertexEligibilityTruthTable`, on chain [1,4,7] with hard edges {1-4, 4-7}:
     - **true:** R4;
     - **false:** R1; R7; R5; R4 with 4-5 added to the hard edges (a third spoke); R4 with only {1-4} hard (a missing spoke); R4 on chain [1,4]; R4 on chain [1,4,7,4] (repeated).
   - **No factory-level R test.** No open-rail fixture reaches `make` (RA-88.3), so a factory negative would fail earlier and be vacuous (RA-84.4.4). The factory R branch gains real-data coverage at TB18, when the consumer emits R on these 30 records.
10. **Out of scope:** consumer R emission (CB18); probes; any T, I or C behaviour; selectors, harnesses and workflow. Compile and package with GMP/GMPXX, as for CB16A. The record is 25 lines or fewer: package ID, ZIP SHA-256, source SHA, `runtimeExecution=false`.

#### RA-102.5 TB17 — `M6-CP3-TB17-R10-FACTORY-RAIL-VERTEX-ENDPOINT`

- **Harness:** the TB16A harness (`20b2ebd8…afea`). Change only sha, artifact, digest and labels, and append identity #13, `SurfaceCellAuthorityContractCutover.OpenRailInteriorVertexEligibilityTruthTable` (a gate), with the matching count.
- **Predictions:**
  - #1–#7 and #13 PASS (#7 now includes the R rows);
  - #8–#12 have `first_failure` byte-identical to TB16A, because the consumer is unchanged.
- **Falsifiers:** any other outcome. Each goes to Review.
- **No census:** CB17 changes no admission that any current fixture reaches. The TB18 census measures U4 and U5 together.

#### RA-102.6 Sequence

CB17 → TB17 → TB17-REV (issues the CB18 U5 consumer spec) → CB18 → TB18 (focused run plus census) → TB18-REV → fixture debt (RA-96.6 order) → census → RP-01 Review. Each CB follows a reviewed TB. Accounting is unchanged: 66/17/49, debt 1, census 425/497, selector 497; `RP-01` open, `RP-02` UNREACHED, Gate C suspended.

## `Architecture_M6_CP3_TB17_Rail_Vertex_U5_Review_Decision.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_TB17_Rail_Vertex_U5_Review_Decision.md`; moved verbatim.

### RA-103 — TB17 reviewed: CB17 (U4) accepted; CB18 (U5, consumer emits R) and TB18 specified (2026-10-19)

**Turn:** `M6-CP3-TB17-R10-FACTORY-RAIL-VERTEX-ENDPOINT-REV`. **Inputs:** HEAD `8f1eab028`; CB17 source `ccc0b00ab6a94d0889ed7c60e4532b6c985ce03e` (HEAD `src/include/tests` identical), package `12214741070` ([run 39306529387](https://github.com/akashskypatel/Directional/actions/runs/39306529387)); TB17 [run 39313027637](https://github.com/akashskypatel/Directional/actions/runs/39313027637), result `12215967774`. **S** = `src/geometry/SurfaceCellTracing.cpp`, **H** = its header, **P10** = `tests/SurfaceCellsPhase10Tests.cpp`. Lines are at `ccc0b00ab`.

#### RA-103.1 Re-verification

- **CB17 package:** ZIP SHA-256 `9acb5081…5ca5` matches; manifest 28/28; `source-commit` = `ccc0b00ab`; build exit 0; eight targets; `runtimeExecution=false`, `exactArithmeticBackend=GMP`. The packaged `src`, `include`, `tests` and `CMakeLists.txt` are byte-identical to git `ccc0b00ab`. **The package expires 2026-10-26**; nothing after CB18 depends on it.
- **TB17 result:** ZIP SHA-256 `b32366a1…2ace` matches; manifest 17/17; 13 planned, 13 executed, 0 missing; postflight, package, source, execution view and frozen selectors all true; compile, relink, benchmarks and selector497 false.
- **Harness** `efa91d9b…c7a9` differs from the TB16A harness `20b2ebd8…afea` only in lines 7–9, the appended #13 tuple, the two counts and the two labels.
- **Outcomes:** #1–#7 and #13 PASS (`OK` lines in the raw logs). The #8–#12 ledger `first_failure` fields and the full raw first predicate lines (6,972–9,565 bytes) are byte-identical to TB16A. Every RA-102.5 prediction holds.

#### RA-103.2 CB17 conforms to RA-102.4

- **Field:** `railVertex` is the last member (H:1503-1505), so every five-member construction leaves it empty.
- **Interval helper** (S:8249-8296): both tags on one end → false; an R end must be `vertices[start|end]` with the index strictly inside (0, n−1). Defaults keep every existing caller unchanged.
- **Eligibility** (S:8298-8321): exactly one occurrence at 0<k<n−1; both chain edges hard and distinct; no other incident hard edge.
- **Factory** (S:8723-8727, S:8809-8814, S:8884-8985, S:8986): seeds interior chain vertices; passes R anchors; both tags → reject; the T contact clause is guarded by `terminalVertex`, so T is unchanged; the R clauses are not-a-contact, eligibility and opposite-orientation exclusion; the closed branch rejects R. `hardRailOpenChains.at()` is safe because the route check returns first when the chain is missing.
- **Digest** (P:2125-2129): tag plus index only when R is present; every existing digest is unchanged.
- **Design note:** under eligibility, the carrier's two faces fall in different non-hard components of R's star, so the opposite-orientation clause cannot fire when the selected orientation is admissible. It is a parity guard, not a new restriction. The consumer must carry the same guard (RA-103.4.3).

**CB17 (U4) is accepted.** The factory R and I branches still have no real-data coverage; CB18 supplies it.

#### RA-103.3 Consumer design facts (read at `ccc0b00ab`)

- `endpoint_certificate` (S:19505-19735) tries T (S:19600-19607), then I (S:19608-19627), then rejects `no-exact-terminal-corner` (S:19628). Its A3 star and orientation selection (S:19630-19734) are keyed to `*terminalVertex` only at S:19637-19638 and S:19726.
- The consumer route check (S:20476-20488) passes only the T anchors.
- No other source reads `terminalVertex` (pipeline A5 uses `attachmentTransport()`, which is generic over the paths).
- `ForeignSourceTerminalContactRejectsAtFirstA4ConsumerPredicate` (P10:7451-7505) requires `no-exact-terminal-corner` for a one-hot chain *terminal* that is not a contact. An ineligible vertex must therefore keep that label; no new predicate label is needed.
- Tests that assume every endpoint is T (TQ:3017, TQ:3257, TQ:8832, `SurfaceCellREPackageTests.cpp:713`, P10:7518) are production-dependent and currently RED. They are fixture debt, not CB18 scope.

#### RA-103.4 CB18 specification — `M6-CP3-CB18-R10-CONSUMER-RAIL-VERTEX-ENDPOINT` (U5)

The consumer emits a typed R endpoint exactly where the factory admits one.

1. **R candidate** (S:19608-19628). Declare `std::optional<authority::SourceVertexId> railVertex;` before the `if (!terminalVertex)` block. Keep the T loop and the I branch byte-for-byte. Replace the single `return reject("no-exact-terminal-corner");` with:
   - `railVertex` = the vertex v ∈ {`edge.first()`, `edge.second()`} with v ∉ `contact->second.endpoints`, `exact_corner(fromPoint, v)`, `exact_corner(toPoint, v)`, the rail's chain present in `authoritativeOptions.hardRailOpenChains`, and `open_rail_interior_vertex_valid(v, chain, authoritativeOptions.hardFeatureEdges)`;
   - none → `return reject("no-exact-terminal-corner");` (label unchanged).
2. **Star vertex** (S:19637-19638). After the A3 null check, `const auto starVertex = terminalVertex ? *terminalVertex : *railVertex;` and use it in the spoke filter. `path_to` and the sector test are unchanged.
3. **Orientation parity** (S:19692-19733). Count orientations where both `firstPath` and `secondPath` exist, before the sector test. After the loop, if `railVertex` and the count is 2 → `return reject("ambiguous-carrier-orientation");`. T is unchanged.
4. **Certificate** (S:19725-19727): pass `railVertex` as the sixth positional member.
5. **Route check** (S:20482-20484): pass `firstEndpoint->railVertex, secondEndpoint->railVertex` as the trailing arguments.
6. **Unchanged:** T and I behaviour, the closed branch, the probes (S:19736-20100), the factory, the digest, selectors, harnesses.
7. **Tests** (compiled, not run):
   - P10:7333-7337 (#9's filter): add `!route.endpoints[1].railVertex.has_value()`, so an R endpoint with empty paths cannot stand in for the I endpoint.
   - New `SurfaceCellAuthorityContractCutover.ProducedOpenRailInteriorVertexEndpointRejectsForgedTags`, inserted at P10:7406:
     - build `build_rectangular_hard_rail_phase_front()`; assert `Produced` (with `hard_rail_first_failure_detail`);
     - find a route endpoint with `railVertex`; assert one exists;
     - expect: no `terminalVertex`; R is not a contact endpoint; `open_rail_interior_vertex_valid(R, front.hardRailOpenChains().at(route.rail), front.hardFeatureEdges())`; R is an end of `terminalCarrier.edge`;
     - positive control: `make` with the unmodified routes (the P10:7390-7399 argument list) returns a `SurfacePhaseFrontProduct`;
     - each forgery → `InvalidSourceAuthority`: (i) `terminalVertex = railVertex`; (ii) `railVertex.reset()`; (iii) `railVertex` = the other end of `terminalCarrier.edge`.
8. **Build:** GMP/GMPXX compile and package, the eight CB17 targets. Record ≤25 lines: package ID, ZIP SHA-256, source SHA, `runtimeExecution=false`.
9. **STOP** if any clause cannot be implemented as written or needs a site not listed here.

#### RA-103.5 TB18 — `M6-CP3-TB18-R10-RAIL-VERTEX-ENDPOINT` (artifact-only, two parts)

**Part A, focused.** The TB17 harness (`efa91d9b…c7a9`); change only sha, artifact, digest and labels; append #14 = the new test (`diagnostic`), with the matching counts.
- **Predictions:** #1–#7 and #13 PASS. None of #8–#12 or #14 keeps a B2 first failure (`predicate=endpoint-0|1` with an integer `a3ProbeDecodedVertex`, `a3ProbeContactEndpointMember=0`, `a3ProbeContactPublished=1`); each is PASS or has a new first failure.
- **Falsifiers:** any gate RED; any #8–#12 `first_failure` byte-identical to TB17; any checked-factory `InvalidSourceAuthority` on a route the consumer certified with R.
- If a gate is RED, stop: no Part B; TB18-REV.

**Part B, census.** The unchanged census harness `m6_cp3_entry_497_artifact_only_harness.sh` (`947a95ee…79dd`) with `--execute` and the five CB18 values (`CANDIDATE_ARTIFACT_ID`, `EXPECTED_SOURCE_SHA`, `EXPECTED_CANDIDATE_ZIP_SHA256`, `EXPECTED_ROOT_MANIFEST_SHA256`, `EXPECTED_SOURCE_ARCHIVE_SHA256`). Baseline: TB16C result `12207970911` (expires 2026-11-02).
- **Deliverables:** `Architecture_M6_CP3_TB18_Selector_497_Red_Inventory.tsv` (RA-101.4 columns, with TB16C in place of TB14A); classification RA-90.4 with RA-91.2, plus U6; a report of 30 lines or fewer giving totals per phase, counts per class, the TB16C PASS→RED and RED→PASS lists, each of the 30 TB16C B2 identities by name with its TB18 status and class, and the TSV SHA-256. No interpretation.
- **Predictions:** 0 PASS→RED (≥425 PASS); none of the 30 stays B2.
- **Falsifiers:** any PASS→RED; any of the 30 still B2; any B1, B3 or U6.

#### RA-103.6 Sequence

CB18 → TB18 (A, then B) → TB18-REV → fixture debt (RA-96.6 order 242 → 174 → 250 → adjacent-sheet → 191 → 442, plus any I/R test-assumption sites TB18-REV assigns) → census → RP-01 Review. Accounting is unchanged: 66/17/49, debt 1, census 425/497, selector 497; `RP-01` open, `RP-02` UNREACHED, Gate C suspended.

## `Architecture_M6_CP3_TB18_REV_Factory_Rejection_Review_Decision.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_TB18_REV_Factory_Rejection_Review_Decision.md`; moved verbatim.

### RA-105 — TB18-REV reviewed: measurements confirmed; RA-104 corrected; RP-01 realigned to the checked-factory rejections (2026-10-20)

**Turn:** Review of `M6-CP3-TB18-R10-RAIL-VERTEX-ENDPOINT-REV` (RA-104, `Architecture_M6_CP3_TB18_Rail_Vertex_Endpoint_Independent_Review_20261020.md`). **Inputs:** TB18 Part A `12231529583`, Part B `12232299548`; CB18 source `3bd24682c` (HEAD `00696aedd` has identical `src/include/tests/CMakeLists.txt`). **S** = `src/geometry/SurfaceCellTracing.cpp`, **TQ** = `tests/SurfaceCellTransitionQuotientTests.cpp`, **P10** = `tests/SurfaceCellsPhase10Tests.cpp`, all at HEAD. **Amends:** RA-104 items 2–4 and its successor; RA-103.6 and RA-96.6 (order only).

#### RA-105.1 Measurements confirmed

- Review verified both artifacts before RA-104 existed and withheld its numbers. They match the harvest and RA-104 exactly:
  - Part A: 18/18 hashes, 12/14 PASS.
  - Part B: 1019/1019 hashes, 448/497.
  - Against TB16C: 23 RED→PASS, 0 PASS→RED.
  - Classes: B1 = B2 = B3 = U6 = 0.
  - The 30 former B2 identities are 16 PASS and 14 RED.

  TB18 is accepted as candidate evidence only.
- Part A #10 and #11 are `cp3entry:2` and `cp3entry:6`. Part A has eight gates (#1–#7 and #13), not the four RA-104 states; all eight PASS.

#### RA-105.2 Corrections to RA-104

1. **Wrong locus.** `PublishedProductRejected` is set at exactly one site, S:13097. It is set when the checked factory `SurfacePhaseFrontProduct::make` (S:13080) rejects state that the A4 consumer has already certified. #10 and #11 are therefore checked-factory rejections of consumer-published products. They are not "producer fixture" exceptions that occur before the factory runs. The RA-103.5 falsifier "factory `InvalidSourceAuthority` on an R-certified route" is **undetermined**: its precondition is demonstrated, but the rejecting clause is not logged (`require_produced`, TQ:426, prints only the reason name).
2. **No separation of mechanisms.** RA-104 left all 49 RED as "other". The 14 former-B2 RED and the 6 torus RED fall under two mechanisms (RA-105.3, RA-105.4); this record proves two of the rejections statically.
3. **Wrong priority.** Every cross-region CP3-entry identity (`cp3entry:1`, `2`, `6`) now ends at the checked factory, and no fixture-debt item touches any of them. RA-96.6 and RA-103.6 (both Review's own) placed fixture debt after TB18 on the assumption that the B2 exit would complete the production path; TB18 falsified that assumption. The selector242 plan stays as fixture debt (RA-105.7). Its qualifier "if supported by actual field-atlas contract" is struck: the oracle stays as written, or the turn STOPs.

#### RA-105.3 M1 — the certificate binding shadows frozen precedence (10 identities; static proof)

The identities are `focused30:3, 22, 23` and `selector:139, 140, 142, 211, 219, 227, 230`. Each test edits `route`, `railId` or `oppositeEdge` on one edge of a produced cross-region HardRail pair and leaves `hardRailRouteCertificates` untouched.

- **Proof.**
  - No clause of `make` before S:8756 reads `edges`.
  - S:8766–8775 compares exactly those three fields with the certificate and returns code 0 (`InvalidSourceAuthority`).
  - The raw logs of 211 and 219 show code 0 where the oracle expects 7 (`InvalidOppositeEdge`, S:9242–9249).
  - The other eight print no code. Each fails at the factory's throw or null return, or at the test's `"InvalidPhaseFrontProduct"` mapping (TQ:2345).
- **Origin.** S:8755–8775 arrived with `80fc1688f` (2026-10-08, R2 route τ), after CP2 acceptance. The check stayed hidden because `hard_rail_fixture()` did not produce until CB18.
- **Conflict.**
  - The `M6-CP1-TB6-A6-REV` HardRail amendment (2026-09-29): the reciprocity guard belongs at A5 publication and maps to `InvalidHardRailTransport`.
  - RA-15.2–15.4:
    - malformed routes keep `InvalidHardRailAuthority`;
    - pair failures, including 139 and 142, stay `InvalidHardRailTransport`;
    - route-validity semantics are not duplicated.
  - RA-19 item 1: observable precedence is fixed for 212, 227/230 and 139/140/142.

  No RA amended any of these for certified pairs, so `80fc1688f` is an unreviewed contract change.
- **Disposition.** This is a candidate `VALIDATION_ORDER_SHADOWING` recurrence, owned by production; it is not fixture debt. The binding stays fail-closed. A DEFN after TB19-REV decides who owns it:
  - A4, with amended names; or
  - A5, as the TB6-A6-REV amendment states.

  No M1 oracle changes before that DEFN.

#### RA-105.4 M2 — the relational A3 gauge pin over-reaches its domain (hypothesis H-pin)

> **Confirmed by RA-110.3 (2026-10-20):** H-pin holds on both measured edges; the corrected domain is defined by `M6-CP3-DEFN-P1-GAUGE-PIN-DOMAIN`.

RA-45.3's pin (S:8510–8550) requires `compose(T_A3, g_first) == g_second` on **every** source edge with two incident faces. That includes HardRail carriers and periodic cut edges.

- **`focused30:12` (static proof).**
  - The test adds 1 to the face gauge and to the cell and edge branch rotations of one topology region (TQ:4934–4973). It then requires construction to succeed (TQ:4980).
  - In `hard_rail_fixture()`, the rail edges {1,4} and {4,7} are the only edges joining the two regions, and each has one incident face in each region.
  - The unchanged baseline passes the same pin with the same atlas, so the relabel breaks the pin on those carriers.
  - Nothing in `make` before S:8510 reads branch values: S:8458–8504 cover only the atlas and source binding, presence and range.
- **Torus group (static argument).** The identities are `cp3entry:1`, `focused30:6, 20, 24` and `selector:446, 447`.
  - The witness field (TQ:993–1025) has nonzero Z4 holonomy around the major loop. Around a closed loop, the pin forces the product of the transitions to be the identity, so no face gauge can pass.
  - The first observable changed from `ORGANIC_ODD_TAU_WITNESS_ABSENT` at R3 (`d82e34427`) to `PublishedProductRejected` at CB13A (`e88ac65f`). The pin (`1eaea310f`) landed in that window.
  - `selector:446` was accepted green at CP2.
  - `focused30:24` joins this group: it builds `hard_rail_fixture()` (now produced) and then the torus witness.
- **Contradictions with frozen text.**
  - RA-31a item 1: "the published F is region-relative".
  - RA-33.3: τ is "not a difference of region gauges".
  - RA-34.3 requires a produced witness with `(F_b−F_a) mod 4 ≠ τ_ab`. If the gauge is pinned across carriers, no factory-accepted product can be that witness.
  - Nothing consumes the cross-region gauge difference (RA-45.1).
- **Not yet shown:** which clause rejects `cp3entry:2` and `cp3entry:6`. The pin is a candidate, alongside the R-endpoint clauses (S:8885–8994) and the junction transport (S:9096–9104).

#### RA-105.5 Next unit — `M6-CP3-CB19-RP01-FACTORY-REJECTION-SITE` (Code + Build, compile only; rejection-only)

> **RA-106 (2026-10-20):** CB19 failed to compile. The corrected build is `M6-CP3-CB19A-RP01-FACTORY-REJECTION-SITE` (RA-106.3/106.4/106.6).

1. `include/directional/geometry/SurfaceCellTracing.h`:
   - add `std::string sourceAuthoritySite` as the **last** member of `SurfacePhaseFrontProductError`;
   - add `std::string publishedProductSourceAuthoritySite` as the last member of `SurfacePhaseFrontFailure`.
2. `SurfacePhaseFrontProduct::make` (S:8439–9530): immediately before every `return error;` whose code is `InvalidSourceAuthority`, add one assignment of a site label unique to that return.
   - The label is `<clause>`, followed by:
     - `;edge=<v0>,<v1>` at pin returns;
     - `;certificate=<k>;rail=<id>` inside the certificate loop;
     - `;endpoint=<0|1>;kind=<T|R|I|TR>` inside the endpoint loop;
     - `;junction=<j>` inside the junction loop.
   - **Additive only:** no existing line of `make` changes or moves.
   - The CB record lists every label with its S line.
3. S:13097 block: copy the site into `publishedProductSourceAuthoritySite` (additive).
4. Test reporting only; no assertion or oracle changes:
   - `require_produced` (TQ:426) appends ` product=<int> detail=<int|none> site=<site>` for `PublishedProductRejected`;
   - TQ:4980's `ASSERT_NE` streams the factory code and the site.
5. One new test, in a new suite `SurfaceCellFactoryRejectionSite` that is outside every frozen selector, on `hard_rail_fixture()`:
   - **positive control:** the unmodified draft constructs;
   - **negative:** adding 1 (mod 4) to the gauge of one face that has an intra-region interior edge rejects it with code 0. The site is the pin label, with an edge incident to that face.
6. Build with GMP/GMPXX for the eight targets, `runtimeExecution=false`. **Out of scope:** any change to a condition, an ordering or a code; `RemeshPipeline.cpp`; selectors; harnesses; fixtures.
7. **Review falsifiers (static):**
   - any line inside `make` deleted or modified;
   - a duplicate label;
   - an unlabelled `InvalidSourceAuthority` return;
   - any file outside items 1–5.

#### RA-105.6 TB19 — `M6-CP3-TB19-RP01-FACTORY-REJECTION-SITE` (artifact-only, focused, after CB19)

> **Amended by RA-106.5 (2026-10-20):** the empty-site falsifier applies only to `product=0`. TB19 pins the CB19A package.
> **Superseded by RA-107.3 (2026-10-20)** as the TB19 specification: TQ line mapping and the exact 22-row table.

TB19 uses the TB18 Part A harness with the CB19 values and runs 22 identities:
- **M2 (9):** `cp3entry:1, 2, 6`; `focused30:6, 12, 20, 24`; `selector:446, 447`.
- **M1 (10):** the ten identities in RA-105.3.
- **Controls (3):** `selector:217`, Part A #14 and the new test.

**Predictions:**
- every TB18 status is unchanged;
- M1 first failures are byte-identical to TB18, apart from pointer addresses;
- `focused30:12` reports the pin label with a rail-carrier edge;
- the six torus identities report the pin label;
- `cp3entry:2` and `cp3entry:6` report a site; no prediction is made for them.

**Falsifiers:**
- any change of status;
- a `PublishedProductRejected` with an empty site;
- a torus or `focused30:12` site other than the pin;
- the new test RED.

TB19-REV adjudicates every falsifier. TB19-REV also settles the RA-103.5 falsifier: an R-endpoint label on `cp3entry:2` or `cp3entry:6` fires it.

#### RA-105.7 Sequence

> **Amended by RA-110.6 (2026-10-20):** the DEFN is split; the gauge-pin domain (DEFN-P1) comes first and the M1 binding owner follows TB20-REV.

CB19 (site) → TB19 → TB19-REV (mandatory; rules on H-pin and on `cp3entry:2/6`) → DEFN on the gauge-pin domain and the M1 binding owner, as TB19-REV orders → corrective CB/TB → fixture debt → census → RP-01 Review.

- **Fixture debt:** 242, then 174 → 250 → adjacent-sheet → 191 → 442, plus the I/R sites TQ:3017, TQ:3257, TQ:8832, RE:713 and P10:7518.
- `focused30:12` becomes a uniform-relabel debt (RA-45.4) only if Review keeps the pin's present domain.
- **Accounting is unchanged:** 66/17/49, debt 1, CP2 491/491, R3 403/497 rejected, TB18 candidate 448/497, selector 497. `RP-01` is open, `RP-02` is UNREACHED and Gate C is suspended.

## `Architecture_M6_CP3_TB19_Closeout_Review_Decision.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_TB19_Closeout_Review_Decision.md`; moved verbatim.

### RA-109 — TB19 harvest report accepted; TB19 closed by Review; TB19A gains a static edge classification (2026-10-20)

**Turn:** `M6-CP3-TB19-RP01-FACTORY-REJECTION-SITE-CLOSEOUT-REV`. **Inputs:**
- report `Architecture_M6_CP3_TB19_Factory_Rejection_Site_Harvest_Report_20261020.md` (commit `b2b2aa9c1`);
- the agent's handoff commits `2e71e6aeb` and `2c81346a0`;
- STATUS `IN_PROGRESS` (`74d81af6a`);
- TB19 artifact `12285225197`.

**Amends:** RA-108.5 (adds one item to the report). **TQ** = `tests/SurfaceCellTransitionQuotientTests.cpp` at `d2c7483cd`.

#### RA-109.1 TB19 report accepted

- **Checked against the artifact ledger:** all 22 raw-log SHA-256 values and all 22 TB18 statuses match.
- **Rulings applied as written:**
  - the six torus rows are marked NOT MEASURED;
  - `focused30:12` has `product=0`, site `gauge-pin-consistency;edge=1,4` and detail `not streamed`;
  - the falsifier lines match RA-108.3, with the R-route NOT REACHED.
- **No adjudication** is made, as RA-108.4 requires.
- **Accepted** as TB19's harvest evidence. H-pin is still not ruled on; TB19-REV rules on it after TB19A.

#### RA-109.2 TB19 closed

- **What remained open.** TB19 yielded `IN_PROGRESS`. Its own note said the TODO, CHANGELOG and regression-tracker updates were still pending.
- **Review finishes them.** These are shared durable records that every Review turn maintains anyway, so Review completes them in this turn.
- **TB19 is closed.** No implementation turn is scheduled for bookkeeping alone.

#### RA-109.3 Handoff restored to the template

The agent's handoff departed from `Future_Chat_Session_Handoff_Template.md` in three ways:
- **Heading.** It replaced `## Mandatory next turn — … — EXACT NEXT` with `## Pending successor — … — NOT ENTERED`.
- **Contradictory state.** It marked the TB19 closeout `done` in the Turn Sequence, and called it "complete" in Currency, while STATUS said `IN_PROGRESS`.
- **Shortened lines.** It cut the `load_next` line, dropping "never Code + Build".

**Restored:**
- the template headings and fields;
- in Turn Sequence, only the next authorized edge and the frozen conditional edges, per the template. The past rows, including those Review added in RA-107 and RA-108, are removed; `TODO.md` and `CHANGELOG.md` hold the history.

#### RA-109.4 Addition to TB19A: classify each torus edge statically

- **Basis.**
  - The torus witness declares 18 hard edges (`torus_row408_hard_edges`, TQ:908–927):
    - the minor cycle 0–3–25–37–49–61–0;
    - the major cycle 0–1–4–6–8–10–12–14–16–18–20–22–0.
  - The witness requires at least one of these edges to carry a nonzero Z4 matching (TQ:1617–1631).
  - The rectangle rows reject on a declared hard edge, (1,4).
- **Why it matters.** Whether each torus site's edge is one of the 18 hard edges decides whether the torus rows fall in the same rail-carrier domain as the rectangle rows. It is the input TB19-REV needs for the "rail carriers vs. periodic cuts" split.
- **Added to the TB19A report:** for each torus row that reports `gauge-pin-consistency;edge=a,b`, state whether {a,b}, as an unordered pair, is one of the 18 hard edges, and which cycle it is on.
  - This is a static lookup in the pinned source;
  - nothing is executed or changed for it, and it does not adjudicate.
- **Unchanged:** the RA-108.5 harness, rows, falsifiers G1–G4, STOP rules and boundary.

#### RA-109.5 Sequence and accounting

- **Sequence:** TB19A → TB19-REV (mandatory, over the TB19 and TB19A reports) → [DEFN on the gauge-pin domain and the M1 binding owner → corrective CB/TB] → fixture debt → census → RP-01 Review.
- **Accounting is unchanged:**
  - 66/17/49, debt 1;
  - CP2 491/491;
  - R3 403/497 rejected;
  - TB18 candidate 448/497;
  - selector 497.

  `RP-01` is open, `RP-02` is UNREACHED and Gate C is suspended.

## `Architecture_M6_CP3_TB19_REV_Gauge_Pin_Domain_Review_Decision.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_TB19_REV_Gauge_Pin_Domain_Review_Decision.md`; moved verbatim.

### RA-110 — TB19-REV: TB19A accepted; H-pin confirmed as a producer/factory gauge-domain mismatch; DEFN-P1 ordered (2026-10-20)

**Turn:** `M6-CP3-TB19-RP01-FACTORY-REJECTION-SITE-REV`. **Inputs:**
- TB19 (RA-108, RA-109): run `39464430751`, artifact `12285225197`, report `Architecture_M6_CP3_TB19_Factory_Rejection_Site_Harvest_Report_20261020.md`;
- TB19A: run `39484475466`, artifact `12292268624`, report `Architecture_M6_CP3_TB19A_Torus_Rejection_Site_Harvest_Report_20261020.md`.

**Lines:** S = `src/geometry/SurfaceCellTracing.cpp`, TQ = `tests/SurfaceCellTransitionQuotientTests.cpp`, both at HEAD `59f6daf4b`, whose `src`, `include` and `tests` are identical to `d2c7483cd`. **Amends:** RA-105.7 and RA-106.7 (sequence only).

#### RA-110.1 TB19A evidence verified; TB19A closed

- **Artifact.** Review downloaded `12292268624` independently:
  - ZIP SHA-256 `25d48ed7…7efa7c` matches; run `39484475466` succeeded on head `5335c610a`;
  - `SHA256SUMS` verifies every file, and the 7 raw-log hashes and the ledger match the report;
  - `execution-boundary.txt`: planned = executed = 7, red 6, missing 0, postflight true, no compile, relink, benchmark or selector-497 run.
- **Harness.** The diff against the TB19 harness is exactly RA-108.5: the staging path, the torus pre-check, the per-row not-found guard, the 7 rows, the counts and the labels. SHA-256 `21480db4…cabc` matches the dispatch request.
- **G1–G4 held.** The control `selector:443` PASS proves the torus fixture resolves.
- **Report accepted.** Its RA-109.4 classification is correct: {0,3} is the first edge of the minor cycle (TQ:910), which shares only vertex 0 with the major cycle.
- **Closeout.** The agent's turn ended with STATUS `IN_PROGRESS` and the TODO, CHANGELOG and handoff not updated. Review completes them in this turn, as in RA-109.2, and TB19A is closed.

#### RA-110.2 Combined measurement: all nine M2 identities stop at the pin

| Identities | Fixture | Site | Edge |
|---|---|---|---|
| `cp3entry:2`, `cp3entry:6`, `focused30:12` | rectangle `hard_rail_fixture()` | `gauge-pin-consistency;edge=1,4` | cross-region hard-rail carrier |
| `cp3entry:1`, `focused30:6/20/24`, `selector:446/447` | nonzero-Z4 torus witness | `gauge-pin-consistency;edge=0,3` | minor-cycle hard edge (`torus_row408_hard_edges`) |

- Every rejecting edge is a member of the factory input `hardFeatureEdges`.
- No M2 identity reaches the certificate, endpoint or junction clauses. The R-route is **NOT REACHED** on all nine, so the RA-103.5 falsifier stays undetermined. It carries to the first TB after the pin is corrected.
- All nine codes are `product=0`, so the RA-106.5 non-zero-code follow-up is not invoked.

#### RA-110.3 H-pin ruling

**Static basis:**
1. **Producers are per region.** S:18336–18352 runs uniform, then periodic annulus, then curved bounded disk for each topology region separately. Each producer roots its own gauge; the bounded disk sets root 0 at S:16255. No producer establishes the A3 relation between face gauges in two different regions; DEFN-P1 item 1 verifies this for each producer.
2. **Cut edges are skipped inside a region.** In a region with a hard feature and an accepted conformity plan (`useAcceptedCutDomain`, S:15333), the bounded-disk producer collects the conformity boundary carriers as `acceptedCutEdges` (S:15532). It omits them from:
   - face incidence (S:16000);
   - the gauge BFS (S:16217);
   - the reciprocal-transport check (S:16346).
3. **The pin checks every two-face edge.** It requires `compose(T_A3, g_first) == g_second` on each one, including the edges in items 1 and 2 (S:8509–8567).
4. **The cross-carrier transition is checked elsewhere, on the field.** `rail-transition-a3` (S:8717–8732) authenticates each `hardRailFieldTransitions` entry against the atlas without reading face gauges.
5. **Frozen text.** The pin on carriers contradicts:
   - RA-31a.1: the published F is region-relative;
   - RA-33.3: τ is not a difference of region gauges;
   - RA-34.3: requires a produced witness with `(F_b−F_a) mod 4 ≠ τ_ab`.

   RA-45.1 says the gauge is consumed only relationally.
6. **Torus.** RA-105.4: with nonzero Z4 holonomy on a dual loop, no face gauge satisfies the pin. TB19A measured the rejection at {0,3}.

**Rulings:**
- **H-pin is CONFIRMED.** The pin's domain is wider than the domain over which any producer establishes the face gauge. This is a defect in the checked factory's clause (RA-45.3's domain). It is neither fixture debt nor a producer defect.
- **The pin stays mandatory inside the gauge domain** (RA-45.3), and RA-45.5 (validate, never rewrite) stands. The `SurfaceCellFactoryRejectionSite` negative must still reject at an edge within a region's gauge domain.
- **Rail carrier versus periodic cut is not separated, and need not be.** On the torus witness every rejecting edge is both a hard edge and part of the cut graph. The correction is defined by the producers' gauge domain, not by edge type. DEFN-P1 states the predicate.
- **`focused30:12` is not uniform-relabel debt.** RA-105.7's condition, that Review keeps the present domain, does not hold. It stays an M2 production identity.

#### RA-110.4 Constraints on the corrected domain

> **Amended by RA-111.3 (2026-10-20):** item 3 (exactness) is withdrawn; the domain must instead span each region. RA-111.4 gives the domain.

DEFN-P1 must define a domain that satisfies all five:
1. **Inputs.** It is computable from `make`'s inputs. `make` receives `hardFeatureEdges` and `sourceTopologyRegions`, but not the producer's `acceptedCutEdges`. If the domain needs more, DEFN-P1 names the minimal added input and does not design it.
2. **Producers.** It covers the uniform (S:13178), periodic-annulus (S:13997) and curved-bounded-disk (S:15284) producers.
3. **Exact.** It excludes exactly the edges no producer relates. Excluding an edge that some producer relates weakens RA-45.3, and is forbidden.
4. **Authority.** For each excluded edge class, it names the `make` clause that authenticates what is consumed across it (for example `rail-transition-a3`, or the periodic relation `branchAuthority` described at S:13104–13107), or it records a gap.
5. **Consumers.** It confirms or refutes RA-45.1 at the current source: does any production consumer read a gauge difference across an excluded edge?

#### RA-110.5 Next unit — `M6-CP3-DEFN-P1-GAUGE-PIN-DOMAIN` (Definition, documents only)

> **Amended by RA-111.2 (2026-10-20):** the first STOP condition is withdrawn; a producer relating an intra-region hard edge does not falsify H-pin.

**Deliverable:** `Architecture_M6_CP3_DEFN_P1_Gauge_Pin_Domain_Definition_Record_<date>.md`, containing:
1. **Producer table** (3 rows): the function and its S range, the gauge root rule, and the two-face edges excluded from its gauge domain, each with S lines.
2. **Cut-set inclusion:** is every `acceptedCutEdges` member (S:15532) in `hardFeatureEdges`? Give an S-line proof or a counterexample.
3. **Torus regions:** do the two faces at {0,3} lie in one topology region? Answer statically with S lines, or say that it cannot be decided statically.
4. **Domain:** the corrected domain as one predicate over `make`'s inputs (RA-110.4 item 1), plus the authority table for excluded edges (item 4).
5. **Consumer census** for RA-110.4 item 5, with S and `RemeshPipeline.cpp` lines.
6. **Oracle plan** for the later CB (not executed):
   - for each of the nine M2 identities, the prediction is "passes the pin" only, with nothing beyond it;
   - the `SurfaceCellFactoryRejectionSite` negative still rejects, at (0,4);
   - at least one proposed negative proves that the narrowed pin still rejects a one-face gauge change inside a hard-feature region's gauge domain.

**Out of scope:**
- code, tests, builds and runs;
- the M1 binding (RA-105.3);
- the R-route;
- fixture debt;
- edits to frozen RA text.

**STOP and return to Review** if any of these holds; each would falsify H-pin:
- a producer whose gauge domain includes a hard-feature carrier;
- a production consumer that reads a face-gauge difference across an excluded edge.

**On success:** `M6-CP3-DEFN-P1-GAUGE-PIN-DOMAIN-REV` (Review, mandatory).

#### RA-110.6 Sequence and accounting

- **Sequence:** DEFN-P1 → DEFN-P1-REV → [CB20, the pin domain, compile only → TB20, artifact-only on the nine M2 identities plus controls → TB20-REV] → DEFN on the M1 binding owner (RA-105.3) → corrective CB/TB → fixture debt → census → RP-01 Review. The bracketed turns are planned and are authorized only by DEFN-P1-REV.
- **Accounting is unchanged:** 66/17/49, debt 1, CP2 491/491, R3 403/497 rejected, TB18 candidate 448/497, selector 497. `RP-01` is open, `RP-02` is UNREACHED and Gate C is suspended.

## `Architecture_M6_CP3_TB19_Torus_Staging_Review_Decision.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_TB19_Torus_Staging_Review_Decision.md`; moved verbatim.

### RA-108 — TB19 run read: torus rows unmeasured (fixture staging); TB19 closes on 16 valid rows; TB19A reruns the torus (2026-10-20)

**Turn:** `M6-CP3-TB19-RP01-TORUS-STAGING-REV`. **Inputs:**
- TB19 dispatch run `39464430751` (executor `f8e6e3efc`, harness SHA-256 `c33014b5…5b5c`);
- result artifact `12285225197`, ZIP SHA-256 `2b5dfacf79e068cad8e28af5c840668c3f26287a2a473fade63924d12d77dec0`, expires 2026-11-03T17:19Z;
- TB18 Part B artifact `12232299548` (raw logs, for comparison).

**State.** TB19 is `IN_PROGRESS` and has no report yet. **Why Review now:** the run finished, and six rows carry a defect that RA-107.3's harness rule caused. This record rules only on which rows are valid and on what runs next. It is not TB19-REV: H-pin, the R-route and the DEFN stay with TB19-REV. **S** = `src/geometry/SurfaceCellTracing.cpp`, **TQ** = `tests/SurfaceCellTransitionQuotientTests.cpp`, both at `d2c7483cd`.

#### RA-108.1 What the artifact shows (re-derived independently)

- **Integrity:**
  - the provider digest equals the ZIP SHA-256;
  - `SHA256SUMS` 26/26;
  - raw-log hashes 22/22;
  - boundary: planned 22, executed 22, missing 0, red 19, postflight true, exit 0, no compile, relink or benchmark;
  - GMP linked.
- **`cp3entry:2` and `cp3entry:6`:** RED with `product=0 detail=none site=gauge-pin-consistency;edge=1,4`.
- **`focused30:12`:** RED at TQ:5036 with `product=0 site=gauge-pin-consistency;edge=1,4`. The ledger's product and site columns are empty: the harness extracts only from `producer failed:` lines, and this row fails a direct factory assertion. The values are taken from its first-failure text.
- **M1 (10 rows):**
  - nine are byte-identical to the TB18 Part B raw logs after the RA-107.2 line mapping;
  - `focused30:3` is identical to its TB18 inventory text.
- **Controls:** 3/3 PASS.
- **Torus (6 rows):** `cp3entry:1`, `focused30:6/20/24` and `selector:446/447` are RED with `Directional test-data package not found adjacent to test executable: …/view/bin`. In TB18 they reached `torus nonzero-Z4 source witness producer failed: PublishedProductRejected` (TQ:1672).
- **Observation for TB19-REV:**
  - the `cp3entry:2/6` fixture (TQ:787) declares hard edges (1,4) and (4,7) (TQ:841);
  - it rotates the field a quarter-turn on faces whose centroid has x > 1 (TQ:827);
  - edge (1,4) is therefore a hard-rail carrier that crosses a deliberate field discontinuity. This is recorded here and not adjudicated.

#### RA-108.2 The torus defect: cause and ownership

- **Cause.** Harness line 56, `shutil.copytree(src/"benchmarks/fixtures", view/"test-data/benchmarks")`, puts the fixture tree at `view/test-data/benchmarks/milestone-g/…`. `find_test_data_root` (`tests/TestFixturePaths.h:53`) requires `view/test-data/benchmarks/fixtures`. The 497 harness stages the tree correctly (`m6_cp3_entry_497_artifact_only_harness.sh:249–250`).
- **Inherited from the template.** The line is verbatim from `open_rail_interior_vertex_harness.sh`. None of that harness's 14 tests loads a fixture, so the defect was latent there.
- **Owned by Review.** RA-107.3 said "copy it, change only …" and required no control that loads a fixture. The agent's harness follows RA-107.3, so this is a gap in Review's specification, not an implementation error (LESSONS §7, fixture portability).
- **Exit 0 does not validate the six rows.** They never reached the producer; their RED status matches TB18 only by coincidence.
- **The other 16 rows are unaffected.** Only the six torus logs contain the not-found message, and the three controls pass. None of the 16 reached `test_data_root()` before its first failure or its pass, so staging cannot have changed them.

#### RA-108.3 Validity ruling

- **Valid:** rows #2, #3, #5 and #10–#22 (16 rows).
- **Invalid, NOT MEASURED:** the six torus rows (#1, #4, #6–#9). They are not evidence for F1 or F3.
- **R-route: NOT REACHED** (not "held"). The gauge pin (S:8509–8567) runs before the certificate loop (S:8782), so `cp3entry:2/6` reject before any endpoint clause runs.
- **Falsifier lines for the TB19 report:**
  - F1: held on the 16 valid rows; torus not measured;
  - F2: held;
  - F3: held for `focused30:12` (edge 1,4); torus not measured;
  - F4: held, 10/10;
  - RA-103.5 R-route: not reached;
  - RA-106.5 non-zero code: none, so no follow-up.
- **Left to TB19-REV:** H-pin, the meaning of the edge (1,4) result, and the scope of the DEFN.

#### RA-108.4 TB19 closeout — `M6-CP3-TB19-RP01-FACTORY-REJECTION-SITE` (no dispatch)

- **Output:** `Architecture_M6_CP3_TB19_Factory_Rejection_Site_Harvest_Report_20261020.md`, built from artifact `12285225197` as RA-107.3 specifies, plus:
  - all 22 rows; the six torus rows marked `NOT MEASURED — fixture staging (RA-108.2)`;
  - `focused30:12` product and site taken from its first-failure text, and detail `not streamed`;
  - the falsifier lines exactly as RA-108.3 gives them.
- **Forbidden:** a new harness, a dispatch or rerun, any source/test/selector/fixture change, and any adjudication.
- **On success:** TB19A.

#### RA-108.5 TB19A — `M6-CP3-TB19A-RP01-TORUS-REJECTION-SITE` (Test + Benchmark, artifact-only)

##### Harness

New `.agents/Directional/tools/m6_cp3_tb19a_torus_rejection_site_harness.sh`, a copy of `m6_cp3_tb19_factory_rejection_site_harness.sh` with only these changes:
1. **Staging:** `shutil.copytree(src/"benchmarks/fixtures", view/"test-data/benchmarks/fixtures")`.
2. **Pre-execution check:** `view/test-data/benchmarks/fixtures/milestone-g/torus.obj` and `torus.rawfield` must both be files.
3. **Per-row check:** a raw log that contains `test-data package not found` is a harness failure.
4. **The 7-row list below,** with count checks of 7 and output labels `TB19A`.

Everything else is unchanged:
- the same package pins (source `d2c7483cd…`, artifact `12275794192`, digest `e4a39cdb…d723a`);
- the 28-entry manifest and the frozen-selector hashes;
- the GMP and `runtimeExecution=false` checks;
- one test per filter;
- the extraction;
- the postflight check.

##### Rows

| # | Group | Identity | gtest | TB18 | Prediction |
|---|---|---|---|---|---|
| 1 | M2 | cp3entry:1 | `M6CP3.PeriodicExactA3UnequalFaceGaugeUsesRelationAndOccurrenceAuthority` | RED | RED, `product=0 detail=none site=gauge-pin-consistency;edge=…` |
| 2 | M2 | focused30:6 | `M5CP3.ProducedTorusPeriodicPairStorageSwapPreservesSemanticDirection` | RED | as #1 |
| 3 | M2 | focused30:20 | `M6CP1.NonzeroZ4WitnessPassesProductionCompletionOwnership` | RED | as #1 |
| 4 | M2 | focused30:24 | `M6CP1.ThinAdapterOutputIsPureProjectionOfStageProducts` | RED | as #1 |
| 5 | M2 | selector:446 | `M5CP3.ProducedTorusNonzeroZ4RotationTranslationMaterializes` | RED | as #1 |
| 6 | M2 | selector:447 | `M5CP3.ProducedTorusTamperedNonzeroZ4TransformRejectsTyped` | RED | as #1 |
| 7 | control | selector:443 | `M5CP3.ProducedTorusPublishesTwoCanonicalPeriodicRelationsAndOwnedEdges` | PASS | PASS |

**Why `selector:443` is the control:**
- it loads `milestone-g/torus.obj` through `torus_fixture()` (TQ:883 → TQ:708);
- it is in selector 449, and TB18 Part B passed it.

A PASS proves that the binary resolves the staged root. It also shows a torus product that clears the pin.

##### Falsifiers and output

- **Falsifiers.** Report each as held or fired:
  - **G1:** row #7 is not PASS. This means a staging failure or a regression, and it is a STOP.
  - **G2:** a torus first failure other than `torus nonzero-Z4 source witness producer failed: PublishedProductRejected` plus the appended fields.
  - **G3** (RA-107.3 F3): a torus site other than `gauge-pin-consistency`.
  - **G4** (F2): `product=0` with an empty site.
- **Not falsifiers:**
  - the reported edge, which is recorded, not predicted;
  - a non-zero `product=`, which is recorded under RA-106.5.

> **Amended by RA-109.4:** the report also classifies each torus site's edge against the 18 `torus_row408_hard_edges`.

- **Output:** `Architecture_M6_CP3_TB19A_Torus_Rejection_Site_Harvest_Report_<date>.md` with:
  - the run, the artifact and the ZIP SHA-256;
  - manifest counts;
  - the 7-row ledger (TB18 status, TB19A status, first failure, product, detail, site, raw SHA);
  - G1–G4 held or fired.
  - No adjudication.
- **Forbidden:**
  - compiling or relinking;
  - source, test, selector or fixture changes;
  - benchmarks and test discovery;
  - any repair.
- **STOP:** a harness verification failure, an expired package (2026-10-27T15:24Z), fewer than 7 identities selected, or G1. Preserve the evidence and return to Review.
- **On success:** TB19-REV (mandatory), over the TB19 and TB19A reports together.

#### RA-108.6 Sequence and accounting

- **Sequence:** TB19 closeout → TB19A → TB19-REV (mandatory). TB19-REV rules on H-pin on rail carriers (from the three rectangle rows) and on periodic cuts (from TB19A), records the R-route as not reached, and orders the DEFN. Then: [DEFN on the gauge-pin domain and the M1 binding owner → corrective CB/TB] → fixture debt → census → RP-01 Review.
- **Accounting is unchanged:**
  - 66/17/49, debt 1;
  - CP2 491/491;
  - R3 403/497 rejected;
  - TB18 candidate 448/497;
  - selector 497.

  `RP-01` is open, `RP-02` is UNREACHED and Gate C is suspended.

## `Architecture_M6_CP3_TB1_Entry_R1_Review_Record.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_TB1_Entry_R1_Review_Record.md`; moved verbatim.

### M6-CP3-TB1-ENTRY-R1-REV — Independent Review Record

**Disposition:** REJECTED FOR BOUNDED DEFINITION REPAIR / CANDIDATE UNPROMOTED
**Reviewed candidate:** `11488700954 / 68000a95a94b1d95f22694dc093dc6a538e1b7b4`
**Runtime:** dispatcher `37645974118`, runtime job `112876903729`, result `11495166428`, **482/497**
**Exact successor:** `M6-DEFN-R5-R1`

#### 1. Evidence and mechanical validity

Review independently reuses the immutable R1 evidence: result artifact `11495166428` has provider/download SHA-256 `5ee8380ee7bb557a58274ef0b7cefa47e1abf1ef549650afcb7fff1330f161a6`; its self-manifest verifies **1019/1019**. The gate is exactly focused30 30 + focused12 12 + selector449 449 + six CP3-entry identities = **497** fresh exact-filter processes. Result: focused30 **23/30**, focused12 **12/12**, selector449 **446/449**, CP3-entry **1/6**, aggregate **482 PASS / 15 RED**; exact-one 497/497, zero skips, benchmark 0, immutable package/source/execution-view postflight. No configure, compile, relink, discovery, repair or retry occurred.

The six CP3 identities are unchanged. Identity 6 passes; identities 1–5 are RED. The RA-31a target of 496 PASS plus identity 2 RED only at withdrawn-certificate assertions is therefore **not met**.

#### 2. Independent candidate adjudication

| Group | Rows | Review disposition |
|---|---:|---|
| R1-CAND-01 | 10 | **FAILED RECOVERY of the already-open stable `RP-01 / AUTHORITY_DOMAIN_CONFLATION` event; +0 new event** |
| R1-CAND-02 | 1 | NON-STABLE D1 produced-witness non-vacuity defect |
| R1-CAND-03 | 1 | NON-STABLE D2 definition/witness non-vacuity defect; RA-31a Definition owner applies |
| R1-CAND-04 | 1 | NON-STABLE D3 real-producer fixture/reachability defect |
| R1-CAND-05 | 1 | NON-STABLE D4 test selector/oracle defect |
| R1-CAND-06 | 1 | NON-STABLE D7 real-producer fixture/reachability defect |

##### R1-CAND-01 — P2 recovery still keys seam authority from global sheet labels

Five direct rows report `MissingIsolationSeamEquivalenceAuthority:a6-side-evidence`; five later rows fail because the A6/arrangement/view product does not exist. Static review finds A6 enters its special path when the two endpoint spans name the same `collinearEdge` and their `interiorBinding.sheet` values differ. Only *after* that classification does it require reciprocal isolation evidence, exact transitions and `isolationSeamTransportCertificate`.

That is still the authority-domain error RA-31 P2 intended to remove: global sheet inequality is not itself proof that this OrdinaryFront is the **certified cross-sheet collinear isolation-seam relation**. The correction moved the evidence check but did not move the branch discriminator onto certified relation-owned evidence. These ten rows are continuation of predecessor CAND-02, not another accepted→RED transition. Preserve non-seam full representation equality and all certified-seam exact checks; do not relax them.

##### R1-CAND-02 — D1 witness is still non-vacuous only in name

Identity 1 reaches a produced semantic relation but its endpoint face gauges are not separated by 90°/270°. RA-30a §7 and RA-31a §6 explicitly classify this as test-authority RED and require Review if no organic pair exists. No product defect is established. The next Definition must freeze the producer/search and stop rule before another implementation attempt.

##### R1-CAND-03 — D2 cannot be completed before its withdrawn contract is redefined

Identity 2 now reaches green A5 baseline semantics on the same recovered family for which identity 6 passes, but it cannot find the required produced HardRail with a 90°/270° endpoint-gauge delta. This fails *before* the pre-registered withdrawn-certificate assertions. RA-31a §3 already assigns the certificate and discriminating witness to `M6-DEFN-R5-R1`; Review therefore does not invent another formula or hand-built witness here. The Definition must derive the rule from cross-rail field matching `τ(f_a→f_b)` and name the producer and discriminating real-produced fixture.

##### R1-CAND-04 / R1-CAND-06 — the current split fixture proves a seam exists, not that the tracer produces the required seam-collinear OrdinaryFront

Identities 3 and 5 both obtain a valid produced A5 product but cannot find an OrdinaryFront relation whose endpoint spans are collinear with the same isolation seam and carry the required certificate. The helper `split_isolation_fixture()` is ordinary split-square geometry; materialization and presence of a seam certificate do not imply that a traced front side is seam-collinear with that seam. D3 and D7 explicitly require a **real-tracer produced** seam-collinear witness. These are test-fixture reachability defects; no hand-built relation records are authorized.

##### R1-CAND-05 — D4 chooses a type, not a route-bearing carrier

Identity 4 selects the first `OrdinaryInterior` source edge and then assumes its source route is non-empty. Runtime disproves that assumption. `OrdinaryInterior` does not imply a non-empty A4 route. The test must select or derive an actually route-bearing ordinary carrier before applying the hard-feature tamper, while preserving the existing Periodic/HardRail typed-source barrier checks. No A5 production change is established by this RED.

#### 3. Recovery proved and stable accounting

Predecessor CAND-01 (`INCOMPLETE_AUTHORITY_PUBLICATION`) is **recovery-proved** by the disappearance of its 110-row failure chain after P1; predecessor CAND-07 (`RP-02 / TEST_AUTHORITY_COVERAGE_GAP`) is **recovery-proved** by the recovered focused30 relabel. Predecessor CAND-02 (`RP-01 / AUTHORITY_DOMAIN_CONFLATION`) remains **OPEN / failed recovery** through R1-CAND-01.

No new accepted-green loss is created by the R1 candidate. Historical stable totals remain **63 events / 17 categories / 46 recurrences**. Produced-witness debt remains **1** (`G4-B002`). The R1 candidate is rejected and unpromoted; reviewed runtime authority remains CP2 `11391685901 / 5ce3132ec01748eff5b15f82be07a1abe2bd1af6` until CP3 entry is independently accepted.

#### 4. RA-32 routing

Review freezes **RA-32** in `Architecture_M6_Frozen_Definitions.md` and routes next to runtime-free `M6-DEFN-R5-R1`. That Definition must resolve five bounded authority questions before another Code + Build:

1. certificate-owned A6 seam-path discrimination for P2, never raw global-sheet inequality;
2. D1 organic exact-A3 90°/270° witness selection and stop rule;
3. D2 `τ`-based HardRail contract, publishing owner, path-independence/singularity rule and discriminating produced witness;
4. D3/D7 real-tracer seam-collinear OrdinaryFront fixture/non-vacuity;
5. D4 route-bearing ordinary carrier selection/oracle.

Mandatory Definition Review follows. Only if it accepts RA-32's amendments may one bounded R2 Code + Build be released. CB2 (D5/D6/D8) remains held until the CP3 entry gate is fully green.

#### 5. Closeout

Review is documentation/evidence only. It changes no product source, test, fixture, selector, routing list or runtime. The R1 runtime report remains the current mechanical evidence; this record becomes the current Review; `Architecture_M6_DEFN_R5_R1_CP3_Entry_Recovery_Definition_Plan.md` is the sole next-turn plan.

## `Architecture_M6_CP3_TB1_Entry_R2_Review_Record.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_TB1_Entry_R2_Review_Record.md`; moved verbatim.

### M6-CP3-TB1-ENTRY-R2-REV — Independent Review

**REJECT R2 (444/497, 53 RED).** The full independent Review report is preserved in personal Library `/Directional/Evidence/M6-CP3-TB1-ENTRY-R2-Independent-Review.md`. The 53-identity classification is committed as `Architecture_M6_CP3_TB1_Entry_R2_Red_Classification.tsv`; immutable test artifact `11545716507` (run `37767144537`), outer SHA256 `d6469bea1b4ef6fb3b142d05a97d01dbab98331cfc91d930c7bc30da555ec0ca`.

Independent CP2 / R1 / R2 comparison: accepted CP2 491/491, rejected R1 482/497 and rejected R2 444/497; 47 accepted CP2 identities are RED in R2; 38 R1 PASS→R2 RED, zero recoveries. Seven evidence groups: typed A4 InvalidHardRailRouteCertificate 25, Phase10 downstream 12, periodic odd real-producer witness absent 5, torus A5/A6 downstream 6, D3/D7 seam-aligned tracer positive absent 2, D5 ordinary route baseline absent 1, RE-package terminal mismatch 2.

**New stable event:** A4 HardRail certificate false-rejection of prior accepted-green source fixture: +1 event in existing `RP-01/AUTHORITY_DOMAIN_CONFLATION`, +1 recurrence; total **64/17/47**, debt 1. RA-36.1's consecutive-edge common-face premise is unsound on the supported 3×3 two-HardRail-edge fixture: edge (1,4) faces {0,3}, edge (4,7) faces {4,7}; no common incident face. A4 implementation `src/geometry/SurfaceCellTracing.cpp:18260–18372` uses direct face equality without side-fan transport. This is a static supported-input counterexample, **not** proof of a produced two-edge route; first rejecting predicate remains unlocalized. Preserve RA-36 until revised Definition independently reviewed; do not silently relax it.

**Disposition:** Product R2 candidate UNPROMOTED; CP2 remains accepted. Organic D1/D2/D3/D5 positives unproved; older A6 RP-01 event still open; no RB/CB2/CP3 exit work authorized. **Exact successor:** `M6-DEFN-R5-R3` runtime-free Definition to propose RA-37 with typed vertex-fan-side A3 transports and preserve all false-rejection, witness and 497-process regression gates; mandatory `M6-DEFN-R5-R3-REV` before a new Code+Build turn. Prescriptive full plan `/Directional/Evidence/M6-DEFN-R5-R3-CP3-Entry-Recovery-Plan.md`. No product, test, fixture, selector or workflow change or execution in this Review.

#### Exact mechanical reconstruction and accepted-green comparison

Independent artifact fetches verified three immutable results: accepted CP2 `37419256039 / 11393198123` SHA-256 `0e4e550a09e4fb38b58bfcef2e57db6dcea865a1c46b384b5a288d5c491606bb` with 1005/1005 manifest; rejected R1 `37645974118 / 11495166428` SHA-256 `5ee8380ee7bb557a58274ef0b7cefa47e1abf1ef549650afcb7fff1330f161a6` with 1019/1019; rejected R2 `37767144537 / 11545716507` SHA-256 `d6469bea1b4ef6fb3b142d05a97d01dbab98331cfc91d930c7bc30da555ec0ca` with 1019/1019. All 491 CP2 case names and phase+ordinal positions **exactly match** the corresponding R2 cases. R2: focused30 15/30, focused12 10/12, selector449 419/449, CP3entry 0/6. Exact-one 497/497, no skips/benchmarks, unchanged package/source/execution-view before/after and no configure/build/retry. **47/491** previously accepted GREEN cases now RED; relative to R1 **38 newly RED, 0 recovered**, all 15 R1 RED remain.

##### Exhaustive 53-row classification (independent Review, not mere log keyword totals)

- **CAND-01: 25 direct A4 HardRail typed rejects**. `InvalidHardRailRouteCertificate` on the originally accepted two-edge 3x3 hard-feature fixture, Phase10 and source typed route examples, plus new identity6 and already-R1-red identity2. The root family is a distinct new product false rejection introduced in A4 by R2. There are 23 previously green CP2 cases within this group (22 newly failing vs R1 plus previously red focused30 ordinal24). This is one stable event, not 25. Failure-site predicate within `invalid_route()` is not exposed by the log; below is a static topology falsifier, **not** identification of the runtime step that failed.
- **CAND-02: 12 dependent Phase10 production failures.** Selection/test first needs `SurfacePhaseFrontProduct::Produced` but receives `Rejected` or cannot reach the expected feature authority or final oracle. Selector ordinals 116,122,130,132,134,137,139,140,142,143,406,407. Likely A4-origin cascades, independently unlocalized. Keep diagnostics and do not assign a second stable event.
- **CAND-03: 5 periodic odd witness absences.** Focused30 ordinals 6/20, selector 446/447, CP3entry 1. R2 `make_nonzero_z4_torus_witness_fixture()` enumerates source/A3 candidates, filters by selected-face delta 1 or 3 and then requires a real reciprocal tracer-produced PeriodicCut pair/cut route. R1's helper called weaker `select_torus_source_witness()`, with no same bounded odd-producer test. Selector447's newly failed status is **test-authority tightening**, not by itself a production feature regression.
- **CAND-04: 6 existing torus A5/A6/arrangement RED**. Focused30 25–28, selector444/448 all already R1 RED; inherited failed recovery of separately counted old A6 RP-01. No claim R2 A6 repaired these. No new count.
- **CAND-05: 2 D3/D7 organic seam-collinear fixture gaps.** CP3 identities 3 and 5 produce no fully certified reciprocal cross-sheet OrdinaryFront on the bounded axis-aligned fixture. Their intended A6/A7 certified-seam positive/tamper checks are never reached; non-stable fixture/witness gap.
- **CAND-06: 1 D5 ordinary source-route oracle gap.** CP3 identity4 fails at `baseline != nullptr`; typed barrier mutation is not reached. Non-stable test-oracle/producer-reachability gap.
- **CAND-07: 2 RE-package terminal mismatches.** Selector176/201 observe `NotProductionReady` instead of expected `InjectedStageFailure`. Review cannot assign them independently of A4/A5 first failure from the existing logs; keep provisional dependent status and do not count twice.

The authoritative *one row per failing identity* receipt includes CP2 and R1 prior state, extracted R2 first diagnostic and immutable raw log path: `Architecture_M6_CP3_TB1_Entry_R2_Red_Classification.tsv`. All seven buckets sum 25+12+5+6+2+1+2=53 without overlap. The preserved full raw result is in personal Library `/Directional/Evidence/M6-CP3-TB1-ENTRY-R2-EXEC-result-37767144537.zip` as well as GitHub artifact `11545716507` (expires 2026-10-22).

#### Static architectural counterexample and limits

Frozen RA-36.1 states **consecutive feature carriers share exactly one typed incident source face**. In supported 3×3 rectangle fixture, source edges (1,4) and (4,7) are consecutive and share vertex4, but their source face pairs are respectively `{0: (0,1,4), 3: (1,5,4)}` and `{4: (3,4,7), 7: (4,8,7)}`. Their intersection is empty. This disproves the **universal face-sharing premise for supported input polylines**, not the existence of a produced two-edge paired route. The implementation `SurfaceCellTracing.cpp:18300–18321` requires each successive rail carrier's two incident faces to contain its `current` face, even though its vertex-star `railFanPotentials` graph can contain non-rail A3 transitions connecting two otherwise distinct side faces. A valid typed vertex-fan transfer may exist without direct carrier-pair face equality. Frozen RA-36.3 already calls for independently derived `φ_a`, `φ_b` side transports and commuting `χ_(i+1) ∘ φ_a = φ_b ∘ χ_i`; present code cannot reach that check if it rejects the missing face identity first. A naked fold of cross-rail `χ_i` also requires domain/target proof; the two crossing maps need not compose as if they were a path along one side.

**Important evidentiary distinction:** existing runtime logs do **not** reveal which specific check inside `invalid_route()` failed for each typed source. A later approved Code+Build must add diagnostic-first-locus information without changing production semantics and then prove any corrected path with *real-produced* positive and negative artifacts. The independent R3 Definition must reconcile RA-36 itself; this Review flags the frozen premise but does not silently amend it. Singular/disconnected fan, nonreciprocal atlas, foreign rail owner, route ambiguity and mixed orientation must continue typed fail-closed. Singleton case (one edge, exact incident faces and `firstToSecond`) must remain accepted.

#### Accounting and exact next gate

**New stable event +1 in existing `RP-01/AUTHORITY_DOMAIN_CONFLATION`** for A4 rejecting accepted-green HardRail features using an inapplicable face-adjacency surrogate. Its pattern/category recurs: `63 events / 17 categories / 46 recurrences → 64 / 17 / 47`, debt 1. This newly counted source-transport event is **distinct** from old open A6 seam-domain RP-01 (CAND-04); dependent CAND-02/CAND-07 and non-stable organic gaps do not spawn extra event IDs. R2 is REJECTED and UNPROMOTED. Only authorized successor **`M6-DEFN-R5-R3`** (runtime-free Definition, candidate RA-37 with typed source-face-star side transport, full odd/wedge/seam/ordinary organic requirements) may proceed after formal STATUS completion; mandatory independent **`M6-DEFN-R5-R3-REV`** before Code+Build. No test execution or source mutation occurred in this Review. Full prescriptive plan: `Architecture_M6_DEFN_R5_R3_CP3_Entry_Recovery_Definition_Plan.md` and its expanded durable Library version.

---

#### Independent verification addendum (reviewing agent)

Runtime-free. **Upheld in full. The RA-36.1 falsifier is correct, and the unsound clause is mine.** Accounting
**64 / 17 / 47**, debt **1**, is right. I decline to amend RA-36 here; reasoning in V5.

##### V1 — the counterexample is exact, and it generalizes beyond the fixture

Verified independently from `tests/SurfaceCellTransitionQuotientTests.cpp:694-740`. The 3×3 grid triangulates
per quad as `(lowerLeft, lowerRight, upperRight)` then `(lowerLeft, upperRight, upperLeft)`, giving
`0=(0,1,4), 1=(0,4,3), 2=(1,2,5), 3=(1,5,4), 4=(3,4,7), 5=(3,7,6), 6=(4,5,8), 7=(4,8,7)`. Hence:

- edge `(1,4)` → faces **{0, 3}**
- edge `(4,7)` → faces **{4, 7}**
- intersection **∅** — exactly as reported.

This is not a fixture accident. Two **collinear** edges meeting at a vertex can never share a face, because a
triangle containing `1, 4, 7` would be degenerate. So RA-36.1's clause *"consecutive steps share exactly one
typed source face"* is false for **every** polyline carrier pair in a proper triangle mesh, not merely this one.

##### V2 — the clause was self-defeating

RA-36 rejected the singleton-only contract **on the grounds that polyline hard features are legitimate** — citing
these very edges `(1,4)`/`(4,7)` as a real producer input — and then froze a connectivity clause that polylines
structurally cannot satisfy. The falsifier therefore *strengthens* the singleton-only rejection (polylines are
real and must work) while destroying the premise I attached to it. That is my error, not the producer's, and the
25 `InvalidHardRailRouteCertificate` rejects on previously accepted-green evidence are its direct consequence.
Recording it as **+1 event / +1 recurrence in existing `RP-01/AUTHORITY_DOMAIN_CONFLATION`** is the correct
classification: a rule asserted authority over a domain it had not established.

##### V3 — the error is a primal/dual category mistake, and the fold is wrong in kind

Connectivity "share exactly one face" is the **dual** notion: a face-to-face transition path, where consecutive
steps cross different edges *of the same triangle* and so do share a face. But a HardRail route's steps are
**primal** rail carriers — collinear feature edges — which meet at a **vertex**. The connecting structure is
therefore the **vertex fan**, never a shared face.

The Review is also right that the composition is wrong in kind, not just the connectivity: *"the two crossing
maps need not compose as if they were a path along one side."* My "typed fold" wording implied walking one side
and accumulating χ. The correct form alternates cross-rail and along-side transport,

```text
τ_ab = χ_n ∘ φ_{n-1} ∘ … ∘ φ_1 ∘ χ_1
```

with RA-36.3's square `χ_(i+1) ∘ φ_a = φ_b ∘ χ_i` as the consistency condition and path-independence required
across admissible fan paths. RA-36.3 half-anticipated this; RA-36.1/.2 contradicted it.

##### V4 — the authority already exists in A4, and my clause made already-written code unreachable

This is the part worth adding to the Review's evidence. A4 **already computes** per-vertex fan potentials:
`railFanPotentials` is declared at `src/geometry/SurfaceCellTracing.cpp:18120`, populated at `:18206`, and
**already consumed by junction logic** at `:18337-18342`, which resolves `a0, a1, b0, b1` potentials at a
`junction` vertex. So the φ authority and the junction handling both exist.

Two defects follow, neither of which needs new invention:

1. `railFanPotentials` has **zero header references** — it is a local, unpublished value, so A5 cannot consume it
   even though RA-36.2 requires A5 to validate published evidence only.
2. My face-identity gate at `:18312-18321` threads a single `current` face and rejects when a carrier's incident
   pair contains neither — which, per V1, is the generic polyline case. It therefore rejects **before** the
   junction logic at `:18337` can run.

So the clause did not merely over-constrain: it rendered correct, already-written fan handling **unreachable** —
the same pattern diagnosed at `M5-CP3-TB1-R3-REV`, where CB4's valid seam re-validation never executed because
its guard was deterministically false. And the cure is the one RA-34.3 and RA-35 already established twice in
this milestone: **publish the authority the producer already holds**, rather than add new computation or let a
consumer infer it.

##### V5 — I decline to amend RA-36 myself, and the Review was right to flag rather than relax

Precedent exists for a Review withdrawing a false frozen clause — RA-31a withdrew `C = F⁻¹∘B` on exactly this
basis. I am not taking it here, for two reasons. The only authorized successor is a **runtime-free Definition
turn** (`M6-DEFN-R5-R3`) chartered to reconcile RA-36 into RA-37, so there is no window in which a Code + Build
turn implements against the unsound clause. And amending my own frozen rule outside the turn chartered to
reconcile it would fragment authority in precisely the way this project has repeatedly been bitten by.

What must not happen is a reader treating RA-36.1 as sound in the interim, so I annotate its **status** —
unsound, counterexample recorded, owner R3 — without relaxing its content. That matches the Review's
instruction to *"preserve RA-36 until revised Definition independently reviewed; do not silently relax it."*

##### V6 — what this Review got right, and it is not small

It recorded a **new stable event against a reviewer's own frozen premise** rather than softening the number to
protect it — 64 / 17 / 47 with the false-rejection attributed to RA-36.1 by name. It kept the singleton case
accepted, preserved every RA-34.3 stop gate, left the R2 candidate unpromoted with CP2 still accepted, and
declined to infer the replacement contract from a static counterexample. It also noted that the runtime logs do
**not** reveal which predicate inside `invalid_route()` fired first, and required diagnostic-first-locus before
any corrective change — the instrumentation-before-guessing discipline that ended fifteen turns of static
guessing in M5-CP3. Routing to R3 for RA-37 with typed vertex-fan-side transports is the right successor.

##### V7 — verification limits

Re-derived from repository bytes: the fixture triangulation and both edges' incident face sets; the degeneracy
argument for collinear carriers; the single-`current`-face threading at `:18300-18321`; `railFanPotentials`'
declaration, population, junction consumption and absence from any header. Accepted as reported: the 444/497
tally, the seven evidence groups, the 38 R1→R2 transitions and the per-group RED classification, which are
runtime facts of the reviewed artifact.

## `Architecture_M6_CP3_TB20_Gauge_Pin_Domain_Review_Decision.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_TB20_Gauge_Pin_Domain_Review_Decision.md`; moved verbatim.

### RA-114 — TB20 reviewed: corrected pin confirmed at runtime; M2 cleared at the factory; selector-497 census next (2026-10-21)

**Turn:** `M6-CP3-TB20-RP01-GAUGE-PIN-DOMAIN-REV`. **Input:** TB20 run [39527537505](https://github.com/akashskypatel/Directional/actions/runs/39527537505), harness `m6_cp3_tb20_gauge_pin_domain_harness.sh` (`18a1325d2`, SHA-256 `69b173e5…48bb`). The agent left TB20 `IN_PROGRESS` after dispatch and wrote no report. As in RA-113, this decision holds the verified harvest facts. **Lines:** TQ = `tests/SurfaceCellTransitionQuotientTests.cpp` at `e22c5da5f`.

#### RA-114.1 Harvest verified

- **Harness:** its diff from TB19A is exactly the RA-113.5 set: sha, artifact, digest, the 26 rows, the count and the labels.
- **Result artifact:** `12314700010`, ZIP SHA-256 `3731402f871f042fbaa0540304e28e65c8add9f73233cba704b8c9e1f5d7787f`, expires 2026-11-04T01:35:20Z. Its `ledger.tsv` has SHA-256 `a9dae84c2a23dc4b59c1fc98ed0181323f8bc81f852b03f14d0f4c0581f06c83`.
- **Integrity:** 30/30 result hashes verify; planned = executed = 26; missing 0; 19 RED; postflight immutability true for the package, source, view and frozen selectors.

| # | Group | Identity | Baseline | TB20 | TB20 first failure |
|---:|---|---|---|---|---|
| 1 | M2 | cp3entry:1 | TB19A RED (pin `0,3`) | RED | torus witness not found (TQ:1745) |
| 2 | M2 | cp3entry:2 | TB19 RED (pin `1,4`) | RED | TQ:3024: no produced paired (1,4)→(4,7) hard-rail route certificate |
| 3 | M2 | cp3entry:6 | TB19 RED (pin `1,4`) | **PASS** | — |
| 4 | M2 | focused30:6 | TB19A RED (pin `0,3`) | RED | torus witness not found (TQ:1745) |
| 5 | M2 | focused30:12 | TB19 RED (pin `1,4`) | RED | TQ:5121: `produceA5` on the relabelled front returns no complex |
| 6–9 | M2 | focused30:20, focused30:24, selector:446, selector:447 | TB19A RED (pin `0,3`) | RED | torus witness not found (TQ:1745) |
| 10–19 | M1 | the ten RA-113.3 M1 rows | TB19 RED | RED | 10/10 equal to TB19 after the +77 TQ mapping |
| 20–22 | control | selector:217, TB18 A#14, selector:443 | PASS | PASS | — |
| 23–25 | suite | the three `SurfaceCellFactoryRejectionSite` tests | new | PASS | — |
| 26 | oracle | A6UniformFaceGaugeRotationPreservesRelationOutcome | R4 RED | RED | TQ:2944: `originalOccurrences` is null, before any gauge assertion |

The torus message is byte-identical in all six rows: `sourceA3Candidates=5; sourceFaceGaugePairs=5; oddFaceGaugePairs=0; reciprocalTracerPairs=0; publishedPeriodicHolonomies=18; nonzeroHardCarriers=5`.

#### RA-114.2 Predictions adjudicated

- **P1 observed:** the three suite tests PASS.
- **P2 observed:** no log contains `gauge-pin`.
- **P3 observed:** no log contains `PublishedProductRejected`, so there is no span site and no pin site on a non-hard edge. RA-111.5 stays open but untriggered.
- **P4 observed:** the three controls PASS.
- **Verdict:** CB20/CB20A is accepted at runtime on these 26 rows. Regression safety beyond these rows needs the census (RA-114.5).
- **R-route (RA-103.5):** its falsifier is a checked-factory `InvalidSourceAuthority` on a route the consumer certified with R. It is not observed in any row. M2 is cleared at the checked factory.

#### RA-114.3 M2 after the pin: three outcomes

> *Amended by RA-115.3 (2026-10-21): TQ:1697 is D2 / RA-33.2, not a proxy for odd A3 transport; it sits in a fixture shared with six CP2 rows. H-T2 has no support.*

- **Passing, 1 row:** `cp3entry:6`.
- **Hard-rail certificate area, 2 rows:**
  - `cp3entry:2` constructs its product, but the producer publishes no paired (1,4)→(4,7) route certificate;
  - `focused30:12` passes the factory, which was its TB19 failure at TQ:5113, and then fails in A5.

  Both lie in the area of the M1 binding owner (RA-105.3). The M1 DEFN classifies them; Review does not merge them into M1 now.
- **Torus witness predicate, 6 rows.** The fixture `make_nonzero_z4_torus_witness_fixture` (TQ:1606) drops every candidate whose published face gauges differ by an even quarter-turn (TQ:1697). Its five source/A3 candidates lie on hard carriers.
  - Under RA-111.3, the gauge difference across a hard carrier inside a region is the transport along a non-hard path. That transport is the carrier's A3 transport composed with the cycle's holonomy, which is not the A3 transport itself on a nonzero-Z4 torus.
  - The filter therefore reads a gauge difference outside the RA-111.4 domain, as the old pin did. TB19A measured that inequality at {0,3}.
  - **History:** the filter is absent at CP2 `5ce3132ec`, where the fixture already existed (TQ:1393) and five of these rows were GREEN. It entered with `88aa8eae0` (2026-10-08, M6 CP3 R2).
  - **Hypotheses:**
    - **H-T1:** the filter is a test-side proxy for "odd A3 transport on the carrier" and is invalid under RA-111. The correction is a test-only predicate.
    - **H-T2:** it encodes a producer gauge contract that a later change lost. The correction is in production.

  This is a test consumer, so RA-111.2's STOP does not apply. Deciding between H-T1 and H-T2 is DEFN-T1's job.

#### RA-114.4 Unchanged

- M1 is unchanged: 10/10 identical to TB19.
- The oracle fails before its gauge assertion, so it says nothing about the pin.
- Accounting is unchanged. TB20 is a targeted run and is not a census.

#### RA-114.5 Next unit — `M6-CP3-TB21-RP01-SELECTOR-497-CENSUS` (Test + Benchmark, artifact-only)

**Why now:** CB20 changes every product construction, and TB20 covered three controls. The census is the regression check, and the CB20A package expires 2026-10-28T00:23:30Z.

1. **Harness and inputs.** Run `.agents/Directional/tools/m6_cp3_entry_497_artifact_only_harness.sh` unchanged (SHA-256 `947a95ee4f684143a0f8d7c768a39253ab893d921da488802b45fb6ed58879dd`) with `--execute` and:
   - `CANDIDATE_ARTIFACT_ID=12310848591`;
   - `EXPECTED_SOURCE_SHA=e22c5da5f8ab86a39650c670340a658847a2ac7e`;
   - `EXPECTED_CANDIDATE_ZIP_SHA256=0c9f048e9a67fdaf61231b2ffa6834ee21a48e142f9cdae9e7ab14e015fc3ff5`;
   - `EXPECTED_ROOT_MANIFEST_SHA256=c735e5f76f84a887e0b5613bb65969a68cb4e10321d33a8113167e3978c8206b`;
   - `EXPECTED_SOURCE_ARCHIVE_SHA256=e231fcead36c5436719f13a87b249e2ff6bb69f54c3480fbecee2773d1878f57`.

   Review computed the last two values from the verified package.
2. **Baseline:** TB18 Part B, result `12232299548` (expires 2026-11-03), and `Architecture_M6_CP3_TB18_Selector_497_Red_Inventory.tsv`.
3. **Deliverables:**
   - `Architecture_M6_CP3_TB21_Selector_497_Red_Inventory.tsv`: one row per RED, with columns phase, ordinal, identity, owner, exit, raw_sha256, first_failure, TB18 status and TB18 first failure;
   - `Architecture_M6_CP3_TB21_Selector_497_Census_Report_20261021.md`, at most 30 lines: run, artifact and digest; totals per phase; the TB18→TB21 PASS→RED and RED→PASS lists by name; the TSV's SHA-256. No interpretation.

**Predictions:**
- 0 PASS→RED;
- RED→PASS includes `cp3entry:6`;
- at least 449/497 PASS;
- the other eight M2 rows keep their TB20 first failures;
- no first failure contains `gauge-pin-span` or a `gauge-pin-consistency` site on a hard edge.

**Falsifiers:** any PASS→RED, or any gauge-pin site on a hard edge.

**STOP and return to Review** on:
- a harness orchestration failure or a digest mismatch;
- any need to change the harness.

There is no repair inside the turn.

**Closeout:** the turn is complete only when the report is committed and STATUS is COMPLETE. Do not yield after dispatch; harvest in the same turn.

**On success:** `M6-CP3-TB21-RP01-SELECTOR-497-CENSUS-REV` (Review).

#### RA-114.6 Sequence and accounting

- **Sequence:** TB20 → TB20-REV (RA-114) → **TB21** → TB21-REV → DEFN-T1 → DEFN on the M1 binding owner (RA-105.3), which also classifies `cp3entry:2` and `focused30:12` → corrective CB/TB → fixture debt → census → RP-01 Review.
  - DEFN-T1 is source-only. It compares the torus witness fixture at CP2 `5ce3132ec` with `88aa8eae0` and HEAD, names the invariant behind the odd-gauge filter, and decides between H-T1 and H-T2.
- **Accounting is unchanged:** 66/17/49, debt 1, CP2 491/491, R3 403/497 rejected, TB18 candidate 448/497, selector 497. `RP-01` is open, `RP-02` is UNREACHED and Gate C is suspended.

> *Closed by RA-115 (2026-10-21): TB21 is regression-free (449/497, 0 PASS→RED); CB21 (test-only witness-selection scope) precedes DEFN-T1.*

## `Architecture_M6_CP3_TB21_Selector_497_Census_Review_Decision.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_TB21_Selector_497_Census_Review_Decision.md`; moved verbatim.

### RA-115 — TB21 reviewed: CB20/CB20A regression-free on the 497 selector; torus rows reclassified as a fixture-scope defect; CB21 next (2026-10-21)

**Turn:** `M6-CP3-TB21-RP01-SELECTOR-497-CENSUS-REV`. **Input:** TB21 run [39533914719](https://github.com/akashskypatel/Directional/actions/runs/39533914719) (dispatch `b9c659531`), census harness `m6_cp3_entry_497_artifact_only_harness.sh` (SHA-256 `947a95ee…79dd`, byte-identical at the executor). The agent left TB21 `IN_PROGRESS` after dispatch and wrote no inventory or report. As in RA-113 and RA-114, this decision holds the verified harvest; the RA-114.5 census report is absorbed into RA-115.1. **Lines:** TQ = `tests/SurfaceCellTransitionQuotientTests.cpp` at `e22c5da5f` (HEAD `src`, `include`, `tests` identical).

#### RA-115.1 Harvest verified

- **Result artifact:** `12317287104`, ZIP SHA-256 `12279a26fbe8d2f9d2c4bae6b0317b46b9fb6480212127a59e415fb46f089c8d`, expires 2026-11-04T02:46:55Z. `combined-ledger.tsv` SHA-256 `d4e3d6e5…57f9`, `red-ledger.tsv` `b0f75e2f…5d25`.
- **Integrity:** 1019/1019 result hashes verify; candidate `12310848591` downloaded digest equals `0c9f048e…3ff5`; 497/497 executed, `orchestration_failure=false`, `selection_integrity=true`; postflight package/source/view census equal, all selectors and routing unchanged, manifest 28/28.

| Phase | Total | PASS | RED | TB18 RED |
|---|---:|---:|---:|---:|
| focused30 | 30 | 19 | 11 | 11 |
| focused12 | 12 | 12 | 0 | 0 |
| selector449 | 449 | 417 | 32 | 32 |
| cp3entry | 6 | 1 | 5 | 6 |
| **Total** | **497** | **449** | **48** | **49** |

- **PASS→RED:** none. **RED→PASS:** `cp3entry:6` `M6CP3.HardRailCrossRegionBindingDoesNotCompareGlobalSheetLabels`.
- **First failures against TB18** (all 48 REDs): 24 unchanged; 15 are pure TQ line shifts (each mapped line `3bd24682c`→`e22c5da5f` verified identical); `selector:405` differs only because TB18 recorded the predicate line instead of P10:6975, and its predicate is unchanged; the other 8 are the M2 rows, and each is byte-identical to its TB20 first failure (pointer values aside).
- **Inventory:** `Architecture_M6_CP3_TB21_Selector_497_Red_Inventory.tsv`, 48 rows, SHA-256 `6eb5022a5179ab33ed50e73b3b4cb4094076953667344a3daa767ff997d87c34`. It replaces the TB18 inventory as the census baseline.

#### RA-115.2 Predictions adjudicated

- 0 PASS→RED, `cp3entry:6` RED→PASS, 449 ≥ 449 PASS, the eight M2 rows keep their TB20 failures: **all observed**.
- No log contains `gauge-pin` or `gauge-pin-span`. One log, `selector:250` (curved-disk fixture debt, RED since TB16C, same P10:3598 assertion), prints a `PublishedProductRejected` disposition without a site; it is not a status change, and its site is not readable from the log.
- **Verdict:** CB20/CB20A is regression-free on the frozen 497 selector. TB21 (449/497, 0 PASS→RED) replaces TB18 (448/497) as the candidate evidence. Acceptance and accounting stay with the RP-01 Review.

#### RA-115.3 Torus rows reclassified (amends RA-114.3)

- **The filter is D2, not a proxy.** TQ:1697 implements D2 / RA-33.2 (`Architecture_M6_DEFN_R5_R1_CP3_Entry_Recovery_Definition_Record.md` §D2; `Architecture_M6_DEFN_R5_R2_Review_Record.md`): retain only reciprocal source/A3 witnesses with `(F_b−F_a) mod 4 ∈ {1,3}`, so the identity discriminates relation authority from face gauges. The R2 Review adds: "if absent STOP", and "No synthesized record, loosened test precondition, or selector mutation is authorized." RA-114.3's reading as "a test-side proxy for odd A3 transport" is withdrawn.
- **Scope defect.** Only `cp3entry:1` needs D2, and it asserts it itself at TQ:2802. The six other consumers of `nonzero_z4_torus_witness_fixture()` (`focused30:6/12/20/24`, `selector:446/447`; calls at TQ:8318, 5144, 5800, 6157, 8205, 8368) exist at CP2 `5ce3132ec`, where the fixture took the first source/A3 candidate and all six were GREEN in 491/491. `88aa8eae0` put D2's selection into the shared fixture, so every consumer inherits D2's STOP (LESSONS §2 **A fixture change reaches every fixture built from it**).
- **H-T2 has no support.** Every recorded enumeration (R3, `Architecture_M6_CP3_TB1_Entry_R3_Independent_Review_Record.md`; TB20; TB21) reads `sourceFaceGaugePairs=5; oddFaceGaugePairs=0`, and D2 itself never established that an odd pair exists. No producer gauge contract is shown to have been lost.
- **Unmeasured predicates.** The reciprocal-tracer and holonomy checks run only after the odd filter, so `reciprocalTracerPairs=0` says nothing about the five even candidates (LESSONS §2 **A failure hidden behind an earlier one is unmeasured**).
- **Consequence.** The correction is test-only: return D2 to `cp3entry:1` and measure every predicate on every candidate (RA-115.5). D2 is not loosened. Whether an organic odd pair is attainable on this torus under RA-111.3 becomes DEFN-T1, after TB22 publishes the unmasked receipt.

#### RA-115.4 Unchanged

- M1 (10 identities, RA-105.3), `cp3entry:2` and `focused30:12` keep their TB20 failures and go to the M1 DEFN.
- Frozen: 66/17/49, debt 1, CP2 491/491, R3 403/497 rejected, selector 497. `RP-01` open, `RP-02` UNREACHED, Gate C suspended.

#### RA-115.5 Next unit — `M6-CP3-CB21-RP01-TORUS-WITNESS-SCOPE` (Code + Build, test-only)

**Objective:** confine D2's odd-gauge selection to the identity that requires it, and make each witness predicate measurable on every candidate. TQ only.

1. **Predicates.** In `make_nonzero_z4_torus_witness_fixture` (selection loop TQ:1687–1744), evaluate for every candidate, independently and without an early `continue` on the gauge delta: gauge presence (both face indices in range), `delta`, the reciprocal tracer pair (unchanged forward/reverse `PeriodicCut` test), and the holonomy match (unchanged stored-relation, semantic-action and cut-route test).
2. **Selection.** The first candidate in enumeration order that passes every non-gauge predicate with `delta ∈ {1,3}`; if there is none, the first that passes every non-gauge predicate. Throw only when no candidate passes every non-gauge predicate.
3. **Receipt.** A string with `sourceA3Candidates`, `sourceFaceGaugePairs`, `oddFaceGaugePairs`, `reciprocalTracerPairs`, `holonomyMatchedPairs`, `publishedPeriodicHolonomies`, `nonzeroHardCarriers`, each counted over all candidates; then one `c<i>=<carrier>:delta=<d>;recip=<0|1>;holo=<0|1>` entry per candidate; then `selected=c<i>` or `selected=none`. Append it to the throw message, whose text drops "and odd selected-face gauge delta".
4. **Fixture member.** Add `std::string selectionReceipt` as the last member of `ProducedTorusWitnessFixture` (TQ:903) and fill it in the return at TQ:1771.
5. **D2 identity.** In `cp3entry:1` keep the TQ:2802 assertion and its message unchanged, and append `<< " receipt=" << fixture.selectionReceipt`. Nothing else in the test changes.
6. **Compile.** Eight-target GMP/GMPXX compile as for CB20A; `runtimeExecution=false`.

**Out of scope:** `src`/`include`; any other test or helper, including `enumerate_torus_source_witnesses` and `produced_semantic_relation_for_witness`; D2's requirement; selectors, harnesses, workflows; any runtime; DEFN-T1; M1.

**Record:** `Architecture_M6_CP3_CB21_Torus_Witness_Scope_Code_Build_Record_20261021.md` (≤ 30 lines): source SHA, diff stat, compile run, package id, ZIP digest, hash count, expiry, root-manifest and source-archive SHA-256.

**STOP and return to Review** on a compile failure, or any need to touch `src`/`include` or another test. No repair inside the turn.

**TB22 predictions (to be set in CB21-REV):** P1 — the fixture selects a candidate, and `focused30:6/20/24`, `selector:446/447` reach their own assertions (CP2 expects PASS). P2 — `cp3entry:1` fails at its D2 assertion with `oddFaceGaugePairs=0` in the receipt. P3 — `focused30:12` keeps its A5 failure. **Falsifier:** the fixture throws with `reciprocalTracerPairs=0` or `holonomyMatchedPairs=0`; the blocker is then periodic publication, not the filter, and returns to Review.

#### RA-115.6 Sequence and accounting

- **Sequence:** TB21 → TB21-REV (RA-115) → **CB21** → CB21-REV → TB22 (the seven torus consumers, `cp3entry:6`, three controls) → TB22-REV → DEFN-T1 (D2 attainability on the torus under RA-111.3, from the TB22 receipt) → DEFN-M1 (M1 binding owner, RA-105.3; also `cp3entry:2`, `focused30:12`) → corrective CB/TB → fixture debt → census → RP-01 Review.
- **Accounting:** candidate evidence TB21 449/497 (was TB18 448/497); everything else as RA-115.4.

> *Closed by RA-116 (2026-10-21): CB21 accepted statically; TB22 authorized. TB22 reviewed by RA-117.*

## `Architecture_M6_CP3_TB22_Torus_Witness_Harvest_Review_Decision.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_TB22_Torus_Witness_Harvest_Review_Decision.md`; moved verbatim.

### RA-117 — TB22 reviewed: fixture selection fixed; five CP2 torus rows split into a fixture atlas defect and an unowned A5 isolation family; CB22 next (2026-10-21)

**Turn:** `M6-CP3-TB22-RP01-TORUS-WITNESS-HARVEST-REV`. **Input:** TB22 [run 39549820087](https://github.com/akashskypatel/Directional/actions/runs/39549820087), report `Architecture_M6_CP3_TB22_Torus_Witness_Harvest_Report_20261021.md`, plan and predictions frozen by RA-116. **Lines:** TQ = `tests/SurfaceCellTransitionQuotientTests.cpp`, RP = `src/pipeline/RemeshPipeline.cpp`, S = `src/geometry/SurfaceCellTracing.cpp`, all at CB21 source `8453e19e6` (HEAD `src`, `include`, `tests` identical).

#### RA-117.1 Harvest verified

- Result artifact `12323004201`, ZIP SHA-256 `71569a41315a727da3b1285cbdc94ffa360c366074fdecc3729ef0ed0b058c87` (downloaded and recomputed), expires 2026-11-04T05:31:17Z. 15/15 result hashes verify; 11/11 executed, 0 missing; 4 PASS / 7 RED; postflight package/source/view/selectors immutable; no compile, relink or benchmark.
- The report's rows and first failures match the raw logs. The agent closed TB22 itself with a report.

#### RA-117.2 Predictions adjudicated

- **Falsifier not observed.** The receipt reads `reciprocalTracerPairs=5; holonomyMatchedPairs=5; selected=c0`: periodic publication is intact, and the D2 filter was the only fixture-selection blocker (RA-115.3 confirmed). CB21 is accepted at runtime for its scope.
- **P2 observed.** `cp3entry:1` fails at its own D2 assertion (TQ:2827). All five candidates lie on the minor hard cycle (`0-3`, `0-61`, `3-25`, `25-37`, `37-49`) with `delta=0`.
- **P3 observed.** `focused30:12` fails at TQ:5147 (`relabelledA5` null), as before. **P4 observed.** `cp3entry:6` and the three controls PASS.
- **P1 falsified.** The five CP2 rows now get past the fixture but fail further on. No row is recovered.

#### RA-117.3 The five CP2 rows: two causes

**F — fixture atlas binding (test scope), `focused30:6`, `selector:447`.**
- Both rebuild the torus product from `phase_front_draft(fixture)`, whose `sourceAtlas` is `PhaseFrontFixture::fieldTransportAtlas`. `make_nonzero_z4_torus_witness_fixture` never sets that field (TQ:1607–1796).
- `SurfacePhaseFrontProduct::make` rejects a null atlas at S:8462 (`InvalidSourceAuthority`, site `atlas-binding`). This matches `focused30:6` (`InvalidPhaseFrontProduct`, TQ:8387) and `selector:447` (code 0 instead of `NonReciprocalPeriodicRelation` = 19, TQ:1913). The site is not printed; the null atlas is certain from the source.
- **Origin:** `7de636c88` (2026-10-10) made the atlas mandatory and added `fixture.fieldTransportAtlas = snapshots.fieldTransportAtlas;` to the other pipeline fixtures (TQ:649, 757, 861). This fixture was masked by the D2 filter from `88aa8eae0` (2026-10-08) and was missed. The correction is that one line (LESSONS §2 **A negative must reach the intended guard on a valid baseline**).

**A5-ISO — torus A5 isolation rejection (production, A4→A5), `focused30:20`, `focused30:24`, `selector:446`.**
- `focused30:20` (TQ:5831) and `selector:446` (TQ:8324): `build_authoritative_phase_front_mesh` on the produced torus product fails `InvalidIsolationSeamEquivalenceAuthority:a5-side`, which is A5 `MismatchedIsolationEvidence` without an occurrence (RP:3254–3256). `focused30:24` (TQ:6007): A5 produces no complex on the torus; the code is not printed.
- **This is an existing, unowned family.** TB21 shows the same A5 rejection on five more CP2 rows built from the other torus fixtures: `selector:444`, `selector:448` (`a5-side`) and `focused30:26`, `27`, `28` (`A5:OccurrenceMismatchedIsolationEvidence`). The R3 overlay already classed them as A5 isolation rejections, "carried, no new stable event". No DEFN, plan or tracker row owns them. `focused30:25` (torus pipeline `hasArrangement=false`) is a probable member, unattributed.
- **Weight.** At least 8 CP2-GREEN rows, 10 once F is corrected (both F rows materialize the torus next), and it includes `focused30:28`, the torus G4-B002 extraction (the M6 exit dependency, ROADMAP).
- **Not caused by CB20.** The family fails in A5 at R3, before the pin's extension and before CB20.
- **Two A5 branches emit `a5-side`:**
  - the side-span seam crossings at RP:4318 and RP:4359 through `transition_between` (RP:4136–4165, pre-CP2 code);
  - the relation-level certified-collinear-seam reject at RP:5205–5221, added after CP2 by `8be01326d` (R2, 2026-10-08: "Reject instead of silently falling back when the A4 certificate was present but unusable"). At CP2 this case fell back, and these rows passed.

  The logs do not say which branch fires, nor which `certified_seam_direction` clause (RP:3880–3911) fails.
- **Hypotheses:**
  - **H-ISO-1:** the RP:5205 reject is too strict for a legitimate torus pairing;
  - **H-ISO-2:** A4 publishes a seam certificate whose faces or sheets disagree with A2b sheet authority;
  - **H-ISO-3:** a side-span crossing mismatch at RP:4318/4359.

  Each needs the site, so the next unit is measurement, not repair (LESSONS §5).

**D2.** DEFN-T1 (attainability of an odd gauge on this torus under RA-111.3) remains planned. It owns one CP3-entry row, so it moves behind the two CP2 families, A5-ISO and M1.

#### RA-117.4 Unchanged

`focused30:12`, `cp3entry:2` and M1 (10 identities) stay with DEFN-M1. Frozen: 66/17/49, debt 1, CP2 491/491, R3 403/497 rejected, selector 497, candidate evidence TB21 449/497. `RP-01` open, `RP-02` UNREACHED, Gate C suspended.

#### RA-117.5 Next unit — `M6-CP3-CB22-RP01-TORUS-A5-ISOLATION-SITE` (Code + Build)

**Objective:** correct the F fixture defect and make every A5 isolation-evidence rejection name its site, without changing any accept/reject decision.

1. **Part A (TQ, one line).** In `make_nonzero_z4_torus_witness_fixture`, after `fixture.network = snapshots.traceNetwork;` (TQ:1672), add `fixture.fieldTransportAtlas = snapshots.fieldTransportAtlas;`, as at TQ:649 and TQ:861. No other test change.
2. **Part B (RP and its header, rejection path only).**
   - Add `std::string isolationSite` as the **last** member of `SurfaceOccurrenceComplexError` (`include/directional/pipeline/RemeshPipeline.h:963–970`).
   - Populate it only where `MissingIsolationEvidence` or `MismatchedIsolationEvidence` is returned, with a label and fields:
     - `side-step` (RP:4318), `side-collinear` (RP:4359), `wedge-edge` (RP:4470, edge-supported corner), `wedge-fan` (RP:4551, vertex-fan crossing): `;region=<r>;seam=<a>,<b>;from=<row>/<sheet>;to=<row>/<sheet>;cert=<firstRow>/<firstSheet>-><secondRow>/<secondSheet>` or `cert=none`, plus `;cell=<id>`;
     - `relation-collinear-seam` (RP:5205–5221): `;region=<r>;seam=<a>,<b>;relation=<first>,<second>;first=<row>/<sheet>;second=<row>/<sheet>;certs=<n>`, and for each certificate with that region and seam, its faces/sheets and the first failing `certified_seam_direction` clause, one of `collinear`, `region`, `first-face`, `second-face`, `same-sheet`, `first-side`, `second-side` or `same-side`; `ambiguous` if more than one certificate passes.
   - At RP:8963, when `isolationSite` is non-empty, set `result.failure` to the legacy name followed by `;site=` and the site. Every other failure string is unchanged.
3. **Compile.** Eight-target GMP/GMPXX compile, `runtimeExecution=false`. Record `Architecture_M6_CP3_CB22_Torus_A5_Isolation_Site_Code_Build_Record_20261021.md` (≤ 30 lines): source SHA, diff stat per file, compile run, package id, ZIP digest, hash count, expiry, root-manifest and source-archive SHA-256.

**Invariants (checked in CB22-REV):** no predicate, ordering, code or return-value change in A5; `transition_between` and `certified_seam_direction` decide exactly as before; site computation only on paths that already return the two isolation codes.

**Out of scope:** any other test or helper; S and A4; any repair of A5-ISO; selectors, harnesses, workflows; runtime; DEFN-M1, DEFN-T1.

**STOP and return to Review** on a compile failure, or any need to change an A5 decision, another test, or A4.

**TB23 frame (fixed in CB22-REV):**
- **Rows:** the A5-ISO family (`focused30:20`, `24`, `25`, `26`, `27`, `28`; `selector:444`, `446`, `448`), the F rows (`focused30:6`, `selector:447`), and `cp3entry:6`, `selector:217`, TB18 A#14, `selector:443`, plus one certified-seam positive control chosen by CB22-REV.
- **Predictions:**
  - every A5-ISO row prints a `site=`;
  - the F rows reach materialization, the same site;
  - controls unchanged;
  - no status change elsewhere.

#### RA-117.6 Sequence

- **Sequence:** TB22 → TB22-REV (RA-117) → **CB22** → CB22-REV → TB23 (torus A5 site harvest) → TB23-REV → DEFN-ISO (the A4 seam certificate ↔ A5 binding contract, including the `8be01326d` reject) → corrective CB/TB → DEFN-M1 → corrective CB/TB → DEFN-T1 → fixture debt → census → RP-01 Review.
- **Accounting:** unchanged (RA-117.4).

Closed by RA-118 — CB22 compile stop reviewed; CB22A authorized (`Architecture_M6_CP3_CB22_Torus_A5_Isolation_Site_Compile_Stop_Review_Decision.md`).

## `Architecture_M6_CP3_TB23_Torus_A5_Site_Harvest_Review_Decision.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_TB23_Torus_A5_Site_Harvest_Review_Decision.md`; moved verbatim.

### RA-121 — TB23 reviewed: one site owns all ten torus A5 rows; the occurrence chart face disagrees with its own seam span; seam-face measurement before DEFN-ISO (2026-10-21)

**Turn:** `M6-CP3-TB23-RP01-TORUS-A5-SITE-HARVEST-REV`. **Input:** TB23 report `Architecture_M6_CP3_TB23_Torus_A5_Site_Harvest_Report_20261021.md`; plan per RA-120. **Lines:** RP = `src/pipeline/RemeshPipeline.cpp` at `c6e90916e` (HEAD sources identical); CP2 = `5ce3132ec`.

#### RA-121.1 Harvest verified

- Run [39609365590](https://github.com/akashskypatel/Directional/actions/runs/39609365590) success (single runtime dispatch); result `12348649684`, ZIP SHA-256 `5ce73745…6d1` recomputed locally and equal to the provider digest; expires 2026-11-04T13:37:29Z.
- 20/20 result hashes; 16 raw-log hashes match the ledger; 16/16 selected, zero skips, 6 PASS / 10 RED; `site_bad=0`, `ctrl_bad=0`; package, source, view and frozen selectors unchanged; no compile, relink or benchmarks.
- The pre-execution harness fix `0948a81b0` is accepted: direct-path messages carry no `a5-side`/`a5-wedge` suffix, so any label is admissible there; the pipeline rows keep the suffix check.

#### RA-121.2 Predictions adjudicated

- **P1 held.** Every isolation failure carries a site; all pipeline rows say `a5-side` with `relation-collinear-seam`; no `valid` clause.
- **P2 held, more strongly than predicted.** One byte-identical site across all ten RED rows, so the W and T fixtures fail at the same relation.
- **P3 held.** `focused30:24` has one A5 failure; it names torus faces 120 and 97, which the square hard-rail and split-isolation fixtures do not have.
- **P4 held; F is closed at candidate level.** `selector:447` PASSES (CP2 row recovered, candidate only); `focused30:6` now reaches A5 and joins A5-ISO (10 rows).
- **P5 held.** All five controls PASS with no site.

#### RA-121.3 The site, decoded

`relation-collinear-seam;region=0;seam=60,61;relation=0:1,1:0;first=120/0;second=97/2;certs=1;cert0=120/0->97/2:first-face`.
- Labels are `<source face row>/<sheet>`, and a row is a unique source face, so this is exact face identity. In `torus.obj`, faces 120 `[61,60,1]` and 97 `[49,60,61]` are the only two faces on edge 60–61.
- An `OrdinaryFront` relation between cell 0 corner 1 and cell 1 corner 0 runs along the certified seam. Cell 0's span is on face 120 (sheet 0) and cell 1's on face 97 (sheet 2). The single A4 certificate `120/0 -> 97/2` equals both spans exactly.
- The failing clause `first-face` (RP:3891) means occurrence (0,1)'s `placement.selectedFace` is not face 120. `selectedFace` is the A2 corner trace face (RP:4448, RP:4457), the face whose chart carries that corner's lattice. The second-face clause was never evaluated.
- **Routing (RA-120 pre-registration):** `first-face` → H-ISO-2, refined. The A4 certificate agrees with A5's span authority. The disagreement is inside one occurrence: its chart face versus its own seam span. H-ISO-3 is excluded.

#### RA-121.4 Design finding: the face requirement is post-CP2, and the evidence cannot yet choose its owner

- **At CP2,** A5 attached no seam certificate to relations. A6 took cross-sheet seam sides from the span sheets and span transitions alone (CP2 RP:5295–5311), and never consulted `selectedFace`. The equality `span.interiorBinding.face == placement.selectedFace` arrived after CP2: first through the certificate lookup, then in R2 `88aa8eae0`, and it became fatal in `8be01326d`.
- **Not admissible:** restoring a silent fallback. That would compare a certified cross-sheet relation as same-sheet, which `8be01326d` correctly forbids.
- **Two branches with different owners:**
  - **B-across:** `selectedFace` is 97 (sheet 2) and the corner lies on the edge interior. Cell 0's corner lattice is then charted on the other sheet. The owner is A2 corner placement on certified seams, or an A5 lattice transport through the certificate.
  - **B-fan:** `selectedFace` is a sheet-0 fan face of vertex 60 (`96, 99, 122, 123`) or 61 (`118, 119, 121, 142`). The clause then conflates a chart gauge with a seam side. DEFN-ISO would take the side from the span binding and relate the chart face by an in-sheet chart transition.
- Whether relaxing the face clause alone would yield a unique direction is also unmeasured (`first-side`, `second-side`, `same-side` were never reached). DEFN-ISO written now would guess, so the next unit measures (LESSONS §5).

#### RA-121.5 Next unit — `M6-CP3-CB23-RP01-TORUS-A5-SEAM-FACE-SITE` (Code + Build, compile only)

RP only, inside the `relation-collinear-seam` block: after the certificate loop, before `error.isolationSite = std::move(site);`. Append, in this order:
1. `;sel=<a>,<b>`: each canonical occurrence's `placement.selectedFace` as `<row>/<sheet>`, using `sourceTopologyRegions().row_for_topology` and `sheet_for_row`; `none` without a row.
2. `;support=<a>,<b>`: `vertex`, `edge` or `face` from `authority::support_kind(occurrence.support)`.
3. `;wedge=<a>,<b>`: each occurrence's `cornerWedgeBindings` as `isolation_binding_label` values joined by `+`.
4. For each matching certificate, in `certN` order, `;spanOnlyN=<v>`: the existing classifier without the two face clauses. That gives `same-sheet`, `first-side`, `second-side` or `same-side`, else `forward` (First/Second) or `reverse` (Second/First).

Invariants: no decision, return or error-code change; existing site text byte-identical, with the new fields only appended after the last `certN`; header, TQ and every other file byte-identical to `c6e90916e`; at most 100 columns. Eight-target GMP/GMPXX compile with `runtimeExecution=false`. Record `Architecture_M6_CP3_CB23_Torus_A5_Seam_Face_Site_Code_Build_Record_20261021.md`, at most 30 lines. STOP on any compile error or any need to edit outside the block.

#### RA-121.6 TB24 frame (CB23-REV adds the package and issues the plan)

- **Rows (9):** A5-ISO `focused30:20` (W/P), `selector:444` (T/P), `focused30:28` (T/D, G4-B002); guard `selector:447`; controls `cp3entry:6`, `selector:217`, TB18 A#14, `selector:443`, `focused30:7`.
- **Predictions:** the TB23 site prefix is byte-identical in all three A5 rows, and the new fields are identical across them; the guard and the controls PASS with no site.
- **Routing for TB24-REV:**
  - `sel` first `97/2` with `support` `edge` → B-across;
  - a sheet-0 fan face with `vertex` → B-fan;
  - a `spanOnly` value other than `forward` or `reverse` → relaxing the face clause is insufficient, and DEFN-ISO must also own that clause.

#### RA-121.7 Unchanged and sequence

66/17/49, debt 1, CP2 491/491, R3 403/497 rejected, selector 497 frozen, TB21 candidate 449/497. TB23 is candidate evidence: no count changes. `RP-01` open, `RP-02` UNREACHED, Gate C suspended.

Sequence: **CB23** → CB23-REV → TB24 → TB24-REV → DEFN-ISO → corrective CB/TB → DEFN-M1 → corrective CB/TB → DEFN-T1 → fixture debt → census → RP-01 Review.

## `Architecture_M6_CP3_CB19A_Factory_Rejection_Site_Code_Build_Record_20261020.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_CB19A_Factory_Rejection_Site_Code_Build_Record_20261020.md`; moved verbatim.

### M6 CP3 CB19A — factory rejection-site corrective Code + Build (2026-10-20)

- Authorized scope: RA-106.3, RA-106.4 and RA-106.6; only `src/geometry/SurfaceCellTracing.cpp` and `tests/SurfaceCellTransitionQuotientTests.cpp` changed.
- CB19A source commit: `d2c7483cde8e65d6c35c5df06fa880465a4da46c`; earlier CB19 `1f73d0abd` compile failure retained in its separate record.
- Patch: SHA-256 `c7df5bbd081de16256b3dd23f38399666a822590f18661d481ebcb669a9edb8a`, base `5eb62406b48467e92cdb6b5689ce907d2633aaea`, apply run `39446123275`.
- Immutable compile: [run 39446712217](https://github.com/akashskypatel/Directional/actions/runs/39446712217), artifact `12275794192`, ZIP SHA-256 `e4a39cdb2db5ef9953748cffd3e031e4294ddaf348f4a64fee3b97e08bdd723a`.
- Eight requested targets compiled, GMP and GMPXX linked; preflight/build exit codes `0/0`; `28/28` packaged hashes; five source statuses empty; exact source SHA matched.
- `DIRECTIONAL_ENABLE_GMP=ON`, `exactArithmeticBackend=GMP`, `runtimeExecution=false`; no tests, executable runs or benchmarks were performed.
- Corrective changes: 26 certificate/endpoint/junction labels use scope-local suffix lambdas; two gauge-pin labels use `std::string` first operand; TQ edge oracle checks both corners of face 0.
- Static label census: 47 uniquely named `InvalidSourceAuthority` returns in `make` (line numbers from CB19A packaged source):
- `atlas-binding` S:8469 | `region-empty` S:8489 | `face-gauge-missing` S:8497 | `face-gauge-shape` S:8506 | `gauge-pin-face-row` S:8522 | `gauge-pin-edge-key` S:8532
- `gauge-pin-edge-incidence;edge=` S:8542 | `gauge-pin-consistency;edge=` S:8560 | `hard-rail-source-edge` S:8598 | `hard-rail-incidence` S:8616 | `hard-rail-contact-missing` S:8628 | `closed-rail-contact-conflict` S:8636
- `closed-rail-distinct-vertices` S:8643 | `closed-rail-edge-coverage` S:8666 | `open-rail-chain` S:8675 | `closed-rail-cover` S:8682 | `rail-contact-endpoints` S:8690 | `rail-contact-source-vertex` S:8712
- `rail-transition-a3` S:8730 | `terminal-star-spoke` S:8765 | `certificate-pair-indices` S:8794 | `certificate-pair-binding` S:8808 | `certificate-attachments` S:8829 | `certificate-route-length` S:8835
- `certificate-open-interval` S:8852 | `certificate-closed-edge` S:8867 | `certificate-closed-interval` S:8892 | `certificate-rail-kind` S:8897 | `endpoint-carrier` S:8930 | `endpoint-kind-overlap` S:8936
- `endpoint-interior-point` S:8966 | `endpoint-source-vertex` S:8991 | `endpoint-a3-path` S:9008 | `endpoint-contact-path` S:9025 | `endpoint-contact-target` S:9032 | `endpoint-sector-overlap` S:9039
- `endpoint-no-contact` S:9048 | `junction-edge-continuation` S:9067 | `junction-hard-spokes` S:9088 | `junction-star-size` S:9095 | `junction-manifold-star` S:9117 | `junction-sector-step` S:9142
- `junction-sector-cover` S:9153 | `junction-next-carrier` S:9161 | `junction-transport` S:9172 | `certificate-final-carrier` S:9179 | `hard-rail-uncertified-pair` S:9192
- No selection, admission, predicate, fixture, harness, or acceptance contract changed; frozen 66/17/49, debt 1, CP2 491/491, R3 403/497 rejected, TB18 448/497 candidate, selector 497; `RP-01` remains open and `RP-02` UNREACHED.
- Next separately authorized turn: `M6-CP3-TB19-RP01-FACTORY-REJECTION-SITE` (artifact-only 22 identities, RA-105.6 amended by RA-106.5); mandatory independent TB19 review follows.

## `Architecture_M6_CP3_CB19_Factory_Rejection_Site_Compile_Failure_20261020.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_CB19_Factory_Rejection_Site_Compile_Failure_20261020.md`; moved verbatim.

### CB19 — Factory rejection-site diagnostic: compile failure (2026-10-20)

- **Canonical turn:** `M6-CP3-CB19-RP01-FACTORY-REJECTION-SITE`; source/test changes landed but Code + Build did not complete.
- **Authority:** RA-105.5; no runtime, Test + Benchmark, or selector changes authorized.
- **Original snapshot:** `5c287615785c9562fbb8bcf23eaf9c3207205157`, workflow `39385504966`, artifact `12247187712`, 5,698/5,698 packaged source hashes verified in prior session.
- **Preserved patch:** SHA-256 `0670408146d932c427724bea9cb83feec0733bea3b9cefa5627df4188b110b60`; diff-body SHA-256 `3aeda74419a263236b6cc806bc44b27412b229ff82db5a700e228298ac02cf19`; 32,642 bytes.
- **Transport:** direct Drive upload succeeded after File-Library `source_file_unavailable`; staged File ID `1PDZSdJR3vIpMPkoBI85omL-4jHZoS9TZ`. Workflow [39428169220](https://github.com/akashskypatel/Directional/actions/runs/39428169220) applied it successfully.
- **Semantic commit:** `1f73d0abd1a4f83a85570decd79dfa40c6e2508a`; exactly three intended paths: tracing header +2, tracing implementation +49/-0, transition quotient tests +59/-1. Factory `make` additions only; 47 planned site labels.
- **Compile request:** `6f49dc9610f316dccf5544160343c13099cdc6cf`; eight GMP/GMPXX targets requested, no runtime.
- **Failed compile:** [39428435345](https://github.com/akashskypatel/Directional/actions/runs/39428435345); immutable activity-log artifact `12265949093`; exact source confirmed by workflow mailbox, result `failure`. CMake configuration succeeded, but `directional_core` preflight exited 1. Full target compile was skipped; package artifact was not produced.
- **Root cause:** new `error.sourceAuthoritySite` assignments in `src/geometry/SurfaceCellTracing.cpp` use literal concatenation such as `"certificate-route-length" + ";certificate=" + std::to_string(...)`, which attempts `const char[] + const char[]`. Compiler diagnostics at lines 8823, 8840, 8855 and additional certificate/endpoint/junction labels show the same invalid operands.
- **Corrective measure for authorized Review:** make the leftmost operand a `std::string` before concatenation, in the newly inserted diagnostic assignments only; preserve every preexisting factory line, validation order, predicate, and test oracle. Review whether all diagnostic labels have the same defect and authorize a separate corrected Code + Build turn.
- **Stop decision:** RA-105.5 explicitly requires STOP and return to Review on build failure. No repair, retry, or TB19 execution in this turn. No compile/package success and no regression-count or acceptance change is claimed.
- **Outstanding closeout:** TODO/handoff/changelog reconciliation and any staged-Drive cleanup must be completed under review/next authorized continuation; no declaration of CB19 completion or TB19 eligibility.

## `Architecture_M6_CP3_CB20_Gauge_Pin_Domain_Code_Build_Stop_Record_20261020.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_CB20_Gauge_Pin_Domain_Code_Build_Stop_Record_20261020.md`; moved verbatim.

### M6 CP3 CB20 — gauge-pin domain Code + Build STOP (2026-10-20)

> **Reviewed by RA-112 (2026-10-20):** the stop is verified and the S patch is accepted statically. The accessor correction is authorized as CB20A (`Architecture_M6_CP3_CB20_Gauge_Pin_Domain_Compile_Stop_Review_Decision.md`).

- Canonical turn: `M6-CP3-CB20-RP01-GAUGE-PIN-DOMAIN`; authority RA-111.4/RA-111.6. **Compile RED; mandatory STOP and independent Review.**
- Source code/test semantic commit: `7dc9b89ecd13753173057577d1da320db9515ebb`, applied by Drive workflow `39505814372`; patch SHA-256 `40cd730e9859d677d6e5510b6c7bb97b8a8924920e606eeec93e9849743e3c95` against `9c6bb760576407be6d488ccaf5b5f7f17037298a`.
- Scoped S diff: +37/-5, within RA-45 pin block plus immediate span guard. TQ diff: +82/-2, exact edge site and two RA-111 tests. No header, producer, pipeline or selector edits.
- Static audit on snapshot `5769e4397b374a0680feeabdcd2375f4866cad77`: 5,711/5,711 source hashes verified; 48/48 distinct factory error labels; new site `gauge-pin-span;region=` at S:8595; no >100-column lines in the edited ranges. This is static evidence, not runtime acceptance.
- Compile dispatcher `5624421ebf6e21ee8d4b23adde298bc528c0dc05`, exact source `7dc9b89ecd13753173057577d1da320db9515ebb`, eight approved GMP/GMPXX targets; workflow [39512680019](https://github.com/akashskypatel/Directional/actions/runs/39512680019), compile job `118937410213` **failure**. Log artifact `12306507832`, ZIP SHA-256 `d28cd21a2fde92a3d1d615c7ff054380a58d80c0279dd29104b6958da7c8b915`.
- Preflight `directional_core` compiled (`preflight_exit=0`); overall `build_exit=1`. First distinct compiler diagnostic: `no match for 'operator*'` on `DomainResult<SourceFaceId>` at `tests/SurfaceCellTransitionQuotientTests.cpp:1941`; same type error at lines **1947, 1972, 1978, 1979**. Five instances, one root cause. Compiler expects the typed result's `.value()` accessor rather than unary `*`; proposed correction is for Review to authorize, not applied in this turn.
- No successful compile package, no 28/28 package claim, no test/runtime/benchmark executed (`runtimeExecution=false`), no changes to frozen selector 497 or 66/17/49, debt 1, CP2 491/491, R3 403/497, TB18 candidate 448/497. `RP-01` open, `RP-02` UNREACHED.
- **STOP:** RA-111.6 forbids a second repair in CB20. Required action: independent CB20 Review of compiler failure and source/test correction authority before retrying Code + Build. Do not proceed to TB20 or claim CB20 complete.
- Source patch transport reported owner cleanup required, but the exact Drive patch File ID `1411tvMZY1nCoGELU1Pf4rhXaKeEvHSbR` returned 404 to the authorized Google Drive metadata call. No further deletion attempted.
- Workflow policy pre-read sequencing miss: initial remote documents preceded an explicit snapshot-mode declaration. It was corrected to a verified exact-source snapshot before code inspection; no direct piecemeal source reads followed.

## `Architecture_M6_CP3_DEFN_P1_Gauge_Pin_Domain_Definition_Record_20261020.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_DEFN_P1_Gauge_Pin_Domain_Definition_Record_20261020.md`; moved verbatim.

### M6 CP3 DEFN-P1 — gauge-pin domain, source-only definition (2026-10-20)

> **Reviewed by RA-111 (2026-10-20):** items 1, 3 and 5 are confirmed and item 2 stays open. Item 4's predicate and its added input are superseded by RA-111.4 (`Architecture_M6_CP3_DEFN_P1_Gauge_Pin_Domain_Review_Decision.md`).

**Authority:** RA-110.4/110.5 (`Architecture_M6_CP3_TB19_REV_Gauge_Pin_Domain_Review_Decision.md`). **Source:** verified immutable snapshot of `ee3ef2652fc3cacc6c1ba5619c0f9159681dfcc0`, workflow `39493959673`, artifact `12297225688`, 5,709/5,709 file digests. `S` = `src/geometry/SurfaceCellTracing.cpp`, `R` = `src/pipeline/RemeshPipeline.cpp`, `TQ` = `tests/SurfaceCellTransitionQuotientTests.cpp`. Static inspection only; no code, test, build or runtime execution. **Candidate definition for mandatory independent Review, not CB20 authorization.**

#### Producer census and exact domain

The face-gauge domain is the graph of **transports actually established by the selected producer**, not the graph of all two-face source edges and not simply the connected components of `SourceTopologyRegions`. The dispatcher tries uniform, periodic annulus, then curved bounded disk within each source topology region (S:18336–18352). `build_source_topology_regions` omits hard edges from dual traversal (S:9670–9727), but omitted edges can still have both incident faces in a single connected region through another path.

| Producer | Gauge origin and admitted adjacency | Two-face exclusions / qualification |
|---|---|---|
| `build_uniform_phase_front_for_faces` (S:13178–13550) | `build_planar_phase_frame`: deterministic planar reference axes, per-face best quarter turn (S:11850–11967), and reciprocal A3 check over `edge_faces(faces, activeFaces)` (S:11996–12035). Global +Z4 shift remains irrelevant. | Excludes two-face edges **outside the selected active region**; the planar-frame checker does **not** exclude hard edges *inside* that region. With a conformity baseline and any incident hard rail the producer declines (S:13208–13229). Without the baseline, internal hard edges are checked: a material qualification to RA-110.3. |
| `build_periodic_annulus_phase_front_for_faces` (S:13997–~15283) | Per strip, choose the canonical first source face (S:14290–14311), try four seed branches, BFS the strip dual graph using field transport (S:14275–14387), choose the unique minimum-score candidate (S:14546–14576), then publish each face branch (S:14567–14598). Periodic per-occurrence `branchAuthority` is distinct (S:13104–13107). | Excludes different topology regions and **between-strip adjacencies not in the chosen strip dual graph** from the propagation equation; periodic seam relations use separately published periodic authority. Does **not** exclude an internal hard carrier from strip BFS (S:14275–14286). Defers if a baseline exists and any incident hard feature exists (S:14019–14039). |
| `build_curved_bounded_disk_phase_front_for_faces` (S:15284–18005) | Exact selected root face from minimum face-topology key (S:16153–16188), branch zero (S:16254–16255), transport along dual graph (S:16212–16320), reciprocal check (S:16339–16376). | Excludes different regions and **`acceptedCutEdges`** from face incidence, BFS, and reciprocal check (S:16000, 16217, 16346). The cut set is used only when both accepted topology and conformity baseline exist and the region has an incident hard feature (S:15320–15333); otherwise cuts are not excluded. |

The fact that a hard edge is in `hardFeatureEdges` is **not**, by itself, evidence that the producing algorithm omitted it. In particular, uniform/periodic explicitly check internal edges when the conformity baseline is absent, and curved excludes exactly accepted cut carriers, not an all-hard-edge set. Any proposed predicate that simply removes every hard edge is unsound for RA-110.4's *exactness* requirement.

#### Cut-set membership and torus topology

`acceptedCutEdges ⊆ hardFeatureEdges` **is not established by the producer**. The membership gate `regionHasHardFeature` (S:15328–15333) only requires *some* incident hard edge. Each accepted boundary arc is looked up in the accepted global topology, matched to baseline incidence/schedule and an oriented `SourceEdgeSupport` on the active faces (S:15426–15531); S:15532 then inserts `carrier->edge` without checking `options.hardFeatureEdges.count(carrier->edge)`. It therefore permits a topology-plan boundary carried by a nonhard source edge unless a stronger upstream invariant is proved. An actual accepted runtime counterexample was **not** measured; do not claim one, or infer inclusion from the six observed torus failures. Review must separately verify upstream plan construction before claiming universal inclusion.

**Torus `{0,3}` is same-region.** TQ:708–758 loads committed `benchmarks/fixtures/milestone-g/torus.obj`; TQ:909–929 marks an 18-edge minor/major hard-cycle union. Static dual-graph enumeration of that committed 72-vertex, 144-triangle OBJ, omitting those 18 edges exactly as S:9670–9690 does, yields **one connected component of 144 faces**. Edge `{0,3}` has incident face rows **1 and 22**, both in that component. This disproves using `region_for_row(a) == region_for_row(b)` as a sufficient pin-domain predicate. This is a static graph computation, not a project test or runtime run.

#### Exact pin predicate / missing authority

Current `SurfacePhaseFrontProduct::make` S:8509–8567 builds complete two-face incidence and requires reciprocal A3 with `compose(T_ab, gauge[a]) == gauge[b]` on *all* interior edges. Required mathematical predicate is:

`pin(e,a,b) = two_face(e,a,b) && gauge_relation_published_by_selected_producer(e,a,b)`.

`gauge_relation_published_by_selected_producer` means an actual within-gauge-domain oriented adjacency for the chosen producer, with reverse relation equal to inverse. For uniform it is the planar-frame checked active-face dual adjacency; for periodic the selected strip-dual edges; for curved the region's dual edges **minus the accepted cut carriers**. Boundaries and unrelated region pairs have no pin comparison. The predicate is required to admit all and *only* producer-established relations; the existing `make` arguments (`hardFeatureEdges`, `sourceTopologyRegions`, the A3 atlas, topology and cell records) do not carry **which producer was selected**, the exact selected periodic strip-dual relation set, or the curved producer's `acceptedCutEdges`. A predicate using existing inputs alone cannot be shown exact. **Minimal additional authoritative input**: the selected producer's **source-edge/face-pair gauge-relation set** (canonical typed pair/edge identities). This record names the missing input only and does not design/publicly authorize a new API or source change. The defining producer must establish it, and the factory must independently verify its authority; do not trust an arbitrary caller-provided exclusion mask.

| Outside-predicate class | Existing independent authority / gap |
|---|---|
| Two-face edge between distinct source topology regions | `sourceTopologyRegions` is authoritative for the boundary (S:9670–9727); a hard-rail field transition is independently checked against the atlas in `rail-transition-a3` (S:8717–8732), *not* via gauge difference. |
| Accepted bounded-disk cut inside one source region, including torus `{0,3}` | Accepted global topology arc plus exact source support and conformity schedule are authenticated during producer construction (S:15333–15532); **`make` does not receive this cut set**, so independent membership authentication there is a gap requiring the producer-domain evidence named above. |
| Periodic non-strip edge or holonomy seam | Periodic relation endpoint `branchAuthority` (S:13104–13107, 9281–9297, 9470–9488) and periodic holonomy materialization; the per-strip gauge transport does not attest the omitted edge. An independent `make` membership proof of the selected strip domain is missing. |
| Open source boundary (one incident face) | No gauge comparison is defined; existing pin skips it (S:8539–8541). |

#### Production consumer census (RA-45.1)

S:18392–18403 publishes the per-face gauge; S:19017–19028 reads local face gauge to build source-bound product authority. R:4630–4642 reads it for an occurrence's selected source face; R:5192–5193 attaches first/second endpoint gauge records; R:5633–5655 checks **presence and face identity**, not arithmetic difference; R:7317–7324 checks evidence **presence and region classification**, not numerical difference. R:2154–2164 hashes gauges in a reproducibility fingerprint rather than computing a relation. S:8717–8732 checks hard-rail field transitions against the atlas without face-gauge differences. No production consumer reading a gauge difference *across an excluded cut/region edge* was found in these paths. This is a static source census, not a claim of exhaustive behavioral proof.

#### Review stop conditions and CB20 oracle specification (NOT executed)

**Conditional stop risk:** without an accepted conformity baseline, uniform and periodic producers can include an intra-region hard carrier in their gauge-domain BFS/check (S:11996–12035, 13208–13229, 14019–14039, 14275–14286). The bounded producer can also include hard carriers unless they belong to `acceptedCutEdges` (S:16217, 16346). Review must decide whether this satisfies RA-110.5's *producer-domain-includes-hard-carrier STOP* on a reachable accepted production path. No source-only proof of a successful selected-producer witness is established in this DEFN. **If one is established, STOP and return to Review; do not implement the blanket hard-edge exclusion.**

Later CB20 oracle *only if independent DEFN-P1-REV accepts the contract*:

1. Each of nine M2 identities (`cp3entry:2/6`, `focused30:12`, `cp3entry:1`, `focused30:6/20/24`, `selector:446/447`) should **pass the pin only**, not be presumed Produced or accepted; R-route remains NOT REACHED until measured.
2. Existing `SurfaceCellFactoryRejectionSite` negative must still fail on a **producer-related** interior `(0,4)` edge with one altered face gauge; do not weaken the independent checker or rewrite values.
3. New negative: construct a region containing hard-feature authority and an explicitly proven **noncut** interior related source edge; alter exactly one incident face gauge by +1 modulo 4, preserve A3 transport and all unrelated metadata, and require deterministic `gauge-pin-consistency` at that edge. Include reverse edge, face-row permutation, same-region nonseparating hard-edge and between-strip nonrelated-edge controls. Negative must fail for the violated equation and pass when restored; otherwise it does not establish the domain guard.
4. Prove domain-pair identities are source-topology canonical, deterministic, immutable after production, and derived rather than caller-selected; independently check each against the producer's generated relation proof. Any missing relation evidence fails closed, rather than skipping all edges.

**Disposition:** Definition is source-grounded but contains an unresolved reachability-dependent RA-110.5 stop condition and upstream cut-set inclusion gap. It does **not** authorize CB20, permit tests or source edits, or resolve H-pin beyond Review. Frozen 66/17/49, debt 1, CP2 491/491, R3 rejected 403/497, TB18 candidate 448/497 and selector 497 unchanged; RP-01 open; RP-02 UNREACHED; Gate C suspended.

## `Architecture_M6_CP3_TB18_Rail_Vertex_Endpoint_Independent_Review_20261020.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_TB18_Rail_Vertex_Endpoint_Independent_Review_20261020.md`; moved verbatim.

### TB18 independent review — evidence adjudicated with real history (2026-10-20)

**Turn:** `M6-CP3-TB18-R10-RAIL-VERTEX-ENDPOINT-REV`. **Basis:** RA-103.5; TB18 Part A `39349041417` / `12231529583`; Part B `39349459268` / `12232299548`; CB18 source `3bd24682c5e18eece541ab4d1f38f781a2230e41` and package `12227516380`. This review independently accepts the **diagnostic TB18 measurements**, not CP3 acceptance or universal R-route factory coverage. The next bounded turn is the test-only selector242 fixture repair.

#### Independent re-derivation

- Both ZIP hashes recomputed exactly: A `e08b092d9451d912ead323b7f514d97512eb3c02b4c4971333ecb0498caab459`; B `b3ba45665f900d917c96af223118c49594bd8651a488a08ab9f9f74d5e4a6e9b`. Every manifest entry validated independently, A **18/18**, B **1019/1019**; archive files reconcile with their self-excluding manifests.
- Recomputed from 497 `combined-ledger.tsv` identities, not from the TB18 report: focused30 **19 PASS/11 RED**, focused12 **12/0**, selector449 **417/32**, cp3entry **0/6**, overall **448 PASS/49 RED**. All identities unique, selected once, 0 skipped; every raw log SHA-256 matches its ledger. All 49 RED identities, raw hashes, first failure context, baseline membership, and inventory status independently matched the retained 49-row TSV. The inventory's SHA-256 recomputed as `36cc9682cab7ceac02beca2a8ee25b2231bc3f33ffa768d03e1ade3dc142b9ca`.
- Compared the complete 497 keys with TB16C's retained 72-RED TSV: **23 RED→PASS, zero PASS→RED**; no new RED. All **30** TB16C B2 identities now have **16 PASS / 14 RED** at another first observable; B1=0, B2=0, B3=0, B2+B3=0, U6=0, other=49. The one `firstPredicate` precedence case, selector405, is correctly classified other: its diagnostic reports `a3ProbeContactPublished=0`; RA-91.2 excludes vacuous B2.
- Part A independently read from `ledger.tsv` and all 14 raw logs: #1–#9 and #12–#14 PASS; #10/#11 RED with the exception `non-constant internal-midline hard-rail rectangle producer failed: PublishedProductRejected`. All four `gate` tests (#1–#4) PASS and no B2 first predicate survives in #8–#12. #14 `ProducedOpenRailInteriorVertexEndpointRejectsForgedTags` PASS includes a positive checked-factory call and three single-field forged-tag negatives, so its witness is not vacuous. The universal statement “every consumer-certified R route is factory-admissible” remains unproved by this selected witness; #10/#11 abort earlier in their producer fixture.
- Execution-boundary receipts show immutable package/source/view/selectors, Part A 14/14 selected and B 497/497, neither a rebuild nor relink, benchmark, discovery regeneration or source/test mutation. No new stable accepted-green loss; **66 events /17 categories /49 recurrences, debt 1**, accepted M6 CP2 **491/491**, rejected R3 **403/497** and frozen CP3 selector 497 all stay unchanged. `RP-01` open; `RP-02` UNREACHED; Gate C suspended.

#### Independent adjudication and remaining obligations

1. **History-backed Review authority DISCHARGED.** Full-history checkout audit [run 39380260884](https://github.com/akashskypatel/Directional/actions/runs/39380260884), artifact `12244737394` (`sha256:d93bdb8b907494a4425319355018cf69df139840dbe4df821e331ca7851595f6`) on event `aeccc6682ebcf9db9eb6a020d67565a0a15c0931`: schema validator PASS; `review_check.py authority 3bd24682c5e18eece541ab4d1f38f781a2230e41` PASS (real ancestor; no `src/include/tests/benchmarks/CMakeLists/cmake` drift), `boundary` PASS (all 39 committed numbered selectors byte-equal; durable rewrite base `8b7299b43` present and headings preserved 4/4,1/1,0/0), and `ledgers --base 8b7299b43` PASS (no historical shrinkage of CHANGELOG/LESSONS). Actual git history is present and non-shallow. Initial attempt [39380115463](https://github.com/akashskypatel/Directional/actions/runs/39380115463) had authority and boundary PASS but used `ledgers` without required `--base`; corrected caller was separately committed before retry. The checker does not itself certify this later documentation patch: compare the final changed paths and verify HEAD after application.
2. **RA-103.5 Part A adjudicated:** all four gates PASS. Its specific B2-preservation falsifiers did not trigger. Focused #14 has real Produced, a checked-factory positive, and three individually forged negative cases; this proves the tested R route only, not universal factory admissibility. Two cross-region producer fixtures #10/#11 fail **earlier** with `PublishedProductRejected`; this is a **carried producer/fixture diagnostic**, not demonstrated checked-factory `InvalidSourceAuthority`, nor evidence that every certified route is admissible. Preserve as a bounded later source/fixture provenance question; do not weaken or bypass checked factory, silently reinterpret it as a proof, or claim CP3 acceptance.
3. **RA-103.5 Part B adjudicated:** all 497 identities independently accounted for; every predicted migration and all exclusions (B1/B2/B3/U6 and PASS→RED) hold, 49 RED/other remain. All results are candidate/non-stable; no stable event, ID, selector or debt count changed. `RP-01` open, `RP-02` UNREACHED, Gate C suspended. Continue the RA-96.6 test-only fixture-debt order, beginning with selector242, then 174 → 250 → adjacent-sheet → 191 family → 442, and separately the T/I/R assumptions TQ:3017/3257/8832, RE:713, P10:7518.
4. **Selector242 is a test-authority defect, not a demonstrated production fail-open** (RA-92.3). `tests/SurfaceCellsPhase10Tests.cpp:3286` mutates `crossField.edgeTransitions`; P10:3295–3298 creates the A3 atlas from the *unmodified* `sourceField`, then passes the atlas to the producer. The independent production transport lookup consumes atlas authority. Next authorized unit is **test-only Code + Build** `M6-CP3-CB19-RP01-SELECTOR242-ATLAS-AUTHORITY-TEST`, with exact steps/falsifiers in `Architecture_M6_CP3_CB19_Selector242_Atlas_Authority_Test_Plan_20261020.md`. It must prove the bad transition is actually in the atlas-owned input and preserve an unmodified positive control. If malformed A3 cannot be constructed or the original `InvalidTopologyRegionTransport` oracle does not apply at its actual rejection boundary, STOP and return to independent Review rather than inventing another expected error or changing production code. Test runtime occurs only in its distinct TB successor.

#### Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | n/a — no selector changed or new accepted selector; full-history `boundary` rehashed all 39 numbered selector files against committed HEAD (all PASS) |
| Decisive claims independently re-derived | both ZIP digests, A 18/18 + B 1019/1019 manifests, 497 ledgers/raw hashes, all 49 RED, 30 prior B2, 14 Part A |
| Non-vacuity checked | #14 positive Produced/factory and three forged negatives; universal factory quantifier explicitly unproved |
| Prior obligations discharged/carried | RA-103.5 A/B falsifiers measured and adjudicated; cross-region producer exceptions, universal R factory claim and RA-96.6 fixture debt explicitly carried |
| Stable accounting | 66/17/49, debt 1, accepted CP2 491/491, rejected R3 403/497, frozen CP3 selector 497, TB18 candidate 448/497 |
| New candidates/obligations recorded | existing TB18 candidate adjudicated as non-stable; producer exceptions and selector242 test-authority debt carried in tracker and plan |
| ORIENTATION currency line | 2026-10-20 independent TB18-REV complete; CB19 next |
| ORIENTATION §3 / §4 / §7 / §8 | §3 candidate adjudication and accounting; §4 no witness changed, §7 priorities updated; §8 same existing test-authority/nonvacuity defect pattern (no new one) |
| CHANGELOG | one TB18-REV disposition entry added |
| ROADMAP | candidate still not accepted; pending fixture debt stated |
| Selector manifest | n/a — selector membership, prefix and acceptance unchanged |
| LESSONS | no new rule; existing test-authority, source provenance, immutable evidence and nonvacuity lessons cited |
| Consolidation under CLEAN_UP_POLICY | no superseded document removed: TB18 immutable harvest, RA-103.5 and TB16C baseline remain live independent evidence; no new file was retired between TB17-REV and TB18-REV |
| Successor frozen | `M6-CP3-CB19-RP01-SELECTOR242-ATLAS-AUTHORITY-TEST`; exact test-only CB plan names positive/negative falsifiers and STOP conditions |
| Turn boundary held | PASS: only review documents and temporary audit control changed; no semantic source, test, fixture, selector, compile or runtime changed |
| review_check.py boundary | PASS, real non-shallow checkout on run `39380260884`, with authority and ledgers independently PASS |
| `STATUS` lifecycle maintained | TB18-REV retains original Started at; COMPLETE only after patch application and cleanup, final beacon last |
| Pushed to origin, branch in sync | validate final patch/changed-path set against current GitHub head and no outstanding repository mutation before last STATUS beacon |

## `Architecture_M6_CP3_TB19A_Torus_Rejection_Site_Harvest_Report_20261020.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_TB19A_Torus_Rejection_Site_Harvest_Report_20261020.md`; moved verbatim.

### M6-CP3 TB19A — Torus factory-rejection-site artifact-only harvest (2026-10-20)

**Turn:** `M6-CP3-TB19A-RP01-TORUS-REJECTION-SITE`. **Authority:** RA-108.5 amended by RA-109.4; no adjudication. **Disposition:** artifact-only execution succeeds; six torus rejection cases RED, positive fixture-loaded control PASS. TB19-REV is mandatory next.

#### Frozen authority and integrity

- Semantic source: `d2c7483cde8e65d6c35c5df06fa880465a4da46c`.
- Compile/package: CB19A artifact `12275794192`; ZIP SHA-256 `e4a39cdb2db5ef9953748cffd3e031e4294ddaf348f4a64fee3b97e08bdd723a`; 28/28 package entries verified; `runtimeExecution=false`, GMP linked, build exit 0.
- Exact executor/harness commit: `9aa2a84d679088cb40ddd75b5da7738fa5c74154`; harness `.agents/Directional/tools/m6_cp3_tb19a_torus_rejection_site_harness.sh` SHA-256 `21480db48fe005896d126bad30054e4711f5597117324ff4039a30c74d05cabc`.
- Dispatch request: `5335c610a41a844970a738ce0829f975487c2fa3`, request `m6-cp3-tb19a-torus-20261020-01`.
- [Workflow run 39484475466](https://github.com/akashskypatel/Directional/actions/runs/39484475466), attempt 1, completed success.
- Result artifact `12292268624`, ZIP SHA-256 `25d48ed757a54ba77b7876ff0d3b833673cd57dab151f1e9632fcfcb7a8efa7c`; expires 2026-11-03T19:34:19Z.
- Exact filters selected once each: 7/7 planned and executed; 0 missing; 6 RED; 1 PASS. Result `SHA256SUMS` verified; source, package, staged view and frozen selectors postflight unchanged; no build, relink, benchmark or selector-497 execution.
- Corrected staged fixture root `view/test-data/benchmarks/fixtures`; `milestone-g/torus.obj` and `torus.rawfield` both prechecked as regular files. No log contains `test-data package not found`.

#### Seven-row ledger

Rows 1–6 share the **exact first failure**:

```text
unknown file: Failure | C++ exception with description "torus nonzero-Z4 source witness producer failed: PublishedProductRejected product=0 detail=none site=gauge-pin-consistency;edge=0,3" thrown in the test body.
```

For rows 1–6, the parsed fields are `product=0`, `detail=none`, `site=gauge-pin-consistency;edge=0,3`. Exit 1, selected 1, passed 0. Row 7 exits 0, selected 1, passed 1, without a first failure, product/detail/site fields. The first-failure column below uses **F** for the exact line reproduced above and **—** for no failure.

| # | Identity | GTest | TB18 | TB19A | First failure | product | detail | site | Raw log SHA-256 |
|---:|---|---|---|---|---|---|---|---|---|
| 1 | `cp3entry:1` | `M6CP3.PeriodicExactA3UnequalFaceGaugeUsesRelationAndOccurrenceAuthority` | RED | RED | F | 0 | none | gauge-pin-consistency;edge=0,3 | `ea16747f065e70233f3e465efd60ae1d3e2dfca870efa1defc5c9506e7065e06` |
| 2 | `focused30:6` | `M5CP3.ProducedTorusPeriodicPairStorageSwapPreservesSemanticDirection` | RED | RED | F | 0 | none | gauge-pin-consistency;edge=0,3 | `82aec80432b7a38921cf40601fa0380ed529093657b4cef8982e08efcd71bd45` |
| 3 | `focused30:20` | `M6CP1.NonzeroZ4WitnessPassesProductionCompletionOwnership` | RED | RED | F | 0 | none | gauge-pin-consistency;edge=0,3 | `c48c808dc33d9b690bf0a3a811340960bf47feb6feb130c51438ae10c87b00f5` |
| 4 | `focused30:24` | `M6CP1.ThinAdapterOutputIsPureProjectionOfStageProducts` | RED | RED | F | 0 | none | gauge-pin-consistency;edge=0,3 | `b72e021926348298382f243cb175658793d0fc4da126bf88cb0f128611234cd4` |
| 5 | `selector:446` | `M5CP3.ProducedTorusNonzeroZ4RotationTranslationMaterializes` | RED | RED | F | 0 | none | gauge-pin-consistency;edge=0,3 | `3ca69e0a3b2c430f37e8b6e1757c3bfd54c33c3f73624a551ced29de4e48a5f1` |
| 6 | `selector:447` | `M5CP3.ProducedTorusTamperedNonzeroZ4TransformRejectsTyped` | RED | RED | F | 0 | none | gauge-pin-consistency;edge=0,3 | `2da1abd38effd0a90648b4d96fd62e828b5371dbb06f51de34c1f6ada52cb377` |
| 7 | `selector:443` | `M5CP3.ProducedTorusPublishesTwoCanonicalPeriodicRelationsAndOwnedEdges` | PASS | PASS | — | — | — | — | `c646ddf8759f0d4fbb0d9ac5fddfda5025dc6da2ea252729c73896533d1a4b15` |

#### Falsifiers (RA-108.5)

- **G1 HELD:** control `selector:443` PASS. This is the positive witness proving torus fixture resolution and a produced torus that clears the pin.
- **G2 HELD:** each of the six first failures has the specified `torus nonzero-Z4 source witness producer failed: PublishedProductRejected` prefix and appended fields.
- **G3 HELD:** all six sites are `gauge-pin-consistency`; none falls at another site.
- **G4 HELD:** every `product=0` has a nonempty site.
- All six `product` codes are zero; RA-106.5 nonzero-code follow-up is not invoked.

#### Static hard-rail edge classification (RA-109.4)

At pinned source `tests/SurfaceCellTransitionQuotientTests.cpp:908–927`, `torus_row408_hard_edges` defines 18 unordered source edges in two cycles:

- **Minor:** 0–3–25–37–49–61–0 (six edges).
- **Major:** 0–1–4–6–8–10–12–14–16–18–20–22–0 (12 edges).

Each of the six observed rejection-site edges is the unordered pair **{0,3}**, a member of the **minor** hard-rail cycle and **not** the major cycle. This is a static input-edge membership observation, not an adjudication of H-pin, transport correctness, periodic-cut semantics, or the R-route.

#### Scope and handoff

TB19A does not modify source, tests, selectors, fixtures, package, or binaries; no compile or relink occurred and no benchmark ran. The six TB19 invalid torus readings (fixture staging defect) are now measured here. Together, TB19 (16 valid cases) and TB19A (seven cases including control) are the evidence inputs for mandatory `M6-CP3-TB19-RP01-FACTORY-REJECTION-SITE-REV`. Stable counts remain 66/17/49, debt 1, CP2 491/491, R3 403/497 rejected, TB18 candidate 448/497, selector 497 frozen. RP-01 remains open, RP-02 UNREACHED, Gate C suspended. No repair or promotion is authorized by these results.

## `Architecture_M6_CP3_TB19_Factory_Rejection_Site_Harvest_Report_20261020.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_TB19_Factory_Rejection_Site_Harvest_Report_20261020.md`; moved verbatim.

### M6-CP3-TB19 Factory Rejection-Site Harvest Report (2026-10-20)

**Turn:** `M6-CP3-TB19-RP01-FACTORY-REJECTION-SITE` (harvest-only closeout). **Authority:** RA-107.3 as amended by RA-108.3–108.4. No new runtime or dispatch occurred.

#### Immutable evidence and verification

- GitHub Actions run: [39464430751](https://github.com/akashskypatel/Directional/actions/runs/39464430751); result artifact: `12285225197`, expires `2026-11-03T17:19:06Z`.
- Downloaded ZIP SHA-256: `2b5dfacf79e068cad8e28af5c840668c3f26287a2a473fade63924d12d77dec0`, independently recalculated and equal to provider digest.
- Immutable package: `12275794192`; semantic source `d2c7483cde8e65d6c35c5df06fa880465a4da46c`.
- `SHA256SUMS`: **26/26 verified**. Raw log ↔ ledger hashes: **22/22 verified**.
- Boundary manifest: planned `22`, executed `22`, RED `19`, missing `0`, postflight `true`, exit `0`. Every row selected exactly one gtest.
- GMP and GMPXX were linked. `package=true source=true execution_view=true frozen_selectors=true`; `compile=false relink=false benchmarks=false selector497=false`.
- **RA-108 validity:** 16 rows valid (#2, #3, #5, #10–#22); 6 torus rows (#1, #4, #6–#9) **NOT MEASURED — fixture staging (RA-108.2)**, despite their literal gtest `RED` and exit 1.
- Valid observations: `cp3entry:2/6` and `focused30:12` all reject at `product=0`, `site=gauge-pin-consistency;edge=1,4`; 10 M1 failures unchanged under RA-107.2 line mapping per RA-108; controls 3/3 PASS.

#### Full 22-row ledger

Raw-log hashes below are independently checked against `raw/<index>.log`. `—` indicates a field not streamed. For `focused30:12`, the harness ledger omits the factory fields; `product=0` and the rejection site are extracted from the first-failure assertion and detail is `not streamed`. The first-failure column reproduces the harness-captured failure, including its mapped line numbers.

| # | Group | Identity | TB18 | TB19 observed | First failure (RA-107.2 mapped) | Product | Detail | Site | Raw SHA-256 |
|---:|---|---|---|---|---|---|---|---|---|
| 1 | M2 | cp3entry:1 | RED | NOT MEASURED — fixture staging (RA-108.2) | unknown file: Failure \| C++ exception with description "Directional test-data package not found adjacent to test executable: /home/runner/work/_temp/M6-CP3-TB19-RP01-FACTORY-REJECTION-SITE/view/bin" thrown in the test body. | — | — | — | 99fa232f0a6783b2679e70e3f8f9da5361918c8f7a6dc755100b52ad42a990eb |
| 2 | M2 | cp3entry:2 | RED | RED | unknown file: Failure \| C++ exception with description "non-constant internal-midline hard-rail rectangle producer failed: PublishedProductRejected product=0 detail=none site=gauge-pin-consistency;edge=1,4" thrown in the test body. | 0 | none | gauge-pin-consistency;edge=1,4 | d4558ec2316ad952e99a88d50a01b6a81c93cf789ee43e7e561782b8ff191cc3 |
| 3 | M2 | cp3entry:6 | RED | RED | unknown file: Failure \| C++ exception with description "non-constant internal-midline hard-rail rectangle producer failed: PublishedProductRejected product=0 detail=none site=gauge-pin-consistency;edge=1,4" thrown in the test body. | 0 | none | gauge-pin-consistency;edge=1,4 | 5fc4d9634e06484a422e79c2aecca747eab34e6194d7a2e51afcd61b423952a1 |
| 4 | M2 | focused30:6 | RED | NOT MEASURED — fixture staging (RA-108.2) | unknown file: Failure \| C++ exception with description "Directional test-data package not found adjacent to test executable: /home/runner/work/_temp/M6-CP3-TB19-RP01-FACTORY-REJECTION-SITE/view/bin" thrown in the test body. | — | — | — | 8aa450024489093331b7591ac6f84423c4811e43fc80d98403195d0f706c18f3 |
| 5 | M2 | focused30:12 | RED | RED | ../../Directional/Directional/tests/SurfaceCellTransitionQuotientTests.cpp:5036: Failure \| Expected: (relabelledFront) != (nullptr), actual: NULL vs (nullptr) \| product=0 site=gauge-pin-consistency;edge=1,4 | 0 | not streamed | gauge-pin-consistency;edge=1,4 | 90dee9731373e98ed41db42ce0e1a3ed2a7db350f05d76ab5bdb43a584fa693f |
| 6 | M2 | focused30:20 | RED | NOT MEASURED — fixture staging (RA-108.2) | unknown file: Failure \| C++ exception with description "Directional test-data package not found adjacent to test executable: /home/runner/work/_temp/M6-CP3-TB19-RP01-FACTORY-REJECTION-SITE/view/bin" thrown in the test body. | — | — | — | 5c542ddec1f3d995c05dc5013048a5a0f16eac75d0a120495155793a3aabd67b |
| 7 | M2 | focused30:24 | RED | NOT MEASURED — fixture staging (RA-108.2) | unknown file: Failure \| C++ exception with description "Directional test-data package not found adjacent to test executable: /home/runner/work/_temp/M6-CP3-TB19-RP01-FACTORY-REJECTION-SITE/view/bin" thrown in the test body. | — | — | — | 236f2e6112ed0daebbc3641afdc743ad5560092e46e457eaac8bc08d50bb6d92 |
| 8 | M2 | selector:446 | RED | NOT MEASURED — fixture staging (RA-108.2) | unknown file: Failure \| C++ exception with description "Directional test-data package not found adjacent to test executable: /home/runner/work/_temp/M6-CP3-TB19-RP01-FACTORY-REJECTION-SITE/view/bin" thrown in the test body. | — | — | — | 0c468214c2404ae03dfc72ecc0de837aac7ade9269c62d3cc98989e2367fd6c8 |
| 9 | M2 | selector:447 | RED | NOT MEASURED — fixture staging (RA-108.2) | unknown file: Failure \| C++ exception with description "Directional test-data package not found adjacent to test executable: /home/runner/work/_temp/M6-CP3-TB19-RP01-FACTORY-REJECTION-SITE/view/bin" thrown in the test body. | — | — | — | 660cf171750c0313ebc436cc856fcd051ad9be5aa3d37422c10ef914d2649f51 |
| 10 | M1 | focused30:3 | RED | RED | unknown file: Failure \| C++ exception with description "Malformed phase-front draft rejected at publication." thrown in the test body. | — | — | — | cfbfd88ba21c24579cb0413d38de3daffc03aaee3191ca726217c588ca138899 |
| 11 | M1 | focused30:22 | RED | RED | ../../Directional/Directional/tests/SurfaceCellTransitionQuotientTests.cpp:5828: Failure \| Expected: (front) != (nullptr), actual: NULL vs (nullptr) | — | — | — | 5d6ea2f2c088d448a29a88ad4b811d5d4013a56369cc09ce53e725482f4d826d |
| 12 | M1 | focused30:23 | RED | RED | ../../Directional/Directional/tests/SurfaceCellTransitionQuotientTests.cpp:5869: Failure \| Expected: (front) != (nullptr), actual: NULL vs (nullptr) | — | — | — | c4ee2b4ca4352fc998e60ea1c9e671bba383e28d1083df75edab26a1cdac2fac |
| 13 | M1 | selector:139 | RED | RED | unknown file: Failure \| C++ exception with description "Failed to rebuild structurally valid phase-front product." thrown in the test body. | — | — | — | 971c2b0511906f6c7b141de3d0f8966924d2372df986bf6d63918751c3105d0d |
| 14 | M1 | selector:140 | RED | RED | unknown file: Failure \| C++ exception with description "Failed to rebuild structurally valid phase-front product." thrown in the test body. | — | — | — | 4111ca2374322f1380c2bdab530158d74d0407e7a2df775b1186ff00303edeed |
| 15 | M1 | selector:142 | RED | RED | unknown file: Failure \| C++ exception with description "Failed to rebuild structurally valid phase-front product." thrown in the test body. | — | — | — | e5b26fc203bc7a30d75ec60d11b589a9a4bc836b349b7aab104b761160ddbde0 |
| 16 | M1 | selector:211 | RED | RED | ../../Directional/Directional/tests/SurfaceCellTransitionQuotientTests.cpp:8600: Failure \| Expected equality of these values: \| directional::geometry::SurfacePhaseFrontProductErrorCode:: InvalidOppositeEdge \| Which is: 4-byte object <07-00 00-00> \| error->code \| Which is: 4-byte object <00-00 00-00> | — | — | — | 651bbc7fca05ed778d14d2784cce78cd224909bd2f10861c2636bf13be09aa5e |
| 17 | M1 | selector:219 | RED | RED | ../../Directional/Directional/tests/SurfaceCellTransitionQuotientTests.cpp:8579: Failure \| Expected equality of these values: \| directional::geometry::SurfacePhaseFrontProductErrorCode:: InvalidOppositeEdge \| Which is: 4-byte object <07-00 00-00> \| error->code \| Which is: 4-byte object <00-00 00-00> | — | — | — | f731e9bd9378e557e2b6ed980d341195e3a5c0d2082857916424432ac7af4c99 |
| 18 | M1 | selector:227 | RED | RED | ../../Directional/Directional/tests/SurfaceCellTransitionQuotientTests.cpp:9722: Failure \| Expected equality of these values: \| "InvalidHardRailAuthority" \| result.failure \| Which is: "InvalidPhaseFrontProduct" | — | — | — | e0ceb8ed23f2973d6798fa014993ce61e4797f730cfce329e39f6870278713c0 |
| 19 | M1 | selector:230 | RED | RED | ../../Directional/Directional/tests/SurfaceCellTransitionQuotientTests.cpp:9702: Failure \| Expected equality of these values: \| "InvalidHardRailAuthority" \| result.failure \| Which is: "InvalidPhaseFrontProduct" | — | — | — | 036ea6d705a7a8d4c116407e8af84b8301eda1d29c3f53cd9780f1481b3e8618 |
| 20 | control | selector:217 | PASS | PASS | — | — | — | — | b19bc49261dce0f3eab7da41182dde262b5c57812d111725dd1128ddd7da89c1 |
| 21 | control | TB18 A#14 | PASS | PASS | — | — | — | — | 1dc0511a439ae5925ddccbf03dab7a5261ec1f31de7d1fe7ea50cb422e393f28 |
| 22 | control | new | — | PASS | — | — | — | — | 13e3963318088fd2da4c97b0d17ca421545bd8188787d8cd3cb4e90f97e84031 |

#### Falsifiers and limits (RA-108.3)

- **F1: HELD on the 16 valid rows.** The six torus rows were **NOT MEASURED**.
- **F2: HELD.** No valid `PublishedProductRejected product=0` has an empty site.
- **F3: HELD** for `focused30:12` at edge `(1,4)`; torus rows **NOT MEASURED**.
- **F4: HELD, 10/10.** M1 first failures agree with TB18 after the RA-107.2 TQ mapping (independent adjudication: RA-108.1).
- **RA-103.5 R-route: NOT REACHED.** Gauge pin rejects `cp3entry:2/6` before the endpoint-certificate loop; no endpoint-R inference is made.
- **RA-106.5 non-zero product code: NONE.** No follow-up under this rule.

#### Boundary, disposition, and successor

RA-108.2 identifies the staging defect: `view/test-data/benchmarks` was populated rather than the required `view/test-data/benchmarks/fixtures`. An exit status of zero for the harness does not validate the six torus rows. This report does not adjudicate H-pin, rail-carrier/periodic-cut meaning, or the R-route.

**Authorized successor:** `M6-CP3-TB19A-RP01-TORUS-REJECTION-SITE` (seven-row artifact-only torus rerun under RA-108.5, separate turn). Next mandatory Review after TB19A: `M6-CP3-TB19-RP01-FACTORY-REJECTION-SITE-REV`. No code, test, selector, fixture, workflow or package changes in this turn.

**Stable accounting unchanged:** 66/17/49, debt 1; CP2 491/491; R3 403/497 rejected; TB18 candidate 448/497; selector 497 frozen; RP-01 open, RP-02 UNREACHED, Gate C suspended.

## `Architecture_M6_CP3_CB21_Torus_Witness_Scope_Review_Decision_20261021.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_CB21_Torus_Witness_Scope_Review_Decision_20261021.md`; moved verbatim.

### RA-116 — CB21 torus witness scope, independent Review (2026-10-21)

**Turn:** `M6-CP3-CB21-RP01-TORUS-WITNESS-SCOPE-REV`. **Verdict:** CB21 accepted for **static scope and compilation only**; TB22 runtime evidence is not yet available. Working PR #8 remains draft/open. No product, test, selector, fixture, benchmark, build or workflow logic changed in this Review.

#### RA-116.1 Independent source and package checks

- Reviewed GitHub's exact semantic commit [`8453e19e6ac7d976a9cac45978ad31104a52f034`](https://github.com/akashskypatel/Directional/commit/8453e19e6ac7d976a9cac45978ad31104a52f034), not just CB21's report. Its entire file set is **one** file, `tests/SurfaceCellTransitionQuotientTests.cpp`; `+73/-47`. The diff has precisely three edited regions: `ProducedTorusWitnessFixture`'s last member, the shared torus fixture's candidate loop/selection/receipt/return, and `cp3entry:1`'s assertion stream. No other test/helper and no `src`, `include`, selector, harness or workflow files changed in the implementation commit.
- The original reciprocal pairing still requires two tracer-produced `PeriodicCut` front edges, the same relation, the same source occurrence/span orientations, and inverse routes; holonomy still requires the published ID, successful semantic-action resolution and exact cut-route/inverse comparison. The earlier odd-delta `continue` is gone: all candidates reach both independent measurements. The selected candidate is the earliest holonomy match among odd gauges if one exists, otherwise the earliest holonomy match. The complete seven counters and each per-candidate `delta/recip/holo` plus `selected` are assembled, including in the no-witness exception. D2 remains the same `ASSERT_TRUE(delta==1 || delta==3)` with only a receipt appended. The fixture's input source, source/A3 generator enumerator and semantic-relation helper are unchanged.
- The candidate generator takes face IDs from actual source-region occurrence owners; the phase-front constructor requires a nonempty, face-count-matched branch-rotation vector when periodic holonomies are published (`SurfaceCellTracing.cpp:8495-8504`). Thus a reciprocal candidate selected with `delta=-1` is not a supported produced fixture state; this was checked, not assumed. In particular no gauge-parity constraint is bypassed in `cp3entry:1`.
- Independently downloaded compile package `12318897957`: ZIP SHA-256 **`f0ae4338c462600b6cddbd0a768e0432f2148148f40f920790d6c8f1c0e9c606`**, root `SHA256SUMS` SHA-256 **`4726b88230cb81560ae5464327680a4199bcc7ce42a0e1de011728ba6c171bc0`**, and packaged source archive **`63b260ac5045c141b8918b6d2678a673450e49d82429826bc6614f6d44c98520`**. All **28/28** listed files verify, packaged TQ SHA-256 `a1179ad15cf03f3f7f9802bc35a3fc1986ebd95cedb8a86c479509497a2dc8e8` equals exact verified branch snapshot TQ. Preflight/build are `0/0`, five source statuses empty, eight target names are present, actual linker command contains `libgmpxx.so` and `libgmp.so`, and command boundary explicitly says `runtimeExecution=false`, `exactArithmeticBackend=GMP`.
- Source snapshot run `39544316215`, artifact `12320538954`, exact head `4d0b0a1f9139691dfea8ae1ab7fd6c0199e5e877`, verified **5,720/5,720** file hashes. The source-snapshot trigger and STATUS commits are nonsemantic and do not alter packaged TQ.

#### RA-116.2 Non-vacuity and remaining obligations

The new census now distinguishes `sourceFaceGaugePairs=5; oddFaceGaugePairs=0` from unmeasured reciprocal or holonomy predicates, but **no runtime observation yet proves that `reciprocalTracerPairs` or `holonomyMatchedPairs` is positive**. The CB21 change has not been credited as a runtime fix. A passing selector beyond the shared fixture must reach its own assertion; a fixture throw does not count. The D2 organic odd-gauge witness remains open under RA-33.2/RA-111.3; absent odd candidates trigger `cp3entry:1`'s real D2 assertion, not a fabricated success. `RP-01` remains open; `RP-02` unreached. RA-115.3 M1 failures (`cp3entry:2`, `focused30:12`, ten M1 identities) and deferred fixture-debt obligations are carried to their existing owners unchanged. No stable event or new candidate is created by this static Review.

#### RA-116.3 Exactly one successor

**Authorize only** `M6-CP3-TB22-RP01-TORUS-WITNESS-HARVEST`, artifact-only Test + Benchmark on package `12318897957`, source `8453e19e6ac7d976a9cac45978ad31104a52f034`, using `Architecture_M6_CP3_TB22_Torus_Witness_Harvest_Plan_20261021.md`. Exactly 11 independent test processes: seven torus fixture consumers, `cp3entry:6`, and three unchanged controls. No compile/rebuild, code edit or selector revision. A RED TB routes to mandatory independent TB22 Review; do not launch DEFN-T1 or M1 automatically. Its precommitted falsifiers are in the plan.

#### Review closeout

The verified 32,048-byte Review patch (SHA-256 `8ace3ed09bcafbf620f51dbb9e5067691744eabedfb0a58d41ad60e968499f04`) was applied by the durable Drive dispatcher (`39546749497`, result artifact `12321875478`) and the user-owned Drive staging object was permanently retired (`delete_file success=true`). The independent full-history review gate passed before the temporary workflow and markers were retired. No tests or benchmarks were executed.


| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | n/a to CB21: no selector mutation; selector497 remains frozen; accepted CP2 is unchanged (491/491), no new accepted prefix |
| Decisive claims independently re-derived | GitHub semantic diff, exact TQ bytes, 28/28 packaged hashes, clean build/GMP evidence, independent predicate and selection walk |
| Non-vacuity checked | No runtime claim: reciprocal and holonomy existence unmeasured; exact TB22 receipt/falsifiers explicitly frozen |
| Prior obligations discharged/carried | RA-115.5 static CB21 scope discharged; D2/RA-33.2/RA-111.3, RA-105.3 M1, RP-01, RP-02 and fixture debts carried unchanged |
| Stable accounting | 66 / 17 / 49; debt 1; CP2 491/491 package 11391685901; R3 rejected 403/497; latest TB21 449/497 unaccepted |
| New candidates/obligations recorded | No new stable event; existing obligations remain in tracker and TODO |
| ORIENTATION currency line | Updated to CB21 Review and TB22 next |
| ORIENTATION §3 / §4 / §7 / §8 | §3 and §7 updated; §4 unchanged (no witness runtime); §8 unchanged (existing witness-scope lesson) |
| CHANGELOG | New CB21 Review entry |
| ROADMAP | n/a: no checkpoint status moved |
| Selector manifest | n/a: no selector additions/acceptance |
| LESSONS | Existing §2 **A fixture change reaches every fixture built from it** and **A failure hidden behind an earlier one is unmeasured** |
| Consolidation under CLEAN_UP_POLICY | CB21's 21-line compile evidence remains current immutable package authority; no superseded per-turn report eligible to fold before TB22 |
| Successor frozen | `M6-CP3-TB22-RP01-TORUS-WITNESS-HARVEST`, 11 rows and falsifiers in TB22 plan |
| Turn boundary held | Runtime-free Review; documentation only |
| review_check.py boundary | **PASS** on complete-history GitHub Actions checkout, run `39547232827`, log artifact `12322225719`, exact event source `4cfe0d1a5e1c042e57d40c8a96236c9a213047cd`: all frozen selector hashes match, protected durable rewrite sections preserved, zero source/test/build mutation. `review_check.py ledgers --base 8b7299b43` also **PASS**; no historical CHANGELOG/LESSONS shrinkage. |
| `STATUS` lifecycle maintained | Entry and resume beacons published, `Started at` preserved (`2026-10-21T04:28:35Z`); final COMPLETE beacon to be published as the final repository action after cleanup and verification. |
| Pushed to origin, branch in sync | The complete verified patch was pushed as `56a1754794e0b90012dce99884afc302288eaaca`, with all six intended paths independently confirmed. PR #8 GitHub head verified after workflow and trigger retirement (`46ea50f8aff8b0254fd02939f0a7cadd3e47a0bb`); the full-history CI checkout is clean, though it is a detached HEAD (`git status -sb` does not supply a local branch tracking comparison). |

> *Closed by RA-117 (2026-10-21): TB22 confirmed the fixture-selection scope (reciprocal 5/5, holonomy 5/5); the five CP2 rows split into a fixture atlas defect and the unowned torus A5 isolation family; CB22 is next.*

## `Architecture_M6_CP3_DEFN_ISO_A_Seam_Node_Representative_Census_Review_Decision_20261021.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_DEFN_ISO_A_Seam_Node_Representative_Census_Review_Decision_20261021.md`; moved verbatim.

### RA-124 — DEFN-ISO-A census review: the seam contract does not fit the shared-node producers (2026-10-21)

**Turn:** `M6-CP3-DEFN-ISO-A-RP01-SEAM-NODE-REPRESENTATIVE-CENSUS-REV`.

**Verdict:** the census is **accepted with amendments**.
- Q1 (the `src` enforcer inventory) and Q5 (reach) are accepted.
- Q2 and Q4 are **amended**: Q2 reported statically decidable facts as undecidable and omitted a producer; Q4 misattributed a rule.
- This Review's own finding (RA-124.3) **supersedes RA-123.6–123.7**. The certified-seam contract is written for independently represented sides, but all three producers publish shared nodes in one continuous region frame. **DEFN-ISO-B as framed is withdrawn.**
- The successor is CB24, a diagnostic for one discriminating measurement. No code is authorized.

#### RA-124.1 Verified

- `src` and `include` are identical to `e859175333`.
- Q1: the literal reads match the census exactly: `placement.selectedFace` RP:3891–3892, 4678, 4683, 5051–5052, 5312, 5315, 5347, 5350, 5841–5842; `placement.lattice` RP:4990–4993, 5056–5057, 5149–5153, 5721–5722; `cornerWedgeBindings` RP:3869–3871, 5363, 5538–5539, 7311, 7371, 7447, 8190. `include/` holds only the declaration (RemeshPipeline.h:778).
- Q5: the census states correctly that the new suffix was measured on 3 of the 10 rows.
- Credit: the census declined to design a rule and named the probes it would need.

#### RA-124.2 Corrections to the census

1. **§1 "Selection is per occurrence, not per side" is wrong.** The face is selected per node and only published per occurrence (RA-123.3; RA-124.3 P1).
2. **§1 annulus anchor.** SCT:14502 is the candidate table; the published gauge write is SCT:14596–14615.
3. **§2 omits a producer.** The annulus producer never writes `branchRotation`: only SCT:13419 and SCT:17757 write it (verified by search). Annulus corners therefore keep the default 0 (SurfaceCellTracing.h:1278), while the gauge table holds per-face values.
4. **§2 "residual offsets not statically proven".** The residual can be derived statically for each producer (P3 below). Only *which* producer built region 0 is a runtime fact.
5. **§2 answers the wrong question.** It answers the `(1,0)→97/2` question at A5 (the face clause), but the question asked about A6's turn check.
6. **§4 misattributes the rule.**
   - `point_on_periodic_chart` is shared by the annulus (SCT:15076) and curved (SCT:17636) producers, not used by the curved one alone.
   - The key comparison lists 3 of vertex 61's 6 faces, omitting 118 `[49,59,61]`, 119 `[59,61,71]` and 142 `[0,61,71]`. Face 121's key `[0,1,61]` is still the least, so the conclusion stands.
   - Missed inference: the uniform producer's minimum-row rule would pick 97 (RA-72.6), so the observed 121 is evidence against the uniform producer for region 0.

#### RA-124.3 Finding — the certified-seam contract cannot pass on produced data (static proof)

- **P1 Shared node.**
  - An OrdinaryFront endpoint pair is (the first cell's side start, the second cell's side end) on their shared front edge (RP:4943–4947).
  - Every producer copies one node point into both corners: uniform SCT:13404–13405, annulus SCT:15115–15116, curved SCT:17741–17742.
  - A2 takes `selectedFace` from that point (RP:4448–4458).
  - So both occurrences of an OrdinaryFront relation inside one producer grid carry **the same** `selectedFace`.
- **P2 The A5 seam branch is dead code.**
  - Forward and Reverse each need one span on the certificate's first face and the other on its second face (RP:3855–3875, 3896–3910).
  - The face clauses (RP:3891–3892) require each span's face to equal its own occurrence's `selectedFace`.
  - With equal `selectedFace`s, that demands the first and second faces be equal. That is impossible, because the sheets must differ (RP:3893) and each face row has one sheet.
  - Hence `certified_seam_direction` always returns no direction for a shared-node relation, and RP:5249 rejects **every** certified collinear-seam OrdinaryFront any producer emits. A5-ISO is an instance of this, not a special case.
- **P3 The A6 stripped turn is degenerate.** A6 computes regional = gauge(selectedFace)⁻¹ ∘ branchRotation (RP:5859–5868). By producer:
  - uniform: branch = gauge (SCT:13419–13420, 13579), so regional is always 0;
  - curved: branch = gauge + `chartUBranch`, a single value per region (SCT:16831, 17757–17759, 18037), so regional is always `chartUBranch`;
  - annulus: branch is never written, so regional = −gauge(face).

  For shared nodes, all three give a stripped turn of identity. For any two occurrences of one uniform or curved region, it is identity whatever faces are chosen.
- **Consequence for frozen RA-30a.3 (D3).** D3 requires "face-gauge-stripped branch difference == certificate quarter-turn". It is satisfiable only when the certified turn is identity, or under annulus by a gauge coincidence that reads no lattice data.
- **Corollary 1.** For shared nodes, A6's non-seam OrdinaryFront equalities (chart, branch, coordinate, phase) compare one node's lattice with itself: they are tautological.
- **Corollary 2.** The positive D3 witnesses `cp3entry:3` and `cp3entry:5` are RED with "produced no fully certified reciprocal cross-sheet OrdinaryFront" (TB21 inventory), which P2 predicts. They are filed as "adjacent-sheet helper" fixture debt; this finding contests that filing.
- **No produced seam relation has ever passed A5 and A6 together.**

#### RA-124.4 Realignment

- **RA-123.6 amended.** The A2 per-node representative contributes, but the defect is the seam contract: the A5 face clauses plus frozen D3, set against shared-node producers. A per-occurrence representative would satisfy P2, but P3 would then decide the outcome. RA-72.5 applies: relocation is not repair.
- **Two contract families remain:**
  - **(i) Amend D3 for the continuous frame.**
    - Coordinate-identity transport.
    - A stripped difference of identity.
    - The certified turn checked against the gauge jump `g(second face) − g(first face)`, which is chart evidence (RA-2).
    - A5 side authority from wedge bindings, which `certified_seam_wedge_side` already checks, rather than node-face equality.
  - **(ii) Producers publish per-side representatives** with sheet-relative gauges, leaving D3 unchanged.
- **The deciding fact.** Family (i) is admissible only if the published gauge jump at the seam equals the certificate turn. If it does not, the producer gauge table owns the defect. A frozen definition is not amended on a guess (LESSONS §5).

#### RA-124.5 Successor `M6-CP3-CB24-RP01-SEAM-FRAME-VALUES-SITE` (Code + Build, compile only)

- **RP:** inside the relation-collinear-seam block, after the `spanOnlyN` loop and before `error.isolationSite = std::move(site);`, append in this order:
  1. `;branch=<a>,<b>`: each canonical occurrence's `placement.lattice.branchRotation`;
  2. `;gaugeSel=<a>,<b>`: `sourceFaceBranchRotations()[row(selectedFace)]`, or `none`;
  3. `;gaugeSpan=<a>,<b>`: the same at each canonical span's `interiorBinding.face`, or `none`;
  4. `;turnN=<f>,<r>`: for each matching certificate in `certN` order, `forward().value()`,`reverse().value()`.
- **TQ:** in the A5 branch of `m6cp3_produced_seam_fixture` (TQ:2756–2762), record `a5_rejection_message(a5Construction)` (TQ:960) instead of the bare error name.
- **Invariants:**
  - no decision, return, error-code or assertion change;
  - existing site text is appended to only;
  - every other file is byte-identical;
  - no line over 100 columns.
- **Build and record:** compile the eight targets with GMP/GMPXX and `runtimeExecution=false`. Write `Architecture_M6_CP3_CB24_Seam_Frame_Values_Site_Code_Build_Record_20261021.md` (at most 30 lines).
- **STOP** on any compile error or any need to edit outside those two hunks.

#### RA-124.6 TB25 frame (to be frozen at CB24-REV)

**Rows (11):**
- A5 rows: `focused30:20` (W/P), `selector:444` (T/P), `focused30:28` (T/D);
- D3 witnesses: `cp3entry:3`, `cp3entry:5`, with full assertion messages;
- guard: `selector:447`;
- controls: `cp3entry:6`, `selector:217`, TB18 A#14, `selector:443`, `focused30:7`.

**Routing, pre-registered; read both occurrences:**
- **Producer signature:** `branch − gaugeSel` is 0 for both (uniform); equal to some c ≠ 0 for both (curved); or `branch` is 0 while a gauge is non-zero (annulus).
- **P3:** the stripped turn computed from these values is identity.
- **Gauge jump.** Let d = `gaugeSpan(second) − gaugeSpan(first)` mod 4 and F = `turn0` forward:
  - F = 0 → D3 is satisfiable, and family (i) reduces to A5 side authority;
  - F ≠ 0 and d = F → family (i) is admissible, and D3 must be amended;
  - d ≠ F → the producer gauge table owns the defect.
- **`cp3entry:3/5`:** if any candidate records `relation-collinear-seam`, they join the seam family; otherwise they stay fixture debt at the recorded stage.

#### RA-124.7 Sequence and accounting

- **Sequence:** CB24 → CB24-REV → TB25 → TB25-REV → DEFN-SEAM (the seam contract for the shared-node model, per TB25's routing) → DEFN-SEAM-REV → corrective CB → CB-REV → TB → TB-REV → DEFN-M1 → corrective CB/TB → DEFN-T1 → fixture debt → census → RP-01 Review.
- **Accounting (unchanged):** stable 66/17/49, debt 1, CP2 491/491; R3 403/497 rejected; TB21 449/497 candidate; selector 497 frozen. `RP-01` open, `RP-02` UNREACHED, Gate C suspended.

| Duty | Answer |
|---|---|
| Decisive claims re-derived | The census inventory, re-run; P1–P3 from the cited RP/SCT lines; the `branchRotation` writer search; vertex 61's face keys |
| Non-vacuity | P2 and P3 are proofs over every producer; TB25 measures the one runtime fact (d against F) |
| Obligations | RA-123.7 discharged; RA-123.6 amended; DEFN-ISO-B withdrawn; RA-30a.3 (D3) challenged, not amended |
| Durable docs | Handoff, TODO, tracker, CHANGELOG, ORIENTATION, ROADMAP, Frozen Definitions index, LESSONS |
| Boundary | Review-only; no source, test, selector, workflow or runtime change |

## `Architecture_M6_CP3_TB22_Torus_Witness_Harvest_Plan_20261021.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_TB22_Torus_Witness_Harvest_Plan_20261021.md`; moved verbatim.

### TB22 — Immutable torus witness-scope harvest plan (RA-116)

**Turn:** `M6-CP3-TB22-RP01-TORUS-WITNESS-HARVEST`, Test + Benchmark, artifact-only. **Owner:** TB22; reviewed/issued by CB21-REV. **Source:** `8453e19e6ac7d976a9cac45978ad31104a52f034`; **package:** GitHub artifact `12318897957`, ZIP SHA-256 `f0ae4338c462600b6cddbd0a768e0432f2148148f40f920790d6c8f1c0e9c606`, expires `2026-10-28T03:54:02Z`. Verify 28/28 root package hashes, exact source archive and source/status receipts before execution and unchanged bytes after. Preserve `runtimeExecution` split (CB21 was false; TB22 alone executes tests). Use the durable `test_benchmark` dispatcher and an artifact-only harness with exact frozen hash; no binary regeneration, configuration, relinking, test edits, fixture edits, selector mutation or broader census. Every selected filter must match exactly one test and execute in an independent process; zero skips.

#### Exactly eleven rows

| Class | Key | Exact test name |
|---|---|---|
| torus | `cp3entry:1` | `M6CP3.PeriodicExactA3UnequalFaceGaugeUsesRelationAndOccurrenceAuthority` |
| torus | `focused30:6` | `M5CP3.ProducedTorusPeriodicPairStorageSwapPreservesSemanticDirection` |
| torus | `focused30:12` | `M6CP1.RelationPlacementTransportIsCoordinateRigidAndFaceGaugeInvariant` |
| torus | `focused30:20` | `M6CP1.NonzeroZ4WitnessPassesProductionCompletionOwnership` |
| torus | `focused30:24` | `M6CP1.ThinAdapterOutputIsPureProjectionOfStageProducts` |
| torus | `selector:446` | `M5CP3.ProducedTorusNonzeroZ4RotationTranslationMaterializes` |
| torus | `selector:447` | `M5CP3.ProducedTorusTamperedNonzeroZ4TransformRejectsTyped` |
| M2 control | `cp3entry:6` | `M6CP3.HardRailCrossRegionBindingDoesNotCompareGlobalSheetLabels` |
| control | `selector:217` | `SurfaceCellTransitionQuotient.ExactHardRailCounterpartsStitchAcrossTopologyRegions` |
| control | `TB18 A#14` | `SurfaceCellAuthorityContractCutover.ProducedOpenRailInteriorVertexEndpointRejectsForgedTags` |
| control | `selector:443` | `M5CP3.ProducedTorusPublishesTwoCanonicalPeriodicRelationsAndOwnedEdges` |

The seven torus rows are the seven consumers of the shared nonzero-Z4 torus fixture, including the D2 row, NOT a new 497-run selector gate. Preserve the accepted 491/491 and frozen 497 selector bytes and the 66/17/49 ledger.

#### Predictions (frozen before runtime)

- P1: fixture selection succeeds on genuine reciprocal/holonomy authority and the five CP2-GREEN rows `focused30:6`, `focused30:20`, `focused30:24`, `selector:446`, `selector:447` reach and pass their own assertions. Record selected index and seven counters; `selected=none` or fixture exception invalidates this prediction, even if a process exits successfully.
- P2: `cp3entry:1` reaches **its own D2 odd-gauge assertion** (not earlier fixture failure); predicted RED with `oddFaceGaugePairs=0` and the complete `receipt` visible. If a valid odd witness is actually produced and it passes, report that observation, not the prediction.
- P3: `focused30:12` retains its independently owned A5/factory failure; classify its exact first site, do not count it as a repaired torus row.
- P4: `cp3entry:6` and all three existing controls PASS with unchanged semantics; any regression is a Review stop.

**Decisive falsifier:** if the fixture throws and `reciprocalTracerPairs=0` or `holonomyMatchedPairs=0`, D2 is NOT the established earlier blocker; report the actual `firstPredicate` and route to TB22-REV for periodic source/transport publication, rather than invent a D2 witness or promote the fixture correction. An unexpected out-of-range gauge, failing source/A3 match, post-selection transition mismatch, zero selected test, skip, package/source mismatch, runtime mutation flag, timeout or orchestration error is likewise non-acceptance and requires precise classification. No blanket retry or unrelated repair in TB22.

**After TB22:** always independent `M6-CP3-TB22-RP01-TORUS-WITNESS-HARVEST-REV` (the next TB22 Review turn, not executable in the same turn). DEFN-T1 and M1 remain conditional on that Review; do not auto-advance.

## `Architecture_M6_CP3_TB23_Torus_A5_Site_Harvest_Plan_20261021.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_TB23_Torus_A5_Site_Harvest_Plan_20261021.md`; moved verbatim.

### TB23 — Torus A5 isolation-site harvest plan (RA-120)

**Turn:** `M6-CP3-TB23-RP01-TORUS-A5-SITE-HARVEST`, Test + Benchmark, artifact-only. **Owner:** TB23; issued by CB22B-REV (RA-120). **Source:** `c6e90916eb90bfd33bc8a38c5ece7def15dcc766`; **package:** artifact `12341307713`, ZIP SHA-256 `b5f9a6688226375ea1c6241c2d9a464d9b9ede7679f9259acd03b3fbbb1c8ad5`, root `SHA256SUMS` `7c396be65a3138eca15ad4c7a37db192d6828b80442a656d38f84d1887767f11`, source archive `c3779cc949a97fd8b6ce73e62fc8cc62598c637e362bb57cc5f5ecb52cd0cd75`, expires `2026-10-28T11:21:37Z`. Verify 28/28 before execution and unchanged bytes after. CB22B was `runtimeExecution=false`; TB23 alone executes.

**Harness:** new `.agents/Directional/tools/m6_cp3_tb23_torus_a5_site_harvest_harness.sh`, derived from the TB22 harness. Change only the package/source identities, the rows and the added columns below. Same discipline: `directional_surface_cell_producer_tests`; one process per row; `GTEST_FAIL_IF_NO_TEST_SELECTED=1`; exactly one selected test per row; zero skips. No rebuild, relink, benchmarks, test, fixture or selector edit, broader census or retry.

#### Exactly sixteen rows

Fixture **W** = `nonzero_z4_torus_witness_fixture()`; **T** = `torus_fixture()` (`torus.rawfield`). Path **P** = pipeline failure string; **D** = direct A5 message (CB22B).

| Class | Key | Exact test name | Fixture / path |
|---|---|---|---|
| A5-ISO | `focused30:20` | `M6CP1.NonzeroZ4WitnessPassesProductionCompletionOwnership` | W / P |
| A5-ISO | `selector:446` | `M5CP3.ProducedTorusNonzeroZ4RotationTranslationMaterializes` | W / P |
| A5-ISO | `focused30:24` | `M6CP1.ThinAdapterOutputIsPureProjectionOfStageProducts` | W (3rd `verify`) / D |
| A5-ISO | `focused30:25` | `M6CP1.A6ClosedComplexBoundaryIsCombinatoriallyEquivalentOnProducedTorus` | T / P |
| A5-ISO | `focused30:26` | `M6CP1.A6ClosedComplexBoundaryPreservesHardRailAndPeriodicLabels` | T / D |
| A5-ISO | `focused30:27` | `M6CP1.A6ClosedComplexBoundaryPreservesQuotientVertexLineage` | T / D |
| A5-ISO | `focused30:28` | `M6CP1.A6BoundaryCandidateExtractionHasIndependentEligibilityOracle` (G4-B002) | T / D |
| A5-ISO | `selector:444` | `M5CP3.ProducedTorusPeriodicRelationStoragePermutationPreservesSelectedCertificate` | T / P |
| A5-ISO | `selector:448` | `M5CP3.ProducedTorusUnusedValidRelationDoesNotAlterSelectedCertificate` | T / P |
| F | `focused30:6` | `M5CP3.ProducedTorusPeriodicPairStorageSwapPreservesSemanticDirection` | W / P |
| F | `selector:447` | `M5CP3.ProducedTorusTamperedNonzeroZ4TransformRejectsTyped` | W / P |
| control | `cp3entry:6` | `M6CP3.HardRailCrossRegionBindingDoesNotCompareGlobalSheetLabels` | — |
| control | `selector:217` | `SurfaceCellTransitionQuotient.ExactHardRailCounterpartsStitchAcrossTopologyRegions` | — |
| control | `TB18 A#14` | `SurfaceCellAuthorityContractCutover.ProducedOpenRailInteriorVertexEndpointRejectsForgedTags` | — |
| control | `selector:443` | `M5CP3.ProducedTorusPublishesTwoCanonicalPeriodicRelationsAndOwnedEdges` | — |
| control | `focused30:7` | `M6CP1.SeamEndpointOccurrencesPublishCompleteCornerWedgeSheetAuthority` | — |

#### Ledger columns added to TB22's

- `fixture`, `path` (from the table); `a5_failures` (count of failure lines carrying an A5 isolation code);
- `site_raw`: every `site=` occurrence, untruncated, in output order. The value ends at whitespace or at `;terminalStage=`;
- parsed `label` (one of `side-step`, `side-collinear`, `wedge-edge`, `wedge-fan`, `relation-collinear-seam`), `region`, `seam`, `cert` (side sites) or `certs` plus every `certN=…:<clause>` (relation site).

#### Predictions (frozen before runtime)

- **P1 site coverage:** every row whose output carries an A5 isolation code (`…IsolationSeamEquivalenceAuthority:a5-side` or `:a5-wedge`; `A5:OccurrenceMismatchedIsolationEvidence` or `A5:OccurrenceMissingIsolationEvidence`) shows `site=` with one of the five labels, and no clause is `valid`. `a5-side` pairs only with `side-step`, `side-collinear` or `relation-collinear-seam`; `a5-wedge` only with `wedge-edge` or `wedge-fan`.
- **P2 within-fixture agreement:** the W rows (`focused30:20`, `selector:446`, `focused30:24`) name one label, region and seam; the T rows (`focused30:25/26/27/28`, `selector:444/448`) name one label, region and seam. A disagreement is reported, not reconciled. W and T may differ.
- **P3 `focused30:24`:** exactly one A5 failure, carrying the W site. Two or more are reported in `verify` order (hard-rail, split-isolation, witness).
- **P4 F rows:** both pass `atlas-binding` (no `InvalidSourceAuthority` at the atlas). Any failure is a later site, expected to be the W site.
- **P5 controls:** all five GREEN, with no `site=` in their output.

#### Falsifiers and stops

- An isolation code without `site=`, a `valid` clause, or a label that contradicts its `a5-side`/`a5-wedge` suffix: instrumentation or classifier gap. Review stop, not a result.
- Any control RED: Review stop.
- Package or source mismatch, `selected≠1`, a skip, a timeout or a runtime-flag mismatch: non-acceptance, classified exactly.

#### Routing for TB23-REV (pre-registered, not a verdict)

- `relation-collinear-seam` with `region`, `collinear`, `first-face`, `second-face` or `same-sheet`: A4 certificate disagrees with A5 occurrence authority (H-ISO-2).
- `relation-collinear-seam` with `first-side`, `second-side`, `same-side` or `ambiguous`: the RP reject is a candidate for over-strictness on a legitimate periodic pairing (H-ISO-1).
- `side-step`, `side-collinear`, `wedge-edge` or `wedge-fan`: side-span or wedge crossing (H-ISO-3); `cert=none` against a present certificate separates a missing certificate from a disagreeing one.

#### Deliverable

`Architecture_M6_CP3_TB23_Torus_A5_Site_Harvest_Report_20261021.md`, at most 40 lines: run, result artifact and ZIP SHA-256, harness SHA-256, integrity counts; one line per row (key, fixture, path, verdict, label, region, seam, cert or clauses); P1–P5 marked as observed. No root-cause verdict; that belongs to TB23-REV. **After TB23:** mandatory `M6-CP3-TB23-RP01-TORUS-A5-SITE-HARVEST-REV`; DEFN-ISO only as that Review assigns it.

## `Architecture_M6_CP3_TB24_Torus_A5_Seam_Face_Harvest_Review_Decision_20261021.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_TB24_Torus_A5_Seam_Face_Harvest_Review_Decision_20261021.md`; moved verbatim.

### RA-123 — TB24 seam-face harvest review (2026-10-21)

**Turn:** `M6-CP3-TB24-RP01-TORUS-A5-SEAM-FACE-HARVEST-REV`. **Verdict:** TB24 accepted as diagnostic evidence. The report's "consistent with B-fan" reading is **amended**: the site fits neither pre-registered branch. The owner is the A2 corner representative, which is chosen per node, not per occurrence (the RA-72.4 defect class). **No code is authorized.** DEFN-ISO is split into a census (A) and a contract (B).

#### RA-123.1 Harvest verified independently

- Artifact `12364838156` (run 39641426480, head `840eccf1b`): the provider digest equals the local ZIP SHA-256 `dcf42df9…220d3`; expires 2026-10-28T17:12:14Z.
- `SHA256SUMS`: **14/14** OK (the report says 13; corrected here). Each raw log has exactly one `[ RUN ]` and no `SKIPPED`, and its SHA-256 equals the ledger. Rows 1–3 each carry one site, identical across the three; rows 4–9 carry none. `execution-boundary.txt`: no compile, relink or benchmarks; postflight true; runtime links `libgmpxx`/`libgmp`.
- The harness renders the TB23 harness under a pinned digest and drops TB23's root-manifest pin; the CB23 ZIP SHA-256 pin covers that manifest. Accepted.
- TB24 yielded with its documentation sync pending. This Review performs that sync, and TB24 counts as executed.

#### RA-123.2 P1 and P2 held

All three A5 rows (W/P, T/P, T/D) emit one byte-identical site: the TB23 prefix plus
`;sel=121/0,121/0;support=vertex,vertex;wedge=120/0+121/0,97/2;spanOnly0=forward`. The guard `selector:447` and all five controls PASS without a site.

#### RA-123.3 Decoded

- `fixture_probe --fixture torus`: vertex 61's fan in cyclic order is 142, 119, 118, 97, 120, 121; edge 60–61 has only rows 97 and 120; 121 ∉ fan(60). Both occurrences are therefore **the same grid node at vertex 61**.
- Occurrence (0,1) has wedge `120/0+121/0`, and its representative `121/0` lies **inside** that wedge, on its span's sheet.
- Occurrence (1,0) has wedge `97/2`, and its representative `121/0` lies **outside** that wedge, on the other sheet.
- `spanOnly0=forward`: without the face clauses, the side authority yields one forward certificate. That authority is `certified_seam_wedge_side` (RP:3855–3875), which already requires the span binding to be in the occurrence's wedge with the certified sheet. The face clauses (RP:3891–3892) are the only rejecting clauses.
- The representative is per node. The tracer copies one node point into every incident cell's corner (SCT:13404–13405) and sets that corner's `branchRotation`/`sourceChart` from the point's face (SCT:13410–13422). RP takes `selectedFace` from the same point (RP:4448–4458). This is RA-72.4's finding: one `SurfaceTracePoint::face` cannot be the authoritative face of every occurrence at a node.
- **Open premise:** 121 is the fan's *maximum* row, whereas RA-72.6's minimum-admissible-row rule predicts 97. How this node's face was chosen is unexplained.

#### RA-123.4 Branch adjudication

Not B-across: the support is a vertex and `sel` ≠ 97/2. Not B-fan either: B-fan presumes each representative lies on its own occurrence's side, and occurrence (1,0) contradicts that. RA-121.6 routed on the first `sel` only. That under-specification was this Reviewer's; the report followed it faithfully and is not charged. Classification: **B-node**, a shared per-node representative used as per-occurrence chart authority.

#### RA-123.5 Relaxing the face clauses is inadmissible

A6 (RP:5832–5877) requires gauge face = `selectedFace`, strips the face gauge from the corner lattice, and compares the result with the certificate's forward or reverse turn. That comparison presumes each occurrence's chart lies on its span's sheet, and the A5 face clauses are what guarantee it. For occurrence (1,0) the stripped value would be in sheet 0's frame but compared with a sheet 0→2 turn. Relaxing the clauses therefore either moves the reject to A6 (`RelationCertificateConflict`; RA-72.5: relocation is not repair) or admits a false pass when the turns coincide. B-fan's remedy is withdrawn. Requiring "representative ∈ own wedge, on the span's sheet" is sound, but alone it recovers nothing: it accepts (0,1) and still rejects (1,0).

#### RA-123.6 Owner and unestablished premises

- **Owner:** A2 corner placement, which produces the occurrence representative and its lattice.
- **Enforcers known so far:**
  - A5: RP:3891–3892, the endpoint face gauge (RP:4669–4684) and hard-rail route endpoint attachments (RP:5051–5052);
  - A6: RP:5832–5877.

  A representative change also reaches hard-rail endpoints (controls `selector:217`, TB18 A#14).
- **Admissible shape (RA-72.4):** keep one canonical geometric node and give each occurrence a representative inside its own wedge.
- **Unestablished premises:**
  - (a) one representative per occurrence serves every consumer; a vertex wedge can span several faces (120 and 121) while each relation needs its span face;
  - (b) re-expressing the lattice at another face is exact from published witnesses. The corner `branchRotation` is the frame's per-face value (SCT:13419–13420), and the face-gauge table comes from that same frame (SCT:13579 → 13191; local path SCT:18434). If so, the stripped turn is identity by construction, and A6's seam-turn comparison must be re-derived, not assumed.
- **RA-78.10:** enumerate the enforcers before designing the rule. DEFN-ISO is therefore split into A (census) and B (contract).

#### RA-123.7 Successor `M6-CP3-DEFN-ISO-A-RP01-SEAM-NODE-REPRESENTATIVE-CENSUS`

Documents only: no `src`/`include`/`tests`/selector/workflow change, no compile, no runtime. Deliverable: `Architecture_M6_CP3_DEFN_ISO_A_Seam_Node_Representative_Census_20261021.md` (at most 80 lines). Anchor every answer to lines at HEAD (`src` identical to `e859175333`) and print the search commands verbatim.

1. **Enforcers:** every read of `placement.selectedFace`, `placement.lattice` (`branchRotation`, `sourceChart`), `cornerWedgeBindings` and the endpoint face gauges in `src/`, each with the frame it assumes (face, sheet or region).
2. **Frame semantics:**
   - which writer fills `sourceFaceBranchRotations` on the torus path (SCT:13579/13191 or SCT:18037/18434), and whether the corner `branchRotation` equals the gauge at the node face by construction;
   - what A6's stripped turn (RP:5859–5877) computes for two same-sheet occurrences and for two occurrences on the two certified sides;
   - whether TB24's relation could satisfy `seam.forward()` if (1,0)'s representative were `97/2`.
3. **Sufficiency:** for each consumer kind (seam and non-seam `OrdinaryFront`, hard-rail endpoint, periodic), the face the representative must equal, and whether one wedge face can serve them all or the gauge must be per (occurrence, side).
4. **Node face rule:** the rule that put vertex 61's node on row 121, set against RA-72.6's minimum-row prediction of 97.
5. **Reach:** which of the ten A5-ISO rows share this relation shape, and which of the five controls read a field that a representative change would touch.

**Non-goals:**
- no contract, rule or repair;
- no minimum-face rule (RA-79.4);
- no new producer certificate (RA-78.4);
- no clause relaxation.

**STOP:** if a question cannot be answered statically, say so and name the compile-only, rejection-only probe that would answer it. Do not guess.

#### RA-123.8 Sequence and accounting

- **Sequence:** TB24-REV (this) → **DEFN-ISO-A** → DEFN-ISO-A-REV → DEFN-ISO-B (contract: per-occurrence representative, lattice re-expression, non-weakening, falsifiers) → DEFN-ISO-B-REV → corrective CB → CB-REV → TB → TB-REV → DEFN-M1 → corrective CB/TB → DEFN-T1 → fixture debt → census → RP-01 Review.
- **Accounting (unchanged):** stable 66/17/49, debt 1, CP2 491/491; R3 403/497 rejected; TB21 449/497 candidate; selector 497 frozen. `RP-01` open, `RP-02` UNREACHED, Gate C suspended.

| Duty | Answer |
|---|---|
| Decisive claims re-derived | ZIP digest; 14/14 manifest; 9 raw logs (one RUN, no skip, hash = ledger); site; fans and edge via `fixture_probe`; RP/SCT anchors above |
| Non-vacuity | The fields were emitted on three distinct identities; guard and controls selected and passed |
| Obligations | RA-121.4/121.6 and RA-122 discharged; RA-72.4 reopened for seam vertices; premises (a) and (b) carried to DEFN-ISO-A |
| Durable docs | Handoff, TODO, tracker, CHANGELOG, ORIENTATION, ROADMAP, Frozen Definitions index |
| Boundary | Review-only; no source, test, selector, workflow or runtime change |

## `Architecture_M6_CP3_CB27A_Wedge_Membership_Witness_Design_Review_Decision_20261022.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_CB27A_Wedge_Membership_Witness_Design_Review_Decision_20261022.md`; moved verbatim.

### RA-135 — CB27A design block resolved: isolate wedge membership by withdrawing a real binding from the multi-binding endpoint (2026-10-22)

**Turn:** `M6-CP3-CB27A-RP01-A7-WEDGE-MEMBERSHIP-DESIGN-REV`. **Input:** CB27A `BLOCKED` (`45d9da85a`); CB27-REV (`Architecture_M6_CP3_CB27_A7_Certified_Seam_Negative_Oracles_Review_Decision_20261022.md`).

**Verdict:** the block is real only under CB27-REV's two self-imposed constraints:
- mutate the **first** endpoint;
- mutate the **span binding**.

Neither is required by the predicate under test. A discriminating, source-derived witness exists. **CB27A resumes** (test-only, TQ only) with the construction below. CB27-REV's other findings stand: three negatives discriminating, same-side not constructible from D7.

#### RA-135.1 Why CB27A could not succeed as specified

- `CornerWedgeFaceBinding` is `{face, sheet, chart}` with full equality (`RemeshPipeline.h:769–775`). `certified_seam_wedge_side` (RP:3855–3875) accepts a span binding only if all three of these hold:
  - its face is a certificate side face;
  - its sheet is that side's sheet;
  - the *whole triple* is in the occurrence's `cornerWedgeBindings`.
- **The D7 witness's first wedge has a single binding.** TB25's `cp3entry:3/5` sites show `wedge=0/0,2/1+3/1` with certificate `0/0->3/1`. The first span's binding `0/0` is the first wedge's only member. So:
  - a binding with the same face and sheet outside the first wedge must be synthetic (a fabricated chart);
  - removing `0/0` empties the wedge, so A7 rejects earlier at `cross-sheet:wedge` (RP:7496–7500).

  Both routes are invalid, so the STOP was correct for the first endpoint.

#### RA-135.2 The construction — withdraw, don't substitute

**The membership clause is symmetric.** Both endpoints pass through `certified_seam_wedge_side`. The **second** endpoint's wedge `{2/1, 3/1}` has two bindings on sheet 1, and its span binds the certificate's second face `3/1`.

**Tamper:** in `records.occurrences`, remove exactly the second span's `interiorBinding` (`3/1`, with its real chart) from the second occurrence's `cornerWedgeBindings`. Change nothing else: no span, relation, certificate, sheet list, transition or placement.

**Why only membership changes:**
- **Republishing passes.** `publish_records_for_validation` (RP:3708–3830) checks only cell, corner, occurrence and relation-endpoint structure, never wedge bindings.
- **A7's per-member checks still pass:**
  - support, point and component (RP:7423–7490) read `point`/`support`, not bindings;
  - the bound-sheet set `{1}` still equals `cornerWedgeSheets` `{1}` (RP:7496–7500);
  - a single-sheet wedge is connected (RP:7505–7535);
  - `charts` only feeds the emitted vertex (RP:7491, 7686).
- **In `certified_seam_direction`:**
  - the shared-node triple is unchanged, so the face clauses stay exempt;
  - collinear edge, region and distinct sheets are unchanged;
  - first side = First, membership intact;
  - second binding face `3` = `secondFace`, sheet `1` = `secondSheet`, so it classifies as Second, opposite to the first;
  - **only** `std::find(... cornerWedgeBindings ...)` fails → `nullopt`.
- **B4 is unaffected.** The relation evidence still holds the certificate transition. So with the membership clause deleted, the direction is `Forward`, B4 passes, and A7 **accepts**. That is the counterfactual CB27-REV requires, and it holds without touching production code.

**Expected results:**
- **A6** on the tampered A5: `InvalidIsolationEvidence` (RP:5893–5898). No earlier A6 check reads wedge bindings (RP:5740–5890).
- **A7** with the original A6 product: `UncertifiedCrossSheetBinding`, site `cross-sheet:seam-direction`, with locus occurrence `relation.id.first` (A7's `fail(…, edge.first, …)` at the certified branch).

#### RA-135.3 Binding in-test preconditions (the counterfactual, made checkable)

Before the tamper:
- **(P1)** The chosen endpoint's span binding is in its wedge.
- **(P2)** The wedge has at least two bindings, and another binding has the same sheet.

After the tamper:
- **(P3)** The binding is absent from that wedge, and the wedge's sheet set equals `cornerWedgeSheets` and is unchanged.
- **(P4)** `support`, `placement.selectedFace` and `placement.lattice.latticeCoordinate` are equal across both endpoints.
- **(P5)** Classified by face and sheet only, with a test-local function that does not check membership, the endpoint sides are opposite (First/Second).
- **(P6)** The relation evidence contains `{certificate.region(), certificate.seam(), sheets}` in either orientation.

Endpoint choice and locus:
- **Endpoint choice is deterministic:** the first endpoint if P1–P2 hold for it, otherwise the second. If neither qualifies, STOP and record the endpoint wedge contents.
- **Locus:** A7's failure `occurrence` equals `relation.id.first`, so the rejection belongs to the tested relation and not to another relation of the tampered occurrence.

The helper `check_d7_certified_seam_negative` may gain an **optional** expected-locus argument (default: unchecked), so the other three negatives stay byte-identical in behaviour.

#### RA-135.4 Scope of the resumed CB27A

- **Replace** `CertifiedSeamRejectsSpanBindingOutsideEndpointWedge` (TQ:4266–4286) with `CertifiedSeamRejectsSpanBindingWithdrawnFromEndpointWedge`, implementing RA-135.2–135.3. The old test rejects at membership and would also reject at same-side, so it does not discriminate either predicate.
- **Preserve:** the unrelated-seam, no-certificate and lattice negatives; the D3/D7 positives; the same-side comment, updated to cite RA-135.1.
- **Limits:** TQ only, no production or other-file change. Compile the eight targets with GMP/GMPXX, `runtimeExecution=false`. Record `Architecture_M6_CP3_CB27A_Wedge_Membership_Oracle_Code_Build_Record_20261022.md` (at most 30 lines).

**STOP and return to Review if:**
- neither endpoint satisfies P1–P2;
- any precondition fails at compile-time reasoning;
- a production change would be needed;
- an assertion would have to be weakened.

#### RA-135.5 Sequence and accounting

- **Sequence:** design review (this) → **CB27A (resumed)** → CB27A-REV → CB28 (RA-134.5 diagnostic messages) → CB28-REV → TB29 → TB29-REV → DEFN-M1 → DEFN-M1-REV → corrective CB/TB → DEFN-T1 → fixture debt → census → RP-01 Review.
  - TB29 runs CB27/CB27A's four negatives, D3/D7, the three A7 guards, the 21 silent rows and the four wrong-code rows.
  - `DEFN-SEAM-NZ` and the Periodic follow-up each wait for a witness. `DIAG-RETAIN` is scheduled clear of RP-01 turns.
- **Accounting (unchanged):** stable 66/17/49, debt 1, CP2 491/491; R3 403/497 rejected; TB28 462/497 candidate; selector 497 frozen. `RP-01` open, `RP-02` UNREACHED, Gate C suspended.

| Duty | Answer |
|---|---|
| Decisive claims re-derived | Binding identity (header 769–775); side and membership logic (RP:3855–3934); republish validation scope (RP:3708–3830); A7 per-member gates and `charts` use (RP:7423–7535, 7686); A6 pre-direction checks (RP:5740–5898); D7 wedge contents (TB25 sites); helper signature (TQ:4065–4141) |
| Non-vacuity | A one-binding difference between the accepted positive and the rejected tamper; P1–P6 make the only failing clause checkable in-test |
| Obligations | CB27-REV's fourth-oracle obligation now has a valid witness design; RA-134.5 CB28 still queued |
| Durable docs | Handoff, TODO, tracker, CHANGELOG, ORIENTATION, Frozen Definitions index |
| Boundary | Review-only; no source, test, selector, workflow or runtime change |

## `Architecture_M6_CP3_CB27_A7_Certified_Seam_Negative_Oracles_Review_Decision_20261022.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_CB27_A7_Certified_Seam_Negative_Oracles_Review_Decision_20261022.md`; moved verbatim.

### CB27-REV — independent A7 certified-seam negative-oracle review (2026-10-22)

**Canonical turn:** `M6-CP3-CB27-RP01-A7-CERTIFIED-SEAM-NEGATIVE-ORACLES-REV`.

**Decision: REJECT full CB27 negative-oracle adequacy.** Three negatives are discriminating under static source reasoning, but the outside-wedge negative can pass with the exact wedge-membership requirement removed. This is a test-oracle defect, **not** evidence of a production-code regression. Runtime execution is deferred to an authorized TB turn; none occurred in this Review. Same-side omission is conditionally justified for the present D7 producer witness.

#### Exact evidence and independent derivation

- Exact reviewed semantic source: `175c70e44d2c162d72812c842149f30c53c1fa25`; CB27 changed only `tests/SurfaceCellTransitionQuotientTests.cpp` relative to its pre-CB27 semantic source; neither selector nor product/fixture/build code was changed by CB27.
- Compile run [39815137854](https://github.com/akashskypatel/Directional/actions/runs/39815137854): compile job successful, test/benchmark skipped. Artifact `12443015113`, externally reported and independently recomputed SHA-256 `b1e7cfedc8546c8559592bb8aa6c902c00a47a488d441510ebfd89403172b0de`. Package file manifest **28/28** verified; source archive SHA-256 `ed7ef40b3298333beda991c521bf601b4f2a79fb529cf69e28603f6d7d01a6c8`; packaged source identity matches. Preflight/build exit codes zero, eight targets recorded, GMPXX/GMP verified in linker evidence; `runtimeExecution=false` and clean package source status. These attest **compilation only**.
- Original A6 selected forest is saved and reused for A7 invocation in TQ `check_d7_certified_seam_negative` (TQ:4065–4154). The unaltered producer-positive A5/A6/A7 witness must first succeed; a tampered A5 is independently republished and A6's expected outcome is asserted, then A7 receives tampered A5 with original A6. This correctly distinguishes A6's earlier guards from the A7 decision *if* the tamper isolates that decision.
- **Unrelated-seam** (TQ:4156–4194): retains at least one sheet-set connecting transition while changing all relation evidence transitions away from `certificate.seam()`. The A7 check at RP:7602–7618 requires the certificate's exact seam. A weakened any-connecting-transition check would accept. Statics support non-vacuity, not runtime reachability.
- **No-certificate** (TQ:4196–4238): removes certificate and three relation transition lists, independently requires A6 rejection and demands `cross-sheet:no-certificate` in A7 (RP:7622–7649). Statics support non-vacuity, not runtime reachability.
- **Lattice-coordinate** (TQ:4240–4264): ensures identical endpoint support, selected face and coordinate before mutation, then changes only `latticeCoordinate.x`. Shared-node identity at RP:3878–3884 requires all three equal; the A7 direction at RP:7587–7594 then rejects. Statics support the intended guard, but only TB can establish no earlier rejection masks it.
- **Outside-wedge — NOT A VALID WEDGE-MEMBERSHIP ORACLE** (TQ:4266–4286): copies `secondEndpointSpan->interiorBinding` *as a whole* into the first span. The first binding then equals the second binding. The preconditions establish that the substitute belongs to a certificate face but not to the first wedge; they do **not** preserve opposite seam sides. RP:3855–3875 checks membership, while RP:3912–3925 independently demands opposite `CertifiedSeamSide` values. **Deleting the `std::find(occurrence.cornerWedgeBindings, binding)` membership check still leaves both sides equal and the function returning `nullopt`, so A7 still returns `cross-sheet:seam-direction`.** The test cannot distinguish a correct wedge guard from a weakened one. A superficial expected-code/site match must not be called verification.
- **Same-side omission:** D7 has disjoint endpoint wedge-sheet sets and a certificate with distinct first/second sheets; putting both ends on one certificate side while preserving both wedge memberships is not realizable with the D7 witness. The side-opposition branch already rejects it. Omitting a contrived same-side test is warranted for this witness; the distinct outside-wedge guard remains unproved.

#### Bounded successor — `M6-CP3-CB27A-RP01-A7-WEDGE-MEMBERSHIP-ORACLE-CORRECTION`

**Type:** Code + Build, **test-only**. Owner: `tests/SurfaceCellTransitionQuotientTests.cpp` only; leave production code, other tests, selectors, benchmark fixtures, CI workflows and existing D3/D7 controls unchanged. **Stop** instead of widening scope if the following mutation cannot be produced from a valid source-produced D7 witness.

1. Correct the outside-wedge mutation to preserve first-span certificate face **and sheet**, the opposite-side relation to the untouched second span, and every non-membership precondition; change only the binding identity excluded from the first occurrence's `cornerWedgeBindings`. Do not assume a synthetic chart or malformed source binding is A5-publishable.
2. Assert (a) original/substituted side are identical, (b) side-opposition still holds, (c) substitute is absent from the first wedge and present on a certificate side, (d) republished A5 is structurally valid, and (e) A7 with original A6 rejects specifically due to the tested membership condition. Provide independently checkable counterfactual evidence that **removing just membership** would make the constructed tamper admissible, without modifying production code or weakening tests. If the witness cannot isolate this condition, record a precise unfulfilled oracle obligation and request a new witnessed design in a separate authorized definition turn; do not fake coverage.
3. Preserve the unrelated-seam, no-certificate and lattice negatives unchanged. Compile all eight established targets with GMP/GMPXX using the durable compile workflow; `runtimeExecution=false`. No runtime test/benchmark in CB.
4. Independent CB27A-REV must inspect source, non-vacuity and compiled artifact before CB28 is authorized. CB28 message-only diagnostics and TB29 remain **conditional, not current**.

**Falsifiers:** an unchanged pass under removal of the membership condition; same-side/sheet mismatch independent of wedge membership; republished A5 rejected before A7; A7 rejection from an unrelated earlier guard; compiler or GMP/GMPXX failure; edits to unapproved paths or changing test assertions to obtain green. **STOP**, preserve evidence, and do not promote to CB28 or TB29.

#### Project accounting and carried obligations

Stable: **66 events / 17 categories / 49 recurrences**, produced-witness debt **1**, accepted CP2 **491/491**; frozen CP3 selector 497, TB28 **462/497 candidate only**, not promoted. `RP-01` OPEN, `RP-02` UNREACHED, Gate C suspended. RA-134.4 three additional preconditions are statically present. RA-132.6 periodic negative is still deferred under RA-130.7 pending a valid source-produced periodic witness. RA-134.5 CB28 and TB29 stay queued behind corrected independent oracle review. This review creates no new stable regression event. Existing A7 coverage defect is an unpromoted test-authority obligation.

#### Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | n/a — CB27 Review adds/accepts no selector; frozen 497 and accepted CP2 491/491 retained; source-side selector files unchanged by CB27 |
| Decisive claims independently re-derived | Exact packaged SHA-256, 28/28 manifest, source/build boundary and actual TQ/RP predicate/control-flow inspection; the membership-deletion counterexample proved statically |
| Non-vacuity checked | Three guarded negatives have targeted static discrimination; outside-wedge case **fails** due to independent same-side rejection |
| Prior obligations discharged/carried | RA-134.4 three preconditions present; RA-132.6 four negatives still require adequate fourth witness; same-side omission justified for D7 only; RA-130.7 periodic witness carried; RA-134.5 CB28 pending |
| Stable accounting | 66/17/49, debt 1, CP2 491/491 accepted, TB28 462/497 candidate, frozen selector 497 |
| New candidates/obligations recorded | CB27A wedge-membership negative repair; no stable production regression |
| ORIENTATION currency line | Updated to CB27-REV and CB27A as next |
| ORIENTATION §3 / §4 / §7 / §8 | §3 and §7 adjusted; §4 unchanged (no witness changes); §8 existing vacuous-oracle pattern applies |
| CHANGELOG | Review rejection and successor recorded |
| ROADMAP | No checkpoint status change; no update required |
| Selector manifest | n/a — no selector mutation or acceptance |
| LESSONS | Existing independent non-vacuity / vacuous witness lesson applies; no novel lesson |
| Consolidation under CLEAN_UP_POLICY | No historical document folded without complete retained index; exact compile report and TB28 evidence remain current authority |
| Successor frozen | `M6-CP3-CB27A-RP01-A7-WEDGE-MEMBERSHIP-ORACLE-CORRECTION`; above falsifiers and STOP rules |
| Turn boundary held | Review-only; no runtime, product/test/fixture/selector/build mutation |
| review_check.py boundary | Git metadata absent from packaged archive, so full Git-based command cannot be honestly certified; exact package, GitHub branch comparison and changed-path evidence used as bounded alternative |
| `STATUS` lifecycle maintained | Final beacon published separately as last repository action |
| Pushed to origin, branch in sync | Verify after documentation patch application against GitHub head; local archive has no .git, so `git status -sb` cannot be truthfully claimed |

## `Architecture_M6_CP3_CB28_Factory_Error_Diagnostics_Review_Decision_20261022.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_CB28_Factory_Error_Diagnostics_Review_Decision_20261022.md`; moved verbatim.

### RA-136 — CB28 review: diagnostics accepted for 18 of 21 silent REDs; three M1/A5 asserts missed; CB28A before TB29 (2026-10-22)

**Turn:** `M6-CP3-CB28-RP01-FACTORY-ERROR-DIAGNOSTICS-REV`.

**Verdict:** CB28 (`19aeb3e60`, tests only, +126/−7) is **accepted as message-only and correct** for what it covers. The diff adds message text only. No assertion, expected value, control flow, fixture or product code changes.
- **Coverage is incomplete:** 3 of the 21 silent RED rows in RA-134.2 are still silent.
- **Two of those three are the M1 precedence tests** themselves, the rows DEFN-M1 most needs measured.
- **A narrow CB28A** adds the three messages before TB29. No other rework.

#### RA-136.1 Verified

- **Package:** `12460974720`. The provider digest equals the recorded ZIP SHA-256 `8f5c9a19…3d6b`; it expires 2026-10-29T21:59:16Z. The record reports 28/28 entries, GMP/GMPXX and `runtimeExecution=false`.
- **Factory formatter:** `describe_phase_front_product_error` prints the code (as an integer), `sourceAuthoritySite`, `edge`, `event`, `cell`, `region` and the `periodicRelation` carriers. Each file has its own anonymous-namespace copy, which is acceptable for separate translation units.
- **Atlas formatter:** `describe_field_atlas_build_error` prints `field_atlas_build_error_code_name`, the edge/face/vertex/region locus and the cycle-basis reason.
- **Helpers covered:**
  - direct periodic-owner (TQ:400): `selector:220, 221, 296, 302, 304, 439`;
  - publish draft (TQ:2544): `focused30:3`;
  - rebuild with edges (SP10:6542): `selector:139, 140, 142`;
  - periodic-route atlas (SP10:4401): `selector:189–195`;
  - `cp3entry:4` at its assert (TQ:3948);
  - `expect_phase_front_product_error`, which also helps `selector:211/219`.
- **Safety:** every `std::get` sits on a path where the variant is known to hold the error.
- **Off-target but harmless:** a message on `ASSERT_NE(a5)` in the passing test `M6CP1.A7ProjectsCompleteClassLineageAndSelectedRelationValues`. Keep it.
- **CB27A** (`f021e8f7b`, accepted by its review) was spot-checked against RA-135: P1–P6, the face/sheet-only side check, A6 `InvalidIsolationEvidence`, and the locus flag are present.

#### RA-136.2 Missed: three silent rows

| Row | Test | Assert (HEAD) | Needed message |
|---|---|---|---|
| `focused30:12` | `M6CP1.RelationPlacementTransportIsCoordinateRigidAndFaceGaugeInvariant` | `ASSERT_NE(relabelledA5, nullptr)` TQ:5525 | `a5_rejection_message(relabelledA5Construction)` |
| `focused30:22` | `M6CP1.A5OwnsIsolationAndHardRailRouteValidationWithFrozenNames` | `ASSERT_NE(front, nullptr)` TQ:6309 | factory error of `construction` |
| `focused30:23` | `M6CP1.A5ValidationPrecedencePreservesHardRailAuthorityBeforeTransport` | `ASSERT_NE(front, nullptr)` TQ:6350 | factory error of `construction` |

- **Cause, owned by this Review line:** RA-134.5 cited TB28-era line numbers (source `e3d60337e`) without test names, and CB27/CB27A then inserted about 370 lines. The CB28 record flagged the drift honestly but did not resolve it by test name.
- **Why it matters:** `focused30:22/23` are the frozen-precedence tests on which M1 is defined (RA-105.3). Without their factory clause, DEFN-M1 would again rest on static attribution for its defining rows.
- **Durable rule:** a turn spec names targets **by test identity first**. Line numbers are advisory only.

#### RA-136.3 Successor `M6-CP3-CB28A-RP01-M1-PRECEDENCE-ASSERT-DIAGNOSTICS` (Code + Build, test-only, compile only)

- **File:** `tests/SurfaceCellTransitionQuotientTests.cpp` only.
- **Change:** add message text to exactly the three asserts in RA-136.2, located **by test name**:
  - `focused30:12`: stream `a5_rejection_message(relabelledA5Construction)`;
  - `focused30:22/23`: stream `describe_phase_front_product_error` of the error alternative, using the guarded `get_if` pattern from TQ:3948.
- **Limits:** no other change.
- **Build:** compile the eight targets with GMP/GMPXX, `runtimeExecution=false`. Record `Architecture_M6_CP3_CB28A_M1_Precedence_Assert_Diagnostics_Code_Build_Record_20261022.md` (at most 20 lines).
- **STOP** on a compile error or any need to touch another assert or file.

#### RA-136.4 TB29 plan (issued at CB28A-REV)

- **What runs:** a targeted, artifact-only harness (new, like TB27's) on the CB28A package, with 44 identities:
  - the four A7 negatives: unrelated seam, no certificate, lattice, withdrawn binding;
  - D3/D7 (`cp3entry:3/5`);
  - the three A7 site guards;
  - **all 35 TB28 RED rows.**
- **Report:**
  - for each RED, its typed first-failure reason;
  - for the four negatives, PASS with the expected site;
  - an attribution table by factory clause, atlas code and A5 code.
- **Why all 35, not 25:** the run is cheap, and it gives TB29-REV one complete classification set for DEFN-M1, DEFN-T1 and fixture debt.

#### RA-136.5 Sequence and accounting

- **Sequence:** CB28-REV (this) → **CB28A** → CB28A-REV → TB29 → TB29-REV → DEFN-M1 (scoped from measured clauses) → DEFN-M1-REV → corrective CB/TB → DEFN-T1 → fixture debt → census → RP-01 Review. `DEFN-SEAM-NZ` and the Periodic follow-up each wait for a witness. `DIAG-RETAIN` is scheduled clear of RP-01 turns.
- **Accounting (unchanged):** stable 66/17/49, debt 1, CP2 491/491; R3 403/497 rejected; TB28 462/497 candidate; selector 497 frozen. `RP-01` open, `RP-02` UNREACHED, Gate C suspended.

| Duty | Answer |
|---|---|
| Decisive claims re-derived | CB28 diff, line by line; package digest; helper-to-row mapping against the TB28 inventory; the three unmodified asserts located by test name; CB27A preconditions present |
| Non-vacuity | Message-only diff, with no assertion or control-flow change; coverage measured at 18/21 |
| Obligations | RA-134.5 discharged for 18 rows; 3 carried to CB28A; TB29 scope fixed |
| Durable docs | Handoff, TODO, tracker, CHANGELOG, ORIENTATION, Frozen Definitions index |
| Boundary | Review-only; no source, test, selector, workflow or runtime change |

## `Architecture_M6_CP3_DEFN_SEAM_A5_Shared_Node_Side_Authority_20261022.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_DEFN_SEAM_A5_Shared_Node_Side_Authority_20261022.md`; moved verbatim.

### DEFN-SEAM — A5 certified-seam shared-node side authority (2026-10-22)

**Turn:** `M6-CP3-DEFN-SEAM-RP01-A5-SHARED-NODE-SIDE-AUTHORITY` (definition only). **Review authority:** RA-126.4, RA-124.3 P1–P3; semantic source inspection: snapshot `7efc2ded291091e045b59c154dd6a00f64748fa6`. **Next:** mandatory independent `M6-CP3-DEFN-SEAM-RP01-A5-SHARED-NODE-SIDE-AUTHORITY-REV`; no code or runtime acceptance is authorized by this document.

#### 1. Amended A5 rule (RP:3855–3911)

`certified_seam_direction(firstOccurrence, secondOccurrence, firstSpan, secondSpan, certificate)` shall use the following decision, restricted to a certified collinear-seam `OrdinaryFront` relation:

1. Define `sharedNode` **only** when the canonical occurrences have equal `support` **and** equal `placement.selectedFace`. This is an occurrence-pair property, not geometric proximity, same source sheet, or a new source-vertex certificate. The producer copies one node into both ends of the shared front edge (RA-124.3 P1).
2. For `sharedNode`, do **not** require `firstSpan.interiorBinding.face == firstOccurrence.placement.selectedFace` or `secondSpan.interiorBinding.face == secondOccurrence.placement.selectedFace` (the existing RP:3891–3892 face-equality clauses). The per-node representative is not the authoritative **side** for a seam-spanning relation.
3. For **non-`sharedNode`** pairs, retain **both** existing face-equality clauses without relaxation.
4. In both branches, keep the existing shared seam/collinear-edge equality, region agreement with the certificate, distinct certified sheets, exact wedge-binding membership and typed sheet match in `certified_seam_wedge_side`, and strict opposite-side requirement. `First→Second` means `Forward`; `Second→First` means `Reverse`; any absent, `NotOnSeam`, same-side, invalid, or ambiguous direction rejects.
5. A4 is still the only source of certificate face orientation and `forward()`/`reverse()` transforms. No sheet label, face-row minimum, per-node representative, or local branch is allowed to invent orientation. A certificate must already exist and uniquely match: no certificate or two admissible certificates rejects.

**Scope precision:** this is a removal of two *redundant/incompatible per-node face-equalities* only for a pair that is already one shared node. It is **not** permission to remove any independent gauge-face guard, relabel a sheet, alter transport, fabricate a certificate, or admit arbitrary collinear spans. The shared-node equality must be checked on canonical identities; a coincident world-space position is insufficient.

#### 2. Enforcer/consumer impact and preserved downstream rules

| Source site | Impact of the proposed A5-only change |
|---|---|
| RP:4695, `seam_transport_certificate` | Uses `certified_seam_direction` to select exactly one matching certificate. Two admissible certificates still produce ambiguity/rejection; zero certificates do not silently fall back. |
| RP:5250–5262, `OrdinaryFront` A5 relation | The existing `MismatchedIsolationEvidence` rejection remains if a certified seam is present but no admissible uniquely selected direction/certificate is found. Shared-node spans on opposite certified sides may now pass this one gate. |
| RP:5293, diagnostic `certified_seam_direction` call | The `certs`/`passing` site evidence reflects the new predicate; no synthetic certificate, changed site identity, or acceptance assertion is authorized. |
| RP:5878, A6 quotient | Re-evaluates the same direction, then checks the selected certificate's `forward`/`reverse` turn against the independently gauge-stripped lattice turn. A6 and D3 remain **byte-semantically unchanged**. |

In particular, A6 RP:5869–5870 still requires `firstGauge.face == firstOccurrence.placement.selectedFace` and `secondGauge.face == secondOccurrence.placement.selectedFace`; both endpoint gauges and their provenance stay unchanged. A6 RP:5887–5905 must reject `strippedTurn != expectedTurn` as `RelationCertificateConflict` (frozen RA-30a.3/D3). The identity-turn observations in TB25 do not authorize admitting nonzero-turn seams. The `certified_seam_wedge_side` implementation is unchanged; the corrective CB may change **only** the two scoped comparisons inside `certified_seam_direction`, after Review.

#### 3. Non-weakening / independent negative cases

| Case | Required reject and responsible clause |
|---|---|
| Shared node, span's binding outside that occurrence's wedge | `certified_seam_wedge_side`: exact `cornerWedgeBindings` membership fails (or `NotOnSeam` if not a certified face); direction absent. |
| Shared node, spans both on same certified side | `certified_seam_direction`: neither opposite-side orientation branch matches. |
| Certificate has equal first/second sheets | `certified_seam_direction`: distinct-sheets guard; no admission, regardless of node equality. |
| Two certificates both direction-valid for this pair | `seam_transport_certificate`: second admissible candidate invalidates uniqueness (`nullopt`); A5 rejects. |
| Non-shared-node pair with either face equality failing | Original first/second span-to-selected-face clause remains required; A5 rejects. |
| Shared node, certificate's turn nonzero while both regional lattice turns remain equal | A5 may establish side, but A6's unchanged D3 `strippedTurn != expectedTurn` rejects `RelationCertificateConflict`; **no D3 bypass**. |

Additionally unchanged: wrong seam/region, missing canonical collinear edge, wrong certified sheet, non-wedge binding, missing gauge, or inconsistent gauge/selectedFace are rejections at their respective existing predicates.

#### 4. Corrective TB predictions, falsifiers, and boundary

- **Prediction P1:** all 12 reviewed A5-ISO identities — `focused30:6,20,24,25,26,27,28`; `selector:444,446,448` (including G4-B002); `cp3entry:3,5` — advance beyond their prior A5 `relation-collinear-seam` rejection. The first *subsequent* failure, if any, must be reported from runtime, not guessed to be green.
- **Falsifier F1:** any of these 12 still rejects at the same A5 face clause after the scoped change, or admits without valid opposite certified wedge sides. Report exact pair/certificate identity and revisit this contract in Review.
- **Prediction P2:** the TB25 guard (`selector:447`), the six TB25 PASS controls, and the TB21-PASS population of 449 remain unaffected. A later selector-497 census is required; no unexecuted PASS is claimed here.
- **Falsifier F2:** any previously passing control or accepted-prefix identity loses its result, any newly admitted pair violates source/sheet/uniqueness, or any A6 nonidentity discrepancy passes. Route to independent Review, not ad hoc guard weakening.
- **Unknowns:** production direct-quad success, the next first failure, and nonzero-turn seams are unmeasured. Nonzero-turn semantics belong to deferred `DEFN-SEAM-NZ` only after an actual witness.

**Prohibitions:** no changes in this DEFN turn to code, tests, fixtures, selectors, workflows, compilation, runtime, A2 representatives, A6/D3, gauges, minimum-face rules (RA-79.4), or producer-authored vertex-star certificates (RA-78.4/Gate C). Stable 66/17/49; debt 1; accepted CP2 491/491; candidate TB21 449/497 and frozen selector 497 remain unchanged.

## `Architecture_M6_CP3_DEFN_SEAM_A5_Shared_Node_Side_Authority_Review_Decision_20261022.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_DEFN_SEAM_A5_Shared_Node_Side_Authority_Review_Decision_20261022.md`; moved verbatim.

### RA-127 — DEFN-SEAM review: accepted with two binding amendments; CB25 authorized (2026-10-22)

**Turn:** `M6-CP3-DEFN-SEAM-RP01-A5-SHARED-NODE-SIDE-AUTHORITY-REV`.

**Verdict:** the contract `Architecture_M6_CP3_DEFN_SEAM_A5_Shared_Node_Side_Authority_20261022.md` is **accepted with amendments**.
- Its scope, its non-weakening table, the decision to leave A6/D3 unchanged and the deferral of nonzero-turn seams are correct.
- Its shared-node predicate is too weak, and its enforcer table misses a second copy of the clauses.
- Amendments A1–A4 are binding on CB25. CB25 is authorized: RP only, compile only.

#### RA-127.1 Verified

- RP is byte-identical to the CB24 source `dae267a82`, so every anchor in the contract holds at HEAD.
- **§1** keeps every clause except the two face equalities, only for shared-node pairs. Direction still comes from `certified_seam_wedge_side` (wedge membership and certified sheet, RP:3855–3875), with opposite sides. Certificate uniqueness stays in `seam_transport_certificate` (RP:4695).
- **§2** is right that A6's source is untouched. Its gauge-face check (RP:5869–5870), the D3 check (RP:5887–5905) and the second evaluation of `certified_seam_direction` (RP:5878) all still apply.
  - **Correction:** "A6 byte-semantically unchanged" overstates it. Through the shared function, A6 stops rejecting shared-node pairs as `InvalidIsolationEvidence` (RP:5881–5885), and D3 then becomes their binding guard. That is the intended effect, but the contract must say so.
- **§3:** the non-weakening table covers every independent rejecting clause.
- **§4:** treating the next first failure as a measured outcome is correct.

#### RA-127.2 A1 — "equal support and equal selectedFace" does not identify a node

- **The problem.** `SourceEdgeSupport` holds only `edge` (`SourceSupport.h:23–26`), and a face-interior support only its face. For edge- or face-supported corners, two different points on the same edge or face with the same selected face satisfy the contract's `sharedNode`. That contradicts its own requirement that a shared node be a canonical identity, not geometry.
- **The fix.** The predicate must also require equal `placement.lattice.latticeCoordinate`, which is exact integers.
- **No effect on producer data.** In all three producers, node indices do not wrap (`v * columns + u`; SCT:13317, 15071, 17585). Each cell corner takes its coordinate from the same (u+du, v+dv) offsets as its node id (SCT:13424–13427 uniform, 15119–15121 annulus, 17752–17756 curved). So two cells sharing a node always agree on its coordinate.
- **No new authority.** A6 already rejects any OrdinaryFront pair whose lattice coordinates, scale or phase differ (RP:5748–5766). So A5 only stops admitting pairs that A6 would reject anyway.
- **Binding definition:** `sharedNode` ⇔ equal `support`, equal `placement.selectedFace`, and equal `placement.lattice.latticeCoordinate`.
- **Reading TB26.** After CB25, a `first-face`/`second-face` label on a site whose `support` and `sel` tokens are equal can only mean the lattice coordinates differ. That falsifies the producer argument above; route it to Review.

#### RA-127.3 A2 — the rejection-site classifier must mirror the amended rule

- **The problem.** The relation rejection site (RP:5303–5333) re-implements the face clauses on its own (`first-face`, `second-face`). Only its pass count calls `certified_seam_direction` (RP:5293).
- **The consequence.** If only the function changes, a shared-node pair rejected for another reason (same side, span outside the wedge) is mislabelled `first-face`. That breaks the mirror of `certified_seam_direction` accepted at RA-118.2, and future harvests would be misread.
- **The fix.** CB25 applies the same shared-node exemption to the classifier, in the same commit. This is diagnostic only.
- **Correction to §2:** at RP:5293, the pass count reflects the new predicate; the per-certificate clause labels follow it only once A2 is in.

#### RA-127.4 A3 — the decisive positive witnesses must be named

- `cp3entry:3` and `cp3entry:5` are the frozen D3 identities, `OrdinaryFrontIsolationSeamUsesCoordinateIdentityAndCertifiedSheetTransition` and `ProducedSeamCollinearOrdinaryFrontRequiresExactCrossSheetTransition` (TQ:3613, TQ:3977).
- Once A5 admits their shared-node seam relation, they are the **first exercise of A6's seam branch on producer-built relations**. `cp3entry:3` includes the D3 tamper: rotating the second endpoint's face gauge by a quarter turn must reject as `RelationCertificateConflict` (TQ:3652–3677).
- **TB26** must report, for these two rows:
  - whether the search helper now finds a certified reciprocal cross-sheet relation;
  - whether A6 admits the untampered relation, which needs stripped turn = identity = F;
  - whether it rejects the tampered one.

  A tamper that passes falsifies the contract (F2).

#### RA-127.4b A4 — test coverage of the new branch is owed

- The amended predicate needs direct negative tests before the RP-01 Review can accept the change:
  - a shared node with the span outside its wedge;
  - a shared node with both spans on the same side;
  - edge-supported corners on the same edge and face but with different lattice coordinates (the A1 case).
- These are test-only and belong in their own CB (CB26) after TB26. CB25 stays a source-only change.

#### RA-127.5 Successor `M6-CP3-CB25-RP01-A5-SHARED-NODE-SIDE-AUTHORITY` (Code + Build, compile only)

**Base:** HEAD (RP identical to `dae267a82`). Edit RP only:

1. In `certified_seam_direction` (RP:3880–3911), compute `sharedNode` per A1. When it holds, skip the two face-equality clauses (RP:3891–3892). Every other clause and the side logic are unchanged.
2. In the rejection-site classifier (RP:5303–5333), apply the same `sharedNode` exemption to the `first-face` and `second-face` labels (A2). Keep the existing site text format.
3. Share one helper between (1) and (2), so the rule exists once.
4. Write no other change, especially none to A6, A2, the header, TQ or other files. Lines at most 100 columns.
5. Compile the eight targets with GMP/GMPXX, `runtimeExecution=false`. Record `Architecture_M6_CP3_CB25_A5_Shared_Node_Side_Authority_Code_Build_Record_20261022.md` (at most 30 lines).

**STOP** on a compile error or any need to edit outside RP, or if the classifier cannot use the shared helper.

#### RA-127.6 Sequence and accounting

- **Sequence:** DEFN-SEAM-REV (this) → **CB25** → CB25-REV → TB26 (12 A5-ISO rows with the A3 reporting, guard `selector:447`, TB25 controls) → TB26-REV → CB26 (A4 negative tests, TQ only) → CB26-REV → TB27 (new tests plus a selector-497 census) → TB27-REV → DEFN-M1 → corrective CB/TB → DEFN-T1 → fixture debt → census → RP-01 Review. `DEFN-SEAM-NZ` waits for a nonzero-turn witness; `DIAG-RETAIN` is scheduled clear of RP-01 turns.
- **Accounting (unchanged):** stable 66/17/49, debt 1, CP2 491/491; R3 403/497 rejected; TB21 449/497 candidate; selector 497 frozen. `RP-01` open, `RP-02` UNREACHED, Gate C suspended.

| Duty | Answer |
|---|---|
| Decisive claims re-derived | RP anchors at HEAD; orientation mapping and uniqueness (RP:3880–3911, 4686–4702); support-identity types; producer node indexing and coordinates; classifier duplication; A6 lattice-equality check and direction-failure code; D3 identities and tamper |
| Non-vacuity | A3 names the first runtime exercise of A6's seam branch and its tamper falsifier |
| Obligations | RA-126.4 discharged; A1–A4 binding on CB25/TB26/CB26 |
| Durable docs | Handoff, TODO, tracker, CHANGELOG, ORIENTATION, ROADMAP, Frozen Definitions index |
| Boundary | Review-only; no source, test, selector, workflow or runtime change |

## `Architecture_M6_CP3_DEFN_SEAM_A7_Certified_Seam_Cross_Sheet_Authority_20261022.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_DEFN_SEAM_A7_Certified_Seam_Cross_Sheet_Authority_20261022.md`; moved verbatim.

### DEFN-SEAM-A7 — certified cross-sheet OrdinaryFront authority (2026-10-22)

**Turn:** `M6-CP3-DEFN-SEAM-A7-RP01-CERTIFIED-SEAM-CROSS-SHEET-AUTHORITY`.
**Boundary:** documents-only contract; no implementation, test, workflow or runtime change.
**Inspected source:** `575d10ef8e6efc6f20c24b1643b0620859a489a9` (snapshot 39737334509); `RP` = `src/pipeline/RemeshPipeline.cpp`, `TQ` = `tests/SurfaceCellTransitionQuotientTests.cpp`. RA-129.4 is the authority; RA-127 and RA-124.3 are carried without altering D3.

#### 1. Post-A5 consumer census (search-first audit)

Searched `cornerWedgeSheets`, `cornerWedgeIsolation`, `isolationTransitions`, `SideIsolationEvidence`, `isolationSeamTransportCertificate`, and `certified_seam_direction` across `src/`, `include/` and `tests/`. The decisions on the A5→A9 path are below; hashing, diagnostics, declarations and test inspection are not independent admission sites.

| Consumer and source | Actual predicate on a shared-node, disjoint-sheet, certified OrdinaryFront relation | Disposition |
|---|---|---|
| A5 side evidence, RP:4290–4449, 4699–4740, 5203–5267 | Collinear directed-side spans carry `interiorBinding` plus seam transition; `isolationEvidence` is the union of span transitions; canonical endpoint spans and the unique typed A4 seam certificate are published. | **PASS for TB26 witnesses**; A5 producer prerequisite, not an A6/A7 substitute. |
| A6 OrdinaryFront, RP:5760–5912 | No rail/periodic tag, identity transport, same lattice coordinate/scale/phase, typed reciprocal side isolation, forward/reverse seam span transitions, both selected-face gauges, matching region/seam, `certified_seam_direction`, D3 stripped turn equal to certified turn. | **PASS for the six TB26 `cp3entry:3/5` searches** (RA-129.2); mutations or nonzero turns may reject. No A6 amendment authorized. |
| A6 quotient construction, RP:6035–6095 | Preserve member wedge transitions as provenance after union; selected forest carries the accepted relation, not a new sheet-admission decision. | **PASS** on those witnesses; construction otherwise subject to existing validations. |
| A7 per member, RP:7410–7541 | Same source support and point; valid component and region; wedge-binding sheet set nonempty and equal cached `cornerWedgeSheets`; multi-sheet wedges must be connected *within their own wedge* by `cornerWedgeIsolation`. | **Independent conditional gate**; cannot be waived by a seam certificate. TB26 lacks an A7-site diagnostic to prove each individual predicate on all nine RED rows. |
| A7 forest, RP:7543–7603 | HardRail needs distinct regions/gauges; OrdinaryFront/Periodic need equal regions; with shared wedge sheet, pass. Otherwise both `relationCertified` and `occurrenceCertified` must connect the endpoint sheet sets. | **REJECT for disjoint-sheet seams**: `occurrenceCertified` is impossible; it consults only each endpoint's own wedge transitions. This is the A7 structural defect (RA-129.3). |
| A7 emitted geometry, RP:7641–7642 | Stores union of member sheets as `sourceIsolationSheets` only *after* admissibility; does not independently authorize a crossing. | **Not an admission gate**. |
| A8 verifier, RP:8231–8283 | `a5:wedge-bindings` rechecks support incidence, per-face sheet assignment and flattened bindings; `a5:wedge-isolation` rechecks source seam, edge incidence and exactly the two incident sheets. | **Independent conditional gate**; checks original A5 facts, not endpoint-relation crossing. Keep unchanged. |
| Downstream A8/A9 / other `src` consumers | Search found no further use of these five isolation-evidence symbols as a cross-sheet relation admission check after the sites listed above. | **No further seam-authorization consumer found** in inspected source. |

A5's wedge walk only appends transitions between its own bindings (RP:4540–4665). A disjoint second endpoint sheet therefore cannot be connected by the first occurrence's `cornerWedgeIsolation`, nor conversely. This does **not** imply the relation itself lacks reciprocal cross-seam side evidence.

#### 2. `relationCertified` is attainable — not a replacement for typed direction

RP:4290–4449 appends every collinear segment's seam transition into its directed side's `isolationEvidence`; RP:5203–5219 copies the two front sides into `firstSideIsolationEvidence` and `secondSideIsolationEvidence`, and RP:4970–4978 copies the first side into `equivalence.isolationTransitions`. A6's certified branch requires the forward transition in the first endpoint span and reverse transition in the second (RP:5840–5877). Each endpoint span belongs to the corresponding directed side (RP:4718–4740). Thus, for an unmodified A6-accepted seam relation, at least one relation evidence collection can connect the disjoint endpoint sheet sets: **`relationCertified` can be true**, unlike `occurrenceCertified`. This is a static producer/dataflow implication, **not a runtime assertion that A7 reached the particular predicate**; the A7 site suffix is needed to distinguish other gates.

#### 3. Normative A7 forest-edge rule (CB26 implementation contract)

1. Preserve HardRail, SingularityPort, same-region, same-sheet, and all per-member source-support, component, point, wedge-binding and wedge-connectivity checks exactly as presently enforced. Preserve the existing crossing predicate verbatim for **Periodic** and **OrdinaryFront without** `isolationSeamTransportCertificate`.
2. Only for **OrdinaryFront**, **disjoint** `firstSheets`/`secondSheets` and a present **typed** certificate: require both canonical `firstEndpointSpan` and `secondEndpointSpan`; evaluate `certified_seam_direction(first, second, firstSpan, secondSpan, certificate)` from RP:3889–3934 **once**, without choosing a side from labels, `selectedFace`, or a re-derived orientation.
3. Reject if no direction; otherwise bind Forward to `(certificate.firstFace(), certificate.firstSheet())` for `firstSpan` and `(certificate.secondFace(), certificate.secondSheet())` for `secondSpan`, or Reverse to the opposite ordering. Require each span's `interiorBinding` to be the selected typed face/sheet pair **and** its sheet to appear in its endpoint's certified wedge bindings. Do not require the entire wedge-sheet set to be a singleton. Keep `relationCertified` as an independent transition-evidence guard; it is attainable as shown in §2.
4. The seam-certified branch **replaces only** the impossible cross-endpoint `occurrenceCertified` demand; it does not transform a plain, invalid or Periodic relation into a seam. No inferred side from bare sheet labels; no global sheet equality; no change to A5, A6, the D3 gauge equation or their frozen predicates.

#### 4. Diagnostic-only change (CB26)

At RP:9276–9280, when `geometryError->code == UncertifiedCrossSheetBinding`, append `":" + geometryError->site` to `result.failure` (if nonempty), analogous to the existing `:support-point` handling. Keep code, typed site, stage and return unchanged. At TQ:2725–2814, the D3 fixture helper must record `A7:<GeometryEmbeddingFailureCode>:<site>` (or an equivalently unambiguous code/site pair) instead of `A7:rejected-certified-seam`. No assertion or evidence reduction; a change in diagnostic text alone is not success.

#### 5. Non-weakening / rejection matrix

| Case | Required rejection clause (source) |
|---|---|
| Disjoint sheets, no typed seam certificate | Existing `relationCertified && occurrenceCertified` rule (RP:7574–7603); no new path. |
| Certificate's selected-side sheet/face differs from endpoint span or wedge binding | `certified_seam_direction` / `certified_seam_wedge_side` (RP:3855–3934), then explicit §3 typed pair/binding equality; **reject**. |
| Noncollinear/missing spans, wrong seam, same-side mapping or invalid certificate direction | `certified_seam_direction` (RP:3889–3934); **reject**, no fallback. |
| Periodic cross-sheet with disjoint wedges | Original A7 transition rule unchanged (RP:7543–7603). |
| Wrong topology region | A7 region equality (RP:7558–7565) plus certificate region predicate (RP:3899–3914). |
| Per-member wedge cache mismatch, unconnected wedge or invalid source support | A7 wedge/source checks (RP:7370–7541) and A8 wedge verification (RP:8231–8283); never suppressed. |
| Nonreciprocal seam side transitions, wrong selected-face gauge or D3 gauge tamper | A6 reciprocal/span/gauge/stripped-turn clauses (RP:5840–5912), producing `RelationCertificateConflict` for the D3 tamper. |

#### 6. TB27 predictions and falsifiers (not executed here)

- Re-run exactly the TB26 18 selections, same code+site diagnostics. The eight rows with `UncertifiedCrossSheetBinding` (`focused30:6,20,25`; `selector:444,446,448`; `cp3entry:3,5`) **should pass the former A7 cross-sheet gate** when certified; this does **not** promise end-to-end PASS or invent the next first failure.
- `focused30:24` must expose its actual A7 error code and site; any non-cross-sheet first failure falsifies its proposed attribution to the §3 branch, not the independently proven impossibility of `occurrenceCertified` for disjoint sheets.
- The D3 helper in `cp3entry:3/5` should first produce a successful untampered A7 witness and reach the gauge tamper. A tampered certificate must be rejected at A6 as **`RelationCertificateConflict`**; a tamper that passes falsifies the D3 preservation guarantee. If untampered A7 still fails, report its exact code/site instead of asserting a tamper outcome.
- All TB26 controls (including `focused30:26–28`) must remain PASS; do not promote candidate 449/497 or modify stable 66/17/49, debt 1, or the frozen 497 selector. Any new error or later first failure is **measured**, not inferred from moving diagnostics.

**Disposition:** The requested consumer audit found no additional post-A5 seam gate requiring an A6 contract change, and `relationCertified` is statically attainable. DEFN can proceed to independent Review. CB26, TB27 and downstream turns remain unauthorized until their Reviews assign them.

## `Architecture_M6_CP3_DEFN_SEAM_A7_Certified_Seam_Cross_Sheet_Authority_Review_Decision_20261022.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_DEFN_SEAM_A7_Certified_Seam_Cross_Sheet_Authority_Review_Decision_20261022.md`; moved verbatim.

### RA-130 — DEFN-SEAM-A7 review: accepted with binding amendments; CB26 authorized (2026-10-22)

**Turn:** `M6-CP3-DEFN-SEAM-A7-RP01-CERTIFIED-SEAM-CROSS-SHEET-AUTHORITY-REV`.

**Verdict:** the contract `Architecture_M6_CP3_DEFN_SEAM_A7_Certified_Seam_Cross_Sheet_Authority_20261022.md` is **accepted with amendments**.
- **Accepted:** its consumer census of the source, its proof that `relationCertified` can hold, its core rule (certified seams replace only `occurrenceCertified`), and its diagnostic.
- **Missed:** the frozen test that already pins A7's behaviour on this relation.
- **Defects:** the rule duplicates a predicate, binds spans in an order nobody checks, and accepts any connecting transition where the certificate's own is required.
- Amendments B1–B6 are binding on CB26 and TB27. CB26 is authorized: RP plus one diagnostic line in the TQ helper, compile only.

#### RA-130.1 Verified

- **§1 census:** A6, A7 per-member, A7 forest edges and A8 verification are the only places that decide cross-sheet admissibility. The emitted-geometry union (RP:7641) does not decide anything.
- **§2 `relationCertified` can hold.** Span transitions are unioned into each side's `isolationEvidence` (RP:4444–4448), which A5 copies into `first/secondSideIsolationEvidence` (RP:5213–5219, swapped with canonical order at RP:5226–5234). A6 requires the forward and reverse transitions in the endpoint spans (RP:5856–5867).
- **§3.1, §3.2, §3.4:** the scope is correct, Periodic relations and OrdinaryFront relations without a certificate are unchanged, and `occurrenceCertified` is replaced only for certified seams. This agrees with RA-34.1: one Forward/Reverse match used throughout, and A7 checks its own conditions.
- **§4:** the site suffix is correct. `geometry_embedding_failure_name` exists for the helper (header line 1419).

#### RA-130.2 B1 — the frozen D7 witness is the governing oracle (missed by the audit)

- **What the test requires.** `cp3entry:5` (`M6CP3.ProducedSeamCollinearOrdinaryFrontRequiresExactCrossSheetTransition`, TQ:3977–4056) implements RA-33.4/RA-34's D7 falsifier:
  - **positive:** A7 must produce geometry for the untampered certified seam relation with disjoint endpoint sheets (TQ:4021–4025);
  - **tamper:** clearing `firstSideIsolationEvidence`, `secondSideIsolationEvidence` and `equivalence.isolationTransitions`, while keeping the spans and certificate, must make A7 reject with code `UncertifiedCrossSheetBinding` and site **exactly `cross-sheet`** (TQ:4027–4055).
- **What this means.** The current A7 code contradicts an architecture-level witness, not just a new contract. §1 dismissed tests as "not admission sites", and RA-129 also missed this.
- **Binding:**
  - in the certified-seam branch, failure of the relation-evidence check keeps site `cross-sheet`;
  - TB27 reports the D7 tamper outcome as a falsifier, alongside the D3 tamper.
- **Correction to §6:** the D3 tamper in `cp3entry:3` rotates the second endpoint's face gauge by a quarter turn. It does not tamper a certificate.

#### RA-130.3 B2 — bind spans to the relation's canonical endpoints

- **Why.** A7's forest-edge loop takes `first`/`second` from `edge.first`/`edge.second` (RP:7548–7549). A7 never checks that order against `relation.id` (RP:7191–7204). A6 happens to publish canonical order (RP:5999), but A7 should not depend on that.
- **Binding:** call `certified_seam_direction` with the occurrences `relation.id.first`/`relation.id.second` and `relation.evidence.firstEndpointSpan`/`secondEndpointSpan`.

#### RA-130.4 B3 — delete §3.3's explicit pair and binding equality

- **Why.** `certified_seam_direction` returns `Forward` only when `certified_seam_wedge_side` has already required, for each span, all of the following:
  - the certificate's face on that side;
  - the matching certified sheet;
  - membership of the binding in that occurrence's `cornerWedgeBindings` (RP:3855–3875);

  and symmetrically for `Reverse`. So the explicit check in §3.3 is exactly implied by the function.
- **Binding:** do not write that check. A second copy is the drift hazard RA-127.3 already had to repair once.

#### RA-130.5 B4 — the A7 evidence check must use the certificate's own transition

- **Why.** In the certified branch, the DEFN keeps `relationCertified` as "any transition connecting the endpoint sheet sets". That would let a transition on an unrelated seam that happens to join the same sheets certify the crossing. RA-32/RA-34 forbid this: certificate- and relation-owned seam evidence selects the path, not global sheet labels.
- **Binding:** in the certified branch, the relation evidence (the three lists) must contain the transition `{certificate.region(), certificate.seam(), side-1 sheet, side-2 sheet}`, in either orientation, with the sheets ordered as the direction selects. On producer data this is satisfied: A6 requires that very transition in the endpoint spans, with `collinearEdge` equal to `certificate.seam()`, and the spans feed the side evidence.

#### RA-130.6 B5 — make every cross-sheet rejection identifiable

- **Why.** Six A7 checks share one code, and the plain `cross-sheet` site would cover three different causes. TB27 has to tell them apart. No test asserts the new labels; TQ asserts only `cross-sheet` (D7), `cross-sheet:hard-rail` and `cross-sheet:wedge`.
- **Binding sites:**

| Case | Site |
|---|---|
| Certified branch, no direction | `cross-sheet:seam-direction` |
| Certified branch, evidence check (B4) fails | `cross-sheet` (pinned by D7) |
| OrdinaryFront without a certificate, existing rule fails | `cross-sheet:no-certificate` |
| Periodic, existing rule fails | `cross-sheet:periodic` |

#### RA-130.7 B6 — Periodic is a latent defect, recorded but out of scope

- RA-129.3's impossibility proof does not depend on the relation kind. A Periodic edge with disjoint endpoint sheets also always fails `occurrenceCertified`.
- No witness exists yet. B5's `cross-sheet:periodic` will show one if it occurs, and then it routes to Review. No Periodic change is authorized.

#### RA-130.8 Successor `M6-CP3-CB26-RP01-A7-CERTIFIED-SEAM-CROSS-SHEET-AUTHORITY` (Code + Build, compile only)

1. **RP, A7 forest-edge branch (RP:7543–7603).** For an OrdinaryFront edge with disjoint sheets and a typed `isolationSeamTransportCertificate`:
   - compute the direction per B2;
   - if none, reject with site `cross-sheet:seam-direction`;
   - otherwise run the B4 evidence check, and reject with site `cross-sheet` if it fails;
   - `occurrenceCertified` is not evaluated in this branch.
   - All other cases keep today's predicate, with the B5 labels.
2. **RP, failure mapping (RP:9276–9280):** append `":" + site` to `result.failure` for `UncertifiedCrossSheetBinding` when the site is not empty.
3. **TQ, D3 helper (TQ:2811):** record `"A7:" + geometry_embedding_failure_name(code) + ":" + site`. No other TQ edit.
4. **Limits:** no change to A5, A6, per-member A7 checks, A8, headers, selectors or workflows. No B3 duplicate. Lines at most 100 columns.
5. **Build:** compile the eight targets with GMP/GMPXX, `runtimeExecution=false`. Record `Architecture_M6_CP3_CB26_A7_Certified_Seam_Cross_Sheet_Authority_Code_Build_Record_20261022.md` (at most 30 lines).

**STOP** on a compile error, on any need to edit outside the four places above, or if B4 cannot be stated from data A7 already has.

#### RA-130.9 TB27 plan (issued at CB26-REV) and sequence

- **TB27 selections:** the 18 TB26 selections plus three A7 site guards:
  - `M6CP1.A7CrossSheetBindingRequiresConnectingIsolationTransition` (TQ:10000);
  - `M6CP2.A7WedgeTransitionWrongRegionRejects` (TQ:11196);
  - `M6CP2.A7WedgeTransitionTouchWithoutConnectivityRejects` (TQ:11256).
- **Falsifiers:**
  - any of the eight still rejects with `cross-sheet:seam-direction`;
  - the D7 tamper passes or changes site;
  - the D3 tamper passes;
  - any control or guard turns RED;
  - a `cross-sheet:periodic` site appears (route under B6).
- **Not falsifiers:** a new first failure is measured, not assumed green.
- **Sequence:** DEFN-SEAM-A7-REV (this) → **CB26** → CB26-REV → TB27 → TB27-REV → CB27 (negative tests, TQ only: RA-127.4b plus A7 unrelated-seam evidence and no-direction) → CB27-REV → TB28 (new tests plus a selector-497 census) → TB28-REV → DEFN-M1 → corrective CB/TB → DEFN-T1 → fixture debt → census → RP-01 Review. `DEFN-SEAM-NZ` waits for a witness, and the Periodic follow-up (B6) waits for one too. `DIAG-RETAIN` is scheduled clear of RP-01 turns.
- **Accounting (unchanged):** stable 66/17/49, debt 1, CP2 491/491; R3 403/497 rejected; TB21 449/497 candidate; selector 497 frozen. `RP-01` open, `RP-02` UNREACHED, Gate C suspended.

| Duty | Answer |
|---|---|
| Decisive claims re-derived | Side-evidence dataflow (RP:4444–4448, 5213–5234); forest-edge order (RP:5999, 7191–7204); wedge-side implication (RP:3855–3875); D7 test body (TQ:3977–4056); site assertions in TQ; RA-34.1 |
| Non-vacuity | D7 positive and tamper plus D3 tamper are named falsifiers; three site guards added |
| Obligations | RA-129.4 discharged; RA-127.4 (iii) and D7 carried to TB27; RA-127.4b and A7 negatives carried to CB27; B6 registered |
| Durable docs | Handoff, TODO, tracker, CHANGELOG, ORIENTATION, ROADMAP, Frozen Definitions index |
| Boundary | Review-only; no source, test, selector, workflow or runtime change |

## `Architecture_M6_CP3_TB25_Seam_Frame_Values_Harvest_Review_Decision_20261022.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_TB25_Seam_Frame_Values_Harvest_Review_Decision_20261022.md`; moved verbatim.

### RA-126 — TB25 seam frame-values review: the identity-turn branch; DEFN-SEAM narrowed to A5 shared-node side authority (2026-10-22)

**Turn:** `M6-CP3-TB25-RP01-SEAM-FRAME-VALUES-HARVEST-REV`.

**Verdict:** TB25 is **accepted** as diagnostic evidence. The pre-registered routing (RA-124.6) selects **F = 0**: the frozen D3 rule (RA-30a.3) is satisfiable for every measured seam, and the A5 face clauses are the only blocker. `cp3entry:3` and `cp3entry:5` join the A5 seam family. DEFN-SEAM is **authorized, narrowed** to A5 shared-node side authority. No code is authorized yet.

#### RA-126.1 Harvest verified independently

- **Artifact:** `12384333036` (run 39682528031, head `30a1e9357`). The provider digest equals the local ZIP SHA-256 `f10ef778…cbc`; it expires 2026-10-28T21:56:02Z. **16/16** manifest entries check.
- **Logs:** each of the 11 logs has exactly one `[ RUN ]` and no skip. Rows 6–11 PASS with no site.
- **Torus rows 1–3:** one byte-identical site: the TB24 prefix plus `;branch=3,3;gaugeSel=0,0;gaugeSpan=0,0;turn0=0,0`.
- **D3 witnesses (rows 4–5):** each logs three A5 `OccurrenceMismatchedIsolationEvidence` sites at `seam=1,4`. They show `sel=0/0,0/0`, `support=vertex,vertex`, `wedge=0/0,2/1+3/1`, the clause `second-face`, `spanOnly0=forward`, and `branch=0,0;gaugeSel=0,0;gaugeSpan=0,0;turn0=0,0`.

#### RA-126.2 Routing (RA-124.6, read for both occurrences)

| Family | Producer signature | Stripped turn (RP:5887–5905) | d | F | Branch |
|---|---|---|---|---|---|
| Torus A5 (10 rows, TB23) | curved: `branch − gaugeSel = 3, 3` | (3−0) − (3−0) = 0 | 0 | 0 | F = 0 |
| D3 witnesses `cp3entry:3/5` | uniform: `0, 0` | 0 | 0 | 0 | F = 0 |

**RA-124.3 P3 is confirmed at runtime.** Both families have the same structure (RA-124.3 P1–P2): one shared node, one representative face, inside one occurrence's wedge and outside the other's. The face clause that fails is `first-face` on the torus and `second-face` on the D3 grid. Span/wedge side authority alone gives `forward`, and D3 (stripped turn = F = identity) holds.

Neither gauge-table inconsistency (d ≠ F) nor a nonzero certified turn was observed. **Nonzero-turn seams remain unmeasured.** For them, P3 still predicts an A6 reject under frozen D3. That is deferred, not resolved.

#### RA-126.3 Classification

- **A5-ISO:** 10 torus rows plus `cp3entry:3/5`, 12 rows with one mechanism. The owner is the **A5 certified-seam face clauses (RP:3891–3892)** acting on shared-node relations. A2's per-node representative is the data model, not a defect, for identity seams.
- **`cp3entry:3/5` now have an owner.** Their helper (`m6cp3_produced_seam_fixture`, TQ:2725) fails because of the A5 mechanism, not fixture construction.
- **RA-124.3 Corollary 2 is amended.** RA-124 said these rows were filed as adjacent-sheet fixture debt; that is wrong. The adjacent-sheet item is the curved-disk helper `make_curved_disk_with_adjacent_source_sheet` (P10:2670, RA-93.3), which stays in the fixture-debt list. `cp3entry:3/5` previously had no owning family.

#### RA-126.4 Successor `M6-CP3-DEFN-SEAM-RP01-A5-SHARED-NODE-SIDE-AUTHORITY` (documents only)

**Deliverable:** `Architecture_M6_CP3_DEFN_SEAM_A5_Shared_Node_Side_Authority_20261022.md`, at most 90 lines, anchored at HEAD. It must contain:

1. **Exact amended rule for `certified_seam_direction` (RP:3880–3911).**
   - When both canonical occurrences are **one shared node**, defined as equal `support` and equal `placement.selectedFace`, the two face-equality clauses do not apply. Direction then comes from `certified_seam_wedge_side` (RP:3855–3875), which already requires the span binding to be in the occurrence's own wedge with the certified sheet, with opposite sides.
   - Every other clause is unchanged: collinear edge, certified seam, region, distinct sheets, uniqueness.
   - Relations that are not shared-node keep the face clauses unchanged.
2. **Enforcer impact.** List every caller of the function: RP:4695 (certificate selection), the relation reject at RP:5250–5262, RP:5293 (site diagnostics) and A6 RP:5878. State that A6, its D3 check (RA-30a.3), the gauge-face check at RP:5869–5870 and the endpoint gauges are unchanged.
3. **Non-weakening table.** Cases that must still reject, each with the clause that rejects it:
   - shared node with the span outside the wedge;
   - same side;
   - equal sheets;
   - two certificates;
   - not shared-node with the face clause failing;
   - shared node with a nonzero certified turn, rejected at A6 by D3.
4. **Predictions and falsifiers for the corrective TB.**
   - The A5-ISO rows (including G4-B002) and `cp3entry:3/5` get past the A5 seam reject. Their next first failure is unknown and is a measured outcome; no green is claimed.
   - All current controls still pass.
   - The TB21-PASS 449 rows are not changed by the amendment (a selector census follows).
5. **Out of scope:**
   - nonzero-turn seams (a later `DEFN-SEAM-NZ`);
   - per-occurrence representatives in A2;
   - any A6 or D3 change;
   - any minimum-face rule (RA-79.4) or new producer certificate (RA-78.4).

**STOP** and return to Review if the rule cannot be stated without changing A6, or if a caller depends on the face clause for anything other than side authority.

#### RA-126.5 Sequence and accounting

- **Sequence:** TB25-REV (this) → **DEFN-SEAM** → DEFN-SEAM-REV → CB25 (corrective, RP `certified_seam_direction` only) → CB25-REV → TB26 (12 A5-ISO rows, guard and controls) → TB26-REV → selector-497 census → DEFN-M1 → corrective CB/TB → DEFN-T1 → fixture debt → census → RP-01 Review. `DIAG-RETAIN` (user-directed) is scheduled clear of RP-01 turns.
- **Accounting (unchanged):** stable 66/17/49, debt 1, CP2 491/491; R3 403/497 rejected; TB21 449/497 candidate; selector 497 frozen. `RP-01` open, `RP-02` UNREACHED, Gate C suspended.
- **Interim GUI tooling** (diagnostics sections 6–10, streamlines, build fixes) was committed between CB24 and this Review. All RP-01 sources are byte-identical to `dae267a82`, apart from the legacy streamline tracer, which SurfaceCells does not use.

| Duty | Answer |
|---|---|
| Decisive claims re-derived | ZIP digest; 16/16 manifest; 11 logs (one RUN, no skip); every site string; routing arithmetic for both families |
| Non-vacuity | Values observed on two producers (curved and uniform) and three fixtures; guard and controls selected and passed |
| Obligations | RA-124.6 discharged (F = 0 branch); RA-124.3 P3 confirmed; D3 nonzero-turn obligation carried to `DEFN-SEAM-NZ` |
| Durable docs | Handoff, TODO, tracker, CHANGELOG, ORIENTATION, ROADMAP, Frozen Definitions index |
| Boundary | Review-only; no source, test, selector, workflow or runtime change |

## `Architecture_M6_CP3_TB26_Shared_Node_Seam_Witness_Harvest_Review_Decision_20261022.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_TB26_Shared_Node_Seam_Witness_Harvest_Review_Decision_20261022.md`; moved verbatim.

### RA-129 — TB26 review: A5 and A6 now admit the shared-node seam; A7's cross-sheet rule is the next blocker (2026-10-22)

**Turn:** `M6-CP3-TB26-RP01-A5-SHARED-NODE-SEAM-WITNESS-HARVEST-REV`.

**Verdict:**
- TB26 is **accepted** as diagnostic evidence.
- Its report's A6/D3 conclusion is **corrected**: A6 *did* admit the untampered certified seam relation; only the tamper went unreached.
- All nine RED rows now stop in **A7**, and A7's OrdinaryFront cross-sheet rule is provably unsatisfiable for the relations CB25 now admits.
- Successor: documents-only **DEFN-SEAM-A7**. No promotion; accounting unchanged.

#### RA-129.1 Harvest verified independently

- **Artifact:** `12403479548` (run 39727886868). The provider digest equals the local ZIP SHA-256 `3f7df8c2…ac2d`; it expires 2026-10-29T05:26:45Z.
- **Manifests:** **21/21** entries check. The execution record shows source `c5e0b242f`, package `12399179446`, 18/18 executed, 9 PASS / 9 RED, `control_bad=0`, postflight true, and no compile, relink or benchmark.
- **Logs:** each of the 18 logs has exactly one `[ RUN ]`. The six guard and control rows PASS, and `focused30:26, 27, 28` PASS.

#### RA-129.2 Where each RED row stops

| Rows | Evidence in log | Stage reached |
|---|---|---|
| `focused30:6, 20, 25`; `selector:444, 446, 448` | `UncertifiedCrossSheetBinding`; row 25 shows `firstStage=tracing/phase-front-materialization` | A7. The code exists only in `GeometryEmbeddingFailureCode` (RP:7103), and the pipeline maps A7 errors to that name (RP:9276) |
| `focused30:24` | A5 and A6 assertions pass; `a7 == nullptr` at TQ:6024 | A7; code not printed |
| `cp3entry:3, 5` | `A7:rejected-certified-seam` at all sizes 0.25, 0.5 and 1.0 | A7, after A5 and A6 (below) |

**Correction to the TB26 report.** The helper `m6cp3_produced_seam_fixture` (TQ:2725–2814) records `A7:rejected-certified-seam` only after all of the following:
- A5 produced a certified OrdinaryFront seam relation with a typed seam certificate, and its endpoints' wedge sheets do not overlap;
- A6 produced its product and selected that relation in its forest;
- A7 then rejected.

A6's seam branch (RP:5804–5905) checks the reciprocal span transitions, both gauges and D3 for every relation with a certificate. So:
- **RA-127.4 (i) and (ii) are discharged** in all six searches: A5 finds a certified reciprocal relation, and A6 admits it untampered, which requires stripped turn = expected turn.
- **(iii), the D3 gauge tamper, is still unmeasured.** The test asserts that the helper returned a fixture before it reaches the tamper, and the helper needs A7 to succeed.

#### RA-129.3 Root cause: A7 cannot certify a cross-sheet OrdinaryFront relation (static proof)

A7 (`SourceAttachedGeometryProducer::produce`, RP:7120) handles OrdinaryFront and Periodic forest edges at RP:7543–7603. When the endpoints share a wedge sheet, A7 accepts. When they share none, it requires both `relationCertified` and `occurrenceCertified`.

- **`occurrenceCertified` is never true when the sheets are disjoint.** An occurrence's `cornerWedgeIsolation` holds only transitions crossed while walking its own wedge, and every transition joins two of that wedge's own bindings (RP:4555–4661; the walk starts by pushing `outgoing`). So each transition's two sheets both belong to that occurrence. When the first and second endpoints share no sheet, no transition can join them.
- **So A7 rejects every cross-sheet OrdinaryFront edge it checks.** Before CB25 none reached A7, because A5 rejected them all (RA-124.3 P2); CB25 opened A5 and the rejection moved here. This is the same structural defect: a later stage re-derives cross-sheet authority from per-occurrence data that cannot carry it, and ignores the typed A4 seam certificate that A5 selected and A6 checked with D3.
- **What is measured and what is not.** 8 of 9 rows report the A7 code, and `focused30:24` fails at A7. But A7 publishes no site label (RP:9276), and six A7 checks share this code. That the cross-sheet check fires first is a strong inference, not a measurement.

**Review ownership.** RA-127 accepted an enforcer table that listed only the callers of `certified_seam_direction`. It did not audit stages that re-derive cross-sheet admissibility on their own. That breaks LESSONS "Keep definitions and their validation mutually traceable" (every implementing consumer). The A7 consumer is attributed to this Review's miss, not to CB25, which implemented RA-127 exactly.

#### RA-129.4 Successor `M6-CP3-DEFN-SEAM-A7-RP01-CERTIFIED-SEAM-CROSS-SHEET-AUTHORITY` (documents only)

**Deliverable:** `Architecture_M6_CP3_DEFN_SEAM_A7_Certified_Seam_Cross_Sheet_Authority_20261022.md`, at most 90 lines, anchored at HEAD. It must contain:

1. **Consumer audit, required first.** List every stage after A5 that decides whether a relation may join two different isolation sheets: A6 (RP:5804–5905), A7 (per-member wedge checks RP:7423–7541; forest edges RP:7543–7603), verification (`a5:wedge-bindings` and `a5:wedge-isolation`, RP:8240–8290), and any other site found by searching for `cornerWedgeSheets`, `cornerWedgeIsolation`, `isolationTransitions`, `SideIsolationEvidence` and `isolationSeamTransportCertificate`. For each, give its predicate on a shared-node certified seam relation, and say whether it passes, rejects, or cannot be decided statically.
2. **`relationCertified` analysis.** Say whether it can hold for these relations, using RP:5214–5233 and the side authority of front edges collinear with a seam.
3. **Amended A7 rule.** For an OrdinaryFront forest edge with disjoint endpoint sheets **and** a typed seam certificate:
   - the crossing is certified only if `certified_seam_direction` (the same function as A5 and A6, given the relation's endpoint spans and certificate) returns a direction;
   - the endpoint sheets must equal the certificate's sheets on the sides that direction selects.
   - A7 must not re-derive the side and must not use sheet labels without the certificate.
   - Relations without a certificate, and all Periodic relations, keep the existing rule.
4. **Diagnostic.**
   - For `UncertifiedCrossSheetBinding`, append A7's existing `site` to `result.failure`, as is already done for `:support-point` (RP:9276–9280). No test compares the exact string.
   - The D3 helper records the A7 code and site in place of the bare `A7:rejected-certified-seam`.
5. **Non-weakening table.** Cases that must still reject:
   - a disjoint-sheet edge with no certificate;
   - a certificate whose sheets do not match the endpoints on the selected sides;
   - the endpoint spans failing `certified_seam_direction`;
   - Periodic relations with disjoint sheets (unchanged);
   - a wrong region;
   - per-member wedge checks that fail.
6. **Predictions and falsifiers for TB27.**
   - The 8 rows that report `UncertifiedCrossSheetBinding` get past A7's cross-sheet check.
   - `focused30:24`'s A7 code becomes visible.
   - `cp3entry:3/5` reach the D3 tamper, which must reject as `RelationCertificateConflict`; a tamper that passes falsifies the contract.
   - The next first failure is measured, not assumed.
   - All controls stay PASS.

**Out of scope:** any code, compile or runtime change; changes to A5, A6 or D3; nonzero-turn seams; Periodic cross-sheet semantics; DIAG-RETAIN.

**STOP** and return to Review if the audit finds a further consumer that cannot be stated without changing A6, or if `relationCertified` cannot be decided statically.

#### RA-129.5 Sequence and accounting

- **Sequence:** TB26-REV (this) → **DEFN-SEAM-A7** → DEFN-SEAM-A7-REV → CB26 (RP: A7 rule and failure-site suffix; TQ: helper record only) → CB26-REV → TB27 (the same 18 selections) → TB27-REV → CB27 (negative tests for RA-127.4b and the A7 table; TQ only) → CB27-REV → TB28 (new tests plus a selector-497 census) → TB28-REV → DEFN-M1 → corrective CB/TB → DEFN-T1 → fixture debt → census → RP-01 Review. `DEFN-SEAM-NZ` waits for a nonzero-turn witness; `DIAG-RETAIN` is scheduled clear of RP-01 turns.
- **Accounting (unchanged):** stable 66/17/49, debt 1, CP2 491/491; R3 403/497 rejected; TB21 449/497 candidate; selector 497 frozen. `RP-01` open, `RP-02` UNREACHED, Gate C suspended.
- **`focused30:26–28` PASS** are individual witnesses only, with no family credit until the census.

| Duty | Answer |
|---|---|
| Decisive claims re-derived | ZIP digest; 21/21 manifest; 18 logs (one RUN each); failure lines; A7 code ownership (RP:7103, 9276); helper control flow; A6 seam-branch checks; the `occurrenceCertified` proof |
| Non-vacuity | A6 seam branch exercised on producer data in six searches; D3 tamper still unmeasured and carried |
| Obligations | RA-127.4 (i)/(ii) discharged, (iii) carried to TB27; RA-127.4b carried to CB27; this Review's own audit miss recorded |
| Durable docs | Handoff, TODO, tracker, CHANGELOG, ORIENTATION, ROADMAP, Frozen Definitions index |
| Boundary | Review-only; no source, test, selector, workflow or runtime change |

## `Architecture_M6_CP3_TB27_A7_Certified_Seam_Cross_Sheet_Verification_Review_Decision_20261022.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_TB27_A7_Certified_Seam_Cross_Sheet_Verification_Review_Decision_20261022.md`; moved verbatim.

### RA-132 — TB27 review: the seam family and both tamper falsifiers pass; census next, before more tests (2026-10-22)

**Turn:** `M6-CP3-TB27-RP01-A7-CERTIFIED-SEAM-CROSS-SHEET-VERIFICATION-REV`.

**Verdict:** TB27 is **accepted** as targeted candidate evidence.
- **Pass:** all 12 seam-family rows, the D3 and D7 tamper falsifiers, and every guard and control. RA-127.4 (iii) and RA-130 B1 are discharged at runtime.
- **Not covered:** three of CB26's new rejection paths are exercised by no test.
- **Sequence realigned:** the selector-497 census (TB28) runs **now**, on the unchanged CB26 package, ahead of the test-only CB27. No promotion until the census and the RP-01 Review.

#### RA-132.1 Harvest verified independently

- **Result artifact:** `12420676412` (run 39764327506). The provider digest equals the local ZIP SHA-256 `33dc0878…babb`; it expires 2026-10-29T10:52:14Z.
- **Manifest and execution record:** **24/24** entries check. The record shows source `e3d60337e`, package `12409939859`, 21 planned and executed, 21 PASS, every `*_bad=0`, postflight true, and no compile, relink, benchmark or selector-497 run.
- **Logs:** each of the 21 logs has exactly one `[ RUN ]` and one `[ OK ]`, with no `Failure`, `FAILED` or `SKIPPED`. Each RUN line names the test in its ledger row.
- **Source:** CB26 (`e3d60337e`) is RP +52/−2 and TQ +7/−1. It matches RA-130.8 and RA-131:
  - spans are bound to `relation.id.first/second` (B2);
  - no duplicate check (B3);
  - the evidence must contain the certificate's own transition (B4);
  - the four sites are distinct (B5);
  - the failure-site suffix is added.

#### RA-132.2 What the PASS results prove

- **The seam family is 12/12 PASS:** `focused30:6, 20, 24–28`; `selector:444, 446, 448`; `cp3entry:3, 5`. In TB26, nine of them failed in A7.
- **The PASS results are not vacuous.** The D3 test (TQ:3619) and the D7 test (TQ:3983) contain no `return` or `GTEST_SKIP` before their tampers.
  - **D3:** the producer supplied a certified seam relation that A5, A6 and A7 all accept. The quarter-turn face-gauge tamper is rejected as `RelationCertificateConflict`. This discharges RA-127.4 (iii) and shows the D3 guard works on producer data.
  - **D7:** A7 produced geometry for the untampered relation. With the relation-side evidence cleared, it rejected with `UncertifiedCrossSheetBinding`, site `cross-sheet`. This discharges RA-130 B1 and exercises the B4 rejection path.
- **The three A7 site guards still pass**, so the per-member wedge checks are unchanged.

#### RA-132.3 Coverage still missing (owed to CB27)

No test asserts the new sites:
- `cross-sheet:seam-direction`;
- `cross-sheet:no-certificate`;
- `cross-sheet:periodic`.

The B4 precision case is also untested: a relation with a *connecting* transition on an unrelated seam must reject. The D7 tamper clears every transition, so it cannot tell B4 apart from the old any-transition rule.

The shared-node predicate's negatives (RA-127.4b) are untested too. Records republished for validation get only structural checks (RP:3708–3756) and never re-enter A5's seam check. But A6 (RP:5878) and A7 (CB26) call the same `certified_seam_direction`, so these cases can be tested there.

#### RA-132.4 Realignment: census before more tests

RA-130.9 planned to run the census only after CB27's tests (TB28 = new tests + census). That order is changed, because:
- **No product change remains.** CB27 is test-only, and RP is final for this family. The CB26 package `12409939859` is exactly what the census must measure.
- **Earlier warning.** CB25 and CB26 changed admission in A5 and A7 for every certified seam. A regression from PASS to RED among TB21's 449 PASS rows is the risk that matters most. It should be measured before anything else is built on top.
- **Smaller turns.** The census needs no build, and the new tests then need only a targeted run.

**New order:** TB28 (census) → TB28-REV → CB27 (negative tests) → CB27-REV → TB29 (new tests plus guards) → TB29-REV.

#### RA-132.5 Successor `M6-CP3-TB28-RP01-SELECTOR-497-CENSUS` (artifact-only Test + Benchmark)

- **Input:** the immutable CB26 package `12409939859` (source `e3d60337e`), run unchanged with the existing harness `m6_cp3_entry_497_artifact_only_harness.sh` (SHA-256 `947a95ee…79dd`) through `agent-test-benchmark-reusable.yml`, with `CANDIDATE_ARTIFACT_ID=12409939859`. The selector is byte-frozen (selector-449 SHA-256 `d4a0d1b7…6414`).
- **Harness inputs** (this Review re-derived them from the package):
  - `EXPECTED_SOURCE_SHA=e3d60337ed34538547d3a6d519bafae5b184330e`;
  - `EXPECTED_CANDIDATE_ZIP_SHA256=ee08279e537af4e99f287d28595df0ef639e632aa345bc0b1986bbb361ee86fa`;
  - `EXPECTED_ROOT_MANIFEST_SHA256=0c9183b848e4b13afae4c0b84c23ddd18f0f1526ccdcf4d4da688dc893e8b1cf` (28 entries);
  - `EXPECTED_SOURCE_ARCHIVE_SHA256=d37cfbdab24b92aad6ab2ecfd135d92702c0874f9c69a0164bf578705d78955c`.

  Inside the packaged source, focused-30, focused-12, selector-449 and the routing receipt match the harness's built-in hashes. The package expires 2026-10-29T08:00:15Z, so TB28 must run before then.
- **Report:**
  - all 497 rows: identity, verdict, exit, first failure, log hash;
  - a row-by-row diff against TB21 (`Architecture_M6_CP3_TB21_Selector_497_Red_Inventory.tsv`, 48 RED): every PASS→RED and every RED→PASS;
  - the new inventory `Architecture_M6_CP3_TB28_Selector_497_Red_Inventory.tsv`, with the same columns as TB21 plus a TB21 column;
  - the A7 site for every `UncertifiedCrossSheetBinding`.
- **Predictions:**
  - the 12 seam-family rows go RED→PASS;
  - `selector:447` (RED in TB21, PASS since TB25) is PASS;
  - **no TB21 PASS row becomes RED**;
  - so at least **462/497**.
  - The other 35 TB21 RED rows are measured and classified, not assumed: M1 (`focused30:12`, `cp3entry:2` and the M1 selector rows), D2 `cp3entry:1`, and fixture debt.
- **Falsifiers and STOP rules:**
  - any PASS→RED;
  - any `cross-sheet:seam-direction` or `cross-sheet:periodic` site (`periodic` routes under RA-130.7);
  - a seam-family row RED;
  - a manifest, package or selector hash mismatch.

  Report and stop; no fixing. A change to the harness is allowed only to repair extraction mechanics, and must be recorded.
- **Out of scope:** any source, test, fixture, selector or workflow semantics; compile, relink or benchmarks; promotion.

#### RA-132.6 CB27 scope (issued at TB28-REV; test-only, TQ)

Use the D7 fixture: tamper the A5 records, republish them, and run A7 against the original A6 product (as at TQ:4027–4055). Assert the exact A7 site for each case, plus the A6 code the author derives:

1. **Unrelated seam:** move the certificate transition to a different seam that joins the same sheets → `cross-sheet` (the B4 precision case).
2. **No certificate:** clear the relation's certificate → `cross-sheet:no-certificate`.
3. **RA-127.4b (A1):** change one endpoint's lattice coordinate → `cross-sheet:seam-direction`.
4. **RA-127.4b:** span binding outside its wedge → `cross-sheet:seam-direction`.
5. **RA-127.4b same-side:** only if it can be built without tripping the per-member wedge check first. Otherwise, record which check covers it.

Periodic is not constructible from producer data; it stays under RA-130.7.

#### RA-132.7 Sequence and accounting

- **Sequence:** TB27-REV (this) → **TB28 (census)** → TB28-REV → CB27 → CB27-REV → TB29 → TB29-REV → DEFN-M1 → corrective CB/TB → DEFN-T1 → fixture debt → census → RP-01 Review. `DEFN-SEAM-NZ` and the Periodic follow-up each wait for a witness. `DIAG-RETAIN` is scheduled clear of RP-01 turns.
- **Accounting (unchanged):** stable 66/17/49, debt 1, CP2 491/491; R3 403/497 rejected; TB21 449/497 candidate; selector 497 frozen. `RP-01` open, `RP-02` UNREACHED, Gate C suspended.

| Duty | Answer |
|---|---|
| Decisive claims re-derived | ZIP digest; 24/24 manifest; CB26 package digest, root manifest, source archive and the four packaged gate-file hashes; 21 logs (RUN, OK, test name); CB26 diff against RA-130.8; no early exit in the D3/D7 bodies; validation-path scope (RP:3708–3756); site coverage in TQ; harness extraction and selector checks |
| Non-vacuity | D3 and D7 tampers reached and rejected; untested paths listed for CB27 |
| Obligations | RA-127.4 (iii) and RA-130 B1 discharged; RA-127.4b and B4/B5 negatives carried to CB27; RA-130.7 carried |
| Durable docs | Handoff, TODO, tracker, CHANGELOG, ORIENTATION, ROADMAP, Frozen Definitions index |
| Boundary | Review-only; no source, test, selector, workflow or runtime change |

## `Architecture_M6_CP3_TB28_Census_Review_Audit_Decision_20261022.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_TB28_Census_Review_Audit_Decision_20261022.md`; moved verbatim.

### RA-134 — Audit of the TB28 review (RA-133): evidence and CB27 upheld; RED partition corrected; typed-reason harvest before DEFN-M1 (2026-10-22)

**Turn:** `M6-CP3-TB28-RP01-SELECTOR-497-CENSUS-REV-AUDIT` (independent audit of `M6-CP3-TB28-RP01-SELECTOR-497-CENSUS-REV`, RA-133).

**Verdict:**
- **Upheld:** RA-133's evidence and its CB27 authorization. CB27 gains three binding precondition assertions (RA-134.4).
- **Corrected:** RA-133's partition of the 35 RED rows. It groups by test topic, while claiming to group by "first observed failed stage".
- **Realigned:** 21 of the 35 REDs carry no typed reason. A test-only diagnostic turn (CB28) and a harvest (TB29) now come before DEFN-M1, so that DEFN-M1 is scoped from measured factory clauses rather than static inference.

#### RA-134.1 Evidence re-derived independently

- **Artifact:** `12424484672`. The provider digest equals the local ZIP SHA-256 `a54110db…56e6`; it expires 2026-11-05T12:21:10Z. **1019/1019** manifest entries check.
- **Counts:** `combined-ledger.tsv` has 497 rows, no duplicate phase:ordinal, 462 PASS and 35 RED.
- **Against the TB21 inventory (48 RED), by set difference:**
  - PASS→RED: **none**;
  - RED→PASS: exactly `focused30:6, 20, 24, 25, 26, 27, 28`; `selector:444, 446, 447, 448`; `cp3entry:3, 5`.
- RA-132's prediction (at least 462/497, zero regressions) holds exactly. CB25 and CB26 are regression-free on the frozen selector.

#### RA-134.2 Correction — partition by first failing component

RA-133's "Periodic product/fixture setup" family (13 rows) merges two different failing components, and labels them fixture setup without evidence:
- **`selector:189–195`** throw at the periodic-route helper (SP10:4340), when `FieldTransportAtlas::make` (A3) fails;
- **`selector:220, 221, 296, 302, 304, 439`** throw at the direct periodic-owner helper (TQ:358), when the checked factory `SurfacePhaseFrontProduct::make` rejects.

**Measured partition of the 35** (component, then whether a typed reason is visible):

| First failing component | Rows | Typed reason in log |
|---|---|---|
| Checked phase-front factory (`make` / `construct_phase_front_product`) | `focused30:3` (TQ:2498 helper), `focused30:22, 23` (TQ:5942/5983), `selector:139, 140, 142` (SP10:6479 helper), `selector:220, 221, 296, 302, 304, 439` (TQ:358 helper), `cp3entry:4` (TQ:3900) — **13** | **none** |
| Same factory, wrong typed result | `selector:211, 219` (expected `InvalidOppositeEdge`); `selector:227, 230` (`InvalidPhaseFrontProduct` instead of `InvalidHardRailAuthority`) — **4** | code shown (int or name) |
| A3 `FieldTransportAtlas::make` | `selector:189–195` — **7** | **none** |
| A3, visible | `selector:442` (`SingularityMismatch`, edge (2,3)) — **1** | yes |
| A5 on a relabelled front | `focused30:12` (TQ:5158) — **1** | **none** (`a5_rejection_message` exists but is not streamed) |
| Producer disposition or oracle | `selector:204, 242, 247` (expected Rejected); `selector:250, 405` (expected Produced); `selector:201` (missing terminal vertex); `selector:174` (DCEL exception) — **7** | yes |
| Witness absence | `cp3entry:1` (D2, no odd gauge); `cp3entry:2` (hard-rail midline certificate) — **2** | yes |

**The checked factory is the first failure in 17 of 35.** RA-105.3 attributed M1 (10 rows) statically to one factory clause, the R2 certificate binding (S:8755–8775). Whether the six periodic-owner rows and `cp3entry:4` hit that clause, the H-pin (RA-105.4 covers periodic cut edges) or another clause is **unknown**. So DEFN-M1's scope cannot yet be stated: it may be 10, 17 or a split.

#### RA-134.3 Realignment — measure typed reasons first

- The A7 episode (RA-129.3: one code shared by six checks, and an unmeasured inference) and LESSONS "Diagnostics, classifiers, and causal investigation" both apply: an error code without its site is only a symptom.
- `SurfacePhaseFrontProductError` already carries `code`, `sourceAuthoritySite`, `edge`, `event`, `cell`, `region` and `periodicRelation` (`SurfaceCellTracing.h:1935`). The helpers simply drop them.
- A **test-only, message-only** change makes all 21 silent rows self-describing at zero product risk.
- **New sequence:** CB27 → CB27-REV → **CB28 (diagnostic messages)** → CB28-REV → **TB29**, which runs CB27's negatives, D3/D7, the three A7 guards and the 21 silent rows plus the four wrong-code rows on the CB28 package → TB29-REV → DEFN-M1, scoped from the measured factory clauses.

#### RA-134.4 CB27 upheld, with binding preconditions

The scope stays as RA-132.6/RA-133. Without these preconditions, a negative test can pass for the wrong reason:

1. **Unrelated seam.** Before running A7, assert that the tampered relation evidence **still contains a transition joining the two endpoint sheet sets**, with no transition on `certificate.seam()`. Otherwise the test cannot tell B4 apart from an "any connecting transition" rule.
2. **Lattice coordinate.** Assert that `support` and `placement.selectedFace` are still equal, and that only `latticeCoordinate` differs. That isolates the third clause of the A1 predicate.
3. **Outside wedge.** Assert that the substituted `interiorBinding` is not in that occurrence's `cornerWedgeBindings`, and that its face is a certificate side face.

Every case runs A7 against the **original** A6 product, as D7 does (TQ:4027–4055). If A7 rejects before the forest-edge branch, that is RA-133's STOP: record it, do not adapt.

#### RA-134.5 CB28 scope (issued at CB27-REV; test-only, messages only)

Files: `tests/SurfaceCellTransitionQuotientTests.cpp` and `tests/SurfaceCellsPhase10Tests.cpp`.

1. **One test-local formatter** for `SurfacePhaseFrontProductError`: code as an integer, plus `sourceAuthoritySite`, `edge`, `event`, `cell`, `region` and `periodicRelation`.
2. **Helpers** append the formatted error to their exception text: TQ:358, TQ:2498, SP10:6479. The SP10:4340 helper appends the `FieldAtlasBuildError` code and location, mirroring the formatter at `FieldTransportAtlasTests.cpp:75`.
3. **Assertions stream the reason:** `ASSERT_NE` at TQ:5942, 5983 and 3900 stream the formatted factory error; TQ:5158 streams `a5_rejection_message`.
4. **No other change:** no assertion, control-flow, fixture, expected-value or production change.

#### RA-134.6 Sequence and accounting

- **Sequence:** audit (this) → **CB27** → CB27-REV → CB28 → CB28-REV → TB29 → TB29-REV → DEFN-M1 (evidence-scoped) → DEFN-M1-REV → corrective CB/TB → DEFN-T1 → fixture debt (A3 periodic-route `189–195`; `174`, `242`, `250`, `442`, adjacent-sheet helper) → census → RP-01 Review. `DEFN-SEAM-NZ` and the Periodic follow-up each wait for a witness. `DIAG-RETAIN` is scheduled clear of RP-01 turns.
- **Accounting (unchanged):** stable 66/17/49, debt 1, CP2 491/491; R3 403/497 rejected; **TB28 462/497 candidate**; selector 497 frozen. `RP-01` open, `RP-02` UNREACHED, Gate C suspended.

| Duty | Answer |
|---|---|
| Decisive claims re-derived | ZIP digest; 1019/1019; 497/462/35; set differences against TB21; first-failure text of all 35; helper throw sites (TQ:358, 2498; SP10:4340, 6479); `ASSERT_NE` sites; error-type fields; RA-105.3/105.4 attribution |
| Non-vacuity | CB27 preconditions make each negative discriminating; CB28 makes 21 REDs attributable |
| Obligations | RA-133 evidence upheld; partition corrected; DEFN-M1 deferred behind TB29; docs restored |
| Durable docs | Handoff (sequence and `DIAG-RETAIN` restored), TODO (contradiction removed, sequence added), tracker, CHANGELOG, ORIENTATION, ROADMAP, Frozen Definitions index |
| Boundary | Review-only; no source, test, selector, workflow or runtime change |

## `Architecture_M6_CP3_TB28_Selector_497_Census_Review_Decision_20261022.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_TB28_Selector_497_Census_Review_Decision_20261022.md`; moved verbatim.

### TB28 independent Review — RA-133 (2026-10-22)

**Turn:** `M6-CP3-TB28-RP01-SELECTOR-497-CENSUS-REV`. **Verdict:** accept TB28 as independently verified **candidate-only census** of the unchanged CB26 package; **do not promote CP3 acceptance**. The full 497-entry gate is still RED (462 PASS / 35 RED). No new runtime, compile, source, test, fixture, selector, workflow, or benchmark change is authorized or performed in this Review.

#### Primary evidence and independent arithmetic

- Source snapshot: `9f23dd290694c74edb21e7f80cec60824c594550`, ZIP SHA-256 `d46a2d0b07dca8a9011c854a18fa3dd4b75cf9ff6ed52571d11e5070754f91f6`; 5,784/5,784 source files and nested source archive verified. This is a review snapshot, **not** a replacement semantic source; CB26 semantic authority remains `e3d60337ed34538547d3a6d519bafae5b184330e`.
- TB28 immutable [run 39772864202](https://github.com/akashskypatel/Directional/actions/runs/39772864202), result artifact `12424484672`; independently re-hashed ZIP SHA-256 `a54110dbb5475b76e6b6a6baa8fc1b7dcabd7aa50c95c5b390532509d1c656e6`; SHA256SUMS verifies **1019/1019** files. Recorded immutable compiled package `12409939859` / `ee08279e537af4e99f287d28595df0ef639e632aa345bc0b1986bbb361ee86fa`.
- Independently parsed `combined-ledger.tsv` and all 497 archived per-case logs: distinct `(phase,ordinal)` 497/497; one `[ RUN ]` per exact test identity; PASS logs each contain one `[ OK ]` with no failed test, and RED logs a failing test; SHA-256 matches every log's ledger row. The separately published 497-row full ledger agrees on phase, ordinal, identity, owning executable, exit, verdict, and log hash. The 35-row RED inventory is exactly the RED subset.
- **30 focused30** 26 PASS/4 RED; **12 focused12** 12/0; **449 selector** 421/28; **6 cp3entry** 3/3. Total **462 PASS / 35 RED**. The TB21 inventory contains 48 RED identities; set subtraction yields exactly 13 RED→PASS: `focused30:6,20,24,25,26,27,28`, `selector:444,446,447,448`, `cp3entry:3,5`. TB28 RED ⊂ TB21 RED; **0 PASS→RED**. All 12 known seam family cases and selector:447 pass.
- Artifact `execution-boundary.txt` and `immutability.txt` record no compile, configure, relink, benchmark, package/mode repair, selector or fixture mutation; before/after source/package/execution-view censuses agree. No surviving RED log contains an A7 `UncertifiedCrossSheetBinding` rejection; this is **not** proof of unexecuted A7 negative paths.
- Selector-449 authority hash from RA-132 is `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`; frozen focused30, focused12 and routing receipts are rechecked in the archive's before/after censuses, not rewritten. The accepted CP2 491-case prefix is a **different earlier authority**, not a proven contiguous prefix of the CP3 selector; do not claim a nonexistent prefix hash relationship.

#### All 35 inherited REDs — observable classification, not invented root causes

This is a complete partition of the exact residual RED identity set, checked against each original log. Categories mark the **first observed failed stage/precondition**, not a claim that the underlying product cause is known. Every identity remains RED and non-promoted.

| First-failure family | Exact identities | Count | Disposition |
|---|---|---:|---|
| M1 validation precedence/transport | `focused30:3,22,23`; `selector:139,140,142,211,219,227,230` | 10 | RA-105 M1 candidate, defer causal specification to DEFN-M1; do not change expected typed rejection based on earlier fixture throw |
| Neighboring hard-rail / A5 prerequisites | `focused30:12`; `cp3entry:2` | 2 | Preserve failed certificate/producer preconditions; defer with M1 evidence without attributing either to M1 as proven root cause |
| Odd-gauge torus D2 | `cp3entry:1` | 1 | `oddFaceGaugePairs=0` from 5 candidates, while D2 requires delta 1 or 3. No relaxation; DEFN-T1 must determine attainable producer witness |
| Periodic product/fixture setup | `selector:189–195,220,221,296,302,304,439` | 13 | Most tests throw before their asserted negative oracle (`source A3 unavailable` or `direct periodic-owner product`); no false PASS or proof of those guards; restore fixture authority in separately reviewed work |
| Typed hard-feature front setup | `cp3entry:4` | 1 | Missing expected front; causal owner remains unresolved |
| Other inherited producer/test oracles | `selector:174,201,204,242,247,250,405,442` | 8 | Retain individual first-failure records and per-identity fixture-debt/correctness review; do not merge unlike failures into one cause |
| **Total** | **All 35, disjoint** | **35** | **Remain RED** |

The exact names, exits, SHA-256s and first failure for all 35 are retained in `Architecture_M6_CP3_TB28_Selector_497_Red_Inventory.tsv`. M1's prior candidate is **not** proof that the 10 failing products all share one fixed cause; e.g. three hard-rail pair tests fail in precondition reconstruction. The observed torus D2 receipt establishes **absence of a witness on this fixture**, not mathematical impossibility of nonzero face gauge. Selector:242/247 failures include expected Rejected versus actual Produced; these cannot be dismissed as cosmetic text drift. Selector:442 fails an atlas/singularity construction prerequisite. All 35 inherit TB21's red identity set, but first-failure text can change across packages; no shared causal assumption is made solely from membership.

#### Non-vacuity, obligations, and stable gate decision

RA-132 D3 and D7 tamper positives remain PASS in the 497 archive (`cp3entry:3/5`), and the 12 seam-family results cross the intended positive path. They establish their **specific tested constraints**, not universal certified-seam rejection coverage. CB27 is still required for RA-127.4b endpoint-coordinate/outside-wedge/same-side and RA-130 B4 unrelated-seam evidence, missing-certificate, and seam-direction sites; `cross-sheet:periodic` (RA-130.7) and nonzero-turn carrier obligations remain conditional on constructible witnesses. No new stable accepted-green loss is observed: **66 events / 17 categories / 49 recurrences**, witness debt **1** unchanged; CP2 **491/491 accepted**, R3 **403/497 rejected**, TB28 **462/497 candidate only**, RP-01 OPEN, RP-02 UNREACHED, Gate C suspended.

#### Exactly one authorized successor — Code + Build, test-only

`M6-CP3-CB27-RP01-A7-CERTIFIED-SEAM-NEGATIVE-ORACLES`. Scope **only** `tests/SurfaceCellTransitionQuotientTests.cpp`, preserving all source/fixture/selector/harness/workflow code. Implement the five RA-132.6 A7 negative cases using the D7 fixture and immutable A6 product: unrelated certificate transition on another same-sheet-pair seam rejects at `cross-sheet`; missing certificate rejects at `cross-sheet:no-certificate`; altered lattice endpoint and outside-wedge span each reject at `cross-sheet:seam-direction`; same-side only when it reaches the intended check, otherwise record the earlier per-member guard. Assert the exact A7 site and separately derived A6 disposition; keep intact the positive D3/D7 controls. **Falsifiers/STOP:** altered test preconditions cannot be constructed; tamper fails at an earlier unrelated stage; positive controls no longer produce the certified relation; rejection site differs; test has an early return/skip; any source/header/selector mutation is necessary. Stop and return to independent Review rather than weaken assertions or touch production. CB27 uses the authorized GMP/GMPXX eight-target compile-only dispatcher; no runtime in CB27; separate CB27-REV and TB29 required.

#### Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | n/a: CP3's frozen 497 composite is not a contiguous extension of accepted CP2 491; archive hashes and immutable before/after selector input checked, no new selector admitted |
| Decisive claims independently re-derived | 1019 result files, 5784 source files, 497 exact test logs/identities, per-case SHA, owner/verdict, 13/0 set differences, 35 disjoint REDs |
| Non-vacuity checked | D3/D7 are PASS and tamper-bearing; absent A7 negatives expressly carried |
| Prior obligations discharged/carried | RA-132 census/zero-regression and RA-130 B1 targeted verification discharged; RA-127.4b, RA-130 B4/B5 and RA-130.7 carried to CB27 or witness-dependent review; M1/D2/fixture debt retained |
| Stable accounting | 66/17/49, debt 1; accepted CP2 491/491; rejected R3 403/497; candidate TB28 462/497; frozen selector 497 |
| New candidates/obligations recorded | TB28 classified inherited-RED candidate in tracker; five CB27 negatives scoped; no stable events added |
| ORIENTATION currency line | Updated to RA-133/TB28 on 2026-10-22 |
| ORIENTATION §3 / §4 / §7 / §8 | §3 and §7 current; §4 witness matrix unchanged; §8 existing premature-credit/non-vacuity patterns apply, no new pattern |
| CHANGELOG | RA-133 review entry added |
| ROADMAP | CP3 candidate evidence updated; checkpoint still active |
| Selector manifest | n/a: no new selector or accepted promotion |
| LESSONS | Existing §1/§2 on evidence/non-vacuity and fixture authority cited; no new lesson |
| Consolidation under CLEAN_UP_POLICY | No newly superseded expendable record safe to fold; TB28 full ledger and RA-132 authority remain load-bearing; no removal |
| Successor frozen | `M6-CP3-CB27-RP01-A7-CERTIFIED-SEAM-NEGATIVE-ORACLES`, exact negatives/falsifiers above |
| Turn boundary held | Review-only, 0 runtime, 0 build, 0 code/test/selector changes |
| review_check.py boundary | Executed on verified source-snapshot-derived synthetic checkout: no product/test/fixture/selector mutations detected, but historical baseline/durable-source checks **FAIL (not verifiable)** because snapshot excludes actual Git ancestry. Independent live GitHub compare establishes rewrite baseline `8b7299b43` and semantic CB26 SHA `e3d60337` are ancestors, with no code/test/fixture/selector drift from CB26 to branch; independently compared all rewrite-baseline `DURABLE` headings to live branch, none missing. Full per-commit append-only history scan remains unverified; no synthetic-git PASS claimed. |
| STATUS lifecycle maintained | Started timestamp retained at `2026-10-22T12:47:53Z`; resume beacon written at `2026-10-22T14:22:26Z`. Final direct COMPLETE beacon is the last remote mutation of this Review. |
| Pushed to origin, branch in sync | Durable Drive application [run 39793881309](https://github.com/akashskypatel/Directional/actions/runs/39793881309) committed seven exact documentation paths at `38bd1c2aab146290024ddc3285ca66289eb8f032`; GitHub remote commit comparisons verified no additional review product/code changes. Cleanup removed the snapshot trigger and temporary manifest. Final branch HEAD checked via GitHub connector. `git status -sb` on a real checkout was unavailable because the verified Web snapshot excludes `.git`; a synthetic checkout cannot certify remote synchronization. |

## `Architecture_M6_CP3_DEFN_M1_Certificate_Pair_Binding_Precedence_20261023.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_DEFN_M1_Certificate_Pair_Binding_Precedence_20261023.md`; moved verbatim.

### DEFN-M1 — hard-rail certificate/consumer rejection precedence (2026-10-23)

**Turn:** `M6-CP3-DEFN-M1-RP01-CERTIFICATE-PAIR-BINDING-PRECEDENCE` (documents only). **Disposition: unresolved architecture stop; not an approved corrective CB.** Evidence: semantic source `4473e41e94a35f1bf189fa046e86bac92c7391fb`, inspected in exact snapshot `9e61f4c0765870c6db421357940966ded9f041b4`; TB29 artifact `12481556884`; RA-142 supersedes conflicting six-row scope in the plan/RA-141.

#### 1. First-rejection audit

1. A4 `SurfacePhaseFrontProduct::make` (`src/geometry/SurfaceCellTracing.cpp:8439+`) authenticates the A3/source inputs and certificate/rail domains before inspecting edge pairs. Its certificate loop at `8814–8841` checks indices, then `HardRail` kinds, **both** `oppositeEdge` values, **both** `railId`s, `first.route == certificate.route`, `second.route == certificate.route.reversed()`, and distinct source topology regions. Any disagreement returns `InvalidSourceAuthority` with site `certificate-pair-binding`.
2. The A4 per-edge `oppositeEdge` reciprocity check (`:9331–9353`) later returns `InvalidOppositeEdge`; the certificate check masks it for 211/219. A4 certificate endpoint/source attachments and A3 transition evidence continue after the pair-binding clause. Do not delete these certificate-authentication guards.
3. Once A4 publishes, A5 `SurfaceOccurrenceComplexProducer::produce` (`src/pipeline/RemeshPipeline.cpp:~4890–5090`) first verifies each HardRail route using `exact_interior_route_valid` (`HardRailRouteAuthorityInvalid` → adapter `InvalidHardRailAuthority`), then rail owner, cross-region, reciprocal reversed route, hard-feature carriers (`HardRailOwnerMismatch`/`HardRailRegionMismatch`/`HardRailRouteMismatch` → `InvalidHardRailTransport`), and only then constructs the placement/certificate evidence. A5's later certificate lookup requires exact edge pair, rail and first route (`:5040+`). A6 consumes A5 evidence; the adapter maps typed errors. RA-15, RA-16 §5 and RA-19 freeze this order.
4. `tests/SurfaceCellTransitionQuotientTests.cpp:2551–2563` `materialize` maps **every** rejected A4 construction to `InvalidPhaseFrontProduct`, obscuring an A5/pipeline code. Six TB29 failures measured `code=0;sourceAuthoritySite=certificate-pair-binding;certificate=0;rail=2`; four additional members are statically shown to reach that clause (RA-142.2). Their site strings were not measured.

#### 2. Frozen M1 ownership matrix (exactly ten)

| Identity | Tamper / tested behavior | Frozen first owner and outcome | Current first clause / evidence | Needed first rejection |
|---|---|---|---|---|
| `focused30:3` | Publish valid front, then missing/duplicate/malformed A5 relation endpoints | A5 `RelationEndpointMissing` / `UnownedRelation`, by variant | A4 `certificate-pair-binding` **measured** on fixture setup | Valid baseline passes A4; A5 `publish_records_for_validation` owns later tamper |
| `focused30:22` | Append duplicate step to first HardRail route | A5 `HardRailRouteAuthorityInvalid` or `InvalidHardRailAuthority`; adapter `InvalidHardRailAuthority` | A4 pair-binding **measured** | A5 `exact_interior_route_valid` before pair transport |
| `focused30:23` | Same route tamper; checks precedence | A5 route authority then adapter `InvalidHardRailAuthority` | A4 pair-binding **measured** | Same A5 route-authority clause; no transport preemption |
| `selector:139` | Change second route to a different pair's route | A5 strict pair reciprocity → `InvalidHardRailTransport` | A4 pair-binding **measured** | A5 `first.route != second.route.reversed()` |
| `selector:140` | Give the two sides differing rail IDs | A5 strict pair owner → `InvalidHardRailTransport` | A4 pair-binding **measured** | A5 rail-owner mismatch |
| `selector:142` | Give second route same (not reversed) orientation | A5 strict pair reciprocity → `InvalidHardRailTransport` | A4 pair-binding **measured** | A5 reversed-route mismatch |
| `selector:211` | Set opposite side `oppositeEdge` to itself | A4 `InvalidOppositeEdge` | A4 pair-binding **static**, TB code 0 | A4 global reciprocity before binding |
| `selector:219` | Set first `oppositeEdge` to −1 | A4 `InvalidOppositeEdge` | A4 pair-binding **static**, TB code 0 | A4 HardRail counterpart-required + reciprocity before binding |
| `selector:227` | Duplicate route's transition topology | A5/pipeline `InvalidHardRailAuthority` | A4 pair-binding **static**; adapter shows `InvalidPhaseFrontProduct` | A5 individual exact-route authority before pair check |
| `selector:230` | Substitute wrong interior-transition ID | A5/pipeline `InvalidHardRailAuthority` | A4 pair-binding **static**; adapter shows `InvalidPhaseFrontProduct` | A5 individual exact-route authority before pair check |

#### 3. Option audit and explicit stop

- **(a) Structural-first with typed A4 binding:** fixes `211/219`, but A4 still rejects the deliberately tampered fronts in `focused30:22/23` and `selector:227/230` *before* A5; `focused30:22/23` require A4 success. Typed A4 failure is not A5 authority.
- **(b) Binding-first with field-specific errors:** preserves A4 rejection but cannot satisfy those published-front assertions, and `materialize` masks the factory error. Merely aliasing the error name is insufficient and violates independent ownership.
- **(c) Defer A5-owned pair/route checks:** would enable A5 precedence and preserve the final pipeline's fail-closed behavior, **but** if A4 still returns an authoritative checked product on a mismatched `edge.route`/`railId`/`oppositeEdge` and certificate, the present A4 *edge-to-certificate binding invariant* is relaxed. A5's later certificate lookup rejects, but later rejection is not equivalent to A4's immutable product guarantee. No independently reviewed split between (i) A4 certificate authenticity and (ii) A5 edge-to-certificate association authorizes this weakening today.

**Decision:** no option is yet proven to satisfy *all ten*, **and** retain A4 certificate binding, without a test change or disabling a guard. Invoke RA-142.4/plan STOP: return to independent architectural Review before a corrective CB. Review must decide whether the checked A4 product type may explicitly represent *pending A5 binding*, with a separate non-consumable/untrusted state, or whether the frozen downstream test ownership and A4 product invariant require a higher-level contract change. Neither change is authorized by this DEFN.

#### 4. Non-weakening obligations (unresolved until Review approves an owner split)

| Forgery / invalidity | Required rejection and named guard |
|---|---|
| Missing certificate / duplicated or reordered pair indices | A4 `certificate-pair-indices` and missing/uniqueness guards |
| Forged certificate with wrong source attachment / A3 transition or source star | A4 source-attachment and A3-certificate checks; never infer certificates from untrusted edges |
| Wrong rail or counterpart identity | A4 `InvalidOppositeEdge` for broken opposite structure; A5 `HardRailOwnerMismatch` for unequal IDs; certificate-to-edge agreement remains mandatory before downstream acceptance |
| Reversed/mismatched route or invalid route topology | A5 `HardRailRouteMismatch` / `HardRailRouteAuthorityInvalid` with RA-15 route-before-pair precedence; exact certified route must still match prior to acceptance |
| Same source topology region across HardRail pair | A5 `HardRailRegionMismatch` or existing A4 binding; no same-region HardRail publication into A6 |

#### 5. Corrective TB predictions and falsifiers (conditional; no runtime executed)

- Ten M1 identities must meet the per-row frozen outcomes **without modifying selector/test expectations**; focused30:3 must publish its valid front and reach its independent A5 relation mutation, focused30:22/23 must publish their deliberately invalid-route drafts then reject in A5; 227/230 must not collapse to `InvalidPhaseFrontProduct`.
- The **seven non-M1 factory rows** remain separate: `selector:220,221,296,302,304,439` still reject at `face-gauge-missing`, `cp3entry:4` at `open-rail-chain`. The direct periodic-owner fixture (TQ:~358) does not supply face gauges; do not reinterpret it as evidence that the six are solved.
- All **nine TB29 controls** must continue to PASS; A7/D3/D7 negative controls must remain non-vacuous; A4 forged/absent certificates must still fail. A published A4 product with unchecked certificate binding, any lost A5 guard, any changed frozen error, or unexpected green from a malformed input **falsifies** a proposed contract.
- Preserve stable **66/17/49**, witness debt **1**, CP2 **491/491 accepted**, R3 **403/497 rejected**, TB28 **462/497 candidate only**, RP-01 open, RP-02 unreached, Gate C suspended. The 44-case TB29 is diagnostic, not acceptance.

#### 6. Exclusions and distinct owners

- `selector:220,221,296,302,304,439` → A4/A6 source-face-gauge/certificate owner (separate DEFN). `cp3entry:4` → A4 open-rail-chain owner.
- `selector:189–195` → A3 cycle-locus provenance; `selector:442` → A3 singularity/fixture authority. `focused30:12` → A5 occurrence HardRail transport/relabelled gauge owner.
- `cp3entry:1/2` → independent producer-witness owners (periodic odd gauge / hard-rail midline). The other **nine** untyped rows (excluding 211/219/227/230) → separate first-failure/call-site classification. `DEFN-T1`/fixture debt/497 census/`DIAG-RETAIN` remain later Review-sequenced tasks.

**Next boundary:** independent Review of this incompatibility; **no** code, tests, selector, build, TB, fixture, or successor work authorized by this stopped definition.

## `Architecture_M6_CP3_DEFN_M1_Certificate_Pair_Binding_Precedence_Review_Decision_20261023.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_DEFN_M1_Certificate_Pair_Binding_Precedence_Review_Decision_20261023.md`; moved verbatim.

### RA-143 — DEFN-M1 architecture block resolved: A4 authenticates hard-rail certificates; A5 binds edges to them (2026-10-23)

**Turn:** `M6-CP3-DEFN-M1-RP01-CERTIFICATE-PAIR-BINDING-PRECEDENCE-REV`. **Input:** DEFN-M1 `BLOCKED` (`Architecture_M6_CP3_DEFN_M1_Certificate_Pair_Binding_Precedence_20261023.md`).

**Verdict:** the DEFN's clause audit, ten-row matrix, non-weakening table and predictions are **accepted**. It stopped on one open question: can A4 publish a product whose hard-rail edges are not yet bound to their certificates? Review resolves it:
- **Yes**, for exactly five association predicates, because the frozen contracts make A5 their owner and A5 already enforces each one before any consumer uses those edges.
- A4 keeps every **authenticity** check.
- This is option (c), with an evidence-based owner split. It is not a weakening.

#### RA-143.1 Why A5 is the owner (frozen authority)

- **RA-15 (normative)** pins the order inside A5 (RA-16 §5):
  - first, individual hard-rail route authority, with failures surfacing as `InvalidHardRailAuthority`;
  - then pair owner, region and reversed-route checks, with failures as `InvalidHardRailTransport` (it names `selector:139/142`);
  - no divergent duplicate route semantics elsewhere (RA-15.4).
- **RA-40.1** requires A4 to **authenticate certificate values** against the bound atlas. It says nothing about A4 binding edges to certificates.
- **R2's pair-binding clause** (`80fc1688f`, 2026-10-08, from the CP3-entry R2 work that was later rejected at 444/497) added that association to A4. RA-105.3 already recorded that it preempts the frozen precedence. No frozen definition makes A4 the owner of association.
- **A5 already enforces association** (RP:5040–5051). It looks up a certificate with `firstFrontEdge == edge`, `secondFrontEdge == edge.oppositeEdge`, `rail == railId` and `route == edge.route`, and otherwise fails `HardRailRouteAuthorityInvalid`. It runs **after** the RA-15 checks, as the frozen order requires: route authority (RP:4904–4909) → owner (RP:4917) → region (RP:4921) → reversed route (RP:4924–4925) → certificate lookup (RP:5050). RP:5040 states it explicitly: *"A4, not A5, owns route traversal, endpoint attachment and A3 tau."*
- **The only consumers** of `hardRailRouteCertificates()` are A5's lookup (RP:5042–5049) and a hash (RP:2110–2114). No consumer relies on A4-side association.

#### RA-143.2 The split (binding)

| Predicate in SCT:8831–8841 | Owner after CB29 | First rejection for the M1 tamper |
|---|---|---|
| index range (`certificate-pair-indices`, SCT:8820–8827) | **A4 (kept)** | unchanged |
| both referenced edges are `HardRail` | **A4 (kept)**, site `certificate-pair-binding` | unchanged |
| `first.oppositeEdge == secondFrontEdge`, `second.oppositeEdge == firstFrontEdge` | **A4 structural reciprocity** `InvalidOppositeEdge` (SCT:≈9331–9353), plus the A5 lookup | `selector:211/219` → `InvalidOppositeEdge` |
| `first/second.railId == certificate.rail` | **A5** owner mismatch → `InvalidHardRailTransport`, plus the lookup | `selector:140` |
| `first.route == route`, `second.route == route.reversed()` | **A5** RA-15 route authority, then reversed-route check, plus the lookup | `focused30:3, 22, 23`, `selector:227, 230` → `InvalidHardRailAuthority`; `selector:139, 142` → `InvalidHardRailTransport` |
| `first.sourceTopologyRegion != second.sourceTopologyRegion` | **A5** `HardRailRegionMismatch` → `InvalidHardRailTransport` | none of the ten; kept rejecting downstream |
| certificate attachments, route length, junctions, open/closed interval, endpoints, A3 tau (SCT:8842–8960+) | **A4 (kept)**; these read the certificate's own data (the attachments compare against the edges' `from`/`to` faces, which no M1 tamper changes) | unchanged |

**Product contract after CB29:** a published `SurfacePhaseFrontProduct` guarantees structurally valid edges, including reciprocal `oppositeEdge`, and **authentic** certificates. Whether hard-rail edges match those certificates is an A5 admission predicate, checked before A6 or A7 can consume them. No new type state is needed, because A5 is the binding gate.

**Non-weakening:** every input that R2 rejected is still rejected end to end:
- a forged certificate value: A4 authenticity;
- a broken opposite structure: A4 `InvalidOppositeEdge`;
- a bad route: A5 route authority;
- a pair mismatch: A5 transport;
- any remaining edge-to-certificate mismatch: A5 `HardRailRouteAuthorityInvalid`.

The rejecting stage changes only for those five predicates, and only toward the frozen owner.

**No currently passing test depends on A4 association.** Every test asserting `InvalidSourceAuthority` was checked (SP10:7388–7531, TQ:1972–2244, 2872–2916, 3058–3081, 3084–3354). Each tampers certificate data, face gauges, tau or rail terminals, never edge-to-certificate fields.

#### RA-143.3 Successor `M6-CP3-CB29-RP01-A4-CERTIFICATE-ASSOCIATION-OWNERSHIP` (Code + Build, compile only)

- **File:** `src/geometry/SurfaceCellTracing.cpp` only.
- **Change:** in the certificate loop's pair clause (SCT:8831–8841), remove the five association predicates (both `oppositeEdge`, both `railId`, both route comparisons, the region inequality). Keep the two `HardRail` kind checks with the same site.
- **Comment:** add one comment citing RA-15/RA-16 §5/RA-143 for the ownership.
- **No other change:** RP (A5 already enforces), tests, selectors and workflows are untouched. Lines at most 100 columns.
- **Build:** compile the eight targets with GMP/GMPXX, `runtimeExecution=false`. Record `Architecture_M6_CP3_CB29_A4_Certificate_Association_Ownership_Code_Build_Record_20261023.md` (at most 30 lines).
- **STOP** if a later A4 clause in the same loop reads one of the removed fields assuming it was bound, or if any edit is needed outside that clause.

#### RA-143.4 TB30 plan (manifest issued at CB29-REV)

Targeted harness (`436f5fff…c9a`) with a Review-owned manifest:
- the **10 M1 rows**, expected to reach their frozen outcomes (PASS);
- the **7 non-M1 factory rows**, expected unchanged (still RED at `face-gauge-missing` / `open-rail-chain`);
- the **9 TB29 controls**;
- **3 certificate-authenticity guards:**
  - `SurfaceCellAuthorityContractCutover.ProducedOpenRailInteriorEndpointPreservesExactTerminalGuard`;
  - `…CheckedFactoryRejectsOpenRailWithClearedTerminalAnchor`;
  - `…ProducedOpenRailInteriorVertexEndpointRejectsForgedTags`.

**Falsifiers:**
- an M1 row still fails at A4, or with a non-frozen code;
- an authenticity guard turns RED;
- a control turns RED;
- a non-M1 factory row changes its typed reason.

A census follows with an RA-139.3-compliant harness (RA-139.5).

#### RA-143.5 Sequence and accounting

- **Sequence:** DEFN-M1 (blocked) → DEFN-M1-REV (this; the contract accepted with resolution) → **CB29** → CB29-REV (static diff, issues the TB30 manifest) → TB30 → TB30-REV → owners for face-gauge-missing (6), A3 cycle locus (7) / `selector:442`, A5 `focused30:12` (each DEFN or diagnostic first) → DEFN-T1 (`cp3entry:1/2`) → fixture debt → census (RA-139.5) → RP-01 Review. `DEFN-SEAM-NZ` and the Periodic follow-up each wait for a witness. `DIAG-RETAIN` is scheduled clear of RP-01 turns.
- **Accounting (unchanged):** stable 66/17/49, debt 1, CP2 491/491; R3 403/497 rejected; TB28 462/497 candidate; selector 497 frozen. `RP-01` open, `RP-02` UNREACHED, Gate C suspended.

| Duty | Answer |
|---|---|
| Decisive claims re-derived | R2 clause (SCT:8820–8841) and the post-clause checks; A5 lookup and comment (RP:5040–5051); consumer search; RA-15, RA-16 §5, RA-40.1, RA-105.3; origin of `80fc1688f`; the focused30:3 tamper; all `InvalidSourceAuthority` test expectations |
| Non-vacuity | Per-predicate owner mapping with frozen codes; authenticity guards and controls named for TB30 |
| Obligations | DEFN-M1 accepted; its STOP resolved; RA-142.4 discharged |
| Durable docs | Handoff, TODO, tracker, CHANGELOG, ORIENTATION, Frozen Definitions index |
| Boundary | Review-only; no source, test, selector, workflow or runtime change |

## `Architecture_M6_CP3_TB29H_RP02_Review_Audit_Decision_20261023.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_TB29H_RP02_Review_Audit_Decision_20261023.md`; moved verbatim.

### RA-140 — Audit of the RP02 harness review: acceptance upheld and validated on real GoogleTest logs; TB29 released with complete inputs (2026-10-23)

**Turn:** `M6-CP3-TB29H-RP02-TARGETED-ARTIFACT-HARNESS-CORRECTION-REV-AUDIT` (independent audit of the RP02 review, `Architecture_M6_CP3_TB29H_RP02_Harness_Correction_Review_Decision_20261023.md`).

**Verdict:**
- **Upheld:** the RP02 review's acceptance of the corrected harness (SHA-256 `436f5fff…c9a`) and its release of TB29.
- **Gap closed:** that review's acceptance of H1 and H6 rested on **synthetic** logs only. This audit runs the harness's exact functions over **real** GoogleTest logs from TB28 and TB27. The 600-second kill path (H4) is still verified by reading the code, not by a run; TB29 itself would reveal a timeout as INVALID.
- **Inputs completed:** the TB29 inputs had no root-manifest or source-archive hash. Both are derived from the package here.
- **No defect requires another harness turn.**

#### RA-140.1 Reproduced

- Harness SHA-256 `436f5fff9c3bec97457f4bc6b7c2b6182cb3f47707eb14a66af3b6a3f3dc3c9a` matches.
- `bash -n` passes; `--self-test` prints `SELF_TEST_PASS cases=12`.
- `--self-check Architecture_M6_CP3_TB29_Targeted_Case_Manifest.tsv 44` prints `SELF_CHECK_PASS cases=44`.
- Every RA-139 point is present in the code:
  - **H1:** `classify_case` gives RED only for one RUN, the unadorned `[  FAILED  ] <test>` line and exit 1;
  - **H2:** `read_cases` enforces `EXPECTED_CASE_COUNT`;
  - **H3:** the A5 pattern keeps hyphens;
  - **H4:** `Popen(start_new_session=True)`, `killpg`, then reap;
  - **H5:** `time -o resources/<row>.time.txt`;
  - **H6:** `failure_block` scoping.

#### RA-140.2 Real-log validation (new evidence)

The classifier and extractors, taken verbatim from the harness, were run on archived logs:

| Input | Expected | Observed |
|---|---|---|
| TB28 result `12424484672`: the 35 RED logs, with their recorded exit codes | RED | **35/35 RED**; a first failure line found in 35/35 |
| TB27 result `12420676412`: the 21 PASS logs | PASS | **21/21 PASS** |

This matters because the RED rule depends on GoogleTest's unadorned summary line `[  FAILED  ] Suite.Test`; the per-test line carries a `(N ms)` suffix. Real logs confirm the binaries print it. If they did not, every TB29 RED would be INVALID and the run would fail outright.

#### RA-140.3 TB29 inputs (complete; derived from package `12465330920`)

| Input | Value |
|---|---|
| `CANDIDATE_ARTIFACT_ID` | `12465330920` (expires **2026-10-29T22:54:39Z**) |
| `EXPECTED_SOURCE_SHA` | `4473e41e94a35f1bf189fa046e86bac92c7391fb` (`metadata/source-commit.txt` matches) |
| `EXPECTED_CANDIDATE_ZIP_SHA256` | `da56650a18f99443abf5f721620bb00fd5701dd1e660741da9aafb924a6dfbf5` |
| `EXPECTED_ROOT_MANIFEST_SHA256` | `e6149577b0bb240efadd4bc47638ffd3b1441d6f99664542fa66b368df35454b` (28 entries) |
| `EXPECTED_SOURCE_ARCHIVE_SHA256` | `d06d8484b98ffedfb38d99ebf38deee960d170e7d7fa3011f51453249e61371e` (matches its manifest entry) |
| `CASE_MANIFEST` | `.agents/Directional/Architecture_M6_CP3_TB29_Targeted_Case_Manifest.tsv` |
| `CASE_MANIFEST_SHA256` | `39fa5eb83e2da1b0668bc7368c5304011ec13de8804c54a2a3466f927c42d236` |
| `EXPECTED_CASE_COUNT` | `44` |
| Harness | `.agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh`, SHA-256 `436f5fff9c3bec97457f4bc6b7c2b6182cb3f47707eb14a66af3b6a3f3dc3c9a` |

**TB29 deliverables:**
- the immutable result artifact with a verified `SHA256SUMS`;
- a report, `Architecture_M6_CP3_TB29_Typed_Factory_Cause_Harvest_Report_20261023.md`, containing:
  - all 44 verdicts;
  - the 9 controls PASS;
  - every RED's `typed_reason` and first failure;
  - an attribution table of the 35 REDs by first failing component and typed reason, with counts summing to 35;
  - any `unexpected_pass` or `INVALID` row, listed explicitly.

#### RA-140.4 What TB29-REV must decide (pre-registered)

1. **M1's measured scope.** Group the factory rows (`focused30:3, 22, 23`; `selector:139, 140, 142, 211, 219, 220, 221, 296, 302, 304, 439`; `cp3entry:4`) by factory code and `sourceAuthoritySite`. DEFN-M1 covers exactly the rows whose clause is RA-105.3's R2 certificate binding. Rows rejected by another clause get their own owner.
2. **A3 periodic route** (`selector:189–195`): the atlas code and locus decide between fixture debt and a product owner.
3. **`focused30:12`:** the A5 code and site.
4. **The rest stay as RA-134.2 classified them,** unless new text contradicts that.

#### RA-140.5 Sequence and accounting

- **Sequence:** audit (this) → **TB29** → TB29-REV → DEFN-M1 (evidence-scoped) → DEFN-M1-REV → corrective CB/TB → DEFN-T1 → fixture debt → census (needs an RA-139.3-compliant harness, RA-139.5) → RP-01 Review. If package `12465330920` lapses before TB29 runs, Review issues a recompile-only CB of `4473e41e9`. `DEFN-SEAM-NZ` and the Periodic follow-up each wait for a witness. `DIAG-RETAIN` is scheduled clear of RP-01 turns.
- **Accounting (unchanged):** stable 66/17/49, debt 1, CP2 491/491; R3 403/497 rejected; TB28 462/497 candidate; selector 497 frozen. `RP-01` open, `RP-02` UNREACHED, Gate C suspended.

| Duty | Answer |
|---|---|
| Decisive claims re-derived | Harness SHA; `bash -n`, self-test, self-check; H1–H6 in code; the classifier and extractors run over 35 real RED and 21 real PASS logs; package ZIP, root manifest, source archive and source commit |
| Non-vacuity | The real-log run closes the synthetic-only limit for H1/H6; H4 remains static |
| Obligations | RA-139 discharged; RA-139.5 (census harness) carried; TB29-REV decisions pre-registered |
| Durable docs | Handoff, TODO, tracker, CHANGELOG, ORIENTATION, Frozen Definitions index |
| Boundary | Review-only; no source, test, harness, manifest, selector, workflow or Directional runtime change |

## `Architecture_M6_CP3_TB29H_Review_Audit_Decision_20261023.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_TB29H_Review_Audit_Decision_20261023.md`; moved verbatim.

### RA-139 — Audit of the TB29H review (RA-138): H1–H3 upheld; three further harness defects; built-in self-test required; census harness shares H1 (2026-10-23)

**Turn:** `M6-CP3-TB29H-RP01-TARGETED-ARTIFACT-HARNESS-REV-AUDIT` (independent audit of RA-138).

**Verdict:**
- **Upheld:** RA-138's three findings and its hold on TB29.
- **Amended:** the correction turn `M6-CP3-TB29H-RP02-TARGETED-ARTIFACT-HARNESS-CORRECTION` gains three defects (H4–H6). Its "static synthetic probes" become a **built-in `--self-test` mode**, so every later review can re-run them on the exact harness bytes.
- **Carried:** RA-138 did not record that the 497 census harness has the same RED/INVALID conflation as H1.

#### RA-139.1 Re-verified

- **Hashes:** harness `be3db020…b412` and manifest `39fa5eb8…d236` match.
- **H1** (lines 217–218): any non-zero exit with one `[ RUN ]` and no `[ OK ]` is classified `RED`. A crash, kill or timeout after RUN is therefore accepted as a test failure. Confirmed.
- **H2** (lines 47–68): `read_cases` enforces no expected count. Confirmed. At execute time the SHA input pins the bytes; the `--self-check` mode has no such pin.
- **H3** (line 110): `A5:[A-Za-z][A-Za-z0-9_]*` truncates the helper's hyphenated causes, such as `A5:no-produced-certified-ordinary-seam` (TQ:2810–2827). Confirmed.
- **The GMP preflight is sound.** Lines 191–193 require `libgmp` for every manifest binary. Both binaries in the CB28A package (`12465330920`, ZIP `da56650a…dfbf5` re-hashed) list `libgmp.so.10` in their ELF `DT_NEEDED` (authority kernel: `libgmp`; producer: `libgmpxx`, `libgmp`). No change needed.
- **Extractor on real data.** I ran it over the 35 TB28 RED logs: `selector:442` → `code=SingularityMismatch;sourceEdge=(2,3)`, the other 34 → `reason-not-observed`. No match came from text before the failure line. TB28's logs predate CB28's messages, so this bounds the H6 risk; it does not refute it.

#### RA-139.2 Further defects (binding on RP02)

- **H4 (high) — a timeout leaves the test running.**
  - Line 206 runs `/usr/bin/time … <binary>` with `timeout=600`. On expiry, `subprocess.run` kills only its direct child, `time`. The test binary, a grandchild, keeps running with the log file still open.
  - That process can append to `raw/<row>.log` after line 228 has hashed it, so the ledger's `log_sha256` and the final `SHA256SUMS` disagree. It also competes for CPU with later cases, causing further timeouts.
  - **Required:** start each case in its own process group (`start_new_session=True`). On timeout, `os.killpg(…, SIGKILL)` and reap it before the log is read. The case is then `INVALID` (H1).
- **H5 (low) — timing output is mixed into the test log.**
  - `/usr/bin/time -v` without `-o` merges its resource report into the test log. The 497 harness writes it to a separate file (`-o`, lines 299–301).
  - This makes TB29's raw logs differ in content from TB28's, which TB29-REV must compare, and it puts the full command line into the text the extractors scan.
  - **Required:** `-o resources/<row>.time.txt`, with that file listed in `SHA256SUMS`.
- **H6 (medium) — reasons are read from the whole log.**
  - `typed_reason` and `first_failure` scan the entire log, so text printed before the failure can be reported as its cause.
  - **Required:** extract both from the **first failure block only**: from the first `: Failure` or `unknown file: Failure` line up to the next `[  FAILED  ]` line, or end of file. Record `reason-not-observed` if that block has no typed reason.

#### RA-139.3 H1 classification rule (made precise)

| Verdict | Condition |
|---|---|
| `PASS` | exit 0, exactly one `[ RUN ]` and one `[       OK ] <test>`, no SKIPPED, no FAILED |
| `RED` | exactly one `[ RUN ]`, exactly one `[  FAILED  ] <test>` terminal line naming the same test, no OK or SKIPPED, exit 1 |
| `INVALID` | anything else: timeout, signal or crash (no FAILED line), zero or several RUN, a skip, or a mismatched name |

An `INVALID` row counts as missing, so the harness exits non-zero after publishing evidence (existing gate, line 235).

#### RA-139.4 Built-in `--self-test` (replaces ad-hoc probes)

A `--self-test` mode feeds **embedded synthetic logs** through the same classifier and extractor functions used in execution, and exits 0 only if every expectation holds. Minimum cases:

1. genuine PASS → `PASS`;
2. genuine failure with a `[  FAILED  ]` terminal → `RED`;
3. RUN then crash, no terminal → `INVALID`;
4. RUN then the timeout marker → `INVALID`;
5. a SKIPPED test → `INVALID`;
6. zero RUN → `INVALID`;
7. a factory reason in the failure block → `code=<int>;sourceAuthoritySite=…`;
8. an atlas reason → `code=<Name>;sourceEdge=(a,b)`;
9. `A5:InvalidX;site=…`, retained whole;
10. `A5:no-produced-certified-ordinary-seam`, retained whole (H3);
11. a `site=` line **before** the failure plus a factory reason inside it → the failure-block reason (H6);
12. a failure block with no typed text → `reason-not-observed`.

**Count gate (H2):** `--self-check <manifest> <expected-count>` and an execute-time `EXPECTED_CASE_COUNT` input (allowed by the workflow's key rules). It must reject a 1-row and a 43-row copy of the manifest when 44 is expected.

#### RA-139.5 Carried obligation — census harness

`m6_cp3_entry_497_artifact_only_harness.sh` (SHA-256 `947a95ee…79dd`) sets `result=RED` unless the run is a PASS (lines 311–312), so it has the same H1 defect. TB28's 35 REDs are unaffected: every one of them has a GoogleTest failure line. The **next census** must use a harness with the RA-139.3 rule: either the corrected targeted harness with a 497-row manifest, or a separately reviewed fix of the census harness. That decision is due at the Review that schedules the next census.

#### RA-139.6 Sequence and accounting

- **Sequence:** audit (this) → **TB29H-RP02** (H1–H6, `--self-test`, count gate) → RP02-REV (re-runs `bash -n`, `py_compile`, `--self-check` and `--self-test` on the new SHA) → TB29 (resumed) → TB29-REV → DEFN-M1 → DEFN-M1-REV → corrective CB/TB → DEFN-T1 → fixture debt → census (RA-139.5) → RP-01 Review. `DEFN-SEAM-NZ` and the Periodic follow-up each wait for a witness. `DIAG-RETAIN` is scheduled clear of RP-01 turns.
- **Expiry contingency:** the CB28A package expires **2026-10-29T22:54:39Z**. If TB29 cannot start before then, the next Review issues a recompile-only CB of source `4473e41e9` (no source change) and updates the TB29 inputs. The manifest is unaffected.
- **Accounting (unchanged):** stable 66/17/49, debt 1, CP2 491/491; R3 403/497 rejected; TB28 462/497 candidate; selector 497 frozen. `RP-01` open, `RP-02` UNREACHED, Gate C suspended.

| Duty | Answer |
|---|---|
| Decisive claims re-derived | Harness and manifest SHA; H1–H3 at the cited lines; the timeout/process-tree behaviour of `subprocess.run`; 497-harness `time -o` and RED rule; workflow env-key rules; ELF `DT_NEEDED` of both packaged binaries; the extractor run over the 35 TB28 logs |
| Non-vacuity | `--self-test` makes each verdict and extractor rule executable on the exact harness bytes |
| Obligations | RA-138 H1–H3 carried; H4–H6 added; census-harness H1 carried; expiry contingency stated |
| Durable docs | Handoff, TODO, tracker, CHANGELOG, ORIENTATION, Frozen Definitions index |
| Boundary | Review-only; no source, test, harness, manifest, selector, workflow or runtime change |

## `Architecture_M6_CP3_TB29H_Targeted_Harness_Review_Decision_20261023.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_TB29H_Targeted_Harness_Review_Decision_20261023.md`; moved verbatim.

### RA-138 — TB29H targeted artifact harness independent review (2026-10-23)

**Turn:** `M6-CP3-TB29H-RP01-TARGETED-ARTIFACT-HARNESS-REV`. **Verdict: REJECT runtime authorization.** Control-plane harness is syntactically valid and the frozen 44-case manifest is correct, but the evidence classifier can falsely report a failed test that never terminated as a valid RED. This is a **harness evidence-integrity** finding, not a product regression, and does not change accepted CP2, selector497 or TB28 accounting. **TB29 must not execute.**

#### Authority and independent checks

- Exact-source snapshot `bdc8baee2321a2c5f7c65d8668feeb9cbeb73fdc`, GitHub run `39891305104`, artifact `12474942030`; source archive SHA-256 `39bc56b409f1b872c50b1e1144988857057e9a25254928a45f5686474c416652`; 5801/5801 source checksums. Snapshot adds only the STATUS/CI trigger after the TB29H implementation.
- SHA-256 recomputed: harness `be3db020d5292a7ecb3851d4e662cadb08696e4dd1befe0e159c920069b9b412`; manifest `39fa5eb83e2da1b0668bc7368c5304011ec13de8804c54a2a3466f927c42d236`; TB27 reference harness `5e3ca0a7c513d5373ee200b2442af315d7845d2dce81c6ea71b971ccbff2fe1f`.
- Parsed and checked 44 unique test/identity rows, exactly 4 NEGATIVE / 2 POSITIVE / 3 GUARD / 35 RED, 43 producer-binary / 1 authority-kernel-binary. All 44 named `TEST(suite,name)` identities exist in the snapshotted test sources; the inherited 35-row inventory has 35 entries. No selector modification or accepted-green loss.
- `bash -n`: PASS. Extracted embedded Python `py_compile`: PASS. `--self-check` on frozen manifest: PASS 44. Duplicate-identity copy: REJECTED. Unknown-kind copy: REJECTED. These checks were independent repeats, not proof of runtime behavior.
- Multi-binary lookup, seven environment/hash inputs, `unzip` executable modes, package/source and staged view postflight, per-row process invocation and evidence-before-exit structure were inspected. No Directional test binary, compile, relink or benchmark executed.

#### Blocking harness defects

**RA-138-H1 (high, correction required): interrupted tests can be accepted as RED.** In `tools/m6_cp3_targeted_artifact_harness.sh` lines 202–226, `TimeoutExpired` becomes exit=124; a case with one `[ RUN ]`, zero `[ OK ]` and zero `[ SKIPPED ]` is classified `RED` for *any* nonzero exit, even if the log contains only `HARNESS_TIMEOUT 600s` or `Segmentation fault`, with no GoogleTest terminal failure. On a RED-kind manifest row, `control_bad` remains zero, `missing` remains zero and the final gate can exit success. Reproduced by evaluating the unchanged classification expression against synthetic logs: semantic test failure exit=1 -> RED; timeout exit=124 -> RED; crash exit=139 -> RED. No binaries were executed for this proof. The required distinction is **completed failing assertion vs incomplete/abnormal execution**. **Falsifier:** any timeout, killed process, crash or missing terminal GoogleTest outcome must be `INVALID` and cause a nonzero harness exit with raw evidence retained, even when one RUN marker exists; a genuine one-test GoogleTest failure remains RED; a genuine PASS remains PASS. Preserve `reason-not-observed` when a complete RED has no typed diagnostic.

**RA-138-H2 (medium, correction required): manifest self-check does not enforce a declared count.** `read_cases()` checks nonempty/uniqueness but accepts a single valid data row; confirmed `SELF_CHECK_PASS cases=1` against a 1-row prefix of the canonical manifest. RA-137.3 explicitly required count validation. Make expected count a reusable, review-authoritative input to self-check and execute-time preflight (44 for TB29), or another independently equivalent count commitment in addition to full-file SHA. **Falsifier:** a 43-row or 1-row otherwise syntactically valid file must fail when expected count is 44; a future separately reviewed manifest with a different declared count must remain supported. Keep frozen manifest bytes unchanged.

**RA-138-H3 (medium, diagnostic correctness): incomplete A5 reason parsing.** `typed_reason()` lines 105–119 captures `A5:[A-Za-z][A-Za-z0-9_]*`, truncating hyphenated source-generated messages such as `A5:no-produced-certified-ordinary-seam` (`tests/SurfaceCellTransitionQuotientTests.cpp` lines 2810–2827) to `A5:no`. The specific enum-derived A5 codes are camel-case and unaffected; fallback typed diagnostic text is not. **Falsifier:** complete A5 code/site is retained for both enum names and hyphenated diagnostic reasons, without reading the test's expected assertion as a fabricated observed producer reason.

#### Authorized successor and stop rules

**Only next:** `M6-CP3-TB29H-RP02-TARGETED-ARTIFACT-HARNESS-CORRECTION` (control-plane Code + Build). Repair H1–H3 minimally in the reusable harness, add static synthetic log/verdict and count probes, rerun `bash -n`, Python compilation and positive/negative self-check; no Directional binary, build, product/test/fixture/selector/manifest/workflow change. Commit with exact new harness SHA; independent RP02-REV follows. TB29 remains held pending Review acceptance of the corrected SHA. Stop and return to Review if any proposal requires changing the frozen case manifest, execution semantics or TB29 scope. Preserve CB28A artifact `12465330920` expiry `2026-10-29T22:54:39Z`.

#### Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | n/a: selector497 unchanged and unpromoted; manifest independently hashed at SHA-256 above |
| Decisive claims independently re-derived | 44 rows/owners, 5801/5801 source checksums, harness/manifest/reference SHA; static syntax and negative proofs; synthetic verdict counterexamples |
| Non-vacuity checked | Timed-out/crashed one-RUN logs incorrectly accepted as RED; 1-row manifest incorrectly accepted by self-check |
| Prior obligations discharged/carried | RA-137.1 guard trio and 44-row manifest confirmed; RA-137.3 harness acceptance carried as H1–H3 to RP02 |
| Stable accounting | unchanged 66/17/49, debt 1; accepted CP2 491/491; frozen selector497, TB28 462/497 candidate |
| New candidates/obligations recorded | RA-138-H1–H3; tracker entry, next CB owner |
| ORIENTATION currency line | updated to RA-138 and 2026-10-23 |
| ORIENTATION §3 / §4 / §7 / §8 | §3/§7/§8 updated; §4 n/a, no witness changed |
| CHANGELOG | review decision recorded |
| ROADMAP | n/a: M6-CP3 still open; no checkpoint transition |
| Selector manifest | n/a: no accepted selector or new selector |
| LESSONS | existing evidence/verification principles cited; no generalizable new category beyond test terminal classification |
| Consolidation under CLEAN_UP_POLICY | no current per-turn source folded: TB29H code-build report is live correction baseline; prior historical documents retain review references; no unsafe deletions |
| Successor frozen | RP02 harness correction, exact H1–H3 falsifiers above; independent RP02-REV before TB29 |
| Turn boundary held | runtime-free; no product/test/selector changes |
| review_check.py boundary | local snapshot execution failed: no Git history for ancestry checks; not claimed PASS; structural diff/turn boundary manually inspected |
| `STATUS` lifecycle maintained | entry written; completion beacon final repository write after durable patch publication |
| Pushed to origin, branch in sync | pending remote patch apply verification; do not claim before evidence |

## `Architecture_M6_CP3_TB29_Harness_Authorization_Design_Review_Decision_20261023.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_TB29_Harness_Authorization_Design_Review_Decision_20261023.md`; moved verbatim.

### RA-137 — TB29 block resolved: Review owns the case manifest; one reusable targeted harness (TB29H) before TB29 (2026-10-23)

**Turn:** `M6-CP3-TB29-RP01-HARNESS-AUTHORIZATION-DESIGN-REV`. **Input:** TB29 `BLOCKED` (`Architecture_M6_CP3_TB29_Prerequisite_Stop_20261023.md`); TB29 plan (`Architecture_M6_CP3_TB29_Typed_Factory_Cause_Harvest_Plan_20261022.md`).

**Verdict:** the stop was correct. The plan requires a new 44-identity harness, made and reviewed in its own Code + Build turn, and the TB turn may not write it.
- **The design gap:** each targeted TB has written its own single-use harness with hard-coded package values and cases (TB26, TB27). Selection logic and execution logic then get reviewed together, or not at all.
- **Resolution, separating the two concerns:**
  - **Review owns *what* is measured.** This Review publishes TB29's case manifest as a reviewed, hashed data file.
  - **The implementation agent owns *how* it runs.** One reusable, input-driven targeted harness (TB29H), reviewed once, statically.

  Future targeted TBs then need only a Review-issued manifest, with no new harness code.

#### RA-137.1 Plan corrections (binding)

- **Guard trio.** The plan swapped `M6CP1.A7CrossSheetBindingRequiresConnectingIsolationTransition` for `M6CP2.A7ThreeSheetPartialConnectivityRejects`. RA-136.4 means RA-130.9's three guards, the ones TB27 ran (rows 19–21):
  - `M6CP1.A7CrossSheetBindingRequiresConnectingIsolationTransition`;
  - `M6CP2.A7WedgeTransitionWrongRegionRejects`;
  - `M6CP2.A7WedgeTransitionTouchWithoutConnectivityRejects`.

  The first is the guard closest to the changed A7 cross-sheet branch. The substitution is withdrawn.
- **Binaries.** All nine non-RED identities are in `SurfaceCellTransitionQuotientTests.cpp` and therefore in `directional_surface_cell_producer_tests` (`cmake/DirectionalTests.cmake:89–96`). The 35 REDs carry their TB28 owners: 34 in `directional_surface_cell_producer_tests`, and `selector:442` in `directional_surface_cell_authority_kernel_tests`. The TB27 harness hard-codes one binary, so it cannot run this set.

#### RA-137.2 Case manifest (Review-owned, frozen by hash)

`Architecture_M6_CP3_TB29_Targeted_Case_Manifest.tsv`, SHA-256 **`39fa5eb83e2da1b0668bc7368c5304011ec13de8804c54a2a3466f927c42d236`**, 44 data rows.
- **Columns:** `row, kind, identity, test, binary, expect, asserted_site`.
- **Rows:**
  - 4 `NEGATIVE` (expect PASS; the site is asserted inside the test);
  - 2 `POSITIVE` (`cp3entry:3/5`);
  - 3 `GUARD` (RA-137.1);
  - 35 `RED`, copied verbatim from the TB28 inventory (SHA-256 `66c0ba37…3da` verified): phase:ordinal, identity, owner.
- **Checks:** 44 unique tests and 44 unique identities.

#### RA-137.3 TB29H — reusable targeted harness (control-plane Code + Build)

**File:** `.agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh`. Derive it from the TB27 harness (`m6_cp3_tb27_a7_cross_sheet_verification_harness.sh`, SHA-256 `5e3ca0a7…fe1f`, proven in run 39764327506). Keep its package verification, `unzip` mode-preserving extraction, executable-mode check, staged-view hashing, GMP dependency and postflight checks.

**Generalize:**
1. **No hard-coded package values.** Inputs come from the environment:
   - `CANDIDATE_ARTIFACT_ID`;
   - `EXPECTED_SOURCE_SHA`;
   - `EXPECTED_CANDIDATE_ZIP_SHA256`;
   - `EXPECTED_ROOT_MANIFEST_SHA256`;
   - `EXPECTED_SOURCE_ARCHIVE_SHA256`;
   - `CASE_MANIFEST` (repo-relative path in the dispatch checkout);
   - `CASE_MANIFEST_SHA256`.

   Verify each input before anything runs.
2. **Read cases only from the manifest.** Require the exact header, unique `test` and `identity`, and `kind` in {NEGATIVE, POSITIVE, GUARD, RED}. Resolve each `binary` under the staged `bin/`, and fail closed if it is missing or not executable.
3. **Run each case exactly once:** `GTEST_FAIL_IF_NO_TEST_SELECTED=1 <binary> --gtest_filter=<test>`, with a timeout, no retry and no other selection. Record exactly one `[ RUN ]`; skips count as missing.
4. **Extract a typed reason for every non-PASS case**, using the published formats:
   - factory: `code=<int>;sourceAuthoritySite=…;edge=…;event=…;cell=…;region=…;periodicRelation=…`;
   - atlas: `code=<Name>[;sourceEdge=(a,b)…]`;
   - A5: `A5:<Name>[;site=…]`;
   - A7 or pipeline: `firstStage=…;firstReason=…` and `site=…`.

   If none appears, write the literal `reason-not-observed`. The first failure line is always recorded too.
5. **Gates.** Evidence is always published first; the exit code then reports:
   - **fail closed** on: a missing or duplicate case; skipped > 0; a NEGATIVE, POSITIVE or GUARD that is not PASS (`control_bad`); a manifest, package or view hash mismatch;
   - **report, but do not fail,** a RED row that passes (`unexpected_pass`).
6. **Outputs:**
   - `ledger.tsv`: row, kind, identity, test, binary, verdict, exit, run, passed, skipped, first_failure, typed_reason, log_sha256;
   - `raw/<row>.log`;
   - `execution-boundary.json`: state counts, `compile/relink/configure/benchmark=false`, postflight;
   - `SHA256SUMS`.
7. **`--self-check <manifest>` mode:** validates the manifest (header, count, uniqueness, kinds, column values) with **no** download or execution. Exit 0 or non-zero.

**TB29H evidence:**
- `bash -n` passes;
- the embedded Python compiles (`py_compile` of the extracted program);
- `--self-check` passes on the RA-137.2 manifest, and fails on two deliberately broken copies: a duplicate test, and an unknown kind;
- the harness SHA-256 is recorded in `Architecture_M6_CP3_TB29H_Targeted_Harness_Code_Build_Record_20261023.md` (at most 30 lines);
- **no** product, test, selector, workflow or manifest change, and **no** binary execution.

#### RA-137.4 Sequence and accounting

- **Sequence:** design review (this) → **TB29H** → TB29H-REV → TB29, run with:
  - harness `m6_cp3_targeted_artifact_harness.sh` at its reviewed SHA, via `agent-test-benchmark-reusable.yml`;
  - the RA-137.2 manifest;
  - CB28A package `12465330920`: source `4473e41e94a35f1bf189fa046e86bac92c7391fb`, ZIP `da56650a…dfbf5`; it **expires 2026-10-29T22:54:39Z**.

  → TB29-REV → DEFN-M1 → DEFN-M1-REV → corrective CB/TB → DEFN-T1 → fixture debt → census → RP-01 Review. `DEFN-SEAM-NZ` and the Periodic follow-up each wait for a witness. `DIAG-RETAIN` is scheduled clear of RP-01 turns.
- **CB28A:** the diff `4473e41e9` was re-checked as message-only at exactly the three asserts named in RA-136.3.
- **Accounting (unchanged):** stable 66/17/49, debt 1, CP2 491/491; R3 403/497 rejected; TB28 462/497 candidate; selector 497 frozen. `RP-01` open, `RP-02` UNREACHED, Gate C suspended.

| Duty | Answer |
|---|---|
| Decisive claims re-derived | TB29 stop and plan; TB27 harness structure (single binary, hard-coded cases and package); identity-to-binary mapping (CMake 89–96; inventory owners); guard trio against RA-130.9/TB27; inventory hash; manifest built and hashed; CB28A diff; package expiry |
| Non-vacuity | Self-check negatives required; fail-closed control gates; `reason-not-observed` made explicit |
| Obligations | TB29 plan corrected (guards); RA-136.4 carried into the manifest; harness reuse for later targeted TBs |
| Durable docs | Handoff, TODO, tracker, CHANGELOG, ORIENTATION, Frozen Definitions index |
| Boundary | Review-only; adds a Review-owned data manifest; no source, test, selector, workflow or runtime change |

## `Architecture_M6_CP3_TB29_Review_Audit_Decision_20261023.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_TB29_Review_Audit_Decision_20261023.md`; moved verbatim.

### RA-142 — Audit of the TB29 review (RA-141): evidence upheld; M1 is ten rows (six measured, four proven statically); DEFN-M1 scope restored (2026-10-23)

**Turn:** `M6-CP3-TB29-RP01-TYPED-FACTORY-CAUSE-HARVEST-REV-AUDIT` (independent audit of RA-141).

**Verdict:**
- **Upheld:** RA-141's evidence and its partition of the 35 REDs; the exclusions of the seven non-M1 factory rows, the A3 rows, `focused30:12` and `cp3entry:1/2`; and the authorization of `M6-CP3-DEFN-M1-RP01-CERTIFICATE-PAIR-BINDING-PRECEDENCE`.
- **Corrected:** RA-141 left `selector:211, 219, 227, 230` out of M1 as "reason-not-observed". The source proves they reach the **same** R2 certificate-pair-binding clause first.
- **Why it matters:** they are M1's frozen-precedence oracles, the tests that state which error must win: `InvalidOppositeEdge` and `InvalidHardRailAuthority`. A DEFN-M1 scoped without them would define precedence without its decisive oracles.
- **DEFN-M1 is re-scoped to all ten RA-105.3 rows**, still documents-only.

#### RA-142.1 Re-verified

- **Artifact:** result `12481556884`. The provider digest equals the local ZIP SHA-256 `4e639a63…ae1`; it expires 2026-10-30T05:47:15Z. **92/92** checksums pass. `execution-boundary.json` shows 44/44 executed, 9 PASS, 35 RED, every `*_bad`/missing value 0, postflight true, exit 0.
- **Partition confirmed:**
  - factory 13: `certificate-pair-binding` 6, `face-gauge-missing` 6, `open-rail-chain` 1;
  - A3 8;
  - A5 1;
  - untyped 13.
- **Factory code 0** is `InvalidSourceAuthority` (`SurfaceCellTracing.h:1900–1901`).
- **The four A7 negatives** are non-vacuous, as RA-141 states (RA-135 design; CB27A/CB27 preconditions).

#### RA-142.2 The four "untyped" rows are R2 certificate-pair-binding rejections (static proof)

The R2 clause (SCT:8828–8841) rejects with `InvalidSourceAuthority`, site `certificate-pair-binding`, if a certified hard-rail pair has a mismatched `oppositeEdge`, `railId`, `route`/`route.reversed()`, or region. It runs **before** the factory's own `InvalidOppositeEdge` check (SCT:9350).

| Row | Test | Tamper | First clause reached | Frozen expectation preempted | Log evidence |
|---|---|---|---|---|---|
| `selector:219` | `MissingHardRailCounterpartIsRejected` (TQ:9049) | hard-rail `oppositeEdge = -1` | `first.oppositeEdge != certificate.secondFrontEdge` (SCT:8833) | `InvalidOppositeEdge` (7) | actual code `<00-00 00-00>` = 0 |
| `selector:211` | `AmbiguousHardRailCounterpartIsRejected` (TQ:9067) | the opposite's `oppositeEdge = self` | `second.oppositeEdge != certificate.firstFrontEdge` (SCT:8834) | `InvalidOppositeEdge` (7) | actual code 0 |
| `selector:227` | `DuplicateSemanticRouteTopologyFailsClosed` (TQ:10189) | hard-rail `route` replaced | `first.route != certificate.route` (SCT:8836) | pipeline `InvalidHardRailAuthority` | `InvalidPhaseFrontProduct`, which the TQ `materialize` helper (TQ:2551–2563) returns for **any** factory rejection |
| `selector:230` | `RouteTopologyTransitionMismatchFailsClosed` (TQ:10146) | hard-rail route transition changed | `first.route != certificate.route` (SCT:8836) | pipeline `InvalidHardRailAuthority` | as above |

**Status of the claim:**
- For 211/219, the observed code already narrows the cause to an `InvalidSourceAuthority` clause. The listed clause is the first one in the factory that reads the tampered field.
- For 227/230, the observation shows only that the factory rejected the draft. The route clause is the first factory clause that reads `route`.
- Not measured: the site string. The harness can't read GoogleTest's byte rendering of an enum (`<00-00 00-00>`), and `materialize` discards the factory error.
- The post-fix TB will settle it: if any of the four still fails with code 0, or with `InvalidPhaseFrontProduct`, after the M1 correction, that falsifies the claim.

**Result:** M1 = RA-105.3's ten rows, exactly: `focused30:3, 22, 23`; `selector:139, 140, 142, 211, 219, 227, 230`. Six are measured at site `certificate-pair-binding;certificate=0;rail=2` and four are statically proven. RA-141's statement that RA-105.3's ten-row grouping is unproven is withdrawn: the grouping holds, partly proven from the source rather than measured.

#### RA-142.3 The design question DEFN-M1 must answer

- **The shared failure:** the A4 product factory checks hard-rail pair integrity (opposite, rail id, route, region) against the A4-owned certificate. It reports every mismatch as generic `InvalidSourceAuthority`. That preempts two kinds of frozen, specific rejections:
  1. the factory's **own** structural check, `InvalidOppositeEdge` (211/219);
  2. **downstream** owners: the pipeline's `InvalidHardRailAuthority` (227/230), and A5's hard-rail route and strict-transport validation (focused30:22/23, which encode RA-15/RA-19 precedence; `selector:139/140/142`, strict transport; focused30:3, A5 relation-endpoint checks reached through a published draft).
- **DEFN-M1 must decide, per tampered field, which single owner rejects first and with which typed code.** Options:
  - (a) structural checks run before certificate binding, which then reports field-specific codes;
  - (b) the binding stays first but carries frozen field-specific codes and sites;
  - (c) A4 drops checks that A5 owns, if RA-15/RA-19 make A5 the owner.
- **Each option needs a non-weakening table:** every tamper must still reject, at the owner the frozen tests name, and a forged certificate must still reject.
- **Test expectations are not to change.**

#### RA-142.4 DEFN-M1 deliverables (amended)

The output is `Architecture_M6_CP3_DEFN_M1_Certificate_Pair_Binding_Precedence_20261023.md`, at most 100 lines, anchored at HEAD. It must contain:

1. **Clause audit:** the factory's validation order (`SurfacePhaseFrontProduct::make`, SCT:8439), from the R2 binding loop (SCT:8814–8841) through `InvalidOppositeEdge` (SCT:9350), plus the A5 hard-rail route and strict-transport checks that 22/23 and 139/140/142 expect.
2. **Ownership matrix for the ten rows:** tamper; expected frozen code and owner; currently reached clause (measured or static); proposed first-rejecting clause.
3. **The chosen option**, (a), (b) or (c), with a rationale traced to RA-15.2–15.4, RA-19.1 and RA-105.3.
4. **Non-weakening table:** forged or absent certificate, wrong rail, reversed route, same region; each still rejects, with the named clause.
5. **Predictions and falsifiers for the corrective TB:**
   - the ten rows reach their frozen expected outcome;
   - the seven non-M1 factory rows are unchanged (still `face-gauge-missing` / `open-rail-chain`);
   - the nine TB29 controls still PASS.
6. **Exclusions,** each with its owner:
   - face-gauge-missing (6), with a note that the direct periodic-owner fixture (TQ:≈358) passes no face gauges;
   - open-rail-chain (1);
   - A3 (8);
   - A5 `focused30:12`;
   - `cp3entry:1/2`;
   - the other 9 untyped rows.

**STOP** and return to Review if no option satisfies all ten frozen expectations without changing a test or disabling a guard.

#### RA-142.5 Sequence and accounting

- **Sequence:** audit (this) → **DEFN-M1 (ten rows)** → DEFN-M1-REV → corrective CB (product, scoped by DEFN-M1-REV) → CB-REV → TB (the ten M1 rows, the seven non-M1 factory rows, the nine controls; targeted harness with a Review-owned manifest) → TB-REV.
- **After that:** owners for face-gauge-missing, A3 cycle locus and A5 `focused30:12` (each DEFN or diagnostic first) → DEFN-T1 → fixture debt → census (needs an RA-139.3-compliant harness) → RP-01 Review. `DEFN-SEAM-NZ` and the Periodic follow-up each wait for a witness. `DIAG-RETAIN` is scheduled clear of RP-01 turns.
- **Accounting (unchanged):** stable 66/17/49, debt 1, CP2 491/491; R3 403/497 rejected; TB28 462/497 candidate; selector 497 frozen. `RP-01` open, `RP-02` UNREACHED, Gate C suspended.

| Duty | Answer |
|---|---|
| Decisive claims re-derived | Result digest, 92/92, boundary state; partition; enum value 0; the four tests' tampers and failure blocks; R2 clause conditions (SCT:8828–8841); `InvalidOppositeEdge` site (SCT:9350); `materialize` mapping (TQ:2551–2563) |
| Non-vacuity | Static first-clause proof per row, with an explicit falsifier at the post-fix TB |
| Obligations | RA-141 upheld except the M1 exclusion; DEFN-M1 scope and deliverables amended; RA-139.5 carried |
| Durable docs | Handoff, TODO, tracker, CHANGELOG, ORIENTATION, Frozen Definitions index, DEFN-M1 plan pointer |
| Boundary | Review-only; no source, test, harness, manifest, selector, workflow or runtime change |

## `Architecture_M6_CP3_TB29_Typed_Factory_Cause_Harvest_Review_Decision_20261023.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_TB29_Typed_Factory_Cause_Harvest_Review_Decision_20261023.md`; moved verbatim.

### RA-141 — Independent TB29 typed-failure review (2026-10-23)

**Turn:** `M6-CP3-TB29-RP01-TYPED-FACTORY-CAUSE-HARVEST-REV`. **Disposition:** TB29 immutable 44-case evidence is mechanically authentic; CP3 remains unaccepted, and no cause is assumed from test names. Source/fixture/test/selector, build and runtime are unchanged by this Review. **Authorized bounded successor:** `M6-CP3-DEFN-M1-RP01-CERTIFICATE-PAIR-BINDING-PRECEDENCE` (Definition only). Other owners remain explicitly separate and are not authorized to change code in this turn.

#### Primary evidence independently reproduced

- Original CB28A semantic source `4473e41e94a35f1bf189fa046e86bac92c7391fb`; package `12465330920`; TB29 run `39906802267`, artifact `12481556884`; downloaded ZIP SHA-256 `4e639a633a64df419f1891083911506679c6c4848f1ecbce7b206c4f5d653ae1` independently matched provider digest. 92/92 packaged checksums verified. The 44 raw-log hashes match the ledger; each has exactly one matching `[ RUN ]`; all 44 manifest/ledger identities, binaries, verdicts and 35 TB28 RED phase:ordinal mappings are exact. `execution-boundary.json`: planned/executed 44/44, PASS 9, RED 35, missing/skipped/duplicates/control_bad/unexpected_pass all zero, postflight true, no configure/compile/relink/benchmark, exit zero.
- Frozen TB29 manifest SHA-256 `39fa5eb83e2da1b0668bc7368c5304011ec13de8804c54a2a3466f927c42d236`; TB28 35-RED inventory SHA-256 `66c0ba377c834a969d481cf1ee2253688fa12b7686a0ced6d9da9695e01eb3da`. These hashes were recomputed from source. No selector was changed; 497-case CP3 replay was not performed.
- Independent disjoint failure partition: **13 checked-factory** = 6 `certificate-pair-binding` + 6 `face-gauge-missing` + 1 `open-rail-chain`; **8 A3** = 7 `CycleTransportMismatch` + 1 `SingularityMismatch;sourceEdge=(2,3)`; **1 A5** = `OccurrenceHardRailTransportMismatch`; **13 untyped** = `reason-not-observed`. Total exactly 35, no double allocation. The literal factory `code=0` denotes `InvalidSourceAuthority` at these sites, not successful admission.
- Verified one-source, immutable-A6 non-vacuity for four new negative tests by inspecting `check_d7_certified_seam_negative` (TQ:4123+): it first builds positive A5, A6 and A7 from the actual D7 witness, applies each targeted mutation with preconditions, asserts the independently expected A6 outcome, then invokes A7 on the mutated A5 **with original A6** and asserts `UncertifiedCrossSheetBinding` and the exact site. A7NEG:1 asserts a connecting unrelated-seam transition; :3 holds source support/selected face constant while changing lattice coordinate; :4 withdraws the binding while retaining the sheet and certificate. Their four log PASS results alone would be weaker evidence; source controls make earlier A6 failure unable to masquerade as an A7 PASS.

#### RA-141.1 Exact M1 measured scope and non-merging

**Only six first rejections actually reach RA-105.3's R2 certificate-pair-binding clause**, uniquely labelled at `SurfaceCellTracing.cpp` around the certificate pair check (`first/second railId`, route/opposite orientation, and region). Identities: `focused30:3,22,23` and `selector:139,140,142`. They share first-failure site `certificate-pair-binding;certificate=0;rail=2`, but have different test contracts; the Definition must preserve validation precedence, semantics and named error taxonomy without weakening the certificate binding. This is a **measured branch and a candidate precedence defect**, not proof that each expected outcome has the same correct fix. The older RA-105.3 static ten-row grouping is not accepted as a ten-row first-failure proof.

**Exclude** the other seven typed factory cases: `selector:220,221,296,302,304,439` fail at `face-gauge-missing`, before certificate checks; `cp3entry:4` fails at `open-rail-chain`. They require independent A6/gauge and open-rail-chain owners, respectively. The four other former RA-105 M1 identities `selector:211,219,227,230` emit `reason-not-observed` (wrong expected code/name observed); the TB29 typed material does **not** prove their first clause. Preserve their assertions and carry them as M1-adjacent unknowns, not scope credit. If an independent exact first-site receipt later proves certificate binding on any of these, Review must amend scope before code work.

#### RA-141.2 Other first failures and explicit dispositions

- **A3 periodic fixture `selector:189–195` (7):** A3 `FieldTransportAtlas::make` reports `CycleTransportMismatch` before a usable phase-front product. Source has at least two distinct sites producing this code (local ordered cycle and boundary-cycle corrected lift); TB29's emitted reason has no cycle kind/region/step locus. **Cannot attribute fixture debt or product error from this code alone.** Separate A3 cycle-locus evidence/Review owns the distinction; the cases do not enter M1.
- **A3 `selector:442` (1):** `SingularityMismatch` on source edge `(2,3)` is independent A3 field/fixture authority, not a factory certificate conflict. Preserve hard-feature transition and singularity expectations; separate witness/atlas review must check fixture input and actual topology before assigning blame.
- **A5 `focused30:12` (1):** after the relabelled front is accepted, `produceA5` returns `OccurrenceHardRailTransportMismatch` at the A5 assertion (TQ:5525). This is an A5 relabelling/transport admissibility question, **not** M1. Require a source A5 mismatch-site and independently checked relabel equivalence before any behavior correction.
- **`cp3entry:1/2` (2):** test assertions respectively lack the expected periodic odd-gauge witness and the produced hard-rail midline certificate. These are missing witness/precondition observations, not evidence of a specific factory, A3, or A5 failure. Do not weaken them or call them production failures without a produced witness.
- **Other `reason-not-observed` (11):** `selector:174,201,204,211,219,227,230,242,247,250,405`. Keep distinct first-failure text/oracles (DCEL throw, missing terminal, wrong error codes or disposition, wrong topology). Do not relabel as M1 because of test topic. Prior RA-134.2 disposition remains tentative until individually verified.

#### RA-141.3 Non-promotion and bounded successor

Stable **66 events / 17 categories / 49 recurrences**, produced witness debt **1**; CP2 **491/491 accepted**, CP3 R3 **403/497 rejected**, TB28 **462/497 candidate only**; the frozen 497 selector and accepted prefix are unchanged. TB29 is a 44-case diagnostic replay, **not** a green/full census. RP-01 OPEN, RP-02 UNREACHED, Gate C suspended. No new stable regression established.

Authorize only `M6-CP3-DEFN-M1-RP01-CERTIFICATE-PAIR-BINDING-PRECEDENCE` (no source change, build, test or runtime). It must derive a clause-specific ownership/precedence contract for six observed R2 cases, retain all four adjacent untyped oracles as unresolved, spell out the A4/A5 responsibility and non-weakening table, and pre-register falsifiers **before** any subsequent CB: an invalid certificate must still reject; an A5-invalid pair must retain its specified error; existing A7/D3/D7 positive and negative paths must still discriminate; no change to other typed factory sites; no selector mutation. Halt if this ownership cannot be specified without guessing from the six log messages. Following Definition, separate independent DEFN review is mandatory before any CB; later A3/A5/witness work gets separate authority. RA-139.5 corrected crash-safe 497-case census harness remains owed and may not be satisfied by this 44-case tool.

#### RA-141.4 Authentic committed-history verification

Read-only GitHub Actions [run 39916753662](https://github.com/akashskypatel/Directional/actions/runs/39916753662) checked out real Git history at `6c0d5a7b88d6af600f3e9344622011b8866aeebb` (identical to `origin/agent/surface_cell_quad/p5-recover-bridge-healing` at audit time), not snapshot-synthesized history. Immutable diagnostic-log artifact `12484718148`, provider ZIP SHA-256 `1b492d9a6c251b5dd62edfe0a17e10e86304dc9796bc6285dd66af1e255437b1` independently verified. Original `review_check.py boundary` and `ledgers --base 8b7299b43` both exited 0 with `ALL CHECKS PASSED`; rewrite baseline `8b7299b43764a6ba3444e5bc774a2f1b65e99731` is a real ancestor, all enumerated selector hashes matched, durable rewrite headings were preserved (handoff 4/4, orientation 1/1, tracker 0/0), and no append-only `CHANGELOG.md` or `LESSONS.md` historical shrinkage was found. No runtime, compilation, product-test execution or modification occurred. The runner's detached checkout had a clean worktree and identical remote-ref SHA; it is not evidence of a separate branch-local `git status -sb` tracking display after future writes.

#### Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | Existing accepted focused30/focused12/selector449 immutable hashes retained; no selector changed. TB29 and TB28 inventory hashes independently recomputed as above. |
| Decisive claims independently re-derived | ZIP, 92 files, 44 exact log hashes, 44 RUN/verdict/identity mappings, 35 earlier RED mappings, 6/6/1 + 7/1 + 1 + 13 disjoint partition, source branch-check sites. |
| Non-vacuity checked | A7 negatives source-inspected at TQ:4123–4422 with original A6 independent guard, positive produced checks and site assertions; no dynamic mutation testing performed in this review. |
| Prior obligations discharged/carried | RA-140.4 M1 partition discharged to six exact observed clauses; A3 189–195 and 442, A5 focused30:12, cp3entry:1/2, 13 insufficiently typed and RA-139.5 census-harness debt carried to their separate owners. |
| Stable accounting | 66/17/49; debt 1; CP2 491/491 accepted; R3 403/497 rejected; TB28 462/497 candidate; RP-01 open, RP-02 unreached. |
| New candidates/obligations recorded | The tracker records seven typed non-M1 factory, eight A3, one A5 and thirteen untyped first failures with separate owners/falsifiers; no promotion. |
| ORIENTATION currency line | Updated to RA-141/TB29 2026-10-23 with the correct next Definition boundary. |
| ORIENTATION §3 / §4 / §7 / §8 | §3 updated for TB29 and accepted/candidate gates; §4 no new witness; §7 updated ownership priorities, §8 unchanged because no new pattern. |
| CHANGELOG | RA-141 independent-review entry committed in root `CHANGELOG.md`. |
| ROADMAP | No checkpoint status movement; unchanged for substantive reason. |
| Selector manifest | Unchanged; no selector added or accepted. |
| LESSONS | Existing evidence/diagnostic/precedence lessons apply; no new lesson. |
| Consolidation under CLEAN_UP_POLICY | Folded consumed TB29 artifact-only plan into `M6_Consolidated_Record.md` with its exact filename/verdict, complete verbatim text and provenance resolver; retained authoritative TB29 report, RA-141 Review and next DEFN-M1 plan. |
| Successor frozen | `M6-CP3-DEFN-M1-RP01-CERTIFICATE-PAIR-BINDING-PRECEDENCE` with falsifiers here and in next Definition plan. |
| Turn boundary held | Static independent Review only; no Directional binary, configure, compile, relink, benchmark, code/test/selector mutation. |
| review_check.py boundary | PASS on authentic Git history, run 39916753662, log artifact 12484718148, source `6c0d5a7b...`; `ledgers --base 8b7299b43` PASS. |
| `STATUS` lifecycle maintained | Entry and both continuation resumes written; final terminal beacon is the last repository action after remaining closeout/cleanup. |
| Pushed to origin, branch in sync | Initial and consolidation patches are committed and verified on PR #8; authentic runner checked exact origin ref equality and clean worktree. Final closeout commit/ref synchronization must be checked after remaining writes. |

## `Architecture_M6_CP3_TB30_Certificate_Association_Ownership_Verification_Review_Decision_20261023.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_TB30_Certificate_Association_Ownership_Verification_Review_Decision_20261023.md`; moved verbatim.

### RA-144 — TB30 review: M1 resolved (10/10) on the targeted gate; full census before any further fix (2026-10-23)

**Turn:** `M6-CP3-TB30-RP01-CERTIFICATE-ASSOCIATION-OWNERSHIP-VERIFICATION-REV`.

**Verdict:** TB30 is **accepted** as targeted candidate evidence. All pre-registered RA-143.4 predictions held:
- the 10 M1 rows now PASS;
- the 7 non-M1 factory rows are unchanged, with the same typed sites;
- the 9 TB29 controls and the 3 certificate-authenticity guards PASS.

CB29 matches RA-143.3 exactly. It still needs a census: the change alters A4's admission for **every** hard-rail certificate, and TB30 measured only 29 identities. The next turn is the **selector-497 census**, run on the CB29 package with the crash-safe targeted harness and a Review-owned 497-row manifest (discharging RA-139.5). No further product turn starts before it.

#### RA-144.1 Verified

- **CB29** `2602e7398` (SCT only): it removes exactly the five association predicates (both `oppositeEdge`, both `railId`, both route comparisons, the region inequality), keeps both `HardRail` kind checks, and adds the RA-15/RA-16 §5/RA-143 comment.
- **Package `12492950387`:**
  - ZIP SHA-256 `9e2da1f4…9167319`, digest re-hashed;
  - root manifest `5f7259b7ec0f420c8d161973f450e99e76684b0643c8e21074d192931747320d` (28 entries);
  - source archive `e5ec539063d7bf6dfbe06b1552c081d117e052f8090a58aaa6ac754242e8f53a` (matches its manifest entry);
  - source commit `2602e7398cdc6f1281abe11a758de35166b6590c`;
  - **expires 2026-10-30T09:34:32Z.**
- **TB30 result `12500088095`:** digest equals the local ZIP SHA-256 `bba928eb…308bf`. **61/61** checksums pass. The run shows 29 planned and executed, 22 PASS, 7 RED, and missing, skipped, duplicate, `control_bad` and `unexpected_pass` all 0. Postflight true, exit 0, and no compile, relink or configure. By kind:
  - GUARD 6 PASS;
  - NEGATIVE 4 PASS;
  - POSITIVE 12 PASS (10 M1 and D3/D7);
  - RED 7 RED.
- **RA-142.2's static claim is confirmed:** `selector:211/219/227/230` now PASS, so they did share the R2 clause.

#### RA-144.2 Remaining RED set (25; owners carried)

| Group | Rows | Owner (next definition or diagnostic) |
|---|---|---|
| Factory `face-gauge-missing` | `selector:220, 221, 296, 302, 304, 439` | The direct periodic-owner fixture (TQ:≈358) passes no face gauges. A DEFN decides between fixture debt and the factory contract. |
| Factory `open-rail-chain` | `cp3entry:4` | A4 open-rail-chain owner |
| A3 `CycleTransportMismatch` | `selector:189–195` | A3 cycle-locus diagnostic first: the code has two source sites and no locus (RA-141.2) |
| A3 `SingularityMismatch` (2,3) | `selector:442` | A3 singularity/fixture review |
| A5 `OccurrenceHardRailTransportMismatch` | `focused30:12` | A5 relabelling/transport owner |
| Witness absence | `cp3entry:1` (D2 odd gauge), `cp3entry:2` (midline certificate) | DEFN-T1 / witness owners |
| Producer disposition or oracle, untyped | `selector:174, 201, 204, 242, 247, 250, 405` | Per-row first-failure classification; RA-92.3/93.3 fixture debt covers 174, 242, 250 |

#### RA-144.3 Successor `M6-CP3-TB31-RP01-SELECTOR-497-CENSUS` (artifact-only Test + Benchmark)

- **Why a census now:** RA-139.5 bars the old census harness, because it counts crashes as RED. The reviewed targeted harness (`436f5fff…c9a`, RA-139.3 classifier, validated on real logs in RA-140) runs any Review-owned manifest.
- **Manifest (Review-owned, this turn):** `Architecture_M6_CP3_TB31_Census_Case_Manifest.tsv`, SHA-256 **`b1c135d429f8c659e190f648b8678669cb7c14d393e0db9069568ea3838aa43e`**, 497 rows.
  - **Derivation:** generated from TB28's `combined-ledger.tsv` (SHA-256 `bbac8649…6ec5`, inside result `12424484672`, digest re-verified), which the frozen-selector harness itself produced from the frozen 30 + 12 + 449 + 6 selector. Every phase:ordinal identity, test name and owning binary is copied in TB28's order.
  - **Kinds:** `GUARD` for the 472 rows expected to PASS (TB28's PASS rows plus the 10 M1 rows); `RED` for the 25 in RA-144.2.
  - **Checks:** 497 unique tests across 4 binaries; `--self-check … 497` passes.
  - **GMP preflight:** all four binaries list `libgmp.so.10` in their ELF `DT_NEEDED`.
- **Harness inputs:**
  - `CANDIDATE_ARTIFACT_ID=12492950387`;
  - `EXPECTED_SOURCE_SHA=2602e7398cdc6f1281abe11a758de35166b6590c`;
  - `EXPECTED_CANDIDATE_ZIP_SHA256=9e2da1f4b5cf95ac45364e8c428f0bd9116dcfe96772de18d02a5a7bfb167319`;
  - `EXPECTED_ROOT_MANIFEST_SHA256=5f7259b7…320d`;
  - `EXPECTED_SOURCE_ARCHIVE_SHA256=e5ec5390…f53a`;
  - `CASE_MANIFEST=.agents/Directional/Architecture_M6_CP3_TB31_Census_Case_Manifest.tsv`;
  - `CASE_MANIFEST_SHA256=b1c135d4…aa43e`;
  - `EXPECTED_CASE_COUNT=497`.
- **Prediction:** **472/497**, with exactly the 25 RA-144.2 rows RED and zero regressions from PASS to RED.
- **Reading the gates:**
  - `control_bad > 0` means a measured regression (harness exit non-zero after evidence is published): report it, don't fix it;
  - `unexpected_pass` means a RED row recovered: report it;
  - any `INVALID` row is a harness or run fault: STOP.
- **Report:** `Architecture_M6_CP3_TB31_Selector_497_Census_Report_20261023.md`, with totals, every row diff against TB28, every RED's typed reason, and a new RED inventory TSV.
- **Not promotion:** acceptance stays with the RP-01 Review.

#### RA-144.4 Sequence and accounting

- **Sequence:** TB30-REV (this) → **TB31 (census)** → TB31-REV → per-owner turns, each DEFN or diagnostic first and ordered by row count and independence:
  1. face-gauge-missing (6);
  2. A3 cycle locus (7, diagnostic);
  3. untyped producer/oracle rows (7);
  4. A5 `focused30:12`;
  5. `cp3entry:4`;
  6. `selector:442`;
  7. DEFN-T1 (`cp3entry:1/2`).

  → census → RP-01 Review. `DEFN-SEAM-NZ` and the Periodic follow-up each wait for a witness. `DIAG-RETAIN` is scheduled clear of RP-01 turns.
- **Accounting (unchanged):** stable 66/17/49, debt 1, CP2 491/491; R3 403/497 rejected; TB28 462/497 candidate (TB31 may supersede it as a candidate); selector 497 frozen. `RP-01` open, `RP-02` UNREACHED, Gate C suspended.

| Duty | Answer |
|---|---|
| Decisive claims re-derived | CB29 diff; package digest, root manifest, source archive, source commit, expiry; TB30 digest, 61/61, boundary state, verdicts by kind; 497-row manifest built from a verified source, self-checked; `DT_NEEDED` of four binaries |
| Non-vacuity | M1 flips measured; the census gates every expected PASS as a control |
| Obligations | RA-143.4 discharged; RA-139.5 discharged by the TB31 harness choice; remaining 25 carried with owners |
| Durable docs | Handoff, TODO, tracker, CHANGELOG, ORIENTATION, Frozen Definitions index |
| Boundary | Review-only; adds a Review-owned data manifest; no source, test, harness, selector, workflow or runtime change |

## `Architecture_M6_CP3_TB33_Odd_Atlas_Oracle_Verification_Review_Decision_20261024.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_TB33_Odd_Atlas_Oracle_Verification_Review_Decision_20261024.md`; moved verbatim.

### RA-149 — TB33 review: odd-atlas oracles accepted (synthetic scope); realign onto the 19 residual REDs, largest cluster first (2026-10-24)

**Turn:** `M6-CP3-TB33-RP01-ODD-ATLAS-ORACLE-VERIFICATION-REV`.

**Verdict:** TB33 is **accepted** as runtime evidence for the CB32 odd-atlas and checked-factory oracles. It covers **synthetic scope only**: no produced periodic front, A5/A6, G4-B002 or CP3 credit. This discharges RA-146.3 (odd transport runtime verification) within that scope.

**Realignment:**
- **Since TB31,** six turns of FG01/CB30/TB32 recovered six rows (TB32: 478/497 original plus 3 controls = 481/500). Then six turns of CB31/CB32/TB33 added oracle coverage **without removing any RED**.
- **What is left:** the 19 residual REDs, not further synthetic hardening.
- **Next:** the largest independent cluster, A3 `CycleTransportMismatch` (`selector:189–195`, 7 rows), starting with a **diagnostic**, because its two source sites are indistinguishable today.

#### RA-149.1 Verified

- **Result:** `12543546779`. The provider digest equals the local ZIP SHA-256 `217f6b21…c09d`; it expires 2026-10-31T01:54:32Z. **15/15** checksums pass.
- **Execution record:** source `30e46b9aa`, package `12541198172`; 6 planned and executed, 6 PASS, every `*_bad`/missing value 0; postflight true, exit 0; no compile, relink, configure or benchmark.
- **Manifest:** `Architecture_M6_CP3_TB33_Odd_Atlas_Oracle_Cases.tsv` SHA-256 `09c0d065…f872` matches. Each log has 1 RUN, 1 OK and no failure. The harness was `436f5fff…c9a`.
- **Non-vacuity** (TQ:9284–9436; no `GTEST_SKIP` or early `return`):
  - the positive test asserts the source-derived odd turn `3` (`ASSERT_EQ(3, expectedTurn)`), transport values 1/3 with an exact inverse, and the mapped forward transport `3` under row and corner permutations;
  - both negatives assert `InvalidSourceAuthority` **and** the exact site `gauge-pin-consistency;edge=0,2`, after asserting their preconditions (equal baseline and permuted turns; inverse turn `(4 − 3) % 4 = 1`).

  So PASS on these tests means each assertion was reached and held.

#### RA-149.2 Residual REDs (19) and order of attack

| Order | Group | Rows | First step | Why this order |
|---|---|---|---|---|
| 1 | A3 `CycleTransportMismatch` | `selector:189–195` (7) | **Diagnostic CB** (RA-149.3) | Largest cluster; one fixture helper (SP10:4380–4402); site unknown |
| 2 | Untyped producer/oracle | `selector:174, 201, 204, 242, 247, 250, 405` (7) | Per-row first-failure pin; 174, 242, 250 are RA-92.3/93.3 fixture debt | Independent rows |
| 3 | A5 transport | `focused30:12` | DEFN (relabel equivalence) | Single row, frozen invariance test |
| 4 | A4 open-rail-chain | `cp3entry:4` | DEFN | Single row |
| 5 | A3 singularity | `selector:442` | Fixture/atlas review | Single row |
| 6 | Witness absence | `cp3entry:1/2` | DEFN-T1 | Needs a produced witness |

#### RA-149.3 Why a diagnostic first for A3 cycles

`FieldTransportAtlas::make` raises `CycleTransportMismatch` at **two** sites. Both call `fail(…, region.id())` and drop every locus:
- **S1** (`src/authority/FieldTransportAtlas.cpp:2582–2585`): a cycle's composed transport ≠ its turning lift. `orderingDiagnostics` (`cycleRowIndex`, `cycleKind`: LocalVertex / BoundaryLoop / HandleGenerator) is computed just above and then discarded.
- **S2** (`:2691–2695`): the canonical boundary cycle's lift, **after** the index-sum correction, ≠ its composed transport.

TB31 logs show only `code=CycleTransportMismatch;topologyRegion=0`. The error type already has a `cycleOrderingDiagnostics` field (`FieldTransportAtlas.h:259`) but no way to say which of S1 or S2 fired.

- **S1** points to an inconsistent field or source cycle in the fixture: fixture debt, or a real A3 transport defect.
- **S2** points to an index-sum or boundary-correction problem: an A3 admissibility contract question.

The owner cannot be named until this is measured.

#### RA-149.4 Successor `M6-CP3-CB33-RP01-A3-CYCLE-MISMATCH-LOCUS-DIAGNOSTIC` (Code + Build, compile only; diagnostic only)

1. **`include/directional/authority/FieldTransportAtlas.h`:** add `std::string site;` to `FieldAtlasBuildError`. It defaults to empty. The defaulted `operator<=>` is unchanged; no test compares whole errors (`FieldTransportAtlasTests.cpp:2015–2024, 2480, 2666` compare codes only).
2. **`src/authority/FieldTransportAtlas.cpp`:** on the two `CycleTransportMismatch` paths only:
   - **S1:** `site = "cycle-transport"`; attach `orderingDiagnostics` as `cycleOrderingDiagnostics`; for a LocalVertex cycle, set `sourceVertex` where it is already known before the return. If it is not known before the return, record that, and do not reorder code.
   - **S2:** `site = "cycle-boundary-corrected-lift"`; set `cycleOrderingDiagnostics` with `cycleKind = BoundaryLoop` and `cycleRowIndex` = the canonical boundary cycle's index.
   - Codes, return points and control flow are unchanged.
3. **`tests/SurfaceCellsPhase10Tests.cpp`:** `describe_field_atlas_build_error` (SP10:73–90) also prints `site`, `cycleRowIndex` and `cycleKind` when they are present. Message only.
4. **Limits:** no other file or path. Lines at most 100 columns.
5. **Build:** compile the eight targets with GMP/GMPXX, `runtimeExecution=false`. Record `Architecture_M6_CP3_CB33_A3_Cycle_Mismatch_Locus_Diagnostic_Code_Build_Record_20261024.md` (at most 30 lines).

**STOP** if S1's locus requires reordering code, or if any error code or return changes.

#### RA-149.5 TB34 plan (manifest issued at CB33-REV)

- **What runs:** the targeted harness on the CB33 package:
  - `selector:189–195` (RED expected, now with site and cycle);
  - guards `FieldTransportAtlas.IndependentOracleRejectsCycleOrderingTamper` and `FieldTransportAtlas.IndependentOracleRejectsCompleteTypedTamperMatrix` (PASS expected, because codes are unchanged);
  - the three TB33 factory controls.
- **Then:** TB34-REV names the owner (fixture debt or A3 contract) from S1 versus S2 and the cycle kind and row.

#### RA-149.6 Sequence and accounting

- **Sequence:** TB33-REV (this) → **CB33** → CB33-REV → TB34 → TB34-REV → A3-cycle owner (DEFN, fixture CB or A3 CB) → per-row pins for the 7 untyped rows → `focused30:12` DEFN → `cp3entry:4` DEFN → `selector:442` → DEFN-T1 → census → RP-01 Review. RA-146.2, RA-146.4/RA-45.4 (produced A6), G4-B002, `DEFN-SEAM-NZ` and the Periodic follow-up are carried. `DIAG-RETAIN` is scheduled clear of RP-01 turns.
- **Accounting (unchanged):** stable 66/17/49, debt 1, CP2 491/491; R3 403/497 rejected; **TB32 481/500 candidate** (original 497: 478 PASS / 19 RED); selector 497 frozen. `RP-01` open, `RP-02` UNREACHED, Gate C suspended.

| Duty | Answer |
|---|---|
| Decisive claims re-derived | TB33 digest, 15/15, boundary state, ledger, per-log RUN/OK; manifest SHA; oracle test bodies; both A3 raise sites and the error struct; tests comparing codes only |
| Non-vacuity | Oracle assertions reached, with no early exits; the diagnostic separates S1 from S2 |
| Obligations | RA-146.3 discharged (synthetic scope); 19 REDs ordered with owners; carried items listed |
| Durable docs | Handoff, TODO, tracker, CHANGELOG, ORIENTATION, Frozen Definitions index |
| Boundary | Review-only; no source, test, harness, selector, workflow or runtime change |

## `Architecture_M6_CP3_TB34_REV_Audit_Face_Gauge_Representation_Decision_20261024.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_TB34_REV_Audit_Face_Gauge_Representation_Decision_20261024.md`; moved verbatim.

### RA-150 — TB34-REV audit: periodic-route fixture is a face gauge, not a transition edit (2026-10-24)

**Turn:** `M6-CP3-TB34-RP01-A3-CYCLE-LOCUS-HARVEST-REV-AUDIT` (Review, documents only). **Audited:** [TB34-REV](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_TB34_A3_Cycle_Locus_Harvest_Review_Decision_20261024.md") and its [CB34 plan](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_CB34_Periodic_Route_Face_Gauge_Code_Build_Plan_20261024.md"). Source inspected at `c57e4e1d9` (no product/test change since CB33 `f807c2b89`). **Verdict:** owner classification **ACCEPTED**; CB34 transformation **CORRECTED** (RA-150.3), precondition and stop rules **ADDED**. No runtime or build was run in Review.

#### RA-150.1 — Classification independently confirmed

- Parsed `benchmarks/fixtures/milestone-g/cylinder.obj` and `cylinder.rawfield` (script, Python `-I`): faces 0 `(0,1,2)`, 1 `(0,2,3)`, 30 `(30,0,3)`, 32 `(3,2,32)`; vertices 0,1 boundary, 2,3 interior. Route steps 0/1 are faces 0→1 over `(0,2)` and 1→30 over `(0,3)` (`expected_forward_periodic_route`, SP10:4205).
- Principal matchings recomputed from the raw field by hinge transport are **0 on every interior edge** (including all three face-1 edges).
- The vertex-2 star contains `(0,2)` and `(2,3)`; the vertex-3 star contains `(0,3)` and `(2,3)`. The two-edge edit therefore breaks **both** LocalVertex cycles. Whether region-local row 0 is vertex 2 or vertex 3 does not matter: TB34-REV's "vertex 2" relies on unverified local ordering.
- S1 (`FieldTransportAtlas.cpp:2581`) compares matching composition with the effort/curvature lift. It correctly rejects a field whose matchings no longer agree with its effort around a vertex. **Fixture invalid; A3 not at fault.**
- S2 is unreachable: correction ≡ 0 mod 4 is enforced at FTA:2689, and S1 already checked the same cycle. **RA-149.3's two-site premise is withdrawn.**

#### RA-150.2 — Missing history (affects TB35 predictions)

- `selector:189–195` are rows 189–195 of the accepted 449-line green prefix. They went RED at R3, once A4 required A3 (four `A4_NOT_PRODUCED_UNTYPED`, `193` `A4_INVALID_FINAL_CELL_STATE`).
- R4 (`7ccdcd527`, `2be228d96`, `e0cc0415b`; 2026-10-11) added `build_periodic_route_network_with_source_atlas`. Its record and comment say the source A3 is built "from the original full fixture cross field", but every call site passes the **edited** field. That is what moved the first failure to S1.
- **Prohibited "fix":** passing `fixture.authoritativeField` as `sourceField`. A4 takes route transport from A3 `transition_value` (raw matching, FTA:2039). The negatives `NonzeroNetCycle…` and `Malformed…` depend on tracing/source disagreement producing `PeriodicHolonomyMismatch`, so the positives must have source == tracing.
- **Prediction:** clearing S1 may re-expose an A4 first failure from R3. That is a new producer-owner finding (STOP → Review). It is not a reason to retune the fixture.

#### RA-150.3 — Correction: a gauge acts on the face frame too

The CB34 plan changes only the three edge `matching` values and forbids changing anything else. That is a transition coboundary, not a gauge change:
- With face 1's directions untouched, matching ±1 pairs vectors that are 90° apart, while `effort` still says they are aligned. The field becomes geometrically inconsistent on each edge.
- A3 accepts it only because S1 checks cycle residues, not per-edge geometry. That would make a test pass by relying on a validator gap (LESSONS §2).
- In A4, `resolve_branch_transition` sets target branch = source + A3 transport and then uses the target face axis (`SurfaceCellTracing.cpp`, atlas branch). Face 1's propagated branch would physically turn 90°.

**Required representation gauge, g(face1)=+1, applied to the CrossFieldResult used as both source and tracing field:**
1. **Frame:** relabel face 1's quarter-turn frame (`primaryDirections`, `secondaryDirections` and the `rawField` row's four vectors) so its A3 `rawGauge` shifts by +1. A3 orders directions as `{p, s, −p, −s}` (FTA:275). The expected relabel is `p'=−s, s'=p` with vectors shifted `u'_k=u_{k−1}`, but the CB **must confirm the direction with the invariance oracle**, not take it from this text.
2. **Transitions:** add the directed difference g(to)−g(from) to all three interior edges of face 1, also updating the compact `matching` entries if populated: 0→1 **+1**, 1→30 **−1**, 1→32 **−1**. `effort` is unchanged.
3. **Precondition:** the original directed matchings on those three edges are 0. Apply the change additively and `throw` if the precondition fails. Never *set* values.
4. Find face 1 by route topology (`expectedRoute[0].targetFace == expectedRoute[1].sourceFace`), so reflected and reordered fixtures resolve correctly. Find the third edge as face 1's remaining interior edge.

**Invariance oracle** (new test identity outside the frozen selector; non-tautological):
- A3 built from the gauge field succeeds.
- Its `branch_topology().semantic_digest()`, `frames()` and `transports()` equal those of A3 built from the unedited `authoritativeField`.
- Its raw `transition_value` is +1/−1/−1 on the three directed face-1 steps.
- The two-edge-only construction (the current helper) fails `make` with `CycleTransportMismatch`, `site=cycle-transport`, LocalVertex.

#### RA-150.4 — Turn decomposition

CB34 (amended) is one test file, compile only. Edits:
- the gauge helper (frame, transitions, precondition, topology-located face);
- the new invariance-oracle test.

It makes no change to the seven test bodies, production, selectors or workflows. Then CB34-REV, followed by TB35 on the Review-issued manifest:
- 7 rows;
- the invariance oracle;
- 2 A3 guards;
- 3 TB33 controls.

Then TB35-REV. On S1 clear but A4 RED, write a DEFN for the periodic-producer owner and do no fixture tuning. The remaining queue is unchanged: untyped 7 → `focused30:12` → `cp3entry:4` → `selector:442` → DEFN-T1 → census → RP-01. `DIAG-RETAIN`, DEFN-SEAM-NZ, Periodic, RA-146.2/4, RA-45.4 and G4-B002 are carried.

#### RA-150.5 — Minor notes (no turn)

- CB33-REV says S1 `sourceVertex` is "unavailable until after the return". It is a pure lookup (`interiorLocalVertices[row]` → `globalVertexByLocal`) and is available before the return without reordering. The omission is accepted and carried as optional diagnostic debt.
- S2's `cycleRowIndex` is atlas-global. Leave the dead guard as is.

**Accounting unchanged:** stable 66/17/49, debt 1; CP2 491/491 accepted; TB32 481/500 candidate (19 inherited RED); TB34 5 PASS / 7 RED diagnostic; selector 497 frozen; RP-01 open, RP-02 unreached, Gate C suspended.

## `Architecture_M6_CP3_TB35_REV_Audit_Periodic_Route_Transport_Decision_20261024.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_TB35_REV_Audit_Periodic_Route_Transport_Decision_20261024.md`; moved verbatim.

### RA-152 — TB35-REV audit: the A4 periodic rotation guard is dead on the atlas path (2026-10-24)

**Turn:** `M6-CP3-TB35-RP01-PERIODIC-ROUTE-GAUGE-VERIFY-REV-AUDIT` (Review). **Subject:** [TB35-REV](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_TB35_Periodic_Route_Gauge_Independent_Review_Decision_20261024.md") (RA-151). **Decision:** RA-151's evidence verification and non-promotion are **accepted**; its owner statement is **incomplete and partly wrong**; its successor `M6-CP3-DEFN-RP01-PERIODIC-INGRESS-AUTHORITY` is **withdrawn** and replaced by a test-first production track below. Static source review only; no build or runtime.

#### RA-152.1 — What TB35-REV got right

- `build_surface_cell_network(CrossFieldResult, …)` (`SurfaceCellTracing.cpp:21160–21177`) passes `nullptr` for matching/effort/transitions whenever `options.fieldTransportAtlas` is set; 191 (`sourceEdge=-1`) and 192 (tracing matching 2) mutate only those discarded containers. Mechanism confirmed.
- 189 (±4 on tracing only) and 190 (legacy compact field as tracing) compare two networks built over the **same** atlas; they cannot discriminate. RA-151.2 accepted.

#### RA-152.2 — What TB35-REV missed (production defect F1)

In the periodic-annulus producer's observed-step loop (`SurfaceCellTracing.cpp:14905–15004`) the step matching is read only from `edgeTransitions` (gated on `hasTransitions`) or `edgeMatching`. On the atlas path both are null, and `transitionLookup.atlas` — which `resolve_branch_transition` consults (`:6718–6730`) — is **never read here**. Therefore on the authoritative path:

1. every observed step is `QuarterTurn(0)`; the guard `routeTransport.rotation != 0 → PeriodicHolonomyMismatch` (`:15000`) is **unreachable**;
2. the strip BFS skips the closing edge with the comment "Cycle closure is validated by periodic holonomy below" (`:14369`), so producer-side closure is **unvalidated**;
3. the published `CanonicalRoute` step transports are identity regardless of A3 (the gauged field's raw +1/−1 steps are published as 0), and `SurfacePhaseFrontProduct::make` does not check route steps against the atlas.

A nonzero-monodromy atlas can only be caught later by `make`'s gauge-pin (`:8569–8582`, `InvalidSourceAuthority`, `gauge-pin-consistency`). That is the wrong owner and reason, raised after the producer has claimed success. TB35-REV's sentence "A4 sees the unchanged atlas and therefore a zero canonical route rotation" is **false**: the zero is a constant, independent of any atlas. Its DEFN, which asked for an authoritative nonzero negative, would have yielded a negative that the current producer cannot reject at the guard.

#### RA-152.3 — History TB35-REV did not record

At the accepted 449 prefix (`993932656`), 189–192 called `build_periodic_route_network(fixture, field)` with **no atlas**: legacy single-field ingress whose containers the producer read. R3 made A4 require A3; R4 (`7ccdcd527`, 2026-10-11) rewired them through `build_periodic_route_network_with_source_atlas`, which structurally discards the mutated containers. 191/192 became unsatisfiable on that change, not on TB35. 193 is also non-discriminating at A4 today: its "nonzero steps" never reach the route (item 2.3), and its rotation assertion checks a hard-coded identity action.

#### RA-152.4 — Contract decisions

- **D1 single writer.** On the atlas path, A4 reads transitions **only** from the atlas. Rejected: passing the containers through, or cross-checking them against the atlas in A4. Either re-admits raw containers as a second writer contrary to R3 and to the overload's own contract; and a cross-check reports a located mismatch, which 192's location-free assertions would not match anyway.
- **D2 F1 owner.** In the observed-step loop, when `transitionLookup.atlas != nullptr`, take each step's rotation from `atlas->transport(edge, source, target)->transport`, the same accessor branch propagation uses. A missing transport fails closed with `PeriodicHolonomyMismatch(face, targetFace)`. The guard itself, the cut route, the action and the legacy branches stay unchanged. Closed-loop composition is gauge invariant, so positives keep rotation 0.
- **D3 witness first.** A real nonzero monodromy must come from a geometrically valid field: rotate each face's raw cross by `α = k·(π/2)·φ/2π` about its normal (φ = azimuth about the cylinder axis), then finalize with the production `finalize_surface_cell_raw_cross_field`. k=2 is A3-admissible for either boundary-loop orientation (correction ≡ 0 mod 4); k=1 is predicted admissible (boundary lifts ±1) and must be measured.
- **D4 frozen bodies.** 189–192 are not edited in this track. After F1 is green, a runtime-free DEFN rehomes them: 192 onto the k=1 authoritative field with all assertions kept; 191 onto A3 ingress integrity, since `CrossFieldEdgeTransition::sourceEdge` is consumed by no authority on the atlas path (A3 keys by vertex pair, `FieldTransportAtlas.cpp:1958–1971`); 189/190 onto A3-level normalization, or retired as legacy-ingress oracles.
- **Carried (RA-152.5).** Tracing axes come from `tracingField` while transports come from the atlas's source field, and nothing binds the two (split authority on directions). This is a candidate obligation, not scheduled; falsifier: an un-relabelled tracing field over a gauged atlas Produces.

#### RA-152.6 — Turn sequence (each narrow; independently reviewable)

| # | Turn | Scope / gate |
|---|---|---|
| 1 | `M6-CP3-CB35-RP01-PERIODIC-MONODROMY-WITNESS` | Test-only: helper + 3 witness tests; compile only. [Plan](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_CB35_Periodic_Monodromy_Witness_Code_Build_Plan_20261024.md"). |
| 2 | `…-CB35-…-REV` | Static review; issues the TB36 manifest. |
| 3 | `M6-CP3-TB36-RP01-PERIODIC-MONODROMY-BASELINE` | Pre-fix: 3 witnesses + 191/192. Predicted: A3 accepts k=2 (k=1 measured); all 3 witnesses RED; record first reason. **STOP** if any witness is GREEN pre-fix, if A3 rejects k=2, or if a witness fails before the periodic producer. |
| 4 | `…-TB36-…-REV` | Adjudicate; authorize CB36. |
| 5 | `M6-CP3-CB36-RP01-PERIODIC-ROUTE-ATLAS-TRANSPORT` | Production D2 only (~15 lines in the observed-step loop); compile only. |
| 6 | `…-CB36-…-REV` → `M6-CP3-TB37-RP01-PERIODIC-ROUTE-ATLAS-VERIFY` → `…-REV` | TB37: witnesses GREEN, TB35's 13 cases unchanged except as predicted, **full 497 census**, because route digests and relation ids change. |
| 7 | `M6-CP3-DEFN-RP01-PERIODIC-LEGACY-ORACLE-HOMES` | D4, runtime-free; then one CB/TB pair. |
| 8 | Existing queue | Untyped 7 → `focused30:12` → `cp3entry:4` → `selector:442` → DEFN-T1 → census → RP-01 Review. |

#### Accounting

No change: stable 66/17/49, debt 1; CP2 491/491 accepted; TB32 481/500 candidate (19 RED); TB35 11/2 focused candidate; selector 497 frozen; RP-01 open, RP-02 unreached, Gate C suspended. F1 is a candidate production owner (non-stable) until TB36 measures it.

## `Architecture_M6_CP3_TB36_REV_Audit_Periodic_Route_Atlas_Transport_Decision_20261025.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_TB36_REV_Audit_Periodic_Route_Atlas_Transport_Decision_20261025.md`; moved verbatim.

### RA-153 — TB36-REV audit: D2 authorized as specified; RA-152 errata; TB37 split (2026-10-25)

**Turn:** `M6-CP3-TB36-RP01-PERIODIC-MONODROMY-BASELINE-REV-AUDIT` (Review). **Subject:** [TB36-REV](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_TB36_R1_Periodic_Monodromy_Baseline_Independent_Review_Decision_20261025.md"). **Decision:** TB36-REV is **accepted**: 0/5 pre-fix baseline, F1 confirmed, successor CB36 (D2 only). Three corrections are binding on CB36 and later turns, plus two errata to my own RA-152. This is static review; I did not re-hash TB36's artifacts and rely on TB36-REV's recorded hashes.

#### RA-153.1 — What the baseline establishes

- The RA-152 D3 predictions are confirmed. A3 admits both turning fields (k=1 and k=2): no singularities, route rotation ±k, `make` succeeds. Both reach A4 and end as `PublishedProductRejected(68)`, i.e. the `make` backstop after the producer passed its dead guard. This is the outcome RA-152 allowed, not a STOP.
- The directed-route witness passes its 32-step topology, orientation, kind, compact-id and reversal checks, then fails at the first odd-step assertion. The route really is published with identity steps.
- TB36-REV correctly refuses to name the hidden `make` sub-site, because the logs don't print `publishedProductError`.

#### RA-153.2 — Errata to RA-152 (mine)

- **E1.** RA-152 D4 said that `CrossFieldEdgeTransition::sourceEdge` "is consumed by no authority on the atlas path". **Wrong.** A3 rejects `raw.sourceEdge != edgeIndex` with `NonReciprocalAdjacency` (`FieldTransportAtlas.cpp:2020–2027`). The authoritative fail-closed home for 191's property therefore already exists at A3; D4 for 191 reduces to retiring the A4-level body in favour of an A3 negative.
- **E2.** RA-152.6 said D2 changes "route digests and relation ids". Relation ids do **not** change: `periodic_relation_id` hashes `carrier_identity()` (kind, topology, interior id; `AuthorityKernel.cpp:110–129`), not transports. Only the published route step transports change. `oriented_steps()` keeps the observed order (`:91–96`), so the directed-route oracle's index alignment survives D2.

#### RA-153.3 — Binding CB36 specification (tightens TB36-REV's wording)

- **Edit site:** `SurfaceCellTracing.cpp:14937–14982` only.
  - Add a first branch `if (transitionLookup.atlas != nullptr)`. In it, take `atlas->transport(*sharedKey, faceCycle[index], faceCycle[(index+1)%n])` and use its `.transport` directly as the step rotation.
  - The existing legacy branches stay as `else if` and keep `from_integer(matching)`.
  - Nothing else changes: the guard at `:15000`, the action, the cut route, the BFS, the overload and `make`.
- **Accessor:** `transport()` (the traversable adjacency), the same accessor branch propagation uses (`:6718–6730`). The sibling `generator_route_for_span` (`:18772`) uses `transition_value()`. The two carry identical raw quarter-turns on traversable edges (`FieldTransportAtlas.cpp:2033–2063`), and `transport()` additionally refuses hard and cross-region edges, which the strip BFS already requires. A periodic route must not cross either.
- **Failure:** a missing transport rejects with `PeriodicHolonomyMismatch` and the loop's existing locus convention `(-1, -1, sourceFace, targetFace, -1, sourceEdge)`.
  - This branch is **unreachable through public inputs**: the strip BFS has already resolved every strip edge through `transport()`.
  - CB36-REV verifies it statically. No runtime witness may be demanded or fabricated for it. TB36-REV's falsifier "missing transport accepted or lacking locus" is static-only.
- **Sufficiency:** the guard checks only the first strip's face cycle. That suffices because every strip loop of the annulus is homologous and A3 has validated every local-vertex cycle, so all strip monodromies are equal.

#### RA-153.4 — TB37 split and pre-registered predictions

TB36-REV bundled the witnesses, TB35's 13 cases and a full 497-row census into one runtime turn. That is split:

- **TB37, focused, 16 rows:** the 3 witnesses + TB35's 13, which include 189–195.
  - **Predicted:**
    - k=1 and k=2 **GREEN** (reason 29, locations −1);
    - directed route **GREEN** (route[0] ±1, route[1] its inverse);
    - 189, 190, 193, 194, 195, the face-gauge oracle, both A3 guards and all 3 TB33 controls **PASS**;
    - 191 and 192 **RED unchanged** (`Produced`/`None`), since D1 means their container mutations stay invisible.
  - **STOP → Review if:**
    - k=1 or k=2 still ends in reason 68 (next turn: a test-side diagnostic that prints `publishedProductError`/site, not a production change);
    - 191 or 192 changes disposition, which would mean containers leaked into A4;
    - any TB35 PASS turns RED.
- **TB38, full 497-row census:** a separate turn after TB37-REV, against TB32's 481/500 ledger. Predicted: no accepted-green loss. Any loss → STOP.

#### RA-153.5 — Turn sequence

| # | Turn | Scope / gate |
|---|---|---|
| 1 | `M6-CP3-CB36-RP01-PERIODIC-ROUTE-ATLAS-TRANSPORT` | D2 per RA-153.3; compile only. [Plan](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_CB36_Periodic_Route_Atlas_Transport_Code_Build_Plan_20261025.md"). |
| 2 | `…-CB36-…-REV` | Static review; issues the TB37 16-row manifest with the RA-153.4 predictions. |
| 3 | `M6-CP3-TB37-RP01-PERIODIC-ROUTE-ATLAS-VERIFY` → `…-REV` | Focused 16 rows. |
| 4 | `M6-CP3-TB38-RP01-PERIODIC-ROUTE-ATLAS-CENSUS` → `…-REV` | Full 497 census. |
| 5 | `M6-CP3-DEFN-RP01-PERIODIC-LEGACY-ORACLE-HOMES` → CB/TB | D4 with E1: 191 → A3 `NonReciprocalAdjacency`; 192 → k=1 field; 189/190 → A3-level or retired. |
| 6 | Existing queue | Untyped 7 → `focused30:12` → `cp3entry:4` → `selector:442` → DEFN-T1 → census → RP-01 Review. |

**Accounting:** unchanged. Stable 66/17/49, debt 1; CP2 491/491 accepted; TB32 481/500 candidate (19 RED); TB35 11/13 and TB36 0/5 are focused candidates; selector 497 frozen; RP-01 open, RP-02 unreached, Gate C suspended.

## `Architecture_M6_CP3_TB37_REV_Audit_Periodic_Census_Manifest_Decision_20261025.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_TB37_REV_Audit_Periodic_Census_Manifest_Decision_20261025.md`; moved verbatim.

### RA-154 — TB37-REV audit; Review-owned TB38 census manifest (2026-10-25)

**Turn:** `M6-CP3-TB37-RP01-PERIODIC-ROUTE-ATLAS-VERIFY-REV-AUDIT`. **Decision:** TB37-REV **ACCEPTED** (focused D2 evidence). Its TB38 hand-off is **under-specified and is replaced** by RA-154.4. Static review plus independent artifact re-verification; no build, test or product change.

#### RA-154.1 Independent verification

- TB37 result artifact `12593545901` re-downloaded: ZIP SHA-256 `d7fd939b…1348` matches; **21/21** `SHA256SUMS` OK; ledger 14 PASS / 2 RED; raw/1–3 each `[ OK ]` one test; raw/6 fails at the `Rejected` disposition assertion with actual `01` (Produced) and reason `00` (None). The TB37-REV adjudication of the harness flag is correct.
- The CB36 hunk (`SurfaceCellTracing.cpp:14937–14998`) matches RA-153.3 exactly. `git diff 038ae7fd7..HEAD` touches no `src`, `include`, `tests`, `benchmarks`, CMake or selector file, so package `12590917524` is still current.
- **Witness discrimination holds.** k=1 and k=2 assert reason 29 with **every** location −1. Only the route guard (`:15015`, no locus) produces that. The new missing-transport branch would carry face/edge loci, and `make` would give 68.

#### RA-154.2 Gaps in TB37-REV

- **G1 — TB38 had no Review-issued manifest and no per-row predictions.** "Unexplained discrepancy against the 19 inherited RED" cannot be falsified. Replaced by RA-154.4.
- **G2: one root class is spread across the "untyped" queue.** Three supposedly untyped REDs are tamper oracles stranded by the atlas rewiring, the same class as 191/192. Each test builds A3 from the unmodified field, tampers only the tracing copy, expects `Rejected`, and gets `Produced`. The TB32 raw logs confirm this.

  | Selector | Area | Tamper | Expected reason | Rewired in | Twin |
  |---|---|---|---|---|---|
  | 204 | segment route | `sourceEdge = -1` (`Phase10Tests:~1631`) | — | `4ee15ada1`, 2026-10-11 | 191 |
  | 242 | isolation seam | `matching += 1` (`:3354`) | `InvalidTopologyRegionTransport` | — | — |
  | 247 | periodic | `matching += 1` (`:5236`) | `PeriodicHolonomyMismatch` | `285a50105`, 2026-10-11 | 192 |

  Under RA-152 D1 (single writer), A4 does not consume tracing containers, so these oracles cannot be satisfied by design. They are not producer defects.
  - **Real untyped remainder:** 174 (DCEL exception) and 201 (REPackage terminal vertex).
  - **Already typed:** 405 (`InvalidHardRailRouteCertificate`, `endpoint-0`) and 250 (68, see G3).
- **G3 — `selector:250` is D2-reachable and was not flagged.** TB32 `raw/292.log` shows a positive periodic composition through the atlas ending `PublishedProductRejected` (68), the same outward signature as the pre-D2 witnesses. Statically, `make`'s gauge-pin check (`:8565–8582`) compares face branch rotations, not route steps, so D2 is **not** predicted to clear it. Any first-failure drift on 250 is admissible but must be adjudicated, not credited. The `make` sub-site is unmeasured, so 250 counts as a typed-outcome periodic owner, not untyped.
- **G4 — do not fix the TB37 harness; retire it.** TB38 reuses `tools/m6_cp3_targeted_artifact_harness.sh` unchanged (SHA-256 `436f5fff…3c9a`, the TB32 harness). It classifies by GTest terminal markers and exit code, not enum text. `control_bad>0` already fails the run, and `unexpected_pass` is recorded without being fatal.
- **G5 — compare first failures by assertion, not line number.** CB34/CB35 shifted `SurfaceCellsPhase10Tests.cpp` lines (247: 4933 → ~5240). TB38-REV must match the asserted statement and its expected and actual values.

#### RA-154.3 Observation O1 (recorded, no owner now)

- **Cut-route steps still publish identity.** The periodic cut-route steps (`SurfaceCellTracing.cpp:~15052`) carry `GridAutomorphism::identity()`, while observed steps now carry the raw atlas transport.
- **No consumer composes cut-step transports today.** The consumers are route equality, `periodic_relation_id`, diagnostics and the product digest.
- **The product digest moves for some products.** It hashes every step transport (`RemeshPipeline.cpp:1837–1851, 2191–2192`), so D2 changes the A4 digest of any produced periodic product with non-identity raw step transport. No test pins a literal digest, but cross-run digest equality across the CB36 boundary is **not** a regression signal.
- **Rule going forward:** any future consumer that composes `cutRoute()` transports must first source them from the atlas (RA-152.5 / DEFN scope).

#### RA-154.4 TB38 binding specification

- **Package:** CB36 `12590917524` (ZIP SHA-256 `6dcbfe5a…7d03`), source `038ae7fd7`.
- **Harness:** `m6_cp3_targeted_artifact_harness.sh` unchanged, SHA-256 `436f5fff9c3bec97457f4bc6b7c2b6182cb3f47707eb14a66af3b6a3f3dc3c9a`.
- **Manifest:** `Architecture_M6_CP3_TB38_Periodic_Route_Atlas_Census_Case_Manifest.tsv`, **504 rows**, SHA-256 `b27eecb6b4f6f32fd060b8510a0cabf71f86b8fe1028dbb10c36003867dcf8c2`; `--self-check … 504` PASS.
  - Rows 1–500 carry TB32 manifest `597741…6437` identities, tests, binaries and order unchanged. Only rows 231/232/235/236/237 (`selector:189,190,193,194,195`) flip from RED to GUARD/PASS.
  - Rows 501–504 are the three TB36 witnesses plus `BalancedRouteFieldIsPureFaceGauge` (GUARD).
- **Prediction:** **490 PASS / 14 RED.** On the 497 selector that is 483/14, against TB32's 478/19.
- **The 14 RED:**
  - `focused30:12`, `cp3entry:1/2/4`, `selector:442`, 174, 201, 405: same first-failure assertion as TB32;
  - 191, 192, 204, 242, 247: the `Rejected` assertion fails with Produced;
  - 250: RED, with drift admissible.
- **STOP → TB38-REV:**
  - any GUARD row not PASS (an accepted-green or control loss);
  - any of the 14 RED passing (record it, no credit);
  - a first-failure assertion change on any RED except 250;
  - any integrity failure (hash, selection, duplicate, skip, postflight).
- **Prohibited:** any source, test, harness, manifest or selector edit; any compile; CP3 promotion.

#### RA-154.5 Turn sequence

1. `M6-CP3-TB38-RP01-PERIODIC-ROUTE-ATLAS-CENSUS` → `…-REV`.
2. `M6-CP3-DEFN-RP01-ATLAS-INGRESS-TAMPER-ORACLE-HOMES` replaces the periodic-only DEFN. It is design only; scope 189, 190, 191, 192, 204, 242, 247; then DEFN-REV.
   - For each oracle, decide its stated property, its authoritative home, keep-identity-with-re-homed-ingress versus retire, and selector bookkeeping.
   - Also list any test outside the selector with the same pattern, e.g. `CurvedBoundedDiskInvalidReciprocalTransportFailsClosed` (`:3580`).
   - Recommended homes:
     - 191 and 204: A3 `NonReciprocalAdjacency` negatives (E1).
     - 192 and 247: atlas-built k=1/k=2 fields, or retire as superseded by TB36 witnesses 1/2.
     - 242: an A3 negative from the tampered field.
     - 189/190: state what they discriminate under atlas ingress, or retire.
3. Test-only CB groups, compile only, each followed by its REV. One focused TB → REV after all three.
   - **A:** 191 + 204.
   - **B:** 192 + 247.
   - **C:** 242 + 189/190.
4. **Only if** TB38 still shows 68 for 250: a diagnostic turn that adds a test-side print of the `publishedProductError` code and site. Diagnostic only.
5. Owner queue in order:
   - 405 (A4 hard-rail certificate `endpoint-0`);
   - 174 and 201 (untyped);
   - `focused30:12`;
   - `cp3entry:4`;
   - `selector:442`;
   - DEFN-T1 (`cp3entry:1/2`);
   - census;
   - RP-01 Review.

   Carried: `DIAG-RETAIN`, RA-152.5, DEFN-SEAM-NZ, RA-146.2/4, RA-45.4 and G4-B002.

**Accounting unchanged:** stable 66/17/49, debt 1; CP2 491/491 accepted; TB32 481/500 candidate; TB37 14/16 focused accepted; selector497 frozen; RP-01 open.

## `Architecture_M6_CP3_TB38_REV_Audit_Tamper_Oracle_Homes_Decision_20261025.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_TB38_REV_Audit_Tamper_Oracle_Homes_Decision_20261025.md`; moved verbatim.

### RA-155 — TB38-REV audit; tamper-oracle homes bound; 250 site first (2026-10-25)

**Turn:** `M6-CP3-TB38-RP01-PERIODIC-ROUTE-ATLAS-CENSUS-REV-AUDIT`. **Decision:** TB38-REV **ACCEPTED** (candidate census 490/14). Its successor, a single seven-oracle DEFN turn, is **replaced**. Review binds the determinate homes here (RA-155.3) and narrows the DEFN to the two oracles that cannot yet be decided (RA-155.4). Static review plus independent artifact re-verification; no build, test or product change.

#### RA-155.1 Independent verification

- TB38 result artifact `12597140251` re-downloaded:
  - ZIP SHA-256 `0cdfe445…a9870` matches; **1,014/1,014** `SHA256SUMS` OK.
  - `execution-boundary.json`: 504/504 executed, 490 PASS / 14 RED; missing, skipped, duplicate, `control_bad` and `unexpected_pass` all 0; `postflight=true`.
  - The 14 RED identities match RA-154.4.
- Raw logs 233/234 (191/192) fail at the `Rejected` assertion with Produced. Raw log 292 (250) is still `PublishedProductRejected` (68).
- TB38-REV's table is correct.

#### RA-155.2 Gaps in TB38-REV

- **H1 — the successor is monolithic.** One DEFN covering seven oracles with different mechanisms, several of them decidable statically now. Replaced by RA-155.3/.4.
- **H2 — test 190 is architecturally unsatisfiable, not merely "non-discriminating".**
  - `SurfacePhaseFrontProduct::make` rejects a null atlas (`SurfaceCellTracing.cpp:8462`, `atlas-binding`).
  - A3 cannot be built from a legacy-only field: `edgeTransitions` is empty, so `MissingAdjacency` (`FieldTransportAtlas.cpp:2017`).
  - So no legacy matching path can ever publish a product.
  - **O2:** the producer's legacy branches (`SurfaceCellTracing.cpp:14950–14979`) and the legacy branch of `resolve_branch_transition` (`:6731ff`) are unreachable for any produced output. Removing them is a later DEFN, not now.
- **H3 — 242 does not belong with the others.**
  - Its tampered edge is cross-region (sheets `{0,1}`). A3 keeps the `transition_value` but builds no adjacency for it (`FieldTransportAtlas.cpp:2050–2057`).
  - A4 branch propagation reads `transport()` and never crosses that edge, and the `make` gauge-pin skips cross-region edges (`SurfaceCellTracing.cpp:8558–8561`).
  - A single-record `matching += 1` is reciprocal by construction, because A3 derives `reverse = forward.inverse()`.
  - No A2–A4 consumer exists for the stimulus. Its home is downstream (isolation-seam certificate; DEFN-SEAM-NZ), or the test retires.
- **H4 — test 192's own stimulus is not a monodromy.** A single-edge `+2` (`assign_directed_matching`) fed to A3 is rejected at S1 `CycleTransportMismatch` (the TB34 mechanism). Re-homing therefore needs the turning field, not the existing stimulus.
- **H5 — the 250 diagnostic was left conditional, though its condition was met.** 68 persisted in TB38. The checked-factory rejection already carries `publishedProductError`, `publishedProductSourceAuthorityDetail` and `publishedProductSourceAuthoritySite` (`SurfaceCellTracing.cpp:13196–13201`), so a message-only test change exposes the exact `make` site. Test 250 is the only **positive** periodic composition still failing, which makes it the highest-value item on the RP-01 trajectory. **It goes first.**

#### RA-155.3 Bound homes

All re-homes below are test-only. Each keeps its test identity, so no selector byte changes.

- **A — 191 and 204 (`sourceEdge = -1`):**
  - The tampered field becomes the **A3 input**.
  - Assert the untampered `FieldTransportAtlas::make` succeeds.
  - Assert the tampered `make` fails with `NonReciprocalAdjacency` and `error.sourceEdge ==` the tampered topology key.
  - Do not call A4 on the tampered input.
  - This covers the A3 branch `raw.sourceEdge != edgeIndex` (`FieldTransportAtlas.cpp:2020`), which **no existing test** covers; the `FieldTransportAtlasTests` matrix tampers faces only.
  - Moving the expected failure from A4 (29 / `MissingTransitionProvenance`) to A3 is authorized here. It relocates the failure to the single writer and is not a relaxation.
- **B — 192 and 247 (monodromy):**
  - Replace the stimulus with an atlas built from a turning field: 192 uses k=1 via `turning_periodic_route_field`; 247 uses k=2 on the committed cylinder and rawfield (a mesh-level overload of that helper is allowed).
  - Keep every original A4 assertion: Rejected, 29, no product, empty seeds/traces/proposals, and for 192 the all-−1 locus.
  - Keep each positive half, and assert A3 succeeds and `singularIndices` is empty.
- **C — 189 (equivalent lift):**
  - Build each run's A3 from **its own** field: baseline, and the ±4 equivalent.
  - Assert both A3 builds succeed and the A4 periodic snapshots are equal.
  - This discriminates whether the raw lift (`signedLift`) leaks into A4. The current version is vacuous because the ±4 copy is never consumed.

#### RA-155.4 Narrowed DEFN (after the CB groups)

`M6-CP3-DEFN-RP01-LEGACY-PATH-AND-SEAM-ORACLES`, design only:
- **190:** retire it, or re-home it as an A3 `MissingAdjacency` negative. Either way it needs an accounting rule for an identity in the accepted prefix.
- **242:** find a downstream consumer of cross-region `transition_value`, or retire it; coordinate with DEFN-SEAM-NZ.
- **O2:** the scope for removing the legacy branches.
- Also inventory the out-of-selector analogue `CurvedBoundedDiskInvalidReciprocalTransportFailsClosed` (`Phase10Tests:~3580`).

#### RA-155.5 CB37 specification (next turn)

- **Turn:** `M6-CP3-CB37-RP01-SELECTOR250-FACTORY-SITE-MESSAGE`, test-only, compile only.
- **Edit:** `tests/SurfaceCellsPhase10Tests.cpp:3666–3669` only, the **streamed message** of the existing `ASSERT_EQ(Produced, …)`. Replace it with `curved_disk_factory_rejection_detail(network.phaseFront)` (helper at `:2630`, which prints the reason, `publishedProductError` and the detail), followed by `" site="` and `rejection()->publishedProductSourceAuthoritySite`, null-guarded.
- **Must not change:** the assertion's operands or macro; any other line; production code; selectors; the harness.
- **Evidence:** the 8 GMP/GMPXX targets, `runtimeExecution=false`, and a record of 30 lines or fewer with the exact hunk.
- **STOP:** the helper is not visible at `:3666`, or the field name differs.

#### RA-155.6 Turn sequence

1. CB37 (250 message) → CB37-REV (static; issues the TB39 manifest).
2. `M6-CP3-TB39-RP01-SELECTOR250-FACTORY-SITE-HARVEST`, artifact-only on the targeted harness. Rows: 250 (RED, site harvested) plus the 3 TB36 witnesses and 193–195 as GUARD. Then TB39-REV classifies the site:
   - codes 56–66 → periodic action convention (links to O1);
   - code 0 / `InvalidSourceAuthority` → the reported site;
   - otherwise as typed.
   - It then binds the 250 owner.
3. CB38-A (191+204) → REV.
4. CB39-B (192+247) → REV.
5. CB40-C (189) → REV.
6. TB40, focused on the re-homes: 189, 191, 192, 204, 247 plus guards (TB36 witnesses, 193–195, the two A3 guards). Then TB40-REV.
7. DEFN legacy-path and seam oracles (RA-155.4) → REV → its CB/TB.
8. 250 owner turns, per the TB39-REV binding.
9. 405 → 174, 201 → `focused30:12` → `cp3entry:4` → `selector:442` → DEFN-T1 (`cp3entry:1/2`) → census → RP-01 Review.

Carried: `DIAG-RETAIN`, O1, O2, RA-152.5, DEFN-SEAM-NZ, RA-146.2/4, RA-45.4, G4-B002.

**Accounting unchanged:** stable 66/17/49, debt 1; CP2 491/491 accepted; TB32 481/500 and TB38 490/504 candidate; selector497 frozen; RP-01 open, RP-02 unreached.

## `Architecture_M6_CP3_TB39_REV_Audit_Selector250_Rail_Provenance_Decision_20261025.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_TB39_REV_Audit_Selector250_Rail_Provenance_Decision_20261025.md`; moved verbatim.

### RA-156 — TB39-REV audit: selector250 rail-authority owner bound and promoted (2026-10-25)

**Turn:** `M6-CP3-TB39-RP01-SELECTOR250-FACTORY-SITE-HARVEST-REV-AUDIT`. **Verdict:** TB39-REV's classification is **accepted**: the factory check that fires is `hard-rail-contact-missing`, owned by the test fixture and not by O1. Its corrective requirement and its sequencing are **replaced**. Static review only; no source, test, selector or harness change.

#### RA-156.1 Independent verification

- TB39 result `12609665120` re-downloaded: ZIP `10af6fa8…1f06`, **17/17** `SHA256SUMS`, and the 7 ledger log hashes match the raw logs. 7/7 run, 6 GUARD PASS, 250 RED; 0 missing/skipped/duplicate/control_bad/unexpected_pass; postflight true; no compile, relink or configure. Manifest `a304aeeb…cc61` re-hashed.
- `raw/1.log:13`: `PublishedProductRejected publishedProductError=0 publishedProductSourceAuthorityDetail=6 site=hard-rail-contact-missing`. These values decode to `InvalidSourceAuthority=0` (`SurfaceCellTracing.h:1901`) and `MissingRailTerminalContact=6` (`:1932`). The only site is `SurfaceCellTracing.cpp:8655–8661`: the fixture has hard-feature edges but no terminal contacts and no closed chains.

#### RA-156.2 Gaps in TB39-REV

- **J1 — the corrective requirement is under-specified, and it names the wrong owner.**
  - Test 250 (`SurfaceCellsPhase10Tests.cpp:3610`) already calls `make_curved_disk_fixture()`. That fixture builds the disk's full rail authority through the production functions at `:2582–2626`: `build_authoritative_surface_cell_rails`, then `hard_rail_source_provenance_from_rails`, plus the check `hard_feature_edge_keys_from_rails == hardFeatureEdges`.
  - Test 250 copies only `disk.vertices` and `disk.faces`. It re-inserts the 8 boundary hard edges (`:3647–3660`) and **drops all four authority fields**: `authoritativeRails`, `hardRailTerminalContacts`, `hardRailClosedChains` and `hardRailOpenChains`.
  - So the defect is not only "missing factory provenance". Without `authoritativeRails`, A4 tracing also gets no hard-rail seeds for the disk sheet (`SurfaceCellTracing.cpp:10285–10310`). Test 250 therefore never exercised the disk contract that the passing tests 199, 235 and 236 exercise.
  - Supplying only contacts or chains would get past the factory check while leaving tracing on a different contract. "Derive provenance where possible" is not a binding requirement.
  - The binding requirement is RA-156.3: derive all four fields from one combined-mesh feature map, through the production functions, which is the same path as `RemeshPipeline.cpp:12633–12785`.
- **J2 — sequencing.** Test 250's owner was placed last when the owner was unknown. It is now known, small and test-only. 250 is the only positive periodic-plus-disk composition, so its outcome decides whether RP-01 still has an unmeasured positive-path prerequisite downstream (O1 among them). The A/B/C re-homes are negative-oracle hygiene and nothing downstream depends on them. **The 250 owner moves first.**
- **J3 — new observation O3: the polygonal-disk rejection tests share the same omission and are vacuous on the reason alone.**
  - The polygonal fixture (`:2818`) supplies hard edges but no rail authority.
  - Three tests assert only `InvalidBoundedDiskFrontPairing`: 252 (`:3764`), 251 (`:2971`, forward and reversed runs) and the off-selector `PolygonalCurvedDiskRejectsWithoutPublishingPartialPhase` (`:2936`). That reason is emitted at 5 sites (`SurfaceCellTracing.cpp:17190, 17889, 17948, 17969, 18034`).
  - Only the designed non-rectangular site (`:17184–17191`) leaves both `cell` and `side` at −1; every other site sets one of them.
  - 17969 depends on `path_on_authoritative_boundary`, which uses rail authority. So a run with missing rails could satisfy the oracle at an unintended site.
  - Fix (test-only, CB42): in those three tests, also assert `rejection()->cell == -1 && rejection()->side == -1`.
  - Inventory only, not in CB42: the off-selector `CurvedBoundedDiskPhaseFrontIsStructurallyApplicable` (`:3380`) accepts any of four rejection reasons.
- **J4 — guard selection.**
  - The focused positive disk witness `CurvedBoundedDiskPhaseFrontIsStructurallyApplicable` (`:3380`) is outside selector497 and unmeasured.
  - The `MissingRailTerminalContact` negative `M6CP3.CheckedFactoryRejectsForgedTerminalA2bSideGerm` (`SurfaceCellTransitionQuotientTests.cpp:10092`) was last measured RED (R4, 2026-10-15).
  - Neither may be a GUARD. Use the in-selector PASS rows 199, 235, 236, 249, 251 and 252 instead.
- **J5 — documentation drift.** The handoff Turn Sequence jumped from "1" to "4", and "CB38-A" is not a canonical turn name. Both are corrected below.

#### RA-156.3 Bound spec — `M6-CP3-CB38-RP01-SELECTOR250-RAIL-AUTHORITY` (Code + Build, test-only, compile only)

- **Edit:** only the body of test 250, inline, with no new helper.
- Build an `AdaptiveFeatureMap` on the combined `mesh`:
  - one closed `Hard` curve with `component=2`;
  - ring `{0,1,2,5,8,7,6,3,0}` plus `diskOffset`;
  - each edge's `incidentFaces` computed from the combined `faces`; the test throws if any edge does not have exactly 1 incident face.
- Call `build_authoritative_surface_cell_rails(mesh, features)`. Require that it produces exactly 1 closed rail.
- Set `options.authoritativeRails` and the three provenance maps from `hard_rail_source_provenance_from_rails(rails, mesh.V.rows())`.
- Require that `closedChains` is non-empty and `hard_feature_edge_keys_from_rails(...) == options.hardFeatureEdges`. Do this before `build_phase10_with_source_atlas`.
- **Unchanged:**
  - the 8 `hardFeatureEdges` insertions;
  - the assertion at `:3666` and its CB37 message;
  - every later assertion;
  - `make_curved_disk_fixture`;
  - production code, selectors, the harness and workflows.
- **STOP and return to Review if:**
  - the rail builder rejects (for example, because component 2 is not the disk's connectivity component);
  - the edge-key identity differs;
  - any edit outside test 250 or the helper is needed.

#### RA-156.4 TB40 manifest outline (CB38-REV freezes it; unmodified harness `436f5fff…`)

- **Test 250 row:** kind `RED`, expect `RED`. The outcome is genuinely open. A PASS is recorded as `unexpected_pass`, which is the success signal. A new rejection is a newly measured prerequisite and must not be patched inside TB40.
- **GUARD rows:** 199, 235, 236, 249, 251, 252, the three TB36 witnesses, and 193–195.
- **TB40-REV:**
  - if 250 PASSes, record it as a discharged candidate (no promotion);
  - otherwise, bind exactly one owner for the new first failure.

#### RA-156.5 Sequence (supersedes RA-155.6 order and the TB39-REV order)

1. CB38 (250 rail authority) → CB38-REV, which freezes the TB40 manifest.
2. TB40 → TB40-REV.
3. CB39-A (191 and 204 → A3 `NonReciprocalAdjacency`; RA-155.3 A) → REV.
4. CB40-B (192 with k=1, 247 with k=2; RA-155.3 B) → REV.
5. CB41-C (189; RA-155.3 C) → REV.
6. CB42-O3 (pin the polygonal locus at `cell=-1`, `side=-1` in 251, 252 and `:2936`; J3) → REV.
7. TB41 focused run (189, 191, 192, 204, 247, 251, 252, plus guards) → REV.
8. `M6-CP3-DEFN-RP01-LEGACY-PATH-AND-SEAM-ORACLES` (190, 242, O2) → REV.
9. Any owner bound by TB40-REV, then 405 → 174, 201 → `focused30:12` → `cp3entry:4` → `selector:442` → DEFN-T1 → census → RP-01 Review.

Carried: `DIAG-RETAIN`, O1, O2, O3 (until CB42), RA-152.5, DEFN-SEAM-NZ, RA-146.2/4, RA-45.4, G4-B002.

**Accounting unchanged:**
- stable 66/17/49, debt 1;
- CP2 491/491 accepted;
- TB32 481/500 and TB38 490/504 candidate;
- selector497 frozen;
- RP-01 open; RP-02 unreached.

## `Architecture_M6_CP3_TB40_REV_Audit_CB39_A3_Tamper_Spec_Decision_20261025.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_TB40_REV_Audit_CB39_A3_Tamper_Spec_Decision_20261025.md`; moved verbatim.

### RA-157 — TB40-REV audit: 250 discharge confirmed; CB39 spec re-bound (2026-10-25)

**Turn:** `M6-CP3-TB40-RP01-SELECTOR250-RAIL-AUTHORITY-VERIFY-REV-AUDIT`. **Verdict:** TB40-REV is **accepted**. Selector250's focused candidate discharge stands, with no census, selector497 or CP3 promotion. The CB39 handoff it issued is **too vague to review against** and is replaced by RA-157.3. Static review only.

#### RA-157.1 Independent verification

- TB40 result `12616556389`: ZIP `84d63107…e7a320`, **29/29** `SHA256SUMS`, 13/13 ledger rows, `unexpected_pass=1` on 250 only, postflight true. `raw/1.log` holds one test, `[ OK ]`.
- Between `c9d7c80f6` and `41f39ba92`, the only change under `src`, `include`, `tests`, `cmake`, `benchmarks` and `tools` is `tests/SurfaceCellsPhase10Tests.cpp` +50/−0. The PASS is therefore attributable to the RA-156.3 rail authority.

#### RA-157.2 Findings

- **K1 — the CB39 handoff dropped the RA-155.3 A oracle.**
  - "Independent non-vacuous source support" and "preserve … original" do not say which A4 assertions go, what baseline proves the cause, or which error fields are asserted.
  - Code facts that bind the spec:
    - A3 keys transitions by `sourceVertex0`/`sourceVertex1` (`FieldTransportAtlas.cpp:1966–1975`). A `sourceEdge=-1` tamper is therefore found and reaches `:2020`, which returns `NonReciprocalAdjacency` with `error.sourceEdge = key`.
    - That `if` has five disjuncts sharing one code. The face disjuncts are false only because faces are untouched, so an **untampered-A3 success baseline is required** to attribute the failure to the `sourceEdge` disjunct.
    - A4 reads the atlas first (`authoritative_edge_transition_lookup`, `SurfaceCellTracing.cpp:12565`). TB38 confirms 204 is `Produced`/`None` (`raw` `:1634/1636`). The existing A4 negative blocks in 191 and 204 are unsatisfiable under D1 and must be **removed, not weakened**.
- **K2 — new observation O4.** CB39 removes the only witness of A4 `MissingTransitionProvenance` (`SurfaceCellTracing.cpp:12656, 12698, 12707`). Whether those sites are reachable with a valid A3 is unknown, like O2. Added to the scope of the legacy-path DEFN turn: inventory them, then bind a stimulus or classify them as defensive.
- **K3 — residual weakness, not scheduled.** 250's positive assertions check only per-sheet cell existence and the periodic owner. They do not check that the disk's cells respect the closed rail. Selector 236 covers that for the disk alone.
- **K4 — documentation drift.**
  - The tracker has two TB40-REV entries for one decision.
  - TODO's "EXACT NEXT" lists four turns.
  - The handoff sequence jumps from step 1 to step 3.
  - All three are corrected here.

#### RA-157.3 Bound spec — `M6-CP3-CB39-RP01-A3-SOURCE-EDGE-TAMPER-REHOME` (Code + Build, test-only, compile only)

- **Scope:** only the bodies of 204 (`SurfaceCellsPhase10Tests.cpp:1615`) and 191 (`:5053`). Test names and suites stay the same.
- **Each test:**
  1. Build A2 with `build_source_topology_regions(mesh.F, options)`, using the same options the current helper uses.
  2. `ASSERT_TRUE` that `FieldTransportAtlas::make(mesh, A2, hardFeatureEdges, untamperedField)` succeeds; this is the baseline.
  3. Apply the existing `sourceEdge = -1` tamper, unchanged.
  4. Run `make` on the tampered field and assert `!result`, `result.error().code == NonReciprocalAdjacency` and `result.error().sourceEdge == tamperedKey`.
- **Per test:**
  - **204** keeps its untampered A4 baseline: `Produced` plus non-empty route observations. Its tampered key is `fixture.forwardRoute.sourceTopology[1]`, i.e. edge (6,7). Its untampered field is `fixture.authoritativeField`, on the segment-route plane mesh.
  - **191** uses `balanced_periodic_route_field(fixture)` as the untampered field. Its tampered key is `fixture.expectedRoute.front().currentTopology`. It uses the periodic cylinder mesh with the periodic helper's options.
- **Remove:** in both tests, the A4 call on the tampered field and its rejection assertions. There must be no A4 call on tampered input.
- **Unchanged:** fixtures, helpers, other tests, production code, selectors, the harness and workflows.
- **STOP → Review if:**
  - a fixture's A2 options cannot be reproduced without editing a helper;
  - the baseline `make` fails;
  - the expected key is not interior.
- **Evidence:** 8 GMP/GMPXX targets, `runtimeExecution=false`, and a record of 30 lines or fewer with the exact hunks.

#### RA-157.4 Sequence

1. CB39 → CB39-REV, which freezes the TB41 rows for 191 and 204.
2. `M6-CP3-CB40-RP01-TURNING-FIELD-MONODROMY-REHOME` (192, 247) → REV.
3. `M6-CP3-CB41-RP01-EQUIVALENT-LIFT-A3-INGRESS-REHOME` (189) → REV.
4. `M6-CP3-CB42-RP01-POLYGONAL-DISK-LOCUS-PIN` (251, 252, `:2936`) → REV.
5. `M6-CP3-TB41-RP01-REHOMED-ORACLE-VERIFY` → REV.
6. `M6-CP3-DEFN-RP01-LEGACY-PATH-AND-SEAM-ORACLES` (190, 242, O2, O4) → REV.
7. 405 → 174, 201 → `focused30:12` → `cp3entry:4` → `selector:442` → DEFN-T1 → census → RP-01 Review.

Carried: `DIAG-RETAIN`, O1, O2, O3, O4, RA-152.5, DEFN-SEAM-NZ, RA-146.2/4, RA-45.4, G4-B002.

**Accounting unchanged:**
- stable 66/17/49, debt 1;
- CP2 491/491 accepted;
- TB38 490/504 candidate; 250 is a focused candidate;
- selector497 frozen;
- RP-01 open.

## `Architecture_M6_CP3_DEFN_Legacy_Matching_Path_Disposition_Review_Decision_20261026.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_DEFN_Legacy_Matching_Path_Disposition_Review_Decision_20261026.md`; moved verbatim.

### RA-160 — Legacy matching-path DEFN Review: 190 re-home amended; O2 production CB withdrawn (2026-10-26)

**Turn:** `M6-CP3-DEFN-RP01-LEGACY-MATCHING-PATH-DISPOSITION-REV`, run by the Review Agent. **Decision:** the [DEFN](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_DEFN_Legacy_Matching_Path_Disposition_20261026.md") is **ACCEPTED IN PART**.
- Q1–Q3 are accepted. Q2 is amended (RA-160.3).
- Q4–Q5 are **rejected as incomplete**, so the Q6 production CB is **not authorized**.
- O2 retirement moves after RP-01 (RA-160.4).

Method: static review on source `639730d06`, with no `src`/`tests` change since snapshot `2f183f913`. The selector449 SHA-256 `d4a0d1b7…d6414` was recomputed and is unchanged. No build or runtime.

#### RA-160.1 Verified claims

- **Q1 is correct, and stronger than RA-159 N2.**
  - When an atlas is present, `build_surface_cell_network(crossField)` passes `nullptr` for matching, effort and transitions (`SurfaceCellTracing.cpp:21182–21185`).
  - So `hasTransitions` is false in **both** 190 runs (`:14260`), and the provenance lookup at `:14926–14929` is identical.
  - `legacyField` is completely inert: it contributes only its axes (`:11508–11512`), which are copied unchanged.
  - **Correction to RA-159 N2:** RA-159 N2 said `legacyField` "selects the provenance lookup". That is wrong.
- **Q2 is feasible.**
  - `make(legacyField)` passes the preamble (`FieldTransportAtlas.cpp:1898–1912`; `matchingComputed`/`singularitiesComputed` are copied) and frame building, which reads only directions (`:257–260`).
  - The empty `edgeTransitions` then fails at the first interior edge in sorted key order with `MissingAdjacency` (`:1981–2018`).
- **Q3 is accepted.** CP2 credit for 190 is historical. The TB38/TB41 rows are vacuous. Selector bytes are unchanged.

#### RA-160.2 Defects

- **D1 — the Q2 re-home duplicates accepted coverage and drops the only pin the O2 work needs.**
  - A3 `MissingAdjacency` is already accepted at `selector:28` (`FieldTransportAtlas.RejectsStableAdjacencyTamperReasons`, `FieldTransportAtlasTests.cpp:2576–2593`).
  - Meanwhile **no test** pins the A4 no-atlas ingress outcome: `"atlas-binding"` appears in no test.
  - Yet the DEFN's production CB requires "preserving the precise checked rejection code/site". That condition has no oracle, so it could not be reviewed.
- **D2 — Q4 is false for NotApplicable inputs.**
  - The DEFN says missing A3 "reaches rejection only". That holds only when a phase-front producer runs.
  - For a no-feature input where every region is NotApplicable (`:18473–18481`), `publish_phase_front_result` returns NotApplicable (`:13158`) and the factory is never called.
  - The builder then runs the seed-tracing fallback (`:20661–21160`). It passes the **legacy containers** to `trace_surface_field` and `make_surface_cell_proposal`, and publishes `seeds`/`traces`/`proposals` (`accepted=true`) and `singularSeparatrices`.
  - So on test-only no-atlas ingress, legacy matching **does** decide published network outputs. This is the "legacy no-atlas entry contract" named at `:5802`.
- **D3 — Q4 omits public crossField APIs that ignore the atlas.**
  - `trace_surface_field(crossField)` (`:11527–11538`) always passes legacy containers, even when an atlas is set; it is atlas-first only because `resolve_branch_transition` checks the atlas first (`:6718`).
  - Its production caller `FlowRepStrands.cpp:3511` receives the pipeline options that carry the atlas (`RemeshPipeline.cpp:12979 → 13491`), so production is safe today. But removing branches without this inventory is unreviewable.
- **D4 — Q4/Q5 defer the inventory they were asked to deliver.** The planar, bounded and isolation call sites, and selector233, are left to a "separate census". Selector233 actually passes `&fixture.transitions` with no atlas: the raw-transition branch (`Phase10Tests:5687`).
- **D5 — a fail-open default is unflagged.**
  - The periodic step leaves `stepRotation` at identity when there is no atlas, no transitions and no matching (`:14937–14979`; there is no `else` rejection).
  - The DEFN's "preserve first code/site" removal would require keeping this fail-open fall-through so the factory can still reject.
  - The correct design rejects no-atlas ingress at one entry gate. That changes the rejection locus, and it is a design decision for the post-RP-01 DEFN.

#### RA-160.3 Amended 190 re-home (test-only CB43)

All halves stay in `SurfaceCellPeriodicHolonomyRouteTransportAuthorityMigration.LegacyMatchingPathUsesSameTypedAlgebra` (`Phase10Tests:5171–5195`), with the same identity. Selector bytes do not change.

- **(a) Positive.** Keep the authoritative network: Produced, with one periodic holonomy.
- **(b) A3 negative.**
  - Build A2 as the helper does (`:4496–4503`).
  - `make(fixture.mesh, A2, {}, legacyField)` fails with `MissingAdjacency`.
  - `error.sourceEdge ==` the minimum interior `test_source_edge_topology` key, enumerated independently from `fixture.mesh.F` incidence. Assert that the interior set is non-empty.
- **(c) Anti-vacuity.** A copy of `legacyField` with `edgeTransitions` restored from `authoritativeField` builds A3 successfully.
- **(d) A4 legacy ingress, the new pin.**
  - Use the crossField overload with options that have the same components and sheets, `fieldTransportAtlas == nullptr` and `sourceAuthority == nullptr`.
  - Assert:
    - `Rejected`;
    - `PublishedProductRejected`;
    - `publishedProductError == InvalidSourceAuthority`;
    - detail `AtlasSourceMismatch`;
    - site `"atlas-binding"`;
    - `produced_product() == nullptr`;
    - empty `seeds`/`traces`/`proposals`.
  - Stream the reason name, the error, the detail and the site.
  - This exercises the compact-matching branch `:14966–14979` up to the factory, and pins the locus that any later O2 change must preserve or explicitly re-bind.
- **Must not change:** any other test, production source, selectors, the harness or workflows. `make_legacy_periodic_route_field` stays (190 is its only consumer).
- **STOP → Review:**
  - a needed accessor or enum is not visible;
  - a production edit appears necessary;
  - selector bytes would change.
  - A runtime mismatch in (d) is a TB43 finding for Review to re-bind. It is **not** a CB fix.

#### RA-160.4 O2 disposition

O2 is **not on the RP-01 critical path**: production always supplies an atlas (`RemeshPipeline.cpp:12971–12979`), and the checked factory rejects a null atlas. The Q6 production CB is withdrawn.

O2 moves to the post-RP-01 `M6-CP3-DEFN-POSTRP01-O2-NO-ATLAS-INGRESS-RETIREMENT`, which must decide:
- the NotApplicable seed-fallback contract (D2);
- the crossField API overloads (D3);
- every no-atlas detail consumer, including selectors 179 and 233 and `Phase10Tests:489–611, 5716`;
- an entry-gate design versus the factory locus (D5).

#### RA-160.5 Turn sequence (frozen IDs)

1. `M6-CP3-CB43-RP01-SELECTOR190-LEGACY-INGRESS-REHOME`: test-only, compile only. Then `…-REV`, which is static and issues the TB43 manifest.
2. `M6-CP3-TB43-RP01-SELECTOR190-REHOME-VERIFY`: artifact-only on the targeted harness and the CB43 package.
   - Rows: 190 POSITIVE; GUARD `selector:28`, `selector:179`, `selector:233`.
   - Then `…-REV`.
3. `M6-CP3-DEFN-RP01-A4-PROVENANCE-GUARD-REACHABILITY` (O4) → REV.
4. `M6-CP3-DEFN-RP01-SELECTOR242-CROSS-REGION-SEAM-CONSUMER` → REV.
5. The CB/TB turns those authorize.
6. 405 → 174, 201 → `focused30:12` → `cp3entry:4` → `selector:442` → DEFN-T1.
7. O5 DEFN → REV.
8. Census → RP-01 Review, with the O6 scope statement.
9. After RP-01: the O2 DEFN.

Carried: DIAG-RETAIN, O1, O2 (post-RP-01), O4, O5, O6, RA-152.5, DEFN-SEAM-NZ, RA-146.2/4, RA-45.4, G4-B002.

**Accounting unchanged:**
- stable 66/17/49, debt 1;
- CP2 491/491 accepted;
- TB32 481/500 and TB38 490/504 candidate;
- TB41 18/18 and TB42 1/1 focused candidate;
- selector497 frozen;
- RP-01 open.

## `Architecture_M6_CP3_DEFN_Selector242_Seam_Consumer_Review_Decision_20261026.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_DEFN_Selector242_Seam_Consumer_Review_Decision_20261026.md`; moved verbatim.

### RA-163 — selector242 DEFN Review: D1 missed the typed owner, D2 decided statically, Branch B rejected (2026-10-26)

**Turn:** `M6-CP3-DEFN-RP01-SELECTOR242-CROSS-REGION-SEAM-CONSUMER-REV`. **Reviewed:** [DEFN decision](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_DEFN_Selector242_Cross_Region_Seam_Consumer_Decision_20261026.md") and the [conditional CB45 draft](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_CB45_Selector242_Seam_Rehome_Specification_20261026.md") on source `9ab1563ee` (no `src`, `include` or `tests` drift since).

**Decision:** the DEFN is **PARTIALLY ACCEPTED**.
- Accepted: D2's vacuity diagnosis and D4.
- **Corrected:** D1.
- **Decided here:** D2's branch, which the DEFN left open.
- **Rejected:** D3 Branch B.
- **Superseded:** the CB45 draft, replaced by RA-163.3, which is the only CB45 authority.

This Review made no code, build or runtime change.

#### RA-163.1 Findings on the DEFN

- **R1 — D1 missed the typed owner of non-reciprocity.**
  - `SurfaceIsolationSeamTransportCertificate::make` (`SurfaceCellTracing.cpp:8090–8150`) rejects `compose(forward, reverse) != identity` with `NonReciprocalTransport` (code 7, `:8146–8150`).
  - Its error carries `region`, `seam`, faces and sheets. It is the only place where a non-reciprocal pair can be expressed.
  - A4's builder derives the pair from A3 and pre-checks `candidateReverse != candidateForward.inverse()` (`:18184`). So no atlas-derived input reaches code 7, and the type makes a non-reciprocal certificate unconstructible downstream.
  - Accepted-prefix **`selector:185`** (`SurfaceCellIsolationSeamCertificateAuthority.NonreciprocalIsolationSeamCertificateIsRejected`, `TransitionQuotientTests:7686–7708`) already pins code 7 on `split_isolation_fixture`.
  - The DEFN cited neither the predicate nor the selector.
- **R2 — D2 is decidable statically: mutated A3 ACCEPTS.**
  - The atlas cycle basis is `dual_cycles` (`PCFaceTangentBundle.h:95`).
  - For the 242 disk (4 vertices, all on the boundary; one inner edge, (0,2)), there are 0 interior-vertex rows and 1 boundary row. The boundary row is the sum of the vertex cycles of v0..v3 (`MeshTopology.cpp:130–133, 281–288`).
  - Edge (0,2) gets −1 from v0 and +1 from v2. The sum is 0, and the entry is pruned (`:329–330`).
  - So no cycle observes the edge. `CycleTransportMismatch` cannot fire, and A3 never compares `matching` against the face geometry (`FieldTransportAtlas.cpp:1963–2045` and `2479–2589` read only `effort` and cycles).
  - More fundamentally: when a region's dual graph is a tree, a matching change on one edge is a **gauge relabelling**, not an inconsistency. Acceptance is correct, and a rejection would be a defect.
  - **Branch A is dead.**
- **R3 — the original expectation is unreachable on every path.** `InvalidTopologyRegionTransport` is now emitted only for atlas/source-face mismatch and network-binding failures (`SurfaceCellTracing.cpp:19360–19376`, `12058–12706`).
  - Atlas-bound: the mutation is never read (`:21181–21184`).
  - No atlas: the result is the factory's `atlas-binding` rejection (RA-160).
  - Certificate failures map to `InvalidIsolationSeamTransportCertificate` (`:19215–19230`), not to the old reason.
- **R4 — Branch B is rejected.**
  - It swaps the invariant: cycle-holonomy consistency (`CycleTransportMismatch`, already owned by A3 and its own tests) is not reciprocity.
  - Its fixture must come from production finalization, and the DEFN itself concedes that yields consistent fields. It would spend a CB on a speculative, probably unreachable witness.
  - Its "Review chooses A or B" CB45 draft is not an executable spec.

#### RA-163.2 Selector-meaning disposition (Review-owned)

`selector:242` keeps its identity: `SurfaceCellsPhase10.NonReciprocalSourceAdjacentIsolationSeamFailsClosed`. Its meaning is re-homed from "A4 rejects a legacy non-reciprocal matching" to:

> On the source-adjacent two-sheet seam, A3 cannot represent non-reciprocal transport even under the legacy single-edge mutation. A non-reciprocal pair presented to the seam certificate's owner fails closed with code 7, at that exact seam.

**Overlap with 185:** 242 binds the owner check to the certificate that A4 actually published on the source-adjacent geometry of `selector:239`. It also adds the A3 representation pin. 185 covers neither. The old A4 `Rejected`/`InvalidTopologyRegionTransport` assertions are retired as unreachable (R3).

#### RA-163.3 CB45 specification — `M6-CP3-CB45-RP01-SELECTOR242-SEAM-REHOME`

Test-only, compile only. **Edit only** the 242 body, `tests/SurfaceCellsPhase10Tests.cpp:3340–3391`. Keep its name, mesh, `raw`, `sourceField` and options.

The new body has these sections:

1. **Produce.**
   - `network = build_phase10_with_source_atlas(mesh, sourceField, targetSize, options)`.
   - `ASSERT` the result is `Produced`, with exactly one isolation certificate `c`.
2. **Owner, reverse.**
   - Call `SurfaceIsolationSeamTransportCertificate::make(product.sourceTopologyRegions(), c.region(), c.seam(), c.transition(), c.firstFace(), c.secondFace(), c.firstSheet(), c.secondSheet(), c.forward(), QuarterTurn::from_integer(int(c.reverse().value()) + 1))`.
   - `ASSERT` the result holds an error. Expect code `NonReciprocalTransport`, `error->seam == c.seam()` and `error->region == c.region()`.
3. **Owner, forward.** Same as section 2, but with `forward + 1` and the original reverse. Expect code `NonReciprocalTransport`.
4. **Owner, control.** Call `make` with `c.forward(), c.reverse()`. It must hold a certificate whose `isolation_seam_transport_certificate_hash` equals that of `c`.
5. **A3 representation.**
   - Set `mutatedField = sourceField` and apply the existing interior `matching += 1`.
   - Build `mutatedAtlas = FieldTransportAtlas::make(mesh, *sourceAuthority, options.hardFeatureEdges, mutatedField)` and `ASSERT_TRUE(mutatedAtlas.has_value())` (R2).
   - Let `f/r = transition_value(c.seam(), A, B)` and `(…, B, A)` on both atlases, where A and B are the seam's two `SourceFaceId`s.
   - Expect `r->transport == f->transport.inverse()` on the mutated atlas.
   - Expect the mutated `f->transport` to differ from the source atlas's `f->transport`. This proves the mutation was consumed.
6. **Remove** the old A4 run on `crossField` and its `Rejected` / `InvalidTopologyRegionTransport` / null-product expectations.

**Rules for the change:**
- **Must not change:** any other test or helper, production source, selectors, harness or workflows.
- Do not bind A4 to `mutatedAtlas`. A non-zero seam transport belongs to DEFN-SEAM-NZ.
- **Evidence:** 8 GMP/GMPXX targets, `runtimeExecution=false`, record of at most 30 lines with the exact hunk.

**STOP → Review if:**
- a needed symbol is not visible from the TU (`SourceFaceId` construction, the certificate error type, `transition_value`);
- a helper change is needed;
- selector bytes would change.

If the A3 build rejects at runtime, that is a **TB45 finding against R2**, not something to fix in CB45.

#### RA-163.4 Carried and noted

- **DEFN-SEAM-NZ (hint only, unverified):** cyclically shifting one face's four `raw` vectors in this fixture should make production finalization produce a non-zero principal matching at the seam. If so, that is a production-derived non-zero seam transport. Record it for the SEAM-NZ owner. Do not act on it in 242.
- O2/T2 (post-RP-01), O5 (P1-a re-scoped, P1-b, RA-162 C1), O4, O6, DIAG-RETAIN, RA-152.5, RA-146.2/4, RA-45.4 and G4-B002 are carried unchanged.

#### RA-163.5 Turn sequence (frozen IDs)

1. `M6-CP3-CB45-RP01-SELECTOR242-SEAM-REHOME` → `…-REV`. The REV is static and issues the TB45 manifest:
   - 242 POSITIVE;
   - GUARD `selector:239` (`Phase10Tests:3270`);
   - GUARD `selector:185` (`TransitionQuotientTests:7686`).
2. `M6-CP3-TB45-RP01-SELECTOR242-SEAM-REHOME-VERIFY` → `…-REV`.
3. 174 → 201 → `focused30:12` → `cp3entry:4` → `selector:442` → DEFN-T1 (`cp3entry:1/2`). One owner per turn; Review assigns the IDs.
4. O4 DEFN, then O5 DEFN (+P1, C1) → REV for each. Then census → RP-01 Review (O6 scope). After RP-01: O2 DEFN.

**Accounting unchanged:**
- Stable 66/17/49, debt 1.
- CP2 491/491 accepted.
- Candidate: TB32 481/500, TB38 490/504.
- Focused candidate: TB41–TB44.
- Selector497 frozen. RP-01 open.
- 242 stays RED until TB45 and then a complete gate.

## `Architecture_M6_CP3_TB41_REV_Audit_O3_Owner_And_DEFN_Split_Decision_20261026.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_TB41_REV_Audit_O3_Owner_And_DEFN_Split_Decision_20261026.md`; moved verbatim.

### RA-158 — TB41-REV audit: O3 owner, DEFN split, off-selector coverage gap (2026-10-26)

**Turn:** `M6-CP3-TB41-RP01-REHOMED-ORACLE-VERIFY-REV-AUDIT` (Review). **Decision:** TB41-REV is **confirmed** (18/18 focused candidate; no CP3 or selector497 promotion). Its successor is **realigned**: the orphaned O3 runtime obligation gets an owner first (its package expires), and the monolithic legacy-path/seam DEFN is split by mechanism.

#### RA-158.1 Independent verification

- TB41 result `12638251384`: ZIP SHA-256 `1817f8295709a88bb3a561734b345cc50e81da056684501d714aac08fb7dd854`; 39/39 inner hashes; 18/18 raw logs re-joined to ledger (hash, one RUN, one OK, `PASSED 1`, no FAILED); 18 unique tests; boundary `postflight=true`, no compile/relink/configure.
- Manifest SHA-256 `659c52f08bf5e5cbef6d2f1e1255432a247eb50da77bd4323666dfac900b2959` matches the committed file.
- No `src/`, `include/`, `tests/`, `benchmarks/` or CMake change between CB42 source `8dc8cdeae` and HEAD.
- The five `InvalidBoundedDiskFrontPairing` sites remain `SurfaceCellTracing.cpp:17190, 17889, 17948, 17969, 18034`; only `:17190` leaves `cell`/`side` at −1, so the CB42 pins discriminate.

#### RA-158.2 Findings

- **L1 — O3 obligation orphaned and time-bound.** TB41-REV correctly found that `SurfaceCellsPhase10.PolygonalCurvedDiskRejectsWithoutPublishingPartialPhase` (`Phase10Tests:2940–2958`) was never executed, but carried it to "a future authorized TB gate" with no canonical owner or sequence slot. The omission originated in RA-157.4, which listed TB41 rows by selector number only, so the off-selector test had no row. CB42 package `12634151125` expires **2026-11-02T07:22:41Z**; after that the run needs a recompile. Owner: **TB42** (next turn).
- **L2 — DEFN successor is monolithic and its Review ID was left unfrozen.** `M6-CP3-DEFN-RP01-LEGACY-PATH-AND-SEAM-ORACLES` bundles three mechanisms: (a) 190 + O2, legacy-matching path (RA-155 H2: a legacy-only field yields A3 `MissingAdjacency`, so the legacy branches `SurfaceCellTracing.cpp:14950–14979` and `:6731ff` cannot publish), which also needs an accepted-prefix accounting rule; (b) O4, reachability of A4 `MissingTransitionProvenance` (`:12656/12698/12707`) once A4 reads the checked atlas first; (c) 242, a cross-region `transition_value` with no A2–A4 consumer (RA-155 H3; DEFN-SEAM-NZ). "Successor ID to be frozen by the Definition record" recreates the Successor-UNKNOWN stall of TB40. **Split into three DEFN turns with frozen IDs (RA-158.3).** The old ID is superseded.
- **L3 — 192 is now the TB36 quarter-turn guard.** After CB40, 192's negative half (`turning_periodic_route_field(fixture,1)`, A3-positive, A4 `PeriodicHolonomyMismatch`, all-−1 locus) is assertion-for-assertion `expect_authoritative_periodic_monodromy_rejected(1)` (`Phase10Tests:4665`). TB41 counted one mechanism twice (POSITIVE 192 and GUARD `tb36:quarter-monodromy`). Not a defect: RA-155.3 B required this stimulus. The rotation pin was relaxed from exactly `q` to `q` or `q⁻¹`; acceptable because A4 rejects any non-identity rotation and 194 covers the inverse. No action.
- **L4 — 247 carries orphaned setup.** CB40 stopped mutating the located `transition` (`Phase10Tests:5345–5375`, inside test 247 at `:5297`), but kept ~30 lines that find it and assert its EF reciprocity. They still assert facts about the valid input field, so they are not vacuous, but the next reader will assume they target the stimulus. Not scheduled; remove only if a later turn edits 247 for another reason.
- **L5 — new observation O5: off-selector producer tests are in no gate.** Static parse of `TEST`/`TEST_F` identities in the 14 test sources compiled into `directional_surface_cell_producer_tests` (`cmake/DirectionalTests.cmake:73–90`): **598** identities; **349** are in focused30 ∪ focused12 ∪ selector449 ∪ the six cp3entry names; **249** are in none. They include 42 `SurfaceCellsPhase10`, 14 `M6CP3`, 7 `SurfacePhaseFrontProductFactoryAuthority`, 4 periodic-holonomy (both TB36 guards), and `CurvedBoundedDiskInvalidReciprocalTransportFailsClosed` (the RA-155.4 inventory item). The R3 audit (2026-10-09) reported 4; the gap has grown with every CP3 test added. No regression is claimed (never measured), but the census → RP-01 Review cannot speak to these tests. Owner: a coverage-disposition DEFN placed before the census manifest.
- **L6 — documentation drift.** Handoff authority table had departed from the template rows (and its "Reviewed decision" cited CB41-REV); TODO CURRENT kept "NEXT TB41-REV" unchecked and "O3 pending TB41-REV". Corrected in place.

#### RA-158.3 Turn sequence (frozen IDs)

1. `M6-CP3-TB42-RP01-O3-OFF-SELECTOR-LOCUS-VERIFY` → `…-REV`. Artifact-only, one POSITIVE row on CB42 package `12634151125`; must run before 2026-11-02T07:22Z.
2. `M6-CP3-DEFN-RP01-LEGACY-MATCHING-PATH-DISPOSITION` → `…-REV`. 190 + O2: retire 190 or re-home it as an A3 `MissingAdjacency` negative; accepted-prefix accounting rule for a changed/retired identity in the 449; scope (not code) for removing the unreachable legacy branches.
3. `M6-CP3-DEFN-RP01-A4-PROVENANCE-GUARD-REACHABILITY` → `…-REV`. O4: decide whether each `MissingTransitionProvenance` site is reachable from any input that passes checked A3; if reachable, name a witness; if not, classify as defensive and say whether it stays.
4. `M6-CP3-DEFN-RP01-SELECTOR242-CROSS-REGION-SEAM-CONSUMER` → `…-REV`. 242: name a downstream consumer of cross-region `transition_value` (isolation-seam certificate) or retire; coordinate DEFN-SEAM-NZ.
5. Code/TB turns that steps 2–4 authorize (their Reviews assign IDs).
6. 405 → 174, 201 → `focused30:12` → `cp3entry:4` → `selector:442` → DEFN-T1 (`cp3entry:1/2`).
7. `M6-CP3-DEFN-RP01-OFF-SELECTOR-COVERAGE-DISPOSITION` → `…-REV`. O5: classify the 249 off-gate producer tests (CP3-required / legacy-retire / out-of-scope) and freeze any supplemental census rows.
8. Census → RP-01 Review.

Each DEFN is design-only, one mechanism, falsifiable and independently reviewable. Superseded: `M6-CP3-DEFN-RP01-LEGACY-PATH-AND-SEAM-ORACLES`.

#### RA-158.4 TB42 specification

- **Package:** CB42 artifact `12634151125`, ZIP SHA-256 `d7f7b8302966b14acd919eeef4465d518a6179f1823fbb86ad0e5b1b43488b87`, source `8dc8cdeae6f6ac05c28aaa4504ca2c42c3177ded`, 28/28.
- **Harness:** unchanged `tools/m6_cp3_targeted_artifact_harness.sh` (SHA-256 `436f5fff9c3bec97457f4bc6b7c2b6182cb3f47707eb14a66af3b6a3f3dc3c9a`).
- **Manifest (freeze and commit before dispatch):** exactly one row, `POSITIVE`, identity `o3:polygonal-partial-phase`, test `SurfaceCellsPhase10.PolygonalCurvedDiskRejectsWithoutPublishingPartialPhase`, binary `directional_surface_cell_producer_tests`, expect `PASS`.
- **Pass condition:** one process, exit 0, one RUN, one OK; ledger, raw log, boundary with `postflight=true` and no compile/relink/configure.
- **STOP → Review:** package expired or any hash mismatch (do not recompile); harness rejects a one-row manifest (do not edit it). A RED is recorded as RED with its first failure line, never "fixed" in the same turn.
- **On PASS:** O3 runtime discharged as a focused candidate (3/3 locus tests). No selector or CP3 promotion.

#### RA-158.5 Accounting

Unchanged: stable 66/17/49, debt 1; CP2 491/491 accepted; TB32 481/500 and TB38 490/504 candidate; TB41 18/18 focused candidate; selector497 frozen; RP-01 open, RP-02 unreached. Carried: DIAG-RETAIN, O1, O2, O3 (until TB42), O4, O5, RA-152.5, DEFN-SEAM-NZ, RA-146.2/4, RA-45.4, G4-B002.

## `Architecture_M6_CP3_TB42_REV_Audit_Selector190_Vacuity_And_DEFN_Spec_Decision_20261026.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_TB42_REV_Audit_Selector190_Vacuity_And_DEFN_Spec_Decision_20261026.md`; moved verbatim.

### RA-159 — TB42-REV audit: selector190 vacuity, legacy-path DEFN spec, O6 (2026-10-26)

**Turn:** `M6-CP3-TB42-RP01-O3-OFF-SELECTOR-LOCUS-VERIFY-REV-AUDIT` (Review). **Decision:** TB42-REV is **confirmed** (O3 3/3 focused candidate; no promotion). Its successor `M6-CP3-DEFN-RP01-LEGACY-MATCHING-PATH-DISPOSITION` stands, but its premise is corrected and its questions are bound (RA-159.3).

#### RA-159.1 Independent verification

- TB42 result `12644936205`: ZIP SHA-256 `2d0c6cf7ab7e1eb7321f1adf0720e5ea2fd585c6762e9458de03c4f260d9b1b6`; 5/5 inner hashes; ledger row joined to `raw/1.log` (hash, one RUN, one OK, `PASSED 1`, no FAILED); boundary planned=executed=passed=1, `postflight=true`, compile/relink/configure false, source `8dc8cdeae`, package `12634151125`.
- Manifest SHA-256 `b266c05669dac6159e12b71831de6c7e17d4f64b9f47a8dae1d76a2bf5578885`, identical at freeze commit `b394edf88` (before dispatch `a7acf506d`).
- The rejection is the unique `:17186–17192` site (after `chartConstructed=true`, `cell`/`side` default −1).

#### RA-159.2 Findings

- **N1 — O3 pins a limitation, not a capability (new O6).** `make_polygonal_curved_disk_fixture` (`Phase10Tests:2822`) is a six-corner L-shaped disk with an axis-aligned field and a hard boundary — a routinely quadrangulable input. The producer rejects every nonrectangular bounded disk by design (`SurfaceCellTracing.cpp:17182–17185`: lattice clipping/pairing "remains a distinct deeper front-construction contract"). Neither `DESIGN.md` nor `ROADMAP.md` names a requirement or owner for that contract, and M8's representative-witness gate will meet such inputs. The O3 tests are correct fail-closed oracles today; they will flip by design when the capability lands. **O6:** the RP-01 Review must state whether CP3 excludes nonrectangular bounded disks and name the roadmap owner. Not an RP-01 corrective item.
- **N2 — selector190 is a vacuous PASS, not "unsatisfiable".** RA-155 H2 called it unsatisfiable; TB38 measured it GUARD PASS. Both are explained by commit `7ccdcd527` (2026-10-11), which changed 190 from `build_periodic_route_network(fixture, legacyField)` to `build_periodic_route_network_with_source_atlas(fixture, legacyField, authoritativeField)` (`Phase10Tests:5182–5183`). The atlas is built from `authoritativeField`, and A4 takes each step's transport from the atlas before any field transition (`SurfaceCellTracing.cpp:14937–14979`: atlas → `hasTransitions` → `edgeMatching`). `legacyField` only selects the provenance lookup (`:14926–14929`, `hasTransitions ? edgeTransitions : nullptr`), which succeeds on this fixture; it never decides a transport. The holonomy comparison is therefore authoritative-versus-authoritative. It is the **last** mismatched call in the periodic-route family; every other call site passes the same field twice (189 was the same defect, fixed by CB41).
- **N3 — the accepted-prefix credit for 190 is for a different oracle.** CP2 was accepted 2026-10-06, before `7ccdcd527`. Its 190 asserted that a legacy-only field publishes, which D1/RA-40 now forbids (`SurfacePhaseFrontProduct::make` rejects a null atlas, `SurfaceCellTracing.cpp:8462`). So: the CP2 credit is historical and not revocable, the original oracle is architecturally void, and the TB38/TB41-era 190 PASS rows are not legacy-path evidence.
- **N4 — O2 has a live detail-level consumer.** `SurfaceCellVertexContinuationRouteTransportAuthorityMigration.LegacyMatchingPathUsesSameTypedRouteComposition` (`Phase10Tests:5716`) calls the continuation resolver with `nullptr` transitions and so exercises the legacy branch directly. It is in no gate (O5). Removing the legacy branch (`:6731ff`) deletes its subject.
- **N5 — documentation drift.** TODO listed the DEFN twice (NEXT and Then); the handoff "Latest candidate" row omitted the TB42 result. Corrected.

#### RA-159.3 DEFN specification — `M6-CP3-DEFN-RP01-LEGACY-MATCHING-PATH-DISPOSITION`

Design only; one record ≤60 lines; no source/test/selector/workflow change. It must answer, each with file:line evidence:

1. **Vacuity (confirm or refute N2).** Trace `legacyField` in 190 from the helper (`Phase10Tests:4490–4516`) to every A4 read, including the provenance lookup at `:14926–14929`; state whether any transport or published value depends on it.
2. **190 disposition — choose exactly one:** (a) re-home under the same identity as an A3 negative: untampered `FieldTransportAtlas::make(authoritativeField)` succeeds; `make(legacyField)` fails with `MissingAdjacency` and the first missing edge key; or (b) retire the identity. State the expected first error code from `FieldTransportAtlas.cpp:2016–2018` and why it discriminates.
3. **Accounting rule** for an identity in the accepted 449 prefix whose original oracle is void under D1: selector bytes unchanged (re-home keeps the name) or changed (retire); how CP2 491/491 is annotated (historical credit kept, not re-counted as legacy evidence); how TB38/TB41 rows are annotated.
4. **O2 inventory.** Every non-atlas branch in the producer (at least `SurfaceCellTracing.cpp:14952–14979` and `:6731ff`), each classified: reachable through `build_surface_cell_network` + checked factory to a published product / reachable only to a rejection / reachable only through detail APIs used by tests / unreachable. Name each test that consumes it and its gate (in-gate or O5).
5. **Removal scope** (no code): whether removal changes any rejection reason or locus on no-atlas inputs, and which test identities then die or must be re-homed.
6. **Successor:** at most one test-only CB (for 190) and, separately, at most one production CB (O2 removal), each with exact files, assertions and STOP rules.

**Falsifiers / STOP → Review:** any production caller publishes without an atlas (that is a defect, not a DEFN); `make(legacyField)` returns a code other than `MissingAdjacency`; a legacy branch decides a published product; the accounting rule would alter selector497 bytes without explicit user authorization.

#### RA-159.4 Turn sequence

1. `M6-CP3-DEFN-RP01-LEGACY-MATCHING-PATH-DISPOSITION` → `…-REV`.
2. `M6-CP3-DEFN-RP01-A4-PROVENANCE-GUARD-REACHABILITY` (O4) → `…-REV`.
3. `M6-CP3-DEFN-RP01-SELECTOR242-CROSS-REGION-SEAM-CONSUMER` (242) → `…-REV`.
4. Code/TB turns authorized by steps 1–3 (their Reviews assign IDs).
5. 405 → 174, 201 → `focused30:12` → `cp3entry:4` → `selector:442` → DEFN-T1 (`cp3entry:1/2`).
6. `M6-CP3-DEFN-RP01-OFF-SELECTOR-COVERAGE-DISPOSITION` (O5) → `…-REV`.
7. Census → RP-01 Review (must include the O6 scope statement).

#### RA-159.5 Accounting

Unchanged: stable 66/17/49, debt 1; CP2 491/491 accepted; TB32 481/500 and TB38 490/504 candidate; TB41 18/18 and TB42 1/1 focused candidate; selector497 frozen; RP-01 open, RP-02 unreached. Carried: DIAG-RETAIN, O1, O2, O4, O5, O6, RA-152.5, DEFN-SEAM-NZ, RA-146.2/4, RA-45.4, G4-B002.

## `Architecture_M6_CP3_TB43_REV_Audit_Selector405_Fixture_Provenance_Decision_20261026.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_TB43_REV_Audit_Selector405_Fixture_Provenance_Decision_20261026.md`; moved verbatim.

### RA-161 — TB43-REV audit; selector405 root-caused to fixture rail provenance; O4 demoted (2026-10-26)

**Turn:** `M6-CP3-TB43-RP01-SELECTOR190-REHOME-VERIFY-REV-AUDIT`. **Decision:** TB43-REV **CONFIRMED** (190 re-home 4/4 focused candidate, no promotion). Its successor (O4 DEFN) is **re-sequenced**: O4 closes no RED. Static analysis here root-causes accepted-prefix RED `selector:405` to a test-helper defect, so a narrow test-only CB44 goes next. No build, runtime or product change in this audit.

#### RA-161.1 Independent verification

- Result artifact `12664712967` re-downloaded: ZIP SHA-256 `fbe75000…26804` matches; **12/12** `SHA256SUMS` OK; boundary 4/4 PASS, zero missing/skipped/duplicate/control_bad, `postflight=true`, compile/relink/configure false.
- 4/4 raw logs each hold exactly one `[ RUN ]`/`[ OK ]` for the ledger identity; ledger log hashes match.
- Manifest SHA-256 `812b843b…ffc676` added at `63e00c97b`, an ancestor of dispatch `ce6c084bf`. No `src`/`tests`/`include` change between CB43 source `d354d6ae9` and HEAD.
- CB43 hunk (`Phase10Tests:5176–5284`) implements RA-160.3 (a)–(d) exactly; only the 190 body changed.

#### RA-161.2 Findings on TB43 / TB43-REV

- **T1 — accepted.** The vacuous atlas-versus-atlas comparison is gone; (b)+(c) discriminate the A3 transition relation; (d) pins the no-atlas factory locus `atlas-binding`.
- **T2 — (d) cannot detect a silent identity fallback.** The 190 field carries a balanced face gauge (±1 on three edges, `balanced_periodic_route_field`), so the periodic producer completes and reaches the factory whether the step rotation comes from compact matching (`SurfaceCellTracing.cpp:14966–14979`) or from the identity default (`:14937`, RA-160 D5). (d) guards the rejection *locus*, not whether legacy data is read. TB43-REV did not state this. Carried into the post-RP-01 O2 DEFN as a required discriminating fixture.
- **T3 — the successor does not advance RP-01.** O4 (`:12656/12698/12707` defensive `MissingTransitionProvenance` guards) has no RED identity. Nine REDs remain from TB38 after TB41/TB43: `selector:174, 201, 242, 405, 442`, `focused30:12`, `cp3entry:1, 2, 4`. Five are **accepted-prefix regressions** (CP2 491/491). They take precedence over oracle hygiene.

#### RA-161.3 selector405 root cause (static, decisive)

- Test `SurfaceCellAuthorityContractCutover.FixedConformityPlanTargetPerturbationPreservesSharedBoundaryIntervals` (`Phase10Tests:7583–7609`) calls `build_fixed_plan_rectangular_hard_rail_network(fixture, 0.5/2.0)` with **no** contacts.
- The helper (`:7099–7132`) sets `hardRailTerminalContacts`/`hardRailOpenChains` only when `contacts != nullptr` and `hardRailClosedChains` only when supplied. Production always sets all three from `hard_rail_source_provenance_from_rails(rails, V.rows())` (`RemeshPipeline.cpp:12775–12782`).
- TB38 raw log 447 (selector405): `InvalidHardRailRouteCertificate`, locus 3 (EndpointAttachment), rail 2, `a3ProbeContactPublished=0`, **`a2bProbeFailure=missing-terminal-or-closed-rail-provenance`** — the exact signature the companion negative `MissingOpenRailTerminalContactRejectsBeforeClosedRailFallback` (`:7614`) manufactures by erasing a contact.
- Conclusion: the RA-43.2/46.5 fail-closed contract is correct; 405's fixture never supplies the producer-owned A2b provenance. Defect class: **stale fixture after a production contract tightening** — not an A4 defect. All 12 other helper callers expect `Rejected`; 405 is the only positive.
- **P1 (carried):** two negatives also use the empty default — `ProducedRailIntervalReachesNetworkBoundOpenFrontConsumer` (`:7414`, asserts `InvalidFrontBoundaryAuthority` at a cell side) and `MissingTerminalA3PathRejectsAtFirstA4ConsumerPredicate` (`:8219`, asserts `missing-terminal-A3-path`). Their asserted causes differ from the missing-contact signature, so they are probably discriminating, but they run on non-production inputs. Both are off-gate (O5). Disposition after TB44.

#### RA-161.4 CB44 specification

- **Turn:** `M6-CP3-CB44-RP01-SELECTOR405-FIXED-PLAN-RAIL-PROVENANCE`, test-only, compile only.
- **Edit:** only the 405 body (`Phase10Tests:7583–7609`). Before the two builds: `const auto provenance = directional::pipeline::hard_rail_source_provenance_from_rails(fixture.rails, static_cast<std::size_t>(fixture.mesh.V.rows())); ASSERT_TRUE(provenance.has_value());` then call the helper for 0.5 and 2.0 with `&provenance->terminalContacts, nullptr, &provenance->closedChains` (the helper derives `openChains` from the same rails). Keep every existing assertion and message.
- **Must not change:** the helper, any other test, production source, selectors, harness, workflows.
- **Evidence:** 8 GMP/GMPXX targets, `runtimeExecution=false`, record ≤30 lines with the exact hunk.
- **STOP → Review:** symbol not visible from the test TU; helper change appears necessary; selector bytes would change. A runtime rejection after the fix is a TB44 finding (new first cause), not a CB fix.

#### RA-161.5 Turn sequence (frozen IDs)

1. CB44 → `…-REV` (static; issues TB44 manifest).
2. `M6-CP3-TB44-RP01-SELECTOR405-FIXED-PLAN-VERIFY`, artifact-only, CB44 package: 405 POSITIVE; GUARD `:7614`, `:7414`, `:8219` companions (off-gate, recorded as such). → `…-REV` (disposes P1).
3. `M6-CP3-DEFN-RP01-SELECTOR242-CROSS-REGION-SEAM-CONSUMER` → REV (RED; coordinate DEFN-SEAM-NZ).
4. 174, 201 → `focused30:12` → `cp3entry:4` → `selector:442` → DEFN-T1 (`cp3entry:1/2`); Review assigns IDs one owner per turn.
5. `M6-CP3-DEFN-RP01-A4-PROVENANCE-GUARD-REACHABILITY` (O4) and `M6-CP3-DEFN-RP01-OFF-SELECTOR-COVERAGE-DISPOSITION` (O5) → REV each.
6. Census → RP-01 Review (O6 scope statement). Post-RP-01: O2 DEFN (RA-160.4 + T2).

Carried: DIAG-RETAIN, O1, O2, O4, O5, O6, P1, RA-152.5, DEFN-SEAM-NZ, RA-146.2/4, RA-45.4, G4-B002.

**Accounting unchanged:** stable 66/17/49, debt 1; CP2 491/491 accepted; TB32 481/500 and TB38 490/504 candidate; TB41 18/18, TB42 1/1, TB43 4/4 focused candidate; selector497 frozen; RP-01 open.

## `Architecture_M6_CP3_TB44_REV_Audit_P1_Torn_Input_Selector242_Scope_Decision_20261026.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_TB44_REV_Audit_P1_Torn_Input_Selector242_Scope_Decision_20261026.md`; moved verbatim.

### RA-162 — TB44-REV audit; P1-a remedy corrected (torn input); selector242 DEFN scoped (2026-10-26)

**Turn:** `M6-CP3-TB44-RP01-SELECTOR405-FIXED-PLAN-VERIFY-REV-AUDIT`. **Decision:** TB44-REV is **CONFIRMED** on its evidence, on 405 (a focused positive candidate, not promoted), and on the P1-a/P1-b diagnoses. Its P1-a corrective remedy is **REJECTED as written**: it would make a production-unreachable input pass. The successor stays the selector242 DEFN, but RA-162.4 narrows its scope. This audit made no build, runtime, test or product change.

#### RA-162.1 Independent verification

- Re-downloaded result artifact `12680557878`. ZIP SHA-256 `f1b30006…6b986` matches. `SHA256SUMS` passes **11/11** (TB44 and TB44-REV both recorded "10/10"; the archive has 11 members, all valid).
- Ledger to raw-log joins are 4/4. Each log has exactly one `[ RUN ]`. Logs 1–3 each have one `[ OK ]`. Log 4 has `[ FAILED ]` and the first diagnostic `a2bProbeFailure=missing-terminal-or-closed-rail-provenance`.
- Manifest SHA-256 `f410b550…a6a8a` was added at `2d0a23005`, an ancestor of dispatch `9eef47208`.
- No `src`, `include`, `tests` or CMake change since CB44 `c25667111`. The CB44 hunk implements RA-161.4 exactly.
- 405 non-vacuity: under accepted conformity, `target` is validated (`SurfaceCellTracing.cpp:17550–17560`) and then never read again. Grid dimensions come from the accepted boundary intervals (`:17561–17577`).
  - So the 0.5×/2.0× invariance holds by construction. The test is still a valid regression guard against target-dependence returning. It does not show any computation by which the plan "dominates" the target. **Accepted.**

#### RA-162.2 Findings

- **F1 — The P1-a remedy is unsound (corrects TB44-REV).**
  - Production derives `hardFeatureEdges` from the rails: `hard_feature_edge_keys_from_rails(authoritativeRails, …)` (`RemeshPipeline.cpp:12645–12647`), assigned at `:12783`. A2b provenance is derived from the same rails (`:12775–12782`). So `hardFeatureEdges` always equals the set of rail edges.
  - 8219 inserts a **non-rail** spoke into `hardFeatureEdges` and leaves rails, provenance, A2a and A3 unchanged. That input is torn: production can never produce it.
  - With full provenance supplied, which is TB44-REV's remedy, the spoke becomes an orphan hard edge. The terminal-star walk skips it (`SurfaceCellTracing.cpp:19775`), and the test would then probably reach `missing-terminal-A3-path`.
  - A green 8219 would therefore certify a predicate on an impossible state, and it would hide F2.
  - TB44-REV left soundness as an open question for O5. This audit resolves it: **not sound**. The 8219 negative must be rebuilt as a production-reachable witness. Acceptable forms:
    - a fixture where a second rail genuinely splits the terminal star; or
    - an A3-side absence or non-reciprocity at the needed spoke, built through `FieldTransportAtlas::make` — not a caller-set override.
- **F2 — A4 hard-edge/rail cover is asymmetric (new obligation `RA-162 C1`).**
  - The checked factory (`SurfaceCellTracing.cpp:8655–8716`) checks closed-only rail sets with `closed-rail-cover`, which requires closed-chain edges == `hardFeatureEdges`.
  - When terminal contacts are present, nothing requires `hardFeatureEdges ⊆ ⋃ open/closed chain edges`. `hard_rail_open_chains_valid` (`:8394–8435`) checks only chain ⊆ hard.
  - Production can't reach this today, because both sets are derived from the same rails. But `build_surface_cell_network` and `SurfacePhaseFrontProduct::make` are public, and they accept a torn set.
  - Owner: the O5 DEFN, as a fail-closed decision: either enforce cover with a typed site, or justify an orphan hard edge as a legitimate non-rail barrier. Not on the RP-01 critical path.
- **F3 — The P1-b diagnosis is confirmed.** The forged `sourceEdges.front()` fails `rail.sourceEdges[interval] != publishedEdge` (`SurfaceCellTracing.cpp:6160–6168`) before any lookup of network ownership.
  - Caution for O5: a "network-absent" variant may already be rejected at a binding site. The differential must be pre-registered as a pair of first rejection sites, not as two verdicts.
- **F4 — Static pre-analysis of selector242 (it shapes the DEFN).**
  - `NonReciprocalSourceAdjacentIsolationSeamFailsClosed` (`Phase10Tests:3340–3391`) builds the atlas from the **unmutated** `sourceField` and mutates only `crossField.edgeTransitions[k].matching`.
  - With an atlas bound, `build_surface_cell_network(crossField)` reads only face axes and passes `nullptr` legacy containers (`SurfaceCellTracing.cpp:21181–21184`). The mutation is never observed, so A4 produces. That is TB38's `Produced` result.
  - This is RA-160's selector-190 anti-pattern. It matches TB41-REV's falsifier that a field the A3 atlas never consumes cannot force an A4 negative.
  - Separately, A3 builds reverse := forward.inverse() (`FieldTransportAtlas.cpp:2033–2036`). So a **non-reciprocal transition cannot be represented** through `matching`.
  - The only remaining A3 sensitivity to a single-edge matching change is the singularity / boundary-cycle consistency check (`FieldTransportAtlas.cpp:2091–2160`). Static reading cannot decide whether that check fires here.

#### RA-162.3 P1 re-scope (supersedes the TB44-REV P1 remedy 1)

These items are carried into the O5 DEFN, with a separate test-only CB/TB/REV before any full-selector credit:

- **P1-a (8219):** replace the caller-set hard-edge override with a production-reachable missing-terminal-A3-path witness, using a split star or an A3-side absence (F1). Keep the site assertions `EndpointAttachment` and `missing-terminal-A3-path`, and keep the negative `no-exact-terminal-corner`.
  - Falsifiers: the witness mutates only a caller-supplied set that production derives; or an earlier provenance or cover site fires.
- **P1-b (7414):** unchanged from TB44-REV remedy 2, plus F3's caution.
- **RA-162 C1:** F2 cover decision. If C1 enforces cover, the current 8219 fixture would fail at that new site. This is a further reason not to apply remedy 1 as written.

#### RA-162.4 DEFN `M6-CP3-DEFN-RP01-SELECTOR242-CROSS-REGION-SEAM-CONSUMER` — required scope

Design only. No code or build. Output: one decision document of at most 80 lines, plus a CB45 specification.

- **D1 — owner of the invariant.** Name the producer that owns isolation-seam transport reciprocity in the atlas-bound architecture (A3 `make`, or the A4 certificate built at the seam). Name its observable rejection site, if one exists. Positive control: sibling `ExactReciprocalTransportCrossesSourceAdjacentIsolationSeam` (`Phase10Tests:3270–3338`).
- **D2 — is the input representable at A3?** Decide whether `FieldTransportAtlas::make(mesh, regions, {}, mutatedField)` rejects, and with which code and site. Decide from `FieldTransportAtlas.cpp:2091–2160` if the source settles it. Otherwise, pre-register both outcomes for TB45.
- **D3 — re-home, by branch.**
  - **(A) A3 rejects:** 242 asserts the A3 rejection (code plus edge) on the mutated field, and asserts that A4 bound to the source atlas still produces.
  - **(B) A3 accepts:** the claim is not representable through `matching`. Specify a replacement that is production-reachable, keeps the same identity, and has a discriminating observable. Do not re-enter the legacy ingress, and do not weaken the test into a positive. Any change to the selector's meaning needs an explicit Review disposition.
- **D4 — coordination.** Record how this relates to DEFN-SEAM-NZ, and note the overlap with the O2/T2 identity-fallback discriminator. Do not absorb O2.
- **Falsifiers:** the proposed negative mutates a container that atlas-bound A4 never reads; the expected site cannot be observed separately; the branch choice cites no line evidence.
- **STOP → Review:** the reciprocity owner cannot be identified; or the fix needs a production change. A production change gets its own CB owner, not a test edit.

#### RA-162.5 Turn sequence (frozen IDs)

1. `M6-CP3-DEFN-RP01-SELECTOR242-CROSS-REGION-SEAM-CONSUMER` → `…-REV` (RA-162.4).
2. `M6-CP3-CB45-RP01-SELECTOR242-SEAM-REHOME` (test-only, compile only, per DEFN) → `…-REV` (static; issues the TB45 manifest).
3. `M6-CP3-TB45-RP01-SELECTOR242-SEAM-REHOME-VERIFY` → `…-REV`. 242 is the positive row; sibling `:3270` is a guard.
4. 174 → 201 → `focused30:12` → `cp3entry:4` → `selector:442` → DEFN-T1 (`cp3entry:1/2`). One owner per turn; Review assigns the IDs.
5. O4 DEFN, then O5 DEFN (now carrying P1-a re-scoped, P1-b, RA-162 C1) → REV for each.
6. Census → RP-01 Review (O6 scope statement). After RP-01: O2 DEFN (RA-160.4 + RA-161 T2).

**Carried:** DIAG-RETAIN, O1, O2, O4, O5 (+P1, C1), O6, RA-152.5, DEFN-SEAM-NZ, RA-146.2/4, RA-45.4, G4-B002.

**Accounting unchanged:**
- Stable 66/17/49, debt 1.
- CP2 491/491 accepted.
- Candidate: TB32 481/500, TB38 490/504.
- Focused candidate: TB41 18/18, TB42 1/1, TB43 4/4, TB44 405 PASS (guards 3/4).
- Selector497 frozen. RP-01 open. The nine TB38 REDs are not counted recovered until a complete gate runs.

## `Architecture_M6_CP3_TB45_REV_Audit_Rail_Oracle_Triage_Cadence_Realignment_Decision_20261027.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_TB45_REV_Audit_Rail_Oracle_Triage_Cadence_Realignment_Decision_20261027.md`; moved verbatim.

### RA-164 — TB45-REV audit; 174 and cp3entry:4 decided statically; RED clusters; CP3 cadence realigned (2026-10-27)

**Turn:** `M6-CP3-TB45-RP01-SELECTOR242-SEAM-REHOME-VERIFY-REV-AUDIT`. **Decision:**
- TB45-REV is **CONFIRMED** on its evidence and semantics.
- Its successor, `M6-CP3-DEFN-RP01-SELECTOR174-DCEL-EXCEPTION-DISPOSITION`, is **SUPERSEDED**: this audit decides 174 statically (RA-164.2).
- The one-RED-per-DEFN ladder is replaced by RA-164.3–.6.

This audit made no build, runtime, test or product change.

#### RA-164.1 Verification

- Re-downloaded TB45 result `12702259228`. ZIP SHA-256 `7d18b08a…bcd6080` matches, `SHA256SUMS` passes **9/9** (TB45-REV said 8/8, but the archive has 9 members, all valid), and the ledger-to-log joins are 3/3 with one RUN and one OK each.
- HEAD `tests/SurfaceCellsPhase10Tests.cpp` SHA-256 `f1183015…9c06619` equals the CB45 source `dfeb0751b`. There is no `src`, `include`, `tests` or CMake drift since then.
- **There has been no production change since TB38.** `038ae7fd7..HEAD` touches only `tests/SurfaceCellsPhase10Tests.cpp`, so every TB38 first-failure site is still current for every other test.
- **A1.** The CB45 body implements RA-163.3 exactly.
  - The A3 pin `changedReverse == changedForward.inverse()` is structural (`FieldTransportAtlas.cpp:2033–2036`): it pins the architecture rather than discriminating a defect.
  - `EXPECT_NE(original, changed)` is what carries the non-vacuity. Accepted.
- **A2.** TB45-REV left 174's owner open ("fixture or production"). The source already settles it (RA-164.2 H1), so a DEFN turn would only re-derive this.

#### RA-164.2 Static triage of the 7 remaining TB38 REDs

- **H1 `selector:174` — decided: invalid fixture, unreachable branch.**
  - The third face `0,1,4` (`SurfaceCellREPackageTests.cpp:445–446`) repeats directed edge 0→1 of face `0,1,2`.
  - `TriMesh::set_mesh` (`TriMesh.h:339`) calls `compute_edge_quantities`, which throws at `:158–162`, before the rail builder runs. TriMesh owns manifoldness.
  - Consequently, the rail builder's `claimedFaces.size() > 2U` (`RemeshPipeline.cpp:9639`, added by `18357617a`, 2026-10-14) is unreachable through any `TriMesh`. Keep it as defence in depth.
  - The test lines after `:459` have **not executed since 2026-10-14**, so TB46 must pre-register a possible later first failure.
- **H2 `cp3entry:4` — decided: the oracle names the wrong owner.**
  - TB38 site `code=0;sourceAuthoritySite=open-rail-chain` is the A4 checked factory rejecting a draft whose `hardFeatureEdges` were cleared while its open chains remain (`SurfaceCellTracing.cpp:8703–8708`, chain ⊆ hard).
  - This is a torn input, the RA-162 F1 class. A4 owns that consistency and rejects it correctly, so the test's A5 `InvalidHardRailAuthority` expectation (`TransitionQuotientTests:3985–3994`) is unreachable through the checked factory.
- **Cluster E — `selector:201`, `cp3entry:2`. One fixture family, one open question.**
  - Both use the 3×3 grid with the hard midline 1–4–7. 201 asserts that every endpoint has a `terminalVertex` (`REPackageTests:713`); cp3entry:2 requires one two-carrier route (1,4)→(4,7) with a junction (`TQTests:3139`).
  - Since `ccc0b00ab` (2026-10-19), A4 endpoints can be T, R (`railVertex`) or I (interior carrier point) (`SurfaceCellTracing.cpp:19715–19758`, kinds at `:8944`).
  - 201's assertion (`d581fa974`, 2026-10-13) predates that change, and 201 is first RED at TB28.
  - **Hypothesis E:** A4 now publishes the midline as spans ending at R/I endpoints, not as one junctioned route.
  - What is undecided is which representation is canonical: either the tests re-home, or the producer is fixed. TB46 harvests the decisive evidence through message-only diagnostics D1/D2.
- **Cluster G — `selector:442` (A3 `SingularityMismatch` on a relabelled field with a component seam), `focused30:12` (A5 `OccurrenceHardRailTransportMismatch` on a relabelled front), `cp3entry:1` (A4 unequal face-gauge selection).**
  - All three test face-gauge relabel invariance across A3/A4/A5. RA-163 R2 is the governing principle: a gauge relabel must be accepted.
  - DEFN-G follows E. D3 adds the gauge values to cp3entry:1.

#### RA-164.3 Cadence realignment (binding authority: `Turn_Cadence.md`, unchanged)

- The cadence is CB → **full-gate** TB. A green TB closes the checkpoint; a red TB → REVIEW+PLAN, which a DEFN absorbs.
- CP3 drifted into adding CB-REV, focused TBs, green-TB-REV, DEFN-REV and REV-AUDIT turns. From 10-19 to 10-26 that came to 161 turns, 93 of them Review, and 13 ended with BLOCKED or `UNKNOWN`.
- Focused TBs cannot close anything (rule 2), which is why the TB41–TB45 candidates were never reconciled.

**Bounded procedure (applies from CB46):**
- **P1.** Every CB spec carries a hunk allowlist, the next TB's manifest and a CB outcome table. A CB that matches its table goes **directly** to its TB; there is no CB-REV.
- **P2.** Every TB runs the full gate (the current 504-row manifest, with pre-registered first-failure predicates for its RED rows). A focused run is allowed only as a declared non-gating diagnostic row inside a full-gate TB.
- **P3.** Every TB has an outcome table that maps each observable to a named successor. The successor of a red TB is the Review-owned DEFN that absorbs REVIEW+PLAN. There is no separate DEFN-REV.
- **P4. STOP codes** (each successor is fixed):

  | Code | Condition | Successor |
  |---|---|---|
  | S1 | Symbol not visible from the TU | `<CB>-REV` |
  | S2 | Change outside the allowlist (helper or production) | `<CB>-REV` |
  | S3 | Selector or manifest bytes would change | `<CB>-REV` |
  | S4 | A GUARD row turns RED, or a RED row first-fails at a predicate that was not pre-registered | `<TB>-REV` |
  | S5 | Orchestration or infra failure | Cadence rule 5: `<TB>A-ORCH` CB, then re-run the same TB |
  | C2 | Compile error inside an allowlisted hunk | Fix in the same hunk, at most 2 compile attempts; otherwise S2 |

- **P5.** A COMPLETE or BLOCKED beacon must name a successor from its table. `UNKNOWN` is allowed only while the turn is `IN_PROGRESS`.
- **P6.** REV-AUDIT is used only when two durable records conflict on evidence.

#### RA-164.4 CB46 — `M6-CP3-CB46-RP01-RAIL-ORACLE-REHOME-AND-ENDPOINT-DIAGNOSTICS`

Test-only, compile only. **The allowlist is exactly these hunks:**
- **H1** — `REPackageTests:445–459`, inside the 174 body.
  - Build `nonmanifoldFaces` (3×3: `0,1,2, 1,0,3, 0,1,4`) and `EXPECT_THROW(threeFaceSource.set_mesh(incidenceVertices, nonmanifoldFaces), std::runtime_error)`.
  - Then `overfullHard.edges[0].incidentFaces = {0,1,2}` is built on **`manifoldHardSource`**. Keep the four existing rejection expectations: `is_rejected`, null product, `InvalidFeatureEdge`, `failedEdgeIndex 0`.
  - `#include <stdexcept>` is allowed.
- **H2** — `TQTests:3971–3994`, inside the cp3entry:4 body.
  - Control: `construct_phase_front_product(phase_front_draft(rail))` holds a product.
  - With `hardFeatureEdges.clear()`, the result holds a `SurfacePhaseFrontProductError` with `code == InvalidSourceAuthority` and `sourceAuthoritySite == std::string("open-rail-chain")`.
  - Delete the A5 produce on the cleared draft and its `InvalidHardRailAuthority` expectation. Keep the rest of the body.
- **D1** — `REPackageTests:713`. Message only. Stream:
  - the endpoint kind (`R` if `railVertex`, else `I`);
  - `certificates.size()`;
  - the route `oriented_steps().size()` and `junctions.size()`;
  - the carrier vertex pair.
- **D2** — `TQTests:3136–3141`. Message only. Before the assert, build an `ostringstream` listing each produced certificate: its step carrier pairs (via `carrier_vertices`), its endpoint kinds `T/R/I`, and `j=<junctions>`. Append it to the assert message.
- **D3** — `TQTests:2916–2918`. Message only: add `fromGauge` and `toGauge`.

No predicate may change in D1–D3. Do not change helpers, production code, selectors, the harness or workflows.

**Evidence:** the 8 GMP/GMPXX targets, `runtimeExecution=false`, and a record of at most 30 lines that includes the hunk list.

**Outcome:**
- Compile passes and the diff stays inside the allowlist → `M6-CP3-TB46-RP01-FULL-GATE`.
- Otherwise → the matching P4 code.

#### RA-164.5 TB46 — `M6-CP3-TB46-RP01-FULL-GATE`

- Artifact-only, on the CB46 package.
- Harness: `tools/m6_cp3_targeted_artifact_harness.sh`, unchanged (SHA-256 `436f5fff…3c9a`).
- Manifest: `Architecture_M6_CP3_TB46_Full_Gate_Case_Manifest.tsv` (SHA-256 `717f4f0f…6bb087`). It has 504 rows and keeps TB38's identities and order. All 504 test names resolve at HEAD.
  - 191, 192, 204, 247, 250, 405 and 242 become GUARD.
  - 174 and cp3entry:4 become POSITIVE.
  - Five rows stay RED with pinned predicates.
- **Prediction: 499 PASS / 5 RED.** Raw logs must keep the D1–D3 messages.

| Observed | Successor |
|---|---|
| 499/5, with every RED at its pinned predicate | `M6-CP3-DEFN-RP01-TB46-ENDPOINT-CLUSTER` (Review-owned) |
| 174 or cp3entry:4 RED at a later predicate (latent lines), everything else as predicted | Same DEFN; it also disposes that row |
| A RED row passes unexpectedly | Same DEFN; record it |
| A GUARD row turns RED, or a RED row first-fails at an unregistered predicate | S4 → `M6-CP3-TB46-RP01-FULL-GATE-REV` |
| Missing, duplicate or invalid rows, or a harness failure | S5 |

#### RA-164.6 Turn sequence (frozen IDs)

1. CB46 → TB46.
2. `M6-CP3-DEFN-RP01-TB46-ENDPOINT-CLUSTER` (Review-owned; absorbs the TB46 REVIEW+PLAN; decides E) → CB47 → `M6-CP3-TB47-RP01-FULL-GATE`.
3. `M6-CP3-DEFN-RP01-TB47-GAUGE-CLUSTER` (Review-owned; G: 442, `focused30:12`, cp3entry:1) → CB48, which may split by owner, with each CB → `M6-CP3-TB48-RP01-FULL-GATE`.
4. `M6-CP3-DEFN-RP01-O4-O5-RAIL-PROVENANCE` (Review-owned; O4, O5, P1-a, P1-b, RA-162 C1, and the A5 `InvalidHardRailAuthority` reachability left over from H2) → CB49 → TB49, a full gate plus the non-gating P1 rows.
5. A green full gate → RP-01 Review (O6 scope).
6. After RP-01: the O2 DEFN, then DIAG-RETAIN.

Each CB → TB is direct (P1). Each red TB → the next Review-owned DEFN (P3). That is about 12 turns, 4 of them Review.

**Carried:** O1, O2/T2, O6, DIAG-RETAIN, RA-152.5, DEFN-SEAM-NZ (+RA-163.4), RA-146.2/4, RA-45.4, G4-B002.

**Accounting unchanged:**
- Stable 66/17/49, debt 1. CP2 491/491 accepted.
- TB38 490/504 candidate. Focused TB41–TB45 are candidates until TB46 reconciles them.
- Selector497 frozen. RP-01 open.

## `Architecture_M6_CP3_DEFN_RP01_Off_Selector_Coverage_Working_Inventory_20261029.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_DEFN_RP01_Off_Selector_Coverage_Working_Inventory_20261029.md`; moved verbatim.

### Off-selector census: independently re-derived first-failure inventory (working DEFN evidence)

> **Superseded as authority by [RA-172](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_DEFN_RP01_Off_Selector_Coverage_Disposition_20261030.md") (2026-10-30).** This file is retained as per-row source evidence for the repair slices. Row dispositions are in RA-172.4 and the frozen deferred ledger. The "proposed 916" manifest named below was withdrawn and folded; TB51 is the frozen 831-row manifest.
>
> INCOMPLETE ANALYSIS: group classifications below are **hypotheses**, not an adjudicated root-cause finding or stable-regression change. Do not dispatch CB work or execute the proposed TB51 manifest until the DEFN review is completed.

- Canonical turn: `M6-CP3-DEFN-RP01-OFF-SELECTOR-COVERAGE-DISPOSITION`.
- Evidence: [immutable TB50C-R2 run](https://github.com/akashskypatel/Directional/actions/runs/40965775275), results artifact `12941320247`, logs artifact `12940158599`, source `7cf0857b4818186638ce77e4859adacbeebd288f`, package `12918290481`.
- Independently recomputed: result outer SHA-256 `a18758bda0a0877f75f6a82876eb1256f39b51ba9c8a325e80f7c4f72452d18c`; **822/822** internal checksums; **408/408** raw-log digests; ledger 323 PASS + 83 RED + 2 ABNORMAL = 408.
- Existing TB50 candidate manifest: 508 rows, SHA-256 `eef8855e27df9401545a62afab7aea6c9a882bb4a15c58545f2cb49d62fc7caa`; off-gate OBSERVE manifest: 408 rows, SHA-256 `918239009ddee28ebc5c212ef3db0babf2b9f2b8a2755f4321242b7a1ea2ac86`.
- Candidate target if nothing is retired: **916 identities** = 508 + 408; proposed **NON-AUTHORITATIVE** manifest `Architecture_M6_CP3_TB51_Proposed_916_Case_Manifest.tsv` SHA-256 `53f6c02921c2b9257e38dc381a7f8cb23d0cf7458e83e9cefe09960cd3e6c222`. The first 508 rows remain exactly unchanged; the 408 appended observations are GUARD/PASS targets, **not currently green**. The proposed manifest is not runnable authority.
- No accepted-green baseline was rerun. The 85 observations do not independently establish accepted-green loss; stable 66/17/49, debt 1, CP2 491/491 are unchanged. TB50 508/508 remains a reviewed candidate, not CP3 acceptance.

#### First-failure group inventory

| Group | Rows | Working type | First observable failure and evidence |
|---|---:|---|---|
| P01 | 4 | unconditional-FAIL non-verifying probes=4; retirements-authorized=0 | Rows 182/196 share prescribed-sphere cut-graph NoCarrierMatch, while 191 mechanical and 197 torus reach a typed global topology plan and fail later at tracing. These stage observations are genuine but FAIL() forces red regardless of behavior; preserve four independent nonvacuous replacement obligations. |
| P02a | 4 | A3 outgoing-incidence deficit, fixture-versus-producer owner unresolved | All four logs: 2 selected incidences in fan positions 0/1, **none** at fan 2; 2 singleton classes against 3 required. No union/over-merging occurred; sector selection/carrier generation or fixture field must be adjudicated before changing partitioning. |
| P02b | 1 | A3 construction fails with typed cause unknown; reverse-face/metamorphic control provably unexecuted | Row 303 throws in `build(false)` before `build(true)` and all phase-front assertions; a single forward A3 failure masks both intended sheet rejection and reversed-winding coverage. |
| P03 | 3 | A1 boundary-cycle publication fails; exact per-row cause still unresolved; independently proved TriMesh repeated-initialization boundary-cache defect | A fresh mesh and a mesh reused by preconditioning must be distinguished: TriMesh::set_mesh appends boundaryLoops without clearing them, and repeated canonical loops are rejected by A1 finalization. Raw P03 exceptions do not identify which call or failed guard. |
| P04a | 7 | proven fixture-precondition defect | Seven single-triangle FlowRep fixture calls hit TriMesh pure-boundary-face rejection before their assertions |
| P04b | 1 | proven initial fixture-precondition defect; later controls unassessed | SourcePhaseFront test row 354 first exercises count=1; TriMesh rejects the pure-boundary face before incidence-count assertions |
| P05a/P05b | 3 | invalid region identity on input arcs=3; first reject type still unknown in 2 | Row 8 fails downstream arrangement at known region-3 vs true-region-0 mismatch; rows 16/48 use the same wrong region identity, which prevents same-region network capture, but their original typed completion rejection remains unreported. |
| P06 | 3 | wrong input arc topology-region identity proven; typed rejection unreported=3 | Rows 15/17/35 all stamp TopologyRegionId(3) from the *component* label, but genuine one-face A2 source topology has region ID 0; typed failure details are unprinted, so downstream cause remains unverified. |
| P07 | 11 | registry-precondition-absent=8 (57/58/60/64/65/66/68/69; typed registry mismatch directly observed 58/66); wrong-fixture-argument=1 (54); unsafe-variant-access=1 (61); mixed-provenance-contract-open=1 (52) | The seven newly audited helper paths construct complexes without canonical ownership records, so their later ownership/repair assertions are not yet reached. Only 58/66 have logged registry-mismatch at the exact first identity audit; the other five require typed preflight confirmation. No claimed producer regression is established by a zero-attempt counter. |
| P08 | 13 | missing-A2-source-authority-fixture-proven=13; downstream simplifier untested | All 13 tests call arrangement constructor without sourceAuthority; source producer fails closed with empty halfedges before simplification |
| P09a/P09b/P09c | 4 | proven-projection-omission=1; shared-sphere-trace-event-rejection-observed=2; ordinary-crossed-edge-proposal-structurally-excluded=1 (frozen AK4 correction) | Row 175 loses singularity on diagnostic projection; rows 192/344 reject source-carrier event placement; row 350 proves the expected ordinary trace-crossed promotion is excluded by the present proposal barrier set, and certifies only after saturation. The ordinary-proposal requirement is already frozen under `M3_Closure_Record.md` CP4c-3 AK4. |
| P10a/P10b | 5 | four cone fixtures have an independently proved A3 cycle-transport consistency defect (exact first native guard unlogged); one invalid vertex-arrival fixture choice | Rows 235/236/237/241 use a three-right-angle cone with curvature +pi/2, zero edge efforts and radial matching {2,2,0}; the necessary local-vertex turning lift is +1 mod 4 but the composed matching is 0 mod 4. A3 cannot publish a cycle satisfying both; exact first native reject is unprinted. Row 243 separately has inadmissible arrival direction and no Evaluated state. |
| P11 | 6 | untyped-isolation-equivalence-oracle-proven=1; stale-cross-representation-oracle-proven=1; missing-A2b-provenance-preflight=1; stale-typed-reason-oracle-proven=1; uncovered-hard-rail-negative-preflight-proven=1; nonterminal-endpoint-oracle-defect-proven=1 | Row 331 requires a nonempty route for an isolation seam whose authoritative CornerWedgeIsolation evidence is in isolationTransitions; this does not prove the required seam transition was produced. No P11 RED is currently a newly confirmed stable regression. |
| P12 | 8 | regression-candidate=3; stale-oracle-proven=4 (row 276 chart numbering plus 279/296/317 unconsumed negatives); uncalibrated-microbenchmark=1 | Row 276 wrongly equates gauge-rotated field arms with topology-derived FieldChartId; 277/283/286 remain distinct producer candidates |
| P13 | 3 | cut-domain-Euler-identity-mismatch-observed=1, timeout-unattributed=2 | Bunny row 360 fails FieldTransportAtlas local transport-cut identity (expected chi -5, observed -3), not output meshing; cylinder/vase are 600s harness timeouts |
| P14 | 9 | source-projection-label-omission-proven=2 (375/385); multi-rail-chart-fixture-order-defect-proven=3 (406–408); missing-boundary-authority-fixture-proven=2 (373/401); source-projection-Jacobian-omission-proven=1 (390; total observed error contribution unquantified); metric-contract-open/strict-failclosed=1 (399) | In rows 373/401, the fixture supplies no authoritative boundary loop despite a nonempty source boundary; the strict validator deterministically rejects with MissingBoundaryAuthority before acceptance, even though the original logs do not print typed issues. Additional rejection reasons are unobserved. |

**Important:** `regression-candidate` means an existing test expectation is unmet on this unaccepted source/package; it is **not** a verified newly introduced stable regression. `stale-fixture-candidate` is an investigation request, not permission to weaken test assertions. `timeout-unattributed` cannot be called a platform failure without comparison evidence. The unconditional `FAIL()` probes are retirement *candidates* only; a replacement non-vacuous test or documented loss-of-coverage decision is still required.

#### Required causal proof and one-CB-per-group disposition

- P01: Four probes with an unconditional `FAIL()` in `tests/FieldAlignedCurveNetworkTests.cpp` (lines 10494, 10500, 10506, 16392). Convert to meaningful predicate assertions in a separately specified CB, or provide independently reviewed evidence why each can be retired without losing necessary witness coverage. **No retirement is currently authorized**.
- P02a (rows 24,37,45,46): investigate singularity port class-count mismatch at `FieldTransportAtlas::make` on tetrahedral fixture; distinguish incorrect synthetic field/matching/expected valence from incorrect atlas partition. Preserve independent singularity port-index, orientation, and determinism assertions. Do not bypass singularity validation.
- P02b (row 303): retain unsupported-sheet negative, expose the typed A3 build error from `FieldTransportAtlas::make` before changing source authority or concluding O2; prove that the intended unsupported-sheet consumer is actually reached.
- P03 (rows 157,163,313): reconstruct why A1 finalization fails to publish exact source-boundary cycle facts. Review all branches in `populate_source_boundary_cycle_facts`, particularly boundary vertices mapping to a single `local2Cycle`; ensure fixture input is valid and reject incomplete/contradictory authority. This is not an observed A3/O2 failure, and must remain separate from O2 unless independent evidence connects them.
- P04a (7 rows): Change the seven standalone-triangle FlowRep test meshes to valid, consistently oriented two-face disks while retaining the source-face-0 geometry, first-face barycentric coordinates, and independent A2/A3 authority. Preserve positive and negative assertions. Do not weaken `TriMesh` consistency.
- P04b (row 354): Separate the one-incidence negative, two-incidence positive, and three-incidence negative synthetic authority witnesses. The first control currently calls `TriMesh::set_mesh` on a single pure-boundary face, which cannot pass that API's preflight. Design a genuine source-bound atlas witness for each reachable control without weakening manifold/DCEL checks or accepting forged transitions; independently prove each control reaches its intended A4 incidence predicate.
- P05: Re-derive sub-tolerance identity tests under the project’s exact-coordinate/source-entity contract. If the asserted tolerance behavior contradicts normative design, write an explicit retired-or-replaced rationale per identity and a non-vacuous exact-identity replacement.
- P06: Inspect returned typed endpoint-completion disposition and source-chart/rail dependencies for three tests. Distinguish missing producer prerequisites from a real endpoint completion defect; define a minimal correction at the responsible producer.
- P07: Preserve all eleven rows. Separate four CB designs: (a) **valid source-bound ownership registry and chart-canonicalization fixture repair** for 57/58/60/64/65/66/68/69, preserving each distinct domain/route/repair obligation, (b) correct the passed `invalid` tuple in 54 while proving fail-closed partial-output rollback, (c) enforce a hard produced/rejected branch and capture typed rejection in 61, and (d) adjudicate the authoritative-domain-versus-alternate-provenance contract in 52. The registry group is a shared missing prerequisite, **not** evidence that all eight tests share one runtime failure; stage a typed first-rejection control before any repair assertion. Never change the production domain validator or weaken ownership checks to make these fixtures pass.
- P08: **Shared first-stage root proven for all 13:** every test creates an arrangement with the default empty `sourceAuthority` option, and the source producer returns an empty invalid complex before simplification. Repair the synthetic fixtures with genuine face-bound `SourceTopologyRegions`, including the disconnected two-face negative. Re-derive their topology, candidate, protected-support, healing, and transactional assertions *after* preflight is valid. Never inject artificial candidates or treat absence of candidates as proof the simplifier is correct. The downstream simplification contract remains untested by these runs.
- P09: Row 175 has a proven diagnostic projection omission (previous audit). **Rows 192/344** share the `sphere_prescribed` mesh/field and default `cp4c_remesh_options()`: the source atlas/network exist, but `build_embedded_graph_topology` rejects event placement because a non-terminal incidence on trace 2 has no source-edge carrier. Preserve the fail-closed source-carrier check and diagnose why the network published an incidence that is not positionable; an event producer defect and an incorrect expected witness remain separate hypotheses until independently demonstrated. **Row 350** has a *different* post-certification difference: `saturationUsed=true` in a successful certificate despite a selected trace-crossed candidate. Do not merge it with rows 192/344. Require measured ordinary proposal progress/candidate classification before considering any change to fallback; preserve `proves_embedded_cellularity` as authority.
- P10: Investigate five folded-cone/vertex-transit source atlas and ownership witnesses; establish correct branch monodromy and source-authority construction before changing production.
- P11: Audit A2b/A3 terminal rail paths, hard-carrier reciprocal transport, boundary authority and quotient lineage with exact expected/observed predicates; preserve O9/O13 ownership. Row 324 is an independently proven **stale error-label assertion**, not an accepted-source-boundary leak: production rejects forged boundary route as `FalseAuthoritativeSourceBoundary`, whereas the test expects `InvalidSourceBoundaryAuthority`.
- P12: Preserve all eight cases. Four are independently identified oracle/ingress defects (276, 279, 296, 317), three remain distinct producer/fixture candidates (277, 283, 286), and 314 is an uncalibrated timing assertion. Row 276 must separate topological source-chart component identity from raw cross-field branch-gauge rotation. Correct the test only via independent A2/source-chart graph authority and a non-vacuous multi-chart fixture, while retaining a separate source-produced A3/A4 branch-transport oracle; no artificial chart ID injection. Keep unresolved first-failure witnesses for 277/283/286 unchanged.
- P13: Bunny row 360 fails **before network/arrangement/quad output** in `FieldTransportAtlas::make` local cut-domain validation. The raw diagnostic reports uncut chi=2, 17 barrier edges, 24 barrier vertices, barrier chi=7, boundary-barrier vertices=0, cut chi=-3, cut loops=5; `FieldTransportAtlas.cpp` computes expected cut chi = 2-7+0 = **-5**, unequal to -3. This proves the checked Euler identity is violated for the constructed transport cut; it does **not** identify whether fixture hard features, local vertex splitting, barrier component census, or the expectation is wrong. Require all `cutIdentityValid` conjuncts and exact per-edge cut-boundary multiplicities to be observed without weakening the identity. Cylinder and vase remain **unattributed** 600s harness timeouts and require bounded focused reproductions; do not relabel them platform failures or bypass the full-suite no-timeout rule.
- P14: Audit nine optimizer tests for source provenance, exact chart reachability, derivative mismatch (size-energy relative error 0.083494...), and final validator state. Reconcile domain/rail transport before post-hoc validator changes.

#### P07 exact ownership-registry fixture audit (2026-10-30; no native execution)

**Source authority:** immutable semantic source `7cf0857b…` remains unchanged in implementation/tests through entry branch `d80249a9…` (GitHub compare from verified 050f snapshot lists only the two Review documents, dispatcher control, snapshot trigger cleanup and STATUS). Reused verified 050f snapshot and TB50C-R2 `raw/58,60,64,65,66,68,69.log` (already included in the 822/822-verified result). The source audit is static; no replacement test was compiled or run.

1. **Directly observed first failure, rows 58/66:** `tests/PatchDescriptorMilestoneETests.cpp:1269–1297` / `1110–1147` start with `make_authoritative_patch`, which fills nodes, halfedges, cells and diagnostics but **does not assign** `cell.sourceOwnershipClass` or `complex.sourceOwnershipRegistry` (`:226–263`). Row 58 logs `SuccessfulSubdivisionDomainIdentity;identityFailure=ownership-registry-mismatch`; row 66 logs `ownership-registry-mismatch` at `audit_surface_cell_domain_identity` and an active descriptor conflict. `src/geometry/PatchDescriptor.cpp:587–619` requires the cell ownership class and matching registry **before** checking chart/domain geometry; `src/geometry/SurfaceCellFeasibilityRepair.cpp:1059–1061` transfers the input registry through subdivision rather than inventing missing ownership. This is an independently proved fixture-authority omission at the reported failure locus. It does **not** prove successful subdivision or singularity ownership after a valid registry is supplied.
2. **Five further tests with the *same missing prerequisite* but unreported first typed failure:** rows **60,65,68,69** all call `make_valid_parallel_route_same_corner_complex()` (`tests/...:624–782`); row **64** calls `make_same_corner_distinct_boundary_components()` (`:584–621`). Both manual helpers return without `bind_patch_charts_to_source_topology`/`canonicalize_surface_cell_ownership`; neither constructs ownership records, and the component append helper also does not merge/refresh the registry. The frozen logs show 0 candidate/repair attempts in rows 60/65/69, empty attempt vector for 65, and absent expected same-corner conflict/exhaustion in 64/68/69. These symptoms are consistent with failure before the same-corner repair frontier, but logs **do not print** an exact `OwnershipRegistryMismatch` for these five. Do not certify a common first error without a typed preflight receipt.
3. **Related row 57 (previously classified):** the duplicated-domain fixture appends uncanonicalized patch components and therefore likewise lacks a matching registry. It needs an independently valid initial source-ownership certificate *before* asserting duplicate-domain conflict precedence. This is a distinct negative witness, not permission to normalize intentional overlap away.

**Exact future fixture CB contract:** In `tests/PatchDescriptorMilestoneETests.cpp`, produce stable source-topology-bound charts and a validated `sourceOwnershipRegistry` for each intended source *before* calling side repair/completion; use the existing `complete_fixture_with_source_authority` (`:266–329`) and valid two-cell canonicalization (`:575–578`, `:1013–1025`) only when their source-region assumptions actually fit. Assert `validate_surface_cell_ownership_registry`, cell exact domain identity and typed first-stage readiness. For the intentionally overlapping/parallel-route fixtures, create independently valid owners and verify **both** claimed domains remain distinct after canonicalization; a failure to create two valid owners is a fixture-design stop, not a reason to relax production checks. Preserve each original discriminating assertion: invalid duplicate scope in 57, singularity vs ownership outcome in 58, hard candidate budget/counters in 60/69, no semantic-only overlap in 64, reordering invariance in 65, exact subdivision/domain in 66, and successful route-complete repair in 68. Add a separate malformed-registry negative that must reject at the registry guard. Independently execute focused positive and negative controls in a future TB turn; this DEFN changes no test or producer code.

**Disposition:** eight P07 records have a demonstrably absent fixture prerequisite (57/58/60/64/65/66/68/69), two of which have exact first-locus runtime evidence; remaining three are case 52's unresolved mixed provenance authority, case 54's incorrect completed-fixture argument, and case 61's unsafe failed-product access. **Zero retired; all 11 are retained pending repaired tests.** Do not count a fixture repair as proof of any downstream producer contract or an accepted-green regression.

#### P14 row 399: unscoped geometric metric fallback is not strict source-sheet acceptance (2026-10-30; runtime-free)

The immutable `raw/399.log` of `SurfaceMeshOptimizerPhase21.MixedOutputSheetAuthorityFailsClosed` (`tests/SurfaceMeshOptimizerPhase21Tests.cpp:395-442`) fails *only* its `std::isinf(report.quadToSourceMax)` expectation. Both `std::isinf(report.sourceToOutputMax)` and `EXPECT_FALSE(report.accepted)` do **not** fail in that log. This is positive evidence of a strict fail-closed verdict under that particular test run, not proof that its separately asserted *numeric* metric contract was met.

The fixture uses two distinct source sheets (`sourceFaceSheets={0,0,1,1}`), then forcibly writes alternating output-quad corner provenance `sheet={0,1,0,1}` without supplying `constraints.vertexChartAuthority` (`SurfaceMeshOptimizerPhase21Tests.cpp:34-70,395-442`). `SurfaceMeshOptimizer.cpp:986-1014` makes `quad_chart_authority(...)` invalid when the entire typed `vertexChartAuthority` vector is empty; `:1018-1084` consequently cannot establish `consistent_source_scope` for that quad. Nevertheless, the `validate_final_surface_mesh` **numeric quad-to-source 3x3 sampler** (`:2507-2555`) explicitly falls back to `nearest_source_point(sample,constraints,sourceScope,...)` when `chartFaces` is empty, with `sourceScope=nullopt`; `:126-141` dispatches the unscoped search to `SourceProjectionCache`. For two near-coincident planar source sheets, a valid geometric nearest point can thus return finite distance even when the output provenance sheets are mutually incompatible. `:2685-2695` sets `quadToSourceMax` from those geometric distances. The **independent strict source-authoritative validator** is invoked only afterward (`:2782-2807`), and `strictValidationAccepted` is explicitly required for `report.accepted` (`:2848-2852`). Numeric distance and semantic source-sheet acceptance are distinct checks; the run confirms only the latter rejects.

**Classification:** first-stage *metric scope fallback proven; fail-closed acceptance observed*, **normative metric-sentinel semantics still open**. The raw log does not publish `strictValidationIssues`, `sourceToOutputMax` or the exact offending typed validation issue; do not invent that subtype. Neither declaring metric omission harmless nor forcing all distances to infinity is authorized without a Review decision distinguishing geometric-distance telemetry from source-authoritative compatibility telemetry. No acceptance, source guard or test weakening.

**Falsifiable CB boundary:** retain a genuine two-source-sheet negative with alternating provenance, assert `!report.accepted` and the specific source-sheet/quad-chart incompatibility issue after capturing actual strict validation issues (with a same-sheet positive and source-position adversary); independently define whether `quadToSourceMax` is geometry-only or authority-scoped. If the contract requires authority-scoped values, an incompatible quad must emit an explicit *invalid-metric* sentinel (e.g., infinity) before unscoped fallback while a valid chart's finite 3x3 projection remains unchanged. If the metric is deliberately geometry-only, revise the stale infinity oracle **only after** retaining a separate non-vacuous typed-invalid witness and documenting why a finite geometric distance cannot be mistaken for acceptance. Include a deliberate projection-fallback negative to prove no cross-sheet acceptance. Do not suppress `strictValidationAccepted`, change tolerance thresholds, or infer `sourceToOutputMax` from the single failed assertion.

#### P14 row 390: exact active-set source-projection derivative omission (2026-10-30; source-only proof)

The isolated size-energy test is a real differential oracle: `SurfaceMeshOptimizerPhase20Tests.cpp:104–140` compares `evaluate_surface_optimization_gradient` against an **independent central finite difference of the actual full energy**, with only `weights.size=1`, and fails at relative error `0.083494013311452384` (`raw/390.log`, `SCOPED_TRACE("size")`). Preserve its `1e-6` requirement. The following is a *source-proven local inconsistency*, not a claim to have recomputed the entire observed error or repaired the algorithm:

- Fixture source is the planar square `[0,2] × [0,2]`, triangles `(0,1,2)` and `(0,2,3)`, with vertex size values `(0.9,1.1,1.2,0.8)` (`SurfaceMeshOptimizerPhase20Tests.cpp:45–70`). Test output vertex 3 starts at `(-0.1,0.9,-0.05)` (`:27–33`): its closest source point is **clamped to the external edge `x=0`**, not an interior source-triangle point. For perturbations of vertex-3 `x` by ±`1e-6`, the projected point remains on that edge, so the local scalar target is constant with respect to that perturbation. This claim assumes the nearest-point projector takes the obvious unique closest point on the shown planar source square; verify its exact selected face and tie policy at the later execution gate.
- The piecewise-linear size field on triangle `(0,2,3)` is `h(x,y)=0.9+0.2x−0.05y`, hence its **unconstrained source-face gradient is `(0.2,-0.05,0)`**. `SurfaceMeshOptimizer.cpp:561–568` returns precisely that face gradient via `source_triangle_scalar_gradient`; `:2030–2066` adds `0.5*(∂E/∂target)*local_target_size_gradient` directly to each output vertex. There is **no derivative of the nearest-source projection map** in this path. At the externally clamped vertex the actual `x`-derivative of `h(project(v))` is zero, not `0.2`. Thus the analytic expression is not the derivative of its own energy (`:1490–1504`) for this active set whenever the affected edge's size residual is nonzero.
- The exact **size-gradient mismatch is a production derivative defect at this active projection set**. Whether it wholly explains the logged `0.083494...` vector norm, and whether other seam/vertex active sets suffer distinct errors, remain unverified; do not assign the whole test failure to this mechanism without per-vertex component evidence.

**Future dedicated CB, not authorized to execute in this DEFN:** make the differentiable size target a function of the actual source projection, including its active-face/edge/vertex Jacobian. Interior source-face support uses the tangent projection; an exterior clamped source edge uses the edge-tangent projection (zero normal-to-edge derivative); a source vertex remains locally constant until the active set changes. Resolve nondifferentiable tie/crossing behavior explicitly and consistently with the energy, not through tolerance inflation or global finite-difference substitution. Falsifiers: interior point recovers the full source-face gradient; exterior x-clamped point has zero target derivative under small ±x displacements and retains its y derivative; two-face seam and corner clamp controls do not cross source sheets; analytic and independent finite differences agree under unchanged active sets to the original threshold. Record per-vertex, per-axis energy/gradient terms and first-selected projection simplex. **No source, test, fixture, or selector was modified or executed here.**

#### P12 row 276: raw field branch relabels cannot establish typed source-chart splits (2026-10-30; source/log independent)

`raw/276.log` (immutable TB50C-R2) shows the phase-front is produced and the comparison fails for face 3 (expected `FieldChartId(1)`, observed 0) and face 10 (expected 2, observed 0), including both `boundaryPaths[*].sourceChart` and `cell.lattice[*].sourceChart`. The collected actual chart IDs are precisely `{0}` rather than the asserted `{0,1,2}`; these are not product rejection or atlas-preflight failures.

The test (`tests/SurfaceCellsPhase10Tests.cpp:5924-5985`) invents `expectedChartByFace[3]=1` and `[10]=2` after calling `make_segment_route_fixture()`, which sets *raw field branch shifts* `branchLabels[3]=1` and `[10]=3` (`:1352-1363`). Its `build_segment_route_network` helper (`:1378-1405`) constructs A2 with **every face in the same source component and sheet**, passes no hard-feature edges, and builds A3 from the authoritative cross-field. In `include/directional/geometry/SourceChartTransitions.h:179-194,595-750`, `SourceChartTransitionGraph` deliberately constructs source `FieldChartId` by connected components of the exact source-face adjacency **minus hard-feature barriers**, within published A2 source components. It does not inspect raw field branch order or gauge. The underlying source mesh is a connected, consistently oriented 5x4-vertex planar triangulated grid (`SurfaceCellsPhase10Tests.cpp:1122-1150`, 24 triangles), with no fixture barriers. Therefore there is one topological chart component and the canonical chart ID is 0 on faces 3 and 10; raw branch relabels cannot produce two additional *source* chart components. `SurfaceCellTracing.cpp:14077-14090` constructs these canonical charts directly from the source graph, and later source-chart projection at `:13888-13892` / `:14015-14019` looks up `sourceCharts.chart(segment.face)`.

**Disposition:** proven **stale independent oracle/fixture-design defect**, not a newly proven accepted-green regression or license to overwrite producer source-chart IDs. The test confuses `FieldChartId` (source-topology chart-component authority) with per-face raw branch/gauge labels, which are separately handled by atlas/branch transport. Retain case 276 as RED until a Code + Build boundary repairs and independently executes it. The other P12 rows 277/283/286 remain unresolved production/fixture candidates.

**Falsifiable CB definition:** (1) retain the original connected, barrier-free fixture as a true *single source-chart* positive and assert chart 0 on every observed boundary/lattice occurrence while separately checking a genuinely changed field branch/gauge transport on nontrivial source A3/A4 routes (with correct independent signed expected transports, not atlas-versus-atlas equality); (2) construct a separate valid source-bound *multi-chart* positive by actual barrier/domain topology (all A2/A2b rail covers/terminals and A3 source provenance must pass independently), compute expected chart membership from independently enumerated topology components without copying `SourceChartTransitionGraph`'s output, and require at least three reachable, nonempty typed chart occurrence sets with stable canonical IDs and face-order-invariant component membership; (3) introduce an invalid chart-crossing/forged component negative at an actually consumed authority seam and assert the exact reject site while preserving genuine A3 transport and checked A4 ownership. If a genuine three-chart source cannot be constructed without invalid upstream hard-rail authority, do not weaken that authority merely to force the positive; specify a separately valid multi-component source fixture. Do not accept 0 as a substitute for the positive multi-chart coverage.

#### P12 first-stage source witness separation: cases 277, 283 and 286 (2026-10-30)

Static audit reuses the verified 050f source snapshot (tests/source unchanged through current branch) and original 822/822-verified TB50C-R2 row logs. **These are measured first failures, not root-cause determinations or runtime improvements.**

- **277 (two-carrier A4 proof is absent):** `tests/SurfaceCellREPackageTests.cpp:1177–1240` constructs a real 4-triangle rectangular source, places user hard edges `(1,4),(4,7)`, generates a right-half quarter-turned raw field, and requests a checkpoint after stage 6. It expects an A4-produced route certificate whose `oriented_steps()` contain **both** hard edges and exactly one junction at vertex 4. The frozen log at `:1240` reports `route == routes.end()`, while `InjectedStageFailure` confirms the requested pipeline checkpoint; no atlas, hard-edge/phase-front, or source-region rejection is reported. The failure is **absence of the specifically required two-carrier route**, not proof of an incorrect odd A1 gauge or successful coverage by two unrelated single-carrier routes. Cause remains test fixture/trace scheduling versus A4 route publisher. Future CB: independently inventory A3 hard carrier edges and source-region identities, A4 candidate front edges, terminal receipts, checked route certificates and exact oriented steps; require a paired positive and an invalid missing/junction-swapped negative, invariant under face-row permutations. Do not manufacture certificates inside tests or change A5 to satisfy a missing A4 producer.
- **283 (periodic torus fails at bounded-disk turn precondition):** The direct strict `SurfaceCells` torus test (`tests/SurfaceCellsPhase10Tests.cpp:5354–5400`) rejects at tracing/phase-front `InvalidBoundedDiskBoundaryTurn` before any output. The zeros for `surfaceCellTopologyRegionCount`, materialized components and isolation seams in the frozen log are downstream consequences, not proof that source topology lacks seams. In `src/geometry/SurfaceCellTracing.cpp:16742–16762`, this typed reason is selected when successive *bounded-disk boundary runs* have branch delta **other than 1 or 3 modulo 4**. The immutable row does not reveal which runs or vertex triggered it or whether a torus isolation seam was wrongly presented as a bounded-disk boundary. Require a source-produced typed classification of true source boundaries, hard rails and internal isolation seams *before* evaluating turn sums, plus the exact failing pair/vertex as a bounded fixture witness. Preserve closed torus Euler 0, zero exterior source boundary and no recovery; do not suppress the turn guard for actual disk cells.
- **286 (hard-rail reciprocal region copy blocked before quotient):** `tests/SurfaceCellsPhase10Tests.cpp:3159–3215` sets an internal hard feature `(1,4)` across a 4-triangle two-sided disk and asks for reciprocal A4 hard-rail edges/merges before quotient materialization. Its first `ASSERT` fails with typed `InvalidFrontBoundaryAuthority` (`raw/286.log`); no reciprocal edges or merges are observed in that run. Multiple checks can return this reason (`SurfaceCellTracing.cpp:12853–13047` and later), so the subtype cannot be inferred from the generic code alone. Future CB: bind exact source-edge, region/sheet, incident faces, front-side and exterior flags at the actual rejecting condition; require two opposed checked hard-rail edges and reciprocal merge on the valid fixture plus a forged boundary-side negative. Preserve proper fail-closed checks. **No producer patch is authorized from this diagnostic alone.**

**Gate consequences:** 277, 283 and 286 remain three non-PASS P12 regression *candidates*, not accepted-prefix regressions; 276 remains independently unresolved. No retirements, no test/fixture/selector changes and no native execution. The proposed 916-case TB51 file is still not executable authority.

#### Source-grounded correction on continuation (2026-10-30; runtime-free)

This supplements the earlier first-failure inventory. The previous P04 label was too broad: the eight tests share the *exception text*, but do not establish one common root cause. The partition below is based on independently inspected repository source plus the immutable raw logs. No executable was run.

1. **P04a — seven FlowRep tests, rows 22, 28, 33, 34, 38, 39, 43.** Every failing test constructs a single triangle `faces << 0,1,2` and calls `attach_source_authority(...)`, whose `sourceMesh.set_mesh(vertices, faces)` calls `compute_edge_quantities()` (`tests/FlowRepStrandsPhase15Tests.cpp:64–87`, e.g., tests at 1841, 1895, 2315, 2480). `TriMesh::compute_edge_quantities()` invokes `dcel.check_consistency(verbose,true,true,true)` (`include/directional/core/TriMesh.h:159–162`). `DCEL::check_consistency()` rejects *every* face with no interior/twinned edge when `checkPureBoundary=true`: `face is composed entirely of boundary edges` (`include/directional/core/DCEL.h:1546–1564`). The standalone triangle has three pure boundary edges, so this first-stage exception is causally explained. These seven tests do **not** yet establish a FlowRep producer regression. The same test file already contains two-face-disk replacements in later controls (`RailTruncatedGenericSupport...`, around 1449); reuse that valid setup pattern only where the intended semantics are preserved. Classification: **invalid fixture under the current strict source-mesh precondition**, not an accepted-green regression. A CB may fix fixture geometry; the independent test must still fail if its intended FlowRep requirement is broken.
2. **P04b — row 354, not the same test construction.** `tests/SurfaceCellTransitionQuotientTests.cpp:2154–2288` builds `sourceFaces(count,3)` inside a helper and executes `attempt(1U,...)` before the later two- and three-incidence controls. The first count=1 mesh is again pure-boundary and is passed to `sourceMesh.set_mesh()`, explaining why the test aborts before asserting a typed A4 result. The count=3 nonmanifold scenario has **not** been reached or validated by this run. Classification: **initial synthetic fixture preflight invalid**, with later outcomes unobserved. Do not replace or skip `count=1` in a way that destroys the necessary one-incidence negative control. Require independent typed A3 witness construction and proof of all three incidence branches.
3. **P01 — four always-failing reachability probes, rows 182, 191, 196, 197.** The test bodies explicitly invoke `FAIL() << observation.report` after gathering observations (`tests/FieldAlignedCurveNetworkTests.cpp:10491–10507`, `16388–16392`). On any execution reaching that statement, the tests fail regardless of correctness; a red census verdict therefore proves no product regression. Classification: **non-vacuous-test-authority defect**, with *no retirement yet*. Replace each with falsifiable assertions at its claimed seam, or give a separate, individually justified retirement and coverage-replacement decision in Review.
4. **P14 row 390 — focused differentiable-energy mismatch.** Raw `390.log` reports `SCOPED_TRACE("size")` and relative gradient error `0.083494013311452384` against the preserved `1.0e-6` independent finite-difference threshold (`tests/SurfaceMeshOptimizerPhase20Tests.cpp:126–137`). The size energy accumulates `(length / effective_edge_target_size - 1)^2` (`src/geometry/SurfaceMeshOptimizer.cpp:1486–1504`); the analytic gradient uses local target-size derivatives (`...:2030–2065`). The precise derivative discrepancy is **unresolved**, not a tolerance license; CB must compare individual edge/target derivative terms, preserve independent finite differences and the original bound.
5. **P12 rows 296 and 317 use different stale ingress assumptions.** Row 296 sets raw component/sheet projection mirrors but calls the generic validator, which intentionally requires exact source-face equality without typed cross-chart proof; row 317 tampers with ignored raw transitions while supplying a valid authoritative atlas (details below). Both require meaningful replacement oracles through their actual authority seams; do not weaken the source-authoritative T-junction/transition guards.
6. **P12 row 314 is an uncalibrated micro-timing expectation, not a proven performance regression.** The raw log compares approximately `169.358 µs` validation against a `124.8421 µs` five-percent threshold (`tests/SurfaceCellsPhase10Tests.cpp:1104`). Before assigning platform cause or retiring, require repeatable sufficiently long runs and an independently enforceable performance requirement; retain a meaningful validator safety oracle separate from timing.

##### Independently established stale negative oracle: row 317 (2026-10-30)

`tests/SurfaceCellsPhase10Tests.cpp:1770–1798` adds a duplicate transition to `crossField.edgeTransitions`, but constructs a valid `FieldTransportAtlas` from the *untampered* `sourceField` and sets `options.fieldTransportAtlas` to it. At `src/geometry/SurfaceCellTracing.cpp:21221–21237`, the `build_surface_cell_network(vertices,faces,crossField,...)` overload **explicitly passes `nullptr` for matching, effort, and transition vectors when an atlas is supplied**. Its comment says these are legacy/test ingress and production uses the atlas. Consequently the injected duplicate never reaches `authoritative_edge_transition_lookup`, so the unexpected `Produced` result is not evidence that the authoritative duplicate-transition guard failed. The guard still exists at `src/geometry/SurfaceCellTracing.cpp:12014–12031` (and 12568–12583). Classification: **stale/non-vacuous-test-authority defect, not a proved producer regression**. Proposed CB scope: reauthor the negative through the actually consumed authority/factory seam using a legitimate tampered-source-atlas construction if available; separately assert that changing ignored raw metadata under a valid atlas does *not* change authoritative behavior. No validator or producer guard weakening is authorized. The revised negative must fail if duplicate metadata is admitted at a consumed authority seam.

##### Defensible disposition boundary

- **Proved first-stage fixture causes:** P04a 7 plus P04b 1. **Proved non-verifying probe failures:** P01 4. **Proved stale negative-test ingress:** P12 row 317. **Independently localized energy mismatch:** P14 row 390. Other observations remain candidates with typed/raw-log first failure, **not** independently proven root causes.
- **No retirements authorized:** 0. Consequently `508+(408-0)=916` is only the all-retained *planning cardinality*; the 916-row GUARD/PASS draft is **not executable frozen gate authority** because 85 observations are not green.
- **Corrective CB separation:** a FlowRep strict-mesh fixture CB (P04a) must not silently absorb source-authority factory incidence controls (P04b), optimizer derivative corrections, or negative validator guards. One CB per independently proven causal change, with standalone falsifying tests and frozen source/package identities. Preserve O2 and O9/O13 ownership, accepted CP2 491/491, reviewed TB50 508/508, stable accounting 66/17/49 and debt 1.
- **Unresolved:** full 85-row root-cause adjudication, authoritatively justified retirements, patch-by-patch exact specifications, and genuine TB51 freeze. No semantic acceptance or successor release is supported yet.

#### Additional source-grounded adjudication, continuation 2026-10-30 (no native execution)

This section corrects the earlier overbroad O2 attribution and identifies two negative controls that **already fail closed**. It is based on the source snapshot `76c2aacf4c5bd3f8018831ddc12f77c8df71d52a` and immutable individual logs. Classifications are scoped to the observed behavior; unobserved later contract steps remain unresolved.

##### P03 additional source-only causal hazard — repeated TriMesh::set_mesh retains stale boundary loops (2026-10-30)

This is a **demonstrable production-state defect in the source** but **not yet a proven first runtime cause for any one of the three immutable P03 logs**. Keep all rows 157/163/313 RED, with exact first guard unknown.

1. `include/directional/core/TriMesh.h:143–244` implements `compute_edge_quantities()` using `boundaryLoops.push_back(currBoundaryLoop)` at `:241` for every freshly enumerated boundary loop. The function resets `innerEdges`, `boundEdges`, boundary flags, edge tables and the DCEL, but contains **no `boundaryLoops.clear()`**. `TriMesh::set_mesh` (`:331–360`) calls `compute_edge_quantities()` on **every invocation** without clearing `boundaryLoops`; its subsequent `numGenerators` uses the accumulated size. Thus on a live `TriMesh`, repeated `set_mesh` appends old-loop records. This is independently reproducible from the deterministic source control flow (no native program was executed in this DEFN).
2. `src/pipeline/RemeshPipeline.cpp:19882–19915` in non-SurfaceCells preconditioning initializes `meshWhole.set_mesh(vertices,faces)`, then, when `preconditionInputMesh=true`, calls `meshWhole.set_mesh(preconditioned.vertices,preconditioned.faces)` on the **same object**, or calls `meshWhole.set_mesh(vertices,faces)` again in the fallback catch. Both pathways leave stale boundary loops if the input has a boundary. Tests `BoundedMeshPreconditionerTests.cpp:213–265` cover P03 rows 163/157 and use a 2x2 triangulated grid with an exterior boundary; row 157 runs disabled and then enabled, while 163 runs enabled. A raw-log C++ exception does **not** locate which of the two row-157 calls failed; it cannot prove this hazard is its first cause. Row 313 uses a different two-triangle source and is **not** shown to reuse a `TriMesh` object.
3. `src/fields/CrossField.cpp:58–116` iterates all `mesh.boundaryLoops`, canonicalizes each vertex cycle, and rejects **adjacent duplicate canonical loops** after sorting at `:108–113`; stale copies of the **same** boundary therefore deterministically force `populate_source_boundary_cycle_facts=false`, causing the exact `Cross-field finalization could not publish source-boundary cycle authority` exception at `:208–210`. If the old/new loops are different, invalid indices, different local cycle-row assignment, or inconsistent A1 field indices can instead fail earlier. `src/geometry/MeshTopology.cpp:267–285` maps vertices of **each** current loop to one `vertex2cycle` row, but this does not validate duplicated/stale loops. None of the three original logs emits a guard subtype or the boundary-loop count.
4. Future distinct Code + Build scope (not authorized here): make `TriMesh::set_mesh`/`compute_edge_quantities` reset cached `boundaryLoops` transactionally before computing new topology; prove one-call versus two-call idempotence of the exact canonical loop multiset, boundary counts, Euler metadata, tangent-bundle cycle rows, A1 facts, and unchanged mesh geometry. Test equivalent reinitialization, changed valid topology, and invalid repeated update, retaining fail-closed geometry and no stale records. Capture row-157/163/313 **actual** rejection-stage diagnostics before claiming the repair fixes each and do not disable the duplicate-source-boundary guard. Independent negative: deliberately supply duplicate canonical source cycle facts at the consumed A1 seam and require a typed rejection. No synthetic success and no regression tracker promotion.


##### P01: four unconditional reachability probes split by *observed stage*, not assumed product defect (2026-10-30)

The source at `tests/FieldAlignedCurveNetworkTests.cpp:10491–10507,16388–16392` always executes `FAIL() << report` after observation. Independent exact `raw/182,191,196,197.log` checks establish two materially different *actual* pipeline states beneath that forced failure. No row proves a new accepted-green regression.

- **Sphere 182 and 196:** Both call `observe_cp4c_witness("sphere_prescribed",...)`. The first log adds the `m3Cp4c2X2;` report prefix; the second checks `assert_cp4c_sphere_preconditions` and does not fail there. In both the observed pipeline publishes source topology, A3 atlas, and a field network (**24 traces / 56 events**) but **no** global plan; the cut graph rejects at `CellularityNotEstablished / RotationSystemInconsistent / TraceEventPositionInvalid`, specifically trace 2/event 30 with `NoCarrierMatch` and `SourceEdgeUnavailable`. This coincides with the separately tracked P09 192/344 prescribed-sphere event-placement failure, but independent effect/causal ownership still needs proof. Do **not** call the sphere ready, count these as two distinct producer regressions, or remove two distinct test identities without explicit coverage adjudication.
- **Mechanical 191:** The source atlas/network, surface cut graph, and **global topology plan** all exist with **six** regions; log records `furthestStage=global-topology-plan`, then `pipelineFailureStage=tracing`. An unconditional `FAIL()` cannot establish a global-topology-plan defect or a successful end-to-end trace.
- **Torus 197:** Source atlas/network, surface cut graph and global topology plan exist, with **four** regions, and report `discTopologyEstablished=true` and `fieldRegularity=true` for the plan regions; the later pipeline reports tracing `NotProductionReady`. The same log reports network traces/events **zero**, but that aggregate must not be mistaken for validated final quad cells. This is not evidence that the global plan is absent or that the full pipeline is successful.

**Falsifiable future CB split, preserving all four:** Replace unconditional failures with stage-specific assertions that reject missing source/A3/network authority and, on 191/197, assert a **nonvacuous typed global plan** with real positive region certificates; keep a separate explicit *end-to-end positive* requirement that fails on genuine tracing incompleteness instead of dropping the obligation. For 182/196, preserve the independently traced 24/56 baseline only as a provenance diagnostic and require a true source-carrier-positionable trace event and successful certified graph before expecting a sphere topology plan; add a forged carrier/event negative that still rejects with exact typed reason. Clearly separate the `m3Cp4c2X2` scope probe from the sphere precondition probe so one does not silently replace the other's independent guarantees. For all four, test one deliberately missing upstream stage and one malformed owner/certificate to falsify a vacuous "has stage" check. A retirement is possible **only** with separately proved replacement coverage; today **zero retirements**. None of these changes are authorized in this DEFN itself.

##### P02a: four A3 singularity-incidence failures (rows 24, 37, 45, 46)

All four raw logs expose the same `FieldTransportAtlas.partition summary singularity=0 sourceVertex=0 topologyRegion=0 incidences=2 classes=2 expectedClasses=3`. Their common `attach_source_authority` helper in `tests/FlowRepStrandsPhase15Tests.cpp:64–87` builds `TriMesh`, finalizes the face cross field, and calls `FieldTransportAtlas::make`. It raises `FlowRep test A3 atlas unavailable` if the build result rejects. In `src/authority/FieldTransportAtlas.cpp:600–760`, each incident fan/branch attachment becomes an incidence; adjacency matching partitions them; a different count from expected rejects with `FieldAtlasBuildErrorCode::SingularityPortClassCountMismatch`. This is an **observed atlas precondition failure**; the logs do *not* demonstrate whether the synthetic cross-field singularity is inconsistent or the builder partitions it incorrectly. The test topology, transported branch pairing, expected valence and generated port attachments must be independently reconciled before changing code. The original P02 `O2-legacy-candidate` label is not a proven cause.

**Corrective definition:** one focused A3 source-field/fixture-versus-builder adjudication, preserving exact class-count failure for invalid input and a meaningful success oracle for valid prescribed singularities; add a standalone falsifier that would reject an incorrect 2-versus-3 partition. Do not inject three synthetic ports or bypass atlas checks merely to advance FlowRep tests.

##### P02a focused independent incidence census (2026-10-30; no native execution)

Re-inspection of all four immutable raw logs (`raw/24.log`, `raw/37.log`, `raw/45.log`, `raw/46.log`) and `src/authority/FieldTransportAtlas.cpp:570–762` narrows the *first* defect further than the earlier class-count summary. Every run prints exactly **two selected attachments**, both `branch=0`, at fan indices 0 and 1, from faces `(0,1,2)` and `(0,1,3)`, respectively. **Fan index 2 has no selected attachment.** Printed classes are `0` and `1` and the class count equals the attachment count: **there is no observed union of attachments into an incorrect common class**. The radial adjacency signed lifts are `+1,+1,-3` over edges `(0,1),(0,3),(0,2)` (the last is congruent to `+1` modulo 4); despite these adjacency records, no class merge occurs in this witness because no matching selected neighbor incidence exists. The checked builder rejects `2` singleton classes against expected `4 - indexNumerator = 3`. Do not label this a class-union/over-merging defect or suggest splitting existing classes to manufacture a third.

The common fixture `tetrahedral_singularity_fixture()` (`tests/FlowRepStrandsPhase15Tests.cpp:227–264`) synthesizes an ordinary per-face raw field with `x` along each face's first edge, derives singularity facts via `finalize_surface_cell_raw_cross_field`, then adds three *manual downstream separatrix records* with expected valence 3 only **after** `attach_source_authority` has attempted the atlas build. These later separatrix records cannot supply or independently certify a missing A3 outgoing incidence. A3 selects incidences through `direction_in_vertex_sector(...)` and the reciprocal requirement that the selected direction's `outgoingCarriers` includes the fan's opposite edge; therefore the first missing-certificate question is **why fan 2 has zero eligible sector/outgoing-carrier branch pairings for this raw-field fixture**, not why A3 unioned three incidences into two. The immutable logs print neither rejected per-branch sector tests nor exact pairing flow, so whether this is a faulty synthetic field, an exact sector/flow predicate defect, or a mismatch between normalized source singularity fact and raw arrows is *not proved*.

**Minimum corrective CB definition and independent falsifiers (future only):** (1) keep the original raw tetrahedral fixture and preserve a typed fail-closed A3 test asserting the observed `SingularityPortClassCountMismatch` if it genuinely has only two valid outgoing source incidences; (2) independently construct an authentic three-port **source-field** positive (not by inserting downstream separatrices or fabricated attachments), prove the three distinct source fan/branch/carrier pairs and compatible radial transports *before* FlowRep, then require `FieldTransportAtlas::make` to publish exactly three typed attachments/classes; (3) instrument a focused diagnostic to report each rejected fan-2 branch's sector and outgoing-opposite-edge predicate, and independently check exact branch directions against the geometric wedge; (4) add a deliberately missing/incorrect third-port negative and a face-order/branch-label metamorphic control preserving source-field semantics. If a legitimate three-port field is rejected, locate and repair the responsible **producer** predicate with a small isolated patch; if not, repair the test fixture and preserve all four original downstream FlowRep assertions. Do not weaken A3 class-count enforcement, no test retirement, no acceptance claim without an authorized future CB/TB.

##### P02b: unsupported-sheet atlas preflight (row 303)

`tests/SurfaceCellsPhase10Tests.cpp:4030–4070` constructs two component/sheet labels, finalizes an unmodified per-face raw field, builds `SourceTopologyRegions`, then calls `FieldTransportAtlas::make` before invoking `build_surface_cell_network`. The test itself throws `unsupported-sheet source A3 unavailable` on failure. Its call sequence `const auto forward = build(false); const auto reverse = build(true);` means the uncaught forward throw aborts the entire test **before the reverse/winding variant is even constructed**; its later loop over forward/reverse contains all unsupported-sheet phase-front assertions and is also unexecuted. The log does *not* report an atlas error code; it proves neither variant reached the phase-front consumer, and it provides no evidence about the reversed variant. This is an independently proven *test-harness control-flow noncoverage*, separate from unknown A3 rejection cause, not proof of an O2 legacy call. Require a typed `FieldAtlasBuildError` from both independently attempted variants and a valid source-bound unsupported-sheet negative actually reaching phase-front. Keep each orientation non-vacuous, sheet separation, and fail-closed semantics.

##### P02b row303: forward exception suppresses the entire reverse-orientation witness (2026-10-30; source-only)

`tests/SurfaceCellsPhase10Tests.cpp:3984–4086` declares `build(bool reverseFaces)` for a disconnected two-triangle planar disk plus a four-face closed tetrahedron at height 3. It constructs source component/sheet labels 0/0 and 1/1, constructs original source `FieldTransportAtlas::make`, and deliberately throws `std::runtime_error("unsupported-sheet source A3 unavailable")` when the atlas is rejected. The test body then uses the **sequential unguarded** statements `const auto forward = build(false); const auto reverse = build(true);` followed by a loop over both results asserting `UnsupportedSourceSheetTopology`, no partial phase-front product, and typed component/sheet labels on the error face. Because immutable `raw/303.log` reports the exact deliberately thrown A3 message, execution exits at `build(false)` and **cannot reach either `build(true)` or any of the phase-front assertions**. Therefore this RED is not two witnessed orientation failures or a rejected source sheet; reverse orientation is unobserved. The raw failure still does not expose `FieldAtlasBuildError{code,site,...}`, so it cannot distinguish fixture incompatibility from an A3 producer defect.

**Bounded future CB, independently falsifiable:** Preserve the original geometry, source components/sheets, and clockwise/counterclockwise permutation as separate named controls. Execute and record each orientation independently even if the other fails A3, and capture the typed A3 result with error code/site/source face/vertex/region before considering a fixture revision. Construct genuine certified A2/A3 authority on each valid-expected input (or a separately legitimate source fixture, with a retained typed negative for invalid original atlas), then assert the **intended consumed** `UnsupportedSourceSheetTopology` on each variant with no partial authority and a rejection face whose component/sheet are 1/1. Add a supported-sheet positive and a forged/incorrect-sheet negative, and assert that winding reversal does not change semantic rejection ownership when source identities are correctly rebased. Never catch the A3 error and pass the phase-front test vacuously; never disable atlas preflight. No source/test changes or runtime execution in this DEFN.

##### P03: three earlier A1 boundary-cycle failures (rows 157, 163, 313)

`src/fields/CrossField.cpp:58–112,205–211` raises `Cross-field finalization could not publish source-boundary cycle authority` if `populate_source_boundary_cycle_facts` returns false. The function requires a PC face tangent bundle and matching cycle-row dimensions, nonempty canonical boundary loops with matching cardinality, valid `local2Cycle` row indices, and **one identical cycle row for all vertices of each source boundary loop**, plus valid edge IDs/unique canonical loops. The individual logs contain only the aggregate exception, so the precise failed branch is *not* established. Rows 157 and 163 call `remesh_from_mesh` on `make_grid_mesh(2)` in `tests/BoundedMeshPreconditionerTests.cpp:213–229,248–268`; row 313 calls `remesh_from_mesh` on a two-triangle square in `tests/SurfaceCellsPhase10Tests.cpp:1055–1080`. Their remeshing and validator claims were not reached. Do not assign these to O2 or a later A3 producer. An exact negative control must still reject malformed boundary cycles, while a valid disk source must publish genuine cycle facts. **Candidate common cause:** A1 cycle publication/fixture setup; branch-specific proof is still missing.

##### P11 rows 223 and 225 — verified first-stage witness defects (2026-10-30, runtime-free)

**223 — artificial hard edge invalidates upstream coverage before the alleged A3-path negative.** The immutable `raw/223.log` fails only on the test's request for a populated `sourceAuthorityDetail` (line 10350), although a typed `InvalidSourceAuthority` error exists; it does **not** print the producer's `sourceAuthoritySite`. In `tests/SurfaceCellTransitionQuotientTests.cpp:10337–10353`, a genuine non-hard A2b contact spoke is inserted into `blockedHardEdges`, but the test passes *unchanged* `front.hardRailTerminalContacts()`, `front.hardRailOpenChains()`, and `front.hardRailClosedChains()` to the checked factory. `SurfacePhaseFrontProduct::make` checks `hard_rail_open_chains_valid` first (`src/geometry/SurfaceCellTracing.cpp:8703–8710`) and rejects if the union of authoritative open/closed chain edges differs from `hardFeatureEdges` (`:8712–8725`), with `sourceAuthoritySite="open-rail-chain"` or `"open-rail-cover"` and **no** `sourceAuthorityDetail`. The new spoke is not in either unchanged rail-chain cover, so the test cannot legitimately assert a later `MissingTerminalA3Path`. Which of the two prior guards fires is **not recorded** in the raw log; do not claim a specific one. The production behavior proven is a fail-closed upstream rail-coverage barrier, not proof that its A3 path guard is correct.

**Falsifiable corrective scope for 223:** preserve an actual source-produced A3 atlas and valid, independently complete source-rail cover while damaging *only the authorized A3 path* needed by a chosen nonempty terminal route; or, if changing the barrier graph is itself the intended negative, assert the earlier `open-rail-chain`/`open-rail-cover` typed source site and retain a separate genuine missing-A3-path case. Before asserting `MissingTerminalA3Path`, independently check all preceding rail-coverage and contact contracts on the mutated input. Use a positive unchanged baseline, a negative with an actually missing unique A3 route, and another with only invented hard-edge cover. Do not bypass cover validation, reclassify invalid authority as accepted, or reduce the 85-case gate.

**225 — `terminalVertex` is not universal for a hard-rail route endpoint.** The immutable `raw/225.log` fails its first `ASSERT_TRUE(endpoint.terminalVertex.has_value())` at test line 9932; no A3-path/transport mismatch is independently observed. The test loops over **all** route endpoints whenever the route's rail appears in `hardRailTerminalContacts`, without first checking endpoint class. Yet the normative certificate (`include/directional/geometry/SurfaceCellTracing.h:1495–1507`) explicitly offers mutually exclusive `terminalVertex` and `railVertex`; `src/geometry/SurfaceCellTracing.cpp:19764–19794` also constructs a legitimate *nonvertex interior carrier* with **both fields absent** and empty contact paths when the field-determined rail-front point is coincident and source-certified. The checked factory explicitly validates that interior-point variant without requiring a terminal vertex (`:8970–9018`). Thus the test's unconditional assertion conflicts with allowed producer output. The raw log does not reveal whether the first offending endpoint was an interior carrier point or a `railVertex` junction, so do **not** assign it to one of those two subtypes without an endpoint-class dump.

**Falsifiable corrective scope for 225:** partition independently produced endpoints into terminal/source-vertex, rail-interior-vertex, and carrier-interior-point cases; for true terminals, require source-owned terminal contact, exact vertex and nonhard A3 side paths; for rail-interior vertices, require correct open-chain interior membership and nonterminal A3 star paths; for interior carrier points, require exact same embedded carrier, empty paths and direct attachments as factory contract requires. Require at least one *actual* nonempty produced terminal A3 side path and one actual nonterminal endpoint to prevent vacuity. Preserve the original genuine transport and source-vertex checks for terminal endpoints and fail-closed negatives for forged endpoint classes. No output acceptance or source-guard weakening is authorized.

**Status effect:** two previously broad P11 regression candidates are independently proven upstream witness/oracle defects, leaving only rows 265 and 331 as generic P11 regression candidates. Six P11 failures and **85 total** non-PASS observations remain; no test was executed or edited, no retirement is authorized, and the 916-case proposal remains non-executable. These are definitions for later independent CB work, **not** proof that the original producer obligations pass.

##### P11 row 265 — invalid raw-A3-versus-gauge-canonical branch equality (2026-10-30, runtime-free)

`raw/265.log` shows the producer fixture's phase front is **Produced** and its hard-barrier/normal-adjacency checks proceed, but at `tests/SurfaceCellsPhase10Tests.cpp:7651–7653` the test compares the `FieldBranchTopology::transports()` `forward`/`forwardLift` directly to `fixture.atlas->transport(...)->transport/signedLift` for ordinary links. It repeatedly expects canonical quarter-turns 1 or 3 while raw A3 returns 0. The test *does* orient each value to the same directed face order, but **omits face-gauge conversion**. The immutable A3 producer explicitly publishes two different authorities: `FieldTransportAtlas::make` writes `FieldTransportAdjacency` from raw matching `CrossFieldEdgeTransition::matching` at `src/authority/FieldTransportAtlas.cpp:2018–2061`, whereas `build_branch_transports` (`:349–379`) publishes its canonical nested Z4 lift as `rawForwardLift + rawGauge[firstRow] - rawGauge[secondRow]`, or its negative under topology-key orientation, reduced modulo 4. `rawGaugeByRow` comes from each source-produced built face frame (`:1935–1950`). Equality between these two representations is required **only when the oriented gauge difference vanishes modulo 4**, which this test does not establish.

**Disposition:** the unadjusted cross-representation expectation is a stale test oracle, **not** proof that A3 failed to preserve ordinary adjacency or that the canonical branch publisher is correct. Future CB must compare each raw atlas directed value independently against the source-produced raw matching under row orientation, then compare branch value against an independently calculated topology-key-oriented *gauge-compensated* expectation from input face arms; retain reciprocal-inverse, sign/effort, topology-key permutation, hard-barrier absence from traversable adjacency, exact face/component/sheet authority, and a deliberately nonzero-gauge witness that falsifies direct equality. Keep separate negative controls for incorrect gauge compensation, dropped ordinary links, incorrect directed inversion, and hard barrier accidentally made traversable. No source-side adjustment or relaxation of A3 source validation is authorized solely by this RED.

**Ledger effect:** row 265 leaves the broad P11 regression-candidate bucket; only row 331 remains an unresolved P11 candidate. All six P11 REDs and all 85 non-PASS cases remain in TB51 planning. No native test was run; no retirement or production acceptance is claimed.

##### P11 row 331 — route-only seam equivalence oracle ignores isolation evidence type (2026-10-30, runtime-free)

The `split_isolation_fixture()` is `make_square_fixture(true, false)` (`tests/SurfaceCellTransitionQuotientTests.cpp:841–844`), with two faces on different local isolation sheets `{0,1}`. Its materialization succeeds in immutable `raw/331.log`; all earlier source-point, sorted-occurrence, typed region/sheet/chart, and sorted-equivalence assertions emit **no failures**. Only `foundSeamEquivalence` is false at line 9675. The test sets that flag **exclusively** when `!equivalence.route.empty()` (`:9648–9676`), regardless of equivalence kind.

That existential predicate is not equivalent to isolation seam completeness. The immutable product's typed `PureQuadEquivalenceProvenance` distinguishes `HardRail`, `PeriodicHolonomy`, and `CornerWedgeIsolation` (`include/directional/geometry/PureQuadCompletion.h:187–193,258–270`). `src/pipeline/RemeshPipeline.cpp:6057–6079` builds an authoritative `CornerWedgeIsolation` equivalence from `occurrence.cornerWedgeIsolation`, publishes `isolationTransitions` and sorted `isolationSeams`, and **does not assign a CanonicalRoute**. Separate tests at `tests/SurfaceCellTransitionQuotientTests.cpp:4720–4800` already exercise these typed corner-wedge isolation transitions, while `SurfaceCellIsolationSeamCertificateAuthority.ReciprocalIsolationSeamCertificateMaterializes` (`:7709–7728`) independently checks the actual producer's seam certificate. Therefore a correct corner-wedge isolation can have an *empty* route; the current route-only assertion cannot certify its own claimed isolation-seam authority. The raw log does not expose the produced equivalence kinds or the exact `isolationTransitions`, so **the positive seam lineage remains unverified**, not automatically accepted.

**Corrective CB definition:** assert at least one actual `CornerWedgeIsolation` equivalence from the split-isolation fixture and independently match its region, seam topology key, ordered from/to sheets and reciprocal source certificate to the source-produced isolation seam; retain all original typed lineage/sorting checks, and require `route` only for the specific HardRail/Periodic equivalence kinds whose contract owns a route. Add a negative deleting or corrupting the published seam transition, which must fail the source-authoritative materializer or verifier, and a face-row permutation control. Ensure a fixture with no seam correctly carries no corner-wedge isolation rather than passing vacuously. Do not fabricate a route to satisfy the old existential assertion, suppress typed isolation evidence, or promote this RED to accepted-green coverage without separate execution.

**P11 review consequence:** all six observations now have evidence-based *first-stage oracle/preflight categories* (261,223,225,265,324,331); **none** currently establishes a new accepted-green regression. This is not a claim that P11 source behavior is correct: in particular the nonempty real A3 terminal paths, gauge-covariant branch transports and isolation seam lineage still need the independent corrected oracles defined above. All six rows remain slated for TB51; total census 85, retirements 0, stable regression 66/17/49 debt1 unchanged.

##### P11 row 324: production correctly rejects a forged boundary route, but the expected error is stale

`tests/SurfaceCellTransitionQuotientTests.cpp:7686–7710` replaces a true source-boundary route with a synthetic interior `TransitionStep` and asserts failure code `InvalidSourceBoundaryAuthority`. The immutable log shows `result.success=false` (its `EXPECT_FALSE` passes) and `result.failure="FalseAuthoritativeSourceBoundary"`. `src/pipeline/RemeshPipeline.cpp:3652–3673` uses `InvalidSourceBoundaryAuthority` for malformed boundary edge *structure*, but after structural validation uses `FalseAuthoritativeSourceBoundary` when a genuine boundary route contains a non-boundary/interior transition or false edge incidence. Another independent test (`tests/SurfaceCellTransitionQuotientTests.cpp:9715–9740`) already expects `FalseAuthoritativeSourceBoundary` for forged boundary ownership. Thus **source-boundary false authority remains rejected**; only the expectation of the coarser failure label differs. Review should re-specify an exact semantic negative oracle retaining `EXPECT_FALSE` and the *correct* more-specific typed reason. No production relaxation and no retirement warranted.

##### P14 rows 373 and 401 — source-boundary precondition absent in positive validation fixtures (2026-10-30; source-only proof)

- **Original observations:** immutable TB50C-R2 `raw/373.log` and `raw/401.log` each report only `accepted == false`; neither prints `strictValidationIssues`. Thus the logs do **not** prove that missing boundary authority is the unique or directly reported runtime failure. Both retain RED; no accepted-green regression inferred.
- **Case 373:** `tests/SurfaceMeshOptimizerPhase19Tests.cpp:15–49` builds one planar source square from triangles `(0,1,2)` and `(0,2,3)` with genuine `SourceTopologyRegions`, but `constraints_for_plane` never fills `authoritativeBoundaryEdges`, `authoritativeBoundaryLoop` or `authoritativeBoundaryLoops`. `FinalValidationPassesSectionFiveFixture` (`:254–270`) passes these unchanged through optimizer and `validate_final_surface_mesh`. The source square has one boundary loop `(0,1,2,3)`.
- **Case 401:** `tests/SurfaceMeshOptimizerPhase21Tests.cpp:32–71` defines `make_constraints` which likewise binds genuine source topology but never fills any boundary-loop/edge authority. `PipelineStyleBoundarySingularitiesAcceptCompletedCloseSheetQuads` (`:~303–349`) overwrites source authority to two disconnected close planar sheets, with two disjoint square boundary loops on vertices `(0,1,2,3)` and `(4,5,6,7)`, and runs `validate_final_surface_mesh` without publishing either. It does independently assert the eight singularity valence targets; that passing setup does not supply boundary authority.
- **Deterministic production rejection:** `src/geometry/SurfaceMeshOptimizer.cpp:1769–1798` always sets `validatorOptions.requireBoundaryAuthority=true` and forwards exactly the fixture's empty boundary sets. In `src/validation/SourceAuthoritativeMeshValidator.cpp:1029–1059`, source boundary loops force `topologyOptions.requireAuthoritativeBoundary=true`. At `:1070–1099`, an empty expected boundary yields `orderedBoundaryCyclesPassed=false` and an explicit `MeshValidationFailureCode::MissingBoundaryAuthority` for any source with a boundary loop. `SurfaceMeshOptimizer.cpp:2770–2773,2848–2850` conjuncts strict validator acceptance into the final report, so the missing boundary is independently sufficient to make `report.accepted=false` in **both cases**, regardless of other quality or provenance problems. This is a proved *fixture prerequisite*, not proof that downstream optimizer or close-sheet behavior will pass once repaired.
- **Minimal future CB (not authorized during DEFN):** In the case-373 fixture publish the exact one-loop source boundary; in case 401 publish **two separate** correctly oriented source-boundary loops, rather than one fused loop or heuristic output-derived authority. Feed only genuine A2 source topology and preserve strict `requireBoundaryAuthority=true`, the eight typed singularity-valence assertions for 401, quality checks, provenance checks, and both `report.accepted` positives. Negative falsifiers: delete one loop, misorder a vertex, or include a foreign-sheet edge and require typed `MissingBoundaryAuthority`/`ChangedBoundaryLoop` or `WrongBoundaryEdge` as appropriate; positive controls require `strictValidationIssues` empty, `orderedBoundaryCyclesPassed=true`, actual source-loop matches, and full final acceptance. Record any **remaining** typed failure after publication instead of widening tolerances or weakening guards.
- Keep these two inputs together only for the **shared missing-boundary preflight**. Do not assume identical downstream causes (case 401 also exercises distinct source-sheet and singularity semantics); preserve case-specific independent witnesses. No test retired and no executable TB51 gate released.

##### P14 row 399: fail-closed behavior passes, metric sentinel remains disputed

`tests/SurfaceMeshOptimizerPhase21Tests.cpp:414–444` deliberately gives one output quad alternating sheet IDs and expects both directional distance maxima infinite and final `report.accepted=false`. The raw log reports only `std::isinf(report.quadToSourceMax)` failing: `sourceToOutputMax` and `accepted=false` expectations pass. `src/geometry/SurfaceMeshOptimizer.cpp:2685–2705` computes both maxima from independently collected directional sample errors; `:2848–2865` gates acceptance on strict validation and distance thresholds. The log therefore **does not establish an erroneous acceptance of mixed-sheet output**, but does expose an unresolved direction-specific metric/sentinel contract. Before changing the oracle or producer, determine whether invalid output provenance is required to force both distance metrics to infinity, or whether finite one-way geometric error is valid with rejection certified separately. Preserve the negative acceptance guard and independently validate cross-sheet restrictions.

##### Disposition effect and non-vacuity requirements

- Proven stale expected failure detail: **row 324**. Proven stale ignored-input negative: **row 317** (previous section). These demand corrected meaningful oracles rather than test removal.
- Proven first-stage invalid fixture (without downstream assessment): **rows 22,28,33,34,38,39,43,354**. Proven unconditional `FAIL()` probes: **182,191,196,197**. The current review does **not** authorize retiring any.
- Early-stage failure/typed-cause still open: **24,37,45,46,303,157,163,313**. These are distinct from accepted-green regressions and O2. Disposition may change only after source and independent witness construction establishes the cause.
- Confirmed fail-closed, unresolved metric requirement: **row 399**. No numerical tolerance change or validator relaxation is authorized.
- At most **0 retirements** have earned an authoritative disposition; all-retained 916-case cardinality remains *a planning number only*. Native run, CB patch, new selector, CP3 promotion and actual TB51 freeze remain prohibited until the full 85-case review completes.

##### P14 rows 375 and 385: shared missing source-component/sheet labels in BVH projection

The two independent `SurfaceMeshOptimizerPhase19` logs record valid projected source faces, but each new projected point has `component=-1` and `sheet=-1` rather than authoritative component 0 and sheet 2 (case 375: fixed feature re-projection; case 385: normal source-triangle projection). Their shared `constraints_for_source_triangles()` in `tests/SurfaceMeshOptimizerPhase19Tests.cpp:88–109` supplies an independently constructed `SourceTopologyRegions` with face-component labels `{0,0}` and sheet labels `{2,2}`. There is no absent A2 input in these fixtures.

The production path is provable from its definitions:

- `src/geometry/SurfaceMeshOptimizer.cpp:126–139` delegates `nearest_source_point` to `SourceProjectionCache::project`.
- `include/directional/geometry/SurfaceMeshOptimizer.h:371–463` constructs a BVH and returns `bvh->project(point, options)` from *both* cache projections. Neither overload fills `SurfaceProjectionOptions::faceComponents` / `faceSheets`, nor annotates the returned `SurfacePoint` from `constraints.sourceAuthority` after selecting a face. The allowed-face mask may restrict candidate faces but does not populate the point's component/sheet identity.
- `include/directional/geometry/SurfacePoint.h:25–44,262–278` defaults `SurfacePoint.component` and `.sheet` to `-1` and assigns them during BVH projection **only** when the corresponding `SurfaceProjectionOptions` arrays are supplied. Thus the missing labels in both tests are explained by the shared wrapper's omission, not by test-generated values.
- `src/geometry/SurfaceMeshOptimizer.cpp:765–869` forwards these unlabeled projection results into `projectedProvenance` (fixed/feature/free branches). The defect therefore also risks weakening source-bound sheet comparisons and should be fixed at the shared projection boundary, not with per-test assignments or fallback `0` labels.

**Corrective CB definition — one semantic change group, no executable work in DEFN:** In `SourceProjectionCache::project` for **both** overloads, derive component and sheet for the returned valid `SurfacePoint.face` from the exact `SourceTopologyRegions` bound to `constraints.sourceFaces`, after validating `matches_source_faces` and the face-index domain. The owning implementation may share a small internal labeling helper, or pass cache-owned arrays into `SurfaceProjectionOptions`; never infer labels from nearest world-space sheet, return a default label, synthesize authority, or set labels on invalid results. Ensure all projection entry routes, including feature-fixed refreshes and exact-face masks, use the same authoritative assignment and fail closed on absent/inconsistent authority. Preserve original assertions in rows 375 and 385 and cover negative controls where multiple disconnected coincident/close sheets share coordinates. Re-run the frozen 2-case scope in a later TB, with new source-authoritative invalid-A2 guards; compile/runtime prohibited in this Review turn. Other P14 failures remain separate unless independent evidence proves the same source defect.

#### Further source-grounded adjudication: typed chart and ownership-registry preconditions (2026-10-30)

The checks below inspect the independently verified product source snapshot and the frozen raw TB50C-R2 individual logs. No C++ code, test, fixture, selector, or executable changed. These observations **refine three independent causal workstreams**; a shared error string is not proof of a shared implementation cause.

##### P12 row 296 — stale generic-validator negative oracle (proved)

- The test `SurfaceCellsPhase10.MeshValidatorUsesComponentSheetInsteadOfExactFaceEquality` (`tests/SurfaceCellsPhase10Tests.cpp:865–891`) creates an output quad with a fifth vertex geometrically inside edge (0,1). Its edge endpoints have `SurfacePoint.face=0`, and the fifth vertex has `face=1`; all five points carry raw `component=7`, `sheet=3`. It calls **generic** `MeshValidator::validate_surface_mesh` with `requireVertexProvenanceForGeometry=true` and expects a `GeometricVertexOnUnsplitEdge` rejection. The frozen case-296 log instead shows `accepted=true`, with no such failure code.
- `include/directional/validation/MeshValidator.h:453–473` contains the explicit contract: *generic validation has no typed cross-chart authority*; diagnostic raw component/sheet mirrors do not prove that different source faces share a semantic sheet. `same_source_face` requires `p.face == pa.face && p.face == pb.face`. `validate_geometric_t_junctions` (`:477–541`) skips point-on-edge rejection when this predicate is false. Since the fifth face is 1 and edge endpoints 0, **this generic result follows the documented implementation contract**. This is a **stale test ingress/oracle**, not evidence the trusted source-authoritative cross-chart validator accepts a T-junction.
- Corrective CB must preserve `GeometricTJunctionIgnoresDisconnectedCloseSheet` (same file, about line 817) and same-face T-junction negative; re-author the cross-chart negative using a valid typed `SourceAuthoritativeMeshValidator` / chart witness, with a disjoint-sheet positive control. Raw component/sheet equality alone must **never** be promoted to trusted authority. The resulting test must fail if a cross-face *authoritatively proven* same-sheet unsplit T-junction is admitted. Avoid simply changing this test's `EXPECT_FALSE` to success without replacement coverage. **No producer modification is justified by row 296.**

##### P07 row 52 — split carries alternative-region provenance through authoritative edge (2026-10-30, runtime-free)

The test `AuthoritativeCellScopeOverridesMultiScopeBoundaryDuringSubdivision` (`tests/PatchDescriptorMilestoneETests.cpp:1679–1731`) intentionally adds a `SurfaceArrangementProvenance` record with region **9** to both directed halves of a boundary edge whose owning bounded cell and authoritative halfedge have region **2**. The original immutable `raw/52.log` shows subdivision **Produced**, no first scope failure, and two emitted provenance assertions at test line 1725 with region 9 rather than 2. The producer's preflight in `src/geometry/SurfaceCellFeasibilityRepair.cpp:1019–1047` checks each halfedge's *primary* `source_scope(edge)` against the owning cell but does not check each provenance record. `split_provenance_interval` (`:402–418`) copies the **entire** input provenance vector and only interpolates scalar interval endpoints. Both new directed pieces use it (`:1301–1320`). Later `selectedCompatible` chooses a same-scope provenance to set the *halfedge's* primary scope (`:1450–1500`), but the region-9 alternative remains in the vector. This explains the exact observed mismatch without assuming an unseen producer error or claiming a historically accepted regression.

**Design decision not yet discharged:** the output must not silently reinterpret an authentic different-region lineage claim as region 2. Establish whether all `halfedge.provenance` records are required to have owning-cell scope (then reject the invalid mixed-scope input or represent its foreign claim in a distinct typed multi-scope channel), or whether multi-region lineage is permitted in this vector (then correct the test to assert primary ownership separately and preserve genuine alternate provenance). Do **not** overwrite the region field just to turn the test green, discard source lineage, or relax ownership audits. Future CB must provide (a) a valid region-2 control retaining complete exact lineage; (b) an intentionally mixed-scope test that either rejects with a typed first site or preserves foreign lineage under a separately defined contract; (c) reverse-edge/face-row permutation and exact rollback checks; and (d) a negative that fails if a region-9 record is falsely admitted as region-2 ownership. This is one measured producer/test *contract conflict* in P07; its correct disposition remains Review-owned.

##### P07 row 57 — invalid fixture ownership registry prevents intended duplicate-domain guard (proved initial gate)

- `tests/PatchDescriptorMilestoneETests.cpp:1354–1381` appends `fixture.complex` twice into a fresh `SurfaceCellComplex duplicate`, rewrites cell IDs and halfedge `cell` references, reverses cells, and expects `DuplicateOrientedDomain` with `firstPatch=91`, `secondPatch=401`. The immutable log reports conflict classification **6** (`InvalidDomainIdentity`) versus expected **1** (`DuplicateOrientedDomain`), with `secondPatch=-1`.
- The helper `append_authoritative_component` (`tests/PatchDescriptorMilestoneETests.cpp:330–359`) copies nodes, halfedges, cells, but does **not** copy or reconstruct `sourceOwnershipRegistry`. The newly created `duplicate` therefore lacks the registry records required by its cells' `sourceOwnershipClass` labels. `src/geometry/PatchDescriptor.cpp:602–630` rejects a cell whose ownership class cannot be looked up as `OwnershipRegistryMismatch`, making its domain identity invalid. `derive_patch_descriptors` (`:1890–1911`) checks `!identity.valid` and raises `InvalidDomainIdentity` **before** entering duplicate-domain comparison. Therefore the duplicate-domain contract is **not exercised** in this test. This is a **fixture authority-precondition defect**; do not reclassify the observed early rejection as proof of duplicate-domain regression.
- Corrective CB must build two separately distinguishable, individually **valid** source-bound cells and their exact ownership-registry records, preserving the intentional duplicate oriented-domain claim and proving `audit_surface_cell_domain_identity` passes for each input before comparison. Then assert the exact `DuplicateOrientedDomain` pair. Do not fill missing registry records with arbitrary placeholder IDs or weaken `InvalidDomainIdentity` fail-closed preflight.

##### P07 rows 58 and 66 — post-preparation ownership-registry mismatch (observed, cause unresolved)

- Case 66's test (`tests/PatchDescriptorMilestoneETests.cpp:1110–1142`) starts with `make_authoritative_patch({20,1,1,1,1})`, calls `repair_surface_cell_side_subdivisions` and asserts `is_produced()` and inserted vertices before auditing each repaired cell. Its log reports `ownership-registry-mismatch cell=0 ...` and subsequent active ownership conflict. This is not a mere duplicate-domain fixture initialization case.
- Case 58 (`...:1268–1295`) explicitly verifies two descriptors and one unresolved singular vertex, then calls `complete_surface_cell_complex`. The log shows failure **`SuccessfulSubdivisionDomainIdentity;identityFailure=ownership-registry-mismatch;cell=0`** in place of the intended `UnresolvedSingularityOwnership`, so the singularity rejection path was **not reached**. `src/geometry/PatchDescriptor.cpp:2584–2643` runs the prepared side-subdivision product through `audit_surface_cell_domain_identity` before deriving descriptors; that is the precise early exit. `src/geometry/SurfaceCellFeasibilityRepair.cpp:1059–1060` moves the existing `sourceOwnershipRegistry` into the subdivision transaction, and `:2292–2342` returns the produced complex; code does not establish that the final registry is recomputed for the exact post-split chart identities.
- Classification: **post-preparation ownership-registry mismatch, producer-or-input causal owner not yet proved**. A later CB must trace original valid registry versus side/parity-mutated chart set, source IDs, and before/after hashes for both cases, and only then decide whether registry preservation/reconstruction belongs in the subdivision producer or fixture setup. Maintain fail-closed `InvalidDomainIdentity`, atomic rollback, and independent domain audit; row 58 must additionally prove that its singularity negative can execute after valid preparation. Do **not** merge rows 57/58/66 into one CB merely because they mention ownership registries.

##### Updated disposition accounting

- Newly proved stale/oracle authority: row **296** (generic versus source-authoritative validator). Previously proved row **317** remains separate.
- Newly proved invalid fixture precondition: row **57**. Observed post-preparation registry failure still requiring causal proof: rows **58, 66**.
- No test retirement, accepted selector promotion, stable-regression addition, or TB51 manifest freeze is authorized. The full non-PASS census still contains 85 unique case IDs; existing accepted CP2 491/491 and reviewed TB50 508/508 identities are untouched.

#### P08 full-group preflight adjudication: 13 missing source-authority fixtures (2026-10-30)

This independently establishes a **shared earliest causal defect** for all 13 non-passing simplification cases; it does **not** adjudicate their post-preflight simplifier behavior. Immutable logs show absent expected elements, removable halfedges, candidates or pre-healing topology defects in cases **95, 96, 97, 100, 101, 103, 106, 107, 109, 112, 114, 118, 119**. Exact source inspection explains the common empty input complex:

- `src/geometry/SurfaceArrangement.cpp:1659–1717`, `build_surface_cell_complex` creates an empty `SurfaceCellComplex`, then **immediately returns it** with `SourceTransitionUnavailable` and invalid diagnostics when `options.sourceAuthority == nullptr` or the authority fails `matches_source_faces(faces)`. It does so before generating nodes, halfedges or cells. `make_simplification_elements_from_complex` simply traverses `complex.halfedges` (`src/geometry/SurfaceComplexSimplification.cpp:1843–1861`). Empty halfedges therefore imply no simplification elements or meaningful candidates.
- `tests/SurfaceComplexSimplificationPhase17Tests.cpp:892–908` (95) directly invokes `build_surface_cell_complex(vertices,faces,{arc})` with no fourth `SurfaceArrangementOptions` argument.
- The helper `two_strand_complex()` (`tests/SurfaceComplexSimplificationPhase17Tests.cpp:267–278`) constructs a one-face arrangement with **no** sourceAuthority. Cases **96, 97, 101, 114, 119** invoke this helper, so their candidate/removable-halfedge preconditions are not exercised.
- The helper `oversampled_parallel_complex()` (`:327–344`) likewise constructs its one-face arrangement without sourceAuthority; cases **100, 109, 118** depend on its advertised oversampled candidates and never reach an actual producer output.
- Cases **103, 107, 112** each directly call the same three-argument builder on a single-triangle fixture (`:1164–1181`, `:1227–1247`, `:1356–1378`); row **106** directly calls it on a **disconnected two-triangle** fixture (`:1287–1321`). None passes a typed source-bound authority. That means their `beforeDefect == 0` is an empty-input artifact, **not** proof that topology healing was unnecessary or performed correctly.

**Disposition:** The 13 rows are **invalid setup under the current mandatory source-authority contract**, not 13 individually established product regressions, and not 13 justified retirements. Corrective Code + Build scope may share a fixture-authority constructor but must supply **actual** `build_source_topology_regions(faces, ...)` with face/region/sheet identities consistent with each fixture, bind the resulting `SourceTopologyRegions` to `SurfaceArrangementOptions::sourceAuthority` for the entire synchronous call, and prove each resulting complex has nonempty DCEL and the expected independent topology/protected-support invariants *before* exercising simplification. The disconnected fixture must preserve separate components, and required singularity support must remain protected. Use frozen per-test negative controls to check that missing/mismatched source authority still fails closed; never weaken the arrangement producer preflight or synthesize simplification candidates. The first genuinely valid produced complexes may surface additional downstream failures, so this review has **not** authorized 13 green outcomes.

#### P09a and P10 precise stage audit — 2026-10-30, runtime-free

This rederivation used the verified 2026-10-30 source snapshot from [run 40986100897](https://github.com/akashskypatel/Directional/actions/runs/40986100897), source `9fe12a26133a1fa90b135b499e83b92b8bf120ad`, artifact `12946688157` (`sha256:3cc27449cc5b272aaf87231504837a361d04bbf02dc8f2ea751fd43103812a65`), and immutable TB50C-R2 raw logs in artifact `12941320247`. Snapshot source and archive digests were verified; **no native execution** occurred.

##### P09a, row 175 — independently proven production diagnostic-loss defect

`raw/175.log` contains a single missing-token assertion (`tests/FieldAlignedCurveNetworkTests.cpp:13946`) and prints the complete projected locus: `;sourceVertex=10;sourceFace=9,11,17;traceFirstSegment=1;traceOnePastLastSegment=4;traceSegmentOrientation=Forward;traceSegmentIndex=2;traceSegmentIsFirst=false;traceSourcePort=0;traceBoundCorner=11;traceBoundCornerProvenance=SegmentEntrySupport;traceEntrySupport=Vertex(11);traceExitSupport=Edge(11-17);traceIncomingCarrier=none;traceOutgoingCarrier=9-11;arc=6;trace=3`. Compare the exact 17 expected tokens (`tests/FieldAlignedCurveNetworkTests.cpp:13937–13945`) to the emitted values: **only `singularity=0` is absent**. In the test the producer-side `SurfaceCutGraphError::singularity` is explicitly populated with typed `FieldSingularityId(0)` (`:13909`); `SurfaceCellFailureLocusDiagnostics` has a `singularity` optional (`include/directional/diagnostics/RemeshDiagnostics.h:302`), and the existing report formatter serializes it if set (`tests/FieldAlignedCurveNetworkTests.cpp:4356–4359`). The actual product projection `src/pipeline/RemeshPipeline.cpp:390–556`, `project_surface_cut_graph_failure_locus`, copies the source vertex, edge/face, trace and carriers but **does not assign `locus.singularity` from `error.singularity`**. This is an exact missing-field defect at a live production projection seam, not a stale negative test or unverified topology regression.

**One bounded corrective Code + Build task, separate from P09b:** in `src/pipeline/RemeshPipeline.cpp`, within `project_surface_cut_graph_failure_locus`, copy the optional singularity's typed index into `locus.singularity` without changing the underlying error, acceptance, graph topology, or other emitted locus fields. Add/retain a falsifying positive test that a populated singularity survives into `production_cut_graph_error_locus` and a negative test that absent singularity does **not** produce the tag. Preserve the existing 16 other expected tokens byte-for-byte. A targeted compile-only workflow is required in CB; exact runtime Test + Benchmark belongs to a separate TB turn. **No changes authorized in this DEFN.**

##### P09b, rows 192, 344, 350 — separate, unresolved producer/witness outcomes

These observations are not diagnostic-projection failures. Row 192 reaches source cut-graph and reports `CellularityNotEstablished` / `RotationSystemInconsistent` / `TraceEventPositionInvalid` before the expected prescribed sphere witness. Rows 344 and 350 involve cut-graph ownership/candidate or saturation checks on already constructed typed atlas inputs. Their individual topology/ownership causes require separate source graph, carrier and certifier analysis; do not merge with P09a merely because they share the P09 historical grouping. Avoid accepting synthetic success or altering expected certificates to bypass the product.

##### P10a/P10b — same test family, distinct failed authority stage

Rows **235, 236, 237, 241** each abort on `ASSERT_TRUE(atlasBuild)` in `tests/FieldAlignedCurveNetworkTests.cpp:11646,11710,11985,12132`. Their helpers construct a three-face folded-cone fan (`:195–208`) and a field whose radial matching is altered from the zero-transport base (`:210–247`). `FieldTransportAtlas::make` rejects this fixture before any vertex-star election or hard-carrier transit assertions execute. Their **typed failure code is not logged**, so the actual first guard remains unknown. However the shared fixture is independently shown to violate a necessary A3 cycle-transport equation: a three-face cone with an interior +pi/2 curvature, zero edge effort, and radial matching values {2,2,0} gives local-vertex turning lift +1 modulo 4 against composed quarter-turn 0. This makes an A3 success on the unmodified fixture impossible even if earlier preflight guards were passed; it is **not** evidence that `CycleTransportMismatch` was the first native error. Capture the typed `FieldAtlasBuildError` code/site first, then repair the synthetic *source field* via independently derived matching/effort/singularity or use a legitimately certified A3 fixture, preserving the folded-cone geometry and exact transit oracles. Keep all four RED and keep A3 fail-closed guards. Do not synthesize a matching index or suppress the atlas check.

Row **243** is not the same case: `MinimalExactVertexTransitWitnessPublishesKnownFanState` successfully builds an atlas via `zero_transport_atlas_for_semantic_success`, then calls `resolve_field_vertex_transit` with the **first branch of the first sorted frame** containing center vertex 4, `FaceInterior`. The native result is `VertexTransitSeedUnavailable`, with **no `Evaluated` state**. The preceding `ASSERT_FALSE(error.vertexTransitStates.empty())` does *not fail*, hence the earlier shorthand "empty collection" is **wrong**: at least one non-evaluated diagnostic exists. Static source/geometry audit (details below) establishes a non-admissible chosen arrival direction, while the exact first native guard subtype remains unprinted. Correct the fixture seed while preserving the real A4 transit/oracle and an explicit outside-wedge negative. Keep this separate from four A3 preflight failures.


##### P10a four-folded-cone source-field contradiction (2026-10-30; no native execution)

**Source-only necessary-invariant proof, not a native first-error attribution.** All four tests 235, 236, 237 and 241 call the same `make_three_right_angle_cone_fan()` / `make_folded_cone_vertex_field(...)` before `FieldTransportAtlas::make` (`tests/FieldAlignedCurveNetworkTests.cpp:195–247,11640–11646,11704–11710,11979–11985,12118–12132`). The cone consists of the three oriented faces `(0,1,2),(0,2,3),(0,3,1)` with center vertex 0 and rays along the positive X, Y and Z coordinate axes; each center angle is exactly `pi/2`. Vertex 0 is interior, so its angle-deficit curvature is `2*pi - 3*(pi/2) = +pi/2`. The helper starts from `make_zero_transport_field`: all three source-edge `effort`s remain zero, all `singularCycles/singularIndices` are empty, and it alters only radial `matching`/transition `matching` to 2 on edges `(0,1),(0,2)` and 0 on `(0,3)`. The choice `(rayX,rayY)=(2,1)` or `(1,1)` changes face-0 direction, not this matching/effort invariant.

`FieldTransportAtlas.cpp:2495–2525` computes the local vertex's integer `turningLift = round((sum signed edge effort + 4*curvature)/(2*pi))`, which here is **+1**, and `:2553–2593` requires the composed local cycle quarter-turn to equal `turningLift mod 4`. Every signed occurrence of the radial two-quarter-turn matching equals 2 mod 4, so the cycle transport sums to **0 mod 4** (`2 + 2 + 0 = 4 mod 4`), irrespective of orientation/sign; the required value is **1 mod 4**. The two independent source constraints cannot both hold. Even if the earlier A3 checks passed, its cycle transport would reject; even if matching were fixed, the empty supplied singularity metadata would require a separate audit against nonzero local turning lift at `:2642–2653`. **The raw four logs report only `atlasBuild=false`; they do not establish which earlier guard actually rejected.** This proves an invalid/internally inconsistent *success fixture* under the current A3 contract, not the final causal first-guard attribution and not a production-defect exoneration.

**Future bounded CB:** First print/assert the typed `FieldAtlasBuildError` `{code,site,sourceEdge,sourceVertex,topologyRegion}` from the actual unmodified producer on each of the four test variants; retain raw negative rejection evidence. Then replace the hand-authored incongruent field with independently certified source-valid A3 matching, signed effort, singularity metadata and three-face branch frames (or an independent established fixture) without changing the three-right-angle cone geometry, vertex-star owner/orientation oracle, exact fallback/half-open convention, or hard-carrier cut behavior. Require an atlas-valid *positive*, the original mismatch as a typed *negative*, a genuinely wrong singularity metadata negative, and source-frame/face-order metamorphic independence. Do not coerce zero efforts or a wrong matching into acceptance; do not conflate an admissible A3 source with a successful vertex-transit test. The correct typed first reject and subsequent valid-fixture transit behavior remain unknown until CB/TB verification.

##### P10b case 243: source-proven inadmissible first-frame arrival (2026-10-30, DEFN only)

The earlier statement that `error.vertexTransitStates` is empty is incorrect: `tests/FieldAlignedCurveNetworkTests.cpp:11620–11631` explicitly executes `ASSERT_FALSE(error.vertexTransitStates.empty())` before searching for an `Evaluated` outcome. The immutable `raw/243.log` fails on the rejected error code and the search result, *not* on that nonempty assertion. Thus at least one diagnostic state exists but none reports `Evaluated`; native evidence does not print its `outcome`, `seed`, `face` or `branch`, and does not independently identify the first guard site.

The fixture chooses `frameIt->branches.front().branch` for `FaceInterior` without establishing that its **reversed** branch direction points into the corner of the source face at center vertex 4. `make_four_triangle_fan()` has vertices 0=(-1,-1), 1=(1,-1), center 4=(0,0), with first sorted face `(0,1,4)` (`tests/FieldAlignedCurveNetworkTests.cpp:88–101`). The atlas sorts frames by `sourceFace` (`src/authority/FieldTransportAtlas.cpp:1950–1961`), canonically gauges the first branch to the face edge `(0→1)` direction +X (`:233–313`), and `make_zero_transport_field` supplies raw +X/+Y for every face (`tests/...:172–194`). Therefore branch 0 in that first frame points +X; `resolve_field_vertex_transit` reverses it to arrival -X (`src/geometry/SurfaceCellTracing.cpp:1478–1488`). At center 4 the triangular face's closed interior wedge spans rays to vertices 0 and 1, both with negative Y, while -X has Y=0: it is **outside** that wedge. The implementation checks `direction_in_closed_vertex_wedge` and records `SeedDirectionOutsideClosedWedge` before any transit-state evaluation (`:1499–1506`). This is a **source-provable invalid positive seed fixture**, *consistent* with the native `VertexTransitSeedUnavailable` and missing `Evaluated`; it is not a native printed subtype or a proof that every later transit obligation passes with a valid seed.

**One bounded future CB:** choose an independently source-inward arrival ray and matching typed canonical branch/face using a source-produced atlas, assert barycentric seed direction and closed-wedge eligibility *before* transit, then preserve original requirement of a transported, source-owned, nonvacuous next-face/vertex-star decision (or a legitimately evaluated typed negative). Include distinct negatives with the original first-branch/outside-wedge arrival and with an absent/forged frame/branch, requiring their exact typed seed outcomes and nonempty diagnostics. Do not weaken `direction_in_closed_vertex_wedge`, turn `VertexTransitSeedUnavailable` into success, or count the current witness as production-regression proof. The four P10a atlas failures remain separately untyped and unresolved.

##### Unchanged authority

All five P10 and four P09 rows retain their original identities and native results; no test retirement, accepted-green loss, stable regression, selector change, or TB51 execution approval is established. The 916-row proposed manifest remains a non-authoritative plan, with 508 unchanged candidate rows and 408 proposed observations. Accepted CP2 491/491, reviewed TB50 508/508, stable 66/17/49 and debt 1 remain unchanged.


#### Further independent source audit — A2b preflight and ignored ingress (2026-10-30; runtime-free)

Source authority: independently verified exact snapshot for `9fe12a26133a1fa90b135b499e83b92b8bf120ad`, artifact `12946688157`, outer SHA-256 `3cc27449cc5b272aaf87231504837a361d04bbf02dc8f2ea751fd43103812a65`, paired with immutable TB50C-R2 per-case raw logs. This remains a review-only correction to the working classification, **not** a completed causal census or Code + Build authorization.

##### P12 row 279 — proven stale negative at ignored CrossFieldResult ingress

`SurfaceCellsPhase10.CurvedBoundedDiskInvalidReciprocalTransportFailsClosed` (`tests/SurfaceCellsPhase10Tests.cpp:3647–3675`) calls `make_curved_disk_fixture()`, independently finalizes a `CrossFieldResult`, then changes one `crossField.edgeTransitions` matching value and calls `build_surface_cell_network(..., crossField, ..., fixture.options)`. But `make_curved_disk_fixture()` calls `bind_curved_disk_atlas(fixture)` (`tests/SurfaceCellsPhase10Tests.cpp:2630,2664–2678`), which constructs **a separate authoritative `FieldTransportAtlas` from untampered curved-disk raw data** and populates `fixture.options.fieldTransportAtlas`. The production overload (`src/geometry/SurfaceCellTracing.cpp:21221–21239`) deliberately passes null raw matching/effort/transition pointers whenever `options.fieldTransportAtlas != nullptr`. Therefore the test's `transition->matching += 1` mutation is unconsumed, exactly explaining raw case 279's unexpected `phaseFront.disposition() == Produced` and `rejection_reason() == None` without establishing a missing production guard. This is the same ingress error class as row 317 but a **separate curved-disk fixture and claimed bounded-disk guard**. Corrective CB must (a) test tampered authoritative A3 ingress at the actual consumed producer/factory seam with genuinely inconsistent reciprocal transport and a typed rejection, and (b) explicitly prove that mutating ignored raw metadata while a valid atlas is bound cannot modify authoritative behavior. Preserve negative/positive falsifiers; do not weaken the reciprocal transport contract or treat a now-PASS raw mutation as proof of it.

##### P11 row 261 — first failure is missing published A2b terminal/closed-rail provenance, not proved A3 path failure

`SurfaceCellAuthorityContractCutover.MissingTerminalA3PathRejectsAtFirstA4ConsumerPredicate` (`tests/SurfaceCellsPhase10Tests.cpp:8294–8332`) inserts a previously non-hard path spoke into `blocked` hard-feature edges, then calls `build_fixed_plan_rectangular_hard_rail_network(..., &blocked)` while retaining the fixture's original terminal-contact and closed-rail publication. Raw case 261 already observes typed `InvalidHardRailRouteCertificate` and endpoint-attachment locus, but its diagnostic says `a2bProbeFailure=missing-terminal-or-closed-rail-provenance`, `a2bProbeContactPresent=0`, `a2bProbeClosedChainPresent=0`, `a3ProbeContactPublished=0`, `a3ProbeContactEndpointMember=0`, `a3ProbeComponentMatches=0` (plus `a2bProbeFirstFailedCondition=carrier-orientation`); the asserted string `a2bProbeFailure=missing-terminal-A3-path` is absent. The production endpoint-certificate resolver (`src/geometry/SurfaceCellTracing.cpp:19875–19914`) emits `missing-terminal-A3-path` only after relevant A2b/terminal attachments can be evaluated. Simply adding a spoke to the hard-feature set does not preserve its terminal-ownership provenance; the intended isolated missing-A3 predicate was not reached. This **proves an earlier authority/preflight mismatch**, not that the A3 reachability check is correct or incorrect. Corrective CB must construct a truly source-authoritative A2b-hard-carrier/terminal-contact witness with an independent A3 path witness; remove only admissible A3 transport while keeping published A2b fields valid, and require exactly the typed intended failure. Preserve the existing first-guard rejection case as a separate negative; do not change product source merely to produce the expected string.

##### P12 row 314 — measured result does not independently prove a stable performance regression

`tests/SurfaceCellsPhase10Tests.cpp:1088–1105` performs exactly one `run_phase10_tiny_remesh()` followed by one `validate_surface_mesh()` on its tiny output, using `std::chrono::steady_clock` and asserting validation time is strictly below 5% of **that one remesh time**. Raw case 314 reports approximately `169.358 µs` against a `124.8421 µs` five-percent budget; the whole test finishes in about `2 ms`. The raw result **proves this particular comparison failed**, but one sub-millisecond observation on a tiny synthetic fixture cannot distinguish a stable algorithmic overhead regression from measurement granularity, scheduling, cache warmup, or first-call effects. No independently evidenced benchmark protocol or accepted-green baseline is present in this case's raw log. Classify as an **uncalibrated single-sample benchmark**, not automatic license to discard a documented 5% performance requirement. A corrective test/benchmark CB must derive the requirement from current performance authority, use warmups, repeated paired trials, adequate workload/measurement duration, recorded environment and robust statistics, preserve strict validation acceptance, and retain a non-vacuous validator contract oracle independent of timing. Do not simply relax the 5% comparison to make this red green.

##### Disposition and guardrail

These findings refine three case classifications without changing their failing census outcomes or the 85-case accounting: case 279 is a stale ignored-ingress negative, case 261 an invalid first-stage authority witness for the claimed A3-only guard, and case 314 a measurement-protocol defect with the performance requirement still open. None is an accepted-green regression, retirement, or authorization to change executable gate selectors. Open groups P05/P06, the other P11/P12 branches, P13 and remaining P14 cases still require individual source+raw-log proof and falsifiers before TB51 can be frozen.

#### Additional source-grounded P09/P13 diagnosis — 2026-10-30 (runtime-free)

This diagnosis uses exact semantic source snapshot `7907098a319f2020250f35d785386d1a29e009bb` (source-snapshot run `40990572294`, artifact `12948752544`, outer SHA-256 `ffa53ceed6a74487fc9a1a151954fa89e295b7de15d601411578fc98d0a3eb0c`), plus the previously verified immutable TB50C-R2 results artifact `12941320247`, raw logs `192.log`, `344.log`, `350.log`, `360.log`. All 85 original non-PASS identities remain unaltered. No binary execution or source/test/fixture modifications occurred.

**P09c, rows 192 and 344: same prescribed-sphere pipeline fails a trace-event source-carrier placement check.** Test `GlobalTopologyPlan.PrescribedSphereWitnessDerivesRegionsThroughProductionEntryPath` calls `observe_cp4c_witness("sphere_prescribed",...)` (`tests/FieldAlignedCurveNetworkTests.cpp:10884–10904`). Test `SurfaceCutGraph.CellularityCertificatePublishesTotalSourceFaceOwnershipOnProductionFixtures` calls `build_cp4c_pipeline_products_fixture("sphere_prescribed",...)` after mechanical and torus checks (`...:17280–17298`). Both helpers read the same `milestone-g/sphere_prescribed.obj` and `.rawfield` and call `remesh_from_raw_cross_field` with the same default `cp4c_remesh_options()` (`...:7181–7198,7884–7919,5492–5505`). Row 192's raw output retains source topology, A3 atlas and A3 network (24 traces, 56 events), then reports `surface-cut-graph/CellularityNotEstablished/origin=RotationSystemInconsistent`, `TraceEventPositionInvalid`, `trace=2`, `traceEvent=30`, `traceEventClaimedSourceEdge=none`, `traceEventPositionFailure=NoCarrierMatch`, `traceEventPositionPass=SourceEdgeUnavailable`. Row 344 reaches the same prescribed-sphere fixture and reports `NotProductionReady/CellularityNotEstablished`; its shorter log **does not independently enumerate trace 2/event 30**, so shared causal identity is strongly supported by identical pipeline inputs but not independently proven from row 344's diagnostic payload. In `src/geometry/EmbeddedGraphTopology.cpp:147–176`, a non-terminal event with no `sourceEdge` cannot be located; `...:602–625` correctly rejects the unpositionable incidence. **Corrective task:** instrument an independent event-provenance audit at `FieldAlignedCurveNetwork::make` output comparing event 30's role/sourceFace/node/edge with trace 2's concrete segment incoming/outgoing carriers and terminal metadata, plus the actual embedded cut position. Determine if the event producer invented a non-terminal edge-free incidence or if a valid intrinsic/terminal event was misclassified in the consumer. Do not assign a production repair until that causality is proved; never return a synthetic position for an unsupported event. Falsifiers: one legitimate non-terminal event must map to exactly one carrier/position; one forged edge-free non-terminal event must reject with the existing typed failure; the resulting production sphere witness must progress through actual cut-graph certification and non-vacuous disc proofs.

**P09b row 350: ordinary trace-crossed promotion is structurally excluded, not merely unobserved.** The valid fixture constructs a three-edge hard-feature cycle disjoint from baseline trace crossings (`tests/FieldAlignedCurveNetworkTests.cpp:1707–1774`), then its test (`:10901–10929`) finds a selected `TraceInteriorCrossing` candidate but fails only on `EXPECT_FALSE(certificate.saturationUsed)`; immutable `raw/350.log` reports `true`. Independently trace the source selection algorithm: `SurfaceCutGraph.cpp:1066–1071` builds the *ordinary proposal barrier set* as `mandatory ∪ traceCrossed ∪ cuts`. `proposal_tree_cotree_cut_edges` (`:379–396`) explicitly skips every barrier edge; hence an ordinary proposal **cannot** return any `traceCrossed` edge under these inputs, regardless of spanning-tree order. The ordinary loop only inserts such returned non-barrier edges. Only when that loop makes no progress does saturation (`:1076–1088`) select remaining nonmandatory/noncut edges, including trace-crossed edges. `classify_cut_candidates` (`:294–314`) labels `TraceInteriorCrossing` from the trace carrier set and `selected` from `cuts`, not from edge-addition provenance; a selected label cannot prove ordinary selection. `saturationUsed` is global per-certificate and does not identify the promotion path of a specific edge. Thus **the test's conjunct 'selected crossed edge AND saturationUsed=false' is unreachable under this exact source implementation**, not evidence that the A2a' actual-graph certificate incorrectly accepted a noncellular graph. No native re-execution is claimed.

**Authoritative disposition: already frozen AK4 corrective, not an open policy choice.** `DESIGN.md` Amendment 14 alone requires admissibility and completeness, but the later **explicit CP4c-3 requirement** in `M3_Closure_Record.md` §2.1, §6.2 and **AK4** decides the stronger ordinary-path obligation. It identifies `R10-CAND-01` as a proposal-*heuristic* defect, orders modelling trace crossings as **per-face chords** in the proposal component partition (as A2b does for fragments), and requires an ordinary trace-crossed selection with `saturationUsed=false` while retaining an independent AG5 positive-saturation control. Thus do **not** retire/relax the ordinary-only test or reopen that decision without an authorized superseding definition. The case is a **known, non-stable product quality/coverage debt** that still fails under the current heuristic, not a newly introduced accepted-green regression. One future bounded AK4-owner CB must change only the proposal heuristic, prove a trace-crossed edge is available to ordinary tree–cotree election via per-face chords, record per-edge ordinary-versus-saturation provenance, and retain exact intersection subdivision plus independent **actual embedded-graph** cellularity certification. Falsifiers: original ordinary-without-saturation fixture proves a selected crossed edge before any fallback, AG5 still proves legitimate positive fallback, adversarial noncellular input still rejects. Do not falsely set `saturationUsed=false`, weaken `proves_embedded_cellularity`, or modify the immutable network. Preserve case identity in all 85 non-PASS rows pending CB/TB verification.

**P13 row 360: exact cut-transport Euler mismatch, not a mesher-output defect.** The `BunnyRandom` raw log records terminal `InvalidFieldTransportAtlas:field-transport-atlas/CutTransportDomainIdentityMismatch` with `uncutChi=2`, `barrierEdges=17`, `barrierVertices=24`, `barrierChi=7`, `boundaryBarrierVertices=0`, `cutChi=-3`, `cutBoundaryLoops=5` and no downstream trace/arrangement/quad output. `src/authority/FieldTransportAtlas.cpp:1262–1275` defines `expectedCutEuler = region.euler_characteristic() - barrierEulerCharacteristic + barrierRegionBoundaryVertexCount`, so **2-7+0=-5**, which differs from observed **-3** by 2. Its `cutIdentityValid` also requires uncut source-authority identity, nonnegative additional slit loops, integer/nonnegative genus, and exact cut-boundary multiplicities (two boundary copies per barrier edge, one per original boundary edge; `...:1234–1274`). The present log does not expose all conjuncts separately; do not infer which additional conditions are satisfied. **Corrective task:** a focused deterministic atlas transport-cut diagnostic on the immutable bunny input, emitting each conjunct, barrier graph components and topology, vertex-star splitting, global-to-local copies and edge boundary multiplicities. Reconcile the Euler identity before any production fix. Falsifiers: a valid barrier cut must satisfy each identity and multiplicity and preserve non-synthetic A3 source provenance; an invalid cut must continue failing closed with typed cause. **Rows 362/365** each time out at 600 seconds and remain unattributed; full-gate timeout rules remain authoritative.

No new accepted-green loss, retirement, CP3 acceptance, or TB51 executable manifest was established by this review.

#### Source-grounded multi-rail chart fixture defect: P14 cases 406, 407, 408 (2026-10-30, runtime-free)

The complete immutable logs (`raw/406.log`, `raw/407.log`, `raw/408.log`) first fail on the base `resolve_quad_chart(fixture,0).valid()` check **before** the intended missing-link, row-permutation, or unused-relation perturbations. All three call `make_multi_rail_validation_fixture()` (`tests/SurfaceMeshOptimizerPhase22Tests.cpp:321–409`). This explains a common first-stage non-vacuity failure but **does not** establish the downstream contract is correct.

**Independent source and partition proof.** The fixture initially inserts hard-edge barriers `(0,9)`, `(0,5)`, `(0,13)` (`:347–352`), then creates per-vertex `sourceCharts` through `source_chart(...)` (`:352–399`). `source_chart` constructs a fresh `SourceChartTransitionGraph` from the **current** hard-edge set (`:177–191`). Only **after all those charts are produced and sorted**, the fixture inserts `(0,1)` using `for (const int railVertex : {1,5,9,13})` (`:402–408`). The later `resolve_quad_chart` constructs `SourcePointLabelSupport` with the **final** hard-edge set (`:471–488`). `SourceChartTransitionGraph::build()` (`include/directional/geometry/SourceChartTransitions.h:595–750`) joins two incident source faces unless their shared edge is marked hard; the ring has sixteen fan triangles `faces[i]={0,i+1,i+2}` (last wraps outer vertex 1). The initial barriers split the face rows into exactly **three** connected chart components: `[0,1,2,3,12,13,14,15]`, `[4,5,6,7]`, `[8,9,10,11]`. Adding `(0,1)` splits the first into two, producing **four** components `[0–3]`, `[4–7]`, `[8–11]`, `[12–15]`. This arithmetic was re-derived independently from the exact fan faces and hard-edge list, without native execution. The sheet-label differences do **not** change this component-join rule: the graph joins by component and hard barrier, not by raw sheet field.

`SourceProjectionChart` includes the `FieldChartId` assigned to the old component partition (`SourceChartTransitions.h:220–244`). The later `source_face_row(chart)` checks equality with the current chart (`:232–245`); `SourcePointLabelSupport::resolve_compatible_chart` requires every carried chart to rebind exactly and returns invalid on an unmatched row or changed chart (`src/validation/SourceAuthoritativeMeshValidator.cpp:817–857`). Thus the input test authority is stale under its own fixture mutation. **Classification: proven time-of-construction fixture-authority defect for 406/407/408, not proven multi-rail product regression.** Do not change the production equality or fail-closed checks.

**One bounded future Code + Build correction (not authorized here):** populate the complete hard-feature edge set, including `(0,1)`, **before any** `source_chart(...)` or relation publication, and build all charts/relations against one immutable `SourceTopologyRegions + sourceFaces + hardFeatureEdges` tuple. Add independent test assertions that every stored `SourceProjectionChart` resolves back to the same exact face/chart in the final transition graph and that the 16-triangle ring yields four correct canonical components; a deliberately omitted/late barrier must fail closed. Only then re-run the original cases 406/407/408, keeping their selected-chart reachability, off-face relation reciprocity, and source-face row-permutation invariance assertions unchanged. The intended downstream behavior has **not** been observed on valid input, so additional deficiencies remain possible. Keep this fixture-only CB separate from the proven P14 375/385 projection-label CB and the unresolved size-energy derivative failure 390.

**Disposition accounting (updated):** The P14 nine consist of 2 proven projection-label defects (375,385), 3 proven chart-fixture order defects (406–408), 2 missing-boundary-authority fixture prerequisites (373,401), 1 localized but unresolved gradient error (390), and 1 unresolved numeric-metric contract/fail-closed outcome (399). Original red identities and outcomes are unchanged. No retirement or stable accepted-green loss is established; do not enable the proposed TB51 916-case gate on this evidence.

#### Continuation: distinct FlowRep first failures and size-energy projection derivative (2026-10-30; static-only)

The immutable `raw/{8,15,16,17,35,48,390}.log` records and source from exact snapshot `b890c77efe368b97bba6239a8a23cbd6a0cfbe7a` were independently compared. These are **observability/cause-partition corrections**, not an accepted regression count change or a request to weaken runtime guards. No native execution was performed.

##### P05a: row 8 is *not* a rejected endpoint-completion call

`tests/FlowRepStrandsPhase15Tests.cpp:685–806` successfully passes `ASSERT_TRUE(result.is_produced())`, verifies completion counts and that four arc endpoints have collapsed to the source vertex. It then converts the produced arcs into `SurfaceArrangementArc`, calls `build_surface_cell_complex(...)` with `insertBoundaryRails=false` and `sourceAuthority=&sourceAuthority`, and searches the resulting complex for the source-vertex key. The **only** failing line in `raw/8.log` is `ASSERT_GE(vertexNode, 0)` at test line 802. Therefore the first reported defect is **absence of a matching vertex node in the subsequent arrangement**, not a tolerance-era endpoint-completion rejection. The test uses the same **raw source-component label 3** for both incident faces but their *independently constructed TopologyRegionId is 0*, not 3; the arc helper incorrectly uses component label 3 as a topology-region identity. Subsequent source/arrangement audit below proves the preflight mismatch; retain cross-sheet and vertex-degree questions for after valid source-bound inputs. Prohibit manufacturing a vertex to satisfy this assertion or treating a completed endpoint stage as an arrangement success.

##### P05a case 8: independently proved source-component / topology-region identity substitution (2026-10-30)

- `tests/FlowRepStrandsPhase15Tests.cpp:686–807` constructs two adjacent triangles `(0,1,2)` and `(1,0,3)` sharing source edge `(0,1)`, with component labels `{3,3}`, sheet labels `{5,6}`, and *no* hard barriers. `test_source_authority(faces,{3,3},{5,6})` calls `build_source_topology_regions`; this builder groups faces by **component connectivity across non-hard edges** (the raw sheet labels are kept as per-face sheet ownership but do not split a topology region, `SurfaceCellTracing.cpp:9643–9796`). Therefore it produces **one** `TopologyRegionId(0)` containing both faces. Its component has `SourceComponentId(3)` and its faces retain their different sheet labels. `TopologyRegionId` and `SourceComponentId` are **not interchangeable**.
- `endpoint_completion_arc(..., sourceComponent=3, ...)` (`FlowRepStrandsPhase15Tests.cpp:378–407`) misuses its `sourceComponent` parameter as `test_topology_region_id(sourceComponent)` and stamps **TopologyRegionId(3)** on all three input arcs. The row-8 completion call reports Produced, and after completing the endpoint test copies those unchanged region values directly into `SurfaceArrangementArc` (`:769–786`). The fixture passes independent `SourceTopologyRegions` authority to the arrangement constructor.
- In `src/geometry/SurfaceArrangement.cpp:560–571`, `complete_segment_scope` obtains the face's actual source-region ID from `options.sourceAuthority->region_for_row(...)`, rejects any supplied `segment.sourceTopologyRegion` unequal to that ID, and does not reinterpret component label 3 as region 3. In the input-arc loop (`:1878–1900`) rejection sets `embeddingValid=false` and **skips each segment**. Every copied arc has the bad ID, so this source code establishes a deterministic *arrangement preflight defect in the test fixture*, independently sufficient to explain the missing source vertex node reported in immutable `raw/8.log` at line 802. The original log prints only `vertexNode=-1`, not `embeddingValid`, so do not claim runtime evidence of a specific diagnostic code or successful downstream geometry after correcting IDs.
- **Minimal future CB/falsifiers:** derive arc `sourceTopologyRegion` from `sourceAuthority.region_for_row(...)` and independently assert this genuine ID is 0 while `SourceComponentId` remains 3; retain sheet labels 5/6 and the four near-vertex endpoint assertions from the original test. Require nonempty arrangement segments, `complex.diagnostics.embeddingValid`, a genuine exact source vertex node with the intended degree 2, and no artificial row merging across sheets. Add a forged-region-3 negative that must fail the typed arrangement/scope contract, plus a disconnected-at-vertex or different-component negative that must **not** canonicalize across unrelated fans. Do not globally replace source-component labels, relax `complete_segment_scope`, modify the tolerance to obtain green, or retire the test. This does not adjudicate rows 16/48, which reject earlier during endpoint completion.

##### P05b + P06: five endpoint-completion rejections must be typed before cause grouping

`raw/{15,16,17,35,48}.log` each contains only `Value of: result.is_produced() Actual: false Expected: true` at respective lines 444, 501, 552, 1384 and 668. No `result.rejection()->kind`, `.detail`, `result.diagnostics`, `unresolvedRequiredEndpoints`, or trace-termination distribution was printed. Unlike row 8, none of these observations reaches its asserted endpoint postconditions. Source `include/directional/geometry/FlowRepStrands.h:289–381` exposes a typed `FlowRepEndpointCompletionFailureKind` and `rejection()` accessor, while `src/geometry/FlowRepStrands.cpp:2816+` contains independent failure paths (invalid options, missing axes, invalid arc identity, incomplete retained provenance, trace limits, generated missing provenance, unresolved required endpoints). **The immutable logs do not identify which one occurred**: do not call these five stale-oracle failures, real endpoint regressions, or one shared producer defect yet.

Review-authorized specification only: a future Code + Build diagnostic test patch must preserve every original `ASSERT_TRUE` and add independently readable, structured rejection kind/detail, counts, per-endpoint diagnostics and trace termination, including an explicit non-vacuity control. A fresh immutable TB run is then needed to decide causal groups. The fixture shapes (single triangle and source component/sheet 3/5) are shared, but shared setup alone does not prove a common root. Cases 16/48 assert sub-tolerance behavior; 15/17/35 assert endpoint support, arrangement reproducibility, and hard-feature retention. Keep those distinct obligations even if their typed failure later matches. No instrumentation may synthesize success or overwrite the rejection.

##### P05b/P06 five source-component / topology-region fixture mismatches (2026-10-30, source-only; native first cause unprinted)

All five original RED rows **15, 16, 17, 35, 48** are `FlowRepStrandsPhase15` tests using **one source triangle**, `tracing.sourceFaceComponents={3}`, `sourceFaceSheets={5}`, and `test_source_authority(...)`. The A2 builder in `src/geometry/SurfaceCellTracing.cpp:9643–9997` publishes a single `TopologyRegionId(0)` for this source, with raw `SourceComponentId(3)` and sheet 5. However `endpoint_completion_arc(...)` in `tests/FlowRepStrandsPhase15Tests.cpp:378–407` writes `test_topology_region_id(sourceComponent)` into *every* source arc. All five pass the value **3**, so every retained input arc is stamped with an *incorrect* `TopologyRegionId(3)` despite a valid source-component label 3. Row 15's expected `added.sourceTopologyRegion==TopologyRegionId(3)` (`:453–456`) also codifies this type confusion. This is a independently **proved input-authority inconsistency across five tests**, not a proof that the native completion implementation regressed.

A concrete, source-verified masking mechanism exists: `src/geometry/FlowRepStrands.cpp:3538–3563` obtains the segment's true typed region from `tracing_source_scope` (region 0) and **skips same-face retained network intersections** when `target.sourceTopologyRegion` is not that region (target region 3). Later generated arcs are assigned the actual source-region ID 0 (`:3590–3601`), making their identity inconsistent with the original retained arcs. Row 35 additionally exercises hard-feature ownership; do not assume its complete rejection is explained only by this one mismatch. The immutable logs for the five rows print only `result.is_produced()==false` and no typed `rejection()->kind`, endpoint diagnostics, or accepted trace witnesses. They thus do **not** prove whether the first logged rejection was `UnresolvedRequiredEndpoints` or some other path. Distinguish a certain *invalid test input authority* from an unobserved actual native failure code.

**Future exact CB and falsifiers:** derive each input-arc `TopologyRegionId` from `sourceAuthority.region_for_row(SourceFaceId(0))` and require region 0, while retaining independent assertions for component 3 and sheet 5; change the invalid generated-region-3 expectation in row 15 to the genuine A2 region identity. Instrument original tests to expose structured typed failure/disposition, per-endpoint captures and retained-arc provenance without disabling the original positive assertions or changing tolerances. Add region-3 tamper negatives that must not be considered source-owning network captures; ensure a genuine target arc of region 0 captures appropriately, along with a distinct-sheet/component non-capture control. Retain the precise original near-intersection and hard-rail non-vacuity oracles (rows 16/48 and 35). Only run a future authorized CB/TB after this DEFN closes; additional production defects after correcting these fixtures are possible. None of these five is retired, none is new accepted-green regression authority, and no change is made to the O2 legacy contract.

##### P14 row 390: source-projection Jacobian omitted from target-size derivative (localized risk, not yet a proved whole-gradient fix)

`raw/390.log` isolates the **size** energy (`SCOPED_TRACE("size")`) and reports relative error `0.083494013311452384` against `1e-6` (`tests/SurfaceMeshOptimizerPhase20Tests.cpp:119–137`). The analytic size gradient at `src/geometry/SurfaceMeshOptimizer.cpp:2030–2065` multiplies `local_target_size_gradient(constraints, projectedSourcePoint)` by a chain-rule factor. But `local_target_size_gradient` (`:561–569`) returns the *unrestricted source-triangle scalar gradient*, without applying the Jacobian of the **input-output projection** that produced the source point. The energy, however, uses `project_vertices` (`:759–850`) and then barycentrically interpolates `localTargetSize` at the projected point (`:575–601,1498–1503`). The independent finite-difference function perturbs the *input* vertex and reprojects on every evaluation (`:2219–2254`).

A concrete differentiability counterexample follows directly from the checked test fixture (`tests/SurfaceMeshOptimizerPhase20Tests.cpp:25–76`): source square `(0,0),(2,0),(2,2),(0,2)` with target sizes `(0.9,1.1,1.2,0.8)` and source triangles `(0,1,2),(0,2,3)`; input vertex 3 is `(-0.1,0.9,-0.05)`. Its closest source projection is on the boundary edge `x=0`, so varying input `x` infinitesimally around `-0.1` leaves the projected `x` fixed and gives `d(target)/d(input x)=0`; the unrestricted face-1 scalar gradient has `d(target)/d(source x)=+0.2`. Similarly feature vertex 2 `(1.1,1.4,0.3)` is constrained onto a feature interval along `y=0` (`:50–76`), so the projected size's input-`y` derivative is zero away from interval endpoints although its source-face gradient contains a nonzero `y` component. These are concrete **projection-chain-rule hazards**. Their contribution to the logged full-matrix residual has not been quantified and projection boundaries can be nondifferentiable. Do not declare this alone the proven cause or loosen the `1e-6` oracle.

**Bounded CB falsifiers:** (1) isolate one boundary-projected nonfeature vertex and one feature-projected vertex; compare per-coordinate centered finite differences of `local_target_size(project(input))` with the actual projection-aware Jacobian; (2) compare each weighted edge-size term with numerical differentiation on smooth interior points, then separately test clamped boundary, feature-interval interior, face-transition and immutable-rail cases; (3) recompute the full size-gradient matrix and retain the original `1e-6` error criterion on differentiable inputs; (4) test sheet/component scoping and keep the projection fail-closed invariants unchanged. Treat nondifferentiability separately rather than changing finite-difference acceptance globally.

##### Accounting and stop rules

Rows 8, 15, 16, 17, 35, 48 and 390 retain their original non-PASS status and unchanged test names. The remaining 78 identities are unaffected by this evidence refinement; overall census is still 323 PASS + 83 RED + 2 ABNORMAL, with 85 non-PASS and zero authorized retirements. No stable accepted-green loss established. The 916-case TB51 candidate is **still non-authoritative**. Continue individual proof of unresolved cause groups, then prepare one bounded corrective CB per independently established cause, mandatory review-check and closeout, and only then gate freeze.

#### P07 negative-fixture and variant-access review correction (2026-10-30; no native execution)

**Row 54: the test constructs an invalid fixture but calls the producer with the valid fixture.** `tests/PatchDescriptorMilestoneETests.cpp:1316–1337` creates `Fixture fixture` and `Fixture invalid`, marks `invalid.complex.cells.front().disk=false` and `.cellClass=NonDisk`, and appends a second fixture component to **`invalid`** (`:1318–1324`). But its actual call is `complete_surface_cell_complex(fixture.complex, fixture.V, fixture.F,{})` (`:1326–1327`), *not* `(invalid.complex, invalid.V, invalid.F,...)`. The raw row-54 log shows a rejected result but different detail and zero `attemptedPatches`/`failedPatches`, rather than the expected `IncompleteSurfaceCellComplex` after one failed patch. Because the mutated invalid witness was **never supplied**, the asserted non-disk/partial-output rejection is vacuous on this run. This is an independently proved **wrong-fixture-argument test defect**. A future Code + Build correction must feed the complete invalid complex/vertices/faces tuple and supply a valid-complex positive control, then independently require the exact fail-closed typed reason and no partial output. Do not force rejection by changing the production completion algorithm.

**Row 61: a failed soft assertion is followed by invalid variant extraction.** `tests/PatchDescriptorMilestoneETests.cpp:1181–1193` uses `EXPECT_TRUE(completion.is_produced())` and then immediately accesses `completion.product()` at lines 1190–1191. Immutable `raw/61.log` shows the expectation fails (`is_produced()==false`), followed by `std::get: wrong index for variant` thrown in the test body. `FlowRep`/completion typed-product APIs use `std::get` for produced variants; accessing a rejected product is not a second producer failure. Here the exact **test control-flow defect** is use of a soft assertion where a hard guard is required. A future CB must log the actual typed completion rejection (kind, detail, rollback and authority diagnostics), use a non-vacuous hard guard before reading `.product()`, and preserve all postconditions on successful production. The underlying reason for **rejection remains unresolved**, so do not call this a simple stale oracle or treat fixing the test's secondary exception as resolving the product condition.

**P07 partition integrity:** exactly two rows are relabeled (54,61) without changing the 11 P07 identities, raw first failures, total 85 non-PASS cases, or accepted-green/stable counts. Row 57 remains the separately proven missing-registry fixture; rows 58 and 66 retain their independently observed registry mismatches with causal owner unresolved; all other P07 producer/fixture claims still require source-grounded adjudication. No test, fixture or product implementation changed in this DEFN review.

#### Complete 85-row evidence ledger

| Row | Test | Result | Group | Candidate classification | First observed error (abbreviated) | Raw SHA-256 |
|---:|---|---|---|---|---|---|
| 8 | `FlowRepStrandsPhase15.AdjacentFaceFanCanonicalizesSubToleranceEndpointsToSourceVertex` | RED | P05a | post-completion-arrangement-node-absent | ../../Directional/Directional/tests/FlowRepStrandsPhase15Tests.cpp:802: Failure \| Expected: (vertexNode) >= (0), actual: -1 vs 0 | `a5a62c144c5e583f…` |
| 15 | `FlowRepStrandsPhase15.EndpointCompletionExtendsToRetainedSameSheetNetwork` | RED | P06 | typed-rejection-unreported | ../../Directional/Directional/tests/FlowRepStrandsPhase15Tests.cpp:444: Failure \| Value of: result.is_produced() \| Actual: false \| Expected: true | `a732332a108ca477…` |
| 16 | `FlowRepStrandsPhase15.EndpointCompletionIgnoresSubToleranceIntersectionAtTraceOrigin` | RED | P05b | typed-rejection-unreported | ../../Directional/Directional/tests/FlowRepStrandsPhase15Tests.cpp:501: Failure \| Value of: result.is_produced() \| Actual: false \| Expected: true | `4ab800dd55d6fc56…` |
| 17 | `FlowRepStrandsPhase15.EndpointCompletionOnlyCommitsArrangementReproducibleIntersections` | RED | P06 | typed-rejection-unreported | ../../Directional/Directional/tests/FlowRepStrandsPhase15Tests.cpp:552: Failure \| Value of: result.is_produced() \| Actual: false \| Expected: true | `00d516222f861426…` |
| 22 | `FlowRepStrandsPhase15.IndexAwareSingularitySeparatrixBecomesEmbeddedLayoutSupport` | RED | P04a | setup-precondition-proven | unknown file: Failure \| C++ exception with description "compute_edge_quantities(): DCEL consistency check failed" thrown in the test body. | `286597487f980c91…` |
| 24 | `FlowRepStrandsPhase15.IntraRingRailPrefixUsesCanonicalSingularitySpokeInsteadOfMicroLoop` | RED | P02a | atlas-port-class-deficit-observed | unknown file: Failure \| C++ exception with description "FlowRep test A3 atlas unavailable" thrown in the test body. | `c0047509f72292a4…` |
| 28 | `FlowRepStrandsPhase15.InvalidSingularitySeparatrixMetadataStillFailsClosed` | RED | P04a | setup-precondition-proven | unknown file: Failure \| C++ exception with description "compute_edge_quantities(): DCEL consistency check failed" thrown in the test body. | `66c030981ed87717…` |
| 33 | `FlowRepStrandsPhase15.NetworkConversionUsesOnlyAcceptedClosedBoundaries` | RED | P04a | setup-precondition-proven | unknown file: Failure \| C++ exception with description "compute_edge_quantities(): DCEL consistency check failed" thrown in the test body. | `7531a69075c41b14…` |
| 34 | `FlowRepStrandsPhase15.NonemptyDegenerateSingularitySeparatrixRemainsCompletionObligation` | RED | P04a | setup-precondition-proven | unknown file: Failure \| C++ exception with description "compute_edge_quantities(): DCEL consistency check failed" thrown in the test body. | `ab3703d006fba0f9…` |
| 35 | `FlowRepStrandsPhase15.OpenHardFeatureEndpointsExtendWithoutRemovingAuthoritativeRail` | RED | P06 | typed-rejection-unreported | ../../Directional/Directional/tests/FlowRepStrandsPhase15Tests.cpp:1384: Failure \| Value of: result.is_produced() \| Actual: false \| Expected: true | `70e6fb90d4a7ff39…` |
| 37 | `FlowRepStrandsPhase15.PreRingReturnRerootsRetainedSingularityContinuation` | RED | P02a | atlas-port-class-deficit-observed | unknown file: Failure \| C++ exception with description "FlowRep test A3 atlas unavailable" thrown in the test body. | `cd4151267f43f46e…` |
| 38 | `FlowRepStrandsPhase15.ProposalRailSegmentsRemainMandatoryCycleEvidence` | RED | P04a | setup-precondition-proven | unknown file: Failure \| C++ exception with description "compute_edge_quantities(): DCEL consistency check failed" thrown in the test body. | `786b93bbd598836e…` |
| 39 | `FlowRepStrandsPhase15.RailEndpointTracesBecomeDeduplicatedOptionalLayoutSupport` | RED | P04a | setup-precondition-proven | unknown file: Failure \| C++ exception with description "compute_edge_quantities(): DCEL consistency check failed" thrown in the test body. | `c5864f0e45937453…` |
| 43 | `FlowRepStrandsPhase15.SelectionInputBuildsNormalizedCoverageAndClosedCycleEvidence` | RED | P04a | setup-precondition-proven | unknown file: Failure \| C++ exception with description "compute_edge_quantities(): DCEL consistency check failed" thrown in the test body. | `596c3fbc6ca45a06…` |
| 45 | `FlowRepStrandsPhase15.SingularityTransitionRingIsIntrinsicClosedAndDeterministic` | RED | P02a | atlas-port-class-deficit-observed | unknown file: Failure \| C++ exception with description "FlowRep test A3 atlas unavailable" thrown in the test body. | `41c9cc1240738cf7…` |
| 46 | `FlowRepStrandsPhase15.SingularityTransitionRingMakesRadialSectorsNonBridgingDisks` | RED | P02a | atlas-port-class-deficit-observed | unknown file: Failure \| C++ exception with description "FlowRep test A3 atlas unavailable" thrown in the test body. | `01a21ac5cac2cae9…` |
| 48 | `FlowRepStrandsPhase15.SubToleranceIntrinsicCaptureReconcilesOpenEndpointWithoutTinyArc` | RED | P05b | typed-rejection-unreported | ../../Directional/Directional/tests/FlowRepStrandsPhase15Tests.cpp:668: Failure \| Value of: result.is_produced() \| Actual: false \| Expected: true | `83cec57a5ed4f373…` |
| 52 | `PatchDescriptorMilestoneE.AuthoritativeCellScopeOverridesMultiScopeBoundaryDuringSubdivision` | RED | P07 | mixed-scope-provenance-preservation-observed | ../../Directional/Directional/tests/PatchDescriptorMilestoneETests.cpp:1725: Failure \| Expected equality of these values: \| *provenance.sourceTopologyRegion \| Which is: 8-byte o | `f607e63db04c0666…` |
| 54 | `PatchDescriptorMilestoneE.ComplexCompletionFailsClosedInsteadOfReturningPartialOutput` | RED | P07 | wrong-fixture-argument-proven | ../../Directional/Directional/tests/PatchDescriptorMilestoneETests.cpp:1331: Failure \| Expected equality of these values: \| completion.rejection()->detail.rfind( "IncompleteSurfa | `0186aab074cc0a3f…` |
| 57 | `PatchDescriptorMilestoneE.DuplicateDomainsFailBeforePatchCompletion` | RED | P07 | invalid-fixture-registry-proven | ../../Directional/Directional/tests/PatchDescriptorMilestoneETests.cpp:1376: Failure \| Expected equality of these values: \| directional::geometry::SurfaceCellOwnershipConflictCla | `f1bf2de50d75be97…` |
| 58 | `PatchDescriptorMilestoneE.GlobalDescriptorAssignmentRejectsAmbiguousInteriorSingularity` | RED | P07 | post-preparation-registry-mismatch-observed | ../../Directional/Directional/tests/PatchDescriptorMilestoneETests.cpp:1291: Failure \| Expected equality of these values: \| "UnresolvedSingularityOwnership" \| completion.rejecti | `cc849fde5cc55496…` |
| 60 | `PatchDescriptorMilestoneE.OneCandidateBudgetIsExactAndDoesNotRecurse` | RED | P07 | regression-candidate | ../../Directional/Directional/tests/PatchDescriptorMilestoneETests.cpp:1597: Failure \| Expected equality of these values: \| 1 \| completion.completionOwnershipStructuralRepairAtt | `5c02736a8317d6f4…` |
| 61 | `PatchDescriptorMilestoneE.PermittedSideRepairFailureReturnsExactRollbackForGeneralCompletion` | RED | P07 | unsafe-test-variant-access-proven | ../../Directional/Directional/tests/PatchDescriptorMilestoneETests.cpp:1189: Failure \| Value of: completion.is_produced() \| Actual: false \| Expected: true | `862f4b994563eb20…` |
| 64 | `PatchDescriptorMilestoneE.SemanticOnlySameCornerOverlapFailsBeforeCandidateExpansion` | RED | P07 | regression-candidate | ../../Directional/Directional/tests/PatchDescriptorMilestoneETests.cpp:1541: Failure \| Expected equality of these values: \| directional::geometry::SurfaceCellStructuralRepairExha | `cf0503e895250e96…` |
| 65 | `PatchDescriptorMilestoneE.StructuralRepairLedgerIsPatchOrderInvariant` | RED | P07 | regression-candidate | ../../Directional/Directional/tests/PatchDescriptorMilestoneETests.cpp:1660: Failure \| Value of: a.ownershipRepairAttempts.empty() \| Actual: true \| Expected: false | `cc45b509c17e5054…` |
| 66 | `PatchDescriptorMilestoneE.SuccessfulSideSubdivisionPreservesCanonicalDomainIdentity` | RED | P07 | post-preparation-registry-mismatch-observed | ../../Directional/Directional/tests/PatchDescriptorMilestoneETests.cpp:1129: Failure \| Value of: audit.valid \| Actual: false \| Expected: true \| ownership-registry-mismatch cell | `7c3b7ea57e980280…` |
| 68 | `PatchDescriptorMilestoneE.WholeComplexParallelRouteRepairCompletesWithinOneGlobalLedger` | RED | P07 | regression-candidate | ../../Directional/Directional/tests/PatchDescriptorMilestoneETests.cpp:1476: Failure \| Expected equality of these values: \| directional::geometry::SurfaceCellOwnershipConflictCla | `0c1d0bd597e67bdf…` |
| 69 | `PatchDescriptorMilestoneE.ZeroStructuralBudgetFailsBeforeCandidateExpansion` | RED | P07 | regression-candidate | ../../Directional/Directional/tests/PatchDescriptorMilestoneETests.cpp:1567: Failure \| Expected equality of these values: \| directional::geometry::SurfaceCellOwnershipConflictCla | `084fa95047505a37…` |
| 95 | `SurfaceComplexSimplificationPhase17.BuildsElementsFromPhase16Complex` | RED | P08 | missing-source-authority-fixture-proven | ../../Directional/Directional/tests/SurfaceComplexSimplificationPhase17Tests.cpp:909: Failure \| Value of: elements.empty() \| Actual: true \| Expected: false | `a469ab171f15b52a…` |
| 96 | `SurfaceComplexSimplificationPhase17.CandidateExtractionIsDeterministicAndCarriesAuthoritativeSupport` | RED | P08 | missing-source-authority-fixture-proven | ../../Directional/Directional/tests/SurfaceComplexSimplificationPhase17Tests.cpp:1024: Failure \| Value of: first.candidates.empty() \| Actual: true \| Expected: false | `9ad1c63667d6ebeb…` |
| 97 | `SurfaceComplexSimplificationPhase17.CandidateExtractionMarksProtectedSupportInsteadOfSilentlyDroppingIt` | RED | P08 | missing-source-authority-fixture-proven | ../../Directional/Directional/tests/SurfaceComplexSimplificationPhase17Tests.cpp:1079: Failure \| Expected: (removable) >= (0), actual: -1 vs 0 | `bca7547611ecd7d8…` |
| 100 | `SurfaceComplexSimplificationPhase17.ComplexCandidateRecomputationCreatesRealQueuedCandidates` | RED | P08 | missing-source-authority-fixture-proven | ../../Directional/Directional/tests/SurfaceComplexSimplificationPhase17Tests.cpp:1005: Failure \| Expected: (found) != (extracted.candidates.end()), actual: 8-byte object <00-00 00 | `bcd8fd6e64155a93…` |
| 101 | `SurfaceComplexSimplificationPhase17.ComplexRollbackPreservesHashOnRejectedTrial` | RED | P08 | missing-source-authority-fixture-proven | ../../Directional/Directional/tests/SurfaceComplexSimplificationPhase17Tests.cpp:974: Failure \| Expected: (removable) >= (0), actual: -1 vs 0 | `070f2fa2a6ff12e2…` |
| 103 | `SurfaceComplexSimplificationPhase17.MultipleOptionalBridgeExcursionsHealAtomicallyAcrossFamilies` | RED | P08 | missing-source-authority-fixture-proven | ../../Directional/Directional/tests/SurfaceComplexSimplificationPhase17Tests.cpp:1246: Failure \| Expected: (beforeDefect) > (0), actual: 0 vs 0 | `954e25d5a4b16993…` |
| 106 | `SurfaceComplexSimplificationPhase17.OptionalCellHealingCommitsWhileUnrelatedRequiredDefectRemains` | RED | P08 | missing-source-authority-fixture-proven | ../../Directional/Directional/tests/SurfaceComplexSimplificationPhase17Tests.cpp:1319: Failure \| Expected: (beforeDefect) > (1), actual: 0 vs 1 | `448172ed7ca65447…` |
| 107 | `SurfaceComplexSimplificationPhase17.OptionalLayoutBridgeHealsPinchedCellTransactionally` | RED | P08 | missing-source-authority-fixture-proven | ../../Directional/Directional/tests/SurfaceComplexSimplificationPhase17Tests.cpp:1180: Failure \| Expected: (beforeDefect) > (0), actual: 0 vs 0 | `cb8100c6f8c55a63…` |
| 109 | `SurfaceComplexSimplificationPhase17.OversampledArrangementGeneratesRealNonemptyCandidateSet` | RED | P08 | missing-source-authority-fixture-proven | ../../Directional/Directional/tests/SurfaceComplexSimplificationPhase17Tests.cpp:1062: Failure \| Expected: (extracted.candidates.size()) > (0U), actual: 0 vs 0 | `32c0a0e10967ba36…` |
| 112 | `SurfaceComplexSimplificationPhase17.RequiredSingularityBridgeIsProtectedAndRollsBackExactly` | RED | P08 | missing-source-authority-fixture-proven | ../../Directional/Directional/tests/SurfaceComplexSimplificationPhase17Tests.cpp:1381: Failure \| Expected: (healing) != (extracted.candidates.end()), actual: 8-byte object <00-00  | `87cfa9fd0c6730c7…` |
| 114 | `SurfaceComplexSimplificationPhase17.SimplifySurfaceCellComplexReturnsMutatedComplex` | RED | P08 | missing-source-authority-fixture-proven | ../../Directional/Directional/tests/SurfaceComplexSimplificationPhase17Tests.cpp:943: Failure \| Expected: (removable) >= (0), actual: -1 vs 0 | `903008176e2e254a…` |
| 118 | `SurfaceComplexSimplificationPhase17.TransactionalMutationCommitsExtractedOversampledCandidate` | RED | P08 | missing-source-authority-fixture-proven | ../../Directional/Directional/tests/SurfaceComplexSimplificationPhase17Tests.cpp:1112: Failure \| Value of: extracted.candidates.empty() \| Actual: true \| Expected: false | `6c1719cef97ee7d9…` |
| 119 | `SurfaceComplexSimplificationPhase17.TransactionalMutationPreservesHardRailSupport` | RED | P08 | missing-source-authority-fixture-proven | ../../Directional/Directional/tests/SurfaceComplexSimplificationPhase17Tests.cpp:1145: Failure \| Expected: (protectedHalfedge) >= (0), actual: -1 vs 0 | `a9299a280211382e…` |
| 157 | `BoundedMeshPreconditionerPhase07.HistoricalArrangementComplexityCaseProducesNoWorseOutputTopology` | RED | P03 | A1-boundary-cycle-setup-failure | unknown file: Failure \| C++ exception with description "Cross-field finalization could not publish source-boundary cycle authority." thrown in the test body. | `68ea2ca3cba4124b…` |
| 163 | `BoundedMeshPreconditionerPhase07.PreconditioningOnDoesNotChangeConnectedComponentCount` | RED | P03 | A1-boundary-cycle-setup-failure | unknown file: Failure \| C++ exception with description "Cross-field finalization could not publish source-boundary cycle authority." thrown in the test body. | `3b08694588ff6de7…` |
| 175 | `GlobalTopologyPlan.CarrierlessTraceIncidenceDiagnosticsSurviveProductionFailureProjection` | RED | P09a | proven-projection-omission | ../../Directional/Directional/tests/FieldAlignedCurveNetworkTests.cpp:13946: Failure \| Expected: (std::string::npos) != (emitted.find(token)), actual: 18446744073709551615 vs 1844 | `6d908f43e9b05095…` |
| 182 | `GlobalTopologyPlan.Cp4c2PrescribedSphereCellularityScopeDecisionIsObservable` | RED | P01 | forced-FAIL-nonverifying-not-retired | ../../Directional/Directional/tests/FieldAlignedCurveNetworkTests.cpp:10506: Failure \| Failed \| m3Cp4c2X2;prescribed sphere;railAuthority=pipeline-authoritative;pipelineFailure=N | `33e8ffb8361706cb…` |
| 191 | `GlobalTopologyPlan.MechanicalWitnessStageReachabilityIsObservable` | RED | P01 | forced-FAIL-nonverifying-not-retired | ../../Directional/Directional/tests/FieldAlignedCurveNetworkTests.cpp:10500: Failure \| Failed \| mechanical feature;railAuthority=pipeline-authoritative;pipelineFailure=NotProduct | `544039d0d2dd7fb6…` |
| 192 | `GlobalTopologyPlan.PrescribedSphereWitnessDerivesRegionsThroughProductionEntryPath` | RED | P09c | source-carrier-placement-rejection-observed | ../../Directional/Directional/tests/FieldAlignedCurveNetworkTests.cpp:10890: Failure \| Value of: sphere.cutGraph.has_value() \| Actual: false \| Expected: true \| prescribed spher | `f25cdae84d30ff57…` |
| 196 | `GlobalTopologyPlan.SpherePrescribedWitnessStageReachabilityIsObservable` | RED | P01 | forced-FAIL-nonverifying-not-retired | ../../Directional/Directional/tests/FieldAlignedCurveNetworkTests.cpp:16392: Failure \| Failed \| prescribed sphere;railAuthority=pipeline-authoritative;pipelineFailure=NotProducti | `d251c9dc43467ff0…` |
| 197 | `GlobalTopologyPlan.TorusWitnessStageReachabilityIsObservable` | RED | P01 | forced-FAIL-nonverifying-not-retired | ../../Directional/Directional/tests/FieldAlignedCurveNetworkTests.cpp:10494: Failure \| Failed \| torus;railAuthority=pipeline-authoritative;pipelineFailure=NotProductionReady;pipe | `21f7371e8a494795…` |
| 223 | `M6CP3.CheckedFactoryRejectsForgedTerminalA2bSideGerm` | RED | P11 | uncovered-hard-rail-negative-preflight-proven | ../../Directional/Directional/tests/SurfaceCellTransitionQuotientTests.cpp:10350: Failure \| Value of: unreachableError->sourceAuthorityDetail.has_value() \| Actual: false \| Expec | `50b339aa23e95fb0…` |
| 225 | `M6CP3.TerminalRailContactPathsUseTypedSourceStarA3` | RED | P11 | nonterminal-endpoint-oracle-defect-proven | ../../Directional/Directional/tests/SurfaceCellTransitionQuotientTests.cpp:9932: Failure \| Value of: endpoint.terminalVertex.has_value() \| Actual: false \| Expected: true | `a187593abae8d364…` |
| 235 | `ResolvedBranchCorrection.FoldedConeArrivalRayElectsOneOwnerAndFalsifiesCandidateLocalElection` | RED | P10a | invalid-cone-field-cycle-transport-invariant-typed-first-guard-unreported | ../../Directional/Directional/tests/FieldAlignedCurveNetworkTests.cpp:11646: Failure \| Value of: atlasBuild \| Actual: false \| Expected: true | `562b2ede58651e4a…` |
| 236 | `ResolvedBranchCorrection.FoldedConeBoundaryContinuationUsesExactFallbackAndHalfOpenOwner` | RED | P10a | invalid-cone-field-cycle-transport-invariant-typed-first-guard-unreported | ../../Directional/Directional/tests/FieldAlignedCurveNetworkTests.cpp:11710: Failure \| Value of: atlasBuild \| Actual: false \| Expected: true | `ad588259e52cb93a…` |
| 237 | `ResolvedBranchCorrection.FoldedConeRadialArrivalSeedUsesExactHalfOpenArrivalConvention` | RED | P10a | invalid-cone-field-cycle-transport-invariant-typed-first-guard-unreported | ../../Directional/Directional/tests/FieldAlignedCurveNetworkTests.cpp:11985: Failure \| Value of: atlasBuild \| Actual: false \| Expected: true | `ccd94c9446078842…` |
| 241 | `ResolvedBranchCorrection.HardCarrierStarCutPreservesBoundaryTransit` | RED | P10a | invalid-cone-field-cycle-transport-invariant-typed-first-guard-unreported | ../../Directional/Directional/tests/FieldAlignedCurveNetworkTests.cpp:12132: Failure \| Value of: atlasBuild \| Actual: false \| Expected: true | `b639d2e48319ee5f…` |
| 243 | `ResolvedBranchCorrection.MinimalExactVertexTransitWitnessPublishesKnownFanState` | RED | P10b | inadmissible-face-interior-arrival-seed-source-proven; first-typed-guard-unprinted | ../../Directional/Directional/tests/FieldAlignedCurveNetworkTests.cpp:11619: Failure \| Expected: (FieldAlignedCurveNetworkErrorCode::VertexTransitSeedUnavailable) != (error.code), | `883322ab7c04ad4c…` |
| 261 | `SurfaceCellAuthorityContractCutover.MissingTerminalA3PathRejectsAtFirstA4ConsumerPredicate` | RED | P11 | missing-A2b-provenance-preflight | ../../Directional/Directional/tests/SurfaceCellsPhase10Tests.cpp:8325: Failure \| Expected: (std::string::npos) != (failure->hardRailRouteDiagnostic.find( "a2bProbeFailure=missing- | `42df5c1321a893ba…` |
| 265 | `SurfaceCellAuthorityContractCutover.ProducedHardCarriersAreAtlasBarriersNotSourceBoundaryTransit` | RED | P11 | stale-cross-representation-oracle-proven | ../../Directional/Directional/tests/SurfaceCellsPhase10Tests.cpp:7651: Failure \| Expected equality of these values: \| sameOrientation ? transport.forward : transport.reverse \| W | `521a4b587e6dcca8…` |
| 276 | `SurfaceCellPhaseFrontFieldChartAuthorityMigration.MultipleOrientationChartsPreserveEstablishedNumbering` | RED | P12 | stale-field-rotation-vs-source-chart-oracle-proven | ../../Directional/Directional/tests/SurfaceCellsPhase10Tests.cpp:5950: Failure \| Expected equality of these values: \| static_cast<std::size_t>(expectedChart) \| Which is: 1 \| se | `27d0dbba33d8852d…` |
| 277 | `SurfaceCellPipelinePhase20.ProducedNonconstantTwoCarrierOddTauSharesA1VertexGerm` | RED | P12 | regression-candidate | ../../Directional/Directional/tests/SurfaceCellREPackageTests.cpp:1240: Failure \| Expected: (routes.end()) != (route), actual: 8-byte object <80-9E 93-47 81-55 00-00> vs 8-byte ob | `98fdc431df5b0b58…` |
| 279 | `SurfaceCellsPhase10.CurvedBoundedDiskInvalidReciprocalTransportFailsClosed` | RED | P12 | stale-negative-oracle-proven | ../../Directional/Directional/tests/SurfaceCellsPhase10Tests.cpp:3666: Failure \| Expected equality of these values: \| directional::geometry::SurfaceCellProducerDisposition::Rejec | `c170ed98717dd08a…` |
| 283 | `SurfaceCellsPhase10.ExactCommittedTorusDoesNotTreatIsolationSeamAsBoundedDiskBoundary` | RED | P12 | regression-candidate | ../../Directional/Directional/tests/SurfaceCellsPhase10Tests.cpp:5379: Failure \| Expected: (result.diagnostics.surfaceCellTopologyRegionCount) > (0U), actual: 0 vs 0 | `8b64592b3a4ead07…` |
| 286 | `SurfaceCellsPhase10.HardRailRegionCopiesPairReciprocallyBeforeQuotientMaterialization` | RED | P12 | regression-candidate | ../../Directional/Directional/tests/SurfaceCellsPhase10Tests.cpp:3205: Failure \| Expected equality of these values: \| directional::geometry::SurfaceCellProducerDisposition::Produ | `105122d38a76dd53…` |
| 296 | `SurfaceCellsPhase10.MeshValidatorUsesComponentSheetInsteadOfExactFaceEquality` | RED | P12 | stale-negative-oracle-proven | ../../Directional/Directional/tests/SurfaceCellsPhase10Tests.cpp:888: Failure \| Value of: result.accepted \| Actual: true \| Expected: false | `39694814056fc796…` |
| 303 | `SurfaceCellsPhase10.PhaseFrontProducedThenUnsupportedSheetFailsClosedWithoutPartialAuthority` | RED | P02b | forward-A3-failure-reverse-variant-unexecuted-typed-cause-unknown | unknown file: Failure \| C++ exception with description "unsupported-sheet source A3 unavailable" thrown in the test body. | `942f70c2b6b9aae3…` |
| 313 | `SurfaceCellsPhase10.StrictValidatorAcceptsLegacySyntheticOutput` | RED | P03 | A1-boundary-cycle-setup-failure | unknown file: Failure \| C++ exception with description "Cross-field finalization could not publish source-boundary cycle authority." thrown in the test body. | `56299acccfc09916…` |
| 314 | `SurfaceCellsPhase10.StrictValidatorOverheadStaysBelowFivePercent` | RED | P12 | uncalibrated-microbenchmark | ../../Directional/Directional/tests/SurfaceCellsPhase10Tests.cpp:1104: Failure \| Expected: (validationSeconds) < (remeshSeconds * 0.05), actual: 0.000169358 vs 0.00012484210000000 | `eb2bb42cd2226bd5…` |
| 317 | `SurfaceCellsPhase10.UniformPhaseFrontDuplicateTransitionMetadataFailsClosedWithTypedReason` | RED | P12 | stale-negative-oracle-proven | ../../Directional/Directional/tests/SurfaceCellsPhase10Tests.cpp:1793: Failure \| Value of: network.phaseFront.is_produced() \| Actual: true \| Expected: false | `5eb9574da6527fee…` |
| 324 | `SurfaceCellTransitionQuotient.GenuineBoundaryWithInventedInteriorIndexIsRejected` | RED | P11 | stale-typed-reason-oracle-proven | ../../Directional/Directional/tests/SurfaceCellTransitionQuotientTests.cpp:7707: Failure \| Expected equality of these values: \| "InvalidSourceBoundaryAuthority" \| result.failure | `6716b43daf0b88cc…` |
| 331 | `SurfaceCellTransitionQuotient.QuotientLineageRetainsScalarPointAndCompleteSortedAuthority` | RED | P11 | untyped-isolation-equivalence-oracle-proven | ../../Directional/Directional/tests/SurfaceCellTransitionQuotientTests.cpp:9675: Failure \| Value of: foundSeamEquivalence \| Actual: false \| Expected: true | `a5f4ec8ad11f79f8…` |
| 344 | `SurfaceCutGraph.CellularityCertificatePublishesTotalSourceFaceOwnershipOnProductionFixtures` | RED | P09c | shared-sphere-cut-graph-failure-observed | ../../Directional/Directional/tests/FieldAlignedCurveNetworkTests.cpp:17295: Failure \| Value of: fixture.cutGraph.has_value() \| Actual: false \| Expected: true \| prescribed sphe | `13275b65dc9cb1aa…` |
| 350 | `SurfaceCutGraph.OrdinaryProposalSelectsTraceCrossedEdgeWithoutSaturation` | RED | P09b | ordinary-crossed-edge-proposal-structurally-excluded;AK4-heuristic-owner | ../../Directional/Directional/tests/FieldAlignedCurveNetworkTests.cpp:10924: Failure \| Value of: certificate.saturationUsed \| Actual: true \| Expected: false \| the selected trac | `28c197c999f0fee3…` |
| 354 | `SurfacePhaseFrontProductFactoryAuthority.HardRailTransitionNeedsExactlyTwoSourceFaceIncidences` | RED | P04b | setup-precondition-proven | unknown file: Failure \| C++ exception with description "compute_edge_quantities(): DCEL consistency check failed" thrown in the test body. | `2f5f318674e01098…` |
| 360 | `UniformPhaseFront/SurfaceCellDesignAcceptance.ProducesDirectSourceAuthoritativePureQuadOutput/BunnyRandom` | RED | P13 | cut-domain-Euler-mismatch-observed | ../../Directional/Directional/tests/SurfaceCellDesignAcceptanceTests.cpp:197: Failure \| Value of: independentOracle.ok() \| Actual: false \| Expected: true \| EmptyOutput:output v | `bc682b2d3b9b95ce…` |
| 362 | `UniformPhaseFront/SurfaceCellDesignAcceptance.ProducesDirectSourceAuthoritativePureQuadOutput/Cylinder` | ABNORMAL | P13 | timeout-unattributed | HARNESS_TIMEOUT 600s | `10fdd9c6d37043a3…` |
| 365 | `UniformPhaseFront/SurfaceCellDesignAcceptance.ProducesDirectSourceAuthoritativePureQuadOutput/Vase` | ABNORMAL | P13 | timeout-unattributed | HARNESS_TIMEOUT 600s | `6b3007665ed2e3ba…` |
| 373 | `SurfaceMeshOptimizerPhase19.FinalValidationPassesSectionFiveFixture` | RED | P14 | missing-boundary-authority-fixture-proven | ../../Directional/Directional/tests/SurfaceMeshOptimizerPhase19Tests.cpp:267: Failure \| Value of: report.accepted \| Actual: false \| Expected: true | `23c457a1bfad2e09…` |
| 375 | `SurfaceMeshOptimizerPhase19.FixedFeatureVertexRefreshesSourceTriangleProvenance` | RED | P14 | source-projection-label-omission-proven | ../../Directional/Directional/tests/SurfaceMeshOptimizerPhase19Tests.cpp:665: Failure \| Expected equality of these values: \| result.vertexProvenance[0].component \| Which is: -1  | `d0b07d94d71e8eb3…` |
| 385 | `SurfaceMeshOptimizerPhase19.ProjectsToSourceTrianglesWithProvenance` | RED | P14 | source-projection-label-omission-proven | ../../Directional/Directional/tests/SurfaceMeshOptimizerPhase19Tests.cpp:388: Failure \| Expected equality of these values: \| point.component \| Which is: -1 \| 0 | `ffed748fc3aa6c6d…` |
| 390 | `SurfaceMeshOptimizerPhase20.DirectDerivativesMatchFiniteDifferencesForEveryEnabledEnergy` | RED | P14 | gradient-projection-chain-rule-risk | ../../Directional/Directional/tests/SurfaceMeshOptimizerPhase20Tests.cpp:137: Failure \| Expected: (relative_gradient_error(direct, finiteDifference)) < (1.0e-6), actual: 0.0834940 | `341e937426ddaff8…` |
| 399 | `SurfaceMeshOptimizerPhase21.MixedOutputSheetAuthorityFailsClosed` | RED | P14 | metric-unscoped-projection-fallback-proven-strict-failclosed | ../../Directional/Directional/tests/SurfaceMeshOptimizerPhase21Tests.cpp:440: Failure \| Value of: std::isinf(report.quadToSourceMax) \| Actual: false \| Expected: true | `3bc07c8ce6d735cf…` |
| 401 | `SurfaceMeshOptimizerPhase21.PipelineStyleBoundarySingularitiesAcceptCompletedCloseSheetQuads` | RED | P14 | missing-boundary-authority-fixture-proven | ../../Directional/Directional/tests/SurfaceMeshOptimizerPhase21Tests.cpp:348: Failure \| Value of: validation.accepted \| Actual: false \| Expected: true | `6c6f75f7748298cd…` |
| 406 | `SurfaceMeshOptimizerPhase22.MultiRailChainReachesSelectedChartWithoutConsumingUnusedRelation` | RED | P14 | multi-rail-chart-fixture-order-defect-proven | ../../Directional/Directional/tests/SurfaceMeshOptimizerPhase22Tests.cpp:1056: Failure \| Value of: selected.valid() \| Actual: false \| Expected: true | `64d71b589e3d0c9b…` |
| 407 | `SurfaceMeshOptimizerPhase22.MultiRailChartReachabilityIsInvariantToSourceFaceRows` | RED | P14 | multi-rail-chart-fixture-order-defect-proven | ../../Directional/Directional/tests/SurfaceMeshOptimizerPhase22Tests.cpp:1379: Failure \| Value of: originalChart.valid() \| Actual: false \| Expected: true | `af648c9debe45f73…` |
| 408 | `SurfaceMeshOptimizerPhase22.MultiRailReciprocityMayBeCarriedOutsideTheSelectedFace` | RED | P14 | multi-rail-chart-fixture-order-defect-proven | ../../Directional/Directional/tests/SurfaceMeshOptimizerPhase22Tests.cpp:1078: Failure \| Value of: resolve_quad_chart(fixture, 0).valid() \| Actual: false \| Expected: true | `ca6cbc7be5788295…` |

#### Stop gate / pending evidence

- This turn has **not** completed the exact per-row cause adjudication. The ledger establishes one-to-one observations and working causal groups; source-first classification, falsifiers, patch proposals with exact targets, and retirement decisions remain required.
- **No** accepted selector or test/fixture implementation was altered. The proposed 916-row manifest is a draft and must not be dispatched by the test harness until repaired candidate tests are verified and Review freezes it.
- Next action: take one group at a time, independently inspect the relevant production/fixture source and raw log, record an exact classification and falsifier for each row, then freeze one corrective CB per proven shared cause. Distinct groups may be merged only if a common producer cause is proved; a failure-count coincidence is insufficient.

## `Architecture_M6_CP3_TB53_REV_Local_Gate_Platform_Attribution_RP01_Closure_20261030.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_TB53_REV_Local_Gate_Platform_Attribution_RP01_Closure_20261030.md`; moved verbatim.

### RA-179 — TB53 review: platform attribution of the local reds and RP-01 closure (2026-10-30)

**Turn:** `M6-CP3-TB53-RP01-FULL-GATE-REV` (TB-REV, Review track), run locally at the user's direction.

**Independence is reduced.** The same session wrote RA-178, built CB54 and ran TB53. To compensate, two read-only subagent traces and one subagent result audit were used, and every decisive claim below was recomputed from separately configured builds of the same source. Variant builds are diagnostic (GMP_COMPILE_POLICY), not gate authority.

#### RA-179.1 Evidence re-verified

- **TB53 result** `build/local-evidence/TB53/result.zip` (`5722887a…`):
  - The audit verifies 1,718/1,718 checksums and 855/855 manifest↔ledger↔log joins in order.
  - All 836 PASS logs contain `[  PASSED  ] 1 test.` and no FAILED line.
  - Membership is 938 = exactly the 855 manifest pairs plus the 83 ledger v3 pairs; the retired 261 is absent.
  - Rows 854 (223) and 855 (225) PASS.
- **Package** `21b7cf2d…`: built from source `2a49b873…`, the exact RA-178.7 patch (CB54 record).

#### RA-179.2 Attribution experiments

Both variants use the same source and the CI configure flags. The FMA instructions in the archived `FieldTransportAtlas.cpp.o` were counted with `otool -tv`: CB54 has 159; A and B have 0.

| Build | What changes | Rows run | Result |
|---|---|---|---|
| CB54 (TB53) | default (`-ffp-contract=on`) | 855 | 836 PASS; 18 vertex-35 reds + 283 |
| **A** | only `FieldTransportAtlas.cpp` built with `-ffp-contract=off` | the 19 reds, 854, 855, 86, 396, 397 | **23 PASS**; 283 RED |
| **B** | the whole build with `-ffp-contract=off` | all 855 | **854 PASS**; 283 RED |

- In all three builds, 283 throws the same `segment_arrangement(): surviving twin has invalid next`.
- **Evidence** (`build/local-evidence/TB53-REV/`, gitignored):
  - variant A verdicts `e3fc392d…`;
  - variant B verdicts `513e6d98…`;
  - logs `variant-logs.zip` `50499075…`;
  - runner `run_rows.py` `3a187e4b…`, which uses the frozen harness classifier.

#### RA-179.3 Findings

- **F1 — all 18 vertex-35 reds are O15 and nothing else.** FMA contraction in `FieldTransportAtlas.cpp` alone flips the `mechanical_feature` atlas decision (`SingularityPortClassCountMismatch` at vertex 35). Building that one file without contraction clears all 18. This confirms RA-176 F1 on the static, CI-configured build. These are not regressions: each row passed in TB52 on Linux, and no producer changed.
- **F2 — O15's row list was wrong (RA-176 used a literal grep).** RA-176 listed row 471, which uses `cp4c_torus_fixture()`. It missed:
  - 637 and 638, through `cp4c_mechanical_atlas_fixture()`;
  - 652 and 656, through `cp4c_mechanical_fixture()`.

  **Corrected list (21 gated rows):** 86, 396, 397, 445, 637, 638, 649, 650, 652, 653, 656, 658, 660, 662, 665, 669, 687, 784, 786, 787, 788. On the default macOS build, all of them fail except 86, 396 and 397.
- **F3 — row 283 is a pre-existing macOS-only legacy failure, not FMA.**
  - It fails identically in all three builds, and it already failed locally on 2026-10-28 (RA-170).
  - Its path is the default `LegacyInteger` backend → `NFunctionMesher::segment_arrangement` (`src/meshing/GenerateMesh.cpp:1102`), on an in-memory two-triangle square.
  - Its topology depends on double decisions: the angular order from `slope_function_double` (`:865–890`, with an exact fallback only below 1e-7), the outer-face test `signed_face_area < -1e-5` (`:1055`), and double inputs from integration.
  - The cause is unresolved. RA-176's "likely O15 sibling" is withdrawn. **Owner: O2** (legacy no-atlas retirement), which must retire this row along with the legacy path or establish the cause.
- **F4 — RA-178.2's FMA-off re-verification of 223 and 225 did not take effect.** It replaced the object file by hand, and ninja 1.13 rebuilt it with default flags (the same method left 159 FMA instructions here). Rows 854 and 855 are now verified under A and B, so RA-178's dispositions stand. **Method:** change one file's flags in the scratch `build.ninja` `FLAGS` line, and confirm the change in the archived object.

#### RA-179.4 Disposition

- **TB53 is accepted as the reviewed local (macOS arm64) candidate for source `2a49b873…`:** 836/19, with all 19 classified as platform failures (18 O15, 1 O2/legacy). There is no new stable event: 66/17/49, debt 1. TB52 853/0 remains the latest reviewed Linux candidate. selector497 is not promoted and CP3 is not accepted.
- **RP-01 is CLOSED.** RA-178.5's 855/855 criterion assumed Linux CI, so it is evaluated here under Linux-like arithmetic (variant B): 854/855, and the one red (283) is a legacy row outside RP-01's contract, owned by O2.
  - Rows 223 and 225 pass under FMA on, atlas-only off and global off.
  - Membership is exactly 938; 261 is retired; O9 is ruled (RA-178.3).
  - **Falsifier:** the first Linux CI gate of this source or later fails row 854 or 855 → RP-01 reopens.
  - **Carried:** a Linux confirmation run of TB53 when CI or the implementation agent is available. It does not block.
- **Local-mode convention, until O15 is discharged:**
  - Local CB packages are built with `CMAKE_CXX_FLAGS=-ffp-contract=off` and `CMAKE_C_FLAGS=-ffp-contract=off`, recorded in `command-boundary.txt` as `platform=…-nofma`, so that local gates match Linux arithmetic.
  - TB outcome tables pre-register row 283 as a known legacy platform failure (O2).
  - The default (FMA) build remains O15's red-first witness.

#### RA-179.5 Turn sequence

| Step | Turn | Type / track | Exit |
|---|---|---|---|
| done | CB54 → TB53 → TB53-REV (RA-179) | CB, TB-EXEC (local); TB-REV / R | RP-01 closed |
| **NEXT** | `M6-CP3-DEFN-A3-ATLAS-EXACT-SECTOR-PREDICATES` | DEFN / R | O15 inventory and exact patch (RA-176.3). Red-first evidence: the 18 rows fail on the default macOS build and pass after the patch, plus the vertex 10/35/47/71 exact oracle. The witness for row 935 is then defined. |
| then | CB55 (exact predicates) → CB56 (row 935 witness) → TB54 → TB54-REV | CB, TB / I or local; TB-REV / R | O15 discharged; ledger v4 (82) |
| then | `M6-CP3-DEFN-POSTRP01-O2-NO-ATLAS-INGRESS` (now also row 283) → P13 probe DEFN (Cylinder first; exact-atlas and route-step checks) → FIXTURE / PRODUCT / OPEN slices → CP3-REV | per slice | CP3 exit (RA-174.3 + RA-176.3 + RA-178.3) |
| carried | TB53 Linux confirmation (CI) | TB-EXEC / I | RP-01 falsifier |

## `Architecture_M6_CP3_DEFN_O2_No_Atlas_Entry_Gate_20261031.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_DEFN_O2_No_Atlas_Entry_Gate_20261031.md`; moved verbatim.

### RA-183 — O2: no-atlas A4 ingress (2026-10-31)

**Turn:** `M6-CP3-DEFN-POSTRP01-O2-NO-ATLAS-INGRESS` (DEFN, Review track), run locally. The ID frozen in RA-160.4 ended in `-RETIREMENT`; that suffix is dropped under the RA-167.6 naming rule.
- **Authority:** [RA-160.4](#architecture_m6_cp3_defn_legacy_matching_path_disposition_review_decision_20261026md "moved: Architecture_M6_CP3_DEFN_Legacy_Matching_Path_Disposition_Review_Decision_20261026.md") and RA-161 T2. O4 folds into O2. [RA-179 F3](#architecture_m6_cp3_tb53_rev_local_gate_platform_attribution_rp01_closure_20261030md "moved: Architecture_M6_CP3_TB53_REV_Local_Gate_Platform_Attribution_RP01_Closure_20261030.md") covers row 283.
- **Method:** probes are diagnostic only. Source is CB56 `567d1828…`, unchanged in `src/`, `include/` and `tests/` at HEAD. A Sonnet subagent produced the read-only consumer inventory; a Haiku subagent compared the runs; the Review agent probed and ruled.

#### RA-183.1 Inventory (verified at HEAD)

- **Production always supplies an atlas.**
  - The only `build_surface_cell_network` call is `RemeshPipeline.cpp:13122`. The atlas is set at `:12985` after a successful build, and atlas failures return earlier (`:12977`, `:12993`).
  - The only other production tracing call is `trace_surface_field(crossField)` at `FlowRepStrands.cpp:3511`, reached with the same options. With an atlas, the legacy containers are ignored (`SurfaceCellTracing.cpp:5482`, `:6720`).
- **Without an atlas, the A4 builder takes three paths:**
  - a produced phase front: the checked factory rejects at `atlas-binding` (`:8462–8469`). Gated row 232 (`selector:190`) pins this.
  - a rejected phase front: an early return.
  - **NotApplicable** (every region declined; the no-feature fallback at `:18490`): `publish_phase_front_result` returns `not_applicable()` (`:13167`). The seed fallback (`:20707–20720`) and the singular separatrices (`:21182`) then publish seeds, traces and proposals **decided by legacy matching**. This is D2.
- **Probe (bounded) of the builder with no atlas and no features:**

  | Input | Result |
  |---|---|
  | unit square; 5-, 6- and 8-triangle fans | already reject at `atlas-binding`, with empty outputs |
  | **closed** tetrahedron, octahedron, cube | **NotApplicable**, publishing 4/6/8 seeds, 16/24/32 traces and 4/6/8 proposals |

- **D5 (periodic identity fall-through, `:14946–14989`)** is reachable only without an atlas. Every such path is rejected before anything is published (see RA-183.2), so the identity default never decides a published output (RA-161 T2).
- **Legacy branches in the detail functions** (`resolve_branch_transition` `:6798–6818`, plus the derived containers at `:12016`, `:12569`, `:16243` and `:18083`) are reached by:
  - 12 gated unit tests that call `detail::resolve_*` directly: rows 220–224, 275 and 777–781;
  - the public container overloads (D3);
  - historical tests that are not built (`DIRECTIONAL_BUILD_HISTORICAL_TESTS=OFF`).

  They are not reached from production or from the builder once the gate is in place.

#### RA-183.2 Rulings

- **D2 and D5: fix with one entry gate.** In `publish_phase_front_result`, a NotApplicable phase front with no atlas is rejected with the checked factory's own failure:
  - `PublishedProductRejected` / `InvalidSourceAuthority` / `AtlasSourceMismatch` / `"atlas-binding"`.

  After the gate, every no-atlas builder path ends at the single locus that row 232 pins, with nothing published, and the separatrix code sits behind the same early return. With an atlas, behaviour is unchanged.
- **T2 is discharged.** No no-atlas path publishes anything, so a silent identity fallback is unobservable.
- **D3 and the detail legacy branches → O2b (carried; not CP3-blocking).** Retiring the public no-atlas container and `crossField` tracing APIs, the legacy branches, their 12 gated unit tests and the historical suite is a separate retirement slice. Production is unaffected today. Owner: a retirement DEFN after P13.
- **Row 283 → O16 (new; not O2; not CP3-blocking).** The test is in the default `LegacyInteger` NFunctionMesher backend (`GenerateMesh.cpp:1102`), not the SurfaceCells A4 ingress. It fails only on macOS arm64 and identically without FMA (RA-179); CP3 is evaluated on Linux CI, where it passes. The legacy backend is outside the SurfaceCells exactness amendments. Owner: a legacy-backend determinism probe DEFN, after M6 or when local mode needs it. Local outcome tables keep it pre-registered.
- **O4** (the `MissingTransitionProvenance` same-call guards) stays accepted-defensive (RA-170.3).

#### RA-183.3 Probe evidence for CB57

Builds are local CB56 source plus the CB57 patch, default arithmetic.

| Check | Before the gate | With the gate |
|---|---|---|
| New `NoAtlasNotApplicableInputRejectsBeforeLegacySeedFallback` (closed cube, no atlas) | **FAIL** (disposition NotApplicable, 8 seeds) | PASS |
| Row 232 (`LegacyMatchingPathUsesSameTypedAlgebra`) | PASS | PASS |
| Full gate, 858 rows | 857/858 (TB55) | 857/858, verdicts identical by row (only 283) |
| 82 deferred rows | 81 RED / 1 PASS (362) | identical verdicts; the same first-failure assertions, with 11 lines shifted only by inserted tests (+14 from CB55's test, +63 from CB57's test) |

#### RA-183.4 CB57 — exact patch

**Turn:** `M6-CP3-CB57-O2-NO-ATLAS-ENTRY-GATE` (CB), run locally; Code + Build.
- **Scope:**
  - `src/geometry/SurfaceCellTracing.cpp`: the NotApplicable no-atlas gate, `13 0`.
  - `tests/SurfaceCellsPhase10Tests.cpp`: the failing-first test, `63 0`.
- **Checks:**
  - The RA-183.7 block, extracted verbatim with a trailing newline, has SHA-256 `35eb2fbcb2196b8af934b9a57a7dd5d60d28e2a3d900a315626e9d52ab9644d6`.
  - `git apply --check`, then apply; the numstat must be exactly `13 0` and `63 0`.
  - The resulting SHA-256 must be `c0b753ae0b247063e5c6f426575cbd8a5a13aa804c9d93ab8965caa15457cdb3` (SurfaceCellTracing) and `12e42b5ab8399da4a3a4bf1a2edfb3b41ae0d2f7126648c256febfad31dc3478` (Phase10).
  - Build the eight targets at default arithmetic and stage the package. No native tests.

| CB57 result | Successor |
|---|---|
| All exact, package built | `M6-CP3-TB56-O2-FULL-GATE-EXEC` |
| Mismatch | `M6-CP3-PLAN-O2-ENTRY-GATE-STOP` (PLAN, R) |
| Infrastructure failure | `M6-CP3-CB57A-O2-ORCH`, then one retry |

#### RA-183.5 TB56 frozen inputs

- **Gate:** [`Architecture_M6_CP3_TB56_O2_Full_Gate_Case_Manifest.tsv`](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_TB56_O2_Full_Gate_Case_Manifest.tsv"), 859 rows, SHA-256 `c8437d61e5b9a12d37bcd9d026dc859ee7954e56eaf904f193d8b2a549a2097f`. The first 859 lines are TB55 (`eb508378…`); row 859 is `GUARD ra183:o2-no-atlas-not-applicable` (producer binary).
- **Ledger:** v4 is unchanged (82, `36241caa…`).
- **Checks run:** `--self-check` gives `SELF_CHECK_PASS cases=859 deferred=82`. The real membership check of the patched binaries gives **941**.

| TB56 result (local) | Successor |
|---|---|
| 858/859 PASS, with row 283 (O16) the only RED, postflight true, membership 941 | next turn per RA-183.6; no separate REV |
| Any other non-PASS | `M6-CP3-TB56-O2-FULL-GATE-REV` (R) |
| Membership error | `M6-CP3-PLAN-O2-MEMBERSHIP-STOP` (PLAN, R) |

#### RA-183.6 Turn sequence

| Step | Turn | Type / track | Exit |
|---|---|---|---|
| NEXT | `M6-CP3-CB57-O2-NO-ATLAS-ENTRY-GATE` → `M6-CP3-TB56-O2-FULL-GATE-EXEC` | CB, TB-EXEC / local | 858/859, with only 283 red |
| then | `M6-DEFN-DIAG-RETAIN-A5-A7` (user-directed diagnostics; RA-160.4 sequencing is satisfied now that RP-01 is closed) | DEFN / R | DIAG-RETAIN slices |
| then | P13 probe DEFN (Cylinder first, which passes locally in 179 s; O6; exact-atlas, route-step (O9) and continuation-width (O15c) checks) → FIXTURE / PRODUCT / OPEN slices → CP3-REV | per slice | CP3 exit |
| carried | O2b (no-atlas API and legacy-branch retirement), O15b, O15c, O16 (row 283); Linux CI confirmation of rows 854–859 | — | — |

#### RA-183.7 Exact CB57 patch

~~~diff
diff --git a/src/geometry/SurfaceCellTracing.cpp b/src/geometry/SurfaceCellTracing.cpp
index 86ac4f10c..c90a56ed0 100644
--- a/src/geometry/SurfaceCellTracing.cpp
+++ b/src/geometry/SurfaceCellTracing.cpp
@@ -13165,6 +13165,19 @@ SurfacePhaseFrontResult publish_phase_front_result(
     const SurfaceHardRailClosedChains &hardRailClosedChains,
     const SurfaceHardRailOpenChains &hardRailOpenChains) {
   if (state.disposition == SurfaceCellProducerDisposition::NotApplicable) {
+    // Without an A3 atlas the seed fallback would publish outputs decided by
+    // legacy matching (RA-160 D2). Reject at the checked factory's binding
+    // locus instead, as a produced phase front without an atlas is (RA-183).
+    if (fieldTransportAtlas == nullptr) {
+      state.failure.reason =
+          SurfacePhaseFrontFailureReason::PublishedProductRejected;
+      state.failure.publishedProductError =
+          SurfacePhaseFrontProductErrorCode::InvalidSourceAuthority;
+      state.failure.publishedProductSourceAuthorityDetail =
+          SurfacePhaseFrontSourceAuthorityDetail::AtlasSourceMismatch;
+      state.failure.publishedProductSourceAuthoritySite = "atlas-binding";
+      return SurfacePhaseFrontResult::rejected(std::move(state.failure));
+    }
     return SurfacePhaseFrontResult::not_applicable();
   }
   if (state.disposition == SurfaceCellProducerDisposition::Rejected) {
diff --git a/tests/SurfaceCellsPhase10Tests.cpp b/tests/SurfaceCellsPhase10Tests.cpp
index 4dc7f07fb..e30db35fa 100644
--- a/tests/SurfaceCellsPhase10Tests.cpp
+++ b/tests/SurfaceCellsPhase10Tests.cpp
@@ -5351,6 +5351,69 @@ TEST(SurfaceCellPeriodicHolonomyRouteTransportAuthorityMigration,
   EXPECT_TRUE(rejected.proposals.empty()) << detail.str();
 }
 
+// O2 (RA-183): a closed feature-free input leaves every region NotApplicable.
+// Without an A3 atlas the seed fallback would publish seeds, traces and
+// proposals decided by legacy matching; A4 must reject at the same
+// atlas-binding locus as a produced phase front without an atlas.
+TEST(SurfaceCellAuthorityContractCutover,
+     NoAtlasNotApplicableInputRejectsBeforeLegacySeedFallback) {
+  Eigen::MatrixXd vertices(8, 3);
+  vertices << 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0,
+              0, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1;
+  Eigen::MatrixXi faces(12, 3);
+  faces << 0, 2, 1, 0, 3, 2, 4, 5, 6, 4, 6, 7, 0, 1, 5, 0, 5, 4,
+           1, 2, 6, 1, 6, 5, 2, 3, 7, 2, 7, 6, 3, 0, 4, 3, 4, 7;
+  directional::fields::CrossFieldResult field;
+  field.degree = directional::fields::kCrossFieldDegree;
+  field.primaryDirections.resize(faces.rows(), 3);
+  field.secondaryDirections.resize(faces.rows(), 3);
+  for (int face = 0; face < faces.rows(); ++face) {
+    field.primaryDirections.row(face) = Eigen::RowVector3d::UnitX();
+    field.secondaryDirections.row(face) = Eigen::RowVector3d::UnitY();
+  }
+  std::map<directional::authority::SourceEdgeTopologyKey, int> incidence;
+  for (int face = 0; face < faces.rows(); ++face)
+    for (int corner = 0; corner < 3; ++corner)
+      ++incidence[test_source_edge_topology(faces(face, corner),
+                                            faces(face, (corner + 1) % 3))];
+  const auto interior = static_cast<int>(std::count_if(
+      incidence.begin(), incidence.end(),
+      [](const auto &entry) { return entry.second == 2; }));
+  field.matching = Eigen::VectorXi::Zero(interior);
+  field.effort = Eigen::VectorXd::Zero(interior);
+  field.matchingComputed = true;
+  field.singularitiesComputed = true;
+  directional::geometry::SurfaceCellTracingOptions options;
+  options.sourceFaceComponents.assign(static_cast<std::size_t>(faces.rows()), 0);
+  options.sourceFaceSheets.assign(static_cast<std::size_t>(faces.rows()), 0);
+  options.fieldTransportAtlas = nullptr;
+  options.sourceAuthority = nullptr;
+  const Eigen::VectorXd targetSize = Eigen::VectorXd::Constant(vertices.rows(), 0.25);
+
+  const auto rejected = directional::geometry::build_surface_cell_network(
+      vertices, faces, field, targetSize, options);
+  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Rejected,
+            rejected.phaseFront.disposition());
+  EXPECT_EQ(directional::geometry::SurfacePhaseFrontFailureReason::
+                PublishedProductRejected,
+            rejected.phaseFront.rejection_reason());
+  const auto *failure = rejected.phaseFront.rejection();
+  ASSERT_NE(nullptr, failure);
+  EXPECT_EQ(std::make_optional(
+                directional::geometry::SurfacePhaseFrontProductErrorCode::
+                    InvalidSourceAuthority),
+            failure->publishedProductError);
+  EXPECT_EQ(std::make_optional(
+                directional::geometry::SurfacePhaseFrontSourceAuthorityDetail::
+                    AtlasSourceMismatch),
+            failure->publishedProductSourceAuthorityDetail);
+  EXPECT_EQ("atlas-binding", failure->publishedProductSourceAuthoritySite);
+  EXPECT_EQ(nullptr, rejected.phaseFront.produced_product());
+  EXPECT_TRUE(rejected.seeds.empty());
+  EXPECT_TRUE(rejected.traces.empty());
+  EXPECT_TRUE(rejected.proposals.empty());
+}
+
 TEST(SurfaceCellsPhase10,
      ExactCommittedTorusDoesNotTreatIsolationSeamAsBoundedDiskBoundary) {
   const auto meshPath = directional::tests::benchmark_fixture_path(
~~~

## `Architecture_M6_CP3_TB54_REV_O15_Discharge_20261031.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_TB54_REV_O15_Discharge_20261031.md`; moved verbatim.

### RA-181 — TB54 review: O15 discharged (2026-10-31)

**Turn:** `M6-CP3-TB54-O15-FULL-GATE-REV` (TB-REV, Review track), run locally.

**Independence is reduced.** The same session defined, built and ran O15's fix. To compensate:
- a Sonnet subagent did a read-only correctness review of the committed atlas;
- a Haiku subagent did the result audit and the mechanical run comparison;
- the decisive equivalence claim was recomputed from a separately configured FMA-free build of the exact CB55 source.

Variant builds are diagnostic only (GMP_COMPILE_POLICY).

#### RA-181.1 Evidence re-verified

- **TB54 result** `build/local-evidence/TB54/result.zip` (`706f4ce7…`): 857 executed, 856 PASS, row 283 RED, membership 940, postflight true. The Haiku audit verifies 1,722/1,722 checksums and 857/857 manifest↔ledger↔log joins; the 940 membership pairs are exactly the manifest plus ledger v3. ([TB54 report](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_TB54_O15_Full_Gate_Local_Test_Report_20261031.md").)
- **FMA-free diagnostic** of source `04027167…` (atlas object with 0 FMA instructions): 857 rows give 856 PASS, with only 283 red. The verdicts equal TB54 row by row (0 mismatches). The 4,797 atlas partition records are byte-identical to TB54 (`65824e4b…`). Row 857 shows 3/3/3/3 at vertices 10, 35, 47 and 71 in both modes. Evidence: `build/local-evidence/TB54-REV/` (gitignored).
- **Source review (Sonnet):** T1, T2 and T3 at `04027167` are correct.
  - The gauge comparator is a strict weak order by counter-clockwise angle in [0, 2π), and its tie check means "same angle".
  - `u` and `v` solve the Gram system exactly.
  - The representative ratio order is monotone in angle, and the vertex indexing is consistent.
  - No float or tolerance decision is left at an exact topological tie; only conditioning guards and the near-integer lift check remain.

#### RA-181.2 RA-176.3 discharge conditions

| Condition | Evidence | Met |
|---|---|---|
| Every A3 topological decision is exact, with a recorded tie rule | RA-180.2 rule; source review | Yes |
| `mechanical_feature` outcome is identical with `-ffp-contract` on and off | identical 3/3/3/3 and partitions on CB55's source | Yes |
| A failing-first witness fails before the patch on Linux-like arithmetic | row 856 FAILS on a pre-patch FMA-free atlas (RA-180.3) | Yes (Linux-like; CI not run) |
| An exact oracle test at vertices 10/35/47/71 | row 857 PASS | Yes |
| An outcome table for changed gate rows | RA-180.6, met by TB54 | Yes |

**Decision: O15 is DISCHARGED** on local evidence. A Linux CI confirmation is carried together with RP-01's (the first CI gate of this source or later must pass rows 856 and 857). TB54 (857, 856/1) is the reviewed local candidate. Row 283 stays **O2** (the same `segment_arrangement` signature). There is no new stable event: 66/17/49, debt 1. selector497 is not promoted and CP3 is not accepted.

#### RA-181.3 Findings and carried items

- **F1 — O15c (new, carried; quantified risk, fail-closed).** Exact directions enlarge exact trace parameters. In row 669's census, the maximum trace-parameter width grew:

  | Witness | Before | After |
  |---|---|---|
  | genus_two | 107 bits | 217 bits |
  | sphere_prescribed | 429 bits | 1,531 bits |

  - The A4 continuation bound is 4,096 bits (`kFieldExactContinuationMagnitudeBits`). Beyond it, A4 declines with `BranchContinuationExactMagnitudeExceeded` and never picks a wrong topology.
  - The growth is intrinsic: the reduced exit point depends only on the exact component ratio, so rescaling the direction cannot shrink it.
  - Every gated and deferred row is within budget.
  - **Owner:** the P13 probe DEFN records the maximum continuation width on each design-matrix fixture.
  - **Falsifier:** any `BranchContinuationExactMagnitudeExceeded`, or a width above 50% of the bound, triggers a DEFN that chooses between a revised bound and a deterministic correctly-rounded direction with exact zero and sign handling.
- **F2 — vestigial code (noted, not changed; surgical-change rule):**
  - `canonicalDirections` values are now only size-checked;
  - `reference` is only a degeneracy guard;
  - the double `det` guard sits in front of the exact one;
  - the exact primary-versus-secondary tie reject is shadowed by the 1e-8 near-parallel guard.

  All of this is deterministic and harmless; it is cleanup material for a later refactor.
- **O15b** (the tie in the fields-stage matching argmin) stays carried to CP3-REV.

#### RA-181.4 Turn sequence

| Step | Turn | Type / track | Exit |
|---|---|---|---|
| done | RA-180 → CB55 → TB54 → TB54-REV (RA-181) | DEFN, TB-REV / R; CB, TB local | O15 discharged |
| **NEXT** | `M6-CP3-DEFN-API-DISPLAY-VERTEX-STOP-WITNESS` | DEFN / R | Construct an input that a stage legitimately rejects with a source-vertex locus (RA-180.4), and freeze CB56 for row 935 |
| then | CB56 → TB55 → TB55-REV | CB, TB local; TB-REV / R | Row 935 moves to the gate (ledger v4, 82) |
| then | `M6-CP3-DEFN-POSTRP01-O2-NO-ATLAS-INGRESS` (+ row 283) → P13 probe DEFN (Cylinder first; exact-atlas, route-step and **continuation-width (O15c)** checks) → slices → CP3-REV | per slice | CP3 exit |
| carried | Linux CI confirmation of TB53/TB54 (rows 854–857) | TB-EXEC / I | RP-01 and O15 falsifiers |
