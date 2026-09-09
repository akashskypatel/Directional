# M3-CP4c-3-TB47 Independent Review Record

**Status:** COMPLETE / APPROVED WITH AMENDMENTS / PACKAGE112 PROMOTED / ORDINAL367 RECOVERY CLOSED / 5 CARRIED REDS / CB54 FROZEN
**Turn:** `M3-CP4c-3-TB47-REV`
**Boundary:** independent REVIEW + PLAN; evidence/static only; no Directional runtime or compile
**Date:** 2026-09-09
**Runtime evidence reviewed:** TB47 run/job `34397425632 / 102620523147`
**Immutable evidence source:** `c772b53f1c42e117a948f14f77a33ab3dd2619a2`, package112 artifact `10119861923`, selector409

## 1. Decision

**Decision: `approved_with_amendments`.**

TB47 is mechanically valid and is promoted as the current reviewed semantic runtime authority:

- **404 PASS / 5 RED / 0 SKIP**;
- accepted prefix **365/365 PASS**;
- RED `[368,369,370,374,398]`;
- all 409 selector identities executed exactly once in fresh processes;
- zero selection mismatches and zero timeouts;
- package/source/execution-view byte and mode censuses match before and after execution;
- no configure, compile, relink, generated discovery, repair, mutation, or benchmark path executed;
- ownership remains **300 established / 0 unavailable / 0 conflicting**.

The amendment is planning, not reinterpretation of the raw ledger: TB47-EXEC correctly preserved raw evidence and
refused self-promotion. This review closes ordinal367's non-stable recovery candidate, promotes package112/TB47, and
selects the already-defined AK5 empty-network product defect at ordinal370 as the smallest high-confidence next
Code + Build owner.

## 2. Primary evidence verification

The retained result artifact `10122211479` has SHA-256
`e5cc14813173e005a1c14fb6ce9e62d520a9d458de49ee931afe7b6177d56366`; the log artifact `10122212347` has SHA-256
`d40b560d85c0d8f203091bdadeead1a3eec8a85822f6851500ddde6efa9dddf0`.

Independent inspection confirms:

- `semantic-summary.txt`: `total=409`, `pass=404`, `red=5`, `red_ordinals=[368, 369, 370, 374, 398]`, accepted
  prefix `365/365`;
- `execution-boundary.txt`: runtime started/completed, preflight and execution-view verification true,
  `orchestration_failure=false`, `selection_integrity=true`, timeout count 0, and all prohibited build/repair/mutation
  flags false;
- execution ledger SHA-256 `093c4f009a800b56fe385e5129a1ee739fc1cb8b6534baa5fcc89896dadd1942`;
- failure-detail table SHA-256 `c761660aec3ee209c70299ba9d7d53cbb6dc97e04066c402f8a7b901bbbe830a`;
- resource summary SHA-256 `dc83db754b0c1ff3bd94416ce824c8c0ef8a2ade5b2b1d9fd96b8bbfd731cb26`.

No evidence gap prevents semantic adjudication.

## 3. Ordinal367 — correction is runtime-proved and its candidate closes

Ordinal367 now PASSes after CB53 changed only the independent helper's retired two-sided owner-count equality to the
frozen high-side-only rule. Current failure details contain neither `FragmentCountRule` nor `FragmentPartition`.
Accepted/protected ordinal307 also remains PASS.

This is exactly the predicted behavior of DEFN-R3.4: local fragments may map many-to-one onto global face-walk
owners, so distinct global owner count is upper-bounded by `tracePieces + 1`; it is not required to equal that local
fragment count.

Therefore `M3-CP4c3-TB47-EXEC-CAND-01` is:

**CLOSED / RUNTIME-PROVED TEST-AUTHORITY CORRECTION RECOVERY / NON-STABLE / +0 EVENT / +0 RECURRENCE.**

The separately recorded ordinal307 equality remains a **latent accepted-prefix test-authority debt**. It did not
fire, is not changed by this review, and is not part of CB54. If it ever fires, its standing classification remains
oracle drift under DEFN-R3.4 rather than a product regression.

## 4. Protected Part XII evidence remains non-vacuous

Ordinals 390/393/406/407 remain PASS and execute through `PlanFrontier`. Their receipts preserve the real
producer-owned census predicate, the same-domain corruption negative, and non-empty supporting evidence:

- 390 publishes non-empty `m3Cp4c3BW3` rows;
- 393 publishes a non-empty owner map;
- 406 publishes non-empty partition correspondence;
- 407 publishes a non-empty interior-arc census (`interiorArcs=2`).

This confirms package112 did not recover ordinal367 by bypassing or vacating the protected frontier. No stable
repricing follows from these already-required protections remaining green.

## 5. Every remaining RED retains its established owner

The five REDs are not one failure class and must not be merged:

1. **368 — prescribed sphere / `M3-CP4c2-TB-X2-CAND-04`.** Still
   `RotationSystemInconsistent -> TraceEventPositionInvalid`, trace 2/event 30,
   `NoCarrierMatch / SourceEdgeUnavailable`. AL4 still blocks a sphere semantic fix at this level.
2. **369 — ordinary trace-crossed proposal / `M3-CP4c2-TB-X2-R10-CAND-01`.** Still observes
   `saturationUsed=true`. AK4's per-face-chord proposal correction remains a separate quality/coverage owner.
3. **370 — empty closed network / `M3-CP4c2-TB-X2-R8-CAND-02`.** Still returns
   `CellularityNotEstablished` (4), while the frozen contract requires `EmptyNetworkOnClosedSurface` (6) and a
   source-face locus. This is a genuine product red.
