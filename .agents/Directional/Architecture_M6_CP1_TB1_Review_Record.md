# M6-CP1-TB1 independent Review record

**Turn:** `M6-CP1-TB1-REV`
**Type:** runtime-free independent Review
**Reviewed candidate:** artifact/source `10826090221 / ee8b8ac20571df5773f5f94bf9b382161f37a893`
**Reviewed runtime:** run/job `36045055975 / 107786525272`, result/log `10828084810 / 10827949954`
**Disposition:** **SEMANTIC RED UPHELD / EXEC ROOT-CAUSE CATEGORY CORRECTED / CANDIDATE UNPROMOTED / BOUNDED CB2 RECOVERY REQUIRED**

## 1. Evidence authority independently re-opened

Review re-downloaded and independently checked all decisive immutable authorities.

- Candidate ZIP `10826090221` hashes to `6e3c3b09d272e200f3c213aa5198ed805bff2f293f35b37a55b948176c870a9c`; root `SHA256SUMS` verifies **28/28**, `metadata/source-commit.txt` is exact source `ee8b8ac20571df5773f5f94bf9b382161f37a893`, GMP/GMPXX evidence is present, and its compile boundary remains `runtimeExecution=false`.
- TB1 result ZIP `10828084810` hashes to `796dc825a3d2de765d9618d78663611481077227d8d86b0ab2e78fcd76e1d7bd`; its self-excluding manifest independently verifies **933/933** files. Diagnostic log ZIP `10827949954` hashes to `144a5832801b3e175dcee7ef1a9c35dce64665bffb6806aa2937d7ac1ce6cbc3`.
- Accepted predecessor package `10814505512` re-hashes to `047c3a1d7b3d5b09fe97961442237742e3dc9fac0939ca20c1dffb86b2959aae`, verifies **28/28**, and identifies source `e284fea7c101eb86650d1c87c92d0fefa66050e7`.
- Accepted selector449 is still exactly **449 LF rows**, SHA-256 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`; routing449 is `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707`, with owner census **32 / 301 / 75 / 41**. Both selector and routing bytes are identical between the accepted M5 source archive and the Review snapshot.
- Exact Review snapshot run `36049736162` materialized branch event SHA `0b0c79684adb49d70de0f8c3cde4794d4b3fcdd1`; snapshot artifact `10829214833` has provider SHA-256 `cbeaca4ab0b136c048cc25dfe2fe5b5d677a00d1de61354cba47dea6926b5304`, source archive SHA-256 `a6f69bf7e39efe41b36b6bc83805a1cb6de0b59ff107aade439be43f44aa0a5b`, and its **5310/5310** source manifest verifies. Comparing candidate source to that snapshot over `src`, `include`, `tests`, `benchmarks`, `CMakeLists.txt`, and `cmake` finds **zero code-surface drift**.

Two local snapshot-verification invocations initially used the wrong working directory/path prefix and failed before establishing evidence. Both were corrected immediately; the successful checks above are the only checks credited. No repository or runtime state was affected.

## 2. TB1 mechanics independently re-derived

Review re-parsed the result manifest, semantic summary, execution ledger and RED ledger rather than copying the EXEC report totals.

- focused: **6 total / 3 PASS / 3 RED**;
- accepted selector449: **449 total / 437 PASS / 12 RED**;
- total: **455 processes / 440 PASS / 15 RED**;
- exact-one selection for every process, **0 skips / 0 crashes / 0 selection mismatches**;
- **0 benchmark / configure / build / link** executions.

The focused RED identities are `M6CP1.CoincidentUnrelatedOccurrencesRemainDistinct`, `SurfaceCellTransitionQuotient.MultiIsolationMaterializationRetainsAllLocalSheets`, and `M5CP3.ProducedTorusPeriodicPairStorageSwapPreservesSemanticDirection`. The accepted-prefix RED ordinals are exactly **115, 116, 139, 140, 141, 143, 186, 225, 239, 444, 446, 448**. Their raw SHA-256 values agree with the preserved 15-row RED ledger. There is no second runtime, partial rerun, timeout, or stitched continuation.

The event grouping from EXEC is upheld: the twelve accepted PASS -> RED transitions are one stable event because all are downstream of the same newly inserted A5 construction gate, while the three candidate-only focused REDs are localization evidence and do not add accepted-prefix events.

## 3. Exact `InvalidCornerAuthority` sub-predicate

The EXEC report correctly localized the stop to `SurfaceOccurrenceComplexProducer::produce(...)` but its proposed `RP-01 / AUTHORITY_DOMAIN_CONFLATION` root cause is **not upheld**.

The exact candidate source contains:

```cpp
const authority::IsolationSheetId sheet =
    phaseFront.sourceTopologyRegions().sheet_for_row(*faceId);
