# M4-CP1-CB1 Code + Build Plan — Global Conformity Schedule Authority

**Status:** FROZEN BY `M4-DEFN` / EXACT NEXT = `M4-CP1-CB1`
**Turn type:** canonical Code + Build
**Runtime:** PROHIBITED
**Date:** 2026-09-09

## 1. Objective

Implement the first bounded M4 vertical slice: a standalone exact, immutable A3 `GlobalConformityPlan` for **known-feasible
constructed inputs**, with one global writer, one count per full A2b boundary arc, incidence-multiplicity authority,
mandatory region parity, compact arbitrary-precision breakpoint identity/generation, backend-independent exact binary64
ingress, deterministic positive subdivision counts and an independent validator. Compile the new product/tests through
the mandatory GMP/GMPXX reusable build workflow. Do not expose the production infeasible alternative yet and do not cut
regional A4 producers over to the plan; those boundaries are CP2 and CP3 respectively.

## 2. Entering authority

- M3 is CLOSED / ACCEPTED.
- accepted predecessor selector: 365, LF SHA-256 `6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1`;
- package113/TB48 remains reviewed runtime authority;
- `Architecture_M4_DEFN_Frozen_Definitions.md` is the M4 semantic definition authority;
- no M4 selector exists yet; CB1 may author the first append-only CP1 selector but may not execute it.

## 3. Scope boundary

CB1 may change only the smallest owner set needed for CP1:

- authority/value definitions needed for full-arc `ConformitySpanId`, boundary-incidence occurrence identity and the
  pair-valued arbitrary-precision `ConformityBreakpointId`;
- new `GlobalConformityPlan` public/product source and its independent validation surface;
- build registration for those new files;
- focused CP1 test source and append-only selector publication derived from selector365;
- compile/package workflow caller and Code+Build documentation.

CB1 must **not** change:

- `SurfaceCellTracing.cpp` regional `gridU/gridV` choice or post-hoc hard-rail pairing;
- `RemeshPipeline.cpp` production A4 consumption semantics unless a zero-behavior compile-only declaration is strictly
  necessary for header integration;
- M3 selectors/tests/fixtures;
- CP2 infeasible-subset semantics beyond reserving value-type seams already frozen by DEFN;
- CP-COND/CP-SCALE behavior;
- M5/M6 relation/embedding logic.

If implementing CP1 would require any such semantic cutover, stop and re-plan rather than broadening CB1.

## 4. Required implementation

### CB1.1 — typed semantic identities and compact exact count surface

Add/reuse the full-arc conformity span identity and boundary-incidence occurrence identity in existing authority style.
`ConformityBreakpointId` must be a strong pair `{ConformitySpanId, exactOrdinal}` whose ordinal uses the semantic exact
integer type; it must **not** reuse `SemanticId<size_t>`. Add/reuse a backend-independent exact positive integer
representation for schedule counts. Authoritative compile evidence must select GMP/GMPXX. No CP1 API may require
materializing `x_s+1` breakpoint IDs.

### CB1.2 — exact binary64 ingress and full-span support path

Implement the DEFN bit-decomposition conversion for finite binary64 coordinates/target values. Do not use
`ENumber(double,tol)` or an implicit backend-specific double conversion for semantic binding/objective values. Build one
canonical full A2b span per bound boundary arc and retain its ordered exact A2a/A2a' support-piece path. Do **not** split
the schedule into per-source-simplex positive variables. Preserve every canonical boundary occurrence, including two
incidence ends that may name the same region. Reject malformed/empty/disconnected/zero-energy paths as the frozen typed
degenerate-path error.

### CB1.3 — `GlobalConformityPlan` feasible immutable product

Add the standalone public/value implementation for **known-feasible constructed components**:

- exact source/network/cut-graph/A2b/target bindings;
- full-arc spans plus ordered exact support pieces;
- independent boundary-occurrence region/family/sign/orientation incidences;
- one arbitrary-precision positive `x_s` per full span;
- compact exact-ordinal breakpoint generator using DEFN §4.2;
- deterministic semantic digest over compact authority/count/generator data;
- no diagnostic/container/row-order identity and no O(`x_s`) storage.

CP1 does not yet publish the final carried `GlobalConformityCertificate` or `ConformityInfeasibleSubset`. It also must
not expose a production factory that reclassifies ordinary solver infeasibility as fatal. CP2 adds those outcome/certificate
surfaces without changing any feasible schedule semantics established here.

### CB1.4 — normalized balance/parity graph and deterministic minimum deviation

Implement the DEFN §5–§7 feasible formulation:

- exact binary64 dyadic binding and full-span rational path-energy `R_s`;
- exact preferred `d_s` derivation without floating square roots;
- lower bound `x_s>=1`;
- exact signed balance over **boundary incidences**, preserving self-loop/repeated-occurrence multiplicity;
- mandatory region/family even-boundary parity, structurally implied by balance but checked explicitly;
- dedicated bi-directed minimum-deviation flow, never generic ILP;
- exact lexicographic vector objective `(C,x_1,...,x_E)` (or proved-equivalent symbolic ordered cost), never big-M;
- exact integer/vector costs, balances and reduced-cost decisions returning the unique canonical minimizer without
  numeric-range scans;
