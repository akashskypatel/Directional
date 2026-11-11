# TB101B — focused factory field-corner execution (2026-11-11 UTC)

## Situation
`M6-CP3-TB101B-P13-A3-FIELD-CORNER-FACTORY-EXEC` completed with **MATCH**. Its one authorized `SurfaceCellAuthorityContractCutover.ChainedInputStopsAtBoundaryFieldCorners` test passed.

## Background
The execution used the immutable CB120B compiled source `5e603a239d9d7519668b9c42cb3c2b6e8f16d2f8`, compile run [43004287273](https://github.com/akashskypatel/Directional/actions/runs/43004287273), artifact `13848350912`, outer SHA-256 `ad7ced00acc60c3da2ffe5b051d0cc929a8f509a7591ca6274d022db66d80e7c`. All **28/28** package SHA256SUMS entries passed. An independently verified source snapshot of `a85fc49a3cb141363b16f34e673eda50f072391a` had **5,456/5,456** valid file hashes. Only one new observer manifest was committed; the executable package was not rebuilt.

## Assessment
The frozen one-case manifest is `.agents/Directional/gates/Architecture_M6_TB101B_Field_Corner_Factory_Focused_Manifest.tsv`, SHA-256 `6895038de1fb1f1575b7b293438541f46a732879eab2433dada5a101b0780e1a`. Its one OBSERVE row uses the existing binary and test; manifest self-check passed.

[GitHub Actions run 43010509767](https://github.com/akashskypatel/Directional/actions/runs/43010509767), request event SHA `66747dc64dcff9ba6ec16c10b668f21ef3eee06a`, used exact executor SHA `48d25902b8d66a631a33f034a7391d204da3709f` and source/package SHA above. Result artifact `13849544352`, outer ZIP SHA-256 `a206d66ec6256c5e9edea2a42715f617c8096dd016a5260dcf41af8da3e0baca`; **5/5** result SHA256SUMS verified. Its execution boundary records `planned=1`, `executed=1`, `passed=1`, `red=0`, `abnormal=0`, `skipped=0`, `missing=0`, `duplicate=0`, `postflight=true`, exit zero and `compile=false`, `relink=false`, `configure=false`, `benchmark=false`. The raw GoogleTest log independently reports 1/1 PASSED and exercises both normal and reversed source-face orders. The test checks that the factory keeps existing corner stops and accepts the declared boundary field-corner stops.

No new regression was observed. This focused result does not prove full-gate or production acceptance. Accepted CP2 **491/491**; stable **66 events / 17 categories / 49 recurrences**, debt **1**, deferred **81** unchanged. CP3 and selector497 remain unpromoted. O39 exact boundary-branch authority is required before O36; PR #8 remains draft and unmerged.

## Recommendation
Proceed only in a **separate** Code + Build turn `M6-CP3-CB120C-P13-A3-FIELD-CORNER-CENSUS`. Its scope is the frozen focused census receipt/test change and compile-only validation. Do not execute any CB120C work during TB101B. The later TB101C full gate and independent Review remain conditional.
