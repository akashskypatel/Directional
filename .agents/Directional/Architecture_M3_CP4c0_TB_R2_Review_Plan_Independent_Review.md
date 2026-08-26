# M3-CP4c-0-TB-R2 — Independent Review and Corrective Plan

Turn: `M3-CP4c-0-TB-R2-REVIEW-PLAN`. Review and planning only.
**No product source, test source, fixture, selector, build configuration, or runtime was modified or
executed in this turn.**

Evidence under review: the CB2 build and TB-R2 reports, retired into
`M3_CP4c_Consolidated_Record.md` §3.
Contract under review: `Architecture_M3_CP4c0_DEFN_Frozen_Definitions.md` (as amended) and the **E0–E10**
series in `Architecture_M3_CP4c0_TB_Review_Plan_Independent_Review.md`.

---

## 0. Verdict, stated first

**The brief asks whether identity 329's failure is solely the `std::uint8_t` diagnostic-formatting defect
or exposes a broader frozen diagnostic-authority issue. The answer is: both, and the broader issue is the
more important one.**

1. **For identity 329 specifically, the cause is solely the `std::uint8_t` defect, at exactly two call
   sites.** I audited every token the identity asserts against the emitter and the exact-rational
   backend; `branch=` and `relatedBranch=` are the only two that can fail. This is established
   statically, not inferred. §3.
2. **The broader issue is real and is mine.** DEFN §10 Amendment 5 required loci to be "observable"
   without ever defining what an observable locus *is*. Nothing therefore prevented one locus from being
   emitted by raw stream insertion of a typed accessor while every other locus went through a named
   `*_locus` formatter — and nothing noticed that **the correct idiom already existed in this very
   subsystem** (`FieldTransportAtlas.cpp:673` casts to `int`). §4.
3. **A second, independent defect of the same shape survives, and the E-series is why.** E1c named
   *one line* — `SurfaceCellTracing.cpp:818-819` — instead of a class. CB honoured it exactly, and
   **roughly fifteen other emission sites in the same file still back-fill `error.sourceVertex` from the
   trace seed**, which is precisely what Amendment 5 rule 1 prohibits and precisely what cost the
   TB-R1 review a turn. §5.
4. **The `uint8_t` defect very nearly defeated E1's entire purpose**, for a reason no one has recorded:
   `FieldBranch::from_integer(0)` emits a **NUL byte**, `branch` is emitted *before* `parameter`, and
   `parameter` is the single datum that discriminates the sphere's failure route. §6.
5. **CB2's E1–E9 verification claim is accurate.** I re-verified all nine independently against the
   packaged source rather than trusting the report, and confirmed the audited working tree is
   byte-identical to the packaged semantic source. §2.
6. **Identities 330 and 332–337 will pass once the two call sites are fixed** — established by static
   audit and, for 334, by exact hand computation. **338 and Q8 remain the open questions.** §7.

Both defects found in this cycle are **class defects certified by instance falsifiers**. That is the
lesson of the turn and it drives measure **F3**. Corrective series **F0–F8** in §10.

---

## 1. Independent verification of the evidence — CONFIRMED, with one recording gap

Re-verified against the GitHub REST API and against git during this turn, not taken from the reports.

| Claim | Verified |
|---|---|
| TB-R2 run `32914546494`, head SHA `26c55d13b7449953f27a4e8bd36e3c5b474f00d9` | ✅ |
| result artifact `9587747391` SHA-256 `89d72a42b07bb879f2ba35b18b3771359d522e3c0f444e33e79ce0214d8fc5a3` | ✅ exact |
| log artifact `9587747654` SHA-256 `2b43c3bda84edffe7ea23cd9763fa3c96858285b785624102f202d4e72479dab` | ✅ exact |
| CB2 compile run `32909482352`, package `9586196535` SHA-256 `9f74856149909bc1fbcaffe638fd64b4719cddcb8ed8d92972dd52289362003f` | ✅ exact |
| CB2 log artifact `9586197038` SHA-256 `7c3e56dbdea97b318bbfe10f11c48679293838fcf1f6f94cd66793302f986e2b` | ✅ exact |
| selector = **338** unique identities, SHA-256 `d588cae09067de6914aa1cb917716b11bae01e9f3b45910dbe0faa7d0c7a8116` | ✅ recomputed locally |
| accepted 316-prefix SHA-256 `601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c` | ✅ recomputed locally — **byte-identical to the accepted authority** |
| ordinals 329–338 are the ten `ResolvedBranchCorrection.*` identities, in the reported order | ✅ read from the selector tail |
| semantic source `390e65b373063c667e3c3f5e78b74ed9d859093b` exists, is an ancestor of `HEAD` | ✅ |

