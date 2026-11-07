# RA-156 — TB39-REV audit: selector250 rail-authority owner bound and promoted (2026-10-25)

**Turn:** `M6-CP3-TB39-RP01-SELECTOR250-FACTORY-SITE-HARVEST-REV-AUDIT`. **Verdict:** TB39-REV's classification is **accepted**: the factory check that fires is `hard-rail-contact-missing`, owned by the test fixture and not by O1. Its corrective requirement and its sequencing are **replaced**. Static review only; no source, test, selector or harness change.

## RA-156.1 Independent verification

- TB39 result `12609665120` re-downloaded: ZIP `10af6fa8…1f06`, **17/17** `SHA256SUMS`, and the 7 ledger log hashes match the raw logs. 7/7 run, 6 GUARD PASS, 250 RED; 0 missing/skipped/duplicate/control_bad/unexpected_pass; postflight true; no compile, relink or configure. Manifest `a304aeeb…cc61` re-hashed.
- `raw/1.log:13`: `PublishedProductRejected publishedProductError=0 publishedProductSourceAuthorityDetail=6 site=hard-rail-contact-missing`. These values decode to `InvalidSourceAuthority=0` (`SurfaceCellTracing.h:1901`) and `MissingRailTerminalContact=6` (`:1932`). The only site is `SurfaceCellTracing.cpp:8655–8661`: the fixture has hard-feature edges but no terminal contacts and no closed chains.

## RA-156.2 Gaps in TB39-REV

- **J1 — the corrective requirement is under-specified, and it names the wrong owner.**
  - Test 250 (`SurfaceCellsPhase10Tests.cpp:3610`) already calls `make_curved_disk_fixture()`. That fixture builds the disk's full rail authority through the production functions at `:2582–2626`: `build_authoritative_surface_cell_rails`, then `hard_rail_source_provenance_from_rails`, plus the check `hard_feature_edge_keys_from_rails == hardFeatureEdges`.
  - Test 250 copies only `disk.vertices` and `disk.faces`. It re-inserts the 8 boundary hard edges (`:3647–3660`) and **drops all four authority fields**: `authoritativeRails`, `hardRailTerminalContacts`, `hardRailClosedChains` and `hardRailOpenChains`.
  - So the defect is not only "missing factory provenance". Without `authoritativeRails`, A4 tracing also gets no hard-rail seeds for the disk sheet (`SurfaceCellTracing.cpp:10285–10310`). Test 250 therefore never exercised the disk contract that the passing tests 199, 235 and 236 exercise.
  - Supplying only contacts or chains would get past the factory check while leaving tracing on a different contract. "Derive provenance where possible" is not a binding requirement.
  - The binding requirement is RA-156.3: derive all four fields from one combined-mesh feature map, through the production functions, which is the same path as `RemeshPipeline.cpp:12633–12785`.
- **J2 — sequencing.** Test 250's owner was placed last when the owner was unknown. It is now known, small and test-only. 250 is the only positive periodic-plus-disk composition, so its outcome decides whether RP-01 still has an unmeasured positive-path prerequisite downstream (O1 among them). The A/B/C re-homes are negative-oracle hygiene and nothing downstream depends on them. **The 250 owner moves first.**
- **J3 — new observation O3: the polygonal-disk rejection tests share the same omission and are vacuous on the reason alone.**
  - The polygonal fixture (`:2818`) supplies hard edges but no rail authority.
  - Three tests assert only `InvalidBoundedDiskFrontPairing`: 252 (`:3764`), 251 (`:2971`, forward and reversed runs) and the off-selector `PolygonalCurvedDiskRejectsWithoutPublishingPartialPhase` (`:2936`). That reason is emitted at 5 sites (`SurfaceCellTracing.cpp:17190, 17889, 17948, 17969, 18034`).
  - Only the designed non-rectangular site (`:17184–17191`) leaves both `cell` and `side` at −1; every other site sets one of them.
  - 17969 depends on `path_on_authoritative_boundary`, which uses rail authority. So a run with missing rails could satisfy the oracle at an unintended site.
  - Fix (test-only, CB42): in those three tests, also assert `rejection()->cell == -1 && rejection()->side == -1`.
  - Inventory only, not in CB42: the off-selector `CurvedBoundedDiskPhaseFrontIsStructurallyApplicable` (`:3380`) accepts any of four rejection reasons.
