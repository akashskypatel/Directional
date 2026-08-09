# Surface-Cell Regression Root-Cause Tracker

Permanent stable-ID regression, repeated-pattern, architecture, and test-authority index for PR #8. Detailed point-in-time event evidence remains in `.agents/Directional/PR_8_Regression_Audit_Inventory.md`; dated turn reports retain artifact/runtime detail.

Last updated: **2026-08-09 UTC** after accepted M1a immutable artifact `9041930767`.

## Rules

- Assign a stable regression ID only when previously accepted behavior/test/package/public authority is lost.
- Persistence or worsening while a gate remains red updates the existing event; it is not a recurrence.
- A recurrence requires restoration followed by later loss.
- Compile success never resolves runtime or architecture migration work.
- New architecture is pending until immutable semantic acceptance.
- Known-red/deferred product cases remain explicit and are never relabeled green or expected failure.
- A focused/helper pass cannot close representative product intent.
- Before every turn review `RP-01` through `RP-09`; every touched pattern requires an exact invariant and counterexample/representative gate.

## Historical PR-wide authority

- **34 distinct regression events**;
- **14 architectural categories**;
- **20 recurrences**;
- **114 regression-bearing result-document commits**.

T1 artifacts `9040549377` / `9041289209` and M1a artifact `9041930767` create no production regression event or recurrence. `PR8-R034 / G4-R007` remains active.

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
bad: bare integer reused across semantic domains

good:
  distinct strong domain types
  named checked legacy conversion -> typed DomainError
  numeric coincidence is never conversion
```

**M1a kernel accepted.** Artifact `9041930767` proves exact 14-name discovery and **14/14** semantic contracts. Static non-convertibility, negative/out-of-range rejection, numeric coincidence, and deliberate cross-domain misuse all pass. This closes the M1a kernel prerequisite, not production adoption of all IDs.

**M1b next boundary:** source-face/source-vertex identity inside `surface_optimization_rail_detail::provenance_supports_interval_sheet`. After legacy sentinel/extent validation, raw face/vertex values must cross named adapters once and remain typed until explicit row indexing.

### RP-02 — proxy/incomplete test authority

```text
bad: helper/count/status/raw ID claimed as product proof

good:
  prove precondition
  execute exact stage/public entry
  independently recompute observable contract
  mutate semantic fact and require rejection
