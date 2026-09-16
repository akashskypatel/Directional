# M4-CP-SCALE-TB9-EXEC — Artifact-Only S4 Prerequisite Test + Benchmark Plan

**Execution boundary:** artifact-only Test + Benchmark. This plan authorizes runtime execution of the immutable CB10 package only. It forbids configure, compile, relink, generated-code regeneration, package/source/test/fixture mutation, permission repair, and selector mutation.

## 1. Immutable candidate authority

Consume exactly:

- result artifact ID `10455353524`;
- artifact name `m4-cp-scale-cb10-package-result-35116725106`;
- provider/download SHA-256 `b891318511ef6db2f6317abac99a4b7e1511fe6d4ebc58bdd048cdc49a757de9`;
- semantic source `bebb14e32a0ac53dd420acf46bfa34410cf759a1`;
- packaged source archive SHA-256 `884ff6703f290df8b3479e35945cb3dc29b0732e3810eb66528759721d8366ae`;
- selector425 SHA-256 `e0e0f394faae536ac257ec5409653a34755a8afe0ca437562eb44c9895790e0b`;
- first-424 prefix SHA-256 `f202a1720c0a5288471d04836402b8432eb6f4f788da68a12e70dacb875466ca`;
- owner census **30 authority-kernel / 279 producer / 75 completion / 41 validation**.

The accepted runtime predecessor remains TB7 package `10425344367` until TB9 Review explicitly promotes a successor.

## 2. Preflight — fail closed before runtime

1. Download artifact `10455353524` once and verify its outer SHA-256 exactly.
2. Extract with an archive tool that preserves the archived executable mode bits (`unzip`/`bsdtar`/equivalent). **Do not use Python `zipfile.extractall` for executable payloads and do not `chmod`, copy-repair, relink, or otherwise repair the immutable package.** Missing executable mode is orchestration failure.
3. Verify every entry in root `SHA256SUMS` before execution.
4. Verify `metadata/source-commit.txt` is exactly `bebb14e32a0ac53dd420acf46bfa34410cf759a1`.
5. Verify `metadata/command-boundary.txt` records `runtimeExecution=false`, `turnBoundary=Code+Build-only`, and `exactArithmeticBackend=GMP`.
6. Verify `metadata/gmp-evidence.txt` contains authoritative generated-link evidence for both GMPXX and GMP.
7. Verify all source-status receipts are empty and preflight/build exit codes are zero.
8. Verify the six packaged executable targets exist with their archived executable bits intact. Do not execute help/list/version/discovery commands.
9. Extract the packaged source archive into a separate execution/source view without modifying package bytes. Verify the source archive digest and use only its committed fixtures/control files.
10. Re-hash selector425 from packaged source: exactly 425 LF-only nonempty rows, 425 unique identities, exact selector425 digest above, exact first-424 prefix digest above, and no selector426 substitution.
11. Rebuild the selector owner map **statically from packaged source/CMake ownership**, without runtime discovery. Require census `30 / 279 / 75 / 41` for authority-kernel / producer / completion / validation and exactly one owner binary for every selector row.
12. Verify the focused identity `M4CPScaleS4Prereq.IndependentTopologyOracleIsReachableAndDecisionNeutral` has exactly one source definition and maps to `directional_surface_cell_producer_tests`.
13. Record package, packaged-source, selector, executable-mode, fixture, and execution-view pre-runtime byte/mode censuses for immutable postflight comparison.

Any mismatch above is orchestration/authority failure. Execute **zero** Directional runtime processes in that case.

## 3. Focused S4 prerequisite — exactly one fresh process

Run exactly one fresh process:

```text
directional_surface_cell_producer_tests --gtest_filter=M4CPScaleS4Prereq.IndependentTopologyOracleIsReachableAndDecisionNeutral
```

No aggregate process or imported prior result may substitute for this run. Require:

- exactly 1 selected, 1 executed, 1 passed, 0 skipped, exit code 0;
- exactly one terminal `m4CpScaleS4Prereq` receipt;
- `coveredClass=BettiFaceCountMismatch`;
- `reachableNegative=true`;
- all negative raw/invariant/certificate availability flags `true`;
- negative receipt values `negativeBetti=4`, `negativeRequiredFaces=3`, `negativeObservedFaces=4`, `negativeReject=true`;
- all positive raw/invariant/certificate availability flags `true`;
- positive values `positiveBetti=5`, `positiveRequiredFaces=4`, `positiveObservedFaces=4`, `positiveReject=false`;
- all adversarial raw/invariant/certificate availability flags `true`;
- if `adversarialReject=true`, require `adversarialFinalCellular=false`; a non-reject is not interpreted as final success;
- `enumerationInvariant=true`;
- `decisionNeutral=true`.

