# RA-47.12 — default-path typed-interval liveness census

**Turn:** `M6-CP3-CB1-R4-RA4712-LIVENESS`
**Source authority:** exact frozen `f983508edcd0157ca3c93832753102067ab392ef` from GitHub Actions snapshot run `38645902635`, artifact `11932381704` (5,600/5,600 file hashes; source archive SHA-256 `6f4af4394eb028e06919b4b566c4f8a7a23d4b3c38c9592fb34a78c5fb058259`).
**Disposition:** `RP-02 TEST_AUTHORITY_COVERAGE_GAP` — the default-path **network-bound consumer's actual execution is unproved**, not proven unreachable.

## Call-path census and first decisive distinction

1. `src/pipeline/RemeshPipeline.cpp:9630-9634` validates producer-created rails through `rail_interval_refs(..., nullptr, RequireTypedSource)`; this proves the producer has a strict typed check but does **not** exercise a field-aligned network-bound consumer.
2. `src/pipeline/RemeshPipeline.cpp:12476`, `:12682`, and `:12698` thread the producer's rails through `FieldAlignedCurveNetwork::make` and publish a nonnull `tracingOptions.fieldAlignedNetwork`. This is a structurally legitimate producer-to-consumer path.
3. `src/geometry/SurfaceCellTracing.cpp:10498-10502` calls `rail_interval_refs` with the network at ordinary `trace_surface_field` ingress, but `:19560-19577` returns early for a produced authoritative phase front. This is **not** a proof that normal phase-front production executes that particular check.
4. `src/geometry/SurfaceCellTracing.cpp:12414-12428` contains the authoritative open-front boundary consumer, which does invoke network-bound `rail_interval_refs(..., RequireTypedSource)`. Its call sites at `:13058`, `:14790`, and `:17412` are conditional on respective producers reaching their open-boundary loops; a test must establish that at least one such call occurred with *produced*, nonempty rails on a default execution, without injection, manual invocation or a standalone fixture.
5. `tests/SurfaceCellREPackageTests.cpp:1217-1271`, `DefaultPipelinePublishesSourceBoundMandatoryRailKeysWithoutInjection`, checks no-injection A2a network publication and hard-key ownership; it never observes or asserts execution of `rail_interval_refs` with that network.
6. `tests/SurfaceCellsPhase10Tests.cpp:6298-6339` constructs a no-injection, retained-intermediate pipeline fixture with real source hard edges, and `:6608-6650` checks produced phase-front and mandatory keys. Its forged-key negative invokes `FieldAlignedCurveNetwork::make` directly, **not** the network-bound `rail_interval_refs` consumer. Separate direct `rail_interval_refs` tests validate predicate behavior but do not establish ordinary-pipeline call reachability.

**Conclusion:** There is a static producer-to-consumer call route, and valid authored source tests of publication and isolated negative checks. There is **no executed, non-vacuous default-path witness** establishing that a producer-built rail interval reached the *network-bound* typed check; the existing compiled tests are runtime-unexecuted. Claiming either an observed PASS or definitive consumer unreachability would exceed evidence. Under the frozen rule, record `RP-02 TEST_AUTHORITY_COVERAGE_GAP`, not a fabricated `source_edge_index` migration or a production edit.

## Required future evidence (separately authorized Test + Benchmark)

Use the existing genuine no-injection pipeline fixture. Record an observable nonzero count or a strict path-specific receipt at `assign_open_front_boundary_authority` that proves the network-bound `rail_interval_refs` call has returned `Valid` with nonempty producer-authored `sourceVertices` and `sourceEdges`, an actual `FieldAlignedCurveNetwork`, and matching mandatory rail identity. Also exercise an independently forged typed edge at this *consumer boundary* and require typed first rejection. The assertion must fail if the whole consumer is skipped; an A2a publication assertion, a call made explicitly by the test, a stage-injected run, and factory-only rejection are insufficient. Reuse existing production diagnostics or instrumentation when possible; do not add a no-op counter or weaken guards merely to obtain green status. Run only through the frozen immutable-artifact Test + Benchmark boundary and subsequent independent Review.

## Scope and continuation

Source-only audit and documentation. No changes to production source, test source, fixtures, workflow permissions, selected 497-case gate, ABI, recovery, historical ledger, or PR metadata. No build, executable, benchmark, TB497, or runtime execution was performed. Previous eight-target GMP/GMPXX compile evidence stays historical and is not reinterpreted as a runtime PASS. Ledger 66/17/49, debt 1; accepted CP2 491/491; rejected R3 403/497 (94 RED, 88 accepted losses), all unchanged.

`M6-CP3-CB1-R4-RA4712-LIVENESS` completes its *source-only determination* by recording the coverage gap. Wider R4 remains open. The separately authorized next rung is `M6-CP3-CB1-R4-RA466-SUBCODES`; do not begin it within this turn. RA-52/RA-53 dispositions and all carried runtime gates remain frozen.
