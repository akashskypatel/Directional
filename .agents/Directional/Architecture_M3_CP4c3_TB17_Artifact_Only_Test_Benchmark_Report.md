# M3 CP4c-3 TB17 — Artifact-Only Test + Benchmark Report

Date: 2026-09-03 UTC
Turn: `M3-CP4c-3-TB17`
Status: **COMPLETE / VALID SEMANTIC RED / ACCEPTED PREFIX SAFE / CB19 BRANCH MOVEMENT PROVED / NON-STABLE**

## Authority and immutable envelope

TB17 executed the frozen selector **382** from ordinal 1, one identity per fresh process, plus the retained non-gating mechanical diagnostic, using immutable package **87** only. No configure, compile, relink, package repair, generated discovery, source/test/fixture/selector mutation, package mutation, or benchmark execution occurred.

- semantic source: **`bf971a6c9ad55e9c06c58f9fc73e9112808e5a1e`**;
- package 87 source/build authority: run/job `33763450567 / 100675268847`, artifact **`9896472535`**;
- package artifact digest: **`78d1ac33c9db7592a8a852fafe91d0cabd0548ca5cf6309ceb50f689da9d9770`**;
- inner package tar SHA-256: **`015c1113e2237e779076e397f4907b8a44f101ce159e566ff482f9c598f51c48`**;
- packaged source archive SHA-256: **`f54461f5cba89fdd8d54ad2a43d8476a1785676419535eaa21e1556e3e9b538a`**;
- selector 382 SHA-256: **`f30d5d5625682d928a4878e0139e6b04c9e9082f58e8a545c49c8a350d665a1a`**;
- frozen prefixes: 381 `af667aae37dc6c2342c8f084b4c7ff97719798d76bce5cbb34163afecdd38d90`, 380 `1a95d32852507441c10c0c81154a595ebc367fe4137143ec9290d85d852a0e4e`, accepted 365 `6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1`;
- TB17 orchestration event SHA: `d35d04a377af92433b9bb1b690021d1cb5a083ea` — control plane only, not semantic source;
- run/execute job: **`33770523736 / 100699356052`**;
- result artifact: **`9899516228`**, Actions digest **`c03480f525e6125367c360c851ba374c59dc32180044efd49e40938368509f0f`**;
- diagnostic-log artifact: **`9899516703`**, Actions digest **`f4933482c6b5ec943edf258356157dabd2a5d69de8dfd64a6c893c89344a9bda`**;
- exact result-ledger SHA-256: **`7c4464134a7be19150094bbee874ebe99878c3eaa004908d3660c1ffaa36b6fd`**;
- package pre/post byte+mode census SHA-256: **`0438202b4717c69610374c640c2e7970ce38580b816935a8093e98253dbcd518`**; pre/post census is byte-identical.

The result-ledger hash happens to equal TB16's corrected ledger because the same eight identity ordinals remain RED and all other selector rows remain PASS. That does **not** mean the semantic failure surface is unchanged: ordinal 366 moved downstream as described below.

## Gate result

Selector **382** completed all 382 exact identities organically:

- **374 PASS / 8 RED**;
- accepted ordinals **1–365: 365/365 PASS**;
- RED ordinals: **366, 367, 368, 369, 370, 371, 372, 374**;
- first semantic red: **366**;
- ordinal 373 and ordinals 375–382: **PASS**;
- retained non-gating `GlobalTopologyPlan.MechanicalWitnessStageReachabilityIsObservable`: **RED**, exit 1, zero gate credit.

The run itself completed successfully. `runtimeExecution=true`; every forbidden mutation/build/repair/benchmark flag remained false; postflight package bytes and executable modes were identical.

## CB19 discriminator result — old source-port failure cleared, next region frontier exposed

Ordinal 366 no longer reports TB16's `RegionTraceSourcePortCarrierNotAdmissible` at face `(9,11,17)`. It now reaches the fragment-count validation in `GlobalTopologyPlan` and fails:

`NotProductionReady/global-topology-plan/TraceCutFaceFragmentCountMismatch; sourceFace=(0,1,102); cutCandidateCount=0`.

The production failure also carries the independent trace-segment contract observation introduced by CB19:

- `nonFirstCarrierless=48`;
- `nonFirstCarrierlessDistinctOrigin=48`;
- `terminalSlits=10`;
- positive later carrier-less witness: `trace=0, segment=1, sourceFace=9-11-17, traceOrigin=10, entryCorner=11, provenance=SegmentEntrySupport, forwardEvidenceEdge=9-11, reverseEvidenceEdge=11-17`;
- terminal-slit witness: `trace=0, segment=4, sourceFace=28-29-35, outgoing=28-35, realChordContribution=0`.

This is runtime evidence that CB19 reached the intended segment-local binding semantics and that the independent BR6 boundary observation recognizes terminal slits as zero real-chord contribution. The prior source-port branch/locus is cleared. The mechanical plan still does not publish because the next face-level fragment invariant rejects.

Ordinals 367, 371 and 372 clear the prior `(9,11,17)` source-port stop with 366 and now inherit the same downstream `TraceCutFaceFragmentCountMismatch` at `(0,1,102)`.

