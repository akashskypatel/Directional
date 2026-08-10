from pathlib import Path
import re

REPORT = '.agents/Directional/Architecture_M1e_Segment_Route_Transport_Consumer_Artifact_Only_Test_Benchmark_Report.md'
NEXT_PLAN = '.agents/Directional/Architecture_M1f_Vertex_Continuation_Route_Transport_Consumer_Code_Build_Plan.md'
OLD_PATHS = {
    '.agents/Directional/Architecture_M1d_Phase_Front_Route_Identity_Consumer_Artifact_Only_Test_Benchmark_Report.md': REPORT,
    '.agents/Directional/Architecture_M1e_Segment_Route_Transport_Consumer_Code_Build_Report.md': REPORT,
    '.agents/Directional/Architecture_M1e_Segment_Route_Transport_Consumer_Code_Build_Plan.md': NEXT_PLAN,
    '.agents/Directional/Architecture_M1e_Segment_Route_Transport_Consumer_Artifact_Only_Test_Benchmark_Plan.md': NEXT_PLAN,
}
TARGETS = [
    Path('TODO'),
    Path('MILESTONE_G_TODO.md'),
    Path('.agents/Directional/Future_Chat_Session_Handoff.md'),
    Path('.agents/Directional/REORIENTATION_PLAN.md'),
    Path('.agents/Directional/Regression_Root_Cause_Tracker.md'),
]


def replace_required(text: str, old: str, new: str, path: Path, minimum: int = 1) -> str:
    count = text.count(old)
    if count < minimum:
        raise SystemExit(f'{path}: expected at least {minimum} occurrence(s) of {old!r}, found {count}')
    return text.replace(old, new)


