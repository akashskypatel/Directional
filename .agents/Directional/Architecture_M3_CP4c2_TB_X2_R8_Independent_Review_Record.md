# M3-CP4c-2 TB-X2-R8 Independent Review Record

## Status

**REVIEW COMPLETE / R8 RED ACCEPTED AS A WITNESS DEFECT, NOT A PRODUCT DEFECT / SCOPE BOUNDED TO ORDINALS 359 AND
361 / CORRECTIVE `M3-CP4c-2-CB8` AUTHORIZED UNDER AH0–AH9**

This record adjudicates `M3-CP4c-2-TB-X2-R8-EXEC` (run/job `33288495471 / 99195869180`, immutable package
`9724864897`, semantic product/test source `4f0f3ca74a88ba260a20c019437bc4995f2056e0`, gate selector **365**).
Review and planning only: nothing was executed, compiled, packaged or benchmarked, and no product, test, fixture,
selector or build-logic byte was changed.

Measures issued here are **AH0–AH9**.

## 0. What this review verified independently

The working tree is **byte-identical** to the packaged semantic source R8 executed:

```
git diff --stat 4f0f3ca74a88ba260a20c019437bc4995f2056e0 HEAD -- tests/ src/ include/ benchmarks/   →  empty
```

so every source claim below describes exactly what ran. Selector authority was recomputed from committed bytes and
matches CB7 and the R8 report on all four values: whole-365
`6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1`, first-361
`61918d9fbd7bf757437886f0e86776b60665c58e4d7283b81d42caca03c0288b`, first-357
`b896d0db7f26aeb0f3513418405efdeccbcf84fb6dc971500c6ddac9e364dc70`, first-355
`e9d88f1196e412e06424294d6be22b32f01c9671ec5e4de119abd3f2fb5afeaa`. Ordinals 356–365 in the file are exactly
AG7's frozen order, each resolving to one `TEST(...)` definition.

Where a conclusion depends on the raw log this review cannot open (result artifact `9725240893`), that dependency
is stated explicitly rather than assumed away.

---

## 1. What R8 established, and it is a great deal

R8 is the most productive runtime in this checkpoint's history, and the red should not obscure it.

- **The accepted prefix survived a large A2a′ rewrite.** Ordinals 1–355 are **355/355 PASS** on a package whose
  `SurfaceCutGraph`, `EmbeddedGraphTopology` rotation system, cut proposal and error surface all changed under
  Amendment 14. No accepted-green behaviour was lost.
- **CP4c-2's criterion C1 is demonstrated at runtime.** Ordinal 356
  `TorusWitnessDerivesRegionsThroughProductionEntryPath` passes with `networkV=48`, `networkE=48`,
  `cutEdgeCount=28`, `torusRegionCount=4`. Cross-checking against R7-3's independent oracle
  (`torus V/E/F = 72/76/4`): `72 − 48 = 24` added vertices and `76 − 48 = 28` added edges, and **28 is exactly the
  producer's cut-edge count**. The producer and the independent oracle agree term for term on the torus. A2a′ now
  takes a closed genus-1 surface from a non-cellular network to a certified cellular embedding, and A2b derives
  four regions from it. That is the gap CP4c-2 was created to close.
- **Ordinal 357 passes**, so criterion **C6** (disc proof plus mandatory preservation) holds on the produced torus.
- **Ordinal 358 passes**, so A2a′'s idempotence contract holds: an already-cellular network receives an empty
  certified cut set carrying `complex = ActualEmbeddedGraph`.
- **AF0 confirmed the R7-REV inference exactly.** The sphere now publishes
  `surfaceCutGraphError=CellularityNotEstablished; originatingTopologyError=RotationSystemInconsistent`. R7-REV
  derived that statically from the nine `sourceFace`-carrying error sites in `EmbeddedGraphTopology.cpp` and
  refused to promote it without the printed code; the printed code matches. The eight-turn misreading is now closed
  at the source rather than by argument.
- **AF2 landed and executes.** D2 publishes `oracleComplex=sourceEdgeBarrier`,
  `oracleIsCellularityOracle=false`, `withdrawnBarrierProxySite=proposal-global-certificate`. `R7-CAND-03` is
  properly resolved.
