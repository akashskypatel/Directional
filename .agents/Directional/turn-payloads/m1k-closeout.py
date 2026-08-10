import json
from pathlib import Path

payload = json.loads(Path('.agents/Directional/turn-payloads/m1k-closeout.json').read_text())

todo_path = Path('TODO')
todo = todo_path.read_text()
start = todo.index('## Active direction\n')
end = todo.index('## M1d immutable acceptance\n')
active = f'''## Active direction

- Phase: P5 — producer-correct direct surface paving.
- Product gate: **G4 topology-distinct completion and singularities active**.
- Test architecture: **T1 independent oracle/package foundation accepted**.
- Architecture migration: **M1a through M1j immutable accepted; M1k Code + Build compile/package complete, immutable runtime pending**.
- M1k implementation `{payload['implementation']}` migrates only `SurfaceFrontEdge::sourceTopologyRegion` to checked `TopologyRegionId`; topology-region construction/numbering and neighboring raw compatibility schemas remain unchanged.
- Authoritative Code + Build run/job `{payload['run_id']} / {payload['job_id']}`; result/log artifacts `{payload['result_artifact']} / {payload['log_artifact']}`; recursive package manifest **{payload['manifest_count']}/{payload['manifest_count']}**, digest `{payload['manifest_sha']}`; package has {payload['package_count']} regular files, 7 executables, 2 static libraries, and 27 fixtures.
- Code + Build executed **no** generated Directional binary, test discovery/list, test, benchmark, `ctest`, CLI/GUI/help/version command, fuzzer, or custom input.
- Authoritative next turn: `.agents/Directional/Architecture_M1k_Phase_Front_Edge_Topology_Region_Consumer_Artifact_Only_Test_Benchmark_Plan.md`.
- Expected runtime authority: producer discovery **220**, M1k focused **6/6**, required-green **205/205**, plus complete entering preservation and exact immutable postflight.
- Historical totals remain **34 / 14 / 20**; `PR8-R034 / G4-R007` remains active. Compile/package orchestration retries did not establish a stable product regression.
- Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`; draft PR #8 stays open/unmerged; review policy `never`.
- Current Code + Build report: `.agents/Directional/Architecture_M1k_Phase_Front_Edge_Topology_Region_Consumer_Code_Build_Report.md`.

'''
todo_path.write_text(todo[:start] + active + todo[end:])

handoff_path = Path('.agents/Directional/Future_Chat_Session_Handoff.md')
handoff = handoff_path.read_text()
start = handoff.index('## Mandatory next turn\n')
end = handoff.index('## M1j immutable acceptance authority\n')
mandatory = f'''## Mandatory next turn

Run **M1k Phase-Front Edge Topology-Region Consumer — immutable Artifact-Only Test + Benchmark only** under:

`.agents/Directional/Architecture_M1k_Phase_Front_Edge_Topology_Region_Consumer_Artifact_Only_Test_Benchmark_Plan.md`

Repository: `akashskypatel/Directional`, branch `agent/surface_cell_quad/p5-recover-bridge-healing`. Draft PR #8 stays open, draft, and unmerged. Product gate **G4 topology-distinct completion and singularities** remains active. Architecture slices M1a through M1j are immutable accepted; M1k is compile/package complete but **not** semantically accepted until the artifact-only runtime turn passes. Review policy is `never`.

M1k implementation `{payload['implementation']}` changes only the edge-owned topology-region authority seam:

`SurfaceTopologyRegion::id / normalize_scope -> SurfaceFrontEdge::sourceTopologyRegion -> still-raw pipeline compatibility consumers`.

`SurfaceFrontEdge::sourceTopologyRegion` is now checked optional `TopologyRegionId`. Existing topology-region discovery, partitioning, numbering, `SurfacePhaseFrontCell::sourceTopologyRegion`, raw region-by-face maps, periodic/bounded-disk/certificate topology-region schemas, component/sheet authority, M2-M6, and G4 product behavior remain out of scope.

Authoritative Code + Build evidence:

- run/job `{payload['run_id']} / {payload['job_id']}`;
- result artifact `{payload['result_artifact']}`, ZIP SHA-256 `{payload['result_zip_sha']}`;
- log artifact `{payload['log_artifact']}`, ZIP SHA-256 `{payload['log_zip_sha']}`;
- recursive package manifest **{payload['manifest_count']}/{payload['manifest_count']}**, SHA-256 `{payload['manifest_sha']}`;
- package cardinality **{payload['package_count']}** regular files including `SHA256SUMS`, seven executables, two static libraries, and 27 fixtures;
- Release/static/Ninja/PRE_TEST approved targets compiled successfully; wall `{payload['build_wall']}`, peak RSS `{payload['build_rss_kib']} KiB`;
- every runtime/test/benchmark/discovery/ctest/CLI/fuzzer/custom-input flag is false.

The six compiled M1k production-path contracts remain **unexecuted** until the next turn. Expected runtime discovery is producer **220**; require M1k **6/6** individually and required-green producer **205/205**, plus M1j-M1b preservation, M1d/M1c counterexamples, validation **77/77**, M1a **14/14**, T1 **29/29**, four direct products, historical/deferred-red classification, strict timing characterization, bounded Bunny/Vase comparison when gates permit, and exact postflight.

The Code + Build orchestration had pre-semantic failures while establishing the immutable package (patch recount, post-build untracked build-dir cleanliness, and incomplete fixture-copy cardinality). These were control-plane/package issues; the exact M1k implementation compiled successfully and no generated Directional runtime executed. Do **not** create a stable product-regression event from those retries.

Durable-document safety remains mandatory: design, architecture, policy, handoff, tracker, and planning documents must not be destructively rewritten or have durable information removed except in an explicitly user-authorized review turn or with explicit user authorization. Routine status updates must be surgical and preserve prior durable information.

Current report:
`.agents/Directional/Architecture_M1k_Phase_Front_Edge_Topology_Region_Consumer_Code_Build_Report.md`.

Authoritative next plan:
`.agents/Directional/Architecture_M1k_Phase_Front_Edge_Topology_Region_Consumer_Artifact_Only_Test_Benchmark_Plan.md`.

'''
handoff_path.write_text(handoff[:start] + mandatory + handoff[end:])

