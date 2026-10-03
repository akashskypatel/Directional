# M6-CP1-TB7-A6 Review — HardRail Placement-Gauge Recovery

**Turn:** `M6-CP1-TB7-A6-REV`
**Type:** runtime-free Review + Plan
**Reviewed candidate:** `11257522199 / 40842caa88f8d7a08a38c91273ace77ebd7c0676`
**Authoritative TB7 run/job:** `37090507571 / 111109661723`
**Result/log artifacts:** `11262587435 / 11262387973`
**Disposition:** **CANDIDATE REJECTED / TWO STABLE RECURRENCES / ONE TEST-AUTHORITY DEFECT / CB8-A6 RECOVERY AUTHORIZED**

## 1. Review conclusion

TB7-A6 is mechanically valid and its semantic RED is authoritative. The immutable gate executed all **11 focused + selector449 = 460** exact-filter processes with exact-one selection, zero skips and no benchmark/configure/compile/relink/repair/retry. Outcome is focused **11/11 PASS**, selector **432/449 PASS**, aggregate **443/460 PASS / 17 RED**.

Independent Review re-opens the primary result evidence and exact source and adjudicates the three EXEC candidates as follows:

1. `M6-CP1-TB7-A6-EXEC-CAND-01` is **STABLE**, one recurrence of existing `RP-01 / AUTHORITY_DOMAIN_CONFLATION`. CB7 conflated a HardRail carrier/topology route transport with the relation's cut-domain placement transport. The seven direct HardRail failures and seven downstream reachability losses share that mechanism.
2. `M6-CP1-TB7-A6-EXEC-CAND-02` is **STABLE**, one recurrence of existing `VALIDATION_ORDER_SHADOWING`. Rows227/230 still fail closed, but the new A5 pair-reciprocity gate pre-empts the accepted individual route-authority diagnostic.
3. `M6-CP1-TB7-A6-EXEC-CAND-03` is **CLOSED / NON-STABLE TEST-AUTHORITY DEFECT**. Selector446 now materializes successfully; its sole failure is a stale assertion equating RA-13 placement-gauge selected-step transport with `SurfacePeriodicHolonomy::action()` in the relation-endpoint gauge.

Stable accounting advances from **57 events / 16 categories / 41 recurrences** to **59 events / 16 categories / 43 recurrences**. Produced-witness debt remains **1**. Candidate `11257522199 / 40842caa...` is rejected/unpromoted. Reviewed runtime authority remains TB5 `10879581622 / 82b86a285292379cfd92cdc4e10d74181b38f1e8`, selector449 **449/449**.

Exact successor is bounded runtime-free `M6-CP1-CB8-A6`, followed if compile/package green by fresh immutable `M6-CP1-TB8-A6-EXEC` over the same **11+449=460** shape and mandatory `M6-CP1-TB8-A6-REV`. `M6-DEFN-R4`, A7 and `G4-B002` remain held.

## 2. Evidence authority and independent re-derivation

### 2.1 TB7 evidence re-opened

Review independently verifies the retained TB7 result artifact ZIP against provider digest `sha256:87cfcda2502f10cfc74e04aecd6e32aaca629928dff966988f52751f59e44575` and its self-manifest **953/953**. The result self-manifest SHA-256 is `5a5abda8a8d51a4b75d2266fb0b34604e3d0d4179e731e48a52be5a18771508a`; execution/focused/selector ledgers are respectively:

- `fd41e71a538bb817cea5da989daf1e52a033d0a51818593ba03c3b8054bfa39f`;
- `f2a8cd85937258df3bd57767ce88b3b53f4faed826dfd68159e0a9544a30f11c`;
- `ac7883b7c652cdaedd21d19d5ed2867d6de6f11198f1fb9abf25d80efc8404e3`.

The 17 selector RED ordinals are exactly:

`115, 116, 122, 130, 132, 134, 137, 141, 143, 150, 176, 201, 217, 227, 230, 231, 446`.

