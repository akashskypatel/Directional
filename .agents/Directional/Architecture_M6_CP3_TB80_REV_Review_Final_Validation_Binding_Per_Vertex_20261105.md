# RA-206 — Review of the TB80 Review: row 899 exposed a real O(F×V) binding check, and its wall clock was calibrated on macOS (2026-11-05)

**Reviewed turn:** `M6-CP3-TB80-P13-ARRANGEMENT-CELL-ORDER-FULL-GATE-REV` (ChatGPT, [adjudication](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_TB80_REV_Final_Validation_Cost_Gate_Adjudication_20261105.md"), `1b3e790aa`). It froze `M6-CP3-CB91-P13-FINAL-VALIDATION-BINDING-COST-EVIDENCE` as an open-ended evidence turn.

**State:**
- The implementation agent opened that CB91 at 2026-11-05T05:56:03Z (`c714b4f8c`).
- RA-206 keeps the turn ID and **replaces its content with one exact patch** (RA-206.3).
- STATUS is left to the open CB91 turn.

**Source:** HEAD `a75c9f6ff`. `git diff --quiet e00ef91a8 HEAD -- src include tests benchmarks CMakeLists.txt cmake` passes, so the source is CB90's.

**Scratch build:** `bld55n`, a macOS arm64 FMA-off static build synced byte for byte to the HEAD tree, then to HEAD + CB91 (`diff -rq`: no difference). TB80's raw gate log and result artifacts were downloaded into isolated directories and read with `python3 -I`.

## RA-206.1 Verdict on the TB80 Review

**What holds:**
- Artifact verification;
- the census MATCH;
- the RA-204.9 comparison: CloseSheets' arrangement equals macOS, so O30a holds across platforms in fixed order, while O30b stays open;
- the refusal to retry, soften the guard or promote;
- separating stopwatch from process time.

**Defects:**

1. **No attribution of CB90.** CB90 changes one comparator in `build_surface_cell_complex` and a census-test comment. Row 899 validates a synthetic grid and never builds an arrangement, so CB90 is excluded statically. The Review instead left an "unproven performance root cause".
2. **Wrong hypothesis.** It asked whether binding is re-checked "per output quad … at the shared final validator/optimizer boundary".
   - The check is **per output vertex, inside the independent validator**: `SourceAuthoritativeMeshValidator.cpp:1186`, `matches_source_faces` inside the provenance loop.
   - The cost is dominated by per-sample chart-mask keying (RA-206.2).
   - A witness placed at "the shared owning call boundary" would not have seen either.
3. **The turn shape breaks the standing rule.** Its CB91 was conditional and investigative: "inspect … if … implement … else instrument". The implementation agent gets exact patches only; probes stay on the Review track.
4. **"Keep the existing 2.0 s gate."** On Linux the timed section runs 3.5× macOS (RA-206.2). Even with every per-quad cost removed, Linux would sit near 1.5 s, so the guard would keep flaking.
5. **"LESSONS: n/a, no proven pattern."** There is one: a wall-clock guard calibrated on one platform (RA-206.6).

**My errors, owned:**
- **RA-202.8 set the 2 s bound** from macOS's 0.7 s, without the Linux ratio that RA-202 itself had just documented.
- **CB88's test claims "after one binding check" but never counts checks.** The validation it times makes 450 full binding checks: one per output vertex, plus 9.

## RA-206.2 Measurements (scratch, CB90 source)

**Stopwatch per gated wall-clock guard**, macOS, 5 runs:

| Row | macOS timed section | Linux/macOS whole test (TB80) |
|---|---|---|
| 888 | 0.003 s | 1.28 |
| 890 | 0.004 s | 1.26 |
| 892 | 0.29 s + 0.15 s | 1.60 |
| 893 | 0.007 s | 1.28 |
| **899** | **0.67–0.69 s** | 1.58 (but its timed section is 2.37 s on Linux, **3.5×**) |

Rows 896 and 898 run in under 0.25 s in total on Linux. Only row 899 is at risk.

**Row 899 is O(F×Q):**

| Source faces F | 100 quads | 400 quads | 1,600 quads | Per quad |
|---|---|---|---|---|
| 28,800 | 0.32 s | 0.68 s | 2.05 s | 1.14 ms |
| 7,200 | — | 0.185 s | 0.546 s | 0.30 ms |

The per-quad cost scales with F (ratio 3.8 for 4× faces). The test exists to exclude exactly this.

**Full binding checks**, counted by a thread-local probe in `matches_source_faces`:

| Output vertices | Checks |
|---|---|
| 121 | 130 |
| 441 | 450 |
| 1,681 | 1,690 |

That is **one O(F) binding check per output vertex, plus 9**, at `SourceAuthoritativeMeshValidator.cpp:1186`.

**Chart-face keying.**
- Every quad's `chartFaces` is all 28,800 faces, one distinct key.
- For each of the 3,600 samples, `SourceProjectionCache::allowed_faces(const std::vector<int>&)` copies, sorts, de-duplicates and map-compares those 28,800 ints.
- A scratch prototype keyed by chart component instead removed 28% (0.68 → 0.49 s), bit-identically.

**Remaining per-quad O(F) work**, after both prototypes (profile at 1,600 quads):

| Site | Share |
|---|---|
| `OutputProjectionCache` constructor (scans every chart face into a scope set, per quad) | 32% |
| `validate_source_authoritative_surface_mesh` | 28% |
| `consistent_source_scope` | 16% |
| `resolve_compatible_chart` (copies the chart face list) | 7% |
| `quad_reference_surface_point` | 7% |

The slope is still 0.56 ms per quad at F = 28,800 (0.16 ms at 7,200).

## RA-206.3 CB91 — exact patch (`M6-CP3-CB91-P13-FINAL-VALIDATION-BINDING-COST-EVIDENCE`, ID kept)

- **Precheck:** `git diff --quiet e00ef91a8a5dff8b125c9abfe388952cec20cbe1 HEAD -- src include tests benchmarks CMakeLists.txt cmake`.
- **Patch:** [`Architecture_M6_CP3_CB91_P13_Final_Validation_Binding_Once.diff`](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_CB91_P13_Final_Validation_Binding_Once.diff").
  - SHA-256 `c323ae01e44a96998c07c2e0e0fd30b70d3d867201e49d97480003198d1c4a43`.
  - 177 lines; **keep its 5 single-space context lines**.

  | Path | Numstat | Result SHA-256 |
  |---|---|---|
  | `include/directional/geometry/SourceTopologyRegions.h` | `10 0` | `fe154e30cda51b11530caee121a3e45602d8e99489f08d769d56f768c08027e5` |
  | `src/validation/SourceAuthoritativeMeshValidator.cpp` | `8 9` | `3ea9ff27940d6bfb7c8914066a4905c0a4dbaae9cbd1002019070fa15024e766` |
  | `tests/SurfaceMeshOptimizerPhase22Tests.cpp` | `55 31` | `ec5c94e6adff1253bdb806c85de20a32f3b5011b2444978a28256b037eb121b8` |

- **Content:**
  1. **`source_binding_check_count()`,** a thread-local diagnostic counter incremented by `SourceTopologyRegions::matches_source_faces`. It is diagnostic only, like `SourceProjectionCache::queryCount`, and has no semantic effect.
  2. **The validator checks the loop-invariant binding once,** before the provenance loop, instead of once per output vertex. The local-sheet check reuses that result. Semantics are identical: `matches_source_faces` is `const noexcept` on unchanged inputs.
  3. **Row 899 (test name unchanged, so the selector bytes are unchanged)** validates a 100-quad and a 400-quad grid on the same 28,800-face source. It asserts:
     - source-authoritative validation was used in both runs;
     - binding checks are in (0, 16] (measured: 9);
     - the two counts are equal;
     - a coarse `< 5.0 s` backstop. The comment records the 3.5× Linux ratio.
- **Verified in scratch:**

  | Check | Result |
  |---|---|
  | Local gate, 899 rows | **898/899** (only row 283, O16) |
  | Census digests (Plane, MultiFaceSeam, CloseSheets, Cylinder, BunnyRandom, Vase) | **129/129 items byte-identical** to the [post-CB90 reference](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_CB90_P13_Platform_Digest_macOS_FMAoff_Reference.tsv"), including every `validation` hash |
  | Row 899 | PASS in 3/3 runs |
  | M1 (per-vertex check restored) | **FAILS**: 450 > 16, 130 ≠ 450 |
  | M4 (RA-202's CB88 revert) | **FAILS**: 30,409 > 16 |
  | Equality alone | **does not** kill M4, because its checks scale with source faces; hence the absolute bound |
  | GCC 16 `-Wall -Wextra -fsyntax-only`, CI defines | clean on the changed lines |

- **Build:** one eight-target Linux Release/static GMP/GMPXX package, `runtimeExecution=false`.
- **Routes:**
  - mismatch → `M6-CP3-PLAN-P13-FINAL-VALIDATION-BINDING-STOP`;
  - infrastructure → `M6-CP3-CB91A-P13-FINAL-VALIDATION-BINDING-ORCH`.
- **Not in CB91:** the chart-keyed projection mask. It is a correct 28% cut, but one of five per-quad chart-face sites, and those belong in one design (O33, RA-206.5).

## RA-206.4 TB81 — `M6-CP3-TB81-P13-FINAL-VALIDATION-BINDING-FULL-GATE-EXEC`

- **Package:** the immutable CB91 package, artifact-only.
- **Gate:**
  - the TB78 manifest, 899 rows (`9d2c1ec5…`), reused unchanged, with ledger v5;
  - **899/899**, membership 980;
  - row 899 PASS.
- **Census:** manifest `3af1dc0d…`.
  - Cylinder PASS.
  - BunnyRandom P13-e at vertex 49.
  - Vase RED `SelfIntersectingFace` within 600 s, with 192,482 / 26,817.
  - Record `completedQuads` without pinning it (RA-205).
- **Pinned behaviour-neutrality falsifier.** All seven `platform-digest` lines must be **byte-identical to TB80's** (the TB80 report's verbatim block). They are Linux-observed values, so pinning them is allowed (RA-203.2). CB91 changes no validation outcome.
- **Routes:**
  - match → the Review track (RA-206.7);
  - mismatch → `M6-CP3-TB81-P13-FINAL-VALIDATION-BINDING-FULL-GATE-REV` (Review, Claude, scratch build). A mismatch is any RED, any digest-line difference, or a missing or duplicate line;
  - infrastructure → `M6-CP3-TB81A-P13-FINAL-VALIDATION-BINDING-ORCH`.

## RA-206.5 New obligation O33: per-quad O(F) chart-face work

Final validation and the optimizer still materialize or scan a whole chart's face list for every quad or sample, at five sites (RA-206.2).

- **Today's cost:** about 0.56 ms per quad at F = 28,800.
- **Projected for Vase:** about 2,400 faces and about 68,000 quads once it reaches validation, which is several seconds on macOS and about 3× that on Linux.
- **Not blocking yet:** Vase stops at completion.
- **Owner:** `M6-CP3-DEFN-P13-CHART-FACE-PER-QUAD-COST` (Review, Claude, scratch build). It designs one chart-level cache:
  - chart handles instead of copies;
  - per-chart projection masks (the RA-206.2 prototype);
  - per-chart scope sets.

  Its deterministic witness is a count of chart-face-list materializations, constant in quad count. It runs before Vase reaches optimization.

## RA-206.6 Wall-clock guards

A wall-clock bound in a gated test is a cross-platform measurement. Two rules follow:
- set it from the Linux runner's ratio for that code (memory-bound sections reach 3.5×), not from a macOS run;
- prefer a deterministic counter that kills the regression's mutant, with a coarse time bound only as a backstop.

The other six gated wall-clock rows have at least 4× Linux margin (RA-206.2) and stay. Convert each to a counter when its code is next touched.

## RA-206.7 Turn sequence

| Step | Turn | Track |
|---|---|---|
| 42F — COMPLETE | `M6-CP3-CB90-P13-ARRANGEMENT-CELL-ORDER-TIEBREAK` | Implementation agent |
| 42G — COMPLETE (MISMATCH) | `M6-CP3-TB80-P13-ARRANGEMENT-CELL-ORDER-FULL-GATE-EXEC` | 898/899; row 899 only; census MATCH |
| 42I — Review COMPLETE | `M6-CP3-TB80-P13-ARRANGEMENT-CELL-ORDER-FULL-GATE-REV` | ChatGPT, reviewed by RA-206 |
| 42J — NEXT (already opened) | `M6-CP3-CB91-P13-FINAL-VALIDATION-BINDING-COST-EVIDENCE` | Implementation agent; **apply RA-206.3 exactly** |
| 42K | `M6-CP3-TB81-P13-FINAL-VALIDATION-BINDING-FULL-GATE-EXEC` | Implementation agent; RA-206.4 |
| 43 (Review) | `M6-CP3-DEFN-P13-ROW-PERMUTATION-SEEDS` (O32a) | Claude, scratch build |
| 43B (Review) | `M6-CP3-DEFN-P13-COMPLETED-MESH-ORIENTATION` (P13-l) | Claude, scratch build, after O32a |
| 44 / 44A / 44B (Review) | P13-e; O31; O32b–e | Claude, scratch build |
| 44C (Review) | `M6-CP3-DEFN-P13-CHART-FACE-PER-QUAD-COST` (O33) | Claude, scratch build; before Vase reaches optimization |
| 45 | P13 re-census → metamorphic census rows → matrix 6/6 → slices → CP3-REV | One slice at a time |

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | TB78 manifest `9d2c1ec5…` re-hashed. CB91 keeps every test name, so TB81 reuses it unchanged |
| Decisive claims independently re-derived | CB90 diff scope. TB80 raw log and resources downloaded and read. Stopwatches measured. F×Q scaling measured. Binding checks counted. Profile taken. Every CB91 claim verified on a byte-identical scratch tree |
| Non-vacuity checked | M1 and M4 both fail the new assertions. The digest check is a 129-item equality |
| Prior obligations discharged/carried | Row 899 candidate → owned by CB91 → TB81. O30b, O31, O32a–e, P13-l, P13-e, O27–O29, DR1/DR3 carried. New O33 |
| Stable accounting | 66 / 17 / 49, debt 1; CP2 491/491; selector497 and CP3 unpromoted |
| New candidates/obligations recorded | O33; the wall-clock rule |
| ORIENTATION currency line | `M6-CP3-TB80-P13-ARRANGEMENT-CELL-ORDER-FULL-GATE-REV` reviewed by RA-206 |
| ORIENTATION §3 / §4 / §7 / §8 | §7 and §8 updated; §3 and §4 unchanged |
| CHANGELOG | RA-206 entry |
| ROADMAP | n/a |
| Selector manifest | n/a: unchanged |
| LESSONS | Wall-clock guards and counting the claimed invariant |
| Consolidation under CLEAN_UP_POLICY | The TB80 Review is retained with a review line |
| Successor frozen | CB91 exact (RA-206.3), TB81 (RA-206.4) |
| Turn boundary held | No product, test, fixture, selector or build source changed in the repository; the patch is a committed `.diff`. Scratch probes only |
| review_check.py boundary | Run before the push |
| `STATUS` lifecycle maintained | Not written: `M6-CP3-CB91-…` is IN_PROGRESS (`c714b4f8c`), and overwriting its beacon would break the implementation agent's lifecycle. Its content is replaced by this record |
| Pushed to origin, branch in sync | Confirmed with `git status -sb` after the push |
