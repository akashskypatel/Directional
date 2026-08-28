# Architecture M3 CP4c-0b — DG T4 Independent Review and T5 Authorization

**Turn:** `M3-CP4c-0b-DG-T4-REV`
**Type:** Independent review / planning only — no product, test, fixture, selector, build, package, or runtime mutation. Source, selectors and committed evidence were read and hashed locally; nothing was executed and nothing product-side was modified.
**Evidence under review:** `M3-CP4c-0b-DG-T4-EXEC`, **EXECUTION GREEN 7/7**, run/job `33128261911 / 98711506300`, immutable GMP package `9668492827`, semantic source `b2629040450c12507367c232f68a4d972b46450f`; result `9669229181`, diagnostic log `9669229414`.
**Also consumed:** `Architecture_M3_CP4c0b_CB2_Code_Build_Report.md` (T0–T3), `M3_CP4c_Consolidated_Record.md`.
**Incoming accepted authority:** M3-CP4c-0 **346/346 ACCEPTED**; M3-CP4ab **316/316** beneath it.

---

## 0. Verdict

**T4 is valid and T5 is authorized.** The diagnostic gate is green 7/7 on an immutable GMP package with clean postflight, the T1 measurement returned the first decision row with numbers that leave no ambiguity, and T2/T3 implement exactly what the DG review specified.

**Two things are settled that were open:**

1. **The caveat in `Architecture_M3_CP4c0b_DG_Independent_Review_Record.md` §0 is withdrawn.** That review's link 5 — that every pipeline-torus node is a mandatory-edge endpoint — was explicitly flagged as *inferred from accepted green preconditions, not measured*. T1 measured it: **48 `HardFeature` mandatory edges, 0 singularities, 48 structural endpoint nodes, 0 traces, 0 events, zero contact provenance.** The inference was correct and is now evidence.
2. **`M3-CP4c0b-DG-CAND-02` is RESOLVED**, test-side over-specification, non-stable, no product defect.

**But T4 establishes far less than its greenness suggests, and the gap is the whole of T5.** The seven DG identities have **never been accepted** and are a strict subset of the 353. **Not one accepted identity has executed against S2–S6.** S2–S6 changed the contact predicate, the arrival priority, the event vocabulary, the terminal datum and the *stage at which termination is decided* — and the entire evidence that this did not break accepted authority is, at this moment, **zero runs**.

§4 identifies **four accepted identities at ordinals 7, 9, 12 and 13** — all inside the accepted-316 prefix — whose expectations are functions of exactly what S2–S6 changed. Two are authorized to change; **two are not**. §4.4 names the one I consider most likely to fire and explains why nothing so far has tested it.

**Measures U0–U7 (§5) are the binding specification for `M3-CP4c-0b-TB-T5`.**

---

## 1. Independent verification of T4

Everything below was checked in this review against the committed repository, not taken from the report.

| Claim | Independent check | Verdict |
|---|---|---|
| DG selector is 7 identities | `wc -l` = **7** | ✅ |
| DG selector SHA-256 `d28bbeeb…e245c` | recomputed locally | ✅ **exact match** |
| Full selector is 353 identities | `wc -l` = **353** | ✅ |
| Full selector SHA-256 `51ff96d7…ac6a5` | recomputed locally | ✅ **exact match** |
| The 353 contains every accepted identity | `comm -13 (353) (346)` = **0 missing** | ✅ |
| All seven DG identities are in the 353 | `comm -23 (7) (353)` = **0 outside** | ✅ |
| **The accepted prefix is preserved in order** | SHA-256 of the **first 346 lines** of the 353 selector = `20d3b0b1400d5cab6af4a339a858c56fb7fd0359fb995a395dad215b20f3e46a` | ✅ **byte-identical to the accepted CP4c-0 selector** |

That last row is stronger than the report claims and worth recording: the 353 is not merely a superset, it is the accepted 346 **in the same order**, with seven identities appended. So a T5 run reports the accepted prefix at the same ordinals it always had, and `first_red_ordinal` remains directly comparable to every prior CP4c-0 run.

**Boundary and integrity.** The report records artifact-only runtime, no repository timeout, no configure/compile/relink/repair/generated-discovery, no package/source/test/fixture/selector mutation, package and materialized-source byte-and-mode postflight PASS, result and log independently re-hashed after download, 28/28 package manifest, and GMP runtime supplied without rebuilding. Every identity selected exactly once with exit 0. **Nothing in the boundary record is self-contradictory and nothing is missing.**

