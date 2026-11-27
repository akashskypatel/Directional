# TB-REV-188 — independent activated test gate and completion input review (2026-11-27 UTC)

## Situation

The activated test gate is independently accepted at **1006/1006**. This is test-gate evidence, not global activation safety or production acceptance. The separate V5 census is not accepted: BunnyRandom timed out. Sphere row858 remains a correct negative display test and reaches completion. The first rejecting boundary predicate is now known; the repeated node must already be present in the completion input. Its precise cell and source producer are not measured. No product, test, fixture, selector, benchmark, or build source was changed and no Directional binary was executed during Review.

## Background — independent authority

The [execution report](Architecture_M6_CP3_TB188_Completion_Receipt_Activated_Full_Gate_Execution_Report_20261127.md), [frozen contract](gates/Architecture_M6_CP3_CB210_TB188_Completion_Receipt_Activated_Full_Gate_Exact_Manifest.md), prior [TB-REV-186](Architecture_M6_CP3_TB_REV_186_P13_Activated_Sphere_Full_Gate_Independent_Review_20261126.md), and its adversarial AA1/AA2 control the review. Verified current source snapshot run 45927446195, job 140272087910, artifact 15167490570, outer SHA-256 `78fdb67899f95fea33008682b9101d2af2394eeab806ec8e2047400b06921651`, internal archive `dd62980809051e5bff99b6a72cba7f4e1e822f70aa56f32af1130465ad10c34d`, 5868/5868 file checks, source `24292271972f02d2f98ceba59aed2cba1e6d49d7`. GitHub compare from tested source shows 26 commits ahead, zero behind, 12 changed paths, only documents and control state; no code, fixture, harness, selector or build drift. PR #8 draft/open, branch `agent/surface_cell_quad/p5-recover-bridge-healing`.

| Immutable input | Artifact | SHA-256 (ZIP) | Checks |
|---|---:|---|---:|
| CB-210 source `0409304d6f9f423685ccddc26b19baf4e41ea61e`, compile 45916449585 | 15162357312 | `9aa9f28b3830275c6eb6b1bb712126094976e9556abcfe61d7921b2ed91bd74a` | 28/28 |
| TB188 full | 15163822727 | `59957c5adbb95a5e5a90f1eada11f3aec60366ee3a8c22694edf8de799293780` | 2020/2020 |
| TB186 | 15155787349 | `ee1e603907561d773034c9e48fd76fa2d1e8fe6273ace85f9425f5bf557f76fa` | 2020/2020 |
| TB185V | 15066180913 | `16983f7e40ac9f5934b3a50ffd556925d582e857e41aaf34aae8f5fb3b181082` | 2020/2020 |
| TB187Q | 15130286146 | `a3fb3a89a3dd72ccc2870412fd0d6e78af4921943d7f491c4735443264de8ecc` | 2020/2020 |
| TB188 V5 | 15165185584 | `088d7ba4f2b0daee8c7eaeb14479052d77796affa9d2c30d180b2810c4a2cacb` | 9/9 |
| TB161 V5 prior | 14741883606 | `cc3f200101168f5fd3ff1e0e0dca986adb750dcd7e107a0b03ecc786b4d50b59` | 9/9 |

The compiled source archive and package inventory verify; eight GMP/GMPXX targets, clean source status and `runtimeExecution=false` for compile. Full gate mailbox `m6-cp3-tb188-exec` source and event `7695f7af26e9de6dccbd928f614c4be5e86310a9`, run 45918483650, request `3b737fc286a11be86226045124c728a33f671e886be5930cd68432b01284fd42`, attempt1. V5 mailbox `m6-cp3-tb188-v5`, event `27723a4547b3bddd95fa5fd00b369278abb07228`, run 45920872749, request `0f5769d89b0881ea8ad2fb09aece6872f636fff3b74407bad7b7f8c8e0ec38b1`, attempt1. Both wrapper logs match exact source, executor `cc25a6402cdd3ca1a33a9a9778250176b182bb2a`, harness `423f385b73c3825ce9fe18fbd5ca395287620475deb621389f0efbaa601e572c` and exit0. Independent outer checks for all four logs: full harness 15163812600 `608a3c0a707d5a79de64e1037e41ac021a8d575d296300048bb9b40e4ff99c52`, wrapper 15163847561 `117962b98fe9b24253509bc5c9fc5287e96f920c04480881f4ac2efc77d0123e`; V5 harness 15164960868 `d8e1ec8c632f741b771f4a7fc1766dbea2b662d317fbf83a8d0e112cefcc19fa`, wrapper 15165690015 `e4ca91ca1e8dcaae83e02bc90794f4f1f1508b9cb2db54a90d5dfcf9b1e8ed65`. No rebuild/relink/configure/benchmark in either execution boundary. V5 exit0 only means the OBSERVE harness finished; its row2 resource file is empty.

