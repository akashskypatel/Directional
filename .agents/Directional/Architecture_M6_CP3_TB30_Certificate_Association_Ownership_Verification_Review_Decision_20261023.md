# RA-144 — TB30 review: M1 resolved (10/10) on the targeted gate; full census before any further fix (2026-10-23)

**Turn:** `M6-CP3-TB30-RP01-CERTIFICATE-ASSOCIATION-OWNERSHIP-VERIFICATION-REV`.

**Verdict:** TB30 is **accepted** as targeted candidate evidence. All pre-registered RA-143.4 predictions held:
- the 10 M1 rows now PASS;
- the 7 non-M1 factory rows are unchanged, with the same typed sites;
- the 9 TB29 controls and the 3 certificate-authenticity guards PASS.

CB29 matches RA-143.3 exactly. It still needs a census: the change alters A4's admission for **every** hard-rail certificate, and TB30 measured only 29 identities. The next turn is the **selector-497 census**, run on the CB29 package with the crash-safe targeted harness and a Review-owned 497-row manifest (discharging RA-139.5). No further product turn starts before it.

## RA-144.1 Verified

- **CB29** `2602e7398` (SCT only): it removes exactly the five association predicates (both `oppositeEdge`, both `railId`, both route comparisons, the region inequality), keeps both `HardRail` kind checks, and adds the RA-15/RA-16 §5/RA-143 comment.
- **Package `12492950387`:**
  - ZIP SHA-256 `9e2da1f4…9167319`, digest re-hashed;
  - root manifest `5f7259b7ec0f420c8d161973f450e99e76684b0643c8e21074d192931747320d` (28 entries);
  - source archive `e5ec539063d7bf6dfbe06b1552c081d117e052f8090a58aaa6ac754242e8f53a` (matches its manifest entry);
  - source commit `2602e7398cdc6f1281abe11a758de35166b6590c`;
  - **expires 2026-10-30T09:34:32Z.**
- **TB30 result `12500088095`:** digest equals the local ZIP SHA-256 `bba928eb…308bf`. **61/61** checksums pass. The run shows 29 planned and executed, 22 PASS, 7 RED, and missing, skipped, duplicate, `control_bad` and `unexpected_pass` all 0. Postflight true, exit 0, and no compile, relink or configure. By kind:
  - GUARD 6 PASS;
  - NEGATIVE 4 PASS;
  - POSITIVE 12 PASS (10 M1 and D3/D7);
  - RED 7 RED.
- **RA-142.2's static claim is confirmed:** `selector:211/219/227/230` now PASS, so they did share the R2 clause.

## RA-144.2 Remaining RED set (25; owners carried)

| Group | Rows | Owner (next definition or diagnostic) |
|---|---|---|
| Factory `face-gauge-missing` | `selector:220, 221, 296, 302, 304, 439` | The direct periodic-owner fixture (TQ:≈358) passes no face gauges. A DEFN decides between fixture debt and the factory contract. |
| Factory `open-rail-chain` | `cp3entry:4` | A4 open-rail-chain owner |
| A3 `CycleTransportMismatch` | `selector:189–195` | A3 cycle-locus diagnostic first: the code has two source sites and no locus (RA-141.2) |
| A3 `SingularityMismatch` (2,3) | `selector:442` | A3 singularity/fixture review |
| A5 `OccurrenceHardRailTransportMismatch` | `focused30:12` | A5 relabelling/transport owner |
| Witness absence | `cp3entry:1` (D2 odd gauge), `cp3entry:2` (midline certificate) | DEFN-T1 / witness owners |
| Producer disposition or oracle, untyped | `selector:174, 201, 204, 242, 247, 250, 405` | Per-row first-failure classification; RA-92.3/93.3 fixture debt covers 174, 242, 250 |

## RA-144.3 Successor `M6-CP3-TB31-RP01-SELECTOR-497-CENSUS` (artifact-only Test + Benchmark)

