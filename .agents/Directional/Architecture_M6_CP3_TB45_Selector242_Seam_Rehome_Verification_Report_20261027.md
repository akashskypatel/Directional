# TB45 — selector242 seam re-home immutable artifact-only verification (2026-10-27)

**Turn:** `M6-CP3-TB45-RP01-SELECTOR242-SEAM-REHOME-VERIFY`. **Result: 3/3 PASS; candidate focused evidence, review pending.**

## Authority and execution

- CB45 semantic source: `dfeb0751b1a42a0805aecf4ef4ffb6917f619c83` (unchanged).
- Immutable GMP/GMPXX compile artifact: `12697664329`, compile run `40421241608`. Original ZIP SHA-256 `ad30d61b82e0de541d703073dbdefb5a7b9ed3d250cbc1b726e8cbd8c8aa21fd`; all 28 package member checksums independently verified.
- TB45 executor source: `e48028e9eeed7b6b4c5c874400d75256fb61ada9`. Exact harness SHA-256 `436f5fff9c3bec97457f4bc6b7c2b6182cb3f47707eb14a66af3b6a3f3dc3c9a`; frozen three-case manifest SHA-256 `1b0186095f9d10d10c05084954a30ffa82ffd9b3bbcd0dcddde130c3810ece17`.
- [GitHub Actions test run 40433669771](https://github.com/akashskypatel/Directional/actions/runs/40433669771), `test_benchmark/runtime` success. Exact result artifact `12702259228`, outer SHA-256 `7d18b08a9bc598a39482c4b5d6831ae1aee9bbe77d1f0b208e13a6193bcd6080`; dedicated log artifact `12702474055`, SHA-256 `26488c1ae4a5cab774bda087bb7924a776708d77d3da77eeb69b6b276b6ec628`. Result SHA256SUMS members verified. Execution boundary `compile=false`, `relink=false`, `configure=false`, `benchmark=false`, exit 0, `postflight=true`.
- Exact outcome counts: 3 planned, 3 separate fresh-process executions, 3 PASS, 0 RED, 0 missing, 0 duplicate, 0 skipped, 0 invalid control. The immutable packaged view and source hashes were unchanged at postflight.

## Frozen identities

| Kind | Identity | Exact GoogleTest filter | Observed |
|---|---|---|---|
| POSITIVE | `selector:242` | `SurfaceCellsPhase10.NonReciprocalSourceAdjacentIsolationSeamFailsClosed` | PASS (exit 0, 1/1, zero skips) |
| GUARD | `selector:239` | `SurfaceCellsPhase10.ExactReciprocalTransportCrossesSourceAdjacentIsolationSeam` | PASS (exit 0, 1/1, zero skips) |
| GUARD | `selector:185` | `SurfaceCellIsolationSeamCertificateAuthority.NonreciprocalIsolationSeamCertificateIsRejected` | PASS (exit 0, 1/1, zero skips) |

Case raw logs: `raw/1.log` SHA-256 `aded65991756281eac4c344c2881303fe285f7fd27d4d030b861575ace2a1b72`, `raw/2.log` `9a7d5dc51a582775d08990d39fb583262944e3f24bbf75050f87d53f440e5704`, `raw/3.log` `974e4a5edc8e39f066cb002244418f15ef322fa2973f8599d629dcfeb801ca11`.

## Disposition and remaining review

These three focus tests are mechanically GREEN. Their required independent semantic/oracle review remains **unexecuted** and must not be implied by the test harness result. No full selector497 gate was executed or promoted. CP2 491/491 remains last accepted runtime; stable regression totals 66 events / 17 categories / 49 recurrences, debt 1, unchanged because no new regression was observed. RP-01 remains open and RP-02 unreached. No implementation, tests, fixtures, selector files, or workflow definitions were changed by this TB turn. Do not rerun or repair TB45 in lieu of Review.

**Exact authorized successor:** `M6-CP3-TB45-RP01-SELECTOR242-SEAM-REHOME-VERIFY-REV`. Independently verify immutable package/run/member/raw-log identities, reachability/non-vacuity and expected site from frozen CB45 Review and test source; keep any promotion or next-owner decisions Review-owned.
