# Agent Policy

Except for the same-agent REVIEW/DEFN authorization below, this policy does not apply to `ChatGPT Web` sessions.

## Same-agent REVIEW and DEFN authorization — DURABLE, DO NOT DELETE

**User-authorized 2026-09-10. This section applies to every agent type, including `ChatGPT Web`.** A REVIEW, REVIEW + PLAN, or DEFN turn may be performed by the same agent/session that authored or executed an earlier CB, TB, REVIEW, or DEFN turn in the chain. A personnel/session handoff is not required unless a specific acceptance criterion explicitly requires distinct people or agents.

References to **independent review**, **independent verification**, or an **independent oracle** describe independence of evidence, derivation, authority, or implementation path, not mandatory personnel separation. A same-agent REVIEW must re-open the primary evidence it adjudicates and independently re-derive decisive facts instead of treating its own prior narrative as authority. A same-agent DEFN remains planning/runtime-free and must freeze definitions from cited architecture, evidence, and reviewed constraints; it may not smuggle implementation or runtime acceptance into the definition turn.

This authorization changes only who may perform REVIEW/DEFN. It does **not** relax turn boundaries, runtime/compile prohibitions, evidence provenance, validation integrity, red-TB routing, stop rules, or any explicit criterion that separately demands an independent implementation/oracle/evidence source.

## Universal compile requirement

The exemptions below do **not** exempt local agents from `.agents/Directional/GMP_COMPILE_POLICY.md`. GMP/GMPXX linkage is mandatory for every future Directional compile in every execution environment. A fallback exact-arithmetic build is not authoritative compile evidence.

## Local Agents

Local agents are exmpt from following the following policies and can safly ignore any instructions related to them:

- `Github_Workflow_Policy.md` - This policy is for leveraging GitHub Actions to acomplish certain tasks explicitly by `ChatGPT Web` sessions and does not apply to local agents
- `TOOL_USE_CONSERVATION_POLICY.md` - This policy is for limiting the use of tools to avoid hitting tool use window premateruly by `ChatGPT Web` sessions and does not apply to local agents
- `Future_Chat_session_Handoff.md` **Patch Application Strategy** - This policy is for handling patch application using Github Workflows by `ChatGPT Web` sessions and does not apply to local agents
