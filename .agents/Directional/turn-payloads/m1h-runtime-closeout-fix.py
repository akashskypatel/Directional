from pathlib import Path
p = Path('.agents/Directional/Regression_Root_Cause_Tracker.md')
s = p.read_text()
old = '### RP-03 — policy/stage state conflation\n### RP-03 — policy/stage state conflation\n'
if s.count(old) != 1:
    raise SystemExit(f'expected one duplicated RP-03 heading, found {s.count(old)}')
p.write_text(s.replace(old, '### RP-03 — policy/stage state conflation\n', 1))
print('removed duplicated RP-03 heading only')
