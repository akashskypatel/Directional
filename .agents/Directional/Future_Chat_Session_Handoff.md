# Directional Surface-Cell Quadrangulation — Session Handoff

**Updated:** 2026-08-04  
**Repository:** `akashskypatel/Directional`  
**Base:** `surface_cell_quad`  
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Current checkpoint

P5-CB135 through P5-CB142 code changes and the exact compile-only package gate are complete. P5 remains open because runtime acceptance has not been executed for this source.

Compiled checkpoint:

- prior tested source `247061bbaa835e5e5bf9298cc5e2c4dd25d5c74f`;
- workflow event commit `b7f8a9978764b77931ba6d299fdcbc65639235de`;
- implementation/exact compiled source `aa2917e280fabd2272911a39cd0ecc327cce1cf3`;
- reviewed patch SHA-256 `890dd621cf549f32c55d44f52b85050bfdfa5ce15df5f2bda2f8ba3e33c8ed70`;
- successful run `30912858764`, job `92003602916`;
- artifact `8894034755`, `surface-cell-p5-cb142-github-source-linux-release`;
- artifact SHA-256 `ff77004f8893b9f993165ba685794faca52f5611c9f1c47deb3f1dd5d930cb55`;
- workflow-log artifact `8894035556`, SHA-256 `b7b84ba230c873702ec548318a5cad6b43fe4e1ccaf5d437bcd535201020ab1b`;
- empty source status;
- internal checksums **40/40**;
- package files **42**;
- fixtures **26**;
- recursive submodules **9**;
- all **131/131** Ninja actions complete.

The build compiled exactly `directional_core`, `directional_pipeline`, `directional_phase1_tests`, and `directional_benchmarks`. No project binary, test, benchmark, custom mesh, help/list, or discovery command executed.

The next turn is **P5-TB22 artifact-only test and benchmark**. Execute artifact `8894034755` directly. Do not configure, rebuild, relink, patch, regenerate, or modify source.

## Read first

1. `TODO`
2. `MILESTONE_G_TODO.md`
3. `.agents/Directional/Milestone_G_P5_CB135_CB142_Code_Build_Report.md`
4. `.agents/Directional/Milestone_G_P5_CB142_Test_Benchmark_Plan.md`
5. `.agents/Directional/Milestone_G_P5_TB21_Artifact_Only_Test_Benchmark_Report.md`
6. `benchmark-results/p5-tb21-summary.json`
7. `.agents/Directional/Milestone_G_P5_Post_TB21_Production_Termination_Code_Build_Plan.md`
8. `.agents/Directional/GitHub_Workflow_Policy.md`

## Implemented in P5-CB135–P5-CB142

### Bounded alternative execution

Parity repair now has a finite canonical frontier derived from interfaces incident to the typed failing cell. Every state is canonically hashed and visited at most once. Results are memoized, and diagnostics expose candidate budget, attempts, visited states, selected interface, sequence/state hashes, and typed disposition.

Terminal dispositions distinguish committed, no-candidate, cycle-detected, budget-exhausted, and all-invalid outcomes. The earliest typed domain failure and exact rollback remain authoritative.

This is a topology-derived bound, not a wall-clock timeout or arbitrary subset search.

### Repeated-node and cylinder producers

The repeated-node retry frontier uses all canonical incident interfaces rather than an arbitrary small prefix. Arrangement cycle decomposition evaluates every repeated occurrence and accepts only deterministic splits where both directed cycles contain at least three edges.

Runtime must still prove a valid sphere/mechanical/face-edge alternative and cylinder disk-cell closure. Compile success is not topology success.

### Completion variants

The existing bounded templates now expose cyclic rotations and reversed orientations. Transition completion has six variants; pattern and bounded-combinatorial completion have `2 * boundaryCount` finite variants. Every candidate must pass typed local embedding validation before authority.

Runtime must establish valid focused, cylinder, thin-tube, and smooth outputs.

