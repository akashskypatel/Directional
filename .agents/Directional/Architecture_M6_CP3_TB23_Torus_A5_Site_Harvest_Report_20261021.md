# TB23 — Torus A5 isolation-site harvest (2026-10-21)

- **Authority:** artifact-only Test + Benchmark `M6-CP3-TB23-RP01-TORUS-A5-SITE-HARVEST`; semantic source `c6e90916eb90bfd33bc8a38c5ece7def15dcc766`, immutable CB22B package `12341307713` (ZIP `b5f9a6688226375ea1c6241c2d9a464d9b9ede7679f9259acd03b3fbbb1c8ad5`).
- **Execution:** [run 39609365590](https://github.com/akashskypatel/Directional/actions/runs/39609365590), result `12348649684`, ZIP SHA-256 `5ce737452a23637e74f0241f5f8a9a0ebe34b874b83ad1ff2d0d6f4456ee34d6`; harness executor `0948a81b09e5ff07d240d01f8968f225c285ac2c`, harness SHA-256 `bf2cb7bc2799137e9a3556816380dc93388e9e05ee134cf320b068411f982cbe`.
- **Integrity:** 28/28 preflight and postflight package hashes; 20/20 result files verified against `SHA256SUMS`; 16/16 selected/executed in distinct processes, zero skips, 6 PASS / 10 RED; source, package, execution view and frozen selectors unchanged; `compile=false`, `relink=false`, `benchmarks=false`, `selector497=false`, `exit=0`. No rebuild.
- **Site notation:** all ten RED rows share full `site_raw=relation-collinear-seam;region=0;seam=60,61;relation=0:1,1:0;first=120/0;second=97/2;certs=1;cert0=120/0->97/2:first-face`. Full untruncated per-row occurrences and raw-log hashes are in the immutable result `ledger.tsv`.

| Key | Fixture | Path | Verdict | Label | Region | Seam | Certificate / first clause |
|---|---|---|---|---|---|---|---|
| `focused30:20` | W | P | RED | relation-collinear-seam | 0 | 60,61 | cert0=120/0->97/2:first-face |
| `selector:446` | W | P | RED | relation-collinear-seam | 0 | 60,61 | cert0=120/0->97/2:first-face |
| `focused30:24` | W | D | RED | relation-collinear-seam | 0 | 60,61 | cert0=120/0->97/2:first-face |
| `focused30:25` | T | P | RED | relation-collinear-seam | 0 | 60,61 | cert0=120/0->97/2:first-face |
| `focused30:26` | T | D | RED | relation-collinear-seam | 0 | 60,61 | cert0=120/0->97/2:first-face |
| `focused30:27` | T | D | RED | relation-collinear-seam | 0 | 60,61 | cert0=120/0->97/2:first-face |
| `focused30:28` | T | D | RED | relation-collinear-seam | 0 | 60,61 | cert0=120/0->97/2:first-face |
| `selector:444` | T | P | RED | relation-collinear-seam | 0 | 60,61 | cert0=120/0->97/2:first-face |
| `selector:448` | T | P | RED | relation-collinear-seam | 0 | 60,61 | cert0=120/0->97/2:first-face |
| `focused30:6` | W | P | RED | relation-collinear-seam | 0 | 60,61 | cert0=120/0->97/2:first-face |
| `selector:447` | W | P | PASS | — | — | — | — |
| `cp3entry:6` | — | — | PASS | — | — | — | — |
| `selector:217` | — | — | PASS | — | — | — | — |
| `TB18 A#14` | — | — | PASS | — | — | — | — |
| `selector:443` | — | — | PASS | — | — | — | — |
| `focused30:7` | — | — | PASS | — | — | — | — |

- **P1 observed:** every A5 isolation failure carries the site; all reported labels match the `a5-side` suffix where present, and no certificate clause is `valid`.
- **P2 observed:** all three W A5 rows and all six T A5 rows agree on label, region and seam; W and T agree with each other.
- **P3 observed:** `focused30:24` has exactly one A5 failure, in the witness fixture's third `verify` call.
- **P4 observed:** both F rows pass atlas binding: `focused30:6` reaches A5 (RED, same witness site), while `selector:447` PASSES its typed-negative oracle; neither fails at `InvalidSourceAuthority`.
- **P5 observed:** all five controls PASS and have no `site=`.
- **Disposition:** diagnostic harvest complete, semantic A5-ISO still RED; no root-cause verdict or accepted production/selector promotion. Mandatory next turn: `M6-CP3-TB23-RP01-TORUS-A5-SITE-HARVEST-REV`; it adjudicates the certificate/occurrence mismatch (H-ISO-1/2/3). Stable 66/17/49, debt 1, accepted CP2 491/491 and candidate TB21 449/497 unchanged.
