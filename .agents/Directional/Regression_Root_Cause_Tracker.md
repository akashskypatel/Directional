# Surface-Cell Regression Root-Cause Tracker

This is the permanent regression index for the production surface-cell
implementation. Turn reports retain detailed evidence; this tracker keeps one
stable entry per regression so repeated architectural causes remain visible.

## Rules

- Assign a stable ID when accepted behavior, test authority, packaging, or a
  public contract regresses relative to an exact baseline.
- Do not create a second entry when the same regression reappears. Update its
  `last_seen`, evidence, and recurrence count.
- Record the earliest evidenced cause, not only the terminal failure string.
- Link every entry to one primary architectural cause family. Add contributing
  families only when independently evidenced.
- Mark a regression resolved only after a later immutable artifact proves the
  affected acceptance gate. Compile success alone is `fix_pending_runtime`.
- Keep persistent blockers that are not regressions in the separate table so
  they are not accidentally reported as changes caused by the latest patch.
- Before every turn, review the repeated coding-pattern catalog below and map
  the planned work to every applicable `RP-nn` entry. This is mandatory even
  when the optional Review-turn policy is `never`.
- A Code + Build plan may not instantiate an anti-pattern below. It must record
  the corrective invariant and the counterfactual/representative validation
  that will prove the same mistake was not repeated.
- Test + Benchmark closeout must update the existing pattern/event recurrence
  when the same code shape reappears; persistence is not a new event.

## Status vocabulary

| Status | Meaning |
|---|---|
| `active` | Reproduces in the current runtime authority. |
| `fix_in_progress` | An authorized Code + Build turn is implementing a correction. |
| `fix_pending_runtime` | The correction compiles, but immutable runtime acceptance has not run. |
| `resolved` | A later immutable artifact passes the affected gate. |
| `test_authority_resolved` | The regression was in a test/oracle and corrected runtime evidence accepts the intended contract. |

## PR-wide audit authority

The historical result/code evidence range is
`d8b4dba98747d3adf0ca24002642bcad9e9847db..027e5194a9013cc1fe9ea18c1b79741301e40f74`
(**1,789 commits**). The repeated-pattern expansion was performed from PR head
`8ef353034641c3a068095334ceea5e6ddb0c39c1` (**1,790 commits**); that last
commit is documentation-only and introduces no new runtime event or source
pattern. The audit identifies **34 distinct regression events** in **14
architectural categories**, including **20 recurrences** after an earlier
event in the same category. The primary result-document corpus contains **114
regression-bearing commits**: 55 report introductions, 34 machine-result
updates, and 25 report-lifecycle changes.

The complete event evidence, recurrence links, dispositions, counting rules,
and exclusions are in
`.agents/Directional/PR_8_Regression_Audit_Inventory.md`. Only
`PR8-R034` / `G4-R007` remains active at the audited head, with status
`fix_pending_runtime`.

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

These IDs describe code shapes, not failure strings. The event mappings are
based on the exact compiled/source snapshots named by the contemporaneous
reports. A later symptom belongs to an existing pattern only when source or
test code demonstrates the same shape.

| Pattern | Repeated code shape | Events | Recurrences | Evidence confidence |
|---|---|---:|---:|---|
| `RP-01` | Consumer guesses or intersects distinct authority domains as one scalar/equality predicate. | 6 | 5 | High |
| `RP-02` | Test/build proxy is treated as proof although the semantic path, invariant, or packaged executable is absent. | 6 | 5 | High |
| `RP-03` | One flag/result/disposition carries two independent policy or stage meanings. | 4 | 3 | High |
| `RP-04` | Local bounds surround recursive, nested, or process-cumulative work with no shared global ledger. | 3 | 2 | High for `PR8-R003/R010`; bounded inference for `PR8-R020` |
| `RP-05` | Identity/order/hash includes traversal, allocation, orientation, or emission role. | 2 | 1 | High |
| `RP-06` | Shared authority membership is copied into every consumer object. | 2 | 1 | High |
| `RP-07` | Cyclic adjacency is validated as a linear sequence or by neighbor value rather than sector position. | 2 | 1 | High |
| `RP-08` | Typed producer dispositions are reduced to a boolean or lossy aggregate, permitting invalid substitution. | 2 | 1 | High |
| `RP-09` | Complete global authority is required to be directly consumed by every local face/path. | 2 | 1 | High |

### RP-01 — consumer-domain guessing and compound authority equality

Events: `PR8-R007`, `PR8-R014`, `PR8-R019`, `PR8-R028`, `PR8-R031`,
`PR8-R033`.

Historical code evidence includes the strict `(component, localSheet)`
intersection in `680d81c:src/geometry/SurfaceArrangement.cpp`, the local-sheet
gate on chart-component lookup in
`f4cce52:include/directional/geometry/SourceChartTransitions.h`, the genuine
boundary's mandatory compact-index lookup in
`7f48663:src/geometry/SurfaceCellTracing.cpp`, and the same `int` output from
full-`EF` and source-wide compact lookup paths in `82151bf`.

