from pathlib import Path

IMPLEMENTATION = "b9181364926cea840e9cb50da21fe721f33fd874"
RUN_JOB = "31433794426 / 93603203081"
EVIDENCE = "9080245848 / 9080246452"

# TODO: replace only the live Active direction section. Historical sections remain intact.
p = Path("TODO")
s = p.read_text()
start = s.index("## Active direction\n")
end = s.index("## M1d immutable acceptance\n")
active = f'''## Active direction

- Phase: P5 — producer-correct direct surface paving.
- Product gate: **G4 topology-distinct completion and singularities active**.
- Test architecture: **T1 independent oracle/package foundation accepted**.
- Architecture migration: **M1a through M1k immutable accepted; M1l cell topology-region consumer selected for Code + Build**.
- M1k implementation `{IMPLEMENTATION}` is immutable accepted from exact Code + Build artifacts `9079318682 / 9079319269` and artifact-only runtime run/job `{RUN_JOB}`.
- Runtime authority: producer **220**, M1k **6/6**, required-green **205/205**, validation **77/77**, M1a **14/14**, T1 **29/29**, four direct products independent-oracle clean, all eight historical/deferred red classes unchanged, Bunny known-red unchanged, Vase bounded safety-only, exact **68/68** postflight.
- Strict-validator timing sampled **10/10 pass** in fresh processes but remains the existing nondeterministic sub-millisecond ratio/microbenchmark defect; no threshold/retry workaround is authorized.
- Authoritative next turn: `.agents/Directional/Architecture_M1l_Phase_Front_Cell_Topology_Region_Consumer_Code_Build_Plan.md`.
- M1l seam: `SurfaceTopologyRegion::id / normalize_scope -> SurfacePhaseFrontCell::sourceTopologyRegion -> still-raw materializer compatibility consumers`.
- Expected following runtime authority after M1l build: producer discovery **226**, M1l focused **6/6**, required-green **211/211**, plus complete entering preservation and exact immutable postflight.
- Historical totals remain **34 / 14 / 20**; `PR8-R034 / G4-R007` remains active. M1k extraction/harness/evidence-retention anomalies did not establish a stable product regression.
- Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`; draft PR #8 stays open/unmerged; review policy `never`.
- Current immutable report: `.agents/Directional/Architecture_M1k_Phase_Front_Edge_Topology_Region_Consumer_Artifact_Only_Test_Benchmark_Report.md`.

'''
p.write_text(s[:start] + active + s[end:])

