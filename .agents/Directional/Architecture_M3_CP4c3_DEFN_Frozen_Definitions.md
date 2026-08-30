# M3-CP4c-3 DEFN — Frozen Definitions, Review and Plan

## 0. Turn type and verdict

`M3-CP4c-3-DEFN` is **COMPLETE / DEFINITION + REVIEW/PLAN, COMBINED**.

No Directional runtime, build, compile, package, benchmark, product, test or fixture change was made or is
authorized. One **selector authority file was created** — this turn type's proper output — and no existing selector
byte was modified.

**Cadence change, by user authorization (2026-08-30):** *"combine DEFN step with REVIEW/PLAN step going forward when
DEFN is the next step in the chain."* From this turn on, a `DEFN` turn **is** the review-and-plan turn for its
checkpoint: it freezes definitions, adjudicates inherited candidates, decides gate membership, and issues the
successor's measures in one turn. A separate `REVIEW/PLAN` turn is no longer scheduled ahead of a `DEFN`. The
existing `CB → TB → green? → close / red → REVIEW+PLAN → CB` cadence is otherwise unchanged, and this collapses only
the `REVIEW+PLAN → DEFN` edge. Recorded additively in the durable turn-workflow sections of `TODO.md` and
`Future_Chat_Session_Handoff.md`.

**Four decisions.**

1. **`IncompleteCycleBasis` is a seven-way collapse** (§3), and no evidence has ever identified which of its seven
   conditions the mechanical witness hits. That is `LESSONS.md` 57 recurring in A1, and the checkpoint must
   instrument before it designs.
2. **The prescribed sphere is IN CP4c-3's gate** (§4), after two checkpoints outside one.
3. **CP4c-3 runs in two phases** (§5) with one frozen gate, **selector 367** (§6), extended by append.
4. Measures **AK0–AK9** are issued for `M3-CP4c-3-CB1`.

Amendments 12, 13 and 14 are **unchanged and remain binding**. Accepted selector 365 is unchanged.

---

## 1. What CP4c-3 owns

**Parent responsibility** (`ROADMAP.md` §1): the closed-surface missing field-transport adjacency in A1, then the
mechanical witness — criterion **C2**, `GlobalTopologyPlan.MechanicalFeatureWitnessDerivesRegionsThroughProductionEntryPath`.

**Inherited from CP4c-2** by R10-REV measure AJ9:

| record | substance |
|---|---|
| `M3-CP4c2-TB-X2-CAND-04` | the prescribed sphere: (a) producer `RotationSystemInconsistent` at source face `25-27-28`, `producerCutEdgeCount=0`, **before** cut selection; (b) independently, a non-cellular pre-cut graph `V/E/F = 18/30/18`, `χ=6` vs `sourceChi=2` |
| `M3-CP4c2-TB-X2-R10-CAND-01` | Amendment 14's **ordinary** trace-crossed proposal path is structurally unreachable; only saturation promotes such an edge |
| `M3-CP4c2-TB-X2-R8-CAND-02` | zero-node / zero-arc closed-surface cut-graph behaviour is undefined |

**Not CP4c-3's:** the torus post-A2b `tracing` failure (downstream of A2b, tracked separately), and anything from
A3 onward.

---

## 2. Review of the inherited items

### 2.1 `R10-CAND-01` — cause established, corrective is narrow and heuristic-only

R10-REV localized this fully and the mechanism is in the committed loop:

```cpp
barriers   = mandatory ∪ traceCrossed ∪ cuts;
components = proposal_components(topology, barriers);
proposed   = proposal_tree_cotree_cut_edges(topology, component, barriers);
for (edge : proposed) { if (mandatory.count(edge)) continue;  cuts.insert(edge); }
```

DEFN-R2 §4.5's **filter** was correctly removed — only `mandatory` is skipped. The **barrier set** still contains
`traceCrossed`, so a trace-crossed edge *bounds* a proposal component instead of lying inside one, and a
tree–cotree generator search draws from a component's interior edges. The ordinary path therefore has no
trace-crossed edge available to propose, and saturation is the only route.

**This is a proposal-heuristic defect, not a certification defect.** Amendment 13 §3 already denies the
source-edge-barrier partition any certification authority; the authoritative verdict is always the actual-embedded-graph
certificate, which R10 proved green. So the corrective touches the heuristic only and **does not reopen
Amendment 14**. Frozen corrective: model a trace crossing as a **per-face chord**, matching the fragment machinery
A2b already uses, so a trace-crossed edge is interior to its component. Owned by **AK4**.

### 2.2 `R8-CAND-02` — decided here rather than deferred a third time

