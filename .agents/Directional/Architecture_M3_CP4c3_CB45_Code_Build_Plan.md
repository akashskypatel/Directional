# M3-CP4c-3-CB45 — Code + Build Plan

## Purpose

Implement the `DEFN-R7` actual-embedded face-certificate binding frozen in Part XI of
`M3_CP4c_Frozen_Definitions.md`. This is a bounded **Code + Build** turn. It may edit production/test code as
specified, compile through the mandatory reusable GitHub workflow with GMP/GMPXX, and package the result. It must
execute **no Directional runtime**.

## Immutable authority entering CB45

- Current semantic runtime: `M3-CP4c-3-TB39`, package104 source
  `8756cfe983bf7e05209f560d59a522a6b5b0674a`.
- Selector409: **402 PASS / 7 RED**, accepted **365/365**, RED `[366,367,368,369,370,374,398]`.
- Ownership: **300 established / 0 unavailable / 0 conflicting**.
- Stable accounting: **46 events / 14 categories / 32 recurrences**, debt **5**, packages **104**.
- Normative definition: `M3_CP4c_Frozen_Definitions.md` Part XI (`DEFN-R7`).
- Selector409 and every predecessor selector are byte-frozen.

## Build boundary

CB45 is runtime-free. It may configure/compile/link/package only through `.github/workflows/agent-compile-reusable.yml`
and must satisfy `GMP_COMPILE_POLICY.md`. No generated Directional binary may be run for test discovery, `--help`,
`--version`, gtest listing, benchmark, smoke test, or any other purpose. Required package evidence records
`runtimeExecution=false`.

## EA0 — prove the exact upstream binding in code

In `src/geometry/GlobalTopologyPlan.cpp`, consume the current `SurfaceCutGraph` certificate by the orbit returned by
`region_orbit(region, currentFaceWalk)`.

For each canonical/current region require:

1. exact current region-boundary equality with exactly one face-walk orbit `o`;
2. exactly one `cutGraph.certificate().faces` entry with `orbit == o`;
3. the face certificate is non-exterior by publication membership;
4. `boundaryArcCount == region.boundary.size()` and `proves_disc_topology()`. **Per Part XI-A §A.2,
   `boundaryWalkCount == 1` is a structural assertion, not evidence** — `SurfaceCutGraph.cpp:883` writes it as the
   literal `1U` for every face, so the conjunct cannot fail. Retain it as an assertion; do not count it toward the
   binding proof;
5. current source/network/cut-graph semantic bindings already required by the checked seam remain intact.

A missing/duplicate/mismatched upstream face binding fails closed as `InvalidRegionCertificateBinding` (or the
pre-existing earlier typed boundary/orbit error when that is the actual first failure). Do not introduce a sticky
region trust flag.

## EA1 — reshape `GlobalTopologyRegionDiscCertificate`

In `include/directional/geometry/GlobalTopologyPlan.h`:

- make the semantic topology payload an exact consumed `SurfaceCutGraphFaceCertificate` value (preferred field name
  `actualEmbeddedFace`, or an equivalent exact representation);
- retain `region`, `interiorSingularityFree`, and `boundarySingularities`;
- make `proves_disc_topology()` delegate only to the consumed upstream face certificate;
- keep `proves_field_regularity()` independent;
- remove the current proxy topology fields from the semantic disc certificate:
  `sourceFacesConnected`, `eulerCharacteristic`, `vertexCount`, `edgeCount`, `totalVertexCount`, `totalEdgeCount`,
  `faceCount`.

If exact support measurements remain useful, compute/publish them only as explicitly named diagnostics rather than a
second semantic certificate.

## EA2 — retire the second topology checker

Inside region certification:

- stop raising `RegionEulerCharacteristicNotOne` from reduced/full source-support arithmetic;
- stop raising `RegionInteriorDisconnected` as a disc-topology verdict;
- remove `validate_no_region_fragment_pinch()` from disc-topology authority; if retained, make it non-gating
  diagnostic evidence only;
