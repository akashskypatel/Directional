# TB100 — Boundary field corners, full-gate execution (2026-11-11 UTC)

**Canonical turn:** `M6-CP3-TB100-P13-A3-BOUNDARY-FIELD-CORNERS-FULL-GATE-EXEC` (64B.15). **Measured MISMATCH:** 937/938. This record is an artifact-only Test + Benchmark assessment; it is not a Review decision or authorization to change the frozen CB119/CB120 code.

## Exact authority and execution boundary

- CB119 immutable semantic source `cd1d451b4190bdd6b88e07fafa7e6fe69ff5b3d2`, GMP/GMPXX package artifact `13815545121` from [compile run 42926339655](https://github.com/akashskypatel/Directional/actions/runs/42926339655), archive SHA-256 `6af2c551287b8861f64955f8604d968091ebcfbb9db9ceff08126c5edbe1e70a`. Package `SHA256SUMS` 28/28 independently verified, root manifest SHA-256 `57f3e7d73fa05f53ff34a034d74037b1d95f8a8f60a90faef30186eb3d124df9`, source archive SHA-256 `ee8fc70c40f662c684afaa109459baf4430b52c68eb57b12769c9dca619bb792`.
- Gate manifest 938 cases SHA-256 `2df4bd96ee8a52323ffa4f07292e37a3b6e4aedd6424fb9dc68e805da2cbc24c`; deferred 81 ledger SHA-256 `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce`, membership 1019. Harness SHA-256 `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94`.
- First [run 42932559558](https://github.com/akashskypatel/Directional/actions/runs/42932559558), request commit `8cd1fce4be8a830d8fbc64e324930d2703712136`, used an incorrect `EXPECTED_SOURCE_SHA` and stopped with `package source mismatch`: **0 tests executed**. This is an orchestration error, not product evidence.
- Corrected [gate run 42932637408](https://github.com/akashskypatel/Directional/actions/runs/42932637408), request commit `89d77f7a7709092c79f18a385b0b956f511268fa`, result artifact `13817910944`, ZIP SHA-256 `11178b67745aa3130391eba69c1ef6c680343ace3d834dc2422e621a5cf58604`. Its **1,884/1,884** embedded SHA256SUMS entries were independently checked. Gate executed **938/938** processes (937 PASS / 1 RED), no missing, duplicate, skipped or abnormal processes, postflight true. Harness exit 90 reflects the required-control failure, not package mutation.
- Corrected [census run 42932960676](https://github.com/akashskypatel/Directional/actions/runs/42932960676), request commit `8dbf0eb49bc039aeaf0539966f13df4c74096b4d`, result artifact `13817628224`, ZIP SHA-256 `d1c6ef75300439e808d8a245f547a02f1bece4947e37b987f584c0864b4b9927`. Its **9/9** embedded checksums passed. Census: Cylinder PASS, BunnyRandom and Vase registered RED (unchanged typed first failures). Exit 0, full postflight.
- Both execution boundaries pin CB119 source and artifact and say `configure=false`, `compile=false`, `relink=false`, `benchmark=false`. No package repair, tests/source/selector changes, or local project binary runs occurred.

## Raw independent comparisons

- All inherited **936/936 TB99 ledger rows** match on semantic/control columns (`row, kind, identity, test, binary, verdict, exit, run, passed, skipped, typed_reason`), excluding process-log checksum and diagnostic text. All inherited rows PASS.
- Across the four gate and three census processes, the **seven raw `platform-digest`** and **seven raw `a3-coverage`** lines each match TB97 byte-for-byte, not merely by checksum.
- The **four raw `d4-rim`** lines match TB98 byte-for-byte.
- New row 937 `BoundaryFieldCornersFollowTheFieldNotTheGeometry` PASS. Row 938 `BoundaryFieldCornersMatchTheCurvedProducersSideStarts` fails the fixed expected-set equality for **both** forward and reversed face-row order; the pure-quad producer path itself is not invoked as a new direct production claim in TB100.

## Decisive row 938 failure

`SurfaceCellsPhase10Tests.cpp:8369` with trace `hard rail`:

```text
expected corners = {0, 2, 6, 8, 9, 11, 15, 17}
actual corners   = {0, 1, 2, 6, 7, 8, 9, 10, 11, 15, 16, 17}
extra            = {1, 7, 10, 16}
```

Same failure under reversed face-row order. The following are raw receipts from row 938, not acceptance thresholds:

```text
FIELD_CORNER_RECEIPT case=rail corners=12 passThroughRimNodes=12 sideStarts=12 rimSideStarts=8
FIELD_CORNER_RECEIPT case=plain corners=8 passThroughRimNodes=16 sideStarts=8 rimSideStarts=8
```

The scoped rim-corner/side-start equality later in the test does **not** fail. The stronger complete-set equality fails only on the hard-rail fixture. From this evidence alone, the correct disposition of those four non-corner rail vertices is unresolved: the field-corner product may be overinclusive or the test's full-set expectation may be broader than the frozen rim-node contract. **Do not weaken or rewrite the expectation during TB100.** An independent Review must compare the RA-224 contract against producer side-start semantics, distinguish rail/cut starts from field corners, and issue an exact correction plan and falsifiers.

## Outcome, regression classification and successor

**TB100 = MISMATCH.** This is an unpromoted CB119 gate/control candidate, **not** a new stable regression: no accepted CP2 green test was lost. Retain accepted CP2 **491/491**, stable **66 events / 17 categories / 49 recurrences**, debt **1**, deferred **81**, CP3/selector497 unpromoted. Existing BunnyRandom P13-e and Vase production REDs remain open as previously classified; O36 remains unswitched. The new candidate is the hard-rail/full-field-corner equivalence discrepancy; its product-versus-test root cause is not yet adjudicated.

Next authorized distinct turn only: **`M6-CP3-TB100-P13-A3-BOUNDARY-FIELD-CORNERS-FULL-GATE-REV`**. Do not start CB120 or TB101 without that review and a subsequent authorized correction turn. All earlier repairs, source changes and producer wiring remain outside this TB scope.