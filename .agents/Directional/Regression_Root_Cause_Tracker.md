# Surface-Cell Regression Root-Cause Tracker

Permanent stable-ID regression, repeated-pattern, architecture, and test-authority index for PR #8. Detailed point-in-time evidence remains in `.agents/Directional/PR_8_Regression_Audit_Inventory.md`; dated turn reports retain artifact/runtime detail.

Last updated: **2026-08-09 UTC** after M1a Code + Build artifact `9041930767`.

## Rules

- Assign a stable regression ID only when previously accepted behavior/test/package/public authority is lost.
- Persistence or worsening while a gate remains red updates the existing event; it is not a recurrence.
- A recurrence requires restoration followed by later loss.
- Record the earliest evidenced cause, not only the terminal symptom.
- Compile success never resolves a runtime regression or architecture migration.
- New architecture that has never passed immutable acceptance is `pending`/failed migration work, not automatically a regression event.
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

T1 artifacts `9040549377` / `9041289209` and M1a artifact `9041930767` create no production regression event or recurrence. `G4-R007` remains active.

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
  named checked conversion -> typed DomainError
  semantic topology + optional transition represented together
```

Guard: numeric coincidence is never conversion.

**M1a state:** correction scaffolding is `fix_pending_runtime`. `SemanticId<Tag>` domains are non-interconvertible, raw construction is private, and `LegacyAuthorityAdapters` requires an explicit supplied domain and rejects mismatch/negative/out-of-range values. Immutable runtime must still prove the packaged counterexamples before M1b may consume these types.

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

T1 direct integration is **test-authority resolved** by artifact `9041289209`: exact 29-name discovery, 29/29 mutation/metamorphic contracts, four required-green direct products oracle-clean, Bunny returned known-red and was independently rejected before the unchanged fatal success assertion, Vase remained bounded/nonreturning without synthetic proof.

**M1a preservation evidence:** T1 oracle/direct source blobs and all eight pre-existing T1 binaries/libraries are byte-identical in artifact `9041930767`; the unchanged 29-name manifest remains packaged. The next immutable M1a turn must re-run this authority.

### RP-03 — policy/stage state conflation

```text
bad: one flag/result means execution need + caller retention + stage result
good: execution lifetime, caller retention, policy, and typed stage outcome are separate
```

Untouched by M1a. M2 owns migration.

### RP-04 — nonterminating cumulative work

```text
bad:
  recurse(local_depth):
    for candidate in local_limit: recurse(local_depth-1)

good:
  shared WorkLedger { remaining_global_work, visited_state, attempted_actions }
```

Untouched by M1a; M1a adds bounded value algebra only. Vase's 60 s guard remains safety evidence only. M3/M5/T6 own formal work/resource closure.

### RP-05 — representation-dependent identity

```text
bad: identity/order depends on row, traversal, allocation, orientation, hash
good: semantic value is canonical; representation handles are separate; orientation explicit
```

**M1a state:** `fix_pending_runtime`. New semantic IDs compare only domain values; `SourceEdgeTopologyKey` canonicalizes endpoint order; orientation is explicit; `CanonicalRoute` canonicalizes from semantic steps; a packaged metamorphic contract perturbs unrelated representation handles without changing route identity. Runtime acceptance pending.

### RP-06 — state-cardinality growth

```text
bad: copy global authority membership into every consumer
good: shared registry + consumer semantic key + bounded local witness
```

Untouched by M1a. M2/M4 own migration.

### RP-07 — cyclic topology linearization

```text
bad: cyclic relation validated as linear sequence/order

good:
  explicit modulo/cyclic algebra
  reversible orientation
  exact cycle composition
```

**M1a state:** `fix_pending_runtime`. `QuarterTurn` is exact modulo 4; `GridAutomorphism` supplies exact identity/composition/inverse; route reversal reverses ordered steps, transport, and orientation. Packaged tests cover four-turn closure, identity/inverse/associativity, nonzero rotation+translation round trip, and reversal round trip. Runtime acceptance pending.

### RP-08 — producer-disposition conflation

```text
bad: if !succeeded -> generic substitute
good: NotApplicable | Produced<T> | Rejected<E>, with Rejected terminal for owned domain
```

Untouched by M1a. M2 owns migration.

### RP-09 — local consumption of global authority

```text
bad:
  for face: require every global relation to be consumed locally

good:
  validate global registry once
  for face: consume only unique locally witnessed certificate path
