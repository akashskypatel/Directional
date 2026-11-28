# CB-189 — exact corner visit reader (Code + Build)

## Situation

The exact reviewed corner reader is committed to the working branch. All eight authorized targets compiled. No test or benchmark binary ran.

## Background

- Authority: [TB-REV-169 independent review](Architecture_M6_CP3_TB_REV_169_Region_Visit_Reader_Independent_Review_20261123.md) and [adversarial continuation](Architecture_M6_CP3_TB_REV_169_Adversarial_Review_20261123.md), W1–W6 and contracts C1–C4.
- Frozen patch: `Architecture_M6_CP3_CB189_P13_Corner_Visit_Reader_Exact.diff`, 19,255 bytes, SHA-256 `6e391678934f776d83b1bbae6652724e080763329d6171c7cdb1c5663259e3b8`; exactly two source files. Local `git apply --check`, file preimage hashes and two postimage hashes match the exact approved manifest.
- Source: [`178f17dd59aa9c61c2e6462e2378e3a42b0ee4f7`](https://github.com/akashskypatel/Directional/commit/178f17dd59aa9c61c2e6462e2378e3a42b0ee4f7). Patch applied by [run 45113750825](https://github.com/akashskypatel/Directional/actions/runs/45113750825) with full patch hash and original base checks. The external patch transport files were retired after successful commit.
- `GlobalTopologyPlan.cpp`: `5af71bc023c494a1a5a8ddeb3bb150c347941faa14e64e1e508b0113a8650aae` → `44395316a518c0cef8cd9afabdc622d69900496c1f6e4a290c37715602fb366f`.
- `GlobalTopologyPlan.h`: `277cde20c20864e5d9e60d668aca5bf00ca37e41eeb9983e93ed8bdaafd38f19` → `87831e100b5f05d2adcbf2a8aea89063d8b63a26939da314eb5896aeeacca16c`.
- [Compile run 45113944225](https://github.com/akashskypatel/Directional/actions/runs/45113944225), package `14790917101`, outer ZIP SHA-256 `0432359393d37cf00b9654339c832263f648733237005171ff3a8eb9cfa1ddfd`. Package manifest verified. `DIRECTIONAL_ENABLE_GMP=ON`, `exactArithmeticBackend=GMP`, and the link command includes GMPXX and GMP. The compile exited 0; `runtimeExecution=false`.
- Eight targets: `directional_core`, `directional_pipeline`, `directional_surface_cell_authority_kernel_tests`, `directional_surface_cell_producer_tests`, `directional_surface_cell_completion_tests`, `directional_surface_cell_validation_tests`, `directional_compiled_api_tests`, and `directional_benchmarks`.

## Assessment

The source change uses the exact face-cut corner partition visits, with six compile-time enum guards. It does not change tests, selectors, the gate manifest, activation, workflows or the production default. The runtime behavior of this change is **not yet tested**. The latest accepted run is TB169: 993/993 PASS, CP2 491/491, membership 1,074. Stable regression counts remain 66 events, 17 categories and 49 recurrences, with one witness debt and 81 deferred identities. CP3/497/D0/H4 and production remain held.

The agent read some repository documents before selecting the required snapshot mode. It stopped that access pattern and then used a verified exact source snapshot. This was a procedure error; no additional source change resulted.

## Recommendation

Start only `M6-CP3-TB-EXEC-170-P13-CORNER-VISIT-READER-FULL-GATE` as a separate artifact-only turn. Use the unchanged TB168 993-row manifest and compiled package `14790917101` from exact source `178f17dd59aa9c61c2e6462e2378e3a42b0ee4f7`. Require 993/993 PASS, CP2 491/491, membership 1,074. Compare every row except 979 with TB169 result `14787082075` under N1–N3, with zero allowance. Row 652 must pass without a throw. Row 979 is a measurement: it is predicted to reach the staged plan or a new typed stage, but this prediction is unverified. A new-code outcome falsifies the prediction and must be reported; any other changed output must STOP for independent Review. No census or rebuild. The next Review turn will freeze one later branch. Do not activate or promote CP3/497/D0/H4.