for path in TARGETS:
    text = path.read_text()
    for old, new in OLD_PATHS.items():
        text = text.replace(old, new)

    if path.name == 'TODO':
        text = replace_required(
            text,
            '- Architecture migration: **M1a/M1b/M1c/M1d immutable accepted; M1e Segment Route Transport Consumer compile/package complete, immutable runtime next**.',
            '- Architecture migration: **M1a/M1b/M1c/M1d/M1e immutable accepted; M1f Vertex Continuation Route Transport Consumer Code + Build next**.',
            path,
        )
        text = replace_required(
            text,
            '- M1e implementation: `a0330d0107f7d7340e9f8644d26dd6c8b753ff10`; authoritative Release/static/Ninja run/job `31351113129 / 93341993183` completed **120/120** and produced immutable artifacts `9049125645 / 9049125905`. No generated Directional binary ran.',
            '- M1e immutable acceptance: implementation `a0330d0107f7d7340e9f8644d26dd6c8b753ff10`, build run/job `31351113129 / 93341993183`, artifacts `9049125645 / 9049125905`; focused **6/6**, producer required-green **169/169**, validation **77/77**, M1a **14/14**, T1 **29/29**, and Plane/MultiFaceSeam/CloseSheets/Cylinder green and independent-oracle clean.',
            path,
        )
        text = text.replace('**compile-complete; runtime pending**', '**accepted**')
        text = text.replace('pending exact M1e artifact-only validation', 'preserved through exact M1e artifact-only validation')
        marker = '- `PR8-R034 / G4-R007` remains active and unchanged on production artifact `9031804178`.'
        if marker in text and 'Strict-validator timing remains deferred' not in text:
            text = text.replace(
                marker,
                marker + '\n- Strict-validator timing remains deferred: the exact M1e artifact produced **6/10 pass, 4/10 fail** across fresh repetitions, classifying the sub-millisecond 5% timing gate as nondeterministic rather than stable product evidence.',
            )

    elif path.name == 'MILESTONE_G_TODO.md':
        text = replace_required(
            text,
            'Production remains known-red on direct torus. T1 independent authority and M1a/M1b/M1c/M1d architecture slices are immutable accepted. M1e compile/package is complete and immutable runtime is pending. Architecture migration remains separate from G4 product acceptance.',
            'Production remains known-red on direct torus. T1 independent authority and M1a/M1b/M1c/M1d/M1e architecture slices are immutable accepted. M1f Vertex Continuation Route Transport Consumer is the next Code + Build slice. Architecture migration remains separate from G4 product acceptance.',
            path,
        )
        text = text.replace('## M1e compile/package checkpoint and authoritative next turn', '## M1e immutable acceptance and authoritative next turn')
        text = text.replace('M1e is not accepted until immutable runtime passes.', 'M1e immutable runtime passed all required-green gates and is accepted.')
        text = text.replace('**compile-complete; runtime pending**', '**accepted**')
        text = text.replace('pending M1e immutable validation', 'preserved through M1e immutable validation')
        marker = '- `PR8-R034 / G4-R007` remains **active** under production artifact `9031804178`.'
        if marker in text and 'Strict-validator timing is nondeterministic' not in text:
            text = text.replace(
                marker,
                marker + '\n- Strict-validator timing is nondeterministic under the exact M1e artifact (**6/10 pass, 4/10 fail**) and remains a deferred performance-test defect; no threshold/retry workaround is authorized.',
            )

    elif path.name == 'Future_Chat_Session_Handoff.md':
        pattern = re.compile(r'## Mandatory next turn\n.*?(?=## M1e compile/package authority — immutable runtime pending)', re.S)
        replacement = '''## Mandatory next turn

Run **M1f Vertex Continuation Route Transport Consumer — Code + Build only** under:

`.agents/Directional/Architecture_M1f_Vertex_Continuation_Route_Transport_Consumer_Code_Build_Plan.md`

Repository: `akashskypatel/Directional`, branch `agent/surface_cell_quad/p5-recover-bridge-healing`. Draft PR #8 stays open, draft, and unmerged. Product gate **G4 topology-distinct completion and singularities** remains active. M1a/M1b/M1c/M1d/M1e are immutable accepted. Review policy is `never`.

The next turn may edit and compile/package but may execute no generated Directional binary, discovery, test, benchmark, ctest, CLI/GUI/help/version command, fuzzer, or custom input. Before source expansion, synchronize any remaining `REORIENTATION_PLAN.md` / regression-tracker runtime-pending text with the accepted M1e authority.

'''
        if not pattern.search(text):
            raise SystemExit(f'{path}: mandatory-turn block not found')
        text = pattern.sub(replacement, text, count=1)
        text = text.replace('## M1e compile/package authority — immutable runtime pending', '## M1e immutable acceptance authority')
        text = text.replace('## M1e compile-complete consumer boundary', '## M1e accepted consumer boundary')
        text = text.replace('The compile-complete implementation replaces legacy raw signed `transition.matching` accumulation', 'The accepted implementation replaces legacy raw signed `transition.matching` accumulation')
        text = replace_required(
            text,
            "Exactly six `SurfaceCellSegmentRouteTransportAuthorityMigration` production-path contracts are compiled. The immutable turn must execute all six in fresh processes and interpret them under the artifact-only plan's independent expected-value, semantic-key, and malformed-boundary rules. Do not reimplement route composition in test-only helpers as proof.",
            'Exactly six `SurfaceCellSegmentRouteTransportAuthorityMigration` production-path contracts passed **6/6** in fresh processes under independent expected-value, semantic-key, and malformed-boundary rules. Complete producer accounting was **184**, required-green **169/169**, validation **77/77**, M1a **14/14**, T1 **29/29**, and all four direct required-green products remained oracle-clean. The authoritative details are in the current M1e immutable report.',
            path,
        )
        text = replace_required(
            text,
            "At the start of immutable M1e Test + Benchmark, fetch fresh PR/head and artifact state; verify implementation `a0330d0107f7d7340e9f8644d26dd6c8b753ff10` remains an ancestor and artifacts `9049125645 / 9049125905` remain unexpired with exact digests. Do not assume this handoff's documentation head if external commits move the branch.",
            "At the start of M1f Code + Build, fetch fresh PR/head state; verify accepted M1e implementation `a0330d0107f7d7340e9f8644d26dd6c8b753ff10` remains an ancestor, then inspect the current `resolve_vertex_continuation` owner before editing. Do not assume this handoff's documentation head if external commits move the branch.",
            path,
        )
        text = text.replace(
            'If the following immutable M1e turn finds a required-green regression, remain at M1e and return to corrective Code + Build; do not advance.',
            'If M1f inspection shows the selected continuation consumer no longer owns the raw cumulative transport described by the authoritative plan, stop and revise the plan rather than migrating a different owner. After a successful compile/package-only M1f turn, the next turn is immutable Test + Benchmark against that exact artifact.',
        )

    elif path.name == 'REORIENTATION_PLAN.md':
        text = text.replace(
            '   M1e segment route transport consumer [compile/package complete; runtime pending]\n   later bounded M1 consumers [pending]',
            '   M1e segment route transport consumer [accepted]\n   M1f vertex continuation route transport consumer [next Code + Build]\n   later bounded M1 consumers [pending]',
        )
        text = text.replace('M1e Code + Build is complete at:', 'M1e is immutable accepted at:')
        text = text.replace('Compile/package authority:', 'Immutable M1e authority:')
        text = text.replace(
            '- no generated Directional binary, discovery, test, or benchmark executed.\n\nM1e remains unaccepted until immutable runtime. The authoritative next turn is:',
            '- Code + Build executed no generated Directional binary, discovery, test, or benchmark; immutable runtime subsequently passed M1e **6/6**, producer required-green **169/169**, validation **77/77**, M1a **14/14**, T1 **29/29**, and all four direct required-green products.\n\nM1e is accepted. The authoritative current report is:',
        )
        text = text.replace('## 4. M1e rationale and compile-complete boundary', '## 4. M1e accepted boundary and M1f selection')
        text = text.replace('The compile-complete implementation preserves existing public/raw provenance', 'The accepted implementation preserves existing public/raw provenance')
        text = text.replace('Immutable semantic acceptance is pending.', 'Immutable semantic acceptance passed.')
        text = text.replace(
            'M1e focused transport contracts are compiled and must supplement, never replace, producer accounting, M1d/M1c/M1b/M1a/T1 preservation, direct product oracles, known-red classification, and immutable package postflight. Their runtime authority remains pending.',
            'M1e focused transport contracts are accepted and supplemented, rather than replaced, producer accounting, M1d/M1c/M1b/M1a/T1 preservation, direct product oracles, known-red classification, and immutable package postflight. The exact producer accounting is 184 with required-green 169/169.',
        )
        text = replace_required(
            text,
            'Continue bounded consumers only. After immutable M1e acceptance, inspect the remaining real owners before selecting another slice. The periodic-holonomy transport loop and production `FieldChartId` adoption remain possible later M1 candidates, but neither is pre-approved merely by type availability.',
            'Continue bounded consumers only. Post-M1e source inspection identified `resolve_vertex_continuation` as the next narrow real owner of cumulative ordered route transport; M1f migrates that consumer without changing path discovery/ranking. The separate periodic-holonomy transport loop and production `FieldChartId` adoption remain possible later M1 candidates, but neither is pre-approved merely by type availability.',
            path,
        )

    elif path.name == 'Regression_Root_Cause_Tracker.md':
        text = text.replace(
            'Last updated: **2026-08-10 UTC** after M1e compile artifact `9049125645`; immutable runtime remains pending.',
            'Last updated: **2026-08-10 UTC** after immutable M1e artifact validation; M1e is accepted and M1f is next.',
        )
        text = text.replace(
            'compile-only M1e artifact `9049125645` create no new production regression event or recurrence. M1e runtime authority is pending.',
            'M1e artifact `9049125645` create no new production regression event or recurrence. M1e runtime authority is accepted.',
        )
        text = text.replace('compilation/package is complete and runtime acceptance is pending.', 'immutable runtime is accepted.')
        text = text.replace('M1e preservation is pending immutable artifact execution:', 'M1e preservation is accepted under immutable artifact execution:')
        text = text.replace('- producer discovery exactly **178**;\n- required-green producer segment **163/163**;', '- producer discovery exactly **184**;\n- required-green producer segment **169/169**;')
        text = text.replace('Runtime acceptance is pending.', 'Runtime acceptance is complete.')
        text = text.replace('Immutable runtime acceptance is pending.', 'Immutable runtime acceptance is complete.')
        text = text.replace('## M1e compile-complete pattern record — runtime pending', '## M1e immutable accepted pattern record')
        text = text.replace('| Pattern | Compile result | Pending immutable proof |', '| Pattern | Accepted result | Immutable proof |')
        text = text.replace('| `RP-01` | checked source vertices + compact interior transitions at each observed step | exact six focused tests + complete producer preservation |', '| `RP-01` | **accepted** checked source vertices + compact interior transitions at each observed step | M1e 6/6 + complete producer preservation |')
        text = text.replace('| `RP-05` | canonical topology key and semantic route-keyed observations; `oriented_steps()` preserves behavior order | forward/reverse and signed-equivalence contracts |', '| `RP-05` | **accepted** canonical topology key and semantic route-keyed observations; `oriented_steps()` preserves behavior order | forward/reverse and signed-equivalence contracts passed |')
        text = text.replace('| `RP-07` | zero-shift `GridAutomorphism` route composition replaces raw cumulative signed addition | nonzero multi-step/inverse and legacy-path contracts |', '| `RP-07` | **accepted** zero-shift `GridAutomorphism` route composition replaces raw cumulative signed addition | nonzero multi-step/inverse and legacy-path contracts passed |')
        text = text.replace('| `RP-02 / TA-05` | deterministic hard-authored expected values, independent compact IDs, semantic snapshot keys | producer 184, required-green 169/169, M1d/M1c/M1b/M1a/T1/direct evidence |', '| `RP-02 / TA-05` | **preserved** deterministic hard-authored expected values, independent compact IDs, semantic snapshot keys | producer 184, required-green 169/169, M1d/M1c/M1b/M1a/T1/direct evidence |')
        text = text.replace('## M1e compile authority:', '## M1e immutable authority:')
        text = text.replace(
            '- no generated Directional binary, discovery, test, or benchmark executed;\n- report',
            '- Code + Build executed no generated Directional binary, discovery, test, or benchmark;\n- immutable runtime: M1e **6/6**, required-green producer **169/169**, validation **77/77**, M1a **14/14**, T1 **29/29**, direct Plane/MultiFaceSeam/CloseSheets/Cylinder green;\n- strict-validator timing characterization: **6/10 pass, 4/10 fail**, classified nondeterministic and deferred;\n- report',
        )
        text = text.replace('M1a/M1b/M1c/M1d **accepted**; M1e ordered transport-step adoption compile-complete, runtime pending', 'M1a/M1b/M1c/M1d/M1e **accepted**; M1f vertex-continuation transport is next')
        text = text.replace('strong identity adoption through M1d **accepted**; M1e typed step identity compile-complete, runtime pending', 'strong identity adoption through M1e **accepted**; M1f continues checked step identity at vertex continuation')
        text = text.replace('representation boundaries through M1d **accepted**; M1e observed/canonical orientation boundary compile-complete, runtime pending', 'representation boundaries through M1e **accepted**; M1f continues observed/canonical orientation at vertex continuation')
        text = text.replace('**test authority resolved and preserved through M1d**; M1e preservation pending immutable artifact execution', '**test authority resolved and preserved through M1e**')
        text = text.replace('M1a route algebra + M1c edge transport + M1d route identity accepted; M1e production route-composition contracts compiled, runtime pending', 'M1a route algebra + M1c edge transport + M1d route identity + M1e production segment-route composition accepted; M1f continuation-route contracts next')

    path.write_text(text)

# Final stale reference audit over the current durable/current markdown set.
for path in TARGETS:
    text = path.read_text()
    for old in OLD_PATHS:
        if old in text:
            raise SystemExit(f'{path}: stale reference remains: {old}')

print('updated:')
for path in TARGETS:
    print(path)
