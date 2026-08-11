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

Run **M1 Single-Authority Cutover — Artifact-Only Test + Benchmark** under:

`.agents/Directional/Architecture_M1_Single_Authority_Cutover_Artifact_Only_Test_Benchmark_Plan.md`

Repository: `akashskypatel/Directional`, branch `agent/surface_cell_quad/p5-recover-bridge-healing`. Draft PR #8 stays open, draft, and unmerged. Exact packaged implementation is `5b1c9b314ae1ff2888abf1b81d716a44e63ea45e`; entering immutable comparison authority is M1l implementation `bd140cff4572412e6f4ecd70a6ce0fe85310932c`. Product gate **G4 topology-distinct completion and singularities** remains active but does not resume until M1 artifact-only acceptance. Review policy is `never`.

Consume exact Code + Build result artifact `9105462679` (`m1-single-authority-cutover-code-build-result-31501276992`, digest `sha256:f73f6e02ff7cb3254dce46694af460d3703c7869985bcb69648eb528db9c6ad2`) without rebuilding or modifying the package. Code + Build log artifact is `9105463175`. The recursive package manifest is **57/57** with SHA-256 `ebd5f1587feec0120260eacd127f45fcf66784f5effaf1a60703e7471f9454b4` and contains 27 fixture files.

The next turn must independently discover the packaged test inventory; run the five new cutover semantic contract groups, entering M1a–M1l preservation gates, route/transition counterexamples, T1, validation/compiled API/required-green producer coverage, and Plane/MultiFaceSeam/CloseSheets/Cylinder independent product oracles; execute and classify all historical/deferred reds; characterize strict-validator timing and bounded Bunny/Vase; repeat the packaged-source duplicate-authority audit; and close with immutable postflight. Do not predeclare a test total.

If all required semantic gates pass with no unclassified product regression and the static source audit remains clean, close M1 and return directly to G4. Do not open another M1 letter slice. If M1 fails, create one bounded Code + Build plan only for the proven semantic/source-authority defect; do not restore displaced raw mirrors/adapters.

Current Code + Build report:
`.agents/Directional/Architecture_M1_Single_Authority_Cutover_Code_Build_Report.md`.

Authoritative next plan:
`.agents/Directional/Architecture_M1_Single_Authority_Cutover_Artifact_Only_Test_Benchmark_Plan.md`.

## Current immutable authority

M1l implementation `bd140cff4572412e6f4ecd70a6ce0fe85310932c` remains the latest immutable runtime-accepted authority until the next artifact-only turn completes. Its accepted runtime preserved the existing required-green semantic/product baselines, direct Plane/MultiFaceSeam/CloseSheets/Cylinder oracles, all historical/deferred red classifications, and exact postflight as recorded durably in `CHANGELOG.md`.

The final M1 cutover implementation `5b1c9b314ae1ff2888abf1b81d716a44e63ea45e` is **compile-valid and packaged, not runtime-accepted yet**. Final package run/job `31501276992 / 93811595735` compiled **121/121** approved steps in Release/static/Ninja/PRE_TEST, with all generated-runtime/test/benchmark/discovery/ctest/CLI/fuzzer/custom-input flags false. The source-only cutover audit was clean for every displaced symbol and legacy domain-error term required by the plan. Exact evidence is retained in `.agents/Directional/Architecture_M1_Single_Authority_Cutover_Code_Build_Report.md` and external Actions artifacts `9105462679 / 9105463175`.

Strict-validator timing remains the existing nondeterministic sub-millisecond ratio/microbenchmark defect. Bunny and Vase remain characterization/product gates rather than M1 success requirements unless the cutover introduces a required-invariant regression or unexplained semantic drift. Historical regression totals remain **34 events / 14 categories / 20 recurrences**, and `PR8-R034 / G4-R007` remains active.

Repository-side Code + Build execution state is clean: consumed M1 cutover workflows were retired before their trigger markers/payloads, then consumed triggers/payloads were removed. Only the durable `.github/workflows/agent-source-snapshot.yml` remains. The packaged implementation commit remains separate from later documentation/cleanup commits; do not relabel later handoff/control-plane commits as build evidence.

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
- M1a through M1l acceptance and the final cutover Code + Build do not claim G4 product completion.

## Resume-critical execution lessons

- Validate exact artifact `9105462679` from implementation `5b1c9b...`; later documentation/cleanup commits are not runtime-evidence commits.
- Preserve the artifact's natural executable mode bits during extraction. Do not `chmod` or repair the immutable package.
- A zero-selected GoogleTest filter is an orchestration failure, never a semantic pass. Independently discover exact names before focused execution.
- Do not answer a semantic failure by restoring a displaced numeric field/helper/alias. Classify representation changes versus invariant regressions under the next-turn plan.
- Preserve test intent with distinct typed witnesses and semantic assertions; do not weaken fixtures, failures, product oracles, or known-red reporting.
- One local first-process Cylinder stall in prior M1 evidence did not reproduce in immediate retry or authoritative remote runs. Do not add a product workaround without new reproducible product evidence.

Workflow-specific execution rules and lessons are maintained in `.agents/Directional/GitHub_Workflow_Policy.md`.

## Core references

- `TODO.md`;
- `.agents/Directional/Architecture_M1_Single_Authority_Cutover_Code_Build_Report.md`;
- `.agents/Directional/Architecture_M1_Single_Authority_Cutover_Artifact_Only_Test_Benchmark_Plan.md`;
- `.agents/Directional/CHANGELOG.md`;
- `.agents/Directional/CLEAN_UP_POLICY.md`;
- `.agents/Directional/RETENTION_POLICY.md`;
- `.agents/Directional/GitHub_Workflow_Policy.md`;
- `.agents/Directional/DESIGN.md`;
- `.agents/Directional/REORIENTATION_PLAN.md`;
- `.agents/Directional/Regression_Root_Cause_Tracker.md`;
- `tests/TESTING_STRATEGY.md`.