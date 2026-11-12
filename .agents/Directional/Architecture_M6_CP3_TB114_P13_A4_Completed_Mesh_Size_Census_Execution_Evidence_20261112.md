# TB114 — immutable artifact-only full-gate result (2026-11-12 UTC)

## Situation
The fixed 945-case gate produced a scoped MATCH. The required tracking and handoff records were committed together as `df32f475d916e660103247d44d109392587add6b`.

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

## Complete new diagnostic records

All twelve new diagnostic lines are reproduced exactly from the immutable result artifact. The source test emits eight size records and four span records. The separate SmoothRimDisc observation has no size helper call.

```text
switch-size case=Plane schedule=perArc quads=64 boundary=32:1.27345/1.28181/1.31231 interior=112:0.651854/0.881709/1.18862 interiorBelowHalf=0 target=0.0942809/0.0981658/0.195455
switch-size case=Plane schedule=chained quads=100 boundary=40:0.979874/1.02834/1.07237 interior=180:0.534213/0.731875/0.984895 interiorBelowHalf=0 target=0.0942809/0.0981658/0.195455
switch-spans case=Plane schedule=stopped spans=4 raised=0 lowered=0 moved=-
switch-size case=MultiFaceSeam schedule=perArc quads=64 boundary=32:1.27931/1.27931/1.31388 interior=112:0.531781/0.794908/1.10919 interiorBelowHalf=4 target=0.0942809/0.0977093/0.282843
switch-size case=MultiFaceSeam schedule=chained quads=100 boundary=40:1.02344/1.02344/1.053 interior=180:0.43405/0.667463/0.980494 interiorBelowHalf=36 target=0.0942809/0.0977093/0.282843
switch-spans case=MultiFaceSeam schedule=stopped spans=4 raised=0 lowered=0 moved=-
switch-size case=CloseSheets schedule=perArc quads=200 boundary=80:1.07338/1.15459/1.2063 interior=360:0.673198/0.840811/1.08666 interiorBelowHalf=0 target=0.0849567/0.088046/0.161418
switch-size case=CloseSheets schedule=chained quads=242 boundary=88:0.975393/1.05639/1.09589 interior=440:0.596778/0.778509/1.00219 interiorBelowHalf=0 target=0.0849567/0.088046/0.161418
switch-spans case=CloseSheets schedule=stopped spans=8 raised=0 lowered=0 moved=-
switch-size case=Cylinder schedule=perArc quads=288 boundary=64:0.987618/1.04718/1.05596 interior=544:0.641445/0.983419/1.17049 interiorBelowHalf=0 target=0.184752/0.204594/0.383932
switch-size case=Cylinder schedule=chained quads=288 boundary=64:0.987618/1.04718/1.05596 interior=544:0.641445/0.983419/1.17049 interiorBelowHalf=0 target=0.184752/0.204594/0.383932
switch-spans case=Cylinder schedule=stopped spans=79 raised=0 lowered=0 moved=-
```

## Documentation and transport checks

- The exact source snapshot contained 5,519 files. All source hashes passed.
- The documentation patch changed only the handoff, regression tracker, `TODO.md`, and `CHANGELOG.md`. The patch applied as commit `df32f475d916e660103247d44d109392587add6b`. The patch SHA-256 is `7d1ce66020cb69ca3ce4fb925ff2ac5d8ddc14e44d7643b6c1bd68bd917140ac`.
- The temporary Google Drive transport file required owner-side retirement. The Google Drive permanent-delete action returned `success=true`. The verified patch remains in the Directional ChatGPT Library.
- The document drift audit found two existing `DOCUMENT_BLOAT` errors. They concern the size of `Future_Chat_Session_Handoff.md` and `ORIENTATION.md`. The same two errors occur in the frozen baseline. No new audit finding came from this closeout patch. The audit is **not clean**. These older document-size issues require their own authorized cleanup and do not establish a test regression.
- The preceding session reported a read-mode ordering error. It acquired and verified the complete snapshot afterward. The error did not change the artifact-only test evidence.

## Recommendation
The regression tracker, handoff, TODO, and changelog were committed. Publish the final COMPLETE beacon with Review-only successor `M6-CP3-DEFN-P13-A4-INTERIOR-SIZE-GRADING`. Do not begin the successor in this turn.
