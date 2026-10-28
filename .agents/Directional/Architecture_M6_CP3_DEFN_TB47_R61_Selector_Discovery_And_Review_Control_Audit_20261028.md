# TB47 same-turn R61 — selector discovery and review-control boundary audit (2026-10-28)

**Canonical owner:** `M6-CP3-DEFN-RP01-TB47-GAUGE-CLUSTER` (independent DEFN/Review, **still incomplete**). **Source authority:** exact snapshot run `40716570290`, event/source `b3a1a3d2691e23924454eb5e6e544bee1d705c6a`, artifact `12829495250`, outer SHA-256 `e3643efd9fc4176414cd5ac5a859f27ae912db0f5119257407310ea977e73369`. The inner source archive passed its SHA-256 check and all **5,956/5,956** manifest file hashes. The unchanged real checker is `.agents/Directional/tools/review_check.py`, SHA-256 `2f0315fbdba164eb93567b7c9b3307a36b916bd4a49c57c7b991cc0ad450484e`; frozen TB47 v2 TSV is `488a20b658fc18ddf64addacd9f3150b35b68b067fd37ba7b11346db958d5955` (504 rows + header). This is a **review-only offline audit**; no Directional C++ binary, compile, benchmark, or immutable TB gate was executed, and no product, source, test, selector, workflow or frozen manifest was edited.

## New independent finding: selector-file identity is lost

The real checker's `selector_paths()` (`review_check.py` approximately lines 91–98) scans matching filenames but writes them to `out[int(m.group(1))] = path`. This silently overwrites every earlier filename with the same trailing numeric selector count. That count is **not a unique selector identity** under Directional's retention policy. The exact working source tree contains **45** matching `Required_Green_Selector_<N>.txt` files, but only **39** integer keys. Five keys collide, leaving **six files unrepresented** in the resulting dictionary: 373 (2 files), 380 (2), 382 (2), 403 (3), and 408 (2). Those are actual repository names, not fabricated collisions. Iteration of `os.listdir()` is not an authority-sanctioned choice of which historical file wins.

Additionally, `boundary` only iterates the **currently present** discovered files. A fully committed deletion of the only file for a selector number makes the entry disappear from the iteration; `git status --porcelain` is clean, and `authority` scopes code drift to `src`, `include`, `tests`, `benchmarks`, `CMakeLists.txt`, and `cmake`. Its `CODE_SURFACES` also omits the review checker itself and `.github/workflows`. `ledgers` only checks CHANGELOG and LESSONS line counts. Thus, the three helpers **cannot collectively certify committed selector-file preservation or committed review-tool/workflow immutability**. This is distinct from R51's frozen TB47 TSV omission and R38/R50/R60's historical ledger defects, although the repair should share an explicit frozen-evidence authority model.

## Source-faithful discriminating replay

An isolated disposable Git repository copied the **exact real checker bytes**; the only checker adaptation was rebinding its hard-coded rewrite-base SHA to the synthetic initial commit (required because the actual Directional Git DAG is not in the snapshot). It copied representative selector naming, durable baseline headings, a source `src/sentinel.cpp`, tool and workflow files, and append-only ledgers. No repo-specific production runtime or testing was invoked.

| Synthetic committed state / control | `authority` | `boundary` | `ledgers` |
|---|---|---|---|
| Clean base | PASS | PASS | PASS |
| Commit rewrite of the **unselected filename** among two selector files both numbered 403 | **false PASS** | **false PASS** | **false PASS** |
| Commit deletion of the sole synthetic selector file numbered 497 | **false PASS** | **false PASS** | **false PASS** |
| Commit changes to the checker itself and a reusable workflow file, no code-surface change | **false PASS** | **false PASS** | **false PASS** |
| Commit a changed `src/sentinel.cpp` | FAIL as required | PASS (committed change not dirty) | PASS |
| Change the selected selector file **uncommitted** after source drift control | FAIL from prior source drift | FAIL on dirty selector, as required | PASS |

All **18 helper invocations** in these six states returned the predicted outcomes and the probe's own fail-closed assertions passed. The synthetic 497 filename is an invented **falsifier**, **not** an assertion that the live repository currently contains or lost a file numbered 497. Similarly, the synthetic checker/workflow changes occurred **only in the disposable repository**; no real Directional history mutation was inferred. The exact reproducible probe and JSON receipt are retained as the R61 evidence attachment alongside this note.

