# M3-CP4c-2 TB-X2-PLAN — evidence plan for the frozen 357/358 decision

## 0. Turn type and verdict

`M3-CP4c-2-TB-X2-PLAN` is **COMPLETE / PLANNING-ONLY**.

No Directional runtime, compile, package, benchmark, or product/test/fixture/selector change was made. Both
frozen candidate selectors remain byte-frozen and neither is selected. This document specifies the evidence a
successor must produce so that the frozen 357/358 rule can be applied, and it names the exact turn that produces
each piece.

`M3-CP4c-2-TB-X2-REV`'s stop is upheld: the X2 evidence fits neither branch, and inventing a third branch or
editing a candidate selector remains prohibited.

## 1. Why X2 could not answer its own question — the structural cause

The review localized the symptom. The cause is a single design error in the diagnostic, and it must be
understood before the successor is written, because the obvious repair reproduces it.

`tests/FieldAlignedCurveNetworkTests.cpp::observe_cp4c_witness` calls `SurfaceCutGraph::make` **first**, and
every downstream publication is gated behind that call succeeding. So when A2a′ fails, the identity publishes one
error code and returns. Two consequences, both fatal to the frozen decision rule:

1. **The network-only cellularity fields are unreachable on exactly the input that needs them.** They are emitted
   only after a cut graph exists.
2. **`networkAlreadyCellular` is defined as `cutGraph.cut_edges().empty()`.** That is not a measurement of the
   network's complement; it is a restatement of what the producer decided. It is an oracle built on the
   mechanism it tests — the anti-pattern `LESSONS.md` already names — and it would remain wrong even if the
   gating were fixed.

**The rule the successor must follow: the cellularity oracle must not call, link against, or reuse any part of
`SurfaceCutGraph`.** It must derive `V`, `E`, `F`, and `χ` from the source topology and the immutable network
alone.

Note the deliberate asymmetry with `M3-CP4c-2-DEFN` measure X3, which told the *producer* to reuse A2b's
component traversal rather than duplicate it. That instruction was about the **producer**, where a second
implementation risks divergence. This instruction is about the **oracle**, where a second implementation is the
entire point. They are not in conflict; if the implementation agent perceives one, this paragraph governs.

## 2. Deliverable D1 — independent network-only cellularity evidence

**Question:** with **no cuts at all**, is the prescribed-sphere network already a cellular embedding of the
source surface?

**Method — all of it independent of `SurfaceCutGraph`:**

1. Compute the source Euler characteristic directly from the source topology: `χ_source = |V| − |E| + |F|`.
   Publish all four numbers. For the prescribed sphere the expected value is **2**.
2. Compute the complementary components of the network **using an oracle traversal written for this purpose**,
   not by calling the producer.
3. For each component, publish its Euler characteristic and its boundary-cycle count, and the disc verdict
   `χ == 1 ∧ boundaryCycles == 1`. **Both conditions must be published separately** — an annulus has `χ == 0`,
   and a disc is distinguished from a sphere-with-two-holes only by the second.
4. Publish the count of components that are discs and the count that are not, and for every non-disc component
   publish one representative `sourceFace` so it can be found again.
5. Publish the verdict `networkOnlyCellular = (every component is a disc) ∧ (V − E + F == χ_source)`, **with
   `V`, `E`, and `F` each published as a number and each accompanied by a one-line statement of what was
   counted.** See §4: the definition of these three counts is where the current producer is most likely wrong,
   so an unlabelled number is not evidence.

**Non-negotiable:** D1 must publish its result on the prescribed sphere **whether or not `SurfaceCutGraph`
succeeds**, and must not construct a `SurfaceCutGraph` at all.

**Witness set:** prescribed sphere (the decision witness), torus (the control — expected non-cellular, and the
witness the DEFN theorem covers), two-ring (a second control that already produces traces and barriers).

## 3. Deliverable D2 — exact cut-graph failure localization

`SurfaceCutGraphErrorCode::CellularityNotEstablished` is returned from **four** distinct sites, three of which
are reachable on the production path. One code, several mechanisms — the review is right that the existing
evidence cannot distinguish them.

