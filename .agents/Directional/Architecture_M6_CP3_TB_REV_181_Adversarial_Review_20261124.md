# TB-REV-181 — adversarial continuation (2026-11-24 UTC)

This continues turn `M6-CP3-TB-REV-181` after the [independent review](Architecture_M6_CP3_TB_REV_181_Region_Corner_Ownership_Independent_Review_20261124.md).

The review was runtime-free. It used:
- source reading;
- Haiku read-only work:
  - the CB-202 hashes, apply check and `clang++ -fsyntax-only` checks;
  - the TB182 case-manifest prefix check;
  - a census of plan error codes over all 1003 TB181 raw logs (artifact `14967943314`, SHA-256 `877efb75…fa6b`).

## Verdict

- **Upheld:** TB181 1003/1003, and K6 closed.
- **Upheld unamended:** the CB-202 exact diff `26ec484d…5332`. It implements TB-REV-180 requirements 1–6.
- **Recorded:** one design debt (O3) and one digest risk (O4). Neither blocks CB-202, and the TB182 STOP rules already catch O4.

## Findings

**O1 — CB-202 compiles; the independent review did not check this.**
- The diff, all preimages and all postimages match the manifest, and the diff applies cleanly at HEAD.
- `clang++ -fsyntax-only` results, each with a warning list identical to HEAD:
  - patched `GlobalTopologyPlan.cpp`: 0 errors, 3 warnings;
  - test TU: 0 errors, 9 warnings.
- The new `RegionCornerOwnership.h` compiles on its own (self-contained).
- The TB182 case manifest `d778afbe…a5ca` is the TB179 manifest byte for byte, plus row 1004 `GlobalTopologyPlan.SingularityReachUsesOwningFragmentCorners`.

**O2 — The "only row 979 + row 1004 may change" rule is sound against the evidence.**
- Across all 1003 TB181 logs, these codes appear only in row 979, and only as its `RegionContainsInteriorSingularity`: `RegionContainsInteriorSingularity`, `RegionSourceFaceOwningFragmentMissing`, `RegionOrbitMissing`, `RegionBoundaryNotSingleWalk`, `InvalidRegionCertificateBinding`, `RegionBoundaryArcNotOwnedByNetwork`, `RegionElectedCutComponentEmpty`.
- `Plan outcome=` appears only in row 979.
- So the reordered precedence cannot change any other printed outcome, unlike J1, where line moves were omitted. The asserting negatives (rows 354, 355, 654, 966) are covered by the independent review's census.

**O3 — Design debt: the complete-partition-union branch is production code shaped by one test.**
- `claims_complete_partition_union` and its branch in `build_region_certificates` (about 60 lines) exist only so row 355 keeps reporting `RegionContainsInteriorSingularity`. Row 355's forged candidate claims the whole four-triangle fan disc with an exterior-only walk.
- **Accepted for now, because the branch is bounded:**
  - It runs only on validation candidates (`validationPartition` is non-null only from `validate_candidate_structure`).
  - It returns an error on every path, so it can never accept a candidate.
  - The disc it describes really does contain the singularity. The diagnostic is true, not invented.
- **Not general.** A forged union of only *some* regions falls through to `RegionOrbitMissing`.
- **Debt D-U:** remove the branch once a production-path witness of `RegionContainsInteriorSingularity` exists (row 979, if TB182 shows its rejection is lawful). Otherwise, generalize it to the exact union of any subset of regions.
- Do not change row 355's assertion to delete the branch. Changing it would weaken an existing negative.

**O4 — Digest risk.**
- `boundarySingularities` now comes from the corner-granular set, and it feeds `GlobalTopologyRegionDiscCertificate::boundarySingularities`, which the candidate digest covers.
- A region whose boundary passes through a singular port node also owns a corner sector at that vertex: `partition_face_corners` assigns a corner where cuts end to every side orbit. So no accepted plan's list is predicted to change.
- The TB182 rule "no unrelated semantic-digest change; any off-row change is STOP" is the falsifier. It is not relaxed.

**O5 — Equivalences checked.**
- Using `firstNode`/`secondNode` in place of `oriented_arc_nodes` builds the same boundary node set.
- The removed `incidentFacesByVertex` skip is no longer needed, because reach now comes from region corners.
- The helper namespace `global_topology_plan_detail` matches the existing `validate_candidate_structure` home (`:3030`).

**O6 — Carried.** J6 debt, E5, Branch A, CB-190 and CP3/497/D0/H4 stay held.

## TB-EXEC-182 rules (unchanged from the manifest, restated)

1. Use the CB-202 package and the case manifest `d778afbe…a5ca`: 1004 gated + 81 deferred = 1085.
2. Expect 1004/1004 PASS.
3. Compare against TB181 `14967943314` under N1–N3.
   - Only row 979's raw receipt and the new row 1004 may differ.
   - No test line moves: line 50 is a one-for-one include swap, and line 18184 is edited in place.
   - Anything else means STOP.

## Turn sequence

1. `M6-CP3-CB-202-P13-REGION-CORNER-SINGULARITY-REACH`: exact diff, compile only.
2. `M6-CP3-TB-EXEC-182-P13-REGION-CORNER-SINGULARITY-REACH-FULL-GATE`.
3. `M6-CP3-TB-REV-182`: classify row 979 from its new `region=` field and outcome.
   - **(a) The plan builds.** Freeze the Branch A activation CB, with exact premise rows 393/648/858/971/972/978.

> TB-REV-182 A1: this six-row scope is insufficient and is held, not silently expanded. Row979 has a conflicting production-failure assertion; row858 later stop unmeasured. See [TB-REV-182 review](Architecture_M6_CP3_TB_REV_182_Region_Corner_Singularity_Reach_Independent_Review_20261125.md). Activation requires amended authority and exact evidence.

   - **(b) It advances to a new earliest error.** Freeze one exact receipt or correction for that error.
   - **(c) It is still `RegionContainsInteriorSingularity`.** The rejection is lawful, P1 is falsified as the cause, and the route is A2a at node 1. Schedule removal of D-U against row 979.
4. CB-190, off the critical path.

## Lessons

- Before accepting a "only row X may change" rule, census the predecessor gate's raw logs for every outcome token the patch can reorder.
- Production code that exists only to preserve one negative test's error code is debt. Bound it (reject-only, validation-only) and give it a removal condition.
