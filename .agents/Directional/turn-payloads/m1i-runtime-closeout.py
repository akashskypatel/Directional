from pathlib import Path


def replace_once(text: str, old: str, new: str, label: str) -> str:
    count = text.count(old)
    if count != 1:
        raise RuntimeError(f"{label}: expected one match, found {count}")
    return text.replace(old, new, 1)


def replace_prefix_before(text: str, marker: str, new_prefix: str, label: str) -> str:
    count = text.count(marker)
    if count != 1:
        raise RuntimeError(f"{label}: expected one marker, found {count}")
    return new_prefix.rstrip() + "\n\n" + marker + text.split(marker, 1)[1]


def replace_section(text: str, start_marker: str, end_marker: str, replacement: str, label: str) -> str:
    if text.count(start_marker) != 1 or text.count(end_marker) != 1:
        raise RuntimeError(
            f"{label}: marker counts start={text.count(start_marker)} end={text.count(end_marker)}"
        )
    start = text.index(start_marker)
    end = text.index(end_marker, start)
    return text[:start] + replacement.rstrip() + "\n\n" + text[end:]


# Live handoff: replace only the live current-turn prefix. Historical accepted sections remain intact.
path = Path('.agents/Directional/Future_Chat_Session_Handoff.md')
text = path.read_text()
new_prefix = """# Future Chat Session Handoff

## Mandatory next turn

Run **M1j Phase-Front Edge Source-Scope Consumer — Code + Build only** under:

`.agents/Directional/Architecture_M1j_Phase_Front_Edge_Source_Scope_Consumer_Code_Build_Plan.md`

Repository: `akashskypatel/Directional`, branch `agent/surface_cell_quad/p5-recover-bridge-healing`. Draft PR #8 stays open, draft, and unmerged. Product gate **G4 topology-distinct completion and singularities** remains active. M1a through M1i are immutable accepted. Review policy is `never`.

M1j is bounded to:

`SurfacePhaseFrontCell typed source scope -> SurfaceFrontEdge::{sourceComponent, sourceSheet, sourceIsolationSheets}`.

Migrate only edge-owned source-component/isolation-sheet authority to checked `SourceComponentId` / `IsolationSheetId`. Keep `SurfaceFrontEdge::sourceTopologyRegion` raw for a later `TopologyRegionId` slice. Region aggregation must validate established typed edge scope rather than overwrite it; still-raw downstream consumers use explicit named compatibility conversion. Do not expand into periodic/bounded-disk source-scope schemas, hard-rail/periodic owner IDs, M2-M6, or G4 behavior repair.

This next turn is **Code + Build only**. Execute no generated Directional binary, discovery/list command, test, benchmark, `ctest`, CLI/GUI/help/version command, fuzzer, or custom input.

## M1i immutable acceptance authority

M1i is accepted from implementation `b037157921094604f1b0c17f9c8b7076c7604b3b` and exact Code + Build artifacts `9072101943 / 9072102331`.

Runtime authority: producer discovery **208**, M1i focused **6/6**, required-green **193/193**, M1h-M1b focused preservation green, M1d route witnesses **3/3**, M1c transition counterexamples **3/3**, validation **77/77**, M1a **14/14**, T1 **29/29**, and Plane/MultiFaceSeam/CloseSheets/Cylinder independent-oracle clean without a fixture symlink. All eight historical/deferred red classes remain unchanged. Strict-validator timing remains deferred after fresh **0/10** characterization. Bunny remains `NotProductionReady:completion traceSegments=170831 arrangementCells=0 completedQuads=0`; Vase remains bounded safety-only at 60 seconds.

Heavy artifact-only run `31416928654` retained Bunny evidence/log artifacts `9073803244 / 9073803836` and Vase evidence/log artifacts `9073801150 / 9073801757`. Local and remote postflight preserved the exact result ZIP, **72/72** content manifest, 73 regular files, seven executables, two libraries, 27 fixtures, producer hash, and `fixtureSymlink=false`.

Historical regression totals remain **34 events / 14 categories / 20 recurrences**. `PR8-R034 / G4-R007` remains active.

Lessons that affect the next turn:

- M1b focused names belong to the validation executable; zero-selected filters are orchestration errors and never semantic passes.
- Temporary Actions YAML must not use an unindented shell heredoc inside a block scalar; two pre-job heavy runs failed syntax validation before the corrected run. Prefer a committed helper payload or indentation-safe one-line script when a temporary workflow needs Python.

Current immutable report:
`.agents/Directional/Architecture_M1i_Phase_Front_Cell_Source_Scope_Consumer_Artifact_Only_Test_Benchmark_Report.md`.

Authoritative next plan:
`.agents/Directional/Architecture_M1j_Phase_Front_Edge_Source_Scope_Consumer_Code_Build_Plan.md`.
"""
text = replace_prefix_before(text, '## M1h immutable acceptance authority', new_prefix, 'handoff live prefix')
path.write_text(text)


