# M3-CP4c-2 TB-X2-R10 Independent Review Record

## Status

**REVIEW COMPLETE / R10 EXECUTION VALID / SELECTOR 365/365 GREEN / `M3-CP4c-2` IS CLOSED / ACCEPTED**

**`R9-CAND-01` CLOSED · `AH6` COVERAGE GAP CONFIRMED AND OPENED AS `R10-CAND-01` · `CAND-04` AND `R8-CAND-02`
CARRIED TO CP4c-3 · NEXT TURN IS `M3-CP4c-3-DEFN` UNDER AJ0–AJ9**

This record adjudicates `M3-CP4c-2-TB-X2-R10-EXEC` (run/job `33331453506 / 99310594268`, immutable CB9 package
`9736088354`, semantic/test source `57444781af7bdc460e38cc68930a9a8c8199eeea`, gate selector **365**). Review and
planning only: nothing executed, compiled, packaged or benchmarked, and no product, test, fixture, selector or
build-logic byte changed.

Measures issued here are **AJ0–AJ9**.

---

## 0. What this review verified independently

A green gate closes a checkpoint, so this review verifies rather than accepts. Everything below was checked against
the working tree, confirmed **byte-identical** to the packaged semantic source R10 executed:

```
git diff --stat 57444781af7bdc460e38cc68930a9a8c8199eeea HEAD -- tests/ src/ include/ benchmarks/   →  empty
```

Selector authority recomputed from committed bytes: whole-365
`6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1`, with `head -355`, `head -357` and `head -361`
reproducing `e9d88f11…5afeaa`, `b896d0db…64dc70` and `61918d9f…0288b`. The gate is unchanged from CB7's freeze.
**No selector byte moved anywhere in the CB9 → R10 edge**, so the green is against the same authority the checkpoint
has been measured on since AG7.

---

## 1. Execution validity — ACCEPTED

| requirement | evidence |
|---|---|
| immutable package consumed directly | artifact `9736088354`, ZIP SHA-256 `78f542c7…0490ebdf`, packaged source `2ea3ffcd…4bc21c5e` |
| preflight before any Directional process | package hash, internal manifest **28/28**, packaged source hash, source-status records, GMP/GMPXX metadata, executable modes, selector hashes/cardinality/uniqueness, exact identity resolution — all green |
| one identity per fresh process | selector run from ordinal 1, one process each; three non-gating identities each once |
| no mutation | `configure`/`compile`/`relink`/`repair`/`generatedDiscovery`/`sourceMutation`/`testMutation`/`fixtureMutation`/`selectorMutation`/`packageMutation` all **false** |
| no benchmark | `benchmarkExecution=false` |
| unconditional postflight | `postflightPass=true`; package and materialized-source byte/mode inventories matched preflight; internal manifest re-verified |
| gate result | **365 executed / 365 PASS / first red = none** |

`M3-CP4c-2-TB-X2-R10-EXEC` is a **valid semantic execution**.

## 2. The green is not vacuous — CB9's conversion audited line by line

A green gate is only as good as the change that produced it. The whole CB8→CB9 product diff is 104 lines in
`GlobalTopologyPlan.cpp`, 2 in `SurfaceCutGraph.cpp`, 18 in the test file. Every hunk was read.

**AI2 — `GlobalTopologyPlan.cpp:479-516`, correct and minimally scoped.**
`if (arcIndices.size() != 1U)` became `if (arcIndices.empty())`. That drops only the **upper** bound and **keeps a
typed `InvalidCutGraphBinding` for zero arcs**, exactly as AI2 required — it is not a blanket relaxation. The
per-face body now runs once per sub-arc; the `incident->second.size() != 2U` guard and the
`interiorDart >= walk.orbitByDart.size()` guard are both retained per iteration. The stale *"ordinary embedded
source-edge barriers"* comment was replaced with an arrangement-chord description that **explicitly names the
canonical-direction dependency** — *"build_arcs emits those sub-arcs in canonical cutEdge.first() ->
cutEdge.second() order; the source-face orientation below therefore selects the same side of every sub-arc with the
unchanged dart formula."* That was AI2's exact requirement, so a later change to emission order cannot silently
invalidate the dart formula.