# Handoff: replace only the live next-turn section and insert M1k acceptance before M1j history.
p = Path(".agents/Directional/Future_Chat_Session_Handoff.md")
s = p.read_text()
start = s.index("## Mandatory next turn\n")
end = s.index("## M1j immutable acceptance authority\n")
mandatory = f'''## Mandatory next turn

Run **M1l Phase-Front Cell Topology-Region Consumer — Code + Build only** under:

`.agents/Directional/Architecture_M1l_Phase_Front_Cell_Topology_Region_Consumer_Code_Build_Plan.md`

Repository: `akashskypatel/Directional`, branch `agent/surface_cell_quad/p5-recover-bridge-healing`. Draft PR #8 stays open, draft, and unmerged. Product gate **G4 topology-distinct completion and singularities** remains active. Architecture slices M1a through M1k are immutable accepted. Review policy is `never`.

M1l is bounded to:

`SurfaceTopologyRegion::id / normalize_scope -> SurfacePhaseFrontCell::sourceTopologyRegion -> still-raw materializer compatibility consumers`.

Migrate only cell-owned topology-region identity to checked `TopologyRegionId`. Preserve `SurfaceTopologyRegion::id`, raw region-by-face maps, certificate/periodic/bounded-disk/occurrence/lineage region schemas, topology-region discovery/partition/numbering, accepted component/sheet and edge-region authority, M2-M6, fallback/recovery, optimization, and G4 behavior.

This is **Code + Build only**. Execute no generated Directional binary, GoogleTest discovery/list command, test, benchmark, `ctest`, CLI/GUI/help/version command, fuzzer, or custom input. Exactly six M1l production-path contracts compile only. Expected following runtime authority is producer **226**, M1l **6/6**, required-green **211/211**, plus all entering preservation gates.

Lessons that affect execution:

- use the exact accepted M1k source/package authority below; later documentation/control-plane commits are not runtime evidence commits;
- Python `zipfile.extractall` did not preserve packaged executable mode bits during one local validation attempt; immutable runtime extraction must use a method such as CLI `unzip` that preserves the archive's natural executable attributes, never `chmod`/repair the package;
- a single local Cylinder harness stall did not reproduce in immediate bounded local execution or either controlled remote run; do not add product workarounds for it;
- the first remote M1k semantic run was green but its evidence upload used the wrong temp-root path; evidence paths in future workflows must use `${{ runner.temp }}`/`$RUNNER_TEMP` consistently.

Current immutable report:
`.agents/Directional/Architecture_M1k_Phase_Front_Edge_Topology_Region_Consumer_Artifact_Only_Test_Benchmark_Report.md`.

Authoritative next plan:
`.agents/Directional/Architecture_M1l_Phase_Front_Cell_Topology_Region_Consumer_Code_Build_Plan.md`.

## M1k immutable acceptance authority

M1k implementation `{IMPLEMENTATION}` is immutable accepted from exact Code + Build artifacts `9079318682 / 9079319269` and authoritative artifact-only runtime `{RUN_JOB}`. Runtime evidence/log artifacts are `{EVIDENCE}`.

Acceptance authority: producer discovery **220**, M1k focused **6/6**, M1j-M1b focused preservation green, M1d/M1c counterexamples **3/3 + 3/3**, required-green **205/205**, validation **77/77**, M1a **14/14**, T1 **29/29**, Plane/MultiFaceSeam/CloseSheets/Cylinder independent-oracle clean, all eight historical/deferred red classes unchanged, strict timing fresh **10/10** but still deferred as nondeterministic, Bunny unchanged `NotProductionReady:completion traceSegments=170831 arrangementCells=0 completedQuads=0`, Vase bounded safety-only at 60 seconds, and exact **68/68** immutable postflight.

No stable product regression event or recurrence was created. Historical totals remain **34 / 14 / 20**; `PR8-R034 / G4-R007` remains active.

'''
p.write_text(s[:start] + mandatory + s[end:])

# Milestone G live gate and M1k section.
p = Path("MILESTONE_G_TODO.md")
s = p.read_text()
old_gate = ("Production remains known-red on direct torus. T1 independent authority and M1a through M1j architecture slices are immutable accepted. "
            "M1k phase-front edge topology-region consumer is compile/package complete at implementation `b9181364926cea840e9cb50da21fe721f33fd874`; immutable artifact-only runtime is next. Architecture migration remains separate from G4 product acceptance.")
new_gate = ("Production remains known-red on direct torus. T1 independent authority and M1a through M1k architecture slices are immutable accepted. "
            "M1l phase-front cell topology-region consumer is the next Code + Build slice. Architecture migration remains separate from G4 product acceptance.")
if s.count(old_gate) != 1:
    raise SystemExit(f"MILESTONE gate match count={s.count(old_gate)}")
s = s.replace(old_gate, new_gate, 1)
heading = "## M1k phase-front edge topology-region authority — compile/package complete; runtime pending\n"
next_heading = "## M1f vertex-continuation transport — immutable accepted\n"
if heading not in s or next_heading not in s:
    raise SystemExit("MILESTONE M1k section anchors missing")
