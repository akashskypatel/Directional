# M3-CP4c-2 TB-X2-R5-REV Independent Review and Replan

## 0. Verdict

`M3-CP4c-2-TB-X2-R5-REV` is **COMPLETE / REVIEW GREEN / ACCEPTED PRODUCT REGRESSION CONFIRMED / DEFINITION REPLAN REQUIRED**.

The R5 semantic red is admissible for regression diagnosis and planning despite the missing postflight. It is **not** acceptance evidence, and the missing postflight must not be inferred.

The accepted-prefix failure at ordinal 305 is a real product regression introduced by CP4c-2's `SurfaceCutGraph` authority, not by CB3's AA1 snapshot-publication change and not by the accepted witness. The initiating defect is an `RP-01 / AUTHORITY_DOMAIN_CONFLATION` recurrence: CP4c-2 represents the complement with a **whole-source-face/source-edge-barrier proxy** even though CP4ab had already established that the actual embedded graph requires **face fragments/orbits** when trace arcs cross face interiors.

On the exact accepted two-ring witness, the mismatch is decisive:

- accepted embedded-network authority: **`V=9`, `E=11`, `F=3`, `χ=1`**;
- source-edge-barrier proxy measured in R4: **`V=10`, `E=11`, `F=2`, `χ=1`**;
- current `SurfaceCutGraph` final certificate mixes **network `V/E = 9/11`** with **proxy `F = 2`**, producing `0 != source χ 1` and returning `CellularityNotEstablished`.

That arithmetic pinpoints the accepted ordinal-305 failure at the final global certificate (`SurfaceCutGraph.cpp:473-474`) on this witness. More importantly, merely changing the global certificate to use `10/11/2` would make the arithmetic green while certifying the **wrong semantic object**. That correction is therefore explicitly rejected.

The prior R2 review's statement that the source-edge barrier complex is the normative CP4c-2 complex, and that trace-vs-carrier coarsening is only a quad-quality concern, is **withdrawn**. R5 plus retained CP4ab evidence proves it is a correctness/authority issue.

The stable regression is promoted as **`PR8-R043 / M3-CP4c2-R001`**, category `AUTHORITY_DOMAIN_CONFLATION`, pattern `RP-01`, **ACTIVE**. Stable accounting advances from **42 / 14 / 28** to **43 events / 14 categories / 29 recurrences**. Produced-witness debt remains **5** and M3 packages remain **62**.

The exact successor is **`M3-CP4c-2-DEFN-R1`**, definition/replanning only, under measures **AB0–AB9** in §8. No product/test/fixture/selector mutation, build, package, or Directional runtime is authorized by this review.

`selected_r2_branch=NONE`; `selected_gate=NONE`; `gate_execution_authorized=false`.

## 1. Review authority and evidence admissibility

Review source authority is semantic/test source `76d757aab0ce18df09ce2823302d2dc224965187`, package `9708324052` (`sha256:48e01cea66817525766566a1145b92beb22dbb847e4211629fe4c3373d23ff7a`), and R5 run/job `33232106030 / 99046593525` with result/log artifacts `9708817991 / 9708818239`.

R5 proved before runtime that the package, semantic source, GMP/GMPXX backend, and all six frozen selector hashes were exact. It then ran one accepted identity per fresh process: ordinals 1-304 passed and ordinal 305 selected exactly once and failed. The preserved raw row is:

```text
accepted\t305\tGlobalTopologyPlan.DerivesRegionsAsFacesOfTheEmbeddedNetworkGraph\tdirectional_surface_cell_producer_tests\t1\tSELECTED_ONE
```

The raw ordinal-305 log first reports `CellularityNotEstablished` from `SurfaceCutGraph::make`, then the helper throws `std::get: wrong index for variant` because its non-fatal `EXPECT_TRUE(built)` is followed by `built.value()`. The exception is downstream fallout and not the initiating failure.

### 1.1 Missing postflight does not erase the semantic failure

The R5 shell helper incorrectly re-enabled `set -e`, causing the shell to exit before planned semantic-summary and recursive postflight files were emitted. That is a real orchestration defect and is recorded separately in §7. It prevents any claim that R5 post-runtime mutation inventories passed.

It does **not** make the ordinal-305 semantic observation indeterminate:

1. immutable package/source/selectors/GMP authority was established before the first Directional process;
2. the exact one-process raw log and process-result row for ordinal 305 are complete;
3. the failure occurs deterministically inside the accepted test before any CP4c-2-local diagnostic is reached;
4. independent static source plus retained accepted CP4ab evidence reproduce the semantic contradiction without relying on a missing postflight assertion.

**Adjudication:** R5 is admissible to establish an accepted-behavior regression and to plan its correction. It remains inadmissible as acceptance evidence, as mutation/postflight proof, or as evidence for AA2/D1/D2/357/358/cumulative-gate outcomes that never ran. No no-new-semantics recovery run is required merely to rediscover the same regression.

## 2. The accepted witness is authoritative and previously green

Ordinal 305 is not a new CP4c-2 diagnostic. It is the accepted `GlobalTopologyPlan.DerivesRegionsAsFacesOfTheEmbeddedNetworkGraph` identity carried forward from CP4ab/CP4c-1 authority.

At CP4c-1 source `b1ce8ad65952bd2bd76238f6dfc55523f6a24747`, its shared helper built `GlobalTopologyPlan` directly from source authority plus the accepted `FieldAlignedCurveNetwork`, and CP4c-1 closed **355/355**. CP4c-2 rewired that helper to construct `SurfaceCutGraph` first and pass it to `GlobalTopologyPlan`; ordinal 305 now fails before the plan is built.

The witness is the accepted CP3b two-ring event fixture, not a new approximation or reconstructed stand-in. It remains the same fixture used to establish the CP4ab embedded-graph representation. Therefore the red is loss of previously accepted behavior, not a witness-capability dispute.

## 3. Retained CP4ab evidence already disproved whole-source-face ownership

This checkpoint does not begin from an unknown representation question. `PR8-R042 / M3-CP4b-R001` already established the exact opposite of CP4c-2's current construction premise.

On this same accepted two-ring witness, retained CP4ab measurement reports:

- `drafts.size() = 3` embedded graph-face drafts;
- `cutComponents.size() = 2` whole-source-face cut components;
- `walk.orbits.size() = 4`, exactly one of them exterior;
- the singular-fan source faces collapse into one whole-face component even though the rotation walk exposes multiple graph-face sectors.

That is why CP4ab replaced whole-source-face ownership with `(SourceFaceTopologyKey, orbit)` fragments and closed `PR8-R042 / RP-01`. `LESSONS.md` 22d and 22e preserve the resulting rule: a source face cannot be the atomic ownership unit when trace arcs cross its interior, and every consumer must move with the representation.

CP4c-2's frozen DEFN §5.4 step 1 subsequently directed the implementation to compute complement components by whole source faces separated by mandatory or trace-touched **source edges** and explicitly called this the existing producer representation. That guidance resurrected the representation class CP4ab had already rejected.

**Reviewer finding:** the contradiction is in the CP4c-2 construction guidance and its implementation, not in the high-level `DESIGN.md` contract. `DESIGN.md` still correctly requires A2a′ to certify the actual immutable field-aligned network plus added cuts as a cellular embedding.

## 4. Exact product mechanism and ordinal-305 failure

The current `SurfaceCutGraph` implementation has two incompatible semantic domains in one certificate.

### 4.1 Proxy complement construction

`network_barriers(...)` (`SurfaceCutGraph.cpp:109-120`) inserts:

- every mandatory source edge; and
- every trace segment's incoming/outgoing **source carrier edge**.

`build_components(...)` (`:122-134`) then partitions **whole source faces** by treating those source edges as barriers. `certify_component(...)` (`:142-248`) computes Euler/boundary certificates for those source-face components.

A carrier edge touched by a trace is not thereby an edge of the actual embedded field-aligned graph. When a trace crosses a triangle interior, replacing the trace by its carrier source edges changes the graph and changes the complement. The proxy can be internally consistent and still describe the wrong object.

### 4.2 Final certificate switches complexes

After the proxy components pass their disc tests, the final global certificate (`:444-474`) computes:

- vertices from `network.nodes().size()` plus new cut endpoints;
- edges from `network_edge_count(network)` plus cut edges;
- faces from `finalCertificates.size()`, i.e. the **whole-source-face proxy component count**.

