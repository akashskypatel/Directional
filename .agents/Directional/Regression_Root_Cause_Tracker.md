## TB15 exact I-endpoint witness harvest — expected B2/B3 RED, no new stable regression (2026-10-18)

[Run 39170298228](https://github.com/akashskypatel/Directional/actions/runs/39170298228), result `12152685129` (ZIP SHA-256 `2536c38b958f76cfef6c5e0ef951e902e958d2cdb863e650e2b8b4002a50f748`), immutable CB15 semantic source `e4785d734e35d2f01ca3ee8099772f6ab5257f4c`, package `12150973440`. All nine exact tests selected and postflight-immutable: 4 PASS gates, 5 expected RED diagnostics. Two B2 tests retain no exact witness and binds 0; three B3 tests show matching bound `1,4@1/5` witnesses on both sides. Removing precisely the four new exact-witness fields makes all five first-failure records byte-equal to TB13A (#3–6) or TB14A (selector 217) baselines. **Classification:** existing `RP-01` B2/B3 causes, not newly introduced stable or candidate regressions; no early-admission behavioral change. **66/17/49**, debt **1**, CP2 **491/491**, rejected R3 **403/497**, latest full census **425/497** unchanged. Required independent TB15 Review before CB16. Owning report: `Architecture_M6_CP3_TB15_Exact_I_Witness_Harvest_Report_20261018.md`.

---

## TB14A curved-disk control census — adjudicated by RA-94 (2026-10-18)

[Run 39143325285](https://github.com/akashskypatel/Directional/actions/runs/39143325285), result `12141843937` (`1b06e43e…d455`), on CB14A package `12140756646` (source `2ee499a3`): **425 PASS / 72 RED**.
- Against TB13C, exactly five identities went RED → PASS (199/235/236/294/299) and none went PASS → RED. The 72 REDs are unchanged in substance (RA-94.2).
- 235/236/294/299 are restored curved-disk controls.
- 199 falsified RA-93.4. Its cylinder half was repaired after R3 by `2be228d96` (source A3 supplied, assertions unchanged), and the stale disk half hid that at TB13C. It is a valid control.
- 425 = R3 403 + 26 RED → PASS − 4 test-debt REDs (174, 191, 242, 442).
- No production regression; **66/17/49**, debt **1** unchanged.

---

## TB13D bisect — TB13C candidates resolved: test debt, no production regression (2026-10-18)

P1 [run 39132801755](https://github.com/akashskypatel/Directional/actions/runs/39132801755), result `12138931233`, source `007585f8e` (+32): 422/497. P4 [run 39132921344](https://github.com/akashskypatel/Directional/actions/runs/39132921344), result `12138633102`, CB12 `b1b02d5be`: 420/497, identical to CB13A on all 497. P2 and P3 were cancelled while pending (dispatcher concurrency) and are not needed.

**Classification (RA-92):** none of the 8 is a production regression, and none receives a stable ID.

| Ordinal | First RED | Cause | Class |
|---|---|---|---|
| 235/236/294/299 | by P1 | `make_curved_disk_fixture` lacks the rail provenance required since `c7cb5d68b`/`715fe2d66` | stale fixture (repair CB14A) |
| 242 | by P1 | `8df105b56` | test-spec defect |
| 191 | by P1 | `7ccdcd527`: the atlas build fails in the fixture and its error is dropped | fixture |
| 174 | after P1 | `18357617a`: non-manifold three-face TriMesh | fixture |
| 442 | after P1 | `b9f70f3fe`: seam assertion never run, `SingularityMismatch` | assertion never run |

This corrects RA-91's "production regression" label for the curved disk. **66/17/49**, debt **1** unchanged. Record: `Architecture_M6_CP3_TB13D_Bisect_Review_Decision.md`.

---

## CANDIDATE / NON-STABLE — TB13C census: 8 identities PASS at R3 are RED on CB13A (2026-10-18)

[Run 39127652521](https://github.com/akashskypatel/Directional/actions/runs/39127652521), result `12136761296` (ZIP SHA-256 `92d9c9bd…f545`), CB13A package `12132184878`: 497 executed, **420 PASS / 77 RED**, no orchestration failure. Inventory: `Architecture_M6_CP3_TB13C_Selector_497_Red_Inventory.tsv`.

The 8 identities that were PASS at R3 (`d82e34427`) and are RED now are all in selector449:

| Ordinal | First failure | Status |
|---|---|---|
| 235, 236, 294, 299 | Curved bounded disk: the pipeline returns `PublishedProductRejected`. Fixture and failing lines unchanged since R3. | Production regression, commit unknown |
| 242 | The must-reject seam test now produces. | Test-specification defect from `8df105b56`. Transport reads only the A3 atlas (S:5389-5397), so the tampered raw transitions are never consumed. |
| 174 | DCEL consistency exception | Unattributed |
| 191 | Periodic-route fixture A3 unavailable | Unattributed |
| 442 | FTA:2856 `seamBuilt` false | Unattributed |

**Classification (RA-91):** these are candidates, not stable IDs, until TB13D's retained-package bisect attributes them. The stable counts stay **66/17/49**, debt **1**. The 30 RP-01 identities (B2 11, B3 19) were RED at R3 and are not regressions. The 25 that were R3 RED and now pass are accepted as measured controls; no assertion was removed. Record: `Architecture_M6_CP3_TB13C_Census_Review_Decision.md`.

---

## TB13A — U3 scoped closure, no new stable regression (2026-10-18)

[Run 39121449664](https://github.com/akashskypatel/Directional/actions/runs/39121449664), result 12134411966, CB13A package 12132184878: two PASS gates; B2 (#3/#4) and B3 (#5/#6) expected RED byte-identical to TB13. No `open-rail-chain-interval` falsifier. U3 closed, B2 U4/U5 and B3 U6 still open. No new stable ID or historical-count change: 66 events / 17 categories / 49 recurrences; debt 1. See `Architecture_M6_CP3_TB13A_Truth_Table_Harvest_Report_20261018.md`.

**Classification (RA-90):** confirmed by independent re-verification, with #3–#6 compared directly against TB13. U3 is closed and B1 is cleared on the RP-01 fixtures. RP-01 stays open on B2 (U4/U5) and B3 (U6). The TB13C census measures how many of the frozen 497 each shape owns.

---

## CANDIDATE / NON-STABLE — TB13 reversed-route truth-table discrepancy (2026-10-18)

[TB13 run 39112131501](https://github.com/akashskypatel/Directional/actions/runs/39112131501), source `70217cc2`, package `12130290543`, result `12130683535` (ZIP SHA-256 `43505af2912b840262307db96865c5e7f9e2af8ca3b9cbe5426f0b18e87f4885`): six exact identities, **1 PASS / 5 RED / 0 missing**, immutable postflight. The required truth table expects `check({{4,7},{1,4}}, nullopt, nullopt, [1,4,7])` false, but its implementation returns true, consistent with RA-87.4's allowance of a reverse chain walk. **Candidate specification/test contradiction, not a demonstrated stable regression.** Independent Review must determine required semantics; do not change a test to obtain green. The two P10 diagnostics move from `open-rail-route-anchor` front 29/147 to `endpoint-1` front 61/179 (B2 rail-interior vertex 4). Both pipeline B3 raw 9,180-character first failures remain byte-identical to TB12 at `endpoint-1` front 17/203. RP-01 open, RP-02 UNREACHED; no direct production accepted or selector497 executed. Frozen totals **66/17/49**, debt1, CP2 491/491, R3 403/497, selector497, Gate C suspended. Owner: `Architecture_M6_CP3_TB13_Open_Rail_Chain_Interval_Harvest_Report_20261018.md`. Conditional TB13C held pending independent Review.

**Classification (RA-88):** not a regression and not a code defect. The false row in RA-87.4.7 contradicted RA-87.4.1's own either-direction rule: `[4-7, 1-4]` is the valid reverse walk 7→4→1. This is an owned Review specification defect. The helper is correct, and the RA-87.5 predictions for #2–#6 all held. Front 29/147 now passes the consumer interval rule on real data, which is the rule's first real-data coverage. CB13A corrects the row and adds three discriminating rows. **Falsifier:** at TB13A, #1 is still RED, or any #3–#6 `first_failure` differs from TB13.

---

## CANDIDATE / NON-STABLE — TB12: chain provenance gates pass; RP-01 diagnostics remain RED (2026-10-18)

[TB12 run 39103358061](https://github.com/akashskypatel/Directional/actions/runs/39103358061), immutable CB12 source `b1b02d5bed43898af0708d76dcd70ada96aeecc9`, compile artifact `12125223513`, result `12127706461` (ZIP SHA-256 `1b6c3babd942cfc7fc7bbeff94774bf719297fdb9bc7ca3c0088e40110f2dfee`). Exactly 6 selected / 0 missing, two focused gates PASS and four non-gating RP-01 diagnostics RED. #3/#4 retain the byte-identical TB11 `open-rail-route-anchor` predicate for front 29/147; #5/#6 reject earlier at `endpoint-1` and both raw first-failure lines contain `firstPredicate=`. **The CB12 publication validator is not reached** on these pipeline witnesses; no claim of production validation. All predictions in RA-86.4 are confirmed in the scope actually measured, and the CB12 falsifier `PublishedProductRejected` without `firstPredicate=` is absent. Existing unresolved `RP-01`, not an independently established new stable regression. The failure root remains the previously reviewed missing open-rail interval/interior-vertex contract (U3–U5), pending independent Review; the two control assertions do not prove the later mutation path. Preserve stable **66/17/49**, debt **1**, CP2 **491/491**, R3 **403/497**, selector **497**, RP-02 UNREACHED, Gate C suspended. Owning report: `Architecture_M6_CP3_TB12_Open_Rail_Chain_Provenance_Harvest_Report_20261018.md`.

**Classification (RA-87):** every prediction held, and U2 is closed. **Correction:** for #5/#6 the root is *not* U3–U5. Their first failure is B3: the face-0 side of the I endpoint at (1, 0.2) has barycentrics summing to exactly 1 + 2⁻⁵⁵, so `interior_carrier_parameter` rejects it. This is the RA-61.6 mechanism, which R9B deliberately left open. It is owned by the new unit U6 (DEFN first). **Falsifier:** at TB13, `cp3entry:2/6`'s first failure changes even though CB13 does not touch endpoint predicates.

---

## CANDIDATE / NON-STABLE — TB11: RP-01 fixture now first fails at an I–I front (2026-10-18, RA-85)

Immutable [TB11 run 39092477302](https://github.com/akashskypatel/Directional/actions/runs/39092477302), result artifact `12123605663` (ZIP SHA-256 `e98acd39a8a72f54118c6e6a66f7ec8346a6dd5d1043db06f1b12ad5298d9a65`), CB11 semantic source `9432aa05ef4719cbea912ae0feb2c5508c4e497a`. Exact 3/3 tests selected: **1 PASS, 2 RED**. Both RED tests abort at initial expected `Produced` fixture state, receiving `Rejected` from `open-rail-route-anchor` at locus 9 (rail 2, front 29/147, face 0→3, edge 1–4), **before** cleared-terminal mutation or retained control assertion. The truth-table unit test passed. **Classification (RA-85):** not a U1 regression. The fixture has never been `Produced` (RP-01 family, `no-exact-terminal-corner` since the R4 interior-witness TB of 2026-10-15). Front 29/147 is an I–I middle segment of rail 1–4–7. The consumer pushed it before CB11 and failed later at vertex 4; U1 now rejects it first. The "I–I rejected" rule (RA-84.1) is withdrawn; the open-chain interval route rule (RA-85.4) admits it. **Falsifier:** at TB13, front 29/147 still fails at the route layer.

---

## CURRENT CANDIDATE / NON-STABLE — RP-01: endpoint at an open-rail interior vertex has no admitting branch (TB10, reviewed RA-81 2026-10-17)

TB10 immutable run [38941839640](https://github.com/akashskypatel/Directional/actions/runs/38941839640), result `12062873272` ZIP SHA-256 `4db22a924f31a7bc6fdf1575a66849a2f660a760003e03e26e7f9277ac200513`; compiled source `d938ecb57e1040c2a73d5d25c4a613414556cb18`, artifact `12062565622`. 44/44 selected, 44 RED, 0 missing, 48 A3 observations, 21 exact-one-hot vertices: **contact-endpoint membership 0/21; carrier-edge membership 21/21; composite 0/21**. Example decoded vertex 4, published contact endpoints {1,7}, carrier edge {1,4}, certificate rail 2. Immutable postflight passed, 28/28 package hashes, compile/relink/benchmarks/selector497 not executed. Evidence is candidate/non-stable and does not modify 66/17/49, debt1, CP2 491/491, R3 403/497, selector497; RP-01 open, RP-02 UNREACHED. Independent Review next (ID UNKNOWN); no repair authorized.

The published-contact endpoint mismatch is newly isolated on 21 exact-vertex records; this is a diagnostic candidate, not a new stable regression event or ledger credit.

**Classification (RA-81):** owner — consumer endpoint contract (RA-79 V/I/C), not a producer. The other six records are the same phenomenon in the compacted numbering (vertex `2`, contact `{1,6}`, carrier `{1,2}`). Vertex `4` is the interior vertex of the open rail `1–4–7`; V admits rail terminals, I strictly interior edge points (`0 < t < 1`), C closed rails, so the case is uncovered. **Falsifier:** a source path that admits an interior-rail-vertex endpoint in either checker (`SurfaceCellTracing.cpp:19265-19544` or `:8528-8870`). **RA-83 (R10A reviewed):** confirmed in two verifier layers — per endpoint (`:8699-8721`) and route level (`:8597-8614`, an open-rail front needs a published terminal end); star incidence is seeded only for published terminals (`:8495-8519`). The consumer has no route-level requirement, so I–I fronts it certifies are rejected at publication (`:12858`). The ordered open-rail chain reaches the consumer (`SurfaceCellTracingOptions::authoritativeRails`) but not the verifier.

**RA-84 (R10B reviewed):** rule accepted with amendments. R is admitted only as a strictly interior vertex of the named open rail's ordered chain, carried to the factory next to the terminal pair (same trust root as T, RA-84.2). It needs exactly two hard spokes, unique disjoint per-side A3 paths, and must be the outer vertex of its end step. **RA-85:** the route rule is now an open-chain interval, which admits I–I middle fronts (RA-85.4). Units are realigned to U2–U5; next `M6-CP3-CB12-R10-OPEN-RAIL-CHAIN-PROVENANCE`. **RA-87:** RP-01 has three blocker shapes: B1 I–I anchor (U3), B2 R endpoint (U4/U5), and B3 inexact I parameter (U6, new; `cp3entry:2/6`, front 17/203). **RA-95:** all 19 B3 identities are one template (front 17/203, span 3, ordinal 1). Both sides share one exact `location_parameter`; `boundary_trace_point` rounds it differently per orientation, which gives the one-ULP pair. **RA-96:** U6A verified this trace. The fix is a canonical exact witness, bound bit for bit to the doubles, first measured with no admission change (CB15/TB15). No runtime pass is claimed; `RP-01` stays open until all three are cleared and reviewed.

---

