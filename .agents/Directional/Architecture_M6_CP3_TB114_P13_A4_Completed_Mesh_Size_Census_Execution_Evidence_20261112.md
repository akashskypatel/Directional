# TB114 — immutable artifact-only full-gate result (2026-11-12 UTC)

## Situation
The fixed 945-case gate produced a scoped MATCH. The turn is not yet formally closed because its required tracker and handoff updates remain to be committed.

## Background
- Canonical turn: `M6-CP3-TB114-P13-A4-COMPLETED-MESH-SIZE-CENSUS-FULL-GATE-EXEC`.
- Semantic source and executor: `e60f2c76cc782767daf149d9a78af09474eb310e`.
- Immutable compile artifact `13947781593`: ZIP SHA-256 `e89169f233a6e8c9591acdaaaa76fc345900af19d056c6ee088e1bdfb8ca3aa5`, internal 28/28 verified.
- [Execution run 43231582288](https://github.com/akashskypatel/Directional/actions/runs/43231582288) SUCCESS; runtime job `131228180093`, result artifact `13950773589`, ZIP SHA-256 `ae08fb620b087ce7b05b177dd21d8b98f821f4817c3a217ece504bcf93073f3d`.
- TB113 comparison artifact `13944045361`, ZIP SHA-256 `c07047dab745cdb3b48eda699233982229ec5ce5b818f01fc82b96a7979c6223`.
- Frozen case manifest: 945 cases, SHA-256 `16a909bd6d3fe2b9ba37d263b89fb8ca16dcc3dd42214e4cabcae26c05c91020`.

## Assessment
- Cases planned/executed/passed: **945/945/945**; 1,026 memberships.
- RED, abnormal, missing, skipped, duplicate, invalid-control, unexpected-PASS and registered RED-site mismatches: all **0**.
- Postflight passed, exit code 0. No configure, compile, relink or benchmark.
- Result checksums: **1,898/1,898 passed**.
- All 945 ledger semantic rows agree with TB113; all **46/46 inherited diagnostic lines byte-identical**.
- New **4 switch-spans** lines and **8 switch-size** lines. The four parameterized cases each emit perArc/chained size observations. The separate SmoothRimDisc test does not call the size-printing function, so it emits no size line. All actual new lines were recorded, including required MultiFaceSeam chained.
- Exact key lines:

```text
switch-size case=MultiFaceSeam schedule=chained quads=100 boundary=40:1.02344/1.02344/1.053 interior=180:0.43405/0.667463/0.980494 interiorBelowHalf=36 target=0.0942809/0.0977093/0.282843
switch-spans case=MultiFaceSeam schedule=stopped spans=4 raised=0 lowered=0 moved=-
```

- Evidence favors an interior size-grading cause over parity-raised spans, but only the next Review may decide the remedy.
- No new stable regression observed. Preserve accepted CP2 491/491; stable 66 events/17 categories/49 recurrences, debt 1 and deferred 81. O41 remains open; CP3/selector497 unpromoted; `chainRimSchedules=false`.
- Procedural note: multi-file direct reads preceded the mandatory snapshot-mode decision. A complete exact snapshot was subsequently acquired and verified; this did not affect the immutable test run.

## Recommendation
Complete mandatory regression tracker and handoff/TODO/CHANGELOG closeout in the same TB114 turn, then publish COMPLETE with Review-only successor `M6-CP3-DEFN-P13-A4-INTERIOR-SIZE-GRADING`. Do not begin the successor in this turn.
