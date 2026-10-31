# RA-143 — DEFN-M1 architecture block resolved: A4 authenticates hard-rail certificates; A5 binds edges to them (2026-10-23)

**Turn:** `M6-CP3-DEFN-M1-RP01-CERTIFICATE-PAIR-BINDING-PRECEDENCE-REV`. **Input:** DEFN-M1 `BLOCKED` (`Architecture_M6_CP3_DEFN_M1_Certificate_Pair_Binding_Precedence_20261023.md`).

**Verdict:** the DEFN's clause audit, ten-row matrix, non-weakening table and predictions are **accepted**. It stopped on one open question: can A4 publish a product whose hard-rail edges are not yet bound to their certificates? Review resolves it:
- **Yes**, for exactly five association predicates, because the frozen contracts make A5 their owner and A5 already enforces each one before any consumer uses those edges.
- A4 keeps every **authenticity** check.
- This is option (c), with an evidence-based owner split. It is not a weakening.

## RA-143.1 Why A5 is the owner (frozen authority)

- **RA-15 (normative)** pins the order inside A5 (RA-16 §5):
  - first, individual hard-rail route authority, with failures surfacing as `InvalidHardRailAuthority`;
  - then pair owner, region and reversed-route checks, with failures as `InvalidHardRailTransport` (it names `selector:139/142`);
  - no divergent duplicate route semantics elsewhere (RA-15.4).
- **RA-40.1** requires A4 to **authenticate certificate values** against the bound atlas. It says nothing about A4 binding edges to certificates.
- **R2's pair-binding clause** (`80fc1688f`, 2026-10-08, from the CP3-entry R2 work that was later rejected at 444/497) added that association to A4. RA-105.3 already recorded that it preempts the frozen precedence. No frozen definition makes A4 the owner of association.
- **A5 already enforces association** (RP:5040–5051). It looks up a certificate with `firstFrontEdge == edge`, `secondFrontEdge == edge.oppositeEdge`, `rail == railId` and `route == edge.route`, and otherwise fails `HardRailRouteAuthorityInvalid`. It runs **after** the RA-15 checks, as the frozen order requires: route authority (RP:4904–4909) → owner (RP:4917) → region (RP:4921) → reversed route (RP:4924–4925) → certificate lookup (RP:5050). RP:5040 states it explicitly: *"A4, not A5, owns route traversal, endpoint attachment and A3 tau."*
- **The only consumers** of `hardRailRouteCertificates()` are A5's lookup (RP:5042–5049) and a hash (RP:2110–2114). No consumer relies on A4-side association.

## RA-143.2 The split (binding)

| Predicate in SCT:8831–8841 | Owner after CB29 | First rejection for the M1 tamper |
|---|---|---|
| index range (`certificate-pair-indices`, SCT:8820–8827) | **A4 (kept)** | unchanged |
| both referenced edges are `HardRail` | **A4 (kept)**, site `certificate-pair-binding` | unchanged |
| `first.oppositeEdge == secondFrontEdge`, `second.oppositeEdge == firstFrontEdge` | **A4 structural reciprocity** `InvalidOppositeEdge` (SCT:≈9331–9353), plus the A5 lookup | `selector:211/219` → `InvalidOppositeEdge` |
| `first/second.railId == certificate.rail` | **A5** owner mismatch → `InvalidHardRailTransport`, plus the lookup | `selector:140` |
| `first.route == route`, `second.route == route.reversed()` | **A5** RA-15 route authority, then reversed-route check, plus the lookup | `focused30:3, 22, 23`, `selector:227, 230` → `InvalidHardRailAuthority`; `selector:139, 142` → `InvalidHardRailTransport` |
| `first.sourceTopologyRegion != second.sourceTopologyRegion` | **A5** `HardRailRegionMismatch` → `InvalidHardRailTransport` | none of the ten; kept rejecting downstream |
| certificate attachments, route length, junctions, open/closed interval, endpoints, A3 tau (SCT:8842–8960+) | **A4 (kept)**; these read the certificate's own data (the attachments compare against the edges' `from`/`to` faces, which no M1 tamper changes) | unchanged |

**Product contract after CB29:** a published `SurfacePhaseFrontProduct` guarantees structurally valid edges, including reciprocal `oppositeEdge`, and **authentic** certificates. Whether hard-rail edges match those certificates is an A5 admission predicate, checked before A6 or A7 can consume them. No new type state is needed, because A5 is the binding gate.

