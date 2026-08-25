# M3-CP4c-1-CB3 — Code + Build Report

**Status:** COMPLETE / BUILD GREEN
**Turn boundary:** Code + Build only; no Directional runtime execution
**Evidence / semantic source:** `51f510861a02377d1f45607908191f2fdebdcd33`
**Exact next:** `M3-CP4c-1-TB-R3`

## Scope

This turn executed the binding `M3-CP4c-1-TB-R2-REVIEW-PLAN` corrective measures Z0–Z4. It is observation and planning only; no production translation unit changed.

- Z0 source preconditions were confirmed before mutation:
  - `FieldBranchBoundaryPairing.connections` is the incoming × outgoing Cartesian product;
  - `dbary = {-u - v, u, v}` and therefore sums identically to zero;
  - `FieldAlignedCandidateTraceSegment` carries no position datum;
  - C4/C5 and accepted expectations remain untouched.
- Z1 adds non-gating `FieldAlignedCurveNetwork.BranchBoundaryPairingContinuationIsUnique`, which publishes a per-witness census of frame/pairing shapes and ambiguous incoming continuations.
- Z2 adds non-gating `FieldAlignedCurveNetwork.PrescribedSphereCandidateTraceTransportFailureSiteIsObservable`, which reproduces the sphere A2a failure from published authority and reports the exact candidate site, completed-segment count, face/carrier loci, incoming multiplicity, and branch-transport adjacency presence.
- Z3 adds `.agents/Directional/Architecture_M3_CP4c0_DEFN_Charter.md`, a planning-only charter for the blocking predecessor definition turn.
- Z4 leaves the CP4c-1 required-green selector unchanged at 318 identities. The non-gating selector expands from three to five identities.

No file under `src/` or `include/` changed. No fixture was added or altered. No acceptance expectation was weakened.

## Files changed

- `tests/FieldAlignedCurveNetworkTests.cpp`
- `.agents/Directional/Architecture_M3_CP4c1_Non_Gating_Diagnostic_Selector.txt`
- `.agents/Directional/Architecture_M3_CP4c0_DEFN_Charter.md`

## Engineering-guideline review

- Material assumption: the review's Cartesian-product diagnosis must be measured on accepted witnesses rather than treated as settled by source inspection alone.
- Simplest sufficient implementation: two read-only/non-gating tests plus one definition-turn charter; no production seam was reopened in this turn.
- Why smaller is insufficient: one census does not localize the sphere failure site, while one sphere diagnostic does not establish whether ambiguity is latent on accepted witnesses.
- Unrelated refactors/style drift: none.
- Every changed semantic line supports Z1, Z2, Z3, or the five-identity diagnostic selector.

## Build

Authoritative GitHub Actions run **`32867889140`** compiled exact semantic source `51f510861a02377d1f45607908191f2fdebdcd33`.

- schema-validator job `97867532883`: PASS;
- exact patch-application job `97867597370`: PASS;
- producer compile job `97867694421`: PASS;
- full package compile job `97868351487`: PASS;
- producer target `directional_surface_cell_producer_tests`: compiled and linked;
- full targets: `directional_core`, `directional_pipeline`, `directional_surface_cell_authority_kernel_tests`, `directional_surface_cell_producer_tests`, `directional_surface_cell_completion_tests`, `directional_surface_cell_validation_tests`, `directional_compiled_api_tests`, `directional_benchmarks`: all compiled/linked;
- preflight/build exit: `0`;
- source worktree before configure, after configure/build, and final: clean;
- packaged self-excluding `SHA256SUMS`: **27/27 PASS**;
- package self-verification: PASS;
- `runtimeExecution=false` throughout. No generated Directional binary, test, benchmark, discovery command, `ctest`, CLI, fuzzer, help/version command, or custom input was executed.

### Immutable package authority

- result artifact **`9570940997`** — `m3-cp4c1-cb3-result-result-32867889140`;
- GitHub artifact ZIP SHA-256 **`23876c55e51b94ca3a1e5bcfb727a4c0cebce3294fcd2fbda21336b57ae1de16`**;
- result log artifact **`9570941532`** — SHA-256 `716f27c16ebfddd30ff52945759e232fb7569edecdb9ddd414fdbf9f603243d4`;
- producer result artifact `9570913919` — SHA-256 `b98f7e392a1f9388cf3a26c60522ca0340d46cffe72cca52a5516c37f43c85ca`;
- producer log artifact `9570914457` — SHA-256 `86b9a5cae72f177da6aa3bfb9743bcebf4652b98e8605fee595a71fc68bd636b`.

The two earlier apply retries (`32865041406`, `32865732007`) failed in temporary payload orchestration before semantic source was created or compiled. They are not build or runtime evidence and consumed no semantic attempt.

## Frozen selectors for TB-R3

Required-green selector remains:

- identities: **318** unique/non-empty;
- selector SHA-256: `2f2c24acab0e891273c170c82cdc31b6afa3ae4d43e93c95dbdf6d90a88f45bc`;
- accepted 316-prefix SHA-256: `601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c`;
- C4/C5 remain identities 317–318 and remain gating.

Non-gating diagnostic selector is now exactly five identities:

1. `GlobalTopologyPlan.TorusWitnessStageReachabilityIsObservable`
2. `GlobalTopologyPlan.MechanicalWitnessStageReachabilityIsObservable`
3. `GlobalTopologyPlan.SpherePrescribedWitnessStageReachabilityIsObservable`
4. `FieldAlignedCurveNetwork.BranchBoundaryPairingContinuationIsUnique`
5. `FieldAlignedCurveNetwork.PrescribedSphereCandidateTraceTransportFailureSiteIsObservable`

Selector SHA-256: `9f4f287e074d66da9d69c16e22320ed6fe161b6b09de4dc7dd0618741c7fb130`.

## Known risks and falsifiers

CB3 intentionally does not claim the review's predicted runtime observations. TB-R3 must adjudicate them from the immutable package. In particular, if the sphere site is `field_aligned_next_face` or `topology.transport` rather than `field_aligned_outgoing_carrier`, the proposed CP4c-0 domain must return to independent review before implementation.

## Mandatory Test + Benchmark plan

Plan: `.agents/Directional/Architecture_M3_CP4c1_Artifact_Only_Test_Benchmark_Plan.md`.

Validate immutable artifact `9570940997` only. Execute the 318 required identities plus five non-gating observations, one identity per fresh process, with all mutation/build flags false. Expected required result remains **316/318**; the deliverable is Z1/Z2's measurement, not a manufactured green CP4c-1 gate.

## Disposition

`M3-CP4c-1-CB3` is **COMPLETE / BUILD GREEN**. This turn claims compile/package evidence only.

**Exact next:** `M3-CP4c-1-TB-R3` — artifact-only Test + Benchmark on semantic source `51f510861a02377d1f45607908191f2fdebdcd33`, package `9570940997`, 318 required + 5 non-gating = **323 fresh processes**.
