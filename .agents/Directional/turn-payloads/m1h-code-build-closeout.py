from pathlib import Path


def read(path):
    return Path(path).read_text(encoding="utf-8")


def write(path, text):
    Path(path).write_text(text, encoding="utf-8")


def replace_required(text, old, new, label, count=1):
    actual = text.count(old)
    if actual != count:
        raise SystemExit(f"{label}: expected {count} matches, found {actual}")
    return text.replace(old, new)


def replace_section(text, start_heading, next_heading, replacement, label):
    start = text.find(start_heading)
    if start < 0:
        raise SystemExit(f"{label}: missing start")
    end = text.find(next_heading, start + len(start_heading))
    if end < 0:
        raise SystemExit(f"{label}: missing end")
    return text[:start] + replacement.rstrip() + "\n\n" + text[end:]


implementation = "de4e2ba7c19d2e49931655dc22d758f50656d054"
result_artifact = "9066967620"
log_artifact = "9066968049"
report = ".agents/Directional/Architecture_M1h_Phase_Front_Field_Chart_Consumer_Code_Build_Report.md"
test_plan = ".agents/Directional/Architecture_M1h_Phase_Front_Field_Chart_Consumer_Artifact_Only_Test_Benchmark_Plan.md"
for required in (report, test_plan):
    if not Path(required).is_file():
        raise SystemExit(f"missing M1h authority file: {required}")

# Live handoff: replace only the mutable current-turn header and add the new
# compile/package checkpoint. Preserve all existing historical/lesson sections.
path = ".agents/Directional/Future_Chat_Session_Handoff.md"
text = read(path)
text = replace_section(
    text,
    "## Mandatory next turn",
    "## M1g immutable acceptance authority",
    f'''## Mandatory next turn

Run **M1h Phase-Front Field-Chart Consumer — immutable Test + Benchmark only** under:

`{test_plan}`

Repository: `akashskypatel/Directional`, branch `agent/surface_cell_quad/p5-recover-bridge-healing`. Draft PR #8 stays open, draft, and unmerged. Product gate **G4 topology-distinct completion and singularities** remains active. M1a through M1g are immutable accepted. M1h is compile/package complete and runtime pending. Review policy is `never`.

Consume only M1h result/log artifacts `{result_artifact} / {log_artifact}` produced from implementation `{implementation}`. Rebuild, relink, regeneration, source/test/build/fixture edits, repair, and substitution are prohibited. Expected producer discovery is **202**, M1h focused is **6/6** individually, and required-green producer is **187/187**. The package must resolve sibling `../test-data` directly; do not recreate the M1g runtime fixture symlink.

## M1h compile/package authority — runtime pending

Selected seam:
`build_planar_phase_frame -> UniformPhaseFrame::faceChart -> LocalLatticeState::sourceChart`.

| Evidence | Value |
|---|---|
| implementation | `{implementation}` |
| build run/job | `31398571348 / 93487537918` |
| result artifact / SHA-256 | `{result_artifact}` / `16d04835f9186b94fbb1ab987c5cd0bebd801daa7f368d01dc58139f67f5fe03` |
| log artifact / SHA-256 | `{log_artifact}` / `d6fa10a4b188b5569dfc73008c1a6e8a6f3a4e51f64cf4232a568087b36ac816` |
| recursive manifest | **69/69**, `63c7000e00cf8608861d1651d84c02ddf419581dd7763ba25a9b3837162b92c9` |
| package | **70** regular files including `SHA256SUMS`; 7 executables; 2 static libraries; 27 fixtures |
| build | **120/120**, Release/static/Ninja/PRE_TEST, **8:22.50**, peak RSS **1,850,536 KiB** |
| runtime | **false** |

M1h preserves the existing planar equal-orientation chart partition/BFS numbering, crosses it through checked `FieldChartId`, stores explicit typed optional authority in `LocalLatticeState`, and converts back only at legacy representation boundaries. Periodic and bounded-disk lattice state establish checked chart zero. Downstream hashing/equality/quotient compatibility was touched only as required by the typed state. `SurfaceTraceSegment::sourceChart` remains a compatibility integer schema.

Exactly six `SurfaceCellPhaseFrontFieldChartAuthorityMigration` contracts are compiled but unexecuted. The package also contains the executable-relative sibling fixture lookup correction identified by M1g runtime. No generated Directional binary, discovery, test, benchmark, `ctest`, CLI, fuzzer, or custom input ran in Code + Build.

Current report: `{report}`.

Authoritative next plan: `{test_plan}`.''',
    "handoff current turn",
)
write(path, text)

