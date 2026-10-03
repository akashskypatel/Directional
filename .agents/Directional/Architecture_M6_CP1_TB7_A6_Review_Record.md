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
