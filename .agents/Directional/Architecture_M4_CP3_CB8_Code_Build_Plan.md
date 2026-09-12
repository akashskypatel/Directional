# M4-CP3-CB8 Code + Build Plan — consume cut-open A2b/A3 occurrence authority at A4

**Turn:** `M4-CP3-CB8`
**Status:** COMPLETE / COMPILE-GREEN / RUNTIME NOT EXECUTED
**Turn type:** product Code + Build / runtime-free
**Owner:** `M4-CP3-TB5-REV-CAND-01`
**Entering accepted runtime authority:** R4 artifact `10289601000` / selector403 `c3f509afc823cd73761bdebea0d072d497acf5587a013cb52b795f273af70cb7` / **403/403**
**Rejected candidate:** CB7 artifact `10293750596` / selector408 `c689c0cd8a51f9a8bd8c9ed3a2e8b603728d5a0359ee2732f776a422744b0484`
**Future runtime successor if build green:** artifact-only Test + Benchmark focused recovery gate, then full cumulative gate only if the focused discriminator passes; both require Review before promotion.

## 1. Problem frozen by Review

CB7/TB5 proves row408 now supplies exactly the intended 18-edge two-generator torus cut graph and reaches A4 with A1/A2a/A2b/A3 authority retained. TB5 fails because A4 regional applicability switches back to uncut raw source-face topology:

1. uniform production intentionally returns `NotApplicable` when an accepted conformity plan and hard-feature rails are present;
2. periodic-annulus production intentionally returns `NotApplicable` under the same condition because it cannot publish accepted A3 shared-boundary interval identity;
3. curved bounded-disk production computes `V-E+F` and boundary from `edge_faces(faces, activeFaces)`, i.e. the uncut source submesh;
4. row408's active source-face set is the full closed torus (`72-216+144 = 0`), while accepted cut support is a disc (`chi=1`, one boundary loop);
5. the curved producer returns `NotApplicable`; aggregate dispatch then rejects hard-feature authority as `UnsupportedSourceSheetTopology`.

The defect is an A4 **authority-domain** mismatch. It is not licensed to change A1/A2b topology, A3 schedules, row408 fixture authority, or hard-rail pairing semantics.

## 2. Mandatory pre-mutation guard — STOP on any failed proof

Before changing a repository byte, re-derive all of the following from exact source + fixture bytes. Preserve a machine-readable guard report.

### G1 — reproduce the forced dispatch

Prove for row408's exact options/source:

- effective `HardFeature` set is exactly the frozen 18 source edges;
- `GlobalTopologyPlan` and `GlobalConformityBaselinePlan` are present and bound;
- uniform producer's accepted-plan+hard-feature guard forces `NotApplicable`;
- periodic-annulus producer's accepted-plan+hard-feature guard forces `NotApplicable`;
- curved bounded-disk raw active-face Euler is exactly `0` because it counts the uncut `72/216/144` source support;
- accepted reduced/cut support is exactly `chi=1` with one boundary loop;
- aggregate dispatch therefore reaches the typed `UnsupportedSourceSheetTopology` branch.

If any link is not source-proved, **STOP before mutation**. Do not add diagnostics and guess around it.

### G2 — prove the upstream cut-open authority already exists

Show that the accepted A2b/A3 products, without floating/local-grid inference, uniquely provide the data needed for a cut-open A4 boundary:

- one checked `GlobalTopologyRegionDiscCertificate` per consumed A2b graph face;
- an exact oriented `GlobalTopologyRegion::boundary` arc walk;
- each boundary arc binds to an exact `GlobalTopologyArc::sourcePath`;
- A3 `GlobalConformityBaselinePlan` binds each accepted arc/span to immutable schedule/breakpoint authority;
- the mapping from A2b boundary occurrence to its owning A1 source-topology region is deterministic and total for the row408 witness;
- opposite sides of one hard rail remain distinct **boundary occurrences** until the final exact A3 interval pairing step.

A source vertex id by itself is **not** an occurrence identity. Row408's two generators share vertex `0`, and a cut-open disk necessarily contains repeated occurrences of that source vertex. If the existing typed products cannot distinguish those occurrences without inventing new authority, **STOP before mutation** and return to Review/DEFN. Do not encode occurrence identity by arbitrary duplicate integers, geometry, traversal order that is not already authoritative, or tolerance-based matching.

### G3 — prove the minimum representation seam

Trace the current bounded curved producer from boundary phase through chart construction and identify every structure keyed by raw source vertex or raw one-sided source boundary that would collapse cut copies. At minimum the guard must account for:

- raw `boundaryAdjacency` keyed by source vertex;
- raw `boundaryEdgeKeys` populated only by one-sided source edges;
- `vertexUv` keyed by global source vertex;
- boundary support checks that currently recognize only raw boundary edges;
- final `HardRail` opposite-edge pairing by exact A3 interval identity.

