from pathlib import Path
import re

REPORT = '.agents/Directional/Architecture_M1f_Vertex_Continuation_Route_Transport_Consumer_Code_Build_Report.md'
NEXT_PLAN = '.agents/Directional/Architecture_M1f_Vertex_Continuation_Route_Transport_Consumer_Artifact_Only_Test_Benchmark_Plan.md'
IMPL = 'baed0f24831c476f45a1b742c12314e3fb03e10e'
RUN = '31356131866 / 93356062724'
RESULT = '9050850344'
LOG = '9050850513'
MANIFEST = '3607c79873f45d035e6b1339288ed26582007a9068768da167abc603c376059e'


def write(path, text):
    Path(path).write_text(text)
    print('updated', path)


def require_replace(text, old, new, path):
    count = text.count(old)
    if count < 1:
        raise SystemExit(f'{path}: missing required text: {old[:120]!r}')
    return text.replace(old, new)

# Handoff: replace only the live mandatory block and add current compile authority.
p = '.agents/Directional/Future_Chat_Session_Handoff.md'
t = Path(p).read_text()
pattern = re.compile(r'## Mandatory next turn\n.*?(?=## M1e immutable acceptance authority)', re.S)
if not pattern.search(t):
    raise SystemExit(f'{p}: mandatory block not found')
mandatory = f'''## Mandatory next turn

Run **M1f Vertex Continuation Route Transport Consumer — immutable Test + Benchmark only** under:

`{NEXT_PLAN}`

Consume only immutable result/log artifacts `{RESULT} / {LOG}` produced from implementation `{IMPL}`. Repository: `akashskypatel/Directional`, branch `agent/surface_cell_quad/p5-recover-bridge-healing`. Draft PR #8 stays open, draft, and unmerged. Product gate **G4 topology-distinct completion and singularities** remains active. M1a/M1b/M1c/M1d/M1e remain immutable accepted; M1f is compile/package complete and runtime-pending. Review policy is `never`.

This next turn may execute packaged binaries but may not edit source/tests/fixtures/build logic, configure, compile, relink, regenerate discovery, repair packaged content, or substitute an artifact. Long/resource-heavy cases may use narrowly scoped GitHub Actions under the durable workflow policy below, but remote execution does not relax artifact-only authority.

## M1f compile/package authority — immutable runtime pending

Selected seam:
`surface_cell_tracing_detail::resolve_vertex_continuation -> ordered source-vertex continuation route`.

| Evidence | Value |
|---|---|
| implementation | `{IMPL}` |
| build run/job | `{RUN}` |
| result artifact / SHA-256 | `{RESULT}` / `a2ac9f21cae7f3496a9ffd7cade8b550b5c8e1de57c91d693dde5ece4fcd499f` |
| log artifact / SHA-256 | `{LOG}` / `3f5595a14d7c2b8c8931772fbdb770c9bc1944b211710ccc4939f2fc1dd54c99` |
| recursive manifest | **59/59**, `{MANIFEST}` |
| package | **60** regular files including `SHA256SUMS`; 7 executables; 2 static libraries; 27 fixtures |
| build | **120/120**, Release/static/Ninja/PRE_TEST, **8:50.14**, peak RSS **1,848,704 KiB** |
| runtime | **false** |

M1f replaces `PathState::matching` raw signed accumulation with checked source-step identity, `TransitionStep`, `CanonicalRoute`, and typed `GridAutomorphism` composition in observed route order. It preserves fan/path discovery, branch resolution, ranking, failure semantics, public compatibility representation, the separate periodic whole-cycle holonomy accumulator, `FieldChartId`, M2–M6, and G4 behavior.

Exactly six `SurfaceCellVertexContinuationRouteTransportAuthorityMigration` contracts are compiled but unexecuted. The expected next-turn producer discovery is **190** and required-green producer segment is **175/175**. The first compile attempt `17afbfd8baf0d369d9136534c0a11784ca0dca10` failed because a forward declaration crossed the existing anonymous-namespace helper ownership boundary; the surgical correction introduced a local continuation provenance helper and compiled successfully without changing accepted M1e authority.

Current Code + Build report:
`{REPORT}`.

'''
t = pattern.sub(mandatory, t, count=1)
write(p, t)

