# Durable Lessons — DURABLE, DO NOT DELETE

Consolidated operating lessons earned across M0-M3. Each was paid for with at least one failed
attempt, gate, or milestone. This document is durable project authority under `RETENTION_POLICY.md`:
lessons may be **corrected or extended**, but not deleted, weakened, or summarized away without
explicit user authorization.

**Reviewing this file is a mandatory start-of-turn step.** Before authoring a plan, a fixture, a
gate criterion, or a corrective measure, read the section that governs it. Most repeat failures in
this project were of a class already written down here.

Provenance is kept where it carries the evidence. Where two lessons said the same thing they were
merged; no distinct claim was dropped.

**Cite lessons by section and short title, never by number.** Numbers shift whenever a lesson is
inserted, so a numeric reference in another document silently rots into a pointer at the wrong
lesson.

---

## 1. Evidence and acceptance

### Structured diagnostic fields outrank grep over assertion prose

A machine summary must not infer a typed first rejection by grepping an entire GoogleTest failure stream for enum names. Assertion output prints expected values before actual values, so the expected enum can be misclassified as the observed rejection. Prefer a structured product diagnostic or parse the explicit actual field; retain identity-scoped raw streams as final authority. A reporting-parser defect does not invalidate otherwise correct selector/process/package evidence, but it must be corrected before its classification field is used for planning.


1. **Compile success is build evidence, never semantic acceptance.** Two independent corollaries,
   both paid for: a compile-green package can be **contract-incomplete** (M3-CP1 package 1 passed
   123/123 and had not implemented the frozen contract), and a compile-green package can be
   **semantically wrong**. Re-run the closeout source audit before calling any package an
   acceptance candidate; if the audit proves partial implementation, do not freeze a selector or
   promote the artifact.
2. **A zero-selected test filter is orchestration failure, never a pass.**
3. **A compile-green package is not TB-runnable authority unless it contains every executable that
   owns the frozen selector.** A missing owner binary is pre-semantic package closure, not a
   partial pass.
4. **Changed-block coverage is a candidate set, not required-green authority.** Before promoting a
   red changed-block test into a gate, run that exact identity against the accepted predecessor. If
   it is already red there, keep it visible as inherited/non-gating until its precondition is
   independently repaired. Never manufacture a regression by changing the selector without a
   differential.
5. **Checkpoint-static scanners are immutable historical evidence, not current semantic truth.**
   When accepted later work legitimately changes package layout, source-list indirection, or typed
   representation counts, replay the scanner against its exact accepted source and reconcile the
   delta with a fresh fail-closed audit. Do not weaken the historical baseline, and do not treat
   name-only drift as a semantic regression.
6. **An audit passing means the family was in scope, not that the family is closed.** Record
   out-of-scope families as explicit decisions; otherwise a passing audit reads as proof of absence.
7. **Never treat a documentation or control-plane commit as implementation, build, test, or runtime
   evidence.** A **triggered** workflow is one step further from evidence than a completed one:
   firing a gate proves only that it was fired. A checkpoint is closed by a recorded result — run
   identity, artifact digests, per-group counts, immutability flags — never by the commit that
   launched it. M3-CP2b was reported closed on exactly that basis, with the gate triggered and no
   result in the repository; the claim was rejected, and the same checkpoint closed cleanly one turn
   later once the result was supplied. Rejecting the first claim cost one turn; accepting it would
   have put a fabricated acceptance into the durable record.
8a. **Consolidation must not orphan a citation that another durable document calls binding.** CP4ab's
    closure retired 34 per-turn documents; twelve normative attribution lines in the frozen-definitions
    document and two in the M3 plan then pointed at files that no longer existed. The retirement was
    *correct* — every amendment had inlined the content it froze — but a future agent following
    "`X.md`, binding" would find nothing and could not tell "authority inlined here" from "authority
    lost". Before retiring a cited document, either inline what is load-bearing **and annotate the
    citation as retired provenance**, or keep the file. Do one or the other in the same turn that
    retires it.
8b. **A routing pointer is only as good as the section it names.** Four documents — the task index, the
    handoff, the closing report, and the closure record — all routed the next checkpoint to "section
    4A.3c". No such section had ever existed; the content lived under a differently-numbered heading and
    was a scope statement rather than a decomposition. Nobody noticed because nobody had yet followed
    the pointer. **Resolve every forward routing pointer at the turn that writes it**, not at the turn
    that has to act on it.
8c. **"Through the production entry path" is a claim about production code, not about a fixture.** Two
    CP4c identities were named `…DerivesRegionsThroughProductionEntryPath` and planned as fixture work
    for three checkpoints, while the product they assert on — `GlobalTopologyPlan` — was never
    constructed by the pipeline at all. One grep would have shown it at any point. **When an identity
    name asserts that production reaches a product, grep production for that product before sizing the
    checkpoint.**
8. **Consolidation follows verification; it never precedes it.** The per-turn reports a closure
   record would retire are the very evidence that record must consolidate. Retiring them on an
   unverified claim destroys the material and leaves nothing to reconstruct from. When a closure
   claim cannot be verified, write no closure record, retire nothing, and say plainly what evidence
   is missing and what would satisfy it.

### A premise-discharging result must be reported as a finding

A diagnostic turn can stop on a separate contract violation and still establish a load-bearing premise for the checkpoint. When preserved evidence proves that an upstream product exists, reaches a stage, or satisfies a control theorem, report that fact explicitly as a finding instead of leaving it buried as one field in a larger record. A red turn blocks acceptance; it does not erase independent facts that its admissible evidence established.

## 2. Fixtures and witnesses

8d. **"The fixture exists" is not "the fixture reaches the stage you are asserting on."** CP4c named
    two committed witnesses as verified, and what had actually been verified was that four files exist
    and that one of them could be driven through a **legacy** product call. Neither had ever been
    through A1, A2a, or A2b — the three stages its six identities assert on. Six identities were then
    authored against them, and all six failed in fixture construction. **Before authoring an identity
    against a witness, prove the witness reaches the product stage the identity reads, and record which
    stage that is.** A `-DEFN` turn must state this for every witness it names.
8e. **A rejection code shared by many conditions makes the next turn guesswork.**
    `RegionCutComponentCountDeficit` is emitted at **18 distinct sites** for 18 different conditions,
    four of them inside the single loop that rejected the torus. The evidence therefore localizes the
    failure to an 18-way ambiguity, and no corrective measure can be chosen from it. This project froze
    a rule against exactly this after CP4b emitted one code at seven sites; the rule was not applied to
    code that already existed. **Splitting an overloaded code is a legitimate first corrective measure
    on its own** — it changes no behaviour and it is what makes the next measurement mean something.

9. **A fixture that satisfies a contract's precondition trivially cannot falsify it.** This class
   has now cost four M3 checkpoints:
   - **CP1** — A1's fixtures were entirely planar (`z = 0.0`), so a curvature-sensitive cycle
     invariant was only ever evaluated at the degenerate `0 ≡ 0` point;
   - **CP2** — `rails_from_atlas(...)` built one single-edge *open* rail per barrier, so
     `|V| == |E|+1` held unconditionally and six identities passed a builder that rejected every
     closed production rail;
   - **CP2b** — the skew index-1 helper hard-coded an ordered face pair the mesh does not promise,
     so three consecutive attempts died in fixture construction without ever reaching a semantic
     seam;
   - **CP3a** — the one-ring fan was reused on the strength of a previous green gate, but every edge
     opposite its singular vertex is a boundary edge, so the required multi-face traversal was
     unsatisfiable on that mesh **by construction**.

   The corrected CP3a fixture is the pattern to copy: it **asserts its own precondition at runtime**
   (every singular-fan opposite carrier must be interior) rather than trusting the author to have
   picked a capable mesh.

   Name the shape the production producer actually emits, and build the fixture in that shape.
10. **A non-vacuity requirement is only as good as the check that the witness *can* satisfy it.**
    The CP3a plan mandated "one candidate crossing more than one face" and reused a proven witness —
    but never checked that the reused mesh could produce one. It could not: in a one-ring fan the
    first outgoing carrier is by definition the edge opposite the singular vertex, and every such
    edge is a boundary edge, so every candidate stops on its first step. When you write a non-vacuity
    requirement, derive from the witness's own topology that it is **satisfiable**, not merely
    desirable. Reusing a proven witness proves it was non-degenerate for *its* contract, not for the
    next one.
11. **Green identities on a degenerate witness are not evidence either.** Two of CP3a's six passed
    only because nothing moved: the barrier-stop contract passed because every candidate stopped at a
    barrier immediately, and the ordering-invariance contract passed over single-segment candidates.
    A red diagnostic can make a checkpoint look partly proven when the passes sit on the same
    degeneracy as the failures. Re-audit the passes whenever the failures are attributed to the
    witness.
12. **"Producer-equivalent setup" is the licence that defeats the check.** If a plan permits a
   hand-assembled stand-in for producer output, that is the wording a future attempt will use to
   rebuild the same vacuous fixture. Require derivation from real topology or from the accepted
   producer.
13. **A planar fixture is not automatically vacuous — name the precondition it exercises.** The
    planar square has zero geometric field transport but nontrivial boundary-cycle aggregation, and
    exposed stored-zero support/curvature inconsistency directly. Vacuity is a property of the
    fixture against *this* invariant, not of the fixture alone.
14. **Check the fixture's geometry and topology against the invariant's content.** Before crediting
    or dismissing a fixture, name every quantity the invariant depends on and confirm which are
    intentionally zero and which must be nonzero.
15. **A producer's output shape is part of the convention a fixture must consume, not just its
    values.** M3-CP2b derived matching, effort, and index correctly from the accepted producer and
    still failed, because it hard-coded the *cardinality* of `singularCycles`. Deriving the numbers
    is not enough if the fixture still dictates how many there will be, what domain they cover, or
    how they are keyed.
16. **A fixture must not restate a convention the repository already owns — it must consume it.**
    Hard-coded expected matching, effort, face-pair order, orientation, or index is the fixture
    asserting a convention it cannot enforce. Derive expected values from the accepted producer or
    from the same signed authority the product uses, then assert the semantic property.
17. **An acceptance fixture must establish its intended precondition independently before its
    assertion becomes required-green evidence.** An inherited baseline-red supplemental test stays
    visible but cannot be promoted by naming it part of a new gate.
18. **A fixture that copies legacy raw IDs into typed fields cannot prove typed authority
    independence.** Derive typed expected owners independently from canonical topology, or use
    metamorphic renumbering.
19. **One acceptance test must not require two mutually exclusive execution paths.** If a fast path
    returns before a later fallback seam, prove each contract with a witness that actually reaches
    its owning path.
20. **Arrangement-local typed scope is not proof that a downstream API received independent source
    authority.** When a seam consumes source authority explicitly, the fixture must construct and
    pass that authority from source inputs; a valid ownership registry cannot substitute for a null
    API authority pointer.
21. **When semantic authority moves, counterfactual injection authority must move with it.** A seam
    that mutates only a legacy diagnostic or shadow object after the production sidecar was captured
    no longer proves the consumer contract. Migrate the seam to the declared product; never restore
    reachability by reading the shadow back into production authority.
22. **One member carrying two semantic domains is a single-authority violation even inside a
    fixture.** When a helper populates two members from two inputs and the caller passes the same
    input twice, the domains coincide by accident and stay invisible until another fixture separates
    them. Name the domains and populate each explicitly.
22j. **A re-proof stop locates when a regression was detected, not necessarily when it was introduced.**
    R5's accepted-prefix check first exposed ordinal 305 immediately after AA1, but source comparison proved the
    failing `SurfaceCutGraph` semantics predated AA1 and AA1 was only snapshot observability. A frozen "any red
    reverts the latest change" rule would have removed a correct fix while preserving the actual defect. Route
    rollback by causal ownership, using the re-proof as a detection boundary rather than a blame boundary.
22i. **A self-consistent oracle can still certify the wrong semantic object.** CP4c-2 repaired a mixed Euler
    equation by putting `V/E/F` into one named `sourceEdgeBarrier` complex; the arithmetic became coherent, but
    CP4ab had already proved that whole source faces cannot represent embedded graph faces when traces cross face
    interiors. On the accepted two-ring the proxy is valid at `10/11/2` while the actual graph is valid at
    `9/11/3`. Independence means a different mechanism over the **same semantic complex**, not merely internally
    consistent arithmetic over a different one.
22h. **A stop that costs nothing is worth more than a fix that costs a gate.** CP4ab's CB-R8 stopped at
    a binding precondition, wrote a hand derivation, and changed no byte — and it prevented a correction
    that would have made the arithmetic green while leaving the structural defect in place. Three of this
    checkpoint's stops did that. Write preconditions that can fire *before* mutation, and make the stop a
    first-class outcome rather than a failure.
22g. **A retained record can describe something that never happened.** CP3b's first-contact trim keeps
    the contacting segment, and that segment's non-optional `outgoingCarrier` names the edge the trace
    *would* have crossed had it continued — an edge it never reaches. Reading it as a real exit would
    fabricate a separating cut where the product has only a slit. When a struct field is
    non-optional but the situation it describes is conditional, find the companion field that says
    whether it applies — here, `terminalBarrier`.
22f. **A guard that runs earlier can silently shadow the guard a negative test targets.** CP4's B3 was
    green, then red at a *different* code, because a later revision moved orbit resolution ahead of the
    interior-singularity check. Both guards were correct; the ordering made one unreachable. When a
    negative regresses to a different rejection code, suspect ordering before suspecting the contract —
    and prefer moving the shadowed check earlier over weakening the test to accept whatever arrives.
22n. **A cryptographic digest is written in full, or replaced by a file reference and the word "recompute" —
    never as `PREFIX…SUFFIX` where a value is expected.** An abbreviated hash in a table of values is a
    *reference* wearing a value's clothes, and a later reader cannot reliably tell the difference. Four
    abbreviated selector digests were expanded back to full length by inventing the middle, travelled through a
    build report into an execution plan, and stopped a turn before its first process. One of the fabrications
    was **63 characters** — not even a valid SHA-256 — and nothing in the authoring path checked. Validate every
    expected digest as exactly 64 lowercase hex at the moment it is written, and prefer naming the source file
    and derivation (`head -N <file>`) over transcribing the number at all: a transcribed constant cannot
    distinguish drift from mistranscription, which is the whole reason the mismatch cost a turn to diagnose.
22k. **A review that names a normative representation must cite the architecture that settles it, not the
    code path that exhibits the symptom.** CP4c-2's R2 review declared the whole-source-face barrier partition
    normative on three grounds that were each individually true — it is what one A2b traversal consumes, the
    frozen definition had committed to source-edge cuts, and `V - E + F = chi` holds inside it — and
    collectively wrong. The traversal it cited was a seeding fallback, not A2b's region authority; cut
    *provenance* says nothing about certification *complex*; and internal self-consistency is exactly what a
    coherent computation over the wrong object looks like. `PR8-R042` had already adjudicated the same
    representation question on the same witness, and lessons **22d** and **22e** recorded the answer. Reading
    `LESSONS.md` in full is mandatory start-of-turn step 5; the control existed and was not applied. **Before
    freezing a representation, search for a prior checkpoint that already adjudicated it — a stable regression
    ID in the tracker is the cheapest place to look.**
