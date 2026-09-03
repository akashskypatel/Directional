# M3 CP4c-3 TB18 — Artifact-Only Test + Benchmark Plan

Date frozen: 2026-09-03 UTC
Turn: `M3-CP4c-3-TB18`
State: **FROZEN SUCCESSOR / NOT EXECUTED**

## Purpose

Runtime-measure CB20's diagnostic-only change without rebuilding, repairing, mutating, or semantically correcting the package. TB18 exists to determine the **direction** of `TraceCutFaceFragmentCountMismatch` at `(0,1,102)` and retain the exact contributing chord/orbit incidence needed by the following independent review.

## Immutable authority

- semantic/evidence source: **`57635e87306a416daabb8321e1f36fa9c788d208`**;
- authoritative compile run/job: **`33780005014 / 100731152066`**;
- compile result artifact: **`9903305256`**, Actions digest **`sha256:06def1b690bf63391520392da9381088c2bf6529138b6e9f44816bf06996563a`**;
- selector 383: `.agents/Directional/Architecture_M3_CP4c3_Required_Green_Selector_383.txt`;
- selector 383 SHA-256: **`a7fe57cc47c5035414a82f02f044a911f9c430f90d11f1bd3ef1bca76f3a4b2c`**;
- selector 382 prefix SHA-256: **`f30d5d5625682d928a4878e0139e6b04c9e9082f58e8a545c49c8a350d665a1a`**;
- accepted selector-365 prefix SHA-256: **`6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1`**.

## Hard boundary

TB18 may execute only binaries already present in the immutable CB20 compile artifact and may write result/log artifacts. It must not configure, compile, relink, run generated discovery, repair the artifact, edit source/test/fixture/selector/build logic, change executable modes, or execute benchmarks. `directional_benchmarks` is present only because it is part of the standard CB compile target set; **benchmark execution is not authorized** for this diagnostic turn.

Before any runtime process, verify:

1. artifact Actions digest matches the value above;
2. artifact `metadata/source-commit.txt` equals `57635e87306a416daabb8321e1f36fa9c788d208`;
3. `SHA256SUMS` verifies with zero mismatch;
4. `metadata/build-exit-code.txt == 0` and `metadata/preflight-exit-code.txt == 0`;
5. `metadata/command-boundary.txt` contains `runtimeExecution=false` and `exactArithmeticBackend=GMP`;
6. `metadata/gmp-evidence.txt` proves both GMP and GMPXX linkage;
7. selector 383 recomputes to its frozen hash and its first 382 lines hash exactly to selector 382;
8. record a preflight byte+mode census of the entire immutable artifact tree.

Any failure above is an orchestration/evidence stop: **do not repair and do not execute the gate**.

## Execution order

### TB18-1 — selector 383, one identity per fresh process

Execute all **383** selector identities in exact ordinal order, one GoogleTest identity per fresh process, using the already-built test binaries. Do not use generated discovery to obtain identities; the selector is the authority. Record for each ordinal:

- exact identity;
- selected binary;
- process exit code;
- terminal GoogleTest pass/fail line;
- full stdout/stderr path/hash.

Do not infer pass/fail from an exact textual parser alone; process exit code plus terminal GoogleTest status are authoritative.

### TB18-2 — retained failing-face diagnostic evidence

For ordinal 366 and any co-reaching identity, retain the complete production failure line and all `M3_CP4AB_FRAGMENT_DIAG record=fragment_reconciliation` lines for source face `(0,1,102)`. Do not post-process away repeated orbit ids or exterior-drop flags.

### TB18-3 — postflight immutability

Recompute the package byte+mode census and require byte-identical equality with preflight. Record all mutation/build/repair/benchmark flags as false.

No extra runtime probe is authorized unless it is already an identity in selector 383. If required BS9 evidence is absent, report **diagnostic insufficiency** rather than inventing a new probe in TB18.

## Six mandatory BS9 discriminators

TB18 must publish all six explicitly:

1. **Accepted boundary:** ordinals 1–365 remain **365/365 PASS**. Any accepted red is an immediate semantic regression stop.
2. **No semantic frontier movement:** ordinal 366 must still fail `TraceCutFaceFragmentCountMismatch` at source face **`(0,1,102)`**. A different reason or locus falsifies CB20's BS7 no-semantic-change claim.
3. **Mismatch direction visible:** the production failure must contain actual `fragmentOrbitCount`, `tracePieceCount`, and `expectedFragmentCount`. Report the exact numbers and classify `actual < expected`, `actual == expected`, or `actual > expected` without prescribing a fix.
4. **Contributing incidence visible:** publish the bounded chord incidence list, its total/truncation metadata, trace/arc/segment/orientation, both carriers, forward/reverse orbit ids, and both exterior-drop flags exactly as retained.
5. **Failing-path reconciliation visible:** retained logs must contain `fragment_reconciliation` for face `(0,1,102)` before the failure return, including the accumulated three-edge orbit evidence.
6. **Carried surfaces unchanged:** ordinals 367/371/372 must co-reach the same downstream fragment mismatch if they did in TB17; 368 remains the prescribed-sphere `TraceEventPositionInvalid / NoCarrierMatch / SourceEdgeUnavailable` surface; 369 remains saturation; 370 remains its typed empty-network/cellularity surface; 374 remains the folded-cone `atlasBuild=false` fixture surface. Do not re-own or correct them here.

## Gate accounting and acceptance

TB18 is **diagnostic / non-stable**. It cannot close CP4c-3 by itself and does not authorize a product correction. Stable totals remain **44 events / 14 categories / 30 recurrences** and produced-witness debt remains **5** unless the observed immutable evidence independently meets the project's stable-regression accounting rules.

A complete TB18 report must include:

- exact source, compile artifact, run/job and result/log artifact identities/digests;
- exact 383-entry result ledger and its SHA-256;
- accepted 365 result;
- first red and complete red set;
- exact mismatch counts/direction and retained per-chord/edge evidence;
- pre/post byte+mode census hash and equality result;
- explicit build/repair/discovery/source/test/fixture/selector/benchmark mutation flags;
- disposition of each BS9 discriminator;
- tracker update for `M3-CP4c3-TB17-CAND-01` based only on measured evidence.

## Stop and rerun rules

- **Artifact/selector/source mismatch:** stop before runtime; do not repair.
- **Accepted ordinal 1–365 red:** stop semantic promotion, preserve the first red and complete the evidence report only as far as the immutable run safely permits; do not patch in TB18.
- **Ordinal 366 reason/locus moves:** classify CB20 BS7 as falsified and preserve evidence; do not diagnose by source mutation.
- **Required diagnostic field absent/truncated beyond adjudication:** record diagnostic insufficiency. No ad-hoc runtime probe or source edit is authorized.
- **Infrastructure/process interruption before an identity executes:** retry only the unexecuted/infra-failed identity against the same verified bytes; never overwrite the first attempt evidence.
- **Organic GoogleTest red:** do not rerun merely to seek green.

## Exact successor

After a complete TB18 report and durable tracker/handoff closeout, the next turn is **`M3-CP4c-3-TB18-REV` — independent REVIEW + PLAN only**. That review owns the representation decision. No semantic Code + Build is pre-authorized by this plan.
