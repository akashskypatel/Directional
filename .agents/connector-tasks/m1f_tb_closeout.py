from pathlib import Path
import re

M1F_REPORT = '.agents/Directional/Architecture_M1f_Vertex_Continuation_Route_Transport_Consumer_Artifact_Only_Test_Benchmark_Report.md'
M1G_PLAN = '.agents/Directional/Architecture_M1g_Periodic_Holonomy_Route_Transport_Consumer_Code_Build_Plan.md'
M1E_REPORT = '.agents/Directional/Architecture_M1e_Segment_Route_Transport_Consumer_Artifact_Only_Test_Benchmark_Report.md'
M1F_CB_REPORT = '.agents/Directional/Architecture_M1f_Vertex_Continuation_Route_Transport_Consumer_Code_Build_Report.md'
M1F_TB_PLAN = '.agents/Directional/Architecture_M1f_Vertex_Continuation_Route_Transport_Consumer_Artifact_Only_Test_Benchmark_Plan.md'


def read(path):
    return Path(path).read_text()


def write(path, text):
    Path(path).write_text(text)
    print('updated', path)


def replace_once(text, old, new, label):
    count = text.count(old)
    if count != 1:
        raise SystemExit(f'{label}: expected one exact match, found {count}')
    return text.replace(old, new, 1)


def replace_all(text, old, new, label):
    count = text.count(old)
    if count < 1:
        raise SystemExit(f'{label}: no matches')
    print(label, 'matches', count)
    return text.replace(old, new)


def sub_once(text, pattern, replacement, label):
    out, count = re.subn(pattern, replacement, text, count=1, flags=re.S)
    if count != 1:
        raise SystemExit(f'{label}: expected one regex match, found {count}')
    return out


