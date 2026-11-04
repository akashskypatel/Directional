# RA-203 — TB78 Review: the review-boundary block, and the Vase completed-quad platform split (2026-11-04)

**Turn:** `M6-CP3-TB78-P13-CENSUS-PATH-COST-FULL-GATE-REV`. The Claude Review resumes it from the ChatGPT Review's BLOCKED checkpoint ([WIP](Architecture_M6_CP3_TB78_REV_P13_Census_Count_Review_WIP_20261104.md)).

**Source:** HEAD `4614f6858`. `git diff --quiet 6cc50f878ef829711e16262759afb3367bec2aff HEAD -- src include tests benchmarks CMakeLists.txt cmake` passes, so the product and test source is CB88's.

**Scratch probes** used a macOS arm64 build of exactly that tree. The tree was compared with `diff -rq` against `git archive 6cc50f878` and no file differed.

## RA-203.1 The block

The ChatGPT Review stopped with `REVIEW_BLOCKER`. RA-202.9 requires the mismatch Review to re-run the RA-202 probe recipe, but `REVIEW_TURN_POLICY.md` §4.3 says a Review is runtime-free, and the RA-202.12 scripts are not in the repository.

1. **There is no policy conflict, and no amendment is made.**
   - §4.3 limits what a Review mutates (no product, test, fixture, selector, benchmark or build source) and what it may record as runtime evidence.
   - The standing rulings RA-166.6 F6 and RA-188.1, recorded in `LESSONS.md` ("Re-observe a deferred row…"), hold that Review scratch probes are a Review duty, not a breach. Such probes run on an uncommitted build outside the repository, and nothing they produce is reported as Test + Benchmark evidence.
   - Every P13 DEFN since RA-193 has used such probes.
   - No policy file is changed.
2. **The ChatGPT Review was right to stop.** The defect is in RA-202.9's route, not in the policy. The route has three faults:
   - **It does not name a track.** "Review, which re-runs the RA-202 probe recipe" omits "Claude, scratch build". That same omission produced the BLOCKED Review records at handoff rows 17, 20, 23, 26 and 29.
   - **The recipe cannot answer the question.** The RA-202.12 scripts are environment-switched cost probes of the P13-m sites. Nothing needs them in order to be reproduced. Re-running them on macOS gives 67,829, which is the number in question. A Linux/macOS split cannot be explained from one platform.
   - **Linux runtime belongs to the implementation agent,** as a TB with an exact command and a frozen comparator. This RA authorizes that execution: CB89 (a test-only exact patch), then TB79.
3. **Rule from now on.** A mismatch route that needs a probe names `Review (Claude, scratch build)`. A route that needs Linux runtime names the TB that collects it. A Review that cannot run a scratch probe records BLOCKED immediately and does not start the probe work.

## RA-203.2 RA-202.9's registration error (owned)

- 67,829 has been observed only on macOS: RA-200 onward, every run, FMA on and off.
- No Linux run had reached a completed Vase count at the P13 state:
  - TB72A ended at assembly with 0 quads;
  - TB73–TB77 timed out after assembly.
- RA-202.9 nevertheless froze 67,829 as the Linux expectation.
  - That repeats the error RA-202 itself turned into a lesson ("predict the other platform from its own history"): Linux had no history for this value.
  - ORIENTATION §8 "Platform split" (RA-176, RA-179) treats any difference between builds as a determinism defect to be computed. It cannot be a registration constant.
- **What a cross-platform registration may pin:**
  - typed verdicts;
  - topological counts;
  - values already observed on the executing platform.
  
  A value seen on only one platform is recorded, not pinned.

## RA-203.3 TB78 adjudication

Re-derived independently:
- the TB78 report;
- the WIP's independent rehash (1,806/1,806 gate entries, 9/9 census entries);
- the manifest hash `9d2c1ec5…` with its byte-identical 896-row prefix;
- the source.

