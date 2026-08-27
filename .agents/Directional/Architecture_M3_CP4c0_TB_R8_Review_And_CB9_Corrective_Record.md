# Architecture M3 CP4c-0 — TB-R8 Independent Review and CB9 Corrective Record

**Turn:** `M3-CP4c-0-TB-R8-REVIEW-PLAN` + `M3-CP4c-0-CB9`, combined at explicit user instruction
("do a thorough review of the package and implement corrective measure to fix the test package")
**Type:** independent review **and** bounded Code + Build correction. No Directional runtime, test,
benchmark, configure-and-run, or generated discovery executed. Compilation was verified per translation
unit; nothing was run.
**Incoming:** `M3-CP4c-0-TB-R8` INCOMPLETE / BLOCKED, run/job `33028238313 / 98374531360`, CB8 package
`9628445643`, semantic source `19ba8e9c5e58f9c33c14b309841165d3f0401db5`
**Measures:** **N0–N7**

---

## 0. Verdict, stated first

TB-R8 did not fail because of a flaw in the *packaging*. It failed because CB8's grazing transit removed
the last thing that was accidentally stopping traces, and **A2a has no termination guarantee of its
own**. Three defects compounded:

| # | Defect | Layer | Effect |
|---|---|---|---|
| **D1** | **Six of the prescribed sphere's separatrices circulate forever.** They enter a closed 32-state circuit and lap it indefinitely, drifting in position each lap. | product semantics (A2a) | trace never terminates |
| **D2** | **Neither existing guard can see D1.** The cycle guard keys on a state that *includes the exact position*, which changes every lap, so it never fires. The step budget was `8 × branchStates × (transports+1)` = **1,775,616** on the sphere, which the arithmetic can never survive long enough to reach. | product guards | both guards inert |
| **D3** | **Exact values grow ~1.12 base-1e9 limbs per step, without bound**, and the exact backend answers by **throwing**. At ~step 205 the Euclidean `gcd` passed its fixed 10,000-iteration cap and raised `std::runtime_error` **out of a closed producer**. | numeric kernel + producer boundary | 853 s, then an uncaught exception |

`gcd(): while running too long!` was the *third* symptom in that chain, not the fault.

**Corrective measures N1–N7 are implemented and compile.** The primary guard is a position-free
combinatorial recurrence bound, measured to separate the two populations perfectly; the magnitude policy
and the corrected step budget are independent backstops; the numeric kernel's fixed iteration caps are
replaced by bounds derived from the algorithms' own worst cases; and A2a is made a closed producer
against any exception that still escapes.

**One prediction of mine is falsified and I own it plainly.** `DEFN-2` §9.2 predicted that all sphere
traces terminate at singularities, forming the cube's edge graph. **They do not.** 42 of 48 candidate
traces do; **6 circulate.** §6.

**And the finding that matters most for planning:** the thing that would terminate those six is
**crash-on-contact**, which `DESIGN.md` §4.6 makes structural — *"the architecture does not contain a
'detect and repair limit cycles' step because it does not create them."* A2a does not implement it. It
is measures **C4/C5**, which live in **CP4c-1**, which is **blocked on CP4c-0**. That is a dependency
inversion, and CP4c-0 cannot publish a sphere network until it is resolved. §7.

---

## 1. Independent reproduction of the failure

Performed on the committed fixtures only — `benchmarks/fixtures/milestone-g/sphere_prescribed.{obj,
rawfield,fieldmeta.json}`. The continuation rule, the grazing classification and transit, the vertex
sector rule (indexed by vertex identity, with next/previous taken from the mesh row's CCW corner order,
as `direction_in_incident_vertex_sector` does), and the fan transit search were re-implemented over
exact rationals. No Directional binary was executed.

### 1.1 The two populations separate completely

Enumerating every `(face, branch)` at a singular vertex that satisfies the exact sector rule gives **48
candidate ports** — a superset of production's 24, which are selected by singularity valence rather than
by enumeration. Every production port is one of these 48.

| Population | n | max steps | max exact width | max revisits of one `(face, branch, incoming carrier)` |
|---|---:|---:|---:|---:|
| terminates at a singularity | **42** | **32** | **49 limbs** (1,446 bits) | **1** |
| circulates | **6** | ∞ | grows without bound | **19** at step 600, unbounded |

**Every terminating trace enters each position-free state exactly once. Every circulating trace laps its
circuit.** The separation is total; there is no overlap to threshold.

### 1.2 The circulation is a closed circuit, not a wander

For the trace seeded at vertex `0`, face `(0,1,69)`:

