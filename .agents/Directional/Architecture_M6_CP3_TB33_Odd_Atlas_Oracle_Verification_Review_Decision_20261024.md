# RA-149 — TB33 review: odd-atlas oracles accepted (synthetic scope); realign onto the 19 residual REDs, largest cluster first (2026-10-24)

**Turn:** `M6-CP3-TB33-RP01-ODD-ATLAS-ORACLE-VERIFICATION-REV`.

**Verdict:** TB33 is **accepted** as runtime evidence for the CB32 odd-atlas and checked-factory oracles. It covers **synthetic scope only**: no produced periodic front, A5/A6, G4-B002 or CP3 credit. This discharges RA-146.3 (odd transport runtime verification) within that scope.

**Realignment:**
- **Since TB31,** six turns of FG01/CB30/TB32 recovered six rows (TB32: 478/497 original plus 3 controls = 481/500). Then six turns of CB31/CB32/TB33 added oracle coverage **without removing any RED**.
- **What is left:** the 19 residual REDs, not further synthetic hardening.
- **Next:** the largest independent cluster, A3 `CycleTransportMismatch` (`selector:189–195`, 7 rows), starting with a **diagnostic**, because its two source sites are indistinguishable today.

## RA-149.1 Verified

- **Result:** `12543546779`. The provider digest equals the local ZIP SHA-256 `217f6b21…c09d`; it expires 2026-10-31T01:54:32Z. **15/15** checksums pass.
- **Execution record:** source `30e46b9aa`, package `12541198172`; 6 planned and executed, 6 PASS, every `*_bad`/missing value 0; postflight true, exit 0; no compile, relink, configure or benchmark.
- **Manifest:** `Architecture_M6_CP3_TB33_Odd_Atlas_Oracle_Cases.tsv` SHA-256 `09c0d065…f872` matches. Each log has 1 RUN, 1 OK and no failure. The harness was `436f5fff…c9a`.
- **Non-vacuity** (TQ:9284–9436; no `GTEST_SKIP` or early `return`):
  - the positive test asserts the source-derived odd turn `3` (`ASSERT_EQ(3, expectedTurn)`), transport values 1/3 with an exact inverse, and the mapped forward transport `3` under row and corner permutations;
  - both negatives assert `InvalidSourceAuthority` **and** the exact site `gauge-pin-consistency;edge=0,2`, after asserting their preconditions (equal baseline and permuted turns; inverse turn `(4 − 3) % 4 = 1`).

  So PASS on these tests means each assertion was reached and held.

## RA-149.2 Residual REDs (19) and order of attack

| Order | Group | Rows | First step | Why this order |
|---|---|---|---|---|
| 1 | A3 `CycleTransportMismatch` | `selector:189–195` (7) | **Diagnostic CB** (RA-149.3) | Largest cluster; one fixture helper (SP10:4380–4402); site unknown |
| 2 | Untyped producer/oracle | `selector:174, 201, 204, 242, 247, 250, 405` (7) | Per-row first-failure pin; 174, 242, 250 are RA-92.3/93.3 fixture debt | Independent rows |
| 3 | A5 transport | `focused30:12` | DEFN (relabel equivalence) | Single row, frozen invariance test |
| 4 | A4 open-rail-chain | `cp3entry:4` | DEFN | Single row |
| 5 | A3 singularity | `selector:442` | Fixture/atlas review | Single row |
| 6 | Witness absence | `cp3entry:1/2` | DEFN-T1 | Needs a produced witness |

## RA-149.3 Why a diagnostic first for A3 cycles

`FieldTransportAtlas::make` raises `CycleTransportMismatch` at **two** sites. Both call `fail(…, region.id())` and drop every locus:
- **S1** (`src/authority/FieldTransportAtlas.cpp:2582–2585`): a cycle's composed transport ≠ its turning lift. `orderingDiagnostics` (`cycleRowIndex`, `cycleKind`: LocalVertex / BoundaryLoop / HandleGenerator) is computed just above and then discarded.
- **S2** (`:2691–2695`): the canonical boundary cycle's lift, **after** the index-sum correction, ≠ its composed transport.

TB31 logs show only `code=CycleTransportMismatch;topologyRegion=0`. The error type already has a `cycleOrderingDiagnostics` field (`FieldTransportAtlas.h:259`) but no way to say which of S1 or S2 fired.

