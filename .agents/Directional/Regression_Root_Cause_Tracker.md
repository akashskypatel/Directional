# Surface-Cell Regression Root-Cause Tracker

This is the permanent stable-ID regression and repeated-pattern index for the
production surface-cell implementation. Detailed point-in-time event evidence
is kept in `.agents/Directional/PR_8_Regression_Audit_Inventory.md`; dated turn
reports keep artifact/runtime detail. This file keeps the current state,
recurrence signal, anti-pattern shape, required replacement shape, and
architecture/test enforcement registers concise enough to review every turn.

Last updated: **2026-08-09 UTC** after artifact `9031804178` runtime closeout.

## Rules

- Assign a stable ID when accepted behavior, test authority, packaging, or a
  public contract regresses relative to an exact baseline.
- Do not create a second entry while the same affected gate remains unresolved.
  Consecutive worsening/persistence is evidence on the existing event.
- A later loss after the affected authority was restored is a recurrence.
- Record the earliest evidenced cause, not only the terminal failure string.
- Mark a regression resolved only after an immutable artifact passes the
  affected acceptance gate. Compile success alone is `fix_pending_runtime`.
- Keep persistent blockers that are not regressions in the separate blocker
  table.
- Before every turn, review `RP-01` through `RP-09` and record the mandatory
  pattern table below.
- A Code + Build plan may not instantiate a recorded anti-pattern. It must name
  the corrective invariant and the counterfactual/representative evidence.
- A focused/helper pass cannot close representative product intent by itself.
- Test + Benchmark closeout updates the existing event/pattern when applicable;
  persistence is not a new recurrence.

## Status vocabulary

| Status | Meaning |
|---|---|
| `active` | Reproduces in the current runtime authority. |
| `fix_in_progress` | An authorized Code + Build turn is implementing a correction. |
| `fix_pending_runtime` | The correction compiles, but immutable runtime acceptance has not run. |
| `resolved` | A later immutable artifact passes the affected gate. |
| `test_authority_resolved` | The regression was in a test/oracle and corrected runtime evidence accepts the intended contract. |

## PR-wide audit authority

Historical evidence range:
`d8b4dba98747d3adf0ca24002642bcad9e9847db..027e5194a9013cc1fe9ea18c1b79741301e40f74`
(**1,789 commits**). The repeated-pattern expansion was published from
`8ef353034641c3a068095334ceea5e6ddb0c39c1` (**1,790 commits**); that last
commit is documentation-only.

The audit identifies **34 distinct regression events** in **14 architectural
categories**, including **20 recurrences**. The primary result-document corpus
contains **114 regression-bearing commits**: 55 report introductions, 34
machine-result updates, and 25 report-lifecycle changes.

Artifact `9031804178` creates **no new event or recurrence**. Direct torus
worsened from 165 to 241 `LocalSheetMismatch` issues, but `PR8-R034 / G4-R007`
was never resolved; this is persistence/worsening of the existing event.
`G4-R007` is therefore **active**.

### PR-wide category rollup

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
| `INTRINSIC_SUPPORT_OVERCONSTRAINT` | — | 1 | 0 |
| `INCOMPLETE_TRANSACTIONAL_ROLLBACK` | — | 1 | 0 |
| `SHARED_EDGE_ORIENTATION_INVERSION` | — | 1 | 0 |
| `INCOMPLETE_ORBIT_PUBLICATION` | — | 1 | 0 |
| `EXACT_SIMPLEX_CANONICALIZATION_LOSS` | — | 1 | 0 |
| **Total** |  | **34** | **20** |

## Repeated coding-pattern catalog

The nine repeated code shapes cover **29 events** and all **20 recurrences**.
The five remaining categories are singletons and are not prematurely grouped.

| Pattern | Repeated code shape | Events | Recurrences |
|---|---|---:|---:|
| `RP-01` | Consumer guesses/intersects distinct authority domains as one scalar/equality predicate. | 6 | 5 |
| `RP-02` | Test/build proxy is treated as proof although semantic path, invariant, independent oracle, or packaged executable is absent. | 6 | 5 |
| `RP-03` | One flag/result/disposition carries independent policy or stage meanings. | 4 | 3 |
| `RP-04` | Local bounds surround recursive/nested/process-cumulative work without one global ledger. | 3 | 2 |
| `RP-05` | Identity/order/hash includes traversal, allocation, orientation, or emission role. | 2 | 1 |
| `RP-06` | Shared authority membership is copied into every consumer object. | 2 | 1 |
| `RP-07` | Cyclic adjacency is validated as a linear sequence or by duplicate neighbor value rather than sector position. | 2 | 1 |
| `RP-08` | Typed producer disposition is reduced to a boolean/lossy aggregate, enabling invalid substitution. | 2 | 1 |
| `RP-09` | Complete global authority is required to be directly consumed by every local face/path. | 2 | 1 |

