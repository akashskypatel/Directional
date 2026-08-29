# Architecture M3 CP4c-2 — TB-X2-R3-EXEC Artifact-Only Evidence

- Phase: `M3-CP4c-2-TB-X2-R3`
- Subturn: `M3-CP4c-2-TB-X2-R3-EXEC`
- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`
- Evidence source: `c552a5a4a318063cde2564c40773ec7edaf064f6`
- Immutable package: `9704935112`, `sha256:dcb96ce4e37b2bc58ef69f2146723624575c32c090429ba00e6612b07938133f`
- Runtime run/job: `33222551366 / 99019499929`
- Result artifact: `9705692837`, `sha256:ba989d0ddd3bd244f03c8242060ded9f9c58b33679893ab0ddf1cc5fb8d015f5`
- Runtime log artifact: `9705693025`, `sha256:ab653c13ec7b0eec30f2736a17bbf44406afa7c828cb1fddbadea795aa6701a6`
- Benchmark execution: **none**

## EXEC verdict

**COMPLETE / VALID DIAGNOSTIC SEMANTIC RED / PLANNED STOP IN D1 BEFORE THE TORUS PUBLICATION.**

Immutable preflight passed and the single authorized D1 identity selected exactly once. D1 exited `1` before
publishing any `m3Cp4c2Y1` record. The exact failure is:

```text
../../Directional/Directional/tests/FieldAlignedCurveNetworkTests.cpp:5946: Failure
Value of: fixture.network.has_value()
  Actual: false
Expected: true
witness=torus;error=field-transport-atlas-unavailable
```

This is earlier than Z6's required torus `48/48` publication. Therefore the EXEC stop rule fired: no torus
control was adjudicated, Z3 self-consistency was not reached for any witness, and D2 was correctly not executed.
This subturn makes **no Y5 branch inference** and gives no gate credit.

## Immutable preflight and postflight

Preflight verified all plan authorities before runtime:

- artifact outer digest exactly `dcb96ce4e37b2bc58ef69f2146723624575c32c090429ba00e6612b07938133f`;
- internal `SHA256SUMS` passed for all 28 entries and the producer executable retained mode `755`;
- source commit `c552a5a4a318063cde2564c40773ec7edaf064f6`;
- preflight/build exit codes `0`, all packaged `source-status-*.txt` empty;
- command boundary `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `exactArithmeticBackend=GMP`;
- GMP/GMPXX link evidence present and the eight standard compiled targets match exactly;
- packaged source archive SHA-256 `e533669daa7ac0219bc6ca6bd7d72db2901af32937848c3f37f02b772345ae02`;
- fixture source materialized at the compiled absolute root `/home/runner/work/Directional/Directional` and made
  read-only before runtime;
- frozen selector hashes recomputed unchanged: first 316 `601ce2b6…0193c`, first 346 `20d3b0b1…3e46a`, first
  353 `51ff96d7…ac6a5`, 355 `e9d88f11…afeaa`, 357 `b896d0db…64dc70`, 358 `6eda3aad…fbe62`.

Recursive package and materialized-source byte **and mode** inventories were captured before runtime and repeated
after the stop. All four comparisons match. No configure, compile, relink, generated discovery, fixture-byte
mutation, package repair, selector gate, or benchmark occurred.

## Ordered runtime evidence

D1 command, one fresh process:

```text
./bin/directional_surface_cell_producer_tests \
  --gtest_filter=GlobalTopologyPlan.Cp4c2IndependentNetworkOnlyCellularityOracleIsObservable
```

Observed:

- selected identities: `1`;
- process exit: `1`;
- `m3Cp4c2Y1` publications: `0`;
- first/last failing witness: `torus`;
- exact pre-publication error: `field-transport-atlas-unavailable`;
- elapsed harness time: 14 ms as reported by GoogleTest;
- D1 status: `D1_CONTROL=STOP`.

D2 status: `D2_SKIPPED_DUE_TO_D1_STOP`. This is required by the frozen R3 plan and is not missing evidence caused
by orchestration.

## Orchestration precursor

The first caller attempt, run `33222474179`, ended `startup_failure` with zero jobs and zero Directional runtime
because the caller granted `contents: read` while the reusable observer graph contains a statically validated
`contents: write` branch-file job. The caller permission ceiling was corrected without changing package, source,
test, fixture, selector, or runtime semantics. Run `33222551366` then passed schema validation and executed the
artifact-only workload. This repeats the already-recorded non-stable reusable-observer permission-ceiling
orchestration pattern and changes no stable regression count.

## Candidate/accounting status at EXEC close

- `M3-CP4c2-TB-X2-R2-CAND-01`: **ACTIVE**. Closure condition was not reached because no corrected torus
  publication exists.
- `M3-CP4c2-TB-X2-R2-CAND-02`: **ACTIVE**. No corrected D1 witness publication exists, so the all-three
  self-consistency closure condition was not reached.
- `M3-CP4c2-TB-X2-CAND-04`: **ACTIVE / UNLOCALIZED**. D2 was prohibited after D1 stopped.
- `M3-CP4c2-TB-X2-R3-CAND-01`: **ACTIVE / DIAGNOSTIC-PRECONDITION / UNLOCALIZED / NON-STABLE**. Runtime localizes
  the new failure to torus diagnostic fixture construction before network publication, with
  `field-transport-atlas-unavailable`; EXEC evidence does not establish whether the underlying cause is a
  diagnostic fixture/field precondition, authority-construction defect, or another test-side assumption. The
  evidence-only REV subturn owns that adjudication.

Stable accounting remains **42 events / 14 categories / 28 recurrences**; produced-witness debt remains **5**;
M3 package count remains **60**. CP4c-2 remains runtime-unaccepted. `selected_r2_branch=NONE`,
`selected_gate=NONE`, and `gate_execution_authorized=false` remain binding.

## Exact next state

`M3-CP4c-2-TB-X2-R3-REV` — evidence review only, consuming this preserved EXEC evidence with **no new runtime**.
The review must not rerun unchanged D1, must not run D2/355/357/358, and must not start CB3 before adjudicating
the new pre-publication stop and the still-active candidates.
