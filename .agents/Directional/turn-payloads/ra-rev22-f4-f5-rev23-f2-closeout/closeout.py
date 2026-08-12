from pathlib import Path

SOURCE = "64fa65a9379ad0a246393371516de3a3a7146243"
RUN = "31649372167"
JOB = "94290107577"
RESULT = "9162042615"
RESULT_SHA = "c521a94e087f660cf93b6ebb9791ae1d0979a885e89eee621bc9c2fa6efe9322"
LOG = "9162042971"
LOG_SHA = "58c64afba7d0c31ea83ac8922128c338694fbf5f0bc94150b94138d94bc6c0e8"


def load(path: str) -> str:
    return Path(path).read_text(encoding="utf-8")


def save(path: str, text: str) -> None:
    Path(path).write_text(text if text.endswith("\n") else text + "\n", encoding="utf-8")


def replace_once(text: str, old: str, new: str, label: str) -> str:
    if old not in text:
        raise SystemExit(f"{label}: target missing")
    return text.replace(old, new, 1)


def replace_between(text: str, start_marker: str, end_marker: str, replacement: str, label: str) -> str:
    start = text.find(start_marker)
    if start < 0:
        raise SystemExit(f"{label}: start marker missing")
    end = text.find(end_marker, start)
    if end < 0:
        raise SystemExit(f"{label}: end marker missing")
    return text[:start] + replacement + text[end:]


# TODO: close Code + Build steps 1-2 and make the artifact-only gate the only live R-A action.
path = "TODO.md"
s = load(path)
start = "  R-A closeout sequence — **R-A is one continuous checkpoint and must be implemented all the way through before any Test + Benchmark turn is executed.**"
end = "  - [ ] Complete R-B through R-G and produce one fresh full M1 package."
replacement = f'''  R-A closeout sequence — **R-A remains one continuous checkpoint. Code + Build steps 1-2 are complete; the only live R-A action is the immutable artifact-only gate.**
  - [x] **Step 1 — Code + Build RA-REV-22-F4** at `{SOURCE}`: added present-but-wrong remapped boundary and feature authority negatives, a non-vacuous feature-bearing positive witness, full final-oracle issue-list diagnostics, and inventory probes pinning the new contracts.
  - [x] **Step 1 — Code + Build RA-REV-22-F5** at `{SOURCE}`: removed the residual non-falsifiable usage-option `EXPECT_TRUE` assertions while retaining published-vs-oracle equality checks and input-derived semantic observations.
  - [x] **Step 1 — Code + Build RA-REV-23-F2** at `{SOURCE}`: hardened the whole-statement stitch-kind classifier across all `src/pipeline` translation units, covers wrapped/fully-qualified/stale-copy/alias forms and member writes, and includes a four-case audit self-test.
  - [x] **Step 1 — regenerate the complete R-A inventory**: **19 paths, 48 probes, 203 matches, 22 allowed/0 unexpected raw-projection leaves, 2 allowed/0 unexpected face-count leaves, 2 allowed/0 unexpected pipeline `stitchIdentity` assignments, 4/4 stitch-kind self-tests, final static PASS**.
  - [x] **Step 2 — fresh compile package** from exact source `{SOURCE}`: run/job `{RUN} / {JOB}`, artifacts `{RESULT} / {LOG}`, Release/static/Ninja/PRE_TEST **118/118**, build exit `0`, self-excluding manifest **25/25**, five empty source-status snapshots, `semanticContracts=compiled-not-executed`, `runtimeExecution=false`.
  - [ ] **Step 3 — single artifact-only Test + Benchmark** on exact package `{RESULT} / {LOG}`, with no rebuild or source changes. Execute the new F4 boundary/feature content negatives and feature-bearing positive, retained F1-F3 final-oracle/publication contracts, renamed aggregation-seam guards, and retained REV-21-through-REV-24 / rollback / zero-publication contracts. A zero-selected filter is orchestration failure.
  - [ ] **Step 4 — mark R-A complete** only if step 3 passes organically and the packaged/regenerated static inventory remains clean. Any organic failure returns to Code + Build; R-A does not close on a partial pass.
'''
s = replace_between(s, start, end, replacement, "TODO R-A closeout sequence")
save(path, s)


