# CB168H — reciprocal mutual carrier-end oracle (Code + Build, 2026-11-20 UTC)

## Situation

**Compile PASS.** Exact test-only frozen diff `df73a362ef9749c6806eb718540fdaf2c092007bfa8082bb62fb9e8ad533e254` applied to `tests/FieldAlignedCurveNetworkTests.cpp` at semantic source `63563a40eda9c6712970f7d9063f343a28e0fdd0` (+87/-1). [Compile run 44645373199](https://github.com/akashskypatel/Directional/actions/runs/44645373199), job `135986704658`, immutable package `14587824913`, ZIP SHA-256 `67494ea0138b1978e4ebb4434a4b6bcace048e2e27cb409df167b2c448a45c28`, diagnostic log artifact `14589210228`. All eight RA-245 targets compiled using GMP/GMPXX, exact package manifest verified, and `runtimeExecution=false`.

## Background

[RA-268](Architecture_M6_CP3_TB146_P13_Transverse_Entry_Mutual_Stop_Full_Gate_Independent_Review_20261119.md#ra-268--adversarial-re-review-of-this-review-2026-11-19-utc) froze the exact oracle. TB146 row 393 was RED because the old unconditional strict struck-index assertion failed on four legal reciprocal end-index contacts (7 versus 7). Frozen preimage SHA-256 `5e5709d5eea5045fdf94c9a89fc1ce882c963210bfb0c02ac60ffab46ab4eb9e`; verified source comparison shows `src`, `include` and `tests` unchanged since CB168G (`ebbe893bd5415e05ea828d5587a265d08326d1fa`). The exact patch applied cleanly. Remote applied blob `205c9394e57e029576cf5955e8407cc51276a6a5` and changed-path inventory verify one test file only.

## Assessment

The oracle now independently checks four reciprocal terminal identities, carrier edge/parameter, endpoint correspondence, source-face barycentric proof, terminal roles, and two graph nodes. It retains the strict index bound for other contacts. No product implementation, selector, fixture, manifest or production behavior was changed. Compile success is not runtime or row-393 PASS evidence. TB146 remains the latest RED runtime evidence; stable 66/17/49, one witness debt and 81 deferred remain unchanged. No CP3, selector497 or D0 promotion.

## Recommendation

The single next turn is `M6-CP3-CB168I-P13-SLIDE-COINCIDENCE-RECEIPT`. Apply only its frozen `a1b0fa4129341888a5cdc981a22c31d6c6306fce81d2909678fd85ec827626a4` diff, compile eight RA-245 targets, and execute no runtime. TB147 follows in a separate immutable test/benchmark turn; do not execute it in CB168H or CB168I.
