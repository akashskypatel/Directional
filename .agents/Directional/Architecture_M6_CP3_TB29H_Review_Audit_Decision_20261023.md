# RA-139 — Audit of the TB29H review (RA-138): H1–H3 upheld; three further harness defects; built-in self-test required; census harness shares H1 (2026-10-23)

**Turn:** `M6-CP3-TB29H-RP01-TARGETED-ARTIFACT-HARNESS-REV-AUDIT` (independent audit of RA-138).

**Verdict:**
- **Upheld:** RA-138's three findings and its hold on TB29.
- **Amended:** the correction turn `M6-CP3-TB29H-RP02-TARGETED-ARTIFACT-HARNESS-CORRECTION` gains three defects (H4–H6). Its "static synthetic probes" become a **built-in `--self-test` mode**, so every later review can re-run them on the exact harness bytes.
- **Carried:** RA-138 did not record that the 497 census harness has the same RED/INVALID conflation as H1.

## RA-139.1 Re-verified

- **Hashes:** harness `be3db020…b412` and manifest `39fa5eb8…d236` match.
- **H1** (lines 217–218): any non-zero exit with one `[ RUN ]` and no `[ OK ]` is classified `RED`. A crash, kill or timeout after RUN is therefore accepted as a test failure. Confirmed.
- **H2** (lines 47–68): `read_cases` enforces no expected count. Confirmed. At execute time the SHA input pins the bytes; the `--self-check` mode has no such pin.
- **H3** (line 110): `A5:[A-Za-z][A-Za-z0-9_]*` truncates the helper's hyphenated causes, such as `A5:no-produced-certified-ordinary-seam` (TQ:2810–2827). Confirmed.
- **The GMP preflight is sound.** Lines 191–193 require `libgmp` for every manifest binary. Both binaries in the CB28A package (`12465330920`, ZIP `da56650a…dfbf5` re-hashed) list `libgmp.so.10` in their ELF `DT_NEEDED` (authority kernel: `libgmp`; producer: `libgmpxx`, `libgmp`). No change needed.
- **Extractor on real data.** I ran it over the 35 TB28 RED logs: `selector:442` → `code=SingularityMismatch;sourceEdge=(2,3)`, the other 34 → `reason-not-observed`. No match came from text before the failure line. TB28's logs predate CB28's messages, so this bounds the H6 risk; it does not refute it.

## RA-139.2 Further defects (binding on RP02)

- **H4 (high) — a timeout leaves the test running.**
  - Line 206 runs `/usr/bin/time … <binary>` with `timeout=600`. On expiry, `subprocess.run` kills only its direct child, `time`. The test binary, a grandchild, keeps running with the log file still open.
  - That process can append to `raw/<row>.log` after line 228 has hashed it, so the ledger's `log_sha256` and the final `SHA256SUMS` disagree. It also competes for CPU with later cases, causing further timeouts.
  - **Required:** start each case in its own process group (`start_new_session=True`). On timeout, `os.killpg(…, SIGKILL)` and reap it before the log is read. The case is then `INVALID` (H1).
- **H5 (low) — timing output is mixed into the test log.**
  - `/usr/bin/time -v` without `-o` merges its resource report into the test log. The 497 harness writes it to a separate file (`-o`, lines 299–301).
  - This makes TB29's raw logs differ in content from TB28's, which TB29-REV must compare, and it puts the full command line into the text the extractors scan.
  - **Required:** `-o resources/<row>.time.txt`, with that file listed in `SHA256SUMS`.
- **H6 (medium) — reasons are read from the whole log.**
  - `typed_reason` and `first_failure` scan the entire log, so text printed before the failure can be reported as its cause.
  - **Required:** extract both from the **first failure block only**: from the first `: Failure` or `unknown file: Failure` line up to the next `[  FAILED  ]` line, or end of file. Record `reason-not-observed` if that block has no typed reason.

## RA-139.3 H1 classification rule (made precise)