**AI3 — `GlobalTopologyPlan.cpp:1264-1281`, and it *tightens*.** The two whole-source-edge inserts were replaced by
per-endpoint resolution through `nodeLoci`, inserting only when `locus->second.vertex.has_value()`. A crossing node
carries only an `edge` locus and therefore contributes nothing — precisely the rule AI3 specified. A node with **no**
locus now returns a typed `InvalidCutGraphBinding` with region, arc and source-edge set; that path did not exist
before. Since `boundaryVertices` is a skip list, **this change can only reduce skipping**, so it cannot manufacture
a pass — it can only create new reds, and none appeared. That is meaningful evidence in its own right.

**The `NodeLocus` authority is shared, not duplicated.** `build_node_loci` is now called **once** in
`build_region_certificates` and threaded into both `build_region_certificate` and
`validate_no_region_fragment_pinch` — which previously recomputed it for itself. AI3 said "no second node→vertex
lookup"; CB9 went further and removed a pre-existing redundant one. Consistent with AC1's single-authority rule.

**AI4** annotated `SurfaceCutGraph.cpp:298-300` with *"Proved by ordinal 359
SurfaceCutGraph.IsInvariantToSourceFaceAndEdgeEnumeration"* next to the `face.orbit` rationale — the falsifier now
sits beside the claim.

**AI5** replaced the fall-through in `build_surface_cut_graph` and `build_topology_plan` with `ADD_FAILURE()` plus a
`std::runtime_error` **carrying the stage name and typed code**, instead of the bare
`std::get: wrong index for variant`. The helper still throws, which is correct for a non-asserting helper, but the
exception now identifies the failure rather than obscuring it.

**Nothing in the diff weakens a check.** The single relaxation is the intended Amendment-14 semantic change, and it
retains its zero case. There is no witness substitution, no assertion removal, no tolerance, no enum change, and no
selector change. **AI8's exclusions were respected in full.**

## 3. AI2's reconciliation is proved by the product, not merely published

R10 retained `ai2-fragment-orbit-evidence.txt` with 178 rows — 50 `fragment_reconciliation` and 128
`cut_edge_orbit_evidence` — and correctly left interpretation to review. This review cannot open artifact
`9737796927`, so the row values are unread. **That is not an evidence gap, because the comparison AI2 asked for is
enforced in-product and was executed:**

`GlobalTopologyPlan.cpp:679-687` unconditionally rejects with `TraceCutFaceFragmentCountMismatch` unless
`fragmentOrbits[face].size() == tracePieceCount[face] + 1` **for every face**. That guard is untouched by CB9.
Ordinal 363 passed, which means `build_regions` ran to completion, which means the identity held on every face of
the AG5 witness — including the faces incident to a promoted trace-crossed edge.

So R9-REV §2.3's geometric argument — that sub-arcs `(v₁→p)` and `(p→v₂)` border **different** fragments of each
incident face, so a crossed edge contributes exactly the orbits the trace chords already imply — is **confirmed by
the product's own invariant**. The diagnostic rows are corroboration, not the proof. **AJ3** still requires them read
and their comparison stated, because a published number that nobody ever compares is how this project got the
`localizationConsistent` boolean.

Similarly, `edgeOrbitEvidence`'s multi-orbit case degrades safely: its only consumer (`:719-728`) seeds only from a
singleton set, and `UncutFaceComponentOrbitSeedNotUnique` still fires loudly downstream. Ordinal 363's pass exercises
that path on a witness that now produces multi-orbit entries.

## 4. `M3-CP4c2-TB-X2-R9-CAND-01` — CLOSED

Its frozen condition was *ordinals 363, 364 and 365 all green in a run reaching 365*. R10 satisfies it exactly, and
§2 confirms the fix was the conversion this review specified rather than an accommodation. **CLOSED.**

Two contracts get their first-ever runtime proof with it:

- **ordinal 364** — the **degree-four two-Cut/two-Trace edge-locus rotation**, the single genuine code gap DEFN-R2
  identified. It had been compiled and unexecuted for three turns. It now passes, so CB7's generalization of
  `edge_ray_points_to_second_endpoint` into the shared `edge_ray` owner is proved at runtime, not just statically.
- **ordinal 365** — the saturation last resort publishes `saturationUsed`, `saturationLocus` and
  `saturationPromotedEdgeCount`, and cellularity is still independently proved by the actual embedded-graph
  certificate afterwards. Saturation is not authority, and R10 shows it does not become authority.

---

## 5. `AH6` — the coverage gap is real, and its cause is mine