## Corrective ownership and stop conditions

1. Future authorized checker Code + Build work should **identify selector files by normalized full relative path**, never numeric suffix alone; the numeric count remains metadata. Enumerate every file including branch variants. Require an independently sourced expected set (the retained manifest and frozen selector chain), verify each expected file's exact hash, and reject missing, duplicate-path, rewritten, or unauthorized added files. A scan of presently existing files cannot itself prove missing-file absence.
2. Verify **committed path drift** from an exact reviewed source/entry SHA to HEAD, not only dirty worktree status. Include the audit checker, the applicable executor/harness scripts, workflow definitions, and the exact frozen TB47 case-manifest path as separately classified authority surfaces. Do not indiscriminately freeze unrelated documentation or bypass legitimate future versioned promotions.
3. Add independent mutation-and-restore controls for: (a) each shadowed selector filename, (b) deletion of the last selector for one count, (c) selected-selector edit, (d) checker self-change, (e) workflow change, (f) legitimate unchanged review-only documentation, and (g) a real `src` edit. The real accepted selector hashes and immutable package/source authority must remain unchanged by the control experiment.
4. Review R60's proposed full-DAG ledger patch separately; its synthetic replay does **not** prove historical full-DAG scan performance or merge semantics on the authentic branch. The verified snapshot excludes `.git`, so `review_check.py boundary`/`ledgers` cannot provide a valid authentic-history PASS in this session. Do not claim that these synthetic findings establish any actual Directional selector tampering, committed source drift, or product regression.

**Disposition:** A further *review-instrument correctness obligation*, not a new stable product regression and not a G1/G2/G3 witness. Accepted CP2 remains **491/491**; TB47 remains the **unpromoted** 500 PASS / 4 expected RED, with selector497 unpromoted and stable regression accounting **66 events / 17 categories / 49 recurrences, debt 1**. G1 source-producible positive/negative, G2 paired signed covariance and A5 owner, G3 A4-produced odd reciprocal face gauge, periodic A5 masked tail, separate E2, actual complete Git-history audit, consolidation, and a fully frozen next manifest remain outstanding. No CB48, TB48, E2-PATCH or other successor authorized by this R61 finding. The canonical Review remains open.

## Review closeout (interim; formal turn not closed)

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | n/a as acceptance claim; only frozen TB47 v2 TSV and tool exact bytes re-hashed, source snapshot full manifest verified; accepted prefix remains historically accepted, no promotion |
| Decisive claims independently re-derived | Real selector collisions, checker source review, disposable Git executions and typed controls above |
| Non-vacuity checked | Source-code edit fails `authority`, dirty selected selector fails `boundary`, authentic helper bytes used in synthetic probe |
| Prior obligations discharged/carried | R51/R38/R50/R60 and G1/G2/G3/E2/periodic remain open; R61 adds a distinct checker deficiency |
| Stable accounting | 66/17/49, debt 1; CP2 491/491 accepted, TB47 500/4 candidate |
| New candidates/obligations recorded | R61 checker-file/selector-file audit obligation in this interim review note, no stable product regression assigned |
| ORIENTATION currency line | unchanged: incomplete same canonical turn, no acceptance change |
| ORIENTATION §3 / §4 / §7 / §8 | unchanged: no product/witness acceptance and no formal turn closure |
| CHANGELOG | unchanged: interim Review not closed |
| ROADMAP | n/a: no checkpoint status change |
| Selector manifest | untouched by design |
| LESSONS | Existing source-authority and non-vacuity obligations reused; no new lesson committed |
| Consolidation under CLEAN_UP_POLICY | pending on this still-incomplete canonical Review; do not delete R52–R60 sources |
| Successor frozen | none; canonical turn remains ongoing and successor unknown |
| Turn boundary held | review-only Python/Git synthetic scratch; no Directional C++ execution or production/test edits |
| `review_check.py boundary` | authentic run impossible on history-free snapshot; no fabricated PASS; synthetic controlled results above |
| `STATUS` lifecycle maintained | initial resume beacon updated; final same-turn incomplete beacon is required as last repository action |
| Pushed to origin, branch in sync | to be verified from GitHub write/branch authority; no local Git push claimed |
