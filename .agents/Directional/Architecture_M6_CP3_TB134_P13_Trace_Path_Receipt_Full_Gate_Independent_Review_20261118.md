# TB134 independent review — trace-path receipts (2026-11-18 UTC)

## Situation

`M6-CP3-TB134-P13-TRACE-PATH-RECEIPT-FULL-GATE-REV`: **MATCH upheld** under RA-255 S5. No geometry acceptance or promotion. BunnyRandom first equal face entry is vertex 94; both traces arrive by a same-direction edge slide on (94,210), so the shared carrier interval starts before that vertex. Trace 43 arrives before trace 15 by filtered arc length (bounded reconstruction, not trace ID or segment count).

## Background — immutable authority

- [TB134 execution](Architecture_M6_CP3_TB134_P13_Trace_Path_Receipt_Full_Gate_Execution_Report_20261118.md): CB157 source `a8d1cc9603f9a556564f0b741692217ec6a791ef`, package `14389450751`; CB156 comparator source `779fe661e260f506592c64791fbe655734029478`, package `14369087138`. Package SHA-256 evidence is inherited from the compile records; packages were not executed or downloaded in Review. Candidate mailbox run 44220116762 (gate failure, permitted row 858), 44220173755 (census success); both exact result digests match mailbox. Snapshot run 44225216915, artifact 14393220101, source `d2b8ec36eeceddf92ad51bb490e93c90cdffc1ff`, ZIP `01c4256dfc3add4bfbf0f2fe78f19bcf452605cea4099334131d2af696403ba2`, 5,544/5,544 internal file checks. Connector comparison proves CB157 is ancestor of snapshot, with no code/fixture/build drift; CB156 to CB157 only semantic delta +50/-0 `EmbeddedGraphTopology.cpp`; frozen diff SHA `56ef75c91cf72be85752af61cb276c73aeaf1ca692f92aa5061326fac9eb5f18`, snapshot blob `045498473ab258fafce17df98fcc1498a2f20cc5`.

| Archive | Artifact | Recomputed ZIP SHA-256 |
|---|---:|---|
| TB133 gate | 14381507340 | `d0647213767e3dc7152ebc1e5c31ac0221ad6ea66d4389fe4a8cab68630863f2` |
| TB133 census | 14383400603 | `0d0accf8103db8b5b5b584646935e7c7d4fdd0f0dc08583f32b2947a7af214a5` |
| TB134 gate | 14390702505 | `532ae16d7872c5699a85c0bc11d819856660fb22b1fcaae99f454db714bf0640` |
| TB134 census | 14391390784 | `dcf867473ebc5bd0310ff5249644d4c4cd4a8cf6214cdca9942f2b0ec52fe149` |

## Assessment — independent evidence

Independent read-only parser compared all 956 substantive ledgers, 1,912 raw log SHA-256 bindings, one actual RUN per row, manifest row identity and exact raw-log inventory. Four archives: 3,846 internal checks. 953 gate + 81 deferred membership identical; census 3 rows. N1–N4 + N5″: only GoogleTest elapsed-time suffixes, newline framing, complete `M3_CP4AB_FRAGMENT_DIAG` record multiset (1,738 records, per-row, with prefix count equal to parsed count and ordered non-record lines unchanged), census `GetParam()` 16-byte object presentation, and the two candidate path fields removed before retained receipt comparison. All 956 match; 66 sphere receipts on 19 rows (380,388,393,394,396,397,644,645,648,669,686,691,694,698,699,700,843,844,858), 2 identical BunnyRandom receipts on census row 2; each exactly two path fields. Twelve negative offline controls reject removed/duplicate/altered M3, changed non-record byte, changed ledger, altered retained receipt prefix/suffix, and missing/additional path (both scopes). No project runtime. Both boundary records postflight=true, compile/relink/configure/benchmark=false. Gate 952 PASS, one RED row858 :155 (exit90/control_bad1); census Cylinder PASS/288, BunnyRandom/Vase RED (exit0). Row648 sphere assertions unreached. No unexplained differences.