| Site | Condition | Locus attached today |
|---|---|---|
| `SurfaceCutGraph.cpp:419` | a non-disc component for which `tree_cotree_cut_edges` returned `nullopt` or empty | `sourceFace` |
| `SurfaceCutGraph.cpp:437` | after cuts are applied, a final component still fails `proves_disc_topology()` | `sourceFace` |
| `SurfaceCutGraph.cpp:474` | the **global** certificate `proves_cellularity()` fails | **none** |
| `SurfaceCutGraph.cpp:529` | `make_from_candidate` mismatch fallback | n/a — tamper path, not production |

**D2 must determine which site fired, and it must do so without a product change**, by independent
re-derivation from D1's oracle plus the published error:

- if D1 reports one or more **non-disc** components, sites 419 and 437 are live candidates, and the published
  `sourceFace` distinguishes them: 419's face is a component that was non-disc *before* cutting; 437's is one
  that is still non-disc *after*;
- if D1 reports **every component is a disc**, then `alreadyCellular` is true, the cut set is empty, sites 419
  and 437 are both unreachable by construction, and **the failure is necessarily site 474** — the global Euler
  identity, not the topology.

That last line is the sharp one. It converts a vague "the producer failed" into a decidable statement, and it
requires no new production code.

**D2 must additionally publish, from the producer's own certificate when one is available and from the oracle
when it is not:** `vertexCount`, `edgeCount`, `faceCount`, `eulerCharacteristic`, `sourceEulerCharacteristic`,
and the per-component disc verdicts. When the producer fails at 474 it publishes no certificate, so **the
successor must publish the oracle's counts alongside a re-derivation of what the producer would have computed**,
so the two can be compared term by term. A single boolean is not localization.

If, and only if, D2 cannot distinguish the sites from published data — for instance if 474 fires while D1 also
reports a non-disc component — then a **minimal, additive product change is authorized**: split
`CellularityNotEstablished` into distinct typed codes per site, or attach a locus at 474. That change is
diagnostic-only, must not alter any accept/reject decision, and belongs to the corrective CB, not to a TB.

## 4. The leading hypothesis for site 474, and how to refute it

This is a hypothesis for the successor to test, **not a finding**. It is stated because an unaimed measurement
is how X2 was wasted, and because if it is right it changes what the corrective turn does.

`proves_cellularity()` requires `eulerCharacteristic == sourceEulerCharacteristic`, where the producer computes:

- `graphVertices = network.nodes().size() + addedVertices.size()`
- `graphEdges = network_edge_count(network) + cuts.size()`
- `graphFaces = finalCertificates.size()` — the number of **source-face components separated by `barriers`**

and `barriers = network_barriers(network)` collects, for every trace segment, its `outgoingCarrier` and
`incomingCarrier` — that is, **whole source edges**.

**The suspected defect is a unit mismatch.** `V` and `E` are counted in the network's own abstract graph, whose
arcs are traces that cross face *interiors*. `F` is counted in a partition of source faces cut along **whole
source edges**. A trace crossing a triangle turns two of that triangle's three edges into barriers, which
separates faces the trace does not actually separate. The two counts therefore describe **different complexes**,
and `V − E + F == χ` between them is not an identity — it holds only by coincidence.

**Why this would have stayed invisible until now:** the torus has **zero traces**, so `network_barriers`
degenerates to the mandatory edges, which really are whole source edges. No coarsening occurs and the accounting
is self-consistent. The defect can only appear on a witness that has traces — and the prescribed sphere, with 24
traces and 56 events, is the first such witness to reach A2a′. This is the same shape as the ordinal-13 trap and
the C5 torus recurrence: **the witness the design reasoned about is not the witness that exercises the code.**

**How to refute it.** D1's oracle counts and the producer's counts are both published; compare them term by
term. If `F` differs between the oracle and the producer while the per-component disc verdicts agree, the
coarsening hypothesis is confirmed. If they agree and `eulerCharacteristic` still differs from `χ_source`, the
hypothesis is refuted and the defect is in `network_edge_count` or in `addedVertices` instead — both of which
must then be published in their decomposed form.

## 5. Deliverable D3 — post-certificate A2b observation

