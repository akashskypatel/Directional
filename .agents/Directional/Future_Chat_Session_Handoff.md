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

Run **M1 Single-Authority Cutover — Code + Build only** under:

`.agents/Directional/Architecture_M1_Single_Authority_Cutover_Code_Build_Plan.md`

Repository: `akashskypatel/Directional`, branch `agent/surface_cell_quad/p5-recover-bridge-healing`. Draft PR #8 stays open, draft, and unmerged. Reviewed source authority is M1l implementation `bd140cff4572412e6f4ecd70a6ce0fe85310932c`; review baseline is `fcba2fd9b8905802ca373e0cc88aeccbf38d608a`; authoritative planning commit is `7054eb7add540b35b9892ee18b1488d8bcaa9514`. Product gate **G4 topology-distinct completion and singularities** remains active. M1a through M1l remain immutable accepted evidence. Review policy after the following Test + Benchmark turn is `never`.

The final cutover replaces the complete affected authority contracts in one turn:

- checked strong-ID ingress with numeric projection only at direct storage/export leaves;
- one typed topology-region product consumed by cells, edges, relations, certificates, occurrences, and materialization;
- a fully typed isolation-seam certificate;
- one chart, source-support, route, and periodic-transport representation;
- one exhaustive producer outcome;
- deletion of displaced fields, helpers, aliases, and representation-only tests.

Preserve G0–G3 semantic invariants, truthful typed failures, deterministic identity, strict direct disposition, and no fallback. The M1l artifact is comparison evidence, not a requirement to reproduce raw numbering, hashes, row order, or known-incomplete product output. Classify semantic differences under the plan.

This is **Code + Build only**. Execute no generated Directional binary, GoogleTest discovery/list command, test, benchmark, `ctest`, CLI/GUI/help/version command, fuzzer, or custom input. Compile and package the complete final cutover. Do not predeclare discovery totals; the following artifact-only turn discovers and validates the actual semantic inventory.

Current immutable report:
`.agents/Directional/Architecture_M1l_Phase_Front_Cell_Topology_Region_Consumer_Artifact_Only_Test_Benchmark_Report.md`.

Authoritative next plan:
`.agents/Directional/Architecture_M1_Single_Authority_Cutover_Code_Build_Plan.md`.

## Current immutable authority

M1l implementation `bd140cff4572412e6f4ecd70a6ce0fe85310932c` is immutable accepted from Code + Build artifacts `9083262395 / 9083262833` and artifact-only runtime `31444022339 / 93634344918`, with runtime evidence/log artifacts `9083913766 / 9083913939`. Producer authority is **226** discovered, M1l **6/6**, required-green **211/211**, all M1k-M1b focused preservation green, M1d/M1c counterexamples **3/3 + 3/3**, validation **77/77**, M1a **14/14**, T1 **29/29**, and Plane/MultiFaceSeam/CloseSheets/Cylinder independent-oracle clean. All eight historical/deferred red classifications and exact **56/56** postflight were preserved.

Strict-validator timing sampled **10/10 pass** but remains the existing nondeterministic sub-millisecond ratio/microbenchmark defect. Bunny remains `NotProductionReady:completion traceSegments=170831 arrangementCells=0 completedQuads=0`; Vase remains bounded safety-only at 60 seconds. No stable product regression event or recurrence was created; historical totals remain **34 events / 14 categories / 20 recurrences**, and `PR8-R034 / G4-R007` remains active.

Repository-side per-turn retention is clean: `.agents/Directional` retains the current M1l immutable Test + Benchmark report and the single final-cutover next-turn plan in addition to durable documents. The rejected unimplemented one-field plan is removed. Temporary M1l workflows, triggers, and payloads are absent; only `.github/workflows/agent-source-snapshot.yml` remains durable.

## Mandatory end-of-turn checklist

This is a DURABLE mandatory end-of-turn checklist that must be followed at the end of every turn. Do not delete this checklist.

1. Review and apply `.agents/Directional/CLEAN_UP_POLICY.md`.
2. Update `TODO.md` to reflect completed, active, newly unblocked, or newly deferred tasks.
3. Update `.agents/Directional/CHANGELOG.md` when the turn creates a completed durable implementation/acceptance change; do not add empty or procedural-only entries.
4. Update this handoff with the exact next turn and current resume-critical state while following the anti-bloat policy.
5. Add the final summarized closing comment to the active pull request after all other branch/PR writes required by the turn.

## Standing product and regression state

- Product gate **G4 topology-distinct completion and singularities** remains active; it becomes the primary queue again after immutable M1 cutover acceptance.
- `PR8-R034 / G4-R007` / `G4-B001` remains the active direct-torus `LocalSheetMismatch` blocker.
- `G4-B002` shared hard-rail scheduling, `G4-B003` nonzero periodic Z4 capability, and `G4-B004` positive multi-isolation witness remain unresolved.
- M1a through M1l acceptance and the planned cutover do not claim G4 product completion.

## Resume-critical execution lessons

- Use exact accepted M1l implementation/package/runtime authority above; later documentation/control-plane commits are not runtime-evidence commits.
- One local first-process Cylinder stall did not reproduce in the immediate bounded local retry or authoritative remote artifact-only run. Do not add a product workaround without new product evidence.
- Do not answer a compile failure by restoring a displaced numeric field/helper/alias. Migrate the affected consumer within the same turn or stop only at a plan-defined genuine blocker.
- Preserve test intent with distinct typed witnesses and semantic assertions. Remove raw-conversion assertions; do not weaken fixtures, failures, product oracles, or known-red reporting.
- Treat M1l output differences as evidence to classify. Required invariant regressions block; representation changes and earlier truthful failures do not automatically require reproducing old internals.

Workflow-specific execution rules and lessons are maintained in `.agents/Directional/GitHub_Workflow_Policy.md`.

## Core references

- `TODO.md`;
- `.agents/Directional/Architecture_M1l_Phase_Front_Cell_Topology_Region_Consumer_Artifact_Only_Test_Benchmark_Report.md`;
- `.agents/Directional/Architecture_M1_Single_Authority_Cutover_Code_Build_Plan.md`;
- `.agents/Directional/CHANGELOG.md`;
- `.agents/Directional/CLEAN_UP_POLICY.md`;
- `.agents/Directional/RETENTION_POLICY.md`;
- `.agents/Directional/GitHub_Workflow_Policy.md`;
- `.agents/Directional/DESIGN.md`;
- `.agents/Directional/REORIENTATION_PLAN.md`;
- `.agents/Directional/Regression_Root_Cause_Tracker.md`;
- `tests/TESTING_STRATEGY.md`.