- retain `validate_single_boundary_walk()` only for current candidate/binding structural validation and the 312/409
  synthetic falsifiers;
- retain `RegionContainsInteriorSingularity` and field-regularity proof separately.

The enum/string spellings for retired codes may remain for compatibility/history, but there must be no canonical R7
producer path using them as the region-disc theorem.

## EA3 — preserve the checked candidate seam and semantic digest

`canonical_candidate()` and `validate_candidate_structure()` must both derive the new region certificate from the
current region, current face walk and current `SurfaceCutGraph`. `make_from_candidate()` must reject any copied
candidate whose boundary or consumed face certificate was tampered.

Update `candidate_semantic_digest()` to consume exactly the new semantic certificate fields: region ID, the exact
consumed `SurfaceCutGraphFaceCertificate` fields, and field-regularity semantics. Retired support-projection counts
must not continue as topology-semantic hash terms merely because they were formerly certificate members.

Document the digest decision in the CB45 report; do not pin a new literal hash in tests unless an existing contract
already requires one.

## EA4 — preserve field regularity as a separate authority

The existing interior-singularity validation remains A2b-owned and separate from A2a′ disc topology. Canonical
regions must still publish `proves_field_regularity()` and `boundarySingularities` under the current exact source
binding. Do not let the upstream disc certificate bypass this gate.

## EA5 — repair and domain-name diagnostics

Audit `GlobalTopologyPlanError`, `RemeshDiagnostics.h`, `RemeshPipeline.cpp`, the stderr diagnostic emitters and test
formatter together.

- `regionFullEulerCharacteristic` / `regionChiFull`, if retained, must be whole-source-face `V_total-E_total+F`,
  never the reduced value.
- Do not publish a generic region `eulerCharacteristic/vertexCount/edgeCount/faceCount` as though it were the
  canonical region topology after its producer gate is retired. Retained support values get domain-explicit names.
- Rename/relabel `record=euler_certificate` and its reduced/full/split/barrier columns as support/projection
  diagnostics. The historical TB39 log format is not changed retroactively.
- Diagnostic-only values must not become a new acceptance authority.

## EA6 — update existing test oracles without changing selector identity

`tests/FieldAlignedCurveNetworkTests.cpp` may change assertions, but **selector409 bytes and test identity names are
frozen**.

- Ordinal **311** (`ProvesDiscTopologyForEveryEmittedRegion`): assert exact 1:1 region→upstream face-certificate
  binding and field regularity; remove proxy χ assertions.
- Ordinal **314**: keep its actual-embedded face/orbit independent proof; published-certificate agreement must use
  the new binding authority.
- Ordinal **315** (`RejectsTamperedDiscProofCertificate`): tamper the consumed face binding and require
  `InvalidRegionCertificateBinding`.
- Ordinal **313** keeps the interior-singularity half of its historical name; do not recreate an Euler rejection to
  satisfy the name.
- Shared produced-witness proof helper used by **356/357/366** (and any later A2b-reaching fixture) must check exact
  upstream face binding instead of reduced/full proxy χ.
- **312 and 409** retain their current synthetic boundary mutations and typed-oracle intent unchanged.
- Do not alter tests/fixtures owned by 368/369/370/374/398.

## EA7 — freeze later TB40 evidence now

The CB45 report must freeze `M3-CP4c-3-TB40-EXEC` as artifact-only execution of the immutable CB45 package and
selector409, one identity per fresh process. TB40 must require:

- accepted **365/365**;
- 312/409 PASS;
- 390/393/404/406/407/408 PASS;
- ownership **300/0/0** and retired-code silence;
- unchanged separate ownership of 368/369/370/374/398;
- **non-vacuous 1:1 region/upstream-face binding census**, at least one row and exactly one row per emitted region on
  every creditable produced witness reaching A2b;
