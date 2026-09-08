# M3-CP4c-3-TB40-EXEC — Artifact-Only Runtime Evidence Report

**Verdict:** **MECHANICALLY VALID / SEMANTIC GATE RED / NOT PROMOTED / REVIEW REQUIRED**
**Date:** 2026-09-08

## Immutable authority

Run/job `34246144235 / 102128633623` on immutable CB45 package105 source `0f09439893182235c382492583b82aa35f25045c` executed all **409/409** selector identities exactly once with zero selection mismatch/timeout. Raw result: **394 PASS / 15 RED**, accepted **361/365**, RED `[311,314,356,357,366,367,368,369,370,374,390,393,398,406,407]`. 312/409 and 404/408 PASS; ownership **300/0/0**; retired legacy codes are absent. TB40 is mechanically valid but **not promoted**; TB39 package104 remains semantic runtime authority pending independent review.

Package105 artifact `10057456162` / `m3-cp4c3-cb45-result-34229976475` has provider/download SHA-256 `c9cd0397d22b7cc0c343838a90fdcfe649137fa37a985453778c04731049b99e`; packaged source archive `7d1cb457d1101e6addbadd732d783efdae956f61b9732b492c1b9063828a6472`. Selector409 / selector408-prefix / harness SHA-256 are `eea6d8c2bbc8e9247deb4bfbbe6763042c76002d1894dd62e35f80262403b53e` / `2a742ba92dba744425fccaf81d5cc7a57885cbff37c779d525218fcd70500af6` / `aaadab351c0ba28a39c87aff1948f83ab0c4c71520662177e5cdf6fd08b30ed3`; frozen test source is `7f683267354783068443ffe02f3798723b524633bfb4fc70bca717ce4de80b4d`.

Result artifact `10064213251` / `m3-cp4c3-tb40-result-34246144235` SHA-256 `c165ce0dda2c0bb7742ea6f9a6fd2580932596448892f5bd76f6d585ea031012`; log artifact `10064214144` SHA-256 `990a8f5f41ed5bfd21d5c818fd94240d6e6082c9548fb3561061debf59fa779c`. Ledger SHA-256 `b4ca8fc04d6bac98f88b0ccc26b354fdc6e60f63cf6162e6c929068eb33f1f75`; failure-detail table `26b44b1d0877810f0fc8700e7093eee069beb65e87583ccb9c2210e0267116a8`; verifier JSON `68cfb28e8c1fdf647511ee11cee7a89d2c135e6b37eb90d60301de845806b80c`.

Preflight and postflight prove `runtime_started=true`, `runtime_completed=true`, `orchestration_failure=false`, selection integrity, and zero configure/compile/relink/benchmark/generated-discovery/package-repair/mode-repair/source-test-fixture-selector mutation. Package/source/execution-view byte+mode censuses are identical pre/post.

## Raw gate evidence

Accepted 311 `ProvesDiscTopologyForEveryEmittedRegion` is RED: expected `orbitIndex=1`, published `actualEmbeddedFace.orbit=0`, then zero upstream matches for that published binding. Accepted 314 `IndependentDiscProofOracleAgreesWithPublishedCertificates` is RED at `clause=PublishedCertificate` with `proof.passed=false`.

Accepted 356/357 emit the required non-empty, non-uniform census but directly falsify exact binding. Each publishes one complete complex row and four region rows:

```text
region 0: derivedOrbit=0 certificateOrbit=1 upstreamMatchCount=1
region 1: derivedOrbit=1 certificateOrbit=0 upstreamMatchCount=1
region 2: derivedOrbit=2 certificateOrbit=2 upstreamMatchCount=1
region 3: derivedOrbit=3 certificateOrbit=3 upstreamMatchCount=1
```

Boundary-arc counts match and all rows publish `discTopologyEstablished=true` / `fieldRegularity=true`; the failure is specifically `derivedOrbit != certificateOrbit` for regions 0/1.

366/367 remain RED but have advanced beyond the retired `RegionEulerCharacteristicNotOne` / `RegionInteriorDisconnected` producers to `RegionSourceFaceOwningFragmentMissing` at `RegionCertification`. Protected 390/393/406/407 regress because `regionFrontierComponentCount` is 0 where their oracle requires non-empty publication. Carried 368/369/370/374/398 remain on their pre-existing owner surfaces; EXEC does not reassign them.

## Candidate intake

- **`M3-CP4c3-TB40-EXEC-CAND-01` — NEW / HARD-GATE REGRESSION / REVIEW REQUIRED / UNPRICED.** Accepted 311/314/356/357 regress; 356/357 directly falsify the frozen 1:1 face binding.
- **`M3-CP4c3-TB40-EXEC-CAND-02` — NEW / PROTECTED-SURFACE REGRESSION / REVIEW REQUIRED / UNPRICED.** 390/393/406/407 regress at an empty region-frontier component publication.

EXEC does not promote package105, close/reprice either candidate, or authorize correction. Stable accounting remains last-adjudicated **46 events / 14 categories / 32 recurrences**, debt **5**, semantic packages **105**.

## Exact successor

**`M3-CP4c-3-TB40-REV` — independent evidence-only review/adjudication.** Review owns classification of the accepted/binding failures, protected regressions, 366/367's later frontier, carried owners, stable accounting, and one exact successor. No compile, new runtime, package repair, or product/test/fixture/selector semantic mutation is authorized first.
