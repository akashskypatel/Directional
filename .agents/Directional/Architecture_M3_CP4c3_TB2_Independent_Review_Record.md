# M3-CP4c-3 TB2 Independent Review Record

## Status

**REVIEW COMPLETE / TB2 R4 EXECUTION VALID WITH ONE STATED QUALIFICATION / AMENDMENT 15 CONFIRMED EFFECTIVE AT
RUNTIME / NEW CAUSE ESTABLISHED BY ELIMINATION AND PROVED PRE-EXISTING / AMENDMENT 16 DECLARED /
MEASURES AN0–AN9**

This record adjudicates `M3-CP4c-3-TB2` (authoritative run `33355714664`, semantic package **69** artifact
`9742715856`, fixture-only execution package **70** artifact `9744461475`, semantic source
`005512f20ed56edc793f4d6505f3d2b4c2999c71`, frozen gate selector **373**) and, under the user's authorization to
combine a definition turn where one is needed, declares **Amendment 16**.

Review, definition and planning only: nothing was executed, compiled, packaged or benchmarked, no gate was selected
or run, and **no product, test, fixture, selector or build-logic byte changed**.

Measures issued here are **AN0–AN9**.

---

## 0. What this review verified independently, rather than accepting from the report

The working tree is byte-identical to the packaged semantic source:

```
git diff --stat 005512f20ed56edc793f4d6505f3d2b4c2999c71 HEAD -- src/ include/ tests/ benchmarks/   →  empty
```

so every source claim below describes exactly the binary that ran.

**Selector lineage recomputed from committed bytes, not copied.** Selector 373 is 373 lines, 373 unique identities,
SHA-256 `b47c269851fad1384b5dc9baaf674b3d4ad80ec6c2b40f7f8eda2055c6f44834`, and **all six predecessor prefixes
reproduce exactly**:

| prefix | recomputed from `head -n` of the 373 file | matches frozen |
|---|---|---|
| 355 | `e9d88f1196e412e06424294d6be22b32f01c9671ec5e4de119abd3f2fb5afeaa` | ✓ |
| 357 | `b896d0db7f26aeb0f3513418405efdeccbcf84fb6dc971500c6ddac9e364dc70` | ✓ |
| 361 | `61918d9fbd7bf757437886f0e86776b60665c58e4d7283b81d42caca03c0288b` | ✓ |
| 365 | `6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1` | ✓ |
| 367 | `ef9d082f56f5c8de83124cf2e6257d098408cc597d9147b967cf9c84da4916bf` | ✓ |
| 370 | `9160ea619afb9e10cbad30012d0bd354c263a2b749e690c271f653db3bf83525` | ✓ |

**AM8 was executed exactly as specified.** Ordinals 366–373 are, in order: the mechanical production path; the
rotation/face-walk agreement; the prescribed sphere; the ordinary trace-crossed proposal; the typed empty-network
rejection; and Amendment 15's three — `NonSeparatingBarrierEdgeIsAbsentFromLocalCycleBasis`,
`CutTransportDomainSatisfiesTheEulerCutIdentity`, `PrescribedSingularityOnABarrierArcRemainsBoundToACycle`.

`first_red_ordinal` therefore remains comparable across the whole CP4c arc.

---

## 1. Execution validity — ACCEPTED, with one qualification that must be recorded

R4's postflight reports every mutation flag false, the accepted **365 prefix green**, one identity per fresh
process from ordinal 1, and a first-red hard stop. The package-70 outer digest, its 55-entry internal manifest, the
semantic source commit, the packaged source archive digest, GMP/GMPXX link evidence, selector 373, the static
target map and executable modes were all proved before the first Directional process. **TB2 R4 is a valid semantic
red at ordinal 366.**

### 1.1 The package-70 substitution is acceptable — and here is exactly why, and what is not yet proved

A Test + Benchmark turn consumes an immutable package. TB2 executed a **different** package from the one CB2 froze.
That deserves an explicit finding rather than a footnote.