Raw logs contain zero `QuotientHolonomyConflict` and zero `OccurrenceInvalidCornerAuthority`. `InvalidHardRailTransport` appears 10 times across 9 raw selector logs. Focused6/10/11 and selectors139/140/142/232/444/448/449 are green.

### 2.2 Exact source authority

Review source snapshot run `37094244645` materializes exact branch authority `ea826744832357d7234ebc9d34c3d23cb9865207`; artifact `11263094759` has provider digest `sha256:ef9755771633a0a94e4470ff351e46d42b81a7531e75dfc4daab63e17834e182`, internal source archive SHA-256 `7d1b837ef9a3fc1b781bd37594538859bdf327ed63190d1e094a1428de639b8b`, **5323** verified source files and `runtimeExecution=false`.

The CB7 package embeds semantic source archive `source-40842caa88f8d7a08a38c91273ace77ebd7c0676.tar.gz` with SHA-256 `2c8981c6da6e9e72b4977f2879a687e2ba1c6c042591bd82720936f69888d27f`. Review byte-compares the decisive implementation/test files between that packaged source and the current snapshot; all are identical: `RemeshPipeline.cpp`, `SurfaceCellTracing.cpp`, `PureQuadCompletion.cpp`, their relevant headers, `SurfaceCellTransitionQuotientTests.cpp`, `SurfaceCellsPhase10Tests.cpp`, and `SurfaceCellREPackageTests.cpp`. Static findings therefore apply to the exact runtime candidate rather than only to later documentation state.

## 3. Finding A — HardRail carrier route was promoted into the wrong transport domain

**Candidate:** `M6-CP1-TB7-A6-EXEC-CAND-01`
**Classification:** **STABLE / existing `RP-01 / AUTHORITY_DOMAIN_CONFLATION` recurrence**
**Accounting:** **+1 event / +1 recurrence / +0 categories**.

### 3.1 Direct evidence

The CB7 A5 HardRail branch correctly restores common rail owner, distinct source topology region and exact reversed-route reciprocity. It then publishes:

- `sharedEquivalence.route = first.route`;
- `sharedEquivalence.action = first.route.composed_transport()`;
- `storageTransport = sharedEquivalence.action`;
- two placement-state `action_matches` checks across the paired HardRail endpoints.

That last step crosses authority domains. Exact source in `assign_open_front_boundary_authority` constructs retained HardRail carrier steps with `TransitionStep::interior(..., GridAutomorphism::identity(), runOrientation)`. The route is exact transition/topology/carrier provenance; its composed transport is not thereby a map between the paired endpoint occurrences' cut-domain `LocalLatticeState` placements.

This is not a speculative interpretation. Row141 first establishes a valid reciprocal HardRail pair (common rail and exact reversed routes) and then materialization fails `InvalidHardRailTransport`. The direct accepted-green losses 115/116/141/143/150/217/231 all fail on the new HardRail placement-action condition. CB7's own RA-13 stop rule explicitly required Review if HardRail route transport proved not to be in placement gauge. That stop condition has fired.

### 3.2 Downstream grouping independently confirmed

The seven downstream REDs do not expose separate first mechanisms:

- 122 cannot find HardRail feature authority to tamper;
- 130/132/134 cannot reach the final oracle with non-empty remapped feature authority;
- 137 cannot reach final validation;
- 176 reaches `NotProductionReady` instead of its injected later-stage failure;
- 201 reaches `NotProductionReady` at `tracing` rather than its injected `arrangement` failure and never observes the expected rail/network state.

These identities previously depended on the same valid HardRail-producing path. Their first failures are loss of downstream reachability after A5 rejects that path, not independent newly-authored semantics. They are therefore grouped with the direct HardRail placement-domain defect as one stable event, not priced separately.

### 3.3 RA-14 — HardRail carrier route and placement transport are separate authorities

This Review freezes the following normative amendment to RA-13:

