# TB-REV-186 adversarial continuation (2026-11-26 UTC)

Continues `M6-CP3-TB-REV-186` after the [independent review](Architecture_M6_CP3_TB_REV_186_P13_Activated_Sphere_Full_Gate_Independent_Review_20261126.md). Runtime-free. My own work was a static review of the CB-209 oracle. Haiku did the rest, read-only:
- traced where the completion `PreparationRejected` detail is stored;
- ran syntax-only checks of CB-209 and the new CB-210, each in a throwaway `CLAUDE_` worktree that has since been removed.

Product and test bytes are unchanged.

## Verdict

- **Upheld:** TB186 is a valid semantic RED at 1005/1006, with no gate credit.
  - The 26 material rows all add copies of the same 14 sphere region records, which is plan reach, not a product regression.
  - Row 971 is a test-premise defect, not a product failure: it treated source slide segments and clipped arc occurrences as the same thing.
- **Upheld: CB-209** (`6f17d7c8…fcc4`). It is now syntax-clean (AA1).
- **Realigned: the order after the gate.** TB-REV-186 put the completion-failure receipt after another valid gate. That costs an extra full CB → gate → review cycle just to learn a string the pipeline already stores. **CB-210** is a two-line, print-only receipt and goes before the single gate (AA2).

## Findings

**AA1 — CB-209 is sound and syntax-clean, but it pins observed values.**
- Syntax-only check of the full test file: 0 errors and 45 warnings before and after, the same set, none in the patched hunks. TB-REV-186 had not run this check, which is the Z1 lesson again. This is not compile evidence.
- **Logic:**
  - The split fraction comes from the trace records: the moving trace's `terminalContact` carrier locus, and the wall segment's entry and exit parameters. It is not taken from `build_arcs`.
  - `arcEnd` gives a prefix arc's reverse end a parameter, so that end is no longer a `slideArcEnd`. That removes the false `atVertex` premise at 0:6, and the ten vertex-end rays still balance: four suffixes replace four whole slides.
  - The edge-piece endpoints and the cut-node `struckParameter` are checked against the oracle point and fraction.
- **Limit:** the four exact rationals and the node IDs are pinned from the row 963/978 witnesses. That is a cross-representation oracle (trace records against the arc builder and cut binding), not an independent geometric derivation. It is acceptable for a fixture test; it gives no evidence that the contact parameters themselves are right.

**AA2 — The completion branch can be identified now, so measure it in the same gate.**
- `RemeshPipeline.cpp:14156–14159` stores `closedCompletionFailure->detail` unconditionally in `SurfaceCellPipelineContext::completionFailure` (`RemeshPipeline.h:539`; public `RemeshResult::surfaceCellContext`, `:745`).
- The terminal detail code is only the kind name, `PreparationRejected`, so the `completionFailure` string is what tells the sites apart. Every `PreparationRejected` producer in `PatchDescriptor.cpp` writes a distinct prefix:

| Line | Detail string |
|---|---|
| `:2563` | `BoundaryParityRepair:UnexpectedNotApplicable` |
| `:2570` | `BoundaryParityRepair:` + sub-detail (e.g. `ParityRepairIncomplete`, `;AlternativeRepairBudgetExhausted;attempted=…`) |
| `:2576` | `BoundaryParityRepair:MissingOutcome` |
| `:2622` | `SideSubdivisionRepair:UnexpectedNotApplicable` |
| `:2629` | `SideSubdivisionRepair:` + sub-detail |
| `:2635` | `SideSubdivisionRepair:MissingOutcome` |
| `:2644` | not reached by default (`PatchDescriptor.h:258`) |
| `:2691` | `NoPatchDescriptors` |

- TB-REV-186's "three branches, stored evidence cannot distinguish them" is wrong. The stored string distinguishes all seven reachable sites and carries the sub-reason. Only the test output omits it.
- **CB-210:** `diff 696efc1e…c488`, +2 lines. It prints `SphereCompletionFailure detail=<completionFailure>` after the CB-208R detail line. It passes a syntax-only check: 0 errors and 27 warnings, the same as HEAD. It changes no other file than CB-209 does, and both diffs apply at HEAD.
- The 69,196-byte row 858 prefix and the `SphereDisplayStopDetail` line are unchanged; the new line is recorded verbatim, not predicted.

**AA3 — Trajectory.**
- Activation is behaving as intended: the cut and plan succeed (V18/E30/F14, 14 regions), and every gated reader except row 971 holds.
- The product blocker is now patch-descriptor preparation in completion.
- The sphere's completion branch should be measured in this gate, not three turns later. The step after TB-REV-188 must be chosen from that measured string; it is not pre-planned here.

**AA4 — Carried.**
- V5 runs only after a valid gate.
- CB-207C/D stay held, since no cap was hit.
- close_sheets at 0.02 stays unmeasured.
- The completion locus gap goes to CB-190; J6/E5 and CP3/497/D0/H4 are held.
- Stable accounting is unchanged at 67/17/50, debt 1, deferred 81. No new stable event.

## Turn sequence

1. `M6-CP3-CB-209-P13-SLIDE-ARC-RAY-ORACLE`: exact diff, compile only.
2. `M6-CP3-CB-210-P13-SPHERE-COMPLETION-FAILURE-RECEIPT`: exact diff on the CB-209 package source, compile only.
3. `M6-CP3-TB-EXEC-188`: full 1006-row gate, then V5, STOP-on-RED, on the CB-210 package. [Contract](gates/Architecture_M6_CP3_CB210_TB188_Completion_Receipt_Activated_Full_Gate_Exact_Manifest.md).
4. `M6-CP3-TB-REV-188`: accept activation if the gate is green, and choose the completion step from the measured `SphereCompletionFailure` string.
5. Then parameter deletion, V3b, R1 and O48. CB-190 stays off the critical path.

## Lessons

- Before deferring a "which predicate fired" question to another cycle, check whether the producer already stores a distinguishing string. If it does, a print-only receipt in the same gate is the cheapest measurement.
- Run a syntax check on every exact diff, including those frozen by the independent review (Z1, AA1).
