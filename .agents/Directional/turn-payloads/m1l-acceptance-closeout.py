from pathlib import Path


def replace_section(path: str, start: str, end: str, replacement: str) -> None:
    p = Path(path)
    text = p.read_text()
    a = text.index(start)
    b = text.index(end, a)
    p.write_text(text[:a] + replacement + text[b:])


def replace_once(path: str, old: str, new: str) -> None:
    p = Path(path)
    text = p.read_text()
    count = text.count(old)
    if count != 1:
        raise SystemExit(f"{path}: expected one match, got {count}: {old[:100]!r}")
    p.write_text(text.replace(old, new, 1))


# CHANGELOG: move the complete M1l pending record to a completed immutable entry.
changelog = Path('.agents/Directional/CHANGELOG.md')
text = changelog.read_text()
a = text.index('## [Unreleased]\n')
b = text.index('## [M1k] Phase-Front Edge Topology-Region Consumer — Immutable accepted\n', a)
m1l_entry = '''## [Unreleased]\n\nNo completed changes are currently recorded here. The active M1m Code + Build instructions remain in the handoff.\n\n## [M1l] Phase-Front Cell Topology-Region Consumer — Immutable accepted\n\n### Changed\n\n- Migrated persistent `SurfacePhaseFrontCell::sourceTopologyRegion` from raw `int` to checked optional `TopologyRegionId` at `SurfaceTopologyRegion::id / normalize_scope -> SurfacePhaseFrontCell::sourceTopologyRegion -> still-raw materializer compatibility consumers`.\n- Cell/edge topology-region agreement is direct typed equality; raw materializer, occurrence, hashing, map-key, and compatibility schemas receive legacy integers only through named typed-to-legacy boundaries.\n- Topology-region discovery/partition/numbering, `SurfaceTopologyRegion::id`, raw face-to-region maps, certificate/periodic/bounded-disk/occurrence/lineage schemas, accepted component/sheet and edge-region authority, M2-M6, fallback/recovery, optimization, and G4 behavior remained outside M1l.\n- Final semantic product/test delta was limited to `include/directional/geometry/SurfaceCellTracing.h`, `src/geometry/SurfaceCellTracing.cpp`, `src/pipeline/RemeshPipeline.cpp`, `tests/SurfaceCellsPhase10Tests.cpp`, and compile-driven `tests/SurfaceCellTransitionQuotientTests.cpp`.\n\n### Validation\n\n- Implementation: `bd140cff4572412e6f4ecd70a6ce0fe85310932c`; semantic source base `d5a97953416196a8fc74c8d9790a1ae7b646ca2d`.\n- Authoritative Code + Build run/job `31441661026 / 93627457924` completed Release/static/Ninja/PRE_TEST **121/121** in **8:38.45**, peak RSS **1,860,672 KiB**, with every generated-runtime/test/benchmark/discovery/ctest/CLI/fuzzer/custom-input flag false.\n- Code + Build result artifact `9083262395`, ZIP SHA-256 `3d79b86dbda5e87134aef79330d02c227e0c1ba1f291f24bff6a3946c1aa895c`; build-log artifact `9083262833`, ZIP SHA-256 `a638cf52e9761ddead175aa32aa6824703c98c4553f97c0627e81baa82b3f1b8`.\n- Recursive manifest **56/56**, SHA-256 `be8ec12bab5fc7cc76e6a36d2f833c76330593dada820a3b0c72c0e60fff0454`; package has 57 regular files including `SHA256SUMS`, seven executables, two static libraries, 27 fixtures including 21 milestone-G fixtures, zero symlinks; producer SHA-256 `fe7da9a182c785ae14ba24264682470cce7ceec119ce34251a4bee80c7113856`.\n- Authoritative immutable runtime run/job: `31444022339 / 93634344918`. Runtime evidence artifact `9083913766`, ZIP SHA-256 `64ad28a3334dd3e73346a221e619873dbbc523e879cb31dda0843caa0214cccd`; runtime log artifact `9083913939`, ZIP SHA-256 `a4f9188b19fb9d21d6f7af39b54f9409cb7c3109669d3fddb0fb62fc999ea917`.\n- Producer discovery **226**; M1l focused **6/6** individually; M1k-M1b focused preservation all green; M1d route counterexamples **3/3**; M1c transition counterexamples **3/3**; required-green producer **211/211**; validation **77/77**; M1a **14/14**; T1 **29/29**.\n- Plane, MultiFaceSeam, CloseSheets, and Cylinder remained independent-oracle clean; remote elapsed times were **1.35 / 2.03 / 16.36 / 8.82 s** respectively.\n- All eight historical/deferred red classifications remained unchanged. Exact immutable postflight preserved all **56/56** package checksums and zero symlinks.\n\n### Known limitations\n\n- Strict-validator timing sampled **10/10 pass** in fresh processes but remains the existing nondeterministic sub-millisecond ratio/microbenchmark defect because accepted historical samples vary materially.\n- Bunny preserved `NotProductionReady:completion traceSegments=170831 arrangementCells=0 completedQuads=0`; authoritative remote elapsed time was **78.06 s**.\n- Vase selected one test, reached `[ RUN ]`, and remained bounded safety-only at **60 seconds** with exit code 124.\n- `PR8-R034 / G4-R007` remains active; G4 is unchanged.\n\n### Operational notes\n\n- First compile run/job `31440241452 / 93623230585` found one existing compatibility assertion still comparing integer zero directly with the typed optional cell region. The correction was limited to the named legacy helper; no generated runtime executed and no stable product regression was assigned.\n- A corrected **121/121** compile run/job `31440985022 / 93625446238` then failed only during package provenance because the shallow checkout lacked semantic base `d5a979...`; log artifact `9083016010`, SHA-256 `946490f115398519aa2b3e5bcb9955eb12775ea496ca4c426bcf6be06a1c9991`. The final workflow fetched that exact base before producing the semantic diff.\n- One local first-process Cylinder stall during corroborating artifact execution did not reproduce in the immediate bounded local retry or the authoritative remote run. It remains an execution-plane/harness transient; no product workaround was added.\n- No stable product regression event or recurrence was created. Historical totals remain **34 events / 14 categories / 20 recurrences**.\n\nAuthoritative report: `.agents/Directional/Architecture_M1l_Phase_Front_Cell_Topology_Region_Consumer_Artifact_Only_Test_Benchmark_Report.md`.\n\n'''
changelog.write_text(text[:a] + m1l_entry + text[b:])