**A check worth stating explicitly, because it underwrites everything in §2:** the four files this review
audits — `src/authority/FieldTransportAtlas.cpp`, `src/geometry/SurfaceCellTracing.cpp`,
`tests/FieldAlignedCurveNetworkTests.cpp`, and the selector — are **byte-identical (SHA-256) between my
working tree and the packaged semantic source `390e65b3`**. My source findings are findings about the
immutable package, not about later drift.

**One structural check the reports did not make.** The always-red observability probe
`GlobalTopologyPlan.SpherePrescribedWitnessStageReachabilityIsObservable` contains an unconditional
`FAIL()`. I confirmed it is **not** in the 338 selector. The gate is therefore achievable; had it been
included, 338/338 could never go green. Recording this closes a question no prior turn answered.

### Finding 1a — the CB2 report omits its control SHA (minor, but fix it)

CB2 declares semantic source `390e65b3…`, but run `32909482352` reports `head_sha =
bd4ddf26296c72f3796d6d3f5d1a26c244620a1e`. These differ, and the CB2 report does not reconcile them.

They are reconcilable and nothing is wrong: `bd4ddf26` is *"chore: trigger M3 CP4c0 CB2 compile"*,
committed twelve minutes after `390e65b3` — it is the **control/trigger** commit, exactly the
distinction TB-R1 and TB-R2 both record explicitly as "event/control SHA". **CB2 is the only report in
this sequence that omits it**, so a reviewer must reconstruct it from commit timestamps to verify the
package's provenance. Measure **F7**.

### Finding 1b — retry 0 is correctly characterized

Retry 0 (`32914435964 / 98015089869`) is described as orchestration-only: it verified package, source and
selector, executed identity 1 successfully, then stopped because a temporary shell helper returned the
status of its final bookkeeping predicate. That is a shell-semantics defect in the harness, not a
semantic result, and the diagnosed retry changed only the helper's return. **Accepted.** It is the same
class as TB-R1's retry 0 and confirms the policy is working as intended: an orchestration defect costs a
rerun, not semantic authority.

---

## 2. Independent re-verification of E1–E9 — CB2's claim is accurate

CB2 reports that E1–E9 were "already present" at `390e65b3` and that it performed E10 only. That is an
unusual claim and this review does not accept it on assertion. I verified each measure against the
packaged source myself.

| Measure | Verified at | Result |
|---|---|---|
| **E1a** loci emitted | `tests/FieldAlignedCurveNetworkTests.cpp` `append_network_error` | ✅ emits `sourceFace`, `relatedSourceFace`, `branch`, `relatedBranch`, `parameter`, `exactValues`, `publishedEdges`, `publishedFaces`, plus E6's `traceSteps`/`traceStepBudget` |
| **E1a** losslessness | `exact_rational_locus` = `numerator_string() + "/" + denominator_string()` | ✅ lossless; GMP `mpq_class` canonicalizes, so `1/3`, `0/1`, `-1/1` are well-defined |
| **E1b** sector candidates | `publishedFaces` emitted, incl. the empty-set special case for `VertexTransitSectorUnresolved` | ✅ |
| **E1c** seed separation | `annotate_field_aligned_trace_seed` sets **only** `traceSeedVertex`/`traceSeedSingularity` | ✅ at the sites E1c named — **but see §5** |
| **E2** exact flow classification | `FieldTransportAtlas.cpp:162-172` | ✅ compares `exactDirection[opposite[index]]` against exact zero; the `double`/`τ` comparison is gone |
| **E3** exact sector rule | `FieldTransportAtlas.cpp:404-426` | ✅ `direction[*nextIndex] > zero && direction[*previousIndex] >= zero`, **indexed by vertex identity**, with the canonical-order caveat in a comment |
| **E3** one rule only | `FieldTransportAtlas.h:514`, callers `:547` and `SurfaceCellTracing.cpp:552` | ✅ exactly one overload, two production callers |
| **E3** round trip deleted | grep for `field_branch_world_direction` | ✅ absent from the entire tree |
| **E4** T1 exhaustiveness | `SingleMinimizerVertexEndpointDispatchesVertexHit` + implementation | ✅ endpoint parameter dispatches `VertexHit` |
| **E5** cross-edge flow | `validate_field_branch_transport_flow` `:645-674`, called at `:1003` | ✅ called **before** adopting the transported entry; publishes both faces, both branches, the carrier, and **six** exact derivatives |
| **E6** traversal guard | `FieldAlignedTraceTraversalGuard` at `:866`, observed at `:873` | ✅ state key includes `entryPoint`; cycle and budget both **return an error** — the old spurious clean terminus is gone |
| **E7** reachability notes | `FieldTransportAtlas.cpp:174-179` | ✅ *"Unreachable from valid FieldBranchDirection authority… not production coverage"* |
| **E8** ten falsifiers | selector tail | ✅ exactly ten `ResolvedBranchCorrection.*` |
| **E9** selector | recomputed hashes | ✅ 338; 316-prefix byte-identical to accepted authority |

