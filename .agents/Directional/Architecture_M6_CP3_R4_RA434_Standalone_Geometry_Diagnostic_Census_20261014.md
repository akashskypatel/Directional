# RA-43.4 — standalone geometry diagnostic census (source-only)

Turn: `M6-CP3-CB1-R4-RA434-CENSUS`. The separate `M6-CP3-CB1-R4-RA434-DISPOSE` decision is not part of this turn.

## Verified source

Frozen `b0d5c584a98d5ad321c324be9f18db5ba03d434b`; snapshot run [38653652905](https://github.com/akashskypatel/Directional/actions/runs/38653652905), artifact `11935277891`, ZIP SHA-256 `a476e93fa5aebcb4277ebfbccdb97778e8081d87f2536f97b47f7d9bc20bb5dd`, inner tar SHA-256 `06bcd1be757c0229bf84fab6baa21a6999f3918dd81ddae6b09e1a0eec980fc2`; **5602/5602** source hashes verified; `runtimeExecution=false`. No build, executable, test, benchmark or TB497.

## Non-`rail_interval_refs` geometry helpers: complete source-call inventory

| Helper | Source and all observed calls | Identity significance |
| --- | --- | --- |
| `rail_sample_source_vertex` | Header `include/directional/geometry/SurfaceCellTracing.h:2484`; `src/geometry/SurfaceCellTracing.cpp:5858-5886`, calls at `:5922,6058-6059`, direct test `tests/SurfaceCellTracingPhase14Tests.cpp:1904` | Only exact one-hot source-face corner, not the `sourceEdge` corner, returns `-1` otherwise; untyped inference is limited to diagnostic usage by strict caller gates. |
| `rail_sample_geometry_is_valid` | Header `:2487-2492`, implementation `SurfaceCellTracing.cpp:5889-5930`; invoked in interval validator `:6046,6049`; direct Phase14 assertions `:1876,1879,1886` each supply published vertex ID | Optional default `publishedSourceVertex=std::nullopt` may infer an exact corner. A typed ID must match actual face-corner membership and bit-exact one-hot barycentrics, with geometric position checked separately. No independent production caller found. |
| `rail_sample_is_finite` | `SurfaceCellTracing.cpp:5831-5835` → `:5894` | Numeric finiteness only; never assigns source identity. |
| `rail_position_tolerance` | `SurfaceCellTracing.cpp:5841-5844` → `:5928,6094,6116,6222` | Numeric geometry confirmation/continuity only. |
| `rail_parameter_tolerance` | `SurfaceCellTracing.cpp:5850-5852` → `:6090,6123` | Numeric parameter continuity only. |

At `SurfaceCellTracing.cpp:5971-5985`, `rail_interval_refs` demands published vertices and edge keys whenever strict mode or a nonnull field-aligned network is present; the typed branch checks real source-edge keys at `:6014-6044`. Inference at `:6058-6059` is therefore reachable only for explicitly named, no-network untyped diagnostics. Direct legacy mode sites are test-only: `tests/SurfaceCellTracingPhase14Tests.cpp:1816,1898,2206` and `tests/SurfaceCellsPhase10Tests.cpp:6525,6534,6560,6574,6595`. The latter test's network-override negative is source-authored but unexecuted. The **two identity-relevant helper APIs** are retained for adjudication; there is **no presently demonstrated untyped production entry** and no proved network bypass.

## Frozen RA-52.6 production caller table — verbatim from the Review decision

| caller | network argument | mode |
| --- | --- | --- |
| `src/geometry/SurfaceCellTracing.cpp:10498-10502` | `options.fieldAlignedNetwork` | `RequireTypedSource` |
| `src/geometry/SurfaceCellTracing.cpp:12426-12428` | `options.fieldAlignedNetwork` | `RequireTypedSource` |
| `src/pipeline/RemeshPipeline.cpp:9630-9634` | `nullptr` | `RequireTypedSource` |

All three were rechecked. RA-52.6 **PRESERVES** the named `LegacyStandaloneDiagnostic` opt-out because removing it makes the guard-coupled network-override negative vacuous. Any production caller using this mode is an immediate `REVIEW_BLOCKER`; none exists in the frozen source.

## Disposition and unchanged gates

The separately authorized `M6-CP3-CB1-R4-RA434-DISPOSE` decides what to do with `rail_sample_source_vertex` and the optional-untyped geometry checker. This turn does not invent source edits, change tests, retire the opt-out, run an unchanged-source compile, or claim liveness. `RP-02 TEST_AUTHORITY_COVERAGE_GAP` remains pending. Selector 497, accepted CP2 491/491, R3 rejected 403/497 (94 RED, 88 accepted losses), ledger 66/17/49, debt 1 and 39/34/7/88/six plus organic/A1/odd-τ/multi-carrier execution requirements are unchanged. PR #8 remains draft/unmerged.

**Procedure deviations:** entry handoff/TODO/policy reads preceded the explicit mandatory snapshot-mode decision. Local Git baseline initially failed `safe.directory` ownership validation, then succeeded after an exact-path exception. The prescribed Drive patch stage failed twice with `container_session_unavailable`; the local patch remains preserved separately and this documentation update used an exact-parent Git-object atomic write instead. These issues are not evidence of source or runtime defects.
