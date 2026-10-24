# RA-108 — TB19 run read: torus rows unmeasured (fixture staging); TB19 closes on 16 valid rows; TB19A reruns the torus (2026-10-20)

**Turn:** `M6-CP3-TB19-RP01-TORUS-STAGING-REV`. **Inputs:**
- TB19 dispatch run `39464430751` (executor `f8e6e3efc`, harness SHA-256 `c33014b5…5b5c`);
- result artifact `12285225197`, ZIP SHA-256 `2b5dfacf79e068cad8e28af5c840668c3f26287a2a473fade63924d12d77dec0`, expires 2026-11-03T17:19Z;
- TB18 Part B artifact `12232299548` (raw logs, for comparison).

**State.** TB19 is `IN_PROGRESS` and has no report yet. **Why Review now:** the run finished, and six rows carry a defect that RA-107.3's harness rule caused. This record rules only on which rows are valid and on what runs next. It is not TB19-REV: H-pin, the R-route and the DEFN stay with TB19-REV. **S** = `src/geometry/SurfaceCellTracing.cpp`, **TQ** = `tests/SurfaceCellTransitionQuotientTests.cpp`, both at `d2c7483cd`.

## RA-108.1 What the artifact shows (re-derived independently)

- **Integrity:**
  - the provider digest equals the ZIP SHA-256;
  - `SHA256SUMS` 26/26;
  - raw-log hashes 22/22;
  - boundary: planned 22, executed 22, missing 0, red 19, postflight true, exit 0, no compile, relink or benchmark;
  - GMP linked.
- **`cp3entry:2` and `cp3entry:6`:** RED with `product=0 detail=none site=gauge-pin-consistency;edge=1,4`.
- **`focused30:12`:** RED at TQ:5036 with `product=0 site=gauge-pin-consistency;edge=1,4`. The ledger's product and site columns are empty: the harness extracts only from `producer failed:` lines, and this row fails a direct factory assertion. The values are taken from its first-failure text.
- **M1 (10 rows):**
  - nine are byte-identical to the TB18 Part B raw logs after the RA-107.2 line mapping;
  - `focused30:3` is identical to its TB18 inventory text.
- **Controls:** 3/3 PASS.
- **Torus (6 rows):** `cp3entry:1`, `focused30:6/20/24` and `selector:446/447` are RED with `Directional test-data package not found adjacent to test executable: …/view/bin`. In TB18 they reached `torus nonzero-Z4 source witness producer failed: PublishedProductRejected` (TQ:1672).
- **Observation for TB19-REV:**
  - the `cp3entry:2/6` fixture (TQ:787) declares hard edges (1,4) and (4,7) (TQ:841);
  - it rotates the field a quarter-turn on faces whose centroid has x > 1 (TQ:827);
  - edge (1,4) is therefore a hard-rail carrier that crosses a deliberate field discontinuity. This is recorded here and not adjudicated.

## RA-108.2 The torus defect: cause and ownership

- **Cause.** Harness line 56, `shutil.copytree(src/"benchmarks/fixtures", view/"test-data/benchmarks")`, puts the fixture tree at `view/test-data/benchmarks/milestone-g/…`. `find_test_data_root` (`tests/TestFixturePaths.h:53`) requires `view/test-data/benchmarks/fixtures`. The 497 harness stages the tree correctly (`m6_cp3_entry_497_artifact_only_harness.sh:249–250`).
- **Inherited from the template.** The line is verbatim from `open_rail_interior_vertex_harness.sh`. None of that harness's 14 tests loads a fixture, so the defect was latent there.
- **Owned by Review.** RA-107.3 said "copy it, change only …" and required no control that loads a fixture. The agent's harness follows RA-107.3, so this is a gap in Review's specification, not an implementation error (LESSONS §7, fixture portability).
- **Exit 0 does not validate the six rows.** They never reached the producer; their RED status matches TB18 only by coincidence.
- **The other 16 rows are unaffected.** Only the six torus logs contain the not-found message, and the three controls pass. None of the 16 reached `test_data_root()` before its first failure or its pass, so staging cannot have changed them.

## RA-108.3 Validity ruling

