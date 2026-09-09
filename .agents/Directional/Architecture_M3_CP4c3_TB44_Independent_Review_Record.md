# M3-CP4c-3-TB44 Independent Review Record

**Status:** COMPLETE / EVIDENCE-ONLY / TB44 PROMOTED / TWO ROOT CAUSES ADJUDICATED / CB50 FROZEN

**Turn:** `M3-CP4c-3-TB44-REV`
**Boundary:** independent Review + Plan; no compile, no runtime, no product/test/fixture/selector mutation
**Date:** 2026-09-08 UTC

## EG0 — mechanical validity and promotion

TB44 is mechanically valid and is promoted as the current semantic runtime authority.

- immutable package109: artifact `10081938891`, provider/download SHA-256
  `285ee15784ea29468c367fa9e4778fd835f1e9582370fdcb26a5050a15c4d617`;
- exact built source: `cf969597bda5c49e734b98db0c0165b421c4ee12`;
- packaged source archive SHA-256: `7dead808562e8faf0a90e242532e2965bc9260f24505958eb5f242c19b1273ca`;
- selector409 SHA-256: `eea6d8c2bbc8e9247deb4bfbbe6763042c76002d1894dd62e35f80262403b53e`;
- authoritative run/job: `34295565963 / 102291328376`;
- result artifact `10083047547`, SHA-256
  `7e3229e9f012e7920cb0318eae358768a19b05e863ec12b4484b68d5d067cfab`;
- log artifact `10083047938`, SHA-256
  `c63b6a45c208f704c26939face91f6f961ee5bc04c71f203c059f5109bcfe9cd`;
- aggregate: **398 PASS / 11 RED / 0 SKIP**, accepted **365/365**, RED
  `[366,367,368,369,370,374,390,393,398,406,407]`;
- selection mismatch 0, timeout 0 under the restored `timeout -k 5s 180s` per-identity control; every selector identity executed exactly once in ordinal order;
- package/source/execution-view byte+mode censuses are identical before/after;
- configure, compile, relink, generated discovery, package repair, mode repair, benchmark and source/test/fixture/
  selector mutation are all false.

The full gate had no repository-imposed outer elapsed cutoff. TB44 is therefore valid semantic evidence. TB43 is
superseded as runtime authority; its exact history remains recoverable through the consolidated record and Git history.

The review used an exact repository source snapshot produced by run `34304997040` after a marker-only control commit
`5f5022c78de1ce8c7771d1cf12d1db97050d2498`. That snapshot is static-inspection authority only; it does not replace
package109 source `cf969597...` as runtime provenance.

## EG1 — CB49 succeeded at its exact old-locus falsifier

Ordinals **366/367** no longer reproduce the TB43
`RegionSourceFaceOwningFragmentMissing` locus for source face `10,11,79`, expected orbit 1 and present owner set
`[2,3]`. Both advance to:

`RotationSystemInconsistent;sourceFace=10,11,79;rotationSystemReason=FragmentCornerSourceCornerMismatch`.

The TB44 owner census still publishes the face as a healthy local arrangement: **3 local fragments / 3 owners /
expected 3 / deficit 0**, **2 trace chords**, `chordsCrossInside=false`, and no shared-owner chord. Therefore CB49's
separation-predicate correction is not falsified and must not be reverted. It removed the exact owner-row omission it
was designed to remove and exposed the next consumer assumption.

Disposition: the TB43 predicate-drift diagnosis and CB49 correction remain valid historical authority.

## EG2 — 366/367 root cause: a whole-face bucket is incorrectly treated as one source-corner fan

The new failure is product-side and is fully determined from source plus TB44 evidence.

`build_fragment_corner_incidence()` records every carrierless trace ray as:

`RayCut{port->ordinal, forwardOrbit, reverseOrbit, binding->sourceCorner}`

under `raysByFace[segment.sourceFace]`. It then sorts the **entire face bucket** by port ordinal and requires every
ray to have `sourceCorner == rays.front().sourceCorner`. That is exactly the predicate raising
`FragmentCornerSourceCornerMismatch`.

The representation authority already distinguishes the datum the consumer discards: each ray carries its exact
`sourceCorner`. A source triangle may contain multiple real carrierless trace rays belonging to different source
corners. TB44's failing face has two non-crossing trace chords and three certified fragments/owners, so the existence
of more than one source-corner fan on that face is not itself inconsistent.