# TODO live status.
p = 'TODO'
t = Path(p).read_text()
t = require_replace(t,
    '- Architecture migration: **M1a/M1b/M1c/M1d/M1e immutable accepted; M1f Vertex Continuation Route Transport Consumer Code + Build next**.',
    '- Architecture migration: **M1a/M1b/M1c/M1d/M1e immutable accepted; M1f Vertex Continuation Route Transport Consumer compile/package complete, immutable runtime next**.', p)
t = require_replace(t,
    '- Authoritative next turn: `.agents/Directional/Architecture_M1f_Vertex_Continuation_Route_Transport_Consumer_Code_Build_Plan.md`.',
    f'- Authoritative next turn: `{NEXT_PLAN}`.', p)
anchor = '## Regression status\n'
section = f'''## M1f compile/package checkpoint

Selected seam:
`surface_cell_tracing_detail::resolve_vertex_continuation -> ordered source-vertex continuation route`.

Implementation `{IMPL}` compiled **120/120** under run/job `{RUN}` without generated Directional runtime. Immutable artifacts are `{RESULT} / {LOG}`; the package manifest is **59/59** with SHA-256 `{MANIFEST}`. Six focused M1f contracts are compiled and runtime-pending. Expected immutable discovery/required-green counts are **190 / 175**.

The first compile-only implementation `17afbfd8baf0d369d9136534c0a11784ca0dca10` exposed a namespace-ownership ambiguity in `source_edge_provenance`; the correction was source-local and compiled successfully. No new stable regression event or recurrence was created.

Current Code + Build report: `{REPORT}`.

'''
if '## M1f compile/package checkpoint' not in t:
    if anchor not in t: raise SystemExit(f'{p}: regression anchor missing')
    t = t.replace(anchor, section + anchor, 1)
t = t.replace('- `RP-01`: checked M1e step domains **accepted**.', '- `RP-01`: M1e accepted; M1f checked continuation-step domains **compile-complete; runtime pending**.')
t = t.replace('- `RP-05`: M1e semantic step identity and observed/canonical route-order boundary **accepted**.', '- `RP-05`: M1e accepted; M1f continuation route identity/orientation **compile-complete; runtime pending**.')
t = t.replace('- `RP-07`: M1e typed cumulative route composition **accepted**.', '- `RP-07`: M1e accepted; M1f typed cumulative continuation-route composition **compile-complete; runtime pending**.')
t = t.replace('- `RP-02 / TA-05`: independent authority preserved through exact M1e artifact-only validation.', '- `RP-02 / TA-05`: independent authority preserved through M1e; M1f preservation pending exact artifact-only validation.')
write(p, t)

# Milestone G live status.
p = 'MILESTONE_G_TODO.md'
t = Path(p).read_text()
t = require_replace(t,
    'Production remains known-red on direct torus. T1 independent authority and M1a/M1b/M1c/M1d/M1e architecture slices are immutable accepted. M1f Vertex Continuation Route Transport Consumer is the next Code + Build slice. Architecture migration remains separate from G4 product acceptance.',
    'Production remains known-red on direct torus. T1 independent authority and M1a/M1b/M1c/M1d/M1e architecture slices are immutable accepted. M1f Vertex Continuation Route Transport Consumer is compile/package complete and immutable runtime is next. Architecture migration remains separate from G4 product acceptance.', p)
