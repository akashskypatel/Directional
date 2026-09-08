# M3-CP4c-3-TB39 Independent Review Record

Date: 2026-09-08 UTC
Turn: `M3-CP4c-3-TB39-REV`
Type: **Independent Review + Plan / evidence-only / NO RUNTIME**
Verdict: **TB39 PROMOTED / DEFN-R6 REGION-EULER AUTHORITY WITHDRAWN / ACTUAL-EMBEDDED-FACE AUTHORITY RE-DERIVED / DEFN-R7 REQUIRED**

## 0. Scope and evidence authority

This turn ran no Directional runtime, compile, benchmark, package operation, or product/test/fixture/selector mutation.
Review authority was the exact repository snapshot run `34184340359` at control/document head
`7253a1b93fa4d09f74846850502e31020799ff0a`, together with immutable TB39 runtime artifacts:

- package104 semantic source `8756cfe983bf7e05209f560d59a522a6b5b0674a`;
- TB39 run/job `34177823202 / 101910682975`;
- result artifact `10037931111`, SHA-256
  `8b84cfec3b735d10511c4ca11c40d34180ed134122e885a4fd431e17d1b63b4f`;
- log artifact `10037931384`, SHA-256
  `4353665ba54dd8cff63904388195ff3f795a03b9d1937a8dd56fce5ffdcd3a09`;
- selector409: **402 PASS / 7 RED**, accepted **365/365**, RED `[366,367,368,369,370,374,398]`;
- ledger SHA `058c54603bfe4663578d174531932fa9c9716e905f48a1b2feb1b26656171366`;
- **513** non-empty Euler-certificate rows with zero missing fields and all five frozen arithmetic identities true.

The source-snapshot artifact is `10039986522` (provider ZIP SHA-256
`a6fc8634e347a005247611d0fc66b486ce25bf8347ca59a83e0fd0bada9ae8fd`), archive SHA-256
`c4d7589d66e52a73c5012ee9349876afe06a57fdbaf8894a244ced0a75a354c2`; its snapshot job
`101929588910` succeeded with `runtimeExecution=false`.

### Process-order note

Before `READ_MODE` was explicitly selected, this turn performed several direct repository-document reads. That is a
process-order miss under `TOOL_USE_CONSERVATION_POLICY.md`, not semantic evidence. Piecemeal inspection stopped as
soon as the miss was recognized; the turn then selected `READ_MODE=snapshot`, materialized the exact snapshot above,
and performed the substantive review locally. No semantic source or runtime authority changed because of the miss.
It is a third instance of `LESSONS.md` 152 and changes no regression accounting.

## DB0 — TB39 is mechanically valid and is promoted

TB39 satisfies every frozen restoration gate from the TB38 review:

- all 409 identities executed exactly once with zero selection mismatch and zero timeout;
- accepted 1–365 are **365/365 PASS**;
- the exact TB37 RED set is restored: `[366,367,368,369,370,374,398]`;
- accepted ordinals 356/357/362 and protected 390/393/406/407 recover; 312/404/408/409 remain PASS;
- ownership remains **300 established / 0 unavailable / 0 conflicting**;
- retired codes remain absent;
- package/source/execution views are byte/mode stable and no build/benchmark occurred.

**Decision:** `M3-CP4c-3-TB39` becomes the current valid semantic runtime authority. TB37 is superseded as runtime
authority, not invalidated historically. Package104 remains current package authority. Stable accounting remains
**46 events / 14 categories / 32 recurrences**, produced-witness debt **5**, packages **104**.

## DB1 — TB38's stable event remains historical even though the gate recovered

TB38's accepted-green loss at 356/357/362 was a real observed regression caused by the frozen DEFN-R6.4 choice.
CB44 deliberately restored the previous criterion; TB39 proves that restoration recovers the accepted and protected
greens. Recovery does not erase the event that occurred.

**Disposition:** `M3-CP4c3-TB38-EXEC-CAND-01` is **RESOLVED AT CURRENT RUNTIME / STABLE EVENT RETAINED**. The one
stable `RP-01 / AUTHORITY_DOMAIN_CONFLATION` event remains in the 46/14/32 totals. No new event or recurrence is
created by recovery.

## DB2 — the R6.7 evidence gap is closed non-vacuously