---

## 2. T1 — the measurement that closed the DG question

| rail authority | mandatory edges | kinds | singularities | structural nodes | traces | events | node provenance |
|---|---:|---|---:|---:|---:|---:|---|
| `atlas-derived` | 0 | — | 0 | **0** | 0 | 0 | — |
| `pipeline-authoritative` | **48** | 48 `HardFeature` | 0 | **48** | 0 | 0 | every node a mandatory-edge endpoint; **zero contact nodes** |

This is the first decision row of the DG review's binding table, unambiguously. The three routing rows that would have sent the turn back to review — a node with `contact` provenance, a node with no lawful provenance, or a disagreement between the two witness-construction helpers — **all failed to trigger**, and CB2 records that the same-authority production-witness construction path was audited with no second divergence found.

**One observation worth carrying forward, not a defect.** The pipeline torus carries **48 `HardFeature` mandatory edges** on a closed genus-1 surface with no boundary and no singularities. That is a large feature set, and it is what supplies A2b's ≥2 regions and non-trivial cycle on that witness. It is lawful and predates CP4c-0b entirely. It is recorded here so that a future turn reading "the torus has 48 hard features" does not mistake it for a new phenomenon.

---

## 3. T2 and T3 — verified against what the DG review specified

**T2 — the corrected identity** (`tests/FieldAlignedCurveNetworkTests.cpp:7002-7034`), checked line by line against DG review §5's T2:

| DG review required | Implemented | Verdict |
|---|---|---|
| delete `EXPECT_TRUE(nodes().empty())` | replaced by `ASSERT_FALSE(nodes().empty())` | ✅ |
| keep zero-trace | `EXPECT_TRUE(candidate_traces().empty())` | ✅ |
| keep zero-event | `EXPECT_TRUE(events().empty())` | ✅ |
| add: no node has contact provenance | per-node `EXPECT_FALSE(has_provenance(…, Contact))` | ✅ |
| add: every node lawful | per-node `EXPECT_TRUE(has_provenance(…, MandatoryEdgeEndpoint))` | ✅ **stronger than required** |
| add: no trace carries `terminalContact` | loop over traces | ✅ |
| add: zero `TraceIntersection` and `SingularityPortJunction` | explicit histogram assertions | ✅ |
| rename to state the contract | `TorusPublishesNoTraceAndNoContactNodeAndFanRemainsExcluded` | ✅ |

**T3 — census self-description.** Every census line now emits `railAuthority`, `mandatoryEdgeCount` and `singularityCount` alongside `nodeCount`, and the corrected identity asserts `Cp4cRailAuthority::PipelineAuthoritative` **before** consuming its node figure. That is the enforcement the DG review asked for: a node count can no longer be imported across an unnamed rail-authority boundary.

**No shortfall against the specification was found.**

---

## 4. What T4 does not establish — the T5 risk map

This is the substance of the review. T4 ran seven never-accepted identities. **S2–S6's effect on accepted authority is measured by nothing.**

### 4.1 The general shape of the exposure

S2–S6 changed five things that accepted identities can observe: the contact **predicate** (shared-face → proper crossing, strictly narrower), the arrival **priority** (seniority → `ArcLengthFiltered` with mutual termination), the event **vocabulary** (site A split out of `TraceIntersection`), the terminal **datum** (`terminalContact` added, terminus no longer erased), and — the deepest — the **stage** at which termination is decided (post-hoc truncation → decided during advance).

The first four are visible in event kinds and trace content. **The fifth can change a trace's terminus without any contact being involved at all**, because a barrier or singularity arrival is now resolved inside the priority queue rather than after the fact.

### 4.2 The four accepted identities in the blast radius

Located by reading the accepted selector and the assertions themselves. **All four are inside the accepted-316 prefix.**

| Ordinal | Identity | Witness | What it asserts that S2–S6 can move | Authorized to change? |
|---:|---|---|---|---|
| **7** | `FieldAlignedCurveNetwork.DeclaresTraceIntersectionsAsTypedNetworkEvents` | two-ring | requires a `TraceIntersection` at the singularity port node — which S2 renames to `SingularityPortJunction` | **YES** — S1 review |
| **9** | `FieldAlignedCurveNetwork.IndependentCompositionOracleValidatesTraceEventGraph` | two-ring | its precondition currently depends on site A supplying a `TraceIntersection` | **YES** — S1 review |
| **12** | `FieldAlignedCurveNetwork.PublishesTypedFirstContactAndTerminationEvents` | two-ring | barrier-termination and `FirstContact` contract | **NO** |
| **13** | `FieldAlignedCurveNetwork.PublishesTypedSingularityPortsAndMandatoryGraph` | **four-triangle fan** | `EXPECT_EQ(8U, network.nodes().size())` | **NO** |

