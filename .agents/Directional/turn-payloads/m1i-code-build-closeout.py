from pathlib import Path

fixes = {
    Path('.agents/Directional/Future_Chat_Session_Handoff.md'): [
        (
            '## M1h immutable acceptance authority\n## M1h immutable acceptance authority\n',
            '## M1h immutable acceptance authority\n',
        ),
        (
            'Authoritative next plan:\n`.agents/Directional/Architecture_M1i_Phase_Front_Cell_Source_Scope_Consumer_Code_Build_Plan.md`.\n\n## M1g immutable acceptance authority',
            'Historical following plan:\n`.agents/Directional/Architecture_M1i_Phase_Front_Cell_Source_Scope_Consumer_Code_Build_Plan.md`.\n\n## M1g immutable acceptance authority',
        ),
    ],
    Path('TODO'): [
        (
            '## M1d immutable acceptance\n## M1d immutable acceptance\n',
            '## M1d immutable acceptance\n',
        ),
    ],
}
for path, replacements in fixes.items():
    text = path.read_text()
    for old, new in replacements:
        if text.count(old) != 1:
            raise SystemExit(f'{path}: expected one occurrence of cleanup target, found {text.count(old)}')
        text = text.replace(old, new, 1)
    path.write_text(text)
print('M1i closeout heading cleanup applied')