**Question:** once a *certified cellular* embedding is supplied, does the sphere's `RotationSystemInconsistent`
persist or disappear?

This is the deliverable that cannot be scheduled unconditionally, and the plan must say so plainly rather than
pretend otherwise. **D3 is reachable only when a certified cut graph exists for the sphere.** Three branches,
with the action fixed in advance:

- **Branch A — D1 says the network is already cellular, D2 localizes to site 474.** The producer is wrong, not
  A2b. The corrective CB fixes the accounting so that an already-cellular network yields an **empty cut set and
  a passing certificate** — which is measure **X6**, idempotence, from the frozen DEFN. That fix unblocks the
  normal production path, and D3 is then observed through it with no backdoor. **This is the expected branch.**
- **Branch B — D1 says the network is genuinely non-cellular.** Then A2a′ is being asked to do real work on the
  sphere and is failing at 419 or 437. The corrective CB fixes the cut construction, and D3 follows on the
  normal path.
- **Branch C — the sphere is cellular and the accounting is correct, yet 474 still fires.** Then the hypothesis
  in §4 is refuted and something unmodelled is happening. **Stop and route to review**; do not proceed to D3.

**Explicitly prohibited: building a test-only injection path that hands A2b a cut graph the producer did not
produce.** `make_from_candidate` is a tamper-rejection path — it recomputes the canonical candidate and rejects
anything that differs — so it cannot be used to inject an alternative cut set, and it must not be weakened to
allow it. A backdoor would make the eventual A2b observation unfalsifiable, because the thing observed would not
be the thing production builds. If D3 is unreachable, **report it as unreachable and stop.** An unreachable
measurement honestly reported is worth more than a reachable one that measures a fiction.

When D3 does become reachable, it must publish: whether a plan was produced; if not, the exact
`GlobalTopologyPlanErrorCode` **and its attached locus**; the region count; and, when regions exist, each
region's certificate `eulerCharacteristic` and `boundaryWalkCount`. `RotationSystemInconsistent` is raised from
many sites in `GlobalTopologyPlan.cpp` — including the 412-564 and 790-839 clusters — so **the code alone is not
localization**; the locus is required.

## 6. Measures **Y0–Y9**

- **Y0 — preconditions.** Accepted authority is CP4c-1 TB-R5 **355/355**, selector
  `e9d88f11…5afeaa` with prefixes `601ce2b6…`, `20d3b0b1…`, `51ff96d7…`. Re-verify all four before and after;
  all four must be byte-identical. Both frozen candidates must be re-hashed and unchanged — recorded here so a
  drift is detectable without trusting a later report:
  **357** = `b896d0db7f26aeb0f3513418405efdeccbcf84fb6dc971500c6ddac9e364dc70` (357 lines);
  **358** = `6eda3aad83de81fc55d5cd446f80704d604a842f10995789b483291bb64fbe62` (358 lines).
  Compile under `GMP_COMPILE_POLICY.md` with GMP/GMPXX.
- **Y1 — D1, the independent oracle.** Per §2, on sphere, torus and two-ring. **The oracle may not call
  `SurfaceCutGraph`.** Every count published with a one-line statement of what it counts.
- **Y2 — D2, localization.** Per §3. Publish which of sites 419/437/474 fired and the reasoning that
  distinguishes it, plus the term-by-term comparison of oracle and producer counts.
- **Y3 — the §4 hypothesis, adjudicated.** State explicitly whether the coarsening hypothesis is **confirmed**
  or **refuted**, naming the numbers that decide it. "Consistent with" is not an adjudication.
- **Y4 — the torus control.** Publish the torus's oracle result. **Predicted: non-cellular, and the DEFN
  theorem's `V=48, E=48, χ=0` reproduced.** If the torus oracle disagrees with the DEFN theorem, **stop** — the
  definition rests on a stale measurement and must be re-adjudicated, exactly as DEFN measure X1 requires.
- **Y5 — branch selection.** Name which of §5's branches A/B/C the evidence selects, and take only that
  branch's action. Do not take two.
- **Y6 — D3 when reachable.** Per §5, with the exact error locus. If unreachable, say so and stop; do not
  substitute an inferred answer.
