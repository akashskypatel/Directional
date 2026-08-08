# Gate 4 Closed-Genus-One Source-Sheet Boundary Authority — Code + Build Plan

Status: **authoritative next turn**  
Turn type: **Code + Build only**  
Active design gate: **G4 topology-distinct completion and singularities**  
Review policy: `never`

## Turn boundary

Do not execute any generated Directional binary, test, benchmark, `ctest`/discovery command, CLI/GUI command, help/list command, or custom input during this turn.

Allowed work is source/test design implementation, configure, compile/link the approved targets, and immutable artifact packaging only.

## Entering runtime authority

Exact runtime-proven artifact:

- artifact **`9016834575`** (`g4-curved-disk-code-build`);
- workflow run/job `31240168780 / 93059691196`;
- implementation `90046be649a0fd051e6c44eceec07198dc542c29`;
- cleanup `508211936b790dfb40cdbece7900bb0522368b76`;
- ZIP SHA-256 `6bf7f897926ffeb4634edba67390f60070f8d1413f97bc41fac4435f6ae28e67`;
- internal manifest SHA-256 `e0ec3737e23fbb5c21b6c0be6acb3aa8b3f538b954c566867b6c309a6f5f4736`;
- recursive checksums **48/48**;
- new curved-disk semantics **6/6**;
- prior sheet coverage **3/3**;
- G4 periodic relations **5/5**;
- retained G0-G3 **17/17**;
- direct plane/seam/close-sheets/cylinder exact hashes retained deterministic **3/3**;
- no fallback/recovery.

Detailed runtime record: `.agents/Directional/Gate_4_Closed_Genus_One_Curved_Disk_Sheet_Artifact_Only_Test_Benchmark_Report.md`.

## Required design declaration before source edits

Emit this exact scope declaration before modifying production or test source:

```text
Active design gate: G4 topology-distinct completion and singularities
Earliest failing fixture/contract: exact torus now reaches the curved bounded disk producer and deterministically fails at tracing/phase-front as Rejected / InvalidBoundedDiskTopology; immutable source inspection shows the rejected local boundary is an internal source edge that is not a hard feature even though source-sheet classification made it an authoritative cross-sheet boundary
Missing design contract: curved-disk local boundary validation currently accepts genuine source boundary edges and hard-feature internal edges, but does not recognize an internal edge between different authoritative source component/sheet labels as a valid source-sheet boundary
Smallest general implementation change: validate every internal curved-disk local boundary edge against existing source labels; accept it only when hard-feature authority applies or the opposite incident source face belongs to a different authoritative component/sheet, while continuing to reject hidden same-component/same-sheet cuts
Observable material-progress condition: exact torus advances beyond InvalidBoundedDiskTopology caused solely by non-hard source-sheet boundaries to Produced/materialization or the next deeper truthful typed invariant; curved-disk 6/6, sheet-coverage 3/3, G4 relation 5/5, G0-G3 17/17 and direct hashes remain unchanged
Explicitly deferred: harmonic chart/boundary-phase/front-pairing repair until runtime reaches those invariants, generic arrangement/completion repair, prescribed sphere until torus materialization closes, G5 adaptivity/features, G6 bunny/vase production, historical completion/simplification failures, validator changes, feature demotion, Euclidean welding and unrelated optimization
```

## Exact runtime blocker

Three independent torus processes under artifact `9016834575` report:

- disposition `Rejected`;
- stage `tracing/phase-front`;
- reason `InvalidBoundedDiskTopology`;
- first invalid source face `52`;
- two periodic relations reached before the rejection;
- zero generic trace/arrangement/completion work after rejection;
- terminal `NotProductionReady:tracing`;
- no fallback/recovery.

Face 52 and relation count 2 are **diagnostic evidence only**. Never use them for fixture recognition, branching, ownership, ordering, or success criteria.

The source-level invariant is general:

`build_curved_bounded_disk_phase_front_for_faces()` forms the local sheet boundary from edges with one local incident face. For such an edge, if the full source mesh has two incident faces, current code requires `options.hardFeatureEdges.count(key) != 0`. Otherwise it rejects `InvalidBoundedDiskTopology`.

That condition is incomplete because `classify_source_surface_labels()` can create a sheet boundary without inserting the source edge into `hardFeatureEdges`. It refuses traversal when:

- an explicit barrier/hard edge is present;
- unmarked sharp-bend traversal is disabled and adjacent normals violate `normalCompatibility`; or
- close/opposing-sheet conflict logic rejects traversal under the configured geodesic policy.

Therefore source-sheet labels are part of authoritative boundary identity independently of hard-feature membership.

## Required production correction

Make the smallest general correction at the curved-disk boundary-authority check.

For each local boundary edge:

1. genuine source boundary — if the full source mesh has only one incident face, retain current valid boundary behavior;
2. hard-feature internal boundary — retain current valid behavior;
3. non-hard internal edge — require valid source label arrays and identify the local incident face plus the opposite full-source incident face;
4. accept the edge only when those two incident faces are **not** source-compatible under existing authoritative component/sheet labels;
5. reject when both incident faces belong to the same authoritative component and sheet, because that is a hidden ordinary internal cut;
6. reject malformed/ambiguous incidence or missing labels with an existing precise typed reason, adding a new reason only if no existing reason accurately expresses the failure.

Prefer the existing `source_faces_compatible()` / source-label validation helpers rather than duplicating ownership logic.

Do not change the source classifier merely to make the producer accept the torus. The classifier's normal/close-sheet separation is current authority and already under G2 contracts.

