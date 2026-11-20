# TB150 — same-turn execution receipt (pending)

Current canonical turn: `M6-CP3-TB150-P13-SLIDE-INTERIOR-CUT-POSITION-FULL-GATE-EXEC`. This record is **not** a runtime verdict. Preserve the current turn and do not execute its Review successor until this turn closes.

## Immutable authority
- Source `041bde764365710e6d5148c43751da91205ffd35`; compile artifact `14608341511`, ZIP SHA-256 `d189282ce898af54c3cb48d2eaa47107ebaaf36ca2d0afcaec9689dec926084b`. The exact ZIP and all 28 packaged checksums were verified locally. No rebuild occurred.
- Gate manifest SHA-256 `bce554e6723dfaa77f54d070aab7edc6508cd3aaf69a6120871e21b349b78926`: 964 gate, 81 deferred. Census manifest SHA-256 `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793`: three cases. Both local manifest self-checks passed.
- Baseline TB149 gate artifact `14604413703` ZIP `b9d0ff8746070c2d0928f8ac0647aa5bc0f5add542691b51932a6d85c0c1a621`, and census artifact `14606235652` ZIP `20534de76bd51ffa22bd5cb478b869adb760959139ef025cbf0e53cc531a5f94` verified locally, including their internal checksums.

## Authorized requests submitted
- Full gate request commit `ec902c7f33bcb2be2d7b6d87b0d671164ecbe4b6`, request ID `m6-cp3-tb150-gate-20261120-v1`, mailbox `.workflow-mailbox/m6-cp3-tb150-full-gate/latest.json`.
- Census request commit `cb9a919dbfd1ffaa08e1a59327deea9ebbeb3365`, request ID `m6-cp3-tb150-census-20261120-v1`, mailbox `.workflow-mailbox/m6-cp3-tb150-census/latest.json`.
- Read both mailboxes **only on ref `workflow-mailbox`**. Their absence before completion is not failure evidence. The durable dispatcher runs requests serially. Do not duplicate a request because a mailbox has not published yet.
- Source snapshot run `44692186639` succeeded, source `19ca58bf84f7e31271b078dd135c6b2bf8609636`, artifact `14608653925`, 5631 source checksums validated locally. The temporary snapshot request was removed by cleanup run `44693148703`, commit `dce3d13abe358f92f81c5ab7f5765fdc66cf96b7` (confirmed cleanup result).

## Pending gates and closure
1. Verify both immutable result packages and their exact source, run and artifact identities. The evidence, not a workflow title, decides the verdict.
2. Gate: 964/964 with rows 960/964 PASS; rows 1–963 MATCH TB149 under N1–N3 **with slide-contact receipt lines preserved**, CP2 491/491, 81 deferred.
3. Census: 3/3 MATCH TB149 under N1–N4. N4 applies only to parameter-object address bytes in census RED lines.
4. On a semantic failure, STOP and classify it. Do not patch, rebuild or rerun in this TB turn. Record any regression or candidate in `Regression_Root_Cause_Tracker.md` before closing. A workflow orchestration failure has separate cadence rules.
5. After actual results are known, complete the authoritative execution report and update the handoff, TODO and changelog. Direct-write final root STATUS as the last repository mutation. If the bounded response ends before results, leave TB150 **IN_PROGRESS**, with its original started timestamp `2026-11-20T07:02:46Z` and blank ended timestamp.

No tests, benchmark sources, implementation, selectors, or frozen manifests were changed by this session.
