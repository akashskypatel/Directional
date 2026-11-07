# RA-158 — TB41-REV audit: O3 owner, DEFN split, off-selector coverage gap (2026-10-26)

**Turn:** `M6-CP3-TB41-RP01-REHOMED-ORACLE-VERIFY-REV-AUDIT` (Review). **Decision:** TB41-REV is **confirmed** (18/18 focused candidate; no CP3 or selector497 promotion). Its successor is **realigned**: the orphaned O3 runtime obligation gets an owner first (its package expires), and the monolithic legacy-path/seam DEFN is split by mechanism.

## RA-158.1 Independent verification

- TB41 result `12638251384`: ZIP SHA-256 `1817f8295709a88bb3a561734b345cc50e81da056684501d714aac08fb7dd854`; 39/39 inner hashes; 18/18 raw logs re-joined to ledger (hash, one RUN, one OK, `PASSED 1`, no FAILED); 18 unique tests; boundary `postflight=true`, no compile/relink/configure.
- Manifest SHA-256 `659c52f08bf5e5cbef6d2f1e1255432a247eb50da77bd4323666dfac900b2959` matches the committed file.
- No `src/`, `include/`, `tests/`, `benchmarks/` or CMake change between CB42 source `8dc8cdeae` and HEAD.
- The five `InvalidBoundedDiskFrontPairing` sites remain `SurfaceCellTracing.cpp:17190, 17889, 17948, 17969, 18034`; only `:17190` leaves `cell`/`side` at −1, so the CB42 pins discriminate.

## RA-158.2 Findings

- **L1 — O3 obligation orphaned and time-bound.** TB41-REV correctly found that `SurfaceCellsPhase10.PolygonalCurvedDiskRejectsWithoutPublishingPartialPhase` (`Phase10Tests:2940–2958`) was never executed, but carried it to "a future authorized TB gate" with no canonical owner or sequence slot. The omission originated in RA-157.4, which listed TB41 rows by selector number only, so the off-selector test had no row. CB42 package `12634151125` expires **2026-11-02T07:22:41Z**; after that the run needs a recompile. Owner: **TB42** (next turn).
- **L2 — DEFN successor is monolithic and its Review ID was left unfrozen.** `M6-CP3-DEFN-RP01-LEGACY-PATH-AND-SEAM-ORACLES` bundles three mechanisms: (a) 190 + O2, legacy-matching path (RA-155 H2: a legacy-only field yields A3 `MissingAdjacency`, so the legacy branches `SurfaceCellTracing.cpp:14950–14979` and `:6731ff` cannot publish), which also needs an accepted-prefix accounting rule; (b) O4, reachability of A4 `MissingTransitionProvenance` (`:12656/12698/12707`) once A4 reads the checked atlas first; (c) 242, a cross-region `transition_value` with no A2–A4 consumer (RA-155 H3; DEFN-SEAM-NZ). "Successor ID to be frozen by the Definition record" recreates the Successor-UNKNOWN stall of TB40. **Split into three DEFN turns with frozen IDs (RA-158.3).** The old ID is superseded.
- **L3 — 192 is now the TB36 quarter-turn guard.** After CB40, 192's negative half (`turning_periodic_route_field(fixture,1)`, A3-positive, A4 `PeriodicHolonomyMismatch`, all-−1 locus) is assertion-for-assertion `expect_authoritative_periodic_monodromy_rejected(1)` (`Phase10Tests:4665`). TB41 counted one mechanism twice (POSITIVE 192 and GUARD `tb36:quarter-monodromy`). Not a defect: RA-155.3 B required this stimulus. The rotation pin was relaxed from exactly `q` to `q` or `q⁻¹`; acceptable because A4 rejects any non-identity rotation and 194 covers the inverse. No action.
- **L4 — 247 carries orphaned setup.** CB40 stopped mutating the located `transition` (`Phase10Tests:5345–5375`, inside test 247 at `:5297`), but kept ~30 lines that find it and assert its EF reciprocity. They still assert facts about the valid input field, so they are not vacuous, but the next reader will assume they target the stimulus. Not scheduled; remove only if a later turn edits 247 for another reason.
- **L5 — new observation O5: off-selector producer tests are in no gate.** Static parse of `TEST`/`TEST_F` identities in the 14 test sources compiled into `directional_surface_cell_producer_tests` (`cmake/DirectionalTests.cmake:73–90`): **598** identities; **349** are in focused30 ∪ focused12 ∪ selector449 ∪ the six cp3entry names; **249** are in none. They include 42 `SurfaceCellsPhase10`, 14 `M6CP3`, 7 `SurfacePhaseFrontProductFactoryAuthority`, 4 periodic-holonomy (both TB36 guards), and `CurvedBoundedDiskInvalidReciprocalTransportFailsClosed` (the RA-155.4 inventory item). The R3 audit (2026-10-09) reported 4; the gap has grown with every CP3 test added. No regression is claimed (never measured), but the census → RP-01 Review cannot speak to these tests. Owner: a coverage-disposition DEFN placed before the census manifest.
- **L6 — documentation drift.** Handoff authority table had departed from the template rows (and its "Reviewed decision" cited CB41-REV); TODO CURRENT kept "NEXT TB41-REV" unchecked and "O3 pending TB41-REV". Corrected in place.

