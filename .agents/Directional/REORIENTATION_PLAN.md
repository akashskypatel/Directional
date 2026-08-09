# Directional Surface-Cell Reorientation Plan

**Status:** authoritative architecture-migration roadmap  
**Reviewed implementation:** `6af23d9aeca29e63aa13c4ae49f50d1748939c49`  
**Architecture-review planning baseline:** `dfa77fa6bda44b51454f0189d65a97086aaba049`  
**Decision:** **changes required before architecture expansion**  
**Last updated:** 2026-08-09 UTC

Repository authority: `akashskypatel/Directional`, branch
`agent/surface_cell_quad/p5-recover-bridge-healing`, draft PR #8. Keep the PR
open, draft, and unmerged throughout this migration.

## 1. Purpose and authority

This plan converts the independent architecture review into an ordered,
verifiable migration from the current behavioral implementation to the
normative architecture in `.agents/Directional/DESIGN.md`.

It owns migration order, dependencies, stop conditions, and acceptance gates.
It does not redefine architecture or runtime evidence:

| Concern | Authority |
|---|---|
| Normative product, domains, stages, and invariants | `.agents/Directional/DESIGN.md` |
| Findings and scientific comparison | `.agents/Directional/Surface_Cell_Architecture_Independent_Design_Review_Report.md` |
| Normative testing policy | `tests/TESTING_STRATEGY.md` |
| Test-audit findings and T0–T6 redesign | `.agents/Directional/Surface_Cell_Test_Suite_Independent_Audit_And_Redesign_Plan.md` |
| Current turn and exact next action | `TODO`, `MILESTONE_G_TODO.md`, and `.agents/Directional/Future_Chat_Session_Handoff.md` |
| Regression history and repeated code shapes | `.agents/Directional/Regression_Root_Cause_Tracker.md` |
| Immutable build/runtime evidence | the applicable dated plan and report |

If this roadmap conflicts with `DESIGN.md`, the design wins and this file must
be corrected before implementation. A dated runtime report may update current
status, but it cannot waive a migration invariant.

## 2. Corrected orientation

Product gates and architecture migration are separate progress axes. Passing a
fixture does not close structural debt, and completing a migration slice does
not by itself pass a product gate.

```text
Product:
G0 truthful authority [accepted baseline]
-> G1 uniform phase-front plane [accepted baseline]
-> G2 cross-chart / close-sheet isolation [accepted baseline]
-> G3 periodic holonomy [accepted baseline]
-> G4 topology-distinct completion and singularities [active]
-> G5 adaptivity and hard features [blocked]
-> G6 bunny and vase production success [blocked]
-> G7 hardening/default-on [blocked]

Architecture:
M0 preserve immutable evidence [next]
-> M1 authority kernel and adapters
-> M2 closed outcomes and single-writer snapshots
-> M3 global conformity plan
-> M4 certificate-carrying chart and quotient relations
-> M5 occurrence, embedding, and independent verification split
-> M6 retire legacy representations and decompose ownership modules

Testing:
T0 independent audit and authority separation [complete]
-> T1 independent oracle/package foundation
-> T2 complete direct corpus and semantic manifest
-> T3 property/metamorphic generation and shrinking
-> T4 sanitizer fuzzing and minimized replay
-> T5 calibrated representative quality/corpus gates
-> T6 CI, resource, and oracle-adequacy hardening
```

The current implementation is behavioral comparison authority and migration
input only. It is not an approved foundation for new nonzero holonomy,
adaptivity, prescribed-singularity completion, or other feature growth.

## 3. Immediate M0 checkpoint

The next turn remains the already authorized artifact-only Test + Benchmark:

`.agents/Directional/Gate_4_Torus_Multi_Rail_Chart_Reachability_Artifact_Only_Test_Benchmark_Plan.md`

Use exactly:

| Evidence | Authority |
|---|---|
| Implementation | `6af23d9aeca29e63aa13c4ae49f50d1748939c49` |
| Compile artifact | `9031804178` |
| Compile artifact SHA-256 | `27d16f485c357a236ffd43ce09c335bd246cb3f276cd9cc85b572ca543d87e9e` |
| Log artifact | `9031804382` |
| Log artifact SHA-256 | `5d0b8d0defa3fc371d71160e1db266d3df8037e14c87cf64181b51637cb8a905` |
| Recursive manifest | **49/49**, `2fec5670eb81972233c52c9db1afe82e7eb92da812f1ab537a018bb0d31fb7e2` |

M0 permits no source, test, fixture, validator, manifest, CMake, benchmark, or
workflow edit; no configure, rebuild, relink, or artifact substitution is
allowed.

Classify the result without changing migration order:

- a complete direct torus pass resolves `G4-R007` behaviorally only;
- persistence updates `G4-R007`; it does not create a duplicate event;
- a new regression requires direct evidence and the tracker classification
  rules;
- pass or fail, T1 independent test-oracle foundation is the first subsequent
  mutating turn; M1 follows only after T1 immutable acceptance;
- the separate target-size-dependent `InvalidHardRailPairing` blocker still
  prevents prescribed-sphere work until M3 supplies one shared rail schedule.

## 4. Required target-stage corrections

The migration must reverse the current consumer-reconstruction flow. Each
stage writes one immutable semantic product; later stages consume or verify it
without repairing, overwriting, or rediscovering its meaning.

| Target stage | Legacy defect to remove | Required correction | Migration |
|---|---|---|---|
| A0 source authority | duplicated region/sheet state and tolerance-derived support identity | one immutable `SourceAuthoritySnapshot` and one tagged exact `SourceSupport` kernel | M1, M2, M5 |
| A1 field transport | bare/parallel transition indices, duplicate chart types, zero-rotation special handling | one `FieldChartId`, typed `GridAutomorphism`, `TransitionStep`, and `CanonicalRoute` | M1 |
| A2 topology plan | topology reconstructed or normalized downstream | one `GlobalTopologyPlan` owning regions, cuts, rails, seam certificates, singularity ports, and holonomy | M2, M4 |
| A3 conformity plan | independent rail discretization followed by post-hoc pairing | one verified `GlobalConformityPlan` before any region commits cells | M3 |
| A4 local construction | aggregation overwrites producer scope | immutable `RegionAuthorityView`; fully scoped `RegionCellComplex`; aggregation validates only | M2, M3 |
| A5 occurrence complex | equality inferred from lattice/position/front rows | four explicit corner occurrences per cell and typed directed-side relations | M4, M5 |
| A6 quotient/materialization | validator/consumer reconstructs compatible merges | verified relation registry, `QuotientCertificate`, exact-once consumption, one cell to one quad | M4, M5 |
| A7 embedding | multiple support classifiers and quantized keys | source geometry bound through the shared exact support kernel | M5 |
| A8 verification | validator acts as a second topology producer | independent certificate verification plus elementary source/output incidence recomputation only | M4, M5 |
| A9 diagnostics/export | state flags and retained debug data influence semantic behavior | derived, non-authoritative diagnostics separated from execution lifetime and public retention | M2, M6 |

This ordering follows the scientific constraints already adopted by
`DESIGN.md`: explicit transport algebra from Directional/MIQ; a sanitized
numeric-to-exact extraction boundary and explicit occurrences from QEx;
global shared-side conformity before local patch work from QuadWild; and local
Instant-Meshes/FlowRep scores restricted to proposal or quality roles rather
than topology authority.

## 5. Migration execution rules

1. Complete M0 before any migration edit.
2. Execute M1 through M6 in order. A milestone may require several small turn
   pairs; never combine milestones to manufacture a broad refactor.
3. Every mutating slice is one **Code + Build** turn followed by one immutable
   **Test + Benchmark** turn. Code + Build may compile/package but may not run
   generated binaries. Test + Benchmark may run the exact artifact but may not
   edit implementation, tests, fixtures, validators, benchmarks, or build
   configuration.
