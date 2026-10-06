# M6-DEFN-R5 — CP3 Entry Definition Record (WIP)

**Turn:** `M6-DEFN-R5`
**State:** DEFINITION COMPLETE — D1-D9 decided; pending mandatory independent `M6-DEFN-R5-REV`.
**Turn type:** runtime-free Definition. No Directional executable was run and no source/test/fixture/selector/build byte was changed.
**Mandatory successor:** `M6-DEFN-R5-REV`. No implementation is authorized until that Review accepts RA-30 and the held CB1 plan.

## 0. Frozen source authority

This turn used one authoritative source snapshot only: workflow run `37433281173`, source/event SHA `22b636c636bb0fb793410d7fe31ca8e51f363ba0`, source artifact `11398311934`. The downloaded snapshot metadata records `runtimeExecution=false`; `source.tar.gz` SHA-256 is `8511dfaa1e3c33e059fb8a9fe50d942900ba697f33c704fc4895f0d16e4a0856`; all `5513/5513` source-manifest rows verified. The reviewed entering runtime authority remains `11391685901 / 5ce3132ec01748eff5b15f82be07a1abe2bd1af6`, 491/491, per the frozen R5 plan. Accounting remains 60 / 16 / 44, debt 1.

The decisions below follow the R5 method rule: first establish the real producer branch, then define the predicate, then name a production-reachable falsifier. No hand-built relation record is accepted where the producer can create the product.

## D1 — exact-A3 Periodic unequal-face-gauge rule — DECIDED

### Reachable authority

`SurfacePeriodicRelationEndpointState` is explicitly the periodic **relation-gauge** state, distinct from cut-domain `LocalLatticeState`; it publishes relation-gauge lattice coordinate, branch rotation, scale, source chart, branch authority, boundary occurrence, occurrence orientation and relation rotation (`include/directional/geometry/SurfaceCellTracing.h:1437-1453`). `make_periodic_relation_endpoint_state` strips the local face branch gauge and applies the relation turn only on the Reverse side (`src/geometry/SurfaceCellTracing.cpp:7925-7941`). Semantic Periodic action is selected only when Forward/Reverse interval orientation and reversed cut route agree (`src/geometry/SurfaceCellTracing.cpp:7945-7965`).

A5 already computes the exact placement-gauge conjugation from four endpoint gauges: `T = Γ_to^-1 ∘ g ∘ Γ_from`; it requires the two endpoint-derived transports to be equal (`src/pipeline/RemeshPipeline.cpp:4543-4614`). The remaining defect is the final check against `SurfaceFrontEdge::{from,to}Lattice`, which is face-gauged representation state (`src/pipeline/RemeshPipeline.cpp:4869-4874`). RA-16 established that comparing such face-gauged branch values is unsound when endpoint face gauges differ (`.agents/Directional/Architecture_M6_CP1_TB7_A6_Review_Record.md:247-269`).

### Frozen rule

For **exact-A3 Periodic** relations only:

1. Keep the semantic relation value `g` in the Periodic relation-endpoint gauge. Do not redefine `canonicalRelationValue`.
2. Recompute each published `SurfacePeriodicRelationEndpointState` from its local placement state, interval, relation rotation and `branchAuthority`; exact inequality is a typed Periodic authority failure. This keeps `make_periodic_relation_endpoint_state` as the sole gauge bridge.
3. Derive `Γ` for each endpoint exactly as the current `periodic_endpoint_gauge` does, and derive placement transport `T = Γ_to^-1 ∘ g ∘ Γ_from` for both endpoint pairs. The two derived `T` values must be identical.
4. The final placement check is against the **A5 occurrence endpoint placements named by the relation's canonical endpoint pairs**, not against the `SurfaceFrontEdge` lattice copies. `T` must map both occurrence lattice coordinates exactly and preserve equal scale. No branch equality is evaluated directly in two different face gauges.
5. Independently, in the relation gauge, `g` must map the two published Forward endpoint states to the reciprocal Reverse endpoint states in both coordinate and branch. Thus coordinate placement and relation-gauge branch correctness are separately certified instead of one face-gauged predicate standing in for both.
6. Non-A3 Periodic stays on the existing legacy action-or-inverse placement path; this D-item does not widen its semantics.

