# TB-REV-158 — independent slide-contact cut-binding full-gate review (2026-11-21 UTC)

## Situation

**Qualified PASS for the immutable scoped TB158 gate.** The review independently verified the CB-174 packaged source, the 976-case gate, the unchanged 975-case TB157 prefix, and the three-case production census. This is **not** proof of a production slide stop, sphere cellularity, or M6-CP3 completion. The separate successor is `M6-CP3-CB-175-P13-LATER-SLIDE-CONTACT-STOP-SWITCH` (Code + Build only); this review did not start it.

## Background — independent primary evidence

- Compiled source `5190b0e759146342998e3f380f7e5fe4eabd1714` from CB-174 package `14724824631` (ZIP SHA-256 `d97f3c7ee36a7cec12ede2c73955b1348c3320951e5dbdce71aed5a4db5de205`); verified **28/28** internal checksums. Eight GMP/GMPXX targets are recorded; package `runtimeExecution=false`. The comparison from that source to reviewed snapshot `8372f109a606ea5af880ae58a3f01b07d4c24ed1` shows 19 documentation/control-plane commits and **no** changes under `src`, `include`, `tests`, `benchmarks`, `cmake`, or root CMakeLists.txt.
- Gate [run 44952039401](https://github.com/akashskypatel/Directional/actions/runs/44952039401) artifact `14725784889`, ZIP SHA-256 `b50d32d0892cbc8e19db5f827512cdda2cd2d3698e86335bd77d2da1296554e5`, **1960/1960** checksums; TB157 artifact `14719149475`, ZIP SHA-256 `9609b0e0eb8b51d692118859fef7f0556f7de5e69c336c1bb5033d2694194d11`, **1958/1958** checksums.
- Census [run 44954165527](https://github.com/akashskypatel/Directional/actions/runs/44954165527), artifact `14727495926`, ZIP SHA-256 `5b3012ca2a3ca8e9f3e5d4d8bc84c27601fb455913d15b67393998e1f57eb8bc`, **9/9** checksums; TB157 census artifact `14719268782`, ZIP SHA-256 `9e8f561953ba4ad552a5c30cd2430d0e23c22230e074abd3e2c4ce60b92ebd63`, **9/9** checksums.
- Manifest `gates/Architecture_M6_TB158_P13_Slide_Contact_Cut_Binding_Full_Gate_Case_Manifest.tsv`: full SHA-256 `6a37e4612a6b463eac3de4b5da4ed86f5bba52ac54bfbb1e472ca7508b7caf0f`; exactly 976 identities; first 975 **byte-identical** to TB157 manifest, SHA-256 `92eb18e8aaf2881d933c88dfde1a86b957334fe6785fd88f404459812cdc50c7` (including header). The new row is `FieldAlignedCarrierOccupancy.CarrierContactCutPositionTakesTheEntryElseTheSlideInterior`.

## Assessment — re-derived results and limits

1. Independently parsed the gate manifest and per-row ledger: **976 unique, executed, PASS; 0 RED, skipped, abnormal or duplicate**. CP2 accepted **491/491 PASS**. Membership is **976 gated + 81 deferred = 1,057**. Postflight passed; control and process boundaries did not fail. Every case identity, binary and classification matches the manifest. `compile/configure/relink/benchmark=false`, run exit 0.
2. For each of the first **975/975** cases, compared the TB157 and TB158 ledger fields, verified each raw-log SHA-256, and applied the frozen normalizations: N1 timing, N2 line endings, N3 whole diagnostic records as a **multiset**, while preserving all other log bytes and their order. **736/975 raw logs are byte-identical; 239/975 raw logs differ, but all 975 normalize to exactly equal.** The allowance is empty. No new `InvalidCutGraphBinding` appears.
3. Independently parsed and compared the three production census cases under N1–N4 (N4 masks only 16-byte `GetParam()` presentation). All three match TB157, retaining the unmasked platform digest. Cylinder **PASS**, BunnyRandom **expected RED**, Vase **expected RED**; these two REDs remain unresolved and do not become production passes.
4. CB-174 changed the cut-binding consumer first: `carrier_contact_cut_position` chooses exact entry or slide-interior position, `CarrierContactBinding::struckParameter` preserves the slide fraction, and wall arcs use the same parameter. The added row 976 calls the helper directly, including negative controls for endpoints and incorrect line identity. The test itself states the producer does not yet emit a slide-interior contact. **Non-vacuity is limited to helper classification and not end-to-end producer reaching.** V3b must show a real published producer event, its consumer binding, and its two rotated edge rays in one canonical product.
5. No accepted regression lost or new candidate proved. The stable baseline remains **66 events / 17 categories / 49 recurrences**, **1** produced-witness debt, **81** deferred. The sphere cut graph remains Euler χ6 versus source χ2 (+4), with four unowned slide contacts; the existing stop switch is unwired. Amendment 14 still withholds slide carriers, and a selected-cut slide still fails closed. CP3/selector497/D0/H4 **not accepted or promoted**.

## Recommendation — exactly one bounded successor

Freeze **`M6-CP3-CB-175-P13-LATER-SLIDE-CONTACT-STOP-SWITCH`**, **Code + Build only**. It must compile and package with GMP/GMPXX but run **no tests or benchmarks**. Preserve the CB-174 binding consumer and all accepted gates, guards, fallback and fail-closed behavior. Required source behavior:

1. One **pure, shared** Later-only predicate, used by BOTH the committed-wall loop and the pending-pair loop and by `slideContactArrival` receipt logic. It must require `!movingInSlide && wallInSlide`, a strict interior wall-slide fraction (reuse `carrier_contact_slide_position`), and a `Later` result when moving arrival is compared with `field_aligned_arrival_at_slide_parameter`. Earlier and Inconclusive remain on their present path; do not implicitly stop both.
2. On true, enqueue the **existing** contact event with `carrierLocus`, including wall-proposal provenance. Use the current event publisher; do **not** add a parallel terminal contact builder, duplicate event, positional identity merge, or synthetic cut node.
3. Producer-aware reaching proof V3b: an actual source-edge slide contact from the sphere production network must create an authoritative cut-node composition `(0,2)` with two distinct ordered edge primaries (slots 0 and 2), and one entering-face ray at `2*side+1`; the exact consumer must bind and split the struck slide. The proof **must fail** when the event is suppressed and must reject a same-direction ray mutation as `RotationTraceRaysAlongSharedEdge`. A helper-only test or a manufactured node cannot satisfy this.
4. Freeze independent **per-row** predictions *before* compiling or running the successor test gate for all 21 existing slide-contact receipt rows, with trace/contact identities, Later/Earlier/Inconclusive, committed/proposal status, expected output and nonchanges. Row686's predicted Euler change must be stated explicitly as χ6→χ2 and include expected V/E/F deltas and four contact receipts; this is a falsifiable prediction, **not** a result. Include BunnyRandom pending-wall `26:1/99:0`; do not generalize its site to the sphere. If exact V/E/F deltas cannot be derived ahead of implementation, stop for a separate definition/review rather than invent numbers.
5. Do not resolve slide-start subdivision in this turn. Retain Amendment 14 and selected-cut slide fail-closed; RA-281-F1/F2 and RA-281-A14 belong to later R1; RA-275 S4a, O47/C5/O48/O49, V3b, and sphere χ+4 remain open until independent evidence proves each discharge. O49 is outside this switch path.

**Stop and falsifiers:** any accepted-gate change without prior authorization, newly introduced `InvalidCutGraphBinding`, missing source-event/consumer reach, wrong edge-ray composition, same-direction ray accepted, receipt predicate divergence, multi-owner event, loss of hard rails, or any silent promotion of CP3/497/D0/H4. After compile-only CB-175 a separate TB-EXEC-159 must execute the frozen full gate with independent TB-REV-159 adjudication. No successor execution in this review.

## Procedure and source-boundary verification

The reviewer fetched multiple repository documents before the mandatory snapshot read-mode decision. This was an actual ordering error; source review was stopped and moved to exact snapshot mode. Run [44956196228](https://github.com/akashskypatel/Directional/actions/runs/44956196228), artifact `14726664732`, ZIP SHA-256 `5b5c20e8460cc655186e23eedbe93b08be50773fd4ac62eb5e06f586946e05fa`, snapshot source `8372f109a606ea5af880ae58a3f01b07d4c24ed1`, verified 5,692-file archive. The initial tool-call ledger was not initialized, so the full tool-call count is **unknown**, not falsely reconstructed. No code, test, selector, fixture, benchmark, build, or runtime operation was performed by this Review.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | 975-row gate manifest prefix byte-identical to TB157; SHA-256 `92eb18e8aaf2881d933c88dfde1a86b957334fe6785fd88f404459812cdc50c7`; 976-row whole manifest SHA-256 `6a37e4612a6b463eac3de4b5da4ed86f5bba52ac54bfbb1e472ca7508b7caf0f`. Original accepted 491 tests all PASS; no selector file changed. |
| Decisive claims independently re-derived | 976/976, 975/975 frozen normalized baseline, 3/3 census, internal checksums 28/1960/1958/9/9, package source, read-only source compare, no forbidden binding failure. |
| Non-vacuity checked | Helper negative inputs execute in row976; no product reaching in row976. V3b carried to CB-175 and TB159, not accepted. |
| Prior obligations discharged/carried | TB-REV-157-W3: consumer code compiled, helper tested; production reach carried. W4: Later-only + shared predicate to CB-175. W5: exact diff retained. RA-281 F1/F2/F3 + A14, RA-275 S4a, O47/C5/O48/O49, V3b and sphere χ+4 carried, with owners in successor/R1. |
| Stable accounting | 66 / 17 / 49; debt 1; deferred 81; CP2 accepted 491/491; CP3 selector497 not accepted. |
| New candidates/obligations recorded | No new stable event/candidate; successor's mandatory producer reaching and predictions recorded in this review and tracker. |
| ORIENTATION currency line | Updated to TB-REV-158, 2026-11-21. |
| ORIENTATION §3 / §4 / §7 / §8 | §3 and §7 corrected; §4 and §8 unchanged because no production witness changed and no new defect pattern proved. |
| CHANGELOG | Added TB-REV-158 entry. |
| ROADMAP | Updated M6 CP3 at-a-glance; checkpoint still active. |
| Selector manifest | n/a — no selector added, changed, or promoted. |
| LESSONS | Existing producer-before-consumer and non-vacuity lessons apply; no new lesson added. |
| Consolidation under CLEAN_UP_POLICY | n/a — current TB158 report, current review, and prior adversarial evidence remain load-bearing; no superseded file deleted or silently folded. |
| Successor frozen | `M6-CP3-CB-175-P13-LATER-SLIDE-CONTACT-STOP-SWITCH`; above preconditions and falsifiers, no implementation in Review. |
| Turn boundary held | Read-only evidence, source inspection, documentation updates; no compile, test, benchmark, code, fixture, selector or runtime mutation. |
| review_check.py boundary | Pending exact full-Git runner check; local no-history source archive cannot prove rewrite ancestor. Changed-path and selector-byte check separately recorded; do not claim a full-history PASS without remote evidence. |
| STATUS lifecycle maintained | Review entry 2026-11-21T22:18:45Z; final beacon recorded after accepted documentation push, as last repository action. |
| Pushed to origin, branch in sync | Verified by review patch apply result / branch authority after final documentation commit. No local `git status -sb` on remote checkout; verify via GitHub commit/ref evidence instead. |
