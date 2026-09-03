# M3 CP4c-3 TB17 — Independent Review + Plan

Date: 2026-09-03 UTC
Turn: `M3-CP4c-3-TB17-REV`
Status: **FROZEN SUCCESSOR / INDEPENDENT REVIEW + PLAN ONLY / NOT EXECUTED**

## Authority

Review the completed immutable package-87 TB17 evidence; do not rerun any identity:

- semantic/package source **`bf971a6c9ad55e9c06c58f9fc73e9112808e5a1e`**;
- immutable package **87** artifact `9896472535`, Actions SHA-256 `78d1ac33c9db7592a8a852fafe91d0cabd0548ca5cf6309ceb50f689da9d9770`, inner tar `015c1113e2237e779076e397f4907b8a44f101ce159e566ff482f9c598f51c48`, packaged source `f54461f5cba89fdd8d54ad2a43d8476a1785676419535eaa21e1556e3e9b538a`;
- selector **382** SHA-256 `f30d5d5625682d928a4878e0139e6b04c9e9082f58e8a545c49c8a350d665a1a`, accepted prefix 365 `6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1`;
- run/job **`33770523736 / 100699356052`**;
- result/log artifacts **`9899516228 / 9899516703`**, Actions SHA-256 `c03480f525e6125367c360c851ba374c59dc32180044efd49e40938368509f0f` / `f4933482c6b5ec943edf258356157dabd2a5d69de8dfd64a6c893c89344a9bda`;
- exact ledger SHA-256 **`7c4464134a7be19150094bbee874ebe99878c3eaa004908d3660c1ffaa36b6fd`**: **374 PASS / 8 RED**, accepted 1–365 **365/365 PASS**, first red 366;
- package pre/post byte+mode census SHA-256 **`0438202b4717c69610374c640c2e7970ce38580b816935a8093e98253dbcd518`**, identical;
- ordinal 366 failure: `TraceCutFaceFragmentCountMismatch`, source face **`(0,1,102)`**, after the TB16 `(9,11,17)` source-port failure cleared.

No semantic rerun is authorized in this review.

## Objective

Adjudicate the new face-fragment cardinality frontier without assuming that the stated geometric rule `k real chords -> k+1 local fragments` is equivalent to the implementation's cardinality of **distinct global face-walk orbit IDs**. Recover the exact semantics and evidence ownership of face `(0,1,102)`, decide whether the defect is in local-fragment counting, orbit-owner projection, trace/arc incidence, or witness authority, preserve all settled CB19/TB17 results, then freeze exactly one bounded successor.

## Required measures — BRQ0–BRQ8

### BRQ0 — Re-establish immutable evidence authority

Verify package/source/selector identity, 374/8 ledger, accepted 365/365, red set 366/367/368/369/370/371/372/374, non-gating diagnostic RED, and identical postflight. Confirm that the TB17 control-plane runner/workflow and the recorded `READ_MODE` process miss cannot alter package bytes, selector membership/order, fresh-process execution, or per-identity exit codes. Do not rerun.

### BRQ1 — Preserve the CB19 facts that TB17 actually proved

Treat the following as settled unless immutable evidence contradicts them: the old `RegionTraceSourcePortCarrierNotAdmissible` at `(9,11,17)` is cleared; the independent network observation finds **48** non-first carrier-less segments, all **48** with entry support distinct from trace origin; the positive witness uses `SegmentEntrySupport`; there are **10** terminal slits; and the retained terminal witness has `realChordContribution=0`. Do not reopen the corrected source-port datum or terminal-slit classification merely because a later invariant now fails.

### BRQ2 — Prove the exact `TraceCutFaceFragmentCountMismatch` control path

Trace the sole emitter and every prerequisite required to reach it. Establish what `tracePieceCount`, `fragmentOrbits`, `exteriorOrbits`, forward/reverse dart orbits, cut/mandatory evidence and terminal-slit skipping mean at that point. Distinguish the **local geometric fragment count** from the **set of global region/face-walk orbit owners** used by the implementation.

### BRQ3 — Reconstruct face `(0,1,102)` to the limit of retained evidence

Determine, without guessing, every recoverable datum for the failing face: actual `fragmentOrbits.size()`, expected `tracePieceCount+1`, all real trace segments in the face, trace/arc IDs and segment ranges, orientation, incoming/outgoing carriers, forward/reverse orbit IDs, repeated orbit ownership, and edge-orbit evidence. If TB17 did not retain a required value and committed source/fixtures cannot establish it statically, name the missing datum explicitly.

### BRQ4 — Adjudicate the fragment invariant, not just its symptom

Prove or falsify the assumption that every real chord in one source triangle must add one **distinct global face-walk orbit ID**. Consider repeated visits by one arc, several chords separating the same globally connected region, local fragments that may share one global owner, and duplicated/inconsistent orbit evidence. Do not weaken the geometric `k+1` statement merely to make the test pass; instead identify the correct representation and invariant for local fragments versus global region ownership.

### BRQ5 — Audit both reconciled CB19 loops at the new face

Compare `build_fragment_corner_incidence` and `build_regions` for face `(0,1,102)` after the shared terminal-slit and carrier-less-binding changes. Determine whether both loops now classify exactly the same material segments and, if so, whether they derive equivalent fragment/orbit evidence. If they diverge, localize the first semantic divergence. If they agree, move ownership to the shared invariant/representation rather than inventing another copied-loop fix.

### BRQ6 — Classify the owner before prescribing a correction

Choose exactly one supported class: product local-fragment/orbit representation defect; product trace/arc incidence defect; upstream network/provenance defect; witness/test-precondition defect; or insufficient evidence requiring diagnostic-only instrumentation. Because TB17's new error publishes only `sourceFace`, **diagnostic-only is mandatory unless BRQ2–BRQ5 statically prove the semantic owner and corrective contract without the omitted counts/incidences**.

### BRQ7 — Keep independent carried surfaces independently owned

Preserve accepted 365/365 and the unchanged surfaces: prescribed sphere 368 `TraceEventPositionInvalid / NoCarrierMatch / SourceEdgeUnavailable`; saturation 369; empty-network 370; folded-cone 374. Treat 367/371/372 as co-reachers of the mechanical fragment stop, not independent evidence for the new owner unless their retained logs differ. Preserve PASS ordinals 373 and 375–382, including the BR5/diagnostic-projection witnesses. No vertex-30 or finalize/contact work is imported.

### BRQ8 — Freeze exactly one bounded successor

Issue one successor with explicit owner, permitted mutation surface, focused witness/diagnostic obligations, accepted-prefix preservation, compile/runtime boundary, and next-TB discriminators. A semantic red follows `REVIEW + PLAN -> CB`; however, if BRQ6 finds missing runtime incidence rather than a statically proved correction, freeze a **diagnostic-only Code + Build** that adds the minimum typed fragment-count evidence and no semantic behavior change. Do not execute the successor during this review turn.

## Exit gate

The review completes only when face `(0,1,102)` is reconstructed to the limit of immutable evidence, local fragments are semantically separated from global face-walk orbit ownership, CB19's settled branch movement/terminal-slit facts remain preserved, independent carried surfaces remain separate, unknowns are explicit, and exactly one bounded successor is frozen. No runtime, benchmark, compile, package, or product/test/fixture/selector mutation occurs in `M3-CP4c-3-TB17-REV`.
