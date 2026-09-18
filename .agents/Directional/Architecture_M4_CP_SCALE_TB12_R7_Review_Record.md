# M4-CP-SCALE-TB12-R7-REV — Independent Review Record

**Turn:** `M4-CP-SCALE-TB12-R7-REV`
**Type:** independent Review + Plan, runtime-free
**Reviewed predecessor:** `M4-CP-SCALE-TB12-R7-EXEC`
**Accepted runtime authority entering Review:** package `10473134357` / semantic source `e15e83c79a1e1962c0ed8d31ea85187ab6600e47` / selector426 **426/426**
**Candidate under review:** artifact `10532133889` / semantic source `079933f2ec31a9323218e73c7ae0d3ea1d11103c`
**Verdict:** R7 is a valid semantic RED. CB18 is falsified at the same R4 ownership seam because it added an unsupported equality between a global source-vertex singularity index and a per-region relative `BoundaryLoop.turningLift`. The defect remains existing `RP-01 / AUTHORITY_DOMAIN_CONFLATION`; S5/A3 remain uncredited; exact successor is `M4-CP-SCALE-CB21`.

## 1. Immutable R7 evidence independently re-opened

Review re-opened the R7 result/log artifacts and the exact CB18 source rather than relying on EXEC prose.

- Authoritative R7 run/job: `35326420329 / 105540445909`.
- Immutable CB18 candidate: artifact `10532133889`, semantic source `079933f2ec31a9323218e73c7ae0d3ea1d11103c`, package SHA-256 `4793e0155349a7f6c1e1a7833f5474d468cae89fcdd40916ec3eca192ff09c3a`, 28/28 root manifest SHA-256 `44fd665474f12d79b916eacb77df9dfc07cf7478503e82a8c1ac7f80c64da5bd`, source archive SHA-256 `2d08714f478e0ac93946b02b3f62ca16c099666b3bf3a6f5c40de9e98fb296ea`.
- Corrected frozen R7 harness: Drive `1Q1h9-W7AKuS1VP-IXJ__v4nqvmiNpNGV`, 18,479 bytes, SHA-256 `04f3e8dd49b5521f5850d4bfc2eea4b8f04b4c4f4ef839974b55cd3b1c7e7cdf`. The R6 nounset orchestration defect is therefore recovery-proved by a full generated-runtime/postflight path.
- R7 result/log artifacts: `10538264057 / 10538428912`, provider SHA-256 `12d79ff15e3990a340ed70021901f2c7f23d52eec9c581d0b09e1e34509e1aa8 / d2890bbd40ba3919c2b234065d30860afb42e27e62637d92c951d6e647ece2e3`.
- Exact ledger: **436** initialized rows = A0 5 + A 4 + S5 1 + selector426 426. Exactly one row executed: A0 row1 `FieldTransportAtlas.SeparatingHardFeatureSingularityOwnsCanonicalBoundaryCycle`; it selected one test, skipped zero, exited `1`, and RED with `code=SingularityMismatch;sourceVertex=8`. Final ledger SHA-256 is `b223e343890ef18a7ab728f59f5945fd83263b603926907e93c70d7b5a0b043a`; the other **435/436** rows are explicit `UNEXECUTED`.
- Execution boundary is semantic, not orchestration: `orchestration_failure=false`, `semantic_red=true`, `postflight_complete=true`, `benchmarkExecuted=0`, and all configure/compile/relink/discovery/repair/mutation flags are zero.
- Package/source/execution-view pre/post censuses are byte-identical: `08b25da4f16092e5ed77a886da51f2346868a6d0e6f35daf687db51bf84f8866`, `d199eacce8b9275de2e56df005f36621aef4eb8b8e64aabbab67e61d10576f50`, and `b9fb5e93b15d6fc4a746202b191f9a9495b948bb57c4552b0c5120bed9b5be04` respectively.

The accepted selector was independently re-hashed from the fresh Review snapshot: selector426 remains **426 LF rows**, SHA-256 `41f4d559211375c11c8d1f8c9ccde2581db75819d9409366e8f2695b008b5114`; exact first425 prefix remains `e0e0f394faae536ac257ec5409653a34755a8afe0ca437562eb44c9895790e0b`; owner census remains **30 / 280 / 75 / 41**. No selector427 exists.