It is acceptable, on these grounds: package 70 adds no content, it **relocates bytes that were already immutable**.
The fixture tree was copied out of the embedded source archive whose SHA-256
`c7cd8b4bbba2d3b374da7c7f18e27c0e688ffe7679c261b644c6fffbf34426b1` matches the frozen authority, into the
`test-data` root the binary probes first. No configure, compile, relink, repair or source edit occurred, and the
user explicitly authorized the fixture-only regeneration.

**What is not yet proved is the load-bearing claim.** `semanticBinariesUnchanged=true` is asserted by the same
orchestration that produced package 70, and package 70's manifest has **55** entries against package 69's **28**,
so the two manifests are not comparable line for line. No per-binary SHA-256 from package 69 is published beside
the corresponding digest from package 70. Until that comparison exists in evidence, "the binaries are identical"
rests on the producer's own word. **AN2** requires it, and it is cheap: four digests, twice.

This is not scepticism about the outcome — ordinals 1–365 passing on both packages is strong corroboration. It is
the standing rule that a number and the expectation it is compared against must come from the same authority, and
that an executor may not be the sole witness to its own immutability.

### 1.2 The blocked first attempt, and a rerun rule that does not say what it means

The first attempt ran ordinals 1–40 green and stopped at ordinal 41 on fixture resolution. The frozen TB2 plan's
rerun rule (§ "Plan-Defined Reruns") says first-red ordering restarts from ordinal 1 **"only when the prior attempt
executed no Directional runtime; otherwise preserve the semantic run and route to review."** The first attempt
*did* execute Directional runtime — forty processes of it — so read literally, the plan forbade the restart that
R4 performed.

**The restart was nevertheless correct, and the rule is what is wrong.** The forty green processes produced no
semantic authority that R4 contradicted: R4 re-ran ordinals 1–365 from scratch and they passed. The rule conflates
*runtime executed* with *semantic authority produced*, and those are different things — a harness failure that
prevents a test from reaching its product path yields no verdict to preserve. **AN7** corrects the rule for future
plans: the restart test is whether the prior attempt produced a **semantic verdict**, not whether a process ran.

---

## 2. The headline result: Amendment 15 works, and it is the finding of this turn

Stated first and plainly, because a result that discharges a premise must be reported as a finding rather than left
as a field value.

- **The mechanical witness advanced past `IncompleteCycleBasis`.** TB1's stop was
  `IncompleteCycleBasis → CycleTransportAdjacencyMissing` at region 0, source edge `0-3`. That failure is **gone**.
  The cut transport domain is constructed, the tangent bundle initializes, the cycle basis is built and validated,
  the index accounting completes, and execution proceeds to a later stage of the same producer. Amendment 15's
  central mechanism — a barrier edge becomes a boundary edge, leaves `dual_cycles`' inner-edge columns, and can no
  longer demand a transport adjacency — is **confirmed at runtime**, on the witness it was designed for.
- **It regressed nothing.** Ordinals **1–365** — the entire accepted CP4c-2 gate, byte-identical prefix — are green
  on the cut implementation. A change this invasive to A1's local mesh construction leaving the accepted authority
  untouched is a real result.
- **CB2 implemented the endpoint rule better than the amendment specified it.** DEFN-R1 gave `copies(v)` as a
  formula (`d_B(v)` interior, `d_B(v) + 1` on the boundary) derived from the definition "connected components of
  `star(v) ∖ B(R)`". `make_local_region_mesh` (`src/authority/FieldTransportAtlas.cpp:1030-1104`) implements the
  **definition** instead — it flood-fills the star's face-adjacency graph with barrier edges removed and creates one
  local copy per component. That is strictly more robust: tips, branch vertices and boundary vertices all fall out
  with no special case, and a formula error is impossible because there is no formula. The barrier set
  (`:930-950`) is exactly `B(R)`, with `χ(B)` and `∂` derived alongside it.

