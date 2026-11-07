# RA-202 — TB76 Linux Vase timeout: census-path cost probe adjudication (2026-11-04)

**Turn:** `M6-CP3-TB76-P13-OPTIMIZER-SOURCE-QUERY-FULL-GATE-REV`, re-adjudicated by Review (Claude, scratch build) — **COMPLETE**.

It supersedes the [TB76 independent Review](Architecture_M6_CP3_TB76_P13_Linux_Vase_Independent_Review_Decision_20261104.md)'s successor. It also withdraws the turn that successor started, `M6-CP3-CB84-P13-LINUX-VASE-DIAGNOSTIC-TIMING`. That turn is IN_PROGRESS, but its patch was never applied or compiled ([preservation record](Architecture_M6_CP3_CB84_P13_Linux_Vase_Diagnostic_Timing_Work_Preservation_20261104.md)). **Do not apply that preserved patch.** The CB84 number stays with the withdrawn turn.

**Base:** HEAD `299be8bd7`. Its product source equals CB83 `2278b8b649b4262fb70a522371ed282655383af5` (`git diff --quiet` over `src include tests benchmarks CMakeLists.txt cmake`).

## RA-202.1 Review of the TB76 Review

**What stands:**
- The TB76 execution evidence is valid: 893/893, membership 974, 1794 + 9 hashes.
- That Review was right to refuse RA-201.10's inference that "a timeout means CB82 did not take".
- No promotion follows.

**What does not stand:**
1. **Its successor is the wrong shape.**
   - The successor is an open-ended instrumentation turn written by the implementation agent. The implementation agent receives exact patches only (RA-167, RA-172).
   - It adds permanent stage logging on stderr to product code. That answers a question that needs no product change.
   - It takes at least three turns (CB, TB, then "stack sampling in a later step") to name a *stage*, and still not a cost owner.
2. **It overlooked decisive evidence already in its own artifacts.**
   - **Linux is not uniformly slower.** TB76's 119 gate rows that take at least 1 s on macOS ran at a median Linux/macOS ratio of **0.96** (p10 0.66, p90 1.13). Cylinder took 6.33 s against 6.22 s, and BunnyRandom 0.59 s against 0.60 s.
   - **Vase alone has been slower on Linux, in every TB:**

     | TB | Linux | macOS | Ratio |
     |---|---|---|---|
     | TB68 | 213.6 s | 138 s | 1.55× |
     | TB70 | 259 s | 143 s | 1.81× |
     | TB71 | 288.7 s | 143 s | 2.02× |

     A cost confined to one large fixture fits both facts, and so does one bound by memory bandwidth.
   - **Its falsifiers named no cost owner.**

**RA-201's own errors, owned here:**
1. **RA-201.10 mis-registered the census.** It registered "Vase RED within 600 s" from a 250 s macOS run without applying Vase's 1.55–2.0× platform ratio; that ratio predicts 390–500 s. It also wrote that a timeout would mean CB82 did not take.
2. **RA-201 profiled only the post-assembly stage.**
3. **Its P13-k census was incomplete.** Two per-query `source_face_scope` calls remained inside `validate_final_surface_mesh` itself, against Amendment 33.

## RA-202.2 Findings (macOS scratch, one census process per run)

1. **FMA is not the cause.** An FMA-off build (`-ffp-contract=off`, 9 FMA instructions against 1,885) produced Vase logs and a verdict byte-identical to the default build. Both reached `SelfIntersectingFace` with 192,482 segments, 26,817 cells and 67,829 quads. Their stack samples showed the same phases at the same times. Peak RSS was 0.89 GB.
2. **The HEAD cost profile of the census path** (env-switched timers; 256 s with three Vase runs side by side; about 250 s alone):

   | Section | HEAD | Corrected |
   |---|---|---|
   | Tracing (`build_surface_cell_network`) | ≈60 s | unchanged |
   | Selection (`select_sparse_flow_rep_network`) | 24.1 s | 1.6 s |
   | Arrangement total (`build_surface_cell_complex`) | 105.3 s | ≈10 s |
   | — of which the geometric T-junction scan | 94.5 s | <1 s |
   | Completion | ≈25 s | unchanged |
   | Final validation (pre-optimization) | 31.9 s | ≈9 s |
   | — of which the bow-tie check | 19.7 s | 0.05 s |
   | **Vase run alone** | ≈250 s | **108.5 s** |