| Registered (RA-202.9) | Observed (Linux, CB88 package `13358062295`) | Disposition |
|---|---|---|
| Gate 899/899, membership 980, GUARD 897–899 | 899/899, 980, 897–899 PASS | MATCH |
| Cylinder PASS | PASS, 11.69 s | MATCH |
| BunnyRandom P13-e, source vertex 49 | same | MATCH |
| Vase RED `NotProductionReady:completion detail=SelfIntersectingFace` | same | MATCH |
| `traceSegments=192482 arrangementCells=26817` | same | MATCH |
| Within 600 s | 268.93 s (TB76/TB77: ABNORMAL at 600 s) | MATCH: P13-m's Linux objective is met |
| `completedQuads=67829` | 67,784 | Registration error (RA-203.2); the split is **O30** |

**Attribution.** The 45-quad difference is not a defect of CB85–CB88:

1. **Their product hunks cannot round or reorder.** They add 78 lines with no floating-point arithmetic, hashing, sorting or unordered container, checked on the committed `.diff` files:
   - CB85 groups halfedges in a `std::map` by source face and compares integer scopes.
   - CB86 sums integer endpoint deltas.
   - CB87 builds per-vertex edge lists.
   - CB88 reuses labels.
   
   CB87 and CB88 run after the count is taken: `RemeshPipeline.cpp` 14407–14482 records `surfaceCellCompletedQuadCount` before output validation.
2. **On macOS, each fix ran beside its old computation on every call:** 16,543 cross-check lines, 0 mismatches, Vase included (RA-202.11).
3. **Linux and macOS have agreed on Vase topology through the arrangement wherever both were observed:**

   | Pair | Agreement |
   |---|---|
   | TB71 / RA-198 | 26,827 cells |
   | TB72 / RA-199 | 26,817 cells |
   | TB78 / RA-202 | 192,482 traces, 26,817 cells |

   Completion is the first stage whose count differs, and TB78 is the first Linux run that reached a completed count.

**Classification:**
- TB78 is COMPLETE.
- The count line is a Review registration error, not an executor failure.
- O30 is opened.
- No stable event: no accepted green was lost.
- Unchanged: 66/17/49, debt 1, accepted CP2 491/491. Selector497 and CP3 stay unpromoted.

## RA-203.4 O30 — the Vase completion platform split

**Statement.** The configurations differ in platform only:
- same product source (CB88), same fixture bytes, same options;
- macOS arm64 (clang, libc++, Apple libm) completes **67,829** quads;
- Linux x86-64 (GCC, libstdc++, glibc) completes **67,784**.

Upstream topological counts are equal. Neither count is "right" until it is computed. The fix must make the platforms agree (ORIENTATION §8).

**Known on macOS:** the result repeats. Two digest runs are byte-identical (RA-203.7), and an FMA-off build is identical too (RA-202).

**Candidate mechanisms (none asserted):**
- (a) ULP differences between glibc and Apple libm in field generation or geometry, flipping a discrete decision in completion (for example a rounded segment count).
- (b) Implementation-defined order: `std::sort` ties, or unordered iteration. `PureQuadCompletion.cpp` declares seven unordered containers in assembly; `TriFlowSimplification.cpp` has more.
- (c) The x86-64 80-bit `long double` (`FieldTransportAtlas.h:522`; `NFunctionMesher.h` 7708–7797). On arm64 macOS `long double` is binary64.
- (d) Compiler codegen other than FMA.

**First discriminator: TB79's digest lines against the macOS reference.** The decision table is frozen before TB79:

| Linux vs macOS reference | Meaning | Next |
|---|---|---|
| `vertexBits` or `faceBits` differ | The fixture is read differently | Stop; fixture DEFN |
| `fieldBits` differ | The generated smooth field is not platform-invariant | DEFN inside `extract_cross_field`. Design fork: make the generator invariant, or freeze Vase's field as fixture bytes |
| Inputs equal; first differing product is S | The divergence becomes macroscopic at S | DEFN probes stage S |
| All products through `simplification` equal; `completion` differs | Completion or assembly | DEFN probes `PureQuadCompletion` (unordered containers, libm in patch sizing) |