This is a validation/evidence correction, not a new quotient relation: relation identity, `equivalence.action`, route/cut route, canonical relation value and A6 strict cycle semantics remain unchanged.

### Required produced witness and falsifiers

Reserve `M6CP3.PeriodicExactA3UnequalFaceGaugeUsesRelationAndOccurrenceAuthority`.

The witness must be emitted by the real periodic producer and must prove at least one reciprocal exact-A3 endpoint pair has unequal `branchAuthority.localFaceBranchRotation`. The current hand-constructed endpoint-state test already demonstrates that unequal face gauges are representable (`tests/SurfaceCellTransitionQuotientTests.cpp:5815-5878`), but it is **not** sufficient as the CP3 reachability witness.

Conjunct falsifiers on the produced chain:
- change one occurrence placement coordinate while retaining the published A3 relation endpoint state → placement-coordinate clause rejects;
- change one published local-face gauge/endpoint branch authority and republish the upstream product consistently far enough to reach A5 → endpoint-state recomputation/relation-gauge clause rejects;
- change the semantic Periodic relation value while retaining endpoint states → relation-gauge mapping rejects;
- swap storage orientation only → canonical semantic result stays unchanged (existing storage-canonical periodic coverage at `tests/SurfaceCellTransitionQuotientTests.cpp:5927-6003` remains a control).

A witness whose paired local face gauges are equal is vacuous for D1 and earns no D1 credit.

## D2 — HardRail cross-region branch certification — DECIDED

### Reachable authority

HardRail is a real A5 relation only for reciprocal HardRail front edges with the same rail owner, **different topology regions**, and reversed route (`src/pipeline/RemeshPipeline.cpp:4657-4683`). Its placement transport is correctly coordinate-rigid today: A5 derives the unique quarter-turn/translation mapping the two occurrence endpoint-coordinate pairs (`src/pipeline/RemeshPipeline.cpp:4738-4799`). This must remain the placement authority.

The missing fact is an independent branch certificate. `LocalLatticeState.branchRotation` contains the selected source face's propagated face gauge plus the region-local lattice branch; directly subtracting two regions' values is invalid. The review derives the contamination term explicitly (`branch(b)-branch(a)=R_true+τ`) and shows why constant-field HardRail gates cannot expose it (`.agents/Directional/Architecture_M6_CP1_TB7_A6_Review_Record.md:251-269`).

### Frozen rule

A HardRail relation must carry **per-endpoint face-gauge evidence** for the exact occurrence placements used by the relation. The minimum evidence is the selected source-face topology plus its authoritative `localFaceBranchRotation` (or a semantically equivalent immutable A4-published gauge value). It is evidence only; it does not become occurrence identity or quotient identity.

For each canonical HardRail endpoint mapping `a -> b`:

- `B_a`, `B_b` = placement `branchRotation` as quarter-turns;
- `F_a`, `F_b` = published local-face gauges;
- face-free regional lattice branches are `C_a = F_a^-1 ∘ B_a` and `C_b = F_b^-1 ∘ B_b`;
- `R_coord` = the rotation of the already-authoritative coordinate-rigid `canonicalTransport`;
- require exactly `R_coord = C_b ∘ C_a^-1`.

Apply the same equation to both HardRail endpoint pairs; both must agree with the one coordinate-rigid transport. Failure is a typed HardRail branch-certification failure mapped through the existing `InvalidHardRailTransport` external family unless Review authorizes a more specific stable external name.

This rule deliberately **does not derive** placement transport from branch data. Coordinates remain primary for HardRail placement; the stripped branch relation is an independent certificate.

### Required produced witness and falsifiers

Reserve `M6CP3.HardRailCrossRegionBranchCertificateStripsEndpointFaceGauge`.

The fixture must be produced by the real tracer, have a cross-region HardRail, and require a non-zero selected-face gauge difference or non-zero field matching on the rail; constant-XY HardRail fixtures are insufficient. The repository already demonstrates that non-zero matching on hard carriers is reachable (`.agents/Directional/Architecture_M6_CP1_TB7_A6_Review_Record.md:264-267`).

