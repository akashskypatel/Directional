# M3-CP4c-0-TB-R4 — Independent Review and Corrective Plan

Turn: `M3-CP4c-0-TB-R4-REVIEW-PLAN`. Review and planning only.
**No Directional runtime, build, benchmark, or mutation of product/test/fixture/selector/build logic
occurred.** Evidence and committed fixtures were *read* and arithmetic was done on them; nothing was
executed.

Brief: the TB-R4 review brief, retired into `M3_CP4c_Consolidated_Record.md`.
Contract: `Architecture_M3_CP4c0_DEFN_Frozen_Definitions.md` (Amendments 1–7).

---

## 0. Verdict, stated first

**This is the first cycle in which CP4c-0's real subject is on the table.** The gate is green, Q8 is
creditable for the first time, and the sphere's rejection has a name and a complete numeric payload.

1. **The required gate is GREEN: 338/338, accepted 316/316, prior 328/328, F3 2/2, G5 PASS.** G1–G4 and
   G6 are runtime-proved. The two TB-R3 test-side defects are closed.
2. **G5 did exactly what it was added to do.** For the first time the sphere's A2a rejection is
   published in full, with both faces, both branches, and all six exact derivatives. Three cycles of
   "the decisive datum was computed and discarded" are over.
3. **Q8 is RED at criterion 2, as predicted (TB-R3 review P4).** The sphere publishes no network.
4. **The symptom is proved exactly and is not marginal.** Decoding the payload: **both faces classify
   the shared edge `6-8` as `Outflow`** — `d_source[2] = −1.0035…`, `d_target[2] = −0.5770…`. A single
   continuous direction cannot exit a shared edge from both sides. The magnitudes are ~1.0 and ~0.58, so
   this is **not** a tolerance-band or near-tangency artifact. §3.
5. **The physically correct continuation is the target branch two quarter-turns away.** Negating the
   target direction (branch `1` → branch `3`) gives `d[2] = +0.5770 > 0` — `Inflow`, exactly as
   required. The published lift is off by **2**, i.e. a full reversal. §3.
6. **I could not prove the mechanism, and I am not going to guess it.** I formed a specific hypothesis
   (per-face canonical-normal parity), tested it against source and fixture, and **refuted it**. §5
   records that refutation in full so no one re-derives it. Three candidates survive, with a single
   measurement that discriminates among all of them. §6.
7. **The accepted 316 being green is not evidence that transport is correct.** No accepted identity has
   ever asserted cross-face flow agreement — that invariant did not exist until measure E5 created it.
   §7.

Corrective series **H0–H6** in §9. **No production change is authorized yet**; the first measure is a
census that decides the mechanism in one run.

---

## 1. Independent verification of the evidence — CONFIRMED

| Claim | Verified |
|---|---|
| run `32928381384`, head SHA `bb21207f288c631b1d4149b56b37e78080edade7` | ✅ |
| result artifact `9592385698` SHA-256 `6ffe56ef…70260643` | ✅ exact (API) |
| diagnostic artifact `9592386266` SHA-256 `669e51f2…5f6ac3cb` | ✅ exact (API) |
| CB4 package `9591540182`, semantic source `de291a17d5e9bfb6f54918660320ecfa1d521be4` | ✅ as recorded |
| selector **338** `d588cae0…`, 316-prefix `601ce2b6…`, 328-prefix `cf93622e…` | ✅ **recomputed locally**, all three unchanged |
| gate 338/338, F3 2/2, G5 PASS/non-gating, Q8 creditable/RED | ✅ as reported |

**R1 answer:** the semantic and integrity evidence is independently recoverable and consistent. The
`first_red` postflight naming failure is a **reporting-shell** defect that occurred *after* valid
semantic and immutability evidence existed — it changes no semantic fact. **It must not trigger a
semantic rerun**; see H6.

**R6 answer:** recorded separately as a control-plane item. Correct the variable naming in a successor
workflow; do not re-execute TB-R4 to obtain a green badge.

