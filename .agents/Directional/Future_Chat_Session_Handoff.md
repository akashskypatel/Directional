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
| Currency | 2026-10-19, after `M6-CP3-TB16-R10-EXACT-I-ENDPOINT-WITNESS-CHECKERS-REV` (RA-98). CB16 code is accepted. The TB16 #3 falsifier is an owned Review spec defect: the mutation produced the other valid orientation image of 1/5, which A4 accepts. CB16A corrects that one test row. B3 is cleared on the three measured identities, which now stop at B2. |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 draft; refetch HEAD before mutation. Latest semantic source is `1c45e89ae0ca7a072c5140aea2b95be6387ec078` (CB16). The CB16 package is `12154623660` (ZIP `821edfc6653af356c902d2debedc065a0ee6b51d287c27bdfd0679ef3a619956`). |
| Last accepted semantic runtime | M6 CP2 **491/491**, package `11391685901`, source `5ce3132ec01748eff5b15f82be07a1abe2bd1af6`. The R3 baseline (403/497) is `Architecture_M6_CP3_TB1_Entry_R3_Red_Classification.tsv`. |
| Latest candidate or rejected evidence | TB16 [run 39246335010](https://github.com/akashskypatel/Directional/actions/runs/39246335010), result `12183498229` (ZIP `8a329317…2dc32`): 6 PASS / 6 RED.<br>• #3 RED is the spec defect (RA-98.2).<br>• #8/#9 are byte-identical to TB15.<br>• #10–#12 now stop at B2: front 97/283, vertex 4.<br>Report: `Architecture_M6_CP3_TB16_Exact_I_Witness_Checkers_Harvest_Report_20261019.md`. The latest full census is still TB14A, **425/497**. |
| Regression accounting and debt | **66/17/49**, debt **1**, selector 497 frozen; R3 403/497 rejected; no production regression. Fixture debt covers 174, 191, 242, 442, 250 and the adjacent-sheet helper (RA-96.6 order). |
| Active boundary | `RP-01` (RA-87.3):<br>• B1 is cleared.<br>• B3 (U6) is implemented by CB15/CB16 and cleared on `cp3entry:2/6` and selector 217; TB16C measures the other 16.<br>• B2 (R endpoint at rail vertex 4) is U4/U5 = CB17/CB18; its spec is re-derived from the TB16C census.<br>`RP-02` UNREACHED; Gate C suspended. |

## Mandatory next turn — `M6-CP3-CB16A-R10-EXACT-I-WITNESS-UNBOUND-ROW` — EXACT NEXT

- **Type:** Code + Build, **test-only**, compile only. No production line changes; no test execution, TB dispatch or census.
- **Authority:** RA-98.4 in `Architecture_M6_CP3_DEFN_U6_Exact_I_Origin_Review_Decision.md`. Line numbers are at `1c45e89a`.
- **Scope:** `ExactWitnessUnboundFailsClosedAndMixedKeepsLegacy` (P10:9444; the `corrupted` row is at P10:9461-9464):
  1. `forwardInFace3 = accepted_boundary_trace_point(faces, 3, 1, 4, *p, edge)`; assert present.
  2. Mutate with `std::nextafter(corrupted.barycentric[2], 0.0)` (gives `0x1.9999999999997p-3`). Before the two existing `EXPECT_FALSE` rows, assert that the corrupted slot 2 differs bit for bit from slot 2 of both `*reverse` and `*forwardInFace3`. Keep both `EXPECT_FALSE` rows.
  3. Add the accepted image-swap property: `otherImage = *reverse` with `otherImage.barycentric = forwardInFace3->barycentric`, keeping the witness. Then `EXPECT_TRUE` for `exact_interior_witness_binds(otherImage, …)` and for `same_interior_carrier_point(*reverse, otherImage, …)`.
  4. No other row, test or production line changes.
- **Build:** GMP/GMPXX compile and package. Record of 25 lines or fewer: package ID, ZIP SHA-256, source SHA, `runtimeExecution=false`.
- **Stop:** if the change needs any line outside this test, stop and report.
- **Docs:** in place only (handoff live sections, top `TODO.md` section, one `CHANGELOG.md` entry).
- **STATUS:** `IN_PROGRESS` with an empty Successor while working; `COMPLETE` with the successor below as the final write.
- **Conditional successor:** `M6-CP3-TB16A-R10-EXACT-I-ENDPOINT-WITNESS-CHECKERS` (RA-98.5): the TB16 harness, changing only sha, artifact, digest and labels, with the same 12 identities. #1–#7 PASS; #8–#12 byte-identical to TB16. Nothing beyond it is authorized.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| done | `M6-CP3-CB16-R10-EXACT-I-ENDPOINT-WITNESS-CHECKERS` | Checker rule (RA-97.4). |
| done | `M6-CP3-TB16-R10-EXACT-I-ENDPOINT-WITNESS-CHECKERS` | #3 RED (spec defect); B3 → B2 on 10–12. |
| done | `M6-CP3-TB16-R10-EXACT-I-ENDPOINT-WITNESS-CHECKERS-REV` | RA-98: CB16 accepted; CB16A specified. |
| 1 — next | `M6-CP3-CB16A-R10-EXACT-I-WITNESS-UNBOUND-ROW` | Test-only, compile only (RA-98.4). |
| 2 — conditional | `M6-CP3-TB16A-R10-EXACT-I-ENDPOINT-WITNESS-CHECKERS` | 12 identities (RA-98.5). A falsifier goes to Review. |
| 3 — conditional | `M6-CP3-TB16C-R10-SELECTOR-497-CENSUS` | Only if TB16A holds. Run on the CB16A package with the unchanged 497 harness; compared with TB14A (RA-97.5, RA-98.5). |
| 4 — conditional | `M6-CP3-TB16C-R10-SELECTOR-497-CENSUS-REV` | Re-derives and issues the CB17 (U4) spec from the census. |
| planned, not authorized | CB17 → TB17 → CB18 → TB18 → fixture debt (242 → 174 → 250 → adjacent-sheet → 191 → 442) → census → RP-01 Review | Each CB follows a reviewed TB; a RED TB goes to Review. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **code_build** — CB16A test-only row correction at `1c45e89a`; no test execution.

Minimum context after mandatory policies/checklists: `.agents/Directional/ORIENTATION.md`, `.agents/Directional/ROADMAP.md`, this handoff, RA-97/RA-98 (`Architecture_M6_CP3_DEFN_U6_Exact_I_Origin_Review_Decision.md`), `tests/SurfaceCellsPhase10Tests.cpp` P10:9370-9480, `src/geometry/SurfaceCellTracing.cpp` S:60-191, `LESSONS.md` §2 and §7, `TODO.md`.

**Review tooling:** `.agents/Directional/tools/` holds read-only `review_check.py`, `selector_probe.py`, and `fixture_probe.py`; history-sensitive review gates require real committed history, not a synthesized snapshot.

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
