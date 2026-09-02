# M3-CP4c-3-TB9 — Artifact-Only Test + Benchmark Report

**Turn:** `M3-CP4c-3-TB9`
**Date:** 2026-09-02 UTC
**Verdict:** **COMPLETE / VALID SEMANTIC RED / FIRST RED ORDINAL 366 / TERMINAL-OWNERSHIP SITE DISCRIMINATED**
**Next turn:** independent `M3-CP4c-3-TB9-REV` REVIEW + PLAN under
`Architecture_M3_CP4c3_TB9_Independent_Review_Plan.md`. No unchanged TB retry, semantic correction, rebuild,
repackage, or acceptance attempt is authorized before review.

## 1. Immutable authority and orchestration

TB9 consumed only immutable package **79** built from semantic source
`803300698289e0d0f629eaa878add1aebc7193c1`.

- authoritative compile run/job: `33573956609 / 100073749252`;
- compile result artifact: `9825961944`, Actions SHA-256
  `d3e8a50d880e4f8f5179718b7c91288a50b6755e8ec0d6d94e29c3da1ead3b99`;
- package run/job: `33574167362 / 100074416093`;
- package artifact: `9826005253`, Actions SHA-256
  `1f9c6e1d098a08eb375d415f2724185043de1c1d5d08cdce46cc716d57e3fa8a`;
- inner `package79.tar.gz` SHA-256:
  `dfc197b50ea5b9b88468aa00665470af5aa0e2959de9c380fcd6aebdb978ec99`;
- packaged source archive SHA-256:
  `61107e4fc90368793ebe97c3581cea6cb301effc74c6f39cc3259316066aa0f6`;
- selector 374 SHA-256:
  `d496ce96b3776269cda8086a0a2173ce9a1f9967d81b2a80866266155c503c4f`;
- selector 375 SHA-256:
  `aa7b22bb265f321fad6f85128e572e0251dc5f60d68856ca7ec4323006a8f3a0`;
- execution selector 376 SHA-256:
  `6ab2d9fad0327e00bb2f782741afffe8a0ae08c08df8adbdf9accc6234bfa5e8`;
- authoritative TB9 run/job: **`33575920177 / 100079784804`**;
- result artifact: **`9826689980`**, Actions SHA-256
  **`abea3172c6515bbf5b6fdede5abe96ae6086724299d014201ce3ff020016b68d`**;
- log artifact: **`9826690247`**, Actions SHA-256
  **`c92be7d59ecfb963eb225099737ed99efcb169244bfaa4c9519a1a98967cd648`**.

The caller schema validator passed before the TB9 runtime job. Immutable preflight then re-proved the package/source
hashes, internal manifest, clean source records, GMP/GMPXX authority, 27 fixture files, six executable-mode test
binaries, selector cardinality/uniqueness/prefix continuity, and static one-owner mapping for all 376 selector
identities. The package census contained 58 files. No configure, compile, relink, package repair, generated discovery,
product/test/fixture/selector mutation, or benchmark occurred.

## 2. Ordered semantic frontier

TB9 executed selector 376 authority from ordinal 1, one exact identity per fresh process. Every exact filter selected
exactly one test. Identity 376 remained diagnostic/zero-credit as frozen by BB6/BB9.

- ordinals **1–365: 365/365 PASS**;
- ordinal **366: RED**;
- identity: `GlobalTopologyPlan.MechanicalFeatureWitnessDerivesRegionsThroughProductionEntryPath`;
- target: `directional_surface_cell_producer_tests`;
- exit code: `1`.

The production-rendered failure is:

```
NotProductionReady/field-aligned-network;
detailCode=InvalidNetworkTerminalOwnership;
sourceEdge=36-38;sourceFace=36,38,39;branch=2;
networkErrorCondition=SingularityTerminationPortOwnershipMismatch;
traceSeedVertex=47;traceSeedSingularity=5;
traceHistoryCount=5;traceHistoryTruncated=false;
traceHistory=[
  {sourceFace=45,46,47,branch=2,incomingCarrier=none,entryParameter=1/1},
  {sourceFace=43,44,45,branch=2,incomingCarrier=none,entryParameter=1/1},
  {sourceFace=41,42,43,branch=2,incomingCarrier=none,entryParameter=1/1},
  {sourceFace=39,40,41,branch=2,incomingCarrier=none,entryParameter=1/1},
  {sourceFace=36,38,39,branch=2,incomingCarrier=none,entryParameter=1/1}
]
```

The line contains **exactly one** typed terminal-ownership condition. It therefore resolves TB8's proved two-site
ambiguity to the singularity-termination ownership site in `append_field_aligned_singularity_termination`; it is
**not** the `finalize_field_aligned_events` contact/loop-closure fall-through. The trace provenance identifies seed
vertex 47 / singularity 5 and a five-step, untruncated branch-2 path ending at the unchanged edge/face locus.

`publishedFaceCount` is no longer rendered. No `publishedFaces` token is present at this failure, so under CB11's
honest sparse renderer the actual published-face collection is empty rather than an unassigned constant. This
satisfies the BB9 honesty discriminator without converting absence into a fabricated count.

Accepted semantic authority remains **365/365**. The mechanical path still stops before the previously frozen
vertex-30 owner election, so TB9 does not accept the row-209/row-208 condition and row 41 remains prohibited.

## 3. BB9 discriminator disposition

All five frozen BB9 observations are satisfied:

1. **PASS:** ordinals 1–365 remain 365/365 green.
2. **PASS:** ordinal 366 retains `InvalidNetworkTerminalOwnership` at `sourceEdge=36-38`,
   `sourceFace=36,38,39`, `branch=2`.
