# TB-REV-157 — independent evidence review (work in progress, 2026-11-21 UTC)

**Canonical turn:** `M6-CP3-TB-REV-157-P13-EDGE-LOCUS-ALONG-EDGE-RAY-KEY-FULL-GATE`.
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`; PR #8 remains open, draft and unmerged.
**Boundary:** Review only. No code, test, fixture, selector, benchmark, build, or workflow source was edited on the working branch; no tests, benchmarks or builds were executed in this review.

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

An independent script checked all 975 result rows and per-case raw-log digests; 972 earlier rows have matching identity, result and normalized output under frozen N1–N3 with **zero exceptional allowances**. Of these, 563 logs are byte-identical and 1,750 complete region-support records match under N3. No gate log contains `RotationTraceRaysAlongSharedEdge`, `RayRunsAlongLocusEdge`, or `FirstPieceNotLeavingLocusIntoFace`.

Census157 matches Census156 on all 3/3 cases under frozen N1–N4, retaining the *unmasked* `platform-digest`. Cylinder passes; BunnyRandom and Vase remain RED at their established sites. Neither the current review nor TB157 reran a benchmark. Execution-boundary records confirm artifact `14718074764`, source `47a874ee8baa86284eeee11b4a28f9cca06d73f9`, with configure/compile/relink/benchmark **false**, exit 0 and postflight true. `compare_commits` from that source to the review-entry branch head recorded **no change** in `src/`, `include/`, `tests/`, `benchmarks/`, CMake surfaces, or frozen selectors.

## Assessment — limited mechanism proof; no production promotion

The new tests directly call `edge_locus_edge_ray_primary`, `edge_locus_into_face_primary`, and `edge_locus_edge_ray_composition_valid`; the test at 974 checks the required interleaving and collision falsifier. These checks are non-vacuous for the pure arithmetic, but no TB157 source fixture makes a real slide-contact edge node flow through `build_rotation_system` with `(arcEdgeRays, traceAlongEdgeRays)=(0,2)`. The prior TB-REV-156 adversarial V3 obligation thus remains **not fully demonstrated**.

Sphere row 686 is still V18/E30/F18, Euler characteristic 6 rather than source 2; four slide-interior contacts remain without graph ownership. Rows 644/669/698 still terminate `CutSearchExhaustedBeforeCellularity`. Amendment 14 temporarily withholds slide carriers from cut candidates, and the stop switch remains unwired. Stable accounting remains 66 events / 17 categories / 49 recurrences; produced-witness debt 1; deferred 81. CP2 491/491 accepted; CP3, selector497, D0 and H4 not promoted.

## Candidate for V3 stop-switch helper, NOT YET FROZEN

The Review prepared an **unapplied source candidate**, confined to the existing tracing header, tracing implementation and existing test file. It models a later pending trace entry into the *strict interior* of a committed wall slide, returns the moving trace's existing committed endpoint with `carrierLocus` and the wall's segment identity, and uses existing `carrier_contact_slide_position` to identify the wall-side split. It does **not** publish an event, alter a production consumer, permit slide cuts, or change the source branch's code.

- Candidate patch SHA-256 `489b1ab3297241f945ea97ffc674751c0dc4cbad72c2ff7447cca09f8f8c62d5`, size 10,336 bytes; exact raw file retained at [Google Drive](https://drive.google.com/file/d/1qeTv5MIdAHCu_EpSgEhVlm4rZZxKvbNz/view) in `Directional-CI` and as conversation download. Syntax-only checks passed for the prospective tracing translation unit and existing test translation unit with the four GMP defines (no executed tests or built artifacts); the test source retained six existing override warnings. **Do not treat this as a compiled-and-executed accepted implementation**.
- Candidate includes a positive exact slide-contact stop and wall-cut witness, negative earlier-arrival and absent-slide cases, and two source-derived opposite edge pieces classified into primary slots 0 and 2. However this *still does not execute actual `build_rotation_system` at a contact node*. It therefore does not satisfy the whole V3 reaching obligation and cannot yet be called the frozen exact next CB.
- To complete *this Review* before assigning a successor, construct an independent source-attached edge-locus graph witness with the two split trace arcs and invoke the actual rotation builder (not only pure helpers); confirm it reaches composition `(0,2)`, has two distinct ordered slots, and fails when the two rays share a direction. Add this as an exact reaching test to the prospective helper patch, verify C++ syntax and `git apply --check`, recompute full patch SHA, and only then freeze one bounded CB with strict STOP gates and update durable handoff. Do not start that CB in this Review.

**Carried obligations:** TB-REV-156 V3 (full reaching test and exact helper diff); RA-281 F1/F2/F3 (interim restriction and producer boundary); RA-275 S4a (real slide-plan conformity); O47/C5/O48/O49; sphere χ+4 and four unowned contacts. Neither the scoped GREEN nor the candidate patch discharges these product obligations. RA-279 C1/C2 remain narrowly discharged from TB156/row858 and row972, without any new product claim.

## Recommendation — finish the same Review turn

The evidence portion of TB-REV-157 is upheld. **Do not advance** to a successor code turn until V3's integrated, independent reaching proof and exact patch are frozen. Preserve this turn as unfinished rather than claiming a successful closeout on a pure-helper-only test. No change to selector membership or checkpoint acceptance is authorized.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | TB157 prefix 972 bytes matches TB156 full manifest, hashes above; CP2 focused selector hash above |
| Decisive claims independently re-derived | Six outer ZIP digests and internal checks; 975 rows; N1–N3 gate; N1–N4 census; forbidden reasons; execution boundary; code drift |
| Non-vacuity checked | Three arithmetic helpers have meaningful assertions; integrated `(0,2)` rotation node is still unwitnessed |
| Prior obligations discharged/carried | V3, RA-281 F1/F2/F3, RA-275 S4a, O47/C5/O48/O49 and sphere carried; RA-279 C1/C2 remain narrowly discharged |
| Stable accounting | 66/17/49, debt 1, deferred 81; CP2 491/491 only |
| New candidates/obligations recorded | Candidate exact patch stored separately in Drive; reaching test and frozen successor pending; no new stable regression |
| ORIENTATION currency line | Pending same-turn closeout; remains under review |
| ORIENTATION §3 / §4 / §7 / §8 | Pending; no new changed product witness |
| CHANGELOG | Pending same-turn closeout |
| ROADMAP | n/a — checkpoint has not advanced |
| Selector manifest | n/a — no selector added or accepted |
| LESSONS | Existing evidence/non-vacuity rule; no new general lesson yet |
| Consolidation under CLEAN_UP_POLICY | n/a — active scoped record, no redundant history folded |
| Successor frozen | **Pending**, V3 integrated reaching test missing; no successor launched |
| Turn boundary held | Yes; Review only, no product/test/selector mutation or runtime |
| `review_check.py boundary` | Pending: GitHub snapshot lacks `.git`; static compare confirms no source/selector drift but is not the script's full repository check |
| `STATUS` lifecycle maintained | Review entry beacon written; terminal beacon must remain IN_PROGRESS until V3 is resolved |
| Pushed to origin, branch in sync | Repository review record is being published; pending direct final verification |