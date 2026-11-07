# TB48 RP-01 — immutable 504-case full gate (2026-10-28)

**Canonical turn:** `M6-CP3-TB48-RP01-FULL-GATE-EXEC` (artifact-only TB-EXEC). **Observed:** 502 PASS / 2 registered RED. Valid expected-RED candidate, **not** CP3 admission or accepted-green selector promotion. Independent Review `M6-CP3-TB48-RP01-FULL-GATE-REV` remains required.

## Immutable source and execution

- Semantic CB48 source: `4c611941f0bee7dc2515755fbd159402463879e2`. Compile run `40727946150`; GMP/GMPXX eight targets compiled, runtimeExecution=false. Immutable artifact `12834041300`, ZIP SHA-256 `a544b0c6c5756b428c90377ce36b3be6322620af167a6a7db908d7882761fe3d`; package 28/28 checksums.
- Frozen manifest `.agents/Directional/Architecture_M6_CP3_TB48_Full_Gate_Case_Manifest.tsv` SHA-256 `a3187d5557d792fe22bfd500e14fb0de8e6e14c06888aa17d18b7144ab5900bb`: 504 distinct identities (497 GUARD, 5 POSITIVE, 2 RED). Harness `m6_cp3_targeted_artifact_harness.sh` SHA-256 `142321061c57d130a9c73548ce93f52147ebeaeb4c45d3d1c48830e72e2ef93d` unchanged.
- Executor `e67b5effd34e58548d2ed0992f43c51b5eecf769`; request event `1e801d19368b088f4b01d9facda4508b22ca93d3`. [GitHub Actions run 40731722985](https://github.com/akashskypatel/Directional/actions/runs/40731722985), runtime job `122969711723`. Mailbox publication: check `m6-cp3-tb48-rp01-full-gate-20261028-v1` on orphan `workflow-mailbox` for authoritative source/event correlation; CI artifact and job were independently reconciled by exact run ID.
- Result artifact `12836819707`; independently downloaded ZIP SHA-256 `3aa8b6bc597abef4b4eb3e8168243e7854e09aea95f3e73fc4d531a92dc20131`. Internal SHA256SUMS: **1014/1014** unique exact files verified. Manifest↔ledger unique identity and row joins **504/504**, 504 independently spawned GTest processes, raw log SHA-256 **504/504**; two registered first-failure pins independently matched to raw logs.
- Execution receipt: `planned=504, executed=504, passed=502, red=2, missing=0, skipped=0, duplicate=0, control_bad=0, unexpected_pass=0, later_positive_red=0, red_site_bad=0, postflight=true, exit=0`. `configure=false`, `compile=false`, `relink=false`, `benchmark=false`; no package or source/test/fixture/selector/harness repair or mutation.

## Two registered red witnesses

| Manifest row / identity | Native first failure | Classification |
|---|---|---|
| 492 / `cp3entry:1` | `../../Directional/Directional/tests/SurfaceCellTransitionQuotientTests.cpp:3027: Failure` | Source-produced odd face-gauge torus exhibits A4 periodic endpoint-state gauge non-covariance; P-G3 production candidate, to be adjudicated by Review. |
| 493 / `cp3entry:2` | `../../Directional/Directional/tests/SurfaceCellTransitionQuotientTests.cpp:3183: Failure` | E2 rail-vertex adjacency witness lacks the specified ACTUAL A4-produced paired two-carrier HardRail; witness/production reachability still requires independent Review. |

The other 502 cases passed (all 497 guards and five positives); the old G1 (`selector:442`) and G2 (`focused30:12`) test-authority red cases now pass under RA-167 re-homing. **No repair or expected-red waiver occurred.**

## Root cause, accounting and next action

P-G3 is now reproduced by CI on immutable CB48 source and legal source-level relabel, consistent with RA-167.3; the A4 relationRotation derives from the two From-endpoint carrier-face gauges, while To endpoints may have different gauges (`SurfaceCellTracing.cpp:19088–19123`, `:8194–8218`). This identifies a candidate production defect, not a completed correction. The E2 RED remains a separately registered reachability and witness obligation. No newly introduced PASS→RED or unregistered first failure was observed. Whether CI reproduction satisfies the stable-regression promotion policy is explicitly reserved for independent TB48-REV; **stable 66/17/49, debt 1 remains unchanged in this execution turn**. CP2 **491/491 accepted** remains the last accepted gate; selector497 frozen, CP3 and RP-01 open, RP-02 unreached.

**Authorized successor:** `M6-CP3-TB48-RP01-FULL-GATE-REV` (probe-capable independent Review), which verifies this evidence, decides P-G3 stable accounting and frozen TB49 manifest; no CB49/CB49E or new source work begins in TB48-EXEC.