```

Untouched by M1a. Current production focused chart/reachability contracts pass but direct torus remains red. M4 owns certificate migration.

## M1a mandatory pattern record

| Pattern | Touched? | Exact boundary | Corrective invariant | Counterfactual / representative evidence |
|---|---|---|---|---|
| `RP-01` | **yes** | `directional::authority` IDs + `LegacyAuthorityAdapters` | domain types cannot implicitly convert; conversion requires supplied domain/extent and typed failure | static nonconvertibility, negative/out-of-range, numeric coincidence, cross-domain misuse; **runtime pending** |
| `RP-02` | preservation | new authority test target vs accepted T1 oracle/direct authority | M1a semantic proof remains separate; accepted T1 oracle/package cannot be replaced by compile success | 29-name manifest and T1 binaries byte-identical; following artifact re-runs 29/29/direct cases |
| `RP-03` | no | — | producer state unchanged | production binary identity |
| `RP-04` | no | — | no search/recursion/work loop introduced | source boundary inspection |
| `RP-05` | **yes** | `SourceEdgeTopologyKey`, `Orientation`, `CanonicalRoute` | semantic identity excludes representation handles and treats direction explicitly | endpoint reversal + handle perturbation + route reversal contracts; **runtime pending** |
| `RP-06` | no | — | shared authority storage unchanged | production binary identity |
| `RP-07` | **yes** | `QuarterTurn`, `GridAutomorphism`, route reversal | exact modulo-4/cycle/inverse algebra | four-turn, inverse, associativity, nonzero rotation, reversal contracts; **runtime pending** |
| `RP-08` | no | — | producer disposition unchanged | production binary identity |
| `RP-09` | no | — | global/local relation consumption unchanged | production binary identity; G4-R007 remains active |

A touched row that fails immutable runtime is a stop condition; do not advance to M1b.

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

`G4-R007`: hard-rail face-chart authority over-rejects direct torus; initial remediation consumed complete relation authority locally. Artifact `9031804178` passes focused authority yet direct torus remains 0/3 with 241 `LocalSheetMismatch` issues after 192 quads, complete lineage, `4/8/4`, `1/0/0`. Do not infer a new root cause from mismatch count alone.

## Persistent blockers

| ID | Blocker | Required gate |
|---|---|---|
| `G4-B001` | Direct torus final `LocalSheetMismatch`. | strict-valid torus 3/3 |
| `G4-B002` | Exact Phase10 torus `InvalidHardRailPairing`. | shared source-authoritative rail schedule; M3 |
| `G4-B003` | Nonzero periodic `Z4` production capability. | M1/M4 foundation then production acceptance |
| `G4-B004` | Positive multi-isolation quotient witness. | focused + representative certificate evidence |

## Architecture enforcement register

Structural debts are not additional runtime regression events.

| ID | Severity | Patterns | Close condition / current state |
|---|---|---|---|
| `AR-01` | Critical | `RP-03`, `RP-08` | closed `ProducerOutcome<T>`; M2 |
| `AR-02` | Critical | `RP-01`, `RP-03`, `RP-06`, `RP-07` | strong IDs + one typed route; **M1a implementation compiled, immutable runtime pending; production adoption later** |
| `AR-03` | High | `RP-01`, `RP-03`, `RP-05` | domain-specific semantic keys; **M1a core compiled, runtime pending** |
| `AR-04` | High | `RP-06`, `RP-09` | one chart type + immutable single-writer snapshots; **FieldChartId domain introduced in M1a, snapshots remain M2** |
| `AR-05` | High | `RP-05`, `RP-07` | semantic identity separated from representation; **M1a core compiled, runtime pending** |
| `AR-06` | Critical | `RP-01`, `RP-05`, `RP-09` | producer-owned relation registry + certificate paths; M4 |
| `AR-07` | Critical | `RP-06`, `RP-09` | global conformity before local construction; M3 |
| `AR-08` | High | `RP-03`, `RP-06`, `RP-09` | producer-scoped immutable output; M2/M3 |
| `AR-09` | High | `RP-01`, `RP-05`, `RP-06` | one tagged exact source-support kernel; **tagged representation introduced M1a, production rebinding remains M5** |
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
| `TA-05` | High | **test-authority resolved by artifact `9041289209`** |
| `TA-06` | High | T1 domain-independent mutation tests 29/29; M1a next turn must preserve |
| `TA-07` | High | T1 package/discovery exact 29/29; M1a package statically preserves it |
| `TA-08` | High | T1 canonical row/cycle/reversal metamorphism accepted; M1a adds typed semantic route metamorphism pending runtime |
| `TA-09` | High | coherent reset/work/time/RSS gate remains required |
| `TA-10` | High | T2 semantic fixture manifest |
| `TA-11` | High | T1 topology/lineage/disposition mutation adequate; T5 completes geometry/field/quality |
| `TA-12` | Moderate | `tests/TESTING_STRATEGY.md` remains normative-only |

## Authoritative next architecture/test step

Next turn:
`.agents/Directional/Architecture_M1a_Authority_Kernel_Core_Artifact_Only_Test_Benchmark_Plan.md`.

Consume artifacts `9041930767 / 9041930871` only. Require exact package verification, exact 14-test authority discovery and **14/14**, exact 29-test T1 oracle discovery and **29/29**, preserved direct accepted cases, and explicit Bunny/Vase visibility. No source repair is allowed in that Test + Benchmark turn.

Only after immutable M1a acceptance may M1b migrate exactly one production consumer through the new authority kernel.
