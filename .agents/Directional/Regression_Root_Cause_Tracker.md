# Surface-Cell Regression Root-Cause Tracker

Permanent stable-ID regression, repeated-pattern, architecture, and test-authority index for PR #8. Detailed event evidence remains in `.agents/Directional/PR_8_Regression_Audit_Inventory.md`; dated turn reports retain artifact/runtime detail.

Last updated: **2026-08-09 UTC** after M1c compile/package artifact `9043971772` (**runtime pending; not semantic acceptance**).

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

T1 artifacts `9040549377 / 9041289209`, accepted M1a artifact `9041930767`, and accepted M1b artifact `9042940168` create no production regression event or recurrence. M1c compile/package artifact `9043971772` has not executed runtime and therefore neither resolves nor creates an accepted runtime event. `PR8-R034 / G4-R007` remains active.

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

**M1a kernel:** immutable accepted, 14/14.

**M1b first production adoption:** immutable accepted at `provenance_supports_interval_sheet`.

**M1c field-transition adoption:** **compile-complete; immutable runtime pending** at authoritative `CrossFieldEdgeTransition` consumption in `resolve_branch_transition`.

M1c invariant now implemented:

- pre-existing source-edge topology/adjacency checks remain first;
- source/target and transition first/second faces cross checked `LegacyAuthorityAdapters::source_face(..., faces.rows())` before semantic reciprocity;
- transition source-edge endpoints cross checked `source_vertex(..., vertices.rows())` before semantic edge identity;
- invalid typed conversion fails closed and cannot fall through to legacy matching/geometric inference.

Compiled counterexamples include out-of-range authoritative face and source-edge metadata with valid fallback inputs present. Runtime proof is the next immutable turn.

### RP-02 — proxy/incomplete test authority

```text
bad: compile/helper/status/count claimed as product proof.
good: named semantic contract + independent oracle + direct representative evidence.
```

`RP-02 / TA-05` remains **test-authority resolved** by T1 artifact `9041289209` and independently preserved by accepted M1b:

- validation discovery exactly 77 and full **77/77**;
- M1b focused **6/6** individually;
- M1a exact 14 discovery and **14/14**;
- T1 exact 29 discovery and **29/29**;
- Plane/MultiFaceSeam/CloseSheets/Cylinder green and independent-oracle clean;
- Bunny known-red with independent oracle before fatal product-success assertion;
- Vase bounded 60-second safety-only evidence.

M1c only compiled its six focused tests. **No M1c runtime acceptance is inferred from compile success.** Its following immutable artifact-only turn must repeat focused + aggregate + independent product authority.

### RP-03 — policy/stage state conflation

Untouched by M1a/M1b/M1c. M2 owns closed producer-outcome migration.

### RP-04 — nonterminating cumulative work

Untouched by M1a/M1b/M1c. Vase remains a known 60-second bounded nonreturn; this is safety evidence only. M1c introduces no search/retry/work loop.

### RP-05 — representation-dependent identity

```text
bad: row/hash/traversal/allocation position becomes semantic identity.
good: semantic strong ID/key is authoritative; row/hash is an explicit compatibility representation only.
```

**M1a kernel:** accepted.

**M1b first production adoption:** immutable accepted. Source-face/source-vertex rows become semantic IDs before incidence logic; legacy row indexing occurs only after semantic identity has been established.

**M1c field-transition adoption:** **compile-complete; immutable runtime pending**.

M1c invariant now implemented:

- transition endpoints become `SourceVertexId` first;
- `SourceEdgeTopologyKey::make(v0,v1)` canonicalizes semantic edge identity;
- endpoint order cannot change semantic identity;
- typed endpoints return to legacy row indices only at the existing raw `edge_key` lookup-representation boundary;
- no second hash/key authority was added.

Compiled counterexample: reversed transition endpoints must resolve identically. Runtime proof remains pending.

### RP-06 — state-cardinality growth

Untouched by M1a/M1b/M1c. M2/M4 own shared authority storage.

### RP-07 — cyclic topology linearization

```text
bad: quarter-turn/cyclic relation handled as unrestricted signed integer arithmetic.
good: exact modulo-4 semantic algebra + explicit inverse; legacy integer is compatibility representation only.
```

**M1a kernel:** exact `QuarterTurn`/automorphism/reversal algebra accepted.

**M1c field-transition adoption:** **compile-complete; immutable runtime pending**.

M1c invariant now implemented:

- authoritative `CrossFieldEdgeTransition.matching` becomes `QuarterTurn::from_integer(...)` for semantic transport;
- reverse traversal uses `.inverse()`;
- target branch uses the typed modulo-four transport;
- raw signed `BranchTransitionResult.matching` remains compatibility representation only (`matching` forward, `-matching` reverse);
- the separate legacy fallback remains unchanged.

Compiled counterexamples cover forward +1, reverse inverse, and `+5 == +1` semantically while preserving raw compatibility output. Runtime proof remains pending.

### RP-08 — producer-disposition conflation