## 2. R7 localizes the failure to CB18 owner eligibility

The R7 diagnostic has `sourceVertex=8` and no topology-region field. In the exact CB18 source, the raw-singularity reconciliation returns that shape at `FieldTransportAtlas.cpp:2541-2544` only when the final owner count is not exactly one.

The direct test independently establishes the relevant preconditions before calling the product:

- vertex 8 is globally interior and lies on the ring-1 hard-feature boundary;
- both hard-feature edges incident to the target split distinct source topology regions;
- `preCb18LocalBarrierEdgeCount == 0`, so the existing same-region slit/barrier owner is inapplicable;
- the raw global field index for vertex 8 is independently reconstructed as `+1` from the source `PCFaceTangentBundle`;
- an incident expected source-topology region is independently derived from the radial transport edge.

The production callback is invoked for every vertex of each local region boundary at `FieldTransportAtlas.cpp:2375-2401`. For a candidate at vertex 8, its `BoundaryLoop` kind and current region are therefore already established by the callback context. CB18 then rejects the candidate at `:2006-2010` unless **`cycle.turningLift == rawSingularity[vertex]`**. Since local/slit ownership is absent and R7 reaches owner-count failure, no separating-feature candidate survived this added equality. The evidence does not require guessing the numerical boundary lift: the failure site plus independently established incidence narrows the rejected predicate to the CB18 cross-domain equality.

## 3. CB18 strengthened the R4 contract with an unsupported cross-domain equality

R4 Review froze a narrower correction contract: a prescribed singularity on a **separating hard-feature boundary** must acquire one deterministic incident-region `BoundaryLoop` owner, publish `BarrierAbsorbed`, and emit zero origin ports. Multiple incident regions must be canonicalized by stable authority IDs. R4 did **not** define a per-region boundary-loop lift as the authority for the global source-vertex singularity index.

CB18 implemented the required incidence map and stable `(TopologyRegionId, FieldCycleId)` minimum, but added two equality checks not justified by that contract:

1. eligibility rejects an otherwise incident separating-boundary owner unless `cycle.turningLift == supplied->second` (`FieldTransportAtlas.cpp:2006-2010`);
2. final separating-owner validation repeats `cycle.turningLift != numerator` as a `SingularityMismatch` condition (`:2555-2566`).

Those checks conflate two distinct quantities:

- `rawSingularity[globalVertex]` is the **global source-vertex field singularity index numerator**;
- `BoundaryLoop.turningLift` is a **per-region relative boundary-cycle quantity**. For a region with boundary, the atlas first sums local boundary-cycle lifts, computes the region-level Gauss-Bonnet/Poincare-Hopf correction `requiredIndexSum - interiorIndexSum - boundaryIndexSum`, and adds that correction to the canonical first boundary loop (`:2348-2367`). Its value can therefore change to close the **region aggregate**, independently of any one source vertex on that loop.

The callback already carries the missing ownership fact directly: the vertex is being visited on that exact local boundary loop and the source-topology incidence map establishes that the region is one of the separating-feature regions for the source vertex. Requiring equality to a region aggregate is neither necessary for ownership nor implied by the accepted `BarrierAbsorbed` contract.

The independent snapshot validator reinforces the distinction. For `BarrierAbsorbed`, `FieldTransportAtlasTests.cpp:1758-1767` requires an explicit topology region, an in-range local cycle, and `FieldCycleKind::BoundaryLoop`; it does **not** equate boundary-loop lift with the singularity numerator.

## 4. The CB18 direct test contains a same-assumption oracle weakness

`SeparatingHardFeatureSingularityOwnsCanonicalBoundaryCycle` is non-vacuous on its source-topology and raw-field preconditions: it derives the separating feature, proves the local slit path is absent, reconstructs the target's global `+1` singularity independently, and derives an incident owner region before product construction.

However, after construction it asserts `ownerCycle.turningLift == singularity->indexNumerator` at `FieldTransportAtlasTests.cpp:2592-2596`. That assertion repeats the same unsupported cross-domain equality used by production. The test therefore cannot serve as independent authority for that numeric relation.

