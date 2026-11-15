# TB117 — Edge-port straddle census: immutable full-gate evidence (2026-11-15 UTC)

## Situation

`M6-CP3-TB117-P13-EDGE-PORT-STRADDLE-CENSUS-FULL-GATE-EXEC` meets **RA-236 §5 MATCH**. The next separate Review-only turn is `M6-CP3-DEFN-P13-EDGE-SLIDING-SEPARATRIX-TRACE`. No source, test, selector, manifest, or production schedule change was made by TB117.

## Background

- Source: exact CB136 semantic commit `1d5c9514b8ec479d90e059107dd627656e37d15f`; compile-only package `14184697141`, ZIP SHA-256 `e0b781baffb3057eae1197d5539f7850221269042393def73ae17c06abe1bc7a`; eight GMP/GMPXX targets; compile `43772905298` with `runtimeExecution=false`.
- Gate: [run 43774649075](https://github.com/akashskypatel/Directional/actions/runs/43774649075), result artifact `14186446054`, ZIP SHA-256 `c5806278c67b9321bf26aceb5f557f94437a897e073db976ab2a4fc09b579574`, log artifact `14186291327`. Event SHA `b339904d21d1e50a896db8a64d378c0a204e7408`.
- Census: [run 43774679374](https://github.com/akashskypatel/Directional/actions/runs/43774679374), result artifact `14186002854`, ZIP SHA-256 `a31b7d9b495d1e2fbed1fada6c8a1ee0c585ed5e5a715a44b91def70e93aef33`, log artifact `14186516466`. Event SHA `1beac7a35b7e5966eb16db0467254472e89c9433`.
- Both completed with successful dispatcher mailbox publications. Immutable full-gate manifest SHA-256 `16a909bd6d3fe2b9ba37d263b89fb8ca16dcc3dd42214e4cabca26c05c91020`, byte-identical to TB116. Deferred 81, membership 1,026.
- Baseline TB116 artifacts: gate `13971032208` (ZIP SHA-256 `202baf96c715bc4d8533b9a58422044a8d61102b3e08ef17643bfb52965fadb4`), census `13970373806` (ZIP SHA-256 `7651095a2f8bda7d82e916bd5463e6a1e87e8b3d6f09d79ef907c6c5c0fa3819`).

## Assessment — independently checked

| Gate | Observation |
|---|---|
| Immutable source/package | Correct artifact `14184697141`, exact semantic source; both results report `compile=false`, `relink=false`, `configure=false`, `benchmark=false` |
| Full gate | **945/945 PASS**, zero RED/abnormal/missing/skipped/duplicates; membership **1,026**; postflight true |
| Production census | **3/3 executed**, Cylinder PASS, BunnyRandom RED, Vase RED, no unexpected change; postflight true |
| Internal SHA-256 checks | TB116 gate **1,898/1,898**, census **9/9**; TB117 gate **1,898/1,898**, census **9/9** |
| Ledger comparison | 945 gate and 3 census rows identical to TB116 after excluding the expected raw-log hashes |
| Prior receipts | Gate **13,325** and census **318** records retained verbatim as multisets per raw log; includes **216** census direction records |
| New edge-port records | Gate **462** lines across 945 logs; census **8** lines across 3 logs; **470/470 identity=1** |
| Nonzero straddle | Exactly one, in census `raw/2.log` at BunnyRandom vertex 49; every other edge-port record has `edgePorts=0` |

Exact nonzero record:

```text
FieldTransportAtlas.partition edgePorts singularity=6 sourceVertex=49 classes=4 edgePorts=1 expectedClasses=5 identity=1 straddles= (0,1,48-49)
```

The exact [per-log edge-port count table](Architecture_M6_CP3_TB117_P13_Edge_Port_Straddle_Per_Log_Counts_20261115.tsv) contains 948 rows, including zero-count logs. SHA-256 `c1b4181cbfa5f212457db56cffac308384b4329c6c67db596b0642dd5f0ebf83`. The independent read-only comparison script checked all four artifact checksum lists, all gate/census ledger rows, prior receipt multisets by log, exact nonzero line, every identity, and 216 census direction records. It returned `MATCH`. It did not execute project binaries.

**Regression classification:** BunnyRandom still rejects the known singularity-port count at vertex 49 (4 face classes versus 5 expected; one newly demonstrated radial edge port). Vase remains the separately registered production-completion RED. Neither is a new stable regression, recurrence, or accepted-green loss. The exact diagnostic supports the next Review's A1 edge-sliding port design; it does not implement that design. Stable counts remain **66 events / 17 categories / 49 recurrences**, debt **1**, deferred **81**; accepted CP2 **491/491**; CP3/selector497 unpromoted; `chainRimSchedules=false`.

## Recommendation

Close TB117 as **MATCH** and start only the separate Review turn `M6-CP3-DEFN-P13-EDGE-SLIDING-SEPARATRIX-TRACE` in a new response. Preserve all immutable artifacts, source and selector authority. Do not treat this diagnostic count as production activation.
