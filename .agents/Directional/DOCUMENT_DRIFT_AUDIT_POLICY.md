# Directional — Document Drift Audit Policy

**Status:** Proposed policy for owner review; no existing policy is superseded by this draft.  
**Scope:** Living project guidance, documentation references, durable authority, and milestone/turn status.  
**Companion:** `.agents/Directional/tools/document_drift_audit.py` (read-only, Python standard library).

## 1. Purpose and ownership

Keep the documentation useful to a cold-start developer or agent and prevent repeated status histories from displacing each file's purpose. Documentation is organized by **role, not by turn**:

| Document | Owns | Must not become |
|---|---|---|
| `ORIENTATION.md` | Project summary, architecture map, fixtures, document map, cadence, current position and outlook. | A transcript, review journal, or detailed procedure. |
| `ROADMAP.md` | Milestones/checkpoints: outcome, completed/active/planned status, dependency and concise acceptance signal. | A task ledger, execution log or dump of frozen definitions. |
| `Future_Chat_Session_Handoff.md` | **Exactly one** current authority, bounded next action, success/failure disposition, conditional successor and context loading; conform to `Future_Chat_Session_Handoff_Template.md`. | Historical turn sequence, copied evidence report or independent policy document. |
| `DESIGN.md` / frozen definitions | Product architecture, normative contracts, accepted amendments and stop conditions. | An informal status narrative. |
| `TODO.md` / `Regression_Root_Cause_Tracker.md` | Live tasks, open faults, classifications, owners and falsifiers. | A duplicate handoff. |
| `CHANGELOG.md` / closure records / retained reports | Completed history, exact reviews, selectors, artifacts and preserved normative evidence. | An active successor authority. |
| `LESSONS.md` | Reusable failure modes and correctives. | A copy of an individual turn's log. |
| `*POLICY.md`, checklists and tools | Stable procedures, authorization and verification requirements. | Per-turn status or product semantics. |

The primary **source of truth remains the owning file**, not a summary elsewhere. In particular, a roadmap PASS is not a product claim; the frozen selector and accepted review govern evidence, while the root `STATUS` is only a lifecycle beacon. `workflow-mailbox` is a separate branch: never inspect or mutate its authority as ordinary documentation cleanup.

## 2. Preservation and authorization

1. **Never auto-rewrite, delete, truncate, revert, or regenerate documents.** The audit tool detects risks and reports them; it grants no edit authorization. A failed audit blocks claiming documentation closure, not the preservation of evidence.
2. Existing explicit-user-authorization protections in policies/templates/handoff and `RETENTION_POLICY.md` remain binding. A documentation refactor requires an explicit owner-approved scope; a successful automated check or a note inside an agent-authored commit does **not** prove approval.
3. Normative definitions, frozen selector bytes, durable sections and accepted evidence cannot be silently deleted, abbreviated, reassigned, or weakened. Where consolidation is explicitly authorized, preserve the entire authoritative text in its approved destination, index original filenames and immutable provenance, then reconcile active references. Historical statements embedded in closure records are not live instructions.
4. **Shrinking a navigation document is not intrinsically a defect.** Conversely, adding lines does not prove preservation. The legacy `review_check.py ledgers` append-only/high-water-length rule conflicts with explicitly authorized reductions of `ORIENTATION.md` and the handoff; classify that conflict for human review and update that rule only under its own authorization. This new audit does **not** use document length loss as evidence of substantive loss.
5. Preserve the explicit `[ChatGPT Web]` scope of operational instructions, even if another agent need not execute those instructions. Do not broaden or waive an applicable policy while editing the handoff.

## 3. Required audit and remediation cadence

Run the static audit **locally** before submitting a change to a living document or policy and at each formal Review closeout; run it again against the final tree after changes. A pre-merge CI integration is recommended once the owner authorizes it. Audit against a known base ref when available (e.g. PR base) to identify protected mutations:

```bash
python3 .agents/Directional/tools/document_drift_audit.py --root .
python3 .agents/Directional/tools/document_drift_audit.py --root . --base origin/master --json
python3 .agents/Directional/tools/document_drift_audit.py --root . --base origin/master --strict
python3 .agents/Directional/tools/document_drift_audit.py --self-test
```

`--base` is an **existing local Git ref**; the tool does not fetch remote branches or invoke workflows. Use a real merge-base if the comparison branch contains unrelated historical restructurings. The tool itself is pure-read and can run offline. It does not compile or execute Directional and cannot establish semantic acceptance.

After an audit, the responsible agent must:

1. **Classify each finding**: confirmed current drift, intentionally historical/provenance-only, explicitly authorized transformation, or inconclusive. Do not fix ambiguous authority by guessing.
2. **Repair the owning current location in place**, not by prepending a competing `CURRENT` section; reconcile handoff, `TODO.md`, `ROADMAP.md`, `ORIENTATION.md` and root `STATUS` as warranted. The status beacon may not substitute for review authority.
3. **Preserve/discharge historic evidence** in its proper record before removing stale text. For an intentional normative/protected edit, provide the owner's authorization, old/new destination and exact evidence of preservation.
4. **Re-run the audit** and document residual findings with owner and planned correction. An unresolved error or unadjudicated protected change prevents the agent from reporting a clean audit. Do not suppress a real finding by weakening the checker.

## 4. What the checker detects (static)

| Detection | Disposition |
|---|---|
| Missing landing page, required structural section, policy listed in the handoff template, or handoff template itself | **Error** |
| Multiple append-style `CURRENT`/resume-history headings in living documents | **Error** |
| Broken **local Markdown links** in living landing pages, using actual path resolution | **Error** |
| A known non-`UNKNOWN` root `STATUS.Successor` absent from the handoff's mandatory-next-turn section | **Error** |
| Deleted protected files or lost headings explicitly marked `DURABLE` / `DO NOT DELETE` relative to `--base` | **Error** |
| Any edit to a protected policy, template, definition, selector or key landing file relative to `--base` | **Warning: independent authorization review required** |
| Duplicate section headings, document size exceeding a **heuristic navigation budget** | **Warning** (more than twice budget is an error) |

Budgets are heuristic, not quotas: `ROADMAP` **16 KiB approx.**, `ORIENTATION` **24 KiB**, handoff and template **16 KiB each** (checker uses exact byte thresholds). An owner may authorize a longer document where justified. **No automatic trimming** occurs. Reports include file, rule, severity and (where available) line; `--json` supports CI. Exit codes: **0** no errors (warnings allowed); **1** errors, or any finding under `--strict`; **2** invalid invocation/environment. Do not count `--strict` as proof of human authorization.

## 5. What requires human verification

The checker cannot verify authoritative semantic assertions. An independent reviewer must read primary evidence and resolve, at minimum:

- **Currency and consistency:** accepted checkpoint status/selector, candidate vs promoted evidence, stable ledger/debt, witness status, blocker classification and latest valid review agree across their owning sources. Date alone is not enough to infer current authority.
- **Successor authorization:** the precise next turn, scope and success/failure paths are supported by a reviewed decision. If a canonical ID is absent, handoff states `UNKNOWN — STOP`; the audit never invents an ID.
- **Preservation:** moved frozen definitions, selectors, exact hashes, closure verdicts, and regulatory/contractual obligations retain full content and provenance. A Git-only link to an old document is **not** itself proof of preserving binding content where in-repo retention is required.
- **Link quality:** retired plain-text references, external URLs, anchors, generated paths, and meaningful document navigation; automatic local-link scanning does not prove these correct.
- **Intent and readability:** one-screen summary for the live state, clear owner and next step, no duplicate narratives, no stale warnings, and no new public docs with implementation-only procedure.

Historical closure/review reports are intentionally **not** scanned for `CURRENT` headings, historic successor labels or duplicate headers. The audit checks living documents, not retrospective history. Treat all automated findings as evidence to classify, never as an independent semantic oracle.

## 6. Change control and integration

This policy complements—not replaces—`Durable_Handoff_Policy.md`, `REVIEW_TURN_POLICY.md`, `CLEAN_UP_POLICY.md`, `RETENTION_POLICY.md`, `Mandatory_Start_Checklist.md`, `Mandatory_End_Checklist.md`, and existing selector/authority review tools. Existing mandatory start/end/STATUS lifecycle requirements are unaffected.

**Suggested owner-approved integration:** add one step to the Review/end checklist to run `document_drift_audit.py --base <approved comparison ref>`, record errors/warnings and human dispositions; optionally add a read-only PR CI job after a representative clean baseline. Do **not** add a workflow, edit protected policies or force failures against pre-existing unrelated drift without separate authorization and initial triage.

**Maintenance rule:** adjust the checker's required sections, policy filename inventory and size budgets only when the corresponding canonical document structure changes with owner approval. Changes to the audit tool/policy themselves require code review and its offline self-test. The checker must remain read-only, deterministic, standard-library-only, and never become a second source of normative or acceptance authority.
