# Surface-Cell Producer Reorientation Plan

## Purpose

Keep implementation work aligned with production-ready direct cross-field surface paving. The active objective is not to improve diagnostic detail or preserve historical repair machinery; it is to implement the earliest missing constructive design contract and prove it on the ordered direct fixtures.

## Mandatory direction control

Every turn must declare:

```text
Active design gate:
Earliest failing fixture:
Missing design contract:
Smallest general implementation change:
Observable material-progress condition:
Explicitly deferred work:
```

A later gate, downstream repair, performance task, or historical cleanup item cannot displace an earlier red constructive gate.

## Ordered gates

1. **G0 — Truthful authority**: direct `SurfaceCells`, fallback `Fail`, recovery disabled, strict `CompletedSurfaceCells` validation. Passed and continuously enforced.
2. **G1 — Uniform phase-front plane**: authoritative lattice phase, front ownership, oriented source-attached cells, direct one-to-one quad-domain materialization. **Active.**
3. **G2 — Cross-chart and close-sheet propagation**: seam and close-sheet cases with authoritative chart transport and no cross-sheet merging.
4. **G3 — Periodic closure and holonomy**: cylinder closure and complete incidence.
5. **G4 — Topology-distinct completion and singularities**.
6. **G5 — Adaptive 2:1 transitions and hard features**.
7. **G6 — General production geometry on `bunny_1k_random.obj`**.
8. **G7 — Operational hardening and default-on decision**.

Do not begin a blocked gate.

## Current G1 evidence

The bounded phase-front implementation is live and deterministically consumed:

- baseline plane: 106 traces, 9 arrangement cells, 12 quads;
- current plane: 352 traces, 65 arrangement cells, 409 quads;
- current first invalid record: `completion/output-validation:FlippedFace`, cell 38, source face 41;
- 100 strict validation failures;
- tracing, arrangement, and completion structural hashes stable across three independent processes.

This is material progress, not gate completion. The current producer creates authoritative four-sided cells but then sends them through generic patch completion, which expands their topology and emits flipped output.

## Active G1 subgate

The next implementation must establish **source-normal orientation and direct-cell materialization**:

1. Four distinct source-attached corners.
2. Ordered side endpoint continuity.
3. Nonzero intrinsic signed area.
4. Winding consistent with the authoritative source normal.
5. Component and local-sheet consistency.
6. Exactly one filled side or explicit exterior classification per directed front edge.
7. Transactional whole-cycle reversal when winding is opposite.
8. One accepted four-sided phase-front cell materializes as one intended quad-domain cell.
9. Fail closed before completion on any orientation, incidence, route, component, or sheet inconsistency.

Arrangement may canonicalize identities and split exact crossings. It must not infer connectivity through fan-sector ranking or expand already-decided cells through generic patch completion.

## Valid test maintenance

Two producer tests contain obsolete expectations after the new path began succeeding on their planar inputs:

- a scaffold diagnostic test assumes production must fail;
- a recovery test assumes recovery must run even when direct production succeeds.

Correct these by using valid scenarios or by separating direct-success and recovery-only assertions. Never weaken the four direct acceptance tests or recovery validation.

## Material-progress gate

The next artifact must do at least one of:

- pass plane direct acceptance;
- advance beyond `completion/output-validation:FlippedFace` with one-to-one cell materialization and a lower structural validation burden;
- expose and enforce a general orientation/incidence invariant before invalid cells reach completion.

A renamed diagnostic, new counter, new hash, or higher unrelated pass count is not progress.

## No-progress stop rule

If the next Code + Build turn does not materially improve the orientation/direct-cell contract, the following turn must perform a bounded design review or producer replacement proof. Do not continue equivalent micro-repairs.

## Explicitly deferred

Until G1 exits, do not make the principal objective:

- fan-interval ranking or repair variants;
- new diagnostic/ownership taxonomies;
- seam, close-sheet, cylinder, torus, sphere, thin-tube, mechanical, or bunny-specific logic;
- adaptivity or 2:1 transitions;
- general FlowRep or patch catalogs;
- cache, memory, scheduler, parallelism, or performance work;
- source-grid recovery enhancement;
- historical completion-fixture cleanup unrelated to the current compile path.

## Layered patch authority during GitHub outage

The tested implementation is exact base `e82fb47dccbefa1b878bc9ddff0ae63745f6efe9` plus patch blob `aa18d454877ccf40d16f71f173fdaf765f5f1086`. Keep its five-file synchronization on both TODO files until service recovery.

While the outage persists:

- do not use workflows for repository updates or builds;
- reconstruct current tested source exactly from the recorded base and patch;
- express the next orientation/direct-cell change as a separate incremental patch;
- record patch digest, expected output blobs, local build artifact, logs, and dependency closure;
- retain both patch layers in order.

After recovery, apply and verify the current patch first and the orientation/direct-cell patch second as separate coherent commits. Remove each payload only after its corresponding source state is committed and verified.

## Next plan

`.agents/Directional/Gate_1_Phase_Front_Orientation_Code_Build_Plan.md`
