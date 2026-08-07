# Surface-Cell Backend Remediation Plan

## Production objective

Produce deterministic direct source-authoritative cross-field-aligned pure-quad meshes for arbitrary triangle meshes. Fallback, recovery, synthetic topology repair, fixture-specific bypass, and validator relaxation cannot satisfy acceptance.

## Gate status

- G0 truthful authority — passed.
- G1 uniform phase-front plane — passed.
- G2 cross-chart and close-sheet propagation — active.
- G3–G7 — blocked as principal objectives.

## Current G2 source state

Source commit `21f081b330418a0f34709f61d857f54a03d2fd48` adds:

- trace and lattice source-chart identity;
- exact transition source-edge provenance;
- per-face branch rotation;
- reciprocal quarter-turn transition validation;
- deterministic chart construction for the first planar multi-face slice;
- transition/chart hashing;
- mandatory bunny and vase direct fixtures using generated smooth cross fields;
- fixture topology assertions preventing synthetic simplification.

The compile artifact SHA-256 is `f5c2be0e2131dbce7a6460e3c61da2de57f7d256c00a5401ac6285d6a0145755`. No runtime success is claimed yet.

## Mandatory remediation evidence

The direct matrix is plane, seam, close sheets, cylinder, bunny, and vase. All require `SurfaceCells`, fallback `Fail`, no recovery, non-empty pure-quads, `CompletedSurfaceCells`, strict validation, and determinism.

Bunny and vase must remain in mandatory coverage even when they expose blocked later contracts. Their failures guide general implementation; they are never removed, simplified, or special-cased to improve pass counts.

## Next boundary

Execute the artifact-only plan. Gate 2 material progress requires seam success or nonzero deterministic cross-chart authoritative cells reaching a first-class transport/materialization boundary. Close sheets must show zero positional capture.

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
