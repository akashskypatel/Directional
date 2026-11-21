# TB150 independent full-gate Review — RA-272 (2026-11-20 UTC)

## Situation — decision

**PASS, with the existing production restriction.** The independently reopened immutable TB150 gate gives **964/964 PASS**, accepted CP2 prefix **491/491 PASS**, and **963/963 MATCH** against TB149 under the previously authorized N1–N3 transformations. Its independent direct census gives **3/3 MATCH** against TB149 under N1–N4: Cylinder PASS; BunnyRandom and Vase RED at `SurfaceCellDesignAcceptanceTests.cpp:493`. The decision closes the TB150 comparison gate, **not M6-CP3, H4, selector497, D0, or sphere topology**. No product, test, selector, fixture, build or runtime change was made in this Review.

## Background — primary evidence reopened

| Input | Independent verification |
|---|---|
| Exact semantic source | `041bde764365710e6d5148c43751da91205ffd35` (CB168L), recorded independently in both TB150 result boundaries; immutable binary package `14608341511` |
| Source archive | Snapshot `14608653925`, run `44692186639`, source `19ca58bf84f7e31271b078dd135c6b2bf8609636`; ZIP SHA-256 `8ecc4290e8cd9c985e516c4683c9361877f449ac4da542d2cda5203b3d1429df`, **5631/5631** content checks |
| TB150 gate | Run `44692445950`, artifact `14609657696`, ZIP SHA-256 `9e2117dc4bf4d5e097beeaa90236b1c44ceafdba90bc3fd4751ef2cd2472874f`, **1936/1936** internal hashes |
| TB149 gate baseline | Artifact `14604413703`, ZIP SHA-256 `b9d0ff8746070c2d0928f8ac0647aa5bc0f5add542691b51932a6d85c0c1a621`, **1934/1934** internal hashes |
| TB150 census | Run `44692570324`, artifact `14610319026`, ZIP SHA-256 `b5033d6939a14ce8716455f5dd5f6f20d15087b2ae229c8c646c96052c68225c`, **9/9** internal hashes |
| TB149 census baseline | Artifact `14606235652`, ZIP SHA-256 `20534de76bd51ffa22bd5cb478b869adb760959139ef025cbf0e53cc531a5f94`, **9/9** internal hashes |
| Frozen TB150 manifest | SHA-256 `bce554e6723dfaa77f54d070aab7edc6508cd3aaf69a6120871e21b349b78926`; 964 cases, membership 1045 |
| Prior 963-case manifest | SHA-256 `4350378c95fefeb0dbab6e742b50dcd976af406f865ddef45cc03b35f7b4c01c`; **exact byte prefix** of the 964-case manifest |

The archive verifier checked each ZIP's SHA-256 and then each indexed file hash independently. A first verification attempt checked source entries before extraction and incorrectly reported them absent; the corrected complete verification subsequently passed 5631/5631. The preliminary negative-control script failed from a local `.encode()` typo; the corrected full script completed all controls. Neither mistake changed source, records, or result artifacts.

## Assessment — independently re-derived results

1. **Gate membership and control:** the TSV has 964 unique required rows; result `planned=executed=passed=964`, `red=abnormal=missing=skipped=duplicate=control_bad=unexpected_pass=0`, `postflight=true`, `exit=0`. The first 491 accepted-prefix rows all PASS. New row 964 `ra271:slide-interior-cut-position` passes; retained row 960 `ra262:trace-piece-path-helper` passes. Binary/source/package IDs match the immutable CB168L authority. Both result boundaries say `compile=false`, `relink=false`, `configure=false`, `benchmark=false`.
2. **Prior-gate comparison:** the older 963 ledger rows match the TB149 ledger fields apart from raw-log hashes. Each of the 963 independently loaded raw logs matches after N1 elapsed Google Test duration removal, N2 line-ending normalization and N3 a counted multiset of **complete** M3 `region_support_projection` records (**1,738** such records) with all remaining lines ordered. No other line or field was suppressed; **963/963 MATCH**.
3. **Slide receipts:** all **504** `FieldAlignedCurveNetwork.slideContactArrival` records remain present and equal under the comparison: 126 each for `17:8/0:6`, `20:8/1:6`, `5:8/21:6`, `8:8/22:6`. Each has `wallCommitted=1 movingArrival=later`. The comparison did not remove or normalize these lines. They are observations, not cut-graph events.
4. **Census:** three independent processes, 1 PASS and 2 expected RED, no abnormal/missing/skipped/duplicate/control errors, `postflight=true`, `exit=0`. N4 removes only the two 16-byte ASLR `GetParam()` address payloads in **each** of the two parameterized RED logs (four occurrences); all other records stay ordered. **3/3 MATCH**, both REDs remain at `SurfaceCellDesignAcceptanceTests.cpp:493`.
5. **Non-vacuity:** the new slide-cut test asserts a strict interior point in a reversed slide, two cuts, parameter bounds, a valid edge piece before and after, and rejected invalid loci; it also verifies that the old face-chord path cannot cut that interior point. As independent comparator controls, deletion or duplication of one slide receipt, modification of `chi=6`, modification of census failure site `:493`, and modification of the `GetParam` label each yield a mismatch. The new row therefore verifies an unwired helper but **not** production wiring.
6. **Unresolved output:** sphere row686 remains `V=18 E=30 F=18`, giving `chi=6`, versus source `chi=2`, excess **+4**; rows669/698 still return `CutSearchExhaustedBeforeCellularity`. `EmbeddedGraphTopology::build_arcs` still uses `exact_trace_path_between` (face chord), not the real slide piece path. The four slide contacts do not become graph nodes. No production repair is proven by TB150.

