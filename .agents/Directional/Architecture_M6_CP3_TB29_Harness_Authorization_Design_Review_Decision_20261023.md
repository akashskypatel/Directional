# RA-137 — TB29 block resolved: Review owns the case manifest; one reusable targeted harness (TB29H) before TB29 (2026-10-23)

**Turn:** `M6-CP3-TB29-RP01-HARNESS-AUTHORIZATION-DESIGN-REV`. **Input:** TB29 `BLOCKED` (`Architecture_M6_CP3_TB29_Prerequisite_Stop_20261023.md`); TB29 plan (`Architecture_M6_CP3_TB29_Typed_Factory_Cause_Harvest_Plan_20261022.md`).

**Verdict:** the stop was correct. The plan requires a new 44-identity harness, made and reviewed in its own Code + Build turn, and the TB turn may not write it.
- **The design gap:** each targeted TB has written its own single-use harness with hard-coded package values and cases (TB26, TB27). Selection logic and execution logic then get reviewed together, or not at all.
- **Resolution, separating the two concerns:**
  - **Review owns *what* is measured.** This Review publishes TB29's case manifest as a reviewed, hashed data file.
  - **The implementation agent owns *how* it runs.** One reusable, input-driven targeted harness (TB29H), reviewed once, statically.

  Future targeted TBs then need only a Review-issued manifest, with no new harness code.

## RA-137.1 Plan corrections (binding)

- **Guard trio.** The plan swapped `M6CP1.A7CrossSheetBindingRequiresConnectingIsolationTransition` for `M6CP2.A7ThreeSheetPartialConnectivityRejects`. RA-136.4 means RA-130.9's three guards, the ones TB27 ran (rows 19–21):
  - `M6CP1.A7CrossSheetBindingRequiresConnectingIsolationTransition`;
  - `M6CP2.A7WedgeTransitionWrongRegionRejects`;
  - `M6CP2.A7WedgeTransitionTouchWithoutConnectivityRejects`.

  The first is the guard closest to the changed A7 cross-sheet branch. The substitution is withdrawn.
- **Binaries.** All nine non-RED identities are in `SurfaceCellTransitionQuotientTests.cpp` and therefore in `directional_surface_cell_producer_tests` (`cmake/DirectionalTests.cmake:89–96`). The 35 REDs carry their TB28 owners: 34 in `directional_surface_cell_producer_tests`, and `selector:442` in `directional_surface_cell_authority_kernel_tests`. The TB27 harness hard-codes one binary, so it cannot run this set.

## RA-137.2 Case manifest (Review-owned, frozen by hash)

`Architecture_M6_CP3_TB29_Targeted_Case_Manifest.tsv`, SHA-256 **`39fa5eb83e2da1b0668bc7368c5304011ec13de8804c54a2a3466f927c42d236`**, 44 data rows.
- **Columns:** `row, kind, identity, test, binary, expect, asserted_site`.
- **Rows:**
  - 4 `NEGATIVE` (expect PASS; the site is asserted inside the test);
  - 2 `POSITIVE` (`cp3entry:3/5`);
  - 3 `GUARD` (RA-137.1);
  - 35 `RED`, copied verbatim from the TB28 inventory (SHA-256 `66c0ba37…3da` verified): phase:ordinal, identity, owner.
- **Checks:** 44 unique tests and 44 unique identities.

## RA-137.3 TB29H — reusable targeted harness (control-plane Code + Build)

**File:** `.agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh`. Derive it from the TB27 harness (`m6_cp3_tb27_a7_cross_sheet_verification_harness.sh`, SHA-256 `5e3ca0a7…fe1f`, proven in run 39764327506). Keep its package verification, `unzip` mode-preserving extraction, executable-mode check, staged-view hashing, GMP dependency and postflight checks.

**Generalize:**
1. **No hard-coded package values.** Inputs come from the environment:
   - `CANDIDATE_ARTIFACT_ID`;
   - `EXPECTED_SOURCE_SHA`;
   - `EXPECTED_CANDIDATE_ZIP_SHA256`;
   - `EXPECTED_ROOT_MANIFEST_SHA256`;
   - `EXPECTED_SOURCE_ARCHIVE_SHA256`;
   - `CASE_MANIFEST` (repo-relative path in the dispatch checkout);
   - `CASE_MANIFEST_SHA256`.

   Verify each input before anything runs.