4. Record the exact source commit, artifact identity, changed ownership
   boundary, intended behavior delta, and rollback boundary for every slice.
5. Compatibility adapters are temporary one-way boundaries. New code consumes
   target types; it may not add new reads of raw legacy integers, parallel
   arrays, booleans, or copied authority tables.
6. A stage either returns its complete immutable product or a typed failure.
   Partial/debug state is not consumable authority.
7. Aggregation may remap representation handles only. It may not rewrite
   component, topology-region, sheet, route, relation, or ownership semantics.
8. A validator may independently recompute elementary incidence and materialized
   mesh topology. It may not infer a missing producer certificate.
9. Every recursive, retrying, or combinatorial path touched by a slice uses one
   shared `WorkLedger` and a monotone progress measure. Nested local limits are
   insufficient.
10. Each slice preserves the last accepted immutable artifact as comparison
    authority. A regression blocks the next slice; it is diagnosed within the
    current ownership boundary rather than bypassed with a feature or fallback.
11. No validator weakening, expected-output synthesis, fixture-specific branch,
    proximity weld, recovery output, generic substitution after `Rejected`, or
    predicted topology count can satisfy acceptance.

### 5.1 Interlocked test redesign

The test-suite audit found that `TEST_AUTHORITY_COVERAGE_GAP` has recurred five
times and that the direct oracle does not yet verify the whole product intent.
The architecture migration therefore consumes test authority incrementally:

| Test milestone | Required before | Minimum evidence |
|---|---|---|
| `T1` independent oracle/package foundation | M1 | test-only topology/lineage/geometry checks, oracle mutations, default discovery labels |
| `T2` complete direct corpus/semantic manifest | M2 behavior migration | all ten committed triangle-mesh cases packaged and explicitly green/known-red |
| `T3` generated/metamorphic framework | M3/M4 acceptance | seed replay, shrinking, cycle/order/transform/field-label properties |
| `T4` sanitizer fuzz/replay | M5 closure | bounded fast-stage ASan/UBSan targets and committed minimized reproducers |
| `T5` calibrated quality/corpus gates | G6/G7 readiness | field/feature/approximation/element-quality baselines and stratified corpus |
| `T6` CI/resource/oracle adequacy | M6/G7 closure | no hidden mandatory tests, resource trends, mutation sensitivity |

Each T milestone is its own Code + Build / immutable Test + Benchmark pair.
Known-red direct intent remains visible and cannot be counted as accepted
regression-preservation evidence. The full architecture migration does not
pause for a monolithic test rewrite; each M milestone waits only for its named
test prerequisite.

The queued first mutating plan is
`.agents/Directional/Test_Architecture_T1_Independent_Oracle_Foundation_Code_Build_Plan.md`.

## 6. Ordered migration milestones

### M1 — authority kernel and compatibility boundary

**Findings addressed:** `AR-02`, `AR-03`, `AR-04`, `AR-05`, `AR-09`.

Implement behind adapters, with no intended runtime behavior change:

- strong, non-interconvertible IDs for every source, transport, region, chart,
  rail, cell, occurrence, and quotient domain;
- named checked conversions returning typed errors;
- one `FieldChartId` representation;
- tagged `SourceSupport` for source vertex, source edge, and face interior;
- `QuarterTurn`, `LatticeTranslation`, and `GridAutomorphism` with composition,
  inverse, and cycle-closure algebra;
- `TransitionStep` and `CanonicalRoute`, with topology and optional interior
  transition in one object and explicit orientation;
- domain-specific canonical keys; generic integer-vector identity is not
  accepted in new stage APIs.

**Do not include:** producer-disposition changes, shared-rail scheduling,
validator behavior changes, feature work, or file-only refactoring.