**E2 and E3 are implemented exactly as specified, including the vertex-identity indexing that the
amendment called out as the silent-failure risk.** E3's digest pre-check was performed and found no
absolute atlas digest, which matches prediction **P5** of the previous review.

**The corrective work is real and correctly done.** The remainder of this review is about what the frozen
measures failed to *ask for*, not about what the implementation failed to do.

---

## 3. R1 — adjudication of identity 329: the cause is solely `std::uint8_t`

`ResolvedBranchCorrection.NetworkDiagnosticsPublishEveryRequiredLocusLosslessly` asserts token presence
across eleven constructed errors. I audited **every** token against the emitter and its backends.

| Token class | Emitted by | Verdict |
|---|---|---|
| `sourceFace=0-1-2`, `relatedSourceFace=0-1-3`, `publishedFaces=[…]` | `source_face_locus` → `index()` (`std::size_t`) | ✅ |
| `sourceEdge=0-1`, `publishedEdges=[…]` | `source_edge_locus` → `index()` | ✅ |
| `parameter=1/3`, `exactValues=[1/2,2/3,3/4]`, `[-1/1,2/1,…]`, `[0/1]` | `exact_rational_locus` → GMP `mpq_class` num/den strings | ✅ canonical and lossless |
| `sourceVertex=0` | `index()` | ✅ |
| `traceSteps=64`, `traceStepBudget=64` | `std::optional<std::size_t>` | ✅ **checked — not a narrow type** |
| `publishedEdges=[]`, `publishedFaces=[]` | explicit empty-set special cases keyed on the error code | ✅ present |
| **`branch=1`, `relatedBranch=3`** | `error.branch->value()` → **`std::uint8_t`** | ❌ **the defect** |

`FieldBranch::value()` returns `std::uint8_t` (`FieldTransportAtlas.h:62`). C++ stream insertion of an
unsigned character type writes the **character**, not the decimal string, so `1` becomes `\x01` and `3`
becomes `\x03`. The typed authority in the error object is correct throughout; the loss is entirely at
the serialization boundary, exactly as the TB report states.

**Sweep result — the exposure is exactly two sites and no more.** A repository-wide search for stream
insertion of a narrow-integer accessor returns exactly:

```
tests/FieldAlignedCurveNetworkTests.cpp:2764:    stream << ";branch=" << error.branch->value();
tests/FieldAlignedCurveNetworkTests.cpp:2767:    stream << ";relatedBranch=" << error.relatedBranch->value();
```

The only other `std::uint8_t value()` accessor in the codebase, `GridAutomorphism::value()`
(`GridAutomorphism.h:26`), is **never streamed**. There is no third exposure.

**R1 answer: for identity 329, solely the `std::uint8_t` defect. Casting both sites to a wide integer
type makes identity 329 green.** This is established by exhaustive token audit, not by inference from
the failure message.

---

## 4. R2 — the broader frozen diagnostic-authority issue, which is mine

The brief asks whether the failure exposes something broader. It does, and it is a defect in the
contract I froze, not in the implementation.

**The evidence that this was foreseeable.** The correct idiom already exists in this subsystem:

```cpp
// src/authority/FieldTransportAtlas.cpp:673
        << " branch=" << static_cast<int>(incidence.branch.value())
```

