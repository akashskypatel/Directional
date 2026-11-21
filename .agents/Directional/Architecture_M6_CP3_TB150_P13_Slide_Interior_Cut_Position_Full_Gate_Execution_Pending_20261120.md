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

## Completed full-gate evidence (verified in resumed session)
- Workflow [44692445950](https://github.com/akashskypatel/Directional/actions/runs/44692445950) completed SUCCESS. Immutable gate artifact `14609657696`, ZIP SHA-256 `9e2117dc4bf4d5e097beeaa90236b1c44ceafdba90bc3fd4751ef2cd2472874f`; 1,936/1,936 indexed SHA-256 checks passed. Workload jobs, schema validation, and mailbox publication completed successfully.
- Exact source `041bde764365710e6d5148c43751da91205ffd35`; package `14608341511`; `planned=executed=passed=964`, red/abnormal/missing/skipped/duplicate/control_bad/unexpected_pass=0; membership=1045 (964+81); postflight=true; exit=0; compile/relink/configure/benchmark=false.
- Row 960 PASS and new row 964 PASS. Accepted CP2 prefix 491/491 PASS. An independent, exact per-row comparator gave **963/963 MATCH against TB149** under frozen N1–N3 only: variable Google Test timing, line-ending equivalence, and complete `M3_CP4AB_FRAGMENT_DIAG record=region_support_projection` records compared as a counted multiset; all other lines compared in original order.
- The comparison accounts for 1,738 complete M3 records. All 504 `FieldAlignedCurveNetwork.slideContactArrival` lines from TB149 remain present and unchanged. No diagnostic-line deletion, new normalization rule, or new stable regression event is warranted by the gate.
- The three-case **census result is still pending**; no product outcome or independent Review successor was claimed by this partial report.

## Pending gates and closure
1. Full gate verified as specified above; retain this result and do not re-run.
2. Census: 3/3 MATCH TB149 under N1–N4. N4 applies only to parameter-object address bytes in census RED lines.
4. On a semantic failure, STOP and classify it. Do not patch, rebuild or rerun in this TB turn. Record any regression or candidate in `Regression_Root_Cause_Tracker.md` before closing. A workflow orchestration failure has separate cadence rules.
5. After actual results are known, complete the authoritative execution report and update the handoff, TODO and changelog. Direct-write final root STATUS as the last repository mutation. If the bounded response ends before results, leave TB150 **IN_PROGRESS**, with its original started timestamp `2026-11-20T07:02:46Z` and blank ended timestamp.

No tests, benchmark sources, implementation, selectors, or frozen manifests were changed by this session.
