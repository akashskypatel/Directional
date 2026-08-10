from pathlib import Path


def replace_once(path: str, old: str, new: str) -> None:
    p = Path(path)
    text = p.read_text()
    count = text.count(old)
    if count != 1:
        raise SystemExit(f"{path}: expected one match, found {count}")
    p.write_text(text.replace(old, new, 1))


handoff = ".agents/Directional/Future_Chat_Session_Handoff.md"
text = Path(handoff).read_text()
start = text.index("## Mandatory next turn")
end = text.index("## M1i immutable acceptance authority")
new_top = '''## Mandatory next turn

Run **M1j Phase-Front Edge Source-Scope Consumer — immutable Artifact-Only Test + Benchmark only** under:

`.agents/Directional/Architecture_M1j_Phase_Front_Edge_Source_Scope_Consumer_Artifact_Only_Test_Benchmark_Plan.md`

Repository: `akashskypatel/Directional`, branch `agent/surface_cell_quad/p5-recover-bridge-healing`. Draft PR #8 stays open, draft, and unmerged. Product gate **G4 topology-distinct completion and singularities** remains active. M1a through M1i are immutable accepted. M1j is compile/package complete and semantic runtime is pending. Review policy is `never`.

Consume only result/log artifacts `9076217893 / 9076218338` from implementation `d5f681173600dc32dc7617de6105d9e584e593be`. Result/log ZIP SHA-256 are `a428735f68793e7f4721094b11400c6b4d1276dbea4e6eeb1496fd0ce13f178c / 76684f4ac412f4da7fd1ccf3cbee5fddfbb7dd14efd43940c6a7568b3d22d1f9`; recursive package manifest is **67/67**, digest `2134a0102a38b75d16c859be8fd862ab037c312609ab9bbae19499c9f875da59`.

Rebuild, relink, configure, regeneration, source/test/build/fixture edits, package repair/substitution, and runtime fixture symlinks are prohibited. Expected native producer discovery is **214**, M1j focused **6/6** individually, and required-green producer **199/199**. Preserve M1i-M1b focused suites, M1d route witnesses **3/3**, M1c transition counterexamples **3/3**, validation **77/77**, M1a **14/14**, T1 **29/29**, direct Plane/MultiFaceSeam/CloseSheets/Cylinder oracle authority, all eight historical/deferred red classes, strict-validator 10-process characterization, Bunny/Vase bounded comparison, and exact postflight.

## M1j Code + Build authority — runtime pending

Selected seam:
`SurfacePhaseFrontCell typed source scope -> SurfaceFrontEdge::{sourceComponent, sourceSheet, sourceIsolationSheets}`.

Final implementation `d5f681173600dc32dc7617de6105d9e584e593be` changes exactly the tracing header, tracing implementation, pipeline compatibility consumers, and phase-10 tests relative to source parent `391271e253557b5c6b267befb3f2f33330c090c9`. Edge-owned component/sheet state now uses checked `SourceComponentId` / `IsolationSheetId`; `sourceTopologyRegion` remains raw for a later slice. Edge publication copies typed cell authority directly and region aggregation validates it rather than rewriting it. Six M1j contracts compile and were **not executed**.

Authoritative build/package run/job `31422691741 / 93566993166` compiled **120/120** Release/static/Ninja/PRE_TEST in **8:17.83**, peak RSS **1,860,968 KiB**. Package has 68 regular files including `SHA256SUMS`, seven executables, two libraries, 27 fixtures, and **67/67** verified checksums. Every runtime/test/benchmark/ctest/CLI/fuzzer/custom-input flag is false.

The first implementation `274b7ab88b581aa63e2e99c3abca2bc89eb742e2` exposed one compile-only missed compatibility conversion at a raw periodic-relation component comparison. The corrected implementation converts the typed edge component through the named legacy adapter. An earlier successful 120/120 package `9075863759` was also rejected as runtime authority because its manifest preceded one final log copy; the final authoritative retry closes the manifest after all package writes. Neither event is a stable product regression.

Historical regression totals remain **34 events / 14 categories / 20 recurrences**; `PR8-R034 / G4-R007` remains active.

Current Code + Build report:
`.agents/Directional/Architecture_M1j_Phase_Front_Edge_Source_Scope_Consumer_Code_Build_Report.md`.

Authoritative next plan:
`.agents/Directional/Architecture_M1j_Phase_Front_Edge_Source_Scope_Consumer_Artifact_Only_Test_Benchmark_Plan.md`.

'''
Path(handoff).write_text(text[:start] + new_top + text[end:])

