from pathlib import Path
import re

ROOT = Path('.')
REPORT = '.agents/Directional/Architecture_M1h_Phase_Front_Field_Chart_Consumer_Artifact_Only_Test_Benchmark_Report.md'
NEXT_PLAN = '.agents/Directional/Architecture_M1h_Phase_Front_Field_Chart_Test_Authority_Remediation_Code_Build_Plan.md'

STALE = {
    '.agents/Directional/Architecture_M1g_Periodic_Holonomy_Route_Transport_Consumer_Artifact_Only_Test_Benchmark_Report.md': REPORT,
    '.agents/Directional/Architecture_M1h_Phase_Front_Field_Chart_Consumer_Code_Build_Plan.md': NEXT_PLAN,
    '.agents/Directional/Architecture_M1h_Phase_Front_Field_Chart_Consumer_Code_Build_Report.md': REPORT,
    '.agents/Directional/Architecture_M1h_Phase_Front_Field_Chart_Consumer_Artifact_Only_Test_Benchmark_Plan.md': NEXT_PLAN,
}

DURABLE = [
    '.agents/Directional/Future_Chat_Session_Handoff.md',
    '.agents/Directional/REORIENTATION_PLAN.md',
    '.agents/Directional/Regression_Root_Cause_Tracker.md',
    'MILESTONE_G_TODO.md',
    'TODO',
]


def read(path):
    return (ROOT / path).read_text()


def write(path, text):
    (ROOT / path).write_text(text)


def replace_once(text, old, new, label):
    count = text.count(old)
    if count != 1:
        raise RuntimeError(f'{label}: expected exactly one occurrence, found {count}')
    return text.replace(old, new, 1)


# Globally redirect stale per-turn references to retained current authority.
for path in DURABLE:
    text = read(path)
    for old, new in STALE.items():
        text = text.replace(old, new)
    write(path, text)

# Handoff: replace only the live resume prefix; retain durable historical facts below.
path = '.agents/Directional/Future_Chat_Session_Handoff.md'
text = read(path)
marker = '## M1g immutable acceptance authority'
if marker not in text:
    raise RuntimeError('handoff M1g marker missing')
suffix = text[text.index(marker):]
prefix = f'''# Future Chat Session Handoff

## Mandatory next turn

Run **M1h Phase-Front Field-Chart Test-Authority Remediation — Code + Build only** under:

`{NEXT_PLAN}`

Repository: `akashskypatel/Directional`, branch `agent/surface_cell_quad/p5-recover-bridge-healing`. Draft PR #8 stays open, draft, and unmerged. Product gate **G4 topology-distinct completion and singularities** remains active. M1a through M1g are immutable accepted. M1h production code is compile/package complete but **runtime acceptance is blocked by one invalid focused-test witness**. Review policy is `never`.

The blocked immutable runtime turn consumed exact M1h artifacts `9066967620 / 9066968049` for implementation `de4e2ba7c19d2e49931655dc22d758f50656d054`. Package authority passed exactly: result/log ZIPs `16d04835f9186b94fbb1ab987c5cd0bebd801daa7f368d01dc58139f67f5fe03 / d6fa10a4b188b5569dfc73008c1a6e8a6f3a4e51f64cf4232a568087b36ac816`, recursive manifest **69/69** `63c7000e00cf8608861d1651d84c02ddf419581dd7763ba25a9b3837162b92c9`, producer discovery **202**, validation **77/77**, M1a **14/14**, T1 **29/29**. M1g/M1f/M1e/M1d/M1c/M1b focused preservation all remained green. Direct Plane/MultiFaceSeam/CloseSheets/Cylinder passed from arbitrary extraction with **no fixture symlink**, proving the sibling `../test-data` package lookup correction.

M1h focused result is **5/6**. The only failure is `SurfaceCellPhaseFrontFieldChartAuthorityMigration.MultipleOrientationChartsPreserveEstablishedNumbering`: it expected producer charts `{{0,1,2}}` to all occur among `LocalLatticeState` cell-corner samples, but the existing fixture produces lattice-corner charts `{{0,2}}` while independently retaining producer/segment chart `1` on face `3` and chart `2` on face `10`. The fixture therefore conflates **producer chart-domain coverage** with **lattice occurrence coverage**. Do not weaken the test to accept `{{0,2}}`; repair the witness so producer numbering and actual occurrence identity are proved separately.

Required-green producer accounting was exactly **187 = 186 pass + the same one M1h test failure**. All eight historical/deferred red classes were unchanged. Strict-validator timing characterized **0/10 pass, 10/10 fail** and remains the existing deferred sub-millisecond ratio defect. Bunny/Vase were not relaunched after the blocking focused failure; entering accepted M1g dispositions remain authoritative until the corrected M1h package reaches immutable runtime.

No new stable product regression event or recurrence is assigned. Historical totals remain **34 events / 14 categories / 20 recurrences**; `PR8-R034 / G4-R007` remains active. M1h `RP-01 / RP-05` acceptance remains pending.

Current retained runtime report:
`{REPORT}`.

Authoritative next plan:
`{NEXT_PLAN}`.

Procedural lesson: aggregate GoogleTest filters use exactly one positive/negative separator: `positive-negative1:negative2:...`; the first malformed repeated-dash filter was discarded as harness evidence and did not mutate the package.

'''
write(path, prefix + suffix)