Ordinals 7 and 9 are exactly the two re-authorings the S1 review authorized, and no others. **Ordinals 12 and 13 are not authorized, and if either requires an expectation edit the turn stops.**

### 4.3 Ordinal 12 — expected to survive, and why

`PublishesTypedFirstContactAndTerminationEvents` asserts the two-ring's barrier-termination contract. S1 measured the two-ring at `A/B/C = 1/0/0` with **zero** shared-face contacts and the histogram `SingularityPortOrigin=1, FirstContact=3, TraceIntersection=1, MandatoryBarrierTermination=3`. Its sole `TraceIntersection` is the site-A junction, which S2 relabels; the three `FirstContact` and three `MandatoryBarrierTermination` events are untouched by the vocabulary split.

**Prediction: ordinal 12 stays green with no edit.** If it does not, the cause is S5's relocation changing a barrier arrival, which is materially different evidence and takes priority over everything else in T5.

### 4.4 Ordinal 13 — the one I would watch, and the trap it sits in

```cpp
// 5 vertex-keyed nodes (4 mandatory-edge endpoints + 1 singularity vertex)
// plus one published terminal 0-cell per barrier-terminating trace (3).
EXPECT_EQ(8U, network.nodes().size());
```

**That 8 is not a structural constant. It is `5 + (number of traces that terminate on a barrier)`.** The second term is a direct function of termination semantics — precisely what S2–S6 rewrote. Any fan trace that stops somewhere other than a barrier drops the count to 7 and reds an accepted identity at ordinal 13.

**And here is the trap.** The witness is `make_four_triangle_fan()` — the four-triangle fan, which CP4c-0b has repeatedly and correctly declared **excluded**: excluded from the S1 census's legitimate reasoning (`population=excluded`, *fixture-artifact-imposed-matching-contradicts-geometry*), and executed by the DG's own torus identity "only as an excluded non-creditable structural witness".

**Excluded from reasoning and credit is not excluded from the gate.** The fan is accepted authority at ordinals 12's sibling position 13, and it must stay green. Nothing in S1's decision-making, nothing in the seven DG identities, and nothing in T4 has validated it under the new mechanism. This is the single largest untested surface in CP4c-0b, and it is untested *because* the witness was correctly excluded from a different question.

**Prediction, with its basis stated.** S1 measured the fan at `A/B/C = 1/0/0`, **zero** shared-face contacts, and **`nodes = 8`** — under `rails_from_atlas`, which is the same authority ordinal 13 uses (`tests/…:521`), so the comparison is legitimate this time. A proper crossing is a strict subset of a shared face, so **zero shared-face contacts implies zero proper crossings**, so S3 removes no fan contact and the three barrier terminations should survive. **Ordinal 13 is therefore predicted green at 8.**

**The residual risk is not S3, it is S5.** The prediction holds the contact set fixed at zero; it does not hold the *terminus resolution* fixed. Under the new integrated path a barrier arrival is decided inside the priority queue, and the mutual-termination tie policy can fire on simultaneous arrivals. If the fan's three traces reach their barriers simultaneously — plausible on a symmetric four-triangle fan with an index-one field — the tie policy is exactly the code path least exercised so far. **U3 requires this be measured before the gate is run, not discovered by it.**

### 4.5 Also unmeasured

- **CP4ab digests and A2b.** `tests/…:2126` asserts `network.nodes().size() == plan.rotation_system().size()`. It is relative and will track, but it means any node-count change propagates directly into A2b's rotation system. No accepted A2b identity has run against S2–S6.
- **The prescribed sphere at gate scale.** `PrescribedSpherePublishesTwentyFourTracesAndCorrectedContactEvents` passed in the DG, which is the first live evidence that S5's relocation works and that Q8 criteria 2 and 3 are reachable. It is **one identity, one witness, one run**, and it says nothing about cost at 353-identity scale with GMP.
- **N1/N2/N4.** The CP4c-0b DEFN §6 requires an identity asserting the CB9 stand-in guards **do not fire** on any witness reaching A2a. The sphere now publishes 24 traces, so N1 must no longer fire there. **That identity is not among the seven**, and its absence is not recorded anywhere as deliberate.

