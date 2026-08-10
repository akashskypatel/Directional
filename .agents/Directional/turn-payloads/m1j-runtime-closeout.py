from pathlib import Path
import re

# Live handoff: replace only the superseded current-turn front matter. Historical sections remain intact.
handoff = Path('.agents/Directional/Future_Chat_Session_Handoff.md')
text = handoff.read_text()
start = text.index('## Mandatory next turn')
end = text.index('## M1i immutable acceptance authority')
new_front = '''## Mandatory next turn

Run **M1k Phase-Front Edge Topology-Region Consumer — Code + Build only** under:

`.agents/Directional/Architecture_M1k_Phase_Front_Edge_Topology_Region_Consumer_Code_Build_Plan.md`

Repository: `akashskypatel/Directional`, branch `agent/surface_cell_quad/p5-recover-bridge-healing`. Draft PR #8 stays open, draft, and unmerged. Product gate **G4 topology-distinct completion and singularities** remains active. Architecture slices M1a through M1j are immutable accepted. Review policy is `never`.

M1k is bounded to:

`SurfaceTopologyRegion::id / normalize_scope -> SurfaceFrontEdge::sourceTopologyRegion -> still-raw pipeline compatibility consumers`.

Migrate only edge-owned topology-region identity to checked `TopologyRegionId`. Keep `SurfacePhaseFrontCell::sourceTopologyRegion`, `SurfaceTopologyRegion::id`, region-by-face maps, periodic/bounded-disk/certificate topology-region schemas, topology-region construction/numbering, M2-M6, and G4 behavior out of scope. The next turn is **Code + Build only**: execute no generated Directional binary, discovery/list command, test, benchmark, `ctest`, CLI/GUI/help/version command, fuzzer, or custom input.

## M1j immutable acceptance authority

M1j is immutable accepted from implementation `d5f681173600dc32dc7617de6105d9e584e593be` and exact Code + Build artifacts `9076217893 / 9076218338`.

Runtime authority: producer discovery **214**, M1j focused **6/6**, required-green **199/199**, M1i-M1b focused preservation green, M1d route witnesses **3/3**, M1c transition counterexamples **3/3**, validation **77/77**, M1a **14/14**, T1 **29/29**, and Plane/MultiFaceSeam/CloseSheets/Cylinder independent-oracle clean without fixture symlink. All eight historical/deferred red classes remain unchanged. Strict-validator timing remains deferred after fresh **0/10** characterization.

Remote validation run/job `31425748772 / 93576908519` retained evidence/log artifacts `9077128237 / 9077129029`. Heavy artifact-only run `31425364955` preserved Bunny's known `NotProductionReady:completion traceSegments=170831 arrangementCells=0 completedQuads=0` failure and bounded Vase at 60 seconds; Bunny evidence/log artifacts are `9076993439 / 9076993713`, Vase `9076989920 / 9076990491`. Exact preflight/postflight preserved result ZIP SHA `a428735f68793e7f4721094b11400c6b4d1276dbea4e6eeb1496fd0ce13f178c`, manifest **67/67** digest `2134a0102a38b75d16c859be8fd862ab037c312609ab9bbae19499c9f875da59`, 68 regular files, seven executables, two libraries, 27 fixtures, producer SHA `04d5d4d59c3e7e9d15cc3e57b0887086939735867aeb1a122a4b3b82be826e40`, and `fixtureSymlink=false`.

No stable product regression event or recurrence was created. Historical totals remain **34 events / 14 categories / 20 recurrences**; `PR8-R034 / G4-R007` remains active.

Current immutable report:
`.agents/Directional/Architecture_M1j_Phase_Front_Edge_Source_Scope_Consumer_Artifact_Only_Test_Benchmark_Report.md`.

Authoritative next plan:
`.agents/Directional/Architecture_M1k_Phase_Front_Edge_Topology_Region_Consumer_Code_Build_Plan.md`.

'''
text = text[:start] + new_front + text[end:]
handoff.write_text(text)

