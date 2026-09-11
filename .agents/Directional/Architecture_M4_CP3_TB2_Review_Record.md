# M4-CP3-TB2 Review Record — package120 exact-path/A3 publication acceptance

**Status:** COMPLETE / PACKAGE120 NOT PROMOTED / SELECTOR403 NOT ACCEPTED / ONE NON-STABLE TEST-AUTHORITY COVERAGE FINDING
**Turn:** `M4-CP3-TB2-REV`
**Date:** 2026-09-11 UTC
**Execution mode:** runtime-free Test + Benchmark review
**Accepted runtime authority:** package119 / selector394 **394/394**
**Reviewed candidate:** package120 / selector403, mechanically green but unpromoted
**Exact next:** `M4-CP3-TB2-PLAN`

## 1. Review boundary and evidence reopened

This review independently reopened the frozen TB2 plan, immutable package120, the TB2 result artifact, the exact package-owned source and the deleted execution caller. It did not execute any Directional binary, test, benchmark, discovery command, configure step, compile, relink or package repair.

Authoritative candidate/runtime evidence:

```text
semantic source      = 3f909a5a2cfd305d423faf7a260bc465c7b06892
package120 artifact  = 10280703200
package120 ZIP SHA   = 3f0ae49f1549ff2f5c4f821ee1db5bc0314405f8f726c04cecaaf5fa3cdf80a4
TB2 run/job          = 34647838897 / 103422811636
TB2 result artifact  = 10283220925
result provider SHA  = 314428caf9b240b992f56a48a471e210c0c8361331004d7a0a268ea9fbca4c6f
TB2 log artifact     = 10283302336
selector394 SHA      = 6c27b3a0fc7259c5817bc9bbf41d5e2a23b7dd20f41fb75db8789abeb2cfba68
selector403 SHA      = e8f4fe72cfbbd458289779125c7ff65d7344370df6a6fc98749b4ed9007de802
```

A fresh source snapshot of review head `981ce365410688ee342ea3b798e4ceaff26cb024` was also verified: snapshot archive SHA-256 `d1c2b8288aa3fb881c4c1c8773b3da9e3e2af477a1baa5821115d948f6686b89`, **5268/5268** file hashes valid, `runtimeExecution=false`. Static comparison of the package120 source against review-head `src/`, `include/`, `tests/`, `benchmarks/`, `cmake/` and root `CMakeLists.txt` found **387/387 files byte-identical**. The later documentation/control-plane commits therefore introduce no code/test/build drift relative to the reviewed package source.

## 2. Mechanical execution evidence is trustworthy

The TB2-EXEC mechanical result is upheld. Independent re-derivation from `process-ledger.tsv`, raw logs and pre/post censuses found:

```text
focused-A rows 395-403 =   9/9 PASS
focused-B rows 395-403 =   9/9 PASS
accepted prefix 1-394  = 394/394 PASS
candidate 1-403        = 403/403 PASS
total processes        = 815/815 PASS
RED / SKIP / mismatch  = 0 / 0 / 0
timeouts                = 0
```

Each ledger row records exit `0`, `timeout=false`, exactly one requested `[ RUN      ]`, exactly one matching `[       OK ]` and zero skips. Phase ordinal ranges are exactly 395-403, 395-403, 1-394 and 1-403. The focused-A and focused-B ordered identity/verdict vectors are byte-identical. The result artifact contains exactly **815** per-process raw logs.

Static owner mapping was re-derived from package-owned `cmake/DirectionalTests.cmake` plus default-owner source definitions rather than copied from the EXEC report. Every selector identity resolves exactly once. Owner totals are:

```text
selector394 = 30 authority-kernel / 248 producer / 75 completion / 41 validation
selector403 = 30 authority-kernel / 257 producer / 75 completion / 41 validation
```

Package `SHA256SUMS` independently verifies **28/28** entries and exactly matches the package path set excluding the self-excluded manifest. Package/source/execution-view pre/post censuses are byte-identical. Source commit, preflight/build exit codes, GMP/GMPXX evidence, command-boundary flags and clean source-status files all match the frozen preflight contract.

The historical execution caller was reopened at `55d7c69d32504dcdcd79fddc0a933432ee332ad4`: it executes the four phases sequentially, starts one exact-filter GTest process per row with `GTEST_FAIL_IF_NO_TEST_SELECTED=1`, rejects nonzero/zero-selection/multi-selection/skip outcomes, then repeats package/source/execution-view censuses and manifest verification. No aggregate timeout, compile or generated discovery path is hidden in the caller.

## 3. Accepted prefix and selector lineage re-derived

The package-owned selector files establish:

```text
selector403 rows             = 403
selector403 SHA-256          = e8f4fe72cfbbd458289779125c7ff65d7344370df6a6fc98749b4ed9007de802
selector403 first394 SHA-256 = 6c27b3a0fc7259c5817bc9bbf41d5e2a23b7dd20f41fb75db8789abeb2cfba68
selector394 rows             = 394
selector394 SHA-256          = 6c27b3a0fc7259c5817bc9bbf41d5e2a23b7dd20f41fb75db8789abeb2cfba68
first382 SHA-256             = 1d59b1f709e51854f8ceaee1a161687ff882a128dabdc79882712c97a15ca84f
```

Rows 1-394 of selector403 are byte-identical to accepted selector394. The accepted package119/selector394 authority therefore remains mechanically compatible on package120 at **394/394**; there is no accepted-green loss.

## 4. Rows 395-403 non-vacuity review

The nine appended identities were independently reopened at their exact package-owned definitions. Eight satisfy their frozen witness obligations:

| Row | Review disposition | Non-vacuity evidence in source |
|---:|---|---|
| 395 | CREDIT | constructs event/cut fixtures, requires Mandatory/Trace/Cut to all be observed, and requires every inspected exact path non-empty/canonical |
| 396 | CREDIT | requires both a Mandatory strict interior split interval and a trace-crossed Cut strict interior split interval |
| 397 | CREDIT | requires a Trace arc with more than one support piece and checks piece count/carriers/exact endpoint continuity |
| 398 | CREDIT | checks stored forward path, exact reversal, double reversal and no canonical-arc mutation |
| 399 | CREDIT | independently rebuild-rejects five tamper classes: order, kind, carrier, point coordinate and overbroad split subinterval |
| **400** | **NO CREDIT — FINDING** | names a permuted `sourceRow`, but that row is detached from the point construction; see §5 |
| 401 | CREDIT | requires one span per arc, `from_network_arc` IDs, exact support equality and matching topology digest, with no caller family/sign surface |
| 402 | CREDIT | deliberately substitutes a redundant edge-point-at-endpoint encoding and requires independent rejection |
| 403 | CREDIT | requires production A2b+A3 publication, independent baseline validation, arc/span count equality, exactly one debug product and immediate A2b→A3 product order |

Rows 395-399 and 401-403 therefore receive runtime credit from the frozen 9/9 focused/cumulative executions. Row400's passing process is mechanically real but does not prove the contract its name and R1 plan assign to it.

## 5. Finding `M4-CP3-TB2-REV-CAND-01` — row400's permuted source row is detached

**Classification:** STRUCTURALLY INVALID FIXTURE / MISSING SCENARIO COVERAGE / TEST-AUTHORITY / NON-STABLE.

The R1 plan explicitly requires that any face-barycentric test **use a source-face row whose vertex order differs from canonical key order so canonical component mapping is actually exercised**. Normative §17.12 likewise defines face-point barycentrics as coordinates associated with canonical face-topology vertex order.

The packaged row400 definition does not exercise that mapping:

```cpp
const auto face = topology_face(0, 1, 2, 3U);
const std::array<int, 3> sourceRow{2, 0, 1};
ASSERT_NE(sourceRow[0], static_cast<int>(face.vertices()[0].index()));
const std::array<FieldExactRational, 3> barycentric{1/2, 1/3, 1/6};
const auto point = canonical_exact_source_face_point(face, barycentric);
...
EXPECT_EQ(barycentric, facePoint->barycentric);
```

`sourceRow` participates only in the detached `ASSERT_NE`. It is not used to construct a source mesh/face, convert barycentric components, derive the point, or otherwise affect the subject under test. The helper receives a canonical `SourceFaceTopologyKey` plus an already-canonical coordinate array. Consequently the identity would still pass if the production conversion from a permuted source-face row into canonical component order were absent or wrong.

This is the exact failure pattern in `LESSONS.md` 171: a fixture can contain the demanded structure without exercising it. The discriminator is missing, not red.

### Product-versus-test discrimination

No production defect is established by this review. Static package-source inspection shows the production trace/contact path derives exact face coordinates through canonical topology keys and canonical boundary/vertex mapping before calling `canonical_exact_source_face_point`. That is evidence against inventing a product fix, but static inspection cannot substitute for the frozen runtime non-vacuity obligation. The missing contract must be proved by a valid test scenario before package120 can be promoted.

**Falsifier for successor planning:** a corrective identity must derive the tested exact point from an actual source-face row whose order differs from its canonical topology key, use distinct barycentric components so a permutation is observable, and fail if row→canonical component remapping is omitted/swapped. Merely retaining a detached `sourceRow` variable or asserting the final canonical array against itself is prohibited.

## 6. Package, checkpoint and accounting disposition