22p. **A non-gating diagnostic that iterates witnesses publishes one row per witness; a report that quotes one
    row has withheld evidence the run already paid for.** R7-3 iterated two-ring, torus **and prescribed sphere**
    and published an independent actual-embedded-graph oracle row for each. The EXEC report quoted the torus row
    only. The sphere's row is the exact measurement the checkpoint's standing prediction had been waiting six
    turns for, and it was sitting unread in the retained result artifact. **Before planning a new run, check
    whether the last one already answered the question**: an artifact read is orders of magnitude cheaper than a
    turn, and a diagnostic loop's value is per-witness, not per-test.
22q. **A witness synthesized inside a test is not the witness the project reasons about, and it needs its own
    proof of existence.** The torus semantic/provenance diagnostic built its atlas from a locally synthesized
    zero-transport field rather than the committed `torus.rawfield` the production fixture uses. That synthetic
    torus has no production counterpart and had never been shown constructible; the zero-effort cycle lift is
    integral on a flat mesh and generically non-integral on a curved closed surface, so the diagnostic failed at
    its own precondition before comparing anything. Two identities shared the construction and neither had ever
    run green. **Derive a witness from the production authority whenever one exists**, and when a test must
    synthesize an input, give it an executed precondition of its own rather than assuming the helper that works
    on the flat fixture works everywhere.
22m. **Self-consistency inside a named complex is not evidence that the complex is the right one.** Both the
    actual embedded graph (`9/11/3`) and the source-edge-barrier proxy (`10/11/2`) satisfy `V - E + F = chi`
    on the accepted two-ring. An oracle can therefore be arithmetically flawless and still certify the wrong
    object, and a "self-consistency" assertion will never detect it. Pair every such check with an
    independent statement of *which* semantic object is being measured, and make the complex label a published
    field so a later reader can tell the two apart.
22e. **Converting a representation converts every consumer of it, or none.** CP4 moved region ownership
    from whole source faces to face fragments and left the disc certificate and its oracle computing on
    whole faces and whole edges — so the next gate failed one level down, at connectivity instead of
    cardinality. Each partial conversion costs an attempt and looks like a new defect. When you change
    what a thing *is*, enumerate every place that reads it and convert them in one package.
22d. **Check that the product's representation can express the answer before debugging the algorithm
    that computes it.** CP4 spent four turns failing to satisfy `cutComponents.size() == drafts.size()`
    when whole-source-face ownership *cannot* express a face of the embedded graph at all: mandatory arcs
    run along source edges but trace arcs cross face interiors, and a source face is atomic. On the
    accepted witness the entire singular fan collapses into one cut component while the rotation walk
    correctly reports one orbit per sector, so the equality was unsatisfiable rather than merely unmet.
    When a condition fails identically on every attempt, ask whether the representation admits any
    satisfying value before asking why this one does not.
22c. **A total partition is not a correct partition.** A flood fill, a nearest-seed assignment, or any
    "assign every leftover to something" rule always yields a complete, disjoint cover. Asserting
    completeness and disjointness therefore tests the algorithm's shape, not its semantics. Assert the
    *relation* that defines ownership — for a region, that the face is the one its boundary encloses.
22b. **A witness proven adequate for one checkpoint's contract is not thereby adequate for the
    next one's.** "It was green in the previous gate" says the mesh was capable of *that* contract.
    CP3a's plan directed reuse of the accepted CP2b fan on exactly that reasoning; the fan could not
    express multi-face traversal at all. Re-derive capability against the *new* contract before
    reusing a witness, and encode the result as a runtime assertion inside the fixture.

22r. **A fixture helper's silent precondition surfaces the first time a witness stops being degenerate — and the
    helper, not the witness, is the defect.** `make_zero_transport_field` declares `effort = 0` on every edge and no
    singularities. `FieldTransportAtlas` derives a cycle's lift as `(cycles·effort + 4·cycleCurvature)/2π`, so that
    declaration is consistent **only** on a mesh with zero angle defect at every interior vertex. Every consumer
    before AY5 satisfied it by accident — `make_four_triangle_fan` is entirely planar. AY5 needed the project's
    *first* non-flat star, because a flat star cannot separate `β = α + Θ/2` from `β = α + π`; it inherited the
    flat-only helper unchanged, and the resulting folded cone (`Θ = 3π/2`, `K = π/2`, so lift `1`) was refused by
    the atlas with `CycleTransportMismatch` before the identity's first assertion ran.
    Two things to carry forward. First, this is the degenerate-fixture family arriving from the opposite direction:
    not a witness too degenerate to exercise the code, but a **helper too degenerate to describe the witness** — so
    the control is the CP3a one, **make the helper assert its own precondition at runtime**. Second, a witness spec
    that enumerates geometric properties must also state the *consistency* the product will check: production
    terminates traces at singular vertices before vertex-star transit ever runs, so a vertex-star witness with a
    non-flat centre must carry `Σ_cycle effort = −4K` and a matching composing to lift `0`, or the vertex it is
    built around is a singularity and the path it exists to test is unreachable.
    `Architecture_M3_CP4c3_TB7_Independent_Review_Record.md` §5.

22s. **A shared fixture helper that returns all-or-nothing converts every downstream failure into a blackout over
    every upstream contract that uses it.** `cp4c_mechanical_fixture()` throws unless all five of
    `sourceAuthority`, `atlas`, `network`, `cutGraph` and `plan` are retained. Two gate identities that assert only
    about the **A1 atlas** — the non-separating barrier-edge cycle-basis witness and the Euler cut-identity witness
    — therefore abort in the fixture constructor whenever anything three stages downstream fails, and Amendment 15's
    two contracts have been *unmeasured, not falsified* across nine consecutive Test + Benchmark turns for a reason
    that has nothing to do with either of them. The identities were correct, the products they need were built and
    green in the very same run, and nobody was wrong at any single step.
    **Scope a fixture helper's precondition to what its consumers actually read**, or give it per-stage accessors, so
    an identity is blocked only by the products it asserts about. A helper is also a gate: an over-strong
    precondition silently converts an unrelated red into missing evidence, which is the most expensive kind because
    it looks like nothing happened. `Architecture_M3_CP4c3_TB10_Independent_Review_Record.md` §5.

23. **A loop guard is not effective merely because one exists; its bound must terminate expensive work before the process becomes operationally stuck.** TB-R8 already had two nominal guards: exact tracing tracks visited states and a structural step budget, and `BigInteger::gcd` throws after 10,000 Euclidean iterations. Yet the prescribed sphere received a trace budget of **1,775,616** states, one identity spent 853 s before the GCD backstop fired, and the next sphere identity still had to be cancelled. For geometry with exact arithmetic, guard the semantic progress/cycle at the owning algorithm with a deterministic, practically bounded finite-work contract. Keep low-level arithmetic guards as backstops; do not substitute CI/test wall-clock timeouts for a product termination invariant.

### A witness census is cheap; assuming a witness is capable is not

Nine committed `.obj` witnesses, and their Euler characteristics and boundary-edge counts can be
computed in seconds without building anything. Doing that once revealed that the two witnesses CP4c had
been planning around for three checkpoints are **closed surfaces**, that every witness which had ever
validated A2b is a **bounded disc**, and that a fourth committed witness was structurally guaranteed to
satisfy the contract that was blocking the gate. **Compute the topology of every candidate witness
before choosing one**, and record the census where the next planner will find it.

### Poincare-Hopf is a planning tool, not just a theorem

On a closed surface the singularity indices must sum to the Euler characteristic. A torus therefore
admits a completely singularity-free field — and a network derived only from singularities, features,
and boundaries is then **empty**, with no traces, no nodes, and nothing to seed region ownership from.
Conversely, a closed genus-0 witness with declared index-1 singularities summing to 2 **cannot** have a
barrier, so every trace must terminate by contact. **Before selecting a witness for a trace-behaviour
contract, compute what the field's index budget forces it to produce.**

### A relation that is a Cartesian product is not a function, and a consumer that needs a function will fail

`FieldBranchBoundaryPairing.connections` pairs every inflow carrier with every outflow carrier. That is a
faithful record of what the producer knows and a useless answer to what the consumer asks. A2a needs *the*
continuation; the pairing offers *all* of them. **When a product publishes a relation, check the
cardinality its consumer requires** — if the consumer demands uniqueness and the producer emits a
product set, the seam is broken no matter how correct each side looks alone.

### When the normative reference names two halves of a primitive, check that both were implemented

`DESIGN.md` §4.5 requires inflow/outflow interval decomposition **and** barycentric positions propagating
in arbitrary precision. The intervals were implemented; the positions were not. Without positions the
pairing cannot be resolved, so the implementation substituted the Cartesian product — a silent
substitution that survived every gate because the accepted witnesses never traversed an ambiguous face.
**Enumerate a cited paper's required outputs as a checklist before accepting the stage that cites it.**

### One missing datum can surface as several unrelated-looking defects

The absent barycentric position produced two failures a year apart in this project's terms: the CP4ab
barrier terminus that could not be located along its edge, and the CP4c interval pairing that cannot be
resolved. They were diagnosed independently and are the same gap. **When a second defect traces back to
an absent field you already noted once, stop treating them as separate and unify the fix.**

### Floating-point inputs do not force a tolerance in the decision

Every IEEE double is exactly a dyadic rational, so arithmetic on doubles can be made exact even when the
doubles themselves came from geometry. The CP4c-0 continuation compares exit times by integer
cross-multiplication rather than by dividing and testing against an epsilon, and the tie case becomes an
**exact** predicate instead of a tolerance verdict. **Before accepting that a topological decision needs
a tolerance, check whether the comparison can be restructured to be exact** — usually it can, by
clearing denominators.

### A discarded intermediate is a missing datum in disguise

A1 computed the barycentric direction, used it to classify three edges, and threw it away. The classified
edges were published; the vector was not. Every downstream consumer then had a *classification* where it
needed a *function*, and the substitute was a Cartesian product. **When a stage computes a value to
derive a published summary, ask whether a consumer needs the value itself** — the summary is lossy by
construction.

### Count the missing data before designing the fix

The review that found the Cartesian-product defect named one missing datum, the entry position. The
definition turn found two: the position *and* the discarded direction. A design built on the first alone
would have shipped a position that still could not resolve anything. **Enumerate every input the rule
needs and check each against what is actually published**, rather than stopping at the first gap.

### Exactifying a consumer without exactifying its selectors moves the failure, it does not remove it

CP4c-0 replaced a tolerant continuation rule with an exact one and the required gate went green — then
the sphere failed at the new exact rule's fail-closed assertion. The exact rule was right; its **inputs**
were still chosen by `double` comparisons against `1e-10`, in three separate places, and one of those
comparisons decided *the very same sign* the exact rule was about to re-decide. A tolerant selector
feeding an exact consumer is strictly worse than tolerant-everywhere: it converts a silent
near-degeneracy into a hard rejection at a site that did not cause it. **When you make a decision exact,
enumerate every upstream producer of its inputs and exactify the ones that decide the same predicate —
in the same turn.**

### If two tests answer the same question, prove they are the same expression before trusting either

`direction_in_incident_vertex_sector`'s `alpha` and `beta` are not *approximations of* the barycentric
direction coordinates `d[next]` and `d[prev]` — they **are** those coordinates, recovered by a Gram solve
from a vector that was itself reconstructed from them. The sector rule and the exact continuation rule
were therefore the same predicate at two precisions, and the frozen definition had recorded them as
unrelated: one a "lawful deterministic convention", the other exact. **Reducing both tests to a single
algebraic expression is what turned an undecidable three-way root-cause guess into a proof** — and it
cost no runtime at all.

### A half-open rule with a tolerance is not a partition

`alpha > tol && beta >= -tol` looks like a half-open sector convention and reads like one. With
`tol > 0` it is neither a partition nor a cover of the fan: it over-admits on one side and under-admits
on the other, so a direction can be claimed by a face it exits, or by no face at all. Only `tol = 0`
partitions. **The half-openness is doing the disambiguation work; the tolerance is doing damage.** They
look alike in the source line and must not be conflated.

### A required locus that is computed but not emitted has not been published

CP4c-0's DEFN table required `BranchContinuationDegenerateEntry` to carry `sourceFace`, `branch`,
incoming edge, and parameter. The implementation populated all four **correctly**. The witness diagnostic
emitter printed four *other* fields and dropped them, so the one datum that discriminated between three
candidate root causes was computed and thrown away — and a whole review turn could not name the failing
route. **A diagnostic contract must bind the observable string, not the in-memory struct**, and its
falsifier must assert the field appears in the emitted text.

### Never back-fill a locus field from a seed identifier

The failing trace reported `sourceVertex=0` because the caller filled the field in from the trace's seed
port when the failure site left it unset. The failure was several steps away and had nothing to do with
vertex 0. A locus field that silently falls back to *something else that is also a vertex* is worse than
an absent field: absent is honest, and the reader would have looked elsewhere immediately. **Publish seed
identity in separately named fields, and leave a locus unset when the site has none.**

### A cycle guard chosen before positions existed is unsound once positions exist

The trace loop breaks on a repeated `(face, branch, incoming edge)`, which was complete when a trace had
no position — and became wrong the moment continuation depended on an exact entry parameter, because the
same triple can legitimately recur at a different point. It then publishes the truncation as a clean
terminus, silently corrupting exactly the counts an acceptance oracle checks. **When a new datum enters a
state machine, re-derive every termination and de-duplication key against it**, and never let a
resource-bound stop masquerade as a semantic terminus.

### An instance falsifier certifies an instance

Two defects surfaced in one cycle, and both had a green-looking guard pointed straight at them. A
diagnostic identity built one error object by hand and asserted its tokens — so it certified that *one*
object, while ~15 real emission sites kept back-filling a locus field from the trace seed. A corrective
measure named two line numbers — so the fix landed on those two lines and the same defect survived
everywhere else in the file. **When the defect is "every site that does X", a falsifier over one site and
a measure over one line are both the wrong shape.** Write the identity to quantify over all codes and all
emission sites, and write the measure to name the class, then enumerate the sites as evidence that the
class was swept — not as the definition of the work.

### A narrow integer type is character-valued at a stream boundary

`FieldBranch::value()` returns `std::uint8_t`, so `stream << branch->value()` wrote a control character
instead of a digit, and a required diagnostic token silently vanished. No compiler warning, no type error,
and a `std::string`-based assertion is the only reason it was caught at all. The project had already met
this exact hazard and already solved it one file away — `static_cast<int>(incidence.branch.value())` — but
nothing made the convention enforceable, so the next emitter re-introduced it. **Route every diagnostic
value through a named formatter that returns a string; a convention that lives only in the memory of
whoever wrote the last call site is not a convention.**

### A NUL in a diagnostic truncates everything after it, and field order decides what you lose

The zero-valued branch emitted a NUL byte. `std::string` carries it harmlessly, but every C-string
boundary downstream — log file, `c_str()`, artifact writer — truncates there. The field emitted just after
it was the exact datum the diagnostic had been added to publish. So a formatting defect in one field could
have silently deleted the answer to the question the whole measure existed to answer, and the test suite
would still have looked green if it had happened to assert only on earlier fields. **A diagnostic contract
must constrain the byte content of the whole emitted string, not just the presence of each token.**

### Ordering a gate so the cheapest check gates the most informative one wastes whole cycles

Ten new identities ran in selector order, stop-at-first-red. The two-character formatting defect sat at
ordinal 329; the identity that answered the checkpoint's actual question sat at 338. One cosmetic defect
therefore cost a full build-and-run cycle and returned zero semantic information. The fix is not to
reorder the selector — that changes its hash and invites gaming the stop rule. **When each identity runs
in a fresh process there is no contamination risk in continuing past a red: execute the remainder and
report them as observations that confer no credit.** The gate stays exactly as strict; the turn stops
being uninformative.

