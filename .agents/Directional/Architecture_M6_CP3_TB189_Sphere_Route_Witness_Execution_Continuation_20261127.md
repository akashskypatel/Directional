# TB-EXEC-189 — Sphere route and completion-input witness execution continuation

## Situation

`M6-CP3-TB-EXEC-189` remains IN_PROGRESS. The single authorized full-gate request is committed. Do not dispatch it again, even if the result mailbox does not yet exist. No result or gate credit is claimed. TB-REV-189 remains conditional on valid execution closeout.

## Background

Authority: [exact manifest](gates/Architecture_M6_CP3_CB211R_CB212_TB189_Sphere_Route_Witness_Exact_Manifest.md) and [CB-212 compile record](Architecture_M6_CP3_CB212_P13_Sphere_Completion_Input_Census_Code_Build_Record_20261127.md). The previous TB188 harness ran for 20 min 6 s, longer than the remaining response window after dispatch. Do not terminate the workflow to meet a chat time limit.

## Assessment — verified authority and preflight

| Item | Value |
|---|---|
| Original TB189 entry UTC | 2026-11-27T03:52:16Z |
| Entry beacon commit | `228bfd7c495a34ab024092380dba53cdd655afb6` |
| Source snapshot | Run `45936682612`, job `140301445280`, artifact `15170603088`; source `7e5cf68b50e3e876211eacfd33af511a917ed440` |
| Snapshot ZIP SHA-256 | `3fce894afc7f48757b149be29b47912d9b76128354123341ff945f6573687193`; 5875/5875 file checks PASS |
| CB-212 candidate source | `39253c63c308a2699669095bdb12e4ece72d502a` |
| Candidate artifact | `15170182914` (compile run `45934565154`); ZIP `51cbdd7c323aa6cc29d42afd16a2905c24420d04efa5c1ecfff853f5ed2a5ebf`; 28/28 SHA-256 checks PASS |
| Root manifest SHA-256 | `b7aac97b934933f863ebc4f8f72b048f966f8850025113bb536e57539d6d8124` |
| Source archive SHA-256 | `7c4194e692c13b0f897b974f95b18f292e60aba2746c3e8b1e8dcdc6ab73476a` |
| Executor | `cc25a6402cdd3ca1a33a9a9778250176b182bb2a` |
| Harness SHA-256 | `423f385b73c3825ce9fe18fbd5ca395287620475deb621389f0efbaa601e572c` |
| Case manifest SHA-256 | `a9b8083269ebd0786f0584d66c1f89f43362d884840ab95b95c3d0fa59ca0587` |
| Deferred ledger SHA-256 | `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce` |
| Reference result | TB188 artifact `15163822727`; ZIP `59957c5adbb95a5e5a90f1eada11f3aec60366ee3a8c22694edf8de799293780`; 2020/2020 SHA-256 checks PASS |
| Request trigger commit | `4605b75e3c04810e7fc9cd6c2297315c9a791d76` |
| Request blob | `765a07b34dcb46b44d9dd295de5b115696dde235` (matches local Git object hash) |
| Request ID and mailbox key | `m6-cp3-tb189-exec` |
| Result mailbox | `.workflow-mailbox/m6-cp3-tb189-exec/latest.json` on `workflow-mailbox` only |
| Temporary-state cleanup | Run `45936974764` success; commit `10aabd6e85338381e01ec132e8b85ffd30c93567` removes only the snapshot trigger and cleanup manifest |

All six packaged executables retain mode 755. The candidate receipt records no runtime execution and GMP/GMPXX linkage. Local inspection confirms the candidate source archive contains the exact harness, manifest and deferred ledger. No build, runtime test, benchmark or source modification occurred locally. The dispatch request contains only the authorized full gate, with 1006 cases. No V5. The request write is confirmed, but the run ID and terminal result are not yet verified. The first result-mailbox lookup returned 404; that is not a test result or evidence of a failed execution.

Reference row858: the byte-exact prefix through the LF after `SphereCompletionFailure detail=BoundaryParityRepair:InvalidReplacementBoundary:repeated-boundary-node;AlternativeRepairBudgetExhausted;attempted=106;budget=106` is 69,446 bytes, SHA-256 `68839fe0a5bc1ed0128e90cd9c96ab0ee55aaddb1c85f711494da0fa9d954266`. The first 69,196 bytes have the frozen prefix SHA-256 `32d6de52259ed91a9968109bda21b68d3dc4d37a3b1aed7b59193301c61a42d9`. Use the reference raw file for byte comparison, not the prose receipt count.

## Recommendation — same-turn continuation

1. Preserve the original Started at timestamp. Update Resumed at in STATUS. Inspect the retained dispatcher request and the exact result mailbox above. The mailbox event SHA must equal the request trigger commit. If the mailbox is not published, do not repeat the dispatch. Use the approved bounded run discovery path only when necessary.
2. When terminal, verify job status, artifact inventory, all outer and internal checksums, exact executor/source/package/harness/request, execution boundary, ordered ledger and membership. Require 1006 selected cases, 1087 members = 1006 gated + 81 deferred, 491 CP2 PASS and no RED/abnormal/missing/skip/duplicate. Retain exact result and log artifacts. Do not rebuild, retry or substitute a timeout result.
3. Compare to TB188 result `15163822727`. Reuse the frozen N1–N3 normalizer and its positive/negative controls. N1 removes only elapsed GoogleTest fields; N2 normalizes CRLF; N3 compares the exact multiset of complete region projection records and the ordered residual. No new normalization. The prior local comparison bundle was unavailable through Library raw-byte materialization in this response; recover the existing normalizer or verify an exact equivalent against its frozen definitions before comparison.
4. Row858 must PASS. Verify the 69,446-byte exact prefix. Capture all new receipt lines verbatim and in order: SphereRoute, SpherePlan, SpherePlanRegion for each retained region, two SphereCompletionInput, SphereSimplification, SphereCompletionAudit and SphereAuditedInputCell plus each SphereAuditedBridge (or explicit unavailable). Remove only those authorized lines, then compare the remaining log under N1/N2. Every other row must match under N1–N3. Record the predictions, including any falsified prediction, separately from the measured result. STOP on RED, missing receipt, Produced, unexpected material difference or invalid boundary as required by the manifest.
5. Update the execution report, regression tracker if justified by measured evidence, changelog and handoff at authorized closeout. Keep stable accounting at 67/17/50, debt 1, deferred 81, CP2 491/491 and no CP3/497/D0/H4 promotion until evidence and independent review authorize change. No B1 repair, CB-207D, V5, parameter deletion or successor work in this turn.

## Process limits

Initial handoff/orientation reads preceded the required snapshot and full policy read; the initial STATUS write preceded other repository mutations. Full pre-work policy/LESSONS/design review and exact tool-call accounting are not established. The external turn-based skill root lookup returned 404. The existing handoff is 15,897 bytes, above the direct-write ceiling; this isolated continuation record preserves current execution state without replacing the active dispatcher request with a Drive patch request. No new regression evidence is available, so no tracker change is warranted yet. The normal complete-turn handoff/drift audit remains due at execution closeout.
