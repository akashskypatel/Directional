# M6 Frozen Definitions — Occurrence, Quotient, Embedding, Independent Verification

**Status:** FROZEN / `M6-DEFN` COMPLETE / RUNTIME-FREE / EXACT NEXT = `M6-CP1-CB1`
**Date:** 2026-09-24
**Definition authority:** this record is the normative M6 contract for A5 occurrence creation, A6 quotient construction/materialization, A7 source-attached geometry embedding, and the M6 structural portion of A8 independent verification. It refines `DESIGN.md` §14 M6 without changing accepted M5 producer semantics or pulling M7 disposition/degradation work forward.

This definition turn changes documentation/planning only. It changes no product source, test, fixture, selector, benchmark, or build source and executes no generated Directional runtime.

## 1. Entering authority

M6 enters only after final `M5-CP4-TB2-REV` acceptance:

- accepted package/source `10814505512 / e284fea7c101eb86650d1c87c92d0fefa66050e7`;
- accepted selector449: **449/449 PASS**, LF SHA-256 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`;
- routing449 SHA-256 prefix `9c88a5ed...c5707`, owner census **32 / 301 / 75 / 41**;
- stable accounting **51 events / 14 categories / 37 recurrences**;
- produced-witness debt **1**, the M6-owned closed-complex `G4-B002` subject.

The Definition audit used exact source snapshot run/artifact `36026363482 / 10819439146` at source SHA `c9be476d75e6f5d6df11304ad6b926b27b36430f`; provider artifact SHA-256 `6331c1189591e0429128495719d6168c92827c9024175b2d121387706519d762`, embedded source archive SHA-256 `b57fe2df11bd0d988196b45dee8855581bff8cce942ce66c20b68ac8ee1b1b2e`, and all **5305/5305** source manifest rows verified. No generated Directional runtime executed.

**Process-only observation (`M6-DEFN-OBS-01`, +0):** several small repository documents were fetched directly before the turn fixed the mandatory `READ_MODE`. No semantic conclusion or mutation was accepted from that pre-snapshot inspection. The turn then froze `READ_MODE=snapshot`, acquired and verified the exact source authority above, and all decisive static adjudication used those verified bytes. Existing tool-conservation guidance already covers the pattern, so no new `LESSONS.md` rule is created.

The M5 `G4-B004` half is accepted and immutable: one **pipeline-produced** topology region is multi-isolation, owns a checked internal isolation-seam certificate, and owns a canonical periodic relation explicitly named by reciprocal `PeriodicCut` edges. M6 consumes that fact; it does not reconstruct, weaken, or reinterpret it.

## 2. Current implementation diagnosis

The current transitional function `build_authoritative_phase_front_mesh(...)` performs several future stages inline: it allocates corner occurrences, verifies relation ownership, performs quotient union, chooses quotient representatives, writes geometry, and publishes lineage into `PureQuadMesh`. This is precisely the stage coupling M6 must remove.

Two source facts constrain the cutover:

1. the production classifier now passes an explicit **empty isolation-barrier set** to `classify_source_surface_labels(...)`; hard-feature rails remain topology-region/chart/rail barriers and are not automatically `IsolationSheetId` barriers;
2. the transitional materializer still contains geometric representative consistency and output-lineage publication in the same procedure as quotient construction.

M6 therefore separates products rather than adding another downstream repair layer.

## 3. Stage A5 — `SurfaceOccurrenceComplex`

### 3.1 Sole producer and inputs

**Sole producer:** `SurfaceOccurrenceComplexProducer` (M6 A5).

**Typed inputs:** the complete immutable set of accepted A4 `RegionCellComplex` products plus the already-accepted M5 relation/certificate authority carried by those products. A5 does not consume output vertex rows, `PureQuadMesh`, world-space weld results, `SurfaceCellPipelineContext`, or diagnostic hashes as semantic authority.

### 3.2 Immutable output

```text
SurfaceOccurrenceComplex
  cells[]
    CellId
    cornerOccurrences[4] : OccurrenceId
    directedSides[4]     : (OccurrenceId from, OccurrenceId to)
  occurrences[]
    OccurrenceId
    CellId owner
    canonicalCornerRole
    SourceSupport
    TopologyRegionId
    IsolationSheetId
    FieldChartId / exact chart binding where required
    LocalLatticeState as value/provenance, not identity
  ownedRelations[]
    OccurrenceRelationId
    relationKind          // OrdinaryFront | HardRail | Periodic | SingularityPort
    firstOccurrence
    secondOccurrence
    typed relation owner / certificate reference
  OccurrenceComplexCertificate
