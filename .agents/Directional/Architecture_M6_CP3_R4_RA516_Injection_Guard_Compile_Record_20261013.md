# M6-CP3-CB1-ENTRY-R4 — RA-51.6 injected edge-table guard regression

**Boundary:** continuing Code + Build only. This record is an incremental compile checkpoint, not R4 completion or permission for TB497.

## Authority and change

- RA-51.6 confirms that RA-48.3's `TriMesh::set_mesh` guard G1 is unconditional: edge quantities are derived from source faces, and any caller-supplied EV/FE/EF table triplet must be identical. A forged table cannot bypass this authority.
- Exact source snapshot: `26f176262960573cf605253d985d644981f12532`, workflow [38417355295](https://github.com/akashskypatel/Directional/actions/runs/38417355295), artifact `11824947975`, outer SHA-256 `5a469f69c66dfbc1637dd2de4aea43a31310d4569577c27605a7b67dffbb64af`. Internal source manifest verified 5696/5696.
- Only `tests/SourceGridRecoveryAuthorityTests.cpp` changed in semantic commit `c1be17130799c42bb7791c16f0fc65a59e24f9fb`; exact GitHub blob matches locally generated source (`80ac08dbec466bab7949c3f72d4e8f027ffa71ef`). Local forward and reverse patch application checks passed. Recoverable patch `directional-r4-ra516-injected-edge-guard.patch`, SHA-256 `9997d3c705ec25b409682352aac95cd5b341498b0be05823bf57e0ab5a55e4a1`.
- New GTest `MilestoneGP26.InjectedEdgeTablesMustMatchDerivedSourceFaces` uses the actual plane mesh fixture and asserts that exact derived EV/FE/EF input is accepted and separately altered EV, FE, and EF inputs are rejected as `std::runtime_error`. No existing test identity, frozen 497 selection, production authority guard, fallback, workflow permission, or ABI changed.

## Mandatory compile-only evidence

- Durable dispatcher request commit `06f92a573a972b03a09ed377ba030b2ef2a941d0`, mailbox `.workflow-mailbox/m6-cp3-r4-ra516-table-g1-compile/latest.json`.
- [Workflow 38418360365](https://github.com/akashskypatel/Directional/actions/runs/38418360365): `compile / compile` succeeded for exact semantic source `c1be17130799c42bb7791c16f0fc65a59e24f9fb`.
- Immutable result artifact `11824434528`; outer SHA-256 `da7dbb644851cb8c67f86255ea2243d7892ee2cdb88e83fc5477a5b48067938b`. Independently verified 28/28 packaged SHA256SUMS, all eight requested targets, preflight/build exits 0/0, five empty source-status files, `DIRECTIONAL_ENABLE_GMP=ON`, authoritative generated linker with both GMPXX and GMP, `exactArithmeticBackend=GMP`, `runtimeExecution=false`.
- **No Directional executable, test, benchmark, frozen TB497, or runtime verification was executed.** The new oracle is compiled but not runtime-validated.

## Remaining R4 obligations and entry policy

RA-51 retires only its two unreachable RA-46.5 negatives; the named guards remain fail-closed. RA-49.2's duplicated-endpoint first-rejection test is already source-authored but not runtime verified. RA-43.1 and global RA-43.4, other reachable RA-46.5 negatives, RA-47.12 liveness, the 39 endpoint / 34 Phase10 / seven DCEL / 88 lost accepted CP2 / six CP3 gates, organic produced D1/D2/D3/D5/A6/A7 and genuine odd-tau multi-carrier obligations remain open. Ledger 66/17/49 and debt 1 unchanged. PR #8 stays draft, unmerged. Same canonical `M6-CP3-CB1-ENTRY-R4` continues; do not start a successor or run TB497.

**Tool policy note:** during this session the mandatory snapshot READ_MODE pre-read gate was missed when several source/document connector reads preceded selection. The error was disclosed, piecemeal inspection stopped, and a fresh complete 5696/5696 verified exact-source snapshot was used for all subsequent local analysis. Preserve this finding for policy correction; do not treat the violation as precedent.
