# M4-CP-SCALE-CB3 Code + Build Plan — Repair S2 Test Authority, Not Product Semantics

**Turn:** `M4-CP-SCALE-CB3`
**Boundary:** Code + Build only; `runtimeExecution=false`.
**Entering accepted authority:** package `10360085644`, semantic source `a359b981f9350139304bc5a654041dfba78609b6`, selector423 **423/423**, SHA-256 `4e67e4dc6528a71e8399cd55dce6af4c6143e2502102e421b62a8eb712d89343`.
**Rejected candidate:** `10367451675` / `63cb20d6ba5393058086c62c6422ac58b75c939e`.
**Review owner:** `M4-CP-SCALE-TB2-REV`.

## 1. Falsifiable prediction

The S2 vertex-star Filter/ExactFallback mechanism can still be independently exact-oracled **without production semantic change**, once the test supplies atlas-admissible regular field authority rather than the known-invalid flat-star `make_zero_transport_field` construction.

CB3 succeeds only if a test-local S2 fixture derived through accepted production matching/effort authority builds a valid `FieldTransportAtlas`, leaves the tested center regular/non-singular, reaches `resolve_field_vertex_transit`, and proves the frozen positive/negative/near-boundary/exact-boundary/tamper matrix against an independent exact oracle while exercising both `Filter` and `ExactFallback`.

If that cannot be achieved test-side, **STOP and return to Review**. Do not weaken atlas invariants or broaden into product repair.

## 2. Root-cause guard — mandatory before edit

CB3 must state and preserve these facts before mutation:

- the three-right-angle cone has `Theta = 3*pi/2`, center defect `K = pi/2`;
- `make_zero_transport_field` declares zero effort and no singularities and is invalid on this non-flat regular-star use;
- the rejected CB2 field therefore mismatches exact center lift `1` against composed transport `0 mod 4` and is correctly rejected with `CycleTransportMismatch`;
- this is the existing `M3-CP4c3-TB7-CAND-02` / `LESSONS.md` 22r root cause, not a new product defect;
- historical ordinal374 remains a separate deferred owner and is outside CB3.

Any proposed change that contradicts those facts must STOP.

## 3. Authorized test-source scope

Semantic/test-source changes are limited to:

- `tests/FieldAlignedCurveNetworkTests.cpp` — S2-specific field construction/oracle/assertions only.

CB3 must **not** change:

- production `src/` or `include/` semantics;
- public API;
- CMake ownership/build semantics;
- repository fixture files;
- selector423 or publish selector424;
- historical selector374 bytes;
- the body/meaning of `ResolvedBranchCorrection.FoldedConeArrivalRayElectsOneOwnerAndFalsifiesCandidateLocalElection` as an opportunistic side repair;
- S1 threshold/4096-bit guard, arrival-order S2, S3, S4, S5, CP4, row399 or row408 work.

Prefer a **new S2-local helper** instead of changing shared historical folded-cone helper semantics.

## 4. Atlas-admissible field authority

The S2 helper must author only per-face tangent cross directions and let accepted production field authority derive matching, effort and singularities through the existing raw-field/finalization path (`make_raw_cross_field` + `finalize_cross_field_result`, which invokes `principal_matching` when diagnostics are requested), or an equivalently direct production-authority path whose equivalence is stated.

Before the S2 comparator is called, the test must assert all of the following:

1. finalized matching/effort/singularity diagnostics exist and edge-transition count is complete;
2. the center vertex is **regular for this test path**: no nonzero supplied center singularity and the independently reconstructed center cycle lift is zero;
3. the transport/matching cycle composition agrees with that zero lift;
4. `FieldTransportAtlas::make` succeeds; if it fails, the test emits `field_atlas_build_error_code_name(atlasBuild.error().code)` and fails at the fixture-precondition line;
5. the arrival face/frame/branch used by the oracle exists.

A helper that manually dictates zero effort, manually invents matching, suppresses singularities, or merely catches/ignores atlas rejection is forbidden.

## 5. Independent S2 oracle and required matrix

Keep exactly one identity:

`M4CPScaleS2.VertexStarCertifiedFilterMatchesIndependentExactOracle`

It remains outside selector423 in CB3.

