#!/usr/bin/env python3
"""Directional documentation drift audit. Read-only; Python standard library.

Usage:
  python .agents/Directional/tools/document_drift_audit.py --root .
  python .agents/Directional/tools/document_drift_audit.py --root . --base origin/master
  python .agents/Directional/tools/document_drift_audit.py --root . --base HEAD~1 --json
  python .agents/Directional/tools/document_drift_audit.py --self-test

No modification, restore, git fetch, compile, runtime, or network operation occurs.
Exit: 0 no errors (warnings permitted), 1 errors (or warnings with --strict),
      2 invalid invocation / unreadable repository.
"""
import argparse
import json
import re
import subprocess
import sys
import tempfile
from pathlib import Path
from urllib.parse import unquote, urlsplit

DOC = '.agents/Directional/'
LANDING = {
    DOC + 'ROADMAP.md': (16000, ('## At a glance', '## Completed checkpoints', '## Now', '## Next')),
    DOC + 'ORIENTATION.md': (24000, ('## 1. What the project is', '## 3. Where we are',
                                  '## 4. Fixtures and witnesses', '## 7. Open problems',
                                  '## 8. Recurring defect patterns')),
    DOC + 'Future_Chat_Session_Handoff.md': (16000, ('## Purpose', '## Policies',
                                                   '## Current immutable authority',
                                                   '## Mandatory next turn', '## Turn Sequence',
                                                   '## Context Load Plan', '## Resume-critical lessons')),
    DOC + 'Future_Chat_Session_Handoff_Template.md': (16000, ('## Purpose', '## Policies',
                                                            '## Current immutable authority',
                                                            '## Mandatory next turn', '## Turn Sequence',
                                                            '## Context Load Plan', '## Resume-critical lessons')),
}
POLICY_FILES = (
    'Turn_Cadence.md', 'AGENT_POLICY.md', 'Mandatory_Start_Checklist.md',
    'CLEAN_UP_POLICY.md', 'Durable_Handoff_Policy.md', 'GitHub_Workflow_Policy.md',
    'GMP_COMPILE_POLICY.md', 'RETENTION_POLICY.md', 'REVIEW_TURN_POLICY.md',
    'TOOL_USE_CONSERVATION_POLICY.md', 'Patch_Application_Strategy.md',
    'Mandatory_End_Checklist.md',
)
CORE_PROTECTED = {DOC + name for name in POLICY_FILES} | {
    DOC + 'Future_Chat_Session_Handoff.md',
    DOC + 'Future_Chat_Session_Handoff_Template.md',
    DOC + 'DESIGN.md', DOC + 'REORIENTATION_PLAN.md',
    DOC + 'ORIENTATION.md', DOC + 'ROADMAP.md',
}
LOCAL_LINK = re.compile(r'(?<!!)\[[^\]\n]+\]\(([^\n)]+)(?:\s+"[^"]*")?\)')
HEADING = re.compile(r'^#{1,6}\s+(.+?)\s*$', re.M)
ACTIVE = re.compile(r'^#{1,3}\s+(?:CURRENT\b|Current\s*[-—:]|Resume-critical update\b)', re.M)
STATUS_KEY = re.compile(r'^(Turn|Status|Successor):\s*(.*?)\s*$', re.M)


def git(root, *args):
    result = subprocess.run(['git', '-C', str(root), *args], capture_output=True, text=True)
    if result.returncode:
        raise ValueError('git ' + ' '.join(args) + ': ' + result.stderr.strip())
    return result.stdout


def readable(root, rel):
    path = root / rel
    return path.read_text(encoding='utf-8') if path.is_file() else None


def mask_code(text):
    # Code fences are examples, not operative links or headings.
    text = re.sub(r'^\s*(```|~~~).*?^\s*\1[^\n]*$', '', text, flags=re.M | re.S)
    return text