## Boundary provenance requirements

A valid cross-sheet disk boundary must remain exact source topology, not Euclidean geometry:

- retain the exact source edge key and source face ownership;
- preserve the local cell's source component/sheet;
- do not merge across the opposite sheet;
- do not convert a source-sheet boundary into an exterior source-mesh boundary;
- do not add it to `hardFeatureEdges` synthetically merely to satisfy the producer;
- do not demote actual hard features;
- downstream boundary/front provenance must continue to distinguish sheet authority structurally.

## Required compile-only semantic regressions

Add focused tests whose fixtures naturally establish the intended boundary classes. Compile them only in this turn.

At minimum cover:

1. **non-hard authoritative cross-sheet boundary accepted** — a connected χ=1 local disk whose boundary contains an internal source edge separating different source-sheet labels, without marking that edge hard, does not reject as `InvalidBoundedDiskTopology` solely for that edge;
2. **same-sheet hidden cut rejected** — the same topology with both incident source faces carrying the same component/sheet labels remains fail-closed as invalid local disk boundary authority;
3. **hard-feature boundary retained** — existing hard-feature disk-boundary behavior remains exact;
4. **row-order invariance** — equivalent face-row ordering preserves the same structural authority/failure;
5. **mixed producer composition** — planar + periodic + curved-disk aggregation still uses exact source-sheet ownership and periodic relations;
6. **exact torus producer boundary** — the committed torus must no longer fail solely because a valid non-hard cross-sheet local boundary is not in `hardFeatureEdges`; assert only advancement beyond this contract, not unjustified output counts or a fixture-specific reason;
7. retain all six curved-disk focused cases;
8. retain sheet-coverage **3/3**;
9. retain G4 periodic-relation **5/5**;
10. retain G0-G3 **17/17**.

A test fixture is invalid if its purported cross-sheet edge does not actually separate different authoritative labels. Fix such a fixture rather than weakening the intended assertion.

## Determinism and generalization prohibitions

The implementation must not:

- special-case `torus.obj`, face 52, any source face/sheet/component ID, observed relation count, or boundary length;
- infer sheet authority from minimum ID, first discovered item, count/frequency majority, arbitrary subset, or Euclidean proximity;
- mark every local boundary as valid merely because the active-face subset excludes its opposite face;
- mutate source labels or hard-feature sets to force acceptance;
- remove/demote hard-feature rails;
- merge different sheets by position;
- invent artificial annulus cuts;
- Euclidean-weld seams;
- use fallback/source-grid recovery as production success;
- alter validators or thresholds;
- synthesize topology/cell/Euler counts;
- repair harmonic chart, boundary phase, front pairing, arrangement, or completion before runtime proves one of those later invariants is first-blocking.

## Build scope

Build/package the same seven approved Release/static/Ninja targets:

1. `directional_core`;
2. `directional_pipeline`;
3. `directional_compiled_api_tests`;
4. `directional_surface_cell_producer_tests`;
5. `directional_surface_cell_completion_tests`;
6. `directional_surface_cell_validation_tests`;
7. `directional_benchmarks`.

Use `CMAKE_GTEST_DISCOVER_TESTS_DISCOVERY_MODE=PRE_TEST`. Preserve existing static/GMP and disabled optional-solver configuration from the latest compile report and shallow submodule policy.

**Do not execute any generated project binary in this Code + Build turn.**

Package an immutable artifact with exact binaries/libraries, fixture tree, source archive/patch, source/blob authority, build logs, command-boundary metadata with `runtimeExecution=false`, and recursive checksums. Upload an unconditional separate log artifact.

## Build failure handling

If compilation fails:

- inspect the exact compiler diagnostic;
- make only the smallest compile-valid correction within this boundary-authority/test scope;
- do not run tests to diagnose compilation;
- preserve failed logs;
- package only a fully successful compile/link artifact.

If the boundary-authority correction unexpectedly requires broad classifier or downstream architecture changes, stop and update the next plan rather than expanding scope silently.

## Following Test + Benchmark gate

The following turn must use only the exact new artifact and, in order:

1. run the new source-sheet boundary authority semantics;
2. retain curved-disk **6/6**;
3. retain sheet-coverage **3/3**;
4. retain G4 relations **5/5**;
5. retain G0-G3 **17/17**;
6. retain direct plane/seam/close-sheets/cylinder exact deterministic baselines;
7. run exact torus in at least three independent processes.

Preferred torus result is complete authoritative sheet coverage, `Produced`, materialization, and strict-valid closed pure-quad output.

Acceptable material progress is a deeper deterministic typed boundary-phase/chart/front-pairing/materialization failure only when the non-hard cross-sheet boundary is accepted by source-label authority, the curved-disk producer remains live, periodic authority remains structurally valid, and no generic/fallback path substitutes for failure.

Prescribed sphere remains deferred unless torus reaches direct strict-valid production.

## End-of-turn records

Create/update:

- a source-sheet-boundary Code + Build report;
- the exact next artifact-only Test + Benchmark plan;
- `TODO`;
- `MILESTONE_G_TODO.md`;
- `.agents/Directional/Future_Chat_Session_Handoff.md`;
- `benchmark-results/design-aligned-runtime-summary.json`;
- PR #8 title/body.

Remove bounded workflow/trigger/payload debris after artifact authority is verified. Keep PR #8 open, draft, unmerged. End with a **new top-level PR #8 conversation comment as the final repository write**.