TB39 emits **513** `euler_certificate` rows over **64 ordinals**, including accepted identities. Every row carries
the required fields and satisfies all five frozen arithmetic relations:

1. `chiReduced = V_int - E_int + F`;
2. `chiFull = V_total - E_total + F`;
3. `fullMinusReduced = chiFull - chiReduced`;
4. `fullMinusReduced = X - E_one - B_int`;
5. `B_int = B_int_both_sides`.

**Disposition:** `M3-CP4c3-TB38-EXEC-CAND-02` is **CLOSED / RUNTIME-PROVED / NON-STABLE**. R6.7's arithmetic
instrumentation now has a non-empty witness domain. What it proves is arithmetic coherence of the published proxy
counts; it does **not** prove that either proxy is the semantic region complex.

## DB3 — both decisive fixtures falsify proxy selection, not the region

TB39 preserves the sign-changing discrepancy established by TB38 and makes it non-vacuous on the same runtime:

| fixture | reduced | full | `fullMinusReduced` | additional publication |
|---|---:|---:|---:|---|
| torus | 1 | 0 | **-1** | `trace_cut_faces=0`, `split_fragments==F`, corners 0 |
| mechanical | -3 | 1 | **+4** | `trace_cut_faces=36`, `split_fragments=288`, corners 86 |

The opposite signs still prove that neither the reduced source-support proxy nor the whole-face source-submesh proxy
can be a universal region-disc criterion.

The new “third-complex” fields do not supply a third authoritative cell complex either:

- `splitFragmentCount` starts from `region.sourceFaces.size()` and adds a **source-face-wide trace-piece count** for
  every support face. On a trace-cut source face shared by multiple face-walk orbits, this is not a per-region cell
  decomposition.
- `fragmentCornerAttributionCount` counts source vertices attributed through `fragmentCorners`; it cannot count
  embedded nodes created at trace/cut intersections in edge or face interiors.
- `B_int_one_side` / `B_int_both_sides` classify **source edges**, not arcs of the actual embedded graph.

These measurements are useful falsifiers and projection diagnostics, but they do not define the topology object.
`DEFN-R6.3` and `DEFN-R6.4` therefore have no remaining authority as a region-disc definition. The next definition
must not choose a formula by fitting either fixture.

## DB4 — the normative topology object already exists upstream

The architecture and current source independently agree on one object that already has the required semantics.

`DESIGN.md` §7.2 is explicit:

1. A2a′ `SurfaceCutGraph` makes the immutable network plus cuts a **certified cellular embedding**;
2. A2b extracts the **faces of that certified cellular embedding**;
3. those faces are emitted as topology regions;
4. Amendment 13 says the normative complex is the **actual embedded graph** of
   `FieldAlignedCurveNetwork ∪ cutEdges`, whose faces are dart orbits; the whole-source-face/source-edge-barrier
   partition is withdrawn as cellularity authority.

Current source matches that contract:

- `SurfaceCutGraphCellularityCertificate::complex` is `ActualEmbeddedGraph` and
  `proves_embedded_cellularity()` requires the actual-embedded Euler/source identity and every
  `SurfaceCutGraphFaceCertificate::proves_disc_topology()`;
- each non-exterior face-walk orbit receives a face certificate carrying that orbit, one boundary walk, a non-empty
  boundary arc count, and `discTopologyEstablished`;
- `GlobalTopologyPlan::canonical_candidate` rejects a cut graph that does not
  `proves_embedded_cellularity()` before region derivation;
- `build_regions()` creates each region draft directly from a non-exterior `walk.orbits[orbit]`;
- `region_orbit()` recovers provenance by exact equality between `region.boundary` and a face-walk orbit;
- candidate validation additionally requires `cutGraph.certificate().proves_cellularity()` and reconstructs the
  canonical candidate, so a copied/mutated region cannot retain a stale trusted flag.

**Finding:** the topology region is already the face-walk orbit of the certified actual embedded graph. A2a′
already owns the disc-topology proof for that face. `GlobalTopologyPlan`'s separate Euler certificate is a second
checker over `region.sourceFaces`, which is support/projection data. It re-derives topology over a different object
and can therefore contradict the upstream certificate without showing that the actual region is non-disc.

