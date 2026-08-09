# Surface-Cell Regression Root-Cause Tracker

This is the permanent stable-ID regression, repeated-pattern, architecture, and
test-authority index for the production surface-cell implementation. Detailed
point-in-time event evidence remains in
`.agents/Directional/PR_8_Regression_Audit_Inventory.md`; turn reports retain
artifact/runtime detail.

Last updated: **2026-08-09 UTC** after T1 immutable artifact `9040549377`.

## Rules

- Assign a stable ID only when accepted behavior/test/package/public authority
  is lost relative to an exact accepted baseline.
- Persistence or worsening while the same gate is still red updates the
  existing event; it is not a new recurrence.
- A recurrence requires restoration followed by a later loss.
- Record the earliest evidenced cause, not only the terminal symptom.
- Compile success never resolves a runtime regression.
- Known-red/deferred product cases stay explicit and are not relabeled green or
  expected failure merely to close a test-architecture phase.
- Before every turn review `RP-01` through `RP-09` and record exact touched
  boundaries, corrective invariants, and representative/counterfactual
  evidence.
- A focused/helper pass cannot close representative product intent.

## Status vocabulary

| Status | Meaning |
|---|---|
| `active` | Reproduces in current runtime authority. |
| `fix_in_progress` | Authorized Code + Build is implementing correction. |
| `fix_pending_runtime` | Correction compiles; immutable runtime pending. |
| `resolved` | Later immutable artifact passes affected gate. |
| `test_authority_resolved` | Test/oracle defect corrected and accepted by immutable evidence. |

## PR-wide audit authority

Historical evidence range:
`d8b4dba98747d3adf0ca24002642bcad9e9847db..027e5194a9013cc1fe9ea18c1b79741301e40f74`
(**1,789 commits**). Repeated-pattern expansion was published from
`8ef353034641c3a068095334ceea5e6ddb0c39c1`.

Historical totals remain:

- **34 distinct regression events**;
- **14 architectural categories**;
- **20 recurrences**;
- **114 regression-bearing result-document commits**.

Neither artifact `9031804178` nor T1 artifact `9040549377` creates a new event
or recurrence. `G4-R007` remains active. T1 is new, not-yet-accepted test
architecture, so its direct-oracle execution-order defect is incomplete
`RP-02 / TA-05` work rather than loss of previously accepted test authority.

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

The singleton categories are `INTRINSIC_SUPPORT_OVERCONSTRAINT`,
`INCOMPLETE_TRANSACTIONAL_ROLLBACK`, `SHARED_EDGE_ORIENTATION_INVERSION`,
`INCOMPLETE_ORBIT_PUBLICATION`, and `EXACT_SIMPLEX_CANONICALIZATION_LOSS`.

## Repeated coding-pattern catalog

| Pattern | Repeated code shape | Events | Recurrences |
|---|---|---:|---:|
| `RP-01` | Distinct authority domains guessed/intersected through one scalar/equality predicate. | 6 | 5 |
| `RP-02` | Proxy/incomplete test or package authority is promoted to semantic proof. | 6 | 5 |
| `RP-03` | One flag/result carries independent policy/stage meanings. | 4 | 3 |
| `RP-04` | Local bounds wrap recursive/nested/process-cumulative work without one global ledger. | 3 | 2 |
| `RP-05` | Identity/order/hash depends on traversal/allocation/orientation/emission role. | 2 | 1 |
| `RP-06` | Shared authority membership copied into every consumer. | 2 | 1 |
| `RP-07` | Cyclic topology validated as a linear sequence/value relation. | 2 | 1 |
| `RP-08` | Typed producer disposition reduced to boolean/lossy aggregate. | 2 | 1 |
| `RP-09` | Complete global authority required to be consumed on every local face/path. | 2 | 1 |

### RP-01 — authority-domain conflation

Anti-pattern:

```text
authority_id: int
if cross_field_transition_exists:
    authority_id = full_ef_row
else:
    authority_id = compact_transition_index
consume_without_named_domain(authority_id)
```

Required shape:

```text
RouteAuthority {
  CanonicalEdgeKey topology;
  Optional<SourceWideTransitionIndex> compact;
  Optional<FullEfRow> cross_field;
}
validate each field only in its declared domain
```

