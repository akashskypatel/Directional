# Architecture M6 CP2 TB1 Verifier Review Record

**Turn:** `M6-CP2-TB1-VERIFIER-REV`
**Disposition:** **REJECTED FOR BOUNDED RECOVERY / THREE EXEC REDS ARE FALSE-REJECTION WITNESSES / FOUR STATIC CONTRACT GAPS / NO PROMOTION**
**Reviewed candidate:** artifact `11365308211`, semantic source `265c8fbb19a66c5c3344a525fdbd43932c3ef829`
**Runtime evidence:** run/job `37368784487 / 111962223674`, result `11370598981`, log `11370413984`
**Mechanical gate:** focused30 `30/30`, CP2-focused12 `9/12`, selector449 `449/449`, total `488/491`
**Accounting:** `60 events / 16 categories / 44 recurrences`, debt 1. No accepted-green row regressed.

## 1. Independent evidence verdict

The artifact-only execution is mechanically valid. All 491 frozen exact-filter processes ran once, selected exactly one test, skipped none, ran zero benchmarks, and left the immutable package/source/execution view unchanged. The run-level failure is mailbox-only: validator and runtime jobs succeeded and the result/log artifacts were uploaded before the mailbox job was cancelled. The candidate is nevertheless **not promotable** because three focused-12 rows are RED and independent static review finds additional RA-28a contract omissions.

## 2. Adjudication of the three EXEC candidates

### CAND-01 — FALSE REJECTION / TEST-WITNESS AUTHORITY DEFECT / NON-STABLE

`M6CP2.VerifierRecomputesA0AndA5ElementaryIncidenceIndependently` swaps two corners of one source triangle. `SourceFaceTopologyKey::make` canonicalizes by sorting the three source vertex IDs, so the row still denotes the same source-face topology. The expected `SourceIncidenceMismatch / a0:source-faces` precondition is never created.

**Recovery:** alter one vertex so the canonical topology key actually changes while remaining a valid triangle, and assert `sourceAuthority.matches_source_faces(...) == false` before calling the verifier. Then require the exact A0 finding.

### CAND-02 — FALSE REJECTION / TEST-WITNESS AUTHORITY DEFECT / NON-STABLE

`M6CP2.CertificateChainRequiresExactA5A6A7PayloadBinding` resets `selectedRelationStep` on the first `OrdinaryFront` certificate. Production already resets that optional field for `OrdinaryFront`, so the tamper is a no-op.

**Recovery:** tamper an always-bound field, preferably `relationTransport`, after asserting the baseline certificate equals the cited A5 `canonicalTransport`; mutate the transport and assert inequality before verifier invocation. Require exact `CertificatePayloadMismatch / a6:a5-binding`.

### CAND-03 — FALSE REJECTION / TEST-FIXTURE NON-VACUITY DEFECT / NON-STABLE

`M6CP2.WeldPinchedRecordViewFailsIndependentManifoldness` searches the one-square fixture for two classed cells with disjoint quotient-corner sets. No such pair exists, so `tampered` remains false and the verifier is never called on the intended pinched topology.

**Recovery:** use a produced fixture with two disconnected/disjoint classed-cell components (the existing overlap fixture is an accepted candidate), assert the disjoint pair exists, weld one quotient corner across the pair, then require `NonManifoldTopology / a6:vertex-link`.

These three REDs are not stable regressions. They are failed negative witnesses on new CP2 gate authority.

## 3. Static contract gaps discovered by Review

### REV-OBS-01 — RA-28a §6 pipeline result does not carry the verified report — RECOVERY REQUIRED

`build_authoritative_phase_front_mesh_with_hard_features` obtains `VerifiedSurfaceProducts`, projects them, and returns `AuthoritativePhaseFrontMeshResult`, but that result type contains no `VerificationReport`. Identity 11 only inspects `VerifiedSurfaceProducts::report()` directly. This does not satisfy RA-28a §6's behavioral requirement that **a pipeline result carries a verified report**.

**Recovery:** successful authoritative pipeline results must retain the exact A8 `VerificationReport` that authorized projection; do not synthesize a new empty/green report after projection. Reorder declarations if needed to carry `std::optional<VerificationReport>` (or semantically equivalent exact report carrier). Identity 11 must call the full pipeline and assert the returned report is present, verified, and is the report produced before projection.

### REV-OBS-02 — RA-28a §8 wrong-region identity does not prove an A0-valid alternate region — RECOVERY REQUIRED

Identity 8 constructs `TopologyRegionId(current.index()+1)` through a test helper whose extent is synthetic. It proves only type construction and inequality; it does not prove the replacement ID belongs to the fixture's `SourceTopologyRegions`. RA-28a §8 explicitly freezes a **valid** alternate topology region.

**Recovery:** use a produced fixture with at least two A0 regions and a bridge witness, or a dedicated produced fixture. Assert both the original and replacement IDs occur in `sourceAuthority.regions()`, assert they differ, keep both sheets in-set, republish A5, require fresh A6 success, then require exact A7 `UncertifiedCrossSheetBinding / cross-sheet:wedge`.

### REV-OBS-03 — RA-28a §3 shared source-support kernel is bypassed — RECOVERY REQUIRED

The verifier uses local `verification_support_incident_to_face/edge` helpers. RA-28a §3 requires exact A0 support incidence **through the shared source-support kernel**. A5 already derives support with `geometry::SurfacePointSourceSupportResolver`, and every published occurrence carries the source `point`.

