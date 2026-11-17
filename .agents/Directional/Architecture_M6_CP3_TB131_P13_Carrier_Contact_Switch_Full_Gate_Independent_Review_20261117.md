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

## RA-253 — adversarial re-review of this Review (2026-11-17 UTC)

Runtime-free. I re-opened the TB131 gate `14349985217` (ZIP `3747ea47…`, matches) and census `14349666706` (ZIP `784df0aa…`, matches) in an isolated directory with `python3 -I`, and checked source at HEAD (`git diff --quiet 452eb3d7… HEAD -- src include tests` holds). Haiku agents ran read-only source audits.

**Verdict.** The literal MISMATCH stands as history. Every substantive claim about the unaffected rows is upheld. But the successor is wrong: a comparator-only DEFN turn does no product work, and its question can be settled now from source. This Review also missed the most important new fact (S2) and the site discrimination it allows (S2/S3). **`M6-CP3-DEFN-P13-CARRIER-CONTACT-SWITCH-COMPARISON` is withdrawn.** Its comparator rule is frozen below as TB132 normalization N3–N5. Next is an exact print-only receipt CB at the two newly reached guards.

### S0. My own RA-252 error
RA-252 §6 criterion 1 carried only the row164 complete-line-multiset rule. Rows 174/176/179 are from the same `SurfaceCellAuthorityContractCutover` family and reach the same emitter. I did not check the emitter's concurrency; RA-250's lesson already said to. I also omitted the parameter-object masking that the TB129 Review had used. The MISMATCH came from my freeze, not from CB154.

### S1. Comparator, settled from source
- **Emitter.** `emit_region_euler_certificate_diagnostics` (`GlobalTopologyPlan.cpp:1959–1991`) is called through `build_region_certificate` `:2359` → `build_region_certificates` `:2447` → `canonical_candidate` `:2631` → `GlobalTopologyPlan::make` `:3028`, then `RemeshPipeline.cpp:12958`. That path runs inside per-component `std::async` workers (`RemeshPipeline.cpp:17726`, `:19571`).
- **Rows.** Rows 174/176/179 (`SurfaceCellsPhase10Tests.cpp:10631`, `:10505`, `:9959`) reach the emitter through the final-validation counterfactual aggregate.
- **Interleaving.** `std::cerr << out.str() << '\n'` makes two separate insertions. The concatenated records and stray empty line in row 179 are the signature of another worker's insertion landing between them.
- **Vase.** The two differing bytes are two `const char*` addresses (`SurfaceCellDesignAcceptanceTests.cpp:26–29`).
- **Ruling.** CB154 changes only `EmbeddedGraphTopology`, and 952/953 substantive ledgers are equal. So these are scheduling and pointer presentation. A fresh run on CB154 is not needed. The prospective rule is TB132 N3–N5, with negative controls.

### S2. The sphere passed the zero-cut build — first time
The sphere's `InvalidCutGraphBinding` sets both `trace` and `sourceEdge`, so it can only come from `:373–380`, `:414–420`, `:1121–1128` or `:1130–1137`. The last three are unreachable:
- **`:414`:** crossing keys are unique per trace and segment, and node ids come from a counter.
- **`:1121`:** a crossing exists only for a segment with an `incomingCarrier`. Segment 0 never has one: `runtime.incomingCarrier` starts empty (`SurfaceCellTracing.cpp:3263`) and is set only for following segments (`:4523`). The loop bound also excludes position ≥ size.
- **`:1130`:** only the origin precedes, and a segment has one incoming carrier.

**Site.** It is therefore the `:373` guard: two distinct traces cross selected cut edge (0,2) at the same exact interior parameter, and trace 4 is the earlier of the two.

**Consequence.** Edge (0,2) was a selected cut, and `SurfaceCutGraph.cpp:1007–1016` returns on any failure. So the cut-free `build_embedded_graph_topology` at attempt 0 **succeeded**. The sphere's arcs, rotation system and face walk were built with all 12 contacts bound by FC-7′, which is positive evidence for the switch. The failure is in cut search, a stage the sphere had never reached.

