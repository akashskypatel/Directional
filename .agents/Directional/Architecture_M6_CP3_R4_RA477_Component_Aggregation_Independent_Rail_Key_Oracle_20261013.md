# R4 RA-47.7 — component aggregation vs independent typed rail producer keys (2026-10-13 UTC)

**Same canonical `M6-CP3-CB1-ENTRY-R4` Code + Build turn.** Authored from the exact verified snapshot `08de7bd1cc34c4877f566432f746969463c63a4e` (workflow `38375413926`, artifact `11801220866`, source manifest 5,640/5,640). No runtime or test execution is authorized in this turn.

## Scoped test-source change

New separate test `SurfaceCellAuthorityContractCutover.DecomposedRailSourceKeysEqualIndependentComponentProducerKeys` in `tests/SurfaceCellsPhase10Tests.cpp` uses the existing two-square disconnected fixture and accepted aggregation pipeline. It compares **actual producer-published** typed `sourceEdges` multisets from the two-component aggregate to independently invoked single-component production runs on the **identical sliced input vertex positions and face rows**, mapping only the independently produced vertex IDs into the original source vertex domain. It checks source-vertex interval agreement, nonempty publication per component, no cross-component rails, and that a second-component produced rail key has differing lexical-key/mesh-EV ordinals. Rails are not synthesized or rebuilt in the aggregate path; test identity is new and the frozen 497 selector is unchanged.

## Evidence boundary and risk

This is a **test oracle hypothesis**, not a runtime witness. A later authorized artifact-only Test + Benchmark must confirm that both isolated productions succeed and that global typed-key multisets agree; if the fixture fails at an upstream producer, that is a **failed oracle**, not a justified alternate PASS. No production code, workflow permissions, GMP policy, or accepted normative definitions changed. No CP2/R3 acceptance counts, stable regression ledger, RA-47.12 liveness credit, RA-43/46 completion, or odd-τ/multi-carrier recovery is claimed.

Apply only via exact-base Google Drive patch transport, then verify the mandatory eight-target GMP/GMPXX **compile-only** workflow on the applied semantic SHA. Record the hashes/commit after verification; no test execution, TB497 or successor may be started.

## Applied and compiled (2026-10-13 UTC)

Recovered the prior OpenAI connector safety-check transport blocker: the retained staged file `1GY12FkqEG_-gDf4qnteUDvbQCBDgcOYQ` (patch SHA-256 `41da7542dd92256be6bbe07342dffc602361697a8acb435f94df61010625a6cb`, diff-body SHA-256 `e7f1c77c02eabf07f679c029773e9dd90613356f1a8fed88d7e816828199ae5f`) applied successfully through dispatcher workflow `38383973192`, result artifact `11803909985` SHA-256 `8834e4582492a50e07dba93a6b6fdf6b78cb0806c790bf3dacc09eb2b04ce225`, diagnostic `11804418953` SHA-256 `17f546255c2e6c942fa3533eb7f7a101a63e18e84bec766b89c525b9cd17c701`. Semantic source commit `007585f8eac57a74e89e62a416a844e21c15fe35`; exactly four intended files, 141 additions, no production change. The original Drive stage was permanently deleted using owner-authorized cleanup after successful push.

Mandatory eight-target GMP/GMPXX compile-only workflow `38384224673`, job `115252002875`, finished GREEN against exactly `007585f8eac57a74e89e62a416a844e21c15fe35`. Result artifact `11805220540` ZIP SHA-256 `e564eed3ea3636f1b36262dc91c29e9a65af6c229efc74e58d7935da0c07ddca`; diagnostic artifact `11805540564` SHA-256 `03f5db83d3e48a0de1a14ddade126f1b2d700c8a3c49168fb96a3d12e2a8ed9f`. The downloaded immutable package verified 28/28 manifest hashes, eight prescribed targets, preflight/build exits 0/0, generated GMPXX/GMP linker command, five clean source-status files, `exactArithmeticBackend=GMP`, and `runtimeExecution=false`.

**Scope remains compile-only:** the new independent-component agreement oracle has not been executed, and its producer equality/ordinal expectations are not reported as runtime PASS. The previously blocked transport gate is cleared; canonical R4 remains incomplete with RA-43.1/.4, remaining RA-46.5, RA-47.12 executed liveness, historical 39/34/7/88/six, and genuine odd-τ multi-carrier gates pending. RA-50 discharges RA-43.2. Do not start TB497, runtime or successor here.
