# Directional — R3 A3 factory attestation: exact-source call-site and authority migration impact

**Scope and status:** Technical audit for **independent Decisions A/B/C**, not a design verdict or a successor. Same unfinished `M6-CP3-CB1-ENTRY-R3` Code + Build turn. `READ_MODE=snapshot`, exact semantic commit `089779c15eae27a2bb3b798ef9c8085950e92def`, from immutable compile package `11650409049` (workflow `38005003624`, job `114071737499`). Outer SHA256 `f64575fcdfe94d371a4b0055e22339f42172f8effc90f1cc8b032a3c0a01e364`; independent internal manifest **28/28 PASS**; eight GMP/GMPXX targets compiled, `runtimeExecution=false`. No Directional binary, test, benchmark, or discovery command was executed.

## Source-grounded current contract

- `include/directional/geometry/SurfaceCellTracing.h:1838–1866`: `SurfacePhaseFrontProduct::make` is **public**, accepts supplied `SourceTopologyRegions`, source-face branch rotations, `SurfaceHardRailFieldTransition` and `SurfaceHardRailRouteCertificate` vectors. It does **not** accept an independent `FieldTransportAtlas` or separately sourced nonrail transport table.
- `src/geometry/SurfaceCellTracing.cpp:7969–8228`: factory independently validates typed topology, HardRail source incidence and published carrier consistency; each nonrail sector-step φ used in the commuting-square validation comes from the supplied route certificate (`:8195–8212`). The equality cannot independently authenticate φ. A balanced +1 Z4 mutation on both side paths can preserve the square; this is an algebraic construction, **not a runtime-tested factory acceptance**.
- `src/geometry/SurfaceCellTracing.cpp:18523–18660`: the **A4 producer** retrieves nonrail step φ and reverse through `authoritativeOptions.fieldTransportAtlas->transition_value(edge, f0, f1)` and checks exact reciprocity before constructing its published route. This is source-side attestation but does not make a public reassembler of mutable records an independent attester.
- `include/directional/authority/FieldTransportAtlas.h:835–914`: `FieldTransportAtlas` is an immutable validated source authority, with `transition_value(SourceEdgeTopologyKey, SourceFaceId, SourceFaceId)` and `matches_source_faces(const Eigen::MatrixXi&, const SourceTopologyRegions&, size_t sourceVertexCount)`. The public factory currently lacks a source-face `Eigen::MatrixXi` and independently supplied source-vertex-count binding argument. Certificate face keys must be resolved through `SourceTopologyRegions::row_for_topology` to query atlas transitions; the two certificate copies themselves are not an independent oracle.
- `include/directional/geometry/SurfaceCellTracing.h:2182–2186`: `SurfaceCellTracingOptions` already carries `const FieldTransportAtlas *`, but `src/geometry/SurfaceCellTracing.cpp:12144–12195` shows `SurfacePhaseFrontBuildState` retains transitions/certificates and not the atlas when invoking `make`. An A3-attesting factory would require additional input/binding and deliberate lifetime/ownership management, not just an assertion added inside `make`.

## Exact direct factory call-site census

Static textual invocation count: **12** (`1` production call and `11` tests), plus the factory definition (not a call). This is a source census, not generated runtime registration.

| Caller | Location on 089779c1 source | Role and migration implications |
|---|---|---|
| A4 publication | `src/geometry/SurfaceCellTracing.cpp:12195` | Real product publication from mutable build state. Production needs an independently source-bound A3 authority if Decision A chooses factory attestation. |
| FlowRep test fixture | `tests/FlowRepStrandsPhase15Tests.cpp:84` | Synthetic phase front without supplied HardRail certs; an A3 argument should not be required merely for ordinary/empty-HardRail fixtures. |
| Periodic-only direct fixture | `tests/SurfaceCellTransitionQuotientTests.cpp:315` | Periodic authority without HardRail certificates; do not force unrelated periodic cases through artificial A3. |
| Phase-front draft construction helper | `tests/SurfaceCellTransitionQuotientTests.cpp:1756` | General reconstruction helper; can receive arbitrary supplied route records and is the concentrated test adaptation seam. If certificate nonempty, independently bind atlas rather than copy φ. |
| 1/2/3 source-face factory-incidence test | `tests/SurfaceCellTransitionQuotientTests.cpp:1841` | Topology-only synthetic zero-cell test, typically no HardRail route certificates. Must retain the existing 1/2/3 incidence negative/empty-cell differentiation. |
| Bounded-disk region tests | `tests/SurfaceCellsPhase10Tests.cpp:3182,3209` | No HardRail route certificates passed; preserve their existing early error precedence. |
| Product edge-rebuild test helper | `tests/SurfaceCellsPhase10Tests.cpp:6056` | Rebuilds a produced product from all published fields including route certificates. Under independent factory validation, a source-authentic A3 input must be supplied; merely replaying product's own φ fields is not independently sufficient. |
| Shared-boundary tests | `tests/SurfaceCellsPhase10Tests.cpp:6198,6218` | Factory calls omit HardRail authority fields; preserve expected missing/foreign interval rejection. |
| Authority cutover tests | `tests/SurfaceCellsPhase10Tests.cpp:7774,7814` | Factory calls omit HardRail route fields; preserve source region/error precedence. |

