# O32a isolated scratch runner — continuation record

**Canonical turn:** `M6-CP3-DEFN-P13-ROW-PERMUTATION-SEEDS` (Review, unfinished). This record supplements the existing O32a WIP and does not authorize a successor.

## Isolated remote scratch execution

The validated frozen source snapshot is `4e151e5c139d09ecabca663ea1125d0544c32abb`; production branch `agent/surface_cell_quad/p5-recover-bridge-healing` was not modified in `src/`, `tests/`, fixtures, selectors, benchmarks or workflows.

A strictly temporary exception branch `scratch/p13-o32a-seed-review-20261105` was created from the verified source, because the durable dispatcher cannot inject a scratch patch while preserving exact immutable source/compile authority. Temporary caller `.github/workflows/o32a-scratch-workflow.yml` uses the existing schema validator, Drive patch reusable, GMP compile reusable and isolated workflow mailbox. It was installed at `b6676bb9ff94d6e6860755dac85676b780d80b65` and must be removed with the scratch branch after all evidence is preserved.

- Apply run [42007688756](https://github.com/akashskypatel/Directional/actions/runs/42007688756), trigger `903993d35f5e53893b20085be5ee1b50d06786e0`: schema validation PASS, Drive apply PASS, mailbox PASS. Verified result artifact `13404903831`, ZIP SHA-256 `41f479145f37633a2add2a7a7fa9d33cf515b8301c5b5659b221b2b6440aaf68`.
- Scratch source commit `4499643bc5535d95abd962070dfd58b3f7022895`, patch SHA-256 `9a19f8386d3acb6a904e264f86fff4496f3dc4662bbd0da82e676a9e411427fe`, exactly two scratch-only paths. No formal test or benchmark executed in apply.
- The Drive patch transport reported `drive_file_trashed=false`, `drive_file_retirement_required=true`. Raw Drive ID `1kucBxUvhEqvOVJUg4Ia04jDa1XKCU8Uo` must be retired by the authorized owner-side Drive connector **after** evidence and cleanup.
- Scratch compile/capture run [42007963779](https://github.com/akashskypatel/Directional/actions/runs/42007963779), trigger `59f605752369908cdc0fb0388485892742caf462`. The schema validator passed; the GMP reusable compile was still in progress as of 10:11Z. **No compile success or C++ runtime execution result is claimed yet.**

## Capture and closeout requirements

The compiled test looks up `test-data/benchmarks/fixtures` adjacent to `bin/` (`tests/TestFixturePaths.h`); the reusable compiler package does **not** include those fixtures. Use the verified source fixtures when executing the remote-compiled binary. The scratch generator throws `O32A_SCRATCH_CAPTURE_COMPLETE` once `coverage` has been dumped, but the production component-execution catch may swallow the literal marker; inspect any capture logs separately from the harness failure verdict. Do not interpret test failure due to fixture/marker as producer failure.

After the compile/capture run terminates: verify package source SHA and internal hashes; collect all four logs from actual Vase rows or run scratch-only captures from the verified remote-built binary, parse with the corrected `analyze_o32a_captures_v2.py` (separate semantic vs chart-representation digests), diagnose the first *real* upstream/seed divergence and independently establish fan/sheet/rail safety. Record and validate any corrective proposal before freezing CB→TB. Do not promote acceptance. Complete formal Review checklist and clean up temporary scratch workflow/branch and Drive file. The response timer alone leaves this canonical turn `IN_PROGRESS`.
