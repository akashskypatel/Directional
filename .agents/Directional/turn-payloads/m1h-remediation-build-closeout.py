from pathlib import Path
import re

ARTIFACT_PLAN = '.agents/Directional/Architecture_M1h_Phase_Front_Field_Chart_Test_Authority_Remediation_Artifact_Only_Test_Benchmark_Plan.md'
REPORT = '.agents/Directional/Architecture_M1h_Phase_Front_Field_Chart_Test_Authority_Remediation_Code_Build_Report.md'


def replace_regex(path, pattern, replacement, flags=0):
    p = Path(path)
    text = p.read_text()
    updated, count = re.subn(pattern, replacement, text, count=1, flags=flags)
    if count != 1:
        raise SystemExit(f'{path}: expected one regex replacement, got {count}')
    p.write_text(updated)


def replace_once(path, old, new):
    p = Path(path)
    text = p.read_text()
    if text.count(old) != 1:
        raise SystemExit(f'{path}: expected one literal occurrence, got {text.count(old)} for {old!r}')
    p.write_text(text.replace(old, new, 1))

handoff = '''## Mandatory next turn

Run **M1h Phase-Front Field-Chart Test-Authority Remediation — immutable Artifact-Only Test + Benchmark only** under:

`.agents/Directional/Architecture_M1h_Phase_Front_Field_Chart_Test_Authority_Remediation_Artifact_Only_Test_Benchmark_Plan.md`

Repository: `akashskypatel/Directional`, branch `agent/surface_cell_quad/p5-recover-bridge-healing`. Draft PR #8 stays open, draft, and unmerged. Product gate **G4 topology-distinct completion and singularities** remains active. M1a through M1g are immutable accepted. M1h production code remains runtime-pending. Review policy is `never`.

Consume only remediation result/log artifacts `9069186973 / 9069187317` produced from implementation `32b22d3ee8aa46ba2d1fd149ce04204a4206d0c0`. This commit changes only `tests/SurfaceCellsPhase10Tests.cpp`; production implementation remains `de4e2ba7c19d2e49931655dc22d758f50656d054`. Rebuild, relink, configure, regeneration, source/test/build/fixture edits, repair, substitution, and runtime fixture symlinks are prohibited.

Expected runtime authority: producer discovery **202**, M1h focused **6/6** individually, required-green producer **187/187**, M1g–M1b preservation, validation **77/77**, M1a **14/14**, T1 **29/29**, four direct products independent-oracle clean without fixture symlink, eight historical/deferred red classes unchanged, strict-validator timing characterized without retry-based greening, Bunny/Vase bounded comparison if no earlier blocker remains, and exact immutable postflight.

## M1h test-authority remediation compile/package authority — runtime pending

The prior immutable M1h runtime from artifacts `9066967620 / 9066968049` remains retained evidence: package authority passed, producer discovery was **202**, M1h focused was **5/6**, required-green was **186/187**, all entering preservation/direct-product authority stayed green, and the sole blocker was the invalid witness in `MultipleOrientationChartsPreserveEstablishedNumbering`. That witness incorrectly equated producer chart-domain coverage with lattice-corner occurrence coverage; it was classified as a test-authority defect, not a product regression.

The remediation preserves the exact producer chart domain `{0,1,2}` through hard-authored source-face compatibility assertions while separately checking every actual typed lattice occurrence against the expected producer chart for its source face. It does not encode `{0,2}` as a domain expectation.

| Evidence | Value |
|---|---|
| remediation implementation | `32b22d3ee8aa46ba2d1fd149ce04204a4206d0c0` |
| base M1h production implementation | `de4e2ba7c19d2e49931655dc22d758f50656d054` |
| build run/job | `31404102605 / 93506073062` |
| result artifact / SHA-256 | `9069186973` / `d2b334f278f0281c5b3a5a5a6b33ba8bf085b7cf374376beb437e559646d9df8` |
| log artifact / SHA-256 | `9069187317` / `56c0d0fb012b5d3b5fa4bb7284a496d700a4ebf408806b53c27f21f00311679a` |
| recursive manifest | **72/72**, `4b8839695369a114567a38fbcddc4dde7d1cea8b024940cb2071a256d9d594d8` |
| package | **73** regular files; 7 executables; 2 static libraries; 27 fixtures |
| build | **120/120**, Release/static/Ninja/PRE_TEST, **8:20.53**, peak RSS **1,850,456 KiB** |
| production source delta | **none** |
| runtime | **false** |

Exactly six `SurfaceCellPhaseFrontFieldChartAuthorityMigration` contracts remain compiled. No generated Directional binary, discovery, test, benchmark, `ctest`, CLI, fuzzer, or custom input ran in this Code + Build turn. Compile/package success is not M1h semantic acceptance.

Current Code + Build report:
`.agents/Directional/Architecture_M1h_Phase_Front_Field_Chart_Test_Authority_Remediation_Code_Build_Report.md`.

Authoritative next plan:
`.agents/Directional/Architecture_M1h_Phase_Front_Field_Chart_Test_Authority_Remediation_Artifact_Only_Test_Benchmark_Plan.md`.
'''
replace_regex(
    '.agents/Directional/Future_Chat_Session_Handoff.md',
    r'## Mandatory next turn\n.*?(?=\n## M1g immutable acceptance authority)',
    handoff.rstrip(),
    re.S,
)

