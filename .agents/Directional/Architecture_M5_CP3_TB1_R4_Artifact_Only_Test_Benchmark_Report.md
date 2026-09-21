# M5-CP3-TB1-R4 Artifact-Only Test + Benchmark Report

**Turn:** `M5-CP3-TB1-R4-EXEC`
**Boundary:** artifact-only Test + Benchmark
**Result:** **COMPLETE / MECHANICALLY COMPLETE / SEMANTIC RED / REVIEW REQUIRED**
**Exact successor:** `M5-CP3-TB1-R4-REV`

## 1. Immutable authority and orchestration

Candidate artifact `10627250028` from semantic source `001dfe8f0fec8a8dc2475e534fadc29967cadf84` was consumed without rebuild or repair. Provider/download SHA-256 is `0d26b01c026651ecacf57af04615746e6b48b09db2e5f1baa1dce62db31bc28f`; root `SHA256SUMS` hashes to `abbda66e46b059832027b82b5dde457dfb2f8b10472bdb742f61f25979e7e02b` and verifies **28/28**; packaged source archive SHA-256 is `4335090caf9a1b5f38efa7ce3745d9f1a4bae13871c41572baa62abd2e06570b`. Accepted routing artifact `10592987234` remained fixed at ZIP SHA-256 `352c8cfc9c9b89cf0d532c8e0836339a31ba35fd6e854a781721cbc76f02afce`, identity-map SHA-256 `7a92e7a3b8a69466423c4a0d2ad5ece2dcd4912f04eeb99e1f32fa70b4a5cf6c`, selector430 SHA-256 `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`, and first427 SHA-256 `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`.

The first trigger commit `f73e7f97b6e37f4a636f75cc420ae36622c9a5ba` produced no workflow run. The temporary caller was corrected in `67645b6267e3a6ca5c577d1d5334ed09f7a2efaa`, then retry trigger `c41dfaeb6d6bf6f439690e0f06000568344eabef` launched the authoritative run. No semantic credit is assigned to the first trigger.

Authoritative runtime run/job is `35575202225 / 106255409380`. Workflow schema validation passed. Result artifact `10627818091` has provider/download SHA-256 `a3a17e04b950abdd8563dc279ae1cb4d119f7acb00fba52f7db882a52b488693`; diagnostic log artifact `10628501968` has provider SHA-256 `38b92dcccce3b22ece60984b2d390279911e0ce59baf942956ac03c5c3cd9e4b`. The result self-manifest contains **908** entries, hashes to `a77abc5eafa6420cacd91f712c6853bab81ede91083739d46a7b467f7bbaa812`, and verifies **908/908**.

## 2. Frozen execution result

All **445** planned fresh exact-filter processes executed with exact-one selection and zero skips. Overall result is **432 PASS / 13 RED**:

- mechanism rows: **9/9 PASS**;
- produced rows: **0/6 PASS**, all six RED with `PeriodicHolonomyMismatch` while establishing the production torus fixture;
- selector430: **423/430 PASS**;
- selector RED ordinals: **18, 20, 21, 22, 23, 25, 408**;
- benchmark executions: **0**.

Selector ordinal408, `RemeshPipeline.ExactA3ToA4TorusProductionPathPublishesTypedSharedBoundaryIdentity`, still receives `NotProductionReady/tracing/None` and fails its pre-existing required `Produced` assertion. This does not demonstrate recovery of the open `M5-CP3-TB1-R1-CAND-01 / RP-01` event.

The six newly red accepted selector identities are:

1. `FieldTransportAtlas.BranchTopologyIsInvariantToEquivalentZ4Relabeling`
2. `FieldTransportAtlas.IndependentOracleRejectsBranchPairingOrPortAttachmentTamper`
3. `FieldTransportAtlas.IndependentOracleRejectsCompleteTypedTamperMatrix`
4. `FieldTransportAtlas.IndependentTreeCotreeOracleSurvivesRowAndBranchRelabeling`
5. `FieldTransportAtlas.PublishesCanonicalBranchFramesAndBoundaryPairings`
6. `FieldTransportAtlas.PublishesReciprocalTypedAuthorityAndRelativeBoundaryWitness`

Each fails before its intended later discriminator because a baseline `independent_validate_snapshot(...)` that is expected to accept a valid atlas now returns an error.

## 3. Regression classification required by the TB gate

### `M5-CP3-TB1-R4-CAND-01` — endpoint recovery still RED

The six produced rows and selector ordinal408 reproduce the same endpoint family as R1/R2/R3: `PeriodicHolonomyMismatch` / `Rejected` rather than `Produced`. EXEC makes no new internal-cause claim. This is recorded as **continuation evidence for the already-open stable `RP-01 / AUTHORITY_DOMAIN_CONFLATION` recurrence**, with **+0 stable events / +0 categories / +0 recurrences** pending independent R4 Review.

### `M5-CP3-TB1-R4-CAND-02` — independent atlas oracle omitted the newly published transition-value identity domain

Static localization on the immutable packaged source is decisive for the six new selector reds. CB5 intentionally added retained `FieldTransportTransitionValue` facts to `FieldTransportAtlas` semantic identity. Production `field_transport_atlas_hash(...)` consumes the transition-value vector before adjacency/barrier/cycle facts. The independent test oracle's `IndependentAtlasSnapshot` does **not** contain transition values, and `independent_atlas_digest(...)` therefore still hashes the pre-CB5 identity domain. `independent_validate_snapshot(...)` ends by comparing that stale independent digest with the now-extended published `atlasDigest`, so a valid baseline returns `CanonicalBindingMismatch`; tests that expect baseline validity fail before their actual relabel/tamper assertions.

Classification: **TEST-AUTHORITY ORACLE DRIFT / CONTRACT-COVERAGE GAP / NON-STABLE / REVIEW REQUIRED**. This is not evidence that hard-feature traversal was widened or that the new transition values are semantically invalid. Stable accounting therefore remains **50 events / 14 categories / 36 recurrences**, produced-witness debt **5**, subject to independent R4 Review. The accepted runtime authority remains package `10601978228` / source `0798547dedd8be05f9cd7a096b07e6bd94755316` under selector430 **430/430**.

## 4. Immutable postflight and prohibited operations

Postflight is exact:

- package byte+mode census unchanged;
- packaged-source byte+mode census unchanged;
- execution-view byte+mode census unchanged;
- root candidate manifest still **28/28**;
- selector430 and first427 hashes unchanged;
- routing map unchanged;
- `orchestration_failure=false`;
- configure/compile/relink/generated-discovery/package-repair/mode-repair/source-test-fixture-selector-mutation counters all **0**;
- benchmark execution **0**.

No source, test, fixture, selector, build logic, package bytes, executable mode, or accepted runtime authority was changed by this Test + Benchmark turn.

## 5. Disposition

Candidate `10627250028` remains **unpromoted**. All four M5 produced-witness debts remain open and selector publication remains prohibited. R4 earns no production-debt or selector credit.

Exact successor is independent runtime-free **`M5-CP3-TB1-R4-REV`**. Review must independently re-derive the 445-process evidence, adjudicate `R4-CAND-01` against the existing stable RP-01 event, adjudicate `R4-CAND-02` as test-authority versus product authority, verify whether production actually reaches and consumes the atlas-owned transition-value seam, and resolve the carried `M5-CP3-TB1-R3-REV-OBS-01` frozen-definition recording obligation before any candidate acceptance, test correction, further implementation, debt discharge, or selector-publication step.