**What is nevertheless still unproved.** First-red at 366 means ordinals **371–373 never executed**, so Amendment
15's own three self-checks — barrier exclusion from the cycle basis, the Euler cut identity, and unbound
prescribed singularities = 0 — have **never run**. AM1's barrier decomposition (`n/m/c/χ(B)/∂`, tree-or-cycle
shape, tips and branch vertices) was computed by the implementation but is **absent from the TB2 report**, so every
DEFN-R1 prediction remains unverified, including the falsifier "a measured cycle in `B(R)` reopens the amendment".
The amendment is *effective* and *unverified* at the same time, and both halves must be said.

---

## 3. The new cause — ESTABLISHED by elimination, and proved pre-existing

Measured: ordinal 366 first-red, escaping exception
`mechanical feature pipeline did not retain CP4c topology authority:
InvalidFieldTransportAtlas/field-transport-atlas/MissingSingularityBranchTransport`.

### 3.1 The mechanism, read at source

`build_singularity_attachments` (`FieldTransportAtlas.cpp:597-618`) walks the ordered one-ring fan of a singular
vertex and, for **every** consecutive pair, demands a branch transport on the radial edge between them:

```cpp
const FieldBranchTransportAdjacency *transport = find_branch_transport_in(branchTransports, *radial);
if (transport == nullptr) { error = { MissingSingularityBranchTransport, *radial, face.row,
                                      singularity.sourceVertex, singularity.topologyRegion }; ... }
```

Three facts settle what that means:

1. **The fan is global and must be closed.** `ordered_incident_fan` (`:351-402`) collects incident faces from
   `sourceMesh.F` — the whole source mesh — orders them by the `previousVertex`/`nextVertex` chain, and at `:398`
   **requires the walk to close back on its first face**. It takes no region, no barrier set and no local mesh. It
   is a source-mesh notion end to end.
2. **`branchTransports` excludes every barrier.** `build_branch_transports` (`:304-342`) is built purely from
   `adjacencies` (`:1827`), and `adjacencies` is bucket 4 of the classification at `:1456-1491` — everything
   classified `SourceBoundary`, `HardFeature` or `NonTraversable` is excluded by construction.
3. **The walk covers the entire ring**, `fanIndex` from `0` to `fan->size() - 1` with `nextIndex` wrapping.

So `find_branch_transport_in` returns null for a radial edge **exactly when** that edge is not in `adjacencies`.

### 3.2 The elimination — the same argument as TB1, one consumer later

The failing radial edge is not in `adjacencies`. It is therefore `SourceBoundary`, `NonTraversable`, or
`HardFeature`. On this witness:

| bucket | excluded because |
|---|---|
| `SourceBoundary` | region 0 covers all 300 faces with `boundaryLoops=0` and `globalEF = localEF = 1,158`; the domain is closed |
| `NonTraversable` | there is exactly **one** region over all 300 faces, and region flood-fill requires a shared raw component, so no edge crosses a region or component boundary |
| **`HardFeature`** | **the only remaining bucket** |

**A singular vertex of the mechanical witness is incident to a hard-feature edge, and the port derivation demands
transport across it.** This is the identical architectural disagreement TB1 established — *A1 assumes a
traversable domain where a barrier lies* — at a **different consumer**.

### 3.3 It is pre-existing and was merely unmasked — this is the decisive check

Call order in the current file: `build_branch_transports` at `:1827`, the region cycle-basis loop at `:1865`,
`build_singularity_attachments` at `:2384`. The cycle loop runs **first**, which is why TB1 stopped there.

And CB2 did not touch this path. The earliest hunk of CB2's diff to `FieldTransportAtlas.cpp` begins at old line
**842**; `build_branch_transports` (old `:304`), `ordered_incident_fan` (old `:351`) and
`build_singularity_attachments` (old `:480`) all lie **before** it and are unmodified:

```
git diff d260f6a9c 005512f20 -- src/authority/FieldTransportAtlas.cpp   →  first hunk @@ -842
```