# TODO: replace live status prefix only.
path = 'TODO'
text = read(path)
match = re.search(r'^Last updated:.*?^## M1d immutable acceptance', text, flags=re.S | re.M)
if not match:
    raise RuntimeError('TODO live-status block not found')
new = f'''Last updated: 2026-08-10 UTC

## Active direction

- Phase: P5 — producer-correct direct surface paving.
- Product gate: **G4 topology-distinct completion and singularities active**.
- Test architecture: **T1 independent oracle/package foundation accepted**.
- Architecture migration: **M1a through M1g immutable accepted; M1h field-chart production compiled but runtime blocked by a focused test-authority defect**.
- M1h immutable package: implementation `de4e2ba7c19d2e49931655dc22d758f50656d054`, artifacts `9066967620 / 9066968049`, manifest **69/69**, producer discovery **202**.
- M1h runtime: **5/6 focused**, required-green **186/187** with the same sole focused-test failure; M1g–M1b focused preservation green; validation **77/77**, M1a **14/14**, T1 **29/29**.
- Direct Plane/MultiFaceSeam/CloseSheets/Cylinder remain green without a fixture symlink; eight historical/deferred red classes unchanged.
- Blocking defect: `MultipleOrientationChartsPreserveEstablishedNumbering` incorrectly requires every producer chart to appear among lattice-corner occurrences. Producer chart `1` is still independently observed on face `3`; do not weaken expected chart-domain semantics to `{{0,2}}`.
- Authoritative next turn: `{NEXT_PLAN}`.
- Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`; draft PR #8 stays open/unmerged; review policy `never`.
- Current runtime report: `{REPORT}`.

## M1d immutable acceptance'''
text = text[:match.start()] + new + text[match.end():]
write(path, text)

# MILESTONE_G_TODO: update live gate and next-turn section.
path = 'MILESTONE_G_TODO.md'
text = read(path)
text = text.replace(
    'Production remains known-red on direct torus. T1 independent authority and M1a through M1g architecture slices are immutable accepted. M1h Phase-Front Field-Chart Consumer Code + Build is next. Architecture migration remains separate from G4 product acceptance.',
    'Production remains known-red on direct torus. T1 independent authority and M1a through M1g architecture slices are immutable accepted. M1h production code is compile/package complete, but immutable runtime is blocked by one focused test-authority defect. Architecture migration remains separate from G4 product acceptance.')
pattern = re.compile(r'## Authoritative next turn\n\n.*?(?=## M1f vertex-continuation transport)', re.S)
replacement = f'''## M1h runtime block and authoritative next turn

Exact M1h artifacts `9066967620 / 9066968049` passed immutable package authority, producer discovery **202**, all entering focused preservation, validation **77/77**, M1a **14/14**, T1 **29/29**, four direct products without fixture symlink, and unchanged historical-red classes. M1h focused is **5/6** and required-green is **186/187**, both blocked only by `MultipleOrientationChartsPreserveEstablishedNumbering`.

Diagnosis: the existing multi-orientation fixture retains producer chart numbering `{{0,1,2}}`, including compatibility chart `1` on face `3` and chart `2` on face `10`, but its accepted lattice corners sample only charts `{{0,2}}`. The test incorrectly treats producer-domain coverage as lattice-occurrence coverage. This is a test-authority defect, not a product regression. Do not change the chart-domain expectation to `{{0,2}}`; repair the witness.

Run **M1h Phase-Front Field-Chart Test-Authority Remediation — Code + Build only** under:

`{NEXT_PLAN}`

The remediation is expected to be test-only. Production M1h source and the runtime-proven sibling `../test-data` fixture lookup remain unchanged unless source inspection proves a real semantic contradiction. Compile/package only; execute no generated Directional binary.

Current report: `{REPORT}`.

'''
text, count = pattern.subn(replacement, text, count=1)
if count != 1:
    raise RuntimeError(f'MILESTONE next-turn section count={count}')
write(path, text)