**Stable accounting:** 66 events / 17 categories / 49 recurrences; one produced-witness debt; 81 deferred. O47/C5 and related graph obligations remain open; O48 and O49 remain governed by prior review authority. CP2 accepted 491/491; CP3 selector497, D0, row858 and representative production gates are not promoted. No new stable regression is established.

## Recommendation — freeze exactly one Code + Build successor

**`M6-CP3-CB168M-P13-SOURCE-PIECE-COUNTS-BINDING`**, compile-only; detailed frozen specification: `Architecture_M6_CP3_CB168M_P13_Source_Piece_Counts_Binding_Plan_20261120.md`. Implement only the previously approved EPO-3 representation and exact validator, with an all-ones producer to keep current face-chord geometry byte-identical. Freeze its separate artifact-only **`M6-CP3-TB151-P13-SOURCE-PIECE-COUNTS-FULL-GATE-EXEC`** as the successor's gate (not executed by this Review). Do not combine this with EPO-2 producer conversion, CB169/H4, O49, row686 oracle rewrite, stop switch, tracing changes, repair or acceptance promotion. The exact falsifiers and stop conditions are in the successor plan.

## Procedure and scope notes

The Review first inspected several repository files before completing the required snapshot-first read-mode gate. This violated the documented ordering; it is **not** corrected retroactively. The agent then used one verified exact source snapshot for code and local evidence inspection. No compiled Directional binary was executed; the independent analysis used Python on archived results only.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | TB150 first 963 manifest rows are byte-identical to prior 963-case manifest, SHA-256 `4350378c95fefeb0dbab6e742b50dcd976af406f865ddef45cc03b35f7b4c01c`. Accepted CP2 491 rows PASS; no selector was changed. |
| Decisive claims independently re-derived | Five ZIP digests; manifest rows; 964/964 ledger; 963/963 raw normalized logs; 504 slide receipts; 3/3 census; `18-30+18=6`. |
| Non-vacuity checked | Five independently injected comparator mutations fail equality; positive/negative slide-cut helper assertions examined. |
| Prior obligations discharged/carried | TB150 N1–N4 comparison discharged; EPO-3 and CB169 carried; O47/C5, O48, O49, +4 sphere topology, debt 1 and 81 deferred carried. |
| Stable accounting | 66/17/49, debt 1, accepted CP2 491/491, selector497 not promoted. |
| New candidates/obligations recorded | No new stable candidate; existing O47/C5 and EPO-3 carried. |
| ORIENTATION currency line | TB150 Review authority and count updated. |
| ORIENTATION §3 / §4 / §7 / §8 | §3 and §7 updated; §4 unchanged because no witness moved; §8 unchanged because no new defect class was established. |
| CHANGELOG | TB150 Review entry added. |
| ROADMAP | No checkpoint change; CP3 remains open. |
| Selector manifest | No selector admission/change; no edit. |
| LESSONS | Existing `LESSONS.md` evidence and producer-ownership rules apply; no new reusable rule. |
| Consolidation under CLEAN_UP_POLICY | TB150 execution and CB168L evidence retained in their named records because this review directly depends on them; no deletion until all references and durable homes can be independently checked. |
| Successor frozen | One Code + Build turn in the plan; separate TB defined but not started. |
| Turn boundary held | Review only; no code, test, fixture, selector, benchmark or build mutation; no Directional runtime. |
| review_check.py boundary | Ran against extracted source: inconclusive/FAIL because the snapshot has no Git history or rewrite-base commit `8b7299b43`. A separate six-path documentation-only diff, `git diff --check`, patch-apply preflight, and 5,633 source-content hashes passed. |
| `STATUS` lifecycle maintained | Entry beacon published; final beacon after all other repository writes. |
| Pushed to origin, branch in sync | The remote Drive apply workflow completed successfully at commit `36d73c6110a4098ef27b2f1169a01799e0aca97d`; no local `git status -sb` is possible in the source archive. Final remote ref must be verified before STATUS closeout. |

