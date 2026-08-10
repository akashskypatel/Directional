from pathlib import Path


def replace_once(path: str, old: str, new: str) -> None:
    p = Path(path)
    text = p.read_text(encoding="utf-8")
    count = text.count(old)
    if count != 1:
        raise SystemExit(f"{path}: expected one match, found {count}")
    p.write_text(text.replace(old, new, 1), encoding="utf-8")


replace_once(
    "TODO.md",
    """- [ ] **M1l — Phase-Front Cell Topology-Region Consumer: Code + Build only.**
  - Authoritative plan: `.agents/Directional/Architecture_M1l_Phase_Front_Cell_Topology_Region_Consumer_Code_Build_Plan.md`.
  - Bounded seam: `SurfaceTopologyRegion::id / normalize_scope -> SurfacePhaseFrontCell::sourceTopologyRegion -> still-raw materializer compatibility consumers`.
  - Migrate only cell-owned topology-region identity to checked `TopologyRegionId`; preserve global topology-region construction/schema, accepted source-scope and edge-region authority, M2-M6, fallback/recovery, optimization, and G4 behavior.
- [ ] After a successful M1l Code + Build artifact is produced, run the separate immutable **Artifact-Only Test + Benchmark** turn before selecting another architecture consumer.
- [ ] Continue later bounded M1 consumers only after M1l immutable acceptance.
""",
    """- [ ] **M1l — Phase-Front Cell Topology-Region Consumer: immutable Artifact-Only Test + Benchmark next.**
  - Code + Build is complete for implementation `bd140cff4572412e6f4ecd70a6ce0fe85310932c`; semantic acceptance remains pending.
  - Authoritative validation plan: `.agents/Directional/Architecture_M1l_Phase_Front_Cell_Topology_Region_Consumer_Artifact_Only_Test_Benchmark_Plan.md`.
  - Bounded seam: `SurfaceTopologyRegion::id / normalize_scope -> SurfacePhaseFrontCell::sourceTopologyRegion -> still-raw materializer compatibility consumers`.
  - Migrate only cell-owned topology-region identity to checked `TopologyRegionId`; preserve global topology-region construction/schema, accepted source-scope and edge-region authority, M2-M6, fallback/recovery, optimization, and G4 behavior.
- [x] Produce the immutable M1l Code + Build package without generated runtime execution.
- [ ] Validate exact artifacts `9083262395 / 9083262833` in the separate immutable **Artifact-Only Test + Benchmark** turn before selecting another architecture consumer.
- [ ] Continue later bounded M1 consumers only after M1l immutable acceptance.
""",
)
replace_once(
    "TODO.md",
    "  - [ ] M1l phase-front cell topology-region consumer.\n",
    "  - [ ] M1l phase-front cell topology-region consumer — Code + Build complete; immutable runtime pending.\n",
)

