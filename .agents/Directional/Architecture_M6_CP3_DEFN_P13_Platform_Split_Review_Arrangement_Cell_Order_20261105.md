# RA-204 — O30 Review: the platform split is an arrangement cell-order defect, not the field (2026-11-05)

> **Reviewed by [RA-205](Architecture_M6_CP3_DEFN_P13_Smooth_Field_Portability_Review_Row_Permutation_20261105.md).** The cross-library mechanism and CB90 stand. Corrections:
> - RA-204.4 item 5 is wrong: under DESIGN §10.1, a completed count that depends on the cell schedule *is* a determinism defect;
> - CB90's halfedge tie-break is a source-row-derived order, so it is interim with respect to §10.1;
> - "two draws" overclaims while O30b is open.
>
> A source-face row permutation changes Vase's seed set, traces, strands and quads (O32).

**Turn:** `M6-CP3-DEFN-P13-SMOOTH-FIELD-PORTABILITY`, the successor frozen by the ChatGPT O30 Review ([digest adjudication](Architecture_M6_CP3_DEFN_P13_Platform_Split_Digest_Adjudication_20261105.md), `92e2e9ce8`). The user asked for an adversarial review of `M6-CP3-DEFN-P13-PLATFORM-SPLIT`. This turn reviews it, withdraws its generated-field branch and closes the turn with an exact fix.

**Source:** HEAD `6be82f33c`. `git diff --quiet 9c9616695 HEAD -- src include tests benchmarks CMakeLists.txt cmake` passes, so the source is CB89's, and its product source is CB88's.

**Scratch builds** (macOS arm64, uncommitted, outside the repository):
- **A:** default arithmetic. This is the RA-203.7 reference build.
- **B:** clang/libc++ with `-ffp-contract=off` (`bld55n`). Its tree was re-synced with `rsync --checksum` until `diff -rq` against `git archive HEAD` showed no difference. 0 scalar and 0 vector FMA instructions in its libraries.
- **C:** a standalone GCC 16/libstdc++ build of `extract_cross_field` with `-ffp-contract=off`, using libgcc's `__divdc3` algorithm compiled without contraction.
- **D:** B plus `-D_LIBCPP_DEBUG_RANDOMIZE_UNSPECIFIED_STABILITY`, a full rebuild. libc++ then shuffles every `std::sort`, `nth_element` and `partial_sort` range before sorting, with an ASLR-dependent seed. Equal elements therefore land in a different order in each process.

## RA-204.1 Verdict on the ChatGPT O30 Review

**What holds.**
- Its parse of the seven Linux lines against the 129-row reference is correct. I re-derived it independently.
- So are its first differences per case:
  - MultiFaceSeam has none;
  - Plane, CloseSheets and Cylinder first differ at `relief`;
  - BunnyRandom and Vase first differ at `fieldBits`;
  - Vase's quantized `cross-field` hash is equal, and so are its counts through `arrangement`.
- It refused to infer causation, and it refused to replace generated-field coverage.

**Accuracy defects.**
1. *"Product hashes quantize doubles to 1e-9."* This is false for the atlas.
   - `atlas_fact_digest` (`FieldTransportAtlas.cpp` 1840, 1866) hashes `std::bit_cast` of every transition and adjacency `effort`.
   - The network, cut-graph and topology-plan bindings and the tracing candidates embed that digest.
   - "First differing downstream product is the field-transport atlas" therefore carries no semantic information (RA-204.2).
   - The CB89 test comment I wrote, "(coordinates quantized to 1e-9)", states the same falsehood. I own it; CB90 corrects it.
2. *"O30 root-owner narrowed to generated smooth field and subsequent atlas."* This is refuted (RA-204.3, RA-204.4).

**Completeness defects.**
3. **CloseSheets' relief has a different element count:** 40 branches on Linux and 38 on macOS. That is a topological divergence on bit-identical mesh and field input. The Review recorded it as a "distinct observed portability issue" and gave it no owner. It is now O31 (RA-204.6).
4. **The cleanest witness was missed.**
   - CloseSheets' `embedding` is equal on Linux and macOS (`67442dd8…`), but its `arrangement` differs (`ea29f9db…` against `d433210f…`), and macOS FMA on and off agree.
   - A 36-face fixture whose arrangement differs on identical embedded input points at the arrangement, not at the field.
