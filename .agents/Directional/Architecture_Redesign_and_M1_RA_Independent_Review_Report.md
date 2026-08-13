# Architecture Redesign and M1 R-A Independent Review

**Turn type:** independent Review; documentation changes only  
**Date:** 2026-08-12 UTC  
**Repository:** akashskypatel/Directional  
**Branch:** agent/surface_cell_quad/p5-recover-bridge-healing  
**Current independent-review branch boundary:** db100d15b166a2ac19bf2bb45c829856b43bb5a9  
**Current reviewed implementation/test source:** 9d88d0e47cfc039e5399ebee334290b1eeae792b  
**Review decision/planning commit:** _recorded at push of this documentation-only commit_  
**Entering immutable runtime authority:** M1l bd140cff4572412e6f4ecd70a6ce0fe85310932c  
**Latest independent-review verdict at source `9d88d0e...`:** **REV-21 contract completion and REV-22-through-REV-24 accepted at the Code + Build boundary; overall R-A rejected/open.**
**Post-review remediation status:** **RA-REV-22-F1/F2/F3 and RA-REV-23-F1 are Code + Build remediated / compile-valid at `032d4cbae9e2de2767579934682e78754180338d`; this is not an independent re-review or runtime acceptance.**
**Latest independent re-review verdict at source `032d4cbae9e2de2767579934682e78754180338d`:** **RA-REV-22-F1/F2/F3 and RA-REV-23-F1 are CLOSED at the Code + Build boundary. Three new follow-ups are opened (RA-REV-22-F4, RA-REV-22-F5, RA-REV-23-F2); all three must land in Code + Build before any Test + Benchmark turn, because R-A is one continuous checkpoint. Overall R-A remains rejected/open pending organic runtime execution.**
**Post-re-review remediation status:** **RA-REV-22-F4/F5 and RA-REV-23-F2 are Code + Build remediated / compile-valid at `64fa65a9379ad0a246393371516de3a3a7146243` with widened static inventory PASS and a fresh compile package; this is implementation/build evidence, not a new independent review or runtime acceptance.**
**Latest independent re-review verdict at source `64fa65a9379ad0a246393371516de3a3a7146243`:** **RA-REV-22-F4, RA-REV-22-F5, and RA-REV-23-F2 are CLOSED at the Code + Build boundary. The R-A contract set is complete; no finding blocks the Test + Benchmark gate. Two deferred hygiene items are recorded (RA-REV-23-F3, RA-REV-22-F6) and are explicitly post-R-A backlog. Overall R-A remains rejected/open pending organic runtime execution.**

## Independent review addendum — RA-CB-F1 through RA-CB-F5 pre-runtime readiness

Reviewed at implementation `38d8d7d3e97f3b496e63979cb1348ed2cda304bc`. The compile-pinned source `555109796188b318c788ef5777f622705ee0aa94` is **byte-identical** to it and to branch head `58e9150` across `src`, `include`, `tests`, `.github`, the audit script, and the audit report, so the head is a valid review proxy. Compile run `31665352874` (head_sha `610164ac`) passes `source_sha: 5551097961` into `agent-compile-reusable.yml`, which asserts checkout equality before archiving. Documentation-only turn; the only command executed was the source-only static audit.

**Decision: RA-CB-F1 through RA-CB-F5 are all CLOSED at the Code + Build boundary. One durable-document defect must be corrected before the retry starts, because it would make preflight fail on a correct package.**

### Verified closures

| Finding | Verdict | Evidence |
|---|---|---|
| RA-CB-F1 | **closed** | replaced by `PostMoveSingleComponentOptimizerUsesRetainedSourceAuthority`, which drives `remesh_from_raw_cross_field` on `make_square_mesh()` — the non-aggregate entry, where the published optional **is** the `:6210` retained copy — and asserts `sourceTopologyRegions.has_value()` plus `surfaceCellFirstInvalidProducerReason != "MissingSourceAuthority"`. The old aggregate-gated name is gone from the tree and the inventory probe is repointed to the new one. Both corrective measures taken. |
| RA-CB-F2 | **closed as a carry-forward** | the T+B plan now carries a per-contract reason-capture amendment. It is more careful than I asked: it records that `CoincidentPositionsOnDistinctTypedSheetsDoNotMerge` is a *successful non-merge* contract and must be evidenced as `success=true`, two components, `mergedBoundaryVertices=0` "rather than inventing a failure string", while `WrongOwnerSheetCertificatePublishesNothing` must carry `InvalidTypedStitchAuthority` and `SameExactBoundaryKeyRejectsIncompatibleTypedLineage` must carry `IncompatibleTypedStitchAuthority`. That distinction is correct and avoids fabricating a rejection reason for a contract that is not a rejection. |
| RA-CB-F3 | **closed** | `SameRegionSheetDifferentCompletedSupportsRejectTypedStitchCompatibility` pre-asserts the two source rows share region **and** sheet, drives both patches through `complete_pure_quad_patch` rather than hand-building lineages, pre-asserts equal published region/sheet with `EXPECT_NE` on `sourceSupport`, and requires the assembly to fail closed with `IncompatibleTypedStitchAuthority` publishing no vertices or quads. This is exactly the production-path discrimination negative the finding required, and it directly answers whether the CB-03 chart-closure broadening made compatibility vacuous. |
| RA-CB-F4 | **closed** | both measures taken. The anti-stale contract now `ASSERT_EQ`s the boundary cache extent, `ASSERT_TRUE(identity.valid)`, and `EXPECT_EQ(lineage->stitchIdentity.canonical, identity)` per boundary node, so an empty identity can no longer satisfy it; and `EXPECT_GT(rebuildCount, 0U)` became `EXPECT_EQ(completedPatches.size(), rebuildCount)`, which is exact accounting rather than a presence check. |
| RA-CB-F5 | **closed, and stronger than specified** | `make_component_feature_option_remap_plan` canonicalizes requests, resolves a **unique** owning component per edge, and — beyond what I asked — requires the candidate local edge to exist in that component's actual face edges rather than merely having both endpoints present, which closes a hole I had not identified. Multi-owner resolution is detected as `ambiguous` and counted unassigned. Requested/remapped/unassigned counts and the first unassigned edge are published as typed diagnostics, and an unassigned **hard** edge fails the run closed at stage `component-feature-remap` with `UnassignedUserHardFeatureEdge` and zero publication. Soft edges are recorded but non-fatal, which is the right asymmetry for advisory input. |

The static inventory reproduces byte-for-byte from the current tree, exit `0`: **19 paths / 59 probes / 261 matches**, raw projection 22/0, face-count 2/0, pipeline `stitchIdentity` 2/0, classifier self-test 4/4, final static **PASS**.

### RA-CB-F6 — the handoff's preflight requirement states an inventory match count the package cannot produce

**Blocking for the retry as written. Documentation-only fix.**

**Evidence**

- `Future_Chat_Session_Handoff.md:39` instructs the T+B turn to verify "the regenerated R-A inventory is **19 paths / 59 probes / 245 matches**", and `:64` repeats **245** as the fresh static evidence.
- The committed `R_A_Closure_Inventory_Report.md` records **261** probe matches, and my independent regeneration from the current tree is byte-identical to it at **261**. The same report at the compile-pinned source `5551097961` also records **261**.
- The audit script, audit report, and every scanned path are identical between `5551097961` and the head, so the packaged inventory inside artifact `9167759672` will regenerate at **261**, not 245. Probe count (59) and path count (19) are correct; only the match count is wrong.
- Consequence: a T+B turn following the handoff literally must treat a **correct** package as a preflight mismatch. That either stalls the retry or pressures the turn into waving through a documented discrepancy — the exact failure mode this project's preflight discipline exists to prevent.

**Corrective measures**

1. Correct both occurrences to **261** before the retry begins. This is a durable-document edit only; no source, package, or artifact is affected, and no recompile is required.
2. In the retry report, record the regenerated counts verbatim from the packaged inventory rather than transcribing them from the handoff.

### Readiness verdict

The five findings are genuinely resolved, and two of them (F3, F5) are implemented more strictly than the corrective measures required. I found no weakened check introduced by this change: F5 *adds* a fail-closed, F4 *tightens* two assertions, F3 *adds* a negative, and F1 replaces a mislabeled contract with one that observes the intended object.

**The candidate is ready for the artifact-only retry once RA-CB-F6 is corrected.** No source change is needed for that correction, so the existing package `9167759672 / 9167759825` from `5551097961` remains the valid runtime candidate. RA-REV-23-F3 and RA-REV-22-F6, and the T+B report-structure scoping item, remain post-R-A hygiene.

M1l `bd140cff4572412e6f4ecd70a6ce0fe85310932c` remains immutable runtime authority. Regression totals remain **34 / 14 / 20**.

## Independent review addendum — R-A-TB-CB-00 through CB-04 re-evaluated against retry-2 runtime evidence

This Review re-baselined on branch head `9f27a7d`. The retry-2 remediation landed as `a6723f34707701fc1174c0889028327ff8666c9a`; `git diff a6723f34..HEAD -- src include tests .agents/Directional/R_A_Closure_Inventory.py` is empty, and the source pinned by the new compile package, `f6514a0f8496bd18aacfceb419e2e5ae5b3b6fae` ("chore: remove R-A retry2 apply payload", three commits later), is **byte-identical on all implementation, test, and audit paths**. So `R-A-TB2-CB-01` through `R-A-TB2-CB-04` at `f6514a0f` are exactly the `a6723f34` changes reviewed here, and the branch head is a valid review proxy for both. The static inventory at this head reproduces byte-for-byte at **54 probes / 226 matches / PASS**.

This addendum covers the original CB-00 through CB-04 *as judged by retry-2 runtime evidence*, plus the TB2 remediation that now sits on top of CB-01. Documentation-only turn; the only command executed was the source-only static audit and direct inspection of the audit script's classifiers.

**Decision: CB-01, CB-03, and CB-04 are now RUNTIME-CONFIRMED. CB-00's reasoning is runtime-vindicated. CB-02 is not yet provable and correctly deferred. Two findings from the previous review are resolved or escalated by the runtime evidence, and two new findings are opened against the retry-2 remediation. R-A remains open.**

### Correction to my own reading

On first pass I misread this report's structure and briefly concluded retry 2 had re-run the pre-fix package. That was wrong. Sections 1-7 are the retained attempt-1 record; the retry is section 8, and its 8.1 boundary correctly records exact source `92bf0ae`, package `9164349848 / 9164350085`, the **50-probe / 206-match** inventory, and 232 producer tests — all matching the CB package, not the old one. The retry is authentic.

One real hazard remains from that structure: the document's top header block was overwritten with "Latest …" values while sections 1-2 still describe attempt 1, so the header sits directly above preflight text that verifies the *superseded* digest `c521a94e…` and source `64fa65a…`. Section 4 also repeats the attempt-1 Class A text verbatim, including the `phaseFrontProduct != nullptr` diagnosis this review already rejected and line numbers that no longer mean what they did. **Corrective measure:** scope each section's header to its own attempt and mark sections 1-7 explicitly retained/superseded, so a future turn cannot lift the stale Class A narrative as current.

### Checkpoint re-evaluation

| Item | Prior verdict | Verdict on runtime evidence |
|---|---|---|
| CB-00 | accepted (source inspection only) | **vindicated** — the symptom moved off `optimization / MissingSourceAuthority`, which the use-after-move reading predicted and the null-guard reading did not |
| CB-01 | accepted by inspection | **runtime-confirmed** — the transport blocker is gone |
| CB-02 | accepted, verification pending | **not yet provable; correctly deferred** — final-oracle contracts now fail downstream of a different blocker |
| CB-03 | accepted, discrimination unproven | **runtime-confirmed** — 18/18 completion contracts pass, including both former `IncompatibleTypedStitchAuthority` positives |
| CB-04 | accepted | **runtime-confirmed** — 2/2 direct, optimizer/final-validator set 8/8 |
| Overall R-A | open | **open** — 76/88, twelve `SurfaceCellAuthorityContractCutover` failures remain |

The gate moved from 61/87 to 76/88 with no weakening of any strict check I can find. Attempt 1's Classes B, C, and D are now closed by runtime; the residue is a single new blocker plus its downstream contracts.

### Resolved and escalated prior findings

