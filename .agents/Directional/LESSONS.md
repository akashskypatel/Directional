# Durable Lessons — DURABLE, DO NOT DELETE

This document records **reusable failure-derived engineering lessons**, not an execution log, status tracker, or collection of checkpoint narratives. Read the relevant section before planning a correction, writing a fixture or oracle, modifying authority/representation, defining a gate, or interpreting its result. These lessons supplement, but do not replace, the current frozen definitions, architecture, retention, workflow, and test contracts. Do not treat an example or prior result as proof of a new case.

**Cite a section and bold lesson title, never an ordinal.** Numbered historical entries were not stable identifiers; numbers were reused and changed as new lessons were inserted.

**Provenance and consolidation scope.** The [complete pre-consolidation LESSONS.md at commit 0314572f](https://github.com/akashskypatel/Directional/blob/0314572f256b05e9a65a2bafde4875a819a9a6a8/.agents/Directional/LESSONS.md) retains the full M0–M6 incident descriptions, derivations, counterexamples, former ordinals, reviews, and artifact references. This user-authorized consolidation removes repeated narratives and turns one-off failures into general rules; it does **not** erase that history or supersede independently frozen authority. For an exact historical claim, consult that version and its owning report rather than inferring details from a condensed rule.

## Evidence, acceptance, and scope

- **Compile, runtime, and acceptance are independent evidence.** A compiled or packaged source can be
  incomplete or wrong. A workflow trigger or control-plane/documentation commit is not execution
  evidence; a successful build is not a semantic gate. Record exact semantic source, packaged binaries,
  run/artifact identities and hashes, executed cases, verdicts, exclusions, and immutable postflight
  before claiming a result. A package lacking a selector-owning executable cannot execute that selector.
- **Prove that the requested tests actually ran.** Process exit zero, a green subset, or a suite name
  cannot establish selected-case coverage. Verify nonzero selection, exact selected identities and
  owning binaries, completed versus missing counts, execution view, and whether assertions actually
  inspected returned products. An unconditional success or discarded output may be an intentional smoke
  test, but must not be credited as behavioral coverage.
- **Separate historical baselines, candidates, regressions, and accepted gates.** A red candidate is not
  a newly introduced regression without the exact accepted-predecessor comparison. A re-proof stop
  identifies when the problem was detected, not necessarily when it was introduced. Keep inherited reds
  visible and non-gating until independently repaired; never shrink, rename, reclassify, or silently
  replace frozen selectors to obtain green.
- **Gate membership is the proof boundary.** A passing audit means the listed surface was checked, not
  that omitted families are absent. Reconcile every written obligation to an actually selected test
  identity and required binary before freezing. When extending a selector, append without changing
  accepted prefixes; verify historical hashes against the exact independent accepted files. State the
  uncovered products, stages, branches, witnesses, and cases alongside every pass.
- **Claims need their exact evidentiary owner.** An input/problem digest binds inputs, not outputs; a
  pass/fail ledger digest binds verdicts, not failure semantics. Compare output structural evidence
  separately. Use full validated digests or reference the authoritative file plus a reproducible
  derivation—never an abbreviated digest masquerading as a complete value.
- **A red does not cancel every independent observation.** Preserve admissible facts established before
  an unrelated terminal rejection (producer reached, control passed, field actually published), while
  clearly withholding acceptance. Conversely, clearing one guard merely exposes previously unexecuted
  downstream obligations; their status remains unproven until reached.
- **A claim about production must be observed in production.** The existence of a fixture, enum
  alternative, type, test name, public interface, or declaration does not establish that production
  constructs the product or emits that case. Enumerate call sites and emitting paths; demonstrate
  reachability through the real entry point and owning stage before crediting an end-to-end assertion.
- **Check evidence chronology and scope.** Prior accepted evidence does not automatically discharge a
  subsequently introduced obligation. Distinguish exact source, execution environment, fixture class,
  witness-specific assumptions, and stage ownership. Never promote a theorem established on one
  genus/topology or a single successful instance to another without proving its premises.
- **An unchanged test that turns RED is not by itself a production regression.** Before labeling it,
  check whether a deliberate contract change made the fixture's inputs insufficient (RA-92.4: the
  curved-disk fixture predated the factory's rail-provenance rule).

## Witnesses, tests, and independent oracles

- **A witness must be capable of falsifying its assertion.** Establish preconditions from the witness's
  actual geometry, topology, source provenance, producer shape, and execution path. Assert non-vacuity
  at runtime where it matters: nonempty sets, traversed stages, actual multi-face crossings, genuinely
  nonzero terms, representative cases, or triggered failure sites. A plane is not intrinsically vacuous;
  it is vacuous only for the particular invariant it cannot exercise.
- **Derive the witness from the real semantic product.** Hand-assembled “producer-equivalent”
  substitutes, hard-coded face orders, branch labels, group cardinalities, boundary/closed-rail shapes,
  raw indices copied into typed fields, and convenient fake owner maps can agree with themselves while
  missing production behavior. Use accepted producers or independent source/topology construction and
  metamorphic permutations. A reused witness must re-prove each new contract's preconditions.
- **Proofs must have discriminating counterexamples.** A control proving a test *can* fail and a
  production case showing whether it *does* fail serve different purposes. Pair difficult cases with a
  twin that changes the relevant feature only (e.g., coefficient magnitude, topology, crossing, periodic
  gauge). Verify new closed-form formulas against both easy and adversarial cases before freezing them;
  test stated assumptions, not just a computed table.
- **A test's actual assertion is its scope.** Inspect its result consumption and every field compared. A
  test named “full,” “independent,” “source-authoritative,” or “through production” may check only a
  count, a projection, or a chosen representative. One tampered field proves only one failure mode;
  structured evidence contracts need separate adversarial cases for their distinct mandatory fields and
  branches.
- **Never make a test assert today's defect as its success condition.** Hard-coding the current
  rejection code, expected absence, fixed event count, or incomplete vocabulary makes correct future
  behavior red. Assert the enduring semantic property, allowable vocabulary, non-vacuity, and exact
  rejection locus. When a guard's intended failure mode is replaced, update the oracle from the
  contract, not by allowing any failure.
- **A negative must reach the intended guard on a valid baseline.** First prove a legitimate witness
  passes; mutate one admissible dimension; verify the intended seam/rejection, not merely that an
  earlier guard rejects. If guard order changes, the original negative may become unreachable. A later
  assertion hidden behind a fatal assertion or early return has not executed.
- **Independence is derivation over the same semantic object.** Recomputing the producer's formula from
  its own output, choosing expected signs until equal, or verifying one internally consistent *proxy*
  complex does not establish correctness. Independently obtain topology/inputs or derive another theorem
  on the same authoritative object, then compare meaningful relations—not simply row counts, totals, or
  internally regenerated fields.
- **Partition and relation assertions must check structure.** Total coverage, a count of classes, or an
  injective-looking tuple is not enough: flood fill can guarantee a total partition while assigning the
  wrong owners; several inequivalent equivalence relations have the same class count. Check actual
  membership, edges, oriented incidence, complete keys, disjointness, and intended cross-stage
  consistency. When two partitions use different label spaces, match by canonical members, never equal
  numeric row IDs.
- **The oracle may be correct for only one path or witness class.** Fast and fallback branches, bounded
  versus closed surfaces, empty-rail helpers, source-boundary versus feature cases, and finite versus
  periodic charts require path-specific coverage. A selected test spanning multiple witnesses inherits
  *all* their blockers; split identities when their stages or prerequisites differ.
- **A validator must both accept valid input and detect violations.** Positive green evidence proves
  only non-rejection. Enumerate each failure site's reachability with meaningful tampering, including
  exact-once, bijection, sheet, class, orientation and consistency cases. Do not weaken correct
  rejection-only validation merely because it does not publish or choose authority.
- **A test is a control only after a run has measured it in the stated state.** Before naming a control, cite
  the run that measured its outcome; a test titled `Produced…` may never have produced. Before freezing a
  *reject* row in an outcome matrix, check whether the real producer generates that shape — a rejected shape
  that production emits routinely (middle segments of a subdivided rail) turns the plan's final TB RED (RA-85).
- **A test exercises a change only if its execution path reaches the changed code.** Before predicting
  "unchanged" as evidence for a change, trace where the test stops: a test that fails upstream of the
  change (in the consumer, before the factory runs) cannot falsify it. Add a test whose path reaches the
  change, and give it a falsifier that is readable from its failure text (RA-86.3).
- **Evaluate every truth-table row against an executable model of the rule before freezing it.** A
  row written beside a rule, rather than derived from it, can contradict that rule. A false gate then
  stops a correct implementation for a whole TB cycle. A model of a few lines catches this (RA-88.2).
- **A fixture change reaches every fixture built from it.** Before specifying or predicting one, list
  each helper and test that calls the changed builder, and say what each inherits. A derived fixture
  that edits the inputs afterwards can be left with authority that contradicts its own mesh (RA-93.3:
  the adjacent-sheet curved disk kept a rail over an edge it made interior).
- **A failure hidden behind an earlier one is unmeasured.** When an earlier failure is removed, do not
  predict the next one from an old baseline without first reading the test's history since that baseline.
  A fixture repair may have landed in between (RA-94.3: 199's cylinder half was repaired after R3).
- **Specify a negative mutation by its exact result, and check that result against every accepted image.**
  "Perturb by one ULP" is not a corruption when the rule accepts more than one rounding. RA-97.4 left
  the slot and direction open, and the chosen step landed exactly on the other orientation's valid image
  of 1/5 (RA-98.2).

## Semantic ownership, identity, and dataflow

- **Each semantic fact has one producing authority.** An accepted producer publishes the canonical value
  and a typed evidence product; downstream stages consume it instead of independently recomputing or
  inferring from a narrower projection. A read-only, independently derived consistency checker is
  permissible precisely because it cannot publish competing semantic state. Moving a computation to the
  right stage does not supply missing information or make an underdetermined question decidable.
- **Classify identities by their domain.** Raw row/index values, memory positions, source-face IDs,
  source-edge/vertex identities, source-chart occurrences, seam-quotient classes, regions, local sheets,
  and emitted vertices are not interchangeable. An identifier may be unique only within its source
  vertex, component, face, sector, or run. Prove injectivity and scope before using it as a key or
  tiebreak; never use world-space coincidence or an arbitrary representative as authoritative topology.
- **Representation conversions must include every consumer.** Before cutover, inventory producers,
  tests, checked validators, caches, diagnostics, serialization, adapters, and downstream API callers
  *by actual reads and semantic effects*. Convert all affected paths together, or explicitly freeze what
  remains. Translating a typed product immediately back into legacy shadow state does not finish the
  cutover. Audit assumptions by searchable predicates and dataflow, not stale source line numbers.
- **A typed product must carry every condition it claims.** Writer-only fields, defaulted optional data,
  stale mirrors, one name reused for distinct failure conditions, and lossy enum-to-string defaults
  conceal missing evidence. Publish complete source/chart, membership, transform, origin, side,
  provenance, and rejection data at the owning boundary where required. A derived view is not immutable
  merely because the writer was immutable; test its transformations and copies.
- **Origin, arrival, and carrier have different authority.** A start port cannot certify a valid
  terminal node; a recorded outgoing carrier can describe a proposed continuation that was never
  traversed; a source-edge carrier path may be exact provenance without being the semantic transform in
  the consumer's gauge. Make applicability, contact, endpoint, traversal, and direction explicit; do not
  back-fill a missing contact/locus from a seed or chart label.
- **Directed relations require directed evidence.** Unordered endpoint membership or canonical sorting
  cannot determine action direction. Derive direction from canonical semantic IDs and publish its
  transform independently of storage order; account for inverse and reversed carrier orientation. A
  downstream certificate should not have to recover a period action or transport by looking up global
  representation indices.
- **Semantic identity must survive transformations.** An invariant established when constructing a
  product can fail after copies, merges, per-chart projections, candidate filtering, or source-face
  renumbering. Exact owner/key constructors must be reused for derived caches; verify invariants on the
  consumed representation, not merely the original one. One non-null pointer may reference moved-from
  state, and two iterator endpoints from separately returned temporary containers do not form one valid
  range.
- **A scope restriction does not erase reject-only checks.** Distinguish choosing/merging/accepting
  authority from independently rejecting impossible or inconsistent values. Before deleting a “legacy”
  or “non-authoritative” guard, determine which failure it alone detects, what predicate replaces it,
  and whether a production path still relies on it. If one branch accepts an object another rejects,
  reconcile the contract rather than choosing the convenient branch.
- **Every semantic transition has a declared reference frame.** Compare local directions, regions,
  sheets, chart labels, and coordinates only after transporting both into a common gauge and applying
  source/quotient transitions. An integer-valued branch or local coordinate is not a global direction or
  seam endpoint identity; a common name or exact type does not establish a common geometric datum.
  Compose transports in one frame, prove reference independence, and check both endpoints' evidence.
- **Test an exact-identity rule against the coincidences the data already contains.** A witness that
  must "agree exactly" at every merge also meets legitimate merges: a shared rail vertex is p = 1 on one
  edge and p = 0 on the next. Run the rule over every merge the data passes through, including tolerance
  dedups and junctions, before you specify rejection (RA-96.2 A2).

## Geometry, topology, and mathematical obligations

- **Use the exact complex named by the claim.** Source triangles, split face fragments, embedded arcs,
  certified graph faces, cut-domain cells, quotient cells, plan regions and completion patches may be
  different complexes. They need not share boundary walks, connectivity, Euler terms, or ownership. A
  coherent calculation over a proxy complex is still an incorrect oracle for another one.
- **State topological formulas with their hypotheses.** Euler reductions require the correct vertices,
  edges and faces from the same complex; boundary cancellation needs the actual single-walk/non-pinch
  hypotheses; bridges and revisited nodes can invalidate shortcuts. For dart/face walks on a bordered
  surface distinguish capped exterior faces from bounded interior faces. Prove the formula on cases with
  interior vertices, loops, bridges, open boundaries and periodic topology—not only adjacent triangles.
- **A total surface assignment is not necessarily a valid partition.** “Assign any leftover face to the
  nearest seed” proves coverage by construction but may cross authoritative barriers. Verify the actual
  embedded cell/face partition, correct separation, source-supported boundaries, component/sheet
  independence, and orientation; no same-world-point merge may substitute for source equivalence.
- **Local and global counts answer different questions.** A local chord/fragment count cannot be
  inferred from globally shared orbit IDs without an injectivity proof. A segment-level terminal flag
  cannot decide whether an entire arc separates faces; a non-separating slit may contribute geometry
  without a new cell boundary. Measure actual directed darts, side ownership and separation.
- **A repeated node is not automatically a completed cycle.** Closed boundary tracing must account for
  consumed arcs, repeated vertices, branch/wedge incidence, orientation, and remaining unvisited
  directed edges. “Reached start” before all obligations are discharged is not evidence of a simple
  disk; arbitrary post-hoc slicing cannot replace valid directed incidence.
- **Exactness is about the decision and its premises.** Float input does not require epsilon comparisons
  for topological decisions; exact rational parameters, filtered predicates, and half-open angular
  partitions can preserve ownership. Adding a tolerance to a half-open partition creates overlaps or
  gaps. A chosen threshold is a tolerance, not a derived mathematical bound; near-tangency must be
  judged relative to scale and conditioning.
- **Mathematical guarantees inherit their domain assumptions.** Poincaré–Hopf and singularity-index sums
  constrain realizable cross-field/quad topology. A continuum theorem may not hold for a discretely
  sampled or discontinuous field without an appropriate discrete connection, matching and interpolation
  assumption. Distinguish source topology from resolution/aliasing and avoid assuming arbitrary
  singularity placement or global phase compatibility.
- **Discrete representations cannot invent absent mathematical operations.** When a field atlas stores
  only branch correspondence, it cannot silently supply parallel transport of an arbitrary geometric
  ray. When a topology solver lacks grid phase or a directed incidence rule, a downstream arrangement
  cannot reconstruct that missing decision from labels alone. Define the needed authority or fail
  closed; do not “exactify” an undefined operation by choosing a richer scalar type.
- **Follow the semantic boundary entity through the pipeline.** Scheduling/subdivision variables, cycle
  holonomy, feature constraints and canonical endpoint equivalence belong to the relevant
  source-supported boundary or quotient equivalence class, not whichever triangle row or representative
  point happens to contain them. Audit both sides of source-edge, local-sheet and periodic seam
  transitions.
- **Do not repair a conflict by removing its independent detector.** If a source-authoritative
  consistency check fires, first decide whether its invariant and scope are correct, localize the exact
  failing subcondition, compare deliberate counterexamples, and preserve any valid prior rejection
  coverage. Relaxation or new topology is authorized only from the verified shared root cause and
  normative contract.
- **A double is a lossy, mode-dependent image of an exact value.** Check the conversion's rounding
  mode before reasoning backward from a double. RA-95.3 assumed round-to-nearest and concluded
  p ≠ 1/5; GMP `get_d` truncates, and TB15 measured p = 1/5. Binding a witness to doubles bit for
  bit proves consistency, not identity, because many exact values share one double. Identity comes
  from comparing the exact values (RA-97).

## Diagnostics, classifiers, and causal investigation

- **Publish typed, lossless failures from the stage that owns them.** One error label emitted from many
  conditions is an ambiguity, not localization. Give distinct reachable causes with the complete failed
  source object, stage, branch, identity, numeric operands and authoritative support; never collapse
  distinct types into a generic compatibility name or render a missing field as though it were measured.
  Split analogous helper paths consistently, not just the first site encountered.
- **A diagnostic must be reachable on the failure path.** Check call order, early returns, exception
  paths, environment flags, output projection, and fixture selection. A field declared but never
  assigned, a diagnostic constructed below the return, or a log enabled only outside the frozen
  execution view is not evidence. Put the necessary discriminator before the failure and verify a real
  witness emits it.
- **A classifier must measure the object that failed.** The count/partition/face set built by an
  independent helper can differ from the one the rejecting consumer used. Publish original inputs and
  the actual producer-side and consumer-side identities. An error code plus face row is only a symptom
  if many unrelated witnesses share that row; classify by exact source/route/branch context.
- **Split compound predicates into independently inspectable terms.** A sum does not reveal its addends;
  a composite success/failure flag does not reveal which conjunct failed. A “not exactly one” result
  must distinguish zero from multiple; a paired two-sided scan must avoid double-counting mirrored
  incidences. Re-derive flag values from the emitted raw IDs where possible and check that the
  diagnostic itself did not silently duplicate the suspect logic.
- **Treat diagnostic reachability and outcome separately.** A branch that never executes cannot validate
  its guard. A census over established owners drops precisely the cases where no owner was established;
  a bounded first-N sample can hide rare conflicting classes. Emit unassigned/conflict states, retain
  structurally distinct counterexamples, and state search-space bounds before interpreting absence.
- **Use an unchanged control to distinguish mechanism from harness.** A sudden pass/fail reversal with
  no relevant semantic source change is a harness/selection candidate, not proof of product improvement.
  Confirm executable dispatch, fixture-root resolution, exact source, assertions, archived permissions
  and per-identity outcomes. Ledger digests alone do not capture why a test failed.
- **Diagnose causally, not by narrative proximity.** Source-line order is not call order; the first new
  red may be masked earlier behavior; a stage name, surface shape, or failure-site name can be a poor
  proxy for the actual causal predicate. Read the invoked producer/guard, compare unchanged witnesses
  across commits, and localize the earliest invalid owner without assuming the latest touched code
  introduced it.
- **A prediction must be falsifiable and reported honestly.** Enumerate the alternatives and the
  smallest observation that distinguishes them before dispatching another measurement. A new diagnostic
  subtype, classifier name, or different hash is not semantic progress by itself. Report contradicted
  hypotheses, preserved premises, and undecidable questions explicitly.
- **Bound diagnostic ladders.** Once successive turns repeatedly measure an insufficient discriminator,
  specify an explicit stop condition, an independent control, and the distinct corrective branches
  before adding instrumentation. The number of turns spent or amount of logging does not establish
  progress.
- **Treat a typed rejection as evidence, not a requested fix.** The diagnosis may belong to a different
  producer, stage, or Review than the place it surfaced. A rejection-only implementation may localize
  facts but must not silently decide ownership of a corrective measure, amend a frozen rule, or change
  acceptance.
- **A "not a member" classifier must first require that the set was published.** Non-membership is
  vacuously true of an absent set, so the rule silently admits a different failure shape (RA-91.2:
  selector 405 matched B2 although its fixture published no terminal contact).
- **Normalize `file:line` before calling a changed failure line a behaviour change.** Any edit to a test
  file shifts every gtest location below it. Read the diff hunks, or strip line numbers, before comparing
  first failures across builds (RA-102.1: ten apparent changes were one inserted `#include`).
- **A routing rule over a pair must read both members.** Branches keyed on the first occurrence of a
  relation let a mixed result read as one branch (RA-123.4: occurrence (0,1) fit B-fan, while (1,0)'s
  chart face sat across the seam).
- **Before designing around a relation predicate, ask whether its operands can differ under the producer's
  data model.** A check over two occurrences of one shared node is either tautological or unsatisfiable
  (RA-124.3: the A5 seam face clauses could never hold; a ladder of site diagnostics measured one instance).

## Contracts, planning, reviews, and durable records

- **Plan from the current normative contract and reachable implementation.** Before freezing an
  obligation, identify the actual producer, owning stage, live branch and witness class; confirm it can
  be expressed at that checkpoint. Do not retroactively require a later milestone's capability or treat
  similarity of names as ownership. A blocked successor cannot be made a prerequisite of its own
  predecessor.
- **Keep definitions and their validation mutually traceable.** State a rule and its exact predicate
  first, then derive verification tables from that same rule. When amending a definition, review
  dependent definitions, tests, prohibited corrections, supersession/index entries, and every
  implementing consumer. Do not attach a newly written part without activating it in the authority index
  and supersession text.
- **Require actual preflight before mutation.** A design or Review precondition that fails should stop a
  proposed fix before source changes or a costly gate. A stop is valid progress when it prevents an
  unsound change; it is not an invitation to bypass the precondition. Stop rules must themselves have
  finite, operationally useful bounds rather than magic numbers or budgets derived after work is
  consumed.
- **Write corrective measures as executable obligations.** Name exact behavior to preserve, the
  producer/consumer audit boundary, permitted and prohibited modifications, witness preconditions,
  failing and control cases, and falsifiers. “Convert all consumers,” “fix the owner,” or a
  line-number-only task is incomplete without a list or a searchable predicate that will find every
  affected reader.
- **Scope Review assertions to verified evidence.** A static review debt must reproduce in exact
  reviewed source before becoming successor work. A claimed theorem needs all premises and its relevant
  witness; a proposed invariant needs independently derived falsification. When a checker flips between
  “remove” and “restore,” freeze the missing distinction before another patch.
- **Review the semantics of refactors, not just their green results.** When moving or inlining
  validation, compare normalized predicates, boundary inputs, rejection kinds, order, and emitted
  details before and after. A passing selector or unchanged call order does not prove the transformation
  preserved each guard. Cite changes by source behavior, not by a misleading abstraction label.
- **Make success and failure symmetric in reports.** Verification must state which checks were run,
  skipped, non-gating, reached, and not reached. A contract's validity should be assessed independently
  of whether a chosen witness happens to satisfy it. Report a proved partial premise and a blocking
  later conjunct separately.
- **Keep deferred obligations visible.** A checkpoint closes only when its own written exit criteria are
  reconciled with primary retained evidence, including the less visible tasks and gates; it does not
  close because the loudest current red cleared. Preserve deferred scope and owner until explicitly
  discharged, and route the next turn to the turn type the required work actually needs.
- **Document only durable decisions and reusable rules in durable locations.** Changelogs own historical
  execution facts, trackers own regression/root-cause status, handoffs own current resume state, TODO
  owns pending tasks, and lessons own general operating principles. Avoid repeating full turn chronology
  across these roles. A failed branch or one-off numeric observation belongs in the owning historical
  report unless it teaches a distinct future rule.
- **Preserve before consolidating.** Confirm acceptance, evidence and current authority before folding
  reports. Resolve or annotate binding links, validate every forward section pointer, and retain exact
  historical attribution through Git. In explicitly protected append-only ledgers, a surviving
  header/marker does not prove the content survived: compare against committed-history
  high-water/content requirements; never replace the whole ledger with a one-entry update.
- **Do not mistake authoring for execution.** A Definition or Review turn can only prove claims its
  read-only or explicitly permitted checks establish; it cannot declare runtime outcomes or implement a
  repair under a diagnostic mandate. Separate Code + Build from Test + Benchmark, and do not invent
  successor authorization from an unfinished or conditionally blocked review.
- **A limitation a specification leaves open must reappear in every later plan.** Carry it either as a
  planned unit or as an explicit exclusion with its consequence for the plan's end state. R9B left inexact
  interior-point parameters open; three later plans did not mention them. The unit plan therefore could not
  close `RP-01` until a full-pipeline diagnostic exposed the gap (RA-87.2).
- **Localize before you specify a design turn.** A definition turn asked to search an unlocalized origin
  across a 21k-line file, and to design five more items in the same turn, stopped with nothing written.
  Review then traced from the logged hexfloats and found the single rounding site (RA-95.1, RA-95.3).
  Name the suspected site and the evidence that locates it before asking for a design.

## Build, artifact, workflow, and tool mechanics

- **Preserve exact source/package authority across stages.** Pre-package and package checks must name
  the same semantic SHA unless a source change explicitly invalidates the earlier check. Control-plane
  commits and workflow markers are not implementation source. Validate full digests and manifests;
  source/archive layouts, binary identities, and runner environment must match what the actual
  executables consume.
- **Verify executable and fixture portability before interpreting reds.** Archive bytes can survive
  transfer while executable mode bits do not; preserve mode metadata and reject rather than patch an
  immutable test package in place. Extract source using its recorded directory layout; independently
  verify the fixture path *resolved by the binary*, not merely that an identically named fixture exists
  elsewhere. A harness copied from a template has validated only what the template's own tests
  exercised. If the copy adds fixture-loading tests, add a positive control that loads the same fixture
  (RA-108: the template's tests loaded no fixture, and it staged them one level too high).
- **Inspect actual tool and build API contracts.** Reusable workflow caller permissions must cover every
  nested job, even conditional branches. A workflow definition and its trigger must be ordered according
  to the documented mechanism; use the durable dispatcher where authoritative, never gratuitously
  duplicate temporary callers or reusable logic.
- **A remote push must advance the intended ref.** Verify the branch and resulting head SHA after
  writes, and use compare-and-swap or explicit ancestry authority. A command that pushes a named local
  branch may succeed without pushing working HEAD. Concurrent agents can enter the same named turn;
  inspect the current authority and avoid overwriting work rather than inferring ownership from a turn
  name.
- **Treat files, containers and tool outputs as live objects with contracts.** Materialize
  value-returned ranges before passing iterators; handle moved-from containers safely. Check that
  packaged code really executed, required fields were serialized, and path/byte authority survived each
  API boundary; neither a non-null pointer nor a successful RPC implies semantic validity.
- **Use evidence-focused tool calls.** Prefer one verified immutable package/source snapshot for many
  local inspections, structured summaries over repeated log greps, and an explicit bounded retry only
  for a diagnosed orchestration failure. Do not replay unchanged deterministic failures, perform broad
  searches to justify a specific known action, or optimize call count at the expense of exactness.
- **A frozen manifest is code for its harness.** Before freezing, run the harness's own schema
  check on it, and give observation runs (censuses) a kind whose REDs are evidence rather than
  control failures. RA-169/170 froze site text and parameterized names the harness rejected, and
  GUARD rows that would fail on any census RED; each cost a zero-execution CI turn (RA-171).
- **The dispatcher's concurrency group holds one pending run.** A later push cancels a run that is
  still queued, so dispatch several runs only one at a time, after each has started (RA-92.1).