start = s.index(heading)
end = s.index(next_heading, start)
m1k = f'''## M1k phase-front edge topology-region authority — immutable accepted

Implementation `{IMPLEMENTATION}` migrates only persistent `SurfaceFrontEdge::sourceTopologyRegion` from raw `int` to checked optional `TopologyRegionId`, preserving region discovery/partition/numbering, raw cell/region-by-face identity, periodic/bounded-disk/certificate schemas, and accepted component/sheet authority.

Authoritative Code + Build artifacts `9079318682 / 9079319269` have recursive package authority **68/68**. Exact artifact-only validation `{RUN_JOB}` accepted producer **220**, M1k **6/6**, required-green **205/205**, all entering M1 authority, validation **77/77**, M1a **14/14**, T1 **29/29**, and all four direct independent-oracle products. Eight historical/deferred red classes remained unchanged. Bunny stayed `NotProductionReady:completion traceSegments=170831 arrangementCells=0 completedQuads=0`; Vase remained bounded safety-only. Exact postflight preserved all **68/68** package checksums.

Strict-validator timing sampled **10/10 pass** but remains the known nondeterministic sub-millisecond ratio defect because accepted historical samples vary materially. No stable product regression or recurrence was created; historical totals remain **34 / 14 / 20** and `PR8-R034 / G4-R007` remains active.

Accepted-source inspection selects M1l at `SurfaceTopologyRegion::id / normalize_scope -> SurfacePhaseFrontCell::sourceTopologyRegion -> still-raw materializer compatibility consumers`. M1l migrates only cell-owned topology-region identity; global region schemas/construction and G4 behavior remain out of scope.

Authoritative next plan: `.agents/Directional/Architecture_M1l_Phase_Front_Cell_Topology_Region_Consumer_Code_Build_Plan.md`.

'''
s = s[:start] + m1k + s[end:]
p.write_text(s)

# Regression tracker: surgical current-status additions/replacements; preserve the historical inventory.
p = Path(".agents/Directional/Regression_Root_Cause_Tracker.md")
s = p.read_text()
old = "Last updated: **2026-08-10 UTC** after immutable M1j edge source-scope acceptance from artifact `9076217893`; M1k edge topology-region authority is next."
new = "Last updated: **2026-08-10 UTC** after immutable M1k edge topology-region acceptance from artifacts `9079318682 / 9080245848`; M1l cell topology-region authority is next."
if s.count(old) != 1:
    raise SystemExit(f"tracker last-updated count={s.count(old)}")
s = s.replace(old, new, 1)
needle = "M1j implementation `d5f681173600dc32dc7617de6105d9e584e593be` is immutable accepted from artifact `9076217893`: producer discovery **214**, focused **6/6**, required-green **199/199**, full entering preservation/direct-product authority, all eight historical-red classes unchanged, strict timing truthfully **0/10**, bounded Bunny/Vase comparison, and exact **67/67** postflight. No stable product regression event or recurrence is added."
addition = needle + " M1k implementation `b9181364926cea840e9cb50da21fe721f33fd874` is immutable accepted from artifact `9079318682` and runtime evidence `9080245848`: producer **220**, focused **6/6**, required-green **205/205**, full entering preservation/direct-product authority, all eight historical-red classes unchanged, Bunny/Vase dispositions preserved, and exact **68/68** postflight. Strict timing sampled **10/10** but remains the existing nondeterministic microbenchmark classification. The local extraction/harness anomalies and first remote evidence-upload-path failure are infrastructure only. No stable product regression event or recurrence is added."
if s.count(needle) != 1:
    raise SystemExit(f"tracker history needle count={s.count(needle)}")
s = s.replace(needle, addition, 1)
old = "M1j immediately adjacent `SurfaceFrontEdge` component/sheet authority is **immutable accepted**. M1k next migrates the remaining edge-owned raw topology-region identity to checked `TopologyRegionId` without changing topology-region construction."
new = "M1j immediately adjacent `SurfaceFrontEdge` component/sheet authority is **immutable accepted**. M1k edge-owned topology-region identity is **immutable accepted** as checked `TopologyRegionId` without changing topology-region construction. M1l next migrates the remaining raw cell-owned topology-region identity to checked `TopologyRegionId`."
if s.count(old) != 1:
    raise SystemExit(f"tracker RP01 count={s.count(old)}")
