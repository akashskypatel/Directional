# M4-CP-SCALE-TB5 Artifact-Only Test + Benchmark Report

**Turn:** `M4-CP-SCALE-TB5-EXEC`
**Disposition:** **COMPLETE / MECHANICALLY GREEN / REVIEW REQUIRED / NO PROMOTION IN EXEC**
**Execution run/job:** `35002009539 / 104492480074`
**Control/event SHA:** `1d453a4ef94b4e370bae44f07340d5726b1c6d55`
**Immutable candidate artifact:** `10407605295` (`29f68b3880fb9d2d521aa74541112af9de5d35fdc982decfdbc8067305e747e5`)
**Semantic source:** `0d8e4aa3472fae26c22d49bc0d81acc5e98378d3`
**Selector authority under test:** `Architecture_M4_CP_SCALE_CB6_Required_Green_Selector_424.txt`, 424 LF rows, SHA-256 `f202a1720c0a5288471d04836402b8432eb6f4f788da68a12e70dacb875466ca`
**Mandatory successor:** `M4-CP-SCALE-TB5-REV`

## 1. Boundary and provenance

TB5 stayed artifact-only. The execution harness consumed exact CB6 candidate artifact `10407605295` and did not configure, compile, relink, repair, regenerate, discover tests, mutate source/test/fixture/selector bytes, or run unrelated benchmarks. The package entered TB with `runtimeExecution=false`; runtime began only after immutable preflight completed.

Preflight re-verified:

- provider artifact SHA-256 `29f68b3880fb9d2d521aa74541112af9de5d35fdc982decfdbc8067305e747e5`;
- semantic source `0d8e4aa3472fae26c22d49bc0d81acc5e98378d3` and packaged source archive SHA-256 `55bbe23520e7398fcf2e639623492007d445dd219ca1960cb5f63b301cd7b0c3`;
- package `SHA256SUMS` SHA-256 `802c57feb9cb01293ac61d1795d4ba9b1c848c8b78898ed54340bd55c256d3a7`, **28/28** entries;
- selector424 **424 unique nonblank LF rows**, SHA-256 `f202a1720c0a5288471d04836402b8432eb6f4f788da68a12e70dacb875466ca`;
- rows 1-423 byte-identical to selector423 SHA-256 `4e67e4dc6528a71e8399cd55dce6af4c6143e2502102e421b62a8eb712d89343`;
- row424 exactly `M4CPScaleS2.VertexStarCertifiedFilterMatchesIndependentExactOracle`;
- unique owner census **30 authority-kernel / 278 producer / 75 completion / 41 validation**;
- all four owner binaries present, executable, and linked against GMP/GMPXX evidence from the package;
- exact fixture materialization under `test-data/benchmarks/fixtures/**` without repair or synthesis.

## 2. Runtime result

Selector424 executed cumulatively in exact file order as **424 fresh exact-filter processes**. Every process selected exactly one test and returned exit 0 / one PASS / zero SKIP.

| Measure | Result |
|---|---:|
| Executed | **424 / 424** |
| PASS | **424** |
| RED | **0** |
| SKIP | **0** |
| Timeout | **0** |
| Crash | **0** |
| Selection mismatch | **0** |
| Unexecuted | **0** |
| Authority-kernel | **30 / 30** |
| Producer | **278 / 278** |
| Completion | **75 / 75** |
| Validation | **41 / 41** |

Row424 ran freshly in this TB and passed independently of the earlier TB4 focused result:

`424/424 PASS — M4CPScaleS2.VertexStarCertifiedFilterMatchesIndependentExactOracle`

No TB4 focused-process observation was imported as row424 credit.

## 3. Immutable postflight

Postflight completed successfully and independently re-verified all 28 package-manifest members. Selector424 re-hashed to `f202a1720c0a5288471d04836402b8432eb6f4f788da68a12e70dacb875466ca` with unchanged 423-row prefix `4e67e4dc6528a71e8399cd55dce6af4c6143e2502102e421b62a8eb712d89343` and unchanged row424. Package, extracted-source, and execution-view byte+mode censuses are each exactly equal before versus after runtime.

The execution prohibition receipt records:

- `configureExecution=false`
- `compileExecution=false`
- `relinkExecution=false`
- `repairExecution=false`
- `generatedDiscovery=false`
- `mutationExecution=false`
- `benchmarkExecution=false`

Thus the runtime observation is mechanically valid artifact-only evidence.

## 4. Evidence package

- result artifact `10410518189`, provider SHA-256 `7f9f9a4f9b18930255688e775691a21b92538c666a987f29101541aaec1ce3ac`;
- detailed log artifact `10410672518`, provider SHA-256 `26d59ed6846effe4d38fdc5b2c27b23d95cdf0f6784e8b0ff5d49c212320cc7f`;
- nested evidence ZIP SHA-256 `576104efb4aa5723a0384ec7aac0abe0fbc244b8dbb9417a198ea53041040bac`;
- non-self-referential evidence manifest SHA-256 `1aabede920e5401187f8c8590a4969d26694b8fa43cee98c37f29f63b61ea208`, **1298/1298** entries verified;
- ordered process ledger has exactly 424 ordinals with exact owner census **30/278/75/41**;
- raw stdout/stderr and resource receipts are retained per selector ordinal.

Mechanical status is `mechanical_exit=0`, `mechanicalGreen=true`, `preflightComplete=true`, `runtimeStarted=true`, `runtimeCompleted=true`, `postflightComplete=true`, `selectionIntegrity=true`.

## 5. Regression/accounting disposition

TB5 observed **no regression and no new candidate**: no accepted required-green identity went PASS->RED, no selector row failed, and no orchestration/postflight defect occurred. Stable accounting therefore remains **49 events / 14 categories / 35 recurrences**; produced-witness debt remains **5**.

`M4-CP-SCALE-TB4-REV-OBS-01` advances to **PUBLICATION + CUMULATIVE RUNTIME SATISFIED / REVIEW OWED / NON-STABLE**. EXEC does not discharge it because only Review may promote package/selector424 authority.

## 6. Authority and successor

TB5-EXEC **does not promote** candidate artifact `10407605295` or selector424. Accepted runtime authority remains package `10378808176` / source `905dabe390577d63ed6a9289e3f3d53aa4144936` under selector423 **423/423** until `M4-CP-SCALE-TB5-REV` independently re-opens and adjudicates this evidence.

Exact next formal turn: **`M4-CP-SCALE-TB5-REV`**. Review alone may promote candidate `10407605295`, accept selector424 as cumulative required-green authority, and discharge `M4-CP-SCALE-TB4-REV-OBS-01`. CP-SCALE remains open regardless because S3, S4 and S5 are separate frozen obligations.
