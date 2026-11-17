# RA-245 — independent TB126 mandatory-edge terminal correction Review (2026-11-17 UTC)

Canonical turn: `M6-CP3-TB126-P13-EDGE-TERMINAL-CORRECTION-FULL-GATE-REV`. Runtime-free Review; no successor executed. RA-244 §5 MISMATCH route.

## Situation

TB126 preserved 950 inherited PASS results and observed one new required-guard RED. This is **MISMATCH**, not a scoped MATCH, production success, or stable accepted-green loss. The independent verdict is an invalid test input for row 951. The new BunnyRandom terminal is a distinct non-stable P13-e observation; its causal predicate is unresolved.

## Background — immutable evidence and scope

| Evidence | Archive SHA-256 | Verified checksums | Result |
|---|---|---:|---|
| TB125 gate `14289730737` | `c1754245b4ecbde49ba9bbaf9103cbb7975fdb34d40cae57b4e25b7ac56061c8` | 1,908/1,908 | 950/950 PASS |
| TB125 census `14289927334` | `2f5a4b511d1fac710338acba368b3a892f05e5621eb5e0c89dcbb5143e3ff8d6` | 9/9 | 1 PASS, 2 RED |
| TB126 gate `14294372593` | `c13a0f5e29ab961a6c6d7a31c2883cfaafbdc577d5727f291eb127e9cc8ea55e` | 1,910/1,910 | 950 PASS / 1 RED |
| TB126 census `14294313207` | `79acdba05b737e6987a39d3908ce7bf3f9375f4c051b5c4a35566670b63eb95f` | 9/9 | 1 PASS, 2 RED |

