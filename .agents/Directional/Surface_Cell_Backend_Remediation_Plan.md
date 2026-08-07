# Surface Cell Backend Remediation Plan

## Current blocker

Gate 1 remains the earliest blocker. The exact plane is deterministic but still reaches 106 generic traces / 9 arrangement cells / 12 completion candidates / 15 validation failures instead of authoritative direct output. The seam remains direct and valid with 64 pure quads.

The mandatory architecture review selected **Outcome B — bounded producer replacement proof**.

## Proven architecture defect

`build_surface_cell_network()` currently attempts the uniform phase-front producer and, on any non-success, automatically launches the generic seed/trace/proposal producer. This collapses two different states:

- authoritative producer is genuinely not applicable;
- authoritative producer was applicable and rejected the input.

Later completion/output-validation diagnostics can overwrite the typed phase-front failure, which masks the authoritative boundary and preserves the misleading 106/9/12 downstream signature.

The exact production plane also consumes finalized transition metadata, adaptive target size, source labels, and feature/relief state that the narrow synthetic fan tests do not reproduce. A separate proven semantic mismatch exists where phase-front transport treats relief edges as hard barriers without honoring `reliefBarriersEmbedded`.

## Selected remediation

Implement a bounded first-class authoritative producer result:

```text
NotApplicable
Produced
Rejected
```

- `NotApplicable`: later explicitly selected producer may run.
- `Produced`: direct one-cell-to-one-quad materialization.
- `Rejected`: retain typed source-authoritative failure and stop; do not launch generic seeds/traces/proposals.

The producer inputs must include source topology, finalized cross field, production target size, component/sheet labels, feature constraints, relief state including embedded authority, and tracing/transport options.

Preserve ordinary shared-edge transport, ordered source-vertex fans, reciprocal quarter-turn seam transport, complete route provenance, sheet ownership, and source-normal orientation.

## Next sequence

1. Execute `.agents/Directional/Gate_1_Authoritative_Producer_Boundary_Code_Build_Plan.md`.
2. Add exact committed-plane production-route coverage before downstream stages.
3. Compile approved seven targets without executing generated project binaries.
4. Package immutable artifact.
5. Artifact-only test plane first, seam second, then all mandatory fixtures/default suites.
6. Gate 1 closes only with direct valid plane output and retained seam success.

Minimum architecture proof is disappearance of silent 106/9/12 substitution after an authoritative `Rejected` result. That is material progress but not Gate 1 closure.

## Acceptance discipline

Every direct success requires `SurfaceCells`, fallback `Fail`, no fallback attempt, recovery disabled, non-empty pure quads, `CompletedSurfaceCells`, complete provenance, strict validation, and deterministic hashes.

No validator weakening, fixture special cases, generic-producer substitution after rejection, fallback/recovery, positional sheet merging, arbitrary subset search, synthetic topology correction, or post-hoc cell merging is allowed.