- **Why a census now:** RA-139.5 bars the old census harness, because it counts crashes as RED. The reviewed targeted harness (`436f5fff…c9a`, RA-139.3 classifier, validated on real logs in RA-140) runs any Review-owned manifest.
- **Manifest (Review-owned, this turn):** `Architecture_M6_CP3_TB31_Census_Case_Manifest.tsv`, SHA-256 **`b1c135d429f8c659e190f648b8678669cb7c14d393e0db9069568ea3838aa43e`**, 497 rows.
  - **Derivation:** generated from TB28's `combined-ledger.tsv` (SHA-256 `bbac8649…6ec5`, inside result `12424484672`, digest re-verified), which the frozen-selector harness itself produced from the frozen 30 + 12 + 449 + 6 selector. Every phase:ordinal identity, test name and owning binary is copied in TB28's order.
  - **Kinds:** `GUARD` for the 472 rows expected to PASS (TB28's PASS rows plus the 10 M1 rows); `RED` for the 25 in RA-144.2.
  - **Checks:** 497 unique tests across 4 binaries; `--self-check … 497` passes.
  - **GMP preflight:** all four binaries list `libgmp.so.10` in their ELF `DT_NEEDED`.
- **Harness inputs:**
  - `CANDIDATE_ARTIFACT_ID=12492950387`;
  - `EXPECTED_SOURCE_SHA=2602e7398cdc6f1281abe11a758de35166b6590c`;
  - `EXPECTED_CANDIDATE_ZIP_SHA256=9e2da1f4b5cf95ac45364e8c428f0bd9116dcfe96772de18d02a5a7bfb167319`;
  - `EXPECTED_ROOT_MANIFEST_SHA256=5f7259b7…320d`;
  - `EXPECTED_SOURCE_ARCHIVE_SHA256=e5ec5390…f53a`;
  - `CASE_MANIFEST=.agents/Directional/Architecture_M6_CP3_TB31_Census_Case_Manifest.tsv`;
  - `CASE_MANIFEST_SHA256=b1c135d4…aa43e`;
  - `EXPECTED_CASE_COUNT=497`.
- **Prediction:** **472/497**, with exactly the 25 RA-144.2 rows RED and zero regressions from PASS to RED.
- **Reading the gates:**
  - `control_bad > 0` means a measured regression (harness exit non-zero after evidence is published): report it, don't fix it;
  - `unexpected_pass` means a RED row recovered: report it;
  - any `INVALID` row is a harness or run fault: STOP.
- **Report:** `Architecture_M6_CP3_TB31_Selector_497_Census_Report_20261023.md`, with totals, every row diff against TB28, every RED's typed reason, and a new RED inventory TSV.
- **Not promotion:** acceptance stays with the RP-01 Review.

## RA-144.4 Sequence and accounting

- **Sequence:** TB30-REV (this) → **TB31 (census)** → TB31-REV → per-owner turns, each DEFN or diagnostic first and ordered by row count and independence:
  1. face-gauge-missing (6);
  2. A3 cycle locus (7, diagnostic);
  3. untyped producer/oracle rows (7);
  4. A5 `focused30:12`;
  5. `cp3entry:4`;
  6. `selector:442`;
  7. DEFN-T1 (`cp3entry:1/2`).

  → census → RP-01 Review. `DEFN-SEAM-NZ` and the Periodic follow-up each wait for a witness. `DIAG-RETAIN` is scheduled clear of RP-01 turns.
- **Accounting (unchanged):** stable 66/17/49, debt 1, CP2 491/491; R3 403/497 rejected; TB28 462/497 candidate (TB31 may supersede it as a candidate); selector 497 frozen. `RP-01` open, `RP-02` UNREACHED, Gate C suspended.

| Duty | Answer |
|---|---|
| Decisive claims re-derived | CB29 diff; package digest, root manifest, source archive, source commit, expiry; TB30 digest, 61/61, boundary state, verdicts by kind; 497-row manifest built from a verified source, self-checked; `DT_NEEDED` of four binaries |
| Non-vacuity | M1 flips measured; the census gates every expected PASS as a control |
| Obligations | RA-143.4 discharged; RA-139.5 discharged by the TB31 harness choice; remaining 25 carried with owners |
| Durable docs | Handoff, TODO, tracker, CHANGELOG, ORIENTATION, Frozen Definitions index |
| Boundary | Review-only; adds a Review-owned data manifest; no source, test, harness, selector, workflow or runtime change |
