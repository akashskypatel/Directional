# M3-CP4c-2 TB-X2-R7 Independent Review Record

## Status

**REVIEW COMPLETE / R043 AND R044 CLOSED / R7-ORCH-01 CLOSED / CAND-04 RE-LOCALIZED AND RE-FRAMED /
NO GATE SELECTED / NEXT TURN IS A BOUNDED DIAGNOSTIC CODE+BUILD**

This record adjudicates `M3-CP4c-2-TB-X2-R7-EXEC` (run/job `33276039911 / 99162853852`, immutable package
`9719216316`, semantic/test source `755485865a7cf9c485d754f22b82a41ee151824b`). It is planning and review only:
no product, test, fixture, selector, or build logic was executed or mutated in this turn, and no benchmark ran.

Measures issued here are **AF0–AF9**.

## 0. What this review verified independently, and how

Every source claim below was checked against the working tree at HEAD, which is **byte-identical** to the packaged
semantic source that R7 executed:

```
git diff --stat 755485865a7cf9c485d754f22b82a41ee151824b HEAD -- tests/ src/ include/   →  empty
```

So static reasoning over these files is reasoning over exactly what ran. Where a conclusion depends on a raw record
this review cannot see (result artifact `9721564203`), that dependency is stated explicitly rather than assumed away.

Selector authority was re-derived from committed bytes; the six frozen hashes are unchanged and match
`ORIENTATION.md`, the corrected R7 plan, and the CB5 report. No selector file differs.

---

## 1. R7-1 — the accepted 355 re-proof is ACCEPTED

R7-1 executed the frozen CP4c-1 selector as 355 fresh processes, each selecting exactly one identity, and reached
**355/355 green** with immutable preflight green on all six selector derivations and unconditional postflight
green on every mutation/build flag. Ordinals **305** and **310** are both green **in the same complete run**.

This is the first full accepted-prefix re-proof since CB3 inserted A2a′. It is admissible, and it is the strongest
evidence produced in this checkpoint arc. **Accepted.** The accepted runtime predecessor for CP4c-2 remains
CP4c-1 at 355/355, now re-proved on CB5 package `9719216316`.

R7's execution discipline was also correct and should be preserved verbatim in the next TB plan: one identity per
fresh process, proof of exactly-one selection, first-nonzero hard stop, unconditional postflight, and AE8's
publish-non-gating-first ordering, which is the only reason R7-2..R7-5 evidence exists at all.

---

## 2. `PR8-R043 / M3-CP4c2-R001` — **CLOSED**

Frozen closure condition, recorded at R6-REV under measure AD8: *ordinal 305 green in a run that reaches the full
355/355.* R7-1 satisfies it exactly — ordinal 305 `GlobalTopologyPlan.DerivesRegionsAsFacesOfTheEmbeddedNetworkGraph`
selected once and passed inside the complete 355/355 run.

The underlying defect is also gone at the locus, not merely masked. The mixed-complex certificate that computed
`9 − 11 + 2 = 0 ≠ 1` on the two-ring no longer exists: DEFN-R1 Amendment 13's actual-embedded-graph complex replaced
it, and CB4 delivered `src/geometry/EmbeddedGraphTopology.{h,cpp}` as the single shared authority AC1 required.
`SurfaceCutGraph.cpp` now certifies `ActualEmbeddedGraph` (`proves_cellularity()` requires
`complex == SurfaceCutGraphComplexKind::ActualEmbeddedGraph`), so the withdrawn whole-source-face proxy cannot
re-enter the certificate by construction.

**Disposition: `PR8-R043 / M3-CP4c2-R001` → RESOLVED / CLOSED.** No prefix promotion is involved; the condition
required a full run and it got one.

## 3. `PR8-R044 / M3-CP4c2-R002` — **CLOSED**, with the residual stated precisely

Frozen closure condition: *ordinal 310 green in a run that also reaches the full 355/355.* R7-1 satisfies it.

The fix is also structurally correct, verified at source:

| site | state at CB5 |
|---|---|
| `SurfaceCutGraph.cpp:263` `candidate_hash` | **still consumes `candidate.atlasDigest`** — correct; this is the provenance hash `make_from_candidate` needs to reject a foreign/tampered atlas |
| `SurfaceCutGraph.cpp:268` `candidate_semantic_hash` | new; consumes `sourceDigest`, `networkSemanticDigest`, cut edges and certificate terms — **no `atlasDigest`** |
| `SurfaceCutGraph.cpp:335` `SurfaceCutGraph::make` | constructs with both: `candidate_semantic_hash(value, network.semantic_digest())` and `candidate_hash(value)` |
| `GlobalTopologyPlan.cpp:1630` | `candidate.cutGraphDigest = cutGraph.semantic_digest()` — the consumer was converted |
| `GlobalTopologyPlan.cpp:1511-1519` | `candidate_semantic_digest` consumes `cutGraphDigest` + `network.semantic_digest()`, with the comment now naming **both** sites |

This is exactly the `M3-CP3a-DG-CAND-02` template AD1/AD2 prescribed, and the prohibition held: `atlasDigest` was
**not** removed from the provenance hash. R7-2's two-ring run confirms it at runtime — semantic digests equal
(`13559155349784658228`), provenance digests unequal (`3398751569552983810 ≠ 4134247641157939318`).

**Disposition: `PR8-R044 / M3-CP4c2-R002` → RESOLVED / CLOSED** on its frozen condition.

**What closure does not claim, stated so nobody later reads more into it than it carries.** Ordinal 310
(`RegionAuthorityIsInvariantToEnumerationOrderAndBranchRelabeling`, `tests/FieldAlignedCurveNetworkTests.cpp:2509`)
uses the **two-ring** witness, and R7-2's passing counterpart is also the two-ring. The torus counterpart did not
reach its comparison (§5). So the semantic/provenance split is runtime-proved on **one** witness. That is what the
frozen condition asked for and it is met; the second witness is a separate, newly-opened item, not a reason to
withhold a closure that was defined in advance. Moving a closure condition after the evidence arrives is the
failure mode this project has corrected twice, and it is not repeated here.

**Measure AD3 is still live and is now the sharpest residual.** `candidate_semantic_hash` consumes `face.orbit` —
the raw index into `faceWalk.orbits` — under a written rationale that the orbit ordinal is content-derived because
`EmbeddedGraphTopology` assigns `NetworkArcId` from a total sort over semantic arc descriptors. That rationale is
plausible and is *not* proved. Its single dedicated falsifier is
`SurfaceCutGraph.IsInvariantToSourceFaceAndEdgeEnumeration`, which asserts invariance under source **face and edge
enumeration** reordering — precisely the axis gauge relabeling does not test. That identity is in **no selector**
(§7) and, on the evidence of §5, cannot currently construct its witness. So the AD3 rationale today rests on a
comment, not a test. AF4 owns it.

## 4. `M3-CP4c2-TB-X2-R7-ORCH-01` — **CLOSED**

Its frozen closure condition was: *R7-0 preflight passes on all six rows against unchanged immutable package
`9719216316`.* Run `33276039911` did exactly that, then started Directional runtime. All six values were
independently recomputed in this review from committed selector bytes and match. Selector files were never
modified; the defect was always and only prose.

**Disposition: CORRECTED AND CLOSED / ORCHESTRATION / DOCUMENT-AUTHORITY / NON-STABLE.** Its durable output —
`LESSONS.md` 22n, AE4's 64-lowercase-hex authoring check, AE5's source-file-plus-derivation columns — is already in
force in the corrected R7 plan and stays in force.

---

## 5. The decisive finding — the prescribed sphere is not failing cellularity, and never was

This is the finding of the turn. It is derived entirely from retained evidence and committed source; it needs no
new runtime to establish, only one printed value to confirm.

### 5.1 The record R7-5 published

The regression tracker preserves the full `m3Cp4c2Y2` row, which the EXEC report summarized only in part:

```
surfaceCutGraphStatus=error ; surfaceCutGraphError=CellularityNotEstablished
errorSourceFace=25-27-28    ; publishedLocusClass=419-or-437-source-face-locus
localizedSite=474-global-certificate ; localizationConsistent=false
producerGlobalCountsReached=true
```

`errorSourceFace` is populated. That single field settles the question.

### 5.2 Only one code path can produce that combination

In the `SurfaceCutGraph::make` path that D2 exercises, `CellularityNotEstablished` has exactly three producers:

| producer | sets `sourceFace`? |
|---|---|
| `SurfaceCutGraph.cpp:250` `cut_error(CellularityNotEstablished)` — the `exterior.size() > totalOrbits` guard | **no** — `cut_error` sets only `code` (`:44-48`) |
| `SurfaceCutGraph.cpp:337/339` — `make_from_candidate` binding fallbacks | **no**, and not on this path (D2 calls `make`) |
| `SurfaceCutGraph.cpp:50-67` `topology_error(const GlobalTopologyPlanError &)` | **yes** — `result.sourceFace = error.sourceFace` |

