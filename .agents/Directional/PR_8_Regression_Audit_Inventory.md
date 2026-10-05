# PR #8 Regression Audit Inventory

Status: **repeated-pattern expansion complete from PR head
`8ef353034641c3a068095334ceea5e6ddb0c39c1`**

**Reference note.** The `Milestone_G_P5_*` and `Gate_*` per-turn Test + Benchmark
reports cited below as first evidence were retired from the repository under
`RETENTION_POLICY.md` and `CLEAN_UP_POLICY.md` after their durable facts were
folded into this inventory and `Regression_Root_Cause_Tracker.md`. Those names
are retained here as **historical provenance, not live file pointers** — the
paired commit identity beside each one remains the authority. Do not treat an
unresolved report name in this file as a broken reference, and do not delete the
provenance to make the names resolve.

Audited PR range:
`d8b4dba98747d3adf0ca24002642bcad9e9847db..8ef353034641c3a068095334ceea5e6ddb0c39c1`

Range size: **1,790 commits**

Evidence-bearing result/source range:
`d8b4dba98747d3adf0ca24002642bcad9e9847db..027e5194a9013cc1fe9ea18c1b79741301e40f74`
(**1,789 commits**). Commit `8ef35303` is the documentation-only publication
of the original audit and creates no new runtime event or code pattern.

Audit type: independent documentation-only review plus point-in-time source,
test, and build-pattern analysis; no project binary, test, benchmark,
configure, build, or fixture command was executed.

## Scope and counting rules

The case-insensitive history audit found **114 commits** in the primary
result-document corpus:

- **55** Test + Benchmark report introductions containing `regress*`;
- **34** machine-result or result-summary updates;
- **25** amendments, removals, or other report-lifecycle changes.

Plans, TODOs, handoffs, reviews, and Code + Build reports were corroborating
evidence only. They could explain a runtime event but could not create one.
Likewise, the word *regression* in a passing test name did not create an event.

An inventory event requires at least one of:

1. a baseline-to-candidate loss in runtime or test authority;
2. a newly invalid test/oracle contract;
3. a newly exposed executable or artifact-coverage defect.

Consecutive artifacts showing the same unresolved cause are persistence, not a
new event. A later loss after the affected authority was restored is a
recurrence and receives a new `PR8-Rnnn` ID. Root-cause statements below are
limited to what the report and source at that historical commit proved. A
source-supported inference is labelled as such.

The pattern expansion inspected the exact compiled/source commit named by each
report and the relevant implementation, test, or CMake state at that time. A
pattern ID is assigned only when at least two events demonstrate the same code
shape. Similar failure text alone is insufficient. The complete pseudocode
anti-patterns and required replacement shapes are maintained in
`.agents/Directional/Regression_Root_Cause_Tracker.md`.

One recurring sub-millisecond validator timing observation was excluded from
the event totals because reports repeatedly established scheduler sensitivity
and did not establish a functional regression.

## Category totals

`Recurrences` counts later events in the same category; the first event in a
category is not a recurrence.

| Category | Pattern | Events | Recurrences | Architectural signal |
|---|---|---:|---:|---|
| `AUTHORITY_DOMAIN_CONFLATION` | `RP-01` | 6 | 5 | Typed topology/chart/index domains repeatedly collapsed into one consumer identity. |
| `TEST_AUTHORITY_COVERAGE_GAP` | `RP-02` | 6 | 5 | Tests or packaged executables did not observe the claimed semantic contract. |
| `POLICY_STAGE_STATE_CONFLATION` | `RP-03` | 4 | 3 | One flag/result boundary represented distinct execution, policy, or stage states. |
| `NONTERMINATING_CUMULATIVE_WORK` | `RP-04` | 3 | 2 | Locally bounded work became recursively or cumulatively unbounded. |
| `REPRESENTATION_DEPENDENT_IDENTITY` | `RP-05` | 2 | 1 | Semantically equivalent topology changed identity under ordering/orientation. |
| `STATE_CARDINALITY_GROWTH` | `RP-06` | 2 | 1 | Per-object retention multiplied global state cardinality. |
| `CYCLIC_TOPOLOGY_LINEARIZATION` | `RP-07` | 2 | 1 | A cyclic fan/sector was interpreted as a linear unique-neighbor sequence. |
| `PRODUCER_DISPOSITION_CONFLATION` | `RP-08` | 2 | 1 | `NotApplicable`, `Rejected`, and downstream substitution were not kept distinct. |
| `LOCAL_CONSUMPTION_OF_GLOBAL_AUTHORITY` | `RP-09` | 2 | 1 | Complete global authority was required on one local face/path. |
| `INTRINSIC_SUPPORT_OVERCONSTRAINT` | — | 1 | 0 | One stored chart representative was treated as complete intrinsic support. |
| `INCOMPLETE_TRANSACTIONAL_ROLLBACK` | — | 1 | 0 | A rejected mutation exposed partially modified state. |
| `SHARED_EDGE_ORIENTATION_INVERSION` | — | 1 | 0 | Valid opposite traversal and invalid equal traversal were reversed. |
| `INCOMPLETE_ORBIT_PUBLICATION` | — | 1 | 0 | Valid audited topology was omitted before ownership publication. |
| `EXACT_SIMPLEX_CANONICALIZATION_LOSS` | — | 1 | 0 | Tolerance-expanded construction leaked into exact source-simplex output. |
| **Total** |  | **34** | **20** | |

