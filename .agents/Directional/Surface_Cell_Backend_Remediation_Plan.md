# Surface-Cell Backend Remediation Plan

## Production objective

Produce deterministic, direct, source-authoritative cross-field-aligned quad meshes for arbitrary triangle meshes. Production success must come directly from the requested `SurfaceCells` backend. Fallback, source-grid recovery, synthetic topology repair, or validator relaxation cannot satisfy acceptance.

## Gate policy

Remediation follows the ordered design gates in `.agents/Directional/DESIGN.md`. Only the earliest incomplete gate may be the principal implementation objective.

- G0 truthful authority — passed.
- G1 uniform phase-front plane — **active**.
- G2 cross-chart and close-sheet propagation — blocked.
- G3 periodic closure and holonomy — blocked.
- G4 topology-distinct completion and singularities — blocked.
- G5 adaptive scale and hard features — blocked.
- G6 general production geometry — blocked.
- G7 operational hardening — blocked.

## Current G1 state

Implemented and compile-valid:

- first-class lattice phase and integer coordinates;
- directed front ownership and typed events;
- bounded planar uniform phase-front production;
- source-attached corners and ordered side routes;
- compatible interior merges and exterior termination;
- deterministic phase-front hashes/accounting;
- authoritative proposal-cycle arrangement materialization without fan-sector inference.

Artifact-only runtime evidence:

- plane: 352 traces, 65 arrangement cells, 409 completed quads;
- first invalid record: `completion/output-validation:FlippedFace`, cell 38, source face 41;
- validation failures: 100;
- structural stage hashes and counts stable across three processes;
- seam, close sheets, and cylinder remain at zero-cell `SideSubdivisionRepair:InvalidInputIncidence` and are blocked by the plane gate.

The phase-front architecture is live. The current remediation target is not another tracing or fan-interval adjustment. It is an authoritative orientation/incidence contract and direct one-to-one cell materialization.

## Required G1 remediation

### 1. Authoritative cell orientation

For every phase-front cell, validate before arrangement/completion:

- exactly four distinct source-attached corners;
- ordered side endpoint continuity;
- nonzero intrinsic signed area;
- winding consistent with the authoritative source normal;
- coherent component, source chart, and local-sheet identity;
- coherent route provenance and family/sign state;
- exactly one filled side or explicit exterior classification per directed front edge.

When winding is opposite, reverse the entire cycle transactionally: corner order, lattice states, side routes, edge directions, family/sign state, and ownership. Do not reorder using positional proximity or index heuristics.

### 2. Direct cell materialization

An accepted four-sided phase-front cell already defines topology. Materialize it as one intended quad-domain cell.

Arrangement may:

- canonicalize equivalent source identities;
- split exact crossings;
- materialize halfedges/twins/next links;
- validate provenance and topology.

Arrangement/completion must not:

- choose connectivity through fan-sector interval ranking;
- merge unrelated sheets by position;
- expand one accepted four-sided cell through generic patch completion;
- decompose or merge cycles post hoc to obtain a desired count.

### 3. Fail-closed boundary

Reject the cell before completion when orientation, incidence, route, component, sheet, or ownership is inconsistent. Preserve the first invalid producer record and deterministic state hashes.

### 4. Test correction

Correct two obsolete producer expectations:

- scaffold diagnostics must not assume production failure;
- recovery coverage must use a true recovery-required input or separate direct-success and recovery-only assertions.

The four direct acceptance tests remain unchanged in strength.

## Next compile gate

Use `.agents/Directional/Gate_1_Phase_Front_Orientation_Code_Build_Plan.md`. Compile the approved seven targets only. Do not execute generated binaries, tests, benchmarks, discovery, CLI, GUI, or help/list commands.

## Material progress

Progress requires plane success or a structurally later failure with one-to-one cell materialization and a reduced invalid-output burden. New diagnostics, counters, hashes, or unrelated test passes are insufficient.

## Layered source authority during outage

The tested implementation is base `e82fb47dccbefa1b878bc9ddff0ae63745f6efe9` plus exact patch blob `aa18d454877ccf40d16f71f173fdaf765f5f1086`. Keep its five-file synchronization on both TODO files until service recovery.

While the outage persists:

1. do not use workflows for source application, build, or repository updates;
2. reconstruct the tested source exactly from base plus the existing patch;
3. express the orientation/direct-cell change as a separate incremental patch;
4. record its digest, expected output blobs, local build artifact, and logs;
5. keep both patch layers versioned and ordered.

After recovery, apply and verify the existing patch first, then the orientation/direct-cell patch as a second coherent commit. Remove each payload only after its corresponding source commit and expected blobs are verified.

## Preserved prohibitions

- no validator weakening;
- no count/order/frequency ownership selection;
- no arbitrary subset search;
- no fallback/recovery substitution;
- no synthetic counters or Euler correction;
- no positional merging across unrelated sheets;
- no fixture/ID special cases;
- no post-hoc cycle decomposition or cell merging;
- no timeout-as-correctness.
