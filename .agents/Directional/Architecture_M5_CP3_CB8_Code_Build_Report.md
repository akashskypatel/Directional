# M5-CP3-CB8 Code + Build Report

**Turn:** `M5-CP3-CB8`
**Boundary:** Code + Build only / runtime-free
**Result:** **COMPLETE / STATIC FALSIFIERS GREEN / GMP COMPILE-PACKAGE GREEN / RUNTIME UNADJUDICATED**
**Exact successor:** `M5-CP3-TB1-R7-EXEC`

## 1. Source authority and bounded change

The turn entered from reviewed authority `M5-CP3-TB1-R6-REV` and executed
`Architecture_M5_CP3_CB8_Source_Face_Incidence_Authority_Correction_Plan.md` without widening semantic scope.
The only semantic source changed is `src/geometry/SurfaceCellTracing.cpp`.

The semantic patch was pushed as commit `31d437a0864f99cb44d06430e0faa85c57c862be`. The exact compile source is
`baae6307d189639fdf7d8a0011f5ba5f30de1631`; intervening commits between those identities are temporary-control
cleanup only. No public header, `FieldTransportAtlas` source/API, test, fixture, selector, benchmark, frozen
definition, relation factory, or acceptance expectation changed.

## 2. Implemented correction

CB8 preserves A3's already-authoritative carrier incidence instead of substituting an A4 point representation:

- `SurfacePhaseFrontBuildState` now retains a checked local association keyed by exact
  `SurfaceBoundaryOccurrenceId + NetworkArcId + SourceEdgeTopologyKey` to the accepted
  `AcceptedCutBoundarySegment::sourceFace`.
- The association is populated only after the existing A3 accepted-cut source-face ownership check succeeds.
  Contradictory duplicate authority or contradictory cross-region merge fails closed through the existing
  `InvalidFrontBoundaryAuthority` owner.
- `generator_route_for_span(...)` now receives the two exact reciprocal boundary occurrences, resolves their
  directed `SourceFaceId` values from that accepted authority, and never uses `first.from.face`, `second.to.face`,
  or another `SurfaceTracePoint::face` as generator-route incidence authority.
- The exact one-piece `Mandatory` source-path carrier resolution is unchanged.
- The two occurrence-owned faces must be valid, distinct, and equal the carrier edge's two `sourceEdgeFaces`
  entries as an **unordered pair**. Container order is used only for membership validation and never to invent
  query direction.
- `FieldTransportAtlas::transition_value(...)` receives the occurrence-owned directed pair. Existing edge
  orientation, transition identity, route, `GridAutomorphism`, action-correspondence, checked holonomy, failure
  reason numbering, hard-feature barrier and nontraversability behavior remain unchanged.

## 3. Static falsifiers

The final source/diff satisfies the frozen CB8 falsifiers:

1. No generator-route transition-value query is sourced from A4 endpoint `.face` provenance.
2. Each directed query face traces to exact accepted-cut `sourceFace` authority keyed by the reciprocal boundary
   occurrence, span and carrier.
3. Carrier consistency is revalidated against `sourceEdgeFaces` as a set, with no semantic dependency on its
   storage order.
4. Hard-feature traversability is untouched; only retained atlas `transition_value(...)` is consumed.
5. Semantic changed-path census is exactly `src/geometry/SurfaceCellTracing.cpp`.

`M5-CP3-TB1-R6-REV-OBS-01` remains intentionally open: CB8 preserves the frozen action-correspondence machinery
rather than adding a second direction oracle in product code. R7 Review must independently verify that the
directed pair/action observed by the six produced identities agrees with the independent A3 orientation and
reciprocity authority before any promotion or debt credit.

## 4. Work-preservation and remote application

The exact user-visible/Drive-staged patch is
`Directional__M5-CP3-CB8__base-ba7f09493e3e__work-preservation.patch`:

- exact base: `ba7f09493e3e5c4ca488e2c0c00a02aafc20b0fd`;
- complete patch SHA-256: `0c6b8fe88fbf6948844cb227650960048246b6dca60ad9b946e466f58bb52c67`;
- diff-body SHA-256: `42bd45c6b236ee14a0a1ac3be03b23b9b2b9b0aa4a5df0b4d0f70b8a180f43e9`;
- intended path: `src/geometry/SurfaceCellTracing.cpp` only.

Local `git apply --check` and `git diff --check` passed before staging. Drive application run `35623666059`, job
`106412658580`, verified those hashes and the exact base, applied the one-file patch, passed `git diff --check`,
and pushed semantic commit `31d437a0864f99cb44d06430e0faa85c57c862be`. Result/log artifacts are
`10649899793 / 10649954790` at outer SHA-256
`15bbe34df803b45909dbc1a20eba5a0232f5afb0d71efe31fb36bfcb3e7fd0fc /
1986b116be801c78e1eb1288c735a66d62916de8a242c7de8ff84d8d1b2d28c4`.

