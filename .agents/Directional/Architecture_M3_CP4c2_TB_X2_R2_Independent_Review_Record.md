# M3-CP4c-2 TB-X2-R2 Independent Review and Plan

## 0. Verdict

`M3-CP4c-2-TB-X2-R2-REVIEW-PLAN` is **COMPLETE / REVIEW GREEN**.

The R2 control stop is **upheld**, and its Finding 1 is **confirmed**: the frozen `48/48` torus theorem remains
product-authoritative, and R2's mismatch is a diagnostic-authority defect, not product evidence.

The proposed `M3-CP4c-2-CB2-DIAG-R1` is **AUTHORIZED with amendments**, under measures **Z0–Z9**. The
amendments are not cosmetic: **the report's proposed item 3 is the load-bearing one and is currently the least
specified**, and item 4 is correct but for a reason the report does not state.

**The most important finding of this review is not Finding 1.** R2 records a second defect and correctly
declines to adjudicate it. This review adjudicates it: **D1's prescribed-sphere publication is internally
self-contradictory, and it is so by exactly 4.** That is an independent blocker which would have invalidated
Y5 even if the torus control had passed, and it is the defect closest to the original question.

No runtime, build, compile, package, or product/test/fixture/selector change was made in this turn.

## 1. Independent verification of the R2 arithmetic

Every published figure was recomputed rather than accepted:

| Complex | `V − E + F` | reported χ | verdict |
|---|---|---:|---|
| sphere source | `98 − 288 + 192` | 2 | **OK** |
| torus source | `72 − 216 + 144` | 0 | **OK** |
| two-ring source | `11 − 25 + 15` | 1 | **OK** |
| sphere D1 network terms | `18 − 30 + 18` | 6 | **OK** — the arithmetic is right; the *terms* are not |
| torus D1 network terms | `0 − 0 + 1` | 1 | **OK** |
| two-ring D1 network terms | `9 − 11 + 3` | 1 | **OK** |

All three source characteristics are correct, so the source topology reader is sound. The three D1 sums are
internally arithmetically correct. **The defect is in what is being counted, not in the addition.**

## 2. Finding A — the torus control failure, upheld and classified

R2's Finding 1 is confirmed on the evidence it cites, and this review adds the reason it matters and the reason
it went unnoticed.

`cp4c_network_only_fixture(...)` calls `rails_from_atlas(mesh, atlas)`, which converts only the atlas's
`SourceBoundary` / `HardFeature` non-traversable edges into rails. Production instead builds
`AdaptiveFeatureMapBuilder::build(...)` and then `build_authoritative_surface_cell_rails(...)`, and the frozen
DEFN's torus authority — 48 `HardFeature` mandatory edges, 48 structural nodes — comes from that path. D1
therefore did not instantiate the witness whose frozen counts it was required to reproduce. `V/E = 0/0` is the
correct answer to a different question.

**Why it was invisible until the torus.** On the prescribed sphere and the two-ring the two rail authorities
produce the same rails — the sphere is closed with no hard features, so both yield nothing, which is why the
sphere's 24 traces / 56 events match production exactly. The substitution is **detectable only on the one
witness whose rails originate in the feature map**. This is the same shape as the ordinal-13 trap, the C5 torus
recurrence, and the coarsening hypothesis: *the witness the code was reasoned about is not the witness that
exercises the code.*

**This is the third recurrence of the same rail-authority divergence** — first adjudicated in the CP4c-0b DG
review, again in CB2's T1/T3 labelling, and now here. Three occurrences of one confusion is a structural signal,
not three coincidences. Measure **Z4** addresses it structurally rather than by fixing this one call site.

**Classification:** test-authority / structurally invalid fixture / non-stable. `M3-CP4c2-TB-X2-R2-CAND-01`
stands as recorded. No product regression is established. The frozen DEFN theorem is untouched: D1 never tested
it.

## 3. Finding B — the sphere publication is self-contradictory, by exactly 4

R2 flags this and explicitly declines to adjudicate it, which was the right call for a TB turn. It is
adjudicated here.

D1 publishes, for the prescribed sphere:

- **all 18** complement components are discs — each with `χ = 1` and exactly one boundary cycle;
- global terms `V = 18`, `E = 30`, `F = 18`, giving `18 − 30 + 18 = 6`;
- source `χ = 2`.

**These statements cannot all be true.** If every component of the complement of an embedded graph is an open
disc, the embedding *is* cellular by definition, and Euler's formula is then not an approximation but an
identity:

```
V − E + F = χ   ⟹   E − V = F − χ = 18 − 2 = 16.
```

The publication reports `E − V = 30 − 18 = 12`. **The deficit is exactly 4.** So at least one of three things
is false: the 18 disc verdicts, the vertex/edge counts, or the face count. A single publication that asserts
both "every component is a disc" and "`χ` is 6, not 2" has refuted itself, and **no branch may be selected from
it under any circumstances** — independently of the torus control, and independently of whether the torus is
ever fixed.

**This is the finding that matters most**, because Y5's Branch A hinges on precisely the proposition D1 was
built to establish — whether the sphere network is already cellular — and D1's answer to that question is
self-inconsistent rather than merely absent.

### 3.1 What the numbers most likely mean

Offered as the leading reading, to be confirmed or refuted by measurement, not adopted as fact.

`F = 18` is a count of **source-face components separated by barrier source edges**. `V = 18` and `E = 30`
appear to be counts in the **network's own abstract graph**, whose arcs cross face interiors. Those are two
different complexes, and Euler's identity does not hold between them — which is exactly the unit-mismatch
hypothesis this reviewer issued in `Architecture_M3_CP4c2_TB_X2_Plan.md` §4 for the *producer*.

**The significant discovery is that the oracle inherited it.** `M3-CP4c-2-TB-X2-PLAN` required the oracle to be
independent of `SurfaceCutGraph`, and D1 satisfied that requirement — it never calls the producer. But the
oracle was not made independent of the **counting convention**, which is the actual suspect. An oracle that
avoids the mechanism under test while reproducing its conceptual error is not an independent oracle. Plan §2's
requirement that every count be published "with a one-line statement of what was counted" existed to catch this
and was insufficient; **Z2 replaces it with a stronger, checkable obligation.**

Because barriers cut along **whole source edges** while traces cut only where they actually run, the barrier
partition cuts *more* than the network does. Over-cutting a disc along an edge yields two discs, so
"every component is a disc" and "too many components" are perfectly consistent with each other. That is why the
contradiction shows up as a surplus rather than as a failed disc test.

### 3.2 The two-ring's `networkOnlyCellular=true` is not corroboration

R2 reports the two-ring as consistent: `9 − 11 + 3 = 1`, matching source `χ = 1`, all three components discs.
It is tempting to read that as evidence the oracle works and only the sphere is odd. **It is not evidence of
anything.** Under a counting convention that mixes two complexes, an agreeing result is a coincidence, not a
validation — and the two-ring, with 3 traces against the sphere's 24, is exactly where the coarsening error
would be smallest or zero. A control that passes under a method known to be defective must be treated as
uninformative until the method is fixed. **Z7 requires the two-ring to be re-derived under the corrected
convention and its agreement re-established, not carried forward.**

## 4. Root cause common to both findings

Both defects have the same shape: **a quantity was taken from one authority while the expectation it was
compared against came from another.**

- Finding A: rails taken from the atlas; expected counts taken from the pipeline feature-map witness.
- Finding B: `V`/`E` taken from the network's abstract graph; `F` taken from the source-face barrier partition.

The corrective measures therefore share one principle, and the implementation agent should apply it as a rule
rather than as two patches: **every number that enters a comparison must name the authority it came from, and
two numbers may only be compared when they name the same one.**

## 5. Which complex is normative — the decision the correction needs

The correction cannot proceed without settling this, and neither the DEFN nor the plan settled it explicitly.
It is settled here.

**The normative complex is the source-mesh barrier complex.** Concretely, for a barrier edge set `B ⊆` source
edges:

- `E := |B|`
- `V :=` number of source vertices incident to at least one edge of `B`
- `F :=` number of connected components of the source faces after removing `B`

Three independent reasons:

1. **It is what A2b actually consumes.** `GlobalTopologyPlan.cpp:1694-1704` unions source faces across edges
   that are neither mandatory nor trace-touched. Region derivation already lives in this complex; certifying a
   different one certifies nothing about the consumer.
2. **The frozen DEFN already committed to it.** §5.2 requires that cuts "run along existing source mesh edges
   only — no new geometry, no subdivision, no vertex insertion." A cut graph made of source edges belongs to
   the source-edge complex; counting its `V` and `E` anywhere else is incoherent.
3. **It is self-consistent.** In this complex `V − E + F = χ` is a genuine identity whenever every component is
   a disc, so the certificate becomes a real check rather than a coincidence detector.