**Therefore `MissingSingularityBranchTransport` is not a regression, not a side effect of the cut, and not a defect
in Amendment 15's implementation.** It is the next failure in a queue, revealed because the one in front of it was
removed. The mechanical witness got strictly further, and this is what "further" looks like.

### 3.4 The diagnostic surface failed again, in the stage phase 1 was sent to fix

The typed error at `:613-616` carries **four** locus fields: the radial `sourceEdge`, the `sourceFace`, the
`sourceVertex` and the `topologyRegion`. The gate identity reports **none of them**. The fixture builder
(`tests/FieldAlignedCurveNetworkTests.cpp:5283-5285`) composes its message from
`terminalFailureCode + "/" + terminalFailureStage` and discards the rest, so the review knows *which code* fired
but not *which vertex or which edge* — recoverable only by the elimination in §3.2.

This is pointed, because **AK1 and AK2 existed to fix exactly this** — one turn earlier, in the same producer, for
the neighbouring error code. Those measures added an enumerated reason and a full locus row for
`IncompleteCycleBasis`; they were scoped to *that code*, and the very next code in the same stage still publishes a
bare name. **Instrument the stage's error surface, not the site that is currently failing.** Recorded as
`LESSONS.md` **66**; owned by **AN1**.

---

## 4. My own measure was under-specified — owned, and it is the third instance of a known meta-pattern

**AM2** told the implementer that `globalVertexByLocal` becomes many-to-one and that **every consumer of it** must
be audited *by search, not by copying the DEFN's list*. CB2's report states that audit was performed, and I have no
reason to doubt it: `build_singularity_attachments` **does not consume `globalVertexByLocal`**, does not consume
the local mesh, and does not consume the cut at all. A faithful, diligent search on the key I specified would
correctly return nothing.

The defect is in the search key. I scoped the audit by **symbol** when the thing that needed auditing was an
**assumption**: *"the transport domain around a region or a vertex is fully traversable."* Every consumer holding
that assumption needed converting; only the ones touching a particular map got looked at.

This is the third instance of the family `LESSONS.md` 59 and 61 record — AF3 narrowed "the production torus
authority" to one of four products; DEFN-R2 §4 enumerated five Amendment-14 consumers and omitted a sixth — and it
is the first where the instruction to *search* was given correctly and still failed, because the predicate was
wrong. The refinement is therefore new and worth stating on its own: **when a change invalidates an assumption,
write the audit predicate as the assumption, and name at least one consumer that does not touch the changed data
structure**, to prove the predicate is not secretly a symbol search. Recorded as `LESSONS.md` **66**.

---

## 5. Amendment 16 — the generalization that should have been made at DEFN-R1

Declared normatively in `DESIGN.md` §7.2.1, and deliberately narrow about what it settles.

> **Amendment 16 — every A1 derivation that walks transport is a transport-domain operation.** Amendment 15 defined
> a region's transport domain as the region cut along its non-separating barrier set `B(R)`, and applied it to the
> cycle basis. It applies to **every** A1 derivation that traverses transport, without exception — including
> singularity port attachment, its incident-fan construction, and any future consumer. A barrier edge is never
> traversed, never supplied with a branch transport, and never required to have one. Where a derivation assumed a
> **closed** ring or a fully traversable neighbourhood, that assumption is replaced by the corresponding
> **transport-domain** object: the fan of one local copy — one connected component of `star(v) ∖ B(R)` — which is
> open when the vertex lies on a barrier.

**What Amendment 16 settles.** The prohibition, and the frame. Giving a barrier a branch transport so the ring
closes is the port-derivation form of Amendment 15's option **C** and is **prohibited** for the same reason: it
would let transport cross a feature. Deriving ports from a global closed fan while the cycle basis derives from a
cut domain is also prohibited, because it makes one product carry two contradictory notions of traversability —
and CB2 has already created that contradiction in miniature, since AM4 now binds a barrier-incident singularity to
a **slit boundary cycle** while `build_singularity_attachments` still demands a **closed transportable ring** for
the same vertex.