That is a direct mixed-complex Euler equation.

### 4.3 Exact accepted two-ring arithmetic

The accepted two-ring network has 9 nodes. Its actual embedded-network edge accounting is 11. Retained CP4ab face/orbit authority gives three interior graph-face drafts. Therefore the actual embedded graph satisfies:

```text
V - E + F = 9 - 11 + 3 = 1 = source χ.
```

R4's independent `sourceEdgeBarrier` diagnostic on the same witness instead reports:

```text
barrierV = 10
barrierE = 11
barrierF = 2
10 - 11 + 2 = 1 = source χ
```

Both equations are self-consistent because they describe **different complexes**.

Current `SurfaceCutGraph` combines them:

```text
network V = 9
network E = 11
proxy F   = 2
9 - 11 + 2 = 0 != source χ 1
```

R4 additionally reports both proxy components as discs, so on this witness `alreadyCellular=true`, no cuts are selected, and the per-component final disc check passes. Static control flow therefore reaches the final `proves_cellularity()` check at `SurfaceCutGraph.cpp:473-474`, where the mixed equation rejects.

**Localization:** ordinal 305's `CellularityNotEstablished` is statically localized to the final global certificate for the accepted two-ring witness. This is review/static localization, not a claim that R5 executed D2; D2 did not run.

## 5. Why the apparent one-line fix is prohibited

Changing the final certificate to use the proxy's `barrierV/barrierE/barrierF = 10/11/2` would make the two-ring green. It would also certify the wrong object.

The normative object is `FieldAlignedCurveNetwork ∪ SurfaceCutGraph.cutEdges`. A trace through a triangle interior is an embedded graph arc. Its incoming/outgoing carrier edges are source-topology support/provenance; they are not interchangeable with that arc. The source-edge barrier proxy therefore cannot establish that the **actual network complement** is a disjoint union of discs.

This matters beyond global accounting. The proxy per-component `χ` and boundary-cycle tests also operate on whole faces, so replacing only the final `V/E` terms would leave the local disc proof attached to the wrong complement. That would repeat LESSONS 22e: partially convert the representation and fail one level later.

**Rejected correction:** no CB may simply alter `SurfaceCutGraph` global `V/E/F`, redefine `network_edge_count`, or accept the source-edge-barrier proxy as cellularity authority. A definition/replan turn must first freeze one representation for the actual embedded graph and every consumer of its certificate.

## 6. Prior R2 adjudication is withdrawn; diagnostic authority is reclassified

R2 correctly identified that its first D1 oracle mixed network-graph `V/E` with whole-source-face `F`. The subsequent independent review then made a second mistake: it declared `sourceEdgeBarrier` to be the **normative complex** and stated that whole-carrier-edge coarsening was only a quad-quality concern.

That statement is now falsified by accepted evidence. On the exact two-ring:

- actual embedded graph has `F=3`;
- source-edge barrier proxy has `F=2`;
- the difference is sufficient to make accepted ordinal 305 fail when the product mixes the two;
- CP4ab had already shown why those counts differ structurally.

The R4 D1 `sourceEdgeBarrier` oracle is useful for diagnosing that proxy and its arithmetic is self-consistent. It is **not an independent oracle for the proposition “the network is a cellular embedding.”** Self-consistency inside a named complex does not establish that the named complex is the product's normative semantic object.

`M3-CP4c2-TB-X2-R2-CAND-02` therefore remains ACTIVE but is reclassified as **TEST-AUTHORITY / WRONG SEMANTIC COMPLEX / NON-STABLE**. Its closure condition is replaced: a future diagnostic must measure the actual embedded graph/fragment complement by a mechanism independent of `SurfaceCutGraph`, not merely make all three source-edge-barrier witnesses arithmetically self-consistent.

## 7. Candidate dispositions and accounting