GitHub runs [gate 44005423680](https://github.com/akashskypatel/Directional/actions/runs/44005423680) and [census 44005461405](https://github.com/akashskypatel/Directional/actions/runs/44005461405); CB144 package 14293047782, source `7b0668d432ccb187c5a2d856494064f0bcb2fb95`. Verified source snapshot `40cdd9f1014e912e788aec66491d33075c37f7b7`, run 44010615974, artifact 14295564054, outer SHA-256 `c6fdb3fdf80aa6122b14f48543a46705ffb9ddcbf9d42ffe2caaafd6fb38d115`, 5,577/5,577 checksums. GitHub compare CB144 source to snapshot gives ahead (20 commits), only docs/control paths; no code/test/build/selector drift. The snapshot's local Git baseline is synthetic (not a claim of actual history). No Directional binaries, tests, benchmarks, compiler, configure, or relink were run in this Review.

## Assessment — independent re-derivation

1. Verify all four outer digests, every listed result hash, raw-log hashes per ledger row, and execution boundaries. TB126 gate: 951 planned/executed, 0 skipped/missing/duplicate/abnormal, 1,032 membership including 81 deferred, postflight true, exit 90 (required control failed). Census: 3 executed, postflight true, exit 0. All 950 inherited substantive ledger fields equal TB125; elapsed-normalized raw logs differ only in rows 156/173/190/191/477/705, whose exact `M3_CP4AB_FRAGMENT_DIAG` multisets contain 4/4/8/4/4/8 matching records. Removing diagnostic records leaves identical meaningful logs. Zero gate inventory lines. No claim of byte-identical raw logs.
2. Re-hash the committed gate manifests: TB125 `9a112bd18c4f37248ae8c9fc2c942f9fd19cd67ca4a5236c13f5ed76f95a0290` is the byte prefix of TB126 `44d5a734a819a6d353bf3cb83254af86939e017dbd3a6dc3313d71f814ffdd1f`, plus exactly row 951 (`ra244:mandatory-edge-ordered-split`). Census manifest `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793`. First 491 and 497 gate rows with header hash `483f11016d1f51049921aed879c2b23f523d045efc1a2833889a12bb9852a038` and `0eacb53afdb677e6047af1ccdff5518e9706bcc942161b473449d182a65a6a94`; these are manifest prefixes, not new accepted selectors. The first 491 test names exactly match the concatenation of CP1 focused30, CP2 focused12 and selector449, re-hashed respectively `1e815443a03c7ef4a1b095e6ea973efa9c74bb0eae4e2f872510c97d057ea1d6`, `2aa57aac48ac8c41ea86ed459cdd1acd27eb17c8d3dbe1b4ac7b9c54c67374ed`, `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`.
3. Row951 log SHA-256 `a17f4092754d04dc2e20c79569911afc474460206e0928d2c9011382d8b18b01`, `std::get: wrong index for variant`. In `tests/FieldAlignedCurveNetworkTests.cpp:18588–18598,18650`, `cut(38,13,...)` calls `trace(38)`, using extent 16. `include/directional/authority/AuthorityIds.h:182–195` returns `IndexOutOfRange` for index >= extent; `DomainResult::value()` line 84 uses `std::get<T>` on the error alternative. This is a deterministic source-level fault matching the observed exception; no runtime stack was supplied. Earlier uncut/single inputs are in range, and the helpers check the alternative before `std::get`. The two-cut call cannot execute; later expectations (and later negative controls) cannot establish a PASS. The second occurrence of trace 38 in the expected values is also invalid until the extent is corrected.
4. Non-vacuity: keep node extent 16, set independent trace extent 39 (largest trace ID is 38), keep all identities and existing assertions. Expected chain sizes 1/2/3 and endpoint, positive exact interval, continuity, adjacent trace, sorted node assertions discriminate a missing split, reversed piece, and wrong trace association. Python rational calculation independently confirms the close pair differs by 1/1152921504606846976 = 2^-60 but maps to the same double; the three-piece and order assertions distinguish sorting by double. Equal parameters on distinct/same nodes, endpoint and shared-node controls demand exact typed failures; a premature generic rejection or exception is not a success. This guard tests the split; it does not independently exercise the middle-piece direction through the rotation consumer. Keep that RA-244 gap open.
5. Census: Cylinder PASS, 288 quads; Vase RED completion (189,462 trace segments, 26,817 arrangement cells, 67,750 internal completed quads); both normalized logs identical. BunnyRandom normalized logs differ in exactly three terminal-report lines, all prior receipts and four exact inventory lines equal TB125 (inventory SHA-256 `5b2e329e1483e2335e52ed4485885db15c1d803946ac482dcec85bb9af2dd144`). Two distinct cuts each on `(241,251)` traces 107/38 nodes 149/178 and `(251,278)` traces 92/41 nodes 184/162. Old first terminal `MandatoryEdgeTerminalOrderUnresolved` edge `(241,251)` is no longer the reported first rejection; new `RotationSystemInconsistent` / `CellularityNotEstablished`, face `(5,104,359)`, zero accepted output. This meets the narrow first-terminal progression checks, not C3 closure or proof of correct complete rotation. No `InvalidNetworkBinding`/`RotationEdgeRayEndpointDirectionUnavailable` on either listed edge in the terminal.
6. New terminal owner boundary: `SurfaceCutGraph.cpp:1011` calls `build_embedded_graph_topology`; `EmbeddedGraphTopology.cpp:2028–2069` builds cut-node bindings, arcs, rotations and face walks. The published face alone does not distinguish `TraceEventPositionInvalid`/`TraceEventPositionNodeConflict` (706/723), event node/locus failures (904/914/923), vertex trace face/port/secondary parameter failures (1545/1561/1576), or a same-rank vertex-ray collision (1844 onward). `SurfaceCutGraph.cpp:112,140` and `RemeshPipeline.cpp:465,531` carry subreason and event index, but `tests/SurfaceCellDesignAcceptanceTests.cpp:45–64` emits only selected locus fields, not those typed fields. Therefore no exact root cause, latent/introduced attribution, or fix is justified by the available raw logs. Use the existing typed fields in a later separate diagnostic-only turn if the corrected gate still reaches this terminal; do not relax guards, change geometry, or infer cause from face alone. The product split may have exposed a pre-existing defect or introduced one; both hypotheses remain open.

## Recommendation — exactly one next Code + Build turn

`M6-CP3-CB144B-P13-EDGE-TERMINAL-GUARD-EXTENT-CORRECTION`. CB144A is already reserved for orchestration under RA-244, so use CB144B for this semantic-test-only correction. [Frozen patch](Architecture_M6_CP3_CB144B_P13_Edge_Terminal_Guard_Extent_Exact.diff) SHA-256 `20aeaf0d6e999c12d634f7c505418628add662b4484fdfa6dddaa63c3b1ed4ae`, 19 lines; only `tests/FieldAlignedCurveNetworkTests.cpp` (+4/-3); source file SHA-256 preimage `417ef255e893af1cf46a736c99b5af1d593de97bf58559a47aa30088baaf1f89`, postimage `9160790d7e9830aee73bc6ce9094e277a49d5cff84036c74ac18b396db38b67e`. Static `git apply --check` against verified snapshot passed. No source edit is retained in this Review.

- Before build confirm exact CB144 behavioral source, test preimage, same selector/gate/census manifests, and approved single test path; apply exactly the frozen diff. No fixture, product, benchmark, policy, selector or assertion edits. Stop on any mismatch; do not improvise.
- Compile only via durable dispatcher, GMP/GMPXX, these eight targets: `directional_core`, `directional_pipeline`, `directional_surface_cell_authority_kernel_tests`, `directional_surface_cell_producer_tests`, `directional_surface_cell_completion_tests`, `directional_surface_cell_validation_tests`, `directional_compiled_api_tests`, `directional_benchmarks`. Verify exact source, target/link receipt, immutable package and every package hash; `runtimeExecution=false`. No runtime in CB144B. Stop and return to review on build/source scope mismatch; retry only legitimate transport/orchestration failures.
- Conditional later TB (not authorized to start now): run only the corrected immutable package, same 951-row gate and unchanged three-case census. Require 951/951 PASS, zero skip, membership 1,032 and valid postflight; compare all inherited gate rows and substantive raw logs to TB126/TB125. Preserve row951 full assertions; any exception, typed mismatch, or new semantic difference is a MISMATCH and returns to independent Review. Require normalized census receipts and terminal reports identical to TB126 because behavior source is unchanged; any unexpected change requires independent review. On MATCH, separately review C3 and the new terminal, then consider existing typed-locus diagnostic publication. Do not automatically promote or start CB145. The next turn only is CB144B.

Carry: C3/O42/O43 open, O44/C1 closed; D11=A, D12=A, D10 deferred, D6 pending; C4/CB145 parked; stable 66/17/49, debt1, deferred81. CP2 491/491 accepted package `11391685901` / source `5ce3132ec01748eff5b15f82be07a1abe2bd1af6`; CP3/selector497 unpromoted; `chainRimSchedules=false`; PR #8 draft/unmerged.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | Gate 950 byte-prefix and 491/497 manifest prefixes verified above; no accepted selector changed. |
| Decisive claims independently re-derived | Four archives, internal/ledger-log hashes, prefix, exact diagnostic multisets, counts, static test exception, census progression. |
| Non-vacuity checked | Exact positive chain and typed negative controls examined; row951 stopped before intended witness. Existing Lessons: negative must reach intended guard on a valid baseline. |
| Prior obligations discharged/carried | TB126 adjudicated MISMATCH; C3/O42/O43 and rotation-direction runtime proof carried; O44/C1 remain closed; C4/CB145 parked. |
| Stable accounting | 66/17/49, debt1, deferred81; CP2 package 11391685901 / 491; CP3/497 unpromoted. |
| New candidates/obligations recorded | Test witness defect and separate rotation terminal (non-stable); tracker updated. |
| ORIENTATION currency line | RA-245 canonical turn/date updated. |
| ORIENTATION §3 / §4 / §7 / §8 | Current state, witnesses, priorities and typed-ID pattern updated. |
| CHANGELOG | Entry added. |
| ROADMAP | Current CP3 state updated; no milestone closure. |
| Selector manifest | n/a: no selector added or promoted. |
| LESSONS | Existing witness/valid-baseline lesson applies; no duplicate lesson. |
| Consolidation under CLEAN_UP_POLICY | Continuation folds 71 superseded CB/TB records and the retired continuation note into [Volume D3](M6_Consolidated_Record_Vol_D3_CP3_P13_from_20261109.md); master index includes exact names, original line counts and per-file hashes. Preserves original handoff/orientation preimages as history, updates live references and current navigation. RA-244, CB144, TB125/TB126, normative definitions, frozen exact diffs and selectors retained. Compare RA-244 base `027ab8b4d72320181f7cba81e68205381e510992` to snapshot found zero net retired paths; transient add/remove history not established by compare. |
| Successor frozen | CB144B only; exact diff, scope and falsifiers above. |
| Turn boundary held | Runtime-free; no product, test, fixture, build, selector or benchmark mutation in prepared documentation patch. |
| review_check.py boundary | Local boundary: code/selector checks PASS; historical Git baseline checks FAIL because source snapshot has no Git history. Separately GitHub compare proves `8b7299b43764a6ba3444e5bc774a2f1b65e99731` ancestor of snapshot; exact baseline documents obtained via GitHub show all 4 protected handoff headings and 1 orientation heading preserved; tracker has no protected heading. No fabricated full script PASS. |
| `STATUS` lifecycle maintained | Entry and resume direct. Started 2026-11-17T03:29:09Z; resumed 2026-11-17T03:51:49Z; final beacon only after verification. |
| Pushed to origin, branch in sync | RA-245 initial publication confirmed at `03131fd4136b5faab40b8117332211127dcf805a`; run 44011923494, job 133800903930, result/log 14297545438/14296144882, patch SHA-256 `b895034b133c4f380ec984dc060186e9008f171ec21e264a2c8bd6ec23b293db`. Drive staging deletion confirmed. Cleanup run 44012148606, commit `3226b2ca012eeb18a858da382bdc8eeca2f8af6f`, result/log 14296323812/14297301143 verified. Continuation patch publication requires independent result verification before final STATUS; local snapshot has no real origin. |

Process limitations: Snapshot pre-read order was violated on initial direct handoff/policy inspection and two incorrect STATUS.md lookups returned 404; corrected by verified snapshot and comparison. Timer was started approximately two minutes late; earlier actual 20-minute limit controls. Exact tool-call ledger not retained after context compaction; do not invent counts.

Continuation snapshot: `6ef77580617731bc2d5e364b924c706ad9bb0b34`, run 44013231485, job 133805053077, artifact 14297377278, outer SHA-256 `a15f0ff45d64655463de4aaef8b637e41920d66faec91f8ef37ffef87c1a8997`, inner SHA-256 `9cc8fe4e99e20efe80ec9e255735f0c34b39929f03b240c32ff4f07350089b54`, 5,580/5,580 checksums. Runtime=false. The original continuation note is preserved in [Volume D3](M6_Consolidated_Record_Vol_D3_CP3_P13_from_20261109.md#architecture_m6_cp3_tb126_review_closeout_continuation_20261117md); never replay its old duties after final closeout.

Continuation local verification: 74 complete archived bodies and original hashes verified against the snapshot (72 folded files, two navigation preimages); 173 live references redirected, including three previously broken root-relative references. Document drift audit: zero errors, three protected-document change warnings (authorized Review maintenance under CLEAN_UP_POLICY/REVIEW_TURN_POLICY; all protected headings preserved). Local boundary re-run: product/test/fixture/build and selector checks PASS; four historical-object checks remain unavailable in the synthetic repository as above. All changed paths are Markdown; frozen successor patch unchanged. No runtime or successor execution.

## Owner-requested adversarial re-review (RA-246, 2026-11-17 UTC)

The owner asked for a critical re-review of this turn. It stays runtime-free: two Haiku agents re-downloaded the artifacts, and the source checks were `-fsyntax-only` and reading code.

### 1. What RA-245 got right (re-verified)

- **Archives.** The ZIP SHA-256 of TB125 gate, TB126 gate, TB125 census and TB126 census all match. Checksums: TB125 gate 1,908/1,908 OK, TB126 gate 1,910/1,910 OK.
- **Gate rows 1–950.** All 11 ledger fields, excluding the log hash, are identical to TB125; 0 cells differ.
  - Six raw logs differ: rows 156, 173, 190, 191, 477 and 705.
  - In each, the text is identical once newlines are removed, and the `M3_CP4AB_FRAGMENT_DIAG` marker counts are equal (4/4/8/4/4/8). One side joins two records on one line followed by a blank line. This is the known concurrent-`std::cerr` framing (RA-243), nothing more.
- **Row 951.** The log is `std::get: wrong index for variant`, and the cause is `trace(38)` built with extent 16.
- **The CB144B fix is sufficient.**
  - After it, every index is in range: nodes {0,1,7,8,9,10,11,12,13} < 16, traces {2,3,4,5,6,9,10,38} < 39.
  - I traced every assertion of the test against `split_mandatory_edge_at_terminals` as committed. Every one holds:
    - chains of 1, 2 and 3 pieces;
    - the 1/3 versus 1/3 + 2⁻⁶⁰ pair, which rounds to the same double either way;
    - `EqualParameters`(5, 6), including when both cuts share node 10, where the equality check fires before the shared-node check;
    - `TerminalAtEndpoint`(9);
    - `SharedNode`(9).
  - So CB144B should give PASS, not a second MISMATCH.
  - CB144B still applies at HEAD; `src include tests` has not changed since CB144 `7b0668d43`.
- **Correction of my own record.** The row-951 defect is mine. RA-244 froze the test and called it non-vacuous, but `-fsyntax-only` cannot see a runtime extent contract, and I never checked the `from_index` extents against the IDs used. See the new lesson in LESSONS.md.

### 2. Where RA-245 is wrong or incomplete

**F1. The turn sequence had no reachable exit.**
- Step 2 of the handoff sequence was `UNKNOWN`, and it said "no additional turn is authorized".
- So after CB144B the implementation agent had no canonical turn to run, which breaks RA-172.
- Fixed below: TB127 and the outcome Review now have IDs.

**F2. The planned follow-up TB would have learned nothing about BunnyRandom.**
- RA-245's TB re-runs the census and requires it to be *identical* to TB126, because product source is unchanged.
- That run cannot tell us anything new about the blocker. Only after it would a separate diagnostic CB and TB print the subreason: two full CB→TB→Review cycles to reach one fact.
- Per RA-235/RA-242: the typed fields already exist in `RemeshResult::diagnostics.terminalFailureLocus`, filled by `project_surface_cut_graph_failure_locus` (`RemeshPipeline.cpp:390–548`).
  - That includes `rotationSystemInconsistencyReason`, `sourceVertex`, `trace`, `arc`, `traceEventIndex`, both rays and the fan census.
  - Only the census formatter `failure_locus` (`tests/SurfaceCellDesignAcceptanceTests.cpp:45–68`) drops them.
- Printing them is a test-only change. Its message is only built when the assertion at `:434` fails, so it is gate-neutral: the gate rows that run this test PASS.
- It belongs in the same TB as the CB144B fix.

**F3. "Introduced vs pre-existing" can be narrowed now, from source.** RA-245 left both open. The printed locus has a face and no edge (`locus face=(5,104,359) history=0`), and that already excludes most failure sites:
- **Every edge-locus site sets `sourceEdge`, which would print.** These are `EdgeTraceFaceSideInvalid` (`:1790`), `EdgeTraceSecondaryRankInvalid` (`:1805`), `RotationEdge*`, and `RotationEdgeRayEndpointDirectionUnavailable` (`:1788` area).
- **Face-walk and Euler failures carry no face.**
- **The sites that can print a face with no edge** are:
  - `TraceEventPositionInvalid`/`TraceEventPositionNodeConflict` on a face or vertex event (`:706`/`:723`);
  - `EventNodeLocusMissing` with no event edge (`:904`);
  - `EventLocusMissingSourceEdge` (`:914`);
  - the vertex-locus trace failures (`:1545`/`:1561`/`:1576`);
  - the vertex trace same-rank collision (`:1862`).
- **CB144 changed only two things:** the Mandatory drafts in `build_arcs`, and the Mandatory branch of `edge_ray_points_to_second_endpoint`.
  - The direction helper is read only for edge-locus Mandatory/Cut rays.
  - None of the face-only sites reads a Mandatory draft's interval or direction. Trace-event positions, locus registration and trace-ray vertex keys all come from network events and traces. The collision is between two Trace rays.
- **Conclusion:** CB144 cannot be the direct rejecting cause. BunnyRandom never reached any code after `build_arcs` before CB144, so this is a pre-existing defect that CB144 exposed.
- **Two caveats:**
  - The direction rule's correctness at runtime is still unproven (the RA-244 gap). A wrong but non-failing direction would show up later, in the face walk.
  - The exact site is still unknown, which is what CB146 measures.
- **So C3's own predicate is met.** The `build_arcs` multi-cut rejection is gone, and BunnyRandom does not fail at `InvalidNetworkBinding` or `RotationEdgeRayEndpointDirectionUnavailable` on either split edge.
  - C3 closes at TB127 MATCH, together with the green row 951.
  - The rotation terminal is a new non-stable candidate, **C5**, owned at A2a′/rotation.

**F4. Process items for the record (not design defects).**
- RA-245's closeout has lines about Drive staging, timers and missing tool-call ledgers. I took no action on them.
- The record's "exact multisets … matching records" holds only after newline normalization; the strict per-line multisets differ. That is harmless, but the statement should be read that way.

### 3. Realigned sequence

| # | Turn | Owner | Status |
|---|---|---|---|
| 1 | `M6-CP3-TB126-P13-EDGE-TERMINAL-CORRECTION-FULL-GATE-REV` (RA-245 + RA-246) | Review | COMPLETE |
| 2 | `M6-CP3-CB144B-P13-EDGE-TERMINAL-GUARD-EXTENT-CORRECTION` | Code + Build (compile only, exact diff, unchanged) | NEXT |
| 3 | `M6-CP3-CB146-P13-ROTATION-TERMINAL-LOCUS-PRINT` | Code + Build (compile only, exact diff, test-only) | then |
| 4 | `M6-CP3-TB127-P13-GUARD-AND-ROTATION-LOCUS-FULL-GATE-EXEC` | Test + Benchmark (artifact only) | then |
| 5 | `M6-CP3-DEFN-P13-EDGE-TERMINAL-CORRECTION-OUTCOME` | Review: close C3, classify C5, freeze the next CB | then |
| parked | `M6-CP3-CB145-P13-VERTEX-FOLLOW-BOUNDARY` | Code + Build | after 5 |

RA-245 named no routes for CB144B, so they are set here: mismatch → `M6-CP3-PLAN-P13-EDGE-TERMINAL-GUARD-EXTENT-STOP`, infrastructure failure → `M6-CP3-CB144BA-P13-EDGE-TERMINAL-GUARD-EXTENT-ORCH`. CB144B's own scope and diff are unchanged.

Each turn can be tested on its own. CB144B and CB146 touch different files and apply in either order (both orders checked). CB146's package contains both, so TB127 runs one package. No Review turn is added.

### 4. CB146 frozen

**Patch:** `Architecture_M6_CP3_CB146_P13_Rotation_Terminal_Locus_Print_Exact.diff`.
- SHA-256 `4f1fae63d0d3f2626f02c4f27d26a923e0a525173112556fefe50d9e5be56967`.
- 72 lines.
- Numstat `61 0 tests/SurfaceCellDesignAcceptanceTests.cpp`. Blob preimage `302ce62d`, postimage `c7108034`.

**Content:** `failure_locus` appends, after the existing ` history=N`, each locus field that is present:
- ` vertex=`, ` rotationReason=`, ` vertexSecondaryReason=`, ` edgeSecondaryReason=`;
- ` trace=`, ` secondTrace=`, ` arc=`, ` secondArc=`;
- ` eventIndex=`, ` eventPositionReason=`, ` eventPositionPass=`;
- ` previousRay=[…]`, ` currentRay=[…]`;
- ` fanRays=N[+truncated]`, followed by each ` fanRay=[kind arc trace orientation primary secondary face fanSlot]`.

Every earlier field and its order is unchanged, so every TB126 terminal line must stay an exact prefix.

**Verification:**
- `git apply --check` passes at HEAD, alone and stacked with CB144B in either order.
- `-fsyntax-only -Wall -Wextra -DUSE_GMP_ENABLED` returns 0, with 27 warnings, the same set as HEAD.

**Do not:** touch product or other test files, add fields the locus does not already publish, or run anything.

**Routes:**
- Mismatch → `M6-CP3-PLAN-P13-ROTATION-TERMINAL-LOCUS-PRINT-STOP`.
- Infrastructure failure → `M6-CP3-CB146A-P13-ROTATION-TERMINAL-LOCUS-PRINT-ORCH`.

The package is the eight RA-245 targets, built from CB144B + CB146 source.

### 5. TB127 frozen

**Package:** the CB146 package. **Gate manifest:** TB126's `44d5a734…` unchanged (951 rows, membership 1,032). **Census:** `3af1dc0d…` unchanged.

**MATCH requires all of the following.**

Gate:
- 951/951 PASS, 0 skipped, valid postflight.
- Rows 1–950: ledger fields identical to TB126. Raw logs may differ only in elapsed time and the newline framing of `M3_CP4AB_FRAGMENT_DIAG` (newline-free text equal).
- Row 951 PASS, with no exception text.
- No inventory line in the gate.

Census, for every case:
- Every line is identical to TB126 after normalizing ms timings and gtest `GetParam()` byte dumps, except the `terminal=` line.
- On the `terminal=` line, TB126's text must be an exact prefix of TB127's.
- Cylinder PASS, 288 quads.
- Vase RED, with an unchanged prefix.
- BunnyRandom RED, with an unchanged prefix (`origin=RotationSystemInconsistent … locus face=(5,104,359) history=0`), the same four inventory lines, and a non-empty ` rotationReason=` suffix.
  - If the reason is missing, the projection is losing fields: MISMATCH.

**Record, without deciding MATCH:** the BunnyRandom suffix, verbatim.

**Prediction (pre-registered from §2 F3):** the reason is one of the face-only reasons:
- `TraceEventPositionInvalid`, `TraceEventPositionNodeConflict`;
- `EventNodeLocusMissing`, `EventLocusMissingSourceEdge`;
- `VertexTraceFaceMissingFromFan`, `VertexTracePortOrdinalInvalid`, `VertexTraceSecondaryParameterUnavailable`;
- a vertex trace collision reason.

An edge-locus reason would falsify F3, and the outcome Review must then reopen CB144's direction rule first.

**Routes:**
- Mismatch → `M6-CP3-TB127-P13-GUARD-AND-ROTATION-LOCUS-FULL-GATE-REV`.
- Infrastructure failure → `M6-CP3-TB127A-P13-GUARD-AND-ROTATION-LOCUS-FULL-GATE-ORCH`.
- MATCH → Review-only `M6-CP3-DEFN-P13-EDGE-TERMINAL-CORRECTION-OUTCOME`.

### 6. Work for the outcome Review (no runtime in it)

- Close C3 on the two pieces of evidence above.
- Classify C5 by the printed reason. Join the printed trace, vertex or event with the four terminal traces (107, 38, 92, 41), nodes (149, 178, 184, 162) and vertices (241, 251, 278), and read the owning predicate.
- Freeze the next narrow CB at the owning stage, with a unit test that reaches the rejecting predicate.
- Separately, freeze a rotation-level test of the middle-piece direction (the RA-244 gap). This becomes urgent if BunnyRandom's next terminal is a face walk.

**Carried:**
- Open: O42, O43, C3 (until TB127), and C5 (new, non-stable).
- Closed: O44, C1.
- Decisions: D11 = A, D12 = A, D10 deferred, D6 pending.
- Counts: stable 66/17/49, debt 1, deferred 81; CP2 491/491.
- CP3/selector497 unpromoted; `chainRimSchedules=false`.
- DESIGN.md unchanged.
