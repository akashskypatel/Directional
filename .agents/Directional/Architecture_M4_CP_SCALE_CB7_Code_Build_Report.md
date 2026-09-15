# M4-CP-SCALE-CB7 Code + Build Report — S3 exact-repeat typed termination

**Turn:** `M4-CP-SCALE-CB7`
**Boundary:** Code + Build only; no Directional runtime.
**Result:** COMPLETE / COMPILE + PACKAGE GREEN / RUNTIME UNADJUDICATED.
**Exact successor:** `M4-CP-SCALE-TB6-EXEC`, then mandatory `M4-CP-SCALE-TB6-REV`.

## Implemented scope

CB7 implements only the frozen S3 publication seam. The exact traversal key remains
`(sourceFace, branch, incomingCarrier, exact FieldBoundaryPoint entryPoint)`.

- Added typed `FieldAlignedLimitCycleTermination` carrying the complete repeated-state locus.
- Added `FieldAlignedNetworkEventKind::LimitCycleTermination`.
- Added `publish_field_aligned_trace_traversal_state(...)`: only
  `FieldAlignedTraceTraversalStatus::CycleDetected` publishes the semantic terminal.
- Preserved `CombinatorialRecurrenceExceeded` and `StepBudgetExhausted` as fail-closed typed errors.
- Extended candidate-trace/proposal publication so the terminal reaches the production event seam without a repair path.
- Added focused producer identity
  `M4CPScaleS3.ExactTraversalStateRepeatPublishesLimitCycleTermination`, covering exact repeat, different exact entry, four load-bearing-key tamper controls, combinatorial recurrence, and step budget.
- Added the executable artifact-only `Architecture_M4_CP_SCALE_TB6_Test_Plan.md`.
- Selector424 remains unchanged at
  `f202a1720c0a5288471d04836402b8432eb6f4f788da68a12e70dacb875466ca`; selector425 was not authored.

## Compile correction provenance

The first semantic patch accidentally deleted the existing local
`using directional::authority::NetworkNodeId;` alias in
`tests/FieldAlignedCurveNetworkTests.cpp`. Compile run `35020345003`, job
`104554207559`, therefore failed after the `directional_core` preflight with the
first actionable error `NetworkNodeId has not been declared`. No Directional
runtime executed.

The correction restored only that pre-existing alias. Drive apply run
`35022732817` succeeded and produced exact corrected semantic source
`153047c3f92e9b9b784e11eaee1ede2de5628470`. The correction transport patch was
`4e632f960e965f4218953f12eae62db5ce48c765daeee7131946057813618f07`, with exact
diff-body SHA-256 `a82ef09229d05d589412b1b47fc58c4ed50cc740d24974f2f3427d81990637ec`.
The preceding malformed transport attempt `35022477682` failed verification
before application because its patch lacked the required transport metadata;
it changed no source and carries zero semantic evidence.

## Authoritative compile/package evidence

Authoritative compile run/job: `35022869891 / 104562750677`.

- exact compiled source: `153047c3f92e9b9b784e11eaee1ede2de5628470`;
- result artifact: `10418328122`, provider SHA-256
  `a9f33bce6029022495fccbc4680da9bdd25cf41aa5cc733b2c04335e156ac16e`;
- compile log artifact: `10418537066`, provider SHA-256
  `e0655b106c7803912c882c8c0aeaf84ab1e7e7e3f9c1c015aaa462970232ef75`;
- packaged source archive SHA-256:
  `703dcc22f18ed565b623ef4eb43e117cd8acfd5d982ed0bde111d5cfdd56e0ff`;
- root `SHA256SUMS` SHA-256:
  `d5e2e620f3e5a9e78f4b646be95f872dd78ab8cbee7fe726156abf8249d6d5ad`;
- manifest verification: **28/28 PASS**;
- preflight target `directional_core`: exit `0`;
- all eight approved package targets compiled and linked:
  `directional_core`, `directional_pipeline`,
  `directional_surface_cell_authority_kernel_tests`,
  `directional_surface_cell_producer_tests`,
  `directional_surface_cell_completion_tests`,
  `directional_surface_cell_validation_tests`,
  `directional_compiled_api_tests`, `directional_benchmarks`;
- GMP/GMPXX evidence links `/usr/lib/x86_64-linux-gnu/libgmpxx.so` and
  `/usr/lib/x86_64-linux-gnu/libgmp.so`;
- all packaged source-status receipts are empty;
- `runtimeExecution=false`, `turnBoundary=Code+Build-only`,
  `exactArithmeticBackend=GMP`.

No generated Directional test, benchmark, discovery/list/help/version command,
`ctest`, CLI, fuzzer, or custom runtime input was executed in CB7.

## Authority disposition

The CB7 package is a **candidate only**. Accepted runtime authority remains TB5
package `10407605295` / source `0d8e4aa3472fae26c22d49bc0d81acc5e98378d3`
under selector424 **424/424** until TB6 runtime execution and mandatory Review.
Stable accounting remains **49 events / 14 categories / 35 recurrences** and
produced-witness debt remains **5**.

## Successor contract

`M4-CP-SCALE-TB6-EXEC` must consume artifact `10418328122` exactly, execute the
focused S3 identity once in a fresh exact-filter process, then execute accepted
selector424 as 424 fresh exact-filter processes in file order, and preserve exact
immutable pre/post authority. Focused S3 PASS does not create selector425 credit.
Mandatory successor after EXEC is `M4-CP-SCALE-TB6-REV`.
