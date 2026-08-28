# Architecture M3 CP4c-0b — DG Independent Review and Plan Correction

**Turn:** `M3-CP4c-0b-DG-REV`
**Type:** Independent review / planning only — no product, test, fixture, selector, build, package, or runtime mutation. Source and committed fixtures were read and arithmetic was performed on their contents; nothing was executed and nothing was modified.
**Evidence under review:** `M3-CP4c-0b-DG`, **VALID SEMANTIC RED 6/7**, run/job `33120730355 / 98686699036`, immutable GMP package `9664890562`, semantic source `737f93be10a73db950e2a7f823b96ffb0d59cf4d`; result `9666352028`, diagnostic log `9666352544`.
**Prior evidence consumed:** `M3_CP4c_Consolidated_Record.md` §3 (retired S1 review), `M3_CP4c_Consolidated_Record.md` §3 (retired first DG report).
**Incoming accepted authority:** M3-CP4c-0 **346/346 ACCEPTED**; M3-CP4ab **316/316** beneath it.

---

## 0. Verdict

**`M3-CP4c0b-DG-CAND-02` resolves as a test-side over-specification. No S2–S6 contract breach is established, and none is indicated.**

The single red — `torus.network->nodes().empty()` was `false` — is **not** a change introduced by S2–S6. Network nodes are constructed **before tracing**, from singularity vertices and mandatory-edge endpoints, and that construction is **byte-identical** across the S1 and S2–S6 sources. The apparent delta against S1's `nodeCount=0` is an artefact of comparing **two different constructions of "the torus network"**, built under **two different rail authorities**:

| | how the torus network was built | rail authority |
|---|---|---|
| **S1 census** (`nodeCount = 0`) | `diagnose_field_aligned_contact_census(mesh, …, rails)` with `rails = rails_from_atlas(mesh, atlas)` — `tests/FieldAlignedCurveNetworkTests.cpp:5516` | **atlas-derived rails** |
| **DG identity** (`nodes()` non-empty) | `observe_cp4c_witness("torus", …)`, which sets `observation.rails = products.authoritativeRails` — `tests/FieldAlignedCurveNetworkTests.cpp:3782` | **production-pipeline authoritative rails** |

Different rails ⇒ different `mandatoryByEdge` ⇒ different `nodeVertices` ⇒ different node sets. **Both numbers are correct; they are answers to different questions.** The new identity imported a figure measured under one authority and asserted it against a network built under the other.

The DG report was right to refuse to choose between its two interpretations, and right to record the delta as real evidence rather than dismissing it. This review supplies the third possibility neither interpretation covered.

**One caveat is load-bearing and I state it before the argument, not after.** I have *not* executed anything. Link 5 of §2 is a strong inference from accepted green identities, not a measurement. **Measure T1 exists to prove it**, and no identity may be edited before T1 returns.

---

## 1. What the red is, precisely

`TraceTerminationCorrection.TorusRemainsZeroTraceAndFanRemainsExcludedFromCredit`
(`tests/FieldAlignedCurveNetworkTests.cpp:6944-6966`) asserts three things about the torus, in this order:

```cpp
EXPECT_TRUE(torus.network->candidate_traces().empty());   // PASSED
EXPECT_TRUE(torus.network->nodes().empty());              // FAILED  <- line 6952
EXPECT_TRUE(torus.network->events().empty());             // PASSED
```

`EXPECT_TRUE` does not abort, so all three ran. The observed state is therefore:

**zero candidate traces, zero events, ≥ 1 network node.**

That combination is the signature of **structural** nodes — nodes that exist without any trace having been produced. It is *not* the signature of contact nodes, which can only be allocated by a trace.

---

## 2. Why this is not an S2–S6 breach — five links, four of them checkable without running anything

### Link 1 — nodes are built before tracing, from two sources only

`canonical_field_aligned_candidate` (`src/geometry/SurfaceCellTracing.cpp:3046-3110`) builds

```
nodeVertices = { singularity.sourceVertex for each singularity }
             ∪ { sourceEdge.first(), sourceEdge.second() for each mandatory edge }
```

and materialises `candidate.nodes` from it **before** any trace exists. Nothing downstream can remove a node.

### Link 2 — that construction is unchanged by S2–S6

`git diff 4bb467806df99c70889394a323c17c13bc185ca3 737f93be10a73db950e2a7f823b96ffb0d59cf4d -- src/geometry/SurfaceCellTracing.cpp` touches `canonical_field_aligned_candidate` in exactly **two** hunks: the added `priority` parameter, and the branch that selects `legacy_canonical_field_aligned_traces` + `finalize_field_aligned_events` for the census versus `canonical_field_aligned_traces_and_events` for production. **The `nodeVertices` block and the `candidate.nodes` loop are not in the diff.**