- **J4 — guard selection.**
  - The focused positive disk witness `CurvedBoundedDiskPhaseFrontIsStructurallyApplicable` (`:3380`) is outside selector497 and unmeasured.
  - The `MissingRailTerminalContact` negative `M6CP3.CheckedFactoryRejectsForgedTerminalA2bSideGerm` (`SurfaceCellTransitionQuotientTests.cpp:10092`) was last measured RED (R4, 2026-10-15).
  - Neither may be a GUARD. Use the in-selector PASS rows 199, 235, 236, 249, 251 and 252 instead.
- **J5 — documentation drift.** The handoff Turn Sequence jumped from "1" to "4", and "CB38-A" is not a canonical turn name. Both are corrected below.

## RA-156.3 Bound spec — `M6-CP3-CB38-RP01-SELECTOR250-RAIL-AUTHORITY` (Code + Build, test-only, compile only)

- **Edit:** only the body of test 250, inline, with no new helper.
- Build an `AdaptiveFeatureMap` on the combined `mesh`:
  - one closed `Hard` curve with `component=2`;
  - ring `{0,1,2,5,8,7,6,3,0}` plus `diskOffset`;
  - each edge's `incidentFaces` computed from the combined `faces`; the test throws if any edge does not have exactly 1 incident face.
- Call `build_authoritative_surface_cell_rails(mesh, features)`. Require that it produces exactly 1 closed rail.
- Set `options.authoritativeRails` and the three provenance maps from `hard_rail_source_provenance_from_rails(rails, mesh.V.rows())`.
- Require that `closedChains` is non-empty and `hard_feature_edge_keys_from_rails(...) == options.hardFeatureEdges`. Do this before `build_phase10_with_source_atlas`.
- **Unchanged:**
  - the 8 `hardFeatureEdges` insertions;
  - the assertion at `:3666` and its CB37 message;
  - every later assertion;
  - `make_curved_disk_fixture`;
  - production code, selectors, the harness and workflows.
- **STOP and return to Review if:**
  - the rail builder rejects (for example, because component 2 is not the disk's connectivity component);
  - the edge-key identity differs;
  - any edit outside test 250 or the helper is needed.

## RA-156.4 TB40 manifest outline (CB38-REV freezes it; unmodified harness `436f5fff…`)

- **Test 250 row:** kind `RED`, expect `RED`. The outcome is genuinely open. A PASS is recorded as `unexpected_pass`, which is the success signal. A new rejection is a newly measured prerequisite and must not be patched inside TB40.
- **GUARD rows:** 199, 235, 236, 249, 251, 252, the three TB36 witnesses, and 193–195.
- **TB40-REV:**
  - if 250 PASSes, record it as a discharged candidate (no promotion);
  - otherwise, bind exactly one owner for the new first failure.

## RA-156.5 Sequence (supersedes RA-155.6 order and the TB39-REV order)

1. CB38 (250 rail authority) → CB38-REV, which freezes the TB40 manifest.
2. TB40 → TB40-REV.
3. CB39-A (191 and 204 → A3 `NonReciprocalAdjacency`; RA-155.3 A) → REV.
4. CB40-B (192 with k=1, 247 with k=2; RA-155.3 B) → REV.
5. CB41-C (189; RA-155.3 C) → REV.
6. CB42-O3 (pin the polygonal locus at `cell=-1`, `side=-1` in 251, 252 and `:2936`; J3) → REV.
7. TB41 focused run (189, 191, 192, 204, 247, 251, 252, plus guards) → REV.
8. `M6-CP3-DEFN-RP01-LEGACY-PATH-AND-SEAM-ORACLES` (190, 242, O2) → REV.
9. Any owner bound by TB40-REV, then 405 → 174, 201 → `focused30:12` → `cp3entry:4` → `selector:442` → DEFN-T1 → census → RP-01 Review.

Carried: `DIAG-RETAIN`, O1, O2, O3 (until CB42), RA-152.5, DEFN-SEAM-NZ, RA-146.2/4, RA-45.4, G4-B002.

**Accounting unchanged:**
- stable 66/17/49, debt 1;
- CP2 491/491 accepted;
- TB32 481/500 and TB38 490/504 candidate;
- selector497 frozen;
- RP-01 open; RP-02 unreached.