**Not printed.** `secondTrace`, the parameter and the attempt index are absent because the test printer (`FieldAlignedCurveNetworkTests.cpp:7335–7375`) does not print them. The elimination is a static model, and CB155 tests it.

### S3. BunnyRandom: two face-contact nodes claim one position
- **Guard.** The locus has both `trace` and face set, so it is the contact-insertion guard (`:1155–1164`), as this Review said.
- **The claimants are both face-contact nodes.** The origin key `{0,∅}` and the crossing keys `{k<size,∅}` can never equal a contact key: an interior key carries a parameter, and an end key is `{size,∅}`. Events are inserted after contacts.
- **It happens at attempt 0.** Contact insertion is independent of the cut set, so BunnyRandom never obtains a topology.
- **Possible causes, both producer node-identity facts:**
  - Two distinct nodes record the same contact. The collector checks every terminating trace's face and point, so the face and point would be equal.
  - Two contacts strike trace 82 at the same exact point.
- **Unknown.** Whether the conflict was masked before CB154 by the earlier H1 rejection on trace 1. CB155 prints each node's events, so an FC-7′-promoted node is identifiable.

### S4. FC-7′ premise gap
FC-7′ says a trace-trace contact lies strictly inside a face. S2 means two traces pass through one exact point of edge (0,2). If they share a contact node there, the contact lies **on** an edge and FC-7′ gives it a face locus, so the premise fails. I have not proved whether `field_aligned_publish_contact` excludes boundary contacts. CB155 prints every contact's barycentric point; a zero coordinate falsifies the premise.

**O45 remains open.** It closes on TB132 when every printed contact point is strictly interior. The comparator does not decide it.

### S5. Premise rows
I agree with this Review: row 858 remains a registered permitted RED at `:155`, and row 648's sphere assertions are unreached. No test change is made while the sphere's terminal still moves with each fix. The 858 face-witness correction is a later DEFN after the sphere repair is chosen.

### S6. CB155 — `M6-CP3-CB155-P13-CUT-BINDING-CONFLICT-RECEIPT` (exact, print-only)
**The patch.** `Architecture_M6_CP3_CB155_P13_Cut_Binding_Conflict_Receipt_Exact.diff`:
- SHA-256 `2a9de80f6781caab9c741d450715627ebd136d5407778a2587e05afa3e0f7761`; 189 lines; numstat `157 0 src/geometry/EmbeddedGraphTopology.cpp`.
- Precheck: `git diff --quiet 452eb3d789016e744e99d88811add0f7e0949165 HEAD -- src include tests`.
- `git apply --check` passes at HEAD. `-fsyntax-only` returns rc 0 with 22 warnings, the same as HEAD.

**What it prints.** Two `std::clog` lines, each inside an already-rejecting branch:
- `EmbeddedGraphTopology.duplicateCutCrossing` reports the edge, parameter and cut-edge count. For both traces it reports the crossing segment(s), segment count and terminal contact (struck trace and segment, contact face, barycentric `at=`), plus every event incident to both traces (node, kind, edge).
- `EmbeddedGraphTopology.contactCutConflict` reports the trace and position. For each of the two claimant nodes it reports the role (contact/crossing/network), face, point, terminating traces with their contact records, interior positions, and events (kind and edge).

**Neutrality.** `std::clog` precision is saved and restored. No control flow changes. The failure replay (`SurfaceCutGraph.cpp:208`/`:212`) prints each line twice.

**Tests.** There are none. No test reaches either guard deliberately: `TraceEventPositionNodeConflict` has no test reference, and the only `secondTrace` test is the mandatory-edge splitter. The witnesses are the TB132 criteria.

### S7. TB132 frozen — `M6-CP3-TB132-P13-CUT-BINDING-CONFLICT-RECEIPT-FULL-GATE-EXEC`
**Setup.** TB132 runs on the CB155 package with the same inputs:
- gate `941287fa…` (953 rows), census `3af1dc0d…`, deferred `fd433f54…`, harness `78b8002c…`.
- Comparator: TB131 (gate `14349985217`, census `14349666706`).