## Repeated coding-pattern analysis

The nine repeated patterns cover **29 events** and all **20 recurrences**. The
remaining five categories have one event each and remain monitored without a
premature repeated-pattern classification.

| Pattern | Event mapping | Point-in-time code evidence | Repeated finding |
|---|---|---|---|
| `RP-01` | `R007`, `R014`, `R019`, `R028`, `R031`, `R033` | `680d81c` `SurfaceArrangement.cpp`; `f4cce52` `SourceChartTransitions.h`; `7f48663` and `82151bf` `SurfaceCellTracing.cpp`; `edc14d3` transition tests | Consumers guessed numeric/index domains or intersected local labels as if they were intrinsic ownership. |
| `RP-02` | `R004`, `R013`, `R022`, `R024`, `R027`, `R030` | `e31e5ab` `CMakeLists.txt`; `7f48663` `cmake/DirectionalTests.cmake`; `56f8232`, `0279946`, `3ca89ab` Phase10 tests | A proxy, raw ID, lifecycle observation, impossible witness, or nonpackaged test stood in for production semantic authority. |
| `RP-03` | `R006`, `R009`, `R011`, `R032` | `074ec5d` simplification; `9bff7d3` and `82151bf` pipeline; `aa2917e` benchmark | One mode/flag/result encoded independent execution, public policy, availability, or stage meanings. |
| `RP-04` | `R003`, `R010`, `R020` | `1f4c3c2` and `247061b` `PatchDescriptor.cpp`; P5-TB39 process-isolation evidence | Per-loop/depth limits did not bound recursive, nested, or process-cumulative work globally. `R020`'s exact retaining producer remains unproven. |
| `RP-05` | `R016`, `R026` | `f5305ad` `SurfaceArrangement.cpp`; `3ca89ab` `SurfaceCellTracing.cpp` | Identity and emission order depended on exterior/twin role, traversal orientation, structural hash, or component emission order. |
| `RP-06` | `R001`, `R008` | `d4c1bce` ownership snapshot; `94bf834` arrangement/ownership sources | Complete shared ownership membership was duplicated per completion/cell consumer. |
| `RP-07` | `R017`, `R018` | `ec44ab7` and `2444c38` `SurfaceArrangement.cpp` | Degree-two duplicate neighbor values and first-to-last wrap were rejected because cyclic sectors were treated as a linear list. |
| `RP-08` | `R021`, `R025` | `21f081b` pipeline; `3ca89ab` tracing aggregator | Typed producer disposition was reduced to `succeeded` or a default aggregate, enabling generic substitution after authoritative rejection. |
| `RP-09` | `R029`, `R034` | `7f48663` quotient/materialization flow; `8f37612` validator | Complete seam/relation authority was required to occur on every selected local path/face rather than globally validated and locally witnessed. |

### Cross-pattern architectural concentration

Five higher-level practices account for the nine patterns:

1. **Producer contracts lose type or scope at consumer boundaries** —
   `RP-01`, `RP-08`, and `RP-09`.
2. **Validation universally quantifies at the wrong ownership level** —
   `RP-01` and `RP-09`.
3. **State is compressed into a boolean/row/hash before semantics are fixed** —
   `RP-03`, `RP-05`, and `RP-08`.
4. **Local safety arguments are mistaken for global bounds** — `RP-04` and
   `RP-06`.
5. **Tests mirror representation rather than the intended invariant** —
   `RP-02`, with `RP-01` recurring directly inside test helpers.

These are architecture-review inputs, not additional event categories. Their
counts are not added to the 34-event or 20-recurrence totals.

## Event inventory

### PR8-R001 — ownership diagnostics multiply retained state

- **First evidence:** `8002ded548a685e2fec3374534bd5f0afb4b0db6`,
  `Milestone_G_P5_Test_Benchmark_Report.md`.
- **Test/runtime delta:** random-bunny peak working set rose from
  `749,375,488 B` to about `1,696,000,000 B` (**+126.32%**); completion time
  rose **51.57%**.
- **Contemporaneous cause:** exact ownership identity was retained per
  completion object without compact shared storage. The report treated the
  attribution as sufficient for a performance regression while keeping the
  duplicate-quad correctness blocker separate.