Repeated anti-pattern:

```text
authority_id: int

if cross_field_transition_exists:
    authority_id = full_ef_row
else:
    authority_id = source_wide_compact_index

scope = intersection((component, local_sheet) for every local claim)
require exactly_one(scope)
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
derive local witnesses from canonical topology
never recover intrinsic ownership by intersecting local labels
```

Review guard: every new identity field must have a named domain type, producer,
consumer, serialization meaning, and row/order counterfactual. A bare numeric
authority or a conjunction of independent labels fails review.

### RP-02 — proxy tests and incomplete executable authority

Events: `PR8-R004`, `PR8-R013`, `PR8-R022`, `PR8-R024`, `PR8-R027`,
`PR8-R030`.

Historical evidence includes structural-repair tests that never called the
whole-complex repair path, omitted validator sources in
`e31e5ab:CMakeLists.txt`, raw `sourceRouteEdges` equality in
`56f8232:tests/SurfaceCellsPhase10Tests.cpp`, an impossible unsplit-edge
witness in `0279946`, retention-timing authority in `3ca89ab`, and mandatory
quotient counterfactuals absent from the default targets at `7f48663`.

Repeated anti-pattern:

```text
test semantic_contract:
    fixture = convenient_fixture()
    helper_result = call_lower_level_helper(fixture)
    assert raw_row_ids_equal(helper_result)
    assert intermediate_object_is_retained(helper_result)

# target public path was not entered
# fixture did not prove the semantic precondition
# test may not exist in a packaged executable
```

Required shape:

```text
intent = name_user_or_stage_contract()
precondition = prove_fixture_creates_required_semantic_state()
assert precondition

result = invoke_production_entry_point()
assert result.typed_ledger.entered(target_stage)
assert result.typed_outcome == expected_contract
oracle = independently_recompute_input_output_contract()
assert oracle.accepts(result)

counterexample = mutate_one_semantic_fact(result)
assert oracle.rejects(counterexample)

evidence = {
    fixture_or_corpus_checksum,
    deterministic_seed,
    executable,
    exact_discovered_test_name,
    artifact,
    work_and_resource_budget
}
artifact_preflight.assert_complete(evidence)
```

Review guard: name the production entry point, positive precondition, earliest
typed assertion, independent canonical oracle, rejected counterexample, and
packaged executable/fixture/seed/artifact identity for every mandatory test.
Production `result.success`, counts, helper coverage, raw IDs/order, hashes,
retention lifetime, compilation, no-crash, or a passing proxy are not proof.

### RP-03 — one state carries two meanings

Events: `PR8-R006`, `PR8-R009`, `PR8-R011`, `PR8-R032`.

Historical evidence includes fixed-point refresh gated by the production-only
`topologyHealingOnly` mode at `074ec5d`, completion failure returned before the
requested injected-stage result at `9bff7d3`, measurement availability derived
from process RSS rather than a nonempty ownership sample at `aa2917e`, and
`retainIntermediateGeometry = requested || injectionNeeded` at `82151bf`.

Repeated anti-pattern:

```text
retain = caller_requested_retention OR execution_needs_temporary_state
if retain:
    publish_intermediate_state_to_caller()

if real_completion_failed:
    return NotProductionReady
if requested_injected_stage == completion:
    return InjectedStageFailure   # unreachable

measurement_available = working_set_sample_succeeded
```

Required shape:

```text
retain_for_execution = execution_needs_temporary_state
retain_for_caller = caller_requested_retention

temporary_state = keep_while_needed(retain_for_execution)
publish_to_caller only_if retain_for_caller

real_stage_outcome = run_real_stage()
requested_test_outcome = apply_explicit_test_policy(real_stage_outcome)
publish both without overwriting either meaning

measurement_available = sample_exists AND categorized_bytes > 0
```

Review guard: if a boolean or enum appears in two API sentences, split it.
Counterfactuals must vary each meaning independently and reach the same real
stage before public-policy differences are asserted.

### RP-04 — local bounds around multiplicative work

Events: `PR8-R003`, `PR8-R010`, `PR8-R020`.

At `1f4c3c2:src/geometry/PatchDescriptor.cpp`, every locally bounded boundary
candidate copied a complex and recursively called full completion with a
child-local decremented budget. Later completion alternatives at `247061b`
nested conflict, patch, variant, completion, and restitch work. `PR8-R020`
proved cumulative single-process state because isolated P27 completed, but its
exact retaining producer was not established; that uncertainty remains part
of the record.

Repeated anti-pattern:

```text
solve(complex, local_depth):
    for candidate in candidates[0:local_limit]:
        trial = deep_copy(complex)
        result = solve(trial, local_depth - 1)
        if result.accepted:
            return result

for conflict:
    for patch:
        for variant:
            complete_patch()
            restitch_whole_complex()
```

