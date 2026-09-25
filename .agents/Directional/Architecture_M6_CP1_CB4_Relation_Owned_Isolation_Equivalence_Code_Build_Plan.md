# M6-CP1-CB4 — Complete Seam-Incident Occurrence/Lineage Authority Code + Build Plan

**Status:** HELD / RE-SCOPED BY `M6-DEFN-R2` / IMPLEMENTATION NOT AUTHORIZED UNTIL `M6-DEFN-R2-REV` ACCEPTS
**Turn type:** Code + Build, runtime-free
**Required predecessor:** accepted `M6-DEFN-R2-REV`
**Expected successor if compile/package green:** `M6-CP1-TB4-EXEC`
**TB4 gate:** 7 focused identities + unchanged selector449 = **456 fresh exact-filter processes**
**Compile boundary:** standard eight GMP/GMPXX targets only; no generated Directional binary may execute.

## 1. Goal

Implement only the accepted `M6-DEFN-R2` A5/A6/A7 seam-incident authority amendments. The change must make complete corner-wedge sheet/binding/evidence authority survive occurrence construction, quotient consumption, component remapping and final lineage materialization without changing semantic occurrence identity, quotient equality, accepted M5 relation owners, or any frozen test/selector byte.

Normative authority is `Architecture_M6_Frozen_Definitions.md` as amended by `Architecture_M6_DEFN_R2_Seam_Incident_Authority_Amendment_Definition_Record.md`. If Review changes any R2 rule, update this plan before implementation.

## 2. Immutable boundaries

Do not change:

- `OccurrenceId=(CellId, canonicalCornerRole)` or A4 `CellId` semantics;
- `OccurrenceRelationId` or relation-only quotient equality;
- `OrdinaryFront` ownerlessness;
- accepted HardRail/Periodic owner/action/transport semantics;
- M5 producer relation/certificate facts;
- test assertions, fixtures, selector449, routing449, benchmarks, or accepted test names;
- source-grid recovery, fallback, validators, or unrelated production code;
- A4 products or builder topology to make A5 easier.

Do not weld by coordinate/position, search a global certificate inventory, choose unused valid relations, or invent a representative sheet/chart.

## 3. Scope A — complete A5 corner authority

1. Materialize `CornerWedgeFaceBindings` for every occurrence as the ordered admissible cell-interior fan.
2. Materialize ordered `CornerWedgeIsolationEvidence` and directed-side isolation evidence as exact `(region,seam,fromSheet,toSheet)` tuples.
3. Apply the R2 exact support-span rule to all three side builders. For source-edge-collinear spans, derive the cell-interior incident face from accepted cell orientation and source winding; never use the builder's tie-broken face for semantic sheet/chart authority.
4. Enforce P3/P4 fail-closed exclusions for singular/nonmanifold/SingularityPort and hard-rail-crossing wedge cases.
5. Preserve one region per wedge and one chart component per admissible wedge.

**Verify statically:** every builder path reaches the same helper/rule; no semantic caller uses source-face row/lexicographic triangle selection for seam-collinear authority.

## 4. Scope B — exact A5 failure split and compatibility adapter

Add the R2 semantic failures:

- `OccurrenceHardRailOwnerMissing`;
- `OccurrenceHardRailOwnerMismatch`;
- `OccurrencePeriodicOwnerMismatch`;
- `OccurrenceRelationKindMismatch`;
- `OccurrenceUnownedRelation` only for genuinely unowned cases;
- P3/P4 typed unsupported-corner failures.

Implement exactly one transitional compatibility mapping to the frozen M5 external names. Remove only structural duplicate predicates already proved by the accepted A5 certificate: owner presence/equality and relation-kind compatibility. Keep route reversal/content, periodic shift, exact relation values, transport application, support, and every semantic M5 falsifier.

**Verify statically:** no former accepted typed M5 defect maps to success or unrelated generic failure.

## 5. Scope C — B1 lineage-equivalence projection

Add `PureQuadEquivalenceKind::CornerWedgeIsolation` and an authoritative ordered isolation-transition payload equivalent to:

```text
(region, seam, fromSheet, toSheet)
```

Rules:

- evidence-only; never an A5 `ownedRelation`;
- no front-edge/HardRail/Periodic owner;
- no selected relation path;
- deduplicate by complete ordered semantic transition sequence;
- include new fields in deterministic structural hashing, benchmark structural evidence, aggregation/remap and serialization paths that already expose lineage equivalences.

**Verify statically:** existing HardRail/Periodic consumers remain kind-gated and decision-neutral to the new kind.

