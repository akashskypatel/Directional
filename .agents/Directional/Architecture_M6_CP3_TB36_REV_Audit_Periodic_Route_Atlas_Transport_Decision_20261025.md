# RA-153 — TB36-REV audit: D2 authorized as specified; RA-152 errata; TB37 split (2026-10-25)

**Turn:** `M6-CP3-TB36-RP01-PERIODIC-MONODROMY-BASELINE-REV-AUDIT` (Review). **Subject:** [TB36-REV](Architecture_M6_CP3_TB36_R1_Periodic_Monodromy_Baseline_Independent_Review_Decision_20261025.md). **Decision:** TB36-REV is **accepted**: 0/5 pre-fix baseline, F1 confirmed, successor CB36 (D2 only). Three corrections are binding on CB36 and later turns, plus two errata to my own RA-152. This is static review; I did not re-hash TB36's artifacts and rely on TB36-REV's recorded hashes.

## RA-153.1 — What the baseline establishes

- The RA-152 D3 predictions are confirmed. A3 admits both turning fields (k=1 and k=2): no singularities, route rotation ±k, `make` succeeds. Both reach A4 and end as `PublishedProductRejected(68)`, i.e. the `make` backstop after the producer passed its dead guard. This is the outcome RA-152 allowed, not a STOP.
- The directed-route witness passes its 32-step topology, orientation, kind, compact-id and reversal checks, then fails at the first odd-step assertion. The route really is published with identity steps.
- TB36-REV correctly refuses to name the hidden `make` sub-site, because the logs don't print `publishedProductError`.

## RA-153.2 — Errata to RA-152 (mine)

- **E1.** RA-152 D4 said that `CrossFieldEdgeTransition::sourceEdge` "is consumed by no authority on the atlas path". **Wrong.** A3 rejects `raw.sourceEdge != edgeIndex` with `NonReciprocalAdjacency` (`FieldTransportAtlas.cpp:2020–2027`). The authoritative fail-closed home for 191's property therefore already exists at A3; D4 for 191 reduces to retiring the A4-level body in favour of an A3 negative.
- **E2.** RA-152.6 said D2 changes "route digests and relation ids". Relation ids do **not** change: `periodic_relation_id` hashes `carrier_identity()` (kind, topology, interior id; `AuthorityKernel.cpp:110–129`), not transports. Only the published route step transports change. `oriented_steps()` keeps the observed order (`:91–96`), so the directed-route oracle's index alignment survives D2.

## RA-153.3 — Binding CB36 specification (tightens TB36-REV's wording)

- **Edit site:** `SurfaceCellTracing.cpp:14937–14982` only.
  - Add a first branch `if (transitionLookup.atlas != nullptr)`. In it, take `atlas->transport(*sharedKey, faceCycle[index], faceCycle[(index+1)%n])` and use its `.transport` directly as the step rotation.
  - The existing legacy branches stay as `else if` and keep `from_integer(matching)`.
  - Nothing else changes: the guard at `:15000`, the action, the cut route, the BFS, the overload and `make`.
- **Accessor:** `transport()` (the traversable adjacency), the same accessor branch propagation uses (`:6718–6730`). The sibling `generator_route_for_span` (`:18772`) uses `transition_value()`. The two carry identical raw quarter-turns on traversable edges (`FieldTransportAtlas.cpp:2033–2063`), and `transport()` additionally refuses hard and cross-region edges, which the strip BFS already requires. A periodic route must not cross either.
- **Failure:** a missing transport rejects with `PeriodicHolonomyMismatch` and the loop's existing locus convention `(-1, -1, sourceFace, targetFace, -1, sourceEdge)`.
  - This branch is **unreachable through public inputs**: the strip BFS has already resolved every strip edge through `transport()`.
  - CB36-REV verifies it statically. No runtime witness may be demanded or fabricated for it. TB36-REV's falsifier "missing transport accepted or lacking locus" is static-only.
- **Sufficiency:** the guard checks only the first strip's face cycle. That suffices because every strip loop of the annulus is homologous and A3 has validated every local-vertex cycle, so all strip monodromies are equal.

## RA-153.4 — TB37 split and pre-registered predictions

TB36-REV bundled the witnesses, TB35's 13 cases and a full 497-row census into one runtime turn. That is split:

- **TB37, focused, 16 rows:** the 3 witnesses + TB35's 13, which include 189–195.
  - **Predicted:**
    - k=1 and k=2 **GREEN** (reason 29, locations −1);
    - directed route **GREEN** (route[0] ±1, route[1] its inverse);
    - 189, 190, 193, 194, 195, the face-gauge oracle, both A3 guards and all 3 TB33 controls **PASS**;
    - 191 and 192 **RED unchanged** (`Produced`/`None`), since D1 means their container mutations stay invisible.
  - **STOP → Review if:**
    - k=1 or k=2 still ends in reason 68 (next turn: a test-side diagnostic that prints `publishedProductError`/site, not a production change);
    - 191 or 192 changes disposition, which would mean containers leaked into A4;
    - any TB35 PASS turns RED.
- **TB38, full 497-row census:** a separate turn after TB37-REV, against TB32's 481/500 ledger. Predicted: no accepted-green loss. Any loss → STOP.

## RA-153.5 — Turn sequence

| # | Turn | Scope / gate |
|---|---|---|
| 1 | `M6-CP3-CB36-RP01-PERIODIC-ROUTE-ATLAS-TRANSPORT` | D2 per RA-153.3; compile only. [Plan](Architecture_M6_CP3_CB36_Periodic_Route_Atlas_Transport_Code_Build_Plan_20261025.md). |
| 2 | `…-CB36-…-REV` | Static review; issues the TB37 16-row manifest with the RA-153.4 predictions. |
| 3 | `M6-CP3-TB37-RP01-PERIODIC-ROUTE-ATLAS-VERIFY` → `…-REV` | Focused 16 rows. |
| 4 | `M6-CP3-TB38-RP01-PERIODIC-ROUTE-ATLAS-CENSUS` → `…-REV` | Full 497 census. |
| 5 | `M6-CP3-DEFN-RP01-PERIODIC-LEGACY-ORACLE-HOMES` → CB/TB | D4 with E1: 191 → A3 `NonReciprocalAdjacency`; 192 → k=1 field; 189/190 → A3-level or retired. |
| 6 | Existing queue | Untyped 7 → `focused30:12` → `cp3entry:4` → `selector:442` → DEFN-T1 → census → RP-01 Review. |

**Accounting:** unchanged. Stable 66/17/49, debt 1; CP2 491/491 accepted; TB32 481/500 candidate (19 RED); TB35 11/13 and TB36 0/5 are focused candidates; selector 497 frozen; RP-01 open, RP-02 unreached, Gate C suspended.
