# TB154 trace-piece ray helpers — independent full-gate review (2026-11-21 UTC)

## Situation

**PASS — TB154 immutable gate upheld.** The three new ray-helper tests ran and passed. Independent byte verification supports 971/971, prior 968/968 N1–N3 match, three of three N1–N4 census matches, and 491/491 preserved CP2 cases. The helpers remain unwired and this Review authorizes only one bounded Code + Build producer switch. It does **not** accept CP3, selector 497, D0/H4, a topology repair, or a new direct-production outcome.

## Background — independently opened authority

- Branch `agent/surface_cell_quad/p5-recover-bridge-healing`; frozen review snapshot source `857862586bf8fb9f771a9917cf7ed1863069a677` from GitHub source-snapshot run `44878253914`, artifact `14696882780`. Semantic/build source remains CB169 `ef86370d0a1436250bdc8417b6b1abdeb1df5a74`, package `14694154267` (no rebuild in review).
- TB154 gate run `44874759906`, artifact `14696380156`, ZIP SHA-256 `ce172d892dbf3f52084eaf3a148ec03443bc19c06ec9e5262f89e35c89b648c0`. Internal SHA256SUMS 1950/1950 verified. TB153 prior artifact `14692372657`, ZIP SHA-256 `5e102074ae1bbfcf9c1a94a928e8d354725b484c67fa7dc53410d887a12f8147` (1944/1944).
- TB154 census run `44874777995`, artifact `14696590265`, ZIP SHA-256 `0dd3b6ea13c1c0b6db4822fe91fd58483990cd7515898e99e780bb3bc19991e6` (9/9). TB151 baseline `14621727104`, ZIP SHA-256 `4eacb6f3d9d272a2ee380527fc8f7abab516508a596d3dea3f955e8086a4c611` (9/9).
- TB153 manifest hash `fc075b4c33e0f934d8636a4c9c4186d19fea24e5cd6ae88e516c5c6ff1514116`, 145036 bytes. TB154 hash `0f9c417c6bb4b563abc90e5707eee98656210df322f5e0d00af1efc8f9f4e305`, 145526 bytes. Verified byte prefix; the extra 490 bytes are exactly rows 969–971. Gate membership 1052 = 971 required + 81 deferred.

## Assessment — independent byte and semantic checks

### Gate and census

A separately written Python comparison re-read the four immutable archives' ledgers and raw logs, recomputed each log SHA-256, and compared rows by identity and raw output. **All 971** gate rows have one run, one pass, zero skips and exit zero. **All 968** prior rows match in their metadata and in normalized raw output; 558 raw logs are byte-identical and 1750 exact M3 `region_support_projection` lines match as a multiset. Normalization only removes Google Test millisecond timing (N1), normalizes CRLF to LF (N2), and sorts the existing region-support diagnostic multiset (N3). Row 686 is included; it still reports sphere V18/E30/F18, χ6 versus source χ2. The first 491 accepted CP2 cases are green. Source/package and postflight markers report no configure, compile, relink, or benchmark operation.

Census identities match one to one: Cylinder PASS, BunnyRandom expected RED, Vase expected RED, both at `SurfaceCellDesignAcceptanceTests.cpp:493`. Only four address payloads on each side (two 16-byte `GetParam()` lines in each RED log) were masked under prior N4. No error text, test outcome, row identity, topology digest, or other field was masked. There is no new stable regression: 66 events / 17 categories / 49 recurrences, one produced-witness debt, 81 deferred.

### Row 971 and predeclared predictions

The raw test contains exactly one receipt, ten `SpherePieceRay` records and ten `SpherePieceRaySlideEnd` records (21 total). Receipt: `vertexRays=34 alongEdge=10 inWedge=24 edgeRays=4 alongLocusEdge=0 intoFace=4 changedVertexParameter=0 changedOrdinary=0 failures=0 coincidentAlongEdge=0 coincidentWithEdgeArc=0`.

Slide ends by trace: 0→vertex8 on 6–8, 9→vertex8 on 8–9; 1→vertex21 on 16–21, 11→vertex21 on 20–21; 13→vertex34 on 32–34, 21→vertex34 on 33–34; 12→vertex45 on 40–45, 22→vertex45 on 45–46; single 10→vertex49 on 49–62 and 14→vertex0 on 0–69. All ten report `kind=alongEdge` and use the same outgoing carrier listed in TB153 S1. The four convergence pairs reach different edges at the same respective vertices: no identical along-edge ray (`coincidentAlongEdge=0`). The ordinary-ray difference was reported as zero (`changedOrdinary=0`), not assumed. The prediction that the *production* rotation remains unchanged is not yet established by this unwired helper receipt; it is a mandatory falsifier of the following direct switch's TB.

