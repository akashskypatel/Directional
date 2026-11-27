# TB-EXEC-189 — sphere route and completion input census (2026-11-27 UTC)

## Situation

The one immutable full gate executed successfully: 1006/1006 PASS. All comparison conditions pass. Row858 measures a negative display contract, not a produced sphere. BB1 is supported; BB3's disk prediction is false. No independent gate credit or production acceptance is assigned. Only TB-REV-189 follows formal execution closeout.

## Background

- [Exact manifest](gates/Architecture_M6_CP3_CB211R_CB212_TB189_Sphere_Route_Witness_Exact_Manifest.md); [CB-212 compile record](Architecture_M6_CP3_CB212_P13_Sphere_Completion_Input_Census_Code_Build_Record_20261127.md); [TB-REV-188 adversarial](Architecture_M6_CP3_TB_REV_188_Adversarial_Review_20261127.md). Source `39253c63c308a2699669095bdb12e4ece72d502a`, package `15170182914`, compile run `45934565154`. Candidate ZIP `51cbdd7c323aa6cc29d42afd16a2905c24420d04efa5c1ecfff853f5ed2a5ebf`, root manifest `b7aac97b934933f863ebc4f8f72b048f966f8850025113bb536e57539d6d8124`, archive `7c4194e692c13b0f897b974f95b18f292e60aba2746c3e8b1e8dcdc6ab73476a`, 28/28 checks and six executable modes 755 verified at entry. Executor `cc25a6402cdd3ca1a33a9a9778250176b182bb2a`, harness `423f385b73c3825ce9fe18fbd5ca395287620475deb621389f0efbaa601e572c`.
- [Run 45936843671](https://github.com/akashskypatel/Directional/actions/runs/45936843671), runtime job `140302018167`, attempt 1, dispatch `4605b75e3c04810e7fc9cd6c2297315c9a791d76`, request SHA-256 `39b585b31b0b2a70b206e106d424e1ce326a36d07cc35bb80349b4469ad91e20`. Mailbox `m6-cp3-tb189-exec` on `workflow-mailbox` matches source, event, request and artifact metadata. Both schema validators, parse, runtime and mailbox succeed; drive_apply, compile and noop skipped. Wrapper 03:54:57–04:11:17 UTC (980 s), exit0. One execution, no retry, V5 or local runtime.
- [Continuation record](M6_Consolidated_Record_Vol_D3_CP3_P13_from_20261109.md#tb189-execution-continuation-historical) records snapshot run `45936682612`, job `140301445280`, artifact `15170603088`, source `7e5cf68b50e3e876211eacfd33af511a917ed440`, ZIP `3fce894afc7f48757b149be29b47912d9b76128354123341ff945f6573687193`, 5875/5875 checks; cleanup run `45936974764`, commit `10aabd6e85338381e01ec132e8b85ffd30c93567`. Comparison to resume commit `035d093adf969a4e5f3477cb74a52f58f1dff520` shows only continuation record, dispatcher request, removed snapshot marker and STATUS changes; no intended document or semantic source changed.

## Assessment — execution and comparison

| Artifact | ID | ZIP SHA-256 |
|---|---|---|
| Result | 15171482516 | `9cf3decbf3dea3a11aa645ec5d5db12307508e73611f962d65c78862ec9b70da` |
| Harness log | 15171143285 | `6dd901111d919be5364f54a7a6ff8be778517ff203403aeeff5bec39f6075ddf` |
| Wrapper log | 15171586912 | `f321579127840554f6440b50f47d40ce05c3e9d99a34d40b55e2282c1fe9bbb2` |
| TB188 reference result | 15163822727 | `59957c5adbb95a5e5a90f1eada11f3aec60366ee3a8c22694edf8de799293780` |

All outer hashes match, exact ZIP inventory and 2020/2020 result checks. Manifest `a9b8083269ebd0786f0584d66c1f89f43362d884840ab95b95c3d0fa59ca0587`; header + CP2 prefix 491 `483f11016d1f51049921aed879c2b23f523d045efc1a2833889a12bb9852a038`; deferred `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce`. Membership 1087 = 1006 gated + 81 deferred across five binaries; exact set match and bytes equal TB188 `29f997463824520bb66544ac9b33830067013366328cb63e7ccc301bc40b54f9`. Ledger `593739b86139d1341d85740608cf6dec9915a08787c5670d61e5504277824310`; boundary `c10e026df2b6e1ff25967b3585d995ac829fea0452993335eedcb4901909c6b4`. All 1006 ordered manifest/ledger identities, raw hashes in both ledgers, single-test envelopes, resource exit0 and ordered harness receipts verified. CP2 491/491 PASS. Planned/executed/PASS 1006, zero RED/abnormal/missing/skipped/duplicate/control_bad/unexpected_pass/later_positive_red/red_site_bad; postflight true, exit0; configure, compile, relink and benchmark false.

All ledger fields except raw-log hashes match TB188. Among 1005 other rows: 655 byte-identical, 350 N1/N2 equal, zero N3-only and zero material differences. N1 removes only elapsed GoogleTest summary fields; N2 CRLF; N3 not needed because no off-row differences remain after N1/N2. Prior normalizer bytes were unavailable; an equivalent narrow N1/N2 comparison used positive elapsed/CRLF and negative semantic/non-summary controls. No new normalization or whitelist. All 13 named control rows match under N1/N2. Row858: exact byte prefix 69,446 through LF after SphereCompletionFailure, SHA-256 `68839fe0a5bc1ed0128e90cd9c96ab0ee55aaddb1c85f711494da0fa9d954266`; first 69,196 bytes match frozen SHA-256 `32d6de52259ed91a9968109bda21b68d3dc4d37a3b1aed7b59193301c61a42d9`. Raw TB189 SHA-256 `5edee978137edad1bb5c992a3b0724babcba1131873bafc5576afab074d329d5`; exactly 45 new lines in the frozen order, then N1/N2-equal suffix. No missing/extra receipt or unexpected material difference. Row858 PASS, exit0, GoogleTest 9.199 s. Previous negative completion failure string remains exact.

### Row858 — verbatim added receipt

```text
SphereRoute producerDisposition=NotApplicable phaseFront=NotApplicable uniformDeclined=0 periodicDeclined=0 boundedDiskDeclined=0 seeds=98 traces=392
SpherePlan retained=1 arcs=30 mandatory=0 trace=30 cut=0 regions=14 certificates=14
SpherePlanRegion region=0 boundaryArcs=4 walkNodes=4 repeatedArcs=0 missingArcs=0 mandatory=0 trace=4 cut=0 sourceFaces=46 disc=1 interiorSingularityFree=1 boundarySingularities=2
SpherePlanRegion region=1 boundaryArcs=6 walkNodes=6 repeatedArcs=0 missingArcs=0 mandatory=0 trace=6 cut=0 sourceFaces=14 disc=1 interiorSingularityFree=1 boundarySingularities=3
SpherePlanRegion region=2 boundaryArcs=4 walkNodes=4 repeatedArcs=0 missingArcs=0 mandatory=0 trace=4 cut=0 sourceFaces=16 disc=1 interiorSingularityFree=1 boundarySingularities=2
SpherePlanRegion region=3 boundaryArcs=4 walkNodes=4 repeatedArcs=0 missingArcs=0 mandatory=0 trace=4 cut=0 sourceFaces=46 disc=1 interiorSingularityFree=1 boundarySingularities=3
SpherePlanRegion region=4 boundaryArcs=4 walkNodes=4 repeatedArcs=0 missingArcs=0 mandatory=0 trace=4 cut=0 sourceFaces=16 disc=1 interiorSingularityFree=1 boundarySingularities=2
SpherePlanRegion region=5 boundaryArcs=3 walkNodes=3 repeatedArcs=0 missingArcs=0 mandatory=0 trace=3 cut=0 sourceFaces=16 disc=1 interiorSingularityFree=1 boundarySingularities=2
SpherePlanRegion region=6 boundaryArcs=5 walkNodes=5 repeatedArcs=0 missingArcs=0 mandatory=0 trace=5 cut=0 sourceFaces=14 disc=1 interiorSingularityFree=1 boundarySingularities=3
SpherePlanRegion region=7 boundaryArcs=4 walkNodes=4 repeatedArcs=0 missingArcs=0 mandatory=0 trace=4 cut=0 sourceFaces=32 disc=1 interiorSingularityFree=1 boundarySingularities=2
SpherePlanRegion region=8 boundaryArcs=4 walkNodes=4 repeatedArcs=0 missingArcs=0 mandatory=0 trace=4 cut=0 sourceFaces=46 disc=1 interiorSingularityFree=1 boundarySingularities=2
SpherePlanRegion region=9 boundaryArcs=4 walkNodes=4 repeatedArcs=0 missingArcs=0 mandatory=0 trace=4 cut=0 sourceFaces=53 disc=1 interiorSingularityFree=1 boundarySingularities=3
SpherePlanRegion region=10 boundaryArcs=3 walkNodes=3 repeatedArcs=0 missingArcs=0 mandatory=0 trace=3 cut=0 sourceFaces=9 disc=1 interiorSingularityFree=1 boundarySingularities=2
SpherePlanRegion region=11 boundaryArcs=5 walkNodes=5 repeatedArcs=0 missingArcs=0 mandatory=0 trace=5 cut=0 sourceFaces=14 disc=1 interiorSingularityFree=1 boundarySingularities=3
SpherePlanRegion region=12 boundaryArcs=4 walkNodes=4 repeatedArcs=0 missingArcs=0 mandatory=0 trace=4 cut=0 sourceFaces=32 disc=1 interiorSingularityFree=1 boundarySingularities=2
SpherePlanRegion region=13 boundaryArcs=6 walkNodes=6 repeatedArcs=0 missingArcs=0 mandatory=0 trace=6 cut=0 sourceFaces=14 disc=1 interiorSingularityFree=1 boundarySingularities=3
SphereCompletionInput complex=arrangement retained=1 nodes=973 halfedges=2038 cells=168 closed=168 disk=164 cutCellDisk=0 bridgeExcursion=4 supportOnlyCycle=0 multiCycle=0 oddBounded=68 repeatedNodeCells=4 sameCellTwinCells=4 diskWithRepeatedNode=0 invalidHalfedges=0
SphereCompletionInput complex=simplified retained=1 nodes=973 halfedges=2038 cells=168 closed=168 disk=164 cutCellDisk=0 bridgeExcursion=4 supportOnlyCycle=0 multiCycle=0 oddBounded=68 repeatedNodeCells=4 sameCellTwinCells=4 diskWithRepeatedNode=0 invalidHalfedges=0
SphereSimplification candidates=576 healingCandidates=12 committed=0 rejected=12 transactions=12 oddBeforeRepair=68
SphereCompletionAudit present=1 failure=repeated-boundary-node cell=164 halfedge=67 node=35 sourceFace=4
SphereAuditedInputCell cell=164 halfedges=154 distinctNodes=128 auditedNodeOccurrences=2 boundaryCycle=0 closed=1 disk=0 cutCellDisk=0 bridgeExcursion=1 supportOnlyCycle=0 components=1 cycleOffsets=1 euler=0 sameCellTwinHalfedges=48 region=0
SphereAuditedBridge halfedge=10 twin=11 from=3 to=7 family=0 layoutSupport=1 singularitySupport=1 hardFeature=0 sourceArc=1 curve=-1
SphereAuditedBridge halfedge=42 twin=43 from=7 to=17 family=0 layoutSupport=1 singularitySupport=1 hardFeature=0 sourceArc=2 curve=-1
SphereAuditedBridge halfedge=28 twin=29 from=17 to=18 family=0 layoutSupport=1 singularitySupport=1 hardFeature=0 sourceArc=3 curve=-1
SphereAuditedBridge halfedge=82 twin=83 from=18 to=34 family=0 layoutSupport=1 singularitySupport=1 hardFeature=0 sourceArc=4 curve=-1
SphereAuditedBridge halfedge=60 twin=61 from=34 to=35 family=0 layoutSupport=1 singularitySupport=1 hardFeature=0 sourceArc=5 curve=-1
SphereAuditedBridge halfedge=1710 twin=1711 from=824 to=828 family=0 layoutSupport=1 singularitySupport=1 hardFeature=0 sourceArc=105 curve=-1
SphereAuditedBridge halfedge=1788 twin=1789 from=828 to=860 family=0 layoutSupport=1 singularitySupport=1 hardFeature=0 sourceArc=106 curve=-1
SphereAuditedBridge halfedge=1780 twin=1781 from=860 to=861 family=0 layoutSupport=1 singularitySupport=1 hardFeature=0 sourceArc=107 curve=-1
SphereAuditedBridge halfedge=1868 twin=1869 from=861 to=898 family=0 layoutSupport=1 singularitySupport=1 hardFeature=0 sourceArc=108 curve=-1
SphereAuditedBridge halfedge=1862 twin=1863 from=898 to=899 family=0 layoutSupport=1 singularitySupport=1 hardFeature=0 sourceArc=109 curve=-1
SphereAuditedBridge halfedge=1954 twin=1955 from=899 to=937 family=0 layoutSupport=1 singularitySupport=1 hardFeature=0 sourceArc=110 curve=-1
SphereAuditedBridge halfedge=1942 twin=1943 from=937 to=938 family=0 layoutSupport=1 singularitySupport=1 hardFeature=0 sourceArc=111 curve=-1
SphereAuditedBridge halfedge=2034 twin=2035 from=970 to=931 family=0 layoutSupport=1 singularitySupport=1 hardFeature=0 sourceArc=33 curve=-1
SphereAuditedBridge halfedge=1926 twin=1927 from=931 to=932 family=0 layoutSupport=1 singularitySupport=1 hardFeature=0 sourceArc=34 curve=-1
SphereAuditedBridge halfedge=1938 twin=1939 from=932 to=891 family=0 layoutSupport=1 singularitySupport=1 hardFeature=0 sourceArc=35 curve=-1
SphereAuditedBridge halfedge=1840 twin=1841 from=891 to=892 family=0 layoutSupport=1 singularitySupport=1 hardFeature=0 sourceArc=36 curve=-1
SphereAuditedBridge halfedge=1856 twin=1857 from=892 to=897 family=0 layoutSupport=1 singularitySupport=1 hardFeature=0 sourceArc=37 curve=-1
SphereAuditedBridge halfedge=1678 twin=1679 from=816 to=792 family=1 layoutSupport=1 singularitySupport=1 hardFeature=0 sourceArc=89 curve=-1
SphereAuditedBridge halfedge=1618 twin=1619 from=792 to=784 family=1 layoutSupport=1 singularitySupport=1 hardFeature=0 sourceArc=90 curve=-1
SphereAuditedBridge halfedge=1600 twin=1601 from=784 to=756 family=1 layoutSupport=1 singularitySupport=1 hardFeature=0 sourceArc=91 curve=-1
SphereAuditedBridge halfedge=1544 twin=1545 from=756 to=751 family=1 layoutSupport=1 singularitySupport=1 hardFeature=0 sourceArc=92 curve=-1
SphereAuditedBridge halfedge=1532 twin=1533 from=751 to=718 family=1 layoutSupport=1 singularitySupport=1 hardFeature=0 sourceArc=93 curve=-1
SphereAuditedBridge halfedge=1464 twin=1465 from=718 to=708 family=1 layoutSupport=1 singularitySupport=1 hardFeature=0 sourceArc=94 curve=-1
SphereAuditedBridge halfedge=1438 twin=1439 from=708 to=709 family=1 layoutSupport=1 singularitySupport=1 hardFeature=0 sourceArc=95 curve=-1
```

### Frozen predictions and evidence boundary

| Prediction | Measured result |
|---|---|
| BB1: NotApplicable outcome/disposition, three decline flags 0 | Matches; 98 seeds, 392 traces. Whole-surface legacy fallback, not authoritative A4 regional construction. |
| Retained plan with 14 regions | Matches: 30 trace arcs, 14 certificates; each region reports simple arc walk, disc certificate, no interior singularity, 2 or 3 boundary singularities. Source-face counts are per region, not a disjoint face-row partition. |
| B1: repeated-boundary-node audit and at least two original node occurrences | Matches: typed `RepeatedBoundaryNode` serialized `repeated-boundary-node`, cell164, halfedge67, node35, sourceFace4; audited node occurs twice in retained simplified input. |
| BB3: audited cell disk=1 and cut-cell disk or same-cell twins | **Falsified**: disk=0, cutCellDisk=0, bridgeExcursion=1, one boundary component/cycle offset, Euler0, 48 same-cell twin halfedges (24 distinct pairs). A false prediction is not a gate failure. |

The two census records have the same aggregate counts: 973 nodes, 2038 halfedges, 168 closed cells; 164 disks, four bridge excursions, four repeated-node cells and four same-cell twin cells; zero cut-cell disks, multi-cycle, support-only cycles, disks with repeated nodes or invalid halfedges. 68 odd bounded cells. Simplification records 576 candidates, 12 healing candidates, zero commits, 12 rejects and 12 transactions. This does not prove byte-identical complexes. Cell164 has 154 halfedges and 128 distinct nodes. All 24 listed bridge pairs carry layoutSupport=1, singularitySupport=1, hardFeature=0, curve=-1. The optional bridge-healing filter excludes singularity support (`src/geometry/SurfaceComplexSimplification.cpp:1587–1594`); this supports the ineligibility of the reported bridge edges, not the cause of each of the 12 rejected transactions. The parity rebuild requires simple boundaries even though it admits non-disk incidence (TB-REV-188 BB3). The owner of the fallback's bad input remains unadjudicated. The three aggregate decline flags do not identify individual A4 producer reasons. The unresolved question remains A4 coverage of the certified plan; do not repair fallback or increase parity budget from this evidence.

Stable accounting remains 67/17/50, debt1/deferred81. No accepted-green loss and no new stable regression event. B1 remains a measured non-stable fallback contract mismatch; B2 BunnyRandom cost candidate and close_sheets fine-resolution evidence remain unchanged. TB188 independently accepted 1006/1006; TB189 is an executed candidate awaiting independent review. No CP3/497/D0/H4 promotion.

## Recommendation — TB-REV-189 only after execution closeout

Independently verify the full gate, all raw logs, 45 added lines and receipt producers. Adjudicate BB1 and the falsified BB3. If upheld, the existing review sequence calls for an exact per-region A4 decline receipt, then a definition decision on A4 ownership of closed-surface discs with boundary singularities and the DESIGN section 5.2 fallback. B2 remains a later bounded observation. No B1 repair, V5 execution, CB-207D, activation or parity change, parameter deletion, J6/E5/CB-190. No successor work executed in this turn.

Process limits: prior attempt's policy-review and tool-ledger limitations remain in its continuation record. The retained verified snapshot was reused after checking the exact remote path diff. N3 was not needed; no prior normalizer recovery is claimed. Full historical-policy review is not established. No PR metadata, protected policy or product change. The document drift audit is a local structural check, not independent acceptance.
