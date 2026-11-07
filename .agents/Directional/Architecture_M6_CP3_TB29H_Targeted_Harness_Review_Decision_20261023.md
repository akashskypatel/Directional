# RA-138 — TB29H targeted artifact harness independent review (2026-10-23)

**Turn:** `M6-CP3-TB29H-RP01-TARGETED-ARTIFACT-HARNESS-REV`. **Verdict: REJECT runtime authorization.** Control-plane harness is syntactically valid and the frozen 44-case manifest is correct, but the evidence classifier can falsely report a failed test that never terminated as a valid RED. This is a **harness evidence-integrity** finding, not a product regression, and does not change accepted CP2, selector497 or TB28 accounting. **TB29 must not execute.**

## Authority and independent checks

- Exact-source snapshot `bdc8baee2321a2c5f7c65d8668feeb9cbeb73fdc`, GitHub run `39891305104`, artifact `12474942030`; source archive SHA-256 `39bc56b409f1b872c50b1e1144988857057e9a25254928a45f5686474c416652`; 5801/5801 source checksums. Snapshot adds only the STATUS/CI trigger after the TB29H implementation.
- SHA-256 recomputed: harness `be3db020d5292a7ecb3851d4e662cadb08696e4dd1befe0e159c920069b9b412`; manifest `39fa5eb83e2da1b0668bc7368c5304011ec13de8804c54a2a3466f927c42d236`; TB27 reference harness `5e3ca0a7c513d5373ee200b2442af315d7845d2dce81c6ea71b971ccbff2fe1f`.
- Parsed and checked 44 unique test/identity rows, exactly 4 NEGATIVE / 2 POSITIVE / 3 GUARD / 35 RED, 43 producer-binary / 1 authority-kernel-binary. All 44 named `TEST(suite,name)` identities exist in the snapshotted test sources; the inherited 35-row inventory has 35 entries. No selector modification or accepted-green loss.
- `bash -n`: PASS. Extracted embedded Python `py_compile`: PASS. `--self-check` on frozen manifest: PASS 44. Duplicate-identity copy: REJECTED. Unknown-kind copy: REJECTED. These checks were independent repeats, not proof of runtime behavior.
- Multi-binary lookup, seven environment/hash inputs, `unzip` executable modes, package/source and staged view postflight, per-row process invocation and evidence-before-exit structure were inspected. No Directional test binary, compile, relink or benchmark executed.

## Blocking harness defects

**RA-138-H1 (high, correction required): interrupted tests can be accepted as RED.** In `tools/m6_cp3_targeted_artifact_harness.sh` lines 202–226, `TimeoutExpired` becomes exit=124; a case with one `[ RUN ]`, zero `[ OK ]` and zero `[ SKIPPED ]` is classified `RED` for *any* nonzero exit, even if the log contains only `HARNESS_TIMEOUT 600s` or `Segmentation fault`, with no GoogleTest terminal failure. On a RED-kind manifest row, `control_bad` remains zero, `missing` remains zero and the final gate can exit success. Reproduced by evaluating the unchanged classification expression against synthetic logs: semantic test failure exit=1 -> RED; timeout exit=124 -> RED; crash exit=139 -> RED. No binaries were executed for this proof. The required distinction is **completed failing assertion vs incomplete/abnormal execution**. **Falsifier:** any timeout, killed process, crash or missing terminal GoogleTest outcome must be `INVALID` and cause a nonzero harness exit with raw evidence retained, even when one RUN marker exists; a genuine one-test GoogleTest failure remains RED; a genuine PASS remains PASS. Preserve `reason-not-observed` when a complete RED has no typed diagnostic.

**RA-138-H2 (medium, correction required): manifest self-check does not enforce a declared count.** `read_cases()` checks nonempty/uniqueness but accepts a single valid data row; confirmed `SELF_CHECK_PASS cases=1` against a 1-row prefix of the canonical manifest. RA-137.3 explicitly required count validation. Make expected count a reusable, review-authoritative input to self-check and execute-time preflight (44 for TB29), or another independently equivalent count commitment in addition to full-file SHA. **Falsifier:** a 43-row or 1-row otherwise syntactically valid file must fail when expected count is 44; a future separately reviewed manifest with a different declared count must remain supported. Keep frozen manifest bytes unchanged.

**RA-138-H3 (medium, diagnostic correctness): incomplete A5 reason parsing.** `typed_reason()` lines 105–119 captures `A5:[A-Za-z][A-Za-z0-9_]*`, truncating hyphenated source-generated messages such as `A5:no-produced-certified-ordinary-seam` (`tests/SurfaceCellTransitionQuotientTests.cpp` lines 2810–2827) to `A5:no`. The specific enum-derived A5 codes are camel-case and unaffected; fallback typed diagnostic text is not. **Falsifier:** complete A5 code/site is retained for both enum names and hyphenated diagnostic reasons, without reading the test's expected assertion as a fabricated observed producer reason.

## Authorized successor and stop rules

**Only next:** `M6-CP3-TB29H-RP02-TARGETED-ARTIFACT-HARNESS-CORRECTION` (control-plane Code + Build). Repair H1–H3 minimally in the reusable harness, add static synthetic log/verdict and count probes, rerun `bash -n`, Python compilation and positive/negative self-check; no Directional binary, build, product/test/fixture/selector/manifest/workflow change. Commit with exact new harness SHA; independent RP02-REV follows. TB29 remains held pending Review acceptance of the corrected SHA. Stop and return to Review if any proposal requires changing the frozen case manifest, execution semantics or TB29 scope. Preserve CB28A artifact `12465330920` expiry `2026-10-29T22:54:39Z`.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | n/a: selector497 unchanged and unpromoted; manifest independently hashed at SHA-256 above |
| Decisive claims independently re-derived | 44 rows/owners, 5801/5801 source checksums, harness/manifest/reference SHA; static syntax and negative proofs; synthetic verdict counterexamples |
| Non-vacuity checked | Timed-out/crashed one-RUN logs incorrectly accepted as RED; 1-row manifest incorrectly accepted by self-check |
| Prior obligations discharged/carried | RA-137.1 guard trio and 44-row manifest confirmed; RA-137.3 harness acceptance carried as H1–H3 to RP02 |
| Stable accounting | unchanged 66/17/49, debt 1; accepted CP2 491/491; frozen selector497, TB28 462/497 candidate |
| New candidates/obligations recorded | RA-138-H1–H3; tracker entry, next CB owner |
| ORIENTATION currency line | updated to RA-138 and 2026-10-23 |
| ORIENTATION §3 / §4 / §7 / §8 | §3/§7/§8 updated; §4 n/a, no witness changed |
| CHANGELOG | review decision recorded |
| ROADMAP | n/a: M6-CP3 still open; no checkpoint transition |
| Selector manifest | n/a: no accepted selector or new selector |
| LESSONS | existing evidence/verification principles cited; no generalizable new category beyond test terminal classification |
| Consolidation under CLEAN_UP_POLICY | no current per-turn source folded: TB29H code-build report is live correction baseline; prior historical documents retain review references; no unsafe deletions |
| Successor frozen | RP02 harness correction, exact H1–H3 falsifiers above; independent RP02-REV before TB29 |
| Turn boundary held | runtime-free; no product/test/selector changes |
| review_check.py boundary | local snapshot execution failed: no Git history for ancestry checks; not claimed PASS; structural diff/turn boundary manually inspected |
| `STATUS` lifecycle maintained | entry written; completion beacon final repository write after durable patch publication |
| Pushed to origin, branch in sync | pending remote patch apply verification; do not claim before evidence |
