# RA-132 — TB27 review: the seam family and both tamper falsifiers pass; census next, before more tests (2026-10-22)

**Turn:** `M6-CP3-TB27-RP01-A7-CERTIFIED-SEAM-CROSS-SHEET-VERIFICATION-REV`.

**Verdict:** TB27 is **accepted** as targeted candidate evidence.
- **Pass:** all 12 seam-family rows, the D3 and D7 tamper falsifiers, and every guard and control. RA-127.4 (iii) and RA-130 B1 are discharged at runtime.
- **Not covered:** three of CB26's new rejection paths are exercised by no test.
- **Sequence realigned:** the selector-497 census (TB28) runs **now**, on the unchanged CB26 package, ahead of the test-only CB27. No promotion until the census and the RP-01 Review.

## RA-132.1 Harvest verified independently

- **Result artifact:** `12420676412` (run 39764327506). The provider digest equals the local ZIP SHA-256 `33dc0878…babb`; it expires 2026-10-29T10:52:14Z.
- **Manifest and execution record:** **24/24** entries check. The record shows source `e3d60337e`, package `12409939859`, 21 planned and executed, 21 PASS, every `*_bad=0`, postflight true, and no compile, relink, benchmark or selector-497 run.
- **Logs:** each of the 21 logs has exactly one `[ RUN ]` and one `[ OK ]`, with no `Failure`, `FAILED` or `SKIPPED`. Each RUN line names the test in its ledger row.
- **Source:** CB26 (`e3d60337e`) is RP +52/−2 and TQ +7/−1. It matches RA-130.8 and RA-131:
  - spans are bound to `relation.id.first/second` (B2);
  - no duplicate check (B3);
  - the evidence must contain the certificate's own transition (B4);
  - the four sites are distinct (B5);
  - the failure-site suffix is added.

## RA-132.2 What the PASS results prove

- **The seam family is 12/12 PASS:** `focused30:6, 20, 24–28`; `selector:444, 446, 448`; `cp3entry:3, 5`. In TB26, nine of them failed in A7.
- **The PASS results are not vacuous.** The D3 test (TQ:3619) and the D7 test (TQ:3983) contain no `return` or `GTEST_SKIP` before their tampers.
  - **D3:** the producer supplied a certified seam relation that A5, A6 and A7 all accept. The quarter-turn face-gauge tamper is rejected as `RelationCertificateConflict`. This discharges RA-127.4 (iii) and shows the D3 guard works on producer data.
  - **D7:** A7 produced geometry for the untampered relation. With the relation-side evidence cleared, it rejected with `UncertifiedCrossSheetBinding`, site `cross-sheet`. This discharges RA-130 B1 and exercises the B4 rejection path.
- **The three A7 site guards still pass**, so the per-member wedge checks are unchanged.

## RA-132.3 Coverage still missing (owed to CB27)

No test asserts the new sites:
- `cross-sheet:seam-direction`;
- `cross-sheet:no-certificate`;
- `cross-sheet:periodic`.

The B4 precision case is also untested: a relation with a *connecting* transition on an unrelated seam must reject. The D7 tamper clears every transition, so it cannot tell B4 apart from the old any-transition rule.

The shared-node predicate's negatives (RA-127.4b) are untested too. Records republished for validation get only structural checks (RP:3708–3756) and never re-enter A5's seam check. But A6 (RP:5878) and A7 (CB26) call the same `certified_seam_direction`, so these cases can be tested there.

## RA-132.4 Realignment: census before more tests

RA-130.9 planned to run the census only after CB27's tests (TB28 = new tests + census). That order is changed, because:
- **No product change remains.** CB27 is test-only, and RP is final for this family. The CB26 package `12409939859` is exactly what the census must measure.
- **Earlier warning.** CB25 and CB26 changed admission in A5 and A7 for every certified seam. A regression from PASS to RED among TB21's 449 PASS rows is the risk that matters most. It should be measured before anything else is built on top.
- **Smaller turns.** The census needs no build, and the new tests then need only a targeted run.

**New order:** TB28 (census) → TB28-REV → CB27 (negative tests) → CB27-REV → TB29 (new tests plus guards) → TB29-REV.

## RA-132.5 Successor `M6-CP3-TB28-RP01-SELECTOR-497-CENSUS` (artifact-only Test + Benchmark)

