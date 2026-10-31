# RA-164 — TB45-REV audit; 174 and cp3entry:4 decided statically; RED clusters; CP3 cadence realigned (2026-10-27)

**Turn:** `M6-CP3-TB45-RP01-SELECTOR242-SEAM-REHOME-VERIFY-REV-AUDIT`. **Decision:**
- TB45-REV is **CONFIRMED** on its evidence and semantics.
- Its successor, `M6-CP3-DEFN-RP01-SELECTOR174-DCEL-EXCEPTION-DISPOSITION`, is **SUPERSEDED**: this audit decides 174 statically (RA-164.2).
- The one-RED-per-DEFN ladder is replaced by RA-164.3–.6.

This audit made no build, runtime, test or product change.

## RA-164.1 Verification

- Re-downloaded TB45 result `12702259228`. ZIP SHA-256 `7d18b08a…bcd6080` matches, `SHA256SUMS` passes **9/9** (TB45-REV said 8/8, but the archive has 9 members, all valid), and the ledger-to-log joins are 3/3 with one RUN and one OK each.
- HEAD `tests/SurfaceCellsPhase10Tests.cpp` SHA-256 `f1183015…9c06619` equals the CB45 source `dfeb0751b`. There is no `src`, `include`, `tests` or CMake drift since then.
- **There has been no production change since TB38.** `038ae7fd7..HEAD` touches only `tests/SurfaceCellsPhase10Tests.cpp`, so every TB38 first-failure site is still current for every other test.
- **A1.** The CB45 body implements RA-163.3 exactly.
  - The A3 pin `changedReverse == changedForward.inverse()` is structural (`FieldTransportAtlas.cpp:2033–2036`): it pins the architecture rather than discriminating a defect.
  - `EXPECT_NE(original, changed)` is what carries the non-vacuity. Accepted.
- **A2.** TB45-REV left 174's owner open ("fixture or production"). The source already settles it (RA-164.2 H1), so a DEFN turn would only re-derive this.

## RA-164.2 Static triage of the 7 remaining TB38 REDs

- **H1 `selector:174` — decided: invalid fixture, unreachable branch.**
  - The third face `0,1,4` (`SurfaceCellREPackageTests.cpp:445–446`) repeats directed edge 0→1 of face `0,1,2`.
  - `TriMesh::set_mesh` (`TriMesh.h:339`) calls `compute_edge_quantities`, which throws at `:158–162`, before the rail builder runs. TriMesh owns manifoldness.
  - Consequently, the rail builder's `claimedFaces.size() > 2U` (`RemeshPipeline.cpp:9639`, added by `18357617a`, 2026-10-14) is unreachable through any `TriMesh`. Keep it as defence in depth.
  - The test lines after `:459` have **not executed since 2026-10-14**, so TB46 must pre-register a possible later first failure.
- **H2 `cp3entry:4` — decided: the oracle names the wrong owner.**
  - TB38 site `code=0;sourceAuthoritySite=open-rail-chain` is the A4 checked factory rejecting a draft whose `hardFeatureEdges` were cleared while its open chains remain (`SurfaceCellTracing.cpp:8703–8708`, chain ⊆ hard).
  - This is a torn input, the RA-162 F1 class. A4 owns that consistency and rejects it correctly, so the test's A5 `InvalidHardRailAuthority` expectation (`TransitionQuotientTests:3985–3994`) is unreachable through the checked factory.
- **Cluster E — `selector:201`, `cp3entry:2`. One fixture family, one open question.**
  - Both use the 3×3 grid with the hard midline 1–4–7. 201 asserts that every endpoint has a `terminalVertex` (`REPackageTests:713`); cp3entry:2 requires one two-carrier route (1,4)→(4,7) with a junction (`TQTests:3139`).
  - Since `ccc0b00ab` (2026-10-19), A4 endpoints can be T, R (`railVertex`) or I (interior carrier point) (`SurfaceCellTracing.cpp:19715–19758`, kinds at `:8944`).
  - 201's assertion (`d581fa974`, 2026-10-13) predates that change, and 201 is first RED at TB28.
  - **Hypothesis E:** A4 now publishes the midline as spans ending at R/I endpoints, not as one junctioned route.
  - What is undecided is which representation is canonical: either the tests re-home, or the producer is fixed. TB46 harvests the decisive evidence through message-only diagnostics D1/D2.
