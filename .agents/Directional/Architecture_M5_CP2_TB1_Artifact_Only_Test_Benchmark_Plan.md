# M5-CP2-TB1 Artifact-Only Test + Benchmark Plan

**Turn:** `M5-CP2-TB1-EXEC`
**Turn type:** immutable artifact-only Test + Benchmark execution
**Candidate package:** artifact `10601978228` / exact source `0798547dedd8be05f9cd7a096b07e6bd94755316`
**Entering accepted runtime authority:** package `10600353027` / source `8a86710dd33d7b6cb9a077aef738577e4075b5f7` / selector430 **430/430**
**Build/configure/relink/source mutation:** forbidden
**Benchmark execution:** exactly `0`

## 1. Goal

Execute the frozen CP2 mechanism evidence from the immutable CB1 package: one positive relation-container invariance row, the five exact typed relation-failure classes, the accepted tampered-transform regression row, and the complete unchanged selector430. This turn measures runtime behavior only. Candidate promotion and CP2 semantic acceptance remain Review-owned.

## 2. Immutable preflight

Before executing any packaged binary:

1. Download artifact `10601978228` exactly once and verify provider/download ZIP SHA-256 `ad2e502db60d94c275769616edf5555d12abd87499c6cf3987cdafbd458d2f0b`.
2. Extract with ordinary `unzip`/`tar` so archived executable mode bits are preserved. **Do not use Python `zipfile.extractall` for executable payloads and do not repair modes with `chmod`.** A missing executable bit is orchestration failure.
3. Verify the root recursive self-excluding `SHA256SUMS` manifest **28/28** before execution.
4. Verify exact packaged source `0798547dedd8be05f9cd7a096b07e6bd94755316`, clean source-status receipts, build/preflight exits `0 / 0`, `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `exactArithmeticBackend=GMP`, and explicit GMPXX+GMP linkage.
5. Verify selector430 bytes from the packaged source against SHA-256 `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`, with first427 prefix SHA-256 `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`.
6. Record a byte+mode census of the immutable package/source/execution view before runtime. Do not configure, compile, relink, regenerate discovery/code, edit tests/fixtures/selectors, or mutate the package.

Any preflight mismatch is orchestration failure with **zero semantic credit**; stop without repair.

## 3. Frozen focused gate

Execute each identity below in a **fresh process** with an exact GoogleTest filter. Every command must select exactly one test and skip zero.

| Ordinal | Role | Exact identity |
|---:|---|---|
| 1 | positive container-order invariant | `SurfaceCellTransitionQuotient.PeriodicRelationOwnersSurviveContainerReorderingBeforeMaterialization` |
| 2 | missing | `SurfacePhaseFrontProductFactoryAuthority.UnknownPeriodicRelationOwnerRejectsAtCheckedFactory` |
| 3 | duplicate | `SurfacePhaseFrontProductFactoryAuthority.DuplicatePeriodicRelationIdentityRejectsAtCheckedFactory` |
| 4 | conflicting | `SurfacePhaseFrontProductFactoryAuthority.ConflictingPeriodicRelationValueRejectsAtCheckedFactory` |
| 5 | nonreciprocal | `SurfacePhaseFrontProductFactoryAuthority.NonReciprocalPeriodicRelationRejectsAtCheckedFactory` |
| 6 | representation-renumbered | `SurfacePhaseFrontProductFactoryAuthority.RepresentationRenumberedPeriodicRelationRejectsAtCheckedFactory` |
| 7 | accepted tampered-transform preservation | `SurfaceCellTransitionQuotient.TamperedFullPeriodicTransformIsRejected` |

The focused gate is **7/7 required green**. A missing identity, zero/multiple selection, skip, crash, timeout, or nonzero test result is not a pass.

## 4. Accepted selector gate

Only after the focused gate is mechanically valid, execute all 430 identities from `Architecture_M4_CP4_CB8_Required_Green_Selector_430.txt`, one fresh exact-filter process per row, preserving file order. Require:

- exactly one selected test per identity;
- zero skips per identity;
- **430/430 PASS**;
- no selector edits, substitutions, deduplication, or row reordering.

Selector430 remains the accepted cumulative gate; this execution does not publish CP2 tests into a new selector.

## 5. Runtime boundary and stop rules

- Benchmark commands executed: **0**.
- No source-grid recovery or product-specific extra runtime outside the frozen filters.
- No configure, compile, relink, generated discovery/list/help/version command, source/test/fixture/selector mutation, or package repair.
- Do not retry a semantic RED in the same EXEC turn.
- Do not reinterpret a generic crash/timeout/selection error as a semantic result.
- If any focused row is RED, record exact evidence and stop before granting selector or CP2 acceptance credit; the mandatory next turn remains Review.
- If focus is green and selector contains RED, complete the selector ledger and route the exact RED evidence to Review; do not patch in TB.

## 6. Immutable postflight

After runtime, re-verify:

- package root manifest **28/28**;
- selector430 and first427 hashes;
- exact packaged source archive hash/bytes;
- pre/post byte+mode census equality for package, source, and execution view;
- zero build/configure/relink/mutation/benchmark counters.

Package extraction must remain byte- and mode-identical; no repair is permitted.

## 7. Evidence and successor

Retain a machine-readable ledger for all 7 focused rows and all 430 selector rows, exact command/filter/selection/pass/skip/exit data, immutable pre/post hashes/censuses, package source identity, and runtime-boundary counters.

The exact successor after any orchestration-valid execution is runtime-free **`M5-CP2-TB1-REV`**. Review must reopen the immutable result/log evidence and candidate source, adjudicate the five-class matrix and the selector-row boundary mapping recorded by CB1, decide candidate promotion/CP2 acceptance, and freeze any required selector-publication correction. No Code + Build continuation is authorized before Review.