Freeze the smallest occurrence-keyed replacement surface that can preserve both cut copies through chart construction. If correction requires a cross-stage redesign beyond A4's declared products or a second new semantic authority, **STOP before mutation**.

## 3. Authorized product correction after a green guard

Only after G1-G3 all pass, make the minimum A4 product changes required to consume accepted cut-open occurrence authority.

Required semantics:

1. **Planned hard-rail domains use A2b/A3 boundary occurrence authority.** When `globalTopologyPlan` + `globalConformityBaselinePlan` are present and the region carries hard features, bounded-disk applicability may not be decided from whole-source-face Euler/boundary alone.
2. **Do not weaken the physical bounded-disk path.** Existing no-plan / genuine source-boundary behavior keeps its current raw-domain validation.
3. **Occurrences, not vertex ids.** The cut-open chart must allow multiple boundary/chart occurrences of the same source vertex to hold distinct chart state. Source vertex `0` in the row408 figure-eight cut is the mandatory discriminator.
4. **A2b remains topology writer.** A4 consumes the accepted disc certificate/oriented boundary; it may not recompute graph faces, choose a different cut, or reinterpret hard rails from geometry.
5. **A3 remains subdivision writer.** Shared hard-rail breakpoints/ordinals and span identity come from the accepted baseline schedule unchanged. No local resampling or floating `support_key` fallback.
6. **Pair only after chart materialization.** Opposite cut sides stay distinct/exterior occurrences until the existing exact span + consecutive ordinal + reversed route pairing proves they are the two copies of one shared hard-rail interval.
7. **Fail closed.** Missing/ambiguous occurrence binding, non-disc accepted authority, contradictory A3 schedule, or inability to preserve cut copies must publish a typed rejection. No legacy tracing fallback for a hard-feature region.

Expected primary product surface is `src/geometry/SurfaceCellTracing.cpp` plus the minimum declaration/header support genuinely required by the occurrence representation. Do not touch unrelated pipeline stages.

## 4. Test contract

The existing selector408 identity remains the end-to-end discriminator and must not be weakened or renamed:

`RemeshPipeline.ExactA3ToA4TorusProductionPathPublishesTypedSharedBoundaryIdentity`.

It must continue to require, in order:

- exact effective 18-edge hard authority;
- retained A1/A2a/A2b/A3 products;
- A4 phase front `Produced`;
- A3 topology/baseline receipt digests;
- every produced hard-rail front edge has exact `sharedBoundaryInterval`;
- at least one exact shared hard interval exists;
- terminal detail is not `InvalidHardRailPairing`.

CB8 may strengthen row408 only with a **non-vacuity assertion directly required by the occurrence fix**, e.g. proving the constructed boundary retains distinct occurrences of the shared cut vertex. It may not alter the 18-edge fixture, thresholds, expected disposition, or relax any existing assertion.

Prefer reusing existing helpers/types. A new selector identity is **not authorized** unless the pre-mutation guard proves row408 cannot distinguish deletion of the occurrence-keyed correction. If that happens, STOP and return to Review rather than silently expanding selector408.

## 5. Frozen selector / accepted-prefix invariants

Unless Review is re-entered, selector bytes stay unchanged:

```text
selector403 rows/hash = 403 / c3f509afc823cd73761bdebea0d072d497acf5587a013cb52b795f273af70cb7
selector408 rows/hash = 408 / c689c0cd8a51f9a8bd8c9ed3a2e8b603728d5a0359ee2732f776a422744b0484
first403 = byte-identical selector403
owners = 30 authority-kernel / 262 producer / 75 completion / 41 validation
row408 = producer-owned
```

Any selector or owner drift is a STOP.

## 6. Compile/package boundary

CB8 is runtime-free. After semantic edits:

- emit the required recovery/WIP patch before remote mutation;
- compile first the changed owner target `directional_surface_cell_producer_tests`;
- compile/link the same frozen package target set used by CB7 through the mandatory reusable GitHub workflow;
- require GMP/GMPXX linkage, clean source-status snapshots, immutable package manifest/source archive, and `runtimeExecution=false`;
- preserve the exact semantic source SHA and package artifact/digests.

Forbidden in CB8: GTest execution or listing/discovery, `ctest`, benchmark execution, produced Directional binary execution, package repair, selector generation, or changing reusable workflow permissions.

A compile error may receive only bounded compile/orchestration remediation that does not widen product semantics. A second semantic dependency outside the guarded A4 occurrence seam is a STOP back to Review.

## 7. Future runtime gate

If CB8 builds green, Test + Benchmark must consume the immutable package directly.

### Focused recovery gate first

Run row408 twice in fresh exact-filter processes. Both must:

- select exactly one identity;
- PASS;
- emit/retain evidence that the effective hard set is exactly 18;
- reach A4 `Produced`;
- retain matching A3 receipt digests;
- publish exact shared-boundary intervals on hard-rail front edges.

