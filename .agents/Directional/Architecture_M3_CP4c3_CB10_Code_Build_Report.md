# M3 CP4c-3 CB10 — Code + Build Report

Date: 2026-09-01 UTC
Turn: `M3-CP4c-3-CB10`
Type: **Code + Build only / runtime-free**
Governing authority: `Architecture_M3_CP4c3_TB7_Independent_Review_Record.md` §8, measures **AZ0–AZ9**
Verdict: **PASS — corrected implementation compiled and immutable package 78 produced; semantic acceptance remains pending TB8**

No Directional runtime, test executable, gate, benchmark, `ctest`, generated discovery command, or custom runtime input
was executed as CB10 evidence.

## 1. Immutable authority

- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`.
- Final semantic source: `e2b59295c9920db5685239c2da188858839fa94f`.
- Accepted semantic authority remains selector **365/365** until a later Test + Benchmark turn changes it.
- Selector 373 remains byte-frozen:
  `b47c269851fad1384b5dc9baaf674b3d4ad80ec6c2b40f7f8eda2055c6f44834`.
- Selector 374 remains byte-frozen and is the **gating** selector:
  `d496ce96b3776269cda8086a0a2173ce9a1f9967d81b2a80866266155c503c4f`.
- Selector 375 is the single AZ6 append and is **diagnostic / zero gate credit**:
  `aa7b22bb265f321fad6f85128e572e0251dc5f60d68856ca7ec4323006a8f3a0`.
  Its line 375 is
  `ResolvedBranchCorrection.FaceInteriorRadialArrivalsAdmitBothClosedWedgeBoundaries`.
- Selector 374 is an unchanged byte prefix of selector 375.
- `selected_gate=NONE`; `gate_execution_authorized=false`.

## 2. AZ1–AZ5 implementation

### AZ1 — admissibility and ownership are separate questions

`authority::direction_in_closed_vertex_wedge` is a distinct exact predicate for one arrival ray:
both wedge coordinates are non-negative and they are not both zero. The existing
`direction_in_vertex_sector` half-open convention remains unchanged and remains reserved for unique ownership among
developed sectors. The incoming arrival ray is no longer rejected merely because it lies on the half-open sector's
excluded radial boundary.

### AZ2 — both exact radial arrivals are supported

`resolve_field_vertex_transit` accepts `FaceInterior` arrival rays exactly on either radial boundary. The seed records
`onRadialRay` plus the exact radial vertex identity, and the ray-exact case proceeds through the existing exact
development/fallback authority rather than a tolerance or candidate-order rule. No floating-point topological
decision, nearest-angle rule, candidate-local representative, or `signedLift`-as-geometric-ray shortcut was added.

### AZ3 — one typed outcome per seed condition

The three conditions previously collapsed under `SeedDirectionNotBarycentric` now have distinct setting-site
outcomes:

- `SeedDirectionNotBarycentric` — the branch direction itself is not barycentric;
- `SeedArrivalFaceRowUnavailable` — the arrival face cannot be resolved to a source row;
- `SeedDirectionOutsideClosedWedge` — the exact reversed arrival ray is outside the closed wedge.

Each of these names is set by exactly one condition at the seed-validation layer.

### AZ4 — the audit exists before seed failure

`VertexStarTransitAudit` is created before the first returning seed conditional. Seed failures therefore publish a
non-null audit whose state remains `VertexStarTransitState::SeedUnavailable`; the seed is populated as soon as it is
derivable. `ResolvedBranchContinuation.RejectsUnresolvedRegularVertexSector` statically exercises an early seed
failure and verifies the populated audit plus reachable `SeedUnavailable` state. The other three transit states
remain reachable through their existing construction/election failure and owner paths; CB10 adds no synthetic owner.

### AZ5 — the rows have consumers

The AX8 state rows and vertex-star fields are projected by `RemeshPipeline.cpp::network_failure_locus` into
`SurfaceCellFailureLocusDiagnostics`, including `vertexTransitStates` and the arrival radial-ray fields. Consumer
search was performed by the predicate “any site that renders `SurfaceCellFailureLocusDiagnostics` into a report,
message, or assertion”, not by copying the review's examples. In addition to
`append_cp4c_failure_locus`, `ResolvedBranchCorrection.NetworkDiagnosticsPublishEveryRequiredLocusLosslessly`
directly verifies the projected diagnostic surface. The implementation/projection debt
`M3-CP4c3-TB6-CAND-01` is therefore closed at the Code + Build boundary; runtime confirmation belongs to TB8.

## 3. AZ6 — falsifying radial-arrival witness and selector governance

The final diagnostic witness is
`ResolvedBranchCorrection.FaceInteriorRadialArrivalsAdmitBothClosedWedgeBoundaries` on the planar
`make_four_triangle_fan()` with `make_planar_radial_arrival_field`.

The witness instantiates both radial orientations in arrival face `(0,1,4)` at center vertex 4:

| arrival radial | CB9 half-open seed admits | corrected closed wedge | frozen expected owner |
|---|---:|---:|---|
| vertex 0 | yes | yes | face `(2,3,4)` |
| vertex 1 | **no** | yes | face `(3,0,4)` |

The first orientation demonstrates the later CB9 `FaceInterior alpha==0` rejection; the second demonstrates the
earlier half-open seed-admissibility rejection. Thus the two old guards are falsified side by side rather than
written around. The planar star has zero curvature, zero effort, zero matching, and no singularity, so the atlas is
valid before either corrected guard is reached. Both corrected cases retain `FaceInterior`, publish an exact radial
seed identity, reach `Owner`, and have owner cardinality one.

The first local AZ6 draft reused the non-flat folded-cone helper and therefore inherited the already-adjudicated
invalid-field precondition from ordinal 374. It was corrected before final compile/package authority. The frozen
ordinal-374 witness itself was not changed, no atlas invariant was weakened, and selector 374 kept every byte.

Because the corrected witness demonstrably distinguishes CB9 from CB10, AZ6 authorizes exactly one append:
selector 375. It is diagnostic and does not expand the gate.

## 4. AZ8 — audit by assumption

Two bounded searches were performed.

1. **“An ownership convention among alternatives is used as validity on one alternative.”**
   Remaining `direction_in_vertex_sector` uses were checked against their call-site question. Named sites outside the
   review's seed-guard examples include the authority implementation in `FieldTransportAtlas.cpp` and the developed
   continuation owner check in `SurfaceCellTracing.cpp`; they are ownership/election uses, not single-arrival
   admissibility. No second instance of the CB9 defect class was found in the bounded vertex-transit surface.
2. **“A typed state or diagnostic field is declared but no path can populate it.”**
   The seed-failure path above populates `SeedUnavailable`, `network_failure_locus` projects the state rows, and
   `NetworkDiagnosticsPublishEveryRequiredLocusLosslessly` consumes them. No additional dead field/state was found
   in the bounded AZ4/AZ5 surface.

These are static implementation audits, not semantic runtime events, so stable regression accounting does not
change.

## 5. AZ9 — frozen TB8 discriminators

TB8 must interpret the immutable package using these advance predictions:

1. Ordinal 366 must clear source vertex 11. A repeat `VertexTransitSeedUnavailable` at that locus means CB10 is
   wrong.
2. Any later vertex-transit failure must publish the seed/audit/state rows through the identity's own output.
3. Vertex 30 becomes reachable again. The frozen answer remains row **209** `(30,119,123)` when
   `α < θ₂₀₉`, otherwise row **208** `(30,31,119)`; row **41** `(25,30,31)` is unreachable.
4. Ordinal 374 remains expected to stop at `ASSERT_TRUE(atlasBuild)` with the already-classified
   `CycleTransportMismatch`. This is pre-classified test-witness debt and must not itself consume another review.
5. Ordinals 367/371/372 either go green or expose their own independent loci.
6. Diagnostic identity 375 must pass both exact radial-arrival orientations with **zero gate credit**.

## 6. Authoritative compile evidence

Final compile-only run/job: `33556556002 / 100018687726` — **success**.

- exact semantic source: `e2b59295c9920db5685239c2da188858839fa94f`;
- result artifact `9819595448`, Actions SHA-256
  `b520ecc8f760b29c909ed1fe122dc15b3a9999752f4b85e263a5eafaa15facee`;
- log artifact `9819595930`, Actions SHA-256
  `0a06318c64f9d211caa9c9c92b16e341ed7870a194d3df290e82c08b58036d13`;
- all eight standard targets compiled and linked:
  `directional_core`, `directional_pipeline`,
  `directional_surface_cell_authority_kernel_tests`,
  `directional_surface_cell_producer_tests`,
  `directional_surface_cell_completion_tests`,
  `directional_surface_cell_validation_tests`,
  `directional_compiled_api_tests`, and `directional_benchmarks`;
- exact arithmetic backend `GMP`; link evidence contains both `libgmpxx.so` and `libgmp.so`;
- preflight/build exit codes `0`, final source status clean;
- `runtimeExecution=false`.

A preceding compile attempt exposed one stale reference left by the AZ6 witness replacement. That was a compile-time
control/implementation correction only; the one-line fix is part of the final semantic source above. No failed
compile produced semantic runtime evidence.

## 7. Immutable package 78

The first package-78 orchestration attempt, run `33557314415`, verified the final compile artifact and then stopped
before packaging because its caller carried selector 375's pre-AZ6 hash. It executed no Directional binary. The
caller was corrected from the immutable final source bytes and schema-validated before retry.

Final package workflow run/job `33557613904 / 100022216004` — **success**.

- package artifact `9819958467`, Actions SHA-256
  `81414f18af71d5aacf50231a720b2774df71d88b223283c81ce747d13a977a51`;
- package log artifact `9819959056`, Actions SHA-256
  `a18145ef17bf5b2eebc7b1422e67af488480d2859413709b601457e266ae6ebb`;
- inner deterministic `package78.tar.gz` SHA-256
  `2cc3541cab1208781e234948228baa2d2b8d7bfdb12d855e6fd912cb30006591`;
- packaged source archive SHA-256
  `c1eadfdc4c1f118b34f9996aec00c2b51537e45e201ff52225b1d06b0d253d11`;
- exactly 27 package-relative fixture files;
- exactly six packaged `directional_*` executables retain executable mode;
- recursive internal `SHA256SUMS` verified before upload and again after deterministic extraction;
- selector 373/374/375 hashes and append-only prefix continuity verified;
- package boundary: `runtimeExecution=false`, `packageRepair=false`,
  `exactArithmeticBackend=GMP`, `semanticContracts=compiled-not-executed`.

Package **78** is the sole immutable runtime input authorized for TB8. Package 77 is a superseded CB10 intermediate
that predates the final AZ6 witness correction and must not be used for TB8.

## 8. Disposition

CB10 is **Code + Build PASS** at the implementation/build/package boundary. It grants no semantic gate credit.
CP4c-3 remains **OPEN** and accepted authority remains **365/365**.

Stable accounting remains **44 events / 14 categories / 30 recurrences**. Produced-witness debt remains **5**.
The authoritative semantic M3 package count advances **74 → 75** with package 78; superseded package 77 does not
receive a second semantic-package count.

The mandatory successor is `M3-CP4c-3-TB8`, artifact-only, against immutable package 78. Its gate is frozen selector
374 from ordinal 1, one identity per fresh process; diagnostic identity 375 executes separately with zero gate
credit. No rebuild, repair, mutation, generated discovery, or benchmark is permitted.