A passing process also proves the compiled source assertions for the corrected raw torus counts and topology: empty-cut `48/48/F4/c4/s1/chi0`, four annular complement components with two boundary walks and Euler zero, and accepted-cut `72/76/F4/c1/s1/chi0` with four disc components.

### Focus fail-fast rule

If the focused process is RED, SKIP, crashes, has a selection mismatch, lacks/duplicates the structured receipt, violates any receipt invariant, or otherwise fails mechanically/semantically:

- stop runtime immediately;
- mark selector425 **0/425 executed / 425 UNEXECUTED** for TB9;
- preserve raw focused stdout/stderr and process receipt;
- continue only to immutable postflight and durable regression/root-cause recording;
- do not retry the same immutable candidate in TB9-EXEC.

## 4. Selector425 cumulative gate — only after focused GREEN

Execute selector425 in exact file order as **425 additional fresh processes**, one exact-filter identity per process, using the static owner map from preflight. Each row must:

- select exactly one test;
- execute exactly one test;
- pass exactly one test;
- skip zero tests;
- exit zero;
- run from immutable package/source/fixture bytes.

Do not replace these 425 processes with a suite-level aggregate invocation. Do not import TB7/TB8 results as fresh credit. Do not partition/retry/stitch the gate to evade elapsed runtime. No repository-imposed timeout may terminate this complete acceptance gate.

Acceptance requires **425/425 PASS** with zero RED, SKIP, crash, timeout, selection mismatch, duplicate owner, missing owner, or unexecuted row. Record one machine-readable ledger row per selector identity containing ordinal, identity, owner binary, command/filter, process exit, selected/executed/passed/skipped counts, and raw-output evidence path.

The focused process is prerequisite evidence and is **not** counted as one of the 425 cumulative selector processes; the selector row containing that identity must execute freshly again when its ordinal is reached.

## 5. Immutable postflight

Whether focus/selector is GREEN or RED, postflight is mandatory:

1. re-hash the downloaded package and verify root `SHA256SUMS` again;
2. re-hash packaged source archive and selector425;
3. reproduce the package/source/execution-view byte+mode censuses and require exact pre/post identity;
4. verify source fixtures/control files are byte-identical to preflight;
5. record that no configure, compile, relink, code generation, `chmod`, package repair, selector mutation, benchmark run, or discovery/list/help/version command occurred.

A postflight mismatch invalidates the execution as immutable evidence regardless of test outcomes.

## 6. TB9-EXEC evidence bundle

Retain at minimum:

- artifact/package verification receipts and hashes;
- pre/post package/source/execution-view censuses including mode bits;
- selector425/prefix hashes and static owner map/census;
- focused command, raw stdout/stderr, parsed counts, parsed S4 receipt, and process resource/exit receipt;
- if focus GREEN, all 425 selector commands, raw stdout/stderr, per-row parsed ledger, aggregate counts, and owner census;
- explicit fail-fast/unexecuted ledger when focus blocks selector execution;
- immutable postflight report;
- one machine-readable summary identifying artifact/source and all runtime process counts.

Do not rebuild or patch the candidate to obtain missing evidence.

## 7. Regression documentation and handoff

Every observed RED/orchestration failure must be categorized in `.agents/Directional/Regression_Root_Cause_Tracker.md` before TB9-EXEC closes. If evidence does not justify a stable ID/count change, record/update a candidate/non-stable entry and explicitly leave stable totals unchanged.

`M4-CP-SCALE-TB9-EXEC` makes **no promotion or observation-discharge decision**. Its exact successor is mandatory independent `M4-CP-SCALE-TB9-REV`, which must reopen the immutable package and TB9 evidence, re-derive the corrected negative/positive/adversarial semantics, verify enumeration/decision neutrality and cumulative selector evidence, and decide whether `M4-CP-SCALE-DEFN-OBS-03` can be discharged or whether another bounded correction is required.