def check(root, base=None):
    findings = []

    def add(level, code, path, message, line=None):
        findings.append(dict(severity=level, code=code, path=path,
                             line=line, message=message))

    template_path = DOC + 'Future_Chat_Session_Handoff_Template.md'
    template = readable(root, template_path)
    if template is None:
        add('error', 'MISSING_TEMPLATE', template_path, 'Required handoff template is absent.')
    else:
        for name in POLICY_FILES:
            if DOC + name not in template.replace('\\', '/'):
                add('error', 'TEMPLATE_POLICY', template_path,
                    f'Template omits or misnames protected policy {name}.')

    for rel, (limit, required) in LANDING.items():
        text = readable(root, rel)
        if text is None:
            add('error', 'MISSING_LANDING', rel, 'Required living document is missing.')
            continue
        nbytes = len(text.encode('utf-8'))
        if nbytes > limit:
            add('warning' if nbytes <= limit * 2 else 'error', 'DOCUMENT_BLOAT', rel,
                f'{nbytes} bytes exceeds {limit}-byte orientation budget; examine for copied history.')
        lines = text.splitlines()
        headings = [l.strip() for l in lines if re.match(r'^#{1,6} ', l)]
        for prefix in required:
            if not any(h.startswith(prefix) for h in headings):
                add('error', 'MISSING_SECTION', rel, f'Required structural section absent: {prefix}.')
        stripped = mask_code(text)
        matches = list(ACTIVE.finditer(stripped))
        if matches:
            add('error', 'APPENDED_HISTORY', rel,
                f'{len(matches)} historical CURRENT/resume header(s); replace the single live section in place.',
                stripped.count('\n', 0, matches[0].start()) + 1)
        names = [h.group(1).strip().casefold() for h in HEADING.finditer(stripped)]
        duplicates = {h for h in names if names.count(h) > 1}
        # Duplicate headings within a short living document obscure currency; headings in long archives are excluded.
        for h in sorted(duplicates):
            add('warning', 'DUPLICATE_HEADING', rel, f'Repeated heading: {h}')
        for m in LOCAL_LINK.finditer(stripped):
            target = m.group(1).strip().strip('<>')
            parsed = urlsplit(target)
            if parsed.scheme or parsed.netloc or target.startswith(('#', 'mailto:', 'data:')):
                continue
            # Avoid interpreting navigation examples or URL-like tokens as filesystem paths.
            fpath = unquote(parsed.path).replace('\\', '/')
            if not fpath or fpath.startswith('//'):
                continue
            resolved = (root / rel).parent / fpath
            if not resolved.exists():
                line = stripped.count('\n', 0, m.start()) + 1
                add('error', 'BROKEN_LINK', rel, f'Local Markdown target not found: {target}', line)

    handoff_path = DOC + 'Future_Chat_Session_Handoff.md'
    handoff = readable(root, handoff_path)
    status_path = root / 'STATUS'
    if handoff is not None:
        for name in POLICY_FILES:
            if DOC + name not in handoff.replace('\\', '/'):
                add('error', 'HANDOFF_POLICY', handoff_path, f'Missing mandatory policy reference: {name}')
        if 'DURABLE, DO NOT DELETE' not in handoff:
            add('error', 'DURABLE_MARKER', handoff_path, 'Required durable protection marker absent.')
        if status_path.is_file():
            values = dict(STATUS_KEY.findall(status_path.read_text(encoding='utf-8')))
            if not {'Turn', 'Status', 'Successor'} <= values.keys():
                add('warning', 'STATUS_FORMAT', 'STATUS', 'Turn, Status, or Successor missing.')
            elif values['Status'] == 'COMPLETE' and values['Successor'] not in ('UNKNOWN', ''):
                section = handoff.split('## Mandatory next turn', 1)
                snippet = section[1].split('\n## ', 1)[0] if len(section) == 2 else ''
                if values['Successor'] not in snippet:
                    add('error', 'SUCCESSOR_MISMATCH', handoff_path,
                        'Root STATUS declares a successor absent from the mandatory next-turn section.')

    for name in POLICY_FILES:
        if not (root / DOC / name).is_file():
            add('error', 'MISSING_POLICY', DOC + name, 'Mandatory policy file absent.')

    if base:
        try:
            names = git(root, 'diff', '--name-only', base, '--').splitlines()
            baseline = set(git(root, 'ls-tree', '-r', '--name-only', base).splitlines())
            current = set(git(root, 'ls-files').splitlines())
            changed = set(names) | (baseline - current)
            for rel in sorted(changed):
                protected = rel in CORE_PROTECTED or bool(re.search(
                    r'(^|/)M[1-9].*Closure_Record\.md$|Frozen_Definitions\.md$|Required_Green_Selector_.*\.txt$', rel))
                if not protected:
                    continue
                if rel in baseline and not (root / rel).exists():
                    add('error', 'PROTECTED_REMOVAL', rel,
                        'Protected file removed; explicit owner authorization and content preservation must be reviewed.')
                    continue
                if rel not in baseline:
                    continue
                add('warning', 'PROTECTED_CHANGE', rel,
                    'A protected document changed; obtain evidence of explicit user authorization (not inferred by this tool).')
                before = git(root, 'show', f'{base}:{rel}')
                after = readable(root, rel) or ''
                preserved = [h.group(1) for h in HEADING.finditer(before)
                             if 'DURABLE' in h.group(1).upper() or 'DO NOT DELETE' in h.group(1).upper()]
                new_h = {h.group(1) for h in HEADING.finditer(after)}
                for old_heading in preserved:
                    if old_heading not in new_h:
                        add('error', 'LOST_DURABLE_SECTION', rel,
                            f'Protected heading removed/renamed: {old_heading[:100]}')
        except ValueError as exc:
            add('error', 'INVALID_BASE', '(git)', str(exc))

    # Semantic agreement is deliberately NOT inferred from words such as PASS/CLOSED in archives.
    return sorted(findings, key=lambda f: (f['path'], f['line'] or 0, f['code']))


