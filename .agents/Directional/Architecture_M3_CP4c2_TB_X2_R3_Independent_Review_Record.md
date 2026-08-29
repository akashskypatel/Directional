# M3-CP4c-2 TB-X2-R3-REV Independent Review and Plan

## 0. Verdict

`M3-CP4c-2-TB-X2-R3-REV` is **COMPLETE / REVIEW GREEN**.

The R3 EXEC stop is **upheld**: D1 failed before publication, D2 was correctly skipped, and no Y5 branch or gate
credit may be inferred. `M3-CP4c2-TB-X2-R3-CAND-01` is adjudicated **RESOLVED AS TO CAUSE / TEST-AUTHORITY /
DIAGNOSTIC FIXTURE RECONSTRUCTION DIVERGENCE / NON-STABLE** — it is localized here, not left unlocalized.

**The torus atlas failure is test-side with high confidence, and the cause is structural rather than a typo.**
`cp4c_network_only_fixture` is the **third** witness-construction idiom in one test file, and it hand-rebuilds a
four-stage pipeline that the product already publishes. Two independent divergences from production are
identified by name in §2.

**Three findings, and the second is the one that cost this run its evidence.** The R3 identity aborts the whole
witness loop on the first failing witness, and the torus is first — so the prescribed sphere, which is *the
decision witness for Branch A*, was never measured even though nothing was wrong with it. That is the same
gating anti-pattern the X2 plan named in §1, recurring in a new form.

A bounded `M3-CP4c-2-CB2-DIAG-R2` is **AUTHORIZED** under measures **Z10–Z19**. No runtime, build, compile,
package, or product/test/fixture/selector change was made in this review.

## 1. What R3 actually established, and what it did not

Verified from the preserved EXEC evidence rather than accepted:

- immutable preflight passed; **all six** frozen selector hashes recomputed unchanged (316, 346, 353, 355, 357,
  358); recursive package and materialized-source byte-and-mode postflight matched exactly;
- D1 selected exactly once and exited `1` after **14 ms**, publishing **zero** `m3Cp4c2Y1` records;
- the failure is `tests/FieldAlignedCurveNetworkTests.cpp:5946`,
  `fixture.network.has_value()` false, `witness=torus;error=field-transport-atlas-unavailable`;
- D2 was skipped by the frozen rule, not by orchestration failure.

**R3 therefore establishes nothing about cellularity, about the producer, or about A2b.** It is a diagnostic
precondition failure. In particular it does **not** weaken, confirm, or bear on the frozen `48/48` torus theorem,
and it does not touch `M3-CP4c2-TB-X2-CAND-04`, which remains ACTIVE and unlocalized because D2 has still never
run.

**CB2-DIAG-R1 did comply with the measures it was given.** `Cp4cRailAuthority` is now passed explicitly per
witness with no default (**Z4**), the oracle is a named source-edge barrier complex with
`complex=sourceEdgeBarrier` and `surfaceCutGraphCalls=0` published (**Z2**), and `oracleSelfConsistent` exists
and is asserted (**Z3**). The correction failed on something Z1 asked for but did not specify tightly enough —
see §2.

## 2. Finding A — the root cause, localized

`cp4c_build_rail_authority` under `PipelineAuthoritative` does this:

```
featureMap          = AdaptiveFeatureMapBuilder::build(mesh.V, mesh.F,
                          options.featureAlign ? options.featureMap
                                               : options.surfaceCells.featureMap)
rails               = build_authoritative_surface_cell_rails(mesh, featureMap)
hardFeatureRailEdges= hard_feature_edge_keys_from_rails(rails, |V|)
atlas               = FieldTransportAtlas::make(mesh, sourceAuthority,
                          hardFeatureRailEdges, field)      // <-- fails on the torus
```

The call *shape* matches production — `RemeshPipeline.cpp:6576-6579` builds the atlas with a hard-feature edge
set too — so the difference is in the **arguments**, and there are at least four places they can diverge. Two
are demonstrable from the test file itself:

**Divergence A — the cross field is not production's.** `cp4c_network_only_fixture` computes
`field = finalize_surface_cell_raw_cross_field(fixture.mesh, raw)`. Production passes `crossFieldProduct`, and
the existing, working observer `observe_cp4c_witness` passes **`products.crossField`** — the pipeline's own
published field. These are two different derivations, and the atlas consumes the field.

