# TB158 — immutable slide-contact cut-binding full-gate execution (GREEN)

## Situation
Canonical turn `M6-CP3-TB-EXEC-158-P13-SLIDE-CONTACT-CUT-BINDING-FULL-GATE` completed its artifact-only test gate and separate production census. This is a scoped gate, **not** CP3 production acceptance; independent `M6-CP3-TB-REV-158-P13-SLIDE-CONTACT-CUT-BINDING-FULL-GATE` is next, not started.

## Background — exact evidence
- CB-174 immutable package source `5190b0e759146342998e3f380f7e5fe4eabd1714`; compile run `44950215403`, artifact `14724824631`, ZIP SHA-256 `d97f3c7ee36a7cec12ede2c73955b1348c3320951e5dbdce71aed5a4db5de205`. Package SHA256SUMS **28/28**; GMP/GMPXX link evidence, `runtimeExecution=false`. No rebuild, relink, configure, source/test/fixture/selector change or benchmark in TB158.
- Frozen 976-row manifest SHA-256 `6a37e4612a6b463eac3de4b5da4ed86f5bba52ac54bfbb1e472ca7508b7caf0f`; rows 1–975 byte-equal to TB157, row 976 is `FieldAlignedCarrierOccupancy.CarrierContactCutPositionTakesTheEntryElseTheSlideInterior`.
- Previous TB157 gate `14719149475`, ZIP SHA-256 `9609b0e0eb8b51d692118859fef7f0556f7de5e69c336c1bb5033d2694194d11`, **1958/1958** checksums. Previous census `14719268782`, ZIP SHA-256 `9e8f561953ba4ad552a5c30cd2430d0e23c22230e074abd3e2c4ce60b92ebd63`, **9/9** checksums.
- Exact source snapshot run `44952073552`, snapshot artifact `14725862703`, source event `75a82f1db7afb775025c3a377dabcc7f32d6d2cc`, outer SHA-256 `03de95317b41c2c6d3e8f5fc5212fc0ee117329f51421444d4956c0962544e67`, **5691/5691** file checksums. Temporary snapshot trigger removed at commit `99f7b26e12c348cdfaa1213a613e965fe4dcf8fd`.

## Assessment — full gate
- Request event `8399fb52cf48d3ae518a39767a99736fbf2b8c25`; [run 44952039401](https://github.com/akashskypatel/Directional/actions/runs/44952039401); result artifact `14725784889`, ZIP SHA-256 `b50d32d0892cbc8e19db5f827512cdda2cd2d3698e86335bd77d2da1296554e5`; **1960/1960** internal SHA256SUMS verified.
- **976/976 PASS**, CP2 accepted 491/491 PASS, no skips, no control/duplicate errors, postflight true, membership 1057; row976 PASS in its own process.
- **975/975** previous rows MATCH TB157 under N1–N3, empty allowance, `736` byte-equal raw logs, zero normalized ledger/log mismatches, zero newly introduced `InvalidCutGraphBinding`.
- Runtime boundary: `compile=false`, `configure=false`, `relink=false`, `benchmark=false`, `exit=0`, package source `5190b0e759146342998e3f380f7e5fe4eabd1714`.

## Assessment — production census
- Request event `479f01b4a3a2bf6ee340c6fbf7cdb77ed4fa6df3`; [run 44954165527](https://github.com/akashskypatel/Directional/actions/runs/44954165527); artifact `14727495926`, ZIP SHA-256 `5b3012ca2a3ca8e9f3e5d4d8bc84c27601fb455913d15b67393998e1f57eb8bc`; **9/9** internal SHA256SUMS verified.
- All **3/3** census rows MATCH TB157 under N1–N4, unmasked platform digest retained. Cylinder PASS; BunnyRandom and Vase expected RED at their unchanged sites. These are inherited failures, not direct production successes. No runtime repair or change in controls.

## Limitations and regression disposition
- No new stable regression or candidate was observed. Stable 66 events / 17 categories / 49 recurrences, debt1, deferred81. Existing sphere `CutSearchExhaustedBeforeCellularity`, Euler characteristic χ6 versus χ2, four unowned slide contacts, and the unwired stop switch remain unresolved. Interim Amendment 14 remains. No CP3/497/D0/H4 promotion is justified.
- Procedure: initial source/document connector reads preceded explicit snapshot-mode selection; corrected with verified source snapshot. First-tool ledger was not initialized; exact tool-call total is partial/unknown, not claimed. These procedural misses are not source or runtime acceptance evidence.

## Recommendation
Proceed only to the independent `M6-CP3-TB-REV-158-P13-SLIDE-CONTACT-CUT-BINDING-FULL-GATE`. It may review/freeze CB-175 only if the immutable TB158 result is upheld; do not run successor work inside TB158.