1. `PureQuadEquivalenceProvenance.route` remains the exact HardRail **carrier/topology/transition provenance**. It is validated structurally, carries source hard-feature edge/component evidence, and must remain exactly reciprocal across the relation pair.
2. HardRail `canonicalTransport` / selected-step `appliedTransport` is instead the unique **cut-domain placement transform** between the paired endpoint `LocalLatticeState`s in canonical relation direction.
3. For one source placement state `a` and destination state `b`, derive the only candidate grid automorphism directly from their exact state:
   - require equal `scaleLevel`;
   - `R = branch(b) ∘ branch(a)⁻¹`;
   - `t = b.latticeCoordinate - rotate(R, a.latticeCoordinate)`;
   - `T = {R,t}` and verify it with the existing `action_matches` predicate.
4. Derive `T0` independently for `first.fromLattice -> second.toLattice` and `T1` for `first.toLattice -> second.fromLattice`. The HardRail relation is valid only if both exist and `T0 == T1`. Otherwise fail closed with existing `InvalidHardRailTransport` through `HardRailTransportMismatch`.
5. Publish that unique placement map in `sharedEquivalence.action` and as A5 `canonicalTransport`; preserve `sharedEquivalence.route` separately. A6 continues to consume canonical A5 transport and keeps the strict cycle rule unchanged.
6. The completion selected-relation consumer must compare a HardRail selected step against orientation-adjusted `equivalence.action`, not recompute `equivalence.route.composed_transport()`. The route remains mandatory for the independent hard-feature component/topology certification already performed by `completion_certified_hard_rail_components`.
7. No consumer may infer quotient placement transport from carrier-route transport merely because both belong to the same HardRail evidence object.

This derivation is not circular: relation identity/owner, source regions and reciprocal route are independently fixed first, and the second endpoint pair is an independent coherence constraint on the placement map.

**Stop rule:** if the two exact endpoint pairs do not yield one unique transform, or another current consumer demonstrably requires route-composed transport to remain the quotient placement authority, stop for Review rather than weakening the endpoint check.

## 4. Finding B — malformed route authority is validated after A5 pair reciprocity

**Candidate:** `M6-CP1-TB7-A6-EXEC-CAND-02`
**Classification:** **STABLE / existing `VALIDATION_ORDER_SHADOWING` recurrence**
**Accounting:** **+1 event / +1 recurrence / +0 categories**.

Rows227/230 intentionally corrupt individual HardRail route topology. Accepted behavior is typed `InvalidHardRailAuthority`. They still fail closed under CB7, but now return `InvalidHardRailTransport` because A5's reciprocal route equality runs before the materializer's existing exact route-topology validator.

Exact source proves the ordering: `SurfaceOccurrenceComplexProducer::produce(...)` executes before the adapter defines/applies `exact_interior_route_valid`; malformed individual route content can therefore be compared as a relation pair before its own source transition/topology authority is established.

### RA-15 — individual route authority precedes relation-pair reciprocity

CB8 must preserve the accepted typed ordering without weakening the recovered row139/142 reciprocity checks:

1. Extract/reuse the existing exact individual interior-route validator rather than maintaining two divergent implementations.
2. Run the individual HardRail/Periodic route source/topology validity preflight **before** `SurfaceOccurrenceComplexProducer::produce(...)` can publish relation-pair evidence.
3. Preserve accepted adapter failures: malformed HardRail route -> `InvalidHardRailAuthority`; malformed Periodic route -> its existing `InvalidPeriodicCutAuthority` path.
4. Once an individual route is valid, A5 still requires HardRail common owner, different source region and exact reversed-route pair; those relation-pair mismatches remain `InvalidHardRailTransport`.
5. Remove/avoid a duplicate later semantic validator after the earlier shared preflight so one predicate owns the route-authority contract.

Rows227/230 are the typed-order falsifiers. Rows139/142 and row140 are non-weakening controls.

## 5. Finding C — selector446 pins the pre-RA-13 representation

**Candidate:** `M6-CP1-TB7-A6-EXEC-CAND-03`
**Classification:** **CLOSED / NON-STABLE TEST-AUTHORITY DEFECT**
**Accounting:** **+0**.

Selector446 now clears the production behavior that TB6 was intended to recover:

- materialization succeeds;
- focused6 passes the same nonzero-Z4 witness under storage swap;
- no raw log contains `QuotientHolonomyConflict`;
- selectors232/444/448/449 remain green.