- **S1** points to an inconsistent field or source cycle in the fixture: fixture debt, or a real A3 transport defect.
- **S2** points to an index-sum or boundary-correction problem: an A3 admissibility contract question.

The owner cannot be named until this is measured.

## RA-149.4 Successor `M6-CP3-CB33-RP01-A3-CYCLE-MISMATCH-LOCUS-DIAGNOSTIC` (Code + Build, compile only; diagnostic only)

1. **`include/directional/authority/FieldTransportAtlas.h`:** add `std::string site;` to `FieldAtlasBuildError`. It defaults to empty. The defaulted `operator<=>` is unchanged; no test compares whole errors (`FieldTransportAtlasTests.cpp:2015–2024, 2480, 2666` compare codes only).
2. **`src/authority/FieldTransportAtlas.cpp`:** on the two `CycleTransportMismatch` paths only:
   - **S1:** `site = "cycle-transport"`; attach `orderingDiagnostics` as `cycleOrderingDiagnostics`; for a LocalVertex cycle, set `sourceVertex` where it is already known before the return. If it is not known before the return, record that, and do not reorder code.
   - **S2:** `site = "cycle-boundary-corrected-lift"`; set `cycleOrderingDiagnostics` with `cycleKind = BoundaryLoop` and `cycleRowIndex` = the canonical boundary cycle's index.
   - Codes, return points and control flow are unchanged.
3. **`tests/SurfaceCellsPhase10Tests.cpp`:** `describe_field_atlas_build_error` (SP10:73–90) also prints `site`, `cycleRowIndex` and `cycleKind` when they are present. Message only.
4. **Limits:** no other file or path. Lines at most 100 columns.
5. **Build:** compile the eight targets with GMP/GMPXX, `runtimeExecution=false`. Record `Architecture_M6_CP3_CB33_A3_Cycle_Mismatch_Locus_Diagnostic_Code_Build_Record_20261024.md` (at most 30 lines).

**STOP** if S1's locus requires reordering code, or if any error code or return changes.

## RA-149.5 TB34 plan (manifest issued at CB33-REV)

- **What runs:** the targeted harness on the CB33 package:
  - `selector:189–195` (RED expected, now with site and cycle);
  - guards `FieldTransportAtlas.IndependentOracleRejectsCycleOrderingTamper` and `FieldTransportAtlas.IndependentOracleRejectsCompleteTypedTamperMatrix` (PASS expected, because codes are unchanged);
  - the three TB33 factory controls.
- **Then:** TB34-REV names the owner (fixture debt or A3 contract) from S1 versus S2 and the cycle kind and row.

## RA-149.6 Sequence and accounting

- **Sequence:** TB33-REV (this) → **CB33** → CB33-REV → TB34 → TB34-REV → A3-cycle owner (DEFN, fixture CB or A3 CB) → per-row pins for the 7 untyped rows → `focused30:12` DEFN → `cp3entry:4` DEFN → `selector:442` → DEFN-T1 → census → RP-01 Review. RA-146.2, RA-146.4/RA-45.4 (produced A6), G4-B002, `DEFN-SEAM-NZ` and the Periodic follow-up are carried. `DIAG-RETAIN` is scheduled clear of RP-01 turns.
- **Accounting (unchanged):** stable 66/17/49, debt 1, CP2 491/491; R3 403/497 rejected; **TB32 481/500 candidate** (original 497: 478 PASS / 19 RED); selector 497 frozen. `RP-01` open, `RP-02` UNREACHED, Gate C suspended.

| Duty | Answer |
|---|---|
| Decisive claims re-derived | TB33 digest, 15/15, boundary state, ledger, per-log RUN/OK; manifest SHA; oracle test bodies; both A3 raise sites and the error struct; tests comparing codes only |
| Non-vacuity | Oracle assertions reached, with no early exits; the diagnostic separates S1 from S2 |
| Obligations | RA-146.3 discharged (synthetic scope); 19 REDs ordered with owners; carried items listed |
| Durable docs | Handoff, TODO, tracker, CHANGELOG, ORIENTATION, Frozen Definitions index |
| Boundary | Review-only; no source, test, harness, selector, workflow or runtime change |
