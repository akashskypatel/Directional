# M3-CP4c-3-TB19 Artifact-Only Test + Benchmark Report

## Verdict

**COMPLETE / VALID SEMANTIC RED / ACCEPTED PREFIX SAFE / CB21 FRAGMENT-OWNER CORRECTION RUNTIME-PROVED / NON-STABLE**

TB19 executed the full frozen selector **384** from the immutable CB21 compile artifact, one identity per fresh
process. The accepted prefix remains **365/365 PASS**. The gate is **376 PASS / 8 RED** with the same red ordinal
set as TB18: **366/367/368/369/370/371/372/374**.

The CB21 correction reached production runtime exactly as intended: ordinals **366/367/371/372** all move past
`TraceCutFaceFragmentCountMismatch`. Their new common terminal frontier is
`UncutFaceComponentOrbitSeedNotUnique` at source face **`(0,1,2)`**. This later typed stop is valid new frontier
evidence, not a CB21 regression. Ordinal **384** passes.

Because the gate remains red, CP4c-3 stays **OPEN** and the standing workflow routes next to independent
**`M3-CP4c-3-TB19-REV` — REVIEW + PLAN only**. No product, test, fixture, selector, package, compile, relink, or
benchmark mutation is authorized by this report.

## Immutable authority

- semantic source: **`b00efbd53d3da8caa2bcac0d66594e06e44d2cb2`**;
- compile run/job: **`33794307778 / 100778238374`**;
- immutable compile result artifact: **`9908695433`**;
- compile artifact ZIP SHA-256:
  **`efb65c06cc6d73d233ee271a31fc82705d2575da313fb7f18b389a5196441fc5`**;
- packaged source archive SHA-256:
  **`8b774500559e5cc9cd7afece39a68add2065a9812a0d15a40f39cf7f9aafd8e7`**;
- compile log artifact: **`9908695835`**, SHA-256
  **`f334db6b4bf254c3e2eb84f0a65cb0f6a21fc56285b3677a037cb20881b8ad3f`**;
- selector 384: **384 identities**, SHA-256
  **`c9425b9309415d43d49e5791cc43fd5e5e3bf3ae50d02c329c65d3e632a05564`**;
- selector 383 exact prefix SHA-256:
  **`a7fe57cc47c5035414a82f02f044a911f9c430f90d11f1bd3ef1bca76f3a4b2c`**;
- accepted selector 365 exact prefix SHA-256:
  **`6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1`**.

TB19 runtime:

- workflow run / execute job: **`33798040003 / 100790444711`**;
- result artifact: **`9910078670`**, ZIP SHA-256
  **`4ac445f70449e42091ebff5b6ef31e1c841b79bf2e704f76a9217df717989129`**;
- diagnostic log artifact: **`9910079341`**, ZIP SHA-256
  **`769f06a180edd6b2ef7c218413ee16ceccb40ecee23bf399584f032712804c60`**;
- exact 384-row result ledger SHA-256:
  **`e9ab64a8392aa1e16e30e03f440865914df846567e4b4fd12f3dce241841c04b`**;
- pre/post package byte+mode census: **IDENTICAL**, SHA-256
  **`c238668140634325a75dbb48ed23ce5659376cb5d2d7b79f3f3f46ab275e133d`**.

The workflow schema-validation job and execute job both completed successfully. A successful workflow means the
frozen harness completed its immutable selector execution; it does **not** mean the semantic gate was green.

## Execution boundary and preflight

The runner verified the artifact identity, compile-job success, artifact ZIP digest, all **28** internal
`SHA256SUMS` entries, semantic source commit, zero build/preflight exit codes, clean packaged source-status records,
GMP/GMPXX linkage evidence, executable modes, and the frozen selector hashes/prefixes before runtime.

Execution boundary:

- `runtimeExecution=true`;
- `benchmarkExecution=false`;
- `configureExecution=false`;
- `compileExecution=false`;
- `relinkExecution=false`;
- `packageRepair=false`;
- `modeRepair=false`;
- `generatedDiscovery=false`;
- `sourceMutation=false`;
- `testMutation=false`;
- `fixtureMutation=false`;
- `selectorMutation=false`;
- `benchmarkMutation=false`.

