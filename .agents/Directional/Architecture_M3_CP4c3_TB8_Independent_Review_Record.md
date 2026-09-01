# M3-CP4c-3-TB8 — Independent Review + Plan Record

**Turn:** `M3-CP4c-3-TB8-REV`
**Date:** 2026-09-01 UTC
**Type:** independent REVIEW + PLAN. Static only — no Directional runtime, compile, link, package, benchmark, or
product/test/fixture/selector mutation occurred in this turn.
**Governing plan:** `Architecture_M3_CP4c3_TB8_Independent_Review_Plan.md`, measures **BA0–BA7**.
**Verdict:** TB8 is a **valid semantic red**. The ordinal-366 first red is classified **BA2 category 3 —
diagnostic insufficiency** — over a **proved two-element** candidate set. Exactly one bounded successor is frozen:
**`M3-CP4c-3-CB11`**, diagnostic-only, under **BB0–BB9**.

---

## 1. Executive adjudication

TB8 re-proved accepted authority **365/365** and moved the mechanical production path past the TB7 source-vertex-11
`VertexTransitSeedUnavailable` stop. The new first red at ordinal 366 is

```
NotProductionReady/field-aligned-network;detailCode=InvalidNetworkTerminalOwnership
  ;sourceEdge=36-38;sourceFace=36,38,39;branch=2;publishedFaceCount=0
```

Three results decide this turn.

1. **The locus is reconstructible only down to two emission sites, not one.** `InvalidNetworkTerminalOwnership` has
   **twelve** emission sites in `src/geometry/SurfaceCellTracing.cpp`. Ten are eliminated by proof (§3). The two
   survivors — `:1900` (singularity-termination port ownership) and `:3920` (the `finalize_field_aligned_events`
   fall-through) — emit the **identical rendered locus**. Nothing in the serialized line separates them.

2. **The separation exists in the product and is discarded at the pipeline boundary.**
   `FieldAlignedCurveNetworkError` carries `traceSeedVertex`, `traceSeedSingularity`, `traceHistory`, `traceSteps`,
   `traceStepBudget`, `traceCombinatorialVisits`, `traceCombinatorialVisitAllowance`, `singularity`, `rail`,
   `relatedSourceFace`, `relatedBranch`, `signedLift`, `parameter`, `exactValues` and `publishedEdges`.
   `SurfaceCellFailureLocusDiagnostics` declares a field for **none of them**. The complete reader set for the
   trace-scoped group is `tests/FieldAlignedCurveNetworkTests.cpp:4808-4834` — the **test-local** renderer
   `network_error_locus` — plus direct assertions in ordinals 328/329. There are **zero readers in
   `src/pipeline/RemeshPipeline.cpp`**. Ordinal 366 is a CP4c production identity and reports through
   `append_cp4c_failure_locus`, which can only render what the projection carried.

3. **The guarantee that should have caught this is enforced on the wrong renderer.** Accepted-green ordinal **329**,
   `ResolvedBranchCorrection.NetworkDiagnosticsPublishEveryRequiredLocusLosslessly`, constructs
   `FieldAlignedCurveNetworkError` values by hand and asserts tokens against `network_error_locus`
   (`tests/FieldAlignedCurveNetworkTests.cpp:9127+`). It never touches `network_failure_locus`,
   `SurfaceCellFailureLocusDiagnostics`, or `append_cp4c_failure_locus`. The losslessness claim in its name holds
   for a path that the production witnesses do not use.

Because the correct product semantics for the two survivors are **different corrections with different owners**,
prescribing a fix now would be guessing. BA2's own clause applies: *"If diagnostics are insufficient, freeze a
diagnostic-only successor rather than guessing at semantics."*

---

## 2. BA0 — immutable evidence re-established

All checks below were recomputed in this turn from committed bytes. No build product or rebuilt binary was used.

