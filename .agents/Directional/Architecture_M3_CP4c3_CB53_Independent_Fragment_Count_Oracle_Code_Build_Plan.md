# M3-CP4c-3-CB53 Independent Fragment-Count Oracle Code + Build Plan

**Status:** FROZEN / EXACT SUCCESSOR / RUNTIME-FREE
**Turn:** `M3-CP4c-3-CB53`
**Authority:** `M3-CP4c-3-TB46-R1-REV`
**Runtime authority entering:** TB46-R1/package111/selector409 — **403 PASS / 6 RED / 0 SKIP**, accepted **365/365**
**Stable accounting:** **47 events / 14 categories / 33 recurrences**, debt **5**, packages **111**

## 1. Objective

Correct one stale independent test-oracle cardinality rule at ordinal367. The frozen normative rule allows multiple
local fragments to share one global face-walk owner, so distinct global owner count is an upper-bounded ownership
projection, not a local-fragment identity count.

CB53 is test-authority only. It executes no Directional runtime.

## 2. Authorized semantic edit

In `tests/FieldAlignedCurveNetworkTests.cpp`, within `independent_fragment_partition()`, change only the final
`FragmentCountRule` cardinality guard from a two-sided equality requirement to the frozen one-sided over-count rule:

```text
current:  fragmentOrbits[face].size() != tracePieces[face] + 1U
required: fragmentOrbits[face].size() >  tracePieces[face] + 1U
```

Update the immediately adjacent explanatory comment if needed so it states the authority correctly:

- `tracePieces + 1` is the local-fragment upper bound;
- `fragmentOrbits[face]` is a set of distinct global face-walk owners;
- local-fragment -> global-owner mapping is not injective;
- an owner over-count remains impossible and must still fail `FragmentCountRule`.

## 3. Required independence and preserved logic

The correction must preserve all of the independent helper's existing authority:

1. derive forward/reverse face-walk orbits independently;
2. preserve CB51's final-no-barrier rule: skip only when independently derived forward/reverse orbit IDs are equal;
3. preserve normal bookkeeping for retained separating terminal segments;
4. preserve non-empty ownership checks, touched-edge/edge-orbit evidence, exterior handling, component seed checks and
   `facesByOrbit`;
5. do not query product-owned fragment partitions, `FragmentCornerIncidence`, product region membership, or any
   helper whose result would make the oracle circular.

`FragmentCountRule` remains the failure clause for a genuine over-count.

## 4. Frozen unchanged surface

CB53 must not change:

- any product header/source or build logic;
- fixtures, meshes, fields, rails, seeds or benchmark inputs;
- selector409 bytes, selector manifests or gate membership;
- normative Part VIII/Part XI/Part XII definitions;
- carried RED owners 368/369/370/374/398;
- protected success-path behavior 390/393/406/407;
- accepted-prefix behavior 1–365;
- production region construction, ownership, cut selection, certifier partitions, semantic digests or diagnostics.

No refactor, fallback, repair, test skip, selector growth or assertion weakening outside the exact one-sided
cardinality correction is authorized.

## 5. Required static review before compile

Before compile, verify from exact pushed source:

1. the independent helper's final count guard is exactly `>` against `tracePieces[face] + 1U`;
2. no sibling equality/`!=` restatement reintroduces local-fragment/global-owner injectivity in that helper;
3. CB51's terminal-separation branch remains based only on independently derived forward/reverse orbit equality;
4. retained separating terminal segments still receive normal independent bookkeeping;
5. no product source, fixture, selector or carried-owner source changed.

## 6. Build/package boundary

Compile/package the exact pushed semantic source with the durable GMP/GMPXX reusable workflow. Compile all targets
needed to preserve the complete selector409 execution package. The workflow must execute **no generated Directional
runtime**: no tests, benchmarks, `ctest`, discovery/list/help/version command, CLI, fuzzer or custom input.

The accepted package must record exact source SHA, `runtimeExecution=false`, mandatory GMP/GMPXX link evidence,
recursive manifest verification and clean source status.

Package count advances **111 -> 112** only if a new immutable package is accepted. Stable event/category/recurrence
totals do not change in CB53.

## 7. Closeout

On accepted compile/package, CB53 closeout may freeze the next artifact-only Test + Benchmark plan bound to that exact
immutable package and unchanged selector409. That later plan must measure the full selector409 gate without freezing
an expected aggregate.

If compile/package fails, remain inside CB53. Do not run Directional runtime.

## 8. Exact successor after accepted package

The successor Test + Benchmark turn is authored only by CB53 closeout after immutable package acceptance.