3. **Three memory-bound scans and two Amendment 33 sites** make up most of this (DESIGN Amendment 34):
   - **T-junction scan.** For each node occurrence (57,636 nodes) it reads every halfedge (168,902 halfedges, a 216-byte stride), and builds the occurrence's scoped node key for each candidate. Each key recomputes `source_vertex_extent` in O(F). The disassembly of the hot loop matches the fields `sourceFace` at offset 0x24 and `from`/`to` at 0x0c/0x10.
   - **Selection.** For each of 4,047 transactions it recounted the endpoint degrees of the whole active network into a `std::map`.
   - **Bow-tie check.** For each of 68,038 output vertices it walked the whole `edgeIncidence` map.
   - **Amendment 33 sites.** `validate_final_surface_mesh` calls `source_face_scope` once per source face (line 2627) and once per quad corner (line 2730), after already checking the binding on entry. These cost about 2 s.
4. **The fixes are exact.** Each was compared with the original by an env-switched cross-check computing both:
   - over the 893-row gate, 16,543 cross-check lines with **0 mismatches** (T-junction 110 rows, selection 117, bow-tie 158, scope 118);
   - on Vase: 4,047 selection checks, 273,720 scope checks, 68,038 bow-tie vertices and the T-junction count, all matching.
   The verdict and every count are unchanged.
5. **Linux attribution is a hypothesis, tested by TB77/TB78.** The removed scans stream about 10¹¹ bytes or chase 10⁹ map nodes. A CI runner core has several times less memory bandwidth than Apple Silicon, which explains why only Vase was slower. That runner's own timings are the test.
6. **Remaining costs, carried and not blocking.** Of the 108.5 s:
   - tracing ≈60 s, most of it inline in `make_intersection_surface_cell_proposal`;
   - completion ≈25 s;
   - validation ≈9 s, in `SourceProjectionCache::allowed_faces`.

## RA-202.3 Rulings

1. **Withdraw `M6-CP3-CB84-P13-LINUX-VASE-DIAGNOSTIC-TIMING`.** No product stage logging; a scratch stack sample answers "where is the time" (LESSONS §5).
2. **DESIGN Amendment 34.** A pass over a mesh-sized collection reads, for each element, only what that element concerns. A transaction check on an invariant state reads only the net change. Results, visit order within an element, and failure codes are unchanged. The class is **P13-m**.
3. **Exact patches CB85–CB88, one site each; a TB after each pair:**
   - pre-assembly: CB85, CB86, then TB77;
   - validation: CB87, CB88, then TB78.
4. **Linux registration.**
   - TB77 registers both Vase outcomes, because two validation scans remain until CB87/CB88.
   - TB78 registers RED within 600 s: macOS takes 108.5 s, and even 2.4× is 260 s.
   - A timeout at TB78 goes to Review with this probe recipe. It is not an inference about which CB "did not take".
5. **New obligations:**
   - **O27:** `MeshValidator::validate_face_to_face_intersections` tests every pair of faces (O(Q²); 2.3×10⁹ pairs on Vase) with no spatial culling. Vase stops at its first intersection today. Once P13-l is fixed, the full scan runs; the P13-l DEFN must time it.
   - **O28:** nine per-query `source_face_scope` sites remain in the optimizer stage and overlay: `SurfaceMeshOptimizer.cpp` 712, 814, 848, 877, 896, 2054, 2177, 3026 and 3083. They are not on today's Vase path. Measure them when Vase reaches optimization.
   - **O29:** `source_vertex_extent` is recomputed in O(F) per edge key at about 45 call sites in tracing and the arrangement. Together with the tracing proposal cost, this is the next cost candidate.

## RA-202.4 CB85 — `M6-CP3-CB85-P13-ARRANGEMENT-TJUNCTION-FACE-SCAN`

Code + Build, compile only, implementation agent, Linux.

