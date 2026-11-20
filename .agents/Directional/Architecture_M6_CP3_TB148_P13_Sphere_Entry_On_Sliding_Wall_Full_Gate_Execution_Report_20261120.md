# TB148 — sphere entry on sliding wall, immutable full-gate execution (2026-11-20 UTC)

## Situation

**Test gate PASS: 963/963.** [GitHub Actions run 44668273156](https://github.com/akashskypatel/Directional/actions/runs/44668273156), immutable result artifact `14598534659` (outer ZIP SHA-256 `dac729fa05bb68c53c908476b4c32dfebe21f5f21d82743bcff58e31c7294c4e`). All jobs for schema validation, request parsing, runtime, and mailbox publication succeeded. Compile and patch-application jobs were skipped. This is a diagnostic gate PASS, **not** acceptance of the sphere cut graph, CP3, selector497, or D0.

## Background — immutable evidence

| Field | Exact authority |
|---|---|
| Semantic source | `d78404724a7f0bfb0c9c73769e6a68b9f2addd81` (CB168J test-only patch) |
| Package | `14596864941`, outer SHA-256 `d7b9a99a5b9bf3d50cf9f8df7890d2cabb5f61004a338a9cd1c80e9dac3064b4` |
| Executor snapshot | `673615807739900fb12a981cf3770803e5df8f75`, run `44667758994`, archive `14598581632`; ZIP `7d958a45613b560c59e58790b2aa4721403fdbf6dc2afe36e524c2911dfaabdd` |
| Immutable TB148 gate | 963 rows, manifest SHA-256 `4350378c95fefeb0dbab6e742b50dcd976af406f865ddef45cc03b35f7b4c01c` |
| Deferred membership | 81 rows, SHA-256 `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce` |
| Artifact-only harness | `.agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh`, SHA-256 `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94` |
| Execution request | `eb74df15493b4e71afe77d0f1be133ecc84f8a10`; request `m6-cp3-tb148-full-gate-20261120-v1` |
| Gate result | `14598534659`; 1,934/1,934 indexed file hashes and 963/963 raw-log ledger hashes verified |
| Gate log | `14598949007`, ZIP SHA-256 `80c7d72e8857a4f336d904798e622210ab7d6bc00490dfdb5e2b4b3a85e89a96` |
| TB147 baseline | Result artifact `14590664543`, ZIP SHA-256 `4fe8ddd8ab64669940fad176499cd77a739c798df7a931111fcd6ad5218ed372`; 1,932/1,932 hashes |

## Assessment — exact gate and comparison

- The immutable executor records `planned=executed=passed=963`, `red=abnormal=missing=skipped=duplicate=control_bad=unexpected_pass=0`, `membership=1044`, `postflight=true`, and `exit=0`.
- All 491 accepted-prefix tests passed. Required rows 393, 961, 962, and new 963 passed.
- Existing 962 row identities, binaries, test names, ledger verdicts, typed reasons, and control fields match TB147. Raw-log comparison gives **962/962 MATCH under previously frozen N1–N3 only**: variable Google Test durations and line endings normalized, complete `M3_CP4AB_FRAGMENT_DIAG record=region_support_projection` records compared as a counted multiset, remaining records compared in original order. There are 1,738 complete M3 records; no new normalization was added. Raw sequence differences in M3 output in rows 164 and 172 are order only with the same counted record values. Full raw log bytes remain in both immutable artifacts.
- All four row963 witnesses pass the independently printed conditions: `committed=1`, `movingEntryOnCarrier=1`, `previousExitCarrier=1`, `previousSlides=0`, `wallOutgoingIsCarrier=1`, `sameFace=1`, `strictlyInside=1`, `contactAgrees=1`, `sharedEvents=0`.

### Row 963 — four verbatim receipts

```text
SphereEntryOnSlidingWall moving=17:8 wall=0:6 carrier=(6,8) parameter=4038890029339747/4503599627370496 movingSegments=9 wallSegments=7 committed=1 movingEntryOnCarrier=1 previousExitCarrier=1 previousSlides=0 wallOutgoingIsCarrier=1 sameFace=1 wallSlide=707873584687237/2251799813685248..1/1 strictlyInside=1 contactAgrees=1 sharedEvents=0
SphereEntryOnSlidingWall moving=20:8 wall=1:6 carrier=(16,21) parameter=4038890029339747/4503599627370496 movingSegments=9 wallSegments=7 committed=1 movingEntryOnCarrier=1 previousExitCarrier=1 previousSlides=0 wallOutgoingIsCarrier=1 sameFace=1 wallSlide=707873584687237/2251799813685248..1/1 strictlyInside=1 contactAgrees=1 sharedEvents=0
SphereEntryOnSlidingWall moving=5:8 wall=21:6 carrier=(33,34) parameter=1009722507334937/1125899906842624 movingSegments=9 wallSegments=7 committed=1 movingEntryOnCarrier=1 previousExitCarrier=1 previousSlides=0 wallOutgoingIsCarrier=1 sameFace=1 wallSlide=707873584687237/2251799813685248..1/1 strictlyInside=1 contactAgrees=1 sharedEvents=0
SphereEntryOnSlidingWall moving=8:8 wall=22:6 carrier=(45,46) parameter=464709598030749/4503599627370496 movingSegments=9 wallSegments=7 committed=1 movingEntryOnCarrier=1 previousExitCarrier=1 previousSlides=0 wallOutgoingIsCarrier=1 sameFace=1 wallSlide=1543926228998011/2251799813685248..0/1 strictlyInside=1 contactAgrees=1 sharedEvents=0
```

All four have distinct directed moving/wall pairs. `sharedEvents=0` is direct evidence that these four exact contacts do not own a common graph event. **It does not by itself prove** that publishing these four crossings will repair all topology, or that a proposed consumer/producer switch is valid.

### Row 686 — verbatim independent graph summary (before component detail)

```text
m3Cp4c2ActualGraphOracle;witness=prescribed-sphere;complex=actualEmbeddedGraph;oracleKind=independent-face-planar-rotation-seam-orbit;surfaceCutGraphCallsInsideOracle=0;V=18;E=30;totalOrbits=18;excludedBoundaryOrbits=0;F=18;c=1;s=1;correction=0;chi=6;sourceChi=2;cutCrossingNodes=0;cutCrossingArcs=0;traceEndpointsAttached=true;noDegreeZeroNodes=true;producerComplex=unavailable
```

The oracle remains `V=18 E=30 F=18`, `chi=6`, `sourceChi=2`, excess **+4**. Rows 669 and 698 remain the same recorded `CutSearchExhaustedBeforeCellularity` failure class as TB147. The four receipts agree in number with the four-unit excess, but this is a causal hypothesis for independent Review to test, not a completed product repair. No post-test census ran because the product source was unchanged.

## Regression and promotion status

There is **no new stable regression event**. The previously open O47/C5 sphere cut-graph residual has new exact ownership evidence, but its root cause and repair remain subject to independent Review. Keep 66 stable events, 17 categories, 49 recurrences, one produced-witness debt, and 81 deferred tests. Previously observed Cylinder PASS and BunnyRandom/Vase RED belong to TB147's older census; TB148 did not repeat them. Do not promote CP3, selector497, D0, H4/O49/O48/FC-6, or row858.

## Recommendation

Only the authorized independent Review is next: `M6-CP3-TB148-P13-SPHERE-ENTRY-ON-SLIDING-WALL-FULL-GATE-REV`. It must independently re-open the result and baseline archives, inspect the four exact receipts and graph incidence, and decide whether the RA-269 conditional consumer and producer switches are supported. No source, test, fixture, selector, workflow permissions, compilation, re-link or benchmark workload changed in this Test + Benchmark turn.
