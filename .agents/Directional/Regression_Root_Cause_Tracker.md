# Surface-Cell Regression Root-Cause Tracker

Permanent stable-ID regression, repeated-pattern, architecture, and test-authority index for PR #8. Detailed historical event evidence remains in `.agents/Directional/PR_8_Regression_Audit_Inventory.md`; the current immutable turn report owns current artifact/runtime detail.

Last updated: **2026-08-10 UTC** after M1e compile artifact `9049125645`; immutable runtime remains pending.

## Rules

- Assign a stable regression ID only when previously accepted behavior/test/package/public authority is lost.
- Persistence while a gate remains red is not a recurrence; recurrence requires restoration followed by later loss.
- Compile success never resolves runtime or architecture migration work.
- New migration code remains pending until immutable semantic acceptance.
- Known-red/deferred product cases stay explicit and are never relabeled green/expected-failure to close architecture work.
- Focused/helper passes cannot close representative product intent.
- Before every turn review `RP-01` through `RP-09`; every touched pattern needs an exact invariant and counterexample/representative gate.
- Stale per-turn documents are not historical authority. Once their facts are folded into this tracker/current report/audit inventory, they may be removed under the handoff cleanup policy.

## Historical PR-wide authority

- **34 distinct regression events**;
- **14 architectural categories**;
- **20 recurrences**;
- **114 regression-bearing result-document commits**.

T1 artifacts `9040549377 / 9041289209`, accepted M1a artifact `9041930767`, accepted M1b artifact `9042940168`, accepted M1c artifact `9043971772`, accepted M1d artifact `9046308272`, and compile-only M1e artifact `9049125645` create no new production regression event or recurrence. M1e runtime authority is pending. `PR8-R034 / G4-R007` remains active.

| Cause category | Pattern | Events | Recurrences |
|---|---|---:|---:|
| `AUTHORITY_DOMAIN_CONFLATION` | `RP-01` | 6 | 5 |
| `TEST_AUTHORITY_COVERAGE_GAP` | `RP-02` | 6 | 5 |
| `POLICY_STAGE_STATE_CONFLATION` | `RP-03` | 4 | 3 |
| `NONTERMINATING_CUMULATIVE_WORK` | `RP-04` | 3 | 2 |
| `REPRESENTATION_DEPENDENT_IDENTITY` | `RP-05` | 2 | 1 |
| `STATE_CARDINALITY_GROWTH` | `RP-06` | 2 | 1 |
| `CYCLIC_TOPOLOGY_LINEARIZATION` | `RP-07` | 2 | 1 |
| `PRODUCER_DISPOSITION_CONFLATION` | `RP-08` | 2 | 1 |
| `LOCAL_CONSUMPTION_OF_GLOBAL_AUTHORITY` | `RP-09` | 2 | 1 |
| five singleton categories | — | 5 | 0 |
| **Total** |  | **34** | **20** |

Singletons: `INTRINSIC_SUPPORT_OVERCONSTRAINT`, `INCOMPLETE_TRANSACTIONAL_ROLLBACK`, `SHARED_EDGE_ORIENTATION_INVERSION`, `INCOMPLETE_ORBIT_PUBLICATION`, `EXACT_SIMPLEX_CANONICALIZATION_LOSS`.

## Repeated coding-pattern catalog

### RP-01 — authority-domain conflation

```text
bad: one bare integer is reused as face/transition/chart/rail/etc.
good: distinct semantic type + named checked adapter + typed failure.
```

- M1a strong-ID kernel: **accepted**.
- M1b source-face/source-vertex production consumer: **accepted**.
- M1c field-transition source-face/source-vertex consumer: **accepted**.
- M1d phase-front route source-vertex/interior-transition consumer: **accepted**.
- M1e ordered segment-route step identity crosses the same checked source-vertex/interior-transition boundaries before `TransitionStep` construction; compilation/package is complete and runtime acceptance is pending.

M1d accepted invariants:

- packed route endpoint values cross checked `LegacyAuthorityAdapters::source_vertex(..., sourceVertices.rows())` before semantic use;
- supplied and authoritative compact route values cross checked `LegacyAuthorityAdapters::interior_transition(..., sourceEdgeIndices.size())`;
- semantic transition equality is `InteriorTransitionId` equality, not raw integer equality;
- malformed IDs remain fail-closed through existing HardRail/PeriodicCut authority failures.

### RP-02 — proxy/incomplete test authority

```text
bad: compile/helper/status/count claimed as product proof.
good: named semantic contract + independent oracle + direct representative evidence.
```

`RP-02 / TA-05` remains **test-authority resolved and preserved through M1d**; M1e preservation is pending immutable artifact execution:

- producer discovery exactly **178**;
- required-green producer segment **163/163**;
- M1d focused **6/6** plus route counterexamples **3/3**;
- M1c focused **6/6** plus transition counterexamples **3/3**;
- M1b focused **6/6**, validation **77/77**;
- M1a exact 14 and **14/14**;
- T1 exact 29 and **29/29**;
- Plane/MultiFaceSeam/CloseSheets/Cylinder green and independent-oracle clean;
- nine historical/deferred producer reds explicitly retained;
- Bunny known-red with independent oracle before fatal product-success assertion;
- Vase bounded 60-second safety-only evidence.

M1e focused tests may not replace this authority.

### RP-03 — policy/stage state conflation

```text
bad: attempted/succeeded/disposition/debug retention are combined into mutable policy state.
good: closed producer outcome + single-writer stage product + derived diagnostics.
```

Untouched by M1a–M1e. M2 owns migration.

### RP-04 — nonterminating cumulative work

```text
bad: nested retries each have local bounds but total work can grow without one monotone budget.
good: one shared work ledger + monotone progress measure + deterministic exhaustion failure.
```

Untouched by M1a–M1e. Vase remains bounded safety-only evidence. M1e must add no search/retry loop.

### RP-05 — representation-dependent identity

```text
bad: row/hash/traversal/allocation position becomes semantic identity.
good: semantic strong ID/key is authoritative; row/hash is an explicit compatibility representation only.
```

- M1a semantic ID/key kernel: **accepted**.
- M1b semantic source identity versus row representation: **accepted**.
- M1c canonical `SourceEdgeTopologyKey` versus raw packed source-edge key: **accepted**.
- M1d route identity versus packed route key/index: **accepted**.
- M1e compiles each route step through canonical `SourceEdgeTopologyKey` + `InteriorTransitionId`; observed route orientation is preserved through `CanonicalRoute::oriented_steps()` rather than canonical storage order becoming behavioral order. Runtime acceptance is pending.

### RP-06 — state-cardinality growth

```text
bad: copied mutable authority tables accumulate across stages/regions.
good: one immutable authority product/reference per semantic fact.
```

Untouched by M1a–M1e. M2/M4 own shared authority storage.

### RP-07 — cyclic topology linearization

```text
bad: quarter-turn/cyclic relation handled as unrestricted signed integer arithmetic.
good: exact modulo-4 semantic algebra + explicit inverse/composition; legacy integer is compatibility representation only.
```

M1c is accepted at individual edge transport: `QuarterTurn::from_integer`, algebraic reverse `.inverse()`, raw signed matching retained only as compatibility output.

M1d preserved this unchanged.

**M1e is the current direct RP-07 migration:** `segment_on_source` now compiles typed zero-shift `GridAutomorphism` per step, `TransitionStep`/`CanonicalRoute` for the observed route, algebraic composition in observed order, and integer matching only at the final compatibility write. Immutable runtime acceptance is pending.

The separate periodic-holonomy accumulation remains outside M1e.

### RP-08 — producer-disposition conflation

Untouched. M2 owns migration.

### RP-09 — local consumption of global authority

Untouched by M1a–M1e. `G4-R007` remains active; M3/M4 own global conformity/certificate migration.

## M1d immutable pattern record