- WorkLedger with an implementation-specific proved polynomial step bound and bit-width observations.

No 2:1 adaptivity constraint is active in baseline CP1. Do not add an enable flag, error, cut reason or local-mesher
heuristic for it. If the selected dedicated algorithm cannot supply the polynomial bound promised by DEFN, **do not ship
a heuristic substitute**; stop the CB with compile-safe evidence and route back to review.

### CB1.5 — independent validator

Place the validator in a separately reviewable implementation surface. It may share public value types and exact
arithmetic primitives, but not producer private helpers that derive spans, incidence multiplicity, objective or schedule.
For CP1 it independently verifies/recomputes:

- source/network/cut-graph/topology/target bindings and binary64 bit exactification;
- one full span per A2b boundary arc plus ordered support-piece continuity;
- boundary-occurrence multiplicity, family/sign/orientation authority;
- arbitrary-precision `x_s>=1` and compact breakpoint-generator arithmetic without O(`x_s`) expansion;
- reverse-incidence exact-ordinal agreement;
- every region/family balance and explicit even boundary parity;
- exact `R_s`, `d_s`, objective, feasible-plan optimality and lexicographic tie result through a distinct check path;
- semantic digest.

### CB1.6 — focused compiled test authority

Author direct deterministic value/product tests for CP1 preconditions only. Required identities are **gating** and must
cover at least:

1. one A2b span crossing multiple source-support pieces still publishes exactly one positive schedule count;
2. two incidence ends consume the same compact exact-ordinal breakpoint generator in opposite orientation;
3. a same-region/two-end or repeated-boundary-occurrence fixture preserves multiplicity rather than deduplicating by
   region ID;
4. every published count is positive and each region/family boundary multiplicity is explicitly even;
5. a very large exact count/ordinal is representable, digestible and independently checkable without enumerating
   O(`x_s`) breakpoints or narrowing to `size_t`;
6. binary64 normal/subnormal/signed-zero exactification agrees across producer and independent primitive expectations,
   while non-finite/non-positive target entries reject typed;
7. two symmetric/equal-cost feasible schedules choose the canonical lexicographic winner;
8. path reversal and source/container/region input permutation preserving semantic topology produce the same schedule
   semantics/digest under the frozen orientation mapping;
9. missing/duplicate incidence, broken support-piece continuity, count/parity/binding/support-order tamper is rejected by
   the independent validator;
10. producer and oracle derive the same valid result through distinct derivation paths, including one tamper that would
    survive a shallow self-comparison.

Do not author a guaranteed-red exact-torus production identity in CP1; production A3 reachability belongs to CP3.

### CB1.7 — append-only CP1 selector

Create the first M4 selector only after test names are frozen:

- byte-for-byte/LF prefix = accepted selector365;
- append only the new CP1 gating identities;
- record total count, selector LF SHA-256 and proof that the first 365 rows hash to the accepted predecessor;
- do not copy M3 audit-only rows 366–409 unless independently selected as a new M4 obligation (none are authorized).

## 5. Compile/build contract

All compile activity uses `.github/workflows/agent-compile-reusable.yml` and mandatory GMP/GMPXX policy. The caller may
compile only approved targets and compile-time/static discovery owned by the reusable workflow. It may not execute a
Directional binary, test filter, benchmark, `ctest`, help/list/version command, or custom runtime input.

Required compile evidence:

- exact pushed source SHA;
- `DIRECTIONAL_ENABLE_GMP=ON`, GMP and GMPXX linked on authoritative generated link commands;
- new library/product source and CP1 test target compile/link successfully;
- source status clean and package manifest self-verifies;
- `runtimeExecution=false`;
- durable ccache namespace/schema owned only by reusable workflow;
- result/log artifact IDs and digests.

## 6. Falsifiable Code+Build prediction

If CB1 is implemented as frozen:

- changed semantic owners are limited to the new A3 product/IDs/exact-ingress/build registration/focused CP1 test authority;
- no existing M3 selector byte changes;
- accepted selector365 is the exact new selector prefix;
- the approved library/test targets compile and link with GMP/GMPXX;
- package evidence says `runtimeExecution=false`;
- no source/test path outside the declared owner set changes except documentation/control-plane files.

Any mismatch is evidence requiring diagnosis, not permission to widen scope or weaken the contract.

## 7. Exact successor on successful build

CB1 closeout must freeze **`M4-CP1-TB1`**, artifact-only, against the exact immutable CB1 package. That TB executes the
full CP1 selector one identity per fresh process, verifies the accepted 365 prefix, and tests every new CP1 identity.
No benchmark is required unless CP1 authored a metric whose plan explicitly requires one.

If compilation fails, remain inside the same Code + Build turn only for a bounded correction consistent with this
owner set. If the failure reveals a definition/algorithm contradiction, stop and route to independent review instead
of implementing around the definition.
