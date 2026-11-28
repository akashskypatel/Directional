# M6-CP3-TB-REV-191 — independent review (2026-11-27 UTC)

## Situation

Accept the frozen 1008-row test gate only. The two new guard tests and the appended schedule witness meet the contract. Do not accept a completed sphere, activate the schedule, or promote M6 CP3. CP2 remains 491/491.

## Background

The [execution report](Architecture_M6_CP3_TB191_Region_Boundary_Schedule_Execution_Report_20261127.md), [compile record](Architecture_M6_CP3_CB214_P13_Region_Boundary_Schedule_Code_Build_Record_20261127.md), [frozen manifest](gates/Architecture_M6_CP3_CB214_TB191_Region_Boundary_Schedule_Exact_Manifest.md) and [DEFN-65C](Architecture_M6_CP3_DEFN_P13_A4_Disc_Domain_Construction_20261127.md) govern this review. The source snapshot is `d1be6c5b3f31f61248e8971c914c63b4a937e363`, run 45960143459, artifact 15180816411, ZIP SHA-256 `bb36a31002e8fb7d8105b6909b1f755d3bcdd412ce9da97578b334ed2043b07b`, 5884/5884 file checks. The compile source and executor are `9ed5560822ae435e55101206dcb6ecda59bca706`. GitHub reports this source as an ancestor of the snapshot (20 commits ahead, zero behind); all changes are documentation/control-plane changes. Independent byte comparison also confirms 420 source/header/test/benchmark/build files, all 54 selectors, 95 gate files and 68 tools match the package source.

| Evidence | Identity and verified digest (SHA-256) |
|---|---|
| CB-214 compile | Run 45949296543, job 140341297952, artifact 15175464398; ZIP `d53298314ab80c89e2fd9e8891b8883b798f4d6e9029acf5e3b177070eba108b`, 28/28 file checks; eight GMP/GMPXX targets; five empty source-status receipts; `runtimeExecution=false`. |
| TB-EXEC-191 | Run 45954607872, job 140358236355, artifact 15179335926; ZIP `bab546af9cc089db9deb405ede41b3dd859b9e4547f81507d669c58c911bb519`, 2024/2024 file checks. |
| TB-EXEC-189 reference | Artifact 15171482516, ZIP `9cf3decbf3dea3a11aa645ec5d5db12307508e73611f962d65c78862ec9b70da`, 2020/2020 checks. |
| Candidate package manifest/source archive | `eafa93881c9bfb5e5add286d616a7ec3af1b2d181945a0fba35138109e04ebb9` / `819b4dbf457c575430dc271edd2e3536ae957445c8ce4c4cd093bdf8e9c98236`. |
| Harness and terminal logs | Harness `423f385b73c3825ce9fe18fbd5ca395287620475deb621389f0efbaa601e572c`; artifact 15179440341 ZIP `af88f6bd402065cde9d4ef1ad5b4699e42319da5ed8697e7e0f78a401d8cb14b`; wrapper 15178519098 ZIP `cfac2654e344b7eccf56992d0ff1b2d5c17a8ce9d0cc570ce2e0f308af705d1b`. Source/executor match; exit 0, final job success, postflight true. No rebuild, configuration, relink, benchmark or retry. |

## Assessment

### Exact authority and independent gate checks

Recompute the hashes from the downloaded bytes, not from the execution report. The frozen 1008-row manifest hashes to `ca16b66da3cb52e77a3540c79f9357e3e9e59b211bae872f87d58f60c4434081`; its header plus rows 1–1006 hash to `a9b8083269ebd0786f0584d66c1f89f43362d884840ab95b95c3d0fa59ca0587`; the header plus the accepted CP2 491 rows hash to `483f11016d1f51049921aed879c2b23f523d045efc1a2833889a12bb9852a038`. The unchanged 81 deferred entries hash to `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce`. The membership file hashes to `90ce5fa167e39655c37ca19d865d31bfa546b830c8f2e69a4a7daf6dd76576aa`. Reconcile exact identities: 998 GUARD + 10 POSITIVE = 1008 gated; 81 deferred, disjoint, total 1089. For each of the 1008 rows, independently check the ordered identity, executable/filter, resource exit code, raw log digest, one actual test RUN and one PASS, and the ledger verdict. No missing, skipped, duplicate, RED, abnormal or unexpected outcome. The result ledger hashes to `781d9a2d5e915f023d8ddc0457445e98f1e160b7a2a272e311c4c607791ef985`; execution-boundary JSON `043330cdff0552a6e68ce331718b19a7fe4fe891cd8f909f0a15adda65d85ebc` confirms the artifact-only boundary. The same checks on the prior package give 1006/1006 and membership 1087.