| Datum | Declared | Verified |
|---|---|---|
| semantic source | `e2b59295c9920db5685239c2da188858839fa94f` | commit exists, `M3-CP4c-3-CB10: fix radial witness compile reference`, 2026-09-01 20:37:46 +0000, ancestor of branch HEAD — verified |
| gating selector 374 | `d496ce96…c503c4f` | SHA-256 of the LF blob of `Architecture_M3_CP4c3_Required_Green_Selector_374.txt` = `d496ce96b3776269cda8086a0a2173ce9a1f9967d81b2a80866266155c503c4f` — match |
| diagnostic selector 375 | `aa7b22bb…06a8f3a0` | LF blob SHA-256 = `aa7b22bb265f321fad6f85128e572e0251dc5f60d68856ca7ec4323006a8f3a0` — match |
| selector 374 line count | 374 identities | 374 — match |
| selector 375 line count | 375 identities | 375 — match |
| ordinal 366 identity | `GlobalTopologyPlan.MechanicalFeatureWitnessDerivesRegionsThroughProductionEntryPath` | line 366 of selector 375 — match |
| ordinals 367–374 | as tabled in the TB8 report | all eight match line-for-line |
| diagnostic 375 identity | `ResolvedBranchCorrection.FaceInteriorRadialArrivalsAdmitBothClosedWedgeBoundaries` | line 375 — match |

Four further BA0 results, none of which the TB8 report asserts:

- **375 is a strict one-line extension of 374.** The diff of the two files is exactly `374a375 >
  ResolvedBranchCorrection.FaceInteriorRadialArrivalsAdmitBothClosedWedgeBoundaries`. CB10 appended and did not
  reorder, retitle, or remove. Selector 374 is byte-frozen.
- **Selector 374's hash is asserted identically in the CB9 report, the TB7 plan, the TB7 report, the TB7 review
  record, the CB10 report, the TB8 plan and the TB8 report.** Byte-frozen across five consecutive turns.
- **Accepted authority is an exact prefix.** The first 365 lines of selector 375 are byte-identical to
  `Architecture_M3_CP4c2_Required_Green_Selector_365.txt`. TB8's 365/365 is on the same accepted authority CP4c-2
  closed, not a re-derived list.
- **The semantic source equals branch HEAD on every code surface.** `git diff e2b5929 HEAD -- src include tests
  benchmarks CMakeLists.txt cmake` is empty. Therefore static review of the working tree in this turn is valid
  evidence about the contents of immutable package 78. This is what licenses §3–§5 below; it is not assumed, it is
  checked.

Preflight/postflight and the eleven false control flags are accepted as reported; this turn executes no runtime and
adds no independent evidence there.

---

## 3. BA1 — reconstruction of the terminal-ownership locus

### 3.1 What the rendered line proves by absence

`append_cp4c_failure_locus` (`tests/FieldAlignedCurveNetworkTests.cpp:3421+`) emits in a fixed order:
`sourceVertex`, `sourceEdge`, `sourceFace`, `branch`, `topologyRegion`, `arrivalMode`, `publishedFaceCount`,
`publishedFaces`, `barrier*`, `transportStarComponentCount`, `vertexTransitState[…]`, `vertexStar*`.

The observed line therefore proves, not merely suggests, that on the emitted error:

- `sourceVertex` is `std::nullopt` — it would have printed **before** `sourceEdge`;
- `topologyRegion` is `std::nullopt` and `vertexArrivalMode` is `std::nullopt` — both print **between** `branch` and
  `publishedFaceCount`;
- `vertexTransitStates` is empty and `vertexStarTransit` is `std::nullopt` — no vertex-star transit was involved.

The last point is independently important: **the ordinal-366 failure is not a vertex-star transit failure at all.**
It is a terminal-ownership failure at the network-assembly stage.

`publishedFaceCount=0` carries **no** information. `FieldAlignedCurveNetworkError::publishedFaces`
(`include/directional/geometry/SurfaceCellTracing.h:311`) is **declared and never assigned anywhere in `src/` or
`include/`**. Every network-stage error renders `publishedFaceCount=0` by construction. It must not be read as
evidence of an empty network.