## Assessment — full gate, independent byte comparison

The ordered ledger matches all 1006 manifest rows (row, kind, identity, test and binary), each raw hash and single-test GoogleTest envelope, 1006 PASS/exit0, zero RED/ABNORMAL/skipped. All 1006 resource files are present and nonempty; CP2 491/491. The 1087-member ledger is byte-identical in all four full-gate archives. The 81 deferred entries match by binary and test. Recomputed manifest SHA-256 prefix 491 `483f11016d1f51049921aed879c2b23f523d045efc1a2833889a12bb9852a038`, prefix 1005 `94f02d6bd2d599f02bbc7dc7cd317e490cdb00e18827596acac2cfdd827460be`, full 1006 `a9b8083269ebd0786f0584d66c1f89f43362d884840ab95b95c3d0fa59ca0587`, deferred `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce`. No selector change.

| Prior gate | Byte exact | N1/N2 | N3 | Material | Semantic ledger changes |
|---|---:|---:|---:|---:|---|
| TB186 | 623 | 380 | 1 | 2 | 971 only |
| TB185V | 653 | 327 | 0 | 26 | none |
| TB187Q | 651 | 329 | 0 | 26 | none |

Independent normalizer: N1 only GoogleTest elapsed summaries, N2 line endings, N3 multiset of complete region-projection records with ordered residual. Recounted region records 2902 TB188 and TB186; 1614 in each preactivation comparator. Only 858/971 differ materially against TB186. Both preactivation comparisons give exactly 380,388,393,394,396,397,644,645,648,669,686,691,694,698,699,700,843,844,858,963,968,971,972,978,979,1006. No new normalization or whitelist. Row648 exact expected torus V72/E76/F4/χ0 and sphere V18/E30/F14/χ2, component1 and residual0. Row979 explicit unstaged control `CutSearchExhaustedBeforeCellularity`, production V18/E30/F14 and sourceChi2, 10 classified slide carriers, none selected. The eleven LF-terminated row1006 lines hash `d8407bea068c219f04c785fc2701e0a82093c9b8220514d3786c84869f4ca00c`, exact frozen prediction. All controls 393/669/843/844/963/968/972/978/1005 unchanged from TB186 under N1–N3; explicit false controls preserved. No accepted-green loss.

### A1 — row971 cross-representation oracle (discharged for measured contract)

Raw SHA-256 `4ca35bee1919f600b6d9edb49775f7b7bb65f9771f2e84c2451db5eb2bd8df5a`; organic PASS. Recounted 18 named `SpherePieceRay` lines, ten vertex and eight edge rays. Receipt `vertexRays=34 alongEdge=10 inWedge=24 edgeRays=16 alongLocusEdge=8 intoFace=8 changedVertexParameter=0 changedOrdinary=0 failures=0 coincidentAlongEdge=0 coincidentWithEdgeArc=0`. Vertex reverse rays are exactly trace:node/edge 0:8/6-8, 1:21/16-21, 9:8/8-9, 10:49/49-62, 11:21/20-21, 12:45/40-45, 13:34/32-34, 14:0/0-69, 21:34/33-34, 22:45/45-46 (all segment 6). Split-wall traces 0,1,21,22 each carry both opposite orientations at edges 6-8, 16-21, 33-34, 45-46. The code at `tests/FieldAlignedCurveNetworkTests.cpp:18722` checks actual terminal events, exact carriers, cut binding, ten source slides, six whole plus four prefixes and four suffixes, ordered endpoint fractions and both directions. Pinned contact fractions (not a separate geometric derivation): 17:8→0:6 and 20:8→1:6 both `4038890029339747/4503599627370496`; 5:8→21:6 `1009722507334937/1125899906842624`; 8:8→22:6 `464709598030749/4503599627370496`. The assertions can fail if a slide is absent, split at the wrong point, counted twice, has the wrong support/role or lacks either ray. The count alone cannot pass the oracle. A1/RA-277-NV1 is a non-stable test-authority correction for this measured contract; global independent geometric proof is not claimed.

