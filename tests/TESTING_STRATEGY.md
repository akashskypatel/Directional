# Surface-Cell Testing Strategy

## Mandatory direct matrix

Run in order: plane, multi-face seam, close sheets, cylinder, randomized `bunny_1k_random`, vase. Run all six even after failure when the active turn budget permits a bounded execution; later fixtures cannot pass an earlier gate. A bounded timeout is failure only and does not synthesize a result.

Every direct success requires requested/executed `SurfaceCells`, fallback `Fail`, no fallback attempt, recovery disabled, non-empty pure quads, `CompletedSurfaceCells`, complete source provenance, strict validation, and deterministic output.

Topology/singularity gate fixtures such as torus and prescribed sphere are run additionally when their gate is active. They do not replace the production matrix above.

## Fixture integrity

- bunny SHA-256 `865d864f7afbd90283526d914e0d4d9718d83e9679943029060bde439b10ab05`: 502 vertices, 1,000 triangles, closed, one component;
- vase SHA-256 `5f7bedc1783486589a8721a7b9be881064f361e4a07fd8c5278d8b8f55b2c868`: 1,274 vertices, 2,404 triangles, one boundary loop and 142 boundary edges.

Both use generated smooth fields through production extraction. Replacing, simplifying, bypassing, or special-casing either fixture is prohibited.

## Current runtime authority

Exact artifact **`9021175280`**, implementation `085db9ec23ffaa509b1f5a29e72968229efa103d`.

G0-G3 remain passed:

- retained G0-G3 focused contracts **17/17**;
- plane `Produced / CompletedSurfaceCells`, 64 pure quads / 81 V, hash `730caeae49ec872c`, deterministic 3/3;
- seam `Produced / CompletedSurfaceCells`, 64 pure quads / 81 V, hash `5bdf34d7802e9fb0`, deterministic 3/3;
- close sheets `Produced / CompletedSurfaceCells`, 200 pure quads / 242 V / two components, hash `89b052762f52a5af`, deterministic 3/3;
- cylinder `Produced / CompletedSurfaceCells`, periodic `r=0`, `t=(32,0)`, route 32, cut 4, 288 pure quads / 320 V, zero validation failures, exactly two genuine exterior 32-edge loops, hash `32135be51d7a0a26`, deterministic 3/3;
- no passing direct case uses fallback or source-grid recovery.

G4 focused authority:

- generalized polygonal boundary-phase semantics **5/5**;
- source-sheet/isolation semantics **3/3**;
- retained non-torus curved-disk semantics **5/5**;
- sheet coverage **3/3**;
- G4 periodic-relation semantics **5/5**;
- strengthened exact-torus advancement currently fails because torus reaches `InvalidBoundedDiskBoundaryTurn` before any first-class phase record is retained.

Bounded suites: producer **119/121**, completion/simplification **154/164**, validation **60/60**, compiled API **8/8**.

Detailed runtime authority: `.agents/Directional/Gate_4_Closed_Genus_One_Field_Authoritative_Polygonal_Disk_Boundary_Phase_Artifact_Only_Test_Benchmark_Report.md`.

## Producer-authority contracts

The source distinguishes:

```text
NotApplicable
Produced
Rejected
```

Mandatory behavior:

- applicable valid source regions may reach `Produced`;
- applicable invalid metadata reaches `Rejected`, not `NotApplicable`;
- `Rejected` generates no generic substitute work and remains terminal for the requested backend;
- typed rejection remains first-invalid authority;
- non-embedded relief guidance does not veto transport;
- embedded relief barriers block according to the existing relief contract;
- ordinary shared-edge and ordered source-vertex fan transport remain covered;
- reversed face ordering preserves structural results;
- malformed/duplicate/nonreciprocal transition data fails closed;
- source component, topology-region, and local isolation-sheet identity prevent unrelated capture;
- one accepted authoritative cell maps to exactly one quad;
- periodic source identity, field-authoritative correspondence, canonical source-simplex endpoints, exact quotient and artificial-cut non-exterior behavior remain regressions.

Producer disposition and typed rejection identity must be present in deterministic diagnostic/structural evidence.

## Topology-region versus local isolation-sheet contract

Tests must distinguish two kinds of authority:

### Producer topology region

A topology region is connected only through exact source adjacency and is split by genuine source boundaries, hard features, embedded hard barriers, or equivalent explicit source-topological constraints. Euler characteristic, boundary-loop classification, disk/annulus applicability, region ownership and exact-once producer coverage are evaluated on this region.

### Local isolation sheet

A local isolation sheet protects geometric operations from nearby unrelated surface capture/projection. Close/opposing-sheet classification may split one topology region into several local labels.

