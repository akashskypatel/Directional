# CB168D — carrier-contact edge-node binding (Code + Build, 2026-11-19 UTC)

## Situation

**Compile PASS.** The frozen CB168D code edit is committed at source `60357edb20132b20263fc5a1997f8af50343e2ae`. [Compile run 44478377983](https://github.com/akashskypatel/Directional/actions/runs/44478377983) passed. The immutable compile package artifact `14507741391` has SHA-256 `0cafed08563f6699ff4000b7975f880f2de46a1a91266daab539c85439fbe25a`, with all 28/28 manifest hashes verified. Eight mandatory targets compiled with GMP and GMPXX. `runtimeExecution=false`; no tests or benchmarks were executed.

## Background

RA-266 froze [the exact CB168D patch](Architecture_M6_CP3_CB168D_P13_Carrier_Contact_Edge_Node_Binding_Exact.diff) at SHA-256 `cf726ced720530467d4d36552fa19880196473a9e5856c0d0408aacb406de8de`. The verified source snapshot was `7358dea7c4968b8be6ef02685425f5d35115d5a7` from [snapshot run 44477429547](https://github.com/akashskypatel/Directional/actions/runs/44477429547). Comparison with CB168C source `e0f085eb65ed186bf836305f2896c69c6c90c519` established zero `src`, `include`, or `tests` changes before applying the patch. The exact change touched only `EmbeddedGraphTopology.cpp` (+89/-9) and `EmbeddedGraphTopology.h` (+14/-0).

## Assessment

The patch makes carrier contact an explicit source-edge node binding, validates the carrier locus, reuses the contact node at a selected cut crossing, excludes carrier contacts from face-only contact nodes, and locates the struck trace cut at the recorded segment. The separate [Drive application run 44478099468](https://github.com/akashskypatel/Directional/actions/runs/44478099468) passed with `runtimeExecution=false`. The complete transport patch SHA-256 is `ab59072fe9b7b6f46a69f5b5e1732c1188678bbaf3ae84107091d043edadfbba`, with exact frozen diff body and base `7358dea7c4968b8be6ef02685425f5d35115d5a7`. Google Drive preservation ID `1_N4pKILvRZusby7psu5P8MhnJTnwghKV` was retained until successful application.

The compiled package names the exact source commit, has empty source-status records, build exit code 0, and records `exactArithmeticBackend=GMP`, `runtimeExecution=false`, and link evidence for `libgmpxx.so` and `libgmp.so`. The eight targets include core, pipeline, authority-kernel, producer, completion, validation, compiled API, and benchmark executables. Compile evidence does not establish runtime correctness. Latest accepted test authority remains TB144 Review: 963/963 prior matching records; known row858 RED, stable 66/17/49, one witness debt, 81 deferred, CP2 491/491. No CP3/D0 acceptance, selector change, or EC3 switch.

## Recommendation

The only next turn is `M6-CP3-CB168E-P13-ENTRY-COINCIDENCE-ARRIVAL-RECEIPT` (Code + Build, compile only), using the frozen exact diff SHA-256 `674184224a4a96dadaefce0be997b75ee03e36414af9062fc87ccd70f5b71dc0`. TB145 is later. Do not run tests, modify CB168E now, or promote product acceptance.
