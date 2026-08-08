# Future Chat Session Handoff — Directional Surface Cells

## Resume here

Repository: `akashskypatel/Directional`  
Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`  
Draft PR: #8 — keep **open, draft, unmerged**  
Review policy: `never`  
Active gate: **G4 topology-distinct completion and singularities**  
Next turn: **Code + Build — G4 closed-genus-one periodic authority**  
Authoritative next plan: `.agents/Directional/Gate_4_Closed_Genus_One_Holonomy_Basis_Code_Build_Plan.md`

Read this handoff first, then `TODO`, `MILESTONE_G_TODO.md`, `.agents/Directional/DESIGN.md`, the latest G3 Test + Benchmark report, the G4 Code + Build plan, `tests/TESTING_STRATEGY.md`, `.agents/Directional/GitHub_Workflow_Policy.md`, and the relevant turn-based-coding-agent Code+Build/testing-integrity/recovery/handoff/GitHub-workflow references.

## Current tested authority

G0, G1, G2, and **G3 are passed**.

G3 formal closure is artifact `9013161456` (`g3-field-correspondence-test-witness-code-build`), source/test evidence `117620ec2da2083ce11b205835e58fa404f163ef`, runtime-proven production source `0279946920dfca6e9ac44b7ea31b38e929d1f5fc`, artifact SHA-256 `fbbdac0d85f8e9bd90dd44267c3f71d0932627e25014910077ad1fe659782c62`.

Local evidence archive: `directional-g3-field-correspondence-witness-tb-evidence.tar.gz`, SHA-256 `cf32b8d49626e41922b0214d437e3c0a8a96cdbf90848aae3bb0428644c0baf8`.

- corrected field-correspondence witness passes;
- focused/retained G0-G3 contracts **17/17**;
- plane direct hash `730caeae49ec872c`, 3/3;
- seam direct hash `5bdf34d7802e9fb0`, 3/3;
- close sheets direct hash `89b052762f52a5af`, 3/3;
- cylinder direct `Produced / CompletedSurfaceCells`, `r=0`, `t=(32,0)`, route 32, cut 4, 1,728 traces, 290 arrangement/simplified cells, 288 pure quads / 320 vertices, zero validation failures, field P95 `8.537736463e-7°`, exactly two genuine annulus exterior loops, output hash `32135be51d7a0a26`, deterministic 3/3, no fallback/recovery;
- bounded producer 100/101 (only known timing-only validator-overhead test), completion 154/164 historical failures, validation 60/60, API 8/8.

Latest detailed runtime record: `.agents/Directional/Gate_3_Field_Correspondence_Test_Witness_Artifact_Only_Test_Benchmark_Report.md`.

## Active G4 evidence

Exact torus observation from the same artifact:

- source topology: connected closed genus one, 72 V / 144 triangles / Euler characteristic 0 / no boundary;
- producer `Rejected` at `tracing/phase-front`;
- reason `InvalidPeriodicTopology`;
- zero traces/arrangement/completion/output;
- no fallback/recovery;
- partial diagnostics already retain one periodic relation `r=0`, `t=(24,0)`, route 24, cut 2.

Exact source diagnosis:

- `SurfacePhaseFrontResult` owns only one scalar `SurfacePeriodicHolonomy periodicHolonomy`;
- in `build_uniform_phase_front()`, aggregation rejects a second enabled local periodic relation merely because `result.periodicHolonomy.enabled` is already true;
- phase-front structural hashing, diagnostics, and `materialize_phase_front_mesh()` also consume only one relation.

This singular representation/consumption boundary is the earliest active G4 contract. Do **not** bypass the rejection or choose a relation by ID/order/count/frequency/proximity.

The prescribed sphere is later G4 evidence: it reaches 766 traces / 30 arrangement cells but fails completion at `repeated-boundary-node` plus parity-alternative budget exhaustion. Do not preempt the torus slice with historical completion repair.

## Exact next-turn design declaration

Before any source edit emit:

```text
Active design gate: G4 topology-distinct completion and singularities
Earliest failing fixture/contract: torus__surface_cells rejects at tracing/phase-front with InvalidPeriodicTopology after one authoritative periodic relation is already present
Missing design contract: the result-level phase-front authority can represent and consume only one SurfacePeriodicHolonomy, so a second compatible periodic sheet/topology relation is rejected before tracing even though closed genus-one topology requires retaining multiple nontrivial periodic relations
Smallest general implementation change: replace the singular result-level periodicHolonomy assumption with a deterministic source-topology/reciprocal-transport-derived collection of periodic relations, canonicalize and validate the collection without discovery-order ownership, and make hashing/diagnostics/materialization consume every retained compatible relation while preserving the one-relation annulus contract
Observable material-progress condition: the exact torus no longer rejects solely because a second authoritative periodic relation exists and advances under truthful multi-relation periodic authority, while all G0-G3 focused contracts and plane/seam/close-sheets/cylinder behavior remain unchanged regressions
Explicitly deferred work: prescribed-sphere singularity completion after the torus topology slice, G5 adaptive scale/hard-feature expansion beyond what is required to preserve current source barriers, G6 bunny/vase production, scheduler timing, historical completion/simplification failures unrelated to the active torus contract, validator changes, and unrelated optimization
```

## Next-turn execution

Implement the smallest general multi-relation periodic authority described by `.agents/Directional/Gate_4_Closed_Genus_One_Holonomy_Basis_Code_Build_Plan.md`.

Required properties:

- one first-class canonical relation collection; no competing mutable scalar authority;
- retain component/sheet, Z4 rotation, integral translation, ordered source route, cut route per relation;
- canonicalize equivalent/reversed descriptions from source topology/transport;
- fail closed on conflicting or genuinely ambiguous/dependent authority;
- make every retained relation live in hashing, diagnostics, provenance and exact quotient materialization;
- preserve G2 sheet isolation and exact G3 single-annulus behavior;
- no Euclidean seam welding or positional sheet merge;
- add compile-only semantic regressions including exact torus producer-boundary coverage and G0-G3 retention.

Compile the seven approved targets Release/static/Ninja with compile-only-safe discovery. **Execute no generated Directional binary/test/benchmark/CLI/GUI/help/list/discovery command.** Package exact source/blobs/patch/logs/five executables/two libraries/27 fixtures/checksums and `runtimeExecution=false`.

The following artifact-only Test + Benchmark turn must first retain all 17 G3 focused contracts and direct plane/seam/close-sheets/cylinder. Then exact torus must no longer reject merely because a second compatible periodic relation exists. A deeper truthful torus failure is acceptable as first-slice material progress only when the new multi-relation authority is demonstrably live and consumed; direct strict-valid torus output is preferred.

## Lessons that must not be repeated

- A test expectation is not automatically production authority; verify that the fixture naturally creates the claimed witness. The G3 field witness originally failed only because 0.25 target subdivision made a whole 0.5 source inter-ring edge impossible as one front edge.
- Raw DCEL/source numeric IDs are not stable semantic identities. Compare canonical source endpoint/route authority.
- A source-topologically valid periodic candidate is not field-authoritative merely because it is first/lexicographically minimal.
- Endpoint ownership tolerance may not emit tolerance-expanded geometry; canonicalize to exact source-simplex geometry.
- GitHub build workflows must use this repository's `DIRECTIONAL_BUILD_TESTS` / `DIRECTIONAL_BUILD_BENCHMARKS` options and enough fetch depth to verify/package the exact source parent.
- Packaged tests may retain Actions absolute fixture paths. Artifact-only validation may expose immutable packaged fixtures through a recorded runtime-only symlink; never rebuild or patch packaged source to solve that path issue.
- Timeout is failure only; do not infer a disposition from an incomplete vase run.

## Turn boundary

Authoritative cadence:

`Code + Build -> Test + Benchmark -> [Optional Review] -> Code + Build`.

Never combine turn types.

- Code + Build may edit/configure/compile/link approved targets, but may not execute generated project binaries/tests/benchmarks/ctest/CLI/GUI/help/list/discovery.
- Test + Benchmark executes the exact built artifact and may not edit production/test/fixture/validator/benchmark/build source or configure/compile/relink a replacement.
- Review is optional. Review policy is currently `never`, so the Test + Benchmark plan becomes authoritative.
- Build and runtime claims require exact pushed/evidence commit and artifact authority.
- Direct mandatory fixture/gate evidence outranks aggregate totals.
- Two consecutive Code + Build turns without material progress require mandatory design review or bounded producer-replacement proof. Current counter is 0 because G3 closure is material progress.

## Workflow/temp cleanup — mandatory

1. inspect `.github/workflows`, `.agents/connector-triggers`, and `.agents/Directional/turn-payloads` at start and end;
2. remove stale bounded workflows;
3. during remote compile retain the durable workflow plus at most one bounded workflow/payload;
4. after artifact/log/source/blobs/build authority is verified remove the bounded workflow, trigger, and payload;
5. final workflow state must contain only approved durable workflow state and no stale artifact/trigger debris;
6. do not remove a durable dependency required by normal repository operation;
7. retain payload/source-transfer data until source/blobs/build authority is verified, then remove it.

## Documentation cleanup — mandatory

1. remove stale/superseded plans, reports, and generated result documents at end of turn;
2. retain the live handoff, latest reports needed for current authority, next executable plan, current runtime summary, and durable design/remediation/workflow docs;
3. retained documentation may reference only files that exist;
4. Git history and PR conversation are the archive for superseded turn detail;
5. never delete the latest evidence or next-turn instructions before replacements exist.

## Instruction preservation — mandatory

1. never remove, weaken, consolidate away, reinterpret, or silently replace an existing mandatory instruction unless the user explicitly requests it;
2. handoff edits must be additive or narrowly corrective and preserve all procedural, safety, scope, cleanup, validation, repository-write, and turn-boundary requirements;
3. compare the prior handoff and verify every mandatory instruction remains present;
4. if instructions conflict, preserve both and request user direction rather than silently choosing one;
5. documentation cleanup does not grant authority to remove workflow or safety rules.

## End-of-turn repository write — mandatory

Every completed turn ends with a **new top-level PR #8 conversation comment** after all documentation, cleanup, and PR metadata updates. That comment is the **final repository write** for the turn. Do not perform any GitHub write after it.

## Prohibitions — mandatory

- no validator weakening;
- no count/order/frequency ownership selection;
- no arbitrary subset search;
- no fallback/recovery substitution;
- no synthetic counters/Euler correction;
- no positional merging across unrelated sheets;
- no Euclidean periodic seam welding;
- no fixture/ID special cases;
- no post-hoc cycle decomposition/cell merging;
- no timeout-as-correctness.
