# P13 FlowRep selection — source-verified probe preflight (2026-11-02)

> **Superseded (2026-11-02):** [RA-199](Architecture_M6_CP3_DEFN_P13_FlowRep_Selection_Probe_Adjudication_20261102.md) ran this DEFN's probes on the Review track's scratch build and closed it: the lenses are unmet support chords (Amendment 31, exact CB78, TB72); cross-face coverage and the degree rule are not the P13-i owner (O25); Vase's next failure is P13-j at assembly → `M6-CP3-DEFN-P13-ASSEMBLY-STITCHED-VERTEX`. This file is kept as history.

**Current turn:** `M6-CP3-DEFN-P13-FLOWREP-SELECTION` (Review/Definition, P13-i).
**Disposition:** diagnostic scratch-probe requirement remains unresolved; **this is not an adjudication, code patch, compile result, benchmark, or promotion**.
**Authority:** RA-198 §§1–2, 6, prior `Architecture_M6_CP3_DEFN_P13_FlowRep_Selection_Invariants_Review_20261102.md`, `REVIEW_TURN_POLICY.md`, `DESIGN.md`, and post-TB71 handoff.

## Evidence boundary

- Exact source snapshot: event/source `d6c9cd6eedc139d96b20bc8b603f133bac3a86ab`, source-snapshot run `41499157285`, artifact `13167672172`, ZIP SHA-256 `613bce01aa731229fa2c5064b2d74155dd41ce79be5fcec794263c5e6b3e6141`. All **6,110/6,110** packaged file checksums and the source archive hash were checked locally. No local build or Directional binary executed.
- Last accepted immutable TB71: **881/881** registered gate, membership **962** with **81 deferred** ledger items; Cylinder PASS, BunnyRandom P13-e RED at source vertex 49, Vase P13-i RED at completion `IncompleteSurfaceCellComplex;side-count-unsupported`. No CP3 promotion. Preserve CP2 **491/491**, stable **66/17/49**, debt **1**, selector **497** unpromoted.
- RA-198 scratch probe F observed **0 of 4,057** accepted removals on Vase. Arithmetic check: **3,904+38=3,942** proposal and **102+13=115** support rejections; **3,942+115=4,057**. Scratch probe G (degree rule alone relaxed) accepted 11 supports, including trace 878, and left four lens failures. This is **prior** scratch evidence, not a new execution.
- The previously published independent static review found that production supplies no `FlowRepArc::substitutions`, so required proposal cycles cannot simply lose an arc. Do not treat generic affinity functions or per-test substitutions as production candidate generators.

## Independent source inspection

1. `src/geometry/FlowRepStrands.cpp`: `sample_and_arc_are_intrinsically_compatible` accepts only identical literal `sourceFace`, `sourceTopologyRegion`, and `sourceIsolationSheet`. `build_coverage_index` bins candidate arcs by the same source face. `normalized_intrinsic_sample_distance` then calls a 3-D point-to-segment distance, **which is only confined to a single source triangle** by the previous predicate; it is not a geodesic solver. Thus shared-edge neighbors cannot cover a disappearing face-local support sample.
2. `protected_endpoint_degrees` captures entire initial degree at all rail/singularity contacts **and any node of degree >= 3**. `preserves_protected_endpoint_degrees` requires exact numerical equality after a trial, rather than just retained mandatory incidence or absence of newly dangling ends. Deleting optional support touching a retained rail is therefore vetoed independently of coverage.
3. `select_sparse_flow_rep_network` evaluates a removal transaction through `coverage_max_distance(index,active)`, `cycle_evaluations_are_valid`, and exact protected-degree preservation; it rolls back on any failed guard. Existing complete proposal cycles are required and cannot be weakened to increase removal count.
4. `src/pipeline/RemeshPipeline.cpp` calls `select_sparse_flow_rep_network` with arcs, coverage samples and cycles, not the source triangle adjacency or chart-transition graph. Genuine cross-face coverage therefore needs **an explicit authoritative transport/metric input** (or a precomputed validated candidate-distance relation), not removal of the literal face check and unrestricted Euclidean proximity.
5. The previous source review identifies initially empty production substitution alternatives, mandatory proposal-cycle authority, and no production invocation of affinity clustering. Preserve those findings as independent constraints; a source-chart-valid endpoint is not proof that two arcs belong to one lattice phase.

## Proposed probe contract (not yet accepted)

