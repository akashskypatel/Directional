# M3-CP4c-2 TB-X2-R4-REV Independent Review and Plan

## 0. Verdict

`M3-CP4c-2-TB-X2-R4-REV` is **COMPLETE / REVIEW GREEN**.

Three adjudications, in order of importance:

1. **The evidence contains an unremarked success that changes CP4c-2's framing.** The torus's pipeline
   published **`pipelineCutGraphAvailable=true` and `pipelinePlanAvailable=true`**. A `GlobalTopologyPlan`
   snapshot is written at exactly one place in the product, and only after the plan is successfully built —
   so **the torus now derives a topology plan.** `UncutFaceComponentOrbitSeedNotUnique`, the failure that
   defined this checkpoint, is gone. The DEFN's design is confirmed end to end on the torus and **no turn so
   far has said so.**
2. **The prescribed sphere's "all snapshots unavailable" is a product observability defect, fully localized.**
   It is not a test defect and not a missing product. `RemeshPipeline.cpp:6626-6634` writes all five snapshots
   **after** every early `return fail_surface_cells(...)`, so a failure at A2a′ discards snapshots for products
   that were built successfully and are alive in local variables. **This also means measure Z11 was written on
   a false assumption — mine — and §4 owns that.**
3. **The `STOP_EVIDENCE_CONFLICT` was procedurally correct but the evidence is admissible.** The duplicate is
   byte-identical, so there is exactly one *distinct* record per witness and nothing is in conflict. The
   contract is amended rather than waived, and the torus control is adjudicated **PASS** on this evidence.

A bounded `M3-CP4c-2-CB3-DIAG` is **AUTHORIZED** under measures **AA0–AA9**, and it is the first in this arc
that **touches `src/`** — narrowly, for observability only, with the consequence priced in at AA8.

No runtime, build, compile, package, or product/test/fixture/selector change was made in this review.

## 1. Independently verified from the preserved evidence

- All six frozen selector hashes recomputed unchanged (316, 346, 353, 355, 357, 358); package `29/29` and
  materialized source `533/533` byte-and-mode records match pre/post. The run is trustworthy.
- Torus arithmetic checked: `barrierV − barrierE + barrierF = 48 − 48 + 4 = 4`, against `sourceChi = 0`.
  The identity fails, so `networkOnlyCellular=false` is correct. `oracleSelfConsistent=true` therefore requires
  `everyComponentDisc == false` — at least one of the four components is not a disc. **The oracle is internally
  coherent for the first time in this arc**, and R2's exact-by-4 self-contradiction does not recur.
- Two-ring published successfully, `AtlasDerived`, `oracleSelfConsistent=true`, `networkOnlyCellular=true`.
- CB2-DIAG-R2 complied with Z11's structure: `build_cp4c_pipeline_products_fixture` is the relaxed variant,
  and the strict `build_cp4c_production_fixture` is layered on top of it **without being weakened** — it still
  requires all five snapshots and throws otherwise. Z14's typed failure record, Z13's per-witness isolation,
  and Z2/Z3's named complex with `oracleSelfConsistent` are all present and working.

**A derived reading of the torus, offered as inference to confirm, not as fact.** `barrierV = 48`,
`barrierE = 48`, `barrierF = 4`, and Euler forces the four components' characteristics to sum to
`χ − (V − E) = 0 − 0 = 0`. Four components summing to zero is exactly four annuli. Combined with 48 edges over
48 vertices in four components, the natural structure is **four disjoint loops of twelve edges each**. If true
this matches DEFN prediction 2 precisely. The per-component `χ` and boundary-cycle counts exist in
`d1-records.json` but were not surfaced into the report; **AA6** requires them published.

## 2. Finding A — the torus derives a plan, and this reframes the checkpoint

The torus record reports `pipelineAtlasAvailable=true`, `pipelineNetworkAvailable=true`,
**`pipelineCutGraphAvailable=true`**, **`pipelinePlanAvailable=true`**.

These are read from `products.surfaceCutGraph` and `products.globalTopologyPlan`
(`tests/FieldAlignedCurveNetworkTests.cpp:5276-5277`). Tracing the product: `globalTopologyPlan` is assigned at
**exactly one** site, `RemeshPipeline.cpp:6634`, inside a block reached only after
`GlobalTopologyPlan::make(...)` returns success at 6614-6624. The two other snapshot-writing sites in the file
(12554, 12635) set only `sourceTopologyRegions` and `hasAuthoritativeRails` and cannot produce a plan snapshot.

**Therefore the torus's `GlobalTopologyPlan` was genuinely constructed.** Two consequences:

- **CP4c-2's defining failure is resolved on its own witness.** The DEFN was written because the torus's
  network is provably not a cut graph and A2b consequently failed with
  `UncutFaceComponentOrbitSeedNotUnique`. D1 now independently confirms the first half — network-only
  cellularity is **false** on the torus, exactly as the theorem requires — while the pipeline confirms the
  second half: with `SurfaceCutGraph` supplying cuts, A2b completes. **The design works, measured end to end.**
- **The torus's remaining `terminalFailureCode=NotProductionReady / terminalFailureStage=tracing` is a
  different, later failure.** It is downstream of A2b and is **not** the CP4c-2 gap. It must not be pulled into
  this checkpoint, and it must not be treated as evidence against the cut graph. **AA7** requires it published
  and classified, not fixed.

This finding sat in the EXEC evidence and was reported only as a field value. **A result that discharges the
checkpoint's premise must be stated as a finding, not left as a boolean in a list** — recorded as a lesson in
§7.

## 3. Finding B — snapshot retention is failure-path dependent, and it is a product defect

The sphere's record is internally contradictory on its face:

```
terminalFailureStage = surface-cut-graph/CellularityNotEstablished
pipelineAtlasAvailable = false
pipelineNetworkAvailable = false
error = pipeline-source-topology-snapshot-unavailable
```

A failure **at** `surface-cut-graph` is only reachable through `SurfaceCutGraph::make(meshWhole.F, …,
*sourceTopologyRegionsProduct, *fieldTransportAtlasProduct, *fieldAlignedNetworkProduct)` at
`RemeshPipeline.cpp:6602-6605`. **Dereferencing all three proves all three were built.** So the products
existed and the snapshots were empty at the same instant.

The mechanism is structural and is visible in fifteen lines of the product:

- lines **6576-6612** contain a chain of `return fail_surface_cells(...)` early exits — atlas, network, cut
  graph, plan;
- lines **6626-6634** assign all five snapshots **in one block after every one of those exits**.

So the snapshots are published **only when every stage through A2b succeeds**. Any earlier failure discards
products that were successfully constructed and are still alive in local variables. The torus reaches 6626
because its plan succeeded, and therefore retains everything; the sphere fails at 6607 and therefore retains
nothing.

**Classification: product observability defect.** It changes no accept/reject decision — the failure code and
stage string are already correct — but it makes the pipeline maximally opaque at exactly the moment a
diagnosis is needed, and it is the reason four consecutive diagnostic turns have been unable to measure the
sphere. It is small, in `src/`, and it is the correct thing to fix.

## 4. What I got wrong — Z11's premise

`M3-CP4c-2-TB-X2-R3-REV` measure **Z11** told the implementation agent to consume `productSnapshots` for loaded
production witnesses and to stop reconstructing the pipeline. That instruction was right in principle and it
worked: the torus went from `field-transport-atlas-unavailable` to a clean 48/48 publication in one turn.

**But it rests on an assumption I did not check: that snapshots survive a pipeline failure.** They do not, and
§3 shows the product never promised they would. For the one witness whose pipeline fails at A2a′ — the sphere,
which is the decision witness for Branch A — Z11 is unimplementable as written.

This is the same error class this arc keeps producing, now committed by the reviewer rather than the
implementer: **an instruction was written from what an authority is supposed to expose rather than from what it
actually exposes on the failing path.** It is the direct analogue of X2's unsatisfiable U3/U4. AA1 repairs the
premise instead of working around it.

## 5. Finding C — the stop was correct, the evidence is admissible

The R4 contract required exactly one `m3Cp4c2Y1` record per witness. Four were preserved, because
`ASSERT_TRUE(allWitnessesValid) << failures.str()` at `tests/FieldAlignedCurveNetworkTests.cpp:6071` re-emits
the sphere's already-published record inside its failure message. EXEC stopped. **That was correct: the rule was
frozen and the executor applied it.**

**But a byte-identical restatement is not an evidence conflict.** An evidence conflict is two *different*
records for one witness, which would make the witness's state indeterminate. Byte-identity means there is
exactly one distinct record per witness and nothing is indeterminate. The stop cost this checkpoint a full
cycle over a publication-hygiene defect.

**Adjudication.** The contract is **amended, not waived**: the requirement is **exactly one *distinct* record
per witness**; a byte-identical duplicate emitted inside an assertion message is a defect to fix (**AA5**) and
**not** grounds to discard the run. On that basis the preserved R4 evidence is **admissible**, and §6's
candidate closures follow from it.

**Guard against my own convenience.** This must not read as weakening a frozen rule under pressure — the exact
thing I criticized in the CP4c-1 C5 review. The distinction: there, the rule was wrong *in substance* because it
forbade correct behavior; here the rule is right in substance and only its *response to a benign violation* is
disproportionate. And the adjudication is conditional: **AA2 requires byte-identity to be confirmed from
`d1-records.txt` in the result artifact.** If the two sphere lines differ in any byte, the stop stands, this
section is void, and the evidence is inadmissible.