# Root TODO: replace only the live active-direction bullets.
todo = "TODO"
t = Path(todo).read_text()
start = t.index("## Active direction")
end = t.index("## M1d immutable acceptance")
new_active = '''## Active direction

- Phase: P5 — producer-correct direct surface paving.
- Product gate: **G4 topology-distinct completion and singularities active**.
- Test architecture: **T1 independent oracle/package foundation accepted**.
- Architecture migration: **M1a through M1i immutable accepted; M1j edge source-scope Code + Build complete and immutable runtime pending**.
- M1j implementation `d5f681173600dc32dc7617de6105d9e584e593be`; source parent `391271e253557b5c6b267befb3f2f33330c090c9`; seam `SurfacePhaseFrontCell typed source scope -> SurfaceFrontEdge::{sourceComponent, sourceSheet, sourceIsolationSheets}`.
- Edge-owned source component/sheet authority now uses checked `SourceComponentId` / `IsolationSheetId`; raw `sourceTopologyRegion` remains out of scope and downstream raw consumers use named compatibility conversion.
- Authoritative build run/job `31422691741 / 93566993166`: **120/120**, Release/static/Ninja/PRE_TEST, artifacts `9076217893 / 9076218338`, ZIP SHA-256 `a428735f68793e7f4721094b11400c6b4d1276dbea4e6eeb1496fd0ce13f178c / 76684f4ac412f4da7fd1ccf3cbee5fddfbb7dd14efd43940c6a7568b3d22d1f9`.
- Package manifest **67/67**, digest `2134a0102a38b75d16c859be8fd862ab037c312609ab9bbae19499c9f875da59`; 68 regular files, 7 executables, 2 libraries, 27 fixtures; producer SHA-256 `04d5d4d59c3e7e9d15cc3e57b0887086939735867aeb1a122a4b3b82be826e40`.
- Code + Build runtime boundary: **false**; six M1j contracts compiled and were not executed.
- Initial compile mismatch and earlier incomplete-manifest package are Code + Build/orchestration provenance only; no stable product regression or recurrence is assigned.
- Authoritative next turn: `.agents/Directional/Architecture_M1j_Phase_Front_Edge_Source_Scope_Consumer_Artifact_Only_Test_Benchmark_Plan.md`.
- Expected runtime authority: producer discovery **214**, M1j focused **6/6**, required-green **199/199**, full M1i-M1b/validation/M1a/T1/direct/historical/heavy/postflight preservation.
- Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`; draft PR #8 stays open/unmerged; review policy `never`.
- Current Code + Build report: `.agents/Directional/Architecture_M1j_Phase_Front_Edge_Source_Scope_Consumer_Code_Build_Report.md`.

'''
Path(todo).write_text(t[:start] + new_active + t[end:])

# Milestone: update live gate sentence and replace the old M1j-next tail under M1i.
replace_once(
    "MILESTONE_G_TODO.md",
    "Production remains known-red on direct torus. T1 independent authority and M1a through M1i architecture slices are immutable accepted. M1j phase-front edge source-scope authority is the next Code + Build slice. Architecture migration remains separate from G4 product acceptance.",
    "Production remains known-red on direct torus. T1 independent authority and M1a through M1i architecture slices are immutable accepted. M1j phase-front edge source-scope Code + Build is complete and immutable runtime is next. Architecture migration remains separate from G4 product acceptance.",
)
replace_once(
    "MILESTONE_G_TODO.md",
    "Next architecture slice: **M1j Phase-Front Edge Source-Scope Consumer — Code + Build only** at `SurfacePhaseFrontCell typed source scope -> SurfaceFrontEdge::{sourceComponent, sourceSheet, sourceIsolationSheets}`. Keep raw `sourceTopologyRegion` out of scope and require region aggregation to validate rather than overwrite edge semantic source scope.\n\nAuthoritative plan: `.agents/Directional/Architecture_M1j_Phase_Front_Edge_Source_Scope_Consumer_Code_Build_Plan.md`.\nCurrent immutable report: `.agents/Directional/Architecture_M1i_Phase_Front_Cell_Source_Scope_Consumer_Artifact_Only_Test_Benchmark_Report.md`.",
    "## M1j phase-front edge source-scope authority — compile/package complete; runtime pending\n\nImplementation `d5f681173600dc32dc7617de6105d9e584e593be` migrates only `SurfaceFrontEdge::{sourceComponent, sourceSheet, sourceIsolationSheets}` to checked `SourceComponentId` / `IsolationSheetId` while retaining raw `sourceTopologyRegion` as a later migration boundary. Edge publication copies typed cell scope directly; region aggregation validates it rather than overwriting it.\n\nAuthoritative build run/job `31422691741 / 93566993166` compiled **120/120** Release/static/Ninja/PRE_TEST. Result/log artifacts are `9076217893 / 9076218338`, outer SHA-256 `a428735f68793e7f4721094b11400c6b4d1276dbea4e6eeb1496fd0ce13f178c / 76684f4ac412f4da7fd1ccf3cbee5fddfbb7dd14efd43940c6a7568b3d22d1f9`; recursive manifest is **67/67**, digest `2134a0102a38b75d16c859be8fd862ab037c312609ab9bbae19499c9f875da59`. Every runtime flag is false.\n\nAn initial compile-only missed compatibility conversion and an earlier incomplete-manifest package were corrected before authoritative packaging. They are orchestration/Code + Build provenance, not stable product regressions. Historical totals remain **34 / 14 / 20**; `PR8-R034 / G4-R007` remains active.\n\nRun **M1j immutable Artifact-Only Test + Benchmark only** under `.agents/Directional/Architecture_M1j_Phase_Front_Edge_Source_Scope_Consumer_Artifact_Only_Test_Benchmark_Plan.md`. Expected producer discovery **214**, M1j **6/6**, required-green **199/199**, plus full entering preservation and exact postflight.\n\nCurrent report: `.agents/Directional/Architecture_M1j_Phase_Front_Edge_Source_Scope_Consumer_Code_Build_Report.md`.",
)

