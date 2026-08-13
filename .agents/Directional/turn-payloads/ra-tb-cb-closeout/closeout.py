from pathlib import Path

SOURCE = "92bf0ae2b10856162f175d02aeac318e126f9d22"
RUN_JOB = "31655755100 / 94309741656"
RESULT_ID = "9164349848"
RESULT_SHA = "499bb4b4b6bd33408284bb3985bb04f0bda7312834b462b806965f7799e45870"
LOG_ID = "9164350085"
LOG_SHA = "a7fa938991c13d6a79cf4fdab85669d3e37e6eb625dc2541d8c8fdea2388938f"
APPLY_ID = "9164300537"
APPLY_SHA = "348f0c014ed115c143e2ac226151769f47cd0e42801705d3ceb196c467cdedb1"


def rewrite_lines(path: Path, replacements: dict[str, str]) -> None:
    lines = path.read_text().splitlines()
    seen = {k: 0 for k in replacements}
    out = []
    for line in lines:
        matched = False
        for prefix, replacement in replacements.items():
            if line.startswith(prefix):
                seen[prefix] += 1
                out.append(replacement)
                matched = True
                break
        if not matched:
            out.append(line)
    missing = [k for k, n in seen.items() if n != 1]
    if missing:
        raise RuntimeError(f"replacement prefix count mismatch in {path}: {[(k, seen[k]) for k in missing]}")
    path.write_text("\n".join(out) + "\n")


def replace_between(path: Path, start: str, end: str, new_block: str) -> None:
    text = path.read_text()
    i = text.index(start)
    j = text.index(end, i)
    path.write_text(text[:i] + new_block.rstrip() + "\n\n" + text[j:])


todo = Path("TODO.md")
rewrite_lines(todo, {
    "  R-A closeout sequence —":
        "  R-A closeout sequence — **artifact-only Step 3 attempt 1 failed organically; R-A-TB-CB-00 through R-A-TB-CB-04 are now Code + Build complete / compile-valid at `92bf0ae2b10856162f175d02aeac318e126f9d22`. The mandatory next cadence is one immutable Step 3 retry; Step 4 remains unsatisfied until runtime passes organically.**",
    "  - [ ] **R-A-TB-CB-00":
        "  - [x] **R-A-TB-CB-00 — mechanism inspection completed.** Runtime artifact `9163003950` does not serialize or print `surfaceCellTopologyRegionCount`, so the requested value could not be truthfully read. Exact-source inspection nevertheless confirms the independently reviewed mechanism: `phaseFrontProduct` points into local `traceNetwork`, the authoritative owner is copied before the move, and five post-move reads dereference the moved-from object. No count was fabricated.",
    "  - [ ] **R-A-TB-CB-01":
        "  - [x] **R-A-TB-CB-01 — post-move source-authority lifetime fixed at Code + Build boundary.** After moving `traceNetwork`, the stale `phaseFrontProduct` pointer is nulled and every later optimizer/final-validation consumer uses `result.surfaceCellContext.sourceTopologyRegions` through a retained pointer. Strict `source_optimization_has_complete_authority` and exact-source fail-closed checks remain unchanged. Added `PostMoveAggregateOptimizerUsesRetainedSourceAuthority`, which requires published authority to `matches_source_faces` the actual source matrices.",
    "  - [ ] **R-A-TB-CB-02":
        "  - [x] **R-A-TB-CB-02 — aggregate final-oracle reachability addressed at Code + Build boundary.** Source reasoning after CB-01 found no justification to synthesize boundary/feature authority or weaken seam guards; the existing F1/F3/F4 counterfactual fixtures are retained for the runtime retry, now with the premature empty-owner path removed. Their semantic reachability remains runtime-pending by design.",
    "  - [ ] **R-A-TB-CB-03":
        "  - [x] **R-A-TB-CB-03 — completion authority closure remediated at Code + Build boundary.** Completion now distinguishes source-face-only support resolution from source-geometry projection, generated-interior fixtures supply real source geometry, and published chart authority is the owner-valid chart closure over incident support faces within the selected region/sheet rather than one patch-local chart. Collision coverage now constructs real overlapping/non-identical owner-valid chart sets. No aliases, fabricated IDs, raw mirrors, or pre-intersection identities were restored.",
    "  - [ ] **R-A-TB-CB-04":
        "  - [x] **R-A-TB-CB-04 — optimizer contracts corrected at Code + Build boundary.** Replaced the raw `SurfacePoint.sheet` negative with `TriangleProjectionFailsClosedWhenTypedSourceAuthorityDoesNotMatchSourceFaces`, which supplies a typed authority bound to a different face ordering and requires `MissingSourceAuthority`; pinned the replacement in the R-A inventory. The rail-builder fixture now supplies exact source vertices/faces alongside `sourceAuthority`.",
    "  - [ ] **Step 2 retry — regenerate static inventory":
        f"  - [x] **Step 2 retry — regenerated static inventory and fresh exact-source compile package.** Source `{SOURCE}`; inventory **19 paths / 50 probes / 206 matches**, raw projection **22 allowed / 0 unexpected**, face-count **2 / 0**, pipeline `stitchIdentity` assignments **2 / 0**, stitch-kind self-test **4/4**, final static **PASS**. Compile run/job `{RUN_JOB}` completed Release/static/Ninja/PRE_TEST **118/118**, build exit `0`; result `{RESULT_ID}` SHA-256 `{RESULT_SHA}`, log `{LOG_ID}` SHA-256 `{LOG_SHA}`; 26 regular files, self-excluding manifest **25/25**, five empty source-status snapshots, `runtimeExecution=false`.",
})