- **Input:** the immutable CB26 package `12409939859` (source `e3d60337e`), run unchanged with the existing harness `m6_cp3_entry_497_artifact_only_harness.sh` (SHA-256 `947a95ee…79dd`) through `agent-test-benchmark-reusable.yml`, with `CANDIDATE_ARTIFACT_ID=12409939859`. The selector is byte-frozen (selector-449 SHA-256 `d4a0d1b7…6414`).
- **Harness inputs** (this Review re-derived them from the package):
  - `EXPECTED_SOURCE_SHA=e3d60337ed34538547d3a6d519bafae5b184330e`;
  - `EXPECTED_CANDIDATE_ZIP_SHA256=ee08279e537af4e99f287d28595df0ef639e632aa345bc0b1986bbb361ee86fa`;
  - `EXPECTED_ROOT_MANIFEST_SHA256=0c9183b848e4b13afae4c0b84c23ddd18f0f1526ccdcf4d4da688dc893e8b1cf` (28 entries);
  - `EXPECTED_SOURCE_ARCHIVE_SHA256=d37cfbdab24b92aad6ab2ecfd135d92702c0874f9c69a0164bf578705d78955c`.

  Inside the packaged source, focused-30, focused-12, selector-449 and the routing receipt match the harness's built-in hashes. The package expires 2026-10-29T08:00:15Z, so TB28 must run before then.
- **Report:**
  - all 497 rows: identity, verdict, exit, first failure, log hash;
  - a row-by-row diff against TB21 (`Architecture_M6_CP3_TB21_Selector_497_Red_Inventory.tsv`, 48 RED): every PASS→RED and every RED→PASS;
  - the new inventory `Architecture_M6_CP3_TB28_Selector_497_Red_Inventory.tsv`, with the same columns as TB21 plus a TB21 column;
  - the A7 site for every `UncertifiedCrossSheetBinding`.
- **Predictions:**
  - the 12 seam-family rows go RED→PASS;
  - `selector:447` (RED in TB21, PASS since TB25) is PASS;
  - **no TB21 PASS row becomes RED**;
  - so at least **462/497**.
  - The other 35 TB21 RED rows are measured and classified, not assumed: M1 (`focused30:12`, `cp3entry:2` and the M1 selector rows), D2 `cp3entry:1`, and fixture debt.
- **Falsifiers and STOP rules:**
  - any PASS→RED;
  - any `cross-sheet:seam-direction` or `cross-sheet:periodic` site (`periodic` routes under RA-130.7);
  - a seam-family row RED;
  - a manifest, package or selector hash mismatch.

  Report and stop; no fixing. A change to the harness is allowed only to repair extraction mechanics, and must be recorded.
- **Out of scope:** any source, test, fixture, selector or workflow semantics; compile, relink or benchmarks; promotion.

## RA-132.6 CB27 scope (issued at TB28-REV; test-only, TQ)

Use the D7 fixture: tamper the A5 records, republish them, and run A7 against the original A6 product (as at TQ:4027–4055). Assert the exact A7 site for each case, plus the A6 code the author derives:

1. **Unrelated seam:** move the certificate transition to a different seam that joins the same sheets → `cross-sheet` (the B4 precision case).
2. **No certificate:** clear the relation's certificate → `cross-sheet:no-certificate`.
3. **RA-127.4b (A1):** change one endpoint's lattice coordinate → `cross-sheet:seam-direction`.
4. **RA-127.4b:** span binding outside its wedge → `cross-sheet:seam-direction`.
5. **RA-127.4b same-side:** only if it can be built without tripping the per-member wedge check first. Otherwise, record which check covers it.

Periodic is not constructible from producer data; it stays under RA-130.7.

## RA-132.7 Sequence and accounting

- **Sequence:** TB27-REV (this) → **TB28 (census)** → TB28-REV → CB27 → CB27-REV → TB29 → TB29-REV → DEFN-M1 → corrective CB/TB → DEFN-T1 → fixture debt → census → RP-01 Review. `DEFN-SEAM-NZ` and the Periodic follow-up each wait for a witness. `DIAG-RETAIN` is scheduled clear of RP-01 turns.
- **Accounting (unchanged):** stable 66/17/49, debt 1, CP2 491/491; R3 403/497 rejected; TB21 449/497 candidate; selector 497 frozen. `RP-01` open, `RP-02` UNREACHED, Gate C suspended.

| Duty | Answer |
|---|---|
| Decisive claims re-derived | ZIP digest; 24/24 manifest; CB26 package digest, root manifest, source archive and the four packaged gate-file hashes; 21 logs (RUN, OK, test name); CB26 diff against RA-130.8; no early exit in the D3/D7 bodies; validation-path scope (RP:3708–3756); site coverage in TQ; harness extraction and selector checks |
| Non-vacuity | D3 and D7 tampers reached and rejected; untested paths listed for CB27 |
| Obligations | RA-127.4 (iii) and RA-130 B1 discharged; RA-127.4b and B4/B5 negatives carried to CB27; RA-130.7 carried |
| Durable docs | Handoff, TODO, tracker, CHANGELOG, ORIENTATION, ROADMAP, Frozen Definitions index |
| Boundary | Review-only; no source, test, selector, workflow or runtime change |