milestone_path = Path('MILESTONE_G_TODO.md')
milestone = milestone_path.read_text()
old = ('Production remains known-red on direct torus. T1 independent authority and M1a through M1j architecture slices are immutable accepted. '
       'M1k phase-front edge topology-region consumer is the next Code + Build slice. Architecture migration remains separate from G4 product acceptance.')
new = ('Production remains known-red on direct torus. T1 independent authority and M1a through M1j architecture slices are immutable accepted. '
       'M1k phase-front edge topology-region consumer is compile/package complete at implementation '
       f'`{payload["implementation"]}`; immutable artifact-only runtime is next. Architecture migration remains separate from G4 product acceptance.')
if milestone.count(old) != 1:
    raise SystemExit(f'expected one current-gate paragraph, got {milestone.count(old)}')
milestone = milestone.replace(old, new, 1)
heading = '## M1k phase-front edge topology-region authority — compile/package complete; runtime pending\n'
if heading not in milestone:
    anchor = '\n## M1f vertex-continuation transport — immutable accepted\n'
    if milestone.count(anchor) != 1:
        raise SystemExit(f'expected one M1f insertion anchor, got {milestone.count(anchor)}')
    section = f'''\n{heading}
Implementation `{payload['implementation']}` migrates only persistent `SurfaceFrontEdge::sourceTopologyRegion` from raw `int` to checked optional `TopologyRegionId`. Region discovery/partition/numbering, cell-owned raw topology-region identity, periodic/bounded-disk/certificate schemas, and accepted source component/sheet authority are unchanged. Still-raw pipeline consumers cross the typed boundary through named compatibility conversion.

Authoritative Code + Build run/job `{payload['run_id']} / {payload['job_id']}` compiled the approved Release/static/Ninja/PRE_TEST targets successfully. Result/log artifacts are `{payload['result_artifact']} / {payload['log_artifact']}` with ZIP SHA-256 `{payload['result_zip_sha']} / {payload['log_zip_sha']}`. Recursive package authority is **{payload['manifest_count']}/{payload['manifest_count']}**, digest `{payload['manifest_sha']}`, with {payload['package_count']} regular files, seven executables, two static libraries, and 27 fixtures. Every runtime flag is false; six M1k focused production-path contracts compile but remain unexecuted.

The next mandatory turn is immutable artifact-only Test + Benchmark. Expected producer discovery **220**, M1k **6/6**, required-green **205/205**, and full entering preservation. No stable product regression was established by Code + Build orchestration retries; historical totals remain **34 / 14 / 20** and `PR8-R034 / G4-R007` remains active.
'''
    milestone = milestone.replace(anchor, section + anchor, 1)
milestone_path.write_text(milestone)