- **RA-TB-F1 (my correction of the Class A root cause) is runtime-vindicated.** CB-01 was written to my reading, and `MissingSourceAuthority` at stage `optimization` disappeared. Had the original null-guard diagnosis been implemented instead, the branch added for a case that never fires would have changed nothing.
- **RA-CB-F1 is escalated from "should fix" to "actively misleading."** `PostMoveAggregateOptimizerUsesRetainedSourceAuthority` **failed** in retry 2 *even though CB-01 is correct*, exactly as predicted: it gates on aggregate `result.success` and asserts on the merge-built global owner from `RemeshPipeline.cpp:11497`, not the per-component `:6210` copy it is named for. It is now a red signal attributable to an unrelated blocker, on a contract pinned by an inventory probe. Fix it as previously specified — drive `remesh_from_raw_cross_field` on a single connected mesh — before the next retry, so its colour means something.
- **RA-CB-F2 was not honored.** The retry did not record per-contract rejection reasons for the three faces-only completion negatives (`CoincidentPositionsOnDistinctTypedSheetsDoNotMerge`, `WrongOwnerSheetCertificatePublishesNothing`, `SameExactBoundaryKeyRejectsIncompatibleTypedLineage`). They are inside the 18/18 pass, but a pass does not establish that a negative rejected for its intended reason. Carry the requirement into the next retry.
- **RA-CB-F3's trigger condition has fired.** Both `IncompatibleTypedStitchAuthority` positives are green, which is the case in which I said the production-path discrimination negative becomes required before R-A closes. Still unaddressed.

### RA-CB-F4 — the boundary-identity cache relaxation is sound, but its anti-stale contract no longer proves what it reads

**Non-blocking.**

**Evidence**

- `rebuild_aggregate_output_identity_caches` previously rejected when `patch.boundaryNodeIdentities.size() != patch.boundaryVertices.size()`. It now counts that case into `surfaceCellAggregateIdentityBoundaryCacheRebuildCount` and unconditionally executes `patch.boundaryNodeIdentities.assign(patch.boundaryVertices.size(), {})`.
- The relaxation itself is **justified**: every entry is then refilled from `patch.vertexLineage[row->second].stitchIdentity.canonical`, with a fail-closed `AggregateIdentityInvalidPatchBoundaryVertex` when the local vertex is absent. Requiring a pre-existing cache of final extent demanded an input the authoritative materializer legitimately does not produce. It is also monitored — `EXPECT_GT(...BoundaryCacheRebuildCount, 0U)` proves the path is exercised — and pinned by a probe. The wider conversion of `return false` into typed `AggregateIdentity*` sub-invariants with patch/vertex/face indices is a real diagnostic improvement, and `AggregateIdentityRebuildReportsInvalidPatchMetadataSubInvariant` proves the reporting works.
- The residue is in the REV-23 anti-stale contract. `DisconnectedAggregationDoesNotPublishStalePreRemapIdentityCaches` (`SurfaceCellsPhase10Tests.cpp:5387-5389`) still asserts only `EXPECT_NE({staleToken}, identity.values)` on boundary node identities. Now that the cache is wiped and refilled unconditionally, that assertion is also satisfied by an **empty or invalid** identity. The contract reads as "stale caches are replaced by canonical ones" but now only proves "the stale token is absent."

**Corrective measures**

1. In that contract, additionally require each boundary identity to be valid and to equal the canonical of its corresponding lineage — the same equality already asserted for `vertexLineage`.
2. Assert the boundary-cache rebuild count is consistent with the fixture rather than merely non-zero, so a future regression that wipes more caches than expected is visible.

### RA-CB-F5 — component feature-edge remap can silently drop user authority

**Non-blocking, but this is authority loss, not fixture noise.**

**Evidence**

- `remap_component_surface_cell_feature_options` (`RemeshPipeline.cpp:8562-8590`) maps each global user hard/soft edge into compact component-local indices and `continue`s — silently dropping the edge — when either endpoint is not in the component.
- Dropping is correct for an edge belonging to a different component. It is **not** distinguishable from an edge that belongs to no component at all, one whose endpoints straddle two components, or one referencing a stale vertex id. In every such case a user-specified hard feature vanishes with no diagnostic and no failure.
- `ComponentFeatureOptionsRemapOwnedEdgesWithoutCrossComponentLeakage` proves the two directions that matter for leakage — foreign edges do not appear, owned edges do — but nothing proves **conservation**: that the union of remapped edges across all components accounts for every global user edge.
- This matters because hard-feature authority is exactly what the F4 feature contracts depend on. A silently dropped rail would present as a fixture-adequacy failure at the far end of the pipeline, which is the hardest failure mode to attribute correctly.

**Corrective measures**

1. Count dropped edges into a typed diagnostic and assert conservation: every global user hard/soft edge is either remapped into exactly one component or explicitly accounted as unassigned.
2. Fail closed, or surface a typed reason, when a user-specified hard edge is assigned to no component — a user asked for a feature that the run will not honor.
3. Extend the no-leakage contract with a conservation assertion over the union.

### Review conclusion

The remediation is converging on real defects and the runtime numbers reflect genuine progress, not weakened checks. The one relaxation in this change (boundary-cache extent) is justified, monitored, and paired with a complete authoritative refill.

Before the next retry, land RA-CB-F1 so the CB-01 regression contract stops reporting an unrelated blocker. Carry RA-CB-F2 into the retry as a reporting requirement. RA-CB-F3, RA-CB-F4, and RA-CB-F5 must land before R-A is declared complete. Report-structure scoping (above) should be fixed when the T+B report is next touched, so the superseded Class A narrative cannot be re-adopted.

M1l `bd140cff4572412e6f4ecd70a6ce0fe85310932c` remains immutable runtime authority. Regression totals remain **34 / 14 / 20**.

## Independent review addendum — R-A artifact-only Step 3 failure analysis

This Review inspected the artifact-only Test + Benchmark report `Architecture_M1_RA_Closeout_Artifact_Only_Test_Benchmark_Report.md` and the exact runtime candidate source `64fa65a9379ad0a246393371516de3a3a7146243` against which it ran. Documentation-only turn; no configure, compile, generated binary, discovery, test, benchmark, `ctest`, CLI, fuzzer, or custom input executed.

**Decision: the gate result (R-A NOT CLOSED, 61/87 passed, zero orchestration failures) is accepted as authentic runtime evidence. The Class A root-cause diagnosis is REJECTED as incorrect, and its corrective measure R-A-TB-CB-01 is rewritten. Classes B, C, and D are accepted, with one sequencing correction to Class C.**

### What the gate established

The turn boundary is sound and its negative result is trustworthy. Preflight verified the outer digest, 26 files, manifest 25/25, exact packaged source, five empty status snapshots, and `runtimeExecution=false`; the packaged inventory regenerated byte-for-byte at 48 probes / 203 matches / self-test 4/4 / PASS; postflight re-verified 25/25 with matching path/mode/size and executable hashes. Discovery was non-vacuous in every group and `orchestration_failed=0`. No rebuild or source mutation occurred. The failure is organic and correctly refused promotion of the candidate.

Class D is confirmed by the numbers: authority kernel 13/13, isolation seam 6/6, source-authoritative validator 8/8, rail-authority migration 7/7, source support/chart 1/1. The typed-ID kernel and the direct validator — the subjects of REV-21 and REV-24 — are runtime-sound. The blocker is above them, in pipeline transport.

### RA-TB-F1 — the Class A root cause is misidentified; the stated fix would not fix it

**Evidence**

- The report states the pipeline "assigns `constraints.sourceAuthority = &phaseFrontProduct->sourceTopologyRegions` only when `phaseFrontProduct != nullptr`", concluding that aggregate paths "may have an authoritative global owner without that object". That is not the mechanism that fires.
- `phaseFrontProduct` is captured at `RemeshPipeline.cpp:6191-6192` as a raw pointer into the **local** `traceNetwork`. At `:6414` the pipeline executes `result.surfaceCellContext.traceNetwork = std::move(traceNetwork);` unconditionally on every path that continues past tracing.
- Moving a `std::variant` move-constructs the contained alternative into the destination and leaves the source holding a moved-from value **of the same alternative**. So after `:6414`, `phaseFrontProduct` is still non-null and `produced_product()` still reports Produced — but `phaseFrontProduct->sourceTopologyRegions` is a moved-from `SourceTopologyRegions` whose row-topology, component, sheet, and region vectors are empty.
- Every consumer therefore receives a present-but-empty owner. `matches_source_faces` compares an empty topology against a non-empty face matrix and returns false, so `source_optimization_has_complete_authority` (`SurfaceMeshOptimizer.cpp:1829-1849`) fails and `RemeshPipeline.cpp:7874-7880` reports `MissingSourceAuthority` at stage `optimization`. **That is exactly the observed symptom, produced by a non-null pointer.**
- The null guard the report blames is never the discriminator on these paths. Consequently the proposed remedy — supply the owner "independently of whether a `phaseFrontProduct` object happens to be present" — adds a branch for a case that does not occur, leaves the empty-owner read in place, and the same 26 contracts fail again.
- This is not confined to the optimizer. **Five** sites read `phaseFrontProduct->sourceTopologyRegions` after the move at `:6414`: `:6623` (arrangement arcs), `:6674` (arrangement options), `:6918`, `:7352` (source-quad recovery), and `:7758` (optimizer constraints). All five silently consume an empty owner, which plausibly accounts for far more of the 26 failures than the single optimizer stage the report names.
- The correct owner already exists and was created for precisely this purpose. `RemeshPipeline.cpp:6206-6211` copies the authority into `result.surfaceCellContext.sourceTopologyRegions` **before** the move, under the comment "Preserve the independently validated typed source-authority domain … even when the heavyweight trace network is released later in this pipeline execution." Nothing between `:6210` and `:7758` resets it — the only `surfaceCellContext = SurfaceCellPipelineContext{}` resets are at `:10309` and `:10432`, inside the aggregate merge function — and both lines are in the same function body, `remesh_from_raw_cross_field_impl` (opens at `:5662`). The retained copy is a stable, checked, exact owner with full pipeline lifetime.
- Severity note: this is a latent use-after-move that predates R-A and was benign only while typed authority was optional. R-A made it mandatory, so the first strict runtime execution exposed it. It is a production defect, not a fixture defect.

**Corrective measures — these replace R-A-TB-CB-01 as written**

1. Replace all five post-move reads of `phaseFrontProduct->sourceTopologyRegions` (`:6623`, `:6674`, `:6918`, `:7352`, `:7758`) with the retained copy `result.surfaceCellContext.sourceTopologyRegions`, passing `&result.surfaceCellContext.sourceTopologyRegions.value()` when the optional is engaged and `nullptr` otherwise. This is not a fallback reconstruction and not a weakening: it reads the same checked construction the phase front itself consumed, which is why the copy exists.
2. Do not add a null-`phaseFrontProduct` branch as the fix. Keep `source_optimization_has_complete_authority` and the `:7874-7880` fail-closed exactly as they are — they behaved correctly and caught a real defect.
3. Stop the class, not just the instances: after `:6414`, do not read through `phaseFrontProduct` at all. Either null the local pointer immediately after the move, or re-derive it from `result.surfaceCellContext.traceNetwork.phaseFront.produced_product()` — noting that this re-derived pointer is itself invalidated when the network is cleared at `:6427`, `:6436`, and `:6466` under `!retainForExecution`, so the retained `sourceTopologyRegions` copy remains the only lifetime-safe owner past that point.
4. Add a regression contract that fails on the empty-owner path specifically: assert that a successful SurfaceCells run publishes `sourceTopologyRegions` whose `matches_source_faces` holds against the same source matrices handed to the optimizer. A test asserting only "optimization did not fail" would pass again for the wrong reason.
5. **Cheap decisive confirmation before writing code, from evidence already in hand:** the two candidate mechanisms are distinguishable in the existing runtime log artifact `9163003950`. `surfaceCellTopologyRegionCount` is recorded at `:6212`, before the move. Under the report's mechanism `phaseFrontProduct` is null and that count is `0`; under the mechanism above it is non-null and the count is non-zero while optimization still reports `MissingSourceAuthority`. Read that field first and record which reading it supports. This costs one artifact inspection and prevents a wasted Code + Build cycle.

### RA-TB-F2 — Class C sequencing would silently drop a contract

**Evidence**

- Class C directs that `SurfaceMeshOptimizerPhase19.TriangleProjectionFailsClosedWhenRequiredSheetIsUnavailable` "is obsolete" and must be replaced by a typed-authority mutation. The reasoning is sound — R-A deliberately removed raw `SurfacePoint.sheet` as semantic authority, and `GenericMeshValidationIsInvariantToRawProjectionSheetLabels` passing in the same gate is positive evidence that the invariance is intended.
- But "obsolete" is a claim about the *old* expectation, not evidence that the *new* guard exists. If the replacement is written after the old test is deleted, and the typed mutation turns out not to be rejected either, the project loses a fail-closed contract and the audit will not notice: no inventory probe pins this contract.

**Corrective measures**

1. Write the typed-authority negative first and require it to fail closed for the intended reason, then remove the raw-sheet expectation in the same change. Never delete first.
2. Add an inventory probe pinning the replacement contract by name, so a future deletion is caught statically.