R10 published, for the AG5 witness:

```
ordinary_proposal_selected_trace_crossed_edge = no
saturation_used                              = yes
selected_trace_crossed_edge_exists           = yes
subdivided_crossing_exists                   = yes
```

AH6's stated condition has fired. I wrote at R8-REV §6 and again in AI6: *"if only under saturation, Amendment 14's
primary selection path is ungated and a second witness is owed."* It is, and one is.

### 5.1 What is nevertheless genuinely proved

The distinction matters and must not be overstated in either direction. Saturation changes **which edges are
selected**, not **how a selected edge is represented**. Ordinals 363 and 364 assert on a trace-crossed edge that was
actually promoted — `selectedTraceCrossed` non-empty, `foundSubdividedCrossing`, a degree-four node with two `Cut`
and two `Trace` rays. Those hold identically whichever path selected the edge. So Amendment 14's **representation**
— crossing nodes, exact ordering, arc and trace subdivision, the degree-four rotation, A2b's sub-arc binding, the
certificate — is fully and honestly proved.

### 5.2 What is not proved, and why the ordinary path structurally cannot reach it

What is unproved is that the **ordinary tree–cotree proposal can ever select a trace-crossed edge**. Reading the
committed loop settles the mechanism, and it is not accidental:

```cpp
barriers   = mandatory ∪ traceCrossed ∪ cuts;
components = proposal_components(topology, barriers);
for (component : components)
    proposed = proposal_tree_cotree_cut_edges(topology, component, barriers);
    for (edge : proposed) { if (mandatory.count(edge)) continue;  cuts.insert(edge); }
```

DEFN-R2 §4.5's **filter** was correctly removed — only `mandatory` is skipped now, `traceCrossed` no longer is. But
the **barrier set still contains `traceCrossed`**, so every trace-crossed edge *bounds* a proposal component instead
of lying inside one, and a tree–cotree generator search over a component draws from edges interior to it. **The
ordinary path therefore almost never has a trace-crossed edge available to propose**, and the only route by which
one enters the cut set is saturation, which promotes a component's remaining admissible edges wholesale.

**This traces directly to my own concession in DEFN-R2 §4.5**, which permitted keeping the conservative barrier set
on the reasoning that *"over-separation costs extra cuts, never correctness."* That was true about correctness and
wrong about coverage: over-separation does not merely cost extra cuts, it makes the edges Amendment 14 newly
admitted **structurally unreachable by the ordinary proposal**. DEFN-R2 prediction 5 said saturation firing anywhere
is "a finding". It fired, and this is the finding.

### 5.3 Disposition

**This does not withhold closure**, and the reasoning must be explicit because the temptation runs the other way.
Gate 365 was frozen at CB7 under AG7, before any of this was known; every identity in it passed; the run is valid.
Adding a coverage condition now would be moving the goalpost after the evidence arrived — the failure mode this
project has corrected twice, and the one I explicitly refused for `PR8-R044` at R7-REV when the evidence favoured
being strict. The discipline has to hold when it favours being lenient too.

**It does create a debt, at quality rather than correctness.** Completeness is unaffected: DEFN-R2 §5.1's theorem
guarantees a sufficient cut set always exists, and saturation reaching it is the theorem working as designed. What
is at stake is cut-graph *quality* — a saturated cut set promotes far more edges than a tree–cotree selection would,
producing many small regions — and the fact that a production witness firing saturation would now be
indistinguishable from this expected case.

Opened as **`M3-CP4c2-TB-X2-R10-CAND-01` — ACTIVE / QUALITY / COVERAGE / NON-STABLE**, owned by **AJ4**, with the
corrective candidate already identified: replace the conservative `traceCrossed` barrier contribution with the
per-face **trace-segment chord** model the fragment machinery already uses, so a trace-crossed edge is interior to
its component and available to the ordinary proposal. That is a representation change to the *proposal heuristic*
only — Amendment 13 §3 already labels it a heuristic with no certification authority — so it does not reopen
Amendment 14.

---

## 6. CP4c-2 closes with the prescribed sphere still failing, and that is by frozen design

The non-gating identity `GlobalTopologyPlan.Cp4c2PrescribedSphereCellularityScopeDecisionIsObservable` was **RED**
again in R10. It is an unconditional-`FAIL()` publisher, non-gating by decision recorded at DEFN-R2 §7 and before,
so it cannot and does not block closure.

