# RA-114 — TB20 reviewed: corrected pin confirmed at runtime; M2 cleared at the factory; selector-497 census next (2026-10-21)

**Turn:** `M6-CP3-TB20-RP01-GAUGE-PIN-DOMAIN-REV`. **Input:** TB20 run [39527537505](https://github.com/akashskypatel/Directional/actions/runs/39527537505), harness `m6_cp3_tb20_gauge_pin_domain_harness.sh` (`18a1325d2`, SHA-256 `69b173e5…48bb`). The agent left TB20 `IN_PROGRESS` after dispatch and wrote no report. As in RA-113, this decision holds the verified harvest facts. **Lines:** TQ = `tests/SurfaceCellTransitionQuotientTests.cpp` at `e22c5da5f`.

## RA-114.1 Harvest verified

- **Harness:** its diff from TB19A is exactly the RA-113.5 set: sha, artifact, digest, the 26 rows, the count and the labels.
- **Result artifact:** `12314700010`, ZIP SHA-256 `3731402f871f042fbaa0540304e28e65c8add9f73233cba704b8c9e1f5d7787f`, expires 2026-11-04T01:35:20Z. Its `ledger.tsv` has SHA-256 `a9dae84c2a23dc4b59c1fc98ed0181323f8bc81f852b03f14d0f4c0581f06c83`.
- **Integrity:** 30/30 result hashes verify; planned = executed = 26; missing 0; 19 RED; postflight immutability true for the package, source, view and frozen selectors.

| # | Group | Identity | Baseline | TB20 | TB20 first failure |
|---:|---|---|---|---|---|
| 1 | M2 | cp3entry:1 | TB19A RED (pin `0,3`) | RED | torus witness not found (TQ:1745) |
| 2 | M2 | cp3entry:2 | TB19 RED (pin `1,4`) | RED | TQ:3024: no produced paired (1,4)→(4,7) hard-rail route certificate |
| 3 | M2 | cp3entry:6 | TB19 RED (pin `1,4`) | **PASS** | — |
| 4 | M2 | focused30:6 | TB19A RED (pin `0,3`) | RED | torus witness not found (TQ:1745) |
| 5 | M2 | focused30:12 | TB19 RED (pin `1,4`) | RED | TQ:5121: `produceA5` on the relabelled front returns no complex |
| 6–9 | M2 | focused30:20, focused30:24, selector:446, selector:447 | TB19A RED (pin `0,3`) | RED | torus witness not found (TQ:1745) |
| 10–19 | M1 | the ten RA-113.3 M1 rows | TB19 RED | RED | 10/10 equal to TB19 after the +77 TQ mapping |
| 20–22 | control | selector:217, TB18 A#14, selector:443 | PASS | PASS | — |
| 23–25 | suite | the three `SurfaceCellFactoryRejectionSite` tests | new | PASS | — |
| 26 | oracle | A6UniformFaceGaugeRotationPreservesRelationOutcome | R4 RED | RED | TQ:2944: `originalOccurrences` is null, before any gauge assertion |

The torus message is byte-identical in all six rows: `sourceA3Candidates=5; sourceFaceGaugePairs=5; oddFaceGaugePairs=0; reciprocalTracerPairs=0; publishedPeriodicHolonomies=18; nonzeroHardCarriers=5`.

## RA-114.2 Predictions adjudicated

- **P1 observed:** the three suite tests PASS.
- **P2 observed:** no log contains `gauge-pin`.
- **P3 observed:** no log contains `PublishedProductRejected`, so there is no span site and no pin site on a non-hard edge. RA-111.5 stays open but untriggered.
- **P4 observed:** the three controls PASS.
- **Verdict:** CB20/CB20A is accepted at runtime on these 26 rows. Regression safety beyond these rows needs the census (RA-114.5).
- **R-route (RA-103.5):** its falsifier is a checked-factory `InvalidSourceAuthority` on a route the consumer certified with R. It is not observed in any row. M2 is cleared at the checked factory.

## RA-114.3 M2 after the pin: three outcomes

> *Amended by RA-115.3 (2026-10-21): TQ:1697 is D2 / RA-33.2, not a proxy for odd A3 transport; it sits in a fixture shared with six CP2 rows. H-T2 has no support.*

- **Passing, 1 row:** `cp3entry:6`.
- **Hard-rail certificate area, 2 rows:**
  - `cp3entry:2` constructs its product, but the producer publishes no paired (1,4)→(4,7) route certificate;
  - `focused30:12` passes the factory, which was its TB19 failure at TQ:5113, and then fails in A5.

  Both lie in the area of the M1 binding owner (RA-105.3). The M1 DEFN classifies them; Review does not merge them into M1 now.
- **Torus witness predicate, 6 rows.** The fixture `make_nonzero_z4_torus_witness_fixture` (TQ:1606) drops every candidate whose published face gauges differ by an even quarter-turn (TQ:1697). Its five source/A3 candidates lie on hard carriers.
  - Under RA-111.3, the gauge difference across a hard carrier inside a region is the transport along a non-hard path. That transport is the carrier's A3 transport composed with the cycle's holonomy, which is not the A3 transport itself on a nonzero-Z4 torus.
  - The filter therefore reads a gauge difference outside the RA-111.4 domain, as the old pin did. TB19A measured that inequality at {0,3}.
  - **History:** the filter is absent at CP2 `5ce3132ec`, where the fixture already existed (TQ:1393) and five of these rows were GREEN. It entered with `88aa8eae0` (2026-10-08, M6 CP3 R2).
  - **Hypotheses:**
    - **H-T1:** the filter is a test-side proxy for "odd A3 transport on the carrier" and is invalid under RA-111. The correction is a test-only predicate.
    - **H-T2:** it encodes a producer gauge contract that a later change lost. The correction is in production.

  This is a test consumer, so RA-111.2's STOP does not apply. Deciding between H-T1 and H-T2 is DEFN-T1's job.

## RA-114.4 Unchanged

- M1 is unchanged: 10/10 identical to TB19.
- The oracle fails before its gauge assertion, so it says nothing about the pin.
- Accounting is unchanged. TB20 is a targeted run and is not a census.

## RA-114.5 Next unit — `M6-CP3-TB21-RP01-SELECTOR-497-CENSUS` (Test + Benchmark, artifact-only)

**Why now:** CB20 changes every product construction, and TB20 covered three controls. The census is the regression check, and the CB20A package expires 2026-10-28T00:23:30Z.

1. **Harness and inputs.** Run `.agents/Directional/tools/m6_cp3_entry_497_artifact_only_harness.sh` unchanged (SHA-256 `947a95ee4f684143a0f8d7c768a39253ab893d921da488802b45fb6ed58879dd`) with `--execute` and:
   - `CANDIDATE_ARTIFACT_ID=12310848591`;
   - `EXPECTED_SOURCE_SHA=e22c5da5f8ab86a39650c670340a658847a2ac7e`;
   - `EXPECTED_CANDIDATE_ZIP_SHA256=0c9f048e9a67fdaf61231b2ffa6834ee21a48e142f9cdae9e7ab14e015fc3ff5`;
   - `EXPECTED_ROOT_MANIFEST_SHA256=c735e5f76f84a887e0b5613bb65969a68cb4e10321d33a8113167e3978c8206b`;
   - `EXPECTED_SOURCE_ARCHIVE_SHA256=e231fcead36c5436719f13a87b249e2ff6bb69f54c3480fbecee2773d1878f57`.

   Review computed the last two values from the verified package.
2. **Baseline:** TB18 Part B, result `12232299548` (expires 2026-11-03), and `Architecture_M6_CP3_TB18_Selector_497_Red_Inventory.tsv`.
3. **Deliverables:**
   - `Architecture_M6_CP3_TB21_Selector_497_Red_Inventory.tsv`: one row per RED, with columns phase, ordinal, identity, owner, exit, raw_sha256, first_failure, TB18 status and TB18 first failure;
   - `Architecture_M6_CP3_TB21_Selector_497_Census_Report_20261021.md`, at most 30 lines: run, artifact and digest; totals per phase; the TB18→TB21 PASS→RED and RED→PASS lists by name; the TSV's SHA-256. No interpretation.

**Predictions:**
- 0 PASS→RED;
- RED→PASS includes `cp3entry:6`;
- at least 449/497 PASS;
- the other eight M2 rows keep their TB20 first failures;
- no first failure contains `gauge-pin-span` or a `gauge-pin-consistency` site on a hard edge.

**Falsifiers:** any PASS→RED, or any gauge-pin site on a hard edge.

**STOP and return to Review** on:
- a harness orchestration failure or a digest mismatch;
- any need to change the harness.

There is no repair inside the turn.

**Closeout:** the turn is complete only when the report is committed and STATUS is COMPLETE. Do not yield after dispatch; harvest in the same turn.

**On success:** `M6-CP3-TB21-RP01-SELECTOR-497-CENSUS-REV` (Review).

## RA-114.6 Sequence and accounting

- **Sequence:** TB20 → TB20-REV (RA-114) → **TB21** → TB21-REV → DEFN-T1 → DEFN on the M1 binding owner (RA-105.3), which also classifies `cp3entry:2` and `focused30:12` → corrective CB/TB → fixture debt → census → RP-01 Review.
  - DEFN-T1 is source-only. It compares the torus witness fixture at CP2 `5ce3132ec` with `88aa8eae0` and HEAD, names the invariant behind the odd-gauge filter, and decides between H-T1 and H-T2.
- **Accounting is unchanged:** 66/17/49, debt 1, CP2 491/491, R3 403/497 rejected, TB18 candidate 448/497, selector 497. `RP-01` is open, `RP-02` is UNREACHED and Gate C is suspended.

> *Closed by RA-115 (2026-10-21): TB21 is regression-free (449/497, 0 PASS→RED); CB21 (test-only witness-selection scope) precedes DEFN-T1.*
