# M4-CP-SCALE-TB3-EXEC Artifact-Only Test Plan

**Status:** FROZEN by `M4-CP-SCALE-CB3`; runtime not yet executed.
**Execution role:** TB-EXEC only. Review/adjudication is a separate mandatory `M4-CP-SCALE-TB3-REV` turn.
**Candidate artifact:** `10375799491` (`m4-cp-scale-cb3-package-result-34915185539`)
**Candidate semantic source:** `ba6e204d9daef39bfc6c168b659fc1b94f2b5b9b`
**Artifact ZIP SHA-256:** `60e84d9b630a8a59574b330e83f80120000973f91a011272a743ce6bdbac5379`
**Package manifest SHA-256:** `2f52b377f0a26bd1d474ed64e41a2fd5096b5ad102c4ff802691dd1969246cfb` (28 entries, self-excluding)
**Packaged source archive SHA-256:** `4ec9c7888621fbb0b51cff7173a8ef678c6351a5f3a88988fc0d1b590aee1e2d`
**Selector authority:** unchanged selector423, 423 LF rows, SHA-256 `4e67e4dc6528a71e8399cd55dce6af4c6143e2502102e421b62a8eb712d89343`; first422 SHA-256 `bbd496f3396bd656d13c728ddaad806276e00b901675255e0b67241beec4f7cc`.

## 1. Purpose

Test only the immutable CB3 candidate. TB3-EXEC must determine whether the corrected S2 test authority actually reaches and passes the certified vertex-star comparator on an atlas-admissible regular folded star, then re-prove the unchanged accepted selector423 in fresh processes if and only if focused S2 passes.

TB3-EXEC is mechanical execution only. It does not promote the package, append S2 to the selector, classify a failure as stable/non-stable, alter accounting, or authorize S3/S4/S5. `M4-CP-SCALE-TB3-REV` owns semantic adjudication.

## 2. Immutable preflight

Before any Directional runtime:

1. Download artifact `10375799491` by exact ID and require ZIP SHA-256 `60e84d9b...6d6d2d`.
2. Require the root manifest to contain exactly 28 entries, exclude itself, hash to `2f52b377...246cfb`, and verify 28/28.
3. Require `metadata/source-commit.txt == ba6e204d...b9b`, build/preflight exit codes `0`, every source-status receipt empty, and command-boundary tokens `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `exactArithmeticBackend=GMP`, `manifestExcludesSelf=true`.
4. Require all six packaged runtime executables to be executable and copy them plus the two libraries byte-for-byte into a fresh execution view without `chmod`, rebuild, relink, repair, or mutation.
5. Require the single source archive to hash to `4ec9c788...e1e2d`; extract it and prove selector423 exact row count/hash/prefix hash.
6. Require the S2 test identity to occur in source exactly as `M4CPScaleS2.VertexStarCertifiedFilterMatchesIndependentExactOracle` and to remain absent from selector423.
7. Reconstruct the frozen owner map and require exactly **30 authority-kernel / 277 producer / 75 completion / 41 validation**.
8. Before focused runtime, materialize a **423-row selector process ledger**, one row per selector identity, each initialized to `UNEXECUTED`, and preserve package/source/execution-view byte+mode censuses. This is the structural closure requirement for `M4-CP-SCALE-TB2-REV-OBS-01`.

Any preflight mismatch is a mechanical TB failure. Do not execute runtime and do not substitute another package.

## 3. Focused S2 runtime

Run exactly one fresh process of:

`M4CPScaleS2.VertexStarCertifiedFilterMatchesIndependentExactOracle`

using `directional_surface_cell_producer_tests`, `GTEST_FAIL_IF_NO_TEST_SELECTED=1`, exact `--gtest_filter`, and a 180-second process timeout.

Require exactly one selected test, one OK, zero skipped, process exit 0. Preserve raw stdout/stderr and `/usr/bin/time -v` evidence.

On PASS, parse exactly six `m4CpScaleS2` receipt rows and require the frozen independent-oracle matrix:

| subject | rayX | rayY | exact boundary sign | expected owner | route | on radial ray |
|---|---:|---:|---:|---|---:|---|
| positive-strict-interior | 1 | 2 | +1 | 0-3-1 | Filter | false |
| negative-opposite-order | 2 | 1 | -1 | 0-2-3 | Filter | false |
| near-boundary-certified | 1099511627776 | 1099511627775 | -1 | 0-2-3 | Filter | false |
| exact-boundary-fallback | 1 | 1 | 0 | 0-3-1 | ExactFallback | true |
| tamper-base | 5 | 4 | -1 | 0-2-3 | Filter | false |
| tamper-crossed | 3 | 4 | +1 | 0-3-1 | Filter | false |

The test itself must enforce the CB3 preconditions before comparator use: complete matching/effort/transition diagnostics, center cycle lift zero within frozen tolerance, matching composition `0 mod 4`, no supplied center singularity, successful atlas build with typed failure visibility, and valid arrival face/frame/branch.

If focused S2 is RED, selection-mismatched, skipped, timed out, or crashes, **stop semantic runtime immediately**. The finalizer must still publish the full 423-row `UNEXECUTED` remainder together with immutable package/source/execution-view census and manifest postflight evidence. Do not run selector423 after a focused failure.

## 4. Selector423 runtime on focused PASS only

If focused S2 passes, execute all 423 frozen selector identities in exact file order, each in a fresh process and fresh per-ordinal working directory, against its frozen owner binary. Each process uses an exact `--gtest_filter`, `GTEST_FAIL_IF_NO_TEST_SELECTED=1`, and 180-second timeout.

Update each preinitialized ledger row **exactly once** from `UNEXECUTED` to one of `PASS`, `RED`, `SKIP`, `TIMEOUT`, or `SELECTION_MISMATCH`. Do not append/reorder identities, generated-discover tests, or stop the 423 census on a selector RED.

Mechanical GREEN requires:

- focused S2 PASS with the six-subject receipt matrix;
- selector423 **423/423 PASS**;
- zero RED, SKIP, TIMEOUT, crash, selection mismatch, or `UNEXECUTED` row;
- owner counts still 30/277/75/41.

## 5. Mandatory postflight on success and failure

The EXIT finalizer must always preserve:

- final mechanical status and execution-prohibition flags;
- the complete 423-row selector ledger and result summary, including `UNEXECUTED` count;
- pre/post package, source, and execution-view byte+mode censuses whenever immutable preflight reached census creation;
- postflight verification of the original 28-entry package manifest;
- raw focused/selector logs and resource records that exist;
- an evidence manifest over all published evidence;
- one immutable evidence ZIP and `publication.env` carrying its hash and mechanical exit.

On a focused fail-fast path, a complete 423-row untouched remainder plus immutable census/postflight evidence is mandatory even though selector runtime is not attempted.

## 6. Prohibitions

TB3-EXEC must not configure, compile, link, relink, rebuild, chmod/repair package content, mutate source or fixtures, generate-discover tests, run benchmarks, append/promote selector authority, repair historical ordinal374, or execute S3/S4/S5 work.

No retry with a different candidate is allowed inside TB3-EXEC. Any failed runtime or control contract is carried intact to `M4-CP-SCALE-TB3-REV`.

## 7. Evidence and handoff

Use the frozen payload:

`.agents/Directional/turn-payloads/m4-cp-scale-tb3-exec.sh`

TB3-EXEC records only mechanical facts. Regardless of GREEN or RED, the successor is mandatory `M4-CP-SCALE-TB3-REV` for independent evidence re-opening, semantic classification, package promotion/rejection, stable-accounting decision, and next-plan ownership.
