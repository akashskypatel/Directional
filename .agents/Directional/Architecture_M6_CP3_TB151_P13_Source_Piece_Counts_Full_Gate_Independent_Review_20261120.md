# TB151 source-piece counts — independent archive Review (2026-11-20 UTC)

## Situation
**PASS at the frozen scope.** This review re-opened four immutable test-result ZIP archives rather than relying on the TB151 execution report. The gate is 966/966 PASS. The preceding 964 cases match TB150 under N1–N3; the accepted M6-CP2 subset is 491/491 PASS. The independent three-case census is 3/3 MATCH TB150 under N1–N4. These are scoped test facts, **not** acceptance of CP3, selector497, D0, H4, row686, row858 or the representative direct-production matrix.

## Background — primary evidence

| Archive | GitHub run | Artifact | ZIP SHA-256 | Independently checked |
|---|---:|---:|---|---|
| TB151 full gate | 44716246061 | 14619414153 | `c28d6ecc128bf9994d3c5f5ba2e2c799c192176f11d8818ca08c70d65caf1dab` | 1,940/1,940 internal hash entries; 966 PASS |
| TB150 full gate | preceding immutable package | 14609657696 | `9e2117dc4bf4d5e097beeaa90236b1c44ceafdba90bc3fd4751ef2cd2472874f` | 1,936/1,936; 964 PASS |
| TB151 census | 44719007530 | 14621727104 | `4eacb6f3d9d272a2ee380527fc8f7abab516508a596d3dea3f955e8086a4c611` | 9/9; 1 PASS, 2 expected RED |
| TB150 census | preceding immutable package | 14610319026 | `b5033d6939a14ce8716455f5dd5f6f20d15087b2ae229c8c646c96052c68225c` | 9/9; 1 PASS, 2 expected RED |

The immutable TB151 semantic source is `2d587a2e7ec00b7dc8d0a24df9f6902f03fec931`, compiled package `14618335833`. The gate manifest's SHA-256 is `2a902d364612071db04ffa5a116cd988c0babccae58308152cb368df0ff612da`; its 964-row byte prefix matches TB150's `bce554e6723dfaa77f54d070aab7edc6508cd3aaf69a6120871e21b349b78926`. The separate three-case manifest is `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793`.

## Assessment — independently recomputed checks

- Gate ledger: `planned=executed=passed=966`; every other outcome/error count is zero; membership 1,047, with exactly the two new identities and no removed member. All 964 prior ledger identities/outcomes are identical. The 491-case accepted prefix remains PASS. Both new raw test logs show PASS: row965 `SourcePieceCountsBindEachTraceSegmentToItsRealPieces`, row966 `IndependentValidationBindsTraceSegmentsToSourcePieceCounts`.
- N1 removes only Google Test duration values, including aggregate `ms total`; N2 normalizes line ends. N3 compares complete `M3_CP4AB_FRAGMENT_DIAG record=region_support_projection` records as multisets and leaves other lines in order. This gives 964/964 raw-log matches, including 1,738 matching M3 records. All 504 `slideContactArrival` lines were compared raw in original order and match unchanged.
- Census: Cylinder remains PASS, BunnyRandom and Vase remain expected RED at `SurfaceCellDesignAcceptanceTests.cpp:493`. N4 masks only four varying `GetParam()` 16-byte process-address occurrences, two in each RED log. Under N1–N4 all three raw logs match TB150. No verdict, typed failure field, platform digest or other text was excluded. Full gate and census prove no compilation, configuration, relink or benchmark execution (`compile=false`, `configure=false`, `relink=false`, `benchmark=false`).
- Non-vacuity: deleting or duplicating one M3 diagnostic record causes a mismatch; changing an ordinary non-M3 raw line also causes a mismatch; changing census text outside the address mask also causes a mismatch. N4 is material because the four address values actually vary. Both new positive guards reached their assertions; they are not substitutes for a production two-piece witness.
- Scope limits: the all-ones source-piece counts do not change the plan digest. Production sliding arcs and row686's oracle still encode face chords while the relevant wall is `faceThenEdge`. Sphere row686 remains `V=18 E=30 F=18`, χ6 versus χ2 (four missing slide contacts). Rows669/698 still record `CutSearchExhaustedBeforeCellularity`. This review does not close O47/C5/O49, H4 or a D0 output gate.

## Recommendation — frozen dependency order (do not execute here)

