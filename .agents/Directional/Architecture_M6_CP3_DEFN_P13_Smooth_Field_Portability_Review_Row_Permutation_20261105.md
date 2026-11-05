# RA-205 — Review of `M6-CP3-DEFN-P13-SMOOTH-FIELD-PORTABILITY` (RA-204): cross-library fix confirmed, DESIGN §10.1 row-permutation invariance fails (2026-11-05)

**Turn:** a re-entry of `M6-CP3-DEFN-P13-SMOOTH-FIELD-PORTABILITY` for an adversarial review of its only record, [RA-204](Architecture_M6_CP3_DEFN_P13_Platform_Split_Review_Arrangement_Cell_Order_20261105.md), and the exact CB90. A concurrent ChatGPT session opened this turn (`96aca2a7c`) and only removed its snapshot trigger (`617f5c2e4`). It produced no record.

**Source:** HEAD `617f5c2e4`. `git diff --quiet 9c9616695 HEAD -- src include tests benchmarks CMakeLists.txt cmake` passes. CB90 is not applied on origin.

**Scratch build:** RA-204's build B, with CB90's tie-break, is an FMA-off clang/libc++ static build of the HEAD source. The census probe TU gains `PROBE_PERMUTE_FACES=SEED`. It applies a consistent row permutation to `mesh.faces` and `field.raw` after the field is generated, so mesh, field and corner order are identical and only row order changes. The tracing probes in RA-205.4 were reverted afterwards.

## RA-205.1 What RA-204 got right (re-verified)

- **The cross-library mechanism.** Arrangement cell ids follow `std::sort`'s unspecified order for equal `cell_cycle_key`s, and that order differs between libc++ and libstdc++. Randomized ties vary Vase between 67,753 and 67,827 quads. With CB90 applied, the count is 67,746 in every order.
- **CB90 is correct for its stated purpose,** which is that one input gives one output whichever standard library builds it.
- **No other unspecified order in the stages RA-204 relied on:**
  - **Completion's hash containers** (7 in `PureQuadCompletion.cpp`) were not checked by RA-204. They are order-safe: the loops over `canonicalQuadDuplicateOwners` (3371, 3586) only sum bytes or fill `ownershipConflicts`, which is then sorted and de-duplicated. The other maps are only looked up.
  - **The simplification queue** (`QueueEntry`) is tie-broken by `stableId`.
  - **The arrangement** has no heap or `std::partition`.

## RA-205.2 Accuracy and completeness defects in RA-204

1. **"This is no longer a determinism defect" (RA-204.4 item 5) is wrong.** DESIGN §10.1 is normative:
   - *"Canonical ordering uses semantic tuples of typed source identities. Hashes, object addresses, thread completion order, source-face row order, and output row order do not participate."*
   - *"region and producer scheduling permutation preserves [the semantic output digest]"*.

   RA-204's own randomized runs show the completed-quad count changing with the cell schedule alone (embedding fixed). That violates §10.1, so it is not only a P13-l quality matter. The owner is completion's ownership repair (`PatchDescriptor.cpp` 3120–3150). It greedily covers the conflict graph, breaks equal degree by **patch id** (that is, cell id), and spends a bounded repair budget, `maxCompletionOwnershipRepairs`.
2. **CB90's tie-break is a representation order.**
   - Halfedge ids follow segment construction, which sorts by `sourceFace` row index (`SurfaceArrangement.cpp` 1904).
   - CB90 therefore replaces a library-dependent order with a source-face-row-dependent one.
   - It makes Linux and macOS agree, but it is not §10.1-conformant.
   - The canonical key `cell_cycle_key` is far from injective: 10,891 tied pairs among 26,817 cells. Its nodes are identified only by the source entity that holds them, and most cells lie inside one source face.
3. **"Linux's 67,784 and macOS's 67,829 are two draws from this distribution" overclaims.** O30b, Linux's different Vase embedding, is still open. Only CloseSheets, whose embedding is equal on both platforms, can attribute a Linux difference to cell order alone.
4. **RA-204 measured no metamorphic invariant.** DESIGN §10.1 lists them as mandatory. M3 requires "tracing-order and start-port permutation invariance passes" and M6 requires "source-row, output-row, and scheduler permutation invariance passes" (DESIGN §14). A platform-determinism review should have run the cheapest one, a source-face row permutation. RA-205.3 does.

## RA-205.3 Source-face row permutation (measured)