Falsifiers:
- alter only one endpoint face-gauge evidence value → branch certificate rejects while coordinate-rigid `T` is unchanged;
- alter only one placement branch rotation → branch certificate rejects;
- alter the coordinate correspondence so `R_coord` changes while branch evidence stays fixed → coordinate-rigid or branch certificate rejects;
- storage/canonical endpoint reversal must invert both sides and preserve acceptance.

## D3 — OrdinaryFront identity across isolation seams — DECIDED

### Reachable authority

A5 currently assigns `GridAutomorphism::identity()` to every OrdinaryFront relation (`src/pipeline/RemeshPipeline.cpp:4714-4730`). A6 then demands complete local-lattice equality, including face-gauged `branchRotation`, `sourceChart`, and floating `phase`, before accepting the identity relation (`src/pipeline/RemeshPipeline.cpp:5225-5247`). Separately, if reciprocal side spans are collinear on the same source edge but their sheets differ, A6 requires exact reciprocal `CornerWedgeIsolationTransition` evidence (`src/pipeline/RemeshPipeline.cpp:5266-5313`). Frozen RA-2 already says the checked seam quarter-turn is chart/sheet evidence and must **not** be re-applied as quotient transport (`.agents/Directional/Architecture_M6_DEFN_R3_Review_Record.md:56-68`).

### Frozen rule

Keep `OrdinaryFront.relationTransport = identity` universally. For an OrdinaryFront endpoint pair, quotient-coordinate identity is certified by the face-independent lattice product only:

- exact `latticeCoordinate` equality;
- exact `scaleLevel` equality.

Do **not** require equality of `sourceChart` or face-gauged `branchRotation` across an isolation seam. Those are relation-local chart evidence, not quotient coordinates. Do not convert the isolation-seam transition quarter-turn into quotient transport.

For a collinear span whose reciprocal endpoint sheets differ, acceptance additionally requires the already-frozen reciprocal checked isolation transition (`fromSheet/toSheet` in each direction). For non-seam OrdinaryFront spans, the existing same-sheet/wedge-membership rule remains. `phase` remains placement provenance and may be checked by its own producer contract, but the CP3 OrdinaryFront quotient identity must not rely on the current `1e-10` floating phase comparison as topological authority.

### Required produced witness and falsifiers

Reserve `M6CP3.OrdinaryFrontIsolationSeamUsesCoordinateIdentityAndCertifiedSheetTransition`.

The fixture must be produced by the real tracer and contain a front edge collinear with an isolation seam; hand-built relation records are forbidden. This same produced seam-collinear family may be shared with D7, but D3 and D7 require separate falsifier assertions.

Falsifiers:
- change one endpoint lattice coordinate → reject identity;
- change one endpoint scale → reject identity;
- remove or reverse one required seam transition while keeping coordinates equal → reject reciprocal isolation evidence;
- change only relation-local source-chart/face-gauge representation while keeping valid checked seam evidence and face-independent coordinates → acceptance must not change.

## D4 — A5 chart-barrier census — DECIDED

### Reachable authority

A5 currently constructs its `SourceChartTransitionGraph` barrier set by scanning **only HardRail** front-edge routes (`src/pipeline/RemeshPipeline.cpp:3785-3799`). That is not the same authority as source hard-feature protection. RA-20 already requires A6 `hardFeatureProtected` to come from the typed source hard-feature edge set, independent of relation kind, and explicitly records that PeriodicCut carriers can be hard features (`.agents/Directional/Architecture_M6_Frozen_Definitions.md:735-755`). The produced torus gate demonstrates this non-vacuously: its protected hard-feature carriers include Periodic relations and recover exactly the 18 source hard edges (`tests/SurfaceCellTransitionQuotientTests.cpp:4302-4355`).

### Frozen decision

The HardRail-only A5 barrier census is **not semantic**. It conflates relation kind with source hard-feature authority and must be corrected before CP3 direct-production testing.

A5 must receive the same immutable typed source hard-feature edge authority used by downstream completion/A6 protection and build `SourceChartTransitionGraph` from that set directly. Relation kind is not the barrier selector:

- every typed source hard-feature edge is a chart barrier, including a PeriodicCut carrier;
- every HardRail carrier must be in that typed set; otherwise fail closed as inconsistent authority;
- an unmarked PeriodicCut is not promoted to a hard feature merely because it is Periodic;
- A5 does not reconstruct hard-feature authority from routes.

