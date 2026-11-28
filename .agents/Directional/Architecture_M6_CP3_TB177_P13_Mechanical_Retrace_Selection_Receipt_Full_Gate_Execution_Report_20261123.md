# TB-EXEC-177 — mechanical retrace-selection receipt immutable full gate (2026-11-23 UTC)

## Situation

**COMPLETE as an execution turn; GATE REJECTED AND COMPARISON STOP.** All 1,001 cases executed, **994 PASS / 7 RED** at rows `445/652/653/656/658/660/786`. The strictly frozen TB-REV-176 H4 comparison is **not satisfied**: in addition to the two authorized receipt insertions, five failure-site line numbers shifted and one independent diagnostic record changed order. Stop the comparison gate and refer all deviations to the separate independent `M6-CP3-TB-REV-177`. Do not start CB-199 or reinterpret this as an accepted product gate.

## Background — immutable source, workflow, and evidence

- Exact CB-198 semantic source `6cdd23a10ac6f6fbc6c741fb1e18ccff2038871c`; compile-only GMP/GMPXX [run 45280023495](https://github.com/akashskypatel/Directional/actions/runs/45280023495), package `14868834752` SHA-256 `b5a7104d41e103e3d31094b4d889af1097ffa52edac6ff11fe120acfdb4ee0c9`, internal 28/28 checks, `runtimeExecution=false`.
- Executor `a523df11e8a7b19b070aa0463df0df564d03994b`, harness `.agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh` SHA-256 `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94`.
- Exact unchanged gate manifest `gates/Architecture_M6_TB176_P13_Piece_Builder_And_Ordered_Retrace_Full_Gate_Case_Manifest.tsv` SHA-256 `0f85400ff9713fc8a835f308304ded1db9830e668211bab71c88d580b2e84642`; 1,001 gated +81 deferred =1,082 members. `membership.tsv` is byte-identical between TB176 and TB177.
- Dispatcher request `m6-cp3-tb177-exec-20261123-a` at commit `445cd113be30b0aecc7da9fc0b197ef577f7bca8`; workflow [run 45283342400](https://github.com/akashskypatel/Directional/actions/runs/45283342400), result artifact `14871900641`, ZIP SHA-256 `8c5bce907f59b77207833153912805cccca6fa122c70ff9f299a64f68102b068`, **2010/2010** internal SHA256SUMS checks. Immutable TB176 baseline `14861444963`, ZIP `202cb81282d9e8a0bb6b711020af80450e407feb12b71de613b1be8cca110453`, 2010/2010 checks. Mailbox source and event match the dispatcher request.
- Runtime boundary: all 1,001 launched; none missing, skipped, duplicated or abnormal; `postflight=true`. `configure=false`, `compile=false`, `relink=false`, `benchmark=false`; harness exit 90 (`ValueError: required controls failed`). The test workflow did not build or change source, fixtures, selectors, manifest, or package.

## Assessment — exact comparison, including required STOP

| Comparison | Evidence | Disposition |
|---|---|---|
| Case identity and verdict | 1,001/1,001 cases; same 994 PASS and seven RED; same member ledger | Preserved |
| Raw transcripts | 650 byte-identical; 343 N1/N2-only elapsed-time/line-ending differences; eight have other differences | Classification required |
| Authorized new diagnostic | Two insertions only, at rows **652 and 656**, directly after `alongEdgeVisitsTruncated=false` | Receipt present |
| Failure-site drift | Rows **445, 653, 658, 660, 786**, each `FieldAlignedCurveNetworkTests.cpp` assertion location shifts **+108 lines**; `first_failure` ledger fields shift too | **H4 strict difference; STOP**. Test-only CB-198 inserted 108 lines, but no automatic normalization is authorized here |
| Row 172 | Six `region_support_projection` records retain an exact multiset but appear in different order; no other diagnostic data changed apart from elapsed time | **H4 strict difference; STOP**. N3-equivalent reordering is supported by record multiset; independent Review must decide admissibility under the frozen rules |
| Receipt prediction | Four retraces, four reversed-end shared-edge pairs, five shared edges per pair, both arrival-singularity equalities true; no unavailable path | Narrow diagnostic prediction supported; not product selection evidence |
| Singularity labels | Receipt uses IDs `1/3/5/7`. Same row maps them to source vertices `10/35/47/71` through `FieldTransportAtlas.partition edgePorts` | Predicted vertex values match source-vertex IDs, not the literal receipt's singularity-ID field; Review must keep the namespaces distinct |

The strict H4 rule permits only one text insertion after `alongEdgeVisitsTruncated` in eligible rows and requires stopping on any other difference. **No N3 exception or source-line offset normalization is introduced in this TB turn.** These differences do not establish new accepted-green loss, but they prevent claiming strict transcript equivalence or acceptance. The TB177 result is rejected even though the tally matches TB176.

**Row 652 receipt (verbatim, one continuous exception-text segment):**

```text
;retracedTraceSelection=available;retracedTraceCount=4;retracedTrace[0]={kept=0,keptPort=0,keptSingularity=1,keptArrival=3,removed=3,removedPort=3,removedSingularity=3,removedArrival=1,sharedEdges=10-1111-1717-2323-2929-35};retracedTrace[1]={kept=2,keptPort=2,keptSingularity=1,keptArrival=5,removed=8,removedPort=8,removedSingularity=5,removedArrival=1,sharedEdges=10-7947-7373-7575-7777-79};retracedTrace[2]={kept=7,keptPort=7,keptSingularity=5,keptArrival=7,removed=9,removedPort=9,removedSingularity=7,removedArrival=5,sharedEdges=46-4746-5353-5959-6565-71};retracedTrace[3]={kept=4,keptPort=4,keptSingularity=3,keptArrival=7,removed=11,removedPort=11,removedSingularity=7,removedArrival=3,sharedEdges=35-9571-9292-9393-9494-95};sharedEdgeTracePair[0]={traces=0/3,sharedEdges=5,retrace=true,ends=reversed,facePieces=0/0,pieces=5/5};sharedEdgeTracePair[1]={traces=2/8,sharedEdges=5,retrace=true,ends=reversed,facePieces=0/0,pieces=5/5};sharedEdgeTracePair[2]={traces=4/11,sharedEdges=5,retrace=true,ends=reversed,facePieces=0/0,pieces=5/5};sharedEdgeTracePair[3]={traces=7/9,sharedEdges=5,retrace=true,ends=reversed,facePieces=0/0,pieces=5/5};sharedEdgeTracePairCount=4;sharedEdgeTracePairsTruncated=false
```

Row 656 has the same receipt bytes. Exact arrival premises on all four pairs: `keptArrival = removedSingularity` and `removedArrival = keptSingularity`; these are observed values, not a proof that the future production remap is correct. The prior `RegionElectedCutComponentEmpty` failure persists. The four co-traced zero-area lens orbits 1/3/4/5 are not repaired.

**Regression assessment:** seven RED cases remain the previously documented accepted-green mechanical recurrence, not newly stable events. The extra H4 differences are comparison/diagnostic candidates for independent adjudication, not independently proven product regressions. Historical stable counts stay **67 events /17 categories /50 recurrences**, witness debt **1**, deferred **81**; accepted TB169 993/993 and CP2 491/491 remain unchanged. No CP3/497/D0/H4 or production success promotion.

## Recommendation

The exact next, **separate** turn is `M6-CP3-TB-REV-177`. Reopen both immutable archives; independently verify H4 strict deviation at rows 172/445/653/658/660/786, distinguish N3-compatible reordering from admissible H4 behavior, inspect the recorded source-vertex mapping and arrival predicates, and reject or authorize the subsequent CB-199A producer path only after review. STOP all code/fixture/selector/manifest changes in this execution turn.
