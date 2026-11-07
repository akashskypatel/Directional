# M6 CP3 R7 — admissible-face-set harvest (artifact-only TB6)

**Turn:** `M6-CP3-TB6-R7-NODE-ADMISSIBLE-FACE-SET-HARVEST`
**Status:** measurement complete; independent review and durable tracker/handoff closeout still required.

## Exact execution authority

- Semantic source `4d64b7684ac7ec2d0655f96c88ecf05f2906bca7` (CB6 compile only, no intervening source mutation).
- Immutable GMP/GMPXX eight-target compile artifact `12024554349`, outer SHA-256 `c824a6aa43617309aaae6a54a3dd49a987c51390caa404600a88763d3b04fabf`; package internal manifest 28/28 verified before and after runtime.
- Successful artifact-only dispatcher run [38852145039](https://github.com/akashskypatel/Directional/actions/runs/38852145039), event commit `9eba29a3934b10b19972ff1bb7d34dc3dde0667a`, exact harness/executor source commit `385992f233fb9f79233a0bc14866c4626a6821fd`.
- Result artifact [12025322701](https://github.com/akashskypatel/Directional/actions/runs/38852145039/artifacts/12025322701), recomputed ZIP SHA-256 `cd7ebc41eb1ea20fa9e9ed120c537d5540f4c302dff2df419cf3d307330bb3a9`, matching provider digest; 49/49 result `SHA256SUMS` passed.
- Boundary: `planned=44 executed=44 red=44 missing=0 postflight=true exit=0`; `compile=false relink=false benchmarks=false selector497=false`; immutable package, source, execution view and frozen selector all verified.

## Measured answer to RA-72.8's decisive question

**Yes, for every measured rejected side.** The full producer-region `ActiveFaces` and independently recomputed endpoint `FromAdmissibleFaces`/`ToAdmissibleFaces` were compared against the **actual owning-cell** `PathFaces` in all 48 diagnostic occurrences (42 identities with one emission, two with three identical emissions). For both directed sides of every occurrence, the path's full face set is contained in both its from-node and to-node admissible sets: **96/96 side-occurrence comparisons**, no `Frame=not-planar`, no missing or inconsistent evidence.

| First A2b rejection | Processes | Diagnostic occurrences | First-side path/admissibility | Second-side path/admissibility |
|---|---:|---:|---|---|
| `carrier-orientation` (junction) | 21 | 21 | path `{0}`; to-admissible `{0,1,4}` | path `{3}`; from-admissible `{3,6,7}`, to-admissible `{3}` |
| `not-same-interior-carrier-point` (control) | 23 | 27 | path `{0}`; to-admissible `{0}` | path `{3}`; from-admissible `{3}`, to-admissible `{2,3}` |

The two regions' active sets were respectively `{0,1,4,5}` and `{2,3,6,7}` in every emission. Thus the previously suspected absence of side-path face 3 from the second region's admissible set **is falsified by this probe**. The published corner's earlier observed face 7 versus side path face 3 remains an actual mismatch; the present census does **not** establish why the producer selected 7 despite the later independently measured admissible alternative 3. It does not prove that a proposed endpoint binding preserves all source ownership, route/chart, hard-rail, or paired-edge invariants.

## Retry history and disposition

Two harness orchestration failures produced **no valid test evidence**: [38851813094](https://github.com/akashskypatel/Directional/actions/runs/38851813094) rejected an invalid uniqueness assumption on an intentionally repeated test identity before execution; [38851975506](https://github.com/akashskypatel/Directional/actions/runs/38851975506) attempted 44 commands but selected zero tests because Python ZIP extraction dropped executable permissions. Both failures were diagnosed and the harness corrected without changing the CB6 semantic source, test source/assertions, fixtures, selectors, or benchmark. The third, successful attempt used archive-mode-preserving `unzip` and captured its mandatory diagnostic log.

All 44 RED remain an **R4-VIN-01 candidate / non-stable diagnostic vintage**, not a newly established stable regression recurrence or accepted-green loss. Preserve frozen 66/17/49, debt 1; CP2 491/491, R3 403/497, 497 selector, RP-02 UNREACHED. The `RP-01` repair premise is now supported at the observed side/endpoints, but **no repair implementation or next Code + Build turn is authorized within TB6**. A separate independent review must adjudicate the remaining published-face contradiction and the permissible repair contract.

This report is evidence-only; no producer, tests, build system, or selector changed during TB6.
