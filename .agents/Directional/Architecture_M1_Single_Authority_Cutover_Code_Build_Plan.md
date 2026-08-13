# M1 Single-Authority Cutover — Active Code + Build Plan

## Status

R-A remains **open** after immutable artifact-only retry 4.

Entering runtime authority remains M1l `bd140cff4572412e6f4ecd70a6ce0fe85310932c`.

Retry-4 tested exact source `aa16449577c48bac72257b7b9915e2b70dad3b82` from compile package `9171125667 / 9171126075` in runtime run/job `31679754667 / 94382280555`. Immutable preflight, regenerated **19 / 60 / 270 / PASS** static inventory, independent discovery, and postflight all passed. The semantic gate selected **92 unique contracts: 88 passed / 4 failed, orchestration failures 0**.

Runtime evidence artifacts:
- result `9173016395`, SHA-256 `39f71abb285ac1e806f2fdaded58a3675d6491b3a8177999def697b9aa6678ac`;
- log `9173016645`, SHA-256 `9c1ff473c56cf867e3cd6f8600f888ba438955dfbb96bf3c1084578112ab2176`.

CB-01 stale-cache and CB-03 provenance remediation are runtime-green. The remaining four failures are all the CB-02 feature-bearing aggregate/final-oracle contracts and all stop earlier at component `completion`.

## Turn boundary

The next turn is **Code + Build only**. Source, tests, diagnostics, audit code, build configuration, and durable current-state documentation may change only as required below. Configuration/compile/link/static analysis are allowed. Generated Directional tests, benchmarks, GTest discovery/listing, `ctest`, CLI, fuzzer, help/version commands, and custom inputs are prohibited during that turn.

Do not answer retry-4 failure by weakening validation, removing internal feature authority, converting the witness to a boundary-only feature, synthesizing rails in test callbacks, or bypassing the producer that actually owns the invariant.

## R-A-TB4-CB-01 — preserve the earliest typed feature-production failure

### Runtime evidence

`ComponentFeatureRailTamperRejectsAtAggregationSeam` still terminates at `completion`; the outer first-invalid-producer reason is empty. The outer aggregate already copies the inner component stage/reason fields directly, so retry 4 disproves the assumption that aggregate propagation itself was the remaining loss point.

### Exact-source diagnosis

The current hard-feature witness is the shared diagonal of a two-triangle square.

- Hard-feature edges are barriers in source-topology-region construction, so that diagonal separates the two source triangles into distinct one-triangle topology regions.
- The curved bounded-disk phase-front producer explicitly returns `NotApplicable` when a region has fewer than four boundary edges/vertices. Each one-triangle region has three.
- If every region producer is not applicable and none produces a phase-front product, the pipeline can proceed without `useAuthoritativePhaseFront`.
- The retry-3 CB-02 exact `HardRail` lineage projection is guarded by `useAuthoritativePhaseFront`; it therefore cannot execute for this witness.
- The later generic completion-rejection branch unconditionally assigns `surfaceCellFirstInvalidProducerStage/Reason` from the completion/lineage outcome. If the downstream outcome has no diagnostic string, it can replace earlier producer context with an empty reason.

### Required correction

1. Preserve the **earliest exact producer failure/unsupported condition**. A later generic completion rejection must not overwrite a non-empty earlier typed producer diagnostic with an empty or less-specific reason.
2. When a hard-feature-separated topology region is outside every current phase-front producer's supported domain because its bounded-disk boundary extent is below the supported minimum, publish an explicit typed unsupported/fail-closed condition rather than silently collapsing to empty `completion` diagnostics.
3. Preserve ordinary non-feature fallback behavior unless the same single-authority rule proves that it must change.
4. The disconnected aggregate must continue copying, not inventing, component producer diagnostics.
5. Add/retain a focused contract for the two-triangle diagonal witness that pins the exact typed unsupported/fail-closed result and proves no semantic output is published.

## R-A-TB4-CB-02 — production-feasible internal hard-feature aggregate/final-oracle witness

### Runtime evidence

The following four contracts still never reach their intended seam:

- `ComponentFeatureRailTamperRejectsAtAggregationSeam`;
- `FinalMergedOracleRejectsMissingRemappedFeatureAuthority`;
- `FinalMergedOracleRejectsChangedRemappedFeatureRailContent`;
- `FeatureBearingFinalMergedOracleAcceptsPresentRemappedFeatureAuthority`.

The existing two-triangle-square diagonal is outside the current phase-front bounded-disk support described above. It therefore cannot validate the post-materialization `HardRail` projection or aggregate/final-oracle feature authority.

### Required correction

1. Replace **only the aggregate/final-oracle feature witness** with a sufficiently resolved source mesh carrying a non-empty **internal** hard feature whose hard-feature-separated topology regions meet the current phase-front producer's supported bounded-disk preconditions and naturally produce a phase-front product.
2. The witness must reach production completion without test-side rail synthesis. Establish source-level preconditions that make the witness non-vacuous: internal hard edge(s) are owned/remapped, authoritative hard rails are non-empty, phase-front materialization is actually used, and completed feature authority is non-empty before the aggregate/final-oracle counterfactual.
3. Retain the two-triangle diagonal as the separate unsupported/fail-closed contract from CB-01; do not silently replace or erase it.
4. Preserve these intended runtime outcomes:
   - component feature-authority tamper reaches aggregation and rejects `ChangedComponentValidationAuthority`;
   - missing remapped feature authority reaches the final oracle and rejects `MissingFeatureRail`;
   - changed remapped feature content reaches the final oracle and rejects the exact strict feature-authority issue established by the validator;
   - present non-empty remapped internal-feature authority reaches the final oracle and passes.
5. Do not substitute empty feature authority, a source-boundary rail, or a callback-fabricated feature sequence.

## R-A-TB4-CB-03 — retain retry-4 green authority

Preserve without weakening:

- the genuine same-cardinality stale-cache contract and separate missing-cardinality rebuild positive;
- the guaranteed provenance `SourcePositionMismatch` counterfactual;
- F1 retained source authority;
- all four F2/F3 completion/stitch discriminants and exact reasons;
- F5 component feature-option conservation/no-leakage and unassigned-hard fail-closed;
- all other runtime-green R-A contracts.

If the new feasible feature fixture needs shared helpers, keep its intent explicit and do not broaden production behavior merely to satisfy fixture mechanics.

## R-A-TB4-CB-04 — static closure and fresh immutable compile package

After CB-01 through CB-03:

1. update `R_A_Closure_Inventory.py` only where new/renamed semantic contracts or source authority require probe coverage;
2. regenerate `R_A_Closure_Inventory_Report.md` from the exact source and require final static PASS with zero unexpected authority leaves and classifier self-test PASS;
3. compile/link the approved R-A targets through the durable reusable compile workflow;
4. package exact source, binaries, build logs, five clean source-status snapshots, command-boundary metadata, and a self-excluding recursive SHA-256 manifest;
5. execute **no generated runtime** in Code + Build;
6. record the fresh exact source/artifact authority for the following Test + Benchmark turn.

## Closure after this plan

The following turn is immutable artifact-only **R-A retry 5** against the fresh package. It must run the complete continuous R-A semantic gate with non-vacuous discovery, retained F2 reason evidence, the unsupported hard-feature contract, the four feasible internal-feature aggregate/final-oracle contracts, and immutable pre/postflight.

R-A closes only on an organic all-pass. R-B through R-G remain blocked behind R-A. Full-M1 representative/benchmark acceptance remains dormant until one fresh complete R-A-through-R-G package exists.