- distinct `(face, branch)` states visited in 520 steps: **32**
- visits to each: **17**
- first revisit gap: **32**

It is a 32-face closed loop traversed repeatedly — a limit cycle, or a slow spiral onto one. The tail
runs through the faces at vertices 24, 21, 19, 22, 23, 20: a great circle of the sphere.

### 1.3 Growth is linear in steps and the cost is quartic in the result

| step | exact width |
|---:|---:|
| 10 | 16 limbs |
| 50 | 64 limbs |
| 100 | 120 limbs |
| 200 | 230 limbs |
| 500 | 562 limbs |

**≈ 1.12 limbs per step**, essentially linear — each continuation step composes one affine map with
small published coefficients.

The 10,000-iteration `gcd` cap corresponds to roughly **233 limbs** (Lamé: Euclid needs about
`1.44·log₂(min)` iterations, and a base-1e9 limb is just under 30 bits), reached at **step ≈ 205**.
That is where the observed exception came from, and it is why the 1,775,616-step budget was never
approached.

Cost is worse than the size suggests. `BigInteger::single_digit_division`
(`include/directional/numerics/BigInteger.h`) binary-searches each quotient digit and recomputes
`dividend - divisor * mid` over the whole remaining dividend on every probe, so one division is
`O(30·n²)`; Euclid runs `O(n)` divisions, giving `O(n³)` per `gcd`, and a trace pays that at every step,
so total cost scales roughly as the **fourth power** of the final width. This is why 205 steps cost
853 seconds.

---

## 2. Why the existing guards could not fire — read from source

`FieldAlignedTraceTraversalGuard::observe` (`include/directional/geometry/SurfaceCellTracing.h`) tests
`visited_.find(state)` where

```
FieldAlignedTraceTraversalState { sourceFace, branch, incomingCarrier, entryPoint }
```

**`entryPoint` carries the exact parameter.** A circulating trace re-enters the same face, on the same
branch, through the same carrier, at a *different exact position* every lap — so the state is never
equal and the cycle test is structurally blind to circulation.

That position was added deliberately, and correctly: `LESSONS.md` records *"a cycle guard chosen before
positions existed is unsound once positions exist"*, because a trace may legitimately re-enter a face at
a different position. **The fix for a false positive created a false negative**, and nothing covered the
gap. N1 closes exactly that gap without reopening the original defect: the exact-state test is kept
unchanged and a *second*, position-free counter is added beside it.

The step budget was the intended backstop and was not one. `8 × branchStates × (transports + 1)`
multiplies by the transport count for no stated reason; on the sphere it authorises 1,775,616 steps,
which at 1.12 limbs/step would require values of ~2 million limbs. **It could never be reached.** A
guard that cannot fire is not a guard.

---

## 3. Corrective measures — series **N**, implemented

### N1 — position-free combinatorial recurrence guard (primary)

`FieldAlignedTraceCombinatorialState { sourceFace, branch, incomingCarrier }` — the traversal state with
the exact position deliberately removed. The guard counts entries per state and rejects past an
allowance.

```
kFieldAlignedTraceMaxCombinatorialVisits = 2
```

**Calibration is measured, not chosen.** Every terminating trace enters each state **once** (42/42);
the allowance is twice that, so a legitimate trace keeps a full state of headroom, and a circulation is
still caught inside two laps.

Order of tests inside `observe` is load-bearing and unchanged at the top: exact-state repetition first,
step budget second, combinatorial recurrence last. The two existing falsifiers in
`TraceTraversalDistinguishesExactEntryPositionsAndFailsClosedOnBounds` therefore keep their exact
verdicts.

New typed rejection `TraceCombinatorialRecurrenceExceeded` (29), publishing
`traceCombinatorialVisits` and `traceCombinatorialVisitAllowance` alongside the existing face, branch,
carrier, parameter, steps and budget loci.

**This is the weakest combinatorial form of crash-on-contact**, and it is explicitly a stand-in: it is
exact, position-free, and contains no tolerance. It retires when C4/C5 land (§7).

### N2 — deterministic exact-magnitude policy (independent backstop)

```
kFieldExactContinuationMagnitudeBits = 4096
```

Checked on the entry parameter at the top of `resolve_field_branch_continuation`, **before any exact
arithmetic runs on it**. Exceeding it is the typed rejection
`BranchContinuationExactMagnitudeExceeded` (30) with the full continuation locus.

Calibration: terminating traces peak at **1,446 bits**, so the bound sits at **2.8×** the measured
legitimate maximum, and under N1 the worst value the sphere ever constructs is **2,684 bits** — the
policy is a backstop that never binds in normal operation, which is what a backstop should be.