s = s.replace(old, new, 1)
old = "M1k must preserve `RP-02 / TA-05` while adding six production-path contracts for checked edge topology-region authority. Authoritative next Code + Build plan: `.agents/Directional/Architecture_M1k_Phase_Front_Edge_Topology_Region_Consumer_Code_Build_Plan.md`. Historical totals remain **34 / 14 / 20**."
new = "M1k preserves `RP-02 / TA-05`: producer **220**, M1k **6/6**, required-green **205/205**, validation **77/77**, M1a **14/14**, T1 **29/29**, four direct products oracle-clean, known-red classes unchanged, and exact postflight. M1l must preserve the same authority while adding six production-path contracts for checked cell topology-region authority. Authoritative next Code + Build plan: `.agents/Directional/Architecture_M1l_Phase_Front_Cell_Topology_Region_Consumer_Code_Build_Plan.md`. Historical totals remain **34 / 14 / 20**."
if s.count(old) != 1:
    raise SystemExit(f"tracker RP02 count={s.count(old)}")
s = s.replace(old, new, 1)
anchor = "Global conformity/certificate migration remains M3/M4; `G4-R007` stays active."
insert = anchor + "\n\nM1k is immutable accepted at the adjacent edge topology-region seam. M1l now removes the raw cell-region mirror so cell/edge ownership can agree as `TopologyRegionId` while still-raw materializer/occurrence schemas remain explicit compatibility boundaries. This is the next bounded `RP-01 / RP-05 / RP-09` consumer and does not migrate global topology planning."
if s.count(anchor) != 1:
    raise SystemExit(f"tracker RP09 anchor count={s.count(anchor)}")
s = s.replace(anchor, insert, 1)
p.write_text(s)

# Reorientation roadmap: current ordering and live M1 checkpoint only; normative design text is untouched.
p = Path(".agents/Directional/REORIENTATION_PLAN.md")
s = p.read_text()
old = "   M1k phase-front edge topology-region consumer [selected; Code + Build next]\n   later bounded M1 consumers [pending]"
new = "   M1k phase-front edge topology-region consumer [accepted]\n   M1l phase-front cell topology-region consumer [selected; Code + Build next]\n   later bounded M1 consumers [pending]"
if s.count(old) != 1:
    raise SystemExit(f"reorientation ordering count={s.count(old)}")
s = s.replace(old, new, 1)
old = "Authoritative next Code + Build plan:\n`.agents/Directional/Architecture_M1j_Phase_Front_Edge_Source_Scope_Consumer_Code_Build_Plan.md`."
new = "Historical M1j Code + Build plan:\n`.agents/Directional/Architecture_M1j_Phase_Front_Edge_Source_Scope_Consumer_Code_Build_Plan.md`.\n\nM1j is immutable accepted. M1k implementation `b9181364926cea840e9cb50da21fe721f33fd874` is likewise immutable accepted from artifact `9079318682` and runtime evidence `9080245848`: producer **220**, focused **6/6**, required-green **205/205**, validation **77/77**, M1a **14/14**, T1 **29/29**, four direct products oracle-clean, historical-red classes unchanged, and exact **68/68** postflight.\n\nAccepted-source inspection selects M1l at `SurfaceTopologyRegion::id / normalize_scope -> SurfacePhaseFrontCell::sourceTopologyRegion -> still-raw materializer compatibility consumers`. M1l migrates only cell-owned `TopologyRegionId` authority and leaves global region construction/schema migration for later bounded consumers/M2-M4.\n\nAuthoritative next Code + Build plan:\n`.agents/Directional/Architecture_M1l_Phase_Front_Cell_Topology_Region_Consumer_Code_Build_Plan.md`."
if s.count(old) != 1:
    raise SystemExit(f"reorientation current-plan count={s.count(old)}")
s = s.replace(old, new, 1)
p.write_text(s)
