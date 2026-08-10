from pathlib import Path
fixes = {
    Path('TODO'): (
        '## M1d immutable acceptance\n## M1d immutable acceptance\n',
        '## M1d immutable acceptance\n'),
    Path('MILESTONE_G_TODO.md'): (
        '## M1f vertex-continuation transport — immutable accepted\n## M1f vertex-continuation transport — immutable accepted\n',
        '## M1f vertex-continuation transport — immutable accepted\n'),
}
for path, (old, new) in fixes.items():
    s = path.read_text()
    if s.count(old) != 1:
        raise SystemExit(f'{path}: expected one duplicate heading pair, found {s.count(old)}')
    path.write_text(s.replace(old, new, 1))
    print(f'fixed duplicate heading in {path}')