# Active Code + Build plan: add the completed remediation checkpoint and retain 0G as reviewed history.
path = ".agents/Directional/Architecture_M1_Single_Authority_Cutover_Code_Build_Plan.md"
s = load(path)
s = replace_once(
    s,
    "**Current status:** RA-REV-22-F1/F2/F3 and RA-REV-23-F1 are independently re-reviewed **CLOSED at the Code + Build boundary** at `032d4cbae9e2de2767579934682e78754180338d`; the widened complete R-A inventory is reproducibly PASS; three follow-ups (RA-REV-22-F4, RA-REV-22-F5, RA-REV-23-F2) are open as section 0G and are the **next turn**; R-A is one continuous checkpoint, so no Test + Benchmark turn runs until they land and a fresh package exists",
    f"**Current status:** RA-REV-22-F4/F5 and RA-REV-23-F2 are Code + Build remediated / compile-valid at `{SOURCE}`; the widened complete R-A inventory is reproducibly PASS; a fresh exact-source compile package exists; overall R-A remains open pending the single immutable artifact-only Test + Benchmark gate",
    "Code+Build plan current status",
)
s = replace_once(
    s,
    "**Latest review-remediation implementation/compile source:** `032d4cbae9e2de2767579934682e78754180338d`",
    f"**Latest review-remediation implementation/compile source:** `{SOURCE}`",
    "Code+Build plan source",
)
marker = "## 0G. 2026-08-12 open Code + Build items after independent re-review — RA-REV-22-F4, RA-REV-22-F5, RA-REV-23-F2\n"
section = f'''## 0H. 2026-08-12 RA-REV-22-F4/F5 and RA-REV-23-F2 Code + Build remediation

Exact implementation/test/static-audit source: `{SOURCE}`. This closes the three independent re-review follow-ups at the Code + Build/static-contract boundary only. No new semantic contract executed in this turn; overall R-A remains open.

- **RA-REV-22-F4:** the aggregate final-oracle counterfactual coverage now includes present-but-wrong remapped authority. `FinalMergedOracleRejectsChangedRemappedBoundaryLoopContent` keeps boundary authority present but changes loop content and requires `ChangedBoundaryLoop`; `FinalMergedOracleRejectsChangedRemappedFeatureRailContent` preserves feature authority cardinality but supplies a rail absent from the merged output and requires `MissingFeatureRail`; `FeatureBearingFinalMergedOracleAcceptsPresentRemappedFeatureAuthority` observes a non-empty feature-rail authority set. Final-oracle rejection diagnostics retain the complete validator issue list so preferred single-code selection cannot stand in for guard evidence.
- **RA-REV-22-F5:** removed the remaining `EXPECT_TRUE` assertions whose values were caller-option echoes. Published-vs-oracle equality checks and input-derived boundary/feature/topology observations remain.
- **RA-REV-23-F2:** the R-A audit uses whole-statement classification across all `src/pipeline` translation units, rejects stitch-kind member writes including stale `.kind` copies and alias/qualified/wrapped enum forms, classifies `stitchIdentity` member assignments, and runs four independent evasion self-tests.
- **Complete inventory regenerated:** **19 paths / 48 probes / 203 matches**, raw projection **22 allowed / 0 unexpected**, face-count **2 / 0**, pipeline `stitchIdentity` assignments **2 / 0**, stitch-kind self-test **4 passed / 0 failed**, final static **PASS**.
- **Fresh compile:** run/job `{RUN} / {JOB}` compiled exact source `{SOURCE}` through the mandatory reusable cached workflow. Release/static/Ninja/PRE_TEST **118/118**, build exit `0`; result artifact `{RESULT}` SHA-256 `{RESULT_SHA}`; log artifact `{LOG}` SHA-256 `{LOG_SHA}`.
- **Package verification:** **26** regular files, recursive self-excluding manifest **25/25**, zero self references, five empty source-status snapshots, exact source archive/dependency revisions, `semanticContracts=compiled-not-executed`, `runtimeExecution=false`. ccache recorded **95/108 hits (87.96%)** and the branch cache lineage was pruned to two compatible entries.

Mandatory next cadence: one immutable artifact-only Test + Benchmark turn against exact package `{RESULT} / {LOG}` with no rebuild. It must execute the new F4 content-mismatch/feature-positive contracts together with the complete retained R-A contract set. Do not mark R-A complete from compile/static evidence alone.

'''
if marker not in s:
    raise SystemExit("Code+Build 0G marker missing")