### 3.2 The mechanical geometry at the locus

Computed directly from `benchmarks/fixtures/milestone-g/mechanical_feature.obj`:

- 152 V / 300 F, **0 boundary edges**, `V − E + F = 2` — a closed genus-0 witness.
- **Face row 51 is exactly `(36,38,39)`**; the canonical sorted key coincides with the mesh row order here.
- Edge `36-38` is **interior**, shared by rows **50 `(36,37,38)`** and **51 `(36,38,39)`**.
- v36 `(-1.4, -0.78, -0.9)`, v37 `(-1.4, -0.7385410196624969, -0.54)`, v38 `(-1.4, -0.432, -0.54)`,
  v39 `(-1.4, -0.432, -0.9)` — all four lie in the plane `x = -1.4`.
- Rows 50 and 51 have **identical unit normals `(-1, 0, 0)`**; the dihedral angle at edge `36-38` is
  **0.000000000°**. The `x = -1.4` plane carries a **50-face coplanar patch**.

Both locus renderers use canonical keys (`face.vertices()`, `edge.first()/second()`), so `36,38,39` and `36-38` are
sorted sets and no mesh-row corner order may be inferred from them.

For orientation: vertex 11 — the TB7 stop — is at `(1.4, 0.72, -0.54)`. The new locus is on the **opposite face** of
the part at `x = -1.4`. The new red is not a displaced continuation of the vertex-11 stop; it is a different region
of the same witness, now reachable because the earlier abort is gone.

### 3.3 Elimination of ten of the twelve emission sites

| Site | Locus fields it can set | Disposition |
|---|---|---|
| `:1875` | face+branch **or** edge, never all three | **Eliminated.** Both callers (`:3664`, `:3865`) enter only when `trace.terminalSingularity.has_value()`, so this guard can fire only on `!terminalPoint` (no `sourceEdge` set) or `segments.empty()` (no face/branch set). It cannot produce the observed three-field shape. |
| `:3122` | none | **Eliminated** — seed annotation only. |
| `:3276` | none | **Eliminated.** |
| `:3295` | none | **Eliminated.** |
| `:3317` | `sourceFace` only | **Eliminated** — no `sourceEdge`, no `branch`. |
| `:3609` | `sourceFace` only | **Eliminated.** |
| `:3635` | none (`field_aligned_error`) | **Eliminated.** |
| `:3706` | none | **Eliminated** — the `terminalKinds != 1` sweep sets no locus fields. |
| `:3132` | edge+face+branch | **Eliminated by fixture bytes** — see below. |
| `:3879` | edge+face+branch | **Eliminated by fixture bytes** — see below. |
| **`:1900`** | edge+face+branch | **SURVIVES.** |
| **`:3920`** | edge+face+branch | **SURVIVES.** |

**Why `:3132` and `:3879` are impossible here.** Both set `sourceEdge = *trace.terminalBarrier`, so the emitted edge
must be an edge the tracer terminated on as a **barrier**. Barrier edges are derived in
`src/authority/FieldTransportAtlas.cpp:955-966` strictly as a subset of `hardFeatureEdges`, and
`candidate.mandatoryEdges` (`src/geometry/SurfaceCellTracing.cpp:4204-4250`) are built only from hard-rail-supported
edges. Edge `36-38` has an **exactly zero dihedral angle** in the interior of a 50-face coplanar patch. It is not a
hard feature edge under any positive sharp-feature threshold, so it can never become a `terminalBarrier`. Both sites
are excluded.

### 3.4 The two survivors

