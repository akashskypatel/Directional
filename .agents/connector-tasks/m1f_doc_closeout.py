from pathlib import Path

REPORT = '.agents/Directional/Architecture_M1f_Vertex_Continuation_Route_Transport_Consumer_Code_Build_Report.md'
NEXT_PLAN = '.agents/Directional/Architecture_M1f_Vertex_Continuation_Route_Transport_Consumer_Artifact_Only_Test_Benchmark_Plan.md'
OLD_PLAN = '.agents/Directional/Architecture_M1f_Vertex_Continuation_Route_Transport_Consumer_Code_Build_Plan.md'
M1E_REPORT = '.agents/Directional/Architecture_M1e_Segment_Route_Transport_Consumer_Artifact_Only_Test_Benchmark_Report.md'


def replace_required(text, old, new, path):
    count = text.count(old)
    if count < 1:
        raise SystemExit(f'{path}: missing required text {old!r}')
    return text.replace(old, new)

# Handoff: remove stale resume references while preserving all durable policy.
p = Path('.agents/Directional/Future_Chat_Session_Handoff.md')
t = p.read_text()
t = t.replace(f'- `{OLD_PLAN}`;\n', '')
dup = f'- `{M1E_REPORT}`;\n- `{M1E_REPORT}`;\n'
t = t.replace(dup, f'- `{M1E_REPORT}`;\n')
core_anchor = f'- `{M1E_REPORT}`;\n'
if f'- `{REPORT}`;' not in t:
    t = t.replace(core_anchor, core_anchor + f'- `{REPORT}`;\n- `{NEXT_PLAN}`;\n', 1)
t = replace_required(
    t,
    "At the start of M1f Code + Build, fetch fresh PR/head state; verify accepted M1e implementation `a0330d0107f7d7340e9f8644d26dd6c8b753ff10` remains an ancestor, then inspect the current `resolve_vertex_continuation` owner before editing. Do not assume this handoff's documentation head if external commits move the branch.",
    "At the start of immutable M1f Test + Benchmark, fetch fresh PR/head and artifact state; verify implementation `baed0f24831c476f45a1b742c12314e3fb03e10e` remains an ancestor and artifacts `9050850344 / 9050850513` remain unexpired with exact declared digests. Do not assume this handoff's documentation head if external commits move the branch.", p)
t = replace_required(
    t,
    "If M1f inspection shows the selected continuation consumer no longer owns the raw cumulative transport described by the authoritative plan, stop and revise the plan rather than migrating a different owner. After a successful compile/package-only M1f turn, the next turn is immutable Test + Benchmark against that exact artifact.",
    "If immutable M1f validation finds any required-green semantic or preservation regression, remain at M1f and return to corrective Code + Build. Do not advance to periodic whole-cycle holonomy, production `FieldChartId`, M2, or G4 remediation until M1f is accepted.", p)
p.write_text(t)
print('updated', p)

# Milestone G: authoritative next turn and references must point to artifact-only validation.
p = Path('MILESTONE_G_TODO.md')
t = p.read_text()
old = f'''## Authoritative next turn

Run **M1f Vertex Continuation Route Transport Consumer — Code + Build only** under:

`{OLD_PLAN}`.

M1f is intentionally limited to the real `resolve_vertex_continuation` ordered source-vertex route transport owner. It must preserve continuation path discovery/ranking and defer periodic whole-cycle holonomy, `FieldChartId`, M2–M6, and G4 remediation.
'''
new = f'''## Authoritative next turn

Run **M1f Vertex Continuation Route Transport Consumer — immutable Test + Benchmark only** under:

`{NEXT_PLAN}`.

Consume only immutable artifacts `9050850344 / 9050850513`. Rebuild, relink, regeneration, product/test/build/fixture edits, repair, and artifact substitution are prohibited. M1f remains runtime-pending until the focused, complete producer, preservation, direct-product, and immutable postflight gates pass.
'''
t = replace_required(t, old, new, p)
t = t.replace(f'- `{OLD_PLAN}`;\n', '')
if f'- `{REPORT}`;' not in t:
    marker = f'- `{M1E_REPORT}`;\n'
    t = t.replace(marker, marker + f'- `{REPORT}`;\n- `{NEXT_PLAN}`;\n', 1)
t = t.replace('- `RP-02 / TA-05`: exact producer/M1d/M1c/M1b/M1a/T1/direct authority preserved through immutable M1e validation.', '- `RP-02 / TA-05`: exact producer/M1d/M1c/M1b/M1a/T1/direct authority preserved through immutable M1e validation; M1f preservation pending exact artifact-only validation.')
p.write_text(t)
print('updated', p)

# Reorientation roadmap: current authority and next plan label.
p = Path('.agents/Directional/REORIENTATION_PLAN.md')
t = p.read_text()
t = replace_required(t,
    f'Authoritative next Code + Build plan:\n`{OLD_PLAN}`.',
    f'Authoritative next immutable Test + Benchmark plan:\n`{NEXT_PLAN}`.', p)
p.write_text(t)
print('updated', p)
