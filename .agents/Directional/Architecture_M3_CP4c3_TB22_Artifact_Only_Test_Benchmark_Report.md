# M3-CP4c-3-TB22 — Artifact-Only Test + Benchmark Report

- Phase: `M3-CP4c-3-TB22`
- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`
- Execution mode: canonical Test + Benchmark, artifact-only
- Validated source commit: `d69729a69a40b020968ed6ef1fbc1bc788284518`
- Build artifact: `9919225745`, `m3-cp4c3-cb24-compile-result-33823590494`, `sha256:7955c243d7968e51e62f0f8d4b0cc96da313a2356ee8bf2eeba7c995b856e87d`
- Compile run/job: `33823590494 / 100871347582`
- TB22 execution run/job: `33826248118 / 100879465830`
- TB22 result/log artifacts: `9920122224 / 9920122598`
- TB22 result/log artifact digests: `sha256:862d3a4ccb7bc6a2dca1c1b6cda01fba7b21ca0d458c046f296e94fac45f0fab` / `sha256:67a3e1878a4f4985c80c077fb780fe72906a2f62a140bed968e45ace4f33a65a`
- Test + Benchmark plan: `Architecture_M3_CP4c3_TB22_Artifact_Only_Test_Benchmark_Plan.md` (consumed by this report)
- Environment: GitHub-hosted Ubuntu 24.04; immutable packaged binaries; no benchmark execution

## Plan Execution

All 393 selector identities executed in ordinal order, one exact identity per fresh process. Artifact preflight verified the immutable package digest, internal `SHA256SUMS`, semantic source identity, GMP/GMPXX build boundary, executable modes, selector count/hash/prefixes, and the static identity-to-binary mapping before runtime. The postflight recursive byte+mode census exactly matched preflight.

No plan-defined semantic RED stopped the remainder. No configure, compile, relink, regeneration, generated binary discovery/list/help/version execution, package/mode repair, source/test/fixture/selector mutation, or benchmark occurred.

## Tests Executed and Result

- Selector: **393 identities**, SHA-256 `ee8cc03360c30b7ef662c3972b852d8b6f17dddbf5abac29a632e02227644c4d`.
- Complete ledger: **387 PASS / 6 RED**.
- Accepted prefix: **365 / 365 PASS**.
- RED ordinals: **366, 367, 368, 369, 370, 374**.
- Exact 393-row ledger SHA-256: `4998ca25b1477c2a32299bc3eb3d552e3ea9b0e2ccbf0eb4894393964f29dbbe`.
- Static identity map SHA-256: `fcae7c39cd8363b142203e5ce20578fdd56510b840a4d7a4525a1c36762f4202`.
- Pre/post package byte+mode census SHA-256: `7e0c552c79281f97b7553406acd44383ff867197f36da54cd306ac9258fa2b74` on both sides; postflight **IDENTICAL**.

The six REDs preserve their existing ownership. There is no accepted-prefix regression and no new stable regression category.

## Load-Bearing Runtime Findings

### Ordinal 366 remains the same seed-state surface

Ordinal 366 remains `GlobalTopologyPlan.MechanicalFeatureWitnessDerivesRegionsThroughProductionEntryPath` and terminates at `UncutFaceComponentOrbitSeedNotUnique` for source-face component 0. The production envelope retains:

- first source-face locus `(0,1,2)`;
- component face count **191**;
- seed state `Multiple`, seed count **3**, exact untruncated seed orbits **`[0,1,3]`**;
- certified actual embedded graph `V=22,E=26,F=6,componentCount=1,sourceChi=2,residual=0`;
- boundary edge count **97**; raw rows are truncated, while aggregate orbit attribution remains untruncated at orbit `0→81`, `1→1`, `3→1`.

This preserves the same semantic seed-uniqueness guard. TB22 does not weaken or bypass it.

### BY2/BY3 minority rows identify edge-orbit seeding inside one certificate face per edge

The two retained minority-seed rows are:

| Source edge | Seed | Seed rule | Component source face | Labeled source face | Component certificate face | Labeled certificate face |
|---|---:|---|---|---|---:|---:|
| `10-79` | 3 | `edgeOrbitEvidence` | `10,79,151` | `10,11,79` | 3 | 3 |
| `29-35` | 1 | `edgeOrbitEvidence` | `28,29,35` | `29,35,91` | 1 | 1 |

The production row for each also reports `otherSideLabeled=true`, `labeledFaceOwnerCount=2`, `barrierClass=none`, `noSeedReason=none`, and `minoritySeedOrbit=true`. Ordinal 393 independently required-green re-publishes the same distilled rows.

### BY4 projection-faithfulness residual is zero

For the same mechanical path, production diagnostics report:

`projectionFaithfulnessResidual=0; witnessCount=0; truncated=false`.

Thus the specific CB24 measurement found **no adjacent uncut source-triangle pair assigned to different certificate faces across an edge absent from `componentBarriers`**. Together with the minority rows' same certificate-face attribution on each side, this runtime evidence does not support the prior “missing barrier between different certificate faces” branch of `M3-CP4c3-TB21-CAND-01` at the measured projection relation. It instead leaves the edge-orbit seed-read branch as the live interpretation to adjudicate. **TB22 does not select or authorize a correction**; `M3-CP4c-3-TB22-REV` must validate the residual's semantics and derive the proper seed-selection contract independently of the implementation.

## Re-scoped and Required-Green Witnesses

- **Ordinal 391 PASS.** Mechanical/torus evidence executes independently; the torus reports `V=72,E=76,F=4,componentCount=1,sourceChi=0,residual=0`. The prescribed-sphere half reports `status=SKIPPED,reason=ordinal368-open,terminalFailureCode=NotProductionReady`. `M3-CP4c3-TB21-CAND-02` therefore **CLOSES / RUNTIME PROVED / NON-STABLE**; ordinal 391 is no longer a RED caused by the owned 368 dependency.
- **Ordinal 392 PASS:** `GlobalTopologyPlan.UncutFaceComponentBoundaryEvidenceRetainsDistinctSeedAndReasonRows`.
- **Ordinal 393 PASS:** `GlobalTopologyPlan.MechanicalProjectionEvidencePublishesMinorityRowsAndFaithfulnessResidual`.
- **Ordinals 371 and 372 remain PASS**, preserving their TB21 closure.

## Carried RED Surfaces

The independently owned carried surfaces remain RED at 367/368/369/370/374:

- 367 co-reaches the mechanical seed-uniqueness surface.
- 368 remains the prescribed-sphere `CellularityNotEstablished` path (`sphere.cutGraph` unavailable).
- 369 remains the saturation-used quality surface.
- 370 retains the typed-error mismatch (`<04>` observed where `<06>` is expected) and no source-face locus.
- 374 remains the folded-cone atlas-build surface.

No common-root conclusion is inferred from the coexistence of these failures.

## Regression / Candidate Accounting

`M3-CP4c3-TB21-CAND-01` remains **ACTIVE / ARCHITECTURAL / GATING / NON-STABLE**, narrowed by runtime evidence: the measured projection-faithfulness residual is zero, both minority edges remain within one certificate face per side, and their minority seeds are produced by `edgeOrbitEvidence`. Independent TB22-REV owns semantic interpretation and any correction owner.

`M3-CP4c3-TB21-CAND-02` is **CLOSED / RUNTIME PROVED / NON-STABLE** by ordinal 391 PASS.

Stable accounting is unchanged at **44 events / 14 categories / 30 recurrences**. Produced-witness debt remains **5**. Semantic M3 package count remains **87**. CP4c-3 remains **OPEN**.

## Artifact Integrity and Orchestration

The TB22 execution itself completed successfully and produced complete result/log artifacts. Package pre/post census is byte+mode identical. No repair or mutation occurred.

A separate early cleanup-manifest commit accidentally triggered the durable cleanup workflow before the two temporary workflow callers had been retired. Cleanup run `33826243066` failed closed in its durable-workflow inventory check because `agent-m3-cp4c3-tb22.yml` and `m3-cp2b-cb-r3-schema-validate.yml` were still present. Its repository-removal step, PR-conversation deletion steps, and observer were all skipped. It did not execute Directional runtime, alter TB22 evidence, or mutate semantic source. Final cleanup is performed only after durable closeout and workflow-first retirement.

## Phase Status

**COMPLETE / VALID SEMANTIC RED / ACCEPTED PREFIX SAFE / ARTIFACT IMMUTABLE.** The expected no-new-regression ledger was observed exactly: **387 PASS / 6 RED** with accepted **365/365**.

## Optional Review Decision

- Review: **required**.
- Exact successor: **independent `M3-CP4c-3-TB22-REV`**.
- Reason: the zero projection residual and same-certificate minority rows materially narrow the architectural candidate, but the correct seed-selection contract and correction owner must be independently derived before any Code + Build or DEFN execution.
- No Code + Build, DEFN execution, compile, test, benchmark, or runtime is pre-authorized after this closeout.

## Live Handoff

`Future_Chat_Session_Handoff.md`, `M3_CP4c_Current_And_Forward.md`, `Regression_Root_Cause_Tracker.md`, `TODO.md`, and `CHANGELOG.md` are updated by the TB22 closeout. The next context must load this report plus `Architecture_M3_CP4c3_TB22_Independent_Review_Plan.md`. Runtime evidence remains attributed to semantic source `d69729a69a40b020968ed6ef1fbc1bc788284518`, not to later documentation/control commits.
