# M3-CP4c-3-TB46-R1 Independent Review Record

**Status:** COMPLETE / APPROVED WITH AMENDMENTS / PACKAGE111 PROMOTED / ORDINAL367 TEST-AUTHORITY RECURRENCE / CB53 FROZEN
**Turn:** `M3-CP4c-3-TB46-R1-REV`
**Boundary:** independent REVIEW + PLAN; evidence/static only
**Date:** 2026-09-09
**Runtime evidence reviewed:** TB46-R1 run/job `34382143529 / 102569425154`
**Immutable evidence source:** `4f0663ef3468996abce6f59109f1c67f5be5f604`, package111 artifact `10112532452`, selector409

## 1. Decision

**Decision: `approved_with_amendments`.**

TB46-R1 is mechanically valid and is promoted as the current semantic runtime authority:

- **403 PASS / 6 RED / 0 SKIP**;
- accepted prefix **365/365 PASS**;
- RED `[367,368,369,370,374,398]`;
- all 409 selector identities executed exactly once in fresh processes;
- zero selection mismatches and zero timeouts;
- package/source/execution-view byte+mode censuses equal before and after execution;
- no configure, compile, relink, discovery, repair, mutation, or benchmark path executed.

The amendment is to EXEC's proposed evidence requirement for ordinal367. The retained runtime detail does not name the
failing face/count pair, but that extra witness is **not required to decide the governing rule**. Frozen normative
authority already proves that the test's two-sided cardinality equality is invalid.

## 2. Ordinal367 — root cause is a stale independent-oracle invariant, not a product regression

TB46-R1 reaches `independent_fragment_partition()` and fails at `FragmentCountRule`, after CB51's corrected terminal
separation rule. Static source review shows the independent helper:

1. independently derives face-walk orbit IDs;
2. retains a final no-barrier segment when its independently derived forward/reverse orbit IDs differ;
3. stores `fragmentOrbits[face]` as a **set of distinct global face-walk owners**;
4. counts local `tracePieces[face]`;
5. then rejects unless `fragmentOrbits[face].size() == tracePieces[face] + 1`.

That final equality is obsolete. `M3_CP4c_Frozen_Definitions.md` DEFN-R3.4 already records the measured counterexample
that destroys the injectivity premise: distinct local fragments may map to the same global face-walk owner. The
authoritative rule was deliberately relaxed to the one-sided prohibition:

`distinctGlobalOwnerCount <= localTracePieceCount + 1`.

Product `GlobalTopologyPlan.cpp` implements that rule by rejecting only an **over-count**. DEFN-R4.1 separately
states that `(face, orbit)` is an ownership map, not fragment identity, and therefore need not distinguish local
fragments that share one owner. `LESSONS.md` lesson 96 records the general defect pattern: counting a local quantity
with a global identifier silently assumes injectivity.

Therefore `M3-CP4c3-TB46-R1-EXEC-CAND-01` is:

**CLOSED / TEST-AUTHORITY STALE TWO-SIDED CARDINALITY / DEFN-R3.4 VIOLATION / INCORRECT EXPECTATION / NON-STABLE / CB53.**

The missing current face/count pair would be useful diagnostic detail, but it cannot change the normative
adjudication. If the current independent count is low, the equality is a false rejection; if it is high, the
one-sided guard still rejects it. CB53 can therefore correct the generalized oracle without guessing the current
cardinalities.

## 3. Protected Part XII recovery — runtime proved on the successful-plan subject

Ordinals 390/393/406/407 all recover to PASS on package111. Each retained receipt proves:

- `branch=UncutCensus`;
- `censusPredicateExecuted=yes`;
- `sameDomainCorruptionRejected=yes`;
- `terminalSubjectRelation=NotApplicable`;
- `terminalSubjectBranch=PlanFrontier`;
- `planFrontierEvidenceBranchExecuted=yes`.

