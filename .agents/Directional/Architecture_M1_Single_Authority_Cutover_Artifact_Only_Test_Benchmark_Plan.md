# M1 R-A — Immutable Artifact-Only Test + Benchmark Plan

## Purpose

This is the reusable execution authority for the **continuous R-A semantic gate**. It intentionally contains no current package SHA or artifact ID; the handoff supplies the fresh immutable package produced by the immediately preceding Code + Build turn.

The full M1 representative/benchmark characterization remains dormant until R-A through R-G are complete and one fresh complete M1 package exists.

## Turn boundary

This is an **artifact-only Test + Benchmark** turn.

Allowed:
- download the exact compile result/log artifacts named by the handoff;
- verify outer digests, archive safety, manifests, source/build metadata, and static audit;
- execute GTest discovery/listing and the selected packaged semantic tests;
- read packaged source only for evidence/classification;
- write evidence reports and durable status after runtime is complete.

Forbidden:
- configure, compile, relink, or rebuild;
- patch packaged source/tests/fixtures/manifests;
- repair permissions/content or replace a packaged binary;
- modify implementation/test/validator/build logic during the runtime portion;
- treat compile success, zero-selected filters, or missing evidence as semantic acceptance.

If the package is invalid, classify infrastructure/package failure and stop. Do not repair it in this turn.

## 1. Immutable package preflight

Before any packaged executable runs, require and record all of the following:

1. exact result/log artifact IDs and outer SHA-256 match the handoff;
2. ZIP paths are non-escaping and contain no symlinks;
3. recursive `SHA256SUMS` exists, excludes itself, and verifies every listed entry;
4. packaged source SHA equals the handoff authority and build exit is `0`;
5. build metadata proves the approved Release/static/Ninja/PRE_TEST Code + Build boundary and records generated runtime as not executed during compilation;
6. every packaged source-status snapshot required by the compile workflow is empty;
7. the source archive is extracted to a separate evidence directory, never over the runtime package;
8. `R_A_Closure_Inventory.py` is regenerated against that extracted source, byte-compared with the packaged report, and all required zero-unexpected/classifier-self-test gates pass;
9. record package path/type/mode/size state and executable hashes for postflight.

Any mismatch is infrastructure failure. Do not run semantic tests after a failed preflight.

## 2. Independent discovery

Independently execute `--gtest_list_tests` on every packaged executable used by the R-A gate. Record discovered counts.

For every selected filter:
- list the filtered tests first;
- require selected count > 0;
- a zero-selected filter is **orchestration failure**, never pass/skip;
- runtime execution must use the same immutable executable and filter that was listed.

## 3. Continuous R-A semantic selection

Run the complete R-A semantic groups, not only the contracts changed in the preceding Code + Build turn:

- authority-kernel contracts;
- `SurfaceCellAuthorityContractCutover.*`;
- isolation-seam authority contracts;
- retained completion/source-support/chart authority contracts;
- source-authoritative validator contracts;
- retained optimizer/final-validator authority contracts;
- rail-authority migration contracts.

Direct diagnostic groups may duplicate broad-gate tests, but the final acceptance count must deduplicate by full GTest identity.

### Required completion/stitch discrimination evidence

The following outcomes must be recorded per contract, not inferred from suite colour:

- `CoincidentPositionsOnDistinctTypedSheetsDoNotMerge`: successful non-merge evidence — success true, two connected components, zero merged boundary vertices;
- `WrongOwnerSheetCertificatePublishesNothing`: `InvalidTypedStitchAuthority`;
- `SameExactBoundaryKeyRejectsIncompatibleTypedLineage`: `IncompatibleTypedStitchAuthority`;
- `SameRegionSheetDifferentCompletedSupportsRejectTypedStitchCompatibility`: `IncompatibleTypedStitchAuthority`.

If any contract fails before its intended seam, classify the **earliest actual seam reached**. Do not credit a negative to a later validator it never reached.

## 4. Runtime evidence rules

For each group record:
- independently selected count;
- process exit code;
- pass/fail status;
- GTest XML and log;
- timeout or orchestration failure separately from semantic failure.

Produce:
- unique selected-test list;
- unique failing-test list;
- unique pass/fail totals;
- exact failure messages for every failed test;
- direct reason-capture evidence required above.

Do not convert an organic failure into a retry/threshold workaround within the same immutable package.

## 5. Immutable postflight

After runtime, re-run the recursive package manifest and compare package path/type/mode/size state plus executable hashes to preflight. Require zero symlinks and no package repair/mutation.

Record at minimum:
- `rebuild=false`;
- `sourceMutation=false`;
- `testMutation=false`;
- `fixtureMutation=false`;
- `packageRepair=false`;
- orchestration-failure count;
- semantic gate status.

Upload result and persistent log artifacts **before** propagating an organic semantic failure so failed gates retain immutable evidence.

## 6. Decision rule

R-A closes only when all of the following are true in the same immutable attempt:

1. package preflight PASS;
2. regenerated static inventory PASS and byte-identical to packaged authority;
3. independent discovery is non-vacuous for every selected group;
4. every unique R-A semantic contract passes organically;
5. required per-contract reason evidence is established;
6. postflight proves the package unchanged;
7. no unresolved orchestration/infrastructure failure exists.

If any semantic contract fails, preserve evidence, keep R-A open, classify the earliest failing invariant, and create the next bounded Code + Build plan. Do not mark Step 4 complete.

## 7. Full M1 activation

After R-A passes, complete R-B through R-G in Code + Build/Test + Benchmark cadence. Only then create a fresh full M1 package and a package-specific full-M1 acceptance plan covering representative fixtures, bounded quality/resource characterization, and the strict-validator timing characterization required by `DESIGN.md` and `tests/TESTING_STRATEGY.md`.

Do not reuse an R-A partial package as the full M1 acceptance candidate.