Non-vacuity: row 969 independently distinguishes a piece ray at 2/3 from its legacy chord ray at 0 and tests typed invalid cases; row 970 asserts an along-locus edge ray different from legacy within-side rank 4, plus into-face and negative cases. Row 971 reaches 34 vertex rays and 4 edge rays with 10 actual slide ends, so a no-op receipt would fail its minimum and type checks. The receipt is **non-gating for the production-switch claim**, and no current row demonstrates changed production rotation.

### RA-274 S5 — slide-to-conformity admission

The retained real-piece reach row 968 proves 24 sphere traces / 182 segments / ten face-then-edge slide segments, with zero rejected paths. The sphere's produced topology is not cellular (row686 χ6 vs χ2 and row669/698 `CutSearchExhaustedBeforeCellularity`), so there is **no sphere `GlobalTopologyPlan` reaching conformity with slide arcs**. Retained TB151/TB154 census shows Cylinder succeeds but has no recorded slide, Vase ends at completion without slide receipts, and BunnyRandom stops in cut-graph construction (no plan). Existing evidence therefore supplies **no fixture that both carries a slide in a valid plan and reaches conformity**. This is a scope limit, *not* proof that conformity handles piece paths: post-stop-switch TB must check the sphere's first qualifying plan and piece counts explicitly.

The expected zero slide-conformity overlap makes the current census non-vacuous for unchanged background semantics, but **vacuous for new conformity behaviour**. Do not claim completeness by the three census matches.

### RA-274 S5 — accepted chord assertions and downstream readers

The accepted `GlobalTopologyPlan.IndependentValidationBindsTraceSegmentsToSourcePieceCounts` (`tests/FieldAlignedCurveNetworkTests.cpp:3605–3669`) explicitly enforces one face chord per segment, a one-element count, and rejection of a split face+edge path. After the switch, its formerly-invalid representation can be valid. The next CB must update that test's structural premise using a source-supported, distinct expected case and keep all negative binding/replay assertions meaningful. It must **not weaken assertions or claim that every old accepted row will stay byte-identical**. A TB with intentional changed rows needs a separately frozen non-match allowance and independent review, not N1–N3 normalization.

`tests/FieldAlignedCurveNetworkTests.cpp:12970–13030` and `:13130` retain accepted legacy vertex parameter/rank oracles. Preserve their unaffected ordinary-path results, add piece-path adversarial rays to the same semantic owner, and ensure the switch no longer uses the chord reader in production. The `:3967` one-chord/one-fragment assertion also requires explicit review against the source-face fragment owner once a real piece path reaches that stage. Keep invalid-network-binding cases as failures.

The production consumer inventory is not just arc creation and rotation: `RemeshPipeline.cpp:1014` builds conformity spans from `arc.sourcePath`; `GlobalConformityBaseline.cpp:830` builds mandatory-chain span support from the same field. `GlobalTopologyPlan.cpp:2496` hashes path but not `sourcePieceCounts`; the switch must hash counts so different segment-to-piece partitions cannot share a semantic digest. `GlobalTopologyPlan.cpp:~520` and `~1270` use segment-level orbital ownership and skip terminal slits only when non-separating; `SurfaceCutGraph.cpp:~450,~543` has independent segment/orbit readers. Do not silently mark these old chord readers piece-correct. The next TB must expose any source-face fragment/owner mismatch rather than suppress it.

`RA-275 S4` requires the edge piece's two adjacent faces to receive opposite winding sides. Existing `edge_piece_face_side` is the owner of that operation. The next CB must connect its result consistently to the segment's source support, with false-side and across-face controls. A closed plan may have a face whose only boundary is a slide; when it first reaches conformity, prove the seed is retained or fail closed. No current case proves that path. All-edge-only arc handling in the disc-phase-front remains an explicit conditional gate (none observed at row968). `O49` remains off the producer-switch path until stop-switch suffix-separation measurements.

### Scope and unresolved topology

No source/product/test/fixture, selector, workflow, or build code was changed in this review; no Directional executable or benchmark ran. The producer is still using face chords, so the sphere's four strictly interior sliding-wall contacts remain unowned. Retain O47/C5, O42/O43, O46/O48, held O49, D11=A, D12=A, D10 deferred, D6 pending, `chainRimSchedules=false`, rows669/698, and the held FC-6/terminal cut and row858 definitions. Do not promote CP3/497/D0/H4.

## Recommendation — one frozen successor

**Exactly one authorized next turn:** `M6-CP3-CB-169S-P13-TRACE-PIECE-PRODUCER-SWITCH` (Code + Build; compile-only). No work in that turn was started here.

Required implementation scope (keep all part of one atomic semantic cutover):

