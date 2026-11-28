# TB-EXEC-194 — Co-trace deletion switch execution (2026-11-28 UTC)

## Situation

`M6-CP3-TB-EXEC-194` executed the full frozen gate once on the immutable CB-219 package. All 1013 tests PASS, but two row858 predictions do not match. **STOP for independent review; not accepted.** No source, fixture, test, selector, manifest, design or build-system change. No repair, rerun or V5. Root STATUS governs formal closeout. Next `M6-CP3-TB-REV-194`, not the corners DEFN.

## Background — exact authority

- [Frozen manifest](gates/Architecture_M6_CP3_CB219_TB194_CoTrace_Deletion_Switch_Exact_Manifest.md); [CB-219 compile record](Architecture_M6_CP3_CB219_P13_CoTrace_Deletion_Switch_Code_Build_Record_20261128.md); [switch DEFN](Architecture_M6_CP3_DEFN_P13_A2a_CoTrace_Deletion_Switch_20261128.md). CB-219 defaults claimed co-trace deletion on; tracing-loop controls stay off.
- Source and executor `26eef1ce54b7b311cbf1cedf597ee0c106be52c2`; candidate `15252943713`, ZIP `b12b9ede5678f6d8942559e821c134c602b6ba7446b6a338152573f4cb722f35`, root SHA256SUMS `78482f7f1e34b05cab1038d18c3e3fd767d9e3125b5a5a695e740bcf413a8e68`, source archive `bc32deb11ed5487a986fd8ad98de48b064493ce7674d172ea3d208ad2b8353f2`. 28/28 checks, compile-only, executable archive modes, clean source status and GMP/GMPXX linkage verified at entry.
- Harness `tools/m6_cp3_targeted_artifact_harness.sh`, SHA-256 `423f385b73c3825ce9fe18fbd5ca395287620475deb621389f0efbaa601e572c`; [1013-row manifest](gates/Architecture_M6_CP3_CB217_CB218_TB193_CoTrace_Deletion_Full_Gate_Case_Manifest.tsv) `b910f2a96626660f46042c34360a8062c7546f35fb1980432d038ba8f41d2fc2`; [81-row deferred ledger](gates/Architecture_M6_CP3_RP01_Off_Gate_Deferred_Ledger_v5.tsv) `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce`. The 29 listed exceptions leave 984 other rows, not the manifest's 983; no extra exception granted.
- Dispatch `ac78d06e6104aa54dc29a7a48647dd29e771327e`, request SHA-256 `022581a1e199753a57779a22852af6cd993a9bbd5ae38341e2982b7331023e29`, key `m6-cp3-tb194-exec`. [Run 46122222893](https://github.com/akashskypatel/Directional/actions/runs/46122222893), attempt1, runtime job `140909114140`, mailbox job `140912983893`; both validators, parse, runtime and mailbox success; compile/drive_apply/noop skipped. Mailbox event/source match; published 2026-11-28T07:57:32Z.
- Snapshot `7940deca1dbb490a0ac948bcab44ad00b97a2379`, run `46122143642`, job `140908804235`, artifact `15254311759`, ZIP `f71c3235f2ea62006e8c98fa8c4f6fe0c8af4e509bf01943ab7bd73a24388165`, 5905/5905 checks. Cleanup run `46122369951`, receipt `15253543819`, ZIP `883696cdba12a0f322d20a430e4b60fb0e706d6d40c1ab3ea9eea629280bf4c2`, commit `68475580f9213e4868ff0ab8652a4cdf205e1b7b`; temporary marker removed, zero PR comments deleted. Snapshot reused: comparison to resume commit `da16fab1813b761b7f8015a79f8f04409e365ac5` reports only STATUS, dispatcher request and removed marker.

## Assessment — immutable result

| Artifact | ID | SHA-256 |
|---|---|---|
| TB194 result | `15255025606` | `5fedd54ddf3416bf1cdb475a8e53206ab6382fcd75e9ea8b4a3bfebb4f8d99b4` |
| TB194 harness log (mailbox inventory) | `15254552087` | `aa72cebed3b5dad3a0dd3b97f8434a3f0526cebe30768ec200d6133120b094ba` |
| TB194 wrapper log (mailbox inventory) | `15254279427` | `86550c810f27252d94d0a7237f265055e81be1c0d4ab6a2afaf9f61c0913c041` |
| TB193 comparator result | `15250401219` | `c771dab68abfd32a57e66cb236d5a8d618c124cb3040d0e388e12eb9614daa7b` |

Both result ZIPs and 2034 entries in each SHA256SUMS verified; no missing, mismatched, uncovered or extra files. TB194 result size 1,852,251 bytes, expiry 2026-12-12T07:57:02Z. Result names candidate 15252943713 and source 26eef1ce54b7b311cbf1cedf597ee0c106be52c2. Ledger `bc0f3bc264a3ea43e5f190b25f98f36fdaeb96bd09a6ec17eae5b5a23a8056a4`, membership `e33c542701654a2bf472f1ae172be627ff356a680498202b47a9988cfad97dbd`, boundary `f8de045090769d43d5a3518b1eff8d969b242a9a4ac61c29cd744480fb75b8e5`, root manifest `f27cd5a63627942d41e1b3eb523403ff6652de2d3fc3714af70f35ac6589f33d`.

- Ordered manifest/ledger identities, single-test RUN/OK/PASSED envelopes, all raw-log digests and resource filter/exit receipts match. 1003 GUARD + 10 POSITIVE; 1013/1013 PASS; one test per row, exit0, no first failure. Membership byte-equal to TB193, exact disjoint pairs: 1013 GATED + 81 DEFERRED = 1094.
- Planned/executed/passed1013; red, abnormal, missing, skipped, duplicate, control_bad, unexpected_pass, later_positive_red, red_site_bad all 0; postflight true, exit0. Configure, compile, relink and benchmark false.
- All non-hash ledger fields equal TB193. Normalize only GoogleTest elapsed summary fields (N1), CRLF (N2), and complete `M3_CP4AB_FRAGMENT_DIAG record=region_support_projection` record multiset with residual order unchanged (N3). 591 byte-equal, 392 N1/N2, 1 N3 (row164, six complete records reordered), 29 materially changed. Exact changed rows: 380, 388, 393, 394, 396, 397, 644, 645, 648, 669, 686, 691, 693, 694, 698, 699, 700, 843, 844, 858, 963, 968, 971, 972, 978, 979, 1006, 1012, 1013. All 984 other rows N1–N3 equal, including 1010/1011 (N1/N2). Local comparison is execution evidence, not independent review.
- No typed `CoTraceDeletion...` condition printed; the only matching strings in 1012/1013 are GoogleTest test names. Downstream assertions in 648, 971, 972, 979 PASS. This does not prove all frozen predictions.
- Sum of 1013 per-process wall receipts 990.07 s (TB193 1527.07 s); peak RSS 91,236 KiB (row899; TB193 91,224 KiB, same row). Not a controlled performance comparison. No V5 or production resource claim.

### Row858 — frozen prediction verdicts

Raw TB193 `30443aab1fee1fc8b4c64eb658cf7db84532271c32a35d7211f2d984e2bfb287`; TB194 `cff825fdb84885fb9c54389b389dde882060247bab99be351199989af3707c63`. Row PASS; GoogleTest 9139 ms (TB193 13819 ms).

| Prediction | Result |
|---|---|
| 10 classified radial-edge arrivals, 10 matched, zero portTraced, same trace/node/edge/port | MATCH, all ten lines exact except portTraced=0 |
| Plan retained, arcs18, mandatory0, trace18, cut0, regions8, certificates8 | MATCH |
| Boundary schedules built, regions8, sides36, arcs18, paired18, other0 | MATCH |
| Eight side-count multisets | **MISMATCH**, four schedules differ |
| Atlas partition and tracing records | MATCH, partition 244, slideProposal 30, slideCoincidence 12, slideContactArrival 12, entryCoincidence 6, committedSlide 30 exact lines each |
| SphereRoute, SphereSimplification, SphereCompletion*, SphereAudited*, SphereDisplayStop*, Genus* | MATCH, 1, 1, 4, 25, 2, 2 exact lines respectively |
| M3_CP4AB_FRAGMENT_DIAG unchanged | **MISMATCH**, 56 → 44 complete projection lines; first 28 exactly equal; two copies of 14 region records become two copies of 8; multiset intersection 32 lines. N3 cannot normalize missing/changed content. |
| SpherePlanRegion | Measured below |

Two expected copies of `{30,32,35,37}` and two of `{1,1,30,30,35,37}` are absent. Instead there are two additional copies of `{30,32,35,35}` and two of `{1,1,30,30,35,35}`. Measured regions 0,3,5,6 are four-sided with counts {30,32,35,35}; regions 1,7 are six-sided with counts {1,1,30,30,35,35}. Slivers 2,4 remain {1,1,32,32}. Boundary sums 132 except slivers at 66, all positive and even. Not an ID-order issue.

The last two projection groups reduce in number with the plan. This is a measured association, not proof of the cause or authorization to waive equality. Both discrepancies require review of prediction derivation versus implementation. No newly classified stable regression. Do not change the frozen contract in this execution turn.

Verbatim plan, schedule and arrival receipts:

```text
SpherePlan retained=1 arcs=18 mandatory=0 trace=18 cut=0 regions=8 certificates=8
SpherePlanRegion region=0 boundaryArcs=4 walkNodes=4 repeatedArcs=0 missingArcs=0 mandatory=0 trace=4 cut=0 sourceFaces=53 disc=1 interiorSingularityFree=1 boundarySingularities=3
SpherePlanRegion region=1 boundaryArcs=6 walkNodes=6 repeatedArcs=0 missingArcs=0 mandatory=0 trace=6 cut=0 sourceFaces=32 disc=1 interiorSingularityFree=1 boundarySingularities=4
SpherePlanRegion region=2 boundaryArcs=4 walkNodes=4 repeatedArcs=0 missingArcs=0 mandatory=0 trace=4 cut=0 sourceFaces=16 disc=1 interiorSingularityFree=1 boundarySingularities=2
SpherePlanRegion region=3 boundaryArcs=4 walkNodes=4 repeatedArcs=0 missingArcs=0 mandatory=0 trace=4 cut=0 sourceFaces=46 disc=1 interiorSingularityFree=1 boundarySingularities=3
SpherePlanRegion region=4 boundaryArcs=4 walkNodes=4 repeatedArcs=0 missingArcs=0 mandatory=0 trace=4 cut=0 sourceFaces=16 disc=1 interiorSingularityFree=1 boundarySingularities=2
SpherePlanRegion region=5 boundaryArcs=4 walkNodes=4 repeatedArcs=0 missingArcs=0 mandatory=0 trace=4 cut=0 sourceFaces=46 disc=1 interiorSingularityFree=1 boundarySingularities=3
SpherePlanRegion region=6 boundaryArcs=4 walkNodes=4 repeatedArcs=0 missingArcs=0 mandatory=0 trace=4 cut=0 sourceFaces=53 disc=1 interiorSingularityFree=1 boundarySingularities=3
SpherePlanRegion region=7 boundaryArcs=6 walkNodes=6 repeatedArcs=0 missingArcs=0 mandatory=0 trace=6 cut=0 sourceFaces=32 disc=1 interiorSingularityFree=1 boundarySingularities=4
SphereRegionBoundarySchedules built=1 regions=8 sides=36 arcs=18 pairedArcs=18 otherArcs=0
SphereRegionBoundarySchedule region=0 sides=4 boundaryCount=132 even=1 counts=30,35,35,32, nodes=8,0,4,5,
SphereRegionBoundarySchedule region=1 sides=6 boundaryCount=132 even=1 counts=30,1,35,35,1,30, nodes=0,8,1,3,2,9,
SphereRegionBoundarySchedule region=2 sides=4 boundaryCount=66 even=1 counts=1,32,1,32, nodes=1,8,5,10,
SphereRegionBoundarySchedule region=3 sides=4 boundaryCount=132 even=1 counts=30,32,35,35, nodes=0,9,6,4,
SphereRegionBoundarySchedule region=4 sides=4 boundaryCount=66 even=1 counts=1,32,1,32, nodes=9,2,11,6,
SphereRegionBoundarySchedule region=5 sides=4 boundaryCount=132 even=1 counts=32,30,35,35, nodes=1,10,7,3,
SphereRegionBoundarySchedule region=6 sides=4 boundaryCount=132 even=1 counts=32,35,35,30, nodes=11,2,3,7,
SphereRegionBoundarySchedule region=7 sides=6 boundaryCount=132 even=1 counts=35,1,30,30,1,35, nodes=4,6,11,7,10,5,
SphereSingularityArrivals classified=1 arrivals=10 radialEdge=10 faceInterior=0 matched=10 portTraced=0
SphereSingularityArrival trace=0 node=1 approach=radial-edge edge=6-8 port=4 portTraced=0
SphereSingularityArrival trace=1 node=2 approach=radial-edge edge=16-21 port=6 portTraced=0
SphereSingularityArrival trace=9 node=1 approach=radial-edge edge=8-9 port=3 portTraced=0
SphereSingularityArrival trace=10 node=7 approach=radial-edge edge=49-62 port=23 portTraced=0
SphereSingularityArrival trace=11 node=2 approach=radial-edge edge=20-21 port=7 portTraced=0
SphereSingularityArrival trace=12 node=6 approach=radial-edge edge=40-45 port=19 portTraced=0
SphereSingularityArrival trace=13 node=5 approach=radial-edge edge=32-34 port=15 portTraced=0
SphereSingularityArrival trace=14 node=0 approach=radial-edge edge=0-69 port=2 portTraced=0
SphereSingularityArrival trace=21 node=5 approach=radial-edge edge=33-34 port=16 portTraced=0
SphereSingularityArrival trace=22 node=6 approach=radial-edge edge=45-46 port=18 portTraced=0
```

### Other frozen measurements

| Row | TB193 → TB194 |
|---|---|
| 644 (sphere source-edge barrier proxy) | V/E/F81/109/30 → 76/94/20; producer network V/E18/30 → 12/18; re-derived proxy F30 → 20, chi18 → 14; actual certificate V/E/F18/30/14 → 12/18/8, chi2; no cut edges, both success. Proxy is not the cellularity oracle. |
| 645 (sphere diagnostic barrier complex) | V/E/F81/109/30 → 76/94/20; 30 → 20 disk components, chi2, all disks; traces24 → 14, events56 → 40; terminal NotProductionReady / completion unchanged. |
| 686 (actual embedded graph oracle) | V/E/F18/30/14 → 12/18/8, chi2, no crossing nodes/arcs, all producer difference fields zero; MATCH. |
| 698 (A2a outcome) | networkTraceCount24 → 14; TraceIntersection10 → 4; SingularityTermination10 → 10; networkEventCount56 → 40; MATCH. |

Rows1012/1013 raw SHA-256 respectively `465c664f2eebbcb537533a76dbf5e6d8717fffa5e878f2ee173df70eeb400bc5`, `5af3b00e0bcd68b00ac5e178c153c8cbcb3d7044c3a4a4e23d382dd13fd9eee5`; both PASS. The deletion witness agrees with 14 traces and eight regions, but the full activation contract is not satisfied.

## Recommendation

`M6-CP3-TB-REV-194` must independently re-open the candidate, TB194 and TB193, reproduce all comparison classes and frozen verdicts, then adjudicate the two mismatches. Determine whether each follows from a wrong prediction (schedule subdivision rule or plan-versus-fallback receipt scope) or a producer defect. Do not change the plan or grant acceptance here. O51 remains open; O52 slivers2/4 and O50 open, B1 held, B2 unmeasured. CP2 491/491, stable 67/17/50, debt1/deferred81 unchanged. No CP3/497/D0/H4 promotion, production acceptance or certified sphere. No corners DEFN until review disposition. No successor work in this execution turn.
