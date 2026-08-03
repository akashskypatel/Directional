# Milestone G P5 — Structural Repair Test + Benchmark Report

**Turn type:** Test and benchmark without rebuilding  
**Artifact:** `8842377256` (`surface-cell-p5-same-corner-linux-release`)  
**Exact source:** `1f4c3c2a014f0bc945b50f1bb5a837c438cec992`  
**Review policy:** `never`

## 1. Artifact verification

- ZIP digest: `sha256:669bf5d6f3e9b3738298b5985b6bb715668bce0715b0a68d880eb4aa0e80d6bc`.
- `source-commit.txt` exactly matches the compiled source.
- `source-status.txt` is empty.
- All ten packaged checksums pass.
- Both packaged executables are Linux x86-64 ELF binaries.
- No source was rebuilt and no implementation, test, benchmark, or build logic was edited during this turn.

## 2. Test results

| Scope | Passed | Failed |
|---|---:|---:|
| Corrected fixtures and focused ownership/classification tests | 9 | 0 |
| `PatchDescriptorMilestoneE.*` | 15 | 0 |
| `SurfaceArrangementPhase16.*` + `PureQuadCompletionPhase18.*` | 89 | 0 |
| Phase 14–18 aggregate | 229 | 0 |
| `MilestoneGP23.*` + `SurfaceCellPipelinePhase20.*` | 52 | 0 |

The authoritative non-overlapping total is **296/296 passed**: 229 Phase 14–18 tests, 15 PatchDescriptor tests, and 52 P23/Phase20 tests.

The two P5-TB7 fixture defects are corrected for their intended scenarios:

- generated interiors on either allowed patch face pass, while a valid third face outside patch support is rejected;
- the two-odd-cell fixture supplies authoritative embedding, orientation, source topology, and area evidence and now exercises conforming shared-edge parity repair.

## 3. Direct random-bunny result

Two independent formal processes used:

- backend `SurfaceCells`;
- fallback `Fail`;
- source-grid recovery disabled;
- zero warmups;
- one measured run;
- a 60-second resource guard because preliminary direct attempts did not terminate.

Both runs timed out identically before producing benchmark JSON:

| Run | Exit | Wall | Peak RSS |
|---|---:|---:|---:|
| 1 | 124 | 60.05 s | 2,740,543,488 B |
| 2 | 124 | 60.05 s | 2,740,506,624 B |

Mean peak working set at timeout: **2,740,525,056 B (2.552 GiB)**.

No terminal ownership conflict, accepted output, output origin, completion hash, or final failure payload was emitted because completion did not return. Therefore the previous `8595/8573` claim cannot honestly be declared removed, reclassified, or still present; its disposition is **unresolved due nontermination**.

Relative to artifact `8841726806`, the new result is already at least:

- **+129.62% wall time** at the guard;
- **+207.13% peak memory**.

Relative to baseline artifact `8838467442`, it is already at least:

- **+161.30% wall time**;
- **+265.71% peak memory**.

This is a production-blocking performance and termination regression, not an acceptable slow success.

## 4. Stage isolation

A third diagnostic process injected failure immediately after simplification, before completion:

- wall: **19.260599 s**;
- peak working set: **343,326,720 B**;
- arrangement cells: **21,298**;
- simplified cells: **21,298**;
- terminal stage: `simplification`;
- recovery used: `false`;
- fallback attempted: `false`;
- output origin: `None`.

Stage lineage:

| Stage | Seconds | Objects | Structural hash |
|---|---:|---:|---:|
| `feature` | 0.002099 | 1,500 | `13335273019780706697` |
| `metric` | 0.019734 | 502 | `16830978356707858388` |
| `relief` | 0.174575 | 493 | `15313338397659290031` |
| `tracing` | 4.948876 | 80,862 | `17509532107879806215` |
| `strands` | 4.004260 | 16,958 | `15818654043234526118` |
| `embedding` | 0.001285 | 16,958 | `11224738497694146851` |
| `arrangement` | 9.422667 | 21,298 | `4744180686925088712` |
| `simplification` | 0.517944 | 21,298 | `15209892426726238631` |

The full processes therefore spend at least **40.79 additional seconds** after the verified pre-completion checkpoint and increase peak memory by approximately **2,397,198,336 B**. The runaway is isolated to completion/ownership repair rather than feature extraction, tracing, arrangement, or simplification.

## 5. Diagnosis

The runtime behavior and packaged source support the following diagnosis:

1. `complete_surface_cell_complex()` reaches a same-corner conflict and evaluates boundary candidates.
2. Each successful subdivision recursively invokes `complete_surface_cell_complex()` over the full modified complex.
3. Every recursion level receives a decremented depth-local limit, but there is no shared global candidate/work ledger.
4. Each level may iterate multiple candidates, copy the complex, and recompute parity, descriptors, every patch completion, and assembly.
5. Canonically equivalent repair states are not memoized.
6. The resulting search can expand combinatorially while retaining large per-attempt state.

This is the most strongly supported cause of the deterministic CPU and memory growth. The benchmark did not return a terminal record, so the report does not claim which exact candidate or conflict pair was active at timeout.

## 6. Test-integrity finding

The current tests validate the new stitch-time classification but do **not** exercise the production structural-repair path:

- the only test reference to `SameCornerDistinctBoundaryClaim` checks classification in `stitch_pure_quad_patches()`;
- no test asserts `completionOwnershipStructuralRepairAttempts`;
- no test invokes and verifies `BoundarySectorSubdivision` through `complete_surface_cell_complex()`.

Consequently, 296/296 passing tests do not validate the intended bounded production repair behavior. The missing tests must be added; production limits must not be weakened merely to make the bunny terminate.

## 7. Status

P5 remains **open and not production ready**.

The next authoritative turn is **code changes + compile-only build** using:

- `.agents/Directional/Milestone_G_P5_Bounded_Structural_Repair_Code_Build_Plan.md`;
- this report;
- `benchmark-results/p5-tb8-summary.json`.

The next turn must run no tests, benchmarks, or custom meshes.
