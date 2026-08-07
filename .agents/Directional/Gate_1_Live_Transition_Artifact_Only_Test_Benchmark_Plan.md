# Gate 1 Live Transition Path — Artifact-Only Test + Benchmark Plan

## Turn boundary

Use only `directional-g1-live-transition-local-build-artifact.zip`.

Do not configure, compile, relink, regenerate discovery, or edit source, tests, fixtures, manifests, build logic, validators, fallback policy, or recovery behavior.

## Artifact authority

- SHA-256: `922be37c4ee849152dee40168e3e8604357af46189d6491124b7b83dce7ca741`;
- internal checksums: 45/45;
- source commit: `364a20e12165af7dbfe213bb6d075e3fe25b1574`;
- payload cleanup: `591ada601843237a709d2d6e133a438ca403f042`;
- five executables, two project static libraries, 27 fixture/input files;
- changed source blobs must match the four values in the build report and packaged metadata.

## Required execution order

Run every direct case in a fresh bounded process and preserve every result:

1. plane — active Gate 1 gate;
2. multi-face seam — retained Gate 2 regression;
3. close sheets;
4. cylinder;
5. randomized `bunny_1k_random`;
6. vase.

All six execute even if an earlier fixture fails.

## Gate 1 acceptance

The plane must return direct `SurfaceCells` output with:

- fallback policy `Fail` and no fallback attempt;
- recovery disabled and unused;
- `CompletedSurfaceCells` output origin;
- non-empty pure quads;
- complete source provenance and strict validation;
- exactly one accepted authoritative four-sided cell per output quad;
- no 106-trace / 9-arrangement / 12-completion generic signature;
- deterministic structural and output hashes across three independent processes.

Capture the typed phase-front failure reason and context if the plane still fails. A typed diagnostic without constructive advancement is not acceptance.

## Seam regression acceptance

The seam must retain direct reciprocal quarter-turn transport with non-empty authoritative cells, 64 pure quads or an equivalently valid deterministic direct result, zero validation failures, no fallback/recovery, and stable hashes across three processes.

A plane improvement that loses the seam is failure.

## Source-vertex fan evidence

For a passing plane, verify that the artifact consumes at least one ordered multi-edge source-vertex transition route and that the route is included in structural hashing/provenance. For a failing plane, report the first typed rejection reason and all available cell/side/face/vertex/edge context.

Run the added contract-level producer tests explicitly, including:

- authoritative source-vertex fan traversal;
- reversed face-row invariance;
- duplicate transition metadata fail-closed behavior.

Do not weaken or rewrite tests when they fail.

## Remaining mandatory observations

- Close sheets must not merge unrelated sheets by position.
- Cylinder remains a Gate 3 observation while earlier gates are incomplete.
- Bunny and vase must pass exact fixture hash/topology guards, use ordinary smooth-field extraction, and traverse the real direct `SurfaceCells` path.
- Timeout, partial output, legacy/generic completion substitution, fallback, or recovery is failure.

## Default suites

After direct cases, run the non-overlapping remaining producer suite, completion suite, validation suite, and compiled API suite. Report direct acceptance separately from aggregate totals. The scheduler-sensitive validator timing ratio remains benchmark/closeout evidence only.

## Determinism

Run three independent processes each for plane, seam, close sheets, and cylinder. Run at least two each for bunny and vase within the established resource budget. Never treat timeout as correctness.

## Mandatory next-action rule

This artifact follows the second bounded Code + Build attempt. If Gate 1 does not materially advance beyond the prior 106/9/12 signature, the next turn must be a design review or bounded producer replacement proof. Do not authorize a third local predicate-repair turn.

## Exit products

- raw logs and exact command inventory;
- machine-readable runtime summary;
- Test + Benchmark report;
- either a Gate 2 close-sheet Code + Build plan when plane and seam pass, or the mandatory design-review/replacement-proof plan when Gate 1 does not advance;
- updated TODO, milestone, handoff, design/testing authority, and PR metadata;
- cleanup of stale plans/reports/results;
- final top-level PR #8 comment as the last repository write.