# TODO: update only live status lines and append the M1h checkpoint.
path = "TODO"
text = read(path)
text = replace_required(
    text,
    "- Architecture migration: **M1a through M1g immutable accepted; M1h Phase-Front Field-Chart Consumer Code + Build next**.",
    "- Architecture migration: **M1a through M1g immutable accepted; M1h Phase-Front Field-Chart Consumer compile/package complete, immutable runtime next**.",
    "TODO architecture status",
)
text = replace_required(
    text,
    "- Authoritative next turn: `.agents/Directional/Architecture_M1h_Phase_Front_Field_Chart_Consumer_Code_Build_Plan.md`.",
    f"- Authoritative next turn: `{test_plan}`.",
    "TODO next turn",
)
marker = "## Regression status"
if "## M1h compile/package checkpoint — immutable runtime pending" not in text:
    checkpoint = f'''## M1h compile/package checkpoint — immutable runtime pending

Selected seam:
`build_planar_phase_frame -> UniformPhaseFrame::faceChart -> LocalLatticeState::sourceChart`.

Implementation `{implementation}` is compile/package complete from run/job `31398571348 / 93487537918`. Result/log artifacts are `{result_artifact} / {log_artifact}` with ZIP SHA-256 `16d04835f9186b94fbb1ab987c5cd0bebd801daa7f368d01dc58139f67f5fe03 / d6fa10a4b188b5569dfc73008c1a6e8a6f3a4e51f64cf4232a568087b36ac816`. The package has **69/69** checksummed contents, 70 regular files, seven executables, two static libraries, and 27 fixtures. Build is **120/120** Release/static/Ninja/PRE_TEST and every runtime flag is false.

M1h changes exactly five production/test paths. Six focused field-chart contracts compile and remain unexecuted. The same slice corrects packaged fixture discovery to recognize sibling `../test-data`; immutable runtime must prove this without an external symlink.

Current report: `{report}`. Next immutable runtime: `{test_plan}`.'''
    text = replace_required(text, marker, checkpoint + "\n\n" + marker, "TODO M1h checkpoint marker")
text = replace_required(
    text,
    "- M1g `RP-01 / RP-05 / RP-07` periodic-route migration is **immutable accepted**; `RP-02 / TA-05` preservation is re-proven from exact artifact execution.",
    "- M1g `RP-01 / RP-05 / RP-07` periodic-route migration is **immutable accepted**; `RP-02 / TA-05` preservation is re-proven from exact artifact execution.\n- M1h `RP-01 / RP-05` field-chart migration is compile/package complete; six `RP-02 / TA-05` contracts are compiled but runtime acceptance remains pending.",
    "TODO regression M1h",
)
write(path, text)