Its only failing assertion occurs after successful materialization. The test scans selected relation steps and requires `step.appliedTransport == relation->action()` or inverse. Exact-A3 RA-13 intentionally changed `appliedTransport` to the placement-gauge map `Γ_to⁻¹ ∘ g ∘ Γ_from`; `relation->action()` remains semantic `g` in `SurfacePeriodicRelationEndpointState` relation-endpoint gauge. The test compares two different authorities and is stale.

### Authorized test-only migration

CB8 may change only selector446's assertion body, not its identity or selector449 bytes. The replacement oracle must remain independent and stronger than a tautological product echo:

1. Preserve the existing checks that published periodic endpoint states match `make_periodic_relation_endpoint_state` and that semantic `g` maps those endpoint states correctly.
2. Independently derive the direct placement map from the paired `LocalLatticeState` endpoints using the same exact state-to-state formula frozen in RA-14.
3. Independently derive the gauge-conjugated map `Γ_to⁻¹ ∘ g ∘ Γ_from` from the published endpoint states and semantic action.
4. Require those independently derived placement maps to agree.
5. Require the selected periodic step for the relation to equal that placement map or its exact inverse according to step direction.

Do not change row446 into “compare selected step with A5 canonicalTransport” alone; that would only restate the product under test.

## 6. Non-vacuity, controls and carried obligations

- Focused6 PASS proves the nonzero-Z4 periodic strict-cycle recovery itself is no longer broken.
- Focused10/11 PASS preserve exact-once/certificate-conflict and strict cycle-conflict rejection.
- Selector139/142 PASS prove CB7's recovered HardRail pair reciprocity is live; selector140 keeps independent owner mismatch live.
- Selectors232/444/448/449 PASS preserve periodic control populations and the accepted full selector tail.
- The HardRail direct failures plus downstream seam losses make RA-14 falsifiable; CB8 cannot merely delete the placement check.
- Rows227/230 make RA-15 falsifiable; CB8 cannot merely update expected error strings.
- A7, `M6-DEFN-R4`, `G4-B001`, `G4-B002`, `G4-B004` representative-consumption work and CP1 closure remain carried and held.

## 7. Accounting and promotion

Review prices exactly two stable mechanisms:

1. CAND-01 -> one `RP-01 / AUTHORITY_DOMAIN_CONFLATION` recurrence;
2. CAND-02 -> one `VALIDATION_ORDER_SHADOWING` recurrence.

CAND-03 is a test-authority correction and contributes no stable event. Stable accounting is therefore **59 / 16 / 43**, debt **1**.

Candidate `11257522199 / 40842caa...` is rejected/unpromoted. Reviewed runtime authority remains package/source `10879581622 / 82b86a285292379cfd92cdc4e10d74181b38f1e8` with selector449 **449/449**.

## 8. Exact successor — `M6-CP1-CB8-A6`

CB8 is a bounded Code + Build turn under `Architecture_M6_CP1_CB8_A6_HardRail_Placement_Transport_Recovery_Code_Build_Plan.md`. It may modify only:

- A5 HardRail placement-transport derivation/publication;
- the one HardRail selected-relation completion consumer that currently substitutes route-composed transport for placement transport;
- individual route-validation ordering/shared helper needed for rows227/230;
- selector446 test body and bounded focused/static assertions needed to directly falsify RA-14/RA-15 without increasing the frozen focused count.

It may not change selector449/routing449 bytes, fixtures, relation identity/equality/owner selection, A6 strict cycle semantics, A7/R4/G4 surfaces, or accepted failure strength.

Compile/package green -> fresh `M6-CP1-TB8-A6-EXEC` over **11 focused + selector449 = 460** exact fresh processes -> mandatory `M6-CP1-TB8-A6-REV`.

## 9. Review closeout

