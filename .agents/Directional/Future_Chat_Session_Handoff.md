# Future Chat Session Handoff — Directional Surface Cells

## Resume here

Repository: `akashskypatel/Directional`  
Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`  
Draft PR: #8 — keep **open, draft, unmerged**  
Review policy: `never`  
Active gate: **G4 topology-distinct completion and singularities**  
Next turn: **Test + Benchmark — artifact-only G4 closed-genus-one holonomy-basis validation**  
Authoritative next plan: `.agents/Directional/Gate_4_Closed_Genus_One_Holonomy_Basis_Artifact_Only_Test_Benchmark_Plan.md`

Read this handoff first, then `TODO`, `MILESTONE_G_TODO.md`, `.agents/Directional/DESIGN.md`, the latest G3 runtime report, the G4 Code + Build report, the authoritative G4 artifact-only Test + Benchmark plan, `tests/TESTING_STRATEGY.md`, `.agents/Directional/GitHub_Workflow_Policy.md`, and the relevant turn-based-coding-agent Test+Benchmark/testing-integrity/recovery/handoff/GitHub-workflow references.

## Current tested authority

G0, G1, G2, and **G3 are passed**. G4 is **not runtime passed**.

G3 formal runtime closure remains artifact `9013161456` (`g3-field-correspondence-test-witness-code-build`), source/test evidence `117620ec2da2083ce11b205835e58fa404f163ef`, runtime-proven production source `0279946920dfca6e9ac44b7ea31b38e929d1f5fc`, artifact SHA-256 `fbbdac0d85f8e9bd90dd44267c3f71d0932627e25014910077ad1fe659782c62`.

- corrected field-correspondence witness passes;
- focused/retained G0-G3 contracts **17/17**;
- plane direct hash `730caeae49ec872c`, 3/3;
- seam direct hash `5bdf34d7802e9fb0`, 3/3;
- close sheets direct hash `89b052762f52a5af`, 3/3;
- cylinder direct `Produced / CompletedSurfaceCells`, `r=0`, `t=(32,0)`, route 32, cut 4, 1,728 traces, 290 arrangement/simplified cells, 288 pure quads / 320 vertices, zero validation failures, field P95 `8.537736463e-7°`, exactly two genuine annulus exterior loops, output hash `32135be51d7a0a26`, deterministic 3/3, no fallback/recovery;
- bounded producer 100/101 (only known timing-only validator-overhead test), completion 154/164 historical failures, validation 60/60, API 8/8.

Latest detailed runtime record: `.agents/Directional/Gate_3_Field_Correspondence_Test_Witness_Artifact_Only_Test_Benchmark_Report.md`.

## Completed G4 Code + Build authority

Exact compile artifact: **`9014730437`** (`g4-holonomy-basis-code-build`)  
Workflow run/job: `31233594490` / `93042009574`  
Primary implementation: `aa0f115c19fc8a5afd8487ebb561e2de2b8551ba`  
Final compile-source commit: `6e754bdd64482582d39e71184805fbb053c99f86`  
Build payload cleanup: `8304ba30b0f85bc69deebbf55922f05846d2d5b2`  
Detailed log artifact: `9014730651`

Artifact evidence:

- workflow ZIP digest `sha256:14ad61d02fc67d68267745f5efae4943d53420e34c4373366ff04a9a29fe1aec`;
- internal `SHA256SUMS` digest `41064fa85fe4c68d43a44230b0aae9a8f456c961fb774c92dac5aab26a469b8f`;
- packaged checksum validation **46/46**;
- 47 package files / 27 fixtures / five executables / two static libraries;
- seven approved targets built Release/static/Ninja **111/111**;
- artifact metadata `runtimeExecution=false`;
- no generated Directional binary/test/benchmark/ctest/CLI/GUI/help/list/discovery command executed.

Implementation summary:

- result-level scalar `periodicHolonomy` authority replaced by canonical `periodicHolonomies` collection;
- relation authority includes component/sheet, Z4 rotation, integral translation, source route/cut and stable source-topology signatures;
- equivalent/reversed descriptions canonicalize;
- conflicts reject as `IncompatiblePeriodicRelation`;
- unresolved distinct same-sheet basis authority rejects as `AmbiguousPeriodicRelationBasis` rather than selecting by order/ID/count/frequency/proximity;
- collection is live in structural hashing, diagnostics, benchmark relation cardinality, diagnostics copy/merge and component/sheet-aware periodic materialization;
- G3 single-annulus tests and new G4 semantic tests are compiled but **not yet executed**.

Detailed compile record: `.agents/Directional/Gate_4_Closed_Genus_One_Holonomy_Basis_Code_Build_Report.md`.

Three bounded pre-success attempts are preserved transparently: two setup-only transform failures (log artifacts `9014513436`, `9014530231`) and one compile failure caused by the missing `std::vector<std::uint64_t>` hash overload (log artifact `9014631674`). None executed project runtime binaries.

## Active G4 runtime evidence and decision

Old G3 torus baseline:

- source topology: connected closed genus one, 72 V / 144 triangles / Euler characteristic 0 / no boundary;
- producer `Rejected` at `tracing/phase-front`;
- reason `InvalidPeriodicTopology`;
- zero traces/arrangement/completion/output;
- no fallback/recovery;
- partial diagnostics already retain one relation `r=0`, `t=(24,0)`, route 24, cut 2 before a second local relation hits the scalar-authority limit.

The next turn must execute exact artifact `9014730437` without rebuild and determine whether the new relation collection removes that representation barrier truthfully.

Material progress requires:

1. the five new G4 periodic-relation semantic tests pass;
2. all 17 focused/retained G0-G3 contracts remain passing;
3. plane/seam/close-sheets/cylinder retain exact direct deterministic strict-valid output and G3 hashes;
4. torus no longer rejects merely because a second compatible relation exists;
5. retained relations are demonstrably live in diagnostics/structural/materialization authority;
6. no fallback/recovery or prohibited ownership heuristic is used.

Direct strict-valid torus production is preferred. A deeper truthful torus failure is acceptable as first-slice material progress only when the collection is retained and consumed and the new earliest failing contract is precisely identified.

Do **not** hardcode or expect a torus relation count or `t=(24,0)` from the old partial diagnostic. Observe the new artifact.

The prescribed sphere remains later G4 evidence. It previously reached 766 traces / 30 arrangement cells and failed completion at `repeated-boundary-node` plus parity-alternative budget exhaustion. Do not preempt the earlier torus classification.

## Exact next-turn execution declaration

Before runtime execution state:

```text
Turn type: Test + Benchmark only
Exact artifact: 9014730437 (g4-holonomy-basis-code-build), workflow run 31233594490
Runtime source authority: primary implementation aa0f115c19fc8a5afd8487ebb561e2de2b8551ba plus final compile source 6e754bdd64482582d39e71184805fbb053c99f86
No-build boundary: do not edit source/tests/fixtures/validators/benchmarks/build files and do not configure, compile, link, or rebuild
First correctness check: run the five new G4 periodic relation tests, then retain all 17 G0-G3 focused contracts
Direct regression gate: plane, seam, close sheets, cylinder must retain direct strict-valid deterministic G3 authority with no fallback/recovery
Primary G4 observation: exact torus must no longer reject solely because a second compatible periodic relation exists; record the canonical relation collection and the earliest truthful terminal behavior
Acceptable material progress: direct strict-valid torus output, or a deeper truthful failure only after the relation collection is demonstrably retained and consumed
Deferred: prescribed sphere unless torus closes; G5 adaptivity/features; G6 bunny/vase production; historical completion/simplification repair unrelated to the new earliest failure
```

Follow `.agents/Directional/Gate_4_Closed_Genus_One_Holonomy_Basis_Artifact_Only_Test_Benchmark_Plan.md` exactly.

## Lessons that must not be repeated

- A test expectation is not automatically production authority; verify that the fixture naturally creates the claimed witness. The G3 field witness originally failed only because 0.25 target subdivision made a whole 0.5 source inter-ring edge impossible as one front edge.
- Raw DCEL/source numeric IDs are not stable semantic identities. Compare canonical source endpoint/route authority.
- A source-topologically valid periodic candidate is not field-authoritative merely because it is first/lexicographically minimal.
- Endpoint ownership tolerance may not emit tolerance-expanded geometry; canonicalize to exact source-simplex geometry.
- GitHub build workflows must use this repository's `DIRECTIONAL_BUILD_TESTS` / `DIRECTIONAL_BUILD_BENCHMARKS` options and enough fetch depth to verify/package the exact source parent.
- Packaged tests may retain Actions absolute fixture paths. Artifact-only validation may expose immutable packaged fixtures through a recorded runtime-only symlink; never rebuild or patch packaged source to solve that path issue.
- Timeout is failure only; do not infer a disposition from an incomplete run.
- The successful G4 build needed a `std::vector<std::uint64_t>` hash overload because canonical topology signatures are 64-bit; do not regress structural hashing back to transient source-edge IDs.
- Multiple current periodic relations may belong to distinct authoritative source sheets. Do not infer a generic same-sheet torus homology basis unless runtime topology actually requires one; unresolved same-sheet basis remains fail-closed until derived structurally.

## Turn boundary

Authoritative cadence:

`Code + Build -> Test + Benchmark -> [Optional Review] -> Code + Build`.

Never combine turn types.

- Code + Build may edit/configure/compile/link approved targets, but may not execute generated project binaries/tests/benchmarks/ctest/CLI/GUI/help/list/discovery.
- Test + Benchmark executes the exact built artifact and may not edit production/test/fixture/validator/benchmark/build source or configure/compile/relink a replacement.
- Review is optional. Review policy is currently `never`, so the Test + Benchmark plan becomes authoritative.
- Build and runtime claims require exact pushed/evidence commit and artifact authority.
- Direct mandatory fixture/gate evidence outranks aggregate totals.
- Two consecutive Code + Build turns without material progress require mandatory design review or bounded producer-replacement proof. One G4 Code + Build turn has occurred since G3 closure; runtime validation is next, so the two-turn stop threshold is not reached.

## Workflow/temp cleanup — mandatory

1. inspect `.github/workflows`, `.agents/connector-triggers`, `.github/agent-triggers`, and `.agents/Directional/turn-payloads` at start and end;
2. remove stale bounded workflows;
3. during remote execution retain the durable workflow plus at most one bounded workflow/payload when such a workflow is genuinely needed;
4. after artifact/log/source/blobs/build or runtime authority is verified remove the bounded workflow, trigger, and payload;
5. final workflow state must contain only approved durable workflow state and no stale artifact/trigger debris;
6. do not remove a durable dependency required by normal repository operation;
7. retain payload/source-transfer data until its authority is verified, then remove it.

Current end-of-turn hygiene is clean: `.github/workflows` contains only `agent-source-snapshot.yml`; bounded G4 workflow/trigger/payloads are absent.

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