The project had already met this hazard and already solved it, in the same file that defines
`FieldBranch`. The new emitter did not inherit the fix because **nothing made the convention
enforceable** — not a type, not a helper, not an identity.

**The contract gap.** Amendment 5 (which I wrote) says every required locus must be *"observable in the
witness diagnostic string"*. It never says what observable **means**. Under that wording, `branch=\x01`
is observable: the byte is in the string. Every other locus in the emitter happens to go through a named
formatter — `source_edge_locus`, `source_face_locus`, `exact_rational_locus` — that returns a
`std::string`. `branch` was the **only** locus emitted by raw stream insertion of a typed accessor, and
that asymmetry is the whole defect. My amendment required a property of the *value* and said nothing
about the *mechanism*, so the one field that skipped the mechanism was unconstrained.

**The class, stated generally:** *a typed authority whose accessor returns a narrow integer type is
silently character-valued at a stream boundary.* The type system does not catch it, the compiler does not
warn, and the corruption is invisible in a `std::string`-based test that happens not to assert on that
field. Amendment 6 (§9) closes it by defining observability in terms of the mechanism, and measure **F3**
enforces it with a **class** falsifier rather than another instance.

---

## 5. A second defect of the same shape — E1c named a line, not a class

This is the most consequential finding in this review, and it is a defect in the **E-series**, not in CB2.

E1c said: *"Remove the seed back-fill at `SurfaceCellTracing.cpp:818-819`."* CB honoured that exactly.
`annotate_field_aligned_trace_seed` is clean, and identity 330 asserts it is clean.

But the same file still contains roughly **fifteen** emission sites that write the trace seed into the
`sourceVertex` **locus** field, via the legacy helper:

```cpp
field_aligned_error(FieldAlignedCurveNetworkErrorCode::InvalidCandidateTraceTransport,
                    port.sourceVertex, decision.outgoingCarrier, std::nullopt, port.singularity);
```

Confirmed at `:914`, `:926`, `:978`, `:986`, `:1000` (`port.sourceVertex`) and `:690`, `:709`, `:1150`,
`:1183`, `:1218`, `:1258`, `:1268`, `:1298`, `:1305` (`trace.sourceVertex` / `trace.terminalSingularity`),
including inside `append_field_aligned_singularity_termination`.

**Be precise about which of these are defects.** Where the failure genuinely *is* at the port —
`InvalidCandidateTraceBinding` — publishing the port's vertex is a correct locus. Where the failure is
several steps downstream and has its own site — `InvalidCandidateTraceTransport` at `:978`/`:986`/`:1000`
names `decision.outgoingCarrier` in `currentFace` but publishes `port.sourceVertex` as `sourceVertex`, and
`InvalidNetworkTerminalOwnership` at `:690`/`:709` publishes the trace's **seed** vertex — the field is
being back-filled from the seed. **That is exactly the pattern Amendment 5 rule 1 prohibits, and exactly
the pattern that made the TB-R1 report's `sourceVertex=0` misleading and cost a review turn.**

**This is my error, and it is the same error as §4.** E1c named an *instance* (two line numbers) where it
should have named a *class* (every locus field on every error emitted from the tracing path). Identity
330 is likewise an instance falsifier: it constructs one error by hand, so it passes while fifteen real
sites keep back-filling. **An instance falsifier certifies an instance.**

Measure **F2** fixes the class; measure **F3** adds the class falsifier that would have caught both this
and §4.

---

## 6. Why the `uint8_t` defect nearly defeated E1's entire purpose

No prior turn has recorded this, and it materially raises the priority of the fix.

`FieldBranch::from_integer(0)` is a legitimate, common branch value. It streams as **`\0`** — a NUL byte
embedded in the diagnostic string.

Now read the emitter's field order:

```
sourceVertex, sourceEdge, sourceFace, relatedSourceFace, branch, relatedBranch,
parameter, exactValues, publishedEdges, publishedFaces, rail, singularity,
traceSeedVertex, traceSeedSingularity, traceSteps, traceStepBudget
```

**`branch` is fifth. `parameter` is seventh.** And `parameter` is the single datum the previous review
identified as the *only* discriminator among the sphere's three candidate failure routes.

