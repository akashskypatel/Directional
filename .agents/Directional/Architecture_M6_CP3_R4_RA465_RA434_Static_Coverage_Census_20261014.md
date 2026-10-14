# M6-CP3-CB1-ENTRY-R4 — terminal A3 negatives and typed-rail source census (2026-10-14)

**Authority:** canonical R4 Code + Build, still IN_PROGRESS; PR #8 draft. Frozen exact-source snapshot `0326e9ac3091b3e1fa0ef62ea8224cc4d218e5e2` via [workflow 38505236129](https://github.com/akashskypatel/Directional/actions/runs/38505236129), artifact `11867082482`, ZIP SHA-256 `6ff2b31331904cf84bd95997663872fd30b2ff68b84a1b13c178d718d27951d1`, tar SHA-256 `5e3bae7f98d9a72dd2c119240b0d932149e6a1a8303d967605c018985ba4b30f`, `5827/5827` file SHA-256 checks passed. No runtime, compile or test execution in this census.

## RA-46.5: source negative coverage versus runtime proof

The *remaining reachable* consumer first-rejection candidates already have dedicated, compiled-but-unexecuted source regressions; do **not** add duplicates and do **not** mark them runtime-green:

| Reachable consumer first rejection | Existing first-rejection source oracle | Proof limit |
|---|---|---|
| `ambiguous-terminal-contact` | `tests/SurfaceCellsPhase10Tests.cpp:6996-7035` (`DuplicateSourceTerminalContactRejectsAtFirstA4ConsumerPredicate`), duplicate typed `{v,v}` from a genuine producer contact | Requires artifact-only execution to prove first rejecting stage |
| `no-exact-terminal-corner` | `tests/SurfaceCellsPhase10Tests.cpp:7037-7094` (`ForeignSourceTerminalContactRejectsAtFirstA4ConsumerPredicate`), distinct valid foreign typed vertex | Requires artifact-only execution to prove first rejecting stage |
| `missing-terminal-A3-path` | `tests/SurfaceCellsPhase10Tests.cpp:7096-7138` (`MissingTerminalA3PathRejectsAtFirstA4ConsumerPredicate`), produced non-hard spoke promoted to hard barrier | Requires artifact-only execution to prove first rejecting stage; earlier-stage failure is RED |

The typed **factory** distinction required by RA-46.6 is already implemented: `SurfacePhaseFrontSourceAuthorityDetail::{MissingTerminalA3Path,AmbiguousTerminalA3Path}` in `include/directional/geometry/SurfaceCellTracing.h:1873-1882`; producer selects these details in `src/geometry/SurfaceCellTracing.cpp:8605-8614`, and `tests/SurfaceCellTransitionQuotientTests.cpp:9155-9244` exercises typed details. Do not implement this a second time. It is distinct from the consumer's `a2bProbeFailure` first-predicate obligations.

Per frozen RA-49/51: `nonmanifold-terminal-star-spoke` is retired under RA-48 source/DCEL guards; `overlapping-terminal-sectors` and `missing-or-nonreciprocal-terminal-A3` are retired under RA-51's source-graph proof and paired guards. They remain fail-closed predicates in production, **not** fixture obligations. This is a static coverage census; it does not amend any frozen definitions or waive retained guards.

## RA-43.4: typed-rail ingress authority

All three **non-test** `rail_interval_refs` invocations explicitly use `RailIntervalAuthorityMode::RequireTypedSource`: trace ingress `src/geometry/SurfaceCellTracing.cpp:10480`, A4 open-front consumer `:12408`, and pipeline producer validation `src/pipeline/RemeshPipeline.cpp:9524`. `rail_interval_refs` defaults to strict (`include/directional/geometry/SurfaceCellTracing.h:2496-2510`) and, at `src/geometry/SurfaceCellTracing.cpp:5920-5959`, requires a producer-authored source-vertex chain *and* published source-edge keys whenever strict or network-bound. The legacy diagnostic opt-out is explicit in test files only (`tests/SurfaceCellTracingPhase14Tests.cpp`, `tests/SurfaceCellsPhase10Tests.cpp`), and an actual `FieldAlignedCurveNetwork` overrides it. The fallback function `rail_sample_source_vertex` is still reachable from **only** the explicit no-network diagnostic at `src/geometry/SurfaceCellTracing.cpp:6042-6043`; `tests/SurfaceCellTracingPhase14Tests.cpp:1896-1915` checks exact-corner rather than epsilon acceptance. Existing `tests/SurfaceCellsPhase10Tests.cpp:6502-6585` checks that a real network forbids missing and forged producer identities even if the caller requests diagnostic mode.

**Interpretation:** production strict-callsite coverage is source-audited, not a global RA-43.4 runtime disposition. Genuine producer-to-consumer edge identity on new organic networks and the legacy diagnostic migration/retirement policy remain separately open. Do not weaken strict ingress or delete intentionally explicit diagnostic coverage solely to increase a test count.

## Work still owed (not closed by this census)

RA-43.1 live source-vertex-star/multi-carrier germ and RA-43.4 global source coverage; RA-47.12 production liveness; *execution* of the compiled first-rejection regressions only in the separately authorized artifact-only Test + Benchmark turn; historical 39 endpoint / 34 Phase10 / seven DCEL / 88 accepted CP2 losses / six CP3 positives; organic D1/D2/D3/D5/A6/A7; genuine odd-τ multi-carrier witness. R4 is **not complete**. Selector 497 untouched; no TB497, runtime commands, source-code mutation, GMP compile, or successor turn in this source-only census. Ledger `66/17/49` and debt `1` are unchanged historical facts, not new measured output.

## Applied static-record evidence (supersedes transport-pending state)

- Exact three-path patch, full SHA-256 `5cbc59131b738be7ceac5607f2732037d897c3800ac2d4b600f87a827ea73a26`, diff-body SHA-256 `2e2acb5fb0ecfa0613c77e205222c0e7d4f91b83a246a50198f5bbf85db5d5a9`, base `0326e9ac3091b3e1fa0ef62ea8224cc4d218e5e2`. Exact-base forward/reverse and whitespace checks passed locally; no source changed.
- Drive dispatcher commit `e0abb8de3f6aea72cff5f5ef14c39be6dc203442`, [workflow 38505937817](https://github.com/akashskypatel/Directional/actions/runs/38505937817), apply job `115663434797` GREEN, mailbox exact source/event verified. Receipt artifact `11867524398`, ZIP SHA-256 `a1f1d808d58816d5c68fb439124b9ed6616521e004fb8f3d350caeee4c6f84b3` confirms semantic commit [`a3f5694`](https://github.com/akashskypatel/Directional/commit/a3f56944192d3a753e523c08d2a645c4ff1fe72c), exact patch hash/base, and `runtimeExecution=false`; independent commit inventory lists only this census, TODO, and handoff. The staging Drive file was owner-deleted successfully, and the consumed source-snapshot marker was deleted in `08d31bf7caffc560d0ee0d0ff597b7a2a5ace998`.
- R4 remains incomplete; no GMP compile was requested because no production/test sources changed. No runtime test, benchmark, TB497, or successor executed.
