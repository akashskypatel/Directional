# `M6-CP1-CB7-A6` — relation-validation recovery — Code + Build report

## Disposition

**COMPLETE / COMPILE+PACKAGE GREEN / RUNTIME-FREE / CANDIDATE UNPROMOTED.**

- Semantic source: `40842caa88f8d7a08a38c91273ace77ebd7c0676`.
- Candidate package: `11257522199`.
- Reviewed runtime authority remains `10879581622 / 82b86a28...`, selector449 **449/449**.
- Stable accounting remains **57 events / 16 categories / 41 recurrences**; project debt remains **1**.
- No generated Directional binary was executed in this Code + Build turn.

This report closes only the authorized CB7-A6 recovery turn. It does **not** promote the candidate, close CP1, discharge `G4-B002`, or authorize R4/A7 work. Those decisions remain behind immutable TB7-A6 and mandatory Review.

## Implemented scope

### Goal A — restore fail-closed HardRail authority at A5

A5 relation publication again validates the accepted HardRail contract before evidence becomes immutable:

- one accepted HardRail owner ID;
- endpoint source-topology regions must differ;
- endpoint routes must be exact reverses;
- route-composed canonical transport must act exactly on both endpoint placement states.

The new internal failure codes `HardRailRegionMismatch`, `HardRailRouteMismatch`, and `HardRailTransportMismatch` remain distinct in A5 and map through the legacy adapter to `InvalidHardRailTransport`. This restores the TB6 selectors 139/142 fail-closed predicate without weakening any downstream validator.

### RA-13 — one authoritative placement gauge

Exact-A3 Periodic relations no longer pass relation-endpoint-gauge `g` directly into the quotient product. A5 derives endpoint gauges from the published `make_periodic_relation_endpoint_state` authority and converts the relation transport to placement gauge as

```text
T = Γ_to^-1 ∘ g ∘ Γ_from
```

Both endpoint relation states are independently re-created and required to equal the published endpoint authority; the resulting placement-gauge transport must act exactly on both endpoint placement states. Storage direction is canonicalized by inversion when needed. Non-A3 Periodic relations keep their prior canonical action but now receive the same exact placement-action validation.

The strict A6 cycle rule is retained. On direct/path mismatch, `QuotientHolonomyConflict` still rejects and now carries the exact residual `compose(pathTransport.inverse(), directTransport)` as diagnostic evidence. Focused identity `M6CP1.CycleClosingRelationTransportConflictRejected` is unchanged.

### A6 certificate-to-A5 authority seam

Before `SurfaceQuotientProduct` acceptance, every A6 relation certificate is resolved to the immutable A5 owned relation and rechecked for exact canonical transport, equivalence evidence, and selected-step authority. A6 therefore cannot certify a locally self-consistent but stale or tampered copy of A5 relation evidence.

Focused identity `M6CP1.QuotientRejectsMissingDuplicateOrConflictingConsumption` gains one tamper-away-from-A5 branch that must reject as `RelationCertificateConflict`. The focused identity count remains 11; no selector, routing, fixture, benchmark, or unrelated test surface changed.

## Frozen static checks

- selector449 SHA-256: `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`;
- selector448 prefix SHA-256: `70ff08601bf244fcb4883e5d0601d5e7a3a44f52a8e855544a065c6ca5c75789`;
- routing449 SHA-256: `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707`;
- routing owner census: `32 / 301 / 75 / 41`;
- selector line count: 449;
- focused identity 11 remains byte-unchanged in source.

## Patch transport evidence

The exact source patch was generated from source-snapshot authority `752cb378a0c6d7ef78dd534eec14c11e912a0903`, verified with `git apply --check` and `git diff --check`, and preserved as a user-visible recovery patch before remote application.

- Patch SHA-256: `64bae4be00d40d461f540aa99dbef73f6d61670820660add39050c668fe29e70`.
- Diff-body SHA-256: `90cc7232adf19cd135a23042bcae3dd25d208819b3241d88d797fc8e92686b7c`.
- Apply run/job: `37077973335 / 111072026039` — success.
- Result/log artifacts: `11258135023 / 11258010305`.
- Result/log digests: `sha256:b9d009c3d712ad9615f00cf3836bbb46522b9e8d75c4d29ddb04ec861a16e236` / `sha256:69c9d96d6c8e828355e5d9c616c0b242cb6e5a1bc4f3f8a417886dd497bee9cf`.
- Produced semantic source: `40842caa88f8d7a08a38c91273ace77ebd7c0676`.
- The workflow Drive identity reported owner retirement required; the user-authorized Drive connector then permanently deleted the exact staged file.