Because selector403 is a required-green acceptance surface and row400 has no valid proof of its intended contract, package120 is **NOT PROMOTED** and selector403 is **NOT ACCEPTED** despite 815/815 mechanical PASS. The accepted runtime authority remains package119 / selector394 **394/394**.

This review records no accepted-green loss and no production implementation regression. `M4-CP3-TB2-REV-CAND-01` is non-stable. Stable accounting remains **47 events / 14 categories / 33 recurrences**; produced-witness debt remains **5**. CP3 remains open. The deferred A3→A4 cutover (`CB5` in earlier prose) is **not authorized**.

## 7. Prior obligations

`M4-CP3-TB1-R1-REV-OBS-01` remains open. Its region-incidence multiplicity weighting is still structurally present but behaviourally unexercised because the retained oracle receipt contains only multiplicities `[1,1,1]`. CB4-R1 touched test source for the §17.12 recovery but did not discharge this obligation. It is explicitly re-carried rather than silently expired.

Per `LESSONS.md` 170, do not combine that unrelated multiplicity experiment with the row400 recovery merely because both touch test source: the row400 recovery needs a one-variable falsifiable control. `M4-CP3-TB2-PLAN` must assign the multiplicity obligation to the first later test-source turn that can exercise it without confounding the bounded row400 recovery, or explicitly prove why a combined turn preserves independent falsifiability.

No other unresolved TB2 review obligation is created.

## 8. Exact successor and boundary

Exact next is **`M4-CP3-TB2-PLAN`**, runtime-free planning only. It must freeze the smallest bounded recovery for `M4-CP3-TB2-REV-CAND-01`, preserve selector403 identity/name/order/hash unless the plan proves a selector change is unavoidable, prohibit product changes absent contradicting evidence, and require a later artifact-only rerun that re-proves the corrected row400 contract plus the accepted selector394/cumulative selector403 gates before any promotion.

This review does not design or execute the corrective Code + Build turn, does not run new tests, and does not authorize A4 cutover work.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | selector403 first394 = selector394 = `6c27b3a0fc7259c5817bc9bbf41d5e2a23b7dd20f41fb75db8789abeb2cfba68`; first382 = `1d59b1f709e51854f8ceaee1a161687ff882a128dabdc79882712c97a15ca84f` |
| Decisive claims independently re-derived | 28/28 package manifest/path set; 815-row ledger; four phase ranges/totals; owner maps; focused A/B equality; pre/post censuses; package/source code identity; exact row395-403 source definitions |
| Non-vacuity checked | rows395-399 and 401-403 credited; row400 rejected because its permuted `sourceRow` is detached from the tested mapping |
| Prior obligations discharged/carried | `M4-CP3-TB1-R1-REV-OBS-01` carried; CB4-R1 did not discharge it; next planning must preserve one-variable recovery discipline |
| Stable accounting | **47 events / 14 categories / 33 recurrences**, debt **5**, accepted package119 / selector394 **394/394** |
| New candidates/obligations recorded | `M4-CP3-TB2-REV-CAND-01` added to `Regression_Root_Cause_Tracker.md`; no stable event |
| ORIENTATION currency line | updated to `M4-CP3-TB2-REV`, 2026-09-11 |
| ORIENTATION §3 / §4 / §7 / §8 | §3 and §7 updated; §4 n/a because no witness state changed; §8 adds this new instance of structural-presence-without-behavioural-coverage |
| CHANGELOG | TB2-REV entry added |
| ROADMAP | CP3 remains open; package120 review-blocked and exact next TB2-PLAN recorded |
| Selector manifest | selector394 accepted lineage corrected; selector403 candidate/review-blocked receipt added; selector bytes unchanged |
| LESSONS | no new number; existing lessons **170** and **171** apply |
| Consolidation under CLEAN_UP_POLICY | superseded CP3 per-turn docs folded into `M4_Consolidated_Record.md`; package119 accepted runtime report, selectors, frozen definitions and current review retained |
| Successor frozen | exactly one: `M4-CP3-TB2-PLAN`; falsifier stated in §5 and boundary in §8 |
| Turn boundary held | runtime-free; no product/test/fixture/selector/build mutation and no Directional runtime |
| review_check.py boundary | **PASS** — no product/test/fixture/build or selector mutation; selector394 explicit hash matched; exact M4 selector403 independently hashed `e8f4fe72...` (numeric-count helper collides with historical M3 selector403, so path-specific SHA was used) |
| Pushed to origin, branch in sync | **PASS** — exact review closeout patch `f601625ced023c96f1a835f58eb460407cfd2309c7ad1a802e63ce5af5da2192` applied and pushed as `842137328e66f140839747b625dcd2bb152a48eb`; remote review record/handoff read-back verified; subsequent control-plane-only cleanup does not alter review semantics |