- **Category / recurrence:** `STATE_CARDINALITY_GROWTH`; first event.
- **Disposition:** resolved through successive ownership compaction; later
  face-edge checkpoints were below the original baseline.

### PR8-R002 — stored chart face rejects valid intrinsic source support

- **First evidence:** `c46aa49ea6a0cb74221c1768790c28af7d203e96`,
  `Milestone_G_P5_Source_Support_Test_Benchmark_Report.md`.
- **Test/runtime delta:** three valid cylinder shared-boundary contracts
  regressed and production failed `CompletionOwnershipSourceSupportEscape`.
- **Contemporaneous cause:** `validate_completion_domain_ownership()` required
  the scalar `SurfacePoint.face` to be a literal patch face. A point on a
  source edge or vertex is intrinsically supported by all incident faces.
- **Category / recurrence:** `INTRINSIC_SUPPORT_OVERCONSTRAINT`; single event.
- **Disposition:** resolved by intrinsic source-entity support checks; the
  corrected ownership/fixture scope later passed `296/296`.

### PR8-R003 — recursive whole-complex repair is nonterminating

- **First evidence:** `e8e1b3d15c1165aa4f242c70cd2519b5ba7b946d`,
  `Milestone_G_P5_Structural_Repair_Test_Benchmark_Report.md`.
- **Test/runtime delta:** two random-bunny processes hit the 60-second guard at
  about `2.74 GB`, despite the authoritative focused suites passing `296/296`.
- **Contemporaneous cause:** each candidate recursively copied and recomputed
  the whole complex under a depth-local limit; there was no global work ledger
  or canonical-state memoization.
- **Category / recurrence:** `NONTERMINATING_CUMULATIVE_WORK`; first event.
- **Disposition:** resolved by a shared bounded controller and global candidate
  ledger; subsequent runs terminated fail-closed.

### PR8-R004 — passing tests do not execute structural repair

- **First evidence:** `e8e1b3d15c1165aa4f242c70cd2519b5ba7b946d`,
  `Milestone_G_P5_Structural_Repair_Test_Benchmark_Report.md`.
- **Authority delta:** the full focused inventory passed while no test invoked
  and asserted `BoundarySectorSubdivision` through
  `complete_surface_cell_complex()` or its structural-attempt ledger.
- **Contemporaneous cause:** coverage stopped at stitch-time classification and
  did not package a non-vacuous production repair scenario.
- **Category / recurrence:** `TEST_AUTHORITY_COVERAGE_GAP`; first event.
- **Disposition:** resolved by direct whole-complex budget/ledger fixtures and
  explicit preconditions, even when the producer itself remained fail-closed.

### PR8-R005 — rejected side repair returns mutated rollback state

- **First evidence:** `760cd187a24005380058e6119db2b55e12e54d44`,
  `Milestone_G_P5_TB12_Memory_Frontier_Test_Benchmark_Report.md`.
- **Test/runtime delta:** descriptor-dependent tests regressed to empty output
  and production failed `InvalidArrangementDomainIdentity` before descriptor
  acceptance.
- **Contemporaneous cause:** the failure path moved `sideRepair.complex` into
  `preparedComplex` after the transaction had mutated it, instead of restoring
  the committed `parityRepair.complex`.
- **Category / recurrence:** `INCOMPLETE_TRANSACTIONAL_ROLLBACK`; single event.
- **Disposition:** resolved by exact committed-state rollback; the real
  side-repair rollback contract passed in P5-TB15.

### PR8-R006 — simplification policy suppresses fixed-point refresh

- **First evidence:** `c960dc42101fe473cecd3f8416b8fba7a103609d`,
  `Milestone_G_P5_TB13_Rollback_Integrity_Test_Benchmark_Report.md`.
- **Test/runtime delta:** two established Phase 17 fixed-point contracts
  regressed after candidate refresh was limited to `topologyHealingOnly`.
- **Contemporaneous cause:** an internal policy/mode branch silently changed
  the documented default explicit-candidate API behavior.
- **Category / recurrence:** `POLICY_STAGE_STATE_CONFLATION`; first event.
- **Disposition:** resolved by restoring dependency-bounded default refresh;
  Phase 14–18 returned to `230/230` in P5-TB14.

### PR8-R007 — component ownership is conflated with local-sheet intersection

- **First evidence:** `84518e5d67c5e2ce2530556f33d073d1fe6e1411`,
  `Milestone_G_P5_TB17_Parity_Reuse_Output_Memory_Test_Benchmark_Report.md`.
- **Test/runtime delta:** twelve Phase 16/17 and Milestone D contracts regressed
  from the P5-TB16 baseline.
- **Contemporaneous cause:** the arrangement change required one strict
  `(component, local-sheet)` intersection across every boundary provenance
  record. Exact-adjacent traces may cross local chart labels while remaining
  in one source component.
