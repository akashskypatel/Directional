# TB47 RP-01 immutable full gate — verified 500/4 (2026-10-27)

**Canonical turn:** `M6-CP3-TB47-RP01-FULL-GATE` (artifact-only Test + Benchmark). **Verdict:** valid expected-RED gate, exactly RA-166.5 prediction, not CP3 acceptance.

## Immutable authority and execution

- Repository `akashskypatel/Directional`; working branch `agent/surface_cell_quad/p5-recover-bridge-healing`, draft PR #8.
- CB47 semantic source commit `08d41626e3487f3cba2e8fed5fe1f2185da8ac9f`, compiled/package artifact `12732383172` from compile run `40501143033`. Package ZIP SHA-256 `c2bf478d0cd610514528c10db62256e30407c1db600d7b8c2723371f765d910e`; 28/28 package checksums and GMP/GMPXX linkage previously verified, compile-boundary `runtimeExecution=false`.
- Frozen TB47 v2 case manifest `.agents/Directional/Architecture_M6_CP3_TB47_Full_Gate_Case_Manifest.tsv`: SHA-256 `488a20b658fc18ddf64addacd9f3150b35b68b067fd37ba7b11346db958d5955`; harness `.agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh`: SHA-256 `142321061c57d130a9c73548ce93f52147ebeaeb4c45d3d1c48830e72e2ef93d`.
- Executor authority SHA `e72edff2b05d3fb3ba4afb6440daa3ef3f45cd43`; dispatch event commit `21dfb46bf8815e6cb92468742475bb4bd92a531c`; [Actions run 40504055818](https://github.com/akashskypatel/Directional/actions/runs/40504055818) (runtime job `122188877343`, success), authoritative mailbox key `m6-cp3-tb47-rp01-full-gate-20261027-v1` on `workflow-mailbox`.
- Result artifact `12734719880`, ZIP SHA-256 `f03efe3c2f75b113ac9e05329799955e4306d611feb4d83c38a2cd672be6b04d`; independently checked 1,014/1,014 unique internal manifest entries and result ZIP members, 504/504 manifest↔ledger matches, independent raw GTest run logs, per-process time receipts and raw log SHA-256s.
- Execution boundary: `planned=504`, `executed=504`, `passed=500`, `red=4`, `missing=0`, `skipped=0`, `duplicate=0`, `control_bad=0`, `unexpected_pass=0`, `later_positive_red=0`, `red_site_bad=0`, `postflight=true`, harness `exit=0`. `compile=false`, `configure=false`, `relink=false`, `benchmark=false`; one fresh GTest process per identity. No source, test, selector, manifest, fixture, or harness mutation.

## Registered REDs — independently matched first failures

| Row/identity | Exact first failure | Witness / owning cluster |
|---|---|---|
| 12 / `focused30:12` | `SurfaceCellTransitionQuotientTests.cpp:5581` | `A5:OccurrenceHardRailTransportMismatch`; G |
| 484 / `selector:442` | `FieldTransportAtlasTests.cpp:2856` | `code=SingularityMismatch;sourceEdge=(2,3)`; G |
| 492 / `cp3entry:1` | `SurfaceCellTransitionQuotientTests.cpp:2916` | `selected=c0 fromGauge=0 toGauge=0`; G |
| 493 / `cp3entry:2` | `SurfaceCellTransitionQuotientTests.cpp:3154` | `D2/RA-38 requires an ACTUAL A4-produced paired two-carrier HardRail (1,4)->(4,7)`; E2 |

Every one of the other 500 identities passed (including re-homed `selector:201` and `cp3entry:4`), all GUARD/POSITIVE cases remained valid, and no RED first-site mismatch occurred. Ledger assertion rows with `reason-not-observed` remain assertion evidence, not synthetic typed product rejection classifications.

## Regression disposition and successor

No new stable regression is established: the four REDs are previously registered candidate obligations and remain Review-owned. Stable accounting **66 events / 17 categories / 49 recurrences**, debt **1**, unchanged. Last accepted CP2 **491/491**; selector497 remains byte-frozen and unpromoted; CP3 remains candidate, RP-01 open, RP-02 unreached. TB46 predecessor was 498 PASS / 6 RED; TB47 improves expected candidate coverage to 500 PASS / 4 RED, **without** full gate promotion.

Per RA-166.5, authorized successor is **`M6-CP3-DEFN-RP01-TB47-GAUGE-CLUSTER`** (independent Review, scratch-probe-backed), followed separately by Review `M6-CP3-DEFN-RP01-E2-RAIL-VERTEX-ADJACENCY-PATCH`. This TB turn does not begin Review or change accepted tests.