### Verify a "already implemented, nothing to do" claim against the artifact, not the report

A build turn reported that eight of its nine measures were already present and that it had only packaged
the result. That claim was true — but it is exactly the claim that costs the most if it is wrong, because
it converts an implementation turn into a no-op with a green label. Re-deriving it took one pass over the
source plus a hash comparison proving the audited tree was byte-identical to the packaged source.
**Cheap to check, unbounded to assume.**

### A search candidate that throws during fixture construction has not falsified the product

A witness-search test built a near-degenerate one-triangle mesh and called `TriMesh::set_mesh` before
checking whether the candidate geometry satisfied the determinant/admissibility condition that made it
usable. DCEL setup threw first. The test was red, but the intended product predicate had not executed.
**Establish candidate geometric/topological admissibility before constructing a strict mesh object, or make
the search skip invalid candidates at the construction boundary. An exception before the predicate is
fixture evidence, not product evidence.** A deterministic capable witness is better than a search whose
invalid prefix can abort the falsifier.

### A test that asserts a witness currently fails will invert the day you fix it

A mandatory falsifier was written against the prescribed sphere's live tracing failure and contains
`ASSERT_FALSE(networkBuild)`. It passes today. It will go **red at exactly the moment the checkpoint
succeeds**, blocking acceptance for the opposite of the right reason — and in the meantime its passing is
the only place in the entire gate that records the far more important fact that the sphere still does not
publish. **Prove a property on a constructed failure whose existence the test controls.** If a production
witness is also exercised, make that branch conditional, so the test cannot become an assertion that the
product stays broken.

### A numeric label is only portable if something says it is

Branch indices `0..3` look like a global naming of four field directions, and an oracle was written that
iterated one label across four faces of a vertex fan. They are not global: each face assigns its own
**gauge** relative to its own canonical reference edge, so the same integer denotes a different physical
direction on each face. The strongest evidence was sitting in production the whole time — the transport
builder explicitly corrects each lift by the two faces' gauge difference, and code does not correct for
something that does not vary. **Before comparing a typed label across two owners, find the code that
translates between them; if a translation exists, the label is local and your comparison needs it.**

### An oracle built on the mechanism it tests is not yet a test

The corrected fan-partition oracle must walk the fan applying the published transport lift — which is
exactly what production does. That makes it consistent with production by construction, including if
production's gauge correction is wrong. The repair is not to avoid the published authority but to pair it
with an **independent** invariant the same defect would break: composed lift around a closed vertex fan
must be `≡ 0 (mod 4)` at a regular vertex and `≡ index` at a singularity. **When a test necessarily
consumes the authority under test, add a second check that closes a loop rather than following a path.**

### Predicting a test's result means predicting its whole precondition chain

A review predicted eight identities green and two went red. One threw before its assertion ever ran,
because its fixture built a mesh the DCEL rejects by construction; the other asserted on authority whose
semantics the review had never read. In both cases the `EXPECT` lines were audited and the path to them
was not. **A prediction about an identity is a prediction about fixture construction, authority
semantics, and assertion — in that order.** Both misses were one `grep` away.

### Screen a candidate before you construct it

The failing fixture called `TriMesh::set_mesh` on every candidate and only afterwards applied the
determinant test meant to reject bad ones. Construction throws, so the screen never ran. The 0 ms
failure time was the tell: nothing had been searched yet. **Order validity checks before construction,
not after** — and when a search loop dies instantly, suspect the first candidate rather than the search.

### Test your own hypothesis before you write it into the record

A per-face-normal parity mismatch looked like an obvious cause: the two faces sharing the failing edge
genuinely have opposite canonical parity, and the statistic is spectacular — 86.8 % of that mesh's
interior edges. It is still wrong. The quantity in question is an **index shift**, and it cancels in the
subtraction regardless of which frame chose it. The compelling statistic was measuring something real
and irrelevant. **A number that supports a hypothesis is not the same as a mechanism that produces the
symptom** — derive the mechanism end to end, or say you have not.

### Record the refutation, not just the conclusion

The refuted hypothesis above is the most attractive wrong answer available for this defect, and the
supporting statistics make it look conclusive. Writing only "cause undetermined" would guarantee the
next agent re-derives it and spends the same effort. **A review that eliminates a candidate should say
which candidate, on what evidence, and why the attractive-looking statistic does not carry** — an
exclusion is a durable result, not an absence of one.

### An invariant nothing ever asserted is not an invariant that held

A cross-edge flow-agreement check was added late, and it immediately rejected a production witness. The
tempting reading is "the new check is too strict". The correct reading is that nothing had ever compared
the two sides of an edge, so a reversed transported branch produced a wrong-but-plausible trace and no
identity could notice. **A long-green accepted suite is evidence about what was checked, not about what
was true** — when a new invariant fires, first ask how long it could have been failing unobserved.

### When one failure site suggests a one-line global fix, that is the moment to measure

The failing edge implied an off-by-two in a transport lift, and a sign flip would plausibly fix it. It
would also silently rewrite every trace in the project on the strength of a single observation. A census
over all edges and all branches costs one diagnostic identity and distinguishes a global convention
error from a local aliasing artifact from a caller-side bookkeeping bug — three fixes that look
identical at one site and are completely different everywhere else. **Cheap global measurement before
cheap global change.**

### Read a witness by its construction, not by its name

A census reported violations on four witnesses and a whole planning turn treated them as one population.
One of them was a flat, constant field with a period jump *imposed* on a single edge — a field whose
declared matching contradicts its own geometry, so a flow disagreement there is guaranteed by
construction and says nothing about production. The witness's name gave no hint; only its builder did,
and the builder was three call-hops away. **Before a witness's result becomes evidence, open the function
that builds it.** A synthetic fixture can be perfectly valid for the identity it was written for and
completely invalid as a population member for a different question.

### A published sum tells you nothing about its terms

`signedLift = matching + gauge_source − gauge_target`. A histogram over published lifts looked like
strong evidence — one value dominated — and it supported a hypothesis that then failed. It could not have
supported anything: a lift of 0 is consistent with matching 0 and equal gauges, with matching +1 and a
gauge difference of −1, and with several other combinations. **When a diagnostic publishes a derived
quantity, publish the terms it was derived from, or expect the derived quantity to be misread as
evidence about them.**

### A two-sided check double-counts, and the symmetry it produces looks like a finding

A census that examines each edge from both incident faces reports every disagreement twice, and the
reverse direction negates the lift — so the output shows a beautifully symmetric distribution of `+k` and
`−k`. That symmetry is an artifact of the loop, not a property of the field, and the totals are twice the
number of distinct problems. **Report distinct occurrences alongside directed ones**, so nobody has to
notice the halving to read the number correctly.

### An invariant that spans two stages is auditing both of them

The cross-edge flow check was written as an output invariant on one stage. It is really a check that the
*input field's* matching agrees with the *input field's* geometry, evaluated using that stage's
composition. So when it fires, three different owners are implicated and the diagnostic names none of
them. **State, for every cross-stage invariant, which inputs it also audits** — otherwise its first
failure will be attributed to whichever stage happens to emit the error.

### A continuum invariant is not automatically true of a discrete field

"A direction leaving one face through a shared edge must enter the neighbouring face through it" is
obviously true of a continuous field, and it was frozen as an invariant on that basis. It is false for a
**piecewise-constant** field near edge tangency: the perpendicular component at the edge is small, the
field's own rotation across the edge is larger, and both faces then correctly report outflow. Six percent
of ordinary edge/branch pairs on a well-formed sphere fall in that regime. **When freezing an invariant
over discretized data, state which regime it holds in** — and expect the first witness that violates it
to be right.

### Near-tangency is a ratio, and an absolute magnitude says nothing about it

A quantity was judged "three orders of magnitude above any epsilon" and therefore not a tangency effect.
The same quantity was the **smallest of its face's three coordinates** — a fifth of the largest. Distance
from a tolerance measures numerical safety; distance from tangency measures geometry, and the two are
unrelated. **When excluding a geometric regime, compute the geometric ratio, not the distance from an
epsilon.**

### Do not specify the suspect as its own oracle

An independent check was commissioned to test whether principal matching aliases field topology. Its
implementation computes the nearest branch by absolute rotation — which is principal matching. It
therefore reports near-perfect agreement and cannot detect the failure it was built to find. The
specification asked for "find which target index the source direction actually maps to," and that phrase
*is* the algorithm under suspicion. **When commissioning an oracle for algorithm A, write down what A
does first, and check the oracle is not a paraphrase of it.**

### A discrete model must be continuous across its own exact cases

The tracing model already defined what happens when a face's direction is **exactly** tangent to the
edge a trace is on: the trace travels along that edge and exits at a vertex. When the near-tangent case
had to be defined, one candidate was to terminate the trace instead. That candidate is wrong on
structure alone, before any measurement: it makes a topological outcome flip across a measure-zero
configuration, which is the same defect class as a tolerance deciding ownership even when no tolerance
appears. **Before choosing a rule for a neighbourhood, find the exact case at its centre and check the
candidate agrees with it in the limit.** The correct rule turned out to select the same endpoint by the
same expression the exact case already used.

### A diagnostic that reimplements a retired rule measures the retired rule

A non-gating census walked traces with its own carrier-resolution loop instead of calling the
production continuation. That loop was the Cartesian carrier lookup the design had **deleted** one
checkpoint earlier: it carries no position, so it resolved nothing on the first ambiguous face and
stopped. Every trace reported one traversed edge and zero observations — a null result that was then
recorded as a limitation of the *design options under evaluation*. **A census must either call the
production entry point or state in its own published output which rule it implements.** A null result
from a diagnostic is not evidence about the product until the diagnostic's rule has been identified.

### A high-incidence "violation" that clusters on the structures the stage exists to find is not noise

An invariant fired on 6-14% of edge/branch pairs and was read for several turns as a defect to localize.
Mapping where those edges actually were settled it: they lay in narrow corridors along the field's
separatrices — the very curves the stage is built to trace. **Plot the violations against the geometry
before deciding they are damage.** A violation distribution that traces the answer is telling you the
invariant is wrong, not that the input is.

### The exact quantity a rule needs is often already the published one

A rule that had to pick a direction along a shared edge looked like it needed the metric, an unfolding,
and a convex combination of the two faces' vector fields. It needed one published barycentric
coordinate, because the code that builds the boundary-point parameter builds it as exactly that
coordinate — so its rate of change *is* the rate the parameter moves. **Read the publication convention
of the datum you must produce before importing geometry to produce it.** Importing a metric into a
combinatorial rule also imports an exactness problem that the published form does not have.

### A guard that cannot fire is not a guard, and a budget is not a bound

A trace step budget authorised 1,775,616 steps on a witness whose exact arithmetic could not survive
205. It had never fired, was never going to, and had been read as protection for several turns. **Check
every bound against the cost of reaching it, not only against the semantics of the thing it bounds.** The
repair was to derive the budget from the guard that actually binds, so the two cannot drift apart again.

### Fixing a false positive can create a false negative in the same predicate

A cycle guard keyed on face, branch and incoming carrier once rejected a trace that legitimately
re-entered a face at a different position, so the exact position was added to its state. That was
correct, and it made the guard structurally blind to a circulation whose position drifts every lap -
which is every real limit cycle. **When a discriminator is weakened to admit a legitimate case, ask what
illegitimate case it now admits, and cover that beside the original rather than by re-tightening.**

### A runaway guard written as a magic constant will fire on correct work

A hand-rolled bignum capped Euclid's loop at 10,000 iterations. That is a fine tripwire for a
non-decreasing loop and a landmine for a large but entirely valid operand - and when it fired it threw
`std::runtime_error` out of a closed producer, surfacing as a test-body failure with no locus at all.
**Bound a loop by its own worst case computed from its inputs** (Lame's bound for Euclid, the digit count
for a trim, the range width for a binary search), so the guard can only fire on a real fault.

### A closed producer must be closed against its dependencies' failure modes

The product contract says every producer outcome is a typed value. The exact-arithmetic backend reports
its guards by throwing. Nothing reconciled the two until an exception escaped and left the producer with
no outcome to report. **Where a dependency signals failure by a mechanism your contract does not admit,
convert it at the boundary** - and make the conversion a backstop behind a policy that fires first, not
the policy itself.

### Removing a blocker exposes everything it was masking

A rejection that fired at the first grazing edge was aborting the sphere network - and was incidentally
stopping every trace before any could circulate. Retiring it was right, and it immediately surfaced a
latent non-termination that had never been reachable before. **When a stage's first rejection is
removed, expect the second defect to arrive in the very next run**, and budget a turn for it rather than
reading it as a regression in the fix.

### Do not predict a global property from a local resolution

A definition turn resolved one blocked locus, observed that the witness's singularities sat at the
corners of a cube, and predicted that every separatrix therefore ran corner to corner. Measured: 42 of 48
did and 6 wound forever. **Symmetry of the singularity set does not constrain the trajectories between
them.** The reproduction that settled it cost one script and was available at prediction time.

### When a checkpoint blocks on its own successor, look for two obligations under one gate

A checkpoint could not close because it needed a capability assigned to the checkpoint after it. The
instinct is to reorder or to re-scope; both preserve the mistake. The real cause was that the checkpoint
had been carrying two unrelated obligations - how a thing continues and how it stops - under a single
gate, and only one of them had ever been defined. **Splitting the checkpoint let the finished half close
on its own evidence and gave the undefined half a definition turn of its own.** When a dependency
inversion appears, check whether the gate is actually two gates before rearranging the schedule.

### A stopping rule must be validated against the traces that need stopping, not the ones that don't

Two plausible termination rules - self-contact, and a length budget derived from the mesh - were both
excluded by measuring them against the actual runaway traces. Self-contact never fires, structurally,
because the field is one constant vector per cell so repeat visits lay parallel segments. A length
budget cannot separate the populations at all: the longest correctly terminating trace and one lap of a
never-terminating trace were the same length to four decimal places. **Both would have looked reasonable
in review and failed in production.** Measure a candidate rule against the failing case before adopting
it.

### Exact ties are systematic on the inputs you use to judge quality

A tie-break looks like a rare fallback until you notice that symmetric models produce *exact* ties by
construction - and symmetric models are exactly what gets rendered to judge whether a partition looks
right. An arbitrary tie-break therefore decides the whole result on the nicest inputs. The way out was
to find the case that needs no arbitrary rule: simultaneous arrivals at *different* points are
independent and their order cannot matter, and simultaneous arrivals at the *same* point mean both
parties stop there. **Before picking a tie-break, check whether the tie has a canonical answer.**

### A bound derived from the computation is not a tolerance; a chosen constant is

Where exact comparison is infeasible, a floating-point comparison plus a *computed* forward error bound
is defensible: it decides only whether the order is knowable, and the unknowable case gets a canonical
answer. The same code with a hand-picked epsilon is the tolerance-as-ownership-key defect all over
again. The distinguishing test is whether the number is derived from the operands at run time or written
in the source, and whether the inconclusive branch has an answer that needed no choice.

### A guarantee inherited from a citation inherits its assumptions

The architecture claimed traces cannot fail to terminate, citing a result about motorcycles walking the
edges of an existing quad mesh - a finite graph where every step consumes an edge. One stage earlier,
tracing a field with exact positions in cell interiors, the state space is continuous and limit cycles
exist; one was exhibited with an exactly contracting first-return map. The conclusion still held, but
for a completely different reason. **When a design leans on a citation for a guarantee, restate the
citation's preconditions in the design's own terms and check each one.**

