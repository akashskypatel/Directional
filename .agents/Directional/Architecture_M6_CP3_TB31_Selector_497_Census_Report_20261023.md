# TB31 — 497-case immutable census (2026-10-23)

**Turn:** `M6-CP3-TB31-RP01-SELECTOR-497-CENSUS`.
**Outcome:** 472/497 PASS, 25 RED, 0 INVALID. 10 RED→PASS, 0 PASS→RED relative to TB28. Candidate only; review successor remains mandatory.

## Source and execution authority

- Semantic package: CB29 source `2602e7398cdc6f1281abe11a758de35166b6590c`, artifact `12492950387`, ZIP SHA-256 `9e2da1f4b5cf95ac45364e8c428f0bd9116dcfe96772de18d02a5a7bfb167319`.
- Review-owned case manifest 497 identities SHA-256 `b1c135d429f8c659e190f648b8678669cb7c14d393e0db9069568ea3838aa43e` (472 GUARD, 25 RED). Harness SHA-256 `436f5fff9c3bec97457f4bc6b7c2b6182cb3f47707eb14a66af3b6a3f3dc3c9a`.
- Dispatcher source request SHA `3c8dfed8ca9d0e3f1898c8f0ac852af1f4c34816`; exact executor source `a2dafcc702f9de262d3315fad7645b0f400ec2d4`.
- Workflow run: [39959505758](https://github.com/akashskypatel/Directional/actions/runs/39959505758); evidence artifact: `12506242253`; outer ZIP SHA-256 `97828fac57a63b5d8ca85ef0e5fd35fb7d5ed71c2b2579cd463bacc20d5e947b`. All 1,000 packaged checksum entries independently verified, including 497/497 individual process logs; 497/497 manifest identity, binary, and predicted verdict matches independently checked against the Review-owned manifest.
- Boundary: `planned=497`, `executed=497`, `passed=472`, `red=25`, `missing=0`, `skipped=0`, `duplicate=0`, `control_bad=0`, `unexpected_pass=0`, `postflight=true`, `exit=0`. No configure/compile/relink/benchmark (`false/false/false/false`).
- The analysis used the downloaded immutable result, the TB28 full ledger committed in the repository, and the Review-owned TB31 manifest; no Directional runtime was executed locally. The unchanged frozen selector/manifest and independent source/package receipts are preserved.

## Exact per-row changes against TB28 (462 PASS / 35 RED)

| Identity | TB28 | TB31 |
|---|---|---|
| `focused30:3` | RED | PASS |
| `focused30:22` | RED | PASS |
| `focused30:23` | RED | PASS |
| `selector:139` | RED | PASS |
| `selector:140` | RED | PASS |
| `selector:142` | RED | PASS |
| `selector:211` | RED | PASS |
| `selector:219` | RED | PASS |
| `selector:227` | RED | PASS |
| `selector:230` | RED | PASS |

## Remaining REDs (25)

| Identity | Typed reason | First failure (abbreviated) |
|---|---|---|
| `focused30:12` | `A5:OccurrenceHardRailTransportMismatch` | ../../Directional/Directional/tests/SurfaceCellTransitionQuotientTests.cpp:5525: Failure |
| `selector:174` | `reason-not-observed` | unknown file: Failure |
| `selector:189` | `code=CycleTransportMismatch` | unknown file: Failure |
| `selector:190` | `code=CycleTransportMismatch` | unknown file: Failure |
| `selector:191` | `code=CycleTransportMismatch` | unknown file: Failure |
| `selector:192` | `code=CycleTransportMismatch` | unknown file: Failure |
| `selector:193` | `code=CycleTransportMismatch` | unknown file: Failure |
| `selector:194` | `code=CycleTransportMismatch` | unknown file: Failure |
| `selector:195` | `code=CycleTransportMismatch` | unknown file: Failure |
| `selector:201` | `reason-not-observed` | ../../Directional/Directional/tests/SurfaceCellREPackageTests.cpp:713: Failure |
| `selector:204` | `reason-not-observed` | ../../Directional/Directional/tests/SurfaceCellsPhase10Tests.cpp:1626: Failure |
| `selector:220` | `code=0;sourceAuthoritySite=face-gauge-missing;edge=-1;event=-1;cell=none;region=none;periodicRelation=none` | unknown file: Failure |
| `selector:221` | `code=0;sourceAuthoritySite=face-gauge-missing;edge=-1;event=-1;cell=none;region=none;periodicRelation=none` | unknown file: Failure |
| `selector:242` | `reason-not-observed` | ../../Directional/Directional/tests/SurfaceCellsPhase10Tests.cpp:3362: Failure |
| `selector:247` | `reason-not-observed` | ../../Directional/Directional/tests/SurfaceCellsPhase10Tests.cpp:4933: Failure |
| `selector:250` | `reason-not-observed` | ../../Directional/Directional/tests/SurfaceCellsPhase10Tests.cpp:3658: Failure |
| `selector:296` | `code=0;sourceAuthoritySite=face-gauge-missing;edge=-1;event=-1;cell=none;region=none;periodicRelation=none` | unknown file: Failure |
| `selector:302` | `code=0;sourceAuthoritySite=face-gauge-missing;edge=-1;event=-1;cell=none;region=none;periodicRelation=none` | unknown file: Failure |
| `selector:304` | `code=0;sourceAuthoritySite=face-gauge-missing;edge=-1;event=-1;cell=none;region=none;periodicRelation=none` | unknown file: Failure |
| `selector:405` | `reason-not-observed` | ../../Directional/Directional/tests/SurfaceCellsPhase10Tests.cpp:7040: Failure |
| `selector:439` | `code=0;sourceAuthoritySite=face-gauge-missing;edge=-1;event=-1;cell=none;region=none;periodicRelation=none` | unknown file: Failure |
| `selector:442` | `code=SingularityMismatch;sourceEdge=(2,3)` | ../../Directional/Directional/tests/FieldTransportAtlasTests.cpp:2856: Failure |
| `cp3entry:1` | `reason-not-observed` | ../../Directional/Directional/tests/SurfaceCellTransitionQuotientTests.cpp:2886: Failure |
| `cp3entry:2` | `reason-not-observed` | ../../Directional/Directional/tests/SurfaceCellTransitionQuotientTests.cpp:3109: Failure |
| `cp3entry:4` | `code=0;sourceAuthoritySite=open-rail-chain;edge=-1;event=-1;cell=none;region=none;periodicRelation=none` | ../../Directional/Directional/tests/SurfaceCellTransitionQuotientTests.cpp:3948: Failure |

Full first-failure lines, raw log digests, owners, baseline states: `Architecture_M6_CP3_TB31_Selector_497_Red_Inventory.tsv`. Every untyped reason is left explicitly untyped; no causal attribution is invented.

## Regression and acceptance disposition

No PASS→RED observed. Any remaining RED is not a newly established stable regression without an exact accepted-predecessor comparison; retain as candidate/non-stable pending independent TB31 Review. Stable ledger remains **66 events / 17 categories / 49 recurrences** with **one** produced-witness debt. M6 CP2 **491/491** remains the last accepted cumulative gate; M6 CP3 497-gate remains unaccepted, RP-01 open, RP-02 UNREACHED, Gate C suspended.

**Next mandatory turn:** `M6-CP3-TB31-RP01-SELECTOR-497-CENSUS-REV` to adjudicate the census and assign per-owner correction turns. No source, test, fixture, harness, selector or workflow mutation is permitted under this TB31 turn.