Question: what should A2a′ do when the network is empty (zero nodes, zero arcs) on a closed surface?

**Decision: reject with a typed error naming the empty network.** Rationale: A2a′'s contract is to *add cuts that
make an existing network's complement cellular*. An empty network has no complement structure to complete — cutting
"from scratch" would make A2a′ the producer of the entire embedded graph, which is A2a's single-writer authority
(`ORIENTATION.md` §1). Silently succeeding would also mean a witness with no field-aligned content could produce a
"certified" plan, which is the vacuous-green shape `LESSONS.md` 64r warns about. A typed rejection keeps
single-writer authority intact and fails closed with a locus, per the architecture's own commitment.

The new code must be **additive** — a new `SurfaceCutGraphErrorCode` value, appended, with no renumbering of
existing values, since accepted identities consume them. Owned by **AK5**.

### 2.3 `CAND-04` — the sphere's two problems, and why (a) comes first

(a) and (b) are independent and (a) blocks observation of (b) through the producer. Until the producer reaches cut
selection, the sphere's cut set cannot be examined at all. So (a) is sequenced first, and it is the same shape as
the A1 problem in §3 — a typed error whose exact origin site has never been printed, at a finer grain than
"`RotationSystemInconsistent`, one of nine sites in `EmbeddedGraphTopology.cpp`".

---

## 3. The finding — `IncompleteCycleBasis` is a seven-way collapse, and nobody has printed which one

The mechanical witness has been out of scope for the entire CP4c arc, and **no diagnostic has ever been run on it**.
`ORIENTATION.md` §4 records only "no atlas — stops in **A1** at `IncompleteCycleBasis`". Read at source, that code
is not one condition:

| site in `src/authority/FieldTransportAtlas.cpp` | condition | locus published |
|---|---|---|
| `:1597` | `PCFaceTangentBundle::init(local->mesh)` threw | region only |
| `:1613` | `cycles.rows()`, `cycleCurvatures.size()` or `cycles.cols()` disagrees with `interiorVertices + boundaryLoops + 2·genus` | region only |
| `:1673` | a cycle coefficient is neither ≈0 nor ≈±1, or a column index is out of range | region only |
| **`:1682`** | **no `FieldTransportAdjacency` exists for a cycle's edge** | region + **edge** |
| `:1688` | a local edge has a negative incident face | region + edge |
| `:1700` | `order_cycle_steps` could not order the directed cycle | region only |
| `:1751` | per-kind cycle partition counts disagree with expected local/boundary/handle counts | region only |
| `:1818` | boundary-cycle count ≠ `local->mesh.boundaryLoops.size()` | region only |

**Seven distinct mechanisms, one name, and five of them publish nothing but a region id.** Site `:1682` is
literally "missing field-transport adjacency" — the phrase `ROADMAP.md` uses for CP4c-3's parent responsibility — so
the roadmap's framing points at one specific site among seven that has never been confirmed.

This is `LESSONS.md` **57** recurring in A1: *a `default:`-shaped collapse assigns a name that will be believed*.
CP4c-2 paid **eight turns** for exactly this at `topology_error`, and the fix that ended it — AF0's additive
`originatingTopologyError` provenance field — is a directly reusable template. **CP4c-3 must not design a fix for
the mechanical witness before the discriminator is printed.** That is **AK1**, and it is the first measure for the
same reason AF1 was first at CB6.

**A second, related gap:** these checks all read `local->mesh`, built by `make_local_region_mesh`
(`:850-895`) from a region's faces plus **all** their vertices. Whether a region's local mesh is a manifold disc, or
pinches at a vertex where several feature curves meet — common in mechanical parts — determines
`isBoundaryVertex`, `boundaryLoops` and hence the expected counts at `:1613`, `:1751` and `:1818`. **AK2** requires
the local-region-mesh shape published alongside the failing site, because the site alone will not explain the count.

**No mechanism is promoted here.** The candidate readings above are hypotheses; AK1/AK2 exist so the next turn
reports a measurement rather than adopting one. This is the R2 discipline, and the last three checkpoints have all
been shortened by honouring it.

---

## 4. Scope decision — the prescribed sphere IS in CP4c-3's gate

R10-REV measure AJ2 required this decided explicitly and in writing. **Decision: the sphere is gated.**