5. **The successor would not have found the cause.** The successor was a 2,404×12 binary64 field fixture replayed on both platforms.
   - The mechanism is library sort order (RA-204.4), so the replay would have reproduced 67,784 on Linux.
   - It would then have sent the next Review back to noise-carrying hashes ("earliest remaining stage").
   - Neither RA-203.4's second discriminator nor the TODO's GCC/libstdc++ step was run or routed.
6. **Wording.** "Six later product hashes" (Plane, Cylinder) and "ten later products" (CloseSheets) are totals that include `relief`.

## RA-204.2 Noise carriers (measured), and RA-203.4's under-specified row (owned)

On build B, Vase was run with four distinct fields:
- the build's own field;
- +1 ULP on all 28,848 coefficients;
- ±1 ULP on 100 random coefficients;
- ±1 ULP on all 28,848 coefficients.

`strands`, `embedding`, `arrangement`, `completion` and the 67,829 count are bit-identical in all four runs. Even so, these hashes change:

| Hash | Changes under |
|---|---|
| `field-transport-atlas`, `field-aligned-network`, `surface-cut-graph`, `global-topology-plan`, `global-conformity-baseline` | every perturbation |
| `tracing` | two of three perturbations |
| `strands` | FMA on/off (its cycle-quality doubles) |

These are **noise carriers**. A difference in one of them does not localize anything.

RA-203.4's row "first differing stage S → probe S" omitted that qualification. That is my error: the rule now reads "the first differing stage that is **not** a noise carrier". For Vase that stage is `embedding` (Linux `f2fc0cca…` against macOS `909330af…`). For CloseSheets it is `arrangement`.

## RA-204.3 The generated-field branch is withdrawn

- **macOS output does not depend on the field noise.**
  - Five distinct Vase fields give the same `embedding`, `arrangement` and 67,829:
    - default arithmetic, `afdad15a…`;
    - FMA off, `976eabe6…`;
    - the three ±1-ULP variants, `46dae79c…`, `475786be…` and `4c5c0593…`.
  - FMA on/off also changes every downstream floating-point operation, with the same result.
- **Linux's field differs from macOS's only below 1e-9:** the quantized `cross-field` hashes are equal.
- **Field generation is not portable, but this is recorded, not owned.** BunnyRandom's field digest takes four values on four builds:

  | Build | `fieldBits` |
  |---|---|
  | Linux | `03ee413e…` |
  | macOS default | `76b1646b…` |
  | FMA off | `134a0152…` |
  | GCC/libstdc++ with FMA off | `fa5eaf2b…` |

  The contributors are FMA contraction and the library complex algorithms:
  - `std::pow(z, 4)` is repeated squaring in libstdc++ and `exp(4·log z)` in libc++;
  - complex division is Smith's algorithm (`__divdc3`) in libstdc++ and `logb`/`scalbn` scaling in libc++.

  libm (glibc against Apple) also contributes, because C still differs from Linux.
- **Disposition:** making the generator bit-portable would need a libm-free generator. No requirement asks for that, and output is robust to this noise. The fixed-field replay is withdrawn.

## RA-204.4 O30 root cause: arrangement cell ids follow `std::sort`'s unspecified order

1. **Randomized tie order changes the result on one platform** (build D, four processes each):

   | Case | What stays the same | What changes |
   |---|---|---|
   | Vase | field, tracing, strands and `embedding` (`909330af…`) | `arrangement` takes four values; completed quads are **67,753 / 67,806 / 67,827 / 67,809**, all RED `SelfIntersectingFace` |
   | CloseSheets | `embedding` | `arrangement` takes four values; completion is unchanged |
   | Plane, MultiFaceSeam, Cylinder | every hash | nothing |

   Linux's 67,784 and macOS's 67,829 are two draws from this distribution.
