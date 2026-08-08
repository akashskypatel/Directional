# Milestone G Production Readiness TODO

Last updated: 2026-08-08 UTC

## Current gate

G0 truthful authority [passed baseline; candidate relief regression] → G1 uniform phase-front plane [passed] → G2 cross-chart / close-sheet isolation [passed baseline; candidate exact-order regression] → G3 periodic closure / holonomy [passed] → **G4 topology-distinct completion and singularities [active]** → G5 adaptivity/features → G6 bunny/vase production success → G7 hardening.

## Runtime validation — topology-region candidate

Artifact **`9022061741`** is runtime-validated artifact-only from implementation `3ca89ab55efff461b050fb12033174be70e7464f`.

Validated structural contracts:

- topology-region / isolation-seam **9/9**;
- polygonal boundary phase **5/5**;
- non-torus curved disk **5/5**;
- non-torus sheet coverage **2/2**;
- G4 periodic relations **5/5**;
- retained G0-G3 **16/17**.

Exact torus now constructs and consumes topology-region authority: four annular regions, eight internal isolation seams, one region spanning two local isolation labels, and four periodic relations. It reaches phase-front `Produced` and fails deeper at `tracing/phase-front-materialization / InvalidAuthoritativePhaseFrontCell`, with no fallback/recovery.

This confirms the former `InvalidBoundedDiskBoundaryTurn` was caused by conflating local isolation cuts with physical topology boundaries.

## Regressions that block accepted material progress

- Embedded relief no longer remains fail-closed: barrier-induced topology-region decomposition can return all local producers `NotApplicable`, allowing generic traces.
- Close-sheets remains strict-valid with two disconnected components and identical geometry, but deterministic component order reverses and exact hash changes from accepted `89b052762f52a5af` to `aaec5574aa2e52f9`.
- Torus contract test aborts at `hasTraceNetwork=false` before its intended topology diagnostics; this is pending independent review as a likely over-coupled expectation.

Bounded suites: producer **124/127**, completion/simplification **154/164**, validation **60/60**, API **8/8**, aggregate **346/359**.

## Mandatory design-review transition

The controlling plan required both runtime-visible topology-region progress and preservation of prior accepted authority. Because prior authority regressed, accepted material progress is not established. This is the second consecutive Code + Build cycle without accepted material progress.

**No further ordinary Code + Build is authorized until mandatory independent Design Review completes.**

Authoritative next plan:
`.agents/Directional/Gate_4_Topology_Region_Mandatory_Design_Review_Plan.md`

Pending proposal, not executable before review:
`.agents/Directional/Gate_4_Topology_Region_Materialization_And_Regressions_Code_Build_Proposal.md`

The reviewer must resolve the embedded-relief/topology-region contract, close-sheets deterministic identity, topology-region-aware multi-isolation materialization, and torus test scope before publishing exactly one authoritative implementation/evidence plan.

Prescribed sphere remains deferred until torus reaches direct strict-valid production. G5/G6 and historical completion/simplification repair remain deferred.

Every completed turn ends with a new top-level PR #8 conversation comment after all other repository writes.
