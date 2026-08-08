# Milestone G Production Readiness TODO

Last updated: 2026-08-08 UTC

## Current gate

G0 truthful authority [passed] → G1 uniform phase-front plane [passed] → G2 cross-chart / close-sheet isolation [passed] → G3 cylinder / periodic holonomy [passed] → **G4 topology-distinct completion and singularities [active]** → G5 adaptivity/features → G6 bunny/vase production success → G7 hardening.

## G3 runtime closure authority

Artifact `9013161456`, source/test evidence `117620ec2da2083ce11b205835e58fa404f163ef`, runtime-proven production source `0279946920dfca6e9ac44b7ea31b38e929d1f5fc`:

- exact artifact SHA-256 `fbbdac0d85f8e9bd90dd44267c3f71d0932627e25014910077ad1fe659782c62`;
- corrected field-correspondence witness passes under target subdivision;
- focused/retained contracts **17/17**;
- plane/seam/close sheets/cylinder direct strict-valid outputs pass;
- cylinder periodic authority `r=0`, `t=(32,0)`, route 32, cut 4;
- cylinder 1,728 traces, 290 arrangement/simplified cells, 288 pure output quads, 320 vertices/provenance;
- cylinder validation failures **0**, field P95 `8.537736463e-7°`;
- two genuine 32-edge exterior annulus loops and no artificial-cut exterior seam;
- cylinder output hash `32135be51d7a0a26`, deterministic 3/3;
- no fallback/recovery.

Bounded producer is **100/101**, with only the known scheduler/environment-sensitive validator-overhead performance test failing. Completion/simplification remains **154/164**, validation **60/60**, compiled API **8/8**. Direct gate authority outranks those aggregates.

G3 is formally closed. This remains the latest runtime-proven authority until the new G4 artifact is executed.

## G4 Code + Build completed — compile authority only

Exact compile artifact **`9014730437`** (`g4-holonomy-basis-code-build`) was produced by workflow run `31233594490`, job `93042009574`.

Source authority:

- primary implementation `aa0f115c19fc8a5afd8487ebb561e2de2b8551ba`;
- final compile-source commit `6e754bdd64482582d39e71184805fbb053c99f86`;
- build payload cleanup `8304ba30b0f85bc69deebbf55922f05846d2d5b2`.

Build evidence:

- seven approved Release/static/Ninja targets compiled/linked **111/111**;
- workflow artifact digest `sha256:14ad61d02fc67d68267745f5efae4943d53420e34c4373366ff04a9a29fe1aec`;
- internal `SHA256SUMS` digest `41064fa85fe4c68d43a44230b0aae9a8f456c961fb774c92dac5aab26a469b8f`;
- packaged checksum verification **46/46**;
- 47 package files, including five executables, two static libraries, and 27 fixtures;
- log artifact `9014730651`;
- artifact metadata and workflow boundary record `runtimeExecution=false`.

The implementation replaces the result-level singular `periodicHolonomy` authority with a canonical collection of periodic relations and makes the collection live in structural hashing, diagnostics, benchmark JSON, and component/sheet-aware periodic materialization. Canonical source-topology route/cut signatures support equivalent/reversed relation normalization. Conflicting authority and unresolved same-sheet basis authority fail closed with typed reasons instead of choosing by order/ID/count/frequency/proximity.

The successful build required one surgical compile correction: add the missing `std::vector<std::uint64_t>` structural-hash overload. No runtime semantics were changed by that compile fix.

Detailed record: `.agents/Directional/Gate_4_Closed_Genus_One_Holonomy_Basis_Code_Build_Report.md`.

## Active G4 runtime blocker — exact torus

The old G3 artifact's exact torus observation remains the baseline:

- connected closed genus one, 72 V / 144 triangles / 216 edges / Euler characteristic 0 / no boundary;
- producer `Rejected`;
- first invalid `tracing/phase-front / InvalidPeriodicTopology`;
- zero traces/arrangement/completion/output;
- no fallback/recovery;
- one partial relation `r=0`, `t=(24,0)`, route 24, cut 2 before the scalar representation rejected another local relation.

Artifact `9014730437` must now be tested artifact-only. Material progress requires:

1. canonical relation semantic regressions pass;
2. all 17 G0-G3 focused contracts remain passing;
3. direct plane/seam/close-sheets/cylinder remain strict-valid and deterministic with their G3 hashes;
4. torus no longer rejects solely because a second compatible relation exists;
5. every retained relation is demonstrably live in diagnostics/structural/materialization authority;
6. no fallback/recovery and no prohibited ownership heuristic is used.

Preferred outcome is direct strict-valid torus production. A deeper truthful failure is acceptable only if the multi-relation authority is retained and consumed and the new earliest failing producer contract is precisely identified.

## Later G4 singularity observation

The prescribed sphere remains deferred until the torus topology slice is classified. Previous runtime authority:

- producer `NotApplicable`;
- 766 traces;
- 30 arrangement/simplified cells;
- zero completion;
- `BoundaryParityRepair:InvalidReplacementBoundary:repeated-boundary-node;AlternativeRepairBudgetExhausted;attempted=68;budget=68`;
- no fallback/recovery.

Do not preempt the earlier torus topology contract with historical completion repairs.

## Next turn

Execute `.agents/Directional/Gate_4_Closed_Genus_One_Holonomy_Basis_Artifact_Only_Test_Benchmark_Plan.md` as **Test + Benchmark only** against exact artifact `9014730437`. No source/test/fixture/validator/benchmark/build edit, configure, compile, or relink is permitted.

Review policy remains `never`. Every completed turn ends with a new top-level PR #8 comment after all other repository writes.
