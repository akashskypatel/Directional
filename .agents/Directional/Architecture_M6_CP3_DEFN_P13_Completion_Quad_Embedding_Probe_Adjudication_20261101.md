# RA-196 — P13-g completion quad embedding: probe adjudication; exact CB73/CB74/CB75, TB69 (2026-11-01)

**Turn:** `M6-CP3-DEFN-P13-COMPLETION-QUAD-EMBEDDING` (Review/Definition), reopened at `fe29a3554`. The [static decision](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_DEFN_P13_Completion_Quad_Embedding_Review_Decision_20261101.md") (ChatGPT, `6b6048966`) ran no binary. It left its central question open: is patch 1200's boundary malformed (branch A), or is the split inadmissible (branch B)? It then froze a CB73 that would investigate, branch and possibly stop. RA-195.7 gave this DEFN one exit: name the owner, close `detail=None`, and produce an exact patch. RA-196 meets that exit with probes on current source. It replaces the decision's CB73 with three exact patches and a TB.

Source at review: HEAD `fe29a3554`, fast-forwarded to `b7eb717b4` at closeout. `src include tests benchmarks CMakeLists.txt cmake` are byte-equal to CB72 `7b85b450bc98abfb65db511fdcd524eb11f537f8` (TB68 package `13093439789`, 873/873) at both. Only documents and orchestration landed after TB68. A CB73 attempt under the superseded scope started at 2026-11-01T21:39:52Z (`60bc9ac84` … `b7eb717b4`, resumed 22:02:58Z). It changed only `STATUS` and is superseded: CB73 restarts from RA-196.9, whose precheck still holds.

## RA-196.1 Findings on the decision

1. **F1 — exit not met, and neither branch holds.** The decision says "the existing record does not distinguish those two hypotheses", and it hands that question to a Code + Build turn. Two probes settle it (RA-196.2):
   - **Branch A is false.** Patch 1200 lies entirely in source face 264. In that face's barycentric chart (an affine image, so incidence and orientation are exact) its 8-node boundary is a simple counter-clockwise polygon. It has two reflex corners (9073, 9076) and one straight corner (59254, the exact midpoint of 9076–9062).
   - **Branch B, as stated, would not fix it.** The decision wants more "topology-distinct odd-span separator/strip pairings", each tested for "simple embedding and orientation" before commit. The real defects are listed under F2 and F3.
2. **F2 — the validator the decision protects is unsound.** The decision says "do not … relax `completed_quads_have_simple_embedding`", so it treats that function as the oracle. But the check projects each quad onto its *own* Newell plane, so it cannot see orientation: a folded quad passes.
   - Of the 12,452 boundary-only completions that Vase's first pass accepts, 2,552 (20.5 %) disagree with the source surface: 1,809 contain a reversed quad and 743 a quad more than 60° off the source normal.
   - Exactly, in single-face patches: 29 accepted completions are folded.
   - The acceptance test's independent oracle checks combinatorial winding, zero area and manifoldness, not geometric folds (`tests/support/SurfaceCellProductOracle.h`). A Vase "PASS" could therefore have contained folded quads.
   - Branch B, run against this validator, would have accepted the first fold it produced.
3. **F3 — the producer's search is incomplete.** `append_balanced_boundary_quadrangulation` always splits at span 3 from `n/4`. Over all 16 rotations and reversals it reaches only the 4 parallel-chord quadrangulations of an octagon, out of 12. Patch 1200's only 2 embedded quadrangulations are fans (three quads sharing an apex), which it never reaches.
   - An exact DP over sub-polygons, with the source-orientation predicate, finds an embedded quadrangulation for **every** one of the 12,524 boundary-only patches in Vase's first pass. That holds under the sign test and under every margin up to 60°.
   - So no interior (Steiner) vertex is needed for this class, and no new producer.
4. **F4 — the terminal hides the rest of the pass.** Descriptors are processed in `domainIdentity` order (`PatchDescriptor.cpp:1874`), and the stage reports only the first failure. Patch 1200 is the first of **150** failed patches at CB72:
   - 72 boundary-only (pattern/bounded) bow-ties;
   - 73 closed-form grids (72 bow-tie, 1 degenerate normal);
   - 5 descriptors rejected as `side-count-unsupported`.

   The decision's TB69 expectation was "Vase PASS, or a newly named *earlier* producer RED". It cannot be met. With CB73–CB74, Vase moves to the next failure in the same pass: patch 4, a closed-form bow-tie. That failure is later in order, outside P13-g's class, and is P13-h.
5. **F5 — monolithic CB with an internal stop rule.** CB73 bundled four things: a new witness product, an A/B investigation with "stop and return to Review", a producer rewrite and a terminal change. It had no patch, numstat or result hashes. Implementation agents receive exact patches only (RA-172), and a CB with an embedded investigation has no single verifiable outcome.
6. **F6 — the proposed terminal fix misattributes.** "Pass through `firstCompletionEmbeddingFailure`" names the first *embedding* failure, not the first failure. When an earlier patch fails some other way, the terminal would name a decision that did not end the run (Amendment 19).
   - The truthful terminal detail is the typed completion failure kind, `PatchCompletionRejected` here.
   - The per-patch reason stays in `completion=`.
7. **F7 — reversed variants were never embeddable.** Variants `n … 2n−1` of the pattern and bounded backends (and 3–5 of the transition template) reverse the cycle. Their quads wind against the patch boundary and its shared halfedges. CB72 would accept such a completion if its quads were not bow-ties. No accepted Vase completion used one, but nothing prevented it.
   - Under Amendment 28 every reversed variant fails as an embedding failure.
   - Dropping them from `completion_variant_count` is cleanup (O22).
8. **F8 — what stands.**
   - Generated-vertex projection is not the owner: the bounded backend generates no vertices.
   - Ownership reconciliation is not reached.
   - The `detail=None` diagnosis is correct.
   - The scope limits stand: no epsilon relaxation, no fallback or recovery route, no selector change, no P13-e work.

## RA-196.2 Probes (macOS, scratch, diagnostic only)

Build `bld61` (Release `-O3`, GMP), source byte-equal to CB72. Each Vase run is one fresh process of `UniformPhaseFront/SurfaceCellDesignAcceptance.ProducesDirectSourceAuthoritativePureQuadOutput/Vase`. The probe switch `PROBE_P13G_MODE` lives in a scratch copy of `PureQuadCompletion.cpp`:
- `0`: CB72;
- `1`: Amendment 28 orientation check only;
- `2`: `1` plus an extra final variant that runs the exhaustive search;
- `3`: `1` plus the exhaustive search inside each forward variant (the CB74 design).

`PROBE_P13G_TRACE` prints every failed descriptor of every completion pass. Offline audits (Python, exact `Fraction` arithmetic for single-face charts) read a dump of every boundary-only completion in the first pass: 19,076 records, 12,524 patches.

| Probe | Result |
|---|---|
| CB72 (mode 0) | Vase RED `completion`, `detail=None`, `completion=InvalidCompletionQuadEmbedding;patch=1200;backend=bounded-combinatorial;variant=15;localQuad=2;classification=bow-tie-intersection`; 145 s. Same locus as TB68 on Linux (the macOS corner 59254 is Linux 59257, a representation handle) |
| Patch 1200 boundary, exact chart of face 264 | Simple, counter-clockwise; reflex at 9073 and 9076, straight at 59254. Sides `[1,1,1,3,1,1]`, `side-inequality`, so it takes the bounded fallback |
| Patch 1200, all 12 quadrangulations, exact | 2 embed, both fans: {(9056,9057,9073,9061), (9073,59254,9062,9061), (9073,9082,9076,59254)} and {(9056,59254,9062,9061), (9056,9057,9073,59254), (9073,9082,9076,59254)}. The 16 variants reach only the 4 parallel-chord ones, none embedded |
| Accepted first-pass boundary-only completions vs. the local source normal (sum of corner-face unit normals) | 12,452 accepted (11,413 bounded, 1,039 pattern). Reversed quad: 1,506 + 303. Beyond 60°: 715 + 28. Exact single-face subset: 29 folded, 332 with a straight (180°) corner |
| Angle of each quad's vector area to the source normal (all 85,301 quads tried; 23 have a zero normal) | 58,888 within 5°; 11,462 at 175–180° (true folds); a thin continuum between. Every corner-face normal is within 15° of its quad's reference, so the surface is smooth at quad scale. Quads near 90° are edge-on slivers whose sign is noise; sign-only and polygon-normal tests disagree on 57 such quads |
| Exact DP, every first-pass boundary-only patch | An embedded quadrangulation exists for 12,524/12,524 under the sign test and under every bound tested, from 90° down to 60° (cos 0, 0.05, 0.1, 0.2, 0.3, 0.5). DP over all patches: 1.25 s in Python |
| Mode 1 (orientation only), trace | 545 failed descriptors. 252 more boundary-only completions are now rejected as folded or edge-on, and 171 closed-form grids too. First: patch 1200, `source-orientation-mismatch` |
| Mode 3 (orientation + search), trace | **229** failed descriptors, **none boundary-only**: 171 closed-form `source-orientation-mismatch`, 53 closed-form bow-tie, 5 `side-count-unsupported`. Vase RED at patch 4 (`closed-form`, variant 0, `bow-tie-intersection`, source faces 155/248) in 147 s uncontended. One completion pass, no repair pass reached |
| Clean CB73 + CB74 + CB75 build (exact patches, no probe code) | The 5 new tests pass. `PureQuadCompletionPhase18.*` and `PatchDescriptorMilestoneE.*` show 97 passes and exactly CB72's 11 pre-existing off-gate `PatchDescriptorMilestoneE` failures (RA-170 baseline). **Vase RED `terminal=NotProductionReady:completion detail=PatchCompletionRejected`**, `completion=InvalidCompletionQuadEmbedding;patch=4;backend=closed-form;variant=0;localQuad=0;classification=bow-tie-intersection`, in 210 s while the ledger ran. Cylinder PASS (8 s); BunnyRandom P13-e unchanged. The chain CB73 → CB74 → CB75 applies to `fe29a3554` and reproduces every result SHA-256 |
| Gate (TB69 manifest, 878 rows) | **877/878**, only row 283 (O16, macOS LegacyInteger). Against RA-195's CB72 gate (872/873), no shared row changes; new rows 874–878 PASS. (A first run from a directory of copied binaries failed 140 rows, because tests read data relative to the build directory. It was rerun in place.) |
| Ledger v5 (81 rows) | 0/81 PASS, as at CB72; no row changes its verdict or first-failure token. Row 365 (Vase) is RED in 209 s under load (164 s at CB72) |
| Mutants (each rebuilt; the five new tests run) | M1, orientation check removed: rows 874, 875 and 876 fail. M2, sign only (no 60° margin): 874. M3, no search (balanced split only): 876 and 877. M4, search ignores the source orientation: 876. M5, exhaustion not reported: 877. M6, kind name collapses to `None`: 878. Restored: all pass. The CB73-only and CB73 + CB74 states pass `-fsyntax-only` for `PureQuadCompletion.cpp`, `PatchDescriptor.cpp`, `RemeshPipeline.cpp` and the test file |

The search runs only on forward rotations, which all share one set of quadrangulations. A first version also ran it on reversed variants. Its own test then showed that every reversed variant reports "no embedded quadrangulation", which is true only of the reversed winding (F7). The CB74 below keeps reversed variants on the historical split, so the validator rejects them as embedding failures, and reports `NoEmbeddedQuadrangulation` only from a forward rotation.

## RA-196.3 Rulings

- **DESIGN Amendment 28** (added): a completed quad must agree with the source surface, and a boundary-only completion searches every quadrangulation before failing.
  - **The predicate.** A quad is embedded only if it is simple in its own Newell plane (existing checks, unchanged and in the same order) and its vector area lies within 60° of the local source orientation. The local source orientation is the sum of the unit normals of the source faces under its four corners.
  - **One owner.** `quad_embedding_failure` is the single predicate. The validator `completed_quads_have_simple_embedding` uses it whenever it has the source matrices, and so does every producer that chooses quads by geometry.
  - **Why 60°.** The margin is structural, not a quality bound: it rejects folds and edge-on slivers, whose sign is numerical noise.
  - **The search.** The pattern and bounded backends keep the historical balanced split whenever all its quads embed. Otherwise they search every quadrangulation of the same forward cycle by diagonals: a DP over sub-polygons that takes the first admissible split in index order.
  - **Reversed variants.** A reversed variant keeps the split, and the validator rejects it.
  - **No embedding.** If no quadrangulation embeds, the patch fails with the typed `NoEmbeddedQuadrangulation`, which no rotation can change.
  - **Terminal detail.** The completion terminal reports the typed completion failure kind as its detail (Amendment 19).
- **CB73** (exact, RA-196.9) adds the predicate and the validator check. **CB74** (exact, RA-196.10) adds the search and the typed reason. **CB75** (exact, RA-196.11) adds the terminal detail.
  - Each is compile-only, with its own GUARD tests and a mutant that fails them.
  - One TB runs after all three (TB69). A TB after CB73 alone would register a Vase verdict that CB74 immediately changes.
- **P13-h** (new, next Review): closed-form bilinear grids that do not embed. 224 descriptors in Vase's first pass after CB74: 53 bow-tie and 171 folded. Of these, 73 already fail at CB72.
  - Owner candidates: the bilinear target in `complete_rectangular_grid`, or the projection of its interior vertices.
  - DEFN: `M6-CP3-DEFN-P13-COMPLETION-GRID-EMBEDDING`, a probe DEFN that can start now on the scratch build.
- **P13-i** (new, Review): 5 Vase descriptors with fewer than three sides are inadmissible (`side-count-unsupported`) at every source state probed. To be classified in the P13-h DEFN, by the same per-descriptor trace; it may need its own DEFN.
- **O21** (new, quality, non-blocking): the search takes the *first* embedded quadrangulation, not the best. Quads with a straight (180°) corner are accepted (332 in the exact single-face subset). This is a §2.1 item 10 quality criterion, owned by the M7 quality gates.
- **O22** (new, cleanup, non-blocking): reversed variants can never embed under Amendment 28, so they only cost attempts. Drop them from `completion_variant_count` in a later cleanup slice.
- The decision's CB73 scope is superseded. The turn ID `M6-CP3-CB73-P13-COMPLETION-EMBEDDING` is kept for the exact validator patch, and TB69 keeps the decision's ID.

## RA-196.4 CB73 — `M6-CP3-CB73-P13-COMPLETION-EMBEDDING`

Code + Build, compile only, implementation agent, Linux.

- **Precheck:** `git diff --quiet 7b85b450bc98abfb65db511fdcd524eb11f537f8 HEAD -- src include tests benchmarks CMakeLists.txt cmake`.
- **Patch:** RA-196.9 verbatim plus a trailing newline. Keep its 5 single-space context lines. SHA-256 `4020fad1d3a16c536504d0a3d58e11522dfd99688111bdc09e77b3a6885fabf1`; `git apply --check`, then apply.
- **Numstat and result SHA-256:**

  | Path | Numstat | Result SHA-256 |
  |---|---|---|
  | `include/directional/geometry/PureQuadCompletion.h` | `10 0` | `38ef15f3fb204516bce022044da92d35e550065251d91597ae66a6617dc479d5` |
  | `src/geometry/PureQuadCompletion.cpp` | `124 63` | `33de77c38ab5e71de44aa36ecd1969472062267a697e196bc18d9fa2b73ec492` |
  | `tests/PureQuadCompletionPhase18Tests.cpp` | `73 0` | `5ccbd88f772c0ba8008c88fd256c128baa90cd8fa4d178d02abc8ce982db1267` |

- **Content:**
  - `PureQuadEmbeddingFailureKind::SourceOrientationMismatch` (`source-orientation-mismatch`).
  - `source_orientation_normal`.
  - `quad_embedding_failure`, the existing per-quad geometry moved verbatim and followed by the 60° check. It is declared in the header for tests.
  - The validator takes the source matrices; `complete_pure_quad_patch` passes `options.sourceVertices` and `options.sourceFaces`. Without them only the existing checks run, as before.
- **Tests (gate rows 874–875):**
  - `QuadEmbeddingRejectsFoldedAndEdgeOnQuadsAgainstTheSourceNormal`: 0° and 55° pass; 65°, 90° and 180° fail; no source means no orientation check; a bow-tie keeps its classification.
  - `CompletionRejectsQuadsFoldedAgainstTheSourceSurface`: the 2×2 plane patch traversed clockwise is rejected `SourceOrientationMismatch`, while the counter-clockwise patch is produced.
- **Build:** one eight-target Linux Release/static GMP/GMPXX package, `runtimeExecution=false`, no binary runs.
- **Outcomes:**
  - Exact → CB74.
  - Mismatch → `M6-CP3-PLAN-P13-COMPLETION-EMBEDDING-STOP`.
  - Infrastructure → `M6-CP3-CB73A-P13-COMPLETION-EMBEDDING-ORCH` (one retry).

## RA-196.5 CB74 — `M6-CP3-CB74-P13-COMPLETION-QUADRANGULATION-SEARCH`

Code + Build, compile only.

- **Precheck:** the source differs from `7b85b450…` in exactly CB73's three paths, each at its RA-196.4 result SHA-256.
- **Patch:** RA-196.10 plus a trailing newline. Keep its 5 single-space context lines. SHA-256 `b2c6a251c915371845d93c05d753cbf7ad5ed92936cf0fa66879d0dd307c7b4b`.
- **Numstat and result SHA-256:**

  | Path | Numstat | Result SHA-256 |
  |---|---|---|
  | `PureQuadCompletion.h` | `3 0` | `5580f55294047e168624b3e661c71083c53fc15920c1be89ed00e77c6681da14` |
  | `PureQuadCompletion.cpp` | `146 7` | `28a26b80f4b0b13605f691ebf15dd91191e51496be4f11db84b64f2f6adbad9b` |
  | `tests/PureQuadCompletionPhase18Tests.cpp` | `131 0` | `c433da17e3fd8f03bf3359c84fb87a56809da853e62d6b3e024e2e6d6c97ccf8` |

- **Content:**
  - `PureQuadPatchRejectReason::NoEmbeddedQuadrangulation` (`no-embedded-quadrangulation`).
  - `append_embedded_boundary_quadrangulation`: keep the balanced split if it embeds; otherwise run the exhaustive memoized DP on forward rotations, while reversed variants keep the split.
  - `complete_pattern` and `complete_bounded` take the source matrices and an `exhausted` flag; `complete_pure_quad_patch` reports the typed reason.
- **Tests (rows 876–877):**
  - `BoundedCompletionFindsAnEmbeddedQuadrangulationOfAConcaveBoundary`: patch 1200's chart scaled to integers. Every forward variant produces 3 quads that an independent exact oracle (positive area, no crossing) accepts, and every reversed variant is rejected as an embedding failure.
  - `BoundedCompletionReportsABoundaryWithNoEmbeddedQuadrangulation`: a simple hexagon whose 3 quadrangulations all contain a bow-tie is rejected `NoEmbeddedQuadrangulation` on every forward variant.
- **Outcomes:**
  - Exact → CB75.
  - Mismatch → `M6-CP3-PLAN-P13-COMPLETION-QUADRANGULATION-STOP`.
  - Infrastructure → `M6-CP3-CB74A-P13-COMPLETION-QUADRANGULATION-ORCH`.

## RA-196.6 CB75 — `M6-CP3-CB75-P13-COMPLETION-TERMINAL-DETAIL`

Code + Build, compile only.

- **Precheck:** the source differs from `7b85b450…` in exactly the three CB73/CB74 paths, each at its RA-196.5 result SHA-256.
- **Patch:** RA-196.11 plus a trailing newline. Keep its 1 single-space context line. SHA-256 `d1f5652a979c414e53f11f8b62a71f9d528a79428c0067f2b4946ad71844d933`.
- **Numstat and result SHA-256:**

  | Path | Numstat | Result SHA-256 |
  |---|---|---|
  | `include/directional/geometry/PatchDescriptor.h` | `23 0` | `e9c090df552cd227c814756a853bf0fa348a28781beb45041cc5ef3986d77a31` |
  | `src/pipeline/RemeshPipeline.cpp` | `6 2` | `fca712094c21313fddb81f40160b392dbf1ab1888e632fa4f3c00e17b764db12` |
  | `tests/PatchDescriptorMilestoneETests.cpp` | `22 0` | `e4275e614d983f5492b861230a1e5dd5899d8afdf7ae7095381fc39094c67184` |

- **Content:**
  - `surface_cell_complex_completion_failure_name`.
  - The rejected-completion terminal passes it as `fail_surface_cells`'s detail code.
- **Test (row 878):** `CompletionFailureKindsNameTheTerminalDetail`, where every rejection kind has a distinct typed name.
- **Outcomes:**
  - Exact → TB69.
  - Mismatch → `M6-CP3-PLAN-P13-COMPLETION-TERMINAL-STOP`.
  - Infrastructure → `M6-CP3-CB75A-P13-COMPLETION-TERMINAL-ORCH`.

## RA-196.7 TB69 — `M6-CP3-TB69-P13-COMPLETION-EMBEDDING-FULL-GATE-EXEC`

Test + Benchmark, artifact-only, CB75's immutable package.

- **Gate:** [manifest](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_TB69_P13_Completion_Embedding_Full_Gate_Case_Manifest.tsv"), 878 rows, SHA-256 `aaaba077a067853a00310683946f82394c60247bd42717fd283b4d7cde423c82`. That is TB68's 873 rows byte for byte plus GUARD rows 874–878.
  - Ledger v5 `fd433f54…`; harness P8 `78b8002c…`; `SELF_CHECK_PASS cases=878 deferred=81`.
  - Pre-registered **878/878**, membership **959**.
- **Census:** `3af1dc0d…`, unchanged.
  - Cylinder: PASS.
  - BunnyRandom: P13-e unchanged (`SingularityPortClassCountMismatch;sourceVertex=49`).
  - **Vase: RED within 600 s**, `terminal=NotProductionReady:completion detail=PatchCompletionRejected`, with `completion=InvalidCompletionQuadEmbedding;…;backend=closed-form;…`.
  - The registered match is the stage, the detail, the code and `closed-form`. The macOS locus (patch 4, variant 0, `bow-tie-intersection`) is recorded, not registered (RA-176).
  - A Vase RED whose `completion=` names `bounded-combinatorial` or `pattern` is a mismatch, and so are `detail=None` and a timeout.
- **Outcomes:**
  - Mismatch → `M6-CP3-TB69-P13-COMPLETION-EMBEDDING-FULL-GATE-REV` (Review).
  - Infrastructure → `M6-CP3-TB69A-P13-COMPLETION-EMBEDDING-ORCH` (one retry).

## RA-196.8 Turn sequence

| Step | Turn | Track |
|---|---|---|
| 1 — NEXT | `M6-CP3-CB73-P13-COMPLETION-EMBEDDING` | Implementation agent, Linux; RA-196.9, compile only |
| 2 | `M6-CP3-CB74-P13-COMPLETION-QUADRANGULATION-SEARCH` | Implementation agent, Linux; RA-196.10, compile only |
| 3 | `M6-CP3-CB75-P13-COMPLETION-TERMINAL-DETAIL` | Implementation agent, Linux; RA-196.11, compile only |
| 4 | `M6-CP3-TB69-P13-COMPLETION-EMBEDDING-FULL-GATE-EXEC` | Implementation agent, Linux; gate 878/878, membership 959; Vase RED `completion` / `PatchCompletionRejected` / closed-form within 600 s |
| 5 (Review, can start now) | `M6-CP3-DEFN-P13-COMPLETION-GRID-EMBEDDING` (P13-h; P13-i classified there) | Probe DEFN on the RA-196 scratch build. 224 closed-form descriptors plus 5 `side-count-unsupported`; name the owner, then exact patches |
| 6 (Review, parallel) | `M6-CP3-DEFN-P13-SINGULARITY-PORT-COUNT` (P13-e, BunnyRandom vertex 49) | Probe DEFN, then an exact patch |
| 7 | P13 re-census → O6/O9 where reached → matrix 6/6 → retire/FIXTURE/PRODUCT/OPEN slices → CP3-REV | One slice at a time |

## RA-196.9 Exact CB73 patch

Base: CB72 source `7b85b450…` (HEAD `fe29a3554`). SHA-256 `4020fad1d3a16c536504d0a3d58e11522dfd99688111bdc09e77b3a6885fabf1` with a trailing newline.

```diff
diff --git a/include/directional/geometry/PureQuadCompletion.h b/include/directional/geometry/PureQuadCompletion.h
--- a/include/directional/geometry/PureQuadCompletion.h
+++ b/include/directional/geometry/PureQuadCompletion.h
@@ -139,6 +139,7 @@ enum class PureQuadEmbeddingFailureKind : int {
   DegenerateNormal = 6,
   ZeroProjectedArea = 7,
   BowTieIntersection = 8,
+  SourceOrientationMismatch = 9,
 };
 
 inline const char *pure_quad_embedding_failure_name(
@@ -162,6 +163,8 @@ inline const char *pure_quad_embedding_failure_name(
     return "zero-projected-area";
   case PureQuadEmbeddingFailureKind::BowTieIntersection:
     return "bow-tie-intersection";
+  case PureQuadEmbeddingFailureKind::SourceOrientationMismatch:
+    return "source-orientation-mismatch";
   }
   return "unknown";
 }
@@ -787,6 +790,13 @@ bool complete_pattern(const PureQuadPatch &patch, PureQuadMesh &mesh);
 bool complete_bounded(const PureQuadPatch &patch, PureQuadMesh &mesh,
                              int &explored);
 
+// One completed quad: simple in its own Newell plane and, given the summed
+// unit normals of the source faces under its corners, oriented within 60
+// degrees of that source normal.
+PureQuadEmbeddingFailureKind quad_embedding_failure(
+    const std::array<Eigen::Vector3d, 4> &corners,
+    const Eigen::Vector3d *sourceNormal);
+
 } // namespace pure_quad_detail
 
 PureQuadCompletionResult complete_pure_quad_patch(
diff --git a/src/geometry/PureQuadCompletion.cpp b/src/geometry/PureQuadCompletion.cpp
--- a/src/geometry/PureQuadCompletion.cpp
+++ b/src/geometry/PureQuadCompletion.cpp
@@ -472,9 +472,117 @@ std::pair<int, int> diagnostic_source_scope(const PureQuadMesh &mesh) {
   return {-1, -1};
 }
 
+Eigen::Vector3d source_orientation_normal(
+    const Eigen::MatrixXd &sourceVertices, const Eigen::MatrixXi &sourceFaces,
+    const std::array<int, 4> &faces) {
+  // Sum of the unit normals of the source faces carrying a quad's corners:
+  // the local source-surface orientation the quad must agree with.
+  Eigen::Vector3d sum = Eigen::Vector3d::Zero();
+  for (const int face : faces) {
+    if (face < 0 || face >= sourceFaces.rows()) {
+      continue;
+    }
+    const Eigen::Vector3d a =
+        sourceVertices.row(sourceFaces(face, 0)).transpose();
+    const Eigen::Vector3d b =
+        sourceVertices.row(sourceFaces(face, 1)).transpose();
+    const Eigen::Vector3d c =
+        sourceVertices.row(sourceFaces(face, 2)).transpose();
+    const Eigen::Vector3d normal = (b - a).cross(c - a);
+    const double length = normal.norm();
+    if (std::isfinite(length) && length > 0.0) {
+      sum += normal / length;
+    }
+  }
+  return sum;
+}
+
+PureQuadEmbeddingFailureKind quad_embedding_failure(
+    const std::array<Eigen::Vector3d, 4> &p,
+    const Eigen::Vector3d *sourceNormal) {
+  for (const Eigen::Vector3d &corner : p) {
+    if (!corner.allFinite()) {
+      return PureQuadEmbeddingFailureKind::NonFinitePosition;
+    }
+  }
+  const auto orient2 = [](const Eigen::Vector2d &a,
+                          const Eigen::Vector2d &b,
+                          const Eigen::Vector2d &c) {
+    return (b.x() - a.x()) * (c.y() - a.y()) -
+           (b.y() - a.y()) * (c.x() - a.x());
+  };
+  const auto oppositeEdgesIntersect = [&](const Eigen::Vector2d &a,
+                                          const Eigen::Vector2d &b,
+                                          const Eigen::Vector2d &c,
+                                          const Eigen::Vector2d &d) {
+    constexpr double eps = 1.0e-13;
+    const double o1 = orient2(a, b, c);
+    const double o2 = orient2(a, b, d);
+    const double o3 = orient2(c, d, a);
+    const double o4 = orient2(c, d, b);
+    return ((o1 > eps && o2 < -eps) || (o1 < -eps && o2 > eps)) &&
+           ((o3 > eps && o4 < -eps) || (o3 < -eps && o4 > eps));
+  };
+  Eigen::Vector3d normal = Eigen::Vector3d::Zero();
+  for (int corner = 0; corner < 4; ++corner) {
+    const Eigen::Vector3d &current = p[static_cast<std::size_t>(corner)];
+    const Eigen::Vector3d &next =
+        p[static_cast<std::size_t>((corner + 1) % 4)];
+    normal.x() += (current.y() - next.y()) * (current.z() + next.z());
+    normal.y() += (current.z() - next.z()) * (current.x() + next.x());
+    normal.z() += (current.x() - next.x()) * (current.y() + next.y());
+  }
+  if (!normal.allFinite() || normal.squaredNorm() <= 1.0e-24) {
+    return PureQuadEmbeddingFailureKind::DegenerateNormal;
+  }
+  Eigen::Index dropAxis = 0;
+  normal.cwiseAbs().maxCoeff(&dropAxis);
+  std::array<Eigen::Vector2d, 4> projected;
+  for (int corner = 0; corner < 4; ++corner) {
+    const Eigen::Vector3d &value = p[static_cast<std::size_t>(corner)];
+    if (dropAxis == 0) {
+      projected[static_cast<std::size_t>(corner)] =
+          Eigen::Vector2d(value.y(), value.z());
+    } else if (dropAxis == 1) {
+      projected[static_cast<std::size_t>(corner)] =
+          Eigen::Vector2d(value.x(), value.z());
+    } else {
+      projected[static_cast<std::size_t>(corner)] =
+          Eigen::Vector2d(value.x(), value.y());
+    }
+  }
+  double signedArea2 = 0.0;
+  for (int corner = 0; corner < 4; ++corner) {
+    const Eigen::Vector2d &a = projected[static_cast<std::size_t>(corner)];
+    const Eigen::Vector2d &b =
+        projected[static_cast<std::size_t>((corner + 1) % 4)];
+    signedArea2 += a.x() * b.y() - a.y() * b.x();
+  }
+  if (!std::isfinite(signedArea2) || std::abs(signedArea2) <= 1.0e-14) {
+    return PureQuadEmbeddingFailureKind::ZeroProjectedArea;
+  }
+  if (oppositeEdgesIntersect(projected[0], projected[1], projected[2],
+                             projected[3]) ||
+      oppositeEdgesIntersect(projected[1], projected[2], projected[3],
+                             projected[0])) {
+    return PureQuadEmbeddingFailureKind::BowTieIntersection;
+  }
+  // A quad agrees with the source surface only if its vector area lies
+  // within 60 degrees of the local source normal. This rejects folded quads
+  // and edge-on slivers, whose orientation sign is numerical noise.
+  if (sourceNormal != nullptr &&
+      !(normal.dot(*sourceNormal) >
+        0.5 * normal.norm() * sourceNormal->norm())) {
+    return PureQuadEmbeddingFailureKind::SourceOrientationMismatch;
+  }
+  return PureQuadEmbeddingFailureKind::None;
+}
+
 bool completed_quads_have_simple_embedding(
     const PureQuadMesh &mesh, const int completionVariant,
-    PureQuadEmbeddingFailure &failure) {
+    PureQuadEmbeddingFailure &failure,
+    const Eigen::MatrixXd *sourceVertices,
+    const Eigen::MatrixXi *sourceFaces) {
   failure = {};
   failure.sourcePatch = mesh.sourcePatch;
   failure.backend = mesh.backend;
@@ -520,24 +628,6 @@ bool completed_quads_have_simple_embedding(
       return reject(PureQuadEmbeddingFailureKind::DuplicateMeshVertex, 0);
     }
   }
-  const auto orient2 = [](const Eigen::Vector2d &a,
-                          const Eigen::Vector2d &b,
-                          const Eigen::Vector2d &c) {
-    return (b.x() - a.x()) * (c.y() - a.y()) -
-           (b.y() - a.y()) * (c.x() - a.x());
-  };
-  const auto oppositeEdgesIntersect = [&](const Eigen::Vector2d &a,
-                                          const Eigen::Vector2d &b,
-                                          const Eigen::Vector2d &c,
-                                          const Eigen::Vector2d &d) {
-    constexpr double eps = 1.0e-13;
-    const double o1 = orient2(a, b, c);
-    const double o2 = orient2(a, b, d);
-    const double o3 = orient2(c, d, a);
-    const double o4 = orient2(c, d, b);
-    return ((o1 > eps && o2 < -eps) || (o1 < -eps && o2 > eps)) &&
-           ((o3 > eps && o4 < -eps) || (o3 < -eps && o4 > eps));
-  };
 
   for (int quadIndex = 0; quadIndex < static_cast<int>(mesh.quads.size());
        ++quadIndex) {
@@ -552,6 +642,7 @@ bool completed_quads_have_simple_embedding(
                     quadIndex);
     }
     std::array<Eigen::Vector3d, 4> p;
+    std::array<int, 4> faces{{-1, -1, -1, -1}};
     for (int corner = 0; corner < 4; ++corner) {
       const auto row = rowByVertex.find(quad[static_cast<std::size_t>(corner)]);
       if (row == rowByVertex.end() || row->second < 0 ||
@@ -565,52 +656,21 @@ bool completed_quads_have_simple_embedding(
         return reject(PureQuadEmbeddingFailureKind::NonFinitePosition,
                       quadIndex);
       }
-    }
-    Eigen::Vector3d normal = Eigen::Vector3d::Zero();
-    for (int corner = 0; corner < 4; ++corner) {
-      const Eigen::Vector3d &current = p[static_cast<std::size_t>(corner)];
-      const Eigen::Vector3d &next =
-          p[static_cast<std::size_t>((corner + 1) % 4)];
-      normal.x() += (current.y() - next.y()) * (current.z() + next.z());
-      normal.y() += (current.z() - next.z()) * (current.x() + next.x());
-      normal.z() += (current.x() - next.x()) * (current.y() + next.y());
-    }
-    if (!normal.allFinite() || normal.squaredNorm() <= 1.0e-24) {
-      return reject(PureQuadEmbeddingFailureKind::DegenerateNormal, quadIndex);
-    }
-    Eigen::Index dropAxis = 0;
-    normal.cwiseAbs().maxCoeff(&dropAxis);
-    std::array<Eigen::Vector2d, 4> projected;
-    for (int corner = 0; corner < 4; ++corner) {
-      const Eigen::Vector3d &value = p[static_cast<std::size_t>(corner)];
-      if (dropAxis == 0) {
-        projected[static_cast<std::size_t>(corner)] =
-            Eigen::Vector2d(value.y(), value.z());
-      } else if (dropAxis == 1) {
-        projected[static_cast<std::size_t>(corner)] =
-            Eigen::Vector2d(value.x(), value.z());
-      } else {
-        projected[static_cast<std::size_t>(corner)] =
-            Eigen::Vector2d(value.x(), value.y());
+      if (row->second < static_cast<int>(mesh.vertexProvenance.size())) {
+        faces[static_cast<std::size_t>(corner)] =
+            mesh.vertexProvenance[static_cast<std::size_t>(row->second)].face;
       }
     }
-    double signedArea2 = 0.0;
-    for (int corner = 0; corner < 4; ++corner) {
-      const Eigen::Vector2d &a = projected[static_cast<std::size_t>(corner)];
-      const Eigen::Vector2d &b =
-          projected[static_cast<std::size_t>((corner + 1) % 4)];
-      signedArea2 += a.x() * b.y() - a.y() * b.x();
+    Eigen::Vector3d sourceNormal = Eigen::Vector3d::Zero();
+    const bool oriented = sourceVertices != nullptr && sourceFaces != nullptr;
+    if (oriented) {
+      sourceNormal =
+          source_orientation_normal(*sourceVertices, *sourceFaces, faces);
     }
-    if (!std::isfinite(signedArea2) || std::abs(signedArea2) <= 1.0e-14) {
-      return reject(PureQuadEmbeddingFailureKind::ZeroProjectedArea,
-                    quadIndex);
-    }
-    if (oppositeEdgesIntersect(projected[0], projected[1], projected[2],
-                               projected[3]) ||
-        oppositeEdgesIntersect(projected[1], projected[2], projected[3],
-                               projected[0])) {
-      return reject(PureQuadEmbeddingFailureKind::BowTieIntersection,
-                    quadIndex);
+    const PureQuadEmbeddingFailureKind kind =
+        quad_embedding_failure(p, oriented ? &sourceNormal : nullptr);
+    if (kind != PureQuadEmbeddingFailureKind::None) {
+      return reject(kind, quadIndex);
     }
   }
   return true;
@@ -2295,7 +2355,8 @@ PureQuadCompletionResult complete_pure_quad_patch(
     return close_pure_quad_completion(std::move(result));
   }
   if (!pure_quad_detail::completed_quads_have_simple_embedding(
-          mesh, options.completionVariant, result.embeddingFailure)) {
+          mesh, options.completionVariant, result.embeddingFailure,
+          options.sourceVertices, options.sourceFaces)) {
     result.failureReason = PureQuadPatchRejectReason::TopologyValidationFailed;
     const PureQuadEmbeddingFailure &failure = result.embeddingFailure;
     std::ostringstream stream;
diff --git a/tests/PureQuadCompletionPhase18Tests.cpp b/tests/PureQuadCompletionPhase18Tests.cpp
--- a/tests/PureQuadCompletionPhase18Tests.cpp
+++ b/tests/PureQuadCompletionPhase18Tests.cpp
@@ -2611,3 +2611,76 @@ TEST(PureQuadCompletionPhase18, StitchingIsPatchOrderInvariant) {
   EXPECT_EQ(forward.eulerCharacteristic, reverse.eulerCharacteristic);
   EXPECT_EQ(forward.boundaryLoopCount, reverse.boundaryLoopCount);
 }
+
+TEST(PureQuadCompletionPhase18,
+     QuadEmbeddingRejectsFoldedAndEdgeOnQuadsAgainstTheSourceNormal) {
+  using directional::geometry::PureQuadEmbeddingFailureKind;
+  using directional::geometry::pure_quad_detail::quad_embedding_failure;
+  // A unit square turned about the x axis, so that its vector area makes
+  // `degrees` with +z.
+  const auto turned = [](const double degrees) {
+    const double angle = degrees * std::numbers::pi / 180.0;
+    const Eigen::Vector3d u(1.0, 0.0, 0.0);
+    const Eigen::Vector3d v(0.0, std::cos(angle), std::sin(angle));
+    return std::array<Eigen::Vector3d, 4>{
+        {Eigen::Vector3d::Zero(), u, u + v, v}};
+  };
+  // Two unit source normals summed, as for corners on two faces.
+  const Eigen::Vector3d source(0.0, 0.0, 2.0);
+  EXPECT_EQ(PureQuadEmbeddingFailureKind::None,
+            quad_embedding_failure(turned(0.0), &source));
+  EXPECT_EQ(PureQuadEmbeddingFailureKind::None,
+            quad_embedding_failure(turned(55.0), &source));
+  EXPECT_EQ(PureQuadEmbeddingFailureKind::SourceOrientationMismatch,
+            quad_embedding_failure(turned(65.0), &source));
+  EXPECT_EQ(PureQuadEmbeddingFailureKind::SourceOrientationMismatch,
+            quad_embedding_failure(turned(90.0), &source));
+  EXPECT_EQ(PureQuadEmbeddingFailureKind::SourceOrientationMismatch,
+            quad_embedding_failure(turned(180.0), &source));
+  // Without a source surface only the quad's own simplicity is checked.
+  EXPECT_EQ(PureQuadEmbeddingFailureKind::None,
+            quad_embedding_failure(turned(180.0), nullptr));
+  // A bow-tie keeps its own classification ahead of orientation.
+  const std::array<Eigen::Vector3d, 4> bowTie{
+      {Eigen::Vector3d(0.0, 0.0, 0.0), Eigen::Vector3d(3.0, 1.0, 0.0),
+       Eigen::Vector3d(3.0, 0.0, 0.0), Eigen::Vector3d(0.0, 2.0, 0.0)}};
+  EXPECT_EQ(PureQuadEmbeddingFailureKind::BowTieIntersection,
+            quad_embedding_failure(bowTie, &source));
+}
+
+TEST(PureQuadCompletionPhase18,
+     CompletionRejectsQuadsFoldedAgainstTheSourceSurface) {
+  CompletionFixture fixture = generated_plane_patch();
+  directional::geometry::PureQuadCompletionOptions options;
+  options.sourcePatch = 17;
+  options.sourceVertices = &fixture.vertices;
+  options.sourceFaces = &fixture.faces;
+  const auto sourceAuthority = test_source_authority(
+      fixture.faces, {0, 0, 1}, {0, 0, 1});
+  options.sourceAuthority = &sourceAuthority;
+  ASSERT_TRUE(directional::geometry::complete_pure_quad_patch(
+                  fixture.patch, options)
+                  .is_produced());
+
+  // The same square traversed clockwise about the +z source normal: every
+  // generated quad now faces away from the source surface.
+  auto &patch = fixture.patch;
+  std::reverse(patch.boundaryVertices.begin() + 1,
+               patch.boundaryVertices.end());
+  std::reverse(patch.boundaryProvenance.begin() + 1,
+               patch.boundaryProvenance.end());
+  std::reverse(patch.boundaryTopologyRegions.begin() + 1,
+               patch.boundaryTopologyRegions.end());
+  std::reverse(patch.boundaryCharts.begin() + 1, patch.boundaryCharts.end());
+  std::reverse(patch.boundaryNodeIdentities.begin() + 1,
+               patch.boundaryNodeIdentities.end());
+  const auto folded =
+      directional::geometry::complete_pure_quad_patch(patch, options);
+  ASSERT_TRUE(folded.is_rejected());
+  EXPECT_EQ(directional::geometry::PureQuadEmbeddingFailureKind::
+                SourceOrientationMismatch,
+            folded.rejection()->embeddingFailure.kind);
+  EXPECT_EQ(folded.rejection()->detail.rfind(
+                "InvalidCompletionQuadEmbedding", 0),
+            0U);
+}
```

## RA-196.10 Exact CB74 patch

Base: CB73 result. SHA-256 `b2c6a251c915371845d93c05d753cbf7ad5ed92936cf0fa66879d0dd307c7b4b` with a trailing newline.

```diff
diff --git a/include/directional/geometry/PureQuadCompletion.h b/include/directional/geometry/PureQuadCompletion.h
--- a/include/directional/geometry/PureQuadCompletion.h
+++ b/include/directional/geometry/PureQuadCompletion.h
@@ -58,6 +58,7 @@ enum class PureQuadPatchRejectReason : int {
   RewritePreconditionFailed = 14,
   RewriteFeatureViolation = 15,
   RewriteValenceMismatch = 16,
+  NoEmbeddedQuadrangulation = 17,
 };
 
 inline const char *pure_quad_patch_reject_reason_name(
@@ -97,6 +98,8 @@ inline const char *pure_quad_patch_reject_reason_name(
     return "rewrite-feature-violation";
   case PureQuadPatchRejectReason::RewriteValenceMismatch:
     return "rewrite-valence-mismatch";
+  case PureQuadPatchRejectReason::NoEmbeddedQuadrangulation:
+    return "no-embedded-quadrangulation";
   }
   return "unknown";
 }
diff --git a/src/geometry/PureQuadCompletion.cpp b/src/geometry/PureQuadCompletion.cpp
--- a/src/geometry/PureQuadCompletion.cpp
+++ b/src/geometry/PureQuadCompletion.cpp
@@ -2120,6 +2120,130 @@ bool append_balanced_boundary_quadrangulation(
          append_balanced_boundary_quadrangulation(second, mesh);
 }
 
+bool append_embedded_boundary_quadrangulation(
+    const PureQuadPatch &patch, const std::vector<int> &boundary,
+    const int completionVariant, const Eigen::MatrixXd *sourceVertices,
+    const Eigen::MatrixXi *sourceFaces, PureQuadMesh &mesh, bool &exhausted) {
+  // The balanced split is kept whenever every one of its quads embeds.
+  // Otherwise every quadrangulation of the same cycle by diagonals is
+  // searched: split(i, j) records the first quad (i, a, b, j) in (a, b) order
+  // whose three sub-polygons also split, so the result is deterministic. The
+  // search is exhaustive, so `exhausted` proves that no forward rotation of
+  // this cycle has an embedded quadrangulation either.
+  const int n = static_cast<int>(boundary.size());
+  if (n < 4 || n % 2 != 0) {
+    return false;
+  }
+  // A reversed variant winds every quad against the patch boundary. It keeps
+  // the balanced split, which the validator then rejects; only the forward
+  // rotations, which all share one set of quadrangulations, are searched.
+  if (normalized_completion_variant(completionVariant, 2 * n) >= n) {
+    return append_balanced_boundary_quadrangulation(boundary, mesh);
+  }
+  std::map<int, std::size_t> indexByVertex;
+  for (std::size_t index = 0; index < patch.boundaryVertices.size(); ++index) {
+    indexByVertex.emplace(patch.boundaryVertices[index], index);
+  }
+  std::vector<const SurfacePoint *> corners;
+  corners.reserve(boundary.size());
+  for (const int vertex : boundary) {
+    const auto found = indexByVertex.find(vertex);
+    if (found == indexByVertex.end() ||
+        found->second >= patch.boundaryProvenance.size()) {
+      return false;
+    }
+    corners.push_back(&patch.boundaryProvenance[found->second]);
+  }
+  const bool oriented = sourceVertices != nullptr && sourceFaces != nullptr;
+  const auto embedded = [&](const int i, const int a, const int b,
+                            const int j) {
+    const std::array<int, 4> rows{{i, a, b, j}};
+    std::array<Eigen::Vector3d, 4> p;
+    std::array<int, 4> faces{};
+    for (std::size_t corner = 0; corner < 4; ++corner) {
+      const SurfacePoint &point =
+          *corners[static_cast<std::size_t>(rows[corner])];
+      p[corner] = point.position;
+      faces[corner] = point.face;
+    }
+    Eigen::Vector3d sourceNormal = Eigen::Vector3d::Zero();
+    if (oriented) {
+      sourceNormal =
+          source_orientation_normal(*sourceVertices, *sourceFaces, faces);
+    }
+    return quad_embedding_failure(p, oriented ? &sourceNormal : nullptr) ==
+           PureQuadEmbeddingFailureKind::None;
+  };
+
+  const std::size_t firstQuad = mesh.quads.size();
+  if (append_balanced_boundary_quadrangulation(boundary, mesh)) {
+    std::map<int, int> rowByVertex;
+    for (int row = 0; row < n; ++row) {
+      rowByVertex.emplace(boundary[static_cast<std::size_t>(row)], row);
+    }
+    const bool balancedEmbeds = std::all_of(
+        mesh.quads.begin() + static_cast<std::ptrdiff_t>(firstQuad),
+        mesh.quads.end(), [&](const std::vector<int> &quad) {
+          return quad.size() == 4U &&
+                 embedded(rowByVertex.at(quad[0]), rowByVertex.at(quad[1]),
+                          rowByVertex.at(quad[2]), rowByVertex.at(quad[3]));
+        });
+    if (balancedEmbeds) {
+      return true;
+    }
+  }
+  mesh.quads.resize(firstQuad);
+
+  constexpr int unknown = -2;
+  constexpr int infeasible = -1;
+  std::vector<int> split(static_cast<std::size_t>(n) * n, unknown);
+  const auto splits = [&](const auto &self, const int i, const int j) -> bool {
+    if (j - i == 1) {
+      return true;
+    }
+    int &memo = split[static_cast<std::size_t>(i) * n + j];
+    if (memo != unknown) {
+      return memo != infeasible;
+    }
+    memo = infeasible;
+    for (int a = i + 1; a < j; a += 2) {
+      if (!self(self, i, a)) {
+        continue;
+      }
+      for (int b = a + 1; b < j; b += 2) {
+        if (self(self, a, b) && self(self, b, j) && embedded(i, a, b, j)) {
+          memo = a * n + b;
+          return true;
+        }
+      }
+    }
+    return false;
+  };
+  if (!splits(splits, 0, n - 1)) {
+    exhausted = true;
+    return false;
+  }
+  std::vector<std::pair<int, int>> pending{{0, n - 1}};
+  while (!pending.empty()) {
+    const auto [i, j] = pending.back();
+    pending.pop_back();
+    if (j - i == 1) {
+      continue;
+    }
+    const int choice = split[static_cast<std::size_t>(i) * n + j];
+    const int a = choice / n;
+    const int b = choice % n;
+    mesh.quads.push_back({boundary[static_cast<std::size_t>(i)],
+                          boundary[static_cast<std::size_t>(a)],
+                          boundary[static_cast<std::size_t>(b)],
+                          boundary[static_cast<std::size_t>(j)]});
+    pending.emplace_back(b, j);
+    pending.emplace_back(a, b);
+    pending.emplace_back(i, a);
+  }
+  return true;
+}
+
 } // namespace directional::geometry::pure_quad_detail
 
 namespace directional::geometry::pure_quad_detail {
@@ -2166,12 +2290,16 @@ bool complete_singularity_pole(
 namespace directional::geometry::pure_quad_detail {
 
 bool complete_pattern(const PureQuadPatch &patch, PureQuadMesh &mesh,
-                      const int completionVariant) {
+                      const int completionVariant,
+                      const Eigen::MatrixXd *sourceVertices,
+                      const Eigen::MatrixXi *sourceFaces, bool &exhausted) {
   if (patch.boundaryVertices.size() < 4 ||
       patch.boundaryVertices.size() % 2 != 0) return false;
   const std::vector<int> boundary =
       rotated_cycle(patch.boundaryVertices, completionVariant);
-  if (!append_balanced_boundary_quadrangulation(boundary, mesh)) {
+  if (!append_embedded_boundary_quadrangulation(
+          patch, boundary, completionVariant, sourceVertices, sourceFaces,
+          mesh, exhausted)) {
     return false;
   }
   mesh.backend = PureQuadCompletionBackend::Pattern;
@@ -2183,12 +2311,16 @@ bool complete_pattern(const PureQuadPatch &patch, PureQuadMesh &mesh,
 namespace directional::geometry::pure_quad_detail {
 
 bool complete_bounded(const PureQuadPatch &patch, PureQuadMesh &mesh,
-                      int &explored, const int completionVariant) {
+                      int &explored, const int completionVariant,
+                      const Eigen::MatrixXd *sourceVertices,
+                      const Eigen::MatrixXi *sourceFaces, bool &exhausted) {
   PureQuadMesh trial = mesh;
   ++explored;
   const std::vector<int> boundary =
       rotated_cycle(patch.boundaryVertices, completionVariant);
-  if (!append_balanced_boundary_quadrangulation(boundary, trial) ||
+  if (!append_embedded_boundary_quadrangulation(
+          patch, boundary, completionVariant, sourceVertices, sourceFaces,
+          trial, exhausted) ||
       !pure_quad_topology_is_disk(trial)) {
     return false;
   }
@@ -2305,6 +2437,7 @@ PureQuadCompletionResult complete_pure_quad_patch(
   const std::vector<unsigned char> *allowedFacePtr =
       allowedFaces.empty() ? nullptr : &allowedFaces;
   bool completed = false;
+  bool quadrangulationExhausted = false;
   if (!boundedFallbackAdmissible && patch.singularityCount != 0) {
     completed = pure_quad_detail::complete_singularity_pole(
         patch, mesh, projection.get(), allowedFacePtr,
@@ -2326,14 +2459,20 @@ PureQuadCompletionResult complete_pure_quad_patch(
   }
   if (!completed && !boundedFallbackAdmissible && patch.simple) {
     completed = pure_quad_detail::complete_pattern(
-        patch, mesh, options.completionVariant);
+        patch, mesh, options.completionVariant, options.sourceVertices,
+        options.sourceFaces, quadrangulationExhausted);
   }
   if (!completed && options.allowBoundedCombinatorialFallback) {
     completed = pure_quad_detail::complete_bounded(
-        patch, mesh, result.exploredPatterns, options.completionVariant);
+        patch, mesh, result.exploredPatterns, options.completionVariant,
+        options.sourceVertices, options.sourceFaces,
+        quadrangulationExhausted);
   }
   if (!completed) {
-    result.failureReason = PureQuadPatchRejectReason::SearchLimitExceeded;
+    result.failureReason =
+        quadrangulationExhausted
+            ? PureQuadPatchRejectReason::NoEmbeddedQuadrangulation
+            : PureQuadPatchRejectReason::SearchLimitExceeded;
     return close_pure_quad_completion(std::move(result));
   }
   if (!pure_quad_detail::fill_positions(mesh)) {
diff --git a/tests/PureQuadCompletionPhase18Tests.cpp b/tests/PureQuadCompletionPhase18Tests.cpp
--- a/tests/PureQuadCompletionPhase18Tests.cpp
+++ b/tests/PureQuadCompletionPhase18Tests.cpp
@@ -2684,3 +2684,134 @@ TEST(PureQuadCompletionPhase18,
                 "InvalidCompletionQuadEmbedding", 0),
             0U);
 }
+
+namespace {
+
+CompletionFixture single_face_patch(const std::vector<Eigen::Vector2d> &boundary,
+                                    std::vector<int> sides) {
+  CompletionFixture fixture;
+  fixture.vertices.resize(3, 3);
+  fixture.vertices << 0.0, 0.0, 0.0,
+                      2000.0, 0.0, 0.0,
+                      0.0, 2000.0, 0.0;
+  fixture.faces.resize(1, 3);
+  fixture.faces << 0, 1, 2;
+  fixture.patch.sideEdgeCounts = std::move(sides);
+  fixture.patch.turns.assign(fixture.patch.sideEdgeCounts.size(), 1);
+  fixture.patch.sourceFaces = {0};
+  for (int index = 0; index < static_cast<int>(boundary.size()); ++index) {
+    const Eigen::Vector2d &corner = boundary[static_cast<std::size_t>(index)];
+    fixture.patch.boundaryVertices.push_back(index);
+    fixture.patch.boundaryProvenance.push_back(
+        directional::geometry::project_to_surface(
+            fixture.vertices, fixture.faces,
+            Eigen::Vector3d(corner.x(), corner.y(), 0.0)));
+  }
+  const auto authority = test_source_authority(fixture.faces, {0}, {0});
+  assign_patch_boundary_authority(
+      fixture.patch, fixture.faces, authority,
+      std::vector<int>(fixture.patch.boundaryVertices.size(), 0));
+  return fixture;
+}
+
+} // namespace
+
+TEST(PureQuadCompletionPhase18,
+     BoundedCompletionFindsAnEmbeddedQuadrangulationOfAConcaveBoundary) {
+  // Vase patch 1200 in its source face's barycentric chart, scaled to
+  // integers: reflex corners 2 and 4, straight corner 5. No rotation or
+  // reversal of the balanced split embeds; three of the twelve
+  // quadrangulations by diagonals do.
+  const std::vector<Eigen::Vector2d> boundary = {
+      {250.0, 582.0}, {442.0, 466.0}, {384.0, 666.0}, {618.0, 526.0},
+      {556.0, 740.0}, {492.0, 963.0}, {428.0, 1186.0}, {2.0, 1444.0}};
+  const CompletionFixture fixture =
+      single_face_patch(boundary, {1, 1, 1, 3, 1, 1});
+  directional::geometry::PureQuadCompletionOptions options;
+  options.sourcePatch = 1200;
+  options.sourceVertices = &fixture.vertices;
+  options.sourceFaces = &fixture.faces;
+  const auto sourceAuthority = test_source_authority(fixture.faces, {0}, {0});
+  options.sourceAuthority = &sourceAuthority;
+  const auto cross = [](const Eigen::Vector2d &a, const Eigen::Vector2d &b,
+                        const Eigen::Vector2d &c) {
+    return (b.x() - a.x()) * (c.y() - a.y()) -
+           (b.y() - a.y()) * (c.x() - a.x());
+  };
+  const auto properlyCross = [&](const Eigen::Vector2d &a,
+                                 const Eigen::Vector2d &b,
+                                 const Eigen::Vector2d &c,
+                                 const Eigen::Vector2d &d) {
+    return cross(a, b, c) * cross(a, b, d) < 0.0 &&
+           cross(c, d, a) * cross(c, d, b) < 0.0;
+  };
+  // Variants 8-15 reverse the cycle, so every quad winds against the
+  // counter-clockwise boundary and the source face; none is emitted.
+  for (int variant = 8; variant < 16; ++variant) {
+    options.completionVariant = variant;
+    const auto reversed =
+        directional::geometry::complete_pure_quad_patch(fixture.patch, options);
+    ASSERT_TRUE(reversed.is_rejected()) << "variant " << variant;
+    EXPECT_TRUE(reversed.rejection()->embeddingFailure.active)
+        << "variant " << variant;
+    EXPECT_EQ(reversed.rejection()->detail.rfind(
+                  "InvalidCompletionQuadEmbedding", 0),
+              0U)
+        << "variant " << variant;
+  }
+  for (int variant = 0; variant < 8; ++variant) {
+    options.completionVariant = variant;
+    const auto completion =
+        directional::geometry::complete_pure_quad_patch(fixture.patch, options);
+    ASSERT_TRUE(completion.is_produced()) << "variant " << variant;
+    const auto &mesh = completion.product();
+    EXPECT_EQ(directional::geometry::PureQuadCompletionBackend::
+                  BoundedCombinatorial,
+              mesh.backend);
+    ASSERT_EQ(3U, mesh.quads.size()) << "variant " << variant;
+    EXPECT_TRUE(directional::geometry::pure_quad_topology_is_disk(mesh));
+    // Independent exact oracle on the fixture's integer corners: every quad
+    // is simple and counter-clockwise, like the source face.
+    for (const auto &quad : mesh.quads) {
+      std::array<Eigen::Vector2d, 4> q;
+      for (std::size_t corner = 0; corner < 4; ++corner) {
+        q[corner] = boundary[static_cast<std::size_t>(quad[corner])];
+      }
+      double area2 = 0.0;
+      for (std::size_t corner = 0; corner < 4; ++corner) {
+        const Eigen::Vector2d &a = q[corner];
+        const Eigen::Vector2d &b = q[(corner + 1) % 4];
+        area2 += a.x() * b.y() - a.y() * b.x();
+      }
+      EXPECT_GT(area2, 0.0) << "variant " << variant;
+      EXPECT_FALSE(properlyCross(q[0], q[1], q[2], q[3]));
+      EXPECT_FALSE(properlyCross(q[1], q[2], q[3], q[0]));
+    }
+  }
+}
+
+TEST(PureQuadCompletionPhase18,
+     BoundedCompletionReportsABoundaryWithNoEmbeddedQuadrangulation) {
+  // Every one of the three quadrangulations of this hexagon contains a
+  // bow-tie, so no forward rotation can succeed and the failure is typed.
+  const std::vector<Eigen::Vector2d> boundary = {
+      {100.0, 500.0}, {200.0, 200.0}, {700.0, 500.0},
+      {500.0, 400.0}, {300.0, 500.0}, {400.0, 400.0}};
+  const CompletionFixture fixture = single_face_patch(boundary, {1, 1, 1, 3});
+  directional::geometry::PureQuadCompletionOptions options;
+  options.sourcePatch = 6;
+  options.sourceVertices = &fixture.vertices;
+  options.sourceFaces = &fixture.faces;
+  const auto sourceAuthority = test_source_authority(fixture.faces, {0}, {0});
+  options.sourceAuthority = &sourceAuthority;
+  for (int variant = 0; variant < 6; ++variant) {
+    options.completionVariant = variant;
+    const auto completion =
+        directional::geometry::complete_pure_quad_patch(fixture.patch, options);
+    ASSERT_TRUE(completion.is_rejected()) << "variant " << variant;
+    EXPECT_EQ(directional::geometry::PureQuadPatchRejectReason::
+                  NoEmbeddedQuadrangulation,
+              completion.rejection()->reason)
+        << "variant " << variant;
+  }
+}
```

## RA-196.11 Exact CB75 patch

Base: CB74 result. SHA-256 `d1f5652a979c414e53f11f8b62a71f9d528a79428c0067f2b4946ad71844d933` with a trailing newline.

```diff
diff --git a/include/directional/geometry/PatchDescriptor.h b/include/directional/geometry/PatchDescriptor.h
--- a/include/directional/geometry/PatchDescriptor.h
+++ b/include/directional/geometry/PatchDescriptor.h
@@ -298,6 +298,29 @@ enum class SurfaceCellComplexCompletionFailureKind : int {
   AssemblyRejected = 7,
 };
 
+inline const char *surface_cell_complex_completion_failure_name(
+    const SurfaceCellComplexCompletionFailureKind kind) {
+  switch (kind) {
+  case SurfaceCellComplexCompletionFailureKind::None:
+    return "None";
+  case SurfaceCellComplexCompletionFailureKind::PreparationRejected:
+    return "PreparationRejected";
+  case SurfaceCellComplexCompletionFailureKind::InvalidDomainIdentity:
+    return "InvalidDomainIdentity";
+  case SurfaceCellComplexCompletionFailureKind::UnresolvedSingularityOwnership:
+    return "UnresolvedSingularityOwnership";
+  case SurfaceCellComplexCompletionFailureKind::PatchCompletionRejected:
+    return "PatchCompletionRejected";
+  case SurfaceCellComplexCompletionFailureKind::CompletionOwnershipRejected:
+    return "CompletionOwnershipRejected";
+  case SurfaceCellComplexCompletionFailureKind::StructuralRepairExhausted:
+    return "StructuralRepairExhausted";
+  case SurfaceCellComplexCompletionFailureKind::AssemblyRejected:
+    return "AssemblyRejected";
+  }
+  return "Unknown";
+}
+
 struct SurfaceCellComplexCompletionEvidence {
   int parityOddCellsBefore = 0;
   int parityOddCellsAfter = 0;
diff --git a/src/pipeline/RemeshPipeline.cpp b/src/pipeline/RemeshPipeline.cpp
--- a/src/pipeline/RemeshPipeline.cpp
+++ b/src/pipeline/RemeshPipeline.cpp
@@ -14376,8 +14376,12 @@ remesh_from_raw_cross_field_impl_with_stage_products(
       result.surfaceCellContext.hasSimplifiedComplex = true;
     }
     if (completionResult.is_rejected()) {
-      return fail_surface_cells(SurfaceCellFailureCode::NotProductionReady,
-                                "completion");
+      // The typed completion failure is the terminal detail; the per-patch
+      // reason stays in surfaceCellContext.completionFailure.
+      return fail_surface_cells(
+          SurfaceCellFailureCode::NotProductionReady, "completion",
+          geometry::surface_cell_complex_completion_failure_name(
+              closedCompletionFailure->kind));
     }
     if (!completionResult.is_produced()) {
       return fail_surface_cells(SurfaceCellFailureCode::NotProductionReady,
diff --git a/tests/PatchDescriptorMilestoneETests.cpp b/tests/PatchDescriptorMilestoneETests.cpp
--- a/tests/PatchDescriptorMilestoneETests.cpp
+++ b/tests/PatchDescriptorMilestoneETests.cpp
@@ -1908,3 +1908,25 @@ TEST(PatchDescriptorMilestoneE,
   EXPECT_EQ(0, completion.completionOwnershipRouteCandidateCount);
   EXPECT_TRUE(completion.ownershipRepairAttempts.empty());
 }
+
+TEST(PatchDescriptorMilestoneE, CompletionFailureKindsNameTheTerminalDetail) {
+  using directional::geometry::SurfaceCellComplexCompletionFailureKind;
+  using directional::geometry::surface_cell_complex_completion_failure_name;
+  // The completion terminal reports this name instead of "None"; every
+  // rejection kind has its own.
+  std::vector<std::string> names;
+  for (int value = 1; value <= 7; ++value) {
+    const std::string name = surface_cell_complex_completion_failure_name(
+        static_cast<SurfaceCellComplexCompletionFailureKind>(value));
+    EXPECT_NE("None", name);
+    EXPECT_NE("Unknown", name);
+    for (const std::string &previous : names) {
+      EXPECT_NE(previous, name);
+    }
+    names.push_back(name);
+  }
+  EXPECT_STREQ("PatchCompletionRejected",
+               surface_cell_complex_completion_failure_name(
+                   SurfaceCellComplexCompletionFailureKind::
+                       PatchCompletionRejected));
+}
```

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | n/a: no selector change. The TB69 manifest is TB68's 873 rows byte for byte plus rows 874–878; `SELF_CHECK_PASS cases=878 deferred=81` with harness P8 |
| Decisive claims independently re-derived | Patch 1200 boundary and all 12 quadrangulations in exact arithmetic; first-pass census of every boundary-only completion; DP existence for all 12,524 patches; per-descriptor failure traces in modes 0/1/3; clean build of the exact patches (tests, gate, ledger, Vase); mutants; patch chain applied to `fe29a3554` with every result SHA-256 reproduced; embedded blocks re-hashed |
| Non-vacuity checked | Each new row fails under its own mutant (RA-196.2), and row 876 also fails when the search ignores orientation. Row 876's fixture is exact: 0 of 16 balanced variants embed, and 3 of 12 quadrangulations do. Row 877's hexagon has no embedded quadrangulation (all 3 contain a bow-tie). The clean build moves Vase off the boundary-only class (229 failures, 0 boundary-only) |
| Prior obligations discharged/carried | F1–F8 ruled. P13-g attributed and routed (CB73/CB74/CB75/TB69); P13-h, P13-i, O21, O22 new. Carried: P13-e, O6, O9, O16, O17, O19, O20, DR1/DR3, DR2/DR4, O2b, O15b, O7 (the oracle target still does not compile; seen in the probe build) |
| Stable accounting | 66/17/49, debt 1; CP2 491/491; selector497 unpromoted |
| New candidates/obligations recorded | P13-h, P13-i → `M6-CP3-DEFN-P13-COMPLETION-GRID-EMBEDDING`; O21 (quality), O22 (cleanup) |
| ORIENTATION currency line | Updated to RA-196 / CB73 next |
| ORIENTATION §3 / §4 / §7 / §8 | §3 boundary row, §7 Immediate and priority 1, §8 pattern updated. §4: n/a |
| CHANGELOG | Entry added |
| ROADMAP | Now line and CP3 boundary updated |
| Selector manifest | n/a |
| LESSONS | New lesson: count every failure in a pass and check the validator against the source before designing a producer fix |
| Consolidation under CLEAN_UP_POLICY | The decision stays as history with a superseded note pointing here |
| Successor frozen | CB73 (RA-196.4, exact RA-196.9) → CB74 (RA-196.5, exact RA-196.10) → CB75 (RA-196.6, exact RA-196.11) → TB69 (RA-196.7) |
| Turn boundary held | No product, test, fixture or selector change in the repository; probes ran in scratch only |
| `review_check.py boundary` | ALL CHECKS PASSED on the full-history checkout; `ledgers --base 0dfde11f6` PASSED |
| `STATUS` lifecycle maintained | COMPLETE, Successor CB73 |
| Pushed to origin, branch in sync | Yes, fast-forward, no force |