# Milestone G: update current turn and append M1h checkpoint; preserve all
# historical accepted sections.
path = "MILESTONE_G_TODO.md"
text = read(path)
text = replace_required(
    text,
    "Production remains known-red on direct torus. T1 independent authority and M1a through M1g architecture slices are immutable accepted. M1h Phase-Front Field-Chart Consumer Code + Build is next. Architecture migration remains separate from G4 product acceptance.",
    "Production remains known-red on direct torus. T1 independent authority and M1a through M1g architecture slices are immutable accepted. M1h Phase-Front Field-Chart Consumer is compile/package complete and immutable runtime is next. Architecture migration remains separate from G4 product acceptance.",
    "milestone gate",
)
text = replace_section(
    text,
    "## Authoritative next turn",
    "## M1f vertex-continuation transport — immutable accepted",
    f'''## Authoritative next turn

Run **M1h Phase-Front Field-Chart Consumer — immutable Test + Benchmark only** under:

`{test_plan}`

Consume only exact artifacts `{result_artifact} / {log_artifact}` from implementation `{implementation}`. Expected producer discovery is **202**, M1h focused **6/6**, and required-green producer **187/187**. Rebuild/edit nothing. The package must locate sibling `../test-data` without an external fixture symlink.''',
    "milestone next turn",
)
marker = "## Regression disposition"
if "## M1h phase-front field-chart authority — compile/package complete" not in text:
    section = f'''## M1h phase-front field-chart authority — compile/package complete

Selected boundary:
`build_planar_phase_frame -> UniformPhaseFrame::faceChart -> LocalLatticeState::sourceChart`.

Implementation `{implementation}` retains deterministic chart partition/numbering, crosses checked `FieldChartId`, carries typed optional lattice chart authority, and uses explicit compatibility conversions downstream. The package-layout correction resolves executable-relative sibling `../test-data` before historical fallbacks.

| Evidence | Value |
|---|---|
| Build run/job | `31398571348 / 93487537918`, **120/120** |
| Result artifact / SHA-256 | `{result_artifact}` / `16d04835f9186b94fbb1ab987c5cd0bebd801daa7f368d01dc58139f67f5fe03` |
| Log artifact / SHA-256 | `{log_artifact}` / `d6fa10a4b188b5569dfc73008c1a6e8a6f3a4e51f64cf4232a568087b36ac816` |
| Recursive manifest | **69/69**, `63c7000e00cf8608861d1651d84c02ddf419581dd7763ba25a9b3837162b92c9` |
| Package | **70** regular files; 7 executables; 2 static libraries; 27 fixtures |
| M1h focused | exactly **6 compiled, unexecuted** |
| Build boundary | Release/static/Ninja/PRE_TEST; runtime **false** |

No stable regression event or recurrence is assigned from compile-only evidence. Runtime preservation and semantic acceptance remain pending.'''
    text = replace_required(text, marker, section + "\n\n" + marker, "milestone M1h checkpoint")
text = replace_required(
    text,
    "- M1g `RP-01 / RP-05 / RP-07` is **immutable accepted**; exact M1g artifact execution re-proved `RP-02 / TA-05` preservation.",
    "- M1g `RP-01 / RP-05 / RP-07` is **immutable accepted**; exact M1g artifact execution re-proved `RP-02 / TA-05` preservation.\n- M1h `RP-01 / RP-05` is compile/package complete; six focused `RP-02 / TA-05` contracts compile, with immutable runtime pending.",
    "milestone regression M1h",
)
text = replace_required(
    text,
    "- `.agents/Directional/Architecture_M1h_Phase_Front_Field_Chart_Consumer_Code_Build_Plan.md`;",
    f"- `{report}`;\n- `{test_plan}`;",
    "milestone references",
)
write(path, text)

# Reorientation roadmap: only update live M1h status/next evidence paragraph.
path = ".agents/Directional/REORIENTATION_PLAN.md"
text = read(path)
text = replace_required(
    text,
    "   M1h phase-front field-chart consumer [next]",
    "   M1h phase-front field-chart consumer [compile/package complete; runtime next]",
    "reorientation diagram",
)
old = """Next plan: `.agents/Directional/Architecture_M1h_Phase_Front_Field_Chart_Consumer_Code_Build_Plan.md`."""
new = f"""M1h implementation `{implementation}` is now compile/package complete. It preserves the established chart partition/numbering while adopting checked `FieldChartId` at the phase-frame/constructive-front boundary, carries typed optional lattice chart authority, and corrects packaged sibling `../test-data` lookup. Run/job `31398571348 / 93487537918` built **120/120** without generated runtime execution; exact artifacts are `{result_artifact} / {log_artifact}` with a **69/69** content manifest. Six M1h contracts compile but remain unexecuted.

Next immutable Test + Benchmark plan: `{test_plan}`."""
text = replace_required(text, old, new, "reorientation M1h live checkpoint")
write(path, text)

