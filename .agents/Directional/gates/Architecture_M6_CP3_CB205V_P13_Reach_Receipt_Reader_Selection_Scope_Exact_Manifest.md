# CB-205V exact manifest: scope the reach receipt to the reader's selection (2026-11-25 UTC)

**Review artifact only.** TB-REV-185T (adversarial continuation) authorizes no apply, build or runtime here.

- **Owner:** `M6-CP3-CB-205V-P13-REACH-RECEIPT-READER-SELECTION-SCOPE`, Code + Build only, test-only.
- **Authority:** [TB-REV-185T adversarial](../Architecture_M6_CP3_TB_REV_185T_Adversarial_Review_20261125.md) W1/W2. It supersedes the prose CB-205U on the critical path.
- **Semantic preimage:** current branch head. CB-205 source `21087c8285a5dd367cc16f610386accc061bd194` has the same test bytes.
- **Exact diff:** [the diff file](../Architecture_M6_CP3_CB205V_P13_Reach_Receipt_Reader_Selection_Scope_Exact.diff).
  - 2,428 B, SHA-256 `c9d66976d9d8f765f572de4f66fc00ee8a815abac8f3a04b3f51b39b67881178`, one path, +8/−3.
- **Checks done in Review:** `git apply --check` passes. Syntax-only (adversarial review W5): 0 errors and 45 warnings, the same as HEAD. Not compile evidence.

| Path | Before SHA-256 | After SHA-256 |
|---|---|---|
| `tests/FieldAlignedCurveNetworkTests.cpp` | `03abb0a6abcd8dbafb40bfe4dfbc56c0a2744a5eca9353749c1bf08b9cf3d72d` | `39b22f998b29b9662640e1212440db3d3f997bd1e1eba8c5492fa25b350efc48` |

## Required behavior (row 1006 only)

1. **The `polyline-defaults` loop stops where its reader stops.**
   - `produced_network()` (`FieldAlignedNetworkPolylinesTests.cpp:52–99`) returns at the first eligible production fixture.
   - Row 1006 now breaks as soon as it has both a first eligible production fixture and a first eligible staged fixture.
   - Fixtures after that point are never read by 843/844, so they are not measured.
2. **Receipt count.** The fixed `13U` becomes `9 + polylineFixtures`, where `polylineFixtures` is the number of polyline fixtures visited. The 9 are 3 observe + 2 pipeline-products + 4 census.
3. **Receipt formatting.** Recipes that publish no network now print ` published=not-applicable`. This fixes the missing separator TB185T showed: `productionStagedDigestEqual=1not-applicable`.
4. **Unchanged:** every other assertion, including:
   - the explicit-false sphere control;
   - staged `slideStops=4`;
   - the published-digest bindings;
   - the required baseline builds;
   - `EXPECT_FALSE(firstProduction.empty())`.

   No product, fixture, selector or other test change.

## Build, then a separate runtime falsifier

1. **CB-205V, build only.**
   - Verify the preimage, diff and postimage hashes, and that only this one path changed.
   - Compile the eight GMP/GMPXX targets with `runtimeExecution=false`.
   - STOP on any mismatch.
2. **`M6-CP3-TB-EXEC-185V`, full gate, not authorized here.**
   - Same 1006-case manifest `a9b80832…0587`, deferred v5, 1087 members, and the no-timeout full-gate harness. Compare against accepted TB184.
   - **Required:**
     - All 1006 PASS, organically.
     - The first 1005 rows are N1–N3-equal to TB184.
     - Row 1006 records its elapsed time and prints exactly **10** recipe receipts and one `SlideEntryActivationReachPolyline productionFirst=sphere_prescribed stagedDiagnosticFirst=sphere_prescribed` line.
     - The 10 receipts equal TB185T raw receipt lines 1–10 (artifact `15035995368`, raw SHA-256 `661c9417…a550`) byte for byte. The only exception is census lines 6–9, where `=Nnot-applicable` becomes `=N published=not-applicable`.
   - **This is a prediction derived from TB185T's measured eligibility:** sphere `polylineEligible=1` in both the production and staged columns. Any other count, line or failure is a STOP.