Of the 1006 inherited raw logs, 766 match byte-for-byte, 239 match after only N1/N2 (test duration and line ending), and row858 alone has the authorized addition. N3 is not necessary. All inherited non-hash ledger fields match. The independent normalizer distinguishes timing/line-ending changes from semantic text, numeric and filter changes. All 13 named controls match: row1005 exactly; rows393,648,669,843,844,963,968,971,972,978,979,1006 under N1/N2. An initial offline checker assumption that every asserted site was `-` was wrong for the authorized POSITIVE row216; the checker was corrected to require the exact manifest annotation and the full independent check rerun. No test, gate or product was edited.

The frozen diff SHA-256 is `0fc97ddc4ac033281a1bc6c8ce9eafd379e89a888f5906ccf3c74a1f59b8c02b`. On copies of the four postimages, reverse apply check, reverse replay, all four preimage hashes, forward apply check, forward replay and all four postimage hashes pass. The diff is +316/−0. The only helper call sites are in `GlobalConformityBaselineTests.cpp` and `SurfaceCellTracingDisplayTests.cpp`; no production caller exists. Display assertions are unchanged. The code review of `GlobalConformityBaseline.cpp:862–943` confirms digest validation, binding to the exact support slice, orientation and incidence selection, and one count per occurrence. No repair of A2b or A3 occurs.

### Row858 and the two new GUARD rows

The exact 76578-byte TB189 prefix, including all 45 prior receipt lines, hashes to `a54805755d62dc9d691cc24d3f094a69f22c6a9453f6587885ad7609c80bdc74`. There are exactly 16 appended lines, hash `28655ca359437a061d182bc551b178a3e79cd79d8ffc5d7df72ac350fb1d3f09`; the remaining suffix matches under N1/N2. Current raw row858 SHA-256 `2a0611f283c8ab32c6356fdbb8d7a593f182222125d022e1d2cc5a64e43b5540`; prior `5edee978137edad1bb5c992a3b0724babcba1131873bafc5576afab074d329d5`.

| Region | Sides | Boundary count | Counts in walk order | Nodes in walk order |
|---:|---:|---:|---|---|
| 0 | 4 | 132 | 30,35,35,32 | 12,0,17,5 |
| 1 | 6 | 124 | 30,1,31,31,1,30 | 0,12,1,9,2,13 |
| 2 | 4 | 66 | 1,32,1,32 | 1,12,5,14 |
| 3 | 4 | 132 | 30,32,35,35 | 0,13,6,4 |
| 4 | 4 | 66 | 1,32,1,32 | 13,2,15,6 |
| 5 | 3 | 72 | 35,35,2 | 17,0,4 |
| 6 | 5 | 142 | 35,35,2,35,35 | 8,1,16,3,2 |
| 7 | 4 | 132 | 35,35,31,31 | 1,8,2,9 |
| 8 | 4 | 132 | 32,30,35,35 | 1,14,7,16 |
| 9 | 4 | 132 | 32,35,35,30 | 15,2,3,7 |
| 10 | 3 | 72 | 2,35,35 | 3,16,7 |
| 11 | 5 | 142 | 35,35,35,35,2 | 4,6,10,5,17 |
| 12 | 4 | 132 | 35,35,31,31 | 5,10,6,11 |
| 13 | 6 | 124 | 31,31,1,30,30,1 | 5,11,6,15,7,14 |

Re-derive 14 sphere regions, 60 side occurrences, 30 distinct unordered endpoint pairs, each twice with opposite direction and equal positive count. Every region sum matches the receipt and is even. Sum 1600 over occurrences, 800 over paired arcs. The source display also checks pairing by arc identity. Sphere summary: built=1, arcs=30, pairedArcs=30, otherArcs=0. Genus_two summary: built=1, regions=14, sides=184, arcs=92, pairedArcs=92, otherArcs=0. The latter is a measured aggregate from the display's arc-id pairing loop; the raw log has no per-region genus_two lines, so independent reconstruction of its individual arc pairs is not claimed. No `unavailable`, failed build, non-positive span or unpaired arc appears in these witnesses. All frozen row858 predictions match.

- Row1007, `GlobalConformityBaseline.RegionBoundarySchedulesBindEveryWalkOccurrenceToItsSpan`: a real square per-arc plan, exact region count, ordered span/arc identities, chain ordinal, incidence ordinal, continuity, positive span counts and parity. The test would fail if the schedule were empty or did not bind the walk. It does not prove the multi-arc chain route.
- Row1008, `GlobalConformityBaseline.RegionBoundarySchedulesRejectAnotherPlanOrAForeignSupport`: a different valid plan with the square baseline, then a foreign-support baseline. The two typed rejection reasons are distinct (`TopologyPlanMismatch`, `ArcNotScheduled`). The unreachable-on-validated-input `IncidenceNotFound` branch has no unit witness, as DEFN-65C explicitly states. Do not claim coverage of this branch or infer production activation.

### Prior obligations and remaining state