## 6. Candidate dispositions

| Candidate | Disposition |
|---|---|
| `M3-CP4c2-TB-X2-R2-CAND-01` — torus control used atlas-derived rails | **RESOLVED / TEST-SIDE / NON-STABLE.** The torus now publishes `railAuthority=pipeline-authoritative` with the frozen `48/48` **from authority, not from a constant**. Closure condition met. |
| `M3-CP4c2-TB-X2-R3-CAND-01` — torus fixture reconstruction divergence | **RESOLVED / TEST-SIDE / NON-STABLE.** Z11's product-snapshot consumption removed the reconstruction entirely for the torus. |
| `M3-CP4c2-TB-X2-R3-CAND-02` — one witness suppressed the others | **RESOLVED / TEST-SIDE / NON-STABLE.** The sphere failed and the torus and two-ring were still published. Z13 works. |
| `M3-CP4c2-TB-X2-R2-CAND-02` — mixed-complex Euler accounting | **PARTIALLY RESOLVED — remains ACTIVE.** The torus and two-ring are self-consistent under `complex=sourceEdgeBarrier`, but the sphere has never been measured. Closure requires all three; do not close it early. |
| `M3-CP4c2-TB-X2-R4-CAND-01` — duplicate publication | **ACTIVE**, owned by **AA5**; downgraded from evidence conflict to publication hygiene per §5, conditional on AA2. |
| `M3-CP4c2-TB-X2-R4-CAND-02` — sphere snapshots unavailable | **LOCALIZED / PRODUCT OBSERVABILITY DEFECT**, owned by **AA1**. Cause is §3's early-return placement, not the test. |
| `M3-CP4c2-TB-X2-CAND-04` — sphere `CellularityNotEstablished` unlocalized | **ACTIVE / UNLOCALIZED.** D2 has still never run on any package. This is the fifth turn in which that remains true. |

Stable accounting unchanged: **42 / 14 / 28**, debt **5**, M3 packages **61**.

## 7. Measures **AA0–AA9** for `M3-CP4c-2-CB3-DIAG`

- **AA0 — preconditions.** Accepted authority remains CP4c-1 TB-R5 **355/355**. Re-verify all six frozen
  hashes before and after, unchanged: 316 `601ce2b6…0193c`, 346 `20d3b0b1…3e46a`, 353 `51ff96d7…ac6a5`,
  355 `e9d88f11…5afeaa`, 357 `b896d0db…64dc70`, 358 `6eda3aad…b64fbe62`. Compile under
  `GMP_COMPILE_POLICY.md` with GMP/GMPXX; `runtimeExecution=false`.
- **AA1 — the product fix, and it is the only `src/` change authorized.** In
  `src/pipeline/RemeshPipeline.cpp`, publish each product snapshot **immediately after that product is
  successfully constructed**, before any subsequent stage can fail — `sourceTopologyRegions` after its build,
  `fieldTransportAtlas` after 6578, `fieldAlignedCurveNetwork` after its build, `surfaceCutGraph` after 6613,
  `globalTopologyPlan` after 6625. **Change nothing else:** no `fail_surface_cells` call, no failure code, no
  stage string, no control flow, no ordering of the builds themselves. The observable effect must be exactly
  that a failed run now retains snapshots for the products that succeeded.
  - **Why a product change is authorized here** when four prior turns were test-only: this is not a
    workaround for a test, it is the defect. Every remaining CP4c-2 question needs the sphere's products, and
    they exist but are unreachable. Reconstructing them test-side is what R2 and R3 already proved fragile.
  - **Bounded risk, and how to show it.** The strict `build_cp4c_production_fixture` requires all five
    snapshots and throws otherwise; partial retention cannot make it accept less. No accepted identity's
    behavior should change. **AA8** makes that a measurement rather than an assertion.
- **AA2 — confirm §5's premise before relying on it.** Extract `d1-records.txt` from result artifact
  `9707662462` and confirm the two prescribed-sphere `m3Cp4c2Y1` lines are **byte-identical**. Publish the
  comparison result. **If they differ in any byte, stop and return to review** — §5's admissibility
  adjudication and §6's closures are void, and the R4 evidence cannot be used.
- **AA3 — the sphere is the whole point.** After AA1, D1 must publish a complete `m3Cp4c2Y1` record for the
  prescribed sphere: `barrierV`, `barrierE`, `barrierF`, `sourceChi`, per-component `χ` and boundary-cycle
  counts, `everyComponentDisc`, `eulerIdentityMatches`, `oracleSelfConsistent`, `networkOnlyCellular`, and the
  four `pipeline*Available` flags. This is the measurement four turns have failed to obtain.
