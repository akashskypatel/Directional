# M3-CP4c-3-TB41 Artifact-Only Test + Benchmark Plan

**Owner:** successor of `M3-CP4c-3-CB46`
**Execution split:** `M3-CP4c-3-TB41-EXEC` followed by independent `M3-CP4c-3-TB41-REV`
**Boundary:** artifact-only runtime; **no rebuild, no relink, no source mutation**
**Selector:** byte-frozen `Architecture_M3_CP4c3_Required_Green_Selector_409.txt`
**Purpose:** adjudicate EB7.1–EB7.7 after CB46 without reopening the production region→orbit→upstream-face binding.

## 1. Immutable execution authority

TB41-EXEC must consume the exact immutable package and exact source SHA recorded by the completed CB46 Code + Build report. It must not infer authority from the branch head if later documentation-only commits exist.

Before any runtime identity:

1. Verify the package root checksum manifest completely.
2. Verify the packaged source SHA equals the CB46 semantic source SHA.
3. Verify selector409 bytes have SHA-256
   `eea6d8c2bbc8e9247deb4bfbbe6763042c76002d1894dd62e35f80262403b53e`.
4. Verify the artifact-only harness bytes against the CB46 package manifest.
5. Verify `exactArithmeticBackend=GMP`, both `gmpxx` and `gmp` are present in compile evidence, and the package carries the required GMP runtime dependency.
6. Verify `turnBoundary=Code+Build-only` and `runtimeExecution=false` in the package build evidence. Runtime begins only in TB41-EXEC.
7. Record an empty packaged source status. A dirty or reconstructed execution view is orchestration failure.
8. Run exactly one selector identity per fresh process, preserving selector order. A zero-selected process is orchestration failure.

No test or benchmark executable may be rebuilt. No fallback backend, source-grid recovery, selector regeneration, test mutation, fixture mutation, or package repair is authorized.

## 2. Required accepted-prefix result — hard stop gate

The accepted authority prefix is ordinals **1–365**. TB41 must require:

- **365/365 PASS**.
- Any accepted RED is a semantic gate failure and immediately blocks promotion.
- In particular, ordinals **311, 314, 356, and 357 must PASS**. They are the four TB40 accepted-green losses that CB46 repairs by matching independently re-derived face partitions by content rather than foreign orbit index.

Do not reinterpret an accepted RED as an expected frontier. Accepted authority is immutable.

## 3. EB7.1 / EB7.4 — content-derived face-certificate binding

CB46 chooses the preferred EB7.1(b) repair: each `SurfaceCutGraphFaceCertificate` publishes a content-derived oriented-boundary anchor in addition to its producer-local `orbit` ordinal. The anchor is the lexicographically minimum `(NetworkArcId, Orientation)` incidence of that certified face walk. The production binding continues to be derived from exact region-boundary equality and then keyed by the producer's own orbit ordinal; the new anchor is evidence, not a replacement binding key.

For every creditable A2b witness exercised by ordinals 311/314/356/357, TB41-EXEC must capture the `M3_CP4C3_FACE_BINDING_CENSUS` rows and require:

1. `regionCount > 0` and one census row per emitted region.
2. Each region has exactly one upstream certificate matching the independently re-derived boundary anchor: `upstreamMatchCount == 1`.
3. The certificate anchor equals the independently re-derived anchor in both arc and orientation.
4. The copied `actualEmbeddedFace` equals that uniquely matched upstream certificate.
5. `certificateBoundaryArcCount == regionBoundaryArcCount`.
6. `discTopologyEstablished=true` and `fieldRegularity=true` for every credited row.
7. Consumed upstream anchors are injective and cover all emitted regions.
8. On any witness with more than one region, the census must contain more than one distinct anchor. A constant/non-varying field is not a measurement under `LESSONS.md` §2, “A conjunct that asserts a literal is not a check, and a census whose rows cannot differ is not a measurement.”
9. **Do not compare the independently re-enumerated face index with `certificateOrbit`.** A mismatch between those two foreign labels is not a failure. The anchor/content relation is the oracle.
10. Record that adding the boundary anchor changes the face-certificate semantic digest surface. This is expected representation evidence under Part XI §R7.8; it must not change cut selection, region construction, ownership, cellularity truth, selector bytes, or accepted identity membership.

### Falsifier

If 311/314/356/357 pass only because the orbit equality was removed while the content anchor cannot uniquely distinguish the rows, TB41 is RED. The census must be able to disagree with itself on the field being checked.

## 4. EB7.3 — binding-preservation falsifiers

The following must remain PASS:

- **312** `GlobalTopologyPlan.RejectsRegionWithMultipleBoundaryWalks`
- **409** `GlobalTopologyPlan.RegionBoundaryWithTwoDisjointLoopsIsStillRejected`
- **315** `GlobalTopologyPlan.RejectsTamperedDiscProofCertificate`

For ordinal 315 specifically, verify from the raw identity log that the mutation still changes `actualEmbeddedFace.orbit` and the rebuilt plan is rejected with `InvalidRegionCertificateBinding`. If 315 stops detecting that tamper, CB46 weakened the binding instead of repairing the oracle and TB41 is RED.

No TB41 interpretation may authorize changing `region_orbit`, the orbit-keyed production lookup, or the derived-not-stored binding rule.