4. **374 — folded-cone / `M3-CP4c3-TB7-CAND-02`.** Still stops at `atlasBuild=false`. The fixture's flat-star field
   is invalid for its non-flat star; the known repair is test-only but remains deferred under its own owner.
5. **398 — prescribed-sphere owner-map surface.** Still lacks the cut graph because the same upstream sphere A2a'
   failure at 368 prevents it. It must not be repaired independently of 368.

No new stable regression event or recurrence is justified.

## 6. Why ordinal370 is the exact next Code + Build owner

The next step must be the smallest correction whose semantics are already decided and whose failing regression is
already in the gate.

- 368 is blocked by its finer-grain sphere diagnosis rule; 398 is downstream of 368.
- 374 is a separately owned invalid-fixture/precondition repair and remains deferred.
- 369 is actionable but is a broader proposal-quality correction; its certifier remains authority and the existing
  saturation fallback is explicit.
- 370 is a genuine product failure, DEFN-R1 AK5 already decided the behavior, the typed enum value is already
  appended without renumbering, and selector409 already contains the exact failing regression.

Static source review narrows the defect further. `SurfaceCutGraphErrorCode::EmptyNetworkOnClosedSurface = 6` and its
name mapping already exist, but `SurfaceCutGraph::canonical_candidate()` has **no early empty-network/closed-source
branch**. It proceeds into the actual-embedded-graph certifier and returns generic `CellularityNotEstablished`.
The helper `embedded_graph_topology_detail::source_boundary_loop_count()` already provides the exact closed-source
predicate used elsewhere. No test, fixture, selector, public enum, certificate, or heuristic change is required.

The simplest sufficient correction is therefore a surgical product-side early rejection in
`src/geometry/SurfaceCutGraph.cpp`, after source/atlas/network binding validation and before cut classification or
certification. It must recognize a truly empty network (`nodes`, `mandatory_edges`, and `candidate_traces` all
empty), establish the source is closed from the existing topology authority, and return
`EmptyNetworkOnClosedSurface` with a deterministic source-face locus. Malformed-source behavior remains fail-closed
as `NonManifoldSource` where the boundary-loop predicate cannot be established.

## 7. Success criteria for the successor

CB54 is runtime-free. Its semantic diff is exactly one product source file and must leave tests/selector409 bytes,
fixtures, error-code numbering, sphere/saturation/folded-cone owners, certifier semantics, and all protected gates
unchanged.

Compile verification must use the mandatory GMP/GMPXX reusable workflow on the exact pushed semantic source:

1. changed-owner pre-package compile of `directional_surface_cell_producer_tests`;
2. complete package compile of the durable eight-target set on the **same exact semantic source**;
3. clean source, recursive manifest verification, exact GMP backend evidence, and `runtimeExecution=false`.

If an immutable package113 is accepted, CB54 closeout freezes the next artifact-only selector409 plan. A later TB is
expected, but not assumed, to move only ordinal370 to PASS, yielding **405 PASS / 4 RED / 0 SKIP** with RED
`[368,369,374,398]`. Any accepted-prefix loss, protected-control loss, or different carried failure surface is a
new review question, not permission to weaken validation.

## 8. Promotion and accounting

Package112/TB47 supersedes TB46-R1/package111 as reviewed semantic runtime authority.

Stable accounting remains **47 events / 14 categories / 33 recurrences**; produced-witness debt remains **5**;
ownership remains **300/0/0**; accepted package count remains **112**. Package count advances only when a later
Code + Build accepts a new immutable package.

## 9. Mandatory REVIEW consolidation

This review folds the two live superseded TB46-R1 per-turn authorities:

| Folded document | Lines | Role |
|---|---:|---|
| `Architecture_M3_CP4c3_TB46_R1_EXEC_Report.md` | 186 | superseded runtime report — package111 403/6 |
| `Architecture_M3_CP4c3_TB46_R1_Independent_Review_Record.md` | 197 | superseded review authority — package111 promotion and CB53 freeze |

**Folded this review: 2 documents / 383 lines. Running total: 156 documents / 29,252 lines.**

Three documents were already retired between reviews by TB47-EXEC stale-evidence cleanup and are indexed
retrospectively, accounting-neutral:

- `Architecture_M3_CP4c3_CB53_Independent_Fragment_Count_Oracle_Code_Build_Plan.md` — 96 lines;
- `Architecture_M3_CP4c3_CB53_Independent_Fragment_Count_Oracle_Code_Build_Report.md` — 213 lines;
- `Architecture_M3_CP4c3_TB47_Artifact_Only_Test_Benchmark_Plan.md` — 196 lines.

Retained current per-turn authorities after consolidation are exactly the TB47 EXEC report, this review record, and
the single CB54 plan, together with frozen definitions, selectors and durable family records.

## 10. Process/conservation note

The turn initially read the handoff before making the mandatory explicit `READ_MODE` choice. That was a
`TOOL_USE_CONSERVATION_POLICY.md` start-of-turn miss. Piecemeal repository inspection stopped immediately, the turn
switched to `READ_MODE=snapshot`, and all substantive static review then used one exact verified source snapshot.
The miss affected efficiency only; source/evidence authority and the review boundary were not weakened.

## 11. Exact successor

**`M3-CP4c-3-CB54` — Code + Build / runtime-free**, under
`Architecture_M3_CP4c3_CB54_Empty_Network_Typed_Rejection_Code_Build_Plan.md`.

No Directional runtime, compile, implementation mutation, or test mutation was executed in this review.
