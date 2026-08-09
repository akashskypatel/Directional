# Surface-Cell Regression Root-Cause Tracker

Permanent stable-ID regression, repeated-pattern, architecture, and test-authority index for PR #8. Detailed event evidence remains in `.agents/Directional/PR_8_Regression_Audit_Inventory.md`; dated turn reports retain artifact/runtime detail.

Last updated: **2026-08-09 UTC** after M1b first-consumer Code + Build artifact `9042940168`.

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

T1 artifacts `9040549377 / 9041289209`, accepted M1a artifact `9041930767`, and M1b compile artifact `9042940168` add no production regression event or recurrence. `PR8-R034 / G4-R007` remains active.

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

**M1b first production adoption:** **compile-complete / runtime pending** at:
`provenance_supports_interval_sheet`.

Invariant:

- legacy source-face validation occurs before `source_face` adapter conversion;
- source vertices from source-face topology reject negative values before `source_vertex` conversion;
- `source_face_contains_vertex` accepts `SourceFaceId` and `SourceVertexId`, so numeric coincidence/domain swap cannot compile;
- typed IDs return to legacy integers only at explicit matrix/vector access.

Counterexamples packaged: invalid faces, wrong source-face incidence, compile-time domain swap rejection. Runtime gate: focused 6/6 plus full validation 77/77.

### RP-02 — proxy/incomplete test authority

```text
bad: compile/helper/status/count claimed as product proof.
good: named semantic contract + independent oracle + direct representative evidence.
```

`RP-02 / TA-05` remains **test-authority resolved** by T1 artifact `9041289209`. M1a preserved 29/29 and direct oracle integration.

M1b compile does **not** re-accept that boundary. The next immutable artifact turn must require:

- M1b focused 6/6;
- validation 77/77;
- M1a 14/14;
- T1 oracle 29/29;
- four required-green direct cases oracle-clean;
- Bunny/Vase explicit known-red evidence.

### RP-03 — policy/stage state conflation

Untouched by M1b. M2 owns closed producer-outcome migration.

### RP-04 — nonterminating cumulative work

Untouched by M1b. No search/retry/work loop was introduced. Vase timeout remains safety-only evidence.

### RP-05 — representation-dependent identity

```text
bad: row/hash/traversal/allocation position becomes semantic identity.
good: semantic strong ID is authoritative; row index is explicit representation access only.
```

**M1a kernel:** accepted.

**M1b first production adoption:** **compile-complete / runtime pending**. Source-face/source-vertex rows are converted into semantic IDs and remain typed through incidence comparison. `to_legacy_index` is used only at existing representation accesses. No row/hash becomes semantic ownership.

### RP-06 — state-cardinality growth

Untouched by M1b. M2/M4 own shared authority storage.

### RP-07 — cyclic topology linearization

M1a exact Z4/automorphism/reversal kernel is accepted. M1b does not migrate cyclic/periodic topology.

### RP-08 — producer-disposition conflation

Untouched by M1b. M2 owns migration.

### RP-09 — local consumption of global authority

Untouched by M1b. `G4-R007` remains active; M4 owns certificate/global-local consumption migration.

## M1b mandatory pattern record

| Pattern | Touched? | Exact boundary | Corrective invariant | Following immutable gate |
|---|---|---|---|---|
| `RP-01` | **yes** | rail source-face/source-vertex identity | named conversion once; strong domains cannot swap | focused 6/6 + validation 77/77 |
| `RP-02` | preservation | M1b focused target vs M1a/T1/direct authority | compile/focused helper cannot replace independent product oracle | exact 14/29 discovery + 14/14 + 29/29 + direct cases |
| `RP-03` | no | — | producer state unchanged | source scope + direct comparison |
| `RP-04` | no | — | no search/work loop introduced | source scope |
| `RP-05` | **yes** | typed IDs versus Eigen/vector row access | representation index appears only after semantic identity | focused incidence counterexamples + direct preservation |
| `RP-06` | no | — | storage/cardinality unchanged | source scope |
| `RP-07` | no | — | periodic algebra unchanged | M1a 14/14 preservation |
| `RP-08` | no | — | disposition unchanged | direct comparison |
| `RP-09` | no | — | global/local relation policy unchanged | G4-R007 remains separate |

## M1b compile-attempt lesson

The first committed migration (`f768c2f...`) failed compile at `[49/120]` because a reopened `surface_optimization_rail_detail` namespace lacked its close. Corrective commit `0340addf...` inserted only that missing namespace close; authoritative run `31330737703` then compiled **120/120**.

This failure occurred before M1b runtime acceptance and did not lose accepted product authority, so it is **not** a new regression event. It is retained as an implementation-process lesson: connector-side source transformations that replace namespace-scoped blocks must statically verify both opening and closing ownership boundaries before expensive compile execution.

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

`G4-R007` production authority remains artifact `9031804178`: direct torus 0/3 with 241 `LocalSheetMismatch` issues after 192 quads, complete lineage, `4/8/4`, `1/0/0`. M1b does not repair or reinterpret this event.

## Persistent blockers

| ID | Blocker | Required gate |
|---|---|---|
| `G4-B001` | Direct torus final `LocalSheetMismatch`. | strict-valid torus 3/3 |
| `G4-B002` | Exact Phase10 torus `InvalidHardRailPairing`. | shared source-authoritative rail schedule; M3 |
| `G4-B003` | Nonzero periodic Z4 production capability. | later M1/M4 adoption + product acceptance |
| `G4-B004` | Positive multi-isolation quotient witness. | focused + representative certificate evidence |

## Architecture enforcement register

| ID | State |
|---|---|
| `AR-01` | M2: closed producer outcomes |
| `AR-02` | M1a strong-ID/route kernel accepted; **first production consumer compile-complete, runtime pending** |
| `AR-03` | M1a domain-key core accepted; **first source-face/source-vertex adoption runtime pending** |
| `AR-04` | FieldChartId exists; production chart/snapshot migration remains |
| `AR-05` | M1a identity/orientation core accepted; **first typed representation boundary runtime pending** |
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
| `TA-05` | **test-authority resolved by `9041289209`; M1b preservation runtime pending** |
| `TA-06` | T1 mutation suite 29/29 accepted; M1b must preserve |
| `TA-07` | exact package/discovery accepted; M1b manifests statically retained |
| `TA-08` | T1 metamorphism + M1a typed-route metamorphism accepted |
| `TA-09` | coherent resource/work gate pending |
| `TA-10` | T2 semantic fixture manifest pending |
| `TA-11` | topology/lineage/disposition adequate; quality expansion later |
| `TA-12` | `tests/TESTING_STRATEGY.md` normative only |

## Authoritative next step

`.agents/Directional/Architecture_M1b_First_Production_Consumer_Artifact_Only_Test_Benchmark_Plan.md`.

Consume artifacts `9042940168 / 9042940336` only. Require exact package authority, focused **6/6**, validation **77/77**, M1a **14/14**, T1 **29/29**, direct four-green preservation, and explicit Bunny/Vase visibility. No source repair is allowed in that Test + Benchmark turn.
