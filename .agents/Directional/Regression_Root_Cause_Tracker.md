# Surface-Cell Regression Root-Cause Tracker

Permanent stable-ID regression, repeated-pattern, architecture, and test-authority index for PR #8. Detailed point-in-time event evidence remains in `.agents/Directional/PR_8_Regression_Audit_Inventory.md`; dated turn reports retain runtime/artifact detail.

Last updated: **2026-08-09 UTC** after accepted T1 direct-oracle artifact `9041289209`.

## Rules

- Assign a stable regression ID only when previously accepted behavior/test/package/public authority is lost.
- Persistence or worsening while a gate remains red updates the existing event; it is not a recurrence.
- A recurrence requires restoration followed by later loss.
- Record the earliest evidenced cause, not only the terminal symptom.
- Compile success never resolves a runtime regression.
- Known-red/deferred product cases remain explicit and are never relabeled green or expected failure to close architecture/test work.
- A focused/helper pass cannot close representative product intent.
- Before every turn review `RP-01` through `RP-09`; every touched pattern needs an exact invariant and counterfactual/representative gate.

## Status vocabulary

| Status | Meaning |
|---|---|
| `active` | Reproduces in current runtime authority. |
| `fix_in_progress` | Authorized Code + Build is implementing correction. |
| `fix_pending_runtime` | Correction compiles; immutable runtime pending. |
| `resolved` | Later immutable artifact restores affected product authority. |
| `test_authority_resolved` | Test/oracle defect is corrected and accepted by immutable evidence. |

## PR-wide audit authority

Historical totals remain:

- **34 distinct regression events**;
- **14 architectural categories**;
- **20 recurrences**;
- **114 regression-bearing result-document commits**.

T1 artifacts `9040549377` and `9041289209` are test-architecture work and create no production regression event or recurrence. `G4-R007` remains active.

### Category rollup

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
bad:
  id: int
  if transition: id = full_ef_row
  else: id = compact_transition_index
  consume_without_domain(id)

good:
  distinct strong domains
  named checked conversion -> expected<T, DomainError>
  semantic topology + optional transition represented together
```

Guard: numeric coincidence is never conversion. M1a is the first architectural correction targeting this pattern directly.

### RP-02 — proxy/incomplete test authority

```text
bad:
  helper = convenient_helper()
  assert counts/raw IDs/success
  claim product proof

good:
  prove precondition
  invoke public entry or exact stage
  independently recompute observable contract
  mutate semantic fact and require rejection
  record executable/test/fixture/artifact identity
```

T1 status: **direct-integration test authority resolved** by artifact `9041289209`.

Accepted T1 evidence:

- oracle discovery **29/29** exact names;
- mutation/metamorphic suite **29/29**;
- four required-green direct cases pass and reach the oracle;
- BunnyRandom returns known-red `NotProductionReady:completion` and now reaches the independent oracle **before** the unchanged fatal product-success assertion;
- Vase remains a bounded nonreturning known-red case; no synthetic oracle result is created.

The accepted T1 report is `.agents/Directional/T1_Direct_Oracle_Execution_Order_Artifact_Only_Test_Benchmark_Report.md`.

### RP-03 — policy/stage state conflation

```text
bad: one flag/result means execution need + caller retention + stage result
good: execution lifetime, caller retention, policy, and typed stage outcome are separate
```

No T1 production state changed. M2 owns the architecture migration.

### RP-04 — nonterminating cumulative work

```text
bad:
  recurse(local_depth):
    for candidate in local_limit: recurse(local_depth-1)

good:
  shared WorkLedger { remaining_global_work, visited_state, attempted_actions }
```

T1 bounded producer completed 163 selected tests in 37.81 s. Vase's 60 s guard is safety evidence only and does not prove a work bound. M3/M5/T6 own formal work/resource closure.

### RP-05 — representation-dependent identity

```text
bad: identity/order depends on row, traversal, allocation, orientation, hash
good: semantic value is canonical; representation handles are separate; orientation explicit
```

T1 row/cycle/reversal oracle metamorphism passes. M1a introduces canonical semantic authority types.

### RP-06 — state-cardinality growth

```text
bad: copy global authority membership into every consumer
good: shared registry + consumer semantic key + bounded local witness
```

No T1 production storage change. M2/M4 own migration.

### RP-07 — cyclic topology linearization

```text
bad: cyclic relation validated as linear sequence/order

good:
  prev=(i-1+n)%n
  next=(i+1)%n
  explicit cyclic algebra and orientation
```

T1 cyclic/reversal oracle contracts pass. M1a introduces exact `Z4`/route reversal algebra.

### RP-08 — producer-disposition conflation

```text
bad: if !succeeded -> generic substitute
good: NotApplicable | Produced<T> | Rejected<E>, with Rejected terminal for owned domain
```

No T1 production behavior changed. M2 owns migration.

### RP-09 — local consumption of global authority

```text
bad:
  for face: require every global relation to be consumed locally

