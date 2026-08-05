# Directional Surface-Cell Quadrangulation — Session Handoff

**Updated:** 2026-08-04  
**Repository:** `akashskypatel/Directional`  
**Base:** `surface_cell_quad`  
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Current checkpoint

P5-R2D source-topology preflight, explicit boundary-cycle structure, source-authoritative exterior classification, and transactional orbit publication are implemented and compile successfully.

Exact compiled source: `0ba0aa9f7a07d5ca6ba67280d705ee8439e1d760`.

Runtime acceptance has not been executed for this source. Remain on R2. The next turn is **P5-TB28 artifact-only R2D validation** using artifact `8913777837`. Do not configure, rebuild, relink, patch, regenerate, or modify source.

## Read first

1. `TODO`
2. `MILESTONE_G_TODO.md`
3. `.agents/Directional/Milestone_G_P5_R2D_Code_Build_Report.md`
4. `.agents/Directional/Milestone_G_P5_R2D_Test_Benchmark_Plan.md`
5. `benchmark-results/p5-r2d-summary.json`
6. `.agents/Directional/Milestone_G_P5_TB27_Artifact_Only_R2C_Test_Benchmark_Report.md`
7. `.agents/Directional/Milestone_G_P5_R2D_Authoritative_Orbit_Publication_Code_Build_Plan.md`
8. `.agents/Directional/REORIENTATION_PLAN.md`
9. `.agents/Directional/DESIGN.md`
10. `.agents/Directional/GitHub_Workflow_Policy.md`

## P5-R2D authority

- previous tested source: `94b86c50c38a849a744f40b0a21c86ed19551769`;
- workflow event commit: `6757e6e98aa90e5b5eefce1db9645fbf523f2650`;
- exact compiled source: `0ba0aa9f7a07d5ca6ba67280d705ee8439e1d760`;
- reviewed patch SHA-256: `c7355a7de3998638f596fa927117584fce274920ca00fcd84f08773bf75935e8`;
- applied commit-diff SHA-256: `de9b6e9e30bf182d73082330d1ef2dbaceca07ffb7a2aa1a938d8e71896319a8`;
- successful run/job: `30963007513` / `92170817963`;
- artifact: `8913777837`, `surface-cell-p5-r2d-github-source-linux-release`;
- artifact SHA-256: `bcb9c6962677f2f638cf6a832eb25d88fdcd2a97e506a1435a7f936d4891416a`;
- workflow-log artifact: `8913778202`;
- workflow-log SHA-256: `04ba6f577b4d76519c365b564762b72844fa5b3f17e71c80bd7d292acf760384`;
- empty source status;
- recursive checksums **44/44**;
- package files **45**;
- fixtures **26**;
- recursive submodules **9**;
- all four target hashes verified;
- all **132/132** Ninja actions completed;
- no project binary executed.

## P5-R2D implementation

1. Rejects source edges with more than two incident faces before publishing valid incidence, using typed `NonManifoldSourceEdge` evidence.
2. Stores explicit `boundaryCycleOffsets` so a bounded cell can retain multiple directed boundary cycles.
3. Separates complete successor-orbit audit from bounded-cell topology and exterior classification.
4. Computes geometry from core cycles rather than treating bridge excursions as one simple polygon.
5. Uses source-boundary evidence as authoritative exterior ownership.
6. Assigns compatible contained cycles as explicit inner boundaries of the smallest bounded owner, deriving boundary count, Euler characteristic, disk state, and area.
7. Audits every boundary cycle independently before committing cell ownership.
8. Propagates boundary-cycle identity through simplification, feasibility repair, descriptor memory, rollback state, and pipeline hashes.
9. Includes focused nested-topology and typed nonmanifold contracts; they were compiled but not executed.

## P5-TB28 execution order

1. Verify artifact SHA, exact source, empty status, **44/44** checksums, 45 files, 26 fixtures, nine submodules, target hashes, source contents, one base workflow, and zero patch payloads.
2. Run source-chart, source-validator, recovery, feature/barrier, and graph-dependent authority scopes.
3. Run all R2/R2C/R2D incidence, bridge, multi-boundary, and transactional-publication contracts.
4. Require typed nonmanifold rejection and no valid halfedge with `cell == -1`.
5. Run all `MilestoneDClosure.*` tests and require **7/7**.
6. Run Phase 14–18 aggregate plus Phase 16, Phase 17, and Phase 18 independently.
7. Run direct plane, seam, close sheets, cylinder, and packaged disconnected-close-sheet cases with fallback `Fail` and recovery disabled.
8. Require seam, close sheets, and cylinder to retain nonzero valid arrangement inventories.
9. Run complete Phase 20.
10. Run the complete suite once with a watchdog used only as a safety mechanism; measure runtime, bunny duration, and maximum RSS.
11. Do not run the full standalone bunny matrix unless focused and complete-suite evidence cannot identify the producer.

Advance to R3 only if all R2 gates close and remaining failures move to later typed completion evidence.

## Mandatory working-branch hygiene

At the start and end of every Code + Build turn, compare the working branch’s temporary agent resources with the base branch and the current turn.

- Remove every superseded agent workflow, trigger marker, patch fragment, patch README, generated transfer file, and temporary build artifact.
- While a remote build is active, retain only base workflows plus the single bounded workflow and payload required for that turn.
- Remove the active workflow and payload from the exact compiled source whenever the workflow can self-clean; otherwise delete them in the documentation-only handoff commit immediately after the run.
- Verify the final branch and packaged source contain no stale temporary artifacts before declaring the CB turn complete.
- Never leave historical workflow YAML on the branch: even an unrelated stale syntax error can emit a failing check on later commits.

P5-R2D removed 18 stale workflows and five old payload files before the run. The exact compiled source then removed its active workflow and two active patch parts. The source now contains only `.github/workflows/agent-source-snapshot.yml` and no agent patch payloads.

## Key lessons

- A valid successor permutation does not prove admissible source topology, disk topology, or exterior ownership.
- Multiple boundary cycles must remain explicit; flattening them destroys Euler and incidence meaning.
- Bridge/support ownership and area-bearing topology are separate, but support classifications cannot hide nonmanifold source topology.
- Compile success proves integration and packaging only. P5-TB28 determines whether R2D fixes runtime behavior.
- Stale workflows are active failure sources, not harmless history. Remove them as part of every CB transition.

## Preserved prohibitions

- no validator weakening;
- no frequency/count/order ownership selection;
- no fallback/recovery substitution;
- no synthetic counters;
- no positional merging or source-triangle pairing;
- no arbitrary subset search;
- no fixture/ID special cases;
- no post-hoc cycle decomposition;
- no timeout-as-correctness.
