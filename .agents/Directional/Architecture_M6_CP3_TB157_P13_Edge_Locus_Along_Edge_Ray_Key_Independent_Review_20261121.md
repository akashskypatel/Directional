# TB-REV-157 — independent evidence review (complete, 2026-11-21 UTC)

**Canonical turn:** `M6-CP3-TB-REV-157-P13-EDGE-LOCUS-ALONG-EDGE-RAY-KEY-FULL-GATE`.
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`; PR #8 remains open, draft and unmerged.
**Boundary:** Review only. No product, test, fixture, selector, benchmark or build source was edited. One **temporary verification workflow** was created to run the mandatory full-Git boundary script, then deleted. Its reusable workflows and permissions were not modified. No Directional tests, benchmarks or builds were executed in this review.

## Situation — TB157 scoped GREEN upheld by independent byte checks

The execution result from `M6-CP3-TB-EXEC-157-P13-EDGE-LOCUS-ALONG-EDGE-RAY-KEY-FULL-GATE` is correctly reported as **975/975 PASS**, no failures/skips/duplicate cases/control errors; membership 1,056, including 81 deferred. Accepted CP2 remains **491/491**. This is a scoped gate verdict, not checkpoint closure or production acceptance.

## Background — original evidence and recomputation

Re-read six original immutable ZIP artifacts and independently recomputed their outer and internal SHA-256 digests. All matched:

| Asset | Artifact | Outer SHA-256 | Internal matches |
|---|---:|---|---:|
| TB157 gate | 14719149475 | `9609b0e0eb8b51d692118859fef7f0556f7de5e69c336c1bb5033d2694194d11` | 1958/1958 |
| TB156 gate | 14715014772 | `0bfac9c0eaf626408d666a5bd298b681236e7f54c69bfd25340b6064aa8d1e9b` | 1952/1952 |
| TB157 census | 14719268782 | `9e8f561953ba4ad552a5c30cd2430d0e23c22230e074abd3e2c4ce60b92ebd63` | 9/9 |
| TB156 census | 14716036015 | `847b88f3e95881ed2044c6ed9cd49bce9eba1e89a567a95bb202d3fbe8bd1680` | 9/9 |
| TB157 snapshot | 14718564682 | `38438349589eecadebb6c11aeb44e4cfa3a523e80e9a0feac1d6b349f8903181` | 5683/5683 |
| CB173 compiled package | 14718074764 | `cad613506dbadff3179f17a8492a57062d31cf27cfff6d1378417f351ab5ad09` | 28/28 |

The TB157 source manifest is exactly 975 cases, SHA-256 `92eb18e8aaf2881d933c88dfde1a86b957334fe6785fd88f404459812cdc50c7`; its first 972 rows equal the complete TB156 manifest byte-for-byte (SHA-256 `cbba9e76fa436f1e2e6ef34d50bb377b931c19fc4780660412a9f6072128dc6a`). Rows 973–975 are the three named edge-locus helper cases and independently pass. The 491 accepted CP2 result rows pass. The accepted focused selector source has SHA-256 `2aa57aac48ac8c41ea86ed459cdd1acd27eb17c8d3dbe1b4ac7b9c54c67374ed`; no selector mutation was made.

The independent verifier was re-executed on 2026-11-21 in this continuation and returned exit 0. An independent script checked all 975 result rows and per-case raw-log digests; 972 earlier rows have matching identity, result and normalized output under frozen N1–N3 with **zero exceptional allowances**. Of these, 563 logs are byte-identical and 1,750 complete region-support records match under N3. No gate log contains `RotationTraceRaysAlongSharedEdge`, `RayRunsAlongLocusEdge`, or `FirstPieceNotLeavingLocusIntoFace`.

Census157 matches Census156 on all 3/3 cases under frozen N1–N4, retaining the *unmasked* `platform-digest`. Cylinder passes; BunnyRandom and Vase remain RED at their established sites. Neither the current review nor TB157 reran a benchmark. Execution-boundary records confirm artifact `14718074764`, source `47a874ee8baa86284eeee11b4a28f9cca06d73f9`, with configure/compile/relink/benchmark **false**, exit 0 and postflight true. `compare_commits` from that source to the review-entry branch head recorded **no change** in `src/`, `include/`, `tests/`, `benchmarks/`, CMake surfaces, or frozen selectors.

## Assessment — limited mechanism proof; no production promotion

The new tests directly call `edge_locus_edge_ray_primary`, `edge_locus_into_face_primary`, and `edge_locus_edge_ray_composition_valid`; the test at 974 checks the required interleaving and collision falsifier. These checks are non-vacuous for the pure arithmetic, but no TB157 source fixture makes a real slide-contact edge node flow through `build_rotation_system` with `(arcEdgeRays, traceAlongEdgeRays)=(0,2)`. The prior TB-REV-156 adversarial V3 obligation thus remains **not fully demonstrated**.

Sphere row 686 is still V18/E30/F18, Euler characteristic 6 rather than source 2; four slide-interior contacts remain without graph ownership. Rows 644/669/698 still terminate `CutSearchExhaustedBeforeCellularity`. Amendment 14 temporarily withholds slide carriers from cut candidates, and the stop switch remains unwired. Stable accounting remains 66 events / 17 categories / 49 recurrences; produced-witness debt 1; deferred 81. CP2 491/491 accepted; CP3, selector497, D0 and H4 not promoted.

## Exact V3a successor candidate — frozen source scope, not executed

The Review prepared and then guarded an **unapplied source candidate**, confined to the existing tracing header, tracing implementation and existing test file. It models a later pending trace entry into the *strict interior* of a committed wall slide, returns the moving trace's existing committed endpoint with `carrierLocus` and the wall's segment identity, and uses existing `carrier_contact_slide_position` to identify the wall-side split. It does **not** publish an event, alter a production consumer, permit slide cuts, or change the source branch's code.

- Revised **unapplied** candidate SHA-256 `684d53d681f1e1ba82730e52239042a6947d6f5a6f035b70d0f252c41807d238`, 13,342 bytes, [preserved in Drive](https://drive.google.com/file/d/1ZssZep4xVhe6l3AXEHyaEIaiU57Q2nwJ/view) and as chat download. Its three-path patch applies to the exact frozen package source with `git apply --check` and `git diff --check`. Earlier candidates `489b1ab3…62d5` and `cb65e1e9…443c` are superseded. The test now checks equal arrival, same-trace identity, missing moving segment, slide endpoint, wrong previous carrier and invalid wall segment index in addition to the existing cases. Syntax-only checks passed for the prospective tracing translation unit and existing test translation unit with the four GMP defines (no executed tests or built artifacts); the test source retained six existing override warnings. **Do not treat this as a compiled-and-executed accepted implementation**.
- Revised candidate includes an exact slide-contact stop and wall-cut witness, negative earlier/equal arrivals, absent/endpoint slides, trace identity, component/region identity and carrier checks, plus two source-derived opposite edge pieces classified into slots 0 and 2. The component/region negatives change typed metadata and are **not** two-sheet production fixtures. These are meaningful helper controls, but **none invokes actual `build_rotation_system`**; they do not discharge V3b.
- The exact helper CB is frozen as a compile-only successor, with STOP rules and local non-vacuous helper assertions. Full V3b source-attached graph production, two split arcs, rotation-builder `(0,2)` receipt, distinct ordered slots and same-direction failure belong to the separate wiring CB and its later Test + Benchmark gate. A missing builder witness is still a STOP for that later gate, **not** permission to claim success from this helper test.

**Carried obligations:** TB-REV-156 V3a exact helper source is frozen but uncompiled/unexecuted; V3b full reaching proof is carried to later canonical stop-switch wiring; RA-281 F1/F2/F3 (interim restriction and producer boundary); RA-275 S4a (real slide-plan conformity); O47/C5/O48/O49; sphere χ+4 and four unowned contacts. Neither the scoped GREEN nor the candidate patch discharges these product obligations. RA-279 C1/C2 remain narrowly discharged from TB156/row858 and row972, without any new product claim.

## Additional independent finding — V3 requires two production stages

The [source-level feasibility record](Architecture_M6_CP3_TB_REV_157_V3_Reaching_Test_Feasibility_20261121.md) identifies an incompatibility in the inherited V3 test timing. The original V3 asks for an **unwired** stop helper with a test that reaches a full rotation-builder node. Yet `make_from_candidate` reconstructs the canonical network after validation (`SurfaceCellTracing.cpp:6155+`); `build_node_loci` only receives published network events or bound cut nodes (`EmbeddedGraphTopology.cpp:2044+`); `build_rotation_system` consumes that network and its actual arcs (`:2756+`). The stand-alone helper publishes none of these. A pure `edge_piece_ray` check or a fabricated candidate therefore cannot prove the required `(0,2)` production node.

The review has **not** waived the integrated requirement. It separates the technical evidence into V3a (exact helper definition and non-vacuous local contracts) and V3b (canonical node/arc publication, actual rotation-builder call, distinct along-edge rays and same-direction mutation during later producer wiring). V3b remains mandatory before accepting the stop-switch wiring gate. An [exact CB-174 successor specification](Architecture_M6_CP3_CB174_P13_Later_Entry_Slide_Stop_Helper_Code_Build_Proposal_20261121.md) records the guarded source patch SHA-256, exact per-file preimages and postimages, independent falsifiers, and compile-only STOP rules. It is **the single frozen successor definition, not yet started**. The Review has adjudicated the inherited V3 sequence with source evidence; this turn must finish the remaining policy checks before the successor can start.

## Recommendation — complete the same Review turn

The TB157 evidence portion is independently upheld. Do not start a successor code turn, claim a full builder witness, or change source/tests/selectors in this Review. Retain the resolved V3a/V3b sequencing from the verified producer boundary, preserve the full reaching requirement for the first **wired** node, and finish mandatory review closeout checks. The exact guarded patch remains unapplied until the next separate Code + Build turn. No change to selector membership or checkpoint acceptance is authorized.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | TB157 prefix 972 bytes matches TB156 full manifest, hashes above; CP2 focused selector hash above |
| Decisive claims independently re-derived | Six outer ZIP digests and internal checks; 975 rows; N1–N3 gate; N1–N4 census; forbidden reasons; execution boundary; code drift |
| Non-vacuity checked | Prior helper tests plus exact later-slide arrival tests and six added distinct negative controls; source-attached `(0,2)` rotation node remains mandatory only after canonical producer wiring |
| Prior obligations discharged/carried | V3, RA-281 F1/F2/F3, RA-275 S4a, O47/C5/O48/O49 and sphere carried; RA-279 C1/C2 remain narrowly discharged |
| Stable accounting | 66/17/49, debt 1, deferred 81; CP2 491/491 only |
| New candidates/obligations recorded | Exact frozen CB-174 diff and V3a/V3b source evidence preserved; tracker records falsifier, later V3b owner, and prohibited shortcuts; no new stable regression |
| ORIENTATION currency line | Updated to TB-REV-157, 2026-11-21; review completed and exact next CB documented |
| ORIENTATION §3 / §4 / §7 / §8 | §3, §7 updated; §4 n/a (no new production witness), §8 n/a (known non-vacuity defect) |
| CHANGELOG | Historical WIP entry amended into one complete TB-REV-157 entry with exact CB-174 v3 SHA; dispatcher run 44946465697 success, live top entry verified, consumed Drive patch deleted |
| ROADMAP | TB-REV-157 scoped review completed; CB-174 exact helper-only next; CP3 checkpoint remains active, unpromoted |
| Selector manifest | n/a — no selector added or accepted |
| LESSONS | Existing evidence/non-vacuity rule; no new general lesson yet |
| Consolidation under CLEAN_UP_POLICY | n/a — active scoped record, no redundant history folded |
| Successor frozen | `M6-CP3-CB-174-P13-LATER-ENTRY-SLIDE-STOP-HELPER`; exact three-file diff SHA-256 `684d53d681f1e1ba82730e52239042a6947d6f5a6f035b70d0f252c41807d238`; STOP rules in CB-174 proposal; full V3b builder proof is a separately required wiring-gate condition; turn has NOT started |
| Turn boundary held | Yes; Review only, no product/test/selector mutation or runtime |
| `review_check.py boundary` | **PASS** from full-Git GitHub Actions run 44946170911 at commit b6c0498f: exit 0, all selector hashes and rewrite durable headings PASS; `review_check.py authority 47a874ee...` also PASS. Temporary workflow retired. No local runtime tests/builds |
| `STATUS` lifecycle maintained | Original start preserved; this resumption recorded; terminal COMPLETE beacon must be the final repository write and name CB-174 exactly |
| Pushed to origin, branch in sync | GitHub Actions run 44946170911 printed `git status -sb` with branch tracking `origin` and no ahead/behind; subsequent review documentation written directly to origin by GitHub connector; last source diff verification remains code/selector clean |