- **Y7 — the frozen decision.** Apply the frozen rule and publish `selected_gate` as **357**, **358**, or
  **NONE** with the evidence for each conjunct stated separately. **`NONE` remains a legitimate outcome** and is
  preferable to a selection made on partial evidence. A third selector may not be invented and neither
  candidate may be edited.
- **Y8 — accounting.** Carry `M3-CP4c2-TB-X2-CAND-03` (test-authority/measurement-incomplete) and
  `M3-CP4c2-TB-X2-CAND-04` (unlocalized producer failure) to a disposition, or state why each remains open.
  Totals stay **42 / 14 / 28**, debt **5**; update the package count if a package is built.
- **Y9 — prohibited.** Editing any accepted identity or ordinal 1–355; changing either frozen candidate
  selector; inventing a third selector; running the cumulative gate before `selected_gate` is 357 or 358;
  defining cellularity in terms of `cut_edges().empty()`; any oracle that calls `SurfaceCutGraph`; any test-only
  injection path into A2b or any weakening of `make_from_candidate`; widening a certificate condition, adding a
  tolerance, or making `proves_cellularity()` easier to satisfy in order to get past 474; touching the
  mechanical witness, C2, or CP4c-3.

**On the last of those.** The tempting repair for site 474 is to relax `proves_cellularity()`. That would
convert a real accounting defect into a silently-wrong certificate and would destroy the only guarantee A2a′
exists to provide. The certificate condition is correct; if the counts do not satisfy it, **the counts are
wrong.** Fix the counts.

## 7. Turn sequencing

The three deliverables do not belong to one turn, and forcing them into one is what produced an unusable X2.

1. **`M3-CP4c-2-CB2-DIAG`** — Code + Build, runtime-free. Implements the D1 oracle and the D2 localization as
   **non-gating** diagnostic identities. Adds the split error codes from §3 only if §3's condition for them is
   met. No production accept/reject behavior changes.
2. **`M3-CP4c-2-TB-X2-R2`** — artifact-only. Executes the diagnostics, publishes Y1–Y4, and selects a branch
   under Y5. This turn does **not** run the cumulative gate.
3. **`M3-CP4c-2-CB3`** — the corrective build for whichever branch Y5 selected.
4. **`M3-CP4c-2-TB-X2-R3`** — observes D3 on the normal path and applies Y7's frozen decision.
5. **`M3-CP4c-2-TB-GATE-EXEC`** — the cumulative gate, only once `selected_gate` is 357 or 358.

Steps 1–2 may not be merged. Step 3 may not begin before Y5 names a branch.

## 8. Falsifiable predictions

1. The prescribed sphere's network **is** already cellular: every complementary component is a disc, and the
   oracle's own `V − E + F == 2`.
2. The producer's failure is therefore at **site 474**, the global certificate, with sites 419 and 437
   unreachable because `alreadyCellular` is true and the cut set is empty.
3. The producer's `faceCount` **differs** from the oracle's face count, while the per-component disc verdicts
   **agree** — confirming the §4 coarsening hypothesis.
4. The torus oracle reproduces `V = 48`, `E = 48`, `χ = 0` and reports non-cellular, matching the DEFN theorem.
5. Branch **A** is selected, and after the accounting fix the sphere's cut set is **empty** with a passing
   certificate — DEFN measure X6, idempotence, satisfied.

Prediction 1 is the one that carries the frozen decision, and it is genuinely uncertain: it is the same
proposition as DEFN prediction 5, which remains unadjudicated. **If prediction 1 is false, branch B applies and
prediction 5 of the DEFN is refuted — which is a good outcome, not a failure of this plan.** Predictions 2 and 3
are conditional on 1 and are the ones most likely to be wrong on their own terms.

## 9. Stop / successor

The exact next turn is **`M3-CP4c-2-CB2-DIAG`**, Code + Build, runtime-free, implementing D1 and D2 as
non-gating diagnostics under measures **Y0–Y9**.

`M3-CP4c-2-TB-GATE-EXEC` remains **not authorized**. `selected_gate` remains **NONE**. Both frozen candidate
selectors remain byte-frozen and unselected.