The workflow identity could not trash the Drive file and explicitly returned owner cleanup required; the connected
owner Drive control plane then permanently deleted the exact staged File ID after successful push.

## 5. Mandatory GMP compile/package gate

Compile run/job `35623934990 / 106413580650` completed successfully through the mandatory
`agent-compile-reusable.yml` path from exact source `baae6307d189639fdf7d8a0011f5ba5f30de1631`.

All eight required targets compiled and linked:

1. `directional_core`
2. `directional_pipeline`
3. `directional_surface_cell_authority_kernel_tests`
4. `directional_surface_cell_producer_tests`
5. `directional_surface_cell_completion_tests`
6. `directional_surface_cell_validation_tests`
7. `directional_compiled_api_tests`
8. `directional_benchmarks`

The package records preflight/build exit **0/0**, `runtimeExecution=false`, `turnBoundary=Code+Build-only`,
`exactArithmeticBackend=GMP`, explicit `/usr/lib/x86_64-linux-gnu/libgmpxx.so` plus `libgmp.so` linkage, and empty
source-status receipts before/after configure, after build and at finalization. No generated Directional binary,
test, benchmark, discovery command, `ctest`, CLI, fuzzer, help/version command or custom input was executed.

Compile result artifact `10651055588` has provider/download SHA-256
`376f61120b4a71dd9747daae8c248fe766bbf899faac0e2f336fc97e57acda96`; diagnostic log artifact `10651435428`
has provider/download SHA-256 `c2f9a47c0b9346fe9ab35394b2460d9ca6517aa7dcc5608dc1980c38ee589d53`.
The package root `SHA256SUMS` is self-excluding, hashes to
`06f7e6f068a6b390d212da07928b7088918ee675ccd1968355497b8143f598cd`, and verifies **28/28**. Packaged source
archive SHA-256 is `f75528fe7c9349d76430bbe06ca67e4593cce452107071405ed2c6c7d848143f`; its
`SurfaceCellTracing.cpp` is byte-identical to the compiled correction.

## 6. Runtime, accounting and acceptance boundary

CB8 earns compile evidence only. No runtime process was executed and no recovery, promotion, selector publication,
or produced-witness debt credit is claimed. The open stable `M5-CP3-TB1-R1-CAND-01 / RP-01
AUTHORITY_DOMAIN_CONFLATION` event remains open pending corrected runtime. Stable accounting therefore stays
**50 events / 14 categories / 36 recurrences**, debt **5**. Accepted runtime authority remains package/source
`10601978228 / 0798547dedd8be05f9cd7a096b07e6bd94755316` under byte-frozen selector430 **430/430**.

## 7. Control-plane process notes

Before explicitly selecting the mandatory repository `READ_MODE`, this turn performed one batched direct authority
read containing the handoff/TODO after the policy source had not yet been fully exposed. Once
`TOOL_USE_CONSERVATION_POLICY.md` exposed the pre-read gate, piecemeal inspection stopped and the turn switched to
`READ_MODE=snapshot`. Source-snapshot run `35622547203` produced artifact `10649018954` at event/snapshot SHA
`ba7f09493e3e5c4ca488e2c0c00a02aafc20b0fd`; provider/local outer SHA-256 is
`6e80b3c04a386e25170bb98ce40a5cb119cdbaf5ddde5bd6d807bc87319d1fc4`, contained archive SHA-256 is
`6635f464b2f2d7f8346a8fac2f18356d8f915e465e9bec6bfd9a1a73f98fa260`, and the extracted **5296/5296** file
manifest verified. Subsequent substantive source/document inspection used those snapshot bytes.

The connector exposes no workflow-dispatch write action, so the temporary Drive-apply and compile callers used the
repository's established marker-gated bootstrap pattern: each caller invoked the mandatory SchemaStore validator
as its first reusable gate, and its workload depended on successful validation. Both validations passed. Temporary
callers were deleted workflow-first and their markers were removed after evidence capture.

The turn-local tool-call ledger was not preserved exactly from the first invocation. Per policy, closeout reports
that ledger as **partial/unknown** rather than reconstructing or guessing it; no accounting-only tool calls are
spent to recover it.

## 8. Disposition

CB8 is complete as a runtime-free Code + Build turn. Candidate artifact `10651055588` is compile/package green but
runtime-unadjudicated and unpromoted. Exact successor is artifact-only `M5-CP3-TB1-R7-EXEC` under
`Architecture_M5_CP3_TB1_R7_Artifact_Only_Test_Benchmark_Plan.md`.