It must nevertheless be said plainly, because a closure record that omits it would mislead: **CP4c-2 closes with one
of its three witnesses unable to reach A2b at all.** The sphere still carries two independent, unfixed problems:

1. the producer fails at `SurfaceCutGraph.cpp:240/243` with
   `originatingTopologyError=RotationSystemInconsistent` at source face `25-27-28`, `producerCutEdgeCount=0` —
   **before** cut selection, so Amendment 14 is not an account of it;
2. independently, its pre-cut actual embedded graph is **non-cellular** — `V/E/F = 18/30/18`, `c=1`, `χ=6` against
   `sourceChi=2` — so it genuinely needs cuts, and with 24 traces and zero mandatory edges they will be
   trace-crossed. Fixing (1) does not fix (2), and (2) is exactly the case §5's coverage gap governs.

That the sphere sits outside the gate was a deliberate, recorded scoping decision, not an oversight — but it is the
single largest piece of unfinished business leaving this checkpoint, and **AJ2** makes it CP4c-3's first-class
subject rather than a carried-over note.

---

## 7. `M3-CP4c-2` — CLOSED / ACCEPTED

Per the standing workflow — *"a green TB closes the checkpoint; there is no separate acceptance ceremony"* — and on
the verification in §§1–4:

**`M3-CP4c-2` is CLOSED / ACCEPTED at 365/365.**

| item | value |
|---|---|
| accepted source | `57444781af7bdc460e38cc68930a9a8c8199eeea` |
| accepted GMP package | `9736088354`, SHA-256 `78f542c775090968cde0d010cb9cd794d2c9deab15b42a7b29285f1d0490ebdf` |
| packaged source archive | `2ea3ffcd806e8f9ffc04efeb99cf05962017ce4ad03587f07d09b2aa4bc21c5e` |
| accepted gate | selector **365**, SHA-256 `6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1` |
| authoritative run/job | `33331453506 / 99310594268` |
| result / log artifacts | `9737796927` / `9737797177` |
| final result | **365 / 365 PASS**, first red none, postflight green, benchmarks not run |

**What CP4c-2 delivers.** Criteria **C1** (torus derives regions through the production entry path), **C3**
(rotation-system / face-walk agreement on the produced torus) and **C6** (disc proof plus mandatory preservation)
are green. A2a′ `SurfaceCutGraph` exists as a certified pre-region authority: it takes a closed genus-1 surface from
a non-cellular network to a certified cellular embedding with 28 cut edges, A2b derives four regions from it, and
the producer's cut count reconciles exactly with the independent oracle (`76 − 48 = 28`). Cellularity is certified
in the **actual embedded graph** (Amendment 13), trace-crossed source edges are admissible cuts with proved
completeness (Amendment 14), semantic and provenance identity are separate digests on both a bounded and a closed
witness, and enumeration invariance is proved rather than asserted.

**What it does not deliver**, recorded here so the closure is not read as more than it is: the prescribed sphere
(§6), the ordinary trace-crossed proposal path (§5), and the zero-node/zero-arc closed-surface question
(`R8-CAND-02`).

---

## 8. Measures **AJ0–AJ9** for `M3-CP4c-3-DEFN`

The next turn is **`M3-CP4c-3-DEFN`**, definition and planning only. CP4c-3's parent responsibility is the
closed-surface missing field-transport adjacency in A1 and then the mechanical witness (criterion **C2**), and it
now inherits three carried items.

**AJ0 — record the closure and its authority.** Write CP4c-2's closure into
`M3_CP4c_Consolidated_Record.md` §2 and `ROADMAP.md` §1 with the §7 table's exact identities. Update the
authoritative M3 package count to **67**. **Stable accounting is unchanged at 44 / 14 / 30**, produced-witness debt
**5**. Selector 365 becomes accepted authority; 357, 358 and 361 remain retained lineage. Recompute all four
prefix/whole hashes from committed bytes at authoring; never transcribe.

**AJ1 — freeze CP4c-3's gate by appending, and state per-identity membership.** The successor selector extends 365,
so `head -355`, `head -357`, `head -361` and `head -365` must all still reproduce their frozen hashes — that
property is what keeps `first_red_ordinal` comparable across the whole arc, and DEFN-R2 §7.3 records what happens
when an identity is *inserted* instead (candidate 358 broke it). State, per new identity, gating or not and why —
"it was never added" is not a rationale (`LESSONS.md` 64w).

