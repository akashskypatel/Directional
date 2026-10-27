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
| Currency | 2026-10-27, after [RA-164](Architecture_M6_CP3_TB45_REV_Audit_Rail_Oracle_Triage_Cadence_Realignment_Decision_20261027.md): TB45-REV confirmed; 174 and cp3entry:4 decided statically (fixture / owner re-home); remaining REDs clustered (E: 201, cp3entry:2; G: 442, focused30:12, cp3entry:1); CP3 cadence realigned to `Turn_Cadence.md` (CB→full-gate TB direct; red TB → Review-owned DEFN; STOP codes; no `UNKNOWN` successor). |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing` / verify fresh before mutation. |
| Last accepted semantic runtime | CP2 **491/491** accepted 2026-10-06 (selector449 `d4a0d1b7…d6414`, focused12 `2aa57aac…c67374ed`). Nothing newer is accepted. |
| Latest candidate or rejected evidence | TB45 **3/3** focused on CB45 source `dfeb0751b` ([report](Architecture_M6_CP3_TB45_Selector242_Seam_Rehome_Verification_Report_20261027.md), [TB45-REV](Architecture_M6_CP3_TB45_Selector242_Seam_Rehome_Independent_Review_Decision_20261027.md), result `12702259228` SHA-256 `7d18b08a…bcd6080`, 9/9 members). Last full gate: TB38 **490/504** candidate on source `038ae7fd7`; no production change since. Focused TB41 18/18, TB42 1/1, TB43 4/4, TB44 3/4, TB45 3/3 await TB46 reconciliation. Selector497 frozen, unpromoted. |
| Regression accounting and debt | Stable **66/17/49**, debt 1 ([tracker](Regression_Root_Cause_Tracker.md)). No new stable event. |
| Active boundary | RP-01 open, RP-02 unreached. TB46 predicted **499/5**: RED `selector:201`, `selector:442`, `focused30:12`, `cp3entry:1`, `cp3entry:2`; POSITIVE 174, cp3entry:4 (RA-164 H1/H2); GUARD 191/192/204/247/250/405/242. O4/O5 (+P1-a, P1-b, RA-162 C1, H2 A5 reachability) → one Review-owned DEFN (RA-164.6 step 4). O6 unowned nonrectangular disks. Carried: DIAG-RETAIN, O1, O2 (post-RP-01, + RA-161 T2), RA-152.5, DEFN-SEAM-NZ, RA-146.2/4, RA-45.4, G4-B002. |

## Mandatory next turn — `M6-CP3-CB46-RP01-RAIL-ORACLE-REHOME-AND-ENDPOINT-DIAGNOSTICS` — EXACT NEXT

- **Authority:** [RA-164.4](Architecture_M6_CP3_TB45_REV_Audit_Rail_Oracle_Triage_Cadence_Realignment_Decision_20261027.md). Test-only Code+Build, compile only. Allowlist: H1 (174, `REPackageTests:445–459`), H2 (cp3entry:4, `TQTests:3971–3994`), D1 (`REPackageTests:713`), D2 (`TQTests:3136–3141`), D3 (`TQTests:2916–2918`); D1–D3 message-only.
- **Evidence:** 8 GMP/GMPXX targets, `runtimeExecution=false`, record ≤30 lines with hunk list.
- **Outcome table (P1/P4):** compile OK and diff ⊆ allowlist → `M6-CP3-TB46-RP01-FULL-GATE` (no CB-REV). C2 compile error in a hunk → fix in-hunk, ≤2 attempts. S1 symbol not visible / S2 change outside allowlist / S3 selector or manifest bytes → `M6-CP3-CB46-RP01-RAIL-ORACLE-REHOME-AND-ENDPOINT-DIAGNOSTICS-REV`. S5 orchestration → Cadence rule 5. Never `Successor: UNKNOWN` on COMPLETE/BLOCKED.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| done | TB45 → TB45-REV → RA-164 audit | 242 focused 3/3; 174 DEFN superseded; cadence realigned (RA-164.3). |
| 1 — next | `M6-CP3-CB46-RP01-RAIL-ORACLE-REHOME-AND-ENDPOINT-DIAGNOSTICS` | Test-only, 5 allowlisted hunks; → TB46 directly. |
| 2 | `M6-CP3-TB46-RP01-FULL-GATE` | Artifact-only, 504-row [manifest](Architecture_M6_CP3_TB46_Full_Gate_Case_Manifest.tsv) `717f4f0f…6bb087`, harness `m6_cp3_targeted_artifact_harness.sh` `436f5fff…`; predict 499/5; outcome table RA-164.5. |
| 3 | `M6-CP3-DEFN-RP01-TB46-ENDPOINT-CLUSTER` (Review) → CB47 → `M6-CP3-TB47-RP01-FULL-GATE` | Absorbs TB46 REVIEW+PLAN; decides E (201, cp3entry:2) from D1/D2 harvest. |
| 4 | `M6-CP3-DEFN-RP01-TB47-GAUGE-CLUSTER` (Review) → CB48 (may split by owner) → `M6-CP3-TB48-RP01-FULL-GATE` | G: 442, `focused30:12`, cp3entry:1; RA-163 R2 relabel principle. |
| 5 | `M6-CP3-DEFN-RP01-O4-O5-RAIL-PROVENANCE` (Review) → CB49 → TB49 | O4, O5, P1-a/P1-b, RA-162 C1, H2 A5 reachability; full gate + non-gating P1 rows. |
| 6 | Green full gate → RP-01 Review | Must state O6 CP3 scope and owner. |
| post-RP-01 | `M6-CP3-DEFN-POSTRP01-O2-NO-ATLAS-INGRESS-RETIREMENT`, then `DIAG-RETAIN` | RA-160.4 + RA-161 T2; DIAG-RETAIN edits `RemeshPipeline.cpp`. |
| rule | RA-164.3 P1–P6 | CB→TB direct; full-gate TBs only; red TB → Review-owned DEFN; STOP codes S1–S5 with fixed successors; REV-AUDIT only on record conflict. |
| carried | O1, O6, RA-152.5, DEFN-SEAM-NZ (+RA-163.4), RA-146.2/4, RA-45.4, G4-B002 | Separate gates. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **M6-CP3-CB46-RP01-RAIL-ORACLE-REHOME-AND-ENDPOINT-DIAGNOSTICS** — test-only per [RA-164.4](Architecture_M6_CP3_TB45_REV_Audit_Rail_Oracle_Triage_Cadence_Realignment_Decision_20261027.md). Load `tests/SurfaceCellREPackageTests.cpp:430–460, 700–720`, `tests/SurfaceCellTransitionQuotientTests.cpp:2905–2920, 3110–3145, 3960–3995`, `include/directional/core/TriMesh.h:331–340`, `include/directional/geometry/SurfaceCellTracing.h:1493–1531, 1940–1946`. Compile only; then TB46 with the frozen 504-row manifest.

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
