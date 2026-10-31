# TB26 — immutable shared-node seam witness harvest (2026-10-22)

**Turn:** `M6-CP3-TB26-RP01-A5-SHARED-NODE-SEAM-WITNESS-HARVEST`. **Boundary:** artifact-only Test + Benchmark. No product, test, fixture, selector, compile, relink or benchmark mutation.

## Immutable execution

- Semantic source `c5e0b242f3c3015f1f4f5f886058f0086fe1f679`; eight-target GMP package artifact `12399179446`, SHA-256 `a82c75e0f648fa8f1c8e34e07934d7a01321692e12e993638f02465766f236e9`.
- First harness attempt [39726328838](https://github.com/akashskypatel/Directional/actions/runs/39726328838), result `12402438641`: **0/18 tests executed**, each exited 126, nonexecutable ZIP-extracted binary. No product evidence or green credit.
- Corrected harness `59b5410c48e0e2780fe48f5dbf163cd24b1be52b`, SHA-256 `54c54aaf757510c0c32ab09b8416b1e747a69750d18cdabae1ae621255d18eb3`: only `0o755` permissions restored on copies of compiled executables, package unchanged. Retry dispatch `90bdf2e3a5b4936b1c9861ffa3461090c2edcf4e`.
- [Successful evidence-harvest run 39727886868](https://github.com/akashskypatel/Directional/actions/runs/39727886868): result artifact `12403479548`, ZIP SHA-256 `3f7df8c2ecbd9587127c4621feb3965abe383df31deae57bd48cf0283080ac2d`, independently rehashed **21/21** result manifest entries; all 18 raw logs, ledger, GMP runtime dependency and postflight records included.
- **18/18** distinct selections ran once, **0 skipped**, **9 PASS / 9 RED**. All six guard/controls PASS. Postflight package and staged view unchanged, no compile/relink/benchmarks; source identity verified. The green workflow badge means only that the allowed diagnostic-harvest procedure succeeded, **not** that all tests passed.

## Twelve A5-ISO witness outcomes

| Identity | Outcome | Earliest visible observation |
|---|---|---|
| `focused30:6` | RED | `UncertifiedCrossSheetBinding` (TQ:8381) |
| `focused30:20` | RED | `UncertifiedCrossSheetBinding` (TQ:5836) |
| `focused30:24` | RED | A7 absent (TQ:6024); root cause unresolved |
| `focused30:25` | RED | tracing materialization `UncertifiedCrossSheetBinding` (TQ:6197) |
| `focused30:26,27,28` | PASS | individual positive witnesses, no generalized acceptance |
| `selector:444` | RED | `UncertifiedCrossSheetBinding` (TQ:7944) |
| `selector:446` | RED | `UncertifiedCrossSheetBinding` (TQ:8318) |
| `selector:448` | RED | `UncertifiedCrossSheetBinding` (TQ:8457) |
| `cp3entry:3` | RED | no certified reciprocal cross-sheet OrdinaryFront: each size `0.25,0.5,1.0` reports `A7:rejected-certified-seam` (TQ:3616) |
| `cp3entry:5` | RED | identical bounded search failure (TQ:3980) |

**Six controls PASS:** `selector:447` (guard), `cp3entry:6`, `selector:217`, TB18 A#14, `selector:443`, `focused30:7`. No observed control PASS→RED. No first-failure diagnostic contained prior A5 `first-face`/`second-face` sites; `site_bad=0` does **not** prove that all twelve reach or pass the amended A5 branch.

**RA-128 A6/D3 stop:** Both `cp3entry:3/5` fail before selecting a certified reciprocal relation. Therefore A6 untampered decision, stripped/expected turns and `cp3entry:3` D3 tamper rejection are **not reached or measured**. The required witness is missing, the central runtime obligation is **undischarged**, and the review's explicit stop/falsifier applies. Do not claim an A6 pass or D3 guard acceptance.

## Classification and next gate

Candidate/non-stable continuation evidence: six `UncertifiedCrossSheetBinding` producer failures, one missing A7, and two `A7:rejected-certified-seam` fixture candidates. The shared root cause relative to the new A5 shared-node rule is not established. **Do not fabricate a new stable regression event or assume a successful fix.** Stable totals **66/17/49**, debt **1**, accepted CP2 **491/491**, rejected R3 **403/497**, TB21 candidate **449/497**, frozen selector **497** unchanged. RP-01 open; RP-02 unreached; Gate C suspended.

The *harvest workload* and immutable diagnostic evidence are complete, but acceptance failed. **Independent TB26 Review must adjudicate** the missing certified relation and shifted upstream failures before any corrective Code + Build turn. CB26, TB27, DEFN-M1, DEFN-T1, DIAG-RETAIN and nonzero-turn seam work remain unauthorized. Repository tracker/handoff/TODO/CHANGELOG synchronization and final STATUS closeout remain separate same-turn duties.