def self_test():
    with tempfile.TemporaryDirectory() as td:
        root = Path(td)
        (root / DOC).mkdir(parents=True)
        for name in POLICY_FILES:
            (root / DOC / name).write_text('# Policy\n', encoding='utf-8')
        tpl = '\n'.join([f'## {x}' for x in ('Purpose', 'Policies', 'Current immutable authority',
                 'Mandatory next turn', 'Turn Sequence', 'Context Load Plan', 'Resume-critical lessons')])
        tpl += '\n' + '\n'.join(DOC + p for p in POLICY_FILES)
        (root / DOC / 'Future_Chat_Session_Handoff_Template.md').write_text(tpl, encoding='utf-8')
        (root / DOC / 'Future_Chat_Session_Handoff.md').write_text(tpl + '\nDURABLE, DO NOT DELETE\n', encoding='utf-8')
        (root / DOC / 'ORIENTATION.md').write_text('\n'.join(LANDING[DOC+'ORIENTATION.md'][1]), encoding='utf-8')
        (root / DOC / 'ROADMAP.md').write_text('\n'.join(LANDING[DOC+'ROADMAP.md'][1]), encoding='utf-8')
        assert not check(root), 'clean fake documentation should pass'
        p = root / DOC / 'ROADMAP.md'
        p.write_text(p.read_text()+'\n## CURRENT — old\n[old](missing.md)\n', encoding='utf-8')
        assert {'APPENDED_HISTORY', 'BROKEN_LINK'} <= {x['code'] for x in check(root)}
        (root / 'STATUS').write_text('Turn: done\nStatus: COMPLETE\nSuccessor: NEXT-TURN\n')
        assert 'SUCCESSOR_MISMATCH' in {x['code'] for x in check(root)}
    print('self-test: PASS (clean, appended history, broken link, successor mismatch)')


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--root', type=Path, default=Path('.'), help='Repository working-tree root')
    ap.add_argument('--base', help='Optional git ref to compare protected docs against, e.g. origin/master')
    ap.add_argument('--strict', action='store_true', help='Also fail on warnings; useful for review gating')
    ap.add_argument('--json', action='store_true', help='Emit machine-readable findings')
    ap.add_argument('--self-test', action='store_true', help='Run built-in offline smoke tests')
    args = ap.parse_args()
    if args.self_test:
        self_test()
        return 0
    root = args.root.resolve()
    if not (root / DOC).is_dir():
        print(f'Not a Directional repository root: {root}', file=sys.stderr)
        return 2
    findings = check(root, args.base)
    if args.json:
        print(json.dumps({'findings': findings, 'error_count': sum(f['severity']=='error' for f in findings),
                          'warning_count': sum(f['severity']=='warning' for f in findings)}, indent=2))
    else:
        for f in findings:
            print(f"{f['severity'].upper()} {f['code']} {f['path']}" +
                  (f":{f['line']}" if f['line'] else '') + f": {f['message']}")
        print(f"Audit: {sum(f['severity']=='error' for f in findings)} error(s), "
              f"{sum(f['severity']=='warning' for f in findings)} warning(s).")
    return int(any(f['severity']=='error' or args.strict for f in findings))


if __name__ == '__main__':
    sys.exit(main())
