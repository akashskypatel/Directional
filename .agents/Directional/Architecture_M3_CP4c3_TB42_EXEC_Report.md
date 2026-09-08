# M3-CP4c-3-TB42-EXEC Artifact-Only Runtime Report

**Status:** EXECUTION COMPLETE / EVIDENCE PRESERVED / REVIEW NOT PERFORMED
**Canonical turn:** Test + Benchmark — EXEC subturn only
**Semantic source:** `5dacce6019ea34316c48743f3033d2bb5c26281a`
**Immutable package:** artifact `10070788592` / `directional-m3-cp4c3-cb47-result-34262805758`
**Package provider/ZIP digest:** `sha256:f3a936866dc0bc0a81ed7d6d06380836e98e5c32806ac5a8680cf4a0ab393114`
**Execution run:** `34265561941`; workload job `102193966106`
**Result artifact:** `10071763480`, digest `sha256:a862d93b34be4439919be56938f3318b551b902484f6f8ede7776d0f41b3f86f`
**Log artifact:** `10071764085`, digest `sha256:57dcfdbddd6e571c11d565a1ffaaa3bc3014ea4fb299e48bb9cea2f644598336`
**Exact successor boundary:** independent `M3-CP4c-3-TB42-REV` — implementation/orchestration loop stops here.

## Boundary and package integrity

TB42-EXEC executed the frozen artifact-only plan. It performed no configure, compile, relink, generated discovery,
package repair, source/test/fixture/selector mutation, or benchmark execution. The workload completed normally with
`script_exit=0`, `orchestration_failure=false`, selection integrity true, zero timeouts, and zero nonzero runtime
process exits.

Preflight verified:

- exact semantic source `5dacce6019ea34316c48743f3033d2bb5c26281a` in package manifest and metadata;
- root package `SHA256SUMS`: **28/28 PASS**;
- packaged source status clean;
- compile metadata `runtimeExecution=false`;
- `exactArithmeticBackend=GMP` with GMPXX+GMP link evidence;
- selector409 count **409** and SHA-256 `eea6d8c2bbc8e9247deb4bfbbe6763042c76002d1894dd62e35f80262403b53e`;
- selector408 remained the required prefix of selector409;
- frozen harness SHA-256 `aaadab351c0ba28a39c87aff1948f83ab0c4c71520662177e5cdf6fd08b30ed3`.

Package immutability held across execution: root-before and root-after digest were both
`23c687d1d4e296ef8de21661b9feff0bf22f66119fede3fa1e37c76ac5137696`.

## Exact selector result

All **409** identities executed exactly once, one fresh process each.

- **398 PASS / 11 RED / 0 SKIP**.
- Accepted ordinals **1–365 = 365/365 PASS**.
- RED ordinals: `[366,367,368,369,370,374,390,393,398,406,407]`.
- Hard protected controls: 311/314/356/357 PASS; 312/315/409 PASS; 404/408 PASS.
- Certified owner publication evidence recorded `sourceFaceCount=300; established=300; unavailable=0; conflicting=0`.
- Required retired tokens were absent from all raw ordinal logs: `RegionEulerCharacteristicNotOne`,
  `RegionInteriorDisconnected`, `TraceArcDoesNotSeparateItsSides`, and `UncutFaceComponentOrbitSeedNotUnique`.
- Ledger SHA-256: `5b1e663e2855d453cf461847ed463b7539f9d0e945b4c40468eab64ae3e57a99`.
- Failure-detail digest table SHA-256: `f2b3cb59b79d4497117ecab2e62d6dd5e6476d9089149554173a795f4192e472`.

The RED identity set is identical to the promoted TB41 baseline. TB42-EXEC does not promote this execution or
alter stable regression accounting; independent TB42-REV owns interpretation and accounting decisions.

## EC7 measurement rows — preserved verbatim by identity

The four protected RED identities each reported `regionFrontierComponentCount = 0` through the existing assertion
(`actual: 0 vs 0`) and the following CB47 measurement row:

| Ordinal | unlabeledFaceCount | frontierPartitionComponentCount | ownerConsistencyRowCount | regionFrontierLocator | regionFrontierLocatorSurvivedGuard | failure source face in partition | failing-region source faces | failing-region source faces in partition |
|---:|---:|---:|---:|---|---|---|---:|---:|
| 390 | 226 | 9 | 9 | `none` | `none` | `false` | 10 | 0 |
| 393 | 226 | 9 | 9 | `none` | `none` | `false` | 10 | 0 |
| 406 | 226 | 9 | 9 | `none` | `none` | `false` | 10 | 0 |
| 407 | 226 | 9 | 9 | `none` | `none` | `false` | 10 | 0 |

These are raw measurements only. This EXEC report does **not** select a classification from the review-owned matrix,
redefine the census subject, weaken the oracle, or issue a corrective plan.

## Evidence digests

- `semantic-summary.txt`: `5fab1ae6a866ac40bfff78e9bb65d3b4e2863188c821bebae2da7649ad3ebbf6`
- `frozen-gate-status.txt`: `d8eb292e4cb49c7f77c6d74da85d081cb73b45ede14076b9ef6c9a2730ab8318`
- `ec7-measurements.txt`: `69b6107f8c429dd0fff00f5c6466e55fdc6a20a795407ae2f3ad5ceb74317f96`
- `execution-boundary.txt`: `ee5dd388519620b94bbafdb092411bc8e16632185c01cdf83c6dde9a50de062d`
- `failure-detail-digests.tsv`: `f2b3cb59b79d4497117ecab2e62d6dd5e6476d9089149554173a795f4192e472`

## Stop boundary

`M3-CP4c-3-TB42-EXEC` is complete. No review, diagnosis, promotion, definition change, or corrective planning was
performed in this subturn. Exact next is the independently executed **`M3-CP4c-3-TB42-REV`**. The implementation
and orchestration loop must stop completely at that boundary.