`topology_error` is called from exactly two places, `SurfaceCutGraph.cpp:240` and `:243`:

```cpp
const auto embeddedBuild = build_embedded_graph_topology(...);
if (const auto *failure = std::get_if<GlobalTopologyPlanError>(&embeddedBuild)) return topology_error(*failure);   // :240
const auto exteriorBuild = exterior_boundary_orbits(...);
if (const auto *failure = std::get_if<GlobalTopologyPlanError>(&exteriorBuild)) return topology_error(*failure);   // :243
```

and its mapping is a three-case switch over 39 `GlobalTopologyPlanErrorCode` values:

```cpp
case InvalidSourceBinding:                       → InvalidSourceBinding
case InvalidNetworkBinding: case InvalidCutGraphBinding: → InvalidNetworkBinding
default:                                         → CellularityNotEstablished   // 36 distinct codes
```

**Thirty-six distinct typed errors are flattened into one.** `CellularityNotEstablished` on this path is therefore
not a verdict about cellularity — it is the default bucket.

### 5.3 What the collapsed code almost certainly is

Both `topology_error` call sites are entry points into `src/geometry/EmbeddedGraphTopology.cpp`
(`build_embedded_graph_topology` and `exterior_boundary_orbits` are both defined there, at `:1160` and above).
Across that file's 58 error constructions:

| code | occurrences | can carry `sourceFace`? |
|---|---|---|
| `RotationSystemInconsistent` | 44 | **yes — all nine `sourceFace` assignments in the file (`:364, :372, :499, :507, :514, :813, :827, :929, :939`) belong to this code** |
| `InvalidNetworkBinding` | 5 | mapped away by `topology_error`, would not read `CellularityNotEstablished` |
| `InvalidCutGraphBinding` | 4 | mapped away |
| `InvalidSourceBinding` | 3 | mapped away |
| `MandatoryEdgeTerminalOrderUnresolved` | 1 | no `sourceFace` |
| `MandatoryEdgeNotOnAnyRegionBoundary` | 1 | no `sourceFace` |

**Every code in that file that both survives `topology_error`'s default case and carries a source face is
`RotationSystemInconsistent`.** The file calls nothing in `global_topology_plan_detail`, so no error is constructed
for it elsewhere.

Conclusion, stated at the confidence the evidence supports: the prescribed sphere's A2a′ failure is
**`GlobalTopologyPlanErrorCode::RotationSystemInconsistent`, raised at one of nine sites in
`EmbeddedGraphTopology.cpp` with locus source face `25-27-28`, and relabeled `CellularityNotEstablished` by
`topology_error`'s `default:` case.** The one residual — an error constructed in a helper this review did not
enumerate — is closed by AF0, which prints the code rather than inferring it.

### 5.4 Why this matters more than any other item in the checkpoint

Three things follow, and each one reverses a standing assumption.

**(a) The sphere never reached a cellularity decision at all.** Neither `topology_error` call site evaluates
cellularity. Cellularity is decided later — at `certificate.proves_cellularity()` inside the cut loop
(`SurfaceCutGraph.cpp:323`) and at the `:250` orbit guard. The sphere fails *before* the complex is certified.
Every turn from X2 forward has read `CellularityNotEstablished` and reasoned about whether the sphere is cellular,
how many cuts it needs, and which complex certifies it. **That entire line of reasoning was aimed at a mechanism
the sphere never reached.** The eight-turn drought was not only a scheduling problem; the vocabulary was pointing
the wrong way the whole time.

**(b) It is very likely the same failure the sphere always had.** `CAND-04`'s own record asks whether "the sphere's
old `RotationSystemInconsistent` was caused by non-cellularity." On this evidence the answer is that A2a′ did not
change the sphere's failure — it **renamed** it. Inserting `SurfaceCutGraph` upstream of `GlobalTopologyPlan` moved
the same rotation-system inconsistency one stage earlier and, through `topology_error`'s default case, gave it a new
name. That is a textbook instance of the pattern `ORIENTATION.md` §8 already carries: *a typed error flattened to a
bare string; one error code collapsing several mechanisms with no locus.* It has now cost this checkpoint eight
turns.

