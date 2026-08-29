# M3-CP4c-2 DEFN-R1 — Frozen Definitions: the actual embedded-graph complex for A2a′

> **SUPERSEDED IN PART by `Architecture_M3_CP4c2_DEFN_R2_Frozen_Definitions.md` (2026-08-29). Never read this
> document alone.**
>
> - **§6 case 2 is withdrawn.** Amendment 14 makes a trace-crossed source edge an **admissible** cut. The stated
>   ground — that promoting one would subdivide an immutable trace — is false about this codebase: `build_arcs`
>   already emits one trace arc per network event and already splits a mandatory source edge at a trace terminal,
>   and the crossing point is already published exactly. §6 cases 1 and 3 stand.
> - **§8 is superseded.** Completeness is **proved** for all cases, not split: `network ∪ (source 1-skeleton)` is a
>   cellular embedding, so a sufficient cut set always exists. §8.2's typed stop
>   (`NoAdmissibleCutForNonDiscComponent`) is retired as an outcome, and §8.3's conditional trigger is void.
> - **§10 Option B is withdrawn**, its single trigger having been proved impossible; Option A stands and is now
>   unconditional.
> - **Everything else stands unchanged and binding** — Amendment 13, §§4, 5, 7, 9, and Amendment 12.
> - `DESIGN.md` §7.2.1 carries the normative record of Amendments 12, 13 and 14.

## 0. Turn type and verdict

`M3-CP4c-2-DEFN-R1` is **COMPLETE / DEFINITION-ONLY**.

No Directional runtime, build, compile, package, benchmark, product, test, fixture, or selector change was made
or is authorized by this turn. This document supersedes the withdrawn parts of
`Architecture_M3_CP4c2_DEFN_Frozen_Definitions.md` §5.4 and freezes the contract that `M3-CP4c-2-CB4` will
implement, under measures **AC0–AC9**.

**The decision.** The normative complex for A2a′ is the **actual embedded graph of
`FieldAlignedCurveNetwork ∪ cutEdges`**, represented by the **arc / dart / rotation / face-orbit machinery that
A2b already contains** — `GlobalTopologyArc`, `GlobalTopologyOrientedArc`, `GlobalTopologyNodeRotation`,
`walk_graph_faces` — lifted into a shared pre-region authority that A2a′ and A2b both consume. Nothing new is
invented; the correct representation already exists one stage downstream and is duplicated badly one stage up.

**Amendment 13** to `DESIGN.md` §7.2 records this. **Amendment 12 stands unchanged** — its precondition-versus-
repair boundary is unaffected and remains binding.

## 1. A reviewer error, owned precisely

`M3-CP4c-2-TB-X2-R2-REVIEW-PLAN` §5 declared the **source-mesh barrier complex** normative, on three stated
grounds. R5 has falsified it and the withdrawal is accepted in full. The failure is worth stating exactly,
because the same reasoning will be available to the next agent and must not be repeated.

I gave three reasons. Each was individually true and collectively wrong:

1. *"It is what A2b actually consumes"* — at `GlobalTopologyPlan.cpp:1694-1704`. **True, and irrelevant.** That
   code path is the *whole-source-face seeding fallback*, not A2b's region authority. A2b's actual region
   authority is `walk_graph_faces` over arcs and rotations, and it produces graph-face orbits. I read one
   traversal, matched it to the symptom, and never asked whether A2b had a second, primary representation.
2. *"The frozen DEFN §5.2 committed to source-edge-only cuts"* — **true, and a non-sequitur.** That cuts are
   drawn from source edges says nothing about which complex certifies them. A source edge added to the graph
   becomes an arc; it does not make whole source faces the unit of complement accounting.
3. *"In it, `V − E + F = χ` is a genuine identity"* — **true, and the trap.** The barrier complex is internally
   self-consistent. That is exactly why it was seductive and exactly why self-consistency is not evidence: a
   coherent computation over the wrong object is still the wrong object. R5 §6 states this correctly.

