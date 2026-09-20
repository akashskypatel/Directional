# M5-CP1-CB3 Test-Authority Correction Code + Build Plan

**Turn:** `M5-CP1-CB3`
**Milestone/checkpoint:** M5 / CP1
**Mode:** Code + Build / test-authority-only correction
**Reviewed runtime:** `M5-CP1-TB1-R2-EXEC`, run `35491016562`
**Semantic product source under review:** `b98f461b9a392cc182891a81c0a84b0b01dfbb45`
**Accepted runtime authority:** M4 package `10591801825` / selector430 **430/430**
**Review authority:** `Architecture_M5_CP1_TB1_R2_Review_Record.md`

## 1. Objective

Correct only the invalid witness precondition in:

`M5CP1.SelectedRelationPathCertificateSurvivesRelationContainerPermutation`

R2 proved the current helper-backed test starts with exactly one periodic relation and therefore aborts before its intended permutation/materialization/certificate invariant. Independent Review found no demonstrated product semantic defect and froze a test-only correction.

CB3 must not broaden into product work.

## 2. Authorized source edit

The only semantic source file authorized to change is:

`tests/SurfaceCellTransitionQuotientTests.cpp`

Within that file, change only the body of:

`TEST(M5CP1, SelectedRelationPathCertificateSurvivesRelationContainerPermutation)`

The correction must:

1. create the materializable baseline from `direct_full_periodic_materializer_draft()`;
2. derive one **distinct valid unused periodic relation** from an existing owner using the already runtime-green row7 construction pattern:
   - same `sourceTopologyRegion`;
   - same action/value;
   - owner `cutRoute()` as generator route and owner `route()` as cut route;
   - checked `SurfacePeriodicHolonomy::make(...)`;
3. prove the constructed relation ID is absent from the baseline table before insertion;
4. append the constructed relation to the baseline table;
5. copy that complete table into `reorderedDraft`;
6. require at least two distinct relation IDs and record/prove that reversing the reordered table changes its first stored relation ID;
7. reverse **only** `reorderedDraft.periodicHolonomies`;
8. materialize baseline and reordered drafts;
9. require both materializations to succeed;
10. compare:
    - complete `selected_relation_certificate_signature(...)`;
    - `directional::pipeline::hash_completion(...)`;
    - `consumedPeriodicHolonomies`.

The baseline and reordered subjects must therefore have identical relation membership and values; only relation-table storage order may differ.

## 3. Frozen surfaces

CB3 must not change:

- any file under `src/` or `include/`;
- `direct_full_periodic_materializer_draft()` or another shared test helper;
- row7 `UnusedValidPeriodicRelationDoesNotChangeSelectedCertificate`;
- row9 `PeriodicRelationOwnersSurviveContainerReorderingBeforeMaterialization`;
- fixtures or benchmark data;
- any `Required_Green_Selector_*.txt`;
- `Required_Green_Selector_Manifest.md`;
- CMake/build scripts or reusable workflows;
- M5 frozen definitions;
- production-debt ownership or discriminators.

Selector430 must remain exactly **430 LF rows** at SHA-256:

`1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`

and its first427 prefix must remain:

`f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`

Because `SurfaceCellTransitionQuotientTests.cpp` also owns accepted selector identities, the CB3 diff must explicitly prove that no accepted selector test body or shared helper was edited.

## 4. Build/package gate

Use the mandatory reusable GitHub compile workflow under `GMP_COMPILE_POLICY.md`. No local compile is authoritative.

Compile/package all standard test/benchmark targets required by the existing artifact-only selector430 execution surface so the successor can consume one complete immutable package. Require:

- `DIRECTIONAL_ENABLE_GMP=ON`;
- exact arithmetic backend `GMP`;
- explicit `gmpxx` + `gmp` linkage evidence;
- successful compile/link of the standard package target set;
- clean source-status receipts;
- `runtimeExecution=false`;
- immutable packaged source archive;
- package root manifest complete and self-verifying.

CB3 runs **no Directional test, benchmark or generated runtime**.

## 5. Static acceptance and falsifiers

CB3 is green only if all of the following hold:

- changed semantic source path set is exactly `tests/SurfaceCellTransitionQuotientTests.cpp`;
- the changed hunk is confined to ordinal-6's test body;
- no shared helper or accepted selector identity body changes;
- the corrected test visibly constructs and inserts a distinct second relation before copying/reversing the table;
- the two compared drafts have the same relation membership and differ only in storage order;
- reversal is asserted nontrivial;
- selector430 and first427 hashes are byte-identical to accepted authority;
- mandatory GMP compile/package is green;
- package evidence says `runtimeExecution=false`.

Stop and preserve evidence without widening the patch if:

- the second relation cannot be constructed without changing product/shared-helper/fixture authority;
- the correction would require changing relation identity/value semantics;
- any accepted selector row/body must be weakened or retargeted;
- selector bytes change;
- compile/GMP/package evidence is red;
- the diff touches any unauthorized semantic source.

A CB3 compile failure does not authorize a product fix inside the same turn.

## 6. Successor boundary

If CB3 is green, the exact successor is:

`M5-CP1-TB1-R3-EXEC`

R3 must use the newly packaged immutable candidate and rerun the complete CP1 gate from ordinal 1:

- focused **9** fresh exact-filter processes in the established order;
- selector430 **430** fresh exact-filter processes;
- exact-one selection / zero skip for every row;
- immutable pre/post package/source/execution-view census;
- benchmark execution **0**;
- no build, discovery, repair, fixture/source/selector mutation.

R3 imports no failed ordinal-6 semantic credit from R2. If R3 becomes mechanically green, candidate promotion/CP1 acceptance still requires the normal independent Review turn.
