# CB134 — Production-size census: Code + Build record (2026-11-12)

## Situation

`M6-CP3-CB134-P13-A4-PRODUCTION-SIZE-CENSUS` (64E.10) is complete after a compile-only GitHub Actions run. The next separate turn is `M6-CP3-TB115-P13-A4-PRODUCTION-SIZE-CENSUS-FULL-GATE-EXEC`. No test or benchmark executable ran during this turn.

## Background

RA-233 required the exact 17-line patch `Architecture_M6_CP3_CB134_P13_A4_Production_Size_Census_Exact.diff`, SHA-256 `0f3eb0d8c62043013f47b5815fc280d959aec13bca4f7f79d52d2b4431ae4ab4`. The change adds six lines and deletes none in `tests/SurfaceCellDesignAcceptanceTests.cpp`. It publishes production-labelled `switch-run`, `switch-validation`, and `switch-size` evidence without changing assertions or production behavior.

## Assessment

- The applied semantic source is [`c565a3ada13d4b785fb45182db80fd5adf665add`](https://github.com/akashskypatel/Directional/commit/c565a3ada13d4b785fb45182db80fd5adf665add). The direct GitHub diff confirms only the six authorized test lines changed.
- The patch was checked against exact snapshot `50a35378be5aa95166ef32d687201337e3854542` (5,523/5,523 files verified) and applied by [workflow 43244393778](https://github.com/akashskypatel/Directional/actions/runs/43244393778), which reported `runtimeExecution=false`. The Drive staging object was retired after the push.
- [Compile run 43244784978](https://github.com/akashskypatel/Directional/actions/runs/43244784978) succeeded with all eight authorized targets. Immutable package 13956118408, ZIP SHA-256 `e1e4d67cee10be6001369ec8f7fc9e7e09225202dbd87fdbc51facf483dd88dd`; 28/28 internal manifest entries verified. GMP and GMPXX linkage, `exactArithmeticBackend=GMP`, and `runtimeExecution=false` are required for this result.
- The diagnostics are compiled, not yet observed. TB114 remains the last scoped runtime: 945/945 PASS, 1,026 memberships, 1,898/1,898 hashes. CP2 remains 491/491 accepted; stable accounting remains 66/17/49, debt 1, deferred 81. CP3/selector497 is not promoted.
- O41 remains open. D10 (A4 size transitions, region-aware A3 count, or gate-policy change) is still the user's decision. `chainRimSchedules=false`; no production switch, recovery, quality gate, or fixture changed.
- Process note: an initial group of repository reads occurred before the required snapshot read-mode choice. Inspection was corrected by obtaining and verifying one exact source snapshot before the patch application. No source mutation relied on an unverified source snapshot.

## Recommendation

Use only package 13956118408 from source `c565a3ada13d4b785fb45182db80fd5adf665add` for `M6-CP3-TB115-P13-A4-PRODUCTION-SIZE-CENSUS-FULL-GATE-EXEC`. Run TB115's immutable 945-row gate and census without rebuilding. Apply RA-233 §5: preserve all TB114 receipts and verdicts, record production-labelled lines, and check Vase's registered completion failure (`accepted=0 strict=0`). On scoped MATCH, the next turn is `M6-CP3-DEFN-P13-A4-SIZE-GRADING-DECISION` (Review-only); do not perform it during TB115.