Required shape:

```text
WorkController:
    remaining_global_work
    visited_canonical_states
    attempted_actions

solve(state, controller by reference):
    key = canonical_state(state)
    if key already visited: reject DuplicateState
    if controller.remaining_global_work == 0: reject BudgetExhausted
    consume one globally classified action
    evaluate bounded incremental delta

reset all per-run state at the public process/test boundary
```

Review guard: derive a worst-case global work bound across every nested loop,
recursive call, copy, recomputation, and suite/process cache. A depth counter
or per-loop limit alone is insufficient. Do not claim the exact `PR8-R020`
producer without new evidence.

### RP-05 — representation-dependent identity

Events: `PR8-R016`, `PR8-R026`.

At `f5305ad:src/geometry/SurfaceArrangement.cpp`, exterior boundary halfedges
and ordinary twins entered different directed-incidence record branches, so
orientation reversal changed serialization role. At
`3ca89ab:src/geometry/SurfaceCellTracing.cpp`, region emission sorted first by
`structuralHash` and only then by canonical source vertices, reversing stable
component order relative to the accepted aggregator.

Repeated anti-pattern:

```text
if record_is_exterior_in_this_traversal:
    identity = hash("EXTERIOR", directed_record)
else:
    identity = hash("WEDGE", directed_record)

sort(components, key = (structural_hash, canonical_source_vertices))
```

Required shape:

```text
canonical_record = quotient_by(
    traversal_start,
    orientation,
    face_row_order,
    allocation_order,
    exterior_or_twin_role)

identity = hash(canonical_record)
sort(components, key = canonical_source_topology)
use hash only as derived evidence, never as primary semantic order
```

Review guard: every identity/hash/order change needs face-row, traversal-start,
whole-orientation, and disconnected-component permutation counterfactuals.

### RP-06 — duplicated shared authority membership

Events: `PR8-R001`, `PR8-R008`.

The `d4c1bce` source tree retained expanded ownership identity with completion
objects and increased bunny RSS by 126%. At `94bf834`, each
`SurfaceArrangementCell` stored `sourceCharts` plus the values of its full
`sourceOwnershipClass`; memory accounting explicitly summed both vectors for
every cell, producing roughly cell-count by component-face-count growth.

Repeated anti-pattern:

```text
for cell in cells:
    cell.ownership_members = copy(all_members_of_component(cell.component))
    cell.chart_map = copy(all_charts_of_owner(cell.owner))
```

Required shape:

```text
registry[class_key] = canonical_membership_once

for cell in cells:
    cell.class_key = class_key
    cell.local_witness = fixed_size_local_authority

validate registry[class_key] when full membership is needed
```

Review guard: state and benchmark the asymptotic storage model. Shared
membership must be `O(classes + members + consumers)`, not
`O(consumers * members)`.

### RP-07 — cyclic topology treated as a linear list

Events: `PR8-R017`, `PR8-R018`.

At `ec44ab7:src/geometry/SurfaceArrangement.cpp`, both predecessor and
successor positions match the same opposite ray for a degree-two rotation;
the second match was treated as a contradiction. At `2444c38`, an intrinsic
sector required `sourcePosition > 0` and `targetPosition == sourcePosition - 1`,
rejecting the valid first-to-last cyclic wrap.

Repeated anti-pattern:

```text
if rays[previous(i)] == exterior_outgoing:
    step = -1
if rays[next(i)] == exterior_outgoing:
    if step already set: reject Contradiction

if source_position <= 0:
    reject Wrap
require target_position == source_position - 1
```

Required shape:

```text
previous_position = (i - 1 + count) mod count
next_position = (i + 1) mod count

compare sector positions, not only neighbor ray values
allow previous_ray == next_ray when count == 2
adjacent(a, b) = ((a - b + count) mod count) in {1, count - 1}
classify exterior and interior sectors explicitly
```

Review guard: include cardinalities 1/2/3+, both wrap directions, reversal,
and hard-rail-separated fan counterfactuals for every cyclic algorithm.

### RP-08 — lossy producer-disposition reduction

Events: `PR8-R021`, `PR8-R025`.

At `21f081b:src/pipeline/RemeshPipeline.cpp`, authoritative use was selected by
`phaseFront.succeeded`; any false value entered the generic arrangement path
without first making `Rejected` terminal. At
`3ca89ab:src/geometry/SurfaceCellTracing.cpp`, all child regions returning
`NotApplicable` left the parent at its default `NotApplicable`, even when
embedded barriers made the parent domain authoritatively rejected.

Repeated anti-pattern:

```text
use_authoritative = producer.succeeded
if not use_authoritative:
    run_generic_substitute()

if unsupported_child and not any_child_produced:
    return default_NotApplicable
```