**Non-weakening:** every input that R2 rejected is still rejected end to end:
- a forged certificate value: A4 authenticity;
- a broken opposite structure: A4 `InvalidOppositeEdge`;
- a bad route: A5 route authority;
- a pair mismatch: A5 transport;
- any remaining edge-to-certificate mismatch: A5 `HardRailRouteAuthorityInvalid`.

The rejecting stage changes only for those five predicates, and only toward the frozen owner.

**No currently passing test depends on A4 association.** Every test asserting `InvalidSourceAuthority` was checked (SP10:7388–7531, TQ:1972–2244, 2872–2916, 3058–3081, 3084–3354). Each tampers certificate data, face gauges, tau or rail terminals, never edge-to-certificate fields.

## RA-143.3 Successor `M6-CP3-CB29-RP01-A4-CERTIFICATE-ASSOCIATION-OWNERSHIP` (Code + Build, compile only)

- **File:** `src/geometry/SurfaceCellTracing.cpp` only.
- **Change:** in the certificate loop's pair clause (SCT:8831–8841), remove the five association predicates (both `oppositeEdge`, both `railId`, both route comparisons, the region inequality). Keep the two `HardRail` kind checks with the same site.
- **Comment:** add one comment citing RA-15/RA-16 §5/RA-143 for the ownership.
- **No other change:** RP (A5 already enforces), tests, selectors and workflows are untouched. Lines at most 100 columns.
- **Build:** compile the eight targets with GMP/GMPXX, `runtimeExecution=false`. Record `Architecture_M6_CP3_CB29_A4_Certificate_Association_Ownership_Code_Build_Record_20261023.md` (at most 30 lines).
- **STOP** if a later A4 clause in the same loop reads one of the removed fields assuming it was bound, or if any edit is needed outside that clause.

## RA-143.4 TB30 plan (manifest issued at CB29-REV)

Targeted harness (`436f5fff…c9a`) with a Review-owned manifest:
- the **10 M1 rows**, expected to reach their frozen outcomes (PASS);
- the **7 non-M1 factory rows**, expected unchanged (still RED at `face-gauge-missing` / `open-rail-chain`);
- the **9 TB29 controls**;
- **3 certificate-authenticity guards:**
  - `SurfaceCellAuthorityContractCutover.ProducedOpenRailInteriorEndpointPreservesExactTerminalGuard`;
  - `…CheckedFactoryRejectsOpenRailWithClearedTerminalAnchor`;
  - `…ProducedOpenRailInteriorVertexEndpointRejectsForgedTags`.

**Falsifiers:**
- an M1 row still fails at A4, or with a non-frozen code;
- an authenticity guard turns RED;
- a control turns RED;
- a non-M1 factory row changes its typed reason.

A census follows with an RA-139.3-compliant harness (RA-139.5).

## RA-143.5 Sequence and accounting

- **Sequence:** DEFN-M1 (blocked) → DEFN-M1-REV (this; the contract accepted with resolution) → **CB29** → CB29-REV (static diff, issues the TB30 manifest) → TB30 → TB30-REV → owners for face-gauge-missing (6), A3 cycle locus (7) / `selector:442`, A5 `focused30:12` (each DEFN or diagnostic first) → DEFN-T1 (`cp3entry:1/2`) → fixture debt → census (RA-139.5) → RP-01 Review. `DEFN-SEAM-NZ` and the Periodic follow-up each wait for a witness. `DIAG-RETAIN` is scheduled clear of RP-01 turns.
- **Accounting (unchanged):** stable 66/17/49, debt 1, CP2 491/491; R3 403/497 rejected; TB28 462/497 candidate; selector 497 frozen. `RP-01` open, `RP-02` UNREACHED, Gate C suspended.

| Duty | Answer |
|---|---|
| Decisive claims re-derived | R2 clause (SCT:8820–8841) and the post-clause checks; A5 lookup and comment (RP:5040–5051); consumer search; RA-15, RA-16 §5, RA-40.1, RA-105.3; origin of `80fc1688f`; the focused30:3 tamper; all `InvalidSourceAuthority` test expectations |
| Non-vacuity | Per-predicate owner mapping with frozen codes; authenticity guards and controls named for TB30 |
| Obligations | DEFN-M1 accepted; its STOP resolved; RA-142.4 discharged |
| Durable docs | Handoff, TODO, tracker, CHANGELOG, ORIENTATION, Frozen Definitions index |
| Boundary | Review-only; no source, test, selector, workflow or runtime change |