- **Category / recurrence:** `AUTHORITY_DOMAIN_CONFLATION`; first event in this
  category.
- **Disposition:** resolved by canonical intrinsic ownership construction;
  Phase 14–18 later returned to a clean baseline.

### PR8-R008 — ownership class membership is duplicated quadratically

- **First evidence:** `6b75ee51a06a227ce36455e18e93bd5c067fba6d`,
  `Milestone_G_P5_TB18_Canonical_Ownership_Output_Memory_Test_Benchmark_Report.md`.
- **Test/runtime delta:** face-edge bunny reached `2.51 GB`; smooth bunny was
  killed at `3.80 GB` before writing JSON.
- **Contemporaneous cause:** every cell serialized every chart member of its
  component-wide ownership class, multiplying roughly
  `cell count × component face count` across rollback, descriptors, and caches.
- **Category / recurrence:** `STATE_CARDINALITY_GROWTH`; recurrence of
  `PR8-R001`.
- **Disposition:** resolved by one interned class-membership registry plus
  fixed-size per-cell class keys; the next smooth checkpoint completed at
  about `451 MB`.

### PR8-R009 — real completion validation preempts injected stage authority

- **First evidence:** `25f7ecc98c9860220c809d671d39d4a52e895161`,
  `Milestone_G_P5_TB19_Ownership_Compaction_Topology_Output_Test_Benchmark_Report.md`.
- **Test/runtime delta:** GP23/GP24/Phase20 injection and fallback-lineage tests
  regressed because a newly inserted completion validation stopped before the
  declared optimization or validation stage.
- **Contemporaneous cause:** real producer validity and synthetic injected-stage
  policy shared one terminal-stage path; the earlier real failure overwrote
  the intended test-stage disposition.
- **Category / recurrence:** `POLICY_STAGE_STATE_CONFLATION`; recurrence of
  `PR8-R006`.
- **Disposition:** resolved by the later design-aligned producer/stage boundary;
  obsolete injection expectations were not used to weaken real validation.

### PR8-R010 — alternative completion work makes the suite nonterminating

- **First evidence:** `f7e81f767e6ea52144fc118ec9ca9525c79852fd`,
  `Milestone_G_P5_TB21_Artifact_Only_Test_Benchmark_Report.md`.
- **Test/runtime delta:** the unfiltered suite exceeded 20 minutes; a second
  selection still exceeded 15 minutes, and a fourth face-edge repeat did not
  complete in the remaining batch window.
- **Contemporaneous cause:** source inspection and typed ledgers placed the
  cumulative work in repeated completion alternatives, not a correctness pass.
- **Category / recurrence:** `NONTERMINATING_CUMULATIVE_WORK`; recurrence of
  `PR8-R003`.
- **Disposition:** resolved by topology-derived bounded alternative budgets;
  P5-TB22 completed all 600 tests and four-run bunny repetitions.

### PR8-R011 — an empty ownership sample is reported as available

- **First evidence:** `a5ad1a1cfcc73509a6e69d6899d36553e0d04d38`,
  `Milestone_G_P5_TB22_Artifact_Only_Test_Benchmark_Report.md`.
- **Test/runtime delta:** every result reported
  `sameSampleOwnershipMeasurementAvailable=true` while categorized owned bytes
  were zero and coverage was 0%.
- **Contemporaneous cause:** sampler completion and a meaningful ownership
  sample used the same availability state.
- **Category / recurrence:** `POLICY_STAGE_STATE_CONFLATION`; recurrence of
  `PR8-R006` and `PR8-R009`.
- **Disposition:** resolved/superseded by truthful availability semantics in
  the design-aligned runtime records.

### PR8-R012 — shared-edge orientation predicate is inverted

- **First evidence:** `02c824985dc422050c3be287b4d2076c3b455ab0`,
  `Milestone_G_P5_TB23_Artifact_Only_R0_R1_Test_Benchmark_Report.md`.
- **Test/runtime delta:** valid manifold adjacency was rejected, same-direction
  winding was accepted, Phase 14–18 fell to `233/242`, and the bounded suite
  exposed 50 failures.
- **Contemporaneous cause:** the predicate accepted equal traversal directions
  across a shared edge; consistently oriented incident faces traverse it in
  opposite directions.
- **Category / recurrence:** `SHARED_EDGE_ORIENTATION_INVERSION`; single event.
- **Disposition:** resolved in P5-R1C; all `SourceChartTransitionsR1` and source
  validator contracts passed.

### PR8-R013 — requested validator contracts are absent from the artifact

- **First evidence:** `02c824985dc422050c3be287b4d2076c3b455ab0`,
  `Milestone_G_P5_TB23_Artifact_Only_R0_R1_Test_Benchmark_Report.md`.
