# RA-121 — TB23 reviewed: one site owns all ten torus A5 rows; the occurrence chart face disagrees with its own seam span; seam-face measurement before DEFN-ISO (2026-10-21)

**Turn:** `M6-CP3-TB23-RP01-TORUS-A5-SITE-HARVEST-REV`. **Input:** TB23 report `Architecture_M6_CP3_TB23_Torus_A5_Site_Harvest_Report_20261021.md`; plan per RA-120. **Lines:** RP = `src/pipeline/RemeshPipeline.cpp` at `c6e90916e` (HEAD sources identical); CP2 = `5ce3132ec`.

## RA-121.1 Harvest verified

- Run [39609365590](https://github.com/akashskypatel/Directional/actions/runs/39609365590) success (single runtime dispatch); result `12348649684`, ZIP SHA-256 `5ce73745…6d1` recomputed locally and equal to the provider digest; expires 2026-11-04T13:37:29Z.
- 20/20 result hashes; 16 raw-log hashes match the ledger; 16/16 selected, zero skips, 6 PASS / 10 RED; `site_bad=0`, `ctrl_bad=0`; package, source, view and frozen selectors unchanged; no compile, relink or benchmarks.
- The pre-execution harness fix `0948a81b0` is accepted: direct-path messages carry no `a5-side`/`a5-wedge` suffix, so any label is admissible there; the pipeline rows keep the suffix check.

## RA-121.2 Predictions adjudicated

- **P1 held.** Every isolation failure carries a site; all pipeline rows say `a5-side` with `relation-collinear-seam`; no `valid` clause.
- **P2 held, more strongly than predicted.** One byte-identical site across all ten RED rows, so the W and T fixtures fail at the same relation.
- **P3 held.** `focused30:24` has one A5 failure; it names torus faces 120 and 97, which the square hard-rail and split-isolation fixtures do not have.
- **P4 held; F is closed at candidate level.** `selector:447` PASSES (CP2 row recovered, candidate only); `focused30:6` now reaches A5 and joins A5-ISO (10 rows).
- **P5 held.** All five controls PASS with no site.

## RA-121.3 The site, decoded

`relation-collinear-seam;region=0;seam=60,61;relation=0:1,1:0;first=120/0;second=97/2;certs=1;cert0=120/0->97/2:first-face`.
- Labels are `<source face row>/<sheet>`, and a row is a unique source face, so this is exact face identity. In `torus.obj`, faces 120 `[61,60,1]` and 97 `[49,60,61]` are the only two faces on edge 60–61.
- An `OrdinaryFront` relation between cell 0 corner 1 and cell 1 corner 0 runs along the certified seam. Cell 0's span is on face 120 (sheet 0) and cell 1's on face 97 (sheet 2). The single A4 certificate `120/0 -> 97/2` equals both spans exactly.
- The failing clause `first-face` (RP:3891) means occurrence (0,1)'s `placement.selectedFace` is not face 120. `selectedFace` is the A2 corner trace face (RP:4448, RP:4457), the face whose chart carries that corner's lattice. The second-face clause was never evaluated.
- **Routing (RA-120 pre-registration):** `first-face` → H-ISO-2, refined. The A4 certificate agrees with A5's span authority. The disagreement is inside one occurrence: its chart face versus its own seam span. H-ISO-3 is excluded.

## RA-121.4 Design finding: the face requirement is post-CP2, and the evidence cannot yet choose its owner

- **At CP2,** A5 attached no seam certificate to relations. A6 took cross-sheet seam sides from the span sheets and span transitions alone (CP2 RP:5295–5311), and never consulted `selectedFace`. The equality `span.interiorBinding.face == placement.selectedFace` arrived after CP2: first through the certificate lookup, then in R2 `88aa8eae0`, and it became fatal in `8be01326d`.
- **Not admissible:** restoring a silent fallback. That would compare a certified cross-sheet relation as same-sheet, which `8be01326d` correctly forbids.
- **Two branches with different owners:**
  - **B-across:** `selectedFace` is 97 (sheet 2) and the corner lies on the edge interior. Cell 0's corner lattice is then charted on the other sheet. The owner is A2 corner placement on certified seams, or an A5 lattice transport through the certificate.
  - **B-fan:** `selectedFace` is a sheet-0 fan face of vertex 60 (`96, 99, 122, 123`) or 61 (`118, 119, 121, 142`). The clause then conflates a chart gauge with a seam side. DEFN-ISO would take the side from the span binding and relate the chart face by an in-sheet chart transition.
- Whether relaxing the face clause alone would yield a unique direction is also unmeasured (`first-side`, `second-side`, `same-side` were never reached). DEFN-ISO written now would guess, so the next unit measures (LESSONS §5).

## RA-121.5 Next unit — `M6-CP3-CB23-RP01-TORUS-A5-SEAM-FACE-SITE` (Code + Build, compile only)

RP only, inside the `relation-collinear-seam` block: after the certificate loop, before `error.isolationSite = std::move(site);`. Append, in this order:
1. `;sel=<a>,<b>`: each canonical occurrence's `placement.selectedFace` as `<row>/<sheet>`, using `sourceTopologyRegions().row_for_topology` and `sheet_for_row`; `none` without a row.
2. `;support=<a>,<b>`: `vertex`, `edge` or `face` from `authority::support_kind(occurrence.support)`.
3. `;wedge=<a>,<b>`: each occurrence's `cornerWedgeBindings` as `isolation_binding_label` values joined by `+`.
4. For each matching certificate, in `certN` order, `;spanOnlyN=<v>`: the existing classifier without the two face clauses. That gives `same-sheet`, `first-side`, `second-side` or `same-side`, else `forward` (First/Second) or `reverse` (Second/First).

Invariants: no decision, return or error-code change; existing site text byte-identical, with the new fields only appended after the last `certN`; header, TQ and every other file byte-identical to `c6e90916e`; at most 100 columns. Eight-target GMP/GMPXX compile with `runtimeExecution=false`. Record `Architecture_M6_CP3_CB23_Torus_A5_Seam_Face_Site_Code_Build_Record_20261021.md`, at most 30 lines. STOP on any compile error or any need to edit outside the block.

## RA-121.6 TB24 frame (CB23-REV adds the package and issues the plan)

- **Rows (9):** A5-ISO `focused30:20` (W/P), `selector:444` (T/P), `focused30:28` (T/D, G4-B002); guard `selector:447`; controls `cp3entry:6`, `selector:217`, TB18 A#14, `selector:443`, `focused30:7`.
- **Predictions:** the TB23 site prefix is byte-identical in all three A5 rows, and the new fields are identical across them; the guard and the controls PASS with no site.
- **Routing for TB24-REV:**
  - `sel` first `97/2` with `support` `edge` → B-across;
  - a sheet-0 fan face with `vertex` → B-fan;
  - a `spanOnly` value other than `forward` or `reverse` → relaxing the face clause is insufficient, and DEFN-ISO must also own that clause.

## RA-121.7 Unchanged and sequence

66/17/49, debt 1, CP2 491/491, R3 403/497 rejected, selector 497 frozen, TB21 candidate 449/497. TB23 is candidate evidence: no count changes. `RP-01` open, `RP-02` UNREACHED, Gate C suspended.

Sequence: **CB23** → CB23-REV → TB24 → TB24-REV → DEFN-ISO → corrective CB/TB → DEFN-M1 → corrective CB/TB → DEFN-T1 → fixture debt → census → RP-01 Review.
