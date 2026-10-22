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
| Currency | 2026-10-22, CB28A test-only three-assert messages independently accepted, TB29 artifact-only next; no new runtime. RA-136.3/4; compiled source `4473e41e94a35f1bf189fa046e86bac92c7391fb` package `12465330920`. |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing`; PR #8 draft/open. Exact CB28A semantic commit `4473e41e94a35f1bf189fa046e86bac92c7391fb`, GMP/GMPXX package `12465330920` (run `39867988763`), outer ZIP SHA-256 `da56650a18f99443abf5f721620bb00fd5701dd1e660741da9aafb924a6dfbf5`; branch head includes subsequent dispatcher/documentation commits. |
| Last accepted semantic runtime | CP2 **491/491**, package `11391685901`, semantic `5ce3132ec01748eff5b15f82be07a1abe2bd1af6`. R3 **403/497** rejected. |
| Latest candidate evidence | RA-133-reviewed TB28 [run 39772864202](https://github.com/akashskypatel/Directional/actions/runs/39772864202), result artifact **`12424484672`**, ZIP SHA-256 `a54110dbb5475b76e6b6a6baa8fc1b7dcabd7aa50c95c5b390532509d1c656e6`; 1019/1019 manifest, 497/497 executed, **462 PASS/35 RED**, 13 RED→PASS and no PASS→RED vs TB21 449/48. Owning report `Architecture_M6_CP3_TB28_Selector_497_Census_Report_20261022.md`; TSV inventory and full ledger. **Not promoted.** |
| Regression accounting and debt | **66 events / 17 categories / 49 recurrences**, witness debt **1**, selector **497 frozen**, TB28 candidate 462/497, RP-01 OPEN. Tracker: `Regression_Root_Cause_Tracker.md`. |
| Active boundary | `RP-01` open. The seam family (12) and `selector:447` PASS at TB28. **35 REDs by first failing component (RA-134.2):**<br>- checked phase-front factory: 17 (13 silent: `focused30:3, 22, 23`; `selector:139, 140, 142, 220, 221, 296, 302, 304, 439`; `cp3entry:4`. 4 with the wrong code: `selector:211, 219, 227, 230`);<br>- A3 atlas: 8 (`selector:189–195` silent, `selector:442`);<br>- A5: `focused30:12`;<br>- producer disposition or oracle: 7 (`selector:174, 201, 204, 242, 247, 250, 405`);<br>- witness absence: `cp3entry:1` (D2), `cp3entry:2`.<br>CB27A-REV accepted the static oracle; CB28 and CB28A diagnostic text independently reviewed; TB29 measures typed reasons next. `RP-02` UNREACHED; Gate C suspended. |

## Mandatory next turn — `M6-CP3-TB29-RP01-TYPED-FACTORY-CAUSE-HARVEST` — EXACT NEXT

- **Type:** Test + Benchmark, artifact-only, authorized by CB28A independent Review and RA-136.4. **Do not compile/rebuild/relink/configure/modify source, fixture, selector or workflow.**
- **Immutable executor:** CB28A semantic `4473e41e94a35f1bf189fa046e86bac92c7391fb`, compile result `12465330920`, outer SHA-256 `da56650a18f99443abf5f721620bb00fd5701dd1e660741da9aafb924a6dfbf5`, 28/28 internal checksums, GMP/GMPXX. Runtime has **not** run on this package.
- **Exactly 44 tests:** four A7 negatives, D3/D7 positives (`cp3entry:3/5`), three existing A7 site guards, and all 35 frozen TB28 REDs. Source inventory and checks: `Architecture_M6_CP3_TB29_Typed_Factory_Cause_Harvest_Plan_20261022.md`. Measure each authentic first-failure code/site; report falsifiers and non-vacuous A7 paths; do not infer root cause from topic.
- **Review record:** `Architecture_M6_CP3_CB28A_M1_Precedence_Assert_Diagnostics_Review_Decision_20261022.md`. After TB29, a separately authorized independent TB29-REV determines DEFN-M1 scope. No successor beyond TB29 may be entered within this turn.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| 1 — completed | `M6-CP3-CB28A-RP01-M1-PRECEDENCE-ASSERT-DIAGNOSTICS` | Message-only 3 asserts; semantic `4473e41e94a3`; eight-target GMP/GMPXX compile `12465330920`, no runtime. |
| 2 — completed | `M6-CP3-CB28A-RP01-M1-PRECEDENCE-ASSERT-DIAGNOSTICS-REV` | Static-only acceptance of three assertion messages, exact package verification, no runtime. |
| 3 — next | `M6-CP3-TB29-RP01-TYPED-FACTORY-CAUSE-HARVEST` | Targeted artifact-only 44-identity harvest, no compile; independent TB29-REV follows. |
| later — UNKNOWN until assigned | TB29-REV → DEFN-M1 (scoped from measured factory clauses) → DEFN-M1-REV → corrective CB/TB → DEFN-T1 → fixture debt → census → RP-01 Review; `DEFN-SEAM-NZ` and the Periodic follow-up (RA-130.7) only after a witness | Planned, not authorized; each Review assigns the next edge. |
| later — UNKNOWN until assigned | `DIAG-RETAIN` (user-directed): retain A5 occurrences and relations, A6 merged classes and A7 vertex geometry as diagnostic snapshots for GUI/CLI; scope in `TODO.md` | Planned, not authorized; Review places it in the sequence clear of RP-01 turns. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **test_benchmark** — exact CB28A package (`12465330920`) and 44-identity TB29 plan; no compile and no semantic edits.

Minimum successor context **after the mandatory start checklist and policies**:

0. `.agents/Directional/ORIENTATION.md` — project context, read first.
1. `.agents/Directional/ROADMAP.md` — milestone position only.
2. `.agents/Directional/Future_Chat_Session_Handoff.md` — exact current handoff.
3. `Architecture_M6_CP3_TB29_Typed_Factory_Cause_Harvest_Plan_20261022.md`, `Architecture_M6_CP3_CB28A_M1_Precedence_Assert_Diagnostics_Review_Decision_20261022.md`, RA-136.4, and exact immutable compile package `12465330920`; no source mutation.
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