1. Switch the `build_arcs` trace producer from chord assembly to the verified `exact_trace_piece_path_between`, with per-segment `sourcePieceCounts`, canonical support, direction, and the existing exact binding validator; preserve mandatory/cut-edge arc behaviour.
2. Wire both vertex and edge rotation/rank readers to the EPO-4 piece-ray helpers. Compare along-edge rays with source-edge-supported order, not wedge-only interior parameters. No new tie-break, positional equivalence, or silent rank reassignment. Retain source-face/sheet authority and typed errors.
3. Hash canonical `sourcePieceCounts` into `candidate_semantic_digest`, retaining the independently validated path hash and other contract fields. Keep the original three ownership readers and `edge_piece_face_side` obligations visible; no O49 or stop-switch edit.
4. Replace the old chord-specific test premise only when it is made false by actual piece production, with an exact positive slide witness and negative count, support, and replay controls. Keep ordinary-path regression assertions and accepted test identities. Add direct cross-face and all-edge-only controls where the producer change makes them reachable; do not dilute a failure or make tests green by changing assertions without a new independent oracle.
5. Compile the eight mandatory GMP/GMPXX targets through the existing dispatcher, `runtimeExecution=false`. No tests/benchmarks in the CB. No graph stop switch, sphere chi repair, source-face ownership rewrite, selector or checkpoint promotion.

**Predeclared falsifiers for the following TB (separate subsequent turn; not authorized now):** a changed prior row without an explicit, independently justified semantic delta; loss of any of CP2's 491 green identities; changed ordinary non-slide rays, wrong terminal/outgoing-carrier direction or order, nonzero unaccounted along-edge coincidences, unowned chart/sheet/side, incorrect counts or unchanged digest under a counts-only mutation, conformity falsely admitted for a slide-owned face, a lost seed at the edge-piece opposite-face boundary, or invalid all-edge-only handling. Record first changed row with raw receipts, reject rather than normalize it away. A sphere χ result is not a success criterion for this switch; the contact stop switch comes later and has its own independent gate.

**STOP at the following Review instead of the stop switch** if any falsifier holds, if producer cutover changes an accepted row beyond an independently frozen allowance, or if piece rays introduce a source-face/edge ownership ambiguity. Do not infer that the four missing contacts were repaired.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | TB153 manifest `fc075b4c…1514116` 145036 bytes is exact prefix of TB154 `0f9c417c…f4e305` 145526 bytes; three additional rows 969–971; 81 deferred; CP2 frozen selector 491 remains accepted. |
| Decisive claims independently re-derived | Four source ZIP outer hashes, all internal SHA256SUMS, 971 gate ledgers/log hashes, 968 prior rows N1–N3 with 558 byte-equal and 1750 exact M3 projection records, 3 census rows N1–N4, 21 row971 records; code-reader inventory inspected. |
| Non-vacuity checked | Row969 2/3 versus 0; row970 along-edge vs rank4, typed controls; row971 34 vertex and four edge rays; no slide-conformity success fixture, so conformity behaviour remains unproved. |
| Prior obligations discharged/carried | Discharged TB153 S3 observed along-edge slides, changedOrdinary0, no equal-edge collision; row971 and RA-274 S5 receipt/chord-test inventory. Carried: production-rotation invariance, RA-275 S4 opposite-face sides/seed, disc all-edge-only case, first slide-plan conformity and real-piece counts at stop-switch TB, O49 suffix-orbit measurement. |
| Stable accounting | 66/17/49; debt1; deferred81; CP2 491/491 accepted; CP3/selector497/D0 unpromoted. |
| New candidates/obligations recorded | No new stable candidate; conditional reader and conformity gates assigned to bounded successor and tracker. |
| ORIENTATION currency line | TB154 Review, 2026-11-21; current turn authority and next code switch updated in place. |
| ORIENTATION §3 / §4 / §7 / §8 | §3 stale RA-276/TB152 state replaced; §4 no witness changes, same sphere contacts; §7 stale TB154-EXEC priority replaced and superseded warning removed; §8 no new general defect pattern, cited existing lessons. |
| CHANGELOG | Added this independent review's verdict and exact evidence identity. |
| ROADMAP | Active M6-CP3 status updated only; no checkpoint promotion. |
| Selector manifest | n/a: no selector accepted or modified in Review. |
| LESSONS | Existing field ownership, review evidence, old-premise test and cutover coverage lessons applied; no genuinely new general rule. |
| Consolidation under CLEAN_UP_POLICY | No current evidence authority or cited historical review can be safely folded without losing load-bearing or retained exact references; no stale file deleted. This review is current. |
| Successor frozen | Only `M6-CP3-CB-169S-P13-TRACE-PIECE-PRODUCER-SWITCH`; scope, falsifiers and STOP rule above. |
| Turn boundary held | Review-only; no product, test, fixture, manifest, selector, build, benchmark or workflow source change; no Directional runtime. |
| review_check.py boundary | PENDING LOCAL CHECK — replace after execution. |
| `STATUS` lifecycle maintained | Entry written for this canonical turn at 2026-11-21T07:00:58Z; final direct beacon must follow all documentation and cleanup. |
| Pushed to origin, branch in sync | PENDING remote patch push and branch confirmation; do not claim success until verified. |
