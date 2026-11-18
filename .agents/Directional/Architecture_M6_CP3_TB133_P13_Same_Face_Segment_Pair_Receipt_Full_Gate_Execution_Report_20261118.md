# TB133 — same-face segment-pair receipt full gate (2026-11-18 UTC)

## Situation

Execution verdict: **MATCH** under [RA-254 S4](Architecture_M6_CP3_TB132_P13_Cut_Binding_Conflict_Receipt_Full_Gate_Independent_Review_20261117.md#ra-254--adversarial-re-review-of-this-review-2026-11-17-utc). All 956 substantive ledger records and normalized raw logs match TB132. Gate 952/953 PASS; row 858 is the same permitted RED. Census: Cylinder PASS (288 quads), BunnyRandom/Vase RED. The new diagnostic field is present at both specified rejection sites. This is diagnostic-only evidence, not CP3, selector497, D0 or geometry acceptance.

## Background — immutable authority

- Turn `M6-CP3-TB133-P13-SAME-FACE-SEGMENT-PAIR-RECEIPT-FULL-GATE-EXEC` on `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 draft and unmerged. [CB156 compile record](Architecture_M6_CP3_CB156_P13_Same_Face_Segment_Pair_Receipt_Code_Build_Record_20261117.md) owns package `14369087138`, source/executor `779fe661e260f506592c64791fbe655734029478`, ZIP SHA-256 `9bec7da392d32c0dafedb77bc08426a2aeaa795c7905e6e5facde7ad8c14d032`, root manifest `84c4040b473a636dc28014269601e04c3567b7f24e40684811868f888baecf68` and source archive `3ec79e509fa77a640c0889934aa9ce9b1c406d0882f121884ae4020ee038392f`. The immutable harness verifies all three hashes, source metadata, GMP dependency, archived executable modes, and pre/postflight package/view integrity. Both executions used exact package bytes without repair.
- Source snapshot `f0476b8151f963e84dc19d962a86c42a4edb94a8`, run [44178492260](https://github.com/akashskypatel/Directional/actions/runs/44178492260), artifact `14371780161`, ZIP `436344869e094263db01350a0027a59b02606f078e4dc5e5d2302bb6bfa72bbf`, source archive `877baef8b311b32a51c4a536674fb541376f7f9028e6c0acfe46fa104121670c`; 5,540/5,540 checksums. GitHub comparison to census dispatch `47ecc88682a359323fc66e791cc7fb187decbcbd` shows only STATUS and the request slot changed. Exact reviewed +65/-0 diff SHA-256 `1246f12b3cc22f62aa70ea503cf14e1f8438b160995e85225ba26c8fb7bfc205`.
- Four frozen inputs match: gate `941287fa96f3432eb1d67a9ae1e5dc7bc0ca2f3a1775cd5f9fb35482a4fa7962`; census `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793`; deferred `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce`; harness `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94`. Comparator TB132 gate `14359654903` ZIP `b2a9997c5f41ba760a75003d3edc7682cbd20dbd852f7df49bd8a90de6c2611e`, census `14362615302` ZIP `a44f41eb558fd9205d9725d85d9f83b8d754beef1b24a3d886b847f6e1d639a2`; recovered from retained evidence and verified by digest.

| Execution | Dispatcher event / request SHA-256 | Run / runtime job | Mailbox key |
|---|---|---|---|
| Gate | `cf9fdd1fccb8f5302c70c07214ef42bd87df3fbf` / `296c51d3d8345e83d5b5e343ddd177c0c306e98a10a0f41e56de066715e291b3` | [44200479694](https://github.com/akashskypatel/Directional/actions/runs/44200479694) / `134453211292` | `m6-cp3-tb133-gate-v1` |
| Census | `47ecc88682a359323fc66e791cc7fb187decbcbd` / `b8f12caba47273a26e33adf8fab5441c63363838aa2298b70bc86cb545ce75fd` | [44203730406](https://github.com/akashskypatel/Directional/actions/runs/44203730406) / `134464396289` | `m6-cp3-tb133-census-v1` |

Both mailbox records match the event/source/request identities. Schema validation, parse and mailbox jobs succeed. Gate runtime completes with organic exit 90 (required control RED at row 858); census exit 0. No configure, compile, relink, benchmark, fixture or source mutation. No project binary executes locally.

| Archive | Artifact ID | ZIP SHA-256 |
|---|---:|---|
| Gate result | 14381507340 | `d0647213767e3dc7152ebc1e5c31ac0221ad6ea66d4389fe4a8cab68630863f2` |
| Gate log | 14381207987 | `383b6ce6058e429a9714791867d3f9002f7076354dccab3894a69d2100d92eb9` |
| Gate reusable log | 14381292640 | `b2cb9e8dd08a8a4840ffde99083267ea7ca259cc46248bf4e896416b1b734daf` |
| Census result | 14383400603 | `0d0accf8103db8b5b5b584646935e7c7d4fdd0f0dc08583f32b2947a7af214a5` |
| Census log | 14382162789 | `efc1ecb534dc43407d620393ab70dfa6a5321bc06ef7c83f7d93b887368b49fc` |
| Census reusable log | 14382372596 | `ec4f58f3c7ba92d7cbab756e927b8fd9ce33c432353038137c92cb1638353b9f` |

## Assessment — frozen comparison

| Criterion | Evidence |
|---|---|
| 1. Substantive ledger equivalence | MATCH 956/956; 953 gate and three census identities. Gate membership 1,034 (953 + 81 deferred), byte-identical. |
| 2. Raw log equivalence (N1–N4 + N5′) | MATCH 956/956. N5′ removes only the `sameFacePairs=` field and preserves the existing receipt bytes. Complete M3 records compare as multisets. Ordered non-record remainder is equal. |
| 3. Receipt scope | Same 66 lines across 19 sphere rows and two lines on BunnyRandom. Each line carries the new field once. |
| 4. No other difference | Zero ledger, normalized log, or receipt count mismatches. |

All 3,846 internal artifact checks and 1,912 raw-log-to-identity bindings passed. Both postflight checks passed. Gate: 953 executed, 952 PASS, one RED, control_bad=1; census: 3 executed, one PASS, two RED, control_bad=0. Both have zero abnormal, missing, skipped, duplicate, unexpected_pass, later_positive_red and red_site_bad cases. Accepted prefix 491/491 PASS. The offline comparator rejects 10/10 mutations, including removed/duplicated/changed M3 records, non-record/ledger mutations, removed receipt field, removed/duplicated receipt, altered retained receipt field, and duplicate new field. Six positive controls pass, including field values `none` and `unevaluated`. No broadening of the frozen normalization.

### Raw receipt data for TB133-REV

Sphere: rows 380,388,393,394,396,397,644,645,648,669,686,691,694,698,699,700,843,844,858. All 66 lines are byte-identical within TB133:

```text
EmbeddedGraphTopology.duplicateCutCrossing edge=(0,2) t=0.12749386848657163 cutEdges=288 trace=[4 segments=8 crossing=7  struckTrace=1 struckSegment=0 contactFace=(0,2,3) at=0.89373888688647607 0.016127667144259561 0.090133445969264342 ] trace=[6 segments=8 crossing=7  struckTrace=0 struckSegment=0 contactFace=(0,1,2) at=0.89373888688647618 0.090133445969264175 0.016127667144259533 ] sameFacePairs=4/6:6-7@(0,1,2)b=2-3 o=0:1:1:0 eq=xe,7-6@(0,2,3)b=1-2 o=-1:0:0:-1 eq=ex sharedEvents=none
```

BunnyRandom census row 2: both lines are byte-identical:

```text
EmbeddedGraphTopology.contactCutConflict trace=82 position=0:0.2305473011248014 existing=[node=220 contact face=(21,72,273) point=0.032006329006921713 0.19854097211787966 0.76945269887519852 terminating=43 struckTrace=82 struckSegment=0 contactFace=(21,72,273) at=0.032006329006921713 0.19854097211787966 0.76945269887519852  interior=82:0:0.2305473011248014  events=FirstContact@none,TraceIntersection@none] claimant=[node=222 contact face=(21,72,273) point=0.032006329006921713 0.19854097211787966 0.76945269887519852 terminating=15 struckTrace=82 struckSegment=0 contactFace=(21,72,273) at=0.032006329006921713 0.19854097211787966 0.76945269887519852  interior=82:0:0.2305473011248014  events=FirstContact@none,TraceIntersection@none] sameFacePairs=43/15:0-3@(103,282,283)b=0-0 o=-1:-1:1:1 eq=-,1-4@(282,283,348)b=0-0 o=1:1:-1:-1 eq=-,3-8@(13,348,350)b=3-3 o=1:1:-1:-1 eq=-,4-9@(1,13,350)b=1-1 o=1:1:-1:-1 eq=-,5-10@(1,2,13)b=1-1 o=1:1:-1:-1 eq=-,6-11@(0,1,2)b=2-2 o=-1:-1:1:1 eq=-,7-12@(0,2,18)b=1-1 o=-1:-1:1:1 eq=-,8-13@(0,18,60)b=0-0 o=-1:-1:1:1 eq=-,12-18@(124,210,290)b=1-1 o=1:1:-1:-1 eq=-,13-19@(94,124,210)b=2-2 o=unevaluated,14-20@(72,94,243)b=1-1 o=0:0:0:0 eq=ee+xx,15-21@(72,243,273)b=1-1 o=0:0:0:0 eq=ee+xx,16-22@(21,72,273)b=2-2 o=0:0:0:0 eq=ee+xx
```

`o=` gives the four exact orientation signs; `eq=` names equal canonical segment ends. See RA-254 S3 for the emitter contract and its limits. TB133-REV independently decides overlap versus transverse meeting and freezes the applicable definition. Do not classify by the existence of a coincident point alone. No coordinate welding, guard weakening, deletion of protected roles or guessed cut is authorized here.

### Regression disposition

No newly introduced semantic regression relative to TB132. Existing sphere C5 cut-binding rejection and BunnyRandom FC-1/FC-4 contact conflict remain; RA-254 attributes the missing contact event to the same-face producer's classifier exclusion of EndpointTouch and CollinearOverlap. New fields measure the candidates but do not select a repair within this execution turn. Existing row 858 premise failure at `SurfaceCellTracingDisplayTests.cpp:155` and unreached row 648 sphere assertions remain; Vase completion RED unchanged. O45 stays narrowly closed; O47 remains open. C5/O42/O43/O46, H2 and middle-piece direction witness remain open, FC-6 and terminal-cut outcome held. Stable 66/17/49, debt 1, deferred 81, CP2 491/491. D11=A, D12=A, D10 deferred, D6 pending; `chainRimSchedules=false`. No CP3/D0 promotion.

## Recommendation — separate independent Review

After root STATUS completes `M6-CP3-TB133-P13-SAME-FACE-SEGMENT-PAIR-RECEIPT-FULL-GATE-EXEC`, perform `M6-CP3-TB133-P13-SAME-FACE-SEGMENT-PAIR-RECEIPT-FULL-GATE-REV` per RA-254 S4–S5. Re-open both raw archives independently, classify each site from the observed exact signs and canonical equal ends, and freeze at most one DEFN per site. Do not execute successor work in TB133. Evidence includes both result archives, logs, TB132 comparator archives, comparator source and JSON in the File Library archive `Directional_TB133_verified_evidence.zip`.
