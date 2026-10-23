# RA-140 — Audit of the RP02 harness review: acceptance upheld and validated on real GoogleTest logs; TB29 released with complete inputs (2026-10-23)

**Turn:** `M6-CP3-TB29H-RP02-TARGETED-ARTIFACT-HARNESS-CORRECTION-REV-AUDIT` (independent audit of the RP02 review, `Architecture_M6_CP3_TB29H_RP02_Harness_Correction_Review_Decision_20261023.md`).

**Verdict:**
- **Upheld:** the RP02 review's acceptance of the corrected harness (SHA-256 `436f5fff…c9a`) and its release of TB29.
- **Gap closed:** that review's acceptance of H1 and H6 rested on **synthetic** logs only. This audit runs the harness's exact functions over **real** GoogleTest logs from TB28 and TB27. The 600-second kill path (H4) is still verified by reading the code, not by a run; TB29 itself would reveal a timeout as INVALID.
- **Inputs completed:** the TB29 inputs had no root-manifest or source-archive hash. Both are derived from the package here.
- **No defect requires another harness turn.**

## RA-140.1 Reproduced

- Harness SHA-256 `436f5fff9c3bec97457f4bc6b7c2b6182cb3f47707eb14a66af3b6a3f3dc3c9a` matches.
- `bash -n` passes; `--self-test` prints `SELF_TEST_PASS cases=12`.
- `--self-check Architecture_M6_CP3_TB29_Targeted_Case_Manifest.tsv 44` prints `SELF_CHECK_PASS cases=44`.
- Every RA-139 point is present in the code:
  - **H1:** `classify_case` gives RED only for one RUN, the unadorned `[  FAILED  ] <test>` line and exit 1;
  - **H2:** `read_cases` enforces `EXPECTED_CASE_COUNT`;
  - **H3:** the A5 pattern keeps hyphens;
  - **H4:** `Popen(start_new_session=True)`, `killpg`, then reap;
  - **H5:** `time -o resources/<row>.time.txt`;
  - **H6:** `failure_block` scoping.

## RA-140.2 Real-log validation (new evidence)

The classifier and extractors, taken verbatim from the harness, were run on archived logs:

| Input | Expected | Observed |
|---|---|---|
| TB28 result `12424484672`: the 35 RED logs, with their recorded exit codes | RED | **35/35 RED**; a first failure line found in 35/35 |
| TB27 result `12420676412`: the 21 PASS logs | PASS | **21/21 PASS** |

This matters because the RED rule depends on GoogleTest's unadorned summary line `[  FAILED  ] Suite.Test`; the per-test line carries a `(N ms)` suffix. Real logs confirm the binaries print it. If they did not, every TB29 RED would be INVALID and the run would fail outright.

## RA-140.3 TB29 inputs (complete; derived from package `12465330920`)

| Input | Value |
|---|---|
| `CANDIDATE_ARTIFACT_ID` | `12465330920` (expires **2026-10-29T22:54:39Z**) |
| `EXPECTED_SOURCE_SHA` | `4473e41e94a35f1bf189fa046e86bac92c7391fb` (`metadata/source-commit.txt` matches) |
| `EXPECTED_CANDIDATE_ZIP_SHA256` | `da56650a18f99443abf5f721620bb00fd5701dd1e660741da9aafb924a6dfbf5` |
| `EXPECTED_ROOT_MANIFEST_SHA256` | `e6149577b0bb240efadd4bc47638ffd3b1441d6f99664542fa66b368df35454b` (28 entries) |
| `EXPECTED_SOURCE_ARCHIVE_SHA256` | `d06d8484b98ffedfb38d99ebf38deee960d170e7d7fa3011f51453249e61371e` (matches its manifest entry) |
| `CASE_MANIFEST` | `.agents/Directional/Architecture_M6_CP3_TB29_Targeted_Case_Manifest.tsv` |
| `CASE_MANIFEST_SHA256` | `39fa5eb83e2da1b0668bc7368c5304011ec13de8804c54a2a3466f927c42d236` |
| `EXPECTED_CASE_COUNT` | `44` |
| Harness | `.agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh`, SHA-256 `436f5fff9c3bec97457f4bc6b7c2b6182cb3f47707eb14a66af3b6a3f3dc3c9a` |

**TB29 deliverables:**
- the immutable result artifact with a verified `SHA256SUMS`;
- a report, `Architecture_M6_CP3_TB29_Typed_Factory_Cause_Harvest_Report_20261023.md`, containing:
  - all 44 verdicts;
  - the 9 controls PASS;
  - every RED's `typed_reason` and first failure;
  - an attribution table of the 35 REDs by first failing component and typed reason, with counts summing to 35;
  - any `unexpected_pass` or `INVALID` row, listed explicitly.

## RA-140.4 What TB29-REV must decide (pre-registered)

1. **M1's measured scope.** Group the factory rows (`focused30:3, 22, 23`; `selector:139, 140, 142, 211, 219, 220, 221, 296, 302, 304, 439`; `cp3entry:4`) by factory code and `sourceAuthoritySite`. DEFN-M1 covers exactly the rows whose clause is RA-105.3's R2 certificate binding. Rows rejected by another clause get their own owner.
2. **A3 periodic route** (`selector:189–195`): the atlas code and locus decide between fixture debt and a product owner.
3. **`focused30:12`:** the A5 code and site.
4. **The rest stay as RA-134.2 classified them,** unless new text contradicts that.

## RA-140.5 Sequence and accounting

- **Sequence:** audit (this) → **TB29** → TB29-REV → DEFN-M1 (evidence-scoped) → DEFN-M1-REV → corrective CB/TB → DEFN-T1 → fixture debt → census (needs an RA-139.3-compliant harness, RA-139.5) → RP-01 Review. If package `12465330920` lapses before TB29 runs, Review issues a recompile-only CB of `4473e41e9`. `DEFN-SEAM-NZ` and the Periodic follow-up each wait for a witness. `DIAG-RETAIN` is scheduled clear of RP-01 turns.
- **Accounting (unchanged):** stable 66/17/49, debt 1, CP2 491/491; R3 403/497 rejected; TB28 462/497 candidate; selector 497 frozen. `RP-01` open, `RP-02` UNREACHED, Gate C suspended.

| Duty | Answer |
|---|---|
| Decisive claims re-derived | Harness SHA; `bash -n`, self-test, self-check; H1–H6 in code; the classifier and extractors run over 35 real RED and 21 real PASS logs; package ZIP, root manifest, source archive and source commit |
| Non-vacuity | The real-log run closes the synthetic-only limit for H1/H6; H4 remains static |
| Obligations | RA-139 discharged; RA-139.5 (census harness) carried; TB29-REV decisions pre-registered |
| Durable docs | Handoff, TODO, tracker, CHANGELOG, ORIENTATION, Frozen Definitions index |
| Boundary | Review-only; no source, test, harness, manifest, selector, workflow or Directional runtime change |
