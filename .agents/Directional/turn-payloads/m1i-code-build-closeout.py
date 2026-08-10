from pathlib import Path

REPORT = '.agents/Directional/Architecture_M1i_Phase_Front_Cell_Source_Scope_Consumer_Code_Build_Report.md'
RUNTIME_PLAN = '.agents/Directional/Architecture_M1i_Phase_Front_Cell_Source_Scope_Consumer_Artifact_Only_Test_Benchmark_Plan.md'
CODE_PLAN = '.agents/Directional/Architecture_M1i_Phase_Front_Cell_Source_Scope_Consumer_Code_Build_Plan.md'


def replace_once(text, old, new, label):
    count = text.count(old)
    if count != 1:
        raise SystemExit(f'{label}: expected exactly one occurrence, found {count}')
    return text.replace(old, new, 1)


def replace_region(text, start, end, replacement, label):
    a = text.find(start)
    if a < 0:
        raise SystemExit(f'{label}: start marker missing')
    b = text.find(end, a + len(start))
    if b < 0:
        raise SystemExit(f'{label}: end marker missing')
    return text[:a] + replacement + text[b:]

# Handoff: only live front matter.
p = Path('.agents/Directional/Future_Chat_Session_Handoff.md')
s = p.read_text()
front = f'''## Mandatory next turn

Run **M1i Phase-Front Cell Source-Scope Consumer — immutable Artifact-Only Test + Benchmark only** under:

`{RUNTIME_PLAN}`

Repository: `akashskypatel/Directional`, branch `agent/surface_cell_quad/p5-recover-bridge-healing`. Draft PR #8 stays open, draft, and unmerged. Product gate **G4 topology-distinct completion and singularities** remains active. M1a through M1h are immutable accepted. M1i is compile/package complete and runtime pending. Review policy is `never`.

Consume only result/log artifacts `9072101943 / 9072102331` from implementation `b037157921094604f1b0c17f9c8b7076c7604b3b`. Result/log ZIP SHA-256 are `e30860e5ec411dc4dc446d0a4dc65ce6f15c5784a6f5daca138ab44d7196bf25 / 38353b8c101a298d9a537a82da17e075180619343246a6ba4a8e2f430bd14d44`; recursive package manifest is **72/72**, digest `f5614100e1638990d46c7c8fa3d7c720c837dfae1ae515387977d4c0b9e9cac3`.

Rebuild, relink, configure, regeneration, source/test/build/fixture edits, repair, substitution, and runtime fixture symlinks are prohibited. Expected native producer discovery is **208**, M1i focused **6/6** individually, and required-green producer **193/193**. Preserve M1h–M1b focused suites, validation **77/77**, M1a **14/14**, T1 **29/29**, direct Plane/MultiFaceSeam/CloseSheets/Cylinder oracle authority, all eight historical/deferred red classes, strict-validator 10-process characterization, Bunny/Vase bounded comparison, and exact postflight.

## M1i Code + Build authority — runtime pending

Selected seam:
`phase_front_cell_source_scope -> SurfacePhaseFrontCell::{{sourceComponent, sourceSheet, sourceIsolationSheets}}`.

Implementation `b037157921094604f1b0c17f9c8b7076c7604b3b` changes exactly four paths: the tracing header, tracing implementation, pipeline compatibility consumers, and phase-10 tests. `SurfacePhaseFrontCell` now owns optional checked `SourceComponentId`, optional checked `IsolationSheetId`, and a typed sorted isolation-sheet collection. Raw edge/pipeline representations remain explicit compatibility boundaries only. Exactly six `SurfaceCellPhaseFrontCellSourceScopeAuthorityMigration` contracts compile and were **not executed**.

Authoritative build/package run/job `31411770135 / 93531293415` compiled **120/120** Release/static/Ninja/PRE_TEST in **7:39.61**, peak RSS **1,857,412 KiB**. Package is 73 regular files, seven executables, two libraries, 27 fixtures, with **72/72** verified checksums. Every runtime-execution flag is false.

First attempt `31410750675` also compiled **120/120** but failed only in package checksum verification because the manifest was checked from the repository cwd rather than package cwd. The retry made no source delta and records that provenance in the final package. First-attempt log artifact is `9071739970`.

M1i is not semantically accepted until immutable runtime passes. Historical regression totals remain **34 events / 14 categories / 20 recurrences**; `PR8-R034 / G4-R007` remains active.

Current Code + Build report:
`{REPORT}`.

Authoritative next plan:
`{RUNTIME_PLAN}`.

'''
s = replace_region(s, '## Mandatory next turn\n', '## M1h immutable acceptance authority\n', front + '## M1h immutable acceptance authority\n', 'handoff front')
p.write_text(s)

# Reorientation current roadmap/checkpoint only.
p = Path('.agents/Directional/REORIENTATION_PLAN.md')
s = p.read_text()
s = replace_once(s,
    '   M1i phase-front cell source-scope consumer [selected; Code + Build next]',
    '   M1i phase-front cell source-scope consumer [compile/package complete; immutable runtime next]',
    'reorientation M1i state')
