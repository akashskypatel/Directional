# TB131 independent Review — MISMATCH upheld (2026-11-17 UTC)

## Situation

`M6-CP3-TB131-P13-CARRIER-CONTACT-SWITCH-FULL-GATE-REV`. Runtime-free independent Review of [TB131](Architecture_M6_CP3_TB131_P13_Carrier_Contact_Switch_Full_Gate_Execution_Report_20261117.md) against [RA-252 §6](Architecture_M6_CP3_DEFN_P13_Carrier_Contact_Switch_Review_20261117.md). **MISMATCH upheld; no accepted-green loss; no O45 closure or package promotion.** The observed discrepancy in unaffected logs is presentation, not evidence of a changed product result. The new sphere and BunnyRandom failure sites are real. The current evidence does not establish their root causes.

## Background — exact authority

CB154 source `452eb3d789016e744e99d88811add0f7e0949165`, package `14347130681` (published package ZIP `f768d7dc97fb6cf7f345f45fe6e52e681c6d7c21b6436ff3239ef44cec382489`); comparator CB153 `95f082b144f2bbe145d764cbf6b3d10d123a6514`, package `14338920906`. The four primary result archives were reopened from the preserved File Library evidence bundle. Outer hashes independently match the execution report; the package binaries themselves were not downloaded or executed in this Review.

| Primary result | Artifact | ZIP SHA-256 | Internal checks / rows |
|---|---:|---|---:|
| TB130 gate | 14338844806 | `d93a644f800e2c4e641fdc31051556d62f4a55541ef74009c2b86aaedf927fcc` | 1914 / 953 |
| TB130 census | 14339793522 | `c21ce302c41839542015b03bb6c18618798ed1e8dde74b40925c1693785532ca` | 9 / 3 |
| TB131 gate | 14349985217 | `3747ea473be4ff441acc9b8808ba2b3bdeb280ff8d38963ee2f1d2a825165824` | 1914 / 953 |
| TB131 census | 14349666706 | `784df0aa5d6fd5f2e3cb5ba22a2aa42d7e712460a8447f4e27e3f4e725920b00` | 9 / 3 |

Re-derived 3,846/3,846 internal hashes, 1,912/1,912 ledger-to-raw-log hashes, all 1,912 row/identity/test/binary joins to frozen manifests, exact selected-test and result markers, four valid postflights, and membership 1,034 = 953 gated + 81 deferred (same 81 identities). Membership SHA-256 `364ed142e1134b9f465a0689be5f44f845815dcd5b64e354a893f4ddbaaf47bd`. Both candidate and comparator record no configure/compile/relink/benchmark. Candidate gate exit 90, control_bad=1; no missing, duplicate, skipped or abnormal result. The gate failure is organic, not infrastructure.

Snapshot source `cd69d087dfd1088ae3170cdd87a0b490e308f1dd`, run `44135982912`, job `134225691663`, artifact `14351762938`, outer ZIP `5d1b7e85cd7f4b87b586f0136ee25f22b32d9f6f9e9aff6b1eb5aae675174bb1`, inner archive `1badf22cd4f16a440b747c5fb2f47d548883c2959b57dbdaa8cae166eb48c869`, 5533/5533 checks. GitHub comparison CB154→snapshot: 21 commits, no product/test/fixture/build paths changed; CB153→CB154: only semantic changes `EmbeddedGraphTopology.cpp` +30/−105 and `.h` +6/−9, as in frozen exact diff SHA `98e14bfe3fb030a691eed5d181f8e427e28072c2b00e96e47b2372ed214430b9`. This licenses source inspection, not a fresh execution claim.

