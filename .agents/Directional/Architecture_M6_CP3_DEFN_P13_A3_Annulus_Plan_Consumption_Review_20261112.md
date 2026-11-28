# RA-227 — Annulus plan consumption (step 64D)

Turn `M6-CP3-DEFN-P13-A3-ANNULUS-PLAN-CONSUMPTION`, Review agent only, runtime-free. Inputs: TB107 (943/943, scoped MATCH), RA-222 (D4 uniform), RA-226 F4 (the ring scoring's own alignment rule).

## 1. What happened since RA-226

CB125 → TB106 → CB126 → TB107 applied the exact rim branch rule as the one owner. Every receipt matched RA-226's predictions: four `rim-branch` lines with `undecided=0`, zero disagreements, census unchanged (Cylinder PASS, BunnyRandom and Vase registered RED). O39 is discharged.

## 2. Findings

| # | Finding | Evidence |
|---|---|---|
| F1 | **The annulus producer does not read A3.** Each strip's count is `llround(mean strip length / mean local target)`. Rim cell edges record no interval. Under a plan it declines only regions with a hard feature | `SurfaceCellTracing.cpp:14284` (decline), `:14894–14945` (counts); TB98 `d4-rim case=Cylinder … recorded=0` on every side |
| F2 | **Declining is not available.** The D4 uniform answer (decline, let the bounded-disk producer build it) does not carry over. The bounded-disk producer returns `NotApplicable` for Euler ≠ 1 (`:16272`), so an annulus region declined by its producer has no producer, and the Cylinder fixture would stop producing | Dispatch `:18727–18741` |
| F3 | **The annulus lattice is a product.** Every ring layer uses the same u-breakpoints, and every source ring vertex is a breakpoint (`:14890`). To read a rim schedule, the two rim edges of each strip need breakpoints at both ends and the same split | `:14949–14972`, ring correspondence `:14723–14834` |
| F4 | **A chained schedule does not put a breakpoint at every rim vertex.** The locator spreads a span's ordinals over its runs by run weight. A run boundary is a breakpoint only when `count · prefix / total` is an integer. On a polygonal rim each edge is its own run, so a chain passing a rim vertex usually bridges it. That is legal for the bounded-disk producer, whose cell edges may bridge a vertex. It cannot be read by the annulus lattice | `GlobalConformityBaselineSupport.cpp:299–360`; exact model below |
| F5 | **Under the per-arc schedule the reading is exact and equals today's placement.** One source edge is one span of one piece, so its breakpoints sit at `k/n`. The annulus already places rim vertex `k` at `stripStart + (stripEnd − stripStart)·k/n` in its chart (`:14957–14962`). Only the count source and the interval record differ. On Cylinder the per-arc count is 2 on every rim arc and the output is 2 on every strip (TB98), equal by the fixture's symmetry, not by construction | TB98 `d4-rim` line |
| F6 | **RA-226 F4, the ring scoring, gets no code.** It chooses the ring correspondence and seed gauge from a mean of squared `acos` values. That is transcendental, so there is no rational exact form. It is not an A3 reader. Candidates within `256·eps·scale` reject as ambiguous, so an exact tie fails closed. Residual: two candidates whose true scores differ by less than the band also reject, and at the band edge rounding can flip produce/reject. The torus oracle stays as RA-226 left it | `:14505–14510`, `:14700–14811` |

Exact-fraction model of the locator (`rev227/model.py`, runtime-free):

| Case | Per piece: (ends are breakpoints, intervals, even split) |
|---|---|
| One piece, count 2 | (yes, 2, yes) |
| Two runs, equal weight, count 4 | (yes, 2, yes), (yes, 2, yes) |
| Two runs, weights 7 and 8, count 4 | (no, 2, no), (no, 3, no) |
| One run over two collinear pieces, count 3 | (no, 2, no), (no, 2, no) |

## 3. Definition (D4 annulus)

1. **Producer.** Under an A3 plan, an Euler-0 region with two rims and no hard feature stays with the periodic annulus producer. Its boundary is its two rims. The trace and cut spans inside it belong to A4 (65C) and the trace contract (65B), not to D4.
2. **Reading a rim.** A rim is walked in lattice order with the bounded-disk producer's side reader (one shared decomposition, RA-217): for each rim source edge, its Mandatory arcs, their bound spans, and the span breakpoints on each arc in walk order.
3. **Readable strip.** Strip `u` is readable when, on both of its rim edges (paired by the ring correspondence), every arc's two ends are breakpoints and the breakpoints split the edge at the same local parameters. Then the strip's count is that split's `n`, the rim lattice vertices are the plan's exact points, and each rim cell edge records its unit interval: span, consecutive ordinals, and `Forward` when the walk follows the chain.
4. **Unreadable strip.** A rim with an unreadable strip is not consumed. The producer rejects with `InvalidFrontBoundaryAuthority`, as the bounded-disk producer does for an unreadable side. This rule takes effect only with the reader (§6), never silently.
5. **Periodic identity.** `gridU = Σ n(u)`, which equals each rim's interval total. The holonomy keeps its form.
6. **Reversed-boundary tamper (the reader's test).** Reading a rim against its walk gives the same counts with `Reverse` orientation and descending ordinals. A rim whose binding orientation is flipped must be rejected.
7. **Height.** `gridV` and the interior lattice are unchanged.

## 4. CB127 — rim census (compile only, test only)

[Exact patch](Architecture_M6_CP3_CB127_P13_A3_Annulus_Rim_Census_Exact.diff): SHA-256 `d796c60dd0fa83c57194f89e9e97c949888d3a0e081a11ec1e7badb320a1d7da`, 110 lines, keep 1 single-space context line; numstat `99 0` `tests/SurfaceCellDesignAcceptanceTests.cpp`. Base: CB126 source `3ac6801e4bffb721ffce993cba1e4157b6fa31b8` (applies at HEAD).

It extends the existing rim census (rows 932–935). For each rim network edge it reads the per-arc, chained and stopped schedules through `breakpoint_location` and prints one line per schedule:

`annulus-rim case=<name> schedule=<perArc|chained|stopped> periodic=<P> rimEdges=<E> split=<S> vertexBreaks=<V> equalOutput=<Q> evenSplit=<U>`

`periodic` is the product's periodic holonomy count, so the line also shows which producer ran. `split` counts rim edges carrying two arcs. `vertexBreaks` counts edges whose arcs all have breakpoints on both ends. `equalOutput` counts those whose interval total equals the output rim edges there. `evenSplit` counts those split at `k/n` on every arc. Asserts only that every arc binds a schedule and every ordinal locates. No product source changes.

Mismatch → `M6-CP3-PLAN-P13-A3-ANNULUS-RIM-CENSUS-STOP`; infrastructure → `M6-CP3-CB127A-P13-A3-ANNULUS-RIM-CENSUS-ORCH`.

## 5. TB108 — full gate

`M6-CP3-TB108-P13-A3-ANNULUS-RIM-CENSUS-FULL-GATE-EXEC`. Manifest `.agents/Directional/gates/Architecture_M6_TB108_P13_A3_Annulus_Rim_Census_Full_Gate_Case_Manifest.tsv`, the TB107 manifest byte for byte (943 rows, `938836fc3326df11ccb3d475e0c6a3a4d629d8ac6e252436dcfac47286bfb651`, membership 1024; `SELF_CHECK_PASS cases=943 deferred=81`).

**MATCH needs all of:**
- 943/943;
- the 25 earlier receipt lines and four `rim-branch` lines byte-identical to TB107;
- twelve `annulus-rim` lines, all recorded verbatim;
- `annulus-rim case=Cylinder schedule=perArc` with `periodic` ≥ 1, `rimEdges=32 split=0 vertexBreaks=32 equalOutput=32 evenSplit=32`;
- the Cylinder `chained` and `stopped` lines identical apart from `schedule=` (no field corners, TB104);
- census unchanged.

Every other value is evidence, not a pass condition. Mismatch → `M6-CP3-TB108-P13-A3-ANNULUS-RIM-CENSUS-FULL-GATE-REV`; infrastructure → `M6-CP3-TB108A-P13-A3-ANNULUS-RIM-CENSUS-ORCH`. On MATCH close with `Successor: M6-CP3-DEFN-P13-A3-ANNULUS-RIM-SCHEDULE`.

## 6. Follow-on — `M6-CP3-DEFN-P13-A3-ANNULUS-RIM-SCHEDULE` (Review agent only)

It freezes the reader in two patches. The first extracts the bounded-disk side reader into one function, with a byte-identical TB. The second has the annulus read its rims through it, with the §3.6 tamper test on a hand-built ring and a switch TB whose digest changes are pre-registered from TB108. It also decides from the Cylinder `chained` line whether O36 needs an annulus clause: annulus rim vertices as chain stops, or chained rims left unread. That decision is why the reader is not frozen here. Its digest set and the O36 clause depend on TB108's numbers.

## 7. Sequence

| Step | Turn | Owner |
|---|---|---|
| 64D **COMPLETE** | `M6-CP3-DEFN-P13-A3-ANNULUS-PLAN-CONSUMPTION` (this record) | Review |
| 64D.1 | `M6-CP3-CB127-P13-A3-ANNULUS-RIM-CENSUS` (§4) | implementation agent |
| 64D.2 | `M6-CP3-TB108-P13-A3-ANNULUS-RIM-CENSUS-FULL-GATE-EXEC` (§5) | implementation agent |
| 64D.3 | `M6-CP3-DEFN-P13-A3-ANNULUS-RIM-SCHEDULE` (§6) | **Review agent only** |
| later | The O36 switch definition | Review, then implementation |

**O36 preconditions after this record:** as RA-226, plus **annulus rims readable under the switch schedule** (open; TB108 measures Cylinder, 64D.3 decides).

**Gaps, stated.** No fixture has rims of different length, so F4's failure is shown by the model, not by a fixture. The receipt counts per rim edge; equality across the two rims is implied only where the output is the annulus's own product lattice. The reader is not frozen. The F6 residual stands.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | TB108's manifest is TB107's byte for byte; selector497/CP3 unpromoted |
| Decisive claims re-derived | Annulus producer `:14244–14990`, dispatch, bounded-disk side reader `:17470–17882`, `bound_arc_schedule`, the locator and the coverage summary were read by me. The locator cases come from an exact-fraction model |
| Runtime-free checks | `-fsyntax-only` returns 0 on `SurfaceCellDesignAcceptanceTests.cpp` with CB127; CB127 applies at HEAD; manifest self-check passes |
| Non-vacuity | The Cylinder per-arc line is a MATCH condition; if the annulus did not run or split a strip differently, TB108 routes to REV |
| Obligations carried | 64D.1–64D.3; D9c 65A; trace 65B; A4 65C; D8 65D; D6 user decision pending; O34 (narrowed); O35; O36; O37; O38; P13-e, O30b, O31, O32b–e, O33. O39 discharged (TB107) |
| Stable accounting | CP2 491/491, stable 66/17/49, debt 1, deferred 81; TB107 943/943, membership 1024 |
| Turn boundary | No product or test source changed in the repository |
