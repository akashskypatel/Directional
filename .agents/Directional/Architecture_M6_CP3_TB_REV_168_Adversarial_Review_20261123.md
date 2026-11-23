# TB-REV-168 — adversarial continuation (2026-11-23 UTC)

Continues turn `M6-CP3-TB-REV-168-P13-ARC-FACE-VISIT-ADAPTER-FULL-GATE` after the [independent review](Architecture_M6_CP3_TB_REV_168_Independent_Review_20261123.md). Runtime-free: reading, `git apply --check`, `clang++ -fsyntax-only`, and an SHA-checked read of the TB168 artifact logs.

## Verdict

- **Upheld:**
  - TB168 993/993.
  - The exact CB-188 diff, unchanged.
  - The CB-189 diff design.
- **Amended:** CB-189, which gains six compile-time guards on its enum cast (Q4). New SHA `6e391678…e3b8`.
- **Corrected in the record:**
  - The CB-189 "performance hold" is withdrawn (Q5).
  - C1/C2 are not witnessed by any gated test (Q6).
- **Sequence unchanged:** CB-188 → TB-EXEC/REV-169 → CB-189 → TB-EXEC/REV-170.

## Findings

**Q1 — CB-188 is faithful to R1–R4.**
- Visits are classified once per arc. A cut visit is skipped only on the old terminal-slit predicate. Edge-only visits add 0 chords and only their visited-face side orbit.
- Everything R4 lists is left untouched: the segment loop, `traceTouchedEdges`, diagnostics and the excess ceiling.
- The new check `sourceFaces.size() == onePastLastSegment − firstSegment` already holds by construction (`EmbeddedGraphTopology.cpp:1964–1967`). It is harmless.
- The TB169 prediction can be observed. `fragmentOwnerFace[...]` prints `traceChordCount` straight from `tracePieceCount` (`GlobalTopologyPlan.cpp:1444`), so no new print is needed.

**Q2 — CB-188 cannot create a new excess.**
- In a face with at least one counted cut, every fragment is bounded by a counted cut. The visited-face orbit of an edge-only slide is therefore one of the cut sides, and the owner count cannot rise above `k+1`.
- TB167 confirms this: orbit 0 ∈ {0,1,6,7,8} and orbit 13 ∈ {1,8,11,12,13}.
- A face visited only by slides goes to `{side}` with expected 1, which is within the ceiling.

**Q3 — Census of the corner-reader errors CB-189 deletes.**
- Logs read from TB168 artifact `14781634158` (ZIP SHA verified, 993 logs).
- Of the 12 deleted error and rotation codes, only `SourceFaceCarriesMultipleTraceCuts` appears, once, at row 979. No `Region`-prefixed variant appears.
- So deleting the branches cannot move the failure stage of any other gated row.
- Equivalence on the success path rests on two things:
  - CB-186 tests 985–989 (single chord; corner fans).
  - The single-ray case, which is the one-ray fan: corner → {f, r}, corner+1 → r, corner+2 → f. This matches the old rule.
- Row 652 (`MechanicalFeatureWitnessDerivesRegionsThroughProductionEntryPath`) builds through production without throwing. In TB170 it is a real success-path witness for the switched reader.
- The port-carrier check is not lost: `build_regions` raises `RegionTraceSourcePortCarrierNotAdmissible` (`:1359`) through the same `resolve_carrierless_corner_binding`, before certificates are built. C3's trace-port binding check (`InvalidNetworkBinding`) is kept.

**Q4 — Defect, amended: unchecked enum cast.**
- CB-189 converts `detail::FaceCutPartitionFailure` to the public `FaceCutPartitionReason` with `static_cast`. Nothing checks that the two enumerations stay value-equal, so reordering either would silently report the wrong reason.
- Six `static_assert`s now sit before `build_fragment_corner_incidence`. The diff is regenerated against the CB-188 postimage:
  - Diff `6e391678934f776d83b1bbae6652724e080763329d6171c7cdb1c5663259e3b8`, 19,255 B, +117/−179.
  - `GlobalTopologyPlan.cpp` postimage `44395316a518c0cef8cd9afabdc622d69900496c1f6e4a290c37715602fb366f`.
  - Header postimage unchanged: `87831e10…a16c`.
- Haiku check:
  - The diff applies on CB-188 in a fresh worktree.
  - Both postimages match.
  - `-fsyntax-only` gives 0 errors and the same 24 warnings as before, none on the inserted lines.

**Q5 — Correction: the performance hold is withdrawn.**
- `validate_candidate_structure` has exactly one caller, `make_from_candidate`, reached once from `GlobalTopologyPlan::make`. No search loop calls it.
- It already re-runs `canonical_candidate` (`:2803`), and that includes `build_regions`.
- So the added `build_regions` call is one extra fixed-cost build per `make`. It is not an acceptance condition, and the gate has no performance measure that could discharge it.
- Passing the canonical evidence through `CandidateBuildResult` instead would widen a candidate type. It is not worth a turn.

**Q6 — Coverage stated, not invented.**
- `build_fragment_corner_incidence` is file-local. No gated test reaches `SourceFaceCutPartitionFailed`, `SourceFaceCutOrbitNotOwned` or the C2 subset check.
- They are witnessed only if row 979's log prints them.
- TB-REV-170 must not record C1/C2 as discharged without such a log line. Row 652 and rows 985–989 witness success-path equivalence only.

**Q7 — Turn granularity.**
- CB-188 and CB-189 are each one narrow, stacked, pre-frozen switch with its own manifest and TB.
- Splitting CB-189's plumbing into a separate CB would add a TB that informs no decision, so no split.
- CB-188 adds `arcVisits` and `fragmentOrbits` to `RegionBuildSuccess` before CB-189 reads them. This is accepted only because the reader is frozen and stacked.

## TB-EXEC-169 rules (frozen)

1. 993/993 PASS; CP2 491/491; membership 1074.
2. Rows other than 979 are equal to TB168 `14781634158` under N1–N3, with zero allowance. Any difference → STOP, return to Review, no edits.
3. Row 979:
   - The `fragmentOwnerFace` rows for `6-8-9`, `16-20-21`, `32-33-34` and `40-45-46` print `traceChordCount=4`, `expectedFragmentCount=5`, `ownerCount=5` and `ownerDeficit=0`.
   - The outcome stays `SphereStagedPlan outcome=SourceFaceCarriesMultipleTraceCuts sourceFace=6-8-9`.
   - Every other row-979 line is unchanged. A change elsewhere → STOP, return to Review.
4. No census, because CB-188 changes no production-only branch beyond the measured edge-only visits. No rebuild.

## TB-EXEC-170 decision map (carried, amended)

- Rows other than 979 are unchanged under N1–N3. Row 652 still passes without a throw.
- Row 979 either builds the staged plan or prints the next typed stage. The new codes count as witnessed only if printed (Q6).

## Lessons

- Before deleting a reader's error branches, grep the last gate's logs for each code. A code no row reaches cannot move a row.
- A cast between a private and a public mirror enumeration needs a per-value `static_assert`.
- Check a validation path's call frequency and what it already recomputes before calling an added recomputation a performance risk.