1. **One successor definition only:** classify each EPO-1 source-arc reader as traversal-sensitive, geometry-only, or both; keep the exact reader inventory in RA-273 S4. Never infer that an edge-slide piece is a face chord. Freeze this boundary in `Architecture_M6_CP3_DEFN_P13_Source_Arc_Reader_Classification_Plan_20261120.md`.
2. O49/EPO-6: specify the edge-piece-only slide-interior rule, unwired. Then make the row686 oracle consume real pieces **test-only**, without changing production arcs.
3. EPO-2/3/4: coordinate *all* piece-path, count, ray, rank and digest consumers in one Code + Build cutover. Add real piece counts to the digest only at this cutover, not while they remain all ones. Test with an immutable full gate and separate census.
4. Only then switch the `carrier_contact_slide_position` stop consumer. Test row686 χ2, rows669/698 and all four graph nodes independently. Only after that proceed to CB170, CB171, CB172/O48; the latter needs the vertex-overlap rule and tie control. Keep `chainRimSchedules=false` and all held decisions untouched.

**Disposition:** Uphold TB151 PASS at frozen scope; no new stable event or candidate. Stable accounting **66 events / 17 categories / 49 recurrences**; produced-witness debt **one**; **81** deferred. CP2 **491/491** remains the accepted authority. No runtime or product/test/fixture/selector mutation in this review. Existing RA-273 obligations are carried by the exact ordering above; no new generalized lesson is needed.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | TB150 first 964 manifest rows: `bce554e6723dfaa77f54d070aab7edc6508cd3aaf69a6120871e21b349b78926`; TB151 full manifest: `2a902d364612071db04ffa5a116cd988c0babccae58308152cb368df0ff612da`; exact byte prefix |
| Decisive claims independently re-derived | Four result ZIP hashes, 1,940 + 1,936 + 9 + 9 internal checks, 966/966, 964/964 N1–N3, 491/491, 504 raw receipts, 3/3 N1–N4 |
| Non-vacuity checked | M3 record removed/duplicated; ordinary line changed; census unmasked line changed — every control mismatched |
| Prior obligations discharged/carried | TB151 archive review discharged; EPO-1/EPO-6/O49/row686/EPO-2/3/4, C5/O47/O48 and H4 carried; no promotion |
| Stable accounting | 66/17/49, debt one, CP2 491/491 accepted, 81 deferred |
| New candidates/obligations recorded | None new; existing ordered work carried in TODO and handoff |
| ORIENTATION currency line | TB151 independent Review and next definition turn dated 2026-11-20 |
| ORIENTATION §3 / §4 / §7 / §8 | §3 and §7 updated; §4 unchanged witness states; §8 existing lessons apply |
| CHANGELOG | New review entry |
| ROADMAP | M6-CP3 at-a-glance updated; no checkpoint promotion |
| Selector manifest | n/a: no selector changed or accepted |
| LESSONS | Existing evidence/acceptance and comparison lessons apply; no new pattern |
| Consolidation under CLEAN_UP_POLICY | Current TB151 execution, active RA-273 chain, and exact CB168M/N records remain needed for cutover; no current authority folded or deleted |
| Successor frozen | `M6-CP3-DEFN-P13-SOURCE-ARC-READER-CLASSIFICATION`; falsifiers and stop rules in successor plan |
| Turn boundary held | Runtime-free analysis of archived results; no source, test, fixture, selector, benchmark or workflow modifications |
| review_check.py boundary | Invoked on a temporary source snapshot: code/test and selector checks PASS; full script FAIL because Git history for `8b7299b43` is absent. Verified all original protected headings against GitHub historical blobs and the exact remote changed-file set. History-complete execution remains unverified. |
| `STATUS` lifecycle maintained | Entry written on 2026-11-20T11:13:24Z; final beacon must be the last repository mutation |
| Pushed to origin, branch in sync | Drive application [run 44729296206](https://github.com/akashskypatel/Directional/actions/runs/44729296206) succeeded; applied commit `4751c22806070145d98ebb69aeda1161d9b1df28` verified as PR #8 head (before this small documentation correction). No local source checkout push was performed. |

## RA-274 — adversarial re-review of this Review (2026-11-20 UTC)

Runtime-free: two Haiku read-only audits, direct source reads, `-fsyntax-only` on the new patch, `git apply --check`, manifest self-check. **TB151 PASS is upheld; the successor DEFN is withdrawn and replaced by an exact CB.**

### S1 — Evidence (independently re-derived)

- All four ZIP SHA-256 values match. Internal hashes verify 1,940/1,936/9/9, and the ledger `log_sha256` values match the raw logs.
- Rows 1–964 agree with TB150 on every ledger field. All 964 raw logs match under N1–N3: 1,738 M3 records in each run, and the 504 `slideContactArrival` lines are identical in order. Rows 965/966 PASS with their `[ OK ]` lines.
- Census: 3/3 match under N1–N4. N4 is material: the masked bytes differ between runs, two per RED log. Every `platform-digest` line is byte-identical.
- All four controls mismatch: M3 line deleted, M3 line duplicated, ordinary line altered, unmasked census line altered.
- `compile`, `configure`, `relink` and `benchmark` are all `false`. The boundary `artifact` field is the executable package (14618335833), not the result artifact.
- Code: `041bde764` plus the two frozen diffs reproduces `2d587a2e7` byte-for-byte in all five files. `src`, `include` and `tests` are unchanged since.

### S2 — Design defects in this Review

1. **The successor repeated a frozen contract.** EPO-1 ([RA-262](Architecture_M6_CP3_TB140_P13_Trace_Segment_Pieces_Helper_Full_Gate_Independent_Review_20261118.md)) already splits readers into a traversal layer and a geometry layer. The DEFN asked a later turn to classify them again, using prose acceptance criteria and with no executing exit (RA-172/RA-223). The classification is Review work; S3 completes it here.
2. **The inventory it carried was wrong (my error in RA-273 S4).**
   - `GlobalConformityBaselineSupport.cpp:530/:617` read Mandatory arcs only. They are unaffected.
   - The inventory missed the real geometry consumer: both conformity input builders copy every arc's `sourcePath` into span support (`RemeshPipeline.cpp:1014`, `GlobalConformityBaseline.cpp:830`).
   - It also missed `CutGraphDisplay.cpp:126`.
3. **EPO-6's side rule is under-specified.** "Forward orbit to F" holds only when F winds the carrier in the slide's direction.
   - The third-edge rule (`SurfaceCutGraph.cpp:589–625`) and the mandatory rule (`:493`, `EmbeddedGraphTopology.cpp:3332`) both make the forward dart the arc's left side.
   - A trace can slide either way along an edge of its face.
   - The exact rule: F takes Forward iff `face_orients_edge_forward(F, e)` equals "the piece advances first→second". The face across e takes the other dart.
4. **The recommendation stayed monolithic.** It kept "all consumers in one Code + Build". S3 shows the conformity, display and schedule readers consume real pieces without code changes. The cutover therefore splits by what each reader needs.

### S3 — Reader classification (EPO-1, complete)

| Reader | Reads | Layer | At the cutover |
|---|---|---|---|
| `validate_candidate_structure` + replay (`GlobalTopologyPlan.cpp:2692–2718`, `:2953`) | faces, counts, path | binding | Already accepts the three shapes (CB168N) |
| `candidate_semantic_digest` (`:2520–2522`) | faces, path | hash | Path hash changes; add counts (RA-273 S2.3) |
| `actual_complement_component_count` (`EmbeddedGraphTopology.cpp:3414`) | path | geometry | Edge pieces become barrier intervals. The sliver between chord and edge changes side, but the count is unchanged unless an edge piece overlaps another arc's barrier (O48) |
| `build_source_face_ownership` (`SurfaceCutGraph.cpp:508–758`) | `sourceFaces`, trace segments | traversal | Unchanged for faceThenEdge. Edge-only segments need O49 (S2.3) |
| Conformity span support (`RemeshPipeline.cpp:1014`, `GlobalConformityBaseline.cpp:830`) → partition-stable runs, preferred count, breakpoints, schedule digest | whole path | geometry | **New.** A slide bend starts a new metric run, so the count, breakpoints and `global-conformity-baseline=` can change on any plan that publishes a slide |
| `bound_arc_schedule` `:14237`, piece total `:19764` (`SurfaceCellTracing.cpp`) | path vs span support | consistency | Self-consistent: the support is built from the same path |
| Disc phase front `:17097` | path carriers | traversal + geometry | Admits a trace arc only when every piece is a vertex-ended edge. An all-edge-only arc is newly admitted: an O49 obligation |
| `edge_arc_schedule` `:14286`, `generator_route_for_span` `:20237`, `GlobalConformityBaselineSupport.cpp:530/:617` | path | — | Mandatory only; unaffected |
| `CutGraphDisplay.cpp:126` | path | display | Polylines follow the slide |

No other `src` reader of `sourcePath`, `sourceFaces` or `sourcePieceCounts` exists (audit at `98b370512`). Rays and ranks (EPO-4) are computed inside the producer, so they stay with the producer switch.

### S4 — Frozen successors

1. **`M6-CP3-CB168O-P13-EDGE-PIECE-FACE-SIDE-HELPER`.** Compile only.
   - Patch: [exact diff](Architecture_M6_CP3_CB168O_P13_Edge_Piece_Face_Side_Helper_Exact.diff), SHA-256 `b8daffc93c26260e9ad7af464560fe24de38054db66b57fa866ab1deacfa0d34`. Numstat: `34 0 src/geometry/EmbeddedGraphTopology.cpp; 13 0 src/geometry/EmbeddedGraphTopology.h; 115 0 tests/FieldAlignedCurveNetworkTests.cpp`.
   - Preimages: `.cpp` `88e6c062…43a3`, `.h` `c9ff6721…bcde`, tests `f3a7d53f…01fb`.
   - Precheck: `git diff --quiet 2d587a2e7 HEAD -- src include tests`.
   - It adds the unwired pure function `edge_piece_face_side(face, piece)`, which implements S2.3 on the producer's own edge piece (one decomposition).
   - Row 967 `FieldAlignedCarrierOccupancy.EdgePieceFaceSideFollowsTheFaceWindingAlongTheSlide` uses the row-960 departure fixture (real output, counts `{1,1}`). Expected sides are read from the declared windings, not from the function:
     - face Forward and the face across Reverse;
     - both swap on the reversed arc;
     - the side is kept on both parts of a slide cut at 1/2;
     - empty for a face without the edge, a face piece, a zero-length piece, an off-edge vertex, and another edge's point.
   - Falsifiers: an always-Forward rule fails, a rule that ignores piece direction fails, and a rule that handles vertices only fails.
   - Syntax: 0 errors; warnings 22/42/27/24 equal HEAD.
2. **`M6-CP3-TB152-P13-EDGE-PIECE-FACE-SIDE-FULL-GATE-EXEC`.**
   - Manifest [`gates/Architecture_M6_TB152_P13_Edge_Piece_Face_Side_Full_Gate_Case_Manifest.tsv`](gates/Architecture_M6_TB152_P13_Edge_Piece_Face_Side_Full_Gate_Case_Manifest.tsv), SHA-256 `cab375d014112b6ab48fe468003b9a57b2918a717e6f56e7478f0417362c0204`. It is the TB151 manifest as an exact byte prefix plus row 967: 967 + 81 deferred, membership 1048.
   - STOP on failure:
     - row 967 PASS;
     - rows 1–966 MATCH TB151 under N1–N3, with receipt lines compared raw;
     - 491/491;
     - no compile, relink, configure or benchmark.
   - **No census:** the function has no production caller (RA-242). The TB must show this by `grep` in its report.
3. **`TB152-REV` freezes, each as an exact patch:**
   - the thin O49 wiring in `build_source_face_ownership`: read `exact_trace_segment_pieces`; for an edge-only segment, F stays out of `traceCutFaces`, F and the face across get their sides from `edge_piece_face_side`, and the other owners are skipped;
   - the row 686 piece oracle (test-only).
   No current fixture publishes an edge-only segment to the cut graph (TB141), so the wiring's correctness rests on the pure helper (RA-248), and its gate criterion is strict MATCH.

### S5 — Cutover obligations added

- **Before freezing the producer switch,** list from existing receipts which fixtures build a plan that contains a slide arc and reaches conformity. Expected: none.
  - The sphere fails at χ before its plan.
  - Cylinder and Vase have no slides.
  - BunnyRandom fails inside `build_arcs`.
  So conformity is expected census-neutral at the switch, but **not after the stop switch**: the sphere's first plan will carry real-piece conformity counts. That TB must check them on real pieces, not chords.
- **Before freezing the switch,** grep the accepted tests that assert chord shapes (RA-217).
- Counts enter the digest at the switch (RA-273 S2.3, unchanged).

**Disposition:** TB151 PASS upheld; stable 66/17/49, debt one, 81 deferred, CP2 491/491. No promotion. Successor `M6-CP3-CB168O-P13-EDGE-PIECE-FACE-SIDE-HELPER`.
