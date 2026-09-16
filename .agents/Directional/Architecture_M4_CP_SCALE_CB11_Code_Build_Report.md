# M4-CP-SCALE-CB11 Code + Build Report

**Disposition:** COMPLETE / COMPILE + PACKAGE GREEN / RUNTIME UNEXECUTED
**Semantic source:** `2adb7b8169a387fcb6db6487768d7bd3d678265c`
**Compile run/job:** `35130835524 / 104911222945`
**Candidate artifact:** `10461816370` / provider SHA-256 `93f47702e3919eff0b5503acd7506fbdf661477b6b55b91a0f29fc5a98be2358`
**Required successor:** `M4-CP-SCALE-TB10-EXEC`

## 1. Boundary

CB11 executed only the bounded S4 product-activation Code + Build plan. It authored product/test semantics, compiled and packaged them, and executed no Directional binary. Package evidence records `runtimeExecution=false`; no test, benchmark, CTest, discovery/list/help/version command, or generated executable was run. Accepted runtime authority is unchanged: TB9 Review package `10455353524` / semantic source `bebb14e32a0ac53dd420acf46bfa34410cf759a1` under selector425 **425/425**.

## 2. Semantic changes

Exactly four semantic paths changed: `src/geometry/EmbeddedGraphTopology.cpp`, `src/geometry/EmbeddedGraphTopology.h`, `src/geometry/SurfaceCutGraph.cpp`, and `tests/FieldAlignedCurveNetworkTests.cpp`. No public `include/**` API, fixture, CMake semantic, selector, or benchmark source changed.

The product adds an exact fixed-candidate S4 receipt using the actual embedded graph and a connected actual-complement count reconstructed independently of `proposal_components`, face-walk orbit count, and final-certificate fields. Unavailable/impossible reconstruction falls through to unchanged final certification. A rejecting invariant skips only that doomed full certification attempt and then enters the existing proposal path; it does not return a new semantic failure, mutate/reorder cuts, backtrack, repair topology, weaken final certificate authority, or accept a candidate.

The internal diagnostics expose `candidateEvaluations`, `earlyRejectedCandidates`, `fullCertificationAttempts`, and `bypassedFinalCertificationAttempts`; a test-only reference seam runs the same canonical search with S4 disabled. The focused identity is defined exactly once in the producer owner: `M4CPScaleS4.IncrementalTopologyRejectorNeverDisagreesWithFinalDiscCertificate`. Its test-side connected-complement oracle remains structurally separate and statically covers the accepted empty-cut negative, accepted-cut positive, one-edge adversarial implication, reversed enumeration, accelerated/reference decision neutrality, and deletion discriminator.

## 3. Frozen selector checks

Selector425 remains exactly 425 unique LF rows at `e0e0f394faae536ac257ec5409653a34755a8afe0ca437562eb44c9895790e0b`; exact first424 remains `f202a1720c0a5288471d04836402b8432eb6f4f788da68a12e70dacb875466ca`. No selector426 exists.

## 4. Compile/package evidence

Mandatory reusable compile workflow run/job `35130835524 / 104911222945` used exact semantic source `2adb7b8169a387fcb6db6487768d7bd3d678265c` with GMP/GMPXX. Changed-owner preflight `directional_surface_cell_producer_tests` exited `0`; full build exited `0`; all eight standard targets were packaged. Generated link evidence contains both `libgmpxx.so` and `libgmp.so`.

- result artifact `10461816370`, provider/package ZIP SHA-256 `93f47702e3919eff0b5503acd7506fbdf661477b6b55b91a0f29fc5a98be2358`
- log artifact `10461716532`, provider SHA-256 `4ff36bd4421b7baf7a6d99187fd1be491a0a8bb94b969ec1885f8ccaa7b498fc`
- source archive SHA-256 `79ea26c2f9faf9499e33db02c65cba04b47f3a64eeb35b0c4c421fcf45c50afe`
- 28-entry package `SHA256SUMS`, all verified; manifest SHA-256 `ef128c01e17db2eebb78e7e92722f732af040d8a6862cda9b24f9e5969ca6dbf`
- source status before/after configure, after build, and final: empty
- `exactArithmeticBackend=GMP`, `runtimeExecution=false`

Compile GREEN provides zero S4 runtime or selector credit.

## 5. Successor

Exact successor is artifact-only `M4-CP-SCALE-TB10-EXEC` under `Architecture_M4_CP_SCALE_TB10_Artifact_Only_Test_Benchmark_Plan.md`: run the focused S4 product identity first, then selector425 as 425 additional fresh exact-filter processes only if focus is GREEN, followed by mandatory `M4-CP-SCALE-TB10-REV` before selector426 publication or cumulative S4 credit.