### RP-01 — consumer-domain guessing and compound authority equality

Events: `PR8-R007`, `R014`, `R019`, `R028`, `R031`, `R033`.

Point-in-time evidence includes component/local-sheet intersection in
`680d81c`, local-sheet chart gating in `f4cce52`, genuine-boundary compact-index
lookup in `7f48663`, and one bare `int` carrying full-`EF`/compact meanings in
`82151bf`.

Anti-pattern:

```text
authority_id: int
if cross_field_transition_exists:
    authority_id = full_ef_row
else:
    authority_id = source_wide_compact_index
scope = intersection((component, local_sheet) for every local claim)
consume_as_compact_index(authority_id)
```

Required shape:

```text
RouteAuthority:
    topology: CanonicalEdgeKey
    source_wide_transition: Optional<SourceWideTransitionIndex>
    cross_field_transition: Optional<FullEfRow>

OwnershipAuthority:
    source_component: SourceComponentId
    intrinsic_chart_component: IntrinsicChartComponentId
    local_sheet_label: LocalIsolationLabel

validate each field only in its declared domain
never recover intrinsic ownership by intersecting local labels
```

Guard: every identity field needs a named domain type, producer, consumer,
serialization meaning, and row/order counterfactual.

### RP-02 — proxy tests and incomplete executable authority

Events: `PR8-R004`, `R013`, `R022`, `R024`, `R027`, `R030`.

Evidence includes tests that did not enter the claimed production path, omitted
default target sources, raw-ID equality used as semantics, impossible witnesses,
retention timing used as authority, and required contracts absent from packaged
executables.

Anti-pattern:

```text
fixture = convenient_fixture()
helper = call_lower_level_helper(fixture)
assert raw_ids_or_counts(helper)
# production semantic path not entered
# precondition not proved
# independent oracle absent
# packaged discovery may be absent
```

Required shape:

```text
intent = declared_contract()
precondition = independently_prove_fixture_state()
result = invoke_public_entry_or_exact_declared_stage()
assert typed_stage_or_public_outcome(result)
oracle = independently_recompute_observable_contract(input, result)
assert oracle.accepts(result)
mutated = change_one_semantic_fact(result)
assert oracle.rejects(mutated)
record exact executable/test/fixture/seed/artifact identity
```

Guard: production `result.success`, production validator output, counts,
helper coverage, raw IDs/order, hashes, retention lifetime, compilation, or
no-crash are not independent product proof.

**Current evidence:** artifact `9031804178` passes all **18/18** required
multi-rail/face-chart/canonical focused contracts while direct torus remains
**0/3** and worsens to **241** mismatches. This is direct `TA-05 / AR-12`
evidence and is why T1 independent test-oracle foundation is next.

### RP-03 — one state carries two meanings

Events: `PR8-R006`, `R009`, `R011`, `R032`.

Anti-pattern:

```text
retain = caller_requested OR execution_needs_state
if retain: publish_state()
measurement_available = process_sample_succeeded
real_failure overwrites requested test-policy outcome
```

Required shape:

```text
retain_for_execution != retain_for_caller
real_stage_outcome != explicit_test_policy_outcome
measurement_available = required semantic sample actually exists
```

Guard: vary each meaning independently and prove the same real stage is reached.

### RP-04 — local bounds around multiplicative work

Events: `PR8-R003`, `R010`, `R020`.

Evidence includes recursive whole-complex copies/recompletion and nested
conflict/patch/variant/restitch loops. `R020` proves cumulative process state,
but its exact retaining producer remains unproven.

Anti-pattern:

```text
solve(state, local_depth):
    for candidate in local_limit:
        trial = deep_copy(state)
        solve(trial, local_depth - 1)
```

Required shape:

```text
WorkController:
    remaining_global_work
    visited_canonical_states
    attempted_actions

all recursion/nested loops share controller
canonical duplicate states are rejected
public run boundary resets per-run state
```

Guard: derive a worst-case global bound across every nested loop, recursive
call, copy, recomputation, and suite/process cache.