2. **Site.** The sort probe instrumented all 44 `std::sort` calls in `SurfaceArrangement.cpp` and counted adjacent pairs that compare equal.
   - **The defect is at line 6762.** `pendingCells` is sorted by `cell_cycle_key`, and `cell.id` is then assigned in sorted order. Distinct cells share a key: 18 pairs among CloseSheets' 202 cells, and 10,891 pairs among Vase's 26,817. The key is a sorted set of undirected canonical edges plus source faces, so it is not injective.
   - **The other flagged sites are harmless.**
     - 2049, 2274 and 5881 sort plain values;
     - 5762 and 6744 sort keys whose equivalent elements are equal and are then de-duplicated.
3. **Fix, verified.** CB90 breaks ties by `lhs.halfedges < rhs.halfedges`. Every halfedge belongs to exactly one cell, so the order becomes total. Halfedge ids do not depend on tie order: build D's arrangement is invariant once the fix is in.

   | Build | Case | Result with the fix |
   |---|---|---|
   | D, four processes | CloseSheets | `arrangement` `5612032b…` every time |
   | D, four processes | Vase | `arrangement` `e7575660…`, `completion` `7ef76208…`, **67,746**, RED `SelfIntersectingFace`, every time |
   | B, deterministic | Vase and CloseSheets | the same values |
   | B, deterministic | Plane, MultiFaceSeam, Cylinder, BunnyRandom | unchanged |
4. **Why nothing caught it.**
   - Each library is deterministic, and two macOS runs agree byte for byte (RA-203.7).
   - Only a second sort implementation exposes the defect: Linux, or libc++'s randomization.
   - A single-platform unit test cannot observe it, so CB90 adds no test. Build D is the oracle, and TB80's comparison (RA-204.9) is the cross-platform falsifier.
5. **The completion count is still sensitive to cell order.** The spread is 67,746 to 67,829 over five orders, and RA-204.4 does not fix that sensitivity.
   - Once the order is total it is deterministic, so this is no longer a determinism defect.
   - That a valid layout depends on processing order belongs to P13-l. The completed mesh is RED in every order.

## RA-204.5 O30b: Linux-only Vase embedding difference (open, discriminated by TB80)

Linux's Vase `embedding` differs from macOS's (`f2fc0cca…` against `909330af…`), with equal counts. The embedding is upstream of CB90, and randomization does not move it on macOS. Only one candidate remains open; the others are excluded or tie-broken:

| Candidate | Status |
|---|---|
| Sort ties | excluded by build D |
| FMA | excluded: on and off agree |
| ±1-ULP field noise | excluded |
| Unordered containers | none in tracing, FlowRep or the arrangement |
| Priority queues in tracing (lines 3807, 10173, 10491) | tie-broken |
| libm differences, the x86 80-bit `long double` in the tracing grid key (`SurfaceCellTracing.cpp` 7768) and a single 1e-9 quantization flip in the embedding hash | open |

The embedding hash quantizes about 186,000 barycentric doubles, so one flip from last-bit noise is plausible. That would be a hash difference with no semantic difference. TB80's Vase count decides (RA-204.9).

## RA-204.6 O31 (new): relief critical points are decided by rounding noise

| Fixture | Linux | macOS default | macOS FMA off |
|---|---|---|---|
| CloseSheets relief branches | 40 | 38 | 40 |
| Cylinder relief branches | 44 | 44 | 48 |
| Plane relief hash | `b41394be…` | `0f8d74ab…` | `b41394be…` |

The inputs are bit-identical. FMA off reproduces Linux on Plane and CloseSheets, but not on Cylinder.

- **Mechanism.** `compute_salience_relief` forms a five-term weighted sum, which the compiler can contract into FMA. `analyze_relief_topology` then classifies critical points by exact `!=` comparison with an index tie-break (`symbolic_less`). On near-constant relief (flat or cylindrical regions), rounding noise picks the critical points.
- **Effect today.** None on completed topology: completion hashes are equal across the three builds for all four gate fixtures. It is still a determinism defect under the RA-176 rule.
- **Owner.** `M6-CP3-DEFN-P13-RELIEF-NOISE-TIES` (Review, Claude, scratch build), after P13-l. It is not CP3-blocking unless a fixture's completed topology changes across FMA on and off. That is its falsifier.

