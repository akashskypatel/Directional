# M3 CP4c-3 TB21 — Artifact-Only Test + Benchmark Report

Date: 2026-09-03 UTC
Turn: `M3-CP4c-3-TB21`
Type: **Test + Benchmark — ARTIFACT-ONLY**
Status: **COMPLETE / VALID SEMANTIC RED / ACCEPTED PREFIX SAFE / D3 CONTRADICTS EXPECTED NON-CELLULARITY / REVIEW REQUIRED / NON-STABLE**

TB21 consumed the immutable CB23 package and executed the full frozen selector. No source, product, test, fixture,
selector, package, mode, discovery or benchmark mutation occurred; no configure, compile or relink occurred.

## 1. Immutable execution authority

| Authority | Value |
|---|---|
| Semantic source | `fa5646106ccaa23770b84a935c6d1d6007928640` |
| Compile run / package job | `33815475590 / 100847694307` |
| Immutable package | artifact `9916511617`, `sha256:8378a108811740cff5fd1a0fc9db66f9e3334d7048ea9e7c7d6e8e1cbd852050` |
| Selector 391 | 391 identities, `f60638a5890e133d7eb3cfcee2783c000192f310a41ef5ec1b4ec3b0cf6086c0` |
| Selector 385 prefix | 388 identities, `164a8b25118a4d00fc9261e4645795ad396130b6d6ea4dd8784158b76e1d0fca` |
| Accepted 365 prefix | `6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1` |
| TB21 run / execute job | `33818038269 / 100854435211` |
| Result artifact | `9917317234`, `sha256:8483cd5fefc200081ccce1160303cab15d499e31decb697a9c58a72627667542` |
| Diagnostic-log artifact | `9917317654`, `sha256:77278f33fdd9558f8df69df31eef8541026bc773482846f4a0b1abc46d14c5e7` |
| 391-row ledger | `8606fb7ba5673e6d3b45b5055f7744559b29a79d5caa8d0df76da85920aa6f77` |
| Package census | pre/post identical, `e15a8ababed2d6580d36abe9e2421a9d573bd29fb5fe36fb08ab844f80161897` |

The caller's SchemaStore validation job passed before the execution job ran. Package metadata, successful package
job identity, internal SHA-256 manifest, executable modes, GMP/GMPXX linkage evidence, source commit and selector
hashes all passed preflight. The result artifact ZIP independently hashes to the digest shown above.

## 2. Full-gate result

All **391** identities ran, one identity per fresh process. The ledger closes at **384 PASS / 7 RED**. Accepted
ordinals **1–365 are 365/365 PASS**. The exact RED set is:

`366, 367, 368, 369, 370, 374, 391`.

Compared with TB20, 371 and 372 clear after the authorized atlas-only fixture decoupling; appended 391 is a new
RED. No accepted-prefix regression occurred.

## 3. D2 — ordinal 366 is semantically unchanged

Ordinal 366 remains `UncutFaceComponentOrbitSeedNotUnique` at source face `(0,1,2)` with
`sourceFaceLocusKind=FirstUnlabeledFaceInIterationOrder`. The deciding component remains:

- `uncutFaceComponent=0`;
- `uncutFaceComponentSeedState=Multiple`;
- `uncutFaceComponentSeedCount=3`;
- untruncated seed orbits `[0,1,3]`;
- component face count `191`.

BW8's seed/locus immutability discriminator therefore passes.

## 4. D3 — the actual embedded graph is cellular; the expected non-cellularity conclusion is contradicted

CB23's production failure census is complete and reports for the **mechanical actual embedded graph**:

`V=22, E=26, F=6, componentCount=1, sourceChi=2, residual=V-E+F-chi=0`.

This is not the historical fragment-owner trace-arc subset. It is the same actual-complex authority used by the
`SurfaceCutGraph` certificate. The package source's `SurfaceCutGraph::canonical_candidate` returns a cut graph only
after `certificate.proves_cellularity()` succeeds; the mechanical fixture has such a cut graph. The certificate's
own arithmetic and accepted disc-face predicate are therefore consistent with the zero residual.

**This contradicts the TB20-REV expectation that ordinal 366's three-seed state establishes that this actual
embedded graph is non-cellular.** TB21 does not resolve the contradiction by weakening the seed guard, the
certificate, or frozen definitions. It routes to independent `M3-CP4c-3-TB21-REV` to reconcile what topology the
source-face component/seeding construction represents versus the certified post-cut actual embedded graph.

## 5. D4 — complete per-orbit attribution on the failing source-face component

