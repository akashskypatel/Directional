# RA-88 — TB13 reviewed: the RED truth-table row is a Review specification defect; U3 code accepted; CB13A corrects the row (2026-10-18)

**Turn:** `M6-CP3-TB13-R10-OPEN-RAIL-CHAIN-INTERVAL-ROUTE-REV` (RA-89, the CB13A closeout, and RA-90, the TB13A review, are appended; RA-90.4 is amended by RA-91.2 in `Architecture_M6_CP3_TB13C_Census_Review_Decision.md`). **Inputs:** CB13 source `70217cc2bf7d257bebd2969e1aa56b5a43326a70`, package `12130290543`; TB13 run `39112131501`, result `12130683535` (ZIP SHA-256 `43505af2…4885`). **Amends:** RA-87.4.7 (one row). RA-87.3 and RA-87.5 (TB13C) stay live.

## RA-88.1 Re-verification

- The result ZIP hash matches; `SHA256SUMS` has 0 mismatches; 6 executed, 0 missing, 5 RED; postflight true; compile, relink, benchmarks and selector497 all false.
- The harness differs from TB12's only in sha, artifact, digest, the truth-table identity and two output labels.
- #1 has exactly one failure, at P10:7182: `check({{4,7},{1,4}}, nullopt, nullopt, [1,4,7])` returned true and the test expected false. The other eleven rows hold.
- #2 PASS.
- #3/#4: `endpoint-1`, locus 3, front 61/179, `a3ProbeDecodedVertex=4`, contact endpoints `1,7`. This is B2, as RA-87.5 predicted.
- #5/#6: the raw producer-failure line (SHA-256 `142f195a…`) is byte-identical to TB12's. B3 is unchanged, as predicted.
- U3 falsifiers are absent: `open-rail-chain-interval` occurs in no log, and front 29/147 is no longer first.

## RA-88.2 The RED row is wrong, not the helper (owned Review defect)

- RA-85.4 and RA-87.4.1 admit a chain interval in either direction. On chain `[1,4,7]`, route `[4-7, 1-4]` is the reverse walk 7→4→1 (`s=2`, `d=−1`). With no T endpoint it is valid. RA-87.4.7 listed it as a false row, which contradicts RA-87.4.1. TB13's stop was correct.
- Reverse traversal is the intended semantics. A front's orientation (endpoint 0 → 1) is independent of the order the rail builder gives the chain. The existing I–T1 row (`[1-4]`, last T1) already relies on it.
- The row's intent was order sensitivity. The replacement rows below keep that intent with genuine negatives: terminals that contradict the walk direction, and a backtrack. All 15 rows were evaluated against an executable model of RA-87.4.1, with 0 mismatches.
- This is not a weakening. Under the frozen rule the row was false, and the three added rows add discrimination.

## RA-88.3 U3 code accepted; closure waits on the corrected gate

- The helper matches RA-87.4.1, including every bound, `n < 2`, an empty route, and the `|steps| ≥ n` early exit.
- The factory (S:8672-8682) and the consumer (S:20311-20324) call it over the certificate's `oriented_steps()`, keyed by the same rail ID as the contact. In the consumer, the walk is bound to both endpoint carriers beforehand (`endpoint-1-terminal-carrier`, S:20305-20310). The empty-map exemption is gone. The plumbing follows RA-87.4.6, and each negative tampers only its named input.
- **First real-data coverage of the consumer rule:** the consumer visits fronts in ascending order (S:19231), so front 29/147 (I–I, rail 2, edge 1-4) passed the interval check before front 61/179 failed. The factory call still has no real-data coverage, because no open-rail fixture reaches `make`.
- U3 closes when TB13A's truth table passes.

## RA-88.4 CB13A specification — `M6-CP3-CB13A-R10-OPEN-RAIL-CHAIN-INTERVAL-TRUTH-TABLE` (test-only)

In `SurfaceCellAuthorityContractCutover.OpenRailRouteChainIntervalTruthTable` (P10:7152-7187), over chain `[1,4,7]`:

1. Flip `check({{4,7},{1,4}}, nullopt, nullopt, chain)` to `EXPECT_TRUE` (the reverse walk).
2. Add `EXPECT_TRUE(check({{4,7},{1,4}}, t7, t1, chain))` (reverse T–T).
3. Add `EXPECT_FALSE(check({{4,7},{1,4}}, t1, t7, chain))` (the terminals contradict the walk).
4. Add `EXPECT_FALSE(check({{1,4},{1,4}}, nullopt, nullopt, chain))` (a backtrack).

No other row, test or production line changes. GMP/GMPXX compile and package. Record the package ID, ZIP SHA-256 and source SHA, with `runtimeExecution=false`. The CB13A record is 25 lines or fewer.

## RA-88.5 TB13A and TB13C

**TB13A** — `M6-CP3-TB13A-R10-OPEN-RAIL-CHAIN-INTERVAL-TRUTH-TABLE`. Use the TB13 harness, changing only sha, artifact, digest and labels, with the same six identities in the same order. Predictions:

- #1 and #2 PASS;
- #3/#4 `first_failure` byte-identical to TB13 (B2, front 61/179);
- #5/#6 byte-identical to TB13 (B3).

Falsifiers: #1 RED; any #3–#6 change; `open-rail-chain-interval` anywhere. A RED goes to Review (rule 4).

