# M3-CP4c-3-TB26-R1 — Artifact-Only Test + Benchmark Report

**Verdict:** COMPLETE / VALID SEMANTIC RUNTIME / SEMANTIC RED / ACCEPTED PREFIX SAFE / ROUTE TO INDEPENDENT REVIEW + PLAN.

## Immutable authority

- semantic source: `e045bf7147afc02bd90eff4822e4b609edbaba66`
- immutable CB30 package artifact: `9957324848`, SHA-256 `7ea9446f2e8cde520b8f7570cc62ba189ccffe801bd68a298f56560c661f81de`
- selector 405: `615370b65e590dadb59d7a233c6ce74b7dc8cb46a1f40fd3ea5a44257583aae7`
- formal run/job: `33931380325 / 101210520053`, SUCCESS
- result artifact: `9958722468`, SHA-256 `1daf2ec4a4b8a644f7cf66407ac14b69ac92aa20ec3c241093270179ae6c6768`
- diagnostic-log artifact: `9958722840`, SHA-256 `8aa10c9a8c7725aca996b304d3db59ab6a42bcde69cd2bb33c6cf896102732f0`
- ledger SHA-256: `5d16ee4508ead7eb5422c4dd0d03a9903009b8552d8e815ff2394f872eebe34a`
- identity-map SHA-256: `63e353ce01be9e8fabaed76ae40bd7a55e1193967a439e1bcd8a7b7e3bbd52e2`
- CJ6 selected raw-payload SHA-256: `8336ce97102a5cfeb2e554108992642d6d3a832de2c6b960bb1c624cf025119c`

The result ZIP provider digest was independently rechecked after download. Selector 403/401/397/365 exact-prefix authority passed before runtime.

## Execution boundary

All 405 identities executed exactly once, in selector order, one identity per fresh process. `orchestration_failure=false`, `runtime_started=true`, `runtime_completed=true`; configure, compile, relink, generated discovery, package repair, mode repair and source/test/fixture/selector mutation were all false. Package, packaged-source and execution-view censuses are byte-identical before/after. No interpretation-driven retry occurred.

Census hashes:

- package: `94b2f2d846b3027eeeb57d9849eb39d9f98ee583332cb8ac7ac625779873d7ae`
- packaged source: `387e29275c2b06edd39ccf72e7869a88ba69ffdbcaae6388ab3118c4f723e5a2`
- execution view: `9f5ed67b76fb7c2778dd001e73f3a877b16fc44c653c885c2e363abbdc02b32a`

## Ledger

**397 PASS / 8 RED.** Accepted prefix **1–365 = 365/365 PASS**. RED ordinals:

`366, 367, 368, 369, 370, 374, 393, 398`

Relative to TB25-R1, **389 and 390 recover RED → PASS**. New ordinals **404 and 405 PASS**. The other eight REDs remain red. There is no accepted-green loss.

Key gate results:

| Ordinal | Result | Runtime fact |
|---:|:---:|---|
| 389 | PASS | embedded Euler census `V=22;E=26;F=6;components=1;sourceChi=2;residual=0` |
| 390 | PASS | component 0 census publishes `certifiedOwnerCount=3` without asserting a winner |
| 393 | RED | failure-locus observation count is 573 while component face count is 191; owners serialize as `0:191,1:191,3:191` |
| 398 | RED | strong `proves_cellularity()` ownership-totality gate remains false |
| 404 | PASS | component 0 publishes `boundaryEdges=76;interiorArcs=4;vertexTransits=53;seedAttributions=46` |
| 405 | PASS | constructed vertex-transit falsifiability witness passes |

## TB26-REV diagnostic findings

### 1. CJ6 selects the separating-arc horn

The frozen discriminator is no longer ambiguous at the aggregate level. Component 0 has **4 interior trace-arc incidences**, so the first horn applies: at least one separating trace arc meets the interior of the 191-face component. The “component lies in exactly one certified face” horn is false for this measured object. Vertex-transit evidence is also nonempty at **53** rows, but the discriminator stops at interior-arc incidence.

This is progress, not a new regression: it resolves `M3-CP4c3-TB25-REV-CAND-02` toward the separating-arc mechanism and explains why source-edge-only component ownership cannot be reconciled by choosing the 81/1/1 majority.