# Future handoff: preserve durable body; update only live/current-state and references.
path = '.agents/Directional/Future_Chat_Session_Handoff.md'
t = read(path)
old = '''## Mandatory next turn\n\nRun **M1f Vertex Continuation Route Transport Consumer — immutable Test + Benchmark only** under:\n\n`.agents/Directional/Architecture_M1f_Vertex_Continuation_Route_Transport_Consumer_Artifact_Only_Test_Benchmark_Plan.md`\n\nConsume only immutable result/log artifacts `9050850344 / 9050850513` produced from implementation `baed0f24831c476f45a1b742c12314e3fb03e10e`. Repository: `akashskypatel/Directional`, branch `agent/surface_cell_quad/p5-recover-bridge-healing`. Draft PR #8 stays open, draft, and unmerged. Product gate **G4 topology-distinct completion and singularities** remains active. M1a/M1b/M1c/M1d/M1e remain immutable accepted; M1f is compile/package complete and runtime-pending. Review policy is `never`.\n\nThis next turn may execute packaged binaries but may not edit source/tests/fixtures/build logic, configure, compile, relink, regenerate discovery, repair packaged content, or substitute an artifact. Long/resource-heavy cases may use narrowly scoped GitHub Actions under the durable workflow policy below, but remote execution does not relax artifact-only authority.\n'''
new = '''## Mandatory next turn\n\nRun **M1g Periodic Holonomy Route Transport Consumer — Code + Build only** under:\n\n`.agents/Directional/Architecture_M1g_Periodic_Holonomy_Route_Transport_Consumer_Code_Build_Plan.md`\n\nRepository: `akashskypatel/Directional`, branch `agent/surface_cell_quad/p5-recover-bridge-healing`. Draft PR #8 stays open, draft, and unmerged. Product gate **G4 topology-distinct completion and singularities** remains active. M1a/M1b/M1c/M1d/M1e/M1f are immutable accepted. Review policy is `never`.\n\nM1g migrates only the separate periodic whole-cycle `totalMatching` transport accumulator to the accepted checked route/`GridAutomorphism` algebra. It is representation-only: preserve canonical face-cycle discovery/order, `PeriodicHolonomyMismatch` rejection semantics, legacy matching behavior, public `SurfacePeriodicHolonomy` compatibility output, lattice translation/cut-route behavior, G4 outcomes, and unresolved `G4-B003` nonzero periodic Z4 capability. Code + Build may edit/configure/compile/package but may execute no generated Directional binary, discovery, test, benchmark, `ctest`, CLI/GUI/help/version command, fuzzer, or custom input.\n'''
t = replace_once(t, old, new, 'handoff mandatory next')
t = replace_once(t, '## M1f compile/package authority — immutable runtime pending', '## M1f compile/package authority — historical accepted build', 'handoff m1f heading')
old = f'''Current Code + Build report:\n`{M1F_CB_REPORT}`.\n'''
new = f'''The superseded Code + Build report has been folded into the current immutable M1f report:\n`{M1F_REPORT}`.\n\n## M1f immutable acceptance authority\n\nExact artifact-only validation accepted implementation `baed0f24831c476f45a1b742c12314e3fb03e10e`: producer discovery **190**, M1f **6/6**, required-green producer **175/175**, M1e/M1d/M1c/M1b preservation, validation **77/77**, M1a **14/14**, T1 **29/29**, and direct Plane/MultiFaceSeam/CloseSheets/Cylinder independent-oracle gates all passed. Bunny preserved the known `NotProductionReady:completion traceSegments=170831 arrangementCells=0 completedQuads=0` failure after independent-oracle rejection; Vase reached `[ RUN ]` and remained bounded safety-only at 60 seconds. Strict-validator timing remained nondeterministic at **9/10 pass, 1/10 fail** in fresh M1f characterization. Local and remote postflight preserved exact artifact/package authority.\n\nRemote heavy-case evidence: run `31357556834`; Bunny job/artifact `93360001159 / 9051190671` (`04c1c9a74dd5c0d104006230180043d7d0eed6a22812379558138c4c4b7fcadf`), Vase job/artifact `93360001142 / 9051188086` (`84cf33ee9ef469c33b149a0e4a77620df13207d991a89f73ed5c6c2c9da06750`). The temporary runtime workflow was removed before its trigger.\n\nA non-blocking package metadata defect was found: `metadata/direct-product-test-names.txt` contains stale nonexistent non-parameterized names for MultiFaceSeam and CloseSheets. Runtime authority used the accepted parameterized independent-oracle product tests; the next Code + Build plan corrects only this packaging metadata.\n\nCurrent immutable report:\n`{M1F_REPORT}`.\n'''
t = replace_once(t, old, new, 'handoff m1f report block')
t = replace_all(t, M1E_REPORT, M1F_REPORT, 'handoff stale m1e report refs')
t = replace_all(t, M1F_TB_PLAN, M1G_PLAN, 'handoff stale m1f tb plan refs')
t = t.replace(M1F_CB_REPORT, M1F_REPORT)
t = replace_once(t,
    'At the start of immutable M1f Test + Benchmark, fetch fresh PR/head and artifact state; verify implementation `baed0f24831c476f45a1b742c12314e3fb03e10e` remains an ancestor and artifacts `9050850344 / 9050850513` remain unexpired with exact declared digests. Do not assume this handoff\'s documentation head if external commits move the branch.',
    'At the start of M1g Code + Build, fetch fresh PR/head state; verify accepted M1f implementation `baed0f24831c476f45a1b742c12314e3fb03e10e` remains an ancestor, then inspect the current periodic whole-cycle transport owner before editing. Do not assume this handoff\'s documentation head if external commits move the branch.',
    'handoff start instruction')
t = replace_once(t,
    'If immutable M1f validation finds any required-green semantic or preservation regression, remain at M1f and return to corrective Code + Build. Do not advance to periodic whole-cycle holonomy, production `FieldChartId`, M2, or G4 remediation until M1f is accepted.',
    'If M1g inspection shows the periodic face-cycle path no longer owns the raw cumulative transport described by the authoritative plan, stop and revise the plan rather than migrating a different owner. M1g must not implement nonzero periodic Z4 support; `G4-B003` remains a separate product blocker.',
    'handoff stop instruction')