Four independently rehashed unchanged inputs: gate `941287fa96f3432eb1d67a9ae1e5dc7bc0ca2f3a1775cd5f9fb35482a4fa7962`; census `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793`; deferred `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce`; harness `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94`. Reconstructed ordered 491 accepted rows, all PASS: focused30 `1e815443a03c7ef4a1b095e6ea973efa9c74bb0eae4e2f872510c97d057ea1d6`, focused12 `2aa57aac48ac8c41ea86ed459cdd1acd27eb17c8d3dbe1b4ac7b9c54c67374ed`, M5 449 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`; concat `452360f771daacb96f87697286ec7708832f63c876b9df9b1857e93433e5300b`. Accepted CP2 package 11391685901 unchanged.

### First common carrier and first equal entry (O48)

| Trace/segment | Face, branch | Entry / continuation |
|---|---|---|
| 43/13 | (94,124,210), 2 | (124,210):0.61720848767415282; transit (94,210):0=v94 |
| 15/19 | (94,124,210), 2 | (124,210):0.96607399795485316; transit (94,210):0=v94 |
| 43/14 and 15/20 | (72,94,243), 1 | exact entry (72,94):1=v94, incoming carrier none, to (72,243); exact eq=ee+xx |
| 43/15 and 15/21 | (72,243,273), 1 | same exact entry/exit, eq=ee+xx |
| 43/16 and 15/22 | (21,72,273), 2 | same exact entry/exit, eq=ee+xx, both end against trace82 segment0 |

The nine earlier same-face pairs have distinct parallel lines (nonzero opposing signs); the 13/19 pair is unevaluated. `SurfaceCellTracing.cpp:678–706` classifies exact vertex hits separately and clamps ordinary edge exits to a strictly interior dyadic parameter. Both measured inputs are interior, not vertex departures; `:3729–3836` records `edgeTransitExit` only on the grazing/edge-slide branch, adds the slide length, then resolves regular vertex outflow. `:2121–2168` chooses the carrier endpoint from consistent signed rates. Thus both slide from interior points of (94,210) toward its first endpoint 94. The common positive-length interval is from the nearer of their two carrier-entry points to 94. The receipt does **not** print those carrier-entry parameters: exact overlap onset and which entry is nearer are not certified. RA-255's vertex is the first identical **face entry**, not the earliest geometric overlap. This corrects the next definition's scope; do not postpone to the sphere fix. Downstream nodes 220 and 222 claim the same trace82 cut (display 0:0.2305473011248014); node welding would not remove either overlapping carrier or the identical suffix.

### Arrival order by independent bounded reconstruction

Source `BenchmarkCases.cpp:340–382,590–630` loads vertices in OBJ order; `InputConditioner.cpp:471,499–516`, `InputConditioner.h:19–29` use bit-preserving identity, `TriMesh.h:331–348` copies V/F; `RemeshPipeline.cpp:19711–19759,12917–12935` supplies the source mesh (parallel components false by default). Fixture `benchmarks/fixtures/milestone-g/bunny_1k_random.obj`, SHA `865d864f7afbd90283526d914e0d4d9718d83e9679943029060bde439b10ab05`, 502 vertices/1000 faces. All reconstructed path face keys and entry/exit supports match the fixture. Production default is ArcLengthFiltered (`SurfaceCellTracing.cpp:4854–4855`), with disjoint arrival bounds (`:2365–2374`); length accumulation `:3160–3219,3599–3608,3763–3786,3836`, and priority queue `:4296–4484` reject ordering by ordinal or insertion. For each non-slide segment sum the distance from its entry to the next entry. For unknown slide entry X on carrier AB, with start P and vertex V, triangle inequality gives lower |P−V|; convexity gives upper max(|P−A|+|A−V|, |P−B|+|B−V|). Sum all pieces before v94 (43: 14 segments, with slides 11 and 13; 15: 20 segments, slide 19). Decimal 60-digit reconstruction gives:

| Trace | Lower | Upper | Conservatively widened interval |
|---|---:|---:|---|
| 43 | 0.12952949962971406 | 0.13316803071398237 | [0.1294294996, 0.1332680308] |
| 15 | 0.13560762567243229 | 0.13592247012051176 | [0.1355076256, 0.1360224702] |

Widening by 1e-4 is conservative for printed rational truncation (18 decimal places, then double; producer uses 17), OBJ conversion and filtered double operations: coordinate magnitudes <1, barycentric weights in [0,1]; per-coordinate error/bound <1e-14, squared length error <1e-12, square-root error <1e-6, fewer than 25 legs per path, accumulation error negligible at this margin. The intervals are disjoint by >0.00223. Therefore 43 is conclusively earlier at v94 and at every common point of the co-directional slide suffix (subtract the same remaining carrier distance). This is a bounded reconstruction, not a recorded queue timestamp or exact slide-entry coordinate. Do not invent an exact overlap-start parameter or contact role from the decimal display.

## Recommendation — freeze the next definition obligation only

Exactly `M6-CP3-DEFN-P13-OPPOSING-TRACE-OVERLAP` (Review/definition, not implemented in this turn). Scope: co-directional overlap at a shared carrier interval and vertex locus O48, not opposing-only despite historical ID. Define the earliest occupied source locus and exact directed slide-piece interval, including the interior carrier entry before the vertex. Distinguish co-directional overlap, opposing overlap, transverse crossing, contact at a single endpoint, and disjoint paths. Prove whether a pending later trace terminates on the earlier wall at first shared locus under existing filtered-arrival authority; define inconclusive and already-retired-wall outcomes, including pending and committed segments and same-trace prior pieces. Use exact source component/region, carrier, direction, interval and vertex incidence, not rounded position, trace ID, segment order or consumer duplicate-ID welding. Preserve D11/D12 transport: do not change the outflow election to hide overlap. The shared vertex entry is a positive witness but not sufficient to resolve the earlier interval. Require exact per-piece slide start/end and arrival evidence where not already authoritative. Reuse the representation defined by the parallel sphere O47 DEFN where applicable; do not start or supersede that parallel turn.

Freeze independent falsifiers: distinct or disjoint exact intervals, opposite direction, different compatible source occurrence/region, single endpoint without overlap, earlier/later reversed by actual arrival, inconclusive filtered bounds, and no shared prior wall. A valid correction must remove the measured overlap at its causal producer and preserve exact incidence/cut ownership and all guards, not merely erase the receipt or move failure earlier. Require positive reduced carrier/vertex cases and near-miss/disjoint controls, order/face-row permutation invariance, stable unchanged 491 prefix, full gate and census comparison in separate CB/TB/REV turns. Do not freeze product implementation in this Review; definition must determine exact ownership/cut representation and test boundaries before a CB is authorized. Sphere through-crossing C5/O47 parallel unchanged. FC-6, terminal-cut and row858 fix held; C5/O42/O43/O46/O47/O48, H2, FC-1/FC-4 and middle-piece witness remain open. O45 consumer proxy only, C3/O44/C1 narrow closures retained. D11=A, D12=A, D10 deferred, D6 pending; chainRimSchedules=false. Stable 66 events/17 categories/49 recurrences, debt1, deferred81. No selector497/CP3/D0 promotion; PR #8 stays draft/unmerged.

## Review closeout

| Duty | Evidence |
|---|---|
| Independent comparison and non-vacuity | 956/956; 1,912 digest bindings; 12 negative controls; 491/491 prefix; 68 path receipts. |
| Causal classification | Carrier slide overlap before v94; first equal face entry 43/14 versus 15/20; 43 earlier by bounded arc length. Exact slide onset parameter open. |
| Durable tracking | Update handoff, TODO, ORIENTATION, ROADMAP, CHANGELOG, tracker; preserve prior criteria and append general lesson. |
| Consolidation | TB133 execution folded verbatim into D3; index and live references updated. RA-255 Review and previous compile records remain load-bearing for exact comparison, parallel definition and current package lineage. |
| Review boundary | Offline evidence only; no compile, runtime, source, test, fixture, selector or build edit. Local synthetic Git baseline has no historical commit objects; historical ancestry and no source drift independently checked by connector. |
| Successor | `M6-CP3-DEFN-P13-OPPOSING-TRACE-OVERLAP` definition only; no successor execution. |
| Lifecycle | Entry IN_PROGRESS; 2026-11-18T02:41:35Z; no Resumed at (initial entry from completed EXEC). Final completion requires verified push, cleanup and final STATUS. |