2. **Read cases only from the manifest.** Require the exact header, unique `test` and `identity`, and `kind` in {NEGATIVE, POSITIVE, GUARD, RED}. Resolve each `binary` under the staged `bin/`, and fail closed if it is missing or not executable.
3. **Run each case exactly once:** `GTEST_FAIL_IF_NO_TEST_SELECTED=1 <binary> --gtest_filter=<test>`, with a timeout, no retry and no other selection. Record exactly one `[ RUN ]`; skips count as missing.
4. **Extract a typed reason for every non-PASS case**, using the published formats:
   - factory: `code=<int>;sourceAuthoritySite=…;edge=…;event=…;cell=…;region=…;periodicRelation=…`;
   - atlas: `code=<Name>[;sourceEdge=(a,b)…]`;
   - A5: `A5:<Name>[;site=…]`;
   - A7 or pipeline: `firstStage=…;firstReason=…` and `site=…`.

   If none appears, write the literal `reason-not-observed`. The first failure line is always recorded too.
5. **Gates.** Evidence is always published first; the exit code then reports:
   - **fail closed** on: a missing or duplicate case; skipped > 0; a NEGATIVE, POSITIVE or GUARD that is not PASS (`control_bad`); a manifest, package or view hash mismatch;
   - **report, but do not fail,** a RED row that passes (`unexpected_pass`).
6. **Outputs:**
   - `ledger.tsv`: row, kind, identity, test, binary, verdict, exit, run, passed, skipped, first_failure, typed_reason, log_sha256;
   - `raw/<row>.log`;
   - `execution-boundary.json`: state counts, `compile/relink/configure/benchmark=false`, postflight;
   - `SHA256SUMS`.
7. **`--self-check <manifest>` mode:** validates the manifest (header, count, uniqueness, kinds, column values) with **no** download or execution. Exit 0 or non-zero.

**TB29H evidence:**
- `bash -n` passes;
- the embedded Python compiles (`py_compile` of the extracted program);
- `--self-check` passes on the RA-137.2 manifest, and fails on two deliberately broken copies: a duplicate test, and an unknown kind;
- the harness SHA-256 is recorded in `Architecture_M6_CP3_TB29H_Targeted_Harness_Code_Build_Record_20261023.md` (at most 30 lines);
- **no** product, test, selector, workflow or manifest change, and **no** binary execution.

## RA-137.4 Sequence and accounting

- **Sequence:** design review (this) → **TB29H** → TB29H-REV → TB29, run with:
  - harness `m6_cp3_targeted_artifact_harness.sh` at its reviewed SHA, via `agent-test-benchmark-reusable.yml`;
  - the RA-137.2 manifest;
  - CB28A package `12465330920`: source `4473e41e94a35f1bf189fa046e86bac92c7391fb`, ZIP `da56650a…dfbf5`; it **expires 2026-10-29T22:54:39Z**.

  → TB29-REV → DEFN-M1 → DEFN-M1-REV → corrective CB/TB → DEFN-T1 → fixture debt → census → RP-01 Review. `DEFN-SEAM-NZ` and the Periodic follow-up each wait for a witness. `DIAG-RETAIN` is scheduled clear of RP-01 turns.
- **CB28A:** the diff `4473e41e9` was re-checked as message-only at exactly the three asserts named in RA-136.3.
- **Accounting (unchanged):** stable 66/17/49, debt 1, CP2 491/491; R3 403/497 rejected; TB28 462/497 candidate; selector 497 frozen. `RP-01` open, `RP-02` UNREACHED, Gate C suspended.

| Duty | Answer |
|---|---|
| Decisive claims re-derived | TB29 stop and plan; TB27 harness structure (single binary, hard-coded cases and package); identity-to-binary mapping (CMake 89–96; inventory owners); guard trio against RA-130.9/TB27; inventory hash; manifest built and hashed; CB28A diff; package expiry |
| Non-vacuity | Self-check negatives required; fail-closed control gates; `reason-not-observed` made explicit |
| Obligations | TB29 plan corrected (guards); RA-136.4 carried into the manifest; harness reuse for later targeted TBs |
| Durable docs | Handoff, TODO, tracker, CHANGELOG, ORIENTATION, Frozen Definitions index |
| Boundary | Review-only; adds a Review-owned data manifest; no source, test, selector, workflow or runtime change |