### 2. CJ7 restores disagreement honestly; no winner exists

Mechanical component 0 now has `seedCount=3`, `seedState=Multiple`, distinct orbits `[0,1,3]`. GlobalTopologyPlan fails at `UncutFaceComponentOrbitSeedNotUnique` instead of silently choosing one. This is exactly the fail-closed CJ7 behavior. Ordinals 366/367 remain RED because the production plan cannot consume a conflicting ownership component; ordinal 398 remains the correct strong ownership-totality gate.

### 3. The required named-locus evidence is incomplete

Ordinal 404 proves the in-memory census is published, complete by its tested vector/count contracts and untruncated, but its runtime output serializes **only aggregate counts**. With `interiorArcs=4` and `vertexTransits=53`, the TB26 plan required the selected discriminator to name source faces plus arc IDs/kinds/orbits (and, if needed, vertex/trace/segment/non-barrier face pair). None of those component-census rows are emitted by ordinal 404 or another selector-405 identity. Therefore TB26 cannot independently name which four arcs constitute the decisive incidence set from runtime evidence alone.

This is an **evidence-surface/test-authority defect**, not an orchestration failure and not permission to infer rows from source code. The independent review must decide the minimal diagnostic publication needed before a successor can claim the dichotomy fully discharged.

### 4. The boundary census does not reproduce the frozen 97-edge baseline

TB25/TB20 authority records the identical 191-face mechanical component with **97 boundary edges**. TB26 ordinal 404 reports **76** boundary edges while CB30 was forbidden to add/remove barriers. Because ordinal 404 intentionally asserts completeness rather than a hard-coded count, it still passes. The discrepancy requires independent adjudication: determine whether the old 97 and new 76 count different boundary domains or whether CJ6 omitted 21 rows. Do not silently treat 76 as equivalent to the frozen 97-edge requirement.

### 5. Ordinal 393 is now collateral to multi-seed semantics

CJ8 correctly removed ownership-totality coupling from 393 by using `proves_embedded_cellularity()`, but the failure-locus branch still asserts one certified-face observation per component face. CJ7 now publishes all three conflicting owners on each of 191 faces, so the plan-layer multiplicity is **573**, not 191. The identity's owner-map publication succeeds and prints `certifiedOwners=0:191,1:191,3:191;allEqual=false`; its remaining equality assertion is incompatible with the deliberately preserved full conflict multiset. Independent review must decide whether 393 should count source faces, owner observations, or a different contract. No test weakening is authorized in this turn.

### 6. Carried REDs remain separately owned

- 368 remains `RotationSystemInconsistent → TraceEventPositionInvalid`, trace 2/event 30, `NoCarrierMatch / SourceEdgeUnavailable`.
- 369 remains its previously carried ordinary-proposal/saturation surface.
- 370 still returns the wrong typed error and lacks the expected source-face locus.
- 374 still fails at folded-cone `atlasBuild`, the pre-classified flat-star-field fixture issue.

No evidence justifies merging these into the ownership cause.

## Resource evidence

Peak recorded RSS: **18,664 KiB** at ordinal 147. Longest identity elapsed time: **25.97 s** at ordinal 137. Resource capture exists for every ledger row; no resource threshold is promoted to a semantic checkpoint criterion here.

## Accounting and routing

No accepted-prefix regression occurred. 389/390 recovery and 404/405 green are not stable events. The remaining carried REDs are already owned; the new aggregate separating-arc evidence resolves an open candidate rather than creating a regression. The 393 contract mismatch, missing named-locus serialization and 76-vs-97 boundary discrepancy are **review candidates / non-stable pending independent adjudication**.

Stable accounting remains **44 events / 14 categories / 30 recurrences**. Produced-witness debt remains **5**. Semantic M3 package count remains **91**.

CP4c-3 remains **OPEN**. Per the mandatory red-TB workflow, the exact next action is the separately outsourced **`M3-CP4c-3-TB26-INDEPENDENT-REVIEW`**. No retry, product patch, selector change, barrier change, ownership winner, or CB successor is authorized before that independent review.
