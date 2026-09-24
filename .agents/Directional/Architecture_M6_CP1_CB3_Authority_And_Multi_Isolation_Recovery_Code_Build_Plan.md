# M6-CP1-CB3 Authority and Multi-Isolation Recovery Code + Build Plan

**Turn:** `M6-CP1-CB3`
**Type:** Code + Build, runtime-free
**Predecessor:** `M6-CP1-TB2-REV`
**Accepted runtime authority:** `10814505512 / e284fea7c101eb86650d1c87c92d0fefa66050e7`, selector449 **449/449 PASS**
**Recovery candidate basis:** `10834642074 / 724316a5b3f49e33dc8e649989bb413b3dc6b7c9`
**If compile-green successor:** `M6-CP1-TB3-EXEC`, then mandatory `M6-CP1-TB3-REV`

## Goal

Produce the smallest runtime-free CP1 correction that addresses exactly the two Review-owned TB2 surfaces without changing the frozen M6 product contract:

1. restore the accepted HardRail-specific rejection precedence for explicit reciprocal rail-ID mismatch while preserving A5 fail-closed relation ownership; and
2. restore genuine cross-sheet quotient-lineage consumption for the retained split-isolation mechanism witness by correcting the first proved production-authority loss in the A5 occurrence/relation -> transitional quotient -> lineage path.

Do not extract A6/A7, publish a selector, or fold unrelated work into this recovery.

## Scope A — HardRail validation precedence

`M6-CP1-TB2-REV-CAND-01` is a stable accepted-prefix event. The negative `HardRailPairExplicitRailIdMismatchRejectsStrictTransport` deliberately gives a reciprocal HardRail pair two distinct explicit `HardRailId` values. New A5 currently rejects it first as generic `UnownedRelation`, shadowing the established downstream `InvalidHardRailTransport` contract.

Required properties:

- the mismatched pair remains rejected; no permissive fallback is allowed;
- A5 remains fail-closed and may not publish an owned HardRail relation with inconsistent owner IDs;
- the external accepted failure remains `InvalidHardRailTransport` for this exact semantic mismatch;
- prefer one typed/specific ownership error or an equivalent single-authority mapping that preserves the downstream contract; do not duplicate two independent validators that can drift;
- preserve every other A5 relation failure and all valid HardRail/ordinary/periodic behavior;
- do not edit, broaden, or remove selector row140 or any related negative test.

**Falsifier:** if restoring the specific failure would require accepting an invalid A5 relation, bypassing A5 ownership, or maintaining two contradictory semantic authorities, stop and return to Review rather than patching around the contract.

## Scope B — multi-isolation quotient-lineage mechanism

`M6-CP1-TB2-REV-CAND-02` is non-stable but gating. The split-isolation producer publishes a checked certificate joining distinct sheets, while materialization succeeds with no lineage containing both sheet IDs. The old `consumedInternalIsolationSeams` count is certificate inventory size and is not proof of quotient consumption.

Before editing semantic code, statically trace and record for the split-isolation fixture:

1. the four A5 occurrence IDs per participating cell and each occurrence's typed `IsolationSheetId`;
2. the A5 owned relation endpoint pairs spanning the certified isolation seam;
3. the union/quotient member set created from those endpoint pairs;
4. the `isolationSheets` set written into the resulting `PureQuadVertexLineage`.

Correct **the first locus** where valid distinct-sheet authority fails to propagate. Preserve these invariants:

- only a verified A5 owned relation may equate occurrences;
- equal world position, lattice coordinate, support, or chart is never merge authority;
- exact source support stays consistent within every quotient class;
- A5 still assigns one typed sheet to each occurrence; do not silently redefine frozen occurrence identity/authority;
- final lineage sheet lists remain sorted, unique, and derived from actual quotient members;
- no certificate-count diagnostic may be substituted for actual lineage consumption.

**Stop rule:** if the trace shows the frozen A5 product cannot represent the necessary cross-sheet relation without changing the normative occurrence-sheet/owner contract, make no speculative semantic change. Record the contradiction and return to Review/Definition.

## Frozen validation source

Do not modify tests, fixtures, selector449, routing449, or the six focused identities. Preserve exact hashes:

- selector449: `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`, exactly 449 LF rows;
- routing449: `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707`.

The six focused identities remain, in exact TB order:

1. `M6CP1.SurfaceOccurrenceComplexPublishesFourSemanticCornersPerCell`
2. `M6CP1.SourceFaceRowPermutationPreservesOccurrenceIdentity`
3. `M6CP1.SurfaceOccurrenceComplexRejectsMalformedMissingAndDuplicateRelationEndpoints`
4. `M6CP1.CoincidentUnrelatedOccurrencesRemainDistinct`
5. `SurfaceCellTransitionQuotient.MultiIsolationMaterializationRetainsAllLocalSheets`
6. `M5CP3.ProducedTorusPeriodicPairStorageSwapPreservesSemanticDirection`

Re-run the whole-tree by-value accessor split-range static scan and require it to remain clean. No benchmark semantic adaptation is authorized.

## Compile/package gate

After the smallest semantic patch is complete, compile/package exactly the standard eight targets through mandatory `.github/workflows/agent-compile-reusable.yml`:

- `directional_core`
- `directional_pipeline`
- `directional_surface_cell_authority_kernel_tests`
- `directional_surface_cell_producer_tests`
- `directional_surface_cell_completion_tests`
- `directional_surface_cell_validation_tests`
- `directional_compiled_api_tests`
- `directional_benchmarks`

Require `DIRECTIONAL_ENABLE_GMP=ON`, verified `gmpxx` + `gmp` linkage, `exactArithmeticBackend=GMP`, clean source receipts, complete recursive package manifest, and `runtimeExecution=false`. Code + Build may perform static/compile-time checks only; it must not run Directional tests, benchmarks, discovery, help/version binaries, or generated runtime.

## TB3 pre-registration

If compile/package is green, `M6-CP1-TB3-EXEC` consumes that exact artifact immutably and reruns the unchanged **six focused + selector449 = 455 fresh exact-filter processes**, in the same order, benchmark count 0.

Recovery-green shape is **6/6 focused + 449/449 selector = 455/455 PASS**, exact-one selected and zero skipped per process, with immutable postflight exact. In particular:

- no `OccurrenceInvalidCornerAuthority` anywhere;
- row140 must reject with the accepted `InvalidHardRailTransport` contract;
- focused multi-isolation must publish at least one legitimate lineage spanning >1 isolation sheet with equivalence evidence;
- pair-swap remains PASS.

Any mechanically valid RED is preserved and sent to mandatory `M6-CP1-TB3-REV`; do not repair/rerun it inside TB3. No candidate promotion, CP1 closure, stable-event recovery, or debt credit is granted by CB3 alone.
