# `M6-CP1-CB12-CLOSE` — Code + Build stop report

**Disposition:** STOP FOR REVIEW before implementation or compile/package.

C5 found an **anchor-assuming** optimizer consumer, an explicit stop condition in the CB12 plan / RA-25. No C1-C4 production/test edits were started; no build or runtime was executed.

## Source authority
- Snapshot run/artifact: `37247854766 / 11319199706`.
- Exact SHA: `29085d063718fa17dffee5581410dbd53c9ed30f`.
- Archive SHA-256: `da68d35cabc3c1c5d8e860f1a8fff9305819feeebe4c6895fe7b09c2f3b84a85`.
- 5,355 files; `runtimeExecution=false`; archive checksum verified locally.

## C5 audit
- `project_surface_cell_vertex_chart_authority`: **class-wide** (`RemeshPipeline.cpp:8061-8127`).
- Final validator face-chart resolution: **class-wide** (`SourceAuthoritativeMeshValidator.cpp:620-710,1232-1260`); `:1166-1183` face use is representation-only.
- Optimizer source-face sampling `:2576`: **representation-only** (`SurfaceMeshOptimizer.cpp:2572-2595`).
- Optimizer source-vertex rebinding `:3020`: **anchor-assuming — BLOCKER**. `SurfaceMeshOptimizer.cpp:3015-3031` takes the first incident face, derives `source_face_scope`, then breaks. `SurfaceMeshOptimizer.h:344-360` maps that one row to one component/sheet, so multi-chart/sheet vertices are face-row/order dependent.
- `BenchmarkQuality.cpp:1478-1504`: **representation-only**.

RA-22b says any anchor-assuming consumer blocks CP1 closure. RA-25/CB12 require immediate Review and forbid repairing it inside CB12. C1-C4, identities 29/30, focused-30, compile/package, and TB12 were therefore not started.

Reviewed runtime remains `11316716869 / 8dd958217d8cbda2d403f7a5c4c7dce242dde1c0`, 477/477. Stable accounting remains **60 / 16 / 44**, debt **1**. No successor ID is frozen; Review must define bounded correction/routing.