# TODO: current focus and architecture status only.
replace_section(
    'TODO.md',
    '## Current focus\n',
    '## Product roadmap\n',
    '''## Current focus\n\n- [ ] **M1m — Isolation-Seam Certificate Topology-Region Consumer: Code + Build only.**\n  - Authoritative plan: `.agents/Directional/Architecture_M1m_Isolation_Seam_Certificate_Topology_Region_Consumer_Code_Build_Plan.md`.\n  - Bounded seam: `SurfaceTopologyRegion::id / build_isolation_seam_transport_certificates -> SurfaceIsolationSeamTransportCertificate::sourceTopologyRegion -> still-raw materializer/hash compatibility consumers`.\n  - Migrate only certificate-owned topology-region identity to checked `TopologyRegionId`; preserve global topology-region construction/schema, accepted cell/edge region authority, all other raw compatibility schemas, M2-M6, fallback/recovery, optimization, and G4 behavior.\n- [x] **M1l — Phase-Front Cell Topology-Region Consumer: immutable accepted.**\n  - Implementation `bd140cff4572412e6f4ecd70a6ce0fe85310932c`; Code + Build artifacts `9083262395 / 9083262833`; immutable runtime `31444022339 / 93634344918`, evidence/log artifacts `9083913766 / 9083913939`.\n  - Producer **226**, M1l **6/6**, required-green **211/211**, full entering preservation/direct-product authority, unchanged known-red classes, and exact **56/56** postflight.\n- [ ] After a successful M1m Code + Build artifact is produced, run the separate immutable **Artifact-Only Test + Benchmark** turn before selecting another architecture consumer.\n- [ ] Continue later bounded M1 consumers only after M1m immutable acceptance.\n\nCurrent baseline: T1 and M1a-M1l are immutable accepted. Product gate G4 remains active and independent of architecture-migration acceptance. Draft PR #8 remains open and unmerged.\n\n''')
