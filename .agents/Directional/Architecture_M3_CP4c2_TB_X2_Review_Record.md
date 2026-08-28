# M3-CP4c-2 TB-X2-REV Review Record

## Scope and boundary

`M3-CP4c-2-TB-X2-REV` reviews only the immutable evidence already produced by
`M3-CP4c-2-TB-X2-EXEC`. No Directional runtime, compile, benchmark, package regeneration, source/test/fixture/
selector/build-logic mutation, or corrective implementation design occurred in this review.

The frozen decision rule is the one in
`Architecture_M3_CP4c2_TB_Artifact_Only_Test_Benchmark_Plan.md`:

- select **357** only if the prescribed-sphere network is already cellular **and**
  `RotationSystemInconsistent` persists with a certified cellular embedding;
- select **358** only if non-cellularity caused that failure **and** the failure disappears once a certified
  cellular embedding is supplied;
- if the evidence fits neither branch, **stop before gate execution and route to planning/review**. A third
  selector may not be invented and neither frozen candidate may be edited inside TB.

## Reviewed immutable authority

- semantic/test source executed by X2: `93d9d49f052fa481bd3a8ad8c9bf31eccda7705c`;
- immutable GMP package: `9696201700` /
  `af3ebe2efaab66fed70de8d954cb5615abd9428f401ea974dffe1e14577c8097`;
- authoritative X2 run/job: `33199227974 / 98944212158`;
- X2 result/log artifacts: `9697052371 / 9697052810`;
- result/log digests:
  `524534f76d99500c91e921d81d9d38bc6f8607f379500cd976d0c9fa8600f22b /
  916fa2478d9bd3fc5ba42e3dd670c7373ed3e26a6fcc721a733063da42161719`;
- immutable preflight/postflight: PASS; configure/compile/relink/repair/generated-discovery/mutation: all false;
- current static-review snapshot run/job: `33205468604 / 98965263201`, artifact `9699477568`, snapshot SHA
  `661a4501ea0b3b3de39c5a8747044a252e370709`. The only difference from the pre-review branch authority
  `447cc493ab31da2b2f281a3f7ba04aea31ca417c` is the source-snapshot trigger control commit.

The raw X2 publication is retained verbatim in
`Architecture_M3_CP4c2_TB_X2_EXEC_Artifact_Only_Evidence.md`. It reports a valid prescribed-sphere source
(`χ=2`, boundary-loop count 0, genus 0), a produced field atlas and field-aligned network (24 traces / 56 events),
then stops at `surface-cut-graph/CellularityNotEstablished` before any `GlobalTopologyPlan` is produced.

## Evidence review

### 1. Execution evidence is trustworthy

The corrected X2 execution selected exactly the one frozen report-only identity, used the immutable CB1 GMP
package, materialized the exact packaged source at the compiled fixture root, and passed immutable preflight and
postflight. The earlier startup and fixture-root controls remain orchestration-only and are not semantic evidence.
There is no basis to discard or reinterpret the authoritative raw publication.

### 2. X2 did not measure its frozen first predicate

The frozen definition requires X2 to publish whether **the network alone** is already a cellular embedding,
including the `V-E+F==χ==2` evidence. Static re-derivation of
`tests/FieldAlignedCurveNetworkTests.cpp::observe_cp4c_witness` shows that the observation first calls
`SurfaceCutGraph::make`. If that call fails, the function returns immediately after publishing only the cut-graph
error code.

The fields named `networkAlreadyCellular`, `cutGraphV/E/F/chi`, and `sourceChi` are emitted only **after** a
`SurfaceCutGraph` has successfully been built. Moreover, `networkAlreadyCellular` is defined as
`cutGraph.cut_edges().empty()`, not as an independent certification of the network-only complement. Therefore the
authoritative publication contains no network-only `V/E/F` cellularity result and cannot establish the first
predicate of either frozen branch.

### 3. X2 did not measure its frozen second predicate

