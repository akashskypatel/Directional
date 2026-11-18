# CB158 — edge-transit entry record (Code + Build, 2026-11-18 UTC)

## Situation

**Source applied; compile evidence pending.** Resume `M6-CP3-CB158-P13-EDGE-TRANSIT-ENTRY-RECORD`; do not apply the source patch again or start TB135. Source `5bdc7c092a8935faeab75cf7a739928fd8ddca46`. [RA-256 S4–S6](Architecture_M6_CP3_TB134_P13_Trace_Path_Receipt_Full_Gate_Independent_Review_20261118.md#ra-256--adversarial-re-review-of-this-review-2026-11-18-utc) owns the frozen scope.

## Background

- [Snapshot run 44233525696](https://github.com/akashskypatel/Directional/actions/runs/44233525696), job `134564157714`, source `07ed6ab5afa5bb26a8aecd3767532ee57aa455f5`, artifact `14395544048`, ZIP SHA-256 `3cddc49625c1e65c7818b27f961d4f388b7c9341117e13e758e6832ac44560e1`, archive SHA-256 `a8f1f5675ee13c28023aa98330ccf57d838345ed3cdd6d774b170ec0fa7c9cdd`. 5,545/5,545 checksums pass. Complete remote comparison to CB157 `a8d1cc9603f9a556564f0b741692217ec6a791ef` shows zero src/include/tests changes before application; the snapshot has no Git history for the literal local historical diff command.
- [Frozen diff](Architecture_M6_CP3_CB158_P13_Edge_Transit_Entry_Record_Exact.diff) SHA-256 `17dd9ac558f9d2e24bd4d5010262b9d3092c9414c8d9d9bfbbbfa3b4ef12822f`, 51 lines. Forward/reverse application, whitespace and frozen-body comparison pass. The source commit changes exactly three paths (+5/+4/+2, no deletions); verified remote postimages `bdf947602a2d559491e6d3451f7aed832a13d65e` (SurfaceCellTracing.h), `2ccad3f4a961e951cf32237f67c24cf46d84175a` (EmbeddedGraphTopology.cpp), `e5b15ec57302d413f4dfb3aca6abeb33bbe104ff` (SurfaceCellTracing.cpp).
- [Apply run 44234035308](https://github.com/akashskypatel/Directional/actions/runs/44234035308), job `134565882712`, SUCCESS. Event `0898f8d3f8b4ba6804b662e7fafce955c74f3854`, result `14395703935` ZIP SHA-256 `5321103959cfcf0095cf24a2d32f891db3902bb9a40e0aa44d9b16972a9edd41`, log `14395708945` ZIP SHA-256 `8f3ed3ee5116c2a7a268ad08833c67cd4e6c0ad926756d3e818ce06fd91be178`. Both outer digests verified. Preservation patch SHA-256 `0ef0cde84bcf29043c33c2a2c5080c26932c39f147adbe84638f64bc26967d2e`, body `cdc548b9ed82c9f26940bf9be27f61762ca15e0bf04f84a439136215fd6b4087`. Apply/push exit 0. Workflow identity could not trash the consumed Drive object; owner connector deletion succeeded. Library backup retained.

## Assessment

Both existing edge-slide writers store `decision.exitPoint` in `edgeTransitEntry`; the receipt adds ` slide=` before ` transit=`. No digest, guard, test, fixture or workflow edits. The compile dispatcher event is `25fdb50c968b6c919d70ff9ee21216cea2278ebf`; observe mailbox `m6-cp3-cb158-compile-v1` on orphan ref `workflow-mailbox` only. Eight RA-245 targets with GMP/GMPXX requested. No terminal compile verdict or package ID claimed. No local compilation or runtime execution.

TB134 remains measured authority: 956/956 MATCH, gate 952/953 (row 858 permitted RED), CP2 491/491, stable 66/17/49, debt 1, deferred 81. No CP3/selector497/D0 promotion. D11=A, D12=A, D10 deferred, D6 pending; chainRimSchedules=false. FC-6, terminal-cut outcome and row858 held; CB145 parked.

## Recommendation

Resume CB158 by obtaining the terminal compile mailbox, checking the event/source identity and verifying result/log archives, all eight targets, GMP/GMPXX evidence, clean source state, internal checksums and four frozen inputs. Do not re-dispatch without failure evidence. Clean this turn's snapshot marker `.agents/connector-triggers/source-snapshot/cb158-20261118.txt` through the durable cleanup workflow after evidence verification. Preserve the durable request slot and mailbox history. Finish this record, handoff, TODO, CHANGELOG and documentation audit before publishing COMPLETE STATUS.

Separate TB135 only after COMPLETE: RA-256 S5; comparator TB134 gate 14390702505 and census 14391390784. N1–N4 plus N6, six frozen acceptance criteria, ratio 0.0886278847694713 within relative 1e-12. Mismatch `M6-CP3-PLAN-P13-EDGE-TRANSIT-ENTRY-RECEIPT-STOP`; infrastructure `M6-CP3-CB158A-P13-EDGE-TRANSIT-ENTRY-RECEIPT-ORCH`. No successor executed.