---

## 2. What TB-R4 proves that no previous cycle did

Worth stating plainly, because four consecutive red cycles can obscure real progress:

- **The exactification programme (E2–E5) worked.** The original CP4c-0 failure —
  `BranchContinuationDegenerateEntry` at edge `6-8` — is gone, and identity 338 confirms neither that
  code nor `BranchContinuationOutsideOutflowSet` is published on any accepted witness or the sphere.
- **The diagnostic programme (E1, F1–F3, G5) worked.** The sphere's rejection is now fully observable.
- **The execution-policy change (F6) worked.** All 338 ran, so this cycle produced a complete picture.
- **And the failure has moved from a symptom to a cause.** `BranchTransportFlowDisagreement` is the code
  measure **E5** created specifically to type this condition — the cross-edge invariant that the first
  CP4c-0 review found was *entirely unasserted*. That review named this exact possibility as **route A**:
  *"the entered face's `d[opp] < 0` — the direction points back out through the edge it just crossed."*
  **Route A is now confirmed as the live condition.**

The invariant is doing its job: it converted a silent wrong-branch continuation into a localized, typed
rejection naming both faces, both branches, and both exact directions.

---

## 3. R2/R3 — the exact edge-`6-8` state, decoded

The G5 payload, decoded from the six exact rationals (all are exact dyadics; both triples sum to
**exactly** zero, so both directions are valid `is_barycentric()` authority):

**Source face `6-8-9`, branch `3`** — canonical vertices `(6, 8, 9)`:

| index | opposite vertex | edge | exact `d` | flow |
|---|---|---|---|---|
| 0 | 6 | `8-9` | `−4.0035357904` | Outflow |
| 1 | 8 | `6-9` | `+5.0070715807` | Inflow |
| 2 | 9 | **`6-8`** | **`−1.0035357904`** | **Outflow** |

**Target face `6-8-97`, branch `1`** — canonical vertices `(6, 8, 97)`:

| index | opposite vertex | edge | exact `d` | flow |
|---|---|---|---|---|
| 0 | 6 | `8-97` | `−3.2246869293` | Outflow |
| 1 | 8 | `6-97` | `+3.8016833692` | Inflow |
| 2 | 97 | **`6-8`** | **`−0.5769964399`** | **Outflow** |

**Both faces call the shared edge `6-8` Outflow.** That is the disagreement, stated exactly.

Three consequences follow immediately:

1. **It is not a tolerance artifact.** `|d| = 1.0035` and `0.5770` are three orders of magnitude above
   any epsilon in this codebase. The "route A′" within-face tolerance explanation from the first CP4c-0
   review is **excluded**.
2. **It is not an invariant that is too strong.** A continuous direction field cannot have one direction
   exit a shared edge from both incident faces. Amendment 4 / measure E5 is correct as stated.
3. **The correct continuation is target branch `3`.** Because branch `b+2` negates the direction,
   branch `3` has `d[2] = +0.5769964399 > 0` — `Inflow`, exactly what the crossing requires. The
   published transport selected branch `1`; the physically correct one is `3`. **The lift is off by 2 —
   a full reversal, not a small rotation.**

**A detail worth recording:** the source face is a **`1×2` face** — two outflow carriers (`8-9` and
`6-8`) and one inflow (`6-9`). So CP4c-0's exact minimum-ratio rule *chose* edge `6-8` from a genuine
ambiguity, which is precisely the capability CP4c-0 exists to add. The continuation rule is working; the
transport that follows it is not.

**R3 classification: production semantic defect in cross-face branch transport authority (A1), or in the
branch the trace carries into it (A2a). Not a fixture issue, not a diagnostic false positive, not an
admissibility issue.** Which of the two, and by what mechanism, is not yet determined — see §5, §6.

---

## 4. R4 — relation to the prior exactification

**The disagreement is a downstream condition newly *exposed* by E2–E5, not a defect introduced by them,
and not a recurrence.**