good:
  validate global registry once
  for face: consume only unique locally witnessed certificate path
```

Current production implementation passes focused chart/reachability contracts but direct torus remains red. M4 owns certificate migration.

## Mandatory per-turn pattern record

| Pattern | Touched? | Exact producer/consumer boundary | Corrective invariant | Counterfactual / representative gate |
|---|---|---|---|---|
| `RP-01` … `RP-09` | yes/no | symbol/target/artifact | concrete invariant | named negative + representative evidence |

A touched row that cannot be completed is a stop condition.

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

`G4-R007`: hard-rail face-chart authority over-rejects direct torus; the initial remediation consumed complete relation authority locally. Artifact `9031804178` passes focused 18/18 yet direct torus remains 0/3 with 241 `LocalSheetMismatch` issues after 192 quads, complete lineage, `4/8/4`, `1/0/0`. Do not infer a new root cause from mismatch count alone.

## Persistent blockers

| ID | Blocker | Required gate |
|---|---|---|
| `G4-B001` | Direct torus final `LocalSheetMismatch`. | strict-valid torus 3/3 |
| `G4-B002` | Exact Phase10 torus `InvalidHardRailPairing`. | shared source-authoritative rail schedule; M3 |
| `G4-B003` | Nonzero periodic `Z4` rotation. | deferred G4 capability; M1/M4 foundation |
| `G4-B004` | Positive multi-isolation quotient witness. | focused + representative certificate evidence |

## Architecture enforcement register

These are structural debts, not runtime regression events.

| ID | Severity | Patterns | Close condition / current state |
|---|---|---|---|
| `AR-01` | Critical | `RP-03`, `RP-08` | closed `ProducerOutcome<T>`; M2 |
| `AR-02` | Critical | `RP-01`, `RP-03`, `RP-06`, `RP-07` | strong IDs + one canonical typed route; **M1a begins this** |
| `AR-03` | High | `RP-01`, `RP-03`, `RP-05` | domain-specific semantic keys; **M1a begins this** |
| `AR-04` | High | `RP-06`, `RP-09` | one chart type + immutable single-writer snapshots; chart domain begins M1a, snapshots M2 |
| `AR-05` | High | `RP-05`, `RP-07` | semantic identity separated from representation; **M1a begins this** |
| `AR-06` | Critical | `RP-01`, `RP-05`, `RP-09` | producer-owned relation registry + certificate paths; M4 |
| `AR-07` | Critical | `RP-06`, `RP-09` | global conformity before local construction; M3 |
| `AR-08` | High | `RP-03`, `RP-06`, `RP-09` | producer-scoped immutable output; M2/M3 |
| `AR-09` | High | `RP-01`, `RP-05`, `RP-06` | one tagged exact source-support kernel; **representation begins M1a, production rebinding M5** |
| `AR-10` | Moderate | all | incremental responsibility modules |
| `AR-11` | High | `RP-02`, `RP-03` | normative architecture separate from status/evidence |
| `AR-12` | High | `RP-02` | independent oracle/package foundation accepted in T1; representative/quality expansion continues T2–T6 |

## Test architecture enforcement register

| ID | Severity | Current state / close condition |
|---|---|---|
| `TA-01` | Critical | T1 topology/lineage/disposition oracle accepted; geometry/field/feature/quality remains T5 |
| `TA-02` | Critical | T2: all ten direct cases semantically classified and packaged |
| `TA-03` | Critical | independent metric decisions + approved baselines/thresholds |
| `TA-04` | High | T3 generator/shrinker + T4 sanitizer fuzz/replay |
| `TA-05` | High | **test-authority resolved by artifact `9041289209`**: every returned direct result reaches independent oracle before fatal success assertion |
| `TA-06` | High | T1 domain-independent mutation tests 29/29; retain through M migrations |
| `TA-07` | High | T1 package/discovery exact 29/29; retain through T6 |
| `TA-08` | High | T1 canonical row/cycle/reversal metamorphism accepted |
| `TA-09` | High | coherent reset/work/time/RSS gate remains required |
| `TA-10` | High | T2 semantic fixture manifest |
| `TA-11` | High | T1 topology/lineage/disposition mutation adequate; T5 completes geometry/field/quality |
| `TA-12` | Moderate | `tests/TESTING_STRATEGY.md` remains normative-only |

## Next architecture slice

Authoritative next turn:
`.agents/Directional/Architecture_M1a_Authority_Kernel_Core_Code_Build_Plan.md`.

M1a touched-pattern focus:

- `RP-01`: strong non-interconvertible domains and named checked conversions;
- `RP-05`: semantic identity independent of representation handles;
- `RP-07`: exact quarter-turn/route reversal/cycle algebra;
- `RP-02`: preserve accepted T1 oracle/package authority; do not substitute compile success for semantic proof.

M1a is Code + Build only and has no intended production behavior delta. Its following immutable Test + Benchmark must accept the new authority kernel before any M1b production consumer migration.
