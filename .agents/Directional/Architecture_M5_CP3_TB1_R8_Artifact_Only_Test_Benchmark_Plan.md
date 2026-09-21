# M5-CP3-TB1-R8 Artifact-Only Test + Benchmark Plan

## Validation identity

- Phase: `M5-CP3-TB1-R8-EXEC`
- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`
- Candidate source: `1023eea6090a1f6c2d47ecaceb1099967c32e6c2`
- Candidate artifact: `10660365136` (`m5-cp3-cb9-result-35644260337`)
- Candidate ZIP SHA-256: `30333b2edbcd011ca52ae9e7e134884f72f4425a56103f179b6a3b6b3d1b0729`
- Candidate root `SHA256SUMS`: 28 entries, SHA-256 `9cfe8fac63bf730c59b271eec7ee5948debca285d73eec4b9cbc81396b58e464`
- Candidate packaged source archive SHA-256: `38dff143f89ee882cd40f85d2344fb96b68f87eb864d52a352a5404e244a5bbc`
- Compile run/job: `35644260337 / 106480821581`
- Compile log artifact: `10660330234`, ZIP SHA-256 `7957e1f97820866a6b26d0149e6ca98ec67de857273c0f24185418c9e8c657d1`
- Accepted selector430 SHA-256: `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`
- Accepted first427 SHA-256: `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`
- Accepted selector routing identity-map SHA-256: `7a92e7a3b8a69466423c4a0d2ad5ece2dcd4912f04eeb99e1f32fa70b4a5cf6c`
- Platform: GitHub Actions `ubuntu-24.04`, artifact-only
- Mandatory successor after mechanically complete execution: `M5-CP3-TB1-R8-REV`

## 1. Boundary

R8 is an immutable artifact-only runtime gate. It may execute only binaries contained in candidate artifact `10660365136`. Do not rebuild, configure, compile, relink, repair the package, run generated discovery, mutate source/tests/fixtures/selectors, or substitute a checkout-built binary. Preserve packaged executable modes during extraction; `chmod` repair is prohibited.

The candidate was compile/package verified with mandatory GMP/GMPXX and `runtimeExecution=false`. R8 supplies the first semantic execution of the CB9 witness-authority correction.

## 2. Preflight

Before generated Directional runtime:

1. verify artifact/provider identity and candidate ZIP SHA-256;
2. verify all 28 root `SHA256SUMS` entries and the manifest file hash;
3. verify packaged source archive SHA-256 and exact semantic source commit;
4. verify required executables are present with archived executable modes intact;
5. verify GMP/GMPXX evidence from the compile package;
6. verify selector430, first427, and accepted routing identity-map hashes exactly;
7. record package/source/execution-view byte+mode censuses for immutable postflight;
8. initialize counters for configure, compile, relink, generated discovery, package repair, mode repair, source/test/fixture/selector mutation, custom input, and benchmark execution at zero.

Any identity, checksum, mode, selector, routing, or source mismatch is an orchestration stop. Do not repair the candidate.

## 3. Frozen execution surface — exactly 446 processes

Execute each required identity in a fresh process with exact-one selection and zero skips:

- nine reviewed mechanism identities;
- one focused retained-value atlas control;
- the same six CP3 produced identities;
- selector430: 430 identities.

Total: **446 processes**. Execute benchmark work **0** times.

The six produced identities remain the exact CP3 set used by R7. CB9 changed only their test-local witness authority, not selector430 or accepted routing.

## 4. Mandatory semantic outcomes

The intended all-green vector is:

- mechanism: **9/9 PASS**;
- focused retained-value atlas: **1/1 PASS**;
- produced: **6/6 PASS**;
- selector430: **430/430 PASS**.

Produced rows 1–3 must remain green and continue to provide the already reviewed relation-owner/reorder and missing-owner production evidence.

### Produced row 4 — genuine nonzero-Z4 materialization

Require the source/A3 oracle to select a genuine nonzero directed row408-class hard-edge transition before product relation inspection. The corresponding published relation must preserve the independently derived generator route and directed quarter-turn, retain nonzero rotation and translation, materialize successfully, be consumed by a selected relation-path certificate, and yield `consumedPeriodicHolonomies > 0`.

The inverse directed transition is **not** equivalent. Any source-oracle/product-direction disagreement is RED.

### Produced row 5 — tampered nonzero-Z4 action

Require the same independently selected relation. The test must prove its action changes while its semantic ID remains unchanged, reach the tamper discriminator, and reject with exact typed `NonReciprocalPeriodicRelation`. Failure to reach tamper is RED.

### Produced row 6 — genuinely unused valid relation

Require the appended relation to be independently valid and, before insertion, absent from the produced relation table, unowned by all phase-front edges, and unreferenced by the baseline selected certificate. Baseline and extended materialization must succeed with identical selected certificate signatures, completion hashes, and consumed-periodic counts; the added ID must remain unselected/unconsumed.

## 5. Immutable postflight

After all 446 processes, require exact equality with preflight for:

- package bytes;
- packaged source bytes;
- execution-view bytes and modes;
- selector/routing authority hashes;
- candidate manifest.

Require all prohibited-operation counters to remain zero:

- configure;
- compile;
- relink;
- generated test discovery/listing;
- package repair;
- mode repair;
- source/test/fixture/selector mutation;
- custom input;
- benchmark execution.

## 6. Evidence package

Publish a self-contained result artifact with at minimum:

- provider/candidate/source/checksum receipts;
- exact 446-row process ledger with filter, owner, selection count, skip count, exit status, outcome, duration, and raw-output hash;
- mechanism/focused/produced/selector summaries;
- raw logs for all semantic REDs, if any;
- package/source/execution-view pre/post byte+mode censuses;
- prohibited-operation counters;
- final recursive self-manifest and hashes;
- `runtimeExecution=true` for this TB gate and `benchmarkExecution=0`.

Do not promote candidate authority, credit debt, publish a selector, or mutate repository semantics in EXEC.

## 7. Stop and successor rules

A mechanically complete R8 always routes to mandatory runtime-free `M5-CP3-TB1-R8-REV`.

- If any semantic identity is RED, preserve it exactly and route to Review. Do not repair tests or product code in EXEC.
- If all **446/446** pass, Review must independently re-derive the nonzero source witness, directed-orientation oracle, unused-relation non-vacuity, process ledger, immutable postflight, and accounting before it may discharge the remaining two M5 debts or pre-commit selector publication.
- Candidate `10660365136` remains unpromoted until that Review explicitly promotes it.
