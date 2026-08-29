# Architecture M3 CP4c-2 — TB-X2-R7 Independent Review Plan

## Status

**READY / NOT EXECUTED**

Exact turn: **`M3-CP4c-2-TB-X2-R7-REV`**. Independent review/planning only. R7-EXEC stopped in immutable
preflight before any Directional process because four exact selector hashes in the R7 plan disagree with the
unchanged selector bytes in package `9719216316`.

## Review authority

Read, in this order after the durable start checklist:

1. `Architecture_M3_CP4c2_TB_X2_R7_EXEC_Artifact_Only_Evidence.md` and raw archive
   `Directional__M3-CP4c-2-TB-X2-R7-EXEC__raw-evidence.tar.gz` (`sha256:b83172acc3519fc6fe3472e5844a48e0bfd938fe9e6a5d68d14e515371454cc7`);
2. `Architecture_M3_CP4c2_TB_X2_R7_Artifact_Only_Test_Plan.md` — the executable authority that hard-stopped;
3. immutable CB5 package/source authority `9719216316` / `755485865a7cf9c485d754f22b82a41ee151824b`;
4. `ORIENTATION.md` selector table, CP4c-1 closure authority, and R6-EXEC exact preflight evidence;
5. `Architecture_M3_CP4c2_TB_X2_R6_Independent_Review_Record.md` AD0 and
   `Architecture_M3_CP4c2_CB5_Code_Build_Report.md` AD0;
6. `Regression_Root_Cause_Tracker.md` entry `M3-CP4c2-TB-X2-R7-ORCH-01`.

## Questions the review must answer

1. **Exact authority.** Recompute 316/346/353 prefixes from the immutable accepted-355 selector and recompute the
   357/358 file digests. Confirm whether the exact authoritative values are:
   - 316 `601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c`
   - 346 `20d3b0b1400d5cab6af4a339a858c56fb7fd0359fb995a395dad215b20f3e46a`
   - 353 `51ff96d72e1c2c88e9407e99737e42ec9093ea238aaf8b1e45ff2559f71ac6a5`
   - 355 `e9d88f1196e412e06424294d6be22b32f01c9671ec5e4de119abd3f2fb5afeaa`
   - 357 `b896d0db7f26aeb0f3513418405efdeccbcf84fb6dc971500c6ddac9e364dc70`
   - 358 `6eda3aad83de81fc55d5cd446f80704d604a842f10995789b483291bb64fbe62`
2. **Causal boundary.** Determine exactly where the four wrong full strings were introduced. Distinguish selector
   mutation from documentation transcription; do not infer one from the other.
3. **CB5 evidence correction.** Decide whether the CB5 report's AD0 hash table must be corrected while leaving the
   compile/package result and semantic implementation intact.
4. **R7 plan correction.** Decide whether a documentation-only correction to the four constants is sufficient to
   re-authorize the same R7 artifact-only execution against package `9719216316`, without rebuilding.
5. **Regression accounting.** Confirm `R7-ORCH-01` is orchestration/document-authority only and therefore changes
   neither stable event nor recurrence totals.
6. **No silent substitution.** Confirm R7-EXEC was correct to stop rather than replacing plan constants at runtime.

## Frozen boundaries

The review executes **no Directional binary** and performs no compile, package, benchmark, selector, fixture,
product, or test semantic change. It does not close R043/R044, select 357/358, select a cumulative gate, touch
mechanical/C2, or begin CP4c-3.

If exact selector bytes and accepted closure/R6 authority agree on the six values above, the expected successor is
a narrowly bounded documentation correction followed by a fresh artifact-only R7 execution on the **same**
immutable package. The review must record that conclusion explicitly; EXEC may not assume it in advance.
