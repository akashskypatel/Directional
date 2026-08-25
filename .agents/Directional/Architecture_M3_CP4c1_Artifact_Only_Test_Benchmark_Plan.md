# M3-CP4c-1-TB-R3 — Artifact-Only Test + Benchmark Plan

**Status:** READY / UNBLOCKED
**Consumes:** immutable `M3-CP4c-1-CB3` package only
**Source authority:** `51f510861a02377d1f45607908191f2fdebdcd33`
**No source/build/configure/relink/repair/package mutation is authorized.**

## Validation identity

- phase: `M3-CP4c-1-TB-R3`;
- working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`;
- evidence commit: `51f510861a02377d1f45607908191f2fdebdcd33`;
- package artifact: **`9570940997`** — `m3-cp4c1-cb3-result-result-32867889140`;
- GitHub artifact ZIP SHA-256: **`23876c55e51b94ca3a1e5bcfb727a4c0cebce3294fcd2fbda21336b57ae1de16`**;
- CB3 package internal manifest: **27/27 PASS**;
- platform: immutable Linux package produced by GitHub Actions run `32867889140`.

## Validation objective

Re-run the unchanged CP4c-1 gate and obtain the two measurements authorized by the independent TB-R2 review:

1. **Z1:** determine whether unresolved branch-continuation multiplicity is latent on accepted witnesses, not merely the prescribed sphere;
2. **Z2:** pin the prescribed sphere's A2a `InvalidCandidateTraceTransport` to the exact candidate call site and publish the quantities that decide whether `M3-CP4c-0` is the correct blocking predecessor.

This TB does not implement or repair the pairing. A red required gate is expected and remains honest evidence.

## Preconditions and integrity checks

Before runtime:

- independently verify artifact ZIP SHA-256 equals `23876c55e51b94ca3a1e5bcfb727a4c0cebce3294fcd2fbda21336b57ae1de16`;
- verify embedded semantic source is exactly `51f510861a02377d1f45607908191f2fdebdcd33`;
- verify every package `SHA256SUMS` entry;
- verify required and non-gating selectors are present, unique, non-empty, and match their frozen hashes;
- verify the first 316 required identities are byte-identical to the accepted prefix.

Repeat package/source/selector hash inventories after execution.

## Frozen selectors

### Required gate

- **318** unique/non-empty identities;
- SHA-256 `2f2c24acab0e891273c170c82cdc31b6afa3ae4d43e93c95dbdf6d90a88f45bc`;
- accepted 316-prefix SHA-256 `601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c`;
- C4/C5 remain identities 317–318 and remain gating.

Required semantic gate: **318/318**. Do not remove, rename, demote, or substitute an identity.

### Non-gating diagnostics

Execute exactly:

1. `GlobalTopologyPlan.TorusWitnessStageReachabilityIsObservable`
2. `GlobalTopologyPlan.MechanicalWitnessStageReachabilityIsObservable`
3. `GlobalTopologyPlan.SpherePrescribedWitnessStageReachabilityIsObservable`
4. `FieldAlignedCurveNetwork.BranchBoundaryPairingContinuationIsUnique`
5. `FieldAlignedCurveNetwork.PrescribedSphereCandidateTraceTransportFailureSiteIsObservable`

Diagnostic selector SHA-256: `9f4f287e074d66da9d69c16e22320ed6fe161b6b09de4dc7dd0618741c7fb130`.

These five identities are observation-only and excluded from the 318 required count.

## Ordered execution plan

Execute **318 required + 5 non-gating = 323 total identities** in selector order, exactly one identity per fresh process.

For every process preserve identity, executable, exit status, selected-count proof, stdout/stderr, and elapsed time. A process selecting zero or more than one identity is orchestration failure.

Every build/configure/relink/repair/generated-discovery/source/test/fixture/selector/package mutation flag must remain false.

### 1. Required 318 gate

Expected result:

- accepted prefix: **316/316 PASS**;
- C4 `FieldAlignedCurveNetwork.RejectsTamperedTraceIntersectionCrossing`: FAIL;
- C5 `FieldAlignedCurveNetwork.EveryTraceTerminatesAtATypedEventKindThatIsActuallyProduced`: FAIL;
- total expected: **316/318**.

A different accepted-prefix red is a regression and must be classified before TB closeout. C4/C5 passing would be evidence that the new measurements or existing witness path changed assumptions and must be reviewed before checkpoint closure is claimed.

### 2. Existing three reachability observations

Record torus, mechanical, and prescribed-sphere reports unchanged as non-gating context. Any stage movement must be reported, not normalized to the prior result.

### 3. Z1 branch-pairing census

From `FieldAlignedCurveNetwork.BranchBoundaryPairingContinuationIsUnique`, preserve the complete report for:

- two-ring skew disc;
- four-triangle fan;
- torus when its atlas is published;
- mechanical witness when its atlas is published;
- prescribed sphere.

For each published atlas record:

- frame and pairing counts;
- `(incomingCarriers.size(), outgoingCarriers.size())` distribution;
- ambiguous-pairing count and percentage.

For the prescribed sphere also record the failing face, incoming/outgoing carrier sets, and incoming multiplicity.

Falsifiable predictions:

- two-ring and four-triangle fan each report **more than 0%** ambiguous pairings;
- non-degenerate witnesses are expected to be near half ambiguous;
- the prescribed-sphere failing face is among the ambiguous pairings.

If accepted witnesses report zero ambiguous pairings, the review's genericity claim is falsified. Preserve the result and return to review; do not reinterpret the identity.

### 4. Z2 prescribed-sphere site pin

From `FieldAlignedCurveNetwork.PrescribedSphereCandidateTraceTransportFailureSiteIsObservable`, preserve:

- exact site name;
- completed segment count;
- current face;
- source edge;
- inflow/outflow carrier sets;
- incoming multiplicity;
- whether branch transport adjacency exists for the reported carrier;
- original production error/locus.

Binding prediction:

- site = `field_aligned_outgoing_carrier`;
- completed segments **>= 1**;
- source edge = `1-2`;
- incoming multiplicity = **2**.

If site is `field_aligned_next_face` or `topology.transport`, or if the reported carrier/locus does not match the production error, the CP4c-0 charter is not confirmed. Stop semantic planning and route to `M3-CP4c-1-TB-R3-REVIEW-PLAN`.

## Benchmark plan

Not applicable. This turn measures semantic/diagnostic identities only; no performance claim is in scope.

## Unit-test design check

The two new identities are deliberately non-gating diagnostics:

- Z1 consumes published A1 authority and measures a relation cardinality; it does not construct a replacement pairing.
- Z2 independently replays the candidate trace decisions against published A1 authority only to localize which production guard corresponds to the already-observed product error.
- Both deliberately fail after printing their observation, so they cannot be mistaken for acceptance.
- Neither weakens C4/C5 or derives a passing expectation from current output.

## Stop and blocker conditions

Stop and preserve evidence if:

- package/source/selector integrity does not match this plan;
- any identity selects zero or multiple tests;
- any prohibited mutation/build flag becomes true;
- an accepted-prefix identity regresses;
- Z2 contradicts the production error locus;
- Z2 reports `field_aligned_next_face` or `topology.transport` rather than the predicted outgoing-carrier site.

Do not repair, rebuild, patch, or rerun a deterministic semantic red inside TB.

## Plan-defined reruns

No automatic semantic rerun. Retry only a diagnosed orchestration/infrastructure failure that produced no valid semantic evidence, with the package and selectors unchanged.

## Completion and routing

TB-R3 is complete when all 323 processes have a recorded result or an explicit orchestration blocker, pre/post integrity is proven, and every observed regression/candidate is recorded in `Regression_Root_Cause_Tracker.md` as required.

If the required gate remains 316/318 **and Z1/Z2 confirm the review predictions**, exact next is **`M3-CP4c-0-DEFN`**, a review/definition/planning-only turn consuming these measurements. It freezes the blocking predecessor contract before any pairing/position implementation.

If Z1 or Z2 falsifies the charter assumptions, exact next is **`M3-CP4c-1-TB-R3-REVIEW-PLAN`**. In either case, no implementation follows a red TB without an intervening review/planning turn.