**Exit evidence:** T1 independent oracle/package authority remains green; all
configured targets compile; implicit cross-domain conversion is impossible;
adapter round trips are exact or fail typed;
boundary/interior route, inverse/composition, route reversal, and face-row
permutation contracts pass in the following artifact turn; direct accepted
baselines remain semantically unchanged.

### M2 — closed producer outcomes and single-writer scope

**Depends on:** M1.  
**Findings addressed:** `AR-01`, `AR-04`, `AR-08`.

- replace `disposition + attempted + succeeded` with exhaustive
  `ProducerOutcome<T> = NotApplicable | Produced<T> | Rejected<E>`;
- make `Produced<T>` nonempty and internally valid by construction;
- make `Rejected` terminal for an owned producer domain;
- introduce immutable `SourceAuthoritySnapshot`, `GlobalTopologyPlan`, and
  typed `RegionAuthorityView` references;
- remove duplicated mutable region/sheet/chart authority from consumer
  aggregates;
- replace scope-normalization writes with validation and typed rejection;
- separate temporary execution retention, public result retention, test
  policy, and diagnostics availability.

**Exit evidence:** inconsistent outcomes cannot be constructed; exhaustive
dispatch covers every alternative and parent/child reduction; generic
substitution never follows `Rejected`; aggregation cannot mutate semantic
scope; plane, seam, close sheets, and cylinder remain direct strict-valid,
with torus classified against the M0 baseline.

### M3 — global conformity before regional production

**Depends on:** M1 and M2.  
**Findings addressed:** `AR-07`, with `AR-09` and `AR-12` enforcement.

- collect all incident requirements for each canonical `HardRailId` before
  local construction;
- solve one exact ordered breakpoint sequence, side count, parity, fixed
  endpoint, and incident-region assignment;
- publish a verified `HardRailScheduleCertificate` inside one
  `GlobalConformityPlan`;
- make region producers consume immutable breakpoint IDs exactly;
- remove post-production support-key grouping and post-hoc side pairing;
- report deterministic solver/work bounds through the global work ledger.

Solver choice is replaceable. The schedule schema and certificate are not.

**Exit evidence:** both sides consume the identical sequence; independent
insert/remove/reorder/quantize attempts fail typed; region-order and target-size
metamorphic cases preserve conformity; the historical exact-torus
`InvalidHardRailPairing` blocker is removed through the production entry path,
not a pairing exception.

### M4 — certificate-carrying chart and quotient relations

**Depends on:** M1 through M3.  
**Findings addressed:** `AR-02`, `AR-05`, `AR-06`.

- create one producer-owned canonical relation registry;
- give relations typed semantic endpoints, source support, transport,
  orientation, owner certificate, and separate representation handles;
- retain an ordered relation path in every `ChartSelectionCertificate`;
- represent ordinary, hard-rail, periodic, and singularity-port relations
  explicitly;
- replace boolean witness compression, front-edge equality, and validator-side
  relation discovery with certificate consumption and independent checks;
- keep complete global relation validity separate from the path selected by
  one face or occurrence.

**Exit evidence:** chained, unused-valid, off-face-peer, missing, duplicate,
conflicting, nonreciprocal, ambiguous, reverse-route, and representation-
renumbered cases have typed results; selected paths are auditable; production
torus lineage and quotient acceptance use the same certificates as focused
tests.

### M5 — occurrence/quotient/embedding/verification split

**Depends on:** M1 through M4.  
**Findings addressed:** `AR-06`, `AR-09`, `AR-12`.

This milestone must be divided into bounded ownership slices if it cannot be
reviewed atomically. Its final state must:

- create four distinct occurrences per accepted cell;
- merge only certified ordinary, hard-rail, periodic, or singularity-port
  relations;
- materialize one output vertex per verified quotient class and one quad per
  accepted cell;
- centralize source attachment and exact support rebinding;
- prove every owned relation is consumed exactly once;
- compute connected components, boundaries, orientability, manifoldness, and
  Euler characteristic from the materialized mesh;
- verify schema, certificates, source attachment, topology, product, and
  geometry independently;