**Recorded, no new obligation:**
- The cell sort rebuilds `cell_cycle_key` on every comparison: 962,136 key builds and 8.2 s per Vase run on macOS, which is 7.5 %. A decorate-sort would cut it to 26,817 builds. This is an addendum to O20, owned by the performance slice.

## RA-204.7 CB90 — exact patch (`M6-CP3-CB90-P13-ARRANGEMENT-CELL-ORDER-TIEBREAK`)

- **Precheck:** `git diff --quiet 9c9616695ecdc8c6ec219eb7486cbe85f3915c95 HEAD -- src include tests benchmarks CMakeLists.txt cmake`.
- **Patch:** [`Architecture_M6_CP3_CB90_P13_Arrangement_Cell_Order_Tiebreak.diff`](Architecture_M6_CP3_CB90_P13_Arrangement_Cell_Order_Tiebreak.diff), applied byte for byte.
  - SHA-256 `0931939d461ad2d19a6e45e9d39fb5ba130c9846a0bd286b7a9dda0d0228ab24`.
  - 36 lines. Keep its 1 single-space context line.
- **Content:**
  - the `pendingCells` comparator in `build_surface_cell_complex` gains the halfedge tie-break and a 3-line comment;
  - the CB89 digest comment in the test is corrected.
- **Numstat and resulting SHA-256:**

  | Numstat | File | Result SHA-256 |
  |---|---|---|
  | `9 1` | `src/geometry/SurfaceArrangement.cpp` | `94d4b4e9ba3372f87f9c5854f9735efa0ecf06853a9a4a0f6cd6bcc3f6179ad9` |
  | `3 1` | `tests/SurfaceCellDesignAcceptanceTests.cpp` | `2216e82e8d2da2e20c60f5063d7aec184daaece5900573866b58005c31945c35` |

- **Build:** one eight-target Linux Release/static GMP/GMPXX package, `runtimeExecution=false`. No test is added, so membership stays 980.
- **Routes:**
  - success → TB80;
  - precheck, apply, numstat or hash mismatch → `M6-CP3-PLAN-P13-ARRANGEMENT-CELL-ORDER-STOP`;
  - infrastructure → `M6-CP3-CB90A-P13-ARRANGEMENT-CELL-ORDER-ORCH` (one retry).

## RA-204.8 TB80 — full gate and census (`M6-CP3-TB80-P13-ARRANGEMENT-CELL-ORDER-FULL-GATE-EXEC`)

- **Package:** the immutable CB90 package only, with no rebuild.
- **Gate:**
  - the TB78 manifest, 899 rows (`9d2c1ec5…`), reused unchanged, with ledger v5 (81);
  - **899/899**, membership 980;
  - rows 795, 796, 797 and 864 each log exactly one `platform-digest` line.
- **Census:** the three-case manifest `3af1dc0d…`, 600 s ceiling.
  - Cylinder PASS.
  - BunnyRandom RED P13-e at `sourceVertex=49`.
  - **Vase RED `SelfIntersectingFace` within 600 s, with trace segments 192,482 and arrangement cells 26,817.** Both counts are Linux-observed and upstream of CB90.
  - **Record `completedQuads` without pinning it** (RA-203.2).
  - Each census log has exactly one digest line.
- **Record:**
  - the seven digest lines, verbatim;
  - the comparison table in RA-204.9, as observations, not criteria.
- **Routes:**
  - match → the Review track's P13-l DEFN, which adjudicates O30 from the table first;
  - mismatch (any verdict change, a gate RED, or a missing or duplicate digest line) → `M6-CP3-TB80-P13-ARRANGEMENT-CELL-ORDER-FULL-GATE-REV` (Review, Claude, scratch build);
  - infrastructure → `M6-CP3-TB80A-P13-ARRANGEMENT-CELL-ORDER-ORCH`.

## RA-204.9 macOS post-CB90 reference and the frozen O30 decision table

[`Architecture_M6_CP3_CB90_P13_Platform_Digest_macOS_FMAoff_Reference.tsv`](Architecture_M6_CP3_CB90_P13_Platform_Digest_macOS_FMAoff_Reference.tsv) holds 129 rows from build B with CB90 (SHA-256 `955223c86c78c4ffd30dbc20fdb39a44f14cefbea271acf036d1cad59299a7d6`). FMA off was chosen because it matches Linux arithmetic for contraction.