s = s.replace(marker, section + marker, 1)
s = replace_once(
    s,
    marker.strip(),
    "## 0G. Retained 2026-08-12 independent re-review findings before RA-REV-22-F4/F5 and RA-REV-23-F2 remediation",
    "Code+Build 0G retained heading",
)
s = replace_once(
    s,
    "The independent re-review at `032d4cbae9e2de2767579934682e78754180338d` closed RA-REV-22-F1/F2/F3 and RA-REV-23-F1 at the Code + Build boundary and opened three follow-ups. **This is closeout step 1 and the mandatory next turn.** R-A is one continuous checkpoint: all three must land, and a fresh package must be produced, before any Test + Benchmark turn runs. Package `9160266493 / 9160266848` is retained compile history and is superseded as a runtime candidate — do not execute it.",
    "The independent re-review at `032d4cbae9e2de2767579934682e78754180338d` opened the three findings below. **Retained as the pre-remediation specification only; section 0H records their Code + Build closure.**",
    "Code+Build 0G retained intro",
)
save(path, s)


# Handoff: replace stale Code + Build next action with the immutable artifact-only gate.
path = ".agents/Directional/Future_Chat_Session_Handoff.md"
s = load(path)
next_turn = f'''## Mandatory next turn

Run **step 3 of the continuous R-A closeout sequence**: one immutable **artifact-only Test + Benchmark turn** against the fresh RA-REV-22-F4/F5 and RA-REV-23-F2 correction package. Do not rebuild or change implementation, test, benchmark, build, fixture, or inventory source.

Repository: `akashskypatel/Directional`
Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`
PR: #8 remains open, draft, and unmerged
Exact compile-valid implementation/test/audit source: `{SOURCE}`
Compile run/job: `{RUN} / {JOB}`
Result artifact: `{RESULT}`, SHA-256 `{RESULT_SHA}`
Log artifact: `{LOG}`, SHA-256 `{LOG_SHA}`

Before executing any packaged binary, verify exact source `{SOURCE}`, both outer artifact digests, recursive self-excluding manifest **25/25** with zero self references, all five empty source-status snapshots, dependency revisions, Release/static/Ninja/PRE_TEST build exit `0`, and `runtimeExecution=false`. Extract the packaged source archive only for evidence inspection and verify `R_A_Closure_Inventory_Report.md` reports **19 paths, 48 probes, 203 matches, 22/0 raw-projection leaves, 2/0 face-count leaves, 2/0 pipeline `stitchIdentity` assignments, 4/4 stitch-kind classifier self-tests, final static PASS**.

Then execute the complete focused R-A gate, without rebuilding. It must include:

- `FinalMergedOracleRejectsChangedRemappedBoundaryLoopContent`, requiring the actual final-oracle issue list to contain `ChangedBoundaryLoop` with zero aggregate publication;
- `FinalMergedOracleRejectsChangedRemappedFeatureRailContent`, preserving non-empty feature authority/cardinality and requiring the actual final-oracle issue list to contain `MissingFeatureRail` with zero publication;
- `FeatureBearingFinalMergedOracleAcceptsPresentRemappedFeatureAuthority`, which must prove its precondition `expectedFeatureRailCount > 0` before acceptance;
- retained `FinalMergedOracleRejectsMissingRemappedBoundaryAuthority`, `FinalMergedOracleRejectsMissingRemappedFeatureAuthority`, `FinalOracleOutcomePublishesWhenComponentValidationReportIsMissing`, `DisconnectedAggregationPublishesGlobalOwnerAndRebuildsIdentityCaches`, and the renamed component aggregation-seam tamper contracts;
- retained REV-21 permutation-pair, REV-23 canonical/re-stitch, REV-24 null/foreign-authority, transactional rollback, optimizer/final-validator authority, and zero-publication contracts needed to detect regressions.

A zero-selected filter is orchestration failure. If a feature-bearing test fails its explicit fixture precondition, classify it as fixture adequacy rather than a semantic contract failure and return to Code + Build. Classify every failure from immutable runtime evidence. Do not rebuild, weaken validation, restore aliases/fallbacks, or alter fixtures inside this Test + Benchmark turn.

Mark overall R-A complete only if this single gate passes organically and the packaged/regenerated static inventory remains clean. Any organic failure returns to Code + Build; R-A does not close on a partial pass.

The retained full M1 artifact-only plan remains dormant until one fresh complete R-A-through-R-G package exists. Do not implement M3, M4, M7, or Pipeline A during this cadence turn.
'''
s = replace_between(s, "## Mandatory next turn\n", "## Current authority\n", next_turn + "\n", "handoff next turn")
status = f'''### R-A closure status

- Overall R-A remains **open / not runtime-accepted**.
- RA-REV-22-F1/F2/F3 and RA-REV-23-F1 remain independently re-reviewed closed at the Code + Build boundary at `032d4cbae9e2de2767579934682e78754180338d`.
- RA-REV-22-F4/F5 and RA-REV-23-F2 are now **Code + Build remediated / compile-valid** at exact source `{SOURCE}`. They are not independently or runtime accepted.
- F4 adds present-but-wrong boundary/feature final-oracle negatives, a feature-bearing positive witness, and full final-oracle issue-list diagnostics. F5 removes residual option-echo assertions. F2 hardens structural stitch-kind auditing across every pipeline translation unit and proves four evasion cases are caught.
- Complete R-A inventory is regenerated and static-PASS: **19 paths, 48 probes, 203 matches, 22/0 raw-projection leaves, 2/0 face-count leaves, 2/0 pipeline `stitchIdentity` assignments, 4/4 stitch-kind self-tests**.
- Fresh compile evidence: run/job `{RUN} / {JOB}`, artifacts `{RESULT} / {LOG}`, exact source `{SOURCE}`, Release/static/Ninja/PRE_TEST **118/118**, build exit `0`, manifest **25/25**, five empty source-status snapshots, `runtimeExecution=false`.
- No new semantic contract executed in this Code + Build turn. M1l `bd140cff4572412e6f4ecd70a6ce0fe85310932c` remains immutable runtime authority; regression totals remain **34 events / 14 categories / 20 recurrences**.
'''
s = replace_between(s, "### R-A closure status\n", "## Standing product state\n", status + "\n", "handoff R-A status")
save(path, s)