Required shape:

```text
switch producer.disposition:
    Produced: consume_authoritative_output()
    Rejected: fail_closed_with_original_reason()
    NotApplicable: allow_substitute_only_if_parent_domain_is_unclaimed()

parent_disposition = exhaustive_reduce(
    parent_authority,
    all_child_dispositions)
Rejected dominates when parent authority was attempted and invalid
downstream stages may not overwrite the first typed producer reason
```

Review guard: every aggregation and fallback boundary needs a truth table for
`Produced`, `Rejected`, and `NotApplicable`, including all-children-empty and
mixed-child cases.

### RP-09 — global authority consumed by each local face

Events: `PR8-R029`, `PR8-R034`.

The transition quotient first required every reciprocal isolation seam to
appear on selected cell-side routes. At
`8f37612:src/validation/SourceAuthoritativeMeshValidator.cpp`, every retained
hard-rail equivalence had to connect directly from a scalar component, every
equivalence had to be marked used, and a reciprocal peer had to occur among
the vertices of the same face. Both confuse complete retained authority with
the witness selected by one consumer.

Repeated anti-pattern:

```text
for face in output_faces:
    for relation in complete_vertex_authority:
        require relation directly connects scalar_chart to face_chart
        require relation appears on this face
    require every relation was used
```

Required shape:

```text
global_graph = validate_complete_authority_once()
require global_graph.structure_and_reciprocity_are_exact

for face in output_faces:
    reachable = graph_reachability(from each scalar-supported root)
    selected = unique_intersection(reachable components for face vertices)
    require only a valid witness path to selected
    do not require unrelated valid relations on this face
```

Review guard: write down the owner, validation scope, and consumption scope of
every authority collection. Focused fixtures must include chained, unused,
off-face-peer, missing-link, ambiguity, and disconnected-sheet cases.

### Mandatory per-turn pattern review record

Every plan, turn report, and handoff must contain or link this table:

| Pattern | Touched? | Evidence anti-pattern is absent | Corrective invariant | Counterfactual and representative gate |
|---|---|---|---|---|
| `RP-01` … `RP-09` | yes/no | exact code/data-flow reference | named invariant | exact test/artifact evidence |

If a touched row cannot be completed before implementation, stop and revise
the design. If the proposed code resembles an anti-pattern, an independent
architectural Review is required before the related Code + Build turn. The
configured optional review policy does not waive this user-mandated check.

### Current G4 stable-ID mapping

| PR-wide event | Stable G4 entry | PR-wide category | Pattern |
|---|---|---|---|
| `PR8-R028` | `G4-R001` | `AUTHORITY_DOMAIN_CONFLATION` | `RP-01` |
| `PR8-R029` | `G4-R002` | `LOCAL_CONSUMPTION_OF_GLOBAL_AUTHORITY` | `RP-09` |
| `PR8-R030` | `G4-R003` | `TEST_AUTHORITY_COVERAGE_GAP` | `RP-02` |
| `PR8-R031` | `G4-R004` | `AUTHORITY_DOMAIN_CONFLATION` | `RP-01` |
| `PR8-R032` | `G4-R005` | `POLICY_STAGE_STATE_CONFLATION` | `RP-03` |
| `PR8-R033` | `G4-R006` | `AUTHORITY_DOMAIN_CONFLATION` | `RP-01` |
| `PR8-R034` | `G4-R007` | `LOCAL_CONSUMPTION_OF_GLOBAL_AUTHORITY` | `RP-09` |

## Current G4 architectural cause families

| Cause family | Pattern | Definition | Regression IDs | Recurrence signal |
|---|---|---|---|---|
| `AUTHORITY_DOMAIN_CONFLATION` | `RP-01` | Distinct topology, validation, or serialization identities share an untyped numeric representation and are consumed interchangeably. | `G4-R001`, `G4-R004`, `G4-R006` | **Repeated three times across production and tests.** Architectural review required before another numeric authority is added. |
| `LOCAL_CONSUMPTION_OF_GLOBAL_AUTHORITY` | `RP-09` | Complete retained authority is incorrectly required to appear in, or be consumed by, one local face/path rather than validated globally and witnessed only where selected. | `G4-R002`, `G4-R007` | **Repeated twice.** Review ownership and consumption boundaries together. |
| `EXECUTABLE_COVERAGE_GAP` | `RP-02` | Required counterfactual contracts compile outside the default immutable artifact or are not independently discoverable. | `G4-R003` | Single G4 occurrence; retain artifact-closure checks. |
| `POLICY_STATE_CONFLATION` | `RP-03` | Internal execution state and caller-visible policy use one mutable flag. | `G4-R005` | Single G4 occurrence; keep internal lifetime and public retention separate. |

## Regression entries

### G4-R001 — genuine source boundaries rejected by transition quotient