---

## 5. Measures **U0–U7** — binding for `M3-CP4c-0b-TB-T5`

Artifact-only Test + Benchmark on the immutable CB2 package. **No configure, compile, relink, repair, generated discovery, or source/test/fixture/selector mutation.** GMP runtime supplied without rebuilding.

### U0 — binding preconditions

Stop and return to review if any fails.

- **U0.1** The package is exactly `9668492827`, SHA-256 `e0661e66cfc12ce8945962a18b8a8f6fc8aa5a1213b3ad4d2409054573dce0b8`, from semantic source `b2629040450c12507367c232f68a4d972b46450f`; manifest 28/28.
- **U0.2** The 353 selector hashes to `51ff96d72e1c2c88e9407e99737e42ec9093ea238aaf8b1e45ff2559f71ac6a5`, and **its first 346 lines hash to `20d3b0b1400d5cab6af4a339a858c56fb7fd0359fb995a395dad215b20f3e46a`** — the accepted prefix, in order. Verify both, not just the first.
- **U0.3** `exactArithmeticBackend=GMP` in the package metadata, and the runner provides the GMP runtime libraries.

### U1 — the ordered gate

Run all **353** identities in selector order, one identity per fresh process, recording ordinal, identity, owning executable, exit code, elapsed time and complete stdout/stderr for each. **Continue through the full gate after a red**, preserving `first_red_ordinal`.

Required re-proof, reported separately:

- accepted prefix **316/316**;
- CP4c-0 prefix **346/346**;
- full gate **353/353**.

### U2 — the four watched ordinals, reported individually

Report ordinals **7, 9, 12, 13** by name with their exact result, **whether or not the gate is green**, and for each red the complete failure text and the assertion line.

**Binding disposition:**

| Observation | Action |
|---|---|
| Ordinals 7 and 9 red **only** in the site-A vocabulary way the S1 review authorized | Re-author exactly those two, name them in the report, continue |
| **Ordinal 12 or 13 red** | **STOP.** Do not edit. Return to review with the full failure text and the T5 result artifact. Neither is authorized, and §4.4 predicts 13 green — a red there falsifies the prediction and is new evidence about S5's relocation |
| Any other accepted identity red | **STOP.** Same. |
| Ordinal 13 green but at a value other than 8 | Impossible — it is `EXPECT_EQ`. If the identity was silently altered, that is a selector/package integrity failure and a stop |

### U3 — fan and two-ring terminus census, non-gating, **published even if the gate is green**

The gap in §4.4 is that nothing measures *why* ordinal 13 holds. Publish, per witness (four-triangle fan, two-ring) under `rails_from_atlas`:

1. per-trace terminal kind — `terminalSingularity` / `terminalBarrier` / `terminalContact` — and the assertion that exactly one is set;
2. the count of barrier-terminating traces, which is the second term of ordinal 13's `8`;
3. node count with **per-node provenance**, in the T3 format including `railAuthority`;
4. the event-kind histogram;
5. **whether any arrival comparison returned inconclusive, and whether the mutual-termination tie policy fired** — the code path §4.4 identifies as least exercised.

**Prediction:** fan `nodes = 8` with 3 barrier-terminating traces; two-ring `nodes = 9` with 3 barrier-terminating traces; zero contact termini on both; zero mutual terminations on both. **A mutual termination on either witness is material new evidence** and must be reported prominently even if every identity passes.

### U4 — guard-silence census, non-gating

Publish, per witness reaching A2a, whether **N1** (`TraceCombinatorialRecurrenceExceeded`), **N2** (`BranchContinuationExactMagnitudeExceeded`) or **N4** (step budget) fired. **Prediction: none fire anywhere**, including the prescribed sphere, which now publishes 24 traces.

A guard firing after S5's relocation means the termination contract is incomplete. **It is a stop, and the response is never to widen the allowance** — CP4c-0b DEFN §6 and the CB9 record both freeze that.

### U5 — cost and integrity

Record per-identity elapsed time and flag any identity exceeding a small multiple of its historical time. **No process may run for minutes**; the TB-R8 lesson is that an unbounded identity is a defect, not a slow test. Record zero escaping `C++ exception with description` anywhere in the log — N5 makes that a product invariant.

