# M3-CP4c-3-TB20 Artifact-Only Test + Benchmark Report

## Turn identity

- Phase: `M3-CP4c-3-TB20`
- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`
- Execution mode: canonical Test + Benchmark, artifact-only
- Validated semantic source: **`c5d3c65936e14e1c3e2c8afcffbc4236f37aa131`**
- Compile run/job: **`33805683152 / 100815534364`**
- Immutable compile result artifact: **`9912976409`**
- Compile artifact ZIP SHA-256: **`b4cbcbf5304ff94bd815790264ac360fa1275f23b3af2080cffda381a698a851`**
- Runtime run/job: **`33809177155 / 100826787667`**
- Result/log artifacts: **`9914226104 / 9914226799`**
- Result artifact SHA-256: **`38acaac785afed41c1a0daf0ced6f3b925ebba62e8219d45e40f564cbe54b0bd`**
- Diagnostic-log artifact SHA-256: **`438b3480ebd5ecce937dcbfba94c79357bd5d77e2a7c460662df6a88d7c112c5`**
- Runtime tests executed: selector 385 only, one exact identity per fresh process
- Benchmarks executed: **none**
- Configure/compile/relink/package repair/mode repair/generated discovery: **none**

## Verdict

**VALID SEMANTIC RED / ACCEPTED PREFIX SAFE.**

Selector 385 completed all **388** identities: **380 PASS / 8 RED**. Accepted ordinals 1–365 remain
**365/365 PASS**. The red set is unchanged from TB19:

`366, 367, 368, 369, 370, 371, 372, 374`.

Ordinal 384 passes, and all four CB22 diagnostic identities 385–388 pass. The complete execution ledger SHA-256 is
**`0a4d8b17abd4e397bb80ff0fa92b70bc50e971589e368d1cdf2ecef85868203a`**. Pre/post package byte+mode census is
identical at **`f0b1beec127dacbec9b356630ce8d9e7364de55a5b014598ee67fcdab653c5b0`**.

Stable accounting is unchanged: **44 events / 14 categories / 30 recurrences**, produced-witness debt **5**,
semantic M3 package count **85**.

## Frozen authority checks

TB20 verified before execution:

- packaged source archive SHA-256
  `cec7db850646ffc4c2de0ed1515afc42d544f989ec83ca20055c30accd9929d3`;
- packaged source commit exactly `c5d3c65936e14e1c3e2c8afcffbc4236f37aa131`;
- build and preflight exit codes zero and source-status evidence clean;
- compile boundary records `runtimeExecution=false`, `turnBoundary=Code+Build-only`, and
  `exactArithmeticBackend=GMP`, with both GMPXX and GMP link evidence;
- selector 365 SHA-256 `6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1`;
- selector 384 SHA-256 `c9425b9309415d43d49e5791cc43fd5e5e3bf3ae50d02c329c65d3e632a05564`;
- selector 385 SHA-256 `164a8b25118a4d00fc9261e4645795ad396130b6d6ea4dd8784158b76e1d0fca`,
  388 unique identities, selector 384 an exact prefix and selector 365 an exact accepted prefix;
- 28 internal manifest entries and a 29-file package census;
- executable test binaries were hard-linked into the execution view and fixtures extracted from the packaged
  source; no package or repository byte was repaired or mutated.

## Primary discriminator — `Multiple`, not `None`

Ordinal 366 remains at the exact typed frontier
`UncutFaceComponentOrbitSeedNotUnique` with source face `(0,1,2)`. CB22's retained decision evidence resolves the
TB19 ambiguity:

- `uncutFaceComponent=0`;
- `uncutFaceComponentSeedCount=3`;
- `uncutFaceComponentSeedState=Multiple`;
- `sourceFaceLocusKind=FirstUnlabeledFaceInIterationOrder`;
- matching component census:
  `component=0, faceCount=191, seedCount=3, seedState=Multiple, seedOrbitCount=3,
  seedOrbitsTruncated=false, seedOrbits=[0,1,3]`;
- global component census contains **9** rows and is not truncated.

The historical torus occurrence remains a different, already-proved zero-seed mechanism. TB20 therefore resolves
the mechanical witness's branch without merging the two candidates or authorizing a correction.

## Bounded component and boundary evidence

For component 0:

- face count: **191**; retained face rows: **64**; `uncutFaceComponentFacesTruncated=true`;
- boundary-edge count: **97**; retained boundary rows: **64**;
  `uncutFaceComponentBoundaryEdgesTruncated=true`;
- all 64 retained boundary rows have `otherSideLabeled=true`;
- neighboring labeled-face owner counts: **47 × 1**, **17 × 2**;
- barrier classes: **46 `none`**, **18 `traceTouched`**;
- contributed seeds in the retained window: **44 × orbit 0**, **1 × orbit 1**, **1 × orbit 3**;
- 18 rows contribute no seed because `noSeedReason=barrier`.

The retained **production** first-64 boundary window contains no `edgeOrbitEvidenceNotUnique` skip row. Because the
97-row boundary census is truncated, TB20 does **not** infer that such a row is globally absent. This is an evidence
limit for independent review, not a reason to rerun or mutate TB20.

Ordinal 386 independently passes the projection contract that includes `edgeOrbitEvidenceNotUnique`, proving that
the diagnostic schema/projection can preserve that reason when present. The question for review is whether the
bounded production evidence plus the exact three-orbit census is sufficient to specify the next semantic
correction or whether one more evidence contract is unavoidable.

## Diagnostic witness results

The four appended identities are green:

- 385 `GlobalTopologyPlan.UncutFaceComponentSeedFailurePublishesProductionDecisionEvidence`;
- 386 `GlobalTopologyPlan.UncutFaceComponentSeedFailureProjectsDecisionAndBoundaryEvidence`;
- 387 `GlobalTopologyPlan.FragmentOwnerEvidenceProjectsUncutComponentSeedCensus`;
- 388 `GlobalTopologyPlan.UnrelatedFailureProjectionIsByteIdenticalWithoutUncutSeedDiagnostics`.

Their log SHA-256 values are respectively:

- `06c490443869d3aeb79599be0abe6249a5532cf5d33cfbacc755bd92a4d71b2d`;
- `5b36b1d2e01f8585238b640d09c402a3696ca6ea7f11bfb47ce58f3e35014c25`;
- `8ecc845fb619d411c5a0d7366e728f4b0d087a973abec9f9210ea7adbcfcbaac`;
- `d99459120bea1c5595b1f8e3a5072c97b2c31ea1596f48f6e8977d817d0e97d3`.

Ordinal 384 also remains green. CB22's diagnostics therefore did not move the accepted boundary or the previous
frontier.

## Co-reachers and carried surfaces

Ordinals 367, 371 and 372 independently reach the same typed component-seed frontier and retain the same
`Multiple`/cardinality/locus diagnostics. Because TB19 and TB20 are now two consecutive TB turns with this
production frontier unmoved, the standing trigger from `M3-CP4c3-TB10-REV-CAND-01` is satisfied as a fact;
**TB20-REV must adjudicate** the previously specified test-only atlas-scoped decoupling for 371/372.

The other carried reds remain under their established owners:

- 368: `CellularityNotEstablished` originating
  `RotationSystemInconsistent / TraceEventPositionInvalid`, trace 2 / event 30,
  `NoCarrierMatch / SourceEdgeUnavailable`;
- 369: saturation remains used where the witness expects no saturation;
- 370: actual typed error remains object `<04>` instead of expected `<06>`, with no source-face locus;
- 374: `atlasBuild=false`.

No carried surface is merged into the component-seed correction.

## Regression/candidate disposition

- `M3-CP4c3-TB19-CAND-01`: **branch discriminator resolved**. Mechanical witness is
  `Multiple`, seed count 3, component 0, seed orbits `[0,1,3]`. The product frontier remains gating and non-stable;
  semantic ownership transfers to TB20-REV.
- `M3-CP4c3-TB19-REV-CAND-02`: **closed/satisfied as an evidence-contract candidate**. CB22 retained the component,
  exact cardinality/state, bounded membership/boundary rows and component census, and TB20 runtime-proved those
  fields.
- Production boundary retention is bounded and truncated. The absence of an
  `edgeOrbitEvidenceNotUnique` row from the retained first 64 rows is recorded as a review limitation, not as a new
  stable regression.
- `M3-CP4c3-TB10-REV-CAND-01`: its two-consecutive-TB standing-trigger condition is now met; disposition belongs
  to TB20-REV.
- Stable totals remain **44 / 14 / 30** with no accepted-green loss and no new stable recurrence.

## Tool/read-mode note

The turn used snapshot read mode for project-wide inspection after the start-of-turn source snapshot. One control
plane handoff read occurred before the read mode declaration; the same authority was then captured in the exact
snapshot and all substantive source analysis used that snapshot. This policy-order miss did not affect runtime
source, selector, artifact, or evidence identity.

## Next turn

Exactly one successor is authorized:

**`M3-CP4c-3-TB20-REV` — independent REVIEW + PLAN, planning-only.**

No product/test/fixture/build mutation, compile, benchmark, or additional runtime is authorized by this report.