```

Every accepted A4 cell appears exactly once and owns exactly four distinct corner occurrences and four directed sides. Every relation endpoint names an occurrence that exists in this product. A5 **does not union occurrences** and does not choose an output representative.

### 3.3 Occurrence identity

`OccurrenceId` is the semantic pair:

```text
(CellId, canonicalCornerRole)
```

where `canonicalCornerRole` is the corner between two adjacent directed sides in the A4 cell's immutable canonical cycle. The cycle's orientation/rotation is fixed by A4 semantic authority before A5; storage row, vector position, scheduler order, output row, world-space position, lattice coordinate, representative face/sheet, hash, and cache index are excluded.

Two occurrences remain distinct even when all of these coincide:

- lattice coordinate;
- exact source support;
- chart-local coordinate;
- 3D position.

Only A6 may equate them, and only through a verified A5 owned relation.

**`CellId` basis (reviewing-agent note; the definition is unchanged).**
- **What `CellId` is today.** The accepted A4 `CellId` is `from_index(rank)` over the sorted set of `(TopologyRegionId, region-chart grid ordinal v*width+u)` (`SurfaceCellTracing.cpp:17060-17075`, `:7785-7793`). `TopologyRegionId` is itself a rank over regions sorted by `canonicalFaceTopology`, a key built from source-vertex IDs (`:8520-8575`, `:8687`). Its semantic content is therefore (region canonical face topology, canonical chart cell coordinate). The chart position is legitimate *cell* identity, and the §3.3 lattice-coordinate exclusion concerns equality **between** occurrences.
- **Invariance evidence.** Face-row invariance of region, chart and periodic-cut identity is already accepted: selector449 rows 129, 196, 213, 245 and 254.
- **Known limit.** Rank-based IDs **renumber when a cell is inserted or omitted anywhere**. M6 does not rely on stability across differing cell sets, but M7 omission bookkeeping will, and `M7-DEFN` must decide whether a content-keyed `CellId` is required then.
- **Consequence for CB1.** The A5 permutation test must permute **source face rows**, not only cell storage (row 213 already covers storage). If face-row permutation renames `OccurrenceId`s because of A4 `CellId`, that is the CB1 stop rule "changing A4 `CellId` semantics". It routes to Review/Definition and must not be satisfied by a storage-only test.

### 3.4 A5 certificate and failures

`OccurrenceComplexCertificate` proves:

- one A5 cell record per accepted A4 `CellId`;
- exactly four unique occurrence IDs per cell;
- the four directed sides form the cell's exact ordered cycle;
- every occurrence has exactly one cell/corner owner;
- every owned relation has two existing, distinct typed endpoints and one typed owner/certificate reference;
- no occurrence or relation was inferred from geometric coincidence.

A5 owns fail-closed `OccurrenceConstructionFailure` codes for missing/duplicate cell ownership, missing/duplicate corner occurrence, invalid directed-side cycle, relation endpoint missing, duplicate relation declaration, unowned relation, and source-authority mismatch. A rejected A5 product is not consumable.

## 4. Stage A6 — `SurfaceQuotientProduct`

### 4.1 Sole producer and inputs

**Sole producer:** `SurfaceQuotientProducer` (M6 A6).

**Typed inputs:** immutable A0 source authority plus exactly one complete `SurfaceOccurrenceComplex`. A6 may look up the typed M5 relation values named by A5, but may not search for an alternative relation or synthesize a missing one.

### 4.2 Immutable output

```text
SurfaceQuotientProduct
  classes[]
    QuotientClassId
    sorted member OccurrenceId set
  relationCertificates[] : QuotientRelationCertificate
  consumptionLedger[]
    OccurrenceRelationId
    firstOccurrence
    secondOccurrence
    exactlyOneConsumption
  topology
    quotient vertices identified by QuotientClassId
    one ordered quad per accepted CellId
  MaterializationCertificate
  QuotientCertificate