- **Authority delta:** required `SourceAuthoritativeMeshValidatorPhase22`
  contracts existed only in dedicated Milestone F executables, not in the
  packaged four-target artifact.
- **Contemporaneous cause:** the artifact source list did not include the
  validator test source in `directional_phase1_tests`.
- **Category / recurrence:** `TEST_AUTHORITY_COVERAGE_GAP`; recurrence of
  `PR8-R004`.
- **Disposition:** resolved in the next artifact, which exposed and passed the
  six validator contracts.

### PR8-R014 — local-sheet inequality incorrectly splits exact adjacency

- **First evidence:** `f65485055434b3e589cf7be121c19129fe089a42`,
  `Milestone_G_P5_TB24_Artifact_Only_R1C_Test_Benchmark_Report.md`.
- **Test/runtime delta:** completion alias, adjacent ownership-class, and bunny
  fan-rotation contracts remained red after the orientation correction.
- **Contemporaneous cause:** `SourceChartTransitionGraph::build()` required
  equal local-sheet labels across a valid manifold edge. Local sheets protect
  geometric capture; they do not override exact source adjacency within one
  source component.
- **Category / recurrence:** `AUTHORITY_DOMAIN_CONFLATION`; recurrence of
  `PR8-R007`.
- **Disposition:** resolved in P5-R1D; graph-dependent and feature-rail scopes
  passed and Phase 14–18 reached `247/247`.

### PR8-R015 — valid successor orbits are omitted before cell publication

- **First evidence:** `671e1ba3b44b4996c41728b1d374b701167e8a8a`,
  `Milestone_G_P5_TB26_Artifact_Only_R2_Test_Benchmark_Report.md`.
- **Test/runtime delta:** Phase 14–18 fell from `247/247` to `227/240`; valid
  boundary, disconnected, fan, hard-rail, and cylinder halfedges retained
  `cell == -1`.
- **Contemporaneous cause:** cell ownership was committed only for one
  `auditedCycles` inventory; valid boundary/support orbit classes were rejected
  or omitted before transactional publication.
- **Category / recurrence:** `INCOMPLETE_ORBIT_PUBLICATION`; single event.
- **Disposition:** resolved/superseded through the R2C–R2E producer sequence;
  later accepted artifacts restored complete ownership for the prior valid
  consumers while keeping genuine invalid orbits fail-closed.

### PR8-R016 — directed-incidence identity depends on mesh orientation

- **First evidence:** `ad92fe61717665ea4cbc50b9f8c60e047949033f`,
  `Milestone_G_P5_TB30_Artifact_Only_R2E2_Test_Benchmark_Report.md`.
- **Test/runtime delta:** the suite lost one previously passing whole-mesh
  orientation-reversal contract; forward and reversed incidence hashes differed
  despite valid equivalent topology.
- **Contemporaneous cause:** exterior and twin records were hashed through
  different directed encodings; reversing the mesh swapped their roles.
- **Category / recurrence:** `REPRESENTATION_DEPENDENT_IDENTITY`; first event.
- **Disposition:** resolved in P5-R2E3 by canonical paired-boundary identity.

### PR8-R017 — degree-two cyclic adjacency is treated as contradictory

- **First evidence:** `49fff75caf71db6c01c32036fe766e8fd2b218ad`,
  `Milestone_G_P5_TB32_Artifact_Only_R2E4_Test_Benchmark_Report.md`.
- **Test/runtime delta:** 21 prior tests regressed; ordinary degree-two boundary
  nodes failed `BoundaryRotationalSystemConflict`.
- **Contemporaneous cause:** in a two-ray cycle the predecessor and successor
  ray IDs are the same opposite ray. The code interpreted the two valid sectors
  as contradictory duplicate matches.
- **Category / recurrence:** `CYCLIC_TOPOLOGY_LINEARIZATION`; first event.
- **Disposition:** resolved in P5-R2E5; all 21 regressions were restored.

### PR8-R018 — cyclic fan wrap is rejected as a linear interval

- **First evidence:** `38d128c0e759e5dfa504e321b29eabff6eb637d2`,
  `Milestone_G_P5_TB34_Artifact_Only_R2E6_Test_Benchmark_Report.md`.
- **Test/runtime delta:** six Phase 17 contracts regressed after they had been
  restored by the degree-two fix.
- **Contemporaneous cause:** the ordered fan vector was treated as linear and
  every first-to-last intrinsic sector was rejected, although one legitimate
  source-interior sector crosses that cyclic wrap.
- **Category / recurrence:** `CYCLIC_TOPOLOGY_LINEARIZATION`; recurrence of
  `PR8-R017`.
- **Disposition:** resolved in the accepted R2E8 checkpoint; the six consumers
  returned to their prior passing state without Phase 17 changes.

### PR8-R019 — normalized pair ownership is re-gated by raw fan identity

