# M3 CP4c-3 TB3-R1 — Artifact-Only Test + Benchmark Report

Date: 2026-08-31 UTC
Turn: `M3-CP4c-3-TB3-R1`
Status: **COMPLETE / VALID SEMANTIC RED — FIRST RED AT ORDINAL 366**

## Authority

- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`
- Immutable semantic/evidence source: `93ed2ff50ddad96c9a6aa93f327b3e4d9d93a9b4`
- Immutable mode-preserving package **72**: artifact `9765247195`, Actions SHA-256 `41ebe4dec4a3eb5c8194900a3f27a0377c3271212edd10fb952c48f55a6a2e6d`
- Inner `package72.tar.gz` SHA-256: `20630897aa432572d0929022abef3861fff80c2b5792c223071990dd2e3c6a73`
- Packaged source archive SHA-256: `fb3080e58f41f7c55790f8a77ad9989ce4a91e212ae323ab71afc9bc061812fb`
- Frozen selector 373 SHA-256: `b47c269851fad1384b5dc9baaf674b3d4ad80ec6c2b40f7f8eda2055c6f44834`
- Authoritative artifact-only run/job: `33416686424 / 99568970224`
- Result artifact: `9767376410`, SHA-256 `7f2c9492d2dae96dfcf1732c320e772be05538a3552ce6a673bd83eb9189824e`
- Diagnostic log artifact: `9767376976`, SHA-256 `492d19f1e08fd339f130a07dfcf891a3b7bbaaf537483fb54af6e9b96095ad72`

No configure, compile, relink, package repair, generated discovery, benchmark, or package/source/product/test/fixture/selector mutation occurred.

## 1. Immutable preflight

Preflight passed before the first Directional process:

- package 72 outer artifact and inner tar digests matched the frozen CB4-PKG authority;
- the complete self-excluding **55-entry** internal `SHA256SUMS` passed;
- semantic source and packaged source archive matched exactly;
- exactly **27** package-relative fixtures were present, including the mechanical and prescribed-sphere witnesses;
- GMP/GMPXX command-boundary evidence remained present;
- all six frozen executables reproduced their exact SHA-256 values and mode **`0755`** without repair;
- selector 373 and frozen 355/357/361/365/367/370 prefixes reproduced their frozen byte identities;
- static ownership mapped all 373 identities exactly once across the four test executables: producer **227**, authority-kernel **30**, completion **75**, validation **41**.

`M3-CP4c3-TB3-ORCH-01` therefore remains resolved: the package-71 executable-mode defect did not recur.

## 2. Ordered gate result

The gate executed one exact identity per fresh process from ordinal 1 and stopped at the first semantic red.

- ordinals **1–365**: **365/365 PASS**;
- ordinal **366**: `GlobalTopologyPlan.MechanicalFeatureWitnessDerivesRegionsThroughProductionEntryPath` selected exactly once and exited 1;
- ordinals **367–373**: **not executed** under first-red semantics;
- total: **366 executed / 365 PASS / 1 RED**.

The first-red exception is:

`NotProductionReady/field-aligned-network/VertexTransitSectorUnresolved`

This is a later failure seam than TB2. The prior `InvalidFieldTransportAtlas/.../MissingSingularityBranchTransport` stop is absent.

## 3. What the runtime proves

The mechanical witness now reaches field-aligned-network construction. Its atlas partition diagnostics are emitted for the four non-barrier prescribed singularities at source vertices **10, 35, 47, 71**, each with the expected three branch classes. No `MissingSingularityBranchTransport` occurs. This proves Amendment 16/P2 clears the illegal closed-fan branch-transport demand far enough for the producer to enter network trace construction.

It does **not** prove CP4c-3 C2 or the complete P2 contract: ordinal 366 is still red, and first-red prevents ordinals 367–373 from executing. In particular, the frozen barrier-exclusion, Euler-cut, prescribed-sphere, ordinary-proposal, empty-network, and barrier-singularity-binding identities remain unknown at 367–373.

## 4. New first-red localization

Static inspection of the exact semantic source localizes `VertexTransitSectorUnresolved` to `resolve_field_vertex_transit` in `src/geometry/SurfaceCellTracing.cpp`.

The routine walks only published `FieldBranchTransportAdjacency` entries incident to the hit vertex while preserving source component/topology region and transporting the branch. For each reachable `(face, branch)` state it tests `direction_in_vertex_sector(...)`; after deduplication it requires **exactly one** continuation candidate. Any candidate cardinality other than one returns `VertexTransitSectorUnresolved` and stores the candidate faces in `error.publishedFaces`.

The current CP4c production-harness formatting collapses a `FieldAlignedCurveNetworkError` to only `stage=field-aligned-network;error=<code>` at this path. The underlying typed error can carry `sourceVertex`, `sourceFace`, `branch`, and `publishedFaces`, but the failing production exception did not publish those fields. Consequently this TB cannot distinguish the two materially different causes:

1. **zero candidates** — no reachable transported branch lies in an admissible outgoing vertex sector; or
2. **multiple candidates** — more than one reachable sector satisfies the exact predicate.

Nor does the current evidence identify whether the failing call entered through `FaceInterior` or `EdgeTransit`. Those are review questions, not grounds for an in-TB correction.

## 5. Regression disposition

New candidate `M3-CP4c3-TB3-R1-CAND-01` is **ACTIVE / SEMANTIC / CAUSE UNADJUDICATED / GATING / NON-STABLE** for the ordinal-366 `VertexTransitSectorUnresolved` first red. Causality is deliberately not assigned: the review must determine whether this is pre-existing and merely unmasked, an interaction with Amendment 16/P2's changed port set, or another representation/consumer mismatch.

Prior records are updated as follows:

- `M3-CP4c3-TB2-REV-CAND-01`: **RESOLVED** — CB3 independently compared package 69/70 binary hashes.
- `M3-CP4c3-TB2-ORCH-01`: **RESOLVED / RUNTIME PROVED** — package-relative fixtures and removal of the absolute source fallback survived package 72 preflight and execution past the former fixture stop.
- `M3-CP4c3-TB2-CAND-01`: **PRIOR FAILURE LOCUS CLEARED / SUPERSEDED BY DOWNSTREAM FIRST RED** — `MissingSingularityBranchTransport` no longer occurs, but the gating identity remains red and CP4c-3 does not close.
- `M3-CP4c3-DEFN-R1-CAND-01` and the inherited ordinal 368–370 candidates remain active because first-red prevented their confirming identities from running.

Stable accounting remains **44 events / 14 categories / 30 recurrences**, produced-witness debt **5**, semantic M3 packages **70**. The current checkpoint was already unaccepted, and the accepted 365-prefix remained green, so no accepted behavior loss is demonstrated.

## 6. Immutable postflight

Postflight re-proved the immutable package and selector authority after the semantic red. Package/tar/source/fixture/binary identity and executable modes remained unchanged. Recorded boundary flags are:

- `runtimeExecution=true` — exactly the 366 selected test processes above;
- `benchmarkExecution=false`;
- `configure=false`, `compile=false`, `relink=false`;
- `packageRepair=false`, `generatedDiscovery=false`;
- `productMutation=false`, `testMutation=false`, `fixtureMutation=false`, `selectorMutation=false`.

The red is therefore valid semantic evidence rather than orchestration failure.

## 7. Disposition

`M3-CP4c-3` remains **OPEN**. A deterministic semantic red is not retried unchanged.

Exact successor: **independent `M3-CP4c-3-TB3-R1-REV` — REVIEW + PLAN** under `Architecture_M3_CP4c3_TB3_R1_Independent_Review_Plan.md`. No product/test/fixture/selector mutation, compile, package, or additional Directional runtime is authorized before that review adjudicates the candidate cardinality/locus and freezes any bounded successor measures.