handoff = Path(".agents/Directional/Future_Chat_Session_Handoff.md")
next_block = f'''## Mandatory next turn

Run one **immutable artifact-only R-A Test + Benchmark retry** against the fresh Code + Build package below. Do not rebuild, edit source/tests/fixtures, repair the package, or activate the dormant full-M1 plan.

Repository: `akashskypatel/Directional`  
Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`  
PR: #8 remains open, draft, and unmerged  
Exact candidate source: `{SOURCE}`  
Compile run/job: `{RUN_JOB}`  
Compile result artifact: `{RESULT_ID}`, SHA-256 `{RESULT_SHA}`  
Compile log artifact: `{LOG_ID}`, SHA-256 `{LOG_SHA}`

Pre-runtime requirements: verify the exact source commit, outer artifact digest, archive/path safety, self-excluding manifest **25/25**, dependency revisions, all five empty source-status snapshots, `runtimeExecution=false`, and the packaged **19-path / 50-probe / 206-match** R-A static inventory. A zero-selected filter is orchestration failure.

Execute the same continuous R-A closeout semantic gate that failed on attempt 1, including the F1/F3/F4 aggregate final-oracle contracts, complete `SurfaceCellAuthorityContractCutover.*` selection, retained completion authority contracts, source-authoritative validator contracts, optimizer/final-validator authority contracts, rail-authority migration, isolation-seam authority, source-support/chart authority, plus the new `PostMoveAggregateOptimizerUsesRetainedSourceAuthority` and typed source-authority mismatch optimizer negative. Do not weaken filters or substitute proxy tests.

If every selected contract passes organically and immutable postflight remains clean, mark Step 3 and Step 4 / R-A complete. Any organic semantic failure returns to a bounded Code + Build turn with the exact failing contract and runtime evidence. **No independent Review turn is requested before this retry.**

`R-A-TB-CB-00` through `R-A-TB-CB-04` are Code + Build complete / compile-valid at `{SOURCE}`. CB-00 specifically did not fabricate the unavailable `surfaceCellTopologyRegionCount`: artifact `9163003950` contains no serialized/printed instance of that field; exact-source inspection confirmed the reviewed use-after-move mechanism instead.

RA-REV-23-F3 and RA-REV-22-F6 remain post-R-A hygiene and do not block this runtime retry. M1l `bd140cff4572412e6f4ecd70a6ce0fe85310932c` remains immutable runtime authority until the candidate is organically accepted.'''
replace_between(handoff, "## Mandatory next turn", "## Current authority", next_block)
status_block = f'''### R-A closure status

- Overall R-A remains **open / runtime-pending** for candidate `{SOURCE}`; Code + Build does not establish semantic acceptance.
- `R-A-TB-CB-00` through `R-A-TB-CB-04` are Code + Build complete / compile-valid. CB-00 could not read `surfaceCellTopologyRegionCount` because neither retained runtime artifact serializes it; exact source confirms the use-after-move mechanism and no value was invented.
- CB-01 removes all five post-move `phaseFrontProduct->sourceTopologyRegions` reads, nulls the stale pointer, and routes consumers through the retained pre-move `surfaceCellContext.sourceTopologyRegions`; strict exact-source validation remains unchanged.
- CB-03 separates source-face support authority from geometry projection and publishes owner-valid chart closure over support faces, while generated-interior fixtures now provide real source geometry.
- CB-04 replaces the raw-sheet expectation with a typed exact-owner mismatch negative and completes the rail-builder source-scope fixture.
- Static inventory at `{SOURCE}`: **19 paths / 50 probes / 206 matches**, raw projection **22/0**, face-count **2/0**, pipeline `stitchIdentity` assignments **2/0**, stitch-kind self-test **4/4**, final **PASS**.
- Compile run/job `{RUN_JOB}`: Release/static/Ninja/PRE_TEST **118/118**, exit `0`; artifacts `{RESULT_ID} / {LOG_ID}`; manifest **25/25**; five empty statuses; no generated runtime executed.
- The mandatory next gate is the immutable artifact-only R-A semantic retry. M1l `bd140cff4572412e6f4ecd70a6ce0fe85310932c` remains runtime authority; historical regression totals remain **34 / 14 / 20**.'''
replace_between(handoff, "### R-A closure status", "## Standing product state", status_block)