**What Amendment 16 deliberately does NOT settle, and why.** Whether an *open* sector fan should still emit
singularity ports, and how a vertex's index is apportioned when its star is split into several copies. Two
candidate policies exist and they differ in product-visible behaviour:

| policy | what it does | cost |
|---|---|---|
| **P1 — per-sector ports** | each local copy derives ports from its own open fan | ports exist but the closed-ring index identity does not hold per copy; apportionment across copies must be defined and proved |
| **P2 — boundary-absorbed, no ports** | a barrier-incident singular vertex derives **no** ports; its index is absorbed by the slit boundary cycle, exactly as AM4 already binds it | internally consistent with AM4 today, and cheaper — but **no traces start at that singularity**, a real A2a consequence that must be measured before it is chosen |

Choosing between them requires facts that have never been measured: how many singularities are barrier-incident,
whether they sit at tips, interior arc vertices or branch vertices, and what index each carries in the cut domain.
**AN4 forbids designing the correction until AN1 reports them.** This is the same discipline that has now shortened
five consecutive turns, and the temptation is strongest here precisely because P2 looks obviously consistent.

One structural fact is already established and should not be re-derived: **a tip does not escape.** At a
degree-1 barrier vertex `star(v) ∖ B(R)` has one component, so the vertex is not duplicated — but the ring walk
still straddles the single barrier ray, so the closed fan still fails. Every barrier-incident singular vertex is
affected, not only those on arc interiors.

---

## 6. The packaging defect is inside the artifact, not the orchestration — reclassify it

`M3-CP4c3-TB2-ORCH-01` is recorded as a resolved, non-stable **harness** defect. That misfiles it, and the
misfiling will cost a turn later.

`tests/TestFixturePaths.h:51-64` resolves the fixture root by probing `<exe>/../test-data`, then `<exe>/test-data`,
then returning the **compile-time absolute** `DIRECTIONAL_TEST_SOURCE_DIR` baked in by
`cmake/DirectionalTests.cmake:307,377,409`. That last value is the *build machine's* source directory. It is not a
fallback; on any machine but the builder it is a guaranteed miss, and on the builder it succeeds **by coincidence
of path**, which is precisely the kind of coincidence this project refuses to let an authority depend on.

Package 69's internal manifest has 28 entries and ships no fixture tree; package 70's has 55 and does. So the
packaged artifact **cannot locate its own fixtures**, and every future artifact-only TB will need the same
out-of-band remedy. That is a **build/packaging contract defect owned by a Code + Build turn**, not an orchestration
mishap that TB fixed and closed.

TB1 executed 366 ordinals on package **68** without hitting this, so something differs between the two packages or
between the two runners' paths. Which of those it is has not been measured, and the review does not guess: **AN3**
requires the comparison and the fix. Note the shape of the risk if it is left alone — a green TB could depend on a
runner's directory layout, which would make gate authority environment-dependent.

---

## 7. Disposition

- **TB2 is a valid semantic red at ordinal 366.** CP4c-3 remains **OPEN**. Gate **373** stays frozen and
  unselected; `selected_gate=NONE`, `gate_execution_authorized=false`.
- **Amendment 15 is confirmed effective and is not reopened.** No measured evidence contradicts it; its own
  self-checks are simply unreached.
- **Phase 2 continues** with the correction defined by Amendment 16's frame, but the **policy choice is blocked on
  AN1's measurement** (AN4).
- **Nothing disturbs CP4c-2.** The accepted 365 prefix is green in this very run.

Tracker dispositions this review sets:

- **`M3-CP4c3-TB2-CAND-01`** — **CAUSE ESTABLISHED** (§3): `build_singularity_attachments` requires branch
  transport on every radial edge of a globally-closed fan, and `branchTransports` excludes barriers by
  construction, so a barrier-incident singular vertex fails by construction. Pre-existing and unmasked, not a
  regression. Closes on ordinal 366 green in a run reaching at least 366.