| Field | Value |
|---|---|
| Classification | product implementation regression |
| First detected | artifact `9024549134`, implementation `7f486632b154a303789df6c4dd44f602c8c71281` |
| Baseline / symptom | Previously accepted plane, seam, close-sheets, and cylinder all failed `3/3` at `InvalidFrontBoundaryAuthority`; producer fell from `124/127` to `99/128`. |
| Root cause | `assign_open_front_boundary_authority()` required an `edge_matching_indices()` entry before classifying a one-face edge, although that index contains only two-face interior edges. Canonical boundary topology and optional interior transition identity were treated as one authority. |
| Cause family | `AUTHORITY_DOMAIN_CONFLATION` |
| Corrective guard | Genuine one-face boundaries carry canonical topology without an invented interior index; two-face transitions retain their separate index authority. |
| Resolution | `resolved` by artifact `9026181778`; direct multi-face seam and the focused boundary/certificate contracts passed. |
| Evidence | `Gate_4_Transition_Quotient_Materialization_And_Retained_Authority_Artifact_Only_Test_Benchmark_Report.md`; `Gate_4_Transition_Quotient_Runtime_Regression_Independent_Design_Review_Report.md` |

### G4-R002 — internal isolation seams required as cell-boundary crossings

| Field | Value |
|---|---|
| Classification | product/contract regression |
| First detected | artifact `9024549134`, implementation `7f486632b154a303789df6c4dd44f602c8c71281` |
| Baseline / symptom | Torus phase-front was `Produced` but stopped at `UnconsumedAuthoritativeIsolationSeam`; all `4/8/4` region/seam/relation authority remained unconsumed. |
| Root cause | Seam consumption was inferred only from `SurfaceTraceSegment::transitionSourceEdges` on output cell-boundary paths. Internal isolation seams are region transport authority and need not cross a selected cell side. |
| Cause family | `LOCAL_CONSUMPTION_OF_GLOBAL_AUTHORITY` |
| Corrective guard | Validate reciprocal seam certificates globally; require a certificate only when cross-sheet transport is selected; never consume by presence or counts. |
| Resolution | `resolved` by the boundary/isolation certificate and canonical-transition artifacts; direct torus later consumed all `4/8/4`. |
| Evidence | `Gate_4_Transition_Quotient_Runtime_Regression_Independent_Design_Review_Report.md`; `Gate_4_Boundary_And_Isolation_Transport_Certificate_Artifact_Only_Test_Benchmark_Report.md` |

### G4-R003 — required quotient counterfactuals absent from immutable artifact

| Field | Value |
|---|---|
| Classification | build/test packaging regression |
| First detected | artifact `9024549134` |
| Baseline / symptom | Required semantic-digest tests existed only in the disabled historical target; several reviewed quotient and retention contracts were not independently discoverable. |
| Root cause | Coverage was added to a target excluded by the default build instead of a packaged executable, and artifact closure was not verified against the review test list. |
| Cause family | `EXECUTABLE_COVERAGE_GAP` |
| Corrective guard | Every mandatory contract must be independently named, discovered in a default packaged executable, and listed during artifact preflight. |
| Resolution | `resolved` in artifact `9026181778`, which exposed all 33 reviewed transition-quotient contracts. |
| Evidence | `Gate_4_Transition_Quotient_Materialization_And_Retained_Authority_Artifact_Only_Test_Benchmark_Report.md` |

### G4-R004 — full-`EF` and compact transition indices serialized as one domain

| Field | Value |
|---|---|
| Classification | product implementation regression |
| First detected | artifact `9026181778`, implementation `82151bf51bce9af9859282b2a03e295a0ee5a309` |
| Baseline / symptom | Plane and close sheets failed `InvalidAuthoritativeTransitionSourceEdge`; cylinder and torus failed `InvalidPeriodicCutAuthority`; only seam remained direct-valid. |
| Root cause | One `int` route field alternated between a full `mesh.EF` row, a source-wide compact two-face index, and potentially a region-local compact index. Materialization always interpreted it as the source-wide compact domain. |
| Cause family | `AUTHORITY_DOMAIN_CONFLATION`; recurrence of `G4-R001` |
| Corrective guard | Store canonical topology separately, validate CrossField authority in its full-`EF` domain, and serialize only the source-wide compact pair beside topology. Never use region-local numbering. |
| Resolution | `resolved` by artifact `9028103772`, implementation `edc14d38f862b94941b249f564050e2e1f8f5287`; plane, seam, close sheets, and cylinder became `3/3`, torus consumed `4/8/4`. |
| Evidence | `Gate_4_Boundary_And_Isolation_Transport_Certificate_Artifact_Only_Test_Benchmark_Report.md`; `Gate_4_Canonical_Transition_Index_And_Failure_Retention_Artifact_Only_Test_Benchmark_Report.md` |

### G4-R005 — internal failure-injection retention leaked into public context

