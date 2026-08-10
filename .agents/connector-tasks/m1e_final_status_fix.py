from pathlib import Path

REPORT = '.agents/Directional/Architecture_M1e_Segment_Route_Transport_Consumer_Artifact_Only_Test_Benchmark_Report.md'
NEXT_PLAN = '.agents/Directional/Architecture_M1f_Vertex_Continuation_Route_Transport_Consumer_Code_Build_Plan.md'


def require_replace(path: Path, old: str, new: str) -> None:
    text = path.read_text()
    count = text.count(old)
    if count != 1:
        raise SystemExit(f'{path}: expected exactly one occurrence of {old!r}, found {count}')
    path.write_text(text.replace(old, new))


roadmap = Path('.agents/Directional/REORIENTATION_PLAN.md')
require_replace(
    roadmap,
    f'M1e is accepted. The authoritative current report is:\n`{NEXT_PLAN}`.\n\nCurrent M1e Code + Build report:\n`{REPORT}`.',
    f'M1e is accepted. The authoritative current report is:\n`{REPORT}`.\n\nAuthoritative next Code + Build plan:\n`{NEXT_PLAN}`.',
)

handoff = Path('.agents/Directional/Future_Chat_Session_Handoff.md')
require_replace(
    handoff,
    f'Code + Build report:\n`{REPORT}`.',
    f'Current immutable report:\n`{REPORT}`.',
)
require_replace(
    handoff,
    f'Authoritative report:\n`{REPORT}`.',
    f'M1d accepted facts are retained in `.agents/Directional/Regression_Root_Cause_Tracker.md` and the current immutable report:\n`{REPORT}`.',
)
text = handoff.read_text()
needle = 'The malformed contract was narrowly corrected after Review: typed construction is unreachable as a distinct failure once derived topology/compact provenance validates, so the test targets the real predecessor `source_edge_provenance` boundary and requires `MissingTransitionProvenance` without fallback. `CrossFieldEdgeTransition::sourceEdge` remains validation metadata, not semantic `InteriorTransitionId`.\n'
if text.count(needle) != 1:
    raise SystemExit('handoff: malformed-contract anchor missing or duplicated')
acceptance = ('\nImmutable runtime acceptance passed M1e focused **6/6**, producer discovery **184**, required-green producer **169/169**, '
              'M1d/M1c/M1b preservation, validation **77/77**, M1a **14/14**, T1 **29/29**, and direct '
              'Plane/MultiFaceSeam/CloseSheets/Cylinder independent-oracle gates. The strict-validator 5% microbenchmark '
              'was characterized as nondeterministic (**6/10 pass, 4/10 fail**) and remains deferred; it is not stable product evidence.\n')
handoff.write_text(text.replace(needle, needle + acceptance))

tracker = Path('.agents/Directional/Regression_Root_Cause_Tracker.md')
repls = [
    ('`RP-02 / TA-05` remains **test-authority resolved and preserved through M1d**; M1e preservation is accepted under immutable artifact execution:',
     '`RP-02 / TA-05` remains **test-authority resolved and preserved through M1e** under immutable artifact execution:'),
    ('- M1e compiles each route step through canonical `SourceEdgeTopologyKey` + `InteriorTransitionId`; observed route orientation is preserved through `CanonicalRoute::oriented_steps()` rather than canonical storage order becoming behavioral order. Runtime acceptance is complete.',
     '- M1e routes each step through canonical `SourceEdgeTopologyKey` + `InteriorTransitionId`; observed route orientation is preserved through `CanonicalRoute::oriented_steps()` rather than canonical storage order becoming behavioral order. Immutable runtime is accepted.'),
    ('**M1e is the current direct RP-07 migration:**', '**M1e is the accepted direct RP-07 migration:**'),
    ('Untouched by M1a–M1e. Vase remains bounded safety-only evidence. M1e must add no search/retry loop.',
     'Untouched by M1a–M1e. Vase remains bounded safety-only evidence. M1e added no search/retry loop; M1f must preserve this.'),
    ('M1e compile authority:', 'M1e immutable authority:'),
]
for old, new in repls:
    require_replace(tracker, old, new)

for path in (roadmap, handoff, tracker):
    text = path.read_text()
    if 'M1e remains runtime-pending' in text or 'M1e runtime authority is pending' in text:
        raise SystemExit(f'{path}: stale M1e pending authority remains')

print('final status consistency updates ready')