replace_once(
    ".agents/Directional/CHANGELOG.md",
    """## [Unreleased]

No completed changes are currently recorded here. The active M1l Code + Build instructions remain in the handoff until that turn is complete.
""",
    """## [Unreleased]

### Changed

- M1l migrated persistent `SurfacePhaseFrontCell::sourceTopologyRegion` from raw `int` to checked optional `TopologyRegionId` at `SurfaceTopologyRegion::id / normalize_scope -> SurfacePhaseFrontCell::sourceTopologyRegion -> still-raw materializer compatibility consumers`.
- Cell/edge topology-region agreement is now direct typed equality; raw materializer, occurrence, hashing, map-key, and compatibility schemas receive legacy integers only through named typed-to-legacy boundaries.
- Topology-region discovery/partition/numbering, `SurfaceTopologyRegion::id`, raw face-to-region maps, certificate/periodic/bounded-disk/occurrence/lineage schemas, accepted component/sheet and edge-region authority, M2-M6, fallback/recovery, optimization, and G4 behavior remain outside M1l.
- Final semantic product/test delta is limited to `include/directional/geometry/SurfaceCellTracing.h`, `src/geometry/SurfaceCellTracing.cpp`, `src/pipeline/RemeshPipeline.cpp`, `tests/SurfaceCellsPhase10Tests.cpp`, and compile-driven `tests/SurfaceCellTransitionQuotientTests.cpp`.

### Validation

- M1l implementation: `bd140cff4572412e6f4ecd70a6ce0fe85310932c`; semantic source base `d5a97953416196a8fc74c8d9790a1ae7b646ca2d`.
- Authoritative Code + Build run/job `31441661026 / 93627457924` completed Release/static/Ninja/PRE_TEST **121/121** in **8:38.45**, peak RSS **1,860,672 KiB**, with every generated-runtime/test/benchmark/discovery/ctest/CLI/fuzzer/custom-input flag false.
- Result artifact `9083262395`, ZIP SHA-256 `3d79b86dbda5e87134aef79330d02c227e0c1ba1f291f24bff6a3946c1aa895c`; log artifact `9083262833`, ZIP SHA-256 `a638cf52e9761ddead175aa32aa6824703c98c4553f97c0627e81baa82b3f1b8`.
- Recursive manifest **56/56**, SHA-256 `be8ec12bab5fc7cc76e6a36d2f833c76330593dada820a3b0c72c0e60fff0454`; package has 57 regular files including `SHA256SUMS`, seven executables, two static libraries, 27 fixtures including 21 milestone-G fixtures; producer SHA-256 `fe7da9a182c785ae14ba24264682470cce7ceec119ce34251a4bee80c7113856`.
- Exactly six `SurfaceCellPhaseFrontCellTopologyRegionAuthorityMigration` contracts compiled but were not discovered, listed, or executed. M1l remains **runtime pending**; M1a-M1k remain the current immutable semantic authority.

### Operational notes

- First compile run/job `31440241452 / 93623230585` found one existing compatibility assertion still comparing integer zero directly with the typed optional cell region. The correction was limited to the named legacy helper; no generated runtime executed and no stable product regression was assigned.
- A corrected **121/121** compile run/job `31440985022 / 93625446238` then failed only during package provenance because the shallow checkout lacked semantic base `d5a979...`; log artifact `9083016010`, SHA-256 `946490f115398519aa2b3e5bcb9955eb12775ea496ca4c426bcf6be06a1c9991`. The final workflow fetched that exact base before producing the semantic diff.
- Historical regression totals remain **34 events / 14 categories / 20 recurrences**; `PR8-R034 / G4-R007` remains active.

Current Code + Build authority: `.agents/Directional/Architecture_M1l_Phase_Front_Cell_Topology_Region_Consumer_Code_Build_Report.md`. The mandatory next turn is immutable artifact-only validation under `.agents/Directional/Architecture_M1l_Phase_Front_Cell_Topology_Region_Consumer_Artifact_Only_Test_Benchmark_Plan.md`.
""",
)
replace_once(
    ".agents/Directional/CHANGELOG.md",
    "Authoritative report retained as current immutable authority: `.agents/Directional/Architecture_M1k_Phase_Front_Edge_Topology_Region_Consumer_Artifact_Only_Test_Benchmark_Report.md`.\n",
    "The former M1k per-turn report was retired under `CLEAN_UP_POLICY.md` after its durable acceptance facts were consolidated here, in the regression tracker, and in immutable GitHub artifact history.\n",
)

