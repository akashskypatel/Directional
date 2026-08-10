from pathlib import Path
p = Path('.agents/Directional/Future_Chat_Session_Handoff.md')
s = p.read_text()
old = '`${ runner.temp }`/`$RUNNER_TEMP`'
new = '`${{ runner.temp }}`/`$RUNNER_TEMP`'
if s.count(old) != 1:
    raise SystemExit(f'expected one handoff expression, got {s.count(old)}')
p.write_text(s.replace(old, new, 1))
