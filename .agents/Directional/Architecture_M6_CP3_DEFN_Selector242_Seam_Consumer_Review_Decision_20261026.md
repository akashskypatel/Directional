# RA-163 — selector242 DEFN Review: D1 missed the typed owner, D2 decided statically, Branch B rejected (2026-10-26)

**Turn:** `M6-CP3-DEFN-RP01-SELECTOR242-CROSS-REGION-SEAM-CONSUMER-REV`. **Reviewed:** [DEFN decision](Architecture_M6_CP3_DEFN_Selector242_Cross_Region_Seam_Consumer_Decision_20261026.md) and the [conditional CB45 draft](Architecture_M6_CP3_CB45_Selector242_Seam_Rehome_Specification_20261026.md) on source `9ab1563ee` (no `src`, `include` or `tests` drift since).

**Decision:** the DEFN is **PARTIALLY ACCEPTED**.
- Accepted: D2's vacuity diagnosis and D4.
- **Corrected:** D1.
- **Decided here:** D2's branch, which the DEFN left open.
- **Rejected:** D3 Branch B.
- **Superseded:** the CB45 draft, replaced by RA-163.3, which is the only CB45 authority.

This Review made no code, build or runtime change.

## RA-163.1 Findings on the DEFN

- **R1 — D1 missed the typed owner of non-reciprocity.**
  - `SurfaceIsolationSeamTransportCertificate::make` (`SurfaceCellTracing.cpp:8090–8150`) rejects `compose(forward, reverse) != identity` with `NonReciprocalTransport` (code 7, `:8146–8150`).
  - Its error carries `region`, `seam`, faces and sheets. It is the only place where a non-reciprocal pair can be expressed.
  - A4's builder derives the pair from A3 and pre-checks `candidateReverse != candidateForward.inverse()` (`:18184`). So no atlas-derived input reaches code 7, and the type makes a non-reciprocal certificate unconstructible downstream.
  - Accepted-prefix **`selector:185`** (`SurfaceCellIsolationSeamCertificateAuthority.NonreciprocalIsolationSeamCertificateIsRejected`, `TransitionQuotientTests:7686–7708`) already pins code 7 on `split_isolation_fixture`.
  - The DEFN cited neither the predicate nor the selector.
- **R2 — D2 is decidable statically: mutated A3 ACCEPTS.**
  - The atlas cycle basis is `dual_cycles` (`PCFaceTangentBundle.h:95`).
  - For the 242 disk (4 vertices, all on the boundary; one inner edge, (0,2)), there are 0 interior-vertex rows and 1 boundary row. The boundary row is the sum of the vertex cycles of v0..v3 (`MeshTopology.cpp:130–133, 281–288`).
  - Edge (0,2) gets −1 from v0 and +1 from v2. The sum is 0, and the entry is pruned (`:329–330`).
  - So no cycle observes the edge. `CycleTransportMismatch` cannot fire, and A3 never compares `matching` against the face geometry (`FieldTransportAtlas.cpp:1963–2045` and `2479–2589` read only `effort` and cycles).
  - More fundamentally: when a region's dual graph is a tree, a matching change on one edge is a **gauge relabelling**, not an inconsistency. Acceptance is correct, and a rejection would be a defect.
  - **Branch A is dead.**
- **R3 — the original expectation is unreachable on every path.** `InvalidTopologyRegionTransport` is now emitted only for atlas/source-face mismatch and network-binding failures (`SurfaceCellTracing.cpp:19360–19376`, `12058–12706`).
  - Atlas-bound: the mutation is never read (`:21181–21184`).
  - No atlas: the result is the factory's `atlas-binding` rejection (RA-160).
  - Certificate failures map to `InvalidIsolationSeamTransportCertificate` (`:19215–19230`), not to the old reason.
- **R4 — Branch B is rejected.**
  - It swaps the invariant: cycle-holonomy consistency (`CycleTransportMismatch`, already owned by A3 and its own tests) is not reciprocity.
  - Its fixture must come from production finalization, and the DEFN itself concedes that yields consistent fields. It would spend a CB on a speculative, probably unreachable witness.
  - Its "Review chooses A or B" CB45 draft is not an executable spec.

## RA-163.2 Selector-meaning disposition (Review-owned)

`selector:242` keeps its identity: `SurfaceCellsPhase10.NonReciprocalSourceAdjacentIsolationSeamFailsClosed`. Its meaning is re-homed from "A4 rejects a legacy non-reciprocal matching" to:

> On the source-adjacent two-sheet seam, A3 cannot represent non-reciprocal transport even under the legacy single-edge mutation. A non-reciprocal pair presented to the seam certificate's owner fails closed with code 7, at that exact seam.