| Duty | Result |
|---|---|
| Primary runtime evidence re-opened | TB7 result ZIP/provider digest, 953/953 self-manifest, ledgers, raw RED logs and controls independently inspected. |
| Exact source independently re-opened | Runtime-free snapshot `37094244645 / 11263094759` verified; decisive source/test files byte-identical to packaged semantic source `40842caa...`. |
| Candidate mechanisms adjudicated | CAND-01 stable RP-01; CAND-02 stable validation-order shadowing; CAND-03 closed non-stable test authority. |
| Stable accounting | **59 / 16 / 43**, debt 1. |
| Normative amendments | RA-14 HardRail carrier/placement separation; RA-15 individual route validation precedes pair reciprocity. |
| Test authority | Selector446 body migration authorized with independent direct-placement + gauge-conjugation oracle; identity/selector bytes frozen. |
| Promotion | TB7 candidate rejected; TB5 reviewed runtime retained. |
| Successor | Exactly one: `M6-CP1-CB8-A6`; then TB8-A6 460-process gate + mandatory Review. |
| Turn boundary | Runtime-free Review; no generated Directional executable executed. |
| Consolidation | Superseded CP1 per-turn docs are folded into `M6_Consolidated_Record.md`; current TB7 report, this Review, one CB8 plan, frozen definitions and selectors remain. |
| Tool-call ledger | **unknown/partial** after context compaction; not reconstructed by extra tool calls, per conservation policy. |

---

## Review-agent addendum (2026-10-03, resumed `M6-CP1-TB7-A6-REV`)

**This addendum overrides §§3.3, 5, 7 and 8 above where they conflict.**

| Item | Result |
|---|---|
| Evidence re-derivation | Confirmed |
| Finding A diagnosis | Confirmed |
| Finding B diagnosis | Confirmed |
| RA-14 derivation | **Corrected** (RA-16) |
| RA-15 location | **Pinned to A5** |
| Finding C | **Overturned:** production regression, +1 stable |
| CB8 plan | **Amended:** the selector446 migration and the completion-consumer edit are revoked; focused identity 12 is added; TB8 becomes **12 + 449 = 461** |

- Stable accounting: **60 / 16 / 44**, debt **1**.
- Candidate `11257522199 / 40842caa...` stays rejected. Reviewed runtime authority stays TB5 `10879581622 / 82b86a28...`.
- Successor is unchanged: `M6-CP1-CB8-A6`, as amended.

### G1. Independent re-derivation (confirmed)

**Artifact.**
- I downloaded result artifact `11262587435` again. The ZIP SHA-256 equals the provider digest `87cfcda2...44575`.
- `SHA256SUMS` verifies **953/953**; the manifest is `5a5abda8...`.
- The execution, focused and selector ledgers are `fd41e71a...`, `f2a8cd85...` and `ac7883b7...`.

**Selector ledger.**
- Its identities equal selector449 (`d4a0d1b7...d6414`) in exact file order.
- Outcome is **432 PASS / 17 RED**, at exactly 115, 116, 122, 130, 132, 134, 137, 141, 143, 150, 176, 201, 217, 227, 230, 231 and 446.
- Every row has selected=1 and skipped=0. Focused is 11/11 PASS.
- The boundary file records 460 executed, no orchestration failure, and every repair/mutation/retry flag false.

**Raw first failures.**
- 115/116/141/143/217/231: `materialized.success` is false with `InvalidHardRailTransport`.
- 150: `NotProductionReady:tracing:InvalidHardRailTransport`.
- 227/230: expected `InvalidHardRailAuthority`, actual `InvalidHardRailTransport`.
- 446: materialization succeeds, then only `EXPECT_TRUE(selected)` fails (tests `:4213`).
- All 460 raw logs contain zero `QuotientHolonomyConflict`.

**Downstream grouping, verified in code (the logs alone cannot show it).** Rows 122/130/132/134/137 assert reachability before printing any root code. The grouping holds because:
- component stage products, including `authoritativeRails`, are published only on the success path (`RemeshPipeline.cpp:11912`);
- `captureFinalValidationAuthority` returns early when `!run.result.is_produced()` (`:14302`).