- **`M3-CP4c3-DEFN-CAND-01`** — **RESOLVED AT RUNTIME**: the mechanical witness passed the cycle basis and
  advanced. Retained as active only for its unexecuted confirming identities (371–373).
- **`M3-CP4c3-DEFN-R1-CAND-01`** — unchanged and still **ACTIVE**; ordinal 373 never ran, so unbound prescribed
  singularities remain unmeasured.
- **`M3-CP4c3-TB2-ORCH-01`** — **REOPENED AND RECLASSIFIED** as a build/packaging contract defect (§6), owned by
  **AN3**.
- **New: `M3-CP4c3-TB2-REV-CAND-01`** — package-70 binary identity is self-reported and unverified against package
  69's per-binary digests (§1.1). Owned by **AN2**.
- `M3-CP4c2-TB-X2-CAND-04`, `R10-CAND-01`, `R8-CAND-02` — unchanged; their identities at ordinals 368–370 were not
  reached.

---

## 8. Measures **AN0–AN9**

The next turn is **`M3-CP4c-3-CB3`** — Code + Build, runtime-free, GMP/GMPXX linked.

**AN0 — preconditions and frozen authority.** Accepted runtime predecessor remains CP4c-2 at **365/365**. CP4c-3's
gate is **373**, whole-file `b47c269851fad1384b5dc9baaf674b3d4ad80ec6c2b40f7f8eda2055c6f44834`; recompute it and
**all six** predecessor prefixes from committed bytes at authoring and at preflight, validating each as exactly 64
lowercase hex. Never transcribe a digest. No existing selector byte may change. `selected_gate=NONE`,
`gate_execution_authorized=false`.

**AN1 — publish the locus before designing anything.** Two publications, both cheap, and the corrective may not be
designed without them.
1. **The failing locus.** Route `MissingSingularityBranchTransport`'s four existing fields — radial `sourceEdge`,
   `sourceFace`, `sourceVertex`, `topologyRegion` — into the reported diagnostic. Extend this to **every**
   `FieldAtlasBuildErrorCode` the mechanical and sphere witnesses can reach, not only this one: the whole point of
   §3.4 is that fixing one code at a time is what produced this turn.
2. **The barrier-incident singularity census.** For each witness publish: the number of prescribed singularities;
   how many are incident to `B(R)`; for each such vertex its barrier degree `d_B(v)`, whether it is a tip
   (`d = 1`), an interior arc vertex (`d = 2`) or a branch vertex (`d ≥ 3`), the number of copies its star splits
   into, and its index. Also publish AM1's barrier decomposition — `n`, `m`, `c`, `χ(B)`, `∂`, tree-or-cycle per
   component — which CB2 already computes and TB2 did not report.

**AN2 — prove package identity instead of asserting it.** Publish the per-binary SHA-256 of all four packaged test
executables from package **69** and package **70** side by side, and state whether they match. If a future TB again
needs a fixture-only transport package, this comparison is a precondition of using it, not a postscript.

**AN3 — fix the fixture-resolution contract in the package.** The compile-time absolute `DIRECTIONAL_TEST_SOURCE_DIR`
fallback must stop being an authority: either the packaging step ships the fixture tree at a package-relative root
the binary probes, or the resolver fails closed with a typed, actionable error naming the roots it tried. A silent
fall-through to a path that exists only on the build machine is prohibited. Also report whether package **68**
shipped a fixture tree, so §6's open question — package difference versus runner-path coincidence — is answered
rather than left.

**AN4 — do not design the port correction until AN1 reports.** P1 and P2 (§5) have different product-visible
consequences and the evidence does not yet choose. A correction whose report cannot name the measured
barrier-incident singularity census is not authorized. This is the same rule as AK6, AL4 and AM7, restated because
it has been the single highest-value control in this checkpoint.