**(c) The standing prediction is not confirmed by this, and must not be recorded as confirmed.** "The sphere's
network is already cellular and needs zero cuts" remains **unadjudicated**. What changed is that its principal
counter-evidence — an apparent `CellularityNotEstablished` — has evaporated, because that string was never a
cellularity finding. The prediction now has to be settled on its own terms, by the actual-embedded-graph oracle
numbers (§6), not by an error name.

**Disposition: `M3-CP4c2-TB-X2-CAND-04` stays ACTIVE, and is re-classified from
`UNLOCALIZED` to `LOCALIZED TO THE SHARED EMBEDDED-GRAPH AUTHORITY / CELLULARITY FRAMING WITHDRAWN`.** It remains
**non-stable**: CP4c-2 has never been runtime-accepted, so no accepted-green behaviour was lost. Totals unchanged.

---

## 6. Evidence that already exists and has never been read

R7-3 (`ResolvedBranchCorrection.ActualEmbeddedGraphCellularityOracleIsPublishedNonGating`,
`tests/FieldAlignedCurveNetworkTests.cpp:7711`) iterates **three** witnesses — two-ring, torus, **and
`sphere_prescribed`** — and for each publishes an `m3Cp4c2ActualGraphOracle` row from
`cp4c_independent_actual_embedded_graph_oracle(mesh, network, cuts)`. When the producer errors, `cuts` is empty, so
the sphere's row is the **pre-cut actual embedded graph** — `V`, `E`, `F`, `χ`, `sourceChi`, exterior-orbit count,
component count — computed independently of the producer.

That is precisely the measurement the standing prediction has been waiting six turns for. **It already ran, it
passed, and it is sitting in retained result artifact `9721564203`.** The EXEC report quoted only the torus row
(`V=72,E=76,F=4,chi=0,sourceChi=0`) and omitted the sphere's.

If the sphere's row shows one graph component, `χ = 2 = sourceChi`, `F > 0` and zero exterior orbits, the network is
already cellular pre-cut and the prediction is confirmed with no new runtime whatsoever. **AF1** requires this row
to be extracted and published before any new execution is planned. This is the cheapest high-value action available
to the project right now, and it costs one artifact read.

The lesson generalizes and is recorded as `LESSONS.md` 22p: *a non-gating diagnostic that iterates witnesses
publishes a row per witness; a report that quotes one row has withheld evidence the run already paid for.*

---

## 7. The D2 localization harness is comparing two different objects with a stale vocabulary

`localizationConsistent=false` looks alarming and carries almost no information. Three independent defects produce
it, and none of them is a product defect.

**7.1 It compares the actual embedded graph against the withdrawn proxy.** `cp4c_producer_rederivation`
(`tests/FieldAlignedCurveNetworkTests.cpp:6139`) builds its components from
`cp4c_source_edge_barrier_accounting(network).barriers` and reports
`producerReDerivationFDefinition=final-source-face-components-separated-by-whole-carrier-edge-barriers-and-tree-cotree-cuts`.
That is the **source-edge-barrier proxy complex that DEFN-R1 Amendment 13 withdrew as cellularity authority**. The
real producer certifies the actual embedded graph. Two different complexes localize failures at different places by
construction, so disagreement is the expected output, not a signal. This is `RP-01 AUTHORITY_DOMAIN_CONFLATION`
at the diagnostic layer — the same class of mistake this reviewer made in R2 and withdrew in DEFN-R1 §1.

**7.2 Its name asserts something false.** `cp4c_producer_rederivation` is not a re-derivation of the producer. It
models a **pre-CB4 producer that no longer exists**. A helper whose name claims an authority it does not have is
exactly how a reader is led to treat its output as a producer cross-check.

**7.3 Its site vocabulary points at line numbers that do not exist.** The three site labels are
`419-initial-nondisc-no-cuts`, `437-final-nondisc`, `474-global-certificate`. `src/geometry/SurfaceCutGraph.cpp` is
**344 lines long**. Those numbers are frozen provenance from a pre-CB4 revision. A locus label that encodes a line
number is stale the moment the file is edited, and here it silently survived a whole-file rewrite.

Given 7.1–7.3, the branch that fired is fully explained: the producer's typed error carried a `sourceFace`
(§5), so D2 classified it `419-or-437-source-face-locus`; the proxy re-derivation ran to completion and reported
`474-global-certificate`; the two strings differ; `localizationConsistent` is `false`. Nothing about the sphere's
actual behaviour is contained in that boolean.

**New candidate `M3-CP4c2-TB-X2-R7-CAND-03` — ACTIVE / TEST-AUTHORITY / `RP-01` / NON-STABLE.** Owned by AF2.