# Changelog: record durable completed Code + Build remediation/evidence only.
path = ".agents/Directional/CHANGELOG.md"
s = load(path)
marker = "## [Unreleased]\n\n"
entry = f'''## [Unreleased]

### Fixed — RA-REV-22-F4/F5 and RA-REV-23-F2 post-re-review remediation

- RA-REV-22-F4 adds final-oracle content-mismatch contracts for present remapped boundary and feature authority, a non-vacuous feature-bearing aggregate positive witness, and complete final-oracle issue-list diagnostics so preferred single-code reporting cannot mask the rejecting guard.
- RA-REV-22-F5 removes the residual non-falsifiable usage-option assertions while retaining published-vs-oracle equality and input-derived semantic assertions.
- RA-REV-23-F2 hardens the structural stitch-kind audit across all `src/pipeline` translation units, including wrapped/qualified/alias/stale-kind-copy/member-write forms, and adds a four-case classifier self-test.

### Validation — RA-REV-22-F4/F5 and RA-REV-23-F2 Code + Build

- Exact implementation/test/audit source: `{SOURCE}`. Regenerated complete R-A inventory: **19 paths / 48 probes / 203 matches**, **22/0** raw-projection leaves, **2/0** face-count leaves, **2/0** pipeline `stitchIdentity` assignments, stitch-kind self-test **4 passed / 0 failed**, final static **PASS**.
- Focused compile run/job `{RUN} / {JOB}` completed Release/static/Ninja/PRE_TEST **118/118**, build exit `0`. Result artifact `{RESULT}`, SHA-256 `{RESULT_SHA}`; log artifact `{LOG}`, SHA-256 `{LOG_SHA}`.
- Independent package inspection verified **26** regular files, recursive self-excluding manifest **25/25**, zero self references, five empty source-status snapshots, exact source archive/dependency revisions, `semanticContracts=compiled-not-executed`, and `runtimeExecution=false`. ccache recorded **95/108 hits (87.96%)** and the compatible cache lineage remains bounded to two entries.
- This closes the three findings at the Code + Build/static-contract boundary only. Overall R-A remains open pending the single artifact-only gate over the complete R-A contract set.

'''
if marker not in s:
    raise SystemExit("CHANGELOG marker missing")