**Why.** It has now sat outside two consecutive frozen gates. `LESSONS.md` 64w and the `AF5` finding record that a
witness outside every gate is how a defect survives indefinitely — the sphere's own eight-turn misdiagnosis is the
project's proof of that. A third silent pass would make the pattern a habit. It is also the only remaining witness
that cannot reach A2b at all, and A2b's region authority is what M4 builds on: deferring it pushes an unknown of
unknown size into the next milestone. And its problem (b) is **directly coupled** to `R10-CAND-01`, which CP4c-3
already owns — a sphere that needs trace-crossed cuts is precisely the production witness the ordinary proposal path
must be able to serve.

**Scope boundary this does not cross.** Adding the sphere as a gated **witness** is not reallocating a **criterion**:
`ROADMAP.md` §1 allocates C1/C3/C6 to CP4c-2 and C2 to CP4c-3, and that allocation is untouched. Which witnesses a
checkpoint's identities bind is a DEFN decision, and `ROADMAP.md` §1 states the successor selector is not frozen
until the definition turn. The sphere enters through §5's phase 2, gated by a new identity named in §6.2 — not by
widening C2.

---

## 5. Phase structure

CP4c-3 has two product problems in two different stages, plus two carried defects. One undifferentiated CB would
repeat the partial-conversion failure this project has now corrected three times, so the checkpoint runs in two
phases against **one** frozen gate. Phase 1 is diagnostic and non-mutating of product semantics; phase 2 fixes.

**Phase 1 — make both failures legible (`M3-CP4c-3-CB1`, measures AK1–AK3).** Instrument A1's
`IncompleteCycleBasis` collapse and the sphere's `RotationSystemInconsistent` at site granularity, publish the
local-region-mesh shape, and run the result through a TB. **No product fix.** Phase 1 exists because both problems
are currently named by a code that does not identify their mechanism, and because CP4c-2's own record shows what
designing across that gap costs.

**Phase 2 — fix, on measured causes (`M3-CP4c-3-CB2+`, measures AK4–AK6).** The mechanical witness's A1 defect, the
sphere's A2a′ defect, `R10-CAND-01`'s proposal-heuristic correction and `R8-CAND-02`'s typed rejection. Ordering
within phase 2 is a phase-1-review decision, not fixed here, because the measured causes may share a locus — as the
torus and sphere did.

---

## 6. The gate

### 6.1 Frozen now — selector 367

Created as `.agents/Directional/Architecture_M3_CP4c3_Required_Green_Selector_367.txt`: accepted **365** plus the
two identities that exist today and that CP4c-3 owns by prior commitment.

| ordinal | identity | why gated |
|---|---|---|
| 366 | `GlobalTopologyPlan.MechanicalFeatureWitnessDerivesRegionsThroughProductionEntryPath` | criterion **C2**, CP4c-3's parent responsibility |
| 367 | `GlobalTopologyPlan.RotationSystemAndFaceWalkAgreeOnProducedWitnesses` | criterion **C3**'s full form, binding torus **and** mechanical. DEFN-R2 §7.3 split C3 and committed the mechanical half to CP4c-3; this honours that commitment. The torus-only variant at ordinal 362 stays in the accepted prefix and is not removed. |

| authority | source file | derivation | SHA-256 |
|---|---|---|---|
| accepted 355 prefix | `…_Selector_367.txt` | `head -n 355 \| sha256sum` | `e9d88f1196e412e06424294d6be22b32f01c9671ec5e4de119abd3f2fb5afeaa` |
| 357 prefix | `…_Selector_367.txt` | `head -n 357 \| sha256sum` | `b896d0db7f26aeb0f3513418405efdeccbcf84fb6dc971500c6ddac9e364dc70` |
| 361 prefix | `…_Selector_367.txt` | `head -n 361 \| sha256sum` | `61918d9fbd7bf757437886f0e86776b60665c58e4d7283b81d42caca03c0288b` |
| **accepted 365 prefix** | `…_Selector_367.txt` | `head -n 365 \| sha256sum` | `6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1` |
| **CP4c-3 gate 367** | `…_Selector_367.txt` | whole file: `sha256sum` | `ef9d082f56f5c8de83124cf2e6257d098408cc597d9147b967cf9c84da4916bf` |

Verified at authoring per `AE4`/`AE5`: every value computed from the created bytes, each exactly 64 lowercase hex;
all 367 lines unique; each appended identity resolves to exactly one `TEST(...)`; and **all four earlier prefixes
reproduce their frozen hashes**, so `first_red_ordinal` stays comparable across the entire CP4c arc. Both appended
identities are **red today** — the mechanical fixture throws — and that is correct: a required-green selector states
what must hold for the checkpoint to close, not what passes today.

`selected_gate=NONE`; `gate_execution_authorized=false`. Freezing bytes is not selecting.

