# TB-EXEC-179 — retraced trace selection full gate (2026-11-24 UTC)

## Situation

**Execution complete; product gate rejected; independent comparison review required.** All 1,003 cases ran: 1,002 PASS, one RED. Six of seven inherited mechanical controls pass. Row 1003 passes. No inherited PASS becomes RED. Row 786 reaches a later assertion and fails. Only `M6-CP3-TB-REV-179` is authorized next, in a separate turn.

## Background — exact execution authority

| Item | Evidence |
|---|---|
| Semantic source and executor | `5d9468d168ee3c9eed086bd787979ced7f86843b` |
| Compile package | [CB-199B record](Architecture_M6_CP3_CB199B_P13_Retraced_Trace_Selection_Code_Build_Record_20261124.md); artifact `14893165901`, ZIP SHA-256 `0ff23208d9329a02951d1aea83c0631ac7790b92bb3bfb46639d52d33e7c225c`; 28/28 compile-package checks recorded there |
| Root manifest / source archive | SHA-256 `b2c0c0fdc8b2cf530bf05b472d7525cd2d0be234b212f7d466564618b6d3d668` / `e5e6e9d24a553e1b1d0d4b6f556ea23d9d01f2e2ff49a67d4d65e2908f00bb21` |
| Frozen gate | `gates/Architecture_M6_TB179_P13_Retraced_Trace_Selection_Full_Gate_Case_Manifest.tsv`, SHA-256 `2928fd3181eb06e635c0b88527550cddc7ff602b95b757ebd8d569e699e2f724`; 1,003 rows; exact byte prefix is the complete TB178 manifest (1,002 rows), SHA-256 `921bd04bbfab596da6679083d5880d3f4893126e19a91c4687ba5ba63827e8ed` |
| Deferred ledger | `gates/Architecture_M6_CP3_RP01_Off_Gate_Deferred_Ledger_v5.tsv`, SHA-256 `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce`; 81 |
| Harness | `.agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh`, SHA-256 `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94` |
| Dispatch | `m6-cp3-tb179-exec`; event `5c48ba005cda9aa89c8ec5c7c26335093111dc5e`, request SHA-256 `54d63c3f00e1b5eea7cd55ececb8f079d6d54e8f687711c6bfa82f90aaba0a32` |
| Runtime | [run 45338168889](https://github.com/akashskypatel/Directional/actions/runs/45338168889), job `138255323818`, wrapper 06:08:39Z–06:20:33Z; schema validation and parser PASS; runtime exit 90; mailbox publication PASS |
| Result | [14895572803](https://github.com/akashskypatel/Directional/actions/runs/45338168889/artifacts/14895572803), ZIP SHA-256 `aeaacb099ea7d51292706802ccf3a9a64702abf70575d01bd8c52847acb0c636`; 2,014/2,014 member checks; root manifest SHA-256 `524eaf030b7b25d3aa645ae37616eba052c65a7ab4f4a38c7aa7b53c1b5c6a70` |
| Harness log | `14894734176`, ZIP SHA-256 `63171bc23ff68c1714b845f924e246ff202a3c07a4c4c4d1c087948356d5d42f` |
| Wrapper log | `14895233543`, ZIP SHA-256 `9fc18340ffa8b8f9212281c7f8d282de4f4478bbdc9914197f2ae1762fd80cbd` |
| Baseline | [TB178 report](Architecture_M6_CP3_TB178_P13_Retraced_Trace_Reference_Remap_Full_Gate_Execution_Report_20261124.md), artifact `14885616510`, ZIP SHA-256 `57260ad2ee62adb02bad56bc09d2ab7e2c4782b8ad4ef43faa76cb5e539600a6`; 2,012/2,012 member checks |

The terminal mailbox, artifact API and local ZIP digests agree. Both archives have exact member inventories; all 1,002 baseline and 1,003 candidate raw-log hashes match their ledgers. The frozen manifest rows and deferred membership match both ledgers exactly. All cases execute once. No missing, duplicate, abnormal or skipped cases; no unexpected passes, later positive failures or RED-site mismatches in harness accounting. `postflight=true`; configure, compile, relink and benchmark are false. No runtime repair or source/test/fixture/selector mutation occurred in TB. The harness rejects one required control; this is semantic RED, not orchestration failure.

## Assessment — frozen gate and raw-record comparison

| Check | Observed |
|---|---|
| Verdict | 1,002 PASS, 1 RED, 1,003/1,003 executed; 995 inherited PASS preserved |
| Membership | 1,003 gated + 81 deferred = 1,084; exactly one added gated identity, no removals or other membership changes |
| New row 1003 | `FieldAlignedCurveNetwork.MechanicalRetracesPublishBothPortsBeforeTopologyReaders`, producer test binary, PASS, exit 0; SHA-256 `43b0bda76f69493cf98909450c79ed859a11d9bb4527c05f76c95df3e97d38c7` |
| Inherited raw records | 594 byte-identical; 385 N1/N2 only; two N3 only (174/176); 21 materially changed |
| Inherited ledger | Six RED→PASS changes and row 786 later assertion; no other field changes except raw hashes |
| N3 records | 1,450→1,550 complete `M3_CP4AB_FRAGMENT_DIAG` records, 100 added and zero removed across the 21 changed inherited rows; additions are not normalized away |
| K4 committedSlide | 1,560 inherited lines on each side; zero per-row additions, removals or replacements |
| Row 979 | Still staged `RegionContainsInteriorSingularity`, not production success |

N1 permits only GoogleTest elapsed-time normalization, N2 line endings, N3 the counted multiset of complete `M3_CP4AB_FRAGMENT_DIAG` records. No assertion-line normalization. The 21 changed inherited rows remain distinct and require review. Exact raw before/after records and order are retained in both immutable result archives at `raw/<row>.log`; the companion comparison inventory and unified raw diff (SHA-256 `dd77516bcda1e6bf355f55156db83627f1eaa4459b330c81e999edad1706a848` and `c8150f26cadcc481609c38d9716872eebd8f236230a34a2d7482912387108f0e`) itemize each difference. Comparison evidence ZIP SHA-256 `099a4240af1e2be460e0f472cae9e74d5ee9942de64fe712cdb2da721dd6370c`. All records are recoverable from the cited artifact IDs.

### Every material inherited difference (N1–N3 not applied to these additions/removals)

| Row | Verdict | Complete fragment record count before→after | Other exact record change |
|---:|---|---|---|
| 396 | PASS→PASS | 16→24 | None |
| 397 | PASS→PASS | 16→24 | None |
| 445 | RED→PASS | 0→4 | Failed `fixture.plan.has_value()` at 19446 → PASS |
| 637 | PASS→PASS | 0→4 | None |
| 638 | PASS→PASS | 0→4 | None |
| 649 | PASS→PASS | 0→4 | `m3Cp4c3BW1BW2`: V=22,E=26,F=6 → V=22,E=22,F=2; χ=2, residual=0 unchanged |
| 650 | PASS→PASS | 0→4 | None |
| 652 | RED→PASS | 0→4 | Removes `RegionElectedCutComponentEmpty` exception and adds `m3Cp4c3BR6` plus three `M3_CP4C3_FACE_BINDING_CENSUS` records |
| 653 | RED→PASS | 0→4 | Failed `mechanical.plan.has_value()` at 14457 → PASS; adds OwnerMap and R8 receipt ordinal393 |
| 656 | RED→PASS | 8→12 | Removes `RegionElectedCutComponentEmpty` exception → PASS |
| 658 | RED→PASS | 0→4 | Failed `mechanical.plan.has_value()` at 20027 → PASS; adds partition correspondence and R8 receipt ordinal406 |
| 660 | RED→PASS | 0→4 | Failed `mechanical.plan.has_value()` at 14256 → PASS; adds BW3 and R8 receipt ordinal390 |
| 662 | PASS→PASS | 0→4 | None |
| 665 | PASS→PASS | 0→4 | None |
| 669 | PASS→PASS | 16→24 | Mechanical reachability record changes: 12→8 traces, 32→23 events, graph E26→22/F6→2, plan absent→two regions; torus and sphere reachability records unchanged |
| 687 | PASS→PASS | 0→8 | None |
| 784 | PASS→PASS | 0→4 | None |
| 786 | RED→RED | 0→4 | Failed plan existence at 20086 → later `region_frontier_interior_arc_census_is_valid(*row)` at 20101 |
| 787 | PASS→PASS | 0→4 | None |
| 788 | PASS→PASS | 0→4 | Census, boundary edges, transits, seed attributions and arc/face records change; exact record diff contains 155 removed /146 added non-fragment lines |
| 857 | PASS→PASS | 0→4 | None |

The additional region-support projection records describe the two mechanical regions: region 0 has 250 support faces, region 1 has 50. Row 652 now has graph/source χ=2 and two region certificates (boundary arcs 40 and 4), both disk and field regularity true. Row 669 confirms the four selected traces are absent; trace IDs 3,8,9,11 disappear while surviving IDs remain. This supports the predicted A2a selection correction and subsequent region election. The row1003 source at line 23591 asserts bindings 0→3, 2→8, 4→11, 7→9, eight traces, all 12 ports exactly once, no removed trace IDs, live contact/event references, digest equality after reconstruction, and rejection with `InvalidCandidateTraceBinding` after stripping an arrival binding. PASS supports these assertions. It does not print whether a production contact actually struck a removed trace; J6 remains for Review. No new A2a rejection or lost accepted-green row is observed. Row 788's census changes from 212 to 222 faces (digest 835099723348023536→8007243191870856758), boundary edges 74→72, transits 50→39, seeds 43→47, interior arcs 20/24→19/21; crossed-face counts remain 5 each. This evidence must be independently checked against the contract, not treated as a permitted normalization or production acceptance.

### Remaining control and classification

Row 786 `SurfaceCutGraph.InteriorArcCensusNamesCrossedFacesAndTheirComponentsInBothPartitions` is the sole RED. The plan now exists; the region frontier interior arc census validator fails at `FieldAlignedCurveNetworkTests.cpp:20101`. The helper (line 5551) checks partition correspondence, publication, count/extent, truncation, nonempty incidences, each crossed-face count/extent and typed reason, and at least one face that touches the plan subject. The receipt prints after this assertion; the log does not identify which internal condition failed. The corruption-negative branch is not reached. TB178 stopped at line 20086 (`mechanical.plan.has_value()`). This is not assertion-line drift: it is a later predicate reached by the corrected producer. The new failing predicate is a candidate downstream correctness or witness-contract issue; the test failure alone does not distinguish them. Do not weaken the oracle. Record no new stable regression event yet: the row was already RED in the seven-control recurrence; no accepted-green loss occurs. Stable totals 67 events / 17 categories / 50 recurrences; witness debt1, deferred81. The six recoveries and row652's first-failure advance require independent review before any acceptance or recurrence disposition. Accepted TB169 993/993 and CP2 491/491 remain unchanged. No CP3/497/D0/H4 promotion.

## Recommendation

Only `M6-CP3-TB-REV-179` is next. Re-open the two immutable result archives and exact CB-199B source. Re-derive all 21 record changes and the row1003 non-vacuity, including both ports, retained traces and live references. Verify row 652's two-region certificate and the exact row786 assertion against the region-frontier census contract and callers. Determine whether the remaining failure is a stale witness or producer/reader defect before freezing any CB-200 correction. Preserve the every-region-owns-a-face assertion, K1–K6, E5, row979, Branch A and CB-190 obligations. No downstream repair, new reader change or acceptance promotion in this execution turn.