- **First evidence:** `b41276f0aa124750fcadbccbff4aa23f2b483235`,
  `Milestone_G_P5_TB37_Artifact_Only_R2E9_Test_Benchmark_Report.md`.
- **Test/runtime delta:** planar and hard-rail targets moved backward from
  post-publication failures to `BoundaryFanSectorCoverConflict`; six naturally
  restored Phase 17 tests regressed again.
- **Contemporaneous cause:** source inspection showed canonical pairs were
  normalized by entity/root, but witness reconciliation still required exact
  original fan-identity variants. Equivalent provenance became a second
  ownership domain.
- **Category / recurrence:** `AUTHORITY_DOMAIN_CONFLATION`; recurrence of
  `PR8-R007` and `PR8-R014`.
- **Disposition:** superseded by the later design-aligned producer boundary;
  the unresolved pair-local micro-repair line was not treated as production
  authority.

### PR8-R020 — cumulative suite state stalls the bunny case

- **First evidence:** `737c4cd184fd7fcdfaa7bcbb5df7de9c4e013bf1`,
  `Milestone_G_P5_TB39_Artifact_Only_R2E11_Test_Benchmark_Report.md`.
- **Test/runtime delta:** two single-process full-suite attempts stopped making
  progress when P27 entered bunny after prior suite state, while isolated P27
  processes completed in about 23 seconds.
- **Contemporaneous cause:** exact producer was not proven; evidence bounded the
  defect to cumulative process state and explicitly kept split correctness
  inventory separate from nontermination evidence.
- **Category / recurrence:** `NONTERMINATING_CUMULATIVE_WORK`; recurrence of
  `PR8-R003` and `PR8-R010`.
- **Disposition:** not reproduced in P5-TB42, whose single-process `625`-test
  run completed and agreed with the split inventory.

### PR8-R021 — seam transport makes the accepted plane fall through generically

- **First evidence:** `1a72073db04d440758ed1ddb23e3dfbf2fe1e7bb`,
  `Gate_2_Cross_Chart_Mandatory_Fixtures_Artifact_Only_Test_Benchmark_Report.md`.
- **Test/runtime delta:** the newly direct-valid seam passed, but the already
  accepted plane regressed from 64 direct quads to the old `106/9/12` generic
  path with 15 validation failures.
- **Contemporaneous cause:** later review showed authoritative phase-front
  non-success fell through to generic tracing/completion and downstream stages
  overwrote the typed producer reason; an attempted metadata-empty branch was
  unreachable on the finalized production field.
- **Category / recurrence:** `PRODUCER_DISPOSITION_CONFLATION`; first event.
- **Disposition:** resolved by the exact authoritative producer boundary;
  plane and seam both returned deterministic strict-valid 64-quad output.

### PR8-R022 — row-order test compares raw DCEL edge IDs

- **First evidence:** `4b2b01e6adc669eadd95965088eacf15ee3ead9e`,
  `Gate_3_Periodic_Cylinder_Artifact_Only_Test_Benchmark_Report.md`.
- **Authority delta:** the row-reversal test failed although both raw routes
  mapped through each mesh's EV table to the same ordered canonical endpoint
  route and cut.
- **Contemporaneous cause:** DCEL edge rows are allocated by face-enumeration
  encounter order; the oracle asserted representation IDs rather than source
  topology.
- **Category / recurrence:** `TEST_AUTHORITY_COVERAGE_GAP`; recurrence of
  `PR8-R004` and `PR8-R013`.
- **Disposition:** `test_authority_resolved` by canonical endpoint-route
  comparison; production code was not weakened.

### PR8-R023 — tolerance-expanded chart tails escape exact simplex authority

- **First evidence:** `f3295829b25291add92bf94f0b6e9d780706f288`,
  `Gate_3_Periodic_Ring_Correspondence_Artifact_Only_Test_Benchmark_Report.md`.
- **Test/runtime delta:** six nominal periodic contracts regressed and cylinder
  moved from `Produced` to `Rejected/InvalidPeriodicChart` at cell 29.
- **Contemporaneous cause:** tolerant clipping emitted its expanded endpoints
  instead of snapping them to exact simplex boundaries. Microscopic tails then
  appeared as overlap beyond a shared source vertex.
- **Category / recurrence:** `EXACT_SIMPLEX_CANONICALIZATION_LOSS`; single
  event.
- **Disposition:** resolved upstream by endpoint canonicalization; strict
  overlap validation remained unchanged and cylinder became strict-valid.

### PR8-R024 — field-correspondence oracle requires an impossible edge witness

- **First evidence:** `25120446082f5500cd7b249e32b9f0e6f630e946`,
  `Gate_3_Periodic_Chart_Endpoint_Canonicalization_Artifact_Only_Test_Benchmark_Report.md`.