- expose a global work ledger for every migrated combinatorial path needed by
  prescribed-sphere validation.

**Exit evidence:** equal coordinates without a relation remain distinct;
tampered ownership/support/transport/winding fails typed; source-face,
producer-schedule, route-orientation, output-row, and container permutations
preserve the semantic digest; close sheets, cylinder, torus, and the next
authorized singularity fixture enter the production path with complete
certificate lineage and no recovery.

### M6 — retire adapters and enforce module ownership

**Depends on:** M1 through M5 accepted under representative artifacts.  
**Findings addressed:** `AR-03`, `AR-04`, `AR-05`, `AR-10`, plus all residual
structural findings.

- move authority, transport, planning, construction, occurrence, quotient,
  verification, and diagnostics into their responsibility modules;
- delete legacy duplicate chart/support/route/ownership types and compatibility
  adapters after parity evidence;
- remove public parallel topology/index arrays, generic integer-vector keys,
  contradictory status aliases, mutable authority copies, and semantic
  equality based on hashes or execution handles;
- keep the former tracing, arrangement, validator, and pipeline monoliths only
  as thin orchestration where still required;
- add compile/static enforcement so forbidden representations cannot return.

**Exit evidence:** repository search and type checks find no forbidden public
representation; all `AR-01` through `AR-12` closure conditions have immutable
evidence; focused, tamper, metamorphic, direct representative, full related
suite, determinism, memory, and bounded-work gates pass before architecture
migration is declared complete.

## 7. Finding closure matrix

A finding is not closed merely because one fixture passes. Close it only when
the forbidden representation or ownership path is removed and the required
counterevidence passes.

| Finding | Required correction | Earliest closure |
|---|---|---|
| `AR-01` | one closed producer outcome; no public aliases | M2 artifact acceptance |
| `AR-02` | typed domains and one route object; no public parallel arrays | M1 advances; M6 removal closes |
| `AR-03` | domain-specific semantic keys; no generic integer-vector identity | M1 advances; M6 removal closes |
| `AR-04` | one chart type and single-writer snapshots | M2 advances; M6 duplicate removal closes |
| `AR-05` | semantic identity excludes representation/execution handles | M4 advances; M6 removal closes |
| `AR-06` | producer certificates retained; validator only verifies | M4/M5 artifact acceptance |
| `AR-07` | one global rail schedule before local production | M3 representative acceptance |
| `AR-08` | aggregation validates scope and cannot overwrite it | M2 artifact acceptance |
| `AR-09` | one sanitized exact support kernel; no tolerance identity | M1 advances; M5 artifact acceptance closes |
| `AR-10` | responsibility modules with thin orchestration | M6 acceptance |
| `AR-11` | normative design separated from status/evidence | corrected at `dfa77fa6`; continuously enforced |
| `AR-12` | positive, tamper, metamorphic, and representative evidence for every contract | enforced per slice; closes with M6 matrix |

Test-architecture findings `TA-01` through `TA-12` are tracked separately in
the regression tracker. They are not runtime regression events. Close each
only at the T milestone named by the test-suite audit; a green focused test or
aggregate count cannot close them.

## 8. Mandatory repeated-pattern controls

Every slice must copy the tracker’s per-turn review table and fill all nine
rows with exact symbols and evidence. The reorientation-level correction is:

| Pattern | Prohibited recurrence | Architectural control |
|---|---|---|
| `RP-01` | consumer guesses/intersects authority domains | strong types, checked conversions, producer certificates |
| `RP-02` | focused proxy or compiled test treated as production proof | four evidence classes plus packaged discovery and direct entry |
| `RP-03` | one state carries policy and stage meanings | closed outcomes and separate retention/policy/diagnostic state |
| `RP-04` | local limits leave aggregate work unbounded | shared global work ledger, visited-state set, monotone measure |
| `RP-05` | identity depends on traversal, order, role, hash, or backend | semantic tuples first; representation handles separate |
| `RP-06` | shared membership copied into every consumer | immutable registry plus typed references and local witnesses |
| `RP-07` | cyclic incidence treated as a linear sequence | explicit cyclic/orbit position, orientation, and wrap contracts |
| `RP-08` | producer disposition reduced to a boolean | exhaustive `ProducerOutcome` dispatch; `Rejected` is terminal |
| `RP-09` | every local face must consume complete global authority | validate global registry once; consume only the certified local path |

