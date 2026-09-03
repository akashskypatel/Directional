# M3-CP4c-3-TB19 Artifact-Only Test + Benchmark Plan

**Turn:** `M3-CP4c-3-TB19-EXEC`
**Type:** artifact-only Test + Benchmark
**Status:** **FROZEN / EXACT NEXT**
**Frozen by:** `M3-CP4c-3-CB21`
**Date:** 2026-09-03

## 1. Purpose

TB19 is the first runtime execution of the CB21 product correction. It must determine whether the corrected
fragment-owner validation clears the measured low-side shared-owner stop without disturbing the accepted boundary
or the carried CP4c-3 surfaces.

This is an immutable-package turn. It may execute packaged Directional test binaries and collect evidence; it may
not configure, compile, relink, repair, regenerate, or mutate product source, tests, fixtures, selectors, package
bytes, or runtime inputs.

## 2. Frozen package and selector authority

TB19 consumes exactly:

- semantic source: **`b00efbd53d3da8caa2bcac0d66594e06e44d2cb2`**;
- CB21 compile run/job: **`33794307778 / 100778238374`**;
- immutable compile result artifact: **`9908695433`**;
- artifact/downloaded ZIP SHA-256:
  **`efb65c06cc6d73d233ee271a31fc82705d2575da313fb7f18b389a5196441fc5`**;
- packaged source archive SHA-256:
  **`8b774500559e5cc9cd7afece39a68add2065a9812a0d15a40f39cf7f9aafd8e7`**;
- compile log artifact: **`9908695835`**, SHA-256
  **`f334db6b4bf254c3e2eb84f0a65cb0f6a21fc56285b3677a037cb20881b8ad3f`**;
- selector 384: **384 identities**, SHA-256
  **`c9425b9309415d43d49e5791cc43fd5e5e3bf3ae50d02c329c65d3e632a05564`**;
- selector 383 prefix: SHA-256
  **`a7fe57cc47c5035414a82f02f044a911f9c430f90d11f1bd3ef1bca76f3a4b2c`**;
- accepted prefix: ordinals **1–365**, current accepted authority **365/365**.

Selector 384's first 383 lines are byte-identical to selector 383. Its sole append is
`GlobalTopologyPlan.FragmentOwnerDeficitPublishesCorrectionEvidenceThroughProductionPath`.

The immutable runtime comparison baseline remains TB18: source
`57635e87306a416daabb8321e1f36fa9c788d208`, run/job `33785382790 / 100748821924`, exact ledger
`a99c31d84200cb97e78bb399fa32c76bea1f3767092f29fc339c4cc9130604ed`, **375 PASS / 8 RED**, red ordinals
366/367/368/369/370/371/372/374.

## 3. Mandatory preflight

Before executing any Directional identity, TB19 must fail closed unless all of the following hold:

1. Download artifact `9908695433` and verify its complete ZIP SHA-256 exactly.
2. Verify every entry in the artifact's `SHA256SUMS`; the CB21 package contains **28** manifest entries.
3. Verify `metadata/source-commit.txt` is exactly
   `b00efbd53d3da8caa2bcac0d66594e06e44d2cb2`.
4. Verify `metadata/build-exit-code.txt == 0`, `metadata/preflight-exit-code.txt == 0`, and every packaged
   source-status file is empty.
5. Verify `metadata/command-boundary.txt` records `runtimeExecution=false`, `turnBoundary=Code+Build-only`, and
   `exactArithmeticBackend=GMP`.
6. Verify GMP/GMPXX authoritative link evidence remains present in `metadata/gmp-evidence.txt`.
7. Recompute selector 384's SHA-256 and line count, recompute the first-383 prefix hash, and verify accepted
   ordinals 1–365 remain the frozen accepted prefix.
8. Record a pre-execution byte-and-mode census of the entire extracted immutable package. The identical census must
   be reproduced after execution.
9. Confirm the runner will use only binaries packaged inside artifact `9908695433`; no source-tree or runner-built
   Directional binary may be executed.

A preflight failure is an **orchestration failure**, not a semantic RED. Correct the orchestration without changing
package/selector bytes and re-enter TB19 under the same immutable authority.

## 4. Execution protocol

Execute the **full selector 384 in selector order**, one identity per fresh process, using the same artifact-only
identity-to-packaged-binary routing established by the preceding CP4c TB turns.

For every ordinal:

- start a fresh process that executes exactly that identity;
- preserve exact process exit status and the complete identity log;
- record identity name, ordinal, executable, start/finish status, and log SHA-256 in the result ledger;
- retain the production terminal failure code/detail/locus and typed CP4c evidence emitted by the identity when
  available;
- do not invoke generated test discovery or any unlisted test identity;
- do not change environment mutation flags to expose optional diagnostics that the frozen gate does not use;
- do not rerun a completed identity as part of a semantic retry. If an orchestration interruption occurs, preserve
  and hash completed rows/logs, prove their immutability, and resume only the unexecuted suffix.

