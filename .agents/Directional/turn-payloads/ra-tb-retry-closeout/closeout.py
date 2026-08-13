from pathlib import Path
import re

SOURCE = "92bf0ae2b10856162f175d02aeac318e126f9d22"
RUN_JOB = "31656958868 / 94313437913"
RESULT_ID = "9164742196"
RESULT_SHA = "2260c0d672dd3a7836f8916648d02e51cd8e3c53b762f318a23b112d08871921"
LOG_ID = "9164742553"
LOG_SHA = "6b07a47937736951b243465f3a4b5abc218d740c13dbb1eb101dcb3127d1066e"


def replace_between(text: str, start: str, end: str, replacement: str) -> str:
    a = text.index(start)
    b = text.index(end, a)
    return text[:a] + replacement + text[b:]


handoff_path = Path('.agents/Directional/Future_Chat_Session_Handoff.md')
handoff = handoff_path.read_text()
mandatory = f"""## Mandatory next turn

Run one **bounded Code + Build R-A remediation turn for artifact-only retry 2**. The exact immutable package from `{SOURCE}` passed preflight/static inventory/postflight but failed organically at the aggregate authority layer. Do not rerun the unchanged package and do not mark R-A complete.

Repository: `akashskypatel/Directional`  
Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`  
PR: #8 remains open, draft, and unmerged  
Failed candidate source: `{SOURCE}`  
Compile run/job: `31655755100 / 94309741656`  
T+B retry run/job: `{RUN_JOB}`  
T+B result artifact: `{RESULT_ID}`, SHA-256 `{RESULT_SHA}`  
T+B log artifact: `{LOG_ID}`, SHA-256 `{LOG_SHA}`

Artifact-only retry 2 was immutable and orchestration-clean: exact result/log digests, archive safety, manifest **25/25**, five empty source-status snapshots, packaged **19-path / 50-probe / 206-match** static inventory, and postflight all passed. Discovery was non-vacuous (**13 authority-kernel / 232 producer / 179 completion / 84 validation**). Across **88 unique R-A contracts, 76 passed / 12 failed**, `orchestration_failed=0`, `rebuild=false`, `sourceMutation=false`, `packageRepair=false`.

Implement only the new retry-2 remediation section **0J** in `Architecture_M1_Single_Authority_Cutover_Code_Build_Plan.md`:

1. make the aggregate derived-identity rejection diagnostic at the failing sub-invariant, then repair that invariant rather than bypassing `rebuild_aggregate_output_identity_caches`. The post-move success contract and multiple disconnected baselines now reach `component-merge-authority`; the provenance-only counterfactual reports `InvalidGlobalDerivedIdentity` before the final oracle. Because that counterfactual mutates only `outputVertexProvenance`, while the derived-identity rebuild consumes completed-patch/output lineages and typed source authority, this is evidence of a baseline aggregate identity blocker rather than the provenance mutation itself;
2. after the identity blocker is fixed, require the boundary final-oracle, missing-component-report, raw-projection counterfactual, and provenance-tamper contracts to reach their declared seams naturally. Do not weaken the final oracle or fabricate boundary authority;
3. fix component feature-option ownership. The aggregate component runner copies `componentOptions = options` onto compact component-local meshes but does not remap `featureMap.userHardEdges` / `userSoftEdges` from original-global vertex IDs. Build an explicit original-to-local vertex map per component, retain only edges wholly owned by that component, and add no-cross-component-leakage coverage. Then revalidate the hard-feature tamper and feature-bearing final-oracle contracts;
4. regenerate the complete R-A inventory and compile one fresh exact-source package through `agent-compile-reusable.yml`. Code + Build only; execute no generated binary/test/benchmark/discovery/CLI/fuzzer/custom input.

Completion authority is now **18/18**, optimizer/final-validator authority **8/8**, authority kernel **13/13**, isolation-seam authority **6/6**, source validator **8/8**, rail migration **7/7**, and source-support/chart **1/1**. Do not reopen CB-03/CB-04 unless new evidence directly implicates them.

No independent Review turn is requested. After the fresh compile package, retry the same immutable R-A semantic gate. R-A closes only on an organic pass.

RA-REV-23-F3 and RA-REV-22-F6 remain post-R-A hygiene. M1l `bd140cff4572412e6f4ecd70a6ce0fe85310932c` remains immutable runtime authority.

"""
handoff = replace_between(handoff, '## Mandatory next turn\n', '## Current authority\n', mandatory)
status = f"""### R-A closure status

- Overall R-A remains **open / runtime-rejected** for candidate `{SOURCE}` after artifact-only retry 2.
- Retry 2 run/job `{RUN_JOB}` consumed compile artifacts `9164349848 / 9164350085` without rebuild or mutation. Preflight, **19 paths / 50 probes / 206 matches** static inventory, discovery, and immutable postflight passed; **88 unique selected, 76 passed / 12 failed**, zero orchestration failures.
- CB-03 completion closure is runtime-confirmed for the retained set: **18/18** completion authority contracts passed, including both former positive stitch failures. CB-04 is runtime-confirmed for its focused authority set: **8/8** optimizer/final-validator contracts passed, including typed source mismatch and rail-builder exact-source scope.
- The remaining aggregate suite is **15/27**. Multiple ordinary disconnected baselines and `PostMoveAggregateOptimizerUsesRetainedSourceAuthority` now progress past the former optimization failure but stop at `component-merge-authority`. `FinalMergedOracleRejectsPostComponentProvenanceTamper` exposes `InvalidGlobalDerivedIdentity` before the intended final oracle; source analysis shows that rebuild does not consume the raw provenance vector being mutated, making the derived-identity gate the next baseline blocker.
- The hard-feature aggregate fixture still stops at `completion`. Exact source shows component execution copies global feature-map edge options onto compact local meshes without an original-global to component-local edge remap; this must be corrected before feature-rail aggregate/oracle contracts can be credited.
- Boundary/feature final-oracle counterfactuals remain uncredited because their seam callbacks were not reached. Do not alter their expected oracle semantics to make them green.
- Result/log evidence: `{RESULT_ID}` SHA-256 `{RESULT_SHA}` / `{LOG_ID}` SHA-256 `{LOG_SHA}`.
- The first retry orchestration attempt `31656834137 / 94313056707` stopped before any packaged binary executed because its temporary preflight grepped obsolete inventory heading text; it is infrastructure-only evidence, not a semantic result.
- No stable regression event/recurrence is added: `{SOURCE}` remains an unaccepted R-A candidate. Historical totals remain **34 / 14 / 20**; M1l `bd140cff4572412e6f4ecd70a6ce0fe85310932c` remains immutable runtime authority.

"""
handoff = replace_between(handoff, '### R-A closure status\n', '## Standing product state\n', status)
handoff_path.write_text(handoff)