After the guard, the function also derives corner ownership using one `sourceVertex = face.vertices[sourceCorner]`
and the first/last rays of the whole bucket. That makes the single-corner assumption structural, not merely a bad
assertion. The correct ownership domain is **face + source corner**, with ordinal/orbit-chain ordering inside each
corner fan and set-wise publication into the face/orbit ownership map.

Root cause: **authority-domain conflation (`RP-01`) in the fragment-corner projection** — distinct source-corner
fans on one source face are collapsed into one whole-face ray chain.

This is a continuation of the same 366/367 ownership-projection owner, not a new independent stable event. CB49
corrected one stale consumer predicate; TB44 reveals the next stale consumer assumption in the same projection.

## EG3 — existing definitions decide the 366/367 correction; no DEFN-R9

No new topology definition is required. Part VIII already makes `FragmentCornerIncidence` an orbit-keyed ownership
map over source-face corner authority; the source itself already carries exact `sourceCorner` for each ray. Part XI
continues to own actual embedded face-walk/region authority.

CB50 must therefore make the minimum representation correction:

1. partition carrierless rays by `(sourceFace, sourceCorner)` before ordinal/chain validation;
2. sort and validate `FragmentCornerRayOrdinalDuplicate` / `FragmentCornerOrbitChainMismatch` **within each
   source-corner fan**;
3. publish the same orbit-to-source-vertex set contributions per fan, merging only through the existing set-valued
   `FragmentCornerIncidence` result;
4. preserve all fail-closed checks for invalid binding, mixed full-chord/ray cases, invalid darts and impossible
   orbit chains;
5. do not alter face-walk construction, region construction, `fragmentOrbits`, `region_orbit`, cut selection,
   partitions, or selector bytes.

CB50 may rename a local bucket variable or add a clarifying comment, but it may not introduce a new topology
certificate, traversal or heuristic ordering.

## EG4 — 390/393/406/407 still prove their Part XII census invariants

The four protected identities changed from PASS to RED, but the producer-owned assertions that Part XII exists to
protect still execute and still succeed. Every raw log publishes:

`branch=UncutCensus;censusPredicateExecuted=yes;terminalSubjectRelation=Outside;sameDomainCorruptionRejected=yes;regionCertificationEvidenceBranchExecuted=yes`.

The real `P_U` census data passes each identity's predicate and the deliberately corrupted same-domain copy is
rejected. Therefore the census/domain correction proven by TB43 has **not** regressed and
`M3-CP4c3-TB40-EXEC-CAND-02` remains historically CLOSED / RUNTIME-PROVED / NON-STABLE.

The new RED occurs only afterward in `expect_outside_region_certification_evidence()`:

- `region_fragment_owner_relation_is_valid(locus)` is false;
- `regionFrontierFailureRegionSourceFaceCount` is absent.

This is a test-authority failure, not a `P_U` product regression.

## EG5 — test root cause: R8.3's current-region precondition was dropped by the helper

Part XII R8.1 defines the failure subject by the object named by the failure contract: a source-face failure owns the
source face; a region failure owns the current region. R8.3 is explicitly conditional:

> when a failure is raised **while certifying a current `GlobalTopologyRegion`**, its failure-local evidence is the
> current region's derived face-walk orbit and failing-face fragment-owner relation.

Package109 now fails earlier inside `build_region_certificates()`: `build_fragment_corner_incidence()` is invoked at
function entry **before** `for (const auto &region : regions)`. The resulting
`FragmentCornerSourceCornerMismatch` names `sourceFace=10,11,79` but no current region exists yet. The outer caller
still annotates the chronology as `RegionCertification`, which is correctly only a stage name under R8.2.

The test helper nevertheless unconditionally demands `topologyRegion`, `regionOwningFragmentOrbit`, owner-set
membership and failing-region source-face counts. That helper has therefore converted a conditional R8.3 contract
into an unconditional stage-driven requirement — precisely the authority-domain substitution Part XII forbids.

R8.4's instruction to retain an `Outside` terminal receipt does not erase R8.3's explicit current-region
precondition. When no current region exists, manufacturing region fields would be a worse defect than the missing
fields.

Root cause: **test-authority domain conflation (`RP-01`)**. The protected producer oracle is sound; the shared
terminal-evidence helper assumes that every later-stage `Outside` failure has a current-region subject.

## EG6 — bounded test correction for CB50

CB50 must preserve or strengthen the four protected tests rather than weakening them.