**Overlap with 185:** 242 binds the owner check to the certificate that A4 actually published on the source-adjacent geometry of `selector:239`. It also adds the A3 representation pin. 185 covers neither. The old A4 `Rejected`/`InvalidTopologyRegionTransport` assertions are retired as unreachable (R3).

## RA-163.3 CB45 specification — `M6-CP3-CB45-RP01-SELECTOR242-SEAM-REHOME`

Test-only, compile only. **Edit only** the 242 body, `tests/SurfaceCellsPhase10Tests.cpp:3340–3391`. Keep its name, mesh, `raw`, `sourceField` and options.

The new body has these sections:

1. **Produce.**
   - `network = build_phase10_with_source_atlas(mesh, sourceField, targetSize, options)`.
   - `ASSERT` the result is `Produced`, with exactly one isolation certificate `c`.
2. **Owner, reverse.**
   - Call `SurfaceIsolationSeamTransportCertificate::make(product.sourceTopologyRegions(), c.region(), c.seam(), c.transition(), c.firstFace(), c.secondFace(), c.firstSheet(), c.secondSheet(), c.forward(), QuarterTurn::from_integer(int(c.reverse().value()) + 1))`.
   - `ASSERT` the result holds an error. Expect code `NonReciprocalTransport`, `error->seam == c.seam()` and `error->region == c.region()`.
3. **Owner, forward.** Same as section 2, but with `forward + 1` and the original reverse. Expect code `NonReciprocalTransport`.
4. **Owner, control.** Call `make` with `c.forward(), c.reverse()`. It must hold a certificate whose `isolation_seam_transport_certificate_hash` equals that of `c`.
5. **A3 representation.**
   - Set `mutatedField = sourceField` and apply the existing interior `matching += 1`.
   - Build `mutatedAtlas = FieldTransportAtlas::make(mesh, *sourceAuthority, options.hardFeatureEdges, mutatedField)` and `ASSERT_TRUE(mutatedAtlas.has_value())` (R2).
   - Let `f/r = transition_value(c.seam(), A, B)` and `(…, B, A)` on both atlases, where A and B are the seam's two `SourceFaceId`s.
   - Expect `r->transport == f->transport.inverse()` on the mutated atlas.
   - Expect the mutated `f->transport` to differ from the source atlas's `f->transport`. This proves the mutation was consumed.
6. **Remove** the old A4 run on `crossField` and its `Rejected` / `InvalidTopologyRegionTransport` / null-product expectations.

**Rules for the change:**
- **Must not change:** any other test or helper, production source, selectors, harness or workflows.
- Do not bind A4 to `mutatedAtlas`. A non-zero seam transport belongs to DEFN-SEAM-NZ.
- **Evidence:** 8 GMP/GMPXX targets, `runtimeExecution=false`, record of at most 30 lines with the exact hunk.

**STOP → Review if:**
- a needed symbol is not visible from the TU (`SourceFaceId` construction, the certificate error type, `transition_value`);
- a helper change is needed;
- selector bytes would change.

If the A3 build rejects at runtime, that is a **TB45 finding against R2**, not something to fix in CB45.

## RA-163.4 Carried and noted

- **DEFN-SEAM-NZ (hint only, unverified):** cyclically shifting one face's four `raw` vectors in this fixture should make production finalization produce a non-zero principal matching at the seam. If so, that is a production-derived non-zero seam transport. Record it for the SEAM-NZ owner. Do not act on it in 242.
- O2/T2 (post-RP-01), O5 (P1-a re-scoped, P1-b, RA-162 C1), O4, O6, DIAG-RETAIN, RA-152.5, RA-146.2/4, RA-45.4 and G4-B002 are carried unchanged.

## RA-163.5 Turn sequence (frozen IDs)

1. `M6-CP3-CB45-RP01-SELECTOR242-SEAM-REHOME` → `…-REV`. The REV is static and issues the TB45 manifest:
   - 242 POSITIVE;
   - GUARD `selector:239` (`Phase10Tests:3270`);
   - GUARD `selector:185` (`TransitionQuotientTests:7686`).
2. `M6-CP3-TB45-RP01-SELECTOR242-SEAM-REHOME-VERIFY` → `…-REV`.
3. 174 → 201 → `focused30:12` → `cp3entry:4` → `selector:442` → DEFN-T1 (`cp3entry:1/2`). One owner per turn; Review assigns the IDs.
4. O4 DEFN, then O5 DEFN (+P1, C1) → REV for each. Then census → RP-01 Review (O6 scope). After RP-01: O2 DEFN.

**Accounting unchanged:**
- Stable 66/17/49, debt 1.
- CP2 491/491 accepted.
- Candidate: TB32 481/500, TB38 490/504.
- Focused candidate: TB41–TB44.
- Selector497 frozen. RP-01 open.
- 242 stays RED until TB45 and then a complete gate.