replace_once(
    ".agents/Directional/Future_Chat_Session_Handoff.md",
    """## Mandatory next turn

Run **M1l Phase-Front Cell Topology-Region Consumer — Code + Build only** under:

`.agents/Directional/Architecture_M1l_Phase_Front_Cell_Topology_Region_Consumer_Code_Build_Plan.md`

Repository: `akashskypatel/Directional`, branch `agent/surface_cell_quad/p5-recover-bridge-healing`. Draft PR #8 stays open, draft, and unmerged. Product gate **G4 topology-distinct completion and singularities** remains active. Architecture slices M1a through M1k are immutable accepted. Review policy is `never`.

M1l is bounded to:

`SurfaceTopologyRegion::id / normalize_scope -> SurfacePhaseFrontCell::sourceTopologyRegion -> still-raw materializer compatibility consumers`.

Migrate only cell-owned topology-region identity to checked `TopologyRegionId`. Preserve `SurfaceTopologyRegion::id`, raw region-by-face maps, certificate/periodic/bounded-disk/occurrence/lineage region schemas, topology-region discovery/partition/numbering, accepted component/sheet and edge-region authority, M2-M6, fallback/recovery, optimization, and G4 behavior.

This is **Code + Build only**. Execute no generated Directional binary, GoogleTest discovery/list command, test, benchmark, `ctest`, CLI/GUI/help/version command, fuzzer, or custom input. Exactly six M1l production-path contracts compile only. Expected following runtime authority is producer **226**, M1l **6/6**, required-green **211/211**, plus all entering preservation gates.

Current immutable report:
`.agents/Directional/Architecture_M1k_Phase_Front_Edge_Topology_Region_Consumer_Artifact_Only_Test_Benchmark_Report.md`.

Authoritative next plan:
`.agents/Directional/Architecture_M1l_Phase_Front_Cell_Topology_Region_Consumer_Code_Build_Plan.md`.
""",
    """## Mandatory next turn

Run **M1l Phase-Front Cell Topology-Region Consumer — immutable Artifact-Only Test + Benchmark only** under:

`.agents/Directional/Architecture_M1l_Phase_Front_Cell_Topology_Region_Consumer_Artifact_Only_Test_Benchmark_Plan.md`

Repository: `akashskypatel/Directional`, branch `agent/surface_cell_quad/p5-recover-bridge-healing`. Draft PR #8 stays open, draft, and unmerged. Product gate **G4 topology-distinct completion and singularities** remains active. Architecture slices M1a through M1k are immutable accepted. Review policy is `never`.

Consume only M1l implementation `bd140cff4572412e6f4ecd70a6ce0fe85310932c` from exact Code + Build artifacts `9083262395 / 9083262833`. Their outer ZIP SHA-256 values are `3d79b86dbda5e87134aef79330d02c227e0c1ba1f291f24bff6a3946c1aa895c / a638cf52e9761ddead175aa32aa6824703c98c4553f97c0627e81baa82b3f1b8`.

This turn is artifact-only: do not edit source/tests/build/fixtures, rebuild, relink, configure, regenerate, substitute/repair package contents, alter executable permissions, or create fixture symlinks. Use the exact plan for preflight, discovery, M1l **6/6**, entering preservation, required-green **211/211**, independent product gates, known-red classification, timing characterization, bounded Bunny/Vase comparison, and exact postflight.

Current Code + Build report:
`.agents/Directional/Architecture_M1l_Phase_Front_Cell_Topology_Region_Consumer_Code_Build_Report.md`.

Authoritative next plan:
`.agents/Directional/Architecture_M1l_Phase_Front_Cell_Topology_Region_Consumer_Artifact_Only_Test_Benchmark_Plan.md`.
""",
)
replace_once(
    ".agents/Directional/Future_Chat_Session_Handoff.md",
    """M1k implementation `b9181364926cea840e9cb50da21fe721f33fd874` is immutable accepted from Code + Build artifacts `9079318682 / 9079319269` and artifact-only runtime `31433794426 / 93603203081`. Producer authority is **220** discovered, M1k **6/6**, required-green **205/205**; the full preservation matrix, product cases, historical/deferred reds, and exact postflight are recorded in the current immutable report.

Strict-validator timing remains the existing nondeterministic sub-millisecond ratio/microbenchmark defect. Bunny remains `NotProductionReady:completion traceSegments=170831 arrangementCells=0 completedQuads=0`; Vase remains bounded safety-only at 60 seconds. No stable product regression event or recurrence was created; historical totals remain **34 events / 14 categories / 20 recurrences**, and `PR8-R034 / G4-R007` remains active.

Repository-side per-turn retention is clean: `.agents/Directional` retains only the current M1k immutable report and the single M1l next-turn plan in addition to durable documents. Superseded M1h–M1j evidence and consumed M1k plans/reports were consolidated into `CHANGELOG.md` before removal under `CLEAN_UP_POLICY.md`.
""",
    """M1k implementation `b9181364926cea840e9cb50da21fe721f33fd874` remains the current immutable semantic authority: producer **220**, M1k **6/6**, required-green **205/205**, full entering preservation, and required representative products accepted. Exact historical acceptance detail is retained in `CHANGELOG.md` and the regression tracker.

Strict-validator timing remains the existing nondeterministic sub-millisecond ratio/microbenchmark defect. Bunny remains `NotProductionReady:completion traceSegments=170831 arrangementCells=0 completedQuads=0`; Vase remains bounded safety-only at 60 seconds. No stable product regression event or recurrence was created; historical totals remain **34 events / 14 categories / 20 recurrences**, and `PR8-R034 / G4-R007` remains active.

M1l Code + Build is complete but **not semantically accepted**. Its current immutable package authority is run/job `31441661026 / 93627457924`, artifacts `9083262395 / 9083262833`, manifest **56/56**, and producer SHA-256 `fe7da9a182c785ae14ba24264682470cce7ceec119ce34251a4bee80c7113856`.
""",
)
replace_once(
    ".agents/Directional/Future_Chat_Session_Handoff.md",
    """- Use the exact accepted M1k source/package authority above; later documentation/control-plane commits are not runtime-evidence commits.
- A single local Cylinder harness stall did not reproduce in immediate bounded local execution or controlled remote runs. Do not add product workarounds for it without new product evidence.
""",
    """- Use exact M1l artifact `9083262395` as the only next-turn runtime package; later documentation/control-plane commits are not runtime-evidence commits.
- The first M1l compile exposed one stale raw test assertion; the corrected code subsequently compiled **121/121**. A later packaging attempt failed only because shallow history omitted the semantic diff base; the authoritative package explicitly fetched that base before manifest creation.
- A single local Cylinder harness stall did not reproduce in immediate bounded local execution or controlled remote runs. Do not add product workarounds for it without new product evidence.
""",
)
replace_once(
    ".agents/Directional/Future_Chat_Session_Handoff.md",
    """- `.agents/Directional/Architecture_M1k_Phase_Front_Edge_Topology_Region_Consumer_Artifact_Only_Test_Benchmark_Report.md`;
- `.agents/Directional/Architecture_M1l_Phase_Front_Cell_Topology_Region_Consumer_Code_Build_Plan.md`;
""",
    """- `.agents/Directional/Architecture_M1l_Phase_Front_Cell_Topology_Region_Consumer_Code_Build_Report.md`;
- `.agents/Directional/Architecture_M1l_Phase_Front_Cell_Topology_Region_Consumer_Artifact_Only_Test_Benchmark_Plan.md`;
""",
)

