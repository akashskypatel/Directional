# Milestone G P5 — Mixed-Sheet Identity and Pipeline Liveness Code + Build Plan

**Next turn:** P5-CB75 through P5-CB82 code changes + compile-only build  
**Input artifact:** P5-TB14 artifact `8864496877`  
**Exact tested source:** `188baf35a13c02b20424cd72fb9c6d8fe81ec9fc`  
**Review policy:** `never`

## Objective

Correct the committed subdivision's mixed-sheet identity, restore truthful rollback and exact product reuse, finish rail propagation and valid Milestone D fixtures, eliminate in-pipeline bunny crashes and nonterminating simplification, and package a compile-only checkpoint without executing a binary.

This is a code changes + compile-only build turn. Compile only the four required targets.

## P5-CB75 — Preserve exact sheet identity through successful subdivision

P5-TB14's only completed bunny process fails with:

```text
SuccessfulSubdivisionDomainIdentity;
identityFailure=mixed-source-sheet;
cell=19;
halfedge=52893;
sourceFace=794;
component=0;
sheet=9
```

Correct the producer at the successful subdivision boundary.

Requirements:

- Treat a source occurrence as the exact tuple `(sourceFace, barycentric, component, sheet, provenance interval)`.
- An inserted node may own multiple valid occurrences, but each oriented replacement halfedge must select occurrences compatible with its incident source sheet and direction.
- Reconstruct twin halfedges independently from their respective incident sheets; do not copy one side's primary chart onto the other.
- Recompute each affected cell's source support from its oriented boundary halfedges and require one exact component/sheet identity.
- Preserve rail, curve, proposal, family, hard-feature, and complete provenance identity during subdivision.
- Audit the full committed transaction before descriptor derivation and reject atomically if any cell is mixed.
- Do not choose charts by Euclidean proximity, discard sheet labels, pair source triangles, or special-case cell/halfedge IDs.

Regression sources must cover a close-sheet or two-sheet shared source-edge case with successful coupled insertions and require order-invariant exact identities under face-row, halfedge, and cell reordering.

## P5-CB76 — Make rollback proof structurally exact

`PermittedSideRepairFailureReturnsExactRollbackForGeneralCompletion` reports rollback equivalence while the structural hash changes.

Requirements:

- Inventory every field mutated by tentative coupled insertion: node occurrences, positions, halfedges, twins, next links, cell boundaries, source support, rail/provenance payloads, hard barriers, diagnostics, and ownership metadata.
- Restore all mutated fields before setting `rollbackEquivalent`.
- Compute before/after exact structural hashes only after rollback is complete.
- Keep one committed complex plus a compact undo log; do not retain a second full complex.
- Expose undo-log owned bytes separately from current structural bytes.
- Fail closed if rollback cannot be proven.

The existing direct-subdivision test now reaches `MissingCommonSourceChart` instead of `InvalidMidpointEmbedding`. Correct its fixture so a valid common chart exists before injecting the intended invalid midpoint, or split the two failure contracts into separate tests. Do not merely change the expected string when the test no longer reaches its stated scenario.

## P5-CB77 — Produce positive exact reusable-product hits

The semantic index compiles, but both targeted tests still report zero reuse.

Requirements:

- Record product count, bucket hash, exact dependency identity, consumption state, and explicit mismatch field for every lookup.
- Build the semantic key only from canonical domain/boundary identity, source/rail support, component/sheet, logical sides/turns, backend, and variant.
- Exclude `cellId`, local patch ordering, compact allocation indices, and rebuilt container positions.
- Support multiple products per hash and exact collision-safe equality.
- Reuse each unaffected product exactly once and recompute each affected product exactly once.
- Do not move payloads out of unmatched products.
- Release superseded products after commit or rejection.

Restore positive reuse in:

- `WholeComplexParallelRouteRepairCompletesWithinOneGlobalLedger`;
- `OneCandidateBudgetIsExactAndDoesNotRecurse`.

## P5-CB78 — Finish authoritative rail propagation

Final arrangement halfedges still lose rail identity.

Audit all paths from embedded arc to final halfedge:

- arc subdivision;
- stitch canonicalization;
- halfedge creation;
- twin creation and orientation reversal;
- provenance expansion;
- compaction and intermediate release.

Each derived halfedge must retain:

- `railId` and `curveId`;
- normalized oriented `railT0`/`railT1`;
- boundary/hard-feature classification;
- component and sheet;
- complete canonical provenance;
- deterministic primary provenance interval.