**AJ2 — the prescribed sphere is CP4c-3's first-class subject, not a footnote.** Its two independent problems (§6)
must be separated in the definition: the producer's `RotationSystemInconsistent` at source face `25-27-28`, and the
measured pre-cut non-cellularity. Decide explicitly whether the sphere enters CP4c-3's gate. If it does not, say why
in writing — CP4c-2 closed with it outside the gate by a recorded decision, and repeating that silently would be the
`AF5` coverage failure a third time.

**AJ3 — read the AI2 rows and state the comparison.** Extract the 50 `fragment_reconciliation` and 128
`cut_edge_orbit_evidence` rows from retained result artifact `9737796927` and state explicitly whether
`fragment_orbit_count == expected_fragment_count` on every row, and what the per-face cut-edge `orbit_count`
distribution looks like on a crossed edge. §3 shows the product's own guard already proves the identity, so this is
confirmation and characterization rather than a gate — but a published number nobody ever compares is exactly how
the `localizationConsistent` boolean became meaningless. No new runtime.

**AJ4 — own `R10-CAND-01`.** Define the corrective for §5.2: the proposal heuristic's barrier set should model
trace crossings as **per-face chords**, matching the fragment machinery, rather than promoting whole trace-crossed
source edges to component barriers. This touches the **proposal heuristic only** — Amendment 13 §3 already denies it
certification authority — so it does **not** reopen Amendment 14 or any certificate. Require a witness in which the
**ordinary** proposal selects a trace-crossed edge with `saturationUsed=false`, and keep the existing AG5 witness
as the positive saturation case. Until that exists, treat `saturationUsed=true` on any production witness as a
finding to report, exactly as DEFN-R2 prediction 5 says.

**AJ5 — carry `R8-CAND-02` forward with a decision, not a deferral.** Zero-node / zero-arc closed-surface cut-graph
behaviour: A2a′ should either certify by cutting from scratch or reject with a typed error naming the empty network.
CP4c-3's definition either resolves it or states which later checkpoint owns it and why.

**AJ6 — preserve the diagnostic surface CP4c-2 built.** `originatingTopologyError`, the AI2 fragment/orbit
publication, the actual-embedded-graph oracle, and the repaired D2 harness are the instruments that made this arc
diagnosable. Do not retire them as CP4c-2 evidence; they belong to the product now. The frozen non-gating selector
must continue to be run in full or its skips justified per identity (`AF6`, `LESSONS.md` 64v).

**AJ7 — measures must carry their own enumerations.** Twice in this arc a measure listed items beside a universal
instruction and the list was read as the scope (`LESSONS.md` 59, 61). CP4c-3's measures must either contain the
enumeration, produced by search, or require the implementer to produce and publish it — and where they require it,
they must require a **search**, not a copy of the reviewer's table.

**AJ8 — prohibited.** No reopening of Amendments 12, 13 or 14. No change to selector 365's bytes, which are now
accepted authority. No relaxation of `proves_cellularity()`, the fragment-count invariant,
`UncutFaceComponentOrbitSeedNotUnique`, or any typed error mapping. No CP4c-3 implementation in the definition turn:
no compile, no package, no runtime, no gate execution, no benchmark. `gate_execution_authorized` stays `false`.

**AJ9 — bookkeeping.** Close `M3-CP4c2-TB-X2-R9-CAND-01`. Open `M3-CP4c2-TB-X2-R10-CAND-01` per §5.3. Carry
`M3-CP4c2-TB-X2-CAND-04` and `M3-CP4c2-TB-X2-R8-CAND-02` to CP4c-3 with owners. Stable totals remain
**44 / 14 / 30**, debt **5**, packages **67**.

---

## 9. Stable accounting

Unchanged: **44 events / 14 categories / 30 recurrences**; produced-witness debt **5**; authoritative M3 packages
**67**. Closing `R9-CAND-01` is a status change, not a count change; `R10-CAND-01` is a quality/coverage finding on
a checkpoint whose gate is green, and no accepted-green behaviour was ever lost — the inherited 355 is green in this
run as in the six before it.

## 10. Exact next turn

**`M3-CP4c-3-DEFN`**, definition and planning only, under **AJ0–AJ9**.

**`M3-CP4c-2` is CLOSED / ACCEPTED at 365/365.** CP4c-3 is unblocked.
