# Milestone G P5-TB22 Artifact-Only Test and Benchmark Report

**Date:** 2026-08-04  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`  
**Turn type:** artifact-only test and benchmark

## Disposition

P5-TB22 is complete. The P5-CB135 through P5-CB142 checkpoint restores bounded deterministic termination, but it does not produce production-valid output.

Closed or improved:

- package authority passed;
- the complete **600-test** suite now terminates normally in **103.441 s**;
- `MilestoneGP26.ProductionMatrixTerminatesWithoutHiddenFallback` passes;
- all four face-edge bunny runs terminate with the same 14-state budget, sequence hash, and typed failure;
- all four smooth bunny runs terminate within the established wall and peak-working-set limits;
- Phase 14–18 remains **236/236**;
- Phase 16 remains **39/39**;
- Phase 17 remains **26/26**;
- typed torus inventory now names `side-count-unsupported`;
- same-sample fields are emitted and sequence-tagged.

Still open:

- the full suite is **585/600**, with 15 failures;
- direct production remains **0/8**;
- no repeated-node alternative commits;
- cylinder remains non-disk and its completion remains self-intersecting;
- the valid parallel route still fails and reuse/recompute remains `0/0`;
- plane, seam, and close sheets retain the same `LocalSheetMismatch` producers;
- rotated/reversed local candidate catalogs still end in invalid geometry;
- GP23, GP24, and Phase20 intended later-stage lineage remains preempted;
- torus remains incomplete;
- same-sample categorized owned bytes are always zero, so coverage is 0% despite `available=true`.

P5 remains open.

## Artifact authority

Executed artifact `8894034755`, `surface-cell-p5-cb142-github-source-linux-release`, directly.

- archive SHA-256: `ff77004f8893b9f993165ba685794faca52f5611c9f1c47deb3f1dd5d930cb55`;
- exact compiled source: `aa2917e280fabd2272911a39cd0ecc327cce1cf3`;
- workflow event commit: `b7f8a9978764b77931ba6d299fdcbc65639235de`;
- reviewed patch SHA-256: `890dd621cf549f32c55d44f52b85050bfdfa5ce15df5f2bda2f8ba3e33c8ed70`;
- source status empty;
- recursive checksums **40/40**;
- package files **42**;
- fixture files **26**;
- recursive submodule records **9**.

Packaged target hashes:

- `directional_phase1_tests`: `e475dd7f64650254fc65ec0b3a32ca5093b1693403fc29c2356c38aec7eb0696`;
- `directional_benchmarks`: `fbe28f7dd1d7e583ce87af4ff11f11515e767915f685fd0c67cbb4e7b469d2e1`;
- `libdirectional_core.a`: `e69739744abbff3fe27335a9da3fa84f254a3eb01d7222afa06797c609d9f0c0`;
- `libdirectional_pipeline.a`: `9be7f7dc0c7f01ad573eb5502abb0848ce69b5d35fdc0600888593d87a195e5d`.

No configure, build, relink, patch, regeneration, or source modification occurred during P5-TB22.

## Test scopes

| Scope | Result |
|---|---:|
| Focused contracts | **32/42** |
| Phase 14–18 | **236/236** |
| Phase 16 | **39/39** |
| Phase 17 | **26/26** |
| Milestone D | **6/7** |
| Milestone E | **23/26** |
| GP23 + GP24 | **10/14** |
| Phase 20 | **46/48** |
| Complete suite | **585/600** |

The complete suite terminates. This closes the P5-TB21 operational nontermination regression, but not correctness.

## Bounded alternative execution

The topology-derived budget is operational and deterministic.

- face-edge bunny: four runs, each `attempted=14`, `budget=14`;
- all four report `budget-exhausted`;
- all four produce state sequence hash `12658256849805696865`;
- wall range **20.727–22.865 s**;
- peak working-set range **165,543,936–165,769,216 B**.

The bounded-state gate passes. The producer gate does not: the repeated-node boundary remains invalid and no replacement cycle commits.

Other repeated-node cases terminate with typed exhaustion:

- prescribed sphere: **68/68** alternatives exhausted;
- mechanical feature: **104/104** alternatives exhausted.

## Earliest focused blockers

1. Cylinder remains `non-disk-cell cell=0 halfedge=43 twin=42 next=29`.
2. The general-completion fixture reaches bounded-combinatorial variant 47 and still produces `degenerate-normal`.
3. The valid whole-complex parallel route still ends in `same-corner-distinct-boundary`.
4. The one-candidate budget contract still records zero incremental recomputation and reuse/recompute `0/0`.
5. GP23 optimization injections still terminate at real completion failure.
6. GP24 and Phase20 validation-lineage fixtures still terminate at completion.
7. Cylinder Phase20 production remains `NotProductionReady/completion`.

## Direct production matrix

All cases used `SurfaceCells`, fallback `Fail`, and source-grid recovery disabled. No fallback or recovery occurred.

| Case | Result | Earliest authoritative blocker |
|---|---|---|
| plane | fail | 12 quads; `LocalSheetMismatch`, cell 4, face 7 |
| cylinder | fail | patch 10, pattern variant 51, local quad 3, `bow-tie-intersection` |
| torus | fail | descriptor 22 / cell 23, `side-count-unsupported`, attempted 41, failed 2, total 43 |
| thin bent tube | fail | patch 108, bounded-combinatorial variant 43, `degenerate-normal` |
| close sheets | fail | 34 quads; `LocalSheetMismatch`, cell 3, face 13 |
| prescribed sphere | fail | repeated boundary node; alternative budget exhausted 68/68 |
| multi-face seam | fail | 24 quads; `LocalSheetMismatch`, cell 2, face 15 |
| mechanical feature | fail | repeated boundary node; alternative budget exhausted 104/104 |

Production remains **0/8**.

The doubled variant catalog advances the terminal candidate IDs from 25 to 51 on cylinder and from 21 to 43 on thin tube, but it only explores rotations/reversals of the same invalid geometry. It does not provide a topology-distinct valid completion.

## Bunny evidence

### Face-edge field

Four independent processes terminate with one matching failed signature:

- 20.727 s, 165,728,256 B;
- 21.433 s, 165,543,936 B;
- 22.865 s, 165,769,216 B;
- 22.525 s, 165,740,544 B.

Every run reports:

`BoundaryParityRepair:InvalidReplacementBoundary:repeated-boundary-node;AlternativeRepairBudgetExhausted;attempted=14;budget=14`

Completion never starts and reuse/recompute remains `0/0`.

### Smooth/default field

Four independent processes terminate with one matching failed signature:

- 31.052 s, 452,636,672 B;
- 31.133 s, 452,632,576 B;
- 35.247 s, 452,571,136 B;
- 35.588 s, 452,689,920 B.

All are below the established **39.228299 s** wall and **1,115,394,560 B** peak limits. Every run still fails at:

`InvalidCompletionQuadEmbedding;patch=9181;backend=closed-form;variant=0;localQuad=0;classification=degenerate-normal;vertices=15000,15001,15003,15002;component=0;sheet=0;sourceFaces=406`

Resource determinism improves, but valid output remains absent.

## Same-sample memory telemetry

Every direct production and bunny result reports a nonzero sample sequence and `sameSampleOwnershipMeasurementAvailable=true`. However, every result records:

- nonzero same-sample working set;
- **zero** same-sample categorized owned bytes;
- coverage ratio **0**;
- reconciliation remainder equal to the entire sampled working set.

This is not a valid same-sample ownership measurement. The sampler is observing a post-release or otherwise uncategorized point. The 75% gate remains open, and availability must not be true for a zero-owned sample.

## P5-TB21 comparison

Improved:

- full suite changes from nonterminating to **585/600** in 103.441 s;
- all four face-edge runs now terminate deterministically;
- smooth wall time improves from 40.090 s to 31.052–35.588 s;
- typed alternative exhaustion and sequence hash are available;
- torus reason is named.

Unchanged or incomplete:

- production remains **0/8**;
- Milestone D remains **6/7**;
- Milestone E remains **23/26**;
- GP23 + GP24 remains **10/14**;
- Phase20 remains **46/48**;
- cylinder, route/reuse, source-sheet, local-template, lineage, and torus correctness remain open;
- same-sample coverage remains unsatisfied and is now incorrectly marked available at 0%.

## Next turn

Proceed with **P5-CB143 through P5-CB150 code changes plus compile-only build** following `.agents/Directional/Milestone_G_P5_Post_TB22_Producer_Correction_Code_Build_Plan.md`.

Compile exactly `directional_core`, `directional_pipeline`, `directional_phase1_tests`, and `directional_benchmarks`. Execute no project binary during the code/build turn.

Preserve all prohibitions: no validator weakening, frequency/count/order selection, fallback/recovery substitution, synthetic counters, positional merging, source-triangle pairing, arbitrary subset search, fixture/ID special cases, or timeout-as-correctness.