Guard: named types, producer/consumer scope, serialization meaning, and
row/order counterfactuals. T1 test-side `DomainIndex<...>` mutation contracts
now pass from artifact `9040549377`.

### RP-02 — proxy/incomplete test authority

Anti-pattern:

```text
helper = call_convenient_helper()
assert counts_or_raw_ids(helper)
# claimed public/stage path may not be entered
# precondition or independent oracle may be absent
# package/discovery authority may be absent
```

Required shape:

```text
prove fixture precondition
invoke public entry or exact declared stage
observe typed result
independently recompute observable contract
mutate one semantic fact and require independent rejection
record executable/test/fixture/seed/artifact identity
```

Guard: production `result.success`, production validator, counts, raw IDs/order,
hashes, retention lifetime, compilation, and no-crash are not independent
product proof.

Current T1 evidence from artifact `9040549377`:

- default oracle package/discovery is exact **29/29**;
- all **29/29** positive/mutation/metamorphic contracts pass individually;
- four required-green direct cases pass and reach the oracle;
- BunnyRandom returns a known-red result but `ASSERT_TRUE(result.success)`
  executes before the oracle and fatally short-circuits independent evidence;
- Vase does not return inside the bounded validation guard.

Therefore the **oracle core is accepted but T1 direct integration remains
incomplete**. The authoritative next Code + Build is statement-order-only under
`.agents/Directional/Test_Architecture_T1_Direct_Oracle_Execution_Order_Code_Build_Plan.md`.

### RP-03 — one state carries two meanings

Anti-pattern:

```text
retain = caller_requested || execution_needs_state
real_failure overwrites requested policy result
```

Required shape:

```text
retain_for_execution != retain_for_caller
real_stage_outcome != test_policy_outcome
```

T1 disposition corruption tests for backend/fallback/recovery/origin/terminal
state all pass and remain test-only observations.

### RP-04 — local bounds around multiplicative work

Anti-pattern:

```text
solve(state, local_depth):
  for candidate in local_limit:
    solve(copy(state), local_depth - 1)
```

Required shape:

```text
shared WorkController {
  remaining_global_work;
  visited_canonical_states;
  attempted_actions;
}
```

Current bounded producer authority under T1 artifact completes selected
163-test filter in **36.993 s**, result **154/163**. This does not alter the
historical `R020` uncertainty or prove Bunny/Vase work bounds.

### RP-05 — representation-dependent identity

Anti-pattern:

```text
identity = hash(traversal_or_exterior_role, record)
sort primarily by derived hash
```

Required shape:

```text
canonical semantic record = quotient by row/order/orientation/allocation role
sort semantic topology first; hash only derived evidence
```

T1 canonical product-record row/cycle/reversal metamorphic test passes.

### RP-06 — duplicated shared authority membership

Anti-pattern:

```text
for consumer: consumer.members = copy(global_members)
```

Required shape:

```text
registry[key] = shared membership once
consumer.key = key
consumer.local_witness = bounded local data
```

No production storage changes occurred in T1.

### RP-07 — cyclic topology linearization

Anti-pattern:

```text
previous/next duplicate value => contradiction
position <= 0 => reject wrap
```

Required shape:

```text
previous = (i - 1 + n) mod n
next = (i + 1) mod n
compare sector positions and support wrap explicitly
```

T1 cyclic/reversed duplicate-face, broken-boundary, and canonical reversal
contracts pass.

### RP-08 — producer-disposition conflation

Anti-pattern:

```text
if !producer.succeeded: run_generic_substitute()
```

Required shape:

```text
switch disposition:
  Produced -> consume
  Rejected -> fail closed
  NotApplicable -> substitute only if domain unclaimed
```

No producer/fallback behavior changed in T1.

### RP-09 — global authority consumed locally

Anti-pattern:

```text
for face:
  require every global relation to occur/consume on this face
```

Required shape:

```text
validate complete authority globally once
for face:
  select unique locally witnessed path from exact global graph
```

Implementation `6af23d9` passes **11/11** chart-reachability/face-chart focused
cases but direct torus remains **0/3** with 241 `LocalSheetMismatch` issues.
`G4-R007` stays active. T1 does not change this production path.

