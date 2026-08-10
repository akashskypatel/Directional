from pathlib import Path
import re

NEW_REPORT = '.agents/Directional/Architecture_M1h_Phase_Front_Field_Chart_Test_Authority_Remediation_Artifact_Only_Test_Benchmark_Report.md'
NEXT_PLAN = '.agents/Directional/Architecture_M1i_Phase_Front_Cell_Source_Scope_Consumer_Code_Build_Plan.md'
OLD_BLOCKED_REPORT = '.agents/Directional/Architecture_M1h_Phase_Front_Field_Chart_Consumer_Artifact_Only_Test_Benchmark_Report.md'
OLD_CB_PLAN = '.agents/Directional/Architecture_M1h_Phase_Front_Field_Chart_Test_Authority_Remediation_Code_Build_Plan.md'
OLD_CB_REPORT = '.agents/Directional/Architecture_M1h_Phase_Front_Field_Chart_Test_Authority_Remediation_Code_Build_Report.md'
OLD_TB_PLAN = '.agents/Directional/Architecture_M1h_Phase_Front_Field_Chart_Test_Authority_Remediation_Artifact_Only_Test_Benchmark_Plan.md'


def replace_once(text: str, old: str, new: str, label: str) -> str:
    count = text.count(old)
    if count != 1:
        raise SystemExit(f'{label}: expected exactly one occurrence, found {count}')
    return text.replace(old, new, 1)


def replace_region(text: str, start: str, end: str, replacement: str, label: str) -> str:
    a = text.find(start)
    if a < 0:
        raise SystemExit(f'{label}: start marker missing')
    b = text.find(end, a + len(start))
    if b < 0:
        raise SystemExit(f'{label}: end marker missing')
    if text.find(start, a + len(start)) >= 0 and text.find(start, a + len(start)) < b:
        raise SystemExit(f'{label}: duplicate start marker inside region')
    return text[:a] + replacement + text[b:]


# Live handoff: replace only the current-turn front matter, retain historical/durable body.
p = Path('.agents/Directional/Future_Chat_Session_Handoff.md')
s = p.read_text()
new_front = f'''## Mandatory next turn

Run **M1i Phase-Front Cell Source-Scope Consumer — Code + Build only** under:

`{NEXT_PLAN}`

Repository: `akashskypatel/Directional`, branch `agent/surface_cell_quad/p5-recover-bridge-healing`. Draft PR #8 stays open, draft, and unmerged. Product gate **G4 topology-distinct completion and singularities** remains active. M1a through M1h are immutable accepted. Review policy is `never`.

M1i is bounded to:

`phase_front_cell_source_scope -> SurfacePhaseFrontCell::{{sourceComponent, sourceSheet, sourceIsolationSheets}}`.

It migrates cell-owned source-component/isolation-sheet authority to checked `SourceComponentId` / `IsolationSheetId` while preserving current source-scope semantics and using explicit compatibility conversions only for still-raw neighboring consumers. Do not expand into `SurfaceFrontEdge` scope migration, `TopologyRegionId`, hard-rail/periodic owner IDs, M2–M6, or G4 behavior repair.

This next turn is **Code + Build only**. Execute no generated Directional binary, discovery, test, benchmark, `ctest`, CLI, fuzzer, or custom input.

## M1h immutable acceptance authority

M1h is accepted from remediation implementation `32b22d3ee8aa46ba2d1fd149ce04204a4206d0c0` over unchanged production implementation `de4e2ba7c19d2e49931655dc22d758f50656d054` and exact artifacts `9069186973 / 9069187317`.

Runtime authority: producer discovery **202**, M1h focused **6/6**, required-green **187/187**, M1g–M1b preservation green, validation **77/77**, M1a **14/14**, T1 **29/29**, and Plane/MultiFaceSeam/CloseSheets/Cylinder independent-oracle clean without a fixture symlink. All eight historical/deferred red classes remain unchanged. Strict-validator timing remains deferred after fresh **0/10** characterization. Bunny remains `NotProductionReady:completion traceSegments=170831 arrangementCells=0 completedQuads=0`; Vase remains bounded safety-only at 60 seconds.

Heavy artifact-only run `31407263138` retained Bunny evidence/log artifacts `9070146263 / 9070146878` and Vase evidence/log artifacts `9070135665 / 9070135953`. Local and remote postflight preserved the exact result ZIP, **72/72** content manifest, 73 regular files, seven executables, two libraries, 27 fixtures, and producer hash with `fixtureSymlink=false`.

Historical regression totals remain **34 events / 14 categories / 20 recurrences**. `PR8-R034 / G4-R007` remains active.

Current immutable report:
`{NEW_REPORT}`.

Authoritative next plan:
`{NEXT_PLAN}`.

'''
s = replace_region(s, '## Mandatory next turn\n', '## M1g immutable acceptance authority\n', new_front, 'handoff front matter')
for old in [OLD_BLOCKED_REPORT, OLD_CB_PLAN, OLD_CB_REPORT, OLD_TB_PLAN]:
    s = s.replace(old, NEW_REPORT if 'Report' in old else NEXT_PLAN)
