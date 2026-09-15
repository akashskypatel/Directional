# M4-CP-SCALE-CB4 Code + Build Plan — regular S2 cross-field winding authority

**Status:** FROZEN BY `M4-CP-SCALE-TB3-REV`
**Turn type:** Code + Build only; `runtimeExecution=false`
**Semantic edit surface:** `tests/FieldAlignedCurveNetworkTests.cpp` only

## 1. Purpose

Repair only the S2 folded-star **test authority** rejected by TB3 Review. Do not change production comparator, atlas, matching, public API, CMake, fixtures, selector semantics, historical ordinal374, S1, S3/S4/S5, or CP4.

The correction is successful only when the test itself independently proves that its authored non-flat cross field is a regular zero-index field before asking the vertex-star comparator for semantic evidence.

## 2. Frozen diagnosis

The three-right-angle center has `Theta=3*pi/2`, curvature defect `K=pi/2`. A regular center therefore requires

`sum_cycle_effort = -4K = -2*pi`,

so `(sum effort + 4K)/(2*pi) = 0`.

CB3 delegated matching/effort derivation to production, but authored a field whose derived aggregate cycle effort is `0`, so production correctly reports center lift `1` and a singularity. CB3 also hand-authored face 2 with a secondary direction opposite the right-handed tangent complement. Fixing handedness alone does not repair the missing `q4` winding.

## 3. Guard-first implementation

Before changing the retained six-subject oracle, construct one S2-local field authority satisfying all of these independently checkable guards:

1. Each primary/secondary pair is tangent to its source face, finite, nonzero, normalized and orthogonal.
2. Derive the secondary from the face normal and primary (`normal x primary` / the established orthogonal-complement helper), not from an independently hand-authored vector; assert positive handedness `normal dot (primary x secondary) > 0` on every face.
3. Independently reconstruct the cross-field `q4` phase around the center from the authored directions and prove winding `-1` (wrapped phase sum `-2*pi`).
4. Run the accepted production authority path `make_raw_cross_field` + `finalize_cross_field_result(..., includeDiagnostics=true)`; do not author matching, effort or singularity results by hand.
5. Independently reconstruct the center cycle effort and curvature from the finalized authority and prove aggregate effort `-2*pi`, center lift `0`, and matching composition `0 mod 4`.
6. Prove the center is absent from supplied singularities, all required edge transitions are complete, typed `FieldTransportAtlas::make` succeeds, and the subject has a valid arrival frame/branch before comparator invocation.

One statically verified admissible construction uses face-primary angle offsets `0, -pi/6, -pi/3` relative to the first face, with consistently right-handed complements; its wrapped `q4` increments sum to `-2*pi`. This is an admissible construction, **not** a requirement to hard-code that exact formula. The invariant above is normative.

## 4. Preserve the independent comparator oracle

Keep `M4CPScaleS2.VertexStarCertifiedFilterMatchesIndependentExactOracle` as one bounded identity and preserve the six-subject semantics:

- positive strict interior via `Filter`;
- negative/opposite exact order via `Filter`;
- nonzero near-boundary certified case via `Filter`;
- exact boundary via `ExactFallback` with independent half-open owner;
- discriminating tamper that changes the independent exact expectation;
- both Filter and ExactFallback must be observed non-vacuously.

Expected sign/owner must remain derived from exact subject input, independent of `vertex_star_compare_angle_sums`, the production certified filter, and the production exact-recursive comparator. Product output may never become the oracle.

## 5. Required falsifiers

CB4 test source must fail if any of the following is deliberately broken:

- reverse one face's secondary handedness;
- remove/change the authored `q4` winding so aggregate effort is no longer `-2*pi`;
- center lift becomes nonzero or production marks the center singular;
- matching composition becomes nonzero;
- atlas construction or arrival-frame/branch proof disappears;
- either Filter or ExactFallback route disappears;
- the near-boundary nonzero subject becomes exact-boundary/vacuous;
- the tamper no longer changes the independent answer.

These falsifiers prevent a second compile-green but unreachable S2 matrix.

## 6. Compile/package gate

After the bounded test-only edit:

- run exact changed-owner preflight for `directional_surface_cell_producer_tests`;
- compile/package the same eight approved targets with GMP/GMPXX using the mandatory GitHub workflow;
- require clean source-status receipts and `runtimeExecution=false`;
- verify the self-excluding package manifest completely;
- package every accepted selector423 owner executable;
- preserve selector423 exactly at 423 LF rows / SHA-256 `4e67e4dc6528a71e8399cd55dce6af4c6143e2502102e421b62a8eb712d89343`, first422 `bbd496f3396bd656d13c728ddaad806276e00b901675255e0b67241beec4f7cc`;
- execute no generated Directional test/runtime/benchmark/discovery/CLI/fuzzer/help/version/custom-input process.

Compile-green does not promote S2 or the package.

## 7. Frozen next runtime harness

If and only if CB4 compiles/packages GREEN, exact next is `M4-CP-SCALE-TB4-EXEC`, followed mandatorily by `M4-CP-SCALE-TB4-REV`.

TB4-EXEC remains artifact-only and must preserve the TB3 control improvement:

- preinitialize all 423 selector rows as `UNEXECUTED` before focused runtime;
- run focused S2 first in one fresh exact-filter process;
- on focused RED, preserve the complete 423-row remainder plus immutable package/source/execution-view postflight and stop;
- on focused PASS, run selector423 as 423 fresh processes and update every row exactly once;
- never rebuild, repair, mutate, discover generated tests or run benchmarks.

Runtime promotion remains Review-owned.

## 8. STOP rules

STOP before widening scope and return to Review if:

- no S2-local authored field can satisfy regular center lift zero through existing production matching authority;
- product/API/CMake/fixture semantics would have to change;
- the exact expected owner/sign would have to depend on production comparator output;
- historical ordinal374 or `make_zero_transport_field` call-site audit would have to be folded into CB4;
- selector423 would have to change before S2 runtime proof;
- compile/package cannot preserve all accepted selector owners/GMP authority;
- any generated Directional runtime would execute during Code + Build.

Do not weaken `FieldTransportAtlas`, suppress legitimate singularities, hand-author matching/effort, use epsilon authority, or treat compile success as runtime proof.

## 9. Success criteria

CB4 completes only when the S2 helper independently certifies a consistently oriented regular zero-index cross field on the non-flat center, production matching agrees with that authority, atlas/arrival preconditions are proved before comparator use, the exact six-subject oracle remains discriminating across both comparator routes, the authorized test-only diff compiles/packages GREEN with GMP/GMPXX under `runtimeExecution=false`, and selector423 is byte-identical for subsequent TB4-EXEC.