replace_once(
    'TODO.md',
    '  - [ ] M1l phase-front cell topology-region consumer — Code + Build complete; immutable runtime pending.\n  - [ ] Select and migrate later bounded M1 consumers one semantic owner at a time until raw compatibility authority no longer drives semantic decisions.\n',
    '  - [x] M1l phase-front cell topology-region consumer.\n  - [ ] M1m isolation-seam certificate topology-region consumer.\n  - [ ] Select and migrate later bounded M1 consumers one semantic owner at a time until raw compatibility authority no longer drives semantic decisions.\n')

# Reorientation: status diagram and current checkpoint/next selection.
replace_once(
    '.agents/Directional/REORIENTATION_PLAN.md',
    '   M1l phase-front cell topology-region consumer [Code + Build complete; immutable runtime pending]\n   later bounded M1 consumers [pending]\n',
    '   M1l phase-front cell topology-region consumer [accepted]\n   M1m isolation-seam certificate topology-region consumer [selected; Code + Build next]\n   later bounded M1 consumers [pending]\n')
replace_section(
    '.agents/Directional/REORIENTATION_PLAN.md',
    'Accepted-source inspection selected M1l at `SurfaceTopologyRegion::id / normalize_scope -> SurfacePhaseFrontCell::sourceTopologyRegion -> still-raw materializer compatibility consumers`.',
    '## 4. M1e accepted boundary and M1f selection\n',
    '''M1l implementation `bd140cff4572412e6f4ecd70a6ce0fe85310932c` is immutable accepted at `SurfaceTopologyRegion::id / normalize_scope -> SurfacePhaseFrontCell::sourceTopologyRegion -> still-raw materializer compatibility consumers`. Exact runtime authority is run/job `31444022339 / 93634344918` from Code + Build artifacts `9083262395 / 9083262833`: producer **226**, M1l **6/6**, required-green **211/211**, validation **77/77**, M1a **14/14**, T1 **29/29**, M1k-M1b preservation green, four direct products independent-oracle clean, eight historical/deferred red classes unchanged, Bunny/Vase dispositions preserved, strict timing truthfully sampled **10/10** while remaining deferred, and exact **56/56** postflight. No new stable product regression or recurrence was created.\n\nAccepted-source inspection now selects M1m at `SurfaceTopologyRegion::id / build_isolation_seam_transport_certificates -> SurfaceIsolationSeamTransportCertificate::sourceTopologyRegion -> still-raw materializer/hash compatibility consumers`. M1m migrates only certificate-owned topology-region authority to checked `TopologyRegionId`; global region construction/schema, periodic/bounded-disk/occurrence/lineage region schemas, and G4 behavior remain outside the slice.\n\nCurrent immutable report:\n`.agents/Directional/Architecture_M1l_Phase_Front_Cell_Topology_Region_Consumer_Artifact_Only_Test_Benchmark_Report.md`.\n\nAuthoritative next Code + Build plan:\n`.agents/Directional/Architecture_M1m_Isolation_Seam_Certificate_Topology_Region_Consumer_Code_Build_Plan.md`.\n\n''')