```

A6 is **topological**. It creates no source-attached 3D vertex representative and no geometric weld. One accepted A5 cell maps to exactly one output quad. An A5 relation becomes quotient authority only after the producer verifies that exact declared relation; an unrelated valid M5 relation remains decision-neutral.

### 4.3 Quotient identity and equality

`QuotientClassId` is the canonical, sorted, non-empty **set of member `OccurrenceId` values**. It is not the smallest member, a sequential class row, the union-find root, a representative sheet, a coordinate, or a hash.

Two classes are equal if and only if their complete member sets are equal. Relation application is deterministic over canonical relation identity, but union-find roots and traversal order are representation leaves only.

### 4.4 Exact-once relation ownership

The phrase **owned relation** means an `OccurrenceRelationId` explicitly published in A5 `ownedRelations`. Available but unreferenced M5 relation-table entries are not A5-owned relations and remain decision-neutral.

For every A5 owned relation, A6 must record exactly one `QuotientRelationCertificate` and exactly one consumption-ledger row. Zero consumption, duplicate consumption, conflicting endpoint use, relation substitution, or consumption by an unowned relation is typed failure. This is the M6 meaning of "every owned relation is consumed exactly once" and is consistent with M5's accepted unused-valid-relation contract.

### 4.5 A6 certificate and failures

`QuotientCertificate` proves the class partition is exactly the transitive closure of **verified A5 owned relations** and nothing else. `MaterializationCertificate` proves:

- every `CellId` maps to one and only one output quad;
- every output quad corner maps to the `QuotientClassId` containing that cell's corresponding `OccurrenceId`;
- every quotient class is non-empty;
- no class arose from coordinate/position equality;
- every A5 owned relation appears exactly once in the relation-consumption ledger.

A6 owns fail-closed `QuotientConstructionFailure` codes for missing/duplicate/conflicting/nonreciprocal relation authority, unowned relation use, zero/duplicate relation consumption, invalid class partition, missing occurrence member, degenerate classed quad, and non-bijective cell-to-quad materialization. M5's accepted typed relation failures remain unweakened; M6 does not rename a valid M5 failure into success.

## 5. Stage A7 — `SourceAttachedGeometryProduct`

### 5.1 Sole producer and inputs

**Sole producer:** `SourceAttachedGeometryProducer` (M6 A7).

**Typed inputs:** immutable A0 source authority and one complete `SurfaceQuotientProduct`, with the A5 occurrence/source-support evidence referenced by the quotient certificates. A7 may not change A6 topology or quotient membership.

### 5.2 Immutable output

```text
SourceAttachedGeometryProduct
  topology                 // identical semantic A6 topology
  vertices[]
    QuotientClassId
    exact SourceSupport
    source-attached coordinates / barycentric representation
    intended component / isolation-sheet authority
  SourceSupportCertificate[]
  GeometryEmbeddingCertificate