### B1 — sphere repeated original boundary node (root class proved, concrete producer unknown)

Row858 raw SHA-256 `4c53c20b7c24095e3c1f3386516b52e9bc9f9b9a6599a319ffa4cda08032361f`. First 69,196 bytes identical to TB186, SHA-256 `32d6de52259ed91a9968109bda21b68d3dc4d37a3b1aed7b59193301c61a42d9`; removing exactly the one new line makes the whole normalized log identical. Terminal stage/code/locus and `SphereDisplayStopDetail detail=PreparationRejected firstInvalidStage= firstInvalidReason=` remain unchanged. New line: `SphereCompletionFailure detail=BoundaryParityRepair:InvalidReplacementBoundary:repeated-boundary-node;AlternativeRepairBudgetExhausted;attempted=106;budget=106`.

Independent source proof, not inference from the count:

1. `SurfaceCellFeasibilityRepair.cpp:426–485` checks node IDs, twin symmetry, one use per directed halfedge and each cycle's continuity; it permits repeated node IDs and multiple cycles. `SurfaceArrangement.h:365–414` explicitly permits cut-cell disks with bridge walks, bridge excursions and support-only cycles. Incidence validity is not a proof of a simple patch boundary.
2. Parity repair computes its dual adjacency only between different cells (`:1675–1691`); same-cell twins are excluded. Every selected pair receives one insertion in `attemptSubdivision` (`:1818–1824`). Subdivision retains the original endpoint IDs, processes each twin pair once, appends a fresh ID per split (`:1140–1330`) and assigns the forward/reverse replacement in order. Because original directed halfedges occur once, and the two split orientations belong to different cells, a newly allocated node cannot occur twice in one cell. The duplicate identified by this parity path must be an original node that already occurs twice in that cell's input boundary.
3. The replacement loop concatenates each original boundary halfedge's ordered replacement (`:1390–1431`), then sets one cycle offset and audits every rebuilt cell (`:1595–1618`). `audit_simple_cell_boundary` (`:490–535`) rejects the second occurrence of `edge.from` before testing next continuity. It cannot erase an original repetition. Therefore varying the selected parity interfaces cannot eliminate that fixed input-boundary defect. The 106 candidates are alternative exclusions, not 106 separately classified failures; the returned detail comes from the **first** subdivision (`:2020–2036`). It is not evidence that every alternative failed at the same site or that the budget is too small.
4. The audit already has cell/node/halfedge/source-face IDs; `:2033`, `PatchDescriptor.cpp:2559–2577` and `RemeshPipeline.cpp:14157–14164` carry it to the context. The latter retains the simplification input at `:14355–14365` before returning the early rejection. Row858 requests retention. The empty `firstInvalidStage` diagnostic is expected because the later producer-field assignment is not reached. The report does not identify the failed cell or its original two occurrences. A test-only witness of the existing context can distinguish bridge traversal, repeated node in a single cycle, repeated node across cycles, or exterior ownership; it cannot assume which. If arrangement already contains the same exact occurrence, inspect producer incidence; if introduced by simplification, inspect its owning transaction. No raw numeric ID equivalence across stage products. Stop if mapping is not proved.

Thus B1 is a completion-input contract incompatibility, not evidence of a bad split position or insufficient budget. The root class is proved, but the concrete earliest producer and the proper topology remedy remain open. Do not bypass simple-boundary validation or discard protected/mandatory occurrences. The successor is a one-path receipt of existing evidence, not another product repair.