A non-hard edge whose exact source-adjacent incident faces have different local labels is **not automatically an exterior boundary**. It may be an internal isolation seam only if exact source adjacency and reciprocal field transition authority are valid. Proximity alone never establishes continuity.

Required regressions include:

- a natural annulus split into multiple local isolation labels but preserved as one source-topological producer region;
- face-row invariance of region/seam identity;
- exact reciprocal transport across a valid internal isolation seam;
- typed failure for malformed/nonreciprocal internal seam transport;
- hard-feature boundaries remain topology boundaries;
- spatially close but source-disconnected sheets/components remain isolated;
- exact-once aggregation across regions while preserving local-sheet provenance.

Do not union local labels by counts, IDs, frequency, discovery order, topology score, boundary length, proximity, or arbitrary subset search.

## G4 polygonal boundary-phase contract

The generalized boundary representation is runtime-valid on structural witnesses.

Required tests retain:

- established rectangular curved disk follows the exact fast path;
- a natural non-rectangular orthogonal/reflex-corner disk constructs ordered source-attached transported runs and a deterministic polygonal chart without run coercion;
- invalid reciprocal turn fails typed `InvalidBoundedDiskBoundaryTurn`;
- cyclic field-index inconsistency fails typed;
- face-row re-enumeration preserves structural phase identity;
- source boundary and hard-feature provenance remain exact;
- mixed periodic/polygonal composition retains periodic authority without partial aggregate cells.

Do not infer correctness from a changed error name. Material progress on a real gate fixture requires diagnostics/hashes showing the intended first-class state was actually constructed and consumed.

Exact torus under artifact `9021175280` currently reports `InvalidBoundedDiskBoundaryTurn` with phase/run/polygon/chart counts all zero. Read-only structural diagnosis shows this is caused by treating a local isolation seam as an exterior disk rail. Boundary-turn/index thresholds must not be relaxed to hide that upstream partition error.

The next Code + Build test additions are governed by `.agents/Directional/Gate_4_Source_Topology_Region_Isolation_Sheet_Decoupling_Code_Build_Plan.md`.

## G3 periodic invariant

Periodic relation authority is first-class:

- source-topology/reciprocal-transport identity;
- canonical equivalent/reversed representation;
- field-authoritative correspondence rather than ID/order/proximity choice;
- typed fail-closed conflict/ambiguity;
- every retained relation consumed by hashing, diagnostics, provenance and exact quotient materialization;
- single-annulus cylinder behavior retained exactly.

The artificial periodic cut is never an exterior output seam. No Euclidean seam welding is permitted.

## Contract tests versus production authority

Narrow synthetic/reconstructed fixtures isolate invariants but are not acceptance authority for the real pipeline. Exact committed fixture tests must enter the production preprocessing/remesh path and must not inject convenient topology-region unions, labels, transitions, target counts, or output cardinalities.

Tests must verify semantic source/topology/transport identities instead of raw DCEL/source numeric IDs or historical discovery order. Diagnostic torus vertex IDs, local-sheet counts, feature counts, relation counts, analytical fixture parameters and observed boundary lengths may not become test or production success keys.

## Default suites

Report direct acceptance separately. Explicitly executed focused/direct tests must be excluded from remaining aggregate totals so counts are non-overlapping. Run completion, validation, and compiled API suites after the direct gate decision. Scheduler-sensitive wall-clock ratios are benchmark/closeout evidence only and cannot override semantic gate authority.

Current bounded baseline from artifact `9021175280`:

- producer **119/121**; failures are the existing sub-millisecond `StrictValidatorOverheadStaysBelowFivePercent` threshold and the strengthened exact-torus advancement contract;
- completion/simplification **154/164**, unchanged historical ten failures;
- validation **60/60**;
- compiled API **8/8**;
- aggregate **341/353**.

## Turn boundaries

Code + Build may edit active-gate implementation and valid producer-level regression tests and compile approved targets, but executes no generated project binary. GitHub workflow compilation is permitted under the workflow policy. Test + Benchmark uses one exact immutable artifact and performs no rebuild or source/test/fixture/validator edit. Review turns do not edit production source/tests.

## Validity and prohibitions

Tests must encode real production contracts and valid scenarios. Never weaken assertions to fit behavior. No validator weakening, fixture special cases, fallback/recovery substitution, generic-producer substitution after authoritative rejection, positional sheet merging, count/order/frequency ownership selection, arbitrary subset search, synthetic topology correction, Euclidean periodic seam welding, post-hoc cell merging, or timeout-as-correctness.