# M6-CP3-TB-REV-192 — independent review (2026-11-27 UTC)

## Situation

Accept the frozen 1010-row test gate only. All 1008 inherited cases and both new guard cases meet the frozen contract. The ten sphere partial co-traces are measured, not removed. M6-CP3 stays open, CP2 stays accepted at 491/491. No production or V5 acceptance.

## Background — evidence authority

The [execution report](Architecture_M6_CP3_TB192_Singularity_Arrival_Execution_Report_20261127.md), [exact manifest](gates/Architecture_M6_CP3_CB215_CB216_TB192_Singularity_Arrival_Exact_Manifest.md), [A2a arrival DEFN](Architecture_M6_CP3_DEFN_P13_A2a_Singularity_Arrival_Port_Ownership_20261127.md), [CB-215](Architecture_M6_CP3_CB215_P13_Singularity_Ray_Classes_Code_Build_Record_20261127.md), [CB-216](Architecture_M6_CP3_CB216_P13_Singularity_Arrival_Classification_Code_Build_Record_20261127.md) and [TB-REV-191](Architecture_M6_CP3_TB_REV_191_Region_Boundary_Schedule_Independent_Review_20261127.md) govern this review.

| Authority | Verified identity |
|---|---|
| Source snapshot | `207f4afe43de9c97e6b305e72ec9cf009d5895ae`, run 45999459976, job 140507202583, artifact 15197905746, ZIP SHA-256 `1f7f7c91d7800c7eed8da12d868bc8af88f26467f0ca8b0e5f54b26d3c17840f`; source archive `31e197b96687bdce5beb9a71509793d0d4bdbd35bd01448cc3e7720ab6a2debd`; 5891/5891 checks. |
| CB-216 candidate | Source/executor `c76e74b35ffa5ba6aa1f3f8662f592e077c63033`, compile run 45986095420, artifact 15192246171, ZIP `e92edf8686722ac4ec96dc07217e7a13923d8786cf89dc6d513793aac381b004`; 28/28 checks, source archive `d8cdcf38a1886bb0ed494d958e7f52f04c4aa22ceca25da791135befae5c5ce4`; six executable mode receipts, five empty source-status receipts, eight GNU Multiple Precision (GMP/GMPXX) targets, runtimeExecution=false. |
| TB192 | Run 45992751511, job 140484678308, attempt1, artifact 15195820651, ZIP `37bd0d7c8ba3abe1f3f1c74c0140903b9e880bf537e38982111621c472aea0ce`; 2028/2028 checks. |
| TB191 comparison | Result 15179335926, ZIP `bab546af9cc089db9deb405ede41b3dd859b9e4547f81507d669c58c911bb519`; 2024/2024 checks; candidate 15175464398, source `9ed5560822ae435e55101206dcb6ecda59bca706`. |
| Harness and wrapper | Harness SHA-256 `423f385b73c3825ce9fe18fbd5ca395287620475deb621389f0efbaa601e572c`; log 15194799175 ZIP `9a96a2705892e822165dc1bc8cfe58462aa9b1fdfbc1786ac5542709632bc4c4`; wrapper 15195358020 ZIP `ec07923655ae8f73a09e436111b7eaa17661cf2dcb90f043a47d6dc4fa8e09eb`; terminal exit0 and postflight true. |

The retained TB192 evidence archive passes all 16 checks; its enclosed result, reference and logs match the pinned ZIP digests. The candidate was downloaded separately. GitHub comparison confirms the source is an ancestor of the snapshot (20 ahead, 0 behind), only 12 documentation/control-plane paths differ. The 421 inspected product/header/test/benchmark/build files match the packaged source; all 54 selectors, 97 gate files and 68 tools match byte-for-byte. No executable ran in this review.

## Assessment

### Independent verification of the exact gate

Recalculate all manifest hashes from bytes. Current 1010-row manifest `c9f6325eee41ebead3d516d3bfcbef3141c9dee8c7051cef1e08ad146f60e9f5`; header and rows 1–1008 `ca16b66da3cb52e77a3540c79f9357e3e9e59b211bae872f87d58f60c4434081`; header and rows 1–1006 `a9b8083269ebd0786f0584d66c1f89f43362d884840ab95b95c3d0fa59ca0587`; CP2 header and rows 1–491 `483f11016d1f51049921aed879c2b23f523d045efc1a2833889a12bb9852a038`. Deferred ledger `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce` remains 81 disjoint identities. Membership: 1000 GUARD + 10 POSITIVE + 81 deferred = 1091, compared with 1089 for TB191. All 1010 and all 1008 comparator rows match ordered identities, executable, exact filter, actual test RUN, OK and PASS, resource command and exit0, raw log digest, ledger verdict and execution-boundary counters. Current ordered harness receipts agree. No duplicate, missing, skipped, RED, unexpected pass or abnormal result. The accepted gate prefix is unchanged.

