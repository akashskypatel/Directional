## 2026-09-22 — `M5-CP3-TB1-R11-EXEC`: final self-manifest enumerates its own staging file — **ORCHESTRATION INVALID / NO SEMANTIC LEDGER / NON-STABLE / +0**

**Stable totals remain 50 events / 14 categories / 36 recurrences. Produced-witness debt remains 3. Accepted runtime authority is unchanged.**

R11 consumed immutable CB12 candidate `10713410215 / 8ff6fdc720b3e8da5c4f5765850f8fe69d4b2188` in run/job
`35771152416 / 106892972571`. All 446 processes ran, but the final evidence contract failed after runtime. Result/log
`10714199742 / 10715035437` are invalid-attempt provenance only.

### `M5-CP3-TB1-R11-EXEC-CAND-01` — CORRECTED / STATIC+SYNTHETIC GREEN / retry confirmation pending

**Status:** CORRECTED / STATIC+SYNTHETIC GREEN / ORCHESTRATION / SELF-INCLUSION TEMP-MANIFEST PATH / NON-STABLE / RETRY CONFIRMATION PENDING / OWNER `M5-CP3-TB1-R11-R1-EXEC` / +0.

Root cause is exact: shell redirection creates `SHA256SUMS.new` inside the result tree before `find` enumerates it. The
temporary empty file is hashed into the manifest, then removed by `mv`. Final result has **913 manifest rows / 912 actual
non-manifest files**; all 912 real evidence files verify and only stale `./SHA256SUMS.new` fails. Workflow records
`result_finalization_exit=1 / driver_exit=1` and fails closed.

Preserved raw ledgers diagnostically read 9/9 mechanism, 1/1 focused, 4/6 produced and selector430 430/430, but durable cadence
forbids semantic credit from an orchestration-invalid attempt. Existing product/debt observations therefore remain open.
CB13 validation run `35775766068` corrects only the finalizer and is schema/static/synthetic GREEN: the temporary manifest is outside the result tree, authority copy precedes finalization, synthetic completeness is 3/3, and checksum plus file-count mismatches both fail closed. No Directional runtime ran. Fresh R11-R1 must still re-execute the full gate from process 1 before this orchestration correction is runtime-confirmed.