write(path, t)

# TODO: narrow current-state substitutions and append accepted evidence.
path = 'TODO'
t = read(path)
t = replace_once(t,
    '- Architecture migration: **M1a/M1b/M1c/M1d/M1e immutable accepted; M1f Vertex Continuation Route Transport Consumer compile/package complete, immutable runtime next**.',
    '- Architecture migration: **M1a/M1b/M1c/M1d/M1e/M1f immutable accepted; M1g Periodic Holonomy Route Transport Consumer Code + Build next**.',
    'todo active migration')
t = replace_once(t,
    '- Authoritative next turn: `.agents/Directional/Architecture_M1f_Vertex_Continuation_Route_Transport_Consumer_Artifact_Only_Test_Benchmark_Plan.md`.',
    f'- Authoritative next turn: `{M1G_PLAN}`.',
    'todo next plan')
t = replace_all(t, M1E_REPORT, M1F_REPORT, 'todo stale m1e report refs')
t = t.replace(M1F_CB_REPORT, M1F_REPORT).replace(M1F_TB_PLAN, M1G_PLAN)
t = replace_once(t, '## M1f compile/package checkpoint', '## M1f immutable acceptance checkpoint', 'todo m1f heading')
t = replace_once(t,
    'Implementation `baed0f24831c476f45a1b742c12314e3fb03e10e` compiled **120/120** under run/job `31356131866 / 93356062724` without generated Directional runtime. Immutable artifacts are `9050850344 / 9050850513`; the package manifest is **59/59** with SHA-256 `3607c79873f45d035e6b1339288ed26582007a9068768da167abc603c376059e`. Six focused M1f contracts are compiled and runtime-pending. Expected immutable discovery/required-green counts are **190 / 175**.',
    'Implementation `baed0f24831c476f45a1b742c12314e3fb03e10e` is immutable accepted from artifacts `9050850344 / 9050850513`: producer discovery **190**, M1f focused **6/6**, required-green producer **175/175**, validation **77/77**, M1a **14/14**, T1 **29/29**, and all four direct products green and independent-oracle clean. Bunny remains known-red, Vase bounded safety-only, and exact postflight preserved **59/59** package checksums.',
    'todo m1f acceptance text')
t = replace_once(t,
    'Current Code + Build report: `.agents/Directional/Architecture_M1f_Vertex_Continuation_Route_Transport_Consumer_Code_Build_Report.md`.',
    f'Current immutable report: `{M1F_REPORT}`. Next Code + Build: `{M1G_PLAN}`. The next build must also correct the stale MultiFaceSeam/CloseSheets names in packaged `metadata/direct-product-test-names.txt` without product-behavior changes.',
    'todo report link')
t = t.replace('M1f checked continuation-step domains **compile-complete; runtime pending**', 'M1f checked continuation-step domains **accepted**')
t = t.replace('M1f continuation route identity/orientation **compile-complete; runtime pending**', 'M1f continuation route identity/orientation **accepted**')
t = t.replace('M1f typed cumulative continuation-route composition **compile-complete; runtime pending**', 'M1f typed cumulative continuation-route composition **accepted**')
t = t.replace('independent authority preserved through M1e; M1f preservation pending exact artifact-only validation', 'independent authority preserved through exact M1f artifact-only validation')
t = replace_once(t,
    '- Strict-validator timing remains deferred: the exact M1e artifact produced **6/10 pass, 4/10 fail** across fresh repetitions, classifying the sub-millisecond 5% timing gate as nondeterministic rather than stable product evidence.',
    '- Strict-validator timing remains deferred: M1e produced **6/10 pass, 4/10 fail** and M1f produced **9/10 pass, 1/10 fail** across fresh repetitions, confirming the sub-millisecond 5% timing gate is nondeterministic rather than stable product evidence.',
    'todo timing')