### Accepted without change

- **Class B (completion).** Fixture-adequacy failures before the intended seam, and the two positive assemblies rejecting with `IncompatibleTypedStitchAuthority`, are correctly separated into fixture work and implementation diagnosis. The instruction not to restore aliases, fabricated IDs, or pre-intersection identity is correct and must hold. One caveat: several of these are downstream of RA-TB-F1, so re-triage them **after** the transport fix rather than rebuilding fixtures against a pipeline that is handing out empty owners.
- **Class C, rail-builder half.** `RailConstraintBuilderUsesOutputVertexSequencesForBoundaryAndFeatures` omitting the exact source matrices is a genuine fixture gap; supplying them without relaxing the production scope check is right.
- **Regression accounting.** Assigning no new stable regression event is correct: the candidate is unaccepted and no loss of accepted M1l behavior is established. Totals stay **34 / 14 / 20**.

### Effect on the R-A closeout sequence

R-A returns to Code + Build. The corrected order is: confirm the mechanism from artifact `9163003950` (RA-TB-F1 measure 5), fix the authority transport, **re-run triage on Classes B and C against the fixed pipeline before rebuilding any fixture**, then regenerate the inventory and compile one fresh exact-source package, then retry the same immutable artifact-only gate. RA-REV-23-F3 and RA-REV-22-F6 remain post-R-A hygiene and are not implicated in any failure here.

M1l `bd140cff4572412e6f4ecd70a6ce0fe85310932c` remains immutable runtime authority.

## Independent re-review addendum — RA-REV-22-F4/F5 and RA-REV-23-F2 closure

This Review inspected exact implementation/test/audit source `64fa65a9379ad0a246393371516de3a3a7146243`. `git diff 64fa65a..HEAD -- src include tests .agents/Directional/R_A_Closure_Inventory.py` is empty, so the branch head is a valid review proxy. Documentation-only turn; the only command executed was the source-only static audit plus direct interrogation of the audit script's classifier functions. No configure, compile, generated binary, discovery, test, benchmark, `ctest`, CLI, fuzzer, or custom input ran.

**Decision: all three follow-ups are CLOSED at the Code + Build boundary. The R-A implementation is complete end to end. The single artifact-only Test + Benchmark gate is now unblocked and is the only remaining R-A action.**

### Checkpoint decision

| Checkpoint | Decision | Evidence-based reason |
|---|---|---|
| RA-REV-22-F4 | **closed at Code + Build** | both content negatives keep authority present and defeat the presence guard, so the oracle's content comparisons actually fire; the positive witness observes non-empty feature authority; all three assert their preconditions |
| RA-REV-22-F5 | **closed at Code + Build** | both flagged option-echo `EXPECT_TRUE`s are removed from the positive and from the F3 contract; the falsifiable published-vs-oracle equalities remain |
| RA-REV-23-F2 | **closed at Code + Build** | the classifier is whole-statement, translation-unit-wide, and verified *discriminating* — it flags the realistic reintroduction form and does not flag legitimate `.kind` writes |
| Overall R-A | **rejected / open** | implementation complete, but still only compile and static evidence; every contract remains compiled-not-executed |

### Verified closures

- **Exact source and package.** The tree matches `64fa65a…` exactly for `src`, `include`, `tests`, and the audit script. Compile run `31649372167` has `head_sha` `2c08580e…`, whose caller passes `source_sha: 64fa65a9379ad0a246393371516de3a3a7146243` into `agent-compile-reusable.yml`, which checks out that ref and asserts equality before archiving; the delta between the two commits is empty for all implementation, test, build, and audit paths. Package `9162042615 / 9162042971` is the correct runtime candidate.
- **Static inventory reproduced.** `python3 .agents/Directional/R_A_Closure_Inventory.py --root .` is **byte-for-byte identical** to the committed report (zero diff lines), exit `0`: 19 paths, 48 probes, 203 matches, 22/0 raw-projection leaves, 2/0 face-count leaves, 2/0 pipeline `stitchIdentity` assignments, classifier self-test 4/4, final static **PASS**.
- **RA-REV-22-F4 — boundary content.** `FinalMergedOracleRejectsChangedRemappedBoundaryLoopContent` (`SurfaceCellsPhase10Tests.cpp:5552`) substitutes one vertex of aggregate loop 0 with a vertex drawn from loop 1 — a different component — guards that the substitute is not already present, and then **rebuilds `authoritativeBoundaryEdges` from the mutated loops**. That rebuild is what makes the test meaningful: the authority set stays non-empty, so `MeshValidator.h:178` does not fire, and rejection must come from the content path. The mutated loop contributes edges that do not exist in the merged output, so `MeshValidator.h:212-216` raises `ChangedBoundaryLoop`, and `SourceAuthoritativeMeshValidator.cpp:1097-1107` independently fails `actualLoops == expectedLoops`. Both preconditions are `ASSERT_TRUE`, so the test cannot pass vacuously.
- **RA-REV-22-F4 — feature content.** `FinalMergedOracleRejectsChangedRemappedFeatureRailContent` (`:5608`) latches `reachedFinalOracleSeam` on `rails.size() == expectedFeatureRailCount`, then replaces one rail with a vertex pair spanning the two disconnected components. Cardinality is preserved, so the `:1119` count check still passes and rejection must come from the per-rail `outputEdges.count(...)` check at `:1124-1130` → `MissingFeatureRail`. This is the exact content guard the finding named as unexercised.
- **RA-REV-22-F4 — diagnostics.** `RemeshDiagnostics.h:251` adds `surfaceCellFinalSourceAuthorityValidationIssues`, populated at `RemeshPipeline.cpp:11533-11539` *after* `reject_merge_authority` (which does not touch the vector) and only on the final-oracle rejection path; `merged` is default-constructed and no other site writes it, so other rejection reasons leave it empty. Both content negatives assert the expected code is present **in the full list**, so the preferred-code selection at `:11545-11557` can no longer stand in for guard evidence.
- **RA-REV-22-F4 — feature-bearing positive.** `FeatureBearingFinalMergedOracleAcceptsPresentRemappedFeatureAuthority` (`:5664`) reuses the counterfactual entry with a **read-only observer**, asserting `expectedFeatureRailCount > 0`, matching cardinality, and every rail of size ≥ 2 before accepting. `authoritativeFeatureRailsPassed` now carries real rail evidence rather than the vacuous `0 == 0`.
- **RA-REV-22-F5.** `EXPECT_TRUE(finalValidation.strictValidationUsed)` and `EXPECT_TRUE(finalValidation.authoritativeFeatureRailsUsed)` are gone from the positive, and the matching `oracle.strictValidationUsed` / `oracle.featureRailAuthorityUsed` assertions are gone from the F3 contract. The five `EXPECT_EQ` published-vs-oracle cross-checks and the input-derived `boundaryAuthorityUsed` remain.
- **RA-REV-23-F2 — verified by direct interrogation, not by reading the diff.** I called `_pipeline_stitch_kind_assignment_matches` on cases outside the committed self-test set:

| Case | Result |
|---|---|
| `geometry::PureQuadStitchIdentity result;` + `result.kind = cached.kind;` — the realistic duplicate-builder reintroduction | **FLAGGED** |
| `equivalence.kind = geometry::PureQuadEquivalenceKind::HardRail;` (real code, `RemeshPipeline.cpp:2596`) | correctly not flagged |
| `lineage.kind = geometry::PureQuadVertexLineageKind::SourceTriangle;` (real code, `:2859`) | correctly not flagged |
| `rail.kind = ordered[...].kind;` (real code, `:3402`) | correctly not flagged |

  The classifier is therefore discriminating, not degenerate: it catches the defect form while leaving the six legitimate `.kind` writes in `src/pipeline` unflagged, which the inventory confirms as 0 unexpected. Defense in depth is also real — `classify_pipeline_stitch_identity_assignments` now flags **every** `stitchIdentity.<member> =` write unconditionally and every whole `stitchIdentity =` assignment outside `rebuild_aggregate_output_identity_caches`, so any reintroduced builder must eventually surface at one of those writes.
- **Control-plane cleanup.** `.agents/Directional/turn-payloads/`, `.agents/connector-triggers/`, and every temporary `agent-ra-rev22-*` / restore workflow are absent from the tree, per `CLEAN_UP_POLICY.md`.

### RA-REV-23-F3 — deferred: the audit documents a pattern it does not execute

**Not blocking. Post-R-A hardening backlog; do not gate the Test + Benchmark turn on it.**

**Evidence**

- `matches_for` dispatches to the structural classifier by **probe-name string equality** (`R_A_Closure_Inventory.py:279`, `if probe.name == "pipeline stitch-kind assignment is structurally absent"`). The declared `Probe.pattern` for that probe is never compiled or run.
- `R_A_Closure_Inventory_Report.md:638` nevertheless prints `Pattern: stitchIdentity\s*(?:\.|->)\s*kind|(?:\w+::)*PureQuadStitchIdentityKind`. An independent auditor reproducing the audit from the report would validate a regex that did not execute — the same conclusion-only defect the REV-18-through-REV-21 review objected to, in a narrower form.
- Renaming the probe silently reverts it to that weaker line-oriented regex with no failure, because the dispatch key is prose.
- The self-test carries only positive cases (`:497-524`). 4/4 passing cannot distinguish a correct classifier from one that flags every `.kind =` write; I established discrimination separately, but the audit does not establish it about itself.
- Residual classifier misses I probed and confirmed: `auto result = build_key(); result.kind = cached.kind;` and designated-initializer construction. Both are backstopped by the whole/member `stitchIdentity` assignment classifier and by the runtime `EXPECT_EQ(canonical_lineage_stitch_identity(patch, row), lineage.stitchIdentity)` contracts, so they are recorded for completeness rather than as exposure.

**Corrective measures**

1. Dispatch on an explicit `Probe` field (for example `classifier=_pipeline_stitch_kind_assignment_matches`) instead of the probe name, and render the executed classifier's identity in the report in place of a pattern that did not run.
2. Add at least one negative self-test case — a legitimate non-stitch `.kind` write that must **not** be flagged — so the audit proves discrimination, not just detection.
3. Optionally add the two residual forms above as self-test cases once measure 1 makes the classifier the documented contract.

### RA-REV-22-F6 — deferred: two same-class option-echo assertions remain

**Not blocking. Post-R-A hardening backlog.**

**Evidence**

- `EXPECT_TRUE(oracle.provenanceValidationUsed)` and `EXPECT_TRUE(oracle.sourceAuthorityUsed)` remain in the F3 contract (`SurfaceCellsPhase10Tests.cpp:5798-5799`) and the feature-bearing positive. `SourceAuthoritativeMeshValidator.cpp:1037` and `:1041` set both unconditionally immediately after the entry guard, and publication only occurs when the oracle accepted, so neither assertion can fail.
- These are the same class as the two RA-REV-22-F5 removed; the finding named `:1041` explicitly. Severity is low — they are documentation assertions sitting beside falsifiable ones, not evidence substitutes.

**Corrective measures**

1. Drop both assertions, or take RA-REV-22-F5's second option and set `strictValidationUsed`, `provenanceValidationUsed`, and `featureRailAuthorityUsed` at the point each gate actually executes, which would make every usage flag falsifiable at once and close this class permanently.

### Review conclusion

The R-A implementation is complete. Every finding raised across REV-21 through RA-REV-23-F2 is closed at the Code + Build boundary, the widened static inventory is reproducibly PASS, and a verified exact-source compile package exists. **Nothing further is owed to R-A before runtime.**

The only remaining R-A action is the single immutable artifact-only Test + Benchmark gate on package `9162042615 / 9162042971`, specified in the handoff. RA-REV-23-F3 and RA-REV-22-F6 are audit and test-hygiene items that do not affect any semantic contract and must not be used to defer that gate; schedule them with R-B or later.

M1l `bd140cff4572412e6f4ecd70a6ce0fe85310932c` remains immutable runtime authority. Regression totals remain **34 events / 14 categories / 20 recurrences**.

## Post-re-review remediation addendum — RA-REV-22-F4/F5 and RA-REV-23-F2

This is a **Code + Build implementation-status addendum**, not an independent re-review. Exact implementation/test/audit source `64fa65a9379ad0a246393371516de3a3a7146243` resolves the three follow-ups specified below; the fresh package has compiled successfully but no semantic contract has executed.