- Keep every producer-owned real-data predicate and same-domain corruption falsifier byte-for-byte equivalent in
  meaning. The `UncutCensus` branch must still execute on every protected identity.
- Replace the unconditional region-only helper with a typed subject check derived from authoritative locus fields:
  - when a current region is identified, require the full existing R8.3 region/fragment relation and region face
    counts;
  - when no current region exists but an authoritative `sourceFace` is identified, require `Outside`, require the
    source-face subject, and require region-specific fields to remain absent rather than fabricated;
  - if neither authoritative subject can be identified, fail closed.
- Keep the deterministic receipt explicit about which terminal subject branch executed. The receipt may be extended
  with a typed subject label, but existing `UncutCensus`, corruption-rejection and `Outside` evidence must remain
  observable.
- Do not alter fixtures, selector409, product census definitions, `P_U`, or partition construction to make the tests
  green.

This is a test-only correction to terminal evidence applicability, paired with the independent product correction in
EG3. The two edits share a runtime witness but remain distinct owners.

## EG7 — carried RED ownership and stable accounting

The other five REDs remain under their established independent owners:

- 368 — prescribed-sphere `CellularityNotEstablished` / upstream `RotationSystemInconsistent` trace-event-position
  owner;
- 369 — ordinary-proposal saturation/quality surface, `saturationUsed=true`;
- 370 — empty closed-surface network typed-rejection mismatch;
- 374 — folded-cone field/atlas admissibility surface, `atlasBuild=false`;
- 398 — prescribed-sphere production cellularity surface.

Protected controls 311/312/314/315/356/357/404/408/409 remain PASS. Certified ownership remains
**300 established / 0 unavailable / 0 conflicting**. Retired-code silence remains intact.

TB44 introduces no accepted-prefix loss. 366/367 are a continuation of their existing non-stable projection owner;
390/393/406/407 are a test-authority color regression while their product-owned census predicates remain proved.
No newly independent stable product event is justified.

Stable accounting therefore remains **47 events / 14 categories / 33 recurrences**, produced-witness debt **5**,
package count **109**.

Current semantic runtime authority is now **TB44 / package109 / selector409: 398 PASS / 11 RED / 0 SKIP,
accepted 365/365**, RED `[366,367,368,369,370,374,390,393,398,406,407]`.

## EG8 — CB50 and TB45 falsifiers

The review decision is **approved_with_amendments**: CB49's correction stands, while the newly exposed product
consumer and the over-broad protected-test helper require one narrow Code + Build successor.

`M3-CP4c-3-CB50` is runtime-free and is frozen by
`Architecture_M3_CP4c3_CB50_Code_Build_Plan.md`. It may change only the fragment-corner ray grouping/ownership
projection and the four protected tests' terminal-subject evidence helper/receipts as bounded in EG3/EG6.

After compile/package success, the next artifact-only gate is `M3-CP4c-3-TB45-EXEC`. It must measure, not assume:

1. 366/367 must no longer stop at `FragmentCornerSourceCornerMismatch` on face `10,11,79`; PASS or a later
   independently reviewable fail-closed guard is acceptable, but the same locus falsifies CB50.
2. 390/393/406/407 must execute the real `P_U` predicate, reject same-domain corruption, classify the terminal
   subject `Outside`, and satisfy the correctly typed source-face-or-region terminal evidence branch.
3. Accepted 1–365 remains **365/365**.
4. 368/369/370/374/398 remain at their already owned surfaces; movement is review evidence, not an opportunistic
   correction authorization.
5. 311/312/314/315/356/357/404/408/409 remain PASS; ownership remains 300/0/0; retired-code silence remains.

If 366/367 and the four protected identities all recover while the five carried REDs stay fixed, the aggregate would
be 404 PASS / 5 RED. That is a consequence to measure, **not** a frozen expected vector.

## EG9 — review consolidation and exact successor

Mandatory REVIEW consolidation folds the superseded TB43 runtime/review records, consumed CB49 plan/report and
consumed TB44 execution plan into `M3_CP4c_Consolidated_Record.md`. Their exact bytes remain in Git history and the
folded-document index records each filename/role. The current TB44 EXEC report remains live as runtime authority;
this review record becomes current review authority; exactly one next-turn plan, CB50, remains live.

**Exact successor:** **`M3-CP4c-3-CB50` — Code + Build, runtime-free**, under
`Architecture_M3_CP4c3_CB50_Code_Build_Plan.md`.