todo_path = Path('TODO.md')
todo = todo_path.read_text()
old = '  - [ ] **Step 3 retry — single artifact-only R-A gate** against that fresh package with no rebuild or source changes. A zero-selected filter is orchestration failure.\n'
new = f"""  - [x] **Step 3 retry attempt 2 — executed and FAILED organically** against exact `{SOURCE}` package `9164349848 / 9164350085`: run/job `{RUN_JOB}`, evidence `{RESULT_ID} / {LOG_ID}`; immutable preflight/static inventory/postflight PASS; **88 unique selected, 76 passed / 12 failed**, `orchestration_failed=0`. R-A remains open.
  - [ ] **R-A-TB2-CB-01 — expose and repair the aggregate derived-identity failure.** Make `rebuild_aggregate_output_identity_caches` report the exact failed invariant (typed outcome/diagnostic, not a generic bool-only rejection), reproduce the ordinary disconnected baseline failure, and repair the remapped canonical identity inputs. Do not skip the rebuild, accept an invalid identity, copy stale cache kind, or restore a second schema.
  - [ ] **R-A-TB2-CB-02 — restore final-oracle reachability after identity repair.** Require the raw-projection counterfactual, global-owner/cache positives, boundary authority negatives, missing component validation-report positive, and provenance-tamper negative to reach their declared aggregate/final-oracle seam. Preserve all zero-publication and issue-code assertions.
  - [ ] **R-A-TB2-CB-03 — remap component feature options into compact component-local vertex space.** The component runner currently copies global `featureMap.userHardEdges` / `userSoftEdges` unchanged into each compact component. Build original-to-local ownership mapping, retain only wholly owned edges, prove no cross-component leakage, and then restore the feature tamper / feature-bearing final-oracle contracts without synthesizing rails.
  - [ ] **R-A-TB2-CB-04 — regenerate the full R-A inventory and produce a fresh compile package.** Code + Build only; no generated runtime. The following turn retries the same immutable R-A semantic gate.
"""
if old not in todo:
    raise SystemExit('TODO Step 3 retry anchor not found')