# Regression tracker: status corrections and next bounded pattern.
tracker = '.agents/Directional/Regression_Root_Cause_Tracker.md'
replace_once(
    tracker,
    'Last updated: **2026-08-10 UTC** after M1l cell topology-region Code + Build completion from artifacts `9083262395 / 9083262833`; M1l immutable semantic runtime is next. M1a-M1k remain accepted.\n',
    'Last updated: **2026-08-10 UTC** after immutable M1l cell topology-region acceptance from Code + Build artifacts `9083262395 / 9083262833` and runtime evidence `9083913766`; M1m isolation-seam certificate topology-region authority is next.\n')
replace_once(
    tracker,
    'The local extraction/harness anomalies and first remote evidence-upload-path failure are infrastructure only. No stable product regression event or recurrence is added.\n\n| Cause category',
    'The local extraction/harness anomalies and first remote evidence-upload-path failure are infrastructure only. No stable product regression event or recurrence is added. M1l implementation `bd140cff4572412e6f4ecd70a6ce0fe85310932c` is immutable accepted from artifact `9083262395` and runtime evidence `9083913766`: producer **226**, focused **6/6**, required-green **211/211**, full M1k-M1b/validation/M1a/T1/direct-product preservation, all eight historical/deferred red classes unchanged, strict timing truthfully sampled **10/10** while remaining deferred, Bunny/Vase dispositions preserved, and exact **56/56** postflight. The local first-process Cylinder stall did not reproduce remotely and is execution-plane only. No stable product regression event or recurrence is added.\n\n| Cause category')
replace_once(
    tracker,
    '- M1h phase-front field charts cross checked `FieldChartId` boundaries before constructive-front semantic use and are **immutable accepted**. M1i cell-owned source component/sheet state through checked `SourceComponentId` / `IsolationSheetId` is **immutable accepted**. M1j immediately adjacent `SurfaceFrontEdge` component/sheet authority is **immutable accepted**. M1k edge-owned topology-region identity is **immutable accepted**. M1l implementation `bd140cff4572412e6f4ecd70a6ce0fe85310932c` removes the remaining raw cell-owned topology-region mirror and compiles/package successfully, but remains runtime pending until artifact-only semantic acceptance.\n',
    '- M1h phase-front field charts cross checked `FieldChartId` boundaries before constructive-front semantic use and are **immutable accepted**. M1i cell-owned source component/sheet state through checked `SourceComponentId` / `IsolationSheetId` is **immutable accepted**. M1j immediately adjacent `SurfaceFrontEdge` component/sheet authority is **immutable accepted**. M1k edge-owned topology-region identity and M1l cell-owned topology-region identity are **immutable accepted** as checked `TopologyRegionId`. M1m next migrates `SurfaceIsolationSeamTransportCertificate::sourceTopologyRegion` so certificate ownership cannot remain a raw semantic integer.\n')
replace_once(
    tracker,
    'M1j edge source-scope migration is immutable accepted: producer discovery **214**, M1j **6/6**, required-green **199/199**, M1i-M1b preservation, validation **77/77**, M1a **14/14**, T1 **29/29**, four direct products independent-oracle clean, all eight historical/deferred red classes unchanged, strict timing **0/10**, Bunny known-red, Vase bounded safety-only, and exact **67/67** postflight. The initial compile mismatch and superseded incomplete-manifest artifact remain Code + Build/orchestration defects only. M1k preserves `RP-02 / TA-05`: producer **220**, M1k **6/6**, required-green **205/205**, validation **77/77**, M1a **14/14**, T1 **29/29**, four direct products oracle-clean, known-red classes unchanged, and exact postflight. M1l Code + Build compiled/package successfully for six new production-path contracts, but no generated runtime executed; `RP-01 / RP-05 / RP-09` and `RP-02 / TA-05` remain runtime pending at M1l. No new stable regression event or recurrence is assigned. Historical totals remain **34 / 14 / 20**.\n',
    'M1j edge source-scope migration is immutable accepted: producer discovery **214**, M1j **6/6**, required-green **199/199**, M1i-M1b preservation, validation **77/77**, M1a **14/14**, T1 **29/29**, four direct products independent-oracle clean, all eight historical/deferred red classes unchanged, strict timing **0/10**, Bunny known-red, Vase bounded safety-only, and exact **67/67** postflight. The initial compile mismatch and superseded incomplete-manifest artifact remain Code + Build/orchestration defects only. M1k preserves `RP-02 / TA-05`: producer **220**, M1k **6/6**, required-green **205/205**, validation **77/77**, M1a **14/14**, T1 **29/29**, four direct products oracle-clean, known-red classes unchanged, and exact postflight. M1l now preserves and extends that authority: producer **226**, M1l **6/6**, required-green **211/211**, all M1k-M1b focused authority, validation **77/77**, M1a **14/14**, T1 **29/29**, four direct products oracle-clean, all eight known-red classes unchanged, Bunny/Vase preserved, and exact **56/56** postflight. `RP-01 / RP-05 / RP-09` and `RP-02 / TA-05` are accepted at M1l. M1m must preserve the same authority while adding six production-path contracts for checked certificate topology-region ownership. No new stable regression event or recurrence is assigned. Historical totals remain **34 / 14 / 20**.\n')
