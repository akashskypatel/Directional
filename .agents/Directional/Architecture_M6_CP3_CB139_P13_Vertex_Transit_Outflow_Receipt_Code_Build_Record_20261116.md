# CB139 Code + Build — vertex transit outflow receipt

## Situation
`M6-CP3-CB139-P13-VERTEX-TRANSIT-OUTFLOW-RECEIPT` implemented the frozen RA-239 §4 diagnostic source patch and compiled the eight authorized targets. The separate TB120 turn owns runtime evidence.

## Background
- Exact patch `.agents/Directional/Architecture_M6_CP3_CB139_P13_Vertex_Transit_Outflow_Receipt_Exact.diff`: SHA-256 `bd0d7afeaf7c0a3e196907fcba6b8230ec7955d269b75cfb833b6ea15bd05eb7`, 175 lines, two files (+131/−1), unchanged from RA-239.
- Pre-patch source snapshot: `e6f6171f6c345424b600eaea1587da9ae878fbfb`, [run 43807953666](https://github.com/akashskypatel/Directional/actions/runs/43807953666), artifact `14198932803`; source 5,549/5,549 file SHA-256 checks passed.
- Source patch transport: full SHA-256 `8cd7cddf356b9c96f8abedd4c8d7a68f71cc3c9f243c6f91834db531855c25ce`, [apply run 43808435065](https://github.com/akashskypatel/Directional/actions/runs/43808435065); exact semantic source commit `c520674030c76be455111d7c41aae7d5f53ce900`. Temporary Drive patch staged by File ID `1J0wQVWw8YyU3YM7PJgrhy41hJxD8tMEU` and retired after successful application.

## Assessment
- [GMP compile run 43808742663](https://github.com/akashskypatel/Directional/actions/runs/43808742663) **SUCCESS**, immutable package artifact `14199183882`, ZIP SHA-256 `daac64075be07c96f0654a933cb0be919f6ce8046c67104786c1caaa1760d120`, log artifact `14199631933`; 28/28 package SHA-256 entries verified, with clean source metadata and exact source `c520674030c76be455111d7c41aae7d5f53ce900`.
- Eight targets compiled: `directional_core`, `directional_pipeline`, `directional_surface_cell_authority_kernel_tests`, `directional_surface_cell_producer_tests`, `directional_surface_cell_completion_tests`, `directional_surface_cell_validation_tests`, `directional_compiled_api_tests`, `directional_benchmarks`.
- GMP and GMPXX linkage checked. `runtimeExecution=false`; no tests, benchmarks, production census, or TB120 execution. Diagnostic prints are compiled but not observed.
- No production semantics, selectors, gate thresholds, `chainRimSchedules`, or acceptance baselines changed. D11=A; D10 deferred; O42/O43 open; CP2 491/491, stable 66/17/49, debt 1, deferred 81; CP3/selector497 unpromoted.

## Recommendation
**Next separate turn:** `M6-CP3-TB120-P13-VERTEX-TRANSIT-OUTFLOW-RECEIPT-FULL-GATE-EXEC`. Use the immutable CB139 compile package and the unchanged TB119 manifest (947 cases, 1,028 membership, SHA-256 `3aac432b9f466e5ce06601c90a08ad09c1886dfeb97c38b05e9bd46f51a1190b`) plus the three-case census, as defined by RA-239 §5. Record the terminal locus and every `vertexTransitWithoutOutflow` / `vertexTransitSector` line. Do not rebuild or promote CP3 in this Code + Build turn.
