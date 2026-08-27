# Agent Policy

This policy does not apply to `ChatGPT Web` sessions.

## Universal compile requirement

The exemptions below do **not** exempt local agents from `.agents/Directional/GMP_COMPILE_POLICY.md`. GMP/GMPXX linkage is mandatory for every future Directional compile in every execution environment. A fallback exact-arithmetic build is not authoritative compile evidence.

## Local Agents

Local agents are exmpt from following the following policies and can safly ignore any instructions related to them:

- `Github_Workflow_Policy.md` - This policy is for leveraging GitHub Actions to acomplish certain tasks explicitly by `ChatGPT Web` sessions and does not apply to local agents
- `TOOL_USE_CONSERVATION_POLICY.md` - This policy is for limiting the use of tools to avoid hitting tool use window premateruly by `ChatGPT Web` sessions and does not apply to local agents
- `Future_Chat_session_Handoff.md` **Patch Application Strategy** - This policy is for handling patch application using Github Workflows by `ChatGPT Web` sessions and does not apply to local agents