The turn must state explicitly that configure, compile, link, package, source mutation, test mutation, fixture
mutation, selector mutation, repair, and benchmark mutation are all false. Packaged `directional_benchmarks` is
part of the immutable package but no benchmark workload is authorized by this plan unless an identity in selector
384 itself routes there under the existing frozen runner.

## 5. Binding TB19 discriminators

The following are the CB21 `BU9` discriminators. They are **observations to measure**, not outcomes to force.

### D1 — accepted boundary

Ordinals **1–365 must remain 365/365 PASS**. Any accepted-prefix red is a regression and prevents acceptance
advance regardless of later results.

### D2 — first fragment-owner stop must move

Ordinal **366** must no longer terminate at
`TraceCutFaceFragmentCountMismatch`. TB18 measured that stop at source face `(0,1,102)` with owner count **1**,
`k=1`, expected **2**. If ordinal 366 remains at that mismatch, CB21's semantic correction did not reach the
production path and BU1 is falsified.

TB19 does **not** require ordinal 366 to become globally green. A later typed failure is valid new frontier
evidence.

### D3 — co-reaching identities

Ordinals **367, 371, and 372**, which co-reached the same fragment-owner validation surface under TB18, must also
move past `TraceCutFaceFragmentCountMismatch`. Record each new terminal site independently; do not collapse their
later outcomes into ordinal 366's result.

### D4 — retained deficit evidence

For the mechanical witness face `(0,1,102)`, retain and report:

- `ownerCount = 1`;
- `expectedFragmentCount = 2`;
- `ownerDeficit = 1`;
- `localFragmentCount = 2` when locally evaluated;
- `traceChordCount = 1`;
- the shared-owner chord `trace=1 / arc=15 / segment=4`;
- forward and reverse orbit ids equal for that chord;
- `chordsCrossInside=false` for the one-chord witness.

The deficit is evidence only. TB19 must not reinterpret a low-side deficit as a fatal mismatch.

### D5 — bridge/orbit census

Retain the CB21 census through the production path and report at least:

- arc 15's forward/reverse orbit ids and `sharesOrbit` state;
- trace 1's `terminalSlit` state;
- total, exterior, and non-exterior orbit counts;
- face/arc/trace evidence counts and every truncation flag.

The census must be reported as observed. Do not infer unretained rows beyond an explicit truncation boundary.

### D6 — carried surfaces

Compare ordinals **368, 369, 370, and 374** against TB18. CB21 authorized no semantic change for prescribed-sphere
368, saturation 369, zero-node/zero-arc closed-surface 370, or folded-cone 374. Record whether each terminal
failure code/detail/locus is unchanged. Any change is unexpected cross-surface movement and must be categorized in
the regression tracker before the turn closes.

## 6. New selector-384 contract

Ordinal **384**,
`GlobalTopologyPlan.FragmentOwnerDeficitPublishesCorrectionEvidenceThroughProductionPath`, is the sole CB21
addition. Execute it exactly once in its fresh process and record its result. It is expected to validate the
production-path evidence contract, including the one-chord/one-shared-owner pass-through and the byte-identical
high-side failure-envelope oracle, but compile success is not runtime credit.

## 7. Required postflight and report

After ordinal 384 (or after a valid resumed suffix completes):

1. recompute the full package byte-and-mode census and require it to equal the preflight census exactly;
2. produce an exact 384-row ledger whose PASS + RED + orchestration classifications arithmetically close;
3. record the full red ordinal set and first red;
4. separately state accepted-prefix result for 1–365;
5. record D1–D6 and ordinal-384 outcomes without substituting expectation for measurement;
6. update `Regression_Root_Cause_Tracker.md` for **every** observed regression or changed candidate. If evidence
   does not justify a stable event/category/recurrence change, state why totals remain unchanged;
7. publish the authoritative artifact/run/job/ledger/census hashes in the TB19 report and durable handoff.

A valid RED is runtime evidence and routes through the standing `CB → TB → REVIEW + PLAN` workflow. Do not patch,
retry semantics, or begin a successor CB inside TB19. A fully green gate closes the checkpoint under the standing
workflow. In either case, TB19 itself closes only after its immutable evidence, tracker dispositions, and exact
next-turn handoff are durable.

## 8. Prohibited actions

TB19 may not:

- rebuild or relink any target;
- edit product, tests, fixtures, selectors, plans, or package bytes before/during execution;
- enable `DIRECTIONAL_CP4AB_FRAGMENT_DIAGNOSTICS` or any other non-frozen diagnostic environment solely to seek
  additional text evidence;
- rerun completed identities to improve a semantic result;
- weaken/skip ordinals 1–365 or omit any selector-384 identity;
- treat an orchestration failure as a semantic RED;
- advance acceptance based on compile evidence or expected behavior.

## 9. Exact next action

Execute **`M3-CP4c-3-TB19-EXEC`** under this plan and stop at its normal Test + Benchmark turn boundary.