| Stage element count | Unpermuted | Seed 1 | Seed 2 | Seed 3 | Seed 4 |
|---|---|---|---|---|---|
| source … `global-conformity-baseline` (13 stages) | as unpermuted | same | same | same | same |
| `tracing` (segments) | 192,482 | 192,979 | 192,770 | 193,624 | 193,432 |
| `strands` = `embedding` | 30,989 | 30,998 | 30,998 | 31,008 | 31,008 |
| `arrangement` = `simplification` | 26,817 | 26,817 | 26,817 | 26,817 | 26,817 |
| `completion` (quads) | 67,746 | 67,771 | 67,777 | 67,777 | 67,784 |
| verdict | RED `SelfIntersectingFace` | same | same | same | same |

- **CloseSheets:** 200 quads and PASS under three permutations. Its hashes differ, as expected: they embed row indices and are same-artifact diagnostics only (§10.1).
- **Reading.** The first stage whose count depends on source-face row order is **tracing**. Every later count inherits that dependence, and completion adds its own (RA-205.2 item 1).
- **This is new obligation O32:** production violates the §10.1 source-face-row metamorphic invariant on Vase. It is an M6 exit (CP3-exit) blocker, and it is not platform-specific.

## RA-205.4 Localizing O32's first owner (scratch probes)

1. **Refuted lead: the adaptive seed candidate tie.** `AdaptiveSeedCandidate::operator<` (`SurfaceCellTracing.h` 2770) breaks distance ties by face row.
   - I replaced it with the face's sorted vertex triple, which is row-invariant.
   - Unpermuted and permuted Vase results were then bit-identical to the earlier runs (tracing `6c19b74c…` / `086e21f9…`, quads 67,746 / 67,771). This tie is not the owner.
2. **First owner: the seed set.** A row-invariant digest of the seeds compared the base run with permutation seed 1. It sorts the seeds' 3D positions, rounded to 1e-7, together with their provenance. The canonical candidate tie was still in place.

   | Run | Seeds | Sorted-position digest |
   |---|---|---|
   | unpermuted | **1,456** | `192d254c…` |
   | permutation seed 1 | **1,461** | `43b925de…` |

   So `generate_deterministic_surface_seeds` (`SurfaceCellTracing.cpp` 10297) is row-order dependent. That is upstream of every trace.
3. **Remaining candidates, for the DEFN to discriminate.** Leads, not conclusions:
   - rail-sample seeding and its `seen` de-duplication key (a sample on a shared edge belongs to two faces);
   - the face-corner node layout of `intrinsicGraph` and its `nearest` distances;
   - seed placement toward the chosen face's centroid.

## RA-205.5 Realignment

- **CB90 → TB80 stand unchanged** (RA-204.7–.9).
  - CB90 is narrow and verified (local gate 898/899, only O16). It is what makes macOS Review probes predict Linux.
  - It is interim with respect to §10.1, not wrong. A canonical, injective cell key (O32, item d below) would leave its tie-break unreachable but harmless. No rework is planned.
- **O32 is now a CP3-exit condition,** added beside "matrix 6/6" in TODO. It is owned by a Review program, one stage at a time and upstream first:

  | Item | Stage | Owner |
  |---|---|---|
  | a | seed set | `M6-CP3-DEFN-P13-ROW-PERMUTATION-SEEDS` (next Review turn) |
  | b | tracing proper | named once (a) is invariant |
  | c | strand selection | named once (a) is invariant |
  | d | arrangement cell identity | an injective canonical key: node identity plus exact barycentrics on the canonical source entity |
  | e | completion ownership repair | a canonical tie and a budget independent of order |

  Each item gets one probe DEFN and one exact CB/TB pair. Its falsifier is the stage count, plus a row-invariant content digest, under three or more permutations.
- **Upstream first, then P13-l.**
  - The seed fix will change every Vase trace, so registrations taken before it would churn. The P13-l DEFN therefore runs on the post-seed-fix state.
  - The P13-l verdict (`SelfIntersectingFace`) is invariant under permutation, so its diagnosis is not blocked: only its registrations wait.
  - P13-e (BunnyRandom, stops at the atlas, upstream of tracing) is unaffected and may run in parallel.