replace_once(
    '.agents/Directional/REORIENTATION_PLAN.md',
    'M1h phase-front field-chart consumer [compile/package complete; runtime next]',
    'M1h phase-front field-chart consumer [test-authority remediation compile/package complete; immutable runtime next]',
)
replace_once(
    '.agents/Directional/REORIENTATION_PLAN.md',
    'Authoritative next Code + Build plan:\n`.agents/Directional/Architecture_M1h_Phase_Front_Field_Chart_Test_Authority_Remediation_Code_Build_Plan.md`.',
    'Authoritative next immutable Test + Benchmark plan:\n`.agents/Directional/Architecture_M1h_Phase_Front_Field_Chart_Test_Authority_Remediation_Artifact_Only_Test_Benchmark_Plan.md`.\n\nM1h remediation implementation `32b22d3ee8aa46ba2d1fd149ce04204a4206d0c0` changes only the focused test witness; production remains `de4e2ba7c19d2e49931655dc22d758f50656d054`. Build `31404102605 / 93506073062` is **120/120** with artifacts `9069186973 / 9069187317`, manifest **72/72**, and no runtime execution. Semantic acceptance remains pending.',
)

active_todo = '''## Active direction

- Phase: P5 — producer-correct direct surface paving.
- Product gate: **G4 topology-distinct completion and singularities active**.
- Test architecture: **T1 independent oracle/package foundation accepted**.
- Architecture migration: **M1a through M1g immutable accepted; M1h test-authority remediation compile/package complete and immutable runtime pending**.
- M1h production implementation remains `de4e2ba7c19d2e49931655dc22d758f50656d054`; remediation implementation `32b22d3ee8aa46ba2d1fd149ce04204a4206d0c0` changes only `tests/SurfaceCellsPhase10Tests.cpp`.
- Remediation build run/job `31404102605 / 93506073062`: **120/120**, artifacts `9069186973 / 9069187317`, result/log SHA-256 `d2b334f278f0281c5b3a5a5a6b33ba8bf085b7cf374376beb437e559646d9df8 / 56c0d0fb012b5d3b5fa4bb7284a496d700a4ebf408806b53c27f21f00311679a`, manifest **72/72**, 73 regular files, 7 executables, 2 libraries, 27 fixtures.
- Code + Build runtime boundary: **false**; no generated binary, discovery, tests, benchmarks, `ctest`, CLI, fuzzer, or custom input executed.
- Prior blocked M1h runtime remains evidence: focused **5/6**, required-green **186/187**; the sole failure was an invalid test witness, with all entering preservation/direct-product authority unchanged.
- Corrected witness preserves producer domain `{0,1,2}` and checks actual typed lattice occurrences per hard-authored source-face chart rather than requiring occurrence coverage to equal the producer domain.
- Authoritative next turn: `.agents/Directional/Architecture_M1h_Phase_Front_Field_Chart_Test_Authority_Remediation_Artifact_Only_Test_Benchmark_Plan.md`.
- Expected next runtime: producer **202**, M1h **6/6**, required-green **187/187**, full preservation/direct/historical/heavy-case/postflight authority.
- Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`; draft PR #8 stays open/unmerged; review policy `never`.
- Current Code + Build report: `.agents/Directional/Architecture_M1h_Phase_Front_Field_Chart_Test_Authority_Remediation_Code_Build_Report.md`.
'''
replace_regex('TODO', r'## Active direction\n.*?(?=\n## M1d immutable acceptance)', active_todo.rstrip(), re.S)