Immutable postflight: re-hash package, source archive, selectors, fixtures and executable inventory; record `configure=false`, `compile=false`, `relink=false`, `repair=false`, `generatedDiscovery=false`, `mutation=false`.

### U6 — regression accounting

Categorize every observed regression or candidate in `Regression_Root_Cause_Tracker.md` before the turn closes. If the evidence does not justify a stable-ID or count change, record the candidate/non-stable disposition and state explicitly why **42 / 14 / 28** is unchanged.

### U7 — prohibited

No configure, compile, relink, repair, or generated discovery. No source, test, fixture, selector or package mutation. **No editing any accepted identity except ordinals 7 and 9 in exactly the authorized way.** No widening a guard allowance, magnitude policy or error bound. No adding a timeout. No entry into CP4c-1/2/3.

### Acceptance

CP4c-0b **closes** on a green U1 (**353/353**, accepted **316/316**, CP4c-0 **346/346**) with U3/U4's predictions met and U5 clean. **Anything less routes to independent review**, not to a retry.

---

## 6. Stop conditions, extended

The CP4c-0b §11 list, the P0.3 review §8 list and the DG review §6 list all stand. Added:

- ordinal 12 or 13 goes red and is edited rather than reviewed;
- an accepted identity outside ordinals 7 and 9 requires an expectation edit;
- a mutual termination or an inconclusive arrival comparison is observed on the fan or two-ring and is not reported;
- N1, N2 or N4 fires on any witness and the response proposed is to widen it;
- any identity runs for minutes;
- the full 353 is run without U0.2's accepted-prefix hash check.

---

## 7. Durable lessons

- **Excluded from reasoning is not excluded from the gate.** The four-triangle fan was correctly excluded from CP4c-0b's census reasoning and from acceptance credit, four separate times and each with a good reason. It is nonetheless accepted authority at ordinal 13, with an absolute node count that is a direct function of the termination semantics the checkpoint rewrote — and nothing in the checkpoint's evidence chain ever tested it. **When a witness is excluded from a question, write down that it remains binding on the gate.**
- **An absolute count is a hidden function of the semantics that produce it.** `EXPECT_EQ(8U, nodes().size())` reads as structure and decomposes as `5 + (barrier-terminating traces)`. Its own comment says so, which is the only reason it was findable. **Before changing a stage's semantics, grep the accepted suite for absolute counts and decompose each one.**
- **A green subset gate measures the subset.** Seven never-accepted identities passing is real evidence about those seven and no evidence at all about the 346 beneath them. State what a gate does not cover in the same breath as its result, every time.
- **When a review flags an inference as unmeasured, the next turn must close it explicitly.** The DG review marked link 5 as inferred; T1 measured it and the caveat is now withdrawn in writing. An unmeasured inference that is never revisited becomes an assumption, and this project has paid four documents' worth for exactly that.

---

## 8. Accounting and exact successor

- accepted runtime authority: **M3-CP4c-0 346/346**; M3-CP4ab **316/316**
- CP4c-0b full selector **353** / `51ff96d72e1c2c88e9407e99737e42ec9093ea238aaf8b1e45ff2559f71ac6a5`; accepted prefix preserved in order at `20d3b0b1…3e46a`
- DG selector **7** / `d28bbeeb74ed8e07810b06d870bdaf470bab1f294bbfe810deaa4f63276e245c`
- CP4c-1 selector **318**, unchanged
- stable accounting **42 / 14 / 28**, produced-witness debt **5**, M3 packages **54** — unchanged; this turn executed nothing
- **`M3-CP4c0b-DG-CAND-02` — RESOLVED / TEST-SIDE OVER-SPECIFICATION / NON-STABLE.** T1 returned the first decision row with zero contact provenance.
- `M3-CP4c0b-DG-CAND-01` remains RESOLVED ORCHESTRATION / NON-STABLE.
- `M3-CP4c0b-P03-CAND-01` remains **ACTIVE** — S2–S6 are implemented and diagnostic-green but **unmeasured against accepted authority until U1**.

**Exact next: `M3-CP4c-0b-TB-T5` under U0–U7.** Artifact-only, package `9668492827`, full 353 gate, with ordinals 7, 9, 12 and 13 reported individually and U3/U4's censuses published whether or not the gate is green.