The same observation constructs `GlobalTopologyPlan` only after `SurfaceCutGraph::make` succeeds. On the
prescribed sphere the cut-graph producer returned `CellularityNotEstablished`, so the observation returned before
A2b. It therefore did not test whether `RotationSystemInconsistent` **persists** after a certified cellular
embedding, nor whether that failure **disappears** after such an embedding is supplied.

The publication also does not satisfy DEFN X2's requirement to report the **exact failing site**. The diagnostic
serializes only `surfaceCutGraphError=CellularityNotEstablished`. Static source has multiple ways to return that
same code: failure to obtain non-empty tree-cotree cuts for a non-disc component, a final component that still
fails the disc certificate, or failure of the final global cellularity certificate. Some paths attach
`sourceFace`; the X2 report does not serialize it, and the final global-certificate path has no such localization.
The existing evidence cannot distinguish these mechanisms.

## Frozen branch adjudication

| Frozen branch | Required evidence | Review result |
|---|---|---|
| 357 | network alone cellular; certified embedding supplied; `RotationSystemInconsistent` persists | **NOT ESTABLISHED** — neither network-only cellularity nor post-certificate A2b behavior was measured |
| 358 | non-cellularity caused the prior failure; certified embedding supplied; `RotationSystemInconsistent` disappears | **NOT ESTABLISHED** — a cut-graph failure was observed, but causality and post-certificate A2b behavior were not measured |

**Decision:** `selected_gate=NONE`; `gate_execution_authorized=false`.

The X2 evidence fits **neither** frozen branch. Under the frozen TB plan, execution must stop here. Candidate 357
and candidate 358 remain byte-frozen but neither is selected. `M3-CP4c-2-TB-GATE-EXEC` is **not authorized**.
Prediction 5 remains unadjudicated rather than being declared true or false from incomplete measurement.

## Finding classification

1. **X2 diagnostic/test-authority defect — measurement incomplete, non-stable.** The report-only identity is
   structurally unable to answer its own frozen two-part decision when `SurfaceCutGraph` fails, because both the
   network-cellularity publication and the A2b observation are gated behind successful cut-graph construction.
   This resolves `M3-CP4c2-TB-X2-CAND-03` as test-authority/measurement-incomplete, not as a stable product
   regression.
2. **Prescribed-sphere `SurfaceCutGraph` failure — product candidate, unlocalized, non-stable.** The valid witness
   reaches source topology, atlas, and a 24-trace/56-event network, then the new A2a′ producer fails closed with
   `CellularityNotEstablished`. This is material product evidence, but the current diagnostic does not localize
   which failure path/certificate condition caused it. It is tracked separately as
   `M3-CP4c2-TB-X2-CAND-04`; no implementation root cause is claimed in this review.

Stable accounting remains **42 events / 14 categories / 28 recurrences**. Produced-witness debt remains **5**.
M3 packages remain **58**. CP4c-2 has no accepted runtime authority, so neither finding establishes loss of an
accepted-green behavior.

## Evidence gap that the next plan must close

Before a frozen selector can be selected, successor evidence must be capable of establishing all of the facts the
current X2 omitted: an **independent network-only** cellularity result with its `V/E/F/χ` proof; exact localization
of any `SurfaceCutGraph::CellularityNotEstablished` failure; and, once a certified cellular embedding is actually
available, whether `RotationSystemInconsistent` persists or disappears at A2b with its exact failure site. The
planning turn owns how to obtain that evidence; this review does not design or implement the correction.

## Exit

`M3-CP4c-2-TB-X2-REV` is **COMPLETE / STOP — EVIDENCE FITS NEITHER FROZEN BRANCH**.

Exact next turn: **`M3-CP4c-2-TB-X2-PLAN`**, loading `references/turns/TB-PLAN.md`. No cumulative gate runtime,
selector choice, source/test/fixture mutation, or Code + Build work is authorized before that plan is completed.
