# Surface-Cell Regression Root-Cause Tracker

Permanent stable-ID regression, repeated-pattern, architecture, and test-authority index for PR #8. Detailed event evidence remains in `.agents/Directional/PR_8_Regression_Audit_Inventory.md`; dated turn reports retain artifact/runtime detail.

Last updated: **2026-08-09 UTC** after M1d compile/package artifact `9046308272` (**immutable runtime pending**).

## Rules

- Assign a stable regression ID only when previously accepted behavior/test/package/public authority is lost.
- Persistence while a gate remains red is not a recurrence; recurrence requires restoration followed by later loss.
- Compile success never resolves runtime or architecture migration work.
- New migration code remains pending until immutable semantic acceptance.
- Known-red/deferred product cases stay explicit and are never relabeled green/expected-failure to close architecture work.
- Focused/helper passes cannot close representative product intent.
- Before every turn review `RP-01` through `RP-09`; every touched pattern needs an exact invariant and counterexample/representative gate.

## Historical PR-wide authority

- **34 distinct regression events**;
- **14 architectural categories**;
- **20 recurrences**;
- **114 regression-bearing result-document commits**.

T1 artifacts `9040549377 / 9041289209`, accepted M1a artifact `9041930767`, accepted M1b artifact `9042940168`, and accepted M1c artifact `9043971772` create no new production regression event or recurrence. M1d artifact `9046308272` is compile/package evidence only and therefore creates no stable runtime event. `PR8-R034 / G4-R007` remains active.

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
- M1d phase-front route consumer: **compile-complete; immutable runtime pending**.

M1d invariant now compiled:

- packed route endpoint values cross checked `LegacyAuthorityAdapters::source_vertex(..., sourceVertices.rows())` before semantic use;
- supplied and authoritative compact route values cross checked `LegacyAuthorityAdapters::interior_transition(..., sourceEdgeIndices.size())`;
- semantic transition equality is `InteriorTransitionId` equality, not raw integer equality;
- malformed IDs remain fail-closed through existing HardRail/PeriodicCut authority failures.

Focused counterexamples compiled for negative/out-of-range transition IDs and out-of-domain packed source vertices. Runtime proof is the next immutable turn.

### RP-02 — proxy/incomplete test authority

```text
bad: compile/helper/status/count claimed as product proof.
good: named semantic contract + independent oracle + direct representative evidence.
```

`RP-02 / TA-05` remains **test-authority resolved** through accepted M1c, but M1d preservation is runtime-pending.

Accepted entering authority remains:

- producer discovery exactly **172**, required-green **157/157**;
- M1c focused **6/6** and three transition counterexamples green;
- M1b focused **6/6**, validation **77/77**;
- M1a exact 14 and **14/14**;
- T1 exact 29 and **29/29**;
- Plane/MultiFaceSeam/CloseSheets/Cylinder green and independent-oracle clean;
- Bunny known-red with independent oracle before fatal product-success assertion;
- Vase bounded 60-second safety-only evidence.

M1d statically packages six focused tests and expects producer discovery **178** / required-green **163**. Those counts and all preservation authority must be proven, not inferred, in the following immutable turn.

### RP-03 — policy/stage state conflation

```text
bad: attempted/succeeded/disposition/debug retention are combined into mutable policy state.
good: closed producer outcome + single-writer stage product + derived diagnostics.
```

Untouched by M1a–M1d. M2 owns migration.

### RP-04 — nonterminating cumulative work

```text
bad: nested retries each have local bounds but total work can grow without one monotone budget.
good: one shared work ledger + monotone progress measure + deterministic exhaustion failure.
```

Untouched by M1a–M1d. Vase remains bounded safety-only evidence; M1d introduces no search/retry/work loop.

### RP-05 — representation-dependent identity

```text
bad: row/hash/traversal/allocation position becomes semantic identity.
good: semantic strong ID/key is authoritative; row/hash is an explicit compatibility representation only.
```

- M1a semantic ID/key kernel: **accepted**.
- M1b semantic source identity versus row representation: **accepted**.
- M1c canonical `SourceEdgeTopologyKey` versus raw `edge_key`: **accepted**.
- M1d phase-front route identity: **compile-complete; immutable runtime pending**.

M1d invariant now compiled:

- packed route endpoints are converted to `SourceVertexId` before identity logic;
- `SourceEdgeTopologyKey::make` supplies semantic route-edge identity and uniqueness;
- typed endpoints are serialized back only at the existing packed-key compatibility lookup boundary;
- canonical serialized representation must equal the supplied packed key;
- no new hash/key authority or route reordering was introduced.

Compiled counterexamples include topology/transition mismatch and duplicate semantic route topology. Runtime proof remains pending.

### RP-06 — state-cardinality growth

```text
bad: copied mutable authority tables accumulate across stages/regions.
good: one immutable authority product/reference per semantic fact.
```

