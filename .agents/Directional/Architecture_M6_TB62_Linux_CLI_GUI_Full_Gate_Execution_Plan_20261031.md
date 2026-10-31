# TB62 — Linux CLI/GUI immutable full-gate execution plan (2026-10-31)

**Next exact turn:** `M6-TB62-DIAG-RETAIN-LINUX-CLI-GUI-FULL-GATE-EXEC` (artifact-only Test + Benchmark; implementation track). Do not execute it during CB63. **Authority:** [CB63 build report](Architecture_M6_CB63_Linux_CLI_GUI_Code_Build_Report_20261031.md) and independent TB61 review.

## Frozen package

- Immutable Linux Release/static/GMP package artifact ID **`13043004468`**, ZIP SHA-256 **`14b7589aba85ed1fa0fdf62d233007293150491d559820dc2b24b8e83df27462`**, GitHub run **`41202931582`**, frozen source **`f6113c4eb0fbf6a02350eee2d37e7e4dab821429`**. Verify the exact archive, all 30 inner `SHA256SUMS` entries, ten-target member list, two executables, CLI/GUI `ON` and authoritative generated GMPXX/GMP link receipts before any execution.
- Use current frozen `Architecture_M6_TB58_Diag_Retain_Display_Full_Gate_Case_Manifest.tsv` (863 cases; SHA-256 `31c1360ab5738cab682e628304914af4a3f7ad4dd077a8f688e79536bf371341`) and deferred ledger v4 (82; SHA-256 `36241caa61d3d27aa062fee05cf3af12a62a81a5a11a42e3ea75e46b0590139d`); total membership 945. Freeze harness identity and verify it separately; avoid using an unfrozen regenerated selector or an altered gate.

## Execution and falsifiers

1. **No compilation, relinking, CMake configuration, repair, product/test/fixture/selector edits, or build logic changes.** Use the mandatory artifact-only reusable test/benchmark workflow and all mutation flags false.
2. Run the **entire 863-case gate**, one identity per fresh process; prove manifest-to-result membership, counted passes/failures, non-vacuity, logs, hashes, and final postflight. Preserve every RED/abnormal/missing case; do not bypass row 283 (Linux previously PASS, macOS O16 RED).
3. Separately register and execute the applicable existing **11 Linux CLI checks**, preserving their real assertions, intended arguments, exit codes, filesystem sidecars, source and artifact identity. Treat their result independently of the 863-case gate; do not infer Linux CLI behavior from macOS TB60.
4. Independently verify GUI's packaged `directional-ui` and generated link/GMP evidence without launching GUI on a headless runner. Do not claim GUI appearance without an actual on-screen manual check.
5. Record source SHA, package ZIP digest, harness SHA, case manifest and deferred-ledger digests, membership, test results and logs. An orchestration defect routes to corrective CB; semantic RED requires independent REVIEW + PLAN under `Turn_Cadence.md`. No accepted CP3 or selector497 promotion from a TB dispatch alone.

## Next boundary

After authoritative TB62 execution, follow the existing Review/Definition and checkpoint cadence. P13 remains conditional on independently adjudicated Linux platform coverage; accepted CP2 491/491, stable 66/17/49 debt 1 and separate macOS O16 persist until specifically resolved.
