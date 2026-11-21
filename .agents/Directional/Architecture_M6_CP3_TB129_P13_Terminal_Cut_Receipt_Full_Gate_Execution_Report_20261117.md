# TB129 — terminal-cut receipt full gate (2026-11-17 UTC)

## Situation

`M6-CP3-TB129-P13-TERMINAL-CUT-RECEIPT-FULL-GATE-EXEC` — **MISMATCH** under [RA-250 §R6](Architecture_M6_CP3_TB128_P13_Face_Contact_Full_Gate_Independent_Review_20261117.md#r6-tb129-frozen-m6-cp3-tb129-p13-terminal-cut-receipt-full-gate-exec). Full gate 953/953 PASS, but the frozen raw-log scope and count fail. Both runtime jobs completed with valid postflight. The 66 sphere receipts and two BunnyRandom receipts each satisfy H1 (common-carrier contact proxy). No H2 or third owner observed. No promotion or correction; no rebuild, fixture, manifest, selector, test, source or workflow edit. No successor execution.

## Immutable authority and preflight

- CB151 semantic source and harness executor `c45e9abe5085f39c1f5bcb149ec07f95b719177e`; immutable package `14327212608`, ZIP SHA-256 `9ef0f781947748cf2433566f3704259ab362dbf8f042999f87248ca6d645eb69`, root manifest `0c65a1f63be701f8497fb828d3826f3b7a2a23f00042d97600570263647677b7`, source archive `434a3817c90395366c572287e205c3d0d9268241817b20c3f106ba6e2a500417`. Preflight 28/28 package checksums; six archived modes, GNU Multiple Precision (GMP/GMPXX) link evidence, `runtimeExecution=false` at compile; [CB151 record](Architecture_M6_CP3_CB151_P13_Terminal_Cut_Before_End_Receipt_Code_Build_Record_20261117.md). Harness `.agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh`, SHA-256 `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94`.
- Frozen [gate](gates/Architecture_M6_TB128_P13_Face_Contact_Node_Full_Gate_Case_Manifest.tsv) `941287fa96f3432eb1d67a9ae1e5dc7bc0ca2f3a1775cd5f9fb35482a4fa7962`, 953 rows; [deferred ledger](gates/Architecture_M6_CP3_RP01_Off_Gate_Deferred_Ledger_v5.tsv) `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce`, 81 identities; [census](gates/Architecture_M6_TB63_P13_Census_Case_Manifest.tsv) `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793`, three rows. Both manifest self-checks passed before dispatch.
- [TB128 comparator](Architecture_M6_CP3_TB128_P13_Face_Contact_Full_Gate_Execution_Report_20261117.md): source `85f9c703c5de86fb2b401cf83c03499a1ce73a27`, gate `14318100443`, ZIP `e208416775f474f75d79ec76697ed19d643a121d8ad086cd37b8f3a330436e5d`; census `14317054197`, ZIP `cdf7dab92f0e8c2650db6e2e5ac015d7ab5f07e251b4acdd17e6ed511ee7ccf4`. Both archives verified (1,914 + 9 members); all ledger identities, raw-log hashes and membership checked.
- Snapshot source `a6fbf0e7cd718d4017a8dca5a33411bd885d9d8e`, run `44083674865`, artifact `14327658805`, ZIP `60117c76247b2b4aa1874662358c05f21390cf63a92de51244bb15a4138cf855`, 5,522/5,522 verified. Compare to resumed HEAD `1b25e38a5c2a58b076f74e485a3b1727d04e69c9` confirms only continuation record, dispatcher slot and STATUS changed. Original CB151-to-snapshot comparison had no semantic source or harness change. PR #8 draft, open, unmerged.

## Execution and evidence

| Work | Request event SHA / request SHA-256 | Actions run / runtime job | Mailbox key (attempt 1) |
|---|---|---|---|
| Full gate | `d86a4d8cd5df50fa9441f4656ed1f3ee508a4007` / `172788d0c07d4d08f6827e31a23814143cdb6b5ebbe22d1ac9c255b981efdf25` | [44083905317](https://github.com/akashskypatel/Directional/actions/runs/44083905317) / `134041536119` | `m6-cp3-tb129-gate-v1` |
| Census | `9b6721c617d850666159fe22b7dd8f7892cc080f` / `3d0607a041db9c59bae092d23705c6b9e51c0f314e3d6afbc9e1ebb49f00a37a` | [44084015700](https://github.com/akashskypatel/Directional/actions/runs/44084015700) / `134047429742` | `m6-cp3-tb129-census-v1` |

Both mailbox records on `workflow-mailbox` match exact event/source/request digests; validation, parse, runtime, mailbox jobs succeeded; compile/drive/noop jobs skipped. Both harnesses ended organically with exit 0. No duplicate dispatch. All six result/log ZIP digests match published values:

| Artifact | ID | SHA-256 |
|---|---:|---|
| Gate result | 14329895372 | `c67b07a15772f73afc87339526fd3849f8b870f9d9d3ee0330e0af5840ccb30c` |
| Gate log | 14329620767 | `21a507456a9edf73e23bf814fb07d3fb1b8bebabd8dcb206701078ef6a718a24` |
| Gate reusable log | 14328199575 | `c968cc59e611e64c6d57602a360ce7dc2a26b5a95c2479e7a14ea2833154b343` |
| Census result | 14328938547 | `9da50feb13375580b7e920ae6e1603b16837ee825202f0631f91efd7cce3a42b` |
| Census log | 14328973484 | `cfe1b035ad82c00bf2ce6c335b8ded64ca3540761018ce4a7df77c613d437f3a` |
| Census reusable log | 14330180368 | `8d1c2035ac52b4c4853a113317ca8003265ee3eebb17dadd0a1e6271040e8b25` |

All 1,914 gate and nine census internal checksums, 956 row identities/raw-log bindings, complete membership equality, source/package bindings and no compile/relink/configure/benchmark flags verified. Gate 953 planned/executed/PASS, zero RED, missing, skipped, duplicate, abnormal or bad controls. Census 3 planned/executed, 1 PASS, 2 registered RED, zero bad controls/abnormal/missing/skip/duplicate. Both postflights true. Baseline plus candidate internal checksums: 3,846/3,846.

## Frozen comparison — MISMATCH

All 951 previously PASS ledger records match in substantive fields, and 858/952 both transition RED to PASS. 927/953 gate raw logs are equal after elapsed-time normalization. Of 26 other rows: five permitted newline-framing differences (162/173/177/195/705, entire newline-free text identical); row164 matches as a multiset of complete lines, six complete projection records each, no torn line; row952 restores the witness with no receipt; 19 rows contain 66 receipt lines. Row 858 is PASS with two real face-event receipts and the former failure lines absent. Its raw log also contains receipts outside rows644/669/698; do not suppress this conflict with the frozen text. Row 952 passes all retained assertions in the corrected fixture. No assertion removal.

| Rows | Receipt count per row | Classification of raw difference |
|---|---:|---|
| 644, 669, 698 | 4 | Requested locations, but repeated receipts. Row644 additionally changes `errorSourceFace=none` to `18-19-24`; rows669/698 populate trace 7/event29, claimed edge 18-24, trace present, incoming/outgoing carrier counts 1/1, edge available, FaceRestricted, candidate (7,7,Incoming,18-24). `ArcTraceTerminalCutPositionMismatch` remains unchanged. |
| 380, 388, 393, 394, 396, 397, 686, 691, 694, 699, 700 | 4 | Out-of-scope receipt-only additions; normalized raw logs otherwise identical. |
| 645, 648, 843, 844 | 2 | Out-of-scope receipt-only additions; normalized raw logs otherwise identical. |
| 858 | 2 | Recovered required guard plus receipt lines; frozen receipt exclusion criterion not met. |

All receipt counts refer to log lines, not distinct network identities or independent defects. The raw archives do not label each repeated build invocation with an independent network ID. For rows644/669/698, do not claim a per-network count proof merely from four identical rows. RA-250 permits no receipt on other rows and explicitly requires exactly one BunnyRandom receipt. Those requirements fail irrespective of per-network grouping. No widening of the frozen comparison. No evidence of new lost test acceptance.

## Representative census and receipt owner

| Case | Result | Comparison |
|---|---|---|
| Cylinder | PASS, 288 accepted quads | Normalized entire log and substantive ledger identical. |
| Prescribed sphere (gate) | Existing A2a′ rejection | All 66 lines identical; H1. |
| BunnyRandom | RED, zero accepted faces | Same preterminal non-receipt lines and same postterminal normalized lines; two added identical receipt lines, not one. Real terminal face/edge/trace/event/pass now printed. |
| Vase | RED, zero accepted faces | Entire normalized log and substantive ledger identical; `AggregateCompletionValidationFailure`, 189,462 segments, 26,817 arrangement cells, 67,750 internal quads. |

Census comparison MISMATCH because the receipt count is two. The two new lines occur before the terminal; removing only those lines demonstrates that all other preterminal records, including all four mandatory-edge inventory records and assertion sites 493/495, match. That diagnostic-only comparison is explanatory, not a broadened pass criterion.

Sphere receipt (66 identical lines):

```text
EmbeddedGraphTopology.terminalCutBeforeEnd trace=7 sourceVertex=21 segments=8 event=29 kind=TraceIntersection node=8 face=(18,19,24) edge=(18,24) position=7 pass=FaceRestricted candidate=[position=7 segment=7 Incoming] lastFace=(18,19,24) lastIncoming=(18,24) lastOutgoing=(19,24) terminal=contact face=(18,19,24) struckTrace=3 struckSegment=6
```

BunnyRandom receipt (two identical lines):

```text
EmbeddedGraphTopology.terminalCutBeforeEnd trace=1 sourceVertex=3 segments=15 event=117 kind=TraceIntersection node=206 face=(42,335,336) edge=(42,336) position=14 pass=FaceRestricted candidate=[position=14 segment=14 Incoming] lastFace=(42,335,336) lastIncoming=(42,336) lastOutgoing=(335,336) terminal=contact face=(42,335,336) struckTrace=21 struckSegment=4
```

BunnyRandom terminal:

```text
terminal=NotProductionReady:surface-cut-graph/CellularityNotEstablished/origin=RotationSystemInconsistent detail=CellularityNotEstablished traceSegments=0 arrangementCells=0 completedQuads=0 completion= locus face=(42,335,336) edge=(42,336) history=0 vertex=3 rotationReason=ArcTraceTerminalCutPositionMismatch trace=1 eventIndex=117 eventPositionPass=FaceRestricted
```

Both H1: `TraceIntersection`, `terminal=contact`, one face-restricted incoming candidate at n−1, same edge as `lastIncoming`. Sphere n=8/position=7; BunnyRandom n=15/position=14. Each terminator strikes a different trace and has a recorded exact contact binding. No H2 (`LimitCycleTermination`) line. These are observed instances, not proof that all contacts can use one treatment. No middle-piece direction falsifier or O46 downstream witness established.

## Candidate root cause and disposition

- **C5/O45/FC-7 (observed H1, existing candidate):** the canonical producer `src/geometry/SurfaceCellTracing.cpp:4062–4210` retains `terminalContact` and emits `sourceEdge` from `field_aligned_common_carrier` (`:2871`, smallest common key). `src/geometry/EmbeddedGraphTopology.cpp:632–637` excludes contact events with an edge from the face-contact collector. The remaining `trace_event_position` (`:147–204`) resolves the carrier on the event face: incoming gives segment index, outgoing gives index+1. The receipts show only incoming at n−1. `build_arcs` (`:1146–1208`) includes this Terminal incidence but fails the existing exact end condition. This supports the RA-250 H1 hypothesis for both fixtures and locates the error before rotation/fragment ownership. The exact contact binding is already present. Review must decide the scope of contact classification and count common-carrier contacts on Cylinder and Vase before freezing any switch; do not infer that the latter cases stay unchanged after a switch. O45 remains open pending that review; no correction in TB129.
- **Comparison scope/count (new non-stable diagnostic/criterion candidate):** the new `report_terminal_cut_before_end` call is in the common `build_arcs` rejection branch, not restricted to a test identity or one execution of a network. The observed identical lines span many tests and repeat within a case. The actual number of rejected-network invocations cannot be recovered just from this untagged receipt; the graph caller `SurfaceCutGraph.cpp:1011` returns the error on each failed call. The scope mismatch is real under R6, not an accepted-green loss. Independent review must adjudicate call multiplicities and whether the frozen comparison itself is too narrow; no log filtering or identity-based production code fix is authorized here.
- **Rows 858/952 (recovered candidates):** CB151 reports the actual terminal face, and the restored row858 passes; CB150 corrects the GMP conversion premise and row952 now passes. This does not establish the final product oracle or independent closure of all earlier obligations. Row164 matches the authorized complete-record multiset; the five newline-framing cases match the allowed normalization. No stable regression count change. Cylinder/Vase unchanged; preserve all pending obligations.
- Stable 66 events / 17 categories / 49 recurrences; debt 1, deferred 81, CP2 accepted 491/491; CP3/selector497 and D0 not promoted. C5/O42/O43/O45/O46 open; narrow C3/O44/C1 closed; FC-1/FC-4 producer proof and middle-piece direction open; D11=A, D12=A, D10 deferred, D6 pending; `chainRimSchedules=false`.

## Recommendation

Exactly next per RA-250 §R6: `M6-CP3-TB129-P13-TERMINAL-CUT-RECEIPT-FULL-GATE-REV` (independent Review, runtime-free). Re-open the primary archives and independently adjudicate all log differences, receipt scope/count, H1 classification and stable-accounting effects. The MATCH-only outcome definition and semantic fixes remain unauthorized until Review. Preserve prior evidence, exact diffs and frozen manifests. See the [folded continuation](M6_Consolidated_Record_Vol_D3_CP3_P13_from_20261109.md#architecture_m6_cp3_tb129_p13_terminal_cut_receipt_full_gate_continuation_20261117md) for dispatch/preflight provenance. The subsequent [independent Review](Architecture_M6_CP3_TB129_P13_Terminal_Cut_Receipt_Full_Gate_Independent_Review_20261117.md) upholds MISMATCH and owns the next-turn decision. The File Library bundle `Directional_TB129_verified_evidence.zip` retains both comparison result archives, candidate result/log archives, exact request JSON, offline comparator, complete row diffs and audit inputs. No repeated runtime or successor work.

## Closeout preservation

- [Cleanup run 44087773567](https://github.com/akashskypatel/Directional/actions/runs/44087773567) succeeded; cleanup commit `773dddaeb02a9ca3a61aac595f0bf08d003d5fa5`, result `14328914735` ZIP `392f8c28dedd1910bb2a317533c91e8b129068251fa0a2d8a166800b9753b5e7`, log `14329708031` ZIP `de65f61a7d7f47ebff7be1c0fdd0590ec87978170ec356d36bb7768ec955de06`. Both ZIPs checked; current TB129 snapshot marker removed. Existing unrelated legacy markers remain; do not delete unadjudicated historical evidence.
- Snapshot-to-cleanup-commit comparison establishes that none of the five intended closeout paths changed. The earlier staged navigation-only patch is superseded by this complete closeout patch; do not apply the older in-progress navigation. Local documentation drift audit has zero errors and one authorized protected-change warning for live handoff maintenance; all durable headings remain. No policy, frozen definition, design, or selector edits.
- Prior attempt reported late policy/timer/read-mode sequencing; this resume started the reminder after the bootstrap and used the retained verified snapshot, not a second runtime execution. Exact combined tool-call count is unavailable. These procedural limitations do not change the byte-verified runtime evidence or frozen comparison verdict.
