# Milestone G P5 — Bounded Structural Repair Test + Benchmark Report

**Turn type:** Test and benchmark without rebuilding  
**Artifact:** `8843206930` (`surface-cell-p5-bounded-repair-linux-release`)  
**Exact source:** `bc95579be68d5de073de956022eec8fb89120ec0`  
**Artifact digest:** `sha256:9b6ef73f2bd04eb49486cd7f0f28a1d2e9121a36791c7dd25fe1ffcc19d64f94`  
**Review policy:** `never`

## 1. Artifact verification

- `source-commit.txt` exactly matches the compiled source.
- `source-status.txt` is empty.
- All ten packaged checksums pass.
- The packaged test and benchmark executables are Linux x86-64 ELF binaries.
- The core and pipeline libraries are valid static archives.
- The exact source archive, configure/build logs, and recursive submodule revisions are present.
- No source was rebuilt and no implementation, test, benchmark, or build logic was edited during this turn.

## 2. Test results

| Scope | Passed | Failed |
|---|---:|---:|
| New whole-complex structural-repair subset | 2 | 3 |
| `PatchDescriptorMilestoneE.*` | 17 | 3 |
| `SurfaceArrangementPhase16.*` + `PureQuadCompletionPhase18.*` | 89 | 0 |
| Phase 14–18 aggregate | 229 | 0 |
| `MilestoneGP23.*` + `SurfaceCellPipelinePhase20.*` | 52 | 0 |

The authoritative non-overlapping total is **298/301 passed**: 229 Phase 14–18 tests, 20 PatchDescriptor tests, and 52 P23/Phase20 tests.

### Invalid structural-repair fixture contract

The three failures are:

- `WholeComplexParallelRouteRepairCompletesWithinOneGlobalLedger`
- `ZeroStructuralBudgetFailsBeforeCandidateExpansion`
- `OneCandidateBudgetIsExactAndDoesNotRecurse`

All three use `make_valid_parallel_route_same_corner_complex()`. The constructed complex is topologically valid, but its initial completion succeeds without producing a `SameCornerDistinctBoundaryClaim`. Consequently:

- structural repair attempts remain zero;
- candidate consumption remains zero;
- the zero-budget case succeeds instead of exhausting a budget;
- the one-candidate case never evaluates a candidate.

The production behavior is correct for the actual input; the fixture does not create the scenario named by the tests. Production logic must not be changed to force a repair when assembly already succeeds.

`StructuralRepairLedgerIsPatchOrderInvariant` also passes vacuously because both orderings perform zero structural attempts. Only `SemanticOnlySameCornerOverlapFailsBeforeCandidateExpansion` currently exercises a meaningful structural-routing contract.

The next code turn must replace the fixture with an authoritative complex that first produces an exact same-corner/distinct-boundary completion claim and must assert that precondition before testing budgets or order invariance.

## 3. Direct random-bunny result

Two clean-exit independent processes used:

- backend `SurfaceCells`;
- fallback `Fail`;
- source-grid recovery disabled;
- zero warmups;
- one measured run.

| Run | Process exit | Pipeline success | Wall | Peak working set | Completion |
|---|---:|---:|---:|---:|---:|
| 3 | 0 | false | 32.075226 s | 1,053,339,648 B | 15.882026 s |
| 4 | 0 | false | 33.230250 s | 1,083,228,160 B | 16.525224 s |

Formal means:

- wall: **32.652738 s**;
- peak working set: **1,068,283,904 B**;
- completion: **16.203625 s**.

Both clean-exit runs terminate below the 39.228299-second wall gate and the 1,115,394,560-byte peak-memory gate.

Two earlier guard-wrapped probes also produced complete benchmark JSON with identical hashes and ledgers, but their outer shell status was not captured cleanly. They measured 1,241,817,088 B and 1,241,993,216 B peak working set. The all-four mean is 1,155,094,528 B, above the memory gate. The bounded implementation therefore removes the catastrophic runaway, but peak-memory compliance is not yet robust across repeated processes.

## 4. Deterministic terminal ledger

All four completed JSON records have identical:

- fixture hash;
- terminal failure;
- ownership repair ledger;
- context-product hashes;
- stage input/output structural hashes;
- descriptor and endpoint counts;
- candidate order and affected patches.

The terminal result is fail-closed:

```text
SameCornerStructuralRepairExhausted:candidate-budget:
DuplicateStitchedQuad:firstPatch=4956;firstLocalQuad=1;
secondPatch=4954;secondLocalQuad=0;
classification=same-corner-distinct-boundary
```

Authoritative ledger totals:

- descriptors attempted/completed/failed: `21,297 / 21,297 / 0`;
- completion variant repairs: `6`;
- structural candidates consumed: `2 / 2`;
- structural attempts: `2`;
- inserted boundary vertices: `2`;
- visited exact states: `3`;
- full recomputation passes: `3`;
- incremental recomputation passes: `0`;
- peak live candidate complexes: `1`;
- current live candidate complexes at return: `0`;
- exhaustion reason: `candidate-budget`;
- output origin: `None`;
- accepted quads: `0`;
- fallback attempted: `false`;
- source-grid recovery used: `false`.

The deterministic route is:

1. completion variants move the earlier `378/394` template conflict through `401/3979` to the exact same-corner claim `4956/4954`;
2. candidate halfedge `22706`, affecting patches `4954/4955`, introduces a new same-corner claim at `14137/14136`;
3. candidate halfedge `23112`, affecting patches `4952/4954`, introduces the same replacement ownership class;
4. the global candidate budget is exhausted and the original claim remains authoritative.

The bounded controller correctly refuses to commit either candidate because replacing one ownership conflict with another is not progress.

## 5. Performance disposition

Relative to the P5-TB8 runaway lower bound, the formal mean improves:

- wall time by **45.62%**;
- peak memory by **61.02%**.

Relative to artifact `8841726806`, the formal mean is:

- **+24.86%** wall;
- **+19.72%** peak memory;
- **+150.24%** completion time.

The termination regression is fixed. Production completion is still unsuccessful, completion remains materially slower than the pre-structural checkpoint, and memory has insufficient repeatability margin.

## 6. Root-cause classification for the next turn

The remaining production blocker is no longer recursive search. It is the repair primitive and candidate representation:

- candidate generation emits individual differing boundary halfedges;
- each individual split is twin-conforming but incomplete for the full parallel boundary sector;
- each isolated split removes the local original pair but creates another same-corner claim elsewhere in the affected neighborhood;
- the two deterministic candidate intervals belong to the same unresolved route-sector relationship and need an atomic route-complete repair, not a larger arbitrary candidate budget.

The next implementation must represent a structural candidate as an exact canonical set of complete boundary-route intervals between shared authoritative corners. It should evaluate a bounded set of route-complete or coupled-sector transactions, not an arbitrary powerset and not one interval at a time.

## 7. Disposition

P5 remains **open and not production ready**.

The next authoritative turn is **code changes + compile-only build** using:

- `.agents/Directional/Milestone_G_P5_Route_Complete_Structural_Repair_Code_Build_Plan.md`;
- this report;
- `benchmark-results/p5-tb9-summary.json`.

That turn must correct the invalid structural-repair fixtures, implement atomic route-complete candidate repair, preserve the global ledger and strict fail-closed contract, improve peak-memory margin, compile the four required targets, and execute no tests, benchmarks, or custom meshes.