`std::string` is NUL-safe, so a gtest assertion sees through it — which is why identity 329 caught this
at all. But any consumer that crosses a C-string boundary — a log file, `c_str()`, an artifact writer,
the Actions log — **truncates at the NUL**, silently discarding `parameter`, `exactValues`,
`publishedEdges`, `publishedFaces`, and both `traceStep` fields.

So: had identity 329 not existed, or had it asserted only on fields emitted before `branch`, measure E1
could have shipped "green", the sphere could have failed again at branch 0, and the diagnostic would have
been **truncated at exactly the field E1 existed to publish**. The instance falsifier caught the class
defect here by luck of field ordering, not by design.

This is a concrete argument for **F3** (class falsifier: the emitted string contains only printable ASCII)
and for **F5** (emit the discriminating loci before the fragile ones is *not* the fix — making no locus
fragile is).

---

## 7. Static audit of identities 330–338 — what CB3 should expect

The gate stopped at 329, so nine identities are unproven. Auditing them now is the difference between one
more cycle and three. Each verdict below is derived from the packaged source.

| # | Identity | Prediction | Basis |
|---|---|---|---|
| 330 | `TraceSeedDiagnosticNeverBackfillsFailureLocus` | **PASS** | `annotate_field_aligned_trace_seed` sets only the two seed fields; asserted tokens are all `index()` |
| 331 | `ExactFlowClassificationKeepsSubToleranceCarrier` | **PASS** | field ε = 5e-11 on a unit-scale mesh puts `|d|` inside `(0, 1e-10]`; E2 makes that a carrier, and `Σd = 0, d ≠ 0` guarantees both carrier sets non-empty |
| 332 | `ExactVertexSectorRejectsToleranceBandAndSelectsUniqueFace` | **PASS** | row 0 has `d[prev] = −1e-11` (old rule admits, exact rejects); row 1 has `d[next] = +1e-11` (old rule rejects, exact admits). **Both bands in one test** — well constructed |
| 333 | `ExactVertexSectorUsesPublishedDirectionAcrossLossyRoundTrip` | **PASS** | with `d = (−1+ε, 1, −ε)` the exact rule sees `d[prev] = −ε < 0` and returns false unconditionally. One caveat below |
| 334 | `ExactVertexSectorPartitionsAcceptedInteriorFans` | **PASS — computed exactly** | see below |
| 335 | `SingleMinimizerVertexEndpointDispatchesVertexHit` | **PASS** | `d = (−1,1,0)`, entry `(1,0,0)` ⇒ `t* = 1`, exit `(0,1,0)` on edge `1-2` at parameter 0 ⇒ E4 dispatches `VertexHit` at vertex 1 |
| 336 | `CrossEdgeFlowDisagreementNamesBothPublishedAuthorities` | **PASS** | implementation inserts both directions' three coordinates = **6**, matching `EXPECT_EQ(6U, …)` |
| 337 | `TraceTraversalDistinguishesExactEntryPositionsAndFailsClosedOnBounds` | **PASS** | `boundGuard(1)`: first `Advanced`, second `steps_ >= 1` ⇒ `StepBudgetExhausted` with `traceSteps=1`, `budget=1`. `cycleGuard(3)` distinguishes parameters `1/3` and `2/3` because E6's key includes `entryPoint` |
| 338 | `AcceptedWitnessesNeverPublishDegenerateOrOutsideOutflowRejections` | **UNKNOWN — the real question** | see below |

### Identity 334, computed exactly — and what it does *not* prove

`make_four_triangle_fan` is the square `[−1,1]²` with centre vertex 4 at the origin; the fan rays at
vertex 4 are the four **diagonals**. `make_zero_transport_field` sets primary `= +X`, secondary `= +Y`,
so the branch directions are the four **axes** — each exactly bisecting a sector. For branch `+X` at
vertex 4:

| Face | `a`, `b` at vertex 4 | `(d[next], d[prev])` | Exact rule |
|---|---|---|---|
| `(0,1,4)` | `(−1,−1)`, `(1,−1)` | `(−1/2, +1/2)` | rejected — `d[next] ≤ 0` |
| `(1,2,4)` | `(1,−1)`, `(1,1)` | `(+1/2, +1/2)` | **admitted** |
| `(2,3,4)` | `(1,1)`, `(−1,1)` | `(+1/2, −1/2)` | rejected — `d[prev] < 0` |
| `(3,0,4)` | `(−1,1)`, `(−1,−1)` | `(−1/2, −1/2)` | rejected |