Untouched by M1a–M1d. M2/M4 own shared authority storage.

### RP-07 — cyclic topology linearization

```text
bad: quarter-turn/cyclic relation handled as unrestricted signed integer arithmetic.
good: exact modulo-4 semantic algebra + explicit inverse; legacy integer is compatibility representation only.
```

M1c is **accepted**: authoritative field transition matching uses `QuarterTurn`, reverse uses `.inverse()`, and raw signed matching remains compatibility representation only.

M1d changes no route transport or periodic Z4 action. The following immutable turn must preserve M1c six focused contracts plus all three transition counterexamples.

### RP-08 — producer-disposition conflation

Untouched. M2 owns migration.

### RP-09 — local consumption of global authority

Untouched by M1a–M1d. `G4-R007` remains active; M3/M4 own global conformity/certificate migration.

## M1d compile-only pattern record

| Pattern | State | Compile/package evidence | Immutable runtime requirement |
|---|---|---|---|
| `RP-01` | **compile-complete** | checked `SourceVertexId` + `InteriorTransitionId`; malformed-domain tests compiled | exact M1d 6/6 + route/direct preservation |
| `RP-05` | **compile-complete** | canonical `SourceEdgeTopologyKey`; mismatch/duplicate tests compiled | route identity semantic success/fail-closed evidence |
| `RP-07` | **preservation pending** | M1c source/static manifests packaged unchanged | M1c 6/6 + three transition counterexamples |
| `RP-02 / TA-05` | **preservation pending** | M1c/M1b/M1a/T1 static manifests packaged unchanged | producer 178 accounting + M1b/M1a/T1/direct authority |

M1d compile/package authority:

- implementation `9446fc82d98d336d3bd59c190dd2bbbe94bd2e25`;
- build run/job `31342400614 / 93318225812`;
- result artifact `9046308272`, SHA-256 `6a9dd880e2e7548b8afc88da48e7ed49935e6ce672ba1af208eee8f84678152c`;
- log artifact `9046308461`, SHA-256 `4813676a45370644fce64854d430822b86a0e406e9446a7ea3159c8fb23d315c`;
- manifest **59/59**, SHA-256 `e9859b25bd6d3a721484abdae679fcf898a85e1903b176192696d4b6b9e7eef0`;
- Release/static/Ninja **120/120**, `runtimeExecution=false`.

Temporary M1d connector workflow/trigger/apply-script files were removed after immutable artifact capture.

## M1c immutable pattern record

| Pattern | Result | Evidence |
|---|---|---|
| `RP-01` | **accepted at field-transition consumer** | checked face/vertex adapters + M1c 6/6 |
| `RP-05` | **accepted at source-edge representation boundary** | canonical key + endpoint reversal contract |
| `RP-07` | **accepted at matching transport boundary** | exact modulo/inverse + `+5` relation |
| `RP-02 / TA-05` | **preserved** | 172 exact accounting + M1b/M1a/T1/direct independent authority |

M1c authority remains artifact `9043971772`; report `.agents/Directional/Architecture_M1c_Field_Transition_Consumer_Artifact_Only_Test_Benchmark_Report.md`.

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
| `AR-02` | M1a/M1b/M1c accepted; **M1d route source-vertex/transition adoption compile-complete/runtime pending** |
| `AR-03` | M1a/M1b/M1c accepted; **M1d packed route identity compile-complete/runtime pending** |
| `AR-04` | `FieldChartId` exists; production chart migration remains later M1 |
| `AR-05` | M1a/M1b/M1c representation boundaries accepted; **M1d compile-complete/runtime pending** |
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
| `TA-05` | test authority accepted through M1c; **M1d preservation runtime pending** |
| `TA-06` | T1 mutation suite 29/29 accepted; M1d preservation pending |
| `TA-07` | M1d exact package authority compile-complete; runtime discovery pending |
| `TA-08` | M1d six route-identity semantic/counterexample tests compiled; runtime pending |
| `TA-09` | coherent resource/work gate pending |
| `TA-10` | T2 semantic fixture manifest pending |
| `TA-11` | topology/lineage/disposition adequate; quality expansion later |
| `TA-12` | `tests/TESTING_STRATEGY.md` normative only |

## Authoritative next step

`.agents/Directional/Architecture_M1d_Phase_Front_Route_Identity_Consumer_Artifact_Only_Test_Benchmark_Plan.md`.

The next turn is **immutable Test + Benchmark only**. It consumes exactly artifacts `9046308272 / 9046308461`, rebuilds/edits nothing, proves exact M1d route semantics and counterexamples, requires producer discovery 178 / required-green 163, and independently preserves M1c/M1b/M1a/T1/direct product authority. If any required-green gate regresses, remain at M1d and return to corrective Code + Build.