Stage hashes quantize coordinates to 1e-9 (`hash_combine_double`). Equal hashes therefore bound where the divergence becomes visible, not where it begins.

**Second discriminator** (Review track, only if the first leaves (a) against (b) open): a GCC + libstdc++ build of the same tree with `-ffp-contract=off` on macOS arm64. It keeps Apple libm, so it separates library order and codegen from libm and `long double`.

## RA-203.5 CB89 — `M6-CP3-CB89-P13-CENSUS-PLATFORM-DIGEST`

Code + Build, test-only, compile only.

- **Precheck:** `git diff --quiet 6cc50f878ef829711e16262759afb3367bec2aff HEAD -- src include tests benchmarks CMakeLists.txt cmake`.
- **Patch:** [`Architecture_M6_CP3_CB89_P13_Census_Platform_Digest.diff`](Architecture_M6_CP3_CB89_P13_Census_Platform_Digest.diff).
  - 68 lines, SHA-256 `64af5c71ad57a662724b077761f71c1c38893be6ed32516fc568166e85c23f71`.
  - Keep its 3 single-space context lines.
  - Numstat `45 0` `tests/SurfaceCellDesignAcceptanceTests.cpp`.
  - Result SHA-256 `ba60c6905db983b53c35a2b5e909a04152eaa557cac8382c84457c5d0f5b1941`.
- **Content:** after the remesh call, `ProducesDirectSourceAuthoritativePureQuadOutput` prints one line, then runs unchanged:

  ```text
  platform-digest case=<name> vertexBits=… faceBits=… fieldBits=… <product>=<structural hash>/<count> …
  ```

  - The three `…Bits` values are FNV-1a over the exact IEEE-754 bit patterns, row-major, low byte first.
  - The products are `RemeshResult::surfaceCellContext.debugProducts`, which the pipeline records for every stage even with `preserveDebugArtifacts=false`.
- **What it does not change:**
  - no product source;
  - no new test, so the test listing and gate membership are unchanged;
  - no changed assertion or failure message, so the registered terminal lines stay byte-identical.
- **Build:** one eight-target Linux Release/static GMP/GMPXX package, `runtimeExecution=false`.
- **Outcomes:**
  - success → TB79;
  - precheck, apply, numstat or hash mismatch → `M6-CP3-PLAN-P13-CENSUS-PLATFORM-DIGEST-STOP`;
  - infrastructure → `M6-CP3-CB89A-P13-CENSUS-PLATFORM-DIGEST-ORCH`.

## RA-203.6 TB79 — `M6-CP3-TB79-P13-PLATFORM-DIGEST-FULL-GATE-EXEC`

Test + Benchmark, artifact-only, on CB89's immutable package.

- **Gate:** [TB78 manifest](Architecture_M6_TB78_P13_Census_Path_Cost_Full_Gate_Case_Manifest.tsv), reused unchanged.
  - 899 rows, SHA-256 `9d2c1ec598fea2b95b251fd2e007b7086740e51fb8f6f3ad7ff5671ab09ddb44`; ledger v5 `fd433f54…`.
  - Registered **899/899**, membership **980**.
  - The raw logs of rows 795 (CloseSheets), 796 (MultiFaceSeam), 797 (Plane) and 864 (Cylinder) each contain exactly one `platform-digest` line.
- **Census:** three-case manifest `3af1dc0d…`, 600 s ceiling.
  - Cylinder PASS.
  - BunnyRandom RED `InvalidFieldTransportAtlas:field-transport-atlas/SingularityPortClassCountMismatch;sourceVertex=49`.
  - **Vase RED within 600 s:** `terminal=NotProductionReady:completion detail=SelfIntersectingFace traceSegments=192482 arrangementCells=26817 completedQuads=67784 completion=`. This is TB78's Linux value, so the run also tests repeatability on Linux.
  - Each census log contains exactly one `platform-digest` line.