replace_once(
    ".agents/Directional/REORIENTATION_PLAN.md",
    "   M1l phase-front cell topology-region consumer [selected; Code + Build next]\n",
    "   M1l phase-front cell topology-region consumer [Code + Build complete; immutable runtime pending]\n",
)
replace_once(
    ".agents/Directional/REORIENTATION_PLAN.md",
    """Accepted-source inspection selects M1l at `SurfaceTopologyRegion::id / normalize_scope -> SurfacePhaseFrontCell::sourceTopologyRegion -> still-raw materializer compatibility consumers`. M1l migrates only cell-owned `TopologyRegionId` authority and leaves global region construction/schema migration for later bounded consumers/M2-M4.

Authoritative next Code + Build plan:
`.agents/Directional/Architecture_M1l_Phase_Front_Cell_Topology_Region_Consumer_Code_Build_Plan.md`.
""",
    """Accepted-source inspection selected M1l at `SurfaceTopologyRegion::id / normalize_scope -> SurfacePhaseFrontCell::sourceTopologyRegion -> still-raw materializer compatibility consumers`. Implementation `bd140cff4572412e6f4ecd70a6ce0fe85310932c` now carries cell-owned topology-region authority as checked `TopologyRegionId`, preserves global region construction/schema, and compiled/package successfully without generated runtime execution.

Code + Build authority is run/job `31441661026 / 93627457924`, result/log artifacts `9083262395 / 9083262833`, manifest **56/56**, and producer SHA-256 `fe7da9a182c785ae14ba24264682470cce7ceec119ce34251a4bee80c7113856`. This does not semantically accept M1l; M1a-M1k remain the accepted architecture boundary.

Authoritative next immutable validation plan:
`.agents/Directional/Architecture_M1l_Phase_Front_Cell_Topology_Region_Consumer_Artifact_Only_Test_Benchmark_Plan.md`.
""",
)

