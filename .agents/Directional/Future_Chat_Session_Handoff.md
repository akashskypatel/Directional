# Future Chat Session Handoff

> **EXPLICIT USER AUTHORIZATION REQUIRED** to modify or delete this file; unauthorized changes must be reverted during documentation drift audit. This rewrite was expressly requested on 2026-10-16.</br>
> Edits to this document must follow the format laid out in `.agents/Directional/Future_Chat_Session_Handoff_Template.md`.

## Purpose — DURABLE, DO NOT DELETE

This file contains durable operating policy, the exact next action, current immutable authority, standing product state, and resume-critical information required to continue safely. Architecture belongs in `DESIGN.md`; tasks in `TODO.md`; completed history in `CHANGELOG.md`; lessons in `LESSONS.md`; roadmap in `ROADMAP.md`; exact runtime evidence in retained reports/closure records and the regression tracker. Do not add transcripts, chronological tool history, tool/policy/procedural failures, copied old artifact tables, obsolete selections, or procedure owned by policy/skill files. Concision never authorizes deleting durable information.

This section is durable and must be preserved. The displaced chronological handoff remains in Git history, **not** as instructions to replay.

All instructions and sections prefixed `[ChatGPT Web]` are mandatory for `ChatGPT Web` sessions. Non-`ChatGPT Web` agents (`ChatGPT Work`, `Codex`, `Claude`, etc.) can ignore instructions/sections bearing that prefix.

## Policies - Read first at start of every turn - DURABLE, DO NOT DELETE

Policies cannot be deleted or modified without explicit user authorization. The list uses verified existing paths (three old template filenames were outdated).

| Policy | File |
|---|---|
| Turn Cadence | `.agents/Directional/Turn_Cadence.md` |
| Agent Policy | `.agents/Directional/AGENT_POLICY.md` |
| Mandatory Start Checklist | `.agents/Directional/Mandatory_Start_Checklist.md` |
| Clean up Policy | `.agents/Directional/CLEAN_UP_POLICY.md` |
| Handoff Policy | `.agents/Directional/Durable_Handoff_Policy.md` |
| GitHub Workflow Policy | `.agents/Directional/GitHub_Workflow_Policy.md` |
| GMP Compile Policy | `.agents/Directional/GMP_COMPILE_POLICY.md` |
| Retention Policy | `.agents/Directional/RETENTION_POLICY.md` |
| Review Turn Policy | `.agents/Directional/REVIEW_TURN_POLICY.md` |
| Tool Use Conservation Policy | `.agents/Directional/TOOL_USE_CONSERVATION_POLICY.md` |
| Patch Application Strategy | `.agents/Directional/Patch_Application_Strategy.md` |
| Mandatory End Checklist | `.agents/Directional/Mandatory_End_Checklist.md` |

## Current immutable authority — replace in place