# REORIENTATION_PLAN: keep M1 active and record blocked M1h acceptance.
path = '.agents/Directional/REORIENTATION_PLAN.md'
text = read(path)
text = text.replace('M1h phase-front field-chart consumer [next]', 'M1h phase-front field-chart consumer [runtime blocked; test-authority remediation next]')
pattern = re.compile(r'### M1g immutable acceptance and M1h selection\n\n.*?(?=## 5\. Required target-stage corrections)', re.S)
replacement = f'''### M1g immutable acceptance and M1h runtime block

M1g implementation `ee1abbd91d8ab39b84b107bba73ebf7aa0acceb2` remains immutable accepted. M1h production implementation `de4e2ba7c19d2e49931655dc22d758f50656d054` compiled/package successfully at `build_planar_phase_frame -> UniformPhaseFrame::faceChart -> LocalLatticeState::sourceChart`, including the sibling `../test-data` package lookup correction.

Exact M1h runtime from artifact `9066967620` discovered **202** producer tests. Five of six M1h focused contracts passed; all M1g–M1b focused preservation, validation **77/77**, M1a **14/14**, T1 **29/29**, four direct products, package portability, and eight historical/deferred red classes were preserved. Required-green was **186/187** with the same sole M1h failure.

The failure is test-authority, not production behavior: `MultipleOrientationChartsPreserveEstablishedNumbering` assumes all producer charts must appear among accepted lattice-corner occurrences. The fixture independently retains chart domain `{{0,1,2}}` but samples lattice corners only on `{{0,2}}`. M1h `RP-01 / RP-05` therefore remains runtime pending until the witness is corrected and a fresh immutable package passes all six contracts.

Current evidence: `{REPORT}`.

Next plan: `{NEXT_PLAN}`.

Do not advance to another M1 consumer, M2, or G4 repair before corrected M1h immutable acceptance.

'''
text, count = pattern.subn(replacement, text, count=1)
if count != 1:
    raise RuntimeError(f'REORIENTATION M1h section count={count}')
write(path, text)

# Regression tracker: no new stable regression; record the test-authority block.
path = '.agents/Directional/Regression_Root_Cause_Tracker.md'
text = read(path)
text = re.sub(r'Last updated: \*\*2026-08-10 UTC\*\* after .*?\.',
              'Last updated: **2026-08-10 UTC** after blocked M1h immutable runtime from artifact `9066967620`; test-authority remediation is next.',
              text, count=1)
text = text.replace(
    'M1h compile artifact `9066967620` creates no stable product regression event from compile-only evidence; semantic acceptance remains pending.',
    'M1h artifact `9066967620` creates no stable product regression event: immutable runtime is blocked by one newly introduced focused test-authority witness, while all entering product/preservation authority remained unchanged. Semantic acceptance remains pending.')
text = text.replace(
    'Focused migration tests do not replace this authority. M1g preservation passed exact artifact execution from `9053047653`. M1h adds six focused contracts, but `RP-02 / TA-05` preservation remains pending until exact artifact runtime.',
    'Focused migration tests do not replace this authority. M1g preservation passed exact artifact execution from `9053047653`. M1h exact artifact runtime preserved entering `RP-02 / TA-05` authority but the new M1h suite is **5/6** because `MultipleOrientationChartsPreserveEstablishedNumbering` conflates producer chart-domain coverage with lattice-corner occurrence coverage. Required-green is **186/187** with that same sole failure. No stable product regression event or recurrence is added; M1h acceptance remains blocked until the test witness is corrected and re-run from a fresh immutable package.')
insert = f'''\n### M1h blocked runtime / test-authority record\n\n- implementation: `de4e2ba7c19d2e49931655dc22d758f50656d054`; artifact `9066967620`; manifest **69/69**; producer discovery **202**;\n- focused: **5/6**; sole failure `MultipleOrientationChartsPreserveEstablishedNumbering`;\n- required-green: **186/187**, same sole failure;\n- M1g/M1f/M1e/M1d/M1c/M1b focused preservation green; validation **77/77**; M1a **14/14**; T1 **29/29**;\n- direct products green from arbitrary extraction with no fixture symlink; historical/deferred red classes unchanged;\n- diagnosis: fixture samples lattice-corner chart IDs `{{0,2}}` while producer/segment authority still proves chart domain `{{0,1,2}}`; test incorrectly equates producer-domain and occurrence coverage;\n- disposition: **test-authority defect, not stable product regression**; historical totals remain **34 / 14 / 20**; `PR8-R034 / G4-R007` remains active;\n- next: `{NEXT_PLAN}`.\n\n'''
anchor = '### M1g immutable accepted pattern record'
if anchor not in text:
    raise RuntimeError('regression M1g anchor missing')
text = text.replace(anchor, insert + anchor, 1)
write(path, text)

# Remove consumed/stale per-turn artifacts only after facts are folded into durable authority.
for stale in STALE:
    p = ROOT / stale
    if p.exists():
        p.unlink()

# Final integrity checks: retained report/plan exist; no stale refs survive in live status docs.
if not (ROOT / REPORT).is_file() or not (ROOT / NEXT_PLAN).is_file():
    raise RuntimeError('retained report/plan missing')
for path in DURABLE:
    text = read(path)
    for stale in STALE:
        if stale in text:
            raise RuntimeError(f'stale reference {stale} remains in {path}')

print('M1h blocked runtime closeout payload applied')
