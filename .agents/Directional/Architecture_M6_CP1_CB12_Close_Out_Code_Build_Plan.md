# `M6-CP1-CB12-CLOSE` — CP1 Close-Out Code + Build Plan

> **Review-agent block — `M6-CP1-CB12-CLOSE-REV` (RA-26), 2026-10-05.**
> - The CB12 C5 stop is **discharged**. This plan is now executed by the new turn **`M6-CP1-CB12-CLOSE-R1`**.
> - **C1–C4, identities 29/30, focused-30, compile/package and the 479 successor are unchanged.**
> - **C5 is complete.** The binding classification is `Architecture_M6_CP1_CB12_Close_Stop_Review_Record.md` §3 (RA-26 §3). The R1 report cites it and does no further C5 work.
> - The C5 table below had wrong optimizer anchors. `:3020` is the test-only overlay; the real source-point rebinding is `project_vertices` (`SurfaceMeshOptimizer.cpp:759-:880`).
> - **Forbidden in R1:** any change to `SurfaceMeshOptimizer` or final validation. Anchor-dependent references are re-homed to `M6-DEFN-R5` / `M6-CP3` (RA-26 §5).
> - The C5 stop rule is replaced by RA-26 §2: only an *authority-deciding* consumer stops a turn.

**Owner:** `M6-CP1-CB12-CLOSE`
**Type:** Code + Build only; compile/package; runtime forbidden.
**Authority:**
- `Architecture_M6_CP1_TB11_G4_R1_Review_Record.md`, review-agent addendum §N2–§N3;
- frozen definitions RA-19a §3, RA-22a §3, RA-22b §5, RA-24 and **RA-25**.

**Entering runtime:** `11316716869 / 8dd958217d8cbda2d403f7a5c4c7dce242dde1c0`, focused-28 + selector449 = **477/477**.

**Successor:**
1. compile-green → `M6-CP1-TB12-CLOSE-EXEC`, **focused-30 + selector449 = 479**;
2. mandatory `M6-CP1-TB12-CLOSE-REV`;
3. `M6-CP1-CLOSE-REV`, a pure verification of the six CP1 exit items on that fresh gate.

## Goals (exactly these; nothing else)

### C1 — exact A7 cross-sheet certification (RA-22a §3)

In `SourceAttachedGeometryProducer::produce`, replace the proxy (`RemeshPipeline.cpp` ~6850-6872).

**Today.** A selected-forest edge whose endpoints share no wedge sheet is accepted if *any* isolation evidence exists on the relation, or any `cornerWedgeIsolation` exists on either occurrence.

**Required.** Let `S1` and `S2` be the endpoints' `cornerWedgeSheets`. The crossing is certified only if there is a `CornerWedgeIsolationTransition t` such that:
- `t` comes from the relation's `firstSideIsolationEvidence`, `secondSideIsolationEvidence` or `equivalence.isolationTransitions`, or from either occurrence's `cornerWedgeIsolation`; and
- either `t.fromSheet ∈ S1` and `t.toSheet ∈ S2`, or `t.fromSheet ∈ S2` and `t.toSheet ∈ S1`.

Otherwise fail `UncertifiedCrossSheetBinding` (`:cross-sheet`). `relationEvidenceSufficient` must now mean exactly this.

**Stop for Review** if this rejects any row that was accepted before.

### C2 — distinct A5 phase-front source diagnostics (RA-19a §3)

Restore three distinct causes, kept apart through to the legacy names:
- **empty phase front** — `cells().empty()` or `edges().empty()` → legacy `MissingAuthoritativePhaseFront`;
- **source shape or face-count mismatch** → legacy `InvalidAuthoritativePhaseFrontSource`;
- **chart-transition unavailability** → legacy `InvalidAuthoritativeSourceChartTransitions`.

Use new `SurfaceOccurrenceComplexErrorCode` values or site tokens, with predicates and order unchanged.

**Empty edges.** A5 previously failed only on empty *cells*. The pre-CB10 adapter also failed on empty *edges*, so restore that predicate as the first A5 check. It is fail-closed either way; this restores the original name.

### C3 — counter from A5-validated authority

`AuthoritativePhaseFrontMeshResult::consumedInternalIsolationSeams` must come from A5's **validated** isolation-certificate set, not from `phaseFront.isolationSeamTransportCertificates().size()`. Do this by exposing a count on the published `SurfaceOccurrenceComplex` certificate, set by the moved bijection check.

Update identity 24's expectation to read that A5 value.

### C4 — RA-24 continuation fails closed (RA-25)

In `build_surface_quotient_closed_complex_view`: at an interior valence-4 quotient vertex, if an incident edge has zero, or more than one, incident edges sharing no classed quad with it, return a new A6 error `ClosedComplexStripContinuationMismatch`. Do not skip silently. Everything else stays unchanged.

### C5 — provenance-face consumer audit (RA-22b §5; static; recorded in the CB12 report)

Classify each consumer that reads a `sourcePoint` or `vertexProvenance` **face** as **class-wide**, **representation-only** or **anchor-assuming**, with a `file:line` justification:

| Consumer | Location | Status |
|---|---|---|
| `project_surface_cell_vertex_chart_authority` | `RemeshPipeline.cpp:8061-8127` | Pre-audited: class-wide (uses `lineage.sourceCharts`) |
| `SourceAuthoritativeMeshValidator` `resolve_compatible_chart` / face-chart checks | `SourceAuthoritativeMeshValidator.cpp:1190-1262` | To classify |
| `SurfaceMeshOptimizer` source-point rebinding | `:2576`, `:3020` | To classify |
| `BenchmarkQuality` field alignment | `:1490-1503` | To classify |

**Stop for Review** if any consumer is anchor-assuming. Do not fix it inside CB12.

### Tests (append after focused 1-28; create focused-30 with focused-28 as its exact prefix)

**29 — `M6CP1.A7CrossSheetBindingRequiresConnectingIsolationTransition`.**
- Positive: a multi-sheet class on an existing split-isolation fixture is accepted.
- Negative: rewrite the relevant transitions' `fromSheet`/`toSheet` to a sheet pair that does not connect the endpoints. A7 must reject with `UncertifiedCrossSheetBinding` and site `cross-sheet`. The C1 rule rejects this case and the old proxy accepted it.

**30 — `M6CP1.A5PhaseFrontSourceFailuresKeepDistinctDiagnostics`.** Three tampers, each producing the exact distinct A5 code and the adapter legacy name:
- empty edges;
- face-count mismatch;
- unavailable chart transitions — use a source-topology authority mismatch if it is reachable; otherwise document unreachability and assert the other two.

**Identity 24** expectation update (C3) only. No other existing test body changes.

## Static checks and gate

- `git diff --check`.
- selector449, routing449 and the focused-12/20/24/28 bytes are unchanged.
- No change to A5/A6/A7 semantics beyond C1–C4, and no tolerance change.
- Compile with the mandatory reusable GMP/GMPXX workflow, standard eight targets, `runtimeExecution=false`.
- TB12: **30 + 449 = 479** fresh exact-filter processes.

## Stop rules

Stop for Review if:
- C1 rejects a previously accepted fixture;
- C5 finds an anchor-assuming consumer;
- C2 cannot keep predicates unchanged;
- any goal requires changing quotient membership, support, relation or transport semantics, or the RA-24 strip rule beyond fail-closed.