This is a **detection weakness attached to the same RP-01 product defect**, not a new stable RP-02 event. The primary semantic failure is production owner eligibility; the test mirrored the mistaken authority relation instead of independently discriminating incidence ownership from relative boundary lift. CB21 must repair both sides of this one seam and add a discriminator that would fail if the old equality were reintroduced.

## 5. Adjudication and candidate disposition

`M4-CP-SCALE-TB12-R7-EXEC-CAND-01` is reclassified:

> **OPEN / PRODUCT / CB18 SEPARATING-OWNER ELIGIBILITY CROSS-DOMAIN EQUALITY / existing `RP-01 AUTHORITY_DOMAIN_CONFLATION` / NON-STABLE; test-authority weakness: shared equality assumption.**

This is not a third distinct downstream product cause. It is a refinement/recurrence of the same R4 ownership seam: R4 exposed conflation of source-region boundary ownership with intra-region slit ownership; CB18 repaired the missing path but then conflated global source-vertex index authority with per-region relative boundary-cycle lift. The definition-turn escalation rule therefore does not fire.

`M4-CP-SCALE-TB12-R4-EXEC-CAND-01` remains **OPEN / PRODUCT / RP-01 / NON-STABLE** until a corrected fresh runtime proves the original genus-two S5 path advances. R7's direct A0 row is correction-gate evidence, not S5 recovery.

`M4-CP-SCALE-TB12-R6-EXEC-CAND-01` is now **CLOSED / ORCHESTRATION RECOVERY PROVED / NON-STABLE**: the exact CB20 harness correction reached generated Directional runtime and completed immutable postflight in R7. R6 remains historical provenance only.

## 6. Accounting and carried obligations

R7 fail-fast executed selector426 **0/426** and S5 **0/1**. No accepted-green identity changed and no candidate package is promoted. Stable accounting remains **49 events / 14 categories / 35 recurrences**, produced-witness debt **5**. Accepted runtime authority remains package `10473134357` / semantic source `e15e83c79a1e1962c0ed8d31ea85187ab6600e47` / selector426 **426/426**.

`M4-CP-SCALE-DEFN-OBS-04` remains **OPEN / NARROWED**: genus-two topology and retained-field singularity/index authority are independently supported, but production atlas admissibility and A3 reachability remain unproved. S1 calibration, the TB2 zero-transport helper audit, S2 arrival exact fallback, inherited produced-witness debt, CP3 observations, ordinal369 proposal quality, prescribed-sphere 368/398 and ordinal374 retain their existing owners.

## 7. Corrective owner frozen — `M4-CP-SCALE-CB21`

The smallest safe successor is **`M4-CP-SCALE-CB21`**, Code+Build only. Its detailed contract is frozen in `Architecture_M4_CP_SCALE_CB21_Separating_Hard_Feature_Owner_Eligibility_Code_Build_Plan.md`.

CB21 may change only the separating-feature owner eligibility/reconciliation in `FieldTransportAtlas.cpp` and the direct independent control in `FieldTransportAtlasTests.cpp`. Eligibility must be established by source-topology incidence and actual boundary-loop containment; deterministic ownership remains the minimum stable `(TopologyRegionId, FieldCycleId)`. The raw global singularity numerator remains the `FieldSingularityFact.indexNumerator`; the selected boundary cycle classifies where the singularity is absorbed and is not its numeric authority. `BarrierAbsorbed`, zero origin ports, owner exclusivity and diagnostics remain mandatory.

CB21 must remove the cross-domain equality from production and test authority, and must add a non-vacuous discriminator proving the repaired subject still owns the separating boundary when the independently established boundary-loop lift differs from the global source-vertex numerator. A test that only deletes the assertion without independently demonstrating the distinction is insufficient.

Frozen: source-topology partition, cycle ordering/`dual_cycles`, same-region slit ownership, source-boundary singularity semantics, retained genus-two OBJ/rawfield/metadata, S5 focus, selector426, CMake/benchmark semantics and accepted predecessor behavior. CB21 may compile/package under GMP/GMPXX with `runtimeExecution=false`; no generated Directional runtime is authorized. If compile/package is green, the next Test+Benchmark turn may be a fresh R8 artifact-only gate under the existing A0 -> A -> S5 -> selector426 fail-fast order.

