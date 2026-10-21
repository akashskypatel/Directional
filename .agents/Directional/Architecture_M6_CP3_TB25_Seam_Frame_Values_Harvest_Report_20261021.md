# TB25 — immutable seam frame-values harvest (2026-10-21)

**Canonical turn:** `M6-CP3-TB25-RP01-SEAM-FRAME-VALUES-HARVEST`. **Boundary:** artifact-only Test + Benchmark, no compile, relink, benchmark or semantic source/test/selector changes.

## Immutable execution

- Semantic source `dae267a82fb884ff9eba4fd0122ad61750d0c924`; CB24 package `12378590512` (ZIP SHA-256 `bbaaa3853e4a0d3cef13d327fefa10676ab0d10108213964772215ec79d630b4`).
- Harness commit `36c4b489ac3cd7e8039e3e99aae1c14543bbb08a`; harness SHA-256 `bd64b409a8adca8c2b9d30e0c1a34670868f428b226fea868f4245d250332713`. Dispatcher commit `30a1e93579cb6866889159840d97d33285993bf1`.
- [Execution run 39682528031](https://github.com/akashskypatel/Directional/actions/runs/39682528031), immutable result artifact `12384333036`; outer SHA-256 `f10ef7786ca2af1f9e2cfa8cc0dfdf0b889c03b2adb54c9f8a5e87de1be6ccbc`; independently checked **16/16** result-manifest entries.
- Eleven independently selected/executed identities, 0 skips, **6 PASS / 5 semantic RED**. Expected A5 RED rows 1–3, D3 RED rows 4–5, six guard/controls PASS rows 6–11. All eleven raw logs, ledger, source/package/execution-view postflight and GMP dependencies preserved in immutable result. `postflight=True`, `site_bad=0`, `ctrl_bad=0`, `compile=false`, `relink=false`, `benchmarks=false`, `selector497=false`, harness exit 0.

## Site observations and causal routing

**A5 torus family** — all three sites byte-identical, `relation-collinear-seam;region=0;seam=60,61`, selected faces `121/0,121/0`, spans `120/0+121/0,97/2`, `spanOnly0=forward`; **`branch=3,3;gaugeSel=0,0;gaugeSpan=0,0;turn0=0,0`**. Both branches have equal nonzero 3, so producer signature is **curved**; canonical `d=(0-0) mod 4=0`, `F=0`. Under the frozen routing rule, this is the **identity-certificate/A5-side-authority branch**, *not* a nonzero D3 transform or producer gauge table mismatch. Original A5 face clauses still reject; no assertion relaxation is authorized. The recorded `turn0` is identity and presents no observed A6 nonidentity turn in the measured family.

**D3 candidate family** — `cp3entry:3` and `cp3entry:5` both RED because the bounded producer supplied no fully certified reciprocal OrdinaryFront. Each logs **three** `relation-collinear-seam` candidate sites at `seam=1,4` with candidate relation keys `3:1,4:0`, `1:1,2:0`, `0:1,1:0`; source-selected `0/0,0/0`; **`branch=0,0;gaugeSel=0,0;gaugeSpan=0,0;turn0=0,0`**. This is a **uniform identity** family with `d=F=0`. Candidate rejection is A5 `OccurrenceMismatchedIsolationEvidence`, not missing a seam site. These contested fixtures therefore join the observed seam-contract family for independent review; the review still owns any reclassification/definition change.

All six controls show PASS without A5 sites. Unexpected semantic GREEN is not claimed.

## Disposition

TB25 execution and immutable evidence are complete; this report does **not** close repository hygiene or the mandatory regression-tracker/handoff/TODO/CHANGELOG synchronization. A follow-up within this same canonical turn must finish those duties and remove the temporary source-snapshot trigger before final COMPLETE status. Independent TB25 Review is required afterward; **Review turn ID remains UNKNOWN**, and DEFN-SEAM is not authorized yet.

Stable accounting remains **66/17/49**, debt **1**, CP2 **491/491** accepted, R3 **403/497** rejected, TB21 **449/497** candidate and selector 497 frozen. RP-01 remains open; RP-02 unreached, Gate C suspended.
