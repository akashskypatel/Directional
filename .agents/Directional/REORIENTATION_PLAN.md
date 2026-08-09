# Directional Surface-Cell Reorientation Plan

**Status:** authoritative architecture-migration roadmap  
**Reviewed implementation:** `6af23d9aeca29e63aa13c4ae49f50d1748939c49`  
**Architecture-review planning baseline:** `dfa77fa6bda44b51454f0189d65a97086aaba049`  
**Decision:** **changes required before architecture expansion**  
**Last updated:** 2026-08-09 UTC

Repository authority: `akashskypatel/Directional`, branch `agent/surface_cell_quad/p5-recover-bridge-healing`, draft PR #8. Keep the PR open, draft, and unmerged throughout this migration.

## 1. Purpose and authority

This plan converts the independent architecture review into an ordered, verifiable migration from the current behavioral implementation to the normative architecture in `.agents/Directional/DESIGN.md`.

It owns migration order, dependencies, stop conditions, and acceptance gates. It does not redefine architecture or runtime evidence:

| Concern | Authority |
|---|---|
| Normative product, domains, stages, and invariants | `.agents/Directional/DESIGN.md` |
| Findings and scientific comparison | `.agents/Directional/Surface_Cell_Architecture_Independent_Design_Review_Report.md` |
| Normative testing policy | `tests/TESTING_STRATEGY.md` |
| Test-audit findings and T0–T6 redesign | `.agents/Directional/Surface_Cell_Test_Suite_Independent_Audit_And_Redesign_Plan.md` |
| Current turn and exact next action | `TODO`, `MILESTONE_G_TODO.md`, and `.agents/Directional/Future_Chat_Session_Handoff.md` |
| Regression history and repeated code shapes | `.agents/Directional/Regression_Root_Cause_Tracker.md` |
| Immutable build/runtime evidence | the applicable dated plan and report |

If this roadmap conflicts with `DESIGN.md`, the design wins and this file must be corrected before implementation. A dated runtime report may update current status, but it cannot waive a migration invariant.

## 2. Corrected orientation

Product gates and architecture migration are separate progress axes. Passing a fixture does not close structural debt, and completing a migration slice does not by itself pass a product gate.

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
M0 preserve immutable evidence [complete]
-> M1 authority kernel and staged production adoption [active]
   M1a authority kernel [accepted]
   M1b first source/provenance consumer [accepted]
   M1c field-transition consumer [accepted]
   M1d phase-front route identity consumer [next]
-> M2 closed outcomes and single-writer snapshots
-> M3 global conformity plan
-> M4 certificate-carrying chart and quotient relations
-> M5 occurrence, embedding, and independent verification split
-> M6 retire legacy representations and decompose ownership modules