**STOP / falsifiers:** stop rather than broaden if source authority proves `BoundaryLoop.turningLift` is normatively the per-vertex singularity authority; if the fix requires changing topology partition/cycle ordering/source-boundary/slit semantics/fixture/selector/CMake; if an independent control cannot distinguish incidence ownership from the deleted equality; or if the correction exposes a boundary-quadrangulability/certificate-definition issue rather than this ownership seam.

## 8. Consolidation

Review consolidation folds all superseded CP-SCALE per-turn documents since R4 Review into `M4_Consolidated_Record.md` §2.64, retaining one current document per role. The following historical files had already been retired by intervening cleanup and are indexed now from git authority: CB18 plan/report, R5 plan/report, CB19 plan/report, and R6 plan. Current-head superseded documents are removed after their durable facts are preserved.

| Folded filename | Lines | Disposition / retained home |
|---|---:|---|
| `Architecture_M4_CP_SCALE_CB18_Separating_Hard_Feature_Singularity_Ownership_Code_Build_Plan.md` | 101 | **CONSUMED/RETIRED; INDEXED BY R7 REVIEW.** R4 contract and CB18 bounded implementation obligations are retained in §2.64 and this Review. |
| `Architecture_M4_CP_SCALE_CB18_Code_Build_Report.md` | 93 | **SUPERSEDED/RETIRED; INDEXED BY R7 REVIEW.** CB18 semantic source/package provenance and added equality are retained in §2.64/current Review. |
| `Architecture_M4_CP_SCALE_TB12_R5_Artifact_Only_Test_Benchmark_Plan.md` | 146 | **CONSUMED/RETIRED; INDEXED BY R7 REVIEW.** Frozen 436-row gate and fail-fast semantics remain in §2.64 and later R7 evidence. |
| `Architecture_M4_CP_SCALE_TB12_R5_Artifact_Only_Test_Benchmark_Report.md` | 77 | **ORCHESTRATION-HISTORICAL/RETIRED; INDEXED BY R7 REVIEW.** Caller permission-ceiling failure is retained in §2.64/tracker/git history. |
| `Architecture_M4_CP_SCALE_CB19_Orchestration_Correction_Code_Build_Plan.md` | 70 | **CONSUMED/RETIRED; INDEXED BY R7 REVIEW.** Permission correction scope retained in §2.64/tracker. |
| `Architecture_M4_CP_SCALE_CB19_Code_Build_Report.md` | 93 | **SUPERSEDED/RETIRED; INDEXED BY R7 REVIEW.** Exact R6 caller authority retained in §2.64/git history. |
| `Architecture_M4_CP_SCALE_TB12_R6_Artifact_Only_Test_Benchmark_Plan.md` | 166 | **CONSUMED/RETIRED; INDEXED BY R7 REVIEW.** Fresh R6 artifact-only contract retained in §2.64. |
| `Architecture_M4_CP_SCALE_TB12_R4_Review_Record.md` | 210 | **SUPERSEDED/FOLDED BY R7 REVIEW.** R4 independent root cause and CB18 correction contract are retained here, §2.63/§2.64 and tracker history. |
| `Architecture_M4_CP_SCALE_TB12_R6_Artifact_Only_Test_Benchmark_Report.md` | 106 | **ORCHESTRATION-HISTORICAL/FOLDED BY R7 REVIEW.** R6 nounset failure and zero semantic execution are retained in §2.64/tracker. |
| `Architecture_M4_CP_SCALE_CB20_Orchestration_Harness_Code_Build_Plan.md` | 123 | **CONSUMED/FOLDED BY R7 REVIEW.** Nounset-only control-plane correction contract is retained in §2.64/tracker. |
| `Architecture_M4_CP_SCALE_CB20_Orchestration_Harness_Code_Build_Report.md` | 98 | **SUPERSEDED/FOLDED BY R7 REVIEW.** Corrected harness and R7 caller provenance are retained in §2.64/tracker. |
| `Architecture_M4_CP_SCALE_TB12_R7_Artifact_Only_Test_Benchmark_Plan.md` | 159 | **CONSUMED/FOLDED BY R7 REVIEW.** 436-row R7 gate/fail-fast/postflight contract is realized by §1 and §2.64. |
| `Architecture_M4_CP_SCALE_TB12_R7_Artifact_Only_Test_Benchmark_Report.md` | 120 | **ADJUDICATED/FOLDED BY R7 REVIEW.** R7 immutable semantic RED evidence is independently retained in §§1–5 and §2.64; it is not accepted runtime authority. |