`make` callsites beyond this enumerated source tree, downstream clients outside the repository and ABI exposure are **not determined by this source census**.

## Decision A — enforce an explicit answer before code/schema mutation

**A1 — A4-trusted issuance.** If the intended `make` contract is *structural reassembly of trusted A4-issued materials*, document that it is not an independent nonrail A3 provenance attester, even though it is public and checks topology. Preserve A4's atlas-based equality and reverse checks. Future tests must not claim that a balanced copied mutant is rejected by `make` because it differs from a separate atlas. Review whether external use of public `make` is compatible with that trust model.

**A2 — factory-independent attestation.** If `make` is expected to validate **arbitrary supplied** HardRail certificates against original A3, its contract must change. Require a genuine independent atlas or separately authenticated source-bound nonrail receipt when route certificates are nonempty. Specify source mesh/vertex count and canonical row binding; verify every nonrail step forward/reverse, missing lookup, orientation, typed face identity, face-row permutation and cuts/holonomy. Do not replace A3 with region face gauges or a second copy of user-provided φ. Migrate A4 publication + relevant reconstruction helpers and test only source-genuine negatives/positives. Decide behavior for already constructed product rebuilds. The current `SourceTopologyRegions` alone does not provide every input that `FieldTransportAtlas::matches_source_faces` takes; an atlas parameter by itself is not a demonstrated complete source binding.

**Reviewer-needed discriminant:** Is the public checked product factory promised to certify transport **provenance from arbitrary caller records**, or only to validate structural integrity of A4-owned published proof? This is a trust-contract decision, not a mechanical test repair. Until answered, retain current source unchanged.

## Decisions B and C — bounded source-grounded recommendations (not approval)

**B:** Existing `Code + Build` authority explicitly prohibits executing any Directional binary. One consistent proposed gate is to allow CB to close only after reviewed source/test authoring plus eight-target GMP/GMPXX compilation, then obtain **actual** organic D1/D2/D3/D5, A6/A7 and all 47 CP2 accepted-green outcomes in the separately authorized immutable artifact-only 497-process TB. Any RED returns to a separately authorized repair turn, rather than being reclassified as CB pass. An independent reviewer must reconcile original CB acceptance wording and name the successor before changing `STATUS` to `COMPLETE`. Alternative sequencing still cannot permit runtime inside CB.

**C:** Source-defined but frozen-unselected tests remain these exact four: `SurfacePhaseFrontProductFactoryAuthority.HardRailTransitionNeedsExactlyTwoSourceFaceIncidences`, `M6CP3.HardRailPublishedTauRequiresIncidentSourceFaces`, `M6CP3.A6SeamDirectionRejectsForeignFaceAndWedgeBindings`, `M6CP3.A7TypedWedgeSheetMismatchRejectsCachedMembership`. A separately counted, separately authorized artifact-only focused run is preferable to silently editing the byte-frozen 497 selectors; that is a recommendation, **not** permission to dispatch it now.

## Explicit nonclaims and next action

This report **does not** establish an A/B/C independent verdict, real A4-produced two-carrier D2 witness, D1 odd torus φ, D3/D5/A6/A7 positives, any of 39 R2 first-locus repairs, or the 47 CP2 green restorations. R2 `444/497` is historical; no new R3 Test + Benchmark was run. **Next step:** obtain a recorded independent A/B/C decision using the current exact-source evidence; until then keep `M6-CP3-CB1-ENTRY-R3` IN_PROGRESS, successor UNKNOWN, without altering public schema or frozen selectors.