| Candidate | R5-REV disposition |
|---|---|
| `M3-CP4c2-TB-X2-R5-CAND-01` | **PROMOTED to `PR8-R043 / M3-CP4c2-R001` — ACTIVE STABLE PRODUCT REGRESSION / `RP-01`.** Previously accepted ordinal 305 is rejected because CP4c-2 conflates actual embedded-network authority with the whole-source-face barrier proxy. |
| `M3-CP4c2-TB-X2-R5-ORCH-01` | **NEW / ACTIVE / ORCHESTRATION / NON-STABLE.** `run_identity` leaks/re-enables caller `errexit`, so the first red process suppresses planned postflight/finalization. Future runtime harness must preserve/restore shell state or execute postflight from an unconditional finalization/trap path. |
| `M3-CP4c2-TB-X2-R2-CAND-02` | **ACTIVE / TEST-AUTHORITY / WRONG SEMANTIC COMPLEX / NON-STABLE.** Source-edge-barrier arithmetic is coherent but is not an oracle for actual network cellularity. Requires an actual embedded-graph/fragment oracle. |
| `M3-CP4c2-TB-X2-R4-CAND-01` | **ACTIVE / RUNTIME PENDING.** AA2 is now independently discharged: the two prescribed-sphere lines in R4 `d1-records.txt` are both 468 bytes and both SHA-256 `84f9ca015ab63093086981cbd29256526159329c64537dfb52fba9e89d9fd078`; byte-identical is true. AA5 compiled, but R5 stopped before D1, so exactly-once runtime publication is still unproved. |
| `M3-CP4c2-TB-X2-R4-CAND-02` | **LOCALIZED / RUNTIME PENDING.** AA1's snapshot placement remains the correct observability fix. R5 did not reach the sphere, so runtime retention remains unproved. Do **not** revert AA1: §9 shows the accepted regression predates it. |
| `M3-CP4c2-TB-X2-R4-CAND-03` | **ACTIVE / OUT-OF-SCOPE.** Torus downstream tracing remains later than A2b and unchanged by this review. |
| `M3-CP4c2-TB-X2-CAND-04` | **ACTIVE / UNLOCALIZED FOR THE PRESCRIBED SPHERE.** R5 never ran D2. The source-edge-barrier oracle also cannot decide actual sphere cellularity, so a future D2 must use the corrected actual-complex authority. |

### Stable accounting

`PR8-R043 / M3-CP4c2-R001` is one new stable event in existing category `AUTHORITY_DOMAIN_CONFLATION / RP-01`, so it adds one recurrence but no category:

- stable events: **42 -> 43**;
- categories: **14 -> 14**;
- recurrences: **28 -> 29**;
- produced-witness debt: **5** unchanged;
- M3 packages: **62** unchanged.

## 8. Exact successor: `M3-CP4c-2-DEFN-R1` under **AB0–AB9**

This review does **not** authorize a corrective Code + Build. The next turn must freeze the representation before any semantic mutation.

- **AB0 — preserve current authority.** Accepted historical authority remains CP4c-1 `355/355`; R5 establishes the new stable regression but no CP4c-2 runtime acceptance. Preserve all six frozen selector files/hashes and keep `selected_r2_branch=NONE`, `selected_gate=NONE`, `gate_execution_authorized=false`. No runtime/build/package in DEFN-R1.
- **AB1 — reaffirm the normative object.** `SurfaceCutGraph` certifies the actual embedded `FieldAlignedCurveNetwork ∪ cutEdges`. Source-edge carrier provenance is not graph-edge authority unless that source edge is itself a mandatory/cut edge in the combined graph.
- **AB2 — withdraw the stale construction premise.** Supersede CP4c-2 DEFN §5.4 step 1's whole-source-face complement as cellularity authority. Preserve §§5.1–5.3's product/guarantee contract. A source-edge barrier partition may remain only as a proposal/diagnostic mechanism whose semantic limits are explicit.
- **AB3 — one actual-complement representation.** Reuse/refactor the accepted CP4ab face-fragment/orbit representation, or freeze an equivalent exact representation that can express trace arcs crossing source-face interiors. `SurfaceCutGraph`, its local disc certificates, its global `V/E/F`, and `GlobalTopologyPlan` must consume one semantic complex; no partial conversion.
- **AB4 — pre-region purity.** The shared arrangement/complement authority must depend only on source topology, immutable network, and candidate cut edges. It must not inspect or repair an already-produced `GlobalTopologyPlan` region; that preserves DESIGN §7.2's stop boundary.
- **AB5 — exact network-alone idempotence.** Freeze how the actual network alone is evaluated. The accepted two-ring must derive its counts from authority, not constants, and the definition must explain the observed `V=9`, `E=11`, `F=3`, `χ=1` actual embedding. If the representation cannot derive those values without witness-specific logic, stop in DEFN-R1.
- **AB6 — candidate-cut proof.** Freeze how adding allowable source-edge cuts changes the **actual** arrangement and how every resulting complement component is proven a disc. Final global and per-component certificates must be recomputed entirely from the actual combined graph; no proxy face count or proxy disc proof may be mixed in.
- **AB7 — cut-selection completeness.** Tree/cotree or source-face operations may propose cuts, but DEFN-R1 must prove the proposal strategy can terminate and establish cellularity for the actual non-disc components without crossing immutable trace interiors or removing network topology. If that completeness argument cannot be made — especially for the prescribed sphere — **stop at definition** rather than code a heuristic.
- **AB8 — independent test oracle.** Redefine D1/D2 to measure the same actual embedded semantic complex by a mechanism independent of `SurfaceCutGraph`. “Different code over `sourceEdgeBarrier`” is insufficient independence. The oracle must expose actual graph `V/E/interior-F`, fragment/orbit component topology, cut provenance, and term-by-term producer comparison without calling the producer.
- **AB9 — successor discipline.** Preserve AA1/AA5 observability work. Fix R5-ORCH-01 before the next runtime harness. Only after AB0–AB8 are frozen may a bounded semantic `M3-CP4c-2-CB4` be planned; after a green build, the next artifact-only diagnostic is a fresh R6, not a cumulative gate. DEFN-R1 itself must not execute R6, select 357/358, or touch CP4c-3.