```

The vertex's semantic identity remains its `QuotientClassId`. Position is a value derived from exact source support and cannot merge, split, or rename a quotient class.

A quotient class spanning multiple certified chart/sheet representations is legal only when the A5/A6 relation certificates explicitly establish that equivalence. A7 records the complete compatible source authority; it never selects a representative sheet and silently discards the others.

### 5.3 A7 certificate and failures

For each quotient class, `SourceSupportCertificate` proves that every contributing occurrence is incident to the published exact support under the already-certified relation path and that the embedded value remains on the intended source component/sheet authority. `GeometryEmbeddingCertificate` proves topology is unchanged from A6 and every quotient vertex is embedded exactly once.

A7 owns fail-closed `GeometryEmbeddingFailure` codes for missing/ambiguous source support, support/certificate mismatch, cross-component or uncertified cross-sheet binding, missing quotient vertex embedding, duplicate embedding, non-finite geometry, and topology mutation. Nearest-position coincidence and epsilon welding are forbidden recovery mechanisms.

## 6. Stage A8-M6 — `VerificationReport`

### 6.1 M6 scope and M7 boundary

**Sole producer:** `SurfaceProductVerifier` (M6 structural A8).

**Typed inputs:** immutable A0, A5, A6, and A7 products and their certificates. The verifier outputs immutable `VerificationReport` only.

`OutputDisposition`, `DegradationCertificate`, tier assignment, omission, and degraded production remain **M7**. The full DESIGN A8 contract is completed in M7; M6 must not pull disposition/degradation forward merely because the verifier exists first.

### 6.2 What the verifier may recompute

The verifier may independently recompute only elementary facts from immutable inputs:

- source face/edge/vertex incidence and component adjacency from A0;
- exact incidence of a published `SourceSupport` using the shared source-support kernel;
- occurrence ownership counts and directed-side cycle incidence from A5;
- output quad incidence, edge incidence, connected components, boundary loops, Euler characteristic, and manifoldness from A6 topology;
- cell-to-quad and occurrence-to-class membership by reading the published A5/A6 IDs;
- exact composition/inversion of a **named** relation certificate's recorded transport;
- source-support incidence of an A7 embedded vertex;
- deterministic equality of immutable certificate payloads under semantic ordering.

Shared primitive value types and exact algebra are allowed. Reusing a producer's **decision procedure** is not independent verification.

### 6.3 What the verifier may never do

The verifier may never:

- create or renumber an `OccurrenceId` or `QuotientClassId`;
- union occurrences or choose a quotient representative;
- search a relation graph for a replacement route/path;
- infer a missing endpoint, route, owner, chart, sheet, source support, or relation;
- canonicalize malformed producer state into an acceptable form;
- substitute an equivalent relation or reverse relation not explicitly certified by the producer;
- weld by lattice coordinate, barycentric tolerance, 3D position, or proximity;
- repair a directed-side cycle, quad incidence, source attachment, or certificate;
- mutate A5/A6/A7 or emit a corrected product;
- invoke fallback/recovery or convert a producer rejection into a verified product.

On any violation it emits a typed `VerificationFailure` in the report. A report is successful only when the original immutable products verify as published.

### 6.4 Verification report identity

Findings are keyed and ordered by semantic stage/locus IDs, never by discovery order. The report may include representation indices as diagnostics, but changing source-row, output-row, or scheduler order cannot change the semantic finding set.

## 7. Product dependency and mutation law

The only M6 authority flow is:

```text
A4 RegionCellComplex set
  -> A5 SurfaceOccurrenceComplex
  -> A6 SurfaceQuotientProduct
  -> A7 SourceAttachedGeometryProduct
  -> A8-M6 VerificationReport
