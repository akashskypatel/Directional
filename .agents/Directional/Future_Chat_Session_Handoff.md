# Future Chat Session Handoff

## Purpose

This handoff is the concise resume document for future agents starting from a clean slate. Its purpose is to bring a new agent up to speed quickly on the **current ongoing work of the cross-field-aligned surface-cell paving pipeline implementation**, including the exact next turn, current authoritative state, live blockers, and the references required to continue correctly.

It is not a changelog, task archive, evidence archive, transcript, or substitute for the project's design, architecture, policy, test, or per-turn authority documents.

## DURABLE handoff policy — mandatory

This section is durable and must remain in every future rewrite of this handoff unless the user explicitly changes it.

### Maintenance policy

Update this handoff at the end of **every turn**. The update must keep current:

1. **Next steps for the next turn** under the `turn-based-coding-agent` skill, including the exact turn type and the authoritative next plan/report needed to resume from a clean slate.
2. **Quick references to important policies, skills, design, architecture, testing, task, and regression documents** required for the next agent to work correctly without duplicating their contents.

Mandatory policy references:

- `.agents/Directional/CLEAN_UP_POLICY.md` — stale-evidence cleanup lifecycle and cleanup verification.
- `.agents/Directional/RETENTION_POLICY.md` — durable-document retention, handoff/changelog ownership, evidence retention, and destructive-mutation authorization.
- `.agents/Directional/GitHub_Workflow_Policy.md` — GitHub Actions execution boundaries, artifact authority, workflow/trigger/payload lifecycle, failure handling, and workflow-specific hygiene.

Mandatory skill/reference categories to keep discoverable from the handoff when relevant to the active work:

- `turn-based-coding-agent` skill: `https://github.com/akashskypatel/turn-based-coding-agent-skill`.
- `TODO.md` for the unified durable task index.
- Current authoritative next-turn plan and current immutable report.
- `.agents/Directional/DESIGN.md` and `.agents/Directional/REORIENTATION_PLAN.md`.
- `.agents/Directional/Regression_Root_Cause_Tracker.md`.
- `tests/TESTING_STRATEGY.md`.
- `.agents/Directional/CHANGELOG.md` for completed historical changes and immutable acceptance checkpoints.

### Anti-bloat policy

Keep this handoff narrowly focused on what a new agent needs to resume the **current** work. Do **not** add information irrelevant to bringing the next agent up to speed.

Specifically, do not add:

- diffs or long code/document excerpts;
- duplicated information already documented in referenced policies, plans, reports, design/architecture documents, trackers, `TODO.md`, or the changelog;
- verbose test or benchmark result details when a concise current-authority statement and report reference are sufficient;
- generic procedural information already defined by the `turn-based-coding-agent` skill or dedicated policy documents;
- transcripts, chronological play-by-play, tool-call history, or exhaustive descriptions of actions taken;
- superseded milestone narratives, old artifact tables, historical acceptance logs, or other changelog material;
- any other excessively verbose information that does not materially help a clean-slate agent execute the next turn correctly.

Prefer concise current-state statements plus direct references to authoritative documents. Move completed historical change information to `CHANGELOG.md`, keep the actionable backlog in `TODO.md`, retain detailed evidence in the authoritative report/tracker where it belongs, and keep only unresolved or immediately resume-critical facts in this handoff.

## Mandatory start-of-turn checklist

This is a DURABLE mandatory start-of-turn checklist that must be followed at the start of every turn. Do not delete this checklist.

1. Review the `turn-based-coding-agent` skill if not already reviewed: `https://github.com/akashskypatel/turn-based-coding-agent-skill`.
2. Fully review this handoff document.
3. Review and strictly follow `.agents/Directional/RETENTION_POLICY.md` for the whole turn.
4. Review and follow `.agents/Directional/GitHub_Workflow_Policy.md` for the whole turn when using GitHub Actions or temporary workflow/trigger/payload state.
5. Review `TODO.md` and the design/architecture/testing documents relevant to the next step, especially `DESIGN.md` and `REORIENTATION_PLAN.md` for architecture migration work.

## Mandatory next turn

Run **M1l Phase-Front Cell Topology-Region Consumer — immutable Artifact-Only Test + Benchmark only** under:

`.agents/Directional/Architecture_M1l_Phase_Front_Cell_Topology_Region_Consumer_Artifact_Only_Test_Benchmark_Plan.md`

Repository: `akashskypatel/Directional`, branch `agent/surface_cell_quad/p5-recover-bridge-healing`. Draft PR #8 stays open, draft, and unmerged. Product gate **G4 topology-distinct completion and singularities** remains active. Architecture slices M1a through M1k are immutable accepted. Review policy is `never`.

