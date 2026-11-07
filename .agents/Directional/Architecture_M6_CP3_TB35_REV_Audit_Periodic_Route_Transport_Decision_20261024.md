# RA-152 — TB35-REV audit: the A4 periodic rotation guard is dead on the atlas path (2026-10-24)

**Turn:** `M6-CP3-TB35-RP01-PERIODIC-ROUTE-GAUGE-VERIFY-REV-AUDIT` (Review). **Subject:** [TB35-REV](Architecture_M6_CP3_TB35_Periodic_Route_Gauge_Independent_Review_Decision_20261024.md) (RA-151). **Decision:** RA-151's evidence verification and non-promotion are **accepted**; its owner statement is **incomplete and partly wrong**; its successor `M6-CP3-DEFN-RP01-PERIODIC-INGRESS-AUTHORITY` is **withdrawn** and replaced by a test-first production track below. Static source review only; no build or runtime.

## RA-152.1 — What TB35-REV got right

- `build_surface_cell_network(CrossFieldResult, …)` (`SurfaceCellTracing.cpp:21160–21177`) passes `nullptr` for matching/effort/transitions whenever `options.fieldTransportAtlas` is set; 191 (`sourceEdge=-1`) and 192 (tracing matching 2) mutate only those discarded containers. Mechanism confirmed.
- 189 (±4 on tracing only) and 190 (legacy compact field as tracing) compare two networks built over the **same** atlas; they cannot discriminate. RA-151.2 accepted.

## RA-152.2 — What TB35-REV missed (production defect F1)

In the periodic-annulus producer's observed-step loop (`SurfaceCellTracing.cpp:14905–15004`) the step matching is read only from `edgeTransitions` (gated on `hasTransitions`) or `edgeMatching`. On the atlas path both are null, and `transitionLookup.atlas` — which `resolve_branch_transition` consults (`:6718–6730`) — is **never read here**. Therefore on the authoritative path:

1. every observed step is `QuarterTurn(0)`; the guard `routeTransport.rotation != 0 → PeriodicHolonomyMismatch` (`:15000`) is **unreachable**;
2. the strip BFS skips the closing edge with the comment "Cycle closure is validated by periodic holonomy below" (`:14369`), so producer-side closure is **unvalidated**;
3. the published `CanonicalRoute` step transports are identity regardless of A3 (the gauged field's raw +1/−1 steps are published as 0), and `SurfacePhaseFrontProduct::make` does not check route steps against the atlas.

A nonzero-monodromy atlas can only be caught later by `make`'s gauge-pin (`:8569–8582`, `InvalidSourceAuthority`, `gauge-pin-consistency`). That is the wrong owner and reason, raised after the producer has claimed success. TB35-REV's sentence "A4 sees the unchanged atlas and therefore a zero canonical route rotation" is **false**: the zero is a constant, independent of any atlas. Its DEFN, which asked for an authoritative nonzero negative, would have yielded a negative that the current producer cannot reject at the guard.

## RA-152.3 — History TB35-REV did not record

At the accepted 449 prefix (`993932656`), 189–192 called `build_periodic_route_network(fixture, field)` with **no atlas**: legacy single-field ingress whose containers the producer read. R3 made A4 require A3; R4 (`7ccdcd527`, 2026-10-11) rewired them through `build_periodic_route_network_with_source_atlas`, which structurally discards the mutated containers. 191/192 became unsatisfiable on that change, not on TB35. 193 is also non-discriminating at A4 today: its "nonzero steps" never reach the route (item 2.3), and its rotation assertion checks a hard-coded identity action.

## RA-152.4 — Contract decisions

- **D1 single writer.** On the atlas path, A4 reads transitions **only** from the atlas. Rejected: passing the containers through, or cross-checking them against the atlas in A4. Either re-admits raw containers as a second writer contrary to R3 and to the overload's own contract; and a cross-check reports a located mismatch, which 192's location-free assertions would not match anyway.
- **D2 F1 owner.** In the observed-step loop, when `transitionLookup.atlas != nullptr`, take each step's rotation from `atlas->transport(edge, source, target)->transport`, the same accessor branch propagation uses. A missing transport fails closed with `PeriodicHolonomyMismatch(face, targetFace)`. The guard itself, the cut route, the action and the legacy branches stay unchanged. Closed-loop composition is gauge invariant, so positives keep rotation 0.
- **D3 witness first.** A real nonzero monodromy must come from a geometrically valid field: rotate each face's raw cross by `α = k·(π/2)·φ/2π` about its normal (φ = azimuth about the cylinder axis), then finalize with the production `finalize_surface_cell_raw_cross_field`. k=2 is A3-admissible for either boundary-loop orientation (correction ≡ 0 mod 4); k=1 is predicted admissible (boundary lifts ±1) and must be measured.
- **D4 frozen bodies.** 189–192 are not edited in this track. After F1 is green, a runtime-free DEFN rehomes them: 192 onto the k=1 authoritative field with all assertions kept; 191 onto A3 ingress integrity, since `CrossFieldEdgeTransition::sourceEdge` is consumed by no authority on the atlas path (A3 keys by vertex pair, `FieldTransportAtlas.cpp:1958–1971`); 189/190 onto A3-level normalization, or retired as legacy-ingress oracles.
- **Carried (RA-152.5).** Tracing axes come from `tracingField` while transports come from the atlas's source field, and nothing binds the two (split authority on directions). This is a candidate obligation, not scheduled; falsifier: an un-relabelled tracing field over a gauged atlas Produces.

## RA-152.6 — Turn sequence (each narrow; independently reviewable)

| # | Turn | Scope / gate |
|---|---|---|
| 1 | `M6-CP3-CB35-RP01-PERIODIC-MONODROMY-WITNESS` | Test-only: helper + 3 witness tests; compile only. [Plan](Architecture_M6_CP3_CB35_Periodic_Monodromy_Witness_Code_Build_Plan_20261024.md). |
| 2 | `…-CB35-…-REV` | Static review; issues the TB36 manifest. |
| 3 | `M6-CP3-TB36-RP01-PERIODIC-MONODROMY-BASELINE` | Pre-fix: 3 witnesses + 191/192. Predicted: A3 accepts k=2 (k=1 measured); all 3 witnesses RED; record first reason. **STOP** if any witness is GREEN pre-fix, if A3 rejects k=2, or if a witness fails before the periodic producer. |
| 4 | `…-TB36-…-REV` | Adjudicate; authorize CB36. |
| 5 | `M6-CP3-CB36-RP01-PERIODIC-ROUTE-ATLAS-TRANSPORT` | Production D2 only (~15 lines in the observed-step loop); compile only. |
| 6 | `…-CB36-…-REV` → `M6-CP3-TB37-RP01-PERIODIC-ROUTE-ATLAS-VERIFY` → `…-REV` | TB37: witnesses GREEN, TB35's 13 cases unchanged except as predicted, **full 497 census**, because route digests and relation ids change. |
| 7 | `M6-CP3-DEFN-RP01-PERIODIC-LEGACY-ORACLE-HOMES` | D4, runtime-free; then one CB/TB pair. |
| 8 | Existing queue | Untyped 7 → `focused30:12` → `cp3entry:4` → `selector:442` → DEFN-T1 → census → RP-01 Review. |

## Accounting

No change: stable 66/17/49, debt 1; CP2 491/491 accepted; TB32 481/500 candidate (19 RED); TB35 11/2 focused candidate; selector 497 frozen; RP-01 open, RP-02 unreached, Gate C suspended. F1 is a candidate production owner (non-stable) until TB36 measures it.