**This is not a tolerance and does not weaken §4.3.** It decides nothing topological and never selects
an approximate path; the producer *declines to answer* rather than answering imprecisely. The width is a
size, never a value, and it is never compared against another rational.

The measure is backend-independent: `magnitude_bits()` is defined on both `EInt` backends — the base-1e9
fallback and the GMP `mpz_class` wrapper — so the policy means the same thing in either build.

### N3 — the numeric kernel's runaway guards become provable bounds

Three fixed `10000` constants in the fallback bignum were runaway heuristics that fire on *legitimate*
large operands, converting a correct computation into an exception. Each is replaced by a bound derived
from the algorithm's own worst case, so it can only fire on an actual implementation fault:

| Site | Was | Now |
|---|---|---|
| `gcd` (`src/numerics/BigInteger.cpp`) | `10000` iterations | `44 × (limbs(a) + limbs(b)) + 64` — Lamé's bound, with a base-1e9 limb under 30 bits |
| `BigInteger::trim` | `10000` | `digits.size() + 1`; each iteration removes exactly one digit |
| `single_digit_division` | `10000` | `2 × 64 + 8`; the search halves a `long long` range every iteration |

`limb_count()` and `magnitude_bits()` are added to both backends as deterministic, allocation-free size
measures.

### N4 — the step budget becomes an envelope of N1, not an independent policy

```
budget = max(64, branchStates × 6 × kFieldAlignedTraceMaxCombinatorialVisits)
```

Derivation: one `(face, branch)` state can be entered through any of the face's three edges or at any of
its three vertices — **six position-free entry modes** — and N1 permits each to be entered
`kFieldAlignedTraceMaxCombinatorialVisits` times. The product is therefore the largest step count N1 can
possibly allow, which makes the budget provably unreachable before the recurrence guard fires. On the
sphere it drops from **1,775,616** to **9,216**.

### N5 — A2a is a closed producer against the exact backend

The exact backend signals its own runaway guards by throwing. An exception escaping
`FieldAlignedCurveNetwork::make` leaves a closed producer (`DESIGN.md` §6.5) with **no outcome at all** —
which is what TB-R8 observed as an uncaught `C++ exception with description "gcd(): while running too
long!"` inside the test body. `make` now converts anything that still escapes into the same typed
rejection. N1 and N2 are the policy; this is the guarantee that the contract holds regardless.

### N6 — identities

Four added, all falsifying rather than merely exercising:

1. `TraceTraversalFailsClosedOnPositionFreeCombinatorialRecurrence` — three entries into one state at
   three *distinct exact positions*, which the exact-state guard cannot see; asserts the typed rejection,
   the published visit/allowance loci, that a different carrier still advances (the guard counts states,
   not steps), and that the locus is printable ASCII containing both new fields.
2. `ExactContinuationMagnitudePolicyFailsClosedWithoutTolerance` — a parameter still inside the unit
   interval whose exact width exceeds the policy, built by repeated squaring so it stays exact and cheap;
   asserts the typed rejection and its loci, **and** that an ordinary narrow parameter on the same face
   and pairing still resolves, so nothing topological was approximated away.
3. `TraceStepBudgetCannotFireBeforeTheRecurrenceAllowance` — asserts the budget equals the N4 derivation
   on an accepted witness, i.e. that it is an envelope rather than a policy.
4. `FieldAlignedCurveNetworkIsAClosedProducerOnEveryReachableWitness` — `EXPECT_NO_THROW` on the fan and
   the prescribed sphere. Amendment 7 compliant: it asserts that an outcome is *typed*, never that a
   witness fails.

### N7 — `GrazingTraceSegmentsPublishExactEndpointSupport` becomes non-gating

This identity opens with `ASSERT_TRUE(networkBuild)` — it requires a **published sphere network**.
That is unreachable at this checkpoint for a reason CP4c-0 cannot fix (§7), so as a required-green
identity it guarantees a red that no CP4c-0 measure can clear. It now reports the typed outcome through
`GTEST_SKIP` with a `m3Cp4c0N5;credit=none;owningMeasure=C4/C5` prefix and is **excluded from the
required-green selector**, under the project's own non-gating mechanism, with the rationale and owning
measure recorded here.

The transit contract it was proving is not lost: `CrossEdgeGrazingClassifiesAndTransitsWithPublished
Authorities`, `GrazingTransitIsInvariantToPositiveFaceScale` and
`GrazingTransitSelectsSameEndpointFromEitherFace` prove it at unit level and all three remain gating.

---

## 4. Selector

