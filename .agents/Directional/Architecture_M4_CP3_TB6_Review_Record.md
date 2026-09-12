# M4-CP3-TB6 Review Record — CB8 torus recovery is real; accepted ordinal138 exposes bounded-disk applicability/disposition scope widening

**Turn:** `M4-CP3-TB6-REV`
**Status:** COMPLETE / CANDIDATE REJECTED / PRODUCT-SEMANTIC COMPATIBILITY REGRESSION / NON-STABLE
**Canonical turn:** Review + Plan / runtime-free
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`
**Reviewed candidate semantic source:** `6934d9edfb56b44f956fbc64a89a501aaed042af`
**Reviewed candidate package:** `10303165017` / SHA-256 `d601e5efc4d6a3cafc34d4a5ead0a5a44040e3026d31b3f75afad59c71b68112`
**Accepted authority retained:** corrected R4 artifact `10289601000` / selector403 `c3f509afc823cd73761bdebea0d072d497acf5587a013cb52b795f273af70cb7` / **403/403**
**Authoritative TB6 execution:** `34711826087 / 103601868455`
**TB6 result/log:** `10303393457 / 10303657623`, SHA-256 `db5770d212befb593d9dd3003c7a399432f4fed4d43aa4b306c117274c21d1d1` / `a3297a070dfd340a177287a59efc9f717210425659cf06c539b6321bccc33239`
**Exact successor:** `M4-CP3-CB9`

## 1. Review decision

**Reject candidate package `10303165017` / selector408 for promotion, while accepting the focused CB8 recovery as genuine.** The two findings must be kept separate:

1. `M4-CP3-TB5-REV-CAND-01` is **CLOSED / RECOVERY PROVED / NON-STABLE**. Row408 now passes twice under the exact 18-edge effective HardFeature torus witness, and rows404-407 pass twice. The CB8 occurrence-domain correction therefore repairs the cut-open torus defect it was authorized to repair.
2. TB6 then loses an identity that belongs to the already accepted selector403. Ordinal138 is not a stale negative whose premise became invalid. It is an accepted fail-closed compatibility contract for a valid, too-small bounded region. CB8 broadened the accepted-cut-domain path from “cut-open topology that needs occurrence identity” to **every planned hard-feature region**, and the new early `<4` accepted-segment guard changes a previously `NotApplicable` bounded region into `Rejected/InvalidFrontBoundaryAuthority`.

The new finding is recorded as:

> **`M4-CP3-TB6-REV-CAND-01` — OPEN / PRODUCT-SEMANTIC / A4 ACCEPTED-CUT-DOMAIN APPLICABILITY-DISPOSITION SCOPE WIDENING / NON-STABLE.**

This is non-stable because no accepted package lost green authority: the failing bytes are on the unpromoted CB8 package. Corrected R4 artifact `10289601000` / selector403 remains accepted **403/403**. Stable accounting remains **47 events / 14 categories / 33 recurrences**, produced-witness debt **5**. CP3 and `G4-B002` remain OPEN.

## 2. Primary evidence independently re-opened and re-derived

The review re-opened the immutable TB6 result/log bundles, not the EXEC narrative. Independent checks establish:

- result ZIP SHA-256 `db5770d212befb593d9dd3003c7a399432f4fed4d43aa4b306c117274c21d1d1` and log ZIP SHA-256 `a3297a070dfd340a177287a59efc9f717210425659cf06c539b6321bccc33239`;
- process ledger contains exactly **148** semantic rows: **147 PASS / 1 RED**;
- phase counts are 2 focused row408, 8 rows404-407 controls, and 138 selector403 processes;
- row408 selected exactly one expected identity in each focused process and PASSed **2/2**;
- rows404-407 selected exactly one expected identity each and PASSed **8/8**;
- selector403 ordinals1-137 PASS, ordinal138 is the first RED, selector408 cumulative execution is never entered;
- ordinal138 selects exactly one identity, exits normally with GTest failure, and is neither a selection mismatch nor crash/timeout;
- immutable postflight says `package_census_equal=true`, `source_census_equal=true`, `execution_view_census_equal=true`;
- package authority is exactly artifact `10303165017`, provider/download SHA-256 `d601e5ef...68112`.

Selector bytes were re-hashed from the exact review source snapshot:

```text
selector403: 403 LF rows
sha256 = c3f509afc823cd73761bdebea0d072d497acf5587a013cb52b795f273af70cb7