**The control that would have caught it existed and I did not apply it.** `LESSONS.md` **22d** — "check that
the product's representation can express the answer before debugging the algorithm that computes it" — and
**22e** — "converting a representation converts every consumer of it, or none" — were both written for
`PR8-R042 / M3-CP4b-R001`, the *same* `RP-01 / AUTHORITY_DOMAIN_CONFLATION` pattern, on the *same* two-ring
witness. 22d says in terms that a source face cannot be the atomic unit when trace arcs cross its interior.
Reading `LESSONS.md` in full is mandatory start-of-turn step 5. I did not consult it before freezing a
representation decision, and I froze the representation CP4ab had already rejected.

**Recorded for the next agent:** a review that names a normative representation must cite the accepted
architecture that settles it, not the code path that exhibits the symptom. Where an earlier checkpoint has
already adjudicated a representation, that adjudication is the authority.

## 2. Independent verification of R5's arithmetic

Recomputed rather than accepted:

| Complex, accepted two-ring | `V` | `E` | `F` | `V − E + F` | source `χ` |
|---|---:|---:|---:|---:|---:|
| actual embedded graph (CP4ab authority) | 9 | 11 | 3 | **1** | 1 |
| source-edge-barrier proxy (R4 D1) | 10 | 11 | 2 | **1** | 1 |
| what `SurfaceCutGraph` actually computes | 9 | 11 | **2** | **0** | 1 |

Both complexes are self-consistent; the producer is a mixture of the two, and `0 ≠ 1` is precisely what
`proves_cellularity()` rejects at `SurfaceCutGraph.cpp:473-474`. R5's localization is confirmed.

The actual-graph `F = 3` is independently corroborated: retained CP4ab evidence records
`walk.orbits.size() = 4` with exactly one exterior orbit, and `drafts.size() = 3` — one draft per interior
orbit. **`F = 3` is a measured product quantity, not a reconstruction.**

## 3. Amendment 13 — normative, supersedes DEFN §5.4 step 1

1. The complex in which A2a′ certifies cellularity is the **actual embedded graph** of the immutable
   `FieldAlignedCurveNetwork` together with the candidate `cutEdges`. Its vertices are network nodes plus any
   node created by a cut; its edges are network arcs plus cut arcs; its faces are the **dart orbits** of that
   graph under the node rotation system.
2. **Source-edge carrier provenance is not graph-edge authority.** A source edge that a trace merely crosses is
   support/provenance. It becomes a graph edge only when it is itself a mandatory edge or a selected cut edge.
3. The whole-source-face / source-edge-barrier partition is **withdrawn as cellularity authority**. It may be
   retained **only** as a cut-*proposal* heuristic and as diagnostic provenance, and every publication of it
   must carry an explicit label saying it is not a cellularity oracle.
4. `DEFN` §§5.1–5.3 — the product's position, single-writer authority, output shape and guarantees — remain
   **binding and unchanged**. §5.4's construction guidance is replaced by §§4–8 of this document.
5. **Amendment 12 is unaffected.** Establishing a precondition before a product is derived is still not
   repairing it afterward, and A2a′ still may not read a `GlobalTopologyPlan`.

## 4. The representation, named concretely

The implementation agent must not invent a representation. **All four pieces exist today in
`src/geometry/GlobalTopologyPlan.cpp` and `include/directional/geometry/GlobalTopologyPlan.h`:**

| Concept | Existing type / function | Meaning |
|---|---|---|
| arc | `GlobalTopologyArc` — `id`, `kind`, `firstNode`, `secondNode`, optional `mandatoryEdge`, optional `trace` | one exact arc of the embedded graph |
| dart | `GlobalTopologyOrientedArc` — `arc` + `orientation` | one directed side of an arc |
| rotation | `GlobalTopologyNodeRotation.counterClockwise` | the cyclic dart order at a node |
| face | `walk_graph_faces(arcs, rotations)` → `FaceWalkResult{orbits, orbitByDart}` | each orbit is one face boundary walk |
| fragment | `fragmentOrbits[SourceFaceTopologyKey] → {orbit}` | the CP4ab ownership unit: a source face split by the orbits crossing it |

**The corrective is a lift, not a rewrite.** A2a′ must consume this machinery rather than its own
`network_barriers` / `build_components` / `certify_component` triple. Move the arc-and-rotation construction and
`walk_graph_faces` into a shared pre-region authority — a new header under `src/geometry/` or an equivalent —
that both A2a′ and A2b include. **Do not copy it.** A second implementation is how this checkpoint arrived
here; `LESSONS.md` 22e requires one conversion covering every consumer.