- **Newly exposed, not introduced.** E5 created the check. Before CB2 nothing compared the two faces'
  flow classifications across a shared edge, so a reversed transported branch produced a
  wrong-but-plausible trace and no identity noticed. The condition is almost certainly older than
  CP4c-0.
- **Not something E2–E5 should have guaranteed.** E2 exactified *within-face* flow classification and E3
  exactified *within-fan* sector selection. Neither makes any claim about the *matching* or the composed
  lift between two faces. The cross-face invariant was added by E5 precisely because it was unowned.
- **Not a recurrence of the degenerate-entry family.** Identity 338 is green; the old codes are absent.
  Causal proof, as R4 requires: the old failure was `t* = 0` at a **vertex-entry** produced by a tolerant
  sector selection; this failure is a **flow-classification disagreement across an edge** with healthy
  magnitudes. Different condition, different site, different mechanism.

---

## 5. A hypothesis I formed, tested, and refuted — recorded so no one repeats it

The TB-R3 review flagged that `build_face_branch_frame` computes its per-face normal from the
**canonical (sorted)** vertex order, which need not preserve mesh orientation. That looked like the
obvious culprit, so I tested it.

**Fixture fact (computed from `sphere_prescribed.obj`):** the two faces sharing edge `6-8` do have
opposite canonical parity —

| mesh row | mesh order | canonical | canonical normal vs mesh orientation |
|---|---|---|---|
| 6 | `(6, 8, 9)` | `(6, 8, 9)` | **agrees** (even permutation) |
| 191 | `(97, 8, 6)` | `(6, 8, 97)` | **anti-parallel** (odd permutation) |

And the exposure is enormous — parity mismatch across an interior edge is the *norm*, not an exception:

| fixture | faces | interior edges | parity-mismatched | % |
|---|---:|---:|---:|---:|
| `sphere_prescribed` | 192 | 288 | 250 | **86.8 %** |
| `torus` | 144 | 216 | 200 | 92.6 % |
| `mechanical_feature` | 300 | 450 | 406 | 90.2 % |
| `cylinder` | 128 | 176 | 167 | 94.9 % |
| `bunny_1k_random` | 1000 | 1500 | 912 | 60.8 % |
| four-triangle fan | 4 | 4 | 2 | 50 % |

**But the hypothesis does not survive.** The gauge is an **index shift into a per-face array**, and it
cancels in the subtraction regardless of the frame in which it was chosen:

- `rawDirections = {primary, secondary, −primary, −secondary}` is indexed identically in every face;
- semantic `s` on face `F` denotes `raw_F[(g_F + s) mod 4]`;
- `matching` relates **raw indices** between the two faces;
- so the correct semantic lift is `t = s + matching + g_X − g_Y`, which is exactly `canonicalLift`.

The canonical normal affects only *which* index is chosen as `g`, and any such choice cancels. **The
composition is algebraically sound even across a parity-mismatched pair.**

Two further checks confirm the surrounding assumptions are also sound, so they can be struck off:

- **The raw-array reconstruction matches the stored field exactly.** `sphere_prescribed.rawfield` stores
  four vectors per face in the order `{v0, v1, −v0, −v1}`; `primaryDirections = extField.leftCols<3>()`
  is `v0` and `secondaryDirections = extField.middleCols<3>(3)` is `v1`. So
  `{primary, secondary, −primary, −secondary}` reproduces the stored ordering **exactly**. A
  reconstruction-order mismatch is excluded.
- **The stored ordering is globally orientation-coherent.** In **all 192** faces, `v1` is the `+90°`
  rotation of `v0` about the **mesh** normal — zero exceptions. A per-face rotational-sense
  inconsistency is excluded.

**I record this refutation deliberately.** It is the most attractive wrong answer available, the parity
statistics make it look compelling, and a future turn will otherwise re-derive it. It is wrong.

---

## 6. The surviving candidates, and the one measurement that separates them

Three candidates remain. Each has a distinct, cheap signature.