**Coverage:** Build candidates by source-topology-region/sheet compatible chart transitions. Allow a neighboring source face only through oriented shared-edge chart transitions that do not cross a source boundary, hard feature barrier or a sheet break. Evaluate intrinsic sample-to-arc distance by a bounded unfolding/walking path or a surface-authoritative shortest-route witness; never compare world-space coordinates across unattested sheets. Keep existing same-face distances as a control. Freeze finite bounds and deterministic tie-breakers before measuring the production matrix. Prove that the expanded relation does not admit opposite-sheet or disconnected-component candidates.

**Endpoint incidence:** Preserve the exact set/order/provenance of mandatory boundary/feature rails and singularity supports, all required port attachments, and all completed proposal cycles. For optional support, permit a degree decrement only if the resulting vertex/link is manifold, no new dangling active end is created, mandatory incidence is untouched, and source-authoritative component/sheet connectivity and index budgets remain valid. A rule based only on `degree>=3` or merely `degree>=1` is insufficient without these structural checks. Enumerate before/after incidence classes, not only total degrees.

**Selection progression:** Treat each accepted removal as a transaction; recompute only affected coverage, cycle and junction witnesses, retain strict fail-closed rollback, and revisit newly admissible optional supports in deterministic order until a fixed point or a proved exhaustion. Do not special-case five trace IDs or accept a whole-fixture geometry solely because removal count increases. Proposal-origin boundary deletion is prohibited without a proven equivalent topology-preserving substitution.

**Falsifiers and counterexamples to pre-register:**
- A nearby arc on another sheet or separated by a hard rail must never cover a sample.
- A removed optional connector must not disconnect a mandatory rail, eliminate a singularity port, open a proposal cycle or create a dangling end.
- Deleting a mandatory or sole coverage-critical arc must fail.
- A valid rail-attached optional support may be removable despite reducing the numeric degree at its contact.
- Face-row/orientation permutations must not change selected network identity or final structural hashes.
- Cylinder accepted output and all existing 881 gate outcomes remain unchanged; BunnyRandom's independent P13-e must not be silently masked.
- If the selector removes supports yet Vase still fails `side-count-unsupported`, obtain the **new exact failure** and decide whether it belongs to selection or a separate owner, rather than promoting a partial solution.

## Required evidence before exact implementation patches

1. Authorized scratch diagnostic executable that is byte-equal to the frozen source except for separately documented probes. Record compiler/backend, source hashes and exact probe deltas. A Review probe is **not** a Test+Benchmark acceptance run.
2. Per-fixture (Cylinder, BunnyRandom, Vase) removal attempts/accepted/rejected by reason, active network structural hashes, selected mandatory incidences, coverage extrema and non-vacuous failed controls.
3. Execute the immutable **881-row gate** and **81-row deferred ledger** for the proposed change in the authorized diagnostic scope; check accepted selector prefix and registered outcomes independently. The existing green gate is a **baseline**, not evidence the new rule passes.
4. On Vase, identify the next earliest terminal and exact cell/descriptor after fixed-point selection. Record whether any remaining two-sided cells are unavoidable or indicate an unmet invariant. No intended success may be inferred from a change of error code.
5. Only after this evidence: freeze a minimal exact code patch and targeted checks for a separate Code+Build turn, then a separate Test+Benchmark turn. No product/test/fixture/selector/benchmark changes are authorized in this Review.

## Continuation / procedural record

This ChatGPT session cannot execute the prerequisite source-mutating diagnostic scratch build under `start.txt`'s **no local build** boundary and the standing Review runtime-free rule. RA-198.6 expressly states a Review turn unable to run its authorized scratch probe does not begin the probe. The required experimental evidence and exact patch are therefore **unresolved**; do not mark this DEFN complete, assign an invented CB successor, or claim source-adjudication success. Previous static Review `Architecture_M6_CP3_DEFN_P13_FlowRep_Selection_Invariants_Review_20261102.md` likewise documented this distinction. A separately authorized scratch execution path is the missing prerequisite; this is **not** a GitHub or Google Drive safety-check rejection.

The initial source/policy inspection used direct document reads before the mandatory snapshot-mode gate; this was a procedural conservation-policy miss. Subsequent source analysis used the one exact verified snapshot. The `review_check.py boundary` attempt on that extracted archive passes source/test/selector change checks but cannot verify Git ancestry, so it is **not a full PASS**. Tool-call ledger was not accurately established at entry; its total/breakdown are partial/unknown, not estimated.

No new runtime results, tests, implementation changes, or selector promotion are claimed.
