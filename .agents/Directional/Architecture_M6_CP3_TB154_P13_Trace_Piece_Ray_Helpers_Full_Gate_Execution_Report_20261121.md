# TB154 — trace-piece ray helpers full gate (2026-11-21 UTC)

## Situation

**PASS.** CB169 source `ef86370d0a1436250bdc8417b6b1abdeb1df5a74`, immutable compiled package `14694154267`, ran unchanged. Full gate **971/971 PASS**, with new rows 969–971 PASS and first **968/968 MATCH** TB153 under frozen N1–N3 (including row 686). Census **3/3 MATCH** TB151 under N1–N4: Cylinder PASS; BunnyRandom and Vase retain the expected RED at `SurfaceCellDesignAcceptanceTests.cpp:493`. CP2 stays **491/491 PASS**. No rebuild, compile, configure, relink, benchmark, test/fixture or manifest mutation occurred. This is not CP3 acceptance, producer switch, or sphere repair.

## Background — immutable evidence

| Item | Authority |
|---|---|
| Source and package | CB169 `ef86370d0a1436250bdc8417b6b1abdeb1df5a74`; compiled artifact `14694154267`, ZIP SHA-256 `ad39099eba5b02262c9287613d2c5921bdabd24442a47ed21fdd70c9e0340d77`, 28/28 checks, eight GMP/GMPXX targets; compile run 44871935919, `runtimeExecution=false` |
| Gate | [run 44874759906](https://github.com/akashskypatel/Directional/actions/runs/44874759906), mailbox key `m6-cp3-tb154-gate`, dispatch event SHA `747eb680ca9801d5f245ae35875fe2b6e2b2924e`; result artifact **14696380156**, ZIP SHA-256 `ce172d892dbf3f52084eaf3a148ec03443bc19c06ec9e5262f89e35c89b648c0`; log **14695753734** |
| Census | [run 44874777995](https://github.com/akashskypatel/Directional/actions/runs/44874777995), mailbox key `m6-cp3-tb154-census`, dispatch event SHA `4827c37cb29be83e3d558b36795e4f4ccb705fd3`; result artifact **14696590265**, ZIP SHA-256 `0dd3b6ea13c1c0b6db4822fe91fd58483990cd7515898e99e780bb3bc19991e6`; log **14696470746** |
| Baselines | TB153 artifact `14692372657` (`5e102074ae1bbfcf9c1a94a928e8d354725b484c67fa7dc53410d887a12f8147`); TB151 census artifact `14621727104` (`4eacb6f3d9d272a2ee380527fc8f7abab516508a596d3dea3f955e8086a4c611`) |
| Gate manifest | `gates/Architecture_M6_TB154_P13_Trace_Piece_Ray_Helpers_Full_Gate_Case_Manifest.tsv`, SHA-256 `0f9c417c6bb4b563abc90e5707eee98656210df322f5e0d00af1efc8f9f4e305`; 971 required + 81 deferred = 1,052 membership entries |
| Census and harness | Census manifest `gates/Architecture_M6_TB63_P13_Census_Case_Manifest.tsv`, SHA-256 `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793`. Artifact-only harness `tools/m6_cp3_targeted_artifact_harness.sh`, SHA-256 `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94` |

## Assessment — exact STOP checks

- Both workflow mailboxes identify their expected run, CB169 source and dispatch event. Workload and publication jobs succeeded; compile and drive apply were skipped.
- Result outer ZIP hashes match GitHub digests. `SHA256SUMS` checks: **1950/1950** gate, **9/9** census; baseline checks TB153 1,944/1,944 and TB151 9/9.
- Gate execution boundary: planned=executed=passed=971, `red=abnormal=missing=skipped=duplicate=control_bad=unexpected_pass=0`, `postflight=true`, `exit=0`, membership 1,052, `compile=configure=relink=benchmark=false`.
- Gate comparison of rows 1–968 to TB153: **968/968 MATCH**, 0 mismatches, 558 byte-identical raw logs. Only frozen normalization N1 (GoogleTest time), N2 (line endings), and N3 (multiset of exact `region_support_projection` lines) were applied. **1,750** M3 records in each side's compared scope, including row 686; all non-M3 lines remain in order.
- Rows 969, 970 and 971 each PASS, exit 0; CP2's first 491 cases remain PASS. Row 971 emitted all three required record families (21 lines below).
- Census boundary: planned=executed=3, passed=1, red=2, `postflight=true`, `exit=0`, no build/benchmark. **3/3 MATCH** TB151. N4 masks only the two 16-byte `GetParam()` values in each RED raw log (two per RED case on each side); no other semantic fields or raw lines are masked. Cylinder PASS; BunnyRandom and Vase retain the exact expected RED site `../../Directional/Directional/tests/SurfaceCellDesignAcceptanceTests.cpp:493: Failure`.
- This turn did not change implementation, tests, manifests, fixtures, selection, production recovery, or fallback policy. No new regression or candidate: both expected REDs are unchanged, no previously accepted case became RED, and no earlier raw record changed under permitted normalization. Stable **66 events / 17 categories / 49 recurrences**, one produced-witness debt, 81 deferred, CP2 491/491.

## Row 971 — verbatim diagnostic records

```
SpherePieceRayReceipt vertexRays=34 alongEdge=10 inWedge=24 edgeRays=4 alongLocusEdge=0 intoFace=4 changedVertexParameter=0 changedOrdinary=0 failures=0 coincidentAlongEdge=0 coincidentWithEdgeArc=0
SpherePieceRay trace=0:6 end=Reverse locus=vertex:8 kind=alongEdge edge=6-8 oldParameter=4219850347643677/4503599627370496 newParameter=none oldRank=none
SpherePieceRay trace=1:6 end=Reverse locus=vertex:21 kind=alongEdge edge=16-21 oldParameter=283749279726819/4503599627370496 newParameter=none oldRank=none
SpherePieceRay trace=9:6 end=Reverse locus=vertex:8 kind=alongEdge edge=8-9 oldParameter=283749279726819/4503599627370496 newParameter=none oldRank=none
SpherePieceRay trace=10:6 end=Reverse locus=vertex:49 kind=alongEdge edge=49-62 oldParameter=283749279726819/4503599627370496 newParameter=none oldRank=none
SpherePieceRay trace=11:6 end=Reverse locus=vertex:21 kind=alongEdge edge=20-21 oldParameter=4219850347643677/4503599627370496 newParameter=none oldRank=none
SpherePieceRay trace=12:6 end=Reverse locus=vertex:45 kind=alongEdge edge=40-45 oldParameter=4219850347643677/4503599627370496 newParameter=none oldRank=none
SpherePieceRay trace=13:6 end=Reverse locus=vertex:34 kind=alongEdge edge=32-34 oldParameter=283749279726819/4503599627370496 newParameter=none oldRank=none
SpherePieceRay trace=14:6 end=Reverse locus=vertex:0 kind=alongEdge edge=0-69 oldParameter=4219850347643677/4503599627370496 newParameter=none oldRank=none
SpherePieceRay trace=21:6 end=Reverse locus=vertex:34 kind=alongEdge edge=33-34 oldParameter=4219850347643677/4503599627370496 newParameter=none oldRank=none
SpherePieceRay trace=22:6 end=Reverse locus=vertex:45 kind=alongEdge edge=45-46 oldParameter=283749279726819/4503599627370496 newParameter=none oldRank=none
SpherePieceRaySlideEnd trace=0:6 locus=vertex:8 kind=alongEdge
SpherePieceRaySlideEnd trace=1:6 locus=vertex:21 kind=alongEdge
SpherePieceRaySlideEnd trace=9:6 locus=vertex:8 kind=alongEdge
SpherePieceRaySlideEnd trace=10:6 locus=vertex:49 kind=alongEdge
SpherePieceRaySlideEnd trace=11:6 locus=vertex:21 kind=alongEdge
SpherePieceRaySlideEnd trace=12:6 locus=vertex:45 kind=alongEdge
SpherePieceRaySlideEnd trace=13:6 locus=vertex:34 kind=alongEdge
SpherePieceRaySlideEnd trace=14:6 locus=vertex:0 kind=alongEdge
SpherePieceRaySlideEnd trace=21:6 locus=vertex:34 kind=alongEdge
SpherePieceRaySlideEnd trace=22:6 locus=vertex:45 kind=alongEdge
```

The record reports 34 vertex rays (10 along-edge, 24 in-wedge), 4 edge rays (all into-face), zero failures, `changedOrdinary=0`, `changedVertexParameter=0`, `coincidentAlongEdge=0`, and `coincidentWithEdgeArc=0`. Interpretation of the row 971 prediction belongs to the **TB154 Review**, not to this execution turn.

## Recommendation — boundary and successor

The only authorized successor is `M6-CP3-TB-REV-154-P13-TRACE-PIECE-RAY-HELPERS-FULL-GATE`. The Review must independently check the row 971 predictions and RA-274 S5, then freeze the producer switch if supported. No producer switch, stop switch or follow-up test was started by TB154. Sphere χ6 vs source χ2, four slide contacts and row 669/698 exhaustion are still open. No CP3, 497-identity selector, D0 or H4 promotion.