todo_path.write_text(todo.replace(old, new, 1))


plan_path = Path('.agents/Directional/Architecture_M1_Single_Authority_Cutover_Code_Build_Plan.md')
plan = plan_path.read_text()
plan = re.sub(
    r'^\*\*Current status:\*\*.*$',
    '**Current status:** artifact-only R-A retry 2 against exact source `92bf0ae2b10856162f175d02aeac318e126f9d22` **FAILED organically** with 88 unique selected / 76 passed / 12 failed, immutable pre/postflight and static inventory PASS, zero orchestration failures; overall R-A remains open and returns to bounded section 0J Code + Build remediation',
    plan,
    count=1,
    flags=re.M,
)
section = f"""## 0J. Post-runtime R-A remediation after artifact-only retry 2

Artifact-only run/job `{RUN_JOB}` consumed exact source `{SOURCE}` compile package `9164349848 / 9164350085` without rebuild or mutation. Preflight, regenerated **19-path / 50-probe / 206-match** inventory, non-vacuous discovery, and immutable postflight passed. The continuous gate selected **88 unique contracts: 76 passed / 12 failed**, `orchestration_failed=0`. R-A remains open.

1. **R-A-TB2-CB-01 — diagnose and repair aggregate derived identity before final validation.** Ordinary disconnected aggregate positives and the new post-move authority contract now reach `component-merge-authority` instead of the former `optimization / MissingSourceAuthority`. The provenance-only counterfactual reports `InvalidGlobalDerivedIdentity` before its final-oracle mutation can be judged. `rebuild_aggregate_output_identity_caches` runs before the final validator and consumes completed-patch/output lineages plus global typed source authority; the counterfactual changes only `outputVertexProvenance`, which the rebuild does not read. Treat this as a baseline aggregate derived-identity blocker. Replace the opaque bool-only failure with a typed/diagnostic sub-invariant outcome sufficient for a regression test to identify the failing condition, then repair the canonical remap/rebuild input. Do not bypass the rebuild, weaken `canonical_authoritative_identity`, copy cached kinds, or construct a pipeline-local identity schema.
2. **R-A-TB2-CB-02 — make non-feature final-oracle contracts reachable after the identity repair.** The raw-projection counterfactual, global owner/cache rebuild positives, missing/remapped boundary authority negatives, missing component validation-report positive, and provenance-tamper negative must reach their intended aggregate/final-oracle seams naturally. Preserve exact issue-code and zero-publication assertions. Do not alter a fixture merely because an earlier production guard currently blocks it; first remove the proven baseline identity blocker.
3. **R-A-TB2-CB-03 — remap explicit feature-map edge options per compact component.** In the component runner, `RemeshOptions componentOptions = options;` is passed to `componentMesh`, whose vertices are compact-local. No remap is applied to `surfaceCells.featureMap.userHardEdges` or `userSoftEdges`, whose IDs originate in the global source mesh. Build an explicit global/original-to-local vertex map for each `FaceComponent`; retain and canonicalize only explicit edges with both endpoints owned by that component; drop edges belonging to other components. Add coverage with a hard/soft edge owned only by the second disconnected component and a no-cross-component-leakage negative. Then require `ComponentFeatureRailTamperRejectsAtAggregationSeam` and the feature-bearing/missing/content final-oracle contracts to reach their intended seams. Do not synthesize rails or mutate expected final authority after production.
4. **R-A-TB2-CB-04 — revalidate source and compile only.** Regenerate the complete R-A inventory and require PASS, then produce one fresh exact-source Release/static/Ninja/PRE_TEST package through `agent-compile-reusable.yml`. Execute no generated binary, discovery, test, benchmark, CLI, fuzzer, help/version command, or custom input.

Runtime-confirmed closure that should remain stable: retained completion authority **18/18**; optimizer/final-validator authority **8/8**; authority kernel **13/13**; isolation-seam **6/6**; source-authoritative validator **8/8**; rail-authority migration **7/7**; source-support/chart **1/1**. The aggregate authority-contract suite is the remaining blocker at **15/27**.

The following turn retries the same immutable R-A gate. R-A may close only after an organic pass with immutable pre/postflight and regenerated static inventory clean. No independent Review turn is requested.

"""
anchor = '## 0I. Post-runtime R-A remediation after artifact-only Step 3 attempt 1 — Code + Build complete\n'
if '## 0J. Post-runtime R-A remediation after artifact-only retry 2' not in plan:
    if anchor not in plan:
        raise SystemExit('plan 0I anchor not found')
    plan = plan.replace(anchor, section + anchor, 1)