- **AG3's conditions hold on all three witnesses**: `traceEndpointsAttached=true` and `noDegreeZeroNodes=true` for
  two-ring, torus and sphere. Those are exactly the two conditions DEFN-R2 §5.2 said must be verified rather than
  assumed for the completeness theorem. **The theorem's premises are now runtime-verified.**
- **AF6 was honoured.** The frozen non-gating selector's single identity ran (`frozen non-gating: 1`), which the R7
  plan had skipped without rationale.
- **Postflight is immutable-green** with every mutation flag false, and `R8-ORCH-01` was a pre-runtime binding stop
  with no Directional process — correctly classified and closed.

CB7 delivered every AF/AG measure it claimed, with one exception examined in §3.

---

## 2. The first red — full localization

R8's report localizes ordinal 359 to "still constructs rails with the test-local `rails_from_atlas(...)` helper,
while the production torus path uses the pipeline-published `authoritativeRails` snapshot." That is true and it is
**not the whole mechanism**. The complete diagnosis is below; it changes what the fix has to be.

### 2.1 The mismatch is fourfold, not single

`make_source_authority(mesh)` (`tests/FieldAlignedCurveNetworkTests.cpp:181-191`) builds
`SurfaceCellTracingOptions` with:

```cpp
options.sourceFaceComponents.assign(mesh.F.rows(), 0);
options.sourceFaceSheets.assign(mesh.F.rows(), 0);
options.hardFeatureEdges = hardFeatureEdges;      // defaulted to {} at every ordinal-359/361 call site
// options.authoritativeRails is never set
```

The production chain in `src/pipeline/RemeshPipeline.cpp:6377-6394` is:

```
featureMap
  → build_authoritative_surface_cell_rails(mesh, featureMap)   → authoritativeRails
  → hard_feature_edge_keys_from_rails(authoritativeRails, |V|)  → hardFeatureRailEdges
  → SourceTopologyRegions( … hardFeatureRailEdges, componentByFace, localSheetByFace, authoritativeRails )
  → FieldTransportAtlas::make( …, hardFeatureRailEdges, … )
```

Ordinal 359 supplies **none** of the four: no rails, no hard-feature edges, all-zero component labels, all-zero
sheet labels. It then asks `rails_from_atlas` to recover rails **from the atlas it just built without them**.

### 2.2 The dependency is acyclic in production and vacuous in the test

`rails_from_atlas` (`:229-252`) selects `atlas.nontraversable_edges()` whose kind is `SourceBoundary` **or**
`HardFeature`. On a **closed** torus built with `hardFeatureEdges = {}`:

- no `SourceBoundary` edges — every edge has two incident faces;
- no `HardFeature` edges — the set passed to the atlas was empty;
- no `NonTraversable` edges — `make_source_authority` gives every face component 0 and sheet 0, so the
  region/component test at `FieldTransportAtlas.cpp:1414-1418` never fires (and that kind is filtered out anyway).

**`rails_from_atlas` therefore returns an empty rail set, forced by the source.** With zero rails the network has
zero mandatory edges, and the torus has zero singularities, hence zero ports and zero traces: an **empty network**.
Production derives hard features from rails; the test tries to derive rails from hard features it never supplied.

### 2.3 R8's own pass/fail split proves the mechanism

The discriminator is not "torus" — it is **closed versus bounded**:

| ordinal | identity | witness | boundary? | rails from `rails_from_atlas` + `{}` | R8 |
|---|---|---|---|---|---|
| 358 | `AlreadyCellularNetworkPublishesEmptyCertifiedCutSet` | `make_square_mesh` | yes, 4 edges | 4 `SourceBoundary` rails | **PASS** |
| 359 | `IsInvariantToSourceFaceAndEdgeEnumeration` | `torus.obj` | **no** | **empty** | **FAIL** |
| 360 | `…ForTwoRingWitness` | `make_cp3a_two_ring_skew_disc` | yes | boundary rails | not run |
| 361 | `…ForTorusWitness` | `torus.obj` | **no** | **empty** | not run |

Every identity using this construction on a witness **with** a boundary passes; the only one executed on a
**closed** witness failed. This is a falsifiable prediction that R8's own results already confirm, and it predicts
361 fails identically.

### 2.4 The error funnel makes the cause unreadable — and would lie if naively printed

Ordinal 359's `build` lambda (`:2346-2378`) prints a typed code for an atlas or network failure via
`ADD_FAILURE()`, then returns a **sentinel**:

```cpp
return directional::geometry::SurfaceCutGraphBuildResult(
    directional::geometry::SurfaceCutGraphError{});     // default-constructed
```

Three consequences the implementation agent must not walk into:

1. `ADD_FAILURE()` is **non-fatal**, so all three causes — atlas failed, network failed, cut graph failed — arrive
   at the same fatal `ASSERT_TRUE(baselineCutGraph)` on line 2381. The reported locus therefore does **not**
   identify the cause, and the R8 report does not say whether an `ADD_FAILURE` line preceded it.
2. A default-constructed `SurfaceCutGraphError` has `code = InvalidSourceBinding` (enum value 0) and
   `originatingTopologyError = nullopt`. **Adding `<< surface_cut_graph_error_code_name(cutGraph.error().code)` at
   line 2381 would print a fabricated `InvalidSourceBinding` whenever the real failure was upstream.** That is a
   worse defect than printing nothing: it manufactures a false locus, which is precisely the class of error that
   cost this checkpoint eight turns at the sphere.
3. The lambda's early-exit shape is the right instinct — it does print codes — applied to the wrong control flow.
   A helper that cannot use `ASSERT_*` should return a typed variant naming the failing stage, not synthesize a
   product error it never obtained.

### 2.5 Established, and not established

**Established from source, needing no runtime:** the rail set is empty; the authority mismatch is fourfold; the
closed-versus-bounded discriminator explains R8's exact pass/fail split; the funnel makes the three causes
indistinguishable at line 2381; ordinal 361 shares the construction and will fail the same way.

**Not established:** *which* of the three stages actually failed. The retained artifact `9725240893` contains the
process stdout and settles it in one read, with no new runtime — the same manoeuvre `AF1` used successfully in CB6.
**AH1 requires that read before any code is written**, because the three causes have materially different
follow-ons (§8).

**Not claimed:** that this is a product defect. It is not. Ordinals 356/357 exercise `SurfaceCutGraph` and
`GlobalTopologyPlan` on the production torus and pass, and the producer's cut-edge count reconciles exactly with
the independent oracle. A2a′ is working on the torus.

---

## 3. The measure that under-specified its own target — my error, owned

R7-REV's **AF3** read:

> *"Change `SemanticDigestIgnoresGaugeRelabelingForTorusWitness` to build its baseline from the **production torus
> authority** — the same `torus.rawfield`-derived field `cp4c_torus_fixture()` uses — rather than
> `make_zero_transport_field`."*

CB7 did exactly that: it replaced the synthetic field with `finalize_surface_cell_raw_cross_field(mesh, raw)` on
the committed `torus.rawfield`, and it also permuted the raw-field rows alongside the mesh rows in ordinal 359,
which is correct and non-obvious. **CB7 executed the measure as written.** The measure was wrong: its parenthetical
narrowed "the production torus authority" to *the field*, and the production torus authority is **four products** —
rails, hard-feature edges, component labels, sheet labels — of which the field is not even one.

This is not a drafting nicety. `RP-01 AUTHORITY_DOMAIN_CONFLATION` has now bitten five times in this subsystem, and
this instance was introduced **by a corrective measure written to prevent it**. Recorded as `LESSONS.md` **59**: a
measure that names an authority must enumerate the products that authority comprises, because "the production X"
is ambiguous exactly when X is a chain — and the ambiguity resolves toward whichever single product the author had
in mind.

**The correct idiom already exists in the same file, and CB7 itself wrote one of the two instances:**

- `observe_cp4c_witness` (`:4391-4403`) threads `authoritativeRails`, `hard_feature_edge_keys_from_rails(...)`,
  `componentByFace` and `localSheetByFace` into `build_source_topology_regions` — all four, from production;
- `build_cp4c_trace_crossed_cut_fixture` (`:1426-1491`, **new in CB7**) computes its hard-feature set first, then
  builds `make_source_authority(mesh, hardFeatures)` **and** `FieldTransportAtlas::make(mesh, auth, hardFeatures,
  field)` from that same set, and only then calls `rails_from_atlas`.

So `rails_from_atlas` is not the defect. It is correct **when the atlas was told about the features first**. The
invariant is: *rails, hard-feature edges, component labels and sheet labels must all come from one feature
authority, and the source authority and atlas must both be built from it before rails are read back out.*

---

## 4. Blast radius — exactly two ordinals

Audited every identity in gate 365 for this construction:

| ordinal | identity | authority surface | verdict |
|---|---|---|---|
| 356 | `TorusWitnessDerivesRegionsThroughProductionEntryPath` | `cp4c_torus_fixture()` production products | correct — PASS |
| 357 | `ProducedWitnessRegionsCarryDiscProofAndMandatoryPreservation` | `cp4c_torus_fixture()` | correct — PASS |
| 358 | `AlreadyCellularNetworkPublishesEmptyCertifiedCutSet` | local + `{}`, but a **bounded** witness | lawful — PASS |
| **359** | `IsInvariantToSourceFaceAndEdgeEnumeration` | local + `{}` on a **closed** witness | **DEFECTIVE** |
| 360 | `…ForTwoRingWitness` | local + `{}`, **bounded** witness | expected lawful |
| **361** | `…ForTorusWitness` | local + `{}` on a **closed** witness | **DEFECTIVE** |
| 362 | `RotationSystemAndFaceWalkAgreeOnTorusProducedWitness` | `cp4c_torus_fixture()` | correct |
| 363–365 | Amendment 14 identities | `build_cp4c_trace_crossed_cut_fixture()`, features threaded correctly | correct |

**The corrective scope is ordinals 359 and 361 only.** No other gate identity, no accepted identity, and no product
source needs to change for this red. Ordinal 358's use of the local construction is lawful because its witness has
a boundary — but it is one refactor away from becoming the same bug, which **AH4**'s guard addresses.

---

## 5. What the hard stop cost, and why it still matters

Ordinals 360–365 remain **NOT RUN**. The frozen first-red stop is correct and must not be weakened. But it means
six contracts are compiled and unexecuted, and CB7's own report calls three of them "complete" on build evidence
alone. `LESSONS.md` §1 is explicit that compiled-but-unexecuted authority is debt wearing a green label. Unproved:

- **360** two-ring semantic/provenance at the A2a′ boundary (green in R7 as a non-gating diagnostic, never as a gate);
- **361** the same on a closed genus-1 witness — `PR8-R044`'s fix is still runtime-proved on **one** witness only;
- **362** criterion **C3**, deferred now for a seventh turn;
- **363** Amendment 14's trace-crossed promotion actually subdividing both arcs;
- **364** the degree-four two-Cut/two-Trace edge-locus rotation — the single genuine code gap DEFN-R2 identified,
  and still the only thing standing between Amendment 14 and shipping unexecuted;
- **365** the saturation last resort.

**`AD3` therefore remains unresolved for a third turn.** Ordinal 359 is its only falsifier, and it has still never
reached its comparison. `candidate_semantic_hash` continues to consume the raw `face.orbit` index into a *semantic*
digest on the strength of a code comment.

---

## 6. A structural observation about ordinals 363–365

All three consume the same `build_cp4c_trace_crossed_cut_fixture()`, and ordinal 365 requires
`certificate.saturationUsed == true` on it. Since saturation promotes *all* remaining admissible edges of the
offending component, a saturated cut set will almost certainly contain a trace-crossed edge — so ordinal 363's
`selectedTraceCrossed` non-empty assertion may be satisfied **through the saturation path rather than the ordinary
tree–cotree path**.

If so, Amendment 14's ordinary selection path would be gated by nothing, and the fixture would prove the last
resort while leaving the primary route unexercised. That is the `AF5` coverage failure recurring one level down.
This is a **hypothesis about unexecuted identities**, not a finding; **AH6** requires it settled by evidence when
360–365 first run, not by argument now.

---

## 7. The prescribed sphere — unchanged by this review, and correctly so

AF0's printed origin (`RotationSystemInconsistent`), D2's `errorSourceFace=25-27-28` and `producerCutEdgeCount=0`
together confirm: the sphere still fails **before** cut selection. Amendment 14 is not an account of it, exactly as
DEFN-R2 §1 required. `M3-CP4c2-TB-X2-CAND-04` stays ACTIVE and unchanged in ownership, and its two independent
problems remain two:

1. the producer fails at `SurfaceCutGraph.cpp:240/243` with `RotationSystemInconsistent` at source face `25-27-28`;
2. independently, its pre-cut graph is non-cellular (`V/E/F = 18/30/18`, `χ=6` vs `sourceChi=2`, re-confirmed by
   R8's AG3 row), so it will need trace-crossed cuts once (1) is fixed.

Neither is in the CP4c-2 gate, which remains a deliberate, recorded scoping decision. **AH8** keeps (1) out of CB8:
it is a product fix on a witness that is not gated, and CB8 must not grow to absorb it while a gate red is open.

---

## 8. Measures **AH0–AH9** for `M3-CP4c-2-CB8`

The next turn is **`M3-CP4c-2-CB8`**, a Code + Build correcting **two test identities**. It is deliberately narrow.
No product source change is authorized by this review.

**AH0 — preconditions and frozen authority.** Gate authority remains selector **365**, whole-file
`6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1`; recompute it and the 355/357/361 prefixes from
committed bytes at authoring and at preflight, never transcribe, and validate each as exactly 64 lowercase hex.
**No selector byte may change** — the fix is inside the two identities, not in the gate. Accepted runtime
predecessor remains 355/355. Compile under `GMP_COMPILE_POLICY.md` with GMP/GMPXX, `runtimeExecution=false`.
`selected_r2_branch=NONE`, `selected_gate=NONE`, `gate_execution_authorized=false`.

**AH1 — read the retained evidence first, before writing any code.** Extract from result artifact `9725240893` the
complete stdout/stderr of the ordinal-359 process and publish, verbatim, every `ADD_FAILURE` line it contains plus
the final assertion. This settles which of the three stages failed. **No new runtime.** Then record which branch of
§2.5 held:

- *atlas failed* → publish `field_atlas_build_error_code_name(...)`; expect `IncompleteCycleBasis` or
  `NonIntegralCycleLift`, because with no hard features the whole closed torus is one region needing `2·genus`
  handle generators. Note this as evidence about the **witness**, not about A1.
- *network failed* → publish the network code; the empty-rail input is the cause.
- *cut graph failed* → publish the code **and** `originatingTopologyError`; this is the only branch that would also
  raise a product question, handled by AH7.

If the artifact is no longer retrievable, say so plainly and proceed under AH2; do not infer a code.

**AH2 — rebuild ordinals 359 and 361 on one production feature authority.** Both identities must obtain
`authoritativeRails` and the source surface labels from the production pipeline and derive everything else from
them, in this order:

```cpp
// once, from the production pipeline on the committed torus fixture
const auto &products = <pipeline run>.surfaceCellContext.productSnapshots;
ASSERT_TRUE(products.hasAuthoritativeRails);
ASSERT_TRUE(products.hasSourceSurfaceLabels);
const auto rails = products.authoritativeRails;
const auto hardFeatures = directional::pipeline::hard_feature_edge_keys_from_rails(
    rails, static_cast<std::size_t>(mesh.V.rows()));

// per ordering: build options explicitly, do not use make_source_authority(mesh)
SurfaceCellTracingOptions options;
options.authoritativeRails   = rails;                 // vertex-keyed: order-invariant
options.hardFeatureEdges     = hardFeatures;          // vertex-keyed: order-invariant
options.sourceFaceComponents = permute(products.sourceSurfaceLabels.componentByFace);
options.sourceFaceSheets     = permute(products.sourceSurfaceLabels.localSheetByFace);
const auto authority = build_source_topology_regions(orderedF, options);
const auto atlas     = FieldTransportAtlas::make(orderedMesh, *authority, hardFeatures, orderedField);
const auto localRails = rails_from_atlas(orderedMesh, atlas.value());   // now non-vacuous
```

Two facts that make this cheap and must be stated in the CB report rather than assumed: `SourceEdgeTopologyKey` is
built from **vertex** indices, so reordering **face** rows leaves `rails` and `hardFeatures` unchanged; only the
per-face label vectors need permuting, by the same reversal the test already applies to `F` and to the raw field
rows. `observe_cp4c_witness` (`:4391-4403`) is the reference implementation of this idiom — follow it.

**AH3 — the alternative that was considered and rejected, so it is not re-proposed.** Re-running the whole
pipeline on the reordered mesh and comparing end-to-end products is a *stronger* test and is **not** what these
identities should do: it would couple A2a′'s gate to the enumeration-invariance of upstream feature detection, so a
red would no longer localize to the cut graph. AH2 keeps each identity's scope equal to its name. If whole-pipeline
enumeration invariance is wanted, it is a separate identity for a later checkpoint — do not fold it in here.

**AH4 — a self-describing runtime precondition, in the CP3a style.** Every identity that builds a
`SurfaceCutGraph` from locally constructed rails must assert, before proceeding, that its rail set is non-empty
whenever its witness is closed:

```cpp
if (mesh.boundaryLoops.empty()) {
  ASSERT_FALSE(rails.empty())
      << "closed witness: rails_from_atlas is vacuous unless the atlas was built "
         "with this witness's hard-feature edges";
}
```

Apply it to ordinals 358, 359, 360 and 361 and to `build_cp4c_trace_crossed_cut_fixture`. `LESSONS.md` §2 records
that CP3a broke a four-checkpoint streak precisely by making a fixture assert its own precondition at runtime; this
is the same control for the same class of defect. Ordinal 358 is lawful today and one refactor from being wrong —
guard it now.

**AH5 — kill the error funnel; never synthesize a product error.** Replace the sentinel
`SurfaceCutGraphBuildResult(SurfaceCutGraphError{})` return. A default-constructed error reports
`InvalidSourceBinding` with no originating code, so a naive `<< error().code` at the fatal assertion would print a
**fabricated locus**. Required shape: make the helper return a typed variant that names the failing stage
(`atlas` / `network` / `cutGraph`) and carries that stage's own error, and have the caller fail fatally with the
stage name plus the real code. Where the cut graph itself fails, also print `originatingTopologyError` — AF0 exists
precisely so that is possible. **Prohibited:** printing `cutGraph.error().code` at line 2381 without first removing
the sentinel.

**AH6 — settle the §6 saturation-versus-ordinary-path question with evidence.** When ordinals 363–365 first
execute, the TB must publish, for `build_cp4c_trace_crossed_cut_fixture`, whether the selected trace-crossed edges
were chosen by the ordinary tree–cotree proposal or only after `saturationUsed` became true. If only under
saturation, Amendment 14's primary selection path is ungated and a second witness — non-disc, trace-crossed, and
solvable **without** saturation — is owed. Do not add that witness pre-emptively in CB8; record the requirement and
let the evidence decide.

**AH7 — the one branch that could widen scope, bounded in advance.** If AH1 shows the cut graph itself failed on an
**empty** network, then A2a′'s behaviour on a zero-arc, zero-node input is an open product question: it should
either certify the whole closed surface by cutting from scratch, or reject with a typed error naming the empty
network. In that case **do not fix it in CB8**. Record it as a new candidate, note that no gated identity depends
on it once AH2 lands, and bring it to the next definition or review turn. CB8 stays two identities wide.

**AH8 — what CB8 must not absorb.** No fix for the sphere's `RotationSystemInconsistent` (a product change on an
ungated witness while a gate red is open). No new gate identity. No selector byte. No change to `topology_error`'s
mapping or to any error enum value. No whole-pipeline invariance identity (AH3). No benchmark, no gate execution,
no `gate_execution_authorized=true`. No revisiting Amendments 12/13/14.