Testing:
T0 independent audit and authority separation [complete]
-> T1 independent oracle/package foundation [accepted]
-> T2 complete direct corpus and semantic manifest
-> T3 property/metamorphic generation and shrinking
-> T4 sanitizer fuzzing and minimized replay
-> T5 calibrated representative quality/corpus gates
-> T6 CI, resource, and oracle-adequacy hardening
```

The current implementation remains behavioral comparison authority and migration input only. Accepted M1 slices prove only their bounded ownership seams; they do not approve feature expansion or close G4.

## 3. Current immutable checkpoint

M1c is immutable accepted under:

`.agents/Directional/Architecture_M1c_Field_Transition_Consumer_Artifact_Only_Test_Benchmark_Report.md`.

| Evidence | Authority |
|---|---|
| M1c implementation | `e139fca885538e310dc47ed7ba531517603d92cf` |
| Compile artifact | `9043971772` |
| Compile artifact SHA-256 | `dde120c94be222dc93aeebb08f7a674882c5f8011ede62ec420209b0e0f4fd85` |
| Log artifact | `9043971968` |
| Log artifact SHA-256 | `7747b3b25882fc86e54890a1efb69d753f9b2e08bff7db8fd2be4f4a8a82fedb` |
| Recursive manifest | **54/54**, `d9a4bdfe5b160095a6cf4949c57e54d726d36f745ff0a6580e9080d5319d495d` |
| M1c focused | exact six, **6/6** |
| M1b / validation | **6/6**, **77/77** |
| M1a / T1 | **14/14**, **29/29** |
| producer required-green | **157/157** plus four direct-green cases |

Exact producer discovery remains 172 with nine historical/deferred known-red members, Bunny known-red, and Vase bounded safety-only explicitly accounted for. G4-R007 remains active and separate.

The authoritative next mutating slice is:

`.agents/Directional/Architecture_M1d_Phase_Front_Route_Identity_Consumer_Code_Build_Plan.md`.

M1d migrates only route identity validation at `build_authoritative_phase_front_mesh -> exact_interior_route_valid`; it does not change public route storage or introduce transport semantics the consumer does not own.

## 4. Required target-stage corrections

The migration must reverse the current consumer-reconstruction flow. Each stage writes one immutable semantic product; later stages consume or verify it without repairing, overwriting, or rediscovering its meaning.

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

This ordering follows the scientific constraints already adopted by `DESIGN.md`: explicit transport algebra from Directional/MIQ; a sanitized numeric-to-exact extraction boundary and explicit occurrences from QEx; global shared-side conformity before local patch work from QuadWild; and local Instant-Meshes/FlowRep scores restricted to proposal or quality roles rather than topology authority.

## 5. Migration execution rules

1. Execute M1 through M6 in order. A milestone may require several small turn pairs; never combine milestones to manufacture a broad refactor.
2. Every mutating slice is one **Code + Build** turn followed by one immutable **Test + Benchmark** turn. Code + Build may compile/package but may not run generated binaries. Test + Benchmark may run the exact artifact but may not edit implementation, tests, fixtures, validators, benchmarks, or build configuration.
3. Record exact source commit, artifact identity, ownership boundary, intended behavior delta, and rollback boundary for every slice.
4. Compatibility adapters are temporary one-way boundaries. New code consumes target types; it may not add new reads of raw legacy integers, parallel arrays, booleans, or copied authority tables.
5. A stage either returns its complete immutable product or a typed failure. Partial/debug state is not consumable authority.
6. Aggregation may remap representation handles only. It may not rewrite component, topology-region, sheet, route, relation, or ownership semantics.
7. A validator may independently recompute elementary incidence and materialized mesh topology. It may not infer a missing producer certificate.
8. Every recursive, retrying, or combinatorial path touched by a slice uses one shared `WorkLedger` and a monotone progress measure. Nested local limits are insufficient.
9. Each slice preserves the last accepted immutable artifact as comparison authority. A regression blocks the next slice and is diagnosed within the current ownership boundary.
10. No validator weakening, expected-output synthesis, fixture-specific branch, proximity weld, recovery output, generic substitution after `Rejected`, or predicted topology count can satisfy acceptance.
11. Do not force an authority type into a consumer that lacks the semantic data required to construct it correctly. M1d therefore adopts route identity types but defers `TransitionStep`/`CanonicalRoute` until a consumer owns real per-step transport.

### 5.1 Interlocked test redesign

| Test milestone | Required before | Minimum evidence |
|---|---|---|
| `T1` independent oracle/package foundation | M1 | **accepted**: topology/lineage/disposition oracle, mutation suite, exact package/discovery authority |
| `T2` complete direct corpus/semantic manifest | M2 behavior migration | all ten committed triangle-mesh cases packaged and explicitly green/known-red |
| `T3` generated/metamorphic framework | M3/M4 acceptance | seed replay, shrinking, cycle/order/transform/field-label properties |
| `T4` sanitizer fuzz/replay | M5 closure | bounded fast-stage ASan/UBSan targets and committed minimized reproducers |
| `T5` calibrated quality/corpus gates | G6/G7 readiness | field/feature/approximation/element-quality baselines and stratified corpus |
| `T6` CI/resource/oracle adequacy | M6/G7 closure | no hidden mandatory tests, resource trends, mutation sensitivity |

Known-red direct intent remains visible and cannot be counted as accepted regression-preservation evidence.

## 6. Ordered migration milestones

### M1 — authority kernel and compatibility boundary

**Status:** active; M1a/M1b/M1c accepted, M1d next.  
**Findings addressed:** `AR-02`, `AR-03`, `AR-04`, `AR-05`, `AR-09`.

Target authority:

- strong, non-interconvertible IDs for every source, transport, region, chart, rail, cell, occurrence, and quotient domain;
- named checked conversions returning typed errors;
- one `FieldChartId` representation;
- tagged `SourceSupport` for source vertex, source edge, and face interior;
- `QuarterTurn`, `LatticeTranslation`, and `GridAutomorphism` with composition, inverse, and cycle-closure algebra;
- `TransitionStep` and `CanonicalRoute`, with topology and optional interior transition in one object and explicit orientation;
- domain-specific canonical keys; generic integer-vector identity is not accepted in new stage APIs.

Accepted staged adoption:

1. **M1a** — authority kernel and adapters: immutable accepted.
2. **M1b** — `provenance_supports_interval_sheet`: checked source-face/source-vertex consumer accepted.
3. **M1c** — `resolve_branch_transition`: checked source IDs, canonical source-edge key, exact quarter-turn/inverse consumer accepted.
4. **M1d next** — `build_authoritative_phase_front_mesh -> exact_interior_route_valid`: checked `InteriorTransitionId`, checked source vertices, and canonical source-edge route identity while public route vectors remain compatibility storage.

Later bounded M1 slices must finish real `FieldChartId`, `TransitionStep`, `CanonicalRoute`, and remaining strong-ID consumers only where the required semantics exist. Do not combine them into one broad schema rewrite.

**Do not include in M1:** producer-disposition changes, shared-rail scheduling, validator behavior changes, feature work, or file-only refactoring.

**M1 exit evidence:** T1 authority remains green; all configured targets compile; implicit cross-domain conversion is impossible; adapter round trips are exact or typed failures; boundary/interior route, inverse/composition, route reversal, and face-row permutation contracts pass; direct accepted baselines remain semantically unchanged.

### M2 — closed producer outcomes and single-writer scope

**Depends on:** M1.  
**Findings addressed:** `AR-01`, `AR-04`, `AR-08`.

- replace `disposition + attempted + succeeded` with exhaustive `ProducerOutcome<T> = NotApplicable | Produced<T> | Rejected<E>`;
- make `Produced<T>` nonempty and internally valid by construction;
- make `Rejected` terminal for an owned producer domain;
- introduce immutable `SourceAuthoritySnapshot`, `GlobalTopologyPlan`, and typed `RegionAuthorityView` references;
- remove duplicated mutable region/sheet/chart authority from consumer aggregates;
- replace scope-normalization writes with validation and typed rejection;
- separate temporary execution retention, public result retention, test policy, and diagnostics availability.

**Exit evidence:** inconsistent outcomes cannot be constructed; exhaustive dispatch covers every alternative and parent/child reduction; generic substitution never follows `Rejected`; aggregation cannot mutate semantic scope; plane, seam, close sheets, and cylinder remain direct strict-valid, with torus classified against the accepted baseline.

### M3 — global conformity before regional production

**Depends on:** M1 and M2.  
**Findings addressed:** `AR-07`, with `AR-09` and `AR-12` enforcement.

- collect all incident requirements for each canonical `HardRailId` before local construction;
- solve one exact ordered breakpoint sequence, side count, parity, fixed endpoint, and incident-region assignment;
- publish a verified `HardRailScheduleCertificate` inside one `GlobalConformityPlan`;
- make region producers consume immutable breakpoint IDs exactly;
- remove post-production support-key grouping and post-hoc side pairing;
- report deterministic solver/work bounds through the global work ledger.

**Exit evidence:** both sides consume the identical sequence; independent insert/remove/reorder/quantize attempts fail typed; region-order and target-size metamorphisms preserve conformity; exact-torus `InvalidHardRailPairing` blocker is resolved structurally rather than patched locally.

### M4 — certificate-carrying chart and quotient relations

**Depends on:** M2/M3.

Produce and consume explicit topology/holonomy/relation certificates once. Local stages may verify them but may not reconstruct global meaning. This milestone owns `AR-06`, `RP-09`, nonzero periodic Z4 production capability, and positive multi-isolation quotient evidence.

### M5 — occurrence, embedding, and independent verification split

**Depends on:** M4.

Adopt explicit corner occurrences, exact tagged support, one cell-to-one-quad quotient materialization, source embedding through the shared support kernel, and independent verifier ownership. This milestone completes the exact numeric-to-semantic boundary and removes consumer repair/reconstruction.

### M6 — retire legacy representations and decompose ownership modules

**Depends on:** M5.

Remove temporary compatibility storage/read paths after all real consumers have migrated; decompose ownership modules around the final stage products; harden CI/resource/oracle adequacy under T6. No compatibility representation may be retired before its last accepted consumer migration.

## 7. Standing stop conditions

Stop the current slice and revise its plan if implementation requires a later milestone's ownership, changes public semantics outside the bounded seam, weakens an accepted test/oracle, hides a known-red case, or cannot construct the target semantic type from facts actually owned by the selected consumer.

The exact next action always comes from `TODO`, `MILESTONE_G_TODO.md`, and `.agents/Directional/Future_Chat_Session_Handoff.md`.