## 5. Conventions that must be made exact, not assumed

These are the places where a plausible guess produces a wrong certificate. Each must be **written down in the
CB report with the reasoning**, not inferred from a passing witness.

- **5.1 Boundary orbits on a surface with boundary.** The accepted two-ring is a disc, `χ = 1`, and its walk
  yields **4 orbits of which exactly one is exterior**; `F = 3` counts interior orbits only. Freeze the rule
  that identifies the exterior orbit(s) and excludes them, and state how it generalizes to a surface with
  several boundary loops. For a **closed** surface — torus, sphere — there is no exterior orbit and every
  orbit is a face.
- **5.2 Disconnected graphs.** The torus's network is 48 arcs over 48 nodes with every node of degree 2 —
  a disjoint union of closed curves, so the graph is **not connected**. The Euler identity for a cellular
  embedding assumes connectivity; with `c` components it acquires a correction term. **Derive that term
  explicitly, state it, and verify it on the torus.** Do not adopt `V − E + F = χ` unqualified: on the torus it
  is false even before any cut is considered, and mistaking that for non-cellularity would be right for the
  wrong reason.
- **5.3 Nodes of degree 0, 1 and 2.** The rotation system must be well defined at every node, including the
  degree-2 nodes that dominate the torus and any isolated node. State the convention.
- **5.4 What counts as `V` and `E` when a cut shares an endpoint with the network.** A cut edge whose endpoint
  is already a network node adds an arc but no vertex; one whose endpoint is a bare source vertex adds both.
  The existing producer already attempts this at `SurfaceCutGraph.cpp:449-456` and must be re-derived in the
  new complex rather than carried over.

## 6. Cut semantics in the actual complex

This is the substantive new constraint, and it is where the previous design was silently unsound.

**A cut edge is a source edge promoted to a graph arc.** Adding it changes the arrangement. Three cases, and
all three must be handled explicitly:

1. **The source edge is untouched by any trace.** It becomes one arc between its two endpoints. Straightforward.
2. **The source edge is a carrier that a trace crosses at an interior point.** Promoting it creates an
   **intersection with an immutable trace arc**. That would subdivide the trace — mutating an immutable
   upstream product, which Amendment 12 forbids. **Such an edge is therefore not an admissible cut.**
3. **The source edge already is a mandatory edge.** It is already an arc; it cannot be "added" and must not be
   double-counted.

**Frozen rule: the admissible cut set is exactly those source edges that are neither mandatory edges nor
crossed by any trace at an interior point.** Admissibility must be decided exactly, from published trace
segment carriers, with no tolerance.

## 7. Certification, in one complex

Both certificates are recomputed from the actual combined graph. **No proxy quantity may appear in either.**

- **Per-face:** every orbit that is not an excluded boundary orbit must bound a disc. Publish, per orbit, the
  evidence used.
- **Global:** the Euler identity in the form fixed by §5.2, over `V` = graph vertices, `E` = graph arcs,
  `F` = counted orbits, against source `χ`.
- **Provenance:** each certificate carries the digests already required by DEFN §5.2 plus a **complex label**
  naming the actual-embedded-graph complex, so a future reader can never again mistake which object was
  certified.

**Prohibited:** mixing any barrier-partition count into either certificate; relaxing `proves_cellularity()` to
accommodate a count; and — restating R5 §5, which is correct — changing the global certificate to the proxy's
`10/11/2`, which would make the two-ring green while certifying the wrong object.

## 8. Cut-selection completeness — proved where it can be, typed stop where it cannot

Measure AB7 required a completeness proof or an explicit definition stop. **The honest answer is that
completeness is provable for one case and not yet for the other, and this definition freezes that split rather
than papering over it.**

- **8.1 Trace-free non-disc components — PROVABLE, and this is the torus.** Where no trace crosses the
  component, every source edge in it is admissible under §6, so a tree–cotree construction over the component's
  own primal and dual spanning trees yields generators whose promotion strictly reduces its first Betti number.
  The process terminates. **The torus is entirely in this case: it has 0 traces.** CP4c-2's own witness is
  therefore fully served.