Retained current CP-SCALE role set: normative `Architecture_M4_CP_SCALE_Frozen_Definitions.md`; accepted runtime-authority report `Architecture_M4_CP_SCALE_TB11_Artifact_Only_Test_Benchmark_Report.md`; this R7 Review record; exactly one next plan `Architecture_M4_CP_SCALE_CB21_Separating_Hard_Feature_Owner_Eligibility_Code_Build_Plan.md`; selector426 plus all historical byte-frozen selectors; `M4_Consolidated_Record.md`; tracker/changelog and other durable authority.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | selector426 = `41f4d559211375c11c8d1f8c9ccde2581db75819d9409366e8f2695b008b5114`; exact first425 = `e0e0f394faae536ac257ec5409653a34755a8afe0ca437562eb44c9895790e0b` |
| Decisive claims independently re-derived | R7 436-row ledger and one-row semantic RED; exact owner-count failure site; direct-test separating-feature/raw-index preconditions; CB18 eligibility/final equality; per-region boundary-lift correction semantics; accepted BarrierAbsorbed validator contract |
| Non-vacuity checked | row1 selected/executed exactly once; target vertex8 independently has separating-feature incidence and global +1 index while local slit authority is absent; CB21 is required to add an independent lift/index-mismatch discriminator rather than merely delete the shared equality |
| Prior obligations discharged/carried | R6 orchestration candidate CLOSED recovery-proved; R4 RP-01 remains OPEN and is refined by R7; R7 candidate is same RP-01 seam; `DEFN-OBS-04` carried/narrowed; prior S1/S2/inherited debts keep existing owners |
| Stable accounting | unchanged **49 events / 14 categories / 35 recurrences**, debt **5**; accepted authority remains package `10473134357` / selector426 **426/426**; CB18 candidate remains unpromoted |
| New candidates/obligations recorded | R7 candidate root-caused as CB18 separating-owner eligibility cross-domain equality, existing `RP-01`, non-stable, with a shared-test-assumption weakness; corrective owner `M4-CP-SCALE-CB21` |
| ORIENTATION currency line | `M4-CP-SCALE-TB12-R7-REV`, 2026-09-18 UTC |
| ORIENTATION §3 / §4 / §7 / §8 | updated for valid R7 semantic RED, CB18 falsification, same-RP-01 refinement, CB21 scope and global-index/per-region-boundary-lift authority distinction |
| CHANGELOG | R7 Review adjudication/root cause/accounting/successor entry added |
| ROADMAP | CP-SCALE current state updated: S5 unaccepted, CB18 falsified at direct A0 owner gate, CB21 next; accepted package/selector unchanged |
| Selector manifest | unchanged — selector426 remains accepted current M4 gate; no selector427 |
| LESSONS | no new entry — existing `RP-01`, lessons 65/150/153 and authority-domain rules already capture the reusable class; ORIENTATION §8 adds the concrete numeric-domain instance |
| Consolidation under CLEAN_UP_POLICY | intervening retired CB18/R5/CB19/R6 documents plus superseded current R4/R6/CB20/R7 documents folded/indexed in `M4_Consolidated_Record.md` §2.64; one accepted runtime report, one current Review and one next plan retained |
| Successor frozen | exactly `M4-CP-SCALE-CB21`; bounded product/test files, independent discriminator, frozen semantics and STOP conditions in the CB21 plan |
| Turn boundary held | yes — runtime-free Review; no generated Directional runtime, compile, package repair, product/test/fixture/selector/benchmark/build-source mutation |
| review_check.py boundary | **PASS** on the consolidated final local diff with declared selector426 SHA-256 `41f4d559211375c11c8d1f8c9ccde2581db75819d9409366e8f2695b008b5114`; no product/test/fixture/build/selector mutation and durable markers preserved |
| `STATUS` lifecycle maintained | start beacon `2026-09-18T09:08:09Z`; final COMPLETE beacon reserved as the last repository mutation after publication/cleanup verification |

