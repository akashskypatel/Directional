# Gate 1 Regression Restoration While Preserving Gate 2 Seam — Code + Build Plan

## Required opening declaration

```text
Active design gate: Gate 1 regression restoration
Earliest failing fixture: plane__surface_cells
Missing design contract: authoritative uniform phase-front activation must remain valid for a constant prescribed field after exact chart-transition transport was added
Smallest general implementation change: repair fail-closed branch/route transport for zero-turn prescribed-field transitions while preserving reciprocal quarter-turn seam transport
Observable material-progress condition: plane and multi-face seam both compile against the same authoritative phase-front path, with no legacy completion substitution
Explicitly deferred work: close-sheet completion, periodic cylinder holonomy, bunny/vase production completion, performance, historical completion failures, and timing-ratio work
```

## Evidence boundary

Use the artifact-only report and runtime summary. Do not reinterpret the seam pass as permission to leave the plane regression.

Current signatures:

- plane: 106 traces, 9 arrangement cells, 12 completion quads, 15 validation failures, `AggregateCompletionValidationFailure`;
- seam: 256 traces, 65 arrangement cells, 64 direct quads, deterministic output hash `a8972efd7c4900a4`.

This indicates seam chart transport is live while the constant prescribed-field plane falls back to the legacy trace/completion path.

## Implementation direction

1. Locate the exact fail-closed exit in `build_uniform_phase_front` for the plane using bounded typed failure state or temporary local instrumentation.
2. Keep the result tied to a general contract; diagnostics alone are not material progress.
3. Canonicalize branch transport by physical directed lattice direction and reciprocal source-edge transition, not arbitrary per-face branch labels.
4. Accept a zero-turn constant prescribed field across triangulation edges when forward and reverse transport are exact and reciprocal.
5. Preserve quarter-turn chart changes that make `multi_face_seam` pass.
6. Preserve exact source face, transition edge, component, sheet, family/sign, phase, integer lattice coordinate, and route provenance.
7. Fail closed on missing, duplicate, non-adjacent, non-reciprocal, or physically inconsistent transitions.
8. Preserve source-normal winding and one authoritative cell → one output quad materialization.
9. Do not route plane through generic strands/arrangement/completion as a substitute for authoritative phase-front success.
10. Do not branch on fixture name, path, ID, mesh dimensions, counts, or expected hashes.

## Required code-validity coverage

Compile the approved seven targets only:

- `directional_surface_cell_producer_tests`
- `directional_surface_cell_completion_tests`
- `directional_surface_cell_validation_tests`
- `directional_compiled_api_tests`
- `directional_benchmarks`
- `directional_core`
- `directional_pipeline`

Use Release static `PRE_TEST`. Execute no generated binary, test, benchmark, discovery, CLI, GUI, help, or list command.

## Exit criteria

- exact source patch committed and verified;
- all seven targets compile/link;
- no runtime claim in the Code + Build turn;
- plane and seam mandatory tests remain unchanged and compiled;
- no validator weakening, fallback/recovery, fixture special case, positional merge, count/order/frequency selection, arbitrary subset search, or post-hoc cell repair;
- next turn is artifact-only direct testing of plane first, seam second, then the full six-fixture matrix.