## Mandatory per-turn pattern record

| Pattern | Touched? | Exact affected producer/consumer | Evidence anti-pattern absent / corrective invariant | Counterfactual and representative gate |
|---|---|---|---|---|
| `RP-01` … `RP-09` | yes/no | exact symbol/target/artifact boundary | concrete invariant | named negative + representative evidence |

A touched row that cannot be completed is a stop condition.

## Current G4 stable-ID mapping

| PR-wide event | Stable G4 entry | Category | Pattern |
|---|---|---|---|
| `PR8-R028` | `G4-R001` | `AUTHORITY_DOMAIN_CONFLATION` | `RP-01` |
| `PR8-R029` | `G4-R002` | `LOCAL_CONSUMPTION_OF_GLOBAL_AUTHORITY` | `RP-09` |
| `PR8-R030` | `G4-R003` | `TEST_AUTHORITY_COVERAGE_GAP` | `RP-02` |
| `PR8-R031` | `G4-R004` | `AUTHORITY_DOMAIN_CONFLATION` | `RP-01` |
| `PR8-R032` | `G4-R005` | `POLICY_STAGE_STATE_CONFLATION` | `RP-03` |
| `PR8-R033` | `G4-R006` | `AUTHORITY_DOMAIN_CONFLATION` | `RP-01` |
| `PR8-R034` | `G4-R007` | `LOCAL_CONSUMPTION_OF_GLOBAL_AUTHORITY` | `RP-09` |

## Regression entries

| ID | Classification / cause | Current status |
|---|---|---|
| `G4-R001` | Genuine source boundaries rejected by compact-index conflation. | `resolved` by artifact `9026181778`. |
| `G4-R002` | Internal isolation seams required as local cell-boundary crossings. | `resolved`; later torus consumes `4/8/4`. |
| `G4-R003` | Required quotient contracts absent from immutable default artifact. | `resolved` by artifact `9026181778`. |
| `G4-R004` | Full-`EF` and compact transition domains serialized as one `int`. | `resolved` by artifact `9028103772`. |
| `G4-R005` | Execution retention leaked into caller-visible retention policy. | `resolved` by artifact `9028103772`. |
| `G4-R006` | Canonical transition tests repeated obsolete numeric-domain authority. | `test_authority_resolved` by artifact `9029584083`. |
| `G4-R007` | Hard-rail face-chart authority over-rejects direct torus; initial resolver consumed complete relation authority locally. | **`active`**. Artifact `9031804178` passes focused 18/18 but torus remains 0/3 with 241 mismatches after 192 quads, complete lineage, `4/8/4`, `1/0/0`. |

Detailed evidence for each remains in the dated reports and PR #8 audit
inventory. Do not infer a new G4-R007 root cause from mismatch count alone.

## Persistent blockers that are not new current-patch regressions

| ID | Blocker | Current gate |
|---|---|---|
| `G4-B001` | Direct torus final `LocalSheetMismatch`. | Same representative gate as active `G4-R007`; strict-valid torus `3/3` required. |
| `G4-B002` | Exact Phase10 torus `InvalidHardRailPairing`. | Shared source-authoritative hard-rail breakpoint scheduling; gates sphere. |
| `G4-B003` | Nonzero periodic `Z4` rotation. | Deferred G4 capability. |
| `G4-B004` | Positive multi-isolation quotient witness. | Deferred focused fixture/implementation evidence. |

## Architecture enforcement register — independent review 2026-08-09

These are structural debts, not additional runtime regression events.