So once a HardRail component fails to materialize:
- row 122's hook still sees `Produced` from the phase-front producer, but finds no HardFeature rail to tamper;
- rows 130/132/134/137 never observe feature authority;
- rows 176/201 stop `NotProductionReady` at `tracing` (row 201's log shows stage `tracing`).

**Source identity.** HEAD `src/`, `include/` and `tests/` are byte-identical to `40842caa` (`git diff 40842caa..HEAD` is empty), so every citation below is the exact runtime candidate.

### G2. Finding A is confirmed, but RA-14's remedy depends on the face gauge

**Diagnosis confirmed.** Retained HardRail carrier steps are published as `TransitionStep::interior(topology, transitionId, GridAutomorphism::identity(), runOrientation)` (`SurfaceCellTracing.cpp:11670-11672`). `route.composed_transport()` is therefore always identity for HardRail. It records which source edges the rail runs along, not the map across the rail.

**Defect in the remedy.** RA-14 derives `R = branch(b) ∘ branch(a)⁻¹`. But `LocalLatticeState.branchRotation` is face-gauged, not a pure lattice frame:

- Cell corner states take `branchRotation = faceBranchRotation[selected source face]`, plus the region's `chartUBranch` (`SurfaceCellTracing.cpp:12094-12095`, `:16324-16326`).
- `faceBranchRotation` is propagated **per topology region**, starting from that region's own root (value 0), across dual edges by FieldTransportAtlas transport (`:14920-14985`; `resolve_branch_transition` uses `atlas->transport`, `:6409+`).
- A3 strips this face gauge before it compares periodic endpoints (`make_periodic_relation_endpoint_state`, `:7926-7931`).
- A4 certifies exact-A3 periodic correspondence only in that face-free relation-endpoint gauge (`:8262-8291`). A4 certifies no lattice relation across a HardRail at all.

Consequence: take endpoint states `a` (region A, selected face `f_a`) and `b` (region B, face `f_b`). Then

  `branch(b) − branch(a) = R_true + τ(f_a → f_b)`,

where `τ` is the field matching across the rail between the two selected faces. RA-14's `R` is the true lattice rotation only when `τ = 0`.

**Why the gate cannot see it.**
- Every HardRail fixture in the 460 gate uses a constant field: `constant_xy_field` / `constant_xy_raw_field` (e.g. `hard_rail_fixture`, the rectangular builder in `SurfaceCellsPhase10Tests.cpp`). So `τ = 0` everywhere and RA-14 would pass TB8.
- Nonzero matching across hard carriers is real. The repo's own nonzero-Z4 witness has to search for hard carriers whose matching is nonzero (`SurfaceCellTransitionQuotientTests.cpp:1351-1363`).
- On a separating rail with `τ ≠ 0`, RA-14 yields `T0 ≠ T1` for a valid pair, because the edge vector does not rotate by `τ`. It fails closed with `InvalidHardRailTransport`.

That is a production regression selector449 cannot detect.

**The "non-circular" claim.** RA-14 §3.3 says its derivation is not circular. Re-checking a state-derived `T` with `action_matches` is tautological for that same pair. The only real content is `T0 == T1`, i.e. rigidity of the edge correspondence. RA-16 keeps exactly that rigidity check without the face gauge.

**Second defect: wrong source states.** A5 derives transports from the `SurfaceFrontEdge` lattice copies (`first.fromLattice`, ...). The adapter only checks those copies against the cell corners afterwards (`lattice_equal`, `RemeshPipeline.cpp:5798-5806`).
- So tampering an edge lattice on a HardRail or Periodic edge now fails as a transport error instead of `InvalidAuthoritativePhaseFrontSideAuthority`.
- Only the OrdinaryInterior variant is pinned (tests `:3251-3263`).
- RA-16 therefore derives from the endpoint occurrences' `placement.lattice`, which are the objects the relation actually unites.

### G3. Finding C is overturned: selector446 falsifies a production lineage regression (+1 stable)

**Mechanism (three steps).**
1. A5 builds the lineage selected step with `step.appliedTransport = evidence.canonicalTransport` (`RemeshPipeline.cpp:4357`).
2. A6 requires `selectedRelationStep->appliedTransport == canonicalTransport` for HardRail and Periodic certificates (`:4723-4724`, `:4749-4750`).
3. RA-13 changed `canonicalTransport` to the placement gauge for the A6 certificate. Through steps 1-2, CB7 therefore also changed the representation of the M5 lineage `SelectedRelationStep.appliedTransport`. RA-13 never authorized that.

**Production consumer.**
- `close_completion_lineage_source_authority` validates every selected step against its lineage equivalence:
  - HardRail: orientation-adjusted `equivalence.route.composed_transport()` (`PureQuadCompletion.cpp:1086-1092`);
  - Periodic: orientation-adjusted `equivalence.action` (`:1105-1128`);
  - otherwise it fails `CompletionOwnershipSelectedRelationValueMismatch` (`:1132`).
- The authoritative pipeline runs this check immediately after materialization (`RemeshPipeline.cpp:10705-10719`) and fails `NotProductionReady` at `completion`.
- Periodic `equivalence.action` is `storedRelation.action()`, i.e. `g` (`:4234`). For any exact-A3 relation with `Q ≠ 0`, the placement map is neither `g` nor `g⁻¹`, so production completion rejects it.
- The gate is blind to this: the nonzero-Z4 witness is materialized only, never completed.

**Selector446 mirrors that check.** Its predicate (`SurfaceCellTransitionQuotientTests.cpp:4204-4213`) is the same comparison production completion makes. It is not stale; it is the gate's only falsifier of this defect.

**What the TB7-REV CB8 plan would have done.**
- (a) Migrated selector446, which deletes that falsifier.
- (b) Changed only the HardRail half of the completion check (plan §2.3). The periodic half would still compare against `g`, so the defect ships.
- (c) Written the placement map into HardRail `equivalence.action` (RA-14 item 4). That field is hashed (`RemeshPipeline.cpp:2718`), checked during component aggregation (`:15533-15537`) and benchmark-hashed (`BenchmarkQuality.cpp:1131`). This contradicts lesson 185, which TB7-REV itself recorded.

**Correction (RA-16 §3): decouple the two values.**
- A5 publishes two A5-owned values per relation, both in canonical direction:
  - `canonicalTransport`: placement gauge; feeds the A6 certificate and the strict cycle rule;
  - `canonicalRelationValue`: the M5 lineage relation value. That is identity for OrdinaryFront, `route.composed_transport()` for HardRail, `g` oriented for exact-A3 Periodic, and the existing selected action for non-A3 Periodic.
- The selected step carries `canonicalRelationValue`.
- A6 already keeps `pathCertificate.composedTransport` (placement) separate from `legacyProjection` (`:4912-4924`; validator `:5339-5346`).
- Result: the lineage projection is byte-identical to the pre-RA-13 projection on every accepted row. Completion and selector446 stay unchanged.

**Accounting.** One event and one recurrence of `RP-01 / AUTHORITY_DOMAIN_CONFLATION`: the A6 quotient-certificate transport and the M5 lineage relation value were conflated through one field.
- Root cause: RA-13 (review agent) did not list the consumers of `canonicalTransport`, and CB7 inherited the field coupling.
- Stable accounting becomes **60 / 16 / 44**, debt 1.

### G4. Finding B is confirmed; RA-15 moves into A5

**Diagnosis confirmed.**
- Row 227 duplicates a route step (tests `:5233-5250`); row 230 replaces a step's interior transition id (`:5190-5230`).
- Both routes are individually invalid under the adapter's `exact_interior_route_valid` (`RemeshPipeline.cpp:5752-5773`). That check only runs after A5: A5 runs at `:5711`, the check at `:5884-5888`.

**Controls survive the reorder.**
- Row 139 swaps in another real edge's route, and row 142 copies `first.route`. Both routes are individually valid (`SurfaceCellsPhase10Tests.cpp:6804-6843`), so they still reach the reciprocity check.
- Row 140 is an owner mismatch and is unaffected.

**Location correction.**
- A5 already receives the needed inputs: `produce(sourceVertices, sourceFaces, phaseFront)` (`:3284`).
- Extract the predicate once as a free function. A5 applies it to both HardRail sides before any pair predicate, with a distinct A5 code `HardRailRouteAuthorityInvalid` that maps to `InvalidHardRailAuthority`.
- The adapter keeps calling the same function for unpaired and exterior edges.
- Do not build an adapter-wide preflight. It would change precedence against every other per-edge adapter check, and it keeps semantic validation in the adapter, against the CP1 thin-adapter exit criterion.
- Periodic is already covered upstream: A4 rejects non-reciprocal and renumbered exact-A3 periodic routes during product construction (`SurfaceCellTracing.cpp:8218-8225`).

### G5. Exact-A3 Periodic: a latent issue, carried to R4

CB7's `periodic_endpoint_gauge` (`RemeshPipeline.cpp:4034-4060`) builds Γ state-to-state, so Γ includes a rotation by `[Q]−F` about the endpoint. Its final `action_matches` (`:4293-4299`) then compares face-gauged branches.

- A4 constructs relation endpoints with `Q = g.rotation`. Under that convention, `T = Γ_to⁻¹ ∘ g ∘ Γ_from` has linear part `rot(F_rt − F_ff)`.
- `T` equals the coordinate map `rot(Q)⁻¹ ∘ g` exactly when the face gauges at corresponding corners agree (`F_rt = F_ff`).
- Otherwise `T_from ≠ T_to`, and an A4-valid product is rejected with `PeriodicTransportMismatch`.
- The non-constant-field witness has equal gauges (focused6 and 446 materialize), so no gate row reaches the other case.

Disposition: no change in CB8, since the output is provably identical whenever CB7 accepts. `M6-DEFN-R4` carries an obligation to supply a witness with unequal corner gauges and to replace the face-gauged final check with coordinate and relation-gauge checks. Focused 12(c) pins the coordinate rule meanwhile.

### G6. Review-agent accountability (RA-13)

- **Item 1** mandated `action_matches` on face-gauged placement states for every relation. That is unsound across faces: applied to OrdinaryFront, it would reject valid relations whose two sides select faces with nonzero matching. CB7 happened not to apply it there.
- **Item 4** predicted selector446 would PASS. I did not audit the assertions over `appliedTransport`, nor the consumers of `canonicalTransport` (lesson 180 again).
- **The HardRail clause** handed a statically answerable question to a stop rule that a runtime-free CB could not fire reliably. `SurfaceCellTracing.cpp:11670-11672` already answered it.

Lessons 186 and 187 record these.

### G7. Closeout

| Duty | Result |
|---|---|
| Primary evidence | Result ZIP digest, 953/953 manifest, three ledgers, 460 raw logs and selector order independently verified. |
| Source authority | HEAD source is byte-identical to `40842caa`; every citation is to the runtime candidate. |
| Finding A | Diagnosis confirmed. Remedy replaced by RA-16 §2: coordinate-rigid derivation from occurrence placements; no cross-region branch comparison. |
| Finding B | Confirmed. RA-15 location pinned to A5 (RA-16 §5). |
| Finding C | **Overturned.** Production lineage-contract regression (`PureQuadCompletion.cpp:1086-1132`, `RemeshPipeline.cpp:10705-10719`). Selector446 retained as falsifier. +1 stable RP-01. |
| Accounting | **60 / 16 / 44**, debt 1. |
| Definitions | RA-16 frozen. RA-14 items 2-5 superseded; RA-13 item 1 withdrawn; RA-15 item 1 located. |
| CB8 plan | Amended: decoupling, coordinate-rigid HardRail, A5-owned route validity, selector446 unchanged, `PureQuadCompletion.cpp` untouched, focused 12 added. |
| TB8 gate | **12 focused + selector449 = 461** fresh exact-filter processes; recovery-green **461/461**. |
| Carried | R4: periodic coordinate-rule replacement with a face-gauge witness, cross-region branch certification, OrdinaryFront coordinate identity across isolation seams. |
| Turn boundary | Runtime-free; no generated Directional executable run. |