replace_once(
    tracker,
    'M1k is immutable accepted at the adjacent edge topology-region seam. M1l now removes the raw cell-region mirror so cell/edge ownership can agree as `TopologyRegionId` while still-raw materializer/occurrence schemas remain explicit compatibility boundaries. This is the next bounded `RP-01 / RP-05 / RP-09` consumer and does not migrate global topology planning.\n',
    'M1k is immutable accepted at the adjacent edge topology-region seam, and M1l is immutable accepted after removing the raw cell-region mirror so cell/edge ownership agrees as `TopologyRegionId` while still-raw materializer/occurrence schemas remain explicit compatibility boundaries. M1m next migrates the producer-published isolation-seam certificate region owner, while the materializer remains a verifier and raw map/hash representations stay explicit compatibility boundaries. Global topology planning remains outside M1m.\n')
replace_section(
    tracker,
    '## Architecture enforcement register\n',
    '## Test architecture register\n',
    '''## Architecture enforcement register\n\n| ID | State |\n|---|---|\n| `AR-01` | M2: closed producer outcomes |\n| `AR-02` | M1a through M1l **accepted**; M1m isolation-seam certificate topology-region consumer next |\n| `AR-03` | strong identity adoption through M1l **accepted**; M1m checked certificate topology-region identity next |\n| `AR-04` | `FieldChartId` production phase-front chart migration accepted; current M1m concerns certificate-owned `TopologyRegionId` |\n| `AR-05` | representation boundaries through M1l **accepted**; M1m certificate hash/materializer raw representation boundary next |\n| `AR-06` | M4 relation registry/certificates; M1m changes only certificate region ID representation, not relation semantics |\n| `AR-07` | M3 global conformity |\n| `AR-08` | M2/M3 producer-scoped immutable output |\n| `AR-09` | tagged source-support representation exists; exact production rebinding remains M5 |\n| `AR-10` | incremental responsibility modules |\n| `AR-11` | normative architecture/status separation maintained |\n| `AR-12` | T1 independent oracle/package accepted; T2–T6 expand authority |\n\n''')
replace_once(tracker, '| `TA-05` | **test authority resolved and preserved through M1k** |', '| `TA-05` | **test authority resolved and preserved through M1l** |')
replace_once(
    tracker,
    '| `TA-08` | M1a route algebra + M1c edge transport + M1d route identity + M1e segment-route + M1f continuation-route + M1g periodic-route + M1h field-chart + M1i/M1j source-scope + M1k edge topology-region authority accepted; six M1l cell topology-region contracts compiled and await artifact-only runtime |',
    '| `TA-08` | M1a route algebra + M1c edge transport + M1d route identity + M1e segment-route + M1f continuation-route + M1g periodic-route + M1h field-chart + M1i/M1j source-scope + M1k edge topology-region + M1l cell topology-region authority accepted; M1m certificate topology-region contracts next |')