**AN5 — the correction, once AN1 reports.** Implement Amendment 16 for `build_singularity_attachments` and its fan
construction: derive the fan within the transport domain, never demand or supply transport across a barrier, and
state in the CB report which policy (P1 or P2) was taken **and which measured fact chose it**. Resolve the
contradiction §5 names — AM4's slit-boundary binding and the port derivation must agree about the same vertex.

**AN6 — carry the unreached identities unchanged.** Ordinals 367–373 were never executed. AM7's sphere
instrumentation, `R10-CAND-01`'s ordinary-proposal identity, `R8-CAND-02`'s empty-network identity, and Amendment
15's three self-checks all stand exactly as compiled. **AL4 still forbids designing the sphere's fix**, and
Amendment 15's predictions remain unverified until ordinals 371–373 run.

**AN7 — correct the rerun rule in the next TB plan.** Replace "executed no Directional runtime" with **"produced no
semantic verdict"**: an attempt that fails in the harness before reaching a product path yields nothing to
preserve and restarts from ordinal 1; an attempt that produced a semantic red is preserved and routes to review.
State it in the plan's Plan-Defined Reruns section so the next executor is not choosing between the rule and the
right thing.

**AN8 — audit by assumption, and prove you did.** For Amendment 16, the audit predicate is *"this code assumes the
transport domain around a region or a vertex is fully traversable"*, **not** "this code touches a particular
symbol". The CB report must list the consumers found, the search that found them, and **at least one consumer that
holds the assumption without touching the cut data structures** — that last item is the evidence the predicate was
applied as an assumption rather than as a symbol search (§4).

**AN9 — prohibited.** Supplying a branch transport for a barrier edge, or otherwise closing a fan across a barrier
(Amendment 16's prohibition; the port-derivation form of Amendment 15's option C). Designing the port correction
before AN1 reports. Reopening Amendment 15, or 12/13/14. Renumbering or removing any existing error-enum value or
changing any existing mapping — new reasons and codes are appended only. Changing accepted selector 365's bytes, or
357 / 358 / 361 / 367 / 370 / 373. Weakening `proves_cellularity()`, the fragment-count invariant, or
`UncutFaceComponentOrbitSeedNotUnique`. Introducing any tolerance into a topological decision. Removing CP4c-2's,
CB1's, CB2's or this turn's diagnostic surface. Substituting a package in a TB without AN2's comparison.
Executing Directional runtime, running a gate, or benchmarking in a CB turn.

---

## 9. Falsifiable predictions

1. **AN1 will report at least one prescribed singularity incident to `B(R)`** on the mechanical witness. §3.2's
   elimination forces it; a census reporting zero falsifies this review's cause and CB3 must stop.
2. **The failing radial edge will be a member of `hardFeatureEdges`.** Same elimination.
3. **AN2's per-binary digests will match** between packages 69 and 70. A mismatch invalidates TB2's semantic
   authority retroactively and routes immediately to review.
4. **AM1's barrier decomposition will report `c ≥ 1` tree components and zero cycles** for the mechanical witness —
   DEFN-R1's prediction, still unverified. A measured cycle falsifies Amendment 15's Theorem 2.
5. **Ordinals 1–365 will remain green** after the Amendment 16 correction. The port path is upstream of nothing the
   accepted gate proves, so a regression there would indicate the correction reached further than intended.

## 10. Accounting

Unchanged: **44 events / 14 categories / 30 recurrences**; produced-witness debt **5**; authoritative semantic M3
packages **69**. Ordinal 366 belongs to a gate that has never been accepted and the accepted 365 prefix is green in
this very run: **+0 events / +0 recurrences.**

## 11. Exact next turn

**`M3-CP4c-3-CB3`** — Code + Build under **AN0–AN9**, runtime-free, GMP/GMPXX linked. It publishes AN1's loci and
census, discharges AN2 and AN3, and — only if AN1's evidence chooses — implements Amendment 16 under AN5.

CP4c-2 remains **CLOSED / ACCEPTED at 365/365**. CP4c-3 is **open**; gate **373** stays frozen and unselected.