s = s.replace(marker, entry, 1)
save(path, s)


# Independent review report: retain the review verdict, add a bounded post-review implementation status only.
path = ".agents/Directional/Architecture_Redesign_and_M1_RA_Independent_Review_Report.md"
s = load(path)
anchor = "**Latest independent re-review verdict at source `032d4cbae9e2de2767579934682e78754180338d`:** **RA-REV-22-F1/F2/F3 and RA-REV-23-F1 are CLOSED at the Code + Build boundary. Three new follow-ups are opened (RA-REV-22-F4, RA-REV-22-F5, RA-REV-23-F2); all three must land in Code + Build before any Test + Benchmark turn, because R-A is one continuous checkpoint. Overall R-A remains rejected/open pending organic runtime execution.**\n"
status_line = anchor + f"**Post-re-review remediation status:** **RA-REV-22-F4/F5 and RA-REV-23-F2 are Code + Build remediated / compile-valid at `{SOURCE}` with widened static inventory PASS and a fresh compile package; this is implementation/build evidence, not a new independent review or runtime acceptance.**\n"
s = replace_once(s, anchor, status_line, "review report top status")
marker = "## Independent re-review addendum — RA-REV-22-F1/F2/F3 and RA-REV-23-F1 closure\n"
addendum = f'''## Post-re-review remediation addendum — RA-REV-22-F4/F5 and RA-REV-23-F2

This is a **Code + Build implementation-status addendum**, not an independent re-review. Exact implementation/test/audit source `{SOURCE}` resolves the three follow-ups specified below; the fresh package has compiled successfully but no semantic contract has executed.

- **RA-REV-22-F4 remediated at Code + Build:** present-but-wrong remapped boundary content requires `ChangedBoundaryLoop`; present-but-wrong feature rail content preserves expected cardinality and requires `MissingFeatureRail`; a feature-bearing positive witness observes non-empty feature authority; final aggregate rejection diagnostics retain the complete source-authority validator issue list.
- **RA-REV-22-F5 remediated at Code + Build:** the option-echo `EXPECT_TRUE` assertions identified by the re-review are absent. Falsifiable published-vs-oracle equality and input-derived semantic checks remain.
- **RA-REV-23-F2 remediated at Code + Build:** pipeline stitch-kind audit is whole-statement and translation-unit-wide, recognizes fully qualified/wrapped/alias/stale-kind-copy forms and member writes, and its four independent evasion self-tests all pass.
- **Static evidence:** regenerated inventory **19 paths / 48 probes / 203 matches**, with **22/0** raw-projection leaves, **2/0** face-count leaves, **2/0** pipeline `stitchIdentity` assignments, classifier self-test **4/4**, final static **PASS**.
- **Compile evidence:** run/job `{RUN} / {JOB}`, exact source `{SOURCE}`, Release/static/Ninja/PRE_TEST **118/118**, build exit `0`; artifacts `{RESULT} / {LOG}` with SHA-256 `{RESULT_SHA}` / `{LOG_SHA}`; manifest **25/25**, five empty source-status snapshots, `runtimeExecution=false`.

**Remaining gate:** the single immutable artifact-only Test + Benchmark turn must execute these new contracts together with the complete retained R-A set. Overall R-A remains rejected/open until that gate passes organically.

'''
if marker not in s:
    raise SystemExit("review report re-review marker missing")
s = s.replace(marker, addendum + marker, 1)
save(path, s)