Consume only M1l implementation `bd140cff4572412e6f4ecd70a6ce0fe85310932c` from exact Code + Build artifacts `9083262395 / 9083262833`. Their outer ZIP SHA-256 values are `3d79b86dbda5e87134aef79330d02c227e0c1ba1f291f24bff6a3946c1aa895c / a638cf52e9761ddead175aa32aa6824703c98c4553f97c0627e81baa82b3f1b8`.

This turn is artifact-only: do not edit source/tests/build/fixtures, rebuild, relink, configure, regenerate, substitute/repair package contents, alter executable permissions, or create fixture symlinks. Use the exact plan for preflight, discovery, M1l **6/6**, entering preservation, required-green **211/211**, independent product gates, known-red classification, timing characterization, bounded Bunny/Vase comparison, and exact postflight.

Current Code + Build report:
`.agents/Directional/Architecture_M1l_Phase_Front_Cell_Topology_Region_Consumer_Code_Build_Report.md`.

Authoritative next plan:
`.agents/Directional/Architecture_M1l_Phase_Front_Cell_Topology_Region_Consumer_Artifact_Only_Test_Benchmark_Plan.md`.

## Current immutable authority

M1k implementation `b9181364926cea840e9cb50da21fe721f33fd874` remains the current immutable semantic authority: producer **220**, M1k **6/6**, required-green **205/205**, full entering preservation, and required representative products accepted. Exact historical acceptance detail is retained in `CHANGELOG.md` and the regression tracker.

Strict-validator timing remains the existing nondeterministic sub-millisecond ratio/microbenchmark defect. Bunny remains `NotProductionReady:completion traceSegments=170831 arrangementCells=0 completedQuads=0`; Vase remains bounded safety-only at 60 seconds. No stable product regression event or recurrence was created; historical totals remain **34 events / 14 categories / 20 recurrences**, and `PR8-R034 / G4-R007` remains active.

M1l Code + Build is complete but **not semantically accepted**. Its current immutable package authority is run/job `31441661026 / 93627457924`, artifacts `9083262395 / 9083262833`, manifest **56/56**, and producer SHA-256 `fe7da9a182c785ae14ba24264682470cce7ceec119ce34251a4bee80c7113856`.

Repository-side cleanup is complete: the only retained per-turn files are the M1l Code + Build report and the M1l artifact-only next-turn plan; temporary M1l workflows, triggers, and payloads are removed, and only `.github/workflows/agent-source-snapshot.yml` remains durable.

## Mandatory end-of-turn checklist

This is a DURABLE mandatory end-of-turn checklist that must be followed at the end of every turn. Do not delete this checklist.

1. Review and apply `.agents/Directional/CLEAN_UP_POLICY.md`.
2. Update `TODO.md` to reflect completed, active, newly unblocked, or newly deferred tasks.
3. Update `.agents/Directional/CHANGELOG.md` when the turn creates a completed durable implementation/acceptance change; do not add empty or procedural-only entries.
4. Update this handoff with the exact next turn and current resume-critical state while following the anti-bloat policy.
5. Add the final summarized closing comment to the active pull request after all other branch/PR writes required by the turn.

## Standing product and regression state

- Product gate **G4 topology-distinct completion and singularities** remains active and separate from architecture migration.
- `PR8-R034 / G4-R007` / `G4-B001` remains the active direct-torus `LocalSheetMismatch` blocker.
- `G4-B002` shared hard-rail scheduling, `G4-B003` nonzero periodic Z4 capability, and `G4-B004` positive multi-isolation witness remain unresolved.
- M1a through M1k architecture acceptance does not claim G4 product completion.

## Resume-critical execution lessons

- Use exact M1l artifact `9083262395` as the only next-turn runtime package; later documentation/control-plane commits are not runtime-evidence commits.
- The first M1l compile exposed one stale raw test assertion; the corrected code subsequently compiled **121/121**. A later packaging attempt failed only because shallow history omitted the semantic diff base; the authoritative package explicitly fetched that base before manifest creation.
- A single local Cylinder harness stall did not reproduce in immediate bounded local execution or controlled remote runs. Do not add product workarounds for it without new product evidence.

Workflow-specific execution rules and lessons are maintained in `.agents/Directional/GitHub_Workflow_Policy.md`.

## Core references

- `TODO.md`;
- `.agents/Directional/Architecture_M1l_Phase_Front_Cell_Topology_Region_Consumer_Code_Build_Report.md`;
- `.agents/Directional/Architecture_M1l_Phase_Front_Cell_Topology_Region_Consumer_Artifact_Only_Test_Benchmark_Plan.md`;
- `.agents/Directional/CHANGELOG.md`;
- `.agents/Directional/CLEAN_UP_POLICY.md`;
- `.agents/Directional/RETENTION_POLICY.md`;
- `.agents/Directional/GitHub_Workflow_Policy.md`;
- `.agents/Directional/DESIGN.md`;
- `.agents/Directional/REORIENTATION_PLAN.md`;
- `.agents/Directional/Regression_Root_Cause_Tracker.md`;
- `tests/TESTING_STRATEGY.md`.
