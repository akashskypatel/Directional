# CB23 — Torus A5 seam-face rejection-site Code + Build (2026-10-21)

- **Turn:** `M6-CP3-CB23-RP01-TORUS-A5-SEAM-FACE-SITE`; authority RA-121.5.
- **Semantic source:** `e859175333f879273a75e3bfc321600e451048aa` (prior base `c6e90916eb90bfd33bc8a38c5ece7def15dcc766`).
- **Diff:** `src/pipeline/RemeshPipeline.cpp` only, +68/−0 in `relation-collinear-seam` rejection block (RP:5343–5410).
- **Witnesses:** appended `;sel=`, `;support=`, `;wedge=`, `;spanOnlyN=` in specified order, before isolation-site return; old site fields preserved.
- **Semantics:** rejection-only; no admission, return, error code, fixture, test, selector, or other source path changed.
- **Compile:** [run 39623185718](https://github.com/akashskypatel/Directional/actions/runs/39623185718), attempt 1, completed successfully; compile job GREEN, test/benchmark job SKIPPED.
- **Result artifact:** `12355892070` (`m6-cp3-cb23-a5-seam-face-result-39623185718`); expires `2026-10-28T15:12:05Z`.
- **ZIP SHA-256:** `5215e5c216cde5cd45d851d36c9aa9b2a62de496aa78db2aac54d828996af91f` (provider and locally recomputed).
- **Root manifest:** 28/28 packaged file hashes verified; all expected target outputs present.
- **Source archive:** `source-e859175333f879273a75e3bfc321600e451048aa.tar.gz`, SHA-256 `b570e9815e8f6b438f3356970f79b80557f4e07941e5501517eb941644222281`; metadata source SHA agrees.
- **Build boundary:** 8/8 requested targets; preflight/build exit codes `0/0`; `DIRECTIONAL_ENABLE_GMP=ON`, `exactArithmeticBackend=GMP`, generated link records both `gmpxx` and `gmp`.
- **Clean source:** all five packaged source-status records empty.
- **Execution:** `runtimeExecution=false`; no tests or benchmark binaries executed; no runtime validation or acceptance promotion claimed.
- **Next:** `M6-CP3-CB23-RP01-TORUS-A5-SEAM-FACE-SITE-REV` independently verifies diff/package and issues the bounded TB24 plan. Stable 66/17/49, debt 1, CP2 491/491; R3 403/497 and TB21 449/497 remain non-promoted.