- **RA-REV-22-F4 remediated at Code + Build:** present-but-wrong remapped boundary content requires `ChangedBoundaryLoop`; present-but-wrong feature rail content preserves expected cardinality and requires `MissingFeatureRail`; a feature-bearing positive witness observes non-empty feature authority; final aggregate rejection diagnostics retain the complete source-authority validator issue list.
- **RA-REV-22-F5 remediated at Code + Build:** the option-echo `EXPECT_TRUE` assertions identified by the re-review are absent. Falsifiable published-vs-oracle equality and input-derived semantic checks remain.
- **RA-REV-23-F2 remediated at Code + Build:** pipeline stitch-kind audit is whole-statement and translation-unit-wide, recognizes fully qualified/wrapped/alias/stale-kind-copy forms and member writes, and its four independent evasion self-tests all pass.
- **Static evidence:** regenerated inventory **19 paths / 48 probes / 203 matches**, with **22/0** raw-projection leaves, **2/0** face-count leaves, **2/0** pipeline `stitchIdentity` assignments, classifier self-test **4/4**, final static **PASS**.
- **Compile evidence:** run/job `31649372167 / 94290107577`, exact source `64fa65a9379ad0a246393371516de3a3a7146243`, Release/static/Ninja/PRE_TEST **118/118**, build exit `0`; artifacts `9162042615 / 9162042971` with SHA-256 `c521a94e087f660cf93b6ebb9791ae1d0979a885e89eee621bc9c2fa6efe9322` / `58c64afba7d0c31ea83ac8922128c338694fbf5f0bc94150b94138d94bc6c0e8`; manifest **25/25**, five empty source-status snapshots, `runtimeExecution=false`.

**Remaining gate:** the single immutable artifact-only Test + Benchmark turn must execute these new contracts together with the complete retained R-A set. Overall R-A remains rejected/open until that gate passes organically.

## Independent re-review addendum — RA-REV-22-F1/F2/F3 and RA-REV-23-F1 closure

This Review inspected exact implementation/test/audit source `032d4cbae9e2de2767579934682e78754180338d`. `git diff 032d4cba..HEAD -- src include tests` is empty, so the branch head is a valid review proxy. This Review changed durable planning documents only; it executed no configure, compile, generated binary, discovery, test, benchmark, `ctest`, CLI, fuzzer, help/version command, or custom input. The only command executed was the source-only static audit `python3 .agents/Directional/R_A_Closure_Inventory.py --root .`.

**Decision: the requested RA-REV-22-F1/F2/F3 and RA-REV-23-F1 checkpoint is CLOSED at the Code + Build boundary. Overall R-A is still not complete — no semantic contract has executed.**

### Checkpoint decision

| Checkpoint | Decision | Evidence-based reason |
|---|---|---|
| RA-REV-22-F1 | **closed at Code + Build** | two new counterfactuals reach the real final oracle non-vacuously, require the concrete validator issue, and assert zero publication; the pre-oracle tests are renamed to their actual seam intent |
| RA-REV-22-F2 | **closed at Code + Build** | the literal-`true` aggregate assignments are gone; every published usage flag is copied from `finalAuthorityValidation`, and the positive witness cross-checks published-vs-oracle by equality |
| RA-REV-22-F3 | **closed at Code + Build** | the typed oracle result and a `componentValidationReportsComplete` discriminator are published before the component-report gate; a direct counterexample compiles |
| RA-REV-23-F1 | **closed at Code + Build** | the identifier-keyed probe is replaced by a structural kind-assignment probe plus an exhaustive `stitchIdentity` assignment classifier; inventory reproduces byte-for-byte and stays PASS |
| Overall R-A | **rejected / open** | still only compile and static evidence; every contract above is compiled-not-executed |

### Verified closures

- **Exact source verified.** Compile run `31644502450` has `head_sha` `30e16a7388d51db0224c450e9c3e4a57ac99053d`, but the trigger workflow passes `source_sha: 032d4cbae9e2de2767579934682e78754180338d` into `agent-compile-reusable.yml`, which checks out that ref and asserts `git rev-parse HEAD = inputs.source_sha` (`:60`, `:190`) before archiving. `git diff 032d4cba..30e16a73 -- src include tests CMakeLists.txt .agents/Directional/R_A_Closure_Inventory.py` is empty. The recorded exact source is therefore accurate.
- **Static inventory reproduced.** `python3 .agents/Directional/R_A_Closure_Inventory.py --root .` against the current tree is **byte-for-byte identical** to the committed `R_A_Closure_Inventory_Report.md` (zero diff lines), exit `0`: 19 paths, 42 probes, 186 matches, 22/0 raw-projection leaves, 2/0 face-count leaves, 2/0 pipeline `stitchIdentity` assignments, final static **PASS**.
- **RA-REV-22-F1.** `remesh_surface_cell_components_from_cross_field_final_validation_counterfactual` (`RemeshPipeline.cpp:11687`) drives a mutator invoked at `:11521-11523`, after global authority remap and immediately before `validate_source_authoritative_surface_mesh` at `:11525-11528` — past the `same_surface_cell_rail_authority` seam guard. Both new negatives (`SurfaceCellsPhase10Tests.cpp:5453`, `:5504`) latch `reachedFinalOracleSeam` from the *pre-mutation* option state and `ASSERT_TRUE` it, so neither can pass vacuously. Both require `FinalMergedSourceAuthorityValidationFailed` plus the concrete issue and assert eight distinct zero-publication observables. `reject_merge_authority` (`:10418`) resets `merged.surfaceCellContext = SurfaceCellPipelineContext{}`, so `hasFinalSourceAuthorityValidationResult` is genuinely false on rejection. The expected issue codes are reachable: with authority cleared and `requireBoundaryAuthority` true, `MeshValidator.h:178` raises `MissingBoundaryAuthority` before any edge-level issue, and `SourceAuthoritativeMeshValidator.cpp:1132` raises `MissingFeatureRail` when `expectedFeatureRailCount` exceeds the supplied rails. The two pre-oracle tests are renamed `ComponentBoundaryRailTamperRejectsAtAggregationSeam` / `ComponentFeatureRailTamperRejectsAtAggregationSeam` (`:5363`, `:5407`) and the inventory probe at `R_A_Closure_Inventory.py:170-173` pins those names.
- **RA-REV-22-F2.** `RemeshPipeline.cpp:11622-11644` sources every published flag from `finalAuthorityValidation`; the inventory carries both a present-probe on `finalAuthorityValidation\.(strict|provenance|boundary|featureRail)…` and an absent-probe on `aggregateValidationResult\.…\s*=\s*true` (`R_A_Closure_Inventory.py:178-185`). `DisconnectedAggregationPublishesGlobalOwnerAndRebuildsIdentityCaches` (`:5228-5237`) now asserts published-equals-oracle by `EXPECT_EQ` for all five usage flags, which is falsifiable against a re-hardcoded literal.
- **RA-REV-22-F3.** `RemeshPipeline.cpp:11563-11568` publishes `finalSourceAuthorityValidationResult`, `hasFinalSourceAuthorityValidationResult`, and `componentValidationReportsComplete` **before** the `allCompletedSurfaceCells && allHaveValidationResult && !firstValidationResult` gate at `:11618`. `FinalOracleOutcomePublishesWhenComponentValidationReportIsMissing` (`:5555`) drops one component report, asserts the merge still succeeds, asserts `hasValidationResult == false` and `componentValidationReportsComplete == false`, and asserts the oracle result is present and accepted. "Oracle ran and passed" is now distinguishable from "oracle result unavailable".
- **RA-REV-23-F1.** The name-keyed `rebuild_aggregate_stitch_identity` probe is gone. `classify_pipeline_stitch_identity_assignments` (`R_A_Closure_Inventory.py:312-357`) enumerates every `stitchIdentity = …;` in `RemeshPipeline.cpp` and fails the audit unless each one lies inside `rebuild_aggregate_output_identity_caches` and derives from `canonical_lineage_stitch_identity` — this does catch a *renamed* reintroduced duplicate builder that assigns stitch identities, which was F1's stated objection.

### RA-REV-22-F4 — the aggregate oracle is proven only against *absent* boundary/feature authority

**Evidence**

- `FinalMergedOracleRejectsMissingRemappedBoundaryAuthority` calls `validationOptions.authoritativeBoundaryEdges.clear()` and `.authoritativeBoundaryLoops.clear()` (`SurfaceCellsPhase10Tests.cpp:5478-5480`); `FinalMergedOracleRejectsMissingRemappedFeatureAuthority` calls `validationOptions.authoritativeFeatureRails.clear()` (`:5530`). Both erase the whole authority set rather than corrupting one remapped entry.
- Erasure reaches only the presence guards: `MeshValidator.h:178` (`requireAuthoritativeBoundary && authoritativeBoundary.empty()`) and `SourceAuthoritativeMeshValidator.cpp:1119`/`:1132` (`rails.size() != expectedFeatureRailCount`). The content comparisons — `actualLoops == expectedLoops` at `SourceAuthoritativeMeshValidator.cpp:1097-1101` yielding `ChangedBoundaryLoop` at `:1107`, and the per-rail `outputEdges.count(...)` check at `:1124-1130` — are never exercised on the aggregate path. `FinalMergedOracleRejectsPostComponentProvenanceTamper` (`:5665`) covers content mismatch for provenance only.
- Consequence under this project's own rule that a negative proves only the guard it actually reaches: nothing yet proves the final oracle rejects a merged product that *disagrees with present* remapped boundary or feature authority. That is the central R-A post-merge semantic claim.
- Secondary: the positive witness runs with no `userHardEdges`, so `expectedFeatureRailCount` is 0 and `featureRailsPassed` is vacuously true there; `EXPECT_TRUE(finalValidation.authoritativeFeatureRailsPassed)` (`:5243`) carries no rail evidence.
- Secondary: `RemeshPipeline.cpp:11533-11545` selects the first issue whose code is in {`MissingBoundaryAuthority`, `ChangedBoundaryLoop`, `MissingFeatureRail`} rather than the first issue raised, so `surfaceCellFirstInvalidProducerValidationIssue` is a *preferred* code, not proof of which guard rejected first.

**Corrective measures**

1. Add a boundary content negative that keeps `authoritativeBoundaryLoops` non-empty and perturbs exactly one entry (replace one loop vertex, or drop one edge from one loop) and requires `ChangedBoundaryLoop` with zero publication.
2. Add a feature content negative that keeps `authoritativeFeatureRails` non-empty and `expectedFeatureRailCount` consistent, but points one rail at a vertex pair absent from the merged output, and requires `MissingFeatureRail` with zero publication.
3. Extend the positive witness (or add a second one) with `userHardEdges` set so `expectedFeatureRailCount > 0`, making `authoritativeFeatureRailsPassed` a real observation.
4. Either record the full issue list in diagnostics or assert on `finalSourceAuthorityValidationResult.issues` in the negatives, so the preferred-code selection at `:11533-11545` cannot mask which guard rejected.
5. Add inventory probes pinning the two new content negatives by name.

### RA-REV-22-F5 — two published usage flags remain non-falsifiable

**Evidence**

- The pipeline no longer hardcodes the flags, but the values it copies are option echoes: `SourceAuthoritativeMeshValidator.cpp:1038-1040` sets `strictValidationUsed = requireBoundaryAuthority && requireFeatureRailAuthority && requireLocalSheetCompatibility`, `:1041` sets `provenanceValidationUsed = true` unconditionally, and `:1042` sets `featureRailAuthorityUsed = options.requireFeatureRailAuthority`. The aggregate caller sets all three options to literal `true` at `RemeshPipeline.cpp:11517-11519`.
- Therefore `EXPECT_TRUE(finalValidation.strictValidationUsed)` (`SurfaceCellsPhase10Tests.cpp:5238`) and `EXPECT_TRUE(finalValidation.authoritativeFeatureRailsUsed)` (`:5241`) still cannot fail under any input — the exact two assertions RA-REV-22-F2 flagged.
- The plumbing defect *is* fixed: the `EXPECT_EQ` published-vs-oracle cross-checks at `:5228-5237` are falsifiable, and `boundaryAuthorityUsed` (`SourceAuthoritativeMeshValidator.cpp:1044`, gated on `sourceTopology.boundaryLoopCount > 0`) is genuinely input-derived. This finding is precision, not a reopening.

**Corrective measures**

1. Either drop the two tautological `EXPECT_TRUE` assertions and rely on the `EXPECT_EQ` cross-checks plus `boundaryAuthorityUsed`, or
2. set `strictValidationUsed` and `featureRailAuthorityUsed` at the point each gate actually executes, so a caller that supplies no rail authority cannot report strict/feature use.

### RA-REV-23-F2 — the structural stitch-kind probe has demonstrable false negatives

**Evidence**

- `R_A_Closure_Inventory.py:197` matches `(?:\.|->)kind\s*=\s*(?:geometry::)?PureQuadStitchIdentityKind::`, and `matches_for` (`:254-261`) applies it **line by line**. Four evasions were verified directly against that regex:

| Reintroduced form | Probe result |
|---|---|
| `identity.kind = directional::geometry::PureQuadStitchIdentityKind::ArrangementBoundaryNode;` | **MISS** — only a bare `geometry::` prefix is allowed |
| `identity.kind =` newline `    geometry::PureQuadStitchIdentityKind::ArrangementBoundaryNode;` | **MISS** — line-oriented scan |
| `identity.kind = lineage.stitchIdentity.kind;` | **MISS** — this is the exact original REV-23 defect (copying the pre-remap cached kind) |
| `using K = geometry::PureQuadStitchIdentityKind; identity.kind = K::ArrangementBoundaryNode;` | **MISS** — alias |

- The wrapped form is not hypothetical: `src/pipeline/RemeshPipeline.cpp:2685` already writes `equivalence.kind =` with the value on the next line, so the file's own clang-format style defeats the probe.
- `classify_pipeline_stitch_identity_assignments` does not compensate: it scans only `src/pipeline/RemeshPipeline.cpp` (`:315`) and matches only `\bstitchIdentity\s*=` (`:318`), so member-level writes (`stitchIdentity.kind = …`, `stitchIdentity.canonical.values = …`) and a duplicate builder placed in any other `src/pipeline` translation unit are unclassified.
- Net: F1's objection was "a renamed reintroduced duplicate builder would leave the probe green." The assignment classifier closes that for whole-identity assignments in `RemeshPipeline.cpp`, but a duplicate builder written in the file's prevailing wrapped style, or one that copies a stale cached kind, still leaves the audit green.

**Corrective measures**

1. Normalize whitespace across the whole file text before matching the kind probe, or match on a joined logical statement, so wrapped assignments are caught.
2. Widen the qualification alternation to any `(?:\w+::)*` prefix, and forbid *any* assignment to a stitch-identity `kind` member, not only enum-literal right-hand sides — including `= <expr>.kind` copies.
3. Extend `classify_pipeline_stitch_identity_assignments` to every translation unit under `src/pipeline/`, and to member-level writes matching `stitchIdentity\s*\.\s*\w+\s*=`.
4. Add a self-test to the audit script that asserts each of the four evasion strings above is classified unexpected, so the probe's own coverage is proven rather than asserted.

### Durable-document trims applied by this Review

- The previous conclusion's amendment 1 named `MissingComponentBoundaryAuthorityRejectsBeforeAggregatePublication` and `MissingComponentFeatureAuthorityRejectsBeforeAggregatePublication`. Those symbols no longer exist at `032d4cba...`. A next-turn filter built from that text would select zero tests, which this project classifies as orchestration failure. That amendment is rewritten below to the current names; the historical evidence line under RA-REV-22-F1 keeps the old names because it describes the reviewed state at `9d88d0e...`.
- `Architecture_M1_Single_Authority_Cutover_Code_Build_Plan.md` section 0F said the new negatives "corrupt that final remapped authority". They **clear** it. Corrected, because that distinction is precisely RA-REV-22-F4.
- `Future_Chat_Session_Handoff.md` mandatory-next-turn text is replaced with the concrete closeout sequence below.
- No other stale `.agents/` or `TODO.md` cross-reference was found: every referenced file resolves, and every test name pinned by an inventory probe exists in the current tree.

### Concrete R-A closeout sequence

**R-A is one continuous checkpoint. It must be implemented all the way through before any Test + Benchmark turn is executed.** No intermediate runtime gate is run against a knowingly incomplete contract set: RA-REV-22-F4 leaves the aggregate content-mismatch contract unwritten, so executing the current package would produce a partial result that cannot close R-A and would invite treating a partial pass as progress. Close R-A in this exact order; do not combine turn types.

1. **Code + Build turn (next).** Implement RA-REV-22-F4 (both content negatives, the feature-bearing positive, issue-list assertions, and the new inventory probes), RA-REV-22-F5, and RA-REV-23-F2 including the audit self-test. Regenerate the complete inventory; it must stay PASS under the widened probes. Execute no generated binary, test, benchmark, `ctest`, discovery, CLI, fuzzer, or custom input in this turn.
2. **Compile package.** One fresh focused Release/static/Ninja/PRE_TEST package from that exact source through `agent-compile-reusable.yml`, with manifest, five empty source-status snapshots, and `runtimeExecution=false` verified.
3. **Single artifact-only Test + Benchmark turn.** Execute the complete R-A contract set in one gate, with no rebuild — REV-21 permutation pair, REV-22 seam guards, the oracle presence negatives, the new oracle content negatives, the feature-bearing positive, REV-23 canonical/re-stitch, REV-24 null/foreign authority, transactional rollback, and zero-publication contracts.
4. **Mark R-A complete** only if step 3 passes organically *and* the regenerated static inventory is clean under the widened probes. Then proceed to R-B.

Package `9160266493 / 9160266848` is **retained compile history and superseded as a runtime candidate**. Do not execute it, and do not relabel it as R-A or M1 acceptance evidence.

If step 3 fails organically, the sequence restarts at step 1 with the failure classification carried forward; R-A does not close on a partial pass. Fixture-adequacy failures are Code + Build work and never repaired inside the Test + Benchmark turn.

## Post-review remediation addendum — RA-REV-22-F1/F2/F3 and RA-REV-23-F1

This addendum records corrective implementation performed after the independent review below. It does **not** rewrite the independent verdict or claim independent/runtime acceptance. Exact corrective source: `032d4cbae9e2de2767579934682e78754180338d`.

| Finding | Post-review Code + Build status | Remaining gate |
|---|---|---|
| RA-REV-22-F1 | **remediated / compile-valid** — final-validation-only boundary and feature counterfactuals target the actual final oracle and require concrete validator issue plus zero publication; prior component tests renamed to aggregation-seam intent | execute both new final-oracle negatives from immutable artifact `9160266493` |
| RA-REV-22-F2 | **remediated / compile-valid** — strict/provenance/boundary/feature usage is published from final-oracle result fields; hardcoded aggregate flags removed | execute positive aggregate oracle observability contract |
| RA-REV-22-F3 | **remediated / compile-valid** — typed final-oracle result is retained independently of component-report completeness | execute missing-component-report publication contract |
| RA-REV-23-F1 | **remediated / static-PASS** — structural audit forbids pipeline stitch-kind assignment and classifies every pipeline `stitchIdentity` assignment; two completion-canonical leaves allowed, zero unexpected | retain structural PASS during focused runtime package verification |

The complete inventory was regenerated from `032d4cbae9e2de2767579934682e78754180338d`: **19 affected paths, 42 probes, 186 probe matches, 22 allowed/0 unexpected raw-projection leaves, 2/0 face-count leaves, 2/0 pipeline `stitchIdentity` assignments, final static PASS**. Focused compile run/job `31644502450 / 94274781412` produced artifacts `9160266493 / 9160266848` and compiled **118/118** with exit `0`; the package self-excluding manifest verifies **25/25**, all five source-status snapshots are empty, and `runtimeExecution=false`.

Overall R-A remains open until the separate immutable artifact-only turn executes the new F1 final-oracle negatives and adjacent F2/F3 contracts organically. The prior package from `9d88d0e...` is superseded as a runtime candidate.

## Current-status addendum — R-A closure review after REV-21 coverage and REV-22 through REV-24

This Review inspected exact implementation/test source `9d88d0e47cfc039e5399ebee334290b1eeae792b` at branch boundary `db100d15b166a2ac19bf2bb45c829856b43bb5a9`. `git log --stat 9d88d0e4..db100d15` shows the 15 later commits touch only `.agents/` documents, `TODO.md`, connector triggers, and removed workflow YAML. **Zero implementation, test, fixture, or build source changed**, so the branch head is a valid review proxy for the compile-valid source. This Review changed durable planning documents only and executed no configure, compile, generated binary, discovery, test, benchmark, `ctest`, CLI, fuzzer, help/version command, or custom input.

**Decision: the requested REV-22-through-REV-24 checkpoint is accepted at the Code + Build boundary. Overall R-A is not complete. Do not mark the R-A checkpoint accepted.**

### Checkpoint decision

| Checkpoint | Decision | Evidence-based reason |
|---|---|---|
| Overall R-A | **rejected / open** | no semantic contract has executed; only compile and static evidence exists, and RA-REV-22-F1 leaves the final-oracle boundary/feature gates unproven |
| R-A-REV-21 | **accepted at Code + Build** | both required permutation-pair contracts are present and non-vacuous |
| R-A-REV-22 | **accepted at Code + Build with one required follow-up contract** | the source defect is fully corrected, but two of three required negatives reject at the pre-oracle seam guard |
| R-A-REV-23 | **accepted at Code + Build** | duplicate schema deleted; one canonical completion-owned constructor; kind derived from patch structure |
| R-A-REV-24 | **accepted at Code + Build** | entry-level authority proof precedes `sourceAuthorityUsed`; both required direct negatives present |

### Review boundary and evidence

- Compile run/job `31634075824 / 94239861945`, result/log artifacts `9156381103 / 9156381524`, Release/static/Ninja/PRE_TEST **118/118**, build exit `0`, self-excluding manifest **25/25**, five empty source-status snapshots, `runtimeExecution=false`. This proves buildability only.
- The complete R-A inventory was **independently reproduced during this Review**: `python3 .agents/Directional/R_A_Closure_Inventory.py --root .` against the current tree produced output **byte-for-byte identical** to the committed `R_A_Closure_Inventory_Report.md` (zero diff lines). Confirmed 17 affected paths, 38 probes, 164 probe matches, 22/22 allowed raw-projection leaves, 2/2 allowed face-count leaves, zero unexpected leaves, final static PASS. This closes the prior review's objection that the source-audit record was conclusion-only.

### Verified closures

- **REV-24.** `SourceAuthoritativeMeshValidator.cpp:1027-1037` requires non-null `sourceAuthority` and `matches_source_faces(*sourceFaces, sourceVertices->rows())` in the same entry guard as vertices/faces/provenance, and sets `sourceAuthorityUsed` only after it returns. The former `requireLocalSheetCompatibility`-gated null check is now an unreachable fallback rather than the sole owner. `SourceAuthoritativeMeshValidatorPhase22Tests.cpp:96` and `:124` supply the direct null and same-extent foreign negatives with all three optional gates disabled; the foreign case pre-asserts `matches_source_faces` is false so it cannot pass vacuously.
- **REV-21.** `SourceTopologyRegions::matches_source_faces` (`SourceTopologyRegions.h:151-188`) reconstructs a `SourceFaceTopologyKey` per row and requires equality with `topology_for_row(row)`; `SourceFaceTopologyKey::make` (`AuthorityKernel.cpp:33-42`) sorts and rejects repeated vertices, so the key is genuinely row-order-independent. `SurfaceCellsPhase10Tests.cpp:5564` permutes only the matrix while retaining the original authority and requires both `matches_source_faces` and `SourceChartTransitionGraph::available()` to fail; `:5588` rebuilds paired authority, requires the pair to match, requires the stale authority to fail, and requires semantic region-snapshot equality.
- **REV-23.** The duplicate pipeline constructor formerly at `RemeshPipeline.cpp:9758-9824` is deleted. `rebuild_aggregate_output_identity_caches` (`RemeshPipeline.cpp:9822-9942`) calls `pure_quad_detail::canonical_lineage_stitch_identity` and `canonical_authoritative_identity`. Verified single-source: the canonical constructor delegates to the same private `typed_lineage_stitch_identity` builder used by `resolved_stitch_identity`, derives kind from `patch.boundaryVertices` membership rather than the cached kind, and keeps chart/support out of the stitch key. Boundary-node caches and both face cycles are regenerated from the rebuilt identities. `SurfaceCellsPhase10Tests.cpp:5263` flips kind and injects a stale token into canonical values and boundary-node identities and requires the rebuild to overwrite all of them; `:5166` requires exact equality with the canonical factory, requires a generated-interior vertex to be exercised, and performs a post-publication `stitch_pure_quad_patches` re-stitch.
- **REV-22 source defect.** `RemeshPipeline.cpp:11494-11523` stages and globally remaps boundary edges/loops, feature rails, hard-feature edges, vertex-chart authority, output-quad source faces, and provenance, and enables all three strict gates. Authority is captured pre-aggregation by `captureFinalValidationAuthority` (`:10050`) and protected against post-capture tamper by `same_surface_cell_rail_authority`, so it is not derived from the merged product under check. Published `validationResult` is overwritten with the oracle's outputs at `:11577-11599` instead of the accumulated component reports. The positive fixture `make_disconnected_square_pair_mesh` is two open unit squares, so it is genuinely boundary-bearing and directly exercises the original false-`ChangedBoundaryLoop` condition.