- **Precheck:** `git diff --quiet 2278b8b649b4262fb70a522371ed282655383af5 HEAD -- src include tests benchmarks CMakeLists.txt cmake`.
- **Patch:** [`Architecture_M6_CP3_CB85_P13_Arrangement_TJunction_Face_Scan.diff`](Architecture_M6_CP3_CB85_P13_Arrangement_TJunction_Face_Scan.diff), byte for byte.
  - SHA-256 `5b6d35a4808393d7274d8f574fa4f68eb343946bc3b065f2c1e8992babcac2f7`.
  - 178 lines; keep its 2 single-space context lines.
  - Run `git apply --check`, then `git apply`.

  | Path | Numstat | Result SHA-256 |
  |---|---|---|
  | `include/directional/geometry/SurfaceArrangement.h` | `3 0` | `3e13e5cb2dde969417cee460370b36ac24369769a7b9fffecf8eeb67ecba97b4` |
  | `src/geometry/SurfaceArrangement.cpp` | `25 11` | `6fa5c6c6f2a09219d0bc2d116a76e6d22152d60de76decbfff790065abd16d65` |
  | `tests/SurfaceArrangementRowIdentityTests.cpp` | `96 0` | `d3290d04c9525e48a34cb2b7fe9636346cc9d223a52b4455ed6d72a7583e8173` |

- **Content:**
  - Halfedges are indexed once by source face. Each occurrence reads its own face's list in halfedge order.
  - The occurrence's authority scope (`make_node_key` + `canonical_node_authority_scope`) is made once, at the first candidate. The halfedge contributes only `sourceTopologyRegion.value()`.
  - `SurfaceArrangementDiagnostics::geometricTJunctionHalfedgeVisits` counts the visits.
- **Test** (gate row 894, `directional_surface_cell_completion_tests`): `GeometricTJunctionScanVisitsOnlyHalfedgesOfTheOccurrenceFace`.
  - The fixture is a 30×30 grid crossed by 60 lines.
  - The visit count must equal an independent per-face recount, which is deterministic and involves no timing.
- **Build:** one eight-target Linux Release/static GMP/GMPXX package, `runtimeExecution=false`; run no binary.
- **Outcomes:**
  - success → CB86;
  - precheck, apply, numstat or hash mismatch → `M6-CP3-PLAN-P13-ARRANGEMENT-TJUNCTION-STOP`;
  - infrastructure → `M6-CP3-CB85A-P13-ARRANGEMENT-TJUNCTION-ORCH` (one retry).

## RA-202.5 CB86 — `M6-CP3-CB86-P13-SELECTION-ENDPOINT-NET-CHANGE`

Code + Build, compile only, applied on CB85.

- **Precheck:** the three CB85 result hashes above.
- **Patch:** [`Architecture_M6_CP3_CB86_P13_Selection_Endpoint_Net_Change.diff`](Architecture_M6_CP3_CB86_P13_Selection_Endpoint_Net_Change.diff).
  - SHA-256 `c2a0c3083df29f99b43dd953ca871f02abf7961f731b52d5de5650c0b621ae81`.
  - 167 lines; keep its 7 single-space context lines.

  | Path | Numstat | Result SHA-256 |
  |---|---|---|
  | `include/directional/geometry/FlowRepStrands.h` | `7 3` | `034a306a4de08783b858cac1bf83c10c0298c96d48806c19abb5057a881a8c53` |
  | `src/geometry/FlowRepStrands.cpp` | `23 14` | `0e3997c89339a179f64223cd0c267b203805f3f70d0f554cf636668f5ef2b179` |
  | `tests/FlowRepStrandsPhase15Tests.cpp` | `61 0` | `6810b11d9d7a8e71062ab7b3018a126574d631bb542b1f11590f2a0e3bc70b26` |

- **Content:** `preserves_protected_endpoint_degrees(arcs, active, required)` is replaced by `transaction_keeps_protected_endpoint_degrees(arcs, removed, added, protected)`. It returns true when the net endpoint change is zero at every protected endpoint. A comment at the call site states the invariant.
- **Tests** (gate rows 895–896, `directional_surface_cell_completion_tests`):
  - `TransactionKeepsProtectedEndpointDegreesByNetChange`: removal, substitution and addition at a degree-3 junction.
  - `SelectionChecksEndpointDegreesOfTheTransactionOnly`: 8,000 transactions finish in under 2 s, with 6,000 rejected.