**A deferred design concern, recorded so it is not lost and explicitly not in scope now.** Cutting along whole
carrier edges is coarser than the traces themselves: a trace crossing a triangle turns two of its three edges
into barriers, separating faces the trace does not actually separate. That means A2b's regions are coarser than
field-aligned regions ideally would be, which is a **quad-quality** question. It does not affect CP4c-2's
correctness obligation, because the barrier complex is what A2b consumes and certifying it is exactly the
guarantee A2a′ owes. **Do not attempt to refine the cut model in this correction.** It is recorded as an open
design question for a later checkpoint.

## 6. Adjudication of the proposed `CB2-DIAG-R1`

The report's six proposed items are assessed individually. The proposal is **authorized with amendments**.

| # | Proposed item | Adjudication |
|---:|---|---|
| 1 | rebuild production witnesses' pre-A2a rails through the product-authoritative feature map and rail builder | **ACCEPT.** Necessary and correctly scoped. Strengthened by **Z4**. |
| 2 | publish rail-authority identity and mandatory-rail count beside every D1 record | **ACCEPT.** This is the right structural control. Strengthened by **Z4** to make it non-optional and machine-checkable. |
| 3 | independently audit/fix D1's global Euler `V/E/F` so the equation uses one explicitly named complex | **ACCEPT, AND IT IS THE LOAD-BEARING ITEM.** As written it is under-specified — "one explicitly named complex" does not say *which*. §5 names it. See **Z2**. |
| 4 | preserve the two-ring's intended authority rather than mechanically replacing it | **ACCEPT, for a reason the report does not give.** The two-ring is a *constructed* witness, not a loaded production one; `rails_from_atlas` is its legitimate authority. The rule is not "leave the two-ring alone" but "each witness declares its own authority, and production witnesses must use the production one." See **Z4**. |
| 5 | do not alter production source, `SurfaceCutGraph`, selectors, C1/C3/C6, or frozen branch rules | **ACCEPT** without change. |
| 6 | compile/package under GMP/GMPXX with no runtime; a retry must reproduce the torus control before running D2 | **ACCEPT, with one addition:** the retry must **also** clear the Finding B self-consistency check before D2, since Finding B is an independent blocker. See **Z6**. |

## 7. Measures **Z0–Z9** for `M3-CP4c-2-CB2-DIAG-R1`

- **Z0 — preconditions and immutability.** Accepted authority remains CP4c-1 TB-R5 **355/355**, selector
  `e9d88f11…5afeaa` with prefixes `601ce2b6…`, `20d3b0b1…`, `51ff96d7…`. Both frozen candidates must be
  re-hashed unchanged: **357** `b896d0db7f26aeb0f3513418405efdeccbcf84fb6dc971500c6ddac9e364dc70`, **358**
  `6eda3aad83de81fc55d5cd446f80704d604a842f10995789b483291bb64fbe62`. Compile under `GMP_COMPILE_POLICY.md`
  with GMP/GMPXX; `runtimeExecution=false`. **`src/` and `include/` are frozen — this is a test/diagnostic-only
  correction.**
- **Z1 — fix the rail authority for production witnesses.** The torus and prescribed sphere must reach A2a
  through `AdaptiveFeatureMapBuilder::build(...)` → `build_authoritative_surface_cell_rails(...)`, the same
  path production uses. Do not special-case the torus; fix the helper for every loaded production witness.
- **Z2 — one complex, named, for every count.** Recompute `V`, `E`, and `F` in the **source-mesh barrier
  complex** defined in §5: `E = |B|`, `V =` source vertices incident to `B`, `F =` components of source faces
  after removing `B`. Publish all three **plus `|B|` itself and the barrier-set provenance**, and publish a
  literal complex name string on every record (for example `complex=sourceEdgeBarrier`). **Do not publish a
  network-abstract-graph count and a barrier-partition count in the same equation.** If any count cannot be
  derived in the named complex, publish it as unavailable rather than substituting the other complex's value.
- **Z3 — a self-consistency assertion the oracle cannot pass while incoherent.** D1 must check, per witness,
  that *(every component is a disc)* **⟺** *(`V − E + F == χ_source`)*, and publish the result as an explicit
  pass/fail field. **If the two sides disagree, D1 must report `oracleSelfConsistent=false` and the run must
  stop before Y5.** This is the check that would have caught Finding B automatically instead of leaving it to
  a human reader; it is mandatory, and it is the single most valuable line in this correction.