### RA-REV-22-F1 — the two missing-authority negatives never reach the final oracle

**Evidence**

- `MissingComponentBoundaryAuthorityRejectsBeforeAggregatePublication` (`SurfaceCellsPhase10Tests.cpp:5347`) and `MissingComponentFeatureAuthorityRejectsBeforeAggregatePublication` (`:5391`) erase a rail after capture and both assert `surfaceCellFirstInvalidProducerReason == "ChangedComponentValidationAuthority"`.
- That reason is raised by the `same_surface_cell_rail_authority` seam guard at `RemeshPipeline.cpp:10642-10648`, which runs at component index 1 — roughly 870 lines before the final oracle call at `:11517`. The tests prove capture-versus-mutation consistency, not final-oracle enforcement.
- `MeshValidationFailureCode::MissingBoundaryAuthority` and `MissingFeatureRail` are asserted only at component/optimizer level (`SurfaceCellsPhase10Tests.cpp:679`, `SurfaceMeshOptimizerPhase22Tests.cpp:603`), never on the aggregate path. Only `FinalMergedOracleRejectsPostComponentProvenanceTamper` reaches the oracle, and it tampers provenance rather than boundary or feature authority.

**Corrective measures**

1. Add an aggregate negative that corrupts or drops a remapped entry in `globalValidationBoundaryLoops`/`globalValidationBoundaryEdges` so the seam guard passes and the oracle rejects with `FinalMergedSourceAuthorityValidationFailed` carrying `MissingBoundaryAuthority` or `ChangedBoundaryLoop`.
2. Add the equivalent negative for `globalValidationFeatureRails`/`expectedFeatureRailCount` requiring `MissingFeatureRail`. Assert zero aggregate publication in both.
3. Rename the two existing tests to state what they prove, for example `ComponentValidationAuthorityTamperRejectsAtAggregationSeam`, so the names no longer imply oracle coverage.

### RA-REV-22-F2 — three published validation flags are hardcoded

**Evidence**

- `RemeshPipeline.cpp:11579-11587` assigns `strictValidationUsed`, `provenanceValidationUsed`, and `authoritativeFeatureRailsUsed` literal `true` instead of sourcing them from `finalAuthorityValidation`.
- `DisconnectedAggregationPublishesGlobalOwnerAndRebuildsIdentityCaches` asserts `strictValidationUsed` and `authoritativeFeatureRailsUsed`; neither can fail under any input. The remaining assertions in that test are oracle-sourced and do carry evidence.

**Corrective measures**

1. Derive `strictValidationUsed` and `authoritativeFeatureRailsUsed` from oracle observables, or drop the two tautological assertions and rely on the oracle-sourced ones.

### RA-REV-22-F3 — final-oracle evidence is discarded when a component report is missing

**Evidence**

- The publication block at `RemeshPipeline.cpp:11577` is gated on `allCompletedSurfaceCells && allHaveValidationResult && !firstValidationResult`. The oracle call at `:11517` is unconditional and still rejects the merge on failure, so the gate itself is not weakened, but a successful final-oracle result is dropped from the published context with no diagnostic when any component lacks a report.

**Corrective measures**

1. Publish the final-oracle outcome, or a typed record stating that the oracle passed while component reports were incomplete, independently of component-report availability so consumers can distinguish "oracle not run" from "oracle ran and passed".

### RA-REV-23-F1 — the duplicate-schema probe is keyed to one identifier

**Evidence**

- The REV-23 probe "duplicate pipeline stitch-key constructor is deleted" matches the literal symbol `rebuild_aggregate_stitch_identity` with expectation `absent`. A renamed reintroduced duplicate builder would leave the probe green.

**Corrective measures**

1. Replace the name-specific probe with a structural one: require that `PureQuadStitchIdentityKind::` never appears as an assignment target under `src/pipeline/`, and that `stitchIdentity` assignments in `RemeshPipeline.cpp` occur only through `canonical_lineage_stitch_identity`.

### Durable-document trims applied by this Review

- `Architecture_M1l_..._Test_Benchmark_Report.md` section 12 directed the next turn to a nonexistent `Architecture_M1m_..._Code_Build_Plan.md`. It is now marked superseded and points at the authoritative plan.
- `Architecture_M1_Single_Authority_Cutover_Code_Build_Plan.md` sections 4 through 6 are now marked retained history, because their file-level instructions (for example deleting the already-absent `LegacyAuthorityAdapters.h`) read as active work.
- All other `.agents/` and `TODO.md` cross-references resolve. `Architecture_M1_..._Artifact_Only_Test_Benchmark_Report.md` and `tests/fixtures/surface-cells/manifest.json` remain correctly phrased prospective deliverables of dormant plans; no action taken.

### Review conclusion

The requested REV-22-through-REV-24 checkpoint passes at the Code + Build boundary and is marked accepted there. Overall R-A stays open: the only evidence in existence is compile and static evidence, and compile success is not semantic acceptance.

The authoritative next turn remains the **artifact-only Test + Benchmark cadence turn** against the exact fresh package, approved unchanged with two amendments:

1. **Superseded by the re-review addendum above.** Those two tests were renamed at `032d4cba...`; the current names are `ComponentBoundaryRailTamperRejectsAtAggregationSeam` and `ComponentFeatureRailTamperRejectsAtAggregationSeam`. They still reject at the seam guard by design and are classified as aggregation-seam coverage, not final-oracle coverage. Do not build a test filter from the old names — it would select zero tests.
2. **Superseded by the re-review addendum above.** RA-REV-22-F1/F2/F3 and RA-REV-23-F1 are now closed at Code + Build. The remaining R-A gate is the concrete closeout sequence in that addendum.

M1l `bd140cff4572412e6f4ecd70a6ce0fe85310932c` remains immutable runtime authority. Regression totals remain **34 events / 14 categories / 20 recurrences**.

## Retained prior-status addendum — R-A closure review after REV-18 through REV-21

The prior Review inspected exact implementation/test source `0580c5c8d7e4b12a41eefb0197f3660a0c7a8fca` at branch boundary `922c36b43b8d35af2d2ffdeccb8e0c2ef551c760`. The 13 later commits between that source and the review boundary change only four durable planning/status documents. No production, test, build, workflow, or fixture source was changed in that Review.

**Decision at that boundary: overall R-A was not complete.** The REV-22, REV-23, and REV-24 findings recorded below are superseded by the current addendum, which accepts them at the Code + Build boundary. Do not execute a task selection from this retained section.

### Checkpoint decision

| Checkpoint | Decision | Evidence-based reason |
|---|---|---|
| Overall R-A | **rejected / open** | mandatory semantic contracts never executed, the complete inventory is not reproducibly recorded, and three source-level authority/oracle defects remain |
| R-A-REV-18 | **bounded compile-only progress; not accepted** | a global owner is built, but aggregate identity rebuilding emits a noncanonical stitch schema and trusts stale cached kind |
| R-A-REV-19 | **bounded compile-only progress; not accepted** | publication is staged, but the new final oracle rejects ordinary boundary meshes and omits strict boundary/feature/chart authority |
| R-A-REV-20 | **reopened at validator boundary** | named optimizer compatibility branches remain absent, but the public source-authoritative validator can accept null typed authority when local-sheet checking is disabled |
| R-A-REV-21 | **core binding present; contract incomplete** | exact row-topology matching is implemented, but the required authority-only row-permutation negative and consistently paired permutation positive are absent |
| R-A-REV-22 | **open / new finding** | final aggregate validation is neither usable on boundary inputs nor authority-complete |
| R-A-REV-23 | **open / new finding** | aggregate stitch-identity rebuilding diverges from the canonical completion contract |
| R-A-REV-24 | **open / new finding** | source-authoritative validation retains a null-authority fail-open mode |

### Review boundary and evidence

- Compile run/job `31625763711 / 94211611771` succeeded. Independent artifact inspection verified exact source `0580c5c8d7e4b12a41eefb0197f3660a0c7a8fca`, result/log artifacts `9153147035 / 9153147459`, outer SHA-256 values `bbc07fad9a767dc77aff290c540659b4140aab414ddf1148dec1b637fc32af38` and `ad5984db04ab98a4bbcd058d58c83e1cdef2383890b8bcfab1c209e487b3889b`, **26** regular files, self-excluding manifest **25/25**, five empty source-status snapshots, and `runtimeExecution=false`.
- Release/static/Ninja/PRE_TEST compiled and linked **118/118** targets. This proves buildability only; none of the new semantic contracts executed.
- The packaged REV-18-through-REV-21 source-audit record is a conclusion-only summary. It records no checked-path inventory, commands, match counts, or allowed-leaf classification, so it cannot establish the required complete R-A inventory.
- A direct review inventory confirmed zero affected `SourceEntityId`, `sourcePositions`, `constraints.sourceComponent`, `featureIntervals`, `legacyIndex`, or named standalone-fixture compatibility matches in `include/` and `src/`; `complete_for_face_count` remains only as the implementation detail used by `matches_source_faces`.
- This Review executed no configure, compile, generated binary, discovery, test, benchmark, `ctest`, CLI, fuzzer, help/version command, or custom input.

### R-A-REV-22 — final merged-product oracle is unusable and incomplete

**Evidence**

- `RemeshPipeline.cpp:11260-11274` constructs aggregate validator options without authoritative boundary loops/edges, feature rails, hard-feature edges, vertex chart authority, or output-quad face authority. It explicitly disables boundary and feature authority.
- `SourceAuthoritativeMeshValidator.cpp:1076-1105` nevertheless always compares actual boundary cycles with supplied expected cycles. On any source with a boundary, the aggregate caller supplies an empty expected set, so a valid output receives `ChangedBoundaryLoop`. The compiled disconnected-aggregation positive cannot establish its asserted success until it actually runs.
- Even for closed inputs, omitting hard-feature/chart/rail authority makes this call weaker than the component strict validator and therefore not the required post-merge semantic oracle.

**Corrective measures**

1. Stage and globally remap every validator authority input required by the component strict path: ordered boundary cycles/edges, hard-feature edges and rails, vertex chart authority, output-quad source-face authority, and provenance.
2. Invoke the strict source-authoritative validator on the final staged mesh with applicable authority gates enabled. Do not derive expected authority from the output being checked.
3. Add boundary-bearing disconnected positives, missing/tampered boundary and feature negatives, and an assertion that proves the final strict oracle executed and accepted the valid merged product.

### R-A-REV-23 — aggregate stitch identities use a second incompatible schema

**Evidence**

- Canonical completion construction at `PureQuadCompletion.cpp:1924-1963` derives stitch kind from boundary/interior ownership and encodes only the exact local key plus normalized topology regions and isolation sheets. Chart/support authority is encoded separately by `canonical_typed_authority_identity`.
- `RemeshPipeline.cpp:9758-9824` reimplements that builder, copies `lineage.stitchIdentity.kind` from the pre-remap cache, and appends source charts and support to the stitch key. This is a different schema and preserves stale kind authority.
- `resolved_stitch_identity` at `PureQuadCompletion.cpp:1984-2001` recomputes the canonical completion key for generated interior vertices and rejects a cached key that differs. A published aggregate interior lineage rebuilt by the new helper is therefore not consumable by the canonical stitch path.
- Added aggregate tests assert validity and compute authoritative identity from the already-mutated stitch key. The stale-cache test changes only canonical values, not kind, and no test re-stitches published aggregate patches.

**Corrective measures**

1. Delete the duplicate pipeline stitch-key constructor and expose/use one canonical completion-owned construction API.
2. Derive boundary/interior kind from authoritative patch structure, not the old cache; normalize region/sheet authority once and keep chart/support only in the authoritative certificate identity.
3. Add a stale-kind counterexample, exact equality with the canonical factory, and a post-publication re-stitch/resolve contract covering generated interior vertices.
4. Regenerate boundary-node caches and face cycles only from those canonical rebuilt identities.

### R-A-REV-24 — source-authoritative validator can accept missing typed authority

**Evidence**

- `SourceAuthoritativeMeshValidator.cpp:1028-1041` requires source vertices, faces, and provenance but not `sourceAuthority`; it sets `sourceAuthorityUsed=true` before proving a non-null matching authority.
- Null authority is rejected later only when `requireLocalSheetCompatibility` is true at `1205-1217`. A caller that disables that option can traverse the otherwise valid geometry/provenance path with no typed owner while the result falsely reports that source authority was used.
- Existing missing-authority tests exercise optimizer/final-wrapper predicates, not this direct public validator option combination.

**Corrective measures**

1. Require non-null `sourceAuthority` and exact `matches_source_faces` success at validator entry, independent of optional boundary/feature/local-sheet gates.
2. Set `sourceAuthorityUsed` only after that proof succeeds.
3. Add a direct null-authority negative with optional gates disabled, plus a same-extent foreign-authority direct negative; both must reject with `MissingSourceAuthority`.

