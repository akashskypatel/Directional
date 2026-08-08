# Future Chat Session Handoff — Directional Surface Cells

## Resume here

Repository: `akashskypatel/Directional`  
Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`  
Draft PR: #8 — keep **open, draft, unmerged**  
Review policy: `never`  
Active gate: **G4 topology-distinct completion and singularities**  
Next turn: **Test + Benchmark — artifact-only field-authoritative polygonal bounded-disk boundary-phase validation**  
Authoritative next plan: `.agents/Directional/Gate_4_Closed_Genus_One_Field_Authoritative_Polygonal_Disk_Boundary_Phase_Artifact_Only_Test_Benchmark_Plan.md`

Read this handoff first, then `TODO`, `MILESTONE_G_TODO.md`, `.agents/Directional/DESIGN.md`, the current runtime report `.agents/Directional/Gate_4_Closed_Genus_One_Source_Sheet_Boundary_Authority_Artifact_Only_Test_Benchmark_Report.md`, the latest compile report `.agents/Directional/Gate_4_Closed_Genus_One_Field_Authoritative_Polygonal_Disk_Boundary_Phase_Code_Build_Report.md`, the authoritative artifact-only plan above, `tests/TESTING_STRATEGY.md`, `.agents/Directional/GitHub_Workflow_Policy.md`, and the relevant turn-based-coding-agent Test+Benchmark/testing-integrity/recovery/handoff/GitHub-workflow references.

## Current tested authority

G0, G1, G2, and **G3 are passed**. G4 remains **active**.

Current runtime-proven artifact: **`9019024467`** (`g4-source-sheet-boundary-code-build`)  
Workflow run/job: `31247546780 / 93078496378`  
Implementation: `b425898fa7367406fa0c07e8f4441a37efc01315`  
Cleanup: `3fcfd2cf2996919eed5c951a9148d83deb5aa6f8`

Runtime authority:

- source-sheet-boundary semantics **3/3**;
- combined source-sheet-boundary + curved-disk semantics **9/9**;
- sheet-coverage semantics **3/3**;
- G4 periodic-relation semantics **5/5**;
- retained G0-G3 focused contracts **17/17**;
- plane hash `730caeae49ec872c`, 64 quads / 81 V, deterministic 3/3;
- seam hash `5bdf34d7802e9fb0`, 64 quads / 81 V, deterministic 3/3;
- close-sheets hash `89b052762f52a5af`, 200 quads / 242 V / two components, deterministic 3/3;
- cylinder hash `32135be51d7a0a26`, 288 pure quads / 320 V, one relation `r=0`, `t=(32,0)`, route 32, cut 4, 1,728 traces, 290 arrangement/simplified cells, zero validation failures, exactly two genuine 32-edge exterior loops, deterministic 3/3;
- no passing direct case uses fallback or source-grid recovery;
- bounded suites: producer **115/116**, completion/simplification **154/164**, validation **60/60**, API **8/8**, aggregate **337/348**.

Detailed runtime record: `.agents/Directional/Gate_4_Closed_Genus_One_Source_Sheet_Boundary_Authority_Artifact_Only_Test_Benchmark_Report.md`.

Exact torus under current runtime authority is deterministic 3/3:

- producer `Rejected` at `tracing/phase-front`;
- reason `InvalidBoundedDiskBoundaryPhase`;
- first invalid face `-1`;
- periodic authority remains live;
- zero downstream trace/arrangement/simplification/completion cells after rejection;
- no fallback, legacy substitution, returned-input fallback, or source-grid recovery.

Existing artifact diagnostics do not expose which global four-run/canonical-order subcheck fired. Never infer an unobserved torus run count or branch sequence from the old failure.

## Completed polygonal boundary-phase Code + Build candidate

Exact compile artifact: **`9021175280`** (`g4-polygonal-boundary-phase-code-build`)  
Workflow run/job: **`31254896323 / 93096734152`**  
Event commit: `c24af6c83ab25397df1c2bfc4692b91689502f85`  
Implementation commit: **`085db9ec23ffaa509b1f5a29e72968229efa103d`**  
Payload cleanup: **`c3b5dcbcd0c35ee421d5b44273c142aa9f874dcc`**

Artifact authority:

- outer ZIP SHA-256 **`16191e84bcfcebb2cfc1401b4aae7d5d8de2a02444f189a54d68164c1327a646`**;
- internal `SHA256SUMS` SHA-256 **`a8161eb579e1c06e63b5c7bc6203f610693f3e6259f56d8ce2c6ba78e424d3b5`**;
- recursive checksums **48/48**;
- 49 files / 27 fixtures / five executables / two project static libraries;
- approved Release/static/Ninja build **111/111**;
- log artifact `9021175444`, SHA-256 `170c8d869af4ec737250a1a5ce7dfb532ca76fbef972a696cea85a53c61b0f67`;
- `runtimeExecution=false`, review policy `never`.

Final packaged source blobs:

- diagnostics header `9597c49693a1146e5dac2ac90270348b55a0c91d`;
- tracing header `0c1daa94300121df40c923716314ae6b242c7e8c`;
- benchmark source `fd74cd39fff73bee7b4db578eb08382bd6ef50cf`;
- tracing source `c834e8c81db04c39af9ecf1f45044ea107de3291`;
- pipeline source `945bbc58bc56cb9838532889c616520cb234aaa3`;
- Phase 10 tests `981b0f6e6fc935c1bfe3d1f6871736035d6bdfcb`.

Detailed compile record: `.agents/Directional/Gate_4_Closed_Genus_One_Field_Authoritative_Polygonal_Disk_Boundary_Phase_Code_Build_Report.md`.

## Candidate implementation contract

The candidate introduces first-class `SurfaceBoundedDiskBoundaryPhase` / run records with:

- source-attached cyclic run ordering;
- transported global branch, family and sign;
- exact run start/end corner provenance;
- signed quarter-turn to the next run;
- cumulative and run intrinsic lengths;
- source face/edge provenance;
- source-boundary, hard-feature and non-hard source-sheet edge authority;
- source component/sheet ownership;
- cyclic signed quarter-turn index;
- polygon/chart state and deterministic structural hash.

Boundary semantics:

- per-edge field-alignment threshold remains unchanged;
- adjacent runs must differ by reciprocal ±quarter-turn or fail typed `InvalidBoundedDiskBoundaryTurn`;
- oriented cyclic disk boundary index must close or fail typed `InvalidBoundedDiskBoundaryIndex`;
- no run is inserted, deleted, merged, split or length-corrected to manufacture a desired side count;
- canonical run rotation remains geometry/source-topology based, not raw ID/order/count/frequency/proximity based.

Chart semantics:

- the established four-run all-positive-turn rectangle is preserved as the exact fast path, including opposite-side length averaging and existing grid/front construction;
- a valid non-rectangular phase is developed from transported branch directions and exact intrinsic run lengths into an orthogonal polygon;
- no synthetic closing edge or Euler correction is added;
- polygon closure, area/extents and nonadjacent self-intersection are checked;
- boundary source vertices map monotonically to exact polygon side intervals;
- interior UV uses the existing deterministic positive-weight solve;
- all source triangles must remain finite, nondegenerate and orientation-consistent;
- a successfully constructed non-rectangular chart sets `chartConstructed=true` and then intentionally rejects at the deeper typed `InvalidBoundedDiskFrontPairing` invariant because generalized polygon lattice clipping/front pairing is not implemented in this slice.

This deeper rejection is observable rather than relabeled: aggregation retains the boundary-phase record, trace-network hashing consumes its first-class state, and diagnostics expose phase count, run count, polygonal phase count, constructed-chart count, and phase hashes. Aggregate rejection does not leak partial cells.

Compile-only tests add a natural L-shaped six-run/reflex-corner witness, invalid transported turn, face-row invariance, rectangular fast-path retention, periodic composition without partial cells, source-sheet/hard-feature provenance retention, and strengthened exact torus advancement. **None has executed yet.**

## Exact next-turn execution declaration

Before runtime execution state:

```text
Turn type: Test + Benchmark only
Exact artifact: 9021175280 (g4-polygonal-boundary-phase-code-build), workflow run/job 31254896323 / 93096734152
Runtime candidate source authority: implementation 085db9ec23ffaa509b1f5a29e72968229efa103d, cleanup c3b5dcbcd0c35ee421d5b44273c142aa9f874dcc
No-build boundary: do not edit production/tests/fixtures/validators/benchmarks/build files and do not configure, compile, link, regenerate discovery, or rebuild
First correctness check: verify artifact/source/blobs/checksums, then run the new generalized polygonal boundary-phase semantic tests
Regression gate: retain source-sheet-boundary 3/3, prior curved-disk authority, sheet coverage 3/3, G4 relations 5/5, retained G0-G3 17/17 and exact direct plane/seam/close-sheets/cylinder hashes with no fallback/recovery
Primary G4 observation: exact torus must prove the first-class boundary phase is constructed and consumed and advance beyond the old rectangle-only InvalidBoundedDiskBoundaryPhase, preferably to production or truthfully to the deeper polygonal chart/front-pairing invariant
Expected bounded material progress: if torus has a valid non-rectangular phase and chart, diagnostics show phase/run/polygon/chart/hash evidence and producer stops deterministically at InvalidBoundedDiskFrontPairing; do not infer or repair beyond the artifact
Deferred: prescribed sphere unless torus direct strict-valid production closes; G5 adaptivity/features; G6 bunny/vase; historical completion/simplification repair
```

Follow `.agents/Directional/Gate_4_Closed_Genus_One_Field_Authoritative_Polygonal_Disk_Boundary_Phase_Artifact_Only_Test_Benchmark_Plan.md` exactly.

## Lessons that must not be repeated

- A test expectation is not production authority; verify that its fixture naturally creates the claimed structural witness.
- Raw source/DCEL numeric IDs are not stable semantic identities; use canonical topology and source ownership.
- A topologically plausible route is not field-authoritative merely because it is first/lexicographically minimal.
- Endpoint tolerance may not emit tolerance-expanded geometry; canonicalize to exact source-simplex geometry.
- Connector-created text payload authority is the committed Git blob; verify transferred patch content/hash separately before application.
- For connector-mediated source transfer, prefer independently verifiable raw text chunks over manually copied compressed/base64 streams; two prior encoded transfers corrupted bytes before source modification.
- GoogleTest macro expressions containing template commas require extra expression parentheses; do not confuse syntax failures with production semantics.
- Packaged tests may carry Actions absolute fixture paths; artifact-only validation may expose immutable packaged fixtures through a recorded runtime-only symlink, never by patching artifact bytes.
- Canonical periodic topology signatures are 64-bit; preserve the `std::vector<std::uint64_t>` structural-hash path.
- Multiple periodic relations can belong to distinct authoritative source sheets; do not invent a same-sheet homology basis without source-topology evidence.
- A partially accumulated phase-front is not whole-surface authority; never fix coverage by merely flipping disposition to `Produced`.
- The torus's hard-feature rails are source-derived authority; do not demote them to simplify chart topology.
- Source-sheet boundaries are not synonymous with hard-feature edges. The classifier can create authoritative sheet separation through normal compatibility and close/opposing-sheet logic.
- Observed face IDs, sheet counts, relation counts, run counts and boundary lengths are diagnostics, not implementation or acceptance keys.
- A focused hard-boundary test does not prove broader source-sheet boundary coverage; retain the naturally non-hard cross-sheet witness.
- Do not infer an exact boundary run count from the old `InvalidBoundedDiskBoundaryPhase`; artifact `9019024467` does not expose the failed global run-count/canonical-order subcheck.
- A four-run rectangular chart is a special case, not permission to arbitrarily merge/split a valid field boundary until four sides remain.
- A changed failure reason is not material progress unless first-class boundary-phase/chart diagnostics prove the generalized representation was constructed and consumed.
- A valid polygonal chart does not authorize partial output; non-rectangular front pairing remains fail-closed until implemented structurally.
- Harmonic chart compilation and focused applicability are not proof of production chart success; follow the first runtime invariant.
- A downstream completion failure is not automatically the next target; follow the first truthful producer/materialization failure.
- Timeout is failure only; never infer correctness/disposition from incomplete execution.

## Turn boundary — mandatory

Authoritative cadence:

`Code + Build -> Test + Benchmark -> [Optional Review] -> Code + Build`.

Never combine turn types.

- Code + Build may edit/configure/compile/link approved targets, but may not execute generated project binaries/tests/benchmarks/ctest/CLI/GUI/help/list/discovery.
- Test + Benchmark executes the exact built artifact and may not edit production/test/fixture/validator/benchmark/build source or configure/compile/relink/regenerate a replacement.
- Review is optional. Review policy is currently `never`; after Test + Benchmark its next Code + Build plan is authoritative.
- Build and runtime claims require exact pushed/evidence commit and artifact authority.
- Direct mandatory fixture/gate evidence outranks aggregate totals.
- Two consecutive Code + Build turns without material progress require mandatory design review or bounded producer-replacement proof. The preceding artifact-only turn established material progress; this is the first Code + Build since then, so the no-progress Code + Build count is 1 pending runtime decision.

## Workflow/temp cleanup — mandatory

1. inspect `.github/workflows`, `.agents/connector-triggers`, `.github/agent-triggers`, and `.agents/Directional/turn-payloads` at start and end;
2. remove stale bounded workflows;
3. during remote execution retain the durable workflow plus at most one bounded workflow/payload when genuinely needed;
4. after artifact/log/source/blobs/build or runtime authority is verified remove the bounded workflow, trigger and payload;
5. final workflow state must contain only approved durable workflow state and no stale artifact/trigger debris;
6. do not remove a durable dependency required by normal repository operation;
7. retain payload/source-transfer data until its authority is verified, then remove it.

The successful polygonal Code + Build removed its six raw payload files in cleanup commit `c3b5dcbcd0c35ee421d5b44273c142aa9f874dcc`, then removed the bounded workflow before its trigger after artifact verification. Expected final state: `.github/workflows` contains only `agent-source-snapshot.yml`; `.agents/connector-triggers`, `.github/agent-triggers`, and `.agents/Directional/turn-payloads` are absent. Verify again at the beginning and end of the Test + Benchmark turn.

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