# Root TODO: replace only current active-direction block.
todo = Path('TODO')
text = todo.read_text()
end = text.index('## M1d immutable acceptance')
new_top = '''Last updated: 2026-08-10 UTC

## Active direction

- Phase: P5 — producer-correct direct surface paving.
- Product gate: **G4 topology-distinct completion and singularities active**.
- Test architecture: **T1 independent oracle/package foundation accepted**.
- Architecture migration: **M1a through M1j immutable accepted; M1k edge topology-region consumer selected for Code + Build**.
- M1j implementation `d5f681173600dc32dc7617de6105d9e584e593be` accepted from exact artifacts `9076217893 / 9076218338`: producer **214**, focused **6/6**, required-green **199/199**, validation **77/77**, M1a **14/14**, T1 **29/29**, and four direct products independent-oracle clean without fixture symlink.
- Remote validation run/job `31425748772 / 93576908519`; evidence/log artifacts `9077128237 / 9077129029`.
- Heavy run `31425364955`: Bunny unchanged `NotProductionReady:completion traceSegments=170831 arrangementCells=0 completedQuads=0`; Vase bounded safety-only at 60 seconds; exact **67/67** package authority preserved.
- Strict-validator timing remains deferred after fresh **0/10** characterization; no threshold/retry workaround is authorized.
- M1k seam: `SurfaceTopologyRegion::id / normalize_scope -> SurfaceFrontEdge::sourceTopologyRegion -> still-raw pipeline compatibility consumers`; migrate only edge-owned `TopologyRegionId` authority.
- Authoritative next turn: `.agents/Directional/Architecture_M1k_Phase_Front_Edge_Topology_Region_Consumer_Code_Build_Plan.md`.
- Expected following runtime authority after M1k build: producer discovery **220**, M1k focused **6/6**, required-green **205/205**, plus full entering preservation and exact postflight.
- Historical totals remain **34 / 14 / 20**; `PR8-R034 / G4-R007` remains active.
- Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`; draft PR #8 stays open/unmerged; review policy `never`.
- Current immutable report: `.agents/Directional/Architecture_M1j_Phase_Front_Edge_Source_Scope_Consumer_Artifact_Only_Test_Benchmark_Report.md`.

'''
text = new_top + text[end:]
todo.write_text(text)

# Milestone G: update current gate sentence and append one bounded accepted section without deleting older evidence.
mg = Path('MILESTONE_G_TODO.md')
text = mg.read_text()
old = 'Production remains known-red on direct torus. T1 independent authority and M1a through M1i architecture slices are immutable accepted. M1j phase-front edge source-scope Code + Build is complete and immutable runtime is next. Architecture migration remains separate from G4 product acceptance.'
new = 'Production remains known-red on direct torus. T1 independent authority and M1a through M1j architecture slices are immutable accepted. M1k phase-front edge topology-region consumer is the next Code + Build slice. Architecture migration remains separate from G4 product acceptance.'
assert text.count(old) == 1
text = text.replace(old, new)
if '## M1j phase-front edge source-scope authority — immutable accepted' not in text:
    marker = '## M1f vertex-continuation transport — immutable accepted'
    assert text.count(marker) == 1
    section = '''## M1j phase-front edge source-scope authority — immutable accepted

Implementation `d5f681173600dc32dc7617de6105d9e584e593be` migrates only `SurfaceFrontEdge::{sourceComponent, sourceSheet, sourceIsolationSheets}` to checked `SourceComponentId` / `IsolationSheetId`, preserving raw `sourceTopologyRegion` for the next bounded slice.

Exact artifacts `9076217893 / 9076218338` are immutable accepted. Runtime authority: producer discovery **214**, M1j **6/6**, required-green **199/199**, M1i-M1b focused preservation, M1d/M1c counterexamples **3/3 + 3/3**, validation **77/77**, M1a **14/14**, T1 **29/29**, and Plane/MultiFaceSeam/CloseSheets/Cylinder independent-oracle clean without fixture symlink. All eight historical/deferred red classes remain unchanged. Strict-validator timing remains deferred after fresh **0/10** characterization.

Heavy run `31425364955` preserved Bunny's known `NotProductionReady:completion traceSegments=170831 arrangementCells=0 completedQuads=0` failure and bounded Vase at 60 seconds as safety-only evidence. Exact pre/postflight preserved **67/67** package checksums. No stable product regression event or recurrence was created; historical totals remain **34 / 14 / 20** and `PR8-R034 / G4-R007` remains active.

Next architecture slice: **M1k Phase-Front Edge Topology-Region Consumer — Code + Build only** at `SurfaceTopologyRegion::id / normalize_scope -> SurfaceFrontEdge::sourceTopologyRegion -> still-raw pipeline compatibility consumers`.

Authoritative plan: `.agents/Directional/Architecture_M1k_Phase_Front_Edge_Topology_Region_Consumer_Code_Build_Plan.md`.  
Current immutable report: `.agents/Directional/Architecture_M1j_Phase_Front_Edge_Source_Scope_Consumer_Artifact_Only_Test_Benchmark_Report.md`.

'''
    text = text.replace(marker, section + marker)
