# CB-211R and CB-212 exact manifests and TB-EXEC-189 contract (2026-11-27 UTC)

**Review artifact only.** Frozen by the [TB-REV-188 adversarial continuation](../Architecture_M6_CP3_TB_REV_188_Adversarial_Review_20261127.md), BB1–BB4. It supersedes the [CB-211 prose plan](../M6_Consolidated_Record_Vol_D3_CP3_P13_from_20261109.md#cb-211-prose-plan-withdrawn-historical). Nothing here has been applied, built or run.

**Checks done in Review** (throwaway `CLAUDE_` worktree, since removed):
- `git apply --check`, exact replay and `git diff --check`.
- clang++ `-fsyntax-only`: 0 errors and 27 warnings for the preimage and both postimages, the same set, all in headers. This is not compile evidence.

## `M6-CP3-CB-211R-P13-SPHERE-ROUTE-PLAN-WITNESS` — Code + Build, compile only

- **Diff:** [the diff file](../Architecture_M6_CP3_CB211R_P13_Sphere_Route_Plan_Witness_Exact.diff), 5,170 B, SHA-256 `288e99bf99a72a5ebf370b36ec001f12c0f17db96735a115bbfe537242ab0486`. One path, `tests/SurfaceCellTracingDisplayTests.cpp`, +87/−0.
- **Preimage:** `0089c18ef38298c207a52574fb98ed995c2d65db6bceadea6ea1b5de219bc7a9`, the CB-210 postimage, which equals HEAD.
- **Postimage:** `ae573fe424753dec91ea7f691e9f38efbcb2b69cf5304acb367114acbdf7bdbd`.
- **Change:**
  - Adds `<map>` and `<set>`.
  - Right after `SphereCompletionFailure`, prints one `SphereRoute` line: phase-front outcome, producer disposition, the three declined flags, seed and trace counts.
  - Prints one `SpherePlan` line and one `SpherePlanRegion` line per plan region: boundary arcs, distinct walk nodes, repeated arcs, missing arcs, arc kinds, source faces, disc certificate, interior-singularity-free flag and boundary singularity count.
  - Output only; no assertion is added or changed.
- **CB steps:**
  1. Verify the hashes and that only the one path is touched.
  2. Apply the diff.
  3. Compile the eight CB-210 GMP/GMPXX targets, `runtimeExecution=false`.
  4. STOP on any mismatch. No runtime.

## `M6-CP3-CB-212-P13-SPHERE-COMPLETION-INPUT-CENSUS` — Code + Build, compile only

- **Order:** runs after a successful CB-211R compile, on the CB-211R source. It is a separate turn on the same path.
- **Diff:** [the diff file](../Architecture_M6_CP3_CB212_P13_Sphere_Completion_Input_Census_Exact.diff), 7,718 B, SHA-256 `2483d16a2d5f563681b59267ca7d84cb302e6af84aa77da94ead52a27779545b`. One path, +122/−0.
- **Preimage:** `ae573fe4…dbd`, the CB-211R postimage.
- **Postimage:** `6149b26dc7564342261920c1b669e25dfd61cb3ba323cf844ecff07aa65f16cc`.
- **Change:** right after the CB-211R block, prints:
  - two `SphereCompletionInput` census lines, for the arrangement and the simplified complex;
  - one `SphereSimplification` line;
  - one `SphereCompletionAudit` line;
  - either one `SphereAuditedInputCell` line plus one `SphereAuditedBridge` line per same-cell twin pair, or `SphereAuditedInputCell unavailable`.
  - Output only; no assertion is added or changed.
- **CB steps:** the same as CB-211R. No runtime.

## `M6-CP3-TB-EXEC-189` — full gate on the CB-212 package

- **Inputs:** CB-212 package; harness `423f385b…572c`; manifest `a9b80832…0587` (1006 cases); deferred `fd433f54…64ce`; 1087 members. No rerun, rebuild or timeout substitution. **No V5** (B2 has its own later contract).
- **Comparisons** under frozen N1–N3, against TB188 result `15163822727`:
  - **Row858:** must PASS.
    - Every byte through the LF after `SphereCompletionFailure detail=BoundaryParityRepair:InvalidReplacementBoundary:repeated-boundary-node;AlternativeRepairBudgetExhausted;attempted=106;budget=106` must equal TB188. That is the 69,196-byte prefix `32d6de52…42d9` plus the three receipt lines.
    - The only permitted new lines are those listed above, in that order, recorded verbatim. After removing them, the rest of the log must be N1/N2-equal to TB188.
  - **Every other row:** N1–N3-equal to TB188. That includes the controls 393, 648, 669, 843, 844, 963, 968, 971, 972, 978, 979, 1005 and 1006.
- **Recorded predictions.** These are for the review; only a RED, a missing line or a crash is STOP.
  - `phaseFront=NotApplicable`, with `producerDisposition=NotApplicable` and all three declined flags 0 (BB1).
    - `Produced` is impossible given the TB188 string; if seen, STOP.
    - `Rejected:<reason>` falsifies the BB1 inference only. Record it.
  - `SpherePlan retained=1 regions=14`, consistent with row648 V18/E30/F14.
  - `SphereCompletionAudit present=1 failure=RepeatedBoundaryNode`, with `auditedNodeOccurrences>=2` (TB-REV-188 B1).
  - `SphereAuditedInputCell disk=1`, and `cutCellDisk=1` or `sameCellTwinHalfedges>0` (BB3).
- **STOP** on any RED, any unpredicted material difference, or an invalid boundary.
- **Not allowed:** gate credit before `M6-CP3-TB-REV-189`, B1 repair, CB-207D, CP3/497/D0/H4 promotion, or parameter deletion.