**Site A — `SurfaceCellTracing.cpp:1900`, `append_field_aligned_singularity_termination`, port-ownership guard.**
Fires when the trace claims a terminal singularity but *(i)* the terminal point's `source_support()` is not a
`SourceVertexSupport`, *or (ii)* no entry of `candidate.singularityPorts` matches `*trace.terminalSingularity`,
*or (iii)* the matched port's `sourceVertex` differs from the support vertex. It emits
`sourceEdge = trace.terminalPoint->edge`, `sourceFace = trace.segments.back().sourceFace`,
`branch = trace.segments.back().branch`, and `sourceVertex = std::nullopt`. Disjunct *(ii)* is the semantically
live one on this witness: a singularity whose `portPolicy` is `BarrierAbsorbed` contributes **no ports**, so a trace
that legitimately terminates on it finds no owner.

**Site B — `SurfaceCellTracing.cpp:3920`, the `finalize_field_aligned_events` fall-through.** It emits
`sourceEdge = last.outgoingCarrier`, `sourceFace = last.sourceFace`, `branch = last.branch`, and
`sourceVertex = std::nullopt` — the same shape. Two structural facts make it live:

- **`terminalContact` is never read in `finalize_field_aligned_events`.** Enumerating every reference in the file:
  set at `:3285`, `:3303`, `:3333`; reset at `:3662`, `:3675`; counted at `:3703`; hashed at `:4434`; compared at
  `:4606`. **None** lies in `:3745-3935`. The `:3706` sweep guarantees each trace has exactly one terminal kind, and
  finalize branches on `terminalSingularity` (`:3864`) and `terminalBarrier` (`:3871`) only. A trace whose sole
  terminal kind is `terminalContact` therefore falls through to `:3908`, where it is adjudicated by a
  **loop-closure** rule (`closesOnEarlierState`) that belongs to a different terminal kind, and is rejected unless
  it happens to re-enter a face it already visited.
- **The pre-filter cannot catch trace 0.** `field_aligned_first_trace_contact` (`:2466`) compares trace `i` only
  against traces with index `< i`, so it always returns `nullopt` for trace index 0. A contact-terminated trace 0
  always reaches the fall-through. (Separately worth recording: that function declares a contact on **mere
  source-face coincidence**, with no crossing test — `field_aligned_segments_properly_cross` is computed only for
  the census, never for the decision.)

**The two survivors are not separable from the artifact.** They emit the same code, the same three populated fields,
and the same three absent ones. The datum that separates them — which trace failed, from which port, after how many
steps, through which faces — exists on the error object and is destroyed at the projection.

---

## 4. BA2 — classification and ownership

**Classification: category 3 — diagnostic insufficiency — over a proved two-element candidate set.**

Category 1 (genuine product ownership defect on a valid witness) is **not excluded** — indeed at least one of the
two survivors is a product defect, and site B is a product defect on its face. Category 2 (invalid witness) is
**effectively excluded**: the mechanical witness is a closed manifold with `χ = 2`, the locus edge is an ordinary
interior edge of a coplanar patch, and no precondition of the network stage is violated by it. But BA2 requires the
classification to be **proved**, and choosing between site A and site B decides *which stage and which DTO owns the
invariant*:

- if site A, the owner is **singularity port ownership** — `FieldAlignedSingularityPort` / the `BarrierAbsorbed`
  port policy — and the correction is about which authority owns a terminal at a port-less singularity;
- if site B, the owner is **`finalize_field_aligned_events`** — a missing `terminalContact` branch — and the
  correction is about publishing a contact termination rather than testing it for loop closure.

These are different files, different invariants, and different falsifiers. Prescribing either now would be an
ordering guess, which the prohibitions forbid.

**Named diagnostic owner.** The stage that owns the defect is the pipeline projection
`src/pipeline/RemeshPipeline.cpp::network_failure_locus` together with the DTO
`include/directional/diagnostics/RemeshDiagnostics.h::SurfaceCellFailureLocusDiagnostics`. Required invariant, stated
positively: **every field of `FieldAlignedCurveNetworkError` that can discriminate two emission sites of the same
typed code must have a projected field and a rendered token on the path the CP4c production identities use.**

