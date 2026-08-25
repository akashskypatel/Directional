# M3-CP4c-0-TB-R2 — Artifact-Only Test + Benchmark Plan

**Status:** READY / UNBLOCKED
**Consumes:** immutable `M3-CP4c-0-CB2` package only
**Source authority:** `390e65b373063c667e3c3f5e78b74ed9d859093b`
**No source/build/configure/relink/repair/package mutation is authorized.**

## Validation identity

- phase: `M3-CP4c-0-TB-R2`;
- working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`;
- evidence commit: `390e65b373063c667e3c3f5e78b74ed9d859093b`;
- package artifact: **`9586196535`** — `m3-cp4c0-cb2-result-32909482352`;
- GitHub artifact ZIP SHA-256: **`9f74856149909bc1fbcaffe638fd64b4719cddcb8ed8d92972dd52289362003f`**;
- CB2 package internal manifest: **27/27 PASS**;
- compile workflow run/job: `32909482352 / 98000623070`;
- platform: immutable Linux package produced by GitHub Actions.

## Validation objective

Runtime-prove the E0–E10 corrective series without changing the frozen contract:

1. re-prove accepted authority **316/316** unchanged;
2. re-prove the prior **12/12** CP4c-0 identities;
3. prove the **10/10** new `ResolvedBranchCorrection.*` falsifiers;
4. after a green 338 gate, evaluate frozen Q8 from the same immutable package.

A green 338 gate is necessary but not sufficient for checkpoint closure. Q8 remains a separate binding condition.

## Preconditions and integrity checks

Before any runtime process:

- independently verify artifact ZIP SHA-256 equals `9f74856149909bc1fbcaffe638fd64b4719cddcb8ed8d92972dd52289362003f`;
- verify embedded semantic source is exactly `390e65b373063c667e3c3f5e78b74ed9d859093b`;
- verify every package `SHA256SUMS` entry;
- verify `.agents/Directional/Architecture_M3_CP4c0_Required_Green_Selector.txt` contains exactly **338 unique, non-empty identities** in frozen order;
- verify selector SHA-256 `d588cae09067de6914aa1cb917716b11bae01e9f3b45910dbe0faa7d0c7a8116`;
- verify first-316 prefix SHA-256 `601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c`;
- verify first-328 prefix SHA-256 `cf93622ea8807b26037d2fb6305adf721a23724bc519886c455e98c49c5f3600`;
- verify the final ten identities are exactly the ten `ResolvedBranchCorrection.*` identities authored for E8;
- verify package/runtime-input/source inventories before execution and preserve them for exact post-run comparison.

Any integrity mismatch is orchestration failure. Do not execute semantic runtime against a mismatched package or selector.

## Frozen required selector

Required semantic gate: **338/338**.

Composition:

- identities 1–316: accepted predecessor authority;
- identities 317–328: prior CP4c-0 exact-continuation/rejection authority;
- identities 329–338: E8 corrective falsifiers.

Hashes:

- full 338: `d588cae09067de6914aa1cb917716b11bae01e9f3b45910dbe0faa7d0c7a8116`;
- first 316: `601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c`;
- first 328: `cf93622ea8807b26037d2fb6305adf721a23724bc519886c455e98c49c5f3600`.

Do not remove, rename, demote, substitute, reorder, or regenerate an identity during TB.

## Ordered execution plan — TB-EXEC

Execute the 338 identities in selector order, **one identity per fresh process**. For every process preserve:

- selector ordinal and exact identity;
- owning executable;
- exact command / GTest filter;
- selected-count proof (exactly one test);
- process exit status;
- stdout/stderr;
- elapsed time.

A process selecting zero or more than one identity is orchestration failure, never a pass.

Use only packaged executables. No `ctest`, test discovery/listing command, configure, compile, relink, source generation, fixture repair, or package mutation is permitted. Static identity-to-executable routing must be supplied by the runner from the frozen repository/package contract rather than discovered by executing project binaries.

Every control flag must remain false: `packageMutation`, `sourceMutation`, `testMutation`, `fixtureMutation`, `selectorMutation`, `configure`, `compile`, `relink`, `repair`, `generatedDiscovery`, and `performanceBenchmark`.

### Required gate interpretation

Expected binding result is **338/338 PASS**.

- Any red identity among 1–316 is an accepted regression: **stop semantic progression and route to review**. Do not edit the expectation.
- Any red identity among 317–328 means the previously green CP4c-0 contract regressed: preserve the first typed failure and route to review.
- Any red identity among 329–338 means the corresponding E1–E7/E8 correction is not runtime-proved: preserve the exact diagnostic and route to review.

Do not continue to Q8 after a red 338 gate except where the runner must finish evidence-preservation bookkeeping. Do not repair or rerun a deterministic semantic red inside TB.

## Binding Q8 — verbatim frozen prediction

Q8 is only creditable because **E6 is present in this package**. If package/source verification cannot prove E6 belongs to `390e65b373063c667e3c3f5e78b74ed9d859093b`, Q8 is **not creditable** and the turn must stop as an integrity/planning failure.

The frozen Q8 text is:

1. Accepted **316/316** green, zero expectation edits.
2. The prescribed sphere reaches A2a and publishes a network — **24 traces**, from 8 index-1 singularities × 3 ports.
3. At least one sphere trace terminates on a trace/trace contact, producing a terminal `TraceIntersection` — which unblocks CP4c-1's C4/C5.
4. Face `1-2-5` with incoming `1-2` resolves to exactly one of `{1-5, 2-5}`, and the exit edge **flips** when the entry parameter is moved across the crossover.
5. The torus still publishes 0 traces; the mechanical still fails A1. Unchanged — they are not in scope.

Prediction 3 is binding: **if the sphere publishes a network but produces no terminal `TraceIntersection`, do not adjust anything — return to review**, because crash-on-contact still has no witness.

Preserve the complete emitted locus for any typed failure, including failure-site source face/edge/vertex when present, branch, exact parameter, exact values/published carriers, trace seed fields, trace step count/budget, and related face/branch for cross-edge disagreement.

## Post-run integrity

After the final planned process:

- re-hash the package archive and all package files used by runtime;
- re-hash the selector and confirm the 316/328 prefix hashes;
- compare pre/post source, package, selector, fixture, and runtime-input inventories byte-for-byte;
- record all mutation/build flags as false;
- preserve a machine-readable per-process ledger and complete diagnostic log.

Evidence upload failure prevents acceptance even if semantic commands passed.

## Benchmarks

None. CP4c-0 has no performance benchmark criterion. `performanceBenchmark=false` must remain frozen.

## TB-REV review obligations

Review existing TB-EXEC evidence only; do not launch unplanned runtime work. Classify every observed regression/candidate in `.agents/Directional/Regression_Root_Cause_Tracker.md` before durable closeout.

If the 338 gate and Q8 are both green, CP4c-0 closes and becomes the new accepted runtime authority; update checkpoint/project records accordingly and unblock CP4c-1.

If either the 338 gate or Q8 is red, route to independent **review + plan**. No Code + Build, semantic retry, fixture edit, expectation edit, tolerance retuning, or implementation change is authorized before that review.

## Plan-defined reruns

No automatic semantic rerun. Retry only a diagnosed orchestration/infrastructure failure that produced no valid semantic evidence, with the package, selector, commands, and semantic source unchanged.

## Completion criteria

`M3-CP4c-0-TB-R2` is complete only when:

- all 338 required processes have an exact result, or an explicit pre-semantic orchestration blocker stopped execution;
- Q8 has a binding PASS/RED result whenever the 338 gate is green;
- pre/post integrity is exact;
- machine-readable result and diagnostic evidence are uploaded;
- every regression/candidate observed by TB is durably classified;
- the next state is recorded without mutating semantic authority inside TB.