Untouched. M2 owns migration.

### RP-09 — local consumption of global authority

Untouched by M1a/M1b/M1c. `G4-R007` remains active; M4 owns certificate/global-local relation migration.

## M1c compile-only pattern record

| Pattern | State | Compile/package evidence | Immutable runtime requirement |
|---|---|---|---|
| `RP-01` | **compile-complete** | checked face/vertex adapters; malformed authority test compiled | exact M1c focused pass + producer/direct preservation |
| `RP-05` | **compile-complete** | canonical `SourceEdgeTopologyKey`; endpoint reversal test compiled | endpoint-order semantic equality at runtime |
| `RP-07` | **compile-complete** | `QuarterTurn` modulo/inverse; +5/reverse tests compiled | exact six focused contracts + periodic tamper preservation |
| `RP-02 / TA-05` | **preservation pending** | M1b/M1a/T1 source/static manifests packaged unchanged | M1b 6/6 + validation 77/77 + M1a 14/14 + T1 29/29 + direct oracle cases |

M1c authoritative compile/package evidence:

- implementation `e139fca885538e310dc47ed7ba531517603d92cf`;
- build run/job `31334345368 / 93297618568`;
- result artifact `9043971772`, SHA-256 `dde120c94be222dc93aeebb08f7a674882c5f8011ede62ec420209b0e0f4fd85`;
- log artifact `9043971968`, SHA-256 `7747b3b25882fc86e54890a1efb69d753f9b2e08bff7db8fd2be4f4a8a82fedb`;
- manifest **54/54**, SHA-256 `d9a4bdfe5b160095a6cf4949c57e54d726d36f745ff0a6580e9080d5319d495d`;
- Release/static/Ninja **120/120**, `runtimeExecution=false`.

Temporary connector workflow/helper files were removed after artifact capture and are not part of the final product/test diff.

## M1b immutable pattern record

| Pattern | Result | Evidence |
|---|---|---|
| `RP-01` | **first production seam accepted** | focused 6/6 + compile-time domain boundary + validation 77/77 |
| `RP-02` | **preserved** | exact 14/29 discovery, 14/14 + 29/29, direct oracle evidence |
| `RP-05` | **first representation boundary accepted** | typed incidence contracts + direct preservation |
| `RP-03/04/06/07/08/09` | untouched | bounded source diff + preserved aggregate/direct behavior |

M1b report: `.agents/Directional/Architecture_M1b_First_Production_Consumer_Artifact_Only_Test_Benchmark_Report.md`.

## Standing Bunny/Vase runtime procedure

Long-running Bunny/Vase may use an artifact-only GitHub Actions runner under explicit user authorization. The runner must verify immutable artifact/package/executable content before execution, restore executable mode only after content-hash verification if needed, perform no configure/build/relink/content mutation, retain exact runtime evidence, and remove temporary workflow/trigger/helper files before closeout.

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

`G4-R007` authority remains production artifact `9031804178`: direct torus 0/3 with 241 `LocalSheetMismatch` issues after 192 quads, complete lineage, `4/8/4`, `1/0/0`. M1 migration work does not repair or reinterpret this event.

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
| `AR-02` | M1a strong-ID/route kernel accepted; M1b first production consumer accepted; **M1c field-transition adoption compile-complete/runtime pending** |
| `AR-03` | M1a domain-key core accepted; M1b source identity adopted; **M1c source-edge key compile-complete/runtime pending** |
| `AR-04` | `FieldChartId` exists; production chart/snapshot migration remains after bounded M1 consumers |
| `AR-05` | M1a identity/orientation core accepted; M1b first representation boundary accepted; **M1c source-edge/quarter-turn boundary compile-complete/runtime pending** |
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
| `TA-05` | **test-authority resolved by T1 and preserved through M1b; M1c preservation pending immutable runtime** |
| `TA-06` | T1 mutation suite 29/29 accepted; M1c preservation pending |
| `TA-07` | exact package/discovery authority accepted; M1c package preflight complete, runtime discovery pending |
| `TA-08` | T1 metamorphism + M1a typed-route metamorphism accepted; **M1c six field-transition algebra/identity counterexamples compiled, runtime pending** |
| `TA-09` | coherent resource/work gate pending |
| `TA-10` | T2 semantic fixture manifest pending |
| `TA-11` | topology/lineage/disposition adequate; quality expansion later |
| `TA-12` | `tests/TESTING_STRATEGY.md` normative only |

## Authoritative next step

`.agents/Directional/Architecture_M1c_Field_Transition_Consumer_Artifact_Only_Test_Benchmark_Plan.md`.

The next turn is **immutable Test + Benchmark only**. It consumes exactly artifacts `9043971772 / 9043971968`, rebuilds/edits nothing, proves the six M1c semantic contracts and explicit transition counterexamples, and independently preserves M1b/M1a/T1/direct product authority. If any required-green gate regresses, remain at M1c and return to a corrective Code + Build turn rather than advancing.
