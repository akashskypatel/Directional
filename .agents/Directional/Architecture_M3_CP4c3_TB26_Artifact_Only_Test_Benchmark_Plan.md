# M3-CP4c-3-TB26 — Artifact-Only Test + Benchmark Plan

## Validation identity

- Phase/checkpoint: `M3-CP4c-3`
- Execution subturn: **`M3-CP4c-3-TB26-EXEC`**
- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`
- Exact semantic source under test: `e045bf7147afc02bd90eff4822e4b609edbaba66`
- Immutable CB30 package artifact: **`9957324848`**
- Package provider SHA-256: **`7ea9446f2e8cde520b8f7570cc62ba189ccffe801bd68a298f56560c661f81de`**
- Package producer run/job: **`33927223741 / 101198287660`**
- Selector: `.agents/Directional/Architecture_M3_CP4c3_Required_Green_Selector_405.txt`
- Selector 405 LF SHA-256: **`615370b65e590dadb59d7a233c6ce74b7dc8cb46a1f40fd3ea5a44257583aae7`**
- Frozen prefixes: selector 403 `60ff6daa0e1dc71fe9c856ee9559d665628b756ed634f70ffce5881ec2514007`; selector 401 `0d0857a97158dfd0763b536718c24ba257417866aad3d8e51d6f0093be5a5869`; selector 397 `d67e5fb72196313c54fbc21be0b446ab0fba3974c47c02e18c33dfe9b4853ee5`.

## Objective

Execute the complete selector-405 authority from the immutable CB30 package, one identity per fresh process, to determine the runtime effect of CJ6–CJ9 while protecting the accepted 1–365 boundary. TB26-EXEC records facts only. It must not diagnose beyond the plan-defined factual classifications or authorize a source change.

The decisive new evidence is:

- ordinal **404**: the boundary, interior-arc and vertex-transit censuses publish completely on the production ownership-failure path without requiring an established owner;
- ordinal **405**: an independently constructed vertex-transit witness proves the census can name a separation that no source-edge barrier can carry;
- ordinals **389/390/393**: their own embedded-cellularity/census contracts execute without being collateral gates on ownership totality;
- ordinal **398** remains unchanged and is the only gate on complete certified source-face ownership.

## Preconditions / fail-closed checks

Before the first Directional process:

1. Download artifact `9957324848` exactly once and verify its provider SHA-256.
2. Verify the package `SHA256SUMS` recursively and confirm `metadata/source-commit.txt == e045bf7147afc02bd90eff4822e4b609edbaba66`.
3. Verify `metadata/command-boundary.txt` records `runtimeExecution=false`, `turnBoundary=Code+Build-only`, and GMP exact arithmetic.
4. Verify the packaged binaries are the immutable package bytes; create only a staged execution view/hardlinks needed for fixture-relative lookup. Do not relink or repair.
5. Verify selector 405 has exactly 405 identities and exact LF hash above.
6. Verify selector 403 is the exact first 403 lines of selector 405, selector 401 the exact first 401 lines, selector 397 unchanged, and accepted selector 365 remains the exact first 365 identities.
7. Record byte censuses of package, packaged source and execution view before runtime.
8. Fail as **orchestration failure with no semantic ledger** if any authority/integrity/prefix/fixture/execution-view precondition fails or if zero identities are selected.

## Ordered execution

### 1. Full selector-405 gate

For ordinals **1 through 405 in selector order**:

- launch the owning packaged GoogleTest binary in a **fresh process** using exactly one selector identity as the filter;
- do not use generated test discovery/listing; selector 405 is the authority;
- capture ordinal, exact identity, binary, exit status, PASS/RED classification, stdout/stderr, elapsed time and `/usr/bin/time -v` resource data;
- continue through all 405 identities after semantic failures so the ledger is complete;
- do not retry an identity merely because it is RED.

A process launch failure, missing packaged binary/fixture, malformed filter, zero selection, timeout imposed by orchestration, package mutation, or harness failure is **orchestration failure**, not semantic RED.

### 2. CJ6/CJ7 evidence preservation

For the mechanical production identities that reach the certificate, preserve the complete untruncated per-component diagnostic payload, especially component 0:

- every boundary-census row (expected 97 rows only as a prior observation, **not** an acceptance oracle);
- every interior arc-incidence row with arc kind and both dart orbits;
- every vertex-transit row with source vertex, incident component faces and non-barrier adjacency state;
- seed state, seed count, full seed multiset/per-edge attributions;
- published source-face ownership census.

Do **not** collapse this evidence to counts before TB26-REV. The frozen CJ6 falsification contract requires named loci.

### 3. Postflight immutability

After ordinal 405 terminates:

- recompute package, packaged-source and execution-view censuses and require equality with preflight;
- record `configure_execution=false`, `compile_execution=false`, `relink_execution=false`, `generated_discovery=false`, `package_repair=false`, `mode_repair=false`, and `source_test_fixture_selector_mutation=false`;
- package the complete 405-row ledger, identity map, raw per-identity logs, resource records and structured CJ6 payload separately from the diagnostic workflow log.

## Acceptance criteria

TB26-EXEC itself records results; `M3-CP4c-3-TB26-REV` adjudicates them.

- **Accepted-prefix safety:** ordinals 1–365 must remain **365/365 PASS**. Any accepted GREEN loss is blocking semantic RED.
- **Selector integrity:** all 405 identities must execute exactly once in fresh processes under the immutable package.
- **New witnesses:** 404 and 405 are gating and must PASS for CB30's new observability/falsifiability claims to hold.
- **CJ8 collateral gates:** 389, 390 and 393 are evaluated only against their retained identity-owned assertions; their results must be preserved exactly.
- **Ownership totality:** ordinal 398 remains unchanged and authoritative. Do not reinterpret or weaken it in EXEC.
- **Checkpoint closure:** only **405/405 PASS** under a valid immutable execution can be a GREEN gate eligible for checkpoint closure after TB26-REV confirms the evidence/accounting. Any semantic RED routes through diagnostic review and then the project-required independent review/planning boundary; no patch/retry is authorized directly from EXEC.

## TB26-REV discriminator contract

TB26-REV must classify the production component-0 CJ6 evidence using the pre-authored exhaustive cases, without changing them after seeing runtime:

1. **interior arc-incidence non-empty** → a separating embedded arc meets the component interior; name the arc/locus;
2. otherwise, **vertex-transit census contains a vertex whose incident uncut faces are adjacent across a non-barrier edge** → the missing separator is a vertex transit the source-edge barrier partition cannot represent; name the vertex/faces;
3. otherwise, neither hidden-arc mechanism is present → by the frozen certified-face dichotomy the component lies in exactly one certified face; record the seed evidence separately and do not choose an owner by majority inside EXEC.

These cases interpret only the CJ6 measurement. They do not authorize a barrier or partition change inside TB26-REV; if a semantic RED requires architectural correction, the next boundary is independent REVIEW + PLAN and the orchestration loop must stop there.

## Benchmarks / resources

No performance benchmark target is part of CP4c-3 acceptance. Record per-process elapsed time and maximum RSS for regression visibility only. No quality/performance threshold may override correctness or gate integrity.

## Unit-test design check

- Contract: publication of independent structural censuses on the failure path; falsifiability of vertex-transit separation; one contract per gate.
- Production witness 404 asserts publication/completeness rather than a predicted census value, preventing the test from encoding the review's hypothesis.
- Constructed witness 405 supplies a known vertex-transit topology so a broken census cannot pass on default/empty values.
- Ordinal 398 remains the unchanged strong ownership-totality oracle.

## Stop / blocker conditions

Stop before semantic runtime if artifact/source/selector/prefix/GMP authority fails. Stop and classify the attempt as orchestration failure if the execution harness cannot run the complete selector as authored. Do not rebuild, repair, alter fixtures/selectors, synthesize missing evidence, change timeouts to manufacture a result, or stitch multiple partial ledgers into semantic authority.

## Completion

TB26-EXEC is complete when one immutable run has a full 405-row ledger or a clearly preserved orchestration failure with no semantic ledger. Its exact successor is **`M3-CP4c-3-TB26-REV`** for diagnostics/review of the recorded evidence; TB26-EXEC must not perform that review itself.