write(path, t)

# Milestone G live status.
path = 'MILESTONE_G_TODO.md'
t = read(path)
t = replace_once(t,
    'Production remains known-red on direct torus. T1 independent authority and M1a/M1b/M1c/M1d/M1e architecture slices are immutable accepted. M1f Vertex Continuation Route Transport Consumer is compile/package complete and immutable runtime is next. Architecture migration remains separate from G4 product acceptance.',
    'Production remains known-red on direct torus. T1 independent authority and M1a/M1b/M1c/M1d/M1e/M1f architecture slices are immutable accepted. M1g Periodic Holonomy Route Transport Consumer Code + Build is next. Architecture migration remains separate from G4 product acceptance.',
    'milestone active')
t = replace_all(t, M1E_REPORT, M1F_REPORT, 'milestone stale m1e report refs')
t = t.replace(M1F_CB_REPORT, M1F_REPORT).replace(M1F_TB_PLAN, M1G_PLAN)
t = sub_once(t,
    r'## Authoritative next turn\n\nRun \*\*M1f Vertex Continuation Route Transport Consumer — immutable Test \+ Benchmark only\*\* under:.*?(?=\n## M1f vertex-continuation transport)',
    f'''## Authoritative next turn\n\nRun **M1g Periodic Holonomy Route Transport Consumer — Code + Build only** under:\n\n`{M1G_PLAN}`\n\nM1g migrates only the separate periodic whole-cycle `totalMatching` transport owner to checked typed route algebra while preserving current zero-rotation `PeriodicHolonomyMismatch` rejection semantics and leaving `G4-B003` unresolved. No generated Directional binary may execute during Code + Build.\n''',
    'milestone next section')
t = replace_once(t, '## M1f vertex-continuation transport — compile/package complete', '## M1f vertex-continuation transport — immutable accepted', 'milestone m1f heading')
t = replace_once(t,
    'Final implementation `baed0f24831c476f45a1b742c12314e3fb03e10e` compiled **120/120** in run/job `31356131866 / 93356062724` with `runtimeExecution=false`. Result/log artifacts `9050850344 / 9050850513` have ZIP SHA-256 `a2ac9f21cae7f3496a9ffd7cade8b550b5c8e1de57c91d693dde5ece4fcd499f / 3f5595a14d7c2b8c8931772fbdb770c9bc1944b211710ccc4939f2fc1dd54c99`; recursive manifest is **59/59**, `3607c79873f45d035e6b1339288ed26582007a9068768da167abc603c376059e`. Six M1f contracts are compiled but unexecuted.\n\nRun immutable Test + Benchmark only under `.agents/Directional/Architecture_M1f_Vertex_Continuation_Route_Transport_Consumer_Artifact_Only_Test_Benchmark_Plan.md`. Expected producer discovery is **190** and required-green segment **175/175**. Long/resource-heavy Bunny/Vase or other bounded runtime cases may use temporary artifact-only GitHub workflows under the durable policy.',
    f'Final implementation `baed0f24831c476f45a1b742c12314e3fb03e10e` is immutable accepted from artifacts `9050850344 / 9050850513`: producer discovery **190**, M1f **6/6**, required-green **175/175**, M1e/M1d/M1c/M1b preservation, validation **77/77**, M1a **14/14**, T1 **29/29**, and Plane/MultiFaceSeam/CloseSheets/Cylinder independent-oracle gates passed. Bunny preserved `NotProductionReady:completion`, Vase was bounded safety-only at 60 seconds, and local/remote postflight preserved exact **59/59** package authority. Current report: `{M1F_REPORT}`. A checksum-valid but stale direct-product metadata-name defect is deferred to the next Code + Build packaging correction.',
    'milestone m1f acceptance body')
