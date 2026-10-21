## TB19A — torus rejection-site harvest; candidate/non-stable (2026-10-20)

Artifact-only [run 39484475466](https://github.com/akashskypatel/Directional/actions/runs/39484475466), result artifact `12292268624` (ZIP SHA-256 `25d48ed757a54ba77b7876ff0d3b833673cd57dab151f1e9632fcfcb7a8efa7c`), semantic source `d2c7483cde8e65d6c35c5df06fa880465a4da46c`, immutable compiled artifact `12275794192` (28/28 checksum entries verified). All 7 selected; positive fixture-loaded control `selector:443` PASS, 6 RED at `PublishedProductRejected product=0 detail=none site=gauge-pin-consistency;edge=0,3`. G1–G4 HELD. Source hard-rail edge `{0,3}` belongs to the minor torus cycle 0–3–25–37–49–61–0, not the major cycle. This restores measurement of TB19's six fixture-staging-invalid cases without changing source, tests, selectors, fixtures, or compiled package. The observation does **not** prove an H-pin root cause or stable regression; mandatory TB19-REV must adjudicate hard-rail carriers versus periodic cuts and record the R-route as NOT REACHED. Stable counts unchanged: **66/17/49**, debt **1**, CP2 491/491, R3 403/497 rejected, TB18 candidate 448/497, selector497 frozen, RP-01 open, RP-02 UNREACHED. Full evidence: `Architecture_M6_CP3_TB19A_Torus_Rejection_Site_Harvest_Report_20261020.md`.

## TB18 — rail-vertex consumer census; candidate/non-stable (2026-10-20)

Runs [Part A 39349041417](https://github.com/akashskypatel/Directional/actions/runs/39349041417) and [Part B 39349459268](https://github.com/akashskypatel/Directional/actions/runs/39349459268), artifacts `12231529583` / `12232299548`, immutable source `3bd24682c`, packages 18/18 and 1019/1019. Part A 12/14 PASS: the two cross-region diagnostics now fail earlier in the producer with `PublishedProductRejected`, while the R-route forged-tag test PASSes. Part B 448/497 PASS vs TB16C 425/497, 23 RED→PASS and zero PASS→RED; all 30 former B2 identities exited B2 (16 PASS, 14 RED/other), leaving 49 RED/other. These are **non-stable candidate outcomes**: first-failure migrations are not proven production regressions, and their causal source is not established by the artifact; TB18-REV owns adjudication and fixture debt. Falsifier: independent review discovers a B1/B3/U6 or a PASS→RED, or validates a factory `InvalidSourceAuthority` on an R-certified route. No stable identifier, total or selector changed: **66/17/49**, debt **1**, CP2 491/491, R3 403/497 rejected; RP-01 still open, RP-02 UNREACHED. Inventory `Architecture_M6_CP3_TB18_Selector_497_Red_Inventory.tsv` SHA-256 `36cc9682cab7ceac02beca2a8ee25b2231bc3f33ffa768d03e1ade3dc142b9ca`; report `Architecture_M6_CP3_TB18_Rail_Vertex_Endpoint_Harvest_Report_20261020.md`.

**Independent TB18-REV (RA-104, 2026-10-20):** primary manifests/497 logs/49 RED/30 B2/Part A 14 re-derived; no new B1/B2/B3/U6 or PASS→RED. Full-history authority, boundary and ledgers PASS (run `39380260884`). Existing candidate is independently adjudicated **non-stable**, never promoted to CP3 acceptance; stable 66/17/49 and debt 1 unchanged. #10/#11 `PublishedProductRejected` occur in producer fixture before a certified-route checked-factory oracle, so root cause and universal R factory admissibility are **undetermined**, carried after bounded fixture-debt work. **First assigned correction:** selector242 is a test-authority defect (modified crossField but atlas from original field); owner CB19 test-only, falsifier: mutated atlas cannot be constructed or the typed negative oracle cannot be preserved; prohibited: production edits, removing rejection assertions, or inferring a stable fail-open. Plan `Architecture_M6_CP3_CB19_Selector242_Atlas_Authority_Test_Plan_20261020.md`.

**Review of TB18-REV (RA-105, 2026-10-20):** the measurements are confirmed. The candidate attributions below change no counts:

| Mechanism | Identities | Locus / origin | Status |
|---|---|---|---|
| M1: certificate binding shadows frozen precedence (`VALIDATION_ORDER_SHADOWING` candidate) | `focused30:3, 22, 23`; `selector:139, 140, 142, 211, 219, 227, 230` | S:8755–8775, `80fc1688f` (R2). The first `make` clause to read `edges`; code 0 replaces 7 at 211/219 | Static proof; ownership decided by a DEFN after TB19-REV |
| M2: the RA-45.3 gauge pin spans rail carriers and periodic cuts (H-pin) | `focused30:12` (proved); `cp3entry:1`, `focused30:6, 20, 24`, `selector:446, 447` (nonzero-holonomy torus) | S:8510–8550, `1eaea310f`; the torus first observable changed between R3 and CB13A | TB19 site labels confirm or refute it |
| Unlocated checked-factory rejection | `cp3entry:2, 6` (Part A #10/#11) | S:13097, clause not logged | TB19; decides the RA-103.5 R-route falsifier |

RA-106/RA-107 (2026-10-20): the site labels compiled in CB19A (`d2c7483cd`, package `12275794192`), which RA-107 accepted. RA-108 (TB19 run `39464430751`): `cp3entry:2/6` and `focused30:12` reject at `gauge-pin-consistency;edge=1,4`, so the `cp3entry:2/6` clause is the gauge pin. The six torus rows were not measured (fixture staging) and TB19A reruns them. RA-109 accepted the TB19 report (`Architecture_M6_CP3_TB19_Factory_Rejection_Site_Harvest_Report_20261020.md`). RA-110 (TB19-REV): TB19A accepted; all nine M2 identities stop at the pin, and H-pin is CONFIRMED as a producer/factory gauge-domain mismatch (`Architecture_M6_CP3_TB19_REV_Gauge_Pin_Domain_Review_Decision.md`). M2 is attributed to the checked factory's pin domain, not fixture debt. RA-111 (DEFN-P1-REV) freezes the corrected domain, same-region non-hard two-face edges with a span guard, for CB20 (`Architecture_M6_CP3_DEFN_P1_Gauge_Pin_Domain_Review_Decision.md`). RA-112 (CB20-REV): the CB20 source `7dc9b89ec` matches that domain statically; the compile failed only on a test accessor, corrected by CB20A (`Architecture_M6_CP3_CB20_Gauge_Pin_Domain_Compile_Stop_Review_Decision.md`). RA-113 (CB20A-REV) accepts the compiled package `12310848591` (source `e22c5da5f`) and authorizes TB20, whose rows separate the pin from the RA-103.5 R-route (`Architecture_M6_CP3_CB20A_Gauge_Pin_Domain_Review_Decision.md`). RA-114 (TB20-REV): the pin is no longer the first failure of any M2 identity and the R-route falsifier is not observed; `cp3entry:6` passes, six torus rows stop at the test-fixture odd-gauge filter (TQ:1697, added after CP2 in `88aa8eae0`), and `cp3entry:2` and `focused30:12` stop in the hard-rail certificate/A5 area. M1 is unchanged (`Architecture_M6_CP3_TB20_Gauge_Pin_Domain_Review_Decision.md`). M1 is unchanged. No stable count changes.

## TB17 — focused artifact-only gate, no new stable regression — adjudicated by RA-103 (2026-10-19)

[Run 39313027637](https://github.com/akashskypatel/Directional/actions/runs/39313027637), result `12215967774` (ZIP SHA-256 `b32366a1b4f102a2c09388bd5debb34bbbb6b6ff9d71931f8e0a06e700ea2ace`) on immutable CB17 package `12214741070`/source `ccc0b00ab6a94d0889ed7c60e4532b6c985ce03e`. 13/13 exact-filter processes: #1–#7 and #13 PASS; five previously RED diagnostic identities #8–#12 remain RED and each `first_failure` is byte-identical to TB16A. These are existing candidate/non-stable `endpoint-1` route-certificate failures: CB17 changes only the factory R rule while the consumer still does not emit R. No new regression identity or root cause is evidenced. Immutable postflight; no compile/relink/benchmarks or selector-497 census. **Stable accounting 66/17/49, debt 1, candidate census 425/497 unchanged.** `RP-01` open, `RP-02` UNREACHED. Owning report `Architecture_M6_CP3_TB17_Factory_Rail_Vertex_Endpoint_Harvest_Report_20261019.md`; independent TB17-REV next.

## TB16C selector-497 census — adjudicated by RA-102 (2026-10-19)

[Run 39295624822](https://github.com/akashskypatel/Directional/actions/runs/39295624822), result `12207970911`, ZIP SHA-256 `d10553f037a4ae92913db3c07b325636fe221335f79d955258d16b4671874fcb`; immutable CB16A package `12193816372`/source `7cfa5b46`. 497 exact processes, package manifest 28/28 and immutable postflight; 425 PASS / 72 RED, identical in disposition to TB14A, with no new PASS→RED/RED→PASS identities. Under RA-90.4 with RA-91.2, B1=0, B2=30, B3=0, U6=0, other=42. All 19 previously B3 identities now B2. Candidate/non-stable classification is retained because this is a mechanistic blocker migration, not a newly demonstrated production regression; no stable ID or count change. **66/17/49**, debt **1** unchanged. Owning evidence `Architecture_M6_CP3_TB16C_Selector_497_Red_Inventory.tsv` (SHA-256 `9ea7c62ec4bbc1c9d703f121429827f2d077c25f643d9a314b641186bebb4acf`) and `Architecture_M6_CP3_TB16C_Selector_497_Census_Report_20261019.md`; TB16C-REV mandatory before CB17.


**Adjudicated by RA-102:** independently re-verified (1019/1019; the 72 REDs reclassified from raw logs as B2 30 and other 42, agreeing 72/72). Outside the B3 set, no first failure changed in substance; 10 differ only by the P10:12 `#include <bit>` line shift. U6 is complete. All 30 B2 records are one I–R shape at rail vertex 4, which the R rule satisfies. CB17 (U4) is specified. No new regression.
---

## TB16A exact-I checker harvest — predictions confirmed; adjudicated by RA-101 (2026-10-19)

[Run 39277232731](https://github.com/akashskypatel/Directional/actions/runs/39277232731), result `12198063461` (ZIP SHA-256 `7f8769edbddc8439662526ca9520919ad78888b31a12abdd9548d476edd06cba`), source `7cfa5b46`, CB16A package `12193816372`. Full 12/12 immutable selection: **7 PASS / 5 expected diagnostic RED**, 0 missing, no rebuild or selector-497 run. Corrected independent oracle #3 goes RED → PASS; #8–#12 remain RED with `first_failure` byte-identical to TB16 artifact `12183498229`. No new stable production regression established, and no promotion of the B2 diagnostics to accepted production. Stable **66/17/49**, debt **1**, CP2 **491/491**, rejected R3 **403/497**, last full census TB14A **425/497**; RP-01 open, RP-02 UNREACHED, Gate C suspended. All RA-100.3 predictions hold. Conditional TB16C 497 census now authorized; do not ascribe an unmeasured outcome to its remaining B3 identities. Report: `Architecture_M6_CP3_TB16A_Exact_I_Witness_Checkers_Harvest_Report_20261019.md`.


**Adjudicated by RA-101:** independently re-verified (manifest 16/16; the harness diff is lines 7–9 and the labels only). The full #8–#12 predicate lines, not only the 600-character ledger field, are byte-identical to TB16. The U6 gates are closed. The TB16C deliverables are pinned (RA-101.4).
---

## TB16 exact-I checker harvest — adjudicated by RA-98 (2026-10-19)

[Run 39246335010](https://github.com/akashskypatel/Directional/actions/runs/39246335010), artifact `12183498229`, ZIP `8a329317a610a014cb834947d841fac788ffa55813519dc5259c342a3b62dc32`, CB16 `1c45e89a`: **12/12 selected; 6 PASS, 6 RED; immutable postflight**. Ordinal 3 is a **candidate test-oracle defect**: nextafter on reverse bary[2] yields the other legitimately reconstructed canonical rounding, so bound witness remains true. Ordinals 8–9 unchanged relative to TB15 #5/#6; ordinals 10–12 advance from front 17/203 to 97/283 but remain RED. RA-97.5 falsifier triggers independent Review; TB16C held. **Not a demonstrated new production regression**; stable **66/17/49**, debt 1, CP2 491/491, rejected R3 403/497, TB14A census 425/497 unchanged. Report: `Architecture_M6_CP3_TB16_Exact_I_Witness_Checkers_Harvest_Report_20261019.md`. **Adjudicated by RA-98:** independently re-verified.
- #3 is a Review spec defect: the mutation produced the other valid orientation image, so the checker is correct.
- #10–#12 are now B2 (front 97/283, vertex 4), so B3 is cleared on these identities.
- No regression.

---

## TB15 exact I-endpoint witness harvest — adjudicated by RA-97 (2026-10-18)

[Run 39170298228](https://github.com/akashskypatel/Directional/actions/runs/39170298228), result `12152685129` (ZIP SHA-256 `2536c38b958f76cfef6c5e0ef951e902e958d2cdb863e650e2b8b4002a50f748`), immutable CB15 semantic source `e4785d734e35d2f01ca3ee8099772f6ab5257f4c`, package `12150973440`. All nine exact tests selected and postflight-immutable: 4 PASS gates, 5 expected RED diagnostics. Two B2 tests retain no exact witness and binds 0; three B3 tests show matching bound `1,4@1/5` witnesses on both sides. Removing precisely the four new exact-witness fields makes all five first-failure records byte-equal to TB13A (#3–6) or TB14A (selector 217) baselines. **Classification:** existing `RP-01` B2/B3 causes, not newly introduced stable or candidate regressions; no early-admission behavioral change. **66/17/49**, debt **1**, CP2 **491/491**, rejected R3 **403/497**, latest full census **425/497** unchanged. Required independent TB15 Review before CB16. Owning report: `Architecture_M6_CP3_TB15_Exact_I_Witness_Harvest_Report_20261018.md`. **Adjudicated by RA-97:** independently re-verified; classification confirmed. The witness is exactly 1/5. RA-95.3's "p ≠ 1/5" is withdrawn. CB16 specified.

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