```

A later stage may reference earlier immutable IDs/certificates; it may not write into them. Aggregation is a new immutable output, never in-place normalization. `PureQuadVertexLineage`, `SurfaceCellPipelineContext`, diagnostics, hashes, output row numbers, and existing transitional materializer locals may be retained temporarily as compatibility/diagnostic surfaces, but none may become semantic stage authority.

## 8. M6 debt and blocker ownership

### 8.1 `G4-B002` closed-complex produced witness

The original contract remains unchanged: fail-closed `SurfaceCells`, recovery/fallback disabled, closed source, independently validated candidate eligibility, and a discriminating hard-feature/protection tamper. Synthetic/direct arrangement authority receives zero credit.

- **M6-CP1 mechanism owner:** establish the real A5 occurrence product and A6 stage boundary from which candidate extraction can consume closed-complex authority without `SurfaceCellPipelineContext::hasArrangement`.
- **M6-CP3 evidence owner:** re-prove the unchanged candidate-extraction eligibility oracle and hard-feature tamper on direct production after A5-A8 are complete.

CP1 mechanism evidence cannot close the production debt.

### 8.2 `G4-B001 / PR8-R034 / G4-R007`

**Disposition: not a currently demonstrated M6 implementation defect; carry as a direct-production evidence debt to `M6-CP3`.**

The historical root was a hard feature being promoted into `IsolationSheetId` authority, after which strict closure reported `LocalSheetMismatch`. Current production source explicitly separates those domains: `hardFeatureRailEdges` remain topology-region/chart/rail barriers while `classify_source_surface_labels(...)` receives an empty `sourceIsolationBarrierEdges` set. The original root condition is therefore not present at the current source boundary.

M6 must nevertheless preserve this separation:

- CP1/A5-A7 must not derive an isolation sheet from hard-rail membership;
- A7 may cross a chart/region boundary only under certified quotient relation authority and must preserve complete sheet evidence;
- CP3 owns the historical strict-valid torus **3/3** direct-production re-proof.

If CP3 reproduces `LocalSheetMismatch`, the new failure must be classified against the frozen A7 source-support/embedding contract; validators or sheet authority may not be weakened to obtain green output.

### 8.3 `G4-B004` M6 representative-consumption half

M6 closure requires the **same direct produced torus authority** accepted by M5-CP4, not a synthetic substitute. The proof chain is:

1. retain the accepted M5 same-region producer fact unchanged;
2. A5 materializes four explicit occurrences per cell and relation endpoints by occurrence ID;
3. A6 consumes every A5-owned relation exactly once and publishes quotient/materialization certificates;
4. A7 embeds the resulting quotient classes with complete source-support and multi-isolation evidence;
5. A8 independently verifies the same immutable A5-A7 products without reconstructing the M5 relation or isolation-seam fact.

Existing never-gated identities are disposed as follows:

- `SurfaceCellTransitionQuotient.MultiIsolationMaterializationRetainsAllLocalSheets` — **retain and gate during M6-CP1** as focused mechanism preservation only. It is not representative direct-production credit by itself.
- `SurfaceCellsPhase10.ExactCommittedTorusDoesNotTreatIsolationSeamAsBoundedDiskBoundary` — **retain and gate during M6-CP3** as direct torus preservation. It is necessary but insufficient by itself for M6 closure because it does not independently prove the new A5/A6 exact-once ledger and A8 verification.

M6-CP3 must therefore add/use a dedicated representative M6 identity that binds the accepted M5 producer fact to A5 occurrence ownership, A6 exact-once consumption, A7 embedding, and A8 independent verification in one direct production result. No M6 evidence grants retroactive M5 credit.

## 9. Dormant CB14 identity disposition

`M5-CP3-TB1-R16-REV-OBS-01` is now fully resolved with **no M5 credit**: one deletion, and one retention with a named gating owner (see the re-adjudication below the table).

| Dormant identity | Disposition | Existing accepted replacement authority | First action owner |
|---|---|---|---|
| `M5CP3.PeriodicRelationEndpointGaugeIsIndependentAndExact` | **DELETE as superseded/redundant** | accepted `M5CP3.PeriodicRelationRotationUsesBothAcceptedOccurrenceGauges` covers the exact occurrence-gauge/branch rotation seam; accepted nonzero-Z4 production identities cover nonzero translation/materialization | `M6-CP1-CB1` test-source cleanup only |
| `M5CP3.ProducedTorusPeriodicPairStorageSwapPreservesSemanticDirection` | ~~DELETE as superseded/redundant~~ → **RETAIN AND GATE in the first M6-CP1 prepublication gate** *(deletion stopped by the §9 precondition; see note below)* | ~~row 444 covers storage permutation~~. Row 444 reverses the **relation container** and row 432 resolves semantic direction. Neither permutes **edge storage**, and no selector449 row does. | `M6-CP1` prepublication gate (vector frozen by the CB1 report / TB1 plan) |

Deletion removes dormant, never-gated duplicate authority; it does not modify an accepted selector and cannot be cited as evidence for M5 or M6. If either accepted replacement ceases to cover the stated property, deletion must stop and be re-adjudicated before test source changes.

**Reviewing-agent re-adjudication of row 2.** The pair-swap identity swaps the reciprocal `PeriodicCut` edge pair **in `edges` storage**, remaps events and compares selected certificates after materialization, all on the nonzero-Z4 witness. Front-edge indices are a DESIGN §6.2 representation handle, and the A5 cutover must not depend on them. No accepted identity covers this permutation, so the precondition above fires. The identity is **retained untouched** and becomes a candidate in the M6-CP1 prepublication gate. Classification rules if it runs RED:
- if it is RED on the CB1 candidate, that is an edge-storage-order dependence, a §11 falsifier-1-class finding;
- its pre-cutover status is unknown, so Review must determine whether CB1 introduced the dependence.

It still carries **no M5 credit**. Row 1's deletion is upheld, because accepted row 446 checks `make_periodic_relation_endpoint_state` outputs against produced edges.

## 10. M6 checkpoint split

### M6-CP1 — product separation

Establish complete A5 occurrence, A6 quotient, and A7 geometry products in bounded Code + Build / artifact-only TB steps. Transitional `build_authoritative_phase_front_mesh(...)` may remain as a thin adapter during the cutover, but semantic occurrence/quotient/embedding decisions must move behind the stage-product APIs. CP1 also gates the focused multi-isolation mechanism identity and proves no coordinate/position weld.

### M6-CP2 — independent verifier

Introduce `SurfaceProductVerifier` consuming immutable A0/A5/A6/A7 products and certificates. It independently recomputes only §6.2 elementary facts and fails typed on every §6.3 malformed-authority class. It never calls producer repair/canonicalization/search routines.

### M6-CP3 — direct production exit

Fresh direct-production evidence must prove:

- equal coordinates/positions without a certified relation remain distinct;
- every A5-owned relation is consumed exactly once;
- source support is exact/shared, with no consumer-specific quantized identity;
- source-row, output-row, and scheduler permutation invariance;
- the unchanged `G4-B002` candidate-extraction + hard-feature tamper contract;
- `G4-B001` strict torus 3/3 re-proof;
- `G4-B004` representative same-produced-authority occurrence/quotient/embedding/verifier chain.

## 11. Frozen falsifiers

The M6 definition is falsified by any implementation that:

1. uses world-space position, lattice coordinate, vector row, output row, scheduler order, representative sheet, hash, or cache index as `OccurrenceId`/`QuotientClassId` equality;
2. lets A5 union occurrences or A7 change A6 quotient/topology;
3. consumes an A5 owned relation zero or more than once, or lets an unrelated valid relation affect the selected quotient;
4. lets the verifier search, infer, repair, substitute, canonicalize, weld, or mutate producer state;
5. credits CP1 mechanism evidence as the direct `G4-B002` or `G4-B004` production proof;
6. treats dormant CB14 identities as M5 evidence or deletes them without the replacement-authority precondition in §9;
7. re-promotes hard features into isolation-sheet authority or weakens `LocalSheetMismatch` to close `G4-B001`;
8. implements `OutputDisposition`/degradation before M7.

Any such result halts the current M6 checkpoint and returns to definition/review rather than being patched downstream.

## 12. Exact bounded successor

Exactly one successor is authorized: **`M6-CP1-CB1`**, under `Architecture_M6_CP1_CB1_Occurrence_Product_Code_Build_Plan.md`.

CB1 is intentionally limited to the first A5 seam: introduce content-semantic occurrence identity and a complete immutable `SurfaceOccurrenceComplex` producer, make the existing transitional materializer consume that product instead of allocating A5 occurrence authority inline, and perform the two §9 dormant-test deletions. It does **not** implement A6 quotient extraction as a new product, A7 embedding, A8 verifier, selector publication, runtime execution, or any G4 debt closure.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | selector449 LF SHA-256 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`; unchanged |
| Decisive claims independently re-derived | current hard-rail/isolation classifier separation; current inline occurrence/quotient/geometry coupling; dormant CB14 selector absence and accepted replacement identities; M6/M7 sequencing |
| Non-vacuity checked | coordinate/position coincidence is explicitly excluded from identity; exact-once ledger can fail at zero/duplicate consumption; verifier repair/search/substitution are explicit falsifiers; direct production remains distinct from mechanism evidence |
| Prior obligations discharged/carried | `M5-CP3-TB1-R16-REV-OBS-01` discharged by §9 no-credit deletion disposition; M6 `G4-B002`, `G4-B001`, and `G4-B004` carried with checkpoint owners in §8 |
| Stable accounting | `51 / 14 / 37`; debt `1`; accepted package/source `10814505512 / e284fea7...`; selector449 accepted |
| New candidates/obligations recorded | M6 A5-A8 stage contract, `G4-B001` CP3 evidence owner, `G4-B004` CP1/CP3 gate split; tracker updated |
| ORIENTATION currency line | `M6-DEFN`, 2026-09-24 |
| ORIENTATION §3 / §4 / §7 / §8 | §3 and §7 updated for M6; §4 unchanged because no witness ran; §8 no new recurring defect pattern |
| CHANGELOG | root and agent changelogs updated for `M6-DEFN` |
| ROADMAP | M6-DEFN marked complete; exact next `M6-CP1-CB1` |
| Selector manifest | n/a — no selector byte added, changed, published, or accepted |
| LESSONS | n/a — no genuinely new recurring process/product pattern; existing identity/authority and no-synthetic-success rules apply |
| Consolidation under CLEAN_UP_POLICY | consumed `Architecture_M6_DEFN_Occurrence_Embedding_Verifier_Plan.md` folded into the new M6 consolidated record/index; frozen definitions and one next-turn plan retained |
| Successor frozen | exactly `M6-CP1-CB1`; falsifiers in this record §11 and successor plan |
| Turn boundary held | runtime-free; no product/test/fixture/selector/benchmark/build mutation; no generated Directional runtime |
| review_check.py boundary | **PASS** — `review_check.py boundary --expect-selector 449=d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`; no product/test/fixture/build or selector mutation; durable markers preserved |
| `STATUS` lifecycle maintained | `M6-DEFN / IN_PROGRESS` at entry; final COMPLETE beacon is the required last repository write |
| Pushed to origin, branch in sync | **CONFIRMED.** Verified Drive patch transport run/job `36028759747 / 107731931289` pushed exact patch SHA-256 `f8429d1f49adf9945b58ed2cf506f4477a5b9ef5872f0b49e3d1c8f7b9f8aab7` with schema validation PASS and `runtimeExecution=false`; owner-side Drive retirement succeeded. Turn-cleanup run/job `36028922947 / 107732420524` removed both M6-DEFN trigger markers; recursive tree verification at cleanup head found exactly the seven durable workflows and no connector-trigger/workflow-observation/turn-payload state. This isolated closeout-row update is applied against the current blob by exact SHA before the final STATUS beacon. |