- **AA4 — D2 becomes reachable; run it.** With the sphere's products retained, execute D2 and localize
  `CellularityNotEstablished` to site **419**, **437**, or **474** per the X2 plan §3, with the term-by-term
  comparison of oracle counts against producer counts required by Y2/Y3. **`M3-CP4c2-TB-X2-CAND-04` has been
  unlocalized for five turns; this measure exists to end that.**
- **AA5 — the duplicate.** Emit each witness's record exactly once. The accumulated assertion message must
  reference failing witnesses by **name and status only** — it must not restate a record already written to
  stdout. Publish the per-witness record count so the contract is machine-checkable rather than eyeballed.
- **AA6 — surface what was already measured.** The torus's per-component `χ` and boundary-cycle counts exist in
  `d1-records.json` but never reached a report. Publish them for every witness. **Predicted for the torus: four
  components, each `χ = 0` with two boundary cycles — four annuli.** If they are not annuli, say so
  prominently; it would refute DEFN prediction 2 and is material.
- **AA7 — classify the torus's remaining failure, do not fix it.** Publish the torus's
  `terminalFailureCode=NotProductionReady` / `terminalFailureStage=tracing` with whatever locus is available,
  and state explicitly that it is **downstream of A2b and outside CP4c-2's scope**. Open a candidate for it.
  **Do not attempt to fix it in this checkpoint.**
- **AA8 — pay for the `src/` change.** Because AA1 touches production, the successor TB must re-prove the
  accepted prefixes **316/316, 346/346, 353/353 and 355/355** before any CP4c-2-local identity is credited.
  Report them separately. **A regression in any accepted prefix is a stop and reverts AA1**, not something to
  reason around. This cost is real and is the price of AA1; it is largely absorbed because the eventual CP4c-2
  gate re-proves those prefixes anyway.
- **AA9 — prohibited.** Any `src/` or `include/` change beyond AA1's snapshot placement; touching
  `SurfaceCutGraph`'s logic or `proves_cellularity()`; changing or inventing selectors; running a cumulative
  gate before AA8's prefixes are green; encoding `48/48`, the sphere outcome, or any expected value as a
  constant, special case, or witness-name branch; defining cellularity as `cut_edges().empty()`; any oracle
  call into `SurfaceCutGraph`; any test-only injection path into A2b or weakening of `make_from_candidate`;
  weakening `build_cp4c_production_fixture`'s preconditions; adding a fourth witness idiom; fixing the torus's
  post-A2b `tracing` failure; touching the mechanical witness, C2, or CP4c-3.

## 8. Falsifiable predictions

1. After AA1 the prescribed sphere retains `sourceTopologyRegions`, `fieldTransportAtlas` and
   `fieldAlignedCurveNetwork`, with `surfaceCutGraph` and `globalTopologyPlan` still absent — its failure is
   genuinely at A2a′.
2. The sphere's network is **already cellular** under the barrier complex: every component a disc **and**
   `V − E + F = 2`. *(This is DEFN prediction 5 and X2 plan prediction 1, still unadjudicated after five
   turns. It is the load-bearing uncertainty of the entire checkpoint.)*
3. If prediction 2 holds, D2 localizes to site **474**, the global certificate — sites 419 and 437 being
   unreachable when `alreadyCellular` is true — and the producer's `faceCount` differs from the oracle's while
   the per-component disc verdicts agree, confirming the coarsening hypothesis.
4. The torus's four components are **annuli**: `χ = 0`, two boundary cycles each.
5. AA8's accepted prefixes stay green: AA1 changes observability only.
6. Branch **A** is selected and the gate resolves to **357**. **Do not act on this before AA4 reports.**

Predictions 1 and 5 gate the mechanics. Prediction 2 is the one that matters and is genuinely uncertain.

## 9. Lesson recorded

**A result that discharges a checkpoint's premise must be reported as a finding, not left as a field value.**
The torus's `pipelinePlanAvailable=true` — the single most consequential fact produced by this arc, since it
shows the DEFN's cut graph doing exactly what it was designed to do — appeared in the EXEC evidence only as one
boolean in a list of four, under a verdict of "semantic red". A turn that stops on a contract violation must
still say what its evidence *established*, not only what blocked it. To be added to `LESSONS.md` §1 by the
successor CB.

## 10. Stop / successor

The exact next turn is **`M3-CP4c-2-CB3-DIAG`**, Code + Build, runtime-free, under measures **AA0–AA9**, with
`src/` opened **only** for AA1's snapshot placement.

Its successor is `M3-CP4c-2-TB-X2-R5`, artifact-only, which must satisfy AA8's accepted-prefix re-proof, then
AA2/AA3/AA6/AA7, then AA4's D2 localization. `selected_r2_branch` remains **NONE**, `selected_gate` remains
**NONE**, and `gate_execution_authorized` remains **false**.
