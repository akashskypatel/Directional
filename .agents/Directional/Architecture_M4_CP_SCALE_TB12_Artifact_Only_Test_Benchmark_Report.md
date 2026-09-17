# M4-CP-SCALE-TB12-EXEC — Artifact-Only Test + Benchmark Report

**Turn:** `M4-CP-SCALE-TB12-EXEC`
**Date:** 2026-09-17 UTC
**Disposition:** **COMPLETE / ORCHESTRATION FAILURE / NO SEMANTIC LEDGER**
**Candidate package:** `10503330993`
**Candidate semantic source:** `d65ea2071990a443750ca7d84a43b63630fbdad4`
**Accepted runtime authority remains:** package `10473134357` / source `e15e83c79a1e1962c0ed8d31ea85187ab6600e47` / selector426 **426/426**

## 1. Artifact-only boundary

TB12 consumed the immutable CB13 result archive directly. No repository checkout was configured or built, no package/source/test/fixture byte was repaired, no executable bit was changed, and no generated Directional binary was executed. Ordinary `unzip` and `tar` extraction preserved archived modes. No benchmark, test discovery/listing, CTest, CLI, help/version command, fuzzer, or custom input ran.

The preflight stopped before semantic execution because the required S5 fixture pair is absent from both the immutable package source archive and current repository authority. Per `Turn_Cadence.md`, this is an orchestration/source-retention failure rather than a semantic RED and therefore produces no semantic runtime ledger.

## 2. Package authority verified before the stop

- CB13 compile run/job: `35234488577 / 105246855648`.
- Result artifact: `10503330993`; provider SHA-256 `5e3542c1be833043a86191491c6e3387287b7d698f3e48fe42fe282ffa08f197`.
- The downloaded archive hashes to the same `5e3542c1be833043a86191491c6e3387287b7d698f3e48fe42fe282ffa08f197`.
- Recursive package manifest: **28/28 PASS**.
- `metadata/source-commit.txt`: `d65ea2071990a443750ca7d84a43b63630fbdad4`.
- Packaged source archive SHA-256: `4b05fdfd048575b254f670ed82af6b5908acdb3278118e7a7647139d98044df6`.
- `metadata/command-boundary.txt` records `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `exactArithmeticBackend=GMP`, and `semanticContracts=compiled-not-executed`.
- GMP evidence contains both `/usr/lib/x86_64-linux-gnu/libgmpxx.so` and `/usr/lib/x86_64-linux-gnu/libgmp.so` on an authoritative generated test link command.
- Packaged producer executable SHA-256 `c4abba23c75b1d805d94fa6ac736ad8d264792a7c81c194b6b9ee28241019f7f`, archived/extracted mode `0755`.
- Selector426 re-hashes to `41f4d559211375c11c8d1f8c9ccde2581db75819d9409366e8f2695b008b5114`, exactly **426 unique LF rows**, with first425 prefix `e0e0f394faae536ac257ec5409653a34755a8afe0ca437562eb44c9895790e0b`. The S5 focus remains outside selector426.
- `M4CPScaleS5.GenusTwoProducedWitnessReachesA3WithVerifiedTopology` is compiled exactly once in `tests/FieldAlignedCurveNetworkTests.cpp` and directly requests `milestone-g/genus_two.obj` plus `milestone-g/genus_two.rawfield`.

## 3. Failed mandatory fixture preflight

The handoff required TB12 to verify the exact S5 fixture bytes before executing any focused process. That check fails deterministically:

| Authority | `genus_two.obj` | `genus_two.rawfield` |
|---|---:|---:|
| immutable package semantic source `d65ea207...` | **ABSENT** | **ABSENT** |
| exact start-of-turn source snapshot `672ef174713a95ec3d0973832b05e54eb528dfdb` | **ABSENT** | **ABSENT** |

The current `benchmarks/fixtures/generate_milestone_g_fixtures.py` emits the existing plane/cylinder/torus/thin-tube/close-sheets/sphere/seam/mechanical set but does not emit a genus-two pair. The milestone-G directory likewise contains no retained genus-two bytes.

GitHub comparison of the CB13 baseline `8e73d23074e925e2d69e6f2154266a8b26e1bd3d` to the authored test commit `5da96cfa340e44fba6279b1bd2853d16d6d7f90e` shows the only semantic source change is `tests/FieldAlignedCurveNetworkTests.cpp`; the other two changed paths are temporary CB13 control files. No fixture path was committed. Therefore the later CB13 closeout statement that a retained `genus_two.obj/.rawfield` pair already existed was factually incorrect.

The previously recorded `V/E/F = 120/366/244`, `chi=-2`, genus `2` census was local construction/analysis evidence only; without retained fixture bytes it is not reproducible repository fixture authority and cannot satisfy the frozen S5 precondition.

## 4. Stop classification

`M4-CP-SCALE-TB12-EXEC-CAND-01` — **OPEN / MISSING REQUIRED RETAINED S5 FIXTURE / ORCHESTRATION / NON-STABLE**.

This is not a product-semantic RED. The immutable artifact cannot construct the required execution view without inventing or repairing source fixture bytes, which artifact-only TB explicitly forbids. TB12 therefore stopped before invoking the S5 focused test or any selector426 identity:

- focused processes: **0**;
- selector426 processes: **0/426**;
- generated Directional runtime processes: **0**;
- benchmark processes: **0**;
- semantic runtime ledger: **none**.

Accepted runtime authority therefore remains package `10473134357` / selector426 **426/426**. Stable accounting remains **49 events / 14 categories / 35 recurrences**, produced-witness debt **5**.

## 5. Root cause and bounded correction

The root cause is a fixture-retention/source-authority omission in CB13: the focused test was authored and compiled against paths that were never committed or packaged. Compilation could not detect this because fixture loading occurs only at runtime. The package itself faithfully contains its exact semantic source; the defect is not package corruption.

Per the orchestration-failure edge in `Turn_Cadence.md`, the exact next turn is **`M4-CP-SCALE-CB14`**, not Review. CB14 is a bounded Code + Build correction that must:

1. extend the deterministic milestone-G fixture generator to create the intended connected closed orientable genus-two triangular source and matching raw field;
2. commit `benchmarks/fixtures/milestone-g/genus_two.obj` and `genus_two.rawfield` plus required manifest/provenance/checksum updates;
3. independently derive the fixture topology from committed bytes, including the frozen `V/E/F=120/366/244`, one component, zero boundary loops, orientability, `chi=-2`, genus `2`, or stop rather than changing the frozen test expectations by convenience;
4. preserve production `src/**`/`include/**`, the S5 focused test semantics, CMake ownership, selector426 and all accepted predecessor bytes unchanged;
5. compile/package the standard eight targets with mandatory GMP/GMPXX and `runtimeExecution=false`;
6. verify the new package source archive contains the exact committed S5 fixture bytes and modes.

After CB14, a fresh artifact-only `M4-CP-SCALE-TB12-R1-EXEC` may re-attempt the original S5 focus plus selector426 gate. A semantic focused RED at that point routes to Review; this orchestration-invalid TB12 attempt does not.