- **Build and outcomes:** as CB85 → TB77. The stop turn is `M6-CP3-PLAN-P13-SELECTION-ENDPOINT-STOP` and the orchestration retry is `M6-CP3-CB86A-P13-SELECTION-ENDPOINT-ORCH`.

## RA-202.6 TB77 — `M6-CP3-TB77-P13-PRE-ASSEMBLY-COST-FULL-GATE-EXEC`

Test + Benchmark, artifact-only, CB86's immutable package.

- **Gate:** [manifest](Architecture_M6_TB77_P13_Pre_Assembly_Cost_Full_Gate_Case_Manifest.tsv), 896 rows, SHA-256 `48ef4743b18683e78d9f740c4eb0e7f249abcab78a4aeac849620e251d9fface`.
  - It is TB76's 893 rows byte for byte, plus GUARD rows 894–896.
  - Ledger v5 `fd433f54…`; harness P8 `78b8002c…`; `SELF_CHECK_PASS cases=896 deferred=81`.
  - Pre-registered **896/896**, membership **977**.
- **Census:** `3af1dc0d…`, unchanged.
  - Cylinder PASS; BunnyRandom P13-e unchanged.
  - **Vase:** either RED `terminal=NotProductionReady:completion detail=SelfIntersectingFace … completedQuads=67829`, or ABNORMAL at 600 s. Both are registered, because the validation scans remain; macOS takes about 150 s, estimated from components.
  - Record the Linux Vase wall time if it completes.
  - Any other verdict, or a RED with other counts, is a mismatch.
- **Outcomes:**
  - match → CB87;
  - mismatch → `M6-CP3-TB77-P13-PRE-ASSEMBLY-COST-FULL-GATE-REV` (Review);
  - infrastructure → `M6-CP3-TB77A-P13-PRE-ASSEMBLY-COST-ORCH` (one retry).

## RA-202.7 CB87 — `M6-CP3-CB87-P13-BOW-TIE-VERTEX-EDGES`

Code + Build, compile only, applied on CB86.

- **Precheck:** the CB86 result hashes.
- **Patch:** [`Architecture_M6_CP3_CB87_P13_Bow_Tie_Vertex_Edges.diff`](Architecture_M6_CP3_CB87_P13_Bow_Tie_Vertex_Edges.diff).
  - SHA-256 `eeef1a515995e032e2a35342a4b92a678c309933845c03102915c1e071f53237`.
  - 134 lines; keep its 1 single-space context line.

  | Path | Numstat | Result SHA-256 |
  |---|---|---|
  | `include/directional/validation/MeshValidator.h` | `15 7` | `0b4025fe47f0e7208490e687fab1884f9c2139b072cec6d88391a0cb83c3c015` |
  | `tests/SourceAuthoritativeMeshValidatorPhase22Tests.cpp` | `81 0` | `14ac6f37155613e4377df0b3a19d80d2f5aa9a80a6fb5c5f30b09c7227ddc57c` |

- **Content:** `validate_bow_tie_vertices` lists each vertex's edge face lists once, whichever end of the edge it is. The adjacency is a set, so the result is unchanged.
- **Tests** (gate rows 897–898, `directional_surface_cell_validation_tests`):
  - `BowTieVertexReadsEdgesNamingItFirstOrSecond`: a closed fan whose centre is the first end of two edges and the second end of two reports no bow-tie; a true bow-tie is reported.
  - `BowTieCheckReadsOnlyTheEdgesOfEachVertex`: a 150×150 quad grid validates, topology only, in under 2 s.
- **Build and outcomes:** as CB85 → CB88. The stop turn is `M6-CP3-PLAN-P13-BOW-TIE-STOP` and the orchestration retry is `M6-CP3-CB87A-P13-BOW-TIE-ORCH`.

## RA-202.8 CB88 — `M6-CP3-CB88-P13-FINAL-VALIDATION-ROW-LABELS`

