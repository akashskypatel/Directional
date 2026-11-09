# RA-207 — Review of the O32a seed Review: the mechanism holds; CB92 becomes an exact, capability-preserving patch (2026-11-05)

**Reviewed turn:** `M6-CP3-DEFN-P13-ROW-PERMUTATION-SEEDS` (ChatGPT, closed `cb2c68539`). Its records:
- [WIP](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_DEFN_P13_Row_Permutation_Seeds_WIP_20261105.md");
- [producer scratch result](Architecture_M6_CP3_DEFN_P13_O32a_Vase_Producer_Scratch_Result_20261105.md);
- [CB92 plan](Architecture_M6_CP3_CB92_P13_Source_Vertex_Fan_Seed_Identity_Plan_20261105.md);
- scratch branch `origin/scratch/p13-o32a-seed-review-20261105`.

This re-entry reviews them. It keeps the successor ID `M6-CP3-CB92-P13-SOURCE-VERTEX-FAN-SEED-IDENTITY` and replaces the plan with an exact patch.

**Source:** HEAD `cb2c68539` (CB91 product source; TB81 899/899 MATCH).

**Scratch build:** `bld55n`, FMA-off clang/libc++ static. `diff -rq` against `git archive HEAD` showed no difference before the patch. The census probe TU has `PROBE_PERMUTE_FACES` (RA-205). Scratch-only `PROBE_SEED_DIGEST` and `PROBE_MULTIFAN_LOG` instrumentation was in the scratch copy and is not in the patch.

## RA-207.1 What the O32a Review got right (independently re-derived)

- **The mechanism.**
  - `vertex_point` places a vertex seed in `incident[vertex].front()`, the lowest source-face row.
  - `initialize_seed` de-duplicates on (face row, barycentrics).
  - So whether a vertex seed collides with a rail seed at the same vertex depends on row order. Vase gives 1,456 / 1,460 / 1,458 / 1,455 seeds. RA-205 measured 1,456 / 1,461.
- **The scratch remedy works.** Placing vertex-origin seeds by typed `SourceVertexEntityIdentity` fan, at the fan's minimum `SourceProjectionChart`, makes the seed set row-invariant.
  - Re-derived here on a fresh build: **1,416 seeds** in four orders, with an identical sorted digest over position, provenance and source id (`8b4ef97c…`).
  - Trace counts are **189,462** and strand counts **30,989** in all four orders.
  - Completed quads still vary (67,750 / 67,771 / 67,773 / 67,786). That is O32e (completion ownership repair), as RA-205 named.
- **The Vase fan audit is correct.** Every Vase vertex has one intrinsic fan.
- **The invalid one-sample rail control was correctly retracted.**

## RA-207.2 Defects

1. **The CB92 plan is not an exact patch** — the third Review in a row to give the implementation agent a design instead (TB80-REV's CB91 was the second).
   - It describes a redesign across five seed classes and a new fail-closed terminal outcome "through the existing `SurfaceCellNetwork`/pipeline outcome".
   - It then says: "if no truthful existing failure reason supports it, STOP for a … Review amendment".
   - A turn whose own spec says it may be unimplementable is monolithic by construction.
2. **Fail-closed on multi-fan vertices is a capability regression, and the case it targets is not measured.**
   - Today a seed request on a vertex split by a hard barrier produces one seed, in a row-chosen fan. The plan turns that input into a terminal failure.
   - The code's own precedent goes the other way: a hard-rail sample is seeded in **both** incident face charts "instead of depending on the arbitrary provenance face" (`SurfaceCellTracing.cpp`, rail seeding).
   - A barrier blocks traces, so a seed in one fan cannot cover the other. Seeding each unseeded fan is the coverage-complete, row-invariant choice: a typed canonical rule, as DESIGN §10.1 asks.
   - The plan calls that "unauthorized duplication". It is the same both-sides rule already applied to rails.
3. **The gate impact was never measured.** No scratch gate ran with the remedy. Measured here (RA-207.4):
   - **no vertex-origin request in all 899 gate rows lands on a multi-fan vertex** (positive control: the new split test logs 2 events);
   - the chart graph is never unavailable.

   So the fail-closed path would have shipped untested by the gate. A capability loss would have stayed invisible until a feature-bearing input arrived.
4. **The falsifier design is not gateable.** "Four consistent Vase face/field permutations" as a product test means four full Vase pipelines (about 100–270 s each). The mechanism needs a millisecond synthetic test whose legacy outcome depends on row order (RA-207.3).
5. **Residual, not owned by the plan.** `AdaptiveSeedCandidate::operator<` still breaks distance ties by face row. RA-205.4 showed it does not fire on Vase. It is still a §10.1 non-conformance; it is recorded under O32a, to fix when that code is next touched.

## RA-207.3 CB92 — exact patch (`M6-CP3-CB92-P13-SOURCE-VERTEX-FAN-SEED-IDENTITY`, ID kept)

- **Precheck:** `git diff --quiet 96ee281a40920f21eb911880a3b2c458ef4f0563 HEAD -- src include tests benchmarks CMakeLists.txt cmake` (the CB91 source).
- **Patch:** [`Architecture_M6_CP3_CB92_P13_Source_Vertex_Fan_Seed_Identity.diff`](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_CB92_P13_Source_Vertex_Fan_Seed_Identity.diff").
  - SHA-256 `c377b206c195613b045b0f5a431df5dc31e553035343b567cdeb2ba0751834fa`.
  - 285 lines; **keep its 5 single-space context lines**.

  | Path | Numstat | Result SHA-256 |
  |---|---|---|
  | `src/geometry/SurfaceCellTracing.cpp` | `77 15` | `9e9b979f0976f3c1714e1dbcddd4d973b21f3268e443cff7518bbd4a987a4c7b` |
  | `tests/SurfaceCellREPackageTests.cpp` | `141 0` | `a169667c6c6705be547b257295e6d9eb5ea2d1f933f6958370c7e806cbb28e90` |

- **Product content.** Changes are confined to `generate_deterministic_surface_seeds`.
  - **Where it applies:** with source authority and an available `SourceChartTransitionGraph`, built on the existing combined barrier set.
  - **Which seeds:** every seed named by a source vertex — field-aligned or legacy singularities, relief critical points and roots, relief-region representatives, separatrices and anchors.
  - **The rule:** each such seed resolves the vertex's incident faces to typed fans. **Each fan not already holding a seed gets one, at its minimum canonical chart.**
  - **What counts as held:** fans already holding a rail or earlier vertex seed, known by typed identity.
  - **Unchanged:** rail seeding; provenance and source ids; adaptive coverage. Without authority, the legacy `vertex_point` path keeps its documented contract.
  - **What the patch adds:** no exception, no new type, no new terminal outcome.
- **Tests** (producer binary; new gate rows 900–901):

  | Row | Test | What it checks |
  |---|---|---|
  | 900 | `SurfaceCellTracingPhase14.VertexSeedsFollowSourceVertexFansNotFaceRows` | A boundary-rail sample on vertex 1 in face (1, 5, 4), with relief requests on vertices 1 and 4, in two row orders. The rail's face is first for vertex 1 in one order only. Asserts no relief seed on vertex 1 (its fan holds the rail seed), exactly one on vertex 4, and identical seed multisets (position, provenance, source id) in both orders. **Legacy fails:** one relief seed on vertex 1 in one order, and different multisets |
  | 901 | `SurfaceCellTracingPhase14.VertexSeedsCoverEachHardBarrierFanInBothRowOrders` | Vertex 0 of the two-triangle grid, coalesced or split by hard barrier (0, 3). Asserts 1 or 2 relief seeds, one per distinct typed fan, with the same fan sets in both orders. **Legacy fails:** 1 seed when split |

- **Verified in scratch:**

  | Check | Result |
  |---|---|
  | Local 901-row gate | **900/901** (only row 283, O16); rows 900–901 PASS |
  | Census, Plane / MultiFaceSeam / CloseSheets / Cylinder | **unchanged**, every digest item |
  | Census, BunnyRandom | unchanged (stops before tracing) |
  | Census, Vase | changes from `tracing` on: 189,462 traces, 30,989 strands, 26,817 cells, 67,750 quads; still RED `SelfIntersectingFace` |
  | Four-order Vase | seed digest identical; trace and strand counts identical |
  | GCC 16 `-Wall -Wextra -fsyntax-only` | clean |
  | Patch on a clean worktree at `cb2c68539` | applies and reproduces the tree |

- **Build:** one eight-target Linux Release/static GMP/GMPXX package, `runtimeExecution=false`.
- **Routes:**
  - mismatch → `M6-CP3-PLAN-P13-SOURCE-VERTEX-FAN-SEED-STOP`;
  - infrastructure → `M6-CP3-CB92A-P13-SOURCE-VERTEX-FAN-SEED-ORCH`.

## RA-207.4 Measurements

| Measurement | Result |
|---|---|
| Multi-fan census (`PROBE_MULTIFAN_LOG`, full 899-row gate) | 0 vertex-origin requests on multi-fan vertices; 0 graph-unavailable events. The positive control (row 901, split case) logs 2 |
| Vase, four orders (original + `PROBE_PERMUTE_FACES` = 1, 2, 4) | seeds 1,416 / 1,416 / 1,416 / 1,416 (digest `8b4ef97c…` all); traces 189,462 ×4; strands 30,989 ×4; cells 26,817 ×4; quads 67,750 / 67,771 / 67,773 / 67,786 |
| Vase stage digest vs post-CB90 reference | identical through `global-conformity-baseline` (`895d709f…/299`); differs from `tracing` (`2317b75c…/189462`) onward |

## RA-207.5 TB82 — `M6-CP3-TB82-P13-SOURCE-VERTEX-FAN-SEED-FULL-GATE-EXEC`

- **Package:** the immutable CB92 package, artifact-only.
- **Gate:** [`Architecture_M6_TB82_P13_Vertex_Fan_Seeds_Full_Gate_Case_Manifest.tsv`](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_TB82_P13_Vertex_Fan_Seeds_Full_Gate_Case_Manifest.tsv").
  - 901 rows, SHA-256 `9fbf329167cbe84698d5a08eda6e5374200c7729a5f0f1e4292836227902f878`.
  - TB78's 899 rows byte for byte, plus GUARD rows 900–901.
  - `SELF_CHECK_PASS cases=901 deferred=81` with ledger v5.
  - **901/901**, membership **982**.
- **Census:** manifest `3af1dc0d…`.
  - Cylinder PASS.
  - BunnyRandom P13-e at vertex 49.
  - Vase RED `SelfIntersectingFace` within 600 s.
  - Trace segments, arrangement cells and `completedQuads` are **recorded, not pinned**: CB92 changes Vase tracing, and Linux has not observed the new values.
- **Pinned digest falsifiers,** all Linux-observed:
  - gate rows 795, 796, 797 and 864, and census rows 1 (Cylinder) and 2 (BunnyRandom), byte-identical to TB81;
  - census row 3 (Vase) byte-identical to TB81 **through `global-conformity-baseline`**. The items from `tracing` on are recorded.
- **Routes:**
  - match → the Review track (RA-207.6);
  - mismatch → `M6-CP3-TB82-P13-SOURCE-VERTEX-FAN-SEED-FULL-GATE-REV` (Review, Claude, scratch build);
  - infrastructure → `M6-CP3-TB82A-P13-SOURCE-VERTEX-FAN-SEED-ORCH`.

## RA-207.6 Trajectory and turn sequence

- **O32a closes when TB82 matches.** Seeds are row-invariant and so are trace and strand counts.
- **O32 continues downstream.**
  - O32b/c, the content of traces and strands, need a row-invariant semantic digest. Counts are already equal.
  - O32d, the canonical cell key.
  - O32e, completion's ownership-repair tie and budget, is the remaining count-level dependence (67,750–67,786).
- **P13-l (Vase orientation) starts on the post-CB92 state.** Its verdict is the same in every order.

| Step | Turn | Track |
|---|---|---|
| 42J — COMPLETE | `M6-CP3-CB91-P13-FINAL-VALIDATION-BINDING-COST-EVIDENCE` | Implementation agent (`96ee281a4`) |
| 42K — COMPLETE (MATCH) | `M6-CP3-TB81-P13-FINAL-VALIDATION-BINDING-FULL-GATE-EXEC` | 899/899, seven digests pinned |
| 43 — Review COMPLETE (re-entered) | `M6-CP3-DEFN-P13-ROW-PERMUTATION-SEEDS` (O32a) | ChatGPT, reviewed by RA-207 |
| 43A — NEXT | `M6-CP3-CB92-P13-SOURCE-VERTEX-FAN-SEED-IDENTITY` | Implementation agent; RA-207.3, exact |
| 43C | `M6-CP3-TB82-P13-SOURCE-VERTEX-FAN-SEED-FULL-GATE-EXEC` | Implementation agent; RA-207.5 |
| 43B (Review) | `M6-CP3-DEFN-P13-COMPLETED-MESH-ORIENTATION` (P13-l) | Claude, scratch build, post-CB92 |
| 44 / 44A (Review) | P13-e; O31 | Claude, scratch build |
| 44B (Review) | O32e first (the count-level dependence), then O32d, O32b/c | Claude, scratch build |
| 44C (Review) | O33 chart-face per-quad cost | Claude, scratch build |
| 45 | P13 re-census → metamorphic census rows → matrix 6/6 → slices → CP3-REV | One slice at a time |

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | TB78 899-row prefix of the new 901-row manifest is byte-identical (`9d2c1ec5…`); harness self-check PASS |
| Decisive claims independently re-derived | Mechanism read at source. Four-order seed, trace and strand invariance on a fresh build. Multi-fan census of the whole gate with a positive control. Census digests. Full gate |
| Non-vacuity checked | Both new tests FAIL on the legacy `SurfaceCellTracing.cpp` and PASS on CB92. The multi-fan logger fires on the split control |
| Prior obligations discharged/carried | O32a → CB92/TB82. O32b–e, O33, O30b, O31, P13-l, P13-e, O27–O29, DR1/DR3 carried. AdaptiveSeedCandidate tie recorded |
| Stable accounting | 66 / 17 / 49, debt 1; CP2 491/491; selector497 and CP3 unpromoted |
| New candidates/obligations recorded | O32a residual (adaptive tie); none new otherwise |
| ORIENTATION currency line | `M6-CP3-DEFN-P13-ROW-PERMUTATION-SEEDS` re-entered, RA-207 |
| ORIENTATION §3 / §4 / §7 / §8 | §7 updated; §8 adds the both-sides rule; §3 and §4 unchanged |
| CHANGELOG | RA-207 entry |
| ROADMAP | n/a |
| Selector manifest | New 901-row TB82 manifest (two GUARD rows), self-checked |
| LESSONS | Measure the gate impact of a policy before freezing it, and prefer the codebase's existing symmetric rule over a new failure mode |
| Consolidation under CLEAN_UP_POLICY | The O32a records are retained, each with a review line; the CB92 plan is marked superseded |
| Successor frozen | CB92 exact (RA-207.3), TB82 (RA-207.5) |
| Turn boundary held | No product, test, fixture or build source changed in the repository; the patch is a committed `.diff`; the manifest is new. Scratch probes only |
| review_check.py boundary | Run before the push |
| `STATUS` lifecycle maintained | Re-entry beacon pushed (Resumed at 2026-11-05T14:03:47Z); COMPLETE with Successor CB92 as the final write |
| Pushed to origin, branch in sync | Confirmed with `git status -sb` after the push |