# Reorientation roadmap: status-only updates, preserving all architecture/history.
path = Path('.agents/Directional/REORIENTATION_PLAN.md')
text = path.read_text()
text = replace_once(
    text,
    '   M1i phase-front cell source-scope consumer [compile/package complete; immutable runtime next]\n   later bounded M1 consumers [pending]',
    '   M1i phase-front cell source-scope consumer [accepted]\n   M1j phase-front edge source-scope consumer [selected; Code + Build next]\n   later bounded M1 consumers [pending]',
    'reorientation map',
)
old = """M1i implementation `b037157921094604f1b0c17f9c8b7076c7604b3b` is compile/package complete at `phase_front_cell_source_scope -> SurfacePhaseFrontCell::{sourceComponent, sourceSheet, sourceIsolationSheets}`. Cell-owned component/sheet identity now crosses checked `SourceComponentId` / `IsolationSheetId` boundaries; neighboring raw representations remain explicit compatibility only.

Authoritative build/package run `31411770135` compiled **120/120** with exact artifacts `9072101943 / 9072102331`, recursive manifest **72/72**, and no generated Directional runtime execution. The first packaging attempt compiled successfully but its checksum verification used the wrong cwd; the corrected retry made no source delta. M1i semantic acceptance remains pending immutable runtime.

Authoritative next Artifact-Only Test + Benchmark plan:
`.agents/Directional/Architecture_M1i_Phase_Front_Cell_Source_Scope_Consumer_Artifact_Only_Test_Benchmark_Plan.md`."""
new = """M1i implementation `b037157921094604f1b0c17f9c8b7076c7604b3b` is immutable accepted at `phase_front_cell_source_scope -> SurfacePhaseFrontCell::{sourceComponent, sourceSheet, sourceIsolationSheets}` from exact artifacts `9072101943 / 9072102331`: producer discovery **208**, focused **6/6**, required-green **193/193**, full M1h-M1b/validation/M1a/T1/direct-product preservation, unchanged historical-red classes, Bunny known-red, Vase bounded safety-only, and exact **72/72** postflight. No new stable product regression or recurrence was created.

Accepted-source inspection selects M1j at `SurfacePhaseFrontCell typed source scope -> SurfaceFrontEdge::{sourceComponent, sourceSheet, sourceIsolationSheets}`. Edge publication currently downgrades typed cell authority back to raw integers and region aggregation later overwrites/normalizes those raw edge fields. M1j migrates only edge-owned component/sheet authority, keeps raw `sourceTopologyRegion` out of scope, and requires aggregators to verify rather than recreate semantic source scope.

Authoritative next Code + Build plan:
`.agents/Directional/Architecture_M1j_Phase_Front_Edge_Source_Scope_Consumer_Code_Build_Plan.md`."""
text = replace_once(text, old, new, 'reorientation M1i checkpoint')
path.write_text(text)