### B2 — V5 runtime candidate, not a completed production result

Census manifest `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793`; exact three OBSERVE identities and log hashes rechecked against prior TB161. Current boundary 3 planned/executed, 1 PASS, 1 RED, 1 ABNORMAL, no membership. All checksums verify, but row2 resource file has zero bytes. This is not a valid complete geometric census or full-gate failure.

| Identity | TB161 | TB188 |
|---|---|---|
| Cylinder | PASS, 8.65 s | PASS, 10.64 s, 288 quads; `accepted=1 strict=0`, 32/81 A3 spans covered; no strict-production promotion |
| BunnyRandom | RED, 325.23 s; terminal `RotationSystemInconsistent` / `TraceEventPositionNodeConflict`, trace82 face (21,72,273) | ABNORMAL exit124, `HARNESS_TIMEOUT 600s`; no terminal result or resource receipt |
| Vase | RED, 200.18 s | RED, 252.30 s, unchanged `AggregateCompletionValidationFailure` |

BunnyRandom prior 142:2→87:0 three receipts, current two; 26:1→99:0 three in each. All corresponding `wallCommitted=0 movingArrival=later movingCommitted=0 interior=1 stop=1 stopRecord=1`. Carrier `(280,411)` fraction `952111344332611/4503599627370496` and carrier `(302,349)` fraction `348952146602893/2251799813685248` remain in the captured contact receipts. No `InvalidNetworkBinding` or struck-index rejection in the captured prefix; absence in a truncated run cannot establish their absence at termination. No terminal geometry, CPU/RSS or exact runtime cost location is established. The old terminal has not been disproved; timeout hides it. Classify non-stable off-gate runtime regression candidate, not proof of a hang, infinite loop, or a new geometric failure. The prior strict offline verifier correctly rejects the missing resource evidence; no invented resource value or substituted timeout.

Bounded corrective route after the single CB-211 chain: use exact TB161 and CB-210 immutable packages and the existing bounded debugger/stack observation mechanism (see CB-205T/TB185T), on only `offgate:360` with identical mode and 600 s limit. Freeze observation schedule, capture repeated stacks before cutoff, elapsed/CPU/RSS and terminal or cutoff, preserve raw receipt positions. Compare where the time is spent; only then isolate one causal cost owner and propose its correction with an independent cost and semantic falsifier. If samples or resource evidence are absent, report invalid observation and do not infer cost owner. No product instrumentation, cap increase, retry as gate, or concurrent semantic fix. V5 is not a required-green identity and does not debit the valid 1006 gate; global activation safety remains held.

## Recommendation — one successor and outstanding obligations

Only next after STATUS COMPLETE: `M6-CP3-CB-211-P13-COMPLETION-INPUT-BOUNDARY-WITNESS`, [bounded plan](gates/Architecture_M6_CP3_CB211_P13_Completion_Input_Boundary_Witness_Plan_20261127.md). Test-only existing audit receipt, compile eight GMP/GMPXX targets, no runtime. No successor work in this Review. Freeze a separate immutable gate only after its compile. B2 remains a carried obligation; no second current turn.

| Prior obligation | Disposition |
|---|---|
| X1/W4/Y1 | Six selected recipes and full gate terminate; no general scaling proof. |
| Y2, X2/Z1, Z3 | Six-row census and corrected row858/972 PASS retained; actual preparation predicate now known. |
| X3/V10, S2/S3/V11, U4 | Exact 648/1006, row393 and row669 controls and transcript verified; wider activation reach unmeasured. |
| Z2 | Exact parity rejecting predicate discharged; carry B1 for concrete input class and earliest producer. |
| A1/RA-277-NV1/AA1 | Row971 ten slides, fourteen pieces, eighteen ray receipts and actual cut bindings pass; pinned fractions remain a cross-representation oracle, no independent geometric derivation. |
| AA2 | CB-210 receipt matches unchanged prefix and old detail, identifies first parity failure. |
| V5 | Executed once, both pending contacts observed; carry B2 timeout, terminal and resource evidence missing. No census acceptance. |
| Y3/Y4, Z4/X5/Y5, S4/U2/U3, U5/W6/R2/R3/R5/R6 | Carried as previously scoped; CB-207C size receipt conditional, CB-207D held. Fine-resolution close_sheets not measured. |
| X4/W5, S1/U1/W1/W2/R1, W3, R4/CB-190, P1, D-U/O3, O1/O2/O4/O5, O6, K6/TB170 | Prior syntax not rerun, prior discharges retained, W3 withdrawn, R4/CB-190 held, P1 supported, D-U/O3 carried, O6 held, K6/TB170 closed. J6/E5/CB-190 and parameter deletion/V3b/R1/O48 held. |

