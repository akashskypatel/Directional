# RA-117 — TB22 reviewed: fixture selection fixed; five CP2 torus rows split into a fixture atlas defect and an unowned A5 isolation family; CB22 next (2026-10-21)

**Turn:** `M6-CP3-TB22-RP01-TORUS-WITNESS-HARVEST-REV`. **Input:** TB22 [run 39549820087](https://github.com/akashskypatel/Directional/actions/runs/39549820087), report `Architecture_M6_CP3_TB22_Torus_Witness_Harvest_Report_20261021.md`, plan and predictions frozen by RA-116. **Lines:** TQ = `tests/SurfaceCellTransitionQuotientTests.cpp`, RP = `src/pipeline/RemeshPipeline.cpp`, S = `src/geometry/SurfaceCellTracing.cpp`, all at CB21 source `8453e19e6` (HEAD `src`, `include`, `tests` identical).

## RA-117.1 Harvest verified

- Result artifact `12323004201`, ZIP SHA-256 `71569a41315a727da3b1285cbdc94ffa360c366074fdecc3729ef0ed0b058c87` (downloaded and recomputed), expires 2026-11-04T05:31:17Z. 15/15 result hashes verify; 11/11 executed, 0 missing; 4 PASS / 7 RED; postflight package/source/view/selectors immutable; no compile, relink or benchmark.
- The report's rows and first failures match the raw logs. The agent closed TB22 itself with a report.

## RA-117.2 Predictions adjudicated

- **Falsifier not observed.** The receipt reads `reciprocalTracerPairs=5; holonomyMatchedPairs=5; selected=c0`: periodic publication is intact, and the D2 filter was the only fixture-selection blocker (RA-115.3 confirmed). CB21 is accepted at runtime for its scope.
- **P2 observed.** `cp3entry:1` fails at its own D2 assertion (TQ:2827). All five candidates lie on the minor hard cycle (`0-3`, `0-61`, `3-25`, `25-37`, `37-49`) with `delta=0`.
- **P3 observed.** `focused30:12` fails at TQ:5147 (`relabelledA5` null), as before. **P4 observed.** `cp3entry:6` and the three controls PASS.
- **P1 falsified.** The five CP2 rows now get past the fixture but fail further on. No row is recovered.

## RA-117.3 The five CP2 rows: two causes

**F — fixture atlas binding (test scope), `focused30:6`, `selector:447`.**
- Both rebuild the torus product from `phase_front_draft(fixture)`, whose `sourceAtlas` is `PhaseFrontFixture::fieldTransportAtlas`. `make_nonzero_z4_torus_witness_fixture` never sets that field (TQ:1607–1796).
- `SurfacePhaseFrontProduct::make` rejects a null atlas at S:8462 (`InvalidSourceAuthority`, site `atlas-binding`). This matches `focused30:6` (`InvalidPhaseFrontProduct`, TQ:8387) and `selector:447` (code 0 instead of `NonReciprocalPeriodicRelation` = 19, TQ:1913). The site is not printed; the null atlas is certain from the source.
- **Origin:** `7de636c88` (2026-10-10) made the atlas mandatory and added `fixture.fieldTransportAtlas = snapshots.fieldTransportAtlas;` to the other pipeline fixtures (TQ:649, 757, 861). This fixture was masked by the D2 filter from `88aa8eae0` (2026-10-08) and was missed. The correction is that one line (LESSONS §2 **A negative must reach the intended guard on a valid baseline**).

**A5-ISO — torus A5 isolation rejection (production, A4→A5), `focused30:20`, `focused30:24`, `selector:446`.**
- `focused30:20` (TQ:5831) and `selector:446` (TQ:8324): `build_authoritative_phase_front_mesh` on the produced torus product fails `InvalidIsolationSeamEquivalenceAuthority:a5-side`, which is A5 `MismatchedIsolationEvidence` without an occurrence (RP:3254–3256). `focused30:24` (TQ:6007): A5 produces no complex on the torus; the code is not printed.
- **This is an existing, unowned family.** TB21 shows the same A5 rejection on five more CP2 rows built from the other torus fixtures: `selector:444`, `selector:448` (`a5-side`) and `focused30:26`, `27`, `28` (`A5:OccurrenceMismatchedIsolationEvidence`). The R3 overlay already classed them as A5 isolation rejections, "carried, no new stable event". No DEFN, plan or tracker row owns them. `focused30:25` (torus pipeline `hasArrangement=false`) is a probable member, unattributed.
- **Weight.** At least 8 CP2-GREEN rows, 10 once F is corrected (both F rows materialize the torus next), and it includes `focused30:28`, the torus G4-B002 extraction (the M6 exit dependency, ROADMAP).
- **Not caused by CB20.** The family fails in A5 at R3, before the pin's extension and before CB20.
- **Two A5 branches emit `a5-side`:**
  - the side-span seam crossings at RP:4318 and RP:4359 through `transition_between` (RP:4136–4165, pre-CP2 code);
  - the relation-level certified-collinear-seam reject at RP:5205–5221, added after CP2 by `8be01326d` (R2, 2026-10-08: "Reject instead of silently falling back when the A4 certificate was present but unusable"). At CP2 this case fell back, and these rows passed.

  The logs do not say which branch fires, nor which `certified_seam_direction` clause (RP:3880–3911) fails.
- **Hypotheses:**
  - **H-ISO-1:** the RP:5205 reject is too strict for a legitimate torus pairing;
  - **H-ISO-2:** A4 publishes a seam certificate whose faces or sheets disagree with A2b sheet authority;
  - **H-ISO-3:** a side-span crossing mismatch at RP:4318/4359.

  Each needs the site, so the next unit is measurement, not repair (LESSONS §5).

**D2.** DEFN-T1 (attainability of an odd gauge on this torus under RA-111.3) remains planned. It owns one CP3-entry row, so it moves behind the two CP2 families, A5-ISO and M1.

## RA-117.4 Unchanged

`focused30:12`, `cp3entry:2` and M1 (10 identities) stay with DEFN-M1. Frozen: 66/17/49, debt 1, CP2 491/491, R3 403/497 rejected, selector 497, candidate evidence TB21 449/497. `RP-01` open, `RP-02` UNREACHED, Gate C suspended.

## RA-117.5 Next unit — `M6-CP3-CB22-RP01-TORUS-A5-ISOLATION-SITE` (Code + Build)

**Objective:** correct the F fixture defect and make every A5 isolation-evidence rejection name its site, without changing any accept/reject decision.

1. **Part A (TQ, one line).** In `make_nonzero_z4_torus_witness_fixture`, after `fixture.network = snapshots.traceNetwork;` (TQ:1672), add `fixture.fieldTransportAtlas = snapshots.fieldTransportAtlas;`, as at TQ:649 and TQ:861. No other test change.
2. **Part B (RP and its header, rejection path only).**
   - Add `std::string isolationSite` as the **last** member of `SurfaceOccurrenceComplexError` (`include/directional/pipeline/RemeshPipeline.h:963–970`).
   - Populate it only where `MissingIsolationEvidence` or `MismatchedIsolationEvidence` is returned, with a label and fields:
     - `side-step` (RP:4318), `side-collinear` (RP:4359), `wedge-edge` (RP:4470, edge-supported corner), `wedge-fan` (RP:4551, vertex-fan crossing): `;region=<r>;seam=<a>,<b>;from=<row>/<sheet>;to=<row>/<sheet>;cert=<firstRow>/<firstSheet>-><secondRow>/<secondSheet>` or `cert=none`, plus `;cell=<id>`;
     - `relation-collinear-seam` (RP:5205–5221): `;region=<r>;seam=<a>,<b>;relation=<first>,<second>;first=<row>/<sheet>;second=<row>/<sheet>;certs=<n>`, and for each certificate with that region and seam, its faces/sheets and the first failing `certified_seam_direction` clause, one of `collinear`, `region`, `first-face`, `second-face`, `same-sheet`, `first-side`, `second-side` or `same-side`; `ambiguous` if more than one certificate passes.
   - At RP:8963, when `isolationSite` is non-empty, set `result.failure` to the legacy name followed by `;site=` and the site. Every other failure string is unchanged.
3. **Compile.** Eight-target GMP/GMPXX compile, `runtimeExecution=false`. Record `Architecture_M6_CP3_CB22_Torus_A5_Isolation_Site_Code_Build_Record_20261021.md` (≤ 30 lines): source SHA, diff stat per file, compile run, package id, ZIP digest, hash count, expiry, root-manifest and source-archive SHA-256.

**Invariants (checked in CB22-REV):** no predicate, ordering, code or return-value change in A5; `transition_between` and `certified_seam_direction` decide exactly as before; site computation only on paths that already return the two isolation codes.

**Out of scope:** any other test or helper; S and A4; any repair of A5-ISO; selectors, harnesses, workflows; runtime; DEFN-M1, DEFN-T1.

**STOP and return to Review** on a compile failure, or any need to change an A5 decision, another test, or A4.

**TB23 frame (fixed in CB22-REV):**
- **Rows:** the A5-ISO family (`focused30:20`, `24`, `25`, `26`, `27`, `28`; `selector:444`, `446`, `448`), the F rows (`focused30:6`, `selector:447`), and `cp3entry:6`, `selector:217`, TB18 A#14, `selector:443`, plus one certified-seam positive control chosen by CB22-REV.
- **Predictions:**
  - every A5-ISO row prints a `site=`;
  - the F rows reach materialization, the same site;
  - controls unchanged;
  - no status change elsewhere.

## RA-117.6 Sequence

- **Sequence:** TB22 → TB22-REV (RA-117) → **CB22** → CB22-REV → TB23 (torus A5 site harvest) → TB23-REV → DEFN-ISO (the A4 seam certificate ↔ A5 binding contract, including the `8be01326d` reject) → corrective CB/TB → DEFN-M1 → corrective CB/TB → DEFN-T1 → fixture debt → census → RP-01 Review.
- **Accounting:** unchanged (RA-117.4).

Closed by RA-118 — CB22 compile stop reviewed; CB22A authorized (`Architecture_M6_CP3_CB22_Torus_A5_Isolation_Site_Compile_Stop_Review_Decision.md`).