### Parallel routes and cache reuse

Semantic overlap and stitch separation are treated independently. Individual stitch-separation repair is considered before coupled refinement. Cache reuse first matches a canonical dependency hash and then requires finite exact-dependency, topology, ownership, lineage, and retarget validation.

Reuse/recompute counters remain operation-derived. Runtime must prove valid annular completion, no duplicate stitched output, and positive real reuse/recompute.

### Global source-chart agreement

Stitching now receives source face/component/sheet authority. Shared output vertices retain all provenance candidates. A global intrinsic resolver intersects exact source support, chooses a canonical common face, and rebinds barycentric coordinates only under proven source-entity equivalence.

No positional merge or source-triangle pairing is used. Runtime must close plane, seam, close-sheets, and disconnected-sheet contracts.

### Pipeline, torus, and memory evidence

Parity alternative diagnostics propagate through patch and pipeline contexts. Incomplete completion diagnostics expose a stable reason name plus explicit numeric reason code. Benchmark telemetry samples working set and categorized ownership at the same sequence and reports availability and reconciliation remainder separately from legacy peak ratios.

Runtime must close GP23/GP24/Phase20 lineage, torus completion, and the 75% same-sample reconciliation gate.

## Last runtime authority: P5-TB21

- Phase 14–18 **236/236**;
- Milestone D **6/7**;
- Milestone E **23/26**;
- GP23 + GP24 **10/14**;
- Phase20 **46/48**;
- full suite did not terminate on bunny aggregates;
- bounded subset **583/597**;
- production **0/8**;
- repeated-node alternatives did not commit;
- reuse/recompute `0/0`;
- plane/seam/close sheets `LocalSheetMismatch`;
- cylinder non-disk and invalid local variant;
- thin tube/smooth invalid local variants;
- torus incomplete;
- face-edge fourth repeat nonterminating;
- smooth above wall limit;
- same-sample memory unavailable.

Do not claim any runtime closure from the CB142 compile result.

## P5-TB22 execution order

1. Verify archive SHA, source commit, empty status, internal **40/40** checksums, 26 fixtures, nine submodules, source contents, and target hashes.
2. Run focused finite alternative-state, memoization, cycle/exhaustion, valid-commit, and rollback contracts.
3. Run generalized repeated-node alternatives.
4. Run cylinder periodic DCEL and permutation contracts.
5. Run typed bounded local completion variants.
6. Run semantic duplicate, annular route, duplicate-output, and exact cache reuse contracts.
7. Run global source-chart reconciliation and disconnected-sheet contracts.
8. Run GP23/GP24/Phase20 stage/fallback lineage.
9. Run torus typed inventory and completion.
10. Run Phase 14–18, D, E, GP23/24, Phase20, and the complete unfiltered suite.
11. Run all eight direct production fixtures with fallback `Fail` and recovery disabled.
12. Run isolated resource-gated face-edge and smooth bunny processes.
13. Evaluate same-sample measurement availability and at least 75% categorized reconciliation.

A process watchdog may protect the environment and record nontermination, but timeout is never correctness evidence and cannot make a test pass.

## Preserved prohibitions

- no validator weakening;
- no frequency/count/order ownership selection;
- no fallback/recovery substitution;
- no synthetic counters;
- no positional merging or source-triangle pairing;
- no arbitrary subset search;
- no fixture/ID special cases;
- no timeout-as-correctness.

## Key lessons

- A finite source-level catalog is not operationally bounded until canonical states are deduplicated and attempted once.
- Typed exhaustion and exact rollback are necessary evidence, but production still requires a valid alternative where one exists.
- More template variants are acceptable only when every candidate remains validator-gated and the catalog is finite and deterministic.
- Semantic overlap, stitch separation, and exact cache dependency are three distinct contracts.
- Shared source-chart validity is a global intersection problem, not a local patch choice.
- Same-sample memory coverage must use one measurement sequence; peak-to-peak ratios are not a substitute.