```

`RP-02 / TA-05` direct integration remains **test-authority resolved** by T1 artifact `9041289209`.

M1a preservation is accepted:

- T1 oracle discovery exact **29**;
- oracle contracts **29/29**;
- Plane/MultiFaceSeam/CloseSheets/Cylinder green and oracle-clean;
- BunnyRandom remains known-red and reaches independent oracle before fatal product-success assertion;
- Vase remains bounded/nonreturning with safety-only interpretation;
- all eight pre-existing T1 binaries/libraries are byte-identical in M1a.

### RP-03 — policy/stage state conflation

```text
bad: one flag/result means execution need + retention + stage result
good: execution lifetime, caller retention, policy, and typed stage outcome are separate
```

Untouched by M1a/M1b. M2 owns migration.

### RP-04 — nonterminating cumulative work

```text
bad: nested local limits without global monotone bound
good: shared WorkLedger + finite global budget + monotone measure
```

Untouched by M1a/M1b. Vase's 60-second guard remains safety evidence only. M3/M5/T6 own formal work/resource closure.

### RP-05 — representation-dependent identity

```text
bad: identity/order depends on row, traversal, allocation, orientation, or hash
good: semantic value is canonical; representation handles are separate; orientation explicit
```

**M1a kernel accepted.** Source-edge endpoint reversal, canonical route reversal, and representation-handle perturbation contracts pass. M1b must not introduce hashes/rows as semantic identity; its explicit source-row conversion is a legacy representation boundary only.

### RP-06 — state-cardinality growth

```text
bad: copy global authority membership into every consumer
good: shared registry + semantic key + bounded local witness
```

Untouched by M1a/M1b. M2/M4 own migration.

### RP-07 — cyclic topology linearization

```text
bad: cyclic/periodic relation represented as linear special case
good: explicit modulo/cyclic algebra + reversible orientation + exact composition
```

**M1a kernel accepted.** Exact quarter-turn normalization/four-turn closure, grid automorphism identity/inverse/associativity, nonzero rotation+translation round trip, and route reversal pass **14/14**. Production Z4 capability remains deferred behind later consumers/M4.

### RP-08 — producer-disposition conflation

```text
bad: failure -> generic substitute
good: NotApplicable | Produced<T> | Rejected<E>, with Rejected terminal
```

Untouched. M2 owns migration.

### RP-09 — local consumption of global authority

```text
bad: local face/consumer required to consume complete global relation authority
good: global registry validated once; local consumer uses only certified local path
```

Untouched by M1a/M1b. `G4-R007` remains active; M4 owns certificate migration.

## M1a immutable pattern record

| Pattern | Result | Accepted evidence |
|---|---|---|
| `RP-01` | **kernel accepted** | exact 14 discovery, negative/domain counterexamples, static non-convertibility |
| `RP-02` | **preserved** | exact 29 discovery, 29/29, direct comparison authority |
| `RP-05` | **kernel accepted** | source-edge reversal, route reversal, representation-handle metamorphism |
| `RP-07` | **kernel accepted** | exact Z4/automorphism/reversal algebra |
| `RP-03/04/06/08/09` | untouched | byte-identical pre-existing artifacts/direct semantics |

M1a report: `.agents/Directional/Architecture_M1a_Authority_Kernel_Core_Artifact_Only_Test_Benchmark_Report.md`.

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

`G4-R007` authority remains production artifact `9031804178`: direct torus 0/3 with 241 `LocalSheetMismatch` issues after 192 completed quads, complete lineage, `4/8/4`, `1/0/0`. Do not infer a new root cause from M1 migration work.

## Persistent blockers

| ID | Blocker | Required gate |
|---|---|---|
| `G4-B001` | Direct torus final `LocalSheetMismatch`. | strict-valid torus 3/3 |
| `G4-B002` | Exact Phase10 torus `InvalidHardRailPairing`. | shared source-authoritative rail schedule; M3 |
| `G4-B003` | Nonzero periodic Z4 production capability. | M1/M4 foundation then product acceptance |
| `G4-B004` | Positive multi-isolation quotient witness. | focused + representative certificate evidence |

## Architecture enforcement register

| ID | Severity | Current state |
|---|---|---|
| `AR-01` | Critical | M2: closed producer outcomes |
| `AR-02` | Critical | **M1a strong-ID/route kernel accepted; production consumer adoption begins M1b** |
| `AR-03` | High | **M1a domain-specific key core accepted; production adoption incremental** |
| `AR-04` | High | `FieldChartId` domain exists; one-chart production migration and immutable snapshots remain |
| `AR-05` | High | **M1a semantic identity/orientation core accepted; production adoption incremental** |
| `AR-06` | Critical | M4: producer-owned relation registry/certificates |
| `AR-07` | Critical | M3: global conformity before local construction |
| `AR-08` | High | M2/M3: producer-scoped immutable output |
| `AR-09` | High | tagged source-support representation exists; exact production rebinding remains M5 |
| `AR-10` | Moderate | incremental responsibility modules |
| `AR-11` | High | normative architecture/status separation maintained |
| `AR-12` | High | T1 independent oracle/package accepted; T2–T6 expand representative/quality authority |

## Test architecture enforcement register

| ID | Current state |
|---|---|
| `TA-01` | T1 topology/lineage/disposition accepted; geometry/field/feature/quality later |
| `TA-02` | T2 complete ten-case direct semantic matrix |
| `TA-03` | metric definitions/baselines pending |
| `TA-04` | T3/T4 generation, shrinking, sanitizer fuzz/replay pending |
| `TA-05` | **test-authority resolved by `9041289209`, preserved by M1a** |
| `TA-06` | T1 mutation suite 29/29 preserved |
| `TA-07` | exact discovery/package authority preserved |
| `TA-08` | T1 metamorphism accepted; M1a typed route metamorphism accepted |
| `TA-09` | coherent resource/work gate pending |
| `TA-10` | T2 semantic fixture manifest pending |
| `TA-11` | topology/lineage/disposition adequate; quality expansion later |
| `TA-12` | `tests/TESTING_STRATEGY.md` remains normative-only |

## Authoritative next step

`.agents/Directional/Architecture_M1b_First_Production_Consumer_Code_Build_Plan.md`.

M1b is **Code + Build only** and migrates exactly the source-face/source-vertex identity seam inside `provenance_supports_interval_sheet`. It must preserve all legacy sentinel, support-classification, rail-assignment, optimizer, product, and T1 behavior. Its following immutable turn must prove focused consumer semantics plus M1a **14/14**, T1 **29/29**, direct four-green preservation, and explicit Bunny/Vase visibility before another consumer may migrate.