- **Pin only permutation-invariant values.** P13 registrations should pin typed verdicts and the counts shown invariant in RA-205.3 (through `global-conformity-baseline`, and `arrangement`). Trace, strand and completed-quad counts are recorded, not pinned, until O32a–e close. TB80 already records `completedQuads` without pinning it. Its pinned 192,482 trace segments is valid only for the fixed row order, and TB80 uses exactly that.
- **Gate coverage gap.** No gate row runs the production pipeline on a census fixture under a source-face row permutation. Row 2 (`SourceFaceRowPermutationPreservesOccurrenceIdentity`) covers occurrence identity on a small fixture. O32's final CB adds the metamorphic census rows once the counts are invariant.

## RA-205.6 Turn sequence

| Step | Turn | Track |
|---|---|---|
| 42E — Review COMPLETE (re-entered) | `M6-CP3-DEFN-P13-SMOOTH-FIELD-PORTABILITY` | RA-204, reviewed by RA-205 |
| 42F — NEXT | `M6-CP3-CB90-P13-ARRANGEMENT-CELL-ORDER-TIEBREAK` | Implementation agent; unchanged (RA-204.7) |
| 42G | `M6-CP3-TB80-P13-ARRANGEMENT-CELL-ORDER-FULL-GATE-EXEC` | Implementation agent; unchanged (RA-204.8) |
| 43 (Review, next) | `M6-CP3-DEFN-P13-ROW-PERMUTATION-SEEDS` (O32a) | Claude, scratch build. Make the seed set row-invariant (count and sorted-position digest equal under ≥3 permutations) → exact CB → TB; then re-measure tracing and strands and name O32b/c |
| 43B (Review, after 43) | `M6-CP3-DEFN-P13-COMPLETED-MESH-ORIENTATION` (P13-l) | Claude, scratch build, on the post-O32a state. After TB80 it opens with the RA-204.9 O30 decision |
| 44 (Review, parallel) | `M6-CP3-DEFN-P13-SINGULARITY-PORT-COUNT` (P13-e) | Claude, scratch build |
| 44A | `M6-CP3-DEFN-P13-RELIEF-NOISE-TIES` (O31) | Claude, scratch build |
| 44B | O32b–e DEFNs, one stage each, upstream first | Claude, scratch build |
| 45 | P13 re-census → metamorphic census rows → matrix 6/6 → slices → CP3-REV | One slice at a time |

The implementation agent takes 42F and 42G, one turn each. Later implementation turns come only from the exact patches those DEFNs freeze.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | n/a: no selector change; TB80 reuses the TB78 manifest `9d2c1ec5…` (RA-204) |
| Decisive claims independently re-derived | DESIGN §10.1 and §14 (M3, M6) read verbatim. Completion's hash-container loops and the repair tie-break read at source. Four Vase and three CloseSheets permutations run. Seed-set digests measured |
| Non-vacuity checked | The permutation changes row order only, so stage counts through `global-conformity-baseline` stay equal, which is a control. The seed-tie probe changed code on the seeding path, and identical output refutes that lead rather than passing vacuously |
| Prior obligations discharged/carried | RA-204's O30a, O30b and O31 carried as stated. RA-204.4 item 5 corrected. New O32a–e |
| Stable accounting | 66 / 17 / 49, debt 1; CP2 491/491; selector497 and CP3 unpromoted |
| New candidates/obligations recorded | O32 (§10.1 source-row permutation), with the CP3-exit condition added |
| ORIENTATION currency line | Re-entry of `M6-CP3-DEFN-P13-SMOOTH-FIELD-PORTABILITY`, RA-205 |
| ORIENTATION §3 / §4 / §7 / §8 | §7 O32 and Next; §8 "Platform split" extended with metamorphic invariance; §3 and §4 unchanged |
| CHANGELOG | RA-205 entry |
| ROADMAP | n/a |
| Selector manifest | n/a |
| LESSONS | One lesson: test the design's metamorphic invariants before calling an order-dependent result deterministic |
| Consolidation under CLEAN_UP_POLICY | RA-204 retained with a review line; nothing superseded |
| Successor frozen | CB90 (unchanged); the Review track's next turn is O32a |
| Turn boundary held | No product, test, fixture, selector or build source changed in the repository; scratch probes only |
| review_check.py boundary | Run before the push |
| `STATUS` lifecycle maintained | Re-entry beacon pushed (`IN_PROGRESS`, Resumed at 2026-11-05T02:42:38Z); COMPLETE with Successor CB90 as the final write |
| Pushed to origin, branch in sync | Confirmed with `git status -sb` after the push |