# Regression tracker: update current state and add only the new compile record.
path = ".agents/Directional/Regression_Root_Cause_Tracker.md"
text = read(path)
text = replace_required(
    text,
    "Last updated: **2026-08-10 UTC** after immutable M1g acceptance from artifact `9053047653`; M1h phase-front field-chart consumer is next.",
    f"Last updated: **2026-08-10 UTC** after M1h compile/package completion from artifact `{result_artifact}`; immutable M1h runtime is next.",
    "tracker current date",
)
text = replace_required(
    text,
    "Accepted M1g artifact `9053047653` likewise creates no stable product regression event or recurrence; M1g semantic acceptance is complete. `PR8-R034 / G4-R007` remains active.",
    f"Accepted M1g artifact `9053047653` likewise creates no stable product regression event or recurrence; M1g semantic acceptance is complete. M1h compile artifact `{result_artifact}` creates no stable product regression event from compile-only evidence; semantic acceptance remains pending. `PR8-R034 / G4-R007` remains active.",
    "tracker historical status",
)
text = replace_required(
    text,
    "- M1g periodic crossings cross checked source-vertex/interior-transition boundaries before `TransitionStep` construction and are **immutable accepted**.",
    "- M1g periodic crossings cross checked source-vertex/interior-transition boundaries before `TransitionStep` construction and are **immutable accepted**.\n- M1h phase-front field charts cross checked `FieldChartId` boundaries before constructive-front semantic use; compile/package is complete and runtime acceptance is pending.",
    "tracker RP01",
)
text = replace_required(
    text,
    "Focused migration tests do not replace this authority. M1g preservation passed exact artifact execution from `9053047653`.",
    "Focused migration tests do not replace this authority. M1g preservation passed exact artifact execution from `9053047653`. M1h adds six focused contracts, but `RP-02 / TA-05` preservation remains pending until exact artifact runtime.",
    "tracker RP02",
)
marker = "## Current G4 stable-ID mapping"
if "## M1h compile/package pattern record — runtime pending" not in text:
    record = f'''## M1h compile/package pattern record — runtime pending

M1h implementation `{implementation}` migrates the real field-chart owner `build_planar_phase_frame -> UniformPhaseFrame::faceChart -> LocalLatticeState::sourceChart` from bare semantic integers to checked `FieldChartId`, while retaining legacy representation only at explicit compatibility boundaries. The deterministic chart partition/BFS numbering is unchanged. Missing typed lattice chart authority is fail-closed before aggregate front acceptance. Periodic and bounded-disk single-chart lattice states use checked chart zero.

Compile/package authority:

- run/job `31398571348 / 93487537918`, **120/120**;
- result artifact `{result_artifact}`, ZIP SHA-256 `16d04835f9186b94fbb1ab987c5cd0bebd801daa7f368d01dc58139f67f5fe03`;
- log artifact `{log_artifact}`, ZIP SHA-256 `d6fa10a4b188b5569dfc73008c1a6e8a6f3a4e51f64cf4232a568087b36ac816`;
- manifest **69/69**, SHA-256 `63c7000e00cf8608861d1651d84c02ddf419581dd7763ba25a9b3837162b92c9`;
- six focused M1h contracts compiled and unexecuted;
- all Code + Build runtime flags false;
- packaged sibling `../test-data` resolution correction compiled;
- current report `{report}`.

No new stable regression event or recurrence is assigned. `RP-01 / RP-05` and `RP-02 / TA-05` remain runtime pending for M1h. `RP-07` is preservation-only and unchanged.'''
    text = replace_required(text, marker, record + "\n\n" + marker, "tracker M1h record")
write(path, text)

print("m1h_closeout_docs=pass")