**Divergence B — the hard-feature edge set is not production's.** The new helper recomputes it from a feature
map built with `options.featureAlign ? options.featureMap : options.surfaceCells.featureMap`.
`observe_cp4c_witness` instead passes **`tracingOptions.hardFeatureEdges`**, which came from the pipeline. The
torus is precisely the witness whose rails originate in the feature map, so it is the one witness where this
set is non-empty and therefore the one witness where the divergence can bite.

**Divergences C and D, plausible and unmeasured.** Production builds its atlas over `meshWhole`, which may be a
processed mesh rather than the raw loaded OBJ; and it builds source authority through
`build_source_topology_regions` with `sourceFaceComponents` and `sourceFaceSheets` populated from
`sourceSurfaceLabels`, whereas the fixture uses bare `make_source_authority(mesh)`. Either could also matter.
They are listed so the corrective does not "fix" A and B and then trip over C or D.

**Why this is test-side with high confidence.** Production reaches A2a on the torus — that is where the frozen
`48 HardFeature rails / 48 structural nodes / 0 traces / 0 events` came from in CB2's T1 — so production's atlas
construction for the torus **succeeds**. A reconstruction that fails where the original succeeds is a
reconstruction defect. **This must still be confirmed by publication, not assumed** (measure **Z12**).

### 2.1 The structural cause: a third idiom for one job

`tests/FieldAlignedCurveNetworkTests.cpp` now contains **three** ways to build the same witness:

| # | Idiom | Atlas source | Fidelity |
|---:|---|---|---|
| 1 | `cp4c_production_fixture` (~4425) | **`products.fieldTransportAtlas`** — consumed directly, along with `sourceTopologyRegions`, `fieldAlignedCurveNetwork`, `surfaceCutGraph`, `globalTopologyPlan` | **faithful** |
| 2 | `observe_cp4c_witness` (~3957-3991) | rebuilt, but from `products.crossField` and `tracingOptions.hardFeatureEdges` | proven to work on the torus |
| 3 | `cp4c_network_only_fixture` (new in R1) | rebuilt from a locally re-derived field **and** a locally re-derived feature map | **fails on the torus** |

Each new idiom has introduced a defect: idiom 3's first version used `rails_from_atlas` (R2 CAND-01) and its
second version diverges on field and feature map (this finding). **The corrective is not to repair idiom 3's
arguments one at a time — it is to stop hand-reconstructing a pipeline the product already publishes.**

**This is the fourth incident in one authority-divergence family** — the CP4c-0b DG rail-authority split, CB2's
T1/T3 labelling, R2's `rails_from_atlas` control, and now this. Z4 fixed *which authority is named*; it did not
fix *how the authority is obtained*. **Z11** closes that.

## 3. Finding B — the abort-on-first-witness gate cost this run its evidence

The R3 identity loops over `{torus, prescribed-sphere, two-ring}` and calls
`ASSERT_TRUE(fixture.network.has_value())` **inside the loop**. In GoogleTest an `ASSERT_*` in the test body
returns from the test. The torus is element **0**. So its failure terminated the identity after 14 ms with zero
publications — and the prescribed sphere and two-ring were never constructed, never measured, and never
published, **despite nothing being known to be wrong with either**.

The prescribed sphere is the witness whose corrected `V/E/F` under the §5-normative complex decides Branch A and,
through it, the 357/358 selector. **It was available and was thrown away.** Had the loop published per witness
and deferred failure to the end, R3 would have delivered the sphere's corrected numbers and the Z3
self-consistency verdict, and the open question might already be closed.

This is the **third appearance** of one anti-pattern in this checkpoint:

1. the original X2 gated every publication behind `SurfaceCutGraph::make` succeeding;
2. `CellularityNotEstablished` collapsed three distinct mechanisms behind one code with no locus;
3. now, one witness's precondition failure suppresses every other witness's evidence.

**The rule, stated so it cannot be missed: in a multi-witness diagnostic, a per-witness failure must produce a
per-witness typed failure record and must never suppress another witness's publication.** Fail the identity at
the end, once, on accumulated status. **Z13.**

## 4. Finding C — the typed atlas error was discarded, and a helper that publishes it already exists

`cp4c_build_rail_authority` sets `error = "field-transport-atlas-unavailable"` and returns, **throwing away
`atlas.error().code`** and its locus. So R3's evidence names the stage but not the reason, and the review cannot
distinguish, say, `IncompleteCycleBasis` from any other atlas failure.

