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

