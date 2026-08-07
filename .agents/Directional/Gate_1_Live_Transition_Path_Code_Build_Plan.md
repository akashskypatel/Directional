# Gate 1 Live Transition Path — Code + Build Plan

## Turn declaration

```text
Active design gate: Gate 1 — uniform phase-front plane regression restoration
Earliest failing fixture: plane__surface_cells
Missing design contract: complete zero-turn prescribed-field metadata must be consumed by the uniform planar phase-front segment route, including exact source-topology handling when a lattice segment meets a source vertex
Smallest general implementation change: expose the first phase-front rejection predicate, then replace the confirmed invalid consecutive-segment transition assumption with an ordered authoritative source-topology transition; preserve strict reciprocal edge-transition validation
Observable material-progress condition: the phase-front rejection contract is live and consumed, and the next artifact restores the prior direct 64-quad/81-vertex plane result or an equivalently valid deterministic direct result while retaining the seam's 64 direct quads
Explicitly deferred work: close sheets, cylinder holonomy, bunny/vase completion, validator timing, fallback/recovery, and historical completion cleanup
```

## Boundary

This is a Code + Build turn.

- Do not execute generated project binaries, tests, benchmarks, discovery, CLI, GUI, help, or list commands.
- Compile only the approved seven targets under the existing Release static `PRE_TEST` configuration.
- Do not modify fixtures, manifests, validators, fallback policy, recovery behavior, or unrelated completion code.
- Preserve the seam as a mandatory regression and keep PR #8 open, draft, and unmerged.

## Proven starting point

- exact tested source: `a90f6b9de83dba4aeac359b2f63d735e2049b54e`;
- tested artifact SHA-256: `c516af42f6aa388ef219408ef63e939490176385e976885f1ea9176ec3609e20`;
- plane: deterministic unchanged 106/9/12 generic completion failure;
- seam: deterministic direct 64-quad pass, hash `a8972efd7c4900a4`;
- evidence SHA-256: `57e2f247dbf1cb7ad4c2470f30fa8ec7705b888ec891515ce61b76c329cd2591`.

## Required source proof before editing

1. Compare the successful Gate 1 parent `aea10409c73c490b92f78760b73191641ef823c6` with the tested source.
2. Trace the complete prescribed-field route:
   `finalize_surface_cell_raw_cross_field` → populated matching/effort/transitions → `build_surface_cell_network` → `build_uniform_phase_front` → `segment_on_source`.
3. Enumerate every Boolean rejection introduced by Gate 2 in deterministic execution order.
4. Introduce a typed `SurfacePhaseFrontFailure` result with the first failing predicate, source face/edge/vertex context where applicable, and no counter synthesis.
5. Propagate that typed result into existing tracing/pipeline diagnostics without changing success or validation semantics.

Diagnostics alone do not complete the turn. They must be used to select and implement the bounded producer correction below.

## Bounded producer correction

The current leading candidate is a lattice segment passing through a source vertex, where consecutive selected intervals can meet at the vertex without sharing one edge. Confirm this against the exact committed plane fixture and metadata before applying the correction.

When confirmed:

1. Classify consecutive segment attachment as either:
   - ordinary shared-edge crossing; or
   - exact shared-vertex crossing.
2. Keep the existing shared-edge path unchanged and strict.
3. For a shared-vertex crossing, derive the unique ordered incident-face fan from source topology and segment direction.
4. Traverse every fan edge in order and apply each authoritative transition using `resolve_branch_transition`.
5. Require reciprocal transport, matching/effort/topology consistency, and final family/sign agreement.
6. Record every crossed canonical source-edge index in route provenance; do not collapse the fan to a positional jump.
7. Reject ambiguous, non-manifold, disconnected, repeated, or non-unique fans fail-closed.
8. Preserve exact chart/component/local-sheet ownership and one-cell-to-one-quad materialization.

If the typed first rejection is not the vertex-transition candidate, do not add speculative fan logic. Repair only the confirmed first general predicate and document the evidence.

## Targeted tests to add or strengthen

Tests must exercise contracts, not fixture identities:

- uniform planar zero-turn metadata across ordinary interior edges;
- uniform planar zero-turn metadata through a source vertex;
- reciprocal quarter-turn seam transport remains exact;
- reversed face/edge ordering produces the same structural result;
- malformed, missing, duplicate, nonreciprocal, or ambiguous fan metadata fails closed;
- source-sheet/component identity prevents unrelated face capture;
- one accepted phase-front cell maps to exactly one quad.

Do not weaken existing tests or change expected acceptance to match failure.

## Compile-only verification

Compile exactly:

1. `directional_core`
2. `directional_pipeline`
3. `directional_compiled_api_tests`
4. `directional_surface_cell_producer_tests`
5. `directional_surface_cell_completion_tests`
6. `directional_surface_cell_validation_tests`
7. `directional_benchmarks`

Package five executables, two project static libraries, all 27 fixture/input files, exact source, compile database, logs, authority metadata, and recursive checksums. Execute none of them.

## Exit conditions

A completed turn must provide:

- exact source commit and final changed-file blobs;
- compile success for all seven targets;
- a fresh immutable artifact and SHA-256;
- a Code + Build report describing the confirmed first rejection and general repair;
- an artifact-only plane-first Test + Benchmark plan;
- updated design, TODO, milestone, handoff, runtime authority, and PR metadata;
- cleanup of bounded workflows, triggers, payloads, stale reports, and stale results;
- a new top-level PR #8 comment as the final repository write.

If this second Code + Build attempt does not materially advance Gate 1 in the following artifact-only turn, the mandatory next turn is a design review or bounded producer replacement proof, not another local repair attempt.