replace_section(
    tracker,
    '## Authoritative next step\n',
    '',
    '') if False else None
# Replace the terminal next-step block without relying on an empty end marker.
p = Path(tracker)
t = p.read_text()
marker = '## Authoritative next step\n'
pos = t.index(marker)
t = t[:pos] + '''## Authoritative next step\n\n`.agents/Directional/Architecture_M1m_Isolation_Seam_Certificate_Topology_Region_Consumer_Code_Build_Plan.md`.\n\nThe next turn is **Code + Build only**. Migrate only `SurfaceIsolationSeamTransportCertificate::sourceTopologyRegion` to checked optional `TopologyRegionId`, preserve certificate transport semantics and all raw global/materializer compatibility schemas, compile/package exactly six M1m production-path contracts, and execute no generated Directional binary. Expected following immutable runtime authority is producer **232**, M1m **6/6**, required-green **217/217**, plus all entering M1l-M1b preservation/product/known-red/postflight gates.\n'''
p.write_text(t)

# Handoff: change only current next-turn/current-authority/resume state sections; retain durable policy verbatim.
handoff = '.agents/Directional/Future_Chat_Session_Handoff.md'
replace_section(
    handoff,
    '## Mandatory next turn\n',
    '## Current immutable authority\n',
    '''## Mandatory next turn\n\nRun **M1m Isolation-Seam Certificate Topology-Region Consumer — Code + Build only** under:\n\n`.agents/Directional/Architecture_M1m_Isolation_Seam_Certificate_Topology_Region_Consumer_Code_Build_Plan.md`\n\nRepository: `akashskypatel/Directional`, branch `agent/surface_cell_quad/p5-recover-bridge-healing`. Draft PR #8 stays open, draft, and unmerged. Product gate **G4 topology-distinct completion and singularities** remains active. Architecture slices M1a through M1l are immutable accepted. Review policy is `never`.\n\nM1m is bounded to:\n\n`SurfaceTopologyRegion::id / build_isolation_seam_transport_certificates -> SurfaceIsolationSeamTransportCertificate::sourceTopologyRegion -> still-raw materializer/hash compatibility consumers`.\n\nMigrate only certificate-owned topology-region identity to checked `TopologyRegionId`. Preserve `SurfaceTopologyRegion::id`, raw region-by-face maps, periodic/bounded-disk/occurrence/lineage region schemas, topology-region construction/numbering, accepted cell/edge region authority, certificate transport semantics, M2-M6, fallback/recovery, optimization, and G4 behavior.\n\nThis is **Code + Build only**. Execute no generated Directional binary, GoogleTest discovery/list command, test, benchmark, `ctest`, CLI/GUI/help/version command, fuzzer, or custom input. Exactly six M1m production-path contracts compile only. Expected following runtime authority is producer **232**, M1m **6/6**, required-green **217/217**, plus all entering preservation gates.\n\nCurrent immutable report:\n`.agents/Directional/Architecture_M1l_Phase_Front_Cell_Topology_Region_Consumer_Artifact_Only_Test_Benchmark_Report.md`.\n\nAuthoritative next plan:\n`.agents/Directional/Architecture_M1m_Isolation_Seam_Certificate_Topology_Region_Consumer_Code_Build_Plan.md`.\n\n''')