## 5. EB7.2 — frontier evidence independent of terminal code

Protected ordinals **390, 393, 406, and 407 must PASS**.

When the mechanical production path terminates during `RegionConstruction` or `RegionCertification`, require the projected locus to publish frontier evidence independently of the typed terminal error:

- `regionFrontierFailureStage` is `RegionConstruction` or `RegionCertification`;
- `regionFrontierComponentCount > 0`;
- `regionFrontierComponentCount == regionFrontierComponents.size()`;
- `regionFrontierComponentsTruncated=false`;
- every row has non-empty plan partition identity and face-set digest;
- every row has certifier census correspondence `Exact` or `Superset`;
- every row has census component, census partition identity, and census face-set digest;
- `componentSubsetOfCensusComponent=true`.

This is DEFN-R4.4 evidence. The terminal enum value is not part of these four identities' contract.

### Falsifier

A transition to a different typed terminal code must not zero or remove the frontier census. If the evidence is present only for a named failure code, EB7.2 remains unsatisfied.

## 6. EB7.6 — measure `RegionSourceFaceOwningFragmentMissing`; do not repair it

Ordinals **366 and 367 are not required to become green in TB41**. Their current frontier is intentionally preserved for measurement.

If either terminates at `RegionSourceFaceOwningFragmentMissing`, require the raw diagnostic to publish all of:

1. the failing `sourceFace`;
2. `regionOwningFragmentOrbit`, the producer-local owning orbit whose `(sourceFace, orbit)` ownership row is missing;
3. non-empty `fragmentOwnerEvidence` including the row for the failing source face;
4. that row's `localFragmentCount` when evaluated, `ownerCount`, `expectedFragmentCount`, `ownerDeficit`, trace-chord count, crossing status, and shared-owner chord census;
5. the existing trace-arc owner census and component seed census needed to interpret the face row.

TB41-REV must use those measurements to assign the next owner. **TB41-EXEC must not change the failure behavior.** If 366/367 advance past `RegionSourceFaceOwningFragmentMissing`, or if the source face/orbit/census is missing, CB46 exceeded EB7.6 or failed its measurement obligation.

## 7. Carried owners and protected surfaces

The following identities retain their existing owners and are not corrected or re-scoped by CB46:

- 368 `GlobalTopologyPlan.PrescribedSphereWitnessDerivesRegionsThroughProductionEntryPath`
- 369 `SurfaceCutGraph.OrdinaryProposalSelectsTraceCrossedEdgeWithoutSaturation`
- 370 `SurfaceCutGraph.EmptyNetworkOnClosedSurfaceIsRejectedWithTypedError`
- 374 `ResolvedBranchCorrection.FoldedConeArrivalRayElectsOneOwnerAndFalsifiesCandidateLocalElection`
- 398 `SurfaceCutGraph.CellularityCertificatePublishesTotalSourceFaceOwnershipOnProductionFixtures`

Also require **404 and 408 PASS** and retain the certified source-face ownership census at **300 established / 0 unavailable / 0 conflicting**.

No result in this group authorizes work on those owners during TB41-EXEC.

## 8. Retired-code and semantic-boundary checks

Across all selector processes:

- retired `RegionEulerCharacteristicNotOne` and `RegionInteriorDisconnected` must remain absent from the mechanical 366/367 path;
- no source-support Euler/connectivity proxy may reappear as a topology gate;
- no selector identity may be added, removed, renamed, or reordered;
- no source-grid recovery or legacy backend may execute;
- no package/source bytes may change during execution.

## 9. Result accounting and regression documentation

TB41-EXEC must publish:

- raw PASS/RED count over selector409;
- accepted-prefix count over ordinals 1–365;
- exact RED ordinal list;
- per-identity fresh-process exit/status records;
- binding-census rows for 311/314/356/357;
- frontier-census rows for 390/393/406/407;
- EB7.6 missing-fragment measurement for 366/367;
- source/package/selector/harness checksum evidence;
- ownership census and retired-code census.

Before TB41-EXEC closes, categorize every observed regression or candidate in `.agents/Directional/Regression_Root_Cause_Tracker.md` as required by `GitHub_Workflow_Policy.md`. If no new stable event is justified, state why the stable totals remain unchanged.

## 10. Promotion criteria

TB41 is mechanically valid only if the artifact/package/source/selector/process contract is satisfied. It is semantically promotable only if all of the following hold:

- accepted **365/365 PASS**;
- 311/314/356/357 PASS through content-derived anchors, with non-vacuous census;
- 312/315/409 PASS;
- 390/393/406/407 PASS with non-empty later-frontier evidence;
- 404/408 PASS;
- ownership remains 300/0/0;
- 366/367 remain measured at `RegionSourceFaceOwningFragmentMissing` unless an independently justified pre-existing behavior proves otherwise;
- no prohibited owner changes or retired proxy resurrection is observed.

TB41-EXEC does **not** promote itself. Its exact successor is independent **`M3-CP4c-3-TB41-REV`**, which reviews the immutable execution evidence, adjudicates regression accounting, assigns the missing-fragment frontier owner, and decides the next bounded turn.

**Stop completely at the TB41-REV boundary.**
