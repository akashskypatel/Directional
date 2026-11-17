# CB143 — exact mandatory-edge terminal inventory (Code + Build; 2026-11-17 UTC)

**Canonical turn:** `M6-CP3-CB143-P13-EDGE-TERMINAL-EXACT-INVENTORY`. Authoritative freeze: [RA-243](Architecture_M6_CP3_DEFN_P13_Edge_Terminal_Inventory_Review_20261117.md).

## Change and source authority

- Applied the exact 223-line RA-243 frozen diff, SHA-256 `c0439b1f303827d2f9584373bf7a8515df771649ff9ab4c04ab9b1d1cc29205b`.
- Implementation commit: `6857c66b788841f8e400151b6068b2f23be25167`. Its only changed files are `src/geometry/EmbeddedGraphTopology.cpp`, `src/geometry/EmbeddedGraphTopology.h`, and `tests/FieldAlignedCurveNetworkTests.cpp`.
- Added exact-parameter ordering, trace-ID tie break, equality classes and the all-offending-edge `SurfaceCutGraph.mandatoryEdgeTerminalInventory` diagnostic. Kept the existing `MandatoryEdgeTerminalOrderUnresolved` rejection and downstream arc behavior unchanged.
- Added regression `MandatoryEdgeTerminalInventory.OrdersCutsExactlyAndClassesEqualParameters` (gate row 950). It compiles in this turn but **was not executed**. The TB125 manifest remains frozen at 950 cases, membership 1,031 (SHA-256 `9a112bd18c4f37248ae8c9fc2c942f9fd19cd67ca4a5236c13f5ed76f95a0290`).
- Exact source snapshot: workflow 43990375028, event SHA `fb3bb9d0b022b93284de41d88007191586ef5ff4`, artifact `14288155639` (ZIP SHA-256 `7d1acbfc84c148412900d2b75657658c640732958cf5c7551edd45341ac3c9a3`). Source archive and all 5,570 file hashes verified.
- Preserved transport patch (SHA-256 `717fedde2a88c158e7b59137cbaf4113fb16eb0cb5eff217f1f326ee7ef882e6`) in ChatGPT Library `/Directional/Work-Preservation/`. Application [workflow 43990925311](https://github.com/akashskypatel/Directional/actions/runs/43990925311) succeeded. The temporary Drive file was deleted by the owner-authorized connector.

## Compile evidence

- Compile-only [workflow 43991193705](https://github.com/akashskypatel/Directional/actions/runs/43991193705), job `133732063461`: **SUCCESS**, exact pinned source `6857c66b788841f8e400151b6068b2f23be25167`.
- Immutable package artifact `14287742226`, outer ZIP SHA-256 `c35f4dd6c61441794999a55b0068fb41b3ab298d1b473c8ab60048d9b20bdab9`. Internal 28/28 checksums verified.
- All eight approved targets compiled and linked: `directional_core`, `directional_pipeline`, `directional_surface_cell_authority_kernel_tests`, `directional_surface_cell_producer_tests`, `directional_surface_cell_completion_tests`, `directional_surface_cell_validation_tests`, `directional_compiled_api_tests`, `directional_benchmarks`.
- Build was GMP/GMPXX exact arithmetic with `DIRECTIONAL_ENABLE_GMP=ON`. The workflow states `turnBoundary=Code+Build-only`, `runtimeExecution=false`. **No Directional test, benchmark, or production census ran** in CB143.

## Issues and next turn

- Initial Drive-apply workflow `43990835170` failed to push when a later dispatcher request advanced the branch (non-fast-forward). The second run applied the same verified patch successfully. No source behavior changed between attempts.
- Process deviation: initial repository document reads preceded the mandatory source snapshot. The correct frozen snapshot was obtained and used before any code edit. Do not repeat this read-mode error.
- C3 remains open; exact duplicate terminals and the count of offending mandatory edges are not yet measured. The rejection stays fail-closed. O42/O43 open; O44/C1 closed; D11=A/D12=A, D10 deferred/D6 pending; stable 66/17/49, debt 1, deferred 81; accepted CP2 491/491; CP3/selector497 unpromoted; `chainRimSchedules=false`.
- **Exactly next, in a separate turn:** `M6-CP3-TB125-P13-EDGE-TERMINAL-EXACT-INVENTORY-EXEC`. Run TB125 only from the immutable CB143 package, with RA-243 §4's 950-row gate and three-case census, then independent equivalence Review. Do not start TB125 in CB143.
