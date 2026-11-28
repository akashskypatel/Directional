# CB-209 exact manifest — slide arc ray oracle (2026-11-26 UTC)

Review artifact only. Authority: [TB-REV-186](../Architecture_M6_CP3_TB_REV_186_P13_Activated_Sphere_Full_Gate_Independent_Review_20261126.md). Only authorized next Code + Build after Review closes: `M6-CP3-CB-209-P13-SLIDE-ARC-RAY-ORACLE`.

- Exact [diff](../Architecture_M6_CP3_CB209_P13_Slide_Arc_Ray_Oracle_Exact.diff), 14,643 bytes, SHA-256 `6f17d7c84672dc3780ca15e6556f2ffbc40bbd5565c881242f14573afe38fcc4`.
- One intended path `tests/FieldAlignedCurveNetworkTests.cpp`; SHA-256 preimage `073d5254b055a74ac32e6509418375c3ad31058c20f263139f5f5481e81017da`, postimage `a371dffbb30576dfe492631ecd68f2006b1cef01b721f2518a8472362e617584`. Verify exact current preimage before apply; STOP on drift.
- Scratch `git apply --check`, real replay, postimage and `git diff --check` verified. No syntax compiler invoked; compile correctness unproved. No repository test or production change in Review.
- Correct the one test's semantic distinction between original slide segments and clipped arc occurrences. Four exact independent interior wall contacts specified in Review imply six whole, four prefix and four suffix occurrences. Keep ten vertex-end rays and require both orientations at each interior wall node; check exact endpoint/carrier/fraction, direction, coverage, all existing unaffected assertions. Do not infer correctness from counts or select actual output as expected value.

## Code + Build boundary

Apply only the exact diff after preflight. No implementation, fixture, harness, selector, manifest membership or workflow change. Compile eight targets as in CB-208R, with GMP/GMPXX, runtimeExecution=false; verify package member hashes and source status. STOP on apply, hash, scope or compile mismatch. No runtime tests/benchmarks in CB. No other repair. Freeze next TB plan against the actual immutable compile package only after successful compile.

## Subsequent Test + Benchmark requirements (not authorization to execute now)

Full 1006-row manifest and deferred81 unchanged; membership1087, accepted CP2 491. Required 1006 organic PASS, valid execution boundary, postflight, no abnormal/missing/skipped/duplicate. Compare to TB186 and both accepted preactivation baselines using frozen N1–N3 only. Against TB186 only row971 may change materially; exact new receipts, counts and all existing unaffected controls must be present and pass; no other unpredicted row changes. Against TB185V/TB187Q preserve the adjudicated activation differences in Review, row858 exact prefix/detail, 648/963/968/972/978/979/1006 exact controls and explicit unstaged negatives. Do not claim rays proven until execution. STOP on any RED, unpredicted material difference, missing evidence or boundary failure. Later separate independent Review required. V5 held until valid full gate, both pending wall contacts and deferred obligations retained. No CB-207D or CP3/497/D0/H4 promotion. Exact completion rejection remains unresolved; a distinct receipt is a later proposal, not part of this CB.