Exactly one admitted, by a margin of `1/2`, with every value exactly representable in `double` — **no
rounding participates at all.** Identity 334 will pass deterministically.

**But that also means identity 334 does not test what its name promises.** The hard case for a fan
partition is a direction lying **on or within rounding distance of a fan ray**, where the two faces
sharing that ray each round their own `d` independently. This fixture places every direction at the
sector *bisector* — maximally far from that case. **The four per-face directions at a shared vertex are
four independent `double` roundings of one geometric vector, and nothing in the 338 gate asserts they are
mutually consistent.** That is a genuine residual, and §8 states it as a prediction rather than a
finding, because it has never been observed.

### Identity 333's one caveat

333 *searches* for its witness (`ASSERT_TRUE(found)`) rather than constructing it. On IEEE-754 doubles
with the packaged build flags this is deterministic, and the package is immutable, so it will behave
identically on rerun. It would become fragile only under fast-math or a different rounding mode. Worth a
comment, not a measure.

### Identity 338 — and why it is ordered last

338 is the direct machine statement of the previous review's Theorems 1–3: on the accepted witnesses and
the prescribed sphere, neither `BranchContinuationDegenerateEntry` nor `BranchContinuationOutsideOutflowSet`
may be published. **It is ordinal 338 of 338.** A two-character formatting defect at ordinal 329 therefore
blocked the answer to the only question CP4c-0 exists to settle.

Note also that 338 is correctly scoped and must not be over-read: it uses `if (!sphereNetwork) { EXPECT_NE(…) }`,
so **338 green does not mean the sphere publishes a network** — only that it does not fail with those two
codes. Q8 remains the sole proof of publication. That separation is correct; it just needs saying so no
one credits 338 as a Q8 substitute.

---

## 8. Falsifiable predictions

- **P1.** Fixing the two `->value()` sites turns identity **329** green. No other change is required for it.
- **P2.** Identities **330–337** go green in the same run, per §7.
- **P3.** Identity **338** is the first real test of E2–E5 on the sphere. If green, the previous review's
  Theorems 1–3 hold in production and Q8 becomes the remaining question.
- **P4.** If **338** goes red, it will *not* be `BranchContinuationDegenerateEntry` — it will be
  `VertexTransitSectorUnresolved` or `BranchTransportFlowDisagreement`, because E2–E5 convert the old
  degeneracy into those two typed rejections by construction. **Either outcome is a localized, informative
  result, not a repeat.** `BranchTransportFlowDisagreement` at edge `6-8` would confirm route A and put
  the residual defect in A1's Z4 lift; `VertexTransitSectorUnresolved` with a published candidate set
  confirms route B and points at §7's fan-consistency residual.
- **P5.** If **P4**'s second branch occurs with the candidate set **empty or of size ≥ 2**, the cause is
  that the per-face directions at a shared vertex are independently rounded (§7). **That is not an E3
  defect and must not be answered with a tolerance.** It would be an A1 single-authority question — one
  transported representative per `(vertex, branch)` fan rather than four independent roundings — and it
  belongs to its own checkpoint, not to CB3.
- **P6.** The accepted **316** stay green: F1–F3 touch only the test diagnostic emitter and locus
  population, and F2 changes no control flow. If any accepted identity regresses, it is a **stop
  condition and a finding for review**, not a CB edit.

---

## 9. Normative amendment 6 to `Architecture_M3_CP4c0_DEFN_Frozen_Definitions.md` §10

Issued under the reviewer's authority to correct frozen definitions found inconsistent.

**Amendment 5 rule 2 said a locus must be "observable in the witness diagnostic string" and left
"observable" undefined. Replace it with a definition in terms of mechanism.**

A locus token is **observable** if and only if all four hold:

1. **Formatted, not inserted.** It is produced by a named `*_locus` formatter returning `std::string`.
   Raw stream insertion of a typed authority's accessor is prohibited — it is the mechanism by which a
   narrow integer type becomes character-valued.
2. **Printable.** The complete emitted diagnostic contains only printable ASCII plus the field
   separators. **No control character, and in particular no NUL, may appear anywhere in it.**
