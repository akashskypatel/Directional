# CB83 output-validation terminal detail — Code + Build record (2026-11-04)

- **Turn:** `M6-CP3-CB83-P13-OUTPUT-VALIDATION-TERMINAL-DETAIL`; **authority:** RA-201.9 / DESIGN Amendment 33.
- **Patch:** frozen `Architecture_M6_CP3_CB83_P13_Output_Validation_Terminal_Detail.diff`, SHA-256 `3741697ed34d219579a97081db3763126292a3d103a445e2ceda6cbbf37df682`; only `src/pipeline/RemeshPipeline.cpp` (`+4/-1`).
- **Semantic source:** `2278b8b649b4262fb70a522371ed282655383af5`; [commit](https://github.com/akashskypatel/Directional/commit/2278b8b649b4262fb70a522371ed282655383af5).
- **Compile:** [run 41759757801](https://github.com/akashskypatel/Directional/actions/runs/41759757801); eight required Linux Release/static targets, exact arithmetic GMP/GMPXX; `28/28` artifact checksums; `runtimeExecution=false`.
- **Immutable package:** GitHub artifact `13289188434`; ZIP SHA-256 `c4ca145a987cffef1035c95e0febedbc8b8b387c72678ec41bc59139230288b9`.
- **Behavior:** on completed-mesh source-authoritative validation rejection, forward the recorded `surfaceCellFirstInvalidProducerReason` into terminal details. Validator and admission semantics unchanged.
- **Runtime evidence:** none created in CB83. No tests, benchmarks, or generated binaries executed; compile success does not certify runtime behavior.
- **Next separate turn:** `M6-CP3-TB76-P13-OPTIMIZER-SOURCE-QUERY-FULL-GATE-EXEC`, artifact-only immutable gate 893/893 (manifest SHA-256 `3b72716137800726f9ce46a7ea6aee1f8a7db0122be29df97c359ea098545bf8`; membership 974), plus Cylinder/BunnyRandom/Vase census. P13-e/P13-l separate Review tracks.
- **Unchanged acceptance:** CP2 491/491; stable 66/17/49, debt 1; selector497/CP3 unpromoted.
