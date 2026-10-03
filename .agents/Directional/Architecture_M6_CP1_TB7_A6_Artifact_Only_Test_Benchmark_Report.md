# `M6-CP1-TB7-A6-EXEC` — Artifact-Only Test + Benchmark Report

## Disposition

**COMPLETE / MECHANICALLY VALID SEMANTIC RED / REVIEW REQUIRED / CANDIDATE UNPROMOTED.**

- Candidate package/source: `11257522199 / 40842caa88f8d7a08a38c91273ace77ebd7c0676`.
- Runtime run/job: `37090507571 / 111109661723` — workflow/job success; artifact-only harness completed without orchestration failure.
- Result artifact: `11262587435`, provider digest `sha256:87cfcda2502f10cfc74e04aecd6e32aaca629928dff966988f52751f59e44575`.
- Log artifact: `11262387973`, provider digest `sha256:99008db67dd27e673f642ce341dfb93278674b768df709a593de7a77bcdfe92a`.
- Outcome: focused **11/11 PASS**, selector449 **432/449 PASS**, aggregate **443/460 PASS / 17 RED**.
- Exact-one selection: **true**. Zero skips: **true**. Benchmark execution: **0**.
- Stable accounting remains **57 events / 16 categories / 41 recurrences**; project debt remains **1**. EXEC does not reprice history.
- Reviewed runtime authority remains `10879581622 / 82b86a285292379cfd92cdc4e10d74181b38f1e8`, selector449 **449/449**.

This mechanically valid RED is preserved exactly. There was no repair, retry, test/fixture/selector mutation, package mutation, configure, compile, relink, generated discovery or benchmark execution after runtime began. Exact successor is mandatory runtime-free `M6-CP1-TB7-A6-REV`.

## 1. Immutable candidate and preflight authority

The gate consumed the CB7-A6 package immutably:

- package ZIP SHA-256 `bbb18e89f41b959aa82e285c20b543ac9fea9f65fad6a07b0e6cfb1d989f10fd`;
- packaged source archive SHA-256 `2c8981c6da6e9e72b4977f2879a687e2ba1c6c042591bd82720936f69888d27f`;
- root package `SHA256SUMS`: **28/28** before and after runtime;
- selector449: **449 rows**, SHA-256 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`;
- routing449: SHA-256 `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707`, owner census **32 / 301 / 75 / 41**;
- packaged executable modes were preserved; no `chmod`/repair occurred;
- the separate execution view copied packaged-source `benchmarks/fixtures` to adjacent `test-data/benchmarks/fixtures` without altering candidate/source bytes.

Package, packaged-source, execution-view and fixture byte/mode censuses are identical pre/post. The result self-manifest verifies **953/953** entries; its SHA-256 is `5a5abda8a8d51a4b75d2266fb0b34604e3d0d4179e731e48a52be5a18771508a`. Execution-ledger SHA-256 is `fd41e71a538bb817cea5da989daf1e52a033d0a51818593ba03c3b8054bfa39f`; focused ledger `f2a8cd85937258df3bd57767ce88b3b53f4faed826dfd68159e0a9544a30f11c`; selector ledger `ac7883b7c652cdaedd21d19d5ed2867d6de6f11198f1fb9abf25d80efc8404e3`.

The execution boundary records `runtime_started=true`, `runtime_completed=true`, `preflight_completed=true`, `orchestration_failure=false`, `selection_integrity=true`, `total_executed=460`, and all configure/compile/relink/discovery/repair/mutation/retry flags false.

## 2. Exact runtime result and TB6 differential

The 17 selector RED ordinals are:

`115, 116, 122, 130, 132, 134, 137, 141, 143, 150, 176, 201, 217, 227, 230, 231, 446`.

Focused identities 1-11 all PASS. Registered controls/falsifiers:

- focused6 `M5CP3.ProducedTorusPeriodicPairStorageSwapPreservesSemanticDirection`: **PASS**;
- focused10 `M6CP1.QuotientRejectsMissingDuplicateOrConflictingConsumption`: **PASS**;
- focused11 `M6CP1.CycleClosingRelationTransportConflictRejected`: **PASS**;
- selector139 / 140 / 142: **PASS / PASS / PASS**;
- selector232 / 444 / 448 / 449: **PASS / PASS / PASS / PASS**;
- selector446: **RED**, but no longer at `QuotientHolonomyConflict`.

Raw-log census contains **0** `QuotientHolonomyConflict` and **0** `OccurrenceInvalidCornerAuthority`. `InvalidHardRailTransport` occurs 10 times across 9 raw selector logs.

Relative to authoritative TB6-A6 (`456/460` with focused6 + selector139/142/446 RED): focused6, selector139 and selector142 recover to PASS. Selector446 remains RED with a different first failure. Sixteen previously accepted-green selector identities newly turn RED, so the aggregate changes from **456/460** to **443/460**.

## 3. Candidate regression root-cause records

EXEC records three **non-stable / Review-owned** candidate records. These satisfy the mandatory TB regression tracker gate but do not change stable totals.

### `M6-CP1-TB7-A6-EXEC-CAND-01` — HardRail route transport is not placement-gauge authority

**Rows:** direct `InvalidHardRailTransport` on 115/116/141/143/150/217/231; downstream reachability losses on 122/130/132/134/137/176/201. **Candidate category:** existing `RP-01 / AUTHORITY_DOMAIN_CONFLATION`.

CB7-A6 added an A5 requirement that `first.route.composed_transport()` act on the two HardRail endpoints' `LocalLatticeState` placement states. Exact source shows the HardRail route is constructed by `assign_open_front_boundary_authority`, where every retained interior HardRail `TransitionStep` is published with `GridAutomorphism::identity()`. `CanonicalRoute::composed_transport()` therefore composes route-carrier transition transport, not a derived cross-region placement gauge transform. Row141 independently proves the valid pair has common rail ownership and exact reversed routes before materialization, then materialization rejects `InvalidHardRailTransport`. The new failure therefore isolates the added placement-action check rather than the restored owner/region/reversed-route checks.

This is exactly the CB7 stop-rule condition: if HardRail route transport is not in placement gauge, return to Review. No TB repair is authorized. Review must decide the authoritative HardRail placement-gauge derivation (or whether HardRail A6 transport should use a different already-published authority) while preserving rows139/142's recovered reciprocal-route rejection and row140's owner-ID control.

The seven downstream rows share the same hard-feature fixture/stage path and now stop before their established later seams: feature-rail tamper/final-oracle callbacks are not reached, and the RE-package stage-injection tests terminate `NotProductionReady` in `tracing` rather than reaching the requested injected stage. Review owns final grouping/pricing.

### `M6-CP1-TB7-A6-EXEC-CAND-02` — restored A5 reciprocal-route check shadows typed route-authority negatives

**Rows:** 227 and 230. **Candidate category:** existing `VALIDATION_ORDER_SHADOWING`.

Both tests intentionally mutate HardRail route topology and previously reject as `InvalidHardRailAuthority`. CB7's earlier A5 exact reciprocal-route predicate now rejects first as `InvalidHardRailTransport`, before the established route-topology validator reaches its more specific accepted failure contract. The tests still fail closed; the regression is validation precedence / typed-error shadowing, not permissive acceptance. No expectation is changed in TB.

### `M6-CP1-TB7-A6-EXEC-CAND-03` — selector446 still pins the pre-RA-13 transport representation

**Row:** 446 only. **Candidate category:** existing `RP-05 / REPRESENTATION_DEPENDENT_IDENTITY`, test-authority candidate.

The original TB6 `QuotientHolonomyConflict` is recovered: row446 now materializes successfully, focused6 passes, and the raw gate contains zero `QuotientHolonomyConflict`. Row446 instead fails only its post-materialization `selected` assertion, which requires the selected periodic step's `appliedTransport` to equal `SurfacePeriodicHolonomy::action()` or its inverse. RA-13 intentionally changed exact-A3 A5/A6 certificate transport to the **placement gauge** `Γ_to^-1 ∘ g ∘ Γ_from`; `SurfacePeriodicHolonomy::action()` remains the relation-endpoint/stored action. The accepted assertion therefore compares representations from different gauges after the reviewed semantic change.

EXEC does not modify the frozen selector test. Mandatory Review must decide whether this is a test-only expectation migration to the RA-13 placement-gauge authority or evidence of a remaining production contract defect. The mechanically important controls are green: materialization succeeds, focused6 passes, selector232/444/448/449 pass, and zero holonomy conflicts are emitted.

## 4. Regression/accounting disposition

`Regression_Root_Cause_Tracker.md` records all 17 REDs through the three candidate envelopes above. Because this is EXEC, all are **candidate/non-stable** and formal grouping/category/stable-count decisions remain Review-owned. Stable accounting therefore remains **57 / 16 / 41**, project debt **1**.

The candidate package is not promoted. The prior reviewed TB5 authority remains current until Review adjudicates TB7.

## 5. Turn boundary and successor

- Runtime used only the immutable packaged candidate plus a separate derived execution view.
- No generated binary ran outside the 460 exact-filter test processes.
- No configure, compile, relink, discovery, benchmark, repair, selector/fixture mutation or post-runtime retry occurred.
- No same-turn correction is authorized for this semantic RED.

Exact successor: **`M6-CP1-TB7-A6-REV`**. It must independently re-open this result, adjudicate the three candidate envelopes, decide stable accounting/promotion, and authorize any bounded recovery. `M6-DEFN-R4`, A7, `G4-B002`, `G4-B004` representative consumption, and direct-torus debt work remain held.

## 6. Process note

The turn-local tool-call ledger was partially lost across context compaction. Per conservation policy, the exact total is reported as **unknown/partial** rather than reconstructed by extra tool calls. No acceptance claim depends on the missing accounting metric.
