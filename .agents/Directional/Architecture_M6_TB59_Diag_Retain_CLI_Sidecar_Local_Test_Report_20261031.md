# M6-TB59-DIAG-RETAIN-CLI-EXEC — CLI sidecar check runs on the CB60 package (2026-10-31)

**Scope:** TB-EXEC, run locally at the user's direction. It runs the three registered CLI cases of RA-186.3 and §.5 against the staged CB60 binary. The five-binary gate is not re-run, because no gate binary changes (TB58 862/863 stands).

## Frozen inputs

- **Package:** CB60 `build/local-evidence/CB60/pkg.zip` (gitignored), ZIP `c867573b…`, root `SHA256SUMS` `c6de6427…` (11 entries, re-verified after extraction), source `a31f2d39f38b01b855c7c17193d124f9b7af2b14`, `bin/directional` `380131ab…`. [CB60 record](Architecture_M6_CB60_Diag_Retain_CLI_Sidecar_Code_Build_Record_20261031.md).
- **Fixture:** `benchmarks/fixtures/milestone-g/plane.{obj,rawfield}`; common options `--raw-field <plane.rawfield> --remesh-backend SurfaceCells --surface-cell-fallback Fail --length-ratio 0.2`.
- **Runner:** a check script (kept with the evidence as `build/local-evidence/TB59/tb59_check.sh`, SHA-256 `16137c4e…`), self-checked first against the RA-186 probe binary (11/11). Run from 05:17:34Z to 05:17:53Z.

## Result

| Check | Registered | Observed |
|---|---|---|
| Run A (retention + prefix): exit; files | 1 (DR4 message); `out.obj`, `plane.degrees.dmat`, `plane.materialization.txt` | same |
| Run B (prefix only): exit; files | 1 (DR4 message); `out.obj`, `plane.degrees.dmat` | same |
| Run C (retention only): exit; files | 0; `out.obj` | same |
| Run A dump headers | `cells=64 occurrences=256 relations=224`; `classes=81 classed-cells=64`; `vertices=81 cells=64` | same |
| Run A dump element lines; total | 256 / 224 / 81 / 81; 645 | same |

All 11 checks pass (`TB59_RESULT PASS`). Run A's dump is byte-identical to the RA-186 probe dump (SHA-256 prefix `fa55ca63…`).

## Outcome

Per RA-186.5, the result matches the registered outcome. **The CLI materialization sidecar is landed.** No separate REV is scheduled. The next turn is **`M6-DEFN-DIAG-RETAIN-GUI-LAYERS`**. Stable 66/17/49, debt 1, unchanged. The latest local gate candidate stays TB58 (863, 862/1); TB52 853/0 remains the latest reviewed Linux candidate.
