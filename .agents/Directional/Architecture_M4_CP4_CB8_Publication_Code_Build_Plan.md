# M4-CP4-CB8 Publication Code + Build Plan

**Turn:** `M4-CP4-CB8`
**Type:** publication-only Code + Build
**Predecessor:** `M4-CP4-DEFN-R2`
**Runtime boundary:** compile/package only; generated Directional runtime prohibited

## 1. Frozen inputs

- accepted prefix: `Architecture_M4_CP_SCALE_CB24_Required_Green_Selector_427.txt`, 427 LF rows / 34,783 bytes / SHA-256 `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`;
- reviewed publication rows, in exact order:
  1. `M4CP4.ProductionBaselineWorkReceiptIsBoundedAndIndependentlyValidated`;
  2. `M4CP4.ProducedSameRegionMultiplicityTwoSurvivesA2bToBaselineBinder`;
  3. `M4CP4.ZeroTransportFieldPreconditionDistinguishesFlatSuccessFromNonFlatRejection`;
- expected selector430: **430 rows / 35,001 bytes / SHA-256 `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6` / owners 31 / 283 / 75 / 41**;
- accepted runtime authority remains package `10565723112` until final selector430 TB + Review.

## 2. Authorized mutations

1. Add exactly one selector430 file equal to exact selector427 bytes plus the three frozen LF rows. Existing selector files are immutable.
2. Update `Required_Green_Selector_Manifest.md` and only the bounded package/control metadata needed to make selector430 the next cumulative gate.
3. Do **not** change product source, test source, fixtures, CMake semantics, benchmark semantics, existing selector rows, or reusable workflow permissions.

## 3. Compile/package gate

Use `.github/workflows/agent-compile-reusable.yml` with mandatory GMP/GMPXX linkage and the durable cache namespace. Compile/package all standard selector-owner test binaries required for a self-contained cumulative TB package; do not rely on generated test discovery. Evidence must record exact source SHA/archive, all owner executables, executable modes, manifest, clean source receipts, GMP/GMPXX linkage and `runtimeExecution=false`.

No generated Directional binary may be executed in CB8: no tests, benchmarks, `ctest`, discovery, list/help/version invocation, CLI/GUI or custom runtime input.

## 4. Falsifiers / stop rules

Stop the turn rather than broadening it if:

- the selector427 prefix differs by one byte or does not re-hash to the frozen SHA;
- selector430 is not exactly 430 LF rows / 35,001 bytes / expected SHA / owner census;
- any row other than the three reviewed identities is proposed for append;
- packaging requires a product/test/fixture/CMake semantic change;
- any M5/M6 re-homed debt row is pulled into M4 publication;
- any reusable-workflow permission change is required;
- compile/package evidence executes generated Directional runtime.

A compile failure may be corrected within CB8 only when the correction is publication/package/control-only and does not cross these boundaries. Any semantic correction stops to Review/DEFN.

## 5. Successful successor

On exact publication + compile/package GREEN, the only successor is **`M4-CP4-TB3-EXEC`**: immutable artifact-only execution of selector430 as 430 fresh exact-filter processes with exact-one selection, zero skips, full immutable pre/postflight and no configure/compile/relink/discovery/repair/mutation. Semantic non-green routes to mandatory Review; mechanically green TB3 routes to mandatory `M4-CP4-TB3-REV`, which alone may close CP4/M4.
