# M3-CP4c-3-TB24 Artifact-Only Test + Benchmark Plan

## Status

**FROZEN FOR `M3-CP4c-3-TB24-EXEC`.** Runtime execution only. This plan consumes the immutable CB27 compile
package and does not authorize any source, build, test, fixture, selector, harness, or package mutation.

## Immutable authority

- semantic source: `9c72fea8b666534b9e52fa42bbe8cbf8ae68ffe5`
- package artifact: `9935929108`
- package SHA-256: `b5e11a2c97c110d2cf484d63bb3afe3b753e7f4769098ec927a5cf1692f5d881`
- CB27 compile run/job: `33870767698 / 101015974984`
- selector 397 frozen prefix SHA-256:
  `d67e5fb72196313c54fbc21be0b446ab0fba3974c47c02e18c33dfe9b4853ee5`
- selector 401 current gate SHA-256:
  `0d0857a97158dfd0763b536718c24ba257417866aad3d8e51d6f0093be5a5869`
- accepted runtime authority entering TB24: TB23-R1, **365/365 accepted**, **389 PASS / 8 RED** on selector 397.

## Hard execution boundary

TB24-EXEC may execute packaged binaries only. It must not configure, compile, link, relink, rebuild, repair the
package, generate discovery data, edit source/tests/fixtures/selectors, or substitute a locally built binary.
Package, packaged-source, selector, fixture, executable, and execution-view censuses are captured before and after
runtime and must match.

Run each selector identity in ordinal order in a fresh process, using the same executable-routing and
package-fixture resolution discipline proven by TB23-R1. Stop and classify the turn as orchestration-invalid if
preflight cannot prove that every selected executable and required fixture tree resolve to immutable package
authority before the first Directional runtime starts.

`TB24-EXEC` records facts only. It does **not** diagnose new REDs or change stable regression accounting. Semantic
RED diagnosis/classification belongs to the subsequent `TB24-REV` independent review boundary.

## Required preflight

1. Verify outer package artifact digest and every packaged manifest checksum.
2. Verify `metadata/source-commit.txt` is exactly
   `9c72fea8b666534b9e52fa42bbe8cbf8ae68ffe5`.
3. Verify command boundary says `runtimeExecution=false`, `turnBoundary=Code+Build-only`, and
   `exactArithmeticBackend=GMP` for the producer package.
4. Verify the exact six packaged runtime executables used by the selector and record their SHA-256 values.
5. Materialize an execution view without modifying package bytes; verify every executable resolves to the package
   and fixture resolution succeeds through the consumer's own fail-closed rule.
6. Verify selector 397 is byte-identical to the frozen hash and is the exact first 397 lines of selector 401.
7. Verify selector 401 has exactly 401 identities and the frozen selector-401 hash.
8. Capture package/source/execution-view pre-runtime censuses.

## Runtime gate

Execute selector 401, one exact identity per fresh process, preserving ordinal order. Record for every ordinal:

- identity name;
- executable identity and SHA-256;
- process exit/result;
- PASS or RED;
- exact emitted diagnostic/locus for RED;
- whether the ordinal belongs to accepted prefix 1–365, carried CP4c-3 authority, or new CB27 witness set.

The authoritative ledger must include all 401 ordinals. No result may be inferred from another identity.

## CG9 mandatory discriminator report

### D1 — accepted prefix

Report ordinals 1–365 independently. Required checkpoint safety condition: **365/365 PASS**. Any RED in this prefix
is an accepted regression and blocks semantic credit for the turn.

### D2 — owner-map production totality

For the mechanical production witness, report source-face count, published owner-entry count, whether the map is
total, whether every owner orbit belongs to the certificate's own face-orbit set, and the first typed failure if
not.

### D3 — component-0 owner multiset

Report the certified owner for **every one of component 0's 191 source faces**. Publish:

- observed count;
- unavailable count;
- distinct owner count and sorted distinct owners;
- all-equal = true/false;
- if not all equal, representative source faces for each distinct owner.

This is the authoritative discriminator for `M3-CP4c3-TB21-CAND-01`: **all equal** supports the mis-read-seed
branch; **not all equal** supports the missing-barrier branch. EXEC reports only the measured branch; review owns
classification.

### D4 — relocated ordinal 366 guard

Ordinal 366 must either PASS or fail through the relocated certified-owner consistency rule. A RED must name the
component and conflicting owners. The old seed-derived diagnostic is not an acceptable substitute.

### D5 — corrected ordinals 393 and 397

Both **393 and 397 must PASS**. 393 now tests the published owner-map contract; 397 remains the byte-identical
unrelated-locus regression witness and must not accept `;cutCandidateCount=0`.

### D6 — carried surfaces

Report 367/368/369/370/374 exactly as observed. Report 371/372/391/392 explicitly and compare them with the prior
PASS authority. Do not classify changes in EXEC.

## New selector-401 witnesses

Execute and report ordinals 398–401 independently:

398. production owner-map totality on the production fixtures;
399. rejection of a source-face owner outside the certificate's own face set;
400. independent falsifiability of conflicting certified owners in one source component;
401. fail-closed missing package/fixture resolution.

All four are gating in selector 401.

## Postflight

1. Recompute package/source/execution-view censuses and prove equality with preflight.
2. Confirm no configure/compile/relink/rebuild/discovery/package-repair/mode-repair/source-test-fixture-selector
   mutation occurred.
3. Publish the complete 401-row ledger, summary counts, accepted-prefix count, all six discriminators, and runtime
   environment/resource evidence required by the standing TB policy.
4. Preserve immutable result and diagnostic-log artifacts with SHA-256 digests.

## Outcome routing

- If orchestration/preflight is invalid before semantic runtime, the evidence is orchestration provenance only;
  route according to the standing orchestration-correction workflow.
- If semantic runtime is valid and any gating identity is RED, stop at **`M3-CP4c-3-TB24-REV`**, independent
  REVIEW + PLAN. EXEC does not diagnose the RED.
- If semantic runtime is valid and selector 401 is fully GREEN, preserve the evidence and advance only to the
  project-defined checkpoint-close/review boundary; do not start later milestone implementation from TB-EXEC.
