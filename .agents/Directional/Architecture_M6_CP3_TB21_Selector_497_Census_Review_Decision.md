# RA-115 — TB21 reviewed: CB20/CB20A regression-free on the 497 selector; torus rows reclassified as a fixture-scope defect; CB21 next (2026-10-21)

**Turn:** `M6-CP3-TB21-RP01-SELECTOR-497-CENSUS-REV`. **Input:** TB21 run [39533914719](https://github.com/akashskypatel/Directional/actions/runs/39533914719) (dispatch `b9c659531`), census harness `m6_cp3_entry_497_artifact_only_harness.sh` (SHA-256 `947a95ee…79dd`, byte-identical at the executor). The agent left TB21 `IN_PROGRESS` after dispatch and wrote no inventory or report. As in RA-113 and RA-114, this decision holds the verified harvest; the RA-114.5 census report is absorbed into RA-115.1. **Lines:** TQ = `tests/SurfaceCellTransitionQuotientTests.cpp` at `e22c5da5f` (HEAD `src`, `include`, `tests` identical).

## RA-115.1 Harvest verified

- **Result artifact:** `12317287104`, ZIP SHA-256 `12279a26fbe8d2f9d2c4bae6b0317b46b9fb6480212127a59e415fb46f089c8d`, expires 2026-11-04T02:46:55Z. `combined-ledger.tsv` SHA-256 `d4e3d6e5…57f9`, `red-ledger.tsv` `b0f75e2f…5d25`.
- **Integrity:** 1019/1019 result hashes verify; candidate `12310848591` downloaded digest equals `0c9f048e…3ff5`; 497/497 executed, `orchestration_failure=false`, `selection_integrity=true`; postflight package/source/view census equal, all selectors and routing unchanged, manifest 28/28.

| Phase | Total | PASS | RED | TB18 RED |
|---|---:|---:|---:|---:|
| focused30 | 30 | 19 | 11 | 11 |
| focused12 | 12 | 12 | 0 | 0 |
| selector449 | 449 | 417 | 32 | 32 |
| cp3entry | 6 | 1 | 5 | 6 |
| **Total** | **497** | **449** | **48** | **49** |

- **PASS→RED:** none. **RED→PASS:** `cp3entry:6` `M6CP3.HardRailCrossRegionBindingDoesNotCompareGlobalSheetLabels`.
- **First failures against TB18** (all 48 REDs): 24 unchanged; 15 are pure TQ line shifts (each mapped line `3bd24682c`→`e22c5da5f` verified identical); `selector:405` differs only because TB18 recorded the predicate line instead of P10:6975, and its predicate is unchanged; the other 8 are the M2 rows, and each is byte-identical to its TB20 first failure (pointer values aside).
- **Inventory:** `Architecture_M6_CP3_TB21_Selector_497_Red_Inventory.tsv`, 48 rows, SHA-256 `6eb5022a5179ab33ed50e73b3b4cb4094076953667344a3daa767ff997d87c34`. It replaces the TB18 inventory as the census baseline.

## RA-115.2 Predictions adjudicated

- 0 PASS→RED, `cp3entry:6` RED→PASS, 449 ≥ 449 PASS, the eight M2 rows keep their TB20 failures: **all observed**.
- No log contains `gauge-pin` or `gauge-pin-span`. One log, `selector:250` (curved-disk fixture debt, RED since TB16C, same P10:3598 assertion), prints a `PublishedProductRejected` disposition without a site; it is not a status change, and its site is not readable from the log.
- **Verdict:** CB20/CB20A is regression-free on the frozen 497 selector. TB21 (449/497, 0 PASS→RED) replaces TB18 (448/497) as the candidate evidence. Acceptance and accounting stay with the RP-01 Review.

## RA-115.3 Torus rows reclassified (amends RA-114.3)

- **The filter is D2, not a proxy.** TQ:1697 implements D2 / RA-33.2 (`Architecture_M6_DEFN_R5_R1_CP3_Entry_Recovery_Definition_Record.md` §D2; `Architecture_M6_DEFN_R5_R2_Review_Record.md`): retain only reciprocal source/A3 witnesses with `(F_b−F_a) mod 4 ∈ {1,3}`, so the identity discriminates relation authority from face gauges. The R2 Review adds: "if absent STOP", and "No synthesized record, loosened test precondition, or selector mutation is authorized." RA-114.3's reading as "a test-side proxy for odd A3 transport" is withdrawn.
- **Scope defect.** Only `cp3entry:1` needs D2, and it asserts it itself at TQ:2802. The six other consumers of `nonzero_z4_torus_witness_fixture()` (`focused30:6/12/20/24`, `selector:446/447`; calls at TQ:8318, 5144, 5800, 6157, 8205, 8368) exist at CP2 `5ce3132ec`, where the fixture took the first source/A3 candidate and all six were GREEN in 491/491. `88aa8eae0` put D2's selection into the shared fixture, so every consumer inherits D2's STOP (LESSONS §2 **A fixture change reaches every fixture built from it**).
- **H-T2 has no support.** Every recorded enumeration (R3, `Architecture_M6_CP3_TB1_Entry_R3_Independent_Review_Record.md`; TB20; TB21) reads `sourceFaceGaugePairs=5; oddFaceGaugePairs=0`, and D2 itself never established that an odd pair exists. No producer gauge contract is shown to have been lost.
- **Unmeasured predicates.** The reciprocal-tracer and holonomy checks run only after the odd filter, so `reciprocalTracerPairs=0` says nothing about the five even candidates (LESSONS §2 **A failure hidden behind an earlier one is unmeasured**).
- **Consequence.** The correction is test-only: return D2 to `cp3entry:1` and measure every predicate on every candidate (RA-115.5). D2 is not loosened. Whether an organic odd pair is attainable on this torus under RA-111.3 becomes DEFN-T1, after TB22 publishes the unmasked receipt.

## RA-115.4 Unchanged

- M1 (10 identities, RA-105.3), `cp3entry:2` and `focused30:12` keep their TB20 failures and go to the M1 DEFN.
- Frozen: 66/17/49, debt 1, CP2 491/491, R3 403/497 rejected, selector 497. `RP-01` open, `RP-02` UNREACHED, Gate C suspended.

## RA-115.5 Next unit — `M6-CP3-CB21-RP01-TORUS-WITNESS-SCOPE` (Code + Build, test-only)

**Objective:** confine D2's odd-gauge selection to the identity that requires it, and make each witness predicate measurable on every candidate. TQ only.

1. **Predicates.** In `make_nonzero_z4_torus_witness_fixture` (selection loop TQ:1687–1744), evaluate for every candidate, independently and without an early `continue` on the gauge delta: gauge presence (both face indices in range), `delta`, the reciprocal tracer pair (unchanged forward/reverse `PeriodicCut` test), and the holonomy match (unchanged stored-relation, semantic-action and cut-route test).
2. **Selection.** The first candidate in enumeration order that passes every non-gauge predicate with `delta ∈ {1,3}`; if there is none, the first that passes every non-gauge predicate. Throw only when no candidate passes every non-gauge predicate.
3. **Receipt.** A string with `sourceA3Candidates`, `sourceFaceGaugePairs`, `oddFaceGaugePairs`, `reciprocalTracerPairs`, `holonomyMatchedPairs`, `publishedPeriodicHolonomies`, `nonzeroHardCarriers`, each counted over all candidates; then one `c<i>=<carrier>:delta=<d>;recip=<0|1>;holo=<0|1>` entry per candidate; then `selected=c<i>` or `selected=none`. Append it to the throw message, whose text drops "and odd selected-face gauge delta".
4. **Fixture member.** Add `std::string selectionReceipt` as the last member of `ProducedTorusWitnessFixture` (TQ:903) and fill it in the return at TQ:1771.
5. **D2 identity.** In `cp3entry:1` keep the TQ:2802 assertion and its message unchanged, and append `<< " receipt=" << fixture.selectionReceipt`. Nothing else in the test changes.
6. **Compile.** Eight-target GMP/GMPXX compile as for CB20A; `runtimeExecution=false`.

**Out of scope:** `src`/`include`; any other test or helper, including `enumerate_torus_source_witnesses` and `produced_semantic_relation_for_witness`; D2's requirement; selectors, harnesses, workflows; any runtime; DEFN-T1; M1.

**Record:** `Architecture_M6_CP3_CB21_Torus_Witness_Scope_Code_Build_Record_20261021.md` (≤ 30 lines): source SHA, diff stat, compile run, package id, ZIP digest, hash count, expiry, root-manifest and source-archive SHA-256.

**STOP and return to Review** on a compile failure, or any need to touch `src`/`include` or another test. No repair inside the turn.

**TB22 predictions (to be set in CB21-REV):** P1 — the fixture selects a candidate, and `focused30:6/20/24`, `selector:446/447` reach their own assertions (CP2 expects PASS). P2 — `cp3entry:1` fails at its D2 assertion with `oddFaceGaugePairs=0` in the receipt. P3 — `focused30:12` keeps its A5 failure. **Falsifier:** the fixture throws with `reciprocalTracerPairs=0` or `holonomyMatchedPairs=0`; the blocker is then periodic publication, not the filter, and returns to Review.

## RA-115.6 Sequence and accounting

- **Sequence:** TB21 → TB21-REV (RA-115) → **CB21** → CB21-REV → TB22 (the seven torus consumers, `cp3entry:6`, three controls) → TB22-REV → DEFN-T1 (D2 attainability on the torus under RA-111.3, from the TB22 receipt) → DEFN-M1 (M1 binding owner, RA-105.3; also `cp3entry:2`, `focused30:12`) → corrective CB/TB → fixture debt → census → RP-01 Review.
- **Accounting:** candidate evidence TB21 449/497 (was TB18 448/497); everything else as RA-115.4.

> *Closed by RA-116 (2026-10-21): CB21 accepted statically; TB22 authorized. TB22 reviewed by RA-117.*
