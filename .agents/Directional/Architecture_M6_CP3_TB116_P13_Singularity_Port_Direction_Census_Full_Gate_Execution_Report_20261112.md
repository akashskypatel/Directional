# TB116 — Singularity-port direction census: immutable full-gate evidence (2026-11-12 UTC)

## Situation

The canonical turn `M6-CP3-TB116-P13-SINGULARITY-PORT-DIRECTION-CENSUS-FULL-GATE-EXEC` meets **RA-235 §5 MATCH**. No fix, selector change, rebuild, or separate Review was performed. The next turn is the Review-only `M6-CP3-DEFN-P13-SINGULARITY-PORT-OWNER`.

## Background

- Repository: `akashskypatel/Directional`, branch `agent/surface_cell_quad/p5-recover-bridge-healing`, draft PR #8.
- Semantic source: [`40f979d203b08cec236d047e4e9968b5d86d15d3`](https://github.com/akashskypatel/Directional/commit/40f979d203b08cec236d047e4e9968b5d86d15d3). CB135 compile-only package `13968642290`; ZIP SHA-256 `e952583fdcb74d30f25ba55c2613d288626b8c37e078100a7f7ee958f544e41e`; GMP and GMPXX link evidence, eight targets.
- Full gate: [run 43275319557](https://github.com/akashskypatel/Directional/actions/runs/43275319557), immutable result `13971032208`, ZIP SHA-256 `202baf96c715bc4d8533b9a58422044a8d61102b3e08ef17643bfb52965fadb4`.
- Three-case production census: [run 43275431208](https://github.com/akashskypatel/Directional/actions/runs/43275431208), immutable result `13970373806`, ZIP SHA-256 `7651095a2f8bda7d82e916bd5463e6a1e87e8b3d6f09d79ef907c6c5c0fa3819`.
- Full-gate manifest is byte-identical to TB115, SHA-256 `16a909bd6d3fe2b9ba37d263b89fb8ca16dcc3dd42214e4cabcae26c05c91020`. Self-check: `SELF_CHECK_PASS cases=945 deferred=81`.
- Independent comparison used verified TB115 artifacts `13960368135` and `13960224847`. The two TB116 ZIP archives passed CRC and SHA-256 checks.

## Assessment — independent checks

| Measure | Observed |
|---|---|
| Full gate | **945 planned, 945 executed, 945 passed, zero RED** |
| Membership | **1,026**, byte-identical to TB115 |
| Full-gate artifact member checks | **1,898/1,898** SHA-256 valid |
| Full-gate ledger | **945/945 substantive records** byte-identical after excluding raw-log hashes |
| Existing `switch-*` gate records | **44/44** verbatim, including all 12 TB115 production receipts |
| Census | **Cylinder PASS, BunnyRandom RED, Vase RED**, three expected outcomes |
| Census artifact member checks | **9/9** SHA-256 valid |
| Census existing `switch-*` records | **7/7** verbatim |
| Census existing atlas summary/incidence/adjacency records | **95/95** verbatim |
| New direction records in census | **216** across the census; **32** for singularity 6 |
| Singularity-6 positive wedge decisions | Exactly **(fan 0, branch 2), (fan 2, branch 0), (fan 4, branch 0), (fan 6, branch 0)** |
| Source mutation or runtime recompilation | **None** (`configure=false`, `compile=false`, `relink=false`, `benchmark=false`) |

The full-gate raw logs retain all 4,885 existing atlas partition records. Four additional printed summary lines came from interleaving of concurrent output streams in five cases. They do not change the accepted ledger, prior receipt text, or recorded atlas values. Other raw-log differences are elapsed-time and process-address text. The checks do not treat raw-log hash changes alone as semantic regressions.

The BunnyRandom case still fails at `InvalidFieldTransportAtlas/field-transport-atlas/SingularityPortClassCountMismatch`, source vertex **49**. The atlas reports **4 classes where 5 are required**. The candidate never reaches output completion. Vase still fails at `NotProductionReady/completion` with `AggregateCompletionValidationFailure`; it is a separate registered obligation. Cylinder remains green. Neither case establishes a new accepted-gate regression.

**Root-cause classification:** The new diagnostics establish the four exact face-wedge incidences and provide the direction weights around vertex 49. They do not, by themselves, decide whether A1 must support radial-edge ports or a transport-lift representative is incorrect. That decision belongs only to the next independent Review. The stable ledger remains **66 events / 17 categories / 49 recurrences**, debt **1**, deferred **81**. Accepted CP2 remains **491/491**. CP3/selector497 is not promoted; `chainRimSchedules=false` and D10 remains deferred.

## Verbatim BunnyRandom singularity-6 direction records

These 32 raw lines come from result artifact `13970373806`, `raw/2.log`. Every fan has branches 0–3. Exactly four have `inSector=1`, and they match all four prior incidence records.

```text
FieldTransportAtlas.partition direction singularity=6 fanIndex=0 branch=0 v25=-89.0316 v48=-192.804 next=48 inSector=0
FieldTransportAtlas.partition direction singularity=6 fanIndex=0 branch=1 v25=-16.9786 v48=119.813 next=48 inSector=0
FieldTransportAtlas.partition direction singularity=6 fanIndex=0 branch=2 v25=89.0316 v48=192.804 next=48 inSector=1
FieldTransportAtlas.partition direction singularity=6 fanIndex=0 branch=3 v25=16.9786 v48=-119.813 next=48 inSector=0
FieldTransportAtlas.partition direction singularity=6 fanIndex=1 branch=0 v48=-165.599 v109=24.6364 next=109 inSector=0
FieldTransportAtlas.partition direction singularity=6 fanIndex=1 branch=1 v48=-80.7372 v109=189.524 next=109 inSector=0
FieldTransportAtlas.partition direction singularity=6 fanIndex=1 branch=2 v48=165.599 v109=-24.6364 next=109 inSector=0
FieldTransportAtlas.partition direction singularity=6 fanIndex=1 branch=3 v48=80.7372 v109=-189.524 next=109 inSector=0
FieldTransportAtlas.partition direction singularity=6 fanIndex=2 branch=0 v108=22.9844 v109=78.4972 next=108 inSector=1
FieldTransportAtlas.partition direction singularity=6 fanIndex=2 branch=1 v108=-70.0919 v109=272.695 next=108 inSector=0
FieldTransportAtlas.partition direction singularity=6 fanIndex=2 branch=2 v108=-22.9844 v109=-78.4972 next=108 inSector=0
FieldTransportAtlas.partition direction singularity=6 fanIndex=2 branch=3 v108=70.0919 v109=-272.695 next=108 inSector=0
FieldTransportAtlas.partition direction singularity=6 fanIndex=3 branch=0 v108=-62.1653 v300=81.3333 next=300 inSector=0
FieldTransportAtlas.partition direction singularity=6 fanIndex=3 branch=1 v108=58.5838 v300=-20.6589 next=300 inSector=0
FieldTransportAtlas.partition direction singularity=6 fanIndex=3 branch=2 v108=62.1653 v300=-81.3333 next=300 inSector=0
FieldTransportAtlas.partition direction singularity=6 fanIndex=3 branch=3 v108=-58.5838 v300=20.6589 next=300 inSector=0
FieldTransportAtlas.partition direction singularity=6 fanIndex=4 branch=0 v300=2.57488 v306=81.2392 next=306 inSector=1
FieldTransportAtlas.partition direction singularity=6 fanIndex=4 branch=1 v300=52.0006 v306=-71.4561 next=306 inSector=0
FieldTransportAtlas.partition direction singularity=6 fanIndex=4 branch=2 v300=-2.57488 v306=-81.2392 next=306 inSector=0
FieldTransportAtlas.partition direction singularity=6 fanIndex=4 branch=3 v300=-52.0006 v306=71.4561 next=306 inSector=0
FieldTransportAtlas.partition direction singularity=6 fanIndex=5 branch=0 v306=-207.035 v349=298.718 next=349 inSector=0
FieldTransportAtlas.partition direction singularity=6 fanIndex=5 branch=1 v306=164.858 v349=-107.96 next=349 inSector=0
FieldTransportAtlas.partition direction singularity=6 fanIndex=5 branch=2 v306=207.035 v349=-298.718 next=349 inSector=0
FieldTransportAtlas.partition direction singularity=6 fanIndex=5 branch=3 v306=-164.858 v349=107.96 next=349 inSector=0
FieldTransportAtlas.partition direction singularity=6 fanIndex=6 branch=0 v302=105.456 v349=19.3389 next=302 inSector=1
FieldTransportAtlas.partition direction singularity=6 fanIndex=6 branch=1 v302=-88.9884 v349=116.65 next=302 inSector=0
FieldTransportAtlas.partition direction singularity=6 fanIndex=6 branch=2 v302=-105.456 v349=-19.3389 next=302 inSector=0
FieldTransportAtlas.partition direction singularity=6 fanIndex=6 branch=3 v302=88.9884 v349=-116.65 next=302 inSector=0
FieldTransportAtlas.partition direction singularity=6 fanIndex=7 branch=0 v25=-226.555 v302=392.913 next=25 inSector=0
FieldTransportAtlas.partition direction singularity=6 fanIndex=7 branch=1 v25=57.5598 v302=-222.183 next=25 inSector=0
FieldTransportAtlas.partition direction singularity=6 fanIndex=7 branch=2 v25=226.555 v302=-392.913 next=25 inSector=0
FieldTransportAtlas.partition direction singularity=6 fanIndex=7 branch=3 v25=-57.5598 v302=222.183 next=25 inSector=0
```

The existing summary in the same log is unchanged:

```text
FieldTransportAtlas.partition summary singularity=6 sourceVertex=49 topologyRegion=0 incidences=4 classes=4 expectedClasses=5
```

## Recommendation

The scoped checkpoint is **MATCH**. Start `M6-CP3-DEFN-P13-SINGULARITY-PORT-OWNER` only in a new, Review-only turn under RA-235 §6. Review the verified fan-face directions and signed lifts to choose the owning corrective stage. Do not change the field, sector predicate, transport lift, gate, selector, or production schedule inside TB116.