plan_path.write_text(plan)


report_path = Path('.agents/Directional/Architecture_M1_RA_Closeout_Artifact_Only_Test_Benchmark_Report.md')
report = report_path.read_text()
report = report.replace('**Exact immutable source:** `64fa65a9379ad0a246393371516de3a3a7146243`', f'**Latest immutable source:** `{SOURCE}`', 1)
report = report.replace('**Compile package:** result `9162042615` / log `9162042971`', '**Latest compile package:** result `9164349848` / log `9164350085`', 1)
report = report.replace('**Runtime run/job:** `31652227682 / 94298883415`', f'**Latest runtime run/job:** `{RUN_JOB}`', 1)
report = report.replace('**Runtime result artifact:** `9163003523`, SHA-256 `d87293c864c2e17495017567ff0abbe7a40888b7af2e3479306e2b12e2241d74`', f'**Latest runtime result artifact:** `{RESULT_ID}`, SHA-256 `{RESULT_SHA}`', 1)
report = report.replace('**Runtime log artifact:** `9163003950`, SHA-256 `6125912547d698c4cb24175692f876609372b86729aa122bd2923e6e14cc6d28`', f'**Latest runtime log artifact:** `{LOG_ID}`, SHA-256 `{LOG_SHA}`', 1)
if '## 8. Artifact-only retry 2' not in report:
    report += f"""

## 8. Artifact-only retry 2 — organic aggregate failure after CB-00 through CB-04

**Date:** 2026-08-13 UTC  
**Exact source:** `{SOURCE}`  
**Compile package:** `9164349848 / 9164350085`  
**Runtime run/job:** `{RUN_JOB}`  
**Result artifact:** `{RESULT_ID}`, SHA-256 `{RESULT_SHA}`  
**Log artifact:** `{LOG_ID}`, SHA-256 `{LOG_SHA}`  
**Verdict:** **R-A NOT CLOSED — retry 2 failed organically.**

### 8.1 Immutable boundary

The retry downloaded the exact compile result and compile log artifacts by immutable artifact ID and verified both outer SHA-256 digests. Archive path/symlink safety passed; the package contained 26 regular files and zero symlinks; recursive self-excluding `SHA256SUMS` verified **25/25**; exact source was `{SOURCE}`; build exit was `0`; all five source-status snapshots were empty; `runtimeExecution=false` and `semanticContracts=compiled-not-executed` were preserved. The packaged R-A inventory regenerated byte-for-byte at **19 affected paths / 50 probes / 206 matches**, raw projection **22 allowed / 0 unexpected**, face-count leaves **2 / 0**, pipeline `stitchIdentity` assignments **2 / 0**, stitch-kind self-test **4/4**, final static **PASS**.

Discovery was non-vacuous: **13** authority-kernel, **232** producer, **179** completion, and **84** validation tests. Postflight again verified **25/25**, identical package path/mode/size state, unchanged executable hashes, and zero symlinks. `orchestration_failed=0`, `rebuild=false`, `sourceMutation=false`, `packageRepair=false`.

A preceding temporary workflow attempt (`31656834137 / 94313056707`) stopped before discovery or any packaged binary execution because its orchestration grepped obsolete inventory heading text. The corrected workflow changed only those preflight labels and reran the same package. That first attempt is infrastructure-only evidence and is not counted as a semantic gate attempt.

### 8.2 Runtime results

| Group | Selected | Result |
|---|---:|---|
| F4 direct final-oracle contracts | 3 | **0/3 — FAIL** |
| CB-01 post-move direct | 1 | **0/1 — FAIL** |
| CB-03 positive stitch direct | 2 | **2/2 — PASS** |
| CB-04 optimizer direct | 2 | **2/2 — PASS** |
| `SurfaceCellAuthorityKernel.*` | 13 | **13/13 — PASS** |
| `SurfaceCellAuthorityContractCutover.*` | 27 | **15/27 — FAIL** |
| `SurfaceCellIsolationSeamCertificateAuthority.*` | 6 | **6/6 — PASS** |
| retained completion authority | 18 | **18/18 — PASS** |
| `SurfaceCellSourceSupportAndChartAuthority.*` | 1 | **1/1 — PASS** |
| `SourceAuthoritativeMeshValidatorPhase22.*` | 8 | **8/8 — PASS** |
| retained optimizer/final-validator authority | 8 | **8/8 — PASS** |
| `SurfaceOptimizationRailAuthorityMigration.*` | 7 | **7/7 — PASS** |

The broad continuous gate selected **88 unique contracts: 76 passed / 12 failed**. Direct groups duplicate eight of those contracts and are diagnostic only. No zero-selected filter occurred. No standalone benchmark executable was run because the active R-A gate remains a semantic contract gate; the retained full-M1 benchmark plan is still dormant.

The 12 unique failures are all `SurfaceCellAuthorityContractCutover` contracts:

- `ProductionAggregationCounterfactualIgnoresPreConsumerRawProjectionTamper`
- `PostMoveAggregateOptimizerUsesRetainedSourceAuthority`
- `DisconnectedAggregationPublishesGlobalOwnerAndRebuildsIdentityCaches`
- `DisconnectedAggregationDoesNotPublishStalePreRemapIdentityCaches`
- `ComponentFeatureRailTamperRejectsAtAggregationSeam`
- `FinalMergedOracleRejectsMissingRemappedBoundaryAuthority`
- `FinalMergedOracleRejectsMissingRemappedFeatureAuthority`
- `FinalMergedOracleRejectsChangedRemappedBoundaryLoopContent`
- `FinalMergedOracleRejectsChangedRemappedFeatureRailContent`
- `FeatureBearingFinalMergedOracleAcceptsPresentRemappedFeatureAuthority`
- `FinalOracleOutcomePublishesWhenComponentValidationReportIsMissing`
- `FinalMergedOracleRejectsPostComponentProvenanceTamper`

### 8.3 Failure classification

**A — aggregate derived-identity blocker after the CB-01 transport fix.** The new post-move authority contract no longer reports `optimization / MissingSourceAuthority`; it advances to `NotProductionReady:component-merge-authority`. Ordinary disconnected aggregate positives and several final-oracle witnesses stop at the same stage. The provenance-only counterfactual provides the most specific retained diagnostic: it expected final-oracle rejection but instead reports `surfaceCellFirstInvalidProducerReason = InvalidGlobalDerivedIdentity`. In exact source, `rebuild_aggregate_output_identity_caches` executes before the final validator and consumes completed-patch/output lineages plus global typed source authority; the counterfactual mutates only `outputVertexProvenance`, which that rebuild does not read. Therefore the current evidence localizes the next blocker to the baseline aggregate derived-identity rebuild, not to the provenance tamper. The exact failing internal sub-check is not serialized; Code + Build must make that invariant diagnostic before correcting it rather than guessing or bypassing the rebuild.

**B — final-oracle boundary/report/provenance contracts are downstream of A.** Missing/changed boundary counterfactual callbacks report `reachedFinalOracleSeam=false`; the missing component validation-report positive and raw-projection counterfactual also fail on the ordinary aggregate baseline. These contracts must not be rewritten yet. First repair the proven derived-identity blocker, then confirm they reach the declared final-oracle seam with unchanged assertions.

**C — explicit feature options are not component-remapped.** `ComponentFeatureRailTamperRejectsAtAggregationSeam` now fails at stage `completion`, not at the aggregate seam; the feature final-oracle contracts likewise never reach the oracle. Exact source creates compact `FaceComponent` meshes and then copies `RemeshOptions componentOptions = options` without remapping `featureMap.userHardEdges` or `userSoftEdges`. Those edge IDs are expressed in the original global source vertex domain, so handing them unchanged to compact local component meshes is an ownership/domain error. The next Code + Build turn must remap explicit feature edges per component and prove no leakage, rather than fabricating rail authority in tests.

**D — CB-03 and CB-04 are runtime-confirmed.** All 18 retained completion authority contracts passed, including `CompatibleExactBoundaryKeyMergesWithTypedAuthorityCertificate` and `StitchingIsPatchOrderInvariant`. Both focused optimizer corrections passed, and the complete selected optimizer/final-validator set is **8/8**. Authority kernel, isolation seam, direct source validator, rail migration, and source-support/chart sets are also fully green. These areas are not current R-A blockers.

### 8.4 Regression accounting and next turn

No stable regression event or recurrence is added. `{SOURCE}` remains an unaccepted R-A candidate and this retry establishes no loss of accepted M1l behavior. Historical totals remain **34 events / 14 categories / 20 recurrences**.

**R-A remains open.** The mandatory next turn is bounded Code + Build section 0J: expose/repair the aggregate derived-identity invariant, restore non-feature final-oracle reachability, remap explicit hard/soft feature edges into each compact component-local domain, regenerate the full R-A inventory, and produce one fresh exact-source compile package without runtime execution. The following turn retries the same immutable R-A semantic gate.
"""
report_path.write_text(report)