selector408: 408 LF rows
sha256 = c689c0cd8a51f9a8bd8c9ed3a2e8b603728d5a0359ee2732f776a422744b0484

selector408 first403: byte-identical to selector403
sha256 = c3f509afc823cd73761bdebea0d072d497acf5587a013cb52b795f273af70cb7
```

The owner partition remains the frozen **30 authority-kernel / 262 producer / 75 completion / 41 validation** for selector408.

## 3. CB8 recovery is non-vacuous and closes the TB5 candidate

Both row408 logs independently emit the same exact torus support receipt:

```text
support_F=144
support_E_total=216
support_V_total=72
interior_barrier_edges_both_sides=18
support_E_int=198
support_V_int=55
support_chi_reduced=1
support_chi_whole_source_faces=0
whole_minus_reduced_euler=-1
```

Thus the focused PASS is not a vacuous branch. The runtime still receives the exact 18-edge cut, distinguishes reduced/cut-open disc support from the raw torus, and reaches the end-to-end row408 `Produced` contract twice. Rows404-407 passing twice additionally protects the accepted A2b/A3 receipt, fixed-plan shared intervals, tamper rejection, and A4-local family/sign behavior.

`M4-CP3-TB5-REV-CAND-01` is therefore **DISCHARGED / CLOSED / RECOVERY PROVED / NON-STABLE**. Its correction is real even though the package cannot be promoted because a different accepted-prefix contract now fails.

## 4. Ordinal138 is a valid accepted contract, not stale test authority

The failing identity is:

`SurfaceCellAuthorityContractCutover.HardFeatureRegionDeclinedByAllPhaseFrontProducersFailsClosedTyped`.

Its fixture is deliberately small and deterministic: `make_square_mesh()` is two triangles `(0,1,2)` and `(0,2,3)`, with user hard edge `{0,2}`. Runtime diagnostics show the hard edge partitions support into two one-face regions, each with:

```text
support_F=1
support_E_total=3
support_V_total=3
source_submesh_boundary_edges=3
interior_barrier_edges_one_side=1
interior_barrier_edges_both_sides=0
support_chi_reduced=1
support_chi_whole_source_faces=1
```

The accepted test requires a precise producer-disposition contract, not a guessed incidental string:

- aggregate result is rejected at `tracing/phase-front`;
- reason is `UnsupportedSourceSheetTopology`;
- uniform, periodic-annulus and bounded-disk producer-declined flags are all true;
- no product/validation result is published.

Production code documents the same contract: `UnsupportedSourceSheetTopology` is emitted only after the ordered uniform → periodic-annulus → curved bounded-disk chain all returned `NotApplicable` for the region. Because mandatory hard-feature authority is present, the aggregate then fails closed rather than entering legacy fallback. The test therefore protects **fail-closed fallback ownership while retaining producer applicability semantics**. It does not require an invalid authority to be accepted.

TB6 observes instead:

```text
reason = InvalidFrontBoundaryAuthority
uniform_declined = false
periodic_declined = false
bounded_disk_declined = false
```

That is a product-semantic disposition change inside accepted selector403, not stale test text.

## 5. Exact source cause: an early validity rejection shadows the established applicability gate

Current CB8 source selects planned cut-domain handling with:

```cpp
useAcceptedCutDomain = useAcceptedConformity && regionHasHardFeature;
```

This is broader than “a region whose physical/raw topology is insufficient because an accepted cut must be materialized.” It includes the square fixture's already-valid one-face physical discs simply because they are planned and contain hard authority.

After validating A2b incidences and materializing `acceptedSegments`, CB8 added:

```cpp
if (acceptedSegments.size() < 4U) {
  result.disposition = SurfaceCellProducerDisposition::Rejected;
  result.failure.reason = InvalidFrontBoundaryAuthority;
  return result;
}
```

The same producer later retains the pre-existing applicability rule:

```cpp
if (boundaryEdgeKeys.size() < 4U || boundaryAdjacency.size() < 4U) {
  return result; // NotApplicable
}
```

For ordinal138 each valid region has exactly three boundary segments. CB8 therefore intercepts the region at the new earlier guard and reclassifies **insufficient chart cardinality** as **corrupt boundary authority**. Before CB8, the same `<4` condition reached the established `NotApplicable` path; aggregate hard-feature dispatch then produced the accepted typed `UnsupportedSourceSheetTopology` failure.

This is the decisive distinction:

- missing/ambiguous incidence binding, inconsistent topology digest, contradictory schedule, non-disc accepted authority, or collapsed opposite occurrences are **authority failures** and remain `Rejected/InvalidFrontBoundaryAuthority`;
- a valid accepted boundary whose cardinality is below the curved bounded-disk producer's minimum chart size is an **applicability outcome** and remains `NotApplicable`.

No selector/test weakening is authorized.

## 6. CB8 plan boundary independently checked

The reviewed CB8 plan authorized the minimum A4 occurrence-domain correction because row408's uncut torus loses the accepted cut-open disc domain. It explicitly required:

- A2b remain topology writer and A3 remain subdivision writer;
- occurrence identity, not raw vertex identity;
- physical bounded-disk behavior remain intact;
- fail-closed semantics remain intact;
- selector403/408 bytes remain frozen;
- a second semantic dependency outside the guarded occurrence seam return to Review.

The ordinal138 RED is therefore not an allowed consequence that invalidates its test. It is evidence that the implementation's **activation/disposition boundary widened beyond the reviewed seam**. The architectural occurrence-domain mechanism itself remains justified by row408 2/2.

## 7. New candidate and exact corrective boundary

### `M4-CP3-TB6-REV-CAND-01`

**Classification:** OPEN / PRODUCT-SEMANTIC / A4 ACCEPTED-CUT-DOMAIN APPLICABILITY-DISPOSITION SCOPE WIDENING / NON-STABLE.

**Root cause:** a valid planned hard-feature region with fewer than four accepted boundary segments enters the CB8 accepted-cut branch and is rejected as `InvalidFrontBoundaryAuthority` before the established `<4 => NotApplicable` bounded-disk applicability gate.

**Owner:** `M4-CP3-CB9` under `Architecture_M4_CP3_CB9_Code_Build_Plan.md`.

**Falsifier:** the exact ordinal138 square fixture must be statically proved to reach that early `<4` branch under current bytes; the pre-CB8/current common applicability semantics must independently establish `<4` as `NotApplicable`; row408 must remain a genuinely cut-open occurrence-domain case with at least four accepted boundary segments. If any premise fails, CB9 stops before mutation and returns to Review.

**Prohibited:** test/fixture/selector changes; changing the public aggregate fail-closed contract; bypassing A2b/A3 authority; disabling accepted-cut handling for row408; weakening missing/ambiguous/tampered occurrence rejection; changing topology/subdivision writers; geometry/tolerance fallback; broad producer redesign.

## 8. Prior obligations

- `M4-CP3-TB5-REV-CAND-01`: **DISCHARGED / CLOSED / RECOVERY PROVED / NON-STABLE** by TB6 row408 2/2 plus rows404-407 8/8.
- `M4-CP3-TB1-R1-REV-OBS-01`: **CARRIED / NON-BLOCKING**. TB6 does not exercise the multiplicity-2 end-to-end oracle path; CB9 does not touch that test-authority surface.
- `M4-CP3-CB4-REV-OBS-02`: **CARRIED / NON-BLOCKING**. TB6/CB9 do not touch row399 path/`sourceFaces` divergence tamper coverage.
- TB3 provenance warning: **CARRIED.** Row408 is a constructed production torus witness. Runtime now proves it completes the intended A3→A4 occurrence-domain path, but this remains evidence of the constructed witness—not evidence that `InvalidHardRailPairing` was historically observed before the witness existed.

## 9. Non-vacuity and stable accounting

The new RED is strongly discriminating rather than decorative:

- deleting the CB8 accepted-cut activation for all hard regions would re-break row408;
- keeping the activation but converting all `InvalidFrontBoundaryAuthority` to `NotApplicable` would weaken genuine tamper failures;
- preserving current bytes breaks accepted ordinal138;
- the bounded successor therefore has two opposed controls that can each fail: ordinal138 protects applicability/fail-closed compatibility; row408 protects cut-open occurrence authority.

No accepted-green package has regressed. Candidate package `10303165017` is rejected for promotion; accepted authority remains corrected R4 artifact `10289601000` / selector403 **403/403**. Stable accounting remains **47 / 14 / 33**, debt **5**.

## 10. Lessons applied

No new `LESSONS.md` entry is warranted. This is a concrete recurrence of existing documented patterns:

- **A guard that runs earlier can silently shadow the guard a negative test targets.**
- **Before removing a rejection, grep the accepted corpus for the code it raises.**
- **A measurement freezes a domain as well as a quantity — say which one, in the definition.**
- **Never add a variable to a turn whose evidential value comes from holding variables fixed.**

The corrective turn therefore changes one disposition seam only and keeps the torus recovery mechanism, accepted negative, selectors, fixture bytes and pipeline aggregate contract fixed.

## 11. Process note

At Review start, several carried connector/source reads were made before the mandatory `READ_MODE` gate was explicitly frozen. That was a tool-conservation process miss, not semantic evidence. Piecemeal inspection was then stopped; `READ_MODE=snapshot` was selected, exact source snapshot run `34713178370` materialized head `8da9bd6dd6184870045b30c349c54848e61f9d21`, and all subsequent repository analysis/editing was performed from that verified snapshot. No acceptance claim relies on the earlier read ordering.

## 12. Exact successor

`M4-CP3-CB9` is the one authorized successor. It is runtime-free Code + Build and may correct only the curved bounded-disk **applicability/disposition seam** frozen in `Architecture_M4_CP3_CB9_Code_Build_Plan.md`.

Its pre-mutation guards must independently prove both sides before changing source: ordinal138 is a valid three-segment planned hard-feature disc that currently reaches the early rejection, while row408 is a cut-open torus whose accepted occurrence domain remains necessary. Failure of either proof stops before mutation and returns to Review.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | PASS — selector403 `c3f509afc823cd73761bdebea0d072d497acf5587a013cb52b795f273af70cb7`; selector408 `c689c0cd8a51f9a8bd8c9ed3a2e8b603728d5a0359ee2732f776a422744b0484`; first403 byte-identical and re-hashes exactly to selector403 |
| Decisive claims independently re-derived | PASS — authoritative ZIP hashes, 148-row ledger, 147/1 classification, exact fail-fast ordinal, focused/control results, immutable postflight, selector prefix, ordinal138 raw diagnostics/assertions, producer dispatch and CB8 source branch were independently recomputed from raw bytes |
| Non-vacuity checked | PASS — row408's exact 18-edge cut receipt and ordinal138's exact three-edge one-face support force opposed outcomes; deleting either side of the intended distinction changes a frozen control |
| Prior obligations discharged/carried | TB5 candidate CLOSED recovery-proved; `TB1-R1-REV-OBS-01`, `CB4-REV-OBS-02`, and TB3 provenance warning carried explicitly |
| Stable accounting | UNCHANGED — 47 events / 14 categories / 33 recurrences; debt 5; accepted R4 artifact `10289601000` + selector403 403/403 |
| New candidates/obligations recorded | `M4-CP3-TB6-REV-CAND-01` recorded with root cause, falsifier, owner and prohibitions; tracker updated |
| ORIENTATION currency line | UPDATED to `M4-CP3-TB6-REV`, 2026-09-12 |
| ORIENTATION §3 / §4 / §7 / §8 | UPDATED — TB5 candidate discharged, torus witness marked recovery-proved, ordinal138 scope-widening blocker installed, recurring early-guard/applicability pattern recorded |
| CHANGELOG | UPDATED with TB6 Review adjudication and CB9 successor |
| ROADMAP | UPDATED — CP3 remains open; `M4-CP3-CB9` is exact next |
| Selector manifest | UPDATED status/receipt only — no selector byte was added or accepted; hashes/prefix re-proved and selector408 remains frozen/unpromoted |
| LESSONS | No new entry — existing short-title lessons above directly cover this recurrence |
| Consolidation under CLEAN_UP_POLICY | TB5 review, consumed CB8 plan and consumed TB6 execution plan folded/indexed into `M4_Consolidated_Record.md`; current TB6 runtime report retained, current Review retained, exactly one CB9 plan retained |
| Successor frozen | PASS — exactly `M4-CP3-CB9`, with G1-G3 falsifiers/stop rules in `Architecture_M4_CP3_CB9_Code_Build_Plan.md` |
| Turn boundary held | PASS — runtime-free Review + Plan; no product/test/fixture/selector/benchmark/build source mutation |
| review_check.py boundary | PASS — `ALL CHECKS PASSED` on the documentation-only review delta; no product/test/fixture/build or selector byte changed. M4 selector403/408 hashes were independently path-hashed because the helper ordinal map is milestone-ambiguous. |
| Pushed to origin, branch in sync | PENDING publication/cleanup confirmation; close only after final branch authority is re-read |
