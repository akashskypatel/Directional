# RA-160 — Legacy matching-path DEFN Review: 190 re-home amended; O2 production CB withdrawn (2026-10-26)

**Turn:** `M6-CP3-DEFN-RP01-LEGACY-MATCHING-PATH-DISPOSITION-REV`, run by the Review Agent. **Decision:** the [DEFN](Architecture_M6_CP3_DEFN_Legacy_Matching_Path_Disposition_20261026.md) is **ACCEPTED IN PART**.
- Q1–Q3 are accepted. Q2 is amended (RA-160.3).
- Q4–Q5 are **rejected as incomplete**, so the Q6 production CB is **not authorized**.
- O2 retirement moves after RP-01 (RA-160.4).

Method: static review on source `639730d06`, with no `src`/`tests` change since snapshot `2f183f913`. The selector449 SHA-256 `d4a0d1b7…d6414` was recomputed and is unchanged. No build or runtime.

## RA-160.1 Verified claims

- **Q1 is correct, and stronger than RA-159 N2.**
  - When an atlas is present, `build_surface_cell_network(crossField)` passes `nullptr` for matching, effort and transitions (`SurfaceCellTracing.cpp:21182–21185`).
  - So `hasTransitions` is false in **both** 190 runs (`:14260`), and the provenance lookup at `:14926–14929` is identical.
  - `legacyField` is completely inert: it contributes only its axes (`:11508–11512`), which are copied unchanged.
  - **Correction to RA-159 N2:** RA-159 N2 said `legacyField` "selects the provenance lookup". That is wrong.
- **Q2 is feasible.**
  - `make(legacyField)` passes the preamble (`FieldTransportAtlas.cpp:1898–1912`; `matchingComputed`/`singularitiesComputed` are copied) and frame building, which reads only directions (`:257–260`).
  - The empty `edgeTransitions` then fails at the first interior edge in sorted key order with `MissingAdjacency` (`:1981–2018`).
- **Q3 is accepted.** CP2 credit for 190 is historical. The TB38/TB41 rows are vacuous. Selector bytes are unchanged.

## RA-160.2 Defects

- **D1 — the Q2 re-home duplicates accepted coverage and drops the only pin the O2 work needs.**
  - A3 `MissingAdjacency` is already accepted at `selector:28` (`FieldTransportAtlas.RejectsStableAdjacencyTamperReasons`, `FieldTransportAtlasTests.cpp:2576–2593`).
  - Meanwhile **no test** pins the A4 no-atlas ingress outcome: `"atlas-binding"` appears in no test.
  - Yet the DEFN's production CB requires "preserving the precise checked rejection code/site". That condition has no oracle, so it could not be reviewed.
- **D2 — Q4 is false for NotApplicable inputs.**
  - The DEFN says missing A3 "reaches rejection only". That holds only when a phase-front producer runs.
  - For a no-feature input where every region is NotApplicable (`:18473–18481`), `publish_phase_front_result` returns NotApplicable (`:13158`) and the factory is never called.
  - The builder then runs the seed-tracing fallback (`:20661–21160`). It passes the **legacy containers** to `trace_surface_field` and `make_surface_cell_proposal`, and publishes `seeds`/`traces`/`proposals` (`accepted=true`) and `singularSeparatrices`.
  - So on test-only no-atlas ingress, legacy matching **does** decide published network outputs. This is the "legacy no-atlas entry contract" named at `:5802`.
- **D3 — Q4 omits public crossField APIs that ignore the atlas.**
  - `trace_surface_field(crossField)` (`:11527–11538`) always passes legacy containers, even when an atlas is set; it is atlas-first only because `resolve_branch_transition` checks the atlas first (`:6718`).
  - Its production caller `FlowRepStrands.cpp:3511` receives the pipeline options that carry the atlas (`RemeshPipeline.cpp:12979 → 13491`), so production is safe today. But removing branches without this inventory is unreviewable.
- **D4 — Q4/Q5 defer the inventory they were asked to deliver.** The planar, bounded and isolation call sites, and selector233, are left to a "separate census". Selector233 actually passes `&fixture.transitions` with no atlas: the raw-transition branch (`Phase10Tests:5687`).
- **D5 — a fail-open default is unflagged.**
  - The periodic step leaves `stepRotation` at identity when there is no atlas, no transitions and no matching (`:14937–14979`; there is no `else` rejection).
  - The DEFN's "preserve first code/site" removal would require keeping this fail-open fall-through so the factory can still reject.
  - The correct design rejects no-atlas ingress at one entry gate. That changes the rejection locus, and it is a design decision for the post-RP-01 DEFN.