---

## Independent verification addendum (reviewing agent)

Runtime-free. **UPHELD WITH AMENDMENTS.** The A5/A6/A7/A8-M6 product split, the exact-once owned-relation ledger, the verifier's recompute-only / never-repair boundary, the CP1/CP2/CP3 split, the M7 disposition boundary and the successor `M6-CP1-CB1` all stand.

**Verified:**
- **Clean process.** Docs landed (16:38Z) before the COMPLETE beacon (16:41:45Z), and nothing was written after it. `review_check.py ledgers --base 62b5ed26` PASSes, and no code surface changed.
- **§2/§8.2 `G4-B001` basis.** `RemeshPipeline.cpp:7862-7865` constructs an empty `sourceIsolationBarrierEdges` set and passes it to `classify_source_surface_labels`, as claimed. The last measurement of `G4-B001` is still pre-M1 (0/3 at artifact `9031804178`), so the CP3 re-proof is its first fresh measurement.
- **The `DESIGN.md` A8 row edit** is consistent with DESIGN §14 M7, which already introduces `OutputDisposition`. The dropped "computed, not asserted" wording survives as M7's "labeled by the verifier, never by a producer".

**Amendments:**
1. **§3.3 `CellId` basis was unstated.** `OccurrenceId = (CellId, role)` was declared free of representation handles without examining `CellId`. `CellId` is a canonical rank of (region canonical-face-topology rank, region-chart grid ordinal). Face-row invariance is accepted (selector449 rows 129, 196, 213, 245 and 254), so M6's permutation exclusions hold. The rank renumbers on insertion or omission, which is flagged for `M7-DEFN`. The CB1 permutation test must permute face rows. A note is added in §3.3, with the definition unchanged.
2. **§9 row 2 deletion stopped.** `ProducedTorusPeriodicPairStorageSwapPreservesSemanticDirection` permutes **edge storage** on the nonzero witness. Its named replacement, row 444, permutes the relation container, and no selector449 row permutes edge storage. Front-edge indices are a DESIGN §6.2 representation handle that A5 must not depend on. Under §9's own precondition the identity is retained and proposed for the CP1 prepublication gate. The row-1 deletion stands.
3. **Tracker entries were buried.** This turn appended them at the end of `Regression_Root_Cause_Tracker.md`, below the 9,800-line restored history. They are moved above it, and a placement rule is added at the boundary. This is the third "append at end of a newest-first ledger" instance.
4. **Stale text.** The closed M5 frozen header still said "EXACT NEXT = `M6-DEFN`", and the TODO `G4-B001` item was stale. Both are fixed.