---

## Independent verification addendum (reviewing agent)

Runtime-free. **Upheld, no correction.** Accounting holds at **49 / 14 / 35**, debt **5**; accepted package
`10473134357` / selector426 **426/426** unchanged.

### V1 — all three cited sites verified directly

- `src/authority/FieldTransportAtlas.cpp:2009` rejects an otherwise-incident owner on
  `cycle.turningLift != supplied->second`, exactly as §3 states;
- the same equality reappears as a `SingularityMismatch` condition in final separating-owner validation;
- `tests/FieldTransportAtlasTests.cpp:2596` asserts
  `EXPECT_EQ(singularity->indexNumerator, ownerCycle.turningLift)` — the test encodes the same equality the
  product does.

The domain argument holds. `rawSingularity[globalVertex]` is a **global source-vertex** index numerator;
`BoundaryLoop.turningLift` is a **per-region relative** boundary-cycle quantity built from summed local lifts.
Those coincide only in special configurations, so equality is not a general invariant and cannot serve as an
eligibility gate. §3's observation that the callback already carries the ownership fact — the vertex is being
visited on that exact local boundary loop, with source-topology incidence establishing the rest — is what makes
the removal a simplification rather than a weakening.

### V2 — the pattern worth naming for CB21

CB18 was the correction for an `RP-01 / AUTHORITY_DOMAIN_CONFLATION` defect, and its fix **introduced a new
`RP-01` conflation**. That is not a coincidence worth passing over: a correction in this family is written by
someone reasoning across two domains at once, which is exactly the state in which the two get equated.

CB21 is the next correction in the same family, so the caution applies directly to it: whatever CB21 uses in place
of the removed equality must be drawn from **the same domain as the decision it governs**. Owner eligibility is a
per-region incidence question, so it should be settled by per-region incidence facts — the local boundary loop and
the source-topology incidence map — and not by any quantity whose authority is global. The §7 stop rule already
guards the converse case, where source authority turns out to make `turningLift` normatively the per-vertex
authority; this guards the direction that actually failed.

### V3 — the handoff stop condition was applied and correctly declined

`Future_Chat_Session_Handoff.md` records that a **third distinct product root cause** on this S5 path should route
to a definition turn rather than another bounded CB. §5 addresses it head-on and correctly determines it does not
fire: this is a refinement/recurrence of the same R4 ownership seam, not a third distinct downstream cause, and
CB19/CB20 were control-plane rather than semantic attempts. CB21 is therefore only the **second** semantic attempt
at this seam. The threshold remains live and unspent.

Keeping `M4-CP-SCALE-TB12-R4-EXEC-CAND-01` **OPEN** until a corrected runtime proves the genus-two S5 path
advances is the right bookkeeping — R7 falsified a correction, which is not the same as closing the defect that
correction targeted.

### V4 — the CB21 contract needs nothing added

Checked against what this reviewer would otherwise have required, and each is already frozen: the discriminator
must establish a case where the relative loop lift is **not equal** to the global numerator while incidence and
ownership preconditions stay valid, and then require ownership to succeed; the mismatch must be established
**without reading the producer's published owner as the oracle**; the discriminator must **fail if the old CB18
equality is restored**, with mere deletion of the assertion called vacuous in terms; and the canonicalization
control requires multiple incident owner candidates to resolve by stable authority IDs rather than insertion
order, with the expected identity derived independently of producer output.

That last control is the competing-owner negative this reviewer intended to add, stated more precisely than the
addition would have been. Removing the equality from both production and test authority together is also correct —
leaving it in the test would reproduce the self-confirming oracle that prevented CB18's defect from being caught
at the time.
