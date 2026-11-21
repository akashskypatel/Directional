# RA-222 — D4 uniform plan consumption (step 64C)

> **AMENDED (2026-11-10) by [RA-223](Architecture_M6_CP3_DEFN_P13_A3_Uniform_Plan_Consumption_Adversarial_Review_20261110.md).** The decision, CB117 and TB98 stand. TB98's MATCH route is now `M6-CP3-CB118-P13-A3-UNIFORM-DECLINES-CHAINED-PLAN`; CB118 → TB99 are added before 64B.13; O34 joins the switch preconditions.

**Turn:** `M6-CP3-DEFN-P13-A3-UNIFORM-PLAN-CONSUMPTION` (64C, Review). **Disposition: COMPLETE.** The D4 contract for the uniform producer is decided (§2). Its production switch is **not** frozen, because it shares its preconditions with the D5 switch (§3). One narrow, test-only patch is frozen instead: CB117 reports, for each produced gate fixture, the rim counts of both A3 schedules against the output; TB98 gates it. Runtime-free: syntax checks only; no product or test source changed in the repository.

## 1. What was read

- **Dispatch** (`SurfaceCellTracing.cpp:18676–18690`): each A1 region is offered to the uniform producer, then the periodic annulus producer, then the curved bounded-disk producer. A producer that returns `NotApplicable` passes the region on; a `Rejected` region rejects the whole phase front.
- **Uniform producer** (`:13417`): builds a planar frame and a uniform lattice from the target size. It never reads the A3 schedule. Under a plan it already declines regions that touch a hard feature (`:13465`), with the comment that the curved producer "owns that cutover" because the uniform producer "cannot publish the required typed shared-boundary interval identity".
- **Bounded-disk producer** (`:15538`): the only reader of A3 counts and breakpoints (RA-220 §1). It handles regions without a hard feature through its non-cut-domain branch.
- **Evidence** (RA-213, unchanged since): A3 boundary edges against output boundary edges are Plane 42 vs 32, MultiFaceSeam 48 vs 32, CloseSheets 96 vs 80. All four produced fixtures report `covered=0` on their rim spans.
- **TB96 and TB97 receipts** (both MATCH): on the rectangular hard-rail fixture a unit edge counts 4 and a two-edge chain counts 8, and the bounded-disk producer built the mixed chained plan (`disposition=Produced covered=16/16`).

## 2. Decision: the uniform producer declines under an A3 plan

DESIGN §2.1 item 7 requires every region's construction to consume the certified plan unmodified. A region produced under a plan must therefore place its boundary vertices on the plan's breakpoints and record a unit interval on every boundary cell edge, so that `summarize_a3_span_coverage` shows each of its spans covered.

Two ways to meet this were weighed:

| | Adopt in the uniform producer | Decline to the bounded-disk producer |
|---|---|---|
| Change | Rebuild the uniform lattice from boundary breakpoints, add interval recording | One condition: decline whenever a plan is present |
| A3 readers | Two producers reading counts, breakpoints and bindings | One |
| Non-uniform breakpoints | A uniform lattice cannot place them; needs the bounded-disk interpolation anyway | Already handled |

**Decided: decline.** Under an A3 plan the uniform producer returns `NotApplicable` for every region, not only for hard-feature regions. The bounded-disk producer is the single disc producer that consumes A3. The uniform producer stays for callers without a plan. The annulus producer is a separate definition (64D).

The switch itself is one line (`:13465`: drop `&& region_has_hard_feature()`), plus the oracles in §3.

## 3. Why the switch is not frozen now

Declining hands Plane, MultiFaceSeam and CloseSheets to the bounded-disk producer, which rejects a region whose opposite sides differ in interval count. A rejection there rejects the whole phase front. Under today's per-arc schedule those fixtures schedule 42, 48 and 96 rim intervals where the uniform grids have 32, 32 and 80; nothing shows that their per-arc side sums agree pairwise.

The chained schedule gives each rail between stops one metric count, which is what a rectangle needs. So the D4 uniform switch has the same preconditions as the D5 switch (O36): chained production input, and disc corners as stops (O38, decided; 64B.13). The two switches are best frozen together, and neither has per-fixture evidence yet. RA-221 F3 asked for exactly that evidence.

**What the D4 switch TB must carry** (registered now, frozen with the switch):

1. positive: every produced gate fixture reports `unrecorded=0` and `covered=scheduled` on its `a3-coverage` line, and its `d4-rim` line shows output = scheduled on every side;
2. omission falsifier: dropping one rim interval from a produced product makes coverage report one partial span (the RA-215 rim test already does this on the rectangular fixture);
3. row permutation: the reversed-face-row variant produces the same coverage;
4. a pre-registered list of the digests allowed to change (the three uniform fixtures) and those that may not (Cylinder until 64D, closed surfaces always).

## 4. CB117, frozen — rim census receipt (test only)

- [Patch](Architecture_M6_CP3_CB117_P13_A3_Rim_Census_Receipt_Exact.diff): SHA-256 `f2238aebf8a98eee00c3842c37f6cf1e97607e3c6d94734295d3a6add06e8c8b`, 206 lines, 1 single-space context line. Numstat `188 0` `tests/SurfaceCellDesignAcceptanceTests.cpp`. Base is product source CB116 `57c253ba7…`; `git apply --check` is clean at HEAD. No product source changes.
- **Adds** a parameterized test, `ProducedGateFixtures/SurfaceCellDesignD4RimCensus.ReportsRimCountsAgainstTheA3Schedules`, over Plane, MultiFaceSeam, CloseSheets and Cylinder. It runs the pipeline with retained products and prints one line per fixture:

  `d4-rim case=<name> inputs=own|foreign phaseFront=Produced|NotProduced rimArcs=… sides=… perArcTotal=… outputRimEdges=… unresolved=… arcs:perArc/chained/output/recorded=<one entry per side>`

  A side is a chained span on a source-boundary rail. Each entry gives its arc count, the sum of the per-arc counts on those arcs, the chained count, the number of output rim edges whose first route step lies on the side, and how many of those record an interval.