| Field | Exact value / evidence owner |
|---|---|
| Currency | 2026-10-23, after the audit of the TB29H review (RA-139). RA-138's H1–H3 and the TB29 hold are upheld. Added: H4 (on timeout, kill the whole process group, or the test keeps writing to its hashed log), H5 (timing output to a separate file, as the census harness does) and H6 (read the reason only from the first failure block). The probes become a built-in `--self-test`, and a count gate is added. The census harness has the same RED/INVALID flaw (carried). The GMP preflight was verified sound (`DT_NEEDED`). |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing`; PR #8 draft/open. Exact CB28A semantic commit `4473e41e94a35f1bf189fa046e86bac92c7391fb`, GMP/GMPXX package `12465330920` (run `39867988763`), outer ZIP SHA-256 `da56650a18f99443abf5f721620bb00fd5701dd1e660741da9aafb924a6dfbf5`; branch head includes subsequent dispatcher/documentation commits. |
| Last accepted semantic runtime | CP2 **491/491**, package `11391685901`, semantic `5ce3132ec01748eff5b15f82be07a1abe2bd1af6`. R3 **403/497** rejected. |
| Latest candidate evidence | RA-133-reviewed TB28 [run 39772864202](https://github.com/akashskypatel/Directional/actions/runs/39772864202), result artifact **`12424484672`**, ZIP SHA-256 `a54110dbb5475b76e6b6a6baa8fc1b7dcabd7aa50c95c5b390532509d1c656e6`; 1019/1019 manifest, 497/497 executed, **462 PASS/35 RED**, 13 RED→PASS and no PASS→RED vs TB21 449/48. Owning report `Architecture_M6_CP3_TB28_Selector_497_Census_Report_20261022.md`; TSV inventory and full ledger. **Not promoted.** |
| Regression accounting and debt | **66 events / 17 categories / 49 recurrences**, witness debt **1**, selector **497 frozen**, TB28 candidate 462/497, RP-01 OPEN. Tracker: `Regression_Root_Cause_Tracker.md`. |
| Active boundary | `RP-01` open. The seam family (12) and `selector:447` PASS at TB28. **35 REDs by first failing component (RA-134.2):**<br>- checked phase-front factory: 17 (13 silent: `focused30:3, 22, 23`; `selector:139, 140, 142, 220, 221, 296, 302, 304, 439`; `cp3entry:4`. 4 with the wrong code: `selector:211, 219, 227, 230`);<br>- A3 atlas: 8 (`selector:189–195` silent, `selector:442`);<br>- A5: `focused30:12`;<br>- producer disposition or oracle: 7 (`selector:174, 201, 204, 242, 247, 250, 405`);<br>- witness absence: `cp3entry:1` (D2), `cp3entry:2`.<br>CB27A-REV accepted the static oracle; CB28 and CB28A diagnostic text independently reviewed; TB29 measures typed reasons next. `RP-02` UNREACHED; Gate C suspended. |

## Mandatory next turn — `M6-CP3-TB29H-RP02-TARGETED-ARTIFACT-HARNESS-CORRECTION` — EXACT NEXT

- **Type / owner:** Code + Build, control-plane only (harness), no binary execution; implementation agent. Authority: RA-138 (`Architecture_M6_CP3_TB29H_Targeted_Harness_Review_Decision_20261023.md`) as amended by RA-139 (`Architecture_M6_CP3_TB29H_Review_Audit_Decision_20261023.md`); base design RA-137.3 (`Architecture_M6_CP3_TB29_Harness_Authorization_Design_Review_Decision_20261023.md`).
- **Objective:** make the reusable targeted harness classify terminal outcomes correctly, contain timeouts, extract reasons only from the failure, enforce a declared count, and prove all of this with an executable self-test.
- **Read before work:** RA-139 (all), RA-138 H1–H3, RA-137.3; `.agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh` (current SHA-256 `be3db020d5292a7ecb3851d4e662cadb08696e4dd1befe0e159c920069b9b412`); the 497 harness lines 295–312 (`time -o`, per-case pattern).
- **In scope** (edit only `m6_cp3_targeted_artifact_harness.sh`):
  1. **H1:** the RA-139.3 classifier. PASS = exit 0, 1 RUN, 1 `[       OK ] <test>`. RED = 1 RUN, 1 `[  FAILED  ] <test>`, exit 1. Everything else is INVALID, which counts as missing and makes the harness exit non-zero after evidence is published.
  2. **H2:** `--self-check <manifest> <expected-count>`, and an execute-time `EXPECTED_CASE_COUNT` input.
  3. **H3:** the A5 extractor keeps the whole reason, including hyphens (`A5:[A-Za-z][A-Za-z0-9_-]*` plus an optional `;site=…`).
  4. **H4:** `start_new_session=True`; on timeout `os.killpg(SIGKILL)` and reap the process before the log is read; write the timeout marker.
  5. **H5:** `/usr/bin/time -v -o resources/<row>.time.txt`, included in `SHA256SUMS`.
  6. **H6:** `typed_reason` and `first_failure` read only the first failure block (first `: Failure` or `unknown file: Failure` line up to the next `[  FAILED  ]` line, or end of file).
  7. **`--self-test`:** the 12 embedded synthetic cases of RA-139.4, run through the same functions; exit 0 only if all pass.
- **Validation (recorded):**
  - `bash -n`;
  - `py_compile` of the embedded program;
  - `--self-test` passes;
  - `--self-check Architecture_M6_CP3_TB29_Targeted_Case_Manifest.tsv 44` passes;
  - `--self-check` with 44 fails on scratch 1-row and 43-row copies, a duplicate copy and an unknown-kind copy.
- **Out of scope:** the manifest, the 497 and TB27 harnesses, workflows, product source, tests, selectors; any binary execution or dispatch.
- **Success evidence:** the corrected harness with its new SHA-256; record `Architecture_M6_CP3_TB29H_RP02_Harness_Correction_Code_Build_Record_20261023.md` (at most 30 lines) with the validation outputs; STATUS COMPLETE.
- **On success:** `M6-CP3-TB29H-RP02-TARGETED-ARTIFACT-HARNESS-CORRECTION-REV` (Review, mandatory): re-runs all validation on the new SHA; releases TB29.
- **On failure/blocker:** STOP and return to Review if a fix would require changing the manifest, the workflow or TB29's scope.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| 1 — next | `M6-CP3-TB29H-RP02-TARGETED-ARTIFACT-HARNESS-CORRECTION` | Control-plane harness correction (RA-138 H1–H3 + RA-139 H4–H6, `--self-test`, count gate); no execution. |
| 2 — conditional | `M6-CP3-TB29H-RP02-TARGETED-ARTIFACT-HARNESS-CORRECTION-REV` | Review, only after step 1 completes: re-runs `bash -n`, `py_compile`, `--self-check`, `--self-test` on the new SHA; releases TB29. |
| later — UNKNOWN until assigned | `M6-CP3-TB29-RP01-TYPED-FACTORY-CAUSE-HARVEST` (resumed: corrected harness at its reviewed SHA + `Architecture_M6_CP3_TB29_Targeted_Case_Manifest.tsv` + `EXPECTED_CASE_COUNT=44` on CB28A package `12465330920`, which expires 2026-10-29T22:54:39Z; recompile-only CB of `4473e41e9` if it lapses) → TB29-REV → DEFN-M1 → DEFN-M1-REV → corrective CB/TB → DEFN-T1 → fixture debt → census (needs an RA-139.3-compliant harness, RA-139.5) → RP-01 Review; `DEFN-SEAM-NZ` and the Periodic follow-up only after a witness | Planned, not authorized; each Review assigns the next edge. |
| later — UNKNOWN until assigned | `DIAG-RETAIN` (user-directed): retain A5 occurrences and relations, A6 merged classes and A7 vertex geometry as diagnostic snapshots for GUI/CLI; scope in `TODO.md` | Planned, not authorized; Review places it in the sequence clear of RP-01 turns. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **code-build (control-plane, static)** — TB29H-RP02: harness correction H1–H6 with built-in `--self-test` and count gate (RA-138, RA-139); no Directional binary execution.

Minimum successor context **after the mandatory start checklist and policies**:

0. `.agents/Directional/ORIENTATION.md` — project context, read first.
1. `.agents/Directional/ROADMAP.md` — milestone position only.
2. `.agents/Directional/Future_Chat_Session_Handoff.md` — exact current handoff.
3. `Architecture_M6_CP3_TB29H_Review_Audit_Decision_20261023.md` (RA-139: audit, H4–H6, RA-139.3 classifier, RA-139.4 self-test, census-harness obligation); `Architecture_M6_CP3_TB29H_Targeted_Harness_Review_Decision_20261023.md` (RA-138 H1–H3); `Architecture_M6_CP3_TB29_Harness_Authorization_Design_Review_Decision_20261023.md` (RA-137.3); `Architecture_M6_CP3_TB29_Targeted_Case_Manifest.tsv`.
4. `.agents/Directional/Regression_Root_Cause_Tracker.md` and `TODO.md` — unresolved issues and scope; required policy readings still govern.

**Review tooling:** `.agents/Directional/tools/` holds read-only helpers — `review_check.py authority <sha>` and
`review_check.py boundary`, `selector_probe.py` for selector hashes, ordinal ↔ identity and identity-existence
checks, and `fixture_probe.py` for fixture topology and vertex fans. See `tools/README.md` for the caveats.

## Resume-critical lessons — DURABLE, DO NOT DELETE

The substantive lessons live in `LESSONS.md`; use the relevant section rather than copying incident accounts.

| Section | Read it before |
|---|---|
| 1. Evidence, acceptance, and scope | Interpreting results, claiming acceptance, changing gates/selectors or classifying regressions. |
| 2. Witnesses, tests, and independent oracles | Designing fixtures, tests, invariants or independent checks. |
| 3. Semantic ownership, identity, and dataflow | Modifying semantic IDs, representations or producer-consumer contracts. |
| 4. Geometry, topology, and mathematical obligations | Changing geometric algorithms, topology or exact predicates. |
| 5. Diagnostics, classifiers, and causal investigation | Instrumentation, rejecting predicates or root-cause hypotheses. |
| 6. Contracts, planning, reviews, and durable records | Requirements, plans, reviews, authorization or documentation. |
| 7. Build, artifact, workflow, and tool mechanics | Compilation, packaging, CI, artifacts or repository operations. |

New lessons belong in `LESSONS.md`, not here.

## Maintenance — one live handoff

At authorized closeout, **replace** current authority, next action, conditional successor and context **in place**. Keep the durable purpose/policy/load/lesson sections. Archive completed changes in `CHANGELOG.md`, evidence in reports/tracker, tasks in `TODO.md`. Never append a second `CURRENT` section, a transcript or old turn ladder. The mandatory end checklist and `Durable_Handoff_Policy.md` govern `STATUS` closeout.