## RA-160.3 Amended 190 re-home (test-only CB43)

All halves stay in `SurfaceCellPeriodicHolonomyRouteTransportAuthorityMigration.LegacyMatchingPathUsesSameTypedAlgebra` (`Phase10Tests:5171–5195`), with the same identity. Selector bytes do not change.

- **(a) Positive.** Keep the authoritative network: Produced, with one periodic holonomy.
- **(b) A3 negative.**
  - Build A2 as the helper does (`:4496–4503`).
  - `make(fixture.mesh, A2, {}, legacyField)` fails with `MissingAdjacency`.
  - `error.sourceEdge ==` the minimum interior `test_source_edge_topology` key, enumerated independently from `fixture.mesh.F` incidence. Assert that the interior set is non-empty.
- **(c) Anti-vacuity.** A copy of `legacyField` with `edgeTransitions` restored from `authoritativeField` builds A3 successfully.
- **(d) A4 legacy ingress, the new pin.**
  - Use the crossField overload with options that have the same components and sheets, `fieldTransportAtlas == nullptr` and `sourceAuthority == nullptr`.
  - Assert:
    - `Rejected`;
    - `PublishedProductRejected`;
    - `publishedProductError == InvalidSourceAuthority`;
    - detail `AtlasSourceMismatch`;
    - site `"atlas-binding"`;
    - `produced_product() == nullptr`;
    - empty `seeds`/`traces`/`proposals`.
  - Stream the reason name, the error, the detail and the site.
  - This exercises the compact-matching branch `:14966–14979` up to the factory, and pins the locus that any later O2 change must preserve or explicitly re-bind.
- **Must not change:** any other test, production source, selectors, the harness or workflows. `make_legacy_periodic_route_field` stays (190 is its only consumer).
- **STOP → Review:**
  - a needed accessor or enum is not visible;
  - a production edit appears necessary;
  - selector bytes would change.
  - A runtime mismatch in (d) is a TB43 finding for Review to re-bind. It is **not** a CB fix.

## RA-160.4 O2 disposition

O2 is **not on the RP-01 critical path**: production always supplies an atlas (`RemeshPipeline.cpp:12971–12979`), and the checked factory rejects a null atlas. The Q6 production CB is withdrawn.

O2 moves to the post-RP-01 `M6-CP3-DEFN-POSTRP01-O2-NO-ATLAS-INGRESS-RETIREMENT`, which must decide:
- the NotApplicable seed-fallback contract (D2);
- the crossField API overloads (D3);
- every no-atlas detail consumer, including selectors 179 and 233 and `Phase10Tests:489–611, 5716`;
- an entry-gate design versus the factory locus (D5).

## RA-160.5 Turn sequence (frozen IDs)

1. `M6-CP3-CB43-RP01-SELECTOR190-LEGACY-INGRESS-REHOME`: test-only, compile only. Then `…-REV`, which is static and issues the TB43 manifest.
2. `M6-CP3-TB43-RP01-SELECTOR190-REHOME-VERIFY`: artifact-only on the targeted harness and the CB43 package.
   - Rows: 190 POSITIVE; GUARD `selector:28`, `selector:179`, `selector:233`.
   - Then `…-REV`.
3. `M6-CP3-DEFN-RP01-A4-PROVENANCE-GUARD-REACHABILITY` (O4) → REV.
4. `M6-CP3-DEFN-RP01-SELECTOR242-CROSS-REGION-SEAM-CONSUMER` → REV.
5. The CB/TB turns those authorize.
6. 405 → 174, 201 → `focused30:12` → `cp3entry:4` → `selector:442` → DEFN-T1.
7. O5 DEFN → REV.
8. Census → RP-01 Review, with the O6 scope statement.
9. After RP-01: the O2 DEFN.

Carried: DIAG-RETAIN, O1, O2 (post-RP-01), O4, O5, O6, RA-152.5, DEFN-SEAM-NZ, RA-146.2/4, RA-45.4, G4-B002.

**Accounting unchanged:**
- stable 66/17/49, debt 1;
- CP2 491/491 accepted;
- TB32 481/500 and TB38 490/504 candidate;
- TB41 18/18 and TB42 1/1 focused candidate;
- selector497 frozen;
- RP-01 open.