**What TB80 records** (each Linux value next to its reference value):

| Item | Reference | Prediction if CB90 is the whole cell-order defect |
|---|---|---|
| CloseSheets `embedding` | `67442dd8c6025d7f/1128` | equal (TB79 Linux already equal) |
| CloseSheets `arrangement` and `simplification` | `5612032bbe02f5df/202` | **equal** |
| Plane, MultiFaceSeam, Cylinder `arrangement` | as TB79 Linux | equal |
| Vase `embedding` | `909330af789bee4c/30989` | O30b: equal or not |
| Vase `arrangement` and `completion` | `e7575660c00edebe/26817`, `7ef762088d515416/67746` | equal only if O30b is a hash-only difference |

**How the Review decides, at the start of the P13-l DEFN:**
- **CloseSheets equal and Vase 67,746:** O30 is closed, and future Vase registrations may pin 67,746 because Linux has then produced it.
- **CloseSheets equal, Vase different:**
  - O30a (cell order) is closed;
  - O30b stays open, and its first measurement is a semantic embedding digest on Linux. That needs an exact test-only CB, defined then.
  - P13-l continues on macOS, and its TB pins only Linux-observed counts.
- **CloseSheets different:** another library-dependent order exists in the arrangement, one that libc++ randomization does not reach (heap or iteration order). This routes to `…-FULL-GATE-REV` (Review, Claude, scratch build).

## RA-204.10 Trajectory and turn sequence

**Trajectory.** O30 has cost two implementation turns (CB89 and TB79) and two Review turns. Its root cause now has a 9-line fix.
- P13's critical path is P13-l. Vase is RED `SelfIntersectingFace` in every cell order, so the completed mesh is not consistently oriented whatever the order.
- O30 must not take more implementation turns unless a single turn decides it. TB80 does: it is the gate any product change needs anyway.
- P13-l starts from the post-CB90 state, which is deterministic across libraries, so its macOS probes predict Linux better.
- The Review track's P13-l DEFN may start now, on build B with CB90 and macOS 67,746. Its TB must pin only Linux-observed counts.

| Step | Turn | Track |
|---|---|---|
| 42D — Review COMPLETE | `M6-CP3-DEFN-P13-PLATFORM-SPLIT` | ChatGPT; reviewed and partly withdrawn by RA-204 |
| 42E — Review COMPLETE | `M6-CP3-DEFN-P13-SMOOTH-FIELD-PORTABILITY` | RA-204: field branch withdrawn; O30a root cause; exact CB90 |
| 42F — NEXT | `M6-CP3-CB90-P13-ARRANGEMENT-CELL-ORDER-TIEBREAK` | Implementation agent, Linux; compile only |
| 42G | `M6-CP3-TB80-P13-ARRANGEMENT-CELL-ORDER-FULL-GATE-EXEC` | Implementation agent; 899/899; census; seven digest lines; RA-204.9 table recorded |
| 43 (Review, can start now) | `M6-CP3-DEFN-P13-COMPLETED-MESH-ORIENTATION` (P13-l) | Claude, scratch build, post-CB90. After TB80 it opens with the RA-204.9 O30 decision |
| 44 (Review, parallel) | `M6-CP3-DEFN-P13-SINGULARITY-PORT-COUNT` (P13-e) | Claude, scratch build |
| 44A (Review, after P13-l) | `M6-CP3-DEFN-P13-RELIEF-NOISE-TIES` (O31) | Claude, scratch build |
| 45 | P13 re-census → O6/O9 → matrix 6/6 → slices → CP3-REV | One slice at a time |

The implementation agent takes 42F and 42G, one turn each, and starts 42G only after 42F is verified.

## RA-204.11 Scratch verification

