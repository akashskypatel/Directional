# R4 RA-47.7 — component aggregation vs independent typed rail producer keys (2026-10-13 UTC)

**Same canonical `M6-CP3-CB1-ENTRY-R4` Code + Build turn.** Authored from the exact verified snapshot `08de7bd1cc34c4877f566432f746969463c63a4e` (workflow `38375413926`, artifact `11801220866`, source manifest 5,640/5,640). No runtime or test execution is authorized in this turn.

## Scoped test-source change

New separate test `SurfaceCellAuthorityContractCutover.DecomposedRailSourceKeysEqualIndependentComponentProducerKeys` in `tests/SurfaceCellsPhase10Tests.cpp` uses the existing two-square disconnected fixture and accepted aggregation pipeline. It compares **actual producer-published** typed `sourceEdges` multisets from the two-component aggregate to independently invoked single-component production runs on the **identical sliced input vertex positions and face rows**, mapping only the independently produced vertex IDs into the original source vertex domain. It checks source-vertex interval agreement, nonempty publication per component, no cross-component rails, and that a second-component produced rail key has differing lexical-key/mesh-EV ordinals. Rails are not synthesized or rebuilt in the aggregate path; test identity is new and the frozen 497 selector is unchanged.

## Evidence boundary and risk

This is a **test oracle hypothesis**, not a runtime witness. A later authorized artifact-only Test + Benchmark must confirm that both isolated productions succeed and that global typed-key multisets agree; if the fixture fails at an upstream producer, that is a **failed oracle**, not a justified alternate PASS. No production code, workflow permissions, GMP policy, or accepted normative definitions changed. No CP2/R3 acceptance counts, stable regression ledger, RA-47.12 liveness credit, RA-43/46 completion, or odd-τ/multi-carrier recovery is claimed.

Apply only via exact-base Google Drive patch transport, then verify the mandatory eight-target GMP/GMPXX **compile-only** workflow on the applied semantic SHA. Record the hashes/commit after verification; no test execution, TB497 or successor may be started.