**H-A — matching sign/direction convention.** `forwardLift = raw.matching` is consumed as "rotation
taking face-1 indices to face-2 indices". If the field library's convention is the inverse, the stored
lift is `−k` where `+k` is meant. **A sign error produces a difference of exactly 2 when the true
matching is odd (`±1`) and no error at all when it is even (`0` or `2`).**
*Fit:* strong. It explains an off-by-2 exactly; it is invisible on the flat/smooth edges where matching
is `0`; and it concentrates where matching is odd — **near singularities**. Edge `6-8` is incident to
**vertex 8, which is one of the sphere's eight singularities**.
*Signature:* failures occur **exactly** on edges whose published lift is odd.

**H-B — matching aliasing.** `DESIGN.md` §4.1 records the known result (Vaxman et al.) that *principal
matching alone can alias field topology*. If the sphere's transitions are derived by principal matching,
a locally large rotation could select a wrong `k`.
*Fit:* moderate. It explains locality near singularities, but principal matching minimises rotation and
would not normally select a 180° reversal.
*Signature:* failures are sparse, clustered near singularities, and the lift values are **not**
systematically related to parity of `k`.

**H-C — the trace carries the wrong branch on arrival (A2a, not A1).** The failure is several steps from
the seed (`traceSeedVertex=0`, `traceSeedSingularity=0`; the failing faces contain vertex 8). If an
earlier step — the port attachment or a prior vertex transit — put the trace on the wrong branch, the
disagreement surfaces at the first edge where the two faces disagree, not at the site of the error.
*Fit:* live and not excludable from a single failure site.
*Signature:* the A1-only census below shows **no** violations, yet the trace still fails ⇒ the defect is
in A2a's branch bookkeeping, not in A1's published transport.

### The measurement

**A cross-face flow-agreement census, over A1 authority alone, with no tracing at all.** For every
interior edge and every branch of a witness, check the invariant in **both** directions:

> if edge `e` is in `outgoingCarriers(X, b)` then `e` must be in `incomingCarriers(Y, b′)`, where
> `b′ = b.rotated(signedLift(e, X→Y))`.

Report, per witness: total `(edge, branch)` pairs checked; violations; and for each violation the edge,
both faces, both branches, the **published lift**, and both exact `d[opp]` values.

This is decisive:

| Census result | Conclusion |
|---|---|
| violations occur exactly where the published lift is **odd** | **H-A** — sign/direction convention. Fix is one-line and global |
| violations sparse, clustered near singularities, no lift-parity pattern | **H-B** — matching aliasing. Fix belongs to field-authority scope |
| violations ≈ 50 % or uniformly distributed | a systematic index error not yet enumerated — re-open §5 with new data |
| **zero violations** | **H-C** — A1 transport is sound and the defect is in A2a's carried branch. Redirect entirely |

This is the same instrument that turned the CP4c ambiguity question from argument into fact (the 50 %
census), and it costs one non-gating identity. **It must run before any production change is
authorized.**

---

## 7. A caveat that must go into the durable record

**The accepted 316 being green does not establish that cross-face transport is correct.**

Measure E5 created the cross-edge flow-agreement check in CB2. Every one of the accepted 316 identities
was frozen *before* that invariant existed, so none of them asserts it. A reversed transported branch
would have produced a wrong-but-plausible trace, and nothing in the accepted suite could have detected
it. The parity statistics in §5 show that adjacency configurations of every kind are abundant in the
accepted witnesses too.

Concretely: **if the census returns violations at a material rate, then some accepted traces are
probably wrong** — they were simply never checked against this invariant. That would not be a regression
introduced by CP4c-0; it would be a pre-existing defect that CP4c-0's new invariant is the first thing
ever to detect. That possibility must be sized by the census, not assumed away in either direction.

---

## 8. Falsifiable predictions

- **P1.** The census returns **at least one** violation independent of tracing — namely `(6-8, branch 3,
  faces 6-8-9 / 6-8-97)`, reproducing the exact values in §3. If the census finds **zero** violations
  while the trace still fails, **H-C** is confirmed and the whole investigation moves to A2a.