Stable **67 events / 17 categories / 50 recurrences**, debt1/deferred81. The activated test gate is accepted; no CP3/497/D0/H4 promotion, produced sphere or strict production acceptance. Existing lessons §5 (read producer audit before instrumenting consumers; measure cost before repair) and §2 (non-vacuity) apply; no new general rule needed.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | 491, 1005, 1006 and 81 hashes above; unchanged. |
| Decisive claims independently re-derived | Immutable package, all ledger identities/log hashes, envelope, resources, N1–N3, exact controls, both V5 archives and source proof above. |
| Non-vacuity checked | A1 actual ten/14/18 bindings; row858 negative display obligation only; B1/2 falsifiers frozen. |
| Prior obligations discharged/carried | IDs and dispositions above. |
| Stable accounting | 67/17/50; debt1/deferred81; CB-210 package 15162357312 and same 1006 manifest; accepted gate only. |
| New candidates/obligations recorded | B1 and B2 in regression tracker; A1 measured correction discharged. |
| ORIENTATION currency line | TB-REV-188, 2026-11-27 UTC. |
| ORIENTATION §3 / §4 / §7 / §8 | In-place state, sphere and V5 witness, priority and existing pattern update. |
| CHANGELOG | Review entry appended at top; historical CB209 link resolved. |
| ROADMAP | Active CP3, no promotion; current evidence updated. |
| Selector manifest | Gate acceptance entry added; actual selector files unchanged. |
| LESSONS | Existing §2 and §5 lessons cited; no new general pattern. |
| Consolidation under CLEAN_UP_POLICY | CB209 compile record folded with full text, exact filename/line count/hash and live link replacements. Current CB210 and TB186/TB185V/TB187Q evidence remain load-bearing. |
| Successor frozen | `M6-CP3-CB-211-P13-COMPLETION-INPUT-BOUNDARY-WITNESS`; [plan](gates/Architecture_M6_CP3_CB211_P13_Completion_Input_Boundary_Witness_Plan_20261127.md), one test path and falsifiers; no work started. |
| Turn boundary held | Runtime-free; no product/test/fixture/selector/benchmark/build mutation. |
| review_check.py boundary | Native invocation exit1 because the downloaded snapshot has no `.git` or rewrite-baseline object; not a pass. Independent GitHub compare confirms rewrite base `8b7299b43764a6ba3444e5bc774a2f1b65e99731` is ancestor (8476 ahead, 0 behind); reopened all three baseline documents and compared protected headings. Exact snapshot diff and path audit used instead; no missing durable heading. |
| `STATUS` lifecycle maintained | Entry M6-CP3-TB-REV-188 IN_PROGRESS, started 2026-11-27T02:16:52Z, blank resumed/ended. Final direct beacon follows verified remote application/cleanup, not this patch. |
| Pushed to origin, branch in sync | Verify the Drive apply workflow's push receipt and GitHub branch-head comparison before final STATUS. No local Git history/remote sync command is possible with the downloaded snapshot. |

Procedural limits: initial direct document reads preceded the mandatory snapshot read-mode gate; corrected by exact snapshot and source comparison. Native `review_check.py boundary` unavailable as a complete Git-history check in this environment; equivalent connector ancestry and preimage/heading audit used. External turn skill availability and complete per-family tool-call count are not established. Do not represent those checklist items as passed.