Current artifact evidence: the exact literal bounded producer filter completed
163 tests with a full summary in **30.63 s**. Earlier orchestration-wrapper
return behavior is not classified as product nontermination.

### RP-05 — representation-dependent identity

Events: `PR8-R016`, `R026`.

Anti-pattern:

```text
identity = hash(exterior_or_twin_role, directed_record)
sort(components, key=(structural_hash, semantic_topology))
```

Required shape:

```text
canonical_record = quotient_by(
    traversal_start, orientation, face_row_order,
    allocation_order, exterior_or_twin_role)
identity = hash(canonical_record)
sort by canonical semantic topology before derived hash
```

Guard: face-row, traversal-start, whole-orientation, disconnected-component,
and cyclic/reversed representation counterfactuals.

### RP-06 — duplicated shared authority membership

Events: `PR8-R001`, `R008`.

Anti-pattern:

```text
for consumer in consumers:
    consumer.members = copy(all_shared_members)
```

Required shape:

```text
registry[class_key] = canonical_membership_once
consumer.class_key = class_key
consumer.local_witness = bounded local authority
```

Guard: storage must scale `O(classes + members + consumers)`, not
`O(consumers * members)`.

### RP-07 — cyclic topology treated as a linear list

Events: `PR8-R017`, `R018`.

Anti-pattern:

```text
previous/next duplicate neighbor value => contradiction
source_position <= 0 => reject wrap
```

Required shape:

```text
previous = (i - 1 + count) mod count
next = (i + 1) mod count
compare sector positions, not only neighbor values
explicitly support wrap and degree-two duplicate rays
```

Guard: cardinalities 1/2/3+, both wrap directions, reversal, and hard-rail
separation.

### RP-08 — lossy producer-disposition reduction

Events: `PR8-R021`, `R025`.

Anti-pattern:

```text
use_authoritative = producer.succeeded
if !use_authoritative: run_generic_substitute()
```

Required shape:

```text
switch producer.disposition:
    Produced -> consume authoritative output
    Rejected -> fail closed with original reason
    NotApplicable -> substitute only if parent domain is unclaimed
```

Guard: exhaustive truth table for `Produced`, `Rejected`, `NotApplicable` at
every aggregation/fallback boundary.

### RP-09 — global authority consumed by each local face

Events: `PR8-R029`, `R034`.

Original `R034` anti-pattern at `8f37612`:

```text
for face:
    for relation in complete_vertex_authority:
        require direct scalar->face relation
        require relation peer appears on this face
        mark relation used
    require every relation used
```

Required shape:

```text
global_graph = validate_complete_authority_once()
for face:
    reachable = exact graph reachability from scalar-supported roots
    selected = unique intersection of reachable components for face corners
    require only selected witness path
    unrelated globally valid relations need not be consumed on this face
```

Guard: owner, validation scope, and consumption scope must be explicit. Focused
fixtures include chained, unused, off-face-peer, missing-link, ambiguity,
disconnected-sheet, and row-order cases.

**Current runtime:** implementation `6af23d9` satisfies those focused local
contracts (**11/11** chart-reachability/face-chart relevant cases), but direct
torus still fails **0/3** with **241** `LocalSheetMismatch` issues. Therefore
that correction is insufficient as product remediation. Do not infer a new
root cause from count alone; keep `G4-R007` active and require independent
product authority before the next production migration.

## Mandatory per-turn pattern review record

Every plan, report, and handoff must contain or link this table:

| Pattern | Touched? | Exact affected producer/consumer | Evidence anti-pattern is absent / corrective invariant | Counterfactual and representative gate |
|---|---|---|---|---|
| `RP-01` … `RP-09` | yes/no | exact symbol/target/artifact boundary | concrete invariant and inspection evidence | named focused negative + representative evidence |

A touched row that cannot be completed is a stop condition. If proposed code
resembles a recorded anti-pattern, revise it or use an already accepted design
proof / required independent Review before Code + Build.

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

## Current G4 cause families

| Cause family | Pattern | G4 IDs | Signal |
|---|---|---|---|
| `AUTHORITY_DOMAIN_CONFLATION` | `RP-01` | `G4-R001`, `R004`, `R006` | repeated three times across product/tests |
| `LOCAL_CONSUMPTION_OF_GLOBAL_AUTHORITY` | `RP-09` | `G4-R002`, `R007` | repeated twice; representative product still red |
| `EXECUTABLE_COVERAGE_GAP` | `RP-02` | `G4-R003` | resolved G4 event; broader test architecture remains open |
| `POLICY_STATE_CONFLATION` | `RP-03` | `G4-R005` | resolved G4 event |