| Field | Value |
|---|---|
| Classification | public contract regression |
| First detected | artifact `9026181778` |
| Baseline / symptom | `retainIntermediateGeometry=false` still returned trace authority whenever deterministic failure injection needed internal state. |
| Root cause | One computed flag controlled both temporary execution lifetime and the caller's public retain/release request. |
| Cause family | `POLICY_STATE_CONFLATION` |
| Corrective guard | Keep `retainForExecution` separate from `retainRequested`; every terminal path publishes context only when requested. |
| Resolution | `resolved` by artifact `9028103772`; the true/false counterfactual reached the same injected failure and retained iff requested. |
| Evidence | `Gate_4_Boundary_And_Isolation_Transport_Certificate_Artifact_Only_Test_Benchmark_Report.md`; `Gate_4_Canonical_Transition_Index_And_Failure_Retention_Artifact_Only_Test_Benchmark_Report.md` |

### G4-R006 — canonical transition tests retained obsolete numeric-domain authority

| Field | Value |
|---|---|
| Classification | test-authority regression |
| First detected | artifact `9028103772` |
| Baseline / symptom | Three new canonical tests selected topology absent from serialized routes; two Phase10 tests used compact values as `mesh.EV` or full-`EF` rows. Their intended materializer assertions were unreachable or invalid. |
| Root cause | Test helpers repeated the production domain conflation and did not prove a real serialized witness before tampering it. |
| Cause family | `AUTHORITY_DOMAIN_CONFLATION`; recurrence of `G4-R001` and `G4-R004` |
| Corrective guard | Record an actual serialized cell/side/segment/route slot, pair compact values with canonical topology, and resolve full-`EF` validation identity only through reciprocal incident faces. |
| Resolution | `test_authority_resolved` by artifact `9029584083`; all seven canonical contracts passed individually. |
| Evidence | `Gate_4_Canonical_Transition_Index_And_Failure_Retention_Artifact_Only_Test_Benchmark_Report.md`; `Gate_4_Canonical_Transition_Test_Authority_Remediation_Artifact_Only_Test_Benchmark_Report.md` |

### G4-R007 — single-relation face-chart projection over-rejects torus

| Field | Value |
|---|---|
| Classification | product implementation regression |
| First detected | artifact `9030700527`, implementation `8f37612148f34bac63cf294000c17c7de2e03b41` |
| Baseline / symptom | Direct torus remained `0/3`; `LocalSheetMismatch` increased from 74 under artifact `9029584083` to 165, rejecting 91 additional faces. Plane, seam, close sheets, and cylinder remained `3/3`. |
| Root cause | The resolver treats a quotient vertex's complete relation graph as a direct star around one scalar representative, requires every retained relation to be consumed by each incident face, and requires a reciprocal peer on that face. The focused two-quad fixture carried only one relation per shared vertex and missed chained and unused production authority. |
| Cause family | `LOCAL_CONSUMPTION_OF_GLOBAL_AUTHORITY`; recurrence of `G4-R002` |
| Corrective guard | Validate complete relation structure and reciprocity globally, derive exact vertex-local graph reachability, and require only the selected face's witness path. Add chained, unused, off-face-peer, missing-link, tamper, ambiguity, isolation, and row-order counterfactuals. |
| Correction | Implementation `6af23d9aeca29e63aa13c4ae49f50d1748939c49` validates the complete relation graph and global reciprocity, derives scalar-rooted vertex-local reachability, intersects reachable face charts uniquely, and consumes only selected witnesses. Four multi-relation counterfactuals compile in artifact `9031804178`. |
| Status | `fix_pending_runtime`; compile artifact `9031804178` is verified, but direct torus and retained runtime acceptance have not run. |
| Evidence | `Gate_4_Torus_Hard_Rail_Face_Chart_Authority_Artifact_Only_Test_Benchmark_Report.md`; `Gate_4_Torus_Multi_Rail_Chart_Reachability_Code_Build_Report.md`; next acceptance `Gate_4_Torus_Multi_Rail_Chart_Reachability_Artifact_Only_Test_Benchmark_Plan.md` |

## Persistent blockers that are not current-patch regressions

| ID | Blocker | Reason kept separate | Current gate |
|---|---|---|---|
| `G4-B001` | Baseline torus `LocalSheetMismatch` (74 issues) | This surfaced after upstream route/quotient repair; it was not introduced by the rejected projection. One scalar `SurfacePoint` loses the complete chart/equivalence authority retained by its quotient class. | Multi-rail reachability must reduce this to strict-valid torus `3/3`; reduced issue count is not acceptance. |
| `G4-B002` | Exact Phase10 torus `InvalidHardRailPairing` | This is an earlier target-size-dependent scheduling defect, not the direct final-validator regression. Independently generated region fronts do not share one source-authoritative hard-rail breakpoint schedule. | Deferred scheduling slice; still gates prescribed sphere. |
| `G4-B003` | Nonzero periodic `Z4` rotation | The producer rejects nonzero accumulated branch matching and hard-codes rotation zero. This is missing capability, not caused by the chart resolver. | Deferred G4 slice. |
| `G4-B004` | Positive multi-isolation quotient witness | The current fixture accepts certificates but does not create a quotient class spanning multiple local sheets. This is missing test authority unless a valid fixture proves production lineage loss. | Deferred focused fixture/implementation slice. |