## RA-273 — adversarial re-review of this Review (2026-11-20 UTC)

**Verdict: TB150 PASS upheld; the successor is withdrawn and re-frozen as two exact patches.** The section above is labelled RA-272; this re-review is RA-273.

### S1 — Evidence, independently re-derived

A read-only Haiku sub-agent downloaded the four archives in isolation.
- **Archive integrity:** all four ZIP SHA-256 values equal the recorded ones. Index checks: 1936/1936, 1934/1934, 9/9 and 9/9.
- **Gate comparison:** rows 1–963 MATCH TB149 under N1–N3, 963/963. There are 1,738 M3 records, and all 504 `slideContactArrival` lines were compared raw. Rows 960 and 964 PASS, and so do rows 1–491.
- **Census comparison:** 3/3 MATCH under N1–N4. The masked `GetParam` bytes really differ, so N4 is doing work.
- **Negative controls:** a removed receipt, a duplicated M3 record, a changed non-M3 byte and a changed byte outside the census mask each give MISMATCH.
- **Row 686:** the sphere reads `V=18 E=30 F=18 chi=6 sourceChi=2`. Rows 669 and 698 each still print `CutSearchExhaustedBeforeCellularity`.

The evidence claims above are accurate.

### S2 — Design defects in the frozen successor (CB168M plan, prose version)

1. **No exact patch.** The plan leaves the Review's own decisions to the implementation agent: "define the existing mandatory/cut arc contract", "inspect every reader", "ambiguous use … must be classified before implementation". RA-261 forbids a prose CB, and RA-271 S5 required "the exact EPO-3 binding CB".
2. **Its required positive is unreachable.** Item 6 demands an accepted two-piece segment. But `make_from_candidate` replays every candidate against the producer (`candidate.arcs != wanted.arcs`, `GlobalTopologyPlan.cpp:2953`), and the producer stays all-ones. So any two-piece candidate is rejected, and the plan names no test seam. The test could not be written honestly.
3. **The digest rule contradicts its own TB criterion.** Item 5 adds the counts to `candidate_semantic_digest`.
   - The census `platform-digest` line prints `global-topology-plan=` (that digest, `RemeshPipeline.cpp:13008`) and `global-conformity-baseline=` (which hashes it, `GlobalConformityBaseline.cpp:255`). The tracing hash also embeds `receipt.topologyPlanDigest` (`RemeshPipeline.cpp:2094`).
   - Cylinder builds a plan, so its census line would change, and TB151's own "census 3/3 MATCH TB150" would STOP.
   - **Ruling:** do not hash the counts while they are all-ones. Every plan that passes `make_from_candidate` has `sourcePieceCounts == ones(sourceFaces.size())`, and the digest already commits to `sourceFaces`, so no identity is lost. The cutover CB, where counts first carry information, **must** add them to the digest. That is a frozen obligation.
4. **One monolithic turn.** The plan put field, validator, producer, digest and tests in a single turn. It is now split into an unwired helper (CB168M) and its wiring (CB168N).

### S3 — Frozen exact successors

The [CB168M/CB168N/TB151 plan](Architecture_M6_CP3_CB168M_P13_Source_Piece_Counts_Binding_Plan_20261120.md) replaces the prose version.
- **CB168M (unwired):** a pure `source_piece_binding_failure(faces, counts, path)`, plus `pieceCounts` output from `exact_trace_piece_path_between`. Both come from one decomposition (EPO-2).
- **CB168N:** the field, the all-ones producer, the validator wired in place of the 1:1 rule, and the non-trace-arc emptiness check. No digest change.
- **TB151:** strict MATCH, with rows 965 and 966 added.

### S4 — Obligations carried to the cutover

These are inputs for the TB151 Review, which freezes the cutover split. Readers of arc `sourcePath`/`sourceFaces` outside the validator:
- `SurfaceCellTracing.cpp`: `bound_arc_schedule` :14237, `edge_arc_schedule` :14286, the phase-front builders :17097 / :19764 / :20237;
- `SurfaceCutGraph.cpp` `build_source_face_ownership`;
- `GlobalConformityBaselineSupport.cpp` :530 / :617;
- `EmbeddedGraphTopology.cpp` `actual_complement_component_count` :3366.

Each must be classified as traversal or geometry (EPO-1) before real pieces are published. The cutover must also hash `sourcePieceCounts` (S2.3).