p.write_text(s)

# Reorientation roadmap: only current M1 status and exact next-action checkpoint.
p = Path('.agents/Directional/REORIENTATION_PLAN.md')
s = p.read_text()
s = replace_once(
    s,
    '   M1h phase-front field-chart consumer [test-authority remediation compile/package complete; immutable runtime next]\n   later bounded M1 consumers [pending]',
    '   M1h phase-front field-chart consumer [accepted]\n   M1i phase-front cell source-scope consumer [selected; Code + Build next]\n   later bounded M1 consumers [pending]',
    'reorientation M1 status')
old = f'''Authoritative next immutable Test + Benchmark plan:\n`{OLD_TB_PLAN}`.\n\nM1h remediation implementation `32b22d3ee8aa46ba2d1fd149ce04204a4206d0c0` changes only the focused test witness; production remains `de4e2ba7c19d2e49931655dc22d758f50656d054`. Build `31404102605 / 93506073062` is **120/120** with artifacts `9069186973 / 9069187317`, manifest **72/72**, and no runtime execution. Semantic acceptance remains pending.'''
new = f'''M1h is immutable accepted from remediation implementation `32b22d3ee8aa46ba2d1fd149ce04204a4206d0c0` and artifacts `9069186973 / 9069187317`: producer discovery **202**, focused **6/6**, required-green **187/187**, validation **77/77**, M1a **14/14**, T1 **29/29**, four direct products independent-oracle clean, unchanged historical-red classes, Bunny known-red, Vase bounded safety-only, and exact **72/72** postflight. No new stable product regression or recurrence was created.\n\nFresh accepted-source inspection selects M1i at `phase_front_cell_source_scope -> SurfacePhaseFrontCell::{{sourceComponent, sourceSheet, sourceIsolationSheets}}`. The cell still persists source-component/isolation-sheet identity as raw integers although the authority kernel already defines `SourceComponentId` and `IsolationSheetId`.\n\nAuthoritative next Code + Build plan:\n`{NEXT_PLAN}`.'''
s = replace_once(s, old, new, 'reorientation current checkpoint')
for old_name in [OLD_BLOCKED_REPORT, OLD_CB_PLAN, OLD_CB_REPORT, OLD_TB_PLAN]:
    s = s.replace(old_name, NEW_REPORT if 'Report' in old_name else NEXT_PLAN)
p.write_text(s)

# Regression tracker: preserve history, update only M1h disposition and next owner.
p = Path('.agents/Directional/Regression_Root_Cause_Tracker.md')
s = p.read_text()
s = replace_once(
    s,
    'Last updated: **2026-08-10 UTC** after M1h test-authority remediation Code + Build from artifact `9069186973`; immutable runtime is next.',
    'Last updated: **2026-08-10 UTC** after immutable M1h acceptance from remediation artifact `9069186973`; M1i cell source-scope authority is next.',
    'tracker last updated')