## Architecture enforcement register — independent review 2026-08-09

This register tracks structural debt found by the documentation-only surface-cell
architecture review. These are not new runtime regression events and do not
change the PR-wide totals of 34 events, 14 categories, or 20 recurrences.
Close an item only when its forbidden representation is removed and the named
focused, metamorphic, and representative evidence passes. A passing torus
artifact may resolve `G4-R007` behaviorally; it does not close this register.

| ID | Severity | Pattern mapping | Structural evidence at `6af23d9` | Required close condition |
|---|---|---|---|---|
| `AR-01` | Critical | `RP-03`, `RP-08` | `SurfacePhaseFrontResult` exposes independently mutable disposition/attempted/succeeded state; pipeline consumers use different fields. | One closed `ProducerOutcome<T>` with exhaustive dispatch; inconsistent states are unrepresentable. |
| `AR-02` | Critical | `RP-01`, `RP-03`, `RP-06`, `RP-07` | Bare integer edge domains and parallel topology/index route vectors remain public. | Strong ID domains and one `CanonicalRoute<TransitionStep>`; checked named conversions only. |
| `AR-03` | High | `RP-01`, `RP-03`, `RP-05` | Generic `SurfaceCellCanonicalIdentity.values` carries unrelated schemas; ownership uses a class ordinal. | Domain-specific semantic keys; no ordinal, row, or backend handle in ownership identity. |
| `AR-04` | High | `RP-06`, `RP-09` | Duplicate chart types and copied region/sheet/topology tables create multiple readable authorities. | One chart type and immutable single-writer authority snapshots referenced by typed IDs. |
| `AR-05` | High | `RP-05`, `RP-07` | Semantic equality/order includes front-edge, patch, local-quad, backend, variant, or primary hash ordering. | Semantic identity separated from representation handles; canonical semantic ordering precedes hashing. |
| `AR-06` | Critical | `RP-01`, `RP-05`, `RP-09` | Validator reconstructs relation endpoints/reachability and returns booleans/sets without the selected proof path. | Producer-owned canonical relation registry and exact `ChartSelectionCertificate` paths independently verified. |
| `AR-07` | Critical | `RP-06`, `RP-09` | Region producers choose hard-rail breakpoints independently and pair them after production. | One global conformity schedule is verified before local construction; exact torus scheduling evidence passes. |
| `AR-08` | High | `RP-03`, `RP-06`, `RP-09` | Aggregate `normalize_scope` overwrites producer component/region/sheet/relation semantics. | Producers construct fully scoped immutable output; aggregation verifies rather than mutates semantics. |
| `AR-09` | High | `RP-01`, `RP-05`, `RP-06` | Source support is reimplemented with tolerance/quantization-derived identity in multiple consumers. | One sanitized exact source-support kernel; tolerance values cannot be topology keys. |
| `AR-10` | Moderate | all | Tracing, arrangement, pipeline, and validation monoliths collapse stage ownership. | Responsibility modules reached incrementally; new behavior enters only through stage APIs. |
| `AR-11` | High | `RP-02`, `RP-03` | The former design mixed normative invariants with several historical “current” authorities. | `DESIGN.md` remains normative-only; status/evidence/handoff records remain separate. |
| `AR-12` | High | `RP-02` | Focused relation fixtures can pass before production emits and consumes the same certificate. | Positive, tamper, metamorphic, packaged-discovery, and representative production evidence all pass. |

Normative replacement architecture and the staged M0–M6 migration are in
`.agents/Directional/DESIGN.md`. Full evidence and the scientific/framework
comparison are in
`.agents/Directional/Surface_Cell_Architecture_Independent_Design_Review_Report.md`.


## Test architecture enforcement register — independent audit 2026-08-09

This register tracks structural test debt found by the documentation-only
test-suite audit. These items are not new runtime regression events and do not
change the PR-wide totals of 34 events, 14 categories, or 20 recurrences.
Close an item only with the T0–T6 evidence named in the audit plan.

The current suite has meaningful local contracts and six direct production
cases. All ten committed SurfaceCells production inputs are triangle-only, so
pre-quad fixtures are not the defect. The missing authority is the complete
intent oracle, direct rich-case gating, generated/fuzz coverage, and
independent package evidence. `TEST_AUTHORITY_COVERAGE_GAP` already records six
events and five recurrences.