| Pattern | Result | Evidence |
|---|---|---|
| `RP-01` | **accepted at phase-front route consumer** | checked source vertices + interior transitions; M1d 6/6 |
| `RP-05` | **accepted at route representation boundary** | canonical topology key; mismatch/duplicate fail-closed contracts |
| `RP-07` | **preserved** | M1c 6/6 + three transition counterexamples |
| `RP-02 / TA-05` | **preserved** | producer 178, required-green 163/163, M1b/M1a/T1/direct authority |
| `RP-03/04/06/08/09` | untouched | bounded implementation and unchanged dispositions |

M1d authority:

- implementation `9446fc82d98d336d3bd59c190dd2bbbe94bd2e25`;
- build run/job `31342400614 / 93318225812`;
- result artifact `9046308272`, SHA-256 `6a9dd880e2e7548b8afc88da48e7ed49935e6ce672ba1af208eee8f84678152c`;
- log artifact `9046308461`, SHA-256 `4813676a45370644fce64854d430822b86a0e406e9446a7ea3159c8fb23d315c`;
- manifest **59/59**, SHA-256 `e9859b25bd6d3a721484abdae679fcf898a85e1903b176192696d4b6b9e7eef0`;
- authoritative current report `.agents/Directional/Architecture_M1d_Phase_Front_Route_Identity_Consumer_Artifact_Only_Test_Benchmark_Report.md`.

Bunny/Vase M1d comparison run `31343763822` preserved accepted known-red/safety dispositions and exact package postflight. Temporary runtime workflow/trigger files were removed.

Prior M1a/M1b/M1c detailed per-turn reports were cleaned after their accepted facts were folded into this tracker, the PR audit inventory, current live status, and immutable artifact history. Artifact IDs above remain historical authority; deleted stale report paths are not resume dependencies.

## M1e compile-complete pattern record — runtime pending

| Pattern | Compile result | Pending immutable proof |
|---|---|---|
| `RP-01` | checked source vertices + compact interior transitions at each observed step | exact six focused tests + complete producer preservation |
| `RP-05` | canonical topology key and semantic route-keyed observations; `oriented_steps()` preserves behavior order | forward/reverse and signed-equivalence contracts |
| `RP-07` | zero-shift `GridAutomorphism` route composition replaces raw cumulative signed addition | nonzero multi-step/inverse and legacy-path contracts |
| `RP-02 / TA-05` | deterministic hard-authored expected values, independent compact IDs, semantic snapshot keys | producer 184, required-green 169/169, M1d/M1c/M1b/M1a/T1/direct evidence |
| `RP-03/04/06/08/09` | untouched | unchanged dispositions/accounting |

M1e compile authority:

- implementation `a0330d0107f7d7340e9f8644d26dd6c8b753ff10`;
- build run/job `31351113129 / 93341993183`, **120/120**;
- result artifact `9049125645`, SHA-256 `d16222c62f6f7491eaa830fe22ac4f768b6f426646639f155ccfd8feb9d378f7`;
- log artifact `9049125905`, SHA-256 `fd1d816fd4265f803f6be278941eb7647d056eb6336d05fe98e865621fd5e7be`;
- manifest **61/61**, SHA-256 `36a6377350aa4b58205ccd881a7ee34156800d28e3c5edecf634769289d9e7e5`;
- no generated Directional binary, discovery, test, or benchmark executed;
- report `.agents/Directional/Architecture_M1e_Segment_Route_Transport_Consumer_Code_Build_Report.md`.

The review-authorized malformed contract targets the reachable predecessor `source_edge_provenance` authority boundary. It does not claim an unreachable typed-constructor failure and does not reinterpret `CrossFieldEdgeTransition::sourceEdge` as semantic transition identity.

## Current G4 stable-ID mapping

