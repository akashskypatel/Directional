# R4 RA-43.1 / D2 — paired terminal identities and A1 germ seed (2026-10-14 UTC)

**Canonical boundary:** `M6-CP3-CB1-ENTRY-R4` remains IN_PROGRESS Code + Build, PR #8 draft/open. No TB497, runtime binaries, executed tests, benchmarks, frozen-selector changes, or successor work.

## Exact source / motivation

Previously pinned semantic source `853f2eb6d43bd23c866db3d9ceaaf5367b6b85ee`, immutable result artifact `11872335445` (workflow `38515990739`), matched its 28/28 package checksums and included the exact compiled test source. The opening branch comparison confirmed no subsequent src/include/tests changes. Analysis used its exact bulk source tar, not piecemeal overlapping GitHub source reads.

The existing `SurfaceCellPipelinePhase20.ProducedNonconstantTwoCarrierOddTauSharesA1VertexGerm` assertion authenticated an A4-produced two-edge rail, A1 carrier quarter turn, and directed A1 germ diagnostics, but did **not** independently assert that both endpoint certificates represented both different source carriers (a repeated terminal could have been counted). It also checked the elected owner audit without reattesting the audit's recorded seed against the exact junction, arrival face, branch, and arrival mode passed to `resolve_field_vertex_transit`.

A 12-line test-only correction in `tests/SurfaceCellREPackageTests.cpp` now:
1. collects each `endpoint.terminalCarrier.edge` in a typed `std::set<SourceEdgeTopologyKey>`, requires uniqueness, and requires the final set to equal both producer-published hard edges `(1,4)` and `(4,7)`;
2. requires `decision->vertexStarTransit->seed`, then compares typed `sourceVertex`, `arrivalFace`, `arrivalBranch`, and `FaceInterior` mode against the actual germ-call seed.

Both additions preserve the existing odd-τ, branch transport, paired-route and diagnostic-walk assertions, test identity, and prior RA-49/51 retirement decisions. They do not establish runtime acceptance.

## Patch, exact publish and compile

Complete Git full-index one-path work-preservation patch against base `853f2eb6d43bd23c866db3d9ceaaf5367b6b85ee`:
- SHA-256 `78b288eed8989273a719bd16e052ecb4e3c8f7819206b354a0ad4768509879c1`
- Diff-body SHA-256 `4fee5470153903e56432f33a90d2f698508288475bda5b03ebbaa2ed323d8ddc`
- Verified `git apply --check`, actual pristine application and byte-for-byte result, `git diff --check` and exactly one file/12 additions; backup preserved at ChatGPT Library `/Directional/Evidence/Directional__M6-CP3-CB1-ENTRY-R4__base-853f2eb6d43__terminal-identity-germ-seed.patch`.

An initial direct GitHub contents write `19deee32473ad1a41b61bb5d6f3c46c19a7e0e7b` dropped only a final newline because the Library text rendering omitted it; independently detected by Git blob mismatch and repaired immediately. **Authoritative exact semantic commit:** [9780154](https://github.com/akashskypatel/Directional/commit/9780154878a37b9792179b76c4bc7b39d5b2667c), exact published `tests/SurfaceCellREPackageTests.cpp` blob `6eb202471a421db6aa1ab32ff412cd5a7e82ed3b`, matching the local patch and the compiled source package.

Dispatcher commit [c5cda02](https://github.com/akashskypatel/Directional/commit/c5cda028874dd8cb9f10908e21cd45ebc24eebc6) pinned that exact semantic source and mailbox `m6-cp3-r4-odd-terminal-seed-compile`. **Mandatory eight-target GMP/GMPXX compile GREEN:** [workflow 38518554549](https://github.com/akashskypatel/Directional/actions/runs/38518554549), compile job `115702860045`, result artifact `11872792658`, ZIP SHA-256 `4f62d313bad05bd32b70463beec3275c7d4c4bc447c33fd4565c8c3e83062da5`. Independently verified 28/28 archive hashes, source SHA and exact packaged test-file blob, eight required targets, preflight/build 0/0, `DIRECTIONAL_ENABLE_GMP=ON`, generated GMPXX/GMP link, five clean source-status files, producer-test object compiled, `exactArithmeticBackend=GMP`, `runtimeExecution=false`. The Test + Benchmark job was skipped. **Do not claim runtime PASS or promote the odd-τ witness.**

## Carry-forward

Same canonical R4 continues: genuinely executed multi-carrier/odd-τ witness only in separately authorized artifact-only Test + Benchmark; RA-43.1/.4 producer/consumer work, RA-47.12 uninjected liveness, historical 39 endpoint / 34 Phase10 / seven DCEL / 88 accepted CP2 / six CP3 recoveries, organic D1/D2/D3/D5/A6/A7. No frozen 497 selector edit; historical acceptance ledgers remain unchanged. Existing RA-46.5/46.6 source oracles and RA-49/51 guarded retirements are not duplicated.