# Regression tracker: update only live status/pattern statements.
path = Path('.agents/Directional/Regression_Root_Cause_Tracker.md')
text = path.read_text()
text = replace_once(
    text,
    'Last updated: **2026-08-10 UTC** after M1i cell source-scope Code + Build from artifact `9072101943`; immutable runtime is next.',
    'Last updated: **2026-08-10 UTC** after immutable M1i cell source-scope acceptance from artifact `9072101943`; M1j edge source-scope authority is next.',
    'tracker last updated',
)
text = replace_once(
    text,
    'M1i implementation `b037157921094604f1b0c17f9c8b7076c7604b3b` compiled **120/120** and packaged as artifact `9072101943`; no generated runtime executed, so no stable product regression event or recurrence is assigned from M1i compile-only evidence.',
    'M1i implementation `b037157921094604f1b0c17f9c8b7076c7604b3b` is immutable accepted from artifact `9072101943`: focused **6/6**, required-green **193/193**, full entering preservation/direct-product authority, unchanged historical-red classes, bounded Bunny/Vase comparison, and exact postflight. No stable product regression event or recurrence is added.',
    'tracker historical M1i status',
)
text = replace_once(
    text,
    'M1h phase-front field charts cross checked `FieldChartId` boundaries before constructive-front semantic use and are **immutable accepted**. M1i now carries cell-owned source component/sheet state through checked `SourceComponentId` / `IsolationSheetId`; compile/package is complete and runtime acceptance is pending.',
    'M1h phase-front field charts cross checked `FieldChartId` boundaries before constructive-front semantic use and are **immutable accepted**. M1i cell-owned source component/sheet state through checked `SourceComponentId` / `IsolationSheetId` is **immutable accepted**. M1j next migrates the immediately adjacent `SurfaceFrontEdge` component/sheet consumer.',
    'tracker RP01',
)
old = """M1i source-scope migration adds six compiled production-path contracts covering `SourceComponentId` versus `IsolationSheetId`, multi-sheet no-representative semantics, malformed enabled labels, face-row permutation, and typed-to-legacy compatibility derivation. They remain runtime pending; compile success is not test authority. The first package attempt's wrong-working-directory checksum failure was orchestration-only and caused no source change.

Authoritative next immutable runtime plan: `.agents/Directional/Architecture_M1i_Phase_Front_Cell_Source_Scope_Consumer_Artifact_Only_Test_Benchmark_Plan.md`. Expected producer discovery is **208**, M1i focused **6/6**, and required-green **193/193**. Historical totals remain **34 / 14 / 20**."""
new = """M1i source-scope migration is immutable accepted: producer discovery **208**, M1i **6/6**, required-green **193/193**, M1h-M1b focused preservation, validation **77/77**, M1a **14/14**, T1 **29/29**, four direct products independent-oracle clean, all eight historical/deferred red classes unchanged, Bunny known-red, Vase bounded safety-only, and exact **72/72** postflight. The initial wrong-working-directory package checksum issue and a later zero-selected M1b executable-mapping mistake are orchestration defects only; neither changes semantic evidence.

M1j must preserve `RP-02 / TA-05` while adding six production-path contracts for typed edge source scope and then re-prove complete immutable runtime authority. Authoritative next Code + Build plan: `.agents/Directional/Architecture_M1j_Phase_Front_Edge_Source_Scope_Consumer_Code_Build_Plan.md`. Historical totals remain **34 / 14 / 20**."""
text = replace_once(text, old, new, 'tracker RP02')
text = replace_once(
    text,
    'Untouched by M1a–M1e. `G4-R007` remains active; M3/M4 own global conformity/certificate migration.',
    'M1i exposes the next bounded `RP-09` seam: typed cell source scope is currently downgraded and then overwritten on `SurfaceFrontEdge`. M1j owns only the correction that edge publication preserves typed component/sheet authority and region aggregation verifies rather than recreates it. Global conformity/certificate migration remains M3/M4; `G4-R007` stays active.',
    'tracker RP09',
)
path.write_text(text)