Independent comparison of the 1007 inherited rows other than 858 gives 770 byte-identical, 237 only N1/N2 (anchored GoogleTest duration fields and CRLF conversion). No N3 required. All inherited non-hash ledger fields match. Negative normalizer controls preserve semantic text, numbers and filters. Named controls 393,648,669,843,844,963,968,971,972,978,979,1006 match under N1/N2; 1005 exactly. Row1003 N1/N2; 1007 and 1008 exact. An initial checker condition for comparator identity was too permissive; corrected to require its exact candidate and source and reran the complete check. No gate bytes changed.

Both frozen diffs replay in reverse and forward on copies of the six packaged postimages: CB-215 `e6176e8f0a12eccb191356e57819eb4c22402e7e28ff84b6e6dffdc5aeb44e83`; CB-216 `d6e980a89dc6bdc47569e81dabffb763b645d60023f542d6f9d24dac2f664bfa`. Every preimage, intermediate image and final image hash matches the manifest. The only classifier callers are `tests/FieldAlignedCurveNetworkTests.cpp:24265` and `tests/SurfaceCellTracingDisplayTests.cpp:506`; no production reader exists. `SurfaceCellTracing.cpp:6677` validates atlas identity, uses the last exact piece, chooses edge-supported attachment before on-edge ray before straddled class, else matches the opposite face-interior branch. `portTraced` checks candidate trace membership. The pinned sphere class selection is unique by the older evidence; generic ambiguous inputs are not proved by these fixtures. The zero-segment skip is not exercised; the inspected tracing paths commit a segment/proposal before assigning a terminal singularity. No generic coverage claim.

### Row858 — independently derive the ten arrivals

The exact previous prefix through the genus schedule summary is 78276 bytes, SHA-256 `aa702e385156ccec02bd52de7fa936f40342d1d474aaf3bcc3241beaa09a9888`. The exact 12 appended lines hash to `04511fa7e6ab0a532e8b470033acee5122db736f0162d21ac076410fa2a94344`; the suffix matches under N1/N2. Derive eight nodes and 24 two-ray classes from TB191 partition/incidence records and ten arrivals from the final committed slide carrier, independently of the new classifier. For each edge there is exactly one class at the target node whose two distinct faces contain that edge. Each new matched port lies in the target node's three-port range; all ten ports are distinct, including those sharing nodes. The frozen prediction did not specify a unique numerical slot oracle. All ten have `portTraced=1`.

| Trace | Node | Radial edge | Reported port |
|---:|---:|---|---:|
| 0 | 1 | 6–8 | 4 |
| 1 | 2 | 16–21 | 6 |
| 9 | 1 | 8–9 | 3 |
| 10 | 7 | 49–62 | 23 |
| 11 | 2 | 20–21 | 7 |
| 12 | 6 | 40–45 | 19 |
| 13 | 5 | 32–34 | 15 |
| 14 | 0 | 0–69 | 2 |
| 21 | 5 | 33–34 | 16 |
| 22 | 6 | 45–46 | 18 |

The genus_two summary reports zero arrivals. This is not a positive genus arrival or face-interior/null-port witness. The original O51 falsifier (no arrival carrier matching an existing port trace) is contradicted. This does not prove the effects of removing any trace or demonstrate a completed surface-cell mesh.

### New guard rows and prior obligations

- Row1009 `FieldTransportAtlas.MechanicalSingularityRaysLieOnRadialEdgesAndNameTheirPortSlot`: 12 attachments and 12 rays, exact class/attachment/slot matching, stable sorted order, 12 explicit vertex/face/branch/radial-edge expectations. A missing, misbound or incorrectly supported ray fails. Raw log `8a035d4d1adbb3b101231f45975271bd0011ab5df2a4aef5883a3a2389d5c8c2`.
- Row1010 `FieldAlignedCurveNetwork.MechanicalRetraceArrivalsRealizeTheRemovedPortsSeparatrix`: requires an available classifier, one output for each terminal trace, matching trace and singularity identities, port/node and existing-trace membership checks; exactly four exact retrace owners are required. Each matches the previously recorded `arrivalPort`, uses radial approach and has `portTraced=false`. The test cannot pass with an empty classifier or no retraces. Raw log `848f023adf22e16b4e389022e25cc8fbc62f2d476102f6af2ead72b6b023960e`. These prove the pinned mechanical behavior, not partial co-trace removal.
- AP1–AP3 and the exact CB-215/216 evidence: discharged for the pinned diagnostic/test contract. AP4 remains undecided; AP5 and A4D5 carry to the corners definition after O51. DD1's 34 = 24 ports + 10 arrivals is corroborated; DD2's partial co-trace diagnosis corroborated, removal not proved; DD3 unchanged; DD4 resequencing retained; DD5 unequal-side construction remains scheduled. The earlier 1008-row boundary-schedule witness remains accepted and unactivated.
- BB1/BB3 and CC1–CC5 carry with their prior dispositions; BB2/B1 held, BB4 discharged, CB-213 remains withdrawn. O50 duplicate lookup remains until 65D; no third copy. Row971 contract discharged for the pinned witness only. B2 cause unmeasured; no V5 rerun (Cylinder PASS 288, Vase RED, BunnyRandom ABNORMAL 600 s). 65B reciprocal intervals, 65D per-disc dispatch, Amendment-19 flags, O41/switch remain open. CB-207C conditional, CB-207D, D6, J6/E5/CB-190 and parameter deletion → V3b → R1 → O48 held. No promotion of CP3/497/D0/H4. Stable events/categories/recurrences 67/17/50; debt1/deferred81. No new stable regression, cause or reclassification.

