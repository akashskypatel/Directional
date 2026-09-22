## 2026-09-22 — `M5-CP3-CB13`: result-manifest orchestration correction validates runtime-free; R11-R1 next

CB13 is control-plane-only and runtime-free. The retry finalizer moves its temporary manifest outside the result tree, preserves
`driver-authority.txt` copy-before-manifest ordering, verifies the complete manifest fail-closed, and independently requires
manifest-row/non-manifest-file equality. Retry SHA-256 authorities are frozen in the retained R11-R1 plan and materialized through
`write_orchestration_payload.py`; the workflow contains no raw 64-hex digest literals.

Validation run `35775766068` is GREEN: retry/self schema jobs `106908450647 / 106908451034` and static/synthetic job
`106908512994` all pass. Result/log artifacts `10716415780 / 10716260918` hash to
`e8a3d09981e6eb22df70325741bb265cc2f81cc141c507f6f1577e1e8efeb20b /
f1cfbc376c05be90da52f7e6660eb86589ec79578e3f0aba35a44e01b10df88b`. Synthetic baseline is 3/3 and both checksum
corruption and late-file count mismatch are detected. The retry driver is identical to historical R11 except for turn ID and
still freezes 446 fresh processes / benchmark 0. No Directional executable ran. Candidate/runtime/accounting/debt remain
unchanged; exact next is fresh `M5-CP3-TB1-R11-R1-EXEC` with zero semantic carry-forward from invalid R11.

## 2026-09-22 — `M5-CP3-TB1-R11-EXEC`: runtime attempt invalidated by self-including result-manifest finalizer

R11 run/job `35771152416 / 106892972571` consumes unchanged CB12 candidate/source
`10713410215 / 8ff6fdc720b3e8da5c4f5765850f8fe69d4b2188`. All 446 planned exact-filter processes run and immutable runtime
postflight completes, but the wrapper creates `SHA256SUMS.new` inside the directory before `find` enumerates it. Final
evidence is therefore **913 manifest rows for 912 actual non-manifest files**, with only stale `./SHA256SUMS.new` failing.
Result/log artifacts are `10714199742 / 10715035437` at SHA-256
`26b0d4aa711fa1481f45d6eb4dc8dc0d605126abb08fa744a6843f958df1f23e /
aa80f1859fce582fdba8a0a7e31c6d8a5edae3c0e521b800171a1af8494b3d7f`.

Per orchestration cadence this attempt has no semantic ledger despite preserved diagnostic 444/2 raw rows. Stable accounting
remains **50 / 14 / 36**, debt **3**, accepted runtime unchanged, candidate unpromoted. Exact successor is control-plane-only
`M5-CP3-CB13`, then fresh `M5-CP3-TB1-R11-R1-EXEC` from process 1 if static/schema validation is green.

