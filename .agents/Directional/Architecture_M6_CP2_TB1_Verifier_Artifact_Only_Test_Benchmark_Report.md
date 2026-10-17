# `M6-CP2-TB1-VERIFIER-EXEC` — Artifact-Only Test + Benchmark Report

**Disposition:** COMPLETE / VALID SEMANTIC RED / 488/491 / THREE NON-STABLE REVIEW-OWNED CANDIDATES / CANDIDATE UNPROMOTED.

This turn consumed the immutable CP2 verifier compile package without rebuilding, relinking, configuring, repairing package content or permissions, regenerating discovery, or changing source/test/fixture/selector bytes. The frozen gate was exactly focused30 + CP2-focused12 + selector449 = **491 fresh exact-filter processes**.

## Immutable candidate authority

- compile/result artifact: `11365308211`;
- semantic source: `265c8fbb19a66c5c3344a525fdbd43932c3ef829`;
- candidate ZIP SHA-256: `3065e58741b1354e1f94ca04cc6169f0458aa11247443e77fb2914e55fa7b35e`;
- package root manifest: **28/28** before and after execution;
- exact arithmetic: GMP/GMPXX;
- Code + Build boundary entering TB: `runtimeExecution=false`.

The first executor attempt (`37364404710`) was cancelled by GitHub Actions before validation/runtime began; runtime was skipped and no evidence artifact was produced. It is infrastructure-only, not semantic evidence.

The authoritative retry is run `37368784487`, event/trigger SHA `136e80283ea6cca62a32ca5d2f8294e7ae2f27ab`:
- schema validator job `111960366428`: SUCCESS;
- runtime job `111962223674`: SUCCESS;
- mailbox job `111976782865`: CANCELLED after runtime evidence upload during the GitHub-hosted-runner incident;
- run-level conclusion is therefore FAILURE solely because the mailbox job did not publish.

Per workflow policy fallback authority, the exact run/job and immutable artifacts below are used directly. No duplicate runtime was launched.

## Runtime artifacts and mechanical gate

- result artifact `11370598981`, provider SHA-256 `e9260e352326edcf16ba5798830debf456f08e4bb3ff69c92ac53ceab33c17b6`;
- execution log artifact `11370413984`, provider SHA-256 `a455e284dbd17c81f42eceaccc88ea500e88dad3a8ce832024e2d20a038d5625`;
- result `SHA256SUMS`: **1005/1005** verified;
- result `SHA256SUMS` SHA-256: `2d7d798482e6e96e057fe16fe78a9421e10a4c63e4cad4c6d4366509baaba224`.

Gate result:
- focused30: **30/30 PASS**;
- CP2 focused12: **9/12 PASS**;
- selector449: **449/449 PASS**;
- aggregate: **488/491 PASS**;
- RED focused12 ordinals: **2, 6, 7**;
- exact-one selection: PASS for all 491;
- skips: **0**;
- benchmarks executed: **0**.

Execution boundary:
- `runtime_started=true`;
- `runtime_completed=true`;
- `orchestration_failure=false`;
- `selection_integrity=true`;
- `configure_execution=false`;
- `compile_execution=false`;
- `relink_execution=false`;
- `generated_discovery=false`;
- `package_repair=false`;
- `mode_repair=false`;
- `source_test_fixture_selector_mutation=false`;
- `retry_after_runtime_start=false`.

Package/source/execution-view byte-and-mode censuses match before/after, and focused30/focused12/selector449/routing449 hashes remained unchanged.

## RED candidates

### `M6-CP2-TB1-VERIFIER-EXEC-CAND-01` — focused12 ordinal 2

Identity: `M6CP2.VerifierRecomputesA0AndA5ElementaryIncidenceIndependently`.

Observed RED: expected `SourceIncidenceMismatch / a0:source-faces`, but no such finding was emitted.

The test's A0 tamper swaps two corners of one source triangle. `SourceFaceTopologyKey::make` sorts the three source vertex IDs before constructing the face key, so that permutation preserves the exact semantic source-face topology key. The test therefore does not actually create the intended A0 source-face mismatch.

**Classification:** ACTIVE / NON-STABLE / TEST-WITNESS AUTHORITY DEFECT / REVIEW-OWNED. This RED does not disprove the verifier predicate because the tamper is semantically a no-op.

### `M6-CP2-TB1-VERIFIER-EXEC-CAND-02` — focused12 ordinal 6

Identity: `M6CP2.CertificateChainRequiresExactA5A6A7PayloadBinding`.

Observed RED: expected `CertificatePayloadMismatch / a6:a5-binding`, but no such finding was emitted.

The test resets `relationCertificates.front().selectedRelationStep`. For an `OrdinaryFront` relation, production explicitly resets `certificate.selectedRelationStep`; the square fixture's first certificate therefore already has no selected step. The attempted tamper leaves the frozen A6→A5 field unchanged.

**Classification:** ACTIVE / NON-STABLE / TEST-WITNESS AUTHORITY DEFECT / REVIEW-OWNED. This RED does not disprove exact certificate payload binding because the selected field is unchanged.

### `M6-CP2-TB1-VERIFIER-EXEC-CAND-03` — focused12 ordinal 7

Identity: `M6CP2.WeldPinchedRecordViewFailsIndependentManifoldness`.

Observed RED: `ASSERT_TRUE(tampered)` fails before `SurfaceProductVerifier` is invoked.

The test searches the square fixture's classed cells for two cells with disjoint quotient-corner sets and only then welds one quotient vertex. The produced square fixture contains no such pair, so the malformed pinched record view is never constructed.

**Classification:** ACTIVE / NON-STABLE / TEST-FIXTURE NON-VACUITY DEFECT / REVIEW-OWNED. Independent verifier manifoldness is not disproved because the intended malformed input never reaches the verifier.

## Regression accounting

All three RED identities are newly introduced CP2 focused-gate authority and fail before their intended semantic predicates. The accepted focused30 prefix remains **30/30**, selector449 remains **449/449**, and no previously accepted-green runtime row regressed.

This EXEC therefore prices **+0 stable events / +0 categories / +0 recurrences**. Stable accounting remains **60 events / 16 categories / 44 recurrences**, architecture debt **1**. The CP2 verifier candidate remains **unpromoted**.

## Boundary and mandatory successor

EXEC does not authorize source repair or promotion. The exact next turn is mandatory independent `M6-CP2-TB1-VERIFIER-REV`, which must adjudicate the three candidates and freeze any bounded recovery before a new Code + Build or runtime attempt.

Reviewed production authority remains the prior promoted CP1 runtime `11330703256 / 3f40f04a0e9d382b2ec82cf37a03c18ad405eb05` (479/479) until Review promotes a successor.