**A second, independent contributor.** `FieldAlignedCurveNetworkErrorCode::InvalidNetworkTerminalOwnership` names
**twelve distinct conditions**. CB10's AZ3 measure — *one typed name per condition* — was applied to the three
vertex-star seed conditions and to nothing else. Even a complete projection would leave this code ambiguous across
its own emission sites; the discriminator has to be carried explicitly.

**Constraint that binds the fix.** Accepted-green ordinal **328**
(`ResolvedBranchContinuation.RejectsUnresolvedRegularVertexSector`) asserts
`EXPECT_EQ(FieldAlignedCurveNetworkErrorCode::InvalidNetworkTerminalOwnership, constructedError->code)` at
`tests/FieldAlignedCurveNetworkTests.cpp:9408`. **Splitting the enum value would break an accepted identity.** The
discriminator must therefore be an **added field**, not a renamed code.

---

## 5. BA3 — separation from the CB10 corrections

**`M3-CP4c3-TB7-CAND-01` — CLOSED, closure CONFIRMED.** Ordinal 366 no longer emits `VertexTransitSeedUnavailable`
at source vertex 11 on the mechanical production path, and diagnostic 375 passes. Reviewing 375 directly
(`tests/FieldAlignedCurveNetworkTests.cpp:8995+`): it builds `make_four_triangle_fan` with
`make_planar_radial_arrival_field`, and for **both** radial arrival vertices — including the one the CB9 half-open
predicate rejected (`cb9HalfOpenAdmits = false`) — asserts a single expected owner face. That is precisely the AZ1/AZ2
falsifier the TB7 review demanded. The TB7 radial-arrival admissibility mechanism is closed.

**`M3-CP4c3-TB7-REV-CAND-01` — CLOSED, verdict CONFIRMED, evidentiary basis CORRECTED.** The candidate's third and
outermost defect was that the 26 `vertexStar*` fields had no reader. That is now **false**: CB10 added the reader to
`append_cp4c_failure_locus` (`tests/FieldAlignedCurveNetworkTests.cpp:3457-3530+`), which renders both the
`vertexTransitState[…]` rows and the `vertexStar*` group. The closure holds on that static evidence.

The TB8 report's *stated reason* does not hold and is corrected here. TB8 §4 cites gating identities **328/329** and
diagnostic **375** as "runtime evidence that … the repaired audit/projection consumer surface [is] reachable and
functioning." All three are **unit-level synthetic identities**:

- **328** calls `append_field_aligned_singularity_termination` directly on a hand-built trace and inspects the raw
  error object;
- **329** builds `FieldAlignedCurveNetworkError` values by hand and asserts tokens against the **test-local**
  `network_error_locus`;
- **375** drives `resolve_field_vertex_transit` on a four-triangle fan.

None of the three executes `network_failure_locus`, populates a `SurfaceCellFailureLocusDiagnostics`, or renders
through `append_cp4c_failure_locus`. **No identity in selector 375 exercises the production projection.** The only
runtime evidence TB8 provides about that projection is ordinal 366's own locus line — which is the evidence that it
is incomplete.

**Vertex 30 — no acceptance claimed.** The mechanical path does not reach vertex 30. `M3-CP4c3-TB6-CAND-01` stays
**ACTIVE**. Row 41 remains a prohibited result, not an observed one, and the frozen row-209/row-208 owner election is
runtime-unmeasured.

---

## 6. BA4 — independently owned report-only debt preserved

No evidence in this turn proves shared ownership with the ordinal-366 locus. All of the following are preserved
unchanged and are **not** combined into the successor:

- **368** — prescribed-sphere `RotationSystemInconsistent → TraceEventPositionInvalid`, trace 2 / event 30,
  `NoCarrierMatch / SourceEdgeUnavailable`, under **AL4**. Untouched.