This preserves the single-writer rule: source hard-feature authority decides barrier membership once; A5 and A6 consume it for different products.

### Required produced witness and falsifiers

Reserve `M6CP3.A5ChartBarriersConsumeTypedHardFeatureAuthorityAcrossRelationKinds`.

Use the existing produced torus path because it already supplies the required PeriodicCut-carried hard features. The identity must prove that all 18 frozen torus hard edges are present in the A5 chart barrier input/effect even though the relations are PeriodicCut, and that the resulting occurrence binding components do not cross those barriers.

Falsifiers:
- remove one typed hard edge while leaving its Periodic relation intact → that edge must cease being a chart barrier (proves authority comes from the typed hard-feature set, not relation kind);
- keep a HardRail relation but remove its carrier from typed hard-feature authority → fail closed on the HardRail/source-authority consistency rule;
- mark an Ordinary/Periodic carrier as hard in typed source authority → it becomes a chart barrier without changing relation kind.

## 5. Bounded-turn disposition

D1-D4 are decided above. **D5-D9 are not yet decided** and are intentionally not summarized into normative text without their required source/gate audit. In particular, this WIP does not freeze the class-wide optimizer/validation reference, the D6 permutation equality, D7 relation-kind-aware selected-edge cross-sheet semantics, the full CP3 exit evidence matrix, or final CB/gate arithmetic.

No RA-30 amendment is published from this partial record. RA-30 must be written only after D5-D9 are decided so the normative amendment is internally complete and reviewable as one CP3-entry definition.

Resume `M6-DEFN-R5` at **D5** using this exact snapshot authority unless branch/source semantics have changed; if they have, acquire a new authoritative snapshot before accepting further static conclusions.


---

## Resume addendum — D5-D9 decided (2026-10-06)

This addendum supersedes only the bounded-turn statement above that D5-D9 were undecided. D1-D4 remain as frozen above. The turn itself remains WIP until RA-30, the held CB plan, exact G4-B001 3/3 test-name resolution, durable navigation updates, and final self-audit are complete.

## D5 — class-wide optimizer and validation references — DECIDED

RA-26's two representative-sensitive consumers are confirmed in current source: optimizer energy selects `facePoints.front()` (`SurfaceMeshOptimizer.cpp:1470-1509`), gradient selects the first valid face provenance (`1943-1970`) and finite differences narrow to `source_face_scope(faceSource.face)` (`2001,2124`); final edge-field validation begins from the first endpoint scope (`2675-2680`). Existing helpers already expose the correct class/quad-wide ingredients at `986-1153`: all four corner authorities, compatible-chart resolution, and quad reference projection. RA-28b forbids assuming the selected representative face belongs to every chart carried by the quotient class.

Freeze one authoritative reference rule:
1. resolve a compatible chart from all four quad-corner provenance points plus all four `vertexChartAuthority` sets;
2. project the quad centroid in that resolved chart and use the resolved chart-face set for normal/field energy and gradient;
3. freeze that face set across each finite-difference gradient evaluation and each line-search candidate evaluation; no corner/representative face may narrow the scope;
4. final edge-field metrics project the edge midpoint in the same quad-wide compatible chart rather than first-endpoint scope;
5. if no compatible authoritative chart can be resolved, or projection within it fails, fail typed. The current first-valid-provenance fallback in `quad_reference_surface_point` is forbidden on this authoritative path.

Cost bound: four-corner chart resolution is linear in the total published chart memberships of those four corners. Gradient and line-search use a fixed number of projections per quad. No class-pair scan, global search, or asymptotic regression is authorized.

## D6 — produced permutation falsifier — DECIDED

Use a direct-produced torus with recovery disabled and fail-closed fallback. Compare baseline with a perturbation that simultaneously:
- permutes source-face rows while consistently remapping every source-face-indexed field/provenance input;
- permutes output vertex and face rows before optimizer entry with lineage/indices remapped consistently;
- rotates every quad corner cycle by a deterministic nonzero offset.

Non-vacuity requires at least one quotient-class representative source-face row to change and at least one quad corner-0 vertex to change.