- **Authority delta:** production cylinder was direct strict-valid, but one test
  required a V edge whose endpoints were distinct exact source-ring vertices.
  Target size split every source interval into two, so no such edge could exist.
- **Contemporaneous cause:** witness cardinality depended on subdivision rather
  than source-attached field transport.
- **Category / recurrence:** `TEST_AUTHORITY_COVERAGE_GAP`; recurrence of
  `PR8-R004`, `PR8-R013`, and `PR8-R022`.
- **Disposition:** `test_authority_resolved` by inspecting every nonzero
  source-attached V path segment; all 17 G0-G3 contracts passed.

### PR8-R025 — embedded relief rejection becomes generic substitution

- **First evidence:** `5abf60bdb90a012f2a7a2c563bc1785002749573`,
  `Gate_4_Source_Topology_Region_Isolation_Sheet_Decoupling_Artifact_Only_Test_Benchmark_Report.md`.
- **Test/runtime delta:** the retained relief-guidance contract regressed.
  Embedded barriers split producer domains into unsupported children; an
  all-`NotApplicable` aggregate launched generic traces instead of failing
  closed.
- **Contemporaneous cause:** child applicability and parent-domain rejection
  were collapsed during producer aggregation.
- **Category / recurrence:** `PRODUCER_DISPOSITION_CONFLATION`; recurrence of
  `PR8-R021`.
- **Disposition:** resolved by authoritative parent-domain disposition and
  retained in later focused groups.

### PR8-R026 — close-sheet identity depends on component emission order

- **First evidence:** `5abf60bdb90a012f2a7a2c563bc1785002749573`,
  `Gate_4_Source_Topology_Region_Isolation_Sheet_Decoupling_Artifact_Only_Test_Benchmark_Report.md`.
- **Test/runtime delta:** strict-valid close sheets retained identical vertex
  and face-geometry multisets, but the accepted hash changed because the two
  components were emitted in reverse order.
- **Contemporaneous cause:** the topology-region aggregator sorted by structural
  hash before canonical source vertices, unlike the accepted sheet aggregator.
- **Category / recurrence:** `REPRESENTATION_DEPENDENT_IDENTITY`; recurrence of
  `PR8-R016`.
- **Disposition:** resolved by restoring canonical source-authoritative region
  ordering in later accepted G0-G3 matrices.

### PR8-R027 — torus topology test depends on retention timing

- **First evidence:** `5abf60bdb90a012f2a7a2c563bc1785002749573`,
  `Gate_4_Source_Topology_Region_Isolation_Sheet_Decoupling_Artifact_Only_Test_Benchmark_Report.md`.
- **Authority delta:** the test failed first on `hasTraceNetwork` even though
  typed diagnostics proved its intended topology-region/isolation-seam
  contract. Materialization failed before the network was moved to retained
  context.
- **Contemporaneous cause:** an intermediate-retention timing assertion was
  over-coupled to a topology/seam oracle.
- **Category / recurrence:** `TEST_AUTHORITY_COVERAGE_GAP`; recurrence of prior
  test-authority events.
- **Disposition:** `test_authority_resolved` by asserting typed topology/seam
  authority at its actual lifetime boundary.

### PR8-R028 / G4-R001 — genuine source boundaries require an interior index

- **First evidence:** `a2d2b0ae60e7684decdcca526f9f94365befd8c3`,
  `Gate_4_Transition_Quotient_Materialization_And_Retained_Authority_Artifact_Only_Test_Benchmark_Report.md`.
- **Test/runtime delta:** plane, seam, close sheets, and cylinder all regressed
  `3/3` at `InvalidFrontBoundaryAuthority`; producer fell to `99/128`.
- **Contemporaneous cause:** one-face canonical boundary topology was required
  to have an `edge_matching_indices()` entry even though that domain contains
  only two-face interior edges.
- **Category / recurrence:** `AUTHORITY_DOMAIN_CONFLATION`; recurrence.
- **Disposition:** resolved by artifact `9026181778`; see tracker `G4-R001`.

### PR8-R029 / G4-R002 — every isolation seam must occur on a cell boundary

- **First evidence:** `a2d2b0ae60e7684decdcca526f9f94365befd8c3`,
  same transition-quotient report and the mandatory review.
- **Test/runtime delta:** torus reached `Produced` but failed
  `UnconsumedAuthoritativeIsolationSeam`; all `4/8/4` authority remained
  unconsumed.
- **Contemporaneous cause:** global reciprocal seam authority was consumed only
  by presence on selected local cell-side routes.
- **Category / recurrence:** `LOCAL_CONSUMPTION_OF_GLOBAL_AUTHORITY`; first
  event.
- **Disposition:** resolved by global certificate validation and selected-path
  witnesses; see tracker `G4-R002`.

### PR8-R030 / G4-R003 — quotient counterfactuals are not executable

