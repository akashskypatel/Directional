# M4-CP-SCALE-CB23 — source-boundary global-cycle authority Code + Build plan

**Turn:** `M4-CP-SCALE-CB23`
**Type:** Code + Build
**Prerequisite:** `M4-CP-SCALE-DEFN-R1` COMPLETE / D1-D5 frozen
**Runtime boundary:** COMPILE/PACKAGE ONLY — generated Directional binaries MUST NOT execute.

## Goal

Replace the invalid vertex -> single-regional-boundary owner representation for producer boundary aliases with the frozen source-global boundary-cycle authority and exact support-association reconciliation, without changing interior separating/slit semantics or accepted selector/fixture authority.

## Success criteria

1. A typed source-global boundary-cycle identity/fact exists independently of `TopologyRegionId`/`FieldCycleId` and owns the producer numeric index from the existing full-cycle index computation.
2. Every legacy boundary alias is exactly reconciled to that producer fact before collapse; missing/duplicate/foreign/wrong-numerator aliases reject.
3. One source-global boundary cycle can associate with multiple regional `BoundaryLoop`s. Their true source-boundary edge subsets form a disjoint exact cover of the global loop and preserve source component identity.
4. No comparison remains between global boundary `indexNumerator` and regional `BoundaryLoop.turningLift`.
5. Source-boundary global facts publish no `FieldSingularityFact` and no singularity ports; interior separating and same-region slit owners retain their existing semantics.
6. The R9 skew four-triangle control is representable without minimum-region selection: its one source-global boundary cycle has support in both real regions while center4's interior separating owner remains stable.
7. Source-face row/orientation permutation preserves the global boundary key and association set.
8. Selector426/first425 and retained genus-two fixture/rawfield bytes are unchanged; no selector427 exists.
9. Mandatory exact-source compile/package is GREEN under GMP/GMPXX and records `runtimeExecution=false`.

## Assumptions frozen by DEFN-R1

- `FieldCycleWitness::BoundaryLoop` is region-relative by type; its `turningLift` is not global source-boundary index authority.
- The producer's existing complete-source cycle-index computation is the sole numeric source for a source-boundary index. CB23 may expose that fact but may not recompute a second number in A1.
- Regional association is exact source-edge support/incidence, not ownership of the global value.
- Interior `rawSingularity` ownership continues to use local/slit/separating owner classes and exact-one-owner rules.

## Bounded implementation surface

Expected semantic surface, subject to the stop rules below:

- `include/directional/authority/AuthorityIds.h` — add a typed source-boundary-cycle identity if no already-suitable exact type exists.
- field result contract/finalization (`include/directional/fields/**`, `src/fields/FieldMatching.cpp` or the minimal existing owner) — expose source-global boundary cycle facts from the same `fullIndices` computation.
- `include/directional/authority/FieldTransportAtlas.h` — publish the global facts/associations and keep diagnostics non-authoritative.
- `src/authority/FieldTransportAtlas.cpp` — replace `boundaryCycleByGlobalVertex` one-owner semantics with D1-D4 reconciliation; do not alter CB21 interior owner semantics.
- `tests/FieldTransportAtlasTests.cpp` — focused producer-consistent positive/negative/permutation controls only.

Do not refactor unrelated cycle, trace, topology, or port code. If exact type ownership can be implemented with a smaller existing type surface, use the smaller change.

## Required focused test authority to compile

Author tests that, when a later TB executes them, can falsify all of the following independently:

- mutate exactly one legacy boundary alias numerator -> reject;
- omit one expected alias or duplicate/foreign-map an alias -> reject;
- one hard-cut source boundary cycle supports two regional boundary loops -> atlas construction succeeds and retains both support associations;
- remove one source-boundary edge from support or make two regional loops claim the same source-boundary edge -> reject;
- reverse source-face storage/order while preserving topology/field -> identical canonical global source-boundary key and association set;
- center4 globally-interior separating singularity in the skew direct control keeps the same owner and `BarrierAbsorbed` zero-port behavior;
- boundary global facts create zero singularity ports and do not change four-index interior expected class counts.

These tests may be compiled but MUST NOT execute in CB23.