plan = Path(".agents/Directional/Architecture_M1_Single_Authority_Cutover_Code_Build_Plan.md")
text = plan.read_text()
text = text.replace(
    "**Current status:** R-A artifact-only Step 3 attempt 1 executed against exact source `64fa65a9379ad0a246393371516de3a3a7146243` and **FAILED organically** (run/job `31652227682 / 94298883415`); immutable preflight/static inventory/postflight passed and orchestration was clean; overall R-A remains open and the mandatory next turn is section 0I Code + Build runtime remediation before a fresh compile package and artifact-only retry",
    f"**Current status:** R-A-TB-CB-00 through R-A-TB-CB-04 are **Code + Build complete / compile-valid** at `{SOURCE}` after the organic Step 3 failure; widened static inventory is PASS and fresh compile is 118/118; overall R-A remains open pending one immutable artifact-only semantic retry")
text = text.replace(
    "**Latest review-remediation implementation/compile source:** `64fa65a9379ad0a246393371516de3a3a7146243`",
    f"**Latest review-remediation implementation/compile source:** `{SOURCE}`")
plan.write_text(text)
section = f'''## 0I. Post-runtime R-A remediation after artifact-only Step 3 attempt 1 — Code + Build complete

Exact implementation/test/static-audit source: `{SOURCE}`. `R-A-TB-CB-00` through `R-A-TB-CB-04` are closed at the **Code + Build / compile-valid boundary only**. No generated semantic contract executed in this turn; overall R-A remains open pending the immutable artifact-only retry.

- **CB-00:** artifact `9163003950` was exhaustively inspected but does not serialize/print `surfaceCellTopologyRegionCount`; no value was fabricated. Exact-source inspection confirms the reviewed use-after-move: `phaseFrontProduct` points into local `traceNetwork`, the authoritative source owner is retained before the move, and five later reads dereference moved-from state.
- **CB-01:** after `traceNetwork` is moved, the stale `phaseFrontProduct` pointer is nulled and all five later authority consumers use a lifetime-safe `retainedSourceAuthority` derived from `result.surfaceCellContext.sourceTopologyRegions`. Strict `source_optimization_has_complete_authority` / exact source-row binding is unchanged. Added `PostMoveAggregateOptimizerUsesRetainedSourceAuthority` to pin `matches_source_faces` publication.
- **CB-02:** retained F1/F3/F4 aggregate final-oracle fixtures were not synthetically rewritten. With the premature empty-owner path removed, their boundary/feature/component-report reachability is reserved for the next runtime gate, preserving zero-publication and no-substitution semantics.
- **CB-03:** `complete_pure_quad_patch` now permits source-face-only support resolution while requiring full source geometry only for projection. Generated-interior fixtures supply real source vertices. Published chart authority is the complete owner-valid chart closure over incident support faces within the selected region/sheet, resolving false incompatibility between adjacent same-owner patches without aliases or fabricated authority. Collision coverage uses owner-valid overlapping/non-identical chart sets.
- **CB-04:** the obsolete raw-sheet expectation is replaced by `TriangleProjectionFailsClosedWhenTypedSourceAuthorityDoesNotMatchSourceFaces`, pinned by inventory and requiring `MissingSourceAuthority` under a real typed face-order mismatch. The rail-builder fixture carries exact source vertices/faces with its typed owner.
- **Static inventory:** **19 affected paths / 50 probes / 206 matches**, raw projection **22 allowed / 0 unexpected**, `complete_for_face_count` **2 / 0**, pipeline `stitchIdentity` assignments **2 / 0**, stitch-kind self-test **4 passed / 0 failed**, final static **PASS**.
- **Fresh compile:** run/job `{RUN_JOB}`, exact source `{SOURCE}`, Release/static/Ninja/PRE_TEST **118/118**, build exit `0`; ccache **102/108 hits (94.44%)**. Result artifact `{RESULT_ID}` SHA-256 `{RESULT_SHA}`; log artifact `{LOG_ID}` SHA-256 `{LOG_SHA}`; apply/static artifact `{APPLY_ID}` SHA-256 `{APPLY_SHA}`.
- **Package verification:** 26 regular files, zero symlinks, recursive self-excluding manifest **25/25**, zero self references, five empty source-status snapshots, exact source archive, `runtimeExecution=false`, `semanticContracts=compiled-not-executed`.

Mandatory next cadence: **one immutable artifact-only R-A Test + Benchmark retry against `{RESULT_ID} / {LOG_ID}` with no rebuild or source mutation.** Step 4 / R-A may close only after an organic semantic pass with clean pre/postflight. No independent Review turn is requested before the retry.'''
replace_between(plan, "## 0I.", "## 0H.", section)