## Regression entries

### G4-R001 — genuine source boundaries rejected by transition quotient

| Field | Value |
|---|---|
| Classification | product implementation regression |
| First detected | artifact `9024549134`, implementation `7f486632b154a303789df6c4dd44f602c8c71281` |
| Symptom | Plane, seam, close sheets, and cylinder failed at `InvalidFrontBoundaryAuthority`; producer fell from `124/127` to `99/128`. |
| Cause | One-face boundary canonical topology was conflated with a two-face compact transition index. |
| Guard | Genuine boundaries carry topology without invented interior index; two-face transitions keep separate typed authority. |
| Resolution | `resolved` by artifact `9026181778`. |

### G4-R002 — internal isolation seams required as cell-boundary crossings

| Field | Value |
|---|---|
| Classification | product/contract regression |
| First detected | artifact `9024549134` |
| Symptom | Torus stopped at `UnconsumedAuthoritativeIsolationSeam`; `4/8/4` authority remained unconsumed. |
| Cause | Complete internal seam authority was required to appear on selected output cell-side routes. |
| Guard | Validate reciprocal seam certificates globally; require a certificate only for selected cross-sheet transport. |
| Resolution | `resolved`; later torus artifacts consume complete `4/8/4`. |

### G4-R003 — required quotient counterfactuals absent from immutable artifact

| Field | Value |
|---|---|
| Classification | build/test packaging regression |
| First detected | artifact `9024549134` |
| Cause | Required contracts existed only in a disabled historical target / artifact closure was not checked. |
| Guard | Every mandatory contract is independently named, default-packaged, discovered, and preflighted. |
| Resolution | `resolved` by artifact `9026181778`. |

### G4-R004 — full-`EF` and compact transition indices serialized as one domain

| Field | Value |
|---|---|
| Classification | product implementation regression; recurrence of G4-R001 family |
| First detected | artifact `9026181778`, implementation `82151bf51bce9af9859282b2a03e295a0ee5a309` |
| Symptom | Plane/close sheets failed `InvalidAuthoritativeTransitionSourceEdge`; cylinder/torus failed `InvalidPeriodicCutAuthority`. |
| Cause | One `int` alternated between full `mesh.EF`, source-wide compact, and possible region-local compact identities. |
| Guard | Canonical topology, full-EF validation identity, and source-wide compact serialization are separate domains. |
| Resolution | `resolved` by artifact `9028103772`, implementation `edc14d38f862b94941b249f564050e2e1f8f5287`. |

### G4-R005 — internal failure-injection retention leaked into public context

| Field | Value |
|---|---|
| Classification | public contract regression |
| First detected | artifact `9026181778` |
| Cause | One flag controlled temporary execution lifetime and caller-visible retention. |
| Guard | `retainForExecution` and `retainRequested` are independent. |
| Resolution | `resolved` by artifact `9028103772`. |

### G4-R006 — canonical transition tests retained obsolete numeric-domain authority

| Field | Value |
|---|---|
| Classification | test-authority regression; recurrence of G4-R001/R004 family |
| First detected | artifact `9028103772` |
| Cause | Tests repeated domain conflation and did not witness an actual serialized route before tampering. |
| Guard | Record exact serialized route slot; pair compact value with canonical topology; select full-EF authority only through reciprocal incident faces. |
| Resolution | `test_authority_resolved` by artifact `9029584083`; seven canonical contracts pass individually. |

### G4-R007 — hard-rail face-chart authority over-rejects direct torus