if (component != region->second->component() ||
    !std::binary_search(region->second->isolation_sheets().begin(),
                        region->second->isolation_sheets().end(), sheet)) {
  error.code = SurfaceOccurrenceComplexErrorCode::InvalidCornerAuthority;
  ...
}
```

`SurfaceTopologyRegion::isolation_sheets()` returns `std::vector<IsolationSheetId>` **by value**. The two calls therefore materialize two distinct vectors. The `begin()` iterator belongs to the first temporary and the `end()` iterator belongs to the second; they do not define one valid iterator range. Passing that cross-container pair to `std::binary_search` violates the algorithm's range precondition and gives undefined behavior. A source-wide search finds this as the only `isolation_sheets().begin()/end()` split in candidate production/test code.

The accepted M5 source is the decisive differential. Its corresponding corner-authority check already requires the **same region, same component, and membership in the region's isolation-sheet set**, but first materializes one stable vector in `regionSheetsById` and calls `std::binary_search` with `begin()`/`end()` from that same vector. Accepted M5 then passes selector449 **449/449**. `SourceTopologyRegions.h`, including the by-value `isolation_sheets()` contract, is byte-identical between accepted M5 and the M6 candidate.

Only five production/test surfaces differ between accepted M5 and the candidate: `AuthorityIds.h`, `RemeshPipeline.h`, `BenchmarkQuality.cpp`, `RemeshPipeline.cpp`, and `SurfaceCellTransitionQuotientTests.cpp`. The existing selector test bodies were not rewritten; the test-file diff only adds the four M6CP1 identities and deletes the authorized endpoint-gauge identity. The phase-front source-topology authority implementation is unchanged.

This differential rules out the EXEC report's projection-chart/support interpretation as the accepted->RED cause. Projection-chart semantics may still matter later, but the accepted M5 implementation already enforced the same region/component/sheet semantic contract and passed. The new accepted-prefix loss is introduced by the **invalid cross-temporary iterator range**, before later source-support/chart validation can establish a different failure.

The ordering is decisive for recovery even though TB1 printed only the shared `OccurrenceInvalidCornerAuthority` code. Every A5 corner reaches the component/sheet membership expression before source-support resolution. Once the algorithm is called with endpoints from different vector objects, C++ range preconditions are violated and subsequent behavior is undefined; Review therefore cannot use any downstream behavior from that execution to credit a later support-resolution hypothesis while leaving this earlier invalid operation in place. A separate static observation is that A4 and `SurfacePointSourceSupportResolver` do not express identical barycentric admissibility bounds. That may deserve later evidence, but TB1 does **not** prove it is reached or responsible for the accepted-prefix loss. It is deliberately excluded from CB2 so the cross-temporary repair remains a one-variable falsifier; any remaining post-repair `InvalidCornerAuthority` belongs to fresh TB2 evidence and its mandatory Review.

## 4. Stable-event classification correction

`M6-CP1-TB1-EXEC-CAND-01` remains **one stable accepted-prefix event**, but Review corrects its category:

- **not** an `RP-01 / AUTHORITY_DOMAIN_CONFLATION` recurrence;
- **new singleton category:** `CROSS_TEMPORARY_ITERATOR_RANGE`;
- root mechanism: one value-returning container accessor is invoked independently for range `begin` and `end`, constructing iterators from different temporary containers.

Accordingly the stable totals are **52 events / 15 categories / 37 recurrences**, not 52/14/38. Project produced-witness debt remains **1**, M6-owned. This is a product implementation defect, not test-authority drift: twelve byte-frozen accepted identities lose accepted-green behavior and the direct focused A5 identities independently reach the same new seam.

Recovery does not erase this event. It closes only when a Review-authorized correction has compile/package evidence and a fresh immutable gate restores the complete unchanged selector449 plus the same six focused identities.

## 5. Candidate disposition

Candidate `10826090221 / ee8b8ac...` remains **UNPROMOTED / REJECTED FOR A5 ACCEPTANCE**. Accepted runtime authority remains M5 package/source `10814505512 / e284fea7c101eb86650d1c87c92d0fefa66050e7` under selector449 **449/449**.

No A5 acceptance, M6-CP1 closure, G4 debt credit, selector change, test weakening, or A6/A7/A8 work is authorized from TB1.

## 6. Complete TB1-EXEC Actions-window reconciliation

The complete working-branch Actions window from TB1 start through closeout contains exactly seven runs:

1. `36042627324` — source snapshot — **success**;
2. `36043977471` — harness Drive patch apply — **failure**, apply/control only, no Directional runtime;
3. `36044785998` — corrected harness Drive patch apply — **success**, apply/control only;
4. `36045055975` — **the sole artifact-only Directional runtime** — **success** mechanically / semantic RED as above;
5. `36047116151` — temporary-state cleanup — **success**, control only;
6. `36048171172` — closeout Drive patch apply — **failure**, apply/control only;
7. `36048440309` — corrected closeout Drive patch apply — **success**, apply/control only.

There is exactly **one** Directional runtime and no re-arm after it. The two failed Drive-apply runs are orchestration/control failures and contribute zero semantic evidence.

## 7. Bounded recovery frozen for `M6-CP1-CB2`

Exactly one successor is authorized: **`M6-CP1-CB2`**, Code + Build only.

The correction is intentionally one-variable:

1. In `SurfaceOccurrenceComplexProducer::produce(...)`, materialize the region's `isolation_sheets()` result exactly once into stable storage before forming an iterator range, or reuse an equivalently stable precomputed region-sheet container.
2. The sheet-membership search must use `begin()` and `end()` from that **same object**.
3. Preserve the existing region equality, source-component equality, typed `IsolationSheetId` membership, support resolution, chart validation, A5 `OccurrenceId=(CellId,canonicalCornerRole)`, relation semantics, A4 `CellId`, and all M5 authority. Do not remove or weaken any check to obtain green output.
4. Do not change tests, fixtures, selectors, routing, benchmarks, headers, A6/A7/A8, hard-feature/isolation classification, or fallback/recovery behavior. Existing focused and accepted-prefix failures already provide the recovery falsifier; changing them would destroy the controlled comparison.
5. Static CB2 closeout must prove there is no `binary_search` (or equivalent range algorithm) whose endpoints are obtained by separate calls to the by-value `isolation_sheets()` accessor, and that no product/test/selector surface outside the bounded production correction changed.
6. Compile/package the standard eight approved targets only through `agent-compile-reusable.yml` with mandatory GMP/GMPXX and `runtimeExecution=false`.

CB2 earns no semantic credit. Its exact successor, if compile/package evidence is complete, is **`M6-CP1-TB2-EXEC`**. TB2 must consume the CB2 package immutably and execute **the same six focused identities plus the unchanged selector449 as 455 fresh exact-filter processes**. The recovery criterion is 6/6 focused and 449/449 selector PASS with exact-one/zero-skip and immutable postflight. Mandatory runtime-free **`M6-CP1-TB2-REV`** follows. Any accepted-prefix RED remains a failed recovery and must not be repaired inside TB2.

## 8. Prior obligations and retained boundaries

- `M6-CP1-TB1-EXEC-CAND-01`: **CAUSE CORRECTED / RECOVERY OPEN**, owner chain `M6-CP1-CB2 -> M6-CP1-TB2-EXEC -> M6-CP1-TB2-REV`.
- M6 closed-complex produced debt `G4-B002`: **OPEN**, still CP1 mechanism / CP3 direct production.
- `G4-B004` M6 representative-consumption half: **OPEN**. No representative-consumption credit follows from a rejected A5 candidate.
- `G4-B001`: still CP3 direct-torus evidence debt; no validator weakening.
- Retained edge-storage pair-swap focused identity remains required in the same six-test CP1 recovery vector.
- A4 `CellId` insertion/omission renumbering remains a later M7-definition concern, not part of this correction.

## 9. Consolidation

Following `CLEAN_UP_POLICY.md`, this Review retains one current document per role and folds the consumed M6 per-turn predecessors only after their durable facts are preserved. The following are retired from current head and indexed in `M6_Consolidated_Record.md`: `Architecture_M6_CP1_CB1_Occurrence_Product_Code_Build_Plan.md` (78 lines), `Architecture_M6_CP1_CB1_Occurrence_Product_Code_Build_Report.md` (94 lines), and `Architecture_M6_CP1_TB1_Artifact_Only_Test_Benchmark_Plan.md` (66 lines). The retained current set is the TB1 runtime report, this Review record, exactly one CB2 plan, the consolidated record, frozen definitions and byte-frozen selector/routing authority. The live historical reference in `Architecture_M6_Frozen_Definitions.md` is repaired to the consolidated index.

## 10. Review closeout orchestration reconciliation

An overlapping closeout attempt prepared a different staged Review patch and triggered run `36053774476` at event SHA `8235acdbd16c54a57b93b85d4e0c6c88af523876`. The workflow schema validation passed and the Drive patch verified, but the required Review-resume `STATUS` write advanced the branch while the apply job was running; its push was rejected non-fast-forward. Result/log artifacts `10831995776 / 10831826556` record `applied_commit_sha=unavailable`, `runtimeExecution=false`, and no repository semantic/document bytes from that patch became authority.

That unapplied draft attributed the failure to downstream source-simplex canonicalization. Independent reconciliation rejects that attribution for TB1 because it assumes the preceding sheet-membership search is a valid range. Exact candidate source proves that search enters undefined behavior first by combining iterators from two by-value temporaries. The downstream admissibility mismatch is therefore not credited as TB1 root cause and is not folded into CB2. This correction is an evidence adjudication, not a runtime rerun or product mutation.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | selector449 **449 LF rows**, `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`; routing449 `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707`; accepted M5 and Review snapshot bytes are identical. |
| Decisive claims independently re-derived | Candidate 28/28 and exact source; TB result 933/933 and 455-process ledger; accepted predecessor 28/28; 15-row RED set; accepted-vs-candidate source differential; exact by-value accessor and cross-temporary range; complete seven-run EXEC Actions window. |
| Non-vacuity checked | **PASS.** Twelve accepted selector identities lose previously accepted behavior and three focused rows reach the same A5 seam. Accepted M5 performs the same semantic region/component/sheet checks with a valid stable range and passes 449/449, directly discriminating the new implementation defect. |
| Prior obligations discharged/carried | TB1 exact-subpredicate obligation discharged with the cross-temporary range proof; stable recovery event carried to CB2/TB2/Review; G4-B002, G4-B004 M6 half and G4-B001 remain open; pair-swap remains in CP1 gate. |
| Stable accounting | **52 events / 15 categories / 37 recurrences; debt 1 M6-owned.** Accepted authority remains `10814505512 / e284fea7...` + selector449 449/449. |
| New candidates/obligations recorded | `M6-CP1-TB1-EXEC-CAND-01` category corrected to new singleton `CROSS_TEMPORARY_ITERATOR_RANGE`; recovery owner chain and falsifier recorded in tracker. A downstream barycentric-admissibility hypothesis is explicitly **not credited** by TB1 and may be reconsidered only if fresh post-range-repair evidence reaches it. |
| ORIENTATION currency line | `M6-CP1-TB1-REV`, 2026-09-24 UTC. |
| ORIENTATION §3 / §4 / §7 / §8 | §3 corrected totals/root cause and CB2 next; §4 unchanged witness facts; §7 puts CB2 recovery first; §8 records the new cross-temporary range pattern and removes the superseded RP-01 reading from current authority. |
| CHANGELOG | Agent and root entries prepended for this Review; TB1 historical entry retained with Review correction noted. |
| ROADMAP | M6-CP1 changed from Review-pending RP-01 reading to cause-proved cross-temporary-range recovery with CB2 exact next. |
| Selector manifest | n/a — no selector added, published, demoted, or accepted; selector449 remains exact accepted authority. |
| LESSONS | New named lesson: **Materialize value-returning containers before forming iterator ranges**. |
| Consolidation under CLEAN_UP_POLICY | **DONE.** Folded consumed CB1 plan (78 lines), CB1 report (94 lines), and TB1 plan (66 lines) into the M6 consolidated index after preserving their durable facts; retained TB1 runtime report, this Review, one CB2 plan, frozen definitions and selector/routing authority. |
| Successor frozen | Exactly `M6-CP1-CB2`; bounded one-variable range correction and falsifiers are in §7 and `Architecture_M6_CP1_CB2_Corner_Authority_Range_Correction_Code_Build_Plan.md`. |
| Turn boundary held | Runtime-free Review; no Directional product/test/fixture/selector/benchmark/build source mutated and no generated Directional runtime executed. |
| `review_check.py boundary` | **PASS on the exact verified Review snapshot with the proposed durable diff**; selector449 declared hash matched and no product/test/fixture/build or selector mutation was present. |
| `STATUS` lifecycle maintained | Entry/resume beacons maintained for `M6-CP1-TB1-REV`; COMPLETE -> `M6-CP1-CB2` is reserved for the final repository write after durable docs and cleanup. |
| Pushed to origin, branch in sync | Connector-mode closeout: no local origin branch exists in the analysis container; final remote PR head/hygiene is re-read after apply/cleanup before COMPLETE. This is the connector equivalent of the in-sync confirmation. |

---

## Independent verification addendum (reviewing agent)

Runtime-free. **UPHELD.** The UB root cause, the one-event grouping, the new singleton category (52 / 15 / 37), candidate rejection and the one-variable `M6-CP1-CB2` scope all stand.

**What I re-derived:**
- **Artifacts, downloaded fresh.** TB1 result/log `796dc825…` / `144a5832…` and CB1 package `6e3c3b09…` (source `ee8b8ac2`, eight targets). The manifest verifies 933/933. The 455-row ledger has 6 focused rows plus 449 selector rows in exact selector449 order, 0 selection or skip anomalies, and all raw-log hashes match.
- **Failure codes.** The RED selector ordinals are exactly 115, 116, 139, 140, 141, 143, 186, 225, 239, 444, 446 and 448. Each of them, and focused rows 5-6, logs `OccurrenceInvalidCornerAuthority`.
- **The defect.** `SourceTopologyRegions.h:74` returns `isolation_sheets()` by value, and `RemeshPipeline.cpp:3337-3338` calls it separately for `begin()` and `end()`.
- **The differential.** I opened accepted M5's corner check (`e284fea7:RemeshPipeline.cpp:3449-3468`). It applies the **same** `trace.face` → component/region/sheet predicates as the candidate, through one stable `regionSheetsById` vector. The only difference is the iterator range, which confirms that EXEC's RP-01 projection-face reading is correctly rejected. §3 above compares against the isolation-certificate block, but the corner check is the exact counterpart and supports the same conclusion.
- **No other instance of the defect class.** I scanned every header for by-value container accessors (eight: `isolation_sheets`, `oriented_steps`, `carrier_identity`, `region_by_face`, `singularity_vertices` and three string accessors). Only one `X().begin() … X().end()` split range exists in `src/`, `tests/` and `include/`: this one. CB2's one-variable scope is therefore sufficient.

**Additions:**
1. **TB1's focused PASSes are not evidence.** `…PublishesFourSemanticCornersPerCell`, `…SourceFaceRowPermutationPreservesOccurrenceIdentity` and `…RejectsMalformedMissingAndDuplicateRelationEndpoints` each run `SurfaceOccurrenceComplexProducer::produce` on the single-region `square_fixture()`, through the undefined range. Their PASS may be chance. This record credited nothing to them explicitly, and it should have said so. Only TB2 can credit them.
2. **TB2 classification is pre-registered in the CB2 plan.** `M6-CP1-TB1-EXEC-CAND-01` counts as recovered only if no process reports `OccurrenceInvalidCornerAuthority` **and** selector449 is 449/449. A focused RED whose first failure is different is a **new** candidate, not a failed recovery. This matters for `M5CP3.ProducedTorusPeriodicPairStorageSwapPreservesSemanticDirection`, which has never run cleanly and could expose a latent M5 edge-storage-order dependence.
3. **The benchmark edit is accepted.** CB1 changed `src/bench/BenchmarkQuality.cpp` despite its plan's "no benchmark change". The edit hashes the new semantic `OccurrenceId` as `(cell, canonical_corner_role)` because `.index()` no longer exists. It was a necessary compile adaptation that changes the digest domain, not benchmark inputs. §§1-3 above list the file but never reconcile it with the prohibition.
4. **Stale header fixed.** The M6 frozen-definitions header still read `EXACT NEXT = M6-CP1-CB1`.

### Review closeout — reviewing-agent addendum

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | selector449 `d4a0d1b7…`, 448 `70ff0860…`, 430 `1c412850…` via `boundary --expect-selector`. The TB1 selector phase order equals selector449. |
| Decisive claims independently re-derived | Artifacts, manifest, ledger, raw hashes and RED codes; the by-value accessor and split range; the M5 corner-check differential; a repo-wide split-range scan; the benchmark diff |
| Non-vacuity checked | Focused PASSes under UB are declared uncredited. Accepted-prefix losses discriminate, because M5 passes the same predicates with a valid range. |
| Prior obligations discharged/carried | CAND-01 recovery is carried to CB2/TB2/TB2-REV under the pre-registered rule. `G4-B002`, the `G4-B004` M6 half and `G4-B001` are unchanged. |
| Stable accounting | 52 / 15 / 37; debt 1 (M6); accepted authority `10814505512 / e284fea7…` under selector449 |
| New candidates/obligations recorded | Tracker addendum; CB2 plan pre-registration |
| ORIENTATION currency line | `M6-CP1-TB1-REV` (incl. reviewing-agent addendum), 2026-09-24 UTC |
| ORIENTATION §3 / §4 / §7 / §8 | §7 item 1 gains the pre-registration. §3, §4 and §8 are correct. |
| CHANGELOG | Agent and root entries amended |
| ROADMAP | n/a — correct |
| Selector manifest | n/a |
| LESSONS | This Review's new lesson ("Materialize value-returning containers…") is upheld, and the scan confirms the single instance |
| Consolidation under CLEAN_UP_POLICY | n/a — correctly done by this Review |
| Successor frozen | `M6-CP1-CB2`, per its plan plus the binding amendment |
| Turn boundary held | Runtime-free; no product/test/selector change |
| review_check.py | `boundary --expect-selector 449=d4a0d1b7… 448=70ff0860… 430=1c412850…`: **ALL CHECKS PASSED**. No product/test/build or selector mutation; durable markers 1→1, 3→3, 13→13. `ledgers --base 009c679b`: **ALL CHECKS PASSED**. |
| `STATUS` lifecycle | Resume beacon first; final `COMPLETE → M6-CP1-CB2` last |
| Pushed, in sync | Confirmed by `git status -sb` after the final push |