Freeze equality as follows:
- A5/A6/A7/A8 semantic identities, relation values, certificates, failure/accept decisions and canonical structural digests: exact after semantic remapping;
- optimizer accept/reject and iteration/line-search decision sequence: exact;
- optimized positions and continuous validation metrics: componentwise absolute difference <= `1e-12 * max(1, source_bbox_diagonal)` after lineage-based remapping;
- discrete validator outcomes, codes and topological counts: exact.

Reserve `M6CP3.ClassWideOptimizerReferencesAreSourceOutputAndCornerPermutationInvariant`.

## D7 — relation-kind-aware selected-edge cross-sheet rule — DECIDED

The current A7 selected-edge rule (`RemeshPipeline.cpp:6861-6960`) compares endpoint wedge sheet sets globally and, if disjoint, demands connecting isolation-transition evidence without dispatching on relation kind. RA-27a already establishes that sheet IDs are not semantically comparable across unrelated topology-region partitions.

Freeze:
- **HardRail:** do not compare global sheet IDs across its different topology-region partitions. Require the HardRail relation/route, D2 endpoint gauge+branch certificate, and each endpoint's own wedge-sheet validity. A cross-region isolation transition is neither required nor sufficient.
- **OrdinaryFront:** require one topology region. Shared sheet passes. Disjoint sheets require one exact connecting isolation transition certified both by the source transition graph and the relation evidence.
- **Periodic:** same rule within one topology region. A produced cross-region Periodic witness is a Review stop; do not silently exempt it.
- unsupported relation kinds fail closed.

Produced seam-collinear witness: use the real tracer on split-isolation geometry with an isolation seam deliberately collinear with a traced front side; no hand-built relation records. It must actually produce an OrdinaryFront selected relation whose endpoint sheet sets are disjoint. Baseline A7 accepts only because the exact connecting transition exists. Tampering only that transition's sheet endpoints must trigger the selected-edge cross-sheet rejection.

Reserve:
- `M6CP3.ProducedSeamCollinearOrdinaryFrontRequiresExactCrossSheetTransition`
- `M6CP3.HardRailCrossRegionBindingDoesNotCompareGlobalSheetLabels`.

## D8 — CP3 exit evidence — DECIDED

Mechanism-only CP1/CP2 rows remain prerequisites but cannot replace fresh direct-produced CP3 evidence. Freeze these direct owners:

| Frozen exit obligation | CP3 evidence owner |
|---|---|
| equal coordinates/positions without certified relation remain distinct | `M6CP3.DirectProductionKeepsCoincidentUnrelatedClassesDistinct` |
| every A5 relation consumed exactly once | `M6CP3.DirectProductionConsumesEveryA5RelationExactlyOnce` |
| exact/shared source support independently bound | `M6CP3.DirectProductionPublishesExactSharedSupportAndA8BindsIt` |
| source/output/corner and scheduler permutations | D6 identity + `M6CP3.DirectProductionSchedulerPermutationIsSemanticNoOp` |
| G4-B002 direct candidate eligibility + hard-feature tamper | `M6CP3.DirectProducedTorusCandidateEligibilityAndHardFeatureTamper` |
| G4-B001 strict torus 3/3 | the three historical strict direct-torus product rows; first fresh M6 measurement; no validator weakening |
| G4-B004 representative A5→A6→A7→A8 chain | `M6CP3.DirectProducedTorusBindsA5A6A7A8RepresentativeChain` |

The G4-B004 identity must bind one actual direct-produced representative continuously from source authority through A5 explicit occurrence/relation, A6 exact-once selected relation, A7 materialized class/vertex, and A8 independent verification. Separate per-stage checks are insufficient.

G4-B002 uses the same direct-produced torus authority for baseline and hard-feature tamper. CP1 candidate-eligibility evidence remains prerequisite mechanism evidence, not debt closure.

G4-B001 keeps hard features out of isolation-sheet authority. Any returned `LocalSheetMismatch` is diagnosed against A7/source-support authority; validator weakening is forbidden.

## D9 — CB sequencing and gate arithmetic — DECIDED, with one exact-name item still open

