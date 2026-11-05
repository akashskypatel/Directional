# TB80 — CB90 immutable full gate and cross-platform census (2026-11-05 UTC)

**Canonical turn:** `M6-CP3-TB80-P13-ARRANGEMENT-CELL-ORDER-FULL-GATE-EXEC`. **Formal result: COMPLETE / valid artifact-only gate RED (898/899)**. Registered RA-204.8 **MISMATCH** because required gate row 899 failed. Route **M6-CP3-TB80-P13-ARRANGEMENT-CELL-ORDER-FULL-GATE-REV** (independent Review). This report does not perform the Review, alter a test, assume environmental flakiness, re-execute the gate, or promote the candidate.

## Exact package, executor and evidence

- **Semantic source:** `e00ef91a8a5dff8b125c9abfe388952cec20cbe1` (CB90); immutable artifact **13385965448** from [compile run 41960980473](https://github.com/akashskypatel/Directional/actions/runs/41960980473). Package ZIP SHA-256 `f8b9f6b83d1aea589284569bfc42ca2b1b68288d76ebf4202e0a62150c185b18`, 28/28 packaged checksums, eight required Linux static GMP/GMPXX compile targets. The build had `runtimeExecution=false`; this TB rebuilt nothing.
- **Executor source:** exact snapshot `6410c15e42c5262a2484e6aeea688397a13fa013` from [run 41966976684](https://github.com/akashskypatel/Directional/actions/runs/41966976684), artifact `13387249004`, embedded tar SHA-256 `c247c57ff11f233757a6e6dd7b5788c77678a35fadd4d4e94aa76dd25238794f`; verified against the snapshot metadata. Harness `.agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh` SHA-256 `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94`.
- **Frozen selector:** 899-case `Architecture_M6_TB78_P13_Census_Path_Cost_Full_Gate_Case_Manifest.tsv` SHA-256 `9d2c1ec598fea2b95b251fd2e007b7086740e51fb8f6f3ad7ff5671ab09ddb44`; ledger v5 SHA-256 `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce` has 81 deferred, total membership 980. Census manifest SHA-256 `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793`.
- **Gate:** [run 41967375039](https://github.com/akashskypatel/Directional/actions/runs/41967375039) / result artifact `13389065475` SHA-256 `0310706261dfaf81fac34f2c6c3b61d4d960d8a99d0661e203b75aec27f51535` / log artifact `13388083866` SHA-256 `17b810987f751cfbf9ba189a2ca72e450942b5f426d97c2e9a76532ff2faee3`. All **1,806/1,806** packaged result checksums and all **899** raw-log row hashes rechecked. `planned=899`, `executed=899`, `passed=898`, `red=1`, `abnormal=0`, `missing=0`, `skipped=0`, `duplicate=0`, `control_bad=1`, `postflight=true`; harness exit **90** / `ValueError: required controls failed`. Ten POSITIVE rows pass; the sole RED is a GUARD.
- **Census:** [run 41967458556](https://github.com/akashskypatel/Directional/actions/runs/41967458556) / result artifact `13388307944` SHA-256 `d8c309c1029daf4bdca6fc2962367a2e57471288a2650019724b2a6735d235c6` / log artifact `13388662064` SHA-256 `afdbeb4d6ebc4cc10cfae29eab478cdfda3ccb6ec1b37327ee624577f4bbe19f`. **9/9** result checksums and **3/3** raw-log hashes rechecked. `planned=executed=3`, 1 PASS, 2 registered RED, no abnormal, missing, skipped, duplicate or control failures; postflight true; harness exit 0.
- **Execution boundary:** both artifacts report `configure=false`, `compile=false`, `relink=false`, `benchmark=false`; immutable package, source, test and selector untouched.

## First decisive gate failure — row 899

- Identity: `ra202:final-validation-row-labels`, test `SurfaceMeshOptimizerPhase22.FinalValidationReadsSourceRowLabelsAfterOneBindingCheck`, binary `directional_surface_cell_validation_tests`.
- Raw assertion, `tests/SurfaceMeshOptimizerPhase22Tests.cpp:1953`: `Expected: (seconds) < (2.0), actual: 2.3740529700000002 vs 2`. The test's earlier `EXPECT_TRUE(report.sourceAuthoritativeValidationUsed)` does not report failure. The GoogleTest row elapsed time is 7,781 ms, not the stopwatch value being asserted.
- This is a **real required performance-control RED**, not an artifact download/orchestration failure and not demonstrated incorrect validation semantics. The test constructs a 28,800-face source and 400 output quads; the next independent Review should re-open this exact source, assess resource variability and the original time-bound contract, and establish whether a reproducible implementation cost/regression exists. It must not silently soften the threshold, retry to get green, or alter the immutable TB80 artifact.
- Compare TB79's 899/899 PASS against this row 899 RED; **no accepted CP2 regression** is established because CP3 is unpromoted. The failure is nonetheless a candidate and mandatory RA-204.8 mismatch route.

## Production census — registered outcomes

| Row | Fixture | Direct outcome and terminal evidence | Registration |
|---|---|---|---|
| 1 | Cylinder | PASS, direct source-authoritative output | MATCH |
| 2 | BunnyRandom | RED: `InvalidFieldTransportAtlas:field-transport-atlas/SingularityPortClassCountMismatch;sourceVertex=49`, 0 traces/cells/quads, fail closed | MATCH (P13-e) |
| 3 | Vase | RED: `NotProductionReady:completion`, `detail=SelfIntersectingFace`; `traceSegments=192482`, `arrangementCells=26817`, `completedQuads=67746` (observed only); wall `4:28.87` = 268.87 seconds, under 600s, fail closed | MATCH (P13-l) |

The census matches its three registered typed results. Vase's completed-quad count is **not a new acceptance pin** under RA-205 O32.

## All seven platform-digest records (verbatim)

Each specified row contains exactly one digest line; these values are observations, not new acceptance criteria.

```text
Gate row 795: platform-digest case=CloseSheets vertexBits=610a515ac548d9e5 faceBits=2aac7a4034a53084 fieldBits=67f14e9a0da8cc25 source=5e6048ce544f359c/36 cross-field=2b0d354a26601973/36 feature=ec6eee995a69d42d/66 rails=71402b8cd6b33439/2 metric=fab649a3b38bf0fb/32 relief=14e153b4b075e5d5/40 relief-consumption=b65993849fc47e82/78 source-labels=b526355d3dfb71ca/36 field-transport-atlas=cab4682b73f5bce1/52 field-aligned-network=d723620693f6f1c5/48 surface-cut-graph=d35fc38600a73aa2/2 global-topology-plan=e896b18cb73c56e2/50 global-conformity-baseline=d96525d83266060b/48 tracing=589edaf2eb87bbb5/1104 strands=d68abf6c7e47a0a3/1128 embedding=67442dd8c6025d7f/1128 arrangement=5612032bbe02f5df/202 simplification=5612032bbe02f5df/202 completion=89ced6d01559f38f/200 optimization=42308fa2adadb7fb/200 validation=aefefcede85f098a/200
Gate row 796: platform-digest case=MultiFaceSeam vertexBits=d9bdfcc0a3925655 faceBits=41696de4685917ab fieldBits=05bfd9b9dd3ecb25 source=7a8c005d839eace8/32 cross-field=871c9a976d8cbb50/32 feature=8b611bf652405bf2/56 rails=3786416b45502da0/1 metric=da3ce1897060b72f/25 relief=1908fbf2bf880d8e/19 relief-consumption=14625a19e9ce7588/57 source-labels=8a6a6560dcb5c8d3/32 field-transport-atlas=e2c732ede2f158c4/50 field-aligned-network=fc93e24d9a4d1dd0/32 surface-cut-graph=b998dd302510bbf6/1 global-topology-plan=160571701e6dd0a9/33 global-conformity-baseline=c9809142d83085e0/32 tracing=c3996b86d41d70fd/256 strands=4fd4b6f6b9f72e34/272 embedding=040136465efa8eab/272 arrangement=cb3826c8d7773023/65 simplification=cb3826c8d7773023/65 completion=c399607d09eb2683/64 optimization=a64dac0edaddbdf8/64 validation=12db7cff9b1d0517/64
Gate row 797: platform-digest case=Plane vertexBits=a6dd696d19d50a18 faceBits=8363b4abcc93efd5 fieldBits=5f4eba6ca6046f25 source=710e15a4220d8ee6/24 cross-field=ae54f37ee5d26302/24 feature=dbcb95cbdb24d00d/43 rails=f1b1bb761198fcc6/1 metric=aad884a80b65bf5d/20 relief=b41394be2321cadb/24 relief-consumption=03c611f59a22c352/49 source-labels=3990f1f0538c4e1c/24 field-transport-atlas=65bec7a9ba3d4eb3/36 field-aligned-network=882f8b00cc981707/28 surface-cut-graph=6d79d3c14247d71d/1 global-topology-plan=1b47db4c3e092091/29 global-conformity-baseline=f5c3f877fce4e8ef/28 tracing=77deb7d5c253f883/352 strands=a4fe21aeb7a7dd73/366 embedding=4f4c21f3dda4a166/366 arrangement=bf49c52b429b8a6d/65 simplification=bf49c52b429b8a6d/65 completion=17e781c735a1b531/64 optimization=f94b7d773cc7c9f1/64 validation=e7e5ad577e046893/64
Gate row 864: platform-digest case=Cylinder vertexBits=275ec93baa764a47 faceBits=5cbe02acf3a8b550 fieldBits=9cf2ceb792da2ec5 source=72815904cc9359c2/128 cross-field=048282ce2f33efc7/128 feature=4720dae9adc48841/208 rails=e13580329f22ee39/28 metric=8b544a23d1cff9e3/80 relief=c66182ca3b9667b4/44 relief-consumption=1a618682fbfff038/180 source-labels=a00ad649e820c7fd/128 field-transport-atlas=e12d7d76e66148f6/226 field-aligned-network=4ab72b48e4600ee3/64 surface-cut-graph=ef9a4e56f7901be5/50 global-topology-plan=5e1ff8c1a605f265/162 global-conformity-baseline=12db9fbca63979ca/211 tracing=e0a85269f80c1190/1728 strands=70f1c35bb0c5f759/1760 embedding=b3fb03c2631853a6/1760 arrangement=663e2b4524a30d5b/290 simplification=663e2b4524a30d5b/290 completion=ad7b4ed251f77e3e/288 optimization=6f09047d714f4a98/288 validation=5d261446433662f0/288
Census row 1: platform-digest case=Cylinder vertexBits=275ec93baa764a47 faceBits=5cbe02acf3a8b550 fieldBits=9cf2ceb792da2ec5 source=72815904cc9359c2/128 cross-field=048282ce2f33efc7/128 feature=4720dae9adc48841/208 rails=e13580329f22ee39/28 metric=8b544a23d1cff9e3/80 relief=c66182ca3b9667b4/44 relief-consumption=1a618682fbfff038/180 source-labels=a00ad649e820c7fd/128 field-transport-atlas=e12d7d76e66148f6/226 field-aligned-network=4ab72b48e4600ee3/64 surface-cut-graph=ef9a4e56f7901be5/50 global-topology-plan=5e1ff8c1a605f265/162 global-conformity-baseline=12db9fbca63979ca/211 tracing=e0a85269f80c1190/1728 strands=70f1c35bb0c5f759/1760 embedding=b3fb03c2631853a6/1760 arrangement=663e2b4524a30d5b/290 simplification=663e2b4524a30d5b/290 completion=ad7b4ed251f77e3e/288 optimization=6f09047d714f4a98/288 validation=5d261446433662f0/288
Census row 2: platform-digest case=BunnyRandom vertexBits=afeef971d97f3e77 faceBits=a493d538d4f12dff fieldBits=03ee413ed128cbdd source=f1def128f3fd2d31/1000 cross-field=32eb9c1b3674ab2e/1000 feature=b91068287ee13189/1500 rails=dc5225500a257ab7/7 metric=e993a5a41ddc17d4/502 relief=d483e8239dd4d9af/493 relief-consumption=9b6e882062ada641/1142 source-labels=5076a6e22fae513a/1000
Census row 3: platform-digest case=Vase vertexBits=eef00a8706c009f5 faceBits=e43da6cccb821779 fieldBits=5c9a34a47d717fdc source=bda54d4fd948e6c0/2404 cross-field=8e16b454468fe056/2404 feature=116dae2abefd55cb/3677 rails=0e65f0d581f8c717/1 metric=46e5eb6de00adb8b/1274 relief=88c04e58d9413be9/453 relief-consumption=1a74a99cdb61ff3e/1569 source-labels=2f58b6b0a0d9c652/2404 field-transport-atlas=9634dbd00b8015b2/4668 field-aligned-network=e4787cde9c9c8c8e/291 surface-cut-graph=c8cf0e9fdad8b6df/3 global-topology-plan=817296327ba75c64/297 global-conformity-baseline=018723ddd3522976/299 tracing=d35129b974e6df7d/192482 strands=66c38d23d7421c2d/30989 embedding=f2fc0cca0e258de4/30989 arrangement=26e811501b72fd6b/26817 simplification=26e811501b72fd6b/26817 completion=1925fdbe6354006d/67746
```

## RA-204.9 comparison (observational)

The macOS FMA-off reference is `Architecture_M6_CP3_CB90_P13_Platform_Digest_macOS_FMAoff_Reference.tsv`, SHA-256 `955223c86c78c4ffd30dbc20fdb39a44f14cefbea271acf036d1cad59299a7d6` (129 rows). Differences are not silently reclassified as row 899's cause.

| Case | Stage | TB80 Linux | macOS reference | Observation |
|---|---|---|---|---|
| CloseSheets | embedding | `67442dd8c6025d7f/1128` | `67442dd8c6025d7f/1128` | equal |
| CloseSheets | arrangement | `5612032bbe02f5df/202` | `5612032bbe02f5df/202` | equal |
| CloseSheets | simplification | `5612032bbe02f5df/202` | `5612032bbe02f5df/202` | equal |
| Plane | arrangement | `bf49c52b429b8a6d/65` | `bf49c52b429b8a6d/65` | equal |
| MultiFaceSeam | arrangement | `cb3826c8d7773023/65` | `cb3826c8d7773023/65` | equal |
| Cylinder | arrangement | `663e2b4524a30d5b/290` | `663e2b4524a30d5b/290` | equal |
| Vase | embedding | `f2fc0cca0e258de4/30989` | `909330af789bee4c/30989` | different |
| Vase | arrangement | `26e811501b72fd6b/26817` | `e7575660c00edebe/26817` | different |
| Vase | simplification | `26e811501b72fd6b/26817` | `e7575660c00edebe/26817` | different |
| Vase | completion | `1925fdbe6354006d/67746` | `7ef762088d515416/67746` | different |

**Disposition:** CloseSheets' same embedding and arrangement/simplification digests, plus matching Plane/MultiFaceSeam/Cylinder arrangement digests, support the CB90 cell-order fix (O30a) in the measured fixed-order cases. Vase has equal **67,746 completed-quad count** but distinct embedding, arrangement and completion hashes; O30b remains open and this does not prove semantic embedding equivalence. O32a–e source-row permutation invariance remains unresolved even though CB90 stabilizes the current row order. No broad O30/O32 closure or CP3 acceptance is claimed.

## Turn disposition and carried obligations

- **Formal TB80 outcome:** COMPLETE / **MISMATCH** due solely to required gate row 899. The next authorized turn is `M6-CP3-TB80-P13-ARRANGEMENT-CELL-ORDER-FULL-GATE-REV`; its Review may separately adjudicate row 899's runtime threshold and O30a/b measurements before freezing a corrective CB. No retry or source/fixture change occurred during this TB turn.
- **Accepted authority unchanged:** CP2 **491/491**, stable **66 events / 17 categories / 49 recurrences**, produced-witness debt **1**; selector497 and CP3 remain unpromoted; selector membership **980**, 81 deferred.
- **Carried:** O30b, O31, O32a–e and O32 CP3-exit, P13-l Vase orientation, P13-e BunnyRandom, O27–O29, DR1/DR3 and independent Review-track ordering RA-205.6 (O32a before P13-l). No successor work was begun.