3. **PASS:** exactly one typed condition is present — `SingularityTerminationPortOwnershipMismatch`, selecting the
   singularity-termination ownership site and excluding the finalize/contact site for this failure.
4. **PASS:** the same production-rendered line carries `traceSeedVertex=47`, `traceSeedSingularity=5`, five exact
   history rows, and `traceHistoryTruncated=false`.
5. **PASS:** the misleading constant `publishedFaceCount` is gone; the sparse renderer publishes no `publishedFaces`
   token because the actual collection is empty.

Diagnostic insufficiency at the **emission-site** level is therefore resolved. TB9 does not decide which internal
subcondition of the singularity-port ownership guard is semantically wrong; that classification belongs to
`M3-CP4c-3-TB9-REV`.

## 4. Full report-only remainder and diagnostic 376 — zero gate credit

After gate credit fixed at ordinal 366, TB9 executed ordinals **367–375** once each in fresh processes with zero gate
credit: **2 PASS / 7 RED**. Diagnostic identity **376** then executed once in a fresh process and **PASSed**, also with
zero gate credit.

| Ordinal | Result | Runtime disposition |
|---|---|---|
| 367 | RED | blocked by the same `SingularityTerminationPortOwnershipMismatch` mechanical locus; no independent face-walk conclusion |
| 368 | RED | unchanged prescribed-sphere `RotationSystemInconsistent → TraceEventPositionInvalid`, trace 2/event 30, `NoCarrierMatch / SourceEdgeUnavailable` |
| 369 | RED | unchanged quality/coverage result: `certificate.saturationUsed=true` |
| 370 | RED | unchanged genuine empty-network contract red: actual `CellularityNotEstablished`, expected `EmptyNetworkOnClosedSurface`, source-face locus absent |
| 371 | RED | blocked by the same mechanical singularity-terminal ownership locus |
| 372 | RED | blocked by the same mechanical singularity-terminal ownership locus |
| 373 | PASS | synthetic barrier-arc singularity binding only; mechanical zero-unbound proof remains owed |
| 374 | RED | unchanged pre-classified folded-cone witness precondition; stops at `atlasBuild=false` before owner/fallback measurement |
| 375 | PASS | exact radial-arrival correction remains green |
| 376 | PASS | production terminal-ownership conditions and trace-scoped projection survive the production failure renderer |

No report-only result receives gate credit. The sphere, saturation, ordinal-370, folded-cone, exact-fallback/budget,
mechanical zero-unbound, and vertex-30 dispositions remain independently owned.

## 5. Regression and candidate disposition

TB9 loses no accepted-green behavior, so stable accounting changes by **+0 events / +0 recurrences** and remains:

- **44 events / 14 categories / 30 recurrences**;
- produced-witness debt **5**;
- authoritative semantic M3 package count **76**.

Candidate disposition:

- `M3-CP4c3-TB8-CAND-01`: remains **ACTIVE / GATING / NON-STABLE**, but its emission site is now runtime-discriminated
  to `SingularityTerminationPortOwnershipMismatch`. Owner advances to independent `M3-CP4c-3-TB9-REV` for exact
  guard-disjunct/root-cause classification and one bounded corrective plan.
- `M3-CP4c3-TB8-REV-CAND-01`: advances **CLOSED / RUNTIME PROVED**. Ordinal 366 now carries the typed condition and
  trace provenance through the production renderer, and diagnostic 376 passes.
- `M3-CP4c3-TB6-CAND-01`: remains **ACTIVE**; vertex 30 is still unreached.
- `M3-CP4c3-DEFN-R2-CAND-01`: remains **ACTIVE**; ordinal 374 still fails before the general non-flat
  exact-fallback/budget discriminator.
- `M3-CP4c3-TB7-CAND-02`: remains **ACTIVE / DEFERRED / PRE-CLASSIFIED WITNESS PRECONDITION**.
- the prescribed-sphere, saturation, ordinal-370, and mechanical singularity-binding candidates retain their prior
  dispositions unchanged.

No new stable regression is created merely because CB11 made the owner site observable on an unaccepted CP4c-3
surface.

## 6. Immutable postflight

Postflight is **PASS**. TB9 reverified package SHA256SUMS, packaged source digest, source commit, GMP/GMPXX evidence,
selector 374/375/376 hashes and prefix relations, executable modes, and the full package-tree byte/mode census. The
58-file preflight and postflight censuses are byte-identical.

Final control state:

- `runtimeExecution=true`;
- `configureExecution=false`;
- `compileExecution=false`;
- `relinkExecution=false`;
- `packageRepair=false`;
- `generatedDiscovery=false`;
- `productMutation=false`;
- `testMutation=false`;
- `fixtureMutation=false`;
- `selectorMutation=false`;
- `benchmarkExecution=false`.

Package 79 remained immutable throughout authorized runtime.

## 7. Stop decision

TB9 is a **valid semantic red** under the frozen stop rule. CP4c-3 remains **OPEN**, accepted authority remains
**365/365**, and no unchanged TB retry is permitted.

Exact successor is independent **`M3-CP4c-3-TB9-REV`** REVIEW + PLAN. That review must reconstruct the named
`SingularityTerminationPortOwnershipMismatch` site, determine which exact ownership invariant/subcondition fired and
who owns it, preserve independently owned report-only debt, reconcile accounting/candidates, and freeze exactly one
bounded successor. TB9 itself authorizes no product correction.
