## CURRENT — TB50C-R2 census complete; off-selector DEFN next (2026-10-29)

- [x] **`M6-CP3-TB50-RP01-FULL-GATE-REV`** (TB-REV) COMPLETE per [RA-171](.agents/Directional/Architecture_M6_CP3_TB50_REV_Gate_Closeout_Census_Observe_Harness_20261029.md).1–.2.
  - CB50–CB52 are byte-identical to P3–P6 applied to RA-170.
  - TB50-R2 independently verified: artifact `12929917136`, 1022/1022 checksums, 508/508 manifest–ledger–log joins, source = HEAD.
  - 508/0 is the reviewed candidate gate. CB50A's `-` site cells are sound, since the sites stay asserted in-test.
- [x] `M6-CP3-TB50C-RP01-OFF-GATE-CENSUS-EXEC`: S5, 0/408 ([report](.agents/Directional/Architecture_M6_CP3_TB50C_Off_Gate_Census_Orchestration_Failure_Report_20261029.md)). RA-171.3 root cause is a Review freeze defect: the name regex rejected `Prefix/Suite.Test/Param`, and GUARD semantics would have failed on any census RED.
- [x] RA-171.4: P7 adds the `OBSERVE` kind (PASS/RED/ABNORMAL as evidence; INVALID still fails; no mixing with gate rows), parameterized names, and `GetParam()` FAILED-line normalization. Probed: self-test 21/21, self-checks 504/508/408, real gtest logs. Census re-frozen `918239009ddee28e…` (kind/expect only).
- [x] `M6-CP3-CB50C-RP01-CENSUS-HARNESS-ORCH` (CB, I): exact P7 `9c30f6b6…`, numstat `71 8`, harness `600c6455…`, offline self-test 21/21 and self-checks 504/508/408. Applied in commit `9355721b67398a2e874f77eecfd61477d8bf9a76`, run 40962940548, no native runtime; [record](.agents/Directional/Architecture_M6_CP3_CB50C_RP01_Census_Harness_Orchestration_Record_20261029.md).
- [x] `M6-CP3-TB50C-RP01-OFF-GATE-CENSUS-EXEC-R2` (TB-EXEC, I): [run 40965775275](https://github.com/akashskypatel/Directional/actions/runs/40965775275), 408/408 OBSERVE, 323 PASS / 83 RED / 2 ABNORMAL / 0 INVALID; 822/822 artifact hashes; [detailed report](.agents/Directional/Architecture_M6_CP3_TB50C_RP01_Off_Gate_Census_R2_Test_Benchmark_Report_20261029.md). No classification.
- [ ] **NEXT** `M6-CP3-DEFN-RP01-OFF-SELECTOR-COVERAGE-DISPOSITION` (DEFN, R): classify every non-PASS row by first-failure group; exact patches; freeze the TB51 manifest = 508 + (408 − retired). Then CB53… → TB51-EXEC → TB51-REV → `M6-CP3-PLAN-RP01-CLOSURE`. Post-RP-01: `M6-CP3-DEFN-POSTRP01-O2-NO-ATLAS-INGRESS`, then `M6-DEFN-DIAG-RETAIN-A5-A7`.
- [ ] Carried separately:
  - O1, O6 and O7 (oracle-tests target does not compile).
  - O8 (`lengthRatio=0.29`) and O9 (A4 junction path unwitnessed; owns P1-a's `missing-terminal-A3-path`).
  - **O10:** non-hard isolation-barrier producer. **O11:** 5 off-gate TQ tests failing at HEAD. **O12:** R61 `review_check.py` selector collision. **O13:** `ProducedHardCarriersAreAtlasBarriers…` off-gate RED (all now inside the O5 census).
  - RA-152.5, DEFN-SEAM-NZ (+RA-163.4), RA-146.2/4, RA-45.4 and G4-B002.
- [ ] **Planned (user-directed, 2026-10-21; Review schedules it) — `DIAG-RETAIN`: keep A5–A7 products as diagnostic snapshots.**
  - Retain the A5 corner occurrences (support, placement, wedge bindings), the A5 occurrence relations (kind, endpoints, evidence), the A6 merged quotient classes and the A7 final vertex geometry in `SurfaceCellDiagnosticProductSnapshots` whenever `retainIntermediateGeometry` is set, including every product completed before a rejection.
  - Make them reachable from the GUI (display layers) and the CLI (a diagnostics dump) in those diagnostic contexts.
  - Constraints: one-way observations under the existing snapshot contract, never read back as stage authority; no admission, return-value or ordering change; bounded memory; nothing retained when retention is off.
  - Suggested turns: DEFN (snapshot types, retention point per stage, behaviour on rejection, memory bound) → one CB+TB per product (A5 occurrences and relations; A6 classes; A7 geometry), each with a no-read-back test → CLI dump → GUI layers. It edits `RemeshPipeline.cpp`, so Review must sequence it clear of RP-01 diagnostic and corrective turns.
- **Turn sequence:**
  - Done: CB50 (P3) → CB50F (P4) → CB51 (P5) → CB52 (P6) → TB50-EXEC S5 → CB50A-ORCH → TB50-EXEC-R2 (508/0) → TB50C-EXEC S5 → TB50-REV (RA-171) → CB50C-ORCH (P7).
  - **TB50C-EXEC-R2 COMPLETE** (408 census) → **DEFN NEXT** off-selector disposition → CB53… → TB51-EXEC → TB51-REV → PLAN-RP01-CLOSURE.
  - One CB per exact patch; implementation agents get only exact patches and frozen manifests; probe-requiring DEFN/TB-REV turns stay on the Review track.
  - **Naming (RA-167.6):** types per `turn_type_from_turn`; DEFN/PLAN IDs carry no `-CB<n>`/`-TB<n>` segment and no final R+letters qualifier. CB50C stop → `M6-CP3-PLAN-RP01-CENSUS-HARNESS-STOP`; CB50C orchestration → `M6-CP3-CB50CA-RP01-ORCH`; TB50C-R2 without a complete ledger → the same PLAN stop.
  - Rules: RA-164.3 P1–P6, RA-165.2 F1/F2, RA-166.6 F6/F7, RA-168 oracle rule, RA-169 masking rule, RA-170 (factory negatives pin a site; a gate pass says nothing about off-gate tests), RA-171 (Review self-checks every manifest against its harness before freezing; census rows are OBSERVE, never GUARD).
- Frozen:
  - Stable 66/17/49, debt 1; CP2 491/491 accepted.
  - TB50-R2 508/0 reviewed candidate; selector497 frozen; RP-01 open, RP-02 unreached; Gate C suspended.

---

## HISTORY — RA-170; CB50–CB52; TB50 S5; CB50A; TB50-R2 (2026-10-28/29)

- [x] [RA-170](.agents/Directional/Architecture_M6_CP3_TB49_REV_Reaudit_P1_O4_DEFNs_E2_Site_Pins_OffGate_Census_20261028.md): TB49 504/0 re-derived. P1-a accepted-defensive (O9); P1-b re-specified as P5; O4 accepted-defensive (→ O2); P6 factory site pins. C1 adds no off-gate regression (the same 101/408 local REDs at HEAD and patched).
- [x] CB50 (P3), CB50F (P4), CB51 (P5) and CB52 (P6) applied exactly; eight GMP targets compile-only ([CB50F](.agents/Directional/Architecture_M6_CP3_CB50F_RP01_C1_Factory_Rail_Cover_Code_Build_Record_20261029.md), [CB51](.agents/Directional/Architecture_M6_CP3_CB51_RP01_P1B_Network_Owner_Witness_Code_Build_Record_20261029.md), [CB52](.agents/Directional/Architecture_M6_CP3_CB52_RP01_E2_Factory_Site_Pins_Code_Build_Record_20261029.md)).
- [x] TB50-EXEC S5, 0/508 (site-pin schema; [report](.agents/Directional/Architecture_M6_CP3_TB50_RP01_Full_Gate_Orchestration_Failure_Report_20261029.md)) → CB50A-ORCH ([record](.agents/Directional/Architecture_M6_CP3_CB50A_RP01_Orchestration_Correction_Record_20261029.md), manifest `eef8855e…`) → TB50-EXEC-R2 **508/0** ([report](.agents/Directional/Architecture_M6_CP3_TB50_RP01_Full_Gate_R2_Test_Benchmark_Report_20261029.md), run 40941114716).

---

## HISTORY — RA-169; TB49-REV closeout; C1 DEFN (2026-10-28)

- [x] **`M6-CP3-TB49-RP01-FULL-GATE-REV`** (TB-REV) COMPLETE per [RA-169](.agents/Directional/Architecture_M6_CP3_TB49_REV_Closeout_C1_Rail_Cover_DEFN_Patches_20261028.md).1: authentic-history `review_check.py boundary` and `ledgers --base 1399da715` PASS; HEAD blobs equal RA-168 P1+P2 applied to `1399da715`; only those two files changed. TB49 504/0 accepted as a reviewed candidate; no CP3 promotion. TB49-REV's bundled successor was rejected as monolithic.
- [x] **`M6-CP3-DEFN-RP01-C1-ORPHAN-HARD-EDGE-COVER`** (DEFN, probe-backed): RA-162 C1 confirmed. The checked factory accepts an orphan hard edge when open rails exist (`SurfaceCellTracing.cpp:8712`); 3×3 fixtures masked it via `gauge-pin-span` (`:8595`). The builder runs A4 consumers on unchecked rail authority. D1 ingress check, D2 exact factory cover, D3 no orphan-barrier licence. Falsifiers: both new tests fail at HEAD.

---

## HISTORY — RA-168; CB49; CB49E; TB49-EXEC (2026-10-28)

- [x] **RA-168** ([decision](.agents/Directional/Architecture_M6_CP3_TB48_REV_Audit_G3_A5_Gauge_And_E2_Rail_Vertex_Patches_20261028.md)) audits `M6-CP3-TB48-RP01-FULL-GATE-REV` and completes `M6-CP3-DEFN-RP01-G3-PERIODIC-GAUGE-COVARIANCE` and `M6-CP3-DEFN-RP01-E2-RAIL-VERTEX-ADJACENCY-PATCH` (DEFN, probe-backed).
  - TB48 evidence confirmed: 502/2, 1014/1014, pins `TQ:3027`/`TQ:3183`.
  - **P-G3 re-owned A4 → A5.** A4 periodic relation states are identical under the odd relabel. A5 `periodic_endpoint_gauge` rotated gauge-free lattice coordinates by the local face gauge. P1 strips the gauge and fixes RA-167's copied oracle, adding gauge-free coordinate checks.
  - **E2 re-homed to D2.** A4 already publishes the R-split at vertex 4. TB48-REV's junction falsifier contradicted RA-166 D2. P2 rewrites cp3entry:2 (test-only).
  - Probes: TQ 140 pass, only the five O11 failures; local 504-case TB49 run 502/504, with 492/493 passing; 283/445 are macOS-only baselines (also fail unpatched; pass on CI).
- [x] **`M6-CP3-CB49-RP01-G3-A5-PERIODIC-PLACEMENT-GAUGE`** (CB; RA-168.4): exact P1 `5897798d…`, numstat `8 2` RemeshPipeline.cpp + `13 2` TQ; eight GMP targets compiled at `9c84ba9cc8e4` ([record](.agents/Directional/Architecture_M6_CP3_CB49_RP01_G3_A5_Periodic_Placement_Gauge_Code_Build_Record_20261028.md)); no runtime.
- [x] `M6-CP3-CB49E-RP01-E2-RAIL-VERTEX-ADJACENCY` (CB; RA-168.5): exact P2 `9ebef3cc…`, numstat `215 255` TQ; 8 GMP targets compiled at `092b52eba881` ([record](.agents/Directional/Architecture_M6_CP3_CB49E_RP01_E2_Rail_Vertex_Adjacency_Code_Build_Record_20261028.md)), no runtime.
- [x] `M6-CP3-TB49-RP01-FULL-GATE-EXEC` (TB-EXEC; RA-168.6): **504 PASS / 0 RED** observed ([report](.agents/Directional/Architecture_M6_CP3_TB49_RP01_Full_Gate_Test_Benchmark_Report_20261028.md), run 40776332136); immutable artifact 12857282498.

---

## HISTORY — RA-167; CB48; TB48; TB48-REV (2026-10-28)

- [x] RA-167 ([decision](.agents/Directional/Architecture_M6_CP3_TB47_REV_Gauge_Cluster_Decision_And_Canonical_Turn_Sequence_20261028.md)): G1/G2 re-homed; G3 odd-gauge witness; canonical turn types. Its P-G3 owner (A4) is superseded by RA-168.
- [x] CB48 `4c611941…` ([record](.agents/Directional/Architecture_M6_CP3_CB48_RP01_Gauge_Cluster_Tests_Code_Build_Record_20261028.md)) → TB48 502/2 ([report](.agents/Directional/Architecture_M6_CP3_TB48_RP01_Full_Gate_Test_Benchmark_Report_20261028.md)) → TB48-REV ([decision](.agents/Directional/Architecture_M6_CP3_TB48_RP01_Full_Gate_Independent_Review_Decision_20261028.md); P-G3 owner and E2 falsifier corrected by RA-168).

---

## HISTORY — RA-166; CB47; TB47; DEFN-G R1–R62 (2026-10-27/28)

- [x] RA-166 re-homed D5 and D2 → CB47 `08d41626e` ([record](.agents/Directional/Architecture_M6_CP3_CB47_RP01_Endpoint_Witnesses_Code_Build_Record_20261027.md)) → TB47 500/4 ([report](.agents/Directional/Architecture_M6_CP3_TB47_RP01_Full_Gate_Test_Benchmark_Report_20261027.md)).
- [x] DEFN-G R1–R62, static only ([index](.agents/Directional/Architecture_M6_CP3_DEFN_TB47_Gauge_Cluster_Independent_Review_20261027.md)), superseded by RA-167. Its R30/R34/R37 identification of the G2 source-relabel fixture is confirmed by probe.

---

## HISTORY — RA-165; CB46B; TB46 re-run; DEFN-E; CB47A; CB47 E1 (2026-10-27)

- [x] RA-165: 174 two invalid fixtures. CB46B `8f0d4329695d` → TB46 re-run 498/6 ([report](.agents/Directional/Architecture_M6_CP3_TB46_RP01_Full_Gate_Rerun_Report_20261027.md)).
- [x] DEFN-E ([decision](.agents/Directional/Architecture_M6_CP3_DEFN_TB46_Endpoint_Cluster_Review_Decision_20261027.md)). Its E3 and E2 witness specifications are superseded by RA-166.
- [x] CB47A ([record](.agents/Directional/Architecture_M6_CP3_CB47A_Harness_Manifest_Pins_Code_Record_20261027.md)): harness reads pins from the manifest.
- [x] CB47 E1 `dabb0970e` compiled (run `40489392387`; [interim](.agents/Directional/Architecture_M6_CP3_CB47_Endpoint_Witnesses_Interim_Investigation_20261027.md)). It is defective; RA-166 corrects it.

---

## HISTORY — RA-164; CB46; TB46 (S5); TB46A-ORCH (2026-10-27)

- [x] RA-164 TB45-REV audit: 174/cp3entry:4 decided statically (174 throw site later corrected by RA-165); clusters E/G; cadence realigned (P1–P6).
- [x] CB46 `c05d52dd7` (H1/H2/D1–D3, [record](.agents/Directional/Architecture_M6_CP3_CB46_Rail_Oracle_Rehome_And_Endpoint_Diagnostics_Code_Build_Record_20261027.md)) → TB46 run `40448739180` 497/7, S5 ([report](.agents/Directional/Architecture_M6_CP3_TB46_Full_Gate_Test_Benchmark_Report_20261027.md)): 174 uncaught DCEL exception, cp3entry:4 later `:4063`.
- [x] TB46A-ORCH harness `5e6de03fa` ([record](.agents/Directional/Architecture_M6_CP3_TB46A_Orchestration_Correction_Compile_Record_20261027.md)), compile run `40457083585`, package `12712389032`; review prerequisite resolved by RA-165.

---

## HISTORY — RA-163; CB45; CB45-REV; TB45; TB45-REV (2026-10-27)

- [x] RA-163 DEFN-242 Review: D1 corrected to `NonReciprocalTransport` owner (`selector:185`); D2 decided (mutated A3 accepts, gauge relabel); Branch B rejected; 242 re-homed.
- [x] CB45 ([record](.agents/Directional/Architecture_M6_CP3_CB45_Selector242_Seam_Rehome_Code_Build_Record_20261026.md), source `dfeb0751b`) → CB45-REV ([decision](.agents/Directional/Architecture_M6_CP3_CB45_Selector242_Seam_Rehome_Independent_Review_Decision_20261027.md)) → TB45 ([report](.agents/Directional/Architecture_M6_CP3_TB45_Selector242_Seam_Rehome_Verification_Report_20261027.md), 242/239/185 3/3) → TB45-REV ([decision](.agents/Directional/Architecture_M6_CP3_TB45_Selector242_Seam_Rehome_Independent_Review_Decision_20261027.md), focused only).

---

## HISTORY — RA-162; selector242 DEFN (2026-10-26)

- [x] **RA-162 audit** ([decision](.agents/Directional/Architecture_M6_CP3_TB44_REV_Audit_P1_Torn_Input_Selector242_Scope_Decision_20261026.md)):
  - TB44-REV confirmed: ZIP `f1b30006…6b986`, **11/11** members (records said 10/10), 4/4 log joins, manifest `f410b550…a6a8a` frozen at `2d0a23005` before dispatch; no source drift since CB44 `c25667111`. 405 PASS is invariance by construction (target dead under accepted conformity) — valid regression guard.
  - F1: TB44-REV P1-a remedy rejected — 8219 adds a non-rail spoke to `hardFeatureEdges`, which production derives from rails (`RemeshPipeline.cpp:12645, 12783`); supplying provenance would certify a torn input. Re-home to a production-reachable witness.
  - F2 → **RA-162 C1**: checked factory enforces hard-edge cover only for closed-only rail sets (`SurfaceCellTracing.cpp:8712`); open-rail sets accept orphan hard edges. O5 owner.
  - F3: P1-b confirmed (`SurfaceCellTracing.cpp:6160–6168`); pre-register the differential as a pair of first-sites.
  - F4: 242 mutates `crossField.edgeTransitions` after the atlas is built from `sourceField`; atlas-bound A4 never reads it (`SurfaceCellTracing.cpp:21181–21184`); A3 reciprocity is structural (`FieldTransportAtlas.cpp:2033–2036`). DEFN scoped in RA-162.4.
- [x] **`M6-CP3-DEFN-RP01-SELECTOR242-CROSS-REGION-SEAM-CONSUMER`** — [decision](.agents/Directional/Architecture_M6_CP3_DEFN_Selector242_Cross_Region_Seam_Consumer_Decision_20261026.md) and [CB45 spec](.agents/Directional/Architecture_M6_CP3_CB45_Selector242_Seam_Rehome_Specification_20261026.md); A3 matching inverse is structural; A4 certificate owner; independent A3 outcome not run, B production reachability conditional. No code/tests/selector/build/runtime.

---

## HISTORY — RA-161; CB44; CB44-REV; TB44; TB44-REV (2026-10-26)

- [x] RA-161 audit: TB43-REV confirmed; 405 root-caused to fixed-plan helper omitting A2b provenance; O4 demoted behind REDs.
- [x] CB44 (`c25667111`): 405 body forwards producer-derived contacts/closed chains; compile [40373930737](https://github.com/akashskypatel/Directional/actions/runs/40373930737), artifact `12674401457`, 28/28, `runtimeExecution=false`. CB44-REV accepted; four-row TB44 manifest frozen.
- [x] TB44 ([report](.agents/Directional/Architecture_M6_CP3_TB44_Selector405_Fixed_Plan_Verification_Report_20261026.md), [run 40387240269](https://github.com/akashskypatel/Directional/actions/runs/40387240269)): 405 PASS, 7614 PASS, 7414 PASS, 8219 RED (`missing-terminal-or-closed-rail-provenance` before intended `missing-terminal-A3-path`). No promotion.
- [x] TB44-REV ([decision](.agents/Directional/Architecture_M6_CP3_TB44_Selector405_Fixed_Plan_Independent_Review_Decision_20261026.md)): 3/4 valid; P1-a stale fixture, P1-b not network-discriminating; P1 to O5 (remedy 1 superseded by RA-162 F1).

---

## HISTORY — RA-160; CB43; CB43-REV; TB43; TB43-REV (2026-10-26)
- [x] **RA-160 DEFN Review** ([decision](.agents/Directional/Architecture_M6_CP3_DEFN_Legacy_Matching_Path_Disposition_Review_Decision_20261026.md)) — accepted in part:
  - Q1 accepted and strengthened: the atlas-present wrapper nulls all legacy containers (`SurfaceCellTracing.cpp:21182–21185`); `legacyField` is fully inert. Corrects RA-159 N2 (it does not select the provenance lookup).
  - Q2/Q3 accepted; Q2 amended — A3 `MissingAdjacency` alone duplicates accepted `selector:28`; add the A4 no-atlas ingress pin (no test pins `"atlas-binding"`).
  - D2: Q4 false on NotApplicable inputs — the seed fallback (`:20661–21160`) publishes legacy-decided seeds/traces/proposals/separatrices on no-atlas ingress.
  - D3/D4: crossField `trace_surface_field` (`:11527`) always passes legacy containers (FlowRep production caller has atlas); planar/bounded/isolation and selector233 inventory deferred.
  - D5: periodic step defaults to identity transport with no source (`:14937–14979`, no `else` rejection).
  - O2 production CB withdrawn; O2 moves to post-RP-01 DEFN.
- [x] **CB43 `M6-CP3-CB43-RP01-SELECTOR190-LEGACY-INGRESS-REHOME`** — [compile record](.agents/Directional/Architecture_M6_CP3_CB43_Selector190_Legacy_Ingress_Rehome_Code_Build_Record_20261026.md), test-only, compiled (not executed); halves (a) positive, (b) A3 `MissingAdjacency` + independent min interior key, (c) restored-transitions anti-vacuity, (d) no-atlas A4 `PublishedProductRejected`/`InvalidSourceAuthority`/`AtlasSourceMismatch`/`"atlas-binding"`, empty outputs (RA-160.3).
- [x] **CB43-REV** independent source/compile Review accepted; [decision](.agents/Directional/Architecture_M6_CP3_CB43_Selector190_Legacy_Ingress_Rehome_Independent_Review_Decision_20261026.md) and [TB43 four-case manifest](.agents/Directional/Architecture_M6_CP3_TB43_Selector190_Rehome_Verification_Case_Manifest.tsv) frozen; no runtime credit.
- [x] **TB43 `M6-CP3-TB43-RP01-SELECTOR190-REHOME-VERIFY`**: 4/4 PASS (190 POSITIVE; 28/179/233 GUARD), zero skips/duplicates, [report](.agents/Directional/Architecture_M6_CP3_TB43_Selector190_Rehome_Verification_Report_20261026.md), run 40353956056, result 12664712967; focused candidate only.
- [x] **TB43-REV** independently verified 12/12 result and 28/28 package checksums, four exact raw-log joins, A3/A4 anti-vacuity, and unchanged selector449/focused12; focused candidate only. [Decision](.agents/Directional/Architecture_M6_CP3_TB43_Selector190_Rehome_Independent_Review_Decision_20261026.md).
- Frozen: stable 66/17/49, debt 1; CP2 491/491 accepted; TB43 4/4 focused candidate; selector497 frozen; RP-01 open.

---

## HISTORY — RA-159; legacy-path DEFN; DEFN-REV (2026-10-26)
- [x] **RA-159 audit** ([decision](.agents/Directional/Architecture_M6_CP3_TB42_REV_Audit_Selector190_Vacuity_And_DEFN_Spec_Decision_20261026.md)):
  - TB42-REV confirmed: ZIP `2d0c6cf7…b1b6`, 5/5 hashes, 1/1 log join, manifest `b266c056…8885` frozen before dispatch. O3 3/3 focused candidate.
  - N1/O6: the O3 tests pin a limitation — every nonrectangular bounded disk (incl. the L-shaped fixture) is rejected by design (`SurfaceCellTracing.cpp:17182–17192`); no requirement or owner exists. RP-01 Review must state CP3 scope and owner.
  - N2: selector190 passes vacuously since `7ccdcd527` (2026-10-11): A3/A4 use `authoritativeField`'s atlas; `legacyField` decides no transport. Last mismatched call in the periodic-route family.
  - N3: CP2's 190 credit (2026-10-06) was for a legacy-only-publishes oracle now void under D1; TB38/TB41 190 PASS rows are not legacy-path evidence.
  - N4: O2 has a live detail-level consumer, `LegacyMatchingPathUsesSameTypedRouteComposition` (`Phase10Tests:5716`, off-gate).
  - N5: duplicate DEFN item in TODO and missing TB42 result in the handoff fixed.
- [x] **DEFN legacy matching path** — [decision](.agents/Directional/Architecture_M6_CP3_DEFN_Legacy_Matching_Path_Disposition_20261026.md): Q1–Q6 answered; re-home 190 as a discriminating A3 MissingAdjacency oracle, preserve legacy detail-only consumers and accepted-prefix credit as historical only. Design only, no selector or runtime change.
- [x] **COMPLETE `M6-CP3-DEFN-RP01-LEGACY-MATCHING-PATH-DISPOSITION-REV`** — Review Agent (RA-160); accepted in part, production CB withdrawn.
- Frozen: stable 66/17/49, debt 1; CP2 491/491 accepted; selector497 frozen; RP-01 open.

---

## HISTORY — RA-158; TB42; TB42-REV (2026-10-26)
- [x] **RA-158 audit** ([decision](.agents/Directional/Architecture_M6_CP3_TB41_REV_Audit_O3_Owner_And_DEFN_Split_Decision_20261026.md)):
  - TB41-REV confirmed: ZIP `1817f829…d854`, 39/39 hashes, 18/18 log joins, manifest `659c52f0…2959`; no source change since CB42 `8dc8cdeae`. Focused candidate only.
  - L1: the O3 third locus test (`Phase10Tests:2940`) had no owner; RA-157.4 listed TB41 rows by selector number, so it got no row. Package `12634151125` expires 2026-11-02T07:22Z → TB42 next.
  - L2: the legacy-path/seam DEFN bundled three mechanisms and left its Review ID unfrozen; split into three DEFN turns with frozen IDs.
  - L3: 192 is now assertion-for-assertion the TB36 quarter-turn guard; no action.
  - L4: 247 keeps orphaned transition-lookup setup (`:5345–5375`); not scheduled.
  - L5/O5: 249 of 598 producer-binary tests are in no frozen gate (42 `SurfaceCellsPhase10`, 14 `M6CP3`); disposition DEFN before the census.
  - L6: handoff authority table realigned to the template; stale TODO items closed.
- [x] **TB42 artifact-only:** one O3 POSITIVE row on CB42 package `12634151125` using unchanged targeted harness; [run 40310754811](https://github.com/akashskypatel/Directional/actions/runs/40310754811), result `12644936205`, 5/5 checksum and 1/1 PASS, postflight=true; candidate, not gate promotion. [Report](.agents/Directional/Architecture_M6_CP3_TB42_O3_Off_Selector_Locus_Verification_Report_20261026.md).
- [x] **COMPLETE `M6-CP3-TB42-RP01-O3-OFF-SELECTOR-LOCUS-VERIFY-REV`** — independent 28/28 CB42, 5/5 TB42 result hashes, one raw GTest join, typed locus non-vacuity; O3 now 3/3 focused candidate; [decision](.agents/Directional/Architecture_M6_CP3_TB42_O3_Off_Selector_Locus_Independent_Review_Decision_20261026.md). No selector497/CP3 promotion.
- Frozen: stable 66/17/49, debt 1; CP2 491/491 accepted; O3 3/3 focused candidate; selector497 frozen; RP-01 open.

---

## HISTORY — RA-157; CB39–CB42 with Reviews; TB41; TB41-REV (2026-10-26)
- [x] **RA-157 audit** ([decision](.agents/Directional/Architecture_M6_CP3_TB40_REV_Audit_CB39_A3_Tamper_Spec_Decision_20261025.md)):
  - TB40-REV accepted: 29/29 hashes and 13/13 rows; the CB37→CB38 diff is the test hunk only. 250 is a focused candidate (no promotion).
  - K1: the CB39 spec was too vague to review; re-bound to an untampered-A3 baseline plus `code`+`sourceEdge` assertions, with the A4 negatives (unsatisfiable under D1) removed.
  - K2/O4: A4 `MissingTransitionProvenance` (`SurfaceCellTracing.cpp:12656/12698/12707`) loses its only witness; its reachability goes into the DEFN turn.
  - K3: 250 does not check that disk cells respect the rail (236 covers that); not scheduled.
  - K4: duplicate tracker entry, multi-turn "EXACT NEXT" and the sequence-numbering gap all fixed.
- [x] **CB39 `A3-SOURCE-EDGE-TAMPER-REHOME` compiled** ([record](.agents/Directional/Architecture_M6_CP3_CB39_A3_Source_Edge_Tamper_Rehome_Code_Build_Record_20261026.md)); RA-157.3, only tests 191/204, untampered A3 success and tampered A3 exact code/key, two A4 negative blocks removed. Exact source `c6cc82aa0aa8e5e46dc58cfc887050bf46a65963`; [compile 40254362620](https://github.com/akashskypatel/Directional/actions/runs/40254362620), `12621099926`; no runtime, selector or acceptance promotion.
- [x] **CB39-REV** — independent static acceptance of selector191/204 test hunks, exact A2/A3 ingress, 28/28 package hashes, eight GMP/GMPXX targets and compile-only boundary; TB41 rows 191/204 frozen for later execution, not runtime PASS. [Decision](.agents/Directional/Architecture_M6_CP3_CB39_A3_Source_Edge_Tamper_Independent_Review_Decision_20261026.md).
- [x] **CB40 turning-field monodromy re-home compiled** — [record](.agents/Directional/Architecture_M6_CP3_CB40_Turning_Field_Monodromy_Rehome_Code_Build_Record_20261026.md); exact source `0d227875d8f031a467e661be2da4dd901846797c`, [compile 40264202131](https://github.com/akashskypatel/Directional/actions/runs/40264202131), artifact `12625069994`, verified eight GMP/GMPXX targets and `runtimeExecution=false`; 192 k=1 and 247 k=2 require A3 acceptance; original A4 assertions retained. No runtime or selector promotion.
- [x] **COMPLETED `M6-CP3-CB40-RP01-TURNING-FIELD-MONODROMY-REHOME-REV`** — [decision](.agents/Directional/Architecture_M6_CP3_CB40_Turning_Field_Monodromy_Rehome_Independent_Review_Decision_20261026.md) independently re-derived k=1/k=2 A3/atlas and A4 oracles, 28/28 compile package manifest, 5898/5898 frozen snapshot, and [full-history run 40271541658](https://github.com/akashskypatel/Directional/actions/runs/40271541658) PASS on authority, boundary and ledgers. No runtime, no selector497/CP3 promotion.
- [x] **CB41 equivalent-lift A3 ingress test compiled** — RA-155.3 C selector189; independently build both A3 atlases from each ±4 raw field, assert signed-lift relationship and unchanged quarter-turn transport; preserve A4 periodic snapshots. Corrected source `53830149ea16473d0321e53da2587695916fd9cb`; [compile 40275357335](https://github.com/akashskypatel/Directional/actions/runs/40275357335), artifact `12630300861`; eight GMP/GMPXX targets, 28/28 checksums, `runtimeExecution=false`. Initial compile 40274040338 failed on result API and was corrected, not counted as passing. [Record](.agents/Directional/Architecture_M6_CP3_CB41_Equivalent_Lift_A3_Ingress_Rehome_Code_Build_Record_20261026.md).
- [x] **CB41-REV static decision** — independently verified exact test bytes and own-field A3 ±4/transport/A4 non-vacuity against compile source and 5900-hash snapshot, 28/28 package hashes. [Decision](.agents/Directional/Architecture_M6_CP3_CB41_Equivalent_Lift_A3_Ingress_Rehome_Independent_Review_Decision_20261026.md); no runtime or selector/CP3 promotion.
- [x] **CB42 polygonal-disk locus pin compiled (static only)** — RA-156 J3/O3: 12 rejection-locus assertions in 251, 252 and `:2936`; source `8dc8cdeae6f6ac05c28aaa4504ca2c42c3177ded`, [compile 40285233031](https://github.com/akashskypatel/Directional/actions/runs/40285233031), artifact `12634151125`, 28/28 checksum manifest, eight GMP/GMPXX targets, `runtimeExecution=false`. [Record](.agents/Directional/Architecture_M6_CP3_CB42_Polygonal_Disk_Locus_Pin_Code_Build_Record_20261026.md). No runtime evidence or promotion.
- [x] **COMPLETE `M6-CP3-CB42-RP01-POLYGONAL-DISK-LOCUS-PIN-REV`** — independent static test/compile review, 12 exact O3 assertions and 28/28 package checksums, 5902/5902 source hashes; authentic Git-history check [run 40292894222](https://github.com/akashskypatel/Directional/actions/runs/40292894222) PASS. [CB42-REV decision](Architecture_M6_CP3_CB42_Polygonal_Disk_Locus_Pin_Independent_Review_Decision_20261026.md). No runtime or promotion.
- [x] **COMPLETE `M6-CP3-TB41-RP01-REHOMED-ORACLE-VERIFY`** — immutable CB42 artifact `12634151125`, [run 40296007299](https://github.com/akashskypatel/Directional/actions/runs/40296007299) and result `12638251384`: 18/18 PASS, 0 RED, 39/39 checksums, `postflight=true`; all 8 re-homed oracles and 10 nonduplicated TB40 guards. [Owning TB41 report](.agents/Directional/Architecture_M6_CP3_TB41_Rehomed_Oracle_Verification_Report_20261026.md). Candidate only, not CP3/selector497 promotion.
- [x] **COMPLETED `M6-CP3-TB41-RP01-REHOMED-ORACLE-VERIFY-REV`** — [decision](.agents/Directional/Architecture_M6_CP3_TB41_Rehomed_Oracle_Independent_Review_Decision_20261026.md): 18/18 focused candidate accepted; third O3 locus test found unexecuted.
- Frozen: stable 66/17/49, debt 1; CP2 491/491 accepted; TB32 481/500 and TB38 490/504 candidate; 250 focused candidate; selector497 frozen; RP-01 open, RP-02 unreached, Gate C suspended.

---

## HISTORY — RA-156; CB38; CB38-REV; TB40; TB40-REV (2026-10-25)
- [x] **RA-156 audit** ([decision](.agents/Directional/Architecture_M6_CP3_TB39_REV_Audit_Selector250_Rail_Provenance_Decision_20261025.md)):
  - TB39-REV accepted: 17/17 hashes and 7 log hashes verified; 250 site `hard-rail-contact-missing` (code 0, detail 6) is owned by the fixture, not O1.
  - J1: test 250 discards all four rail-authority fields that `make_curved_disk_fixture` builds (`:2582–2626`). Without `authoritativeRails`, tracing also gets no disk rail seeds. Derive all four through the production rail functions.
  - J2: the 250 owner is known and small, so it moves first; the A/B/C re-homes follow.
  - J3/O3: the polygonal-disk rejection oracles (251, 252, `:2936`) check the reason only; that reason has 5 sites. Pin `cell=-1, side=-1`.
  - J4: guards use only the in-selector PASS rows; `:3380` and the `:10092` negative are unmeasured.
- [x] **COMPLETED `M6-CP3-CB38-RP01-SELECTOR250-RAIL-AUTHORITY`** (test-only, compile only; RA-156.3). Inside test 250 only:
  - build a combined-mesh feature map (closed `Hard` ring, `component=2`, plus `diskOffset`);
  - call `build_authoritative_surface_cell_rails`;
  - set `authoritativeRails` and the three provenance maps;
  - require the edge-key identity `== hardFeatureEdges`.
  - Assertions unchanged. [CB38 record](.agents/Directional/Architecture_M6_CP3_CB38_Selector250_Rail_Authority_Code_Build_Record_20261025.md) verifies one hunk, eight GMP/GMPXX targets, 28/28 checksums, no runtime.
- [x] **COMPLETED `M6-CP3-CB38-RP01-SELECTOR250-RAIL-AUTHORITY-REV`** — exact one-hunk test correction and immutable compile accepted, no runtime; [decision](.agents/Directional/Architecture_M6_CP3_CB38_Selector250_Rail_Authority_Independent_Review_Decision_20261025.md). TB40 13-case manifest SHA256 `5dd7d9499918b04a277b907835993beb7829e6d9f52c4cc345faf5e3cd2158e4` frozen.
- [x] **COMPLETED `M6-CP3-TB40-RP01-SELECTOR250-RAIL-AUTHORITY-VERIFY`** — [run 40240164913](https://github.com/akashskypatel/Directional/actions/runs/40240164913), 13/13 PASS, 12/12 guards, selector250 unexpected PASS, clean immutable postflight; candidate only. [Report](.agents/Directional/Architecture_M6_CP3_TB40_Selector250_Rail_Authority_Verification_Report_20261025.md).
- [x] **COMPLETED `M6-CP3-TB40-RP01-SELECTOR250-RAIL-AUTHORITY-VERIFY-REV`** ([independent review](.agents/Directional/Architecture_M6_CP3_TB40_Selector250_Rail_Authority_Independent_Review_20261025.md)):
  - Re-verify the TB40 result `12616556389`: ZIP `84d63107…e7a320`, 29/29 `SHA256SUMS`, 13 ledger↔log joins, boundary state.
  - Attribute the 250 PASS to CB38: the only CB37→CB38 source change is `tests/SurfaceCellsPhase10Tests.cpp` +50/−0, and TB39 on CB37 was `hard-rail-contact-missing`.
  - Confirm the 250 assertions are unchanged and were reached.
  - RA-156 250 owner discharged as focused candidate; CP3/selector497 unpromoted, stable 66/17/49 debt1; CB39 frozen.
- **Frozen accounting:** stable **66/17/49**, debt 1; CP2 **491/491 accepted**; TB38 490/504 candidate; 250 focused candidate; selector497 frozen; RP-01 open, RP-02 unreached.

---

## HISTORY — RA-155; CB37; CB37-REV; TB39; TB39-REV (2026-10-25)
- [x] **RA-155 audit** ([decision](.agents/Directional/Architecture_M6_CP3_TB38_REV_Audit_Tamper_Oracle_Homes_Decision_20261025.md)):
  - TB38-REV accepted: 1,014/1,014 hashes; 490/14; 191/192/250 raw logs re-checked.
  - The seven-oracle DEFN is replaced, because Review binds the determinate homes:
    - **A** — 191 and 204: tampered field as the A3 input; expect `NonReciprocalAdjacency` at the tampered key. This covers the untested `FieldTransportAtlas.cpp:2020`.
    - **B** — 192 (k=1) and 247 (k=2): turning-field monodromy; keep the A4 assertions.
    - **C** — 189: A3 built from its own ±4 field; snapshots equal.
  - H2/O2: `make` requires an atlas (`:8462`), so legacy paths cannot produce output and 190 cannot be satisfied.
  - H3: 242's tampered edge is a cross-region seam with no A2–A4 consumer.
  - H5: 250 still 68; the failure already carries the code, detail and site.
- [x] **CB37 compiled (test-only):** changed only the streamed diagnostic message at `tests/SurfaceCellsPhase10Tests.cpp:3666–3669` (assertion unchanged). Exact source `c9d7c80f6d41abdbc2ecd02de7006c7847988df8`; [run 40216902065](https://github.com/akashskypatel/Directional/actions/runs/40216902065), package `12607777892`, ZIP SHA256 `fa437659c633de1b5e69dc93b35bcbb65dec84c212a957d005ada58e4dd01b58`; eight targets GMP/GMPXX, `runtimeExecution=false`, no tests/benchmarks. [Record](.agents/Directional/Architecture_M6_CP3_CB37_Selector250_Factory_Site_Message_Prepared_Patch_Record_20261025.md).
- [x] **CB37-REV** — independently accepted one streamed-message hunk and the exact CB37 package (28/28 hashes; eight GMP/GMPXX targets; no runtime). Seven-row TB39 manifest frozen (`a304aeebb6bbbaadf17be43c56b080714e2e39fe4e7f8615da126f3f0150cc61`); no selector or CP3 promotion.
- [x] **TB39 executed (artifact-only):** [run 40221114658](https://github.com/akashskypatel/Directional/actions/runs/40221114658), 7/7 fresh cases, six PASS guards and expected RED selector250; `publishedProductError=0`, `publishedProductSourceAuthorityDetail=6`, `site=hard-rail-contact-missing`; result 12609665120, 17/17 hashes, 0 missing/skipped, postflight true. [Report](.agents/Directional/Architecture_M6_CP3_TB39_Selector250_Factory_Site_Harvest_Report_20261025.md).
- [x] **TB39-REV** — independently rehashed 17/17 result members and the 7/7 raw logs; traced code 0/detail 6 to missing open/closed hard-rail provenance in selector250 combined positive fixture, not periodic-action O1. No selector or CP3 promotion. [Decision](.agents/Directional/Architecture_M6_CP3_TB39_Selector250_Factory_Site_Independent_Review_20261025.md).
- **Frozen accounting:** stable **66/17/49**, debt 1; CP2 **491/491 accepted**; TB32 481/500 and TB38 490/504 candidate; selector497 frozen; RP-01 open, RP-02 unreached, Gate C suspended.

---

## HISTORY — RA-154; TB38; TB38-REV (2026-10-25)
- [x] **RA-154 TB37-REV audit** ([decision](.agents/Directional/Architecture_M6_CP3_TB37_REV_Audit_Periodic_Census_Manifest_Decision_20261025.md)): issued the Review-owned 504-row TB38 manifest (`b27eecb6…`); reclassified 204/242/247 with 191/192 as atlas-ingress tamper oracles; flagged 250 as D2-reachable; O1 (cut-route identity transport).

- [x] **TB38 artifact-only**: [run 40185527486](https://github.com/akashskypatel/Directional/actions/runs/40185527486), source/package CB36 `038ae7fd7`/`12590917524`, immutable result `12597140251` outer SHA-256 `0cdfe445fbc5388b8e95331f87c4a291001645f30458001bb5426244022a9870`, 1,014/1,014 manifest hashes; **504/504 executed; 490 PASS / 14 RED; 0 missing/skipped/duplicates/control bad/unexpected pass; postflight true**. 497-selector 483/14 vs TB32 478/19; 5 expected legacy RED→GUARD, 4 new guards PASS. No compile/relink/source/test/selector change. [Owning report](.agents/Directional/Architecture_M6_CP3_TB38_Periodic_Route_Atlas_Census_Report_20261025.md).
- [x] **TB38-REV:** independently rehashed TB38/TB32/CB36 artifacts and compared all 14 raw residual assertions. Reviewed **candidate-only** 490/504; 191/192 reached but remain negative-oracle RED, 250 still typed 68. [Decision](.agents/Directional/Architecture_M6_CP3_TB38_Periodic_Route_Atlas_Census_Independent_Review_Decision_20261025.md). Real-history `review_check.py authority` / `boundary` / `ledgers` verified 0/0/0 exits in [run 40211601306](https://github.com/akashskypatel/Directional/actions/runs/40211601306); current Review is COMPLETE, next DEFN is a separate turn.
- **Frozen accounting:** stable **66/17/49**, debt 1; CP2 **491/491 accepted**; TB32 481/500 candidate; selector497 frozen; RP-01 open, RP-02 unreached, Gate C suspended.

---

## HISTORY — CB36; CB36-REV; TB37; TB37-REV (2026-10-25)

- [x] `M6-CP3-CB36-RP01-PERIODIC-ROUTE-ATLAS-TRANSPORT`: production `SurfaceCellTracing.cpp` periodic observed-step atlas transport first, missing transport fail-closed with existing locus; legacy branches preserved. Exact semantic `038ae7fd7c290731c28225d2693a3e13866e325a`; [record](.agents/Directional/Architecture_M6_CP3_CB36_Periodic_Route_Atlas_Transport_Code_Build_Record_20261025.md).
- [x] Eight-target compile-only [run 40173209091](https://github.com/akashskypatel/Directional/actions/runs/40173209091), artifact `12590917524` ZIP SHA256 `6dcbfe5a468be5f548c368bfebeba411c6abd19ed4a4efd01be9923da9eb7d03`; 28/28 hashes, GMP/GMPXX, `runtimeExecution=false`, no tests/benchmarks.
- [x] `M6-CP3-CB36-RP01-PERIODIC-ROUTE-ATLAS-TRANSPORT-REV` independent static Review: D2 one-site semantics/source/package/GMP 28/28 accepted **without runtime**. [Decision](.agents/Directional/Architecture_M6_CP3_CB36_Periodic_Route_Atlas_Transport_Independent_Review_Decision_20261025.md).
- [x] `M6-CP3-TB37-RP01-PERIODIC-ROUTE-ATLAS-VERIFY`: 16/16 fresh processes, 14 PASS and two inherited frozen RED, no regression; [Architecture_M6_CP3_TB37_Periodic_Route_Atlas_Verification_Report_20261025.md](.agents/Directional/Architecture_M6_CP3_TB37_Periodic_Route_Atlas_Verification_Report_20261025.md); [run](https://github.com/akashskypatel/Directional/actions/runs/40179570318). First 0/16 uniqueness-gate attempt invalid; corrected retry passes immutable postflight. Harness false warning on frozen enum textual decoding requires Review.
- [x] **TB37-REV accepted focused evidence:** independent manifest SHA, 16/16 raw joins, 21/21 result hashes, 28/28 CB36 package hashes and prior TB36 191/192 numeric enums verified; harness `FROZEN_191_192_DISPOSITION_CHANGED` is a textual-parser false positive. [Decision](.agents/Directional/Architecture_M6_CP3_TB37_Periodic_Route_Atlas_Verification_Independent_Review_Decision_20261025.md).
- Frozen: stable 66/17/49, debt 1; CP2 491/491 accepted; TB32 481/500 candidate (19 inherited RED); TB35 11/13, TB36 0/5; selector497 frozen; RP-01 open, RP-02 unreached, Gate C suspended.

---

## HISTORY — CB35-R1/R2; TB36 harness correction; TB36-R1; TB36-REV (2026-10-25)

- [x] `M6-CP3-CB35-R1-RP01-PUBLISHED-ROUTE-ORACLE-CORRECTION` compiled test-only +5/−1; immutable artifact 12577649024 verified 28/28, GMP/GMPXX, no runtime. R1 canonical-key and translation checks are present.
- [x] **CB35-R1-REV material finding R-2:** `route_topology(route)` compares `CanonicalRoute::steps()` rather than observed `oriented_steps()`. `CanonicalRoute::reversed()` preserves canonical keys while reversing the published traversal; remaining shift/±1/total identity assertions can still pass. Review **NOT ACCEPTED**; see [decision](.agents/Directional/Architecture_M6_CP3_CB35_R1_Published_Route_Oracle_Independent_Review_20261024.md).
- [x] `M6-CP3-CB35-R2-RP01-ORIENTED-ROUTE-IDENTITY-ORACLE` — test-only oriented 32-step route identity + reversal-negative; exact semantic `7de805c487fa66bcb96744f51b8bfbe7210ee8dc`, [compile run 40147720351](https://github.com/akashskypatel/Directional/actions/runs/40147720351), artifact `12580989509` 28/28 GMP/GMPXX. No runtime. [Record](.agents/Directional/Architecture_M6_CP3_CB35_R2_Oriented_Route_Identity_Oracle_Code_Build_Record_20261025.md).
- [x] **R2 independent static Review ACCEPTED:** directed 32-step ordered source-edge, Forward/kind/interior identity, reversal negative, test-only +26/−0; 28/28 package hashes and eight GMP/GMPXX targets. No runtime. [Architecture_M6_CP3_CB35_R2_Oriented_Route_Identity_Oracle_Independent_Review_20261025.md](.agents/Directional/Architecture_M6_CP3_CB35_R2_Oriented_Route_Identity_Oracle_Independent_Review_20261025.md).
- [x] **Invalid TB36 attempt + control-plane correction:** first run `40155549123` executed 0/5 due five-row uniqueness gate and bad source-location regex (invalid orchestration, no semantic result). `M6-CP3-CB36-ORCH-RP01-TB36-HARNESS-CORRECTION` changed harness only at `0ba22724c97e9231f24a6d9bc7201e58b3c6da81`, corrected SHA-256 `343cdc6e53daf33da7d2893086751e0f762e6a3ed2111e69bf077555a4e3f439`, local static checks PASS; [record](.agents/Directional/Architecture_M6_CP3_CB36_TB36_Harness_Orchestration_Correction_Record_20261025.md). No build or Directional execution.
- [x] **TB36-R1 VALID / CANDIDATE:** [run `40159803899`](https://github.com/akashskypatel/Directional/actions/runs/40159803899), artifact `12586275698`, five distinct fresh-process cases, **0 PASS / 5 RED**, exact immutable package and postflight; witness1/2 `PublishedProductRejected(68)` vs expected `PeriodicHolonomyMismatch(29)`, route witness3 non-odd rotation, frozen 191/192 still Produced/None. No compile/relink/repair/selector changes. [Report](.agents/Directional/Architecture_M6_CP3_TB36_R1_Periodic_Monodromy_Baseline_Report_20261025.md).
- [x] **TB36 independent Review:** 5/5 RED validated, A4 missing atlas read confirmed; `PublishedProductRejected(68)` is a downstream checked-factory rejection with unmeasured sub-site. No stable or selector promotion. [Decision](.agents/Directional/Architecture_M6_CP3_TB36_R1_Periodic_Monodromy_Baseline_Independent_Review_Decision_20261025.md).
- [x] CB36 successor confirmed and spec bound by RA-153 (see CURRENT).
- [ ] Carried: RA-152 A4 periodic F1; frozen 189–192 no edits; selector497 frozen; CP2 491/491 accepted, TB32 481/500 candidate, TB35 11 PASS/2 RED, stable 66/17/49 debt1; RP-01 open/RP-02 unreached. Continue prior queue only after accepted witness evidence.

## HISTORY — CB35 compiled; independent witness Review (superseded by R1) (2026-10-24)

- [x] `M6-CP3-TB35-RP01-PERIODIC-ROUTE-GAUGE-VERIFY-REV-AUDIT` (RA-152):
  - TB35-REV's evidence, mechanism and non-promotion are accepted;
  - **F1 (production, candidate):** on the atlas path the A4 periodic observed-step loop (`SurfaceCellTracing.cpp:14905–15004`) never reads `transitionLookup.atlas`. Consequences:
    - every route step is identity, so the guard at `:15000` is unreachable;
    - strip closure (`:14369`) is unvalidated;
    - published route transports are wrong;
  - 191–192 history: at the accepted 449 these used legacy no-atlas ingress, and R4 `7ccdcd527` made them unsatisfiable; 193 is also non-discriminating;
  - D1 single writer (no container pass-through or cross-check); D2 the owner fix; D3 witness first; D4 frozen-body re-homing is deferred to a DEFN;
  - the ingress DEFN is withdrawn. [Decision](.agents/Directional/Architecture_M6_CP3_TB35_REV_Audit_Periodic_Route_Transport_Decision_20261024.md).
- [x] `M6-CP3-CB35-RP01-PERIODIC-MONODROMY-WITNESS` — test-only, compile-only (no runtime). [Plan](.agents/Directional/Architecture_M6_CP3_CB35_Periodic_Monodromy_Witness_Code_Build_Plan_20261024.md).
  - Add the helper `turning_periodic_route_field(fixture, k)`: a raw-cross rotation `k·(π/2)·φ/2π` about the face normal, then the production finalizer.
  - `AuthoritativeQuarterTurnMonodromyRejectsAtPeriodicGuard` (k=1) and `AuthoritativeHalfTurnMonodromyRejectsAtPeriodicGuard` (k=2): 192's assertion set, with the same field as tracing and source. Preconditions: no singularities; route rotation ±k and not identity; A3 make succeeds.
  - `PublishedRouteStepsCarryAtlasTransport`: the gauged field; the steps at route[0]/route[1] are ±1 and inverse; all others identity.
  - No production, frozen-test, selector or runtime change. [Verified record](.agents/Directional/Architecture_M6_CP3_CB35_Periodic_Monodromy_Witness_Code_Build_Record_20261024.md); 28/28 GMP/GMPXX package, eight targets, runtimeExecution=false.
- [ ] **EXACT NEXT:** `M6-CP3-CB35-RP01-PERIODIC-MONODROMY-WITNESS-REV` — independent static witness/API/source/package review; only if accepted, author exact TB36 manifest (new 3 + frozen 191/192). No runtime in this Review.
- [ ] Then: **TB36** pre-fix baseline → TB36-REV.
  - TB36 runs the 3 witnesses + 191/192; the witnesses are predicted RED.
  - STOP if a witness is GREEN pre-fix, A3 rejects k=2, or a witness fails before the periodic producer.
- [ ] Then: **CB36** `M6-CP3-CB36-RP01-PERIODIC-ROUTE-ATLAS-TRANSPORT` → CB36-REV → **TB37** → TB37-REV.
  - CB36 is production D2 only: the observed steps read `atlas->transport`; a missing transport means `PeriodicHolonomyMismatch(face, targetFace)`; compile only.
  - TB37 covers the witnesses + TB35's 13 + a full 497 census.
- [ ] Then: `M6-CP3-DEFN-RP01-PERIODIC-LEGACY-ORACLE-HOMES` (189–192 re-homing; runtime-free) → CB/TB.
- [ ] Then, one owner per turn: untyped 7 (`selector:174,201,204,242,247,250,405`) → A5 `focused30:12` → A4 `cp3entry:4` → A3 `selector:442` → DEFN-T1 (`cp3entry:1/2`) → census → RP-01 Review. Carried: RA-152.5 axis binding, DEFN-SEAM-NZ, Periodic follow-up, RA-146.2/4, RA-45.4, G4-B002.
- [ ] **Planned (user-directed, 2026-10-21; Review schedules it) — `DIAG-RETAIN`: keep A5–A7 products as diagnostic snapshots.**
  - Retain the A5 corner occurrences (support, placement, wedge bindings), the A5 occurrence relations (kind, endpoints, evidence), the A6 merged quotient classes and the A7 final vertex geometry in `SurfaceCellDiagnosticProductSnapshots` whenever `retainIntermediateGeometry` is set, including every product completed before a rejection.
  - Make them reachable from the GUI (display layers) and the CLI (a diagnostics dump) in those diagnostic contexts.
  - Constraints: one-way observations under the existing snapshot contract, never read back as stage authority; no admission, return-value or ordering change; bounded memory; nothing retained when retention is off.
  - Suggested turns: DEFN (snapshot types, retention point per stage, behaviour on rejection, memory bound) → one CB+TB per product (A5 occurrences and relations; A6 classes; A7 geometry), each with a no-read-back test → CLI dump → GUI layers. It edits `RemeshPipeline.cpp`, so Review must sequence it clear of RP-01 diagnostic and corrective turns.
- **Turn sequence:** TB35 → TB35-REV → TB35-REV-AUDIT (RA-152) → CB35 compiled → **CB35-REV** → TB36 → TB36-REV → CB36 → CB36-REV → TB37 → TB37-REV → DEFN legacy-oracle homes → untyped 7 → `focused30:12` → `cp3entry:4` → `selector:442` → DEFN-T1 → census → RP-01 Review; `DIAG-RETAIN` carried.
- Frozen: stable 66/17/49, debt 1; CP2 491/491 accepted; TB32 481/500 candidate (19 inherited RED); TB35 11 PASS / 2 RED focused candidate; selector 497 frozen; RP-01 open, RP-02 unreached, Gate C suspended.

---

## HISTORY — TB35 run; TB35-REV adjudicated (2026-10-24)

- [x] CB34 static face-gauge correction and independent CB34-REV compile/source review remain accepted (no runtime credit).
- [x] `M6-CP3-TB35-RP01-PERIODIC-ROUTE-GAUGE-VERIFY`: 13/13 immutable fresh processes, **11 PASS / 2 RED**; selector189,190,193–195 PASS, selector191/192 RED (expected A4 `PeriodicHolonomyMismatch` but phase-front `Produced`). Face-gauge invariant, two atlas guards, three factory controls PASS. [TB35 report](.agents/Directional/Architecture_M6_CP3_TB35_Periodic_Route_Gauge_Verification_Report_20261024.md); first zero-test harness preflight failure disclosed, corrected and rerun. No source, test, selector or package changes.
- [x] **TB35-REV:** original manifest SHA and 18/18 artifact hashes verified; 13/13 processes 11 PASS / 2 RED; source review proves 191/192 modify raw matching/provenance discarded by atlas-owned overload. Legacy 189/190 PASS is not non-vacuous migration evidence. [Decision](.agents/Directional/Architecture_M6_CP3_TB35_Periodic_Route_Gauge_Independent_Review_Decision_20261024.md).
- [x] ~~`M6-CP3-DEFN-RP01-PERIODIC-INGRESS-AUTHORITY`~~ withdrawn by RA-152 (premise incomplete: A4 guard dead on atlas path).
- [ ] Preserve prior queue: untyped seven → `focused30:12` → `cp3entry:4` → `selector:442` → DEFN-T1, and `DIAG-RETAIN` separate. No new whole-497 census executed.
- Frozen: stable 66/17/49, debt 1; CP2 accepted 491/491; TB32 candidate 481/500 (19 inherited RED); selector497 frozen; RP-01 open, RP-02 unreached, Gate C suspended.

---

## HISTORY — RA-150 TB34-REV audit; CB34 corrected to a true face gauge (2026-10-24)

- [x] `M6-CP3-TB34-RP01-A3-CYCLE-LOCUS-HARVEST-REV-AUDIT` (RA-150):
  - TB34-REV's invalid-fixture owner is confirmed independently: faces 0/1/30/32 adjacency, all principal matchings 0, vertex-2 **and** vertex-3 stars broken;
  - S2 is unreachable (RA-149.3 withdrawn);
  - the CB34 plan is corrected: a face gauge needs the frame relabel too;
  - switching `sourceField` is prohibited;
  - R3/R4 history recorded. [Decision](.agents/Directional/Architecture_M6_CP3_TB34_REV_Audit_Face_Gauge_Representation_Decision_20261024.md).
- [ ] **EXACT NEXT:** `M6-CP3-CB34-RP01-PERIODIC-ROUTE-FACE-GAUGE-REPAIR`. This is test-only and compile-only. [Amended plan](.agents/Directional/Architecture_M6_CP3_CB34_Periodic_Route_Face_Gauge_Code_Build_Plan_20261024.md).
  - Change `balanced_periodic_route_field` to a representation gauge g(face1)=+1:
    - find the face by route topology;
    - the original matchings must be 0;
    - apply +1/−1/−1 additively on all three face-1 edges, keeping the compact matching consistent and `effort` unchanged;
    - relabel face 1's frame so A3 `rawGauge` shifts by +1.
  - Add the test `BalancedRouteFieldIsPureFaceGauge` (A3 branch-topology invariance; raw +1/−1/−1; the two-edge-only construction still rejects at S1).
  - The seven test bodies, `sourceField` arguments, production code and selectors stay unchanged. Record ≤30 lines.
- [ ] Then: CB34-REV (static; issues the TB35 manifest) → TB35 (7 rows + oracle + 2 A3 guards + 3 TB33 controls) → TB35-REV. If S1 clears but an A4 RED follows → DEFN for the periodic-producer owner.
- [ ] Then, one owner per turn: untyped 7 (`selector:174,201,204,242,247,250,405`) → A5 `focused30:12` → A4 `cp3entry:4` → A3 `selector:442` → DEFN-T1 (`cp3entry:1/2`) → census → RP-01 Review. Carried: DEFN-SEAM-NZ, Periodic follow-up, RA-146.2/4, RA-45.4, G4-B002.
- [ ] **Planned (user-directed, 2026-10-21; Review schedules it) — `DIAG-RETAIN`: keep A5–A7 products as diagnostic snapshots.**
  - Retain the A5 corner occurrences (support, placement, wedge bindings), the A5 occurrence relations (kind, endpoints, evidence), the A6 merged quotient classes and the A7 final vertex geometry in `SurfaceCellDiagnosticProductSnapshots` whenever `retainIntermediateGeometry` is set, including every product completed before a rejection.
  - Make them reachable from the GUI (display layers) and the CLI (a diagnostics dump) in those diagnostic contexts.
  - Constraints: one-way observations under the existing snapshot contract, never read back as stage authority; no admission, return-value or ordering change; bounded memory; nothing retained when retention is off.
  - Suggested turns: DEFN (snapshot types, retention point per stage, behaviour on rejection, memory bound) → one CB+TB per product (A5 occurrences and relations; A6 classes; A7 geometry), each with a no-read-back test → CLI dump → GUI layers. It edits `RemeshPipeline.cpp`, so Review must sequence it clear of RP-01 diagnostic and corrective turns.
- **Turn sequence:** TB34 → TB34-REV → TB34-REV-AUDIT (RA-150) → **CB34** → CB34-REV → TB35 → TB35-REV → untyped 7 → `focused30:12` → `cp3entry:4` → `selector:442` → DEFN-T1 → census → RP-01 Review; `DIAG-RETAIN` carried.
- Frozen: stable 66/17/49, debt 1; CP2 491/491 accepted; TB32 481/500 candidate (19 inherited RED); TB34 5 PASS / 7 RED diagnostic; selector 497 frozen; RP-01 open, RP-02 unreached, Gate C suspended.

---

## HISTORY — CB33-REV; TB34 harvest; TB34-REV (2026-10-24)

- [x] `M6-CP3-CB33-RP01-A3-CYCLE-MISMATCH-LOCUS-DIAGNOSTIC-REV`: independent three-file diff and 28/28 eight-target GMP/GMPXX compile/package audit; `runtimeExecution=false`. S1 row/kind now visible; mathematical S2 unreachable and row-index namespace warning documented in [Architecture_M6_CP3_CB33_A3_Cycle_Mismatch_Locus_Diagnostic_Review_Decision_20261024.md](.agents/Directional/Architecture_M6_CP3_CB33_A3_Cycle_Mismatch_Locus_Diagnostic_Review_Decision_20261024.md). No new runtime acceptance.
- [x] `M6-CP3-TB34-RP01-A3-CYCLE-LOCUS-HARVEST`: [run 40090972464](https://github.com/akashskypatel/Directional/actions/runs/40090972464), result `12558378347`, 17/17 hashes; seven inherited A3 REDs all at `cycle-transport`, `LocalVertex`, row 0, region 0; five controls PASS, 12/12 complete, immutable postflight. [Report](.agents/Directional/Architecture_M6_CP3_TB34_A3_Cycle_Locus_Harvest_Report_20261024.md).
- [x] `M6-CP3-TB34-RP01-A3-CYCLE-LOCUS-HARVEST-REV` — independently adjudicated: two-edge-only gauge fixture invalid, A3 S1 appropriate. [Review](.agents/Directional/Architecture_M6_CP3_TB34_A3_Cycle_Locus_Harvest_Review_Decision_20261024.md).
- [x] (superseded by RA-150 amendment) CB34 handoff by TB34-REV. [Plan](.agents/Directional/Architecture_M6_CP3_CB34_Periodic_Route_Face_Gauge_Code_Build_Plan_20261024.md).
- [x] TB34 independent Review assigned invalid periodic-route fixture as first owner; subsequent CB and immutable TB needed before recovery credit. 19 inherited REDs, CP2 491/491, TB32 481/500 candidate, stable 66/17/49 debt1 unchanged; RP-01 open, RP-02 unreached.

## HISTORY — TB33 run; RA-149 review (2026-10-24)

- [x] `M6-CP3-TB33-RP01-ODD-ATLAS-ORACLE-VERIFICATION`: six prescribed fresh GTest processes on unchanged CB32 package `12541198172`, semantic `30e46b9aabc44925643f46bab20db40962a5e494`; [run 40051854120](https://github.com/akashskypatel/Directional/actions/runs/40051854120), result `12543546779`, 15/15 checksums. **6/6 PASS**, zero RED/invalid/skips/duplicate, immutable postflight, no compile/relink/benchmark. [Report](.agents/Directional/Architecture_M6_CP3_TB33_Odd_Atlas_Oracle_Verification_Report_20261024.md).
- **EXACT NEXT ROLE, CANONICAL ID UNKNOWN:** separate independent TB33 Review of immutable 6-case evidence, raw-source signed inverse/gauge oracles and negative non-vacuity. Do not promote CP3, A5/A6, periodic production, or G4-B002 on TB33 alone.
- **CARRIED:** TB32 481/500 candidate / 19 inherited RED, RA-146.2/4, RA-45.4, G4-B002, DIAG-RETAIN, DEFN-SEAM-NZ, periodic/DEFN-T1. CP2 491/491 accepted, CP3 not, frozen selector497, stable 66/17/49 debt1; RP-01 open, RP-02 unreached.

### Authorized turn sequence

| Step | Canonical turn | Boundary |
|---|---|---|
| 1 — role next | `UNKNOWN` | Independent TB33 Review, assigned by repository authority; do not invent ID |

---

## HISTORY — RA-145 TB31 independent census Review; FG01 Definition next (2026-10-23)

- [x] **TB31-REV accepted as evidence, not gate promotion:** immutable 497/497 with 472 PASS / 25 inherited RED / 0 INVALID, ten RED→PASS and no PASS→RED. Independently verified 1,000 checksum entries, 497 case identities/log hashes and TB28 ledger. Decision `Architecture_M6_CP3_TB31_Selector_497_Census_Review_Decision_20261023.md`.
- [x] **Historical successor (completed, superseded by RA-146):** `M6-CP3-DEFN-FG01-RP01-PERIODIC-FACE-GAUGE-FACTORY-CONTRACT` — documents-only evaluation of `selector:220,221,296,302,304,439`; disambiguate missing fixture face gauge vs checked-factory contract, supply falsifiable options. No code/test/fixture/selector change; next Review before CB.
- [ ] Planned, **not yet authorized** (each independent owner gate): A3 cycle-locus seven → seven untyped producer/oracle cases → A5 `focused30:12` → A4 `cp3entry:4` → A3 `selector:442` → DEFN-T1 `cp3entry:1/2` → new census → RP-01 Review. `DIAG-RETAIN`, `DEFN-SEAM-NZ` and Periodic remain separately gated.
- Frozen: stable 66/17/49, debt1, CP2 491/491 accepted; R3 403/497 rejected; TB31 472/497 candidate only. Selector 497 byte-frozen, RP-01 open, RP-02 UNREACHED, Gate C suspended.

---

## HISTORY — TB31 immutable selector-497 census complete; independent review next (2026-10-23)

- [x] Review (RA-144, TB30-REV):
  - CB29 `2602e7398` matches RA-143.3;
  - TB30 result `12500088095` re-verified (61/61; 29 executed, 22 PASS, 7 RED; exit 0);
  - **M1 10/10 PASS**; 7 non-M1 factory rows unchanged; 12 controls and guards PASS;
  - RA-142.2's static claim confirmed;
  - a census is required because CB29 changes A4 admission for every hard-rail certificate;
  - Review-owned 497-row manifest `Architecture_M6_CP3_TB31_Census_Case_Manifest.tsv` (SHA-256 `b1c135d429f8c659e190f648b8678669cb7c14d393e0db9069568ea3838aa43e`, from TB28's ledger; 472 GUARD + 25 RED; self-check passes; all four binaries link GMP). Record: `Architecture_M6_CP3_TB30_Certificate_Association_Ownership_Verification_Review_Decision_20261023.md`.
- [x] **TB31 COMPLETE:** immutable [run 39959505758](https://github.com/akashskypatel/Directional/actions/runs/39959505758), result `12506242253` SHA-256 `97828fac57a63b5d8ca85ef0e5fd35fb7d5ed71c2b2579cd463bacc20d5e947b`. Exact 497/497 cases, 472 PASS / 25 inherited RED / 0 INVALID; 10 RED→PASS and 0 PASS→RED against TB28; 1,000/1,000 result SHA-256 checks, 497/497 manifest identity/owner/expectation matches; no missing/skips/duplicates/bad controls/unexpected passes; immutable postflight. CB29 source/package and selector unchanged; no compile/relink/benchmark. Own reports: `Architecture_M6_CP3_TB31_Selector_497_Census_Report_20261023.md` and `Architecture_M6_CP3_TB31_Selector_497_Red_Inventory.tsv`.
- [ ] **EXACT NEXT:** `M6-CP3-TB31-RP01-SELECTOR-497-CENSUS-REV` — independent evidence Review. Adjudicate measured 472/497, all 25 inherited REDs, the ten recoveries and zero regressions, and order per-owner turns. No further implementation or census work is authorized in this TB31 turn.
- [ ] Planned, not authorized: per-owner turns (each DEFN or diagnostic first): face-gauge-missing (6) → A3 cycle locus (7, diagnostic) → untyped producer/oracle rows (7) → A5 `focused30:12` → `cp3entry:4` open-rail-chain → `selector:442` → DEFN-T1 (`cp3entry:1/2`) → census → RP-01 Review; `DEFN-SEAM-NZ` and the Periodic follow-up only after a witness.
- [ ] **Planned (user-directed, 2026-10-21; Review schedules it) — `DIAG-RETAIN`: keep A5–A7 products as diagnostic snapshots.**
  - Retain the A5 corner occurrences (support, placement, wedge bindings), the A5 occurrence relations (kind, endpoints, evidence), the A6 merged quotient classes and the A7 final vertex geometry in `SurfaceCellDiagnosticProductSnapshots` whenever `retainIntermediateGeometry` is set, including every product completed before a rejection.
  - Make them reachable from the GUI (display layers) and the CLI (a diagnostics dump) in those diagnostic contexts.
  - Constraints: one-way observations under the existing snapshot contract, never read back as stage authority; no admission, return-value or ordering change; bounded memory; nothing retained when retention is off.
  - Suggested turns: DEFN (snapshot types, retention point per stage, behaviour on rejection, memory bound) → one CB+TB per product (A5 occurrences and relations; A6 classes; A7 geometry), each with a no-read-back test → CLI dump → GUI layers. It edits `RemeshPipeline.cpp`, so Review must sequence it clear of RP-01 diagnostic and corrective turns.
- **Turn sequence:** DEFN-M1-REV (RA-143) → CB29 → CB29-REV → TB30 → TB30-REV (RA-144) → TB31 census [complete] → **TB31-REV** → per-owner turns (face-gauge 6, A3 cycle 7, untyped 7, A5 focused30:12, cp3entry:4, selector:442, DEFN-T1) → census → RP-01 Review.
- Frozen: stable 66/17/49, debt 1, CP2 491/491; R3 403/497 rejected; TB28 462/497 candidate superseded by TB31 472/497 **candidate only**; selector 497 frozen. RP-01 open, RP-02 UNREACHED, Gate C suspended.

---

## HISTORY — CB29 built and reviewed; TB30 verified; RA-144 review (2026-10-23)

- [x] **CB29-REV static ACCEPT:** one-clause diff, A4 certificate authentication/opposite reciprocity, A5 route-before-pair certificate binding, exact GMP 8-target package verified; no runtime acceptance. Decision `Architecture_M6_CP3_CB29_A4_Certificate_Association_Ownership_Review_Decision_20261023.md`.
- [x] **TB30 targeted runtime verification:** [run 39949886169](https://github.com/akashskypatel/Directional/actions/runs/39949886169), artifact `12500088095`, 29/29 with 22 expected PASS (9 controls, 10 M1, 3 A4 authenticity guards), seven expected unchanged typed RED (six face-gauge-missing; one open-rail-chain); zero invalid/skipped/duplicates/unexpected-pass. Result verified 61/61 hashes; no configure/compile/relink/benchmark. `Architecture_M6_CP3_TB30_Certificate_Association_Ownership_Verification_Report_20261023.md`; CP3 not accepted.
- **EXACT NEXT ACTION — independent TB30-REV, canonical ID UNKNOWN:** review the immutable 29-case result, seven typed REDs and ten M1 outcomes; register any causal attribution and future owner. The CB29 independent review requires a separate TB30-REV but does not freeze its full canonical identifier. STOP before another Definition/CB/census until Review identity/authority is assigned.
- [x] DEFN-M1 written and BLOCKED: the ten-row matrix showed that no option fit without deciding A4-versus-A5 ownership.
- [x] Review (RA-143, DEFN-M1-REV):
  - contract accepted;
  - **A4 keeps authenticity** (RA-40.1); **A5 owns edge-to-certificate association** (RA-15/RA-16 §5), which it already enforces in the frozen order (RP:4904–4925, then lookup at RP:5040–5051);
  - only consumers: the A5 lookup and a hash;
  - no passing test depends on A4 association;
  - R2's clause (`80fc1688f`) is not frozen authority. Record: `Architecture_M6_CP3_DEFN_M1_Certificate_Pair_Binding_Precedence_Review_Decision_20261023.md`.
- [x] **CB29 COMPLETE:** `M6-CP3-CB29-RP01-A4-CERTIFICATE-ASSOCIATION-OWNERSHIP` — SCT only, compile only:
  1. in the pair clause SCT:8831–8841, remove both `oppositeEdge`, both `railId`, both route comparisons and the region inequality;
  2. keep the `HardRail` kind checks;
  3. add an RA-15/16/143 comment.

  Verified [compile run 39932638282](https://github.com/akashskypatel/Directional/actions/runs/39932638282), result `12492950387` (28/28 checksums, exact GMP/GMPXX link, 8/8 targets, runtimeExecution=false). Source `2602e7398cdc6f1281abe11a758de35166b6590c`. Record `Architecture_M6_CP3_CB29_A4_Certificate_Association_Ownership_Code_Build_Record_20261023.md`.
- [x] **CB29-REV:** independent static Review accepted; 29-row TB30 manifest issued. No runtime.
- Planned after independent TB30-REV: owners for face-gauge-missing (6), A3 cycle locus (7) / `selector:442`, A5 `focused30:12` → DEFN-T1 (`cp3entry:1/2`) → fixture debt → census (RA-139.5 harness) → RP-01 Review; `DEFN-SEAM-NZ` and the Periodic follow-up only after a witness.
- **Turn sequence:** TB29-REV (RA-141) → audit (RA-142) → DEFN-M1 [BLOCKED] → DEFN-M1-REV (RA-143) → CB29 [complete] → CB29-REV [complete] → TB30 [complete, independent review pending] → **TB30-REV (ID UNKNOWN)** → face-gauge / A3 / A5 owners → DEFN-T1 → fixture debt → census → RP-01 Review.
- Frozen: stable 66/17/49, debt 1, CP2 491/491; R3 403/497 rejected; TB28 462/497 **candidate only**; selector 497 frozen. RP-01 open, RP-02 UNREACHED, Gate C suspended.

---

## HISTORY — RA-142 audit; DEFN-M1 blocked; RA-143 resolution (2026-10-23)

- [x] Audit (RA-142) of the TB29 review (RA-141):
  - re-verified result `12481556884` (92/92; 44 executed, 9 PASS, 35 RED, exit 0) and RA-141's partition;
  - **corrected:** `selector:211/219` (wrong `oppositeEdge`; actual code 0 = `InvalidSourceAuthority`, expected `InvalidOppositeEdge`) and `selector:227/230` (wrong `route`; the factory rejection shows as `InvalidPhaseFrontProduct`) reach the R2 `certificate-pair-binding` clause first (SCT:8833–8837, before SCT:9350), proven statically;
  - M1 = ten rows, and these four are its frozen-precedence oracles. Record: `Architecture_M6_CP3_TB29_Review_Audit_Decision_20261023.md`.
- **EXACT NEXT:** `M6-CP3-DEFN-M1-RP01-CERTIFICATE-PAIR-BINDING-PRECEDENCE` — documents only. Write `Architecture_M6_CP3_DEFN_M1_Certificate_Pair_Binding_Precedence_20261023.md` (at most 100 lines):
  1. clause audit;
  2. ten-row ownership matrix;
  3. option (a), (b) or (c) with RA-15/RA-19/RA-105.3 rationale;
  4. non-weakening table;
  5. corrective-TB predictions and falsifiers (10 M1, 7 non-M1 factory rows, 9 controls);
  6. exclusions with owners.

  STOP if no option meets all ten frozen expectations without changing a test.
- **CONDITIONAL:** `M6-CP3-DEFN-M1-RP01-CERTIFICATE-PAIR-BINDING-PRECEDENCE-REV` — Review: adjudicates; scopes the corrective CB.
- Planned, not authorized: corrective CB (product; scoped by DEFN-M1-REV) → CB-REV → TB (10 M1 rows + 7 non-M1 factory rows + 9 TB29 controls; targeted harness with a Review-owned manifest) → TB-REV → owners for face-gauge-missing (6), A3 cycle locus (7) and `selector:442`, A5 `focused30:12` (each DEFN or diagnostic first) → DEFN-T1 (`cp3entry:1/2`) → fixture debt → census (needs an RA-139.3-compliant harness) → RP-01 Review; `DEFN-SEAM-NZ` and the Periodic follow-up only after a witness.
- **Turn sequence:** TB29H-RP02 → RP02-REV → audit (RA-140) → TB29 → TB29-REV (RA-141) → audit (RA-142) → **DEFN-M1** → DEFN-M1-REV → corrective CB → CB-REV → TB → TB-REV → face-gauge / A3 / A5 owners → DEFN-T1 → fixture debt → census → RP-01 Review.
- Frozen: stable 66/17/49, debt 1, CP2 491/491; R3 403/497 rejected; TB28 462/497 **candidate only**; selector 497 frozen. RP-01 open, RP-02 UNREACHED, Gate C suspended.

---

## HISTORY — TB29 harvested; RA-141 review; RA-142 audit (2026-10-23)

- [x] Audit (RA-140) of the RP02 harness review:
  - reproduced the harness SHA `436f5fff…c9a`, `bash -n`, `--self-test` (12/12) and `--self-check` (44);
  - **new evidence:** the harness's own classifier and extractors on real logs give TB28 35/35 RED → RED and TB27 21/21 PASS → PASS, with a first failure found in 35/35;
  - TB29's missing root-manifest (`e6149577…454b`) and source-archive (`d06d8484…371e`) hashes derived from the package;
  - TB29-REV's decisions pre-registered (M1 scope by factory clause; A3 route; `focused30:12`). Record: `Architecture_M6_CP3_TB29H_RP02_Review_Audit_Decision_20261023.md`.
- [x] **TB29 COMPLETE (artifact-only):** [run 39906802267](https://github.com/akashskypatel/Directional/actions/runs/39906802267), result `12481556884`, CB28A package `12465330920`: 44/44, 9 PASS controls, 35 RED, 0 invalid/controls bad, 92/92 package hashes verified; 13 checked factory, 8 A3, 1 A5, 13 untyped. Report `Architecture_M6_CP3_TB29_Typed_Factory_Cause_Harvest_Report_20261023.md`. No 497-case promotion or stable-count change.
- **EXACT NEXT:** `M6-CP3-TB29-RP01-TYPED-FACTORY-CAUSE-HARVEST-REV` — mandatory independent Review: adjudicate typed first-failure causes, 13 untyped failures, A3/A5 and D2/fixture debt; scope DEFN-M1, no rerun or implementation.
- Planned, not authorized: DEFN-M1 (scoped from measured factory clauses, RA-140.4) → DEFN-M1-REV → corrective CB/TB → DEFN-T1 → fixture debt → census (needs an RA-139.3-compliant harness, RA-139.5) → RP-01 Review; recompile-only CB of `4473e41e9` if package `12465330920` lapses before TB29; `DEFN-SEAM-NZ` and the Periodic follow-up only after a witness.
- **Turn sequence:** TB29H-REV (RA-138) → audit (RA-139) → TB29H-RP02 → RP02-REV → audit (RA-140) → TB29 [done] → **TB29-REV** → DEFN-M1 → DEFN-M1-REV → corrective CB/TB → DEFN-T1 → fixture debt → census → RP-01 Review.
- Frozen: stable 66/17/49, debt 1, CP2 491/491; R3 403/497 rejected; TB28 462/497 **candidate only**; selector 497 frozen. RP-01 open, RP-02 UNREACHED, Gate C suspended.

---

### RA-141 review finding (superseded in part by RA-142)

- [x] Independently verified immutable TB29 artifact `12481556884`: 44/44 logs, 9 PASS, 35 RED, 92/92 hashes; all 35 match TB28 identities, no unmeasured green promotion.
- [x] First-clause measured: M1 R2 certificate pair **six** (`focused30:3,22,23`; `selector:139,140,142`). Six `face-gauge-missing`, one `open-rail-chain`, eight A3, one A5, thirteen untyped are separate until reviewed. A3 189–195 lack cycle-locus proof; `cp3entry:1/2` still lack producer witnesses.
- **Only next after formal review closeout:** `M6-CP3-DEFN-M1-RP01-CERTIFICATE-PAIR-BINDING-PRECEDENCE` (Definition only, six sites, non-weakening, then independent DEFN-REV). Do not launch source work, TB or 497-case census from TB29 alone.
- Independent A3 cycle-locus/fixture, A5 focused30:12, 13 untyped, and RA-139.5 census harness remain later separate obligations; stable 66/17/49, debt 1, CP2 491/491; TB28 462/497 candidate.

---

## HISTORY — TB29H-RP02 built and reviewed; RA-140 audit (2026-10-23)

- [x] Audit (RA-139) of the TB29H review (RA-138):
  - H1–H3 confirmed at the cited lines;
  - **added H4:** `subprocess.run` timeout kills only `/usr/bin/time`; the test keeps running and can append to its log after it is hashed;
  - **added H5:** timing output is merged into the test log (the census harness uses `-o`);
  - **added H6:** reasons are read from the whole log; scope them to the first failure block;
  - GMP preflight verified sound (both packaged binaries have `libgmp.so.10` in `DT_NEEDED`); extractor run over the 35 TB28 logs: 1 typed reason, no early matches;
  - **carried:** the census harness classifies crashes as RED (lines 311–312), so the next census needs an RA-139.3-compliant harness. Record: `Architecture_M6_CP3_TB29H_Review_Audit_Decision_20261023.md`.
- [x] **TB29H RP02 harness correction:** H1–H6, count gate and built-in 12-case self-test landed in `813d377ed5dec911766d18c2568d438121fb592d`. Verified shell syntax, Python compile, 12/12 synthetic cases, 44 manifest entries and 4/4 negative manifest copies. No Directional binaries executed. Record: `Architecture_M6_CP3_TB29H_RP02_Harness_Correction_Code_Build_Record_20261023.md`.
- [x] **RP02-REV accepted (static only):** `M6-CP3-TB29H-RP02-TARGETED-ARTIFACT-HARNESS-CORRECTION-REV` independently rehashed source/manifest, reran `bash -n`, embedded `py_compile`, 12 synthetic cases, 44-row and four negative manifest checks; H1–H6 accepted without Directional runtime. Review: `Architecture_M6_CP3_TB29H_RP02_Harness_Correction_Review_Decision_20261023.md`.
- The RP02 review released `M6-CP3-TB29-RP01-TYPED-FACTORY-CAUSE-HARVEST` — resume 44-case artifact-only TB29 on exact CB28A package with reviewed harness SHA and `EXPECTED_CASE_COUNT=44`; immutable package expires 2026-10-29T22:54:39Z; follow original typed-cause plan and stop rules.
- Planned, not authorized: `M6-CP3-TB29-RP01-TYPED-FACTORY-CAUSE-HARVEST` (resumed: corrected harness at its reviewed SHA + `Architecture_M6_CP3_TB29_Targeted_Case_Manifest.tsv` + `EXPECTED_CASE_COUNT=44` on CB28A package `12465330920`, which expires 2026-10-29T22:54:39Z; recompile-only CB of `4473e41e9` if it lapses) → TB29-REV → DEFN-M1 → DEFN-M1-REV → corrective CB/TB → DEFN-T1 → fixture debt → census (needs an RA-139.3-compliant harness, RA-139.5) → RP-01 Review; `DEFN-SEAM-NZ` and the Periodic follow-up only after a witness.
- **Turn sequence:** TB29 [BLOCKED] → design review (RA-137) → TB29H → TB29H-REV (RA-138) → audit (RA-139) → TB29H-RP02 [done] → **RP02-REV** [done] → **TB29 (resumed; next)** → TB29-REV → DEFN-M1 → DEFN-M1-REV → corrective CB/TB → DEFN-T1 → fixture debt → census → RP-01 Review.
- Frozen: stable 66/17/49, debt 1, CP2 491/491; R3 403/497 rejected; TB28 462/497 **candidate only**; selector 497 frozen. RP-01 open, RP-02 UNREACHED, Gate C suspended.

---

## HISTORY — TB29H built and reviewed (RA-138); RA-139 audit (2026-10-23)

- [x] Design review (RA-137):
  - TB29 stopped correctly (the plan required a separately authorized harness);
  - each targeted TB had been writing a single-use, hard-coded harness, and the TB27 harness supports only one binary;
  - **separation:** Review owns the case manifest `Architecture_M6_CP3_TB29_Targeted_Case_Manifest.tsv` (44 rows, SHA-256 `39fa5eb83e2da1b0668bc7368c5304011ec13de8804c54a2a3466f927c42d236`); the implementation agent builds one reusable input-driven harness;
  - plan's guard trio corrected to RA-130.9's (TB27 rows 19–21). Record: `Architecture_M6_CP3_TB29_Harness_Authorization_Design_Review_Decision_20261023.md`.
- [x] **COMPLETE (static only):** `M6-CP3-TB29H-RP01-TARGETED-ARTIFACT-HARNESS` — control-plane Code + Build, no execution. Create `.agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh`, derived from the TB27 harness:
  1. environment inputs, including `CASE_MANIFEST` and `CASE_MANIFEST_SHA256`;
  2. multi-binary resolution;
  3. one run per case;
  4. typed-reason extraction or `reason-not-observed`;
  5. fail-closed control gates; `unexpected_pass` reported;
  6. `--self-check`.

  Validated with `bash -n`, `py_compile`, and `--self-check` (44 manifest cases PASS; duplicate and unknown-kind copies rejected). Record `Architecture_M6_CP3_TB29H_Targeted_Harness_Code_Build_Record_20261023.md`.
- [x] **REVIEWED / REJECTED:** `M6-CP3-TB29H-RP01-TARGETED-ARTIFACT-HARNESS-REV` (RA-138): timeout/crash can masquerade as RED; count self-check undercommits; A5 diagnostics truncate hyphenated reasons.
- RA-138 issued `M6-CP3-TB29H-RP02-TARGETED-ARTIFACT-HARNESS-CORRECTION` (amended by RA-139) — control-plane harness-only H1–H3 correction, static probes, no binaries/build. Mandatory independent RP02-REV before releasing TB29.
- Planned at the time: `M6-CP3-TB29-RP01-TYPED-FACTORY-CAUSE-HARVEST` (resumed: harness `m6_cp3_targeted_artifact_harness.sh` at its reviewed SHA + manifest `Architecture_M6_CP3_TB29_Targeted_Case_Manifest.tsv` on CB28A package `12465330920`, which expires 2026-10-29T22:54:39Z) → TB29-REV → DEFN-M1 (scoped from measured factory clauses) → DEFN-M1-REV → corrective CB/TB → DEFN-T1 → fixture debt → census → RP-01 Review; `DEFN-SEAM-NZ` and the Periodic follow-up (RA-130.7) only after a witness.
- **Turn sequence:** CB28 → CB28-REV (RA-136) → CB28A → CB28A-REV → TB29 [BLOCKED] → design review (RA-137) → TB29H → TB29H-REV (RA-138 REJECT) → **TB29H-RP02** → RP02-REV → TB29 (resumed) → TB29-REV → DEFN-M1 → DEFN-M1-REV → corrective CB/TB → DEFN-T1 → fixture debt → census → RP-01 Review.
- Frozen: stable 66/17/49, debt 1, CP2 491/491; R3 403/497 rejected; TB28 462/497 **candidate only**; selector 497 frozen. RP-01 open, RP-02 UNREACHED, Gate C suspended.

---

## HISTORY — CB28A built and reviewed; TB29 blocked on harness authorization; RA-137 (2026-10-22/23)

- [x] `M6-CP3-CB28A-RP01-M1-PRECEDENCE-ASSERT-DIAGNOSTICS` — RA-136.3 three message-only asserts, TQ only (+16/−3), semantic `4473e41e94a35f1bf189fa046e86bac92c7391fb`. Exact GMP/GMPXX eight-target compile [run 39867988763](https://github.com/akashskypatel/Directional/actions/runs/39867988763), artifact `12465330920`; 28/28 hashes, `runtimeExecution=false`. Build record: `Architecture_M6_CP3_CB28A_M1_Precedence_Assert_Diagnostics_Code_Build_Record_20261022.md`.
- [x] `M6-CP3-CB28A-RP01-M1-PRECEDENCE-ASSERT-DIAGNOSTICS-REV` — independent Review accepted the exact one-file three-message-only diff and 28/28 immutable GMP/GMPXX compile package; no runtime or CP3 promotion. Decision: `Architecture_M6_CP3_CB28A_M1_Precedence_Assert_Diagnostics_Review_Decision_20261022.md`.
- [x] TB29 started, then BLOCKED before any execution (`a5145e9b9`): `M6-CP3-TB29-RP01-TYPED-FACTORY-CAUSE-HARVEST` — TB29 artifact-only 44-identity typed-cause harvest; exact plan `Architecture_M6_CP3_TB29_Typed_Factory_Cause_Harvest_Plan_20261022.md`; no rebuild, no selector/source/test/fixture changes.
- Planned at the time: TB29-REV → DEFN-M1 → corrective CB/TB → DEFN-T1 → fixture debt → census → RP-01 Review; nonzero-turn and Periodic follow-ups witness-gated.

---

## HISTORY — CB27A built and reviewed; CB28 built and reviewed (RA-136) (2026-10-22)

- [x] Design review (RA-135):
  - the block came from CB27-REV's insistence on the **first** endpoint's **span binding**, but D7's first wedge has one binding (`0/0`), so any same face/sheet binding outside it would be synthetic, and removing it trips `cross-sheet:wedge`;
  - membership is checked for both endpoints. Withdraw the second span's real binding `3/1` from the second wedge `{2/1, 3/1}`;
  - republishing is structural only (RP:3708–3830); A7's per-member checks do not read bindings beyond the sheet set; A6 reads membership only through `certified_seam_direction` → `InvalidIsolationEvidence`;
  - with the membership clause deleted, the tamper would be accepted. Record: `Architecture_M6_CP3_CB27A_Wedge_Membership_Witness_Design_Review_Decision_20261022.md`.
- [x] **CB27A COMPLETE — compile only:** `M6-CP3-CB27A-RP01-A7-WEDGE-MEMBERSHIP-ORACLE-CORRECTION`. Test-only one-path correction, P1–P6 and A6/A7/locus oracles; exact source `f021e8f7b876c261b8337334596f519f4b7652a7`, GMP/GMPXX eight-target compile [run 39838687950](https://github.com/akashskypatel/Directional/actions/runs/39838687950) artifact `12452346647`. No runtime; see `Architecture_M6_CP3_CB27A_Wedge_Membership_Oracle_Code_Build_Record_20261022.md`.
- [x] **CB27A-REV:** accepted static non-vacuity of real D7 span-binding withdrawal under P1–P6; no executed runtime evidence. See `Architecture_M6_CP3_CB27A_Wedge_Membership_Oracle_Review_Decision_20261022.md`.
- [x] **CB28 COMPILED (no runtime):** `M6-CP3-CB28-RP01-FACTORY-ERROR-DIAGNOSTICS` — test-only message formatting on TQ/SP10; source `19aeb3e60e2d762006d95dc4a5007af54f094ee7`; [run 39861294132](https://github.com/akashskypatel/Directional/actions/runs/39861294132), artifact `12460974720`. Independent CB28-REV must audit RA-134.5 scope including stale line references.
- [x] Independent CB28-REV done (RA-136). Was: independent CB28-REV static review (full canonical ID not yet assigned); no runtime, no TB29 before Review.
- Planned at the time: CB28-REV → TB29 (4 A7 negatives + D3/D7 + 3 A7 guards + 21 silent + 4 wrong-code rows, on the CB28 package) → TB29-REV → DEFN-M1 (scoped from measured factory clauses) → DEFN-M1-REV → corrective CB/TB → DEFN-T1 → fixture debt → census → RP-01 Review; `DEFN-SEAM-NZ` and the Periodic follow-up (RA-130.7) only after a witness.
- **Turn sequence:** TB28-REV audit (RA-134) → CB27 → CB27-REV (fourth oracle rejected) → CB27A [BLOCKED] → design review (RA-135) → CB27A [compiled] → CB27A-REV [static accepted] → CB28 [compiled] → **CB28-REV** → TB29 → TB29-REV → DEFN-M1 → DEFN-M1-REV → corrective CB/TB → DEFN-T1 → fixture debt → census → RP-01 Review.
- Frozen: stable 66/17/49, debt 1, CP2 491/491; R3 403/497 rejected; TB28 462/497 **candidate only**; selector 497 frozen. RP-01 open, RP-02 UNREACHED, Gate C suspended.

---

## HISTORY — CB27 compiled and reviewed (CB27-REV); CB27A blocked; RA-135 design resolution (2026-10-22)

- [x] Audit (RA-134) of the TB28 review (RA-133):
  - re-derived the ZIP digest, 1019/1019 files, 497/462/35, and **0 PASS→RED / 13 RED→PASS** against TB21;
  - **correction:** RA-133's "periodic fixture setup" family merged A3-atlas failures (`selector:189–195`) with checked-factory rejections (`selector:220, 221, 296, 302, 304, 439`);
  - the factory is the first failure in **17/35**; **21/35** carry no typed reason;
  - DEFN-M1's scope (10, 17 or a split) is unknown until those reasons are measured. Record: `Architecture_M6_CP3_TB28_Census_Review_Audit_Decision_20261022.md`.
- [x] **CB27 compile-only delivered:** `M6-CP3-CB27-RP01-A7-CERTIFIED-SEAM-NEGATIVE-ORACLES` — test-only, TQ only, compile only. Four D7-fixture negatives, each against the original A6 product (fifth is conditional and omitted):
  1. unrelated seam → `cross-sheet` (precondition: a connecting transition is kept, none on the certificate seam);
  2. no certificate → `cross-sheet:no-certificate`;
  3. lattice coordinate → `cross-sheet:seam-direction` (precondition: support and selectedFace equal);
  4. outside wedge → `cross-sheet:seam-direction` (precondition: binding not in the wedge, and on a certificate face);
  5. same side only if reachable.

  Record `Architecture_M6_CP3_CB27_A7_Certified_Seam_Negative_Oracles_Code_Build_Record_20261022.md`.
- [x] **CB27-REV adjudicated:** three A7 negatives statically discriminating, fourth outside-wedge tamper copies the second endpoint binding and leaves both certificate sides equal; A7 still rejects if wedge-membership guard is deleted. Not accepted as full coverage. Same-side negative not constructible on D7 without earlier guards. Review: `.agents/Directional/Architecture_M6_CP3_CB27_A7_Certified_Seam_Negative_Oracles_Review_Decision_20261022.md`. No runtime or CP3 promotion.
- [x] CB27A started, then BLOCKED (`45d9da85a`): `M6-CP3-CB27A-RP01-A7-WEDGE-MEMBERSHIP-ORACLE-CORRECTION` — test-only correction of the outside-wedge negative, GMP/GMPXX compile only; retain all other tests and product source; STOP if no source-produced discriminating binding exists. Independent CB27A-REV before CB28.
- Planned at the time: CB28 (test-only diagnostic messages for the 21 silent REDs; RA-134.5) → CB28-REV → TB29 (CB27 negatives + D3/D7 + 3 A7 guards + 21 silent + 4 wrong-code rows, on the CB28 package) → TB29-REV → DEFN-M1 (scoped from measured factory clauses) → DEFN-M1-REV → corrective CB/TB → DEFN-T1 → fixture debt → census → RP-01 Review; `DEFN-SEAM-NZ` and the Periodic follow-up (RA-130.7) only after a witness.
- **Turn sequence:** TB27-REV (RA-132) → TB28 → TB28-REV (RA-133) → TB28-REV audit (RA-134) → CB27 [compile-only] → CB27-REV [rejected fourth oracle] → **CB27A** → CB27A-REV → CB28 → CB28-REV → TB29 → TB29-REV → DEFN-M1 → DEFN-M1-REV → corrective CB/TB → DEFN-T1 → fixture debt → census → RP-01 Review.
- Frozen: stable 66/17/49, debt 1, CP2 491/491; R3 403/497 rejected; TB28 462/497 **candidate only**; selector 497 frozen. RP-01 open, RP-02 UNREACHED, Gate C suspended.

---

## HISTORY — TB28 census and RA-133 review; RA-134 audit (2026-10-22)

- [x] **TB28 artifact-only census:** `M6-CP3-TB28-RP01-SELECTOR-497-CENSUS`. Immutable [run 39772864202](https://github.com/akashskypatel/Directional/actions/runs/39772864202), result `12424484672` (SHA-256 `a54110dbb5475b76e6b6a6baa8fc1b7dcabd7aa50c95c5b390532509d1c656e6`), 1019/1019 manifest, 497/497 executed, 462 PASS, 35 RED; vs TB21: 13 RED→PASS (12 seam family + selector:447), zero PASS→RED. Original CB26 package `12409939859`, unchanged harness/selector; no rebuild, relink or benchmark. Report `Architecture_M6_CP3_TB28_Selector_497_Census_Report_20261022.md`, red inventory and full ledger TSV.
- [x] **RA-133 independent TB28 Review:** 1019/1019 result hashes and 497 exact log/identity/hash/verdict records; 13 improvements, zero regressions; 35 inherited REDs classified without invented causes. Candidate-only 462/497, unchanged stable totals. Record `Architecture_M6_CP3_TB28_Selector_497_Census_Review_Decision_20261022.md`.
- RA-133 issued `M6-CP3-CB27-RP01-A7-CERTIFIED-SEAM-NEGATIVE-ORACLES` — RA-132.6 five A7 negatives in `SurfaceCellTransitionQuotientTests.cpp` only (unrelated-seam, no-certificate, different lattice coordinate, outside-wedge and conditional same-side); compile-only and independent CB27-REV, then TB29. Preserve D3/D7 controls and frozen selector; STOP if the tamper cannot reach the intended negative branch.
- (superseded by RA-134; contradictory duplicate removed) Conditional: CB27 test-only negatives (RA-132.6; A7 unrelated-seam, no-certificate, lattice-coordinate and outside-wedge; same-side if constructible), then CB27-REV → TB29 → TB29-REV → DEFN-M1 → corrective CB/TB → DEFN-T1 → fixture debt → census → RP-01 Review. Nonzero-turn and Periodic obligations wait for witnesses.
- Frozen stable 66/17/49, debt 1, CP2 491/491; R3 403/497 rejected; TB28 462/497 **candidate only**; selector 497 byte-frozen. RP-01 OPEN, RP-02 UNREACHED, Gate C suspended.

---

## HISTORY — CB26 compiled and reviewed (RA-131); TB27 verified and reviewed (RA-132) (2026-10-22)

- [x] Review (RA-130, DEFN-SEAM-A7-REV): consumer census, the proof that `relationCertified` can hold, the core rule and the diagnostic are accepted. Binding amendments:
  - **B1:** the frozen D7 test `cp3entry:5` (TQ:3977–4056) requires A7 to accept the certified seam relation and to reject its evidence tamper with site `cross-sheet`; TB27 reports the D7 tamper. §6 correction: the D3 tamper is a face-gauge quarter turn;
  - **B2:** bind spans to `relation.id.first/second` (A7 never checks forest-edge order);
  - **B3:** drop §3.3's explicit pair/binding equality (implied by `certified_seam_wedge_side`);
  - **B4:** the evidence check must contain the certificate's own transition, not any transition connecting the sheet sets;
  - **B5:** sites `cross-sheet:seam-direction`, `cross-sheet` (D7), `cross-sheet:no-certificate`, `cross-sheet:periodic`;
  - **B6:** Periodic disjoint-sheet edges are equally impossible; latent, recorded, out of scope. Record: `Architecture_M6_CP3_DEFN_SEAM_A7_Certified_Seam_Cross_Sheet_Authority_Review_Decision_20261022.md`.
- [x] **CB26 COMPLETE (compile-only):** `M6-CP3-CB26-RP01-A7-CERTIFIED-SEAM-CROSS-SHEET-AUTHORITY` (RA-130.8):
  1. A7 certified-seam branch: direction on canonical endpoints, then the certificate-bound evidence check; B5 sites;
  2. RP:9276–9280 failure-site suffix;
  3. TQ:2811 helper records the A7 code and site;
  4. eight targets compiled with GMP/GMPXX, `runtimeExecution=false`; [run 39744189868](https://github.com/akashskypatel/Directional/actions/runs/39744189868), artifact `12409939859` (28/28 manifest). Record: `Architecture_M6_CP3_CB26_A7_Certified_Seam_Cross_Sheet_Authority_Code_Build_Record_20261022.md`.
  No A5, A6, per-member A7, A8, header, other-test, selector or workflow change.
- [x] **RA-131 Review COMPLETE:** `M6-CP3-CB26-RP01-A7-CERTIFIED-SEAM-CROSS-SHEET-AUTHORITY-REV` — independently accepted the two-path CB26 B1–B6 diff and hashed exact GMP compile evidence; no runtime. Record: `Architecture_M6_CP3_CB26_A7_Certified_Seam_Cross_Sheet_Authority_Review_Decision_20261022.md`.
- [x] **TB27 complete (targeted verification):** `M6-CP3-TB27-RP01-A7-CERTIFIED-SEAM-CROSS-SHEET-VERIFICATION` — compliant [run 39764327506](https://github.com/akashskypatel/Directional/actions/runs/39764327506), artifact `12420676412`, 21/21 PASS; no rebuild/selector edits. Report `Architecture_M6_CP3_TB27_A7_Certified_Seam_Cross_Sheet_Verification_Report_20261022.md`.
- [x] TB27 independent Review done (RA-132). Was: independent TB27 Review is mandatory; RA-131 authorizes the Review *task* but did not assign its canonical turn ID. Independently audit run artifacts, 21 individual test oracles and A7 falsifiers, decide promotion and whether CB27 can be authorized. Do not invent an ID or begin code work.
- Later conditional sequence at the time (only after authorized TB27 completes): TB27-REV → CB27 (negative tests, TQ only: RA-127.4b + A7 unrelated-seam evidence and no-direction) → CB27-REV → TB28 (new tests + selector-497 census) → TB28-REV → DEFN-M1 → corrective CB/TB → DEFN-T1 → fixture debt → census → RP-01 Review; `DEFN-SEAM-NZ` and the Periodic follow-up (RA-130.7) only after a witness.
- **Turn sequence:** TB26-REV (RA-129) → DEFN-SEAM-A7 → DEFN-SEAM-A7-REV (RA-130) → CB26 → CB26-REV (RA-131) → **TB27** → TB27-REV → CB27 → CB27-REV → TB28 (+ census) → TB28-REV → DEFN-M1 → corrective CB/TB → DEFN-T1 → fixture debt → census → RP-01 Review.
- Frozen: stable 66/17/49, debt 1, CP2 491/491; R3 403/497 rejected; TB21 candidate 449/497; selector 497 frozen. RP-01 open, RP-02 UNREACHED, Gate C suspended.

---

## HISTORY — DEFN-SEAM-A7 contract authored and reviewed (RA-130) (2026-10-22)

- [x] Review (RA-129, TB26-REV):
  - harvest verified (ZIP digest, 21/21 manifest, 18 logs with one RUN each); controls PASS; `focused30:26–28` PASS individually;
  - **correction:** `cp3entry:3/5` record `A7:rejected-certified-seam` only after A5 found the certified seam relation and A6 admitted and selected it. RA-127.4 (i)/(ii) discharged; the D3 tamper (iii) is still unmeasured;
  - all nine RED stop in A7 (eight `UncertifiedCrossSheetBinding`, `focused30:24` code unprinted);
  - **proof:** A7's OrdinaryFront cross-sheet rule needs an occurrence wedge transition joining the two endpoints' sheets; wedge transitions only join a wedge's own sheets, so the rule can never pass when the sheets are disjoint, and it ignores the typed seam certificate;
  - RA-127's enforcer audit missed A7 (Review's miss, not CB25's). Record: `Architecture_M6_CP3_TB26_Shared_Node_Seam_Witness_Harvest_Review_Decision_20261022.md`.
- [x] **DEFN-SEAM-A7:** `M6-CP3-DEFN-SEAM-A7-RP01-CERTIFIED-SEAM-CROSS-SHEET-AUTHORITY` — documents-only A7 certified seam contract `Architecture_M6_CP3_DEFN_SEAM_A7_Certified_Seam_Cross_Sheet_Authority_20261022.md` (58 lines); post-A5 consumer census, `relationCertified` proof, amended A7 typed-direction rule, A7 site diagnostic and D3 helper recording, non-weakening matrix, TB27 predictions/falsifiers. No code, build or runtime; source frozen to `575d10ef8e6e`.
- [x] `M6-CP3-DEFN-SEAM-A7-RP01-CERTIFIED-SEAM-CROSS-SHEET-AUTHORITY-REV` done (RA-130) — independent Review adjudicates the six-part contract, audits all cross-sheet decision consumers and freezes CB26 only if the contract passes. Review-only; no compile/runtime/source/test changes.
- CB26 was conditional: only when that Review expressly assigns it; no preauthorization from DEFN.
- Planned at the time: CB26 (RP: A7 rule and failure-site suffix; TQ: helper record only) → CB26-REV → TB27 (the same 18 TB26 selections) → TB27-REV → CB27 (negative tests for RA-127.4b and the A7 table; TQ only) → CB27-REV → TB28 (new tests + selector-497 census) → TB28-REV → DEFN-M1 → corrective CB/TB → DEFN-T1 → fixture debt → census → RP-01 Review; `DEFN-SEAM-NZ` only after a nonzero-turn witness.
- **Turn sequence:** DEFN-SEAM-REV (RA-127) → CB25 → CB25-REV (RA-128) → TB26 → TB26-REV (RA-129) → DEFN-SEAM-A7 [done] → **DEFN-SEAM-A7-REV** → CB26 → CB26-REV → TB27 → TB27-REV → CB27 → CB27-REV → TB28 (+ census) → TB28-REV → DEFN-M1 → corrective CB/TB → DEFN-T1 → fixture debt → census → RP-01 Review.
- Frozen: stable 66/17/49, debt 1, CP2 491/491; R3 403/497 rejected; TB21 candidate 449/497; selector 497 frozen. RP-01 open, RP-02 UNREACHED, Gate C suspended.

---

## HISTORY — CB25 compiled and reviewed (RA-128); TB26 harvested and reviewed (RA-129) (2026-10-22)

- [x] Review (RA-127, DEFN-SEAM-REV): contract scope, non-weakening table, A6/D3 independence and nonzero-turn deferral accepted. Binding amendments:
  - **A1:** equal `support` + `selectedFace` does not identify a node (edge/face supports carry no parameter); also require equal `placement.lattice.latticeCoordinate`. Producer nodes never wrap, so producer data is unaffected;
  - **A2:** the rejection-site classifier (RP:5303–5333) duplicates the face clauses; it must mirror the exemption (RA-118.2);
  - **A3:** TB26 reports, for `cp3entry:3/5`, the certified reciprocal relation, A6 admission and the D3 gauge tamper (TQ:3652–3677);
  - **A4:** negative tests for the new branch are owed (CB26, TQ only);
  - correction: A6 source is unchanged, but A6 stops rejecting shared-node pairs as `InvalidIsolationEvidence`; D3 becomes their guard. Record: `Architecture_M6_CP3_DEFN_SEAM_A5_Shared_Node_Side_Authority_Review_Decision_20261022.md`.
- [x] **CB25 COMPLETE:** `M6-CP3-CB25-RP01-A5-SHARED-NODE-SIDE-AUTHORITY` — Code + Build, compile only, RP only (RA-127.5):
  1. helper `certified_seam_shared_node` (support, `selectedFace`, lattice coordinate all equal);
  2. skip RP:3891–3892 when it holds; every other clause byte-identical;
  3. classifier RP:5303–5333 skips `first-face`/`second-face` when it holds; site format unchanged;
  4. eight targets with GMP/GMPXX, `runtimeExecution=false`; record `Architecture_M6_CP3_CB25_A5_Shared_Node_Side_Authority_Code_Build_Record_20261022.md` (at most 30 lines).
  No A6, A2, header, test, selector, workflow or runtime change.
- [x] **CB25-REV:** `M6-CP3-CB25-RP01-A5-SHARED-NODE-SIDE-AUTHORITY-REV` — RA-128 independently accepted exact RP-only diff and 28/28 GMP package; **no runtime promotion**. Review record: `Architecture_M6_CP3_CB25_A5_Shared_Node_Side_Authority_Review_Decision_20261022.md`.
- [x] **TB26 HARVEST COMPLETE — NOT ACCEPTED:** `M6-CP3-TB26-RP01-A5-SHARED-NODE-SEAM-WITNESS-HARVEST`, [run 39727886868](https://github.com/akashskypatel/Directional/actions/runs/39727886868), result `12403479548`, 21/21 hashes, 18/18 executed, 9 PASS / 9 RED; six controls PASS. Twelve A5-ISO: 3 PASS and 9 RED; six `UncertifiedCrossSheetBinding`, one missing A7, two missing certified reciprocal seams. A6 untampered gauge and D3 tamper were not reached; RA-128 §3 stop/falsifier applies. No stable event/count promotion. Evidence: `Architecture_M6_CP3_TB26_Shared_Node_Seam_Witness_Harvest_Report_20261022.md`.
- [x] Independent TB26 Review done (RA-129): adjudicate TB26 certified-seam witness absence, producer/fixture failures and non-promotion under RA-128 §3; assign a canonical TB26-REV ID from Review authority before entering it. No autonomous CB26 or TB27.
- Planned at the time: independent TB26-REV (canonical ID UNKNOWN) → CB26 (RA-127.4b negative tests, TQ only) → CB26-REV → TB27 (new tests + selector-497 census) → TB27-REV → DEFN-M1 → corrective CB/TB → DEFN-T1 → fixture debt → census → RP-01 Review; `DEFN-SEAM-NZ` only after a nonzero-turn witness.
- **Turn sequence:** TB26 diagnostic harvest complete (not accepted) → independent TB26-REV [canonical ID UNKNOWN; first required decision] → conditional corrective turn assigned by Review. CB26/TB27/DEFN-M1/DEFN-T1 and `DIAG-RETAIN` remain deferred.
- Frozen: stable 66/17/49, debt 1, CP2 491/491; R3 403/497 rejected; TB21 candidate 449/497; selector 497 frozen. RP-01 open, RP-02 UNREACHED, Gate C suspended.

---

## HISTORY — DEFN-SEAM contract authored and reviewed (RA-127) (2026-10-22)

- [x] Review (RA-126, TB25-REV):
  - harvest verified (ZIP digest, 16/16 manifest, 11 logs with one RUN each and no skip); torus `branch=3,3;gaugeSel=0,0;gaugeSpan=0,0;turn0=0,0` (curved), D3 grid `0,0;0,0;0,0;0,0` (uniform); d = F = 0;
  - RA-124.3 P3 confirmed at runtime; routing selects F = 0, so frozen D3 is satisfiable and the A5 face clauses on shared-node relations are the only blocker;
  - `cp3entry:3/5` join A5-ISO (12 rows); RA-124's "adjacent-sheet debt" filing corrected (that item is P10:2670); record: `Architecture_M6_CP3_TB25_Seam_Frame_Values_Harvest_Review_Decision_20261022.md`.
- [x] **DEFN-SEAM authored:** `M6-CP3-DEFN-SEAM-RP01-A5-SHARED-NODE-SIDE-AUTHORITY` — documents only, RA-126.4. Contract `Architecture_M6_CP3_DEFN_SEAM_A5_Shared_Node_Side_Authority_20261022.md` (<=90 lines), independently review before code:
  1. the amended rule: equal `support` and equal `placement.selectedFace` (shared node) → no face-equality clauses; direction from `certified_seam_wedge_side` with opposite sides; every other clause unchanged; non-shared-node relations keep the face clauses;
  2. enforcer impact: RP:4695, RP:5250–5262, RP:5293, RP:5878; A6, D3, the gauge-face check and endpoint gauges unchanged;
  3. non-weakening table with the rejecting clause per case;
  4. corrective-TB predictions and falsifiers.
  No code, compile or runtime; no nonzero-turn seams, A2 change, A6/D3 change, minimum-face rule or new certificate.
- [x] `M6-CP3-DEFN-SEAM-RP01-A5-SHARED-NODE-SIDE-AUTHORITY-REV` done (RA-127) — independent Review: re-derive A5 shared-node side authority, all four enforcers, non-weakening cases, A6/D3 independence and TB falsifiers; issues exact CB25 turn only if accepted. No source/compile/runtime.
- Planned at the time: CB25 → CB25-REV → TB26 (12 A5-ISO rows, guard, controls) → TB26-REV → selector-497 census → DEFN-M1 → corrective CB/TB → DEFN-T1 → fixture debt → census → RP-01 Review; `DEFN-SEAM-NZ` when a nonzero-turn seam is observed.
- **Turn sequence:** CB24 → CB24-REV (RA-125) → interim GUI tooling (network, diagnostics, streamlines, cut graph, target size; build fixes) → TB25 → TB25-REV (RA-126) → DEFN-SEAM [contract authored] → **DEFN-SEAM-REV** → CB25 → CB25-REV → TB26 → TB26-REV → census → DEFN-M1 → corrective CB/TB → DEFN-T1 → fixture debt → census → RP-01 Review.
- Frozen: stable 66/17/49, debt 1, CP2 491/491; R3 403/497 rejected; TB21 candidate 449/497; selector 497 frozen. RP-01 open, RP-02 UNREACHED, Gate C suspended.

---

## HISTORY — TB25 harvested; interim GUI tooling; TB25 reviewed (RA-126) (2026-10-21/22)

- [x] `M6-CP3-CB24-RP01-SEAM-FRAME-VALUES-SITE-REV` — independently verified CB24's RP +28 / TQ +1−6 rejection-only semantic diff; package `12378590512`, 28/28 hashes, GMP/GMPXX, 8 targets, clean source and no runtime. Decision `Architecture_M6_CP3_CB24_Seam_Frame_Values_Site_Review_Decision_20261021.md`.
- [x] Interim `M6-TOOL-VIS-FIELD-NETWORK-GUI-LAYER` (user-directed tooling) — commit `bf518b003`: A2a network polyline adapter, GUI section "6. Field-aligned curve network", 2 adapter tests; display only, RP-01 sources byte-identical to CB24 `dae267a82`. Record: `Architecture_M6_TOOL_VIS_Field_Network_GUI_Layer_Record_20261021.md`.
- [x] Interim `M6-TOOL-README-GUI-BUILD-DOCS` (user-directed) — README: CMake and `setup.py` GUI build commands, complete CMake options, corrected solver defaults, `setup.py` flags and PEP 517 keys; `CMakeLists.txt`: OBJCXX enabled after `project()` for Apple GUI builds (CMake 4.3). No RP-01 source change.
- [x] **TB25:** `M6-CP3-TB25-RP01-SEAM-FRAME-VALUES-HARVEST` — immutable [run 39682528031](https://github.com/akashskypatel/Directional/actions/runs/39682528031), result `12384333036`, 11/11 selected, 6 PASS controls / 5 RED A5+D3, 16/16 manifests/postflight; curved A5 and uniform D3 seam candidates both `d=F=0`. Evidence: `Architecture_M6_CP3_TB25_Seam_Frame_Values_Harvest_Report_20261021.md`. No rebuild or selector changes.
- [x] Independent TB25 Review done (RA-126); canonical ID **UNKNOWN — STOP** pending authoritative assignment. Review immutable artifact, A5-side and D3 fixture interpretation before DEFN-SEAM; do not invent an ID or advance.
- DEFN-SEAM was conditional on independent TB25 Review adjudicates identity-certificate A5-side authority and D3 candidate classification. RP-01 open; M1/D2 and fixture debt remain deferred.
- **Turn sequence:** CB24 → CB24-REV (RA-125) → interim VIS (GUI network layer) → interim README GUI build docs → TB25 [harvest complete] → **TB25-REV [ID UNKNOWN]** → DEFN-SEAM → DEFN-SEAM-REV → corrective CB/TB → DEFN-M1 → corrective CB/TB → DEFN-T1 → fixture debt → census → RP-01 Review.


## HISTORY — Seam-node representative census: DEFN-ISO-A committed and reviewed (RA-124) (2026-10-21)

- [x] `M6-CP3-DEFN-ISO-A-RP01-SEAM-NODE-REPRESENTATIVE-CENSUS` — documents-only census committed `d2e2dc523` (49 lines): `Architecture_M6_CP3_DEFN_ISO_A_Seam_Node_Representative_Census_20261021.md`.
- [x] Review (RA-124, DEFN-ISO-A-REV):
  - Q1 enforcer inventory verified exact; Q5 accepted; Q2 and Q4 amended (annulus never writes `branchRotation`; stripped residual decidable per producer; `point_on_periodic_chart` shared by annulus and curved; 3 of 6 fan faces compared);
  - finding: an OrdinaryFront relation's two occurrences share one producer node, so the A5 certified-seam face clauses are unsatisfiable and A6's stripped turn is identity by construction (uniform/curved); frozen D3 (RA-30a.3) holds only for an identity turn; `cp3entry:3/5` contested as fixture debt;
  - RA-123.6 amended; DEFN-ISO-B withdrawn as relocation; CB24 measures the gauge jump against the certificate turn; record: `Architecture_M6_CP3_DEFN_ISO_A_Seam_Node_Representative_Census_Review_Decision_20261021.md`.

---

## HISTORY — Torus A5 seam-face fields: CB23 compiled and reviewed (RA-122); TB24 harvested and reviewed (RA-123) (2026-10-21)

- [x] `M6-CP3-CB23-RP01-TORUS-A5-SEAM-FACE-SITE` — RP-only +68 diagnostic fields, exact source `e859175333f879273a75e3bfc321600e451048aa`, run [39623185718](https://github.com/akashskypatel/Directional/actions/runs/39623185718), package `12355892070` (28/28, GMP/GMPXX, compile only).
- [x] `M6-CP3-CB23-RP01-TORUS-A5-SEAM-FACE-SITE-REV` — RA-122 independent acceptance of diagnostic scope and immutable package only. Record: `Architecture_M6_CP3_CB23_Torus_A5_Seam_Face_Site_Review_Decision_20261021.md`.
- [x] `M6-CP3-TB24-RP01-TORUS-A5-SEAM-FACE-HARVEST` — run `39641426480`, result `12364838156`; 9/9, 3 A5 RED / 6 PASS, zero skips; site suffix `sel=121/0,121/0;support=vertex,vertex;wedge=120/0+121/0,97/2;spanOnly0=forward`. Report: `Architecture_M6_CP3_TB24_Torus_A5_Seam_Face_Harvest_Report_20261021.md`. Yielded with documentation sync pending; the Review performed it.
- [x] Review (RA-123, TB24-REV):
  - harvest verified (ZIP digest, 14/14 manifest, one RUN per log, raw hashes = ledger); P1/P2 held;
  - both occurrences are one vertex-61 node with one per-node representative `121/0`: inside (0,1)'s wedge, outside (1,0)'s (`97/2`, other sheet); neither B-across nor B-fan; owner the A2 per-node representative (RA-72.4 class);
  - relaxing the face clauses is inadmissible (A6 RP:5832–5877 relies on them); DEFN-ISO split into census (A) and contract (B); record: `Architecture_M6_CP3_TB24_Torus_A5_Seam_Face_Harvest_Review_Decision_20261021.md`.

---

## HISTORY — TB23 reviewed (RA-121): one site owns all ten torus A5 rows; seam-face measurement (CB23) before DEFN-ISO (2026-10-21)

- [x] `M6-CP3-CB23-RP01-TORUS-A5-SEAM-FACE-SITE` — Code + Build, RA-121.5, base `c6e90916e`, RP only, inside the `relation-collinear-seam` block (before `error.isolationSite = std::move(site);`):
  - append `;sel=<a>,<b>` (each canonical occurrence's `placement.selectedFace` as `<row>/<sheet>`), `;support=<a>,<b>` (`vertex`/`edge`/`face`), `;wedge=<a>,<b>` (`cornerWedgeBindings` labels joined by `+`), and `;spanOnlyN=<v>` per matching certificate (classifier without the two face clauses);
  - no decision, return or error-code change; existing site text byte-identical; header, TQ and every other file unchanged; at most 100 columns;
  - eight-target GMP/GMPXX compile, `runtimeExecution=false`; record `Architecture_M6_CP3_CB23_Torus_A5_Seam_Face_Site_Code_Build_Record_20261021.md`;
  - STOP on any compile error or any need to edit outside the block.
- [x] `M6-CP3-CB23-RP01-TORUS-A5-SEAM-FACE-SITE-REV` — mandatory Review: verifies the CB23 diff and package; issues the TB24 plan (RA-121.6 frame).
- Planned at RA-121: TB24 (`focused30:20`, `selector:444`, `focused30:28`; guard `selector:447`; controls `cp3entry:6`, `selector:217`, TB18 A#14, `selector:443`, `focused30:7`) → TB24-REV → DEFN-ISO (B-across: A2 corner chart face on certified seams; B-fan: side from span binding plus in-sheet chart transition) → corrective CB/TB → DEFN-M1 (RA-105.3; also `focused30:12`, `cp3entry:2`) → corrective CB/TB → DEFN-T1 (D2 attainability on the torus) → fixture debt (242 per `Architecture_M6_CP3_CB19_Selector242_Atlas_Authority_Test_Plan_20261020.md`, then 174 → 250 → adjacent-sheet → 191 → 442, plus I/R sites TQ:3017, TQ:3257, TQ:8832, RE:713, P10:7518) → census → RP-01 Review.
- **Turn sequence:** CB22B-REV (RA-120) → TB23 (16/16, 6 PASS / 10 RED) → TB23-REV (RA-121) → **CB23** → CB23-REV → TB24 → TB24-REV → DEFN-ISO → corrective CB/TB → DEFN-M1 → corrective CB/TB → DEFN-T1 → fixture debt → census → RP-01 Review.
- Frozen: 66/17/49, debt 1, CP2 491/491, R3 403/497 rejected, selector 497; candidate evidence TB21 449/497; `RP-01` open, `RP-02` UNREACHED, Gate C suspended.

---

## HISTORY — Torus A5 site harvested: TB23 executed and reviewed (RA-121) (2026-10-21)

- [x] `M6-CP3-TB23-RP01-TORUS-A5-SITE-HARVEST` — run `39609365590`, result `12348649684` (ZIP `5ce73745…6d1`); 16/16 selected, 6 PASS / 10 RED, zero skips, 20/20 result hashes, immutable postflight. Report: `Architecture_M6_CP3_TB23_Torus_A5_Site_Harvest_Report_20261021.md`.
- [x] Review (RA-121, TB23-REV):
  - harvest verified independently (raw-log hashes, single runtime dispatch); pre-execution harness fix `0948a81b0` accepted;
  - P1–P5 held; one byte-identical site on all ten RED rows (`relation-collinear-seam;region=0;seam=60,61;…;cert0=120/0->97/2:first-face`); F closed at candidate level (`selector:447` PASS; `focused30:6` joins A5-ISO);
  - decoded: the A4 certificate equals both spans (faces 120 and 97, the only faces on edge 60–61); occurrence (0,1)'s chart face is not face 120; the face clause is post-CP2 (CP2 used span sheets and transitions only); reverting `8be01326d` is inadmissible;
  - two branches with different owners (B-across, B-fan); CB23 measures before DEFN-ISO; record: `Architecture_M6_CP3_TB23_Torus_A5_Site_Harvest_Review_Decision.md`.

---

## HISTORY — Torus A5 isolation site: CB22 compile stop reviewed (RA-118); CB22A compiled and reviewed (RA-119); CB22B compiled and reviewed (RA-120) (2026-10-21)

- [x] `M6-CP3-CB22-RP01-TORUS-A5-ISOLATION-SITE` — **STOPPED, compile RED**: source `384961bb4ac292e99bf41681117bf8d1d4e9d520` (3 files, +122: TQ atlas line, header `isolationSite`, RP rejection-site diagnostic); run `39564087707` failed at RP:5274–5275 (`OccurrenceId` has no member `index`); no package, no runtime. Record: `Architecture_M6_CP3_CB22_Torus_A5_Isolation_Site_Code_Build_Stop_Record_20261021.md`.
- [x] Review (RA-118, CB22-REV):
  - stop verified: exactly two errors; the rest of RP type-checks; TQ not yet compiled;
  - diff accepted statically against RA-117.5: each side site prints its `transition_between` arguments and certificate; the relation classifier mirrors `certified_seam_direction` clause for clause (`valid` unreachable); `;site=` only on the five isolation returns; no exact consumer of the legacy names; no A5 decision change;
  - root cause: wrong identity projection, not a design defect; design finding: canonical names shadow storage-order names in the relation block (RA-118.4);
  - TB23 frame fixed, with certified-seam control `focused30:7`; record: `Architecture_M6_CP3_CB22_Torus_A5_Isolation_Site_Compile_Stop_Review_Decision.md`.
- [x] `M6-CP3-CB22A-RP01-TORUS-A5-ISOLATION-SITE-FORMATTER` — compile GREEN, harvested by Review (STATUS left `IN_PROGRESS` while the compile ran): source `f082d9aebce0ad72906ccbf70c37a4bf90a9ae6f` (RP only, +29/−23: `<cell>:<corner>` formatter, `canonical` renames); run `39573431400`; package `12333216637`, ZIP `ecde5067…4066`, 28/28, GMP/GMPXX, no runtime; expires 2026-10-28T09:05:23Z.
- [x] Review (RA-119, CB22A-REV):
  - package verified (28/28; 350 source files match git; clean statuses); diff inside RP:5264–5337, no bare old names, no A5 decision change; CB22 + CB22A accepted statically as one compiled unit;
  - design finding: the site reaches only rows printing the pipeline failure string; `focused30:24/25/26/27/28` (including G4-B002) call A5 directly or assert without a message, and four use `torus_fixture()`, so their site cannot be inferred;
  - CB22B authorized (TQ messages only); TB23 frame amended; record: `Architecture_M6_CP3_CB22A_Torus_A5_Isolation_Site_Formatter_Review_Decision.md`.
- [x] `M6-CP3-CB22B-RP01-TORUS-A5-SITE-TEST-MESSAGES` attempt 1 (entered 10:01:18Z) — yielded `IN_PROGRESS` after snapshot runs `39581581511` and `39582530295`; no source change, no compile.
- [x] Review (CB22B-YIELD-REV): HEAD sources identical to `f082d9aeb`; RA-119.4 anchors re-verified (TQ:960–1000, 6008, 6193, 6472–6484, 6544–6556; header :960, :963–971, :1015–1018; `a5Error` used only in the two replaced messages); specification unchanged; CB22B re-entered as a new turn.
- [x] `M6-CP3-CB22B-RP01-TORUS-A5-SITE-TEST-MESSAGES` — compile GREEN: source `c6e90916eb90bfd33bc8a38c5ece7def15dcc766` (TQ only, +22/−24); run `39591106454`; package `12341307713`, ZIP `b5f9a668…8ad5`, 28/28, GMP/GMPXX, no runtime; expires 2026-10-28T11:21:37Z. Record: `Architecture_M6_CP3_CB22B_Torus_A5_Site_Test_Messages_Code_Build_Record_20261021.md`.
- [x] Review (RA-120, CB22B-REV):
  - package verified independently (28/28; 1,046 source files match git; zero warnings); diff exactly RA-119.4; no assertion, fixture or production change;
  - every A5 isolation return carries a site; all nine A5-ISO rows print it; `focused30:24`'s three-fixture lambda resolved by TB23 P3, not by code;
  - TB23 issued: `Architecture_M6_CP3_TB23_Torus_A5_Site_Harvest_Plan_20261021.md`; record: `Architecture_M6_CP3_CB22B_Torus_A5_Site_Test_Messages_Review_Decision.md`.

---

## HISTORY — Torus witness scope: CB21 compiled and accepted (RA-116); TB22 harvested and reviewed (RA-117) (2026-10-21)

- [x] `M6-CP3-CB21-RP01-TORUS-WITNESS-SCOPE` — Code + Build, test-only (TQ), RA-115.5:
  - evaluate every torus witness predicate on every candidate (gauge presence, delta, reciprocal tracer pair, holonomy match), with no early `continue` on the delta;
  - select the first D2-qualifying candidate (`delta ∈ {1,3}`), else the first that passes every non-gauge predicate; throw only if none passes them;
  - add `selectionReceipt` (seven counts, a `c<i>` entry per candidate, `selected=`) as the last member of `ProducedTorusWitnessFixture`, and append it to the throw message;
  - `cp3entry:1` keeps its TQ:2802 D2 assertion and streams the receipt; no other test changes; no `src`/`include`;
  - eight-target GMP/GMPXX compile, `runtimeExecution=false`; record `Architecture_M6_CP3_CB21_Torus_Witness_Scope_Code_Build_Record_20261021.md`;
  - STOP on a compile failure or any need to touch `src`, `include` or another test.
  - **Evidence:** source `8453e19e6ac7d976a9cac45978ad31104a52f034`, run `39540888446` GREEN, package `12318897957`, hashes 28/28, GMP/GMPXX, no runtime. Record: `Architecture_M6_CP3_CB21_Torus_Witness_Scope_Code_Build_Record_20261021.md`.
- [x] **CB21 independent Review (RA-116):** exact one-file GitHub diff and packaged TQ independently checked; 28/28 package hashes, GMP/GMPXX, runtime-free. Static scope/compile accepted only; no selector or runtime promotion. Decision: `.agents/Directional/Architecture_M6_CP3_CB21_Torus_Witness_Scope_Review_Decision_20261021.md`.
- [x] `M6-CP3-TB22-RP01-TORUS-WITNESS-HARVEST`: run `39549820087`, result `12323004201`, exact CB21 source `8453e19e`; 11/11 selected/executed, 4 PASS / 7 RED, immutable postflight. Five previously CP2-GREEN torus cases fail at later assertions, so predicted P1 is false; `cp3entry:1` D2 odd gauge assertion fails with five reciprocal/holonomy matches and zero odd gauges; `focused30:12` A5 RED; four controls PASS. No build or source/selector edits. Full evidence in `Architecture_M6_CP3_TB22_Torus_Witness_Harvest_Report_20261021.md`.
- [x] Review (RA-117, TB22-REV):
  - harvest verified: result `12323004201`, 15/15 hashes, 11/11 executed, 4 PASS / 7 RED, postflight immutable; the report matches the raw logs;
  - falsifier not observed (reciprocal 5/5, holonomy 5/5, `selected=c0`): CB21 accepted at runtime for its scope; `cp3entry:1` RED at its D2 assertion (all five minor-cycle carriers `delta=0`); P1 falsified;
  - F: `focused30:6`, `selector:447` — the torus witness fixture never sets `fieldTransportAtlas` (missed by `7de636c88` while masked);
  - A5-ISO: `focused30:20/24`, `selector:446` — A5 `MismatchedIsolationEvidence` (`a5-side`), the same unowned family as `selector:444/448`, `focused30:26/27/28`; not caused by CB20; branch unknown;
  - record: `Architecture_M6_CP3_TB22_Torus_Witness_Harvest_Review_Decision.md`.

---

## HISTORY — Gauge-pin domain: DEFN-P1 frozen (RA-111); CB20/CB20A accepted (RA-112, RA-113); TB20 and TB21 confirmed at runtime (RA-114, RA-115) (2026-10-20/21)

- [x] `M6-CP3-DEFN-P1-GAUGE-PIN-DOMAIN` — source-only producer-domain definition in `.agents/Directional/Architecture_M6_CP3_DEFN_P1_Gauge_Pin_Domain_Definition_Record_20261020.md`. Exact relation-pair input is not presently published to `make`. Torus {0,3} is same-region. Cut-set inclusion is unproved; hard-carrier producer-domain reachability is a mandatory Review stop check. No implementation/compile/runtime.
- [x] Review (RA-111, DEFN-P1-REV):
  - producer table, torus single region and consumer census confirmed;
  - exactness (RA-110.4 item 3) withdrawn: a same-region, non-hard pin spans every region and fixes the gauge up to a per-region shift;
  - RA-110.5's first STOP withdrawn; cut-set inclusion open but fail-closed;
  - record: `Architecture_M6_CP3_DEFN_P1_Gauge_Pin_Domain_Review_Decision.md`.
- [x] `M6-CP3-CB20-RP01-GAUGE-PIN-DOMAIN`: source `7dc9b89ec` (S +37/−5 inside the pin block, TQ +82/−2). Compile [39512680019](https://github.com/akashskypatel/Directional/actions/runs/39512680019) RED on five test lines; stop record `.agents/Directional/Architecture_M6_CP3_CB20_Gauge_Pin_Domain_Code_Build_Stop_Record_20261020.md`.
- [x] Review (RA-112, CB20-REV):
  - the stop is verified, and the S patch is accepted statically against RA-111.4;
  - root cause: `DomainResult` offers `value()` and has no `operator*`. This is not a design defect;
  - a static walk of the three tests; `RegionGaugeShiftPassesPin` is tightened to require a product;
  - record: `Architecture_M6_CP3_CB20_Gauge_Pin_Domain_Compile_Stop_Review_Decision.md`.
- [x] `M6-CP3-CB20A-RP01-GAUGE-PIN-TEST-ACCESSOR`: source `e22c5da5f` (TQ +9/−12: five accessors and the item 5 product oracle). Compile [39520787768](https://github.com/akashskypatel/Directional/actions/runs/39520787768) GREEN, package `12310848591`. The agent left the turn `IN_PROGRESS` without a record.
- [x] Review (RA-113, CB20A-REV):
  - package verified independently: ZIP digest, 28/28 hashes, empty statuses, build exit 0, no warnings, GMP/GMPXX, `runtimeExecution=false`;
  - the CB20A diff matches RA-112.5; CB20 and CB20A are accepted as one compiled unit (static);
  - TB20 rows (26) and predictions P1–P4 set;
  - record: `Architecture_M6_CP3_CB20A_Gauge_Pin_Domain_Review_Decision.md`.
- [x] `M6-CP3-TB20-RP01-GAUGE-PIN-DOMAIN`: harness `m6_cp3_tb20_gauge_pin_domain_harness.sh` (`18a1325d2`); run [39527537505](https://github.com/akashskypatel/Directional/actions/runs/39527537505), result `12314700010`. The agent left the turn `IN_PROGRESS` after dispatch, without a report.
- [x] Review (RA-114, TB20-REV):
  - harvest verified: 26/26 executed, 19 RED, 30/30 hashes, postflight immutable;
  - P1–P4 observed (suite 3/3, controls 3/3, no pin or factory rejection in any log); the R-route falsifier is not observed;
  - M2 after the pin: `cp3entry:6` PASS; six torus rows at the fixture odd-gauge filter TQ:1697 (added in `88aa8eae0`, after CP2); `cp3entry:2` and `focused30:12` in the hard-rail certificate/A5 area;
  - M1 10/10 unchanged;
  - record: `Architecture_M6_CP3_TB20_Gauge_Pin_Domain_Review_Decision.md`.
- [x] `M6-CP3-TB21-RP01-SELECTOR-497-CENSUS`: unchanged census harness (`947a95ee…79dd`) on CB20A; run [39533914719](https://github.com/akashskypatel/Directional/actions/runs/39533914719), result `12317287104`. The agent left the turn `IN_PROGRESS` after dispatch, without the inventory or report.
- [x] Review (RA-115, TB21-REV):
  - harvest verified: 497/497 executed, 449 PASS / 48 RED, 1019/1019 hashes, postflight immutable; census report absorbed into RA-115.1;
  - 0 PASS→RED, `cp3entry:6` RED→PASS, no `gauge-pin` site in any log: CB20/CB20A regression-free; TB21 replaces TB18 as candidate evidence;
  - inventory `Architecture_M6_CP3_TB21_Selector_497_Red_Inventory.tsv` (48 rows) is the new census baseline;
  - RA-114.3 amended: TQ:1697 is D2 / RA-33.2, placed by `88aa8eae0` in a fixture shared with six CP2-GREEN rows; H-T2 unsupported; reciprocal/holonomy predicates unmeasured;
  - record: `Architecture_M6_CP3_TB21_Selector_497_Census_Review_Decision.md`.

---

## HISTORY — Factory rejection site measured (CB19/CB19A, TB19, TB19A); H-pin confirmed (2026-10-20)

- [x] `M6-CP3-CB19-RP01-FACTORY-REJECTION-SITE`: 47 unique labels; the compile failed at `1f73d0abd` (RA-106).
- [x] `M6-CP3-CB19A-RP01-FACTORY-REJECTION-SITE`: the RA-106.3/106.4 correction, committed as `d2c7483cd`. GMP/GMPXX eight-target compile [39446712217](https://github.com/akashskypatel/Directional/actions/runs/39446712217), package `12275794192` (ZIP `e4a39cdb…d723a`, expires 2026-10-27T15:24Z), no runtime. Record: `.agents/Directional/Architecture_M6_CP3_CB19A_Factory_Rejection_Site_Code_Build_Record_20261020.md`.
- [x] Review (RA-107):
  - CB19A accepted: digest verified, insertions only, 47 labels identical to CB19's.
  - The TB19 specification is corrected: TQ line mapping (+11/+53/+59), `selector:217` = TB18 A#12, a new harness, M1 as a no-regression check only, and `focused30:12`'s edge must be (1,4) or (4,7).
  - Record: `Architecture_M6_CP3_CB19A_Factory_Rejection_Site_Review_Decision.md`.
- [x] TB19 dispatched by the agent: run [39464430751](https://github.com/akashskypatel/Directional/actions/runs/39464430751), artifact `12285225197` (ZIP `2b5dfacf…dec0`, expires 2026-11-03); 22/22 executed. STATUS was left `IN_PROGRESS` while results were pending.
- [x] Review (RA-108):
  - Valid rows: `cp3entry:2/6` and `focused30:12` reject at `gauge-pin-consistency;edge=1,4` (`product=0`); the 10 M1 rows match TB18 after mapping; the 3 controls PASS.
  - The six torus rows are NOT MEASURED: `test-data package not found`. The harness inherited a fixture-staging line from its template that is one directory level too high; this is a gap in Review's spec.
  - The R-route is not reached, because the pin runs before the certificate loop.
  - Record: `Architecture_M6_CP3_TB19_Torus_Staging_Review_Decision.md`.
- [x] `M6-CP3-TB19-RP01-FACTORY-REJECTION-SITE` closeout: report `.agents/Directional/Architecture_M6_CP3_TB19_Factory_Rejection_Site_Harvest_Report_20261020.md` (`b2b2aa9c1`); 16 valid rows, 6 torus NOT MEASURED; falsifier lines per RA-108.3.
- [x] Review (RA-109):
  - The report is accepted: 22/22 raw hashes and TB18 statuses re-checked.
  - Review completed the TODO, CHANGELOG and tracker updates the agent left open, and TB19 is closed.
  - The handoff is restored to the template.
  - TB19A gains a static classification of each torus edge against the 18 row408 hard edges.
  - Record: `Architecture_M6_CP3_TB19_Closeout_Review_Decision.md`.
- [x] `M6-CP3-TB19A-RP01-TORUS-REJECTION-SITE`: harness `m6_cp3_tb19a_torus_rejection_site_harness.sh` (`9aa2a84d6`); run [39484475466](https://github.com/akashskypatel/Directional/actions/runs/39484475466), artifact `12292268624` (ZIP `25d48ed7…7efa7c`, expires 2026-11-03); 7/7, control `selector:443` PASS, 6 torus RED at `gauge-pin-consistency;edge=0,3`; G1–G4 held. Report `.agents/Directional/Architecture_M6_CP3_TB19A_Torus_Rejection_Site_Harvest_Report_20261020.md`. STATUS was left `IN_PROGRESS`.
- [x] Review (RA-110, TB19-REV):
  - TB19A verified independently and accepted; Review closed TB19A.
  - All nine M2 identities reject at the pin; the R-route is NOT REACHED.
  - H-pin CONFIRMED: producers establish face gauges per region and skip accepted cut edges, but the pin checks every two-face edge.
  - `focused30:12` is not uniform-relabel debt.
  - Record: `Architecture_M6_CP3_TB19_REV_Gauge_Pin_Domain_Review_Decision.md`.
---

## HISTORY — CB15 exact I-edge witness compiled; TB15 subsequently executed (2026-10-18)

- [x] `M6-CP3-TB10-R9-CARRIER-ENDPOINT-SUBCONDITION-HARVEST`: TB10 immutable run [38941839640](https://github.com/akashskypatel/Directional/actions/runs/38941839640), result `12062873272` ZIP SHA-256 `4db22a924f31a7bc6fdf1575a66849a2f660a760003e03e26e7f9277ac200513`; compiled source `d938ecb57e1040c2a73d5d25c4a613414556cb18`, artifact `12062565622`. 44/44 selected, 44 RED, 0 missing, 48 A3 observations, 21 exact-one-hot vertices: **contact-endpoint membership 0/21; carrier-edge membership 21/21; composite 0/21**. Example decoded vertex 4, published contact endpoints {1,7}, carrier edge {1,4}, certificate rail 2. Immutable postflight passed, 28/28 package hashes, compile/relink/benchmarks/selector497 not executed. Evidence is candidate/non-stable and does not modify 66/17/49, debt1, CP2 491/491, R3 403/497, selector497; RP-01 open, RP-02 UNREACHED. Independent Review next (ID UNKNOWN); no repair authorized.
- [x] Independent Review (RA-81): TB10 accepted as diagnostic evidence; vertex 4 is the interior vertex of the open rail 1–4–7 and no V/I/C branch admits it. Record: `Architecture_M6_CP3_R9_Carrier_Endpoint_Subcondition_Review_Decision.md`.
- [x] R10 pre-work (`0660af9d1`, user-authorized): `review_check.py` re-baselined to `8b7299b43`; `ROADMAP.md:7` link fixed; root `CHANGELOG.md` is the only changelog. The R10 turn then blocked: its snapshot has no `.git`, so it could not run the history checks.
- [x] Review (RA-82): pre-work verified on a full clone — `boundary` and `ledgers` pass, drift audit 0 errors, 433/433 changelog identifiers kept. History-dependent gates are now Review gates. The verifier rejects an interior-rail-vertex endpoint in two layers (route level and per endpoint). R10 split into R10A/R10B. Record: `Architecture_M6_CP3_R10_Prework_Verification_Review_Decision.md`.
- [x] `M6-CP3-DEFN-R10A-RAIL-INTERIOR-VERTEX-WITNESS-CENSUS`: source-only, two-table rejection/witness census and conditional two-hard-spoke answer; `Architecture_M6_CP3_R10A_Rail_Interior_Vertex_Witness_Census_20261017.md`. No rule, runtime, build or code change.
- [x] Review (RA-83): R10A accepted as facts. Correction: the consumer has no route-level terminal requirement, so it certifies I–I fronts that publication then rejects. Sharpened: the ordered open-rail chain already reaches the consumer (`SurfaceCellTracingOptions::authoritativeRails`, unused) but not the verifier. RA-81/RA-82 records folded. Record: `Architecture_M6_CP3_R10A_Witness_Census_Review_Decision.md`.
- [x] `M6-CP3-DEFN-R10B-RAIL-INTERIOR-VERTEX-ENDPOINT-RULE` documents-only rule authored: `.agents/Directional/Architecture_M6_CP3_R10B_Rail_Interior_Vertex_Endpoint_Rule_20261017.md`. Independent ordered source chain for R (not two-spoke inference), exactly one compatible A3 orientation and disjoint Unique paths; per-endpoint and route-anchor agreement; T–T/T–I unchanged; I–I rejected; T–R/I–R/R–R conditional. Test/counterexample groups A–E specified; no implementation, runtime or promotion. Snapshot `df37ffc1`, run `39080614250`, artifact `12118283137`, 5,646/5,646 verified.
- [x] Review (RA-84): R10B accepted with amendments. Corrections: `hardFeatureEdges`, the terminal pair and the chain come from one rail product (consistency check, not independent evidence), and the factory has no shared-boundary interval. Added clauses: exactly two hard spokes at R; R is the outer vertex of its end step; chain validity at ≥2 vertices. The work is split into U1–U4. Record: `Architecture_M6_CP3_R10B_Endpoint_Rule_Review_Decision.md`.
- [x] `M6-CP3-CB11-R10-OPEN-RAIL-ROUTE-ANCHOR` (U1, compile only): shared factory/consumer open-rail anchor helper and compiled truth-table / forged-terminal regression tests. Exact source `9432aa05ef4719cbea912ae0feb2c5508c4e497a`, workflow `39085601323`, result artifact `12121016836`, SHA-256 `e92158729bf4cfc13432678e8a05cffba4d922feca6e902d8154a535ab1f2676`; GMP/GMPXX 8 targets, 28/28 packaged manifest, no runtime. Record: `.agents/Directional/Architecture_M6_CP3_CB11_R10_Open_Rail_Route_Anchor_Code_Build_Record_20261018.md`.
- [x] `M6-CP3-TB11-R10-OPEN-RAIL-ROUTE-ANCHOR`: run [39092477302](https://github.com/akashskypatel/Directional/actions/runs/39092477302), result `12123605663`. Truth table PASS; both midline-fixture tests RED at `open-rail-route-anchor`, rail 2, front 29/147, edge 1–4. Report: `Architecture_M6_CP3_TB11_Open_Rail_Route_Anchor_Harvest_Report_20261018.md`.
- [x] Review (RA-85): U1 implemented to spec. The fixture has never been `Produced`, so this is not a regression; calling it a control was a Review error. Front 29/147 is an I–I middle segment of the rail, which withdraws RA-84's I–I rejection. The new route rule is an open-chain interval (RA-85.4), and the units are realigned to U2–U5. Record: `Architecture_M6_CP3_TB11_Route_Anchor_Review_Decision.md`.
- [x] `M6-CP3-CB12-R10-OPEN-RAIL-CHAIN-PROVENANCE` (U2, compile-only): ordered open hard-rail source chain is projected, validated at `make`, and published on the phase-front product without admission change. Semantic source `b1b02d5bed43898af0708d76dcd70ada96aeecc9`; GMP eight-target package `12125223513`, workflow `39097975393`; owning CB12 report under `.agents/Directional/`. Compiled tests not executed.
- [x] TB12 first attempt stopped `BLOCKED` before dispatch (`e718548a3`): no harness for CB12's tests, and the handoff barred harness changes.
- [x] Review (RA-86): this was a handoff defect, not orchestration; TB12 authors one new harness like every prior TB. CB12 is accepted after independent verification of the package (`12125223513`, 28/28, source parity). TB11's tests stop in the consumer, so the two full-pipeline RP-01 tests are added as diagnostics, with falsifier `PublishedProductRejected` without `firstPredicate=`. The U3 constraints are fixed now. Record: `Architecture_M6_CP3_TB12_Harness_Authority_Review_Decision.md`.
- [x] `M6-CP3-TB12-R10-OPEN-RAIL-CHAIN-PROVENANCE`: immutable [run 39103358061](https://github.com/akashskypatel/Directional/actions/runs/39103358061), result `12127706461`, 6/6 selected, 2/2 gates PASS, 4/4 RP-01 diagnostics RED as predicted, postflight immutable; owning TB12 report in `.agents/Directional/`. No new stable regression or direct-production acceptance.
- [x] Review (RA-87): every TB12 prediction held; U2 closed. New: `cp3entry:2/6` first fail at B3 (`endpoint-1`, front 17/203; face-0 barycentrics sum to 1 + 2⁻⁵⁵), the RA-61.6 mechanism that R9B left open. RA-85.5 had no unit for it, so U6 is added. The selector has not been measured for 67 source commits, so census TB13C is added. Record: `Architecture_M6_CP3_TB12_Chain_Provenance_Review_Decision.md`.
- [x] `M6-CP3-CB13-R10-OPEN-RAIL-CHAIN-INTERVAL-ROUTE` (U3, compile only, RA-87.4; source `70217cc2`, run `39109464680`, package `12130290543`, all eight GMP targets linked, no runtime; owning record in `.agents/Directional/`):
  - `open_rail_route_interval_valid` replaces the anchor helper in both checkers; consumer predicate `open-rail-chain-interval`;
  - chains mandatory; real chains in every hand-built input with contacts;
  - new truth table.
- [x] `M6-CP3-TB13-R10-OPEN-RAIL-CHAIN-INTERVAL-ROUTE`: [run 39112131501](https://github.com/akashskypatel/Directional/actions/runs/39112131501), result `12130683535`, 6/6 selected, 1 PASS / 5 RED, immutable postflight. The truth-table gate went RED on one row: it expected `[4-7, 1-4]` (no endpoints) to be false, and the helper returned true. P10 #3/#4 moved to B2 (front 61/179, vertex 4); `cp3entry:2/6` stayed byte-identical to TB12 (B3).
- [x] Review (RA-88): the RED row is an owned Review defect. Under the either-direction rule, `[4-7, 1-4]` is the valid reverse walk 7→4→1. The U3 code is accepted, and front 29/147 now passes the consumer interval rule on real data. Record: `.agents/Directional/Architecture_M6_CP3_TB13_Chain_Interval_Review_Decision.md`.
- [x] `M6-CP3-CB13A-R10-OPEN-RAIL-CHAIN-INTERVAL-TRUTH-TABLE` (test-only, RA-88.4): source `e88ac65f`, package `12132184878`, ZIP `36197dff…`; 28/28, GMP, no runtime. The turn stopped before closeout; Review verified the package and closed it (RA-89).
- [x] `M6-CP3-TB13A-R10-OPEN-RAIL-CHAIN-INTERVAL-TRUTH-TABLE`: [run 39121449664](https://github.com/akashskypatel/Directional/actions/runs/39121449664), result `12134411966`; #1/#2 PASS, and #3–#6 are byte-identical to TB13.
- [x] Review (RA-90): TB13A was re-verified and **U3 is closed** (B1 cleared). TB13C can run: all 497 identities exist in their routed binaries, and the R3 baseline is the in-repo TSV, since the artifact expires 2026-10-24. RED classification is now mechanical (RA-90.4).
- [x] `M6-CP3-TB13C-R10-SELECTOR-497-CENSUS`: [run 39127652521](https://github.com/akashskypatel/Directional/actions/runs/39127652521), result `12136761296`; 497 executed, **420 PASS / 77 RED**. The turn stopped after dispatch, so Review closed it out (RA-91.1).
- [x] Review (RA-91): Review built the inventory (`Architecture_M6_CP3_TB13C_Selector_497_Red_Inventory.tsv`). Classes: B1 0, B2 11, B3 19, other 47.
  - **Rule fix:** the B2 rule now also requires a published contact (selector 405 was a vacuous match).
  - **RP-01 owns 30 identities**, all on rail 2 and all RED at R3.
  - **R3 deltas:** 25 R3 RED → PASS (now controls). 8 R3 PASS → RED, held as candidates:
    - curved disk 235/236/294/299: rejected by the checked factory (reclassified by RA-92 as a stale fixture);
    - 242: a test-spec defect from `8df105b56`, not a fail-open;
    - 174/191/442: unattributed.
  - Record: `.agents/Directional/Architecture_M6_CP3_TB13C_Census_Review_Decision.md`.
- [x] `M6-CP3-TB13D-R10-RETAINED-PACKAGE-BISECT`: P1 [run 39132801755](https://github.com/akashskypatel/Directional/actions/runs/39132801755) 422/497; P4 [run 39132921344](https://github.com/akashskypatel/Directional/actions/runs/39132921344) 420/497. P2 and P3 were cancelled while pending (the dispatcher holds one pending run). The turn stopped without a report, so Review closed it out (RA-92.1).
- [x] Review (RA-92): P4 equals CB13A on all 497, so CB13 changed nothing. **None of the 8 is a production regression:**
  - curved disk ×4: a stale fixture after the provenance contract (`c7cb5d68b`/`715fe2d66`); this corrects RA-91.3;
  - 242: a test-spec defect;
  - 191: an atlas build failure in the fixture, with the error code dropped;
  - 174: a non-manifold TriMesh fixture (`18357617a`);
  - 442: an assertion that has never been run (`b9f70f3fe`).

  The U4–U6 hold is discharged. Record: `.agents/Directional/Architecture_M6_CP3_TB13D_Bisect_Review_Decision.md`.
- [x] `M6-CP3-CB14A-R10-CURVED-DISK-RAIL-PROVENANCE` (test-only; RA-92.6): source `2ee499a3403c07be05e8084a669f30c1c735f04a`, one file `tests/SurfaceCellsPhase10Tests.cpp` +78/-7, source-supported 8-edge closed Hard rail and producer-owned provenance; typed factory diagnostics for 235/236/294/299. Compile-only [39138385869](https://github.com/akashskypatel/Directional/actions/runs/39138385869), package `12140756646`, SHA-256 `eee92aeb38ce098c8580a199f340ec65f3bf650df6464d5a3f2b7dfee5add906`, 28/28 manifest, 8/8 targets, GMPXX/GMP, preflight/build 0/0, five clean source statuses, runtimeExecution=false. No tests run; TB14A next. See CB14A record.
- [x] Review (RA-93): CB14A accepted after independent package verification (351 files match the source commit; only P10 changed). Class `Hard` is correct.
  - Finding: `make_curved_disk_with_adjacent_source_sheet` inherits rail provenance that contradicts its own hard edges. Its users 237/253/254 read no rail field.
  - TB14A predictions sharpened. Record: RA-93, appended to `Architecture_M6_CP3_TB13D_Bisect_Review_Decision.md`.
- [x] `M6-CP3-TB14A-R10-CURVED-DISK-CONTROL-CENSUS`: [run 39143325285](https://github.com/akashskypatel/Directional/actions/runs/39143325285), result `12141843937`; **425 PASS / 72 RED**. The turn stopped before committing `TODO.md`/`CHANGELOG.md`, so Review closed it out (RA-94.1).
- [x] Review (RA-94): five tests went RED → PASS against TB13C (199/235/236/294/299), and the REDs are unchanged in substance. The curved-disk `make` control is restored.
  - 199 falsified RA-93.4. A post-R3 fixture repair (`2be228d96`) had been hidden, so 199 is a valid control.
  - Order: DEFN-U6 first, then U4 → U5 (renamed CB15/CB16).
  - Record: `.agents/Directional/Architecture_M6_CP3_TB14A_Curved_Disk_Control_Review_Decision.md`.
- [x] `M6-CP3-DEFN-U6-EXACT-I-ENDPOINT-PARAMETER`: began and requested a source snapshot (run `39148463200`), then stopped `IN_PROGRESS` with no deliverable. It is superseded by DEFN-U6A.
- [x] Review (RA-95):
  - all 19 B3 identities are one template (front 17/203, edge 1–4, span 3, ordinal 1);
  - origin: one exact `location_parameter` (S:17205-17218), rounded per orientation by `boundary_trace_point` (S:16944-16972). The model reproduces both observed hexfloat triples;
  - DEFN-U6 is narrowed to U6A.
  - Record: `.agents/Directional/Architecture_M6_CP3_DEFN_U6_Exact_I_Origin_Review_Decision.md`.
- [x] `M6-CP3-DEFN-U6A-I-ENDPOINT-EXACT-ORIGIN-TRACE` (documents only; RA-95.5). Deliverable `.agents/Directional/Architecture_M6_CP3_DEFN_U6A_I_Endpoint_Exact_Origin_Trace_20261018.md` (37 lines; existing source-authoritative deliverable):
  - verify RA-95.3;
  - trace link 4 to the three checkers;
  - map ordinals to endpoints;
  - give p exactly;
  - compare representations (a)/(b)/(c) with the doubles binding and fail-closed behavior, and recommend one;
  - a CB outline of 10 lines or fewer.
- [x] Review (RA-96): the U6A trace is verified independently. Amendments:
  - A1: the witness is canonical, edge points only;
  - A2: the DEFN's dedup rule would reject every multi-edge side at a shared vertex, so a conflict clears the witness instead;
  - A3: the witness lives inside `SurfaceTracePoint`;
  - A4: the witness is bound bit for bit to one rounding helper; the trust root is the producer.
  - U6 goes first: CB15 (producer witness) and CB16 (checkers); U4/U5 become CB17/CB18. Record: RA-96, appended to `.agents/Directional/Architecture_M6_CP3_DEFN_U6_Exact_I_Origin_Review_Decision.md`.
- [x] `M6-CP3-CB15-R10-EXACT-I-ENDPOINT-WITNESS-PRODUCER` (compile-only; RA-96.4):
  - `SurfaceTracePoint::exactEdgePoint`;
  - `accepted_boundary_trace_point` and `exact_interior_witness_binds`;
  - dedup clears conflicting witnesses;
  - four appended probe fields;
  - three P10 tests.
  - No admission change; exact semantic source `e4785d734e35d2f01ca3ee8099772f6ab5257f4c`.
  - GMP/GMPXX eight-target compile package `12150973440`, source/run/hash in CB15 code-build record; runtimeExecution=false.
- [ ] **NEXT:** `M6-CP3-TB15-R10-EXACT-I-ENDPOINT-WITNESS-PRODUCER` (RA-96.5, nine identities): the 19-identity template must show equal, bound, strictly interior witnesses; bytes outside the new fields must be unchanged. Then TB15-REV issues the CB16 spec.
- [ ] Fixture debt (RA-92.3, RA-93.3), scheduled by RA-96.6 after TB18 as test-only CB/TB pairs, in the order 242 → 174 → 250 → adjacent-sheet → 191 family → 442; none blocks U4–U6:
  - 174: replace the non-manifold three-face TriMesh source;
  - 191 family (189–195): print the atlas build error, then repair the fixture field;
  - 242: retarget the tamper to an input that is actually consumed;
  - 442: either show the seam claim is required (a production gap) or correct its fixture;
  - 250: the composite gives its disk boundary as hard edges with no provenance (P10:3580-3593). It was RED at R3 for another reason;
  - the adjacent-sheet curved-disk helper (P10:2670) must rebuild or clear rail provenance before any `make` use (RA-93.3).
- [ ] Remaining units (RA-85.5, RA-87.3):
  - U6 exact I parameter (19 identities, one template): `M6-CP3-CB15-R10-EXACT-I-ENDPOINT-WITNESS-PRODUCER`, then `M6-CP3-CB16-R10-EXACT-I-ENDPOINT-WITNESS-CHECKERS`;
  - U4 factory admits R (`M6-CP3-CB17-R10-FACTORY-RAIL-VERTEX-ENDPOINT`; 11 identities);
  - U5 consumer emits R (`M6-CP3-CB18-R10-CONSUMER-RAIL-VERTEX-ENDPOINT`).
  - RP-01 closes only after all three blocker shapes are cleared.
- Turn sequence: CB15 → TB15 → TB15-REV → CB16 → TB16 → TB16-REV → CB17/TB17 (U4) → CB18/TB18 (U5) → fixture debt → census → RP-01 Review. A RED TB goes to Review (rule 4). Dispatch several runs only one at a time, after each run starts. DEFN-U6A and RA-96 are done.
- Frozen: `RP-01` unresolved; `RP-02` UNREACHED; Gate C suspended; **66/17/49**, debt **1** (no new production regression; 4 test-debt REDs since R3), accepted M6 CP2 **491/491**, rejected R3 **403/497**, frozen selector **497** unchanged; latest census 425/497 (TB14A).

---

## HISTORY — CB10 compile verified; TB10 artifact-only successor (2026-10-16)

- [x] `M6-CP3-CB10-R9-CARRIER-ENDPOINT-SUBCONDITION-PROBE`: +26 diagnostic-only lines; source `d938ecb57e1040c2a73d5d25c4a613414556cb18`; eight-target GMP/GMPXX compile GREEN [38938801351](https://github.com/akashskypatel/Directional/actions/runs/38938801351); artifact `12062565622`, SHA-256 `30111e7f26c8bbeb7ef9762e31fea5fb449b70c9cbdee64a27d4fc660834ef4f`, 28/28 manifest, 0/0 preflight/build, clean source, `runtimeExecution=false`. Composite predicate unchanged; no runtime membership outcome claimed. Owning record `Architecture_M6_CP3_CB10_Carrier_Endpoint_Subcondition_Probe_Code_Build_Record_20261016.md`.
- [ ] **NEXT:** `M6-CP3-TB10-R9-CARRIER-ENDPOINT-SUBCONDITION-HARVEST` — consume immutable compile artifact, measure both membership halves on authorized selected logs only; no code mutation or hypothetical repair. Strict separation: any subsequent repair/definition requires separate Review authority.
- Ledger 66/17/49, debt 1, CP2 491/491, R3 403/497, frozen selector 497; `RP-01` open, `RP-02` UNREACHED, Gate C suspended. Historical RA-80 and old CURRENT below superseded, not reauthorized.

---

## HISTORY — RA-80 frozen; branch V measured NOT APPLICABLE (0/21); the star path passes and an unexamined membership test fails (2026-10-16)

### Turn sequence (byte-derived from `STATUS` history; frozen clauses in `Architecture_M6_Frozen_Definitions.md`)

| # | Turn | Kind | Review | Outcome |
|---:|---|---|---|---|
| 1-9 | `CB2` → `TB5` (R4/R5 ladder) | mixed | RA-63 … RA-70 | probe/decision separation; mechanism derived; 44/44 RED; RA-68.9 confirmed |
| 10 | `M6-CP3-DEFN-R6-CORNER-ASSIGNMENT-AUTHORITY-SPEC` | Definition | RA-71 | falsified the reviewer's prediction **and** census |
| 11 | `M6-CP3-DEFN-R7-CORNER-FACE-SELECTION-REPAIR-SPEC` | Definition | RA-72 | accepted w/ amendment; passes RA-65.5 |
| 12 | `M6-CP3-CB6-R7-NODE-ADMISSIBLE-FACE-SET-PROBE` | Code + Build | RA-73 | calls the production predicate |
| 13 | `M6-CP3-TB6-R7-NODE-ADMISSIBLE-FACE-SET-HARVEST` | Test + Benchmark | RA-73 | RA-72.8 falsified |
| 14 | `M6-CP3-CB7-R7-LATTICE-UV-CANDIDATE-PROBE` | Code + Build | RA-74 | moved producer-side as instructed |
| 15 | `M6-CP3-TB7-R7-LATTICE-UV-CANDIDATE-HARVEST` | Test + Benchmark | RA-74 | sampler exonerated |
| 16 | `M6-CP3-DEFN-R8-BOUNDARY-OVERRIDE-AUTHORITY-SPEC` | Definition | RA-75 | overriding face legitimately derived |
| 17 | `M6-CP3-CB8-R8-SOURCE-ENTITY-EQUIVALENCE-PROBE` | Code + Build | RA-76 | first probe with deletions — correct |
| 18 | `M6-CP3-TB8-R8-SOURCE-ENTITY-EQUIVALENCE-HARVEST` | Test + Benchmark | RA-76 | **branch (b) settled**; every producer exonerated |
| 19 | `M6-CP3-DEFN-R9-ENDPOINT-EQUIVALENCE-CONTRACT-SPEC` | Definition | RA-77 | **NO DELIVERABLE** — over-scoped by the reviewer; split |
| 19a | `M6-CP3-DEFN-R9A-ENDPOINT-FACE-COMPARISON-CENSUS` | Definition | RA-78 | **found a second active admission path** |
| 19b | `M6-CP3-DEFN-R9B-ENDPOINT-EQUIVALENCE-CONTRACT-SPEC` | Definition | RA-79 | contract admissible; **narrowed RA-78.3** |
| 20 | `M6-CP3-CB9-R9-TERMINAL-STAR-PATH-PROBE` | Code + Build | RA-80 | 270-line hoist **verified semantics-preserving** |
| 21 | `M6-CP3-TB9-R9-TERMINAL-STAR-PATH-HARVEST` | Test + Benchmark | RA-80 | **branch V NOT APPLICABLE, 0/21** |
| **22** | **`M6-CP3-CB10-R9-CARRIER-ENDPOINT-SUBCONDITION-PROBE`** | **Code + Build** | pending | **NEXT — compile-only** |
| 23 | `M6-CP3-TB10-R9-CARRIER-ENDPOINT-SUBCONDITION-HARVEST` | Test + Benchmark | pending | artifact-only harvest of rung 22 |
| 24 | repair or further definition | undetermined | pending | **not authorized**; shape depends on which half fails |

- [x] Rungs 20 and 21 **both ACCEPTED** (RA-80), one charge, one carried note. Decision: `.agents/Directional/Architecture_M6_CP3_R9_Terminal_Star_Path_Review_Decision.md`.
- [x] **RA-80.1 — 0/21.** Re-derived independently from raw logs: 44 files, 48 `a3Probe` records, 21 vertex / 27 non-vertex, every field invariant. `a3ProbeContactPublished=1`, `a3ProbeComponentMatches=1`, `a3ProbeSameExactOneHotVertex=1`, **`a3ProbePublishedCarrierEndpoint=0`**, orientation 0 `Unique`/`Unique`/disjoint/A3 ✓, orientation 1 `Missing`/`Missing`, **`a3ProbeAdmissibleOrientationCount=0`**. **The star path passes**; the failing conjunct is a membership test no rung had examined. Branch V **not applicable** to the 21 — which does **not** make the contract unsound.
- [x] **RA-80.2 — the 270-line hoist is semantics-preserving**, verified by expansion: `matchesA3(spoke, incident[0], incident[1], forward->transport)` reduces exactly to `forward && reverse && reverse->transport == forward->transport.inverse()` because `expected` is bound to `forward->transport` itself. Null guard unreachable (`:8245`); `uniquePathFaces` defaults null and production passes nothing; call site `:8724-8737` structurally unchanged. **No production admission change**; the probe **calls** the hoisted function.
- [x] Charge **RA-80.3** — the inlining was not named. "No change to predicate results" is true but is the claim under test; a reviewer had to reconstruct the equivalence. **When a refactor substitutes a predicate call for its inlined equivalent, name the substitution and say why it is equivalent.**
- [x] Credits: **cross-checked its own instrument** (the harness does not aggregate `a3Probe`, so it scanned all 44 raw logs and said so); **named the deciding conjunct and refused to subclassify**; distinguished "not applicable" from "unsound"; **four disclosed failures all independently `conclusion=failure`** (`38911565252`, `38914058261`, `38914322511`, `38915195172`); **tracker and ORIENTATION written** (RA-79.8 absorbed); beacon `COMPLETE`/`UNKNOWN` with reasoning (RA-79.6 absorbed). **`RP-03` satisfied a fifteenth turn.** Note: gates unreported, eighth mandate — carried.
- [x] **RA-80.7 prediction for rung 22**, falsifier and rung named: the carrier edge at RA-70 is `{1,4}` and the vertex is `4`, so carrier-edge membership should hold, pointing at the **published terminal contact's endpoint set** as the failing half. **Falsifier:** a different carrier reaches the certificate, or the vertex is not an endpoint of it. **Observation rung: 22.**
- [ ] **Rung 22 — `M6-CP3-CB10-R9-CARRIER-ENDPOINT-SUBCONDITION-PROBE` (compile-only, rejection-only).** Split `a3ProbePublishedCarrierEndpoint` into its two halves and emit raw identities on both sides: (1) is the decoded `SourceVertexId` in the **published terminal contact's endpoint set** — emit that set's vertex ids; (2) is it an endpoint of the **carrier's canonical `SourceEdgeTopologyKey`** — emit that edge's two vertex ids; (3) the decoded vertex id, and the carrier edge and rail id actually used at the test. **Do not interpret the fields.**
- [ ] **Rung 23** harvests. **Rung 24** is **not authorized**; its shape depends on which half fails. **Do not reorder rungs 22-24.**
- [ ] Standing: no epsilon anywhere; relocation is not repair (RA-72.5); no new star predicate, no weakening of `unique_terminal_star_path`, `Ambiguous`/`Missing` never acceptable (RA-78.4); gate C suspended; branch I exact-rational strictness and branch C restrictions stand (RA-79.4); do not revive branch (a) (RA-76.1), `point_on_source` as the locus (RA-71.5), or RA-73.5's framing (superseded); admission does **not** compare raw endpoint faces (RA-76.8 amended).
- [ ] Carried: `RP-02` **UNREACHED**. Frozen 66/17/49, debt 1, CP2 491/491, R3 403/497, selector 497. **`R4-VIN-01` re-arms at `18cc4da5e`** — every earlier artifact through `12052388003` is a baseline, never a comparand. RA-61.9, RA-64.6, RA-70.14, RA-72.8 withdrawn; RA-71.5 amended; RA-73.5 superseded; RA-74.1 narrowed and confirmed; RA-76.8 amended; RA-78.3 narrowed. `PROCESS-01` discharged. The historical `ledgers` failure at `b2b6e6541` is permanent for any earlier base, correct, **must not be suppressed, and must never hold a turn open**.

---

## HISTORY — TB9 artifact-only harvest complete; independent Review required (2026-10-16)

- [x] `M6-CP3-CB9-R9-TERMINAL-STAR-PATH-PROBE`: compile-only, source `18cc4da5e2bc41138c5363a74de4e2db1e28ef23`, immutable compile artifact `12052388003`, no runtime in CB9.
- [x] `M6-CP3-TB9-R9-TERMINAL-STAR-PATH-HARVEST`: [run 38921052963](https://github.com/akashskypatel/Directional/actions/runs/38921052963), result `12055460315`, 44/44 selected, 44 RED, 0 missing, postflight immutable. The 48 `a3Probe` observations contain 21 exact-one-hot vertex cases and 27 controls; **0/21** vertex cases satisfy the complete branch-V conjunction because `a3ProbePublishedCarrierEndpoint=0`. Root-cause candidate recorded as non-stable in `Regression_Root_Cause_Tracker.md`; stable ledger unchanged.
- [ ] **Independent Review before any further repair or Code + Build.** The composite published-terminal/carrier-endpoint rejection is not separated into its subconditions; do not infer which fails. Review turn identifier and any next implementation authorization are **UNKNOWN**. Do not initiate conditional rung 22 based on star-path evidence alone. `RP-01` open, `RP-02` unreached; branch I strict, branch C suspended, no relaxation.

Owning report: `.agents/Directional/Architecture_M6_CP3_TB9_Terminal_Star_Path_Harvest_Report_20261016.md`. Earlier CURRENT material below is historical and superseded.

---

## HISTORY — CB9 compile/package verified; TB9 separate (2026-10-16)

The diagnostic-only terminal-star-path probe is compile/package GREEN at `18cc4da5e2bc41138c5363a74de4e2db1e28ef23` (run `38916496178`, artifact `12052388003`, 28/28 packaged hashes, 8/8 targets, mandatory GMP/GMPXX, clean source, no runtime). No test or benchmark executed. CB9 final beacon pending; afterward `M6-CP3-TB9-R9-TERMINAL-STAR-PATH-HARVEST` alone is next. RP-01 open, RP-02 UNREACHED, RA-79 66/17/49, debt1, CP2 491/491, R3 403/497, selector497 unchanged.

---

## HISTORY — CB9 rejection-only terminal-star-path probe (2026-10-16)

Source-only probe committed at `81101d7370a7d3cfe36baa57b4635ef7e0819bb2`; Drive patch-apply `38911327141` verified exact one-path change. GMP/GMPXX eight-target compile dispatched from `a17e59517486470d1a89eceab91b70c5214cce26`; immutable package verification pending. Neither 497 selector nor tests/benchmarks were executed. `RP-01` open, `RP-02` UNREACHED; unchanged 66/17/49, debt1, CP2 491/491, R3 403/497. CB9 remains IN_PROGRESS; TB9 cannot start before CB9 formal closeout.

---

## HISTORY — RA-79 frozen; contract admissible, precedent is a five-part conjunction, applicability to the 21 unmeasured (2026-10-16)

### Turn sequence (byte-derived from `STATUS` history; frozen clauses in `Architecture_M6_Frozen_Definitions.md`)

| # | Turn | Kind | Review | Outcome |
|---:|---|---|---|---|
| 1 | `M6-CP3-CB2-R4-PREDICATE-SEPARATION` | Code + Build | RA-63 | accepted; probe separated from decision |
| 2 | `M6-CP3-CB3-R4-LEDGER-CONTENT-FLOOR` | Code + Build | — | tooling floor added to both gates |
| 3 | `M6-CP3-TB3-R4-PROBE-HARVEST` | Test + Benchmark | RA-64 | accepted; contradicted the reviewer, credited |
| 4 | `M6-CP3-DEFN-R4-ENDPOINT-AUTHORITY-SPEC` | Definition | RA-65 | accepted w/ amendment; RA-64.6 withdrawn, gate C suspended |
| 5 | `M6-CP3-CB4-R4-ENDPOINT-CHART-PROBE` | Code + Build | RA-66 | accepted; compile chain closed by bytes |
| 6 | `M6-CP3-TB4-R4-ENDPOINT-CHART-HARVEST` | Test + Benchmark | RA-67 | accepted; mechanism derived; 44/44 RED |
| 7 | `M6-CP3-DEFN-R5-JUNCTION-CARRIER-AUTHORITY-SPEC` | Definition | RA-68 | accepted; both repair shapes inadmissible |
| 8 | `M6-CP3-CB5-R5-ROUTE-PATH-RECONCILIATION-PROBE` | Code + Build | RA-69 | accepted; neutrality structural |
| 9 | `M6-CP3-TB5-R5-ROUTE-PATH-RECONCILIATION-HARVEST` | Test + Benchmark | RA-70 | accepted; RA-68.9 CONFIRMED |
| 10 | `M6-CP3-DEFN-R6-CORNER-ASSIGNMENT-AUTHORITY-SPEC` | Definition | RA-71 | accepted; falsified the reviewer's prediction **and** census |
| 11 | `M6-CP3-DEFN-R7-CORNER-FACE-SELECTION-REPAIR-SPEC` | Definition | RA-72 | accepted w/ amendment; passes RA-65.5 |
| 12 | `M6-CP3-CB6-R7-NODE-ADMISSIBLE-FACE-SET-PROBE` | Code + Build | RA-73 | accepted; calls the production predicate |
| 13 | `M6-CP3-TB6-R7-NODE-ADMISSIBLE-FACE-SET-HARVEST` | Test + Benchmark | RA-73 | accepted; RA-72.8 falsified |
| 14 | `M6-CP3-CB7-R7-LATTICE-UV-CANDIDATE-PROBE` | Code + Build | RA-74 | accepted; moved producer-side as instructed |
| 15 | `M6-CP3-TB7-R7-LATTICE-UV-CANDIDATE-HARVEST` | Test + Benchmark | RA-74 | accepted; sampler exonerated |
| 16 | `M6-CP3-DEFN-R8-BOUNDARY-OVERRIDE-AUTHORITY-SPEC` | Definition | RA-75 | accepted; overriding face legitimately derived |
| 17 | `M6-CP3-CB8-R8-SOURCE-ENTITY-EQUIVALENCE-PROBE` | Code + Build | RA-76 | accepted; first probe with deletions — correct |
| 18 | `M6-CP3-TB8-R8-SOURCE-ENTITY-EQUIVALENCE-HARVEST` | Test + Benchmark | RA-76 | accepted; **branch (b) settled** |
| 19 | `M6-CP3-DEFN-R9-ENDPOINT-EQUIVALENCE-CONTRACT-SPEC` | Definition | RA-77 | **NO DELIVERABLE** — over-scoped by the reviewer; split |
| 19a | `M6-CP3-DEFN-R9A-ENDPOINT-FACE-COMPARISON-CENSUS` | Definition | RA-78 | accepted; **found a second active admission path** |
| 19b | `M6-CP3-DEFN-R9B-ENDPOINT-EQUIVALENCE-CONTRACT-SPEC` | Definition | RA-79 | accepted; contract admissible; **narrowed RA-78.3** |
| **20** | **`M6-CP3-CB9-R9-TERMINAL-STAR-PATH-PROBE`** | **Code + Build** | complete | compile-only; immutable package verified |
| 21 | `M6-CP3-TB9-R9-TERMINAL-STAR-PATH-HARVEST` | Test + Benchmark | complete | 44 RED, 0/21 vertex contract applicability; Review pending |
| 22 | first repair-implementation rung | undetermined | **not authorized** | conjunction failed (0/21); independent Review required |

- [x] Rung 19b **ACCEPTED** (RA-79) — the strongest Definition turn in this ladder. Decision: `.agents/Directional/Architecture_M6_CP3_R9B_Endpoint_Equivalence_Contract_Review_Decision.md`.
- [x] **RA-79.2 — RA-78.3 NARROWED.** The vertex branch accepts *same vertex, different face* **only when** all five hold: a published open-rail terminal contact agreeing on component; both points decoding the same `SourceVertexId` with **bit-exact one-hot** barycentrics; a **unique** admissible non-hard-feature A3 star path from each side's attachment face to the correspondingly oriented carrier face; **disjoint** directed-side face sets; **exactly one** admissible carrier orientation. **Whether the 21 satisfy that conjunction is unmeasured.**
- [x] **RA-79.3 — specified against both checkers**, with a six-obligation correspondence table, and the residual stated honestly ("pass/fail equivalence is a goal… not an asserted fact").
- [x] **RA-79.4 — two relaxations refused unprompted.** Branch **I** keeps exact `FieldExactRational` equality and names the one-ULP population as not a reason to relax; branch **C** is not promoted. Minimum-face-index selection rejected by name as inadmissible. "No synthetic producer-side vertex-star certificate is introduced" — RA-78.4 honoured.
- [x] **RA-79.5 — non-weakening met**, ten counterexample classes with dispositions; the demanded concrete case is the **324 measured one-ULP instances**, rejected now and still rejected under branch I. F1–F5 stated.
- [x] **RA-79.9 — RA-65.5 satisfied without a new producer**: branch V uses only existing witnesses, with `unique_terminal_star_path` already at `:8452` and enforced at `:8685-8699`. **Code NOT authorized** until applicability is measured.
- [x] Charges: **RA-79.6** beacon self-referential after seven prohibitions and now contradicting its own document (which correctly says `UNKNOWN`); **RA-79.7** gates unreported, seventh mandate — **the instruction conflict is the reviewer's** and is now **RESOLVED AND FROZEN: the mandated base is always the last Review commit; the `b2b6e6541` failure is permanent, expected, and never a reason to hold a turn; "stop on FAILED" applies only at the mandated base.**
- [x] Credits: **`RP-03` satisfied a fourteenth turn** — refused the inference the reviewer drew from the reviewer's own census. Provenance verified (artifact `12047105604` digest matches; trees identical at `6eda761dd`, `f0d724045`, HEAD; `ledgers --base 87b770b6d` ALL CHECKS PASSED). Note (not charged): tracker (fifth omission) and frozen definitions not written; ORIENTATION was.
- [ ] **Rung 20 — `M6-CP3-CB9-R9-TERMINAL-STAR-PATH-PROBE` (compile-only, rejection-only).** Answer the spec's own **F1/F2**: for each rejected endpoint pair emit (1) whether a published `hardRailTerminalContacts[rail]` exists, its component, and whether the decoded vertex is one of its published endpoints and an endpoint of the carrier's canonical source edge; (2) whether **both** points decode the same `SourceVertexId` with **bit-exact one-hot** barycentrics; (3) `unique_terminal_star_path(vertex, attachment, carrierFace)` — `Unique`/`Missing`/`Ambiguous`/`Invalid` — **for each side and both orientations**, by **calling the existing function at `:8452`**; (4) whether the directed-side face sets are disjoint and how many orientations are admissible. **Do not interpret the fields.**
- [ ] **Rung 21** harvests. **Rung 22** implements only if the conjunction holds; if it does not, the contract is sound and the 21 fall outside it — equally a result (RA-68.12). **Do not reorder rungs 20-22.**
- [ ] Standing: no epsilon anywhere; relocation is not repair (RA-72.5); no new star predicate, no weakening of `unique_terminal_star_path`, `Ambiguous`/`Missing` never acceptable (RA-78.4); gate C stays suspended; do not revive branch (a) (RA-76.1), `point_on_source` as the locus (RA-71.5), or RA-73.5's framing (superseded); admission does **not** compare raw endpoint faces (RA-76.8 amended).
- [ ] Carried: `RP-02` **UNREACHED**. Frozen 66/17/49, debt 1, CP2 491/491, R3 403/497, selector 497. **`R4-VIN-01` armed at `f0d724045`**, no new semantic source — every earlier artifact through `12047105604` is a baseline, never a comparand. RA-61.9, RA-64.6, RA-70.14, RA-72.8 withdrawn; RA-71.5 amended; RA-73.5 superseded; RA-74.1 narrowed and confirmed; RA-76.8 amended; **RA-78.3 narrowed**. `PROCESS-01` discharged. The historical `ledgers` failure at `b2b6e6541` is permanent, correct, **must not be suppressed, and must never hold a turn open**.

---

## HISTORY — R9B endpoint-equivalence contract specified (2026-10-16)

- [x] `M6-CP3-DEFN-R9B-ENDPOINT-EQUIVALENCE-CONTRACT-SPEC`: documents-only proposed V/I/C equivalence contract, both consumer checkers, missing/ambiguous rejection proof obligations, one-ULP strict interior limit, RA-65.5 and RA-72.5 dispositions. See `.agents/Directional/Architecture_M6_CP3_R9B_Endpoint_Equivalence_Contract_Specification_20261016.md`. No implementation, compile or runtime authorized; independent review pending with exact successor name UNKNOWN.
- [ ] Obtain independent Review of R9B contract before any producer repair. No selector, frozen accounting or RP-02 promotion. `RP-01` open, Gate C suspended.

---

## HISTORY — RA-78 frozen; census corrects the localization and finds a second active admission path; next rung writes the contract against both (2026-10-16)

### Turn sequence (byte-derived from `STATUS` history; frozen clauses in `Architecture_M6_Frozen_Definitions.md`)

| # | Turn | Kind | Review | Outcome |
|---:|---|---|---|---|
| 1 | `M6-CP3-CB2-R4-PREDICATE-SEPARATION` | Code + Build | RA-63 | accepted; probe separated from decision |
| 2 | `M6-CP3-CB3-R4-LEDGER-CONTENT-FLOOR` | Code + Build | — | tooling floor added to both gates |
| 3 | `M6-CP3-TB3-R4-PROBE-HARVEST` | Test + Benchmark | RA-64 | accepted; contradicted the reviewer, credited |
| 4 | `M6-CP3-DEFN-R4-ENDPOINT-AUTHORITY-SPEC` | Definition | RA-65 | accepted w/ amendment; RA-64.6 withdrawn, gate C suspended |
| 5 | `M6-CP3-CB4-R4-ENDPOINT-CHART-PROBE` | Code + Build | RA-66 | accepted; compile chain closed by bytes |
| 6 | `M6-CP3-TB4-R4-ENDPOINT-CHART-HARVEST` | Test + Benchmark | RA-67 | accepted; mechanism derived; 44/44 RED |
| 7 | `M6-CP3-DEFN-R5-JUNCTION-CARRIER-AUTHORITY-SPEC` | Definition | RA-68 | accepted; both repair shapes inadmissible |
| 8 | `M6-CP3-CB5-R5-ROUTE-PATH-RECONCILIATION-PROBE` | Code + Build | RA-69 | accepted; neutrality structural |
| 9 | `M6-CP3-TB5-R5-ROUTE-PATH-RECONCILIATION-HARVEST` | Test + Benchmark | RA-70 | accepted; RA-68.9 CONFIRMED |
| 10 | `M6-CP3-DEFN-R6-CORNER-ASSIGNMENT-AUTHORITY-SPEC` | Definition | RA-71 | accepted; falsified the reviewer's prediction **and** census |
| 11 | `M6-CP3-DEFN-R7-CORNER-FACE-SELECTION-REPAIR-SPEC` | Definition | RA-72 | accepted w/ amendment; passes RA-65.5 |
| 12 | `M6-CP3-CB6-R7-NODE-ADMISSIBLE-FACE-SET-PROBE` | Code + Build | RA-73 | accepted; calls the production predicate |
| 13 | `M6-CP3-TB6-R7-NODE-ADMISSIBLE-FACE-SET-HARVEST` | Test + Benchmark | RA-73 | accepted; RA-72.8 falsified |
| 14 | `M6-CP3-CB7-R7-LATTICE-UV-CANDIDATE-PROBE` | Code + Build | RA-74 | accepted; moved producer-side as instructed |
| 15 | `M6-CP3-TB7-R7-LATTICE-UV-CANDIDATE-HARVEST` | Test + Benchmark | RA-74 | accepted; sampler exonerated |
| 16 | `M6-CP3-DEFN-R8-BOUNDARY-OVERRIDE-AUTHORITY-SPEC` | Definition | RA-75 | accepted; overriding face legitimately derived |
| 17 | `M6-CP3-CB8-R8-SOURCE-ENTITY-EQUIVALENCE-PROBE` | Code + Build | RA-76 | accepted; first probe with deletions — correct |
| 18 | `M6-CP3-TB8-R8-SOURCE-ENTITY-EQUIVALENCE-HARVEST` | Test + Benchmark | RA-76 | accepted; **branch (b) settled** |
| 19 | `M6-CP3-DEFN-R9-ENDPOINT-EQUIVALENCE-CONTRACT-SPEC` | Definition | RA-77 | **NO DELIVERABLE** — over-scoped by the reviewer; split |
| 19a | `M6-CP3-DEFN-R9A-ENDPOINT-FACE-COMPARISON-CENSUS` | Definition | RA-78 | accepted; **corrected the localization; found a second admission path** |
| **19b** | **`M6-CP3-DEFN-R9B-ENDPOINT-EQUIVALENCE-CONTRACT-SPEC`** | **Definition** | pending | **NEXT — documents only** |
| 20 | first repair-implementation rung | undetermined | pending | **not authorized** |

- [x] Rung 19a **ACCEPTED** (RA-78), one charge, one note. The split worked — RA-77.3 was the right call. Decision: `.agents/Directional/Architecture_M6_CP3_R9A_Endpoint_Face_Comparison_Census_Review_Decision.md`.
- [x] **RA-78.2 — RA-76.8 AMENDED.** Exhaustive search for `(fromPoint|toPoint|first\.(from|to)|second\.(from|to))\.face\s*[!=]=` returns **no matches**: there is **no direct endpoint-to-endpoint face comparison**. The demand is indirect — `oriented_carrier` (`:19253-19261`) requires its ordered face pair to equal the endpoint-derived attachments, and `path_to(firstAttachment, oriented.firstFace)` (`:19425-19450`) takes its start face from the endpoint's representative.
- [x] **RA-78.3 THE DISCOVERY — a second active admission path at `:8621-8736`**, never previously examined. Its interior branch returns `InvalidSourceAuthority` on `carrier.firstFace != endpoint.firstAttachment` etc. **(1) Any repair must satisfy two independent checkers.** **(2) The vertex branch already implements the needed relation** — `exact_vertex_attachment` plus `unique_terminal_star_path(...)==Unique`, rejecting `Missing`/`Ambiguous` (`:8685-8699`). **"Same vertex, different face, unique star path" is already production behaviour**, and the measured 21 are vertex cases.
- [x] **RA-78.4 — the vertex-star prohibition clarified.** Gate C concerns a **producer-authored pre-admission** certificate that does not exist and **stays SUSPENDED**; `unique_terminal_star_path` is a **consumer-side lambda at `:8452`**, already enforced. **The prohibition bars inventing a new producer-authored certificate, not reasoning about the existing consumer-side check.** No new star predicate; no weakening of `unique_terminal_star_path`; `Ambiguous`/`Missing` never acceptable.
- [x] **RA-78.5 — the one-ULP hazard is consequential.** `same_interior_carrier_point` (`:91-97`) is exact rational equality (`*a == *b`); RA-76.7's one-ULP difference would reject outright. Not the current cause (the 21 are vertex cases) but a live constraint. **No epsilon.**
- [x] Charge **RA-78.7** — neither gate run or reported, **sixth consecutive mandate**. Both pass; the defect is the silence. Not cosmetic: the `ledgers` gate is exactly what detects RA-74.6, the one real integrity incident. **The ask is changed:** paste **one line each** — the final `ALL CHECKS PASSED` / `FAILED:` line from each gate — verbatim into the closeout.
- [x] Credits: **search queries stated verbatim** (RA-71.4 applied); **respected the split** and did not drift into 19b; honest hedging where the source does not settle a classification; beacon `COMPLETE` with `Successor: UNKNOWN` and reasoning; transport limitation disclosed. **`RP-03` satisfied a thirteenth turn.** Note (not charged): tracker (4th), ORIENTATION (3rd) and frozen definitions not written — the Review writes all three.
- [ ] **Rung 19b — `M6-CP3-DEFN-R9B-ENDPOINT-EQUIVALENCE-CONTRACT-SPEC` (documents only).** (1) **Specify the contract against BOTH checkers** — the endpoint certificate (`:19265-19495`) and the checked-product verifier (`:8621-8736`); a rule satisfying one and not the other is not a candidate. (2) **Prove it is not a weakening** by exhibiting what it still rejects; the vertex branch at `:8685-8699` is the precedent — show what `Missing` and `Ambiguous` still exclude. (3) **State what happens at interior endpoints**, where exact rational equality and the one-ULP difference collide; if the contract does not cover them, say so. (4) **Apply RA-65.5** and classify each candidate as repair or **relocation** (RA-72.5).
- [ ] **Rung 20** implements only after 19b. **Do not reorder 19b / 20 and do not pre-empt them.**
- [ ] Standing: no epsilon anywhere; relocation is not repair (RA-72.5); no new star predicate and gate C stays suspended; do not revive branch (a) (zero support, RA-76.1), `point_on_source` as the locus (RA-71.5 amended), or RA-73.5's framing (superseded); do not claim the override is junction-specific (RA-74.1 narrowed, RA-76.2 confirmed otherwise).
- [ ] Carried: `RP-02` **UNREACHED**. Frozen 66/17/49, debt 1, CP2 491/491, R3 403/497, selector 497. **`R4-VIN-01` armed at `f0d724045`**, no new semantic source — every earlier artifact through `12040008801` is a baseline, never a comparand. RA-61.9, RA-64.6, RA-70.14, RA-72.8 withdrawn; RA-71.5 amended; RA-73.5 superseded; RA-74.1 narrowed and confirmed; **RA-76.8 amended**. `PROCESS-01` discharged. The historical `ledgers` failure at `b2b6e6541` is permanent for any earlier base, correct, and **must not be suppressed**.

---

## HISTORY — R9A endpoint face-comparison census delivered; independent Review required (2026-10-16)

- [x] `M6-CP3-DEFN-R9A-ENDPOINT-FACE-COMPARISON-CENSUS` — static, document-only census: `.agents/Directional/Architecture_M6_CP3_R9A_Endpoint_Face_Comparison_Census_20261016.md`. Active constructor, face-keyed A3 sector paths, independent checked-product validator, and rejection-only diagnostics distinguished with source line anchors. The exact source snapshot was `b34c571768e2227a8ea2fed42e7b287e21e466eb`; semantic producer `f0d724045` unchanged. RA-76's 48 same-source-vertex mismatched-face samples and 324 exact one-ULP same-edge representations retained without claiming parameter identity or tolerance.
- [ ] **Next authorization gate: independent R9A census Review**, not R9B implementation or predicate design. R9B remains conditional on review of the census; it alone owns the contract and non-weakening proof. No formal review turn identifier is assumed here.
- [ ] `RP-01` consumer remains unresolved; `RP-02` UNREACHED; gate C SUSPENDED; source, selectors, fixtures, tests, binaries and frozen accounting unchanged (66/17/49, debt 1, CP2 491/491, R3 403/497, selector 497). No runtime measurement or green claim.
- **Procedure:** `READ_MODE=snapshot` was chosen late, after initial direct document reads (recorded policy miss). An earlier successful snapshot was verified (5,672/5,672 hashes), and semantic source was compared to the entry head; a Library preservation upload failed with `container_session_unavailable`. The document was committed directly through the GitHub connector, not misrepresented as a Drive patch application.

---

## HISTORY — RA-77 frozen; rung 19 returned no deliverable and is split into 19a/19b; the reviewer over-scoped it (2026-10-16)

### Turn sequence (byte-derived from `STATUS` history; frozen clauses in `Architecture_M6_Frozen_Definitions.md`)

| # | Turn | Kind | Review | Outcome |
|---:|---|---|---|---|
| 1 | `M6-CP3-CB2-R4-PREDICATE-SEPARATION` | Code + Build | RA-63 | accepted; probe separated from decision |
| 2 | `M6-CP3-CB3-R4-LEDGER-CONTENT-FLOOR` | Code + Build | — | tooling floor added to both gates |
| 3 | `M6-CP3-TB3-R4-PROBE-HARVEST` | Test + Benchmark | RA-64 | accepted; contradicted the reviewer, credited |
| 4 | `M6-CP3-DEFN-R4-ENDPOINT-AUTHORITY-SPEC` | Definition | RA-65 | accepted w/ amendment; RA-64.6 withdrawn, gate C suspended |
| 5 | `M6-CP3-CB4-R4-ENDPOINT-CHART-PROBE` | Code + Build | RA-66 | accepted; compile chain closed by bytes |
| 6 | `M6-CP3-TB4-R4-ENDPOINT-CHART-HARVEST` | Test + Benchmark | RA-67 | accepted; mechanism derived; 44/44 RED |
| 7 | `M6-CP3-DEFN-R5-JUNCTION-CARRIER-AUTHORITY-SPEC` | Definition | RA-68 | accepted; both repair shapes inadmissible |
| 8 | `M6-CP3-CB5-R5-ROUTE-PATH-RECONCILIATION-PROBE` | Code + Build | RA-69 | accepted; neutrality structural |
| 9 | `M6-CP3-TB5-R5-ROUTE-PATH-RECONCILIATION-HARVEST` | Test + Benchmark | RA-70 | accepted; RA-68.9 CONFIRMED |
| 10 | `M6-CP3-DEFN-R6-CORNER-ASSIGNMENT-AUTHORITY-SPEC` | Definition | RA-71 | accepted; falsified the reviewer's prediction **and** census |
| 11 | `M6-CP3-DEFN-R7-CORNER-FACE-SELECTION-REPAIR-SPEC` | Definition | RA-72 | accepted w/ amendment; passes RA-65.5 |
| 12 | `M6-CP3-CB6-R7-NODE-ADMISSIBLE-FACE-SET-PROBE` | Code + Build | RA-73 | accepted; calls the production predicate |
| 13 | `M6-CP3-TB6-R7-NODE-ADMISSIBLE-FACE-SET-HARVEST` | Test + Benchmark | RA-73 | accepted; RA-72.8 falsified |
| 14 | `M6-CP3-CB7-R7-LATTICE-UV-CANDIDATE-PROBE` | Code + Build | RA-74 | accepted; moved producer-side as instructed |
| 15 | `M6-CP3-TB7-R7-LATTICE-UV-CANDIDATE-HARVEST` | Test + Benchmark | RA-74 | accepted; sampler exonerated |
| 16 | `M6-CP3-DEFN-R8-BOUNDARY-OVERRIDE-AUTHORITY-SPEC` | Definition | RA-75 | accepted; overriding face legitimately derived |
| 17 | `M6-CP3-CB8-R8-SOURCE-ENTITY-EQUIVALENCE-PROBE` | Code + Build | RA-76 | accepted; first probe with deletions — correct |
| 18 | `M6-CP3-TB8-R8-SOURCE-ENTITY-EQUIVALENCE-HARVEST` | Test + Benchmark | RA-76 | accepted; **branch (b) settled** |
| 19 | `M6-CP3-DEFN-R9-ENDPOINT-EQUIVALENCE-CONTRACT-SPEC` | Definition | RA-77 | **NO DELIVERABLE — over-scoped by the reviewer; split** |
| **19a** | **`M6-CP3-DEFN-R9A-ENDPOINT-FACE-COMPARISON-CENSUS`** | **Definition** | pending | **NEXT — documents only** |
| 19b | `M6-CP3-DEFN-R9B-ENDPOINT-EQUIVALENCE-CONTRACT-SPEC` | Definition | pending | contract + non-weakening proof; **not authorized until 19a is reviewed** |
| 20 | first repair-implementation rung | undetermined | pending | **not authorized** |

- [x] Rung 19 examined: **no deliverable**. Four commits — `c5121b3bf` STATUS flip, `2ee549827` trigger added, `b34c57176` trigger removed (net zero), `ecb175b92` **empty commit**. `git diff --stat c3e1e2948..HEAD` = **one file, `STATUS`**. Nothing to accept, reject or charge. Decision: `.agents/Directional/Architecture_M6_CP3_R9_Rung_Rescope_Review_Decision.md`.
- [x] **The turn did start properly** — snapshot runs `38886874381` and `38888296894` both `conclusion=success`; beacon left `IN_PROGRESS` with **`Successor: UNKNOWN`**, correct under RA-63.13 and **not self-referential**, so **RA-76.6 is absorbed**.
- [x] **RA-77.2 — the scope was the reviewer's and it was wrong.** Q3 asked for a soundness proof; no prior Definition turn in this ladder was asked to prove a predicate sound. Bundling a mechanical census with a soundness proof violates the standing instruction against monolithic turns.
- [x] **RA-77.3 — the split.** 19a = former Q1+Q2 (mechanical census + producer guarantee); 19b = former Q3+Q4 (contract + non-weakening proof, scoped by 19a).
- [x] **RA-77.4 — nothing else changes.** `RP-01` stands where RA-76.8 left it: every producer exonerated, the **consumer's endpoint-equivalence contract** the sole remaining candidate, **code NOT authorized**. `RP-02` **UNREACHED**. No new semantic source.
- [x] **Rung 19a — `M6-CP3-DEFN-R9A-ENDPOINT-FACE-COMPARISON-CENSUS` (documents only, pure static reading).** (1) Enumerate every comparison in the admission path testing `SurfaceTracePoint::face` or performing a face-keyed lookup against a corner — `find_carrier`, `oriented_carrier`, `exact_corner`, the no-exact-terminal-corner test, the closed-chain branch, anything else — with line anchors, and for each say whether it **needs a face** or whether a face was merely **the available handle**. **State the query you ran, not only its result** (RA-71.4). (2) State precisely what the producers guarantee — source-entity identity, not face identity (RA-75.2, RA-76.1), with the **one-ULP edge-parameter caveat** (RA-76.7): what is promised about vertices, edge points and interior points, and what is **not**. **Do not design the contract and do not propose a repair.**
- [ ] **Rung 19b** writes the contract and proves it is not a weakening, scoped by 19a's census. **Not authorized until 19a is reviewed.**
- [ ] **Rung 20** implements only after 19b. **Do not reorder 19a / 19b / 20 and do not pre-empt them.**
- [ ] Standing: no epsilon anywhere, including to absorb the one-ULP difference (RA-76.7); relocation is not repair (RA-72.5); no vertex-star predicate and gate C stays suspended; do not revive branch (a) (zero support, RA-76.1), `point_on_source` as the locus (RA-71.5 amended), or RA-73.5's framing (superseded).
- [ ] Carried: `RP-02` **UNREACHED**. Frozen 66/17/49, debt 1, CP2 491/491, R3 403/497, selector 497. **`R4-VIN-01` armed at `f0d724045`** — every earlier artifact through `12036818514` is a baseline, never a comparand. RA-61.9, RA-64.6, RA-70.14, RA-72.8 withdrawn; RA-71.5 amended; RA-73.5 superseded; RA-74.1 narrowed and confirmed. `PROCESS-01` discharged. **`RP-03` not advanced this rung** — streak stands at twelve, neither extended nor broken. The historical `ledgers` failure at `b2b6e6541` is permanent for any earlier base, correct, and **must not be suppressed**.

---

## HISTORY — RA-76 frozen; branch (b) settled, every producer exonerated, RP-01 localized to the consumer's equivalence contract (2026-10-16)

### Turn sequence (byte-derived from `STATUS` history; frozen clauses in `Architecture_M6_Frozen_Definitions.md`)

| # | Turn | Kind | Review | Outcome |
|---:|---|---|---|---|
| 1 | `M6-CP3-CB2-R4-PREDICATE-SEPARATION` | Code + Build | RA-63 | accepted; probe separated from decision |
| 2 | `M6-CP3-CB3-R4-LEDGER-CONTENT-FLOOR` | Code + Build | — | tooling floor added to both gates |
| 3 | `M6-CP3-TB3-R4-PROBE-HARVEST` | Test + Benchmark | RA-64 | accepted; contradicted the reviewer, credited |
| 4 | `M6-CP3-DEFN-R4-ENDPOINT-AUTHORITY-SPEC` | Definition | RA-65 | accepted w/ amendment; RA-64.6 withdrawn, gate C suspended |
| 5 | `M6-CP3-CB4-R4-ENDPOINT-CHART-PROBE` | Code + Build | RA-66 | accepted; compile chain closed by bytes |
| 6 | `M6-CP3-TB4-R4-ENDPOINT-CHART-HARVEST` | Test + Benchmark | RA-67 | accepted; mechanism derived; 44/44 RED |
| 7 | `M6-CP3-DEFN-R5-JUNCTION-CARRIER-AUTHORITY-SPEC` | Definition | RA-68 | accepted; both repair shapes inadmissible |
| 8 | `M6-CP3-CB5-R5-ROUTE-PATH-RECONCILIATION-PROBE` | Code + Build | RA-69 | accepted; neutrality structural |
| 9 | `M6-CP3-TB5-R5-ROUTE-PATH-RECONCILIATION-HARVEST` | Test + Benchmark | RA-70 | accepted; RA-68.9 CONFIRMED |
| 10 | `M6-CP3-DEFN-R6-CORNER-ASSIGNMENT-AUTHORITY-SPEC` | Definition | RA-71 | accepted; falsified the reviewer's prediction **and** census |
| 11 | `M6-CP3-DEFN-R7-CORNER-FACE-SELECTION-REPAIR-SPEC` | Definition | RA-72 | accepted w/ amendment; passes RA-65.5 |
| 12 | `M6-CP3-CB6-R7-NODE-ADMISSIBLE-FACE-SET-PROBE` | Code + Build | RA-73 | accepted; calls the production predicate |
| 13 | `M6-CP3-TB6-R7-NODE-ADMISSIBLE-FACE-SET-HARVEST` | Test + Benchmark | RA-73 | accepted; RA-72.8 falsified |
| 14 | `M6-CP3-CB7-R7-LATTICE-UV-CANDIDATE-PROBE` | Code + Build | RA-74 | accepted; moved producer-side as instructed |
| 15 | `M6-CP3-TB7-R7-LATTICE-UV-CANDIDATE-HARVEST` | Test + Benchmark | RA-74 | accepted; sampler exonerated |
| 16 | `M6-CP3-DEFN-R8-BOUNDARY-OVERRIDE-AUTHORITY-SPEC` | Definition | RA-75 | accepted; overriding face legitimately derived; RA-74.1 narrowed |
| 17 | `M6-CP3-CB8-R8-SOURCE-ENTITY-EQUIVALENCE-PROBE` | Code + Build | RA-76 | accepted; first probe with deletions — correct and necessary |
| 18 | `M6-CP3-TB8-R8-SOURCE-ENTITY-EQUIVALENCE-HARVEST` | Test + Benchmark | RA-76 | accepted; **branch (b) settled** |
| **19** | **`M6-CP3-DEFN-R9-ENDPOINT-EQUIVALENCE-CONTRACT-SPEC`** | **Definition** | pending | **NEXT — documents only** |
| 20 | first repair-implementation rung | undetermined | pending | **not authorized**; only if rung 19 proves no weakening |

- [x] Rungs 17 and 18 **both ACCEPTED** (RA-76), two charges. Decision: `.agents/Directional/Architecture_M6_CP3_R8_Source_Entity_Equivalence_Review_Decision.md`. This Review wrote the tracker section rung 18 staged but could not apply, and closed its beacon.
- [x] **RA-76.1 — branch (b) settled.** 2,628 rows, 0 errors: `carrier-orientation` 1,008 SAME / 0 DIFFERENT; controls 1,296 SAME / 324 DIFFERENT. All 48 `sampled_face=3` / `accepted_face=7` rows are **SAME_ENTITY** — 42 × `vertex:4`, 6 × `vertex:2` (the RA-67.5 compaction again). **The 324 are same canonical edge with ULP histogram `{1: 324}` and zero vertex entities** — branch (a) has **no** support.
- [x] **RA-76.2 — `override=1` on all 2,628 rows.** The substitution fires at **every** grid-boundary node including `FirstTo`. RA-74.1's narrowing **confirmed**: the override is not junction-specific.
- [x] **RA-76.8 — every producer exonerated**: chart sampler (RA-74), planar selector (RA-71.5 amended), accepted-boundary producer (RA-75.2), the override (RA-76.1), route publisher / carrier producer / tracer / `from` corner (RA-70.7). **The consumer's endpoint admission is the sole remaining candidate** — it compares raw `SurfaceTracePoint::face` where producers guaranteed only **source-entity** identity. **Code NOT authorized.**
- [x] **RA-76.3 — rung 17's three deletions are correct**: a widened capture before the in-place overwrite at `:17279`, and a hoist of `accepted` out of the `if` so the outcome is observable. Semantics-preserving and necessary. Neutrality verified (emission `:19743`, depth 1, branch `:19507`→`:19825`; no writes to `points[`, `cell.`, `proposal.`, `frame.`). Classifier in the right domain — exact `== 1.0` / `!= 0.0`, source-vertex ids, canonical `(lo,hi)` edges, hexfloat parameters.
- [x] Charges: **RA-76.5** hedged where total ("include one-ULP-like" vs all 324 exactly one ULP) — fifth in the claim-calibration family; **RA-76.6** beacon `IN_PROGRESS` with self-referential `Successor` after six prohibitions, **mitigated** by a genuine transport failure and an explicit "do not claim this patch pushed."
- [x] **RA-76.7 latent locus** — accepted boundary and chart sample agree on edge parameters only to **one ULP**, not bit-identically (324 instances). Any exact comparison of those parameters will fail. **Not authorized for repair; no epsilon.**
- [x] Credits: probe blob `fd07f514da…` = HEAD, `include`/`tests` byte-identical; all four artifact digests and all runs verified; both dispatcher failures independently `conclusion=failure` (`38879689539`, `38879850655`); `ledgers --base 7f5160cd8` **ALL PASSED** — RA-74.6 not repeated. **`RP-03` satisfied a twelfth consecutive turn.**
- [ ] **Rung 19 — `M6-CP3-DEFN-R9-ENDPOINT-EQUIVALENCE-CONTRACT-SPEC` (documents only).** (1) Name every comparison in the endpoint-certificate path that tests `SurfaceTracePoint::face` or a face-keyed lookup against a corner, with line anchors. (2) State precisely what equality the producers guarantee — source-entity identity (RA-75.2, RA-76.1), with the one-ULP edge-parameter caveat (RA-76.7). (3) **Specify the contract the consumer should require and prove it is not a weakening** by showing what it would still reject; the carrier is edge-keyed (RA-67.6) and the `to` endpoint is a vertex of the crossed edge, so an incidence test is the obvious candidate **and the obvious danger**; **gate C stays SUSPENDED and no vertex-star predicate may be introduced**. (4) Apply RA-65.5 and classify each candidate as repair or **relocation** (RA-72.5).
- [ ] **Rung 20** implements only if rung 19 proves the contract is not a weakening. **Do not reorder rungs 19-20 and do not pre-empt rung 20.**
- [ ] Standing: relocation is not repair (RA-72.5); no epsilon anywhere; do not sort or reorder `activeFaces`; do not revive `point_on_source` as the locus (RA-71.5 amended); do not replace `.face` without transporting barycentrics (RA-75.2).
- [ ] Carried: `RP-02` **UNREACHED**. Frozen 66/17/49, debt 1, CP2 491/491, R3 403/497, selector 497. **`R4-VIN-01` re-arms at `f0d724045`** — every earlier artifact through `12035788036` is a baseline, never a comparand. RA-61.9, RA-64.6, RA-70.14, RA-72.8 withdrawn; RA-71.5 amended; RA-73.5 superseded; RA-74.1 narrowed and confirmed. Gate C suspended and moot for `RP-01`. `PROCESS-01` discharged. The historical `ledgers` failure at `b2b6e6541` is permanent for any earlier base, correct, and **must not be suppressed**.

---

## HISTORY — M6 CP3 CB8 source-entity probe, compile-only (2026-10-16)

`M6-CP3-CB8-R8-SOURCE-ENTITY-EQUIVALENCE-PROBE` records boundary override activation and exact chart/accepted source-entity representations for every reached boundary lattice node in a rejected region, without modifying admission or selecting either repair branch. Semantic `f0d7240455b10237af47de58c035cd4c576d889a`; verified application run `38877023124`. GMP/GMPXX eight-target **GREEN**, workflow `38877282902`, immutable artifact `12035788036`, outer ZIP SHA-256 `1967771d10b765168102158ae8460a7973319f0bbec452166a1c732a6e7c097d`; exact source `f0d7240455b10237af47de58c035cd4c576d889a`, 28/28 packaged hashes, 8/8 targets, preflight/build 0/0, five empty source-status files, `DIRECTIONAL_ENABLE_GMP=ON`, real link includes GMPXX/GMP, `exactArithmeticBackend=GMP`, `runtimeExecution=false`. No runtime, tests, benchmarks or selector 497; RP-01 remains unresolved and RP-02 UNREACHED. **Next authorized separate turn:** `M6-CP3-TB8-R8-SOURCE-ENTITY-EQUIVALENCE-HARVEST` (artifact-only). Detailed evidence: `.agents/Directional/Architecture_M6_CP3_R8_Source_Entity_Equivalence_Probe_Code_Build_Record_20261016.md`. Historical current sections below are superseded, not deleted.

---

## HISTORY — RA-75 frozen; the overriding face is legitimately derived; RP-01 splits into two branches with opposite repairs (2026-10-16)

### Turn sequence (byte-derived from `STATUS` history; frozen clauses in `Architecture_M6_Frozen_Definitions.md`)

| # | Turn | Kind | Review | Outcome |
|---:|---|---|---|---|
| 1 | `M6-CP3-CB2-R4-PREDICATE-SEPARATION` | Code + Build | RA-63 | accepted; probe separated from decision |
| 2 | `M6-CP3-CB3-R4-LEDGER-CONTENT-FLOOR` | Code + Build | — | tooling floor added to both gates |
| 3 | `M6-CP3-TB3-R4-PROBE-HARVEST` | Test + Benchmark | RA-64 | accepted; contradicted the reviewer, credited |
| 4 | `M6-CP3-DEFN-R4-ENDPOINT-AUTHORITY-SPEC` | Definition | RA-65 | accepted w/ amendment; RA-64.6 withdrawn, gate C suspended |
| 5 | `M6-CP3-CB4-R4-ENDPOINT-CHART-PROBE` | Code + Build | RA-66 | accepted; compile chain closed by bytes |
| 6 | `M6-CP3-TB4-R4-ENDPOINT-CHART-HARVEST` | Test + Benchmark | RA-67 | accepted; mechanism derived; 44/44 RED |
| 7 | `M6-CP3-DEFN-R5-JUNCTION-CARRIER-AUTHORITY-SPEC` | Definition | RA-68 | accepted; both repair shapes inadmissible |
| 8 | `M6-CP3-CB5-R5-ROUTE-PATH-RECONCILIATION-PROBE` | Code + Build | RA-69 | accepted; neutrality structural |
| 9 | `M6-CP3-TB5-R5-ROUTE-PATH-RECONCILIATION-HARVEST` | Test + Benchmark | RA-70 | accepted; RA-68.9 CONFIRMED |
| 10 | `M6-CP3-DEFN-R6-CORNER-ASSIGNMENT-AUTHORITY-SPEC` | Definition | RA-71 | accepted; falsified the reviewer's prediction **and** census |
| 11 | `M6-CP3-DEFN-R7-CORNER-FACE-SELECTION-REPAIR-SPEC` | Definition | RA-72 | accepted w/ amendment; passes RA-65.5 |
| 12 | `M6-CP3-CB6-R7-NODE-ADMISSIBLE-FACE-SET-PROBE` | Code + Build | RA-73 | accepted; calls the production predicate |
| 13 | `M6-CP3-TB6-R7-NODE-ADMISSIBLE-FACE-SET-HARVEST` | Test + Benchmark | RA-73 | accepted; RA-72.8 falsified |
| 14 | `M6-CP3-CB7-R7-LATTICE-UV-CANDIDATE-PROBE` | Code + Build | RA-74 | accepted; moved **producer-side** as instructed |
| 15 | `M6-CP3-TB7-R7-LATTICE-UV-CANDIDATE-HARVEST` | Test + Benchmark | RA-74 | accepted; **sampler exonerated** |
| 16 | `M6-CP3-DEFN-R8-BOUNDARY-OVERRIDE-AUTHORITY-SPEC` | Definition | RA-75 | accepted; **the overriding face is legitimately derived**; RA-74.1 narrowed |
| **17** | **`M6-CP3-CB8-R8-SOURCE-ENTITY-EQUIVALENCE-PROBE`** | **Code + Build** | pending | **NEXT — compile-only** |
| 18 | `M6-CP3-TB8-R8-SOURCE-ENTITY-EQUIVALENCE-HARVEST` | Test + Benchmark | pending | artifact-only harvest of rung 17 |
| 19 | repair for the surviving branch | undetermined | pending | **not authorized**; branch unknown until rung 18 |

- [x] Rung 16 **ACCEPTED** (RA-75), one charge, one note. Decision: `.agents/Directional/Architecture_M6_CP3_R8_Boundary_Override_Authority_Spec_Review_Decision.md`.
- [x] **RA-75.2 — the overriding face is legitimately derived.** At `src/geometry/SurfaceCellTracing.cpp:17117-17118` and `:17139-17140`, `append_point(*parameter, run.sourceFaces[edgeIndex])` — **the accepted point's face comes from the source-edge run's own face, never a chart selector**. Face 7 is **not** an error value. The accepted boundary also **sizes the lattice**: grid interval counts come from `acceptedBoundary[side].intervals.size()` at `:17204-17215`. Flags: `useAcceptedConformity` (`:14993`) and `useAcceptedCutDomain` (`:14998`) are **not coextensive**.
- [x] **RA-75.3 — RA-74.1 NARROWED.** The guard `v==0 || u==gridU || v==gridV || u==0` selects **every** grid-boundary node, and **`FirstTo` face 0 may also have been replaced**. So the override is **not** shown to be junction-specific; only that at `SecondFrom` the published face differs from the sample.
- [x] **RA-75.4 charge — the cohort "discrepancy" is one population in four index domains.** 54 endpoint records = 27 occurrences = 23 ledger entries = 22 distinct identities (multiplicity `{2: 21, 12: 1}`; the duplicate is deliberate, commit `c4da30a37`). No cross-vintage mapping needed. **RA-67.13 a third time.** The caution survives on its other ground (RA-74.7, the control override state was never measured).
- [x] **RA-75.5 — Q3 declines to name one owner, with a reason**: accepted conformity owns the published source-edge point and its face-relative location, chart sampling owns interior samples, and **neither face is a unique directed-side carrier certificate** (consistent with RA-72.4). Admissible under RA-68.12.
- [x] **RA-75.6 — Q4 admissibility table**: two admissible **shapes only**, one **relocation only** (RA-72.5), three forbidden including an invented vertex-star route (RA-65.5, gate C suspended); F1–F7 stated, none executed.
- [x] Credits: **both RA-74 charges absorbed in one rung** — ledger prepended not overwritten (`ledgers --base 298b6779d` clean), `ORIENTATION.md` written after two omissions; beacon `COMPLETE` with a named Successor, not self-referential. **`RP-03` satisfied an eleventh consecutive turn.** Note (not charged): the tracker was not written by rung 16.
- [ ] **Rung 17 — `M6-CP3-CB8-R8-SOURCE-ENTITY-EQUIVALENCE-PROBE` (compile-only, rejection-only).** For **every** grid-boundary node reached in a rejected case, emit (1) whether the override fired (`accepted != nullptr` at `:17278`), settling whether `FirstTo` is also overridden; (2) the **exact source entity** of the chart sample — vertex id when a barycentric coordinate is exactly `1`, else edge plus exact parameter when one is exactly `0`, else interior; (3) the same for the accepted boundary point. Do not modify `point_on_periodic_chart` or the override. Compile and dispatch; **do not interpret the fields**.
- [ ] **Rung 18** harvests and answers the discriminator: **do the two points denote the same source entity?** Same → **branch (b)**, the override is legitimate and the consumer contract is at fault. Different entity or sheet → **branch (a)**, the override is invalid upstream. This is the spec's own **F1** falsifier.
- [ ] **Rung 19** repairs the surviving branch only. **Do not reorder rungs 17-19 and do not pre-empt rung 19.**
- [ ] Standing: relocation is not repair (RA-72.5); do not touch `tolerance` or any epsilon; do not sort or reorder `activeFaces`; do not revive `point_on_source` as the locus (RA-71.5 amended); do not replace `.face` without transporting barycentrics.
- [ ] Carried: `RP-02` **UNREACHED**. Frozen 66/17/49, debt 1, CP2 491/491, R3 403/497, selector 497. **`R4-VIN-01` armed at `cdd6dc4a9`** — every earlier artifact through `12032341939` is a baseline, never a comparand. RA-61.9, RA-64.6, RA-70.14, RA-72.8 withdrawn; RA-71.5 amended; RA-73.5 superseded; **RA-74.1 narrowed**. Gate C suspended and moot for `RP-01`. `PROCESS-01` discharged. The historical `ledgers` failure at `b2b6e6541` is permanent for any earlier base, correct, and **must not be suppressed**.

---

## HISTORY — M6 CP3 R8 Definition recorded (2026-10-16)

- [x] Four-question source-static boundary override authority Definition: `Architecture_M6_CP3_R8_Boundary_Override_Authority_Specification_20261016.md`.
- [ ] **Next:** independent `M6-CP3-DEFN-R8-BOUNDARY-OVERRIDE-AUTHORITY-SPEC-REV` to rederive face ownership, cohort distinction, RA-65.5 and F1–F7; repair code held.
- [ ] RP-01 source-entity/sheet and per-side carrier proof; RP-02 unreached. 66/17/49, debt1; CP2 491/491, R3 403/497, selector497 frozen. No runtime evidence.

## HISTORY — RA-74 frozen; the sampler is exonerated and the point is overwritten by the accepted conformity boundary; next rung names the owning authority (2026-10-16)

### Turn sequence (byte-derived from `STATUS` history; frozen clauses in `Architecture_M6_Frozen_Definitions.md`)

| # | Turn | Kind | Review | Outcome |
|---:|---|---|---|---|
| 1 | `M6-CP3-CB2-R4-PREDICATE-SEPARATION` | Code + Build | RA-63 | accepted; probe separated from decision |
| 2 | `M6-CP3-CB3-R4-LEDGER-CONTENT-FLOOR` | Code + Build | — | tooling floor added to both gates |
| 3 | `M6-CP3-TB3-R4-PROBE-HARVEST` | Test + Benchmark | RA-64 | accepted; contradicted the reviewer, credited |
| 4 | `M6-CP3-DEFN-R4-ENDPOINT-AUTHORITY-SPEC` | Definition | RA-65 | accepted w/ amendment; RA-64.6 withdrawn, gate C suspended |
| 5 | `M6-CP3-CB4-R4-ENDPOINT-CHART-PROBE` | Code + Build | RA-66 | accepted; compile chain closed by bytes |
| 6 | `M6-CP3-TB4-R4-ENDPOINT-CHART-HARVEST` | Test + Benchmark | RA-67 | accepted; mechanism derived; 44/44 RED |
| 7 | `M6-CP3-DEFN-R5-JUNCTION-CARRIER-AUTHORITY-SPEC` | Definition | RA-68 | accepted; both repair shapes inadmissible |
| 8 | `M6-CP3-CB5-R5-ROUTE-PATH-RECONCILIATION-PROBE` | Code + Build | RA-69 | accepted; neutrality structural |
| 9 | `M6-CP3-TB5-R5-ROUTE-PATH-RECONCILIATION-HARVEST` | Test + Benchmark | RA-70 | accepted; RA-68.9 CONFIRMED |
| 10 | `M6-CP3-DEFN-R6-CORNER-ASSIGNMENT-AUTHORITY-SPEC` | Definition | RA-71 | accepted; falsified the reviewer's prediction **and** census |
| 11 | `M6-CP3-DEFN-R7-CORNER-FACE-SELECTION-REPAIR-SPEC` | Definition | RA-72 | accepted w/ amendment; passes RA-65.5 |
| 12 | `M6-CP3-CB6-R7-NODE-ADMISSIBLE-FACE-SET-PROBE` | Code + Build | RA-73 | accepted; calls the production predicate |
| 13 | `M6-CP3-TB6-R7-NODE-ADMISSIBLE-FACE-SET-HARVEST` | Test + Benchmark | RA-73 | accepted; RA-72.8 falsified |
| 14 | `M6-CP3-CB7-R7-LATTICE-UV-CANDIDATE-PROBE` | Code + Build | RA-74 | accepted; moved **producer-side** as instructed |
| 15 | `M6-CP3-TB7-R7-LATTICE-UV-CANDIDATE-HARVEST` | Test + Benchmark | RA-74 | accepted; **sampler exonerated**; locus relocated |
| **16** | **`M6-CP3-DEFN-R8-BOUNDARY-OVERRIDE-AUTHORITY-SPEC`** | **Definition** | pending | **NEXT — documents only** |
| 17 | first repair-implementation rung | undetermined | pending | **not authorized**; runs only if rung 16 names the owner |

- [x] Rungs 14 and 15 **both ACCEPTED** (RA-74); one hard charge, two lesser. Decision: `.agents/Directional/Architecture_M6_CP3_R7_Lattice_UV_Candidate_Review_Decision.md`. This Review restored the `ORIENTATION.md` section rung 15 skipped.
- [x] **RA-74.1 — the sampler is innocent.** At `src/geometry/SurfaceCellTracing.cpp:17256-17281` in the **bounded-disk** producer, `point_on_periodic_chart` fills the point; then, under `useAcceptedConformity` (`:14993`) **at grid-boundary nodes** (`v==0 || u==gridU || v==gridV || u==0`), it is **replaced in its entirety** by `*accepted` from `acceptedBoundary[side]`, with **no admissibility check, no source-entity comparison, no agreement test**. `sampledFace` exists only at `:17264` and `:17305`, **both probe-added** — production never retained the discarded value.
- [x] **RA-74.2 measurement re-derived.** Artifact `12030150301` ZIP recomputed `de79aed888a2…`, manifest **51 OK / 0 BAD**, boundary clean; 96 rows, 0 errors. Junction `FirstTo` sampled 0 / published 0; junction `SecondFrom` **sampled 3 / published 7**; both control categories `producer=none`, **not measured**. Harness summary records **`sampled-min` for both junction categories**.
- [x] **RA-74.3** — **RA-72.6 CONFIRMED** at the sample point and thereby **moot**; **RA-73.5 SUPERSEDED** (a substitution, not a selection asymmetry); **RA-71.5 AMENDED** (the measured cells are **bounded-disk**; planar `point_on_source` is **exonerated**). The reviewer's **RA-73.6 charge is vindicated**.
- [x] **RA-74.4 — search order now frozen:** RA-68.3 ordered too late → RA-71.7 present but comparing the wrong thing → **RA-74.4 absent entirely**.
- [x] **RA-74.6 HARD CHARGE — the append-only tracker was destroyed and pushed.** 14,225 lines → **6** at `b2b6e6541`, destroyed across **four pushed commits**, restored at `9d0ed94e6`. **Restore is byte-faithful** (restored tail ≡ `7c83fb0ec`; 14,232 = 14,225 + 7; 665 = 664 + 1; markers 13 throughout) — nothing permanently lost. **The mandated gate catches it** (`[FAIL] … b2b6e654 14225->6`, exit **1**); **five consecutive NEXT_TURNs have required both gates before closing**. Mitigation: self-detected, byte-perfect restore, named in the commit subject.
- [x] **RA-74.7 charge** — all 54 control endpoints record `producer=none`, so **the controls cannot discriminate on the override**; no later turn may cite them as evidence it is junction-specific (RA-68.5 pattern). **RA-74.8 charge** — `ORIENTATION.md` skipped, second consecutive rung.
- [x] Credits: rung 14 **moved producer-side** rather than substituting an approximate input, with the reason in the record **and** a source comment — **RA-73.10 applied one rung after freezing**; neutrality verified by content (no assignment to `points[`, `cell.`, `result.`, `proposal.`, `frame.`); blob `4a524d204e…` = HEAD, `include`/`tests` byte-identical; all four artifact digests and all four runs verified; **claim calibration corrected in one rung**; **beacon correct** (`Successor: UNKNOWN` with reasoning, not self-referential); two non-evidential failures disclosed. **`RP-03` satisfied a tenth consecutive turn.**
- [ ] **Rung 16 — `M6-CP3-DEFN-R8-BOUNDARY-OVERRIDE-AUTHORITY-SPEC` (documents only).** (1) What authority does `acceptedBoundary` carry — produced at `:16822`, `:16867-16885`; what do `useAcceptedConformity` (`:14993`) and `useAcceptedCutDomain` (`:14998`) gate; what does it guarantee about `.face`? (2) Is the override guard `v==0 || u==gridU || v==gridV || u==0` **coextensive with the measured 21**, derived **from source, not the measurement**? (3) **Which authority owns the corner's face at a conformity-baseline boundary node** — chart sample or accepted boundary? If the accepted boundary is authoritative, face 7 is *correct* and `RP-01` is a downstream consumer defect. (4) Apply RA-65.5 to each candidate repair and say whether it is repair or **relocation**.
- [ ] **Rung 17** implements only if rung 16 names the owner. **Do not reorder rungs 16-17 and do not pre-empt rung 17.**
- [ ] Standing: relocation is not repair (RA-72.5); do not touch `tolerance` or any epsilon; do not sort or reorder `activeFaces`; do not revive `point_on_source` as the locus for these cells (RA-71.5 amended).
- [ ] Carried: `RP-02` **UNREACHED**. Frozen 66/17/49, debt 1, CP2 491/491, R3 403/497, selector 497. **`R4-VIN-01` re-arms at `cdd6dc4a9`** — every earlier artifact through `12028682600` is a baseline, never a comparand. RA-61.9, RA-64.6, RA-70.14 and RA-72.8 withdrawn; **RA-71.5 amended, RA-73.5 superseded**. Gate C suspended and moot for `RP-01`. `PROCESS-01` discharged.

---

## HISTORY — TB7 pre-snap candidate harvest verified (2026-10-16)

- [x] `M6-CP3-TB7-R7-LATTICE-UV-CANDIDATE-HARVEST`: immutable [run 38861867717](https://github.com/akashskypatel/Directional/actions/runs/38861867717) verified; 44/44 selected, 44 RED unchanged, 96 endpoint records. Report: `.agents/Directional/Architecture_M6_CP3_R7_Lattice_UV_Candidate_Harvest_TB_Report_20261016.md`.
- [ ] **NEXT — independent Review, exact turn ID not yet frozen.** Adjudicate the accepted boundary override (original sampled SecondFrom face 3, published face 7) against authoritative A2b endpoint/carrier contracts. Do **not** implement repair without the Review/Definition gate.
- [ ] Preserve 66/17/49, debt 1, CP2 491/491, R3 403/497 and frozen selector 497. `RP-02` remains unreached. No new accepted-green losses or stable event credited.

---

## HISTORY — CB7 pre-snap producer-candidate probe compile complete; TB7 next (2026-10-16)

- [x] `M6-CP3-CB7-R7-LATTICE-UV-CANDIDATE-PROBE`: producer-captured pre-snap UV, raw candidate barycentrics and pass/fail published only in original rejection diagnostic; one source file (+123), source commit `cdd6dc4a9ba95a42aace6226194b38e712b53e4b`. Exact apply and compile-only evidence: `.agents/Directional/Architecture_M6_CP3_R7_Lattice_UV_Candidate_Probe_Code_Build_Record_20261016.md`.
- [ ] **NEXT: `M6-CP3-TB7-R7-LATTICE-UV-CANDIDATE-HARVEST`** — immutable artifact-only harvest; answer the producer sample-point minimum-admissible selection question. No code repair in this turn.
- [ ] Repair rung unapproved until harvest and Review. Frozen 66/17/49, debt 1; CP2 491/491, R3 403/497 and selector 497 unchanged, `RP-02` unreached.

Immutable GMP compile [38859497594](https://github.com/akashskypatel/Directional/actions/runs/38859497594) **GREEN**, job `116838424581`, artifact `12028682600` ZIP SHA-256 `54b7f5a73ae7a041491fddef64807f71a9ac49f42c1508cea0ce64dfe61095d9`: 28/28 package checksums, 8/8 targets, GMPXX/GMP, preflight/build 0/0, clean source, `runtimeExecution=false`. Not runtime acceptance.

---

## HISTORY — RA-73 frozen; RA-72.8 falsified; the junction cases are exactly where one corner had three candidates and the producer took the largest (2026-10-16)

### Turn sequence (byte-derived from `STATUS` history; frozen clauses in `Architecture_M6_Frozen_Definitions.md`)

| # | Turn | Kind | Review | Outcome |
|---:|---|---|---|---|
| 1 | `M6-CP3-CB2-R4-PREDICATE-SEPARATION` | Code + Build | RA-63 | accepted; probe separated from decision |
| 2 | `M6-CP3-CB3-R4-LEDGER-CONTENT-FLOOR` | Code + Build | — | tooling floor added to both gates |
| 3 | `M6-CP3-TB3-R4-PROBE-HARVEST` | Test + Benchmark | RA-64 | accepted; contradicted the reviewer, credited |
| 4 | `M6-CP3-DEFN-R4-ENDPOINT-AUTHORITY-SPEC` | Definition | RA-65 | accepted w/ amendment; RA-64.6 withdrawn, gate C suspended |
| 5 | `M6-CP3-CB4-R4-ENDPOINT-CHART-PROBE` | Code + Build | RA-66 | accepted; compile chain closed by bytes |
| 6 | `M6-CP3-TB4-R4-ENDPOINT-CHART-HARVEST` | Test + Benchmark | RA-67 | accepted; mechanism derived; 44/44 RED |
| 7 | `M6-CP3-DEFN-R5-JUNCTION-CARRIER-AUTHORITY-SPEC` | Definition | RA-68 | accepted; both repair shapes inadmissible |
| 8 | `M6-CP3-CB5-R5-ROUTE-PATH-RECONCILIATION-PROBE` | Code + Build | RA-69 | accepted; neutrality structural |
| 9 | `M6-CP3-TB5-R5-ROUTE-PATH-RECONCILIATION-HARVEST` | Test + Benchmark | RA-70 | accepted; RA-68.9 CONFIRMED; locus localized |
| 10 | `M6-CP3-DEFN-R6-CORNER-ASSIGNMENT-AUTHORITY-SPEC` | Definition | RA-71 | accepted; falsified the reviewer's prediction **and** census |
| 11 | `M6-CP3-DEFN-R7-CORNER-FACE-SELECTION-REPAIR-SPEC` | Definition | RA-72 | accepted w/ amendment; passes RA-65.5; RA-71.6 amended |
| 12 | `M6-CP3-CB6-R7-NODE-ADMISSIBLE-FACE-SET-PROBE` | Code + Build | RA-73 | accepted; probe calls the production predicate — faithful by construction |
| 13 | `M6-CP3-TB6-R7-NODE-ADMISSIBLE-FACE-SET-HARVEST` | Test + Benchmark | RA-73 | accepted; **RA-72.8 falsified**; 96/96 complete |
| **14** | **`M6-CP3-CB7-R7-LATTICE-UV-CANDIDATE-PROBE`** | **Code + Build** | pending | **NEXT — compile-only** |
| 15 | `M6-CP3-TB7-R7-LATTICE-UV-CANDIDATE-HARVEST` | Test + Benchmark | pending | artifact-only harvest of rung 14 |
| 16 | first repair-implementation rung | undetermined | pending | **not authorized**; runs only if rung 15 settles the rule |

- [x] Rungs 12 and 13 **both ACCEPTED** (RA-73), two charges. Decision: `.agents/Directional/Architecture_M6_CP3_R7_Node_Admissible_Face_Set_Review_Decision.md`. This Review closed the beacon rung 13 left open and wrote the tracker and ORIENTATION sections it skipped.
- [x] **RA-72.8 FALSIFIED and WITHDRAWN.** The junction `Second` side's `from_admissible` is `{3,6,7}` — **it contains 3**, so the two selections are not drawing from sets that exclude the path's face. Credit to the turn.
- [x] **RA-73.5 — the asymmetry.** Per `:19365-19366`, on a second-certificate failure `FromFace=0` is `first.to` and `ToFace=7` is `second.from`. `first.to` published **0** from `{0,1,4}` = the **minimum**; `second.from` published **7** from `{3,6,7}` = the **maximum**. Same rejection, same source vertex, two regions. **A single minimum-row rule cannot explain both**, so RA-72.6 does not survive as a universal account.
- [x] **RA-73.5 — the discriminator is set cardinality.** Controls: that corner's set is the **singleton** `{3}`, published 3. Junction: **three** members, published the largest. *The junction population is exactly the population where a choice existed* — complete separator, no exceptions. 96 rows re-derived, all `COMPLETE`, `frame` empty, multiplicity `[(1,42),(3,2)]`.
- [x] **RA-73.6 charge — measured at the wrong UV.** The probe samples at `phase_uv(frame, point_position(point))`, the **published post-snap** position; the producer sampled the **lattice** UV at `:12951-12952`, and `point_on_source` snaps barycentrics within `1e-10` to exact 0/1 (`:11495-11501`). **The measured set is not the set the producer chose from**, so the apparent violation may be a post-snap artefact. The headline overstates; the report's own later sentence is accurate. **Fourth turn in the claim-calibration category** (RA-67.9, RA-70.7, RA-71.10, RA-73.6), first to **over**-claim.
- [x] **RA-73.7 constraint** — `UniformPhaseFrame` (`:11421-11426`) carries `minU/maxU/minV/maxV`, `faceBranchRotation`, `faceChart` but **no `stepU`/`stepV` and no node counts**; `cell.lattice[k].latticeCoordinate` is published at `:13005-13008` but a coordinate without the step does not determine the UV. **A consumer-side probe cannot rebuild the producer's sample point.**
- [x] **RA-73.8 charge — beacon left `IN_PROGRESS` with a self-referential `Successor`**, fourth consecutive NEXT_TURN to prohibit exactly that (RA-67.11); durable closeout incomplete. Credited separately: the commit subject declared the incompleteness rather than faking a close.
- [x] Credits: probe neutral structurally (`:19360` → `:19504-19576` → closes `:19639`); **calls `point_on_source` with singleton lists rather than re-implementing it** — faithful by construction; chain closed by content (blob `bfcc7f88ee…` = HEAD, `include`/`tests` byte-identical); **both orchestration failures independently `conclusion=failure`** (`38851813094`, `38851975506`) and disclosed when the retry would have hidden them. **`RP-03` satisfied a ninth consecutive turn.**
- [ ] **Rung 14 — `M6-CP3-CB7-R7-LATTICE-UV-CANDIDATE-PROBE` (compile-only, rejection-only).** Emit, for the ambiguous corner only, the **pre-snap** candidate evidence at the **producer's own lattice UV**: the sample UV, and for each active face the raw unsnapped barycentric from `face_barycentric_from_uv` with the containment pass/fail. Do not modify `point_on_source`. If the lattice UV is not reconstructible from published state (RA-73.7), **say so, name the missing field, and move the emission producer-side** rather than substituting an input. Compile and dispatch; **do not interpret the fields**.
- [ ] **Rung 15** harvests and answers: **at the producer's sample point, is the published face the minimum admissible one?** Yes → RA-72.6 stands and the snap explains RA-73.5. No → the selection rule is unidentified and the repair shape changes again.
- [ ] **Rung 16** implements only if rung 15 settles the rule. **Do not reorder rungs 14-16 and do not pre-empt rung 16.**
- [ ] Standing: relocation is not repair (RA-72.5); do not touch `tolerance` or any epsilon; do not sort or reorder `activeFaces` (already sorted at `:17823`).
- [ ] Carried: `RP-02` **UNREACHED**. Frozen 66/17/49, debt 1, CP2 491/491, R3 403/497, selector 497. **`R4-VIN-01` re-arms at `4d64b7684`** — `11994726341`, `11996317553`, `12005034654`, `12010485442`, `12019178209`, `12021892076`, `12024554349` are baselines, never comparands. RA-61.9, RA-64.6, RA-70.14 and **RA-72.8** withdrawn; RA-71.6 amended and contradicted at one corner pending rung 15. Gate C suspended and moot for `RP-01`. `PROCESS-01` discharged.

---

## HISTORY — 2026-10-16 CB6 rejection-only node/side face census compiled; TB6 harvest next

`M6-CP3-CB6-R7-NODE-ADMISSIBLE-FACE-SET-PROBE` completed its **Code + Build** boundary. Exact semantic commit `4d64b7684ac7ec2d0655f96c88ecf05f2906bca7` changes only `src/geometry/SurfaceCellTracing.cpp` (+73 lines): after the existing A2b endpoint-certificate rejection, emit producer-region `ActiveFaces`, independent `From/ToAdmissibleFaces` evaluated through the original `point_on_source` containment predicate at the **actual published endpoint position** (not inferred lattice-node UV), and previously existing `PathFaces` for each directed side. Planar-frame-unavailable cases explicitly report `Frame=not-planar`. It does **not** change admission, topology, tolerance, tests, selectors or frozen evidence.

Patch transport `38850167371` (result artifact `12024129249`) verified base `5f70370cd920765388ce6f0d29517cf7498bb945`, full patch SHA-256 `0a1f779996edcb6088298462403867f30ace3fd70bdb0ddce04c5a178db11f0f`, one-path semantic commit, owner-retired Drive staging. Immutable GMP/GMPXX eight-target compile [38850333038](https://github.com/akashskypatel/Directional/actions/runs/38850333038), result artifact `12024554349` ZIP SHA-256 `c824a6aa43617309aaae6a54a3dd49a987c51390caa404600a88763d3b04fabf`: **28/28** manifest, **8/8** targets, configure/preflight and build `0/0`, `DIRECTIONAL_ENABLE_GMP=ON`, linker contains GMPXX/GMP, five empty source-status files, exact packaged source SHA, `exactArithmeticBackend=GMP`, **`runtimeExecution=false`**. No tests, benchmarks, 497 or production acceptance executed.

**Next authorized turn only:** `M6-CP3-TB6-R7-NODE-ADMISSIBLE-FACE-SET-HARVEST` must run an immutable artifact-only harvest and answer whether each rejected side path's face is in the actual node-admissible set. Do not infer that result from compile success, implement the repair, adjust selectors, or advance beyond TB6 in this turn. Ledger 66/17/49, debt 1, CP2 491/491, R3 403/497, frozen selector 497 and `RP-02` UNREACHED unchanged.

---

## HISTORICAL — RA-72 frozen; repair shape passes the producer test, premise unverified; RA-71.6 amended; next rung is a probe, not code (2026-10-16)

### Turn sequence (byte-derived from `STATUS` history; frozen clauses in `Architecture_M6_Frozen_Definitions.md`)

| # | Turn | Kind | Review | Outcome |
|---:|---|---|---|---|
| 1 | `M6-CP3-CB2-R4-PREDICATE-SEPARATION` | Code + Build | RA-63 | accepted; probe separated from decision |
| 2 | `M6-CP3-CB3-R4-LEDGER-CONTENT-FLOOR` | Code + Build | — | tooling floor added to both gates |
| 3 | `M6-CP3-TB3-R4-PROBE-HARVEST` | Test + Benchmark | RA-64 | accepted; contradicted the reviewer, credited |
| 4 | `M6-CP3-DEFN-R4-ENDPOINT-AUTHORITY-SPEC` | Definition | RA-65 | accepted w/ amendment; RA-64.6 withdrawn, gate C suspended |
| 5 | `M6-CP3-CB4-R4-ENDPOINT-CHART-PROBE` | Code + Build | RA-66 | accepted; compile chain closed by bytes |
| 6 | `M6-CP3-TB4-R4-ENDPOINT-CHART-HARVEST` | Test + Benchmark | RA-67 | accepted; mechanism derived; 44/44 RED |
| 7 | `M6-CP3-DEFN-R5-JUNCTION-CARRIER-AUTHORITY-SPEC` | Definition | RA-68 | accepted; both repair shapes inadmissible |
| 8 | `M6-CP3-CB5-R5-ROUTE-PATH-RECONCILIATION-PROBE` | Code + Build | RA-69 | accepted; neutrality structural; chain closed by content |
| 9 | `M6-CP3-TB5-R5-ROUTE-PATH-RECONCILIATION-HARVEST` | Test + Benchmark | RA-70 | accepted; RA-68.9 CONFIRMED; RP-01 locus localized |
| 10 | `M6-CP3-DEFN-R6-CORNER-ASSIGNMENT-AUTHORITY-SPEC` | Definition | RA-71 | accepted; falsified the reviewer's prediction AND census; producer named |
| 11 | `M6-CP3-DEFN-R7-CORNER-FACE-SELECTION-REPAIR-SPEC` | Definition | RA-72 | accepted **with amendment**; passes RA-65.5, **premise unverified**; **RA-71.6 amended** |
| **12** | **`M6-CP3-CB6-R7-NODE-ADMISSIBLE-FACE-SET-PROBE`** | **Code + Build** | pending | **COMPLETE — 8/8 compile, no runtime** |
| 13 | `M6-CP3-TB6-R7-NODE-ADMISSIBLE-FACE-SET-HARVEST` | Test + Benchmark | pending | artifact-only harvest of rung 12 |
| 14 | first repair-implementation rung | undetermined | pending | **not authorized**; runs only if rung 13 confirms the premise |

- [x] Rung 11 **ACCEPTED WITH AMENDMENT** (RA-72), two charges. Decision: `.agents/Directional/Architecture_M6_CP3_R7_Corner_Face_Selection_Repair_Spec_Review_Decision.md`.
- [x] **First repair family to pass the RA-65.5 producer test (RA-72.3).** `SurfaceTraceSegment` (`include/directional/geometry/SurfaceCellTracing.h:1211-1232`) carries `face`, `startBarycentric`, `endBarycentric`, `family`, `sign`, `sourceChart`, a typed `CanonicalRoute entryRoute` and `railId`; `cell.boundaryPaths[side]` is filled at `:13012-13021` **before** `SurfaceFrontEdge` is built at `:13030-13035`.
- [x] **Per-directed-side is structurally necessary (RA-72.4).** One face per `(u,v)` node at `:12949-12958`, copied to the corner at `:12986-12987` and to the endpoints at `:13033-13035`, while each path is traced independently; a node belongs to up to four cells with incoming and outgoing side incidences. Keep one canonical geometric node, allow several side-occurrence representations.
- [x] **RA-72.6 AMENDMENT — RA-71.6's "arbitrary iteration order" clause WITHDRAWN.** `:17823` sorts `work.sourceRows` before it is passed as `activeFaces` at `:17887`; `SourceFaceId = SemanticId<...>` has one `std::size_t value_`, `index()` returning it, and `auto operator<=>(...) const = default`; `source_face_row` (`:189-195`) returns `faceId.index()`. So **`activeFaces` is ascending by row** and `point_on_source` first-match = **minimum admissible row**, while `segment_on_source` at `:12124-12130` also takes the **minimum** covering row. **Both rules are the same rule.** Surviving conclusion, on firmer ground: `face_barycentric_from_uv` (`:11450-11474`) is a planar inverse affine map failing only on `|det| <= 1e-18`, so at a shared vertex every incident active face is admissible — the ambiguity is structural, **no epsilon can repair it**, and the choice is still made without reference to the consuming side.
- [x] **RA-72.8 — the premise fails.** A minimum-row rule **cannot return 7 from a set containing 3**, yet RA-70 measured `toFace=7` and path `{3}` in all 21. So **the two selections draw from different face sets**, and §3.2's `path.back().face` binding would adopt a face the node test never saw. **Do not implement before measuring.**
- [x] Charges: **RA-72.7** inherited the reviewer's premise instead of re-deriving it (rung 10 refused a census and was credited; rung 11 accepted a mechanism unchecked); **RA-72.9** both mandated gates omitted and the closeout table dropped — escalation on RA-71.9; `ORIENTATION.md` also not updated. Both gates run by this Review, both pass; ORIENTATION currency restored here.
- [x] Credits: root `CHANGELOG.md` written this turn, correcting RA-71.11 within one rung; **declined to authorize its own code successor** (`Successor: UNKNOWN` with reasoning, the RA-63.13 shape) — **`RP-03` satisfied an eighth consecutive turn**; seven falsifiers F1–F7 stated; disclosed the local snapshot was not a Git clone; rejected sorting `activeFaces` as a general repair (right conclusion, wrong reason — the list is already sorted, and changing it would alter **every** node's corner face).
- [x] **Rung 12 — `M6-CP3-CB6-R7-NODE-ADMISSIBLE-FACE-SET-PROBE` (compile-only, rejection-only).** Extend the post-decision probe block at `:19360` to emit, for rejected edges only: (1) the **full** admissible face set at each endpoint node — every active face passing the `point_on_source` containment test, not merely the first; (2) the region's `activeFaces` content as presented to the producer; (3) the side path's covering face set. Decision-neutral by construction; compile and dispatch a package; **do not interpret the fields**.
- [ ] **Rung 13** harvests those fields and answers the single decisive question: **does the node's admissible set contain the path's face?**
- [ ] **Rung 14** implements only if rung 13 confirms the premise. **Do not reorder rungs 12-14 and do not pre-empt rung 14.**
- [ ] Standing: relocation is not repair (RA-72.5); do not touch `tolerance` or any epsilon (RA-72.6); do not sort or reorder `activeFaces`.
- [ ] Carried: `RP-02` **UNREACHED**. Frozen 66/17/49, debt 1, CP2 491/491, R3 403/497, selector 497. **`R4-VIN-01` armed at `a143af264`** — `11994726341`, `11996317553`, `12005034654`, `12010485442`, `12019178209`, `12021892076` are baselines, never comparands. RA-61.9, RA-64.6 and RA-70.14 withdrawn; **RA-71.6 amended**. Gate C suspended and moot for `RP-01`. `PROCESS-01` discharged.

---

## HISTORY — R7 definition prepared; independent review required (2026-10-16)

- [x] `M6-CP3-DEFN-R7-CORNER-FACE-SELECTION-REPAIR-SPEC`: source witnesses enumerated; per-node face proven insufficient as a general side authority; source-attested per-directed-side endpoint repair shape and blast radius defined. Report: `.agents/Directional/Architecture_M6_CP3_R7_Corner_Face_Selection_Repair_Specification_20261016.md`.
- [ ] Obtain independent Review decision on the bounded repair witness/negative controls and the unproved path-face tie-break. **No Code + Build successor is authorized yet.** No runtime execution, selector or stable ledger change.

---

## HISTORICAL — RA-71 frozen; RP-01's producer named and verified; next rung is the repair spec, documents only (2026-10-16)

### Turn sequence (byte-derived from `STATUS` history; frozen clauses in `Architecture_M6_Frozen_Definitions.md`)

| # | Turn | Kind | Review | Outcome |
|---:|---|---|---|---|
| 1 | `M6-CP3-CB2-R4-PREDICATE-SEPARATION` | Code + Build | RA-63 | accepted; probe separated from decision |
| 2 | `M6-CP3-CB3-R4-LEDGER-CONTENT-FLOOR` | Code + Build | — | tooling floor added to both gates |
| 3 | `M6-CP3-TB3-R4-PROBE-HARVEST` | Test + Benchmark | RA-64 | accepted; contradicted the reviewer, credited |
| 4 | `M6-CP3-DEFN-R4-ENDPOINT-AUTHORITY-SPEC` | Definition | RA-65 | accepted w/ amendment; RA-64.6 withdrawn, gate C suspended |
| 5 | `M6-CP3-CB4-R4-ENDPOINT-CHART-PROBE` | Code + Build | RA-66 | accepted; compile chain closed by bytes |
| 6 | `M6-CP3-TB4-R4-ENDPOINT-CHART-HARVEST` | Test + Benchmark | RA-67 | accepted; mechanism derived; 44/44 RED |
| 7 | `M6-CP3-DEFN-R5-JUNCTION-CARRIER-AUTHORITY-SPEC` | Definition | RA-68 | accepted; both repair shapes inadmissible |
| 8 | `M6-CP3-CB5-R5-ROUTE-PATH-RECONCILIATION-PROBE` | Code + Build | RA-69 | accepted; neutrality structural; chain closed by content |
| 9 | `M6-CP3-TB5-R5-ROUTE-PATH-RECONCILIATION-HARVEST` | Test + Benchmark | RA-70 | accepted; RA-68.9 CONFIRMED; RP-01 locus localized |
| 10 | `M6-CP3-DEFN-R6-CORNER-ASSIGNMENT-AUTHORITY-SPEC` | Definition | RA-71 | accepted; **falsified the reviewer's prediction AND census**; producer NAMED AND VERIFIED |
| **11** | **`M6-CP3-DEFN-R7-CORNER-FACE-SELECTION-REPAIR-SPEC`** | **Definition** | pending | **NEXT — documents only** |
| 12 | first code rung, scope set by rung 11 | undetermined | pending | **not authorized**; rung 11 must pass RA-65.5 first |

- [x] Rung 10 **ACCEPTED** (RA-71) with two charges. Decision: `.agents/Directional/Architecture_M6_CP3_R6_Corner_Assignment_Authority_Spec_Review_Decision.md`.
- [x] **`RP-01` producer NAMED AND VERIFIED.** The corner's source face is selected per **lattice node** by first-match over `activeFaces` in `point_on_source` (`src/geometry/SurfaceCellTracing.cpp:11477-11509`), made authoritative for `SurfacePhaseFrontCell::corners` at `:12949-12958` / `:12986-12987`; `boundaryPaths[side]` is built separately at `:13012-13021`; endpoints are read from the corners at `:13033-13035`. **Code NOT authorized** — RA-65.5 producer test not yet applied to the repair family.
- [x] **RA-71.6 — ordering dependency, NOT a tolerance defect.** `:11483` `tolerance = 1.0e-10`, containment admits `[-tol, 1+tol]`, `:11495-11501` snaps to exact 0/1. A point exactly on a shared vertex passes in **every** incident face (vertex 4 is a corner of f0, f1, f3, f4, f6, f7), so the winner is decided purely by `activeFaces` order. **No epsilon change can repair this — do not touch `tolerance`.**
- [x] **RA-71.7 — the reconciler exists and is blind; third instance of the pattern.** `validate_closed_boundary_paths` is called twice (`:12718`, `:12736`); inside (`:7319-7357`) `valid()` bounds-checks `point.face` and `close()` is a 3D distance test, so a corner in f7 and a path endpoint in f3 at the same vertex pass at distance **exactly 0**. Generalization: **when a missing authority is sought here, look first for it existing in a form that cannot do the job** (cf. RA-68.3).
- [x] **RA-70.14 WITHDRAWN** on its own falsifier (a): the measured 44 are rejections and `:19801-19803` returns before `:19814`, so `:11269` and `:10479` are unreachable; `:19790` is inside the `is_produced()` branch at `:19781`. **The reviewer's three-writer census was wrong by type conflation** — `H:1719` `SurfacePhaseFrontCell::corners` vs `H:2160` `SurfaceCellProposal::corners`, identically typed; all three nominated writers target the latter. **Lesson RA-71.4: an enumeration is only as bounded as the filter that produced it — state the query, not just its result.**
- [x] Charges: **RA-71.9** mandated `ledgers` gate omitted from the closeout and not disclosed (RA-66.4 category, a repeat; both gates run by this Review, both pass); **RA-71.10** under-claimed its own completed attribution — **third consecutive turn in this category** (RA-67.9, RA-70.7, RA-71.10), recorded as a pattern.
- [x] Credits: **`RP-03` satisfied a seventh consecutive turn** — falsified a reviewer prediction **and** a reviewer census in one turn, on the merits; four explicit self-falsifiers stated, all four settleable from source; refused to claim an unverifiable push. Provenance: snapshot `12019178209` ZIP SHA-256 recomputed `37dab2b2f129…`, manifest **5,656 OK / 0 BAD**, `src`/`include`/`tests` tree-identical at `c85bd3600`, `a143af264` and HEAD.
- [x] **Rung 11 — `M6-CP3-DEFN-R7-CORNER-FACE-SELECTION-REPAIR-SPEC` (documents only; definition written, Review pending).** Three static questions: (1) **apply the RA-65.5 producer test** — enumerate every witness a repair needs and name its publisher (`activeFaces` + barycentric test gives the admissible face set; `boundaryPaths[side]` segments carry `segment.face`; this may be the first family whose witnesses all exist); (2) **settle per-node versus per-side** — a node is shared by up to four sides and four cells and `:12949-12958` makes one choice for all, so if their paths lie in different faces the repair is **structural**, not a selection-order fix; (3) **state what a face-identity check at `:12718` would and would not achieve** — it **relocates** the rejection to the true producer and **does not repair `RP-01`**. No code, no compile, no runtime.
- [ ] **Rung 12 is not authorized.** It is the first code rung and its scope is set by rung 11. **Do not reorder rungs 11-12 and do not pre-empt rung 12.**
- [ ] Do not mistake relocation for repair; do not touch `tolerance`; do not epsilon.
- [ ] Carried: `RP-02` **UNREACHED**. Frozen 66/17/49, debt 1, CP2 491/491, R3 403/497, selector 497. **`R4-VIN-01` armed at `a143af264`** — `11994726341`, `11996317553`, `12005034654`, `12010485442`, `12019178209` are baselines, never comparands. RA-61.9, RA-64.6 and RA-70.14 withdrawn. Gate C suspended and moot for `RP-01`. `PROCESS-01` discharged.

---

## HISTORY — R6 Definition source-static result; Review gate only (2026-10-16)

- [x] `M6-CP3-DEFN-R6-CORNER-ASSIGNMENT-AUTHORITY-SPEC`: exact verified source shows RA-70.14 predicted `:11269` cause is unreachable for rejected phase fronts; `:10479` also fallback-only and `:19790` produced-success copy. Actual responsible boundary: planar `point_on_source` first-containing-face selection (`SurfaceCellTracing.cpp:11477-11509`), propagated to phase-front corners (`:12953-12959`, `:12985-12989`) before side paths (`:13012-13022`); closure compares only 3D positions (`:7319-7357`), so source-face disagreement can survive. See `Architecture_M6_CP3_R6_Corner_Assignment_Authority_Specification_20261016.md` for bounded source evidence and falsifiers.
- [ ] Next and only authorized turn: `M6-CP3-DEFN-R6-CORNER-ASSIGNMENT-AUTHORITY-SPEC-REV` independent source-static Review; adjudicate whether this producer supplies the measured f7 vs f3 mismatch and whether any pre-A4 reconciliation exists. **No Code+Build, TB, repair or rung11 implementation is authorized.**
- [ ] RP-01 still unresolved; RP-02 UNREACHED; RA-65 gate C SUSPENDED and moot for RP-01. Frozen ledger 66/17/49 debt 1, CP2 491/491, R3 403/497, selector 497 unchanged. No new runtime/build/tests were performed this Definition turn.

---

## HISTORY — RA-69/RA-70 frozen; RP-01's producer locus localized; next rung is a corner-assignment definition, documents only (2026-10-16)

### Turn sequence (byte-derived from `STATUS` history; frozen clauses in `Architecture_M6_Frozen_Definitions.md`)

| # | Turn | Kind | Review | Outcome |
|---:|---|---|---|---|
| 1 | `M6-CP3-CB2-R4-PREDICATE-SEPARATION` | Code + Build | RA-63 | accepted; probe separated from decision |
| 2 | `M6-CP3-CB3-R4-LEDGER-CONTENT-FLOOR` | Code + Build | — | tooling floor added to both gates |
| 3 | `M6-CP3-TB3-R4-PROBE-HARVEST` | Test + Benchmark | RA-64 | accepted; contradicted the reviewer, credited |
| 4 | `M6-CP3-DEFN-R4-ENDPOINT-AUTHORITY-SPEC` | Definition | RA-65 | accepted w/ amendment; RA-64.6 withdrawn, gate C suspended |
| 5 | `M6-CP3-CB4-R4-ENDPOINT-CHART-PROBE` | Code + Build | RA-66 | accepted; compile chain closed by bytes |
| 6 | `M6-CP3-TB4-R4-ENDPOINT-CHART-HARVEST` | Test + Benchmark | RA-67 | accepted; mechanism derived; 44/44 RED |
| 7 | `M6-CP3-DEFN-R5-JUNCTION-CARRIER-AUTHORITY-SPEC` | Definition | RA-68 | accepted; both repair shapes inadmissible |
| 8 | `M6-CP3-CB5-R5-ROUTE-PATH-RECONCILIATION-PROBE` | Code + Build | RA-69 | accepted; neutrality structural; chain closed by content |
| 9 | `M6-CP3-TB5-R5-ROUTE-PATH-RECONCILIATION-HARVEST` | Test + Benchmark | RA-70 | accepted; **RA-68.9 CONFIRMED**; RP-01 locus localized |
| **10** | **`M6-CP3-DEFN-R6-CORNER-ASSIGNMENT-AUTHORITY-SPEC`** | **Definition** | pending | **NEXT — documents only** |
| 11 | scope set by rung 10 | undetermined | pending | not authorized; do not pre-empt |

- [x] Rungs 8 and 9 **both ACCEPTED** (RA-69, RA-70). Decision: `.agents/Directional/Architecture_M6_CP3_R5_Route_Path_Reconciliation_Review_Decision.md`.
- [x] **RA-68.9 CONFIRMED; the named falsifier did not occur.** `hit_to` separates perfectly and without exception — 0 in all 21 junction cases, 1 in all 23 controls. Partition re-derived from the TSV: 23 controls (route `1,4`, toFace `3`, paths `0`/`3`), 15 junction (route `1,4`, toFace **7**), 6 junction (route `1,2`, toFace **7**); `routeStepCount=1` universal.
- [x] **Mechanism closed from fixture bytes.** Edge `{1,4}` is incident to faces `{0,3}`; the traced paths visit exactly `{0}` and `{3}`. The corner declares `to` in `f7=(4,8,7)`, the far face of the **other** hard edge `(4,7)`, sharing only vertex 4 — so `oriented_carrier` is asked for a face pair meeting at a lone vertex, no edge-keyed carrier can exist, and `carrier-orientation` fails first. **The corner walked around the junction; the path did not.**
- [x] **What the same measurement exonerates (RA-70.7 charge — the turn omitted this):** paths are `0`/`3` in **all 44 rows** and `hit_from=1` **universally**, so the tracer, route publisher, carrier producer and `from` corner are all cleared, leaving **one field on one side**.
- [x] **Both RA-68 repair shapes are the wrong family (RA-70.10)**, not merely unbuildable. Gate C gains a third ground and is additionally **moot for `RP-01`** (RA-70.11) — no consumer-side vertex-star authority can repair a wrong corner.
- [x] `RP-01` → **producer locus localized**: the assignment of `SurfacePhaseFrontCell::corners[(side+1)%4].face` (`include/directional/geometry/SurfaceCellTracing.h:1719`, `SurfaceTracePoint` carries `int face` at `:90-93`). **Code NOT authorized.** RA-65.10 is now the measured defect, not a backlog note.
- [x] Charges: **RA-69.5** chat-retained evidence is not provenance (transport settled harmless by content — packaged cpp hashes equal to the `a143af264` blob and to `HEAD`); **RA-70.7** under-claimed result; **RA-70.8** one edge printed in two index domains, RA-67.13 not applied one rung after freezing.
- [x] Credits: probe neutrality verified **structurally** (`:19360` → depth 2 → `:19566` → `:19567`); absence published as absence; **RA-67.8 discharged and consequential** — the fix turned a hidden ambiguity into dispatch `38831159326`, independently `conclusion=failure`, refused and **disclosed** when the retry would have concealed it. **`RP-03` satisfied a sixth consecutive turn.**
- [ ] **Rung 10 — `M6-CP3-DEFN-R6-CORNER-ASSIGNMENT-AUTHORITY-SPEC` (documents only).** Three bounded corner producers in `src/geometry/SurfaceCellTracing.cpp`: `:10479` primary aggregate from four traced points; `:11269` per-corner override from a two-way closure walk; `:19790` propagation copy. For each, state what authority defines the corner's `face`, whether anything reconciles it against `boundaryPaths[side]`, and which can supply a `face` the traced path never visits. Name the single responsible locus and stop. **No code, no compile, no runtime, no repair design.**
- [ ] **RA-70.14 prediction for rung 10, falsifier named:** `:11258-11271` keeps `xy.point`, discards `yx.point`, and reduces the two walks' disagreement to a positional `closureError` against `closureToleranceFactor * min(hx,hy)` — a face-index disagreement is invisible to a distance test when both faces meet at the junction vertex. **Falsifier:** rejected cells never reach `:11269`, or a face comparison guards it → the locus is `:10479` or `:19790`. **Observation rung: 10, by static reading.** Does **not** revive RA-64.6.
- [ ] **Rung 11 is not authorized.** Its scope is set by rung 10's named locus. **Do not reorder rungs 10-11 and do not pre-empt rung 11.**
- [ ] Residue to close: `get()` is still first-match for the nine non-route fields (bounded to two **control** identities, **measured** harmless — both logs byte-identical across all three emissions).
- [ ] Carried: `RP-02` **UNREACHED**. Frozen 66/17/49, debt 1, CP2 491/491, R3 403/497, selector 497. **`R4-VIN-01` re-arms at `a143af264`** — `11994726341`, `11996317553`, `12005034654`, `12010485442` are baselines, never comparands. RA-61.9 and RA-64.6 withdrawn, final. `PROCESS-01` discharged.

---

## HISTORY — 2026-10-16 TB5 route/path reconciliation harvest verified (separate independent decision pending)

`M6-CP3-TB5-R5-ROUTE-PATH-RECONCILIATION-HARVEST` completed its bounded artifact-only observation. Workflow [38831615391](https://github.com/akashskypatel/Directional/actions/runs/38831615391) **succeeded**, immutable result artifact `12017109271` outer SHA-256 `e394c4deab99e5f8dca919a7a8e61a24aa93de3ba0ed96c3c3afddc19f8b9458`, internal SHA256SUMS verified; packaged source `a143af264bc8b33f0e1b2f8def16b2479b53d5fc` from build artifact `12015849679`. **44/44 separate processes executed; 44 RED, zero missing, postflight passed**, with no compile or benchmark. Diagnostic multiplicity was verified (42×1, 2×3). **RA-68.9 confirmed observationally:** 21/21 junction cases have no route edge incident to the to-attachment face (to row 7, traced second boundary path row 3); 23/23 interior controls have route incidence (to row 3). This supports investigating A4 corner/path producer reconciliation but neither prior repair shape is authorized; no specific producer cause has been proven. First harness attempt [38831159326](https://github.com/akashskypatel/Directional/actions/runs/38831159326) failed postflight due to aggregating multiple diagnostic occurrences; diagnosed retry did not modify production/test semantics. Full record: `.agents/Directional/Architecture_M6_CP3_R5_Route_Path_Reconciliation_Harvest_Artifact_Only_TB_Report_20261016.md`. Ledger 66/17/49 debt 1, CP2 491/491, R3 403/497, frozen 497; RP-02 unreached. Next separately authorized independent decision; no successor ID established.

---

## HISTORY — 2026-10-16 CB5 route/path reconciliation probe — compile GREEN

`M6-CP3-CB5-R5-ROUTE-PATH-RECONCILIATION-PROBE` completed its narrow Code + Build scope. In the post-decision rejection-only A4 endpoint diagnostic, the source now emits each oriented route step's topology key and the distinct source-face sets visited by each owning cell's actual traced boundary path. Exact semantic source [`a143af264bc8b33f0e1b2f8def16b2479b53d5fc`](https://github.com/akashskypatel/Directional/commit/a143af264bc8b33f0e1b2f8def16b2479b53d5fc); snapshot run `38828612903`, artifact `12016346107`, 5651/5651 source hashes verified. **Compile GREEN:** workflow [38829147491](https://github.com/akashskypatel/Directional/actions/runs/38829147491), job `116743695976`, source `a143af264bc8b33f0e1b2f8def16b2479b53d5fc`, artifact `12015849679` outer ZIP SHA-256 `92a014a6d0bc4de3bef55b2ebcec2fd8c5095d3b65f90eb7bd79567dbcb10444`; 28/28 SHA256SUMS, all eight targets, GMPXX and GMP linked, build/preflight exits 0/0, five source-status snapshots empty, `runtimeExecution=false`. No Directional executable, test, benchmark, TB5 or frozen 497 selector was run; no predicates, topology, fixtures, ledgers, gate decisions or source repair changed. The separate authorized successor is `M6-CP3-TB5-R5-ROUTE-PATH-RECONCILIATION-HARVEST`, to be started in its own turn; no interpretation of newly emitted fields in CB5. Evidence: `.agents/Directional/Architecture_M6_CP3_R5_Route_Path_Reconciliation_Probe_Code_Build_Record_20261016.md`. Historical CURRENT sections follow. Ledger 66/17/49 debt 1, CP2 491/491, R3 403/497, frozen selector 497, RP-02 unreached remain unchanged.

---

## HISTORY — RA-68 frozen; both repair shapes inadmissible; next rung is a probe, not a producer (2026-10-15)

### Turn sequence (byte-derived from `STATUS` history; frozen clauses in `Architecture_M6_Frozen_Definitions.md`)

| # | Turn | Kind | Review | Outcome |
|---:|---|---|---|---|
| 1 | `M6-CP3-CB2-R4-PREDICATE-SEPARATION` | Code + Build | RA-63 | accepted; probe separated from decision |
| 2 | `M6-CP3-CB3-R4-LEDGER-CONTENT-FLOOR` | Code + Build | — | tooling floor added to both gates |
| 3 | `M6-CP3-TB3-R4-PROBE-HARVEST` | Test + Benchmark | RA-64 | accepted; contradicted the reviewer, credited |
| 4 | `M6-CP3-DEFN-R4-ENDPOINT-AUTHORITY-SPEC` | Definition | RA-65 | accepted w/ amendment; RA-64.6 withdrawn, gate C suspended |
| 5 | `M6-CP3-CB4-R4-ENDPOINT-CHART-PROBE` | Code + Build | RA-66 | accepted; compile chain closed by bytes |
| 6 | `M6-CP3-TB4-R4-ENDPOINT-CHART-HARVEST` | Test + Benchmark | RA-67 | accepted; mechanism derived; 44/44 RED |
| 7 | `M6-CP3-DEFN-R5-JUNCTION-CARRIER-AUTHORITY-SPEC` | Definition | RA-68 | accepted; both repair shapes inadmissible |
| **8** | **`M6-CP3-CB5-R5-ROUTE-PATH-RECONCILIATION-PROBE`** | **Code + Build** | pending | **NEXT** |
| 9 | `M6-CP3-TB5-R5-ROUTE-PATH-RECONCILIATION-HARVEST` | Test + Benchmark | pending | artifact-only harvest of rung 8 |
| 10 | producer-definition turn, scope set by rung 9 | Definition | pending | deferred behind rung 9 on purpose |

- [x] `M6-CP3-DEFN-R5-JUNCTION-CARRIER-AUTHORITY-SPEC` **ACCEPTED** (RA-68). Both repair shapes fail the RA-65.5 producer test and no winner was picked. Decision: `.agents/Directional/Architecture_M6_CP3_R5_Junction_Carrier_Authority_Spec_Review_Decision.md`.
- [x] Gate C **re-grounded and still SUSPENDED**: `SurfaceHardRailRouteJunctionCertificate` exists (`SurfaceCellTracing.h:1512-1516`) but is constructed at `SurfaceCellTracing.cpp:19525-19530` and published at `:19728-19731`, both reachable only past the rejection branch at `:19352-19360` — ordered too late to authorize the admission it would license.
- [x] Naive split falsified by measurement: `routeLength=1` in every raw log. **RA-68.5 charge:** the spec reports this of the 21 when it holds for all 44; the 23 do not control for this property.
- [x] Two new loci recorded, neither authorized: boundary hard rails publish **no** carrier (`:18939-18941`, `incident->second[1] < 0` → `continue`); the published face pair is canonically ordered (`:18968-18970`), so `oriented_carrier`'s two-branch test is complete.
- [ ] **Rung 8 — `M6-CP3-CB5-R5-ROUTE-PATH-RECONCILIATION-PROBE` (compile-only, rejection-only).** Extend the post-decision probe block opened at `:19360` to emit, for rejected edges only, the route's step count, each step's source-edge topology key, and the distinct source-face set visited by the traced path, beside the corner-derived endpoint faces already emitted. Decision-neutral by construction; compile and dispatch a package; **do not interpret the fields**.
- [ ] **Rung 9** harvests those fields against the new package and tests the RA-68.9 prediction: the route's step edge set contains no edge incident to the `to` endpoint face (falsifier: it does).
- [ ] **Rung 10** defines a producer only if rung 9 leaves one needed. **Do not reorder rungs 8-10.**
- [ ] Carried: `RP-01` measured, mechanistically derived and bounded on both families — **code NOT authorized**. `RP-02` **UNREACHED**. Frozen 66/17/49, debt 1, CP2 491/491, R3 403/497, selector 497. RA-61.9 and RA-64.6 withdrawn, final.

---

## HISTORY — R5 junction/carrier definition delivered; independent decision gate (2026-10-15)

- [x] `M6-CP3-DEFN-R5-JUNCTION-CARRIER-AUTHORITY-SPEC`: independent source/fixture check confirms RA-67.6 for 21 junction cases only. Recorded existing producer/witness census, both candidate repair shapes and concrete falsifiers in `.agents/Directional/Architecture_M6_CP3_R5_Junction_Carrier_Authority_Specification_20261015.md`; no implementation or runtime authority inferred.
- [x] Both candidate shapes examined against actual producer ordering. Neither presently has the requisite pre-admission junction witness; naive division of a one-step carrier route is insufficient. The 23 nonjunction REDs remain separate controls. Gate C SUSPENDED; no replacement predicate licensed.
- [ ] Authorize a **separately named independent Review/producer-definition decision** before any change to A2b/A3/A4/A5, new vertex-star type, new paired-front producer, test selector, or green ledger. No successor ID established. Frozen 66/17/49, debt 1, CP2 491/491, R3 403/497, selector 497; RP-02 still UNREACHED.

---

## HISTORY — TB4 endpoint-chart harvest evidence durably recorded; independent Review separately required (2026-10-15)

- [x] `M6-CP3-TB4-R4-ENDPOINT-CHART-HARVEST`: 44/44 artifact-only identities executed against new immutable package `11994726341` and semantic source `5be5e123e`, 44 RED / 0 missing, run `38782417387`, result `11996317553`, ZIP SHA-256 `44df6e2fc1bdba1e15f81e11ddec7bbb6cc90e2d43adcda4f334d875d1dbd9c9`. Observed 23 both-attached interior and 21 from-only junction cases; computed canonical carrier edges, no emitted `a2bProbeCarrierEdge`. Detailed report: `.agents/Directional/Architecture_M6_CP3_R4_Endpoint_Chart_Harvest_Artifact_Only_TB_Report_20261015.md`.
- [x] Append `R4-VIN-01` non-stable vintage in protected regression tracker and preserve previous headings and line floors; update handoff and two changelogs, using exact 5,647/5,647 verified source snapshot `393d6c5488ff2a8866327fad9bab27a8389619d6` (run `38805395498`). Earlier CURRENT section's unchecked closeout item is superseded by this evidence entry without erasing the historical task record.
- [ ] **Next action requires separately authorized independent Review**, with no named turn ID established. Review measured attachment/carrier keys and *exhibit* the fixture's other incident rail edges before asserting a source sector, publisher failure or `RP-01` remedy. Do not start code changes, TB497, selector/acceptance promotion or new ledger credit. 66/17/49, debt 1, CP2 491/491, R3 403/497, frozen 497 unchanged; `RP-02` unreached.

---

## HISTORY — endpoint chart artifact-only harvest measured; durable closeout pending (2026-10-15)

- [x] `M6-CP3-TB4-R4-ENDPOINT-CHART-HARVEST` executed 44/44 identities on **new immutable artifact 11994726341** at semantic `5be5e123e`, workflow [38782417387](https://github.com/akashskypatel/Directional/actions/runs/38782417387), result artifact `11996317553`, ZIP SHA-256 `44df6e2fc1bdba1e15f81e11ddec7bbb6cc90e2d43adcda4f334d875d1dbd9c9`, entire manifest verified. **44 RED, 0 missing**, fail-closed. All 21 carrier-orientation cases measured actual rows `0→7`, with exactly one endpoint attachment in the carrier face pair: 15 computed edge (1,4), 6 computed edge (1,2). Full per-identity record: `.agents/Directional/Architecture_M6_CP3_R4_Endpoint_Chart_Harvest_Artifact_Only_TB_Report_20261015.md`.
- [ ] **Durable turn closeout remains pending:** append the non-stable recurring `R4-VIN-01` measurement to `.agents/Directional/Regression_Root_Cause_Tracker.md` and verify the full long-file protected-history constraints; update handoff/changelogs without truncation; set final STATUS only after these are committed. Independent Review is separately required before any `RP-01` code correction or sector/mechanism claim. Do not run TB497, change frozen selectors, alter acceptance or ledger counts, or reuse the old artifact. The tracker exceeds the GitHub contents read ceiling; a fresh exact source snapshot and verified Drive patch transport are required for its safe mutation. Until complete, continue **the same TB4 turn**, not a successor.

---

## HISTORY — endpoint chart probe compile-only completion (2026-10-15)

- [x] `M6-CP3-CB4-R4-ENDPOINT-CHART-PROBE`: rejection-only actual endpoint face/source topology/carrier face diagnostic published at semantic `5be5e123e14e2ddab8bb8c0db2a354a0a900435a`; compile GREEN [38776964197](https://github.com/akashskypatel/Directional/actions/runs/38776964197), artifact `11994726341`, SHA256 `b59dc16f4417693c4aec79025160da2054cfbca3a1589ef051ee3a171d3185bb`, 28/28 manifest, eight GMP/GMPXX targets, preflight/build 0/0, no runtime. Owning record `.agents/Directional/Architecture_M6_CP3_R4_Endpoint_Chart_Probe_Code_Build_Record_20261015.md`.
- [ ] **Separate authority required** for immutable artifact-only diagnostic execution and independent Review. Do not invent successor, repair RP-01, assume endpoint face pair, promote credits, run frozen TB497, or change ledger (66/17/49; debt 1; CP2 491/491; R3 403/497).

---

## HISTORY — endpoint chart source diagnostic Code + Build (2026-10-15)

- [ ] `M6-CP3-CB4-R4-ENDPOINT-CHART-PROBE`: publish post-rejection source-face rows and source topology attachment/carrier keys, apply the source patch, and verify exact-source mandatory eight-target GMP/GMPXX compile. No runtime, no `RP-01` repair, no selector/ledger changes. Evidence record `.agents/Directional/Architecture_M6_CP3_R4_Endpoint_Chart_Probe_Code_Build_Record_20261015.md`.
- [ ] Separately authorize artifact-only diagnostic execution and independent Review after this compile, without assuming endpoint faces `{0,7}` or inventing a vertex-star authority product. Preserve RA-65 amendments, frozen 497 selectors and historical ledgers.

---

## HISTORY — R4 ledger content floor completed (2026-10-15)

- [x] `M6-CP3-CB3-R4-LEDGER-CONTENT-FLOOR`: Python-only nonzero committed-history heading/line floors, tracker zero-tolerance, consumed request cleared to noop. Isolated destructive-equal-line rejection and legitimate-prepend acceptance checked, no simulations committed. Evidence: `.agents/Directional/Architecture_M6_CP3_R4_Ledger_Content_Floor_20261015.md`. No C++ build, runtime, selectors, ledger credit.
- [ ] Next separately authorized `M6-CP3-TB3-R4-PROBE-HARVEST`: artifact-only on the current new diagnostic source; no `RP-01` repair or RA-61.9 remedy. Ledger 66/17/49, debt 1, CP2 491/491 and R3 403/497 frozen.

---
## HISTORY — R4 predicate diagnostics compile-only complete (2026-10-15)

- [x] `M6-CP3-CB2-R4-PREDICATE-SEPARATION`: RA-62.2 committed-history durable integrity guard for handoff/ORIENTATION plus decision-neutral A2b actual one-hot source vertex, both exact-rational shared intervals/ordinals and typed first-rejection diagnostic. Semantic `16c3134c02ab3872eee77a6b9dcc9d3fc6e01b7b`, apply [38742750098](https://github.com/akashskypatel/Directional/actions/runs/38742750098). Source-exact GMP/GMPXX eight-target compile [38743048456](https://github.com/akashskypatel/Directional/actions/runs/38743048456), job `116449586867`, artifact `11976790988`, ZIP SHA-256 `31faf55a33c31abb60c8f34acb64ad901514de821cd6d2f3acbdcd817b1dbb36`, **28/28** digests; no runtime. No test/fixture/selector changes. Details in handoff and both changelogs.
- [ ] **No named successor currently authorized.** Future immutable artifact-only targeted Test + Benchmark and independent Review require separate explicit turn authority. Do not run TB497, infer predicate acceptance, repair `RP-01`, promote historical counts, or begin a successor from a `Successor: UNKNOWN` beacon. Keep ledger 66/17/49, debt 1, CP2 491/491, R3 403/497, frozen 497; `RP-02` unreached, PR #8 draft/open.

---
## HISTORY — R4 immutable terminal-conjunct extraction complete (2026-10-15)

- [x] `M6-CP3-TB2-R4-CONJUNCT-EXTRACT`: existing artifact `11967601999` from workflow `38725063279`, outer SHA-256 `8b52373eebc7bda574f1fed2914dec4577ff70c670396f2ea3b19383d0fd25f1`, **50/50** manifest. All 45 original log rows classified without rerun: **23 interior-shaped**, **21 one-hot**, **ordinal 405 separate**. In every one-hot case candidate 1 belongs to the carrier edge but fails both exact-corner checks; candidate 6 or 7 fails all three. No source/test edits, workflow dispatch, executable, acceptance or ledger credit. Full evidence: `.agents/Directional/Architecture_M6_CP3_R4_Terminal_Conjunct_Artifact_Extraction_20261015.md`.
- [ ] **Next separately authorized `M6-CP3-CB2-R4-PREDICATE-SEPARATION`**: diagnostic-only distinct A2b first-rejection reasons, plus `sharedBoundaryInterval` presence and exact ordinals (RA-61.9 falsifier (i)); acceptance MUST remain unchanged. No epsilon, unreviewed RA-61.9 remedy, combined test runtime, or TB497. `RP-02` not reached. Ledger 66/17/49, debt 1, CP2 491/491, R3 403/497, frozen 497 unchanged; PR #8 draft/open.

---

## HISTORY — R4 interior carrier witness Code + Build compile complete (2026-10-15)

- [x] `M6-CP3-CB1-R4-WITNESS-REPAIR`: RA-59.9 approved exact source-carrier certificate implemented at `570c51733761c17a198bda6c9aba7d8b1e7ae2dd`; mandatory eight-target GMP/GMPXX compile GREEN workflow 38720128740 result artifact 11964478813, 28/28 verified, no test runtime. Owner report `Architecture_M6_CP3_R4_Witness_Repair_Code_Build_Record_20261015.md`.
- [ ] **Separately authorize immutable artifact-only supplemental TB and independent Review** of RP-02 original positive/typed tamper negatives, stop on first RED, then other six only as prescribed. Exact successor turn ID not yet frozen; do not invent. Historical Phase14 packaging is separate. Frozen 497 and ledger unchanged (66/17/49 debt1; 491/491 CP2; R3 403/497). The TODO CURRENT blocks below are historical superseded states.

---
## HISTORY — Endpoint39 census measured; carrier independent Review is the next authorized turn (2026-10-15)

- [x] `M6-CP3-TB1-R4-ENDPOINT39-CENSUS`: artifact-only workflow 38687783618; 39/39 exact identities executed, 39 RED, 0 missing, immutable package/selector/source, 28/28 manifest before and after, no build/TB497. Detailed report `Architecture_M6_CP3_R4_Endpoint39_Census_Artifact_Only_TB_Report_20261015.md` and 39-row `Architecture_M6_CP3_R4_Endpoint39_Census_Measured_Identities_20261015.tsv`. 38 endpoint-1/no-exact-terminal-corner; 1 endpoint-0/missing-terminal-or-closed-rail-provenance; shared thrown fixture causes flagged; no semantic acceptance, no new stable regression or ledger change.
- [ ] **Next turn only: `M6-CP3-TB1-R4-CARRIER-REV`**, mandatory independent architecture Review; adjudicate terminal certificate / incorrect pairing / truncated route with RA-58 and the full 39-row census. Do not silently pick hypothesis or relax terminal authority. Retained `M6-CP3-CB1-R4-WITNESS-REPAIR` requires subsequent authorization and RA-57.5 across-rail terminology correction; RA-58.7 A5/A6/A7 and RP-02 are independent debt. Frozen selector 497 untouched, stable 66/17/49, debt 1, CP2 491/491, R3 403/497, PR #8 open draft.

---
## HISTORY — true controls measured; 39-identity R4 census next (2026-10-15)

- [x] `M6-CP3-TB1-R4-TRUE-CONTROL` 4/4 executed, square/cylinder PASS, both closed-chain torus tests RED. Orchestration complete with intact immutable package and 28/28 pre/post checksums; exact torus failures are missing arrangement/occurrence products, **not** proven open-rail `no-exact-terminal-corner`. See `Architecture_M6_CP3_R4_True_Control_Artifact_Only_TB_Report_20261015.md`.
- [ ] **Next only `M6-CP3-TB1-R4-ENDPOINT39-CENSUS`** (new artifact-only turn), same immutable package and all 39 exact identities. Record owning fixture singleton, first predicate, `a2bProbeFailure`, `routeLength/step/chi`, source probe charts/parameters, `closedChainPresent` and complete `faceEnds`/rail/edge details (RA-57.12). No build, source/test/selector mutation, TB497 or acceptance. Then independent `M6-CP3-TB1-R4-CARRIER-REV` before any approved repair. Ledger 66/17/49, debt1 unchanged.

---

## HISTORY — RP-02 first-RED independent Review, 2026-10-15

- [x] `M6-CP3-TB1-R4-WITNESS-REV` independently localized `R4-TB-A-RP02-01`: paired source-edge-interior samples are not authentic whole-rail terminal source vertices; terminal-corner gate correctly rejects the incorrectly routed interval. Detailed `Architecture_M6_CP3_R4_Witness_First_RED_Independent_Review_Decision_20261015.md`. Valid first-RED measurement; non-stable; no RP-02 runtime PASS.
- [ ] **Next only `M6-CP3-CB1-R4-WITNESS-REPAIR`**, exact typed source-edge/interval-vs-terminal correction, 8-target GMP compile-only; see `Architecture_M6_CP3_R4_Witness_Interval_Terminal_Recovery_Code_Build_Plan.md`. Stop for Review if a sound interior certificate cannot be expressed without relaxing terminal authority. Separate immutably packaged supplemental TB/Review before TB497; six identities unexecuted, Phase14 historical binary still missing. Stable 66/17/49, debt1, 491/491 accepted CP2 and 403/497 rejected R3 frozen.

---

## HISTORY — R4 supplemental TB first-execution RED (2026-10-15)

- [x] `M6-CP3-TB1-R4-WITNESS-EXEC` immutable artifact-only run 38668126299; 1/1 executed RED at `SurfaceCellAuthorityContractCutover.ProducedRailIntervalReachesNetworkBoundOpenFrontConsumer` initial `Produced` precondition; actual `a2bProbeFailure=no-exact-terminal-corner` / no closed chain. 6 planned witnesses not executed under mandatory stop-on-first-RED. Artifact/source/selector immutable, no TB497 or benchmark.
- [ ] **Next separate independent Review `M6-CP3-TB1-R4-WITNESS-REV`**: determine causal fork between source A2b terminal-corner failure and witness fixture validity. Preserve `RP-02` coverage gap; classify candidate `R4-TB-A-RP02-01` before a Code + Build correction. Future Phase14 executions also require separate immutable package with historical test executable.

---

## HISTORY — RP-02 network-bound open-front consumer witness compiled (2026-10-15 UTC)

`M6-CP3-CB1-R4-RP02-WITNESS` authored **one** nonvacuous producer-to-consumer source test `SurfaceCellAuthorityContractCutover.ProducedRailIntervalReachesNetworkBoundOpenFrontConsumer` in `tests/SurfaceCellsPhase10Tests.cpp`: authentic A2a network and producer rail must yield an A4 `HardRail` open-front edge and an actual filled cell/side with typed route, while a forged typed rail source edge must cause `InvalidFrontBoundaryAuthority` at that same A4 consumer. The test fails if `assign_open_front_boundary_authority` is skipped. Semantic source `953f812ff1f431e3ad3af3b68a92284a7831c94a`; pinned eight-target GMP/GMPXX compile [38664036225](https://github.com/akashskypatel/Directional/actions/runs/38664036225), artifact `11939982141` SHA-256 `2d5d1fc3f75b573307cae8af3c837da3dde2302ffdb4fe0ef3dd34d2aafeed7a`. **Compile-only; no binaries, tests, benchmarks or TB497 executed; no runtime PASS.** Detailed evidence `.agents/Directional/Architecture_M6_CP3_R4_RP02_Network_Bound_Consumer_Witness_20261015.md`.

**R4 Code + Build authoring ends here:** both last authoring turns (OHF-01 and RP-02) are disposed. Stop and await a separately authorized immutable-artifact TB / independent acceptance Review, not another invented Code rung. Frozen 497 selector, 66/17/49 ledger, debt 1, CP2 491/491, R3 403/497, PR #8 open draft unchanged.

---

## HISTORY — OHF-01 overfull hard-feature factory reachability probe (2026-10-15 UTC)

`M6-CP3-CB1-R4-OHF01-PROBE` answers **(b) UNREACHABLE through the checked source/atlas construction path**, source-only. `SourceTopologyRegions::make` can encode three incident faces, but `TriMesh::set_mesh` derives topology and rejects repeated directed halfedges via `DCEL::check_consistency` (three undirected-edge incidences force a duplicate direction), `FieldTransportAtlas::make` has no alternate supported construction seam, and `SurfacePhaseFrontProduct::make` pins the same source faces/regions to that atlas **before** counting rail incidences. Coupled retirement only; retain the fail-closed `OverfullHardFeatureIncidence` guard, reopen if any checked-construction/atlas-binding guard weakens. Evidence: `.agents/Directional/Architecture_M6_CP3_R4_OHF01_Overfull_Hard_Feature_Reachability_Probe_20261015.md`; source `3b655c44dc102603d1c7b16b2d1f4fa4a1c02987` snapshot run `38660874872`, artifact `11938238763`, **5604/5604** hashes. No implementation/test edits, compile, executable, benchmark or TB497. The only next Code + Build authoring turn is **`M6-CP3-CB1-R4-RP02-WITNESS`**, separate and not started; subsequent runtime requires separately authorized immutable-artifact TB. Ledger 66/17/49 and debt 1, accepted 491/491, R3 403/497, PR #8 draft/open remain unchanged.

---

## HISTORY — RA-43.4 standalone geometry helper disposition (2026-10-14)

- [x] `M6-CP3-CB1-R4-RA434-DISPOSE`: source-only no-op; retain `rail_sample_source_vertex` and `rail_sample_geometry_is_valid` with its explicitly scoped untyped diagnostic fallback. No independent untyped production caller or network bypass; strict production caller census 3/3. Frozen RA-52.6 preserves named opt-out and network override. Evidence `.agents/Directional/Architecture_M6_CP3_R4_RA434_Standalone_Geometry_Helper_Disposition_20261014.md`; exact verified snapshot `fa230b2a00e698eee9478fc06b3490cba5a86a11`, run 38656142605, artifact 11937071668, 5603/5603 hashes. No code/test/build/runtime/ledger/selector change.
- [ ] Main R4 Code + Build and RP-02/39/34/7/88/six/organic/A1/odd-τ/multi-carrier evidence remain open. The frozen ladder names no additional successor; require fresh authorized next turn rather than inventing one. No TB497 here.

---

## HISTORY — RA-43.4 standalone geometry diagnostic census (2026-10-14)

- [x] `M6-CP3-CB1-R4-RA434-CENSUS`: exact source `b0d5c584a98d5ad321c324be9f18db5ba03d434b`, snapshot `38653652905`, artifact `11935277891`, 5602/5602 hashes. Two identity-relevant standalone geometry helper APIs; no direct untyped production caller and no production legacy named opt-out. Frozen RA-52.6 caller table retained in `.agents/Directional/Architecture_M6_CP3_R4_RA434_Standalone_Geometry_Diagnostic_Census_20261014.md`. No runtime/build/test.
- [ ] Next separate `M6-CP3-CB1-R4-RA434-DISPOSE`: adjudicate only those helpers without removing RA-52.6 opt-out or weakening the network override. R4, RP-02 and historical test gates remain open.

---

## HISTORY — RA-46.6 typed factory subcodes (2026-10-14)

- [x] `M6-CP3-CB1-R4-RA466-SUBCODES`: exact source `0f2b1822cf3fecd209a610b6055549c561a000c3` already implements the seven frozen typed distinctions. No duplicate production/test changes or unchanged-source compile. See `.agents/Directional/Architecture_M6_CP3_R4_RA466_Typed_Factory_Subcodes_NoOp_20261014.md`.
- [ ] The next **separate** `M6-CP3-CB1-R4-RA434-CENSUS` must inventory other standalone geometry diagnostic sites while preserving RA-52.6 and no-network opt-out; no TB497 or ledger update.

---

## HISTORY — RA-47.12 default-path consumer-liveness census (2026-10-14)

- [x] `M6-CP3-CB1-R4-RA4712-LIVENESS` source-only audit at verified snapshot `f983508edcd0157ca3c93832753102067ab392ef` (run 38645902635, artifact 11932381704, 5600/5600 files). Source path offers network-bound typed interval validation, but no *executed* normal-pipeline witness proves the consumer was reached with producer-built rails. **RP-02 TEST_AUTHORITY_COVERAGE_GAP**; see `.agents/Directional/Architecture_M6_CP3_R4_RA4712_Default_Path_Typed_Interval_Liveness_Census_20261014.md`. Prior authored factory/producer assertions do not close execution liveness.
- [ ] Separate artifact-only TB and Review must supply a nonzero, non-vacuous real-consumer receipt; no runtime accepted here. The next separate Code + Build rung is `M6-CP3-CB1-R4-RA466-SUBCODES` (reachable predicates only); retain frozen RA-52/RA-53 and historical 497/ledger gates. No test/production code/build/TB performed here.

---

## HISTORY — RA-47.11 seven-site source-only census (2026-10-14)

- [x] Audit all seven `source_edge_index` textual sites at exact source `09e8451ed6314a458e9abe8c6b74e866d19728fc` (snapshot 38640107266, artifact 11930195949, 5598/5598 file hashes). All six callers require real EV rows or mesh-edge membership; the seventh site is the typed-key-to-row helper. **No wrongly untyped site or migration target**. Record: `.agents/Directional/Architecture_M6_CP3_R4_RA4711_Seven_Source_Edge_Index_Census_20261014.md`. No tests, builds or runtime ran.
- [x] `M6-CP3-CB1-R4-RA4711-MIGRATE` disposed as a documented **no-op** because all seven sites were legitimate; zero edits, zero unchanged-source compiles. Record: `.agents/Directional/Architecture_M6_CP3_R4_RA4711_Migration_NoOp_20261014.md`.
- [ ] Next separately authorized `M6-CP3-CB1-R4-RA4712-LIVENESS` must investigate producer-path typed-interval liveness without starting it in the migration turn. Frozen 497 and all other carried R4 gates remain untouched.

---

## HISTORY — R4 verified current source; independent selected-branch Review prerequisite (2026-10-14 18:30 UTC)

R4 remains Code + Build with exact compile-GREEN source `5ecaa2acbec9a03622e14e6afac4dfc71763778f` / immutable GMP package `11919172109` / `38613136344` (28/28 checksums, 8/8 targets, runtimeExecution=false). Current source snapshot `8f490bd7fb196bfb2a9d8b83cf9c65c5d6c001d0` / [38615232734](https://github.com/akashskypatel/Directional/actions/runs/38615232734), artifact `11919555806`, 5594/5594 source hashes; no semantic source/test drift. Re-inspection confirms A4 junction route certificates cannot authenticate the A1 branch *selected* at the directed arrival and the oriented filled side. RA-43.4 production entries are typed; the explicit standalone opt-out has no demonstrated network-bound bypass, but its retention is an independent Review policy question. **Do not invent a selected-branch receipt or remove the opt-out without independent Review**; no newly verified unblocked source edit remains. Exact source/first-failure Review request: `Architecture_M6_CP3_R4_Source_Current_Review_Gate_20261014.md`. No runtime tests, TB497, successor, selector/accepted-ledger changes. 39/34/7/88/six and organic/A1/RA-47.12 remain for later authorized TB and acceptance Review.

---

## HISTORY — R4 standalone negative curve-owner sentinel (2026-10-14)

- [x] R4 standalone rail negative-owner sentinel guard: exact source `42d7915e9e3ba34216a50ff48974c8e9734af91f` now rejects `AdaptiveFeatureEdge::curve=-2` for a source-valid unowned rail (only `-1` denotes unassigned). Existing producer rejection test expanded, no new test identity. Apply run 38600624930 artifact 11913556037 verified; mandatory eight GMP/GMPXX targets compile GREEN in run 38600920037 job 115979814702, package 11913234237, SHA-256 `89d899cffebdf077c2903c88de716cf94862ae15512787410c3eafda9d339829`, manifest 28/28; no executable test, benchmark or acceptance claim. Owning record `Architecture_M6_CP3_R4_Standalone_Negative_Curve_Owner_Guard_20261014.md`.
- [ ] Preserve seven DCEL historical first-failure oracles, RA-43.1/.2/.4 independent decisions and future artifact-only 497 gate; compile GREEN does not close those obligations.

---

## HISTORY — R4 historical seven-DCEL regression static census (2026-10-14)

- [x] Source-fixture migration already present for selector449 R3 DCEL-RED ordinals 40/220/221/296/302/304/439; dual-triangle source-matched A3 and original test oracles verified statically against snapshot 38596495573 (5963/5963 hashes). See `Architecture_M6_CP3_R4_Seven_DCEL_Fixture_Static_Census_20261014.md`. Do not repeat these implementation edits.
- [ ] All seven remain unverified at runtime: only future immutable artifact-only TB plus Review can restore their accepted-prefix credit. Frozen 497, ledger, RA-43.1/.2/.4, RA-47.12, 39/34/88/six and organic CP3 witnesses remain unchanged.

---

## HISTORY — R4 duplicate curve-owner correction (2026-10-14)

- [x] Apply two-file curve-owner ID integrity guard, semantic `6d6d269dd2df211a96de1fcd20bacb54a4e34358`, apply workflow [38593331149](https://github.com/akashskypatel/Directional/actions/runs/38593331149) GREEN, result artifact `11909000384` SHA256 `5584bc466c04a8f696ededf55b9b129fd4ec1b972815e14078c08edb95964f81`, staging owner-deleted, exact two-file +26-line change. No new test identity, selector or ABI change.
- [ ] Pinned eight-target GMP/GMPXX compile result: compile GREEN in [run 38593643840](https://github.com/akashskypatel/Directional/actions/runs/38593643840), job `115954831123`, artifact `11909760571`, outer SHA256 `b84cf6a8215c8cbf02a8b0f5a443854a18cf738d9144f7fb0b29bfabfd206fa8`, root manifest 28/28, all eight GMP/GMPXX targets, preflight/build 0/0, clean source, `runtimeExecution=false` (no tests/benchmarks); independent RA-43.1/.2 and RA-43.4, 39/34/7/88/six and all organic/RA-47.12/odd-τ TB obligations stay open. No runtime acceptance or successor.

---

## HISTORY — `M6-CP3-CB1-ENTRY-R4` compile evidence reconciled (2026-10-14)

- [x] Correct source-curve membership for uncovered standalone hard rails: semantic `f026512e`, compile run `38586952664`, eight GMP/GMPXX targets GREEN, 28/28 manifest, no runtime; evidence `Architecture_M6_CP3_R4_Orphan_Curve_Membership_Source_Guard_20261014.md`.
- [ ] Remain R4 Code + Build; independent RA-43.1/.2 provenance Review and RA-43.4 diagnostic API decision open. Retain 39/34/7/88/six and organic D1/D2/D3/D5/A6/A7/RA-47.12/odd-τ obligations for separately authorized artifact-only TB; no selector or acceptance promotion.

---

## HISTORY — R4 produced odd-τ admitted A1 germ fan typed topology and directed branch-lift compile (2026-10-14 UTC)

Canonical `M6-CP3-CB1-ENTRY-R4` **IN_PROGRESS Code + Build**, PR #8 draft/open; continue this same turn, not TB497/successor. Existing `SurfaceCellPipelinePhase20.ProducedNonconstantTwoCarrierOddTauSharesA1VertexGerm` source-only test now independently attests all sectors of a **genuinely admitted** A1 vertex-star owner on the real A4-produced two-carrier odd-τ rail: source-component/topology-region/junction containment, continuous radial edge ordering, absence of atlas nontraversable and A4 hard carrier crossings, actual directed `topology.transport`, and exact `FieldBranch` rotation under each signed A3 lift. Rejected diagnostic paths remain nonaccepting. Two isolated commits [c937c29](https://github.com/akashskypatel/Directional/commit/c937c29e91576313437d5ee2dd9427c452e1640d) and final [d47b363](https://github.com/akashskypatel/Directional/commit/d47b363682e449bb6525ec9fc4f6fd4d56c04d14) modify **only** this existing test; final Git blob `841eac2a7d8fd4f15f3405b6fefac83f937870a2`. Full-index verified recovery patches preserved in Directional Library.

**Final exact-source 8/8 GMP/GMPXX compile GREEN:** [run 38526113617](https://github.com/akashskypatel/Directional/actions/runs/38526113617), job `115726847638`, source `d47b363682e449bb6525ec9fc4f6fd4d56c04d14`, artifact `11875598179`, ZIP SHA256 `e702072b87cd9fd8d5a0192575b1a443db4368d0221e5969b47ab26b3cb96f1d`. Independently verified 28/28 manifest, all eight targets, exits 0/0, GMPXX+GMP actual link, five clean source-status files, exact test blob, `runtimeExecution=false`. No binary/test/benchmark ran; **not a runtime PASS**. Owning report: `.agents/Directional/Architecture_M6_CP3_R4_RA431_Produced_OddTau_Multicarrier_Germ_20261014.md`; full downloadable continuation is `/Directional/Evidence/Directional_R4_A1_Owner_Fan_Continuation_20261014.md` in ChatGPT Library.

**Still open:** the A4-selected *source field branch* cannot independently be attributed to the A1 germ with currently published A4 junction certificates; prior `Architecture_M6_CP3_R4_RA431_A1_A4_Branch_Coupling_Census_20261014.md` remains the narrow design/review path, and this test does not resolve it. Actual odd-τ owner runtime witness only in separately authorized artifact-only TB; other RA-43.1/.4 source-consumer work, RA-47.12 executed liveness, historical 39/34/7/88/six restorations, organic D1/D2/D3/D5/A6/A7 remain open. RA-46.5/46.6 oracles and RA-49/51 retirements retained; frozen 497 selector and acceptance ledger unchanged. No TB497, PR change or successor.

---

## HISTORY — R4 RA-43.1 A4/A1 selected-branch attribution gap (source-only; 2026-10-14 UTC)

Canonical `M6-CP3-CB1-ENTRY-R4` remains **IN_PROGRESS Code + Build**, PR #8 draft/open. Reused verified exact compile source `182b0b835148ac80c9add15a38f2a9d4380fada6` (artifact `11873407961`, 28/28 manifest). **New source-census finding:** the compiled `ProducedNonconstantTwoCarrierOddTauSharesA1VertexGerm` now requires an admitted unique A1 owner, but independently searches **all** sector seed-face `FieldBranch` pairings. The A4 `SurfaceHardRailRouteJunctionCertificate` attests source vertex, A3 source-edge/face/quarter-turn paths and a two-carrier route, **not the selected A1 field branch of the corresponding A4 trace**. Thus the source-authored positive does not yet prove *branch-specific* A4/A1 ownership, even if it passes at runtime. The trace/front `branchRotation` and A1 `FieldBranch` mapping needs an independently sourced orientation and source-gauge receipt; the existing RA-43.2 producer-side oriented terminal review gate is related but does not itself supply it. Do not fabricate a branch from geometric coincidence or weaken the current admitted-owner assertion.

Durable source-only evidence and prescriptive next steps: `.agents/Directional/Architecture_M6_CP3_R4_RA431_A1_A4_Branch_Coupling_Census_20261014.md`, published in [59a5aa4](https://github.com/akashskypatel/Directional/commit/59a5aa491779aa13a4c0e4fd6097b6d0fb7de807). An exact report copy is preserved in Directional Library `/Directional/Evidence/Directional_R4_A1_A4_Branch_Coupling_20261014.md`. **No source/test/build/benchmark/runtime changes this attempt**. Narrow independent Review is needed if no existing upstream typed trace-to-front branch ownership link exists; other R4 Code + Build duties may continue. Previous compile [38520696782](https://github.com/akashskypatel/Directional/actions/runs/38520696782) remains compile-only GREEN; no runtime acceptance credit. RA-43.1/43.4, RA-47.12 liveness, historical 39/34/7/88/six and organic D1/D2/D3/D5/A6/A7 remain open. Frozen 497 selector unchanged; no TB497 or successor.

---

## HISTORY — R4 odd-τ positive no longer accepts rejected vertex-transit diagnostics (2026-10-14 UTC)

Canonical `M6-CP3-CB1-ENTRY-R4` **IN_PROGRESS Code + Build**, PR #8 draft/open. Static source review uncovered a material false-positive in `SurfaceCellPipelinePhase20.ProducedNonconstantTwoCarrierOddTauSharesA1VertexGerm`: the original accepting sum (`verifiedOwners + evaluatedNontrivialGerms`) counted *rejected* `FieldAlignedCurveNetworkError::vertexTransitStates` diagnostic walks as if an admitted A1 vertex-star owner existed. Real `resolve_field_vertex_transit` returns `FieldVertexTransitDecision` only after certifying an eligible owner; an evaluated path preceding a fail-closed return is not admissible. Corrected existing test to require `verifiedOwners > 0` for its positive assertion; failed-walk counts are diagnostic only. Exact semantic [182b0b8](https://github.com/akashskypatel/Directional/commit/182b0b835148ac80c9add15a38f2a9d4380fada6), test blob `8b26c8fa80a7a3ccf1eb6db63c79972f84d90cb1`; verified exact-base patch SHA-256 `3b5c6abc9af2cfcfb2efeb2c749438f903b081a805465f286d9a4c0004ac57de` backed up to Directional Library Evidence.

**Pinned GMP/GMPXX eight-target compile GREEN:** [run 38520696782](https://github.com/akashskypatel/Directional/actions/runs/38520696782), job `115709569509`, source `182b0b835148ac80c9add15a38f2a9d4380fada6`, artifact `11873407961` ZIP SHA256 `844accc1318bf4b5ce05ad83775a589d2b398c1796432f76b0d0e7d0a8dc3372`, 28/28 hashes, 8/8 targets, preflight/build 0/0, GMPXX/GMP generated link, five clean status files, source test blob exact, `runtimeExecution=false`. No generated binary, test, benchmark or TB497 run; **actual positive odd-τ owner unproven** and cannot be credited until authorized artifact-only TB execution. Durable evidence: `.agents/Directional/Architecture_M6_CP3_R4_RA431_Produced_OddTau_Multicarrier_Germ_20261014.md`. If the stricter witness fails at runtime, investigate source A1 fan topology and eligibility rather than accepting rejected diagnostics.

Continue the **same R4**: RA-43.1/43.4 source/consumer obligations, RA-47.12 runtime only in separately authorized TB, historical 39 endpoint/34 Phase10/7 DCEL/88 accepted CP2/six CP3 recoveries, organic D1/D2/D3/D5/A6/A7; prior RA-46.5/46.6 and RA-49/51 retirements retained, frozen 497 selector and ledger unchanged. No successor, no acceptance promotion.

---

## HISTORY — R4 paired odd-τ terminal identities and A1 vertex-germ seed compiled (2026-10-14 UTC)

Same canonical `M6-CP3-CB1-ENTRY-R4` **IN_PROGRESS Code + Build**; do not begin TB497 or successor. The existing genuine `ProducedNonconstantTwoCarrierOddTauSharesA1VertexGerm` test now requires the two A4 endpoint certificates to use **both distinct producer-published hard edges** (1,4)/(4,7), and requires every successful elected A1 germ audit seed to exactly match the actual typed junction, arrival face, branch, and arrival mode. This eliminates duplicate-terminal or unrelated-seed credit without changing the algorithm, test identity, frozen 497 selector or workflow. Exact semantic [9780154](https://github.com/akashskypatel/Directional/commit/9780154878a37b9792179b76c4bc7b39d5b2667c), test Git blob `6eb202471a421db6aa1ab32ff412cd5a7e82ed3b`, verified full-index source patch SHA-256 `78b288eed8989273a719bd16e052ecb4e3c8f7819206b354a0ad4768509879c1` backed up in Directional Library.

**Exact-source 8/8 GMP/GMPXX compile GREEN:** [run 38518554549](https://github.com/akashskypatel/Directional/actions/runs/38518554549), job `115702860045`, immutable artifact `11872792658` ZIP SHA-256 `4f62d313bad05bd32b70463beec3275c7d4c4bc447c33fd4565c8c3e83062da5`. Verified 28/28 SHA256SUMS, exits 0/0, both GMP libs, five clean source-status records, packaged test source blob exact, `runtimeExecution=false`. **No test/benchmark executed; this does not establish runtime odd-τ acceptance.** Durable record `.agents/Directional/Architecture_M6_CP3_R4_RA431_Paired_Endpoint_Germ_Seed_Source_Oracle_20261014.md`.

Remaining R4: actual odd-τ multi-carrier execution only in separately authorized artifact-only TB; broader RA-43.1/.4, RA-47.12 runtime liveness, historical 39/34/7/88/six restorations, organic D1/D2/D3/D5/A6/A7. Previous RA-46.5/.6 and RA-49/51 guards retained; frozen 497 and ledgers unchanged.

---

## HISTORY — R4 combined odd-τ A1 diagnostic directed-walk source proof (2026-10-14 UTC)

Canonical `M6-CP3-CB1-ENTRY-R4` stays **IN_PROGRESS Code + Build**, PR #8 draft/open; do not begin successor or TB497. Strengthened the existing `SurfaceCellPipelinePhase20.ProducedNonconstantTwoCarrierOddTauSharesA1VertexGerm` producer fixture's *evaluated failure diagnostic* path: each source edge must touch the actual junction, avoid A4 hard carriers, resolve to the next A1 typed source face with available **directed** A3 transport, and reproduce the diagnostic terminal source face, mod-4 signed lift and branch rotation. This closes a source-oracle loophole where an unrelated nonempty path could count toward the combined germ. No new test identity, algorithm, selector or workflow change. Semantic [853f2eb](https://github.com/akashskypatel/Directional/commit/853f2eb6d43bd23c866db3d9ceaaf5367b6b85ee), exact blob `89c6893b85158aea83ffeaf2b359ac3a24a41ce1`; verified exact-base patch SHA256 `4e1a1ae0fe14cad5309ad9de9bf22190b22e7e6f1851bb09e82aaff75c1dbbd7` preserved in Directional Library.

**Pinned eight-target GMP/GMPXX compile GREEN:** [run 38515990739](https://github.com/akashskypatel/Directional/actions/runs/38515990739), compile job `115694867401`, source `853f2eb6d43bd23c866db3d9ceaaf5367b6b85ee`, result artifact `11872335445` SHA256 `7bfc97f99490dfc1575e8fef5b3400ab1c39235eb1d6653229518b8712a585a3`; 28/28 hashes, 8 targets, exits 0/0, GMPXX+GMP, five clean status files, packaged test-source blob matched, `runtimeExecution=false`. **No runtime tests, no actual odd-τ PASS.** Evidence in `.agents/Directional/Architecture_M6_CP3_R4_RA431_Produced_OddTau_Multicarrier_Germ_20261014.md`.

Remain on the same R4: source/consumer RA-43.1/.4 work, executed RA-47.12 only in separately authorized artifact-only TB, historical 39 endpoint/34 Phase10/7 DCEL/88 CP2 accepted/six CP3 obligations, organic D1/D2/D3/D5/A6/A7. Maintain RA-49/51 retirements and existing RA-46.5/46.6; frozen selector 497 and historic counts unchanged. Never promote compile evidence to acceptance.

---

## HISTORY — R4 genuine nonconstant paired odd-τ carrier/A1 germ compiled (2026-10-14 UTC)

Canonical `M6-CP3-CB1-ENTRY-R4` **IN_PROGRESS Code + Build**, continue this turn only; PR #8 draft/open. A new source-authored positive in existing `tests/SurfaceCellREPackageTests.cpp`, `SurfaceCellPipelinePhase20.ProducedNonconstantTwoCarrierOddTauSharesA1VertexGerm`, requires the **same genuinely A4-produced two-edge midline rail** `(1,4),(4,7)` from a nonconstant quarter-turned source field to have odd (1/3) A1-authenticated carrier τ **and** an A1 vertex-star owner/nontrivial evaluated walk at the real junction vertex 4, using typed A1 hard-edge barriers. It is an independent combined source obligation, **not a runtime witness or accepted result**. Initial semantic [b640d51](https://github.com/akashskypatel/Directional/commit/b640d51a9e3369449ea4cc75ca5939754443740c) compile [38514059053](https://github.com/akashskypatel/Directional/actions/runs/38514059053) FAILED with ten `DomainResult` test-source dereference errors; corrected all ten to `.value()` in exact semantic [651da42](https://github.com/akashskypatel/Directional/commit/651da423b66645a2e1fc1962d04acc047eef8070). Corrected source blob `9c1e333c82d4cf5a45eaaa11a6c91d36bda509c2` verified against local work-preservation patch.

**Mandatory GMP/GMPXX eight-target compile GREEN:** [run 38514261408](https://github.com/akashskypatel/Directional/actions/runs/38514261408), compile job `115689475286`, pinned source `651da423b66645a2e1fc1962d04acc047eef8070`, result artifact `11871405217`, outer SHA256 `a2a0cac31d78944ad9f608ff5ec59f36c403753143afd9f374ad65c05b206837`; independently verified 28/28 manifest, all 8 targets, preflight/build 0/0, CMake GMP enabled, generated GMPXX+GMP link, five clean source-status records, artifact test-source blob match and `runtimeExecution=false`. Test/benchmark job skipped; **no runtime PASS**, no TB497, frozen-selector edit or successor. Exact owning evidence: `.agents/Directional/Architecture_M6_CP3_R4_RA431_Produced_OddTau_Multicarrier_Germ_20261014.md`. Corrected exact-base backup in Directional Library Evidence, full patch SHA256 `20534b4aaa8c0d7de13171bca10e7842908d890c0c6afb2f215fc27ac9c425f1`; first erroneous draft superseded.

**Still open for this same R4:** the combined fixture's actual runtime witness (only in separately authorized artifact-only TB); RA-43.1/.4 remaining source/consumer scope, RA-47.12 liveness, historical 39 endpoints/34 Phase10/seven DCEL/88 CP2 accepted/six CP3 recoveries and organic D1/D2/D3/D5/A6/A7; source-oracle compile does not close these. Existing RA-46.5/46.6, RA-49/51 retirements, frozen 497 and historical ledger remain intact.

---

## HISTORY — R4 genuine multi-carrier A1 vertex-germ compile-only checkpoint (2026-10-14 UTC)

Canonical `M6-CP3-CB1-ENTRY-R4` remains **IN_PROGRESS, Code + Build**; not TB497/successor. The real producer-generated two-hard-edge A4 junction fixture in `tests/SurfaceCellREPackageTests.cpp` now calls the A1 `resolve_field_vertex_transit` germ with atlas-owned hard-carrier pointers, reconstructs each diagnostic source-edge path and checks face-contiguous directed A3 signed lifts/branch rotations without crossing producer hard carriers, and requires a nonvacuous real germ owner or examined path. **This is an extended existing source oracle, not synthetic multi-carrier or odd-τ runtime success.** Source-only commit [49c5362](https://github.com/akashskypatel/Directional/commit/49c5362dd58365abdee05307b75e197bd0c071cf), exact one-file blob `38cf9c99fa1d6483230c254cf6f6c16fffd04a59`; patch SHA-256 `474b986927987842d79594ca468a75338a8083d864ccfb5abb10c0575d73a0f0` preserved in Directional Library Evidence.

**Pinned eight-target GMP/GMPXX compile GREEN:** [run 38512103184](https://github.com/akashskypatel/Directional/actions/runs/38512103184), semantic source `49c5362dd58365abdee05307b75e197bd0c071cf`, artifact `11870900442`, outer SHA-256 `5470facda992313db906817373c6ea353ba7a482161c46941d11f27801b0e7e0`; 28/28 package hashes, 8/8 targets, preflight/build 0/0, GMPXX+GMP on generated link, five clean source status records, `runtimeExecution=false`. No tests/benchmarks executed; **do not claim runtime PASS**. Durable evidence: `.agents/Directional/Architecture_M6_CP3_R4_RA431_Organic_Producer_Vertex_Germ_Code_Build_20261014.md`.

**Next same turn:** prove the real combined multi-carrier odd-τ case (not addressed here), continue RA-43.1/.4 organic source/consumer duties, RA-47.12 execution only in separately authorized TB, historical 39/34/7/88/six restorations and D1/D2/D3/D5/A6/A7. Avoid duplicate already compiled RA-46.5/46.6 source oracles; keep RA-49/51 retirements; frozen selector 497 and historical counts unchanged. PR #8 remains draft. Do not advance or run TB497.

---

## HISTORY — R4 open-rail component GMP compile and producer vertex-star callsite proof (2026-10-14 UTC)

Canonical `M6-CP3-CB1-ENTRY-R4` remains **IN_PROGRESS Code + Build**; continue this turn, not TB497/successor. Genuine two-file open-rail A4 first-consumer component check landed as semantic [`43e090c`](https://github.com/akashskypatel/Directional/commit/43e090ccb887a87c76f6242f498f78182103cee0) in Drive apply [38508173122](https://github.com/akashskypatel/Directional/actions/runs/38508173122). Pinned eight-target GMP/GMPXX compile **GREEN** in [38508335369](https://github.com/akashskypatel/Directional/actions/runs/38508335369), artifact `11869275592`, outer ZIP SHA-256 `6da4a5f47c2072e7f0d0216b517ed95299b8a19d5ccdff1d122a32a5dbd75ed2`: 28/28 package file hashes, eight targets, exits `0/0`, GMP/GMPXX linked, five clean source-status records, `runtimeExecution=false`. **Do not claim runtime PASS** for the new regression `ForeignOpenRailComponentRejectsAtFirstA4ConsumerPredicate`; no binaries/tests/benchmarks executed. Staging Drive file was owner-deleted. Evidence `.agents/Directional/Architecture_M6_CP3_R4_Open_Rail_Component_First_A4_Consumer_20261014.md`.

Fresh nonduplicative RA-43.1 static production-path census (source-verified against the same packaged exact source) at `.agents/Directional/Architecture_M6_CP3_R4_RA431_Production_Vertex_Star_Callsite_Census_20261014.md`: the `FieldAlignedCurveNetwork::make` producer builds `mandatoryByEdge` from typed A1 `nontraversable_edges()` and every four production `resolve_field_vertex_transit` invocations passes that authority pointer. The star loop cuts only `HardFeature` while retaining `SourceBoundary`; A1 itself excludes genuine hard carriers from traversable A3 `branch_topology().transports()` and keeps independent directed `transition_value` (already covered by prior compiled source tests). **This is reachability/authority wiring evidence only**, not an organic multi-carrier germ proof or runtime acceptance. Do not mint redundant fixtures. Existing RA-46.5 first-A4 negative source oracles and RA-46.6 typed factory distinctions remain compiled-but-unexecuted, not missing. No code, test, selector, workflow or build mutation in this census.

Still open: RA-43.1 real organic multi-carrier vertex germ and RA-43.4 diagnostic/global disposition, RA-47.12 executed liveness **only in separately authorized artifact-only TB**, historical 39 endpoint / 34 Phase10 / seven DCEL / 88 accepted CP2 losses / six CP3 positives, organic D1/D2/D3/D5/A6/A7 and genuine multi-carrier odd-τ. Frozen 497 unchanged; ledger 66/17/49, debt 1 remain historical/unmeasured. No TB497 or successor.

---

## HISTORY — R4 RA-46.5 / RA-43.4 nonduplicative source census (2026-10-14 UTC)

Same canonical `M6-CP3-CB1-ENTRY-R4` Code + Build IN_PROGRESS. Exact current snapshot `0326e9ac3091b3e1fa0ef62ea8224cc4d218e5e2` (run `38505236129`, `5827/5827` hashes). Static coverage census `.agents/Directional/Architecture_M6_CP3_R4_RA465_RA434_Static_Coverage_Census_20261014.md`: reachable first-A4-consumer negative source oracles for duplicated typed terminal contact, foreign source vertex, and missing terminal A3 path already exist; RA-46.6 typed factory disjunction already exists; RA-49/51 retirement applies to the other unrepresentable disjuncts under preserved guards. All three production rail interval callers explicitly require typed source and edge keys; standalone no-network legacy opt-out remains test-only. **Do not duplicate these compile-only fixtures or claim runtime PASS**. Remaining R4 work is the genuine nonduplicated RA-43.1/43.4 organic consumer/producer gap, runtime liveness/acceptance only in a separate TB, historical restoration, and multi-carrier odd-τ. No source change, build, runtime, TB497, or successor in this census.

---

## HISTORY — R4 produced nonhard A3 corrected compile GREEN (2026-10-14 UTC)

Canonical `M6-CP3-CB1-ENTRY-R4` remains **IN_PROGRESS** (Code + Build); successor is the same canonical R4, not TB497. FieldBranchTransportAdjacency member-name correction applied as [`524a029`](https://github.com/akashskypatel/Directional/commit/524a0291847e08c33f316c9db71fc90a002d58db), modifying only `tests/SurfaceCellsPhase10Tests.cpp`. Original compile [38501717039](https://github.com/akashskypatel/Directional/actions/runs/38501717039) failed for the diagnosed test-source fields; that run is **not** green. Replacement compile [38503341223](https://github.com/akashskypatel/Directional/actions/runs/38503341223) job `115655195706` passed against **exact source** `524a0291847e08c33f316c9db71fc90a002d58db`: eight approved targets, preflight/build exits `0/0`, generated GMPXX+GMP link, `DIRECTIONAL_ENABLE_GMP=ON`, `exactArithmeticBackend=GMP`, five clean source-status files, `28/28` artifact SHA-256 checks, and `runtimeExecution=false`. Result artifact `11866374487`, outer SHA-256 `54b349c04dc818f2ac6e6a1b4d31f6335da8393a11be46551b5866bada93d9df`; mailbox `m6-cp3-r4-nonhard-a3-fixed-compile`. No tests/benchmarks run.

The first three-path handoff documentation apply [38502155929](https://github.com/akashskypatel/Directional/actions/runs/38502155929) failed due to a comma-delimited `intended_paths` header; patch contents and SHA verified, but workflow safely rejected the path set and did not push. Semicolon-delimited metadata correction (same diff body SHA-256 `82d21dbc361d2ebae072d1d4d7068546f41b2517c9a799bf021e0e8303ed1b53`) applied successfully in [38503603309](https://github.com/akashskypatel/Directional/actions/runs/38503603309), result artifact `11867465022`, outer SHA-256 `0593689288aba61bda3df32549e3a7592a7522f32f1cd9e0225eb4d08b324dd9`, repository commit [`3fc782f`](https://github.com/akashskypatel/Directional/commit/3fc782fc794f7468e8af3e0b0dfa0215d279d640); both prior failed and successful Drive staging files owner-deleted. Independent diff confirms exactly TODO, handoff and owning record modified. This section supersedes any older `PENDING` text below.

Outstanding: broader RA-43.1/43.4 source coverage, reachable RA-46.5 first-rejection, RA-47.12 runtime liveness, historical 39/34/7/88/six restoration, organic D1/D2/D3/D5/A6/A7, and true multi-carrier odd-τ. All source-authored regressions remain runtime-unexecuted. No frozen-selector edit, TB497, or successor work.

---

## HISTORY — R4 producer nonhard directed A3 parity checkpoint (2026-10-14 UTC)

`M6-CP3-CB1-ENTRY-R4` Code + Build **IN_PROGRESS**, no successor. Source/test-only RA-43.1 producer differential now asserts that every genuine nonhard traversable atlas link retains the same two directed A3 values as `transition_value`, including reciprocal quarter-turn, signed lift and effort; hard carrier values remain nontraversable. Semantic commit [`3a461b7`](https://github.com/akashskypatel/Directional/commit/3a461b747579220cfac6b15049f6cab70b89f1eb), verified single test-source path. Source snapshot [38500983174](https://github.com/akashskypatel/Directional/actions/runs/38500983174), 5810/5810 SHA-256 file checks. Patch SHA-256 `5c1afff29783cf0d3621cd9b8f28a2ffeaecb8924639cc6d9c9563bb9655447c`, Drive apply [38501554940](https://github.com/akashskypatel/Directional/actions/runs/38501554940), staging retired. **FIRST PINNED COMPILE FAILED**: workflow 38501717039, compile job 115650065161, source 3a461b747579220cfac6b15049f6cab70b89f1eb, diagnostic artifact 11866206890 (SHA-256 36914a8fd1d69af77d0a7f6a9117a7e95cd0d929372f53444c700db4cf9c8546). Diagnosed test-source field-name mismatch: FieldBranchTransportAdjacency exposes firstFace/secondFace/forward/forwardLift, not FieldTransportStep fields. Bounded fix patch cc31065f8d97c56e0a21dfb28d20a95bdc0c07b210bec314309c07d16114af94 exact-base 3a461b7, forward/reverse/whitespace verified, staged in Drive and dispatched via 8185292a15352ca38691409f9d4fd1e2501bc8df to m6-cp3-r4-nonhard-a3-fix-apply. Subsequent fix applied as 524a029; replacement compile was later verified GREEN by run 38503341223 (see superseding checkpoint above); runtime still not executed.

Tests and runtime gates **not executed**. RA-43.1/43.4 global, RA-46.5, RA-47.12 runtime, historical 39/34/7/88/six, organic D1/D2/D3/D5/A6/A7 and real odd-τ multi-carrier remain open. No TB497, frozen selector or successor.

---

## HISTORY — R4 A1 directed nontraversable row-order regression (2026-10-14 UTC)

Same canonical `M6-CP3-CB1-ENTRY-R4` Code + Build **IN_PROGRESS**. Existing A1 hard-feature/non-hard seam regression now compares exact directed `QuarterTurn` and signed lift under source-face row order swap with branch gauges anchored to physical face IDs; ordinary traversable adjacency stays absent. One-test-source change, no production or frozen selector change. Verified patch SHA-256 `8b67e67f48d01d7c48912b357d4178ed35da1eb5eb767735f84935798803df95`; full result at `Architecture_M6_CP3_R4_RA431_Directed_Seam_Row_Permutation_20261014.md`. Source patch applied `7e8f7cd`; pinned eight-target GMP/GMPXX compile **GREEN**, run `38497529587` / artifact `11864830175` SHA-256 `cedb6cbe6716fe1ff7517b76e022ccaed8a2ee0ef9fcddd5f780b588c843b324`, 28/28 checksums, 8/8 targets, preflight/build `0/0`, GMPXX/GMP, five clean source-status records, `runtimeExecution=false`. All assertions remain runtime-unexecuted; no TB497 or successor. Other RA-43.1/.4, RA-46.5, RA-47.12, 39/34/7/88/six, organic and real multi-carrier odd-τ obligations remain open.

---

## HISTORY — R4 RA-43.4 source census + replacement pinned compile GREEN (2026-10-14 UTC)

Same canonical `M6-CP3-CB1-ENTRY-R4`, Code + Build, **IN_PROGRESS**; no review blocker or successor. Source snapshot `13df05220f84cba35923855ec50d8aa6c7a6d088`, workflow [38492441978](https://github.com/akashskypatel/Directional/actions/runs/38492441978), immutable artifact `11862018574`, outer SHA-256 `a58b3e902b224a7bffb15598cfe399df64cd5b5b9a5588e3a7bf7f15f782c3d6`, **5789/5789** source-file SHA-256 checks and inner archive valid. Static RA-43.4 census: all three production `rail_interval_refs` callers explicitly require typed source; the exact-barycentric fallback remains only the named no-network standalone diagnostic, and network presence overrides that opt-out. Evidence `.agents/Directional/Architecture_M6_CP3_R4_RA434_Static_Ingress_Census_20261014.md` (commit `bdc3e8d66d8721937e026f47df4176fda7650532`). No runtime credit.

The **older** closed-rail compile request at `608c5338f4a04a3ba3194a7e11ec7956e482c793` has no verified result in its mailbox; **do not call that attempt green**. Its unchanged source implementation and the added documentation have been superseded for compilation by a **new pinned source**: dispatcher `463f39802154c518a55a0b23e019f9a910473f62`, compile run [38492719549](https://github.com/akashskypatel/Directional/actions/runs/38492719549), job `115621564151`, package artifact `11862361115`, outer SHA-256 `cf966f536d22b6b88afb11684fe04f11e5a53336ba33b660a67d32d323f9d003`; exact source `13df05220f84cba35923855ec50d8aa6c7a6d088`. Verified **28/28** artifact manifest hashes; all eight GMP/GMPXX targets, preflight/build `0/0`, generated link with `libgmpxx.so` + `libgmp.so`, `DIRECTIONAL_ENABLE_GMP=ON`, `exactArithmeticBackend=GMP`, five empty source-status checkpoints, `runtimeExecution=false`. Test/benchmark job skipped. The closed-rail component first-consumer guard and its differential fixture are **compiled, not executed**. No TB497, no selector change, no acceptance promotion.

**Open:** RA-43.1 live consumer/source-germ work; non-static RA-43.4 proof/legacy diagnostic gates where applicable; other reachable RA-46.5 first rejections; RA-47.12 runtime liveness (only in a separately authorized TB turn); historical 39 endpoint / 34 Phase10 / seven DCEL / 88 accepted CP2 restorations / six CP3 positives; organic D1/D2/D3/D5 and A6/A7; genuine multi-carrier odd-τ. Do not advance to successor.

---

## HISTORY — R4 closed-rail source-component authority (2026-10-14 UTC)

- [x] Same canonical `M6-CP3-CB1-ENTRY-R4` Code + Build. First A4 consumer now checks the contact-free closed chain's claimed component against **both** authentic source attachment components before granting a cyclic bypass; a differential Phase10 negative changes only the claimed component, contrasting against the same endpoint-owning chain with real component. Exact two-file patch SHA-256 `5afc476876a1517b797af1627cee7bbbebd8b618fb3ceb59339446d49665519c`, apply commit `62fec4a7f4ccf05a6fe8bc14f81d4b8ff774d809`, dispatcher [38488410002](https://github.com/akashskypatel/Directional/actions/runs/38488410002), matching receipt verified; transient staging file retired.
- [ ] Pinned eight-target GMP/GMPXX compile request at dispatcher commit `608c5338f4a04a3ba3194a7e11ec7956e482c793`, exact semantic source `62fec4a7f4ccf05a6fe8bc14f81d4b8ff774d809`, mailbox `m6-cp3-r4-closedrail-component-compile`: **PENDING**; do not claim GREEN/RED until the immutable compile artifact and source/link evidence are verified. Code + Build only; no executable/test/benchmark run, no TB497, no runtime PASS, no frozen-selector or downstream factory changes. All open R4 historical/organic, RA-43.1/.4, RA-47.12 and genuine odd-τ multi-carrier duties carry forward. The older WIP subsection below is historical and superseded by this applied checkpoint.

---

## HISTORY — RA-51 terminal-A3 reachability resolved; R4 Code + Build resumes (2026-10-13 UTC)

- [x] The independent RA-51 Review **discharged** `R4-TA3-01`: `missing-or-nonreciprocal-terminal-A3` is unreachable under H1–H6 and `overlapping-terminal-sectors` is unreachable under K1–K5. Both fixture obligations are **RETIRED**, their runtime fail-closed guards **retained**. RA-48.3 already landed; its unconditional topology derivation keeps R4-OVF-01 **closed**. Authority: `Architecture_M6_CP3_R4_Terminal_A3_First_Rejection_Review_Decision.md` and frozen `Architecture_M6_Frozen_Definitions.md` RA-51. Do not resurrect these negatives without a broken guard premise or mint dead-disjunct typed sub-codes (RA-51.7).
- [x] The most recent RA-43.1 source-star continuity oracle in `tests/SurfaceCellREPackageTests.cpp` is **compiled only**, exact source `2e27e52e72e6325fa980bbf531a3f0d6b3bafc4a`, pinned eight-target GMP/GMPXX compile workflow `38444070795` (28/28 packaged hashes, 8/8 targets, no runtime). This is not a PASS or completed RA-43.1 proof. See `Architecture_M6_CP3_R4_RA431_Produced_Hard_Barrier_Authority_Oracle_20261013.md`.
- [ ] Continue canonical `M6-CP3-CB1-ENTRY-R4` **IN_PROGRESS** Code + Build: remaining RA-43.1 live consumer/germ and RA-43.4 global diagnostic disposition, reachable RA-46.5 first rejections (including `ambiguous-terminal-contact`), RA-47.12 executed liveness, 39 endpoint / 34 Phase10 / seven DCEL / 88 accepted CP2 restorations / six CP3 positives, and genuine odd-τ multi-carrier witnesses. Preserve frozen 497 selector and prior baselines; do **not** execute tests/benchmarks or begin TB497/successor in Code + Build.

---

## HISTORICAL — R4-TA3-01 superseded independent REVIEW STOP (2026-10-13 UTC)

- [x] The earlier request to review `missing-or-nonreciprocal-terminal-A3` was **resolved by RA-51**; the provisional assertion that a public-ingress exception might revive this fixture is superseded. Original review-stop request remains at `Architecture_M6_CP3_R4_RA465_Terminal_A3_First_Rejection_Review_Stop_20261013.md` as historical evidence, not an active blocker. Do not reopen without evidence breaking H1–H6 or K1–K5.
- [x] Prior R4 RA-43.1 admissible non-hard transport test applied and eight-target GMP compile GREEN at semantic `32eff2943d4c3c8d2183f5a51439d33dc3c84ae1`, run `38405627436`, artifact `11818707033` (28/28 checksums, no runtime). No production runtime acceptance; all prior recovery obligations retained.

---

## HISTORY — R4 RA-43.1 real A1 hard-barrier production compile GREEN (2026-10-13 UTC)

- [x] Applied at `cf87a8e10d3a390efbdc748c23388ae0da7965c4` by `38392849958`, eight-target GMP/GMPXX compile GREEN `38393072606` (artifact `11809223261`, SHA256 `1b06fe10a15ce5134bd7744436adaab6cc3beb0151812ee330ba8b028082503d`, 28/28 hashes, no runtime), source regression `ProducedHardCarriersAreAtlasBarriersNotSourceBoundaryTransit`; source barrier origin is genuine atlas output, not test-labelled. Evidence `Architecture_M6_CP3_R4_RA431_Produced_Hard_Barrier_Authority_Oracle_20261013.md`.
- [ ] Runtime proof and full A1 consumer/germ, RA-43.1/.4, RA-46.5, RA-47.12, 39/34/7/88/six and genuine odd-tau multi-carrier remain open. No TB497 or successor.

---

## HISTORY — R4 RA-43.1 producer barrier authority source oracle (2026-10-13 UTC)

- [ ] Apply and compile-only verify `SurfaceCellAuthorityContractCutover.ProducedHardCarriersAreAtlasBarriersNotSourceBoundaryTransit` against verified source `45d09820b25f4330bad825cee1e5a1349d9fc0c1` (5668/5668 hashes). It checks unmodified A1 producer hard/barrier kinds, full typed key set, exclusion of hard A3 traversals, and mandatory A2a rail ID ownership; distinct from test-labelled RA-43.1 star filter. No runtime or TB497 in Code + Build. See `Architecture_M6_CP3_R4_RA431_Produced_Hard_Barrier_Authority_Oracle_20261013.md`.
- [ ] RA-43.1/.4 broader producer/consumer evidence, RA-46.5, RA-47.12 executed liveness, 39/34/7/88/six historical cases and real odd-tau multi-carrier remain open. RA-50 discharges RA-43.2.

---

## HISTORY — R4 RA-47.12 no-injection pipeline source oracle compiled (2026-10-13 UTC)

- [x] Applied at `3b8b14e31f7546eb59f71fa9c1b3617b83ed59c7` in `38390007877`; eight-target GMP/GMPXX compile GREEN `38390222662` (artifact `11808227197`, SHA-256 `a02f07389274950cdcd20ebc7e9d2ae63445956cda9a6d1aabb7807ce4ad1530`, 28/28 manifest). Source test only; **no runtime execution**. See `Architecture_M6_CP3_R4_RA4712_Uninjected_Pipeline_Rail_Liveness_Source_Oracle_20261013.md`.
- [ ] RA-47.12 actual uninjected runtime liveness, RA-43.1/.4, RA-46.5, historical 39/34/7/88/six and organic multi-carrier/odd-tau still open. No TB497 or successor.

---

## HISTORY — RA-47.12 default-path liveness source coverage (2026-10-13 UTC)

- [ ] Apply and compile-only verify `DefaultPipelinePublishesSourceBoundMandatoryRailKeysWithoutInjection` against exact verified source `f1dbd6c6ddeb60c3c74b0a40862fd26340d7b4b5`; positive requires actual uninjected pipeline publishing producer-matched typed hard rail keys `(1,4)` and `(4,7)` through the field-aligned network. This is an **unexecuted** source oracle. No TB497 or runtime tests in Code + Build. Evidence plan `Architecture_M6_CP3_R4_RA4712_Uninjected_Pipeline_Rail_Liveness_Source_Oracle_20261013.md`.
- [ ] RA-47.12 executed liveness and remaining R4 RA-43.1/.4, RA-46.5, 39/34/7/88/six and genuine odd-tau multi-carrier remain open; RA-50 discharged RA-43.2.

---

## HISTORY — R4 RA-43.1 borrowed barrier differential regression (2026-10-13 UTC)

- [x] Applied at `3bb0733267a18e151866a3f25e388a173b56f8b4` (workflow `38387022153`) and eight-target GMP/GMPXX compile GREEN `38387271419` (artifact `11806403200`, 28/28 checksums; no runtime). Compile-only verify new `ResolvedBranchCorrection.HardCarrierStarCutPreservesBoundaryTransit` on the exact applied source. Test category labels distinguish hard-carrier cut from boundary traversal over identical real A1 topology transports; they are diagnostic, not A1 producer attestations. Runtime/TB497 forbidden within CB. Evidence: `Architecture_M6_CP3_R4_RA431_Borrowed_Barrier_Differential_Oracle_20261013.md`.
- [ ] R4's other source/producer authority, RA-43.4/46.5, RA-47.12 liveness, historical 39/34/7/88/six and genuine odd-tau multi-carrier remain. RA-50 discharges RA-43.2. No successor.

---

## HISTORY — R4 RA-47.7 component aggregation typed-key equality oracle (2026-10-13 UTC)

- [x] Applied the source-exact independent-component/aggregated typed `sourceEdges` equality oracle at `007585f8eac57a74e89e62a416a844e21c15fe35` (Drive workflow `38383973192`); mandatory eight-target GMP/GMPXX compile GREEN `38384224673`, immutable artifact `11805220540` SHA-256 `e564eed3ea3636f1b36262dc91c29e9a65af6c229efc74e58d7935da0c07ddca`, 28/28 manifest and no runtime. Prior transport blocker cleared, Drive file retired. Evidence `Architecture_M6_CP3_R4_RA477_Component_Aggregation_Independent_Rail_Key_Oracle_20261013.md`. **Unexecuted source oracle, not runtime PASS.**
- [ ] Remain within canonical R4; RA-47.12 executed producer liveness, RA-43.1/.4, RA-46.5, 39/34/7/88/six, odd-τ multi-carrier and separate artifact-only TB remain open. Frozen 497 selector unchanged; no successor.

---

## HISTORY — R4 RA-47.10 ordinal-discriminating producer positive (2026-10-13 UTC)

- [x] Applied the one-test ordinal-discriminating positive at `1ee05785c9f35d60d7dc2264f92bccb0fe423b24` (workflow `38373640827`); mandatory eight-target GMP/GMPXX compile GREEN run `38373896079`, 28/28 artifact hashes and runtime disabled. See `Architecture_M6_CP3_R4_RA4710_Lexical_DCEL_Positive_Code_Build_Record_20261013.md`. This is not a runtime PASS.
- [ ] R4 remains unfinished: RA-43.1/.4, RA-46.5, RA-47.12 executed liveness, RA-47.10 component-decomposed equality, historical 39/34/7/88/six and odd-τ genuine multi-carrier. No Test + Benchmark, no TB497 or successor; RA-50 discharges RA-43.2.

---

## HISTORY — R4 RA-46.5 A4 missing terminal A3 consumer oracle (2026-10-13 UTC)

- [x] Applied at `d6240c9bc2d59899829ec259e9babd2878736e50` and compile-only verified in `38370592790` (28/28 hashes, all 8 GMP/GMPXX targets, no runtime) the new Phase10 source test `MissingTerminalA3PathRejectsAtFirstA4ConsumerPredicate`: choose a genuinely produced non-hard A3 terminal step, block only that step in replay, require consumer `EndpointAttachment` and `a2bProbeFailure=missing-terminal-A3-path`. Existing checked-factory `MissingTerminalA3Path` is a separate later-stage oracle and cannot satisfy this coverage. No test runtime, TB497, selector change or successor. Evidence: `Architecture_M6_CP3_R4_RA465_A4_Missing_Terminal_A3_Consumer_Oracle_20261013.md`.
- [ ] R4 RA-43.1/.4, RA-46.5 other consumer negatives, RA-47.12 executed liveness, historical 39/34/7/88/six and odd-τ multi-carrier obligations remain. RA-43.2 discharged under RA-50.

---

## HISTORY — R4 public strict trace foreign-key compile verified (2026-10-13 UTC)

- [x] Verified and applied published present/in-range foreign `sourceEdges` negative at public `trace_surface_field` entry, exact source `f5c0d0b325ecf7333abbd3573759ed09a011ea3e`, Drive apply `38366995891`. Mandatory compile-only GMP/GMPXX run `38367436364` GREEN, artifact `11796334785`, SHA-256 `1a56a2ee7fee179e9c5c251e5d68560fb3e714364f8b89084b6ec39707b40f19`, internal 28/28, 8/8 compiled, exit 0/0, GMPXX/GMP generated linkage, five clean source status files, runtime disabled. Initial request rejected targets string before compile; corrected array executed successfully. See `Architecture_M6_CP3_R4_Public_Trace_Foreign_Edge_Oracle_Compile_Record_20261013.md`.
- [ ] Continue same canonical R4 Code + Build. RA-43.1/.4 global, RA-46.5, RA-47.12 executed liveness, historical 39 endpoint / 34 Phase10 / 7 DCEL / 88 accepted restoration / six CP3 and true odd-τ multi-carrier remain open. RA-43.2 discharged by RA-50; no fabricated filled-side owner. No TB497, no runtime acceptance, no successor.

---

## HISTORY — R4 strict trace public-entry foreign published edge key (2026-10-13 UTC)

- [ ] Test-only, unexecuted extension to `SurfaceCellTracingPhase14.ProducedRailEndpointsRequireExactSourceVertexIncidence`: preserve the valid public trace baseline and missing-key negative; additionally replace only the published key with a distinct in-range source key `(1,4)` and require `FieldMetadata` at `trace_surface_field` strict no-network entry. Lower-level foreign-key check already exists, but is not equivalent to public ingress coverage. Patch authored against verified snapshot `45d210e51a12dd3b8416c5179e6737edbb53e4e3` (snapshot workflow `38359143085`, 5612/5612 checksums). Code + Build source compilation and immutable evidence remain pending; do not claim runtime acceptance, start TB497 or successor. Same canonical `M6-CP3-CB1-ENTRY-R4`.

---

## HISTORY — R4 RA-43.4 strict no-network default tracing ingress (2026-10-13 UTC)

- [x] Applied and compile-only verified the typed rail positive and missing-published-key negative in existing Phase14 `trace_surface_field` entry (semantic `f1fbf8561d3d6d77f6807d0178263fa0a9ba11ef`, compile GREEN `38357644503`, 28/28 hashes, 8/8 targets, generated GMPXX/GMP, no runtime). Exact snapshot `fc22e74ec72570d401a14f7146cda8a8a82ffaec` (run `38356618714`), source-only oracle. Apply and compile eight GMP/GMPXX targets through durable Actions; no runtime test/benchmark, no TB497. Scope and non-vacuity: `Architecture_M6_CP3_R4_RA434_Strict_Trace_Entry_Missing_Edge_Oracle_20261013.md`.
- [ ] R4 remains IN_PROGRESS: RA-43.1/.4 global, RA-46.5, RA-47.12 runtime liveness, historical 39/34/7/88/six and genuine odd-τ multi-carrier remain open. RA-43.2 discharged under RA-50.

---

## HISTORY — R4 RA-43.4 strict no-network published-edge key migration (2026-10-13 UTC)

- [x] Applied at `52389f6749e90e9fdc9c9f2b711ea0c339e323ca` and exact eight-target GMP/GMPXX compile GREEN in `38355543522` (28/28 package checksums, 8/8 targets, GMPXX/GMP link, runtime disabled) the `rail_interval_refs` default strict no-network producer edge-list requirement plus Phase14 / REPackage authored typed source-edge fixture migration, preserving first-rejection predicates and named no-network diagnostic mode. Frozen selector unchanged; no executable/test/benchmark run. Inspect `Architecture_M6_CP3_R4_RA434_Strict_NoNetwork_Published_Edge_Keys_Code_Build_Record_20261013.md` for exact snapshot/patch/authority. Update compile evidence only after verifying immutable package.
- [ ] R4 remains IN_PROGRESS: RA-43.1/43.4 global, RA-46.5 first rejections, RA-47.12 executed liveness, historical 39/34/7/88/six and odd-τ multi-carrier remain open. No TB497 or successor.

---

## HISTORY — R4 RA-43.4 network-bound foreign published edge key (2026-10-13 UTC)

- [x] Applied and compile-only verified the test-source oracle extending `StandaloneRailDiagnosticModeCannotBypassProducedNetworkTypedIngress` to reject a present but *wrong* producer source-edge key at the `rail_interval_refs` consumer. This is distinct from the existing network **factory** forged-key oracle; requires producer-backed full-network positive, real alternate feature-edge key, wrong-key `TypedAuthorityMismatch` and correct failing rail ID. Applied source `91e5c2a` (Drive `38352833746`), eight-target GMP/GMPXX compile GREEN `38352976015` (artifact `11791682503`, ZIP SHA-256 `c449ccb818e42882106186afdae2066b3c1e7e591e454b4e62906617eaa7d764`, 28/28 hashes, 8/8 targets, exit 0/0, gmpxx/gmp linkage, clean source, no runtime). Exact snapshot `a2e63a6`, workflow `38352281752`, 5585/5585 file hashes; see `Architecture_M6_CP3_R4_RA434_Consumer_Foreign_Edge_Key_Regression_20261013.md`. No runtime, selectors or TB497.
- [ ] Separately migrate remaining standalone Phase14 strict no-network typed vertex fixtures before globally requiring published `sourceEdges` at no-network helper ingress. Do not incorrectly claim previous network-bound cardinality guard closed this seam. RA-50 prohibits upstream filled-side receipt; R4 still carries remaining RA-43/46/47 and historical/multi-carrier gates.

---

## HISTORY — R4 RA-43.4 network-bound missing typed edge-key check (2026-10-13 UTC)

- [x] Applied the source-exact `rail_interval_refs` network-bound published-edge key cardinality guard and Phase10 positive/negative (same test identity) at `c11eb6f4aac75676f864c84aed501dcd38d2aeb6`; eight-target GMP/GMPXX compile **GREEN** workflow `38350909779`, artifact `11790937173` SHA-256 `959cab5897c43900d4ec3986ecb4e6b75a74d06401be6eddd0ab24bf23660b36`, 28/28 hashes, exits 0/0, clean source and runtime disabled. The missing-key rejection must occur even in named legacy diagnostic mode when a real network exists; the source-only no-network diagnostic stays unchanged. Record: `Architecture_M6_CP3_R4_RA434_Network_Bound_Typed_Rail_Edge_Key_Code_Build_Record_20261013.md`; snapshot `ea25856980b5ac8b8ddd643151c31affb1ea785b`, 5576/5576 checksums. No runtime or TB497.
- [ ] Continue R4 RA-43.1/.4 global, RA-46.5, RA-47.12 executed, historical 39/34/7/88/six and odd-τ multi-carrier gates. RA-50 discharges RA-43.2 and forbids invented filled-side receipts.

---

## HISTORY — R4-SID-01 corrected A5 GMP compile verified (2026-10-13 UTC)

- [x] Source `b836329e540ddaca5a7e4d233a6c0a99f574fd85` compiled on all eight required GMP/GMPXX targets in workflow `38348617454`, artifact `11790165302`, SHA-256 `8542f0118b4f85cbaa8da3ae94c4b125421da234fdf8e7dc401206bcbbcc1a3b`. Verified 28/28 artifact SHA256SUMS, 8/8 targets, preflight/build 0/0, actual GMPXX/GMP link, clean source and `runtimeExecution=false`. This resolves the previous connector dispatch issue and corrects the earlier A5 test-only compiler error; see `Architecture_M6_CP3_R4_SID01_A5_Selected_Face_Pin_Code_Build_Record_20261013.md`.
- [ ] Runtime A4 acceptance/A5 `HardRailRouteAuthorityInvalid` rejection has **not** been tested. The A4 side-swap test is likewise compile-only. Continue same R4 Code + Build; preserve RA-50 side-authority scope, the frozen 497-selector/TB boundary, remaining producer/rejection/historical/odd-τ gates. **No TB497 or successor.**

---

## HISTORY — R4-SID-01 A5 selected-face pin (2026-10-13 UTC)

- [ ] Apply and compile-only verify `M6CP3.A5RejectsSourceEquivalentHardRailSelectedFaceRechart` against exact source `9c126c1a9d814c39742bd63acbf9dbac3261a0da` (snapshot workflow `38340642958`, 5,561/5,561 hashes). It recharts only one produced hard-rail cell corner to a distinct same-region/sheet source face carrying the same intrinsic point, requires checked A4 acceptance and A5 `HardRailRouteAuthorityInvalid` rejection with self-inverse τ. Runtime tests deferred; no TB497.
- [ ] R4-SID-01 A4 and A5 test sources are separate checks; both remain unexecuted. RA-43.2 discharged; do not invent upstream filled-side receipts. Preserve remaining R4 gates, full 497 selector freeze and independent Review decisions. See `Architecture_M6_CP3_R4_SID01_A5_Selected_Face_Pin_Code_Build_Record_20261013.md`.

## HISTORY — R4-SID-01 load-bearing A4 trace-to-certificate side pin (2026-10-13 UTC)

- [ ] Apply the source-only `M6CP3.CheckedA4RejectsGlobalHardRailSideSwapWithSelfInverseTau` test from verified snapshot `2ddf6fa143f61335fbfba511943d5e9cdde3dbe6`, record exact Drive dispatcher semantics and compile the standard eight GMP/GMPXX targets. The test uses real produced τ=0/2 certificates and swaps both sides without changing composed transport; checked A4 must reject the trace-attachment mismatch. **No execution or TB497 during Code + Build.** See `Architecture_M6_CP3_R4_SID01_SelfInverse_Side_Pin_Code_Build_Record_20261013.md`.
- [ ] Independently protect the distinct A5 selected-face pin in later evidence; do not claim this A4 negative verifies it. Preserve RA-50's RA-43.2 discharge and prohibition on invented upstream filled-side authority. All remaining R4 production/first-rejection/historical gates stay open.

## HISTORY — RA-47.11 test EV-row census verified (2026-10-13 UTC)

- [x] Classified all five remaining `source_edge_index` test call sites (six textual uses including definition) as legitimate typed-key → DCEL `EV` row lookups for `EF`, indexed transition diagnostics or real topology membership; none republishes an EV index as `SurfaceCellRail::sourceEdges`. See `Architecture_M6_CP3_R4_RA4711_Test_EV_Row_Disposition_20261013.md`.
- [x] RA-43.2 is DISCHARGED by RA-50; the suggested new source-authored filled-cell/side receipt is REFUSED and must not be implemented. The earlier RA-43.2 open item below is superseded by RA-50.
- [ ] R4 Code + Build still requires independently scoped RA-43.1/.4, RA-46.5, RA-47.12 and historical/odd-τ gates. No TB497 or Test + Benchmark execution is authorized here; static census is not runtime PASS.

## HISTORY — R4 RA-43.2 source-owner design gate (2026-10-13 UTC)

- [ ] Independently resolve which producer binds `(rail, terminal, oriented source-face germ, filled-side owner)` before A4 uses trace rows. Triangle winding plus ordered rail edges can supply source carrier-side ordering but **not the independent A4 filled-side owner mapping**. See `Architecture_M6_CP3_R4_RA432_Oriented_Germ_Producer_Boundary_Review_Request_20261013.md`; do not accept trace-face/self-certified A4 evidence as producer authority.
- [ ] Distinguish the already authored **factory** `MissingTerminalA3Path` tamper oracle from the still-open **A4 consumer first-rejection** `missing-terminal-A3-path` obligation; avoid duplicating or double-counting. `overlapping-terminal-sectors` and `missing-or-nonreciprocal-terminal-A3` feasibility remains unadjudicated.
- [ ] R4 still carries RA-43.4 diagnostic retirement, RA-46.5, RA-47.12 runtime, 39/34/7/88/six and odd-tau multi-carrier. No TB497 or successor.

## HISTORY — R4 RA-43.4 compile-only network override checkpoint (2026-10-13 UTC)

- [x] Apply producer-backed typed-network override regression at semantic `f08770f004404f46356cc6fac59882aae5508849` through Drive workflow `38329088933`; consumed Drive stage deleted, source and test identity preserved.
- [x] Pinned eight-target GMP/GMPXX compile GREEN workflow `38329228942`, artifact `11781824492`, ZIP SHA-256 `e76c87f5ecd5285192785278e5fdb8a9be3ae79ca7e4317e43f029df9372f486`; 28/28 hashes, 8/8 targets, preflight/build 0/0, GMPXX/GMP linkage, clean source, `runtimeExecution=false`.
- [ ] Do not claim runtime PASS. Global RA-43.4 legacy exception disposition, RA-43.2 oriented terminal-side authority, remaining RA-46.5 and RA-47.12 executed liveness, historical 39/34/7/88/six and true odd-τ multi-carrier remain open. R4 continues; TB497 forbidden.

## HISTORY — R4 RA-43.4 verified compile / mandatory typed network override (2026-10-13)

- [x] Exact source `40f3e7a8307bd0626e99318e3a295caa3978cd37` named-mode migration compiled GREEN, workflow `38327322520`, artifact `11781461538`, ZIP SHA-256 `995f98408d7d465b400051cf5626992481aee132d9fdd4dcf93406bb3f7a7e22`, 28/28 hashes, eight targets, GMPXX/GMP, clean source, `runtimeExecution=false`.
- [ ] Apply and compile-check the new producer-backed Phase10 trust-boundary regression: explicitly named standalone diagnostic accepts geometrically valid untyped rail only with no network; default strict and actual producer A2a network both reject `TypedAuthorityMismatch`. No test execution or TB497 in current turn. Owning record: `Architecture_M6_CP3_R4_RA434_Explicit_Standalone_Diagnostic_Optout_Code_Build_Record_20261013.md`.
- [ ] Continue RA-43.2 independently oriented terminal-side producer, global RA-43.4 legacy disposition, remaining RA-46.5 and RA-47.12 runtime, historical 39/34/7/88/six, odd-τ multi-carrier. No successor until formal complete.

## HISTORY — R4 RA-43.4 explicitly named standalone diagnostic exception (2026-10-13)

- [ ] Apply/compile-source-check the exact-base `RailIntervalAuthorityMode` migration in `rail_interval_refs`: strict typed default, explicit standalone diagnostic-only opt-out, network still forbids untyped ingress. No test/benchmark execution; this is not global legacy retirement. See `Architecture_M6_CP3_R4_RA434_Explicit_Standalone_Diagnostic_Optout_Code_Build_Record_20261013.md`.
- [ ] R4 oriented producer-side binding and remaining RA-43.4/46.5/47.12/historical/odd-τ gates remain open. No TB497.

## HISTORY — R4 RA-43.2 missing open-rail provenance compile receipt (2026-10-13 UTC)

- [x] Source-only first-consumer missing-contact negative applied `03b712e660d2bfd0dd8114a158158540a7808a4e` and compiled via workflow `38324952482`, artifact `11781035489`, SHA-256 `4251a424b3371eb0ada98c1e43fd2357199cb943ce3637060ba2bf1a0d4e41a9` (28/28 packaged hashes; 8/8 requested targets; preflight/build exits 0/0; GMP/GMPXX linker; five source-status files clean; exactArithmeticBackend=GMP; runtimeExecution=false); no test runtime.
- [ ] Producer-authored oriented side occurrence still unimplemented; remaining RA-43.4/46.5/47.12 and frozen R4 historical/multi-carrier gates open; do not start TB497. Owning evidence record: `Architecture_M6_CP3_R4_RA432_Open_Terminal_Contact_First_Rejection_Code_Build_Record_20261012.md`.

## HISTORY — R4 open-rail terminal provenance first rejection (2026-10-12)

- [ ] Verify source-exact RA-43.2/RA-46.5 missing-open-contact first-rejection negative at compile only. No runtime acceptance. Source snapshot `4a68d108a592126a9443ae8644c2fcab2df6d181`, 6574/6574 hashes. New `MissingOpenRailTerminalContactRejectsBeforeClosedRailFallback` uses produced source-authenticated open rail, removes only the selected terminal contact, and requires consumer `missing-terminal-or-closed-rail-provenance`. Evidence: `Architecture_M6_CP3_R4_RA432_Open_Terminal_Contact_First_Rejection_Code_Build_Record_20261012.md`. Oriented producer side-binding RA-43.2, RA-43.4, other RA-46.5 negatives, RA-47.12 runtime and historical R4 gates remain open. No TB497.

## HISTORY — R4 RA-47.12 compile evidence recorded (2026-10-12)

Production-path rail liveness test source is applied at `60d3292018105ffd4e0064dd9b6849ffecefc2e0` and compiled in workflow `38322933412` (artifact `11779273254`, SHA-256 `75a86ca1c88c2c3c8537f84a25dfe2b7487034a26438482b513adfd95f251849`). 28/28 checksums; 8/8 targets; preflight/build 0/0, GMPXX/GMP linker, clean source, exactArithmeticBackend=GMP, runtimeExecution=false. **Not a runtime PASS;** RA-47.12 executed witness and all other R4 goals remain open. See `Architecture_M6_CP3_R4_RA4712_Default_Producer_Rail_Liveness_Code_Build_Record_20261012.md`.

## HISTORY — R4 RA-47.12 authored default-path liveness oracle (2026-10-12)

An unexecuted, actual-pipeline typed-rail positive + foreign typed-key negative was added to the existing Phase10 fixture. Apply/compile source first; defer execution to authorized TB/Review. RA-47.12 remains observationally open; no runtime PASS. See `Architecture_M6_CP3_R4_RA4712_Default_Producer_Rail_Liveness_Code_Build_Record_20261012.md`. R4 remains IN_PROGRESS and TB497 remains held.

## HISTORY — R4 typed rail helper source-corner confirmation (2026-10-12)

- [x] Apply and eight-target GMP/GMPXX compile-check source-exact RA-43.4 shared-helper counterexample patch. Exact snapshot `b178f5628bf9e07a4ede14f4717fbe37c2b6e3ab`, 6556/6556 hashes. Test source extends the existing Phase14 typed rail case with coincident distinct source-vertex ID and near-corner geometry negatives; production/legacy diagnostic contracts remain unchanged. Compile GREEN workflow `38320820157`, source `e15e1d18a38308f2c4c83b1a616a85f73af37ac7`, artifact `11778313525`, 28/28, 8/8, runtime disabled. See `Architecture_M6_CP3_R4_RA434_Typed_Rail_Corner_Confirmation_Code_Build_Record_20261012.md`.
- [ ] Continue same R4 turn afterward. RA-43.2 producer-oriented side binding, global RA-43.4 legacy migration, RA-46.5 first-rejection set, RA-47.12 observed liveness, and carried recovery matrix remain open. TB497 forbidden in this Code + Build turn.

---

## HISTORY — RA-49 unblocked; R4 duplicate terminal first-rejection regression prepared (2026-10-12)

- [x] Independent RA-49 decides duplicate `{v,v}` `ambiguous-terminal-contact` is reachable at the A4 consumer; the earlier proposed retirement is rejected. `nonmanifold-terminal-star-spoke` negative is retired (guard kept), and `R4-CTC-01` validate-after-use is reserved for a Definition turn.
- [x] Exact-source snapshot `7c228ec451ab605e9a1b913ec2dca8a2c14db365` verified (workflow `38315391692`, artifact `11775764498`, 6541/6541 files). The RA-49.2 regression in the existing rectangular HardRail tests injects duplicated original typed terminal ID, requiring the consumer's first-rejection diagnostic.
- [x] RA-49.2 duplicate-contact patch applied at `ae6af23` and compiled GREEN in `38316154434` (8/8, 28/28); no test or runtime PASS.
- [x] Apply RA-46.5 foreign typed terminal negative at `54a58af` (Drive `38318409957`) and compile GREEN in `38318599087` (8/8, 28/28, GMP/GMPXX, zero exits); no runtime PASS. Continue remaining RA-43.2/43.4, RA-46.5, RA-47.12 and carried R4 gates. No TB497 or successor before R4 closeout.

---

## CURRENT REVIEW STOP — R4 RA-46.5 ambiguous terminal contact (2026-10-12 20:45Z)

- [x] Verify source snapshot `69649fda99508310ce93a9e2920da28fa966c578` (run `38301273941`, 6535/6535). Independently show RA-46.5's literal `ambiguous-terminal-contact` witness conflicts with the distinct typed terminal IDs enforced at checked A4 and bit-exact one-hot `exact_corner` in A4 route production. Preserve proof in `.agents/Directional/Architecture_M6_CP3_R4_RA465_Ambiguous_Terminal_Contact_Review_Stop_20261012.md`.
- [ ] **REVIEW_BLOCKER:** independent Definition/Review must confirm or refute the impossibility lemma and amend only the unsatisfiable RA-46.5 negative if confirmed. Keep fail-closed branch; require valid earlier factory-first malformed-contact rejection and the remaining reachable negatives. Do not counterfeit first rejection or rename frozen selector identities.
- [ ] After independent Review, continue **the same** `M6-CP3-CB1-ENTRY-R4` Code + Build, including RA-43.2 side-attachment, RA-43.4 diagnostic opt-out, RA-47.12 runtime liveness, historical regression and genuine odd-τ/multi-carrier gates. No TB497 or successor now; no compile/runtime PASS new to this stop.

---

## HISTORY — R4 RA-43.4 compile GREEN; canonical turn remains open (2026-10-12 19:10Z)

- [x] Exact semantic `9c75f44dab79cd3b5ad014d918f15f808b6ac504` compiled in run `38293645339`, eight targets, 28/28 manifest, GMPXX/GMP, no runtime. Evidence in `Architecture_M6_CP3_R4_RA434_Default_Strict_Source_Vertex_Contract_20261012.md`.
- [ ] Continue `M6-CP3-CB1-ENTRY-R4`, not its successor: RA-43.2 producer-bound endpoint certificate; RA-43.4 legacy diagnostic opt-out; RA-46.5 actual first-rejection negative witnesses; RA-47.12 liveness; all carried first-rejection, 39/34/7/88/six CP3 and genuine odd-τ/multi-carrier obligations. Freeze selector 497. No tests/benchmarks within Code + Build.

---

## HISTORY — RA-47 typed rail implementation source staged (2026-10-12)

- [x] Frozen RA-47 review replaces raw rail-edge index with canonical typed `SourceEdgeTopologyKey` keys; source and test changes prepared from verified snapshot `1bcc068c`, including `(0,2)` differing-index regression.
- [ ] Verify exact GMP/GMPXX eight-target compile on applied semantic source. Do not infer runtime PASS from compile.
- [ ] Continue current R4: RA-47.12 liveness, RA-48.3 `set_mesh` supplied topology injection, RA-46.6/RA-48.5 typed A4 error detail, remaining RA-43 and first-rejection gates. Do not run TB497.

---

## CURRENT STOP — R4 sourceEdges feature-map vs EV index domain (2026-10-12)

- [x] Independently re-open exact source `dcf24e2c881b9ed67ec8f992d94d4b4e364fd4e2` from verified compile artifact `11740652527` (ZIP SHA `7af625c8ca0bcbc5f4f59d3793484280157e388db05a412b9d188d4cba1418a2`), derive explicit single-triangle feature-edge-vs-EV counterexample without running a Directional executable. Record `Architecture_M6_CP3_R4_Edge_Index_Namespace_Conflict_Review_Stop_20261012.md`.
- [ ] **REVIEW_BLOCKER R4-IDX-01:** accepted RA-43 defines `rail.sourceEdges` as feature-map edge positions; default field-aligned and component aggregation interpret them as EV positions; later Phase20 test assumes EV. Independent source-exact Review must select/freeze **one** authoritative namespace, amend RA-43 and first-rejection tests as warranted, and explicitly address diagnostic `failedEdgeIndex`. Neither blanket conversion nor relaxed validation is authorized within blocked CB.
- [ ] After reviewed amendment, resume this **same** R4 Code + Build: implement checked, source-proven index conversion or consumer mapping, compile eight mandatory GMP/GMPXX targets, preserve causal regressions for edges where the two enumerations differ. Retain other R4 gates and ban TB497 until Code + Build formally closes.
- [ ] Existing historical regression counts and runtime acceptance unchanged: CP2 491/491, rejected R3 403/497, 94 RED/88 accepted losses; ledger 66/17/49 debt1; no new stable event credited.

---

## HISTORY — R4 typed rail raw-sidecar interval count integrity (2026-10-12)

- [x] Verify previous RA-43.4 strict production interval guard exact eight-target GMP/GMPXX build GREEN at `0cd4391b976141ec6499378a319d933a9f7ec6c2`: run `38234679163`, result `11740820820` SHA-256 `13b2f1773e8625255482611e99cf20a3c3b65634912e1161407676757ca6f903`, 28/28 checksums, preflight/build 0/0, GMPXX/GMP linked, runtimeExecution=false.
- [x] Source hardening: typed rail with nonempty `sourceEdges` must have exact interval count; existing Phase14 source-incidence test adds mismatch negative without altering identity. Source `dcf24e2c881b9ed67ec8f992d94d4b4e364fd4e2`, Drive apply `38236532142` GREEN, consumed stage deleted, recovery patch in Library. Record `Architecture_M6_CP3_R4_Typed_Raw_Edge_Cardinality_Code_Build_Record_20261012.md`.
- [x] Verified exact 8-target GMP/GMPXX compile **GREEN** `38236639195`, job `114768941337` at source `dcf24e2c881b9ed67ec8f992d94d4b4e364fd4e2`; result `11740652527` ZIP SHA-256 `7af625c8ca0bcbc5f4f59d3793484280157e388db05a412b9d188d4cba1418a2`, manifest 28/28, exits 0/0, real GMP/GMPXX linking, source clean, runtimeExecution=false. No runtime PASS.
- [ ] Global RA-43.4, numerical raw edge `mesh.EV` source binding, overfull-A3 independent Review, 39 endpoints/34 Phase10/seven DCEL/88 CP2 losses/six CP3 plus authentic odd-τ/multi-carrier remain OPEN; no TB497 or successor.

---

## HISTORY — R4 RA-43.4 production interval-rail typed-source gate (2026-10-12)

- [x] On exact source `5ebddc55...` (snapshot `38231038572`, 6446/6446), add production-enforced `requireTypedSourceVertices` to three actual `rail_interval_refs` call sites, preserving standalone helper legacy negative diagnostics. Four-file source `0cd4391b976141ec6499378a319d933a9f7ec6c2`, Drive apply `38234541145` successful; patch stored in Library and Drive stage deleted.
- [x] Extend existing Phase14 rail-source-incidence test to require valid typed production rail and reject otherwise geometrically-valid untyped rail at strict helper and actual production trace-entry. No test names, frozen selector, network ABI, or workflow permissions changed.
- [x] Exact-source GMP/GMPXX eight-target compile **GREEN** workflow `38234679163` / job `114762421998`, source `0cd4391b976141ec6499378a319d933a9f7ec6c2`, artifact `11740820820` SHA-256 `13b2f1773e8625255482611e99cf20a3c3b65634912e1161407676757ca6f903`, `28/28` hashes, preflight/build `0/0`, GMPXX/GMP link, source clean, `runtimeExecution=false`. No runtime PASS. Record `Architecture_M6_CP3_R4_RA434_Strict_Production_Rail_Interval_Compile_Record_20261012.md`.
- [ ] Global RA-43.4 remains open (legacy direct helper and other rail metadata consumers); independent overfull-A3 Review and historical 39/34/7/88/six CP3 plus authentic odd-tau/multi-carrier remain unverified. No TB497 or successor.

---

## HISTORY — R4 seven historical DCEL fixtures: implementation census, NOT runtime PASS (2026-10-12)

- [x] Verify exact independent source snapshot `38231038572` at `5ebddc55b47167d5062914156c4be66a390df41c`: archive SHA verified, all `6446/6446` file hashes valid.
- [x] Source-prove six historical periodic-owner fixture identities (220, 221, 296, 302, 304, 439) now share a DCEL-valid oriented two-triangle disk and source-owned A3; the seventh (40, FlowRep support) has its own DCEL-valid two-triangle source and independent A3. Record `.agents/Directional/Architecture_M6_CP3_R4_Seven_DCEL_Fixture_Static_Source_Census_20261012.md`.
- [ ] **Still requires separately authorized runtime evidence:** all seven exact frozen identities must reach and preserve their individual original oracle; the old R3 `DCEL_FIXTURE_CONSISTENCY_EXCEPTION` is not a current-source runtime result. Do not count any restored PASS from static source setup or compile. No source rewrite solely to redo already-landed two-triangle repairs.
- [ ] R4 other gates remain open: independent overfull-A3 feasibility Review, RA-43.4, 39 endpoints, 34 Phase10, 88 former CP2 accepted losses, six CP3 positives and genuine odd-τ/multi-carrier. Frozen TB497 must not run during this Code + Build turn.

---

## HISTORY — R4 typed rail rejects foreign valid face-local edge (2026-10-12)

- [x] Source-independent Phase14 typed chain `(0,4)` vs valid but foreign local source edge `(1,4)` rejected by existing preprocessor oracle at interval 0; semantic `34379d974819be5586e7ef5dfaef00912ad4a343`; source patch `eac5243e1def71a503b193eedd87e5e2400276ca3a63f2639bf47ad6cd3bfc0e`, apply workflow `38228853566`.
- [x] Exact source eight-target GMP/GMPXX compile GREEN, run `38228978981`, job `114743570982`, result `11737497543` ZIP SHA-256 `bf6500a06082adaab384ee76cf7b72106cebebf0ee7c2103013ce966fd33b50a`, 28/28 manifest, preflight/build 0/0, `runtimeExecution=false`.
- [ ] R4 still ongoing: independent overfull-A3 Review, RA-43.4, 39 carried endpoints, 34 Phase10, 7 DCEL, 88 CP2 accepted losses, six CP3 and authentic odd-tau multi-carrier. No TB497 or successor authorized.

---

## HISTORY — R4 closed-rail wraparound wrong raw-index rejection (2026-10-12)

- [x] Existing closed-rail rotation/reversal fixture now asserts a distinct in-range incorrect source-edge index on typed closing interval is rejected at `InvalidRailGeometry`; semantic `cc7f6b1010309d3eb82d78c33fbddc66ef6c7e1a`, Drive apply `38226080567`, staging deleted.
- [x] Exact-source 8-target GMP/GMPXX compile GREEN, workflow `38226217402`, result `11736147455` SHA-256 `581cbe9eb2a9f3b3b7e07db2e742328e9c267442234d5a2b6a139b3b95f7aecb`, 28/28 manifest, clean source, no runtime.
- [ ] Runtime confirmation and all 39/34/7/88/six CP3 + odd-τ/multi-carrier obligations, global RA-43.4, independent overfull-A3 Review remain open; do not start TB497 or successor work.

---

## HISTORY — R4 produced raw rail index positive oracle (2026-10-12)

- [x] One existing Phase20 produced rail test gains original-source `TriMesh::EV` bounds and topology identity checks; semantic `702dfbb89df40f4f2dabddb24400911c4460ca79`, exact snapshot `38220631107` manifest 6418/6418.
- [x] Exact eight-target GMP/GMPXX compile GREEN at `702dfbb89df40f4f2dabddb24400911c4460ca79`, workflow `38221325600`, job `114718105515`, result `11734432831` ZIP SHA-256 `9c2120f3bcd65dd07a4a1e2ded691557b33333b53b82ca014c77d8da7624b11d`, manifest 28/28, preflight/build 0/0, GMPXX/GMP linked, runtimeExecution=false.
- [ ] No runtime pass claim; same R4, overfull-A3 Review, RA-43.4, 39 endpoints, 34 Phase10, 7 DCEL, 88 CP2, six CP3 and odd-τ/multi-carrier OPEN. TB497 unauthorized.

---

## HISTORY — R4 typed rail index consistency compile correction pending (2026-10-12)

- [x] Original-source edge-index/typed chain binding added at semantic `a92ddb5`, corrected after `DomainResult` compile failure at source `b970e1a113fe00b90e225d917597c649f9e1aa1d`; apply workflow `38213040179` succeeded.
- [x] Corrected `b970e1a113fe00b90e225d917597c649f9e1aa1d` compiled **GREEN** via workflow `38214261145`, job `114695273536`, artifact `11732105024` SHA-256 `f6f5f73de7626bb29402f61dd79b01091c65b712fd74fa1c03725ac1a428511d`: eight targets, GMP/GMPXX link, 28/28 checksums, source clean, `runtimeExecution=false`. Initial `38212754554` preflight failure preserved as history; no runtime PASS established.
- [ ] Overfull-A3 independent Review, RA-43.4, frozen 39 endpoints, 34 Phase10, 7 DCEL, 88 CP2, six CP3 and odd-τ multi-carrier remain OPEN; TB497 unauthorized.

---

## HISTORY — R4 unsupported-sheet first-rejection original-source A3 (2026-10-12)

- [x] Source-bounded negative fixture A2/A3 ingress, source `24fbd353332c1d55ec2612e9a0ccbe748a861d9f`, apply workflow `38208759469`, Drive stage owner-deleted.
- [x] Eight-target GMP/GMPXX compile GREEN, workflow `38208927096`, result `11728751414`, no runtime.
- [ ] First-rejection runtime verification; original 39 endpoints / 34 Phase10 / seven DCEL / 88 CP2 / six CP3 / odd-τ multi-carrier, RA-43.4 and independent overfull-A3 Review; TB497 unauthorized.

---

## HISTORY — R4 M6 CP3 produced seam witness source-A3 ingress (2026-10-12)

- [x] Correct one original CP3 A5/A6/A7 seam candidate builder's missing original-source A2/A3; semantic `b58314b3c8f024d2e6a3ce6092ad87b85425d40f`, Drive apply `38207015195`, staging retired; 3 source lines, unchanged existing test identities and topology.
- [x] Exact-source eight-target GMP/GMPXX compile **GREEN**: workflow `38207150160`, job `114673117668`, result artifact `11727628126` ZIP SHA-256 `59145348b1324241ea596fbcce410c75b016881b9abc2d06917be43d21d045b7`, manifest **28/28**, preflight/build exits **0/0**, `DIRECTIONAL_ENABLE_GMP=ON`, generated link includes GMPXX/GMP, `exactArithmeticBackend=GMP`, clean source, `runtimeExecution=false`. Diagnostic artifact `11727807480` ZIP SHA-256 `36decf1318c952fdb6bfcb222acd7336918ab6aa18540f3a82095db6a960e44d`.
- [ ] R4 runtime acceptance, RA-43.4, overfull-A3 independent Review, 39 endpoint, 34 Phase10, seven DCEL, 88 CP2, six CP3, odd-τ multi-carrier still unresolved; no TB497 and no authorized successor.

---

## HISTORY — R4 composite bounded/periodic negative source-A3 ingress (2026-10-12)

- [x] Exact source `0ffc7857c544d050a70516dbaeea6092fad1b6d7`, one Phase10 test ingress through original-source A2/A3; original `InvalidBoundedDiskFrontPairing` oracle, fixture and selector unchanged. Drive apply `38205257494`, stage retired; source patch preserved.
- [x] Exact eight-target GMP/GMPXX compile GREEN: workflow `38205407002`, job `114667758421`, result `11727133144` ZIP SHA-256 `82026586b7286971b8aadb16a6e8031f338ca4ff65b0b2facc9b0a156ef537a6`, 28/28 manifest, preflight/build 0/0, GMPXX/GMP linked, clean source, `runtimeExecution=false`.
- [ ] Actual first rejection and all frozen regression PASS/FAIL remain untested. Original R4 obligations (RA-43.4, overfull-A3 Review, endpoints, Phase10, DCEL, CP2, CP3, multi-carrier odd-τ) remain open; no TB497 promotion.

---

## HISTORY — R4 two Phase10 negative source-A3 fixture ingresses (2026-10-12)

- [x] Source-only +21/-0 two original Phase10 negatives with independently original-source-bound A3: periodic ring ambiguity and two-triangle disk invalid cyclic turn. Source `2be8da1198f9861efb7231c9468760df787b22f5`, apply run `38203661294`, Drive staging deleted; unchanged test identities and original oracles.
- [x] Exact eight-target GMP/GMPXX compile `38203770454` GREEN; result `11726506719`, ZIP SHA-256 `a5399cd78e5a38e8f2969c00dc453fa66079f0cf2f31bc8b603658cc5078a972`, 28/28 manifest, preflight/build exits 0/0, source clean, `runtimeExecution=false`.
- [ ] Runtime PASS/FAIL for these two unchanged negative oracles unverified. R4 original RA-43.4 source migration, independent overfull A3 review, 39 endpoint, 34 Phase10, seven DCEL, 88 accepted CP2 losses, six CP3, genuine odd-τ/multi-carrier all OPEN; no TB497.

---

## HISTORY — R4 three Phase10 source A3 fixture repairs (2026-10-12)

- [x] One source test file +24/-4, unchanged three selector identities and oracles; semantic source `8df105b560625ea09b3ac136b3ee4b9656a38e2f`. Source apply `38202273478` success, staged patch deleted.
- [x] Mandatory eight-target GMP/GMPXX compile `38202384969` GREEN, artifact `11725774026`, manifest 28/28, preflight/build 0/0, clean source, `runtimeExecution=false`.
- [ ] All runtime semantics and frozen 497 acceptance unverified; R4 global RA-43.4, overfull-A3 independent Review, 39 endpoint, 34 Phase10, 7 DCEL, 88 CP2, six CP3, real odd-τ multi-carrier remain open. Same R4 turn, successor UNKNOWN.

---

## HISTORY — R4 produced rail source-chain oracle (2026-10-12)

- [x] Compile-visible RA-43.2/RA-43.4 source-chain assertions in the existing producer integration test, plus exact `{0,3}` interior hard-rail seed fixture. Source `e7a39b891a046df46811bc9f792a17e0c33e7da9`, one test path +24/-0, Drive apply `38200534499` success, stage owner-deleted.
- [x] Exact source eight-target GMP/GMPXX compilation **GREEN**: workflow `38200681852`, job `114653260254`, result artifact `11725410765`, ZIP SHA-256 `ee7472bc18b63bff93c24a1c4cd7a848eb8f30ff113e99e87b25da5f6d0ff44c`, package manifest **28/28**, preflight/build exits **0/0**, **8/8** required targets, CMake GMP enabled and GMPXX/GMP linker verified, clean source, `runtimeExecution=false`.
- [ ] Runtime verification separately gated. Global untyped-rail fallback removal, overfull-A3 independent review, 39 endpoint, 34 Phase10, seven DCEL, 88 CP2 accepted-loss, six CP3 positive and multi-carrier odd-τ cases remain unresolved. No frozen 497 test execution or selector changes.

---

## HISTORY — R4 Phase14 typed rail first-rejection coverage (2026-10-12)

- [x] Source `4d51805d79994f1d718d71332be06f504d6312cf` migrates two existing Phase14 supplemental tests to authentic typed ordered source-vertex chains, one test file +9/-0, unchanged assertions/identities/frozen selectors. Genuine `Valid` baseline added; disconnected negative remains deliberately untyped so its intended first rejection is not masked. Exact patch `cc819992da00acd005904c69a8203f457aff116d749ab00161ce4156c404fb42`, apply workflow `38198898409` success, Drive patch deleted.
- [x] Exact-source eight-target GMP/GMPXX compile **GREEN**: workflow `38198996718`, job `114648012662`, source `4d51805d79994f1d718d71332be06f504d6312cf`, result artifact `11723819181`, ZIP SHA-256 `23ee086aaeef3fec3ff9b04dc200e8de2fb54c9350f33f7925458dda9ab63d73`; manifest 28/28, preflight/build 0/0, GMP/GMPXX linker verified, source clean, `runtimeExecution=false`.
- [ ] No runtime acceptance or TB497 execution. Independent overfull-A3 Review, global RA-43.4 legacy fallback retirement, 39 endpoints, 34 Phase10, seven DCEL, 88 CP2 losses, six CP3 positives and true odd-τ multi-carrier remain OPEN.

---

## HISTORY — R4 Phase14 incident-order/barrier source vertices (2026-10-12)

- [x] Authenticated two remaining Phase14 fixtures with exact typed source-vertex chain `{0,4,7}` in source `9709bd8e855e4f6a92165b082ba9b3f4330f8411`, only two insertions in one test file, all original oracles/identities unchanged.
- [x] Mandatory eight-target GMP/GMPXX compilation GREEN — exact source `9709bd8e855e4f6a92165b082ba9b3f4330f8411`, dispatcher event `c6cf2651f5d5fcfbcbdaa53b79d2fbaed6a29261`, workflow `38196555564`, compile job `114640470513`, result artifact `11723373444` ZIP SHA-256 `a122eb21e00a387d5585d6cf55244a79a15a2091138343051eb98192266d9b7f`; eight required targets, preflight/build 0/0, manifest 28/28, GMP/GMPXX generated linker evidence, clean source before/after, `runtimeExecution=false`.
- [ ] No runtime acceptance established. RA-43.4 final cutover, independent overfull-A3 Review, 39 endpoints, 34 Phase10, seven DCEL, 88 CP2 losses, six CP3 positives and odd-τ multi-carrier remain OPEN; frozen TB497 not run.

---

## HISTORY — R4 Phase14 positive rail source-vertex migration (2026-10-12)

- [x] Source-owned exact `sourceVertices` published on 10 previously untyped valid Phase14 rail instances across seven existing tests. Applied in commit `10afde93e4de3202d5bc8d2bbd0304f629a2375e`, workflow `38194680839`, result `11722878840` (patch hash verified; Drive staging deleted). One test file, ten insertions, no deletions, seven unchanged Phase14 test identities and oracles; closed, reversed, multi-interval and side-chart sample topology checked against exact source faces. No runtime Directional tests or frozen 497 execution.
- [x] Exact-source mandatory eight-target GMP/GMPXX compile **GREEN**; workflow `38194789102`, job `114635016916`, result artifact `11723220719`, ZIP SHA-256 `3340a26bc7fc8a543843981d0040a84339ec44490ed26c17b5541f1cc53e6039`. Eight targets verified; CMake `DIRECTIONAL_ENABLE_GMP=ON`, actual generated linker command references both `libgmpxx.so` and `libgmp.so`, package 28/28 checksum manifest, preflight/build exit 0/0, source worktree clean and `runtimeExecution=false`. No Directional test or benchmark executed.
- [ ] Do not claim runtime PASS, 497-case restoration, completed RA-43.4, or R4 exit. Independent overfull A3 Review, 39 endpoints, 34 Phase10, seven DCEL, 88 CP2 accepted losses, six CP3 and genuine multi-carrier odd-τ remain open.

---

## HISTORY — R4 Phase14 typed-rail valid positive (2026-10-12)

- [x] One source-owned positive fixture migration in `SurfaceCellTracingPhase14Tests.cpp`: `validRail.sourceVertices={0,4}`, preserving original negative and open-endpoint assertions, commit `5fbfa5de3f1421dab122ea70ba677efb6dd6f5f1`, apply `38193068301`; stage deleted. Exact-source 8/8 GMP/GMPXX compile GREEN workflow `38193556754`, job `114631316138`, artifact `11721982481` SHA-256 `2e665b1a2d7833c979e2bc5975979f36053e218443934de26c2cf208076637b2`, manifest 28/28, exits 0/0, clean source, `runtimeExecution=false`.
- [ ] No runtime acceptance. Remaining RA-43.4 legacy rail migration, overfull-A3 independent Review, endpoint/Phase10/DCEL/CP2/CP3/multi-carrier R4 obligations and frozen TB497 gate remain open.

---

## HISTORY — R4 overfull same-edge source/A3 feasibility (2026-10-12)

- [x] Identified source-exact reachability conflict for the supplemental three-face rail-incidence fixture: three triangles incident to the same source edge repeat one directed halfedge and are rejected by `TriMesh` DCEL consistency before A3 construction. The checked A4 factory requires a matching source-bound A3 before its later `railIncidenceCounts > 2` guard. Independent review requested in `.agents/Directional/Architecture_M6_CP3_R4_Overfull_A3_Feasibility_Review_Request_20261012.md` (commit `82d0942d05bbf8c9859d54daea5230f8dff2f323`). This is static proof, not executed evidence.
- [ ] Obtain independent Definition/Review ruling before modifying the supplemental three-face test expectation, retiring a source-valid A4-overfull witness, or replacing it with a producer-source invalidity negative. Preserve existing A4 guard, A3 gate, frozen selectors, accepted baselines, and all outstanding R4 obligations; no TB497.

---

## HISTORY — R4 typed missing-path regression oracle repair (2026-10-12)

- [x] Static first-rejection audit found `74e74e41` fixture would trip certificate/front attachment equality before typed missing-path check. Corrected one test source file without changing frozen identity or production guard; apply `38188448212`, semantic source `3c1f001fa03dde476222bbad48ae46cfebe12c9a`, owner Drive stage deleted.
- [x] Exact-source eight-target GMP/GMPXX compile **GREEN** for corrected test: request `1b60967136ad863491a2ab15dfb63a491bb07a3e`, workflow `38188542762`, job `114616135782`, source `3c1f001fa03dde476222bbad48ae46cfebe12c9a`, result artifact `11720182846`, ZIP SHA-256 `3ef4c113979d2e861df4d4b30f1c529ba56a408e67c5d250a970bff22823e679`; 28/28 manifest, 8/8 targets, GMP/GMPXX, clean source, preflight/build 0/0, `runtimeExecution=false`. The earlier compile `38187046419` covers only superseded source.
- [ ] Runtime first-rejection proof for the corrected missing-terminal-path case remains separately gated; no runtime tests performed. Further R4 obligations remain open.

---

## HISTORY — R4-A3U-01 source-exact correction (2026-10-12)

- [x] Independent terminal path uniqueness review confirmed RA-46; the impossible literal two-path fixture was retired without weakening A4.
- [x] Checked factory distinguishes typed missing versus ambiguous A3 terminal-star paths; safe source-incidence lookup; produced-terminal missing-path regression authored. Semantic source `74e74e41a7f040f34798d998dba36677e7ff07d4`, apply runs `38186808688` and `38186915904`; both Drive stages deleted.
- [x] Mandatory eight-target GMP/GMPXX exact-source compile **GREEN**, workflow `38187046419` / job `114611565662`, source `74e74e41a7f040f34798d998dba36677e7ff07d4`, artifact `11719319676` ZIP SHA-256 `b9b881b7cc820f23b2cf04983f33bbcd9df22d2a9f30a2a5a6eb0b449da2d7f9`, package 28/28 verified, 8/8 targets, source clean and GMP/GMPXX linked. No Directional binary execution or frozen TB497 authorization. Overfull three-face A3 source feasibility review and all other R4 runtime obligations remain open.

---

**Current R4 — Eigen checkout recovered; independent Definition/Review STOP remains (2026-10-11):** The original-source A2/A3 ingress correction for Phase10 `UniformPhaseFrontReliefGuidanceOnlyBlocksWhenEmbedded` is preserved in source `572cd8aea6a11717c1dd471025fde69c76acfd1e` (Drive apply `38178284384`). The initial eight-target compile `38178491667` failed *before compiling* when GitLab could not serve the pinned Eigen submodule; this historical failure remains documented in `Architecture_M6_CP3_R4_Relief_Guidance_Atlas_Compile_Blocker_Record_20261011.md`. **Resolved:** `.gitmodules` now uses `https://github.com/eigen-mirror/eigen` with the same gitlink `769c72fd8019e389810d1de1e7c243521a43b594` (source `37c349948758328ac9bfac303a93d431b5b3e8e7`). Exact-source mandatory compile `38183615883` passed all eight targets with GMP/GMPXX, preflight/build exits `0/0`, manifest `28/28`, `runtimeExecution=false`; durable evidence `Architecture_M6_CP3_R4_Eigen_Mirror_Compile_Record_20261011.md`. **Active REVIEW_BLOCKER:** `Architecture_M6_CP3_R4_Terminal_A3_Uniqueness_Design_Review_Request_20261011.md` requires a source-exact, independent Definition/Review ruling on whether two distinct admissible non-hard terminal A3 simple paths are possible under the RA-37a connected oriented two-manifold source-link contract. No qualifying counterexample or normative amendment has been reviewed or accepted. The overfull three-face incidence/A3 feasibility Review also remains open. Do not fabricate a nonmanifold witness, relax the A4 `pathCount != 1` guard, alter frozen identities/selectors, or start TB497. Canonical `M6-CP3-CB1-ENTRY-R4` stays BLOCKED with successor UNKNOWN until its independent Review conditions are resolved; remaining 39 endpoint, 34 Phase10, seven DCEL, 88 CP2 accepted-prefix losses, six CP3 positive gates and genuine multi-carrier odd-τ witnesses are unverified in runtime. Verified continuation source snapshot `38184226362` at `e3b45e67e1e69cee1ee011422af95febe5ef6724` (6,271 verified manifest entries); no production source or runtime code was changed by this documentation correction.

---

## HISTORY — R4 four legacy Phase10 producer positives receive source-owned A2/A3 (2026-10-11)

- [x] Four unchanged `SurfaceCellsPhase10` produced-positive test identities now call existing independently source-built A2/A3 helper, semantic source `ee800cce8d3bef34a8f2f891d0482cd8ff7a9f68`; source apply `38170296491` succeeded; Drive staging retired. Only `tests/SurfaceCellsPhase10Tests.cpp` changed.
- [x] Eight-target source-exact GMP/GMPXX compile **GREEN**: workflow `38170442175`, job `114561804678`, source `ee800cce8d3bef34a8f2f891d0482cd8ff7a9f68`; preflight/build exits `0/0`, 8/8 targets, CMake `DIRECTIONAL_ENABLE_GMP=ON`, both `libgmpxx.so` and `libgmp.so` linked, package `SHA256SUMS` 28/28, clean source, `exactArithmeticBackend=GMP`, `runtimeExecution=false`; result artifact `11713818041` outer ZIP SHA-256 `dd506cef5b50423857893f35266404c699ed4dea42ebaff6345187c86c7eb269`, diagnostic artifact `11713098129` ZIP SHA-256 `b3c68ccf3dda22893daf2daaf80a237b618876a54140084e9d0a323a7388228a`.
- [ ] No runtime tests performed. This code-only correction does not itself discharge 39 endpoint, 34 Phase10, seven DCEL, 88 CP2, six CP3, genuine multi-carrier/odd-τ or dual-path independent Review obligations; separate authorized Test + Benchmark needed for real PASS.

---

## HISTORY — R4 A2b closed-chain-vs-absent-contact source producer guard (2026-10-11)

- [x] Source `d8698996f3c3206830bc2aedeae06d7019d523a3` rejects contactless hard-rail endpoint A2b certificates without exact same-ID closed-chain authority, while retaining valid closed-only behavior. One `SurfaceCellTracing.cpp` change, apply `38167011887`; stages owner-deleted.
- [x] Exact eight-target GMP/GMPXX compile **GREEN**: workflow `38167114181`, job `114551928729`, source `d8698996f3c3206830bc2aedeae06d7019d523a3`, preflight/build `0/0`, eight targets built, CMake linked `libgmpxx.so` and `libgmp.so`, package checksum manifest `28/28`, source tree clean, `exactArithmeticBackend=GMP`, `runtimeExecution=false`; result artifact `11712702267` ZIP SHA-256 `7e285a50395217a3d47c5dafd6a851c695eaebceaf6e64cb7c9e3675d0e6e9a6`, diagnostic artifact `11712622481` ZIP SHA-256 `77fdd8868e9aba9e43df1ccab219cd8592c97274678e806f68c46cc19b835f14`. No runtime tests, benchmarks, or selector discovery executed.
- [ ] Runtime-check typed first-rejection and authentic open/closed positive controls in independently authorized Test + Benchmark; none run here. Original 39 endpoint, 34 Phase10, 7 DCEL, 88 CP2 losses, six CP3 gates, real multi-carrier/odd-τ and independent dual-path Review remain open. No R4 completion / TB497 promotion.

---

## HISTORY — R4 checked A4 terminal-contact absence / foreign-source negatives (2026-10-11)

- [x] Exact source `72615c7a0bf7ca4d3b9d3729c81eb47842278251` adds two negative cases to the original `CheckedFactoryRejectsForgedTerminalA2bSideGerm` selected test: remove one genuine contact; substitute real source vertex 0 (not on the hard rail). Retains original source A3 and producer baseline. Source apply `38164373890`, follow-up typed DomainResult fix `38164686585`; both Drive stages deleted.
- [x] Exact eight-target mandatory GMP/GMPXX compile **GREEN**: workflow `38164832322`, job `114545168786`, semantic source `72615c7a0bf7ca4d3b9d3729c81eb47842278251`, preflight/build exit `0/0`, both GMP libraries linked, manifest `28/28` clean, `exactArithmeticBackend=GMP`, `runtimeExecution=false`; result artifact `11711333843` ZIP SHA-256 `af09d91d99b3e0e3b0c3bac3161fd6e2d4fa9054cbfb7065f8f8de792c7e35c8`, log `11711413607` ZIP SHA-256 `dce3dc30b92f025fa63bb4c221a78c5e9c742a86fa75d50bf0c68f7309b61f54.
- [ ] Runtime evidence for actual first A4 rejection remains unverified. No Directional generated binary, test, benchmark, discovery or frozen 497-case selector was executed. This is compile-only candidate evidence, not runtime acceptance or restoration of any R3 RED/CP2 case. The 39 endpoint, 34 Phase10, 7 DCEL, 88 accepted CP2 losses, six CP3 gates, real multi-carrier/odd-tau and independently reviewed dual-terminal-path obligation remain open. Canonical `M6-CP3-CB1-ENTRY-R4` remains `IN_PROGRESS`, successor `UNKNOWN`; no Test + Benchmark successor is authorized. Record `.agents/Directional/Architecture_M6_CP3_R4_A2b_Terminal_Contact_Negative_Code_Build_Record_20261011.md`.

---

## HISTORY — R4 periodic malformed-crossing independent A3 ingress (2026-10-11)

- [x] Source-only test migration `e0cc0415b447c045443e3d498c6d6f50769b29e8` removes legacy A3-unbound periodic builder and passes original-source A2/A3 to `MalformedAuthoritativeCrossingProvenanceFailsClosed` without changing its malformed metadata or expected `PeriodicHolonomyMismatch`. Apply `38161729069`, verified; staged Drive patch permanently deleted; frozen identities/selectors unchanged.
- [x] Exact eight-target GMP/GMPXX compile GREEN: `38161835655` job `114536250404`, preflight/build `0/0`, clean source, `28/28` self-manifest, GMP linked, `exactArithmeticBackend=GMP`, `runtimeExecution=false`, result artifact `11710631873` ZIP SHA256 `8e672d4720e4ff244dc80a540a0c1989a67b43155a01883fced3c8d9c1a9d9c7`, log artifact `11710816692` SHA256 `74210d3d205f49f22f38ded7598514edb772689c750bbef84165efaeaa31276e`.
- [ ] No runtime PASS attributed. R4 still requires 39 endpoints, 34 Phase10, 7 DCEL negatives, 88 CP2 losses, six CP3 positives, genuine multi-carrier/odd-τ and independent dual-path Review. Frozen 497 Test + Benchmark is not authorized in this Code + Build turn.

---

## HISTORY — R4 supplemental hard-rail source A3 positive-control non-vacuity (2026-10-11)

- [x] Source `e7871efaf56a1ee717cea5b66115e5c50a125d46` strengthens the original *supplemental* `HardRailTransitionNeedsExactlyTwoSourceFaceIncidences` with independent A3 non-null positive control and an actually published two-face A3 carrier. One test file, 12 lines; Drive apply `38158972074` succeeded and stage retired.
- [x] Exact GMP/GMPXX eight-target compile GREEN: workflow `38159098983`, job `114528148302`, semantic source `e7871efaf56a1ee717cea5b66115e5c50a125d46`, preflight/build exits `0/0`, real `libgmpxx.so` and `libgmp.so` linked, `DIRECTIONAL_ENABLE_GMP=ON`, source clean, manifest `28/28`, `exactArithmeticBackend=GMP`, `runtimeExecution=false`; result artifact `11708843472` ZIP SHA-256 `39fc4fdb3020d6c3f8902264c2297818a9b840d9b1330fc86b7a08dec509786c`, log artifact `11708998433` ZIP SHA-256 `072db2fe296a1d336e572ccfbdc619a79bf30747523c428b8c4d084defd9e670`.
- [ ] Independent overfull three-face source/A3 feasibility Review still required; no runtime PASS for this supplemental test. Other R4 39 endpoint/34 Phase10/7 DCEL/88 CP2/six CP3/real multi-carrier odd-τ and independent dual-path obligations remain. Frozen TB497 not authorized.

---

## HISTORY — R4 factory-incidence negative oracle and frozen DCEL static audit (2026-10-11)

- [x] Exact snapshot `38154965590`, 6207/6207 verifies. Identified potential overfull-rail negative vacuity: for three shared-edge triangles, missing/nonconstructible A3 can yield `InvalidSourceAuthority` **before** the intended checked incidence guard; no runtime evidence. Seven frozen R3 DCEL fixtures currently share source-valid-looking two-face disk topology; none is verified PASS.
- [ ] Independent A3/manifoldness feasibility decision for the three-face negative; preserve A3 matching, hard-feature incidence guard and all frozen selectors. Runtime-check seven original DCEL negatives only in a future independently authorized artifact-only Test + Benchmark. Full evidence `.agents/Directional/Architecture_M6_CP3_R4_Factory_Incidence_Oracle_Source_Validity_Static_Audit_20261011.md`. All 39 endpoint / 34 Phase10 / 88 CP2 / six CP3 / multi-carrier odd-τ / terminal dual-path obligations remain; R4 IN_PROGRESS, successor UNKNOWN.

---

## HISTORY — R4 supplemental hard-rail incidence receipt (2026-10-11)

- [x] Diagnose missing open-rail terminal-contact provenance on supposedly valid one/two-face incidence cases; patch original supplemental factory negative with source-owned terminal contact (`3a5b1d852fb2c91464969612a312679271043ad2`), followed by exact `DomainResult::value()` compiler fix (`b2b398591e399f2a8aeeea811c0850c45b128283`). Apply `38152596179` and `38152951894` succeeded and consumed Drive stages were retired. One test file only.
- [x] Exact GMP/GMPXX eight-target compile **GREEN**: workflow `38153070583`, compile job `114510410732`, semantic source `b2b398591e399f2a8aeeea811c0850c45b128283`, eight requested targets, `0/0` preflight/build exits, 28/28 artifact manifest checksums, linked both `/usr/lib/x86_64-linux-gnu/libgmpxx.so` and `libgmp.so`, source tree clean, `exactArithmeticBackend=GMP`, `runtimeExecution=false`; result artifact `11706799174` ZIP SHA256 `81a9a52a14db4ef03f60e56737be007baedeea6c19ad98e3383d54615f4617ef`, log artifact `11706888808` ZIP SHA256 `0243bffa99b76b8947c6568145b063673375e073db3683f7bc2e5837875d9f18`.
- [ ] Supplemental case excluded from frozen 497; runtime behavior remains unverified. R4 39 endpoint, 34 Phase10, seven DCEL, 88 CP2 accepted losses, six CP3 positives, genuine multi-carrier/odd-τ and independent dual-path design review remain open. No TB successor authorization.

---

## HISTORY — R4 FlowRep singularity-support fixture (2026-10-11)

- [x] Exact source `245ef12a10dca2f258d53dcf997f43e2a7567de4` replaces a one-triangle supplemental singularity-support source fixture with a consistently oriented two-triangle disk while preserving the original rail/trace geometry, test identity and oracle. Apply `38150151923`; Drive staging permanently deleted.
- [x] Exact mandatory GMP/GMPXX eight-target compile GREEN `38150289951`, job `114502218749`, source `245ef12a10dca2f258d53dcf997f43e2a7567de4`, preflight/build 0/0, both GMP libraries linked, clean tree, 28/28 ZIP manifest, `runtimeExecution=false`; result `11706318595` SHA-256 `7f0db84857a847378b07b998d02cf592cab47f8c2bdae72d8dfab819669e6be2` and log `11706588040` SHA-256 `c9933e7976cdc2062514d1d536c25fc04e8f1122d9d732d6c8d5cc31c2471c9b`.
- [ ] Runtime execution and all original R4 obligations still pending. This supplemental fixture is not among the frozen seven R3 DCEL regressions and earns no restored PASS. R4 `IN_PROGRESS`; no frozen TB497. See `.agents/Directional/Architecture_M6_CP3_R4_FlowRep_Singularity_TwoFace_Source_Fixture_Code_Build_Record_20261011.md`.

---

## HISTORY — R4 rejected terminal source-point coordinates (2026-10-11)

- [x] Verified exact snapshot `38146355008`, 6,174/6,174 entries. Applied source-only diagnostic `5650747e75703d644ba7f7b888981fe32fbce542` through `38146992456`; one code file, original A2b/A3 selection unchanged, Drive staging deleted.
- [x] Mandatory GMP/GMPXX compile `38147128884` GREEN: 8/8, preflight/build `0/0`, manifest `28/28`, clean source, `runtimeExecution=false` (result `11704508997`).
- [ ] First actual rejected endpoint source barycentrics remain runtime-unverified. The stored point may already be canonicalized by a chart tolerance; no source-valid contact claimed. Outstanding 39 endpoints, 34 Phase10, seven DCEL, 88 CP2 losses, six CP3 gates, genuine multi-carrier/odd-τ, and independent dual-path Review. No TB497 in current Code + Build.

---

## HISTORY — R4 carried 39 endpoint static grouping (2026-10-11)

- [x] Crosswalked all 39 frozen A4 route-certificate RED rows: 31 share the internal-midline hard-carrier endpoint predicate (17 constant fixture, 12 fixed-plan variants, two odd χ); eight have distinct observed first failures. Independently mapped the 3×3 source-star spokes; no extrapolated runtime evidence. Exact record: `.agents/Directional/Architecture_M6_CP3_R4_Carried_39_Endpoint_Fingerprint_Source_Star_Triage_20261011.md`.
- [ ] Determine authentic traced terminal corner/contact vs source-star paths and resolve real first predicate without weakening A2b/A3. No 39 endpoint, 34 Phase10, seven DCEL, 88 CP2, six CP3 or multi-carrier/odd-τ PASS claimed. Dual-path Review pending; no TB497.

---

## HISTORY — R4 terminal dual-path source-topology Review gate (2026-10-11)

- [x] Verified exact source snapshot `5a7288c254f2b6d96320a5f645d3dcfb4bc4254b`, workflow `38139725760`, source archive SHA/6,164 manifest entries. Static graph argument: an accepted two-manifold terminal face-star is a link path/cycle, and removing the incident hard-carrier spoke leaves at most one simple non-hard A3 path to its carrier face. Full bounded proof and precise independent Review question: `.agents/Directional/Architecture_M6_CP3_R4_Terminal_A3_Uniqueness_Design_Review_Request_20261011.md`. **Not** a revised normative definition or runtime evidence.
- [ ] Independent Definition/producer Review must either provide a source-valid two-path counterexample under existing rules or amend only that impossible witness obligation. Maintain all A4 fail-closed checks and frozen selectors. R4 other 39 endpoint / 34 Phase10 / seven DCEL / 88 CP2 / six CP3 / genuine odd-τ multi-carrier gates remain open; do not run TB497 here.

---

## HISTORY — R4 A2b terminal missing/ambiguous simple-path diagnostic (2026-10-11)

- [x] Diagnostic-only source `3bcbb1f28adaa5b1b7dc5de9bc31e8be46ef5a4c`: report finite A3-admissible simple-path count to distinguish missing/ambiguous terminal path *on already rejected A4 endpoint certificates*, retaining typed first-failure and all checked A2b/A3/sector/orientation gates. Apply `38137073789` verified; patch `cb0702f4382d247dd9b5eec0d202bc1ecbb34ed0e291efd9c00af422bffcf3a2` backed up; transient Drive staging deleted.
- [x] Mandatory GMP/GMPXX compile GREEN: workflow `38137200763`, job `114463449240`, 8/8 targets, preflight/build 0/0, 28/28 checksums, final tree clean, `runtimeExecution=false`, result `11702155468` SHA-256 `f5cb12568e252e2d2a5280f2bd1daffb4a98fd934a327151b6be437861464d0e`, separate log `11701761274` SHA-256 `c6ca9ea7c62e3f7a31049a0b13550f2592c9ece2395edea96a92b36cbd587f40`.
- [ ] No runtime evidence, no 39 endpoint or CP2 PASS restoration, no proof of source-valid second admissible path; all 34 Phase10, seven DCEL, 88 CP2 losses, six CP3 positives, genuine multi-carrier/odd-τ and independent dual-path Review remain open. Frozen TB497 cannot start in Code + Build.

---

## HISTORY — R4 endpoint A2b first-rejection localization (2026-10-11)

- [x] Source `13139486e9a4ae4ff9fb1df48860026efc8b7b63`: rejection-only `a2bProbeFailure` records actual first failed A2b terminal predicate (source-face, carrier, contact, A3, sector path or orientation) alongside earlier source-corner presence probes. Existing A4/A2b approval, route-certificate reason and selectors unchanged; Drive apply `38134295353` confirmed; File-Library patch backed up, consumed Drive staging deleted.
- [x] Mandatory GMP/GMPXX eight-target compile GREEN: workflow `38134409505`, job `114455278370`, semantic source `13139486e9a4ae4ff9fb1df48860026efc8b7b63`, preflight/build 0/0, package 28/28, source clean, `exactArithmeticBackend=GMP`, `runtimeExecution=false`; result `11700646459` ZIP SHA-256 `aee723437263bfe017297cc56ac3923ec8a7b7080e804b0819f3f12226c524ef`, log `11700402184` ZIP SHA-256 `19fbaac9f45ad37c8b427ddf4a125b98cc53b44d6cec8751c8d359b502ec0027`.
- [ ] Runtime first-rejection evidence remains separately gated. No acceptance or PASS is claimed. R4 still must resolve 39 endpoint, 34 Phase10, seven DCEL, 88 formerly accepted CP2 losses, genuine multi-carrier/odd-τ, six CP3 gates and dual-path independent review. No frozen Test + Benchmark run in Code + Build.

---

## HISTORY — R4 post-rejection hard-rail A2b endpoint evidence (2026-10-11)

- [x] Source `3f9dd2b390caf03e3e780aab6e58ba26fc4a8d58`: diagnostic-only endpoint rejection probe, verified one-file Drive apply `38131410373`; unchanged A2b/A3 acceptance and frozen selectors. Source patch backed up in `/Directional/Evidence/`; staging owner-deleted.
- [x] Mandatory eight-target GMP/GMPXX compile verified: workflow `38131508716`, job `114446675580`, semantic source `3f9dd2b390caf03e3e780aab6e58ba26fc4a8d58`, eight requested targets, GMP/GMPXX linked, preflight/build exit 0/0, package 28/28 manifest, clean final source, `exactArithmeticBackend=GMP`, `runtimeExecution=false`; result `11699316241` ZIP SHA256 `bc8d5c35428ebe03b17a6f84f96d0573134c16ab4b1e4ab8c3fa2259c01845ad`, log `11699830258` ZIP SHA256 `0331a56d385125966be78481e0b5fefbd72c0b0b0a58da557c19612935826ffb.
- [ ] Runtime verify the first rejected endpoint predicate in a separately authorized immutable Test + Benchmark turn. No runtime, PASS or acceptance claim. Continue 39 endpoint, 34 Phase10, seven DCEL, 88 CP2 regressions, 6 CP3 gates, multi-carrier/odd-τ and independent dual-path review. R4 `IN_PROGRESS`, successor `UNKNOWN`.

---

## HISTORY — R4 R3 Phase10 source-atlas ingress census (2026-10-11)

- [x] Static source/overlay crosswalk at `fa03f13298c1ade7b46ba6bf4ca515c9831409ed`: 52/94 R3 RED identities owned by `SurfaceCellsPhase10Tests.cpp`, all 52 CP2-accepted by independent recomputation; 22 untyped, 18 A4 rail-route certificates, 12 invalid final-cell-state first predicates. Direct-builder ordinals 199/247 already have independently sourced A3; 29 delegated identities require separate analysis. Full evidence: `.agents/Directional/Architecture_M6_CP3_R4_Phase10_R3_RED_Source_Atlas_Static_Census_20261011.md`.
- [ ] No case is runtime-restored by this census. Diagnose route-certificate/39 endpoint and source final-cell-state owners instead of blindly attaching another atlas; preserve 34 Phase10, seven DCEL, 88 CP2 regression obligations, authentic multi-carrier/odd-τ and independent dual-path review. R4 remains Code + Build; no frozen TB497.

---

## HISTORY — R4 original-source A3 ingress for two region-reference negatives (2026-10-11)

- [x] Frozen CP2-accepted/R3-RED ordinals 123/124: correct missing original-source A2/A3 authority in their initial positive producer, leaving checked A4 region mutation, expected typed reasons, identities and selectors unchanged. Exact source `d3a70402a999b34fe69cacd4905440f7d529e3ab`, apply workflow `38125626216`; one test file; patch backup retained and staging retired.
- [x] Eight-target mandatory GMP/GMPXX compile GREEN: run `38125718129`, job `114429605388`, source `d3a70402a999b34fe69cacd4905440f7d529e3ab`, all eight required targets, GMP/GMPXX links, configure/preflight/build `0/0`, manifest `28/28`, clean source, `exactArithmeticBackend=GMP`, `runtimeExecution=false`; result artifact `11697351263` ZIP SHA256 `85074becb5acfb2170b406126b67d99e0cf8873252ec63adc54f71b731f27e44`, log artifact `11696729558` ZIP SHA256 `3a180fd2ddf4338104313ad423efc39b3cb42d7d405623bdb25384a5e36c17ea.
- [ ] Runtime positive production and actual expected `InvalidCellRegion`/`InvalidEdgeRegion` first rejection remain unverified; no prior accepted PASS restored. Remaining R4 39 endpoint, 34 Phase10, seven DCEL, 88 CP2, authentic multi-carrier/odd-τ, six CP3 gates and independent dual-path Review; successor UNKNOWN.

---

## HISTORY — R4 periodic cylinder malformed-holonomy independent A3 ingress (2026-10-11)

- [x] Frozen CP2-accepted/R3-RED ordinal 247, `SurfaceCellsPhase10.PeriodicPhaseFrontMalformedHolonomyFailsClosedWithTypedReason`: exact test-only source `285a501053fa7a1c80683fb12d98d31052cd7239` adds independent original mesh/cross-field A2/A3 to the positive and deliberately malformed selected inputs without changing existing assertions, name, selector or production code. Apply `38123037201`; Drive stage owner-deleted.
- [x] Eight-target exact-source GMP/GMPXX compile GREEN `38123145650`, job `114421910761`, source `285a501053fa7a1c80683fb12d98d31052cd7239`, exits 0/0, both GMP libraries, 28/28 checksums, final clean source, `runtimeExecution=false`; result `11696216443` ZIP SHA256 `9fc195ee2fc4c034ff26188e19d381385a75655ff03674e4d337e42890082deb`, diagnostic `11696116646` ZIP SHA256 `135481236e1ea87eaf1c9e2c03e7c3c0276b6e0ab9ab25b942eaef49f9fad8e8`.
- [ ] Runtime first rejection is **unverified**: prior first observable `A4_NOT_PRODUCED_UNTYPED`; original negative still expects `PeriodicHolonomyMismatch`. No R4 recovery PASS or frozen 497 acceptance credited. Remaining 39 endpoint, 34 Phase10, seven DCEL, 88 CP2 accepted, source-valid multi-carrier/odd-τ, six CP3 gates, and independent dual-path design review; successor UNKNOWN.

---

## HISTORY — R4 two original-source A3 periodic / chart fixtures (2026-10-11)

- [x] Migrate existing frozen 192/199 A4 positive subject ingress to original-mesh/source-field A2/A3; preserve ordinal 192's separately mutated nonzero tracing input, original negative assertion and both original test identities. Source `2be228d96c5a69ef2da584a221ae2fa6d4b5e720`, apply `38120304731`, one test file, Drive stage owner-deleted.
- [x] Mandatory compile-only GMP/GMPXX GREEN `38120408348`, job `114413835117`, source `2be228d96c5a69ef2da584a221ae2fa6d4b5e720`, 8/8 targets, `0/0` exits, 28/28 manifest, clean source, `runtimeExecution=false`; result `11695256383` ZIP SHA256 `8b581fa5b391e22b59fea07035ec69285e495d9536b2066050d19460978339e7`, log `11695226430` ZIP SHA256 `2f0b040357319c40e2084755e2384360a6b39c87d69e6a7bda53f3592d74152c`.
- [ ] Runtime verification required: both source R3 failures were `A4_INVALID_FINAL_CELL_STATE`. No source acceptance/restored PASS counted. Other R4 39 endpoint / 34 Phase10 / seven DCEL / 88 CP2 / odd-τ multi-carrier / six gates / dual-path review unchanged. No TB in Code + Build.

---

## HISTORY — R4 five periodic route source-A3 ingress candidates (2026-10-11)

- [x] Existing frozen R3-RED 189, 190, 193, 194, 195 use independent original-source A2/A3 in positive fixtures; source `7ccdcd527380f8ab0fb2c19fbc08a7ab4dbd0819`, apply run `38117860858`, no production/selectors/assertions altered.
- [x] GMP/GMPXX compile-only workflow `38117950975`, job `114406619697`, exact semantic source `7ccdcd527380f8ab0fb2c19fbc08a7ab4dbd0819`, all eight requested targets, preflight/build exits `0/0`, real `gmpxx`/`gmp` linkage, `exactArithmeticBackend=GMP`, 28/28 self-manifest checksums, clean final source, and `runtimeExecution=false`. Result artifact `11693642603` ZIP SHA256 `0fbc36cbdf35567a0dedaa27bc9cd92f8d22b0515e8e1e0767785f1cd4bd2664`; separate log `11694026916` ZIP SHA256 `27c0681a455bfae283a915afbf7e8241ff466032ec632c4e624ffdcca75a07bf`.
- [ ] Runtime-verify five distinct first rejections in separately authorized TB; no PASS restoration. Remaining 39 endpoint, 34 Phase10, seven DCEL, 88 CP2 losses, odd-τ/multi-carrier, six CP3 gates, dual-path review; R4 stays open.

---

## HISTORY — R4 two Phase10 composite A3 atlas candidates (2026-10-11)

- [x] Existing R3-RED ordinals 239 and 250 now build original source A2/A3 before checked A4, preserving all prior assertions and hard-feature/sheet metadata; semantic source `9535719a9d0e796ec455b721a199f0d6551530ae`, apply workflow `38115050210`.
- [x] Exact eight-target GMP/GMPXX compile-only GREEN workflow `38115159602` job `114398532401`, source `9535719a9d0e796ec455b721a199f0d6551530ae`, exits 0/0, manifest `28/28`, clean source, `runtimeExecution=false`; result `11693471916` ZIP SHA256 `5777133eb4b189023450f9b1a6b2eb02355c177b5c1cf310ea142e025afd9853`, log `11692992849` ZIP SHA256 `96557fd19e09e599106ae8556d4115a9ba1f98d3ed63912a228c13d78c9808b1`.
- [ ] Both cases had historical `A4_INVALID_FINAL_CELL_STATE` failures and are **not proven recovered**; runtime execution remains unauthorized in Code + Build. R4 39 endpoint/34 Phase10/7 DCEL/88 CP2 and six CP3 gates, odd-τ multi-carrier, and dual-path design review remain open.

---

## HISTORY — R4 segment-route independent A3 fixture ingress (2026-10-11)

- [x] Six frozen R3-RED `SurfaceCellSegmentRouteTransportAuthorityMigration` identities at 202–207 share a source-owned A2/A3 fixture constructor, without changing raw/legacy/malformed test inputs, original test names or assertions. Exact source `4ee15ada1493e14ed49ab542025040ce6e9dd91a`, apply run `38112589873`, only one test file modified; Drive staging retired.
- [x] Mandatory eight-target compile-only GMP/GMPXX: GREEN run `38112672216`, job `114391347393`; preflight/build `0/0`, source `4ee15ada1493e14ed49ab542025040ce6e9dd91a`, 28/28 checksums, clean source, `runtimeExecution=false`, artifact `11691733820` ZIP SHA256 `555573b5d42e78f1f06c69d042e8d809a1f84d0830341bbaa9334a67816854e4`, log `11691718914` ZIP SHA256 `33351ed67361d8ca882851303fbbb04044236433a3222a4eeaa473d25821689c`.
- [ ] Runtime acceptance of any of the six is unverified; R4 still owes the 39 endpoint, 34 Phase10, seven DCEL, 88 accepted CP2 regressions, genuine multi-carrier/odd-τ, six CP3 gates and independent dual-admissible-path design review. No frozen 497-case Test + Benchmark authorized.

---

## HISTORY — R4 seven Phase10 source-A3 ingress candidate repairs (2026-10-11)

- [x] Seven frozen CP2-accepted/R3-RED ordinals 144/145/152/200/246/249/256 migrated to independent source-owned A2/A3; source `d268e7660648ddfaf689f2fd00a5d2e2ada6497a`, apply run `38109848235`; original assertions/selector identities unchanged.
- [x] Eight-target GMP/GMPXX compile GREEN: Run `38109941607` / job `114383284022`; exact source `d268e7660648ddfaf689f2fd00a5d2e2ada6497a`; eight mandatory targets, GMP/GMPXX linked, preflight/build exits `0/0`, manifest `28/28`, clean source, `exactArithmeticBackend=GMP`, `runtimeExecution=false`; result artifact `11690494421` ZIP SHA256 `b81f408a7367126d50108be60cb1f467cf976a330570aaa1046f84a7989b980c`; diagnostic `11690928607` ZIP SHA256 `9f783d727ba6de013e65452725cd990d0cc9a85de0ac47cfa4bac9643e1159a6`.
- [ ] Runtime first rejections/PASS of all seven still unverified; 39 endpoint, 34 Phase10, seven DCEL, 88 CP2 regressions, multi-carrier/odd-τ, six CP3 gates and dual-path review remain open. No frozen 497-case TB in Code + Build.

---

## HISTORY — R4 four Phase10 source-A3 fixture migrations (2026-10-11)

- [x] Four frozen R3-RED Phase10 identities 119/129/196/248 migrated at six A4 ingress sites to existing independent `build_phase10_with_source_atlas` helper. Applied source `4467edc69f6c8b2d4530cd902d4de32681aa3671`, workflow `38107433774` (one test file). Original assertions, selectors and production code unchanged; Drive stage owner-deleted.
- [x] Mandatory eight-target GMP/GMPXX compile GREEN `38107520617` job `114376101533`, source `4467edc69f6c8b2d4530cd902d4de32681aa3671`; exit 0/0, clean, 28/28 manifest and `runtimeExecution=false`. Result `11689459391` SHA256 `a6b1a0ab0f91694ba33d730de0a596be8d49cd1d72ef799323ee37a826646506`, log `11689613812` SHA256 `ac7d3802a0ee67df5391ee12af6ab1df0d0d2f1a4370612f3f5567ec81981434`.
- [ ] Runtime validation remains separate and **unauthorized in Code + Build**. 39 endpoint / 34 Phase10 / 7 DCEL / 88 CP2 R3 regressions, genuine multi-carrier/odd-τ and dual-path independent review remain open. Do not advance to frozen TB497 or count a candidate as PASS.

---

## HISTORY — Three R4 Phase10 A2/A3 row-order candidate repairs (2026-10-11)

- [x] Source `2626a053424cc8ff53c31c13fe5559494835b1af` migrated frozen ordinals 245/255/257 to independent A2/A3; apply `38104841732`, exact one-file change and Drive stage cleanup.
- [x] Compile-only eight-target GMP/GMPXX GREEN `38104929249` job `114368349287`, 0/0 exits, 28/28, clean source and `runtimeExecution=false`, artifacts `11689775162` ZIP SHA `841dfae0769f52f71578cc2b75fc8607329304a699c9154a88fa94ffb1771dcd`, log `11688649940` SHA `9a15450a17cb68d98cd6ee65fa9fd69cc74f2616a605fca7da5117314a529d12`.
- [ ] Runtime regressions NOT yet proved recovered. R4 39 endpoint/34 Phase10/7 DCEL/88 CP2/multi-carrier/odd-tau and dual-path review still open. No frozen 497 TB.

---

## HISTORY — R4 complete checked-A4 region-reference negative witnesses (2026-10-11)

- [x] `ConflictingCellRegionFailsBeforeMaterialization` and `ConflictingEdgeRegionFailsBeforeMaterialization` preserve source-owned A3 and all produced A2b/conformity evidence, positively reconstruct original A4 before sole region mutation, then assert original typed `InvalidCellRegion` / `InvalidEdgeRegion`. Exact source `e200af8b0e2984ae6a452df9fd8520016043cc7d`, Drive apply `38102136461`; source patch backed up in `/Directional/Evidence/`, staging deleted. No production/selector change.
- [x] Exact eight-target GMP/GMPXX compile GREEN: run `38102239838`, job `114360426650`, source `e200af8b0e2984ae6a452df9fd8520016043cc7d`, preflight/build 0/0, 8/8 targets, 28/28 checksum manifest, clean source, both GMP libraries verified, `runtimeExecution=false`. Result `11688525324` SHA256 `509da9e590f598bf262b63e55bd2d10ef59d94e47579d5cbbab3c0cf22aff634`; diagnostic `11687754449` SHA256 `812a2a2fea38cf70d9c60a1b88b1c7dc9b466701e17eec1065567c719d75fa0f`.
- [ ] Neither expected error is runtime-confirmed. All R4 39 endpoint, 34 Phase10, seven DCEL, 88 CP2 losses, multi-carrier/odd-τ and dual-admissible-path design review obligations remain open; no Test + Benchmark successor is authorized.

---

## HISTORY — R4 curved-disk complete A4 checked-factory bounded-disk negatives (2026-10-11)

- [x] Correct both curved-disk A4 negative tests to reconstruct full source authority and assert a successful unmodified positive checked-factory round-trip. Source `10fe9476be39f71171d6df33bc282089c0461944`, apply workflow `38099335208`, original test identities/expected errors preserved; source patch retained in `/Directional/Evidence/` and consumed Drive staging retired.
- [x] Exact mandatory GMP/GMPXX compile GREEN: workflow `38099415226` / job `114352107025`, exact semantic source `10fe9476be39f71171d6df33bc282089c0461944`, all eight required targets linked, preflight/build exit `0/0`, CMake `DIRECTIONAL_ENABLE_GMP=ON`, authoritative link command includes both `libgmpxx` and `libgmp`, 28/28 package self-manifest checksums verified, final source clean, `exactArithmeticBackend=GMP`, `runtimeExecution=false`. Result artifact `11686914874` ZIP SHA-256 `decfd995e52efa2f6a3f242bbbdbe7d2279d38e6bf18834a3a4e190fd7c01643`; diagnostic log artifact `11687480020` ZIP SHA-256 `ca6806b77e0d33eb55cf91cc12c2880695e0d8cc8778f3856c5dfd16fc096340`.
- [ ] Runtime prove both negative first rejections only in a separately authorized artifact-only Test + Benchmark turn. Full R4 39 endpoint / 34 Phase10 / 7 DCEL / 88 CP2 regressions and authentic multi-carrier/odd-τ remain open; dual-path independent adjudication remains required.

---

## HISTORY — R4 Phase10 shared-boundary negative A4 authority correction (2026-10-10)

- [x] Source `f7be55e01c525ef4ae7c8db0039956246d8f04cc` fixes the existing missing/tampered interval negative fixture to preserve full hard-rail A2b/A3 authority and require successful positive checked A4 reconstruction before negative checks. Drive apply `38096715429` verified. No production code, selector changes or runtime execution.
- [x] Exact GMP/GMPXX compile GREEN: workflow `38096829899`, job `114344387141`, semantic source `f7be55e01c525ef4ae7c8db0039956246d8f04cc`, eight required targets, preflight/build exit `0/0`, CMake GMP discovery and both `libgmpxx` / `libgmp` link verified, 28/28 recursive package checksums, clean source and `runtimeExecution=false`; result artifact `11686391124` ZIP SHA-256 `cbfbe488bda31b5542bb19ceefc80628181d65e1c0bf36ad8f91cec533c3efaa`, log artifact `11686760574` ZIP SHA-256 `7d0ef296ef8d9074c83604fa9ad845e3d38cfffac8f22151d18c385c9e4190d1`.
- [ ] The expected `InvalidSharedBoundaryInterval` first rejection is **not yet runtime verified**. Separately authorized artifact-only Test + Benchmark is required; R4 39 endpoint / 34 Phase10 / 7 DCEL / 88 CP2 / multi-carrier/odd-τ and independent dual-path review obligations remain open.

---

## HISTORY — R4 Phase10 source-owned A2/A3 fixture ingress (2026-10-10)

- [x] Source-only candidate migration of frozen ordinals `128` and `146`, previously accepted CP2 but R3 RED: original TriMesh/CrossFieldResult produces independent A2/A3 atlas; unchanged A4 factory validates the source; semantic commit `f9db8c009835435aa1b64f07058244e58518b50b` via Drive apply `38092755831`. No selector edits or acceptance claim.
- [x] Exact GMP/GMPXX compile GREEN: run `38092868020` / job `114332779081`; source `f9db8c009835435aa1b64f07058244e58518b50b`; 8/8 GMP/GMPXX, preflight/build exit 0/0, self-manifest 28/28, clean source, `runtimeExecution=false`; result `11685040908` SHA256 `bc2648aa9a679dc344398d8abd83a90c11c55a42a0bd36b478fb8214199e0197`; log `11684876187` SHA256 `d5c8d86b89d86f3f1be81c4ec54e561629dc14e9571b2cbf8d0ab5292195175a`.
- [ ] Runtime evidence remains restricted to separately authorized immutable Test + Benchmark. All 34 Phase10, 39 endpoint, seven DCEL, 88 CP2, multi-carrier/odd-tau and dual-path review obligations remain open; compiler-green is not a recovered selector.

---

## HISTORY — R4 A5-reachable hard-rail lattice branch negative (2026-10-10)

- [x] Source `7ac899b2d91e9d8c0925bbb4cc1ccd367872dcc4` adds a produced-baseline, complete-A4-accepted, A5-expected `HardRailTransportMismatch` regression. Apply workflow `38091134482`; Drive staging retired; no tests run.
- [x] Exact GMP/GMPXX compile GREEN: run `38091230910` (job `114327961939`), semantic source `7ac899b2d91e9d8c0925bbb4cc1ccd367872dcc4`, eight requested targets built, preflight/build exits `0/0`, `DIRECTIONAL_ENABLE_GMP=ON`, both `libgmpxx` and `libgmp` linked, clean source, 28/28 checksums, `runtimeExecution=false`; result artifact `11684470998` (ZIP SHA-256 `98434eea000957664acee32c57cba233642142da0ef40afcc4fb9d663f9e9fc2`) and log artifact `11684296178` (ZIP SHA-256 `5b6abc8f86fd852a002ee48709089a4d0628fe710f487c07ac17395fe9554d89`).
- [ ] Runtime-verify actual first A5 rejection in a **separately authorized** immutable Test + Benchmark turn; current Code + Build cannot run any executable. R4 remaining 39 endpoint, 34 Phase10, seven DCEL, 88 CP2, multi-carrier/odd-τ and dual-path review unchanged.

---

## HISTORY — R4 complete draft authority and A3-correct D2 mutation oracle (2026-10-10)

- [x] Exact source `a6b803fb08ccbc99d87a4fa9e1635c451e902c60`: `PhaseFrontDraft` now carries produced `conformityPlanReceipt`, terminal contacts, and closed-rail chains through factory reconstruction; D2 asserts a real reconstructed product and checks that forged odd rail chi fails the immutable A3 check at A4, rather than claiming impossible A5 rejection. Drive apply `38089504108` succeeded. Compile-only; tests not executed.
- [x] Exact compile GREEN: workflow `38089604435`, job `114323207863`, source `a6b803fb08ccbc99d87a4fa9e1635c451e902c60`, 8/8 GMP/GMPXX targets, 0/0 exits, 28/28 package checksums, clean source, `runtimeExecution=false`, result artifact `11682953835` (ZIP SHA256 `9e3c258011e6b0ca8d010a66f50110dde3f824591fa3e594ee267fcd060eef7c`), log artifact `11683118643` (ZIP SHA256 `ca9813122d080e9d2da946776334f19c49e3e6955ecacff184091c965fc1ca3d`).
- [ ] R4 remains open: A5-reachable causal negative, 39 endpoint effects, 34 Phase10 positive recoveries, seven dual-triangle DCEL negatives, 88 CP2 accepted losses, genuine source-valid multi-carrier/odd-tau, independent adjudication of impossible-looking dual-path witness, and separately authorized frozen 497 TB. Never count compile as runtime acceptance.

---

## HISTORY — R4 D2 attached-tau relational witness correction (2026-10-10)

- [x] Source `e3d2a1bcdb6965ec48f11af5add0113c4eae2785` corrects D2 odd-carrier witness to use full A2b source-star attachment transport in the A5 endpoint equation while keeping odd carrier chi as a separate mutation guard. Source patch applied in run `38088012591`; Drive staging retired; tests not executed.
- [x] Compile-only GREEN: `38088126976` job `114318883131`, exact `e3d2a1bcdb6965ec48f11af5add0113c4eae2785`, 8/8 GMP/GMPXX, exits 0, 28/28 manifest, clean source, `runtimeExecution=false`, result artifact `11683325306` ZIP SHA256 `0486bc6e5780ccced5d5dd30a74d83248fbf465ecf2ee34157bf2def0c93a2b8`, log `11683815002` ZIP SHA256 `cbdbf250a2539f473d310c6e5ab0940e7b330d8c8f35c5ca5e7fe2b7352301e4`.
- [ ] R4 remains open: prove genuine odd-tau/multi-carrier transport in runtime and restore 39 endpoint, 34 Phase10, seven DCEL, 88 CP2 regressions; obtain independent design decision on allegedly dual-admissible paths in a cut two-manifold vertex link. Do not run frozen 497 in Code + Build.

---

## HISTORY — R4 D2 terminal A2b/A3 typed row-permutation attestation (2026-10-10)

- [x] Compile-only D2 regression extension applied at source `5a8f79f62a671345da9bb1c2ded320e2d8daccdc`, Drive apply run `38086310642`. Checks non-hard source-vertex A2b path steps bidirectionally against the independent A3 atlas and compares normalized typed step multisets across face-row permutations. Requires a produced nonempty step. No runtime tests.
- [x] **Compile VERIFIED:** Exact GMP/GMPXX compile GREEN: workflow `38086431310`, job `114313866942`, source `5a8f79f62a671345da9bb1c2ded320e2d8daccdc`, 8/8 requested targets, preflight/build exits 0/0, clean source, 28/28 manifest, `runtimeExecution=false`, result artifact `11682567721` ZIP SHA256 `37d9c9f0f163c3d8fccca4072494744d22233d44d48c808a04a8d24b4275eb2f`, log artifact `11682517856` ZIP SHA256 `992bc2ad7000ca12fedc94c0ce6deff8e0e74f4cc1803eb90c98f0c2faa839dc`. No test/benchmark executed.**
- [ ] R4 obligations still pending: genuine source-valid multi-carrier/odd-τ and 39 endpoint/34 Phase10/7 DCEL/88 CP2 regressions, complete eight-target production build and formally authorized separate frozen 497 acceptance. Dual simple non-hard path witness on a cut manifold vertex link needs independent design clarification; do not fabricate/mark complete.

---

## HISTORY — R4 D2 multi-carrier endpoint A2b checked-factory test correction (2026-10-10)

- [x] Source `e1e2821a4b3e28aec9a18c871eb259bdb9fb1925` restores real terminal-contact and closed-chain authority in the existing D2 factory tamper/regression test; validates nonrail A2b path endpoint composition instead of deprecated direct-face equality. Applied run `38084818029`; Drive staging retired.
- [x] Eight-target compile: GREEN — 8/8 GMP/GMPXX targets, preflight/build exit 0, 28/28 ZIP manifest, clean source, runtimeExecution=false; workflow 38084965438 (job 114309529227), result artifact 11681609714 (SHA256 31562ad01a696a8c39dbe946c9ece0026eaf1963aa5cb13b932de7f35de5197f), log artifact 11681871272 (SHA256 071f6ebc48068114bda8156227e202a5af9bf07bd8ecf3ab7dfebb3bb9ce7591), exact semantic source e1e2821a4b3e28aec9a18c871eb259bdb9fb1925.
- [ ] Complete source-valid multi-carrier/odd-τ proof, 39 endpoint/34 Phase10/seven DCEL/88 CP2 regression repairs; independent review of potentially unrealizable dual-admissible-path witness; no TB497 in R4.

---

## HISTORY — R4 forged terminal-germ negative oracle (2026-10-10)

- [x] Source `1da010b6b607aca3f5a2e3078b32f5fb94d4d34b` adds a producer-nonvacuous checked-factory negative for an omitted A2b terminal path and a forged A3 side-germ step. Drive-apply `38083050527` succeeded; source patch owner deleted. Compile-only; tests not executed.
- [x] Exact eight-target GMP/GMPXX compile `GREEN: eight targets, GMP/GMPXX, 28/28 archive checksums, clean source, exits 0, runtimeExecution=false` (run `38083162432 (job 114304131242)`, artifact `11680664166, ZIP SHA256 ebbf236e3a389fcff744ca2ae47acf2014dea2f487cb759d9ee0795651d3f33e`). Do not start TB497.
- [ ] Build a source-valid dual-admissible-path negative to exercise *independent* uniqueness, plus multi-carrier/odd-τ positive carriers; close seven DCEL negatives, 34 Phase10 positive recoveries, 39 endpoint and 88 accepted CP2 regressions. These are not discharged by an extra compiled test.

---

## HISTORY — R4 A2b checked-factory uniqueness increment (2026-10-10)

- [x] Exact source patch `c28f1d241e6d84503e4ab38ce02b7200b8c9cfe5`
  independently re-derives unique nonhard A2b source-star paths at factory,
  rejecting hidden alternative paths, with one compile-only positive regression;
  Drive apply workflow `38081631821` success and owner staging cleanup complete.
- [x] Eight-target GMP/GMPXX compile GREEN at run `38081759082` (job `114300020996`, artifact `11680344767`, 28/28, runtimeExecution=false), mailbox
  `.workflow-mailbox/m6-cp3-r4-factory-unique-star-compile/latest.json`,
  exact source `c28f1d2...`; request commit `3f136c63...`. No tests executed.
- [ ] R4 production work remains: causal 39 endpoint, multi-carrier/odd-τ,
  34 Phase10 positives, seven negative fixtures, 88 CP2 restorations,
  full compile and separate immutable 497-case TB permission.

---

## HISTORY — R4 typed terminal source-star germ (2026-10-10)

- [x] Bounded A4 terminal source-star paths with typed endpoint vertex and
  A3-authenticated non-rail transitions landed at semantic source `991f6551...`;
  A5 consumes attached transport rather than bare carrier χ.
- [x] Eight-target GMP/GMPXX compile **GREEN**, run 38080007254, job 114294869088, result artifact 11680003032, 28/28 checksums, `runtimeExecution=false`; exact source 991f6551... .
- [ ] Verify actual direct-plane / 39-carried endpoint behavior only in separately
  authorized artifact-only TB. Do not infer runtime success from compile.
- [ ] R4 remains open: 88 accepted CP2 restorations, seven fixture oracles,
  multi-carrier positive source witnesses, full code/compile and immutable TB gate.

---

## HISTORY — `M6-CP3-CB1-ENTRY-R4` resumed (RA-45, 2026-10-10)

- [ ] **Continue same Code + Build turn.** The earlier `M6-DEFN-R5-R4-REV` HOLD at the top of the historical TODO sections below is superseded by independent RA-43/RA-45 decisions. `M6-CP3-CB1-ENTRY-R4` is released and IN_PROGRESS, not complete.
- [x] **Second incremental exact legacy-corner change compiled:** `rail_sample_source_vertex` no longer promotes tolerance-close samples to vertices; the existing Phase14 fixture covers untyped near-corner rejection and exact-corner acceptance. Semantic source `68533fd7faf80efa8b7388f8af83f0bfd269bca4`, GMP/GMPXX compile `38078250813`, artifact `11678578265`, 28/28 manifest, runtime-free. **No runtime proof or R4 closure.**
- [x] **Incremental typed-rail contract landed:** produced ordered `sourceVertices` now attest exact source edge/corner incidence and malformed/mismatched topology is typed rejected; a compile-visible negative regression was added. Initial compile failure was corrected at semantic source `aab8e22c1a997ffcca72cc42a13df51bf0e4d29b`; eight-target compile `38077156162`/artifact `11679541934` passed 28/28 manifest; see `.agents/Directional/Architecture_M6_CP3_R4_Typed_Rail_Incremental_Code_Build_Record.md` for exact verification.
- [ ] **RA-43.4 remains OPEN:** migrate direct-rail legacy fixtures with absent sourceVertices and retire their untyped floating-corner incidence (the epsilon tolerance has been removed but untyped identity is still not source-attested); authenticate producer-owned source-star terminal-contact/A2b germ and A3 φ, preserve all seven DCEL fixture negatives, restore 88 CP2 accepted-green cases, and prove non-vacuous odd-τ/multi-carrier witnesses.
- [ ] **Frozen 497 gate remains deferred** until R4's complete eight-target GMP/GMPXX compile-only closure. No TB/benchmarks/selector mutation. CP2 491/491 accepted, R3 403/497 rejected, 94 RED / 88 CP2 regressions, stable 66/17/49, debt 1.

---

## HISTORY — R5/R4 source-exact Review STOP (2026-10-10)

- [ ] **R4-REV-01A:** independently attest source-entity conversion of raw rail face/edge IDs and uniquely associate an oriented front endpoint with one rail vertex/interval and side germ; reject missing or ambiguous producer contact, no barycentric-epsilon authority.
- [ ] **R4-REV-01B:** identify actual existing source-star/rail-cut producer (the previously cited `SurfaceCellTracing.cpp:18120-18206` is isolation-seam processing), or explicitly design the missing producer without claiming it exists.
- [ ] **R4-REV-02A:** retain unconditional RA-40/RA-42 matched-atlas obligation (HELD plan corrected); independently attest `sourceFaceBranchRotations` and indirect periodic/isolation gauge dependencies.
- [ ] Remain in `M6-DEFN-R5-R4-REV` REVIEW_BLOCKED with successor UNKNOWN; zero produced multi-carrier witness, R4 Code + Build HELD; no frozen selector or runtime change. Historical items below are carried evidence, not permission to implement.

---

## HISTORY — mandatory M6 R4 independent Review blockers (2026-10-10)

- [ ] `R4-REV-01`: authenticate the **producer-owned** terminal source-vertex side germ, actual trace endpoint occurrence, unique ordered nonrail A2b path and bidirectional A3 φ. Face `2 -> 3` via `(1,5)` is **only** a geometrically valid candidate, not a published producer certificate. Keep RA-38.3 multi-carrier boundary through-junction prohibition; distinguish terminal boundary germs.
- [ ] `R4-REV-02`: explicitly adjudicate conflict between RA-40.1's mandatory matched A3 at `make` and RA-41.1's proposed null-atlas exemption. Prove complete gauge/periodic/isolation source dependency or retain RA-40 and migrate legacy inputs. Typed first-failure instrumentation for all 34 Phase10 observations remains required.
- [ ] `M6-DEFN-R5-R4-REV` remains review-blocked; RA-41 unfrozen, `M6-CP3-CB1-ENTRY-R4` HELD. No successor is authorized pending both independent architecture decisions. Last accepted CP2 491/491, rejected R3 403/497; 66/17/49 debt 1 unchanged. Review record `Architecture_M6_DEFN_R5_R4_Independent_Review_Record.md`.

---

## HISTORY — R4 Definition candidate for independent Review

- [x] `M6-DEFN-R5-R4`: draft source-exact RA-41 authority-domain, local-endpoint-contact and DCEL-valid fixture **Definition proposal**; no code, build or runtime; current candidate is not independently accepted.
- [ ] **Mandatory `M6-DEFN-R5-R4-REV`**: adjudicate conditional A3/gauge provenance and producer-owned terminal rail side-germ/A2b/A3 contact proof before releasing the one HELD `M6-CP3-CB1-ENTRY-R4` plan. A missing implementable source witness is an architectural STOP, not a reason to accept fake source/gauge.
- [ ] Future R4 code/compile and separate artifact-only frozen 497 TB/independent Review must restore 88 CP2 accepted RED, all 94 distinct R3 REDs, six CP3 entry witnesses. Preserve 66/17/49 debt 1; four RA-40(C) supplementals remain separate/unexecuted diagnostic-only.

## HISTORY — 2026-10-10 independent Review `M6-CP3-TB1-ENTRY-R3-REV`: R3 REJECTED

**Review verdict: R3 candidate is REJECTED / UNPROMOTED, but artifact-only execution is mechanically valid.** Frozen 497 fresh processes: **403 PASS / 94 RED** (30:15/15, 12:10/2, 449:378/71, 6:0/6); 1019/1019 result checksums and 497/497 individual log hashes independently verified; no test skipped or rebuilt. Exact source `d82e34427adc6fe09ad216a4363fea23dd0ae0b8`; runtime `38030196207`, artifact `11661044443`, SHA256 `555b973a69810f95a2f170fdea30aac11c0805ba7e25bc9914577bdd1bb26ac5`. **53/53 historical R2 RED remain RED, zero recovered; 41 additional accepted CP2 tests turn RED, making 88/491 accepted CP2 identities RED in R3** (47 R2-carried + 41 new). The prior 94-row EXEC report incorrectly tagged these 41 as `CP2_ACCEPTED=false`; its historical file is preserved, with a distinct independent 94-row corrected overlay. New accepted-loss families: 34 A4 publication/authority ingress failures (`R3-REV-NEW-01`) and seven synthetic mesh DCEL fixture exceptions (`R3-REV-NEW-02`); first rejected predicates observed, exact algorithmic roots not yet proven. Stable events now **66 / 17 / 49** (two grouped new recurrences), debt **1**. CP2 **491/491** remains latest reviewed accepted candidate; R3 may not be promoted. The 39 carried R2 rail endpoint errors are not counted a second time. Four RA-40(C) supplemental tests remain unexecuted and excluded from 497.

**Review authority:** `.agents/Directional/Architecture_M6_CP3_TB1_Entry_R3_Independent_Review_Record.md` and `.agents/Directional/Architecture_M6_CP3_TB1_Entry_R3_Independent_94_Review_Overlay.tsv`. **Authorized successor only after final COMPLETE beacon:** `M6-DEFN-R5-R4` Definition, plan `.agents/Directional/Architecture_M6_DEFN_R5_R4_Recovery_Definition_Plan.md`; independent R4 Definition Review required before any Code + Build. No new implementation, runtime, benchmark, promotion, selector alteration or fake A3 atlas is authorized in this Review.

---

- [x] Independent R3 review re-derived 497 process identities, 94 raw failures, accepted CP2 identity mapping; two new recurrence events and 94-row corrected overlay.
- [ ] `M6-DEFN-R5-R4`: resolve mandatory-A3 ingress for 34 previously accepted producer positives, DCEL-valid source fixtures for seven, and existing endpoint-0 rail misattachment for 39; conduct independent Definition Review before changes.
- [ ] Restore every prior CP2 accepted test (88 RED), all 53 historic R2 failures and all six CP3 organic witness gates through later source-exact GMP compile and separate artifact-only 497 TB. Four supplemental diagnostic tests require separately counted non-acceptance TB.

## HISTORY — `M6-CP3-TB1-ENTRY-R3-EXEC` frozen TB evidence (2026-10-10 06:20Z)

**EXEC mechanically COMPLETE; candidate REJECTED / UNPROMOTED.** Immutable run `38030196207`, result artifact `11661044443` provider ZIP SHA-256 `555b973a69810f95a2f170fdea30aac11c0805ba7e25bc9914577bdd1bb26ac5`, self-manifest **1019/1019**, exact source `d82e34427adc6fe09ad216a4363fea23dd0ae0b8`, 497 fresh exact-one processes, zero skips/configure/compile/relink/benchmarks/mutations. **403 PASS / 94 RED** = focused30 15/15, focused12 10/2, selector449 378/71, CP3entry6 0/6. All **53** historical R2 REDs remain RED, all **47** formerly CP2-accepted remain RED; **41 newly RED** identity-exact vs R2. Review-only provisional groups (39 A4 route cert, 22 A4 not-produced, 14 InvalidFinalCellState, 7 DCEL exceptions, 5 odd-τ witness absent, 4 A5 occurrence-mismatch, 2 A5 seam equivalent, 1 other). Complete 94-row raw-hashed first-failure inventory in `.agents/Directional/Architecture_M6_CP3_TB1_Entry_R3_Red_Classification.tsv`; historical 53 comparison in `.agents/Directional/Architecture_M6_CP3_TB1_Entry_R3_R2_Identity_Comparison.tsv`. Full report `.agents/Directional/Architecture_M6_CP3_TB1_Entry_R3_Execution_Record.md`. **Mandatory independent successor `M6-CP3-TB1-ENTRY-R3-REV`; no unreviewed fix, no promotion, no replay.** Four RA-40 supplemental tests remain separate/unrun. Stable ledger 64 events /17 categories /47 recurrences, debt 1, unchanged pending Review.

---

## CURRENT authoritative RA-40 Code + Build result — 2026-10-10 06:02Z

**COMPLETE / compile GREEN / runtime unexecuted** for `M6-CP3-CB1-ENTRY-R3`, pending durable docs push and final root STATUS beacon. RA-40 A/B/C Review completed; exact source `d82e34427adc6fe09ad216a4363fea23dd0ae0b8` includes five-file source-attested A3 factory/11-caller migration patch `7de636c88fe6ad8c4f09c1956161f56f88995785` and one-file fixed-size Eigen test-helper correction. Initial eight-target compile `38028700056` failed on dynamic `.cross()` Eigen static assertion; corrected compile **run `38029281891` succeeds** (`compile / compile` job `114146685417`), immutable result artifact **`11661566000`** outer ZIP SHA-256 **`18591009acf98b4c6ea996bc4bb1445959bbd49b1f96cc78327caacfb302ac95`**, internal **28/28 SHA256SUMS**, metadata `source-commit.txt` exact match, `preflight-exit-code=0`, `build-exit-code=0`, eight approved targets, `DIRECTIONAL_ENABLE_GMP:BOOL=ON`, actual generated linker command contains both `/usr/lib/x86_64-linux-gnu/libgmpxx.so` and `/usr/lib/x86_64-linux-gnu/libgmp.so`, `exactArithmeticBackend=GMP`, `runtimeExecution=false`, `turnBoundary=Code+Build-only`. No tests, benchmarks, Directional binaries, or TB harness executed.

**Authorized successor:** `M6-CP3-TB1-ENTRY-R3-EXEC` — distinct artifact-only frozen 497-process TB; four supplementary RA-40(C) tests must be separately scheduled and counted with diagnostic-only weight; do not merge into 497. Organic produced witnesses, historical R2 first failures, and 47 accepted→RED restorations remain entirely unverified until TB; no promotion or test pass claim. Any prior local entries below describing the second compile as pending are historical and superseded by this record.

---

# LIVE — RA-40 A3 factory patch applied; R3 GMP compile pending (2026-10-10)

 **Update (2026-10-10 05:58Z):** Initial GMP run `38028700056` failed only on Eigen compile-time vector-size assertion in test `FlowRepStrandsPhase15Tests.cpp:79` (`preflight_exit=0`, `build_exit=1`, `runtimeExecution=false`); one-file typed `Eigen::RowVector3d` correction applied successfully by workflow `38029206658` and semantic commit `d82e34427adc6fe09ad216a4363fea23dd0ae0b8`. Repair patch SHA256 `1cdb28c1c4ac8a1752f8201de3602053a4c10b1a2abcd8a9a2f01f37adb4cb26`; staging retired. Second immutable eight-target compile request event `b94820aaf64ee4c68f670e7c69b49b0f5f50b81a` pinned to `d82e344...`, mailbox `m6-cp3-r3-ra40-eigen-repair-gmp-compile-r2`, terminal result pending. No runtime work.


- [x] RA-40 A/B/C independent Review: factory source-bound A3 validation; CB compile-only acceptance; four supplementals separately counted diagnostic-only.
- [x] Verified 65,361-byte source/test patch (`6c88a8fb...`) applied to exact five intended paths at `7de636c88fe6ad8c4f09c1956161f56f88995785` via `38028610928`; Drive staging deleted.
- [ ] Await mandatory eight-target GMP/GMPXX compile/package on pinned source `7de636c...`, dispatcher event `8ff01b62485d79eaccb610e3f515e54dffa52672`, `runtimeExecution=false`; verify jobs, GMP linkage and immutable manifests. Current R3 not yet complete; do not run TB.
- [ ] After compile evidence, finish Code+Build records and exact authorized TB successor. Future frozen 497 and four separate supplemental cases require artifact-only execution and independent Review. D1/D2/D3/D5/A6/A7, 39 historical first loci, odd τ and 47 restorations unverified; stable 64/17/47 debt 1.

---

# LIVE — R3 independent A/B/C decisions remain pending (2026-10-10T01:46Z)

- [x] Latest source `089779c15eae27a2bb3b798ef9c8085950e92def`, eight GMP/GMPXX targets GREEN run `38005003624`, package `11650409049`, SHA256SUMS 28/28, `runtimeExecution=false`. Static audit exact source, **12 factory callers** (1 production, 11 tests). Migration report `.agents/Directional/Architecture_M6_CP3_R3_A3_Factory_Callsite_Migration_Impact_20261010.md`; no source changes or tests run.
- [ ] Independent A: factory nonrail A3 trust boundary; independent B: compile-only Code+Build acceptance vs later real-witness TB; independent C: four supplemental compiled tests outside frozen 497. **No verdict or successor authorized.**
- [ ] Organic D1/D2/D3/D5 A6/A7, all 39 R2 historical first loci, 47 CP2 accepted-green recovery cases and future separate frozen 497-process TB **not runtime verified**. Do not alter frozen selectors or invent results.

---

# LIVE — R3 latest-source static acceptance boundary (2026-10-10T00:09Z)

- [x] Source `089779c15eae27a2bb3b798ef9c8085950e92def`: eight GMP/GMPXX targets compiled GREEN in run `38005003624`, package `11650409049`, 28/28 internal hashes, `runtimeExecution=false`. Verified last patch adds six diagnostics but changes no positive predicates.
- [x] Fresh frozen **497=30+12+449+6** static owner census: 497 unique single-packaged definitions; 53 historic R2 REDs including 47 former CP2 greens selected; 4 supplemental tests unselected. Report `.agents/Directional/Architecture_M6_CP3_R3_089_Exact_Source_Static_Census_20261010.md`, reproducible CSV/script in Library `/Directional/Evidence/`.
- [ ] SAME R3 IN_PROGRESS, no successor. Independent A3 factory trust (A), CB closure vs separate runtime 497 TB (B), and 4 supplemental cases (C) remain unadjudicated. Organic D1/D2/D3/D5/A6/A7, 39 R2 first-failure loci and 47 accepted-green restorations **not executed/proven**; no schema/selector/runtime mutation authorized.

---

# HISTORICAL — R3 D3/D5 fail-context GMP compile (2026-10-09T23:21Z)

- [x] Added six typed first-failure message contexts to unchanged D3/D7 and D5 selected `ASSERT_NE` assertions, semantic commit `089779c15eae27a2bb3b798ef9c8085950e92def`, exact patch retained in Library `/Directional/Evidence/`. Apply run `38004878130` succeeded, consumed Drive patch deleted.
- [x] Eight mandatory GMP/GMPXX targets compiled GREEN run `38005003624`, artifact `11650409049`, 28/28 internal hashes, clean source, `runtimeExecution=false` (no binary executed).
- [ ] SAME `M6-CP3-CB1-ENTRY-R3` IN_PROGRESS. A/B/C independent decisions still pending, actual D1/D2/D3/D5/A6/A7 produced witnesses, 39 historic R2 first-loci and 47 accepted-green recoveries unverified; four supplemental tests outside frozen 497 pending authorization. Later immutable 497-case TB only after review. Details in current WIP and `Directional__M6-CP3-CB1-ENTRY-R3__continuation-20261009T2321Z.md`.

---

# HISTORICAL — R3 exact-source static 497 checkpoint (2026-10-09T21:48Z)

- [x] Verified current semantic source `f135946f1007c35960624a368df5f58318fd98e7` in eight-target GMP/GMPXX package `11644984310`, run `37991952457`, 28/28 internal hashes, `runtimeExecution=false`. Nine later doc/control commits, zero semantic source changes at check time. No new compile or runtime test.
- [x] Recomputed frozen 30+12+449+6: **497 distinct selected test identities**, all 497 statically owned once by default packaged sources; historical R2 53 REDs/47 CP2 accepted selected, four supplemental tests unselected. Library report `Directional__M6-CP3-CB1-ENTRY-R3__latest-source-frozen-497-census-20261009.md` and continuation `Directional__M6-CP3-CB1-ENTRY-R3__continuation-20261009T2148Z.md`. Refreshed A/B/C independent decision requests.
- [ ] SAME `M6-CP3-CB1-ENTRY-R3` IN_PROGRESS, successor UNKNOWN. Independent A3 factory trust (A), CB-vs-TB closure (B), supplemental four execution (C) unresolved; actual organic D1/D2/D3/D5/A6/A7, 39 historical first causes, 47 lost CP2 accepts, later frozen 497 TB **not run**. No stable ledger change.

---

# HISTORICAL — M6-CP3-CB1-ENTRY-R3 checkpoint (2026-10-09T21:00Z)

- [x] Typed A5/A6 torus downstream reporter change `f135946f1007c35960624a368df5f58318fd98e7`, applied `37991764540`; original test names and assertions preserved, Drive staging owner-deleted.
- [x] Eight-target GMP/GMPXX compile GREEN `37991952457`, package `11644984310`, 28/28 checksum, clean source, `runtimeExecution=false`; zero runtime tests. Historical 14 R2 organic/downstream cases inventoried alongside existing 39 report.
- [ ] SAME R3 IN_PROGRESS: A/B/C independent reviews, true produced D1/D2/D3/D5/A6/A7, 39 R2 first causes, 47 accepted-green restorations and separate frozen 497 TB remain unverified. See WIP and Library `Directional__M6-CP3-CB1-ENTRY-R3__continuation-20261009T2100Z.md`.

---

# HISTORICAL — R3 D1/D5 fail-only diagnostic compile (2026-10-09T20:17Z)

- [x] Source `9380c1a5a6ecb8ed50cc3290e9a7ff3808d24f20` adds fail-only D1 candidate-stage counts and D5 A5 first-error code; original tests, producer and frozen selectors unchanged. Patch full SHA256 `47d0ca34b0fc4d7f125ac395d25949dba9ff5557d58673270f875c33249cb402`, Drive apply run `37986806459` GREEN, staged file owner-deleted; patch backed up Library.
- [x] Mandatory GMP/GMPXX eight-target compile/package GREEN, run `37986977367`, result `11643991054`, 28/28 hashes, source clean, `runtimeExecution=false`; no tests/benchmarks run. Latest handoff `Directional__M6-CP3-CB1-ENTRY-R3__continuation-20261009T2017Z-final.md` in Library `/Directional/Evidence/`.
- [ ] SAME `M6-CP3-CB1-ENTRY-R3` IN_PROGRESS; A/B/C independent review unresolved, true D1/D2/D3/D5/A6/A7 organic witnesses, 39 R2 first-locus results, 47 CP2-green restorations and separate frozen 497-case TB still NOT EXECUTED. Frozen 497 static census from 19:31Z remains unchanged; 4 supplemental cases excluded.

---

# HISTORICAL — R3 frozen 497 static packaged-route census (2026-10-09T19:31Z)

- [x] Source-only static census on semantic `89b17c90a3941f080d47f47d10fea9f23cf2b818`: **497/497** unique identities, one packaged target each, receipt ordinal/target matches; all 53 R2 REDs and 47 formerly CP2-green identities are frozen-selected; 7 extra raw definitions historical-only; 4 supplemental cases outside frozen selector. Report and CSV in ChatGPT Library `/Directional/Evidence/`. No binaries executed.
- [x] Latest GMP/GMPXX eight-target run `37970925842` package `11634853973` 28/28 manifest `runtimeExecution=false`; exact-head snapshot `37976299041` artifact `11639141520` 5779/5779 hashes; latest source/test/CMake unchanged.
- [ ] SAME R3 IN_PROGRESS; independent A/B/C review and organic D1/D2/D3/D5/A6/A7, historical 39 first-locus and 47 accepted→RED recovery still unverified; separate frozen 497 TB not authorized in this CB.

---

# LIVE — R3 exact-head and 39-case compiled diagnostic checkpoint (2026-10-09T18:46Z)

- [x] Latest **semantic** source `89b17c90a3941f080d47f47d10fea9f23cf2b818`, GMP/GMPXX compile GREEN `37970925842`, artifact `11634853973`, **28/28** hashes, eight targets, source clean, `runtimeExecution=false`. Exact head snapshot `9417bf44e4a8dd7c85d6452c759eee65154fe2c7` verified `37976299041`, artifact `11639141520`, **5779/5779** hashes.
- [x] Source-level consolidated 39-reporter coverage audit `Architecture_M6_CP3_R3_39_First_Failure_Compiled_Diagnostic_Coverage_20261009.md`, exact historical 25+12+2 grouped; no new runtime/root-cause result and no selector/source/workflow change.
- [ ] SAME R3 IN_PROGRESS, successor UNKNOWN. Independent A/B/C gate Review outstanding (A3 trust, compile-only CB versus separate TB, four supplemental out-of-scope tests). Frozen 497 is unchanged. Actual D1/D2/D3/D5/A6/A7 producer positives, 39 first causes and 47 accepted-green recoveries are still UNPROVEN. Do not run tests/benchmarks in Code+Build.

---

# LIVE — R3 RE terminal first-failure diagnostics compile checkpoint (2026-10-09T17:59Z)

- [x] Source `89b17c90a3941f080d47f47d10fea9f23cf2b818` adds **only** fail-only diagnostic `SCOPED_TRACE` to the two historical RE terminal-code ordering assertions, ordinals 176/201, with unchanged assertions, cases and selectors. Drive apply `37970722412` succeeded; consumed patch owner-deleted; patch backed up Library.
- [x] Mandatory eight-target GMP/GMPXX compile/package **GREEN** run `37970925842`, artifact `11634853973`, 28/28 checksums, zero preflight/build exits, clean source, `runtimeExecution=false`. No tests or benchmarks executed.
- [ ] SAME R3 IN_PROGRESS. All R2 39 first-locus cases have compiled reporters (25 direct A4, 12 Phase10, 2 RE), but **zero new runtime proof**; independent decisions A/B/C, organic D1/D2/D3/D5/A6/A7, 47 accepted→RED recovery and future separately authorized frozen 497 process TB remain OPEN. Latest handoff `Directional__M6-CP3-CB1-ENTRY-R3__continuation-20261009T1759Z.md` in Library `/Directional/Evidence/`.

---

# HISTORICAL — R3 Phase10 dependent first-failure diagnostics compile checkpoint (2026-10-09T17:07Z)

- [x] Latest semantic commit `49d0c5077bd1ab4334f5affc45e7a3b3c2ed5f53`: fail-only source-attested diagnostics across 12 historically dependent Phase10 tests, original 148 test identities unchanged. Drive apply run `37965215474` GREEN; consumed patch owner-deleted; exact patch retained ChatGPT Library.
- [x] Eight mandatory GMP/GMPXX compile targets GREEN run `37965409601`, artifact `11633695568`, 28/28 internal hashes, clean source, GMPXX/GMP, `runtimeExecution=false`; no Directional tests or benchmarks executed.
- [ ] SAME `M6-CP3-CB1-ENTRY-R3` IN_PROGRESS, successor UNKNOWN. Independent A/B/C decisions; frozen 497 acceptance and four supplemental unselected tests, true D1/D2/D3/D5/A6/A7 witnesses, 39 R2 first loci and 47 CP2-green restorations remain unverified. Detail `Architecture_M6_CP3_CB1_Entry_R3_WIP_Continuation.md` and Library `Directional__M6-CP3-CB1-ENTRY-R3__continuation-20261009T1707Z.md`.

---

# HISTORICAL — R3 Phase10 A4 first-locus diagnostic compile (2026-10-09T15:36Z)

- [x] Test-only `SurfaceCellsPhase10Tests.cpp` first-predicate reporting on five historical direct-A4 Phase10 tests, six assertion sites; applied source **`f15bb63569ac4621349eebf78584b8743001705d`**, run `37953798528`; Drive stage deleted, patch Library backup.
- [x] Eight GMP/GMPXX targets compiled GREEN run `37954003990`, immutable package `11627142384`, 28/28 checksum, 0 exit codes, GMPXX+GMP, clean source, **`runtimeExecution=false`**. No Directional tests/benchmarks executed.
- [ ] SAME R3 IN_PROGRESS; independent A/B/C decisions OPEN. Actual D1/D2/D3/D5/A6/A7 positives, 39 historical R2 first loci, 47 accepted-green recoveries and separately authorized frozen 497 + four supplemental tests remain unverified. No successor.

---

# LIVE — M6-CP3-CB1-ENTRY-R3 diagnostic compile checkpoint (2026-10-09T14:57Z)

- [x] A4 fail-only Z4 square evidence `cec8255f6c4e0d7745da2788447ae4d65d47fbfa` applied via `37949576370` and exact GMP/GMPXX eight-target compile `37949800110` GREEN; result `11625746635`, 28/28 hashes, `runtimeExecution=false`; no tests run.
- [x] Historical R2 **25 direct A4** first-observable stop triage `Architecture_M6_CP3_R3_R2_Direct_A4_25_First_Locus_Triage.md` (17 shared constant fixture, 2 nonconstant fixture, 6 Phase10 entry). Not a resolved root cause or R3 run.
- [ ] SAME R3 IN_PROGRESS. Three independent A/B/C decisions still OPEN. Organic D1/D2/D3/D5/A6/A7, 39 historical R2 first loci, 47 CP2 previously accepted-green recoveries, supplemental four test decision and separate frozen 497 TB all remain unverified. No successor.

---

# LIVE — R3 verified input-star/static source checkpoint (2026-10-09T12:40Z)

- [x] Current semantic `32994a92dcc6492230ee768c476e65d31a38f59e` verified: snapshot `37921960048`, **5760/5760** hashes; GMP/GMPXX compile `37878691159`, result `11593975930`, **28/28** package hashes, `runtimeExecution=false`. No newer source edits versus current branch head.
- [x] Statically enumerated D2 3×3 *input* vertex-4 face-star into exactly two 3-face sectors around hard spokes `(1,4)` and `(4,7)`. This is **not** runtime proof of an A4-produced route; full evidence in `Architecture_M6_CP3_R3_Verified_Compile_and_CP3_Evidence_Reconciliation_20261009.md` and Library source-star note.
- [ ] SAME `M6-CP3-CB1-ENTRY-R3` IN_PROGRESS. A3 factory trust, CB/TB sequencing, supplemental 4 unselected tests await independent Review. Real D1/D2/D3/D5/A6/A7, R2 39 first loci and 47 lost CP2 greens remain unverified; frozen 497 separate future turn. No source/selector edits.

---

# LIVE — R3 exact-source race resolution (2026-10-09T11:01Z)

- [x] Older `2ae6f5d1` GMP/GMPXX compile `37861343725` passed 28/28 but is superseded. Stale patch apply run `37921603342` failed both hunks after 73 intervening commits; no semantic source pushed; staged Drive file permanently owner-deleted, patch retained Library as OBSOLETE/DO NOT RETRY.
- [x] Current source `32994a92dcc6492230ee768c476e65d31a38f59e` independently verified against fresh snapshot `37921960048`, **5760/5760** hashes; already checks all HardRail feature incidences (zero/>2 fail) and compiles eight GMP/GMPXX targets GREEN in run `37878691159`, package `11593975930` **28/28**, `runtimeExecution=false`. Temporary snapshot marker cleaned.
- [ ] Same R3 IN_PROGRESS, successor UNKNOWN. Independent A3 trust, CB/TB proof sequencing and supplemental four-case testing decisions still pending; frozen 497 selectors unchanged; organic witnesses, 39 R2 first failures and 47 regression recoveries unverified. Library continuation `Directional__M6-CP3-CB1-ENTRY-R3__continuation-20261009T1101Z.md`.

---

# HISTORICAL — M6-CP3-CB1-ENTRY-R3 source/coverage checkpoint 2026-10-09T09:24Z

- [x] Latest semantic `32994a92dcc6492230ee768c476e65d31a38f59e` compile evidence independently verified: GMP/GMPXX run `37878691159` package `11593975930`, 28/28 hashes, eight targets, clean source, `runtimeExecution=false`; older run `37861343725` superseded.
- [x] Static selection audit `.agents/Directional/Architecture_M6_CP3_R3_Frozen_497_Supplemental_Test_Coverage_Audit.md` (commit `a646e3a6`) documents four source-defined test identities outside immutable 497 (30+12+449+6) gate. No selector source changes or runtime.
- [ ] SAME R3 IN_PROGRESS: independent A3 factory trust and CB/TB sequencing decisions, plus whether a separately authorized supplemental test pass is required. Actual 39 historical R2 first-cause investigations, 47 accepted-green restorations and D1/D2/D3/D5/A6/A7 real-produced witnesses remain unverified; no successor.

---

# LIVE — R3 2026-10-09T04:44Z verified source and CP3 historic failures

- [x] Existing latest source `32994a92dcc6492230ee768c476e65d31a38f59e` still latest; eight GMP/GMPXX targets compile GREEN `37878691159`, package `11593975930`, 28/28, `runtimeExecution=false`. No reapplication of already-superseded factory all-edge patch rejected in `37882090618`.
- [x] Reconciled all six historical CP3 RED raw logs from immutable R2 archive `11545716507` (1019/1019 hashes) in `.agents/Directional/Architecture_M6_CP3_R3_Verified_Compile_and_CP3_Evidence_Reconciliation_20261009.md`. Historical only; no R3 runtime credit.
- [ ] SAME R3 IN_PROGRESS. Independent A3 factory attestation + Code+Build/TB sequencing verdict still required; genuine D1/D2/D3/D5/A6/A7, 39 R2 first causes, 47 lost accepted-green recoveries and frozen 497-case TB all unverified. No successor.

---

# LIVE — R3 stale-base conflict resolved without source edit (2026-10-09T03:59Z)

- [x] Prior checked-factory commit `2ae6f5d1...` compiled GREEN `37861343725`, package `11586413529`, 28/28 checksum.
- [x] Local proposed all-feature incidence patch on old base safely rejected by Drive `37882090618` at changed-path CAS before apply, not a compiler failure. Superseded code already applied in `648c84f1...` and `32994a92...`, newer GMP compile **GREEN** `37878691159`, package `11593975930`, 28/28 hashes, `runtimeExecution=false`. Abandoned staging file deleted by Drive owner; historical patch retained in Library.
- [ ] SAME `M6-CP3-CB1-ENTRY-R3` IN_PROGRESS, successor UNKNOWN. Do NOT reimplement already present all-feature 0/>2 incidence checks or treat compiled tests as runtime passes. Independent factory nonrail A3 trust / CB-to-TB gate decision and D1/D2/D3/D5 A6/A7 organic positives, R2 39 first causes and 47 CP2 accepted→RED restorations remain open; frozen 497-process TB separate. Detailed Library handoff `/Directional/Evidence/Directional__M6-CP3-CB1-ENTRY-R3__continuation-20261009T0359Z.md`.

---

# LIVE — R3 checked-factory zero-incidence guard compiled (2026-10-09T03:10Z)

- [x] Fixed checked `SurfacePhaseFrontProduct::make` to reject declared hard-feature edges absent from all source faces, matching A4 fail-closed topology; focused source-row-order negative tests compiled only. Semantic commit `32994a92dcc6492230ee768c476e65d31a38f59e`.
- [x] Corrected Drive apply run `37878562176` GREEN after first delimiter-only transport failure `37878348948`; both staging files retired, exact corrected patch in Library. Eight-target GMP/GMPXX compile run `37878691159` GREEN, package `11593975930`, 28/28 hashes, clean source, `runtimeExecution=false`.
- [ ] SAME `M6-CP3-CB1-ENTRY-R3` remains IN_PROGRESS: no runtime tests, no independent A3 factory trust decision, no CB/TB sequencing verdict, no organic D1/D2/D3/D5/A6/A7 witness results, no 39 R2 root corrections or 47 CP2-green restorations proven. Frozen 497-case separate TB and successor still unauthorised. WIP and Library handoff `Directional__M6-CP3-CB1-ENTRY-R3__continuation-20261009T0310Z.md` have exact evidence.

---

# HISTORICAL — R3 checked-factory all-HardRail preflight compiled (2026-10-09T02:06Z)

- [x] Source `648c84f1d5b3bb532c684bf0444658f864687760`: count actual face incidence for **all** declared hard-feature edges even without published transition, reject >2; expand existing checked-factory negative/control test for unissued 2/3 faces and face-row permutation. Drive apply `37873233397` SUCCESS, staging owner-deleted.
- [x] Eight GMP/GMPXX targets compile/package `37873391621` GREEN, artifact `11591586072` SHA256 `0af7235a6aa66f40415a7f7866644164bf4500d94cf20ae316e8b0e063fef18f`, **28/28** hashes, both exits 0, `runtimeExecution=false`; tests/benchmarks not executed.
- [ ] SAME `M6-CP3-CB1-ENTRY-R3` IN_PROGRESS, successor UNKNOWN. Independent A3/CB-to-TB Review pending, genuine D1/D2/D3/D5/A6/A7 witnesses, 39 historical R2 first causes, 47 CP2 accepted-green restorations and future frozen 497 TB unverified. Detailed WIP and Library `Directional__M6-CP3-CB1-ENTRY-R3__continuation-20261009T0206Z.md`.

---

# HISTORICAL — prior R3 checked factory compile checkpoint

- [x] `SurfacePhaseFrontProduct::make` now requires **exactly two** full source triangle incidences for every published HardRail transport (source `2ae6f5d1ba4e7657a5089fb52c09812a495dfe47`); typed 1/2/3-face, two source-row-order factory negative/control test compiled (not executed, not added to frozen selectors). Does **not** settle A3 phi provenance.
- [x] Drive apply run `37861219049` SUCCESS, consumed patch retired. Eight GMP/GMPXX targets compiled GREEN run `37861343725`, immutable artifact `11586413529`, package manifest 28/28, GMPXX/GMP, clean source, `runtimeExecution=false`; no runtime executed.
- [ ] SAME R3 IN_PROGRESS. Independent A3 factory-attestation and CB/TB sequencing review, organic D1/D2/D3/D5 A6/A7 witnesses, 39 historic R2 first-locus failures and 47 accepted CP2→RED restoration remain unverified; future separate 497 immutable TB, no successor. Full WIP/Library handoff `Directional__M6-CP3-CB1-ENTRY-R3__continuation-20261008T2339Z.md`.

---

# HISTORICAL — R3 independent review gate (2026-10-08T23:16Z)

- [x] Audited exact compiled source `7666939d9ee1a53148d2c85d7b6d40c509d8df10`; eight-target GMP/GMPXX compile already GREEN run `37856816696`, package `11584990429`, 28/28 hashes, `runtimeExecution=false`. Published `Architecture_M6_CP3_R3_A3_Trust_CB_TB_Gate_Review_Request.md`.
- [ ] Independent Review: choose A4-trusted versus factory-independent A3; adjudicate CB closure versus 497-process TB witness proof. No independent verdict or successor.
- [ ] SAME `M6-CP3-CB1-ENTRY-R3` IN_PROGRESS, true D1/D2/D3/D5/A6/A7, 39 R2 historical roots, 47 CP2-green restorations still unverified; frozen selectors unchanged.

---

# HISTORICAL — M6-CP3-CB1-ENTRY-R3 compile checkpoint (2026-10-08T22:52Z)

- [x] Guard overfull hard-feature source edge on singleton and paired HardRail before A4 publishes owner carrier: commit `7666939d9ee1a53148d2c85d7b6d40c509d8df10`. One-face boundary behavior unchanged; no public certificate change. Applied via Drive `37856665013`, staging owner-deleted; exact patch archived in Library.
- [x] GMP/GMPXX eight-target compile/package run `37856816696` GREEN; immutable artifact `11584990429`, 28/28 SHA256SUMS, GMPXX+GMP direct link, clean sources, `runtimeExecution=false`. No tests/benchmarks run.
- [ ] SAME R3 IN_PROGRESS. Proposed 3+ face overfull guard negative and 1/2 face controls are FUTURE TESTS, not executed. Independent A3 factory attestation Review and D1/D2/D3/D5 A6/A7 producer witnesses; 39 R2 first failures and 47 accepted-green losses; frozen 497-case TB deferred to separate successor. Full handoff `Architecture_M6_CP3_CB1_Entry_R3_WIP_Continuation.md` + Library `Directional__M6-CP3-CB1-ENTRY-R3__continuation-20261008T2252Z.md`.

---

# HISTORICAL — R3 A4 nonmanifold source-spoke guard compiled (2026-10-08T22:26Z)

- [x] Source `91fafdc6e2a3f46c77444b2a0cf1038f09f85e6b`, sole A4 `src/geometry/SurfaceCellTracing.cpp` edit: reject junction spoke unless **all** source triangles give exactly two edge incidences; preserve first-failure count and typed edge. Drive apply `37853932935` GREEN; staged patch owner-deleted.
- [x] Eight GMP/GMPXX targets compiled/package GREEN run `37854111387`, result `11582993643`, 28/28 internal SHA256SUMS, clean source, `runtimeExecution=false`; **no tests or benchmarks executed**.
- [ ] SAME `M6-CP3-CB1-ENTRY-R3` IN_PROGRESS. Five suggested future runtime test cases in Library continuation `Directional__M6-CP3-CB1-ENTRY-R3__continuation-20261008T2226Z.md` (no selector edits). Retain independent A3 factory trust Review, true D1/D2/D3/D5 A6/A7 witnesses, 39 R2 first causes, 47 CP2-green recoveries; frozen 497-case TB separate and not begun. No new stable regression evidence.

---

# HISTORICAL — M6-CP3-CB1-ENTRY-R3 bounded Code + Build (2026-10-08T22:02Z)

- [x] Source audit of RA-39 endpoint-local terminal-carrier contract against compiled semantic source `d56f57adc184d6180fc2c69087a5340b8e97bcc7`: **already reviewed and implemented at certificate shape level**, not an unimplemented fan detour. GMP/GMPXX compile `37849106999`, artifact `11581102206`, internal **28/28** hashes, `runtimeExecution=false`.
- [x] Historical R2 497-run source evidence independently rechecked **1019/1019** hashes; 53 RED records classify 25+12+2 A4/Phase10/RE and 14 other REDs; all R3 current-runtime first predicates remain **UNVERIFIED**.
- [ ] Same R3 IN_PROGRESS, NO successor. Independently resolve public factory A3-trust contract; do not change certificate schema without authority. Genuine D1/D2/D3/D5, A6/A7, odd-τ, 39 first-locus REDs, 47 CP2 accepted→RED recoveries and separate frozen 497 TB remain open. Evidence `Architecture_M6_CP3_CB1_Entry_R3_WIP_Continuation.md`; Library `Directional__M6-CP3-CB1-ENTRY-R3__RA39-A3-static-audit-and-review-gate-20261008T2202Z.md`.

---

# HISTORICAL — M6-CP3-CB1-ENTRY-R3 Code + Build (2026-10-08T21:39Z)

- [x] A4 first-invalid source-spoke/topology diagnostics compiled GREEN on `d56f57adc184d6180fc2c69087a5340b8e97bcc7`, 8 GMP/GMPXX targets, run `37849106999`, artifact `11581102206`, 28/28 hashes, `runtimeExecution=false`.
- [ ] SAME R3 IN_PROGRESS: factory A3 attestation independent Review; real produced D1/D2/D3/D5 and A6/A7 witnesses; 25+12+2 first-failure investigations and 47 CP2 accepted-green recoveries; future separate immutable frozen 497-case TB. No runtime proofs from compile.

---

# LIVE — M6-CP3-CB1-ENTRY-R3 Code + Build (2026-10-08T21:26Z)

- [x] Test-only D2 balanced A3 falsifier e49431df81a3e23dc7870a4e409128dea618d378, eight GMP/GMPXX targets GREEN run 37846303377, result 11580420381, 28/28 manifest, runtimeExecution=false.

- [ ] SAME R3 IN_PROGRESS. Factory A3 independent attestation and CB/TB produced-witness sequencing need independent Review. No D1/D2/D3/D5 organic positives, 39 R2 first causes, 47 CP2-green recoveries, or future frozen 497-process TB accepted. See Architecture_M6_CP3_CB1_Entry_R3_WIP_Continuation.md.

---

# HISTORICAL — R3 Definition Review RA-37a / exactly one bounded CB (2026-10-08)

- [x] `M6-DEFN-R5-R3-REV` — independently reconstruct 3×3 typed vertex-star arcs; accept candidate with binding RA-37a local-endpoint vs along-route distinction; freeze A4/A5/A6/organic STOPs.
- [ ] `M6-CP3-CB1-ENTRY-R3` **EXACT NEXT AFTER BEACON** — implement only when A4 owns uniquely typed two sectors and independently valid endpoint-local paths; otherwise stop for producer Design Review. Remote GMP/GMPXX compile-only eight targets, followed by separate immutable 497 TB and independent Review. Do not begin CB2 or CP3 exit.

**`M6-DEFN-R5-R3-REV` ACCEPTS RA-37a as a *bounded, fail-closed source-topology contract*; this is not any new runtime promotion. Exact successor after final beacon: `M6-CP3-CB1-ENTRY-R3` Code + Build only, with mandatory source A4 two-sector and both endpoint-local path STOPs.** CP2 491/491 remains accepted; R2 rejected 444/497; 47 accepted-green losses; 64/17/47, debt 1. See `Architecture_M6_DEFN_R5_R3_Review_Record.md`. No organic D1/D2/D3/D5 positives or A6 recovery accepted.

---

## HISTORY — M6-DEFN-R5-R3 candidate RA-37 ready for independent Review (2026-10-08)

- [x] Read exact source snapshot `fade2a964355adeb4c94d5fc28f322343e60abae`; independently verify R2 ZIP checksums and 497/53 ledger. Write topology-owned A4 two-sided face-star transport definition and zero/single/multi-route falsifiers in `Architecture_M6_DEFN_R5_R3_CP3_Entry_Recovery_Definition_Record.md`; no product/fixture/test/selector/build/runtime mutation.
- [x] Prepare one **HELD** `Architecture_M6_CP3_CB1_Entry_R3_Recovery_Code_Build_Plan.md` with A4→A5/A6 ordering, real producer witnesses, all-eight GMP compile and separate 497 immutable TB gate.
- [ ] **Exact next after this turn's STATUS closure:** independent `M6-DEFN-R5-R3-REV`; accept/amend/reject RA-37's A2b/A4 source-side uniqueness and both endpoint lane proofs. If side sectors cannot be proven, return to producer-owned architecture Review. R3 CB, CB2/CP3 exit stay HELD. No claim of organic D1/D2/D3/D5 positives or A6 recovery. Stable 64/17/47, debt 1; 47 accepted CP2→R2 RED must be restored in future TB.

---

## LIVE — R2 REVIEW REJECTED; independent Definition recovery next (2026-10-08)

- [x] `M6-CP3-TB1-ENTRY-R2-REV`: independent 3-artifact checksum and exact identity comparison, 53-RED classification; R2 unpromoted. **M6-CP3-TB1-ENTRY-R2-REV COMPLETE: R2 REJECTED 444/497; 53 RED; 47 previously accepted CP2 identities now RED.** Independent cross-run comparison: CP2 491/491, rejected R1 482/497, rejected R2 444/497; R1→R2 38 new RED, zero recoveries. Stable **+1 new RP-01 product event**, current ledger **64 events / 17 categories / 47 recurrences**, produced-witness debt **1**; prior A6 RP-01 remains OPEN. Exact source `80fc1688f13e5ed52699177a845f25cc4dbda38b`; mechanical R2 run/job `37767144537 / 113277596566`, result artifact `11545716507`, ZIP sha256 `d6469bea1b4ef6fb3b142d05a97d01dbab98331cfc91d930c7bc30da555ec0ca`, internal 1019/1019. Direct new A4 `InvalidHardRailRouteCertificate` producer regression on accepted HardRail fixtures; accepted RA-36.1 adjacent-carrier shared-face assumption is unsound for legal rail polyline (1,4) faces {0,3}, (4,7) faces {4,7}; input counterexample is NOT a demonstrated produced multi-step route. Organic D1/D2/D3/D5 positives unproved. Candidate UNPROMOTED; CB2/CP3 exit HELD. **Exact authorized successor (only after final STATUS closure): `M6-DEFN-R5-R3` runtime-free Definition, then mandatory independent `M6-DEFN-R5-R3-REV`; no implementation until acceptance.** Canonical review `Architecture_M6_CP3_TB1_Entry_R2_Review_Record.md`, row classification `Architecture_M6_CP3_TB1_Entry_R2_Red_Classification.tsv`, held plan `Architecture_M6_DEFN_R5_R3_CP3_Entry_Recovery_Definition_Plan.md`; complete full reviews mirrored in ChatGPT Library `/Directional/Evidence/`.
- [ ] `M6-DEFN-R5-R3` only after STATUS closure: produce typed A3 face-star-side transport candidate RA-37, exact route/endpoints/commuting-square proof, separately repair organic D1/D2/D3/D5 witness premises and A6 certificate-domain gap. **No code/runtime in Definition.**
- [ ] Mandatory `M6-DEFN-R5-R3-REV` before one allowed CB; then eight GMP/GMPXX targets, immutable 497 TB, separate TB Review. No CB2/CP3 exit until accepted.

---

## LIVE — R2 immutable TB executed: 444/497, 53 RED; mandatory independent Review next (2026-10-08)

- [x] `M6-CP3-TB1-ENTRY-R2-EXEC`: exact compiled artifact `11542824274`, source `80fc1688f13e5ed52699177a845f25cc4dbda38b`, 497=30+12+449+6 fresh processes. Dispatcher `37767144537`; job `113277596566`, terminal mechanical success. **444 PASS / 53 RED**, six CP3 entry identities **0/6**; exact-one 497/497, zero skip, zero benchmark, immutable pre/postflight, no local/runtime replays. Result artifact `11545716507`, ZIP SHA256 `d6469bea1b4ef6fb3b142d05a97d01dbab98331cfc91d930c7bc30da555ec0ca`, internal SHA256SUMS 1019/1019.
- [ ] **Exact successor after final STATUS: `M6-CP3-TB1-ENTRY-R2-REV`** independent Review. Verify 53 raw REDs, distinguish `InvalidHardRailRouteCertificate` (25 observed logs) and propagated phaseFront rejections, empty D1/D3/D7 witness searches, D5 baseline missing and downstream A6/A7 failures. Read `.agents/Directional/Architecture_M6_CP3_TB1_Entry_R2_Execution_Record.md`, [artifact](https://github.com/akashskypatel/Directional/actions/runs/37767144537/artifacts/11545716507). Do not classify stable events, fabricate organic positives, or change tests/fixtures/selectors in Review.
- [ ] R2 candidate stays **unpromoted**; CB2 / optimizer / CP3 exit held until Review authorizes a bounded successor. Accepted CP2 baseline 491/491; stable 63/17/46, debt 1 pending Review.

---

## LIVE — M6 CP3 R2 Code + Build compile-green; immutable 497-process TB next (2026-10-08)

- [x] Implement/push five-file RA-36 R2 correction at source `80fc1688f13e5ed52699177a845f25cc4dbda38b`; authoritative Drive apply `37762551926` GREEN.
- [x] Eight standard GMP/GMPXX targets compiled/linked; dispatcher `37762724429`, job `113262943750` GREEN; immutable artifact `11542824274` ZIP SHA-256 `8aa756b1085a75109648b4da7f07a2ffebcdf975ea04981ec88b2d2e61c89114` and manifest **29/29**. Clean source and `runtimeExecution=false`. See `.agents/Directional/Architecture_M6_CP3_CB1_Entry_R2_Code_Build_Closeout_Report.md`.
- [ ] **Exact successor after STATUS closure: `M6-CP3-TB1-ENTRY-R2-EXEC`** using artifact `11542824274` only, exactly **497=30+12+449+6** fresh exact-filter processes; immutable pre/postflight, exact-one, zero skips, benchmark zero. No recompile/repair/discovery. Witness nonvacuity and RA-36 multi-edge produced-route existence remain unproved; stop for Review on absent evidence.
- [ ] Mandatory `M6-CP3-TB1-ENTRY-R2-REV`; only its independent decision may promote/reject or authorize CB2/CP3 exit. Stable accounting **63/17/46**, debt 1.

---

## Current — R2 Definition Review ACCEPTED RA-34; bounded R2 Code + Build next (2026-10-08)

- [x] Independent source-only review accepts D1 one-orientation A4 certificate and D3 odd oriented τ Definition; R1 OBS-01/02 discharged Definition-only.
- [ ] Exact next `M6-CP3-CB1-ENTRY-R2` with independent typed A4 sheet mapping and real organic D2/D3/D4/D5 positives as mandatory stop gates; eight GMP/GMPXX compile targets ONLY.
- [ ] If compile GREEN, immutable 497-process TB then mandatory R2 Review. CB2/CP3 exit held; rejected R1 entry 482/497, accepted CP2 491/491, stable 63/17/46, debt 1.

## Current — `M6-DEFN-R5-R2` RA-34 candidate; mandatory independent Review next (2026-10-08)

- [x] Inspected exact-source snapshot `f3ae67ade2ac37f00d2317d0de007aaf959f8969`, no runtime or build.
- [x] D1 single typed seam certificate orientation, with raw sheet labels neither granting nor denying lookup and A4 producer-owned sheet-incidence stop; D3 real-produced odd τ and independent F/τ discriminant.
- [ ] `M6-DEFN-R5-R2-REV` to independently adjudicate RA-34; D2/D4/D5 organic positives remain unproven.
- [ ] R2 Code+Build and CB2 HELD. Frozen gate 497, rejected 482/497, stable 63/17/46, debt 1.

## Current — `M6-DEFN-R5-R1` candidate RA-33 prepared / mandatory independent Definition Review pending (2026-10-07)

- [x] Inspect exact snapshot `46717738454a96ab9a379a995eb903939e7a9413` for five RA-32 authority gaps. No product edits or runtime.
- [x] Draft source-evidenced `Architecture_M6_DEFN_R5_R1_CP3_Entry_Recovery_Definition_Record.md`, RA-33 candidate and exactly one HELD R2 plan.
- [ ] Mandatory `M6-DEFN-R5-R1-REV`: independently adjudicate candidate rules and the unresolved **organic produced-witness proofs** (periodic odd gauge pair, HardRail `F_b−F_a != τ`, seam-collinear OrdinaryFront, route-bearing ordinary). No R2 release before approval.
- [ ] R2 Code+Build and CB2 held; frozen entry gate 497, stable **63 / 17 / 46**, debt **1**.

## Current — `M6-CP3-TB1-ENTRY-R1-REV` COMPLETE / RA-32 / exact next `M6-DEFN-R5-R1` (2026-10-07)

- [x] Re-derive R1 mechanics: **482/497**, exact-one, zero skips, benchmark 0, immutable postflight.
- [x] Adjudicate all six groups: prior `RP-01` event remains open through ten failed-recovery rows; D1/D3/D4/D7 are non-stable witness/oracle gaps; D2 remains Definition-owned.
- [x] Mark predecessor incomplete-publication and focused-relabel events recovery-proved; stable totals unchanged **63 / 17 / 46**, debt 1.
- [x] Freeze RA-32 and consolidate superseded R1/prior-entry documents.
- [ ] **Exact next: `M6-DEFN-R5-R1`** (runtime-free) using `Architecture_M6_DEFN_R5_R1_CP3_Entry_Recovery_Definition_Plan.md`; mandatory `M6-DEFN-R5-R1-REV` follows. R2 implementation and CB2 remain held.

## Current — `M6-CP3-TB1-ENTRY-R1-EXEC` COMPLETE / 482 PASS + 15 RED / mandatory R1 Review next (2026-10-07)

- [x] Execute immutable `11488700954 / 68000a95...` through durable dispatcher run `37645974118` as exactly 497 fresh exact-filter processes.
- [x] Verify exact-one, zero skips, benchmark 0, result manifest 1019/1019, package manifest 28/28 and immutable package/source/execution-view postflight.
- [x] Record **482 PASS / 15 RED**: focused30 23/30, focused12 12/12, selector449 446/449, CP3-entry 1/6.
- [x] Classify every RED once into six non-stable R1 candidate groups; stable accounting remains **63 / 17 / 46**, debt 1.
- [ ] **Exact next: mandatory `M6-CP3-TB1-ENTRY-R1-REV`.** The RA-31a 496+identity2 acceptance shape was not met; no source/test repair or retry before Review.

## Current — `M6-CP3-TB1-ENTRY-REV` review-agent addendum / RA-31a / exact next `M6-CP3-CB1-ENTRY-R1` (2026-10-06)

- [x] Re-derive TB1: 1019/1019; frozen order; 373/497; the TSV covers every RED once with matching hashes.
- [x] Confirm CAND-01/02/04/06/07 and accounting 63 / 17 / 46.
- [x] Re-adjudicate CAND-05: the D2 certificate's gauge model is unproven (region-relative F vs cross-rail τ) → RA-31a withdraws it. Publish RA-31. Lesson 207.
- [ ] **Exact next `M6-CP3-CB1-ENTRY-R1`**: P1, P2, T1, T2 (with stop), T4; remove the certificate rejection; identity 2 pre-registered RED; identity 6 must pass.
- [ ] TB1-R1 497 → R1 Review → `M6-DEFN-R5-R1` (D2 redefinition) → D2 CB → CB2 (D5/D6/D8) → CP3 close.

## HISTORY — M6-CP3 entry recovery

- **Exact next:** `M6-CP3-CB1-ENTRY-R1` under RA-31.
- Fix only: complete A4 face-gauge publication in uniform/periodic regional producers; scope A6 OrdinaryFront isolation evidence to certified cross-sheet seams; repair focused30 ordinal12 relabel; repair D1/D2 produced witnesses; rewrite D4 barrier oracle.
- Compile/package all eight standard GMP/GMPXX targets; no generated runtime.
- Then immutable `M6-CP3-TB1-ENTRY-R1-EXEC`: exactly **497** fresh processes, benchmark 0, followed by mandatory `M6-CP3-TB1-ENTRY-R1-REV`.
- CP3 exit remains held. Stable accounting **63 / 17 / 46**, debt 1.

## Current — `M6-CP3-TB1-ENTRY-EXEC` COMPLETE / semantic RED / mandatory Review next (2026-10-06)

- [x] Execute immutable `11411137781 / 912760f1...` as exactly **497** fresh exact-filter processes with exact-one selection, zero skips and immutable postflight.
- [x] Record **373 PASS / 124 RED**: focused30 4/30, focused12 0/12, selector449 369/449, CP3-entry 0/6; benchmark 0.
- [x] Categorize all 124 RED rows into six non-stable candidate groups with row-level mapping and root-cause analysis; keep stable accounting **60 / 16 / 44**, debt 1.
- [x] Complete durable cleanup: RED-evidence commit `145f7af552483ead00a6605e0ec793cb9f4af595`, cleanup run `37470228257` / SHA `4eae760859ed48a7898d9383e583681111fe9023`, staged Drive patch owner-deleted, temporary workflow/marker/harness state removed. Retired predecessor CB1 plan/report and TB1 WIP handoff are recoverable at git commit `4eae760859ed48a7898d9383e583681111fe9023` and must be indexed by Review.
- [ ] **Exact next `M6-CP3-TB1-ENTRY-REV`:** independently adjudicate every candidate group and row mapping. CB2 remains held until Review.

## Current — `M6-CP3-CB1-ENTRY` COMPLETE / exact next `M6-CP3-TB1-ENTRY-EXEC` (2026-10-06)

- [x] Implement RA-30 + RA-30a entry authority at semantic source `912760f1ffc785676f5d50717177b1cd8be69234`.
- [x] Add exactly the six frozen CP3-entry identities; do not edit focused30/focused12/selector449/routing449 authority.
- [x] Compile/package all eight standard GMP/GMPXX targets: `37458495402 / 112251921276`, immutable result `11411137781`, manifest **28/28**, clean source, `runtimeExecution=false`.
- [x] Preserve the historical CB1 evidence report (retired at TB1 cleanup; recoverable at `4eae760859ed48a7898d9383e583681111fe9023`); retire the consumed Drive patch and temporary apply/compile control state while retaining mailbox history.
- [ ] **Exact next `M6-CP3-TB1-ENTRY-EXEC`:** consume immutable `11411137781 / 912760f1...` with no rebuild/repair and execute exactly **497** fresh exact-filter processes = focused30 30 + focused12 12 + selector449 449 + six CP3-entry identities 6.
- [ ] Mandatory `M6-CP3-TB1-ENTRY-REV`; CB2 (D5/D6/D8, final intended gate 507) remains held until Review.

## Current — `M6-DEFN-R5-REV` ACCEPTED with RA-30a / exact next `M6-CP3-CB1-ENTRY` (2026-10-06)

- [x] Review D1–D9 against source and gates; verify the 497/507 arithmetic.
- [x] V1–V8 → RA-30a:
  - D4 authority from A4;
  - D2 produced non-constant HardRail fixture;
  - D3 seam branch certification;
  - D9 historical target;
  - D6 accumulation order;
  - scheduler definition;
  - D1 witness;
  - D2 site.
- [x] Release the CB1 plan; lesson 206.
- [x] `M6-CP3-CB1-ENTRY` completed compile/package GREEN at `912760f1...` / artifact `11411137781`.
- [ ] TB1-ENTRY **497** → mandatory entry Review → CB2 (D5/D6/D8; final gate 507) → CP3 close.

## Current — `M6-DEFN-R5` COMPLETE / mandatory `M6-DEFN-R5-REV` next (2026-10-06)

- [x] Decide D1-D9 with producer reachability, per-conjunct falsifiers, bounds and stop rules.
- [x] Freeze current G4-B001 strict 3/3 identities without fabricating historical exact names.
- [x] Publish candidate RA-30 and held `Architecture_M6_CP3_CB1_Entry_Authority_Code_Build_Plan.md`.
- [x] Freeze CP3 entry **497** and intended final **507** process arithmetic; preserve inherited 491 authorities unchanged.
- [x] Self-audit lessons 199-205; no source/test/fixture/selector/build/runtime change; accounting **60 / 16 / 44**, debt 1.
- [ ] **Exact next: mandatory `M6-DEFN-R5-REV`.** Independently re-derive RA-30 and release or reject the held CB1 plan. Do not begin CP3 implementation before Review.

## Current — `M6-CP2-CLOSE-REV` ACCEPTED / CP2 CLOSED / exact next `M6-DEFN-R5` (2026-10-06)

- [x] Independently re-derive TB2: 491/491, exact-one 491/491, zero skips/RED/benchmarks, 1005/1005 result manifest, immutable postflight.
- [x] Close RA-29d OBS-01/02/03 as recovery-proved.
- [x] Write `Architecture_M6_CP2_Close_Review_Record.md` and `M6_CP2_Closure_Record.md`; OBS-04 closed.
- [x] Promote `11391685901 / 5ce3132e...` as reviewed CP2 verifier/runtime authority; accounting remains **60 / 16 / 44**, debt 1.
- [ ] **Exact next: `M6-DEFN-R5`** — carried CP3 definition/permutation/direct-production entry obligations.

## Current — `M6-CP2-TB2-COVERAGE-EXEC` COMPLETE / 491/491 / mandatory `M6-CP2-CLOSE-REV` next (2026-10-06)

- [x] Consume immutable `11391685901 / 5ce3132e...` without rebuild, repair, configure, relink, generated discovery, or selector/test/fixture mutation.
- [x] Execute exactly **491** fresh exact-filter processes: focused30 **30/30**, CP2-focused12 **12/12**, selector449 **449/449**.
- [x] Verify exact-one 491/491, zero skips, benchmark 0, immutable package/source/execution-view postflight, and no runtime retry.
- [x] Persist result/log artifacts `11393198123 / 11393312986`; result self-manifest **1005/1005**.
- [x] Record +0 regressions; stable accounting remains **60 / 16 / 44**, debt 1.
- [ ] **Exact next: mandatory `M6-CP2-CLOSE-REV`** — independently re-derive TB2, adjudicate RA-29d recovery, and write `M6_CP2_Closure_Record.md` only if CP2 exit is satisfied.
- [ ] `M6-DEFN-R5` remains held until Close Review accepts CP2 closure.

## Current — `M6-CP2-CB2-COVERAGE` COMPLETE / exact next `M6-CP2-TB2-COVERAGE-EXEC` (2026-10-06)

- [x] G1 exact `a7:vertex-binding`.
- [x] G2 remove `UncertifiedAuthoritySubstitution`; assign `BoundaryOrEulerMismatch` to component/boundary/Euler predicates.
- [x] G3 strengthen identities 2-4 and make identity 5 the ten-row §6.3 table without changing names/order or gate bytes.
- [x] G4 publish the §6.2 / §6.3 predicate-to-witness/API-shape coverage table.
- [x] Compile/package all eight GMP/GMPXX targets: `37415985763 / 112114628756`, package `11391685901`, manifest 28/28, clean source, `runtimeExecution=false`.
- [ ] **Exact next `M6-CP2-TB2-COVERAGE-EXEC`** — immutable `11391685901 / 5ce3132e...`, exactly 491 fresh exact-filter processes.
- [ ] Mandatory `M6-CP2-CLOSE-REV` → closure record → `M6-DEFN-R5` if accepted.

## Current — `M6-CP2-TB1-VERIFIER-R2-REV` review-agent addendum / CP2 closure REVOKED / exact next `M6-CP2-CB2-COVERAGE` (2026-10-06)

- [x] Re-derive R2 TB: 1005/1005, frozen order, 491/491, all raw hashes match; `c64baacd` == HEAD; RA-29c implemented.
- [x] Confirm the promotion of `c64baacd`; revoke CP2 closure:
  - U1: A7 vertex binding unimplemented;
  - U2: negative coverage missing;
  - U3: dead codes;
  - U4: no closure record.
- [x] RA-29d; CB2 coverage plan; lesson 205.
- [ ] **Exact next `M6-CP2-CB2-COVERAGE`** (compile/package only; gate 491).
- [ ] TB (491) → `M6-CP2-CLOSE-REV` (`M6_CP2_Closure_Record.md`) → `M6-DEFN-R5`.

## Superseded (CP2 closure revoked by RA-29d) — `M6-CP2-TB1-VERIFIER-R2-REV` ACCEPTED / CP2 CLOSED (2026-10-06)

- [x] Independently re-derive **491/491**, exact-one 491/491, zero skips, benchmark 0, immutable postflight.
- [x] Confirm RA-29c exact three-hop binding and removal of reverse lookup/fallback, raw component rule, O(V·P) scan and self-declared ownership trait.
- [x] Close R1-REV-01/02/03, EXEC-OBS-01 and RA-29c T3/T5 as recovery-proved/non-stable.
- [x] Promote `11385836615 / c64baacd...`; accounting remains **60 / 16 / 44**, debt 1.
- [ ] **Exact next: `M6-DEFN-R5`** — carried CP3 definition/permutation gate.

## Current — `M6-CP2-TB1-VERIFIER-R2-EXEC` COMPLETE / 491/491 / mandatory Review next (2026-10-06)

- [x] Consume immutable `11385836615 / c64baacd...` without rebuild/repair.
- [x] Execute exactly **491** fresh exact-filter processes: focused30 **30/30**, CP2-focused12 **12/12**, selector449 **449/449**.
- [x] Verify exact-one 491/491, zero skips, benchmark 0, immutable package/source/execution-view postflight, and no configure/compile/relink/discovery/repair/mutation/retry.
- [x] Persist result/log artifacts `11387562709 / 11387233341`; result manifest **1005/1005**.
- [x] Record +0 regression candidates; stable accounting remains **60 / 16 / 44**, debt 1.
- [ ] **Exact next: mandatory `M6-CP2-TB1-VERIFIER-R2-REV`** — independently adjudicate the 491/491 recovery and candidate promotion/rejection.
- [ ] Candidate remains unpromoted; `M6-DEFN-R5` stays held until Review.

## Current — `M6-CP2-CB1-VERIFIER-R3` COMPLETE / exact next `M6-CP2-TB1-VERIFIER-R2-EXEC` (2026-10-06)

- [x] Implement RA-29c exact three-hop A5/A6/A7 binding and remove R2's reverse lookup / O(V·P) scan.
- [x] Remove only `a0:component-adjacency` and its identity-2 sub-witness; replace identity-11 `owns_products` self-assertion with behavioral ownership evidence.
- [x] Compile/package all eight standard GMP/GMPXX targets: run/job `37401647591 / 112069997705`, package `11385836615`, manifest **28/28**, clean source, `runtimeExecution=false`.
- [x] Preserve focused30 / CP2-focused12 / selector449 / routing449 bytes; stable accounting **60 / 16 / 44**, debt 1.
- [ ] **Exact next: `M6-CP2-TB1-VERIFIER-R2-EXEC`** — immutable package `11385836615 / c64baacd...`, exactly **491** fresh exact-filter processes, `TURN_ID`-derived upload paths, no rebuild/repair.
- [ ] Mandatory `M6-CP2-TB1-VERIFIER-R2-REV`; candidate stays unpromoted until Review.

## Current — `M6-CP2-TB1-VERIFIER-R1-REV` review-agent addendum / RA-29c / exact next `M6-CP2-CB1-VERIFIER-R3` (2026-10-06)

- [x] Re-derive R1 from job log `112044082007`: 491 RUN in frozen order; 462/491; 29 REDs; signatures 19/1/9; clustering confirmed.
- [x] Confirm R1-REV-01's diagnosis and R1-REV-02 (my RA-29a §4 error).
- [x] Replace the RA-29b §1 fallback and §3 ambiguity witness with the exact three-hop binding (RA-29c); behavioral ownership check; lesson 204.
- [x] `M6-CP2-CB1-VERIFIER-R3` compile/package completed at `c64baacd...` / package `11385836615`.
- [ ] TB1-R2 **491** (`TURN_ID`-derived upload paths) → mandatory R2 Review.

## Current — `M6-CP2-TB1-VERIFIER-R1-REV` / RA-29b / exact next R3 (2026-10-06)

- [x] Independently accept R1 mechanics: **462/491**, exact-one 491/491, zero skips, benchmark 0.
- [x] Cluster 28 RED rows under A7 legacy-projection reverse-binding false rejection; R2 wrongly requires uniqueness instead of RA-29a's ambiguity fallback.
- [x] Withdraw RA-29a component connected-partition rule: ingress component labels are not independently reconstructable from raw mesh connectivity; selector144 is accepted counterexample.
- [x] Classify stale R1 upload paths as post-runtime orchestration-only; no duplicate runtime.
- [x] Freeze RA-29b and the bounded R3 Code + Build plan; stable accounting remains **60 / 16 / 44**, debt 1.
- [x] `M6-CP2-CB1-VERIFIER-R3` completed compile/package GREEN without Directional runtime.
- [ ] If green: immutable `M6-CP2-TB1-VERIFIER-R2-EXEC` at unchanged **491**, then mandatory R2 Review.

## Current — `M6-CP2-TB1-VERIFIER-R1-EXEC` COMPLETE / mandatory Review next (2026-10-06)

- [x] Consume immutable `11382000465 / 9c8478ae...` without rebuild/repair and execute exactly **491** fresh exact-filter processes.
- [x] Re-derive job-log gate: focused30 **26/30**, focused12 **11/12**, selector449 **425/449** = **462/491**; exact-one 491/491; zero skips; benchmark 0.
- [x] Record Review-owned CAND-01 A7/A5 relation-step cluster, CAND-02 focused12 ordinal6 baseline, CAND-03 A0 component-adjacency rejection.
- [x] Record EXEC-OBS-01: post-runtime caller upload paths were stale, so runtime result/log artifacts were not created; no runtime retry authorized.
- [x] Clean temporary R1 EXEC workflow, harness and trigger; mailbox remains durable.
- [ ] **Exact next: `M6-CP2-TB1-VERIFIER-R1-REV`** — independently adjudicate 29 REDs and evidence-upload defect, cluster causal/downstream failures, freeze smallest recovery.
- [ ] Candidate remains unpromoted; stable accounting remains **60 / 16 / 44**, debt 1.

## Current — `M6-CP2-CB1-VERIFIER-R2` COMPLETE / exact next `M6-CP2-TB1-VERIFIER-R1-EXEC` (2026-10-06)

- [x] Apply RA-29 + RA-29a verifier recovery at semantic source `9c8478aec40bf07144ca7372c2aa58293cd42f5e`.
- [x] Compile/package all eight standard GMP/GMPXX targets: run/job `37391389044 / 112037085233`, result `11382000465`, manifest **28/28**, `runtimeExecution=false`.
- [x] Preserve focused30 / CP2-focused12 / selector449 / routing449 bytes; no optimizer source change; stable accounting **60 / 16 / 44**, debt 1.
- [x] Retire consumed Drive patches and temporary R2 callers/triggers.
- [ ] **Exact next: `M6-CP2-TB1-VERIFIER-R1-EXEC`** — immutable package `11382000465 / 9c8478ae...`, exactly **491** fresh exact-filter processes, no rebuild/repair.
- [ ] Mandatory `M6-CP2-TB1-VERIFIER-R1-REV`; candidate stays unpromoted until Review.

## Current — `M6-CP2-TB1-VERIFIER-REV` review-agent addendum / RA-29a / exact next `M6-CP2-CB1-VERIFIER-R2` (2026-10-05)

- [x] Re-derive TB1: 1005/1005, frozen order, 488/491, all raw hashes match, REDs 2/6/7; candidate `265c8fbb` == HEAD.
- [x] Confirm CAND-01/02/03 and REV-OBS-01/03/04 (extend REV-OBS-03 to A7); withdraw REV-OBS-02.
- [x] New: S2.1 split-class fail-open; S2.2 quadratic topology; S2.3 first-match A7 step binding; S2.4 missing A0 component adjacency; S2.5 address-bound token → RA-29a; lesson 203.
- [ ] **Exact next `M6-CP2-CB1-VERIFIER-R2`** (RA-29 + RA-29a; compile/package only).
- [ ] TB1-R1 **491** → mandatory R1 Review.

## HISTORY — M6-CP2 verifier R2 recovery

- [ ] Execute `M6-CP2-CB1-VERIFIER-R2` under RA-29.
- [ ] Repair the three non-vacuous CP2 witnesses plus identity8 valid-region authority, carried full-pipeline verification report, shared support-kernel check, and independent selected-forest path verification.
- [ ] Compile/package only; no Directional runtime. If green, run fresh 491-process `M6-CP2-TB1-VERIFIER-R1-EXEC`, then mandatory Review.
- [ ] Do not promote `11365308211 / 265c8fbb...`; stable accounting remains 60/16/44, debt 1.

## Superseded by Review — `M6-CP2-TB1-VERIFIER-EXEC` COMPLETE / 488/491 (2026-10-05)

- [x] Consume immutable `11365308211 / 265c8fbb...` without rebuild/repair.
- [x] Execute exactly **491** fresh exact-filter processes: focused30 **30/30**, CP2 focused12 **9/12**, selector449 **449/449**.
- [x] Verify exact-one selection, zero skips, benchmark 0, immutable package/source/execution-view postflight, and no configure/compile/relink/discovery/repair/mutation.
- [x] Record three active non-stable Review-owned RED candidates: ordinal 2 source-face permutation no-op; ordinal 6 `selectedRelationStep` no-op; ordinal 7 non-vacuity failure before verifier.
- [x] Keep stable accounting **60 / 16 / 44**, debt 1; candidate remains unpromoted.
- [x] `M6-CP2-TB1-VERIFIER-REV` independently adjudicated CAND-01..03 and froze RA-29 bounded recovery; exact next is R2.

## Current — `M6-CP2-CB1-VERIFIER-R1` COMPLETE / compile-package GREEN / exact next `M6-CP2-TB1-VERIFIER-EXEC` (2026-10-05)

- [x] Implement independent A0/A5/A6/A7 verifier record views, semantic findings, dependency gating, and exact certificate-chain binding.
- [x] Integrate `VerifiedSurfaceProducts` after A7 / before adapter projection; exact failure string `VerificationFailed:<code>:<site>`.
- [x] Add focused-12 exactly as frozen, including three wedge tampers, weld-pinched manifoldness witness, and RA-28b representative-scope identity 12.
- [x] Preserve selector449 (`d4a0d1b...`) and focused-30; no `SurfaceMeshOptimizer` production change.
- [x] Compile/package exact source `265c8fbb19a66c5c3344a525fdbd43932c3ef829`: run/job `37358279504 / 111926243775`, result `11365308211`, eight GMP/GMPXX targets, manifest 28/28, `runtimeExecution=false`.
- [x] Classify first compile-only `DomainResult` test typo as bounded/non-runtime; no stable repricing.
- [ ] **Exact next `M6-CP2-TB1-VERIFIER-EXEC`:** immutable `11365308211 / 265c8fbb...`, exactly **491** fresh processes (30 + 12 + 449), no rebuild/repair.
- [ ] Mandatory `M6-CP2-TB1-VERIFIER-REV`; candidate remains unpromoted until Review. Stable accounting **60 / 16 / 44**, debt 1.

## Superseded — `M6-CP2-CB1-VERIFIER-REV` / RA-28b / exact next `M6-CP2-CB1-VERIFIER-R1` (2026-10-05)

- [x] Verify the stop report (all five points accurate); HEAD source == `3f40f04a`.
- [x] Root cause: RA-28a §7 over-tightened RA-26 §5(iii) (review-agent error).
- [x] Reject an A5 `selectedFace ∈ bindings` invariant and a class-wide optimizer check. Authoritative projection is confined to the seed scope, and that static property is certified by the completion guard, the verifier and final validation.
- [x] RA-28b: retain the optimizer self-check as non-authoritative; re-specify identity 12 as a confinement falsifier; note for DEFN-R5; lesson 202.
- [ ] **Exact next `M6-CP2-CB1-VERIFIER-R1`** (compile/package; no optimizer change).
- [ ] TB1 **491** → mandatory Review.

## Superseded stop — `M6-CP2-CB1-VERIFIER` RA-28a §7 (adjudicated by `M6-CP2-CB1-VERIFIER-REV`)

- [x] Re-audit the RA-28a §7 representative-face precondition on exact semantic source `8bc1f52b...`.
- [x] Establish that A5 selects `placement.selectedFace` independently of edge/vertex `cornerWedgeBindings`, phase-front closure does not require source-face identity, and A7 `sourceCharts` are binding-derived only.
- [x] Stop before applying the exploratory verifier WIP, compiling, or starting TB1, as RA-28a requires.
- [ ] Runtime-free Review must adjudicate the missing invariant and freeze a bounded correction/contract amendment.
- [ ] Successor is `UNKNOWN` until Review authority freezes it; 491-process TB1 remains held.

## Current — `M6-CP2-DEFN-REV` ACCEPTED with RA-28a / exact next `M6-CP2-CB1-VERIFIER` (2026-10-05)

- [x] Review the CP2 Definition (D1–D6, RA-26 §5(iii)) against frozen §6/§10 and exact source.
- [x] RA-28a:
  - exact-once/forest/spanning/cycle checks; A6 → A5 field table; A5 wedge/support vs A0;
  - dependency gating; drop two predicate-less codes; `VerifiedSurfaceProducts`;
  - `retained`-gated optimizer check; tamper precision; A0 tuple and failure string.
- [x] Release the CB1 plan; lesson 201.
- [ ] **Exact next `M6-CP2-CB1-VERIFIER`** (compile/package only; 12 identities; RA-28a stops).
- [ ] TB1 **491** → mandatory Review → (later) `M6-DEFN-R5` → CP3.

## Current — `M6-CP2-DEFN` COMPLETE / mandatory Definition Review next (2026-10-05)

- [x] Freeze D1 record-view negative seam and typed semantic finding identity.
- [x] Classify C4 accepted-defensive; verifier manifoldness owns the executed pinched-topology falsifier.
- [x] Freeze three mutant-killing wedge tampers without changing identity29.
- [x] Integrate A8 after A7 / before adapter projection; resolve RA-26 §5(iii) to class-wide optimizer chart membership.
- [x] Freeze CP2 focused-12 and gate **30 + 12 + 449 = 491**; standard eight GMP targets.
- [ ] **Exact next `M6-CP2-DEFN-REV`**. `M6-CP2-CB1-VERIFIER` remains held until Review.
- [ ] `M6-DEFN-R5` follows CP2; `G4-B002` debt remains 1.

## Superseded historical snapshots

## Current — `M6-CP1-CLOSE-REV` ACCEPTED / CP1 CLOSED / exact next `M6-CP2-DEFN` (2026-10-05)

- [x] Re-confirm no semantic-source advance from promoted `3f40f04a`.
- [x] Complete RA-26 current-HEAD provenance-consumer census: zero authority-deciding consumers.
- [x] Adjudicate all six frozen CP1 exit items PASS with focused-30 ordinals and source citations.
- [x] Classify C2/C4/RA-27a static-only branches with later owners; keep `G4-B002` open.
- [x] Close M6 CP1 mechanism-only; stable accounting remains **60 / 16 / 44**, debt 1.
- [x] Freeze `Architecture_M6_CP2_Definition_Plan.md`.
- [ ] **Exact next `M6-CP2-DEFN`** (runtime-free): freeze `SurfaceProductVerifier`, certificate-chain binding, RA-26 §5(iii), C4 witness, and appended wedge-rule tampers.
- [ ] `M6-DEFN-R5` follows CP2 and retains CP3-entry obligations.

## Superseded historical snapshots

## Current — `M6-CP1-TB12-CLOSE-R1-REV` + review-agent addendum / RA-27b / exact next `M6-CP1-CLOSE-REV` (2026-10-05)

- [x] Re-derive R1: 497/497, frozen-order ledgers, 479/479; all 479 raw-log hashes match; candidate `3f40f04a` == HEAD.
- [x] Confirm the RA-27a wedge rule (exact; fail-closed on malformed membership input), the C4 name and identity 29 on a consistent chain.
- [x] Record overclaims (runtime proves one wedge-rule dimension) and unowned defensive branches (C4, C2 empty-front) → RA-27b; lesson 200.
- [x] Amend the close plan: verbatim exit items, defensive-branch classification, `G4-B002` stays open, successor `M6-CP2-DEFN`.
- [ ] **Exact next `M6-CP1-CLOSE-REV`** (runtime-free).
- [ ] If CP1 closes → `M6-CP2-DEFN` (RA-27b §4), then CP2 CBs, then `M6-DEFN-R5` → CP3.

## Current — `M6-CP1-TB12-CLOSE-R1-REV` ACCEPTED / 479/479 promoted / exact next CP1 close Review (2026-10-05)

- [x] Independently re-derived R1 result manifest **497/497**, focused30 **30/30**, selector449 **449/449**, exact-one, zero skips, benchmark 0 and immutable postflight.
- [x] Accepted RA-27a exact wedge graph and consistent-chain identity29 falsifier; C4 name correction verified.
- [x] Closed `M6-CP1-TB12-CLOSE-EXEC-CAND-01` recovery-proved/non-stable; stable accounting remains **60 / 16 / 44**, debt 1.
- [x] Promoted `11330703256 / 3f40f04a0e9d382b2ec82cf37a03c18ad405eb05` as current reviewed M6 runtime authority.
- [ ] **Exact next:** runtime-free `M6-CP1-CLOSE-REV` under `Architecture_M6_CP1_Close_Review_Plan.md`; CP1 remains ACTIVE until all six exit items and RA-26 current-HEAD audit pass.
- [ ] Later-owner obligations remain carried: RA-27a §6 / OBS-01 / OBS-02 / RA-26 §5 to M6-CP2 / DEFN-R5 / CP3 as frozen.

## Current — `M6-CP1-TB12-CLOSE-R1-EXEC` COMPLETE / 479/479 GREEN / mandatory R1 Review next (2026-10-05)

- [x] Immutable candidate `11330703256 / 3f40f04a0e9d382b2ec82cf37a03c18ad405eb05`; exact **30 + 449 = 479** process gate.
- [x] Focused **30/30** + selector449 **449/449** = **479/479 PASS**; exact-one selection, zero skips, benchmark 0.
- [x] Identity29 recovery is GREEN; identity30 remains GREEN; selector449 remains fully GREEN.
- [x] Result self-manifest **497/497**, immutable package/execution-view postflight, no retry/repair/rebuild/mutation.
- [x] +0 new regression events/candidates; stable accounting remains **60 / 16 / 44**, debt 1.
- [ ] **Exact next:** mandatory runtime-free `M6-CP1-TB12-CLOSE-R1-REV`. Candidate remains unpromoted until Review; `M6-CP1-CLOSE-REV` remains held.

## Current — `M6-CP1-CB12-CLOSE-R2` COMPLETE / compile-package GREEN / exact next R1 EXEC (2026-10-05)

- [x] RA-27a exact A7 wedge sheet-graph connectivity; site `cross-sheet:wedge`.
- [x] C4 diagnostic name corrected to `QuotientClosedComplexStripContinuationMismatch`.
- [x] Identity29 recovered without stale A6 reuse: baseline accepts; wedge-only tamper; A5 republish; A6 re-produce/succeed; A7 rejects at wedge site.
- [x] Focused30 / selector449 / routing449 frozen bytes unchanged.
- [x] Compile/package GREEN: `11330703256 / 3f40f04a...`, run/job `37278068286 / 111659540374`, eight GMP/GMPXX targets, manifest 28/28, `runtimeExecution=false`.
- [ ] **Exact next:** `M6-CP1-TB12-CLOSE-R1-EXEC`, immutable **479** process gate, then mandatory `M6-CP1-TB12-CLOSE-R1-REV`.
- [ ] Stable accounting remains **60 / 16 / 44**, debt 1; candidate remains unpromoted until Review.

## Current — `M6-CP1-TB12-CLOSE-REV` + review-agent addendum / RA-27a / exact next `M6-CP1-CB12-CLOSE-R2` (2026-10-05)

- [x] Re-derive TB12: digests `da42bf2a`/`70880747`, 979/979, ledgers in frozen order, 478/479, ordinal 29 pre-tamper RED; candidate source == HEAD.
- [x] Review C2–C4. C2/C3 accepted; C4 fail-closed accepted but its name lacks the `Quotient` prefix and it has no executed falsifier.
- [x] Correct the CAND-01 cause: the fixture has no disjoint-sheet relation. Withdraw RA-27 §2–§3.
- [x] Find the reachable wedge proxy (`:6884-6895`) → RA-27a §2; the stale-A6 negative → RA-27a §5; OBS-01/02; lesson 199.
- [ ] **Exact next `M6-CP1-CB12-CLOSE-R2`**: wedge rule, C4 name, identity 29 consistent-chain witness; compile/package only.
- [ ] TB12-R1 **479**, then mandatory Review, then `M6-CP1-CLOSE-REV`.

## Current — `M6-CP1-TB12-CLOSE-REV` COMPLETE / exact next `M6-CP1-CB12-CLOSE-R2` (2026-10-05)

- [x] Re-derived TB12 mechanical evidence: 478/479; identity29 sole RED; no tamper reached.
- [x] Adjudicated CAND-01 as false rejection / test-fixture witness defect / non-stable. Production-selection defect not established.
- [x] RA-27 freezes test-only witness recovery; production C1 remains unchanged and candidate unpromoted.
- [ ] **Exact next:** `M6-CP1-CB12-CLOSE-R2` test-authority recovery + compile/package only.
- [ ] Then `M6-CP1-TB12-CLOSE-R1-EXEC` at unchanged **479**, mandatory R1 Review, then CP1 close if accepted.
- [ ] Stable accounting remains **60 / 16 / 44**, debt 1.

## Current — `M6-CP1-TB12-CLOSE-EXEC` COMPLETE / 478/479 / mandatory Review next (2026-10-05)

- [x] Immutable candidate `11324028392 / 02149f1518fc6a753acf3235f7dcdc6fcdf59f24`; exact 479-process gate.
- [x] Focused **29/30** + selector449 **449/449** = **478/479**, exact-one, zero skips, benchmark 0, immutable postflight, 979/979 result manifest.
- [x] CAND-01: non-stable / Review-owned; identity29 lacks a selected cross-sheet witness and fails before its C1 tamper. Stable accounting **60 / 16 / 44**, debt 1.
- [ ] **Exact next:** runtime-free `M6-CP1-TB12-CLOSE-REV`; `M6-CP1-CLOSE-REV` remains held.

## Current — `M6-CP1-CB12-CLOSE-R1` COMPLETE / exact next `M6-CP1-TB12-CLOSE-EXEC` (2026-10-05)

- [x] C1 exact A7 cross-sheet transition endpoint-sheet certification.
- [x] C2 distinct A5 missing-front / invalid-source / unavailable-chart diagnostics, including empty edges.
- [x] C3 `consumedInternalIsolationSeams` projected from A5 `validatedIsolationCertificateCount`; identity24 updated.
- [x] C4 RA-25 ambiguity now fails closed with `ClosedComplexStripContinuationMismatch`.
- [x] Identities 29/30 and focused-30 (`1e815443...a1d6`), exact focused-28 prefix.
- [x] C5 discharged by RA-26 §3; no optimizer/final-validator change.
- [x] Compile/package GREEN: `11324028392 / 02149f1518fc6a753acf3235f7dcdc6fcdf59f24`, run/job `37259524323 / 111603703243`, 28/28, GMP/GMPXX, `runtimeExecution=false`.
- [ ] **Exact next:** `M6-CP1-TB12-CLOSE-EXEC`, focused30 + selector449 = **479**, then mandatory Review and `M6-CP1-CLOSE-REV`.

## Current — `M6-CP1-CB12-CLOSE-REV` / RA-26 / exact next `M6-CP1-CB12-CLOSE-R1` (2026-10-05)

- [x] Confirm HEAD source == `8dd95821` (fetched by SHA after the squash); CB12 made no source change.
- [x] Adjudicate C5. `SurfaceMeshOptimizer.cpp:3015-3031` is not a provenance consumer and is test-only → OBS-01 (M8-CP2). Its "anchor-assuming" label is withdrawn.
- [x] Audit all 12 optimizer and validation provenance-face sites. No authority-deciding consumer exists. The optimizer energy/gradient and the final-validation field-metric fallback are reference-selecting → RA-26 §5 → `M6-DEFN-R5` / `M6-CP3`.
- [x] RA-26; CB12 plan header block; lesson 198.
- [ ] **Exact next `M6-CP1-CB12-CLOSE-R1`**: C1–C4; identities 29/30; focused-30; compile/package only; no optimizer change.
- [ ] TB12 **479**, then mandatory Review, then `M6-CP1-CLOSE-REV`, which also re-checks RA-26 §3.
- [ ] `M6-DEFN-R5`: add RA-26 §5 items (i)–(iv).

## Superseded stop — M6-CP1-CB12-CLOSE (adjudicated by `M6-CP1-CB12-CLOSE-REV`)

- C5 audit found **BLOCKER**: `SurfaceMeshOptimizer.cpp:3015-3031` picks the first incident source face, derives one component/sheet scope, and breaks; this is anchor-assuming.
- RA-22b / RA-25 / CB12 require Review; do not repair it inside CB12.
- C1-C4, identities 29/30, compile/package and TB12 were not started.
- Reviewed runtime remains 477/477; successor UNKNOWN pending Review.

## Current — `M6-CP1-TB11-G4-R1-REV` + review-agent addendum / RA-25 / exact next `M6-CP1-CB12-CLOSE` (2026-10-05)

- [x] Re-derive TB11-R1: digest `1082edce`, 973/973 manifest, focused-28 and selector449 ledgers in frozen order (477/477), ordinals 25/28 OK; HEAD == `8dd95821`.
- [x] Confirm the RA-24 production change (bounded) and the identity 25/28 oracles. M1: the continuation skips silently on ambiguity → RA-25 fail-closed.
- [x] Re-route the successor to close-out CB12 (the carried obligations need code). Write the CB12 plan; pre-audit `project_surface_cell_vertex_chart_authority` as class-wide. Lesson 197.
- [ ] **Exact next `M6-CP1-CB12-CLOSE`**: C1-C5; identities 29/30; compile/package only.
- [ ] TB12 **479**, then mandatory Review, then `M6-CP1-CLOSE-REV`.

## Superseded — `M6-CP1-TB11-G4-R1-REV` pre-addendum checklist
## Current — `M6-CP1-TB11-G4-R1-REV` ACCEPTED / candidate promoted / exact next `M6-CP1-CLOSE-REV` (2026-10-04)

- [x] Independently re-derive candidate **28/28**, runtime **973/973**, focused28 **28/28**, selector449 **449/449**, aggregate **477/477**, exact-one, zero skips, benchmark 0 and immutable postflight.
- [x] Discharge RA-24/CAND-02: edge-loop strip closure is bounded to the A6 view builder; identity28 independently proves produced-torus non-vacuity and hard-feature tamper rejection.
- [x] Discharge RA-21c/RA-21d/CAND-01: per-occurrence arrangement witnesses and typed relation authority are exact; equality is retained for Ordinary non-isolation relations and relaxed only at certified seams.
- [x] Promote `11316716869 / 8dd958217d8cbda2d403f7a5c4c7dce242dde1c0` as current reviewed M6 runtime authority. Stable accounting remains **60 / 16 / 44**, debt 1.
- [ ] **Exact next `M6-CP1-CLOSE-REV`:** runtime-free close Review; complete A7 cross-sheet proxy, remaining provenance-face consumer audit, merged diagnostic-name closeout and `consumedInternalIsolationSeams` counter-source audit before any CP1 closure claim.

## Current — `M6-CP1-TB11-G4-R1-EXEC` COMPLETE / 477/477 GREEN / exact next `M6-CP1-TB11-G4-R1-REV` (2026-10-04)

- [x] Consume immutable R1 candidate `11316716869 / 8dd958217d...`; verify 28/28 package manifest, exact source, GMP/GMPXX compile receipts and frozen gate authorities.
- [x] Execute focused28 + selector449 as **477** fresh exact-filter processes: **28/28 + 449/449 = 477/477 PASS**, exact-one selection, zero skips, benchmark 0.
- [x] Confirm focused ordinals 25 and 28 both PASS; package/source/execution-view postflight immutable; no repair or retry after runtime start.
- [x] Record +0 new regression events/candidates; stable accounting remains **60 / 16 / 44**, debt 1.
- [ ] Next: mandatory runtime-free `M6-CP1-TB11-G4-R1-REV` independently verifies R1 recovery and adjudicates promotion. Do not begin CP1 close first.

## Current — `M6-CP1-CB11-G4-R1` COMPLETE / compile-package GREEN / exact next `M6-CP1-TB11-G4-R1-EXEC` (2026-10-04)

- [x] Implement RA-24 edge-loop strip closure as the sole production change.
- [x] Recover identity25 under RA-21d: exact chain/node equality only for Ordinary non-isolation relations; typed barrier seams remain per-side.
- [x] Recover identity28 on the produced torus with independent edge-loop partition/candidate checks, non-vacuous `ClosedLoop`, and hard-feature tamper rejection.
- [x] Apply exact two-file patch as semantic source `8dd958217d8cbda2d403f7a5c4c7dce242dde1c0`; owner-side Drive cleanup complete.
- [x] Mandatory GMP/GMPXX compile/package run/job `37238936105 / 111543578349`: all eight targets GREEN; artifact `11316716869`; 28/28 manifest; clean receipts; `runtimeExecution=false`.
- [ ] **Exact next `M6-CP1-TB11-G4-R1-EXEC`:** immutable focused28 + selector449 = **477** fresh exact-filter processes.
- [ ] Mandatory `M6-CP1-TB11-G4-R1-REV`; only then may `M6-CP1-CLOSE-REV` proceed.

## Current — `M6-CP1-TB11-G4-REV` + review-agent addendum / RA-24 / RA-21d / exact next `M6-CP1-CB11-G4-R1` (2026-10-04)

- [x] Re-derive TB11: digest `7de4a320`, 973/973 manifest; RED focused 25 and 28; selector449 449/449. Ordinal 28's log shows an empty candidate vector.
- [x] F2 overturned. R4 D3 rule-7 quad-opposite strips are rung sets, which the path-degree classifier always skips, so there are zero candidates on any closed complex and RA-23's synthetic torus would also fail. RA-24: edge-loop (strand) closure.
- [x] F1 confirmed; RA-21d keeps Ordinary non-isolation equality.
- [x] Re-scope the R1 plan (R1-0 production strip relation only; oracles). Lesson 196.
- [ ] **Exact next `M6-CP1-CB11-G4-R1`**: compile/package only.
- [ ] TB11-R1 **477**, then mandatory Review, then `M6-CP1-CLOSE-REV`.

## Superseded — `M6-CP1-TB11-G4-REV` pre-addendum checklist
## Current — `M6-CP1-TB11-G4-REV` COMPLETE / CB11 candidate rejected / exact next `M6-CP1-CB11-G4-R1` (2026-10-04)

- [x] Independently re-derive immutable TB11 evidence: candidate **28/28**, result **973/973**, focused **26/28**, selector449 **449/449**, aggregate **475/477**, exact-one, zero skips, benchmark 0, immutable postflight.
- [x] Adjudicate ordinal25 as a **false rejection / test-oracle + definition defect**: RA-21b incorrectly required quotient-equivalent cut occurrences to share physical arrangement nodes/chains. Freeze RA-21c per-occurrence/per-side subdivision witness semantics.
- [x] Adjudicate ordinal28 as a **definition/fixture-witness gap**, not a demonstrated extractor regression: the old arrangement `(family,strand)` witness never proved non-vacuity under quotient opposite-edge strip closure. Freeze RA-23.
- [x] Close `M6-CP1-TB11-G4-EXEC-CAND-01` as false-rejection/non-stable; reclassify `...-CAND-02` as non-stable definition-witness recovery work. Stable accounting remains **60 / 16 / 44**, debt **1**.
- [x] Publish `Architecture_M6_CP1_TB11_G4_Review_Record.md` and bounded `Architecture_M6_CP1_CB11_G4_R1_Recovery_Code_Build_Plan.md`. Candidate `11308472138 / 582da20a...` stays unpromoted; reviewed runtime remains `11299078582 / 96b456f9...`.
- [ ] **Exact next `M6-CP1-CB11-G4-R1`:** test-authority recovery only. Implement RA-21c in ordinal25 and RA-23 in ordinal28; preserve focused28/selector449 bytes and production A5/A6 semantics. Any semantic production change is STOP -> Review.
- [ ] Compile-green R1 -> immutable `M6-CP1-TB11-G4-R1-EXEC`, unchanged **28+449=477** -> mandatory `M6-CP1-TB11-G4-R1-REV`.
- [ ] `M6-CP1-CLOSE-REV` remains held until R1 Review succeeds.

## Completed predecessor — `M6-CP1-CB11-G4` compile-package GREEN / TB11 executed (2026-10-04)

- [x] Implement RA-20/RA-21/RA-21b A6 `SurfaceQuotientClosedComplexView`: canonical side-incidence edges, A6 relation labels, typed-source hard-feature protection, quotient lineage and opposite-edge strip closure.
- [x] Candidate extraction consumes only the A6 closed-complex view; no arrangement-authority dependency.
- [x] Freeze focused identities 25-28; focused-28 SHA-256 `9154a986ce005c53f99faad3551989b05516abe9e4fd02dce585a645d70a011d`, exact focused-24 prefix.
- [x] Final semantic source `582da20a925ba920c923bf5aacb9e0e56ef0723d`; mandatory GMP/GMPXX compile/package run/job `37216400150 / 111477707423` GREEN for all eight standard targets; result/log `11308472138 / 11308317584`; package manifest 28/28; clean source receipts; `runtimeExecution=false`.
- [ ] **Exact next `M6-CP1-TB11-G4-EXEC`:** immutable candidate `11308472138`, focused28 + selector449 = **477** fresh exact-filter processes.
- [ ] Mandatory `M6-CP1-TB11-G4-REV`; only then `M6-CP1-CLOSE-REV`. Code + Build makes no `G4-B002`, debt, runtime-promotion or CP1-closure claim.

## Current — `M6-CP1-TB10-A5V-R1-REV` + review-agent addendum / RA-21b / exact next `M6-CP1-CB11-G4` (2026-10-04)

- [x] Re-derive TB10-R1: digest `b9f2daed`, 965/965 manifest, focused-24 and selector449 ledgers in frozen order (473/473), focused 20/24 OK; HEAD == `96b456f9`.
- [x] Confirm the F1 reorder and binding in source, and the F2 oracle by a full struct-field census.
- [x] CB11 pre-analysis → RA-21b. The proposal key is positional (no `CellId`); `halfedge.proposalId` is only the primary entry; cell sides are per-face polylines, so a degree-2-contraction equivalence is needed. CB11 plan amended.
- [x] Record `consumedInternalIsolationSeams` sourcing for CP1 close. Lesson 195.
- [ ] **Exact next `M6-CP1-CB11-G4`** (RA-20/RA-21/RA-21b): compile/package only; focused 25-28.
- [ ] TB11 **477**, then mandatory Review, then `M6-CP1-CLOSE-REV`.

## Superseded — `M6-CP1-TB10-A5V-R1-REV` pre-addendum checklist
## Current — `M6-CP1-TB10-A5V-R1-REV` ACCEPTED / exact next `M6-CP1-CB11-G4` (2026-10-04)

- [x] Independently re-derive candidate/runtime evidence: 28/28 package, 965/965 result, focused24 24/24 + selector449 449/449 = **473/473**, exact-one, zero skips, benchmark 0, immutable postflight.
- [x] Discharge F1: publish A5 records first; moved helper validates the published complex and its certificate/cells.
- [x] Discharge F2: identity24 independently asserts every adapter-written result, mesh, vertex-lineage and face-lineage field.
- [x] Close CAND-01/CAND-02 as recovery-proved/non-stable; keep stable accounting **60 / 16 / 44**, debt 1.
- [x] Promote `11299078582 / 96b456f925be00e00bad6645e6eb905a804c14ea` as current reviewed M6 runtime authority.
- [ ] **Exact next `M6-CP1-CB11-G4`:** implement RA-20/RA-21 A6 closed-complex `G4-B002` boundary; Code + Build only.
- [ ] Compile-green -> TB11 **28+449=477** -> mandatory Review.
- [ ] `M6-CP1-CLOSE-REV` retains cross-sheet proxy, provenance-face audit and merged diagnostics; no CP1 closure yet.

## Current — `M6-CP1-TB10-A5V-R1-EXEC` runtime GREEN / mandatory Review next (2026-10-04)

- [x] Consume immutable R1 candidate `11299078582 / 96b456f925be00e00bad6645e6eb905a804c14ea`.
- [x] Execute focused24 then selector449 as **473** fresh exact-filter processes.
- [x] Record focused **24/24**, selector **449/449**, aggregate **473/473 PASS**, exact-one selection, zero skips, benchmark 0.
- [x] Verify result self-manifest **965/965** and immutable package/source/execution-view postflight; package manifest remains **28/28**.
- [x] Record **+0 new regression events/candidates**; stable accounting remains **60 / 16 / 44**, debt 1. Existing TB10 Review CAND-01/CAND-02 remain Review-owned and open/non-stable.
- [x] Complete workflow-first temporary-state cleanup; the final EXEC beacon follows as the last repository action.
- [ ] **Exact successor `M6-CP1-TB10-A5V-R1-REV`:** independently verify R1 runtime/static evidence and adjudicate candidate promotion plus CAND-01/CAND-02.
- [ ] CB11 remains held until R1 Review.

## Superseded — prior `M6-CP1-CB10-A5V-R1` COMPLETE / compile-package GREEN / exact next `M6-CP1-TB10-A5V-R1-EXEC` (2026-10-04)

- [x] Restore RA-19a ordering: publish all A5 records first, then validate the published complex.
- [x] Rebind moved side/cell checks to `complex.certificate().directedSideCount` and `complex.cells()`.
- [x] Strengthen identity24 to the exact TB10 Review §J3 pure-projection field table without changing identity/list bytes.
- [x] Re-hash focused24/focused20/selector449/routing449 unchanged.
- [x] Patch applied as semantic source `96b456f925be00e00bad6645e6eb905a804c14ea`.
- [x] Compile run/job `37192727051 / 111408174395`: all eight GMP/GMPXX targets GREEN, artifact `11299078582`, manifest 28/28, clean receipts, `runtimeExecution=false`.
- [ ] **Exact next `M6-CP1-TB10-A5V-R1-EXEC`:** immutable focused24 + selector449 = **473** fresh exact-filter processes.
- [ ] Mandatory `M6-CP1-TB10-A5V-R1-REV`; then only if accepted proceed toward CB11. CB11 remains held.

## Superseded — prior TB10-A5V Review exact-next checklist

## Current — `M6-CP1-TB10-A5V-REV` + review-agent addendum / RA-19a / exact next `M6-CP1-CB10-A5V-R1` (2026-10-04)

- [x] Re-derive TB10: digest `109e98d6`, 965/965 manifest, focused-24 and selector449 ledgers in frozen order (473/473); HEAD == `7c56845d`.
- [x] Confirm F1 in source (`:4937` before `:4943`) and F2 (identity-24 field gaps). Accept shared `τ`, RA-22b and the thin adapter's mapping and serialization.
- [x] Verify move fidelity by normalized predicate diff: 28 identical; side count re-bound to the A4 input; 3 unpinned names merged.
- [x] RA-19a: bind the helper to the published complex; exact identity-24 field table (§J3). R1 plan amended. Lesson 194.
- [ ] **Exact next `M6-CP1-CB10-A5V-R1`**: R1 ordering + binding, R2 exact oracle, R3 static checks; compile/package only.
- [ ] TB10-R1 **473**, then mandatory Review. Then CB11 (477), then `M6-CP1-CLOSE-REV` (cross-sheet proxy, provenance-face audit, merged diagnostics).

## Superseded — `M6-CP1-TB10-A5V-REV` pre-addendum checklist
## Current — `M6-CP1-TB10-A5V-REV` REJECTED / exact next CB10-A5V-R1 (2026-10-04)

- [x] Independently verify TB10 result: result/log/candidate digests, 965/965 self-manifest, 28/28 candidate manifest, focused24 24/24 + selector449 449/449 = 473/473, exact-one, zero skips, benchmark 0, immutable postflight.
- [x] Re-hash focused24/focused20/focused12 and selector449/routing449.
- [x] Accept shared `tau` single-sourcing and RA-22b representative-face guard.
- [x] **F1:** reject promotion because moved category-(a) helper executes before pre-existing `publish_records_for_validation`, contrary to RA-19.
- [x] **F2:** reject promotion because identity24 under-compares the adapter serialization and is not yet the frozen full pure-projection falsifier.
- [ ] **Exact next `M6-CP1-CB10-A5V-R1`:** fix F1 ordering and strengthen identity24 only; compile/package, runtime forbidden.
- [ ] Compile-green -> `M6-CP1-TB10-A5V-R1-EXEC`, unchanged focused24 + selector449 = **473**, then mandatory `M6-CP1-TB10-A5V-R1-REV`.
- [ ] CB11 remains held. `M6-CP1-CLOSE-REV` retains A7 cross-sheet proxy + provenance-face consumer audit.

## Current — `M6-CP1-TB10-A5V-EXEC` COMPLETE / 473/473 GREEN / mandatory Review next (2026-10-04)

- [x] Consume immutable CB10 candidate `11295692493 / 7c56845d4fac7ccb28898bbf4c681fc509ff9c3b`.
- [x] Execute focused24 then selector449 as **473** fresh exact-filter processes.
- [x] Record focused **24/24**, selector **449/449**, aggregate **473/473 PASS**, exact-one, zero skips, benchmark 0.
- [x] Verify result self-manifest **965/965** and immutable package/source/execution-view postflight; no runtime repair or retry.
- [x] Keep stable accounting **60 / 16 / 44**, debt 1; no new regression candidate and no promotion in EXEC.
- [ ] **Exact next `M6-CP1-TB10-A5V-REV`:** independently verify TB10 evidence and adjudicate candidate promotion.
- [ ] CB11 remains held until TB10 Review.

## Superseded — `M6-CP1-CB10-A5V` COMPLETE / TB10 next
## Current — `M6-CP1-CB10-A5V` COMPLETE / compile-package GREEN / exact next TB10-A5V 473 (2026-10-04)

- [x] Move RA-19 category-(a) phase-front semantic validation into A5 after all pre-existing A5 checks; preserve compatibility failure names and validation precedence.
- [x] Single-source accepted source-support tolerance `1.0e-8`; A5 and A7 consume one canonical accessor.
- [x] Restore RA-22b representative-face retained region/sheet reject-only guard and focused20 negative; preserve focused20 positive.
- [x] Freeze focused identities 21-24; focused24 SHA-256 `6bcc8a544cbc0296df4cdb66dcb0c2dc7f86c88dfb340b795462c8c9544067bf`, exact focused20 prefix.
- [x] Prove the adapter static-thin contract: no phase-front semantic tolerance/selector remains; identity24 behaviorally matches independent A5/A6/A7 serialization on three fixtures.
- [x] Repair one compile-only Eigen row/column mismatch in identity24; final semantic source `7c56845d4fac7ccb28898bbf4c681fc509ff9c3b`.
- [x] Mandatory eight-target GMP/GMPXX compile/package GREEN at run/job `37182633770 / 111378124041`; candidate `11295692493`; 28/28 manifest; `runtimeExecution=false`.
- [ ] **Exact next `M6-CP1-TB10-A5V-EXEC`:** immutable candidate `11295692493`, focused24 + selector449 = **473** fresh exact-filter processes, exact-one, zero skips, benchmark 0.
- [ ] Mandatory `M6-CP1-TB10-A5V-REV`; CB11 remains held until Review.
- [ ] `M6-CP1-CLOSE-REV` retains A7 cross-sheet certification proxy + provenance-face consumer audit.

## Superseded — `M6-CP1-TB9-A7-R1-REV` / CB10 next
## Current — `M6-CP1-TB9-A7-R1-REV` + review-agent addendum / RA-22b / exact next `M6-CP1-CB10-A5V` (2026-10-04)

- [x] Re-derive TB9-R1:
  - digest `a690ca39`, 970/970 manifest;
  - focused-20 and selector449 ledgers in frozen order, 469/469;
  - focused 20 OK (72 s);
  - HEAD == `584f80fe`.
- [x] Review the R1 diff: RA-22/RA-22a are implemented. **Found:** R1 deleted the A7 representative-face reject-only guard. RA-22b restores it in CB10 Goal T2, with a focused-20 negative; this is provably gate-neutral.
- [x] Record the provenance-face consumer audit for `M6-CP1-CLOSE-REV`. Lesson 192.
- [ ] **Exact next `M6-CP1-CB10-A5V`**: RA-19 + shared `τ` + RA-22b T2; focused 21-24; compile/package only.
- [ ] `M6-CP1-TB10-A5V-EXEC` **473**, then mandatory Review. Then CB11 (477), then `M6-CP1-CLOSE-REV` (cross-sheet proxy + consumer audit).

## Superseded — `M6-CP1-TB9-A7-R1-REV` pre-addendum checklist
## Current — `M6-CP1-TB9-A7-R1-REV` ACCEPTED / R1 promoted / exact next CB10-A5V (2026-10-04)

- [x] Independently re-verify result manifest **970/970**, focused **20/20**, selector449 **449/449**, aggregate **469/469**, exact-one, zero skips, benchmark 0 and immutable postflight.
- [x] Re-hash focused12/focused20 and prove the first12 byte prefix; re-hash selector449/routing449.
- [x] Re-open focused20 source/raw log and confirm non-vacuous production completion-ownership execution.
- [x] Accept RA-22/RA-22a recovery and promote `11292072930 / 584f80fe27fe3fbe482f3b6db035651a3083257c` as current reviewed M6 runtime authority.
- [x] Close `M6-CP1-TB9-A7-EXEC-CAND-01` as recovery-proved/non-stable existing `RP-01`; stable accounting stays **60/16/44**, debt 1.
- [x] Carry `τ` single-sourcing into amended CB10 plan; carry A7 cross-sheet proxy to `M6-CP1-CLOSE-REV`.
- [ ] **Exact next `M6-CP1-CB10-A5V`:** bounded A5 validation/thin-adapter migration + shared `τ`; compile/package only.
- [ ] Compile-green -> `M6-CP1-TB10-A5V-EXEC`: focused24 + selector449 = **473** fresh exact-filter processes -> mandatory Review.
- [ ] CB11 remains held until TB10 Review.

## Superseded — `M6-CP1-TB9-A7-R1-EXEC` COMPLETE / 469/469 GREEN / mandatory Review next (2026-10-04)

- [x] Consume immutable R1 candidate `11292072930 / 584f80fe27fe3fbe482f3b6db035651a3083257c`.
- [x] Execute focused20 then selector449: **469** fresh exact-filter processes, exact-one, zero skips, benchmark 0.
- [x] Record focused **20/20**, selector **449/449**, aggregate **469/469 PASS**; formerly failing focused20 now PASSes.
- [x] Verify 970/970 result manifest, immutable package/source/execution-view/fixtures, unchanged selector/routing, and zero tracked diagnostics.
- [x] Record prior non-stable `RP-01` candidate as recovery-proved in EXEC; stable accounting remains **60/16/44**, debt 1.
- [ ] **Exact next `M6-CP1-TB9-A7-R1-REV`:** independently verify R1 result and adjudicate candidate promotion.
- [ ] CB10 remains held until recovery Review.

## Current — `M6-CP1-CB9-A7-R1` COMPLETE / compile-package GREEN / exact next TB9-R1 469 (2026-10-04)

- [x] Implement RA-22 completion-consumer class authority only in `PureQuadCompletion.cpp`.
- [x] Derive A7 source-component singleton from retained charts; fail closed with `:component-singleton`.
- [x] Validate A7 selected destination by retained region/sheet membership plus singleton component; preserve legacy closure.
- [x] Emit RA-22a `:dest-unresolved`, `:dest-region`, `:dest-sheet`, `:dest-component` suffixes; no test/production exact-string consumer found.
- [x] Compile/package all eight standard GMP/GMPXX targets at `584f80fe27fe3fbe482f3b6db035651a3083257c`; run/job `37173519009 / 111351273790`; candidate `11292072930`; 28/28 manifest; `runtimeExecution=false`.
- [ ] **Exact next `M6-CP1-TB9-A7-R1-EXEC`:** immutable candidate `11292072930`, focused20 + selector449 = **469** fresh exact-filter processes.
- [ ] Mandatory `M6-CP1-TB9-A7-R1-REV`; CB10 remains held until Review.

## Current — `M6-CP1-TB9-A7-REV` + review-agent addendum / RA-22a / exact next `M6-CP1-CB9-A7-R1` (2026-10-04)

- [x] Re-derive TB9: digest, 970/970 manifest, ledgers. Focused-20 order matches the frozen file and its prefix is byte-identical to focused-12. 468/469, sole RED focused 20.
- [x] Verify CB9 A7 against RA-18:
  - support from A5;
  - reject-only same-simplex guard;
  - the `1e-9` check removed;
  - no placement-transport read;
  - focused 15 asserts code plus site.
- [x] Deduce the failing subclause statically: destination sheet ≠ representative sheet. Confirm RA-22.
- [x] RA-22a: destination and component-singleton site suffixes (R1 G5).
- [x] Record the A7 cross-sheet proxy (owner: CP1 close) and `τ` single-sourcing (owner: CB10). Lesson 191.
- [ ] **Exact next `M6-CP1-CB9-A7-R1`**: completion seam only, compile/package only.
- [ ] `M6-CP1-TB9-A7-R1-EXEC`, **469**, then mandatory Review. Then CB10 (473), CB11 (477), `M6-CP1-CLOSE-REV`.

## Superseded — `M6-CP1-TB9-A7-REV` pre-addendum checklist
## Current — `M6-CP1-TB9-A7-REV` COMPLETE / completion authority defect proved / R1 recovery next (2026-10-04)

- [x] Independently re-open TB9 result `11288673996`: self-manifest **970/970**, focused **19/20**, selector449 **449/449**, aggregate **468/469**, exact-one, zero skips, benchmark 0, immutable postflight.
- [x] Confirm focused20 alone fails after successful materialization at real `validate_materialized_completion_domain_ownership` with `CompletionOwnershipInvalidSelectedRelationDestination`.
- [x] Uphold CB9 A7 producer: class-wide chart/region/sheet lineage and singleton component authority are published; representative `sourcePoint` is compatibility-only.
- [x] Prove completion-consumer authority-domain conflation and freeze **RA-22**: A7 destinations consume retained chart/region/sheet authority and a component singleton derived from retained charts; no representative-sheet/component semantic selection.
- [x] Adjudicate `M6-CP1-TB9-A7-EXEC-CAND-01` as cause-proved/non-stable existing `RP-01`; accounting stays **60 / 16 / 44**, debt 1.
- [x] Reject/unpromote `11287202960 / b8d27b63...`; reviewed runtime remains TB8 `11265967968 / 8e0818b1...`.
- [ ] **Exact next `M6-CP1-CB9-A7-R1`:** implement only RA-22 completion-consumer recovery; compile/package only, runtime forbidden.
- [ ] Compile-green -> `M6-CP1-TB9-A7-R1-EXEC`: unchanged focused20 + selector449 = **469** -> mandatory `M6-CP1-TB9-A7-R1-REV`.
- [ ] Keep CB10 held until recovery Review; do not change focused20, selector449, fixtures, A7 producer, RA-18 or relation/transport semantics.

## Current — `M6-CP1-TB9-A7-EXEC` COMPLETE / 468/469 semantic RED / mandatory Review next (2026-10-04)

- [x] Consume immutable candidate `11287202960 / b8d27b63425c11c27c45a1e7b9e2b866b0e1e8b8`.
- [x] Execute focused20 then selector449: **469** fresh exact-filter processes, exact-one, zero skips, benchmark 0.
- [x] Record focused **19/20**, selector **449/449**, aggregate **468/469**.
- [x] Localize sole RED to focused20 real production completion ownership: `CompletionOwnershipInvalidSelectedRelationDestination` after materialization succeeds.
- [x] Record `M6-CP1-TB9-A7-EXEC-CAND-01` as Review-owned/non-stable candidate `RP-01`; stable accounting remains **60/16/44**, debt 1.
- [ ] **Exact next `M6-CP1-TB9-A7-REV`:** independently adjudicate the class-wide A7 relation authority vs representative-anchored completion destination predicate and candidate promotion/rejection.
- [ ] CB10 (RA-19, 473) remains held until TB9 Review explicitly authorizes it.

## Current — `M6-CP1-CB9-A7` COMPLETE / compile-package GREEN / exact next `M6-CP1-TB9-A7-EXEC` (2026-10-03)

- [x] Implement immutable A7 `SourceAttachedGeometryProduct` / producer and RA-18 typed support + reject-only same-simplex point guard.
- [x] Remove the adapter's old semantic `1e-9` point-coincidence check.
- [x] Add focused identities 13-20; focused-20 SHA-256 `15d04a2a09eeb678923b0bfcf70bf9c07b79e7ff343ec468316f6510b16827d2` and exact focused-12 prefix verified.
- [x] Compile/package all eight standard GMP/GMPXX targets at `b8d27b63425c11c27c45a1e7b9e2b866b0e1e8b8` using run/job `37160018910 / 111311373537`; candidate artifact `11287202960`; `runtimeExecution=false`.
- [x] Diagnose and repair the two compile-only defects without executing Directional runtime.
- [ ] **Exact next `M6-CP1-TB9-A7-EXEC`:** immutable candidate `11287202960`, **20+449 = 469** fresh exact-filter processes.
- [ ] Mandatory `M6-CP1-TB9-A7-REV`.
- [ ] Then CB10 (RA-19, 473), CB11 (RA-20/RA-21, 477), `M6-CP1-CLOSE-REV`.
- [ ] `M6-DEFN-R5` remains the CP3-entry gate.

## Superseded — pre-CB9 routing

## Current — `M6-DEFN-R4-REV` COMPLETE / R4 accepted with RA-18 – RA-21 / exact next `M6-CP1-CB9-A7` (2026-10-03)

- [x] Review the R4 record, D4 census, CB9-11 plans and frozen amendment against exact source (HEAD == `8e0818b1` semantics).
- [x] Re-derive the D2 pinned-literal claim independently: only rows 212, 227/230 and 139/140/142.
- [x] F1 → RA-18. The `1e-9` check is the only cross-relation point-coincidence detector, so add a reject-only same-simplex point guard. Support comes from A5 `occurrence.support` only. Identity 15 renamed.
- [x] F2 → RA-20. Protection comes from source hard-feature authority. The torus's 18 hard edges are PeriodicCut carriers.
- [x] F3 → RA-21. Oracle key path `(proposalId, proposalSide)` → A4 `CellId`/side, with a stop rule.
- [x] F4/F5 → RA-19. Moved A5 checks go after existing A5 checks; identity 24 is behavioral; the source rule is a static check.
- [x] Amend the CB9/10/11 plans; lessons 189-190.
- [ ] **Exact next `M6-CP1-CB9-A7`** (RA-18 block governs): compile/package only.
- [ ] `M6-CP1-TB9-A7-EXEC`, **20+449 = 469**, then mandatory Review.
- [ ] Then CB10 (473), CB11 (477), `M6-CP1-CLOSE-REV`.
- [ ] `M6-DEFN-R5` (CP3-entry): include the A5 HardRail-route-only chart-barrier census item.

## Superseded — `M6-DEFN-R4` completion checklist

- [x] D4 complete consumer/frozen-assertion census: 1,189 exact-snapshot references, 666 production + 523 test/benchmark.
- [x] D1 freeze immutable A7 product, exact typed SourceSupport incidence, deterministic representative, lineage projection, RA-17 transport guard and typed A7 failures.
- [x] D2 classify all 55 direct adapter failures: 31 A5 + 4 A6 projection + 19 A7 + 1 serialization; freeze stage precedence and thin-adapter predicate.
- [x] D3 freeze A6 `SurfaceQuotientClosedComplexView`, exact HardRail/Periodic label derivation, topology-derived strip identity, produced-torus labeled-isomorphism demonstration and independent mechanism oracle; CP3 keeps direct `G4-B002` debt proof.
- [x] D5 freeze CB9/CB10/CB11 sequences and focused 20/24/28 gates: 469 / 473 / 477 processes, respectively.
- [x] Append the pending-Review R4 amendment to `Architecture_M6_Frozen_Definitions.md` and write CB9/CB10/CB11 plans.
- [x] Durability closeout: exact documentation patch applied by run `37144877459` as commit `0f3024732e2f16b35c8c2a787a519378af2b9591`; changed-path authority verified; `runtimeExecution=false`.
- [ ] **Exact next `M6-DEFN-R4-REV`:** mandatory runtime-free Review. No CB9 implementation before Review acceptance.

## Current — `M6-CP1-TB8-A6-REV` review-agent addendum: promotion confirmed / R4 bounded (RA-17) / R4 next (2026-10-03)

- [x] Re-derive TB8 independently:
  - result digest, 954/954 manifest and five ledgers;
  - selector449 order, focused 1-12 order, the focused-12 raw log;
  - HEAD semantic source == `8e0818b1`.
- [x] Review the CB8 diff against RA-16:
  - coordinate-rigid HardRail derivation from occurrence placements;
  - the `canonicalRelationValue` decoupling;
  - A5-owned route predicate;
  - focused 3 and focused 12(b) discriminate (12(b) would fail the RA-14 rule).
- [x] Correct TB8-REV §3's overclaim: selector446 replicates the completion comparator and does not run it. Pre-register the witness production-completion identity for the first A7 CB.
- [x] Freeze `Architecture_M6_CP1_Required_Green_Focused_12.txt` (SHA-256 `59a523ae...3d571c`) as a required-green prefix.
- [x] Freeze RA-17:
  - transport guard;
  - R4 bounded to CP1 exit;
  - gauge obligations → `M6-DEFN-R5` (CP3-entry).
- [x] Write `Architecture_M6_DEFN_R4_CP1_A7_Thin_Adapter_G4B002_Definition_Plan.md`. Order: D4 census first, then D1 A7, D2 adapter 55-site classification, D3 `G4-B002`, D5 CB sequencing.
- [x] Record lesson 188.
- [ ] **Exact next `M6-DEFN-R4`:** runtime-free; follow the plan.
- [ ] Mandatory `M6-DEFN-R4-REV`. Then the A7/adapter/G4 CBs per D5, each gated by focused-12 + new identities + selector449.
- [ ] `M6-DEFN-R5` (CP3-entry): periodic face-gauge witness and rule; HardRail branch certification; OrdinaryFront identity across isolation seams.

## Superseded — `M6-CP1-TB8-A6-REV` pre-addendum checklist (R4 scope replaced by the R4 plan and RA-17)

- [x] Independently re-hash candidate `11265967968`, verify 28/28 root manifest, source `8e0818b1...`, GMP command boundary, selector449/routing449 hashes and row counts.
- [x] Independently verify TB8 result `11273611682`: **954/954** self-manifest, focused 12/12, selector449 449/449, aggregate **461/461**, exact-one, zero skips, benchmark 0 and empty RED ledger.
- [x] Verify immutable postflight and zero diagnostic census; re-open critical focused/selector outcomes.
- [x] Adjudicate TB7 stable recovery: HardRail placement authority, route-validation precedence and lineage-value regressions are **RECOVERY PROVED**; historical accounting stays **60 / 16 / 44**, debt 1.
- [x] Promote `11265967968 / 8e0818b1...` as current reviewed M6 runtime authority under selector449 449/449.
- [ ] **Exact next `M6-DEFN-R4`:** runtime-free Definition for A7 representation/certificates, thin adapter, `G4-B002` A6-derived boundary, carried periodic unequal-face-gauge witness/rule, HardRail branch certification and OrdinaryFront seam identity.
- [ ] Mandatory `M6-DEFN-R4-REV` before any A7/G4 Code + Build implementation.
- [ ] CP1 closure remains held until the frozen A7 / thin-adapter / `G4-B002` boundary scope is implemented and freshly gated.

## Current — `M6-CP1-TB8-A6-EXEC` COMPLETE / 461/461 GREEN / mandatory Review next (2026-10-03)

- [x] Consume CB8 candidate `11265967968 / 8e0818b1...` immutably.
- [x] Execute focused 1-12 then selector449: **461 fresh exact-filter processes**, **461/461 PASS**, exact-one, zero skips, benchmark 0.
- [x] Focused12 and full TB7 RED-set recovery verified; focused6/10/11 and selector139/140/142/232/444/446/448/449 PASS.
- [x] Zero raw holonomy/corner-authority/HardRail-transport/relation-certificate diagnostics; self-manifest **954/954**; immutable postflight.
- [x] No new candidate or stable repricing; **60 / 16 / 44**, debt 1; candidate remains unpromoted.
- [ ] **Exact next `M6-CP1-TB8-A6-REV`:** independently verify evidence, adjudicate recovery/promotion and authorize next work.
- [ ] Keep R4/A7/G4 held until TB8 Review.

## Current — `M6-CP1-CB8-A6` COMPLETE / compile-package GREEN / TB8 next (2026-10-03)

- [x] Implement RA-16 coordinate-rigid HardRail placement transport from occurrence placements; no branch comparison.
- [x] Decouple `canonicalRelationValue` from `canonicalTransport`; selected lineage steps consume the former while A6 certificates retain the latter.
- [x] Move exact HardRail route-authority validation into A5 with shared `exact_interior_route_valid` and preserve `InvalidHardRailAuthority`.
- [x] Strengthen focused 3 and add focused 12, `M6CP1.RelationPlacementTransportIsCoordinateRigidAndFaceGaugeInvariant`.
- [x] Preserve selector446 / `PureQuadCompletion.cpp`, selector449 / selector448-prefix / routing449, fixtures and A7/R4/G4.
- [x] Complete the required pre-CB7 lineage proof for OrdinaryFront, HardRail, exact-A3 Periodic and non-A3 Periodic in `Architecture_M6_CP1_CB8_A6_Code_Build_Report.md`.
- [x] Apply source patch at `2b182f1c...`; diagnose the declaration-order-only test compile failure; apply bounded test-local repair at `8e0818b1...`.
- [x] Mandatory compile/package retry `37101997642 / 111143233041` GREEN on all eight GMP/GMPXX targets; candidate artifact `11265967968`; `runtimeExecution=false`.
- [ ] **Exact next `M6-CP1-TB8-A6-EXEC`:** focused 1-12 in order, then selector449 in file order with routing449 = **461** fresh exact-filter processes, benchmark 0.
- [ ] Recovery-green is **461/461** -> mandatory `M6-CP1-TB8-A6-REV`.
- [ ] Keep `M6-DEFN-R4`, A7, `G4-B002`, `G4-B004` representative half and direct-torus debt held until TB8 Review.

Stable accounting remains **60 / 16 / 44**, debt 1. Reviewed runtime authority remains TB5 `10879581622 / 82b86a28...` until TB8 Review.

## Current — `M6-CP1-TB7-A6-REV` review-agent addendum: RA-16 / CB8 amended / TB8 = 461 (2026-10-03)

- [x] Re-derive the TB7 evidence: digest, 953/953 manifest, three ledgers, selector order, 460 raw logs. Verify the downstream-row grouping in code (`RemeshPipeline.cpp:11912`, `:14302`).
- [x] Confirm Finding A's diagnosis: HardRail route steps carry identity transport (`SurfaceCellTracing.cpp:11670-11672`). Correct the remedy: RA-14's branch-derived `R` is off by the field matching across the rail, because `branchRotation` is face-gauged.
- [x] Overturn Finding C. Selector446 restates the production completion check (`PureQuadCompletion.cpp:1086-1132`, run at `RemeshPipeline.cpp:10705`); CB7 rewrote the M5 lineage step transport. CAND-03 becomes a stable RP-01 recurrence → **60 / 16 / 44**, debt 1.
- [x] Freeze RA-16:
  - coordinate-rigid HardRail placement transport from occurrence placements;
  - `canonicalRelationValue` decoupled from `canonicalTransport`;
  - A5-owned route validity;
  - RA-14 items 2-5 superseded; RA-13 item 1 withdrawn.
- [x] Amend the CB8 plan:
  - revoke the selector446 migration and the `PureQuadCompletion.cpp` edit;
  - add the A2 decoupling;
  - strengthen focused 3; add focused 12 (face-gauge relabel invariance plus the witness coordinate rule);
  - TB8 = 12+449 = 461.
- [x] Record lessons 186-187.
- [ ] **Exact next `M6-CP1-CB8-A6` as amended:** compile/package only; runtime forbidden.
- [ ] CB8 green -> `M6-CP1-TB8-A6-EXEC`: exactly **12+449 = 461** fresh processes -> mandatory `M6-CP1-TB8-A6-REV`.
- [ ] Carried to `M6-DEFN-R4`:
  - an exact-A3 periodic face-gauge witness (unequal corresponding-corner `faceBranchRotation`) with the coordinate-rule replacement;
  - cross-region branch certification for HardRail;
  - OrdinaryFront coordinate identity across isolation seams.

## Superseded — `M6-CP1-TB7-A6-REV` pre-addendum checklist (its CB8 scope is replaced by RA-16)

- [x] Independently re-open TB7 result `11262587435`, raw RED logs, 953/953 self-manifest and exact source; confirm mechanically valid **443/460** semantic RED.
- [x] Adjudicate CAND-01 as one stable `RP-01` recurrence: HardRail carrier route is not cut-domain placement transport; direct + downstream losses share one first mechanism.
- [x] Adjudicate CAND-02 as one stable `VALIDATION_ORDER_SHADOWING` recurrence: rows227/230 route-authority typing is pre-empted by earlier pair reciprocity.
- [x] Close CAND-03 as non-stable test authority: selector446 production recovers; stale assertion compares RA-13 placement transport to relation-endpoint semantic action.
- [x] Freeze RA-14 HardRail carrier/placement separation and RA-15 individual-route-before-pair validation; stable accounting **59 / 16 / 43**, debt 1.
- [x] Reject/unpromote `11257522199 / 40842caa...`; retain reviewed runtime `10879581622 / 82b86a28...`, selector449 449/449.
- [ ] **Exact next `M6-CP1-CB8-A6`:** implement RA-14/RA-15 and selector446 gauge-aware assertion migration, compile/package only, runtime forbidden.
- [ ] CB8 green -> `M6-CP1-TB8-A6-EXEC` exact **11+449=460** fresh processes -> mandatory `M6-CP1-TB8-A6-REV`.
- [ ] Keep `M6-DEFN-R4`, A7, `G4-B002`, `G4-B004` representative half and direct-torus debt held until TB8 Review.

## Current — `M6-CP1-TB7-A6-EXEC` COMPLETE / mechanically valid 443/460 RED / exact next `M6-CP1-TB7-A6-REV` (2026-10-03)

- [x] Consume candidate `11257522199 / 40842caa...` immutably; verify package/source/selector/routing/modes and construct the separate packaged-fixture execution view without repair.
- [x] Execute exact **11 focused + 449 selector = 460** fresh exact-filter processes: focused **11/11 PASS**, selector **432/449 PASS**, aggregate **443/460 PASS / 17 RED**; exact-one selection and zero skips hold.
- [x] Confirm CB7 target recoveries: focused6 PASS; rows139/142 reject correctly; row140 and 232/444/448/449 PASS; zero raw `QuotientHolonomyConflict` and zero `OccurrenceInvalidCornerAuthority`.
- [x] Record the 17 REDs in the regression tracker as three non-stable Review-owned candidate envelopes; keep stable accounting **57 / 16 / 41**, debt 1.
- [x] Preserve semantic RED without repair/rerun; no configure/compile/relink/discovery/benchmark/package/test/fixture/selector mutation occurred.
- [ ] **Exact next `M6-CP1-TB7-A6-REV`:** independently re-open result `11262587435`, adjudicate CAND-01 HardRail gauge authority, CAND-02 typed validation precedence, CAND-03 row446 RA-13 test authority, stable accounting and candidate promotion/rejection.
- [ ] Keep `M6-DEFN-R4`, A7, `G4-B002`, `G4-B004` representative half and direct-torus debt held until TB7 Review.

Candidate `11257522199 / 40842caa...` remains unpromoted. Reviewed runtime authority remains `10879581622 / 82b86a28...`, selector449 449/449.

## Review-agent addendum — `M6-CP1-TB6-A6-REV` (2026-10-02)

- [x] TB6 re-verified; Finding A upheld (fail-open guard loss); 57/16/41 with debt 1 upheld.
- [x] Finding B corrected: gauge mixing, not legitimate holonomy. Residual fallback revoked; RA-13 frozen; CB7 plan amended (§3 replaced, §4.2 revoked).
- [x] `M6-CP1-CB7-A6`: Goal A + RA-13 implemented and compile/package green at `11257522199 / 40842caa...`; runtime remains held for TB7.
- [ ] `M6-CP1-TB7-A6-EXEC` (460, same order; 446 and focused 6 must pass strict) → `M6-CP1-TB7-A6-REV`.

## Historical initial `M6-CP1-TB6-A6-REV` conclusion — superseded by the 2026-10-02 review-agent addendum

- [x] Reconcile both TB6-A6 Actions runs; authoritative run `36362570974` is mechanically valid at **456/460 PASS**.
- [x] Reject/unpromote candidate `10896307843 / a532f803...`; retain reviewed runtime `10879581622 / 82b86a28...`, selector449 449/449.
- [x] Reprice stable history to **57 / 16 / 41**, debt 1: selector446 = existing `RP-07` recurrence; rows139+142 = one `VALIDATION_ORDER_SHADOWING` recurrence.
- [x] Invoke and freeze R3 residual-holonomy fallback: cycle-closing A6 publishes exact `D`, `P`, `H=compose(P.inverse(),D)`; nonidentity residual alone is not `QuotientHolonomyConflict`.
- [x] Confirm focused row4 migration is runtime-green/value preserving; A6 focused8-11 all PASS.
- [ ] **Exact next `M6-CP1-CB7-A6`:** restore A5 HardRail reciprocal region/reversed-route validation; implement exact cycle residual evidence; strengthen A6 certificate-to-A5 authority validation; keep focused count 11.
- [ ] CB7-A6 compile/package only using standard eight GMP/GMPXX targets; `runtimeExecution=false`; no selector/fixture/A7/R4/G4 mutation.
- [ ] Compile-green -> `M6-CP1-TB7-A6-EXEC`, exact **11+449=460** fresh processes -> mandatory `M6-CP1-TB7-A6-REV`.
- [ ] Keep `M6-DEFN-R4`, A7, `G4-B002`, `G4-B004` representative half and direct-torus debt held until recovery Review.

## Superseded EXEC-only interpretation — mandatory Review found an authoritative second run

- [x] Re-verify candidate `10896307843 / a532f803...` immutably: ZIP/source hashes, root 28/28, selector/routing449, owner census and executable modes unchanged.
- [x] Record the execution error: package binaries were run without the standard separate adjacent `test-data/benchmarks/fixtures` execution view. Six completed tests failed only on that missing fixture package.
- [x] Stop invalid attempt after 149 completed exact-filter processes; do not rerun because the frozen plan forbids retry after runtime starts.
- [x] Record +0 regression/accounting disposition and preserve candidate immutability.
- [ ] `M6-CP1-TB6-A6-REV`: mandatory next turn; adjudicate zero semantic credit and explicitly authorize/name any fresh retry turn if warranted.
- [ ] Keep `M6-DEFN-R4`, A7 and `G4-B002` held until valid runtime evidence plus Review.

Accounting remains **55 / 16 / 39**, debt 1. Reviewed runtime authority remains `10879581622 / 82b86a28...`; candidate `10896307843 / a532f803...` is unpromoted.

## Superseded TB6-A6 pre-execution gate (review-agent reconciliation, 2026-09-28)

- [x] CB6-A6 COMPLETE (candidate `10896307843 / a532f803`); handoff consistent.
- [x] Froze the exact 460-process order now folded into `M6_Consolidated_Record.md` §24: focused 1-7 in TB5 order, new 8-11, then selector449; all focused route to the producer tests. Holonomy falsifiers are row232 and 444/446/448/449, with no `QuotientHolonomyConflict` allowed.
- [x] `M6-CP1-TB6-A6-EXEC` completed as orchestration-invalid / zero semantic credit → mandatory `M6-CP1-TB6-A6-REV`.

## Superseded — `M6-CP1-CB6-A6` COMPLETE; TB6-A6 attempt now closed invalid

- [x] A6 quotient-product extraction and legacy-field retirement are compile/package green at semantic source `a532f803bd2f0ef92342652ea3f1a9b64945ba69`.
- [x] Compile R1 `36212725707 / 108322509801` packages candidate `10896307843` (28/28, eight GMP/GMPXX targets, clean receipts, `runtimeExecution=false`). First compile `36212343902` failed on declaration clashes and was superseded only by the bounded `a532f803` compile fix.
- [x] CB report records RA-1 – RA-4 static compliance and the focused row4 `lattice` → `placement.lattice` value-identical migration. Prior CB6-A6 compile/snapshot temporary state was retired through cleanup run `36358568335`.
- [x] TB6-A6 EXEC attempted; orchestration invalid because the standard adjacent test-data execution view was not constructed. No semantic gate credit and no same-turn retry.
- [ ] Mandatory `M6-CP1-TB6-A6-REV` before any promotion, fallback, R4, A7 or `G4-B002` work.
- [ ] `M6-DEFN-R4` remains deferred until the A6 implementation/gate/Review sequence completes.

Accounting remains **55 / 16 / 39**, debt 1. Reviewed runtime authority remains `10879581622 / 82b86a28...`, selector449 449/449; candidate `10896307843 / a532f803` is unpromoted.

## Superseded historical checklist — `M6-DEFN-R3` definition closeout (Review now complete)

- [x] Freeze CP1 exit checklist, A6 member-set identity, exact-once joining/cycle-closing ledger, cycle transport consistency, selected-path ownership and A6 failure vocabulary.
- [x] Record analytic split-square / uniform hard-rail / ordinary-identity holonomy proof and pre-register produced cylinder row232 + torus rows444/446/448/449 as TB falsifiers.
- [x] Write `Architecture_M6_DEFN_R3_A6_Product_Separation_Definition_Record.md` and the normative frozen-definition amendment.
- [x] Write the now-consumed CB6-A6 plan (folded into `M6_Consolidated_Record.md` §§23-25); four new focused identities; later gate = **11 + 449 = 460**.
- [x] Mark standalone legacy-field CB6 plan superseded/held; retirement is folded into A6 extraction.
- [x] **Historical exact next completed:** `M6-DEFN-R3-REV` accepted and authorized `M6-CP1-CB6-A6`.
- [ ] `M6-DEFN-R4` before A7 CB: freeze A7 product representation and exact `G4-B002` A6 stage boundary.

## Recovery — `M6-DEFN-R3` stalled after its start beacon; resume the same turn with the bounded scope (2026-09-25T21:13:47Z)

- [x] Recovery verified: only beacon `cd084a0d`; no record, snapshot or Drive patch. Beacon repaired to canonical form (it had `NONE` values).
- [x] DEFN-R3 plan bounded (§5): A6-only decisions plus the A6 CB plan. A7 and `G4-B002` deferred to `M6-DEFN-R4`. The holonomy static proof on produced fixtures is replaced by an analytic proof plus a TB falsifier.
- [ ] Resume `M6-DEFN-R3` (keep Started at 20:10:00Z; new Resumed at) → `M6-DEFN-R3-REV` → A6 extraction CB.

## Review-agent addendum — `M6-CP1-TB5-REV` (2026-09-25)

**TB5 recovery and promotion upheld; CP1 scope corrected; exact next `M6-DEFN-R3`.** See `M6_Consolidated_Record.md` §22 (TB5 Review/addendum) and `Architecture_M6_DEFN_R3_CP1_Product_Separation_Plan.md`.

- [x] `M6-DEFN-R3`: bounded A6 definition complete. A7 representation and exact `G4-B002` boundary intentionally deferred to `M6-DEFN-R4`.
- [x] `M6-DEFN-R3-REV` — accepted; bounded R3 record and A6 plan reviewed.
- [x] `M6-CP1-CB6-A6` — completed compile/package green; runtime gate remains 11 focused + selector449 = 460 -> mandatory Review.
- [ ] A7 extraction and adapter thinning CB, then TB, then Review.
- [ ] `G4-B002` A6 stage-boundary CB, then TB, then Review, then CP1 closure Review against the restated exit scope.
- [x] ~~CB6 standalone legacy-field retirement~~ — HELD and folded into the A6 CB.

## M6-CP1-TB5 Review complete — bounded CB6 product-surface cleanup next (2026-09-25)

**TB5 Review: RECOVERY ACCEPTED / runtime candidate PROMOTED / CP1 OPEN only on static A5 product shape. Exact next: `M6-CP1-CB6`.** Current reviewed runtime authority is `10879581622 / 82b86a28...` under selector449 **449/449**. Stable accounting remains **55/16/39**, debt **1**.

- [x] Independently re-open candidate package/source and TB5 result/log: package 28/28, result 933/933, exact 456/456 mechanics and immutable postflight upheld.
- [x] Formal recovery: TB1 iterator-range, TB3 RP-01 and TB4 RP-01 are RECOVERY PROVED; TB2 validation-order remains recovery-proved. Historical stable counts remain intact.
- [x] Promote CB5/TB5 package/source `10879581622 / 82b86a28...` as current reviewed runtime authority under unchanged selector449.
- [x] Correct stale TB4-REV debt: aggregated lineage `equivalences` are already sorted/de-duplicated after tuple remap in exact candidate source; no code change required.
- [ ] `M6-CP1-CB6`: remove unread public `SurfaceOccurrence.chart`, `.lattice`, `.isolationSheet` plus matching constructor/call-site arguments only; preserve every live A5 semantic field.
- [ ] CB6 compile/package standard eight GMP/GMPXX targets with `runtimeExecution=false`; no generated runtime.
- [ ] Compile-green -> `M6-CP1-TB6-EXEC`, unchanged **7 focused + selector449 = 456** -> mandatory `M6-CP1-TB6-REV`; only that Review may close CP1.

## Historical — M6-CP1-TB5 EXEC complete (2026-09-25)

**TB5 is COMPLETE / MECHANICALLY GREEN / 456/456 / CANDIDATE UNPROMOTED. Exact next: `M6-CP1-TB5-REV`.** Stable accounting remains **55/16/39** in EXEC, debt **1**; accepted M5 package `10814505512` / selector449 449/449 remains runtime authority pending Review.

- [x] Consume candidate artifact `10879581622` immutably; verify package/source/selector/routing and archived executable modes without repair.
- [x] Execute exactly **7 focused + selector449 = 456** fresh exact-filter processes: **456/456 PASS**, exact-one, zero skips/crashes/selection mismatches, benchmark 0.
- [x] Recover all 21 TB4 accepted-prefix losses and the carried torus falsifier (focused row6 + selector 444/446/448); keep rows5/7 and row140 green.
- [x] Record regression gate: **no new regression candidate / +0 stable accounting in EXEC**; formal recovery and promotion remain Review-owned.
- [x] `M6-CP1-TB5-REV`: recovery accepted and candidate promoted; CP1 held only by the static legacy-field precondition.
- [ ] Moved to exact successor `M6-CP1-CB6`: remove unread legacy `SurfaceOccurrence.chart`, `.lattice`, `.isolationSheet`; keep `point` and `chartComponent`.
- [x] Review correction: exact source already sorts/de-duplicates aggregated lineage `equivalences` after tuple remap; stale debt withdrawn.

## M6-CP1-CB5 complete — immutable TB5 next (2026-09-25)

**CB5 is COMPLETE / COMPILE+PACKAGE GREEN / RUNTIME-FREE. Exact next: `M6-CP1-TB5-EXEC` → mandatory `M6-CP1-TB5-REV`.** Stable accounting remains **55/16/39**, debt **1**; accepted M5 package `10814505512` / selector449 449/449 remains runtime authority.

- [x] Correct A6 OrdinaryFront collinear/no-certificate spans to the non-seam same-sheet + both-wedges P2 predicate; preserve certificate-backed seam validation.
- [x] Implement RA-12 site-qualified legacy isolation diagnostics without changing tests or semantic failure prefixes.
- [x] Static audit: only `src/pipeline/RemeshPipeline.cpp` changed semantically; selector449/routing449 hashes remain frozen.
- [x] Compile/package the standard eight targets with GMP/GMPXX; run/job `36168827294 / 108183151046`, artifact `10879581622`, manifest 28/28, clean source receipts, `runtimeExecution=false`.
- [x] **TB5:** artifact `10879581622` consumed immutably; **7/7 focused + 449/449 selector = 456/456 PASS** with exact immutable postflight.
- [x] **TB5 Review:** 456/456 upheld; TB1/TB3/TB4 recovery proved; candidate promoted; CP1 remains open only on CB6 field retirement.
- [ ] Current owner `M6-CP1-CB6`: retire unread legacy `SurfaceOccurrence.chart`, `.lattice`, `.isolationSheet`; keep `point` and `chartComponent`.
- [x] TB5 Review correction: exact source already sorts/de-duplicates after tuple remap; no implementation owed.

## Review-agent addendum — `M6-CP1-TB4-REV` (2026-09-25)

**Upheld 55/16/39; exact next `M6-CP1-CB5` as amended.** See `M6_Consolidated_Record.md` §§19-20 (TB4 Review/addendum).

- [x] CB5: A6 collinear span with no certificate → non-seam P2 rule; certificate present → seam branch unchanged.
- [x] CB5: RA-12 site suffixes on every `Missing/InvalidIsolationSeamEquivalenceAuthority` emission (A5 adapter and the four A6 sites).
- [x] TB5 (456): **456/456 PASS**; there is no residual RA-12 failure to classify in EXEC. Formal recovery is Review-owned.
- [ ] CP1-acceptance precondition: remove or relabel the unread legacy `SurfaceOccurrence` fields `isolationSheet`, `chart` and `lattice` (`point` is live; `chartComponent` is legitimate).
- [ ] Minor: re-sort aggregated lineage `equivalences` after tuple remap.

## M6-CP1-TB4 Review complete — bounded CB5 next (2026-09-25)

**Review verdict:** TB4 mechanics are upheld; `M6-CP1-TB4-EXEC-CAND-01` is one new stable `RP-01 / AUTHORITY_DOMAIN_CONFLATION` recurrence. Stable accounting is **55 / 16 / 39**, debt **1**. Candidate `10871935178` stays unpromoted; accepted M5 package `10814505512` / selector449 449/449 remains authority.

- [x] Independently re-verify candidate package 28/28, TB4 result 932/932, accepted M5 result 911/911, exact 456-process mechanics and selector/prefix/routing hashes.
- [x] Prove root: A5's `collinearEdge` is generic source-edge support, while A6 incorrectly consumes every such edge as isolation-seam certificate authority.
- [x] Record one new stable RP-01 recurrence; totals **55/16/39**. Carry TB3 and TB1 formal recovery clauses; keep TB2 validation-order recovery closed.
- [ ] **Exact next `M6-CP1-CB5`:** one A6 OrdinaryFront P2 correction only — no certificate means non-seam same-sheet + both-wedges validation; exact certificate means existing seam face/sheet/reciprocal-evidence validation.
- [ ] CB5 compile/package only, standard eight GMP/GMPXX targets, `runtimeExecution=false`; no test/fixture/selector or A5/schema change.
- [ ] Compile-green → `M6-CP1-TB5-EXEC`, unchanged **7 + 449 = 456** exact processes → mandatory `M6-CP1-TB5-REV`.

## M6-CP1-TB4 EXEC complete — mandatory Review next (2026-09-25)

**TB4 is COMPLETE / MECHANICALLY VALID / SEMANTIC NON-GREEN / CANDIDATE UNPROMOTED.** Run/job `36157505252 / 108145613689` executed exactly 456 fresh exact-filter processes from immutable artifact `10871935178`: focused **6/7**, selector449 **425/449**, aggregate **431/456 PASS**.

- [x] Immutable artifact/package/source/selector/routing preflight and postflight; exact-one selection, zero skips, no watchdog, no build/repair/benchmark execution.
- [x] Seven focused + selector449 = 456 processes executed exactly once.
- [x] Record `M6-CP1-TB4-EXEC-CAND-01` for the 21 newly RED accepted-selector identities; stable accounting remains 54/16/38 in EXEC.
- [ ] **Exact next:** mandatory runtime-free `M6-CP1-TB4-REV`; independently adjudicate all 24 selector REDs and formal recovery status.
- [ ] Do not rerun TB4 or start a corrective Code + Build turn before Review.

## M6-CP1-CB4 complete — immutable TB4 next (2026-09-25)

**CB4 is COMPLETE / COMPILE+PACKAGE GREEN / RUNTIME-FREE.** Semantic source `20f60bb1412424a6f1093fc8076884d1ea23f1c5`; candidate artifact `10871935178` is unpromoted.

- [x] Implement R2 + RA-1 – RA-11 complete wedge binding/isolation authority, relation-local selected-path charts, tuple-first remap, reciprocal side validation and the strengthened seventh focused identity.
- [x] Static frozen-gate audit complete; selector449/routing449 remain byte-identical (`d4a0d1b7...d6414` / `9c88a5ed...c5707`).
- [x] Compile/package all eight standard targets with mandatory GMP/GMPXX; run/job `36150253128 / 108121497728`, artifact `10871935178`; `runtimeExecution=false`.
- [x] `M6-CP1-TB4-EXEC` — mechanically valid immutable 456-process execution complete; semantic result 431/456 PASS, candidate unpromoted.
- [ ] Then mandatory `M6-CP1-TB4-REV`.

Stable accounting remains **54 / 16 / 38**, debt 1. Accepted runtime authority remains M5 package `10814505512`; no CB4 runtime credit/promotion.

## CB4 blocker resolved — RA-11 (2026-09-25, review agent)

**`M6-CP1-CB4` is UNBLOCKED; resume the same turn.** No consumer needs a per-face branch. Wedge bindings are `(face, sheet, chart)`, and the A4 corner lattice state is published as face-labelled placement provenance. See the blocker record's "Review-agent adjudication".

- [x] Blocker facts re-verified; RA-11 frozen (no A4 change, no raw field input, no representative branch).
- [ ] Resume `M6-CP1-CB4` (preserve `Started at 2026-09-25T06:19:30Z`) and implement R2 + RA-1 – RA-11; compile the eight GMP targets.
- [ ] `M6-CP1-TB4-EXEC` 7 + 449 = 456 → `M6-CP1-TB4-REV`.

## CB4 static blocker — per-face branch authority unavailable at A5 boundary (2026-09-25)

**`M6-CP1-CB4` stopped before production/test mutation and before compile.** Exact snapshot inspection shows D6/R2 requires a per-source-face `branchRotation` in every `CornerWedgeFaceBinding`, while immutable A4 `SurfacePhaseFrontProduct` exposes only corner-selected `LocalLatticeState.branchRotation`, side-segment branch data, and isolation-seam transport certificates. It does not preserve the builders' complete per-face branch table or an ordinary-edge field-transport atlas. An intermediate corner-wedge face can therefore have no derivable exact branch value at A5. See `M6_Consolidated_Record.md §16 (folded RA-11 blocker authority)`.

- [x] Per-face branch authority source resolved by review amendment RA-11 (no Definition turn needed).
- [x] CB4 re-authorized: resume the same turn under RA-1 – RA-11.
- [ ] TB4 remains held; no compile artifact or runtime credit exists for this CB4 attempt.

## Review — `M6-DEFN-R2-REV` (2026-09-25)

**ACCEPTED WITH REVIEW AMENDMENTS RA-1 – RA-10; exact next `M6-CP1-CB4`.** See `Architecture_M6_DEFN_R2_Review_Record.md`.

- [x] B1-B4 and P1-P4 re-derived; the orientation premise is proved in all three builders; consumer neutrality of `CornerWedgeIsolation` confirmed.
- [x] RA-1 – RA-10 frozen (boundary edges, P3/P4 predicates, row-invariant permutation checks, row3 `UnownedRelation`, wedge-union lineage, `crossesSheets` retirement, arc endpoints and direction, resolver tolerance, transitional `quotientClass`).
- [ ] `M6-CP1-CB4` under the amended plan → compile/package the eight GMP targets (no runtime). **Not yet started**: the aborted 05:40Z session produced nothing, so enter as a fresh turn (see handoff recovery note).
- [ ] `M6-CP1-TB4-EXEC` 7 + 449 = 456 → `M6-CP1-TB4-REV`.

## Definition amendment complete — `M6-DEFN-R2` (2026-09-25)

**RUNTIME-FREE / B1-B4 + P1-P4 frozen for Review / CB4 HELD / exact next `M6-DEFN-R2-REV`.** See `Architecture_M6_DEFN_R2_Seam_Incident_Authority_Amendment_Definition_Record.md`.

- [x] B1: freeze evidence-only `CornerWedgeIsolation` lineage equivalence with ordered exact `(region,seam,fromSheet,toSheet)` transitions; v0/center/v2 row5 semantics now satisfiable without invented relations.
- [x] B2: freeze complete occurrence binding signatures, relation-local selected-path charts/components, tuple-preserving remap, and union-of-all-bindings lineage charts.
- [x] B3: freeze exact `SourceSupport` collinearity + canonical cell-interior incident-face rule and prove its orientation premise for uniform, periodic-chart and bounded-disk builders.
- [x] B4: split A5 relation failures 1:1 and freeze compatibility-adapter mappings without weakening M5 semantic checks.
- [x] P1-P4 and frozen-test audit over focused rows 5/6, selector rows 186/214/239/444/446/448, and HardRail single-sheet assertions.
- [x] Re-scope CB4 implementation and strengthen the seventh focused identity; TB4 remains **7+449=456**.
- [ ] Mandatory `M6-DEFN-R2-REV`; only an accepted Review may authorize `M6-CP1-CB4`.

## Historical Review — `M6-DEFN-R1-REV` (2026-09-25)

**Core corner-wedge model UPHELD; not accepted as frozen; CB4 HELD; exact next `M6-DEFN-R2`.** See `Architecture_M6_DEFN_R1_Review_Record.md` and `Architecture_M6_DEFN_R2_Amendment_Plan.md`.

- [ ] B1: represent verified wedge/collinear-side evidence in `PureQuadVertexLineage::equivalences` (new equivalence kind); prove focused row5 passes at v0 and v2; the seventh identity also asserts lineage (v0/centre/v2 `{0,1}`, others singleton).
- [ ] B2: binding-selection rule for the transitional `QuotientDomainState`/`QuotientClassId` ordinal, `representative_key`, selected-path charts and chart components (rows 444/448), and lineage `sourceCharts`; `chartComponent` occurrence-wide with a fail-closed check.
- [ ] B3: collinearity by exact segment `SourceSupport`; one interior-face rule across `segment_on_source`, `periodic_chart_segment` and `bounded_disk_chart_segment`; prove per builder that cell orientation agrees with source winding.
- [ ] B4: split A5 relation failures 1:1 and map them at the adapter to legacy M5 names (or amend §4.6 explicitly).
- [ ] P1-P4, and a frozen-test audit over rows 5, 6, 186, 214, 239, 444, 446, 448 and the HardRail single-sheet rows.
- [ ] `M6-DEFN-R2-REV`, then the re-scoped `M6-CP1-CB4` → TB4 (7+449=456) → TB4-REV.

## Definition complete — `M6-DEFN-R1` (2026-09-25)

**RUNTIME-FREE / eight seam-incident authority decisions frozen / CB4 re-scoped but HELD / exact next `M6-DEFN-R1-REV`.** Occurrence isolation authority is now the complete corner-wedge sheet set with per-wedge face/chart/branch provenance; seam certificates live on the wedge or directed side that actually crosses/runs along the seam; `OrdinaryFront` remains owner-less; seam-collinear sides use exact incident-cell interior-face authority; A7 lineage unions member wedge sets; row140 legacy naming is adapter-only.

- [x] Freeze corner-wedge sheet/certificate authority and seam-vertex rule.
- [x] Freeze A6 ordinary relation membership/side-evidence checks with unchanged `OccurrenceRelationId`.
- [x] Freeze seam-collinear side semantics and per-wedge provenance.
- [x] Freeze A7 lineage completeness and row140 adapter/duplicate-check policy.
- [x] Re-scope CB4/TB4; new focused identity `M6CP1.SeamEndpointOccurrencesPublishCompleteCornerWedgeSheetAuthority`; gate **7+449=456**.
- [x] Mandatory `M6-DEFN-R1-REV`: core upheld; amendments B1-B4/P1-P4 routed to `M6-DEFN-R2`.
- [ ] Only after Review acceptance: re-scoped `M6-CP1-CB4` → `M6-CP1-TB4-EXEC` → `M6-CP1-TB4-REV`.

## Review-agent addendum — `M6-CP1-TB3-REV` (2026-09-25)

**Accounting upheld 54/16/38, debt 1. Root cause corrected; CB4 HELD; exact next `M6-DEFN-R1`.** CB3's outgoing-side occurrence sheet is a representative choice at seam-incident corners, where a cell's wedge spans two sheets. A relation-owned certificate is on the wrong object and is ambiguous at seam vertices. See the TB3 Review addendum A2-A7.

- [ ] `M6-DEFN-R1`: freeze occurrence sheet authority at seam-incident corners (recommended: corner-wedge sheet set).
- [ ] `M6-DEFN-R1`: freeze the certificate carrier (recommended: wedge certificates keyed by the seam edges the wedge crosses) and the rule at seam vertices.
- [ ] `M6-DEFN-R1`: A6 relation check (side sheet in both endpoint wedge sets); `OrdinaryFront` stays owner-less and `OccurrenceRelationId` is unchanged.
- [ ] `M6-DEFN-R1`: A7 lineage completeness (split-square v0 and v2 record {0,1}); single-face occurrence record; sides collinear with a seam.
- [ ] `M6-DEFN-R1`: policy for the row140 adapter mapping and the three unreachable duplicate M5 checks.
- [ ] `M6-DEFN-R1`: re-scope CB4/TB4; recommended new focused identity (7+449=456).
- [ ] `M6-DEFN-R1-REV`, then re-scoped `M6-CP1-CB4` → TB4 → TB4-REV.

## Latest Review turn — `M6-CP1-TB3-REV`

**COMPLETE / ONE NEW STABLE RP-01 RECURRENCE / CANDIDATE UNPROMOTED.** Independent Review upholds TB3 at focused **4/6** + selector449 **443/449** = **447/455 PASS** with exact immutable postflight. Accepted M5 result `10815911956` independently re-verifies **449/449 PASS**, confirming selector losses **186, 214, 239, 444, 446, 448** are accepted-prefix regressions.

All six plus focused multi-isolation/pair-swap stop at `MissingIsolationSeamEquivalenceAuthority`. Root cause is the missing frozen A5 relation-owned isolation-certificate reference for cross-sheet ordinary relations: the transitional consumer currently reconstructs semantic owner authority from front-edge boundary-path representation. This is one stable existing `RP-01 / AUTHORITY_DOMAIN_CONFLATION` recurrence. Stable accounting is **54 / 16 / 38**, debt **1**. Row140 recovery is proved; TB1 formal 449/449 recovery clause remains carried.

## HELD (re-scoped by `M6-DEFN-R2`) — `M6-CP1-CB4`

Runtime-free Code + Build, **not authorized until `M6-DEFN-R2-REV` accepts**. Implement complete wedge bindings/evidence, evidence-only `CornerWedgeIsolation` lineage projection, exact seam-collinear interior-face authority, the one-to-one A5 failure vocabulary/adapter, relation-local selected-path charts, tuple-preserving component remap, and P1/P2 reciprocal validation. Preserve occurrence/relation identity, relation-only quotient equality, tests/fixtures/selector449/routing449, Periodic/HardRail semantic owners and all M5 content/transport falsifiers.

Compile-green then advances to immutable `M6-CP1-TB4-EXEC` with seven focused + selector449 = **456** fresh exact-filter processes, then mandatory Review.

See `.agents/Directional/M6_Consolidated_Record.md §§10-16 (folded TB3 Review authority)` and `.agents/Directional/M6_Consolidated_Record.md §§12-18 (folded CB4 plan authority)`.

## Latest Code + Build turn — `M6-CP1-CB2`

**COMPLETE / COMPILE+PACKAGE GREEN / RUNTIME-FREE / CANDIDATE ONLY.** Exact semantic source `724316a5b3f49e33dc8e649989bb413b3dc6b7c9` materializes the A5 region isolation-sheet vector once, eliminating the Review-proved cross-temporary iterator range without changing region/component/sheet/support/chart semantics. Whole-tree split-range scan is clean; selector449/routing449 and all six focused identities are unchanged.

Mandatory GMP/GMPXX compile run/job `36061049526 / 107839861958` packages all eight standard targets as artifact `10834642074`, SHA-256 `754cfeae794da3304b39a572ef6feb6250709f908d5688dcd21f387a071d0cb8`, with **28/28** root manifest, clean source receipts and `runtimeExecution=false`. Candidate remains unpromoted; accounting stays **52 / 15 / 37**, debt 1.

## Historical successor — `M6-CP1-TB2-EXEC` (completed)

Consume artifact `10834642074` immutably. Execute the unchanged six focused identities followed by selector449 as exactly **455 fresh exact-filter processes**, exact-one selection and zero skips, benchmark 0, then exact immutable postflight. Recovery of `M6-CP1-TB1-EXEC-CAND-01` requires no `OccurrenceInvalidCornerAuthority` anywhere plus selector449 **449/449**. A focused RED with a different first failure is a new candidate. Every mechanically valid outcome advances to mandatory runtime-free `M6-CP1-TB2-REV` with no TB repair/rerun.

Superseded TB2 plan/report/Review authority is folded into `.agents/Directional/M6_Consolidated_Record.md`; current retained runtime evidence is `.agents/Directional/M6_Consolidated_Record.md §§9-11 (folded TB3 runtime authority)`, with adjudication in `.agents/Directional/M6_Consolidated_Record.md §§10-16 (folded TB3 Review authority)`.

## Latest Code + Build turn — `M6-CP1-CB1`

**COMPLETE / COMPILE+PACKAGE GREEN / RUNTIME-FREE / CANDIDATE ONLY.** Exact semantic source `ee8b8ac20571df5773f5f94bf9b382161f37a893` publishes semantic A5 occurrence identity/product authority and makes the transitional materializer consume `SurfaceOccurrenceComplex`. Final compile run/job `36038472933 / 107764451786` packages all eight standard GMP/GMPXX targets as artifact `10826090221` with 28/28 manifest, clean source receipts and `runtimeExecution=false`. Four new A5 identities compiled; TB1 has now executed the frozen six-test vector and selector449. Candidate runtime is semantic RED and unpromoted. Selector449 bytes remain exact `d4a0d1b7...d6414`; historical TB1 mechanics are Review-adjudicated at corrected stable accounting 52/15/37 and debt 1.

- [x] A5 `OccurrenceId=(CellId, canonicalCornerRole)` and immutable occurrence product/certificate extracted.
- [x] True source-face-row permutation test authored; A4 `CellId` semantics unchanged.
- [x] Endpoint-gauge dormant identity deleted; pair-swap identity retained for CP1 prepublication gate.
- [x] Focus vector frozen at six identities; accepted selector449 unchanged.
- [x] Final eight-target GMP/GMPXX compile/package green; no runtime.

## Latest Definition — `M6-DEFN-R2`

**COMPLETE / RUNTIME-FREE / B1-B4 + P1-P4 FROZEN FOR REVIEW.** Normative M6 semantics are the R2-amended `Architecture_M6_Frozen_Definitions.md`; CB4 remains HELD until `M6-DEFN-R2-REV` accepts.

## Latest Code + Build turn — `M5-CP4-CB2`

**COMPLETE / SELECTOR449 PUBLISHED / EIGHT-TARGET GMP COMPILE+PACKAGE GREEN / RUNTIME-FREE.** Publication source `e284fea7c101eb86650d1c87c92d0fefa66050e7`; compile run/job `36013904054 / 107681435506`; result/log `10814505512 / 10814141518`; package manifest 28/28; `runtimeExecution=false`. TB2 has now mechanically validated this exact package, but final acceptance remains Review-owned.

## Latest Test + Benchmark turn — `M5-CP4-TB1-EXEC`

**COMPLETE / 449 PASS + 0 RED / REVIEWED PREPUBLICATION EVIDENCE.** Run/job `35937669401 / 107438319768`; result/log `10784376393 / 10784391222`; exact-one selection, zero skips, benchmark 0, immutable postflight. TB1-REV accepts row449's producer proof but does not promote this package to accepted M5 runtime authority.

## Previous Code + Build turn — `M5-CP4-CB1`

**COMPLETE / COMPILE+PACKAGE GREEN / RUNTIME-FREE.** Candidate artifact/source `10782841045 / 535ec760...`; mandatory GMP/GMPXX linkage, 26/26 package manifest, `runtimeExecution=false`. CB1 plan/report are folded by TB1 Review; immutable artifact evidence remains authoritative.

## Previous accepted Code + Build turn — `M5-CP3-CB20`

**COMPLETE / SELECTOR448 PUBLISHED / RUNTIME-FREE / COMPILE+PACKAGE GREEN.** At CB20, exact selector448 was published at 448 unique rows, 36,382 bytes, SHA-256 `70ff08601bf244fcb4883e5d0601d5e7a3a44f52a8e855544a065c6ca5c75789`, exact selector430 prefix, standard-owner census 32/300/75/41; routing receipt SHA-256 is `c91a5e2f3d84d7d38b7c7c58afd157448cb225ebdbbfac3da2ef6259e811dd7c`. Publication source is `cef1c6ee26ca6fb6791f0e80a66f9b0dc441e0f1`. Compile run/job `35910024971 / 107347291148`, result/log artifacts `10771899191 / 10772810906`, root manifest 28/28; all eight GMP/GMPXX targets link and `runtimeExecution=false`. CB20 itself made no acceptance claim; `M5-CP3-TB2-REV` later accepts these exact bytes and promotes this package.

## Latest Test + Benchmark turn — `M5-CP3-TB2-EXEC`

**COMPLETE / MECHANICALLY GREEN / PUBLISHED SELECTOR448 448 PASS + 0 RED / REVIEW REQUIRED.** Fresh run/job `35913334490 / 107358491487` consumes CB20 artifact/source `10771899191 / cef1c6ee...` immutably and executes selector448 as **448 fresh exact-filter processes**: 448/448 PASS, exact-one selection, zero skips, owner census 32/300/75/41, protected 191/192/247/408 PASS, all appended 431-448 PASS, benchmark 0, result evidence 917/917 and exact immutable postflight. Result/log artifacts are `10775185139 / 10774217117`. No regression was observed; accounting stays 51 / 14 / 37 and project debt 1 M6-owned. EXEC grants no selector acceptance or M5 closure; exact successor is mandatory `M5-CP3-TB2-REV`.

## Previous Definition turn — `M5-DEFN-R1`

**COMPLETE / RUNTIME-FREE / DISPOSITION A — NOT ACCEPTED at `M5-DEFN-R1-REV`.** It proposed that M5 focused multi-isolation means ≥2 isolation sheets joined by a checked isolation-seam certificate, credited rows 186/239, and froze conjunct 8. The Review rejected that on chronology and redundancy grounds. The record is folded (git `d17aada2`).

## Previous semantic Code + Build turn — `M5-CP3-CB17`

CB17 is **COMPLETE / RUNTIME-FREE / COMPILE GREEN**, candidate `10742798135 / 1a36f6483738e1047b5d8ddbefb48cc5ab6fd4a3`. It implements frozen §16.3 exactly: `Q = G_R^-1 A G_F`, Forward cut-domain branch/raw coordinate authority, Reverse `Q` normalization, and relation-owned checked-product validation. The new synthetic contract proves `Q != A` and fails if either accepted occurrence-gauge term is deleted. All eight mandatory GMP/GMPXX targets compile/link; no Directional runtime was executed. Candidate remains unpromoted pending R15.

## Previous control-plane Code + Build turn — `M5-CP3-CB18`

**COMPLETE / CONTROL-PLANE GREEN / RUNTIME-FREE / NO DIRECTIONAL COMPILE / NO REPACKAGE.** Canonical R15-R1 harness/caller are frozen at SHA-256 `7867e779...81b7 / 0f0a12f9...a15c`. Static run `35864475136` proves corrected literal GTest accounting `selected/passed/skipped=1/1/0`, historical parser `0/0`, skip probe `1/0/1`, and both workflow schemas green. No semantic input changed; accounting remains 51 / 14 / 37, debt 3.


## Current observations

- [x] `M5-CP3-TB1-R5-REV-OBS-01` — recovery proved by R7.
- [x] `M5-CP3-TB1-R2-REV-OBS-01` — successful atlas-owned value consumption proved at R7 while hard-feature nontraversal control remains green.
- [x] `M5-CP3-TB1-R8-REV-OBS-01` — **CLOSED / NO-TUNING + CHART ADMISSIBILITY INDEPENDENTLY UPHELD AT R9 REVIEW**.
- [x] `M5-CP3-TB1-R6-REV-OBS-01` — **DISCHARGED AT R16 REVIEW**. Independent source/A3 authority fixes semantic Forward -> Reverse `Q=3`; the accepted produced relation concretely stores the inverse quarter-turn `1`, and corrected row16 proves stored action/route differ before resolving back to the independent semantic authority.
- [x] `M5-CP2-TB1-REV-OBS-01` — **DISCHARGED BY R16 REVIEW PRECOMMITMENT**. The corrected pre-publication gate is independently accepted at 448/448 with complete evidence, and exact selector448 is precommitted under frozen §13.3; publication itself remains owned by `M5-CP3-CB20`.
- [x] `M5-CP3-TB1-R9-REV-OBS-01-A` — **DISCHARGED AT R10 REVIEW**; produced rows1/2/3/6 remain PASS under CB11, empirically upholding frozen §16's `R=0` reduction.
- [x] `M5-CP3-TB1-R13-REV-OBS-01` — **DISCHARGED AS TRIGGERED AT R14 REVIEW**; it forced DEFN-R1 before any CB17 semantic implementation.
- [x] `M5-CP3-DEFN-R1-REV-OBS-01` — **DISCHARGED AT R15-R1 REVIEW**. The `Q != A` mechanism identity passes in a complete mechanically valid ledger and falsifies omission of either occurrence gauge; mechanism-only, no produced-debt credit.
- [x] `M5-CP3-TB1-R14-REV-OBS-01` — **DISCHARGED AT DEFN-R1**; independent committed-torus source/A3 derivation yields relation-gauge `Q=3` before relation publication.
- [x] `M5-CP3-TB1-R15-REV-OBS-01` — **DISCHARGED / RUNTIME-PROVED AT R15-R1 REVIEW**. Frozen corrected parser accounts for all 448 exact-one/zero-skip processes in a complete valid ledger.
- [x] `M5-CP3-TB1-R15-R1-REV-OBS-01` — **DISCHARGED AT R16 REVIEW**. CB19 kept the expectation independent (hard-coded `Q=3`) while using the resolver only to normalize representation; R16 proves it at runtime.
- [x] `M5-CP3-TB1-R16-REV-OBS-01` — **DISPOSED AT TB2 REVIEW / NO M5 CREDIT.** The two CB14 identities were never executed, remain absent from selector448 and receive no M5 credit. `M6-DEFN` DISCHARGED this obligation: both are frozen for no-credit deletion as superseded at `M6-CP1-CB1`; accepted replacement identities are named in `Architecture_M6_Frozen_Definitions.md` §9.
- [x] `M5-CP3-TB2-REV-OBS-01` — **DISCHARGED AT `M5-CP4-TB2-REV`.** DEFN-R2 froze the same-region producer join; row449 proved it, selector449 was published and freshly executed 449/449, and final Review accepts conjunct8 and closes M5. The representative M6 half remains M6-owned.
- [ ] `M5-DEFN-R1-REV-OBS-01` — **RECORDED / process.** COMPLETE was published before the turn's durable work was on the branch. Every implementation turn must make COMPLETE its final write.
- [x] `M5-CP3-TB2-REV-OBS-02` — **RECOVERED.** Tracker overwritten at `ce9bf3cb` (9,837 → 21 lines) and restored verbatim (`LESSONS.md` 176).
- [x] `M5-CP3-TB2-REV-OBS-03` — **RECOVERED.** Agent CHANGELOG overwritten at `0043dd4c` (13,317 → 14 lines) and restored verbatim. The committed-history guard is `review_check.py ledgers --base <previous-review-commit>`. Every Review should run it.
- [ ] M6 closed-complex produced debt (`G4-B002`, `CandidateExtractionBaselineForCanonicalSourceScopeIdentityIsNonVacuous`): **OPEN / M6-owned.** M6-CP1 mechanism, M6-CP3 direct production. *(Restored. TB2-REV had dropped this open item.)*
- [ ] `M5-CP3-TB1-R16-REV-OBS-02` — **RECORDED / NOT FIRING**. Rows 446/447 pin inverse canonical storage. If it fires, classify as test-authority drift and keep the pin.
- [x] `M5-CP3-TB1-R16-REV-OBS-03` — **DISCHARGED AT TB2 REVIEW.** `M5_Consolidated_Record.md` now has one chronological unique §4.1-§4.31 sequence and live citations are repaired.

## Deferred hygiene

- [ ] **Repair `.github/workflows/agent-turn-cleanup.yml` comment handling and trigger safety.** The workflow still deletes **all** PR conversation and inline review comments before its observer step, and creating `.agents/connector-triggers/turn-cleanup/manifest.txt` auto-triggers it. Run `32591251950 / 97075340976` demonstrated 27 conversation-comment deletions. User commit `c359ea925b04471500575a9dcc17bdc6e4bb52d1` explicitly superseded the old prohibition by requiring the manifest/workflow at every turn closeout. Until the workflow is repaired, preserve durable repository evidence before publishing the closeout manifest and treat PR comments as non-durable.

Inherited baseline-red / non-gating fixtures remain frozen in the M1 exclusion register. None may become required-green evidence before its precondition is independently established.

- [ ] `WU2A-TB-CAND-01`: successful-side-subdivision ownership-registry precondition.
- [ ] `WU2B-TB-CAND-01`: hard-rail region-copy valid front-boundary-authority precondition.
- [ ] `WU2B-TB-CAND-02`: side-repair rollback ownership-registry/domain-identity precondition.
- [ ] `WU2B-TB-CAND-03`: authoritative-cell-scope subdivision source-scope reconciliation.
- [ ] `WU2B-TB-CAND-04`: five simplification fixtures need independently proven removable/protected/healing preconditions.
- [ ] `WU2B-TB-CAND-05`: FlowRep mandatory-cycle witness needs `selectionSucceeded=true` before later-cycle evidence is creditable.
- [ ] `RA-REV-23-F3`: dispatch stitch-kind audit through an explicit classifier field rather than probe-name text; add a negative self-test.
- [ ] `RA-REV-22-F6`: remove non-falsifiable validation-used assertions or set them where each gate actually executes.
- [ ] `RA-TB6-H1`: repair repeated `TriMesh::set_mesh` / `DCEL::init` stale halfedge-twin reinitialization outside the R-A fixture path.

## Milestone status

Checkpoint decomposition, per-milestone acceptance mapping, and the path to production-ready are in **`ROADMAP.md`**. Summary only:

- [x] **M0** preserve evidence  ·  [x] **M1** single-authority cutover  ·  [x] **M2** closed stage products
- [x] **M3 — field-aligned curve network.** **CLOSED / ACCEPTED at `M3-CP4c-3-TB48-REV`.** Package113/TB48 is reviewed authority at 405 PASS / 4 RED over the final audit surface, with accepted required-green selector365 at 365/365 and the AU0–AU9 mechanical-witness criterion met. Closure: `M3_Closure_Record.md`.

- [x] **M4** global conformity plan — **CLOSED / ACCEPTED at `M4-CP4-TB3-REV`**. Final runtime authority is package `10591801825` / source `aa6cab176f4f7297c1f9ab20a7a49bf6a00a7431` / selector430 **430/430**. Closure: `M4_Closure_Record.md`; CP4 closure: `M4_CP4_Closure_Record.md`. M4 handed four periodic/relation debts to M5 and one closed-complex debt to M6; R7 Review discharged two M5 debts and R16 Review discharges the remaining two nonzero-Z4 M5 debts. The sole remaining project debt is the M6 closed-complex subject.
- [x] **M5** certificate-carrying chart/quotient relations — **CLOSED / ACCEPTED at `M5-CP4-TB2-REV`.** Final authority is package/source `10814505512 / e284fea7...` under accepted selector449 **449/449**, SHA `d4a0d1b7...d6414`, owners 32/301/75/41. All §13.1 conjuncts 1-8 are accepted; M6 Definition is frozen and M6-CP1 recovery is now active.
- [ ] **M6** occurrence, embedding, independent verification.
- [ ] **M7** disposition and graded degradation — D0–D4 plus the M1 criterion-5 forward re-proof.
- [ ] **M8** module boundaries and operational hardening — `M8-CP3` is the production-ready exit.
- [ ] **Pipeline A.** Unscheduled until Pipeline B is Certified and evidence shows integration would materially improve quality.

## Active product blockers

- [x] **CP4c-3 protected frontier census evidence:** Part XII was first runtime-proved in TB43: 390/393/406/407 executed the producer-owned census predicates and rejected same-domain corruption. `M3-CP4c3-TB40-EXEC-CAND-02` remains historically CLOSED / RUNTIME-PROVED / NON-STABLE. TB45 historically exposed the stale failure-required precondition; package113/TB48 now re-proves all four receipts non-vacuously through `PlanFrontier`.
- [x] **CP4c-3 protected Part XII success-path observability — CLOSED / RUNTIME-PROVED:** package111 ordinals 390/393/406/407 all PASS on `PlanFrontier`, execute the real census predicates, reject same-domain corruption and emit non-vacuous receipts.
- [x] **CP4c-3 ordinal367 independent oracle — CLOSED / RUNTIME-PROVED / NON-STABLE:** TB47/package112 PASSes ordinal367 under the frozen high-side-only rule; package112 is promoted. Accepted ordinal307 remains a separately recorded latent stale equality and is unchanged.
- [x] **CP4c-3 ordinals 371/372 test coupling:** TB21's atlas-scoped accessor makes both identities execute their unchanged assertions and **PASS**. `M3-CP4c3-TB10-REV-CAND-01` is CLOSED / runtime proved.
- [x] **CP4c-3 ordinal 391 diagnostic dependency:** TB22 ordinal 391 PASSes; sphere is explicitly skipped with `reason=ordinal368-open` while mechanical/torus evidence runs. `M3-CP4c3-TB21-CAND-02` is CLOSED / runtime proved / non-stable.

- [x] **CP4c-3 ordinal370 empty closed network — CLOSED / RUNTIME-PROVED / NON-STABLE:** package113 ordinal370 PASSes under the frozen identity requiring `EmptyNetworkOnClosedSurface = 6` plus a non-empty `sourceFace` locus. TB48-REV promotes package113 and closes `M3-CP4c2-TB-X2-R8-CAND-02` without changing stable accounting.
- [ ] **CP4c-3 ordinal 374 (deferred, different owner):** the folded-cone AY5 witness declares a flat-star field (`effort ≡ 0`, no singularities) on a star with `Θ = 3π/2`, so the atlas rejects it with `CycleTransportMismatch`. Corrective is test-only — derive matching/effort/singularities with `directional::fields::principal_matching`, keep the exact expected-owner derivation, certify against the whole admissibility chain. Selector 374 stays byte-frozen and is **not** withdrawn. TB8 repeated this pre-classified stop; it adds no new product evidence.
- [ ] **Prescribed sphere A2a′ upstream error:** ordinal 368 is now repeatedly measured report-only at `RotationSystemInconsistent → TraceEventPositionInvalid`, trace 2/event 30, `NoCarrierMatch / SourceEdgeUnavailable`. AL4 still forbids a sphere semantic fix until separately reviewed.
- [ ] `G4-B001 / PR8-R034 / G4-R007`: direct torus final `LocalSheetMismatch` (last measured 0/3 at artifact `9031804178`, pre-M1). **M6-DEFN disposition:** the original hard-rail→sheet root is absent from current source (production passes an empty isolation-barrier set). Carried as a direct-production evidence debt to **`M6-CP3`** (strict torus 3/3 re-proof). Unmeasured since then; do not weaken `LocalSheetMismatch`.
- [x] `G4-B002` main exact-torus hard-rail pairing blocker — **CLOSED / RECOVERY PROVED at M4-CP3-TB8-REV** on accepted package `10307919492` / selector408 **408/408**. The three produced-witness debts remain open: one closed-complex debt is M6-owned after DEFN-R2 and two periodic debts are M5-owned after DEFN-R1. This checkbox closes the blocker, not those debt items.
- [x] `G4-B003`: nonzero periodic Z4 production — **DISCHARGED at M5 R16 Review**; both direct-production debts are runtime/review proved.
- [ ] `G4-B004`: positive multi-isolation quotient witness. **M5 producer half ACCEPTED / DISCHARGED at `M5-CP4-TB2-REV`; M6 representative-consumption half OPEN.** Selector449 final authority proves the same-region producer join. `M6-DEFN` item 7 now owns representative exact-once materialization/consumption, embedding and independent verifier proof without weakening or reconstructing the producer fact.
- [ ] Bunny/Vase representative production and resource acceptance — later product gates.

## Design and calibration backlog

- [ ] Own the closed-rail cardinality contract once at the rail product boundary rather than re-guarding both closed representations at every consumer.
- [ ] Calibrate `T5` quality/resource thresholds from measured baselines before any milestone asserts a quality gate.
- [ ] Correct `DESIGN.md` section 6.7 invariant 2 so D1 `QualityRelaxed` consistently records missed quality gates.
- [ ] Define the M7 degraded producer algorithm and its fixed-boundary completion proof.
- [ ] **Audit every remaining `kBranchTopologyTolerance` comparison for dimensional coherence.**
  `direction_in_incident_vertex_sector` compares a Gram **determinant** — an area-squared quantity — to
  `1e-10`. After E2/E3 the surviving uses are admissibility guards only, but their scale is arbitrary and
  mesh-size dependent. Not a CP4c-0 measure; do not fold it into CB2.
- [ ] **Sweep for other tolerant-selector / exact-consumer seams.** CP4c-0 found the pattern three times
  in one subsystem (flow classification, vertex sector, cross-edge flow). The same audit is owed wherever
  an exact authority was introduced downstream of a `double` decision.

---

Current corrected totals are **55 events / 16 categories / 39 recurrences**, project debt **1** (M6 only). M4 and **M5 are CLOSED / ACCEPTED**. Final accepted M5 authority remains package/source `10814505512 / e284fea7...` under selector449 **449/449** (`d4a0d1b7...d6414`). `M6-CP1-CB5` is **COMPLETE / COMPILE+PACKAGE GREEN / RUNTIME-FREE**; candidate artifact/source `10879581622 / 82b86a28...` is unpromoted. Exact next is immutable **`M6-CP1-TB5-EXEC`** over 456 processes, then mandatory `M6-CP1-TB5-REV`. PR #8 remains open, draft, and unmerged.
