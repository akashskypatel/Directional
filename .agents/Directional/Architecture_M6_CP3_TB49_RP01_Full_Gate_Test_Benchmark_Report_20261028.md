# TB49 RP-01 — immutable 504-case full gate (2026-10-28)

**Canonical turn:** `M6-CP3-TB49-RP01-FULL-GATE-EXEC` (artifact-only TB-EXEC). **Observed: 504 PASS / 0 RED.** This remains candidate evidence pending the distinct independent `M6-CP3-TB49-RP01-FULL-GATE-REV`; no CP3 acceptance or selector promotion is claimed.

## Immutable execution and source authority

- Source: CB49E semantic SHA `092b52eba881e3bafbff4fa263f84f96cf648838`. Compile run `40770409537`, immutable package `12852132570` ZIP `24a0beb14cc0766a7f77ba5c5ccdffc76b5bbfbe798c11170d6db2ba1c94d022`, 28/28 package checksums.
- Frozen manifest `Architecture_M6_CP3_TB49_Full_Gate_Case_Manifest.tsv`, SHA256 `a0e39fa25d707bfc8eabb25ac9e8c494cff8ebf032e2040718b90366d0250ef0`; 504 distinct rows (497 GUARD, 7 POSITIVE). Harness `m6_cp3_targeted_artifact_harness.sh` SHA256 `142321061c57d130a9c73548ce93f52147ebeaeb4c45d3d1c48830e72e2ef93d`, unmodified.
- Executor snapshot `a3991ce602118e93538eb4e4ff5b07df6b92c919` (snapshot run 40775980641, source archive artifact 12854811850; 5966/5966 checksums). Request event `5fcf815fcac7f09874dfd6a93dfef76415d07ae3`, dispatcher mailbox `m6-cp3-tb49-rp01-full-gate-20261028-v1` on orphan `workflow-mailbox`.
- [GitHub Actions run 40776332136](https://github.com/akashskypatel/Directional/actions/runs/40776332136), immutable result artifact `12857282498`, ZIP SHA256 `3113383ccc64bda5747e9f115e95cafa60e67f569f84b40b22ed6c69cea692db`, result manifest 1014/1014 verified; all 504 manifest identities joined to unique ledger entries and native log digests.
- Gate: planned=504, executed=504, passed=504, red=0, missing=0, skipped=0, duplicate=0, control_bad=0, postflight=true, exit=0; immutable postflight. `configure=false`, `compile=false`, `relink=false`, `benchmark=false`; no build, package repair, selector edit, source/test/fixture modification, or additional binaries.

## Native RED evidence

- None observed.

## Regression classification and successor

**Candidate/non-stable:** No observed RED or newly introduced regression in the 504 selected cases. Stable **66/17/49, debt 1** unchanged in TB49 execution. CP2 **491/491** remains the last accepted gate; selector497 remains frozen/unpromoted. RP-01 and CP3 remain open; RP-02 unreached. Do not infer direct SurfaceCells production acceptance from this full gate.

**Authorized successor:** `M6-CP3-TB49-RP01-FULL-GATE-REV` (separate independent Review). Do not execute that review or subsequent implementation in this TB-EXEC turn.