---

## 8. The torus R7-2 red — the diagnostic invents a witness that has never been shown to exist

`SurfaceCutGraph.SemanticDigestIgnoresGaugeRelabelingForTorusWitness` failed at
`tests/FieldAlignedCurveNetworkTests.cpp:2220`, which is exactly:

```cpp
2217  const CrossFieldResult baselineField = make_zero_transport_field(mesh);
2218  auto baselineAtlas = directional::authority::FieldTransportAtlas::make(
2219      mesh, *sourceAuthority, {}, baselineField);
2220  ASSERT_TRUE(baselineAtlas);            // ← the stop
```

**8.1 This is not the torus witness the project reasons about.** Every torus statement in `ORIENTATION.md` §4/§10 —
48 hard-feature mandatory edges, zero traces, a produced cut graph, a produced topology plan — comes from
`cp4c_torus_fixture()`, which runs `remesh_from_raw_cross_field` on the committed **`torus.rawfield`**
(`:4489-4520`). The R7-2 diagnostic instead synthesizes a field with `make_zero_transport_field` (`:159`): identity
matching, zero effort, zero singular cycles, constant `UnitX`/`UnitY` frames. `milestone-g/torus.obj` is loaded in
exactly two places in the whole test file (`:2119` and `:2213`) and **both** feed it this synthetic field. So the
zero-transport torus is a witness with no production counterpart and no prior green.

**8.2 The failure mechanism is a precondition of that synthetic field, not of A2a′.** `FieldTransportAtlas::make`
lifts each cycle by `(cycles·effort + 4·cycleCurvature) / 2π` and rejects a non-integral result with
`NonIntegralCycleLift` (`src/authority/FieldTransportAtlas.cpp:1655-1660`). With zero effort everywhere, the lift is
`2·K_v/π` at each interior vertex. That is integral on a flat mesh — which is why `make_square_mesh` at `:2093` works
— and generically non-integral on a curved closed surface. The torus fixture is curved. `IncompleteCycleBasis` at
`:1597/:1613` (`2·genus` handle generators must be present) is the other live candidate. This review does **not**
promote either as established; AF3 requires the code to be printed rather than inferred.

**8.3 The assertion throws away the answer.** `FieldTransportAtlas::make` returns
`FieldTransportAtlasBuildResult`, a `std::variant<FieldTransportAtlas, FieldAtlasBuildError>` carrying a typed code
plus optional edge/face/vertex/region/branch loci, and the header already exports
`field_atlas_build_error_code_name()`. `ASSERT_TRUE(baselineAtlas)` discards all of it and prints
`Value of: baselineAtlas / Actual: false`. One turn was spent not knowing a value the process had in hand.

**8.4 The paired identity is in the same trap and has never run.** `SurfaceCutGraph.IsInvariantToSourceFaceAndEdgeEnumeration`
(`:2116`) builds its torus atlas identically — `make_zero_transport_field`, empty hard-feature set,
`make_source_authority(mesh)` — inside a lambda that uses `EXPECT_TRUE(atlas)` (non-fatal) and then calls
`atlas.value()`. On the same input that failed at `:2220`, that is `std::get` on the error alternative: the test
does not fail at a diagnosable assertion, it terminates on an unhandled `std::bad_variant_access`. It is in no
selector, so this has never been observed. Its assertions — `ASSERT_FALSE(cut_edges().empty())`,
`ASSERT_TRUE(proves_cellularity())`, digest equality under face/edge reordering — have therefore **never executed**,
which is why measure AD3's orbit-ordinal rationale (§3) currently has no falsifier.

**Adjudication of `M3-CP4c2-TB-X2-R7-CAND-01`: CONFIRMED as a witness-construction defect in the diagnostic, not a
defect in the CB5 semantic/provenance split.** The red grants no accepted-count debit, and it does not weaken §3's
closure. It does mean the split is proved on one witness. Owned by AF3/AF4. **Non-stable, +0 events.**

---

## 9. The coverage hole nobody has stated: A2a′ has no gated identity anywhere

Checked directly against the frozen selector files:

```
grep -c '^SurfaceCutGraph\.'  accepted-355 → 0    candidate-357 → 0    candidate-358 → 0
```

