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

Run **M1m Isolation-Seam Certificate Topology-Region Consumer — Code + Build only** under:

`.agents/Directional/Architecture_M1m_Isolation_Seam_Certificate_Topology_Region_Consumer_Code_Build_Plan.md`

Repository: `akashskypatel/Directional`, branch `agent/surface_cell_quad/p5-recover-bridge-healing`. Draft PR #8 stays open, draft, and unmerged. Product gate **G4 topology-distinct completion and singularities** remains active. Architecture slices M1a through M1l are immutable accepted. Review policy is `never`.

M1m is bounded to:

`SurfaceTopologyRegion::id / build_isolation_seam_transport_certificates -> SurfaceIsolationSeamTransportCertificate::sourceTopologyRegion -> still-raw materializer/hash compatibility consumers`.

Migrate only certificate-owned topology-region identity to checked `TopologyRegionId`. Preserve `SurfaceTopologyRegion::id`, raw region-by-face maps, periodic/bounded-disk/occurrence/lineage region schemas, topology-region construction/numbering, accepted cell/edge region authority, certificate transport semantics, M2-M6, fallback/recovery, optimization, and G4 behavior.

This is **Code + Build only**. Execute no generated Directional binary, GoogleTest discovery/list command, test, benchmark, `ctest`, CLI/GUI/help/version command, fuzzer, or custom input. Exactly six M1m production-path contracts compile only. Expected following runtime authority is producer **232**, M1m **6/6**, required-green **217/217**, plus all entering preservation gates.

Current immutable report:
`.agents/Directional/Architecture_M1l_Phase_Front_Cell_Topology_Region_Consumer_Artifact_Only_Test_Benchmark_Report.md`.

Authoritative next plan:
`.agents/Directional/Architecture_M1m_Isolation_Seam_Certificate_Topology_Region_Consumer_Code_Build_Plan.md`.

## Current immutable authority

M1l implementation `bd140cff4572412e6f4ecd70a6ce0fe85310932c` is immutable accepted from Code + Build artifacts `9083262395 / 9083262833` and artifact-only runtime `31444022339 / 93634344918`, with runtime evidence/log artifacts `9083913766 / 9083913939`. Producer authority is **226** discovered, M1l **6/6**, required-green **211/211**, all M1k-M1b focused preservation green, M1d/M1c counterexamples **3/3 + 3/3**, validation **77/77**, M1a **14/14**, T1 **29/29**, and Plane/MultiFaceSeam/CloseSheets/Cylinder independent-oracle clean. All eight historical/deferred red classifications and exact **56/56** postflight were preserved.

Strict-validator timing sampled **10/10 pass** but remains the existing nondeterministic sub-millisecond ratio/microbenchmark defect. Bunny remains `NotProductionReady:completion traceSegments=170831 arrangementCells=0 completedQuads=0`; Vase remains bounded safety-only at 60 seconds. No stable product regression event or recurrence was created; historical totals remain **34 events / 14 categories / 20 recurrences**, and `PR8-R034 / G4-R007` remains active.

Repository-side per-turn retention is clean: `.agents/Directional` retains the current M1l immutable Test + Benchmark report and the single M1m next-turn plan in addition to durable documents. The consumed M1l Code + Build report and artifact-only plan have been retired after their necessary facts were preserved in the retained report/changelog/tracker. Temporary M1l workflows, triggers, and payloads are removed; only `.github/workflows/agent-source-snapshot.yml` remains durable.

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
- M1a through M1l architecture acceptance does not claim G4 product completion.

## Resume-critical execution lessons

- Use exact accepted M1l implementation/package/runtime authority above; later documentation/control-plane commits are not runtime-evidence commits.
- One local first-process Cylinder stall did not reproduce in the immediate bounded local retry or authoritative remote artifact-only run. Do not add a product workaround without new product evidence.
- M1m existing wrong-owner certificate coverage must preserve semantic intent after typing: use a genuinely distinct checked topology-region witness when needed rather than manufacturing an ID with a knowingly false extent. Detailed requirements are in the M1m plan.

Workflow-specific execution rules and lessons are maintained in `.agents/Directional/GitHub_Workflow_Policy.md`.

## Core references

- `TODO.md`;
- `.agents/Directional/Architecture_M1l_Phase_Front_Cell_Topology_Region_Consumer_Artifact_Only_Test_Benchmark_Report.md`;
- `.agents/Directional/Architecture_M1m_Isolation_Seam_Certificate_Topology_Region_Consumer_Code_Build_Plan.md`;
- `.agents/Directional/CHANGELOG.md`;
- `.agents/Directional/CLEAN_UP_POLICY.md`;
- `.agents/Directional/RETENTION_POLICY.md`;
- `.agents/Directional/GitHub_Workflow_Policy.md`;
- `.agents/Directional/DESIGN.md`;
- `.agents/Directional/REORIENTATION_PLAN.md`;
- `.agents/Directional/Regression_Root_Cause_Tracker.md`;
- `tests/TESTING_STRATEGY.md`.
