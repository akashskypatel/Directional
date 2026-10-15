# M6-CP3-TB1-R4-ENDPOINT39-CENSUS — artifact-only execution report

**Execution completed mechanically. All 39 tests RED; no runtime acceptance or promotion.**

## Reproducible authority and receipts

- Repository: `akashskypatel/Directional`; working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`; PR #8 remains draft/open.
- Run: https://github.com/akashskypatel/Directional/actions/runs/38687783618 (success); immutable package artifact `11939982141` from semantic SHA `953f812ff1f431e3ad3af3b68a92284a7831c94a`.
- Result artifact `11950303475`, ZIP SHA-256 `3bce344f3a13403a830a2800fea4c47d1e7cdd53f6f3eac6629de57d70788b32`; complete output logs and per-identity ledger are in that artifact.
- Harness commit `d18f3d43ce528402419d0309d873e13395cec971`; harness SHA-256 `4dd5c605710c65317b2f524d0d3bed83602b7922ceec4bab87062374407c40f6`. Dispatcher commit `3d3610935d0a5c3bd9adb1ce3e0874c760db8931`.
- 39/39 independently selected/executed; 0 PASS, 39 RED, 0 missing. Postflight true, exit=0, 28/28 checksums verified before and after, package/source/execution view/selector immutable. No configure, rebuild, relink, benchmark or frozen 497 execution.
- All 39 are in the 94-row R3 RED register; they reproduce **previously observed, unaccepted** failures. Membership of frozen selectors: focused30=9, focused12=2, selector449=26; 2 are in no selector. No stable event or recurrence is minted; unchanged 66/17/49, debt 1, CP2 491/491 and R3 403/497 (94 RED, 88 carried losses).

## Observed first failure loci

| Classification | Count | Interpretation |
|---|---:|---|
| A4 tracing/phase-front hard-rail terminal certification; `endpoint-1` / `no-exact-terminal-corner` | 38 | The measured open-hard-rail carrier, including variation in field angle and source-edge parameter. |
| A4 tracing/phase-front hard-rail terminal certification; `endpoint-0` / `missing-terminal-or-closed-rail-provenance` | 1 | Distinct first predicate; do **not** silently merge into the endpoint-1 classification. |

- The endpoint-0 identity is `SurfaceCellAuthorityContractCutover.FixedConformityPlanTargetPerturbationPreservesSharedBoundaryIntervals` (historical ordinal `405`).
- Every failure log reports `routeLength=1`, `step=0`, `closedChainPresent=0`. `chi=3` for two nonconstant hard-rail identities; remaining 37 report `chi=0`. Full exact probe charts and source-edge parameters, edge records, rail/locus and `faceEnds` are retained in the 39-row TSV. `faceEnds` is **an echo**, not independent corroboration (RA-56.1/RA-57.12).

## Fixture authority (per identity)

- `hard_rail_fixture` static singleton: 17 identities; fixture threw before test-body completion.
- `nonconstant_hard_rail_fixture` static singleton: 2 identities; fixture threw before test-body completion.
- Per-test `build_rectangular_hard_rail_phase_front` helper: 12 identities; no shared static singleton; invocation rejected during the test.
- Per-test `remesh_from_raw_cross_field` pipeline: 2 identities; no shared static singleton; first failure records an A4 diagnostic.
- Direct independent test construction: 6 identities; no identified shared static singleton.
- RA-58.9 applies: merge failures only as one *fixture failure* when the shared singleton threw. The 19 singleton-dependent REDs are not 19 independent carrier defects. Remaining failures should not be merged merely because diagnostic strings match.

## What is and is not established

The census strengthens the measured breadth of open hard-rail terminal rejection across the 39 R3 identities, including a distinct endpoint-0 predicate. It does **not** distinguish (a) an overly strict terminal certificate, (b) incorrect pairing, or (c) truncated routing. It does not reach or discharge `RP-02` network-bound acceptance, and does not resolve unrelated A5/A6/A7 torus failures from RA-58. Neither the complete 497 selector nor the two historically gated Phase14 tests ran. No source/validation/selector changes and no hypothesis selection were authorized.

**Next mandatory turn:** `M6-CP3-TB1-R4-CARRIER-REV`, independent Review, to adjudicate carrier and select whether/how a certificate repair is justified. The retained Code+Build repair remains held; its along-rail wording must reflect RA-57.5 *across-rail* geometry.

## Process transparency

Before switching to the exact verified source snapshot, several direct repository document reads were performed. This violated the conservation policy’s snapshot pre-read gate. Subsequent source analysis used the verified snapshot; this procedure miss is recorded and not treated as acceptance evidence. The snapshot workflow itself succeeded: run `38687362949`, artifact `11950373352`, outer SHA-256 `2907ca6d0d18873e609cc4058043e4f7e6306316b168439f15a52a628ebe6cea`.

## Machine-readable inventory

The companion `endpoint39-measurements.tsv` contains all 39 exact identities, original historical ordinals, source first-failure excerpts, first pipeline locus and predicate, observed/missing evidence fields, fixture construction state, R3 classification and all three selector memberships, and a SHA-256 of every individual GTest log. “NOT_OBSERVED” is used instead of invented values. The original result ZIP is retained intact.