| ID | Severity | Pattern mapping | Structural evidence at `6af23d9` | Required close condition |
|---|---|---|---|---|
| `TA-01` | Critical | `RP-02` | Direct acceptance checks backend/no-recovery/nonempty/degree four but not independent topology, lineage, field/feature, approximation, quality, determinism, or work. | T1 independent product oracle and mutation adequacy; full intent gate by T5. |
| `TA-02` | Critical | `RP-02`, `RP-07`, `RP-09` | Six-case direct matrix omits torus, thin bent tube, prescribed sphere, and mechanical feature. | T2 packages/discovers all ten cases with explicit green/known-red status. |
| `TA-03` | Critical | `RP-01`, `RP-02` | `BenchmarkQuality` metrics are observational and reuse production validator/support concepts. | Independent test decision procedures plus approved metric definitions/baselines/thresholds. |
| `TA-04` | High | `RP-01`, `RP-04`, `RP-06`, `RP-07`, `RP-09` | No property library/generator, shrinker, `LLVMFuzzerTestOneInput`, or fuzz target exists. | T3 seed replay/shrinking and T4 sanitizer fuzz/replay accepted. |
| `TA-05` | High | `RP-02` | Focused helper/internal-state evidence can be promoted to product proof. | Every mandatory test declares intent, precondition, production entry, independent oracle, counterexample, and evidence identity. |
| `TA-06` | High | `RP-01`, `RP-02` | Historical tests copied weak numeric domains or constructed impossible witnesses. | Oracle mutation tests and domain-independent fixtures fail for the intended corruption. |
| `TA-07` | High | `RP-02` | Mandatory sources/tests have previously been absent from packaged default executables. | T1/T6 immutable manifest verifies exact executable, discovery name, label, fixture/corpus/seed, and artifact. |
| `TA-08` | High | `RP-02`, `RP-05`, `RP-07` | Raw IDs/order, exact cardinality, hash, and retention lifetime appear as semantic proxies. | Canonical/metamorphic oracles replace proxies unless the value is itself the declared contract. |
| `TA-09` | High | `RP-03`, `RP-04`, `RP-06` | Sequence/reset/cumulative work and resource behavior lack a coherent gate. | Repeated-process and in-process sequence properties gate monotone work, time, RSS, and state reset. |
| `TA-10` | High | `RP-02`, `RP-07`, `RP-09` | Fixture manifest lacks semantic field/topology/feature coverage descriptors. | T2 versioned semantic manifest proves topology, field matching/holonomy/singularities, features, validity class, expected disposition, and budgets. |
| `TA-11` | High | `RP-02` | The suite does not prove that its product oracle detects topology/lineage/geometry/field/quality corruption. | T1/T5 deliberate mutation families are rejected independently. |
| `TA-12` | Moderate | `RP-02`, `RP-03` | `tests/TESTING_STRATEGY.md` mixed normative contracts with artifact history and next-turn state. | Corrected in this review; continuously enforce normative/status separation. |

Normative testing policy is `tests/TESTING_STRATEGY.md`. The complete evidence,
domain-research mapping, and staged redesign are in
`.agents/Directional/Surface_Cell_Test_Suite_Independent_Audit_And_Redesign_Plan.md`.


## Architectural review triggers

An architectural review should be requested when any of these occurs:

1. A cause family reaches two regressions.
2. A resolved regression reappears in a later immutable artifact.
3. A fix moves the same failure downstream without restoring the entering
   accepted matrix.
4. Focused tests pass while a representative direct fixture regresses for a
   state shape absent from those tests.
5. A new bare numeric field carries topology, source-row, compact-index,
   ownership, or semantic identity authority without a typed domain.
6. Planned work touches an `RP-nn` data flow but the mandatory pattern-review
   record does not prove the corrective shape and representative coverage.
7. A mandatory direct test lacks an independently proved fixture precondition,
   semantic oracle, rejected counterexample, or package/seed identity.
8. A focused/helper/property pass is used to close a representative product
   gate, or a known-red direct case is hidden/disabled.
9. A fuzz/property failure cannot be replayed and minimized within its declared
   precondition and resource budget.

The PR-wide rollup shows nine repeated patterns covering 29 events and all 20
recurrences, plus five single-event categories. `AUTHORITY_DOMAIN_CONFLATION`
and `LOCAL_CONSUMPTION_OF_GLOBAL_AUTHORITY` already satisfy trigger 1 in the
current G4 slice. Every future turn must review `RP-01` through `RP-09`; the
independent architectural review is now complete and records `AR-01` through
`AR-12`; any touched open item remains a design stop even if the immediate
torus correction passes. Only `PR8-R034` / `G4-R007` is active
at the audited source head.

The independent test-suite audit records `TA-01` through `TA-12`. These do not
alter historical regression counts. T1 independent test-oracle foundation is
the first mutating turn after the immutable multi-rail artifact closeout; M1
waits for T1 acceptance.