### R-A-REV-21 contract completion

The exact `matches_source_faces` implementation and consumer migration are useful progress. Complete the prior test matrix: permute only source rows while retaining the original authority and require pre-publication rejection; then permute the source matrix and rebuild/pair its authority consistently and require the same semantic result. The existing row-permutation test builds two independently valid networks and does not exercise the mismatched-pair counterexample.

### Review conclusion

Return to Code + Build for REV-22 through REV-24 and the missing REV-21 contracts. Rerun the complete retained R-A inventory through REV-24 with reproducible checked paths, commands, counts, and allowed leaves; then build one fresh focused package. Only a later immutable Test + Benchmark turn may execute that package and close R-A. Partial artifacts `9153147035 / 9153147459` remain authentic compile history but are superseded as a runtime task and must not be executed or relabeled as acceptance evidence.

M1l `bd140cff4572412e6f4ecd70a6ce0fe85310932c` remains immutable runtime authority. Regression totals remain **34 events / 14 categories / 20 recurrences**.

## Retained prior-status addendum — R-A closure review after REV-17/REV-20 partial remediation

The current review inspected exact implementation/test source `1352f3d18eb3821ecda9d74ea5e439adb5bcb875` at branch authority `356a0bc2733af41e15fad056161e526865c147c5`. Six later commits modify durable documents only. Review decision/planning commit: `49b94da971ff544ac77f9dd2fa394791a1b67435`.

**Decision: overall R-A is not complete. Do not mark the R-A checkpoint accepted.**

### Checkpoint decision

| Checkpoint | Decision | Evidence-based reason |
|---|---|---|
| Overall R-A | **rejected / open** | REV-18 and REV-19 are unimplemented; the complete inventory also found extent-only source-authority binding |
| R-A-REV-17 | **retained bounded progress; not independently accepted** | owner/certificate/canonical-cache changes are present and compile-valid, but a foreign same-extent authority still passes and runtime contracts did not execute |
| R-A-REV-18 | **open / not implemented** | aggregate publication still has no global owner and does not rebuild post-remap vertex/face identity caches |
| R-A-REV-19 | **open / not implemented** | aggregate publication remains non-transactional and still substitutes cached component reports for final merged validation |
| R-A-REV-20 | **retained bounded progress; not independently accepted** | named compatibility paths are removed/fail-closed for missing authority, but “complete authority” remains face-count-only and runtime contracts did not execute |
| R-A-REV-21 | **open / new finding** | paired source geometry and authority are not proven to describe the same topology |

### Review boundary and build evidence

- The implementation delta from prior review head `7b10c1c3cde9769438991742594676ec75e4200a` to `1352f3...` changes 12 implementation/test files. `RemeshPipeline.cpp` has only two deletions; `SurfaceCellsPhase10Tests.cpp` is unchanged. This directly disproves a REV-18/REV-19 implementation claim.
- Run/job `31616904715 / 94181880684` is successful. GitHub records result artifact `9149834162` with SHA-256 `c5055df51d9b94605c27817e596a04983bddb33956727a2c47c494d42a0b2ee2` and log artifact `9149834634` with SHA-256 `04291253c21af768af9c35b61f12e327c0ec536642a2ddf8895781657b1261a7`.
- The retained package record establishes Release/static/Ninja/PRE_TEST **118/118**, self-excluding manifest **21/21**, clean source snapshots, and `runtimeExecution=false`. It is compile evidence, not semantic acceptance.
- This Review changed durable documents only. It executed no configure, compile, generated binary, discovery, test, benchmark, `ctest`, CLI, fuzzer, or custom input.

### Retained REV-17 progress

- `owner_validated_typed_authority_certificate` at `PureQuadCompletion.cpp:1757-1820` checks every claimed chart against the transition graph, support incidence, owning region, and owning sheet.
- Certificate intersection is explicit at `1836-1859`; a present cached identity must equal the canonical full identity at `2016-2048`.
- Stitching requires non-null source faces/authority at `2386-2408`, validates every input/intersection, and creates duplicate-face conflict diagnostics only from the final global authoritative-identity inventory at `2691-2733`.
- The owned overlap contract and wrong-owner/sparse/wrong-sheet/wrong-face/exact-only/stale negatives are present in `PureQuadCompletionPhase18Tests.cpp:1797-2239`.

These changes address the bounded REV-17 defects. They do not close R-A while REV-18/REV-19/REV-21 remain and no immutable runtime contract has run.

### Retained REV-20 progress

- The affected optimizer surface no longer contains `sourcePositions`, `constraints.sourceComponent`, `featureIntervals`, `legacyIndex`, the named standalone-fixture fallback, or the alternate basic-validator branch.
- `source_optimization_has_complete_authority` now fails absent authority and invalid source shapes/indices at `SurfaceMeshOptimizer.cpp:1827-1846`; optimizer and final-validator entry points fail closed when that predicate is false.
- The missing-authority optimizer/final-validator contract is present in `SurfaceMeshOptimizerPhase19Tests.cpp:109-137`.

These changes address the named REV-20 compatibility paths. They do not establish exact owner binding, and the compiled contracts were not executed.

### R-A-REV-18 — global aggregate owner and derived identity remain open

**Evidence**

- The aggregate span `RemeshPipeline.cpp:10004-10846` contains zero assignment to `merged.surfaceCellContext.sourceTopologyRegions`.
- It remaps lineage authority at `10347-10475` but contains zero assignment to `stitchIdentity`, `authoritativeIdentity`, `canonicalStitchCycleHash`, or `canonicalAuthoritativeCycleHash`.
- The REV-17/REV-20 delta changes only two unrelated lines in this file and no aggregation test.

**Corrective measure**

1. Build and publish one checked global source-authority product for the original source mesh.
2. Validate every final global lineage against it.
3. Recompute or remove vertex identity caches after remap and regenerate both face cycles from final identities.
4. Compile colliding-local-domain, stale-cache, wrong-owner, and zero-publication contracts.

### R-A-REV-19 — transactional publication and final merged oracle remain open

**Evidence**

- Labels are written at `RemeshPipeline.cpp:10272-10289` and rails are appended at `10295-10340` before lineage remap validation.
- `reject_component_merge_authority` at `10227-10252` clears mesh/output lineage/completed patches only; it does not reset already written labels, rails, debug/context state, optimization, or validation.
- The aggregate calls `accumulate_surface_validation_report` at `10759-10767` and publishes that cached result at `10832-10836`; it contains no call to the source-authoritative validator on the final merged product.
- The existing zero-publication test asserts only the subset cleared by the rejection lambda.

**Corrective measure**

1. Stage every semantic/context product and commit only after all components, remaps, identity rebuilds, and final validation succeed.
2. Make rejection expose one documented non-consumable empty semantic context, including failure in a later component after an earlier valid component.
3. Run actual final source-authoritative validation against the global owner; retain component reports as diagnostics only.
4. Expand the counterfactual snapshot to global owner, all remap domains, canonical identities, face cycles, complete rollback, and final validation.

### R-A-REV-21 — source authority is bound by extent, not topology

**Evidence**

- `SourceTopologyRegions::complete_for_face_count` returns only `rowBindings_.size() == faceCount && !regions_.empty()` at `SourceTopologyRegions.h:139-140`.
- Stitching at `PureQuadCompletion.cpp:2397-2405` and owner validation at `1763-1805` use that extent predicate. They validate claims within the supplied authority and incidence within the supplied face matrix, but never compare `sourceAuthority.topology_for_row(row)` with the checked topology key constructed from that matrix row.
- `source_optimization_has_complete_authority` at `SurfaceMeshOptimizer.cpp:1827-1846` checks pointer, dimensions, row count, and vertex index bounds only.
- Therefore an authority constructed for a different mesh with the same face count can be treated as complete: its owner relations validate tautologically while support/projection uses another mesh. Current negatives cover null/unowned fields, not this foreign-owner counterexample.

**Corrective measure**

1. Introduce one shared exact binding predicate for every affected `(sourceFaces, SourceTopologyRegions)` boundary.
2. Construct the checked `SourceFaceTopologyKey` for every source row and require equality with `topology_for_row(row)`; reject repeated/invalid/out-of-extent source vertices.
3. Apply it transitively to completion/stitching, `SourceChartTransitionGraph`, optimizer helpers/wrappers, source-authoritative validation, and pipeline ingress.
4. Compile a same-face-count/wrong-topology negative, an authority-only row-permutation negative, and a consistently permuted matrix-plus-authority positive. Every negative must fail before semantic publication.

### Review conclusion

Return to Code + Build for REV-18, REV-19, and REV-21, then rerun the complete retained R-A inventory. The focused runtime turn for partial artifacts `9149834162 / 9149834634` is superseded because the package is source-incomplete and lacks the REV-21 counterexample. Continue R-B through R-G and create one fresh full package only after R-A closes.

M1l `bd140cff4572412e6f4ecd70a6ce0fe85310932c` remains immutable runtime authority. Regression totals remain **34 events / 14 categories / 20 recurrences**.

## Retained prior-review addendum — 2026-08-12 UTC

This report retains the historical review of source `bebac907...` below. The current independent checkpoint review inspected exact implementation/test source `cb848e4dde30bcbe19dcd5d07a408edb2a47dd6e` at branch authority `fd96852d19defe70effd0dc6fbbaf07db8378e55`. Later branch commits changed durable documentation and removed temporary workflow/payload files; the reviewed production and test blobs are unchanged from `cb848e4...`.

**Verdict at that prior boundary:** **overall R-A and the requested REV-14-through-REV-16 review checkpoint were rejected.** The useful compile-only remediation remains historical partial evidence, but it does not establish the single-authority invariant.

### Checkpoint decision

| Checkpoint | Decision | Evidence-based reason |
|---|---|---|
| Overall R-A | **not complete** | aggregate publication has no global owning source-authority product, derived identity caches become stale after typed remap, and named compatibility paths remain |
| R-A-REV-14 | **not independently accepted** | collision certificates are checked only for nonempty fields and the positive fixture fabricates unowned IDs while omitting source authority |
| R-A-REV-15 | **not independently accepted** | aggregation remaps typed IDs without publishing their owner, rebuilding dependent identities, or providing complete transactional rollback |
| R-A-REV-16 | **not independently accepted** | the pre-consumer seam is real, but its snapshot and validation oracle omit the defects above and the audit therefore produces a false closure result |

### Review boundary

- This was an independent Review turn. No production, test, fixture, benchmark, validator, build, workflow, or generated artifact source was modified.
- No configure, compile, discovery, generated test, benchmark, `ctest`, CLI, fuzzer, help/version command, or custom input was executed.
- Existing compile-only evidence remains authentic partial evidence: run/job `31602025466 / 94131563590`, Release/static/Ninja/PRE_TEST **118/118**, result/log artifacts `9143819164 / 9143819888`, verified self-excluding manifest **21/21**, and no generated runtime execution.
- M1l `bd140cff4572412e6f4ecd70a6ce0fe85310932c` remains the immutable runtime authority. Regression totals remain **34 events / 14 categories / 20 recurrences**.

### R-A-REV-17 — collision certificates are not validated against their owner

**Evidence**

- `typed_lineage_authority_certificate` in `src/geometry/PureQuadCompletion.cpp:1700-1720` only normalizes the region/sheet/chart vectors and requires nonempty values plus support. It does not prove that a region owns a sheet, that a chart owns its face, or that support is incident to the chart/region.
- `CompatibleCollisionPublishesOnlyPostIntersectionAuthority` in `tests/PureQuadCompletionPhase18Tests.cpp:1785-1911` appends region IDs 91/92, sheet IDs 93/94, and chart IDs 95/96 without constructing an authority that owns them. It calls `stitch_pure_quad_patches` without `sourceAuthority`.
- The public stitch API permits `sourceAuthority = nullptr` at `include/directional/geometry/PureQuadCompletion.h:602-607`; within stitching that pointer is used for shared geometric provenance, not certificate ownership validation.
- `resolved_authoritative_identity` at `src/geometry/PureQuadCompletion.cpp:1902-1938` accepts the exact stitch identity and an older partial typed identity as compatibility aliases for the canonical full certificate.

**Corrective measure**

1. Require complete `SourceTopologyRegions` plus chart/support ownership authority for semantic stitch publication.
2. Validate every incoming certificate and the final intersection against region-sheet ownership, chart-face ownership, and support incidence before registry insertion or publication.
3. Accept an absent cached authoritative identity by deriving it, or require exact equality with the canonical full identity; reject exact-only and partial-typed aliases.
4. Replace the fabricated positive with a naturally valid overlapping-but-nonidentical boundary certificate owned by the supplied authority. Add wrong-owner, sparse/unowned-ID, wrong-face, exact-only, and stale-partial-identity negatives; each must fail with zero publication.

