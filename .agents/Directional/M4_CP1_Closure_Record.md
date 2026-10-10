# M4-CP1 Closure Record

**Status:** CLOSED / ACCEPTED
**Closed by:** `M4-CP1-TB2-REV` on 2026-09-10
**Reviewed semantic source:** `680f9f1573d3c7e56a273366436463e40e196131`
**Accepted package authority:** package115, artifact `10159019500`
**Accepted selector:** `Architecture_M4_CP1_Required_Green_Selector_373.txt` — **373/373 PASS**

## Closure statement

M4-CP1 closes the known-feasible global conformity schedule slice. The accepted A3 product has one exact positive subdivision count per full A2b arc, preserves multiplicity-bearing incidences and mandatory parity, uses compact arbitrary-precision breakpoint ordinals/generators, exactifies binary64 target ingress, minimizes the frozen exact lexicographic objective with fixed-`M=2` Heistermann/Warnett/Bommes Bi-MDF refinement, and is checked by the independent structural validator and fixed-small test oracle.

No CP2 certificate/infeasibility semantics or CP3 producer-consumption cutover are claimed by this closure.

## Acceptance evidence

- compile/package authority: CB4 run/job `34493860436 / 102927319825`; package115 artifact `10159019500`; SHA-256 `de391c44744d83622dee30cf3a78f781c3b9ad95f0b517a866e7285e77a6b45b`; source `680f9f1573d3c7e56a273366436463e40e196131`; GMP/GMPXX linked; `runtimeExecution=false`;
- runtime authority: TB2 run/job `34497233764 / 102938757986`; result/log artifacts `10160450899 / 10160451919`, SHA-256 `0b7f1551fe3881a0fd46386e1a45ae043faa307f6cb167e91cb4ef78839b9e38` / `2feedf2c278e4735d3506afa124f0cad367d2f23be43cd0d5c3aa66d03f9b955`;
- focused CP1 rows 366-373: **8/8 PASS twice**, identical verdict vectors;
- cumulative selector373: **373/373 PASS**, accepted predecessor **365/365 PASS**, zero RED/SKIP/timeout/selection mismatch;
- one identity per fresh process: independently re-derived from 389 raw process receipts;
- immutable postflight: package, package-source, and execution-view censuses all equal preflight.

## Frozen CP1 closure criteria

The CP1 completion clause in `Architecture_M4_DEFN_Frozen_Definitions.md` is met: full-A2b arc coverage, exact count/generator identity, incidence multiplicity, positivity/parity, bit-exact target binding, exact fixed-`M=2` solver contract, independent structural validation/tamper rejection, and fixed-small optimum/tie comparison are all represented by the accepted selector373 and its reviewed full-green runtime.

## Historical gate-correction disposition

TB1 package114 was not accepted. Its cumulative gate exposed two non-stable evidence/control defects:

- `M4-CP1-TB1-EXEC-CAND-01`: package omitted three selector-owner binaries, causing exactly 146 MISSING rows;
- `M4-CP1-TB1-EXEC-CAND-02`: package launch lacked the executable-relative `test-data` view, causing 38 pre-assertion setup REDs.

CB4 changed only package ownership/execution-view staging while holding semantic source, tests, fixtures, selector and CMake ownership semantics fixed. TB2 then passed all 373 rows. `M4-CP1-TB2-REV` therefore closes both candidates as **RECOVERY PROVED / NON-STABLE**.

## Accounting and successor

Stable accounting remains **47 events / 14 categories / 33 recurrences**. Produced-witness debt remains **5**. Accepted package authority advances to **115**; package114 remains unpromoted. M3 package113/TB48 remains the historical M3 closure/final-audit authority.

The deferred multi-coordinate bidirected `±2` oracle-strengthening obligation was carried into the first later test-source-changing Code + Build turn, **`M4-CP2-CB1`**. That successor plan is now folded after execution/review; its durable facts and disposition are preserved in `M4_Consolidated_Record.md` §§2.8-2.10 and git history.

## Retroactive CP1 graph-class referent — recorded by M4-CP2-CB1

The phrase **“the frozen CP1 graph classes”** in the ninth CP1 exit conjunct refers to the single two-row, two-span equal-counts class represented by `two_row_equal_counts_problem` and `tiny_exhaustive_equal_counts_oracle`. That was the intended fixed-small optimum/tie class because CP1 used the independent exhaustive oracle specifically to falsify the exact scalar objective and canonical tie rule on the known-feasible producer, while the separate same-row bidirected `±2` fixture was a structural/determinism witness rather than an optimum oracle.

Selector373 therefore did cover the intended CP1 graph-class referent. This clarification does **not** reopen or broaden CP1 acceptance. M4-CP2-CB1 strengthens the later oracle surface additively with a genuinely multi-coordinate instance containing same-row `±2` coefficients and full-vector enumeration, as required by the CP1 review carry-forward.