`SurfaceCutGraph` has exactly four direct test identities —
`AlreadyCellularNetworkPublishesEmptyCertifiedCutSet`, `IsInvariantToSourceFaceAndEdgeEnumeration`,
`SemanticDigestIgnoresGaugeRelabelingForTwoRingWitness`, `SemanticDigestIgnoresGaugeRelabelingForTorusWitness` —
and **not one of them is in the accepted selector or in either candidate gate.**

CP4c-2 introduces a new pipeline stage and both proposed gates would accept it while requiring **zero** of that
stage's own witnesses: its empty-cut certificate, its enumeration invariance, and its semantic/provenance
separation are all outside the gate. The stage is only reached transitively through `GlobalTopologyPlan` identities.
That is precisely how a stage ships with a defect its own tests would have caught — and §8.4 shows one of the four
is currently non-viable and nobody noticed, because nothing runs it.

The gate deltas are small enough to state exactly:

| gate | added over 355 | witnesses those identities bind |
|---|---|---|
| **357** | `GlobalTopologyPlan.TorusWitnessDerivesRegionsThroughProductionEntryPath`, `GlobalTopologyPlan.ProducedWitnessRegionsCarryDiscProofAndMandatoryPreservation` | torus only |
| **358** | the above **+** `GlobalTopologyPlan.RotationSystemAndFaceWalkAgreeOnProducedWitnesses` | torus **and mechanical feature** |

**The prescribed sphere appears in neither candidate gate.** So the sphere's failure — the checkpoint's actual open
question — blocks nothing at gate level. The eight-turn drought is structural, not accidental: nothing in the gate
design ever forced the measurement.

**A blocking observation about 358.** Its one added identity calls `cp4c_mechanical_fixture()` (`:6828-6832`),
which is `build_cp4c_production_fixture("mechanical_feature", …)` — and that helper **throws**
`std::runtime_error` when the pipeline did not retain source authority, atlas, network, cut graph and plan
(`:4523-4537`). `ORIENTATION.md` §4 records the mechanical witness as having **no atlas**, stopping in A1 at
`IncompleteCycleBasis`, explicitly **out of CP4c-2 scope** and owned by CP4c-3 / C2. If that durable statement still
holds, **selector 358 is a guaranteed red** and cannot be a gate for this checkpoint. That has never been observed
at runtime, so it is not asserted as fact — AF7 requires 358's added identity to be probed **non-gating** before
358 is ever selected.

**New candidate `M3-CP4c2-TB-X2-R7-CAND-04` — ACTIVE / GATE-AUTHORING / NON-STABLE.** Owned by AF5/AF7.

---

## 10. The frozen non-gating diagnostic selector was bypassed

`Architecture_M3_CP4c2_Non_Gating_Diagnostic_Selector.txt` contains exactly one identity:

```
GlobalTopologyPlan.Cp4c2PrescribedSphereCellularityScopeDecisionIsObservable
```

R7 ran R7-2 through R7-5. **None of them is that identity**, and the R7 plan neither ran it nor recorded why not.
It is an unconditional `FAIL()` publisher at `:6486` that emits `observe_cp4c_witness("sphere_prescribed", …)` —
a full pipeline-reachability report for the sphere, which is directly relevant to §5 and would have been free.

A frozen selector that a plan may silently ignore is not authority. **AF6** requires every TB plan to either run
every identity in the frozen non-gating selector or state, per identity, why it is skipped. Recorded as
`LESSONS.md` 64v.

---

## 11. Gate selection — deliberately NOT made this turn

`selected_r2_branch=NONE`, `selected_gate=NONE`, `gate_execution_authorized=false` **remain unchanged**, and no
cumulative gate or benchmark is authorized.

Reasons, in order of weight:

1. **The discriminator has changed.** For six turns the 357-vs-358 choice was framed as "depends on whether the
   sphere is already cellular." §5 shows the sphere's error string never answered that question. The real inputs are
   now the sphere's actual-graph oracle row (§6, already collected) and the printed collapsed code (AF0).
2. **358 may be structurally impossible** as frozen (§9), for a reason that has nothing to do with the sphere.
3. **Neither candidate gates the sphere or A2a′'s own identities** (§9). Selecting either today would accept a new
   pipeline stage on torus-only evidence while a known, misnamed, unowned failure sits on the trace-rich witness.
   That is acceptance by omission.

357 remains the only viable candidate and is the likely outcome — but it must be selected on evidence, with the
sphere's status explicitly dispositioned rather than silently outside the gate.

---

## 12. Retention check on the deleted predecessor review record