| ID | Severity | Pattern | Required close condition |
|---|---|---|---|
| `AR-01` | Critical | `RP-03`, `RP-08` | Closed `ProducerOutcome<T>` with exhaustive dispatch. |
| `AR-02` | Critical | `RP-01`, `RP-03`, `RP-06`, `RP-07` | Strong ID domains and one canonical typed route. |
| `AR-03` | High | `RP-01`, `RP-03`, `RP-05` | Domain-specific semantic keys; no ordinal/row/backend identity leakage. |
| `AR-04` | High | `RP-06`, `RP-09` | One chart type and immutable single-writer authority snapshots. |
| `AR-05` | High | `RP-05`, `RP-07` | Semantic identity separated from representation; semantic order before hash. |
| `AR-06` | Critical | `RP-01`, `RP-05`, `RP-09` | Producer-owned relation registry + exact `ChartSelectionCertificate` paths. |
| `AR-07` | Critical | `RP-06`, `RP-09` | Global conformity/hard-rail schedule before local construction. |
| `AR-08` | High | `RP-03`, `RP-06`, `RP-09` | Producers emit fully scoped immutable output; aggregation verifies only. |
| `AR-09` | High | `RP-01`, `RP-05`, `RP-06` | One sanitized exact source-support kernel; tolerance cannot be topology identity. |
| `AR-10` | Moderate | all | Incremental responsibility modules; new behavior only through stage APIs. |
| `AR-11` | High | `RP-02`, `RP-03` | Normative architecture remains separate from status/evidence. |
| `AR-12` | High | `RP-02` | Independent product oracle + mutation adequacy + package authority + representative evidence. T1 oracle core now passes; direct integration remains incomplete. |

## Test architecture enforcement register — independent audit 2026-08-09

These are structural test debts and do not alter 34/14/20 historical counts.

| ID | Severity | Pattern | Current evidence / close condition |
|---|---|---|---|
| `TA-01` | Critical | `RP-02` | T1 now provides independent topology/lineage/disposition oracle core; direct integration ordering still blocks T1 closure. Full product intent remains T5. |
| `TA-02` | Critical | `RP-02`, `RP-07`, `RP-09` | T2 must package/discover all ten direct cases with explicit green/known-red state. |
| `TA-03` | Critical | `RP-01`, `RP-02` | Independent metric decisions + approved baselines/thresholds still required. |
| `TA-04` | High | `RP-01`, `RP-04`, `RP-06`, `RP-07`, `RP-09` | T3 generator/shrinker + T4 sanitizer fuzz/replay still required. |
| `TA-05` | High | `RP-02` | **Open T1 defect:** direct returned failures can be stopped by fatal production assertion before independent oracle. Next Code + Build corrects execution order without weakening product assertions. |
| `TA-06` | High | `RP-01`, `RP-02` | T1 domain-independent mutation tests pass; retain through corrected immutable artifact. |
| `TA-07` | High | `RP-02` | T1 package/discovery/labels exact 29/29; retain through corrected immutable artifact and T6. |
| `TA-08` | High | `RP-02`, `RP-05`, `RP-07` | T1 canonical row/cycle/reversal metamorphism passes; broader semantic proxies remain monitored. |
| `TA-09` | High | `RP-03`, `RP-04`, `RP-06` | Coherent reset/work/time/RSS gate still required; T1 60 s Vase guard is safety evidence only, not a budget contract. |
| `TA-10` | High | `RP-02`, `RP-07`, `RP-09` | T2 versioned semantic fixture manifest still required. |
| `TA-11` | High | `RP-02` | T1 topology/lineage/disposition mutation families pass 29/29; T5 must complete geometry/field/quality mutation adequacy. |
| `TA-12` | Moderate | `RP-02`, `RP-03` | `tests/TESTING_STRATEGY.md` remains normative-only. |

Full test audit:
`.agents/Directional/Surface_Cell_Test_Suite_Independent_Audit_And_Redesign_Plan.md`.

## Architectural review triggers

Request/reuse the accepted independent design proof when:

1. a cause family reaches two regressions;
2. a resolved regression reappears;
3. a fix moves a failure without restoring entering accepted authority;
4. focused tests pass while representative product intent remains red for an
   unrepresented state shape;
5. a new bare numeric field carries topology/index/ownership/semantic authority;
6. planned work touches an `RP-nn` path without a complete pattern row;
7. a mandatory direct test lacks proved precondition, independent oracle,
   rejected counterexample, or package identity;
8. focused/helper/property evidence is used to hide or close a known-red
   representative product case;
9. generated/fuzz failures cannot be replayed/minimized within declared bounds.

The independent architecture review and test-suite audit are complete. The
accepted staged response remains: finish T1 independent test authority, then
M1 production authority-kernel migration. Review policy is `never` for an
optional additional Review turn unless a future plan violates the accepted
design proof.