Code + Build, compile only, applied on CB87.

- **Precheck:** the CB87 result hashes.
- **Patch:** [`Architecture_M6_CP3_CB88_P13_Final_Validation_Row_Labels.diff`](Architecture_M6_CP3_CB88_P13_Final_Validation_Row_Labels.diff).
  - SHA-256 `ee12a33fedc24047a960f38a7ba04b905d54716d80ff8c40b5723614b5636640`.
  - 72 lines; 0 single-space context lines.

  | Path | Numstat | Result SHA-256 |
  |---|---|---|
  | `src/geometry/SurfaceMeshOptimizer.cpp` | `5 2` | `89d52dddb449b6f999aa32ce09e1a2d584c54838e716de0da063dac30449eb6e` |
  | `tests/SurfaceMeshOptimizerPhase22Tests.cpp` | `40 0` | `acb41d05d2a6d2b1c296e65b94ef7025236b95fcf76769b72de17b742da1ced2` |

- **Content:** the two `source_face_scope` calls in `validate_final_surface_mesh` become `bound_source_face_scope`. The binding is already checked on entry, as Amendment 33 requires.
- **Test** (gate row 899, `directional_surface_cell_validation_tests`): `FinalValidationReadsSourceRowLabelsAfterOneBindingCheck`. With 28,800 source faces and 400 output quads, the timed section takes 0.7 s, against a 2 s limit; with M4 it takes 4.7 s.
- **Build and outcomes:** as CB85 → TB78. The stop turn is `M6-CP3-PLAN-P13-FINAL-VALIDATION-LABELS-STOP` and the orchestration retry is `M6-CP3-CB88A-P13-FINAL-VALIDATION-LABELS-ORCH`.

## RA-202.9 TB78 — `M6-CP3-TB78-P13-CENSUS-PATH-COST-FULL-GATE-EXEC`

Test + Benchmark, artifact-only, CB88's immutable package.

- **Gate:** [manifest](Architecture_M6_TB78_P13_Census_Path_Cost_Full_Gate_Case_Manifest.tsv), 899 rows, SHA-256 `9d2c1ec598fea2b95b251fd2e007b7086740e51fb8f6f3ad7ff5671ab09ddb44`.
  - It is TB77's 896 rows byte for byte, plus GUARD rows 897–899.
  - `SELF_CHECK_PASS cases=899 deferred=81`.
  - Pre-registered **899/899**, membership **980**.
- **Census:**
  - Cylinder PASS; BunnyRandom P13-e unchanged.
  - **Vase RED within 600 s:** `terminal=NotProductionReady:completion detail=SelfIntersectingFace traceSegments=192482 arrangementCells=26817 completedQuads=67829 completion=`. macOS takes 108.5 s.
  - Record the wall time and peak RSS (macOS: 1.18 GB).
  - ABNORMAL, or any other verdict, is a mismatch.
- **Outcomes:**
  - match → the Review track continues with P13-l;
  - mismatch → `M6-CP3-TB78-P13-CENSUS-PATH-COST-FULL-GATE-REV` (Review, which re-runs the RA-202 probe recipe);
  - infrastructure → `M6-CP3-TB78A-P13-CENSUS-PATH-COST-ORCH`.

## RA-202.10 Turn sequence

| Step | Turn | Track |
|---|---|---|
| — WITHDRAWN | `M6-CP3-CB84-P13-LINUX-VASE-DIAGNOSTIC-TIMING` | Never applied or compiled; do not apply its preserved patch |
| 1 — NEXT | `M6-CP3-CB85-P13-ARRANGEMENT-TJUNCTION-FACE-SCAN` | Implementation agent, Linux; compile only |
| 2 | `M6-CP3-CB86-P13-SELECTION-ENDPOINT-NET-CHANGE` | Implementation agent; compile only |
| 3 | `M6-CP3-TB77-P13-PRE-ASSEMBLY-COST-FULL-GATE-EXEC` | Implementation agent; 896/896, membership 977; Vase RED or ABNORMAL (both registered) |
| 4 | `M6-CP3-CB87-P13-BOW-TIE-VERTEX-EDGES` | Implementation agent; compile only |
| 5 | `M6-CP3-CB88-P13-FINAL-VALIDATION-ROW-LABELS` | Implementation agent; compile only |
| 6 | `M6-CP3-TB78-P13-CENSUS-PATH-COST-FULL-GATE-EXEC` | Implementation agent; 899/899, membership 980; Vase RED within 600 s |
| 7 (Review, can start now) | `M6-CP3-DEFN-P13-COMPLETED-MESH-ORIENTATION` (P13-l) | Probe DEFN on the RA-202 scratch state; time O27 once orientation passes |
| 8 (Review, parallel) | `M6-CP3-DEFN-P13-SINGULARITY-PORT-COUNT` (P13-e) | Probe DEFN |
| 9 | P13 re-census → O6/O9 → matrix 6/6 → slices → CP3-REV | One slice at a time |