Any RED/SKIP/crash/timeout/selection mismatch is fail-fast and returns to Review without spending the cumulative selector gate.

### Cumulative gate only after focused 2/2

Then run rows404-407 twice, accepted selector403 **403/403**, and candidate selector408 **408/408** in the same frozen fresh-process discipline used by TB5. Immutable pre/postflight is mandatory. Review, not EXEC, decides promotion and CP3/`G4-B002` status.

## 8. Acceptance / stop conditions

CB8 completes only if:

- G1-G3 are fully proved before mutation;
- one bounded A4 occurrence-authority correction is implemented without introducing a second topology/subdivision writer;
- physical bounded-disk behavior and fail-closed semantics remain structurally intact;
- selector403/408 bytes and ownership remain frozen;
- mandatory GMP/GMPXX compile/package is green;
- no Directional runtime executes.

Hard STOP and return to Review/DEFN if any of these is required:

- altering A1/A2b/A3 authority to fit A4;
- raw-vertex duplication without typed occurrence identity;
- geometry/tolerance-based cut-side pairing;
- forcing raw Euler/boundary checks to pass rather than consuming accepted cut topology;
- changing row408 fixture authority or suppressing its failing assertion;
- adding a second unrelated product correction;
- selector mutation.


## 9. Executed CB8 closeout — compile authority only

CB8 completed the frozen runtime-free product correction without widening the reviewed seam. The pre-mutation G1-G3 guard was preserved as machine-readable recovery evidence and passed before product mutation. The accepted implementation consumes A2b/A3 cut-open boundary **occurrences** in the curved bounded-disk A4 path while leaving the physical raw bounded-disk path intact. `SurfaceBoundaryOccurrenceId` carries typed region + canonical boundary-occurrence ordinal identity through planned shared-boundary intervals; opposite hard-rail cut copies remain distinct until exact A3 span/ordinal/orientation pairing. The final bounded compile remediation only unwraps an already-checked `DomainResult<SourceVertexId>` with `.value()` and does not change product semantics.

Final semantic source is `6934d9edfb56b44f956fbc64a89a501aaed042af`. Selector authority remained byte-frozen:

- selector403: 403 LF identities, SHA-256 `c3f509afc823cd73761bdebea0d072d497acf5587a013cb52b795f273af70cb7`;
- selector408: 408 LF identities, SHA-256 `c689c0cd8a51f9a8bd8c9ed3a2e8b603728d5a0359ee2732f776a422744b0484`;
- first403 byte-identical; owner partition **30 authority-kernel / 262 producer / 75 completion / 41 validation**.

The first compile run `34708704308` stopped at one compile-only defect in `SurfaceCellTracing.cpp`: `SourceVertexId::from_index(...)` returns `DomainResult<SourceVertexId>`, so the new occurrence signature could not use unary `*`. No generated Directional runtime executed. The one-line `.value()` remediation was applied by Drive workflow `34708941120`, producing the final semantic source above.

Authoritative retry run `34709028122` is GREEN. The changed-owner `directional_surface_cell_producer_tests` compile and the frozen eight-target package compile both succeeded under mandatory GMP/GMPXX. Package result artifact `10303165017` has provider SHA-256 `d601e5efc4d6a3cafc34d4a5ead0a5a44040e3026d31b3f75afad59c71b68112`; package log artifact `10303015368` has SHA-256 `2f284cc6b3b67dbbb07d27060c3d94185ba021dc08708bb5f04f54796f65baa1`. Owner result/log artifacts are `10302114686` / `10302019734`, SHA-256 `25a07df6fa2ffc62c8fb4aa2d671baed5d0eb3d300695eea8376e0c91fd815ed` / `39380717691a2b98a985c3efa9e0f55143349c6cfb8a98cea94e31d895d7ada2`. Local inspection of the immutable package verified all **28/28** root `SHA256SUMS` entries, exact packaged source commit `6934d9ed...`, source archive SHA-256 `7b906b0ad1560d3cb158178ae224d2d391e8fee66d7268f78ba2ed172a0ec5eb`, empty source-status snapshots, exact eight target outputs, `exactArithmeticBackend=GMP`, and `runtimeExecution=false`.

Compile success is **not** runtime acceptance. Corrected R4 artifact `10289601000` / selector403 **403/403** remains reviewed runtime authority. Candidate selector408 is still unpromoted; `M4-CP3-TB5-REV-CAND-01`, CP3 and `G4-B002` remain open pending immutable artifact-only execution and Review.

**Exact successor:** `M4-CP3-TB6-EXEC`, consuming only package artifact `10303165017` under `.agents/Directional/Architecture_M4_CP3_TB6_Artifact_Only_Test_Benchmark_Plan.md`. CB8 authorizes no runtime itself.