The expected semantic result must still be independently derived from exact subject inputs and must not call/mirror `vertex_star_compare_angle_sums`, the certified filter, or the exact-recursive comparator. Approximate/epsilon authority and post-hoc exactification of a product answer remain forbidden.

The identity must non-vacuously cover:

1. positive strict interior through `VertexStarDecisionKernelRoute::Filter`;
2. negative/opposite exact order through `Filter`;
3. a nonzero near-boundary certified case through `Filter`;
4. exact boundary through `ExactFallback` with independent half-open owner;
5. discriminating tamper that changes the independent exact expectation.

The matrix may change its exact direction representatives from CB2 because the CB2 integer seeds were not valid field authority. What may **not** change is the exact geometric comparison being proved or the requirement that both signs, near-boundary, exact-boundary and tamper are independently discriminating.

The PASS receipt must publish enough exact source data for Review to recompute every expected owner/sign and must include the route actually taken.

## 6. Non-vacuity falsifiers

CB3 must fail its own test source if any of these disappear:

- atlas-admissibility proof;
- regular-center proof;
- independent exact expected sign/owner;
- at least one `Filter` result;
- at least one `ExactFallback` result;
- near-boundary certified nonzero comparison;
- tamper crossing/changing the independent answer.

Reordering subjects so an old helper seed runs first, adding only atlas error logging, or reducing to the two historical folded-cone tests is **not** a repair.

## 7. Compile/package gate

After the bounded test-only correction, use the mandatory GitHub GMP/GMPXX compile/package workflow with `runtimeExecution=false`.

Require:

- exact changed-owner preflight for `directional_surface_cell_producer_tests`;
- authoritative eight-target compile/package matching CB2 unless the live reusable workflow proves an equivalent approved superset;
- clean source-status receipts;
- self-excluding package manifest fully verified;
- all accepted selector423 owner executables packaged;
- selector423 remains **423 LF rows / `4e67e4dc...d89343`**, first422 `bbd496f3...f7cc`;
- no generated Directional test/runtime/benchmark/discovery/CLI/fuzzer/help/version/custom-input execution.

Compile-green is not S2 acceptance and does not promote the package.

## 8. Next artifact-only harness requirement

If and only if CB3 compiles/packages GREEN, freeze `M4-CP-SCALE-TB3-EXEC` as the next turn.

Before any TB3 runtime, its harness must structurally close `M4-CP-SCALE-TB2-REV-OBS-01`:

- precompute the exact 423-row owner map and initialize a ledger row for every selector identity as `UNEXECUTED`;
- focused S2 runs first in one fresh exact-filter process;
- on focused failure, preserve the full initialized 423-row remainder and immutable package/source/execution-view census before exiting;
- on focused PASS, run selector423 as 423 fresh exact-filter processes and update each row exactly once;
- full postflight must run on success; failure-path evidence must still preserve immutable input/census receipts;
- no rebuild, repair, semantic mutation, generated discovery or benchmark.

TB3 still cannot append/promote S2 selector authority; mandatory Review adjudicates runtime evidence.

## 9. STOP rules

STOP and return to Review if:

- a regular atlas-admissible S2 subject cannot be produced through existing field authority;
- `principal_matching`/finalization necessarily marks the center singular for all needed subjects;
- satisfying both exact signs or ExactFallback requires product semantic/API changes;
- the independent oracle becomes dependent on production comparator output;
- historical ordinal374 would have to be repaired in the same turn;
- selector423 would need to change before S2 runtime proof;
- compile/package cannot preserve accepted owners/GMP authority;
- any generated Directional runtime would execute during CB3.

Do not substitute epsilon authority, weaken `FieldTransportAtlas`, suppress singularities, hand-author inconsistent matching/effort, or claim compile evidence as runtime proof.

## 10. Success criteria

CB3 is complete only when the S2 identity is test-authority-corrected on an independently certified atlas-admissible regular vertex-star construction, both Filter and ExactFallback remain non-vacuous against the independent exact oracle, the bounded test source compiles/packages GREEN with GMP/GMPXX under `runtimeExecution=false`, selector423 is unchanged, and the exact immutable candidate is ready for separately authorized `M4-CP-SCALE-TB3-EXEC` with the failure-path remainder control frozen.