| Check | Result |
|---|---|
| Scratch tree = HEAD source | `diff -rq` against `git archive HEAD` (`src include tests benchmarks cmake`, `CMakeLists.txt`): no differences before the probes |
| Build B is FMA-free | 0 `fmadd`/`fmsub`/`fnmadd`/`fnmsub` and 0 `fmla`/`fmls` in `libdirectional_core.a` and `libdirectional_pipeline.a` |
| CB90 on a clean worktree at HEAD `6be82f33c` | Precheck passes; `git apply --check` and `git apply` succeed; numstats and result hashes as in RA-204.7; code identical to the tested tie-break (comments aside) |
| Randomized build D | Full rebuild; four processes per case; results in RA-204.4 |
| Local gate, build B + CB90 (TB78 manifest, 899 rows, one process per row) | **898/899** in 1 min 42 s. The only RED is row 283, `SurfaceCellsPhase10.LegacySyntheticOutputHashIsStableAcrossTenRuns`: O16, the pre-registered macOS legacy NFunctionMesher failure, which is not SurfaceArrangement. No new RED |
| Census on build B + CB90 | Cylinder PASS; BunnyRandom P13-e RED; Vase RED `SelfIntersectingFace`, 192,482 / 26,817 / 67,746 in 108.8 s; one digest line per case |

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | The TB78 manifest was re-hashed here (`9d2c1ec598fea2b9…`, 899 rows) and is reused unchanged by TB80. Accepted CP2 selector unchanged |
| Decisive claims independently re-derived | Seven Linux lines re-parsed against both references. Atlas digest semantics read at source (`FieldTransportAtlas.cpp` 1840/1866). Noise carriers measured, not inferred. The cause localized by randomized ties, then a sort-site probe, then a fix verified under randomization |
| Non-vacuity checked | Build D does change outcomes: four distinct Vase counts and four CloseSheets arrangements without the fix. The fix makes them constant. Unaffected fixtures (Plane, MultiFaceSeam, Cylinder) stay constant in both, so the probe separates the two cases |
| Prior obligations discharged/carried | O30 is split. O30a has its root cause and exact fix CB90, discharged when TB80's CloseSheets row matches. O30b is open (RA-204.5). Carried: P13-l, P13-e, O27–O29, O16, O19, O6, O9, O25, O26, DR1/DR3 |
| Stable accounting | 66 / 17 / 49, debt 1; accepted CP2 491/491; selector497 and CP3 unpromoted |
| New candidates/obligations recorded | O31 (relief noise), O30a/O30b, an O20 addendum (cell-sort key cost) |
| ORIENTATION currency line | `M6-CP3-DEFN-P13-SMOOTH-FIELD-PORTABILITY`, RA-204 |
| ORIENTATION §3 / §4 / §7 / §8 | §3 M6-CP3 row; §4 n/a; §7 O30/O31 and Next; §8 "Platform split" gains the noise-carrier and randomized-tie rules |
| CHANGELOG | RA-204 entry added |
| ROADMAP | n/a: no milestone or checkpoint state changes |
| Selector manifest | n/a: TB80 reuses the TB78 manifest; CB90 adds no test |
| LESSONS | New lesson on randomizing unspecified order before attributing a platform split |
| Consolidation under CLEAN_UP_POLICY | The ChatGPT O30 Review is retained as evidence with a closure line. The handoff's "Earlier: TB78" section is folded to a link |
| Successor frozen | CB90 (RA-204.7), TB80 (RA-204.8), O30 decision table (RA-204.9) |
| Turn boundary held | No product, test, fixture, selector or build source changed in the repository; the patch is a committed `.diff`. Scratch probes only |
| review_check.py boundary | See the commit record: `boundary` and `ledgers` are run before the push |
| `STATUS` lifecycle maintained | Turn `M6-CP3-DEFN-P13-SMOOTH-FIELD-PORTABILITY`, COMPLETE, Successor `M6-CP3-CB90-P13-ARRANGEMENT-CELL-ORDER-TIEBREAK`, Ended at the final write; the canonical block only. Started at 2026-11-05T02:18:42Z is preserved from the turn's first repository entry, which a concurrent ChatGPT session wrote (`96aca2a7c`, with source-snapshot trigger `962882503`). This Review began at 01:34:01Z without publishing an entry beacon; that lapse is owned, and it let the second session start. RA-204 supersedes that session's work on this turn |
| Pushed to origin, branch in sync | Confirmed with `git status -sb` after the push |
