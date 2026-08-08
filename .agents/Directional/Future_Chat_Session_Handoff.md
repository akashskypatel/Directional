# Future Chat Session Handoff — Directional Surface Cells

## Resume here

Repository: `akashskypatel/Directional`  
Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`  
Draft PR: #8 — keep **open, draft, unmerged**  
Review policy: `never`  
Active gate: **G4 topology-distinct completion and singularities**  
Next turn: **Code + Build — G4 curved bounded disk-sheet phase-front producer**  
Authoritative next plan: `.agents/Directional/Gate_4_Closed_Genus_One_Curved_Disk_Sheet_Code_Build_Plan.md`

Read this handoff first, then `TODO`, `MILESTONE_G_TODO.md`, `.agents/Directional/DESIGN.md`, the latest sheet-coverage runtime report, the latest sheet-coverage Code + Build report, the authoritative curved-disk Code + Build plan, `tests/TESTING_STRATEGY.md`, `.agents/Directional/GitHub_Workflow_Policy.md`, and the relevant turn-based-coding-agent Code+Build/testing-integrity/recovery/handoff/GitHub-workflow references.

## Current tested authority

G0, G1, G2, and **G3 are passed**. G4 remains **active**.

Exact current runtime artifact: **`9015931928`** (`g4-sheet-coverage-code-build`)  
Workflow run/job: `31237248211 / 93051938159`  
Implementation: `856554ce648e5df09ac50f5c94e3e8f098181524`  
Final compile-source commit: `a647215b4993338b054f04d4c8e54e7ef5370001`  
Payload cleanup: `e46a6d99a45f22f31672c8e5a3367735427d827e`

Artifact authority:

- ZIP SHA-256 `108580a2a20bdd7d50169ed076e7b0583466d5ab11c1a2170814eb4fbe8f3cc4`;
- internal `SHA256SUMS` SHA-256 `c801b0bb157ba2e1b4537c636306d300ab289db2b89e915718efc73394c03635`;
- recursive checksums **47/47**;
- 48 files / 27 fixtures / five executables / two static libraries;
- validation made no configure/compile/link/rebuild or source/test/fixture/validator/benchmark/build edit.

Focused/runtime authority:

- sheet-coverage semantics **3/3**;
- G4 periodic-relation semantics **5/5**;
- retained G0-G3 focused contracts **17/17**;
- plane hash `730caeae49ec872c`, deterministic 3/3;
- seam hash `5bdf34d7802e9fb0`, deterministic 3/3;
- close-sheets hash `89b052762f52a5af`, 200 quads / 242 vertices / two components, deterministic 3/3;
- cylinder `Produced / CompletedSurfaceCells`, one relation `r=0`, `t=(32,0)`, route 32, cut 4, 1,728 traces, 290 arrangement/simplified cells, 288 pure quads / 320 vertices, zero validation failures, exactly two genuine 32-edge exterior loops, hash `32135be51d7a0a26`, deterministic 3/3;
- no passing direct case uses fallback or source-grid recovery.

Bounded suites:

- producer **107/108**, only the existing sub-millisecond `StrictValidatorOverheadStaysBelowFivePercent` performance threshold fails;
- completion/simplification **154/164**, exact same ten historical failures;
- validation **60/60**;
- compiled API **8/8**;
- aggregate **329/340**.

Detailed runtime record: `.agents/Directional/Gate_4_Closed_Genus_One_Sheet_Coverage_Artifact_Only_Test_Benchmark_Report.md`.

Latest compile record: `.agents/Directional/Gate_4_Closed_Genus_One_Sheet_Coverage_Code_Build_Report.md`.

Local evidence archive: `directional-g4-sheet-coverage-artifact-only-evidence.tar.gz`, SHA-256 `4bb8e5235adbffc05411c54d378511ae4eea63bf314d7caf0e50f043d5532b47`.

## Exact current G4 torus evidence

The partial-authority defect is closed. Three independent exact torus runs now deterministically report:

- `surfaceCellAuthoritativeProducerDisposition = Rejected`;
- first invalid stage `tracing/phase-front`;
- reason `UnsupportedSourceSheetTopology`;
- first invalid source face 48;
- periodic relation count **3**;
- trace/arrangement/completion output counts 0 after authoritative rejection;
- terminal `NotProductionReady:tracing`;
- no output/fallback/legacy substitution/input return/source-grid recovery.

Stable stage hashes: feature `f15e4f3be07d3c7f`, metric `34cb872327c9b0c6`, relief `8ccb10d25b69edb9`, tracing `a99e1237a1fe6596`.

This is material progress over artifact `9014730437`: the old `partial NotApplicable -> 670 generic traces -> 113 embedded arcs -> 0 arrangement cells -> SideSubdivisionRepair` path no longer executes.

## Exact source diagnosis — missing curved bounded disk producer

Read-only packaged-source/topology analysis reproduces the current **48 hard feature edges / four closed feature curves** and the authoritative source-sheet classification:

- three χ=0 sheets have two equal boundary loops and are valid periodic annuli; they naturally account for the three retained periodic relations;
- two sheets are non-planar χ=1 topological disks with one genuine source/hard-feature boundary loop; these are unsupported by the current producer family.

The first unsupported disk contains face 48 and has one 22-edge boundary loop; the second has one 18-edge boundary loop. **These IDs/counts are diagnostic evidence only. Never use them for fixture recognition, ownership, ordering, or success branching.**

Current producer applicability explains the failure:

- the bounded uniform producer is planar/rectangular and correctly treats the strongly non-planar disk as outside its contract;
- the periodic-annulus producer requires χ=0 and exactly two compatible boundary cycles, so it correctly treats a χ=1 one-boundary disk as outside its contract.

The next missing design contract is therefore a generalized **intrinsic curved bounded disk-sheet phase-front producer** derived from source topology and reciprocal cross-field transport.

Do not repair the torus by demoting its hard-feature rails, forcing a disk through annulus logic, inventing an artificial exterior cut, Euclidean seam welding, or skipping to generic arrangement/completion.

## Exact next-turn design declaration

Before any source edit emit:

```text
Active design gate: G4 topology-distinct completion and singularities
Earliest failing fixture/contract: exact torus now fails deterministically at tracing/phase-front as Rejected / UnsupportedSourceSheetTopology on the first curved disk source sheet; three annular sheets retain periodic relations and the old partial NotApplicable -> generic zero-cell path is gone
Missing design contract: current sheet-local producer family covers planar rectangular bounded sheets and Euler-0 two-boundary periodic annuli, but torus hard-feature/source-sheet authority also yields curved topological disks (chi=1, one genuine boundary loop) that have no authoritative phase-front producer
Smallest general implementation change: add a topology-derived curved bounded disk-sheet phase-front producer that respects source-sheet/hard-feature boundary authority and reciprocal field transport, composes with existing planar/annulus producers, and fails typed on exact unsupported field/topology invariants without fixture/order/ID ownership
Observable material-progress condition: both curved disk sheets obtain deterministic authoritative cell coverage and complete mixed-sheet aggregate reaches Produced/materialization, or the new disk producer identifies a deeper typed structural blocker; prior sheet-coverage 3/3, relation 5/5, G0-G3 17/17 and direct hashes remain unchanged
Explicitly deferred: generic arrangement/completion repair, prescribed sphere until torus sheet coverage/materialization closes, G5 adaptive scale/hard-feature expansion, G6 bunny/vase production, historical completion/simplification failures, validator changes, feature demotion, Euclidean welding, and unrelated optimization
```

## Next-turn execution

Execute `.agents/Directional/Gate_4_Closed_Genus_One_Curved_Disk_Sheet_Code_Build_Plan.md` as **Code + Build only**.

Required properties:

- add a generalized producer for connected simply connected non-planar source sheets with one genuine source/hard-feature boundary;
- derive bounded chart/phase authority from source topology and reciprocal cross-field transport, not a global plane fit;
- preserve exact source-simplex, source-sheet, and hard-feature ownership;
- preserve existing planar bounded and periodic-annulus producers;
- dispatch to the curved-disk producer by structural applicability, never torus IDs/counts/order;
- preserve complete exact-once source-sheet aggregation and the canonical periodic relation collection;
- fail typed at the next genuine transport/singularity/boundary-phase/incidence invariant if the disk cannot be produced;
- add compile-only semantic regressions for non-planar disk applicability, row-order invariance, hard-boundary preservation, invalid reciprocal transport, mixed producer composition, exact torus boundary, and all retained prior contracts;
- compile/package the same seven approved Release/static/Ninja targets;
- **execute no generated Directional binary/test/benchmark/ctest/CLI/GUI/help/list/discovery command**.

The following Test + Benchmark turn must first retain new curved-disk semantics, sheet-coverage 3/3, G4 relation 5/5, G0-G3 17/17, and direct plane/seam/close-sheets/cylinder exact hashes before exact torus decides progress.

Preferred torus result is complete five-sheet authoritative phase-front `Produced`, exact materialization, and strict-valid pure-quad closed output. A deeper deterministic typed field/chart/materialization failure is acceptable material progress only if both curved disks are no longer rejected as unsupported topology and no generic fallback path substitutes for authority.

Prescribed sphere remains deferred until torus sheet coverage/materialization closes.

## Lessons that must not be repeated

- A test expectation is not automatically production authority; verify that its fixture naturally creates the claimed witness.
- Raw source/DCEL numeric IDs are not stable semantic identities; use canonical topology/source ownership.
- A topologically plausible periodic route is not field-authoritative merely because it is first or lexicographically minimal.
- Endpoint tolerance may not emit tolerance-expanded geometry; canonicalize to exact source-simplex geometry.
- Connector-created text payload authority is the committed Git blob; do not assume a locally predicted SHA-256 survives connector serialization.
- GoogleTest macro expressions containing template commas require extra expression parentheses; do not confuse this syntax issue with production semantics.
- Packaged tests may carry Actions absolute paths; if needed in a future artifact-only turn, expose immutable packaged fixtures through a recorded runtime-only symlink rather than patching artifact bytes.
- Canonical periodic topology signatures are 64-bit; preserve the `std::vector<std::uint64_t>` structural-hash path.
- Multiple current periodic relations can belong to distinct authoritative sheets; do not invent a same-sheet homology basis without source-topology evidence.
- A partially accumulated phase-front is not whole-surface authority. Do not fix coverage by merely flipping disposition to `Produced`.
- The torus's 48 hard edges / four closed feature curves are source-derived current authority; do not demote them to avoid implementing the missing disk class.
- The observed face 48, five sheets, three relations, and 22/18 boundary lengths are diagnostics, not implementation keys.
- A downstream completion failure is not automatically the next target; current evidence proves producer topology is earlier.
- Timeout is failure only; never infer correctness or a disposition from incomplete execution.

## Turn boundary — mandatory

Authoritative cadence:

`Code + Build -> Test + Benchmark -> [Optional Review] -> Code + Build`.

Never combine turn types.

- Code + Build may edit/configure/compile/link approved targets, but may not execute generated project binaries/tests/benchmarks/ctest/CLI/GUI/help/list/discovery.
- Test + Benchmark executes the exact built artifact and may not edit production/test/fixture/validator/benchmark/build source or configure/compile/relink a replacement.
- Review is optional. Review policy is currently `never`, so this Test + Benchmark turn's next Code + Build plan is authoritative.
- Build and runtime claims require exact pushed/evidence commit and artifact authority.
- Direct mandatory fixture/gate evidence outranks aggregate totals.
- Two consecutive Code + Build turns without material progress require mandatory design review or bounded producer-replacement proof. The just-completed artifact-only turn established material progress, so this counter resets to 0.

## Workflow/temp cleanup — mandatory

1. inspect `.github/workflows`, `.agents/connector-triggers`, `.github/agent-triggers`, and `.agents/Directional/turn-payloads` at start and end;
2. remove stale bounded workflows;
3. during remote execution retain the durable workflow plus at most one bounded workflow/payload when genuinely needed;
4. after artifact/log/source/blobs/build or runtime authority is verified remove the bounded workflow, trigger, and payload;
5. final workflow state must contain only approved durable workflow state and no stale artifact/trigger debris;
6. do not remove a durable dependency required by normal repository operation;
7. retain payload/source-transfer data until its authority is verified, then remove it.

Current hygiene is clean: `.github/workflows` contains only `agent-source-snapshot.yml`; `.agents/connector-triggers`, `.github/agent-triggers`, and `.agents/Directional/turn-payloads` are absent.

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
