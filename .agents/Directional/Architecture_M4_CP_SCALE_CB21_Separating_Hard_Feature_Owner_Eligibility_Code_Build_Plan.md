# M4-CP-SCALE-CB21 — Separating Hard-Feature Owner Eligibility Code + Build Plan

**Turn type:** Code + Build only
**Predecessor:** `M4-CP-SCALE-TB12-R7-REV`
**Purpose:** correct only the CB18 cross-domain owner-eligibility condition and repair the direct independent control.
**Runtime boundary:** generated Directional runtime is forbidden in this turn. Compile/package verification only, under GMP/GMPXX.

## 1. Frozen evidence and defect

R7 valid artifact-only execution stops at A0 row1 `FieldTransportAtlas.SeparatingHardFeatureSingularityOwnsCanonicalBoundaryCycle` with `SingularityMismatch;sourceVertex=8`. Review independently localizes the stop to CB18's unsupported requirement that a per-region relative `BoundaryLoop.turningLift` equal the global raw source-vertex singularity numerator.

`BoundaryLoop.turningLift` participates in a per-region index balance and the canonical first boundary loop may absorb a region-level correction. It is not the numeric authority for one source vertex on that loop. Separating-feature ownership is already established by source-topology incidence plus actual local boundary-loop containment.

## 2. Authorized semantic files

Only these semantic files may change:

1. `src/authority/FieldTransportAtlas.cpp`
2. `tests/FieldTransportAtlasTests.cpp`

Durable documentation/workflow transport files may change as required by policy. No other product/test/fixture/build file is authorized without stopping for Review.

## 3. Production correction contract

In `FieldTransportAtlas.cpp`:

1. Keep `separatingFeatureRegionsByGlobalVertex` as the source-topology incidence authority.
2. A separating-boundary owner candidate is eligible only when:
   - the source vertex is globally interior;
   - it is a prescribed raw singularity;
   - the current source topology region is in that vertex's separating-feature incident-region set;
   - the supplied cycle exists and is a `BoundaryLoop` owned by that region;
   - the callback is visiting that global vertex on that actual local boundary loop.
3. **Remove the requirement that `BoundaryLoop.turningLift == rawSingularity[vertex]`.** Do not replace it with any equivalent numeric proxy.
4. Keep deterministic canonicalization by stable authority identity: minimum `(TopologyRegionId, FieldCycleId)` among eligible candidates. Do not use storage or iteration order as authority.
5. In final singularity reconciliation, preserve exact one-owner exclusivity. For a separating owner, validate cycle existence/kind/region and separating-feature incidence; **do not** validate equality between boundary-loop lift and the global singularity numerator.
6. Keep the independently derived raw numerator unchanged as `FieldSingularityFact.indexNumerator`.
7. Publish separating-feature ownership as `FieldSingularityFact::PortPolicy::BarrierAbsorbed`, increment only `separatingFeatureBoundaryBoundSingularityCount`, and emit zero singularity origin ports.
8. Same-region slit ownership and source-boundary singularity handling are unchanged.

## 4. Independent regression-control contract

Update `SeparatingHardFeatureSingularityOwnsCanonicalBoundaryCycle` without weakening its established independent setup:

- retain the five-ring annulus construction, two separating hard-feature rings, source-authority region derivation and `preCb18LocalBarrierEdgeCount == 0` proof;
- retain independent global source-vertex singularity derivation from `PCFaceTangentBundle` and exact target `+1` / interior `-1` checks;
- retain independent incident-region derivation from source authority;
- remove `ownerCycle.turningLift == singularity.indexNumerator` as an oracle;
- assert exactly one target singularity fact, stable expected owner region, valid `BoundaryLoop` owner in that region, `BarrierAbsorbed`, zero origin ports, separating diagnostic `1`, slit diagnostic `0`, and all unbound counts `0`.

### Required discriminator

The corrected test must independently establish a case in which the eligible separating boundary's relative loop lift is **not equal** to the target's global source-vertex singularity numerator, while all incidence/ownership preconditions remain valid, and then require atlas construction/ownership to succeed. The independent mismatch must be established without reading the producer's published owner as the oracle. Acceptable approaches include a test-local reconstruction of the relevant regional boundary cycle/index balance from source mesh/field authority or a deliberately authored subject whose regional correction forces the mismatch and whose expectation is independently derived.

The discriminator must fail if the old CB18 equality is restored. Merely deleting the equality assertion after product construction is vacuous and does not satisfy this plan.

### Canonicalization control

Retain or add a relabeling/permutation control sufficient to show that multiple incident owner candidates resolve by stable authority IDs, not insertion/storage order. The expected identity must be derived independently of the producer's chosen output.

## 5. Frozen semantics

CB21 must not change:

- source-topology region partitioning or hard-feature classification;
- `dual_cycles`, cycle support/order/canonicalization or CB16 behavior;
- same-region slit/barrier ownership semantics;
- source-boundary singularity semantics;
- retained `genus_two.obj`, `.rawfield`, fixture metadata or S5 focus;
- selector426 bytes/order/ownership or create selector427;
- CMake/benchmark semantics;
- accepted predecessor behavior or stable accounting;
- public acceptance by weakening validators outside the direct owner seam.

## 6. Compile/package gate

Before compile:

- prove semantic diff is restricted to the two authorized files;
- re-hash selector426 and first425 exactly;
- re-hash retained genus-two fixture/rawfield/metadata exactly;
- inspect direct test non-vacuity and required mismatch discriminator statically.

Compile using the mandatory reusable compile workflow with GMP/GMPXX and the standard eight targets. Package only from exact semantic source; require clean pre/post source status, root manifest self-verification, executable modes, source archive identity and `runtimeExecution=false`. No generated test binary may run in CB21.

If compile/package is green, freeze one immutable candidate and author a fresh artifact-only successor plan for `M4-CP-SCALE-TB12-R8-EXEC`: A0 5 -> A 4 -> S5 1 -> selector426 426, exact fail-fast, benchmark execution 0, immutable postflight mandatory. Do not execute R8 in CB21.

## 7. STOP / falsifiers

Stop and route back to Review/Definition rather than broadening if any of these occurs:

1. source authority proves `BoundaryLoop.turningLift` is normatively the per-source-vertex singularity index authority;
2. the fix requires source topology, cycle ordering, same-region slit, source-boundary, fixture, selector, CMake or benchmark semantic changes;
3. no independent test can distinguish incidence-owned absorption from the former lift/index equality;
4. canonical owner identity cannot be made iteration-order invariant from existing stable IDs;
5. the correction reaches a boundary-quadrangulability/certificate-definition issue that is not this owner-eligibility seam;
6. compile/package authority is not clean and GMP/GMPXX-linked.

## 8. Success condition

CB21 is complete only when the bounded production/test correction satisfies the independent discriminator and canonicalization controls statically, all standard targets compile/package under GMP/GMPXX with no runtime, all frozen bytes are unchanged, and exactly one next Test+Benchmark plan is frozen. No promotion, S5/A3 credit, selector execution or stable pricing occurs in CB21.
