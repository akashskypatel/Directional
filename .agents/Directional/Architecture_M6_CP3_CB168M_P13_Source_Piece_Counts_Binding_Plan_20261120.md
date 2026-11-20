# CB168M — exact source-piece counts binding (frozen by TB150 Review, 2026-11-20 UTC)

## Situation

The TB150 gate is 964/964 PASS and 963/963 MATCH TB149 under N1–N3; its separate direct census is 3/3 MATCH under N1–N4. The cut-position helper works in isolation, but the production graph still represents an actual face-then-edge slide as one face chord. Before the graph can publish real slide pieces, it must carry an exact segment-to-piece binding.

## Background and scope

Authority: RA-262 §S2 EPO-3, RA-271 §S4, TB150 Review RA-272; compile source `041bde764365710e6d5148c43751da91205ffd35`. **This is one Code + Build turn with no Directional runtime.** The implementation must leave the existing face-chord producer in place. Do not implement CB169 cutover in this turn.

## Exact implementation contract

1. Add `sourcePieceCounts` as `std::vector<std::size_t>` to `ArcDraft` and `GlobalTopologyArc`, parallel to ordered `sourceFaces`. Use a descriptive field name from the contract, not the turn ID.
2. For each trace arc, require `sourcePieceCounts.size() == sourceFaces.size()` and every count is exactly **1 or 2**, with checked sum equal to `sourcePath.size()`. Reject overflow, zero counts, missing or extra counts and unmatched path sizes. Do not infer piece ownership by position, equality of coordinates, or a tolerance.
3. Segment `k` consumes exactly its recorded count of consecutive path pieces. Allowed sequences are `[face(sourceFaces[k])]`, `[face(sourceFaces[k]), edge contained in sourceFaces[k]]`, or `[edge contained in sourceFaces[k]]`. Require each recorded face piece to carry that exact source face and each edge piece to belong to its source face. The edge piece must terminate at a source vertex unless it is the **last piece of the whole arc**. Check source support, orientation, the existing endpoint chain and exact canonical path; a non-last terminal edge ending in an interior point must fail closed. Preserve canonical candidate validation and exact replay against immutable source authority.
4. Modify the existing `build_arcs` trace producer only to emit **one count of 1 for each existing source face**, with no change to its `exact_trace_path_between` call or face-chord `sourcePath`. Update all `ArcDraft` to `GlobalTopologyArc` conversion sites and aggregate initializers. Define the existing mandatory/cut arc contract explicitly and preserve its exact one-piece rule; do not fabricate trace-segment counts for nontrace arcs.
5. Update the canonical candidate/digest serialization and equality-sensitive consumers to carry and hash the counts, so removing/altering a count changes authority. Inspect every reader of `sourceFaces` and `sourcePath`, including `GlobalTopologyPlan.cpp` validation, exact replay, candidate canonicalization and source identities. The field must not become an unchecked advisory decoration.
6. Extend existing independent producer/validator tests (as required by project review policy) with one positive for each allowed shape, plus negative controls: missing/excess count, zero, count greater than 2, sum mismatch, incorrect face carrier, edge not contained in face, edge prematurely ending at a nonvertex, order permutation, path/sourceFaces inconsistency, and changed-count digest. Preserve all existing tamper cases and accepted assertions. Do not weaken a test to accept invalid geometry. At least one positive must contain two real pieces for one segment, to prove the validator is not still 1:1.

## Falsifiers / stop conditions (before implementation)

- A valid trace's `sourceFaces` count remains traversal-based, not newly inferred from geometry. If producer data cannot establish exact face/edge containment, **fail closed** rather than use epsilon matching.
- Any accepted 2-piece path that fails exact replay, canonical source support, or endpoint ownership invalidates this change; do not loosen validators.
- Any change to production cut graph, rank/ray generation, `build_arcs` geometry, representative fixtures, accepted selector, source-grid recovery or stop switch exceeds scope. Revert/exclude that change rather than fold it in.
- Nontrace arc source support must continue to pass its prior exact contract; ambiguous use of the new field must be classified before implementation.
- If source code differs from compiled CB168L semantic surface (`src/`, `include/`, `tests/`) beyond the authorized review-document edits, stop, re-establish exact source authority and re-freeze the diff before compiling.
- Compilation without required GMP and GMPXX, an unverified package, a failed compile, or a binary executed during Code + Build cannot count as CB acceptance.

## Verification split

**CB168M — Code + Build only:** verify scoped diff and negative test assertions statically; compile the same eight CB168L targets with standard remote GMP/GMPXX workflow; produce immutable source/build ZIP, full hashes, clean status and `runtimeExecution=false`. Do **not** run a compiled binary or test. A successful compile alone does not prove contract behavior.

**Separate TB151 — Test + Benchmark, not started here:** select one new required-green EPO-3 binding identity (anticipated row **965**) appended to the 964 frozen TB150 rows; preserve the 491 accepted-prefix byte identity and 81 deferred cases (anticipated membership **1046**). Reject any zero-selected case. Use immutable CB168M binary without configure, compile, relink, rebuild, patch, fixture changes or benchmarks. Run all **965** required gate cases, each in one fresh process, and all **three** fixed direct census cases in separate fresh processes. Require the new positive/negative two-piece identity to be genuinely reached, its negatives to reject, and original **964/964** rows to match TB150 under unchanged N1–N3 (complete M3 records as counted multiset, no slide-receipt removal). Require census **3/3 MATCH** TB150 under unchanged N1–N4 (only address bytes in two RED cases); Cylinder PASS, BunnyRandom/Vase RED at `:493`. Do not add normalization or promote any deferred row without independent review. Any semantic RED must route to Review, not to an ad-hoc fix in TB.

## Deferred, explicitly not authorized

EPO-2 conversion to real producer pieces, EPO-4 rays/ranks, EPO-6 edge-only traversal/O49, CB169/H4 cutover, row686 piece-aware oracle, slide-contact stop switch, O47/C5 topology repair, O48 BunnyRandom, CP3/selector497/D0 promotion and generic mesh repair. Preserve open sphere `chi=6` versus 2 (+4), `CutSearchExhaustedBeforeCellularity` in rows669/698, 66/17/49 stable accounting, one witness debt and 81 deferred.