## Compile evidence

Compile run/job `37078118843 / 111072482082` is authoritative for this Code + Build turn.

- Result artifact: `11257522199`, digest `sha256:bbb18e89f41b959aa82e285c20b543ac9fea9f65fad6a07b0e6cfb1d989f10fd`.
- Log artifact: `11257522202`, digest `sha256:a25f02b42ed950336eda2924c3345c10facf451260395af471838b087a37bef6`.
- Exact packaged source: `40842caa88f8d7a08a38c91273ace77ebd7c0676`.
- Source archive SHA-256: `2c8981c6da6e9e72b4977f2879a687e2ba1c6c042591bd82720936f69888d27f`.
- Root package manifest: **28/28 verified**.
- Preflight/build exit: **0 / 0**.
- All packaged source-status receipts are empty.
- Boundary metadata: `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `exactArithmeticBackend=GMP`.

Compiled targets:

```text
directional_core
directional_pipeline
directional_surface_cell_authority_kernel_tests
directional_surface_cell_producer_tests
directional_surface_cell_completion_tests
directional_surface_cell_validation_tests
directional_compiled_api_tests
directional_benchmarks
```

GMP/GMPXX linkage is explicit in the generated link evidence (`libgmpxx.so`, `libgmp.so`). No tests, benchmarks, generated discovery, or other Directional runtime executed.

## Closeout and hygiene

A process-only observation is recorded at +0: repository/policy reads preceded the explicit `READ_MODE=snapshot` declaration in the web session. The ordering was corrected before semantic source inspection or editing, and all semantic work used verified exact-source snapshots. No product, compile, or runtime evidence depends on the preliminary reads.

The source-patch and compile callers were retired before documentation closeout. The durable documentation patch (SHA-256 `baa6e7ee3b820bffb72ef7dbe260a25cdf8f3f4b9fb352d8d09692a6a00b38d9`) applied successfully in run/job `37079472203 / 111076640601`, producing documentation commit `0fe698fe0f68b24df8024cd8832ce7f73bdc5410`. Its staged Drive file required owner cleanup and was permanently deleted; the temporary docs caller was then retired at commit `c55cf452e53f5e658a1213f1038264b16d0cd1ef`.

Mandatory turn-cleanup run/job `37079589998 / 111076950526` succeeded. Cleanup result artifact `11257234702` has digest `sha256:b31c4abe3f4862e20497d8f5b9ef4c93b28cdfe0c37d5a21f6bba380b0b152f4`; cleanup commit `77497c29d2b56efcb5eca0fbf64e0492dd21c2a1` removed the five inventoried CB7 marker/snapshot paths plus its manifest, deleted 6 PR conversation comments and 0 inline comments, verified 0/0 remained before the observer, and recorded `runtimeExecution=false`. Post-cleanup inspection shows exactly the seven durable workflows and no `.agents/connector-triggers`, `.agents/workflow-observation`, or `.agents/Directional/turn-payloads` temporary state. This cleanup is control-plane evidence, not Code + Build semantic evidence.

## Successor gate

Exact successor: **`M6-CP1-TB7-A6-EXEC`**.

TB7-A6 consumes candidate `11257522199` immutably and executes **11 focused + selector449 = 460** fresh exact-filter processes, benchmark 0. It must construct the standard separate execution view from packaged-source fixtures before runtime. Recovery green requires rows 139/142 to reject with `InvalidHardRailTransport`, rows 140/232/444/446/448/449 to pass, focused6 to pass under strict cycle equality, strengthened focused10 and unchanged focused11 to pass, zero accepted-produced-row `QuotientHolonomyConflict`, zero `OccurrenceInvalidCornerAuthority`, exact-one selection/zero skips, and immutable postflight. Mandatory `M6-CP1-TB7-A6-REV` follows before promotion or R4/A7/G4 work.