All 384 identities executed in selector order, one exact GoogleTest identity per fresh process. No completed
identity was rerun to seek a different semantic outcome.

## Exact gate result

| Scope | Result |
|---|---:|
| selector 384 | **376 PASS / 8 RED** |
| accepted 1–365 | **365 PASS / 0 RED** |
| first red | **366** |
| red ordinals | **366, 367, 368, 369, 370, 371, 372, 374** |
| ordinal 383 | **PASS** |
| ordinal 384 | **PASS** |

Red identity/log hashes:

| Ordinal | Identity | Log SHA-256 |
|---:|---|---|
| 366 | `GlobalTopologyPlan.MechanicalFeatureWitnessDerivesRegionsThroughProductionEntryPath` | `a54c229a78d7b451cbc81157cbc338093fa88cffeda0e8e60bfb83d0a6a729a6` |
| 367 | `GlobalTopologyPlan.RotationSystemAndFaceWalkAgreeOnProducedWitnesses` | `9a43dfbfb1efdd6d34e202fd1795150fbdba4ef466367dd5973cff41ff25cdfb` |
| 368 | `GlobalTopologyPlan.PrescribedSphereWitnessDerivesRegionsThroughProductionEntryPath` | `eb9011d6bcc85dd36d340070f8d8888681ecb4ef36a35239ab936fd04d839e6d` |
| 369 | `SurfaceCutGraph.OrdinaryProposalSelectsTraceCrossedEdgeWithoutSaturation` | `b87e1000bbda71c4b960ec8cff8956be85fd8fa2b84db8f29de094ced81675a9` |
| 370 | `SurfaceCutGraph.EmptyNetworkOnClosedSurfaceIsRejectedWithTypedError` | `86b29b5ef96a1913c3fd9d37f0cef8d3767287725184a3f260abfaefd6b85e4b` |
| 371 | `FieldTransportAtlas.NonSeparatingBarrierEdgeIsAbsentFromLocalCycleBasis` | `dab83736358453187db97872c384f2fe62d6e8f1a6719d0972dee7a4d7bbf8e5` |
| 372 | `FieldTransportAtlas.CutTransportDomainSatisfiesTheEulerCutIdentity` | `18991c82297deb8103b1f65e97a909c76d56db81eb949d312ef870b137931987` |
| 374 | `ResolvedBranchCorrection.FoldedConeArrivalRayElectsOneOwnerAndFalsifiesCandidateLocalElection` | `55ca81ca412f9eb4ecea251f60b64549ee1fa4d5c8ace11b51fb5d4ac3cb39cb` |

## Binding discriminator results

### D1 — accepted boundary: PASS

Ordinals **1–365 are 365/365 PASS**. No accepted behavior regressed.

### D2 — ordinal 366 moves past the fragment-owner mismatch: PASS

TB18 stopped at `TraceCutFaceFragmentCountMismatch`, face `(0,1,102)`. TB19 no longer stops there. Ordinal 366 now
terminates at:

`NotProductionReady/global-topology-plan/UncutFaceComponentOrbitSeedNotUnique;detailCode=UncutFaceComponentOrbitSeedNotUnique;sourceFace=0,1,2`

The newly exposed source site rejects an unlabeled source-face component unless its collected neighboring
face-walk seed-orbit set has cardinality exactly one. TB19's projected error names the first affected face but does
not retain whether the component has zero seeds or multiple seeds. That distinction is review-owned; TB19 does not
guess it.

### D3 — co-reaching identities: PASS

Ordinals **367, 371, and 372** independently move past `TraceCutFaceFragmentCountMismatch` and terminate at the
same later typed frontier, `UncutFaceComponentOrbitSeedNotUnique`, source face `(0,1,2)`. Their own downstream
contracts remain unmeasured because 367 genuinely requires the plan and 371/372 still construct the shared
all-products mechanical fixture.

### D4 — retained deficit evidence: PASS

For face **`(0,1,102)`**, TB19 retains:

- `localFragmentCount=2`;
- `ownerCount=1`;
- `expectedFragmentCount=2`;
- `ownerDeficit=1`;
- `traceChordCount=1`;
- `chordsCrossInside=false`;
- `localArrangementEvaluated=true`;
- one shared-owner chord: **trace 1 / arc 15 / segment 4**;
- that chord has **forwardOrbit=0 / reverseOrbit=0**.

