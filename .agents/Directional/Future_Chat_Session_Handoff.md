---
Turn: M4-CP-COND-TB4-REV
Status: COMPLETE / SELECTOR422 + PACKAGE ACCEPTED / CP-COND OPEN ON BOUNDARY RAW-PRECONDITION; M4 OPEN
Repository: akashskypatel/Directional
Working branch: agent/surface_cell_quad/p5-recover-bridge-healing
PR: 8, open / draft / unmerged
Canonical next turn: M4-CP-COND-CB5
---


# Future Chat Session Handoff — Directional

## Purpose — DURABLE, DO NOT DELETE

This file contains durable operating policy, the exact next action, current immutable authority, standing product state, and resume-critical blockers/lessons required to continue safely. Architecture belongs in `DESIGN.md` and `REORIENTATION_PLAN.md`; tasks belong in `TODO.md`; completed history belongs in `CHANGELOG.md`; current exact runtime evidence belongs in the retained latest report/closure records and regression tracker.

This section is durable. It may be corrected or extended, but it must not be deleted, collapsed into another section, or replaced by a summary without explicit user authorization.

All instructions and sections prefixed with `[ChatGPT Web]` are mandatory for all `ChatGPT Web` sessions and must be followed exactly as written.
All non-`ChatGPT Web` agents, i.e. `ChatGPT Work`, `Codex`, `Claude`, etc., can safely ignore any instruction or section prefixed with `[ChatGPT Web]`.



## Authoritative Pre-Turn Documents — DURABLE, DO NOT DELETE

These documents must be read in full at start of every turn.

| Document | Purpose |
| ------- | -------- |
| [.agents\Directional\Durable_Handoff_Policy.md](.agents/Directional/Durable_Handoff_Policy.md) | Durable handoff policy |
| [.agents\Directional\Mandatory_Start_Checklist.md](.agents/Directional/Mandatory_Start_Checklist.md) | Mandatory start-of-turn checklist |
| [.agents\Directional\Mandatory_End_Checklist.md](.agents/Directional/Mandatory_End_Checklist.md) | Mandatory end-of-turn checklist |
| [.agents\Directional\Patch_Application_Strategy.md](.agents/Directional/Patch_Application_Strategy.md) | Patch application strategy |
| [.agents\Directional\Turn_Cadence.md](.agents/Directional/Turn_Cadence.md) | Turn cadence |

## Current authority

- Repository: `akashskypatel/Directional`
- Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`
- PR: #8, open/draft/unmerged.
- Accepted current M4 runtime authority: package `10327643907`, packaged semantic source `702d9e10afff1fc3ac2ed3f3458acf8f19b617a5`.
- Accepted cumulative selector: `Architecture_M4_CP_COND_CB4_Required_Green_Selector_422.txt`, **422/422**, SHA-256 `bbd496f3396bd656d13c728ddaad806276e00b901675255e0b67241beec4f7cc`.
- Accepted predecessor selector408 is preserved byte-for-byte as rows1-408, SHA-256 `c689c0cd8a51f9a8bd8c9ed3a2e8b603728d5a0359ee2732f776a422744b0484`.
- Stable accounting: **49 events / 14 categories / 35 recurrences**, produced-witness debt **5**.
- M4-CP3 is CLOSED / ACCEPTED. M4-CP-COND remains OPEN.

## TB4 Review decision

TB4-EXEC immutable evidence is accepted: selector422 **422/422 PASS**, predecessor408 **408/408 PASS**, appended CP-COND gates **14/14 PASS**, one expected report-only boundary SKIP, zero gating RED/timeout/selection mismatch and exact byte+mode postflight. TB4's non-self-referential checksum manifest verifies completely.

This closes:

- `M4-CP-COND-TB3-REV-CAND-01` — selector-authority publication gap, recovery proved;
- `M4-CP-COND-TB3-REV-OBS-01` — evidence-manifest self-hash, repaired.

Selector422/package authority is promoted, but CP-COND does **not** close.

## Remaining CP-COND blocker

Frozen §10/§12 conjunct 4 requires a boundary-truncated separatrix **raw precondition independently proved before production execution**, plus conditioner preservation of the authority used by that proof.

The current report-only test does not prove this; it explicitly returns false and SKIPs. The alternate 'genuinely unreachable' path is not available: accepted inherited A2a tests already demonstrate singularity-port traces terminating on mandatory barriers on an open disc with no hard-feature edges, so those barriers are genuine source boundaries. That production observation proves the behavior class is reachable, but it cannot serve as the independent pre-production oracle.

## Exact next — `M4-CP-COND-CB5`

Read and obey `.agents/Directional/Architecture_M4_CP_COND_CB5_Code_Build_Plan.md`.

CB5 is test-authority + selector-publication only, runtime-free:

1. Build one raw boundary-truncation witness and a test-local exact/discrete oracle that proves the route/locus before calling the conditioner and without using production A1/A2a output.
2. Add a load-bearing raw mutation falsifier.
3. Require conditioner `Produced` and re-prove the same oracle on the conditioned raw view/certificate-preserved data.
4. Gate identity is frozen as `InputConditionerCPCondCB5.BoundaryTruncatedSeparatrixRawPreconditionIsIndependentAndPreserved`.
5. Publish selector423 = exact accepted selector422 prefix + that one row. First422 hash must remain `bbd496f3...f7cc`; expected owner census **30 / 277 / 75 / 41**.
6. No `src/`/`include/` product semantic change is authorized. Minimal test/CMake ownership metadata only.
7. Compile/package the complete seven-target GMP/GMPXX owner set with `runtimeExecution=false`; no Directional runtime.
8. Freeze artifact-only TB5 plan: selector423 423/423, exact postflight, mandatory TB5 Review.

STOP if independent proof needs production tracing output, epsilon/proximity authority, production changes, selector weakening/reordering, or cannot be falsified by a raw mutation.

## Mandatory documents

- `.agents/Directional/TOOL_USE_CONSERVATION_POLICY.md`
- `.agents/Directional/GitHub_Workflow_Policy.md`
- `.agents/Directional/AGENT_POLICY.md`
- `.agents/Directional/Mandatory_Start_Checklist.md`
- `.agents/Directional/Mandatory_End_Checklist.md`
- `.agents/Directional/RETENTION_POLICY.md`
- `.agents/Directional/CLEAN_UP_POLICY.md`
- `.agents/Directional/LESSONS.md`
- `.agents/Directional/Architecture_M4_CP_COND_Frozen_Definitions.md`
- `.agents/Directional/Architecture_M4_CP_COND_TB4_Review_Record.md`
- `.agents/Directional/Architecture_M4_CP_COND_CB5_Code_Build_Plan.md`
- `.agents/Directional/Required_Green_Selector_Manifest.md`
- `.agents/Directional/Regression_Root_Cause_Tracker.md`
- `TODO.md`

## Carried obligations

- `M4-CP3-TB1-R1-REV-OBS-01`: same-region multiplicity-2 independent oracle before CP4; CB5 may discharge only if naturally covered, never by distorting the boundary witness.
- `M4-CP3-CB4-REV-OBS-02`: row399 path/`sourceFaces` divergence tamper, next legitimate row399 touch.
- TB3 row408 provenance: historical-claim bound.
- `G4-B002`: 3 produced-witness debts, M4-CP4.
- `G4-B003`: 2 debts, M5.
- CP-SCALE remains blocked until CP-COND closes.