### 6.2 To be appended — named now so they cannot be silently omitted

These identities do not exist yet, so they are not in the frozen file. **AK7** makes their append mandatory and
named, producing gate **370**.

| identity to create | contract | phase |
|---|---|---|
| `GlobalTopologyPlan.PrescribedSphereWitnessDerivesRegionsThroughProductionEntryPath` | §4's decision: the sphere reaches A2b through the production path and publishes disc-proved regions | 2 |
| `SurfaceCutGraph.OrdinaryProposalSelectsTraceCrossedEdgeWithoutSaturation` | `R10-CAND-01`: the ordinary tree–cotree path selects a trace-crossed edge with `saturationUsed=false`; the AG5 witness is retained as the positive saturation case | 2 |
| `SurfaceCutGraph.EmptyNetworkOnClosedSurfaceIsRejectedWithTypedError` | `R8-CAND-02`: §2.2's decision, with the new appended error code and a locus | 2 |

The turn that creates them recomputes and records the 370 whole-file hash and re-verifies the 355 / 357 / 361 /
365 / 367 prefixes. Omitting any requires an explicit written rationale in that turn's report — silence is not a
decision (`LESSONS.md` 64w).

---

## 7. Prohibited

- **Designing a fix for the mechanical witness or the sphere before AK1/AK2 print the site.** Both are currently
  named by a collapsed code. CP4c-2 spent eight turns on exactly that mistake.
- **Renumbering or removing any existing `FieldAtlasBuildErrorCode` or `SurfaceCutGraphErrorCode` value**, or
  changing any existing error mapping. New provenance and new codes are **appended and additive** only — accepted
  identities consume the current values.
- **Reopening Amendments 12, 13 or 14**, or relaxing `proves_cellularity()`, the fragment-count invariant,
  `UncutFaceComponentOrbitSeedNotUnique`, or the actual-embedded-graph complex.
- **Changing accepted selector 365's bytes**, or any byte of 357 / 358 / 361, or 367 other than by AK7's append.
- **Treating `R10-CAND-01`'s corrective as a certification change.** It is a proposal-heuristic change; the
  certificate is untouched.
- **Introducing any tolerance** into a topological decision, or inferring a quantity the producers already publish
  exactly.
- Removing CP4c-2's diagnostic surface — `originatingTopologyError`, the AI2 fragment/orbit publication, the
  actual-embedded-graph oracle, the repaired D2 harness. They belong to the product now.
- A `DEFN` turn compiling, packaging, executing runtime, running a gate, or benchmarking.

---

## 8. Falsifiable predictions

1. The mechanical witness's `IncompleteCycleBasis` resolves to **one** of §3's eight sites, and it is **not**
   `:1597` (a `PCFaceTangentBundle::init` throw), because a throw would more likely have surfaced as a crash in the
   many turns this fixture has been loaded.
2. If it is `:1613`, `:1751` or `:1818`, the local-region-mesh shape published by AK2 will show a region whose
   boundary is not a disjoint union of simple loops — the count checks all derive from `boundaryLoops` and
   `isBoundaryVertex`.
3. The sphere's `RotationSystemInconsistent` resolves to one of the nine `sourceFace`-carrying sites in
   `EmbeddedGraphTopology.cpp` and involves source face `25-27-28`.
4. Fixing the sphere's producer failure does **not** make it cellular: its pre-cut `χ=6` against `sourceChi=2` is an
   independent measurement, so it will still need cuts, and they will be trace-crossed.
5. `R10-CAND-01`'s corrective changes **no** accepted identity's result, because the proposal heuristic has no
   certification authority. If any of ordinals 1–365 moves, the change was not confined to the heuristic and must
   stop.
6. The torus's accepted numbers are unchanged by everything in this checkpoint: `cutEdgeCount=28`,
   `torusRegionCount=4`, actual graph `V/E/F = 72/76/4`.

Prediction 5 is the one to check first and hardest. Prediction 1 is the one most likely to be wrong.

---

## 9. Measures **AK0–AK9**

The next turn is **`M3-CP4c-3-CB1`**, a phase-1 Code + Build that instruments and does not fix.

**AK0 — preconditions and frozen authority.** Accepted runtime predecessor is CP4c-2 at **365/365**, source
`57444781af7bdc460e38cc68930a9a8c8199eeea`, package `9736088354`. CP4c-3's gate is **367**, whole-file
`ef9d082f56f5c8de83124cf2e6257d098408cc597d9147b967cf9c84da4916bf`; recompute it and all four prefixes from
committed bytes at authoring and preflight, validate each as exactly 64 lowercase hex, and never transcribe. No
existing selector byte may change. Compile under `GMP_COMPILE_POLICY.md` with GMP/GMPXX, `runtimeExecution=false`.
`selected_r2_branch=NONE`, `selected_gate=NONE`, `gate_execution_authorized=false`.