Do not infer rail identity later from geometry.

## P5-CB79 — Rebuild valid Milestone D and production fixtures

The attempted Milestone D corrections remain invalid.

Construct the multi-edge interface fixtures from explicit DCEL primitives with:

- two interior cells;
- at least two shared canonical undirected halfedges;
- valid twins, next cycles, and cell incidence;
- deterministic source/component/sheet support;
- a separate protected rail;
- explicit topology and interface-size preconditions.

Construct the cylinder with:

- Euler characteristic `0`;
- one component;
- exactly two boundary loops;
- valid embedding/incidence;
- a genuine removable open strand that avoids boundaries, singularities, and protected support.

Also diagnose the four failing GP26 end-to-end fixtures and `SurfaceCellPipelinePhase20.CylinderFixtureCompletesProductionOutput`. Do not weaken output validation. Correct upstream assembly, optimization, or fixture construction according to the first truthful failing gate.

## P5-CB80 — Make simplification fixed-point live and deterministic

Phase 17 passes, but production runs range from `40.925049 s` to nontermination beyond `300 s`.

Implement a deterministic dependency-bounded frontier:

- assign every candidate a semantic identity and generation;
- invalidate candidates touched by committed nodes, halfedges, strands, cells, interfaces, or rails;
- suppress duplicate live candidates;
- discard stale generations before evaluation;
- recompute only the dependency neighborhood of a commit;
- require a monotone convergence measure or prove that every accepted edit removes a finite semantic candidate;
- report generated, deduplicated, invalidated, stale-discarded, evaluated, committed, and remaining counts per generation;
- retain bounded queue memory and release superseded candidate payloads.

A timeout, arbitrary iteration cap, disabled refresh, or production fixture special case is not an acceptable fix. Explicit diagnostic one-transaction mode may remain bounded, but default production mode must converge deterministically.

## P5-CB81 — Eliminate the in-pipeline bunny signal 11

All three bunny tests stop before their `AFTER_PIPELINE` marker, while the benchmark sometimes returns a fail-closed result. The fault is inside the pipeline.

Add stage and transaction markers around:

- simplification frontier generation/evaluation/commit;
- successful side-subdivision begin/commit/rollback;
- domain audit;
- descriptor derivation;
- product-cache lookup;
- completion assembly;
- intermediate release and context finalization.

Audit for:

- stale references into vectors changed by insertion or compaction;
- references to candidate/product payloads after move or erase;
- Eigen maps/spans/string views into temporary storage;
- invalidated iterators during candidate refresh;
- result/context members that alias stage-owned storage;
- destruction ordering between completion state, diagnostics, and recovery state.

Every public result and retained diagnostic must own its data. Do not catch, suppress, skip, or translate the signal.

Compile sanitizer-compatible code paths and deterministic markers, but execute no binary in this turn.

## P5-CB82 — Memory and compile-only gate

The completed P5-TB14 process reports about `21.60 MB` current structural state and `21.59 MB` rollback state. Verify the latter is compact undo ownership rather than a second complete complex.

Preserve:

- one committed complex;
- at most one mutable transaction;
- compact semantic product keys;
- deferred final output allocation;
- incremental release of descriptors, products, and stale candidates;
- truthful stage-owned byte diagnostics.

Compile only:

- `directional_core`;
- `directional_pipeline`;
- `directional_phase1_tests`;
- `directional_benchmarks`.

Use a clean optimized static Ninja build with shallow submodules. Package exact source, empty source status, both executables, both libraries, fixture closure, logs, recursive submodule state, and checksums.

Execute no test, benchmark, custom mesh, compiled binary, help/list command, or test discovery.

## Following artifact-only gates

P5-TB15 must require:

- all 13 P5-TB14 assertion-failing tests pass;
- all three signal-11 tests terminate normally alone and in the full binary;
- full packaged binary completes from an arbitrary path;
- four fresh random-bunny processes all terminate deterministically;
- successful subdivision has valid exact component/sheet identity and nonzero descriptors;
- real side-repair failure has exact rollback equality;
- unaffected products report positive exact reuse;
- nonempty pure-quad output has zero ownership conflicts and valid lineage/provenance;
- no fallback or recovery;
- wall `<= 39.228299 s` and peak RSS `<= 1,115,394,560 B` in every process;
- candidate-generation and owned-byte diagnostics reconcile liveness and process RSS.

P5 remains open until every gate passes without synthetic tests or prohibited recovery behavior.
