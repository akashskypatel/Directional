# TB99 — A3 uniform chained-plan full-gate execution (2026-11-10 UTC)

**Canonical turn:** `M6-CP3-TB99-P13-A3-UNIFORM-DECLINES-CHAINED-PLAN-FULL-GATE-EXEC` (64C.4, artifact-only Test + Benchmark). **COMPLETE / MATCH** under RA-223's frozen gate. This is not the O36 D4/D5 production switch or CP3/selector497 promotion.

## Immutable authority and execution boundary

- CB118 compiled semantic source `6f0f9331a0dd3cf5a8d404134b0ad0669e5719c7`, package ID `13806737420` from [compile 42909557526](https://github.com/akashskypatel/Directional/actions/runs/42909557526), ZIP SHA-256 `b4c8552016497fd916344a48fa76aac8e6bcd6f9bfafd3aecb6d64f6dbf55aae`; 28/28 internal source/package checksums, eight GMP/GMPXX compile targets, `runtimeExecution=false`. No rebuild or package repair occurred in TB99.
- Frozen [936-row gate manifest](gates/Architecture_M6_TB99_P13_A3_Uniform_Declines_Chained_Plan_Full_Gate_Case_Manifest.tsv) SHA-256 `c137e3f81c75e94ed9596c59b3065e535bd678c05de178501b60923563249d2d`; membership 1,017 = 936 GATED + 81 DEFERRED (ledger v5 unchanged). Harness SHA-256 `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94`.
- [Full gate 42913554879](https://github.com/akashskypatel/Directional/actions/runs/42913554879), event `7875b0b2aad159fba2304608b5e34b348e8dc325`, artifact `13808977160` ZIP SHA-256 `b5e962f74b43397d6e9de3abfe39755e8f143196aa82a2dea57b42ac11446520`; **1,880/1,880** embedded SHA256SUMS entries individually verified. [Census 42913713088](https://github.com/akashskypatel/Directional/actions/runs/42913713088), event `985c0aa9b636c6c121f274deb4c30d6e8f6e4c4c`, artifact `13808653353` SHA-256 `99790ac7d3aac300c36504ef07f127957aa10a75b3f41a8e342886d1efd3c337`; **9/9** embedded checksums verified.
- Both execution-boundary documents pin exact CB118 source and artifact, report `configure=false`, `compile=false`, `relink=false`, `benchmark=false`, `postflight=true`, `exit=0`; the dispatcher compile and Drive jobs were skipped. All 939 expected test processes ran as fresh single-test processes; no missing, abnormal, skipped, duplicate, control error, unexpected pass, or invalid red-site result.

## Result and independent comparisons

- Full gate **936/936 PASS**: 926 GUARD + 10 POSITIVE, all inherited 931 TB97 ledger rows match on semantic/control columns; new rows 932–936 PASS, including RA-223 GUARD 936.
- Census **1 PASS / 2 registered RED**: Cylinder PASS; BunnyRandom RED at `InvalidFieldTransportAtlas/field-transport-atlas/SingularityPortClassCountMismatch`, source vertex 49; Vase RED at `NotProductionReady/completion/AggregateCompletionValidationFailure`, 189,462 trace segments, 26,817 arrangement cells and 67,750 completed quads (not accepted output). Both REDs remain previous production candidates; the census does not establish a new stable failure.
- Seven raw `platform-digest` and seven raw `a3-coverage` records from the four gate plus three census processes match the corresponding **TB97 raw lines byte for byte**, not merely by hash. The Cylinder case occurs once in each archive; both occurrences were checked separately against their original TB97 archive. All 931 inherited gate ledger rows also match TB97 on all semantic/control fields (process-specific log SHA and failure-context text excluded).

## D4 uniform receipts — verbatim from gate row 936

```text
D4_UNIFORM_RECEIPT plan=perArc disposition=Produced reason=None cells=128 discPhases=0 scheduled=16 covered=0 unrecorded=16
D4_UNIFORM_RECEIPT plan=chained disposition=Produced reason=None cells=8 discPhases=2 scheduled=8 covered=8 unrecorded=0
```

These receipts demonstrate a plan-dependent change in the focused two-square fixture: the per-arc path produced 128 cells but did not record A3 coverage; the chained path produced eight cells and records all eight scheduled intervals across two disc phases. A PASS in this test does not establish full production switch safety; O34/O35/O36/O37 and the disc-corner-stop decision remain prerequisites. The separately reported TB98 `d4-rim` side-count mismatches are not resolved by this receipt.

## Regression classification and boundary

**MATCH**, with no accepted-green loss or new stable event/category/recurrence. Accepted CP2 remains **491/491**; stable **66 events / 17 categories / 49 recurrences**, debt **1**, deferred **81**; selector497 and CP3 remain unpromoted. O36 remains unswitched. No source, tests, fixtures, selectors, or production path were changed in this TB turn. Next authorized **separate Review/Definition turn**, not entered here: `M6-CP3-DEFN-P13-A3-DISC-CORNER-STOPS` (64B.13; O38). Its owner must read RA-223's 135-degree corner defect, the TB98 `d4-rim` observations and these two receipts before freezing corner-stop semantics. The D6 decision remains pending.