- **369** — `certificate.saturationUsed=true`; quality/coverage candidate remains active.
- **370** — genuine product-contract red: `CellularityNotEstablished` where `EmptyNetworkOnClosedSurface` is
  required, source-face locus still absent. **No correction authorized.**
- **373** — synthetic-only PASS with zero gate credit; mechanical zero-unbound evidence still owed.
- **374** — pre-classified invalid folded-cone witness (`M3-CP4c3-TB7-CAND-02`). Its repeat is **not** counted as a
  new regression or review trigger, and no atlas invariant is weakened.
- **`M3-CP4c3-DEFN-R2-CAND-01`** — remains **ACTIVE**. Ordinal 374 still stops at `ASSERT_TRUE(atlasBuild)` before
  the non-flat exact-fallback/budget discriminator is reached.
- **367 / 371 / 372** — blocked by the ordinal-366 locus; they yield no independent conclusion and no separate
  candidate.

---

## 7. BA5 — regression and accounting reconciliation

`M3-CP4c3-TB8-CAND-01` is adjudicated: **cause classified (BA2 category 3), owner named (production diagnostic
projection + undiscriminated typed code), candidate set proved to be exactly two product sites.** It remains
**ACTIVE / GATING** and is re-owned to `M3-CP4c-3-CB11`.

One new candidate is opened:

- **`M3-CP4c3-TB8-REV-CAND-01`** — *the trace-scoped diagnostics of `FieldAlignedCurveNetworkError` have no
  production reader, and the identity that asserts losslessness tests the wrong renderer.* **ACTIVE / STATIC /
  NON-STABLE.** Owner: **BB1–BB5** of `M3-CP4c-3-CB11`.

Dispositions confirmed: `M3-CP4c3-TB7-CAND-01` **CLOSED**; `M3-CP4c3-TB7-REV-CAND-01` **CLOSED** (reason corrected
per §5); `M3-CP4c3-TB6-CAND-01` **ACTIVE**; `M3-CP4c3-DEFN-R2-CAND-01` **ACTIVE**; `M3-CP4c3-TB7-CAND-02`
**ACTIVE / DEFERRED**.

**Accounting.** Ordinals 1–365 remain green; TB8 loses no accepted behaviour and this review executes nothing.
**+0 stable events / +0 stable recurrences.** Totals remain **44 events / 14 categories / 30 recurrences**,
produced-witness debt **5**, semantic M3 packages **75**.

A **non-stable pattern recurrence** is recorded for the tracker and `LESSONS.md`, not for the stable count: this is
the **fourth** consecutive turn in which a measurement was produced and then discarded at a stage boundary
(AS1, AU1/AU3, AY7, and now the trace-scoped group). Each previous fix corrected the *instance* that turn's red
exposed. AZ5 required the consumer set to be found "by search against a predicate" — it was, for the fields AY7
named, and the trace-scoped fields were not in that set.

---

## 8. BA6 — the single frozen successor: `M3-CP4c-3-CB11`

**Type:** Code + Build. **Diagnostic-only.** No product decision, no election, no tolerance, and no change to which
traces succeed or fail may be introduced. **Owner:** the production diagnostic projection and the typed-code
discriminator identified in §4.

### BB0 — preconditions
Branch `agent/surface_cell_quad/p5-recover-bridge-healing`. Accepted 365 identities untouched. **Selector 374 stays
byte-frozen at `d496ce96…c503c4f`** and selector 375 at `aa7b22bb…06a8f3a0`; neither may be reordered or edited.
**GMP/GMPXX linkage is mandatory for every compile** (`GMP_COMPILE_POLICY.md`). No runtime gate is claimed by CB11.

### BB1 — carry the trace-scoped discriminators to the production path
Add to `SurfaceCellFailureLocusDiagnostics` and populate in `network_failure_locus`: `traceSeedVertex`,
`traceSeedSingularity`, `singularity`, `traceSteps`, `traceStepBudget`, `traceCombinatorialVisits`,
`traceCombinatorialVisitAllowance`, `relatedSourceFace`, `relatedBranch`, and a **bounded** `traceHistory`
projection (face / branch / incoming carrier / exact entry parameter per step, with a published step cap and an
explicit truncation marker, mirroring `kPublishedFailureFaceLimit`). Render every one in
`append_cp4c_failure_locus`. Exact values stay exact reduced strings; **no float may enter the locus.**