## RA-158.3 Turn sequence (frozen IDs)

1. `M6-CP3-TB42-RP01-O3-OFF-SELECTOR-LOCUS-VERIFY` → `…-REV`. Artifact-only, one POSITIVE row on CB42 package `12634151125`; must run before 2026-11-02T07:22Z.
2. `M6-CP3-DEFN-RP01-LEGACY-MATCHING-PATH-DISPOSITION` → `…-REV`. 190 + O2: retire 190 or re-home it as an A3 `MissingAdjacency` negative; accepted-prefix accounting rule for a changed/retired identity in the 449; scope (not code) for removing the unreachable legacy branches.
3. `M6-CP3-DEFN-RP01-A4-PROVENANCE-GUARD-REACHABILITY` → `…-REV`. O4: decide whether each `MissingTransitionProvenance` site is reachable from any input that passes checked A3; if reachable, name a witness; if not, classify as defensive and say whether it stays.
4. `M6-CP3-DEFN-RP01-SELECTOR242-CROSS-REGION-SEAM-CONSUMER` → `…-REV`. 242: name a downstream consumer of cross-region `transition_value` (isolation-seam certificate) or retire; coordinate DEFN-SEAM-NZ.
5. Code/TB turns that steps 2–4 authorize (their Reviews assign IDs).
6. 405 → 174, 201 → `focused30:12` → `cp3entry:4` → `selector:442` → DEFN-T1 (`cp3entry:1/2`).
7. `M6-CP3-DEFN-RP01-OFF-SELECTOR-COVERAGE-DISPOSITION` → `…-REV`. O5: classify the 249 off-gate producer tests (CP3-required / legacy-retire / out-of-scope) and freeze any supplemental census rows.
8. Census → RP-01 Review.

Each DEFN is design-only, one mechanism, falsifiable and independently reviewable. Superseded: `M6-CP3-DEFN-RP01-LEGACY-PATH-AND-SEAM-ORACLES`.

## RA-158.4 TB42 specification

- **Package:** CB42 artifact `12634151125`, ZIP SHA-256 `d7f7b8302966b14acd919eeef4465d518a6179f1823fbb86ad0e5b1b43488b87`, source `8dc8cdeae6f6ac05c28aaa4504ca2c42c3177ded`, 28/28.
- **Harness:** unchanged `tools/m6_cp3_targeted_artifact_harness.sh` (SHA-256 `436f5fff9c3bec97457f4bc6b7c2b6182cb3f47707eb14a66af3b6a3f3dc3c9a`).
- **Manifest (freeze and commit before dispatch):** exactly one row, `POSITIVE`, identity `o3:polygonal-partial-phase`, test `SurfaceCellsPhase10.PolygonalCurvedDiskRejectsWithoutPublishingPartialPhase`, binary `directional_surface_cell_producer_tests`, expect `PASS`.
- **Pass condition:** one process, exit 0, one RUN, one OK; ledger, raw log, boundary with `postflight=true` and no compile/relink/configure.
- **STOP → Review:** package expired or any hash mismatch (do not recompile); harness rejects a one-row manifest (do not edit it). A RED is recorded as RED with its first failure line, never "fixed" in the same turn.
- **On PASS:** O3 runtime discharged as a focused candidate (3/3 locus tests). No selector or CP3 promotion.

## RA-158.5 Accounting

Unchanged: stable 66/17/49, debt 1; CP2 491/491 accepted; TB32 481/500 and TB38 490/504 candidate; TB41 18/18 focused candidate; selector497 frozen; RP-01 open, RP-02 unreached. Carried: DIAG-RETAIN, O1, O2, O3 (until TB42), O4, O5, RA-152.5, DEFN-SEAM-NZ, RA-146.2/4, RA-45.4, G4-B002.