replace_once(
    ".agents/Directional/Regression_Root_Cause_Tracker.md",
    "Last updated: **2026-08-10 UTC** after immutable M1k edge topology-region acceptance from artifacts `9079318682 / 9080245848`; M1l cell topology-region authority is next.\n",
    "Last updated: **2026-08-10 UTC** after M1l cell topology-region Code + Build completion from artifacts `9083262395 / 9083262833`; M1l immutable semantic runtime is next. M1a-M1k remain accepted.\n",
)
replace_once(
    ".agents/Directional/Regression_Root_Cause_Tracker.md",
    "M1k edge-owned topology-region identity is **immutable accepted** as checked `TopologyRegionId` without changing topology-region construction. M1l next migrates the remaining raw cell-owned topology-region identity to checked `TopologyRegionId`.",
    "M1k edge-owned topology-region identity is **immutable accepted**. M1l implementation `bd140cff4572412e6f4ecd70a6ce0fe85310932c` removes the remaining raw cell-owned topology-region mirror and compiles/package successfully, but remains runtime pending until artifact-only semantic acceptance.",
)
replace_once(
    ".agents/Directional/Regression_Root_Cause_Tracker.md",
    "M1l must preserve the same authority while adding six production-path contracts for checked cell topology-region authority. Authoritative next Code + Build plan: `.agents/Directional/Architecture_M1l_Phase_Front_Cell_Topology_Region_Consumer_Code_Build_Plan.md`. Historical totals remain **34 / 14 / 20**.",
    "M1l Code + Build compiled/package successfully for six new production-path contracts, but no generated runtime executed; `RP-01 / RP-05 / RP-09` and `RP-02 / TA-05` remain runtime pending at M1l. No new stable regression event or recurrence is assigned. Historical totals remain **34 / 14 / 20**.",
)
replace_once(
    ".agents/Directional/Regression_Root_Cause_Tracker.md",
    "| `AR-02` | M1a through M1k **accepted**; M1l phase-front cell topology-region consumer next |\n| `AR-03` | strong identity adoption through M1k **accepted**; M1l checked cell topology-region identity next |\n| `AR-04` | `FieldChartId` production phase-front chart migration accepted; current M1l concerns `TopologyRegionId` cell authority |\n| `AR-05` | representation boundaries through M1k **accepted**; M1l cell topology-region representation boundary next |",
    "| `AR-02` | M1a through M1k **accepted**; M1l Code + Build complete, immutable runtime pending |\n| `AR-03` | strong identity adoption through M1k **accepted**; M1l checked cell topology-region implementation compiled but is not yet semantically accepted |\n| `AR-04` | `FieldChartId` production phase-front chart migration accepted; current M1l concerns `TopologyRegionId` cell authority |\n| `AR-05` | representation boundaries through M1k **accepted**; M1l cell topology-region representation boundary compiled/runtime pending |",
)
replace_once(
    ".agents/Directional/Regression_Root_Cause_Tracker.md",
    "| `TA-08` | M1a route algebra + M1c edge transport + M1d route identity + M1e segment-route + M1f continuation-route + M1g periodic-route + M1h field-chart + M1i/M1j source-scope + M1k edge topology-region authority accepted; M1l cell topology-region contracts next |",
    "| `TA-08` | M1a route algebra + M1c edge transport + M1d route identity + M1e segment-route + M1f continuation-route + M1g periodic-route + M1h field-chart + M1i/M1j source-scope + M1k edge topology-region authority accepted; six M1l cell topology-region contracts compiled and await artifact-only runtime |",
)
replace_once(
    ".agents/Directional/Regression_Root_Cause_Tracker.md",
    """`.agents/Directional/Architecture_M1l_Phase_Front_Cell_Topology_Region_Consumer_Code_Build_Plan.md`.

The next turn is **Code + Build only**. Migrate only `SurfacePhaseFrontCell::sourceTopologyRegion` at the established phase-front cell topology-region consumer to checked `TopologyRegionId`, keep still-raw downstream materializer/occurrence representations behind explicit compatibility conversions, preserve M1a-M1k and G4 behavior, compile/package the required six focused contracts, and execute no generated Directional binary.
""",
    """`.agents/Directional/Architecture_M1l_Phase_Front_Cell_Topology_Region_Consumer_Artifact_Only_Test_Benchmark_Plan.md`.

The next turn is **immutable Artifact-Only Test + Benchmark only** over exact artifacts `9083262395 / 9083262833`. Expected producer discovery is **226**, M1l focused **6/6**, and required-green **211/211**, with full entering preservation/product/known-red/postflight authority. M1l remains runtime pending until that evidence passes.
""",
)