That information loss was avoidable: `observe_cp4c_witness` already calls `append_atlas_error(...)` **and**
`append_cp4c_atlas_failure_diagnosis(...)`, purpose-built helpers that serialize exactly this. The new code path
did not reuse them.

This is the same defect class as `CellularityNotEstablished` — a typed failure flattened to a string at the one
place where the type was the evidence. **Z14** requires the typed code, its locus, and the existing diagnosis
helper on every fixture-construction failure.

## 5. What remains true and unchanged

- The **normative complex** remains the source-mesh barrier complex fixed by the R2 review §5: `E = |B|`,
  `V =` source vertices incident to `B`, `F =` components of source faces after removing `B`. R3 gives no reason
  to revisit it, and CB2-DIAG-R1 implemented it.
- The frozen **`48/48`** torus theorem is untouched. R3 never reached a torus network.
- `M3-CP4c2-TB-X2-R2-CAND-01` and `CAND-02` remain **ACTIVE**: their closure conditions require corrected
  publications that do not exist yet.
- `M3-CP4c2-TB-X2-CAND-04` remains **ACTIVE / UNLOCALIZED**. D2 has never executed on any package.
- `selected_r2_branch=NONE`, `selected_gate=NONE`, `gate_execution_authorized=false`.
- Stable accounting **42 / 14 / 28**, debt **5**, M3 packages **60**.

## 6. Measures **Z10–Z19** for `M3-CP4c-2-CB2-DIAG-R2`

- **Z10 — preconditions and immutability.** Accepted authority remains CP4c-1 TB-R5 **355/355**. Re-verify all
  six frozen hashes before and after, unchanged: 316 `601ce2b6…0193c`, 346 `20d3b0b1…3e46a`, 353
  `51ff96d7…ac6a5`, 355 `e9d88f11…5afeaa`, 357 `b896d0db…64dc70`, 358 `6eda3aad…b64fbe62`. Compile under
  `GMP_COMPILE_POLICY.md` with GMP/GMPXX; `runtimeExecution=false`. **`src/`, `include/`, and `SurfaceCutGraph`
  remain frozen — test/diagnostic source only.**
- **Z11 — consume the published products; stop reconstructing the pipeline.** For the **loaded production
  witnesses** (torus, prescribed sphere), obtain source authority, rails, atlas, and network from
  `remesh_from_raw_cross_field(...)`'s `productSnapshots` — `products.sourceTopologyRegions`,
  `products.authoritativeRails`, `products.fieldTransportAtlas`, `products.fieldAlignedCurveNetwork` — exactly
  as `cp4c_production_fixture` does. **Do not rebuild the feature map, the rails, the cross field, or the atlas
  by hand for these witnesses.**
  - **Critical detail, or this measure fails immediately:** `cp4c_production_fixture` as written *also* requires
    `products.surfaceCutGraph` and `products.globalTopologyPlan` and throws when they are absent. **The torus
    has neither** — that is the whole open problem. Use a **relaxed variant** that requires only through
    `fieldAlignedCurveNetwork` and tolerates absent cut graph and plan, publishing their presence as fields.
    Do not weaken `cp4c_production_fixture` itself; the accepted identities that use it must keep their stricter
    precondition.
  - The **two-ring** is a *constructed* witness with no pipeline products; it keeps its existing
    `AtlasDerived` construction. Publish `witnessConstruction=` on every record — `pipelineProducts` or
    `constructed` — so the two can never be silently conflated.
- **Z12 — confirm the test-side classification rather than assuming it.** Publish, for the torus,
  `pipelineAtlasAvailable=` and `pipelineNetworkAvailable=` from the product snapshots, plus
  `terminalFailureCode` / `terminalFailureStage` when absent. **If the pipeline's own atlas is also unavailable
  for the torus, stop and route to review** — that would make this a product finding and would put the frozen
  `48/48` theorem in question, which is a re-adjudication, not a repair.
- **Z13 — no witness may suppress another.** Restructure the D1 identity: iterate all witnesses, build each
  independently, publish exactly one record per witness — **including a typed failure record for a witness that
  cannot be constructed** — accumulate status, and assert **once, after the loop**. **A per-witness failure may
  never prevent another witness's publication.** The prescribed sphere in particular must be published even when
  the torus fails.