# Architecture roadmap: only current status and selected-line transition.
replace_once(
    ".agents/Directional/REORIENTATION_PLAN.md",
    "   M1j phase-front edge source-scope consumer [selected; Code + Build next]",
    "   M1j phase-front edge source-scope consumer [compile/package complete; immutable runtime next]",
)
# Add concise current checkpoint after the accepted M1i statement if it exists.
rp = Path(".agents/Directional/REORIENTATION_PLAN.md")
r = rp.read_text()
anchor = "M1i semantic acceptance is complete.\n"
if anchor in r and "M1j implementation `d5f681" not in r:
    r = r.replace(anchor, anchor + "\nM1j implementation `d5f681173600dc32dc7617de6105d9e584e593be` is compile/package complete at the adjacent `SurfaceFrontEdge` source-scope seam. Exact artifacts `9076217893 / 9076218338` come from build run `31422691741`, **120/120**, manifest **67/67**, with no generated runtime execution. M1j remains semantically pending immutable runtime under `.agents/Directional/Architecture_M1j_Phase_Front_Edge_Source_Scope_Consumer_Artifact_Only_Test_Benchmark_Plan.md`.\n", 1)
rp.write_text(r)

# Regression tracker: compile-only status, no new stable event.
replace_once(
    ".agents/Directional/Regression_Root_Cause_Tracker.md",
    "Last updated: **2026-08-10 UTC** after immutable M1i cell source-scope acceptance from artifact `9072101943`; M1j edge source-scope authority is next.",
    "Last updated: **2026-08-10 UTC** after M1j edge source-scope Code + Build from artifact `9076217893`; immutable runtime is next.",
)
replace_once(
    ".agents/Directional/Regression_Root_Cause_Tracker.md",
    "M1j next migrates the immediately adjacent `SurfaceFrontEdge` component/sheet consumer.",
    "M1j now carries the immediately adjacent `SurfaceFrontEdge` component/sheet consumer through checked typed authority; compile/package is complete and immutable runtime acceptance is pending.",
)
replace_once(
    ".agents/Directional/Regression_Root_Cause_Tracker.md",
    "M1j must preserve `RP-02 / TA-05` while adding six production-path contracts for typed edge source scope and then re-prove complete immutable runtime authority. Authoritative next Code + Build plan: `.agents/Directional/Architecture_M1j_Phase_Front_Edge_Source_Scope_Consumer_Code_Build_Plan.md`. Historical totals remain **34 / 14 / 20**.",
    "M1j adds six compiled production-path contracts for typed edge source scope. Authoritative build artifact `9076217893` is compile/package complete with no generated runtime execution; semantic acceptance therefore remains pending. The initial compile mismatch and superseded incomplete-manifest artifact are Code + Build/orchestration defects, not stable product regressions. Authoritative next runtime plan: `.agents/Directional/Architecture_M1j_Phase_Front_Edge_Source_Scope_Consumer_Artifact_Only_Test_Benchmark_Plan.md`. Historical totals remain **34 / 14 / 20**.",
)

print("M1j durable closeout updates applied")