- **First evidence:** `a2d2b0ae60e7684decdcca526f9f94365befd8c3`,
  same transition-quotient report.
- **Authority delta:** required digest, relation, isolation, malformed-incidence,
  and retention counterfactuals were absent from default packaged executables.
- **Contemporaneous cause:** tests were added to a disabled historical target or
  were never exposed as independently discoverable contracts.
- **Category / recurrence:** `TEST_AUTHORITY_COVERAGE_GAP`; recurrence.
- **Disposition:** resolved in artifact `9026181778`, which exposed all 33
  reviewed contracts; see tracker `G4-R003`.

### PR8-R031 / G4-R004 — full-EF and compact route indices share one integer

- **First evidence:** runtime artifact `9026181778`, recorded in
  `Gate_4_Boundary_And_Isolation_Transport_Certificate_Artifact_Only_Test_Benchmark_Report.md`
  (`6210522950a7167bd24c4e8ae11eb68f4f32ecca`).
- **Test/runtime delta:** plane/close sheets failed transition-source identity;
  cylinder/torus failed periodic-cut authority.
- **Contemporaneous cause:** one route field alternated among full `mesh.EF`,
  source-wide compact two-face, and region-local compact domains.
- **Category / recurrence:** `AUTHORITY_DOMAIN_CONFLATION`; recurrence.
- **Disposition:** resolved by artifact `9028103772`; see tracker `G4-R004`.

### PR8-R032 / G4-R005 — execution retention leaks into public retention

- **First evidence:** artifact `9026181778`, same boundary/certificate report.
- **Test/runtime delta:** `retainIntermediateGeometry=false` still returned
  trace authority whenever deterministic failure injection needed it internally.
- **Contemporaneous cause:** one computed flag controlled temporary execution
  lifetime and caller-visible retention policy.
- **Category / recurrence:** `POLICY_STAGE_STATE_CONFLATION`; recurrence.
- **Disposition:** resolved by artifact `9028103772`; see tracker `G4-R005`.

### PR8-R033 / G4-R006 — canonical tests preserve obsolete numeric domains

- **First evidence:** `7347fd9b2d0f3b5dee2cd279081d132ea2b24dd4`,
  `Gate_4_Canonical_Transition_Index_And_Failure_Retention_Artifact_Only_Test_Benchmark_Report.md`.
- **Authority delta:** three canonical tests tampered topology absent from
  serialized routes; two Phase10 tests interpreted compact values as full-EF
  rows or source-edge endpoints.
- **Contemporaneous cause:** test helpers repeated the production numeric-domain
  conflation and did not first prove a real serialized witness.
- **Category / recurrence:** `AUTHORITY_DOMAIN_CONFLATION`; recurrence.
- **Disposition:** `test_authority_resolved` by artifact `9029584083`; see
  tracker `G4-R006`.

### PR8-R034 / G4-R007 — local face consumes the complete multi-rail graph

- **First evidence:** `a011b361091b5ca212a84e92809cc8625c56d1d0`,
  `Gate_4_Torus_Hard_Rail_Face_Chart_Authority_Artifact_Only_Test_Benchmark_Report.md`.
- **Test/runtime delta:** all focused face-chart contracts passed, but direct
  torus stayed `0/3` and `LocalSheetMismatch` increased from 74 to **165**.
- **Contemporaneous cause:** the resolver treated complete quotient-retained
  relations as a direct scalar-centered star, required each relation on every
  incident face, and required the reciprocal peer on that face. The synthetic
  fixture contained only one relation and missed chained/unused authority.
- **Category / recurrence:** `LOCAL_CONSUMPTION_OF_GLOBAL_AUTHORITY`; recurrence
  of `PR8-R029`.
- **Disposition:** **`fix_pending_runtime`**. Implementation
  `6af23d9aeca29e63aa13c4ae49f50d1748939c49` compiles in verified artifact
  `9031804178`, but immutable runtime acceptance has not run. See tracker
  `G4-R007`.

## Persistence and exclusions

The following were reviewed but did not create additional event IDs:

- repeated reports of the same unresolved route/reuse, cylinder, sphere,
  bunny/vase, completion, or validator-timing blocker;
- signal-11 and later timeout observations whose contemporaneous reports did
  not establish a distinct baseline loss independent of an already inventoried
  transaction/cardinality/nontermination event;
- missing-fixture-path transport incidents corrected by runtime-only symlinks;
- invalid fixtures documented and corrected before they could establish their
  stated semantic scenario;
- deeper typed failures exposed after an upstream correction when no previously
  accepted behavior was lost;
- plans or reviews that described regression risk without runtime evidence.

Only `PR8-R034` / `G4-R007` remains active at the audited head. Compile success
does not resolve it; the artifact-only acceptance plan remains authoritative.
