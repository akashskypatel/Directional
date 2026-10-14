# M6-CP3-CB1-ENTRY-R4 — RA-43.4 static ingress census

**Boundary:** Same R4 Code + Build turn. Static source evidence only; no runtime PASS, TB497, successor, selector mutation, or acceptance promotion.

## Exact snapshot

Source `13df05220f84cba35923855ec50d8aa6c7a6d088`; source-snapshot workflow [38492441978](https://github.com/akashskypatel/Directional/actions/runs/38492441978), artifact `11862018574`, SHA-256 `a58b3e902b224a7bffb15598cfe399df64cd5b5b9a5588e3a7bf7f15f782c3d6`. The source SHA equals the snapshot event SHA; inner archive SHA validated; **5789/5789** file hashes passed; `runtimeExecution=false`.

## Entire source call-site census

1. The public `rail_interval_refs` default is `RailIntervalAuthorityMode::RequireTypedSource` (`include/directional/geometry/SurfaceCellTracing.h:2497-2509`). The sole override is the named `LegacyStandaloneDiagnostic`.
2. All three production invocations explicitly specify `RequireTypedSource`: public tracing (`src/geometry/SurfaceCellTracing.cpp:10479-10484`), front-boundary tracing (`:12407-12410`), and rail validation (`src/pipeline/RemeshPipeline.cpp:9523-9528`).
3. In `rail_interval_refs` (`SurfaceCellTracing.cpp:5925-5974`), missing published `sourceVertices` or `sourceEdges` is rejected whenever the mode is strict **or** a real `FieldAlignedCurveNetwork` exists. Explicitly selecting the standalone diagnostic mode does not bypass network authority.
4. `rail_sample_source_vertex` (`:5842-5865`) now uses exact barycentric source-corner identity, not epsilon. Its internal fallback use (`:5906`, `:6042-6043`) is on the untyped diagnostic branch after the strict ingress guard. A direct invocation of this helper from production outside this boundary was not found. Existing Phase14 test use remains.
5. `LegacyStandaloneDiagnostic` usage outside the enum/implementation occurs only in `tests/SurfaceCellsPhase10Tests.cpp` and `tests/SurfaceCellTracingPhase14Tests.cpp`, not in `src/` or other production includes. The existing `StandaloneRailDiagnosticModeCannotBypassProducedNetworkTypedIngress` regression exercises produced-rail positive, untyped standalone opt-out, strict rejection, network-override rejection, missing published key and foreign published key (`SurfaceCellsPhase10Tests.cpp:6496-6583`). **It has not executed under Code + Build.**

## Disposition

The **static production call-site migration** portion of RA-43.4 has no remaining untyped-source inference path on this source. Retain the explicit diagnostic helper and fail-closed guards; no broad runtime closure or suppression of the remaining R4 gates is justified by a source census. A separate authorized TB turn must execute the tests.

The compile request for this source is `m6-cp3-r4-closedrail-resume-compile`; its completion and immutable package evidence must be reconciled separately.
