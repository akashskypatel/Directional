# TB36 immutable baseline — invalid orchestration attempt (2026-10-25)

**Canonical attempted turn:** `M6-CP3-TB36-RP01-PERIODIC-MONODROMY-BASELINE`.

**Outcome:** orchestration failure before the immutable package was downloaded or any selected test was executed. **No semantic RED, GREEN, regression, or first rejecting producer is established.** Do not promote this attempt to TB36 evidence and do not start the CB36 production repair.

## Exact authority

- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 (draft).
- Immutable semantic source: `7de805c487fa66bcb96744f51b8bfbe7210ee8dc`.
- CB35-R2 package: GitHub Actions artifact `12580989509`, SHA-256 `a594b8617493087ff9ab50391e30cc7a8870f2dcf92427c03899b076e344bb54`; previously reviewed 28/28 internal hashes, 8 GMP/GMPXX compilation targets and `runtimeExecution=false`.
- Frozen TB36 five-row manifest: `Architecture_M6_CP3_TB36_Periodic_Monodromy_Baseline_Case_Manifest.tsv`, SHA-256 `ab2711b2efc64103a9106b9a63f03064c63dc6e93a16c0602f3c6b3f866c1d0c`.
- Source snapshot: `e2f3f19ba3573a70cbeda3761d8b8ee51d9a2985`; run `40155167844`, artifact `12583269882`, ZIP SHA-256 `230cae19c6d6e81d23b4eb3ef2907cbe3191b354e944ab398d45dec6aa6dba9d`; internal archive and file manifest verified locally.
- Runner harness commit `e9850781601e579c7332683a207a70034bae3f0e`, `.agents/Directional/tools/m6_cp3_tb36_periodic_monodromy_baseline_harness.sh`, SHA-256 `99eb3f4bbdaab1c5e5c7cd385738f8349c4fbfbbb96edb34719518423cbcf0f7`.
- Dispatcher request commit `1e4d0d9e0b8fbed72e57ab2694582cb0eda8b5e5`.
- Failed run `40155549123`; `test_benchmark / runtime` job `121056134755`, harness exit `90`. Result artifact `12584118434`, SHA-256 `35184c73ecaed4089ba8a9891d1dfcb4a4ed5fc36bcb3ca236542de23189a8f9`; log artifact `12584298170`, SHA-256 `c646e1480f87f22705dbbe433a63f98e070b35d033fc6a1534ff651c74398f93`.

## Failure and corrective scope

The harness was derived from the TB35 artifact-only runner, but its case uniqueness preflight retains `== 13` for both case-name and identity cardinality even though TB36 deliberately has five rows. The runner exits before fetching the package:

`TB36_HARNESS_FAILURE RuntimeError('duplicate case')`

This error text is misleading: the five-row TB36 manifest is independently unique. Correct both cardinality comparisons to **5**. Separately, the newly introduced source-location regex is overescaped inside a Python raw string; use the intended single regex backslashes for `\.cpp` and `\d+` (or an equivalent correct parser). Independently verify both with the manifest and representative raw GTest text without executing any Directional binary.

**Required next action:** route to a bounded **control-plane-only Code + Build orchestration correction** under `Turn_Cadence.md` §5. Correct the harness only; do not change immutable package, semantic tests, frozen selectors, fixtures, production implementation, or required workflow permissions. Author an explicit successor turn and fresh executor SHA, then rerun all five frozen identities through a new TB attempt. The invalid attempt must remain retained as provenance, never as semantic outcome. A semantic TB36-REV is authorized only after a valid TB36 execution.

Stable accounting remains **66 events / 17 categories / 49 recurrences**, produced witness debt **1**. CP2 accepted **491/491**; TB32 candidate **481/500**; TB35 **11 PASS / 2 RED**; frozen selector497 unchanged; RA-152 F1 unresolved.

## Local turn observations

The initial source-inspection access preceded the mandatory `READ_MODE=snapshot` choice, contrary to the tool conservation policy. Inspection thereafter used the verified snapshot. No local builds or Directional binaries were executed, and no test bodies or fixtures were modified.