### An absence is only evidence when the search space was bounded first

A frozen precondition asserted that an event kind was "declared but produced by nothing". It had been
produced since three checkpoints earlier, at three sites, in the same file. The claim was written after
auditing one function, and it is a claim about the whole codebase. **Before asserting that something is
never produced, search for it and record the search.** One grep would have falsified this before it
propagated through four documents and shaped a checkpoint's entire scope.

### A true fact about one enum value is not a fact about its neighbour

`SingularityTermination` genuinely was declared and produced by nothing; that was measured and recorded.
The same sentence shape was then carried onto `TraceIntersection`, which had never been unproduced, and
survived every later document because each inherited it from the previous one rather than from source.
**Re-derive an inherited claim from source at least once before making it a binding precondition.**

### When a mechanism seems missing, check the next stage before concluding it does not exist

Crash-on-contact was looked for in the tracing loop, where a termination mechanism would naturally live,
and was not there. It was one function further down the same file, in the finalize pass that runs after
tracing. **Absence at the stage you expected is not absence.** Widen the search to the neighbouring
stages of the same product before concluding a capability is unimplemented.

### A mechanism at the wrong stage is worse than one that is absent

The contact pass, the contact node, the event kinds and the incidence roles all existed, were accepted,
and were cited in a closure record — and none of it could ever terminate a circulating trace, because it
ran only after every trace had finished building. Its existence actively suppressed the search for why
traces did not terminate. **When a capability is present but the behaviour it should produce is not,
check what stage it runs at before assuming the implementation is merely incomplete.**

### A binding precondition that fails is the plan working, not the turn failing

A Code + Build turn stopped at a frozen precondition, performed no implementation, compile, test or
benchmark, and returned a static contradiction with its evidence. That cost one cheap turn and saved an
implementation built on a false premise. **Write preconditions that can fail, and treat a failure as the
successful outcome it is.**

### A measured number is a property of the measurement, not only of the subject

A census reported `nodeCount = 0` for a witness. The figure was correct — under the rail authority the
census happened to use. A later identity imported it in good faith and asserted it against the same
witness built under a *different* rail authority, where the correct answer is non-zero. Nothing in the
census output named the authority, so there was no way to notice. **Publish the inputs that determine a
figure alongside the figure**, and require any identity citing a census number to assert the authority
it was measured under.

### Two names for a witness are two witnesses until proven otherwise

`rails_from_atlas(mesh, atlas)` and the production pipeline's `authoritativeRails` both produce "the
torus network". They are different objects with different mandatory edges and different node sets.
Before comparing a figure across turns, confirm the two constructions match — a shared witness *name*
guarantees nothing.

### Assert the relation the contract owns, not a total that happens to match

An identity asserted "zero nodes" to express "this witness produces no contact". The witness has
structural nodes for lawful reasons that predate the checkpoint entirely, so the assertion failed for a
reason the contract does not own. The correct assertion is relational — *no node has contact
provenance* — which is both true and strictly stronger, and which cannot be satisfied by a coincidence
of counts.

### A red that admits two readings deserves a third

A diagnostic report framed its single failure as either an over-specified identity or a real contract
breach, and correctly declined to choose. The actual cause was neither: a correct figure compared across
a boundary that no document had ever named. **When both available readings require someone to be wrong,
look for the reading in which everyone was right about a different thing.**

### Excluded from reasoning is not excluded from the gate

A witness was excluded from a census's legitimate reasoning and from a checkpoint's acceptance credit,
correctly and repeatedly, because its matching is fixture-imposed and contradicts its geometry. It is
nonetheless **accepted authority** carrying an absolute assertion whose value is a direct function of the
semantics that checkpoint was rewriting — and nothing in the checkpoint's evidence chain ever tested it,
precisely *because* it had been excluded from a different question. **When a witness is excluded from a
question, write down in the same place that it remains binding on the gate.**

### An absolute count is a hidden function of the semantics that produce it

`EXPECT_EQ(8U, network.nodes().size())` reads as a structural constant and decomposes as
`5 structural nodes + one terminal 0-cell per barrier-terminating trace`. Only its own comment made that
findable. **Before changing a stage's semantics, grep the accepted suite for absolute counts and
decompose every one of them** into the parts the change can move.

### A green subset gate measures the subset, and nothing beneath it

Seven never-accepted identities passing is real evidence about those seven and no evidence whatever
about the 346 accepted identities they sit on top of. **State what a gate does not cover in the same
breath as its result**, every time, or the greenness gets read as coverage it never had.

### When a review flags an inference as unmeasured, the next turn must close it in writing

A review deliberately marked one link in its argument as inferred rather than measured, and named the
measure that would settle it. The next turn measured it and the caveat was withdrawn explicitly. An
unmeasured inference that is never revisited quietly becomes an assumption — this project has paid four
documents' worth for exactly that failure once already.

### A classifier that names an owner will route the next turn, right or wrong

A census emitted class labels of the form "this bucket means `functionX` is at fault". The buckets were
real; the attributions were not, and the next report duly concluded that `functionX` was the owner. A
label that names a component is a routing decision embedded in a diagnostic. **Emit the measured
partition, not the inferred owner** — let the review do the attribution, where it can be argued and
challenged.

### Reproducing a runtime number from the fixture is the strongest check available

A census reported 144 disagreements. Recomputing them from the committed mesh and field alone — no
product code — produced exactly 144, which simultaneously validated the census, validated the
reproduction, and made the explanatory statistic trustworthy enough to overturn a frozen invariant on.
**Where a diagnostic's inputs are committed data, re-derive its headline number independently before
building any conclusion on it.**

## 3. Negatives and oracles

23. **A negative test proves only the guard it actually reaches.** Check which guard rejected before
    crediting the contract to the intended validator.
24. **A strict mutation negative is evidence only when the intended seam is reached and the intended
    mutation actually occurs.** `mutated=false` or an unreached callback is non-evidence.
25. **A positive assertion over a compound builder proves nothing about which guard rejected.**
    This is the mirror of the negative-test rule above, and CP2b paid for it: four identities
    asserted only `ASSERT_TRUE(built)` on a valid witness, so a red run could not name the cause. The
    product compounded it — `build_singularity_attachments` collapsed **14** distinct rejection sites
    into one error code and discarded the locus fields its error type already carried. **Report the
    error on every positive build assertion, and give each rejection site a distinguishable code.**
    Diagnosability is a product property, not a test convenience: without it every subsequent run
    costs an attempt and returns the same non-answer.
26. **A negative is not credited while the valid baseline also fails.** A guard that rejects tampered
    input has demonstrated nothing until a sound witness is shown to pass it — otherwise it may
    simply be rejecting everything. Report such a negative as reached-and-passing, never as an
    established contract.
27. **A uniqueness key whose fields are functionally dependent is a one-field key wearing two.**
    CP2b keyed singularity port representatives on `(startFace, firstOutgoingCarrier)`, but within a
    vertex fan the face determines its opposite edge, so the pair carried exactly what `startFace`
    carried alone — and any face whose incident sector exceeded the branch spacing produced a false
    duplicate. Before trusting a composite key, check whether one field determines another in the
    domain where the key is used; the discriminating field may already exist on the record and
    simply be omitted.
28. **A matching count is not a matching structure.** CP2b's port-class guard passed
    `classes.size() == expected` and still rejected, because five incidences can form three classes
    in more than one way. When a count check passes and a structural check then fails, publish the
    structure before changing the rule — otherwise the "fix" may silence the guard over a partition
    that is still wrong.
29. **A test that asserts both invariance and raw equality is internally contradictory — check the
    identity against itself before blaming either side.** CP2b's Z4-relabel identity required raw
    matching to change, published transports to stay equal, and raw matching to equal the published
    lift. The first two are the contract the identity is named for; the third could not hold and was
    the defect. When a single identity fails, read all of its assertions together: the failing one may
    be the one contradicted by the rest.
30. **A canonicalized representative and a raw representative are different quantities — compare
    them modulo the canonicalization, or not at all.** CP2b's published branch lift added a per-face
    gauge, applied a canonical orientation, and reduced into `[0,3]`; the oracle compared it to raw
    per-edge matching with integer `==`. They coincided on the baseline and diverged the moment a
    gauge relabel was applied, which is precisely what the relabel existed to test.
31. **Fixing an over-strict oracle means re-deriving, never relaxing.** A comparison loosened to
    congruence can stop rejecting the tampered inputs the oracle exists to catch. Recompute the
    canonical representative independently from source — never read the product's gauge — and pin the
    result with a negative that a pure relaxation would fail: perturb by one unit and require
    rejection, perturb by a full period and require acceptance.
32. **When a guard rejects early, every check behind it is unproven — not passing.** CP2's rail
    cardinality check fired before the mandatory-edge maps were built, so three cross-closure checks
    had never executed on a closed rail. Before predicting a gate result from a fix, enumerate what
    the failure was masking and say plainly whether those checks are proven or merely unreached.
33. **A producer that forces a relation and an oracle that reads the forced value back are
    self-consistent by construction.** The pair can violate independence even when the oracle appears
    to recompute something. A final oracle must receive independent remapped authority; disabling
    authority or deriving expected state from the output is not validation.
34. **A semantic owner and an independent consistency checker are not duplicate authorities.** The
    accepted producer owns the value; a read-only checker may independently derive a relation and
    reject inconsistent publication. Duplication begins when **both** paths can publish or drive
    semantic state.
35. **Never delete an "obsolete" negative before its replacement exists and fails closed for the
    intended reason.**
36. **A test that permits both legacy and new outcomes while claiming a stricter invariant is a
    compatibility test, not a migration test.** Tighten it before trusting it as a cutover gate.
37. **A validator named source-authoritative must reject missing or mismatched typed source
    authority independently of optional sub-gates.**
38a. **A recompute-and-compare validator proves reproducibility, not correctness.**
    `validate_field_aligned_candidate` rebuilds the canonical candidate from source authority and
    compares it element-by-element to the submitted one. Any producer defect is reproduced identically
    on both sides and passes. Such a validator is a strong tamper gate and **no evidence at all** about
    semantics; do not count it toward a semantic acceptance argument.
38c. **A boolean oracle converts a red into a search.** `independent_disc_proof_oracle` returns a bare
    `bool` over five distinct clauses — an Euler identity, orbit construction, a fragment partition, a
    region/orbit bijection, and a per-face fragment-count rule. When it returned false, nothing said
    which. Give any independent oracle a typed failure reason **before** it is allowed to gate a
    checkpoint; otherwise every red costs a diagnostic just to localize.
38d. **A combinatorial face walk on a surface with boundary counts the capped surface's faces.** The
    dart-orbit walk knows nothing about the source boundary, so it returns the faces of the graph
    embedded in the closed surface obtained by capping each boundary component:
    `V − E + F_all = χ(S) + b`, equivalently `V − E + F_interior = χ(S)`. An oracle that compares the
    all-orbits count against `χ(S)` is wrong by exactly `b` on **every** bounded witness, forever, and
    presents as a deep topological failure rather than an off-by-one.
38b. **An oracle is blind to any defect its invariant is neutral under — say which defects those are
    when you freeze it.** Publishing a missing 0-cell adds one node and one arc, so the global
    cellularity identity `V_g − E_g + F_g` is unchanged and B4 cannot detect the omission. That
    neutrality is why 304/304 accepted the defect. **For every oracle, record the transformation
    group it cannot see**, and never argue "the independent oracle would have caught it" without
    checking membership in that group.

## 4. Single authority and representation

38. **Adding a typed product does not complete a cutover if production immediately projects it back
    into raw semantic arrays.** The product becomes authority only when production consumers read
    the typed owner and the raw representation is reduced to a one-way legacy/test/diagnostic leaf.
39. **A new stage must not re-derive a fact an accepted stage already owns.** Consume the owner's
    value. A second derivation is a second authority, and when the two disagree the accepted owner
    is right.
40. **Raw row/index values may exist only at verified one-way container, serialization, or
    diagnostic leaves.** Do not decode them back into semantic authority or reconstruct typed owners
    from arithmetic. Matching extent is not ownership; exact source-row topology pairing is required.
41. **Derived identity caches must be rebuilt by the same canonical constructor their consumers
    use.** A copied cache kind or a second schema is authority duplication.
42. **A legacy representation that aliases one fact across many keys must be collapsed at the
    typing boundary, not carried through it.** `effort_to_indices` emits one singular entry **per
    vertex**, and `vertex2cycle` maps every boundary vertex of a loop to one cycle row — so a single
    boundary-loop index arrives as N vertex-keyed entries. A1 ingested all of them as distinct
    singularity facts while **already** owning that index correctly as a typed `BoundaryLoop` cycle
    witness: two owners of one quantity. A typing stage exists precisely to collapse aliased legacy
    representation into one owner; passing it through verbatim is that stage failing its purpose.
    When collapsing, **reconcile before discarding** — the dropped entries must be checked against
    the surviving owner, or the filter is an unproven silent drop.
43. **Two stages that validate the same quantity must share one admissible range.** CP2b's
    `build_singularity_attachments` admitted singularity index numerator `[1, 3]` while accepted CP2
    required `[-2, 1]` — disagreeing in both directions, so a valid index `-1` singularity was
    accepted by one accepted stage and rejected by the other. Neither range was exercised, because
    no fixture had ever carried a nonzero index. When a new stage re-validates an accepted stage's
    input, adopt the accepted range; do not invent a third.
44. **A representation with one writer and no enforcing reader is latent ambiguity.** The closed-rail
    `|V|=|E|` form is canonicalized by the producer, but every consumer guards with
    `closed && back() != front()` and so accepts both forms. That tolerance let a diverging consumer
    stay invisible until production runtime.
45. **When a typed migration turns a contract red, check whether the typed member means the same
    thing as the raw one it replaced.** Reverting to the raw member to restore green undoes the
    migration. The defect is usually that the typed member was populated from a different domain.
46. **An abstraction name is not proof of generic authority.** Inspect every template parameter and
    variant alternative before propagating a typed wrapper to a new domain — the accepted
    `ProducerOutcome<T>` was product-generic but hard-coded one failure type. Generalize in place;
    do not create a parallel wrapper.
47. **When a cutover moves a guard earlier, the earlier guard inherits the later one's diagnostic
    obligations.** Static closure cannot see this: an audit proved `K=0` while an accepted diagnostic
    silently degraded to `-1`. Enumerate what the superseded site *published*, not only what it
    *decided*.
48. **Moving semantic rejection earlier does not authorize dropping stage-owned diagnostic
    sub-invariants.** Preserve the same exact diagnostic owner/index or route through the canonical
    seam; matching only the reason string is not equivalent accepted behavior.
49. **When a product-shaped diagnostic mirror is relocated, migrate all literal build-contract
    markers and typed consumers in the same cutover.** A stale CMake source marker or test access to
    removed fields is build-contract drift, not justification for a compatibility alias.
50. **A non-null pointer is not a live object.** After a container is moved from, pointers captured
    into it can still dereference and report the same variant alternative while reading moved-from
    state. Verify the mechanism, not just the symptom, before writing a corrective measure.
51. **When a producer handles N sibling cases and one of them takes a shortcut, that one is the
    defect — read the siblings before believing the shortcut is a design.**
    `finalize_field_aligned_events` publishes a fresh 0-cell for the trace/trace contact case and for
    the loop-closure case, and for the barrier-termination case alone substitutes an existing edge
    endpoint. Two turns searched downstream for missing terminal authority; the mechanism was nine
    lines above the shortcut and already called twice in the same function. **Enumerate a producer's
    parallel cases side by side before concluding a fact is unpublishable.**