- **Z4 — make the rail-authority divergence structurally impossible to repeat.** This is the third recurrence.
  Every witness constructor must obtain rails through **one named accessor** that takes an explicit authority
  argument — production-authoritative or atlas-derived — with **no default**, so that a constructor cannot
  silently pick one. Every D1/D2 record must publish `railAuthority=` and the mandatory-rail count. A witness
  whose declared authority does not match the authority its expected counts came from must fail closed rather
  than report a number.
- **Z5 — do not encode the answers.** Neither `48/48` nor any sphere outcome may be written into the oracle as
  a constant, a special case, an expected-value table, or a witness-name branch. The control's job is to be
  reproducible from the authority, not to be satisfied. **If the corrected oracle reproduces `48/48` only
  because it was told to, the correction has failed.**
- **Z6 — retry ordering.** The successor artifact-only retry must, in this order: (1) reproduce the torus
  control `V=48, E=48, χ=0, non-cellular` from the corrected authority; (2) pass **Z3** self-consistency on
  **all three** witnesses; and only then (3) execute D2 and attempt Y5. A failure at (1) or (2) is a stop, not
  a partial result to be reasoned around.
- **Z7 — re-derive the two-ring, do not carry it forward.** Its previous `networkOnlyCellular=true` was
  produced by the defective convention and is uninformative. Publish its corrected `V/E/F/χ` and state
  explicitly whether the agreement survives. **If the two-ring's numbers change under the corrected
  convention, say so prominently** — that is direct evidence about the size of the coarsening effect.
- **Z8 — accounting.** Carry `M3-CP4c2-TB-X2-R2-CAND-01` to RESOLVED only when the corrected torus control
  reproduces from authority. Open a **new** candidate for Finding B — the oracle's mixed-complex Euler
  accounting — rather than folding it into CAND-01; they are different defects with different fixes, and
  merging them would let one close while the other survives. `M3-CP4c2-TB-X2-CAND-04` stays ACTIVE and
  unlocalized: D2 still has not run. Totals stay **42 / 14 / 28**, debt **5**; increment the package count.
- **Z9 — prohibited.** Editing production `src/` or `include/`; touching `SurfaceCutGraph`; changing selectors
  355/357/358 or inventing a third; running any cumulative gate; executing D2 from the invalid package;
  starting frozen `CB3`; relaxing `proves_cellularity()`; any test-only injection path into A2b or weakening of
  `make_from_candidate`; defining cellularity as `cut_edges().empty()`; any oracle call into `SurfaceCutGraph`;
  refining the cut model per §5's deferred concern; touching the mechanical witness, C2, or CP4c-3.

## 8. Falsifiable predictions

1. Under the production rail authority the torus reproduces **`V = 48`, `E = 48`, `χ = 0`, non-cellular**,
   matching the frozen DEFN theorem. If it does not, **the DEFN rests on a stale measurement and must be
   re-adjudicated** — do not adjust the oracle to match it.
2. Under the corrected barrier-complex convention the prescribed sphere becomes **self-consistent**: either all
   components are discs *and* `V − E + F = 2`, or at least one component is not a disc *and* the sum differs
   from 2. The current state — all discs with a sum of 6 — **cannot recur**.
3. The sphere's corrected `E − V` equals **16** if and only if all components remain discs and `F` remains 18.
4. The sphere's corrected `F` may differ from 18. **A change in `F` is the direct measure of how much the
   whole-source-edge coarsening over-cuts**, and it must be reported explicitly whether or not it changes.
5. The two-ring remains cellular under the corrected convention, with possibly different `V/E/F` terms.
6. Most likely branch: **A** — the sphere is already cellular under a coherent count, making
   `SurfaceCutGraph::CellularityNotEstablished` at site 474 an idempotence failure (DEFN measure X6) caused by
   the same mixed-complex accounting in the producer. **This remains unadjudicated until D2 runs**, and this
   review does not treat it as established.

Predictions 2 and 3 are the load-bearing ones. Prediction 6 is the one most likely to be wrong and must not be
acted on before D2.

## 9. Stop / successor

The exact next turn is **`M3-CP4c-2-CB2-DIAG-R1`**, Code + Build, runtime-free, test/diagnostic source only,
under measures **Z0–Z9**.

Its successor is `M3-CP4c-2-TB-X2-R3`, artifact-only, which must satisfy **Z6**'s ordering before any Y5 branch
selection. `selected_r2_branch` remains **NONE**, `selected_gate` remains **NONE**, and
`gate_execution_authorized` remains **false**.