### CP3-CB1 entry-authority implementation
Implement only D1-D4 and D7 plus these six entry identities:
1. `M6CP3.PeriodicExactA3UnequalFaceGaugeUsesRelationAndOccurrenceAuthority`
2. `M6CP3.HardRailCrossRegionBranchCertificateStripsEndpointFaceGauge`
3. `M6CP3.OrdinaryFrontIsolationSeamUsesCoordinateIdentityAndCertifiedSheetTransition`
4. `M6CP3.A5ChartBarriersConsumeTypedHardFeatureAuthorityAcrossRelationKinds`
5. `M6CP3.ProducedSeamCollinearOrdinaryFrontRequiresExactCrossSheetTransition`
6. `M6CP3.HardRailCrossRegionBindingDoesNotCompareGlobalSheetLabels`

Compile/package only. No CP3 direct-production acceptance TB is allowed until these execute green in the following artifact-only entry TB and independent Review accepts the entry gate.

Entry arithmetic: inherited `30 + 12 + 449 = 491` plus six entry identities = **497** fresh exact-filter processes. Preserve all inherited list/selector bytes. A later cumulative list may concatenate the accepted 30 then 12 in frozen order; it must not rewrite either authority.

### CP3-CB2 class-wide references and direct-exit evidence
Only after entry Review, implement D5-D6 and seven remaining new identities:
7. `M6CP3.ClassWideOptimizerReferencesAreSourceOutputAndCornerPermutationInvariant`
8. `M6CP3.DirectProductionKeepsCoincidentUnrelatedClassesDistinct`
9. `M6CP3.DirectProductionConsumesEveryA5RelationExactlyOnce`
10. `M6CP3.DirectProductionPublishesExactSharedSupportAndA8BindsIt`
11. `M6CP3.DirectProductionSchedulerPermutationIsSemanticNoOp`
12. `M6CP3.DirectProducedTorusCandidateEligibilityAndHardFeatureTamper`
13. `M6CP3.DirectProducedTorusBindsA5A6A7A8RepresentativeChain`

Intended final arithmetic is inherited 491 + all 13 new CP3 identities + the frozen historical G4-B001 strict-torus 3 rows = **507** processes. This final number is not selector-freeze authority until this Definition turn records the exact three historical G4-B001 test names.

**Selector449 optimizer stop rule:** if D5 changes the outcome of any inherited selector449 optimizer/validator row, do not rewrite an expectation, delete a row, or substitute a replacement. Stop before direct-production TB and return to independent Review with the exact changed ordinals and source-level cause.

## Remaining work before COMPLETE

1. Resolve the exact three historical G4-B001 strict-torus test names and replace the provisional 3-row reference above with exact names.
2. Append normative RA-30 to `Architecture_M6_Frozen_Definitions.md`.
3. Write the first CP3 Code+Build plan, HELD pending `M6-DEFN-R5-REV`.
4. Update ORIENTATION, TODO, ROADMAP and handoff coherently.
5. Self-audit D1-D9 against the R5 plan's lessons 199-205 before final Definition closeout.


---

## Completion addendum — exact G4-B001 gate, method audit, and Definition closeout

A second verified runtime-free source snapshot was taken after the bounded D5-D9 addendum: workflow `37441143188`, source/event SHA `612d914d37112cbbc32b974ec30e922805c47062`, artifact `11400583983`, provider/download SHA-256 `f4b5211254ba91f6ea022e4f6072a7f3feec54aa7dc16081cd49f8ac75fa2fd0`, inner `source.tar.gz` SHA-256 `6930ae109d49c91c6e09ffe8e6c20a730ce5f0449e133c19e07d54d67c463edf`, manifest **5518/5518**, `runtimeExecution=false`. It contains the D1-D9 WIP record and confirms no production source/test/fixture/selector byte changed during Definition.

### Exact current G4-B001 strict-direct-torus gate

The durable historical record preserves the old result only as **direct torus 0/3** at artifact `9031804178`; it does not preserve the three old exact-filter names. Do not invent historical names. Current source does expose exactly three strict production identities that independently require the committed torus path to produce rather than merely own diagnostics, and these are frozen as the CP3 G4-B001 3/3 re-proof:

1. `SurfaceCellsPhase10.ExactCommittedTorusDoesNotTreatIsolationSeamAsBoundedDiskBoundary` (`tests/SurfaceCellsPhase10Tests.cpp:4436`; `ASSERT_TRUE(result.is_produced())` and strict final product/source-authority assertions).
2. `MilestoneGP26.TorusCompletesEndToEnd` (`tests/MilestoneGP26Tests.cpp:934`; calls `expect_completed_surface_cells(..., false)`, whose helper asserts `result.is_produced()`, `CompletedSurfaceCells`, pure quads, provenance and accepted validation at `:147-225`).
3. `MilestoneGP27.ProductionSurfaceCellMatrixMatchesSupportedDisposition` (`tests/MilestoneGP27Tests.cpp:519`; the canonical manifest matrix includes `torus__surface_cells` and requires `EXPECT_TRUE(result.is_produced())` for every SurfaceCells case).

`ProductionManifestCases/MilestoneGP27SurfaceCellCase.RunsIndependentlyAndOwnsReturnedDiagnostics/2` is **not** part of the strict 3/3 because that parameterized ownership test deliberately does not require production success; it only checks payload ownership if a result is produced (`MilestoneGP27Tests.cpp:569-631`). This distinction is why it receives no G4-B001 credit.

Accordingly D9 final arithmetic is now frozen as **507 fresh processes**: inherited 491 + 13 named CP3 identities + the three strict G4-B001 identities above. The P27 matrix identity is one process even though it visits every SurfaceCells manifest case. No duplicate invocation of the parameterized ownership row is added.

### D1-D9 method self-audit

| Item | Reachable producer established | Per-conjunct falsifier | Accepted-gate edge cases checked | Bound / stop rule |
|---|---|---|---|---|
| D1 | exact-A3 periodic endpoint-state producer + A5 conjugation path | coordinate, face-gauge/branch, relation-value and orientation controls | nonzero-Z4/current storage-canonical periodic coverage | existing exact operations only; no search |
| D2 | real cross-region HardRail relation producer | endpoint gauge, placement branch, coordinate transport, reversal | nonzero matching/hard-carrier reachability required | two endpoint pairs, constant work |
| D3 | real OrdinaryFront relation + A6 collinear seam evidence | coordinate, scale, seam-transition removal/reversal, representation-only change | RA-2 seam quarter-turn semantics retained | no quotient-transport widening |
| D4 | A5 chart graph + typed source hard-feature authority | remove/add typed hard edge; inconsistent HardRail carrier | produced torus already carries PeriodicCut hard features | one immutable barrier set; no route reconstruction |
| D5 | optimizer/validator class-wide chart helpers and all representative-sensitive sites | incompatible representative/corner scope and missing common chart | RA-28b forbids selected-face membership assumption | O(total four-corner chart memberships) per quad; fixed projections under finite differences/line search |
| D6 | direct torus through real pipeline/optimizer/validator | source-row, output-row and corner-cycle permutation with non-vacuity | exact discrete equality + scaled continuous tolerance frozen | Review stop on any unexplained discrete difference |
| D7 | real A7 selected edge plus real-tracer seam-collinear witness | transition removal/tamper; HardRail cross-region labels | relation-kind dispatch prevents global sheet-ID comparison | one exact transition query; cross-region Periodic is Review stop |
| D8 | direct produced torus and direct CP3 products | named negative/tamper owner for each new rule | historical G4-B001 strict gate distinguished from diagnostic-only ownership row | no mechanism-only evidence may close direct debt |
| D9 | accepted 491 gate plus enumerated CP3 identities | exact-one selection and inherited-byte preservation | 497 entry gate; 507 final gate | selector449 optimizer outcome change is mandatory Review stop |

Lessons 199-205 are therefore satisfied without adding a hand-built substitute where a producer witness exists. Accounting remains **60 / 16 / 44**, debt **1**; `G4-B002` stays open until CP3 direct-production evidence is accepted.

## Definition disposition

`M6-DEFN-R5` is complete as a runtime-free Definition. RA-30 is published in `Architecture_M6_Frozen_Definitions.md`, and the first implementation plan is `Architecture_M6_CP3_CB1_Entry_Authority_Code_Build_Plan.md`, explicitly **HELD** pending independent Review. No source, test, fixture, selector, build, package, benchmark or Directional runtime is changed or executed by this Definition.

**Mandatory successor: `M6-DEFN-R5-REV`.** Review must independently re-derive D1-D9, the 497/507 arithmetic, the three strict G4-B001 identities, and the held CB1 boundary before implementation is released.