t = t.replace('M1f continuation-step domains **compile-complete/runtime-pending**', 'M1f continuation-step domains **accepted**')
t = t.replace('M1f continuation route identity/orientation **compile-complete/runtime-pending**', 'M1f continuation route identity/orientation **accepted**')
t = t.replace('M1f continuation transport **compile-complete/runtime-pending**', 'M1f continuation transport **accepted**')
t = t.replace('M1f preservation pending exact artifact-only validation', 'M1f preservation accepted under exact artifact-only validation')
t = replace_once(t,
    '- Strict-validator timing is nondeterministic under the exact M1e artifact (**6/10 pass, 4/10 fail**) and remains a deferred performance-test defect; no threshold/retry workaround is authorized.',
    '- Strict-validator timing remains nondeterministic: M1e **6/10 pass, 4/10 fail**; M1f **9/10 pass, 1/10 fail**. It remains a deferred performance-test defect; no threshold/retry workaround is authorized.',
    'milestone timing')
# Core references: stale paths already replaced; ensure next plan is present.
write(path, t)

# Reorientation roadmap: update status while preserving the roadmap content.
path = '.agents/Directional/REORIENTATION_PLAN.md'
t = read(path)
t = replace_once(t,
    '   M1f vertex continuation route transport consumer [compile/package complete; runtime pending]\n   later bounded M1 consumers [pending]',
    '   M1f vertex continuation route transport consumer [accepted]\n   M1g periodic holonomy route transport consumer [next]\n   later bounded M1 consumers [pending]',
    'reorientation ladder')
t = replace_all(t, M1E_REPORT, M1F_REPORT, 'reorientation stale m1e refs')
t = t.replace(M1F_TB_PLAN, M1G_PLAN)
t = replace_once(t, '### M1f compile/package checkpoint', '### M1f immutable acceptance and M1g selection', 'reorientation m1f heading')
t = replace_once(t,
    'Implementation `baed0f24831c476f45a1b742c12314e3fb03e10e` replaces `PathState::matching` unrestricted signed accumulation with checked step authority, `TransitionStep`, `CanonicalRoute`, and typed `GridAutomorphism` composition while preserving route search/ranking and compatibility output. Compile/package run `31356131866 / 93356062724` completed **120/120** with immutable artifact `9050850344`, manifest **59/59** `3607c79873f45d035e6b1339288ed26582007a9068768da167abc603c376059e`, and no generated runtime. M1f remains unaccepted until exact artifact-only semantic validation.\n\nThe first compile attempt surfaced a namespace-ownership mistake in a new provenance forward declaration. The correction kept the existing anonymous helper untouched and introduced a narrow continuation-owned provenance helper, avoiding unrelated ownership refactoring.',
    f'Implementation `baed0f24831c476f45a1b742c12314e3fb03e10e` replaces `PathState::matching` unrestricted signed accumulation with checked step authority, `TransitionStep`, `CanonicalRoute`, and typed `GridAutomorphism` composition while preserving route search/ranking and compatibility output. Exact artifact-only validation accepted M1f: producer **190**, focused **6/6**, required-green **175/175**, validation **77/77**, M1a **14/14**, T1 **29/29**, direct products oracle-clean, Bunny known-red preserved, Vase bounded safety-only, and exact postflight clean. Current evidence: `{M1F_REPORT}`.\n\nThe first compile attempt surfaced a namespace-ownership mistake in a new provenance forward declaration. The correction kept the existing anonymous helper untouched and introduced a narrow continuation-owned provenance helper, avoiding unrelated ownership refactoring. Fresh accepted-source inspection selects the separate periodic face-cycle `totalMatching` accumulator as M1g. M1g is representation-only and must preserve current nonzero-rotation `PeriodicHolonomyMismatch` rejection so `G4-B003` remains unresolved.',
    'reorientation m1f body')
write(path, t)

