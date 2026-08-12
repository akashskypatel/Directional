from pathlib import Path


def replace_once(path: Path, old: str, new: str) -> None:
    text = path.read_text(encoding="utf-8")
    count = text.count(old)
    if count != 1:
        raise SystemExit(f"{path}: expected exactly one match, found {count}")
    path.write_text(text.replace(old, new, 1), encoding="utf-8")


plan = Path(".agents/Directional/Architecture_M1_Single_Authority_Cutover_Code_Build_Plan.md")
changelog = Path(".agents/Directional/CHANGELOG.md")

replace_once(
    plan,
    "**Current status:** R-A implementation bebac907de814b07a55a770add4c897ab6d22ffd compiled successfully but independent review found two blocking raw-payload read-back paths; R-A closure plus R-B through R-G remain selected  ",
    "**Current status:** R-A-REV-01 and R-A-REV-02 are compile-closed at source df386d1ad819879abbf9d7660c3d586778d7daee; R-B through R-G remain selected before any M1 runtime acceptance",
)
replace_once(
    plan,
    "The compile is valid evidence of buildability only. It is not runtime evidence and does not close R-A.\n\n### Blocking independent-review findings\n",
    """The compile is valid evidence of buildability only. It is not runtime evidence and does not close R-A.\n\n### R-A review-closure partial checkpoint\n\nThe two independent-review findings were closed in a bounded partial Code + Build turn without advancing R-B through R-G.\n\n| Evidence | Authority |\n|---|---|\n| Source authority | df386d1ad819879abbf9d7660c3d586778d7daee |\n| Compile run/job | 31555887046 / 93988102158 |\n| Result artifact | 9125984929, sha256:23da519d16f59b3ba86d6defab185f51446700c6b6e405b88a5c735453ecdc81 |\n| Log artifact | 9125985115, sha256:5a075c0ede75d79cb6b5ecc50d33c2e43a3f52d78b59bf5248bd33be14f7d051 |\n| Compile boundary | Release/static/Ninja/PRE_TEST, 118/118 |\n| Runtime boundary | no generated binary, discovery, test, benchmark, ctest, CLI, fuzzer, or custom input executed |\n\nR-A-REV-01 is compile-closed: materializer occurrences now carry typed IsolationSheetId and the reviewed cross-sheet equivalence, quotient-state, representative-ordering, and sheet-aggregation paths consume that member instead of SurfacePoint::sheet.\n\nR-A-REV-02 is compile-closed: completion fallback stitch identity is derived from typed lineage topology-region/isolation-sheet authority; raw provenance component/sheet no longer supplies semantic stitch identity, and missing typed fallback authority fails closed.\n\nThis checkpoint is not a full R-A-through-R-G package and is not runtime acceptance. The expanded R-G audit remains required to establish the complete R-A closure gate across all affected consumers.\n\n### Blocking independent-review findings — closed for the reviewed R-A paths\n""",
)
replace_once(
    plan,
    """The next Code + Build turn must:\n\n1. close both R-A review findings;\n2. finish R-B through R-G as the same vertical M1 cutover;\n3. compile/package the exact final source and expanded source audit without running generated runtime;\n4. produce a new full-cutover artifact; neither historical artifact 9105462679 nor R-A compile artifact 9124167871 may be relabeled as the acceptance candidate;\n5. hand only that full R-A-through-R-G package to the retained artifact-only plan.\n""",
    """The next Code + Build turn must:\n\n1. retain the compile-closed R-A-REV-01 and R-A-REV-02 corrections;\n2. finish R-B through R-G as the same vertical M1 cutover;\n3. compile/package the exact final source and expanded source audit without running generated runtime;\n4. produce a new full-cutover artifact; historical artifact 9105462679, R-A compile artifact 9124167871, and partial R-A review-closure artifact 9125984929 may not be relabeled as the acceptance candidate;\n5. hand only that full R-A-through-R-G package to the retained artifact-only plan.\n""",
)

replace_once(
    changelog,
    "## [Unreleased]\n\n### Changed\n",
    """## [Unreleased]\n\n### Fixed\n\n- Closed `R-A-REV-01`: materializer occurrences now own typed `IsolationSheetId`; reviewed cross-sheet equivalence, quotient-state, representative-ordering, and sheet-aggregation decisions no longer read `SurfacePoint::sheet` semantically.\n- Closed `R-A-REV-02`: completion fallback stitch identity derives from typed lineage topology-region/isolation-sheet authority rather than raw provenance component/sheet, and assembly fails closed with `MissingTypedStitchIdentity` when typed fallback authority is absent.\n\n### Validation\n\n- Partial R-A review-closure source authority: `df386d1ad819879abbf9d7660c3d586778d7daee`.\n- Compile-only run/job `31555887046 / 93988102158` completed Release/static/Ninja/PRE_TEST **118/118**. Result artifact `9125984929`, ZIP SHA-256 `23da519d16f59b3ba86d6defab185f51446700c6b6e405b88a5c735453ecdc81`; log artifact `9125985115`, ZIP SHA-256 `5a075c0ede75d79cb6b5ecc50d33c2e43a3f52d78b59bf5248bd33be14f7d051`.\n- Focused source audit passed for both R-A review findings. No generated Directional binary, discovery, test, benchmark, ctest, CLI, fuzzer, or custom input was executed.\n- This is build evidence for the two review corrections only; R-B through R-G remain open, M1 is not runtime accepted, immutable runtime authority remains M1l `bd140cff4572412e6f4ecd70a6ce0fe85310932c`, and runtime regression totals remain **34 events / 14 categories / 20 recurrences**.\n\n### Operational notes\n\n- Initial partial-closure compile run/job `31555727064 / 93987628937` stopped at compile step 82/118 on one stale local `sheet` alias after the typed occurrence member was introduced. The correction was limited to that remaining aggregation read; no generated runtime executed and no stable product regression was assigned.\n\n### Changed\n""",
)

print("durable R-A review-closure records patched")
