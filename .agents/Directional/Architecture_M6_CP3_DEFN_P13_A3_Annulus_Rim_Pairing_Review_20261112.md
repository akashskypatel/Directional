# RA-229 — Annulus rim pairing (step 64D.8)

Turn `M6-CP3-DEFN-P13-A3-ANNULUS-RIM-PAIRING`, Review agent only, runtime-free. Input: TB109 (944/944, scoped MATCH; [report](Architecture_M6_CP3_TB109_P13_A3_Annulus_Rim_Edge_Schedule_Full_Gate_Execution_Report_20261112.md)), RA-228 §5.

## 1. What TB109 showed

Row 729 (`SurfaceCellsPhase10.ExactCommittedCylinderReachesAuthoritativePeriodicProducerBoundary`, `lengthRatio = 0.2`):

`annulus-read case=CommittedCylinder rimEdges=32 readable=32 equalOutput=24 outputRimEdges=56 recorded=0`

- Every rim edge reads, so arc ends are breakpoints and splits are even.
- On 8 of the 32 rim edges, the plan's count differs from the count the annulus builds today. The annulus builds 28 per rim.
- Every other receipt is unchanged (41/41).

**Correction to RA-228.** RA-228's route condition (`equalOutput = rimEdges`) tests whether the switch leaves the counts unchanged. That is stronger than what the annulus needs. TB109 does not show that the rims fail to pair: the plan may give both rim edges of a strip the same new count. RA-228 §7's prediction for the row 729 line assumed unchanged counts, so it does not hold if CB129 lands; §4 below replaces it.

## 2. Findings

| # | Finding | Evidence |
|---|---|---|
| F1 | **A3 does not owe paired rims.** Baseline A3 (M4-CP3-DEFN-R1) guarantees a positive count per arc, identical shared subdivisions, and an even boundary-count sum per region. Equal counts on opposite sides were a property of the framed Bi-MDF schedule, which was superseded; it returns only with an upstream frame certificate and a new definition. A4 owns constructibility from the baseline counts | DESIGN §4.7, §4.9, A3 paragraph near line 704 |
| F2 | **The two count rules differ.** The annulus counts a strip as `llround(mean strip length over both rims / mean of four vertex targets)`. A3 counts each rim edge from its own D7 integral of `1/h`, rounded half down, then flips parities in a minimum T-join. Near a half, they round differently, so differing counts are expected and say nothing about pairing | `SurfaceCellTracing.cpp:14894–14945`; DESIGN D7 |
| F3 | **Pairing can be measured on today's product.** Each annulus strip spans whole lattice columns on both rims, so the two rim edges under one column form a strip. Comparing the plan's counts on those two edges decides readability without changing a producer | annulus lattice `:14949–14972`; output edge route steps |
| F4 | **If a strip does not pair, the product lattice cannot read it.** Two cases follow. (a) Equal rim totals with unequal strips: a singularity-free quad annulus exists, but its columns would not follow ring vertices. (b) Unequal totals: no singularity-free quad annulus exists, since a regular quad annulus has equal boundary lengths, and A3 parity only makes the sum even. Both are A4 constructions, not D4 reading rules | annulus chart construction |

## 3. Decision

1. **A3 stays as it is.** A pairing constraint in A3 would be a framed schedule (F1). It would change every fixture's plan to serve one producer.
2. **The annulus reads the plan only when every strip pairs** (RA-228 §3, unchanged). Measure pairing on row 729 before CB129 (CB130 → TB111).
3. **If row 729 pairs fully:** apply CB129 unchanged. TB110 is re-registered in §5.
4. **If not:** CB129 is withdrawn, and the annulus keeps its own counts and records no intervals, as today. New obligation **O40**: an annulus whose A3 rim counts do not pair needs an A4 construction (case a or b of F4). It goes to the Review-only `M6-CP3-DEFN-P13-A4-ANNULUS-COUNT-TRANSITION`. The O36 precondition "annulus rims readable under the switch schedule" then waits on O40. The O36 annulus clause (rim vertices are chain stops, RA-228) stands either way.

## 4. CB130 — rim pairing receipt (compile only, test only)

[Exact patch](Architecture_M6_CP3_CB130_P13_A3_Annulus_Rim_Pair_Census_Exact.diff): SHA-256 `009166a110f887198d556bdf8abd28c0e388c9ab28542e454376a39817290dc0`, 78 lines, no single-space context lines. Numstat: `45 1` `tests/SurfaceCellsPhase10Tests.cpp`. Base: HEAD `e2aa661e1` (CB128 source `739e79e2…` plus documentation).

- **What it adds:** in row 729, the rim edge under each lattice column on each rim, the plan's count for each readable rim edge, and one new line printed before the `annulus-read` line:
  `annulus-pair case=CommittedCylinder strips=S paired=P rimSources=E0/E1 planRims=T0/T1`
  It asserts nothing new, and no product source changes.
- **Patch checks:** the `annulus-read` line is unchanged. CB129 still applies on top of CB130, and `-fsyntax-only` returns 0 on CB130 alone and on CB130 with CB129.