`Architecture_M3_CP4c2_TB_X2_R7_Independent_Review_Record.md` (the first R7-REV, 211 lines) was deleted in
`5b197391c docs: complete M3-CP4c-2 DOC-R1 and consolidate history`, together with the R6 review record and the R6/R7
EXEC evidence files. Under `RETENTION_POLICY.md` a per-turn review record is retirable **only after** its necessary
durable facts are preserved. Verified preserved:

- measures **AE0–AE9** — `Architecture_M3_CP4c2_DOC_R1_Documentation_Correction_Report.md` §§AE0–AE9, `CHANGELOG.md`
  (16 added lines), `Regression_Root_Cause_Tracker.md` R7-ORCH-01, `M3_CP4c_Consolidated_Record.md` §6.6;
- the adopted rule — `LESSONS.md` **22n**, present and intact;
- the R2 withdrawal and its successors — `LESSONS.md` **22k**, **22m**, intact;
- the review arc — `M3_CP4c_Consolidated_Record.md` §§6.1–6.7, present.

**Compliant.** No durable content was lost. This record is its successor.

---

## 13. Measures AF0–AF9 for the next Code + Build

The next turn is **`M3-CP4c-2-CB6`**, a **narrowly bounded diagnostic-and-witness-repair Code + Build**. It exists
to make three already-observed failures legible. It must not attempt a product fix for the sphere: the cause is not
yet printed, and fixing a mechanism named by inference is how this checkpoint lost R2.

**AF0 — stop collapsing the typed error. Additive only.**
Add a field to `SurfaceCutGraphError` carrying the originating `GlobalTopologyPlanErrorCode` (an
`std::optional<GlobalTopologyPlanErrorCode>`, defaulted empty), and populate it in `topology_error`
(`src/geometry/SurfaceCutGraph.cpp:50-67`) alongside the existing `sourceEdge`/`sourceFace` copies. Print it
wherever `surface_cut_graph_error_code_name` is printed today — at minimum the D2 report
(`tests/FieldAlignedCurveNetworkTests.cpp:6709-6723`) and R7-3's `producerError` (`:7746-7750`).
**Prohibited:** changing which `GlobalTopologyPlanErrorCode` maps to which `SurfaceCutGraphErrorCode`. The three-case
switch is accepted behaviour and 355 accepted identities depend on it; this measure adds provenance, it does not
re-map. Also prohibited: introducing a new `SurfaceCutGraphErrorCode` value in this CB — enum values are consumed by
accepted tests.