- **P2.** If **H-A** holds, every violation has an **odd** published lift, and no edge with an even lift
  violates. This is a sharp, all-or-nothing signature.
- **P3.** Violations cluster on edges incident to the eight singular vertices `{0, 8, 21, 24, 25, 34, 45,
  49}`, because that is where odd matchings live.
- **P4.** The accepted witnesses (two-ring skew disc, four-triangle fan) show violations at a **lower**
  rate than the sphere — possibly zero — because their fields are flat or near-flat and their matchings
  are mostly `0`. That is the reason this survived to CP4c-0 undetected, and the census will show it.
- **P5.** The 338 gate and F3 stay green through H1–H2; they touch no production semantics.
- **P6.** Q8 stays red until the mechanism is fixed. **Do not plan the next TB as a Q8 close.**

---

## 9. Corrective measures — series **H**, one Code + Build turn (`M3-CP4c-0-CB5`)

**H0 — binding preconditions.**
Branch `agent/surface_cell_quad/p5-recover-bridge-healing`. Code + Build only; compile all eight
standard targets; **execute nothing**. **No production change is authorized by this review.** The
mechanism is undetermined and a fix chosen now would be a guess. Do not weaken T6, Q8, accepted
expectations, the sphere fixture, selector ordering, or any Amendment 1–7. Do not retune
`kBranchTopologyTolerance`. Do not enter CP4c-1/2/3 scope. The frozen 338 selector and all three hashes
stay unchanged.

**H1 — the cross-face flow-agreement census (§6).** *The one measure that matters this cycle.*
Add a **non-gating diagnostic identity** that, for each of the two-ring fixture, the four-triangle fan,
the prescribed sphere, and the torus, iterates **every interior edge × every branch** and checks the
invariant in **both** directions using A1 authority only — no tracing.
Report per witness: pairs checked, violation count and rate, and for each violation: the edge, both
face keys, both branches, **the published `signedLift`**, and both exact `d[opp]` values through
`exact_rational_locus`. Follow Amendment 6 (named `*_locus` formatters, printable ASCII) and Amendment 7
(never compare bare branch labels across faces — always apply the lift).
**It must report on success as well as failure**, so a zero-violation result is recorded rather than
inferred from silence. Non-gating: excluded from the 338 count, no credit, with a written rationale and
this measure as owner.

**H2 — publish the published lift alongside every disagreement.**
Extend `BranchTransportFlowDisagreement`'s payload with the **`signedLift` actually used**. The current
payload names both branches, from which the lift is inferable — but P2's discriminator is a statement
about the lift, and an inferred value is not evidence. Update the DEFN §10 required-loci row.

**H3 — publish the trace's step history on a tracing failure.**
To separate **H-C** from **H-A/H-B**, the failure must carry how the trace reached the failing state:
the ordered sequence of `(sourceFace, branch, incomingCarrier, exact entry parameter)` for each step, or
a bounded tail of it. Without this, a wrong branch introduced three steps earlier is indistinguishable
from a wrong lift at the failing edge. Non-gating diagnostic output is acceptable; it need not enter the
error type.

**H4 — record the matching provenance for the census witnesses.**
State, in the CB report, whether each witness's `edgeTransitions` are **loaded** from the fixture or
**computed** by principal matching at load, and which code path produces `CrossFieldEdgeTransition::matching`.
**H-B is only live if matching is computed.** This is a source-audit item, not a code change, and it
converts a hypothesis into a fact for free.

**H5 — do not change production.** Explicitly a measure, because the temptation is high and the fix
looks like one line. A sign flip applied on the strength of a single failure site, with the census
unrun, would be a **fixture-shaped guess at global authority**. If the census confirms H-A, the
correction is small, global, and independently falsifiable — and it will be authorized then, on
evidence.