anchor = '## Regression disposition\n'
section = f'''## M1f vertex-continuation transport — compile/package complete

Selected boundary:
`surface_cell_tracing_detail::resolve_vertex_continuation -> ordered source-vertex continuation route`.

Final implementation `{IMPL}` compiled **120/120** in run/job `{RUN}` with `runtimeExecution=false`. Result/log artifacts `{RESULT} / {LOG}` have ZIP SHA-256 `a2ac9f21cae7f3496a9ffd7cade8b550b5c8e1de57c91d693dde5ece4fcd499f / 3f5595a14d7c2b8c8931772fbdb770c9bc1944b211710ccc4939f2fc1dd54c99`; recursive manifest is **59/59**, `{MANIFEST}`. Six M1f contracts are compiled but unexecuted.

Run immutable Test + Benchmark only under `{NEXT_PLAN}`. Expected producer discovery is **190** and required-green segment **175/175**. Long/resource-heavy Bunny/Vase or other bounded runtime cases may use temporary artifact-only GitHub workflows under the durable policy.

'''
if '## M1f vertex-continuation transport — compile/package complete' not in t:
    if anchor not in t: raise SystemExit(f'{p}: regression anchor missing')
    t = t.replace(anchor, section + anchor, 1)
t = t.replace('M1e checked step domains **accepted**.', 'M1e checked step domains **accepted**; M1f continuation-step domains **compile-complete/runtime-pending**.')
t = t.replace('M1e semantic step identity and observed/canonical route order **accepted**.', 'M1e semantic step identity and observed/canonical route order **accepted**; M1f continuation route identity/orientation **compile-complete/runtime-pending**.')
t = t.replace('M1e cumulative ordered-route transport **accepted**.', 'M1e cumulative ordered-route transport **accepted**; M1f continuation transport **compile-complete/runtime-pending**.')
t = t.replace('preserved through M1e immutable validation.', 'preserved through M1e immutable validation; M1f preservation pending immutable validation.')
write(p, t)

# Reorientation roadmap.
p = '.agents/Directional/REORIENTATION_PLAN.md'
t = Path(p).read_text()
t = t.replace('   M1f vertex continuation route transport consumer [next Code + Build]', '   M1f vertex continuation route transport consumer [compile/package complete; runtime pending]')
anchor = '## 5. Required target-stage corrections\n'
section = f'''### M1f compile/package checkpoint

M1f selects the next real cumulative transport owner:

`surface_cell_tracing_detail::resolve_vertex_continuation -> ordered source-vertex continuation route`.

Implementation `{IMPL}` replaces `PathState::matching` unrestricted signed accumulation with checked step authority, `TransitionStep`, `CanonicalRoute`, and typed `GridAutomorphism` composition while preserving route search/ranking and compatibility output. Compile/package run `{RUN}` completed **120/120** with immutable artifact `{RESULT}`, manifest **59/59** `{MANIFEST}`, and no generated runtime. M1f remains unaccepted until exact artifact-only semantic validation.

The first compile attempt surfaced a namespace-ownership mistake in a new provenance forward declaration. The correction kept the existing anonymous helper untouched and introduced a narrow continuation-owned provenance helper, avoiding unrelated ownership refactoring.

'''
if '### M1f compile/package checkpoint' not in t:
    if anchor not in t: raise SystemExit(f'{p}: target-stage anchor missing')
    t = t.replace(anchor, section + anchor, 1)
t = t.replace('Continue bounded consumers only. Post-M1e source inspection identified `resolve_vertex_continuation` as the next narrow real owner of cumulative ordered route transport; M1f migrates that consumer without changing path discovery/ranking.', 'Continue bounded consumers only. `resolve_vertex_continuation` is now M1f compile/package complete at the cumulative ordered route transport owner without changing path discovery/ranking; immutable runtime validation is the next gate.')
write(p, t)