# Regression tracker: accept M1f, preserve historical totals, identify M1g next RP-07 owner.
path = '.agents/Directional/Regression_Root_Cause_Tracker.md'
t = read(path)
t = replace_once(t,
    'Last updated: **2026-08-10 UTC** after M1f compile/package artifact `9050850344`; immutable runtime remains pending.',
    'Last updated: **2026-08-10 UTC** after immutable M1f acceptance from artifact `9050850344`; M1g periodic whole-cycle transport is next.',
    'regression updated')
t = replace_once(t,
    'T1 artifacts `9040549377 / 9041289209`, accepted M1a artifact `9041930767`, accepted M1b artifact `9042940168`, accepted M1c artifact `9043971772`, accepted M1d artifact `9046308272`, and M1e artifact `9049125645` and compile-only M1f artifact `9050850344` create no new production regression event or recurrence. M1e runtime authority is accepted; M1f runtime authority is pending. `PR8-R034 / G4-R007` remains active.',
    'T1 artifacts `9040549377 / 9041289209`, accepted M1a artifact `9041930767`, accepted M1b artifact `9042940168`, accepted M1c artifact `9043971772`, accepted M1d artifact `9046308272`, accepted M1e artifact `9049125645`, and accepted M1f artifact `9050850344` create no new production regression event or recurrence. M1f runtime authority is accepted. `PR8-R034 / G4-R007` remains active.',
    'regression authority line')
