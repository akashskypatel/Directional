# Milestone G P5 — Route-Complete Structural Repair Test + Benchmark Report

**Turn type:** Test and benchmark without rebuilding  
**Artifact:** `8844133680` (`surface-cell-p5-route-complete-linux-release`)  
**Exact source:** `76cf884a6890a23a6db7d7bda9bc77b85ec4505c`  
**Artifact digest:** `sha256:1f32a4d3600d1a7be39e710d35273f80bed0c24850626d744ab15e7a748a34bb`  
**Review policy:** `never`

## 1. Artifact verification

- `source-commit.txt` exactly matches the compiled source.
- `source-status.txt` is empty.
- All ten packaged checksums pass after removing the archive-time `artifact/` prefix.
- Both executables are Linux x86-64 ELF binaries and both libraries are valid static archives.
- The exact source archive, configure/build logs, and recursive submodule revisions are present.
- No rebuild and no implementation, test, benchmark, or build-system edit occurred.

## 2. Test results

| Scope | Passed | Failed |
|---|---:|---:|
| Corrected route-complete subset | 6 | 0 |
| `PatchDescriptorMilestoneE.*` | 21 | 0 |
| Phase 16 + Phase 18 | 89 | 0 |
| Phase 14–18 aggregate | 229 | 0 |
| Milestone G P23 + Phase 20 | 52 | 0 |

The authoritative non-overlapping total is **302/302 passed**: 229 Phase 14–18 tests, 21 PatchDescriptor tests, and 52 P23/Phase20 tests.

### Artifact portability defect

The first P23/Phase20 invocation produced 51/52 because `BenchmarkManifestDispatchesBackends` attempted to open:

`/home/runner/work/Directional/Directional/benchmarks/fixtures/manifest.example.json`

That is the absolute compile-runner source path. The artifact already contains the exact source archive; staging that archive at the compiled path made the same packaged executable pass 52/52. The test's intended dispatch behavior passes, but the packaged test executable is not self-contained. The next code/build turn must use executable-relative packaged test data, a runtime fixture-root override, or a temporary manifest rather than an absolute CI path.

## 3. Direct random-bunny result

Four independent clean-exit processes used `SurfaceCells`, fallback `Fail`, source-grid recovery disabled, zero warmups, and one measured run.

| Run | Role | Pipeline | Wall | Peak working set | Completion |
|---|---|---|---:|---:|---:|
| 1 | Formal | failed closed | 66.704669 s | 1,094,594,560 B | 25.980217 s |
| 2 | Formal | failed closed | 67.738376 s | 1,094,791,168 B | 25.623915 s |
| 3 | Supplementary | failed closed | 66.756596 s | 1,094,737,920 B | 25.133695 s |
| 4 | Supplementary | failed closed | 66.909710 s | 1,094,815,744 B | 25.683125 s |

Formal means:

- wall: **67.221522 s**;
- peak working set: **1,094,692,864 B**;
- completion: **25.802066 s**.

All-four means:

- wall: **67.027338 s**;
- benchmark peak working set: **1,094,734,848 B**;
- `/usr/bin/time` maximum resident set: **1,094,865,920 B**;
- completion: **25.605238 s**.

Every process stayed below the `1,115,394,560 B` memory cap. The highest independently measured resident set was **1,094,922,240 B**, leaving only **20,472,320 B** of margin. Every process exceeded the `39.228299 s` wall cap by a large margin, and none produced output.

## 4. Deterministic route ledger

All four completed JSON records have identical fixture/stage hashes, context-product hashes, exact repair logs, route identity, interval set, affected patches, terminal failure, and structural owned-byte diagnostics.

The original claim is:

`4956 / 4954`, classification `same-corner-distinct-boundary`.

One topology-derived coupled candidate was evaluated:

- route identity hash: `8326996045896577381`;
- shared-corner hashes: `1852193725494285512`, `13423692822468399424`;
- exact interval count: `8`;
- halfedges: `22706, 23112, 22707, 22710, 22824, 23924, 23922, 23932`;
- affected patches: `4952, 4954, 4955, 4956, 4957, 4958, 5184`;
- inserted vertices / split undirected edges: `8 / 8`;
- full recomputation passes: `2`;
- peak live candidate complexes: `1`;
- route outcome: `introduced-ownership-claim`;
- peak structural-repair owned bytes: `210,773,020`.

The candidate pass reaches:

`DuplicateStitchedQuad:firstPatch=14137;secondPatch=14136;classification=same-corner-distinct-boundary`

Both owners use closed-form completion, have equal source support, and have distinct authoritative boundary identities.

## 5. Root-cause classification

The route-complete transaction removes or bypasses the active `4956/4954` claim and exposes `14137/14136`. Neither resulting patch is in the candidate's affected-patch set. Therefore, labeling every different post-candidate conflict as newly introduced is not justified by the current evidence.

The strongest supported interpretation is that `14137/14136` is a latent subsequent ownership claim that the first-failure assembly scan did not report before the earlier claim was repaired. This remains an inference because assembly currently returns only the first duplicate and does not produce complete before/after conflict inventories.

The production blocker is now the **first-conflict progress model**, not route incompleteness:

- assembly returns one conflict and stops;
- route repair requires the next pass to have zero conflicts;
- any different first conflict is classified as introduced;
- a valid repair cannot advance through multiple independent latent claims;
- the candidate is discarded even when the next conflict lies outside its mutation neighborhood.

## 6. Performance disposition

Relative to P5-TB9 formal means:

- wall: **+105.87%**;
- peak working set: **+2.47%**;
- completion: **+59.24%**.

The route-complete candidate remains memory-bounded and repeatable, but full global recompletion and first-conflict rejection more than double wall time. A solution that simply performs additional full passes would move further away from the wall gate.

## 7. Required next implementation

The next turn must implement an exact global ownership frontier:

1. collect the complete compact ownership-conflict inventory rather than returning after the first duplicate;
2. distinguish pre-existing latent claims from genuinely introduced claims using exact before/after inventories and mutation scope;
3. use strict set reduction as the progress measure;
4. batch pairwise-independent route repairs or reuse unchanged patch completion products so the fix does not require one full global recomputation per claim;
5. retain fail-closed final output, exact state identity, global budgets, and all existing validators;
6. make packaged fixture tests independent of the CI source path.

## 8. Disposition

P5 remains **open and not production ready**.

The next authoritative turn is **code changes + compile-only build** using:

- `.agents/Directional/Milestone_G_P5_Global_Ownership_Frontier_Code_Build_Plan.md`;
- this report;
- `benchmark-results/p5-tb10-summary.json`.

PR #8 must remain draft and unmerged.