old = f'''Fresh accepted-source inspection selects M1i at `phase_front_cell_source_scope -> SurfacePhaseFrontCell::{{sourceComponent, sourceSheet, sourceIsolationSheets}}`. The cell still persists source-component/isolation-sheet identity as raw integers although the authority kernel already defines `SourceComponentId` and `IsolationSheetId`.

Authoritative next Code + Build plan:
`{CODE_PLAN}`.'''
new = f'''M1i implementation `b037157921094604f1b0c17f9c8b7076c7604b3b` is compile/package complete at `phase_front_cell_source_scope -> SurfacePhaseFrontCell::{{sourceComponent, sourceSheet, sourceIsolationSheets}}`. Cell-owned component/sheet identity now crosses checked `SourceComponentId` / `IsolationSheetId` boundaries; neighboring raw representations remain explicit compatibility only.

Authoritative build/package run `31411770135` compiled **120/120** with exact artifacts `9072101943 / 9072102331`, recursive manifest **72/72**, and no generated Directional runtime execution. The first packaging attempt compiled successfully but its checksum verification used the wrong cwd; the corrected retry made no source delta. M1i semantic acceptance remains pending immutable runtime.

Authoritative next Artifact-Only Test + Benchmark plan:
`{RUNTIME_PLAN}`.'''
s = replace_once(s, old, new, 'reorientation checkpoint')
p.write_text(s)

# Regression tracker: compile-only status, no new stable event.
p = Path('.agents/Directional/Regression_Root_Cause_Tracker.md')
s = p.read_text()
s = replace_once(s,
    'Last updated: **2026-08-10 UTC** after immutable M1h acceptance from remediation artifact `9069186973`; M1i cell source-scope authority is next.',
    'Last updated: **2026-08-10 UTC** after M1i cell source-scope Code + Build from artifact `9072101943`; immutable runtime is next.',
    'tracker last updated')
s = replace_once(s,
    'Remediation artifact `9069186973` is now immutable accepted with focused **6/6**, required-green **187/187**, full entering preservation/direct-product authority, unchanged historical-red classes, and exact postflight. No stable product regression event or recurrence is added. `PR8-R034 / G4-R007` remains active.',
    'Remediation artifact `9069186973` is now immutable accepted with focused **6/6**, required-green **187/187**, full entering preservation/direct-product authority, unchanged historical-red classes, and exact postflight. M1i implementation `b037157921094604f1b0c17f9c8b7076c7604b3b` compiled **120/120** and packaged as artifact `9072101943`; no generated runtime executed, so no stable product regression event or recurrence is assigned from M1i compile-only evidence. `PR8-R034 / G4-R007` remains active.',
    'tracker historical status')
s = replace_once(s,
    '- M1h phase-front field charts cross checked `FieldChartId` boundaries before constructive-front semantic use and are **immutable accepted**. M1i next targets cell-owned `SourceComponentId` / `IsolationSheetId` scope.',
    '- M1h phase-front field charts cross checked `FieldChartId` boundaries before constructive-front semantic use and are **immutable accepted**. M1i now carries cell-owned source component/sheet state through checked `SourceComponentId` / `IsolationSheetId`; compile/package is complete and runtime acceptance is pending.',
    'tracker RP01')
old = f'''M1i source-scope migration must preserve `RP-02 / TA-05` while adding production-path counterexamples for `SourceComponentId` versus `IsolationSheetId`, malformed enabled labels, face-row permutation, and typed-to-legacy compatibility derivation.

Authoritative next Code + Build plan: `{CODE_PLAN}`.'''
new = f'''M1i source-scope migration adds six compiled production-path contracts covering `SourceComponentId` versus `IsolationSheetId`, multi-sheet no-representative semantics, malformed enabled labels, face-row permutation, and typed-to-legacy compatibility derivation. They remain runtime pending; compile success is not test authority. The first package attempt's wrong-working-directory checksum failure was orchestration-only and caused no source change.

Authoritative next immutable runtime plan: `{RUNTIME_PLAN}`. Expected producer discovery is **208**, M1i focused **6/6**, and required-green **193/193**. Historical totals remain **34 / 14 / 20**.'''
s = replace_once(s, old, new, 'tracker RP02')
p.write_text(s)