- **Record:** the seven digest lines, verbatim. They are the measurement, not a criterion. TB79 makes no comparison claim.
- **Outcomes:**
  - match → Review `M6-CP3-DEFN-P13-PLATFORM-SPLIT` (O30; Claude, scratch build; decision table RA-203.4).
  - mismatch → `M6-CP3-TB79-P13-PLATFORM-DIGEST-FULL-GATE-REV` (Review, Claude, scratch build). A mismatch is any of:
    - Vase `completedQuads` other than 67,784 (Linux nondeterminism, a separate class);
    - any other verdict change;
    - a missing or duplicate digest line.
  - infrastructure → `M6-CP3-TB79A-P13-PLATFORM-DIGEST-ORCH`.

## RA-203.7 macOS reference (scratch: CB88 source + CB89)

[`Architecture_M6_CP3_CB89_P13_Platform_Digest_macOS_Reference.tsv`](Architecture_M6_CP3_CB89_P13_Platform_Digest_macOS_Reference.tsv): 129 rows (case, item, value, count) for Plane, MultiFaceSeam, CloseSheets, Cylinder, BunnyRandom and Vase. SHA-256 `7e2796fe4991553becf1006d400f288368fe9c9781a6bc0d154faaaa821a167e`; checked against the raw logs.

| Vase item | macOS value / count |
|---|---|
| `vertexBits` / `faceBits` / `fieldBits` | `eef00a8706c009f5` / `e43da6cccb821779` / `afdad15a6d246ed2` |
| `cross-field` | `8e16b454468fe056` / 2404 |
| `field-transport-atlas` | `2e362a754c773930` / 4668 |
| `tracing` | `bbb3c00341039362` / 192482 |
| `strands` / `embedding` | `239f4ed9d48125e3` / 30989; `909330af789bee4c` / 30989 |
| `arrangement` = `simplification` | `611e5aa5aabed428` / 26817 |
| `completion` | `d711fde270eada71` / 67829 |

- Two Vase processes produced byte-identical digest lines and the same terminal: 98.8 s, 1.22 GB peak RSS.
- BunnyRandom's line ends at `source-labels`, because it fails at the field-transport atlas.

## RA-203.8 Turn sequence

| Step | Turn | Track |
|---|---|---|
| 42A — Review COMPLETE | `M6-CP3-TB78-P13-CENSUS-PATH-COST-FULL-GATE-REV` | ChatGPT WIP (BLOCKED on the review boundary), then RA-203 |
| 42B — NEXT | `M6-CP3-CB89-P13-CENSUS-PLATFORM-DIGEST` | Implementation agent, Linux; compile only |
| 42C | `M6-CP3-TB79-P13-PLATFORM-DIGEST-FULL-GATE-EXEC` | Implementation agent; 899/899, membership 980; Vase 67,784; seven digest lines |
| 42D (Review, after TB79) | `M6-CP3-DEFN-P13-PLATFORM-SPLIT` (O30) | Claude, scratch build; RA-203.4 table → exact fix or the second discriminator |
| 43 (Review, can start now) | `M6-CP3-DEFN-P13-COMPLETED-MESH-ORIENTATION` (P13-l) | Claude, scratch build. Its later TB pins only typed verdicts and counts already observed on Linux |
| 44 (Review, parallel) | `M6-CP3-DEFN-P13-SINGULARITY-PORT-COUNT` (P13-e) | Claude, scratch build |
| 45 | P13 re-census → O6/O9 → matrix 6/6 → slices → CP3-REV | One slice at a time |

The implementation agent takes rows 42B and 42C, one turn each. It starts 42C only after 42B is verified. Rows 42D, 43 and 44 are Review-track probe turns (Claude, scratch build).

## RA-203.9 Scratch verification

