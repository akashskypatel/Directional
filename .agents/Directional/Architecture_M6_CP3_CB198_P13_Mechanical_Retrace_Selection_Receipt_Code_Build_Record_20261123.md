# CB-198 — mechanical retrace selection receipt (2026-11-23 UTC)

## Situation
The test-only Code + Build turn `M6-CP3-CB-198-P13-MECHANICAL-RETRACE-SELECTION-RECEIPT` is complete. Its authorized successor is `M6-CP3-TB-EXEC-177-P13-MECHANICAL-RETRACE-SELECTION-RECEIPT-FULL-GATE` in a separate turn; no successor work has begun.

## Background
TB-REV-176 H1–H4 and the frozen `gates/Architecture_M6_CP3_CB198_P13_Exact_Manifest.md` authorize exactly the test-only failure-branch diff `Architecture_M6_CP3_CB198_P13_Mechanical_Retraced_Trace_Selection_Receipt_Exact.diff`: SHA-256 `c30811fca14154427a41d5e90f3fb565bbbbfe0b5601eec8bcec36e845e6391b`, 6,026 bytes, +108/−0, one test file. No production selection is wired.

## Assessment
- Exact source snapshot: [run 45279094151](https://github.com/akashskypatel/Directional/actions/runs/45279094151), source `2f29803395cf7398234d1d3318fc53d4d26d9fa9`, artifact `14869013086` ZIP SHA-256 `7b1175c688d5cbe58866dc930b5ba58339a510217a17029e0656c7b94b334000`; source files 5,832/5,832 verified.
- Frozen preimage `tests/FieldAlignedCurveNetworkTests.cpp` Git blob `e21c3362d2a049769ad376b1e79bf59fa6db1999`; exact postimage SHA-256 `75ae997a94d766bcc9cda56f37abbb3bb9e655758d141003cfbf51c6cb638cc6`. `git apply --check` and `git diff --check` pass.
- Only the approved test file changed in [apply run 45279701397](https://github.com/akashskypatel/Directional/actions/runs/45279701397), commit `6cdd23a10ac6f6fbc6c741fb1e18ccff2038871c`; result artifact `14869445555` ZIP SHA-256 `1dcc9ab85161a68ddc5ac0fc3312410c60edd8337a7a8f774ad504653520149f`, `runtimeExecution=false`. Owner retired staged Drive file after successful application.
- GMP/GMPXX compile-only: [run 45280023495](https://github.com/akashskypatel/Directional/actions/runs/45280023495), exact semantic source `6cdd23a10ac6f6fbc6c741fb1e18ccff2038871c`, eight required targets including `directional_surface_cell_producer_tests`. Package artifact `14868834752` ZIP SHA-256 `b5a7104d41e103e3d31094b4d889af1097ffa52edac6ff11fe120acfdb4ee0c9`, compile log artifact `14868729926` ZIP SHA-256 `70b1b0d412086d6a4d3834d04b84b32e3fa4bb6a696707d16e84d1b493075dd5`, internal checks 28/28; `exactArithmeticBackend=GMP`, `runtimeExecution=false`; no project binary, test or benchmark ran.
- TB176 remains the latest runtime gate: 994/1001, seven RED (445/652/653/656/658/660/786). Accepted TB169 993/993; CP2 491/491; stable 67/17/50, witness debt1, deferred81. No CP3/497/D0/H4 promotion; no selector, fixture, product, manifest, or workflow mutation.

## Recommendation
Start only `M6-CP3-TB-EXEC-177-P13-MECHANICAL-RETRACE-SELECTION-RECEIPT-FULL-GATE` in a new turn. Execute the unchanged 1001-row manifest `0f85400ff9713fc8a835f308304ded1db9830e668211bab71c88d580b2e84642` from immutable artifact `14868834752`; compare with TB176 under N1–N3. Permit only the inserted `retracedTraceSelection` receipt in diagnostics; record row652 verbatim and return to independent Review. Expected 994 PASS/seven RED is a prediction, not a tested result.