- **Z14 — never flatten a typed error.** On any fixture-construction failure publish the typed code and locus:
  reuse the existing `append_atlas_error(...)` and `append_cp4c_atlas_failure_diagnosis(...)` for atlas
  failures, and `network_error_locus(...)` for network failures. **A bare string such as
  `field-transport-atlas-unavailable` is not acceptable evidence** and must not appear alone.
- **Z15 — do not invent a fourth idiom.** After this correction the file must contain **at most three** witness
  constructions with a one-line comment on each stating what it is for and why it differs. If the relaxed
  variant in Z11 can be shared with `observe_cp4c_witness` or `cp4c_production_fixture` without weakening
  either, share it. Record in the CB report how many idioms remain and why.
- **Z16 — carry the surviving Z-measures forward unchanged.** Z2's named complex, Z3's self-consistency
  assertion, Z4's explicit rail-authority argument with no default, Z5's no-encoded-answers rule, and Z7's
  two-ring re-derivation all stand. **Do not re-litigate them; they were implemented correctly.**
- **Z17 — retry ordering** (supersedes Z6, extended by Z13). The successor artifact-only retry must, in order:
  (1) publish a record for **every** witness, including failures; (2) reproduce the torus control
  `V=48, E=48, χ=0, non-cellular` **from authority, never from an encoded constant**; (3) pass Z3
  self-consistency on all three witnesses; and only then (4) execute D2 and attempt Y5. **Step 1 is now
  unconditional** — it is what R3 lacked, and it must produce evidence even when steps 2-3 fail.
- **Z18 — accounting.** Adjudicate `M3-CP4c2-TB-X2-R3-CAND-01` per §2 as test-authority / fixture
  reconstruction divergence; it closes when the torus reaches a published network through Z11. R2 CAND-01 and
  CAND-02 close on their existing conditions. CAND-04 stays ACTIVE until D2 runs. Totals stay
  **42 / 14 / 28**, debt **5**; increment the package count.
- **Z19 — prohibited.** Editing `src/` or `include/`; touching `SurfaceCutGraph`; changing or inventing
  selectors; running any cumulative gate; executing D2 before Z17's steps 1-3 pass; starting frozen `CB3`;
  relaxing `proves_cellularity()`; any test-only injection path into A2b or weakening of
  `make_from_candidate`; defining cellularity as `cut_edges().empty()`; any oracle call into `SurfaceCutGraph`;
  encoding `48/48` or any sphere outcome as a constant, special case, or witness-name branch; weakening
  `cp4c_production_fixture`'s existing preconditions; refining the cut model; touching the mechanical witness,
  C2, or CP4c-3.

## 7. Falsifiable predictions

1. The torus's pipeline-published atlas and network **are available** via `productSnapshots`, so Z11 alone
   clears the R3 stop without any further fix. *(If false, Z12 fires and this becomes a product finding.)*
2. Under Z11 the torus reproduces **`V = 48`, `E = 48`, `χ = 0`, non-cellular**, matching the frozen theorem.
3. The atlas failure that R3 hit is caused by **Divergence A, Divergence B, or both**; if the corrective agent
   tests the hypothesis directly rather than switching wholesale to Z11, substituting `products.crossField` and
   `tracingOptions.hardFeatureEdges` into the old helper makes the torus atlas succeed.
4. Under Z13 the prescribed sphere publishes a full record **on the very next run**, whatever the torus does.
5. The sphere's corrected barrier-complex terms are **self-consistent** — either all components are discs *and*
   `V − E + F = 2`, or at least one is not a disc *and* the sum differs from 2. The R2 state, all discs with a
   sum of 6, cannot recur.
6. Most likely branch remains **A**, and it remains **unadjudicated** until D2 runs. Do not act on it.

Prediction 1 is the load-bearing one. Prediction 3 is diagnostic and optional — it is offered so the agent can
confirm the mechanism cheaply, **not** as an alternative to Z11.

## 8. Stop / successor

The exact next turn is **`M3-CP4c-2-CB2-DIAG-R2`**, Code + Build, runtime-free, test/diagnostic source only,
under measures **Z10–Z19**.

Its successor is `M3-CP4c-2-TB-X2-R4`, artifact-only, which must satisfy **Z17**'s ordering — with step 1
unconditional — before any Y5 branch selection. `selected_r2_branch` remains **NONE**, `selected_gate` remains
**NONE**, and `gate_execution_authorized` remains **false**.
