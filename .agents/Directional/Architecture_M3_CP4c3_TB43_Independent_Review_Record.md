# M3-CP4c-3-TB43 Independent Review Record

**Status:** COMPLETE / EVIDENCE-ONLY / TB43 PROMOTED / 366–367 ROOT-CAUSED / CB49 FROZEN

**Turn:** `M3-CP4c-3-TB43-REV`
**Boundary:** independent Review + Plan; no compile, no runtime, no product/test/fixture/selector mutation
**Date:** 2026-09-08 UTC

## EF0 — mechanical validity and promotion

TB43 is mechanically valid and is promoted as the current semantic runtime authority.

- immutable package108: artifact `10076272909`, digest
  `a2578a82e82c3e1bdc5798e0bf96028e3e854ccbeb65c7a111a6489fa1593612`;
- exact built source: `531b517fb129425f113b5f811215f1d2b1939ee2`;
- selector409 SHA-256: `eea6d8c2bbc8e9247deb4bfbbe6763042c76002d1894dd62e35f80262403b53e`;
- authoritative run/job: `34280642422 / 102244347209`;
- result artifact `10077594302`, SHA-256
  `486a411479bec2249e6c3b33f2612625651e80e4f26b9b6fbf5e7addd63e4110`;
- log artifact `10077595162`, SHA-256
  `7ad742562eb48d0c8f6160176d73ab3baec3d6506262d022cc37580ff4e8bed2`;
- aggregate: **402 PASS / 7 RED / 0 SKIP**, accepted **365/365**, RED
  `[366,367,368,369,370,374,398]`;
- selection mismatch 0, timeout 0; every selector identity executed exactly once in ordinal order;
- package/source/execution-view byte+mode censuses are identical before/after;
- configure, compile, relink, generated discovery, package repair, mode repair, benchmark and source/test/fixture/
  selector mutation are all false.

The runtime exactly measured the Part XII falsifier frozen by DEFN-R8/CB48. It is therefore valid evidence rather
than a synthesized expectation. TB42 is superseded as runtime authority by TB43; its exact history remains in the
consolidated record and Git history.

## EF1 — Part XII recovery is real and closes its non-stable candidate

Ordinals **390, 393, 406 and 407 PASS**. Each publishes the required receipt:

`branch=UncutCensus; censusPredicateExecuted=yes; terminalSubjectRelation=Outside; sameDomainCorruptionRejected=yes; regionCertificationEvidenceBranchExecuted=yes`

The receipt proves all three facts Part XII was written to distinguish: the producer-owned `P_U` census actually
ran, a deliberately corrupted same-domain copy was rejected, and the current terminal region was classified
separately as `Outside`. The recovery is therefore non-vacuous.

Disposition: `M3-CP4c3-TB40-EXEC-CAND-02` is **CLOSED / RUNTIME-PROVED / NON-STABLE**. No stable event is removed;
the historical recurrence remains historical evidence.

## EF2 — 366/367 publish the missing relation exactly

366 and 367 remain RED at
`NotProductionReady/global-topology-plan/RegionSourceFaceOwningFragmentMissing`. Their identical failure-detail row
publishes:

- source face `10,11,79` in topology region 1;
- expected `regionOwningFragmentOrbit=1`;
- complete present owner-orbit set `[2,3]`, count 2;
- `regionOwningFragmentOrbitPresent=false`;
- `localFragmentCount=3`, `ownerCount=3`, `expectedFragmentCount=3`, `ownerDeficit=0`;
- terminal subject relation `Outside`;
- independent `P_U` census remains 226 unlabelled faces / 9 components / 9 owner-consistency rows.

This rules out the two tempting explanations that Part XII was designed to separate: it is neither an empty/unseen
uncut census nor a face-level owner cardinality deficit. `M3-CP4c3-TB41-REV-CAND-01` is therefore **CLOSED /
RUNTIME-PROVED / NON-STABLE** as an evidence-publication candidate. The product defect remains under
`M3-CP4c3-TB40-REV-CAND-02`.

## EF3 — root cause: two ownership projections use different terminal-segment predicates

The exact package108 source resolves the remaining owner without another definition turn.

`GlobalTopologyPlan.cpp` defines `is_terminal_slit(trace, segmentIndex)` as **final segment + no
`terminalBarrier`** (`:285–290`). That condition is broader than the semantic phrase “non-separating terminal slit”:
traces terminated at a singularity or contact can also have no `terminalBarrier` while their final segment is a
real embedded-graph arc.

Two consumers then disagree:

1. `build_fragment_corner_incidence()` derives the certified forward/reverse face-walk orbits (`:444–453`) but at
   `:467–472` drops **every** segment satisfying `is_terminal_slit`, before publishing the orbit-keyed
   `FragmentCornerIncidence` ownership map.
2. `build_regions()` derives the same two face-walk orbits and the predicate
   `separatesCertifiedFaces = forwardOrbit != reverseOrbit`; it drops the final no-barrier segment only when it does
   **not** separate certified faces. A final no-barrier segment whose two graph sides have distinct certified
   face-walk orbits remains a real trace piece and contributes its fragment-orbit evidence.

The comment in the corner-incidence path says `build_regions()` applies the same predicate. Source proves that
comment false. The projections have drifted.

Part VIII already defines `FragmentCornerIncidence` as an **ownership map keyed by the certified face orbit**.
Part XI makes the actual embedded face-walk orbit the region authority and `region_orbit()` derives the current
region from exact boundary equality. Therefore the missing orbit on 366/367 is not evidence that the region itself
is absent. It is evidence that one projection omitted an owner row that the region projection lawfully retained.