s = replace_once(
    s,
    'M1h artifact `9066967620` created no stable product regression event: immutable runtime was blocked by one newly introduced focused test-authority witness while all entering product/preservation authority remained unchanged. Remediation artifact `9069186973` changes only that test witness and creates no stable product regression event from compile-only evidence. Semantic acceptance remains pending.',
    'M1h artifact `9066967620` created no stable product regression event: its sole focused failure was classified as a test-authority witness defect while all entering product/preservation authority remained unchanged. Remediation artifact `9069186973` is now immutable accepted with focused **6/6**, required-green **187/187**, full entering preservation/direct-product authority, unchanged historical-red classes, and exact postflight. No stable product regression event or recurrence is added.',
    'tracker historical M1h disposition')
s = replace_once(
    s,
    '- M1h phase-front field charts cross checked `FieldChartId` boundaries before constructive-front semantic use; compile/package is complete and runtime acceptance is pending.',
    '- M1h phase-front field charts cross checked `FieldChartId` boundaries before constructive-front semantic use and are **immutable accepted**. M1i next targets cell-owned `SourceComponentId` / `IsolationSheetId` scope.',
    'tracker RP01 M1h')
start = 'Focused migration tests do not replace this authority. M1g preservation passed exact artifact execution from `9053047653`.'
end = '### RP-03 — policy/stage state conflation\n'
replacement = f'''Focused migration tests do not replace this authority. M1h remediation artifact `9069186973` is now immutable accepted: producer discovery **202**, required-green **187/187**, M1h **6/6**, all M1g–M1b focused preservation, validation **77/77**, M1a **14/14**, T1 **29/29**, four direct products independent-oracle clean without a fixture symlink, all eight historical/deferred red classes unchanged, Bunny known-red, Vase bounded safety-only, and exact **72/72** postflight. The prior `MultipleOrientationChartsPreserveEstablishedNumbering` failure remains classified as a test-authority witness defect, not a product regression. Historical totals stay **34 / 14 / 20**.\n\nM1i source-scope migration must preserve `RP-02 / TA-05` while adding production-path counterexamples for `SourceComponentId` versus `IsolationSheetId`, malformed enabled labels, face-row permutation, and typed-to-legacy compatibility derivation.\n\nAuthoritative next Code + Build plan: `{NEXT_PLAN}`.\n\n'''
s = replace_region(s, start, end, replacement + end, 'tracker RP02 current block')
for old_name in [OLD_BLOCKED_REPORT, OLD_CB_PLAN, OLD_CB_REPORT, OLD_TB_PLAN]:
    s = s.replace(old_name, NEW_REPORT if 'Report' in old_name else NEXT_PLAN)
p.write_text(s)

# TODO: replace only live Active direction bullets.
p = Path('TODO')
s = p.read_text()
start = '- Architecture migration: **M1a through M1g immutable accepted; M1h test-authority remediation compile/package complete and immutable runtime pending**.'
end = '## M1d immutable acceptance\n'
replacement = f'''- Architecture migration: **M1a through M1h immutable accepted; M1i phase-front cell source-scope consumer selected for Code + Build**.\n- Accepted M1h remediation implementation `32b22d3ee8aa46ba2d1fd149ce04204a4206d0c0`; production implementation remains `de4e2ba7c19d2e49931655dc22d758f50656d054`.\n- M1h artifacts `9069186973 / 9069187317`: producer **202**, focused **6/6**, required-green **187/187**, validation **77/77**, M1a **14/14**, T1 **29/29**, four direct products green without fixture symlink, all eight historical/deferred red classes unchanged.\n- Heavy run `31407263138`: Bunny unchanged `NotProductionReady:completion traceSegments=170831 arrangementCells=0 completedQuads=0`; Vase bounded safety-only at 60 seconds; both preserved exact **72/72** package authority.\n- Strict-validator timing remains deferred after fresh **0/10** characterization; no threshold/retry workaround is authorized.\n- M1i seam: `phase_front_cell_source_scope -> SurfacePhaseFrontCell::{{sourceComponent, sourceSheet, sourceIsolationSheets}}`; migrate only cell-owned source scope to checked `SourceComponentId` / `IsolationSheetId`.\n- Authoritative next turn: `{NEXT_PLAN}`.\n- Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`; draft PR #8 stays open/unmerged; review policy `never`.\n- Current immutable report: `{NEW_REPORT}`.\n'''
s = replace_region(s, start, end, replacement + end, 'TODO active direction')
for old_name in [OLD_BLOCKED_REPORT, OLD_CB_PLAN, OLD_CB_REPORT, OLD_TB_PLAN]:
    s = s.replace(old_name, NEW_REPORT if 'Report' in old_name else NEXT_PLAN)