This is the same architectural class as PR8-R043: a source-support proxy was allowed to stand in for the actual
embedded graph after Amendment 13 had already withdrawn that authority. `M3-CP4c3-TB37-REV-CAND-01` is therefore
**ADJUDICATED / GATING ROOT CAUSE ESTABLISHED / RP-01**. The corrective authority is a definition rebinding, not a
third source-projection formula.

## DB5 — 366/367 remain RED, but the current Euler rejection is not a normative disc proof

Ordinals 366/367 still stop at `RegionEulerCharacteristicNotOne / RegionCertification` because CB44 restored the
reduced `certificate.eulerCharacteristic` as the accepted-baseline stop condition. TB39 proves the mechanical proxy
values remain reduced `-3`, full `+1`.

That RED is preserved as current runtime evidence; this review does **not** waive it. But the architecture/source
finding above means the reduced or full source-support proxy cannot be used as the final semantic authority for
whether the actual face-walk region is a disc. DEFN-R7 must rebind the region certificate to the upstream
actual-embedded-face proof while preserving independent tamper rejection.

## DB6 — `regionChiFull` is a real diagnostic-contract defect, non-stable

TB39's 366/367 error payload publishes `regionChiFull=-3`; the same run's complete certificate row proves
`chiFull=136-385+250=+1`. Static source is exact: after CB44 restored
`certificate.eulerCharacteristic` to the reduced value, the failure still assigns

`failure.regionFullEulerCharacteristic = certificate.eulerCharacteristic`.

**Disposition:** `M3-CP4c3-TB39-EXEC-CAND-01` is **OWNED / NON-STABLE / DIAGNOSTIC CONTRACT / RP-01**. It caused
no gate-colour loss, so stable totals do not change. DEFN-R7 must freeze the field contract; the later Code + Build
may either bind the full-labelled field to the full count or replace the field with explicitly domain-named
publication. This review makes no source patch.

## DB7 — separately owned RED surfaces are unchanged

No TB39 evidence reclassifies 368/369/370/374/398. Their established owners and prohibitions remain in force.
In particular, no sphere semantic correction, empty-network correction, atlas-witness correction, or unrelated
frontier work is authorized by this review.

## DB8 — exact successor: `M3-CP4c-3-DEFN-R7`

The evidence is sufficient for a definition turn, but not for implementation in this turn.

**Exact successor:** `M3-CP4c-3-DEFN-R7` — static Definition / Review + Plan, **NO RUNTIME / NO COMPILE**. Its
binding plan is `Architecture_M3_CP4c3_DEFN_R7_Definition_Plan.md`.

DEFN-R7 must freeze one authority, not another proxy heuristic:

1. region topology authority is the matching non-exterior **actual-embedded face-walk orbit** and its
   `SurfaceCutGraphFaceCertificate`;
2. `region.sourceFaces`, reduced/full source-submesh counts, split-fragment counts and source-edge barrier counts are
   support/projection diagnostics unless a future definition constructs an exact actual-embedded cell complex;
3. the region-to-face-certificate binding is derived from current authoritative structure (orbit/boundary equality
   plus the cut-graph certificate), not a mutable/sticky “trusted” flag;
4. synthetic/copy-mutated negatives 312/409 must remain capable of losing provenance and rejecting;
5. `GlobalTopologyRegionDiscCertificate` must have one semantic object: preferably a thin binding to the upstream
   face certificate plus separately owned field-regularity evidence, or exact counts of that same actual object;
6. every consumer, semantic digest, failure payload and diagnostic field affected by the rebinding must be named;
7. the full-labelled failure field must no longer publish the reduced value;
8. no 368/369/370/374/398 owner, region construction, owner partition, selector byte, or accepted/protected oracle
   is weakened.

The definition turn may freeze a bounded runtime-free successor Code + Build, but it must not implement it in the
same turn.

## Accounting and closeout state

- Current semantic runtime authority: **TB39**, package104, selector409 **402/7**, accepted **365/365**.
- Stable accounting: **46 events / 14 categories / 32 recurrences**.
- Produced-witness debt: **5**.
- Packages: **104**.
- New stable events this review: **0**.
- Exact next: **`M3-CP4c-3-DEFN-R7`**.