replace_section(
    handoff,
    '## Current immutable authority\n',
    '## Mandatory end-of-turn checklist\n',
    '''## Current immutable authority\n\nM1l implementation `bd140cff4572412e6f4ecd70a6ce0fe85310932c` is immutable accepted from Code + Build artifacts `9083262395 / 9083262833` and artifact-only runtime `31444022339 / 93634344918`, with runtime evidence/log artifacts `9083913766 / 9083913939`. Producer authority is **226** discovered, M1l **6/6**, required-green **211/211**, all M1k-M1b focused preservation green, M1d/M1c counterexamples **3/3 + 3/3**, validation **77/77**, M1a **14/14**, T1 **29/29**, and Plane/MultiFaceSeam/CloseSheets/Cylinder independent-oracle clean. All eight historical/deferred red classifications and exact **56/56** postflight were preserved.\n\nStrict-validator timing sampled **10/10 pass** but remains the existing nondeterministic sub-millisecond ratio/microbenchmark defect. Bunny remains `NotProductionReady:completion traceSegments=170831 arrangementCells=0 completedQuads=0`; Vase remains bounded safety-only at 60 seconds. No stable product regression event or recurrence was created; historical totals remain **34 events / 14 categories / 20 recurrences**, and `PR8-R034 / G4-R007` remains active.\n\nRepository-side per-turn retention is clean after closeout: retain the M1l immutable Test + Benchmark report and the single M1m next-turn plan in addition to durable documents. The consumed M1l Code + Build report and artifact-only plan are superseded once their necessary facts are preserved in the retained report/changelog/tracker.\n\n''')
replace_once(handoff, '- M1a through M1k architecture acceptance does not claim G4 product completion.\n', '- M1a through M1l architecture acceptance does not claim G4 product completion.\n')
replace_section(
    handoff,
    '## Resume-critical execution lessons\n',
    '## Core references\n',
    '''## Resume-critical execution lessons\n\n- Use exact accepted M1l implementation/package/runtime authority above; later documentation/control-plane commits are not runtime-evidence commits.\n- One local first-process Cylinder stall did not reproduce in the immediate bounded local retry or authoritative remote artifact-only run. Do not add a product workaround without new product evidence.\n- M1m existing wrong-owner certificate coverage must preserve semantic intent after typing: use a genuinely distinct checked topology-region witness when needed rather than manufacturing an ID with a knowingly false extent. Detailed requirements are in the M1m plan.\n\nWorkflow-specific execution rules and lessons are maintained in `.agents/Directional/GitHub_Workflow_Policy.md`.\n\n''')
# Replace core references to current report/next plan while preserving policy/design set.
p = Path(handoff)
t = p.read_text()
t = t.replace('- `.agents/Directional/Architecture_M1l_Phase_Front_Cell_Topology_Region_Consumer_Code_Build_Report.md`;\n- `.agents/Directional/Architecture_M1l_Phase_Front_Cell_Topology_Region_Consumer_Artifact_Only_Test_Benchmark_Plan.md`;\n', '- `.agents/Directional/Architecture_M1l_Phase_Front_Cell_Topology_Region_Consumer_Artifact_Only_Test_Benchmark_Report.md`;\n- `.agents/Directional/Architecture_M1m_Isolation_Seam_Certificate_Topology_Region_Consumer_Code_Build_Plan.md`;\n')
p.write_text(t)

# Sanity checks: next/current references must exist in resulting documents.
for path, required in {
    'TODO.md': ['M1m', 'M1l — Phase-Front Cell Topology-Region Consumer: immutable accepted'],
    '.agents/Directional/REORIENTATION_PLAN.md': ['M1l phase-front cell topology-region consumer [accepted]', 'M1m isolation-seam certificate topology-region consumer [selected; Code + Build next]'],
    tracker: ['M1a through M1l **accepted**', 'Architecture_M1m_Isolation_Seam_Certificate_Topology_Region_Consumer_Code_Build_Plan.md'],
    handoff: ['Run **M1m Isolation-Seam Certificate Topology-Region Consumer — Code + Build only**', 'M1l implementation `bd140cff4572412e6f4ecd70a6ce0fe85310932c` is immutable accepted'],
    '.agents/Directional/CHANGELOG.md': ['## [M1l] Phase-Front Cell Topology-Region Consumer — Immutable accepted', '9083913766'],
}.items():
    content = Path(path).read_text()
    for needle in required:
        if needle not in content:
            raise SystemExit(f'{path}: missing required postcondition {needle!r}')

print('m1l-closeout-docs=prepared')