### Link 3 — with zero ports, the new code path allocates no node

`canonical_field_aligned_traces_and_events` (`:2341+`) builds `runtimes` from `candidate.singularityPorts`. With zero ports, `runtimes` and `candidateTraces` are empty; `field_aligned_publish_origin_events` (`:2012-2051`) iterates `candidateTraces` and emits nothing; the `while (any_of(runtimes … active))` loop never executes. The three node allocators reachable in the new path — `field_aligned_publish_barrier_termination` (`:2078`), `field_aligned_publish_contact` (`:2280`), and the legacy finalize sites (`:2768`, `:2825`, `:2862`) — **all require a trace**. Zero traces ⇒ zero appended nodes, which is exactly consistent with the observed zero events.

### Link 4 — the torus has zero singularities, computed independently from the committed fixture

Re-derived here from `benchmarks/fixtures/milestone-g/torus.{obj,rawfield}` with no product code: per-vertex fan holonomy composed around each interior vertex fan through the principal matching.

| witness | V | F | interior vertices | boundary vertices | vertices with non-zero fan holonomy |
|---|---:|---:|---:|---:|---:|
| torus | 72 | 144 | 72 | **0** | **0** |
| prescribed sphere | 98 | 192 | 98 | 0 | **8** — exactly `{0, 8, 21, 24, 25, 34, 45, 49}` |

**The method is validated by the sphere row**, which reproduces the known singularity set from `sphere_prescribed.fieldmeta.json` exactly. So the torus contributes **no** singularity vertices to `nodeVertices`, and — having **no boundary loops** — no boundary rails either.

**Therefore every torus node is a mandatory-edge endpoint, and nothing else.** Which mandatory edges exist depends entirely on which rails were supplied.

### Link 5 — the accepted torus fixture requires structure that only mandatory edges can supply *(inferred, not measured — T1 proves it)*

`assert_cp4c_common_preconditions` (`:4559-4574`) requires of every CP4c witness, including the torus:

- `plan.regions().size() >= 2`;
- at least one region with `sourceFaces.size() > 1U`;

and `assert_cp4c_torus_preconditions` (`:4576-4592`) additionally requires a region whose boundary uses a **non-trivial multi-face graph cycle**. These are **accepted and green**.

A2b derives regions from the network. On a closed genus-1 surface with **zero singularities, zero traces and zero events**, the only remaining source of region boundary is the mandatory-edge set. So the pipeline-built torus must already carry mandatory edges — and therefore non-empty nodes — and must have done so since long before CP4c-0b existed.

**This link is an inference from green accepted identities. It is not a measurement, and T1 exists to make it one.**

---

## 3. What the new identity got wrong, and why it was an easy mistake

The identity asserts a **total** property (`nodes().empty()`) where the checkpoint owns a **relational** one. CP4c-0b's torus role, as frozen, is *"torus remains zero-trace"* — the DEFN states no general torus zero-node invariant, and the DG report correctly noted that.

The specific error is narrower and more instructive than "the assertion is too strong":

**The figure `nodeCount = 0` was measured by S1 under `rails_from_atlas` and then asserted against a network built by `observe_cp4c_witness` under the pipeline's `authoritativeRails`.** The S1 review record's own table reports torus `nodeCount 0` and two-ring `nodeCount 9` in the same column, so the number looked like a stable property of the witness. It is a property of the **witness plus the rail authority**, and nothing in the census output said so.

That is a defect in the census's self-description as much as in the identity, and T3 fixes it at the source rather than only at the call site.

---

## 4. What is *not* established, and must not be assumed

- **I have not counted the torus's mandatory edges or nodes under either rail authority.** T1 does.
- **I have not verified that `observe_cp4c_witness("torus", …)` and `build_cp4c_production_fixture("torus", …)` construct the same network.** If they differ, a second rail-authority divergence exists inside the test support itself. T1 checks it.
- **No accepted-green predecessor regression is established by this DG.** Only the seven never-accepted new identities ran. The full 353 gate has not executed, so S2–S6's effect on accepted authority remains **unmeasured**, and the six DG passes are not a substitute for it.
- **The other six DG identities passing is real but bounded evidence.** In particular `PrescribedSpherePublishesTwentyFourTracesAndCorrectedContactEvents` passing is the first live confirmation that the relocation in S5 works and that Q8 criteria 2 and 3 are reachable — but it is one identity on one witness, and it does not speak to accepted witnesses.

---

## 5. Corrective measures — series **T**

`M3-CP4c-0b-CB2`. Code + Build only; **runtime forbidden**; GMP/GMPXX linkage mandatory per `GMP_COMPILE_POLICY.md`; all eight standard targets compiled; the package must record `exactArithmeticBackend=GMP`.

### T0 — binding preconditions