mg.write_text(text)

# Reorientation roadmap: change only current M1 status lines.
reo = Path('.agents/Directional/REORIENTATION_PLAN.md')
text = reo.read_text()
old = '   M1j phase-front edge source-scope consumer [compile/package complete; immutable runtime next]\n   later bounded M1 consumers [pending]'
new = '   M1j phase-front edge source-scope consumer [accepted]\n   M1k phase-front edge topology-region consumer [selected; Code + Build next]\n   later bounded M1 consumers [pending]'
assert text.count(old) == 1
text = text.replace(old, new)
reo.write_text(text)

# Regression tracker: update only current status and M1j authority paragraphs.
tracker = Path('.agents/Directional/Regression_Root_Cause_Tracker.md')
text = tracker.read_text()
old = 'Last updated: **2026-08-10 UTC** after M1j edge source-scope Code + Build from artifact `9076217893`; immutable runtime is next.'
new = 'Last updated: **2026-08-10 UTC** after immutable M1j edge source-scope acceptance from artifact `9076217893`; M1k edge topology-region authority is next.'
assert text.count(old) == 1
text = text.replace(old, new)
needle = 'M1i implementation `b037157921094604f1b0c17f9c8b7076c7604b3b` is immutable accepted from artifact `9072101943`: focused **6/6**, required-green **193/193**, full entering preservation/direct-product authority, unchanged historical-red classes, bounded Bunny/Vase comparison, and exact postflight. No stable product regression event or recurrence is added. `PR8-R034 / G4-R007` remains active.'
replacement = needle + ' M1j implementation `d5f681173600dc32dc7617de6105d9e584e593be` is immutable accepted from artifact `9076217893`: producer discovery **214**, focused **6/6**, required-green **199/199**, full entering preservation/direct-product authority, all eight historical-red classes unchanged, strict timing truthfully **0/10**, bounded Bunny/Vase comparison, and exact **67/67** postflight. No stable product regression event or recurrence is added.'
assert text.count(needle) == 1
text = text.replace(needle, replacement)
old = '- M1h phase-front field charts cross checked `FieldChartId` boundaries before constructive-front semantic use and are **immutable accepted**. M1i cell-owned source component/sheet state through checked `SourceComponentId` / `IsolationSheetId` is **immutable accepted**. M1j now carries the immediately adjacent `SurfaceFrontEdge` component/sheet consumer through checked typed authority; compile/package is complete and immutable runtime acceptance is pending.'
new = '- M1h phase-front field charts cross checked `FieldChartId` boundaries before constructive-front semantic use and are **immutable accepted**. M1i cell-owned source component/sheet state through checked `SourceComponentId` / `IsolationSheetId` is **immutable accepted**. M1j immediately adjacent `SurfaceFrontEdge` component/sheet authority is **immutable accepted**. M1k next migrates the remaining edge-owned raw topology-region identity to checked `TopologyRegionId` without changing topology-region construction.'
assert text.count(old) == 1
text = text.replace(old, new)
old = 'M1j adds six compiled production-path contracts for typed edge source scope. Authoritative build artifact `9076217893` is compile/package complete with no generated runtime execution; semantic acceptance therefore remains pending. The initial compile mismatch and superseded incomplete-manifest artifact are Code + Build/orchestration defects, not stable product regressions. Authoritative next runtime plan: `.agents/Directional/Architecture_M1j_Phase_Front_Edge_Source_Scope_Consumer_Artifact_Only_Test_Benchmark_Plan.md`. Historical totals remain **34 / 14 / 20**.'
new = 'M1j edge source-scope migration is immutable accepted: producer discovery **214**, M1j **6/6**, required-green **199/199**, M1i-M1b preservation, validation **77/77**, M1a **14/14**, T1 **29/29**, four direct products independent-oracle clean, all eight historical/deferred red classes unchanged, strict timing **0/10**, Bunny known-red, Vase bounded safety-only, and exact **67/67** postflight. The initial compile mismatch and superseded incomplete-manifest artifact remain Code + Build/orchestration defects only. M1k must preserve `RP-02 / TA-05` while adding six production-path contracts for checked edge topology-region authority. Authoritative next Code + Build plan: `.agents/Directional/Architecture_M1k_Phase_Front_Edge_Topology_Region_Consumer_Code_Build_Plan.md`. Historical totals remain **34 / 14 / 20**.'
assert text.count(old) == 1
text = text.replace(old, new)
tracker.write_text(text)

print('updated durable docs:', handoff, todo, mg, reo, tracker)