Root cause: **predicate drift in the fragment-corner ownership projection**. A no-barrier final segment was treated
as non-separating solely from terminal metadata, even when the actual embedded graph says its two dart sides belong
to distinct certified face-walk orbits.

## EF4 — existing definitions decide the correction; no DEFN-R9

No new semantic definition is required. Part VIII R4.1/R4.2 already owns the orbit-keyed corner ownership map and
shared-orbit merge behavior; Part XI/Part XI-A already owns the actual embedded face and region binding. Part XII
only made the failure observable enough to distinguish this defect.

The deciding rule is therefore already frozen: **a corner-ownership projection must use the same certified-face
separation predicate as the region ownership projection**. A shared-orbit final slit remains non-separating and is
skipped; a final segment with distinct certified face-walk sides is retained for both projections.

## EF5 — bounded corrective measure frozen for CB49

`M3-CP4c-3-CB49` is a narrow Code + Build turn. In `build_fragment_corner_incidence()` it must align the current
unconditional final-no-barrier skip with `build_regions()`:

- skip only when `is_terminal_slit(trace, segmentIndex)` **and** `forwardOrbit == reverseOrbit`;
- retain the segment when `forwardOrbit != reverseOrbit`, so the orbit-keyed `FragmentCornerIncidence` can publish
  the owner that region certification already expects;
- preserve the shared-orbit merge semantics of R4.1/R4.2.

CB49 must **not** alter `build_regions`, `fragmentOrbits`, region construction/IDs, `region_orbit`, actual embedded
graph construction, cut selection, ownership, `P_U`, certifier partition, selector bytes, or the five separately
owned RED surfaces. The `RegionSourceFaceOwningFragmentMissing` error remains fail-closed for genuine missing rows.

The helper name `is_terminal_slit` is historical and over-broad, but renaming/redefining it globally is outside
CB49 unless a local comment correction is needed to make the predicate explicit. The semantic change is one
consumer predicate, not a new terminal-kind model.

## EF6 — carried RED ownership is unchanged

The other five REDs do not move ownership in this review:

- 368: prescribed-sphere `CellularityNotEstablished`, origin `RotationSystemInconsistent` / upstream trace-event
  position owner;
- 369: ordinary-proposal saturation/quality surface, `saturationUsed=true`;
- 370: empty closed-surface network typed-rejection mismatch;
- 374: folded-cone field/atlas admissibility surface, `atlasBuild=false`;
- 398: prescribed-sphere production cellularity surface.

CB49 is forbidden from correcting or weakening any of them.

## EF7 — accounting and promoted authority

TB43 introduces no new RED ordinal and no accepted-prefix loss; its four recovered identities close a non-stable
candidate and its remaining seven REDs are already owned. Therefore stable accounting remains **47 events / 14
categories / 33 recurrences**, produced-witness debt **5**, package count **108**. Certified ownership remains
**300 established / 0 unavailable / 0 conflicting**.

Current semantic runtime authority is now **TB43 / package108 / selector409: 402 PASS / 7 RED / 0 SKIP, accepted
365/365**, RED `[366,367,368,369,370,374,398]`.

## EF8 — CB49 compile boundary and TB44 falsifiers

CB49 must compile through the durable reusable workflow with GMP/GMPXX and execute **no Directional binary**. After
compile/package success it authors exactly one artifact-only `M3-CP4c-3-TB44-EXEC` plan bound to that immutable
package. This review does not execute TB44 and does not freeze a synthetic aggregate result.

The next runtime must falsify CB49 with these explicit observations:

1. 366/367 must **not** reproduce the exact current `RegionSourceFaceOwningFragmentMissing` locus for source face
   `10,11,79`, expected orbit 1 and owner set `[2,3]`. They may PASS or expose a later independent guard; reproducing
   the same locus falsifies the correction.
2. Accepted 1–365 remains **365/365**.
3. 390/393/406/407 remain PASS with their Part XII non-vacuity receipts.
4. 368/369/370/374/398 remain at their already owned surfaces. Movement is not “bonus recovery”; it falsifies the
   stated scope and requires review.
5. Ownership remains 300/0/0 and retired-code silence remains intact.
6. If 366/367 advance, the first masked corner-ownership gate to inspect is
   `RegionInteriorVertexCornerOwnerMissing`; any new downstream gate is preserved for review rather than patched
   opportunistically.

If both 366/367 become green while all other owners stay fixed, the aggregate would be 404 PASS / 5 RED, but that
is a consequence to measure, **not** a frozen vector.

## EF9 — review process evidence

This review initially began several direct document reads before the mandatory `READ_MODE` declaration and full
policy-read sequence. The miss was detected before semantic adjudication, recorded, and corrected by switching to
`READ_MODE=snapshot`; one exact source snapshot was then used for the substantive cross-file review. This is a
control-plane sequencing defect only. It does not alter package108, TB43 artifacts, selector bytes, runtime
results, or the root-cause derivation above. The lesson is the existing conservation rule itself: a REVIEW whose
checklist names many durable documents is a snapshot turn **before the first document read**.

## Exact successor

**`M3-CP4c-3-CB49` — Code + Build, runtime-free, under the frozen plan
`Architecture_M3_CP4c3_CB49_Code_Build_Plan.md`.**