| Field | Value |
|---|---|
| Classification | product implementation regression; recurrence of G4-R002 cause family |
| First detected | artifact `9030700527`, implementation `8f37612148f34bac63cf294000c17c7de2e03b41` |
| Pre-regression reference | artifact `9029584083`: torus `0/3`, 74 `LocalSheetMismatch` issues after 192 quads, complete lineage, `4/8/4`, `1/0/0`. |
| First regression symptom | artifact `9030700527`: torus `0/3`, 165 issues; plane/seam/close/cylinder remained `3/3`. |
| First evidenced cause | Resolver treated complete quotient relation authority as a direct scalar star and required unrelated/global relations to be consumed by each local face. |
| Corrective guard | Validate complete relation structure globally; derive exact scalar-rooted vertex-local reachability; require only a selected face witness; keep scalar provenance exact. |
| Attempted correction | implementation `6af23d9aeca29e63aa13c4ae49f50d1748939c49`; four new multi-relation contracts plus retained face-chart/canonical contracts. |
| Current runtime | artifact `9031804178`: all required focused **18/18** pass, but direct torus remains **0/3** and reports **241** `LocalSheetMismatch` issues in every run after 192 quads, complete lineage, `4/8/4`, `1/0/0`. |
| Interpretation | Attempted correction is insufficient at representative product level. Count increase alone does not prove a new root cause. This remains the same unresolved event; recurrence totals do not change. |
| Status | **`active`** |
| Evidence | `Gate_4_Torus_Hard_Rail_Face_Chart_Authority_Artifact_Only_Test_Benchmark_Report.md`; `Gate_4_Torus_Multi_Rail_Chart_Reachability_Code_Build_Report.md`; `Gate_4_Torus_Multi_Rail_Chart_Reachability_Artifact_Only_Test_Benchmark_Report.md` |

## Persistent blockers that are not current-patch regressions

| ID | Blocker | Why separate | Current gate |
|---|---|---|---|
| `G4-B001` | Baseline/direct torus `LocalSheetMismatch` | Emerged after earlier quotient repair; not a separate new event from G4-R007. | Still fails representative direct torus; artifact `9031804178` reports 241 issues. Do not accept a reduced count; require strict-valid `3/3`. |
| `G4-B002` | Exact Phase10 torus `InvalidHardRailPairing` | Earlier target-size-dependent scheduling defect. | Shared source-authoritative hard-rail breakpoint scheduling; still gates sphere. |
| `G4-B003` | Nonzero periodic `Z4` rotation | Missing capability, not latest chart patch regression. | Deferred G4 slice. |
| `G4-B004` | Positive multi-isolation quotient witness | Missing proven positive lineage state. | Deferred focused fixture/implementation slice. |

## Architecture enforcement register — independent review 2026-08-09

These are structural debts, not additional runtime regression events. A passing
focused artifact does not close them; each closes only with the named
structural + focused/metamorphic/representative evidence.

| ID | Severity | Pattern mapping | Structural evidence at `6af23d9` | Required close condition |
|---|---|---|---|---|
| `AR-01` | Critical | `RP-03`, `RP-08` | `SurfacePhaseFrontResult` exposes independently mutable disposition/attempted/succeeded state. | One closed `ProducerOutcome<T>` with exhaustive dispatch. |
| `AR-02` | Critical | `RP-01`, `RP-03`, `RP-06`, `RP-07` | Bare integer edge domains and parallel topology/index route vectors remain public. | Strong ID domains and one `CanonicalRoute<TransitionStep>`. |
| `AR-03` | High | `RP-01`, `RP-03`, `RP-05` | Generic canonical identity values carry unrelated schemas; ownership uses representation handles. | Domain-specific semantic keys; no ordinal/row/backend handle in semantic identity. |
| `AR-04` | High | `RP-06`, `RP-09` | Duplicate chart types/tables create multiple readable authorities. | One chart type and immutable single-writer authority snapshots by typed ID. |
| `AR-05` | High | `RP-05`, `RP-07` | Semantic equality/order still contains representation handles in places. | Semantic identity separated from representation; canonical order precedes hash. |
| `AR-06` | Critical | `RP-01`, `RP-05`, `RP-09` | Validator reconstructs relation endpoints/reachability instead of verifying producer proof paths. | Producer-owned relation registry + exact `ChartSelectionCertificate` paths. |
| `AR-07` | Critical | `RP-06`, `RP-09` | Region producers choose hard-rail breakpoints independently then pair post hoc. | One global conformity schedule before local construction. |
| `AR-08` | High | `RP-03`, `RP-06`, `RP-09` | Aggregate normalization can overwrite producer scope semantics. | Producers emit fully scoped immutable output; aggregation verifies only. |
| `AR-09` | High | `RP-01`, `RP-05`, `RP-06` | Source support is reimplemented with tolerance/quantization-derived identity. | One sanitized exact source-support kernel; tolerance cannot be topology key. |
| `AR-10` | Moderate | all | Tracing/arrangement/pipeline/validation monoliths collapse stage ownership. | Incremental responsibility modules; new behavior enters through stage APIs. |
| `AR-11` | High | `RP-02`, `RP-03` | Historical design mixed normative invariants with current status. | `DESIGN.md` remains normative-only; status stays in reports/trackers/handoff. |
| `AR-12` | High | `RP-02` | Focused relation fixtures can pass before representative production intent does. Artifact `9031804178` now demonstrates this directly. | Independent product oracle + mutation adequacy + packaged discovery + representative production evidence. |

