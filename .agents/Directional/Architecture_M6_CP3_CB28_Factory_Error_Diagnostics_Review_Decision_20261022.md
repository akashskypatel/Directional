# RA-136 — CB28 review: diagnostics accepted for 18 of 21 silent REDs; three M1/A5 asserts missed; CB28A before TB29 (2026-10-22)

**Turn:** `M6-CP3-CB28-RP01-FACTORY-ERROR-DIAGNOSTICS-REV`.

**Verdict:** CB28 (`19aeb3e60`, tests only, +126/−7) is **accepted as message-only and correct** for what it covers. The diff adds message text only. No assertion, expected value, control flow, fixture or product code changes.
- **Coverage is incomplete:** 3 of the 21 silent RED rows in RA-134.2 are still silent.
- **Two of those three are the M1 precedence tests** themselves, the rows DEFN-M1 most needs measured.
- **A narrow CB28A** adds the three messages before TB29. No other rework.

## RA-136.1 Verified

- **Package:** `12460974720`. The provider digest equals the recorded ZIP SHA-256 `8f5c9a19…3d6b`; it expires 2026-10-29T21:59:16Z. The record reports 28/28 entries, GMP/GMPXX and `runtimeExecution=false`.
- **Factory formatter:** `describe_phase_front_product_error` prints the code (as an integer), `sourceAuthoritySite`, `edge`, `event`, `cell`, `region` and the `periodicRelation` carriers. Each file has its own anonymous-namespace copy, which is acceptable for separate translation units.
- **Atlas formatter:** `describe_field_atlas_build_error` prints `field_atlas_build_error_code_name`, the edge/face/vertex/region locus and the cycle-basis reason.
- **Helpers covered:**
  - direct periodic-owner (TQ:400): `selector:220, 221, 296, 302, 304, 439`;
  - publish draft (TQ:2544): `focused30:3`;
  - rebuild with edges (SP10:6542): `selector:139, 140, 142`;
  - periodic-route atlas (SP10:4401): `selector:189–195`;
  - `cp3entry:4` at its assert (TQ:3948);
  - `expect_phase_front_product_error`, which also helps `selector:211/219`.
- **Safety:** every `std::get` sits on a path where the variant is known to hold the error.
- **Off-target but harmless:** a message on `ASSERT_NE(a5)` in the passing test `M6CP1.A7ProjectsCompleteClassLineageAndSelectedRelationValues`. Keep it.
- **CB27A** (`f021e8f7b`, accepted by its review) was spot-checked against RA-135: P1–P6, the face/sheet-only side check, A6 `InvalidIsolationEvidence`, and the locus flag are present.

## RA-136.2 Missed: three silent rows

| Row | Test | Assert (HEAD) | Needed message |
|---|---|---|---|
| `focused30:12` | `M6CP1.RelationPlacementTransportIsCoordinateRigidAndFaceGaugeInvariant` | `ASSERT_NE(relabelledA5, nullptr)` TQ:5525 | `a5_rejection_message(relabelledA5Construction)` |
| `focused30:22` | `M6CP1.A5OwnsIsolationAndHardRailRouteValidationWithFrozenNames` | `ASSERT_NE(front, nullptr)` TQ:6309 | factory error of `construction` |
| `focused30:23` | `M6CP1.A5ValidationPrecedencePreservesHardRailAuthorityBeforeTransport` | `ASSERT_NE(front, nullptr)` TQ:6350 | factory error of `construction` |

- **Cause, owned by this Review line:** RA-134.5 cited TB28-era line numbers (source `e3d60337e`) without test names, and CB27/CB27A then inserted about 370 lines. The CB28 record flagged the drift honestly but did not resolve it by test name.
- **Why it matters:** `focused30:22/23` are the frozen-precedence tests on which M1 is defined (RA-105.3). Without their factory clause, DEFN-M1 would again rest on static attribution for its defining rows.
- **Durable rule:** a turn spec names targets **by test identity first**. Line numbers are advisory only.

## RA-136.3 Successor `M6-CP3-CB28A-RP01-M1-PRECEDENCE-ASSERT-DIAGNOSTICS` (Code + Build, test-only, compile only)

- **File:** `tests/SurfaceCellTransitionQuotientTests.cpp` only.
- **Change:** add message text to exactly the three asserts in RA-136.2, located **by test name**:
  - `focused30:12`: stream `a5_rejection_message(relabelledA5Construction)`;
  - `focused30:22/23`: stream `describe_phase_front_product_error` of the error alternative, using the guarded `get_if` pattern from TQ:3948.
- **Limits:** no other change.
- **Build:** compile the eight targets with GMP/GMPXX, `runtimeExecution=false`. Record `Architecture_M6_CP3_CB28A_M1_Precedence_Assert_Diagnostics_Code_Build_Record_20261022.md` (at most 20 lines).
- **STOP** on a compile error or any need to touch another assert or file.

## RA-136.4 TB29 plan (issued at CB28A-REV)

- **What runs:** a targeted, artifact-only harness (new, like TB27's) on the CB28A package, with 44 identities:
  - the four A7 negatives: unrelated seam, no certificate, lattice, withdrawn binding;
  - D3/D7 (`cp3entry:3/5`);
  - the three A7 site guards;
  - **all 35 TB28 RED rows.**
- **Report:**
  - for each RED, its typed first-failure reason;
  - for the four negatives, PASS with the expected site;
  - an attribution table by factory clause, atlas code and A5 code.
- **Why all 35, not 25:** the run is cheap, and it gives TB29-REV one complete classification set for DEFN-M1, DEFN-T1 and fixture debt.

## RA-136.5 Sequence and accounting

- **Sequence:** CB28-REV (this) → **CB28A** → CB28A-REV → TB29 → TB29-REV → DEFN-M1 (scoped from measured clauses) → DEFN-M1-REV → corrective CB/TB → DEFN-T1 → fixture debt → census → RP-01 Review. `DEFN-SEAM-NZ` and the Periodic follow-up each wait for a witness. `DIAG-RETAIN` is scheduled clear of RP-01 turns.
- **Accounting (unchanged):** stable 66/17/49, debt 1, CP2 491/491; R3 403/497 rejected; TB28 462/497 candidate; selector 497 frozen. `RP-01` open, `RP-02` UNREACHED, Gate C suspended.

| Duty | Answer |
|---|---|
| Decisive claims re-derived | CB28 diff, line by line; package digest; helper-to-row mapping against the TB28 inventory; the three unmodified asserts located by test name; CB27A preconditions present |
| Non-vacuity | Message-only diff, with no assertion or control-flow change; coverage measured at 18/21 |
| Obligations | RA-134.5 discharged for 18 rows; 3 carried to CB28A; TB29 scope fixed |
| Durable docs | Handoff, TODO, tracker, CHANGELOG, ORIENTATION, Frozen Definitions index |
| Boundary | Review-only; no source, test, selector, workflow or runtime change |