**AH9 — bookkeeping for the CB8 closeout and its TB.** `M3-CP4c2-TB-X2-R8-CAND-01` is **adjudicated** here
(§§2–4) and closes when ordinals 359 and 361 both pass in a run reaching at least ordinal 361. `R7-CAND-01` is
**superseded by it** and should be marked so rather than carried in parallel. `R7-CAND-03` is **resolved** by AF2's
executed D2. `R8-ORCH-01` is closed. `M3-CP4c2-TB-X2-CAND-04` stays ACTIVE, now with its producer origin printed.
**Stable totals are unchanged at 44 / 14 / 30**, debt **5**, M3 packages **65**. The TB after CB8 re-runs gate 365
from ordinal 1 — the frozen prefix discipline is not negotiable — and must still honour AF6's non-gating selector.

---

## 9. Stable accounting

Unchanged: **44 events / 14 categories / 30 recurrences**; produced-witness debt **5**; authoritative M3 packages
**65**. Ordinal 359 is a newly gated identity that has never been accepted, and the inherited 355 is green in this
very run, so no accepted-green behaviour was lost: **+0 events / +0 recurrences**.

## 10. Exact next turn

**`M3-CP4c-2-CB8`** — Code + Build under **AH0–AH9**, correcting exactly two test identities. **AH1 runs first and
requires no build.** Its successor is a fresh artifact-only TB executing gate 365 from ordinal 1.

CP4c-2 remains **open and runtime-unaccepted**. CP4c-3 remains blocked.
