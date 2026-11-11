# TB100B — Corrected boundary field corners gate, immutable test evidence (2026-11-11 UTC)

**Canonical turn:** `M6-CP3-TB100B-P13-A3-BOUNDARY-FIELD-CORNERS-CORRECTED-GATE-EXEC`. **Result: COMPLETE / MATCH for the corrected gate**, subject to separate independent Review. The product remains unpromoted.

## Situation

The corrected row 938 PASSes. All 938/938 full-gate identities PASS, with zero missing, skipped, duplicate, abnormal, unexpected-PASS, or bad-control cases. The three-case observation census remains Cylinder PASS, BunnyRandom RED, Vase RED; it is not an additional 938-case acceptance gate.

## Background and exact evidence

- Immutable CB119B GMP/GMPXX source `d47b7c24b11cfb568d4ffce971590b8e5f966dc4`, compile run [42953097338](https://github.com/akashskypatel/Directional/actions/runs/42953097338), package ID `13826405755`, SHA-256 `a94196c1276a976618db161478d2e43cfc49f2d1a6977b54a74725f8dac2d667`.
- [Corrected gate run 42958701539](https://github.com/akashskypatel/Directional/actions/runs/42958701539); result artifact ID `13828258166`, ZIP SHA-256 `29f63afec634b08a1e708457ef6b2f97e887b50bc595ba16551cb2510e4a8247`, 1,884/1,884 embedded checksum entries PASS. Execution-boundary `planned=938, executed=938, passed=938, red=0, membership=1019, postflight=true, exit=0`.
- [Corrected census run 42958806101](https://github.com/akashskypatel/Directional/actions/runs/42958806101); result artifact ID `13828198354`, ZIP SHA-256 `8b1d00f279eed7ea9af6fd89dcf6ee14cf1a2b608dfe2790bbd004d20cfce390`, 9/9 embedded checksums PASS. Execution-boundary `planned=3, executed=3, passed=1, red=2, control_bad=0, postflight=true, exit=0`.
- Both boundaries name the **same** compiled source/package. They record `configure=false`, `compile=false`, `relink=false`, `benchmark=false`. No project binaries were executed locally, and no code, tests, selectors, fixtures or workflows were changed in this TB turn.
- A new source snapshot for this ChatGPT turn was verified separately: `f34d003fc87434efa46b5ac0bc18761d7367ad40`, [run 42983377341](https://github.com/akashskypatel/Directional/actions/runs/42983377341), artifact `13838029523`, ZIP SHA-256 `8f14a74fd1247f770aaed87002b35401d06826ebdd05cdc157b07ab3516fc3b1`; 5,450/5,450 source hashes verified. This snapshot is documentation/inspection authority, **not** semantic TB package authority.

## Assessment — independent comparisons

- Compared with the original TB100 [gate run 42932637408](https://github.com/akashskypatel/Directional/actions/runs/42932637408), artifact `13817910944` (ZIP SHA-256 `11178b67745aa3130391eba69c1ef6c680343ace3d834dc2422e621a5cf58604`) and [census run 42932960676](https://github.com/akashskypatel/Directional/actions/runs/42932960676), artifact `13817628224` (ZIP SHA-256 `d1c6ef75300439e808d8a245f547a02f1bece4947e37b987f584c0864b4b9927`). Verified old embedded checksums: gate 1,884/1,884, census 9/9.
- All **936 inherited gate** ledger rows match exactly on `row,kind,identity,test,binary,verdict,exit,run,passed,skipped,typed_reason`; row 937 remains PASS. The **only** semantic/control ledger change is row 938: RED/exit 1 to PASS/exit 0. The census's three semantic/control rows are identical.
- All **seven raw `platform-digest`** lines and all **seven raw `a3-coverage`** lines match TB100 byte-for-byte (four in the gate and three in the census). TB100 already recorded their exact equivalence to TB97. All four raw `d4-rim` lines match TB100 byte-for-byte (and TB100 recorded equality to TB98). Both raw `FIELD_CORNER_RECEIPT` lines match TB100 byte-for-byte.
- Row 938 runs both face-row orders with the independent CB119B oracle; receipt `FIELD_CORNER_RECEIPT case=rail corners=12 passThroughRimNodes=12 sideStarts=12 rimSideStarts=8` and `FIELD_CORNER_RECEIPT case=plain corners=8 passThroughRimNodes=16 sideStarts=8 rimSideStarts=8` are unchanged. The fixture's accepted hard-rail endpoint set is the original eight corners plus source/atlas-verified `{1,7,10,16}`. This PASS does not certify field corners away from source-boundary rims or wire the product into production.
- Existing census REDs: BunnyRandom `SurfaceCellDesignAcceptanceTests.cpp:273` and Vase the same source site, neither accepted-green regressions nor evidence of a new CB119B failure. The prior TB100 disposition and their existing owners remain unchanged.

## Recommendation — disposition and next gate

**TB100B corrected gate MATCH, not CP3 production acceptance.** Record the former row-938 test-oracle mismatch as corrected; do not erase its historical RED evidence or reclassify the two existing census REDs. Keep CP2 **491/491**, stable **66 events / 17 categories / 49 recurrences**, debt **1**, deferred **81**, CP3/selector497 unpromoted. O34/O35/O36/O37/O39 and D6 remain open. The conservative C1 source-boundary stop product is still unwired; exact branch decisions under O39 must precede O36 activation.

**Only authorized successor:** `M6-CP3-TB100B-P13-A3-BOUNDARY-FIELD-CORNERS-CORRECTED-GATE-REV` (independent, runtime-free Review of the oracle falsifiers, full gate, and scoped C1 authority). Do not start CB120A, TB101A, CB120B, CB120C or later turns inside TB100B.