- **Cluster G — `selector:442` (A3 `SingularityMismatch` on a relabelled field with a component seam), `focused30:12` (A5 `OccurrenceHardRailTransportMismatch` on a relabelled front), `cp3entry:1` (A4 unequal face-gauge selection).**
  - All three test face-gauge relabel invariance across A3/A4/A5. RA-163 R2 is the governing principle: a gauge relabel must be accepted.
  - DEFN-G follows E. D3 adds the gauge values to cp3entry:1.

## RA-164.3 Cadence realignment (binding authority: `Turn_Cadence.md`, unchanged)

- The cadence is CB → **full-gate** TB. A green TB closes the checkpoint; a red TB → REVIEW+PLAN, which a DEFN absorbs.
- CP3 drifted into adding CB-REV, focused TBs, green-TB-REV, DEFN-REV and REV-AUDIT turns. From 10-19 to 10-26 that came to 161 turns, 93 of them Review, and 13 ended with BLOCKED or `UNKNOWN`.
- Focused TBs cannot close anything (rule 2), which is why the TB41–TB45 candidates were never reconciled.

**Bounded procedure (applies from CB46):**
- **P1.** Every CB spec carries a hunk allowlist, the next TB's manifest and a CB outcome table. A CB that matches its table goes **directly** to its TB; there is no CB-REV.
- **P2.** Every TB runs the full gate (the current 504-row manifest, with pre-registered first-failure predicates for its RED rows). A focused run is allowed only as a declared non-gating diagnostic row inside a full-gate TB.
- **P3.** Every TB has an outcome table that maps each observable to a named successor. The successor of a red TB is the Review-owned DEFN that absorbs REVIEW+PLAN. There is no separate DEFN-REV.
- **P4. STOP codes** (each successor is fixed):

  | Code | Condition | Successor |
  |---|---|---|
  | S1 | Symbol not visible from the TU | `<CB>-REV` |
  | S2 | Change outside the allowlist (helper or production) | `<CB>-REV` |
  | S3 | Selector or manifest bytes would change | `<CB>-REV` |
  | S4 | A GUARD row turns RED, or a RED row first-fails at a predicate that was not pre-registered | `<TB>-REV` |
  | S5 | Orchestration or infra failure | Cadence rule 5: `<TB>A-ORCH` CB, then re-run the same TB |
  | C2 | Compile error inside an allowlisted hunk | Fix in the same hunk, at most 2 compile attempts; otherwise S2 |

- **P5.** A COMPLETE or BLOCKED beacon must name a successor from its table. `UNKNOWN` is allowed only while the turn is `IN_PROGRESS`.
- **P6.** REV-AUDIT is used only when two durable records conflict on evidence.

## RA-164.4 CB46 — `M6-CP3-CB46-RP01-RAIL-ORACLE-REHOME-AND-ENDPOINT-DIAGNOSTICS`

Test-only, compile only. **The allowlist is exactly these hunks:**
- **H1** — `REPackageTests:445–459`, inside the 174 body.
  - Build `nonmanifoldFaces` (3×3: `0,1,2, 1,0,3, 0,1,4`) and `EXPECT_THROW(threeFaceSource.set_mesh(incidenceVertices, nonmanifoldFaces), std::runtime_error)`.
  - Then `overfullHard.edges[0].incidentFaces = {0,1,2}` is built on **`manifoldHardSource`**. Keep the four existing rejection expectations: `is_rejected`, null product, `InvalidFeatureEdge`, `failedEdgeIndex 0`.
  - `#include <stdexcept>` is allowed.
- **H2** — `TQTests:3971–3994`, inside the cp3entry:4 body.
  - Control: `construct_phase_front_product(phase_front_draft(rail))` holds a product.
  - With `hardFeatureEdges.clear()`, the result holds a `SurfacePhaseFrontProductError` with `code == InvalidSourceAuthority` and `sourceAuthoritySite == std::string("open-rail-chain")`.
  - Delete the A5 produce on the cleared draft and its `InvalidHardRailAuthority` expectation. Keep the rest of the body.