# Root TODO: replace only the live Active direction prefix; historical task evidence below is preserved byte-for-byte.
path = Path('TODO')
text = path.read_text()
new_prefix = """Last updated: 2026-08-10 UTC

## Active direction

- Phase: P5 — producer-correct direct surface paving.
- Product gate: **G4 topology-distinct completion and singularities active**.
- Test architecture: **T1 independent oracle/package foundation accepted**.
- Architecture migration: **M1a through M1i immutable accepted; M1j phase-front edge source-scope consumer selected for Code + Build**.
- M1i implementation `b037157921094604f1b0c17f9c8b7076c7604b3b` is accepted from exact artifacts `9072101943 / 9072102331`: producer **208**, focused **6/6**, required-green **193/193**, validation **77/77**, M1a **14/14**, T1 **29/29**, direct products green without fixture symlink, and all eight historical/deferred reds unchanged.
- Heavy run `31416928654`: Bunny unchanged `NotProductionReady:completion traceSegments=170831 arrangementCells=0 completedQuads=0`; Vase bounded safety-only at 60 seconds; exact **72/72** package authority preserved.
- Strict-validator timing remains deferred after fresh **0/10** characterization; no threshold/retry workaround is authorized.
- M1j seam: `SurfacePhaseFrontCell typed source scope -> SurfaceFrontEdge::{sourceComponent, sourceSheet, sourceIsolationSheets}`; migrate only edge-owned `SourceComponentId` / `IsolationSheetId` authority and keep raw `sourceTopologyRegion` out of scope.
- Authoritative next turn: `.agents/Directional/Architecture_M1j_Phase_Front_Edge_Source_Scope_Consumer_Code_Build_Plan.md`.
- Expected following runtime authority after M1j build: producer discovery **214**, M1j focused **6/6**, required-green **199/199**, plus full entering preservation and exact postflight.
- Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`; draft PR #8 stays open/unmerged; review policy `never`.
- Current immutable report: `.agents/Directional/Architecture_M1i_Phase_Front_Cell_Source_Scope_Consumer_Artifact_Only_Test_Benchmark_Report.md`.
"""
text = replace_prefix_before(text, '## M1d immutable acceptance', new_prefix, 'TODO active prefix')
path.write_text(text)


# Milestone G TODO: update current gate sentence and replace only the M1i status section.
path = Path('MILESTONE_G_TODO.md')
text = path.read_text()
text = replace_once(
    text,
    'Production remains known-red on direct torus. T1 independent authority and M1a through M1h architecture slices are immutable accepted. M1i phase-front cell source-scope Code + Build is complete and immutable runtime is next. Architecture migration remains separate from G4 product acceptance.',
    'Production remains known-red on direct torus. T1 independent authority and M1a through M1i architecture slices are immutable accepted. M1j phase-front edge source-scope authority is the next Code + Build slice. Architecture migration remains separate from G4 product acceptance.',
    'milestone current gate',
)
replacement = """## M1i phase-front cell source-scope authority — immutable accepted

Implementation `b037157921094604f1b0c17f9c8b7076c7604b3b` migrates only `SurfacePhaseFrontCell::{sourceComponent, sourceSheet, sourceIsolationSheets}` to checked `SourceComponentId` / `IsolationSheetId` while retaining neighboring raw representations as explicit compatibility boundaries.

Exact result/log artifacts `9072101943 / 9072102331` are immutable accepted. Runtime authority: producer discovery **208**, M1i **6/6**, required-green **193/193**, M1h-M1b focused preservation, M1d route witnesses **3/3**, M1c transition counterexamples **3/3**, validation **77/77**, M1a **14/14**, T1 **29/29**, and Plane/MultiFaceSeam/CloseSheets/Cylinder independent-oracle clean without fixture symlink. All eight historical/deferred red classes are unchanged. Strict-validator timing remains deferred after fresh **0/10** characterization.

Heavy run `31416928654` preserved Bunny's known `NotProductionReady:completion traceSegments=170831 arrangementCells=0 completedQuads=0` failure and bounded Vase at 60 seconds as safety-only evidence. Local and remote postflight preserved the exact package, producer hash, and **72/72** checksums. No stable product regression event or recurrence was created; `PR8-R034 / G4-R007` remains active.

Next architecture slice: **M1j Phase-Front Edge Source-Scope Consumer — Code + Build only** at `SurfacePhaseFrontCell typed source scope -> SurfaceFrontEdge::{sourceComponent, sourceSheet, sourceIsolationSheets}`. Keep raw `sourceTopologyRegion` out of scope and require region aggregation to validate rather than overwrite edge semantic source scope.

Authoritative plan: `.agents/Directional/Architecture_M1j_Phase_Front_Edge_Source_Scope_Consumer_Code_Build_Plan.md`.
Current immutable report: `.agents/Directional/Architecture_M1i_Phase_Front_Cell_Source_Scope_Consumer_Artifact_Only_Test_Benchmark_Report.md`.
"""
text = replace_section(
    text,
    '## M1i phase-front cell source-scope authority — compile/package complete; runtime pending',
    '## M1f vertex-continuation transport — immutable accepted',
    replacement,
    'milestone M1i section',
)
path.write_text(text)