- 366/367 no longer rejected solely by the retired region-support Euler proxy;
- package/source/execution censuses unchanged by TB40 and no build/repair/mutation inside the artifact-only gate.

TB40 classifies whatever later frontier 366/367 reach; CB45 does not predict that frontier as success.

## EA8 — protected scope

Do not change:

- `build_regions()` region construction, face-walk/orbit generation, rotations, arc semantics or region IDs;
- `SurfaceCutGraph` cut-selection/cellularity/source-ownership semantics;
- source-face ownership, fragment ownership, `fragmentCorners`, cut-edge selection, trace geometry;
- selector files or gate membership;
- 368/369/370/374/398 corrections;
- any A3+ product.

A diff in one of those semantic domains is a stop condition requiring Review before runtime.

## EA9 — compile/package acceptance for this turn

Compile the approved affected targets through the mandatory reusable compile workflow with GMP/GMPXX. The build
must prove:

- exact source SHA used by the workflow;
- successful configure/compile/link with `DIRECTIONAL_ENABLE_GMP=ON` and authoritative `gmpxx` + `gmp` linkage;
- selector409, selector408-prefix, harness and unchanged fixture bytes/digests recorded;
- no Directional runtime executed (`runtimeExecution=false`);
- package result/log artifacts and recursive checksums published;
- source tree clean after packaging.

A compile failure may be corrected within CB45 if the repair stays inside EA0–EA8 and no runtime executes. Any
semantic ambiguity or need to touch a prohibited domain stops for Review.

## Falsifiers / stop conditions

- A region cannot bind to exactly one current A2a′ face certificate.
- A bound upstream face certificate is not a disc or its arc count differs from the exact region boundary length.
- A copied/mutated 312/409-style candidate can retain publication authority without re-derived binding.
- The implementation needs a source-support Euler/connectivity proxy to make `proves_disc_topology()` true.
- The diff changes region construction, cut selection/ownership, a selector, or another RED owner's semantics.
- The compile cannot be produced with mandatory GMP/GMPXX and `runtimeExecution=false`.

### Part XI-A amendments to this plan

**Verified before implementation:** both stages call `build_embedded_graph_topology(...)` with identical arguments
(`GlobalTopologyPlan.cpp:2500–2502`, `SurfaceCutGraph.cpp:863`) and share `exterior_boundary_orbits(...)`
(`:869`, `:866`), so the 1:1 region ↔ non-exterior-face correspondence is real. Three corrections follow from
reading the producer:

1. **`discTopologyEstablished` is a complex-level bit, not per-face evidence.** `SurfaceCutGraph.cpp:879` computes
   `discEmbeddingEstablished` once — `graphComponents == sourceComponentCount && exterior.size() == *boundaryLoops
   && graphEuler == sourceEuler` — and `:883` stamps it identically onto every face. That conjunction is the
   standard cellularity criterion, so the binding is **sound**; but the authority A2b consumes is a
   **certified-cellular-complex** authority restricted to one orbit, not independent per-face evidence.
2. **The binding census must publish the complex-level inputs.** A census of N regions each carrying the same
   `proves_disc_topology` bit publishes one bit N times while reading as N observations. Each creditable witness
   must publish `graphComponents`, `sourceComponentCount`, `exterior.size()`, `boundaryLoops`, `graphEuler` and
   `sourceEuler` **once per complex**, alongside the per-region rows. The non-vacuity rule generalizes: **a census
   whose every row carries the same value for the field under test is not a measurement.**
3. **Ordinal 315's tamper target must vary.** `boundaryWalkCount` is a constant and `discTopologyEstablished` is
   uniform across faces; the tamper must use **`orbit`** or **`boundaryArcCount`**, or the consumed complex-level
   authority itself.

Any of these stops CB45 without a runtime attempt.

## Exact successor after successful CB45

**`M3-CP4c-3-TB40-EXEC` — immutable artifact-only Test + Benchmark under EA7.**