- **D1** — `REPackageTests:713`. Message only. Stream:
  - the endpoint kind (`R` if `railVertex`, else `I`);
  - `certificates.size()`;
  - the route `oriented_steps().size()` and `junctions.size()`;
  - the carrier vertex pair.
- **D2** — `TQTests:3136–3141`. Message only. Before the assert, build an `ostringstream` listing each produced certificate: its step carrier pairs (via `carrier_vertices`), its endpoint kinds `T/R/I`, and `j=<junctions>`. Append it to the assert message.
- **D3** — `TQTests:2916–2918`. Message only: add `fromGauge` and `toGauge`.

No predicate may change in D1–D3. Do not change helpers, production code, selectors, the harness or workflows.

**Evidence:** the 8 GMP/GMPXX targets, `runtimeExecution=false`, and a record of at most 30 lines that includes the hunk list.

**Outcome:**
- Compile passes and the diff stays inside the allowlist → `M6-CP3-TB46-RP01-FULL-GATE`.
- Otherwise → the matching P4 code.

## RA-164.5 TB46 — `M6-CP3-TB46-RP01-FULL-GATE`

- Artifact-only, on the CB46 package.
- Harness: `tools/m6_cp3_targeted_artifact_harness.sh`, unchanged (SHA-256 `436f5fff…3c9a`).
- Manifest: `Architecture_M6_CP3_TB46_Full_Gate_Case_Manifest.tsv` (SHA-256 `717f4f0f…6bb087`). It has 504 rows and keeps TB38's identities and order. All 504 test names resolve at HEAD.
  - 191, 192, 204, 247, 250, 405 and 242 become GUARD.
  - 174 and cp3entry:4 become POSITIVE.
  - Five rows stay RED with pinned predicates.
- **Prediction: 499 PASS / 5 RED.** Raw logs must keep the D1–D3 messages.

| Observed | Successor |
|---|---|
| 499/5, with every RED at its pinned predicate | `M6-CP3-DEFN-RP01-TB46-ENDPOINT-CLUSTER` (Review-owned) |
| 174 or cp3entry:4 RED at a later predicate (latent lines), everything else as predicted | Same DEFN; it also disposes that row |
| A RED row passes unexpectedly | Same DEFN; record it |
| A GUARD row turns RED, or a RED row first-fails at an unregistered predicate | S4 → `M6-CP3-TB46-RP01-FULL-GATE-REV` |
| Missing, duplicate or invalid rows, or a harness failure | S5 |

## RA-164.6 Turn sequence (frozen IDs)

1. CB46 → TB46.
2. `M6-CP3-DEFN-RP01-TB46-ENDPOINT-CLUSTER` (Review-owned; absorbs the TB46 REVIEW+PLAN; decides E) → CB47 → `M6-CP3-TB47-RP01-FULL-GATE`.
3. `M6-CP3-DEFN-RP01-TB47-GAUGE-CLUSTER` (Review-owned; G: 442, `focused30:12`, cp3entry:1) → CB48, which may split by owner, with each CB → `M6-CP3-TB48-RP01-FULL-GATE`.
4. `M6-CP3-DEFN-RP01-O4-O5-RAIL-PROVENANCE` (Review-owned; O4, O5, P1-a, P1-b, RA-162 C1, and the A5 `InvalidHardRailAuthority` reachability left over from H2) → CB49 → TB49, a full gate plus the non-gating P1 rows.
5. A green full gate → RP-01 Review (O6 scope).
6. After RP-01: the O2 DEFN, then DIAG-RETAIN.

Each CB → TB is direct (P1). Each red TB → the next Review-owned DEFN (P3). That is about 12 turns, 4 of them Review.

**Carried:** O1, O2/T2, O6, DIAG-RETAIN, RA-152.5, DEFN-SEAM-NZ (+RA-163.4), RA-146.2/4, RA-45.4, G4-B002.

**Accounting unchanged:**
- Stable 66/17/49, debt 1. CP2 491/491 accepted.
- TB38 490/504 candidate. Focused TB41–TB45 are candidates until TB46 reconciles them.
- Selector497 frozen. RP-01 open.