# TODO live active-direction section only.
p = Path('TODO')
s = p.read_text()
start = '- Architecture migration: **M1a through M1h immutable accepted; M1i phase-front cell source-scope consumer selected for Code + Build**.'
end = '## M1d immutable acceptance\n'
block = f'''- Architecture migration: **M1a through M1h immutable accepted; M1i source-scope Code + Build complete and immutable runtime pending**.
- M1i implementation `b037157921094604f1b0c17f9c8b7076c7604b3b`; seam `phase_front_cell_source_scope -> SurfacePhaseFrontCell::{{sourceComponent, sourceSheet, sourceIsolationSheets}}`.
- Cell-owned source scope now uses checked `SourceComponentId` / `IsolationSheetId`; raw edge/pipeline values are explicit compatibility boundaries only.
- Successful build run/job `31411770135 / 93531293415`: **120/120**, Release/static/Ninja/PRE_TEST, artifacts `9072101943 / 9072102331`, ZIP SHA-256 `e30860e5ec411dc4dc446d0a4dc65ce6f15c5784a6f5daca138ab44d7196bf25 / 38353b8c101a298d9a537a82da17e075180619343246a6ba4a8e2f430bd14d44`.
- Package manifest **72/72**, digest `f5614100e1638990d46c7c8fa3d7c720c837dfae1ae515387977d4c0b9e9cac3`; 73 regular files, 7 executables, 2 libraries, 27 fixtures.
- First build attempt `31410750675` compiled **120/120** and failed only at package checksum verification due wrong cwd; corrected retry made no source delta. First-attempt logs `9071739970`.
- Code + Build runtime boundary: **false**; six M1i contracts compiled and were not executed.
- Authoritative next turn: `{RUNTIME_PLAN}`.
- Expected runtime authority: producer discovery **208**, M1i focused **6/6**, required-green **193/193**, full M1h–M1b/validation/M1a/T1/direct/historical/heavy/postflight preservation.
- Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`; draft PR #8 stays open/unmerged; review policy `never`.
- Current Code + Build report: `{REPORT}`.
'''
s = replace_region(s, start, end, block + end, 'TODO active')
p.write_text(s)

# Milestone live current gate and M1i current status inserted after M1h authority.
p = Path('MILESTONE_G_TODO.md')
s = p.read_text()
s = replace_once(s,
    'Production remains known-red on direct torus. T1 independent authority and M1a through M1h architecture slices are immutable accepted. M1i phase-front cell source-scope authority is the next Code + Build slice. Architecture migration remains separate from G4 product acceptance.',
    'Production remains known-red on direct torus. T1 independent authority and M1a through M1h architecture slices are immutable accepted. M1i phase-front cell source-scope Code + Build is complete and immutable runtime is next. Architecture migration remains separate from G4 product acceptance.',
    'milestone gate')
old = f'''Next architecture slice: **M1i Phase-Front Cell Source-Scope Consumer — Code + Build only** at `phase_front_cell_source_scope -> SurfacePhaseFrontCell::{{sourceComponent, sourceSheet, sourceIsolationSheets}}`.

Authoritative plan: `{CODE_PLAN}`.
Current immutable report: `.agents/Directional/Architecture_M1h_Phase_Front_Field_Chart_Test_Authority_Remediation_Artifact_Only_Test_Benchmark_Report.md`.
'''
new = f'''## M1i phase-front cell source-scope authority — compile/package complete; runtime pending

Implementation `b037157921094604f1b0c17f9c8b7076c7604b3b` migrates only `SurfacePhaseFrontCell::{{sourceComponent, sourceSheet, sourceIsolationSheets}}` to checked `SourceComponentId` / `IsolationSheetId`. Raw `SurfaceFrontEdge` and current pipeline source-scope fields remain explicit compatibility boundaries. Exactly six focused M1i contracts compile and were not executed.

Successful build run/job `31411770135 / 93531293415` compiled **120/120** Release/static/Ninja/PRE_TEST. Result/log artifacts are `9072101943 / 9072102331`, outer SHA-256 `e30860e5ec411dc4dc446d0a4dc65ce6f15c5784a6f5daca138ab44d7196bf25 / 38353b8c101a298d9a537a82da17e075180619343246a6ba4a8e2f430bd14d44`; recursive manifest is **72/72**, digest `f5614100e1638990d46c7c8fa3d7c720c837dfae1ae515387977d4c0b9e9cac3`. Every runtime flag is false.

The first attempt `31410750675` also compiled **120/120** but package checksum verification ran from the wrong working directory. The retry changed no source; the defect is retained as orchestration provenance, not product evidence.

Run **M1i immutable Artifact-Only Test + Benchmark only** under `{RUNTIME_PLAN}`. Expected native producer discovery is **208**, M1i focused **6/6**, required-green **193/193**, with full entering preservation and exact postflight. M1i semantic acceptance remains pending.

Current report: `{REPORT}`.
'''
s = replace_once(s, old, new, 'milestone M1i status')
p.write_text(s)

for path in [Path('.agents/Directional/Future_Chat_Session_Handoff.md'), Path('.agents/Directional/REORIENTATION_PLAN.md'), Path('.agents/Directional/Regression_Root_Cause_Tracker.md'), Path('TODO'), Path('MILESTONE_G_TODO.md')]:
    text = path.read_text()
    if RUNTIME_PLAN not in text:
        raise SystemExit(f'{path}: missing next runtime plan')
print('M1i Code + Build live closeout applied')