| Check | Result |
|---|---|
| Scratch tree = CB88 source | `diff -rq` against `git archive 6cc50f878` (`src include tests benchmarks cmake`, `CMakeLists.txt`): no differences |
| CB89 on a clean worktree at HEAD `4614f6858` | Precheck passes; `git apply --check` and `git apply` succeed; numstat `45 0`; result hash as above, byte-identical to the scratch file |
| Test listing | Same 614 producer-test names as the CB88 binary (sorted full names identical) |
| Compilers | clang (Apple, `-O3`) compiles and runs it. GCC 16 `-std=gnu++20 -Wall -Wextra -fsyntax-only` with the CI defines accepts it, with no diagnostic on the added lines |
| macOS census with CB89 | Plane, MultiFaceSeam, CloseSheets and Cylinder PASS; BunnyRandom P13-e RED; Vase RED, 192,482 / 26,817 / 67,829; one digest line per case; Vase repeat byte-identical |

The scratch build relinked only the producer test binary against CB88's static libraries. The macOS periodic `/tmp` cleaner had removed `build.ninja` and most objects from the scratch build.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | TB78 manifest `9d2c1ec5…` re-hashed by the WIP and re-checked here; its 896-row prefix is byte-identical to TB77 `48ef4743…`. Accepted CP2 selector unchanged |
| Decisive claims independently re-derived | Source equality with CB88 (`git diff --quiet`, `diff -rq`); CB85–CB88 product hunks scanned for floating-point, hash, sort and unordered constructs (none); the history of Linux and macOS topological counts (TB71/RA-198, TB72/RA-199, TB78/RA-202); the macOS Vase count and digests from two fresh processes |
| Non-vacuity checked | The digests are bit-exact for inputs and per-stage for products. Two runs agree on macOS, so a Linux difference cannot be noise from the printer. Missing or duplicate digest lines are a TB79 mismatch, so a binary without CB89 cannot pass silently |
| Prior obligations discharged/carried | P13-m: Linux objective met (268.93 s), discharged for cost. O27, O28, O29 carried (Review P13-l). P13-l and P13-e carried. O16, O19, O6, O9, O25, O26, DR1/DR3 carried. DR2/DR4 stay with M8-CP2 |
| Stable accounting | 66 / 17 / 49, debt 1; accepted CP2 491/491; selector497 and CP3 unpromoted |
| New candidates/obligations recorded | O30 (Vase completion platform split): tracker, ORIENTATION §7, TODO |
| ORIENTATION currency line | `M6-CP3-TB78-P13-CENSUS-PATH-COST-FULL-GATE-REV`, 2026-11-04 |
| ORIENTATION §3 / §4 / §7 / §8 | §3 M6-CP3 row updated; §4 n/a (no fixture change); §7 Immediate, P13-m, O30 and priority row updated; §8 "Platform split" extended to registrations |
| CHANGELOG | RA-203 entry added |
| ROADMAP | n/a: no milestone or checkpoint state changes |
| Selector manifest | n/a: TB79 reuses the TB78 manifest unchanged; no new rows |
| LESSONS | Amended the RA-202 lesson ("Time the whole run…") with registrations from one platform |
| Consolidation under CLEAN_UP_POLICY | The handoff's older "Earlier" sections are folded to links (their facts are in TODO, CHANGELOG and the records). The ChatGPT WIP is retained as evidence, with a closure line |
| Successor frozen | `M6-CP3-CB89-P13-CENSUS-PLATFORM-DIGEST` (RA-203.5); TB79 falsifiers in RA-203.6; O30 decision table in RA-203.4 |
| Turn boundary held | No product, test, fixture, selector or build source changed in the repository; the patch is a committed `.diff`. Scratch probes only (RA-203.1) |
| review_check.py boundary | `boundary`: ALL CHECKS PASSED; `ledgers --base d8c24645b`: ALL CHECKS PASSED (CHANGELOG and LESSONS did not shrink) |
| `STATUS` lifecycle maintained | Turn `M6-CP3-TB78-P13-CENSUS-PATH-COST-FULL-GATE-REV`, COMPLETE, Successor `M6-CP3-CB89-P13-CENSUS-PLATFORM-DIGEST`, Started at 2026-11-04T21:08:48Z (preserved), Resumed at 2026-11-04T22:20:08Z, Ended at the final write; the canonical block only |
| Pushed to origin, branch in sync | Confirmed with `git status -sb` after the final push |