replace_once(
    'MILESTONE_G_TODO.md',
    'Production remains known-red on direct torus. T1 independent authority and M1a through M1g architecture slices are immutable accepted. M1h Phase-Front Field-Chart Consumer is compile/package complete and immutable runtime is next. Architecture migration remains separate from G4 product acceptance.',
    'Production remains known-red on direct torus. T1 independent authority and M1a through M1g architecture slices are immutable accepted. M1h test-authority remediation is compile/package complete and immutable runtime is next; production source remains unchanged. Architecture migration remains separate from G4 product acceptance.',
)
milestone_block = '''## M1h remediation compile/package and authoritative next turn

The prior exact M1h runtime from artifacts `9066967620 / 9066968049` remains retained evidence: package authority and all entering preservation/direct-product gates passed, while M1h focused was **5/6** and required-green **186/187** because `MultipleOrientationChartsPreserveEstablishedNumbering` conflated producer chart-domain coverage with lattice-occurrence coverage.

Remediation implementation `32b22d3ee8aa46ba2d1fd149ce04204a4206d0c0` changes only `tests/SurfaceCellsPhase10Tests.cpp`. Production implementation remains `de4e2ba7c19d2e49931655dc22d758f50656d054`. The repaired witness keeps producer chart-domain authority exactly `{0,1,2}`, hard-authors face `3 -> 1` and face `10 -> 2`, and separately validates every actual typed lattice occurrence against its source-face chart without encoding `{0,2}` as a domain expectation.

Build run/job `31404102605 / 93506073062` compiled **120/120** Release/static/Ninja/PRE_TEST. Result/log artifacts are `9069186973 / 9069187317` with SHA-256 `d2b334f278f0281c5b3a5a5a6b33ba8bf085b7cf374376beb437e559646d9df8 / 56c0d0fb012b5d3b5fa4bb7284a496d700a4ebf408806b53c27f21f00311679a`; recursive manifest is **72/72** with digest `4b8839695369a114567a38fbcddc4dde7d1cea8b024940cb2071a256d9d594d8`. Package cardinality is 73 regular files, seven executables, two static libraries, and 27 fixtures. No generated Directional binary or runtime validation executed.

Run **M1h Phase-Front Field-Chart Test-Authority Remediation — immutable Artifact-Only Test + Benchmark only** under:

`.agents/Directional/Architecture_M1h_Phase_Front_Field_Chart_Test_Authority_Remediation_Artifact_Only_Test_Benchmark_Plan.md`

Expected runtime authority remains producer discovery **202**, M1h focused **6/6**, required-green **187/187**, full M1g–M1b/validation/M1a/T1/direct-product preservation, unchanged historical reds, strict-validator characterization, Bunny/Vase bounded comparison if no earlier blocker remains, and exact immutable postflight.

Current Code + Build report: `.agents/Directional/Architecture_M1h_Phase_Front_Field_Chart_Test_Authority_Remediation_Code_Build_Report.md`.
'''
replace_regex(
    'MILESTONE_G_TODO.md',
    r'## M1h runtime block and authoritative next turn\n.*?(?=\n## M1f vertex-continuation transport)',
    milestone_block.rstrip(),
    re.S,
)
combined_m1h = '''## M1h phase-front field-chart authority — production compiled; witness remediation compiled

Selected boundary:
`build_planar_phase_frame -> UniformPhaseFrame::faceChart -> LocalLatticeState::sourceChart`.

Production implementation `de4e2ba7c19d2e49931655dc22d758f50656d054` retains deterministic chart partition/numbering, crosses checked `FieldChartId`, carries typed optional lattice chart authority, and uses explicit compatibility conversions downstream. The package-layout correction resolves executable-relative sibling `../test-data` before historical fallbacks.

The first immutable runtime from artifacts `9066967620 / 9066968049` proved package portability and all entering preservation gates but blocked M1h at **5/6** focused / **186/187** required-green because one new focused witness confused producer-domain coverage with lattice-occurrence coverage. This did not create a stable product regression.

Remediation implementation `32b22d3ee8aa46ba2d1fd149ce04204a4206d0c0` is test-only. It preserves exact producer domain `{0,1,2}` while checking actual `FieldChartId` occurrences per independently hard-authored source-face expectation.

| Evidence | Value |
|---|---|
| Production implementation | `de4e2ba7c19d2e49931655dc22d758f50656d054` |
| Remediation implementation | `32b22d3ee8aa46ba2d1fd149ce04204a4206d0c0` |
| Build run/job | `31404102605 / 93506073062`, **120/120** |
| Result artifact / SHA-256 | `9069186973` / `d2b334f278f0281c5b3a5a5a6b33ba8bf085b7cf374376beb437e559646d9df8` |
| Log artifact / SHA-256 | `9069187317` / `56c0d0fb012b5d3b5fa4bb7284a496d700a4ebf408806b53c27f21f00311679a` |
| Recursive manifest | **72/72**, `4b8839695369a114567a38fbcddc4dde7d1cea8b024940cb2071a256d9d594d8` |
| Package | **73** regular files; 7 executables; 2 static libraries; 27 fixtures |
| Build boundary | Release/static/Ninja/PRE_TEST; production delta none; runtime **false** |

No stable regression event or recurrence is assigned from compile-only remediation evidence. Immutable runtime is mandatory before M1h acceptance.
'''
replace_regex(
    'MILESTONE_G_TODO.md',
    r'## M1h phase-front field-chart authority — compile/package complete\n.*?(?=\n## Regression disposition)',
    combined_m1h.rstrip(),
    re.S,
)

