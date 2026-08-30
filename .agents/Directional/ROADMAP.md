# Directional Surface-Cell Roadmap — accepted state to production-ready

**Purpose.** One forward-looking map from the current accepted gate to a production-ready
implementation of `DESIGN.md`. It exists because `DESIGN.md` §14 defines milestones **M0–M8** with
acceptance criteria but decomposes none of them into checkpoints, and only M3 had ever been decomposed
— inside a plan document, mid-milestone, under schedule pressure. Every prior milestone that started
without a checkpoint decomposition had to acquire one at cost.

**Authority.** `DESIGN.md` §14 owns *what* each milestone must prove; this file owns *how it is cut
into checkpoints*. If the two conflict, `DESIGN.md` governs and this file is corrected.
`TODO.md` owns the current open task list; this file is not a task list and must not accumulate one.

**Status date:** 2026-08-30 (**CP4c-2 CLOSED / ACCEPTED at 365/365.** Authoritative R10 run/job `33331453506 / 99310594268` consumed immutable GMP package `9736088354`; selector 365 SHA-256 `6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1`, immutable pre/postflight passed, every mutation and benchmark flag false. Criteria C1/C3/C6 green. Carried to CP4c-3: the prescribed sphere, Amendment 14's ordinary trace-crossed proposal path (`R10-CAND-01`), and `R8-CAND-02`. Exact next is definition-only `M3-CP4c-3-DEFN`.)

---

## 1. Where the project actually is

| Milestone | State | Accepted authority |
|---|---|---|
| M0 | historical prerequisite | artifacts retained as regression/oracle evidence only |
| M1 | **CLOSED / ACCEPTED** | `M1_Closure_Record.md` |
| M2 | **CLOSED / ACCEPTED** | `M2_Closure_Record.md` |
| M3 | **in progress — 2 checkpoints remaining** | CP4c-1 **355/355**, `M3_CP4c1_Closure_Record.md` |
| M4–M8 | not started | — |

M3 checkpoint state: CP0 (compile evidence only), CP1, CP2, CP2b, CP3a, CP3b, **CP4ab** are closed.
`M3-CP4-DEFN` is complete. CP4a/CP4b are superseded into CP4ab.

**CP4c was split on 2026-08-25** by `M3_CP4c_Consolidated_Record.md` §7 (retired CP4c parent TB-R1 review) after TB-R1
returned VALID RED 316/322. Its two committed witnesses are **closed surfaces** — torus χ = 0 genus 1,
mechanical χ = 2 sphere — while every witness that has ever validated A2b is a **bounded disc**, χ = 1.
Two of the three failure families are therefore scope gaps in *accepted* authority, not CP4c defects.

Cumulative accepted authority has grown 304 → 316 → 346 → 353 → 355 → **365** through CP4c-2. C1/C3/C6 were allocated to CP4c-2 and are green; C2 is allocated to CP4c-3, whose gate was frozen at **367** by `M3-CP4c-3-DEFN` and extends to **370** under AK7. The allocation of criteria to checkpoints is unchanged; which **witnesses** a checkpoint's identities bind is a DEFN decision, and CP4c-3's DEFN put the prescribed sphere in its gate.

---

## 2. Trajectory check against `DESIGN.md` §14 M3

`DESIGN.md` §14 M3 lists six acceptance criteria. Current disposition, each traced to the identity that
owns it:

| DESIGN §14 M3 criterion | Owner | State |
|---|---|---|
| singularity ports derived from field index, owned exactly once | A1 / A2a | accepted at CP1/CP3 |
| traces branch-consistent and provably non-crossing | A2a | accepted at CP3a/CP3b |
| every trace terminates at a typed network event; no silent interior termination representable | A2a | **accepted / re-proved at CP4c-1**: TB-R5 355/355, C5 PASS with exact W3 kind-union evidence |
| every emitted region carries a disc-topology proof | A2b | **accepted at CP4ab** (B1, B4) |
| network selection preserves mandatory topology under tamper | A2b | accepted at CP4ab (A4, A5) |
| tracing-order and start-port permutation invariance | A2b | accepted at CP4ab (A6) |

**Verdict: the trajectory is correct and the milestone is nearly discharged.** Every M3 criterion has
an owning identity and all six are green under the cumulative immutable 355 gate. M3 remains open only for the
production-representative closed-surface scope owned by CP4c-2/3.

The one substantive gap is not a criterion but a *scope* of proof: all six are proven on **development
witnesses** (the two-ring skew disc and the four-triangle fan), not on production-representative
meshes, and — as the CP4c plan establishes — **A2b is not yet constructed by the production pipeline at
all**. That is exactly and only what CP4c exists to close. See
`M3_CP4c_Consolidated_Record.md` §2.

---

## 3. M3 exit — the remaining checkpoint

CP4c's production A2b wiring (CB1) and its two production-path fixtures (CB2) are **built and
compiled**, and TB-R1 proved the wiring regressed **nothing**: the accepted 316 are green in the same
immutable run. What remains is split into three checkpoints. Identity names are unchanged from DEFN
§7.3; only their allocation moved.

| Checkpoint | Domain | Gate | State |
|---|---|---|---|
| **`M3-CP4c-0`** | resolved interval pairing with propagated barycentric positions (`DESIGN.md` §4.5) — **continuation only after the split** | **346**, `20d3b0b1...` | **Contract complete.** DEFN froze the continuation rule, DEFN-2 the grazing model, CB8 implemented it, CB9 landed deterministic cost guards. Closes on a green `M3-CP4c-0-TB-R9` against Q8 criteria **1, 4, 5** |
| **`M3-CP4c-0b`** | **trace termination** — trace/trace contact, arrival priority, contact node and event (`DESIGN.md` §4.6) | **353**, `51ff96d7…ac6a5` | **CLOSED / ACCEPTED.** T5 `33136084757 / 98736295227` passed 353/353; U3/U4 predictions and immutable postflight PASS. Closure: `M3_CP4c0b_Closure_Record.md`. |
| **`M3-CP4c-1`** | diagnosability, witness observability, event non-vacuity | **355 = accepted 353 + C4 + C5**, `e9d88f11…fb5afeaa` | **CLOSED / ACCEPTED.** TB-R5 `33161644741 / 98817323175` passed 355/355, W3 exact union/contributor prediction, and immutable postflight. Closure: `M3_CP4c1_Closure_Record.md`. |
| **`M3-CP4c-2`** | closed / higher-genus region authority in A2b | **365 = accepted 355 + C1 + C3 + C6 + four `SurfaceCutGraph` identities + three Amendment-14 identities** (frozen at CB7 under AG7) | **CLOSED / ACCEPTED 365/365** |
| **`M3-CP4c-3`** | closed-surface missing field-transport adjacency in A1, then the mechanical witness (**C2**); plus the prescribed sphere, `R10-CAND-01` and `R8-CAND-02` inherited from CP4c-2 | **367 = accepted 365 + C2 + C3's full torus-and-mechanical form**, frozen at `M3-CP4c-3-DEFN`, SHA-256 `ef9d082f56f5c8de83124cf2e6257d098408cc597d9147b967cf9c84da4916bf`; extended to **370** by AK7 | **NEXT:** `M3-CP4c-3-CB1` under AK0-AK3 |

> **`M3-CP4c-0` exists because `DESIGN.md` §4.5 is half-implemented, and its definitions are now frozen**
> in `Architecture_M3_CP4c0_DEFN_Frozen_Definitions.md`. §4.5 requires the inflow/outflow interval
> pairing to be *resolved* with **barycentric positions propagating in arbitrary precision**. Measured by
> the TB-R3 census: two-ring **50%** ambiguous, fan **25%**, torus **50%**, sphere **50%** — the exact
> signature of `dbary = {-u-v, u, v}` summing to zero, so a face is either `2×1` or `1×2` with no third
> case. **The gap is two missing data:** the entry position on trace segments, and the barycentric
> direction, which A1 computes and then discards. The DEFN freezes `FieldBoundaryPoint` (single writer
> A2a, canonical-edge parameter, exact rational), an exact minimum-ratio continuation with **no tolerance
> in any topological decision**, deletion of the Cartesian `connections`, and unification with the CP4ab
> barrier-terminus datum **without reopening CP4ab**. It proves that **no accepted witness's traces
> change**, because old and new rules agree on every `2×1` face and no accepted trace can ever have
> traversed a `1×2` one.

> **`M3-CP4c-2-DEFN` inherits a `DESIGN.md` §7.2 gap.** §7.2 derives the network from singularities,
> features, and boundaries; a closed surface with an index-free field has none of the three, so §4.6's
> motorcycle graph is empty — its size is `O(n)` in extraordinary nodes. Measured: the committed torus
> publishes **0 traces / 0 events**, and A2b then has no labeled face to seed region ownership from.
> Quad-remeshing a torus needs a **seam / cut graph the architecture cannot currently produce.** That
> DEFN must settle it before any genus > 0 code is written.

Historical CP4c turns, retained for provenance: `CB1` (wiring, W0–W5), `DG1` (the last diagnostic turn
this project will run), `CB2` (W7–W9), `TB-R1` (VALID RED 316/322).

CP4c-1's historical TB-R3 is **VALID RED 316/318** with the accepted 316 green in the same run. C4/C5 remain the only
checkpoint-local required identities and **stay gating**; demotion to non-gating was considered and rejected. CP4c-0 and
CP4c-0b are accepted; CB3 rebased the gate to 355, the mandatory review identified C5 test over-specification, CB4 corrected only that test authority, and TB-R5 returned **355/355** with the exact W3 prediction. CP4c-1 is therefore closed; exact next is `M3-CP4c-2-DEFN`.

CP4c-0's artifact-only TB proves the exact-continuation focused gate **328/328**, but frozen Q8 is red:
the prescribed sphere reaches A1 then A2a rejects `BranchContinuationDegenerateEntry` before network
publication. CP4c-0 remains unaccepted and CP4c-1 blocked.

**CB2 → TB-R2 executed that correction, and `M3-CP4c-0-TB-R2-REVIEW-PLAN` closed on 2026-08-26**
(`M3_CP4c_Consolidated_Record.md` §7 (retired TB-R2 review)). CB2 is build green at
`390e65b373063c667e3c3f5e78b74ed9d859093b` / package `9586196535` with the selector re-frozen at
**338 = 316 + 12 + 10**. TB-R2 re-proved the accepted **316/316** and the prior **328/328** prefix, then
failed at ordinal **329** on the first E1 correction identity: `FieldBranch::value()` returns
`std::uint8_t`, which stream insertion writes as a **character**, so `branch=1` emitted as `\x01`. Q8 was
correctly **NOT RUN**.

Review verdict: the failure is **solely** that formatting defect at two call sites — and it exposes a real
frozen gap, because Amendment 5 required a property of the emitted *value* and never constrained the
*mechanism*. A second defect of the same shape was found: ~15 trace-seed back-fills that E1c's
line-scoped wording never reached. Both are **class defects certified by instance falsifiers**, which is
the lesson of the cycle. E1–E9 were independently re-verified as correctly implemented; E2 and E3 in
particular are exactly as amended. **Amendment 6** now defines "observable" by mechanism. Exact next is
**`M3-CP4c-0-CB3`** under measures **F0–F8**. Identity **338** and **Q8** remain the open questions.

**`M3-CP4c-0b-DEFN` split the checkpoint on 2026-08-27**
(`Architecture_M3_CP4c0b_DEFN_Trace_Termination_Frozen_Definitions.md`). The inversion CB9 identified —
CP4c-0 blocked on a capability assigned to its successor — is resolved neither by reordering nor by
re-scoping, but by recognising that CP4c-0 had been carrying two unrelated obligations under one gate.
Continuation is finished and closes on its own 346 identities. Termination becomes its own checkpoint,
and Q8 criteria 2 and 3 move to it **together**, because the six circulating traces are simultaneously
what blocks the 24-trace network and what would satisfy the trace-intersection criterion.

The termination contract is frozen from measurement rather than from the citation. Self-contact cannot
be the rule: the field is one constant vector per `(face, branch)`, so a trace's repeat visits lay
**parallel** segments — measured, 2,548 co-face pairs with zero crossings. A mesh-derived length budget
cannot be the rule either: the longest correctly terminating trace and one lap of a never-terminating
trace measure **the same length to four decimal places**, so length carries no information about
termination, and a truncated trace leaves an arc that bounds no region. What does work is contact with
the **perpendicular** branch family, which crosses every circulating trace at step 0.

The one genuine choice — arrival priority — is frozen as `ArcLengthFiltered`: double arc length with a
*computed* forward error bound rather than a tuned epsilon. Exact comparison is excluded on complexity,
since comparing sums of *k* radicals is exponential in *k*. Ties turn out to need no arbitrary rule at
all: same-time-different-point events are independent, and same-time-same-point means both traces
terminate there. That matters because the sphere's singularities are cube corners, so exact ties are
*systematic* on symmetric input — precisely the inputs used to judge quality. Alternative priorities are
kept for future comparison but are unreachable from the production path, so the knob cannot become a
second authority.

**CB8 → TB-R8 → `M3-CP4c-0-CB9` exposed and guarded non-termination on 2026-08-27**
(`M3_CP4c_Consolidated_Record.md`). CB8 implemented DEFN-2's grazing
transit faithfully. TB-R8 then ran for 853 seconds on one identity and died with
`gcd(): while running too long!` — and the interesting part is what that turned out to mean.

Retiring `BranchTransportFlowDisagreement` was correct, but it had been aborting the sphere network at
the first grazing edge, which *incidentally* stopped every trace before any of them could go anywhere.
With it gone, six of the sphere's separatrices were free to do what the field actually makes them do:
lap a closed 32-face circuit forever. Neither guard noticed. The cycle guard keys on a state that
carries the exact entry position, which drifts every lap, so it is structurally blind to circulation —
the position was added to fix a false positive and created a false negative in the same predicate. The
step budget authorised 1,775,616 steps against an arithmetic that could not survive 205, so it was not a
bound at all. What actually stopped the run was the fallback bignum's fixed 10,000-iteration `gcd` cap,
throwing `std::runtime_error` out of a closed producer.

CB9's measures N0–N7 landed the guards: a **position-free** combinatorial recurrence bound calibrated
against measurement (every terminating trace enters each `(face, branch, carrier)` exactly once; the
allowance is two), a deterministic exact-magnitude policy that declines to answer rather than answering
approximately, iteration bounds derived from the algorithms' own worst cases instead of magic constants,
a step budget that is now provably an envelope of the recurrence guard, and a producer that stays closed
against its dependencies' failure modes. 42/42 legitimate traces are unchanged; the six runaways stop at
step 65; the worst exact width falls from 19,460 bits to 2,684.

**The remaining blocker is architectural, and it is not in CP4c-0.** `DESIGN.md` §4.6 says limit cycles
do not exist because crash-on-contact removes them structurally. A2a does not implement crash-on-contact
— it is C4/C5, in CP4c-1, which is blocked on CP4c-0. So CP4c-0's Q8 criterion 2 depends on a capability
assigned to its own successor. `M3-CP4c-0-DEFN-3` must choose between reordering C4/C5 and re-scoping
the 24-trace network, and no further CB cycle aimed at criterion 2 should start before it does.

**CB7 → TB-R7 → `M3-CP4c-0-DEFN-2` closed the model gap on 2026-08-26**
(`Architecture_M3_CP4c0_DEFN_2_Frozen_Definitions.md`). TB-R7 held the gate at **338/338** with the
accepted prefix at **316/316**, reproduced K1's near-tangency separation, and found **176/176 complete
vertex fans with zero holonomy mismatches** — so no period or transport defect exists to chase, and the
evidence pointed at the tracing model. K2, which was to have measured continuation cost, published
nothing usable: it walks traces with the **retired Cartesian carrier lookup**, carries no position, and
stops on the first `1×2` face, which on a 50%-`1×2` witness is step one for all 24 traces
(`M3-CP4c0-DEFN2-CAND-01`, test-side, owned by measure L8).

DEFN-2 therefore decided on **structure**. The tracing model already defines the exactly-tangent case —
Amendment 3 has the trace travel along the edge and exit at a vertex — so any rule for the near-tangent
neighbourhood must agree with it in the limit. **Grazing edge transit does, by the same expression on
the same index; a grazing terminus does not**, and would additionally forfeit the checkpoint, because
the grazing edges turn out to lie in corridors along the field's own separatrices. A refinement
precondition would reject every non-degenerate witness the project owns, two of them already accepted. A
general edge-following mode is unnecessary: the directions are constant per face, so the transit
completes in one hop.

The evidence was re-derived from the committed fixtures alone, with no product code: **72** grazing
configurations on **72 distinct** sphere edges and **120** on the torus, matching TB-R7's runtime
figures to six decimal places, with **zero** slide-direction ambiguities in 192 configurations. The
eight sphere singularities are exactly the corners of an inscribed cube, each with three grazing edges,
and the live locus `6-8` transits to **vertex 8 — itself a singularity** — so the blocked trace
terminates lawfully by `SingularityTermination`. A1 is untouched, T6 stays unreachable, and no new
event kind is added. Q8 is **not** amended; its criterion 3 is predicted unsatisfiable on this witness
for a reason that is a property of the field, and is re-homed to CP4c-1 with the response
pre-committed. Exact next is **`M3-CP4c-0-CB8`** under **L0–L9**, Code + Build only.

**CB6 → TB-R6 delivered the decomposition, and `M3-CP4c-0-TB-R6-REVIEW-PLAN` closed on 2026-08-26**
(`M3_CP4c_Consolidated_Record.md` §7 (retired TB-R6 review)). **This cycle identified the root cause**,
and it is a contract/model gap rather than an implementation defect.

The review reproduced the sphere's census from the committed `.obj` and `.rawfield` alone — no product
code — and obtained **exactly 144 directed disagreements**, matching the runtime figure. That
reproduction also explains them: the **tangency ratio** `min(|d_opp| / max|d|)` has median **0.0218**
across all 144 disagreeing pairs and **0.9233** across the 1008 agreeing ones, a 42× separation, with
every disagreement at or below **0.2004**. The direction is nearly parallel to the shared edge, the
field's own rotation across that edge (≈ 23°) flips the small perpendicular component, and **both faces
correctly compute "outflow"**.

At the live locus every published term is independently verified correct: `matching = 0` is
geometrically right with a wide margin (nearest target raw index **23.7°**, next **66.3°**);
`0 + 1 − 3 ≡ 2` reproduces the published lift; both gauges map to raw index 0; both `dbary` triples
match to **10 decimal places**; and all 288 interior edges are normal adjacency with no folding.

**So `Amendment 4` / measure `E5` is the defect** — it asserts a *continuum* property that a
piecewise-constant field does not satisfy near tangency. **Amendment 9** corrects it:
`BranchTransportFlowDisagreement` is a **typed grazing observation**, not an A1 defect; no tolerance may
be used to classify grazing; and **`DESIGN.md` §4.5 does not define what a trace does at a grazing
edge** — the substantive gap, and a `-DEFN` obligation. Three prior readings are withdrawn: the live
locus does not indict `build_branch_transports`; the two decision-table classes are one phenomenon; and
J3's 524/524 does not exclude H-B, because `independent_edge_measurement` re-implements principal
matching, the algorithm H-B suspects.

**CB5 → TB-R5 delivered the census, and `M3-CP4c-0-TB-R5-REVIEW-PLAN` closed on 2026-08-26**
(`M3_CP4c_Consolidated_Record.md` §7 (retired TB-R5 review)). H1 ran and reported **390 violations /
4224 pairs**. Review verified the census's *mechanism* in source — it applies the published `signedLift`
per Amendment 7 and reads the right coordinates — and then corrected its *population*:

- **The four-triangle fan's violations are a fixture artifact.** Its field
  (`make_index_one_singularity_field`) leaves the direction vectors globally constant and *imposes*
  `matching = ±1` on one edge. For the violating edge the published lift is **exactly correct**
  (`matching(+1) + g_source(0) − g_target(1) = 0`); the flow disagreement is forced by a matching that
  contradicts the geometry. One edge × two directions predicts **exactly the 2 observed**, and both
  reported `−1/2` derivatives were reproduced by hand. The brief's use of the fan as evidence against
  H-B is therefore **withdrawn**.
- **The lift histogram carries no information about matching.** `signedLift = matching + g_src − g_tgt`
  is a sum of three unobserved terms, and the ±k tail symmetry is imposed by the census's own
  two-direction loop. Distinct disagreements are half the reported counts: two-ring **2**, fan **1**
  (artifact), sphere **72**, torus **120** — a corrected population of **388 directed / 194 distinct**
  over three legitimate witnesses.

**H-A and H-C remain excluded; H-B is undecided and cannot be decided as currently instrumented.** The
next cycle adds one field: decompose the lift into `matching`, `rawGauge[source]`, `rawGauge[target]`.
Each branch of the resulting decision table names a different owner — field matching, gauge composition,
or flow classification. Measure **J1**; still **no production change authorized**.

**CB4 → TB-R4 closed the test-side corrections, and `M3-CP4c-0-TB-R4-REVIEW-PLAN` closed on 2026-08-26**
(`M3_CP4c_Consolidated_Record.md` §7 (retired TB-R4 review)). **This is the first cycle in which
CP4c-0's real subject is on the table.** G1–G4/G6 are runtime-proved, the frozen gate is **338/338
green**, and Q8 became creditable — and red at criterion 2.

G5 published the sphere's rejection in full for the first time. Decoding the six exact rationals:
**both faces classify the shared edge `6-8` as `Outflow`** (`d_source[2] = −1.0035…`,
`d_target[2] = −0.5770…`). A continuous direction cannot exit a shared edge from both sides, and the
magnitudes are three orders above any epsilon here, so this is **not** a tolerance artifact. The
physically correct target branch is **`3`** — two quarter-turns from the published `1` — so the lift is
off by a full reversal. The source face is a genuine `1×2`, meaning CP4c-0's min-ratio rule chose the
exit edge correctly; the transport that follows it did not.

The review **refused to guess the mechanism**. The obvious candidate — per-face canonical-normal parity,
which is mismatched on 86.8 % of the sphere's interior edges — was tested and **refuted**: the gauge is
an index shift and cancels in the subtraction regardless of frame. Two supporting assumptions were also
excluded (the raw-array reconstruction matches the stored field exactly; the stored ordering is globally
orientation-coherent). Three candidates survive — matching sign convention, matching aliasing, or a
wrong branch carried by A2a — and a single **cross-face flow-agreement census** over A1 authority
discriminates among all three. That census is measure **H1** and is the whole point of the next cycle.

**Recorded caveat:** a green accepted 316 is **not** evidence that cross-face transport is correct — no
accepted identity has ever asserted it, because E5 created that invariant in CB2.

**CB3 → TB-R3 executed that correction, and `M3-CP4c-0-TB-R3-REVIEW-PLAN` closed on 2026-08-26**
(`M3_CP4c_Consolidated_Record.md` §7 (retired TB-R3 review)). F1/F2 are runtime-proved and F6
worked — all 338 identities executed despite an early red, which is why this cycle returned a complete
picture rather than one bit. Two identities are red and **both are test-side**:

- **ordinal 333** throws `compute_edge_quantities(): DCEL consistency check failed` before the predicate
  under test runs. The fixture builds a **single-triangle** mesh, and `DCEL::check_consistency`'s
  `checkPureBoundary` rejects any face with no interior edge — so every candidate is invalid regardless
  of coordinates. The near-degenerate coordinate search is a red herring;
- **ordinal 334** is an oracle defect **originating in the reviewer's own E8 specification**.
  `FieldBranch` is **gauged per face** by `build_face_branch_frame`, so iterating one numeric label
  across four faces compares four different physical directions. The gauge model derived from source
  reproduces the observed `0, 1, 0, 3` admitted-face counts exactly.

**Production is correct at both sites** — `build_branch_transports` already corrects every lift by the
per-face gauge difference, and all three cross-face branch steps in production use it. **Amendment 7**
records that `FieldBranch` is not a portable identifier, and that a required falsifier may not assert
that a witness *fails*.

**The finding that outranks both reds:** the supplemental falsifier's passing `ASSERT_FALSE(networkBuild)`
proves **the prescribed sphere still does not publish a network**. Q8 is therefore expected to fail next
cycle even at 338/338, and nothing in the gate currently publishes the sphere's rejection code.
Measures **G4** and **G5** address both. Exact next is **`M3-CP4c-0-CB4`** under **G0–G8**, test-side only.

**`M3-CP4c-0-TB-REVIEW-PLAN` closed that adjudication on 2026-08-25**
(`M3_CP4c_Consolidated_Record.md` §7 (retired TB review)). Verdict: **neither T6 nor Q8 is at
fault, and neither is weakened.** A1 decides the **sign of a barycentric direction coordinate** with a
`double` tolerance in three separate places and publishes those verdicts as topological ownership
(carrier-set membership, vertex-sector membership), while A2a's new continuation rule decides the same
sign exactly on the same published datum. Where they disagree — the band `|d| ≤ 1e-10`, widened further
by a lossy barycentric→world→barycentric round trip — A1 hands A2a a state A2a is correct to reject.
The defect is in the CP4c-0 frozen definitions, which asserted that surviving tolerance was harmless;
five amendments were issued. **CB2 is now BUILD GREEN** at `390e65b373063c667e3c3f5e78b74ed9d859093b` after a verification-first audit found E1–E9 already present; the required selector is **338 = 316 + 12 + 10**. Exact next is **`M3-CP4c-0-TB-R2`**, artifact-only runtime. After E2–E5, T6 is *provably unreachable* from any well-formed production state.

**No budget.** Attempt and diagnostic budgets and the `DG` turn type were abolished on 2026-08-25. Workflow is `CB → TB → (red) → REVIEW+PLAN → CB`; a red TB consumes nothing and mandatorily routes to review.

---

## 4. M4–M8 — proposed checkpoint decomposition

Not yet frozen. Each milestone below is cut by the rule this project has applied since M1: **one
checkpoint carries one independently testable semantic domain.** Gate arithmetic is cumulative —
every checkpoint carries the full accepted predecessor selector plus its own frozen identities.

Each milestone opens with its own `-DEFN` planning turn. That is not ceremony: CP4's DEFN was the
turn that caught an undefined disc-proof certificate before code was written against it, and M1 paid
twice for skipping the equivalent. **A `-DEFN` turn is planning only and runs nothing.**

**A `-DEFN` turn must now also state, for each witness it names, which product stage that witness has
been *proven* to reach** — not that its files exist. CP4c's failure was exactly this omission.

### M4 — global conformity plan (`DESIGN.md` §14 M4)

Entering gate **322**.

| Checkpoint | Semantic domain | Notes |
|---|---|---|
| `M4-DEFN` | freeze the schedule product, its rejection vocabulary, its independent oracle, and witness provenance | planning only |
| `M4-CP1` | shared-rail breakpoint/side-count **schedule product** with one writer | positive + tamper |
| `M4-CP2` | **assignment positivity certificate** and typed subset-scoped infeasibility | infeasible subsets must not fail the run |
| `M4-CP3` | producers **consume** the verified schedule; target-size variation cannot change breakpoints | invariance |
| `M4-CP4` | M4 exit gate — removes the exact-torus `InvalidHardRailPairing` blocker without post-hoc pairing; work/solver bounds reported with an explicit monotone measure | cumulative |

M4 owns `G4-B002`'s three produced-witness debts.

### M5 — certificate-carrying chart and quotient relations (§14 M5)

| Checkpoint | Semantic domain |
|---|---|
| `M5-DEFN` | freeze canonical relation IDs, path certificates, and the tamper matrix |
| `M5-CP1` | canonical relation ID domain and explicit path certificates, replacing verifier-side reachability reconstruction |
| `M5-CP2` | typed failure for missing / duplicate / conflicting / nonreciprocal / representation-renumbered relations |
| `M5-CP3` | M5 exit — torus lineage and quotient acceptance from direct production evidence; unused valid relations provably do not alter the selected certificate |

M5 owns `G4-B003`'s two produced-witness debts.

### M6 — occurrence, embedding, independent verification (§14 M6)

| Checkpoint | Semantic domain |
|---|---|
| `M6-DEFN` | freeze the four stage products and the verifier's recompute boundary |
| `M6-CP1` | separate occurrence creation / quotient construction / geometry embedding as complete stage products |
| `M6-CP2` | verifier consumes certificates and independently recomputes elementary incidence; **never repairs producer state** |
| `M6-CP3` | M6 exit — equal coordinates without a relation remain distinct; every owned relation consumed exactly once; source-row / output-row / scheduler permutation invariance |

### M7 — disposition and graded degradation (§14 M7)

Sequenced after M6 by explicit design decision in `DESIGN.md` §14: disposition is a statement *about*
the verified product, so implementing it earlier reproduces the silent-substitution failure §3
diagnoses. **Do not resequence this.**

| Checkpoint | Semantic domain |
|---|---|
| `M7-DEFN` | freeze `OutputDisposition`, `DegradationCertificate`, and verifier layer 7 as one vertical contract |
| `M7-CP1` | tier assignment by the **verifier only**, never a producer; tier cannot be raised mid-run |
| `M7-CP2` | declared degraded region producer — pure quads conforming exactly to the unmodified plan, cannot mutate upstream products |
| `M7-CP3` | M7 exit — unrecorded and fabricated degradation both fail typed; omitted-region bookkeeping reconciles with quotient relation consumption; tier/degraded/omitted invariant under every §10.1 permutation; **no strict fixture gate closes on a degraded result** |

### M8 — module boundaries and operational hardening (§14 M8)

| Checkpoint | Semantic domain |
|---|---|
| `M8-CP1` | target module layout; forbidden producer/verifier dependencies made unavailable; `construction/` cannot depend on `disposition/` |
| `M8-CP2` | diagnostics, resource accounting, packaging, CI hardening; no semantic equality includes execution handles or backend choice; diagnostics cannot feed semantic decisions |
| `M8-CP3` | **production-ready exit** — every `DESIGN.md` §2.1 certified-acceptance condition met on the full witness set, and **no architecture-debt item in `Regression_Root_Cause_Tracker.md` remains open** |

`M8-CP3` is the production-readiness definition. It is not met while any of `G4-B001`–`G4-B004` is
open.

---

## 5. Open product blockers, and who owns them

These are **not** M3 obligations and must not be claimed closed by M3 evidence.

| Blocker | Stage | Owner |
|---|---|---|
| `G4-B001` / `PR8-R034` / `G4-R007` | completion/materializer — hard rail promoted into `IsolationSheetId` authority, rejected by `close_completion_lineage_source_authority(...)` | M6 at the earliest; adjudicate at `M6-DEFN` |
| `G4-B002` | rail scheduling | M4 |
| `G4-B003` | quotient/chart relations | M5 |
| `G4-B004` | unassigned | adjudicate at `M4-DEFN` |

Produced-witness debt stands at **5** and is discharged by M4 (3) and M5 (2).

---

## 6. What "production ready" means here

From `DESIGN.md` §2.1, unchanged and not restated in full: a run is production-ready when the certified
acceptance conditions hold on the full witness set with no degraded result closing a strict gate, under
the §10.1 determinism requirements, with the §15 stop conditions never triggered.

Operationally, that is `M8-CP3`. The remaining path is: **CP4c-2 → CP4c-3 → M4 (4 checkpoints) → M5 (3)
→ M6 (3) → M7 (3) → M8 (3)**, plus two CP4c `-DEFN` turns and five milestone `-DEFN` turns. Eighteen
checkpoints remain.

This decomposition is a **proposal until each milestone's `-DEFN` turn freezes it.** Gate arithmetic
beyond 322 is deliberately not fixed here — freezing identity counts before the domain is defined is
the failure `M3-CP4-DEFN` was created to prevent.
