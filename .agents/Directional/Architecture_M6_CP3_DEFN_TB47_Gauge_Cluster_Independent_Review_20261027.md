# TB47 gauge-cluster independent review — INCOMPLETE (2026-10-27)

**Turn:** `M6-CP3-DEFN-RP01-TB47-GAUGE-CLUSTER`.
**Boundary:** Review only; no runtime, build, or product/test/fixture/selector/benchmark mutations. This is evidence preservation, **not** a completed Review, patch authorization, or CP3 promotion.

## Primary evidence

- Exact source snapshot `7dba3d3bec578b61ea200f1cec1c8eafce2512b0`; Actions `40510003380`; artifact `12736183727`, ZIP SHA-256 `0031ddf499c492484f0bf55784a51928ec7b6abbabc676415a07b8433a1bb7f0`; 5,950/5,950 packaged source hashes independently matched.
- TB47 immutable artifact `12734719880`, ZIP SHA-256 `f03efe3c2f75b113ac9e05329799955e4306d611feb4d83c38a2cd672be6b04d`; 1,014/1,014 packaged hashes and 504 ledger rows independently checked, 500 PASS / 4 registered RED.
- G failures: `focused30:12` at `SurfaceCellTransitionQuotientTests.cpp:5581` (A5 hard rail transport); `selector:442` at `FieldTransportAtlasTests.cpp:2856` (SingularityMismatch sourceEdge (2,3)); `cp3entry:1` at `SurfaceCellTransitionQuotientTests.cpp:2916` (selected zero face gauges). `cp3entry:2` at `:3154` remains independently owned by the E2 Review.
- Rehashed focused30 `1e815443a03c7ef4a1b095e6ea973efa9c74bb0eae4e2f872510c97d057ea1d6`; focused12 `2aa57aac48ac8c41ea86ed459cdd1acd27eb17c8d3dbe1b4ac7b9c54c67374ed`; selector449 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`; frozen TB47 v2 manifest `488a20b658fc18ddf64addacd9f3150b35b68b067fd37ba7b11346db958d5955`. Complete-file hashes are not yet an independent full prefix proof.
- Accepted CP2 491/491; stable 66/17/49 with debt 1; selector497 unpromoted. No new stable event.

## Source-backed diagnoses, pending producer scratch proofs

**442 — source-boundary topology contradiction.** The two-face square's test-created `sourceFaceComponents={0,1}` splits a single four-edge source-boundary cycle across two component IDs; `FieldTransportAtlas.cpp:2164–2208` requires one component per original boundary cycle. Offline edge-incidence enumeration independently confirms this split and observed failure (2,3). Candidate *fixture* revision: same source component `{0,0}`, two `sourceFaceSheets={0,1}` for a region barrier. `FieldTransportAtlas.cpp:2043–2054` still publishes directed transition values at region barriers. **Not authorized** pending native positive and signed-inverse negative probes.

**focused30:12 — A5 compares non-gauge-stripped hard-rail branch rotations.** Test shifts one region's local branches and its source-face gauges together by one quarter turn. A4 accepts the phase front; A5 fails at `RemeshPipeline.cpp:5066–5077` by comparing `to.branchRotation-from.branchRotation` to the route action without subtracting endpoint face gauges. A5 has `endpoint_face_gauge()` at `:4679–4702`, and A6 uses gauge stripping at `:5906–5923`. Isolated Z4 arithmetic audit of 256 combinations: raw difference changes under 192, gauge-stripped difference remains invariant in all 256. **Candidate**, not authorized without native baseline, relabel, and true-transport tamper checks.

**cp3entry:1 — missing independent odd-gauge witness.** Torus producer selection in `SurfaceCellTransitionQuotientTests.cpp:1740–1880` falls back from an absent odd gauge candidate to any reciprocal holonomy, though `:2916` asserts an odd delta in {1,3}. Real TB47 receipt: five A3 candidates, five reciprocal holonomies, **zero** odd gauge pairs; selected c0 has `fromGauge=toGauge=0`. This is an unsatisfied witness precondition. Do **not** weaken the odd assertion or inject a fake A3 fact. Need native producer-authenticated odd witness or explicit owner for the still-unwitnessed obligation.

These three defects must **not** be merged into one presumed causal repair merely because they share the TB47 G grouping.

## Continuation and open obligations

1. Independently probe each proposed change against actual producer/consumer semantics, including tamper negatives, invariance and first-failure locality. Static analysis and Z4 arithmetic are not native scratch C++ results.
2. Freeze exact, probe-backed CB48 hunks and a TB48 manifest only after authority is established; keep E2/cp3entry:2 for its separate Review.
3. Discharge/re-carry prior obligations; update ORIENTATION (currency, §§3/4/7/8), TODO, handoff, tracker and CHANGELOG; check roadmap/lessons/selector manifest. Finish the 18-row mandatory Review closeout, real-history `review_check.py boundary`, and origin synchronization.
4. Do not advance successor until this Review completes. The canonical root `STATUS` remains IN_PROGRESS. Detailed identical investigation is preserved in ChatGPT Library `/Directional/M6_CP3_TB47_Gauge_Cluster_Working_Review_20261027.md`.

**No exact patch or successor frozen. No CP3 acceptance.**