### Success criterion for DEFN-R1

The turn is complete only when an implementation agent can answer, without inventing policy:

1. what exact cells/vertices/edges/faces represent `network ∪ cuts` when traces cross triangle interiors;
2. how complement components and their boundary walks are derived before `GlobalTopologyPlan` regions exist;
3. how candidate cuts update that exact representation;
4. how disc topology and global Euler are certified in the same complex;
5. why the cut strategy terminates or, if it cannot be proved, what typed definition stop replaces it;
6. how an independent oracle measures the same semantic object by a different mechanism.

## 9. AA1 is not the cause; the frozen rollback instruction was overbroad

R4-REV measure AA8 said that any accepted-prefix regression in R5 “reverts AA1.” That rollback rule was too broad because it encoded temporal correlation as causality.

Source comparison proves `SurfaceCutGraph.cpp` is unchanged between the pre-AA1 diagnostic source `5ad711e5d4ced95f38e103b993139a6307ba2cee` and R5 semantic source `76d757aab0ce18df09ce2823302d2dc224965187`. The only production `src/` semantic change in that interval is AA1's `RemeshPipeline.cpp` snapshot-publication placement. Accepted ordinal 305 calls `SurfaceCutGraph::make` directly from its helper and fails before pipeline snapshot publication is relevant.

The regression therefore predates AA1 and was merely **exposed** by AA8's accepted-prefix re-proof. AA1 remains a valid observability correction and must not be reverted absent evidence that its own behavior is wrong.

**Process correction:** prefix re-proof is a detection boundary, not an automatic blame boundary. Rollback must follow causal ownership.

## 10. Frozen-definition correction

This review adds a narrow correction note to `Architecture_M3_CP4c2_DEFN_Frozen_Definitions.md`:

- §§5.1–5.3 remain binding;
- §5.4's whole-source-face/source-edge-barrier construction guidance is withdrawn as cellularity authority pending DEFN-R1;
- source-edge-barrier data may be used only as proposal/provenance/diagnostic evidence until AB0–AB8 establish its relation to the actual embedded graph;
- no product change is authorized by the note itself.

This is a correction of stale implementation guidance, not a rewrite of the already-correct high-level DESIGN contract.

## 11. Stop / successor

**Stop here.** `M3-CP4c-2-TB-X2-R5-REV` performs no new Directional runtime and authorizes no immediate product mutation.

Exact next: **`M3-CP4c-2-DEFN-R1`**, definition/replanning only, measures **AB0–AB9**.

Do not start `CB4`, R6, selector 357/358, a cumulative gate, mechanical/C2, or CP4c-3 during this review closeout.