### Review closeout — reviewing-agent addendum

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | selector449 `d4a0d1b7…`, 448 `70ff0860…`, 430 `1c412850…` via `boundary --expect-selector` |
| Decisive claims independently re-derived | `CellId` and `TopologyRegionId` construction from source; face-row invariance rows; the `G4-B001` classifier input; each dormant test against its named replacement's actual permutation; DESIGN M7 ownership of `OutputDisposition`; turn write ordering; `ledgers` |
| Non-vacuity checked | The CB1 permutation test is now required to permute face rows, because storage-only is row 213. The edge-storage witness is retained rather than deleted. |
| Prior obligations discharged/carried | R16 OBS-01 resolved: one deletion, plus one retention with a named gate owner. `G4-B002`, `G4-B001` and `G4-B004` are carried as frozen in §8. |
| Stable accounting | 51 / 14 / 37; debt 1 (M6); entry package `10814505512 / e284fea7…`; selector449 |
| New candidates/obligations recorded | Tracker addendum entry (moved M6-DEFN entries plus a placement rule) |
| ORIENTATION currency line | `M6-DEFN` (incl. reviewing-agent addendum), 2026-09-24 UTC |
| ORIENTATION §3 / §4 / §7 / §8 | §7 items 1 and 5 amended. §3, §4 and §8 are unchanged and correct. |
| CHANGELOG | Agent and root entries amended |
| ROADMAP | n/a — correct |
| Selector manifest | n/a |
| LESSONS | 176 and 178 cited; no new lesson |
| Consolidation under CLEAN_UP_POLICY | n/a — the M6 consolidated record exists and the DEFN plan is indexed |
| Successor frozen | `M6-CP1-CB1`, per its plan plus the binding reviewing-agent amendment |
| Turn boundary held | Runtime-free; no product/test/selector change |
| review_check.py | `boundary --expect-selector 449=d4a0d1b7… 448=70ff0860… 430=1c412850…`: **ALL CHECKS PASSED**. No product/test/build or selector mutation; durable markers 1→1, 3→3, 13→13. `ledgers --base 62b5ed26`: **ALL CHECKS PASSED**. |
| `STATUS` lifecycle | Resume beacon first; final `COMPLETE → M6-CP1-CB1` last |
| Pushed, in sync | Confirmed by `git status -sb` after the final push |