changelog_path = Path('.agents/Directional/CHANGELOG.md')
changelog = changelog_path.read_text()
marker = '## [Unreleased]\n'
block = f"""
### Validation — R-A artifact-only retry 2 remains open at aggregate authority

- Immutable run/job `{RUN_JOB}` consumed exact `{SOURCE}` package `9164349848 / 9164350085` with no rebuild/source/test/fixture/package mutation. Result `{RESULT_ID}` SHA-256 `{RESULT_SHA}`; log `{LOG_ID}` SHA-256 `{LOG_SHA}`.
- Exact artifact/log digests, archive safety, manifest **25/25**, five empty source-status snapshots, regenerated **19-path / 50-probe / 206-match** static inventory, non-vacuous discovery, and immutable postflight all passed. **88 unique contracts selected: 76 passed / 12 failed; zero orchestration failures.**
- Completion remediation is runtime-green **18/18** and selected optimizer/final-validator authority is **8/8**. The remaining 12 failures are confined to aggregate authority contracts. Ordinary disconnected baselines now progress beyond the former optimization blocker and stop at `component-merge-authority`; the provenance-only counterfactual exposes `InvalidGlobalDerivedIdentity` before the final oracle. Explicit hard-feature aggregate tests additionally reveal that global user hard/soft edge options are copied unchanged into compact component-local meshes.
- A preceding temporary orchestration run `31656834137 / 94313056707` stopped before any packaged binary executed because it matched stale inventory heading text. It is not semantic evidence.
- R-A remains open; no stable regression accounting changes. Historical totals remain **34 / 14 / 20**, and M1l `bd140cff4572412e6f4ecd70a6ce0fe85310932c` remains immutable runtime authority.

"""
if '### Validation — R-A artifact-only retry 2 remains open at aggregate authority' not in changelog:
    changelog = changelog.replace(marker, marker + block, 1)
changelog_path.write_text(changelog)