# Regression tracker.
p = '.agents/Directional/Regression_Root_Cause_Tracker.md'
t = Path(p).read_text()
t = re.sub(r'Last updated: \*\*2026-08-10 UTC\*\*[^\n]*', 'Last updated: **2026-08-10 UTC** after M1f compile/package artifact `9050850344`; immutable runtime remains pending.', t, count=1)
t = t.replace('M1e artifact `9049125645` create no new production regression event or recurrence. M1e runtime authority is accepted.', 'M1e artifact `9049125645` and compile-only M1f artifact `9050850344` create no new production regression event or recurrence. M1e runtime authority is accepted; M1f runtime authority is pending.')
t = t.replace('- M1e ordered segment-route step identity crosses the same checked source-vertex/interior-transition boundaries before `TransitionStep` construction; immutable runtime is accepted.', '- M1e ordered segment-route step identity is accepted. M1f continuation-route steps cross checked source-vertex/interior-transition boundaries before `TransitionStep` construction; compile/package is complete and runtime acceptance is pending.')
t = t.replace('M1e focused tests may not replace this authority.', 'M1e or M1f focused tests may not replace this authority. M1f preservation is pending exact artifact execution.')
t = t.replace('The separate periodic-holonomy accumulation remains outside M1e.', 'M1f now compiles the same typed algebra at `resolve_vertex_continuation`; immutable runtime is pending. The separate periodic-holonomy accumulation remains outside M1e/M1f.')
anchor = '## Current G4 stable-ID mapping\n'
section = f'''## M1f compile-complete pattern record — runtime pending

| Pattern | Compile result | Pending immutable proof |
|---|---|---|
| `RP-01` | checked source vertices + compact interior transitions per continuation step | M1f 6/6 + complete producer preservation |
| `RP-05` | canonical source-edge topology and observed/canonical route-order boundary | forward/reverse and signed-equivalence contracts |
| `RP-07` | typed `GridAutomorphism` composition replaces `PathState::matching += transition.matching` | nonzero multi-step/inverse/equivalence/legacy contracts |
| `RP-02 / TA-05` | direct production-consumer fixtures with hard-authored semantic expectations | producer 190, required-green 175/175, M1e/M1d/M1c/M1b/M1a/T1/direct authority |

M1f compile authority:

- final implementation `{IMPL}`;
- first compile-only attempt `17afbfd8baf0d369d9136534c0a11784ca0dca10` failed on a namespace-ownership ambiguity and was surgically corrected inside the same turn;
- build run/job `{RUN}`, **120/120**;
- result artifact `{RESULT}`, ZIP SHA-256 `a2ac9f21cae7f3496a9ffd7cade8b550b5c8e1de57c91d693dde5ece4fcd499f`;
- log artifact `{LOG}`, ZIP SHA-256 `3f5595a14d7c2b8c8931772fbdb770c9bc1944b211710ccc4939f2fc1dd54c99`;
- manifest **59/59**, `{MANIFEST}`;
- Code + Build executed no generated Directional binary, discovery, test, or benchmark;
- runtime acceptance pending under `{NEXT_PLAN}`.

No new stable regression event or recurrence is assigned for the corrected compile-only namespace mistake because no accepted M1f runtime authority was lost and accepted M1e remained intact.

'''
if '## M1f compile-complete pattern record — runtime pending' not in t:
    if anchor not in t: raise SystemExit(f'{p}: G4 anchor missing')
    t = t.replace(anchor, section + anchor, 1)
t = t.replace('| `AR-02` | M1a/M1b/M1c/M1d/M1e **accepted**; M1f vertex-continuation transport is next |', '| `AR-02` | M1a/M1b/M1c/M1d/M1e **accepted**; M1f vertex-continuation transport compile/package complete, runtime pending |')
t = t.replace('| `AR-03` | strong identity adoption through M1e **accepted**; M1f continues checked step identity at vertex continuation |', '| `AR-03` | strong identity adoption through M1e **accepted**; M1f checked continuation-step identity compile-complete, runtime pending |')
t = t.replace('| `AR-05` | representation boundaries through M1e **accepted**; M1f continues observed/canonical orientation at vertex continuation |', '| `AR-05` | representation boundaries through M1e **accepted**; M1f observed/canonical continuation orientation compile-complete, runtime pending |')
t = t.replace('| `TA-05` | **test authority resolved and preserved through M1e** |', '| `TA-05` | **test authority resolved and preserved through M1e**; M1f preservation pending immutable artifact execution |')
write(p, t)