52. **An under-constrained identity gets filled by an arbitrary representative, and the substitution
    is invisible.** No accepted contract said which node a barrier termination binds to, so the
    implementation bound it to `mandatory->firstNode`. It compiled, validated, digested, and passed
    304/304. **When a contract pairs two facts (event kind and its edge) but never pins the third
    (the node), assume the third is wrong until an assertion pins it.**
54. **A consumer that rejects before its input is validated masks the real defect with a true
    statement.** "χ ≠ 1" and "no orbit equals this boundary" were both true and both the wrong first
    answer: χ is derived from `sourceFaces`, and orbit election is derived from the boundary walk, so
    each rejected a defect in its own input before the check that owns that input ran. Order validation
    by **ownership**, not by call convenience: structural inputs first, consumers second. Three
    instances on record in one checkpoint.
55. **When a comment states a precondition, check where that precondition is actually evaluated.**
    `GlobalTopologyPlan.cpp:2373-2374` says the single boundary walk and no-pinch condition are why χ's
    boundary terms cancel — and `validate_single_boundary_walk` ran *after* the code path that consumed
    it. The code documented the ordering rule it violated. Grep for the named precondition's call site
    whenever a comment justifies a simplification.
56. **A Review that authorizes a change outside the checkpoint's frozen selector must name the identity
    that will execute it.** The U-series edited two `FieldAlignedCurveNetwork.*` tests while the CP4ab
    selector covers only `GlobalTopologyPlan.*`. Both changes compiled, both were reported delivered, and
    neither ran — the diagnostic that was supposed to check them structurally could not reach them.
    Compiled-but-unexecuted test authority is not evidence; it is debt wearing a green label. Check the
    selector's reach at the moment you authorize the edit, not at acceptance.

63. **A green gate proves exactly what it enumerates; name what it did not cover in the same breath.** CP4c-2
    closed at 365/365 with the prescribed sphere unable to reach A2b at all, and with Amendment 14's ordinary
    trace-crossed proposal path unexercised — both outside the gate by recorded decision, both real. The closure is
    honest only because it says so. **The converse discipline is the same rule:** once a gate is frozen and its
    evidence arrives, do not add conditions to it. That was easy to honour at R7-REV, where the new information
    favoured strictness and `PR8-R044` closed on its frozen condition despite a one-witness residual; it was harder
    at R10-REV, where `AH6`'s coverage gap tempted a withheld closure. A gate that can be tightened after the fact
    is not a gate, and the project's own record shows the temptation runs in both directions.
61. **"Convert every consumer" must ship with the enumeration, or say who owes it.** DEFN-R2 §4 itemized
    Amendment 14 as five producer-side changes under the heading "what must actually be built, itemized", and AG1
    said "land §§4.1–4.5 as one conversion — a partial conversion is the defect this checkpoint is correcting". The
    itemization omitted A2b's cut-arc binding, which the amendment necessarily invalidates. CB7 and CB8 implemented
    all five items correctly and completely; the gate then went red on the sixth. **A numbered list adjacent to the
    words "every consumer" reads as the enumeration whether or not it was meant to, and the reader is not wrong to
    read it that way.** Either produce the list by search over the codebase and put it in the measure, or state
    explicitly that the implementer must produce and publish it — and then make the follow-up measure require the
    search rather than a copy of the reviewer's table, so the next enumeration corrects the last one's omissions
    instead of inheriting them. Second consecutive turn in which an enumeration inside a measure was read as
    exhaustive when it was illustrative; see also **59**.
62. **When one representation change breaks two consumers, the loud one gets fixed and the quiet one becomes the
    real defect.** Amendment 14 made a promoted source edge own several derived arcs. `GlobalTopologyPlan` read
    that change in two places: a binding check that demanded exactly one arc — which failed **loudly**, with a
    typed code and a source-edge locus, and was localized in a single runtime — and a `boundaryVertices` insertion
    that assumed a single whole-edge arc and therefore over-inserted. The second is a **skip list**, so
    over-inserting suppresses an interior-vertex ownership check with no error, no diagnostic, and no symptom: a
    certificate that validates less than it claims. Fixing only the loud site would have converted a red gate into
    a quiet weakening. **After changing a representation, grep for every consumer and classify each by failure
    mode, not just by whether it compiles** — a permissive consumer is more dangerous than a strict one, precisely
    because nothing will tell you about it.
59. **A measure that names an authority must enumerate the products that authority comprises.** R7-REV's AF3 told
    the implementer to "build its baseline from the **production torus authority** — the same `torus.rawfield`-derived
    field". CB7 did exactly that, correctly and including the non-obvious step of permuting raw-field rows alongside
    mesh rows. But the production torus authority is **four** products — authoritative rails, the hard-feature edge
    set derived from them, per-face component labels and per-face sheet labels — and the field is not one of them.
    The parenthetical, meant as a clarification, silently narrowed the target to a single product, and the identity
    shipped with three-quarters of the mismatch intact and a gating red. **"The production X" is ambiguous exactly
    when X is a chain, and the ambiguity resolves toward whichever product the measure's author had in mind.** List
    the products, name the function that derives each, and name a reference call site already doing it right. This
    instance is the fifth `RP-01` in one subsystem and the first introduced *by a corrective measure written to
    prevent it*.
60. **A helper that cannot use `ASSERT_*` must not synthesize the product error it failed to obtain.** Ordinal 359's
    build lambda reported atlas and network failures through non-fatal `ADD_FAILURE()` and then returned a
    default-constructed `SurfaceCutGraphError` as a sentinel, so three distinct causes arrived at one fatal
    assertion and the reported locus identified none of them. Worse, the sentinel is not inert: a default-constructed
    error reads as `InvalidSourceBinding` with no originating code, so the obvious repair — printing the error code
    at the assertion — would have manufactured a **false locus** in a subsystem that had just spent eight turns
    recovering from exactly that. Return a typed result that names the failing stage and carries **that stage's own**
    error; never fabricate a downstream error to satisfy a return type.
58. **An immutability guarantee constrains the writer, not the derived view — check what the representation
    already does before ruling it out.** CP4c-2's DEFN-R1 excluded every trace-crossed source edge from the
    admissible cut set on the ground that promoting one "would subdivide the trace — mutating an immutable
    upstream product". The premise about the product was true and the conclusion was invalid: `build_arcs`
    already emits **one trace arc per network event**, so a trace is many arcs in the arrangement and always has
    been; it already splits a mandatory source edge into two arcs at a trace terminal; and the crossing point is
    already published exactly by the network as a segment `entryPoint`, at a segment position the subdivision
    machinery already keys on. Nothing upstream is mutated either way. The cost of the invalid step was a frozen
    contract with an unprovable completeness case, a rollback plan triggered by it, and two turns of planning
    around a restriction that was never required. **The control is the same one that catches the wrong-complex
    family (`22e`): before a definition rules a representation out, read every existing consumer of that
    representation.** A derived arrangement placing a node where the product already says two curves meet is not a
    repair; it is what a derived arrangement is for.
57. **A `default:` case in an error-translation switch is a lossy channel, and the name it assigns will be
    believed.** `SurfaceCutGraph::topology_error` maps 39 `GlobalTopologyPlanErrorCode` values onto three
    `SurfaceCutGraphErrorCode` values: three survive as themselves and **36 collapse into
    `CellularityNotEstablished`**. The prescribed sphere's failure was almost certainly
    `RotationSystemInconsistent` raised inside the shared embedded-graph authority — a stage that never evaluates
    cellularity at all — and for eight turns every plan, review and prediction reasoned about whether the sphere
    was cellular, how many cuts it needed, and which complex certified it. Inserting a new stage upstream did not
    change the failure; it **renamed** it. Two rules follow. **When translating a typed error across a stage
    boundary, carry the originating code as provenance** so the collapse is reversible at zero semantic cost. And
    **when a `default:` case assigns a name that asserts a semantic verdict, it is not a default — it is a
    fabricated finding**; either enumerate the cases or give the bucket a name that admits it is one
    (`UpstreamTopologyError`, not `CellularityNotEstablished`).
53. **A downstream stage that already models a case perfectly is evidence about ownership, not
    reassurance.** A2b's edge-locus rotation requires exactly two mandatory rays at degree three and
    orders all three darts strictly — written for a trace ending inside a mandatory edge, and never
    once executed. **Dead code in a correct consumer means the producer is not publishing the case.**
    Search for unreachable-but-correct downstream branches when localizing a missing fact.
64. **When instrumenting a collapsed error, check whether the reason you are adding is itself a collapse before
    declaring the layer done.** This is lesson 57 for the third time in this project, one level deeper each turn,
    and all three layers were on the *same* sphere failure: `topology_error` collapsed 36 codes, and AF0 resolved
    it to `RotationSystemInconsistent`; nine sites shared that name, and AK3 resolved it to
    `TraceEventPositionInvalid`; and that name covers **two** conditions —
    `trace_event_position` returns `std::nullopt` from one `if (positions.size() != 1U)`, where `empty` is an
    event/trace **binding** defect and `> 1` is an **ambiguity**, needing opposite corrections. Every layer was
    worth resolving and none was wasted work; each was nevertheless declared "the cause" one turn too early, at a
    cost of one turn apiece. The control is mechanical and belongs in the measure that adds the reason: **read the
    site that sets the value you are about to publish and count the distinct conditions that reach it.** If more
    than one does, the new reason is provenance, not a diagnosis, and the measure must say so. Two corollaries.
    A collapse can be *manufactured* by control flow rather than by a shared name — `trace_event_position` runs a
    precise face-restricted pass and then, only on failure, a widening pass that ignores the face, so an `empty`
    first pass can be reported as `ambiguous`; publish **which pass produced the result**, not only the result.
    And when the two branches need opposite fixes, **do not design across the gap**: the plausible mechanism is
    exactly when the temptation is strongest, and CP4c-2 paid eight turns for acting on one.
65. **When one obligation is discharged by two paths, diff their *failure* behaviour, not their success
    behaviour.** `FieldTransportAtlas` splits prescribed singularities into an interior map and a boundary map at
    `:1557`, then reconciles each: the boundary loop (`:1960-1976`) demands an owner and raises
    `SingularityMismatch` without one; the interior loop (`:1980-1990`) looks the owner up and, on a miss, leaves
    `region` and `cycle` as empty `std::optional`s and continues. Read for what they *do*, the two loops look
    alike — both "handle" a missing owner. Only one **reports** it. Any change that moves items from the strict
    path to the permissive one silently converts a verified fact into an unverified one; Amendment 15's cut does
    exactly that, because every vertex on a barrier loses its inner-vertex cycle. Two sharpeners. **Be most
    suspicious when the split key belongs to a different object than the thing being reconciled** — here the
    *global* mesh's `isBoundaryVertex` decides how a *local* mesh's cycle is checked, so a vertex that is locally
    on a boundary but globally interior takes the permissive path, which is precisely the case the change
    creates. And **an `std::optional` left empty on a lookup miss is a silent failure mode wearing a type**: the
    absence is representable, so nothing forces a decision, and the miss reaches a product as a field that merely
    looks unset. Grep for `.find(...) != ...end()` guards whose else-branch is fallthrough whenever you change
    which items land in the map.

66. **When a change invalidates an assumption, write the audit predicate as the assumption — not as a symbol.**
    Amendment 15 cut A1's local region mesh along its barrier set. Measure AM2 told the implementer that
    `globalVertexByLocal` becomes many-to-one and that **every consumer of it** must be audited *by search, not by
    copying the measure's list*. That search was performed faithfully and correctly returned nothing about
    `build_singularity_attachments` — which consumes neither that map, nor the local mesh, nor the cut, and which
    nevertheless holds the identical assumption the amendment invalidated: *the transport neighbourhood is fully
    traversable*. It walks the **global** one-ring of a singular vertex, requires the ring to **close**, and demands
    a branch transport on every radial edge, while `branchTransports` excludes every barrier by construction. It
    failed the moment the cut let execution reach it. **The instruction to search was right and the predicate was
    wrong.** Two rules follow. Write the audit predicate as the invalidated assumption in words, then search for
    that; and **name at least one consumer that does not touch the changed data structure**, as evidence the
    predicate was not silently reduced to a symbol search. This is the third instance of the family lessons 59 and
    61 record — AF3 narrowed a four-product authority to one, DEFN-R2 §4 enumerated five consumers and omitted a
    sixth — and the first in which the enumeration discipline was honoured and the scope still missed.
67. **Instrument the stage's error surface, not the site that is currently failing.** Measures AK1/AK2 resolved
    `IncompleteCycleBasis` from a name into an enumerated reason plus a full locus row, and did it well. They were
    scoped to *that code*. One turn later the same producer failed on the neighbouring code,
    `MissingSingularityBranchTransport`, whose typed error already carries `sourceEdge`, `sourceFace`,
    `sourceVertex` and `topologyRegion` — and the harness reported only `code/stage`, discarding all four, so the
    locus had to be recovered by elimination instead of read. The cheap fix is not another per-code measure: when a
    stage's typed error carries locus fields, **route the locus for every code that stage can raise**, in one
    change. A per-site instrumentation measure buys exactly one turn of visibility.

68. **When a witness is advancing stage by stage, scope the measure to the pipeline, not to the stage that is
    currently failing.** Three consecutive corrective measures were each satisfied *exactly* and each turned out
    one level too narrow, and the narrowing was invisible precisely because the implementer complied. **AM2**
    scoped a consumer audit by **symbol** (`globalVertexByLocal`) when the thing to audit was an assumption, so a
    faithful search could not reach the consumer that broke. **AN1** scoped error instrumentation by **enum**
    (`FieldAtlasBuildErrorCode`) while the witness was visibly clearing one stage per turn — and the next failure
    was in a different stage's enum. **Amendment 16** was written for **A1** when its own reasoning covered every
    stage. Each measure was narrower than the reasoning that produced it. Two rules. Write the measure's scope from
    the *reasoning*, not from the code you happened to read: if the argument is about "any derivation that walks
    transport", say that, not "A1". And prefer **a predicate a reader can apply to code you have not read** over an
    enumeration of the code you have — an enumeration is a snapshot of your own search, and the next failure is by
    definition somewhere you did not look.
69. **A diagnostic channel rebuilt once per stage is a funnel defect wearing three costumes.** Three consecutive
    review turns recovered a failure locus by elimination because the pipeline's surface-cell failure path takes
    only `(code, stage)` and every caller drops the typed error it is holding — `fail_surface_cells` has no locus
    parameter at all, and one call site had already grown a hand-rolled channel by string-concatenating the stage
    name with the error code. Each turn answered with a bespoke per-code channel instead of fixing the funnel. When
    the same information is lost at the same boundary twice, stop widening the caller and **give the boundary a
    typed payload**, converting every call site in one change; the alternative is paying one turn per stage
    forever. Corollary for reviewers: before writing "add a diagnostic for X", check whether the value already
    exists in a typed object that something downstream is discarding — in all three cases it did.