### BB2 — discriminate the twelve emission sites without touching the enum
`FieldAlignedCurveNetworkErrorCode::InvalidNetworkTerminalOwnership` **must keep its name and value** — accepted
ordinal 328 asserts it (`tests/FieldAlignedCurveNetworkTests.cpp:9408`). Add a **separate typed condition
discriminator** on `FieldAlignedCurveNetworkError`, set at **every** one of the twelve emission sites to a distinct
value, projected and rendered. Report the count of distinct values at each setting site. Apply the same discipline
to any other error code with more than one emission condition that the search in BB4 surfaces.

### BB3 — make `publishedFaces` honest
`FieldAlignedCurveNetworkError::publishedFaces` is declared and never assigned. Either populate it at the network
stage with the faces actually published before the failure, or remove it and stop rendering
`publishedFaceCount` for network-stage errors. **Do not leave a field that renders a constant.** State which was
chosen and why.

### BB4 — find the consumers by search, and fix the guarantee that missed them
Enumerate the readers of `FieldAlignedCurveNetworkError` by **search against a predicate** — every field of the
error struct that has no corresponding projected field — not by copying BB1's list. Name at least one field the
measure did not name. Then **extend ordinal 329 (or add a companion identity) so the losslessness guarantee is
asserted against `network_failure_locus` → `SurfaceCellFailureLocusDiagnostics` → `append_cp4c_failure_locus`**, the
path the production identities actually use. Ordinal 329's current unit-level assertions must continue to pass
unchanged. Closes `M3-CP4c3-TB8-REV-CAND-01`.

### BB5 — demonstrate reachability
For each of the two surviving sites (`:1900`, `:3920`) construct a unit witness that reaches it and shows the new
discriminator and the trace-scoped fields rendered through the **production** renderer. Reachability of the other ten
sites need not be demonstrated, but each must be shown to set a distinct discriminator value by inspection.

### BB6 — selector treatment
Append **selector 376** = selector 375 + the new diagnostic identities, **only** on demonstrated falsification (each
new identity must fail before the change and pass after). Selectors 374 and 375 are byte-frozen and must be
republished with unchanged SHA-256. No reordering of any existing ordinal.

### BB7 — prohibitions
No change to any tracing, election, ownership, or termination decision. No change to
`field_aligned_first_trace_contact`, `finalize_field_aligned_events` control flow, port policy, or barrier
derivation — **including the `terminalContact` fall-through, which CB11 must diagnose and must not repair.** No
renaming or renumbering of `FieldAlignedCurveNetworkErrorCode`. No fixture mutation. No tolerance and no
float-derived topological value. No sphere, ordinal-370, saturation, or folded-cone correction. No acceptance claim
from CB11.

### BB8 — audit by assumption
For each of BB1–BB6, state the assumption it rests on and the evidence that falsifies the nearest alternative, in the
CB11 report. At minimum, prove that no accepted-green identity's observable output changes — the discriminator is
additive, and ordinal 328's assertion is on `code`, not on the new field.

### BB9 — published discriminators expected from the next artifact-only TB
`M3-CP4c-3-TB9` runs **selector 376 from ordinal 1**, artifact-only, on a fresh immutable package. Publish these five
in advance:

1. ordinals 1–365 remain **365/365** — additive diagnostics lose no accepted behaviour;
2. ordinal 366 still reds at `InvalidNetworkTerminalOwnership`, at the **same** `sourceEdge=36-38;sourceFace=36,38,39;branch=2`;
3. its locus now names **exactly one** of the two conditions — the site-A port-ownership discriminator or the site-B
   contact fall-through discriminator — and that value is the input to the next review;
