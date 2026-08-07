# Surface Cell Backend Remediation Plan

## Current blocker

The Gate 1 restoration implementation and compile are complete, but runtime authority is still the prior artifact where the plane regressed and the seam passed. The earliest blocker remains Gate 1 until the new artifact proves plane success without losing the seam.

## Remediation sequence

1. Artifact-only test plane, then seam, from the exact restoration build.
2. Accept restoration only when both direct contracts pass without generic completion, fallback, recovery, or validator changes.
3. Continue the full mandatory matrix and default suites.
4. Resume close-sheet isolation only after plane and seam both pass.
5. Continue cylinder, topology, adaptivity/features, bunny/vase success, and operational hardening in gate order.

## Acceptance discipline

Every success requires direct `SurfaceCells`, fallback `Fail`, no fallback attempt, recovery disabled, non-empty pure quads, `CompletedSurfaceCells`, complete provenance, strict validation, and deterministic hashes.

The historical completion failures and scheduler-sensitive validator timing ratio are not the active constructive blocker.