Component 0 has **97** source-face boundary edges. Raw rows remain bounded at 64/97 and explicitly truncated, but
the aggregate orbit census is complete and untruncated:

| Orbit | Attributed boundary edges |
|---:|---:|
| 0 | 81 |
| 1 | 1 |
| 3 | 1 |

`uncutFaceComponentBoundaryOrbitCount=3`, `uncutFaceComponentBoundaryOrbitsTruncated=false`. The three rows
attribute **83/97** boundary edges; the remaining 14 are barrier/no-seed edges. Identity 390 independently passes
this projection contract.

## 6. D5 — 371/372 now reach their own assertions and both pass

- **371 PASS** — `FieldTransportAtlas.NonSeparatingBarrierEdgeIsAbsentFromLocalCycleBasis` executes its existing
  assertions. The mechanical atlas publishes the non-separating barrier and excludes it from cycle-basis steps.
- **372 PASS** — `FieldTransportAtlas.CutTransportDomainSatisfiesTheEulerCutIdentity` executes its existing
  assertions. The reported transport region satisfies the frozen cut-Euler identity and its barrier-component and
  barrier-singularity assertions.

This closes the test-coupling owner `M3-CP4c3-TB10-REV-CAND-01`; no product semantics changed to obtain the result.

## 7. D6 — carried surfaces and appended diagnostics

Carried REDs remain independently owned and materially unchanged:

- 367 co-reaches the same mechanical `UncutFaceComponentOrbitSeedNotUnique` frontier and carries the same complete
  `22/26/6/1/2/0` Euler census;
- 368 remains prescribed-sphere `CellularityNotEstablished`, originating
  `RotationSystemInconsistent / TraceEventPositionInvalid`, trace 2/event 30,
  `NoCarrierMatch / SourceEdgeUnavailable`;
- 369 still observes `certificate.saturationUsed=true` where the identity requires false;
- 370 still receives typed error `<04>` rather than `EmptyNetworkOnClosedSurface` `<06>` and no source-face locus;
- 374 still fails at `atlasBuild=false`.

Appended diagnostics:

- **389 PASS** and publishes `m3Cp4c3BW1BW2;V=22;E=26;F=6;componentCount=1;sourceChi=2;residual=0`;
- **390 PASS** and publishes `component=0;orbitCount=3;attributedBoundaryEdges=83;boundaryEdgeCount=97`;
- **391 RED** before its comparison print because `sphere.cutGraph.has_value()` is false (`NotProductionReady`).
  This is a new diagnostic co-reacher of the already-owned prescribed-sphere 368 surface, not evidence for a new
  stable regression category and not authority for a sphere correction inside TB21.

## 8. Regression/candidate accounting

- `M3-CP4c3-TB20-REV-CAND-01` is **not accepted as resolved**: TB21 contradicts its load-bearing non-cellularity
  inference for the certified actual embedded graph. It remains active pending independent review.
- **NEW `M3-CP4c3-TB21-CAND-01` — ACTIVE / ARCHITECTURAL / GATING / NON-STABLE:** a certified cellular actual
  embedded graph (`22-26+6-2=0`, certificate accepted) coexists with a GlobalTopologyPlan source-face complement
  component seeded by three distinct face-walk orbits. The representation/topology relationship must be
  adjudicated before any correction.
- `M3-CP4c3-TB10-REV-CAND-01` **CLOSES / RUNTIME PROVED** because 371/372 both reach and pass their own contracts.
- **NEW `M3-CP4c3-TB21-CAND-02` — ACTIVE / DIAGNOSTIC DEPENDENCY / NON-STABLE:** ordinal 391's sphere half is
  blocked by the already-owned 368 `CellularityNotEstablished` surface. It is separately recorded because 391 is
  a new RED, but it does not create a new stable category or recurrence.
- `M3-CP4c3-TB20-REV-CAND-02` remains active governance debt for review; TB21 does not revert CB21.

Stable accounting remains **44 events / 14 categories / 30 recurrences**; produced-witness debt remains **5**;
semantic M3 package count remains **86**.

## 9. Immutable postflight and exact successor

Pre/post recursive package byte+mode census is exactly identical at
`e15a8ababed2d6580d36abe9e2421a9d573bd29fb5fe36fb08ab844f80161897`.

No configure, compile, relink, package repair, mode repair, generated discovery, source mutation, test mutation,
fixture mutation, selector mutation or benchmark execution occurred.

Because D3 contradicts the expected non-cellularity conclusion, the frozen plan requires exactly one successor:
**`M3-CP4c-3-TB21-REV` — independent REVIEW + PLAN only.** No Code + Build or DEFN execution is pre-authorized.