### R-A-REV-18 — aggregate typed lineage is orphaned and its derived identities are stale

**Evidence**

- A single-component result retains `phaseFrontProduct->sourceTopologyRegions` at `src/pipeline/RemeshPipeline.cpp:6114-6115`.
- The disconnected-component aggregator spans `RemeshPipeline.cpp:9758-10850`; a complete search of that range finds **zero** assignment to `merged.surfaceCellContext.sourceTopologyRegions`. It publishes globally remapped region/sheet/chart IDs without publishing the immutable domain that owns those IDs.
- `remap_component_typed_lineage_authority` at `RemeshPipeline.cpp:8662-8866` rewrites `sourceTopologyRegions`, `sourceIsolationSheets`, `sourceCharts`, and `sourceSupport`.
- A complete search of `RemeshPipeline.cpp` finds **zero** assignment to `authoritativeIdentity`, `stitchIdentity`, `canonicalAuthoritativeCycleHash`, or `canonicalStitchCycleHash`. Those caches were produced before aggregation in `PureQuadCompletion.cpp:2776-2830`, while `hash_completion` later consumes both the remapped fields and stale caches at `RemeshPipeline.cpp:1641-1683`.

**Corrective measure**

1. Construct and publish one checked global `SourceTopologyRegions`/chart authority for the original source mesh before any aggregate semantic output becomes visible.
2. Remap through that published domain; validate every final lineage against it.
3. Recompute or remove every derived stitch/authoritative identity after final global remap, then regenerate each face's canonical stitch/authoritative cycle from the final vertex identities.
4. Add a two-component fixture with colliding local ID ranges and assert global ownership, canonical identity equality, and face-cycle regeneration for every published item. Inject a stale local cache and require rejection before publication.

### R-A-REV-19 — aggregate rejection and the REV-16 oracle are not transactional

**Evidence**

- Aggregation writes global source labels at `RemeshPipeline.cpp:10278-10291` and appends rails at `10340-10341` before output-lineage remap validation.
- `reject_component_merge_authority` at `10229-10254` clears mesh/output lineage/completed patches only. It does not reset already-published rails, source labels, debug products, cached optimization/validation products, or the rest of `SurfaceCellPipelineContext`.
- `ProductionAggregationRejectsUnownedTypedRemapWithZeroPublication` at `tests/SurfaceCellsPhase10Tests.cpp:5121-5163` asserts only the subset cleared by that lambda, so it cannot detect leaked context state or a valid first component left behind when a later component rejects.
- The aggregator performs no post-remap source-authoritative validation. It only accumulates each component's already-computed report at `RemeshPipeline.cpp:10763-10838`.
- The REV-16 typed snapshot at `SurfaceCellsPhase10Tests.cpp:5018-5058` omits the owning global authority, stitch/authoritative identity, and face-cycle caches. Its completion hash compares two equally stale cache sets, and its “downstream validation” comparison observes cached pre-aggregation reports.

**Corrective measure**

1. Stage every component's labels, rails, lineages, patches, debug products, metrics, and validation state in a transaction; commit only after all remaps and final validation succeed. Alternatively reset the entire semantic context to a documented non-consumable rejected state.
2. Run source-authoritative validation on the final merged/remapped product using the new global authority; do not substitute accumulated component reports.
3. Expand zero-publication negatives to fail the second component after a valid first component and assert every semantic payload/flag is empty or unavailable.
4. Expand the counterfactual oracle to compare the global owner, canonical identities, face cycles, and actual post-merge validation. Add malformed region, sheet, chart, support, and stale-cache variants.

### R-A-REV-20 — the complete R-A inventory still contains compatibility authority paths

**Evidence**

- `SurfaceOptimizationConstraints` retains raw `sourceComponent` beside optional typed authority, and `SurfaceFeatureCurveInterval` retains raw component/sheet fields at `include/directional/geometry/SurfaceMeshOptimizer.h:91-123`.
- `nearest_source_point` uses the raw point-cloud component fallback at `src/geometry/SurfaceMeshOptimizer.cpp:154-184`.
- The optimizer retains explicit `legacyIndex` feature-interval fallbacks at `SurfaceMeshOptimizer.cpp:275-334` and a “legacy standalone optimizer fixtures” fallback at `2611-2627`.
- `validate_final_surface_mesh` has an alternate basic-validator path when `sourceAuthority == nullptr` at `SurfaceMeshOptimizer.cpp:2852-2894`. Strict wrappers exist and the production pipeline calls them, but active R-A items 9-12 require the affected standalone compatibility branches and fixture exceptions to be removed or isolated outside the SurfaceCells authority boundary.

**Corrective measure**

1. Delete these compatibility paths from the affected SurfaceCells implementation or move generic non-SurfaceCells behavior into a separately typed API/module that the strict wrapper cannot enter.
2. Make every SurfaceCells optimizer/verifier helper transitively require complete typed source authority; remove raw component/sheet mirrors from affected semantic records.
3. Add missing-authority and alternate-validator-path contracts plus a static inventory that fails on the named legacy branches, raw mirrors, or bypass calls.

### Verified progress retained

The reviewed source does correctly establish checked/private `SurfaceTopologyRegion` and `SourceTopologyRegions` construction, exact face coverage, builder-only raw classifier ingress, a phase-front materializer API that accepts the owning product rather than parallel raw arrays, independent local remap tables with region/sheet/chart/support relationship checks, and a real pre-aggregation raw-tamper seam. Those improvements remain valid implementation progress; they are insufficient for checkpoint closure.

### Prior review conclusion

At that boundary, overall R-A and REV-14-through-REV-16 were not independently accepted, and REV-17 through REV-20 were assigned. The current-status addendum supersedes that task selection.

## 1. Review boundary and evidence

This review inspected the supplied redesign, its supporting review/context, the current durable architecture and test records, the R-A source, the final compile record, and the source delta between the downloaded review snapshot and the reviewed source.

No project executable, generated test, discovery command, benchmark, ctest, CLI, fuzzer, or custom input was executed. No production, test, fixture, benchmark, validator, build, or workflow source was edited.

R-A compile evidence:

- workflow run/job 31550744314 / 93972723960;
- result artifact 9124167871, digest sha256:31841bfda6ad39fc5f5c3f2112e24beb5d3e872008e8a65d13985441509f95b8;
- log artifact 9124168143, digest sha256:caf0000f304444a960b051b8445c76be74dd238631ac5f30f3e36fee706f66d8;
- Release/static/Ninja/PRE_TEST compile/link **118/118**;
- all generated-runtime, test, benchmark, discovery, ctest, CLI, fuzzer, and custom-input execution flags false.

The inspected source snapshot was c4932dff1a4249d24224e1b64fea81bdccaba06f. Comparison to reviewed source bebac907... found no later R-A production change; the only later production file was the benchmark translation unit. The inspected R-A paths therefore represent the reviewed implementation.

## 2. Redesign assessment

The supplied DESIGN.md materially improves the prior architecture in four ways:

1. Pipeline B is now the explicit normative default: combinatorial cross-field tracing, a field-aligned curve network, a global topology plan, and a deterministic polynomial conformity/flow stage replace global coordinate integration.
2. Pipeline A is retained as an optional, evidence-gated future path with one integer-free global solve rather than iterative mixed-integer refactorization. It cannot become scheduled work until Pipeline B is Certified on the full representative matrix.
3. The missing A1-to-A2 derivation is made explicit through FieldAlignedCurveNetwork, singularity ports, branch-consistent tracing, typed termination events, motorcycle-style decomposition, and disc-region proofs.
4. Binary success/failure is replaced by verifier-assigned dispositions D0-D4. Degradation is explicit, bounded, non-recursive, certificate-carrying, and cannot close strict gates.

The architecture is scientifically plausible and better aligned with the project's performance goal. It does not yet prove that the adapted tracing/motorcycle composition works for the target input class, that every fixed-boundary region has a successful degraded producer, or that the proposed quality path reaches production thresholds. Those are milestone evidence obligations, not reasons to reject the architecture.

### 2.1 Design clarifications that remain open

These points must be resolved before their owning milestone is accepted:

- DESIGN.md section 6.7 invariant 2 says degradations are empty for QualityRelaxed with all gates passed, while D1 is defined by one or more missed calibrated quality gates. D1 must have a quality-gate degradation record; the invariant needs a narrow wording correction.
- M3 must prove that the Ray-Sokolov-style trace construction plus motorcycle termination/decomposition gives the claimed non-crossing, complete, disc-region network on supported triangle-mesh/cross-field inputs. The cited ingredients do not by themselves prove the combined algorithm.
- The A1 field-quadrangulability certificate needs an executable construction and independent tamper oracle before failure may be classified as FieldTransportUnestablished.
- M7 must specify and prove the one declared degraded region producer, including completion/manifoldness under the unmodified fixed boundary. It cannot be treated as guaranteed merely because its interface is named.
- T5 must calibrate geometry, alignment, approximation, and element-quality thresholds before D0/D1 can be assigned honestly.

The attached DESIGN.md is preserved byte-for-byte as the normative source. These are tracked clarification/evidence items rather than silent edits to the supplied design.

## 3. M1 R-A review

### 3.1 What the implementation established

The implementation makes substantial progress against R-A:

- SourceRegionFaceAuthority owns row-independent SourceFaceTopologyKey plus typed IsolationSheetId.
- SurfaceTopologyRegion and SourceTopologyRegions use private state and checked factories.
- the source-authority factory verifies unique row topology, contiguous typed region IDs, exact row coverage, one row binding per member, component agreement, sheet agreement, and topology/member agreement before publication.
- raw sourceFaceComponents and sourceFaceSheets are confined to the source-authority builder ingress.
- SourceEntityId is removed in favor of typed SourceSupport, SourceProjectionChart, and SourceVertexFanId.
- build_authoritative_phase_front_mesh accepts the owning SurfacePhaseFrontProduct, not parallel raw component/sheet arrays.
- materializer occurrences carry required typed occurrence, support, chart, and topology-region values.

These changes are compile-valid. Compile validity is not semantic/runtime acceptance.

### 3.2 Blocking finding R-A-REV-01 — materializer still reads raw sheet payload as authority

OccurrenceData stores typed support/chart/region but no required typed sheet. The materializer then:

- compares SurfacePoint::sheet to decide whether an ordinary-front equivalence crosses isolation sheets (src/pipeline/RemeshPipeline.cpp:2602-2606);
- includes SurfacePoint::sheet in the canonical representative ordering key (src/pipeline/RemeshPipeline.cpp:2800-2816).

Those values are derived from SourceTopologyRegions, but they are persisted in the generic geometry payload and then read back for semantic decisions. That is exactly the duplicate-authority path prohibited by the corrected authority model and R-A items 7-8.

**Required correction:** each occurrence must carry the required typed sheet/member authority obtained from SourceTopologyRegions; equivalence and representative logic must compare typed region/sheet/chart/support values. SurfacePoint component/sheet may remain only as a one-way geometry/export projection that affected production paths never read as authority.

### 3.3 Blocking finding R-A-REV-02 — completion/lineage still encodes raw component and sheet into identity

PureQuadPatch, PureQuadMesh, and PureQuadVertexLineage retain SurfacePoint provenance beside typed topology-region, chart, sheet, and support authority. More importantly, resolved_stitch_identity writes provenance.component and provenance.sheet into SurfaceCellCanonicalIdentity (src/geometry/PureQuadCompletion.cpp:1694-1721). That identity participates in equality, hashing, ownership conflict detection, and stitching.

This is not diagnostic export. It is a semantic read-back of the raw mirror and leaves R-A item 7 open.

**Required correction:** build fallback stitch/ownership identity from the typed lineage authority or make the typed identity mandatory before assembly. Remove raw component/sheet reads from patch, completion, assembly, lineage, verifier, and materializer semantic decisions.

### 3.4 Acceptance consequence

R-A items 1-6 and the API-removal portion of item 8 are substantially implemented. Items 7 and the semantic-consumption portion of item 8 are not complete. Therefore:

- R-A is **not accepted as complete**;
- R-A source is **compile-valid partial implementation**;
- artifact 9124167871 is **not** an M1 runtime-acceptance candidate;
- no new stable runtime regression is assigned because runtime was intentionally not executed;
- M1l remains the latest immutable runtime authority.

## 4. Historical next sequence — superseded

The original R-A-REV-01/02 sequence below is historical only. Do not execute a task selection from this report's historical sections. The active Code + Build plan owns current R-A-REV-17 through R-A-REV-20, the complete R-A inventory, R-B through R-G, and the fresh full package.