70. **An enumeration of candidate *mechanisms* is exactly as dangerous as an enumeration of candidate
    *consumers*.** At `M3-CP4c-3-TB3-R1-REV` I enumerated three mechanisms for a transit failure — barrier
    truncation with zero candidates, singular-vertex holonomy, and a port-policy consumer mismatch — and one run
    falsified **all three**: the cardinality was 2 (not 0), the vertex was neither barrier-incident nor
    barrier-absorbed, and it turned out to be a **regular** vertex with trivial holonomy. The frozen review plan I
    was working from had listed five possibilities including "exact sector predicate/election defect", which is
    where the answer actually lives, and my own enumeration dropped it. An enumeration of mechanisms is a snapshot
    of the reviewer's imagination, and the next failure is by definition somewhere they did not look. **Enumerate
    mechanisms to design the measurement, never to bound the answer**, and state in the record which observation
    would fall outside every listed mechanism — that sentence is what stops a falsified enumeration from becoming a
    wrong correction. The measurement design is the part worth keeping: one published field (`publishedFaces`)
    discriminated all three mechanisms at once, which is why a single run could kill them all.
71. **A partition test disambiguates one point among cells; it cannot disambiguate one point per cell.** The vertex
    transit election tests, for every candidate face, whether *that face's own* representative of the transported
    branch lies in *that face's* angular sector. The sectors are an exact half-open partition of the full turn — no
    overlap, no gap, no tolerance — so a single direction can elect at most one face. Two faces elected anyway,
    which **proves** that two geometrically distinct vectors were tested: a cross field's per-face branch
    representatives are related by transport, not equal as vectors. No refinement of the cells, no tightening of the
    half-open convention and no ordering of candidates can fix this, because the non-uniqueness is not in the
    cells. **When an election looks ambiguous, check whether every candidate is being tested against the same
    datum before you touch the partition** — and when the predicate is already exact, ambiguity is evidence about
    the *inputs*, never a reason to add a tolerance.

72. **A correction that satisfies a measure's letter can defeat its substance — so write the measure about the
    *provenance*, not the operator.** Amendment 17 required an election to test a single datum, and AS9 prohibited
    "any tolerance in the predicate". CB6 complied with both: it did not touch the predicate, which stayed exact
    `FieldExactRational`. It instead carried the datum through **world-space `double`** — exact barycentric →
    `to_double()` → normalized 3-vector → transported face to face in doubles → `from_double_exact()` → fed to the
    exact comparison. **An exact comparison on a float-derived operand is a floating-point decision with an exact
    final rounding step.** The conversions also brought three silent failure modes (`squaredNorm() == 0.0`,
    non-finite, failed reconstruction) into the least observable place in the pipeline. The rule: **exactness is a
    property of the whole derivation chain, not of the final comparison** (`DESIGN.md` Amendment 18), and a measure
    that names an operator will be satisfied by changing the operand. Where speed is needed, only a **certified
    filter** is admissible — one that returns the provably-correct answer or defers to exact, never an
    approximation.
73. **A producer with an unreportable exit will eventually report a name that is false.** `resolve_field_vertex_transit`
    grew four paths that `continue` or skip before the per-state diagnostic is recorded — an empty seed when the
    arrival pairing is missing or its direction fails to convert, a mid-walk conversion failure, and a failed
    transport during expansion. When the seed itself dropped, the walk never ran, so the function returned
    `VertexTransitSectorUnresolved` with **zero candidates and zero diagnostic rows**: a typed name asserting that
    a sector election was unresolved, for a run in which **no election happened at all**. Five consecutive review
    turns have now been spent on names that misdescribed their own cause. Two rules. **Record the diagnostic before
    any conditional that can skip the state** — a diagnostic gathered after the guards documents only the paths that
    did not fail. And **an empty diagnostic set must be its own named condition**, because "we examined nothing" and
    "we examined everything and none qualified" are opposite findings that must never share a code.

74. **"Measured on the witnesses" and "true in general" are different claims — and the witnesses' regularity is
    itself a measurable property that bounds which one a result can support.** An adversarial architecture review
    proposed input conditioning, a degeneracy taxonomy, index-deficit reconciliation and uncertainty handling.
    Five proposals were rejected as unnecessary, each rejection grounded in measurements of the committed fixtures.
    Then the fixtures were measured: `mechanical_feature` 152V/300F, `sphere_prescribed` 98V/192F, `torus`
    72V/144F, **area ratios 2.05–3.17, maximum aspect ratios 1.72–2.67, valences 4–6**, all singularities `+1`,
    genus ≤ 1, every field admissible by construction. Production inputs carry area ratios of `10⁶`+ and aspect
    ratios in the hundreds. **The evidence base was structurally incapable of producing the cases the proposals
    targeted**, so the rejections established only that the proposals did not diagnose the *current* failure —
    never that they were unnecessary. Five were reversed. The rule: **a review that rejects a proposal as
    unnecessary must name the witness that would exhibit the case, and if no witness can, the correct disposition
    is "unmeasured, witness owed" — never "rejected."** Two corollaries. Distinguish explicitly between *"wrong as
    a diagnosis of what we measured"* and *"wrong as an architecture"*; the first almost never implies the second.
    And treat fixture regularity as a first-class measurement: a witness set built to isolate contracts is, by
    construction, the least likely input to exhibit degeneracy, so its silence about degeneracy is guaranteed and
    carries no information. This is the sixth recorded instance of the same scope-narrowing failure — by symbol
    (66), by enum (67), by stage, by mechanism enumeration (70), by operand (72), and now by **witness domain**.
75. **A measurement is evidence only if some identity or projection carries it — and three correct
    implementations in a row will not make one appear.** AS1 asked for each candidate's exact direction; CB6 built
    the rows. AU1/AU3 asked for reportable exits and the restored measurement; CB7 built them *exactly* — both
    `representativeDirection` and `incomingDirection` as exact barycentrics, a per-state outcome enum, unit tests
    asserting `is_barycentric()`. Every turn complied. The rows still reached no reader:
    `FieldAlignedCurveNetworkError::vertexTransitStates` is populated at the failure site and dropped at
    `RemeshPipeline.cpp::network_failure_locus`, whose `SurfaceCellFailureLocusDiagnostics` DTO has no field for it.
    AP1 had fixed that boundary for the field *shapes* that existed when CB5 wrote it, and those still project
    correctly; a new shape was added twice afterwards and the projection was never extended, because no measure said
    to. Three reviews observed the absence and none diagnosed it, because at each turn the omission was invisible
    from inside the turn.
    Two authoring-time controls, both free. **A measure that orders a measurement must name the identity or the
    projection that will carry it** — otherwise the measure is not dischargeable and the reviewer discovers that
    only after the run. And **a diagnostic added to a typed error for operational reporting must have its projection
    extended in the same change**, or be explicitly declared producer-boundary-only. A diagnostic built and then
    destroyed at a stage boundary is unexecuted authority in the sense of 56, wearing a diagnostic's costume. A
    related trap the same episode exposed: publishing *richer* rows for a datum that is semantically wrong makes the
    wrong decision better documented, so freeze the audit contract for the corrected datum before extending any
    projection. `Architecture_M3_CP4c3_DEFN_R2_Frozen_Definitions.md` §AX8.
76. **When an exact decision has no bounded algebraic representation, the budget is part of the architecture — and
    the measured case is not the worst case.** Electing a developed vertex sector is deciding the sign of a signed
    sum of arccosines: each face angle has `cos θ = D/√P`, `sin θ = √Q/√P` with `D`, `P`, `Q` exact rationals, so
    composing the fan's rotations exactly lands in a tower of degree up to `4^k` in fan length `k`. No amount of
    care makes that bounded. The three tempting escapes are all defects already recorded here: carry the value
    through `double` and exactify the result (the CB6 defect, 72); introduce a tolerance (prohibited by
    Amendment 17); or let "the filter was inconclusive" stand as an answer, which silently converts the
    exactly-degenerate case — the one case that most needs deciding — into a failure.
    The admissible shape is: a **certified filter** that returns the provably-correct answer or defers, an **exact
    fallback that is implemented and reachable**, and a **published budget** with a typed fail-closed state above
    it. Note which of those is load-bearing: here the exact fallback is the *only* path that can decide a
    continuation lying exactly on a radial ray, so it is not a ceremonial backstop, and a stubbed fallback would be
    a correctness hole rather than a performance choice. An unbounded computation with no declared limit is
    Amendment 19's unreportable exit in a performance costume.
    The counterweight, equally worth carrying: **the worst case need not be the measured one.** At the mechanical
    witness's vertex 30 every sign test collapsed to rational identities — two exact right angles (`u·w = 0`) and
    two exact complementary pairs (`D₁D₂ ≥ 0 ∧ (D₁D₂)² = Q₁Q₂`) — giving `Θ = 2π` exactly with no factorization and
    no floating point, and turning a previously non-authoritative float observation into a proof. An
    exactly-recognizable rational short-circuit is a legitimate optimization; it is never a semantics, and the
    general path must stay reachable. `DESIGN.md` Amendment 23.


74a. **A representation gap can be proof that the semantic operation was never defined.** CB8 stopped because the
    exact branch atlas could not transport an arbitrary ray through a non-coplanar vertex fan. The first instinct
    was to choose a richer exact number type. Independent review found a prior question: on a non-flat intrinsic
    vertex star, an unfolded straight-through ray can encounter a gap or overlap, and the architecture had never
    said whether that means no owner, multiple owners, regularizable degeneracy, or something else. **Do not choose
    a representation for an operation whose mathematical result set is still unspecified.** First freeze the
    reference geometry, ownership rule, and typed non-owner states; only then choose an exact predicate or a
    certified filter with exact fallback. Moving a discrete owner upstream does not solve the problem if its writer
    still needs the undefined predicate.

77. **A convention that makes a choice unique is not a precondition on one of the alternatives.** The exact
    half-open sector rule `direction[next] > 0 ∧ direction[previous] ≥ 0` exists so that exactly one sector of a
    vertex fan owns each ray; its asymmetry — include the `next` radial ray, exclude the `previous` one — is
    deliberate, and as a partition it is correct. CB9 reused the same call to answer a different question: *is this
    one face the owner of the ray the trace arrived on?* Asked that way, the deliberate exclusion becomes an
    arbitrary rejection of an ordinary arrival, decided by which side of a shared edge the mesh happened to number
    first. At mechanical vertex 11 the branch direction has an **exact IEEE zero** coordinate, so the trace runs
    along mesh edge `(10,11)` and its reversed arrival ray *is* a radial ray — owned, correctly, by the neighbouring
    face. The product refused a legitimate arrival and reported `VertexTransitSeedUnavailable`.
    The general form: a predicate whose name or comment says *partition*, *elect*, *own*, or *choose* answers a
    question about a **set**. A question about a **single member** — "is this ray admissible in this face?" — is a
    different question and needs its own predicate; the two must never share a call. Membership in a closed region
    and ownership of its boundary are not the same relation, and only the second is allowed to be half-open.
    This is the sharpest form yet of the single-authority family: not two authorities for one datum, but **one
    correct rule reused for a question it was not written to answer**.
    `Architecture_M3_CP4c3_TB7_Independent_Review_Record.md` §3, §6.

78. **A guarantee is scoped by its call graph, not by its name.** Accepted identity
    `ResolvedBranchCorrection.NetworkDiagnosticsPublishEveryRequiredLocusLosslessly` has passed every gate since it
    was written, while the production projection silently discards fifteen fields of
    `FieldAlignedCurveNetworkError`. The identity constructs error objects by hand and asserts tokens against
    `network_error_locus` — a **test-local** renderer. The path every CP4c production witness actually reports
    through — `RemeshPipeline.cpp::network_failure_locus` → `SurfaceCellFailureLocusDiagnostics` →
    `append_cp4c_failure_locus` — is never touched. The authoring control: an identity whose name asserts a property
    of *the system* must be routed through the entry point the system uses; if it builds the DTO itself, its name may
    only claim a property of the DTO. Declared at `M3-CP4c-3-TB8-REV`; the cost was one full turn spent proving that
    a red could not be attributed.

79. **One typed name over many emission conditions is an untyped failure — and splitting the name is often
    unavailable.** `FieldAlignedCurveNetworkErrorCode::InvalidNetworkTerminalOwnership` is emitted at **twelve**
    distinct sites for twelve distinct conditions. When it fired at TB8 ordinal 366, static proof eliminated ten and
    could go no further, because the two survivors emit the identical rendered locus. `M3-CP4c-3-CB10`'s AZ3 rule —
    one typed name per condition — had been applied to the three vertex-star seed conditions and nowhere else. The
    catch worth remembering: an **accepted identity may assert the enum value** (ordinal 328 asserts this one), so
    splitting it would be a stable regression. The discriminator then belongs in an **added field**, which is
    additive and cannot break an accepted assertion. Generalize AZ3 to every multi-site code, by field where the name
    is load-bearing.

80. **A diagnostic field that is declared and never assigned is worse than a missing one.**
    `FieldAlignedCurveNetworkError::publishedFaces` has a declaration, a projection, and a rendered token, and **no
    assignment anywhere in `src/` or `include/`**. Every network-stage failure therefore renders
    `publishedFaceCount=0`, which reads as an observation about the network and is in fact a property of the code.
    Before trusting a locus token as evidence, confirm the field behind it is written on the path that produced it.

81. **An origin credential is not an arrival credential.** A singularity *port* says where a trace may start; a
    singularity *node* says what a trace may end at. `append_field_aligned_singularity_termination` reached the
    terminal node through `terminalPort->node`, so a `BarrierAbsorbed` singularity — which emits no ports **by
    design** — could not receive a termination, even though its node is allocated unconditionally and is a
    mandatory-barrier endpoint. When two tables model the same entity at different cardinalities, decide which one
    the question is about before writing the lookup; reaching a required target *through* an optional table is the
    defect. Declared at `M3-CP4c-3-TB9-REV`.

82. **A reachability witness proves the name, not the branch.** `M3-CP4c-3-CB11` was required to demonstrate that
    each surviving emission site is reachable, and did — but its witness for the port-ownership condition fires the
    disjunct in which a port exists and owns a different vertex, which the production `VertexHit` path can never
    reach because it derives the terminal vertex from the same `source_support()` the guard re-reads. When a typed
    condition is a disjunction, the witness obligation is **per disjunct**: "reachable by some route" says nothing
    about the route production takes.

83. **Geometry locates a failure; only the source predicate adjudicates one.** Every edge of TB9's traced chain has
    an exactly 90 degree dihedral, and "sharp implies barrier" is nonetheless false on that witness — v47 is
    equally sharp and provably emits ports, because barrier edges are region-restricted
    (`FieldTransportAtlas.cpp:962` requires both incident faces inside the region). Reconstructing a fixture is the
    right tool for finding where a trace went and the wrong tool for deciding whether the product was correct.

84. **Resolving a collapsed error code means naming the sites that publish *nothing*; adding the name to the sites
    that already had a locus resolves the cases that were never the problem.** `EmbeddedGraphTopology.cpp` emits
    `RotationSystemInconsistent` from **46 sites**. Nine gained a `RotationSystemInconsistencyReason` in an earlier
    turn — and every one of those nine already set `sourceEdge` and/or `sourceFace`. So the localisable cases became
    more localisable while **twenty-eight** sites that publish neither a reason nor an edge/face locus stayed
    silent, twenty-three of them publishing nothing at all — and the gating red then fired from that silent set,
    leaving the review able to prove only which twenty-eight sites it was **not** narrowed beyond.
    The rule this adds to 57 and 64: when instrumenting a collapsed code, **partition its emission sites by what
    they already publish, and instrument the empty partition first.** The sites you can already localise are the
    ones that least need a name, and an instrumentation measure scoped by "add a reason" will be satisfied by the
    easy half unless it says otherwise. Write the measure as a predicate over sites — *"any site constructing this
    error without assigning a reason"* — and require the implementer to report the count.
    `Architecture_M3_CP4c3_TB10_Independent_Review_Record.md` §3.