- **8.2 Trace-crossed non-disc components — NOT PROVED.** With §6 removing every trace-crossed source edge from
  the admissible set, a component may have no admissible cut that reduces its genus. **No completeness claim is
  made.** The producer must, in that situation, **fail closed with a distinct typed error** — a new code such as
  `NoAdmissibleCutForNonDiscComponent`, carrying the component locus — and must never fall back to an
  inadmissible cut, a tolerance, or a partial cut set.
- **8.3 Why this is not a blocker in practice, and the condition on that claim.** The case in 8.2 arises only
  for a witness that is **both** non-cellular **and** trace-crossed. The torus is non-cellular and trace-free;
  the prescribed sphere is trace-dense and, on the standing prediction, already cellular and needing no cuts at
  all. **If the sphere turns out to be non-cellular, 8.2 becomes live and CP4c-2 must return to definition** —
  measure AC7 makes that an explicit stop rather than a surprise.

## 9. The independent oracle

AB8's independence bar is raised and made concrete. The oracle must:

1. build arcs, rotations and orbits **by its own construction**, not by calling the shared authority of §4 and
   not by calling `SurfaceCutGraph`;
2. publish actual graph `V`, `E`, total orbits, excluded boundary orbits, counted `F`, component count `c`,
   the §5.2 identity and its result;
3. publish per-source-face fragment/orbit structure, so the CP4ab representation is directly visible;
4. publish cut provenance — for each cut, its admissibility class under §6;
5. compare **term by term** against the producer's published certificate and report each difference
   individually;
6. carry `complex=actualEmbeddedGraph` on every record.

**Explicitly insufficient, and named because it was accepted once already:** a different implementation over
the source-edge-barrier partition. Self-consistency inside the wrong complex is not independence.

The retained `sourceEdgeBarrier` oracle is **not deleted**. It is relabelled diagnostic-only, keeps
`complex=sourceEdgeBarrier`, and must carry a field stating it is not a cellularity oracle. It remains useful
for measuring the proposal heuristic.

## 10. Sequencing, and the accepted regression

`PR8-R043 / M3-CP4c2-R001` — accepted ordinal 305 red — is the highest-priority item, and there are two ways to
clear it.

- **Option A — fix the certificate in the actual complex (RECOMMENDED).** Ordinal 305 fails because the
  certificate is wrong. Fixing it restores accepted behavior *and* delivers the checkpoint. The accepted
  identity is doing its job: it detected a real defect the moment CP4c-2 wired A2a′ into its path.
- **Option B — decouple A2a′ from the accepted path until the certificate is correct.** Cheaper and faster to
  green, but it restores the prefix by removing the check that caught the defect, and it re-opens the torus gap
  that CP4c-2 exists to close.

**Option A is frozen as the plan.** Option B is retained as a **contingency with one trigger**: if §8.2 goes
live — the sphere proves non-cellular and no admissible cut set exists — then CP4c-2 returns to definition, and
the accepted prefix must not be held hostage to that redesign. In that case, and only then, decoupling is
authorized so accepted authority is restored while the definition work proceeds.

## 11. Measures **AC0–AC9** for `M3-CP4c-2-CB4`

- **AC0 — preconditions.** Accepted historical authority remains CP4c-1 **355/355**. Preserve all six frozen
  selector files and hashes: 316 `601ce2b6…0193c`, 346 `20d3b0b1…3e46a`, 353 `51ff96d7…ac6a5`, 355
  `e9d88f11…5afeaa`, 357 `b896d0db…64dc70`, 358 `6eda3aad…b64fbe62`. Compile under `GMP_COMPILE_POLICY.md`
  with GMP/GMPXX; `runtimeExecution=false`. Keep `selected_r2_branch=NONE`, `selected_gate=NONE`,
  `gate_execution_authorized=false`.
- **AC1 — lift, do not duplicate.** Move the arc/rotation/face-walk construction of §4 into one shared
  pre-region authority consumed by **both** A2a′ and A2b. **A second implementation is prohibited** — that is
  `LESSONS.md` 22e. Report the exact file and symbol that now owns it and every call site converted.
