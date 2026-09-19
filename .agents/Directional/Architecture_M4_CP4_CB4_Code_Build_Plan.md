# M4-CP4-CB4 — focused test-authority correction Code + Build plan

**Turn:** `M4-CP4-CB4`
**Type:** Code + Build
**Predecessor:** `M4-CP4-TB1-R2-REV`
**Runtime boundary:** compile/package only; generated Directional runtime forbidden

## 1. Purpose

Apply the smallest corrections authorized by R2 Review to the four focused REDs without changing accepted product semantics. All RED ownership is test authority / witness precondition (`RP-02`); selector427 and committed benchmark fixtures remain frozen. Build/package a new immutable candidate through the mandatory GMP reusable compile, then hand off to fresh artifact-only `M4-CP4-TB1-R3-EXEC`.

## 2. Frozen authorities

Preserve exactly:

- accepted M4 runtime authority package `10565723112` / source `6fe075f7d9397a561fe50b79517b4f714fb9eeef` / selector427 **427/427**;
- selector427 bytes: 427 LF rows, SHA-256 `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`, owners **30 / 281 / 75 / 41**;
- every production source byte unless this plan is reopened by Review;
- every committed benchmark fixture byte, especially `benchmarks/fixtures/milestone-g/torus.obj` and `torus.rawfield`;
- CP4 work/boundedness evidence and reviewed same-region multiplicity-2 evidence;
- row408 historical truth and accepted hard-rail production path;
- recovery disabled / fail-closed production semantics; no direct/draft/source-grid substitute.

## 3. Authorized test-only corrections

### CB4-A — rawfield fixture reader

In `tests/SurfaceComplexSimplificationPhase17Tests.cpp`, repair only the test-local rawfield reader so it follows established repository format: header `(degree, faceCount)`, require degree `4`, require `faceCount == expectedFaces`, allocate `faceCount x (3*degree)`, and read that payload. Do not rewrite `torus.rawfield` and do not broaden production parsing.

The focused identity must still reach a **produced closed candidate-bearing complex**, independently derive candidate eligibility from retained authority, and preserve its discriminating tamper. If the corrected reader only moves the test to a different upstream stop, that runtime result belongs to R3 Review; do not synthesize a candidate.

### CB4-B — produced torus periodic-owner witnesses

In `tests/SurfaceCellTransitionQuotientTests.cpp`, align the focused torus production fixture with the accepted row408 hard-rail precondition rather than the generic `torus_fixture()` premise disproved by R2. Use fail-closed SurfaceCells, `allowSourceGridRecovery=false`, retained intermediates, the accepted two torus fundamental cycles / resulting 18 explicit hard-feature edges, and the same 179/180-degree suppression of unrelated automatic hard edges used by row408 authority.

Before either focused semantic assertion receives credit, independently prove the resulting phase front is `Produced`, contains **at least two distinct `PeriodicRelationId`s**, and contains at least two periodic edges resolving through typed relation ownership. Then:

- reorder witness: derive a typed-ID semantic owner map before relation-container reversal and require every periodic edge to resolve the same tuple afterward; discriminating ID-swap tamper must reject;
- missing-owner witness: independently prove one periodic edge's relation membership by ID, clear exactly that owner in copied pre-publication values, reconstruct through the checked product factory, and require typed `MissingPeriodicRelationOwner`.

Do not call `direct_periodic_owner_product()` for produced credit. Do not weaken the multiplicity requirement merely to make the row green.

### CB4-C — genuinely non-flat zero-transport prerequisite

In `tests/FieldTransportAtlasTests.cpp`, replace only the row6 negative subject/precondition. The negative mesh must be intrinsically non-flat, and the test must independently compute/prove a nonzero interior angle defect/curvature condition before constructing the zero-transport field. Preserve the flat positive control. Expect typed `CycleTransportMismatch` only after the negative precondition is proved.

Do not repurpose/rename the currently planar `make_skew_four_triangle_fan()` as proof of non-flatness. Prefer a bounded test-local construction so unrelated tests using that helper remain untouched.

### CB4-D — reporting-control hygiene, only if the R3 harness is frozen here

If CB4 authors/freezes the R3 artifact-only harness, correct the evidence-neutral stop-reason semantics so the field either preserves the first semantic non-green or is explicitly named/encoded as the last semantic non-green. Ledger/raw-log behavior, all-six-focus execution, selector stop rules and immutable postflight must not change. This is control metadata only and grants no semantic credit.

## 4. Build boundary

Use `.github/workflows/agent-compile-reusable.yml` with mandatory GMP/GMPXX. Build all standard targets required to close selector427 package ownership, including all four selector-owner test executables. Record exact compiled source, source archive, clean receipts, GMP evidence, command boundary and recursive manifest. `runtimeExecution=false` is mandatory.

No generated Directional binary may execute: no tests, benchmark, `ctest`, generated discovery/list/help/version, CLI or custom input. PRE_TEST compile-only discovery is the maximum allowed runtime-adjacent configure behavior.

## 5. Static/non-vacuity checks before compile

CB4 must prove from source diff/static inspection:

1. semantic diff is limited to the authorized test files plus bounded R3 control payload if needed;
2. no product, fixture, selector, benchmark, CMake semantic or durable reusable compile-workflow change occurred;
3. rawfield reader matches degree/face-count authority and does not mutate fixture bytes;
4. periodic-owner fixture uses the same hard-rail precondition constants/cycles as accepted row408 and contains explicit runtime assertions for `Produced`, relation-ID multiplicity and periodic-edge multiplicity;
5. zero-transport negative independently checks actual nonzero intrinsic angle defect before expecting rejection;
6. selector427 re-hashes unchanged.

## 6. Falsifiers / STOP rules

Stop and return to Review rather than widen scope if any of the following is required:

- any product semantic change;
- any committed fixture rewrite;
- any selector427 edit or accepted-prefix weakening;
- source-grid recovery, fallback, direct/draft/synthetic substitution for a produced-credit subject;
- changing row408 production semantics or historical provenance;
- inferring periodic multiplicity from the test's desired result rather than the produced phase-front authority;
- changing the zero-transport product contract instead of proving a valid negative precondition;
- adding unrelated test/refactor/CMake/benchmark work.

A static inability to align the focused torus fixture with the accepted row408 hard-rail authority is itself a STOP. If the aligned fixture is structurally valid but R3 runtime produces fewer than the required periodic relations/edges, preserve that RED and route to Review/DEFN; do not weaken the identity in CB4.

## 7. Exit

On compile/package GREEN, exact successor is **`M4-CP4-TB1-R3-EXEC`**: fresh immutable artifact-only execution of all six focused identities plus exact selector427 according to the frozen stop/postflight rules. Any trustworthy semantic result then routes to mandatory runtime-free **`M4-CP4-TB1-R3-REV`**. CB4 itself promotes nothing and discharges no runtime debt.