**Recovery:** in the A5-incidence partition instantiate/use the shared `SurfacePointSourceSupportResolver` over A0 source faces, resolve each published occurrence point, and require the resolved identity to equal the published support before wedge/seam incidence checks. Local duplicated support classification must not be the sole authority. Identity 2 must include a non-vacuous support/point mismatch that only passes when the shared kernel agreement is checked. No A5 producer routine may be called.

### REV-OBS-04 — RA-28a §1.4 selected-path verifier does not prove the path is the published forest path — RECOVERY REQUIRED

The verifier composes the certificate IDs and orientations listed in each `selectedPath`, but it does not independently prove those ordered relations/orientations equal the unique traversal in the published `selectedForest`. Production validation does perform that stronger check via `quotient_forest_path`. A self-consistent but unrelated certificate list can therefore satisfy the verifier's composition check while violating the frozen phrase “along the class's published selected path.”

**Recovery:** independently traverse the **published forest** inside the verifier (no producer routine), derive the unique root→target relation/orientation sequence, and require exact equality with `orderedRelations` and `traversalOrientations` before using it for transport composition. Require one selected path per non-root class member, exact root/target/class membership, and exact path cardinality. Extend identity 6 with a tamper that preserves a plausible composed transport but breaks forest-path relation/orientation identity; require `QuotientMembershipMismatch` for path structure or `NamedTransportMismatch` only for transport disagreement after structure is valid.

## 4. Review verdict and recovery boundary — RA-29

The candidate is **REJECTED FOR BOUNDED RECOVERY**. No production runtime is promoted. The three EXEC REDs remain non-stable test authority defects, while REV-OBS-01/03/04 are production verifier/API contract omissions and REV-OBS-02 is a latent test-witness defect. None reprices the stable regression ledger because no accepted-green identity regressed.

The only authorized successor is `M6-CP2-CB1-VERIFIER-R2` under `Architecture_M6_CP2_CB1_Verifier_R2_Recovery_Code_Build_Plan.md`, followed by fresh immutable `M6-CP2-TB1-VERIFIER-R1-EXEC` (**491**) and mandatory `M6-CP2-TB1-VERIFIER-R1-REV`. No test-only shortcut, selector reduction, promotion, or runtime retry against the old package is authorized.


## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | focused30 `1e815443a03c7ef4a1b095e6ea973efa9c74bb0eae4e2f872510c97d057ea1d6`; CP2-focused12 `2aa57aac48ac8c41ea86ed459cdd1acd27eb17c8d3dbe1b4ac7b9c54c67374ed`; selector449 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`; routing449 `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707`. No selector bytes changed. |
| Decisive claims independently re-derived | Re-opened exact source and runtime evidence; re-derived all three false-rejection roots and the four static RA-28a gaps from the bytes rather than from the EXEC narrative. |
| Non-vacuity checked | CAND-01/02 are canonical/no-op tampers; CAND-03 never constructs the malformed topology. RA-29 requires explicit pre-verifier non-vacuity assertions for each recovery witness. |
| Prior obligations discharged/carried | RA-28a/RA-28b verifier obligations adjudicated here. CAND-01..03 and REV-OBS-01..04 carried only to `M6-CP2-CB1-VERIFIER-R2`; `M6-DEFN-R5` remains after CP2. |
| Stable accounting | `60 / 16 / 44`, debt 1. Candidate `11365308211 / 265c8fbb...` remains unpromoted; accepted reviewed runtime remains `11330703256 / 3f40f04a...` until an R1 Review promotes a replacement. |
| New candidates/obligations recorded | CAND-01/02/03 adjudicated false-rejection/non-stable; REV-OBS-01..04 added to `Regression_Root_Cause_Tracker.md`, owned by R2. |
| ORIENTATION currency line | `M6-CP2-TB1-VERIFIER-REV`, 2026-10-05, candidate rejected; R2 exact next. |
| ORIENTATION §3 / §4 / §7 / §8 | §3 and §7 updated to CP2 R2 recovery; §4 has no milestone witness-state change (test-fixture defects only); §8 records a new instance of the existing non-vacuity/canonical-witness pattern. |
| CHANGELOG | Review rejection / RA-29 entry added. |
| ROADMAP | Live M6 routing updated to R2 recovery then fresh 491-process R1 EXEC + Review. |
| Selector manifest | n/a — no selector added, removed, reordered or newly accepted. |
| LESSONS | No new lesson; existing lesson 10 (non-vacuity must prove the witness can satisfy its precondition) governs the three failed negative witnesses. |
| Consolidation under CLEAN_UP_POLICY | CP2 Definition plan/record/Review and superseded CB1 verifier plan/stop-review/build-report folded into `M6_Consolidated_Record.md` §53 + folded-document index; current TB report, current Review, R2 plan, frozen definitions and selectors retained. |
| Successor frozen | Exactly `M6-CP2-CB1-VERIFIER-R2`; falsifiers and stop rules are frozen in `Architecture_M6_CP2_CB1_Verifier_R2_Recovery_Code_Build_Plan.md` and RA-29. |
| Turn boundary held | runtime-free Review; no product, test, fixture, selector, benchmark or build-source mutation. |
| review_check.py boundary | PASS; selector449 declared hash matched and no product/test/fixture/build/selector mutation was detected. |
| `STATUS` lifecycle maintained | Entry and resume beacons maintained; COMPLETE beacon is the final repository mutation after documentation/cleanup. |
| Pushed to origin, branch in sync | Repository patch application and cleanup are verified at remote branch authority before the final COMPLETE beacon; no ahead/behind local branch is used as authority in ChatGPT Web. |