## STOP / falsifier rules before build

STOP and return to definition/review rather than inventing behavior if any of these is true:

1. The field result does not expose enough information to publish the global boundary numeric fact from the **same** cycle-index computation without independently recomputing it.
2. The implementation needs a minimum region, first region, source-face row, map insertion order, or one alias vertex to select a semantic global owner.
3. A proposed correction retains or introduces equality between global `indexNumerator` and regional `BoundaryLoop.turningLift`.
4. Exact source-boundary edge support cannot distinguish source-boundary edges from hard-feature cut edges.
5. The migration requires weakening hard-feature partition, cycle ordering, source component identity, exact-one-owner interior singularities, or singularity port-class validation.
6. Any product/test change would alter accepted selector426/first425, retained genus-two fixture/rawfield bytes, or create selector427.
7. Scope expands beyond the smallest global-boundary authority/reconciliation correction and focused tests.

## Build procedure

1. Start from the exact configured working-branch authority and materialize one verified source snapshot before broad inspection.
2. Implement the smallest D1-D5 change and run static checks only (`git diff --check`, targeted source/header consistency, no generated binary invocation).
3. Before packaging, invoke the mandatory reusable compile authority `agent-compile-reusable.yml` at the exact pushed semantic source with GMP/GMPXX required by `GMP_COMPILE_POLICY.md`.
4. Compile the owner target first to expose local compile errors, then compile the standard eight accepted targets under the reusable workflow's existing target contract.
5. Package exact source archive, compile/link logs, GMP/GMPXX evidence, clean source states, selector/fixture hash census, and self-excluding manifest. Record `runtimeExecution=false`.
6. Do not execute tests, benchmarks, discovery/list/help/version commands, CLI/GUI, `ctest`, or any generated Directional binary.

## Expected successor

On compile/package GREEN with all static falsifiers preserved, authorize exactly one immutable artifact-only Test + Benchmark turn focused first on the CB23 boundary-authority controls before any production S5 retry. On compile failure, remain in the same Code + Build turn only for a bounded compile correction permitted by policy. On semantic ambiguity or a DEFN-R1 falsifier, STOP and route to Review/definition rather than widening CB23.

## Amendment — convert BOTH population sites; the single-face path is the uncovered one (DEFN-R1 review §V2)

`boundaryCycleByGlobalVertex` carries its one-owner assumption at **two** population sites with different
semantics, plus one consumer:

| site | scope | semantics |
|---|---|---|
| `src/authority/FieldTransportAtlas.cpp:2087` | single-face disc regions only, behind the `:2027` guard `regionRows.size() == 1U && euler_characteristic() == 1 && boundary_loop_count() == 1` | plain `emplace`; **any** duplicate key fails |
| `:2390-2393` | general path | `emplace`, rejecting only a *different* stored owner; tolerates idempotent re-insertion |
| `:2504-2516` | final reconciliation | single-owner lookup, plus the `:2512` `turningLift == numerator` cross-domain equality |

**R9 failed at `:2390-2393`, not `:2087`.** The skew fan's regions `{0,3}` and `{1,2}` hold two faces each, so the
`:2027` guard is false and they take the general path, where the two regions supply different owners for shared
boundary vertex `1`.

Consequently the already-required control — *one hard-cut source boundary cycle supports two regional boundary
loops* — exercises only the general path. **The single-face path at `:2087` has no planned coverage and is the
stricter of the two**, rejecting any duplicate at all, so converting the general path alone would leave a
single-face region whose boundary loop partially covers `E(G)` still failing.

Required:

1. convert **both** population sites and the reconciliation consumer to the D2 support-association relation;
2. add a focused control on a **single-face region** with a partial `E(G)` cover, so `:2087` is exercised. This is
   realizable: cutting the skew fan at `(1,4)` and `(2,4)` leaves face `1` alone — triangle `(1,2,4)`, `χ = 1`, one
   boundary loop, satisfying the `:2027` guard — whose only true source-boundary edge is `(1,2)`, a proper subset
   of `E(G)`.

A conversion that passes the skew-fan control while leaving `:2087` on one-owner semantics has not implemented D2.

