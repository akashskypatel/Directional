# M6-CP1-CB7-A6 Relation Validation Recovery — Code + Build Plan

**Owner:** `M6-CP1-CB7-A6`
**Authorized by:** `M6-CP1-TB6-A6-REV`, **as amended by its review-agent addendum (2026-10-02)**

> **Review-agent amendment. It overrides §3 and §4.2 below.**
> - **§3 Goal B is replaced by RA-13** (end of `Architecture_M6_Frozen_Definitions.md`). The TB6 residual comes from **gauge mixing**: OrdinaryFront identity is in the cut-domain placement gauge, while exact-A3 Periodic `g` is in the PeriodicCut relation-endpoint gauge. It is not legitimate holonomy.
>   - Publish every relation transport in the placement gauge (exact-A3 Periodic: `Γ_to⁻¹ ∘ g ∘ Γ_from`, derived from `make_periodic_relation_endpoint_state`) and verify it against the endpoint placement states in A5.
>   - **Keep the strict cycle rule** (`relationTransport == pathTransport`, else `QuotientHolonomyConflict`). Append the residual as a diagnostic suffix (`:residual=Q<k>,t=(x,y)`).
>   - Do **not** record-and-accept non-identity residuals.
> - **§4.2 is revoked.** Keep `M6CP1.CycleClosingRelationTransportConflictRejected` unchanged as focused 11. Do not add or rename to a "RecordsExactResidual" identity. **§4.1 stands** (focused 10 strengthened with a tamper-away-from-A5 branch).
> - **Goal A stands.** Use distinct A5 codes for the region and route mismatches, mapped to `InvalidHardRailTransport` at the adapter.
> - **§7 TB7:** the same 11 + 449 = 460 order as TB6 (focused 11 unchanged). Recovery-green also requires selector 446 and focused 6 PASS **under the strict rule**.
> - **Stop rules added:** if the exact-A3 Γ cannot be derived from `make_periodic_relation_endpoint_state` without new semantics, or if HardRail transport is not in the placement gauge, stop for Review.
**Turn type:** Code + Build only
**Runtime:** forbidden
**Successor if compile/package green:** `M6-CP1-TB7-A6-EXEC` -> mandatory `M6-CP1-TB7-A6-REV`

## 1. Goal and fixed variables

Recover exactly the two TB6-A6 accepted-prefix regressions without advancing A7/R4 or changing accepted selector/test authority:

1. restore the accepted reciprocal HardRail route/region validation at the A5 relation-publication boundary;
2. implement the Review-authorized cycle-closing residual-holonomy semantics while keeping every A6 certificate bound to immutable A5 relation authority.

Hold fixed:

- `OccurrenceId`, `SurfaceOccurrenceRelationId`, relation owner selection, quotient member-set identity and selected-forest determinism;
- all fixtures, selector449, selector448 prefix, routing449 and owner census;
- exact-once certificate/consumption semantics;
- OrdinaryFront identity transport and Periodic canonical semantic action;
- A7/R4/`G4-B002` work;
- fallback/recovery policies and public validator strength.

Do not refactor unrelated code.

## 2. Goal A — restore HardRail reciprocal semantic validation at A5

### Required implementation

At the point A5 publishes a HardRail `SurfaceOccurrenceRelationEvidence`, validate the reciprocal pair before freezing relation evidence:

- both sides carry the same accepted `HardRailId` under existing owner rules;
- `first.sourceTopologyRegion != second.sourceTopologyRegion`;
- `first.route == second.route.reversed()` exactly.

Failure remains the accepted `InvalidHardRailTransport` contract through the existing A5 adapter mapping. Only after these checks pass may A5 publish HardRail route/action/canonical transport evidence.

Do **not** duplicate this semantic predicate as a second downstream authority. A6 validates that its certificate matches the already-valid immutable A5 evidence.

### Falsifiers

- selector139 `HardRailPairChangedRouteContentRejectsStrictTransport` must reject `InvalidHardRailTransport`;
- selector142 `HardRailPairSameOrientationRejectsStrictTransport` must reject `InvalidHardRailTransport`;
- selector140 explicit rail-ID mismatch remains PASS under its accepted typed contract;
- no valid HardRail relation changes identity, owner, route direction or transport.

Stop and return to Review if restoring those predicates requires changing relation identity/equality, source-region semantics, fixture authority, or accepted test expectations.

## 3. Goal B — publish exact cycle residual instead of rejecting every nonidentity residual

### Frozen formula

For a cycle-closing relation oriented canonically `a -> b`:

- `D` = exact direct `relationTransport` from immutable A5 relation evidence;
- `P` = exact selected-forest path transport `a -> b`, composed under RA-4;
- `H = compose(P.inverse(), D)`.

A6 records `D`, `P`, and exact `H` in its cycle-closing consumption/certificate evidence. `H == identity` is an observed special case, not a universal acceptance predicate.

A nonidentity residual is accepted as exact evidence unless an independently frozen contract for that relation requires zero residual. General produced periodic torus relations in CP1 have no zero-residual obligation.

### Required validation seam

Removing the universal equality rejection must **not** make certificate tampering permissive. Before a certificate participates in forest/path/residual evidence, validate it against the exact immutable A5 relation record in canonical relation direction:

- relation ID/endpoints/kind match;
- canonical transport equals A5 `canonicalTransport`;
- kind-specific owner/equivalence/route/cut evidence matches A5 authority;
- selected relation step, when required, matches the same canonical A5 evidence;
- OrdinaryFront remains exact identity transport.

`publish_records_for_validation` must re-check the same semantic boundary rather than validating only certificate-internal self-consistency.

`QuotientHolonomyConflict` remains available for an algebraically inconsistent `(D,P,H)` record or an explicit zero-residual obligation. Do not use it merely because `H != identity`.

A7 may later project residual evidence but cannot use it to alter quotient class membership/topology.

### Falsifiers

- accepted selector446 and focused pair-swap row6 must no longer fail merely because the periodic cycle residual is nonidentity;
- selector232/444/448/449 stay green;
- exact-one relation consumption remains true for every A5-owned relation;
- tampering a certificate away from immutable A5 evidence must produce a typed A6 certificate/transport rejection rather than being accepted as “residual holonomy”.

Stop and return to Review if the code needs a new relation owner/equality, a global search/substitution for authority, or any A7 topology decision to make the residual coherent.

## 4. Focused test changes — no count expansion

Keep the frozen focused gate at **11** identities.

1. Strengthen existing `M6CP1.QuotientRejectsMissingDuplicateOrConflictingConsumption` so one branch tampers a quotient relation certificate away from A5 authority and requires a typed rejection. Do not fabricate a malformed OrdinaryFront transform that is invalid before the target seam.
2. Replace/rename the previous strict-holonomy negative `M6CP1.CycleClosingRelationTransportConflictRejected` with a positive exact residual identity, e.g. `M6CP1.CycleClosingRelationRecordsExactResidual`, which independently checks direct transport, selected-path transport and `H = compose(P.inverse(), D)` and requires a deliberately nonidentity residual.

No twelfth focused identity. Do not modify selector449 or any accepted selector test.

## 5. Static verification before compile

Verify from the exact source tree:

- changed paths are limited to the A5/A6 implementation/header surfaces and the two existing focused A6 test identities needed above;
- no fixture, selector, routing, benchmark or unrelated test byte changes;
- selector449 SHA-256 remains `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`;
- selector448 prefix remains `70ff08601bf244fcb4883e5d0601d5e7a3a44f52a8e855544a065c6ca5c75789` and byte-identical to selector449 rows1-448;
- routing449 remains `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707`, owners 32/301/75/41;
- `git diff --check` passes;
- no A7/R4/G4 implementation is present in the diff.

## 6. Compile/package boundary

Compile only through the durable GitHub reusable compile workflow with mandatory GMP/GMPXX. Compile/package the standard eight targets used by M6 CB turns. Generated Directional binaries must not execute: no tests, discovery, benchmarks, help/version commands, CLI/GUI, or `ctest`.

Package the usual source/evidence receipts and require `runtimeExecution=false`, clean source receipts and a self-excluding recursive manifest.

A compile failure may receive only the smallest same-turn compile repair consistent with Goals A/B. A semantic redesign, test-authority change or new product surface returns to Review.

## 7. Runtime successor gate

If and only if compile/package is green, exact successor is `M6-CP1-TB7-A6-EXEC` over the same shape:

- 11 focused identities in the same order, with the renamed residual identity occupying focused slot 11;
- selector449, 449 identities in exact file order and routing449;
- total **460** fresh exact-filter processes;
- exact-one selection, zero skips, benchmark 0, immutable pre/postflight;
- mandatory `M6-CP1-TB7-A6-REV` after any mechanically valid outcome.

Recovery-green requires 11/11 + 449/449 = **460/460 PASS**. In particular rows139/140/142/232/444/446/448/449 and focused5/6/7 plus the new residual identity must all be green. TB may not repair or rerun a mechanically valid RED.