- **Asserts** (firm, none about agreement between the three counts): the plan, baseline and network are published; when the test's inputs reproduce the published baseline, the chained input exists, schedules arcs − chained arcs spans, builds and validates. This is the first run of the chained factory and validator on benchmark meshes.
- **`inputs=foreign`** is printed, and the chained column is `-`, if the benchmark vertices and target size do not reproduce the published baseline (for example after preconditioning). That is a reported state, not a failure.
- **Checks:** `-fsyntax-only` returns 0 on the test file.
- **Registered gaps.** Vase and BunnyRandom are not in this test: they are census-only rows, Vase has no produced phase front and BunnyRandom has no rim. A side is counted by an output edge's first route step, so an edge that spans a corner is counted once, on its first side. Which sides are opposite is not printed; on a rectangle the sorted list shows it.

## 5. TB98, frozen

- [Manifest](gates/Architecture_M6_TB98_P13_A3_Rim_Census_Receipt_Full_Gate_Case_Manifest.tsv): 935 rows, SHA-256 `2c967a93e54223000b30539f8be76a2240d68f874446d9d77350846856e5a3a6`. It is TB97's 931 rows byte for byte, plus GUARD 932–935. `SELF_CHECK_PASS cases=935 deferred=81`; membership 1016; ledger v5 and harness unchanged.

| Outcome | Route |
|---|---|
| 935/935 PASS; all 7 platform-digest and 7 a3-coverage lines byte-identical to TB97; census unchanged; the 4 `d4-rim` lines recorded verbatim | MATCH → `M6-CP3-DEFN-P13-A3-DISC-CORNER-STOPS` (64B.13, **Review agent only**) |
| Any failure in 932–935, any regression in 1–931, or any digest change | MISMATCH → `M6-CP3-TB98-P13-A3-RIM-CENSUS-RECEIPT-FULL-GATE-REV` (Review) |
| Infrastructure | `M6-CP3-TB98A-P13-A3-RIM-CENSUS-RECEIPT-ORCH` |

**Registered predictions (not pass conditions).** Plane: 4 sides, with `chained` equal to `output` on each (8 per side) and `perArc` larger. *(TB98: 4 sides and `perArc` larger held; `chained` equal to `output` was false, 10 against 8. See [RA-224](Architecture_M6_CP3_DEFN_P13_A3_Disc_Corner_Stops_Review_20261110.md) §1.)* `recorded=0` on every uniform fixture. Cylinder: `output` equals `perArc` on its rims.

## 6. O36 after TB96 and TB97

| Condition | State |
|---|---|
| Mixed stage produces, or hard-feature rails chain (O35) | **Met for the rectangular fixture** (TB97: Produced, 16/16). Other model classes: the `d4-rim` lines |
| Disc corners cannot fall inside a span (O38) | Decided; 64B.13 defines the work |
| Breakpoints located in one pass (O37) | Open; frozen with the switch |
| Switch TB pre-registers digest changes and amends the named tests | Open |

The D4 uniform switch joins O36: both wait for 64B.13 and the TB98 lines, and are to be frozen as two separate CBs by one definition after them.

## 7. Sequence

| Step | Turn | Owner |
|---|---|---|
| 64C | `M6-CP3-DEFN-P13-A3-UNIFORM-PLAN-CONSUMPTION`: COMPLETE (this record) | Review |
| 64C.1 | `M6-CP3-CB117-P13-A3-RIM-CENSUS-RECEIPT`: exact patch §4, compile only. Mismatch → `M6-CP3-PLAN-P13-A3-RIM-CENSUS-RECEIPT-STOP`; infrastructure → `M6-CP3-CB117A-P13-A3-RIM-CENSUS-RECEIPT-ORCH` | implementation agent |
| 64C.2 | `M6-CP3-TB98-P13-A3-RIM-CENSUS-RECEIPT-FULL-GATE-EXEC` (§5) | implementation agent |
| 64B.13 | `M6-CP3-DEFN-P13-A3-DISC-CORNER-STOPS` (O38); reads the `d4-rim` lines | **Review agent only** |
| 64D | `M6-CP3-DEFN-P13-A3-ANNULUS-PLAN-CONSUMPTION` | **Review agent only** |
| later | D5 and D4 uniform switches (O36), then 65A–65D, 66+ | Review DEFN, then CB, then TB each |

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | TB98's rows 1–931 are TB97's manifest byte for byte. Selector497/CP3 is unpromoted |
| Decisive claims re-derived | §1: dispatch, the uniform producer's applicability rules, the bounded-disk non-cut-domain branch, the acceptance test's digest helper and retention flag, the TB96 and TB97 reports |
| Non-vacuity | §4: the factory and validator assertions run on four benchmark meshes; the receipt is evidence, not an assertion |
| Obligations carried | 64C.1–64C.2; 64B.13 (O38); 64D; D9c 65A; trace 65B; A4 65C; D8 65D; D6 user decision pending; O34; O35; O36 (now also the D4 uniform switch); O37; P13-e, O30b, O31, O32b–e, O33 |
| Stable accounting | CP2 491/491, stable 66/17/49, debt 1, 81 deferred; TB97 931/931, membership 1012; selector497/CP3 unpromoted |
| ORIENTATION / CHANGELOG / LESSONS / tracker / DESIGN §7.4 / handoff / TODO | Updated |
| Turn boundary | No product or test source changed in the repository |