replace_once(
    '.agents/Directional/Regression_Root_Cause_Tracker.md',
    'Last updated: **2026-08-10 UTC** after blocked M1h immutable runtime from artifact `9066967620`; test-authority remediation is next.',
    'Last updated: **2026-08-10 UTC** after M1h test-authority remediation Code + Build from artifact `9069186973`; immutable runtime is next.',
)
replace_once(
    '.agents/Directional/Regression_Root_Cause_Tracker.md',
    'M1h artifact `9066967620` creates no stable product regression event: immutable runtime is blocked by one newly introduced focused test-authority witness, while all entering product/preservation authority remained unchanged. Semantic acceptance remains pending.',
    'M1h artifact `9066967620` created no stable product regression event: immutable runtime was blocked by one newly introduced focused test-authority witness while all entering product/preservation authority remained unchanged. Remediation artifact `9069186973` changes only that test witness and creates no stable product regression event from compile-only evidence. Semantic acceptance remains pending.',
)
replace_once(
    '.agents/Directional/Regression_Root_Cause_Tracker.md',
    'Focused migration tests do not replace this authority. M1g preservation passed exact artifact execution from `9053047653`. M1h exact artifact runtime preserved entering `RP-02 / TA-05` authority but the new M1h suite is **5/6** because `MultipleOrientationChartsPreserveEstablishedNumbering` conflates producer chart-domain coverage with lattice-corner occurrence coverage. Required-green is **186/187** with that same sole failure. No stable product regression event or recurrence is added; M1h acceptance remains blocked until the test witness is corrected and re-run from a fresh immutable package.',
    'Focused migration tests do not replace this authority. M1g preservation passed exact artifact execution from `9053047653`. M1h exact artifact runtime preserved entering `RP-02 / TA-05` authority but the new M1h suite was **5/6** because `MultipleOrientationChartsPreserveEstablishedNumbering` conflated producer chart-domain coverage with lattice-corner occurrence coverage. Required-green was **186/187** with that same sole failure. Remediation implementation `32b22d3ee8aa46ba2d1fd149ce04204a4206d0c0` corrects only the witness: producer chart domain remains exact `{0,1,2}` while actual typed occurrences are validated per hard-authored source face. Build artifact `9069186973` is compile/package complete with no runtime execution. No stable product regression event or recurrence is added; M1h acceptance remains pending immutable runtime.',
)

for path in [
    '.agents/Directional/Future_Chat_Session_Handoff.md',
    '.agents/Directional/REORIENTATION_PLAN.md',
    '.agents/Directional/Regression_Root_Cause_Tracker.md',
    'MILESTONE_G_TODO.md',
    'TODO',
]:
    text = Path(path).read_text()
    if ARTIFACT_PLAN not in text:
        raise SystemExit(f'{path}: next artifact plan not referenced')

print('closeout payload applied surgically')