The implementation agent takes steps 1–6 in order, one turn each, and starts a step only after the previous one is verified.

## RA-202.11 Scratch verification (final state = HEAD + CB85–CB88)

| Check | Result |
|---|---|
| Gate, 899-row TB78 manifest | 898/899; only O16 row 283 (macOS) |
| GUARD rows 894–899 | PASS. Timed or counted sections: 894 0.6 s (count equal); 896 0.07 s; 898 0.05 s; 899 0.7 s |
| Ledger v5 (81 deferred rows) | 0/81, unchanged from RA-201's final state; row 365 (Vase) RED in 98.2 s |
| Census | Cylinder PASS 5.8 s; BunnyRandom P13-e unchanged (vertex 49); Vase RED `SelfIntersectingFace`, 192,482 / 26,817 / 67,829, in 108.5 s alone |
| Cross-check gate (probe, all fixes and both computations) | 892/893 (O16), 16,543 lines, 0 mismatches |

Mutants: each fails only its own CB's rows.

| Mutant | Change | Rows that fail |
|---|---|---|
| M1 | full halfedge scan | 894 |
| M2 | whole-network recount | 896 (8.8 s) |
| M2b | added arcs ignored | 895 |
| M3 | every edge per vertex | 898 (8.0 s) |
| M3b | first end only | 897 and 898 |
| M4 | per-query binding | 899 (9.1 s; timed section ≈4.7 s) |

## RA-202.12 Probe scripts (scratch, not committed)

The scripts are in `scratchpad/tb76r/`:
- `make_m.py` writes state0 → A1–A4;
- `make_patch_m.py`, `make_manifests_m.py`, `mutate_m.py` (M1–M4), `gate_x.py` (gate with cross-check counts);
- `vase.sh BLD TAG TIMEOUT INTERVAL [fixture]` runs a census case with `sample` stacks;
- `ratio.py` computes Linux/macOS per-row time ratios;
- `children.py` breaks down a sample tree.

The probe used env switches `PROBE_M_FIX` (bits 1/2/4/8 for the fixes; 16/64/128/256 for the cross-checks) and `PROBE_M_TIME`. It has been removed from the scratch tree.

## Review closeout

| Check | Result |
|---|---|
| Scope | Review only. No product, test, fixture, selector, benchmark or build file changed in the repository; scratch probes only. The four `.diff` files and two manifests are documents for later turns |
| Exact patches | Four files re-hash to the stated SHA-256. They apply as a chain on a clean HEAD worktree, and every result hash matches |
| Manifests | TB76 prefix byte-identical; `SELF_CHECK_PASS` for 896 and 899 cases with ledger v5 (deferred 81), harness P8 |
| Decisive claims re-derived | TB76 artifacts re-downloaded and their ZIP SHA-256 matched; Linux/macOS row ratios computed; Vase log prefixes identical on both platforms |
| Accepted selector prefix | n/a: no selector change |
| Standing state | CP2 491/491; stable 66/17/49, debt 1; ledger v5 81 deferred; selector497 and CP3 unpromoted |
| New obligations | P13-m (Amendment 34, CB85–CB88); O27, O28, O29 |
| Scratch state left | `wt61`/`bld61` = HEAD + CB85–CB88 (final state, all gate binaries built); `bld55n` = FMA-off build of the same source (producer tests only) |