Normative migration: `.agents/Directional/DESIGN.md`. Review evidence:
`.agents/Directional/Surface_Cell_Architecture_Independent_Design_Review_Report.md`.

## Test architecture enforcement register — independent audit 2026-08-09

These are structural test debts and do not alter 34/14/20 historical counts.
T1 is now the authoritative next Code + Build turn.

| ID | Severity | Pattern mapping | Current defect | Required close condition |
|---|---|---|---|---|
| `TA-01` | Critical | `RP-02` | Direct acceptance lacks independent complete topology/lineage/geometry/disposition oracle. | T1 independent product oracle + mutation adequacy; full intent gate by T5. |
| `TA-02` | Critical | `RP-02`, `RP-07`, `RP-09` | Direct default matrix omits torus, thin bent tube, sphere, mechanical feature. | T2 packages/discovers all ten cases with explicit green/known-red state. |
| `TA-03` | Critical | `RP-01`, `RP-02` | Benchmark quality metrics are observational and partly coupled to production validator concepts. | Independent test decision procedures + approved metric baselines/thresholds. |
| `TA-04` | High | `RP-01`, `RP-04`, `RP-06`, `RP-07`, `RP-09` | No property generator/shrinker/fuzz target. | T3 seed replay/shrinking + T4 sanitizer fuzz/replay. |
| `TA-05` | High | `RP-02` | Focused helper/internal-state evidence can be promoted to product proof; artifact `9031804178` demonstrates the danger. | Every mandatory family declares intent/precondition/entry/independent oracle/counterexample/evidence identity. |
| `TA-06` | High | `RP-01`, `RP-02` | Historical tests copied weak numeric domains/impossible witnesses. | Domain-independent oracle mutation tests reject intended corruptions. |
| `TA-07` | High | `RP-02` | Mandatory tests have previously been absent from default immutable artifacts. | T1/T6 manifest verifies executable/discovery/label/source/fixture/seed/artifact. |
| `TA-08` | High | `RP-02`, `RP-05`, `RP-07` | Raw IDs/order/cardinality/hash/lifetime can become semantic proxies. | Canonical/metamorphic oracle unless value itself is declared contract. |
| `TA-09` | High | `RP-03`, `RP-04`, `RP-06` | Reset/cumulative work and resource behavior lack coherent gate. | Repeated-process/in-process properties gate monotone work/time/RSS/state reset. |
| `TA-10` | High | `RP-02`, `RP-07`, `RP-09` | Fixture manifest lacks semantic field/topology/feature descriptors. | T2 versioned semantic manifest. |
| `TA-11` | High | `RP-02` | Product oracle is not mutation-proven. | T1/T5 deliberate topology/lineage/geometry/field/quality corruptions are rejected independently. |
| `TA-12` | Moderate | `RP-02`, `RP-03` | Testing strategy historically mixed normative/status data. | Keep `tests/TESTING_STRATEGY.md` normative-only. |

Full test audit:
`.agents/Directional/Surface_Cell_Test_Suite_Independent_Audit_And_Redesign_Plan.md`.

## Architectural review triggers

Request/reuse the independent design proof when any of these occurs:

1. a cause family reaches two regressions;
2. a resolved regression reappears;
3. a fix moves a failure without restoring the entering accepted matrix;
4. focused tests pass while a representative direct fixture regresses for an
   unrepresented state shape;
5. a new bare numeric field carries topology/index/ownership/semantic authority;
6. planned work touches an `RP-nn` path without a complete pattern-review row;
7. a mandatory direct test lacks proved precondition, independent semantic
   oracle, rejected counterexample, or package identity;
8. a focused/helper/property pass is used to close representative product
   intent or a known-red direct case is hidden;
9. a property/fuzz failure cannot be replayed/minimized within its declared
   precondition and budget.

Triggers 1, 3, and 4 have already occurred in G4. The independent architecture
review and test-suite audit are complete and their accepted response is staged:
**T1 independent test-oracle foundation first; M1 authority-kernel migration
only after T1 immutable acceptance.** Review policy remains `never` for an
optional additional Review turn unless a new planned change violates those
accepted design proofs.
