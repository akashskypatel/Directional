# M6-CP3-TB-REV-180 — independent cross-partition arc census review (2026-11-24 UTC)

## Situation

**Accept TB180 as the 1,003-case cumulative runtime baseline.** Close the TB170 accepted-green mechanical recurrence for the seven specified controls. This is not CP3 closure, selector497 promotion, D0/H4 acceptance or a certified production mesh. No benchmark was run and no new stable regression occurred.

## Background — immutable authority

- [TB180 execution report](Architecture_M6_CP3_TB180_P13_Cross_Partition_Arc_Census_Full_Gate_Execution_Report_20261124.md): source `4c2b4cf16732cddb58252d5e758ea0b24449ed2a`, compile run `45351329597`, package `14901170173`, ZIP SHA-256 `8f4be71c9121cb0735ca07c1bc1dd83a66be20f4ab489b674a852dd122b6889f`. Independently checked 28/28 package members, source archive SHA-256 `c039e9bfb527ff8ffef0f2b687e0ebb555200593da46fdcc2309ac016c14e88d`, eight targets, empty final source status, explicit GMP/GMPXX link receipt, and `runtimeExecution=false`.
- TB179 rejected baseline: run `45338168889`, result `14895572803`, ZIP SHA-256 `aeaacb099ea7d51292706802ccf3a9a64702abf70575d01bd8c52847acb0c636`; TB180 [run](https://github.com/akashskypatel/Directional/actions/runs/45457449013) `45457449013`, result `14951803089`, ZIP SHA-256 `67e784747b1c8d04bf781b69b486f3310876fde101b7935f0207fd2fd36a39f8`. Both result ZIP digests, exact file inventories, all 2,014 members per archive, all 1,003 raw-log hashes per archive independently verified. TB180 root manifest `00d69a06641b6c0dade139d8e5d44fa87b8da04301d36558e4fd6d0f51fff75c`.
- Snapshot `9e38e162eec9d61db0cc35cb8eab030ede3a8329`, run `45475773142`, artifact `14959397486`, ZIP SHA-256 `624d4eea091b1f88eb0dbd2fede3e7259c2b99680e26752ef8212f3c2f135b79`; source archive `6ce5c838144a0cf96acb4da3c59f0d76f825b3adb30d681b07019ead38ce3c84`. All 5,815 listed file hashes match. Independent comparison of all files in src (162), include (146), tests (68), benchmarks (30), cmake (12), and root CMakeLists against the packaged source found zero differences. GitHub compare to resumed head `ac70e21d5fd06a5634c8130a69ba97bf2066b342` confirms 22 descendant commits, no code drift. Test postimage SHA-256 `6e83fc338d7632c4540691cb12403d7b495ecd0ddea52f31d792c29c267e0b7b` matches the CB-200 exact manifest. PR #8 remains open/draft/unmerged.
- The initial attempt read multiple documents before snapshot acquisition; this was a procedure miss, corrected by using the verified snapshot for subsequent static review. No source discrepancy. The snapshot contains no original Git history.

## Assessment — independently re-derived gate

| Check | Result |
|---|---|
| Frozen full manifest (header + 1,003 rows) | `2928fd3181eb06e635c0b88527550cddc7ff602b95b757ebd8d569e699e2f724` |
| Historical accepted TB169 prefix (header + 993 rows) | `82581dd14064efe3729923cfd94333ef70113b0bb84e6bb8eabfb2ec61cce436` |
| Accepted CP2 prefix (header + 491 rows) | `483f11016d1f51049921aed879c2b23f523d045efc1a2833889a12bb9852a038` |
| Deferred ledger | `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce`; 81 identities |
| Membership | 1,003 gated + 81 deferred = 1,084; both archives equal, no duplicated binary/test identities |
| TB179 → TB180 verdict | 1,002/1,003 → 1,003/1,003; exact manifest identity/order/expectation agrees with every ledger row |
| Raw comparison | 639 byte-equal, 363 equal after N1/N2, 0 N3-only, row786 sole material change |
| Fragment diagnostics | 1,554 → 1,554 complete `M3_CP4AB_FRAGMENT_DIAG` records; identical per-row multisets |
| Ledger comparison | Row786 RED → PASS, exit 1 → 0, pass 0 → 1, failure-site removed; all other non-log-hash fields equal |
| Execution boundary | Exact package/source, 1,003 executed once, no missing/skipped/duplicate/control_bad/unexpected_pass/later_positive_red/red_site_bad; immutable postflight, no compile/configure/relink/benchmark |
| Accepted prefixes | All first 993 and first 491 rows PASS |

The comparison was computed from the archived bytes, not copied from the execution report. N1 removes only GoogleTest elapsed time; N2 normalizes line endings; N3 allows reordering complete counted fragment records. No assertion-location or semantic-record normalization. No unexplained off-row difference.

### M1–M4 adjudication: ordinal 407, not a requirement reduction

`M3_Closure_Record.md:8250–8258` requires each crossed source face and its component in each named partition where defined. It does not require a crossed face in the plan subject. `SurfaceCutGraph.cpp:824–870` admits each arc by its own certifier component, and `GlobalTopologyPlan.cpp:800–815` copies that census and adds independent plan labels. Equal-orbit terminal slits remain in the certifier NotTraceCut partition; the plan assigns their edge-side owner, excluding them from the unowned-face subject. No partition unification or inserted ownership is justified.

Row786 raw SHA-256 `5d9b538105b5b84e1d2209cd3a164c8f951b56cdc239bb8ccbcab0226516a0e2`. Its actual positive row is the nontruncated plan component 0 with `Superset` correspondence, arcs 19 and 21, each five unique crossed faces. Face (36,38,39) and face (66,67,120) have certifierComponent=0, planComponent=absent, reason=TerminalSlit. The other eight have both labels absent, reason=none. These are the predicted witness identities from the prior independent/adversarial review, not an assertion introduced to force the fixture's shape.

The helper at `FieldAlignedCurveNetworkTests.cpp:5558–5643` derives maps independently from plan component face lists and certifier component face lists, rejects duplicate membership, checks the selected plan subject and certifier superset, compares each optional label to its own map, rejects duplicate crossed faces, checks certifier crossing and requires a typed reason when certifier membership exists. The caller at row786 uses real production data, requires complete plan evidence and a published certifier census, asserts the positive, constructs six independently corrupted copies, and compares a full name-to-rejection map at lines20230–20238. Wrong-reason rejection fails the test, as does accepting a corrupt copy. The raw receipt confirms all six:

| Mutation | Exact rejection |
|---|---|
| Increment crossed-face count | `arcFaceCount` |
| Duplicate crossed face, adjust count | `arcFaceDuplicate` |
| Toggle plan label | `planLabel` |
| Erase certifier label | `certifierLabel` |
| Wrong certifier label | `certifierLabel` |
| Clear reason | `reason` |

M1–M4 satisfied for the frozen witness. No new generalized claim about all possible partition or contact fixtures. C4 remains withdrawn: production already rejects a region draft with no owned face; the two-region mechanical plan and its controls provide real production-path evidence.

### M5 — obligations and recurrence disposition

All seven controls (445, 652, 653, 656, 658, 660, 786) PASS. Six were recovered by CB-199B/TB179 through the exact reciprocal retrace selection; row786 was still RED on a test-local stale premise. The test-only CB-200 removes that false premise while adding six discriminating negative checks. No other raw semantic change. TB170 recurrence and L2 non-stable witness defect are closed at their specified control boundary; retain the recorded history and cause. Stable totals remain **67 events / 17 categories / 50 recurrences**; produced-witness debt **1**, deferred **81**. No new stable event. Promote only the cumulative runtime baseline to TB180 (CB-200 package `14901170173`); CP2 acceptance remains 491/491.

- K1 compile evidence preserved; K2/J4/J5 production selection/port ownership remains proved for the selected path; K3/K4 full gate and comparison accepted; K5 unproved reader change remains withdrawn. M1–M4 discharged. C4 withdrawn, not a new assertion obligation.
- J6: row1003 and row669 are unchanged under allowed normalization. The mechanical witness contains no production struck-reference contact; isolated row1002 remains a valid helper proof, not a production witness. Debt stays 1. Do not invent a positive counter or modify the fixture to obtain credit.
- K6: condition met for the shared trace-segment namespace correction; exact next plan only. Row979 remains a staged `RegionContainsInteriorSingularity` at vertex8, not a valid sphere plan. E5 (CollinearOverlap/EndpointTouch), Branch A, CB-190 S4/S6/S7/W6 and CP3/497/D0/H4 remain held.

## Recommendation

Freeze only [`M6-CP3-CB-201-P13-EXACT-TRACE-SEGMENT-NAMESPACE`](gates/Architecture_M6_CP3_CB201_P13_Exact_Trace_Segment_Namespace_Exact_Manifest.md) — namespace-only exact patch, compile-only. Seven files, +66/−66, verified scratch pre/postimages and unchanged source line counts. Separate TB must reproduce all 1,003 TB180 normalized raw records and pass all frozen tests. Any preimage, scope, compile, membership, semantic record or digest difference is STOP. No successor implementation, compilation or runtime in this Review.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | Header + 993 and 491 rows match full historical hashes above; all 1,003 manifest and ledger identities checked. |
| Decisive claims independently re-derived | Both result ZIPs, exact file/raw-log hashes, counts, complete diagnostic multisets, manifests, package and source snapshot, seven controls, six rejection receipts. |
| Non-vacuity checked | Six corruptions require exact expected rejection, real production positive passes. J6 not exercised; debt retained. |
| Prior obligations discharged/carried | M1–M4 and TB170/L2 closed at control boundary; K1–K5/J4/J5 dispositions retained, C4 withdrawn; J6/K6/E5/row979/Branch A/CB-190 carried. |
| Stable accounting | 67/17/50, debt1/deferred81; TB180 1003/1003 accepted runtime baseline, CP2 491/491 unchanged. |
| New candidates/obligations recorded | No new regression. K6 exact successor manifest and tracker updated. |
| ORIENTATION currency line | TB-REV-180, 2026-11-24 UTC. |
| ORIENTATION §3 / §4 / §7 / §8 | Current state, witness, priority and recurrence disposition updated; no product promotion. |
| CHANGELOG | Entry added. |
| ROADMAP | Current status and next updated. |
| Selector manifest | Full-gate baseline index updated, no selector byte changed. |
| LESSONS | Existing membership/non-vacuity and source-authority lessons apply; no new generalized rule. |
| Consolidation under CLEAN_UP_POLICY | TB179 independent and adversarial reviews preserved verbatim with hashes and original source location in consolidated volume D3; live links redirected. |
| Successor frozen | `M6-CP3-CB-201-P13-EXACT-TRACE-SEGMENT-NAMESPACE`, exact manifest and falsifiers above. |
| Turn boundary held | Runtime-free, no product/test/build/fixture/selector mutation; only review documents and proposed patch. |
| review_check.py boundary | Executed: product/test/build and selector boundaries PASS; 39 numbered selector hashes match snapshot HEAD. Four history-dependent checks FAIL because the source snapshot lacks Git history. Fetched the three documents at historical rewrite baseline `8b7299b43` through GitHub and matched all durable headings (handoff 4/4, orientation 1/1, tracker 0/0). This is a separate check, not a clean history-dependent exit. Document drift audit: 0 errors, two size and three protected-landing-file warnings; the Review closeout changes are authorized, existing orientation bloat is not a new semantic defect. |
| STATUS lifecycle maintained | Entry IN_PROGRESS, Started at 2026-11-24T19:57:29Z; Resumed at 2026-11-24T20:21:04Z; final beacon only after verified patch and cleanup. |
| Pushed to origin, branch in sync | Drive apply and GitHub ref verification required; local snapshot is not an origin checkout. No push claimed in this pre-application record. |