The retained non-gating mechanical diagnostic independently reports `surfaceCutGraph=true`, `networkAlreadyCellular=true`, cut edge count 0, `globalTopologyPlan=false`, `planError=TraceCutFaceFragmentCountMismatch`, and `sourceFace=0-1-102`.

## BR9 discriminator disposition

1. **PASS — branch/locus moved.** The old ordinal-366 `RegionTraceSourcePortCarrierNotAdmissible` at `(9,11,17)` is gone. The first red is now `TraceCutFaceFragmentCountMismatch` at `(0,1,102)`.
2. **FAIL / insufficient diagnostic — next region failure is still face-only.** The new fragment-count rejection publishes `sourceFace` but not the actual fragment-orbit cardinality, expected `tracePieceCount+1`, contributing trace segments/arcs, their oriented face-walk orbits, or the per-face edge-orbit evidence. BR9 required the next region failure not to collapse back to a bare face locus. No such missing values are guessed here.
3. **PASS — accepted boundary.** Ordinals 1–365 remain **365/365 green**.
4. **PASS — inherited mechanical source-port surface cleared together.** 367/371/372 move with 366 past the former source-port rejection and co-fail only at the new downstream face-fragment invariant; none retains the old `(9,11,17)` branch.
5. **PASS — independent carried surfaces unchanged.** 368 remains prescribed-sphere `RotationSystemInconsistent -> TraceEventPositionInvalid`, trace 2/event 30, `NoCarrierMatch / SourceEdgeUnavailable`; 369 remains `saturationUsed=true` where the identity expects ordinary proposal without saturation; 370 remains actual `CellularityNotEstablished` with no source-face locus instead of `EmptyNetworkOnClosedSurface`; 374 remains the pre-classified folded-cone `atlasBuild=false` fixture surface.
6. **PASS — BR6 boundary observation.** The independently reconstructed network contract reports ten terminal slits and retains a concrete terminal witness with `realChordContribution=0`, while also proving non-first carrier-less segments with entry support distinct from trace origin. The mechanical plan fails later, so the post-success `m3Cp4c3BR6` line is not reached; the pre-failure independent observation itself is retained in the typed production failure envelope.
7. **PASS — immutable envelope.** Package byte+mode census is identical and all configure/compile/relink/repair/discovery/mutation/benchmark flags are false.

## New frontier and required review question

`M3-CP4c3-TB17-CAND-01` owns the new gating surface provisionally. Static package source localizes its sole emitter to the direct-cut-face validation in `build_regions`: for each face with recorded fragment orbits it computes `expected = tracePieceCount[face] + 1` and rejects when the **set of global face-walk orbit IDs** has a different cardinality.

TB17 does **not** retain enough runtime incidence to adjudicate why face `(0,1,102)` violates that equation. In particular, the failure omits actual/expected counts, the real trace segments in that face, arc/orientation/range, forward/reverse orbit IDs, and edge-orbit evidence. The independent review must therefore decide whether:

- the local `k real chords -> k+1 local fragments` geometry is correct but the implementation is counting/deduplicating global face-walk orbit owners incorrectly;
- repeated segments/arcs or shared global region orbits make `fragmentOrbits.size()` the wrong quantity for a local-fragment cardinality assertion;
- one of the two reconciled loops still assigns inconsistent orbit evidence despite agreeing on terminal-slit and carrier-less semantics; or
- the witness exposes a different product/authority defect.

No semantic correction is authorized from TB17 alone. If static review cannot recover the missing face incidence from retained immutable evidence, the next Code + Build must be diagnostic-only and must publish those exact counts/incidences before any product fix is prescribed.

## Process evidence

The turn initially began repository document inspection before the mandatory `READ_MODE` gate had been explicitly frozen. On recognizing the miss, piecemeal inspection stopped, the turn switched to **`READ_MODE=snapshot`**, one exact source snapshot was materialized, and all subsequent static/source analysis reused that local snapshot/package materialization. This process-policy miss does not alter package 87, selector execution, per-process exit codes, or TB17 semantic evidence; it is retained here rather than normalized away.

The packaged `tools/review_check.py authority bf971a6c...` helper was also attempted locally, but the packaged source archive intentionally has no `.git`, so the helper terminated with `fatal: not a git repository`. Package/source authority was independently established from the immutable package metadata, source-archive hash, selector hashes, and workflow artifact identity. No runtime was rerun for this helper limitation.

## Status and exact successor

`M3-CP4c-3-TB17` is **COMPLETE / VALID SEMANTIC RED / ACCEPTED PREFIX SAFE / NON-STABLE**. CP4c-3 remains **OPEN**. Accepted authority remains **365/365**. Stable accounting remains **44 events / 14 categories / 30 recurrences**; produced-witness debt **5**; semantic M3 package count **84**.

Exact successor: **`M3-CP4c-3-TB17-REV` — independent REVIEW + PLAN only**, under `Architecture_M3_CP4c3_TB17_Independent_Review_Plan.md`. Do not rerun TB17 and do not begin another Code + Build before that review adjudicates `TraceCutFaceFragmentCountMismatch`.
