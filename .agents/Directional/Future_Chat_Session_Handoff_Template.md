# Future Chat Session Handoff

> This file requires EXPLICIT USER AUTHORIZATION to modify or delete. Any modifications or deletions must be reverted during documentation drift audit unless explicitly approved by the user.

## Purpose — DURABLE, DO NOT DELETE

This file contains durable operating policy, the exact next action, current immutable authority, standing product state, and resume-critical information required to continue safely. Architecture belongs in `DESIGN.md`; tasks belong in `TODO.md`; completed history belongs in `CHANGELOG.md`; lessons learned belong in `LESSONS.md`; development roadmap belongs in `ROADMAP.md`; current exact runtime evidence belongs in the retained latest report/closure records and regression tracker. Do not add transcripts, chronological tool history, tool failures policy failures, procedural failures, lessons learned, copied superseded artifact tables, obsolete task selections, or generic procedure already owned by policy/skill files. Concision never authorizes deletion of durable information.

This section is durable. It may be corrected or extended, but it must not be deleted, collapsed into another section, or replaced by a summary without explicit user authorization.

All instructions and sections prefixed with `[ChatGPT Web]` are mandatory for all `ChatGPT Web` sessions and must be followed exactly as written.
All non-`ChatGPT Web` agents, i.e. `ChatGPT Work`, `Codex`, `Claude`, etc., can safely ignore any instruction or section prefixed with `[ChatGPT Web]`.

## Policies - Read first at start of every turn - DURABLE, DO NOT DELETE

These policies cannot be deleted or modified without explicit user authorization.

| Policy | File |
|--------|------|
| Turn Cadence | .agents\Directional\Turn_Cadence.md |
| Agent Policy | .agents\Directional\AGENT_POLICY.md |
| Mandatory Start Checklist | .agents\Directional\Mandatory_Start_Checklist.md |
| Clean up Policy | .agents\Directional\CLEAN_UP_POLICY.md |
| Handoff Policy | .agents\Directional\Durable_Handoff_Policy.md |
| GitHub Workflow Policy | .agents\Directional\GitHub_Workflow_Policy.md |
| GMP Compile Policy | .agents\Directional\GMP_COMPILE_POLICY.md |
| Retention Policy | .agents\Directional\RETENTION_POLICY.md |
| Review Turn Policy | .agents\Directional\REVIEW_TURN_POLICY.md |
| Tool Use Conservation Policy | .agents\Directional\TOOL_USE_CONSERVATION_POLICY.md |
| Patch Application Strategy | .agents\Directional\Patch_Application_Strategy.md |
| Mandatory End Checklist | .agents\Directional\Mandatory_End_Checklist.md |

## Current immutable authority — replace in place

| Field | Exact value / evidence owner |
|---|---|
| Currency | `<UTC date>`, after `<last accepted turn>` |
| Working branch / HEAD | `<branch>` / `<sha>` (verify fresh before mutation) |
| Last accepted semantic runtime | `<source SHA / package ID / accepted selector / results>`; link to authoritative review |
| Latest candidate or rejected evidence | `<turn, package, run, outcome, evidence report>`; **not promoted** unless explicitly accepted |
| Regression accounting and debt | `<current stable totals, owned unresolved debt>`; link to regression tracker |
| Active boundary | `<blocker ID, precise unknown, next evidence needed, explicit restrictions>` |

## Mandatory next turn — `<CANONICAL TURN ID | UNKNOWN>` — EXACT NEXT

- **Type / owner:** `<DEFN | CB | TB | REV>`; `<authorized source decision or plan>`.
- **Objective:** `<one bounded result the next agent must establish>`.
- **Read before work:** `<current plan or review authority>`, `<specific evidence>`, `<frozen definitions>`.
- **In scope:** `<exact authorized read/decision/edit/compile/runtime surface>`.
- **Out of scope:** `<tests, source, selectors, benchmarks, workflow or other forbidden mutations>`.
- **Success evidence:** `<independently checkable acceptance criteria, report and disposition>`.
- **On success:** `<exact, already-authorized canonical successor ID>` or `UNKNOWN — STOP; authorization required`.
- **On failure/blocker:** `<exact, already-authorized recovery successor ID>` or `UNKNOWN — STOP; no speculative continuation`.

