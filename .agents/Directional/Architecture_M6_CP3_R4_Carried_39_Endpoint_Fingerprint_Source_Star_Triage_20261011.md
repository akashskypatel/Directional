# M6-CP3-CB1-ENTRY-R4 — 39 historical carried endpoint failures: fingerprint and source-star triage

**Authority and boundary:** independent static inspection of exact GitHub source snapshot `e1510e64794bf6525dbb3fcfb97cc30b67b4ff9c` (workflow `38143011034`, outer SHA-256 `097675c1ae1bcf485f2ae212ad7699b1a77694b6f36e038afb1e1b0fdf4eed33`, inner archive verified; 6,169/6,169 source SHA256SUMS entries checked, `runtimeExecution=false`). Historical failure authority is the frozen `Architecture_M6_CP3_TB1_Entry_R3_Independent_94_Review_Overlay.tsv`, not a new runtime observation. This note changes **no production code, selector, assertion, definition, or accepted regression count**. The R4 Code + Build turn remains incomplete; no TB497 execution is authorized here.

## Frozen R3 fingerprint census

The independent 94-RED overlay contains **39** rows with `observed_first_failure_class=A4_ROUTE_CERTIFICATE_REJECTION`, all owned by `directional_surface_cell_producer_tests` and all marked CP2 accepted in the recomputed overlay column. Of these:

| First R3 diagnostic prefix | Frozen count | Correlated signature |
|---|---:|---|
| `predicate=endpoint-0;...front=17,203;...edge[0]=1,4:faces=0,3:chi=0` | 17 | internal-midline hard-rail rectangle source |
| `predicate=endpoint-0;...front=13,131;...edge[0]=1,4:faces=0,3:chi=0` | 12 | rectangular hard-rail cutover / fixed-plan family |
| `predicate=endpoint-0;...front=17,203;...edge[0]=1,4:faces=0,3:chi=3` | 2 | nonconstant χ variant of the hard-rail fixture |
| Different leading failures (callbacks, final-oracle assertions, or injection expectations) | 8 | related downstream families, **not** the same proven first predicate |
| **Total** | **39** | 31 shared hard-rail endpoint fingerprints and eight distinct observed symptoms |

**Interpretation limit:** 31 matching historical diagnostic fingerprints may have one or several common roots. They are *not* 31 independent geometrical counterexamples and are *not* 31 accepted recoveries. Do not assume the other eight passed their A4 source gates: their first observable fixture/callback failures differ. The R3 diagnostics predate recent A2b production diagnostics and cannot prove today's first rejecting predicate.

## Source-real fixture facts (independent from test assertions)

`tests/SurfaceCellTransitionQuotientTests.cpp` `make_hard_rail_fixture` (approximately 585–642) and `make_nonconstant_hard_rail_fixture` (approximately 776–855) construct the same oriented **3×3 vertex, eight-triangle** planar source mesh. Both request the actual hard-feature chain `{1,4}` and `{4,7}` and use the production `remesh_from_raw_cross_field` with `allowSourceGridRecovery=false`. The latter variant rotates source cross-field labels for faces with geometric centroid X greater than 1 and can permute source-face row order.

One independently enumerated source-face incidence table is:

| Face index | Source vertices |
|---|---|
| 0 | `(0,1,4)` |
| 1 | `(0,4,3)` |
| 2 | `(1,2,5)` |
| 3 | `(1,5,4)` |
| 4 | `(3,4,7)` |
| 5 | `(3,7,6)` |
| 6 | `(4,5,8)` |
| 7 | `(4,8,7)` |

Source terminal vertex `1` has incident faces `{0,2,3}`. Hard carrier spoke `{1,4}` borders faces `{0,3}`, and non-hard interior spoke `{1,5}` connects `{2,3}`. Source terminal vertex `7` has faces `{4,5,7}`: carrier `{4,7}` borders `{4,7}` (face **indices**, not vertex IDs), and non-hard `{3,7}` connects faces `{4,5}`. Interior junction vertex `4` has faces `{0,1,3,4,6,7}` and two hard incident spokes `{1,4}` and `{4,7}`. Thus the fixture has legitimate, *nontrivial* non-hard source-star path opportunities; a direct-face-only endpoint assumption is not justified.

These are **topological opportunities, not proof that traced `SurfaceTracePoint` barycentric endpoints are exact source corners**. A2b must authenticate genuine source-corner contact and unique nonhard A3 walks. In `src/geometry/SurfaceCellTracing.cpp` `endpoint_certificate` (approximately 18917–19077), the producer explicitly requires both points' exact corner barycentrics at a hard-carrier incident terminal vertex, a real contact, reciprocal A3 spokes, separated sectors, and a unique non-hard simple path to each carrier side. A4 reconstructs terminal path uniqueness independently in `SurfacePhaseFrontProduct::make` (approximately 8284–8355). Passing a forged direct carrier or invented contact is not a legitimate repair.

## Diagnostic reconciliation and corrective boundaries

Current production source has post-rejection `a2bProbeFailure`, `a2bProbeCarrierPresent`, `a2bProbeA3Present`, `a2bProbeContactPresent`, `corner[vertex]`, and `railEnd[vertex]` in the existing typed `InvalidHardRailRouteCertificate` endpoint diagnostic (approximately 19085–19135), and distinguishes `missing-terminal-A3-path` from `ambiguous-terminal-A3-path`. These **new diagnostics were compiled but have not been exercised by an authorized R4 runtime run**; no present-time failure histogram exists. Preserve the historical `endpoint-0` first-order rejection until real evidence shows a different first predicate.

Prescriptive next Code + Build analysis, without touching the frozen selector: (1) map the exact `first.from` and `second.to` trace endpoints to source face and barycentric coordinates for the fixed hard-rail fixture; (2) compare the *actual* terminal contact vertices and incident carrier edges with the enumerated stars; (3) if endpoints are not exact source corners, trace where producer trajectory endpoints are assigned and repair the producer's genuine source contact under accepted A2b rather than relaxing exact-corner checks; (4) if the path is absent, investigate face/spoke continuity and source A3, not fabricated nonmanifold second paths; (5) if the first failure is upstream in source/plan/conformity or in downstream callback, record that separately; (6) preserve fixed-run identities and quantify only against a separately authorized, immutable artifact-only Test + Benchmark result. Stop for independent Definition/Review if authentic source topology must change.

The separate independent two-admissible-path design question remains with `Architecture_M6_CP3_R4_Terminal_A3_Uniqueness_Design_Review_Request_20261011.md`; this census does not settle it. No 39 endpoint PASS, 34 Phase10 PASS, seven DCEL negative PASS, 88 CP2 restored PASS, six CP3 gate, or odd-τ/multi-carrier acceptance is inferred here.