**AK1 — print the A1 discriminator. Additive only.** Add an optional provenance field to `FieldAtlasBuildError`
identifying **which** of §3's conditions fired — an enumerated reason, not a line number (`LESSONS.md` 62's stale
`419/437/474` labels are the counter-example). Populate it at all eight sites. Print it wherever
`field_atlas_build_error_code_name` is printed today. **Prohibited:** changing which condition maps to
`IncompleteCycleBasis`, renumbering the enum, or adding a new `FieldAtlasBuildErrorCode` value in this CB. This is
AF0's template applied to A1; follow it exactly.

**AK2 — publish the local-region-mesh shape with the failure.** For the failing region, publish `V`, `E`, `F`, the
computed `eulerCharacteristic`, `boundaryLoopCount`, `genus`, `interiorLocalVertices.size()`, the resulting
`expectedCycleCount`, and the actual `bundle.cycles.rows()` / `cycleCurvatures.size()` / `innerAdjacencies.size()`.
The site alone will not explain a count mismatch; the counts will. Publish for **every** region of the mechanical
witness, not only the first failing one — a per-region row set, in the AG3 idiom.

**AK3 — print the sphere's site at nine-way granularity.** AF0 gave the sphere
`originatingTopologyError=RotationSystemInconsistent`; that is one code across nine `sourceFace`-carrying sites in
`EmbeddedGraphTopology.cpp`. Add the same enumerated-reason provenance so the site is identified, and publish it
through the existing frozen non-gating sphere diagnostic. **No product fix for the sphere in phase 1.**

**AK4 — `R10-CAND-01`, phase 2.** Model a trace crossing as a **per-face chord** in the proposal heuristic, matching
the fragment machinery, so a trace-crossed edge is interior to its component and reachable by the ordinary
tree–cotree search. Heuristic only: the certificate, the complex and Amendment 14 are untouched. Publish, per
witness, whether the ordinary path or saturation selected each trace-crossed edge. Keep the AG5 witness as the
positive saturation case and add the §6.2 identity for the ordinary case.

**AK5 — `R8-CAND-02`, phase 2.** Implement §2.2's decision: an empty network on a closed surface is rejected with a
**new, appended** typed error naming the empty network, with a locus. Do not renumber existing values. Add the
§6.2 identity.

**AK6 — the two product fixes, phase 2, on measured causes only.** The mechanical witness's A1 defect and the
sphere's A2a′ defect. Each CB states, in its report, the measured site from AK1/AK3 that it is fixing. **A fix whose
report cannot name the measured cause is not authorized.**

**AK7 — the three new identities enter the gate, by name.** §6.2's identities are created and **appended** to
selector 367 in the listed order, producing gate **370**. That turn recomputes and records the 370 whole-file hash
and re-verifies the 355 / 357 / 361 / 365 / 367 prefixes. Omission requires a written rationale.

**AK8 — enumerations.** Every measure in CP4c-3 that says "every consumer", "every site" or "every region" must
either contain the enumeration, produced by search, or require the implementer to produce and publish it by
**search** rather than by copying this document's tables. §3's eight-site table is a cross-check to compare against
*after* the implementer has produced their own — `LESSONS.md` 59 and 61 exist because a copied enumeration inherits
the author's omissions.

**AK9 — bookkeeping and prohibitions.** §7's prohibitions bind every CP4c-3 turn. Carry
`M3-CP4c2-TB-X2-CAND-04`, `M3-CP4c2-TB-X2-R10-CAND-01` and `M3-CP4c2-TB-X2-R8-CAND-02` as CP4c-3-owned with the
dispositions in §2 and §4. **Stable accounting remains 44 / 14 / 30**, produced-witness debt **5**, authoritative M3
packages **67**. Every TB continues to run the frozen non-gating selector in full or justify skips per identity
(`AF6`).

---

## 10. Stop / successor

The exact next turn is **`M3-CP4c-3-CB1`**, Code + Build, runtime-free, under **AK0–AK3** with §7's prohibitions.
Its successor is an artifact-only TB that executes gate **367** from ordinal 1 and publishes the AK1–AK3 evidence;
that TB's review then orders phase 2.

CP4c-2 remains **CLOSED / ACCEPTED at 365/365**. CP4c-3 is **open**; its gate is frozen at **367** and unselected.