Recomputed frozen inputs (SHA-256):
- gate 953 `941287fa96f3432eb1d67a9ae1e5dc7bc0ca2f3a1775cd5f9fb35482a4fa7962`; census 3 `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793`; deferred 81 `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce`; harness `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94`.
- CP1 focused30 `1e815443a03c7ef4a1b095e6ea973efa9c74bb0eae4e2f872510c97d057ea1d6`; CP2 focused12 `2aa57aac48ac8c41ea86ed459cdd1acd27eb17c8d3dbe1b4ac7b9c54c67374ed`; M5 selector449 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`. Concatenation in that order, LF terminated `452360f771daacb96f87697286ec7708832f63c876b9df9b1857e93433e5300b`: matches the first 491 manifest test names, all 491 PASS. Matches TB129 independent Review hashes. No accepted selector mutation or loss.

## Assessment — frozen gate and forensic comparison

| RA-252 §6 criterion | Independent result |
|---|---|
| 934 unaffected rows and Cylinder/Vase equal | FAIL: 927 gate logs equal after timing normalization; 4 equal only after newline framing (175,177,191,477); rows 174,176,179 differ; Cylinder matches, Vase differs. |
| Retired proxy and trace-trace H1 lines absent | PASS, zero across 956 candidate raw logs; comparator has 34 proxy and 68 H1 lines in 20 logs. |
| 17 neutral rows PASS | PASS: 380,388,393,394,396,397,644,645,669,686,691,694,698,699,700,843,844. |
| Premise rows | PASS criterion: 648 PASS (sphere path skipped internally); 858 RED only at the permitted line 155. |
| BunnyRandom H1 absent | PASS for measured receipts; new terminal is data. |
| Everything else | FAIL due to the four unaffected-log discrepancies. |

All 956 paired substantive ledger records match except row858 (verdict/exit/passed/first_failure/typed_reason); log SHA changes are retained. Gate 952/953 PASS; census 1 PASS/2 registered RED. No retroactive widening, suppression, or MATCH claim.

The following is forensic attribution only, not a replacement acceptance comparator. The Review extracted only complete `M3_CP4AB_FRAGMENT_DIAG record=region_support_projection` records through the final numeric `support_chi_whole_source_faces` field. It checked that extracted count equals prefix count, compared exact record multisets (including multiplicity), and compared all remaining bytes after frozen timing/newline normalization. Row174 = 6/6 records; row176 = 6/6; row179 = 24/24; record multisets and ordered remaining bytes match. Row179 includes adjacent concatenated records. `GlobalTopologyPlan.cpp:1959–1991` builds the full diagnostic in a local stream and emits `std::cerr << out.str() << '\n'`; record scheduling/framing can vary, but identical records do not prove a general race-free implementation. No evidence of a changed product or assertion in these three rows. A changed/missing/extra record, changed residual byte, or any changed substantive ledger field would falsify this attribution.

Vase: after timing normalization only two `GetParam() = 16-byte object <...>` payloads per archive differ. The exact remainder, including failure sites and result markers, matches after masking those payloads only. `tests/SurfaceCellDesignAcceptanceTests.cpp:26–29` defines `DesignAcceptanceCase` as two `const char*` fields. The addresses are presentation, not fixture values. The [TB129 Review](Architecture_M6_CP3_TB129_P13_Terminal_Cut_Receipt_Full_Gate_Independent_Review_20261117.md) explicitly used parameter-object normalization; RA-252 §6 lists timing, row164 multiset and newline framing but omits this exception. Even if that precedent is interpreted as allowed, three gate differences still establish MISMATCH. No change to the historical rule.

## Assessment — product and test candidates

- **FC-7′ / O45:** `EmbeddedGraphTopology.cpp:637–659` implements the node-level predicate, excludes ports, retains an edge-only barrier FirstContact path, and `:767–840` consumes exact terminalContact records. `build_arcs` inserts terminating cuts at the actual end and interior cuts at exact parameters (`:1141–1166`); `build_node_loci` bypasses the contact event proxy (`:1392–1400`). CB154 replaces the old proxy-based choice. The disappearance of H1 on measured paths supports the intended correction; it is not proof of all valid contacts or of reaching rotation: an earlier rejection can also remove a print. RA-252 locality as a literal log-equality assertion is falsified. No evidence that CB154 changed product decisions on unaffected rows; the complete switch correctness and O45 closure remain unproved. Retain exact guard and producer metadata.
- **Sphere:** 644/698 record `surface-cut-graph/InvalidNetworkBinding`, originating `InvalidCutGraphBinding`, trace 4/edge 0–2, face absent. This is different from the prior H1 rejection. Source has several indistinguishable signatures: `build_cut_node_bindings` exact duplicate crossing across traces (`:373–380`, also sets secondTrace), synthetic-node insertion (`:414–420`), `build_arcs` crossing at position 0/outside trace (`:1121–1128`) or conflicting node for same crossing position (`:1130–1137`). `SurfaceCutGraph.cpp:93–136` projects the origin and loci, including secondTrace; the available printed logs do not discriminate these sites. A new typed receipt must report the exact rejecting site, selected cuts, trace/secondTrace and position/extent, exact boundary parameter and both node IDs when applicable. Falsifier: a receipt does not correspond to any of these actual predicates. No assumption that duplicate crossings are valid, no merging by equal coordinates.
- **BunnyRandom:** `surface-cut-graph/CellularityNotEstablished`, originating `RotationSystemInconsistent/TraceEventPositionNodeConflict`, trace 82/face (21,72,273), no edge. The exact source has two collision guards: contact insertion `:1155–1164` sets trace + contact face, while event insertion `:1194–1202` sets event face/edge but not trace. Thus the published trace+face signature supports the contact-insertion guard, subject to provenance propagation; it does not identify either claimant. The map is populated first by origin and synthetic cut crossings, then exact contact candidates. Measure both node identities, claim kinds, exact cut-position representation, source authority and terminal/interior records at the actual rejected insertion. Check whether the previous and new claims represent the same certified identity or contradictory producer facts. Do not assume equality merely because both are at one trace-position key; do not overwrite either claimant, relax guards, or force terminal positions.
- **Row858:** `SurfaceCellTracingDisplayTests.cpp:153–172` uses sphere as face-locus example. The only failed assertion is `:155` face present, with actual edge locus. This is permitted premise RED, not evidence that display mapping is broken. Retain independent vertex/face/stop-location witnesses; a later test change must replace the face witness with a genuinely produced face locus and prove the new assertion can fail, or explicitly defer it with authority. Do not manufacture a face, delete assertions, weaken expected results, or mark row green.
- **Row648:** `FieldAlignedCurveNetworkTests.cpp:13928–13938` returns when the sphere cut graph is absent. Torus assertions execute, sphere assertions at `:13941–13962` do not; no sphere credit. Keep the existing assertion obligation and revisit when the prerequisite is reached.
- **Other census:** Cylinder PASS 288 accepted quads; unchanged. Vase RED at completion, 189,462 segments, 26,817 arrangement cells, 67,750 internal quads, zero accepted. BunnyRandom RED zero accepted. No production-ready matrix claim.

Accounting: 66 stable events / 17 categories / 49 recurrences; one produced-witness debt and 81 deferred. CP2 491/491 accepted package 11391685901. TB125 scoped 950/950 remains accepted; neither CB154, CP3, selector497 nor D0 promoted. C5/O42/O43/O45/O46 open; FC-1/FC-4 producer proof, middle-piece direction witness, H2 (unobserved, not excluded) carried. Previous narrow C3/O44/C1 closure unchanged. CB145 parked; CB149B/CB152 withdrawn; FC-6 held; D11=A, D12=A, D10 deferred, D6 pending, chainRimSchedules=false. No new stable event or debit.

## Recommendation — one bounded successor (definition, not execution)

`M6-CP3-DEFN-P13-CARRIER-CONTACT-SWITCH-COMPARISON` is the corrective Review/definition before the previously held terminal-cut outcome and FC-6 definitions. RA-252 §6 routed the mismatch to independent Review; its explicit MATCH closure condition prevents proceeding as if O45 closed. This new definition is a comparison-authority repair, not a product change. The successor must verify complete diagnostic record framing and scope against source, specify a prospective exact comparator narrowly limited to the verified diagnostic class and parameter-object rendering (not arbitrary log sorting/masking), and freeze negative controls: missing, duplicated, altered or malformed record; altered non-record byte; changed ledger field; lost prior green or unexpected failure site. Preserve all 953 gate identities, 81 deferred, three census rows, and the original TB131 verdict. Establish whether a fresh artifact-only comparison on immutable CB154 is required; do not promote from forensic comparison alone. If repeated execution is required, freeze exact work, identities and comparator before dispatch. Define the bounded observation of the two newly reached rejection sites and test-premise correction separately; do not combine product changes with comparator changes. If a prospective comparator cannot discriminate those controls, stop and retain MISMATCH/O45 open. No product/test/build/runtime work in the definition; no runtime or successor work in this Review.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | 30+12+449, exact 491-name prefix, hashes above; 491 PASS. |
| Decisive claims independently re-derived | 4 result ZIPs, 3,846 internal checks, 1,912 raw hashes/identity joins; exact membership and substantive ledger; strict and forensic comparisons; source guard signatures. |
| Non-vacuity checked | Real strict comparator failures; row858 permitted assertion failure; row648 sphere branch not executed; no inferred O45 closure. |
| Prior obligations discharged/carried | H1 receipt absent in measured paths only; C5/O42/O43/O45/O46, H2, FC-1/FC-4 and direction witness carried; C3/O44/C1 narrow closure unchanged. |
| Stable accounting | 66/17/49, debt1, deferred81; CP2 491/491 package 11391685901, TB125 scoped 950/950; no promotion. |
| New candidates/obligations recorded | Non-stable comparison/presentation discrepancy; sphere and BunnyRandom rejection sites; row858 premise, row648 unreached; tracker updated. |
| ORIENTATION currency line | Updated to this Review, 2026-11-17. |
| ORIENTATION §3 / §4 / §7 / §8 | Current evidence, witness, priority and comparison lesson replaced/updated. |
| CHANGELOG | Review entry added. |
| ROADMAP | Latest CP3 evidence corrected; milestone status unchanged. |
| Selector manifest | n/a — no selector accepted or published. |
| LESSONS | Existing exact-comparison and guard-producer lessons apply; prospective scope must be explicit, not retroactive. |
| Consolidation under CLEAN_UP_POLICY | Superseded TB130 continuation retained verbatim in volume D3, indexed and active citation repaired; active comparator/definitions retained. |
| Successor frozen | `M6-CP3-DEFN-P13-CARRIER-CONTACT-SWITCH-COMPARISON` — bounded recommendation and falsifiers above; not started. |
| Turn boundary held | Documentation only; no source/test/fixture/harness/selector/build mutation or runtime. |
| review_check.py boundary | Local verified snapshot lacks historical Git objects. Scratch preimage comparison checks unchanged code, selectors and retained durable sections; history-dependent baseline checks cannot pass locally. See preservation evidence for actual result. |
| STATUS lifecycle maintained | Initial IN_PROGRESS beacon commit edf81aa644b1dbda0524a938dd3bccd1ede983c1, start 2026-11-17T17:20:16Z, resume empty. Final direct beacon after delivery/cleanup; if not verified, retain IN_PROGRESS. |
| Pushed to origin, branch in sync | Local snapshot is not an authenticated checkout. Verify dispatcher apply and remote branch diff before final COMPLETE; no claim of local origin synchronization. |