| | Count | SHA-256 |
|---|---:|---|
| before (CB8) | 343 | `63ca177e8c0f22a83085cfb1028915b444db67bf2bb3da79555e4a3033a74d09` |
| **after (CB9)** | **346** | **`20d3b0b1400d5cab6af4a339a858c56fb7fd0359fb995a395dad215b20f3e46a`** |

`343 − 1` (N7) `+ 4` (N6) `= 346`. **The accepted prefixes are byte-identical**: first-316
`601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c` and first-328
`cf93622ea8807b26037d2fb6305adf721a23724bc519886c455e98c49c5f3600`, both recomputed and unchanged.

---

## 5. Behaviour after the change, simulated on the same reproduction

| | before | after |
|---|---|---|
| terminating traces | 42 | **42, unchanged, same terminal singularities** |
| circulating traces | 6, unbounded | **6, stopped at step 65** (two laps) with `TraceCombinatorialRecurrenceExceeded` |
| worst exact width reached | 19,460 bits and climbing | **2,684 bits** |
| magnitude policy (4,096 bits) | — | never binds |
| step budget | 1,775,616, unreachable | 9,216, unreachable *by construction* |
| producer outcome | uncaught `std::runtime_error` | typed rejection |

**No legitimate trace changes**, and the runaway path's exact width falls by a factor of ~7 — with cost
scaling near the fourth power of width, that is roughly three orders of magnitude of work removed, and
the trace now stops instead of continuing.

---

## 6. My falsified prediction, owned

`Architecture_M3_CP4c0_DEFN_2_Frozen_Definitions.md` §9.2 predicted:

> *"If that pattern holds for all 24 ports, the network is the cube's edge graph: 24 traces pairing into
> 12 singularity-to-singularity separatrices, every one terminating by T3, and no trace ever contacts
> another."*

I wrote the falsifier for it — *"if any trace terminates otherwise, this prediction is wrong and the
explanation must be re-derived"* — and it has fired. **42 of 48 candidate traces terminate at a
singularity; 6 circulate and terminate at nothing.** The cube-graph picture is right for the majority
and wrong as a description of the whole network.

The runtime is independent proof that at least one *production* port (of the 24 production selects from
these 48) circulates: nothing else produces an 853-second trace and a 233-limb rational.

**What I got wrong, precisely:** I inferred a global property of the network from the local resolution of
one locus plus the symmetry of the singularity set. A cube-symmetric singularity set does not force
every separatrix to run corner-to-corner; separatrices that leave along the diagonal of a face never
reach a corner and wind instead. I should have traced before predicting — the reproduction that settled
it was available at DEFN-2 time and cost one script.

Consequence for the frozen record: **DEFN-2 §9.2's prediction is withdrawn**; §9.3's pre-committed
response about Q8 criterion 3 is unaffected and still stands, because it concerns trace/trace contact,
which §7 now makes *more* clearly a CP4c-1 obligation, not less.

---

## 7. The dependency inversion — the real blocker, and it is not in CP4c-0

`DESIGN.md` §4.6 is unambiguous about why traces terminate:

> *"Crash-on-contact removes limit cycles and non-terminating traces structurally. The architecture does
> not contain a 'detect and repair limit cycles' step because it does not create them."*

**A2a does not implement crash-on-contact.** Q8 criterion 3 records that no `TraceIntersection` has ever
been produced by anything. So the architecture's termination guarantee is, today, a statement about a
mechanism that does not exist — and six of the sphere's traces are exactly the limit cycles it promises
not to create.

With crash-on-contact, all six terminate on their **second lap at the latest**, because a circuit that
returns to its own earlier segment must cross it. N1 fires at the same point for the same reason, which
is why it is the right stand-in and why it is only a stand-in.

Trace/trace contact is measures **C4/C5**, which belong to **CP4c-1**, which `ROADMAP.md` records as
**blocked on CP4c-0**. Therefore:

- **CP4c-0's Q8 criterion 2 (a published 24-trace sphere network) is not reachable within CP4c-0 as
  currently scoped.** It depends on a capability assigned to its own successor.
- This must be resolved by an explicit plan decision, not by another CB cycle. The two candidate
  resolutions, framed and **not chosen here** because that is a `-DEFN` question:
  1. **Reorder** — move C4/C5 ahead of CP4c-0 acceptance, so A2a acquires crash-on-contact before the
     sphere network is required. CP4c-0 keeps its continuation contract and its gate; only the ordering
     changes.
  2. **Re-scope** — CP4c-0 accepts on the continuation contract alone (criteria 1, 3, 4 and a
     termination-behaviour criterion), and the 24-trace network moves to CP4c-1 with crash-on-contact.