The supporting BW3, owner-map, partition-correspondence and interior-arc rows are non-empty. This is the requested
runtime proof that CB51's successful-plan producer-frontier evidence is observable and that the real Part XII
predicate plus same-domain negative execute non-vacuously.

The TB45 transition candidate is therefore fully discharged:

**`M3-CP4c3-TB45-EXEC-CAND-02` — CLOSED / RUNTIME-PROVED SUCCESS-PATH OBSERVABILITY / NON-STABLE.**

No stable repricing is justified: this is recovery of an already required protected evidence contract, not a new
accepted behavior.

## 4. Carried REDs and controls

The five other REDs retain their existing independent owners without merge or repricing:

- 368 — prescribed sphere `TraceEventPositionInvalid`, trace 2/event 30, `NoCarrierMatch / SourceEdgeUnavailable`;
- 369 — ordinary-proposal identity still observes `saturationUsed=true`;
- 370 — empty closed network still returns `CellularityNotEstablished` instead of `EmptyNetworkOnClosedSurface`;
- 374 — folded-cone witness still stops at `atlasBuild=false`;
- 398 — prescribed-sphere cut graph remains absent at `NotProductionReady/CellularityNotEstablished`.

Controls 311/312/314/315/356/357/404/408/409 remain PASS. Ownership remains
**300 established / 0 unavailable / 0 conflicting**. Retired-code silence holds.

## 5. Promotion and accounting

Package111/TB46-R1 is promoted because the artifact-only execution is mechanically valid, preserves every accepted
identity, proves the intended protected success-path recovery, and leaves only five carried REDs plus one
normatively identified stale test-oracle rejection above the accepted boundary.

Stable accounting remains **47 events / 14 categories / 33 recurrences**; produced-witness debt remains **5**;
ownership remains **300/0/0**; accepted package count remains **111**. Ordinal367 is a recurrence of the already
disproved local-fragment/global-owner injectivity assumption and adds **+0 stable events / +0 recurrences**.

TB45/package110 is superseded as current runtime authority by TB46-R1/package111. It remains historical evidence.

## 6. Review of the proposed correction

The smallest generalized correction is test-only and surgical:

- edit only `tests/FieldAlignedCurveNetworkTests.cpp`;
- in `independent_fragment_partition()`, replace the two-sided rejection
  `distinctOwnerCount != tracePieces + 1` with the normative over-count rejection
  `distinctOwnerCount > tracePieces + 1`;
- preserve the helper's independent face-walk derivation and CB51 terminal-separation rule;
- preserve non-empty ownership, edge evidence, exterior handling, component-seed logic and `facesByOrbit`;
- do not query product-owned fragment partitions or other product-derived oracle authority;
- do not change product source, fixtures, selectors, carried RED expectations or frozen definitions.

This correction addresses the root cause, not the current symptom, and preserves the meaningful high-side falsifier.

## 7. Document consolidation

Mandatory REVIEW consolidation folds **8 live superseded documents / 1,040 lines** into
`M3_CP4c_Consolidated_Record.md`. Two plans retired between reviews are retrospectively indexed there as
accounting-neutral history: CB51's 157-line plan and CB52's 67-line plan. Exact bytes remain recoverable from git
history.

After consolidation, the retained current per-turn roles are:

- `Architecture_M3_CP4c3_TB46_R1_EXEC_Report.md` — current runtime report;
- `Architecture_M3_CP4c3_TB46_R1_Independent_Review_Record.md` — current review authority;
- `Architecture_M3_CP4c3_CB53_Independent_Fragment_Count_Oracle_Code_Build_Plan.md` — single exact next plan.

Selectors, frozen definitions, policies and durable family records remain untouched.

## 8. Exact successor

**`M3-CP4c-3-CB53` — Code + Build / runtime-free**, under
`Architecture_M3_CP4c3_CB53_Independent_Fragment_Count_Oracle_Code_Build_Plan.md`.

No new runtime is authorized in this review.