- **AC2 — convert every consumer in one package.** A2a′'s per-face certificate, its global certificate,
  `GlobalTopologyPlan`'s consumption of the cut graph, and every diagnostic that reads either must move to the
  actual complex **together**. Enumerate them in the CB report and state, for each, that it was converted.
  **A partial conversion is the defect this checkpoint is correcting; it must not be the fix.**
- **AC3 — write the conventions down.** Publish §5.1–5.4's four conventions as prose plus code, with the
  derivation of §5.2's disconnected-graph correction term shown, not asserted.
- **AC4 — admissible cuts.** Implement §6 exactly: admissible = source edge that is neither a mandatory edge
  nor crossed by a trace at an interior point, decided exactly with no tolerance. Publish, per candidate cut,
  which class it fell into.
- **AC5 — the typed stop.** Add the §8.2 error code (`NoAdmissibleCutForNonDiscComponent` or an equally
  explicit name) with a component locus. **Never** fall back to an inadmissible cut, a tolerance, or a partial
  cut set. This code existing is not a failure of the design; it is the design refusing to certify what it
  cannot.
- **AC6 — derive the witnesses, never encode them.** The two-ring's `9 / 11 / 3 / χ=1` must fall out of the
  representation. **No witness-name branch, expected-value table, or constant.** If the representation cannot
  reproduce it without witness-specific logic, **stop and report** — §5's conventions are then wrong.
- **AC7 — the §8.2 trigger is a stop, not a judgement call.** If any witness reaches a non-disc component with
  no admissible cut, the CB **stops and returns to definition**. It does not widen admissibility, does not
  subdivide a trace, and does not proceed with a partial cut set.
- **AC8 — the oracle.** Implement §9's independent oracle as a **non-gating** identity, and relabel the
  retained `sourceEdgeBarrier` oracle diagnostic-only with the explicit not-a-cellularity-oracle field.
- **AC9 — prohibited.** Mixing any barrier-partition quantity into a cellularity certificate; relaxing
  `proves_cellularity()`; changing the global certificate to the proxy's `10/11/2`; subdividing or otherwise
  mutating an immutable trace; A2a′ reading a `GlobalTopologyPlan`; a second implementation of the arc/orbit
  machinery; encoding any witness's expected values; changing or inventing selectors; running a cumulative
  gate, R6, 357/358, `CB4`'s own acceptance, mechanical/C2, or CP4c-3; reverting AA1, whose innocence R5 §9
  establishes; and executing Option B of §10 outside its single stated trigger.

## 12. Falsifiable predictions

1. Under the actual complex the accepted two-ring yields `V = 9`, `E = 11`, counted `F = 3`, identity result
   `1 = χ`, **derived from authority**. Accepted ordinal 305 returns green.
2. The torus yields `V = 48`, `E = 48`, `c = 4` connected components, and — under §5.2's corrected identity —
   **non-cellular**, matching the frozen theorem. Its four complement components are annuli.
3. Every torus cut candidate is **admissible** under §6, because the torus has zero traces; §8.1 applies and
   the cut selection terminates.
4. The prescribed sphere, once measurable, is **already cellular** in the actual complex, needs zero cuts, and
   `CellularityNotEstablished` disappears for it. *(This is the standing prediction from DEFN §8.5, the X2 plan,
   and R4 — still unadjudicated across six turns. It is the load-bearing uncertainty.)*
5. `NoAdmissibleCutForNonDiscComponent` is defined but **never fires** on any of the three witnesses.
6. No accepted identity other than 305 changes state.

Prediction 4 is the one that decides whether §8.2 goes live. Prediction 2's correction term is the one most
likely to be got wrong on the first attempt.

## 13. Stop / successor

The exact next turn is **`M3-CP4c-2-CB4`**, Code + Build, runtime-free, under measures **AC0–AC9**.

Its successor is a fresh artifact-only **`M3-CP4c-2-TB-X2-R6`** — **not** a cumulative gate — which must re-prove
accepted prefixes 316/346/353/355 including ordinal 305, then publish the §9 oracle and the term-by-term
comparison, then attempt D2. `R5-ORCH-01` must be fixed in the runtime harness before R6: postflight must run
from an unconditional finalization or trap path so a red process cannot suppress it.

`selected_r2_branch` remains **NONE**, `selected_gate` remains **NONE**, `gate_execution_authorized` remains
**false**.