The five audited singleton categories remain guarded as well: intrinsic
support is not overconstrained; stage edits are transactional; shared-edge
orientation is explicit; complete orbits are published before consumption;
and exact simplex identity survives canonicalization.

## 9. Feature-unblocking rules

| Work | Minimum architecture evidence before authorization |
|---|---|
| Existing multi-rail torus artifact | M0 only; evidence preservation, no edits |
| M1 authority kernel | accepted T1 independent oracle/package foundation |
| Target-size hard-rail behavior and adaptive 2:1 transitions | accepted T3 properties, M3 schedule, and M5 certificate verification for the touched path |
| Nonzero periodic `Z4` holonomy | T3 cycle/branch-label properties, M1 algebra, M4 relation certificates, and M5 independent cycle/quotient verification |
| Prescribed singularity sphere | T2 direct visibility, T3 generated index/cycle evidence, hard-rail blocker closed, and occurrence/singularity-port/work-ledger authority through M5 |
| G6 bunny/vase production closure | T5 representative verifier/quality gates accepted and no touched legacy authority path remains; M6 closure is required before declaring architecture complete |
| G7 default-on/production hardening | T6 and M6 complete, then full-suite, supported-platform, failure-path, determinism, memory, performance, corpus, and fuzz evidence |

Passing M0 cannot authorize these feature slices on the legacy model.

## 10. Stop and rollback conditions

Stop before implementation or before advancing a milestone if a proposed
change:

- introduces an untyped semantic ID or a second representation of the same
  authority;
- requires a consumer or validator to reconstruct a missing producer fact;
- adds new semantic behavior inside a legacy monolith instead of behind the
  target stage API;
- lets an adapter become a second long-lived authority or perform an ambiguous
  conversion;
- schedules a shared rail independently on two sides;
- uses tolerance, proximity, counts, row order, container order, hash, or
  backend choice as topology identity;
- treats compile success, aggregate totals, reduced failure counts, timeout,
  or a focused proxy as representative acceptance;
- uses production success/validation as the independent product oracle, or
  omits the fixture precondition/counterexample/package identity;
- hides a mandatory intent/property/fuzz-replay test behind a default-off
  target, disables a known-red product case, or loses its deterministic seed;
- weakens a fixture, validator, typed failure, lineage requirement, or
  fallback prohibition;
- lacks a finite aggregate work bound or permits partial state to escape as a
  product.

On failure, preserve the immutable artifact and evidence, update the existing
stable regression/pattern entry, and revise only the current slice. Do not
advance, combine the next milestone, or hide the failure behind feature work.

## 11. Reorientation completion

Architecture reorientation is complete only when:

1. M0 is closed with immutable evidence;
2. M1 through M6 each have separate compile and runtime acceptance records;
3. T1 through T6 each have separate compile and runtime acceptance records at
   the dependency named above;
4. all `AR-01` through `AR-12` and `TA-01` through `TA-12` closure conditions
   are evidenced;
5. no `RP-01` through `RP-09` forbidden code shape remains on the direct
   production path;
6. the A0–A9 pipeline has one immutable owner per semantic output;
7. representative direct fixtures prove certificate lineage, exact topology,
   field/feature alignment, source approximation, element quality,
   determinism, bounded work, and no fallback/recovery;
8. `TODO`, milestone, handoff, tracker, and PR state agree on the next product
   gate.

Completion of this roadmap removes the architectural block. It does not by
itself claim G6/G7 production readiness; those gates still require their full
runtime, benchmark, platform, and operational evidence.
