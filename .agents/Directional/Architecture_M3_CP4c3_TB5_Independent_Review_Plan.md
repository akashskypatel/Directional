# M3-CP4c-3-TB5 Independent Review + Plan — Frozen Scope

**Turn:** `M3-CP4c-3-TB5-REV`
**Type:** independent REVIEW + PLAN only.
**Runtime/build boundary:** no Directional runtime, compile, link, package, benchmark, product/test/fixture/selector mutation, or acceptance attempt.

## 1. Authority to review

Review the exact TB5 semantic authority only:

- semantic source `49536cf7b4b261bd52f36a91c861b6459db356a4`;
- immutable package 74 artifact `9778267541`;
- TB5 run/job `33448925069 / 99674216849`;
- TB5 result artifact `9779114492`, SHA-256 `a4d9239e7eee452b6b0e053577ad18126d37b5d5cc2a6a1225c1deefd660ca55`;
- selector 373 SHA-256 `b47c269851fad1384b5dc9baaf674b3d4ad80ec6c2b40f7f8eda2055c6f44834`.

TB5 re-proved ordinals 1–365 and first-red ordinal 366 at source vertex 11 / face `(8,10,11)` / branch 1 /
`FaceInterior`, with `publishedFaceCount=0`, `barrierAbsorbed=false`, `barrierIncident=false`, and **no serialized
`vertexTransitState` records**.

## 2. Mandatory review questions

### AT0 — Re-establish immutable evidence

Independently verify package/source/selector identity and TB5 pre/postflight before interpreting the red. Treat the
two earlier control-plane attempts as non-semantic: `33448461852` had zero jobs; `33448694360` stopped pre-runtime.

### AT1 — Reconstruct the vertex-11 transit path from source and fixture

For source vertex 11 and arrival face `(8,10,11)` / branch 1, reconstruct the full incident fan, barrier incidence,
branch transports, current pairing, arrival incoming datum, and every reachable state that the corrected resolver
*should* visit. Do not infer from the TB4 vertex-30 fan.

### AT2 — Explain the empty diagnostic vector

Enumerate every path in the CB6 `resolve_field_vertex_transit` implementation that can return
`VertexTransitSectorUnresolved` with `vertexTransitStates.empty()`. For each, state the exact condition and test it
against the vertex-11 fixture/source authority. In particular distinguish failures before pending-state creation,
frame/pairing/row lookup failures, world-direction construction failure, exact face re-expression failure, and a
genuine visited fan with zero sector candidates. Do not promote a cause until one path is proved.

### AT3 — Adjudicate Amendment 17, do not assume it passed

Determine whether the old TB4 vertex-30 two-candidate defect is actually removed by the one-datum transport or is
merely no longer reached because vertex 11 fails first. Static proof may establish the former; otherwise freeze a
measurement that can distinguish the two without weakening first-red gate semantics.

### AT4 — Reconcile topology semantics

Classify vertex 11 (regular/singular, interior/boundary in source and cut transport domain), its relationship to the
published singularity at source vertex 10, and whether any barrier/truncation rule legitimately permits zero
continuations for this `FaceInterior` arrival. Preserve Amendments 12–17 and the exact half-open sector predicate
unless source proof shows a normative contradiction.

### AT5 — Dispose report-only diagnostics without widening product scope

- Sphere 368: record `NoCarrierMatch / SourceEdgeUnavailable` as runtime-proved localization. **AL4 remains binding;
  no sphere fix design in this review unless a higher authority explicitly reopens it.**
- Ordinal 369: retain `saturationUsed=true` as the active deferred quality/coverage finding.
- Ordinal 370: classify the synthetic torus `make_zero_transport_field` precondition as invalid for the atlas because
  runtime now reports `NonIntegralCycleLift;topologyRegion=0`; do not repair the witness in this review. The intended
  empty-network A2a′ product contract remains unmeasured.
- Ordinals 371/372: preserve as upstream-blocked, not falsified.
- Ordinal 373: preserve synthetic-only partial credit; mechanical zero-unbound evidence remains owed.

### AT6 — Audit the CB6 assumption surface

Revisit AS5's same-pattern site in singularity-port incidence construction only after AT1–AT4 establish whether it
shares the new failure mechanism. Name any other consumer that elects among cells using per-cell representations of
one semantic datum. Audit only; no implementation edit.

### AT7 — Freeze one bounded successor

Issue one falsifiable Code + Build plan only after the cause is proved. The plan must name the exact source owner,
forbidden alternatives, expected ordinal-366 discriminator, compile targets, and the next immutable artifact-only TB
contract. If evidence is insufficient, freeze a diagnostic-only CB rather than guessing a semantic correction.

## 3. Prohibitions

No forced first/ordered candidate selection; no tolerance added to exact sector predicates; no barrier widening; no
`FaceInterior` exclusion change; no enum renumber/removal; no selector mutation; no sphere semantic correction; no
witness repair for ordinal 370; no reopening accepted CP4c-2 contracts without proof.

## 4. Required durable outputs

Update `ORIENTATION.md` as required for every REVIEW turn, record the adjudication in the regression tracker and
consolidated CP4c record, and freeze exactly one successor plan. Stable-count changes require evidence of lost
accepted-green behavior; TB5 itself provides none.