changelog = Path(".agents/Directional/CHANGELOG.md")
text = changelog.read_text()
needle = "## [Unreleased]\n\n"
entry = f'''### Fixed — R-A-TB-CB-00 through R-A-TB-CB-04 runtime-gate remediation

- Fixed the post-move source-authority lifetime defect by retiring the stale phase-front pointer after moving the trace network and routing all later aggregate optimizer/final-validation consumers through the retained pre-move `SourceTopologyRegions` owner. Strict exact-source binding remains fail-closed.
- Completion now separates source-face support authority from geometry projection, generated-interior fixtures carry real source geometry, and same-owner adjacent patches publish the owner-valid chart closure over their support faces instead of incompatible patch-local singleton charts.
- Replaced the raw projection-sheet optimizer expectation with a typed source-authority/source-face mismatch negative and pinned it in the R-A audit; completed the rail-builder source matrices. Added a focused post-move retained-authority publication contract.
- CB-00 evidence limitation is retained explicitly: runtime artifacts `9163003523 / 9163003950` do not serialize or print `surfaceCellTopologyRegionCount`, so no count was inferred or fabricated; exact-source lifetime analysis confirms the use-after-move mechanism.

### Validation — R-A-TB-CB-00 through R-A-TB-CB-04 Code + Build

- Exact source `{SOURCE}`. Regenerated R-A inventory: **19 paths / 50 probes / 206 matches**, raw projection **22/0**, face-count **2/0**, pipeline `stitchIdentity` assignments **2/0**, classifier self-test **4/4**, final static **PASS**.
- Compile run/job `{RUN_JOB}` completed Release/static/Ninja/PRE_TEST **118/118**, exit `0`; ccache **102/108 hits (94.44%)**. Result `{RESULT_ID}` SHA-256 `{RESULT_SHA}`; log `{LOG_ID}` SHA-256 `{LOG_SHA}`; apply/static evidence `{APPLY_ID}` SHA-256 `{APPLY_SHA}`.
- Independent package inspection verified **26** regular files, zero symlinks, recursive self-excluding manifest **25/25**, five empty source-status snapshots, exact source archive, `runtimeExecution=false`, and `semanticContracts=compiled-not-executed`.
- A first control-plane attempt failed before source application because a single base64 payload was corrupted in transfer; the retry split it into four independently hashed chunks and reconstructed the exact pre-verified patch before apply. This was orchestration-only and executed no generated runtime.
- Overall R-A remains open. The next cadence is the immutable artifact-only semantic retry; M1l remains runtime authority and regression totals stay **34 / 14 / 20**.

'''
if needle not in text:
    raise RuntimeError("CHANGELOG insertion point missing")
changelog.write_text(text.replace(needle, needle + entry, 1))