**TB13C** — `M6-CP3-TB13C-R10-SELECTOR-497-CENSUS`, as RA-87.5, but on the **CB13A** package. Run the unchanged harness `m6_cp3_entry_497_artifact_only_harness.sh` (SHA-256 `947a95ee…79dd`), with the candidate given only through its environment inputs. None of its three selectors names a renamed identity. The census adds one falsifier: any RED whose first predicate is `open-rail-chain-interval` means the U3 rule rejects a real route, and goes to Review.

## RA-88.6 Sequence

CB13A → TB13A → TB13C → TB13C-REV (orders U4/U5/U6 and issues DEFN-U6). Each CB follows a reviewed TB.

## RA-89 CB13A accepted; Review completes its closeout; TB13A authorized (2026-10-18)

- CB13A (`M6-CP3-CB13A-R10-OPEN-RAIL-CHAIN-INTERVAL-TRUTH-TABLE`) stopped with STATUS `IN_PROGRESS` after its compile. Only the documentation closeout remained.
- Independent verification:
  - ZIP SHA-256 `36197dffa91b5dbb3a36d589cab314e95e4d7d24e9121617ed17f59256f2b072` (package `12132184878`, run `39117126811`);
  - root manifest 28/28 OK (SHA-256 `bdb4ad988c463f082a1129d17d463da7e3638f24c81396220adb996a328583e1`);
  - source archive SHA-256 `25ec06e748ea29445d50993c0cd0874bb30da7ab030e24a99cff737e70b3e77f`; `source-commit` `e88ac65ffcf87548138d1c56f2cc6ed4a3d8177b`;
  - build exit 0, 8 targets, `DIRECTIONAL_ENABLE_GMP=ON`, gmp/gmpxx linked, `runtimeExecution=false`, all five source-status files empty.
- The packaged P10 test is byte-identical to HEAD. Relative to CB13 (`70217cc2`), `src`, `include` and `tests` differ only by the four RA-88.4 lines. CB13A is accepted, and Review completes the closeout in place, so no semantic work is outstanding.
- **TB13A** runs on this package, as RA-88.5 specifies.
- **TB13C** then uses the same package, through the harness's environment inputs:
  - `CANDIDATE_ARTIFACT_ID=12132184878`;
  - `EXPECTED_SOURCE_SHA=e88ac65f…`;
  - `EXPECTED_CANDIDATE_ZIP_SHA256=36197dff…`;
  - `EXPECTED_ROOT_MANIFEST_SHA256=bdb4ad98…`;
  - `EXPECTED_SOURCE_ARCHIVE_SHA256=25ec06e7…` (full values above).

## RA-90 TB13A reviewed: U3 closed; TB13C feasibility checked and its classification fixed (2026-10-18)

- **RA-90.1 Re-verification.** TB13A was checked independently.
  - Result `12134411966`: ZIP `17decdbf…`, 0 manifest mismatches, 6 executed, 0 missing.
  - Harness `a42ae6e0…` differs from TB13's only in sha, artifact, digest and labels.
  - #1 and #2 PASS. #3–#6 `first_failure` fields compared directly with TB13: byte-identical. `open-rail-chain-interval` occurs in no log.
  - The report's two hashes (`cbf8bbfe…`, `923d41c5…`) cannot be reproduced from the ledger field or the raw line, and their method is unstated. Identity rests on the direct comparison.
- **RA-90.2 U3 closed.** B1 is cleared on the RP-01 fixtures. The consumer rule has real-data coverage; the factory call gains it only once an open-rail fixture reaches `make`, which requires U4–U6.
- **RA-90.3 TB13C can run.**
  - All 497 identities exist at `e88ac65f` in the binary they are routed to: 30 + 12 + 6 in producer, 449 per the routing receipt; 0 missing and 0 parameterized. The harness's exact-one selection gate therefore should not abort.
  - The R3 artifact `11661044443` expires on 2026-10-24, but the baseline is the in-repo `Architecture_M6_CP3_TB1_Entry_R3_Red_Classification.tsv` (SHA-256 `890a105e…`, 94 RED; any other identity was a PASS at R3). The comparison uses that file, not the artifact.
- **RA-90.4 TB13C classification is mechanical, applied to each RED's first `firstPredicate=` text, or its first gtest failure line when there is none:**
  - **B1:** contains `open-rail-chain-interval`. This is a falsifier and goes to Review.
  - **B2:** `predicate=endpoint-0|endpoint-1` with `a3ProbeDecodedVertex=<integer>` and `a3ProbeContactEndpointMember=0` (a rail vertex that is not a terminal; TB13 #3 is the template). *Amended by RA-91.2: B2 also requires `a3ProbeContactPublished=1`.*
  - **B3:** `a2bProbeFirstFailedCondition=not-same-interior-carrier-point` (TB13 #5 is the template).
  - **B2+B3** if both apply; **other** otherwise, grouped by `predicate=` name or by the first 80 characters of the failure line.
- **RA-90.5 TB13C deliverables:**
  - the unchanged harness `947a95ee…`, run with `--execute` and the five RA-89 inputs;
  - `Architecture_M6_CP3_TB13C_Selector_497_Red_Inventory.tsv`, one row per RED with columns `phase, ordinal, identity, owner, exit, raw_sha256, class, first_failure (≤200 chars), R3 (PASS/RED), R3_first_observable`;
  - a report of 30 lines or fewer giving totals per phase (30/12/449/6), counts per class, the R3 PASS → now RED list, the R3 RED → now PASS list, and the TSV's SHA-256.
  - Prediction: `cp3entry` ordinals 2 and 6 are B3. Nothing else is predicted, so no interpretation is needed. Falsifier: any B1.