3. **Parseable.** Each token round-trips: the emitted text uniquely determines the value.
4. **Site-sourced.** Rule 1 of Amendment 5 is restated with its scope corrected: **every** locus field on
   **every** error emitted anywhere in the tracing path is populated only from the failure site. Trace
   seed identity appears only under `traceSeedVertex` / `traceSeedSingularity`. Where a failure genuinely
   occurs at the port, the port vertex is a legitimate site and may be published as `sourceVertex`; where
   the failure has its own downstream site, the seed may not be substituted for it.

**And a rule about how these are proved, which is the real lesson of this cycle:**

> **Every diagnostic-contract requirement must be falsified by a *class* identity that quantifies over all
> codes and all emission sites, not by an instance identity over one hand-constructed error.** An instance
> falsifier certifies an instance. Both defects found in `M3-CP4c-0-TB-R2` — the `std::uint8_t` formatting
> defect and the surviving seed back-fills — were class defects that instance falsifiers passed over.

---

## 10. Corrective measures — series **F**, one Code + Build turn (`M3-CP4c-0-CB3`)

**F0 — binding preconditions.**
Branch `agent/surface_cell_quad/p5-recover-bridge-healing`. Code + Build only; compile all eight standard
targets; **execute nothing**. Do not weaken T6, Q8, any accepted expectation, or the sphere fixture. Do
not retune, widen, narrow, or delete `kBranchTopologyTolerance`. Do not change E2/E3/E4/E5/E6 semantics —
they are verified correct in §2 and are not in scope. Do not enter CP4c-1/2/3, torus, or mechanical scope.
Re-freeze the selector and publish all three hashes.

**F1 — fix the two formatting sites (the minimum that makes 329 green).**
Add a `branch_locus(authority::FieldBranch)` formatter returning `std::string`, alongside the existing
`source_edge_locus` / `source_face_locus` / `exact_rational_locus`, and use it at
`tests/FieldAlignedCurveNetworkTests.cpp:2764` and `:2767`. **Do not** fix this with an inline
`static_cast<int>` — the point of Amendment 6 rule 1 is that the value goes through a named formatter, so
the next locus added inherits the convention instead of the hazard.

**F2 — apply E1c to the class, not the instance (§5).**
Audit **every** `FieldAlignedCurveNetworkError` construction in `src/geometry/SurfaceCellTracing.cpp` and
populate locus fields only from the failure site:
- sites whose failure is genuinely at the port (`InvalidCandidateTraceBinding`) keep the port vertex as a
  legitimate locus;
- sites with a downstream failure site (`InvalidCandidateTraceTransport` at `:914`, `:926`, `:978`, `:986`,
  `:1000`; `InvalidNetworkTerminalOwnership` at `:690`, `:709`; and the `trace.sourceVertex` sites at
  `:1150`, `:1183`, `:1218`, `:1258`, `:1268`, `:1298`, `:1305`) must publish their own site and carry the
  seed via `annotate_field_aligned_trace_seed`.
Record the disposition of each site in the CB report — including the ones deliberately left as-is and why.
This is a **locus-population** change only; **no control flow, no error codes, no conditions change.**

**F3 — class falsifiers, which is what was missing (§4, §5, §9).**
Two new identities, each quantifying over the whole surface rather than one instance:

| Identity | Asserts |
|---|---|
| `NetworkDiagnosticsContainNoControlCharactersForAnyCode` | For **every** `FieldAlignedCurveNetworkErrorCode`, build an error populating every applicable field — **including `FieldBranch::from_integer(0)`, which is the NUL case** — emit it, and assert the complete string contains only printable ASCII. Reverting F1 must turn this red. |
| `TracingPathNeverPublishesSeedIdentityAsFailureLocus` | Drive the tracing path to each reachable typed rejection and assert no error whose failure site is downstream of the port carries the seed in `sourceVertex` / `singularity`. Reverting F2 must turn this red. |

**F4 — sweep the class across the other emitters.**
`append_atlas_error` and `append_plan_error` in the same file, and any other diagnostic emitter, must be
audited against Amendment 6 rules 1–3. `GridAutomorphism::value()` is confirmed unexposed today; the
sweep is to keep it that way.

**F5 — do not reorder to hide fragility.**
Explicitly **not** a measure: do not reorder emitter fields to put robust loci before fragile ones. F1 and
F3 remove the fragility; field order must stay stable so diagnostics remain comparable across turns.

