# CB-219 exact manifest and TB-EXEC-194 contract (2026-11-28 UTC)

Authority:
- [switch DEFN](../Architecture_M6_CP3_DEFN_P13_A2a_CoTrace_Deletion_Switch_20261128.md) SW1–SW6;
- DESIGN §7.2.1 Amendment 35 (Activation);
- [TB-REV-193](../Architecture_M6_CP3_TB_REV_193_CoTrace_Deletion_Independent_Review_20261128.md) obligations 1–3.

CB-219 is Code + Build only:
- apply exactly one diff;
- compile the eight GMP/GMPXX targets with `runtimeExecution=false`;
- STOP on any hash, path, patch or compile mismatch, and do not adapt.

## `M6-CP3-CB-219-P13-COTRACE-DELETION-SWITCH` — A2a activation, compile only

Diff [`Architecture_M6_CP3_CB219_P13_CoTrace_Deletion_Switch_Exact.diff`](../Architecture_M6_CP3_CB219_P13_CoTrace_Deletion_Switch_Exact.diff): SHA-256 `636ee790b73e883a0a542812e571d21bff54d83521217235ec8ba8ded24db89d`, 26,716 B, +137/−76. It applies on the CB-218 postimages.

| Path | Preimage SHA-256 (CB-218 postimage) | Postimage SHA-256 |
|---|---|---|
| `include/directional/geometry/SurfaceCellTracing.h` | `522cfebbf90dcb806cd9f4f9caf9add379777145689cc75ed73c4aff2beae387` | `16992cc75b2182e8ff7e70d815bb75960d93ecfdb78f8deccfdc3dac9684048e` |
| `src/geometry/SurfaceCellTracing.cpp` | `3a67db446800efe1378c04a1471d64926e2aad88214cfa635c28ce1a3de7c09c` | `34719fab75267c2617b9fc2365e74e5e246c4249e34c0686c7c4dc20c4a6411b` |
| `tests/FieldAlignedCurveNetworkTests.cpp` | `d02c8507f56f5d7bb55fb909bd74cd614bf60203abcc8a1d6ea91d0d99360bc8` | `c453480681c3bb29633d979754ccac286489d2529fdc1435274be19571c90ef6` |

Content: the option `deleteClaimedCoTraces` defaults to true in every derivation (make, validation, make_from_candidate, diagnose); a build and its validation always use the same value. Tests whose subject is the tracing loop, tracing diagnostics and unstaged slide-entry controls observe the traced network with `false`. Test changes follow SW3 of the switch DEFN; no assertion is weakened.

Verification: independent apply and reverse, hashes, syntax check with 0 errors, identical location-stripped warning multisets (40/42; display 24), no plan identifiers.

## `M6-CP3-TB-EXEC-194` — full gate on the CB-219 package

**Inputs:**
- the CB-219 package;
- harness `423f385b73c3825ce9fe18fbd5ca395287620475deb621389f0efbaa601e572c`;
- the SAME **1013-row manifest** `b910f2a96626660f46042c34360a8062c7546f35fb1980432d038ba8f41d2fc2` (no new rows);
- deferred `fd433f54…64ce` (81), so membership is 1094;
- comparator TB193 result `15250401219` (ZIP `c771dab68abfd32a57e66cb236d5a8d618c124cb3040d0e388e12eb9614daa7b`).

No rebuild, retry, timeout substitution or V5.

**Comparisons:**
- All 1013 rows must PASS.
- Rows allowed to differ from TB193 (must still PASS): the 27 sphere rows (380, 388, 393, 394, 396, 397, 644, 645, 648, 669, 686, 691, 693, 694, 698, 699, 700, 843, 844, 858, 963, 968, 971, 972, 978, 979, 1006) and rows 1012 and 1013.
- Every other row (983) must be N1–N3-equal to TB193. Any difference is STOP.

**Predictions.** A mismatch is STOP for review, never a repair.
- Row 858:
  - `SphereSingularityArrivals classified=1 arrivals=10 radialEdge=10 faceInterior=0 matched=10 portTraced=0`;
  - the 10 `SphereSingularityArrival` lines keep TB193's trace, node, edge and port, and read `portTraced=0`;
  - `SpherePlan retained=1 arcs=18 mandatory=0 trace=18 cut=0 regions=8 certificates=8`;
  - `SphereRegionBoundarySchedules built=1 regions=8 sides=36 arcs=18 pairedArcs=18 otherArcs=0`;
  - the eight schedules' side-count multisets are {1,32,1,32} twice, {30,1,37,35,1,30}, {30,32,37,35}, {30,32,35,35}, {32,30,35,37}, {32,35,35,30}, {35,1,30,30,1,37} (region and node ids measured);
  - `FieldTransportAtlas.partition`, `slideProposal`, `slideCoincidence`, `slideContactArrival`, `entryCoincidence` and `committedSlide` lines unchanged;
  - `SphereRoute`, `SphereSimplification`, `SphereCompletion*`, `SphereAudited*`, `SphereDisplayStop*`, `M3_CP4AB_FRAGMENT_DIAG` and `Genus*` lines unchanged (the fallback route reads no A2a or plan product);
  - `SpherePlanRegion` lines measured.
- Row 698 prints traceCount 14, SingularityTermination 10, TraceIntersection 4.
- Row 686 prints V/E/F 12/18/8.
- Rows 644 and 645 measured.
- Falsifiers: any typed `CoTraceDeletion…` condition in any log; any non-sphere row difference (especially mechanical-fixture rows and 1010/1011); a red or abnormal row.

**Not allowed:** re-trace, D13/A2b/A3/dispatch/veto changes, B1/fallback repair, CB-207D, promotion of CP3/497/D0/H4.