**H6 — control-plane correction, no semantic rerun.**
Correct the postflight `first_red` / `first_red_ordinal` variable naming in the successor workflow.
**Do not rerun TB-R4 semantics to obtain a green badge** — the semantic and integrity evidence is valid
and complete, and the naming defect occurred strictly after it.

**H7 — successor TB-R5 plan.**
Rerun the unchanged 338 selector in exact order, fresh processes, F6 continue-and-observe; then F3's two
supplementals; then the G5 and H1 non-gating diagnostics, reported and uncredited. Q8 becomes creditable
only at exact package integrity, 338/338, and supplemental 2/2. **State in the plan that Q8 is expected
to remain red (P6)** and that this cycle's deliverable is the census verdict, not a Q8 close.

---

## 10. Risk register

| # | Risk | Mitigation |
|---|---|---|
| 1 | A one-line sign flip is applied on the strength of one failure site | **H5** prohibits it. The census is cheap and decides it. A wrong global flip would silently corrupt every accepted trace |
| 2 | Census returns zero violations and the review looks wrong | That is **P1's** alternative branch and it is a *result*, not a failure: it proves **H-C** and redirects to A2a. The census is informative either way |
| 3 | The 86.8 % parity statistic is mistaken for the mechanism | §5 refutes it explicitly and records why, precisely so this does not happen |
| 4 | Census finds violations in accepted witnesses ⇒ pressure to suppress | §7: that would be a pre-existing defect newly detected, not a CP4c-0 regression. Size it, record it, do not weaken the invariant |
| 5 | Q8 red read as CP4c-0 stalling | It is the opposite: the subject is finally visible. §2 lists four programmes that demonstrably worked this cycle |
| 6 | `first_red` naming defect triggers a semantic rerun | **H6** prohibits it; the semantic evidence is valid and complete |

---

## 11. Review record

- **R1:** evidence independently verified; all digests and all three selector hashes match, the latter
  recomputed locally. The `first_red` postflight defect is control-plane only and post-semantic.
- **R2:** edge-`6-8` state reconstructed exactly from the G5 payload. **Both faces classify the shared
  edge as Outflow** (`−1.0035…` and `−0.5770…`); the physically correct target branch is `3`, two
  quarter-turns from the published `1`. The source face is a genuine `1×2`, so CP4c-0's min-ratio rule
  chose the exit edge correctly. **Confidence: high** — arithmetic on the published exact rationals.
- **R3:** production semantic defect in cross-face branch transport (A1) **or** in the branch A2a
  carries into it. Not fixture, not diagnostic false positive, not tolerance. **Mechanism
  undetermined — deliberately not guessed.**
- **R4:** newly *exposed* by E5, not introduced by E2–E5, and not a recurrence; causal argument in §4.
- **R5:** Q8 criterion 2 correctly red. Minimum successor frozen as **H0–H7**, whose centre is a
  census, not a correction.
- **R6:** control-plane naming defect recorded; no semantic rerun.
- **Hypothesis refuted and recorded:** per-face canonical-normal parity (§5), together with two
  supporting exclusions (raw-array reconstruction order; global rotational coherence of the stored
  field).
- **Durable caveat added:** a green accepted 316 is **not** evidence that cross-face transport is
  correct — no accepted identity has ever asserted it (§7).
- **Stable accounting:** unchanged at **42 events / 14 categories / 28 recurrences**; produced-witness
  debt **5**. `M3-CP4c0-TB-R4-CAND-01` remains ACTIVE/NON-STABLE with its root cause narrowed to three
  candidates and a decisive test. `CAND-02` is resolved control-plane and is not conflated with Q8.
- **Successor:** `M3-CP4c-0-CB5`, measures **H0–H7**, Code + Build only, **diagnostic-only — no
  production semantics change**.
- **Mutation statement:** this review executed no runtime, build, or benchmark, and changed no product
  source, test source, fixture, selector, or build configuration. Fixtures were read and arithmetic was
  performed on their contents; they were not modified. Its only writes are to durable documentation
  under `.agents/Directional/`.