**F6 — execute the remaining required identities after a red, without credit.**
A process correction, and the highest-leverage item here. Each identity runs in a **fresh process**, so
there is no contamination risk in continuing past a red. Change the TB plan so that on a semantic red the
runner **continues executing the remaining required identities and reports them as non-crediting
observations**, then still fails closed on the gate. Credit semantics are unchanged: the gate is green only
if all 338 pass, and observations after the first red confer no acceptance. This is the same discipline
already adopted for non-gating diagnostic identities.
*Rationale:* a two-character formatting defect at ordinal 329 hid the results of nine identities including
**338**, the one that answers CP4c-0's actual question. That cost a full CB→TB cycle for zero semantic
information. Do not reorder the selector to achieve this — reordering would change the selector hash and
invites gaming the stop rule. Continue-and-observe achieves it without touching the frozen order.

**F7 — record the control SHA (§1a).**
Every CB and TB report records **both** the semantic source SHA and the workflow event/control SHA. CB2
omitted the latter; add it retroactively to the CB2 report and make it a standing requirement.

**F8 — build verification and the successor TB plan.**
Compile all eight targets clean. Record semantic source SHA, control SHA, package id and SHA-256, and all
three selector hashes; confirm the 316-prefix still equals `601ce2b6…`. Restate Q8 **verbatim**. State
explicitly that **identity 338 green is not a substitute for Q8** (§7).

---

## 11. Risk register

| # | Risk | Mitigation |
|---|---|---|
| 1 | F2 is a ~15-site edit and could perturb an accepted identity that reads `sourceVertex` | F2 changes locus **population** only — no control flow, no codes, no conditions. Any accepted red is a stop condition and a finding for review (**P6**) |
| 2 | F1 fixed with an inline cast instead of a formatter | Explicitly prohibited by F1 and by Amendment 6 rule 1; F3's class falsifier does not care, so the CB report must state which mechanism was used |
| 3 | Identity 338 goes red | Expected outcomes enumerated in **P4/P5**; both are localized and informative. Neither is answered with a tolerance |
| 4 | The fan-consistency residual (§7) is mistaken for an E3 defect | **P5** pre-authorizes the disposition: it is an A1 single-authority question for its own checkpoint, not CB3 scope |
| 5 | F6 read as weakening the gate | It changes **reporting**, not credit. The gate is still green only at 338/338 and still fails closed |
| 6 | Pressure to fix 329 alone and rerun | 329 alone is a two-character change; shipping it without F2/F3 leaves a live class defect that already cost one review turn and nearly cost E1 its purpose (§6) |

---

## 12. Review record

- **R1 answer (the brief's question):** identity 329's failure is **solely** the `std::uint8_t`
  diagnostic-formatting defect, at exactly two call sites, established by exhaustive token audit against
  the packaged source. **Confidence: high.**
- **R2 answer:** it **does** expose a broader frozen diagnostic-authority issue — Amendment 5 required a
  property of the value and never constrained the mechanism, so the one locus that bypassed the
  `*_locus` formatter convention was unconstrained. Amendment 6 closes it. **Confidence: high.**
- **Second defect found:** ~15 surviving seed back-fills that E1c's line-scoped wording did not reach
  (§5). **This is a defect in the E-series, not in CB2.**
- **Hazard recorded for the first time:** `FieldBranch::from_integer(0)` emits NUL, `branch` precedes
  `parameter`, and `parameter` is the sphere's discriminating datum (§6).
- **CB2's E1–E9 claim:** independently re-verified and **accurate**. E2 and E3 are implemented exactly as
  the previous amendments specified, including vertex-identity indexing.
- **Evidence:** all six artifact digests, the selector hash, the 316-prefix hash, and the semantic-source
  ancestry independently verified; audited source confirmed **byte-identical** to the packaged source.
- **Unresolved:** identity 338 and Q8 — the sphere's actual behaviour under E2–E5 remains unobserved.
  The fan-consistency residual (§7) is unproven in either direction and deliberately out of CB3 scope.
- **Successor turn:** `M3-CP4c-0-CB3`, measures **F0–F8**. Code + Build only.
- **Mutation statement:** this review executed **no** runtime, **no** build, **no** benchmark, and made
  **no** change to product source, test source, fixtures, the selector, or build configuration. Its only
  writes are to durable documentation under `.agents/Directional/`.