If no authoritative document assigns the canonical Review/turn ID, state **UNKNOWN**; describe the known task but **do not invent** an ID or allow autonomous source mutation. A handoff cannot confer authority the preceding turn did not grant.

## Turn Sequence

Record **only the next authorized edge** and any frozen conditional edge, not the past ladder:

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| 1 — next | `<ID / UNKNOWN>` | `<owner, authorized work>` |
| 2 — conditional | `<ID / UNKNOWN>` | `<only after step 1's reviewed outcome, or STOP>` |

Any further unassigned successor is `UNKNOWN`; the agent requests or freezes authorization before advancing.

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: `<review | plan | code-build | test-benchmark>` — use the turn-appropriate turn-based-coding-agent skill/guidance; **do not default to Code + Build** when the next action is Review.

Minimum successor context **after the mandatory start checklist and policies**:

0. `.agents/Directional/ORIENTATION.md` — project context, read first.
1. `.agents/Directional/ROADMAP.md` — milestone position only.
2. `.agents/Directional/Future_Chat_Session_Handoff.md` — exact current handoff.
3. `<specific frozen definition / accepted review / latest report / plan>` — list only next-turn-relevant files.
4. `.agents/Directional/Regression_Root_Cause_Tracker.md` and `TODO.md` — unresolved issues and scope; required policy readings still govern.

**Review tooling:** `.agents/Directional/tools/` holds read-only helpers — `review_check.py authority <sha>` and
`review_check.py boundary`, `selector_probe.py` for selector hashes, ordinal ↔ identity and identity-existence
checks, and `fixture_probe.py` for fixture topology and vertex fans. See `tools/README.md` for the caveats.

## Resume-critical lessons — DURABLE, DO NOT DELETE

Sections, so the right one can be found without reading the whole document:

| Section                                               | Read it before                                                                                                                  |
| ----------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------- |
| 1. Evidence, acceptance, and scope                    | Interpreting results, claiming acceptance, modifying gates or selectors, or classifying regressions.                            |
| 2. Witnesses, tests, and independent oracles          | Designing fixtures, writing tests, validating invariants, or constructing independent correctness checks.                       |
| 3. Semantic ownership, identity, and dataflow         | Modifying data representations, producer-consumer contracts, semantic identities, or pipeline boundaries.                       |
| 4. Geometry, topology, and mathematical obligations   | Implementing geometric algorithms, topology operations, mathematical invariants, or exact predicates.                           |
| 5. Diagnostics, classifiers, and causal investigation | Investigating failures, adding instrumentation, interpreting rejection codes, or proposing root-cause corrections.              |
| 6. Contracts, planning, reviews, and durable records  | Defining requirements, planning implementation, conducting reviews, authorizing corrections, or updating durable documentation. |
| 7. Build, artifact, workflow, and tool mechanics      | Compiling, packaging, executing CI workflows, handling artifacts, or performing repository operations.                          |

New lessons are added to `LESSONS.md` in the section that governs them, not appended here.

## Maintenance rule — keep a single live handoff

Replace the currency, authority, next turn, conditional sequence and loaded references **in place** at every applicable closeout. Never append another `CURRENT` or copy a chronology into this document. Keep evergreen rules in the policy files, old evidence in its owned report/closure record, task backlog in `TODO.md`, and history in `CHANGELOG.md`. If authority or successor is unknown, say `UNKNOWN`, give the evidence owner and stop condition, and seek explicit authorization. The review/end checklists remain binding even when this document is abbreviated.