The low-side deficit is therefore observed and non-fatal exactly as CB21 specified.

### D5 — bridge/orbit census: PASS as observation

The untruncated production-path census reports:

- face evidence count **70**, `fragmentOwnerFacesTruncated=false`;
- all 70 rows have `localArrangementEvaluated=true`;
- all 70 rows report `chordsCrossInside=false`;
- every face row has `sharedOwnerChordsTruncated=false`;
- 18/70 retained faces have `ownerDeficit=1`; no retained deficit exceeds 1;
- arc evidence count **26**, `fragmentOwnerArcsTruncated=false`;
- **arc 15**: `trace=1`, `forwardOrbit=0`, `reverseOrbit=0`, `sharesOrbit=true`;
- trace evidence count **12**, `fragmentOwnerTracesTruncated=false`;
- **trace 1**: `terminalSlit=false`;
- total face-walk orbits **6**;
- exterior orbits **0**;
- non-exterior orbits **6**.

These are witness observations, not a promoted universal invariant.

### D6 — carried surfaces: UNCHANGED

No unauthorized CB21 cross-surface movement is observed:

- **368** remains `surface-cut-graph/CellularityNotEstablished`, originating
  `RotationSystemInconsistent / TraceEventPositionInvalid`, trace 2 / event 30,
  `NoCarrierMatch / SourceEdgeUnavailable`;
- **369** remains `certificate.saturationUsed == true` where the identity expects false;
- **370** remains cut-graph error code object `<04>` instead of expected
  `EmptyNetworkOnClosedSurface` `<06>`, with `sourceFace.has_value()==false`;
- **374** remains `atlasBuild=false`.

Only source line numbers and wall-clock timings moved where CB21 added test/source lines; the terminal semantic
code/detail/locus and assertions are unchanged.

## Ordinal 384

`GlobalTopologyPlan.FragmentOwnerDeficitPublishesCorrectionEvidenceThroughProductionPath` executes exactly once and
**PASSes**. This runtime-proves the CB21 production-path evidence contract, including the low-side deficit
pass-through and its retained evidence. It does not make the entire selector green.

## Regression/candidate disposition

- No accepted-prefix regression occurred.
- The red ordinal set is byte-for-byte the same ordinal set as TB18.
- 366/367/371/372 advanced past their prior stop as intended; this is progress, not a new stable regression.
- 368/369/370/374 are semantically unchanged and remain under their existing owners.
- `M3-CP4c3-TB17-CAND-01` closes its runtime condition: the fragment-owner low-side mismatch no longer blocks the
  production path.
- `M3-CP4c3-TB18-REV-CAND-01` remains non-stable and review-owned. The current witness reports all 70 retained local
  arrangements evaluated and non-crossing, but runtime on one witness does not prove a universal non-crossing
  theorem.
- New non-stable `M3-CP4c3-TB19-CAND-01` owns the newly exposed
  `UncutFaceComponentOrbitSeedNotUnique` frontier. The current retained envelope is insufficient to distinguish
  zero seed from multiple seeds for the affected unlabeled component.
- 371/372 remain classified under `M3-CP4c3-TB10-REV-CAND-01` test coupling until review decides whether to
  decouple their atlas-only assertions or first address the shared mechanical production frontier.

Stable accounting changes by **+0 events / +0 recurrences** because CP4c-3 remains unaccepted, accepted 365/365
remains green, the red ordinal set did not expand, and the only new terminal site is a newly exposed downstream
candidate. Totals remain **44 events / 14 categories / 30 recurrences**, produced-witness debt **5**, semantic M3
package count **85**.

## Postflight and exact next action

The postflight package byte+mode census is exactly identical to preflight at
`c238668140634325a75dbb48ed23ce5659376cb5d2d7b79f3f3f46ab275e133d`. The 384-row ledger arithmetically closes.
No package or repository semantics were repaired during runtime.

**Exact next turn: `M3-CP4c-3-TB19-REV` — independent REVIEW + PLAN only.**

The review must adjudicate the newly exposed component-seed frontier, the local-fragment non-crossing candidate,
the continued 371/372 fixture coupling, and the unchanged carried surfaces before freezing any successor Code +
Build correction. No retry and no CB is authorized before that review.