Mismatch → `M6-CP3-PLAN-P13-A3-ANNULUS-RIM-PAIR-CENSUS-STOP`; infrastructure → `M6-CP3-CB130A-P13-A3-ANNULUS-RIM-PAIR-CENSUS-ORCH`.

## 5. TB111 — full gate, and the route it decides

`M6-CP3-TB111-P13-A3-ANNULUS-RIM-PAIR-CENSUS-FULL-GATE-EXEC`. Manifest `gates/Architecture_M6_TB111_P13_A3_Annulus_Rim_Pair_Census_Full_Gate_Case_Manifest.tsv`: TB109's byte for byte (944 rows, `46e5c8a8ffb1a8d6337d782bef44fa852d3b17870e2f06ab037d55a8ea201f61`, membership 1,025, `SELF_CHECK_PASS cases=944 deferred=81`).

**MATCH needs all of:**
- 944/944.
- All 41 TB109 receipt lines and the row 729 `annulus-read` line byte-identical.
- Census unchanged.
- The `annulus-pair` line with `strips=16 rimSources=16/16`: one strip per ring edge, 16 rim edges per rim. `paired` and `planRims` are recorded as evidence.

Mismatch → `M6-CP3-TB111-P13-A3-ANNULUS-RIM-PAIR-CENSUS-FULL-GATE-REV`; infrastructure → `M6-CP3-TB111A-P13-A3-ANNULUS-RIM-PAIR-CENSUS-ORCH`.

**Route after MATCH:**
- `paired=16` (then `planRims=T/T`): successor is `M6-CP3-CB129-P13-A3-ANNULUS-RIM-CONSUMPTION`. The patch is unchanged (`ce80f25e…`), and its base becomes CB130.
- `paired<16`: successor is the Review-only `M6-CP3-DEFN-P13-A4-ANNULUS-COUNT-TRANSITION` (O40), and CB129 is not applied. The follow-on must say which F4 case row 729 is, from `planRims`.

**TB110 re-registered (replaces RA-228 §7's row 729 condition; everything else in §7 stands):**
- The row 729 line becomes `annulus-read case=CommittedCylinder rimEdges=32 readable=32 equalOutput=32 outputRimEdges=2T recorded=2T`, with T from TB111.
- The `annulus-pair` line stays byte-identical to TB111: the plan does not change, and the same source edges pair.
- Row 729 stays PASS.
- Anything else is a mismatch and goes to `M6-CP3-TB110-P13-A3-ANNULUS-RIM-CONSUMPTION-FULL-GATE-REV`. The manifest stays TB109's.

## 6. Sequence

| Step | Turn | Owner |
|---|---|---|
| 64D.8 **COMPLETE** | `M6-CP3-DEFN-P13-A3-ANNULUS-RIM-PAIRING` (this record) | Review |
| 64D.9 | `M6-CP3-CB130-P13-A3-ANNULUS-RIM-PAIR-CENSUS` (§4) | implementation agent |
| 64D.10 | `M6-CP3-TB111-P13-A3-ANNULUS-RIM-PAIR-CENSUS-FULL-GATE-EXEC` (§5) | implementation agent |
| 64D.6 / 64D.7 | CB129 → TB110 (re-registered), only if `paired=16` | implementation agent |
| or | `M6-CP3-DEFN-P13-A4-ANNULUS-COUNT-TRANSITION` (O40), if `paired<16` | **Review agent only** |
| later | O36 switch definition (annulus clause; O40 if opened) | Review |

**Gaps, stated.**
- Strips are paired through today's output columns. That is the annulus's own ring correspondence, which the test cannot see directly.
- Only row 729 is measured. Row 935 already has `equalOutput=32`, so its strips pair trivially.
- If `paired<16`, row 729 keeps producing without A3 intervals until O40 is resolved.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | TB111 = TB109 manifest byte for byte; selector497/CP3 unpromoted |
| Decisive claims re-derived | TB109 report, the annulus count code, DESIGN §4.7/§4.9/A3/D7, row 729 test and CB129's hunks read by me |
| Runtime-free checks | CB130 applies at HEAD; CB129 applies on CB130; `-fsyntax-only` returns 0 on the test file (CB130) and on the test file and `SurfaceCellTracing.cpp` (CB130 + CB129); manifest self-check passes |
| Non-vacuity | `strips=16 rimSources=16/16` is a MATCH condition, so a wrong column-to-edge pairing goes to REV; `paired` decides the route |
| Obligations carried | 64D.9–64D.10, then CB129/TB110 or O40; O36 (annulus clause); D9c 65A; trace 65B; A4 65C; D8 65D; D6 user decision pending; O34 (narrowed); O35; O37; O38; P13-e, O30b, O31, O32b–e, O33 |
| Stable accounting | CP2 491/491, stable 66/17/49, debt 1, deferred 81; TB109 944/944, membership 1,025 |
| Turn boundary | No product or test source changed in the repository |