t = t.replace('M1e ordered segment-route step identity is accepted. M1f continuation-route steps cross checked source-vertex/interior-transition boundaries before `TransitionStep` construction; compile/package is complete and runtime acceptance is pending.', 'M1e ordered segment-route step identity is accepted. M1f continuation-route steps cross checked source-vertex/interior-transition boundaries before `TransitionStep` construction and immutable runtime acceptance is complete.')
t = replace_once(t, '`RP-02 / TA-05` remains **test-authority resolved and preserved through M1e** under immutable artifact execution:', '`RP-02 / TA-05` remains **test-authority resolved and preserved through M1f** under immutable artifact execution:', 'regression rp02 heading')
t = t.replace('- producer discovery exactly **184**;\n- required-green producer segment **169/169**;', '- producer discovery exactly **190**;\n- required-green producer segment **175/175**;')
t = t.replace('M1e or M1f focused tests may not replace this authority. M1f preservation is pending exact artifact execution.', 'Focused M1e/M1f tests do not replace this authority. M1f preservation passed exact artifact execution.')
t = t.replace('Untouched by M1a–M1e. Vase remains bounded safety-only evidence. M1e added no search/retry loop; M1f must preserve this.', 'Untouched by M1a–M1f. Vase remains bounded safety-only evidence. M1e/M1f added no search/retry loop.')
t = t.replace('- M1e routes each step through canonical `SourceEdgeTopologyKey` + `InteriorTransitionId`; observed route orientation is preserved through `CanonicalRoute::oriented_steps()` rather than canonical storage order becoming behavioral order. Immutable runtime is accepted.', '- M1e routes each step through canonical `SourceEdgeTopologyKey` + `InteriorTransitionId`; observed route orientation is preserved through `CanonicalRoute::oriented_steps()` rather than canonical storage order becoming behavioral order. Immutable runtime is accepted.\n- M1f applies the same semantic identity/orientation boundary to ordered vertex-continuation routes and is immutable accepted.')
t = t.replace('M1f now compiles the same typed algebra at `resolve_vertex_continuation`; immutable runtime is pending. The separate periodic-holonomy accumulation remains outside M1e/M1f.', 'M1f is immutable accepted with the same typed algebra at `resolve_vertex_continuation`. The separate periodic whole-cycle `totalMatching` accumulator remains the next RP-07 owner and is selected for M1g; nonzero periodic Z4 support remains out of scope.')
t = replace_all(t, M1E_REPORT, M1F_REPORT, 'regression stale m1e refs')
t = sub_once(t,
    r'## M1f compile-complete pattern record — runtime pending\n.*?(?=\n## Current G4 stable-ID mapping)',
    f'''## M1f immutable accepted pattern record\n\n| Pattern | Accepted result | Immutable proof |\n|---|---|---|\n| `RP-01` | checked source vertices + compact interior transitions per continuation step | M1f **6/6** + complete producer preservation |\n| `RP-05` | canonical source-edge topology and observed/canonical route-order boundary | forward/reverse and signed-equivalence contracts passed |\n| `RP-07` | typed `GridAutomorphism` composition replaces `PathState::matching += transition.matching` | nonzero multi-step/inverse/equivalence/legacy contracts passed |\n| `RP-02 / TA-05` | direct production-consumer fixtures plus preserved independent product/oracle authority | producer **190**, required-green **175/175**, validation **77/77**, M1a **14/14**, T1 **29/29**, four direct products green |\n\nM1f immutable authority:\n\n- implementation `baed0f24831c476f45a1b742c12314e3fb03e10e`;\n- build run/job `31356131866 / 93356062724`, **120/120**;\n- result artifact `9050850344`, ZIP SHA-256 `a2ac9f21cae7f3496a9ffd7cade8b550b5c8e1de57c91d693dde5ece4fcd499f`;\n- log artifact `9050850513`, ZIP SHA-256 `3f5595a14d7c2b8c8931772fbdb770c9bc1944b211710ccc4939f2fc1dd54c99`;\n- manifest **59/59**, `3607c79873f45d035e6b1339288ed26582007a9068768da167abc603c376059e`;\n- M1f **6/6**, required-green **175/175**, M1e/M1d/M1c/M1b preservation, validation **77/77**, M1a **14/14**, T1 **29/29**;\n- Plane/MultiFaceSeam/CloseSheets/Cylinder independent-oracle clean;\n- Bunny known-red preserved and Vase bounded safety-only under remote run `31357556834`;\n- strict-validator characterization **9/10 pass, 1/10 fail**, retaining the existing nondeterministic performance-test defect;\n- report `{M1F_REPORT}`.\n\nNo new stable regression event or recurrence is assigned. Historical totals remain **34 / 14 / 20**.\n\n### M1g next RP-07 boundary\n\nFresh inspection of accepted M1f source selects the periodic canonical-face-cycle whole-route accumulator (`totalMatching += directed matching`, then `normalized_branch(totalMatching)`) as the next real transport owner. M1g must migrate only this representation to checked route algebra while preserving current `PeriodicHolonomyMismatch` rejection for nonzero cycle rotation. `G4-B003` remains a separate unresolved product capability and must not be synthetically closed by architecture migration.\n''',
    'regression m1f section')
write(path, t)

# Remove only superseded temporary per-turn evidence after current facts are durable.
for stale in (M1E_REPORT, M1F_CB_REPORT, M1F_TB_PLAN):
    p = Path(stale)
    if not p.exists():
        raise SystemExit(f'missing expected stale evidence: {stale}')
    p.unlink()
    print('removed stale evidence', stale)

# Audit current-head live docs for stale per-turn paths.
for live in [
    '.agents/Directional/Future_Chat_Session_Handoff.md',
    'TODO', 'MILESTONE_G_TODO.md',
    '.agents/Directional/REORIENTATION_PLAN.md',
    '.agents/Directional/Regression_Root_Cause_Tracker.md']:
    text = read(live)
    for stale in (M1E_REPORT, M1F_CB_REPORT, M1F_TB_PLAN):
        if stale in text:
            raise SystemExit(f'{live}: stale current-head reference remains: {stale}')
    if M1F_REPORT not in text or M1G_PLAN not in text:
        raise SystemExit(f'{live}: missing current report/next-plan reference')

print('M1f Test+Benchmark documentation closeout prepared')