## 6. Scope D — B2 exact binding consumers and component remap

1. Replace scalar occurrence sheet/chart use in transitional class/domain duplicate keys with the complete canonical binding signature.
2. Keep semantic `QuotientClassId` as the sorted member-OccurrenceId set; any numeric class row remains adapter-local.
3. Make representative selection use exact support + complete binding signature + semantic OccurrenceId; representative choice cannot define semantic authority.
4. Select HardRail/Periodic path chart/component from the relation-side interior-face binding for each endpoint.
5. Derive path start/end charts from selected relation steps, not quotient representative faces.
6. Remap full binding and isolation-transition tuples first; only then derive legacy region/sheet/chart lineage projections.
7. Derive lineage `sourceCharts` from the union of all member face bindings.

**Verify statically:** rows 444/448 remain selected-relation exact and no code searches alternatives because a new binding was introduced.

## 7. Scope E — P1/P2 reciprocal side validation

Implement ordered maximal positive-length support-span evidence. Near-endpoint classification is per span:

- ordinary non-collinear reciprocal sides require mapped interior-sheet agreement and membership in both endpoint wedge sets;
- seam-collinear reciprocal sides require the same exact seam certificate/span, opposite incident faces/sheets, and reverse-compatible transition lists.

Use typed `QuotientReciprocalSideAuthorityMismatch` for disagreement. Do not silently fall back to representative sheet equality.

## 8. Required new focused identity

Strengthen the already-pre-registered seventh identity:

`M6CP1.SeamEndpointOccurrencesPublishCompleteCornerWedgeSheetAuthority`

It must construct/materialize the analytic split-square and assert at minimum:

- v0: lineage sheets `{0,1}`, non-empty `CornerWedgeIsolation`, exact expected transition orientation;
- center: lineage sheets `{0,1}`, non-empty exact isolation lineage evidence;
- v2: lineage sheets `{0,1}`, non-empty `CornerWedgeIsolation`, reciprocal transition orientation;
- every other lattice vertex is single-sheet;
- the new equivalence kind does not populate selected HardRail/Periodic relation paths;
- source-face-row permutation preserves semantic identity and structural hash.

No other test may be edited unless mandatory Review explicitly amends this plan.

## 9. Frozen static regression audit before compile

Before publishing the compile candidate, re-open but do not edit:

- focused row5 `MultiIsolationMaterializationRetainsAllLocalSheets`;
- focused row6 periodic pair storage semantic-direction test;
- selector rows 186, 214, 239, 444, 446, 448;
- accepted Phase10 HardRail single-sheet assertions.

Demonstrate in the Code + Build report why each remains satisfiable under the concrete implementation. Hash selector449/routing449 and prove byte identity.

## 10. Compile-only build

Use only `.github/workflows/agent-compile-reusable.yml`, with mandatory GMP/GMPXX linkage, to compile/package the standard eight targets required by current M6 policy. Do not execute any generated Directional test, benchmark, discovery, list, help, CLI, or other binary. Package evidence must say `runtimeExecution=false` and include the normal recursive manifest/source receipts.

A compile failure may receive only a bounded compile correction within this same Code + Build turn. Any semantic ambiguity stops the turn instead of inventing authority.

## 11. Stop rules

Stop for Review/Definition if any of the following occurs:

- the exact cell-interior source face is not uniquely derivable after accepted A4 orientation;
- an admissible wedge needs more than one chart component or crosses a hard rail/region boundary;
- complete binding semantics require changing A4 `CellId`, `OccurrenceId`, `OccurrenceRelationId`, or relation-only quotient equality;
- row5 can pass only by inventing an A5 relation for v0/v2;
- rows 444/448 require selecting or searching a different Periodic relation;
- an accepted M5 typed failure must be weakened or renamed generically;
- any frozen test, fixture, selector, routing receipt, benchmark, or unrelated source must change;
- product runtime would need to execute during Code + Build.

## 12. Exit gate

CB4 may close only when:

1. the concrete code matches every accepted R2 rule;
2. the strengthened seventh identity compiles;
3. all standard eight GMP/GMPXX targets compile/link;
4. selector/routing bytes are unchanged;
5. no generated Directional runtime executed;
6. compile/package evidence is complete and source-clean.

Then and only then authorize immutable `M6-CP1-TB4-EXEC` over exactly **456 fresh exact-filter processes**, followed by mandatory `M6-CP1-TB4-REV`. CB4 itself grants no runtime credit, promotion, debt discharge, or milestone closure.