4. the same line carries `traceSeedVertex` / `traceSeedSingularity` and a bounded `traceHistory`, naming the port the
   failing trace came from;
5. `publishedFaceCount` is either populated or gone; if populated and still `0`, that is now a real observation.

**No product correction is authorized until TB9 names the site.** The successor after TB9 is an independent
`M3-CP4c-3-TB9-REV`, which will own the category-1 product correction for whichever site is named.

---

## 9. BA7 — assumption audit

| Measure | Assumption | Evidence falsifying the nearest alternative |
|---|---|---|
| §2 | Static review of the working tree describes package 78. | `git diff e2b5929 HEAD -- src include tests benchmarks CMakeLists.txt cmake` is empty. The alternative — drift since the package — is directly excluded. |
| §3.1 | Absent tokens mean absent optionals, not a truncated report. | The renderer's field order is fixed and `sourceVertex` precedes `sourceEdge`; a truncated tail could not remove a leading token. |
| §3.3 | `36-38` cannot be a `terminalBarrier`. | Its dihedral is exactly 0° between two identical-normal faces inside a 50-face coplanar patch; `barrierEdges ⊆ hardFeatureEdges` (`FieldTransportAtlas.cpp:955-966`). The alternative — a flat edge admitted as a hard feature — contradicts the derivation. |
| §3.4 | Site B is reachable. | `terminalContact` has no reader in `:3745-3935` (all nine references enumerated), and `first_trace_contact` structurally cannot match trace index 0. The alternative — the fall-through is dead — is excluded by each fact independently. |
| §4 | Diagnostics, not semantics, are the blocking unknown. | Two live sites emit identical rendered output; the separating fields exist on the DTO and have zero readers in `RemeshPipeline.cpp`. |
| **BB2** | **Positive case:** the code must survive the change. | Ordinal 328 (`:9408`) asserts `code == InvalidNetworkTerminalOwnership` **and** asserts `traceSeedVertex`/`traceSeedSingularity` round-trip (`:9410-9412`), and it passes in the 365-prefix. A discriminator field preserves both; an enum split breaks the first. |
| **BB4** | **Boundary case:** the losslessness guarantee is real but misaimed. | Ordinal 329 (`:9127+`) asserts only against `network_error_locus`; extending it to the production renderer must be falsified first — it must fail before BB1 lands. |
| BB9 | Ordinal 366 will red again at the same locus. | CB11 changes no decision. If the locus moves, CB11 violated BB7 and the turn is invalid. |

---

## 10. Lessons

- **77r (recurrence, different DTO).** A datum that exists on the producer and is unit-tested there is not delivered
  until the **renderer the failing witness actually uses** prints it. Four consecutive turns have now lost a
  measurement at a stage boundary, each one layer further out. The authoring control that keeps failing is scoping
  the consumer search to *the fields this turn added* rather than to *every field of the DTO that has no reader*.
- **78 (new).** *An identity that asserts a guarantee must exercise the path the guarantee is claimed for.*
  `NetworkDiagnosticsPublishEveryRequiredLocusLosslessly` passes and has always passed, while the production
  projection silently drops fifteen fields — because the identity renders through a test-local function. The name
  of a guarantee is not its scope; its call graph is.
- **79 (new).** *One typed name over twelve emission conditions is an untyped failure.* Splitting a name is not
  always available — an accepted identity may assert the name — so the discriminator belongs in a **field**, added
  additively, rather than in the enum. This generalizes AZ3 from the vertex-star seed to every multi-site code.
- **Standing.** A field that is declared and never assigned (`publishedFaces`) renders a constant that reads as an
  observation. Dead diagnostic fields are worse than missing ones.

---

**End of record.** This turn executed no runtime, no compile, no package, and mutated no product, test, fixture, or
selector byte. The exact next turn is **`M3-CP4c-3-CB11`** under **BB0–BB9**.