- **Valid:** rows #2, #3, #5 and #10–#22 (16 rows).
- **Invalid, NOT MEASURED:** the six torus rows (#1, #4, #6–#9). They are not evidence for F1 or F3.
- **R-route: NOT REACHED** (not "held"). The gauge pin (S:8509–8567) runs before the certificate loop (S:8782), so `cp3entry:2/6` reject before any endpoint clause runs.
- **Falsifier lines for the TB19 report:**
  - F1: held on the 16 valid rows; torus not measured;
  - F2: held;
  - F3: held for `focused30:12` (edge 1,4); torus not measured;
  - F4: held, 10/10;
  - RA-103.5 R-route: not reached;
  - RA-106.5 non-zero code: none, so no follow-up.
- **Left to TB19-REV:** H-pin, the meaning of the edge (1,4) result, and the scope of the DEFN.

## RA-108.4 TB19 closeout — `M6-CP3-TB19-RP01-FACTORY-REJECTION-SITE` (no dispatch)

- **Output:** `Architecture_M6_CP3_TB19_Factory_Rejection_Site_Harvest_Report_20261020.md`, built from artifact `12285225197` as RA-107.3 specifies, plus:
  - all 22 rows; the six torus rows marked `NOT MEASURED — fixture staging (RA-108.2)`;
  - `focused30:12` product and site taken from its first-failure text, and detail `not streamed`;
  - the falsifier lines exactly as RA-108.3 gives them.
- **Forbidden:** a new harness, a dispatch or rerun, any source/test/selector/fixture change, and any adjudication.
- **On success:** TB19A.

## RA-108.5 TB19A — `M6-CP3-TB19A-RP01-TORUS-REJECTION-SITE` (Test + Benchmark, artifact-only)

### Harness

New `.agents/Directional/tools/m6_cp3_tb19a_torus_rejection_site_harness.sh`, a copy of `m6_cp3_tb19_factory_rejection_site_harness.sh` with only these changes:
1. **Staging:** `shutil.copytree(src/"benchmarks/fixtures", view/"test-data/benchmarks/fixtures")`.
2. **Pre-execution check:** `view/test-data/benchmarks/fixtures/milestone-g/torus.obj` and `torus.rawfield` must both be files.
3. **Per-row check:** a raw log that contains `test-data package not found` is a harness failure.
4. **The 7-row list below,** with count checks of 7 and output labels `TB19A`.

Everything else is unchanged:
- the same package pins (source `d2c7483cd…`, artifact `12275794192`, digest `e4a39cdb…d723a`);
- the 28-entry manifest and the frozen-selector hashes;
- the GMP and `runtimeExecution=false` checks;
- one test per filter;
- the extraction;
- the postflight check.

### Rows

| # | Group | Identity | gtest | TB18 | Prediction |
|---|---|---|---|---|---|
| 1 | M2 | cp3entry:1 | `M6CP3.PeriodicExactA3UnequalFaceGaugeUsesRelationAndOccurrenceAuthority` | RED | RED, `product=0 detail=none site=gauge-pin-consistency;edge=…` |
| 2 | M2 | focused30:6 | `M5CP3.ProducedTorusPeriodicPairStorageSwapPreservesSemanticDirection` | RED | as #1 |
| 3 | M2 | focused30:20 | `M6CP1.NonzeroZ4WitnessPassesProductionCompletionOwnership` | RED | as #1 |
| 4 | M2 | focused30:24 | `M6CP1.ThinAdapterOutputIsPureProjectionOfStageProducts` | RED | as #1 |
| 5 | M2 | selector:446 | `M5CP3.ProducedTorusNonzeroZ4RotationTranslationMaterializes` | RED | as #1 |
| 6 | M2 | selector:447 | `M5CP3.ProducedTorusTamperedNonzeroZ4TransformRejectsTyped` | RED | as #1 |
| 7 | control | selector:443 | `M5CP3.ProducedTorusPublishesTwoCanonicalPeriodicRelationsAndOwnedEdges` | PASS | PASS |

**Why `selector:443` is the control:**
- it loads `milestone-g/torus.obj` through `torus_fixture()` (TQ:883 → TQ:708);
- it is in selector 449, and TB18 Part B passed it.

A PASS proves that the binary resolves the staged root. It also shows a torus product that clears the pin.

### Falsifiers and output

- **Falsifiers.** Report each as held or fired:
  - **G1:** row #7 is not PASS. This means a staging failure or a regression, and it is a STOP.
  - **G2:** a torus first failure other than `torus nonzero-Z4 source witness producer failed: PublishedProductRejected` plus the appended fields.
  - **G3** (RA-107.3 F3): a torus site other than `gauge-pin-consistency`.
  - **G4** (F2): `product=0` with an empty site.
- **Not falsifiers:**
  - the reported edge, which is recorded, not predicted;
  - a non-zero `product=`, which is recorded under RA-106.5.

> **Amended by RA-109.4:** the report also classifies each torus site's edge against the 18 `torus_row408_hard_edges`.

- **Output:** `Architecture_M6_CP3_TB19A_Torus_Rejection_Site_Harvest_Report_<date>.md` with:
  - the run, the artifact and the ZIP SHA-256;
  - manifest counts;
  - the 7-row ledger (TB18 status, TB19A status, first failure, product, detail, site, raw SHA);
  - G1–G4 held or fired.
  - No adjudication.
- **Forbidden:**
  - compiling or relinking;
  - source, test, selector or fixture changes;
  - benchmarks and test discovery;
  - any repair.
- **STOP:** a harness verification failure, an expired package (2026-10-27T15:24Z), fewer than 7 identities selected, or G1. Preserve the evidence and return to Review.
- **On success:** TB19-REV (mandatory), over the TB19 and TB19A reports together.

## RA-108.6 Sequence and accounting

- **Sequence:** TB19 closeout → TB19A → TB19-REV (mandatory). TB19-REV rules on H-pin on rail carriers (from the three rectangle rows) and on periodic cuts (from TB19A), records the R-route as not reached, and orders the DEFN. Then: [DEFN on the gauge-pin domain and the M1 binding owner → corrective CB/TB] → fixture debt → census → RP-01 Review.
- **Accounting is unchanged:**
  - 66/17/49, debt 1;
  - CP2 491/491;
  - R3 403/497 rejected;
  - TB18 candidate 448/497;
  - selector 497.

  `RP-01` is open, `RP-02` is UNREACHED and Gate C is suspended.
