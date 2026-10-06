# M6-DEFN-R5 — CP3 Entry Definition Record (WIP)

**Turn:** `M6-DEFN-R5`  
**State:** IN PROGRESS — bounded turn; D1-D4 decided below, D5-D9 intentionally not compressed into this session.  
**Turn type:** runtime-free Definition. No Directional executable was run and no source/test/fixture/selector/build byte was changed.  
**Mandatory successor while WIP:** `M6-DEFN-R5` (resume). After D1-D9 are complete, mandatory successor becomes `M6-DEFN-R5-REV`.

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
