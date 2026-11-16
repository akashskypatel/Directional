# CB142 — Cross-face branch oracle correction (Code + Build, 2026-11-16 UTC)

**Canonical turn:** `M6-CP3-CB142-P13-CROSS-FACE-BRANCH-ORACLE-CORRECTION`.
**Authority:** `Architecture_M6_CP3_TB122_REV_P13_Adversarial_Architecture_Review_20261116.md`, C1 and the frozen single-turn work order.

## Scope and exact source

- Replaced one invalid cross-face branch-number equality assertion in `tests/FieldAlignedCurveNetworkTests.cpp` with independent exact A1 transport and destination-wedge/outflow checks. Same-frame equality is retained. The correction keeps follow kind, face, carrier, component, and topology-region checks.
- Cross-case proof compares the source branch after the signed A1 transport lift to the unique strictly outward destination pairing. Negative controls reject a wrong branch, wrong lift, inward ray, and radial-grazing ray. These are assertions in the test, **not passing runtime evidence**.
- Only the test source changed: 115 insertions, 1 deletion; no product code, fixture, selector, manifest, workflow, or reusable permission changes. Semantic implementation commit: `57b28b737fd92b083d24d882152dea186211f735`.
- Source snapshot `ac1330de2a758cb4439e2e6c08864968d760dda9`, [run 43862825564](https://github.com/akashskypatel/Directional/actions/runs/43862825564), source artifact `14224276991`. Exact work-preservation patch SHA-256 `a7046c070b33d2a2e80897a3544a44453c8c3a073d2a6a3b36ca19b00bdb8044`, diff body SHA-256 `90fc086947745bca89d3c0219e3979e71b22f611cf2f149ad536c60c3ee8cab7`.
- Google Drive patch application [run 43864015905](https://github.com/akashskypatel/Directional/actions/runs/43864015905) succeeded. The applied commit changed only the named test file. The temporary Drive patch was deleted after verified application. Recovery patch remains in the ChatGPT Library.

## Build and package evidence

- First dispatcher request [run 43864341457](https://github.com/akashskypatel/Directional/actions/runs/43864341457) failed during request parsing: `unknown request fields: retention_days`. It did **not** compile or execute test code. This error was corrected by replacing the dispatcher request; no source patch change was needed.
- Corrected request `m6-cp3-cb142-cross-face-oracle-compile-20261116-v2`, event SHA `ec00a107d176ee3255664ddefed24b2847eacdd2`, compiled exact source `57b28b737fd92b083d24d882152dea186211f735` in [run 43864872021](https://github.com/akashskypatel/Directional/actions/runs/43864872021): **SUCCESS**.
- Immutable package artifact **`14224898790`**, outer ZIP SHA-256 `98f448f9e5b5ebcacbd1884ad4e62415d7c10d5878da0ccf1438654b4aeaf52b`. All **28/28** internal checksums independently matched.
- Compiled all eight approved targets: `directional_core`, `directional_pipeline`, `directional_surface_cell_authority_kernel_tests`, `directional_surface_cell_producer_tests`, `directional_surface_cell_completion_tests`, `directional_surface_cell_validation_tests`, `directional_compiled_api_tests`, `directional_benchmarks`.
- `DIRECTIONAL_ENABLE_GMP=ON`. Link evidence lists `/usr/lib/x86_64-linux-gnu/libgmpxx.so` and `libgmp.so`; preflight and build exit codes zero; source status empty. Metadata states `turnBoundary=Code+Build-only`, `exactArithmeticBackend=GMP`, `runtimeExecution=false`. No Directional test, benchmark, census, or compiled binary was executed during CB142.

## Disposition and next gate

CB142 meets the test-only implementation and compile-only requirement. This does **not** establish that row949 passes or that the producer chooses the correct destination branch. If TB123 finds the independent oracle and product branch disagree, stop and send the mismatch to independent Review without changing product behavior inside CB142.

**Exact separate successor:** `M6-CP3-TB123-P13-CROSS-FACE-ORACLE-FOCUSED-EXEC` (immutable artifact-only focused execution of rows 948 and 949 plus negative controls). The subsequent independent Review is `M6-CP3-TB123-REV-P13-CROSS-FACE-ORACLE-OUTCOME`. Full gate, production census, BunnyRandom terminal inventory, and any semantic repair stay deferred until their separate authorized turns.

Unchanged authority: accepted CP2 **491/491**; stable **66/17/49**, witness debt **1**, deferred **81**. D11=A, D12=A, D10 deferred, D6 pending; O42/O43/O44 open; CP3/selector497 not promoted and `chainRimSchedules=false`. Vase O41 remains separate.

## Documentation audit disposition

- The static document-drift audit was run against both the previous handoff and the updated local documents. Both versions produced the same three existing errors: handoff above its size budget; one historical `CURRENT` heading in the handoff; and `ORIENTATION.md` above its size budget. No additional audit error appeared in this turn.
- The errors remain open documentation debt. Any consolidation or reduction of protected historical material requires its own authorized scope and preservation review. This Code + Build turn does not claim a clean documentation audit or alter those protected documents.
- The first document-apply request [43867537904](https://github.com/akashskypatel/Directional/actions/runs/43867537904) failed before commit because the patch header separated intended paths with commas instead of semicolons. The corrected request [43867932152](https://github.com/akashskypatel/Directional/actions/runs/43867932152) applied the unchanged diff body as commit `589f1b0b6eac36362c5263de75a327bce590f9c6`. The four intended document paths were independently checked. Both temporary Drive staging files were deleted successfully.
