from pathlib import Path

base = Path('.agents/Directional/turn-payloads/m1h-remediation-build-closeout.py')
try:
    exec(compile(base.read_text(), str(base), 'exec'), {})
except SystemExit as exc:
    expected = '.agents/Directional/Regression_Root_Cause_Tracker.md: next artifact plan not referenced'
    if str(exc) != expected:
        raise

tracker = Path('.agents/Directional/Regression_Root_Cause_Tracker.md')
text = tracker.read_text()
needle = 'No stable product regression event or recurrence is added; M1h acceptance remains pending immutable runtime.'
replacement = needle + '\n\nAuthoritative next immutable runtime plan: `.agents/Directional/Architecture_M1h_Phase_Front_Field_Chart_Test_Authority_Remediation_Artifact_Only_Test_Benchmark_Plan.md`.'
if text.count(needle) != 1:
    raise SystemExit(f'expected one tracker insertion point, got {text.count(needle)}')
tracker.write_text(text.replace(needle, replacement, 1))

plan = '.agents/Directional/Architecture_M1h_Phase_Front_Field_Chart_Test_Authority_Remediation_Artifact_Only_Test_Benchmark_Plan.md'
for path in [
    '.agents/Directional/Future_Chat_Session_Handoff.md',
    '.agents/Directional/REORIENTATION_PLAN.md',
    '.agents/Directional/Regression_Root_Cause_Tracker.md',
    'MILESTONE_G_TODO.md',
    'TODO',
]:
    if plan not in Path(path).read_text():
        raise SystemExit(f'{path}: next artifact plan not referenced after repair')

print('closeout payload v2 applied surgically')
