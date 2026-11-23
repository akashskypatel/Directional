# CB-195 recovery record — compile pending (2026-11-23 UTC)

Canonical turn: `M6-CP3-CB-195-P13-EXACT-SOURCE-PATH-RETRACE-ALONG-EDGES`.

This record preserves a partially completed Code + Build turn. It is NOT a compile acceptance record and does not authorize TB-EXEC-174.

## Source and patch authority

- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 draft.
- Exact source snapshot: run `45196731432`, commit `e6c1555f0ceb531d35ee46c7093da1f8068eed9c`, artifact `14828981579`, ZIP SHA-256 `34d74e2c5d25475da9f2a1c48b5ed754a823566b4abd16d98e4f1484d9d7cb1a`. All 5,808 file checksums were verified locally.
- Frozen approved two-file diff: `.agents/Directional/Architecture_M6_CP3_CB195_P13_Exact_Source_Path_Retrace_Along_Edges_Exact.diff`, SHA-256 `72fa4fa63c38e831fe6b1a03dd21f166a180fb255395c84cacd7e3454ba8d315`, +91/-0.
- Source commit applied and pushed: `29415df1ca8d76825a531092f65ff85e4ecd3b9d`.
- Final Git blob `include/directional/authority/ExactSourcePath.h`: `a968576efdc02027c7e1c5c2ec2cb7cf19edeeb7`.
- Final Git blob `tests/FieldAlignedCurveNetworkTests.cpp`: `bfc99a2232412ce0edafc0a2de66ae30aa2c1023`.
- Exact recovery patch (v2): `Directional__M6-CP3-CB-195-P13-EXACT-SOURCE-PATH-RETRACE-ALONG-EDGES__base-e6c1555f0ceb__work-preservation-v2.patch`, SHA-256 `193f5e24e980a94843b966e90b03020e1049202e767cd025865e5148bb4fdcd4`, diff body SHA-256 `9f43ba4b788492c1dd9af9d0298b1524286ccf8b19acd344b6a6ef608839a72e`. The wrapper separates intended paths with semicolons.
- Initial application run `45197492357` failed without pushing code because its wrapper separated intended paths with a comma. The corrected application run `45198021085` succeeded; result artifact `14830580338`. Both transient Google Drive staging files were permanently deleted by the owner-authorized connector after the successful push.

## Compile request — awaiting terminal evidence

- Dispatcher request commit `dbb00b334ab1c6e68f7c3835d662c431274573d3`.
- Mailbox key `m6-cp3-cb195-compile` on orphan branch `workflow-mailbox`.
- Exact compilation source SHA `29415df1ca8d76825a531092f65ff85e4ecd3b9d`.
- Requested targets: `directional_core`, `directional_pipeline`, `directional_surface_cell_authority_kernel_tests`, `directional_surface_cell_producer_tests`, `directional_surface_cell_completion_tests`, `directional_surface_cell_validation_tests`, `directional_compiled_api_tests`, `directional_benchmarks`.
- Mandatory GMP/GMPXX compiler/link evidence and `runtimeExecution=false`.
- At 2026-11-23T14:53 UTC, `.workflow-mailbox/m6-cp3-cb195-compile/latest.json` was not yet published. Do not treat this as a failure or success.
- No executable tests, benchmarks, runtime invocations, or successor work were performed in this turn.

## Continuation action

Remain on CB-195. Read the existing compile mailbox and exact run/artifact when it becomes available; verify every target, GMP/GMPXX linkage, packaged source, and `runtimeExecution=false`. On a real compile failure follow the Review stop rule and report exact logs. On verified success finish Code + Build documentation and cleanup, update handoff/TODO and close the SAME CB-195 turn with its final STATUS write. Only a later turn may begin TB-EXEC-174. The temporary source-snapshot trigger file `.agents/connector-triggers/source-snapshot/m6-cp3-cb195-20261123.txt` still needs authorized cleanup. Avoid deleting it directly if that retriggers snapshot automation.