**Normalizations, applied prospectively:**

| Rule | What it normalizes |
|---|---|
| N1 | Elapsed time. |
| N2 | Newline framing. |
| N3 | Gate-wide, `M3_CP4AB_FRAGMENT_DIAG` records are compared as a multiset of complete records split at the prefix. The prefix count must equal the record count, and the non-record remainder must be byte-equal in order. |
| N4 | Only in the census parameterized rows, the bytes of `GetParam() = 16-byte object <…>` are masked. |
| N5 | Lines starting `EmbeddedGraphTopology.duplicateCutCrossing ` or `EmbeddedGraphTopology.contactCutConflict ` are removed before comparison. |

**Negative controls.** The comparator must report MISMATCH on mutated TB131 copies with:
- one M3 record removed, duplicated or altered;
- one non-record byte altered;
- one ledger field changed.

**MATCH requires all of:**
1. All 953 gate and 3 census substantive ledger records equal TB131:
   - row 858 RED only at `:155`;
   - Cylinder PASS (288 quads);
   - BunnyRandom and Vase RED.
2. Raw logs equal TB131 under N1–N5.
3. `duplicateCutCrossing` lines appear only in the 19 sphere rows: 380, 388, 393, 394, 396, 397, 644, 645, 648, 669, 686, 691, 694, 698, 699, 700, 843, 844, 858. `contactCutConflict` lines appear only in the census BunnyRandom log. Within one log, the lines of a failing build are identical.
4. Rows 644 and 698 each contain a `duplicateCutCrossing` line with `edge=(0,2)` whose first trace is 4. BunnyRandom contains a `contactCutConflict` line with `trace=82`, whose claimant is a contact in face (21,72,273). This falsifies or confirms S2/S3.
5. Anything else is a MISMATCH.

**Data, not criteria:**
- the second trace and its parameter;
- the shared events;
- each claimant's role and events (edge-carrying, i.e. FC-7′-promoted, or not);
- any zero barycentric coordinate (S4).

**Routes:**
- MATCH → `M6-CP3-TB132-P13-CUT-BINDING-CONFLICT-RECEIPT-FULL-GATE-REV`.
- Criterion 4 fails → the static model is falsified → independent Review.
- Infrastructure → `M6-CP3-TB132A-P13-CUT-BINDING-RECEIPT-ORCH`.

### S8. Turn sequence
1. RA-253 (this re-review) — COMPLETE.
2. `M6-CP3-CB155-P13-CUT-BINDING-CONFLICT-RECEIPT`, compile only. Compile defect → `M6-CP3-PLAN-P13-CUT-BINDING-RECEIPT-STOP`; infrastructure → `M6-CP3-CB155A-P13-CUT-BINDING-RECEIPT-ORCH`.
3. `M6-CP3-TB132-P13-CUT-BINDING-CONFLICT-RECEIPT-FULL-GATE-EXEC`.
4. `M6-CP3-TB132-P13-CUT-BINDING-CONFLICT-RECEIPT-FULL-GATE-REV`. It attributes both sites, decides S4/O45, and freezes at most one repair DEFN per site:
   - sphere: a shared network node on a cut edge, or a missed producer contact;
   - BunnyRandom: coincident-contact node identity, under FC-1/FC-4.
5. Held: `M6-CP3-DEFN-P13-TERMINAL-CUT-OUTCOME`, then `M6-CP3-DEFN-P13-FACE-CONTACT-OUTCOME` (FC-6); the row 858 face-witness DEFN comes after the sphere repair.

Withdrawn: `M6-CP3-DEFN-P13-CARRIER-CONTACT-SWITCH-COMPARISON`, CB149B, CB152. Parked: CB145.

**Unchanged:**
- Accounting: stable 66/17/49, debt 1, deferred 81; CP2 491/491; CP3/selector497 unpromoted.
- Decisions: D11=A, D12=A, D10 deferred, D6 pending.
- Open items: H2, O46, C5/O42/O43, FC-1/FC-4 producer proof and the direction witness are carried.
