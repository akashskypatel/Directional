# M3 CP4c-3 TB9 — Artifact-Only Test + Benchmark Plan

Date: 2026-09-02 UTC
Turn: `M3-CP4c-3-TB9`
Status: **FROZEN SUCCESSOR PLAN / NOT EXECUTED**

## Validation identity

- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`.
- Evidence source: **`803300698289e0d0f629eaa878add1aebc7193c1`**.
- Final compile run/job: **`33573956609 / 100073749252`**.
- Raw compile artifact `9825961944`, Actions SHA-256
  `d3e8a50d880e4f8f5179718b7c91288a50b6755e8ec0d6d94e29c3da1ead3b99`.
- Immutable mode-preserving package **79**:
  package run/job **`33574167362 / 100074416093`**,
  artifact **`9826005253`**, Actions SHA-256
  **`1f9c6e1d098a08eb375d415f2724185043de1c1d5d08cdce46cc716d57e3fa8a`**.
- Inner `package79.tar.gz` SHA-256:
  **`dfc197b50ea5b9b88468aa00665470af5aa0e2959de9c380fcd6aebdb978ec99`**.
- Packaged source archive SHA-256:
  **`61107e4fc90368793ebe97c3581cea6cb301effc74c6f39cc3259316066aa0f6`**.
- Frozen selector 374 SHA-256:
  `d496ce96b3776269cda8086a0a2173ce9a1f9967d81b2a80866266155c503c4f`.
- Frozen selector 375 SHA-256:
  `aa7b22bb265f321fad6f85128e572e0251dc5f60d68856ca7ec4323006a8f3a0`.
- Execution selector **376** SHA-256:
  **`6ab2d9fad0327e00bb2f782741afffe8a0ae08c08df8adbdf9accc6234bfa5e8`**;
  selector 375 must be its unchanged 375-line byte prefix.
- Diagnostic identity 376:
  `ResolvedBranchCorrection.NetworkTerminalOwnershipConditionsSurviveProductionFailureProjection`.
- Benchmark: **none**; correctness/diagnostic validation only.

Package 78 and all earlier packages are superseded as TB9 inputs.

## Objective

Consume CB11's immutable package without rebuilding it. Re-prove the accepted 365-prefix, reproduce or clear ordinal
366, and use CB11's typed condition plus lossless production projection to determine which of the two statically
proved `InvalidNetworkTerminalOwnership` sites actually fires. Preserve every later pre-classified disposition and
execute identity 376 with zero gate credit. **TB9 diagnoses; it does not correct product behavior.**

## Immutable preflight — before any Directional runtime

1. Download artifact `9826005253` directly and verify its Actions digest and exact inner tar digest above.
2. Extract `package79.tar.gz` with normal `tar` extraction that preserves archived executable mode bits. Do not use
   Python `zipfile.extractall` for executable payloads and do not `chmod`, rebuild, regenerate, relink, or repair the
   package.
3. Verify every internal `SHA256SUMS` entry, exact source commit/archive digest, clean source-status records,
   `runtimeExecution=false`, `packageRepair=false`, `exactArithmeticBackend=GMP`, preflight/build exit code `0`, and
   link evidence containing both GMPXX and GMP.
4. Require exactly 27 package-relative fixture files and exactly six packaged `directional_*` executables with their
   archived executable mode intact.
5. Recompute selectors 374, 375, and 376 from the immutable packaged source. Require exact hashes above, cardinalities
   374/375/376, uniqueness, `374 == head(375,374)`, and `375 == head(376,375)`.
6. Map every selector-376 identity to exactly one packaged executable before runtime. A zero-selected or
   duplicate-selected identity is orchestration failure, never semantic evidence.
7. Record a package-tree byte/mode census for postflight comparison.
8. No configure, compile, relink, generated discovery, source/test/fixture/selector mutation, package repair, or
   benchmark is permitted.

Any mismatch is orchestration failure. Stop before runtime and do not count a semantic attempt.

## Ordered execution — selector 376 from ordinal 1

Execute selector **376 from ordinal 1**, one exact identity per fresh producer process. The accepted-prefix gate still
stops credit at the first semantic red. Later authorized identities execute only report-only with zero gate credit;
that remainder must never alter `first_red_ordinal`, pass count, or acceptance.

### BB9 mandatory discriminators

TB9 must record all five before it closes:

1. **Accepted prefix:** ordinals **1–365 remain 365/365 PASS**. Any red in this prefix invalidates inherited accepted
   authority and is new gating evidence.
2. **Ordinal 366 locus:** if ordinal 366 remains red, it must remain
   `InvalidNetworkTerminalOwnership` with the same `sourceEdge=36-38`, `sourceFace=36,38,39`, and `branch=2` locus.
   A different first locus is new semantic evidence and must be reported exactly.
3. **Exact site discriminator:** the rendered production locus must name **exactly one** of the two statically proved
   owners: the singularity-port ownership site or the finalize/contact fall-through site. Missing/ambiguous/multiple
   site identity means CB11's diagnostic correction is falsified; do not infer the owner.
4. **Trace provenance:** the same rendered line must carry `traceSeedVertex`, `traceSeedSingularity`, and bounded
   `traceHistory` sufficient to name the source port/trace path. If history truncates, the explicit count/truncation
   state must also be present.
5. **Published-face honesty:** `publishedFaceCount` must represent an actual populated production observation. If the
   line reports `publishedFaceCount=0`, zero is accepted only as the real observed published-face count after CB11;
   it must no longer be an unassigned default.

**No product correction is authorized from these observations during TB9.** The purpose is to name the site for the
independent TB9 review.

## Gate and report-only accounting

- Ordinals **1–365** carry inherited accepted gate credit and must remain green.
- Ordinal **366** is the current gating frontier. Stop gate credit at its first red.
- After a first red, execute every remaining ordinal through **375** exactly once, one fresh process each, as the
  already-authorized zero-credit remainder. Preserve the existing sphere, saturation, ordinal-370, mechanical, and
  folded-cone dispositions unless the actual emitted evidence changes.
- Ordinal **376** is diagnostic, **zero gate credit**, and must execute exactly once even when the gate already red.
  It must prove the typed terminal-ownership condition and trace-scoped diagnostic group survive the production
  failure projection/rendering path.
- If ordinal 366 unexpectedly passes, continue sequentially through selector 376 and record the next organic first
  red, but do not close CP4c-3 or promote a later result without the mandatory independent review.

Do not impose an elapsed-time watchdog on the complete selector execution. Do not partition/retry/stitch partial
successful runs to manufacture a complete result.

## Regression/accounting review

Before TB9 closes, categorize every observed regression/candidate in
`Regression_Root_Cause_Tracker.md` and record root-cause analysis required by project policy. If evidence does not
justify a new stable identity/count change, retain candidate/non-stable status and explicitly state why stable totals
remain unchanged.

The known TB8 terminal-ownership red is not automatically a new stable event merely because its newly visible site
identity becomes known. Any accounting promotion requires the tracker criteria and independent review.

## Immutable postflight

After all authorized runtime, re-run the internal manifest; re-check source archive, selector hashes, binary hashes
and executable modes; compare the package-tree byte/mode census; and prove configure/compile/relink/repair/generated
discovery/product/test/fixture/selector mutation and benchmark flags remain false.

A postflight mismatch invalidates semantic authority and is orchestration evidence, not a product verdict.

## Stop/rerun rules

- A red in ordinals 1–365 is a new gating failure; preserve it and stop gate credit.
- Ordinal 366 repeating the old coarse locus **without exactly one typed site discriminator and required trace
  provenance** is CB11 diagnostic failure. Do not guess the site and do not repair product code in TB9.
- Ordinal 366 naming exactly one site is the intended discriminating result. Complete the authorized zero-credit
  remainder, identity 376, immutable postflight, regression documentation, then route to independent
  `M3-CP4c-3-TB9-REV`.
- An orchestration-only failure may be retried only after the exact control defect is diagnosed, with package 79
  unchanged. Never rerun an unchanged deterministic semantic failure merely to see whether it passes.

## Completion criteria

- **Valid semantic result:** ordered selector-376 execution from ordinal 1, truthful gate/remainder accounting,
  identity 376 recorded, all BB9 discriminators resolved as far as the runtime permits, immutable postflight PASS,
  and regression tracker updated → route to **independent `M3-CP4c-3-TB9-REV`**.
- **Blocked:** immutable/orchestration preflight or postflight invalid → repair only the control plane and retain
  package 79 unchanged.

TB9 itself cannot authorize a product correction or CP4c-3 acceptance.