- CB-214 binding prediction and two GUARD rows: discharged for this exact gate. The helper is not a per-disc A4 producer. A4D1–A4D4 unchanged; A4D5 carried. Three-node regions 5 and 10 still falsify a regular straight-arc, node-only corner hypothesis under the stated assumptions. Even boundary counts do not resolve the hypothesis. 34 boundary-singularity incidences need a measured valence explanation.
- BB1/BB3: earlier actual fallback and non-disk cell164 bridge excursion remain established; no change to legacy fallback. B1 held under DESIGN §5.2, because fallback cannot be certified. BB2 remains held. BB4 discharged by the prior exact diagnostic slices. TB-REV-189 adversarial CC1–CC5 remain in force; CB-213 stays withdrawn, not a successor.
- B2: BunnyRandom runtime cause not established. No V5 rerun: Cylinder PASS 288, Vase RED, BunnyRandom ABNORMAL at 600 s. No timeout increase, no acceptance of the three-fixture gate. Row971 retains its pinned measured contract, not a new independent oracle. O50 duplicate lookup remains until 65D; no third copy. 65B reciprocal intervals, 65D per-disc dispatch, Amendment-19 flags, O41/switch remain open. CB-207C conditional; CB-207D, D6, J6/E5/CB-190, parameter deletion → V3b → R1 → O48 held. No CP3/497/D0/H4 promotion. Stable events/categories/recurrences 67/17/50, one produced-witness debt, 81 deferred. No accepted-green loss and no new regression classification.

## Recommendation

Freeze only `M6-CP3-DEFN-P13-A4-DISC-CORNERS` (definition/review, runtime-free). Scope: the corners portion of A4D2; use A4D5 and DESIGN §7.4, RA-237/238, row858 and the accepted gate. Define independent node and arc turning measurements, each port valence, and a gated Vase row. Distinguish the three A4D5 falsifiers (arc turns, invalid interiorSingularityFree, node turn greater than a quarter). Account for the 34 boundary-singularity incidences. Stop if the evidence cannot distinguish the alternatives or if the owning stage cannot be established. No implementation, execution, schedule activation, dispatch/veto change, fallback repair or milestone promotion in this definition turn. Freeze the exact later Code + Build and test contract in that successor, not this review. The name of the successor is assigned here to the previously authorized corners DEFN; no new scope is authorized.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | 491 and 1006 exact hashes above; 1008 manifest independently verified. |
| Decisive claims independently re-derived | 28/28 compile, 2024/2024 current, 2020/2020 prior; per-row identity/exit/hash/actual RUN/PASS; 1008 gate and membership; exact row858 prefix, receipts and normalized controls. |
| Non-vacuity checked | Two new guard source paths and distinct rejection reasons; exact reverse/forward replay; negative normalizer controls. No credit for absent production or unwitnessed branch. |
| Prior obligations discharged/carried | See assessment: binding discharged for pinned witnesses; BB/CC, B1/B2, O50, A4D5, 65B/65D, remaining held work carried. |
| Stable accounting | 67/17/50, debt1/deferred81; CP2 491/491; 1008/1008 test gate accepted only. |
| New candidates/obligations recorded | None; A4D5 owner named, tracker updated. |
| ORIENTATION currency line | TB-REV-191 2026-11-27 UTC. |
| ORIENTATION §3 / §4 / §7 / §8 | Update accepted test gate, witness and priority; no new recurring pattern for §8. |
| CHANGELOG | Entry added. |
| ROADMAP | Accepted gate updated, no milestone transition. |
| Selector manifest | Acceptance metadata only; no selector or gate bytes changed. |
| LESSONS | Existing evidence/acceptance/scope and non-vacuity/production-witness lessons apply; no new general lesson. |
| Consolidation under CLEAN_UP_POLICY | CB-211R, CB-212, TB-EXEC-189 and TB-REV-189 records folded into Vol D3; hashes, line counts, original source, and family index retained. Live links redirected. Current CB-214, TB191, manifest and definition remain. |
| Successor frozen | Only M6-CP3-DEFN-P13-A4-DISC-CORNERS; falsifiers and stop rules above. |
| Turn boundary held | Runtime-free; no product, test, fixture, selector, benchmark or build changes. |
| review_check.py boundary | Exact-byte local baseline: product, selector, durable presence checks pass; four remote-history checks cannot pass in an archive without Git history. GitHub comparison independently establishes rewrite base `8b7299b43764a6ba3444e5bc774a2f1b65e99731` ancestor (8552 ahead, zero behind); all four protected handoff headings and the protected ORIENTATION heading preserved, no protected tracker heading at base. |
| `STATUS` lifecycle maintained | Entry beacon written for TB-REV-191 because prior beacon was TB-EXEC-191 COMPLETE; final beacon requires verified closeout. |
| Pushed to origin, branch in sync | Require dispatcher result, exact patch verification and remote readback before final STATUS. Confirm in turn response. |

Procedure limitations: initial handoff/policy read preceded the entry write; subsequent semantic inspection used the verified snapshot. External turn-based coding skill was unavailable at the attempted repository path (404); local library skills and project policies govern. The complete preliminary reading sequence and precise tool ledger are not certified. No local compiler or project binary ran.