**AF1 — read the evidence already paid for, before planning any new run.**
Extract the **prescribed-sphere `m3Cp4c2ActualGraphOracle` row** from retained result artifact `9721564203` and
publish it verbatim in the CB6 report: `V`, `E`, `F`, `χ`, `sourceChi`, exterior-orbit count, component count,
`producerStatus`, `producerError`. Then state, in one sentence, whether the standing prediction ("the sphere's
network is already cellular pre-cut") is confirmed, refuted, or still undecided by that row. This is an
evidence-extraction task with **no runtime**; it is the first thing CB6 does, because it may change what CB6 needs
to build.

**AF2 — repair the D2 localization harness, or delete its verdict.**
(a) Rename `cp4c_producer_rederivation` → `cp4c_source_edge_barrier_rederivation`, and give it a one-line comment
naming Amendment 13 and stating it models the **withdrawn proxy** and is not a producer cross-check.
(b) Replace the three stale site labels with names that do not encode line numbers (e.g.
`initial-nondisc-no-cuts`, `final-nondisc`, `global-certificate`); a locus label must never encode a line number
again.
(c) Either remove `localizationConsistent` entirely, or redefine it to compare like with like — the producer's
printed `GlobalTopologyPlanErrorCode` and `sourceFace` from AF0 against a re-derivation over the **actual embedded
graph**. A boolean that is false by construction is worse than no boolean.

**AF3 — give the torus digest diagnostic a witness that exists.**
Change `SemanticDigestIgnoresGaugeRelabelingForTorusWitness` (`:2210`) to build its baseline from the **production
torus authority** — the same `torus.rawfield`-derived field `cp4c_torus_fixture()` uses — rather than
`make_zero_transport_field`, then apply `gauge_relabel_field_for_network` to that. The witness the design reasons
about must be the witness that exercises the code.
In the same measure, replace `ASSERT_TRUE(baselineAtlas)` and `ASSERT_TRUE(relabeledAtlas)` with assertions that
print `field_atlas_build_error_code_name(result.error().code)` plus every populated locus field on failure. Apply
the same treatment to the two-ring identity at `:2165` for symmetry.
**Do not** repair `make_zero_transport_field` or the torus fixture to make the old construction work: the synthetic
zero-transport torus has no production counterpart and no reason to exist.

**AF4 — run the fourth A2a′ identity and settle AD3.**
`SurfaceCutGraph.IsInvariantToSourceFaceAndEdgeEnumeration` (`:2116`) has never executed. Give it the same
production-authority witness and typed-error reporting as AF3, then run it **non-gating** in the next TB. Its result
is the only direct falsifier of measure AD3's claim that `face.orbit` is a content-derived rank rather than an
enumeration artifact. If it passes, record AD3 as **proved by test** and cite the identity next to the comment at
`SurfaceCutGraph.cpp:293-297`. If it fails, AD3 becomes an open product defect. Either way AD3 stops resting on a
comment.

**AF5 — decide A2a′'s gate membership explicitly. DEFN scope, not CB.**
Before CP4c-2 is accepted, the frozen definitions must state, per identity, which of the four `SurfaceCutGraph.*`
tests are gating and why any excluded one is excluded. "It was never added" is not a rationale. This measure is
recorded here and owned by the next DEFN revision; CB6 does not edit selector bytes.

**AF6 — a frozen non-gating selector is authority.**
Every TB plan must run every identity in `Architecture_M3_CP4c2_Non_Gating_Diagnostic_Selector.txt`, or state per
identity why it is skipped. The next TB runs
`GlobalTopologyPlan.Cp4c2PrescribedSphereCellularityScopeDecisionIsObservable` and preserves its `m3Cp4c2X2` report.

**AF7 — gate selection stays closed, and 358 must be probed before it can be chosen.**
`selected_r2_branch=NONE`, `selected_gate=NONE`, `gate_execution_authorized=false`. Before selector 358 may ever be
selected, `GlobalTopologyPlan.RotationSystemAndFaceWalkAgreeOnProducedWitnesses` must be executed **non-gating**
once, in a fresh process, and its result recorded — specifically whether `cp4c_mechanical_fixture()` constructs at
all. Selecting a gate whose added identity binds an out-of-scope witness is not a decision that may be taken on
inference, in either direction.

**AF8 — regression bookkeeping for the next TB/CB closeout.**
Close `PR8-R043 / M3-CP4c2-R001` and `PR8-R044 / M3-CP4c2-R002` (§§2-3). Close
`M3-CP4c2-TB-X2-R7-ORCH-01` (§4). Adjudicate `M3-CP4c2-TB-X2-R7-CAND-01` per §8. Re-classify
`M3-CP4c2-TB-X2-CAND-04` per §5.4. Open `M3-CP4c2-TB-X2-R7-CAND-03` (§7) and
`M3-CP4c2-TB-X2-R7-CAND-04` (§9). **Stable totals are unchanged at 44 / 14 / 30** — closure changes an event's
status, never the cumulative count — produced-witness debt **5**, authoritative M3 packages **64**.

**AF9 — prohibitions for CB6.**
No selector byte may change. No fixture byte may change. No new `SurfaceCutGraphErrorCode` or
`GlobalTopologyPlanErrorCode` enum value. No change to `topology_error`'s code mapping. No product fix for the
sphere's rotation-system failure — CB6 makes it legible, a later CB fixes it. No 357/358 execution, no cumulative
gate, no benchmark. GMP/GMPXX linkage is mandatory per `GMP_COMPILE_POLICY.md`; fallback exact arithmetic is not
authoritative build evidence.

---

## 14. Stable accounting

Unchanged: **44 events / 14 categories / 30 recurrences**; produced-witness debt **5**; authoritative M3 packages
**64**. Two stable events move ACTIVE → CLOSED, which is a status change and not a count change. Every finding in
§§5, 7, 8 and 9 is non-stable: CP4c-2 has never been runtime-accepted, and no accepted-green behaviour was lost —
the accepted 355 is green in this very run.

## 15. Exact next turn

**`M3-CP4c-2-CB6`** — bounded diagnostic and witness-repair Code + Build under **AF0, AF1, AF2, AF3, AF4** with the
**AF9** prohibitions. AF1 executes first and requires no build. AF5 is DEFN scope; AF6 and AF7 bind the TB that
follows CB6; AF8 binds that TB's closeout.

CP4c-2 remains **open and runtime-unaccepted**. CP4c-3 remains blocked.