p.write_text(s)

# Milestone G: update current gate sentence and replace the superseded M1h current section only.
p = Path('MILESTONE_G_TODO.md')
s = p.read_text()
s = replace_once(
    s,
    'Production remains known-red on direct torus. T1 independent authority and M1a through M1g architecture slices are immutable accepted. M1h test-authority remediation is compile/package complete and immutable runtime is next; production source remains unchanged. Architecture migration remains separate from G4 product acceptance.',
    'Production remains known-red on direct torus. T1 independent authority and M1a through M1h architecture slices are immutable accepted. M1i phase-front cell source-scope authority is the next Code + Build slice. Architecture migration remains separate from G4 product acceptance.',
    'milestone current gate')
start = '## M1h remediation compile/package and authoritative next turn\n'
end = '## M1f vertex-continuation transport — immutable accepted\n'
replacement = f'''## M1h phase-front field-chart authority — immutable accepted\n\nM1h is immutable accepted from remediation implementation `32b22d3ee8aa46ba2d1fd149ce04204a4206d0c0` over unchanged production implementation `de4e2ba7c19d2e49931655dc22d758f50656d054`. Exact result/log artifacts are `9069186973 / 9069187317`, recursive manifest **72/72**.\n\nRuntime acceptance: producer discovery **202**, M1h **6/6**, required-green **187/187**, all M1g–M1b focused preservation, validation **77/77**, M1a **14/14**, T1 **29/29**, and Plane/MultiFaceSeam/CloseSheets/Cylinder independent-oracle clean without a fixture symlink. All eight historical/deferred red classes are unchanged. Strict-validator timing remains deferred after **0/10** fresh passes.\n\nHeavy run `31407263138` preserved Bunny's known `NotProductionReady:completion traceSegments=170831 arrangementCells=0 completedQuads=0` failure and bounded Vase at 60 seconds as safety-only evidence. Local and remote postflight preserved the exact package, producer hash, and **72/72** content checksums. No stable product regression event or recurrence was created. `PR8-R034 / G4-R007` remains active.\n\nNext architecture slice: **M1i Phase-Front Cell Source-Scope Consumer — Code + Build only** at `phase_front_cell_source_scope -> SurfacePhaseFrontCell::{{sourceComponent, sourceSheet, sourceIsolationSheets}}`.\n\nAuthoritative plan: `{NEXT_PLAN}`.\nCurrent immutable report: `{NEW_REPORT}`.\n\n'''
s = replace_region(s, start, end, replacement + end, 'milestone M1h current section')
for old_name in [OLD_BLOCKED_REPORT, OLD_CB_PLAN, OLD_CB_REPORT, OLD_TB_PLAN]:
    s = s.replace(old_name, NEW_REPORT if 'Report' in old_name else NEXT_PLAN)
p.write_text(s)

# Fail closed if a consumed current-head filename remains in any durable/live document.
for path in [
    Path('.agents/Directional/Future_Chat_Session_Handoff.md'),
    Path('.agents/Directional/REORIENTATION_PLAN.md'),
    Path('.agents/Directional/Regression_Root_Cause_Tracker.md'),
    Path('TODO'), Path('MILESTONE_G_TODO.md')]:
    text = path.read_text()
    for stale in [OLD_BLOCKED_REPORT, OLD_CB_PLAN, OLD_CB_REPORT, OLD_TB_PLAN]:
        if stale in text:
            raise SystemExit(f'{path}: stale current-head reference remains: {stale}')

print('M1h runtime closeout payload applied surgically')
