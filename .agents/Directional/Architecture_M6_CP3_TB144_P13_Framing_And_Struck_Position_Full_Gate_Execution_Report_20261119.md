# TB144 framing and struck-position — Test + Benchmark execution

## Situation

**EXECUTION COMPLETE — 963/963 prior cases MATCH under frozen N1–N7; independent Review next.** The immutable CB168C full gate executed 961/961 cases: **960 PASS / one previously known RED** at row 858. The new row 961 passed. The full-gate workflow reports `failure` because the known row 858 causes `control_bad=1`; it is **not** a green required-control gate. The three-case census executed 3/3: Cylinder PASS and BunnyRandom/Vase expected RED. No CP3, selector497, or D0 promotion.

## Background

- Frozen source `e0f085eb65ed186bf836305f2896c69c6c90c519`; CB168C compile package artifact `14498438448`, ZIP SHA-256 `041ee85006926b674b3692a1315e9ba0695397a144ea0f00c406b4a6cfee081f`. Previously verified 28/28 internal package files. Both runs executed this package only.
- Gate [run 44462908179](https://github.com/akashskypatel/Directional/actions/runs/44462908179), result artifact `14501920082`, ZIP SHA-256 `a2cdbdf635d91b9fde4be5f5fa093d96d088714b24e5f22988518051824b7922` (**1,930/1,930** internal file hashes). Separate log artifact `14500384452`, ZIP SHA-256 `c4968185188986a8b9f09aaa434936e57fc9f35bb2286b468a0beb30ca820465`. Harness exit 90, `ValueError: required controls failed`, solely the one known RED. `planned=executed=961`; `passed=960`, `red=1`, `control_bad=1`, `missing=skipped=abnormal=duplicate=unexpected_pass=later_positive_red=red_site_bad=0`, `postflight=true`, membership 1,042.
- Census [run 44462935556](https://github.com/akashskypatel/Directional/actions/runs/44462935556), result artifact `14502085765`, ZIP SHA-256 `e7573335b7f222f6e6e383c2fa714697a14e70b5eaefac83bd89f1abdcf601c4` (**9/9** internal file hashes). Separate log artifact `14501213279`, ZIP SHA-256 `c024d17c278d6ae1a778954663dc5a039c31f00ab42c14942b2bb6959481ff81`. `planned=executed=3`, `passed=1`, `red=2`, `control_bad=0`, no missing/skipped/abnormal/duplicates, `postflight=true`, exit 0.
- Frozen gate manifest `gates/Architecture_M6_TB144_P13_Carrier_Contact_Struck_Position_Full_Gate_Case_Manifest.tsv` SHA-256 `fc1264e96628ad659302905f5537d8f4fc09973ffbfeaea3a4f228069613e949` (**961 gated + 81 deferred**). No compilation, relinking, configuration, benchmarking, source, test, fixture, selector or manifest edits in either artifact-only workflow; the `compile`, `relink`, `configure`, `benchmark` fields are all `false` in both result boundaries.
- TB143 comparison baselines: gate artifact `14490999571` ZIP SHA-256 `ffa03f7e359eeed8e76ad3f4f7a1624bed5f69d44c97a50b860939a8a044b11d`, census artifact `14492518198` ZIP SHA-256 `4089fc0de5bf38620f98e077b80a0b00706c17240869ff564ff36eb9b8b7cfa1`; both baseline ZIPs and internal file hashes were verified in the originating attempt. TB144 verification independently checked the 1,939 new indexed hashes.

## Assessment

| Independent check | Observed result |
|---|---|
| Prior ledger and normalized log identity | **960/960 gate + 3/3 census = 963/963 MATCH** under frozen N1–N7; no prior ledger field changed |
| N3 complete-record framing | Every existing `M3_CP4AB_FRAGMENT_DIAG record=region_support_projection` record preserved as a complete payload multiset; prefix count equals record count, non-record remainder byte-equal in order |
| CB168B framing falsifier | **Zero** lines with two M3 prefixes in any of the 961 gate + three census raw logs; the old TB143 gate rows 169 and 477 each had a joined two-prefix line; absence alone is weak race evidence |
| New injected helper guard | Row 961 `FieldAlignedCarrierOccupancy.CarrierContactCutsTheStruckTraceAtItsEntryCrossingOnly` PASS, selected one test, exit 0 |
| Accepted prefix | **491/491 PASS**, unchanged; no selector497 promotion |
| Known required-control failure | Row 858 `SurfaceCellTracingDisplay.StopLocationShowsWhatEachStageReported` remains RED at `tests/SurfaceCellTracingDisplayTests.cpp:155` |
| Raw slide receipts | Gate 1,200/1,200 of each `slideProposal` and `committedSlide` preserved byte-for-byte; census 66/66 of each preserved; total **1,266** each type |
| Entry-coincidence receipts | Gate 240/240 raw records as per-row multisets; census six/six; same identities and exact parameters; 19/19 prior sphere witness rows maintained |
| Producer census | Cylinder PASS with **288 quads**; BunnyRandom first binding failure remains trace 82; Vase RED unchanged |
| Negative controls | N3 comparator rejected record deletion, duplication and payload edit, plus non-record edit, in row169; prior ledger verdict mutation also detected |

The companion offline comparison checks each prior ledger and log SHA-256, all retained raw receipt lines, N3 record multiset/prefix/remainder, and each TB144 raw line for doubled M3 prefixes. The 963-case strict result is **not** evidence that the previously failing end-to-end fixtures are repaired. The CB168C helper is still unwired from production, and no slide publication or source-surface acceptance has been established. Stable regression accounting remains **66 events / 17 categories / 49 recurrences**, one produced-witness debt, 81 deferred. No new stable regression or candidate is justified: row858 and both census failures match the prior accepted comparison, and no prior normalized log changed.

## Recommendation

**Run independent Review only**, `M6-CP3-TB144-P13-FRAMING-AND-STRUCK-POSITION-FULL-GATE-REV`. Independently re-open primary evidence and re-derive N1–N7, the framing check, new row 961, accepted prefix, control failure, raw receipts, and unchanged BunnyRandom/Cylinder/Vase outcomes. Only that Review may freeze EC2b under RA-265 S3. Do not run EC2b, EC3, a new Code + Build, or any follow-on test in this execution turn. Preserve known open C5/O47/O48/O49/H4 obligations and no CP3/D0 promotion.
