# M4-CP-SCALE-CB16 — Multi-Component Algebraic Cycle Support Code + Build Plan

**Turn:** `M4-CP-SCALE-CB16`
**Type:** Code + Build
**Authority:** `M4-CP-SCALE-TB12-R2-REV`
**Runtime boundary:** **NO generated Directional runtime**; compile/package only, `runtimeExecution=false`

## 1. Goal

Correct the reviewed `RP-07` defect without changing the algebraic cycle basis: `FieldTransportAtlas` must represent every valid `bundle.cycles` row as **all** of its closed directed successor components, rather than requiring the complete row support to be one simple contiguous face loop.

The motivating immutable receipt is row `14`, `BoundaryLoop`, `supportEdges=34`, `uniqueFromFaces=34`, `SupportEdgeReused`, `currentFace=0`, `sourceEdge=0-72`. Review proves that 34/34 unique outgoing origins plus reuse at the canonical start means the first successor orbit closes before all row support is consumed. `dual_cycles` owns a valid algebraic row; this turn must not erase or replace that support.

## 2. Frozen authority

- Accepted runtime authority remains package `10473134357` / source `e15e83c79a1e1962c0ed8d31ea85187ab6600e47` / selector426 **426/426**.
- Candidate diagnostic lineage is artifact `10517300204` / source `94072bb4f24bdc82a24fd0bb07b6dcf37a420a21`; it is not promoted.
- Selector426 is frozen at 426 LF rows, SHA-256 `41f4d559211375c11c8d1f8c9ccde2581db75819d9409366e8f2695b008b5114`, exact first425 `e0e0f394faae536ac257ec5409653a34755a8afe0ca437562eb44c9895790e0b`, owners **30/280/75/41**.
- Retained genus-two fixture bytes and the S5 focus identity/assertions/preconditions are frozen.
- Stable accounting remains **49 / 14 / 35**, debt **5**. No S5 or selector credit is available in Code + Build.

## 3. Authorized semantic change

In `src/authority/FieldTransportAtlas.cpp`, replace only the single-loop assumption inside cycle-support ordering with a deterministic all-components ordering over the same `DirectedCycleEdge` support:

1. Preserve the existing sort key `(fromFace,toFace,sourceEdge)` and duplicate-`fromFace` rejection.
2. Maintain one global used-edge set. Select the least unused directed edge as the start of the next component.
3. Follow the unique successor by `fromFace` until it returns to that component's start. A missing successor, duplicate origin, invalid directed adjacency, reuse **before that component has closed**, or open component remains failure.
4. After a component closes, continue from the least unused support edge until every support edge is consumed exactly once.
5. Canonicalize each component from its least directed-edge tuple and retain global component order by those starts. Flatten the components into the existing `std::vector<FieldTransportStep>` representation. Do not change `FieldCycleWitness` schema unless Review is reopened.
6. Compose transport across every flattened step exactly once and preserve the existing `composed == turningLift mod 4` check. No component may be ignored because another component already closed.

For a row whose support is already one closed component, the resulting step sequence must be exactly the existing sequence. The change is representational for valid multi-component algebraic rows, not a redefinition of row coefficients, cycle kind, turning lift, singularity authority or field transport.

## 4. Independent test/oracle correction

`tests/FieldTransportAtlasTests.cpp` may change only as required to independently encode the same *algebraic row, multiple closed components* contract and add focused controls.

The validator must no longer require the complete `steps` vector to be one contiguous loop. It must independently verify that:

- published support exactly equals the independently derived sparse-row support;
- each support edge appears exactly once;
- each component is contiguous and closes to its own start before a new component begins;
- component starts/order are canonical and deterministic;
- each step is backed by the exact published adjacency/transport/lift;
- composition over all components equals the independently expected row transport/turning lift.

Add a positive synthetic atlas case whose boundary algebraic row has at least two closed successor components, and negative/tamper cases that prove an open component, duplicate origin/support, non-canonical component ordering or invalid adjacency is rejected. At least one positive control must prove the old single-component case retains the same canonical sequence.

The production S5 focus in `tests/FieldAlignedCurveNetworkTests.cpp` is frozen and may not be edited in CB16.

## 5. Allowed / forbidden files

**Allowed semantic files only:**

- `src/authority/FieldTransportAtlas.cpp`
- `tests/FieldTransportAtlasTests.cpp`

Documentation/report/control-plane files required by normal turn mechanics are separately allowed. If implementation requires a public header/schema change, `src/geometry/MeshTopology.cpp`, fixture/rawfield mutation, `tests/FieldAlignedCurveNetworkTests.cpp`, CMake/benchmark change, or selector mutation, **STOP and return to Review** rather than broadening this plan.

Explicitly forbidden:

- changing `dual_cycles` or any sparse cycle coefficient/support to make row14 look single-component;
- changing exact-lift or singularity arithmetic;
- editing the genus-two OBJ/rawfield/metadata;
- weakening/removing the S5 focus assertion or precondition;
- changing selector426 or publishing selector427;
- local build or any generated Directional runtime, test, benchmark, discovery/list/help/version/CTest invocation.

## 6. Compile/package gate

Compile only through `.github/workflows/agent-compile-reusable.yml`, Release/static/Ninja/PRE_TEST with mandatory GMP/GMPXX, using the standard eight targets:

1. `directional_core`
2. `directional_pipeline`
3. `directional_surface_cell_authority_kernel_tests`
4. `directional_surface_cell_producer_tests`
5. `directional_surface_cell_completion_tests`
6. `directional_surface_cell_validation_tests`
7. `directional_compiled_api_tests`
8. `directional_benchmarks`

Require zero preflight/configure/build exits, authoritative GMPXX+GMP link evidence, clean source-status snapshots, recursive package manifest verification, preserved executable mode, exact frozen selector426/fixture hashes and `runtimeExecution=false`. A compile-green package is only a candidate; it does not promote runtime authority.

## 7. Falsifiers and stop rules

STOP CB16 without semantic expansion if any of the following occurs:

- an existing single-component row's canonical ordered step sequence changes;
- a support edge is omitted, duplicated or consumed twice;
- an open/non-closing component is accepted;
- duplicate outgoing origins or directed-adjacency mismatch become accepted;
- row14 is made acceptable by modifying `dual_cycles`, row coefficients, cycle kind, turning lift, raw field or fixture rather than by representing all valid support;
- the independent validator merely copies production ordering instead of deriving support/component closure independently;
- the S5 focus, selector426, CMake/benchmark semantics or frozen fixture bytes change;
- selector427 appears;
- generated Directional runtime executes in Code + Build;
- the mandatory GMP/GMPXX eight-target compile/package gate is not clean.

## 8. Handoff on a valid compile

A valid CB16 closeout may route to a separately frozen artifact-only retry of the unchanged S5 focus plus the new direct component-ordering controls. Runtime remains unauthorized inside this plan. Clearing row14 ordering is not itself S5 credit: if runtime reaches a later semantic failure, that later boundary becomes the next Review subject; if it reaches A3, mandatory Review still precedes any S5/selector publication.