| Verdict | Condition |
|---|---|
| `PASS` | exit 0, exactly one `[ RUN ]` and one `[       OK ] <test>`, no SKIPPED, no FAILED |
| `RED` | exactly one `[ RUN ]`, exactly one `[  FAILED  ] <test>` terminal line naming the same test, no OK or SKIPPED, exit 1 |
| `INVALID` | anything else: timeout, signal or crash (no FAILED line), zero or several RUN, a skip, or a mismatched name |

An `INVALID` row counts as missing, so the harness exits non-zero after publishing evidence (existing gate, line 235).

## RA-139.4 Built-in `--self-test` (replaces ad-hoc probes)

A `--self-test` mode feeds **embedded synthetic logs** through the same classifier and extractor functions used in execution, and exits 0 only if every expectation holds. Minimum cases:

1. genuine PASS → `PASS`;
2. genuine failure with a `[  FAILED  ]` terminal → `RED`;
3. RUN then crash, no terminal → `INVALID`;
4. RUN then the timeout marker → `INVALID`;
5. a SKIPPED test → `INVALID`;
6. zero RUN → `INVALID`;
7. a factory reason in the failure block → `code=<int>;sourceAuthoritySite=…`;
8. an atlas reason → `code=<Name>;sourceEdge=(a,b)`;
9. `A5:InvalidX;site=…`, retained whole;
10. `A5:no-produced-certified-ordinary-seam`, retained whole (H3);
11. a `site=` line **before** the failure plus a factory reason inside it → the failure-block reason (H6);
12. a failure block with no typed text → `reason-not-observed`.

**Count gate (H2):** `--self-check <manifest> <expected-count>` and an execute-time `EXPECTED_CASE_COUNT` input (allowed by the workflow's key rules). It must reject a 1-row and a 43-row copy of the manifest when 44 is expected.

## RA-139.5 Carried obligation — census harness

`m6_cp3_entry_497_artifact_only_harness.sh` (SHA-256 `947a95ee…79dd`) sets `result=RED` unless the run is a PASS (lines 311–312), so it has the same H1 defect. TB28's 35 REDs are unaffected: every one of them has a GoogleTest failure line. The **next census** must use a harness with the RA-139.3 rule: either the corrected targeted harness with a 497-row manifest, or a separately reviewed fix of the census harness. That decision is due at the Review that schedules the next census.

## RA-139.6 Sequence and accounting

- **Sequence:** audit (this) → **TB29H-RP02** (H1–H6, `--self-test`, count gate) → RP02-REV (re-runs `bash -n`, `py_compile`, `--self-check` and `--self-test` on the new SHA) → TB29 (resumed) → TB29-REV → DEFN-M1 → DEFN-M1-REV → corrective CB/TB → DEFN-T1 → fixture debt → census (RA-139.5) → RP-01 Review. `DEFN-SEAM-NZ` and the Periodic follow-up each wait for a witness. `DIAG-RETAIN` is scheduled clear of RP-01 turns.
- **Expiry contingency:** the CB28A package expires **2026-10-29T22:54:39Z**. If TB29 cannot start before then, the next Review issues a recompile-only CB of source `4473e41e9` (no source change) and updates the TB29 inputs. The manifest is unaffected.
- **Accounting (unchanged):** stable 66/17/49, debt 1, CP2 491/491; R3 403/497 rejected; TB28 462/497 candidate; selector 497 frozen. `RP-01` open, `RP-02` UNREACHED, Gate C suspended.

| Duty | Answer |
|---|---|
| Decisive claims re-derived | Harness and manifest SHA; H1–H3 at the cited lines; the timeout/process-tree behaviour of `subprocess.run`; 497-harness `time -o` and RED rule; workflow env-key rules; ELF `DT_NEEDED` of both packaged binaries; the extractor run over the 35 TB28 logs |
| Non-vacuity | `--self-test` makes each verdict and extractor rule executable on the exact harness bytes |
| Obligations | RA-138 H1–H3 carried; H4–H6 added; census-harness H1 carried; expiry contingency stated |
| Durable docs | Handoff, TODO, tracker, CHANGELOG, ORIENTATION, Frozen Definitions index |
| Boundary | Review-only; no source, test, harness, manifest, selector, workflow or runtime change |