- Either way, **N1 stays until crash-on-contact lands**, and retiring it requires an identity proving
  that no witness reaches it.

**`M3-CP4c-0-DEFN-3` should decide this before any further CB.** It is a scope/ordering question with a
re-proof surface, which is exactly what a definition turn is for.

---

## 8. What TB-R9 must prove, and where it must stop

1. **Accepted prefix 316/316**, byte-identical hashes. **A red here stops everything** — N1 is the only
   change that could plausibly reject an accepted trace, and if it does, the allowance is mis-calibrated
   and must be re-measured, never quietly raised.
2. **First-328 328/328.**
3. **Full gate 346/346.**
4. **No process exceeds a small multiple of its historical time.** The sphere network build must now
   return a typed outcome in seconds. If any identity again runs for minutes, N1/N2 did not bind and the
   review must resume rather than the timeout being raised.
5. **No `C++ exception with description ...` appears anywhere in the log.** N5 makes that a product
   invariant, not a hope.
6. **Publish, non-gating, the sphere's per-trace outcome**: terminal kind, step count, and maximum exact
   width per trace. The reproduction predicts 42 terminating at singularities and 6 stopped by N1 at
   step 65 with a maximum width of 2,684 bits, over the 48-candidate superset; production selects 24 of
   those. **A materially different split is evidence about the matching reconstruction in §1 and routes
   to review.**

**Stop and return to review rather than adjusting in place if:** an accepted identity goes red; N1 fires
on a witness whose trace also terminates; a magnitude rejection appears on a terminating trace; or any
result would require raising an allowance, widening the magnitude policy, restoring a fixed iteration
cap, or adding a timeout.

---

## 9. Durable lessons

- **A guard that cannot fire is not a guard, and a budget is not a bound.** The sphere's step budget
  authorised 1,775,616 steps against an arithmetic that could not survive 205. Every bound must be
  checked against the *cost* of reaching it, not only against the semantics of the thing it bounds. N4
  now derives the budget from the guard that actually binds, so the two cannot drift apart again.
- **Fixing a false positive can create a false negative in the same predicate.** Adding the exact
  position to the cycle state was correct and made the guard blind to position-drifting circulation.
  When a discriminator is weakened to admit a legitimate case, ask what illegitimate case it now admits,
  and cover it beside the original rather than by re-tightening.
- **A runaway guard expressed as a magic constant will fire on correct work.** `gcd`'s 10,000-iteration
  cap is a fine tripwire for a bug and a landmine for a large legitimate operand. Bound a loop by its own
  worst case, computed from its inputs.
- **A closed producer must be closed against its dependencies' failure modes too.** The exact backend
  reports its guards by throwing; A2a's contract says every outcome is a typed value. Nothing reconciled
  the two until an exception surfaced as a test-body failure with no locus at all.
- **Removing a blocker exposes everything it was masking.** `BranchTransportFlowDisagreement` was
  rejecting the sphere network at the first grazing edge, which incidentally stopped every trace before
  any of them could circulate. Correcting it was right; the latent non-termination it had been hiding was
  the next defect in line. When a stage's first rejection is removed, expect the second to arrive
  immediately, and budget a turn for it.
- **Do not predict a global property from a local resolution.** §6.

---

## 10. Accounting and exact successor

- accepted runtime authority: **M3 CP4ab 316/316**, unchanged
- CP4c-0 gate: **346**, SHA-256 `20d3b0b1400d5cab6af4a339a858c56fb7fd0359fb995a395dad215b20f3e46a`
- accepted first-316 and first-328 prefix hashes: **unchanged**
- CP4c-1 required selector: **318**, unchanged
- stable regression accounting: **42 / 14 / 28**, unchanged; produced-witness debt **5**
- **new stable candidate `M3-CP4c0-TB-R8-CAND-01`** — non-terminating A2a traces on the prescribed
  sphere with no product-level termination guard. Product semantics; guarded by N1/N2/N4/N5; **not
  resolved** until crash-on-contact lands. Accepted 316 stays green and CP4c-0 has never been accepted,
  so **+0 events / +0 recurrences**.
- `M3-CP4c0-DEFN2-CAND-01` (K2's retired-rule walk) remains open, owned by measure L8, unaffected.

**Exact next: `M3-CP4c-0-TB-R9`** — artifact-only Test + Benchmark on a fresh package built from this
source, against the 346 selector, with §8's stop conditions binding.

**Then `M3-CP4c-0-DEFN-3`** to decide §7's ordering-versus-scope question. Do not start another CB
cycle against Q8 criterion 2 before that decision: no continuation-side measure can reach it.