85. **Count every boundary that drops the datum before repairing one — the loss you can see is usually the last
    one.** TB10 correctly observed that `RemeshPipeline::cut_graph_failure_locus` publishes two of the ten fields
    `SurfaceCutGraphError` carries, and named that as the cause of an unreadable red. There were **three** losses of
    the same datum in series: the silent producer sites; `SurfaceCutGraph::topology_error`, whose error type has no
    `sourceVertex` field at all; and only then the projection. Repairing the visible one alone would have bought a
    full turn of byte-identical evidence, because the error was already empty before the renderer saw it. **Walk the
    datum from its producer to its reader, count every boundary that narrows it, and fix the earliest.** A corollary
    worth keeping: when one stage boundary in a file publishes everything it holds and the neighbouring one
    publishes two fields, the asymmetry is the finding — here the *atlas* failure in the same function renders
    `incompleteCycleBasisReason` plus full per-region rows, forty lines above the cut-graph failure that renders
    almost nothing. `Architecture_M3_CP4c3_TB10_Independent_Review_Record.md` §3.3.

84. **A fail-closed uniqueness assertion must compare the whole key it asserts on, or say why not.** `RayOrderKey`
    sorts on six members - `primary`, `secondary`, `kind`, `trace`, `arc`, `orientation` - and
    `build_rotation_system` checks collisions on two. That is defensible only if the other four are
    known-irrelevant to the invariant, and if so the key should not carry them and the guard should say so. As
    written, the predicate cannot distinguish "the key is under-determined" from "the input is duplicated" - the
    exact ambiguity that left `M3-CP4c-3-TB11-REV` unable to adjudicate.

85. **An identifier is only a discriminator inside the scope that makes it unique.** `port->ordinal` is injective
    over the ports of one singularity. Used as the within-sector tiebreak at an arbitrary vertex fan - with no
    check that the port's source vertex is the locus vertex - it silently ranges over ordinals minted at other
    vertices, so two unrelated rays in one sector can carry the same number. Before borrowing an id as an ordering
    key, verify that the scope guaranteeing its uniqueness is the scope being ordered.

86. **When one branch of a shared contract is right, read it before designing the other.** The vertex locus and the
    edge locus fill the same `RayOrderKey::secondary` slot in `build_rotation_system`. The edge branch computes a
    locus-relative, exact rank and documents that intent in a comment - "keep that exact topological case between
    the two carrier destinations without using geometry" - while the vertex branch substitutes the ray's origin
    port ordinal. The correct design was already implemented forty lines away. Before inventing a rank, key or
    tiebreak, diff the sibling implementations of the same field.

87. **A quantity that is only incidentally correct will be wrong the first time it matters.** `port->ordinal` was
    consistent for a singularity's own emanating rays, and the v47 census shows `primary` already separated those -
    so it never did any work where it was correct. It became load-bearing only for rays arriving from other
    vertices, which is precisely where it carries no meaning. Ask which inputs actually reach a tiebreak before
    trusting it, and check whether the cases where it is correct are cases where it is also redundant.

88. **A turn that mints a typed reason must audit the reasons it reuses.** `M3-CP4c-3-CB15` correctly created
    `RotationVertexTraceRaysExactlyCoincident` for its exact-coincidence fail-close, then routed its other new
    failure into the pre-existing `VertexTracePortOrdinalInvalid`, whose legacy emitter sets the identical locus
    fields. The result was a first red whose cause TB13 could not attribute, recreating in one commit the
    collapsed-reason ambiguity of lessons 79, 82 and 84. When a change adds a condition, ask not only whether the
    new condition needs a name but whether the name being reused still denotes one thing.

89. **Execution order across turns is usable evidence.** The legacy emitter was excluded at vertex 10 without
    reading its logic: CB15 touched no file upstream of the rotation system, so the network was byte-identical to
    the previous TB's; node ids are monotone in vertex index and the incidence map is keyed by node id, so vertex
    10 is processed before vertex 47 - which the previous TB reached. The same code had already passed that vertex
    on those exact inputs. When a successor changes one layer and the failure moves, the untouched layers' prior
    successes are a proof instrument, not just context.

90. **A fallback chain owes coverage, not arithmetic.** `vertex_locus_secondary_parameter`'s exact opposite-edge
    projection and its guards were correct; the defect was that `vertex_trace_ray_second_point` enumerated four
    ways to locate a ray's second point and omitted a fifth the producer emits - the `VertexHit` exit, documented
    as Amendment 3 since `M3-CP4c-3-TB7-REV`. The rejected ray's parameter was exactly 0 and every guard would
    have passed. When a function body is a lookup chain, review the chain against the producer's case list rather
    than the mathematics that follows it.

91. **Clearing a stage exposes the next stage's untested contract.** `M3-CP4c-3-CB16` fixed the last vertex-locus
    defect, and the very next node the rotation reached was the first contact node ever processed on the mechanical
    witness - whose edge-locus rank helper had never run there. The helper was not wrong for the inputs it had
    previously seen; it had never been exercised. When a correction unblocks a traversal, the newly reachable code
    has the diagnostic maturity of code that has never failed. Budget a diagnostic turn for it instead of reading
    the first red as a regression.

92. **A typed-reason split is a pattern, not a patch.** CB16 correctly applied its measure to the vertex helper and
    left the structurally identical edge helper with five untyped `return std::nullopt` statements, so the next
    failure was again unattributable for the same reason, one helper over. When a turn corrects a
    diagnostic-collapse defect, the measure should name the class - every helper funnelling multiple conditions
    into one bare `nullopt` behind a single typed reason - rather than the one instance the current red exposed.

## 5. Cross-field, cycle, and orientation conventions

These are A1/A2-specific and have been the single most expensive area in M3.

51. **The signed `dual_cycles` row is the one orientation authority.** Order already-directed steps
    without reversing semantic orientation; never mutate an expected lift to make a comparison pass.
    Compare an exact index's `Z4` class to a signed matching composition only after proving both use
    the same canonical semantic cycle support.
52. **Transition orientation is mesh-owned.** `EF(edge,0) -> EF(edge,1)` is published by topology,
    not chosen by the caller. Any code — product or fixture — that assumes a face-pair ordering has
    made an assumption source does not promise. Locate the adjacency topologically, then read its
    published direction.
53. **Representation storage is not semantic cycle support.** Sparse-sparse aggregation retains
    explicit algebraic zeros. Canonicalize exact-zero incidence before any iterator-based
    curvature/support semantics, and keep downstream zero-skips defensive rather than letting
    different consumers see different cycles. Representation validity is also not source-topology
    validity: bind every published fact back to checked source authority.
54. **Independent cycle verification must recreate the semantic basis from source authority**, not
    merely recompute transport over product-published cycle support. A source-derived oracle owns its
    own cycle support/orientation, curvature, matching/effort, and exact lift before comparing the
    published witness.
55. **A derivation is not closed merely because its algebra is internally consistent.** If a
    fixed-orientation producer and an independently source-derived oracle both reject the same valid
    baseline, reopen the mapping from mathematical symbols to repository edge, cycle, curvature,
    index, matching, effort, and sparse-support conventions before any further semantic edit.
56. **Exhausting a sign search does not prove the invariant false** — it proves the searched family
    did not fix the implementation. Re-check the full producer equations, representation
    normalization, and source-to-symbol mapping before changing architecture. *(This lesson is itself
    a correction: a review once concluded from an exhausted search that the invariant was false in
    general, having omitted `indexMinFromZero` from the matching producer. Both the original
    derivation and its rescope were wrong.)*
57. **A check that adjusts its own expected value until it agrees is not a check.** Searching over
    sign conventions converts a falsifiable invariant into a tautology that fails only when every
    candidate fails.
58. **Never publish a guessed value as authority.** An expected lift that was searched or altered to
    satisfy a composition and then hashed into a certificate makes the certificate attest to the
    search's outcome rather than a derived fact.
59. **Do not make a new invariant a hard precondition of an accepted path until the invariant and
    its source mapping have a non-vacuous independent witness.** Once the architecture requires that
    precondition, acceptance must restore the witness rather than bypass the gate. A hard gate
    amplifies one stage-local bug into every downstream red.

### A `FieldBranch` integer is face-gauge-local, not a global direction label

A fan-partition oracle reused branch values `0..3` independently in every face frame and expected each
integer to denote one fixed physical direction across the fan. But each face's branch frame chooses its own
canonical gauge from mesh-owned topology. The same numeric semantic branch can therefore resolve to different
world/exact directions in independently canonicalized frames. **Cross-face oracles must transport branch
authority through the published transition or compare the published physical/exact directions under each
face gauge. Never equate branch integers across distinct frames merely because their stored values match.**

### Branch correspondence is not geometric-datum transport

A quarter-turn/signed-lift transition can prove **which branch label corresponds** across two face gauges without
proving that the target face's local branch representative is the transported image of one incoming geometric ray.
TB6-REV found this after a correct exactness repair: the code rotated the branch label exactly and then assigned the
target `pairing.direction` as `incomingDirection`, restoring exact arithmetic while silently returning to one datum
per cell. **When a contract requires one semantic datum, audit its writer and provenance at every state; exact type,
matching label, and common name do not establish common authority.** If exact continuous transport is not present
in the product, fail closed or add that authority — never manufacture it by rebinding to a local representative.

## 6. Gate and criterion authoring

60. **Do not author a gate criterion in terms the gated milestone cannot express.** M1 criterion 5
    demanded a disposition tier scheduled for M7, making M1 unclosable by construction. The error was
    in the criterion, not the implementation that failed it.
61. **Do not backfill a later architecture concept into an earlier gate by analogy.** If a criterion
    names a product the frozen package does not expose, related evidence is not a substitute. Treat
    the criterion as undecidable until an explicit mapping or authorized amendment exists.
62. **A criterion applied to a set of fixtures or components must be stated per member, at that
    member's own semantic stage.** A conjunction naming one stage's authority cannot apply to members
    that never reach that stage. Before freezing a gate, check every named concept exists for every
    named member.
63. **A milestone-crossing obligation belongs to the milestone that can discharge it, as an exit
    criterion** — not to a task list, which has nothing enforcing it. M4 owns the `G4-B002`
    re-proofs, M5 the `G4-B003` re-proofs, M7 the criterion-5 disposition re-proof.
64. **A frozen selector may not shrink to obtain green.** No identity may be removed, renamed, or
    converted to non-gating evidence inside an acceptance attempt.
64b. **A plan's prose obligation list and its frozen selector are two different artifacts, and only
    the selector is enforced.** Reconcile them item-by-item *before* freezing. CP3b's six identities
    all passed non-vacuously, yet two of its six written obligations — rotation-system/face-walk
    consistency and crossing tamper — had no owning identity, so a green gate proved neither. Nothing
    in a green result reports what the selector forgot to ask.
64c. **Name a proof's construction, its rejection reasons, and its independent oracle before writing
    code against it.** CP0 did this for the A1 certificate and CP1 went cleanly; nobody did it for
    the per-region disc-topology proof, which is why CP4 needed a planning turn inserted ahead of it.
    Naming a product whose definition does not yet exist is the criterion-5 shape.
64d. **Check whether a blocker is actually on your path before treating it as a prerequisite.**
    `G4-B001` looked like it blocked CP4c's torus witness because both say "torus". It fires at the
    completion/materializer stage, downstream of everything M3 does. One tracker read settled it.
    Locate a blocker's *owning seam*, not its subject matter.
64p. **When you amend a definition, re-read the definitions it depends on.** CP4-DEFN's section 4.1 arc
    definition — trace arcs subdivided at every event node, mandatory arcs never subdivided — was written
    once and carried unchanged while sections 4.4 and 6 were amended three times underneath it. That
    unexamined asymmetry was the defect three amendments later. An amendment changes the contract its
    neighbours were written against; walk the dependency both ways before freezing it.
64n. **Verify the formula using the same definition you are about to freeze.** CP4's Euler reduction was
    validated four times computing `V_int` as *all vertices minus mesh-boundary vertices*, then frozen in
    prose as *not an endpoint of a mandatory arc on the region's walk*. Those are different predicates;
    they agree only under a condition nobody stated. The table passed, the rule shipped, and the gate
    over-counted by exactly one. When a verification table and a rule text describe the same quantity,
    write the rule first and compute the table **from the rule**, not from an intuition of it.
64o. **A quantity that is off by exactly one on unrelated fixtures is one missing condition, not two
    bugs.** CP4's `V_int` was `+1` on both a fifteen-face two-ring witness and a four-triangle fan.
    Treat a constant offset across structurally different inputs as a *classification* defect and go
    looking for the case the predicate forgot — not as two coincidences to debug separately.
64m. **"The authority is missing" is a claim to test, not a conclusion to accept.** CP4ab stopped
    correctly on the finding that no product orders two contacts along one carrier — and that finding
    was true. But the *consumer* did not need an order: corner incidence turned out to be forced by
    orbit-label chaining over data already published. Before scoping a reopen of an accepted product,
    state exactly what predicate the consumer must answer and check whether the existing invariants
    already determine it. Reopening an accepted stage is the most expensive move available; spend a
    Review proving it is necessary first.
64k. **A planning agent's formula is a fixture, and it needs a falsifying case before it is frozen.**
    CP4's disc proof was frozen as `χ = F − E_int`, checked only against two triangles glued on an edge
    — the one case where its error vanishes. It is wrong for any region containing an interior source
    vertex, and on the accepted witness it returned **−5** against a true `χ = 1`, costing a full
    acceptance attempt on a false rejection. Every lesson this project has about non-vacuous fixtures
    applies to prescriptions too: before freezing a formula in a plan, compute it on a case that would
    expose it if wrong, and put the table in the document.
64l. **A compressed reduction hides its own preconditions.** `χ = F − E_int` is true for a tree of
    discs and false otherwise; `χ = V_int − E_int + F` is true when the boundary is a single walk with
    no pinch. Neither shortcut is wrong in itself — what is wrong is stating one without its
    precondition, because the implementation then applies it where it does not hold. Write the
    precondition next to the formula, in the plan and in the code comment.
64j. **An oracle that consumes the published output and re-runs the published algorithm is a mirror,
    not an oracle.** CP4's B4 read the published region partition, recomputed the same quantities with
    the same model, and compared six certificate fields one by one — so it agreed with a wrong
    implementation because both shared the defect. Independence must come from **re-deriving the
    inputs**, or from a genuinely different derivation of the same fact, not from recomputing one
    formula on one published output. Comparing a field forces both sides to compute it the same way.
64h. **An implementation turn may localize a condition; it may not decide which corrective measure owns
    it.** A routing table authored inside a diagnosability-only Code + Build turn sent
    `RegionCutComponentCountDeficit` to K5 while the binding Review had already assigned that precondition
    to K3. The next Code + Build correctly refused to proceed. Assigning corrective-measure ownership is a
    planning act: any routing an implementation turn produces is a hypothesis for the next Review, never
    a frozen input.
64i. **When three attempts stop at the same seam, stop tuning and measure.** CP4b spent three acceptance
    attempts and CP4ab spent a diagnostic and a Code + Build before anyone asked for the two integers
    that decided the question. A diagnostic gate that returns a *code* but not the *numbers* has only
    done half its job. Name the specific quantities the next decision depends on, and spend the gate on
    those.