| PR event | G4 ID | Category | Pattern | Status |
|---|---|---|---|---|
| `PR8-R028` | `G4-R001` | `AUTHORITY_DOMAIN_CONFLATION` | `RP-01` | resolved |
| `PR8-R029` | `G4-R002` | `LOCAL_CONSUMPTION_OF_GLOBAL_AUTHORITY` | `RP-09` | resolved |
| `PR8-R030` | `G4-R003` | `TEST_AUTHORITY_COVERAGE_GAP` | `RP-02` | resolved |
| `PR8-R031` | `G4-R004` | `AUTHORITY_DOMAIN_CONFLATION` | `RP-01` | resolved |
| `PR8-R032` | `G4-R005` | `POLICY_STAGE_STATE_CONFLATION` | `RP-03` | resolved |
| `PR8-R033` | `G4-R006` | `AUTHORITY_DOMAIN_CONFLATION` | `RP-01` | test-authority resolved |
| `PR8-R034` | `G4-R007` | `LOCAL_CONSUMPTION_OF_GLOBAL_AUTHORITY` | `RP-09` | **active** |

`G4-R007` authority remains production artifact `9031804178`: direct torus 0/3 with 241 `LocalSheetMismatch` issues after 192 quads, complete lineage, `4/8/4`, `1/0/0`. M1 migration does not repair or reinterpret it.

## Persistent blockers

| ID | Blocker | Required gate |
|---|---|---|
| `G4-B001` | Direct torus final `LocalSheetMismatch`. | strict-valid torus 3/3 |
| `G4-B002` | Exact Phase10 torus `InvalidHardRailPairing`. | shared source-authoritative rail schedule; M3 |
| `G4-B003` | Nonzero periodic Z4 production capability. | staged M1/M4 adoption + product acceptance |
| `G4-B004` | Positive multi-isolation quotient witness. | focused + representative certificate evidence |

## Architecture enforcement register

| ID | State |
|---|---|
| `AR-01` | M2: closed producer outcomes |
| `AR-02` | M1a/M1b/M1c/M1d **accepted**; M1e ordered transport-step adoption compile-complete, runtime pending |
| `AR-03` | strong identity adoption through M1d **accepted**; M1e typed step identity compile-complete, runtime pending |
| `AR-04` | `FieldChartId` exists; production chart migration remains later M1 |
| `AR-05` | representation boundaries through M1d **accepted**; M1e observed/canonical orientation boundary compile-complete, runtime pending |
| `AR-06` | M4 relation registry/certificates |
| `AR-07` | M3 global conformity |
| `AR-08` | M2/M3 producer-scoped immutable output |
| `AR-09` | tagged source-support representation exists; exact production rebinding remains M5 |
| `AR-10` | incremental responsibility modules |
| `AR-11` | normative architecture/status separation maintained |
| `AR-12` | T1 independent oracle/package accepted; T2–T6 expand authority |

## Test architecture register

| ID | State |
|---|---|
| `TA-01` | topology/lineage/disposition accepted; geometry/field/quality later |
| `TA-02` | T2 ten-case direct matrix pending |
| `TA-03` | metric definitions/baselines pending |
| `TA-04` | T3/T4 generation/shrinking/fuzz pending |
| `TA-05` | **test authority resolved and preserved through M1d**; M1e preservation pending immutable artifact execution |
| `TA-06` | T1 mutation suite **29/29** accepted and preserved |
| `TA-07` | exact package/discovery authority accepted and preserved |
| `TA-08` | M1a route algebra + M1c edge transport + M1d route identity accepted; M1e production route-composition contracts compiled, runtime pending |
| `TA-09` | coherent resource/work gate pending |
| `TA-10` | T2 semantic fixture manifest pending |
| `TA-11` | topology/lineage/disposition adequate; quality expansion later |
| `TA-12` | `tests/TESTING_STRATEGY.md` normative only |

## Authoritative next step

`.agents/Directional/Architecture_M1e_Segment_Route_Transport_Consumer_Artifact_Only_Test_Benchmark_Plan.md`.

The next turn is **immutable Test + Benchmark only**. It consumes exact artifact `9049125645`, rebuilds/edits nothing, validates the six focused route-transport contracts with their independent oracles and reachable malformed provenance boundary, and re-proves complete M1d/M1c/M1b/M1a/T1/direct authority.
