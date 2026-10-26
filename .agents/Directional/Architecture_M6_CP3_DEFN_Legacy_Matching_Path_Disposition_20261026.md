# M6-CP3 DEFN — legacy matching-path disposition (2026-10-26)

Boundary: definition only. Source snapshot 2f183f9139a1e500132190e0e4957b2eb62d3c84. Next turn: M6-CP3-DEFN-RP01-LEGACY-MATCHING-PATH-DISPOSITION-REV. No code, test, selector, compile or runtime change.

## Q1 — selector190 vacuity
tests/SurfaceCellsPhase10Tests.cpp:4561–4599 modifies only copied matching/effort and clears edgeTransitions; :5171–5195 passes that legacyField alongside authoritativeField. Helper :4490–4516 creates A3 from authoritativeField. src/geometry/SurfaceCellTracing.cpp:21175–21192 takes the atlas-present overload, nulling all three legacy containers; the field axes remain unchanged. A4 :14926–14979 selects atlas transport first. Therefore the altered legacy data determines no published route/periodic value. Equality under this fixture is an atlas-versus-atlas tautology, not legacy-transport evidence.

## Q2–Q3 — selector190 disposition and accounting
Re-home under exactly the existing selector190 identity/name without changing selector449/497 bytes. A test-only CB should make own-field authoritative FieldTransportAtlas::make succeed, but make(legacyField) with missing edgeTransitions fail with FieldAtlasBuildErrorCode::MissingAdjacency and the first independently enumerated canonical interior source-edge key (FieldTransportAtlas.cpp:1981–2018). Assert the source mesh has an interior edge; restoring transition metadata must make the original A3 valid. STOP if another code/key is returned.
Historical 190 acceptance within CP2 491/491 (2026-10-06) is unchanged as historical legacy-only credit, now void under D1/RA-40; it is not new current-path evidence. TB38/TB41 190 PASS rows are vacuous focused candidates only. Accepted selector449 SHA256 d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414 is unchanged.

## Q4 — O2 complete non-atlas matching inventory
- SurfaceCellTracing.cpp:21182–21192 raw wrapper: missing A3 can enter detail traversal but checked phase-front factory :8459–8470 rejects before published product. Preserve exact fail-closed first code/site.
- :6688–6819 resolve_branch_transition: authoritative atlas first; absent atlas, raw edgeTransitions then compact matching/effort; :6822–6857 geometric nearest-arm fallback. Non-atlas branches have reachable detail consumers in SurfaceCellFieldTransitionAuthorityMigration tests :489–611. The accepted-prefix test LegacyMatchingFallbackRemainsUnchangedWhenTransitionMetadataAbsent :589–611 depends on compact fallback; the other five detail tests use raw transitions.
- :6970–7093 vertex continuation uses shared branch resolver. Off-gate/O5 LegacyMatchingPathUsesSameTypedRouteComposition :5716–5735 uses null transitions and asserts legacy detail behavior. Accepted ContinuationFacePathPreservesIndependentCompactRouteAuthority requires separate static consumer census.
- Periodic :14258–14265, :14926–14979, :15034–15036: A3-present publication consumes atlas; missing A3 reaches rejection only, not A4 published output. Selector190 is vacuous in its current form.
- Planar/bounded/isolation :11877–12081, :12559–12563, :16232–16437, :18070–18174 reuse the resolver; inventory every resolve_branch_transition, resolve_vertex_continuation, build_surface_cell_network and null fieldTransportAtlas call before deleting shared fallback.

## Q5–Q6 — bounded correction
One test-only CB may re-home 190, restricted to tests/SurfaceCellsPhase10Tests.cpp; require genuine positive own-field A3, negative MissingAdjacency canonical edge-key and anti-vacuity restoration. No selector edit. One later production CB, only after independent DEFN Review, may edit src/geometry/SurfaceCellTracing.cpp to remove unreachable production-facing no-atlas dispatch while preserving the precise checked rejection code/site. Do NOT delete shared detail fallback used by accepted and off-gate test identities. Code+Build turns compile only and are separate; independent TB and Reviews own runtime.
STOP on no-atlas published product, unexpected A3 code/key, changed first rejection, still-active published legacy read, broken accepted identity, or need to modify frozen selector497 bytes. O2 detail-only retirement remains separate Review-owned work. Carried O1/O4/O5/O6, 242, DEFN-SEAM-NZ, DIAG-RETAIN unchanged. Stable 66/17/49 debt1, CP2 491/491 accepted, selector497 frozen, RP-01 open; no promotion.

## Review closeout
| Duty | Disposition |
|---|---|
| Accepted selector prefix | Preserved; 449 SHA256 d4a0d1b7…d6414; no changed bytes |
| Evidence re-derived | A3 helper, atlas wrapper, A4 transport, detail fallback call sites |
| Non-vacuity | 190 current proof vacuous; proposed independent typed A3 negative |
| Previous obligations | Six questions answered; O2 detail and other owners carried |
| Accounting | Stable 66/17/49 debt1; CP2 491/491 historical only |
| New candidate | 190 A3 oracle re-home and O2 detail coexistence, no stable event |
| ORIENTATION currency | Synchronized on 2026-10-26 with Review successor and current accounting; local static drift audit 0 errors / 0 warnings |
| ORIENTATION §3/§4/§7/§8 | Stable/witness tables unchanged; priority and vacuity note in prepared patch |
| CHANGELOG | Prepared in preservation patch |
| ROADMAP | Unchanged; RP-01 remains open |
| Selector manifest | Unchanged |
| LESSONS | No new durable rule beyond existing independent-oracle principle |
| Consolidation | No stale record safely removed in this scope |
| Successor | M6-CP3-DEFN-RP01-LEGACY-MATCHING-PATH-DISPOSITION-REV |
| Boundary | Definition only; no source/test/selector/compile/runtime |
| review_check.py boundary | Snapshot has no authentic Git history; no passing result claimed |
| STATUS | Entry beacon written; closeout beacon pending |
| Origin sync | Definition record committed; handoff, ORIENTATION, tracker, CHANGELOG, TODO applied at `e404dc9e4e574a34be052b4fb9efa791d3c68f5b` (five exact paths, checked result hash); Drive staged copies retired; cleanup at `1693c76fb93e825be4868c90e3c94ba1e2562bf2` |