64f. **A green gate certifies that the selected identities passed. It does not certify that they were
    capable of failing.** M3 CP4a reached an immutable 310/310 while its region ownership was assigned
    by container-order seeding, an arbitrary unclaimed-face fallback, and BFS nearest-seed-wins — three
    prohibited moves — because `CoversEverySourceFaceExactlyOnce` asserted only that the partition was
    total, which a flood fill guarantees by construction. The next checkpoint then spent three
    acceptance attempts failing to preserve that manufactured partition. **For every assertion, ask
    what input would make it fail.** If the implementation guarantees it structurally, it is a
    postcondition restatement, not evidence.
64g. **Two checkpoints where one depends on the other's correctness are one checkpoint.** Splitting
    region derivation from the disc proof that adjudicates those regions put an accepted predecessor
    between the halves, and the accepted-predecessor rule then obliged the second half to preserve the
    first half's error. Before splitting, ask whether the second half could ever legitimately *reject*
    what the first half produced. If it can, they are not independent domains.
64e. **An enumerator with no producer proves nothing, and a gate will not notice.**
    `FieldAlignedNetworkEventKind::SingularityTermination` has existed since CP3b, is required by an
    acceptance criterion, and is emitted nowhere — a repository search finds only its declaration.
    Declaring a case is not implementing it. When a criterion names a set of outcomes, check each one
    has a producer *and* a witness that reaches it.
64q. **Write a measure from the selector, not from the design intent.** CP4c-0b's U3 and U4 asked for a
    fan and two-ring terminus census and a guard-silence census that *no selected identity produces*.
    The capability existed — the production census channel is threaded through the producer itself —
    but six of the seven `...IsPublishedNonGating` census identities were in no selector, and the two
    identities in the gate that build the fan discard the result. The measure was written from what the
    code could in principle observe rather than from what the frozen selector actually runs. Before
    freezing a measure, name the identity that will emit each item and confirm it is *selected*.
64s. **An assertion whose failure message contradicts its own predicate is the message telling the
    truth.** CP4c-1's C5 read `ASSERT_EQ(2U, producedTerminalKinds.size()) << "terminal-kind witness
    union must be non-vacuous; …"`. Non-vacuous means non-empty; the code demanded exactly two. The two
    checks that actually carried the requirement sat on the next lines and — because `ASSERT_EQ` is
    fatal — **never executed on any run**. When a red's message and predicate disagree, read the message
    as the author's intent, then check what the fatal abort prevented from running: a correction that
    only fixes the predicate silently promotes never-executed assertions to "passed".
64t. **Freezing a cardinality freezes the incompleteness you happened to have that day.** C5 fixed the
    terminal-kind union at two while `SingularityTermination` had a declaration and no producer — the
    exact gap lesson **64e** names. The day the producer landed, a correct implementation turned the
    identity red *because* a trace correctly terminated at a singularity. Assert the property the
    contract states — non-vacuity, and subset-of-the-allowed-vocabulary — never a count, and never a
    count derived from what the current run happens to produce.
64u. **A witness over-specified once will be over-specified again, in the opposite direction.** The
    pipeline-authoritative torus was asserted *empty* in CP4c-0b (`DG-CAND-02`, resolved test-side) and
    *non-empty* one checkpoint later in CP4c-1's C5 — while an accepted identity green in the same run
    required zero. A universally-quantified contract is satisfied vacuously by a witness that produces
    nothing; adding a productivity precondition is additive over-specification every time. When a
    candidate resolves as test-side over-specification, grep the next checkpoint's new identities for
    the same witness before freezing them.
64r. **A `(void)`-discarded build is not an observation, and a smoke test that cannot fail is not
    coverage.** `FieldAlignedCurveNetworkIsAClosedProducerOnEveryReachableWitness` and DG#7 both build
    the four-triangle fan and both drop the result on the floor; one then calls `SUCCEED()`
    unconditionally. Each is lawful for its own narrow purpose — no-throw closure, and exercising an
    excluded witness without granting credit — but together they created the appearance that the fan was
    covered by the gate twice over when it was covered zero times. When auditing coverage, grep for what
    an identity *asserts about the result*, not for whether it constructs the product.
64v. **A frozen non-gating selector is authority, and a plan that quietly runs something else has replaced
    it.** `M3_CP4c_Consolidated_Record.md` §3.3 records that the frozen CP4c-2 non-gating selector named exactly one identity; R7 ran four
    others and never ran that one, without recording why. The skipped identity was an unconditional-`FAIL()`
    publisher whose whole job was to emit the sphere's pipeline-reachability report — free evidence, directly
    on the checkpoint's open question. **A TB plan must run every identity in the frozen non-gating selector or
    state, per identity, why not.** A selector that a plan may silently ignore is documentation, not authority.
64x. **Extend a gate by appending, so every earlier prefix hash still reproduces.** CP4c-2's gate 361 is candidate
    357 plus four appended identities; `head -355` and `head -357` of the new file reproduce the accepted-355 and
    candidate-357 hashes byte for byte, so `first_red_ordinal` stays comparable across the whole checkpoint arc
    and a red at ordinal 358+ is provably not a regression in accepted authority. Candidate 358 had already broken
    this by **inserting** its extra identity at line 357 rather than appending — so 358 is not a prefix extension
    of 357, and a first-red ordinal from one is not comparable with the other. Insert into a frozen selector and
    you silently destroy the one cross-turn comparison the project runs on.
64z. **A witness construction that is lawful on one witness class can be vacuous on another — bind the
    precondition to the class, not to the fixture.** `rails_from_atlas` filters the atlas's non-traversable edges to
    `SourceBoundary ∪ HardFeature`. On a **bounded** witness that always yields the boundary rails, so ordinal 358's
    square mesh passes. On a **closed** witness built with no declared hard features it yields **nothing**, so the
    torus gets an empty rail set, an empty network, and a red at ordinal 359. The same three lines of code are
    correct in one case and vacuous in the other, and the gate's own pass/fail split was the proof. **When a helper's
    output can be empty for a whole class of witnesses, make every caller assert non-emptiness for that class at
    runtime** — `if (mesh.boundaryLoops.empty()) ASSERT_FALSE(rails.empty())` — so the next author cannot
    reintroduce it silently. That is the CP3a fixture-asserts-its-own-precondition control applied to a helper.
64y. **A gate must not bind a witness its own checkpoint has declared out of scope.** Candidate 358's sole
    addition bound `cp4c_mechanical_fixture()`, whose production fixture *throws* when the pipeline retains no
    atlas — and the mechanical witness has no atlas and belongs to the next checkpoint. The gate would have been
    unconditionally red for a reason with nothing to do with what it was meant to prove. When the criterion is
    real but the witness set is mixed, **split the identity** — keep the in-scope witness gated, move the rest to
    the checkpoint that owns it — rather than withdrawing the criterion or gating on the whole set.
64w. **A new stage must have gated identities of its own, or it ships on transitive evidence.** CP4c-2 added
    A2a′ `SurfaceCutGraph` and **none** of its four direct test identities appears in the accepted selector or in
    either candidate gate — not the empty-cut certificate, not enumeration invariance, not the
    semantic/provenance separation. One of the four turned out to be non-viable and nobody noticed, because
    nothing ran it; another is the only falsifier of a live measure's written rationale. The checkpoint's actual
    open witness, the prescribed sphere, is in neither candidate gate either, which is the structural reason its
    failure survived eight turns unlocalized. **When a checkpoint introduces a stage, the gate decision must
    state, per identity of that stage, gating or not and why** — "it was never added" is not a rationale. And
    before selecting a gate, check what each added identity *binds*: one candidate's sole addition binds a
    witness the checkpoint has explicitly declared out of scope.

## 7. Budget, attempts, and stop rules

65. **A stop rule renegotiated every time it fires is not a stop rule.** M3's cumulative ceiling was
    amended under pressure at each binding point (11, `5 -> 6`, `6 -> 7`, `11 -> 12`, a pending
    `12 -> 13`), costing a turn per amendment and changing no decision. Tie the trigger to the
    checkpoint that is actually failing, and make the consequence a mandatory review rather than a
    request for more budget.
66. **A cost model calibrated on cutovers does not transfer to new capability.** M1/M2 cost tracked
    semantic domains re-typed, because the behaviour already existed. In M3-M8 a red checkpoint is
    usually a design defect, and design defects do not cost a predictable number of attempts.
67. **A budget is never permission to merge semantic domains.** Do not hide a shortfall by merging
    checkpoints, moving acceptance work to a later milestone, or inventing an unapproved partial-CB
    edge. A checkpoint is one surface only when it is one semantic domain — unit-3 Batch E grouped
    five ID domains under one label and spent 4 of that unit's 6 attempts.
68. **Every mandatory review must re-derive the failure from source**, not from the previous review's
    text; **check the checkpoint's fixtures against the contract's non-trivial domain**; **state one
    falsifiable prediction** the next attempt tests; and **enumerate the checks standing behind the
    fix** that the failure has been masking.
69. **Attempts spent on test scaffolding are still spent.** If consecutive attempts die before
    reaching any semantic seam, the checkpoint has no evidence about its own product and the fixture
    strategy — not the product — is what needs replanning. M3-CP2b spent its whole budget this way
    and left its central design question unadjudicated. **The diagnostic gate (next-but-one below) exists to
    stop this;** use it whenever a checkpoint introduces a new fixture.
70. **An attempt is a CB -> TB pair, never either half.** The pair is the unit of evidence, because a
    package that has not run against a gate has proven nothing and a gate result without its package
    is not reproducible. Consumption happens when the pair completes; a package awaiting its TB, a
    harness re-run, and a TB that yields no valid gate result all cost nothing. Hold at most one
    un-submitted package per checkpoint — the pair definition must not become a way to accumulate
    untested packages.
71. **A package attempt must not be the first *execution* of a new fixture** — the counterpart of
    the first-compile rule below, and the gap that cost M3-CP2b three attempts. Run a
    **new-contract-only diagnostic gate** first: the checkpoint's own identities alone, never the
    frozen predecessor selector, artifact-only, attempt-free, reporting the seam each red identity
    reached. The same package may serve the DG and then its acceptance TB, so de-risking is free.
    **A green DG is not acceptance** — the predecessor selector was never run, so predecessor safety
    is unproven and no checkpoint may be advanced or closed on DG evidence.

### A budget that a single red overrides is not a budget

An attempt budget exists to give the implementing agent room to self-correct **before** an external
reviewer intervenes. If one red already triggers a mandatory independent review, the budget grants no
room and adds only ceremony — plus a reset ritual performed four times across CP4ab. Abolished
2026-08-25. The workflow is `CB → TB → (red) → REVIEW+PLAN → CB`; a red TB consumes nothing.

### A turn type that executes a subset of another turn's surface is not a different measurement

`DG` was justified as measuring risk "without spending an attempt". Compared run-for-run, DG1's 316
identities were a strict **subset** of TB-R1's 322 — identical selector SHAs, identical
one-identity-per-fresh-process isolation, identical immutability flags, identical evidence shape. The
only real differences were which identities ran and what the result was *labelled*. It also cost two
turns and returned green about precisely the hazard that then materialised on the witnesses its
selector could not contain. **Before adding a turn type, diff its actual execution surface against the
one you already have.** If the diff is a label, you have added ceremony, not a control.

### Non-gating identities are the honest form of "run it but do not count it"

When a red is expected and informative, declare the identity **non-gating** with a written rationale and
an owning corrective measure, and let the ordinary TB report it. Do not invent a turn type, a budget, or
a reset window to hold that information.

## 8. Build, package, and workflow mechanics

72. **A package attempt must not be the first compile of new code.** A first-target preflight
    *inside* the packaging workflow only shortens the failing package; it does not satisfy this rule.
    Compile the exact changed owner target in a separate pre-package run on the same fixed semantic
    source SHA first. That artifact is **mechanics evidence, not TB input** — its target set is
    intentionally incomplete.
73. **Pre-package and package compiles must name the same fixed semantic source SHA explicitly.**
    Workflow caller/marker cleanup commits are control-plane history, not semantic source authority.
    If product/test/build source changes after the green pre-package compile, invalidate the
    preflight and do not package.
74. **Connector-written control payloads are not byte authority until hashed.** Use exact
    binary-safe Git blob transport and verify the frozen SHA-256 before execution. Bound checkout
    history to the minimum needed for ancestry/source-drift checks, and remember `git diff
    --name-only` omits untracked files unless they are intent-to-add or staged.
75. **Workflow installation and trigger are two distinct commits.** The proven pattern is install the temporary workflow with a narrow
    `.agents/connector-triggers/...txt` `paths` filter followed by create the matching marker, triggering the
    already-present workflow. Do not combine first-time installation with marker creation, and do
    not rely on the install commit as the trigger.
76. **Materialize packaged source archives with their recorded path layout intact.** TB-R2 stripped one path component from an archive that already stored repository-root paths, flattening `benchmarks/fixtures/...` to `fixtures/...` and manufacturing 26 accepted-predecessor reds. Before a long artifact-only gate, inspect the archive root and verify one known compiled fixture path at the exact embedded source root. A missing-fixture predecessor red is harness evidence, never a semantic regression.
76a. **Verify the runtime fixture root the binary will actually select, not only the archive layout.** Package 69 contained the exact Milestone-G manifest, yet TB2 still manufactured an ordinal-41 predecessor failure because `TestFixturePaths` found no sibling `test-data` and fell back to the absolute `DIRECTIONAL_TEST_SOURCE_DIR` baked at compile time. Before the first artifact-only selector process, resolve that fallback chain exactly and prove one known fixture exists at the path the packaged binary will use. If this defect is discovered only after Directional runtime has begun, preserve the attempt as orchestration-invalid and obey the frozen retry rule rather than repairing the launch root mid-turn.
77. **Reusable-workflow caller permissions are the union of every nested job, not only the path you expect to execute.** A reusable observer may contain a conditionally skipped branch-write job; GitHub still validates the caller permission ceiling against that transitive job graph. Before publishing a caller, inspect the reusable workflow's complete permissions and grant the narrow union required by all nested jobs. A permission-ceiling failure before generated runtime is orchestration-only evidence, never a diagnostic or acceptance result.

78. **Actions artifact round-trips preserve bytes but not executable permission.** `actions/download-artifact@v4` documents that artifact downloads normalize files to mode `0644`; a later `upload-artifact` therefore faithfully re-uploads non-executable files even when every SHA-256 is unchanged. `M3-CP4c3-TB3-ORCH-01` proved the failure end to end: raw CB3 artifact 9750227619 stored all six exact runtime binaries as `100755`, fixture packaging materialized them through `download-artifact`, and final package 71 stored the same hashes as `100644`. **When executable mode is part of package authority, carry the package tree inside a mode-preserving archive such as tar before crossing an Actions artifact boundary, and verify the modes after a clean archive round-trip. Never repair modes in TB.**

### Trigger commits must descend from the installed caller

When a temporary workflow caller is assembled with low-level Git objects, creating the commit object does not move the branch. A subsequent Contents-API marker write parents the **current branch head**, not the unattached caller commit. Therefore the safe order is: create caller tree/commit, fast-forward the working ref to the caller-install commit, verify that ref movement if needed, and only then create the separate trigger-marker commit. Marker-only commits made before the caller is on-ref cannot trigger that caller and should be treated as orchestration-only evidence, never as runtime attempts. TB-R4 exposed this control-plane ordering failure before any semantic runtime; the corrected installed caller was SchemaStore-validated and only then triggered.