Stop and return to review if any fails.

- **T0.1** CP4c-0 is **ACCEPTED at 346/346**, selector SHA-256 `20d3b0b1400d5cab6af4a339a858c56fb7fd0359fb995a395dad215b20f3e46a`.
- **T0.2** `canonical_field_aligned_candidate` still builds `nodeVertices` from singularity vertices and mandatory-edge endpoints only, **before** tracing, and `candidate.nodes` is materialised from it (`src/geometry/SurfaceCellTracing.cpp:3046-3110`).
- **T0.3** With zero singularity ports, `canonical_field_aligned_traces_and_events` allocates no node: `field_aligned_publish_origin_events` iterates `candidateTraces`, and every remaining allocator requires a trace.
- **T0.4** The S1 census still builds its witness with `rails_from_atlas` (`tests/…:5516`) and `observe_cp4c_witness` still uses `products.authoritativeRails` (`tests/…:3782`). **If these now agree, this plan is stale and the delta has another cause.**
- **T0.5** The DG selector is still **7** identities with SHA-256 `14570409facfb9c9072375cae3ad4319e383386380ee1060d4af75c6e61c5724`, and the full CP4c-0b selector is **353** with `91371d5ab637447c31c0d25e829be0d58fa61f17245e69bd231dcaec94f21efb`.

### T1 — the discriminating measurement, and nothing may precede it

**Non-gating. Changes no production behaviour. This is the measure that converts §2's link 5 from inference to fact and decides whether T2 is correct or must be replaced.**

For **each** of two rail authorities — `rails_from_atlas(mesh, atlas)` and the production pipeline's `authoritativeRails` — and for each witness that reaches A2a (two-ring, torus, prescribed sphere; fan excluded from credit), publish:

1. the **mandatory-edge count**, and each mandatory edge's `SurfaceCellRailKind`;
2. the **singularity count** and their source vertices;
3. `nodeVertices.size()` and the resulting `nodes().size()`;
4. for every published node, its `sourceVertex` and its **provenance** — `singularity`, `mandatory-edge-endpoint`, or `contact` — so a structural node is distinguishable from an allocated one by inspection rather than by arithmetic;
5. `candidate_traces().size()`, `events().size()`, and the event-kind histogram;
6. whether `observe_cp4c_witness(w)` and `build_cp4c_production_fixture(w)` produce **identical** node sets, event sets and trace counts for the same witness.

**Falsifiable predictions.** Under **atlas-derived** rails the torus has **0** mandatory edges, **0** nodes, **0** traces, **0** events — reproducing S1 exactly. Under **pipeline** rails the torus has **≥ 1** mandatory edge, **≥ 2** nodes, **0** traces, **0** events, and **every** node has provenance `mandatory-edge-endpoint`. Item 6 returns identical for every witness.

**Decision table, binding:**

| T1 result | Action |
|---|---|
| Predictions hold; every pipeline-torus node is a mandatory-edge endpoint | **The identity over-specified.** Proceed to T2. |
| Pipeline torus has **0** mandatory edges yet **≥ 1** node | A node exists with no lawful provenance. **Stop and return to review** — this would be a real S2–S6 defect and T2 is wrong. |
| Any pipeline-torus node has provenance `contact` | Contact allocation is firing with zero traces. **Stop and return to review.** |
| Item 6 shows the two construction helpers disagree | A second rail-authority divergence exists in test support. **Stop and return to review**; correcting only the identity would leave it live. |

### T2 — correct the identity to the contract the checkpoint actually owns

**Only after T1 confirms the first row.** Replace the total assertion with a relational one that is both correct and *stronger* than what it replaces:

- **delete** `EXPECT_TRUE(torus.network->nodes().empty());`
- **keep** `candidate_traces().empty()` and `events().empty()` unchanged — both passed and both are genuine CP4c-0b contract;
- **add**: every published torus node's `sourceVertex` is a mandatory-edge endpoint or a singularity vertex — i.e. **no node has contact provenance**. This is what "the torus produces no contact" actually means, and it cannot be satisfied by a coincidence of counts;
- **add**: no torus trace carries `terminalContact`, and the event histogram contains zero `TraceIntersection` and zero `SingularityPortJunction`.

Rename the identity so the name states the contract rather than a count — e.g. `TorusPublishesNoTraceAndNoContactNodeAndFanRemainsExcluded`. **Record the rename and the reason in the CB report**; the identity has never been accepted, so this is an authorized in-flight correction, not an accepted-expectation edit.

### T3 — make the census self-describing so this class of error cannot recur

The S1 census reported `nodeCount` without stating which rail authority produced it, which is what allowed a correct figure to be asserted against a different construction. Fix it at the source:

- every census line **must** emit `railAuthority=atlas-derived` or `railAuthority=pipeline-authoritative`;
- every census line **must** emit `mandatoryEdgeCount` and `singularityCount` alongside `nodeCount`, so a node figure is never readable without the two inputs that determine it;
- add an identity asserting that **any figure an identity cites from a census is compared against a network built under the same `railAuthority`** — enforced concretely by having the shared witness-construction helper return its authority tag, and by having the identity assert the tag it consumed.

This is a diagnostic-contract requirement of the same family as Amendment 6's "observable is defined by mechanism": **a published number must carry the authority that produced it.**

### T4 — re-run the DG seven

Unchanged selector, unchanged cardinality and hash **unless T2's rename changes a name**, in which case the DG selector is re-frozen and its new cardinality and SHA-256 recorded in the CB report. Required: **7/7**.

### T5 — then, and only then, the full 353

The green-DG route to the full frozen acceptance TB stays blocked until T4 is green. **T5 is the first measurement of S2–S6 against accepted authority**, and §4 records that this is currently unmeasured. Required: accepted **316/316**, CP4c-0 **346/346**, full **353/353**.

The S1 review authorized exactly two accepted re-authorings for the site-A vocabulary split — `DeclaresTraceIntersectionsAsTypedNetworkEvents` and `IndependentCompositionOracleValidatesTraceEventGraph`. **Any other accepted identity requiring an expectation edit is a stop**, exactly as that review froze.

### T6 — prohibited

No A1 change. No tolerance, literal epsilon, or tuned constant in the contact predicate or the priority comparison. No production-reachable priority argument. No length-based termination. No sequential tracing in production. No reuse of a retired enum value. No change to the CP4c-1 **318** selector. No editing an accepted identity outside the two the S1 review authorized. **No editing the failing identity before T1 returns.** No runtime execution in CB2.

### T7 — what the CB2 report must state explicitly

- which rail authority every published figure was measured under;
- the T1 decision-table row taken, with the numbers that selected it;
- the exact before/after text of the corrected identity and its rename;
- the DG selector's cardinality and SHA-256 after any rename;
- `exactArithmeticBackend=GMP` and the eight compiled targets.

---

## 6. Standing stop conditions, extended

The CP4c-0b §11 list and the P0.3 review's §8 list both stand. Added:

- an identity cites a census figure without stating the rail authority it was measured under;
- the failing identity is edited before T1 returns;
- a node is published whose provenance is neither singularity, mandatory-edge endpoint, nor contact;
- the two witness-construction helpers disagree and only the identity is corrected;
- the full 353 gate is run before T4 is green.

---

## 7. Durable lessons

- **A measured number is a property of the measurement, not only of the subject.** `nodeCount = 0` was correct for the torus under atlas-derived rails and wrong for the torus under pipeline rails. The census published the number without the authority that produced it, so a later identity could import it in good faith and be wrong. **Publish the inputs that determine a figure alongside the figure.**
- **A test that asserts a total where the contract is relational will fail for reasons the contract does not own.** "Zero nodes" is not what "the torus produces no contact" means; the torus has structural nodes for lawful reasons that predate the checkpoint. **Assert the relation — no node of contact provenance — not the count.**
- **Two names for a witness are two witnesses until proven otherwise.** `rails_from_atlas` and `products.authoritativeRails` both yield "the torus network", and they are different objects. Before comparing figures across turns, check that the constructions match.
- **A red that admits two readings deserves a third.** The DG report framed the choice as over-specified identity versus S2–S6 breach and correctly declined to choose. The actual cause was neither: a correct figure compared across a boundary that nothing had named.

---

## 8. Accounting and exact successor

- accepted runtime authority: **M3-CP4c-0 346/346**, GMP package `9649395432`; M3-CP4ab **316/316** beneath it
- CP4c-0b full selector **353** / `91371d5a…21efb`; DG selector **7** / `14570409…c5724`
- CP4c-1 selector **318**, unchanged
- stable regression accounting **42 / 14 / 28**, produced-witness debt **5**, M3 packages **53** — unchanged; this turn executed nothing
- **`M3-CP4c0b-DG-CAND-02` — adjudicated: TEST-SIDE OVER-SPECIFICATION / NON-STABLE**, conditional on T1's first decision row. No product impact; owned by T1–T3. **+0 events / +0 recurrences.**
- `M3-CP4c0b-DG-CAND-01` remains RESOLVED ORCHESTRATION / NON-STABLE.
- `M3-CP4c0b-P03-CAND-01` remains ACTIVE; S2–S6 are implemented but unmeasured against accepted authority until T5.

**Exact next: `M3-CP4c-0b-CB2` under T0–T7**, beginning with T0's preconditions and then T1's rail-authority measurement. **T1 must return before any identity is edited**, and its decision table may route back to review.