## Recommendation

Freeze exactly one successor, `M6-CP3-DEFN-P13-A2A-PARTIAL-COTRACE-REMOVAL`, the already authorized AP4 behaviour definition. This name is assigned to that existing scope, not a new task. Do not start it in this turn. The successor must STOP for a user decision before freezing new normative DESIGN §7.2 step 7 text. D13=A remaps only exact retraces; if a partially co-traced trace is removed, another trace stopped at its divergent part can lose its contact. Compare option A (suppress the claimed port and re-trace to a fixed point), B (head-on, excluded by D13 Rule 3), C (keep both, violates invariant 1). Falsifiers: ambiguous or conflicting claims; a lost required port/contact; nonmonotonic suppression or no finite termination proof; unstable ownership or trace result under permitted invariance; a retained contact with no valid trace. Stop if the evidence cannot establish the owning stage or any of these obligations. No new normative choice, product change, build, runtime, V5, tiny-region collapse, fallback repair, dispatch/veto change or milestone promotion here. Freeze a later CB/TB/REV contract only in the authorized successor after the user decision.

Process limits: entry handoff read preceded the entry beacon; no repository mutation preceded it. Full preliminary policy/LESSONS read and exact historical tool-call accounting are not established. A local Git ownership warning and initially permissive comparator check were corrected. The verified source snapshot, independent static check and frozen gate evidence remain valid. The review boundary and remote closeout are distinct from technical acceptance.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | Exact 491, 1006 and 1008 prefixes; exact 1010 manifest, hashes above. |
| Decisive claims independently re-derived | 28/28 candidate, 2028/2028 current, 2024/2024 prior; 1010 and 1008 independent row verdicts, membership, inherited log comparison, row858 and both guards. |
| Non-vacuity checked | Exact diff replay and guard source paths, independent old slide/class identities, negative normalizer controls. No positive credit for unexercised paths. |
| Prior obligations discharged/carried | AP1–AP3 pinned contract discharged; AP4/AP5, DD1–DD5, A4D5, BB/CC, O50/O51, B1/B2 and held work as above. |
| Stable accounting | 67/17/50, debt1/deferred81; CP2 491/491, candidate 15192246171 and gate 1010 accepted for test only. |
| New candidates/obligations recorded | None; tracker carries O51 and original falsifier, names AP4 owner and repair limits. |
| ORIENTATION currency line | TB-REV-192 2026-11-27 UTC. |
| ORIENTATION §3 / §4 / §7 / §8 | Current test gate, arrival witness and priority updated; superseded CB-216 next bullet replaced; no new recurring pattern for §8. |
| CHANGELOG | Entry added. |
| ROADMAP | Accepted gate updated, no milestone transition. |
| Selector manifest | Acceptance metadata only, no selector or gate bytes changed. |
| LESSONS | Existing evidence/acceptance/scope and non-vacuity lessons apply; no new general lesson. |
| Consolidation under CLEAN_UP_POLICY | Superseded TB-EXEC-192 continuation folded into Vol D3 with original filename, exact content, hash, line count and repaired live link; current authorities retained. |
| Successor frozen | Exactly M6-CP3-DEFN-P13-A2A-PARTIAL-COTRACE-REMOVAL; falsifiers and stop rules above. |
| Turn boundary held | Runtime-free, no product/test/fixture/selector/benchmark/build mutation. |
| review_check.py boundary | Product, selector and durable presence checks pass on exact-byte local baseline. Four historical checks fail because archive has no Git history. Separate GitHub ancestry comparison establishes rewrite base `8b7299b43764a6ba3444e5bc774a2f1b65e99731` (8602 ahead, 0 behind); its historical protected headings independently fetched and preserved (handoff 4/4, orientation 1/1, tracker 0 required headings). |
| `STATUS` lifecycle maintained | Entry M6-CP3-TB-REV-192 at 2026-11-27T12:31:55Z; prior beacon complete. Resume timestamp empty. Final direct beacon is sole formal closeout authority; not part of this patch. |
| Pushed to origin, branch in sync | Local source is an archive, not a remote checkout; direct git status -sb cannot prove remote sync. Require exact remote application receipt and branch readback before final beacon. |
