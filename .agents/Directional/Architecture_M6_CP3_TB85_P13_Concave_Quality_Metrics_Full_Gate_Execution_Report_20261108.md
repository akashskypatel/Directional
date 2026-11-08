# TB85 — concave-quality evaluator immutable gate and production census (2026-11-08 UTC)

**Turn:** `M6-CP3-TB85-P13-CONCAVE-QUALITY-METRICS-FULL-GATE-EXEC`; separate artifact-only Test + Benchmark under [RA-212 §7](Architecture_M6_CP3_DEFN_P13_Side_Subdivision_Quality_Review_Legacy_Fallback_Density_20261108.md). **COMPLETE / MATCH** in the scope specified by RA-212; not CP3/selector promotion or successful BunnyRandom/Vase direct production.

## Immutable authority and verification

- Exact CB101 source `23e35798abf0eb3584509c564166ccd97c41cc21`; [GMP/GMPXX compile 42443381491](https://github.com/akashskypatel/Directional/actions/runs/42443381491); immutable binary artifact `13602662424`, ZIP SHA-256 `61a0460f8c60d2429c7b7a62d73dd7110ed7c68c919a939a6741cf5377cdf1b1`, internal **28/28** checksums; source TAR SHA-256 `be9e15543f8a4a6bb837f3e1f2a03649222ea6c268d3e7733d7eb52ed9c4e371`; original compile `runtimeExecution=false`.
- Executor snapshot event SHA `6a44b3575e3c32c9a188296b7f92173683be0d81`, [snapshot run 42444504892](https://github.com/akashskypatel/Directional/actions/runs/42444504892), artifact `13602737725`, ZIP SHA-256 `29821aa873b55a43b30c55f32f97b07a5500305011364f78e1c287a65ca355d9`; **6,231/6,231** internal source-file hashes and nested TAR checksum passed. Temporary snapshot trigger removed at `b1dc382e2eadd0ee42a3f3611983e365a61a7a52`.
- Existing harness `.agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh`, SHA-256 `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94`. Gate manifest **908** rows SHA-256 `ec088eb1121a5846605a4bb3675657b68477c88513c28795350369c03bb9f999`; deferred ledger v5 SHA-256 `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce` (**81** deferred). Census manifest **3** rows SHA-256 `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793`. Harness self-check passed for both requests.

## Full gate — MATCH

- Dispatch event `d9fa9f62f1dcd81e632b727e28a2c92c5cabc69a`; [run 42444755166](https://github.com/akashskypatel/Directional/actions/runs/42444755166) SUCCESS; result artifact **`13603128508`**, provider ZIP SHA-256 **`472ad7f8d72de49aab3845efac6c98cad0910729c5cf877de64f5ebeb4708867`**.
- Verified **1,824/1,824** internal SHA256SUMS checks. Execution ledger **908/908 PASS**; red/abnormal/missing/skipped/duplicates/control errors all **0**; **membership 989 = 908 gated + 81 deferred**, postflight true, exit 0. Execution-boundary flags `compile=false`, `relink=false`, `configure=false`, `benchmark=false`; no artifact repair.
- All first **906** gate identities, verdicts and selected-case metadata equal TB84, and all four pinned `platform-digest` lines **byte-identical** to TB84: 795 CloseSheets, 796 MultiFaceSeam, 797 Plane, 864 Cylinder.
- New GUARD **907** `SurfaceMeshOptimizerPhase21.ConcaveQuadReportsItsReflexAngleAndInteriorDiagonalWarpage`: PASS. New GUARD **908** `SurfaceMeshOptimizerPhase21.NormalErrorOfAConcaveQuadDoesNotDependOnItsFirstCorner`: PASS.

## Production census — MATCH (two registered expected REDs)

- Dispatch event `14a6999e6bbffeba730e11fe1b6d50fd9a67a140`; [run 42444788841](https://github.com/akashskypatel/Directional/actions/runs/42444788841) SUCCESS; result artifact **`13603685923`**, provider ZIP SHA-256 **`4d4feddb80dae75fb8810d60c7d2c4a2f80d51a52e98b9ce8e6068f25db8ec13`**. Verified **9/9** internal SHA256SUMS; **3/3** selected/executed; **1 PASS / 2 registered RED**, no abnormal/missing/skipped/duplicate/control error; postflight true, exit 0, no configure/compile/relink/benchmark.
- **Cylinder:** PASS; wall 8.58 s; peak RSS 48,596 KiB; `validationIssues=0`.
- **BunnyRandom:** expected RED; wall 0.80 s; peak RSS 24,500 KiB; `InvalidFieldTransportAtlas:field-transport-atlas/SingularityPortClassCountMismatch;sourceVertex=49`, the inherited **P13-e** candidate. No accepted quad output.
- **Vase:** expected RED; wall **205.77 s**, peak RSS **2,080,632 KiB**; `NotProductionReady:completion detail=AggregateCompletionValidationFailure`, `validationIssues=0`, **189,462** trace segments, **26,817** arrangement cells, **67,750 informational** completed quads. Still fails closed, **not** a successful direct output; legacy fallback / density and topology remain the pending Review subject.
- All three entire `platform-digest` lines (Cylinder, BunnyRandom, Vase) are **byte-identical to TB84**. Vase `completion=946b59dbe8279a65/67750`, `validationIssues=0` unchanged. The full raw test logs and timings are not required to match.

## Regression classification and next authorized action

- Both new metric tests pass, no accepted-green identity was lost, no new stable regression observed. Existing BunnyRandom P13-e and Vase P13-n / producer-path failure persist as **pre-existing candidate/non-stable observations**. Stable **66 events / 17 categories / 49 recurrences**, debt **1**, accepted CP2 **491/491**, deferred ledger v5 **81** unchanged. Frozen selector497 and CP3 remain unpromoted.
- **Next separate Review:** `M6-CP3-DEFN-P13-VASE-PRODUCER-PATH` under RA-212 §3 (Claude scratch). Determine why A4 phase-front producers return NotApplicable for Vase, decide front extension vs the legacy fallback, address relief-seeding density/rail mutation if fallback retained, and attribute all failing Vase quality gates. No Review or implementation performed in TB85.
