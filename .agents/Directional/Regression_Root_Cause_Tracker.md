# Surface-Cell Regression Root-Cause Tracker

Permanent stable-ID regression, repeated-pattern, architecture, and test-authority index for PR #8. Detailed historical event evidence remains in `.agents/Directional/PR_8_Regression_Audit_Inventory.md`; the current immutable turn report owns current artifact/runtime detail.

Last updated: **2026-08-27 UTC** after the fresh compile and complete `M3-CP4c-0-TB-R9` whole-gate re-proof. Latest accepted runtime is CP4c-0 **346/346** on run/job `33079817998 / 98543736213`, consuming fresh GMP package `9649395432` from semantic source `7bbc0480d9ab5954329b940992ef41a9223102ed`. Both original TB-R9 RED identities are resolved non-stable test-side defects and now pass in the complete frozen gate. CP4c-0 is **CLOSED / ACCEPTED**. Stable accounting remains **42 events / 14 categories / 28 recurrences**, produced-witness debt **5**, M3 packages **51**.

TB-R8 is **INCOMPLETE / BLOCKED BY VALID PRODUCTION TERMINATION FAILURE** on run/job `33028238313 / 98374531360`, control `078aac03923c0badc42d150397065fe5b33212c6`, consuming immutable CB8 package `9628445643` at semantic source `19ba8e9c5e58f9c33c14b309841165d3f0401db5`. P1 completed **342/343** identities: 341 pass, ordinal 338 red after 853.437 s with `gcd(): while running too long!`, ordinal 343 incomplete at explicit user cancellation. First-316 and first-328 remain green. No acceptance credit; P2-P8 were not reached. Stable accounting remains **42 / 14 / 28**, debt **5**, M3 packages **47**. Its termination candidate later transferred to CP4c-0b after CB9 bounded the cost path.

## M3-CP4c0-TB-R9-CAND-01 — GMP backend invalidates legacy digit-limited lossy-round-trip test precondition — RESOLVED / NON-STABLE / TEST-SIDE GMP PORTABILITY

- **Observed:** TB-R9 ordinal 333 `ResolvedBranchCorrection.ExactVertexSectorUsesPublishedDirectionAcrossLossyRoundTrip` failed at `ASSERT_TRUE(found)` before the production vertex-sector predicate was exercised.
- **Root cause:** the test searched for a witness by calling `ENumber::to_double(18)` and relied on the legacy backend's explicit 18-decimal-digit render/parse truncation. The GMP backend implements `to_double(int)` as `mpq_class::get_d()` and ignores `maxDigits`; the backend-specific witness search therefore did not establish its intended lossy precondition.
- **User-authorized bypass:** the user explicitly skipped `M3-CP4c-0-TB-R9-REVIEW-PLAN` and authorized `CB-R10` followed by `TB-R10` for this GMP-related defect only. The skipped review is not retroactively marked complete and does not adjudicate `CAND-02`.
- **Correction:** CB-R10 changed only `tests/FieldAlignedCurveNetworkTests.cpp`, preserving the test identity and production predicate. The witness is now deterministic and backend-independent: exact `epsilon = 1/7` is converted through an explicitly lossy numerator/denominator-to-double round trip in the test itself, and the test asserts the reconstructed direction differs before invoking the production exact predicate. No GMP or product arithmetic semantics were changed.
- **Build proof:** semantic source `30ef2792e2915e0016dfd11f5fa2b3727e5503c0`; compile run/job `33067140968 / 98499967674`; GMP package `9644214591`, ZIP SHA-256 `b9e7729fb557eddc203e38a1c11564bab3ad180982e10740d4374fe06748a390`; all eight standard targets compiled/linked, preflight/build exit 0, source clean, `runtimeExecution=false`.
- **Focused runtime proof:** artifact-only TB-R10 run/job `33067370314 / 98500728780` consumed only package `9644214591`; the exact identity selected once and passed (`exit=0`, `failures=0`, `errors=0`, 5 ms harness elapsed); package preflight/postflight immutable PASS; no configure/compile/relink/repair/discovery/benchmark occurred. Result artifact `9644274456` / `4d80bc1ca8e9d0f624e709eb7c467e5b1c2c880d6a1619f1f8ced95151305693`; log artifact `9644274922` / `2c8922ccf03e356db0e78fbe07a4a22bb99019009e4e40669f58bba16fcdd122`.
- **Disposition:** resolved as a test-side portability/precondition defect. Focused TB-R10 supplied individual corrective proof; the later whole-gate TB-R9 re-proof `33079817998 / 98543736213` selected all 346 frozen identities and passed **346/346**, including this identity, so the correction is now also proven in gate context. CP4c-0 is closed/accepted.
- **Stable-count rationale:** accepted CP4ab prefix remains 316/316 and CP4c-0 has never been accepted; **+0 events / +0 recurrences**. Totals remain **42 / 14 / 28**, debt **5**.

## M3-CP4c0-TB-R9-CAND-02 — exact-magnitude positive-control fixture enters zero-time continuation — RESOLVED / NON-STABLE / TEST-SIDE FIXTURE-PRECONDITION

- **Observed:** TB-R9 ordinal 344 `ResolvedBranchCorrection.ExactContinuationMagnitudePolicyFailsClosedWithoutTolerance` proves the oversized exact-width rejection, then its supposed narrow positive control expects a decision but receives an error.
- **Root cause:** on face `(0,1,2)`, `boundary_point(incoming=(0,1), 1, 2)` has exact barycentric coordinates `[1/2,1/2,0]`. The old positive-control direction `{-1,2,-1}` marks coordinates 0 and 2 as outflow; their exact candidate exit times are `1/2` and `0`, so coordinate 2 wins at exactly zero. `resolve_field_branch_continuation` is contractually required to return typed `BranchContinuationDegenerateEntry` for `time == 0`; production was failing closed as designed.
- **Correction:** CB-R11 changed only `tests/FieldAlignedCurveNetworkTests.cpp`. The positive control now uses direction `{-2,1,1}`, for which only coordinate 0 is outflow and the exact winning exit time is `(1/2)/2 = 1/4`. The test now asserts an `EdgeExit` on outgoing edge `(1,2)` at exact `boundary_point(outgoing,1,4)`. The oversized exact-magnitude rejection and all production/GMP arithmetic semantics are unchanged.
- **Build proof:** semantic source `267272d22f7de67ce7d8e368a53cc78a37ca3e8f`; compile run/job `33077493539 / 98535503386`; GMP package `9648550565`, ZIP SHA-256 `1f0275e96fa75b7fc6fb447eaffb79b414c94230823da7897a4f2d91df33615c`; all eight standard targets compiled/linked, preflight/build exit 0, source clean, `runtimeExecution=false`.
- **Focused runtime proof:** artifact-only TB-R11 run/job `33077761701 / 98536455697` consumed only package `9648550565`; the identity selected exactly once and passed (`exit=0`, `failures=0`, `errors=0`, 39 ms harness elapsed); package preflight/postflight immutable PASS; no configure/compile/relink/repair/generated discovery/performance benchmark occurred. Result artifact `9648618375` / `469cab3ee5a541a5faa29fcdac2a6ff213ca202c8ff38522e131b0a9a4ba6113`; log artifact `9648618836` / `c15831693911134a4ab3eba6fa8060af8b95e85eac679d5374c632fcecdc908d`.
- **Disposition:** resolved as a test-side fixture/precondition defect. The skipped TB-R9 review remains skipped/not completed. The later whole-gate TB-R9 re-proof `33079817998 / 98543736213` passed **346/346**, including this corrected identity; CP4c-0 is therefore closed/accepted. This candidate remains non-stable and adds no regression event.
- **Stable-count rationale:** no accepted-green identity regressed; **+0 events / +0 recurrences**. Totals remain **42 / 14 / 28**, debt **5**.

## M3-CP4c0b-P03-CAND-01 — the accepted trace-contact mechanism is defective in six respects — ACTIVE / PRODUCT SEMANTICS / PRE-EXISTING

- **Observed:** `M3-CP4c-0b-CB1` stopped at binding precondition P0.3, which required `FieldAlignedNetworkEventKind::TraceIntersection` to be declared and produced by nothing. Static inspection of semantic head `49831e30433d72504a69b5a8c817aa6fa00f953c` proved it is produced at three sites and that **A2a already implements crash-on-contact**.
- **D1 - the contact predicate is face equality.** `field_aligned_first_trace_contact` (`src/geometry/SurfaceCellTracing.cpp:1278-1307`) tests only `segment.sourceFace != existingSegment.sourceFace`; everything after it returns a contact. Two traces on parallel, non-crossing paths through one triangle are declared in contact and the later one is truncated. `field_aligned_common_carrier` only labels the contact; it does not gate it.
- **D2 - priority is trace index order.** `existingIndex < traceIndex`. This is the `TraceSeniority` metric the CP4c-0b DEFN §4.2 ranks worst and §5 forbids in production; it is the shipped behaviour.
- **D3 - the contact node ignores geometry.** `field_aligned_append_contact_node` (`:1310-1318`) uses `sourceFace.vertices().front()`, the lowest-numbered vertex of the triangle.
- **D4 - the pass runs after tracing completes.** `canonical_field_aligned_candidate` (`:1804-1817`) returns the tracing error before reaching `finalize_field_aligned_events`, so **the contact pass is unreachable for any trace that never finishes**. This is the mechanism behind the six circulating prescribed-sphere traces and TB-R8's 853 s, and it is the shape `DESIGN.md` 4.6 disclaims as post-hoc repair.
- **D5 - `TraceIntersection` is overloaded** across origin junction (`:1391`), crash-on-contact (`:1433`) and self-closure on a revisited face (`:1512`).
- **D6 - truncation erases a legitimate terminus:** `terminalBarrier`, `terminalPoint` and `terminalSingularity` are all reset at the contact.
- **Classification:** **pre-existing product semantic defect in accepted authority**, latent because the accepted witnesses are small and their traces short. Not a regression introduced by CP4c-0 or CP4c-0b.
- **Re-proof exposure:** correcting D1 strictly reduces the contact set, so any accepted trace currently truncated by a non-crossing contact would continue - changing segments, terminus, events, node set and downstream digests. CP3b's contact identities, CP3a trace content and CP4ab's node count and `network_digest` are in scope. **This must be measured, not estimated.**
- **Owning measures:** S1 (census, mandatory first and empowered to route back to review), S2 (vocabulary split), S3 (exact proper-crossing predicate), S4 (arrival priority replaces seniority), S5 (relocate into the trace loop), S6 (node position and terminal datum).
- **Stable-count rationale:** accepted 316 and CP4c-0 346 are green with the defect present, and CP4c-0b has never been accepted. **+0 events / +0 recurrences**, totals **42 / 14 / 28**, debt **5**.

## M3-CP4c0-TB-R8-CAND-01 — grazing-edge tracing enters pathological exact-arithmetic work; practical termination guard is insufficient — ACTIVE / NON-STABLE / PRODUCTION PERFORMANCE-TERMINATION

- **Observed:** immutable TB-R8 P1 completed 342/343 fresh processes. Ordinal 338 `ResolvedBranchCorrection.AcceptedWitnessesNeverPublishDegenerateOrOutsideOutflowRejections` took **853.437 s** and then failed with `gcd(): while running too long!`. Its last deterministic atlas line was singularity 7, fan 3→0, edge `(43,49)`, lift `-1`. Ordinals 339-342 passed. Ordinal 343 `ResolvedBranchCorrection.GrazingTraceSegmentsPublishExactEndpointSupport` did not return before explicit user cancellation.
- **Prior baseline:** the pre-CB8 338-gate was green in TB-R7. CB8 deliberately changed grazing continuation semantics; the prescribed-sphere network now progresses into a path that did not complete within a reasonable bound.
- **Classification:** production performance/termination candidate, **not** a structurally invalid fixture, expectation error, or CI-only problem. The full TB-R8 gate is incomplete and receives no acceptance credit, but ordinal 338 is trustworthy completed runtime evidence.
- **Proximal source localization:** `src/numerics/BigInteger.cpp::gcd` throws after 10,000 Euclidean iterations. `ENumber::simplify()` invokes it while normalizing exact rationals. This is an emergency backstop, not a practical field-tracing termination policy.
- **Existing guard insufficiency:** `FieldAlignedTraceTraversalGuard` detects exact repeated `FieldAlignedTraceTraversalState` and enforces `field_aligned_trace_step_budget(topology)`. On `sphere_prescribed` the current formula yields **1,775,616** steps (`192*4*(288+1)*8`). The recurrence key contains the exact boundary point, so a topologically repeating path with changing rational parameters may evade early cycle detection.
- **Root-cause confidence:** high that termination/progress guarding is operationally insufficient; medium on the exact first non-progress mechanism because the cancelled run has no stack trace or exact-operand growth census.
- **Required adjudication:** independent review must identify a semantic progress/cycle invariant and a practical deterministic finite-work bound before any correction. Do not simply lower an arbitrary constant and do not make a workflow/test timeout the product guard.
- **User stop rule:** **do not re-run TB-R8 until the guard is implemented and compile-green.**
- **Stable-count rationale:** CP4c-0 has never been accepted, so this is recorded as a non-stable candidate: **+0 events / +0 recurrences**. Totals remain **42 / 14 / 28**, debt **5**.

## M3-CP4c0-TB-R4-CAND-01 — prescribed sphere A2a rejects reciprocal branch flow at edge 6-8 — ACTIVE / NON-STABLE / **ROOT CAUSE IDENTIFIED: near-tangency; the invariant is too strong, A1 is correct**

- **Observed:** creditable Q8 after exact package integrity, frozen **338/338 PASS**, and F3 **2/2 PASS**. G5 publishes `fieldAlignedCurveNetwork=false;networkError=BranchTransportFlowDisagreement;sourceEdge=6-8;sourceFace=6-8-9;relatedSourceFace=6-8-97;branch=3;relatedBranch=1;traceSeedVertex=0;traceSeedSingularity=0` plus six exact source/target direction values.
- **Q8 impact:** criterion 2 is binding red because the sphere does not publish the required 24-trace network. P4 predicted Q8 would remain red; G5 supplies the concrete cause.
- **Static localization:** `src/geometry/SurfaceCellTracing.cpp:644-671`, `validate_field_branch_transport_flow`, rejects when the shared carrier is source-outgoing but not target-incoming.
- **Classification:** semantic candidate requiring independent authority review. Do not infer production defect from the error code alone.
- **Required adjudication:** reconstruct edge-`6-8` pairing + signed-lift authority, account for Amendment-7 gauge, determine why source outgoing is not target incoming, and identify the owning invariant before authorizing correction.
- **Stable-count rationale:** accepted **316/316** remains green and CP4c-0 has never been accepted; **+0 events / +0 recurrences**.
- **Adjudicated 2026-08-26** by `M3_CP4c_Consolidated_Record.md` §3b (retired TB-R4 review). **Symptom proved exactly** by decoding the six exact rationals: source face `6-8-9` canonical `(6,8,9)` has `d[2] = −1.0035357904` (edge `6-8`, opposite vertex 9) ⇒ **Outflow**; target face `6-8-97` canonical `(6,8,97)` has `d[2] = −0.5769964399` ⇒ **also Outflow**. Both triples sum to **exactly** zero, so both are valid `is_barycentric()` authority. **A continuous direction cannot exit a shared edge from both incident faces.**
- **Not a tolerance artifact.** `|d| = 1.0035` and `0.5770` are three orders of magnitude above every epsilon in this codebase, so the "route A′ within-face tolerance band" explanation from the first CP4c-0 review is **excluded**.
- **The invariant is correct.** Amendment 4 / measure E5 is right as stated; the physically correct target branch is **`3`** (= branch `1` + 2), whose `d[2] = +0.5769964399` is **Inflow** exactly as the crossing requires. **The published lift is off by 2 — a full reversal.**
- **Context worth keeping:** the source face is a genuine **`1×2`** face (outflow `8-9` and `6-8`, inflow `6-9`), so CP4c-0's exact min-ratio rule *chose* edge `6-8` from a real ambiguity — the continuation rule is working; the transport that follows it is not.
- **Classification:** **production semantic defect** in cross-face branch transport authority (A1) **or** in the branch A2a carries into it. Not fixture, not diagnostic false positive, not admissibility. **Mechanism undetermined and deliberately not guessed.**
- **Hypothesis refuted and recorded** (review §5): per-face canonical-normal parity. The two faces *do* have opposite canonical parity, and parity mismatch covers **86.8 %** of the sphere's interior edges (torus 92.6 %, mechanical 90.2 %, fan 50 %) — but the gauge is an **index shift** into a per-face array and cancels in `matching + g_X − g_Y` regardless of frame. Two supporting assumptions were also excluded: `{primary, secondary, −primary, −secondary}` reproduces the stored rawfield ordering `{v0, v1, −v0, −v1}` **exactly**, and `v1` is `+90°` CCW from `v0` about the mesh normal in **all 192** faces.
- **Surviving candidates:** (a) **matching sign/direction convention** — a sign error yields a difference of exactly 2 when the true matching is odd and none when even, is invisible where matching is 0, and concentrates near singularities; edge `6-8` is incident to **vertex 8, a singularity**; (b) **matching aliasing** (`DESIGN.md` §4.1, Vaxman et al.); (c) **A2a carries the wrong branch** from an earlier step — the failure is several steps from seed vertex 0.
- **Decisive test — measure H1:** a non-gating **cross-face flow-agreement census** over A1 authority alone (no tracing): every interior edge × every branch, both directions, reporting each violation with the **published `signedLift`** and both exact `d[opp]`. Violations only on odd lifts ⇒ (a); sparse near singularities without a parity pattern ⇒ (b); **zero violations while the trace still fails ⇒ (c)**, redirecting to A2a.
- **Disposition:** `M3-CP4c-0-CB5`, measures **H0–H7**, diagnostic-only. **H5 prohibits any production change this cycle** — a sign flip on one failure site with the census unrun would be a fixture-shaped guess at global authority.
- **CB5 compile status:** H1/H2/H3 are compiled in semantic source `cd2ffb74fc0a5680e55ad63ba2bd3fc6b75e456e` and package `9601160869`; H4 source provenance is recorded; no runtime has executed. Mechanism remains unresolved until TB-R5 runs H1.
- **TB-R5 H1 result:** `32994846466 / 98261255799`, result `9616160533` / `1ecfd85f…02ad8`. H1 checks **4224** pairs and finds **390** disagreements (9.23295%): two-ring `4/160` (all lift 0), fan `2/32` (all lift 0), sphere `144/2304` (`0:102, ±1:7, ±2:6, ±3:8` per sign counts as published), torus `240/1728` (`0:184, ±1:11, ±2:11, ±3:6` per sign counts as published). The live edge `6-8` failure appears as the expected reciprocal pair at lifts `+2/-2`.
- **H1 adjudication boundary:** **H-A is excluded** because violations are not odd-lift-only and are dominated by lift 0. **H-C is excluded** because the A1 census is nonzero. A ~50%/uniform systematic index error is unsupported by 2.5–13.9% witness rates. **H-B remains plausible but is not proved**: the census does not establish singularity localization, and the manually prescribed fan has two lift-0 disagreements even though computed matching aliasing is absent there. The next independent review must distinguish matching aliasing from another sparse A1 pairing/flow inconsistency before authorizing production semantics.
- **Q8 after H1:** still creditable and RED only at binding criterion 2; G5 remains `BranchTransportFlowDisagreement` at edge `6-8`, branch `3 → 1`, `signedLift=2`, now with complete seven-step trace history. This is continuation of the same candidate, not a new accepted regression.
- **Standing caveat:** the accepted **316** being green does **not** establish that cross-face transport is correct — E5 created that invariant in CB2 and no accepted identity asserts it. If the census returns violations at a material rate, some accepted traces may be wrong and were never checked; that is a pre-existing defect newly detectable, not a CP4c-0 regression.
- **Stable-count rationale:** accepted 316 green, CP4c-0 never accepted. **+0 events / +0 recurrences**, totals **42 / 14 / 28**, debt **5**.
- **Reviewed 2026-08-26** by `M3_CP4c_Consolidated_Record.md` §3b (retired TB-R5 review). H1's census **mechanism verified correct in source**: it iterates published `transports()`, applies `directed->signedLift` via `sourceBranch.rotated(...)` (Amendment 7 compliant), and compares exact `d[opp]` against exact zero on each face's own canonical key. Coverage self-check `pairsChecked = interiorEdges × 8` re-derived and correct for all four witnesses.
- **Population corrected — the four-triangle fan's 2 violations are a FIXTURE ARTIFACT.** Its census field is `make_index_one_singularity_field`, which leaves the direction vectors **globally constant** (+X/+Y on every face, inherited from `make_zero_transport_field`) and merely *imposes* `matching = ±1` on **one** edge. For the violating edge `1-4` the published lift is **exactly correct**: `matching(+1) + rawGauge[0-1-4](0) − rawGauge[1-2-4](1) = 0`. The flow disagreement is forced by a matching that contradicts the geometry, not by any A1 defect. Predicted count = one edge × two directions = **exactly the 2 observed**, and both reported `sourceD = targetD = −1/2` were reproduced by hand from the constant field and the runtime-verified gauges `A=0, B=1, C=2, D=1`. A counterfactual simulation with the gauge correction absent everywhere would give **8** fan violations, not 2.
- **Consequently the prior reading that the fan weakens H-B is WITHDRAWN.** The fan's matching is not merely "prescribed rather than computed" — it is prescribed **inconsistently with its geometry**, which guarantees a disagreement whatever A1 does. The fan bears on nothing about production.
- **The lift histogram is uninformative about matching.** `signedLift = matching + g_source − g_target` is a sum of three unobserved terms, so lift-0 dominance is consistent with almost any matching distribution. The ±1/±2/±3 tail symmetry (sphere `−3:8/+3:8`, `−2:6/+2:6`, `−1:7/+1:7`; torus `−3:6/+3:6`, `−2:11/+2:11`, `−1:11/+1:11`) is **imposed by the census's own two-direction loop**, not by the field — and every count is therefore doubled.
- **Corrected population:** distinct `(edge, branch)` disagreements are two-ring **2**, fan **1 (artifact)**, sphere **72**, torus **120** ⇒ **388 directed / 194 distinct** over three legitimate witnesses. The two-ring's field (`make_cp3a_two_ring_index_one_field`) is a genuinely rotating index-one field — `angle = base + 0.25·smoothPhase` sweeps exactly 90° around the centre — so it is a legitimate witness.
- **Hypothesis status:** **H-A excluded** (violations at lift 0 and even ±2; a sign error `k → −k` changes nothing at 0 or 2) — it was the TB-R4 reviewer's own favoured candidate and the census falsified it. **H-C excluded** (A1 is not clean), with the corollary that A2a is *not* thereby cleared. **~50% uniform index error unsupported.** **H-B undecided and undecidable as currently instrumented.**
- **Decisive measurement — measure J1:** publish per violation the three composing terms (`matching`, `rawGauge[source]`, `rawGauge[target]`) plus singular-vertex incidence and distinct-pair counts. Decision table: violations concentrated on `matching ≠ 0` ⇒ field-authority/aliasing (**H-B**); on `matching = 0` with unequal gauges ⇒ **gauge composition** defect in `build_branch_transports`; on `matching = 0` with equal gauges ⇒ **flow classification / direction publication** defect in `build_boundary_pairing`. **J3** adds an independent matching-versus-geometry check.
- **Contract reframing:** E5's cross-edge invariant audits the field's **input matching** as much as A1's composition. A witness with imposed matching **will** trip it, correctly; its firing is not by itself evidence of an A1 code defect.
- **Disposition:** `M3-CP4c-0-CB6`, measures **J0–J7**, diagnostic-only. **J0 prohibits any production semantics change** until the decision table is filled in.
- **TB-R6 J1/J3 result:** authoritative `33006282429 / 98300813772`, result `9620769314 / fe6a7317…6684`. H1 exactly reproduces the reviewed legitimate population: two-ring 4 directed / 2 distinct, sphere 144/72, torus 240/120 ⇒ **388 directed / 194 distinct**; the fan remains excluded at 2/1. Legitimate term split is matching-nonzero **48/24**, matching-zero unequal-gauge **86/43**, matching-zero equal-gauge lift-zero **254/127**. Only 52/388 legitimate directed violations are singular-incident.
- **J3 excludes current legitimate matching mismatch.** Independent geometry audit is two-ring 20/20, sphere 288/288, torus 216/216 = **524/524 agreement**. The only disagreement is the excluded fan edge `1-4`, exactly confirming its fixture-imposed matching contradiction. H-B field-matching/edge-aliasing is therefore not supported for the current legitimate witnesses.
- **Live Q8 owner selected by frozen table:** sphere edge `6-8` forward decomposition is `matching=0`, `rawGaugeSource=1`, `rawGaugeTarget=3`, `signedLift=2`; J3 agrees with declared matching. This selects **A1 gauge composition in `build_branch_transports`** as the direct owner of the live `BranchTransportFlowDisagreement`.
- **Residual class remains:** **254 directed / 127 distinct** legitimate disagreements have matching 0, equal gauges and lift 0, selecting the frozen **A1 flow classification / direction publication in `build_boundary_pairing`** row. Independent review must decide whether one lower convention defect explains both classes or whether the Q8 correction is scoped separately.
- **Disposition after TB-R6:** mandatory independent `M3-CP4c-0-TB-R6-REVIEW-PLAN`; no production fix before review. Stable counts remain **42 / 14 / 28** because accepted 316 stays green and CP4c-0 remains unaccepted.
- **Root cause identified 2026-08-26** by `M3_CP4c_Consolidated_Record.md` §3b (retired TB-R6 review). The disagreements are a **near-tangency discretization phenomenon**, and **Amendment 4 / measure E5's invariant is unsound for a piecewise-constant field**. It asserts a *continuum* property — a direction exiting `X` must enter `Y` — which fails when the direction is nearly parallel to the shared edge, because the field's own rotation across that edge flips the small perpendicular component. **Both faces then correctly compute "outflow".**
- **Independent reproduction.** From the committed `sphere_prescribed.obj` and `.rawfield` alone — no product code — the review reproduced **exactly 144 directed disagreements**, matching the runtime figure. Tangency ratio `min(|d_opp| / max|d|)`: **disagreeing median 0.0218, max 0.2004** (n=144); **agreeing median 0.9233** (n=1008). A 42× separation, with overlap at the bottom — a geometric regime, not a threshold.
- **Every published term at the live locus is CORRECT**, each independently verified: `matching = 0` is geometrically right (nearest target raw index at **23.7°**, next at **66.3°** — not an aliasing case); `matching + g_src − g_tgt = 0 + 1 − 3 ≡ 2` reproduces the published `signedLift = 2`; both gauges map their semantic branch to **raw index 0**; both published `dbary` triples reproduce **to 10 decimal places**; and all 288 interior edges are normal adjacency with none folded. **There is nothing in A1 to fix.**
- **Three prior readings withdrawn.** (1) The live locus does **not** indict `build_branch_transports` — the TB-R5 decision-table row it satisfied is withdrawn as a diagnosis. (2) There are **not two classes**: the unequal-gauge (86/43) and equal-gauge/lift-0 (254/127) populations are one near-tangency phenomenon — the "lowest common invariant" the TB report asked for. (3) **J3's 524/524 does not exclude H-B**: `independent_edge_measurement` (`tests/support/SkewSingularFieldWitness.h`) re-implements **principal matching**, the algorithm H-B suspects, so it is an implementation cross-check, not an aliasing test. H-B is excluded, but by direct measurement at the live locus.
- **Reviewer errors owned:** the TB-R4 "geometrically impossible" claim and its magnitude-versus-ratio reasoning (`|d| = 1.0035` is the **smallest** of `{4.00, 5.01, 1.00}` — tangency is a ratio); the J3 specification, which named principal matching as its own oracle; and the TB-R5 decision-table rows that attached owners to what is one geometric regime.
- **The real open question** is a tracing-model gap: **`DESIGN.md` §4.5 does not define what a trace does at an edge the neighbouring face's direction also exits.** Candidate models (tangential continuation, typed grazing terminus, refinement precondition, joint two-face continuation) are framed but **not chosen** — that is a `-DEFN` obligation and needs K2's cost measurement.
- **Disposition:** `M3-CP4c-0-CB7`, measures **K0–K7**, **diagnostic-only — no production change authorized**; then **`M3-CP4c-0-DEFN-2`** to close the §4.5 gap. **No tolerance may be introduced to classify grazing** (Amendment 9 clause 3).
- **Stable-count rationale:** accepted 316 green, CP4c-0 never accepted. **+0 events / +0 recurrences**, totals **42 / 14 / 28**, debt **5**.


- **TB-R7 K1/K3 disposition:** authoritative `33019554121 / 98346293968` reproduces the near-tangency separation and independently finds **176/176 complete vertex fans / 0 holonomy mismatches**. J3 remains legitimate **524/524** as the explicitly limited principal-matching implementation cross-check. The corrected decision table therefore supports a tracing-model definition gap rather than a period/holonomy production defect.
- **TB-R7 K2 limitation:** the grazing continuation-cost proxy reports **0/24** traces reaching grazing, one traversed edge for every trace, no first-grazing step, and zero consecutive grazing crossings. Review prediction P3 is **not observed**. Because the proxy never reaches the later known G5 grazing locus, it supplies no cost comparison among the four frozen `DEFN-2` models and selects none. Classification: **diagnostic limitation / NON-STABLE; +0 events / +0 recurrences**.
- **Disposition after TB-R7:** exact next `M3-CP4c-0-DEFN-2`, definition only. No production patch, tangency tolerance, or CP4c-1/2/3 entry is authorized.

- **Adjudicated 2026-08-26** by `Architecture_M3_CP4c0_DEFN_2_Frozen_Definitions.md`. **The candidate is no longer a defect under investigation — it is a defined continuation.** `BranchTransportFlowDisagreement` is retired from production emission; a carrier that is an outflow carrier on both sides is a **grazing edge transit**, and the trace slides along it to the endpoint both faces drive the published parameter toward, then re-enters the existing T2/T3 vertex dispatch. At the live locus, edge `6-8` transits to **vertex 8, which is a singularity**, terminating by **T3 `SingularityTermination`**.
- **Independent re-derivation from the committed fixtures alone** (no product code): sphere **72** grazing configurations on **72 distinct** edges, torus **120** of 864 `(edge, branch)` pairs; grazing ratio median `0.021788` / max `0.200424` on the sphere and `0.074604` / `0.102869` on the torus, matching TB-R7's K1 figures to six decimal places. **Slide-direction ambiguity: 0 of 192** — zero sign disagreements and zero zero-rates on both witnesses. The eight sphere singularities are the corners of an inscribed cube with exactly **3** grazing edges each, and the grazing edges lie in narrow corridors along the field's separatrices.
- **Closure path:** the candidate is closable by CB8's **L2** census, which must reproduce those counts and confirm zero ambiguity. It remains ACTIVE / NON-STABLE until then. **+0 events / +0 recurrences**, totals **42 / 14 / 28**, debt **5**.

## M3-CP4c0-TB-R8-CAND-01 — prescribed-sphere traces do not terminate, and no product guard could see it — ACTIVE / PRODUCT SEMANTICS / GUARDED, NOT RESOLVED

- **Observed:** `M3-CP4c-0-TB-R8` INCOMPLETE / BLOCKED on run/job `33028238313 / 98374531360`, CB8 package `9628445643`. Ordinal 338 `ResolvedBranchCorrection.AcceptedWitnessesNeverPublishDegenerateOrOutsideOutflowRejections` failed after **853.437 s** with an uncaught `C++ exception with description "gcd(): while running too long! "`. Ordinal 343 never returned before user cancellation. Accepted first-316 and first-328 remained green.
- **Root cause, three compounding defects.** (1) **Six of the prescribed sphere's separatrices circulate forever**, lapping a closed 32-state `(face, branch)` circuit and drifting in exact position every lap. CB8's grazing transit correctly retired `BranchTransportFlowDisagreement`, which had been aborting the network at the first grazing edge and *incidentally* stopping every trace before any could circulate. (2) **Neither guard could see it.** `FieldAlignedTraceTraversalState` contains the exact entry position, so a lapping trace never repeats a state; the step budget `8 x branchStates x (transports+1)` = **1,775,616** could never be reached. (3) Exact values grow **~1.12 base-1e9 limbs per step** without bound, and the fallback bignum answers by throwing: at ~step 205 (~233 limbs) Euclid passed its fixed 10,000-iteration cap.
- **Independent reproduction from the committed fixtures alone**, no product code: of 48 candidate ports (superset of production's 24), **42 terminate at a singularity** in <=32 steps at <=49 limbs, entering each `(face, branch, incoming carrier)` **exactly once**; **6 circulate** with 19 revisits by step 600 and growing. The populations separate completely.
- **Cost model:** `BigInteger::single_digit_division` binary-searches each quotient digit recomputing `dividend - divisor*mid` over the whole dividend per probe, so a division is `O(30n^2)`, a `gcd` is `O(n^3)`, and a trace's total cost scales near the **fourth power** of its final width. That is the 853 seconds.
- **Classification:** **product semantic defect** in A2a termination. Not fixture, not packaging, not orchestration, not a diagnostic false positive.
- **Corrective measures landed (`M3-CP4c-0-CB9`, N0-N7, compiled, nothing executed):** N1 position-free combinatorial recurrence guard (`TraceCombinatorialRecurrenceExceeded`, allowance **2** against a measured terminating maximum of **1**); N2 deterministic exact-magnitude policy (`BranchContinuationExactMagnitudeExceeded`, **4096 bits**, 2.8x the measured legitimate maximum); N3 the bignum's three fixed `10000` caps replaced by bounds derived from the algorithms' own worst cases; N4 step budget becomes a provable envelope of N1 (1,775,616 -> 9,216); N5 `FieldAlignedCurveNetwork::make` closed against any escaping exception; N6 four falsifying identities; N7 one identity moved to non-gating.
- **Simulated after the change:** 42/42 legitimate traces unchanged with the same terminal singularities; 6/6 runaways stopped at step 65; worst exact width **19,460 -> 2,684 bits**.
- **NOT RESOLVED, and TRANSFERRED to `M3-CP4c-0b`.** The guards bound the damage; they do not make the traces terminate. `M3-CP4c-0b-DEFN` (2026-08-27) resolved the ownership question by **splitting the checkpoint**: CP4c-0 keeps continuation and closes at gate 346 on Q8 criteria 1/4/5, while **CP4c-0b owns trace termination and Q8 criteria 2 and 3**, moved together and unweakened by Amendment 11. This candidate is resolved by CP4c-0b prediction 5 - **N1, N2 and N4 do not fire on any witness** - and not before.
- **Frozen mechanism.** Crash-on-contact terminates all six: measured, every circulating trace has a proper transversal crossing with another trace available at **its own step 0**, always against a **perpendicular** branch pair (`(0,1)`, `(0,3)`, `(1,2)`, `(2,3)`) and never against `(0,2)`/`(1,3)`, which are the same line traversed oppositely and cannot cross. Termination is therefore robust to arrival order; the priority metric decides which partition, never whether one exists.
- **Two candidate rules excluded by measurement.** *Self-contact*: 2,548 co-face segment pairs over 420 steps with **zero** crossings, zero touches, zero collinear overlaps - structural, because A1 publishes one constant direction per `(face, branch)` so repeat visits lay parallel segments, and the circuit is 32 distinct faces each on one branch. *Mesh-derived length budget*: the longest correctly terminating trace (5.0175) and one lap of a never-terminating trace (5.0175) are the same length to four decimal places, separation ratio **1.000**, so length carries no information about termination; a bounding box is also not rotation-invariant, arc length is not exactly comparable, and truncation leaves an arc that bounds no region.
- **N1's calibration risk stands.** Its allowance is measured on one witness (every terminating sphere trace enters each `(face, branch, incoming carrier)` exactly once). A mesh where a legitimate separatrix winds several times before reaching a singularity would trip it. N1 retires only when an identity proves no witness in the matrix reaches it, and the retirement is a plan update recording that evidence.
- **Withdrawn:** `Architecture_M3_CP4c0_DEFN_2_Frozen_Definitions.md` 9.2's cube-graph prediction, which predicted every sphere trace terminating at a singularity. 9.3's Q8-criterion-3 response is unaffected.
- **Stable-count rationale:** accepted **316/316** remains green and CP4c-0 has never been accepted. **+0 events / +0 recurrences**, totals **42 / 14 / 28**, debt **5**.

## M3-CP4c0-DEFN2-CAND-01 — the K2 grazing-cost census walks traces with the retired Cartesian carrier lookup — ACTIVE / NON-STABLE / TEST-SIDE

- **Observed:** TB-R7 measure K2 reported `tracesReachingGrazing = 0 / 24`, `traversedEdges = 1` for **every** trace, `firstGrazingStep = none`, and zero consecutive grazing crossings — while the production tracer's own G5 history reaches the grazing locus after **seven** steps. TB-R7 recorded this as a "diagnostic limitation" without a mechanism.
- **Mechanism, identified statically:** `cp4c_sphere_grazing_cost_census` (`tests/FieldAlignedCurveNetworkTests.cpp:4033-4133`) does not call the production continuation. Its per-step resolution at `:4067-4072` is `cp4c_distinct_outgoing_carriers(*pairing, *incomingCarrier)` with `if (outgoing.size() == 1U)`, then `break` — **the Cartesian carrier-set lookup that `M3-CP4c-0-DEFN` §5.1 deleted.** It carries no `FieldBoundaryPoint`, so on any `1x2` face it sees two outgoing carriers, resolves nothing, and stops. The prescribed sphere is **50% `1x2`** (Z1 census), so every trace dies at step 1.
- **Classification:** **test-side diagnostic defect.** No product impact; the production tracer is unaffected and resolves `1x2` faces correctly with the position datum.
- **Consequence, normative:** K2's null result carries **no information about any grazing model** — it measured the retired rule, not the regime. No model may be preferred or rejected on it, in this turn or a later one.
- **Owning measure:** **L8**. The census must call `resolve_field_branch_continuation(currentFace, *pairing, *currentEntryPoint)` and thread the returned `exitPoint` forward, exactly as `field_aligned_candidate_traces` does. Prediction after correction: every sphere trace traverses more than one edge, and the trace seeded at vertex `0` reaches edge `6-8` at step **7**, matching G5.
- **Durable lesson recorded:** a diagnostic that reimplements a retired rule measures the retired rule. A census must either call the production entry point or state in its published output which rule it implements.
- **Stable-count rationale:** accepted **316/316** remains green, CP4c-0 has never been accepted, and no product behaviour changed. **+0 events / +0 recurrences**, totals **42 / 14 / 28**, debt **5**.

## M3-CP4c0-TB-R6-CAND-01 — Python ZIP extraction lost executable mode before runtime — RESOLVED ORCHESTRATION / NON-STABLE

- **Observed:** control run `33006048971 / 98300014224` verified package/source/selector authority and statically built the 338 route, then the first attempted launch of `directional_surface_cell_producer_tests` failed with `PermissionError`. No Directional binary executed.
- **Root cause:** Python `zipfile.extractall` did not materialize the archived executable permission bits. This was control-materialization behavior, not package corruption and not a product failure.
- **Resolution:** retry `33006282429` changed only package extraction to ordinary `unzip`, which preserves archived modes. No `chmod`, binary repair, rebuild, relink, source mutation, or package mutation occurred; postflight is clean.
- **Stable-count rationale:** pre-runtime orchestration only, **+0 events / +0 recurrences**.

## M3-CP4c0-TB-R5-CAND-01 — hosted Actions outage and temporary self-hosted byte-normalization detour — RESOLVED ORCHESTRATION / NON-STABLE

- **Observed:** GitHub-hosted Actions experienced delayed/failed triggers while TB-R5 control was being installed. Temporary self-hosted migration was explicitly owner-authorized. Runs `32993852779 / 98257876870` and `32994482392 / 98260020875` both stopped at immutable control-payload SHA verification; the test script and all Directional binaries were skipped. Hosted runners were restored before the semantic run.
- **Root cause:** self-hosted checkout line-ending normalization changed the three staged shell-part bytes relative to their frozen SHA-256 values. The attempted `.gitattributes` normalization did not alter the already-checked-out immutable bytes in the failing run. This is control transport/environment behavior, not product semantics.
- **Resolution:** switch workflows back to hosted Ubuntu; hosted run `32994846466` verified all frozen payload hashes, executed the complete immutable gate and postflight, and is the sole semantic authority.
- **Process note:** three artifact-metadata queries were made before this turn's mandatory policy reads during the initial interrupted orchestration phase. They caused no download, mutation, runtime, or evidence promotion. Record as an orchestration/process-order defect and do not repeat it.
- **Stable-count rationale:** no accepted product identity regressed and both self-hosted attempts executed no Directional runtime. **+0 events / +0 recurrences**.

## M3-CP4c0-TB-R4-CAND-02 — postflight summary references `first_red` instead of persisted `first_red_ordinal` — RESOLVED ORCHESTRATION / NON-STABLE

- **Observed:** after all 341 planned semantic processes and post-runtime inventories, final reporting failed under `set -u` with `first_red: unbound variable`; persisted state was `first_red_ordinal=0`.
- **Evidence validity:** result artifact preserves gate/F3/G5/Q8 state, manifest-post, and pre/post inventories; all compare identical and manifest remains **27/27 PASS**.
- **Classification:** orchestration/reporting-control defect only; it altered no semantic command or authoritative bytes.
- **Disposition:** resolved for TB-R4 by preserved evidence; **no semantic rerun**. Successor control may use `first_red_ordinal` consistently.
- **Stable-count rationale:** control-plane only; **+0 events / +0 recurrences**.

## M3-CP4c0-TB-R3-CAND-03 — required supplemental falsifier asserts that the prescribed sphere fails — RESOLVED BY TB-R4 / NON-STABLE

- **Observed:** static + runtime finding of `M3-CP4c-0-TB-R3-REVIEW-PLAN`. The mandatory supplemental falsifier `ResolvedBranchCorrection.TracingPathNeverPublishesSeedIdentityAsFailureLocus` contains `ASSERT_FALSE(networkBuild)` on the prescribed sphere and **passed** in run `32921851098`.
- **Two consequences.** (1) A passing `ASSERT_FALSE` is direct runtime proof that **the prescribed sphere still does not publish a `FieldAlignedCurveNetwork`**, so **Q8 is expected to fail on the next TB even at 338/338**. Neither the TB-R3 report nor its review brief surfaces this, and planning the successor as "fix the two reds and Q8 closes" would be wrong. (2) The assertion **encodes current production output as an expectation** and will invert — going red — at exactly the moment CP4c-0 succeeds, blocking acceptance for the wrong reason.
- **Classification:** diagnostic/oracle defect in the frozen measure series, not in the implementation. The F3 specification asked for a falsifier that "drives the tracing path to each reachable typed rejection"; CB3 reasonably implemented that against the sphere's live failure. The spec should have required the seed-provenance property to be proved on a **constructed** failure whose existence the test controls.
- **Related gap:** nothing in the frozen 338 gate or either supplemental publishes the sphere's *current* rejection code. It is known only by exclusion — not `BranchContinuationDegenerateEntry`, not `BranchContinuationOutsideOutflowSet` (identity 338), not `InvalidCandidateTraceBinding` (supplemental). This is the **third consecutive cycle** in which the sphere's decisive datum was computed at runtime and not published.
- **Disposition:** measures **G4** (de-encode the assertion; prove the property on a constructed failure, make any sphere branch conditional) and **G5** (add a non-gating identity that always publishes the sphere's A2a outcome and locus). G4 must land in CB4, before the sphere is fixed.
- **Stable-count rationale:** no accepted identity regressed; CP4c-0 has never been accepted. **+0 events / +0 recurrences**, totals **42 / 14 / 28**, debt **5**.
- **TB-R4 resolution evidence:** F3 remains **2/2 PASS** after G4 moved the seed-provenance proof onto a constructed failure, while G5 independently publishes the live sphere outcome without asserting that the sphere must fail. The diagnostic/oracle defect is closed. The live sphere failure is tracked separately as `M3-CP4c0-TB-R4-CAND-01`.

## M3-CP4c0-TB-R3-CAND-01 — lossy-roundtrip falsifier builds a DCEL-invalid single-triangle mesh — RESOLVED BY TB-R4 / NON-STABLE

- **Observed:** ordinal 333, `ResolvedBranchCorrection.ExactVertexSectorUsesPublishedDirectionAcrossLossyRoundTrip`, throws `compute_edge_quantities(): DCEL consistency check failed` from the test body.
- **Static localization:** the test's candidate-search loop constructs a near-degenerate one-triangle `TriMesh` and calls `mesh.set_mesh(vertices, faces)` before computing the determinant/admissibility test that would reject a bad candidate. The first rejected candidate can therefore fail fixture/DCEL construction before `direction_in_vertex_sector` is reached.
- **Classification:** high-confidence **test fixture/search-harness candidate**, not current proof of a production semantic regression. The intended predicate may never execute.
- **Required adjudication:** independently verify the call ordering and freeze a deterministic capable lossy-roundtrip witness or admissible candidate construction that reaches the predicate without weakening its expectation. Do not treat arbitrary exception suppression as a fix.
- **Stable-count rationale:** CP4c-0 has never been accepted; accepted 316/316 remains green. **+0 events / +0 recurrences**; totals remain **42 / 14 / 28**, debt **5**.
- **Adjudicated 2026-08-26** by `M3_CP4c_Consolidated_Record.md` §3b (retired TB-R3 review). Primary evidence: `C++ exception with description "compute_edge_quantities(): DCEL consistency check failed" thrown in the test body`, at **0 ms**. `TriMesh::set_mesh` → `compute_edge_quantities()` (`TriMesh.h:145-163`) calls `dcel.check_consistency(verbose, true, true, true)`, which throws. `checkPureBoundary` (`DCEL.h:1546-1565`) fails with *"face is composed entirely of boundary edges"* for any face with no interior edge.
- **Sharper than the original premise:** the near-degenerate coordinate family is a **red herring**. The fixture builds a **single-triangle** mesh, whose one face has all three halfedges on the boundary, so **every** candidate is DCEL-invalid regardless of `base`, `spacing`, or `epsilon` — confirmed by the 0 ms failure on the first candidate. The determinant screen runs *after* `set_mesh`, so it never gets the chance to reject anything.
- **Classification:** test fixture/harness defect. **Not production** — `direction_in_vertex_sector` was never reached, so this identity currently provides **no evidence either way** about the lossy-round-trip property it exists to falsify. That property remains unproven, not disproven. **Confidence: high.**
- **Disposition:** measure **G1** — DCEL-valid witness (≥ 2 triangles sharing an interior edge), screen the determinant **before** `set_mesh`, preserve the `EXPECT_FALSE` falsification, prefer deterministic construction over search. Do not catch the exception, weaken the expectation, or add a tolerance.
- **TB-R4 resolution evidence:** ordinal 333 is **PASS** with G1's DCEL-valid two-triangle witness and pre-construction determinant screen. The intended exact lossy-roundtrip predicate is reached and satisfied; no production change was required.

## M3-CP4c0-TB-R3-CAND-02 — fan-partition falsifier treats face-gauged branch labels as a global direction identity — RESOLVED BY TB-R4 / NON-STABLE

- **Observed:** ordinal 334, `ResolvedBranchCorrection.ExactVertexSectorPartitionsAcceptedInteriorFans`, reports admitted-face counts 0 for branch 0, 1 for branch 1, 0 for branch 2, and 3 for branch 3 instead of exactly one each.
- **Static localization:** `build_face_branch_frame` chooses a per-face canonical gauge from that face's canonical topology reference edge. A numeric `FieldBranch` label is interpreted relative to this face-local gauge. Reusing the same integer branch label in independently gauged frames is therefore not automatically one physical/world direction around the fan.
- **Classification:** high-confidence **test-oracle/authority candidate**. The prior review's hand oracle assumed one cross-face `+X` meaning without proving gauge equivalence.
- **Required adjudication:** decide whether the valid fan oracle transports branch authority between faces or compares each face frame's published physical/exact direction. Do not mutate product semantics unless independent source evidence establishes a product defect.
- **Stable-count rationale:** CP4c-0 remains unaccepted and accepted 316/316 is green. **+0 events / +0 recurrences**; totals remain **42 / 14 / 28**, debt **5**.
- **Adjudicated 2026-08-26** by `M3_CP4c_Consolidated_Record.md` §3b (retired TB-R3 review). Primary evidence: three sub-failures at the fan-partition assertion — branch 0 admitted **0**, branch 2 admitted **0**, branch 3 admitted **3**; branch 1 admitted 1 and passed by coincidence.
- **Mechanism:** `build_face_branch_frame` (`FieldTransportAtlas.cpp:190-270`) assigns each face a **gauge** = the raw direction of `{primary, secondary, −primary, −secondary}` with the smallest positive oriented angle from that face's **canonical reference edge** (`v0→v1` of its canonical topology key), about a normal computed from the **canonical vertex order**. Semantic branch `s` denotes `raw[(gauge + s) mod 4]`. On the four-triangle fan the gauges are `0, 1, 2, 1` (the fourth face's canonical normal is anti-parallel to mesh orientation), which reproduces the observed `0, 1, 0, 3` **exactly**.
- **Classification:** oracle defect, **originating in this reviewer's E8 specification**, which said "for every `(vertex, branch)` fan, assert the exact predicate admits exactly one face" and thereby assumed a numeric branch names one physical direction across faces. It does not. **Not production. Confidence: high.**
- **Production is correct:** `build_branch_transports` (`FieldTransportAtlas.cpp:305-320`) already corrects every lift by `rawGauge[first] − rawGauge[second]`, and the trace loop, `resolve_field_vertex_transit`, and the singularity fan partition all rotate by that corrected `signedLift`. The gauge correction existing at all is source-level proof that branch labels are per-face.
- **Disposition:** measures **G2** (rebuild the oracle to walk the fan through the published `signedLift`), **G3** (independent local-holonomy check so G2 is not circular: composed lift `≡ 0 mod 4` at a regular vertex, `≡ index` at a singularity), **G6** (comment recording why the naive per-branch loop was wrong). **Amendment 7** freezes the rule. Do not special-case the fan and do not mutate production to satisfy an oracle.
- **TB-R4 resolution evidence:** ordinal 334 is **PASS** after G2 transports through published `signedLift`; G3 local-holonomy coverage is also green. The per-face-gauge oracle defect is closed without production mutation.

## M3-CP4c0-TB-R2-CAND-03 — trace-seed identity still back-filled into failure-locus fields — RESOLVED BY TB-R3 / NON-STABLE

- **Observed:** static finding of `M3-CP4c-0-TB-R2-REVIEW-PLAN`, not a runtime failure. Measure E1c named a single line (`SurfaceCellTracing.cpp:818-819`); CB honoured it exactly, and `annotate_field_aligned_trace_seed` is clean. Roughly **fifteen** other emission sites in the same file still write the trace seed into the `sourceVertex` locus via the legacy `field_aligned_error(code, port.sourceVertex, ...)` / `trace.sourceVertex` pattern: `:914`, `:926`, `:978`, `:986`, `:1000`, and `:690`, `:709`, `:1150`, `:1183`, `:1218`, `:1258`, `:1268`, `:1298`, `:1305`.
- **Scope precision:** sites whose failure genuinely *is* at the port (`InvalidCandidateTraceBinding`) publish a legitimate locus and are not defects. Sites with a downstream failure site — `InvalidCandidateTraceTransport` naming `decision.outgoingCarrier` in `currentFace`, and `InvalidNetworkTerminalOwnership` in `append_field_aligned_singularity_termination` — are back-fills and violate Amendment 5 rule 1 / Amendment 6 rule 4.
- **Classification:** **diagnostic-authority defect in the frozen measure series, not in the implementation.** E1c named an instance where it should have named a class; identity 330 is likewise an instance falsifier over one hand-constructed error, so it passes while the real sites keep back-filling. This is the same pattern that made TB-R1's `sourceVertex=0` misleading and cost a review turn.
- **Disposition:** **RESOLVED BY TB-R3.** CB3 F2 repaired the failure-site class and TB-R3 ordinal 330 passed; the supplemental `TracingPathNeverPublishesSeedIdentityAsFailureLocus` class falsifier also passed. The result is runtime re-proof of the correction, not a new stable event.
- **Stable-count rationale:** no runtime regression observed; CP4c-0 has never been accepted and the accepted 316 prefix is green. **+0 events / +0 recurrences**, totals **42 / 14 / 28**, debt **5**.

## M3-CP4c0-TB-R2-CAND-01 — branch locus diagnostic serializes uint8 as control character — RESOLVED BY TB-R3 / NON-STABLE

- **Observed:** authoritative retry 1 passes identities 1–328, then ordinal 329 fails every expected numeric branch token in `NetworkDiagnosticsPublishEveryRequiredLocusLosslessly`; emitted strings contain a raw control character after `branch=` / `relatedBranch=` instead of `1` / `3`.
- **Immediate source evidence:** `FieldBranch::value()` returns `std::uint8_t`; test/witness helper `append_network_error` inserts that value directly into `std::ostringstream`. The stream therefore selects character insertion. The typed `FieldAlignedCurveNetworkError.branch` / `relatedBranch` fields remain populated; serialization loses their decimal representation.
- **Classification:** high-confidence **test/diagnostic-observability candidate** affecting E1 runtime proof. It is not currently evidence of accepted production-authority loss because the accepted 316 prefix and the prior 328 prefix are green and the failure is in the witness serializer used by the correction test.
- **Adjudicated 2026-08-26** by `M3_CP4c_Consolidated_Record.md` §3b (retired TB-R2 review). **Scope: solely this defect, at exactly two call sites** (`tests/FieldAlignedCurveNetworkTests.cpp:2764`, `:2767`), established by exhaustive audit of every token identity 329 asserts against the emitter and the GMP exact-rational backend — `sourceFace`/`sourceEdge`/`publishedFaces`/`publishedEdges` use `index()` (`std::size_t`), `parameter`/`exactValues` use canonical `numerator/denominator` strings, and `traceSteps`/`traceStepBudget` are `std::optional<std::size_t>`. A repository-wide sweep confirms these are the **only** two stream insertions of a narrow-integer accessor; `GridAutomorphism::value()` is never streamed. **Confidence: high.**
- **Broader gap, also adjudicated:** DEFN §10 Amendment 5 required a property of the emitted *value* and never constrained the *mechanism*, so the one locus bypassing the `*_locus` formatter convention was unconstrained — while the correct idiom already existed at `FieldTransportAtlas.cpp:673`. **Amendment 6** now defines observability by mechanism and requires **class** falsifiers.
- **Unrecorded hazard now recorded:** `FieldBranch::from_integer(0)` emits **NUL**; `branch` precedes `parameter` in the emitter's field order; and `parameter` is the datum that discriminates the sphere's failure route. At any C-string boundary that NUL truncates exactly what E1 exists to publish. `std::string` is NUL-safe, which is the only reason identity 329 caught this rather than a log silently losing it.
- **Disposition:** **RESOLVED BY TB-R3.** CB3 introduced the named `branch_locus` formatter. TB-R3 ordinal 329 passed and the supplemental `NetworkDiagnosticsContainNoControlCharactersForAnyCode` class falsifier passed, re-proving decimal/lossless serialization across the diagnostic code class. Q8 remains unconsumed for unrelated gate reasons.
- **Stable-count rationale:** CP4c-0 has never been accepted and accepted 316 is green; **+0 events / +0 recurrences**, totals remain **42 / 14 / 28**, debt **5**.

## M3-CP4c0-TB-R2-CAND-02 — runner helper returned bookkeeping predicate status after identity 1 — RESOLVED ORCHESTRATION / NON-STABLE

- **Observed:** retry 0 `32914435964 / 98015089869` passed immutable preflight and identity 1, then stopped as `ORCHESTRATION_FAIL / incomplete-gate` with no semantic red and Q8 not run.
- **Root cause:** the temporary `run_identity` shell helper had no explicit successful return; for ordinals below 329 its final `[[ ordinal -ge 329 ]] && ...` expression returned false, which the caller interpreted as a gate stop.
- **Correction/evidence:** add only `return 0` after successful bookkeeping. Retry 1 reused the exact package, selector, fixtures, expectations, and semantic source and reached the deterministic ordinal-329 semantic red.
- **Stable-count rationale:** temporary orchestration only; **+0 events / +0 recurrences**.

## M3-CP4c0-TB-CAND-01 — prescribed sphere reaches typed zero-time continuation rejection before Q8 network — FIX IMPLEMENTED / NON-CREDITING 338 RE-PROOF GREEN / Q8 BLOCKED BY TB-R3 GATE RED / NON-STABLE

- **Observed:** authoritative retry 1 `32891161394 / 97943220460` passes **328/328**, but binding Q8 is red. A2a rejects `BranchContinuationDegenerateEntry` at singularity 0 / source vertex 0 / edge 6-8. No network; trace count, terminal `TraceIntersection`, and face `1-2-5` crossover unavailable.
- **Control:** accepted **316/316** and all 12 CP4c-0 identities pass; package/source/test/fixture/selector integrity unchanged; no configure/build/relink/repair.
- **Root-cause status:** **ADJUDICATED 2026-08-25** by `M3_CP4c_Consolidated_Record.md` §3b (retired TB review). **Class:** ill-formed upstream state — A1 decides the sign of a barycentric direction coordinate with a `double` tolerance in three places and publishes those verdicts as topological ownership (carrier-set membership, vertex-sector membership); A2a re-decides the same sign exactly on A1's own published datum. T6 correctly rejects a state A1 was incorrectly allowed to produce. The seam is **proved algebraically, not conjectured**: in `direction_in_incident_vertex_sector`, `alpha = d[next]` and `beta = d[prev]` identically, so `alpha > tol && beta >= -tol` *is* the exact entry predicate at `tol = 1e-10`. Confidence **high**.
- **Route still undetermined, deliberately:** three routes reach `t* = 0` (interior edge entry with cross-face flow disagreement; the same within-face at `|d| <= 1e-10`; vertex entry after a mis-selected sector transit). The discriminating datum — the exact entry parameter — was computed and dropped by the witness emitter. Measure **E1** decides it in one turn; measures **E2–E5** close all three regardless.
- **Note on the published locus:** `singularity=0` / `sourceVertex=0` are the trace **seed**, back-filled at `SurfaceCellTracing.cpp:818-819`, not the failure site. The failure is provably not the trace's first step. Only `sourceEdge=6-8` is a genuine locus.
- **Disposition:** CB2/CB3 implemented the correction series. TB-R3 identity 338 passes as a **non-crediting observation**, excluding the prior `BranchContinuationDegenerateEntry` / outside-outflow rejection pair on the accepted witnesses under package `9589508430`. Because ordinals 333/334 leave the frozen 338 gate red, Q8 is still unauthorized and unrun. This is partial diagnostic re-proof only; do not infer sphere-network publication or CP4c-0 closure.
- **Stable-count rationale:** CP4c-0 never accepted and no accepted 316 identity regressed; **+0 events / +0 recurrences**, totals **42 / 14 / 28**, debt **5**.

## M3-CP4c0-TB-CAND-02 — retry-0 artifact transfer failed before immutable validation — RESOLVED INFRASTRUCTURE / NON-STABLE

- **Observed:** run `32890863928` failed during artifact transfer before package verification and before any identity.
- **Correction/evidence:** single plan-authorized diagnosed infrastructure retry `32891161394` used unchanged package/selector/commands and completed the full gate plus Q8.
- **Stable-count rationale:** zero semantic identities in retry 0; **+0 events / +0 recurrences**.

## M3-CP4c-TB-R1-CAND-01 — production closed-surface witnesses expose accepted scope gaps — ACTIVE / NON-STABLE / DEFERRED TO CP4c-2/3

- **CP4c-1 evidence:** TB-R3 reproduces the prior torus/mechanical observations unchanged. Torus reaches A2a but publishes 0 traces / 0 events and A2b first rejects at `UncutFaceComponentOrbitSeedNotUnique`, `sourceFace=0-1-2`. Mechanical still fails A1 with `IncompleteCycleBasis` at source edge `0-3`; `fieldTransportAdjacencyExists=false` while `globalEF=1,158` and `localEF=1,158` are valid, with source boundary loops 0, genus 0, interior local vertices 152. The observed mechanical failure remains missing field-transport adjacency, not a negative `EF` row; the deeper adjacency-production cause is not yet adjudicated.
- **Control:** TB-R3 keeps the complete accepted prefix **316/316 PASS** with zero orchestration errors. Neither observation is accepted-behavior loss.
- **Disposition:** torus higher-genus region authority remains owned by blocked `M3-CP4c-2-DEFN`; mechanical closed-surface cycle-basis authority remains owned by blocked `M3-CP4c-3-DEFN`. Do not repair either inside the CP4c-1 review.
- **Stable count:** +0 events, +0 recurrences; totals **42 / 14 / 28**, debt **5**.

## M3-CP4c-TB-R1-CAND-02 — terminal TraceIntersection non-vacuity blocked by Cartesian A1 continuation authority — SUPERSEDED BY CP4c0-TB-CAND-01 / NON-STABLE

- **Observed:** C4/C5 remain red because the prescribed sphere reaches A1 and then A2a rejects `InvalidCandidateTraceTransport` at `singularity=0`, `sourceVertex=0`, `sourceEdge=1-2`; no network or terminal `TraceIntersection` is published. TB-R3 preserves the same required result **316/318** with the full accepted prefix **316/316 PASS**.
- **Z1 runtime proof:** published branch-pairing authority is ambiguous on accepted witnesses, not only the sphere: two-ring `30/60 = 50%`, four-triangle fan `4/16 = 25%`, torus `288/576 = 50%`, prescribed sphere `384/768 = 50%`. The sphere failing face `1-2-5` has incoming `1-2`, outgoing `1-5,2-5`, multiplicity `2`.
- **Z2 runtime proof:** the sphere failure site is exactly `field_aligned_outgoing_carrier` after **1 completed segment**, current face `1-2-5`, source edge `1-2`, with `fieldTransportAdjacencyExists=true`. The failure is therefore not next-face lookup or typed branch transport, and the start attachment/first transport path is viable.
- **Root cause status:** **PROVEN production A1→A2a contract gap.** `FieldBranchBoundaryPairing.connections` is a Cartesian inflow × outflow relation while A2a requires one continuation; the trace state lacks the within-face position datum needed to resolve a 1-in/2-out face. TB-R3 confirms the independent TB-R2 review's source diagnosis and falsifies witness-side repair as the smallest correction.
- **Disposition:** exact next `M3-CP4c-0-DEFN`, review/definition/planning only. Freeze one position/continuation authority and its accepted-prefix re-proof obligations before implementation. Do not resolve ambiguity inside A2a, invent identifier/order/magnitude tiebreaks, weaken C4/C5, or patch the sphere.
- **Stable count:** +0 events, +0 recurrences; CP4c-1 has never been accepted and no accepted 316 identity regressed. Totals **42 / 14 / 28**, debt **5**.
- **CP4c-0 re-proof:** CP4c-0 removes Cartesian `connections` authority and all 12 dedicated identities pass in TB `32891161394`. Sphere advances to a different first failure, `BranchContinuationDegenerateEntry` at edge `6-8`; active ownership moves to `M3-CP4c0-TB-CAND-01`.

## M3-CP4c-1-TB-R3-CAND-01 — tar/grep preflight pipefail aborted before runtime — RESOLVED ORCHESTRATION / NON-STABLE

- **Observed:** first TB-R3 orchestration run `32871811711` stopped during immutable-package preflight before the runtime step and executed **0 identities**.
- **Root cause:** an early-exit `tar -tzf <archive> | grep -q <required-path>` pipeline ran under `set -o pipefail`. `grep -q` exited immediately after finding the required path, leaving `tar` to observe a broken pipe; the otherwise successful membership check therefore surfaced as a non-zero pipeline status.
- **Correction/evidence:** replace the SIGPIPE-sensitive early-exit membership check with a preflight form that consumes/records the archive listing without making upstream success depend on `grep -q` closing the pipe. Corrected authoritative run `32872112507 / 97881418987` then completed all **323** planned processes with zero orchestration errors and exact pre/post integrity.
- **Stable-count rationale:** pre-runtime control-plane defect only; no test identity executed in the invalid run and no semantic package changed. Adds **0 stable events / 0 recurrences**; totals remain **42 / 14 / 28**.

## M3 CP4 historical regression/candidate consolidation — CLOSED / ARCHIVED

- `M3-CP4ab-TB-R3` accepted the immutable cumulative gate **316/316** (`304/304` predecessor + `12/12` CP4ab), so `PR8-R042 / M3-CP4b-R001` is **RESOLVED STABLE**.
- All CP4a/CP4b/CP4ab non-stable process, orchestration, diagnostic-reporting, test-authority, and architecture candidates formerly expanded above are closed historical context. Their material facts, exact run/package/artifact identities, dispositions, and stable-count rationales are preserved in the 2026-08-24 M3 CP4 historical-document consolidation entry and the preceding turn entries in `CHANGELOG.md`.
- Historical candidate cleanup changes no stable accounting: **42 events / 14 categories / 28 recurrences**; produced-witness debt **5**; M3 packages **34**.
- No current M3 CP4 regression candidate remains active. CP4c starts from accepted 316 authority and exact next remains `M3-CP4c-CB`.

## M3-CP3b-TB-CAND-01 — remotely transported runtime draft was malformed YAML — RESOLVED ORCHESTRATION / NON-STABLE

- **Observed:** first schema-validation control `32513439436` rejected the remotely transported CP3b TB runtime draft before the acceptance workload could run. No generated Directional semantic runtime or acceptance artifact was produced.
- **Root cause:** control-plane transport did not preserve the intended workflow bytes, leaving malformed YAML; this is not package/source/test/fixture/selector authority.
- **Correction/evidence:** replace the corrupted draft with a compact byte-preserving workflow and require independent SchemaStore validation before publication. Final compact workflow blob `7a604bedc113b5b1c2f89038a18e22cd26c9b34e` passed schema run `32515108310` and authoritative acceptance run `32515222447` later completed **304/304 GREEN**.
- **Stable-count rationale:** pre-runtime orchestration only; acceptance attempt remained unconsumed until the valid 304 gate. Adds **0 stable events / 0 recurrences**; totals remain **41 / 14 / 27**.

## M3-CP3b-TB-CAND-02 — large payload/repair transport failed byte identity — RESOLVED ORCHESTRATION / NON-STABLE

- **Observed:** large runtime/repair-workflow payload transports did not reproduce the intended local bytes. Those controls were rejected before semantic runtime and were not accepted as workflow authority.
- **Root cause:** payload-size/transport integrity on temporary orchestration, not a CP3b product or test defect.
- **Correction/evidence:** author a smaller equivalent immutable-gate caller and transport it through Git blob creation; the resulting exact blob `7a604bedc113b5b1c2f89038a18e22cd26c9b34e` was reused unchanged for both validated payload and active runtime caller. Schema run `32515108310` and in-run validator `96875257718` passed before/with authoritative gate `32515222447 / 96875297990`.
- **Stable-count rationale:** all affected controls were pre-runtime/attempt-free. Adds **0 stable events / 0 recurrences**; totals remain **41 / 14 / 27**.

## M3-CP3b-TB-CAND-03 — closeout changed-path guard omitted a newly added untracked report — RESOLVED ORCHESTRATION / NON-STABLE

- **Observed:** first acceptance-documentation closeout `32516236265 / 96878457696` successfully decoded and applied the frozen documentation patch, then stopped before commit because `git diff --name-only` does not report a newly added untracked acceptance report. The guard therefore saw only four of five intended paths.
- **Root cause:** closeout changed-path oracle used a tracked-diff-only command before staging a new file. Semantic acceptance evidence was already complete and no generated Directional runtime executed in closeout.
- **Correction/evidence:** make the new file visible to the changed-path oracle with `git add -N` before comparing the exact five-path set, while retaining the same frozen documentation content plus this orchestration record.
- **Stable-count rationale:** documentation/control-plane only, post-acceptance; adds **0 stable events / 0 recurrences** and does not alter the accepted 304/304 gate. Totals remain **41 / 14 / 27**.

## M3-CP3b-TB-CAND-04 — compressed closeout payload transport corrupted before patch application — RESOLVED ORCHESTRATION / NON-STABLE

- **Observed:** corrected acceptance-documentation closeout `32518015056 / 96883932212` failed before `git apply` because the embedded base64/gzip patch transport was corrupted (`base64: invalid input`, gzip CRC and length errors). A first file-backed retry `32518441153 / 96885225368` reproduced the same truncation while decoding one large connector-created payload file. Neither produced a durable documentation commit or generated Directional runtime.
- **Root cause:** the large single-object text transport path was not byte-preserving across connector/workflow publication; the failure is administrative transport, not semantic acceptance.
- **Correction/evidence:** split the frozen compressed patch base64 into bounded deterministic chunks, concatenate them in lexical order, verify the concatenated base64 SHA-256 and decoded patch SHA-256, then apply the exact five-path patch. This removes the single-large-text transport assumption while preserving the locally verified documentation bytes.
- **Stable-count rationale:** post-acceptance documentation/control-plane only; adds **0 stable events / 0 recurrences** and does not alter the accepted 304/304 gate. Totals remain **41 / 14 / 27**.

## M3-CP3b-CB-CAND-01 — shrink-only vector resize required an unavailable default constructor — RESOLVED COMPILE-ONLY / NON-STABLE

- **Observed:** first two-target compile `32507150872 / 96849810459` on initial CP3b source `233b8e83be338e9a590c4aa5dfb220e9aa2119f2` failed while compiling `SurfaceCellTracing.cpp`: `std::vector<FieldAlignedCandidateTraceSegment>::resize(...)` instantiated a default-construction path, but `FieldAlignedCandidateTraceSegment` intentionally has no default constructor. No immutable package or generated Directional runtime was produced.
- **Root cause:** C++ container API misuse on a shrink-only operation, not an event-graph semantic defect.
- **Correction/evidence:** replace shrink-only `resize(contactIndex+1)` with iterator `erase(begin+contactIndex+1,end)` inside the already-authorized source file. Correction `32507540808 / 96851028033` produced source `611b3f8f3926792baee9d1078d6677d22006a6c4`; corrected-source precompile `32507660499 / 96851404185` and package `32508124000 / 96852846743` are green.
- **Stable-count rationale:** compile-time only; no accepted semantic behavior regressed and no generated runtime executed. Adds **0 stable events / 0 recurrences**; totals remain **41 / 14 / 27**.

## M3-CP3b-CB-CAND-02 — broad compile-marker glob matched correction control — RESOLVED ORCHESTRATION / NON-STABLE

- **Observed:** the first compile caller watched `m3-cp3b-cb-compile-*.txt`, which also matched the compile-correction marker. Run `32507540724` reached only its metadata resolver, failed there, and its compile job was **skipped**.
- **Root cause:** temporary workflow path-filter namespace overlap.
- **Correction/evidence:** narrow the compile caller to `m3-cp3b-cb-build-*.txt` and lock the corrected source. Authoritative precompile `32507660499` and package `32508124000` then ran through the corrected path.
- **Stable-count rationale:** orchestration-only with no generated Directional compile/runtime in the accidental run. Adds **0 stable events / 0 recurrences**; totals remain **41 / 14 / 27**.

## M3-CP3a-TB-CAND-01 — workflow registration/activation produced no observed TB runtime — RESOLVED ORCHESTRATION / NON-STABLE

- **Observed:** an earlier validated TB caller installation/trigger control did not produce an observed `M3-CP3a-TB` runtime. No workload job, GTest result, or semantic artifact was accepted from that control.
- **Classification/root cause:** orchestration/control-plane only. The exact registration/activation cause was not promoted into product/test authority because no generated Directional runtime executed and the final caller/trigger path superseded it.
- **Correction/evidence:** corrected active caller commit `2bc3bf38f9ef24509b9296f6d7928e397007cecc` plus separate trigger `887b4ad191baf8b4bf9ad2877900d3c18d935df1` produced authoritative run `32485441510`.
- **Stable-count rationale:** no accepted behavior loss and no semantic execution; adds **0 stable events / 0 recurrences**. Totals remain **41 / 14 / 27**.

## M3-CP3a-TB-CAND-02 — caller permission ceiling rejected reusable observer write permission — RESOLVED ORCHESTRATION / NON-STABLE

- **Observed:** an earlier TB caller granted `contents: read` while `agent-run-observer-reusable.yml` includes a `contents: write` job. The reusable-workflow permission ceiling was therefore invalid before acceptance runtime.
- **Root cause:** workflow permission mismatch only; no package/source/test/fixture/selector semantic defect.
- **Correction/evidence:** the caller was corrected to `contents: write`, exact corrected bytes were revalidated by schema run `32485281333`, and authoritative run `32485441510 / 96780835699` then completed **298/298 GREEN**. No generated Directional runtime occurred under the invalid caller.
- **Stable-count rationale:** pre-runtime orchestration only; adds **0 stable events / 0 recurrences**. Totals remain **41 / 14 / 27**.

## M3-CP3a-TB-CAND-03 — closeout stale-reference guard included temporary workflow control text — RESOLVED ORCHESTRATION / NON-STABLE

- **Observed:** documentation closeout run/job `32493625886 / 96806875476` passed workflow schema validation but stopped before any durable documentation commit because its stale-reference census also scanned `.github/workflows/agent-m3-cp3a-tb-closeout.yml`. That temporary workflow intentionally listed the exact superseded per-turn filenames in its staged-path guard.
- **Root cause:** the retained-document stale-reference oracle used a repository-wide text scan without excluding temporary workflow/payload control surfaces that are themselves scheduled for workflow-first cleanup. This is a closeout-oracle scope defect, not product/test authority.
- **Correction/evidence:** retain the same byte-frozen documentation transform, but scope the stale-reference census to retained documentation/content and exclude `.github/workflows/` plus `.agents/Directional/turn-payloads/`; the exact transformed documentation diff remains hash-locked by the work-preservation artifact.
- **Stable-count rationale:** documentation/control-plane only; no generated Directional runtime and no acceptance evidence changed. Adds **0 stable events / 0 recurrences**. Totals remain **41 / 14 / 27**.

## M3-CP3a-TB-CAND-04 — closeout compressed payload corrupted in connector transport — RESOLVED ORCHESTRATION / NON-STABLE

- **Observed:** closeout retry `32494245284 / 96808854595` passed schema validation but failed at `base64 -d ... | gzip -dc` with CRC/length errors before the documentation transform executed. No documentation commit was created.
- **Root cause:** control-plane payload transport corruption/truncation for the single large compressed transform blob; package/source/test/fixture/selector authority was untouched.
- **Correction/evidence:** transport the exact transform in independently bounded chunks, concatenate them only inside the closeout runner, and retain exact script SHA plus exact resulting documentation-diff SHA guards before commit.
- **Stable-count rationale:** pre-transform closeout orchestration only; no generated Directional runtime and no accepted behavior loss; adds **0 stable events / 0 recurrences**. Totals remain **41 / 14 / 27**.

## M3-CP3a-DG-CAND-01 — one-ring witness could not reach CP3a traversal seams — RESOLVED / TEST-AUTHORITY / NON-STABLE

- **Original evidence:** first DG `32445011345 / 96662902496` on old package `9432965083` was 2/6; three reds were upstream non-vacuity failures because every singularity attachment's first outgoing carrier was an outer-boundary barrier, so no multi-face crossing or populated `entryTransport` existed.
- **Root cause:** `RP-02 / TEST_AUTHORITY_COVERAGE_GAP`; the reused one-ring skew fan was topologically incapable of satisfying CP3a's required multi-face traversal witness.
- **Correction:** independent Review J1-J3 replaced the witness with a two-ring planar disc, derived matching/effort/index through `finalize_cross_field_result(...)`, and retained explicit `ASSERT_` non-vacuity for a multi-face trace with populated `entryTransport` plus a mandatory-barrier termination.
- **Resolution evidence:** final DG `32463985548 / 96716645034` on exact source/package `558a35c67919d54899c53de11dc9c69b6dfc9519 / 9435408599` executes the same six identities exactly once and passes **6/6**. The traversal, typed transport composition, ordering, binding rejection, and barrier-stop contracts all reach and pass on the corrected witness.
- **Stable-count rationale:** first-acceptance-only candidate; no accepted predecessor identity ran in either DG. Adds **0 stable events / 0 recurrences**; totals remain **41 / 14 / 27**.

## M3-CP3a-DG-CAND-02 — network semantic digest mixed semantic identity with gauge-sensitive atlas provenance — RESOLVED / ARCHITECTURE-PRODUCT / NON-STABLE

- **Original evidence:** first DG reached equivalent branch relabeling and showed equal `branch_topology().semantic_digest()` plus equal candidate traces but unequal enclosing network semantic digests, isolating the representation-dependent full atlas hash inside semantic identity.
- **Root cause:** `RP-05 / REPRESENTATION_DEPENDENT_IDENTITY`; one digest was carrying two domains: gauge-invariant network semantics and representation-dependent atlas binding/provenance.
- **Correction:** independent Review J4-J5 makes semantic identity consume `branch_topology().semantic_digest()` while retaining the full atlas hash separately for binding/provenance and preserving foreign/tampered-atlas rejection.
- **Resolution evidence:** final DG `32463985548 / 96716645034` passes `CandidateTraceIsInvariantToEquivalentBranchRelabeling` and independently passes `CandidateTraceRejectsForeignPortOrAtlasBinding` in the same **6/6** exact gate, proving the semantic/provenance split did not delete the binding check.
- **Stable-count rationale:** first-acceptance-only candidate; accepted predecessor not executed. Adds **0 stable events / 0 recurrences**; totals remain **41 / 14 / 27**.

## PR8-R040 / M3-CP2b-R001 — singularity local ports inherit four-label representation identity — RESOLVED STABLE / RECURRENCE

- **Original loss:** corrected immutable `M3-CP2b-TB` `32317745051 / 96274463944` was **285/292**. Two identities accepted green in CP2 were red: `FieldAlignedCurveNetwork.PublishesTypedSingularityPortsAndMandatoryGraph` and `FieldAlignedCurveNetwork.RejectsInvalidSingularityPortOwnershipOrCount`; four new CP2b identities also failed at baseline atlas construction.
- **Primary category:** `RP-05 / REPRESENTATION_DEPENDENT_IDENTITY`; detection escape `RP-02 / TEST_AUTHORITY_COVERAGE_GAP`.
- **Root cause:** attempt 1 derived semantic local-port identity from four branch-label starts and representation-level tuple deduplication rather than canonical fan/transport equivalence.
- **Correction:** R1 replaced that path with typed incident-fan incidences quotiented by reciprocal branch transport, requiring exactly `4-indexNumerator` semantic classes and topology-only representative/slot ordering.
- **Resolution evidence:** authoritative `M3-CP2b-TB-R1` `32324880480 / 96294021816` restores accepted CP2 **6/6**, including both formerly red network identities. `FieldTransportAtlas.PublishesCheckedSingularityPortAttachments` is green and proves the skew index-1 path now publishes exactly three checked local attachments with contiguous slots. The remaining CP2b reds have different first-acceptance causes recorded below.
- **Stable-count rationale:** this remains the same historical stable event/recurrence already counted at attempt 1. Resolution does not erase incidence. Historical totals remain **41 / 14 / 27**.

## PR8-R041 / M3-CP2b-R002 — dependent port validation masks accepted singularity diagnostic — RESOLVED STABLE / RECURRENCE

- **Original loss:** accepted CP1 A1 identity `FieldTransportAtlas.IndependentOracleRejectsCompleteTypedTamperMatrix` was red in corrected attempt-1 CP2b TB because a singularity tamper expected `SingularityMismatch` but dependent attachment validation returned `InvalidSingularityPortAttachment` first.
- **Primary category:** `RP-03 / POLICY_STAGE_STATE_CONFLATION`; detection escape `RP-02 / TEST_AUTHORITY_COVERAGE_GAP`.
- **Root cause:** the expanded independent oracle validated dependent singularity-port attachments before reconstructing/validating the singularity facts on which those attachments depend.
- **Correction:** R1 validates raw/published singularity facts first and only then validates dependent branch-topology attachments; dedicated branch/attachment tamper checks remain strict.
- **Resolution evidence:** authoritative `M3-CP2b-TB-R1` restores accepted CP1 A1 **6/6**, including `IndependentOracleRejectsCompleteTypedTamperMatrix`, so the accepted `SingularityMismatch` diagnostic contract is restored.
- **Stable-count rationale:** same historical stable event/recurrence; resolution does not decrement totals. Historical totals remain **41 / 14 / 27**.

## M3-CP2b-TB-CAND-01 — first immutable caller materialized fixtures at wrong compiled source root — RESOLVED ORCHESTRATION / NON-STABLE

- **Observed:** initial TB control `32317379701 / 96272468253` selected all 292 identities exactly once but additionally lost 26 M1 producer tests to fixture file-open/setup errors. The precompiled binaries embed the Code + Build workspace source root; the first caller extracted the embedded package source under runner temp instead.
- **Correction/evidence:** control-only retry used the same package and exact selector and materialized the exact embedded source at the compiled workspace path. Authoritative retry `32317745051 / 96274463944` restores M1 producer **138/138**. No package/source/test/fixture/selector semantic mutation occurred.
- **Stable-count rationale:** orchestration only, so **0 stable events / 0 recurrences**. The retry's final shell status-propagation step had an empty local exit-code read, but the runtime step returned failure and the complete result artifact unambiguously records the semantic 285/292 gate; no second runtime retry is needed.
- **Disposition:** RESOLVED NON-STABLE.

## M3-CP2b-TB-CAND-02 — new CP2b positives fail at baseline atlas construction — RESOLVED/SUPERSEDED SEMANTIC / NON-STABLE

- **Original observation:** four first-runtime CP2b identities failed because attempt-1 index-1 `FieldTransportAtlas::make(...)` rejected before their intended positive/oracle assertions.
- **Original root cause:** same singularity local-port representation-identity defect as stable `PR8-R040 / M3-CP2b-R001`.
- **R1 resolution boundary:** `PublishesCheckedSingularityPortAttachments` is green and baseline atlas construction now succeeds through the three-port seam. The remaining three R1 reds do not share the original four-label cardinality cause; they are split into the two candidates below.
- **Stable-count rationale:** first-acceptance CP2b contracts, so **0 stable events / 0 recurrences** independently.
- **Disposition:** RESOLVED/SUPERSEDED NON-STABLE.

## M3-CP2b-TB-R3-CAND-01 — local harness used Bash special `GROUPS` variable before runtime — RESOLVED ORCHESTRATION / NON-STABLE

- **Observed:** the first local TB-R3 control passed immutable package/selector preflight, then the harness array name `GROUPS` resolved to Bash's special group-ID array. The first run specification became `0`; the control attempted the package `bin/` directory, produced no GTest JSON, and stopped before any generated Directional binary executed.
- **Root cause:** local harness variable-name collision only; no package, source, test, fixture, selector, or expected-result semantic defect.
- **Correction/evidence:** rename the harness array to `RUN_GROUPS`; corrected harness SHA-256 `93d197608efce08001d4ecf76991bd70c45299a9a2d265434e4d0d38a8446131`. The same immutable package then produced the valid **292/292 selected, 288/292** gate with accepted predecessor **287/287** and byte-identical postflight.
- **Attempt/stable-count rationale:** the first control produced no valid semantic gate and executed no generated test binary, so it consumed **0 attempts** and adds **0 stable events / 0 recurrences**.
- **Disposition:** RESOLVED ORCHESTRATION / NON-STABLE.

## M3-CP2b-TB-R1-CAND-01 — equivalent Z4 relabel oracle conflates raw and canonical transport — RESOLVED / TEST-AUTHORITY / NON-STABLE

- **R1 observation:** `BranchTopologyIsInvariantToEquivalentZ4Relabeling` reached its non-vacuous relabel setup. Raw directions and matching changed; canonical frames and singularity-port attachments remained equal; canonical branch transport equality failed and semantic digest changed from `10784329413325343822` to `1098805676228837734`.
- **Primary category:** `RP-05 / REPRESENTATION_DEPENDENT_IDENTITY`.
- **R1 root cause:** CP2b R1 published an unnormalized raw/gauge integer lift even after reducing semantic transport to `QuarterTurn`; equivalent Z4 gauges could therefore differ by `4*k` in equality/hash representation.
- **R2 product change:** exact source `90c737e11c340061dd0167eaf59fec66afa0c8ba` preserves accepted CP1 raw adjacency lift semantics and changes only nested CP2b publication: topology-oriented lift is reduced to `QuarterTurn`, then `forwardLift` is the canonical `[0,3]` representative `static_cast<int>(forward.value())`.
- **TB-R2 disposition:** **UNADJUDICATED.** Immutable TB-R2 `32331037070 / 96311550091` failed inside the old helper before relabeled atlas/transport equality or semantic digest.
- **DG disposition:** **STILL UNADJUDICATED.** `M3-CP2b-DG` `32344594021 / 96350536107` again fails inside `make_skew_index_one_singularity_field(...)`, now at producer singularity-cardinality assertion line 1699, before the baseline atlas and relabel comparison. The R2 `[0,3]` product normalization therefore still has no runtime adjudication after the C1 fixture strategy.
- **DG-R4 disposition:** **STILL UNADJUDICATED.** Final diagnostic `32380986195 / 96463857157` clears the producer-derived helper for every CP2b identity, but `BranchTopologyIsInvariantToEquivalentZ4Relabeling` fails its valid-baseline `FieldTransportAtlas::make(...)` before the relabeled atlas, transport equality, or semantic digest seam. Part D therefore retains CAND-01 and authorizes diagnostics rather than a semantic fix.
- **TB-R3 disposition:** **STILL UNADJUDICATED.** Instrumented R5 runtime names the earlier baseline rejection as `DuplicateSingularityPortRepresentative` at edge `(0,1)`, face `0`, vertex `4`, region `0`. The relabeled atlas, branch-transport equality, and semantic-digest seam are still not reached, so the R2 `[0,3]` normalization remains neither accepted nor rejected by runtime.
- **TB-R4 evidence:** the valid R6 gate finally reaches the equivalent-Z4 relabel seam. Baseline and relabeled `FieldTransportAtlas::make(...)` both succeed. The sole failure is `tests/FieldTransportAtlasTests.cpp:2290`, where `independent_validate_snapshot(... relabeledField ..., independent_snapshot(relabeled.value()))` returns an error although the test expects validity. Because the assertion is non-fatal, execution continues: branch frames compare equal, branch transports compare equal, every `forwardLift` is canonical `[0,3]` and reciprocal, singularity-port attachments compare equal, semantic digests compare equal, and nonzero transport is present. The R2 production normalization is therefore runtime-exercised; the remaining contradiction is narrowed to the independent-validator relabel seam and requires static Review classification before any correction.
- **Part-G Review classification:** **TEST-AUTHORITY.** The identity simultaneously requires raw matching to change under gauge relabel, published branch transport to remain invariant, and raw matching to equal the canonical published lift. Those three requirements are contradictory. Product publication deliberately adds gauge, applies canonical topology orientation, and stores the unique `[0,3]` Z4 representative; all direct invariance assertions being green positively support that product contract. The independent validator's exact raw/canonical equality was the defect, not the product.
- **CB-R7 correction:** semantic edit `9316cc5a7c323ba6cf5235a9f89fc32be3cf96f0`, fixed compile/package source `1d2417c90970db81f8b49dd6e0961868cac32369`, immutable package `9428451548`. Exactly `tests/FieldTransportAtlasTests.cpp` changed semantically. The oracle derives its own face gauge from mesh/field authority, applies its own canonical orientation, reduces through Z4, and corrects all three related comparisons together. Existing tamper rejections remain statically pinned; H4 requires `forwardLift +1` rejection and accepts `+4` as an equivalent representative. Product source remained frozen.
- **TB-R5 resolution evidence:** immutable `32434684618 / 96633374819` executes the frozen 292-selector exactly once per identity and passes **292/292**: accepted predecessor **287/287**, CP2b **5/5**. `BranchTopologyIsInvariantToEquivalentZ4Relabeling` and `IndependentOracleRejectsBranchPairingOrPortAttachmentTamper` both pass; the non-degenerate 5-incidence/3-class partition remains unchanged; package and materialized source are byte-identical pre/post. Result/log `9430381177 / 9430381560` have SHA-256 `41292ffef7231ef7010bd416aa6b730fd6022694933bc0c4b538abadb64bf8be / a789a6567c865e119deef69c295894078ce2621f7972912666c726b1b6b886a4`. **Disposition: RESOLVED / TEST-AUTHORITY / NON-STABLE.**
- **Stable-count rationale:** no accepted predecessor regression and the defect was in first-acceptance independent test authority; adds **0 stable events / 0 recurrences**. Historical totals remain **41 / 14 / 27**.

## M3-CP2b-TB-R1-CAND-02 — duplicate singularity representative key omitted branch — RESOLVED / ARCHITECTURE-PRODUCT / NON-STABLE

- **R1 observation:** `PublishesCanonicalBranchFramesAndBoundaryPairings` reached publication assertions but independent baseline validation rejected; `IndependentOracleRejectsBranchPairingOrPortAttachmentTamper` failed baseline validity before either intended tamper seam.
- **Primary category:** `RP-02 / TEST_AUTHORITY_COVERAGE_GAP`.
- **R1 root cause:** the helper manually injected nonzero transition matching/effort into otherwise identical coplanar face directions, contradicting independent geometric reconstruction.
- **R2 refinement:** non-degenerate directions were introduced, but the helper still assigned its nonzero closing seam using a hard-coded ordered face pair while verification used the signed cycle row. Mesh-owned `EF(edge,0) -> EF(edge,1)` orientation reversed that seam, so matching remained zero and the center index was not 1.
- **Mandatory-review C1 correction:** CB-R3 exact source `c608f77588a43c388bed81295d6cde0977b1c8cd` stopped hand-authoring matching/effort/index. Accepted `finalize_cross_field_result(..., false, true)` derives them from authored non-degenerate directions; the helper independently checks each published transition against mesh orientation and reconstructs the signed center cycle.
- **DG evidence:** attempt-free `32344594021 / 96350536107` executes all five CP2b identities exactly once on package `9395219896`. The helper reaches past every transition/matching assertion and past `orientedEffort ~= 2*pi` and `exactIndex ~= 1`, proving the R2 orientation failure is resolved. It then fails at line 1699 because `field.singularCycles.size()` is **5**, expected **1**. All five identities stop there before their intended semantic seams.
- **Refined root cause:** the open four-triangle disk witness conflates “center cycle has index +1” with “producer emits exactly one singular vertex entry.” `dual_cycles(...)` maps boundary vertices to the aggregate boundary cycle, and `effort_to_indices(CartesianField&)` publishes each local vertex whose mapped cycle index is nonzero. The accepted producer therefore exposes boundary-cycle singular entries as well as the center. This is a witness-domain/cardinality assumption, not another transition convention defect.
- **Architecture consequence:** `FieldTransportAtlas::make(...)` consumes every published singular entry as a `FieldSingularityFact`, while local port construction expects an ordered closed incident fan. Whether boundary singularities are valid CP2b inputs, require an architecture-owned filter/type, or make the open fan the wrong witness domain must be decided by rescope Review; deleting the size assertion is not authorized as a fixture-side filter.
- **Rescope Review / R4 correction:** Part C of `Architecture_M3_CP2b_Witness_Rescope_Review_Plan.md` reclassified the active cause as architecture/product: A1 already owns boundary-loop index as a typed `BoundaryLoop` witness but also admitted aliased boundary-vertex entries as separate singularity facts, and CP2b's attachment valence range diverged from accepted CP2. CB-R4 exact source `93f55536727dbf76504aa29f7835edc8cebaee0c` implements reconcile-before-drop E1, accepted-range E2, derived interior fixture assertion E3, and reconciliation negative E4. Compile/package evidence is green/runtime-free; runtime adjudication is pending the second DG on package `9404970614`.
- **DG-R4 evidence:** final attempt-free `32380986195 / 96463857157` executes all five CP2b identities once on package/source `9404970614 / 93f55536727dbf76504aa29f7835edc8cebaee0c`. Every identity clears the producer-derived helper, including the exact centre `+1` and exactly-one-interior-singularity checks. This runtime-discharges the remaining fixture-authority precondition. Four positive identities then fail only when the valid baseline calls `FieldTransportAtlas::make(...)`; the negative ambiguous/incomplete identity is reached-and-passing but is not credited while the valid baseline also fails.
- **Semantic Review refinement:** Part D reclassifies the live blocker as **architecture/product diagnosability plus an unnamed valid-baseline rejection**, not fixture authority. The positives discard `FieldAtlasBuildError`, while the compound branch-frame/singularity-attachment builders collapse many guards into opaque codes and discard existing locus fields. F1/F2 instrumentation is required before a semantic cause may be asserted. Part E corrects the implementation surface to include the public enum header required by F2; no guard logic change is authorized.
- **TB-R3 evidence:** valid immutable R5 gate is **288/292** with accepted predecessor **287/287**. All four positive identities report `DuplicateSingularityPortRepresentative; sourceEdge=(0,1); sourceFace=0; sourceVertex=4; topologyRegion=0`. Static ordering proves the class-count guard passed, one representative per class was elected, and the final cross-class uniqueness check found two representatives sharing the old `(startFace, firstOutgoingCarrier)` key.
- **Semantic Review result:** Historical TB-R3 Review Part F (recorded in `CHANGELOG.md`) reproduces the collision from frozen geometry. Face 0's 115.647-degree sector contains two 90-degree-spaced rays; those incidences share `startFace` and carrier and differ only in `branch`. The old key is structurally rank-one and production-relevant at ordinary valence-3 `+1` cones.
- **CB-R6 correction evidence:** exact source `9fdb928fe872190b27aa6022b43608eeccf329e4` preserves incidence generation and union-find equivalence, publishes every incidence/class/adjacency lift before later rejection, and widens representative identity/order to `(startFace, branch, firstOutgoingCarrier)`. G3 is discharged statically because the TB-R3 duplicate guard is cross-class by construction: it runs only after one representative per class is elected. Independent G4 coverage requires a legitimate pair sharing `(startFace, carrier)` while differing in branch and separately rejects an exact three-field duplicate. Mandatory pre-package and full package compiles are green; immutable package `9422702053` is runtime-free.
- **TB-R4 resolution evidence:** immutable `32418067075 / 96583693356` publishes the predicted centre partition exactly: five incidences, three classes, with face-0 branch `2` / carrier `(0,1)` in class `0` and face-0 branch `3` / the same carrier in class `1`. All five emitted partition blocks agree. `PublishesCheckedSingularityPortAttachments` passes its legitimate same-face/same-carrier/different-branch representative proof and its exact three-field duplicate rejection in the same package. The corrected key is therefore runtime-proven without changing incidence generation or union-find equivalence.
- **Disposition:** **RESOLVED / ARCHITECTURE-PRODUCT / NON-STABLE.** The runtime partition confirms the Review's Reading A and discharges the bounded R6 correction. This resolution does not imply CP2b acceptance because CAND-01 still leaves one frozen CP2b identity red.
- **Stable-count rationale:** all five affected identities are new CP2b first-acceptance contracts and DG intentionally did not execute the accepted 287-selector, so this adds **0 stable events / 0 recurrences**. Historical totals remain **41 / 14 / 27**.

## PR8-R039 / M3-CP2-R001 — closed authoritative rail cycle linearized as an open path — RESOLVED STABLE / RECURRENCE

- **Observed loss:** original immutable CP2 TB `32289400790 / 96186521474` was **270/287**. All six CP2 contracts and all six CP1 A1 contracts passed, but 17 retained M1 producer identities that were green in accepted CP1 failed at `surface-cells/NotProductionReady:field-aligned-network/InvalidRailGeometry`.
- **Primary category:** `RP-07 / CYCLIC_TOPOLOGY_LINEARIZATION`; detection escape `RP-02 / TEST_AUTHORITY_COVERAGE_GAP`.
- **Root cause:** CP2 applied the open-path contract `|V|=|E|+1` and endpoint `sourceVertices[i+1]` to canonical closed rails published as `closed=true`, `|V|=|E|`; the final closed interval is the wraparound edge.
- **Correction:** CP2-R1 exact source `5a284388d360efa4ce1bd37bc584165e1db0157b` preserves open-path cardinality, accepts canonical closed rails only at minimum three edges, uses modulo wraparound only for closed intervals, and strengthens the existing ordering identity with a real four-edge closed boundary plus exact mandatory-edge/kind cross-closure proof.
- **Resolution evidence:** immutable `M3-CP2-TB-R1` `32300950126 / 96223162140` consumed package `9382182983` directly and passed **287/287**: CP2 **6/6**, CP1 A1 **6/6**, retained M2 **275/275**, M1 producer **138/138**, `failedIdentities=[]`. Result/log `9383055423 / 9383056029` have outer SHA-256 `9f1be41dacb8041ebb49468c6df2c3b44d35c026796ec94cca5caf86cb7dbf46 / 34b30b4ad63873e7144d31b595c09ba2201788057671e260ac4d30829003c48f`.
- **F2 closed-rail cross-closure:** the strengthened positive identity explicitly proves no foreign mandatory edge, complete mandatory-edge coverage, and exact mandatory kind agreement. Runtime failing-diagnostic counts are `ForeignMandatoryEdge=0`, `MissingMandatoryEdge=0`, `MandatoryKindMismatch=0`, as expected for the green positive witness; those zero counts are not a substitute for the explicit assertions.
- **Immutability:** package and materialized source were byte-identical after runtime; repository checkout, rebuild, relink, repair, source/test/fixture mutation, generated discovery, benchmark execution, package mutation, and materialized-source mutation were all false.
- **Disposition:** **RESOLVED.** CP2-R1 attempt **1 of 3** succeeded; no retry or mandatory review is required. Resolution does not erase historical incidence, so totals remain **39 events / 14 categories / 25 recurrences** and produced-witness debt remains **5**.

## PR8-R038 / M3-CP1-R001 — explicit sparse-zero cycle support polluted curvature authority — RESOLVED STABLE / RECURRENCE

- **Observed loss:** package 4 immutable TB was **256/281**, package 5 R1 improved to **258/281**, and package 6 R2 remained **258/281**. R2 retained accepted M2 was **255/275**, with all 20 remaining predecessor losses in M1 producer (**118/138**) behind `InvalidFieldTransportAtlas:field-transport-atlas/CycleTransportMismatch` or dependent early-rejection effects.
- **Primary category:** `RP-01 / AUTHORITY_DOMAIN_CONFLATION`; detection escape `RP-02 / TEST_AUTHORITY_COVERAGE_GAP`.
- **Resolved root cause:** `dual_cycles` aggregates signed integer-incidence cycle rows through sparse multiplication. Opposite `-1/+1` incidence can cancel algebraically to exact `0.0` while Eigen retains the zero as a stored sparse entry. `FieldTransportAtlas` already ignored that representation-only zero when composing semantic cycle transport, but `MeshTopology.cpp` iterated the stored zero while building `cornerSets` / `vertexSets`; because `0.0 < 0` is false, it took the positive-sign branch and polluted `cycleCurvature`. Atlas therefore derived `turningLift` from a different effective support than the typed transport comparison.
- **Correction:** R5 exact source `9f7e222bab6c930a12d1369fa2aee869f5c0dcff` canonicalizes only exact algebraic-zero entries from the final cycle basis immediately after aggregation/slicing and before curvature iteration. It uses exact `value != 0.0`, not a tolerance, so no nonzero cycle coefficient is erased. The existing square A1 witness was strengthened to independently prove zero semantic interior support, identity composed transport, exact corrected boundary lift `4`, and oracle agreement. The A1 congruence and hard production gate remain intact.
- **Resolution evidence:** immutable `M3-CP1-TB-R3` `32263614534 / 96102598799` consumes `9f7e222bab6c930a12d1369fa2aee869f5c0dcff / 9366752046` and passes **281/281** with A1 **6/6**, retained M2 **275/275**, and retained M1 producer **138/138**. `failedIdentities=[]`. Package and materialized source postflight are byte-identical; no rebuild, relink, repair, source/test/fixture mutation, generated discovery, or benchmark execution occurred.
- **Disposition:** RESOLVED. CP1 is accepted on package 7. The accepted runtime proves the shared sparse-support correction restores every retained predecessor identity lost under this regression while satisfying all six A1 contracts.
- **Stable-count rationale:** this remains the same historical accepted-behavior loss and recurrence already counted as `PR8-R038`; resolution does not add, remove, or decrement historical incidence. Totals remain **38 events / 14 categories / 24 recurrences**; produced-witness debt remains **5**.

## M3-CP1-TB-CAND-01 — new A1 positives/oracles failed at baseline atlas construction — RESOLVED SEMANTIC / NON-STABLE

- **Original observation:** package-6 R2 A1 was **3/6**. `FieldTransportAtlas.PublishesReciprocalTypedAuthorityAndRelativeBoundaryWitness`, `FieldTransportAtlas.IndependentOracleRejectsCompleteTypedTamperMatrix`, and `FieldTransportAtlas.IndependentTreeCotreeOracleSurvivesRowAndBranchRelabeling` failed because baseline atlas construction rejected before their intended positive/oracle proof.
- **Root cause:** the same explicit sparse-zero support contamination recorded by `PR8-R038 / M3-CP1-R001`; these first-runtime A1 contracts exposed the producer defect directly.
- **Resolution evidence:** immutable TB-R3 `32263614534 / 96102598799` selects all six frozen A1 identities exactly once and passes **6/6**. The three formerly red positives/oracles now reach and satisfy their intended contracts; combined gate is **281/281**.
- **Stable-count rationale:** these were new M3 acceptance contracts with no accepted-green CP1 predecessor, so they remain non-stable evidence and add **0** stable events / **0** recurrences. Historical totals remain **38 / 14 / 24**.
- **Disposition:** RESOLVED NON-STABLE. No A1 candidate remains open from CP1.

## PR8-R037 / M2-CP4-R001 — declared-product invalid-patch guard collapses canonical rebuild sub-invariant diagnostics — RESOLVED STABLE / RECURRENCE

- **Original observation:** `M2-CP4-TB-R1` `32175491853 / 95836337325` on `8cd82a63f00bd53aee3c7e01f4bef0c258b21ef3 / 9336162929` was frozen M1 **233/234** because `SurfaceCellAuthorityContractCutover.AggregateIdentityRebuildReportsInvalidPatchMetadataSubInvariant` retained stage/reason but lost `surfaceCellFirstInvalidProducerCell`, while static M2 remained **K=0**.
- **Root cause:** CP4 correctly moved the invalid-completed-patch guard from the diagnostic context shadow to declared `componentProducts.completedPatches`, but the earlier guard discarded which patch failed and returned before the later canonical rebuild could publish the failing patch index.
- **Correction:** user-authorized CP4-R1 source `9fda64e88ddc885ce993ff8da3ad6a51765724a4` uses the declared product to locate the offending completed patch and publishes its index at the same `AggregateIdentityInvalidPatchMetadata` rejection. It restores no semantic `surfaceCellContext` read and introduces no second authority.
- **Resolution evidence:** immutable `M2-CP4-TB-R2` `32183306224 / 95861164621` consumes package `9340456431`; the exact formerly red identity passes inside M1 producer **138/138**, frozen M1 is **234/234**, total required-green is **275/275**, and regenerated M2 static closure is **K=0** with direct semantic context refs **0** and CP3 forbidden reads **0**.
- **Stable-count rationale:** the event remains a historical stable recurrence of `RP-03 / POLICY_STAGE_STATE_CONFLATION`; resolution does not erase or decrement historical incidence. Totals remain **37 events / 14 categories / 23 recurrences**. Produced-witness debt remains **5**.

## M2-CP4-TB-CAND-01 — rail closed-product witness fails source-mesh setup before typed rejection seam — RESOLVED TEST-AUTHORITY / FIXTURE-PRECONDITION / NON-STABLE

- **Original observation:** the CP4-R1 predecessor witness used a one-triangle `TriMesh::set_mesh` substrate and threw a DCEL consistency failure before `build_authoritative_surface_cell_rails(...)`, so CP4 was **1/2** and the intended typed rejection was non-evidence.
- **Correction:** CP4-R1 reuses the already established rectangular internal hard-feature grid substrate, retains `edge.incidentFaces = {-1}` as the only counterfactual, and keeps the strict typed `Rejected<SurfaceCellRailBuildFailure>` / `InvalidFeatureEdge` / failed-edge evidence assertions.
- **Resolution evidence:** `M2-CP4-TB-R2` selects `SurfaceCellClosedProductContracts.RailBuildRejectionCarriesFailureWithoutConsumableRails` exactly once and it passes; the CP4 pair is **2/2**. The witness therefore reaches the intended seam and proves the closed rejection contract without a consumable rail product.
- **Stable-count rationale:** this was a new acceptance-fixture precondition gap with no accepted-green predecessor, not lost product behavior. Resolution adds **0** stable events and **0** recurrences. Historical totals remain **37 / 14 / 23**.

## M2-CP4-TB-CAND-02 — initial TB harness assigns CP1/CP2 selectors to wrong owner executable — RESOLVED ORCHESTRATION / NON-STABLE

- **Observed:** first immutable CP4 control `32175260213 / 95835604030` verifies exact package and M1 artifact digests, recursive manifest, source identity/status, selector digests, and static M2 closure, then executes the CP4 pair and reproduces the rail-witness setup failure. It subsequently stops because the temporary harness invokes the accepted CP1/CP2 selectors through `directional_surface_cell_producer_tests`, yielding zero CP1 selection; accepted CP3 TB authority shows those selectors are owned by `directional_surface_cell_completion_tests`.
- **Correction/evidence:** retry harness changes only that owner mapping. `M2-CP4-TB-R1` `32175491853 / 95836337325` verifies both frozen payload blobs, re-verifies the immutable package, executes the complete 275-name gate, and exposes the two real red identities. Initial result/log `9338766391 / 9338767015`; authoritative retry result/log `9338923657 / 9338924194`.
- **Stable-count rationale:** test-control orchestration only; no package/source/test/fixture/selector semantic mutation and no accepted behavior loss. New stable events **0**, recurrences **0**. Totals remain **37 / 14 / 23**.

## M2-CP3-TB-CAND-01 — counterfactual aggregation seam stayed bound to legacy context shadow after declared-product read cutover — RESOLVED TEST-AUTHORITY / MIGRATION-SEAM / NON-STABLE

- **Observed:** immutable CP3 gate `32139341913 / 95718023464` consumes exact `dc837f7ac529c55aa7ba4775621e3b681f74d36b / 9322254546` and passes package/source immutability plus CP3 static read elimination, CP1 **5/5**, CP2 **34/34**, M1 authority **19/19**, completion **36/36**, and validation **41/41**. M1 producer is **135/138**, so combined required-green is **270/273**. Result/log `9325322211 / 9325322646` have SHA-256 `db12e52c5b6236c9db1e823ef93988d94b0cd0fae13b9bd961231795a6caa9bd / 2e78d926ffc24d4881064428db4d1ad7175aeff7ce30347575d404fcb77360b7`. The exact reds are `SurfaceCellAuthorityContractCutover.DisconnectedAggregationDoesNotPublishStalePreRemapIdentityCaches`, `SurfaceCellAuthorityContractCutover.AggregateIdentityRebuildReportsInvalidPatchMetadataSubInvariant`, and `SurfaceCellAuthorityContractCutover.FinalOracleOutcomePublishesWhenComponentValidationReportIsMissing`.
- **Accepted-baseline differential:** no new predecessor run is needed to establish loss: these exact identities are members of frozen M1 and passed in accepted CP2 final gate `32119584283 / 95656737849`, whose combined required-green is **273/273**. CP3 `include/**` and `tests/**` are byte-identical to accepted CP2 and only `src/pipeline/RemeshPipeline.cpp` changed in the bounded production source delta.
- **Root cause:** CP3 correctly captures aggregation semantics into `ComponentRun::stageProducts` and later binds `componentProducts = runs[index].stageProducts`, but the existing `ComponentAggregationInputMutator` API still exposes only `RemeshResult &` and executes after sidecar capture. The frozen counterfactual callbacks therefore mutate legacy `surfaceCellContext` shadows while the production aggregate consumes untouched declared stage products. The stale-cache fixture creates a mixed lineage/shadow counterfactual; invalid patch metadata reaches only the retained shallow shadow guard rather than the canonical product rebuild; clearing the context validation flag cannot change `componentProducts.validationResult` completeness.
- **Correction / Code + Build evidence:** the user explicitly authorized one bounded R1 package. Exact source `0a06127555405abef474af501e2bd09de3320c1b` changes the counterfactual signature to receive `SurfaceCellComponentStageProducts &` directly, passes `runs[index].stageProducts` at the hook, migrates all 11 callbacks, and points exactly the three rejected frozen mutations at declared stage-product authority. No context-to-product reconstruction or assertion weakening was introduced. Runtime-free `32147101079 / 95743427238` completed **117/117** and packaged `9328335558` / `8f75d835e4461ba1dabda91793a88f265e9c00de752a17ec8906943f70f9ced2`; log `9328336222` / `687d395877d92f940cd4f1dd477846ffcc5b6a1f31d39c2546044ea32140a04b`. This structurally remediates the injection seam but does **not** resolve the candidate until immutable TB-R1 restores the accepted gate and proves the intended mutations are non-vacuous.
- **Resolution / TB-R1 evidence:** immutable `32150796184 / 95755876548` consumes exact `0a06127555405abef474af501e2bd09de3320c1b / 9328335558`. The three formerly red identities pass an explicit **3/3** focused run and pass again inside frozen M1 producer **138/138**; frozen M1 is **234/234**, CP1 **5/5**, CP2 **34/34**, combined **273/273**. CP3 static read elimination remains `forbiddenRemaining=0` with 31 remaining refs classified diagnostic/memory or explicit shadow guards. No rebuild, relink, repair, source/test/fixture mutation, generated discovery, or benchmark occurred. The migration-seam candidate is therefore resolved without restoring context-to-product backflow or weakening tests.
- **Stable-count rationale:** the rejected CP3 behavior was isolated to the counterfactual/test-authority seam and is now restored by migrating that seam to declared stage-product authority. TB-R1 observes no product regression. New stable events **0**, recurrences **0**; at that checkpoint totals remained **36 / 14 / 22**, produced-witness debt **5**.

## M2-CP2-TB-CAND-02 — broad changed-block coverage mechanically promoted 12 inherited reds — RESOLVED TEST-AUTHORITY / INHERITED-RED PROMOTION / NON-STABLE

- **Observed:** valid CP2 control `32118066037 / 95651990590` preserved frozen M1 **234/234** and CP1 **5/5**, while a mechanically assembled 46-test changed-block candidate set was **34/46**. Exact accepted-predecessor differential `32118624560` consumed accepted CP1 package `9309981828` and reproduced the same 12 identities as **12/12 red with the same failure modes**. Final authoritative run `32119584283 / 95656737849` re-proved that differential, then executed the corrected CP2 required selector at **34/34**.
- **Exact inherited-red identities:** `FlowRepStrandsPhase15.EndpointCompletionExtendsToRetainedSameSheetNetwork`; `FlowRepStrandsPhase15.EndpointCompletionIgnoresSubToleranceIntersectionAtTraceOrigin`; `FlowRepStrandsPhase15.EndpointCompletionOnlyCommitsArrangementReproducibleIntersections`; `FlowRepStrandsPhase15.SubToleranceIntrinsicCaptureReconcilesOpenEndpointWithoutTinyArc`; `FlowRepStrandsPhase15.AdjacentFaceFanCanonicalizesSubToleranceEndpointsToSourceVertex`; `FlowRepStrandsPhase15.OpenHardFeatureEndpointsExtendWithoutRemovingAuthoritativeRail`; `PatchDescriptorMilestoneE.GlobalDescriptorAssignmentRejectsAmbiguousInteriorSingularity`; `PatchDescriptorMilestoneE.ComplexCompletionFailsClosedInsteadOfReturningPartialOutput`; `PatchDescriptorMilestoneE.WholeComplexParallelRouteRepairCompletesWithinOneGlobalLedger`; `PatchDescriptorMilestoneE.SemanticOnlySameCornerOverlapFailsBeforeCandidateExpansion`; `PatchDescriptorMilestoneE.ZeroStructuralBudgetFailsBeforeCandidateExpansion`; `PatchDescriptorMilestoneE.StructuralRepairLedgerIsPatchOrderInvariant`.
- **Root cause / correction:** source-block proximity was incorrectly treated as sufficient authority to promote every touched-block identity into required-green acceptance. The architecture plan had not frozen a 46-test selector. The corrected required selector contains the 34 non-overlapping, non-inherited-red CP2 identities at SHA-256 `53f5bf57a2edb1c68260186b85964022cd034a899a51bcbf740a37d1c4815c0d`; the 12 inherited reds remain visible/non-gating. No assertion, test, or fixture was weakened or mutated.
- **Stable-count rationale:** every red identity was already red on the accepted CP1 predecessor, so no accepted-green behavior was lost. New stable events **0**, recurrences **0**; at that checkpoint totals remained **36 / 14 / 22**; produced-witness debt remains **5**.

## M2-CP2-TB-CAND-01 — immutable package source not materialized at compiled fixture path — RESOLVED ORCHESTRATION / NON-STABLE

- **Observed:** first CP2 TB control `32117669340 / 95650752285` verified immutable package integrity but produced 26 false M1 producer reds because fixture-relative paths compiled against `/home/runner/work/Directional/Directional` had no materialized package source tree. A later final-control variant reproduced the same orchestration class when source was extracted to a different runner-temp directory.
- **Root cause / correction:** artifact-only runtime still requires the immutable source archive at the absolute fixture path embedded in the compiled tests. Corrected controls materialize the exact package source archive at that path without checkout or source mutation. Valid run `32118066037` restored frozen M1 to **234/234**, and final run `32119584283` confirms **273/273** required-green.
- **Stable-count rationale:** control-plane/runtime-environment only; no product/test/fixture/package semantic mutation and no accepted behavior loss. New stable events **0**, recurrences **0**; at that checkpoint totals remained **36 / 14 / 22**.

## M2-CP1-TB-R2-CAND-02 — working-branch push trigger remains unobservable; default-branch issue-comment control succeeds — RESOLVED ORCHESTRATION / NON-STABLE

- **Observed:** the temporary working-branch TB-R2 push caller and its text marker were installed in separate commits, but no observer comment or Actions run became observable in the bounded window. The control was removed workflow-first before any generated Directional runtime. A genuinely different narrow default-branch `issue_comment` caller, triggered by PR comment `5322834507`, immediately reported observable run `32092820628` through comment `5322835378` and executed the immutable TB harness.
- **Root cause / correction:** available evidence still does not justify a more specific GitHub-side root cause for the earlier push-event observation failure. The TB-R2 correction was a bounded default-branch control. The current standard working-branch push-marker + reusable PR observer path was then directly successful in TB-R3: observer comment reported run `32101777174` at exact trigger SHA before workload completion, so no procedural-blocker bypass is presently required.
- **Stable-count rationale:** orchestration/control plane only. The failed push control produced no semantic evidence and lost no accepted behavior. New stable events **0**, recurrences **0**; at that checkpoint totals remained **36 / 14 / 22**.

## M2-CP1-TB-R2-CAND-01 — shared-edge witness reaches completion but omits completion-level source authority — RESOLVED TEST-AUTHORITY / STRUCTURALLY INCOMPLETE FIXTURE / NON-STABLE

- **Observed:** immutable TB-R2 `32092820628 / 95578263202` preserves frozen M1 at **234/234 PASS** and advances the repaired `SharedEdgeParityRepairConforminglyCompletesTwoOddCells` through incidence, canonical ownership, and produced parity repair. It then fails only at `complete_surface_cell_complex` with `CompletionOwnershipComponentSheetMismatch`; diagnostic support is source vertex 0 with candidate faces `{0,1}`, patch faces `{0}`, and `component=-1;sheet=-1`. CP1 is therefore **4/5**.
- **Root cause:** R2 repaired arrangement-local typed source scope and `sourceOwnershipRegistry`, but the witness still invokes `complete_surface_cell_complex(complex, V, F)` with default options. `SurfaceCellComplexCompletionOptions::sourceAuthority` therefore remains null; the pass forwards that null authority into pure-quad completion, and `completion_ownership_face_matches_authority()` deliberately rejects every candidate face when source authority is absent. The arrangement registry cannot stand in for the independent `SourceTopologyRegions` component/sheet authority required by completion.
- **Correction:** planning amendment authorizes one final fixture-only `M2-CP1-CB-R3`: independently construct canonical `SourceTopologyRegions` from the exact two-face `F` with components `{0,0}` / sheets `{0,0}`, pass it via `SurfaceCellComplexCompletionOptions::sourceAuthority`, and preserve every existing R2 precondition and strict assertion. No production accommodation is authorized.
- **Resolution/evidence:** R3 source/package `65183336d092d8fe165b6ed4709c4759a0b7fe33 / 9309981828` supplies independent canonical completion source authority without production semantic change. Immutable TB-R3 `32101777174 / 95603538759` executes the formerly red identity successfully and closes CP1 at frozen M1 **234/234** + CP1 **5/5**. Result/log `9311843660 / 9311843967`; no new regression observed.
- **Stable-count rationale:** the identity was already outside accepted M1 and baseline-red before R2; TB-R2 exposes a later fixture-authority omission only after the earlier omission was corrected. No accepted-green product behavior was lost. New stable events **0**, recurrences **0**; at that checkpoint totals remained **36 / 14 / 22**.


## M2-CP1-TB-R1-CAND-03 — baseline-red shared-edge fixture promoted into CP1 acceptance — TEST-AUTHORITY / STRUCTURALLY INVALID FIXTURE / NON-STABLE

- **Observed:** authoritative TB-R1 `32075576934 / 95527922027` sees `SharedEdgeParityRepairConforminglyCompletesTwoOddCells` return non-produced. Accepted-M1 differential `32076060405 / 95529428239` consumes package `9293593175` and reproduces the same identity as red with diagnostic `MissingCellSourceScope`; the control test `FiveSidedRepairUsesBoundedClosedFormInsteadOfCompositionSearch` is green. Baseline result/log `9303454816 / 9303455184`.
- **Root cause:** CP1 acceptance mechanically promoted an existing baseline-red identity that was outside the frozen M1 234-selector. Its manually constructed exterior cell is configured without typed `sourceTopologyRegion`/`sourceCharts`, while subdivision preflight requires every participating cell to carry typed source scope.
- **Correction:** `M2-CP1-CB-R2` must correct the fixture structurally by establishing canonical typed source scope and ownership before the repair action, with an explicit proving precondition and unchanged strict produced/conforming assertions. No production accommodation is authorized.
- **Stable-count rationale:** accepted M1 already fails this identity; no accepted-green behavior was lost. This matches the known non-stable test-authority pattern of promoting inherited-red evidence, but does not create a stable recurrence. New stable events **0**, recurrences **0**; at that checkpoint totals remained **36 / 14 / 22**.

## M2-CP1-TB-R1-CAND-02 — side-fallback witness lacks canonical ownership and aborts before target action — STRUCTURALLY INVALID FIXTURE / NON-STABLE

- **Observed:** TB-R1 `32075576934 / 95527922027` fails `SideRepairFallbackPreparationIsProducedBeforeGeneralCompletion` at its explicit domain precondition with `ownership-registry-mismatch`; execution never reaches `repair_surface_cell_side_subdivisions`.
- **Root cause:** `make_authoritative_patch(...)` establishes a paired incidence topology but does not bind its projection charts to the actual source `F` or materialize `sourceOwnershipRegistry`. The witness therefore does not create the domain-authority precondition its claimed fallback assertion requires.
- **Correction:** `M2-CP1-CB-R2` must bind canonical source charts, canonicalize ownership, independently prove the ownership/domain precondition, and only then exercise side repair while preserving every strict produced-kind/reason/rollback/hash assertion.
- **Stable-count rationale:** the claimed semantic action was never reached, so this is non-evidence rather than a product regression. New stable events **0**, recurrences **0**; at that checkpoint totals remained **36 / 14 / 22**.

## M2-CP1-TB-R1-CAND-01 — Python artifact extraction drops stored executable mode before runtime — RESOLVED ORCHESTRATION / NON-STABLE

- **Observed:** first TB-R1 control `32075402079 / 95527384483` verifies the control boundary and artifact download, then stops before generated Directional runtime because Python `zipfile.extractall()` materializes packaged owner binaries without executable permission. Persistent log `9303225818 / fed460956bb666c8d1853e18766c4daa2fafd79d4b5aaf89b36f2c19fc3b6f5c`.
- **Root cause/correction:** the ZIP entries already store executable mode; the harness extraction mechanism failed to preserve it. Retry uses safe member-path validation followed by ordinary `unzip`, which faithfully restores stored archive metadata without mutating/repairing the package, and reaches runtime in `32075576934`.
- **Stable-count rationale:** pre-runtime orchestration only; no product/test/fixture/package semantic mutation and no accepted behavior loss. New stable events **0**, recurrences **0**; at that checkpoint totals remained **36 / 14 / 22**.


## M2-CP1-TB-CAND-02 — closeout workflow invalid before job creation — RESOLVED ORCHESTRATION / NON-STABLE

- **Observed:** documentation-only closeout control `32072822263` registered but produced zero jobs because multiline inline transform payload text broke YAML block indentation.
- **Root cause/correction:** executable transform text was embedded directly inside a YAML `run: |` body without preserving block indentation. Corrected closeout run `32073276034` uses a bounded, validated transform path.
- **Stable-count rationale:** no job, generated runtime, semantic evidence, source/test/fixture mutation, stable event, or recurrence. At that checkpoint totals remained **36 / 14 / 22**.

## M2-CP1-TB-CAND-01 — CP1 package omits frozen M1 authority-kernel owner executable — RESOLVED PACKAGE CLOSURE / NON-STABLE

- **Observed:** preflight `32072479294 / 95518530649` verified immutable package/source/selector integrity, then found `directional_surface_cell_authority_kernel_tests` absent. It owns **19** frozen `SurfaceCellAuthorityKernel.*` identities; only **215/234** required identities were runnable. Result/log `9302217665 / 9302218240`.
- **Root cause:** initial CP1 Code + Build packaged directly affected targets but omitted one unchanged executable mandatory for the already-frozen 234-selector TB gate.
- **Correction/evidence:** `M2-CP1-CB-R1` rebuilt/package-closed the unchanged semantic source `3be733a72330ce688013687f11cd3098ed6c849f` through the durable reusable compile workflow with the prior targets plus `directional_surface_cell_authority_kernel_tests`. Run/job `32074026365 / 95523174425` completed **117/117**, result/log `9302765681 / 9302765964` (`2a4772bec07c9d5c3e5e8d1b0a9d1cdea50724be6c8cdb4f98b11c21cf90733b / 06a1caeb2b65c8d4d80de19df4162d60a71260fd77420ff9d197aa6ca300fcc3`); all four selector-owner binaries are present, the frozen selector remains 234 identities at `dd8ba17ccf67fd3d184ae87272b97028e1debf70b00eab262c3a2aae812de687`, five source-status snapshots are clean, and `runtimeExecution=false`.
- **Disposition/stable-count rationale:** pre-semantic package/orchestration defect only. R1 changes no production/test/fixture semantics and executes no generated runtime. Package closure is resolved; semantic CP1 acceptance remains pending `M2-CP1-TB-R1`. New stable events **0**, recurrences **0**. At that checkpoint totals remained **36 / 14 / 22**; debt remains **5**.

## M2-CP0-TB-CAND-02 — documentation closeout controls expose bounded-checkout, byte-transport, and untracked-file verification defects — RESOLVED ORCHESTRATION / NON-STABLE

- **Observed:** documentation-only closeout run/job `32063141450 / 95488825272` was cancelled during an unbounded full-history checkout before closeout logic began; log artifact `9298979087 / sha256:d18d9c212104d09df4272f12b6b6b97e2766dd9fdf5153c17723bbb6acd5b112`. Bounded retry `32063486394 / 95489930069` completed checkout and source-drift checks, then rejected the connector-written closeout payload because its SHA-256 did not equal the locally frozen script hash; log artifact `9298984642 / sha256:98ddcdf38c89e1f4ec9a932d9d725db3579449087c7a73dbbb09ca20a2400e2a`. Exact-payload retry `32064311289 / 95492601103` verified both payload hashes and prepared all intended docs, then its guard omitted the newly created untracked TB report because `git diff --name-only` does not list untracked files; it failed before commit/push, log artifact `9299279050 / sha256:bf0391bad7fca4829ba4a9e19986dc7fca6b59e3cd0b85a87f16485e4a95d19f`.
- **Root cause / correction:** the first control needlessly requested full Git history on a branch with thousands of commits; the retry bounds checkout to 20 commits. The second control correctly failed closed on non-byte-stable text transport; the payload was replaced with exact Git blobs created from base64 bytes and is hash-verified before execution. The third control exposed a verification-script defect: intent-to-add the new report before the diff inventory so the guard includes untracked creation, while still verifying the exact seven-path closeout set.
- **Disposition:** orchestration/control-plane only. Neither control configured, compiled, rebuilt, relinked, modified source/tests/fixtures, executed generated Directional runtime, ran benchmarks, or changed the immutable CP0 census evidence.
- **Stable-count rationale:** new stable events **0**, recurrences **0**. At that checkpoint totals remained **36 / 14 / 22**; produced-witness debt remains **5**.

## M2-CP0-TB-CAND-01 — `ProducerOutcome<T>` plan notation hides phase-front-specific failure authority — RESOLVED PLANNING / NON-STABLE

- **Observed:** CP0-TB independently accepts the frozen census, then inspects the abstraction CP1 is required to reuse. `DESIGN.md` section 6.5 describes a generic `Rejected<ProducerFailure>`, while accepted source `SurfaceCellTracing.h:671-672` defines `ProducerOutcome<T>` as `variant<NotApplicable, Produced<T>, Rejected<SurfacePhaseFrontFailure>>`. The alias is product-generic but not failure-generic.
- **Risk if uncorrected:** CP1 would have to either encode subdivision/parity/side-repair failures as phase-front failures (authority-domain conflation) or introduce a second closed-outcome wrapper (duplicate authority), contradicting the M2 design before the first product cutover.
- **Correction:** the authoritative CP1 plan now generalizes the **existing** `ProducerOutcome` over failure type while preserving current `SurfacePhaseFrontResult` behavior through the existing/default phase-front failure specialization. CP1 repair products use typed repair failure authority. A rollback-equivalent side-repair state that is legitimately consumable by general completion is encoded as a produced consumable preparation product; true `Rejected` carries no consumable product and is terminal, eliminating string-gated rejected-fallback reconstruction.
- **Disposition:** planning/type-shape defect discovered during artifact-only census acceptance before any CP1 source/test/fixture mutation. CP0 site sets remain exact; no accepted runtime behavior is lost.
- **Stable-count rationale:** new stable events **0**, recurrences **0**. At that checkpoint totals remained **36 / 14 / 22**; produced-witness debt remains **5**.

## M1-FULL-TB-BLOCK-01 — criterion-5 fixture-domain mismatch — RESOLVED PLANNING/EVIDENCE / NON-STABLE

- **Observed:** preflight `32051665150 / 95452236588` correctly stopped because then-current criterion 5 required phase-front producer authority from the directly constructed closed-torus simplification witness.
- **Resolution:** independent planning review `M1-C5-FIXTURE-MAP-REV` confirmed the defect was in the gate and restated criterion 5 per fixture/semantic stage. F1/F2 retain strict producer requirements; F3 retains checked direct construction plus the full unrelaxed simplification predicate and explicitly carries no producer claim.
- **Accepted evidence:** resumed immutable gate `32055365696 / 95464163035`, result `9296299890`, log `9296300150`, passes corrected criterion 5 for all three fixtures and closes M1.
- **Stable-count rationale:** planning/evidence-domain defect only; new stable events **0**, recurrences **0**. At that checkpoint totals remained **36 / 14 / 22**; produced-witness debt remains **5**.

## M1-FULL-TB-CAND-01 — external control-payload HTTP 503 blocks preflight acquisition — RESOLVED ORCHESTRATION / NON-STABLE

- **Observed:** run `32051454584` attempts 1/2 (`95451537737`, `95451721562`) and hardened run/job `32051586068 / 95451972166` fail before immutable package inspection while fetching the temporary preflight control payload; the hardened control exhausts six HTTP-503 retries. Diagnostic logs are `9294835630`, `9294851611`, and `9294881735`.
- **Root cause / correction:** external raw/Contents payload acquisition was an unnecessary control-plane dependency. The successful control removed that hop and used an exact-SHA **control-only checkout**, explicitly not repository checkout as test authority, then downloaded and verified immutable artifacts in `32051665150 / 95452236588`.
- **Disposition:** orchestration/infrastructure only. No package/source/test/fixture mutation, configure, compile, relink, rebuild, discovery, semantic test body, benchmark, or generated Directional runtime occurred in the failed controls.
- **Stable-count rationale:** new stable events **0**, recurrences **0**; at that checkpoint totals remained **36 / 14 / 22**.

## M1-FULL-TB-CAND-02 — monolithic harness transfer corruption — RESOLVED ORCHESTRATION / NON-STABLE

- **Observed:** `32054750074 / 95462203833` fails while decoding the temporary base64/gzip TB control with gzip CRC/length errors. The immutable package is never acquired and generated Directional runtime does not begin. Persistent log `9295977148 / c3564423933186adabc2d869ceec5a645f0edea0d19e8b3fb5eb450f7ef9e4a9`.
- **Root cause / correction:** one large connector-written encoded payload was not byte-stable. The retry split the exact payload into bounded chunks and required SHA-256 `5141bed19f9485b878318041c3afe645b03511f6073d9297765a1f080ffe3930` before decoding, then verified gzip and Python hashes before execution.
- **Disposition:** orchestration/control transfer only; no package/source/test/fixture mutation, configure, compile, rebuild, discovery, semantic test, or benchmark occurred.
- **Stable-count rationale:** new stable events **0**, recurrences **0**; at that checkpoint totals remained **36 / 14 / 22**.

## M1-FULL-TB-CAND-03 — artifact redirect authentication blocks immutable acquisition — RESOLVED ORCHESTRATION / NON-STABLE

- **Observed:** `32055089129 / 95463284124` verifies the chunked harness, then fails before package inspection because Python urllib forwards GitHub authorization through the cross-host signed artifact redirect: attempts 1-4 return 401 and 5-6 return 503. Result `9296124532 / 1483929d82db1be9b7e739debe9500072de592b60a6312e5e0ccd40ca57d806b`; log `9296124829 / c97337864a56c3b42eb418e7007aa46a27c50c468f0df49a8249543b4492ffe4`.
- **Root cause / correction:** redirect authentication was a harness transport defect, not immutable-package evidence. The accepted control patches only the temporary downloader to redirect-safe `curl --location`, verifies the patched harness hash, and then succeeds in `32055365696 / 95464163035`.
- **Disposition:** orchestration/artifact acquisition only. The failed control consumed no Directional package runtime and changed no package/source/test/fixture semantics.
- **Stable-count rationale:** new stable events **0**, recurrences **0**; at that checkpoint totals remained **36 / 14 / 22**.

## WU3G-TB-CAND-01 — harness acquisition/digest controls stop before semantic execution — RESOLVED ORCHESTRATION / NON-STABLE

- **Observed:** `32036059934 / 95406632779` and `32036143687 / 95406892013` stop while acquiring/verifying the temporary TB harness. The first transfer pipeline is unsuitable; the second proves GitHub stores the intended base64 payload without the local terminal newline (20,752 versus 20,753 bytes).
- **Evidence:** logs `9290722028 / 71e7bbd54cc94a547bb1ade2b7ad2d19a862e767300a849fb233916f89cb47fa` and `9290751121 / 7af02428ce3233e35db6c502d648d8d6424cf19e53cc639115a587fc835a919c`.
- **Disposition:** orchestration/control-plane only. No generated Directional runtime, checkout, configure, compile, rebuild, repair, or source/test/fixture mutation occurred.
- **Stable-count rationale:** new stable events 0, recurrences 0; at that checkpoint totals remained **36 / 14 / 22**.

## WU3G-TB-CAND-02 — known WU2B inherited-red hygiene was mechanically promoted into the first G selector — RESOLVED TEST-AUTHORITY / NON-STABLE

- **Observed:** R2 `32036414166 / 95407704293` freezes 235 identities and gets **234 PASS / 1 FAIL**. The sole red is `SurfaceCellsPhase10.HardRailRegionCopiesPairReciprocallyBeforeQuotientMaterialization`, failing at `InvalidFrontBoundaryAuthority` before its claimed seam.
- **Prior authority:** this exact identity is already `WU2B-TB-CAND-01`; accepted-baseline differential `31916254483 / 95088352843` reproduced the same earliest failure. It is explicitly listed in `TODO.md` as deferred non-gating hygiene.
- **Root cause:** selector derivation treated every changed default-packaged test definition as a new G runtime obligation and ignored Gate E's rule that inherited-red/non-gating hygiene must not be promoted unless an independent Batch-G obligation requires its semantic body. Its C06-12 packed-to-typed source change is already established by Gate B static authority and the body still cannot reach its intended reciprocal-copy/materialization seam.
- **Correction:** no source/test/validator mutation. Correct selector authority excludes exactly this known hygiene identity; accepted R5 freezes **234** identities at `dd8ba17ccf67fd3d184ae87272b97028e1debf70b00eab262c3a2aae812de687` and passes all 234.
- **Stable-count rationale:** no accepted-green behavior was lost; new stable events 0, recurrences 0; at that checkpoint totals remained **36 / 14 / 22**.

## WU3G-TB-CAND-03 — corrected-selector diagnostics stage immutable source at the wrong runtime root — RESOLVED ORCHESTRATION / NON-STABLE

- **Observed:** R3 `32037052304 / 95409518757` and R4 `32037349369 / 95410330614` use the correct 234-selector but execute from package/runner-temp source roots. Twenty-six producer tests fail because committed benchmark fixtures resolve under `/home/runner/work/Directional/Directional`, outside those staged roots.
- **Evidence:** R3 result/log `9291066828 / d92cb8e59e4a7673ca16cf717a420f6e2bb0cddb91e1b522dd632a62b495f029` / `9291067171 / fa0ac512a408fe11c5c44b51a6681ff7d1af24f5b115443e1dee17ea51fc0d6b`; R4 result/log `9291141101 / 613d669e6037f8e9a842a081073c8ca50f290ab3f148a525a89f130f9d1ee49b` / `9291141273 / b6bcba70812a894fb41973f83a9b3eda62730d83d365d3fb5c0b50679d11d769`.
- **Root cause/correction:** the accepted R2 harness stages the immutable source archive directly at `GITHUB_WORKSPACE`; the compiled test fixture-root logic expects that source-root shape. R5 stages the exact same archive at that exact root, changes no package/source/test/fixture semantics, and passes **234/234**.
- **Stable-count rationale:** missing-fixture failures are harness working-directory orchestration, not product regressions. New stable events 0, recurrences 0; at that checkpoint totals remained **36 / 14 / 22**.

## WU3G-TB-CAND-04 — monolithic durable-closeout workflow cannot instantiate a job — RESOLVED ORCHESTRATION / NON-STABLE

- **Observed:** temporary closeout workflow runs `32038083261` and `32038154623`, plus the first record-workflow controls `32038648390` and `32038661360`, terminate immediately with workflow conclusion `failure`, **zero instantiated jobs**, and **zero artifacts**. The failure occurs after semantic Batch-G acceptance and before any closeout runner step can execute.
- **Primary category:** workflow-definition/control-plane orchestration; not package, product, test-authority, or runtime semantic evidence.
- **Root-cause boundary:** The temporary YAML embedded Python here-doc content whose inner triple-quoted document lines escaped the indentation of the `run: |` block. Those unindented lines make the workflow definition invalid before job instantiation; the same authoring mistake recurred in the first recorder control.
- **Correction/guard:** replace embedded multiline document bodies with a minimal valid workflow that checks out the branch and extracts/runs the already-retained Python payload, keeping all workflow block-scalar lines correctly indented. `32038265162 / 95412855490` completes the closeout successfully; result/log `9291343390 / a757b37f70a06a7b493ef2abfd51e52984fb338f9d5d08b6db70c53600aab4e0` / `9291343544 / 99d8679897ef206330c80cec44897b56231ce5edb0e24edcb547b7def0b33185`. The matching minimal recorder `32038732132 / 95414127654` also succeeds; result/log `9291467739 / f154a9da1b259cdc0d82c5460efbd92f92f39137284e8bd4f4ad9dddaedf1577` / `9291467977 / 137408b7dbfbd786585f8bc712d2a2baf0ff6a16ca591bbf155b2fe5e708bcb8`.
- **Stable-count rationale:** all four failed workflow-definition controls instantiate no job and execute no generated Directional runtime or package/source/test/fixture mutation. New stable events **0**, recurrences **0**; at that checkpoint totals remained **36 / 14 / 22**.

## WU3F-TB-CAND-01 — one-byte harness-transfer corruption blocks pre-semantic acceptance control — RESOLVED ORCHESTRATION / NON-STABLE

- **Status:** **RESOLVED ORCHESTRATION / NON-STABLE**. The accepted immutable Batch-F gate is green; the failed controls never reached package semantic execution.
- **Observed:** `31991843496 / 95276672302` failed while decoding the repository-side base64/gzip TB harness with gzip CRC/length errors before immutable package preflight. It produced no semantic result artifact; log `9275571066 / b824babe239f0314b807caacff6d48468db3f023bb79c9a796e8dee9ebdf0a35` records `repositoryCheckout=false`, configure/compile/relink/rebuild/packageRepair=false, and source/test/fixture mutation=false. Diagnostic retry `31991956482 / 95276979367` intentionally retained the fetched payload, again before semantic execution; artifact `9275608515 / 810c0f61d83399b73ff623884092992f73b7859d1fc6dd725d135e50401fe8e1`, log `9275608866 / 0de62beef7a458a0f4a9131e58485188475b9643bc1d1909688572a28c352d5e`.
- **Primary category:** orchestration/control-plane evidence transfer; not a product, test-authority, or immutable-package semantic regression.
- **Root cause:** byte-for-byte comparison of the retained fetched payload with the locally syntax/hash-verified harness found exactly one same-length base64 transfer mismatch at byte offset 12905: repository payload `s`, intended payload `S`. That one case change corrupts the gzip CRC/length while leaving the package/source under test untouched.
- **Correction/guard:** the accepted control corrected only the temporary runner-side harness-transfer byte, required corrected base64 SHA-256 `d7826fcadf90f38dd2078a5692bebe97a2877b928395b189783023a0b0e04b29`, decoded it, and required harness SHA-256 `23fef3064c81871c8318547be97d2dfb711354f6dd9907e52171d4d7a1fdf3c5` before execution. Authoritative `31992003088 / 95277103306` then passed immutable preflight, 225/225 required-green, 206/206 + 4/4 obligation reconciliation, and immutable postflight. Result `9275660950 / 81925dc95b8979575be634c6f05c16a10d324ce6dad30c39d3708829fcf5c423`; log `9275661090 / eebff288b5b34c9939e8866ad52a23262d7c3f21ddca63ac576aa3c7bf52f60a`.
- **Stable-count rationale:** both failures occurred before generated Directional runtime and changed no source/test/fixture/package semantics; the accepted retry lost no accepted-green behavior. New stable events **0**, new recurrences **0**. Historical totals at that checkpoint remained **36 / 14 / 22**; produced-witness debt remains **5**.

## WU3E-TB-CAND-01 — two mandatory R-E contracts are source-present but absent from the immutable package — RESOLVED HYGIENE / NON-STABLE

- **Status:** **RESOLVED HYGIENE / NON-STABLE**. The original package-closure attempt ran no semantic body; final R3 acceptance proves the corrected default-package authority exact-once/nonzero and semantically green.
- **Observed:** authoritative artifact-only attempt `31977862327 / 95239937005` validates the exact Batch-E artifacts and reaches independent package discovery, then rejects the candidate because `SurfaceCellPipelinePhase20.LiveTracingConsumesAuthoritativeBoundaryAndHardFeatureRails` and `SurfaceCellTracingPhase14.InteriorHardRailSeedsBothIncidentFaceCharts` each resolve to zero packaged tests. Result `9271533807 / 7685eb2619ceed8f8c32e7df8b42a8ed001fc021a1a7f6475f85ff9c576ef5c8`; log `9271533907 / 23867a9c0ad74b7abff7f16b94b4f56f3964b677ea71d05bf108b9dce21dd03c`.
- **Primary category:** `RP-02 / TEST_AUTHORITY_COVERAGE_GAP`; subtype: mandatory-contract → packaged-target closure.
- **Root cause:** both exact test definitions exist in the immutable source, but `cmake/DirectionalTests.cmake` assigns `tests/SurfaceCellPipelinePhase20Tests.cpp` and `tests/SurfaceCellTracingPhase14Tests.cpp` only to default-off `directional_surface_cell_historical_tests`. The approved Batch-E package therefore cannot own either mandatory identity. This repeats the failure mechanism recorded by `R-A-R12-CAND-01`: source/compile presence was used as a proxy for package membership.
- **Evidence boundary:** the gate executed only package-owned `--gtest_list_tests` discovery before stopping. No semantic test body, benchmark, rebuild, repair, source/test/fixture mutation, or product runtime acceptance occurred. The prior control `31977811984 / 95239813933` was orchestration-only audit-cardinality mismatch and is not semantic/package evidence.
- **Correction/guard:** `WU3E-TB-R1-CB` must surgically migrate exactly one authoritative definition of each missing behavioral contract into an approved default packaged target, remove historical duplicates, preserve the assertions/scenarios, and add a static package-membership guard. Do not enable the historical target wholesale and do not change production semantics without separate evidence.
- **Code + Build remediation evidence:** `WU3E-TB-R1-CB` exact source `94e59a7985c3d152d9376a0d8596127e4f2f3c1d` relocates exactly the two mandatory definitions into focused default `directional_surface_cell_producer_tests` authority, removes historical duplicates, and adds configure-time exact-one/package-membership guards. Static reconciliation `31979623341 / 95244219899` is PASS at frozen **27/27/10**, E1 **6/6**, E2 **4/4**, route K=0; `include/` and `src/` remain unchanged from pre-remediation Batch E. Immutable package `31979729574 / 95244483768` builds all eight approved targets with exit 0 and `runtimeExecution=false`; result `9272021540 / 715673c38493b4a8dfa423a523c42e4b3427be3c60364d56de5bb4dc52a3ccde`, log `9272021654 / 6ee71357f77456a343010eb56537460b4ee1049bee1726445f642efae52b8999`, source archive `52c37811d3cf00f6464895d986972139546727a5b89c473d6efe8f4ec3e732fa` / 548 members. This structurally remediates package membership but does not close the candidate until `WU3E-TB-R1` independently proves exact-once/nonzero-selected runtime discovery and the semantic gate.
- **Stable-count rationale:** Batch E has never been runtime accepted and no accepted-green product behavior was lost; the failure is pre-semantic package closure. New stable events **0**, new recurrences **0**. Historical totals at that checkpoint remained **36 / 14 / 22**; produced-witness debt remains **5**.
- **R1 runtime status:** package/discovery subclosure is now proven on `9272021540`: both formerly missing identities are package-owned, exact-once, and nonzero-selected. `SurfaceCellTracingPhase14.InteriorHardRailSeedsBothIncidentFaceCharts` passes; the LiveTracing identity fails semantically before its claimed seam. Under the R1 plan's stricter resolution rule this package candidate remains open until Batch-E semantic acceptance; the semantic observation is tracked separately as `WU3E-TB-R1-CAND-01`.
- **R2 runtime status:** exact-one/nonzero package ownership remains proven on R2 package `9272732618`; independent discovery is 17/269/183/84 and both mandatory identities resolve exactly once.
- **R3 resolution:** authoritative `31986277605 / 95261755062` discovers **17/269/183/84**, resolves the direct and replacement full-pipeline contracts exact-once/nonzero, passes **222/222 required-green**, and preserves immutable postflight. Result `9273897699 / fe9c22936565603a3bee268f0860b7ff5e874300e5db4317ddc54ae60c385d78`; log `9273897936 / 6fe165df414ae6b2b6ab4a3b617ea918a91d0d75f968eb9f487c27cdc8504643`. Package membership/test authority is closed without a production semantic correction.

## WU3E-TB-R1-CAND-01 — mandatory LiveTracing witness fails before its claimed live-tracing rail seam — RESOLVED HYGIENE / NON-STABLE

- **Observed:** immutable R1 `31980808023 / 95247094263` discovers the now-packaged identity exactly once but `SurfaceCellPipelinePhase20.LiveTracingConsumesAuthoritativeBoundaryAndHardFeatureRails` fails `NotProductionReady` at stage `tracing` instead of reaching the injected `arrangement` failure. The retained trace network has no qualifying boundary/feature rail seed, no hard/boundary FlowRep rail, and no FlowRep network.
- **Primary category:** `RP-02 / TEST_AUTHORITY_COVERAGE_GAP`; subtype: mandatory acceptance witness lacked an independently established producer precondition.
- **R2 root cause:** the Batch-E pre-edit census (retired into `M1_Closure_Record.md`) proves the historical two-triangle-square fixture marks its triangulation diagonal hard, splitting the component into two triangular source-topology regions. The authoritative phase-front dispatcher fail-closes `UnsupportedSourceSheetTopology` when such a hard-feature region is unsupported. Both accepted-D and current `build_surface_cell_network` return on `phaseFront.is_rejected()` **before** deterministic rail-seed generation, so R1's empty seeds/FlowRep are downstream consequence and not evidence of an E1 typed `HardRailId` writer defect. An accepted-D-era rectangular internal-hard-feature fixture independently establishes supported phase-front production.
- **R2 Code + Build correction:** exact source `553408b950b5263e421d97b2d3a944d19b54a784` changes only the packaged LiveTracing fixture/setup plus a static CMake recurrence guard. The strict typed rail-seed, mandatory hard+boundary FlowRep, arrangement, telemetry, and lineage assertions remain. `include/src` and the three accepted-D-red quotient bodies have zero diff from R1. Static reconciliation `31982307676 / 95251170731` PASS preserves **27/27/10**, E1 **6/6**, E2 **4/4**, K=0. Immutable compile/package `31982337642 / 95251246821` exits 0 with package `9272732618 / 552d28e81c970378ded39fd70e36e38927e6427164e5022da79f2c33837fe80a` and `runtimeExecution=false`.
- **R2 runtime refinement:** authoritative `WU3E-TB-R2` `31983608515 / 95254667604` proves the rectangular correction reaches the arrangement-stage full-pipeline path, but `sawRailSeed=false` remains the sole required failure. Accepted-D and current source both return from a produced phase front before deterministic seed generation, while the direct typed seed contract passes. The original R1 fixture-precondition diagnosis was correct but incomplete; the deeper impossible combined-witness mechanism is now tracked as `WU3E-TB-R2-CAND-01`.
- **Status:** **RESOLVED HYGIENE / NON-STABLE**. The fixture-precondition finding was valid but incomplete and was superseded by `WU3E-TB-R2-CAND-01`; R3 `31986277605 / 95261755062` closes the chain by passing both truthful split contracts and all 222 required-green identities without production semantic change.
- **Stable-count rationale:** no accepted-green retained behavior was lost, no production semantic code changed in R2-CB, and the historical witness had no accepted packaged green baseline. New stable events **0**, recurrences **0**; at that checkpoint totals remained **36 / 14 / 22**.

## WU3E-TB-R2-CAND-01 — mandatory full-pipeline witness combines mutually exclusive authoritative phase-front and live seed paths — RESOLVED HYGIENE / NON-STABLE

- **Observed:** authoritative immutable R2 `31983608515 / 95254667604` passed preflight, exact selector ownership, independent discovery, every retained accepted surface, and immutable postflight, but required-green was **221/222**. The only failure was `SurfaceCellPipelinePhase20.LiveTracingConsumesAuthoritativeBoundaryAndHardFeatureRails`, whose only failed assertion was `sawRailSeed=false`. Result `9273120248 / 84c43db2e637b85d24b2e4175aafc4b97c2f109dde048b79707ca6932cb73edc`; log `9273120524 / cb4088085f9e42eafb537586ba769de2877c18c06063f67cfcb9364390ad3bb2`.
- **Primary category:** `RP-02 / TEST_AUTHORITY_COVERAGE_GAP`; subtype: impossible combined witness / execution-path conflation.
- **Root cause:** accepted-D and current `build_surface_cell_network(...)` both return from the authoritative `phaseFront.is_produced()` path before `generate_deterministic_surface_seeds(...)`; rejected hard-feature phase fronts also return/fail closed. The direct `SurfaceCellTracingPhase14.InteriorHardRailSeedsBothIncidentFaceCharts` already passes and independently proves the typed `HardRailId` live-seed seam, while the R2 full-pipeline witness reaches arrangement with authoritative hard/boundary FlowRep and arrangement rail authority. No production regression is established.
- **R3 Code + Build correction:** exact source `c591f52280a4ed31fa77146aa994bbf24147f480` changes only `tests/SurfaceCellREPackageTests.cpp` and `cmake/DirectionalTests.cmake`. The retired identity has **0** source definitions. New `SurfaceCellPipelinePhase20.AuthoritativePhaseFrontPropagatesBoundaryAndHardFeatureRailsThroughFlowRepAndArrangement` and direct `SurfaceCellTracingPhase14.InteriorHardRailSeedsBothIncidentFaceCharts` each have **1** default-packaged definition with fail-closed split-responsibility guards. The full path retains strict produced-phase-front, typed FlowRep/arrangement rail membership, telemetry, and lineage assertions without live-seed responsibility; the direct path retains exact deterministic typed-seed assertions. `include/src` and the three inherited-red quotient bodies are byte-identical to R2.
- **Static evidence:** `31984982608 / 95258287604` PASS, result `9273468102 / 1839c95d72744867d7af9a0c2d9c75edf97071c1fa5d67ef3ab6bce6d7f1ea69`, log `9273468314 / 5de9c7bc49c4b33b5652144dad971d3dace5c8afef83ea1ee4407d140852ef34`; frozen **27/27/10**, E1 **6/6**, E2 **4/4**, route K=0, `runtimeExecution=false`.
- **Compile/package evidence:** `31984982608 / 95258331809` builds all eight approved targets with exit 0. Immutable package `9273490623 / 4f42e3a72bd447a6e943fabd815928a8579570fc8b5ff0161f7a2a9ef20db1de`, log `9273490809 / b037916c6e9e70462326479068188637174edbbec066cd5bdb6b62b34e74f3f3`; source archive `eca4f779170797034b9afed1ff9befc34fc43fbe0478fb0f72e28e9b60ff26fa` / 556 members; package 26/25; five clean snapshots; ccache 110/111; `runtimeExecution=false`.
- **R3 resolution / status:** **RESOLVED HYGIENE / NON-STABLE**. Artifact-only `31986277605 / 95261755062` consumes immutable `c591f52280a4ed31fa77146aa994bbf24147f480 / 9273490623`, substitutes only the retired Phase20 identity in the exact R2 222-identity required-green authority, and passes **222/222**. Both `SurfaceCellPipelinePhase20.AuthoritativePhaseFrontPropagatesBoundaryAndHardFeatureRailsThroughFlowRepAndArrangement` and `SurfaceCellTracingPhase14.InteriorHardRailSeedsBothIncidentFaceCharts` pass; every retained accepted group is green; immutable postflight proves package/executable/source state unchanged. Result `9273897699 / fe9c22936565603a3bee268f0860b7ff5e874300e5db4317ddc54ae60c385d78`; log `9273897936 / 6fe165df414ae6b2b6ab4a3b617ea918a91d0d75f968eb9f487c27cdc8504643`.
- **Controls:** `31984775825` was workflow-schema-invalid before any job; `31984837330 / 95257905406` stopped on patch hunk syntax before source mutation. Neither executed generated runtime or changes regression counts.
- **Stable-count rationale:** no accepted-green behavior was lost and no production semantic code changed. New stable events **0**, recurrences **0**. Historical totals at that checkpoint remained **36 / 14 / 22**; produced-witness debt remains **5**.

## WU3E-TB-R1-CAND-02 — broad R-E selector promoted three accepted-D-red quotient witnesses — CLASSIFIED NON-GATING / NON-STABLE

- **Observed:** R1 includes three additional `SurfaceCellTransitionQuotient` identities outside the retained accepted selector chain. Two stop at `torus pipeline producer failed: InvalidHardRailPairing`; one fails `foundSeamEquivalence=false`.
- **Accepted-baseline differential:** exact accepted-D artifact-only `31981144579 / 95248017736` reproduces all three exact failures with preflight/postflight PASS and no mutation. Result `9272364385` / `13e11dab13cdb6349524073ea8ea850ed5327f01985ebbc38f5fca72e8733290`; log `9272364628` / `c7b4c8e7f31eca3e881f88d8ca8d77132caa800311299185b503be930c2e7234`.
- **Primary category:** `RP-02 / TEST_AUTHORITY_COVERAGE_GAP`; mechanism: acceptance-selector overreach. The two torus identities are coupled to deferred `G4-B002`; the quotient-lineage fixture lacks an accepted-green seam-equivalence precondition.
- **Disposition:** R2 and R3 execute all three separately from required-green and reproduce the exact accepted-D red states. R3 also verifies the quotient test source body matches R2. Keep them visible, bodies unchanged, and non-gating; they are not accepted-green Batch-E evidence.
- **Stable-count rationale:** exact same red states exist on accepted D, so Batch E did not lose accepted behavior. New stable events **0**, recurrences **0**; at that checkpoint totals remained **36 / 14 / 22**.

## WU2D-TB-CAND-01 — full-periodic materializer contracts depend on deferred nonzero-Z4 producer capability — RESOLVED HYGIENE / NON-STABLE

- **Observed identities:** `SurfaceCellTransitionQuotient.FullPeriodicRotationAndTranslationMaterialize` and `SurfaceCellTransitionQuotient.TamperedFullPeriodicTransformIsRejected` are the only red D contracts in corrected artifact-only `WU2D-TB` `31959655069 / 95195574819`. Both throw `cylinder winding field producer failed: PeriodicHolonomyMismatch` before reaching materialization or transform tampering. All other D contracts are **21/21**, and every retained accepted surface is green.
- **Accepted-baseline differential:** artifact-only `31960093048 / 95196635969` executes the exact two identities on accepted Batch-C source/package `d0f14508d59f4ea4d38b4db7b3904de239a6b555` / `9258953680` and reproduces the same **0/2** earliest `PeriodicHolonomyMismatch`. D1 package `9263684031` reproduces the same **0/2**. All differential package manifests/file-state hashes are unchanged post-execution.
- **Primary category:** `RP-02 / TEST_AUTHORITY_COVERAGE_GAP`; mechanism: deferred-blocker coupling. The fixture requests `make_committed_fixture("cylinder", true)`, whose winding field uses `fieldAngle = 0.25 * angle` and requires a produced nonzero periodic-Z4 phase front. `REORIENTATION_PLAN.md` explicitly assigns nonzero periodic Z4 production to `G4-B003`, owned by M5 and outside M1.
- **Root-cause bound:** the evidence proves the D materializer contracts are blocked by a producer precondition they do not own. It does **not** prove a D1/D2 product regression and does not authorize enabling `G4-B003` inside M1. The positive and negative materializer assertions have not yet been reached by these fixtures.
- **Disposition:** one planned same-batch remediation package retry may replace only this fixture dependency with directly constructed checked typed phase-front authority at the materializer boundary, carrying nonzero `QuarterTurn` plus nonzero lattice translation and preserving strict positive/tampered-negative assertions with reachability/non-vacuity guards. Production semantics remain unchanged unless separate evidence establishes a product defect.
- **Stable-count rationale:** accepted C already fails both identities at the same earliest precondition; no accepted-green behavior was lost. New stable events **0**, new recurrences **0**; historical totals at that checkpoint remained **36 / 14 / 22**.

**Resolution evidence — WU2D-TB-R1:** test-authority-only source `37adb93e66385b80199c3f748f4a2e9f1ded06dd` removed the two materializer contracts' dependency on deferred produced nonzero-Z4 while leaving `G4-B003` itself deferred. Immutable artifact-only `31964571034 / 95207639154` then passed both formerly blocked identities (**2/2**) and the complete Batch-D surface (**23/23**) with all retained accepted surfaces green and immutable preflight/postflight PASS. Result `9268218441 / e36c90dabeb51fea6c75d117588bf2386c5eac1e8a00be501a110945c47f08df`; log `9268218707 / b65242f578e6d454f9a01cb26489cf5e3c4fff284206318027c92041bdb8318e`. This closes the candidate as test-authority hygiene, not as a production-Z4 fix. No accepted-green product regression existed, so historical stable totals at that checkpoint remained **36 events / 14 categories / 22 recurrences** and produced-witness debt remained **3**.

## PR8-R035 / WU2C-R001 — recovery one-way component/sheet provenance export erased — RESOLVED STABLE / RECURRENCE

- **Original observed loss:** initial WU2C-TB `31925201569 / 95111570760` failed retained `MilestoneGP26.RecoveryPreservesComponentAndSheetProvenance`: source component `7` / sheet `11` were exported as `-1/-1` after C3 removed the representation boundary.
- **Accepted-baseline differential:** accepted Batch B `31925701879 / 95112819123` passed the identity and showed the checked typed-authority -> public integer provenance export.
- **Primary category:** `RP-01 / AUTHORITY_DOMAIN_CONFLATION`; detection escape `RP-02 / TEST_AUTHORITY_COVERAGE_GAP`.
- **Root cause:** C3 conflated typed semantic authority with the required one-way public provenance representation and erased the latter.
- **Remediation:** exact source `09c4eb41ac2053bccca7e3f82454e3f30b72e956` restores only checked `SourceComponentId` / `IsolationSheetId` -> `SurfacePoint.component` / `.sheet` output export and classifies those two leaves as one-way exports; static audit remains K=0.
- **Resolution evidence:** artifact-only WU2C-TB-R1 `31928106481 / 95118691578` executes the unchanged retained recovery identity as part of R-C/R-G **67/67 PASS** with immutable preflight/postflight PASS. All retained A/B/R-A/R-B/F2 surfaces also pass. Result `9258540747` / `f38f21366d0f3b8f0831f97611127f8fdce72f4062d66db6153ebe57e29bc69a`.
- **Disposition:** **RESOLVED**. Resolution does not erase its historical stable event/recurrence; cumulative totals at that checkpoint were **36 / 14 / 22**.

## PR8-R036 / WU2C-R002 — reflected periodic test conflates current route topology with cross-fixture correspondence — RESOLVED STABLE / RECURRENCE

- **Initial observed loss:** WU2C-TB failed `SurfaceCellPeriodicHolonomyRouteTransportAuthorityMigration.ReverseObservedCycleUsesExactTransportInverse` before its inverse assertion because the reflected field lookup used pre-reflection `semanticTopology` instead of current reflected-mesh `topology`.
- **Accepted-baseline differential:** the exact identity passes on accepted Batch B under `31925701879 / 95112819123`.
- **Primary category:** `RP-02 / TEST_AUTHORITY_COVERAGE_GAP`; secondary mechanism `RP-01 / AUTHORITY_DOMAIN_CONFLATION`.
- **R1 partial remediation evidence:** source `09c4eb41ac2053bccca7e3f82454e3f30b72e956` corrects the two reflected/current-field lookup seams. Artifact-only retry `31928106481 / 95118691578` proves transition authorship now succeeds, every forward/reverse per-step inverse matching assertion passes, both phase fronts are `Produced`, and both periodic holonomy rotations pass. The identity reaches its final route-topology equality instead of failing fixture setup.
- **Refined root cause:** the fixture carries two intentionally different domains. `step.topology` names an edge in the **current fixture mesh** and is remapped through `oldToNew` under reflection. `step.semanticTopology` retains the original pre-reflection edge only to correlate reflected steps with forward steps. Accepted Batch B's `periodic_route_topology` expected `step.topology`; C4 changed that output oracle to `step.semanticTopology`. The produced typed `CanonicalRoute` correctly reports current reflected-mesh source-edge topology, so R1 now fails only because the expected route sequence is in the correspondence domain.
- **R2 Code+Build remediation:** amended plan section 6.1 authorized the bounded 9/9/4 test-authority repair. Exact source `d0f14508d59f4ea4d38b4db7b3904de239a6b555` replaces the overloaded raw/typed pair with typed `currentTopology` and `correspondenceTopology`, makes current-fixture output/field uses typed and distinct from cross-fixture matching, removes both packed-key unpacks, and adds forward-equality/reflected-inequality non-vacuity. No production/validator source changed. Current audits PASS at master 199/199 and Batch C 64/64; package `31929794499 / 95122783913` is 120/120 with immutable artifact `9258953680` and `runtimeExecution=false`. R036 therefore remains OPEN STABLE until `WU2C-TB-R2` executes the exact contract.
- **Retry evidence:** corrected C required-green **68/69**, all retained authority green, immutable postflight PASS. Result `9258540747` / `f38f21366d0f3b8f0831f97611127f8fdce72f4062d66db6153ebe57e29bc69a`; log `9258540956` / `f7f07a1daebff58e3abe844e1f98b24eb094db3981aa34e2da3b6b23b57e3fe8`.
- **R2 resolution evidence:** exact source `d0f14508d59f4ea4d38b4db7b3904de239a6b555` separates typed `currentTopology` from `correspondenceTopology`, removes both packed-key unpacks, and proves the split non-vacuous without production/validator mutation. Artifact-only `WU2C-TB-R2` `31933702100 / 95132287981` executes `SurfaceCellPeriodicHolonomyRouteTransportAuthorityMigration.ReverseObservedCycleUsesExactTransportInverse` successfully as part of producer **27/27** and corrected Batch-C **69/69**, with immutable preflight/postflight PASS. Result `9260116329` / `0b9c1fe37a295c00183e1dfc34b042b660297f276b1918a09b19168adacc21bc`; log `9260116490` / `c22e480788e1c17124a1dd3efc09ee67c1a683274505eb18a6b5007d0d74cc29`.
- **Disposition:** **RESOLVED**. The accepted-green behavior lost during C4 is restored under the corrected typed test-authority domain split while production transport and the exact inverse assertion remain unchanged.
- **Stable-count rationale:** resolution is not a new event or recurrence and does not erase the historical recurrence already counted. New events **0**, new recurrences **0**; historical totals at that checkpoint remained **36 / 14 / 22**.

## WU2C-TB-CAND-01 — three MultiRail optimizer fixtures are inherited accepted-B red — OPEN HYGIENE / NON-STABLE

- **Observed identities:** `MultiRailChainReachesSelectedChartWithoutConsumingUnusedRelation`, `MultiRailChartReachabilityIsInvariantToSourceFaceRows`, and `MultiRailReciprocityMayBeCarriedOutsideTheSelectedFace` fail on C because the fixture's selected/original/resolved chart is invalid before the intended later assertion.
- **Accepted-baseline differential:** exact accepted-B replay reproduces all three same earliest invalid-chart failures.
- **Primary category:** `RP-02 / TEST_AUTHORITY_COVERAGE_GAP`.
- **Root-cause bound:** the differential proves inheritance and that these fixtures lack an accepted-green chart-resolution precondition. It does not justify an optimizer production change or identify the deeper fixture cause.
- **Disposition:** exclude from C required-green proof and retain as explicit hygiene. Repair only after independently establishing a valid chart-resolution baseline while preserving the intended MultiRail assertions.
- **Stable-count rationale:** no accepted-green behavior is lost; stable totals are unaffected.

## WU2C-TB-CAND-02 — multi-orientation chart-numbering witness is inherited accepted-B red — OPEN HYGIENE / NON-STABLE

- **Observed:** `SurfaceCellPhaseFrontFieldChartAuthorityMigration.MultipleOrientationChartsPreserveEstablishedNumbering` expects hard-authored chart IDs `1/2` on selected source faces while runtime publishes chart `0`.
- **Accepted-baseline differential:** exact accepted-B replay reproduces the same numbering mismatch.
- **Primary category:** `RP-02 / TEST_AUTHORITY_COVERAGE_GAP`.
- **Root-cause bound:** evidence proves inheritance but does not establish whether the fixture oracle or produced authority is semantically correct. Renumbering production or changing expected constants would be unsupported.
- **Disposition:** explicit non-gating hygiene outside corrected C required-green proof.
- **Stable-count rationale:** inherited accepted-B red; stable totals are unaffected.

## WU2B-TB-CAND-01 — hard-rail region-copy witness blocked by front-boundary authority on accepted A and B — OPEN HYGIENE / NON-STABLE

- **Observed:** broad WU2B candidate `31915868952 / 95087448907` fails `SurfaceCellsPhase10.HardRailRegionCopiesPairReciprocallyBeforeQuotientMaterialization`: the region producer returns `Declined` with `InvalidFrontBoundaryAuthority` before the intended reciprocal hard-rail copy / quotient-materialization seam.
- **Accepted-baseline differential:** artifact-only `31916254483 / 95088352843` executes the exact same identity on accepted Batch-A source `5e1fed2545ac730c328f1ff475069874a84ec72a` and reproduces the same `InvalidFrontBoundaryAuthority` failure with immutable package/executable state unchanged.
- **Primary category:** `RP-02 / TEST_AUTHORITY_COVERAGE_GAP` — the fixture does not independently establish the front-boundary authority required to reach the semantic seam it claims to validate.
- **Root-cause bound:** evidence proves the red state is inherited and that the earliest failing precondition is front-boundary authority. It does **not** justify a production fix or a more specific deeper fixture cause without a separate Code + Build investigation.
- **Disposition:** non-gating hygiene. Repair or replace the fixture only after independently proving valid front-boundary authority; preserve the reciprocal-copy/materialization assertion. Result evidence: candidate `9254941118` / `28367d7c348f912f46692c57bbc1b2eed19e4dc8f9e720a1984f77a0d7dbd236`, baseline `9254968096` / `9f5f46f5429ddbdbb0c2da5bd36f8de481692980922bdcf0ed1b481ab5d571a2`.
- **Stable-count rationale:** the identity is red on the previously accepted package and no accepted-green behavior is lost. Stable totals at that checkpoint remained **34 events / 14 categories / 20 recurrences**.

## WU2B-TB-CAND-02 — permitted side-repair rollback witness blocked by ownership-registry/domain-identity precondition — OPEN HYGIENE / NON-STABLE

- **Observed:** `PatchDescriptorMilestoneE.PermittedSideRepairFailureReturnsExactRollbackForGeneralCompletion` fails in the broad B candidate with `completion.success=false` and `SuccessfulSubdivisionDomainIdentity;identityFailure=ownership-registry-mismatch`, leaving the expected completion descriptors/quads absent.
- **Accepted-baseline differential:** the exact same identity fails with the same ownership-registry/domain-identity path on accepted Batch-A source under `31916254483 / 95088352843`. This is related to, but distinct from, the existing `WU2A-TB-CAND-01` patch-domain hygiene lineage.
- **Primary category:** `RP-02 / TEST_AUTHORITY_COVERAGE_GAP` — the fixture's prerequisite successful authoritative subdivision/domain identity is not baseline-green, so it cannot prove later permitted-repair rollback semantics.
- **Root-cause bound:** current evidence establishes the earliest failing authority precondition, not the deeper reason that fixture/registry authority disagrees.
- **Disposition:** non-gating hygiene. Independently establish the ownership-registry/domain-identity precondition before re-promoting this rollback witness; do not weaken exact rollback assertions. Evidence: candidate `9254941118`, baseline `9254968096`.
- **Stable-count rationale:** inherited baseline red; no accepted-green behavior was restored then lost. Stable totals at that checkpoint remained **34 / 14 / 20**.

## WU2B-TB-CAND-03 — authoritative-cell-scope subdivision fixture expects unproven region identity — OPEN HYGIENE / NON-STABLE

- **Observed:** `PatchDescriptorMilestoneE.AuthoritativeCellScopeOverridesMultiScopeBoundaryDuringSubdivision` produces provenance `sourceTopologyRegion=9` where the fixture expects region `2` in both the broad B candidate and accepted-A differential.
- **Accepted-baseline differential:** `31916254483 / 95088352843` reproduces the exact region-9-versus-2 assertion failure on accepted Batch-A source with immutable postflight PASS.
- **Primary category:** `RP-02 / TEST_AUTHORITY_COVERAGE_GAP` — the expected source-scope identity is encoded by the fixture without an independently established accepted-green authority derivation.
- **Root-cause bound:** the differential proves inheritance but does not establish whether region 9 or region 2 is semantically correct; changing production or simply updating the expected constant would be unsupported.
- **Disposition:** non-gating hygiene. Re-derive the expected scope from canonical typed authority in a future Code + Build investigation and retain a discriminating assertion. Evidence: candidate `9254941118`, baseline `9254968096`.
- **Stable-count rationale:** exact same red state exists on accepted A; stable totals at that checkpoint remained **34 / 14 / 20**.

## WU2B-TB-CAND-04 — five simplification transaction/support witnesses lack baseline candidate preconditions — OPEN HYGIENE / NON-STABLE

- **Observed identities:** `SurfaceComplexSimplificationPhase17.ComplexRollbackPreservesHashOnRejectedTrial` (`removable=-1`); `CandidateExtractionIsDeterministicAndCarriesAuthoritativeSupport` (empty candidate set); `CandidateExtractionMarksProtectedSupportInsteadOfSilentlyDroppingIt` (`removable=-1`); `TransactionalMutationPreservesHardRailSupport` (`protectedHalfedge=-1`); `RequiredSingularityBridgeIsProtectedAndRollsBackExactly` (required healing candidate absent).
- **Accepted-baseline differential:** `31916254483 / 95088352843` reproduces all five failures with the same assertions on exact accepted Batch-A source. The two independently accepted simplification identity contracts remain green: `CandidateExtractionBaselineForCanonicalSourceScopeIdentityIsNonVacuous` and `CanonicalSourceScopeIdentityIsRowIndependentWithNonVacuousCandidateBaseline`.
- **Primary category:** `RP-02 / TEST_AUTHORITY_COVERAGE_GAP` — these five fixtures do not establish the removable/protected/healing candidate precondition required by their later rollback/support assertions.
- **Root-cause bound:** current runtime proves fixture reachability/precondition failure. It does not justify weakening candidate predicates or synthesizing a candidate in production.
- **Disposition:** non-gating hygiene. Any repair must use a genuinely production-feasible independently proven fixture and preserve strict transaction/rollback/support assertions. Evidence: candidate `9254941118`, baseline `9254968096`.
- **Stable-count rationale:** inherited baseline red across all five identities; stable totals at that checkpoint remained **34 / 14 / 20**.

## WU2B-TB-CAND-05 — FlowRep mandatory-cycle witness lacks successful-selection baseline — OPEN HYGIENE / NON-STABLE

- **Observed:** `FlowRepStrandsPhase15.ProposalRailSegmentsRemainMandatoryCycleEvidence` reaches `selectionSucceeded=false`, so it never establishes the successful sparse-selection precondition needed to credit the later mandatory-cycle evidence assertion.
- **Accepted-baseline differential:** `31916254483 / 95088352843` reproduces the same `selectionSucceeded=false` failure on accepted Batch-A source with immutable postflight PASS. Other selected FlowRep hard-rail provenance contracts are baseline-green and pass WU2B.
- **Primary category:** `RP-02 / TEST_AUTHORITY_COVERAGE_GAP` — the fixture is not a valid accepted-green selection baseline for the claimed cycle-evidence behavior.
- **Root-cause bound:** evidence proves precondition failure only; it does not justify modifying production selection or relaxing the mandatory-cycle requirement.
- **Disposition:** non-gating hygiene. Repair only with an independently demonstrated successful-selection proposal-rail scenario and keep the cycle-evidence assertion strict. Evidence: candidate `9254941118`, baseline `9254968096`.
- **Stable-count rationale:** inherited baseline red; stable totals at that checkpoint remained **34 / 14 / 20**.

## WU2A-TB-CAND-01 — side-subdivision canonical-domain witness is inherited baseline-red — OPEN HYGIENE / NON-STABLE

- **Accepted disposition:** WU2A Batch A is accepted on exact immutable source `5e1fed2545ac730c328f1ff475069874a84ec72a` by corrected artifact-only run/job `31908189133 / 95069151582`. Required-green Batch-A contracts are **43/43**, retained R-C/R-G **67/67**, retained R-B **20/20**, retained R-A **115/115**, F2 **4/4**, and both immutable postflights pass.
- **Observed raw supplemental failure:** semantic run/job `31907649560 / 95067860691` selected **44** dedicated Batch-A identities and reported **43 pass / 1 fail / 0 skip**. The sole failure was `PatchDescriptorMilestoneE.SuccessfulSideSubdivisionPreservesCanonicalDomainIdentity`: `audit_surface_cell_domain_identity` reported `ownership-registry-mismatch`, followed by an active descriptor ownership conflict.
- **Primary category:** `RP-02 / TEST_AUTHORITY_COVERAGE_GAP` — an inherited baseline-red supplemental witness was over-promoted into the required-green Batch-A selection without first establishing a green accepted baseline.
- **Accepted-baseline differential:** artifact-only diagnostic `31908053158 / 95068828434` consumed exact previously accepted R-C source `ec8b3125a62a02f4106599f089d12e7d1c0ccfcb`, independently discovered the same exact identity once, and also reported **0/1 FAIL** with package state unchanged and no rebuild/repair. Result `9252888769` / SHA-256 `09cab334b30c2b2bd90162ad9786965b56496381d80123001d3ebb9672e8158d`; log `9252888883` / SHA-256 `7664f7ff97a7463494561101f8b23006aac25001afc6ea6fc2d7e190234535fc`. This proves WU2A did not introduce the red state; it does not prove the deeper pre-existing fixture/registry root cause, which remains open hygiene.
- **Test-authority correction:** the corrected acceptance harness kept the identity explicitly reported as inherited known-red but removed it from required-green proof. No immutable package, production source, packaged test, fixture, binary, or manifest was changed. Final result `9253004400` / SHA-256 `a330f275682192988786714e6c037874f1b720927f2324d38ddf72963a688f69`; log `9253004614` / SHA-256 `411be79d845e652677a9287a3eae347bfa388c5546a402e72bc8f170a3367a57`.
- **Orchestration-only catches:** initial WU2A run `31907576379` stopped before semantic execution because a retained audit wording marker changed; initial baseline diagnostic `31908004773` stopped before runtime on redirected artifact authentication. Neither is a semantic attempt or regression event.
- **Stable-count rationale:** the exact same test is red on the previously accepted package, while every retained accepted contract remains green on WU2A. No accepted production behavior was lost, restored, then lost again, so stable totals at that checkpoint remained **34 events / 14 categories / 20 recurrences**.
- **Follow-up:** repair or replace this fixture/oracle only after independently proving the intended ownership-registry precondition. Do not weaken its assertions or count it as required-green evidence until that precondition is established.

## R-C-TB2-CAND-02 — checked-Product runtime witness coverage — FULLY RESOLVED / NON-STABLE

- **Final resolution evidence:** immutable `31865263629 / 94965185949` on `ec8b3125a62a02f4106599f089d12e7d1c0ccfcb` passes all 17 exact runtime identities covering all 16 constructible Product error paths, while `InvalidSourceAuthority` remains the one schema-only case. R-C/R-G is **67/67** and immutable postflight passes. The source-audit-overcredit lineage is fully closed.

- **TB3 semantic evidence:** immutable run/job `31862829473 / 94959030721` on exact package source `79393ef49c8c3686ec0833cbc99f0c8f67d5c90b` passes preflight, discovery **17 / 265 / 183 / 84**, all ten newly added checked-Product tests **10/10**, recovery **6/6**, retained R-B **20/20**, F2 **4/4**, and immutable postflight. R-C is **65/67** and retained R-A **114/115**.
- **Resolved portion:** the ten witnesses added by the bounded Code + Build remediation all execute and pass, including `InvalidBoundedDiskRegion` and `DuplicateBoundedDiskRegion`. The original bounded-disk/package-ownership gap is therefore semantically resolved.
- **Superseded assumption:** `.agents/Directional/R_C_Product_Factory_Coverage_Audit.py` credited every pre-existing error-code token in default-built sources as a direct runtime witness. TB3 proves two of those six prior credits are not valid reachability evidence. The overall 16/16 semantic Product-error gate remains open under `R-C-TB3-CAND-01` and `R-C-TB3-CAND-02` below.
- **Artifacts:** result `9241186741` SHA-256 `363e270c5fbeebd2fcf1d366f8862bf4c9624b822062be13c81c1a7131867653`; log `9241187066` SHA-256 `2a2631216ce66f86f2a31469cd3ab4d6300de02fd1961a99d2562d1e7823b26e`.
- **Stable-count rationale:** this lineage remains acceptance-witness/test-authority work; no accepted production behavior is shown lost or restored then lost. Stable totals at that checkpoint remained **34 / 14 / 20**.

## R-C-TB3-CAND-01 — `InvalidCellRegion` replacement witness reaches `InvalidEdgeRegion` first — RESOLVED / NON-STABLE

- **Resolution evidence:** immutable `31865263629 / 94965185949` executes the repaired exact identity on source `ec8b3125a62a02f4106599f089d12e7d1c0ccfcb` and passes the intended `InvalidCellRegion` checked-factory guard. The absent typed region witness no longer reaches `InvalidEdgeRegion` first. No accepted product behavior was lost.

- **Observed:** `SurfaceCellAuthorityContractCutover.ConflictingCellRegionFailsBeforeMaterialization` fails in both R-C and retained-R-A selection. It expects `SurfacePhaseFrontProductErrorCode::InvalidCellRegion`; runtime returns `InvalidEdgeRegion`.
- **Primary category:** `RP-02 / TEST_AUTHORITY_COVERAGE_GAP` — invalid replacement witness / wrong earliest guard.
- **Root cause:** the R-C replacement body changes the first cell from its current region to a *different region already present in the same `SourceTopologyRegions` authority*. Product cell-region membership is therefore valid. The unchanged incident edge retains the old region, so `SurfacePhaseFrontProduct::make` correctly reaches its later edge/cell region-consistency guard and returns `InvalidEdgeRegion`.
- **Accepted-baseline distinction:** the accepted pre-R-C test body did not require this new typed Product error; it mutated the then-public Product and required downstream materialization to fail `AuthoritativePhaseFrontSourceLabelMismatch`. R-C intentionally replaced public mutation with checked construction. The new exact `InvalidCellRegion` reason is an unaccepted replacement-witness requirement, while production remains fail-closed earlier than materialization.
- **Correction:** start from a valid Product, create a valid typed `TopologyRegionId` absent from source authority, assert absence, assign only that ID to one cell, reconstruct through the checked Product factory, and require `InvalidCellRegion`. Do not alter edges, production checks, or validators.
- **Code + Build remediation:** exact source `ec8b3125a62a02f4106599f089d12e7d1c0ccfcb` implements that absent-authority mutation and checked reconstruction; strengthened source audit pins the exact test body and forbids the prior existing-region replacement shape. Compile/package `31864421305 / 94963103637` is green. This is non-runtime evidence; the candidate remains open until the immutable retry reaches `InvalidCellRegion`.
- **Stable-count rationale:** no accepted product behavior is lost; the new replacement witness is malformed for the error it claims to isolate. Stable totals at that checkpoint remained **34 / 14 / 20**.

## R-C-TB3-CAND-02 — `MissingPeriodicRelationOwner` witness blocked by deferred torus failure — RESOLVED / NON-STABLE

- **Resolution evidence:** immutable `31865263629 / 94965185949` executes the repaired direct checked periodic Product witness on `ec8b3125a62a02f4106599f089d12e7d1c0ccfcb` and passes `MissingPeriodicRelationOwner` without entering `torus_fixture()` or deferred `G4-B002`. No accepted product behavior was lost.

- **Observed:** `SurfaceCellTransitionQuotient.MissingPeriodicRelationOwnerIsRejected` throws `torus pipeline producer failed: InvalidHardRailPairing` before its periodic-owner mutation or checked Product construction.
- **Primary category:** `RP-02 / TEST_AUTHORITY_COVERAGE_GAP` — baseline-red/deferred fixture dependency.
- **Root cause:** the test still depends on `torus_fixture()`, which is blocked by known deferred `G4-B002 InvalidHardRailPairing`. R-B already decoupled its periodic-owner reorder invariant from this fixture for the same reason.
- **Correction:** use `direct_periodic_owner_product()` or an equivalent direct checked Product baseline; prove a valid `PeriodicCut` owner exists, clear exactly one owner in copied pre-publication values, reconstruct through the Product factory, and require `MissingPeriodicRelationOwner`. Do not fix/bypass G4-B002 in M1.
- **Code + Build remediation:** exact source `ec8b3125a62a02f4106599f089d12e7d1c0ccfcb` uses `direct_periodic_owner_product()`, proves the selected owner exists in periodic relation authority, clears exactly one owner, and reconstructs through the checked helper; the strengthened source audit forbids `torus_fixture()` for this witness. Compile/package is green. This is non-runtime evidence; the candidate remains open pending immutable semantic proof.
- **Stable-count rationale:** this test is not part of accepted R-A/R-B semantics and never reaches the intended seam; no accepted product behavior is lost. Stable totals at that checkpoint remained **34 / 14 / 20**.

## R-C-TB1-CAND-01 — mandatory source-grid recovery witness absent from immutable package — RESOLVED AT PACKAGE/DISCOVERY

- **Resolution evidence:** TB2 `31859923303 / 94951357157` on exact package source `39ef87cf6d0e35a92b7721031adbbb763bd349fc` independently discovers the six required `MilestoneGP26` recovery identities in `directional_surface_cell_producer_tests`; `.agents/Directional/R_C_Recovery_Package_Coverage_Audit.py` is **6/6 PASS** and historical tests remain OFF.
- **Scope of resolution:** this closes the TB1 package/discovery defect. TB2 did **not** execute the recovery contracts because the later bounded-disk mandatory-coverage check stopped the semantic gate. No recovery semantic-pass claim is made yet.
- **Original evidence:** TB1 `31858506554 / 94947517720`, result/log `9239773538 / 9239773759`, discovered recovery **0** because the contracts were historical-target-only.
- **Stable-count rationale:** package-coverage candidates occur before checkpoint acceptance; neither TB1 nor TB2 demonstrated a failure of previously accepted semantic behavior. Stable totals at that checkpoint remained **34 / 14 / 20**.

## Current R-B-TB2-R3 runtime classification — R-B CLOSED

- **Status:** authoritative immutable `31851663979 / 94928457628` passes preflight, discovery **17 / 249 / 183 / 84**, mandatory identities **6/6 exact-once**, R-B **20/20/0/0**, retained R-A **115/115**, F2 **4/4**, and immutable postflight with zero orchestration failures.
- **Artifacts:** result `9237772411` SHA-256 `d757074a9c7589adbf4fb12168c5b74460efda1eea20d73d9f04a9ce13cbaf1c`; persistent log `9237772573` SHA-256 `d92a208199ae8360c3b10eb2eaf366bfdfb5dab0feef9ff8d56db7dd5a4938cb`.
- **Resolved candidate:** `R-B-TB2-R2-CAND-01 / RP-02 / TEST_AUTHORITY_COVERAGE_GAP`. The strict simplification candidate-extraction companion is baseline-green on the closed periodic toroidal fixture; all row/support/chart identity contracts and retained R-A authority pass organically.
- **Stable-count rationale:** R2/R3 concerned an unaccepted acceptance-witness baseline. The corrected runtime does not demonstrate loss or recurrence of accepted product behavior. Stable totals at that checkpoint remained **34 events / 14 categories / 20 recurrences**.
- **Preliminary orchestration-only attempt:** `31851526497 / 94928068989` stopped before packaged discovery/runtime when the temporary harness transform searched for the wrong quote spelling of the expected-selection predicate. Static inspection had passed; result/log `9237663121 / 9237663340` SHA-256 `b13c34e7ef0e3dde3cae0c8e99ff6bb131fe9139495a41822cd8fb1a01c41be0 / 3e49a1dda7994c4148916280f5ac101980961b3e9e512855ad9169e49e4f54bc`. No generated semantic runtime occurred, so it is excluded from regression counts.
- **Next checkpoint:** work unit 2 Code + Build (R-D.4 + R-G.2, then R-D.5); preserve closed R-A/R-B/R-C authority.

## Current R-B-TB2-R2 runtime classification

- **Status:** R-B remains open. Preflight PASS; discovery **17 / 249 / 183 / 84**; mandatory identities **6/6 exact-once**; R-B **20/19/1/0**; retained R-A **115/115**; F2 **4/4**; postflight PASS.
- **Artifacts:** result `9236929073` SHA-256 `919867cffcee0f0a72c0f1656d8d6a1345fdbf8e21e295f0ca1d2996c710619c`; log `9236929343` SHA-256 `fd21461ad25d09322b5a3b67aab4fe9e337ae28d547b8750ae40f4327891527e`.
- **Observed failure:** only `SurfaceComplexSimplificationPhase17.CandidateExtractionBaselineForCanonicalSourceScopeIdentityIsNonVacuous` fails, at line 170 because no candidate from the one-triangle four-parallel-arc fixture satisfies the strict non-protected/topology-preserving/side-feasible predicate.
- **Primary category:** `RP-02 / TEST_AUTHORITY_COVERAGE_GAP`. The fixture was borrowed from an unselected historical candidate-recomputation test without current runtime proof. Production extraction explicitly treats exterior/boundary participation as protected and requires closed one-boundary-component affected cells for side feasibility; current runtime proves the reused fixture is not a valid acceptance baseline for the requested candidate class.
- **Counterevidence:** the three former R1 failures now pass, all other R-B contracts pass, and retained accepted R-A is fully green. No accepted behavior was restored then lost.
- **Stable-count rationale:** this is an unaccepted acceptance-witness baseline failure, not demonstrated product regression or recurrence. Stable totals at that checkpoint remained **34 events / 14 categories / 20 recurrences**.
- **Correction:** bounded Code + Build `R-B-TB2-R3-CB` must replace only the failing companion fixture with a genuinely production-feasible interior/closed or annular/cylindrical candidate topology, preserve the strict predicate and all current R-B/R-A greens, and execute no generated runtime.

## Rules

## Current R-B-TB2-R3 Code + Build classification — non-runtime

- **Status:** bounded test-authority Code + Build/source-control evidence only. Exact source `2e61dafa4da600608b5b1281d16085d04caeb135`; semantic source delta is one test file, production implementation/validators unchanged, and generated runtime was not executed.
- **Repair:** the failing candidate-extraction companion now uses a direct closed periodic 4x4 toroidal quad complex capable of representing non-boundary closed-cell neighborhoods while preserving the exact strict eligible-candidate predicate. The runtime-green direct canonical source-scope identity contract is unchanged.
- **Evidence:** source audit `31850731957 / 94925875034` PASS/self-tests PASS/**0 forbidden semantic-row findings**; compile `31850731957 / 94925898323` **119/119**, exit `0`, ccache **108/109**; static package inspection `31850731957 / 94926066113` PASS at **26 / 25 / 25**, zero symlinks, five clean source states, 536-member archive SHA-256 `f618a2bcbde5d62fc40fd5981ea9b722499d9e8a652ca43f220c11e0f871e501`.
- **Superseded build catches:** `31850400684` failed a caller static assertion before configure/compile. `31850504085 / 94925286182` reached **118/119** and rejected retired fixture field assignments; the correction removed the stale fields. Neither attempt executed generated runtime. These are orchestration/source-build catches in unaccepted remediation lineage, not semantic regression recurrences.
- **Runtime boundary:** `runtimeExecution=false`; Code + Build cannot resolve `R-B-TB2-R2-CAND-01 / RP-02`.
- **Stable-count rationale:** no accepted runtime behavior was exercised or lost. Stable totals at that checkpoint remained **34 events / 14 categories / 20 recurrences**. The candidate remains pending the immutable R3 semantic retry.
## Current R-B-TB2-R1 remediation Code + Build classification — non-runtime

- **Status:** bounded test-authority Code + Build/source-control evidence only. Exact source `c188b6e82f76d317287dce11ebbffcf31582bb97`; no production source or validator was changed and no generated Directional runtime executed.
- **Repairs:** PatchDescriptor establishes current canonical ownership-registry validity before the unchanged baseline audit; simplification uses a six-strand non-vacuous production candidate baseline before direct scope identity; periodic owner reordering uses direct typed two-relation phase-front/product authority with explicit `PeriodicRelationId` owners and no torus producer/materializer. `G4-B002` remains revised-M4 work.
- **Source/build evidence:** source audit `31839978956 / 94894518575` PASS/self-tests PASS/**0 forbidden semantic-row findings**; compile `31839978956 / 94894518703` **119/119**, exit `0`; inspection `31840183002 / 94895146353` PASS at **26 / 25 / 25**, zero symlinks, five clean source states, 536-member byte-identical source archive. Exact artifact digests are retained in the R-B report/plan.
- **Observed non-runtime catch:** initial caller `31839952660` contained a mistyped full semantic source SHA. Both jobs failed at checkout; configure/build/runtime never began. Corrected exact-source caller `31839978956` supersedes it. This is orchestration/control-plane evidence, not a semantic regression.
- **Stable-count rationale:** Code + Build cannot resolve or create the runtime candidate. No accepted runtime behavior was exercised or lost, so stable totals at that checkpoint remained **34 events / 14 categories / 20 recurrences**. `R-B-TB2-R1-CAND-01` remains pending the next immutable artifact-only retry.


- Assign a stable regression ID only when previously accepted behavior/test/package/public authority is lost.
- Persistence while a gate remains red is not a recurrence; recurrence requires restoration followed by later loss.
- Compile success never resolves runtime or architecture migration work.
- New migration code remains pending until immutable semantic acceptance.
- **Every Test + Benchmark turn MUST, before closure, categorize every observed regression in this tracker and record root-cause analysis.** If evidence is insufficient for a stable regression ID/count, record it explicitly as candidate/non-stable and state why historical totals do not change.
- Known-red/deferred product cases stay explicit and are never relabeled green/expected-failure to close architecture work.
- Focused/helper passes cannot close representative product intent.
- Before every turn review `RP-01` through `RP-09`; every touched pattern needs an exact invariant and counterexample/representative gate.
- Stale per-turn documents are not historical authority. Once their necessary facts are folded into this tracker/current report/audit inventory/changelog, they may be removed under `.agents/Directional/CLEAN_UP_POLICY.md` and `.agents/Directional/RETENTION_POLICY.md`.

## R-B-TB2-R2-CAND-01 — simplification non-vacuity companion acceptance fixture — RESOLVED

- **Status:** resolved by authoritative immutable TB2 R3 `31851663979 / 94928457628` on exact package source `2e61dafa4da600608b5b1281d16085d04caeb135`; R-B closes at **20/20 PASS** with retained R-A **115/115 PASS** and F2 **4/4**.
- **Resolution:** R3 replaced only the invalid one-triangle boundary/exterior baseline with a closed periodic 4x4 toroidal quad complex while retaining `!touchesHardFeature && !touchesBoundary && !touchesSingularity && !changesTopology && sideFeasible`. Production extraction and validators were unchanged. Runtime now finds the required eligible candidate and the companion passes organically.
- **Preservation:** all six mandatory R-B identities resolve exact-once and pass; kernel **3/3**, completion/consumer **7/7**, pipeline **5/5**, digest/periodic-owner **3/3**, validation **2/2**, retained R-A **115/115**, and F2 **4/4**.
- **Primary category:** `RP-02 / TEST_AUTHORITY_COVERAGE_GAP`; the issue was an unaccepted acceptance-fixture baseline, not a production regression.
- **Stable-count rationale:** no previously accepted behavior was lost and no recurrence was established. Stable totals at that checkpoint remained **34 / 14 / 20**.
- **Evidence:** `9237772411 / 9237772573`, SHA-256 `d757074a9c7589adbf4fb12168c5b74460efda1eea20d73d9f04a9ce13cbaf1c / d92a208199ae8360c3b10eb2eaf366bfdfb5dab0feef9ff8d56db7dd5a4938cb`; immutable postflight unchanged.

## R-B-TB2-R1-CAND-01 — prior three-precondition candidate resolved/superseded by TB2 R2

- **Status:** resolved as a three-seam record by `31848878409 / 94920702419`. PatchDescriptor, direct canonical source-scope identity, and periodic owner reordering all pass at TB2 R2.
- **Remaining work:** moved to `R-B-TB2-R2-CAND-01`, which is only the new candidate-extraction companion fixture baseline.
- **Stable-count rationale:** R1 was never accepted and its resolution/supersession changes no stable count.

## R-B-TB2-CAND-01 — mandatory SurfaceArrangement closure witness is source-present but absent from packaged executables

- **Status:** **resolved** package/discovery test-authority record. The semantic retry packages the witness, discovers it exactly once, and it passes. This record remains excluded from stable historical event/recurrence totals.
- **Observed:** immutable TB2 run/job `31832455092 / 94871087169` consumed exact source `6e62ee91e041413b8ba596beab11a9bd67940989` compile/audit/inspection artifacts. Preflight and immutable postflight both PASS. Result `9231190722` SHA-256 `b384c868ac52087a0510dcbf3d2e0fcd5be04fa02a6fdcf25146b6e52492ab12`; log `9231191026` SHA-256 `323f8765a5fc864f4bdda63c96b8ea533ac646c5280a10ace5a3e925917f1b29`.
- **Primary category:** `RP-02 / TEST_AUTHORITY_COVERAGE_GAP`. Classification: **mandatory package/discovery coverage failure**, not a semantic production regression.
- **Discovery:** **17 authority-kernel / 249 producer / 181 completion / 84 validation**. Four mandatory TB2 identities resolve exactly once. `SurfaceArrangementPhase16.FaceInteriorSupportAndChartIdentityAreRowIndependentAndDiscriminating` resolves **0** times, which is an orchestration/package failure under the gate contract.
- **Root cause:** the exact packaged source contains both the SurfaceArrangement test file and mandatory contract, but `cmake/DirectionalTests.cmake` wires `tests/SurfaceArrangementPhase16Tests.cpp` only into `directional_surface_cell_historical_tests`. The immutable package records `DIRECTIONAL_BUILD_HISTORICAL_TESTS=OFF`; the approved compiled-target list and package contain no historical test executable. Therefore Code + Build compiled the contract's source tree but did not package the mandatory runtime identity.
- **Execution boundary:** semantic R-B and retained R-A groups were **not executed** after mandatory discovery failed. This intentionally prevents zero-selected acceptance and preserves the artifact-only gate contract. No semantic pass/fail claim is made for TB2.
- **Immutability:** package manifest remains **25/25**, package/executable state is unchanged, zero symlinks, and `rebuild=false`, `packageRepair=false`, `sourceMutation=false`, `testMutation=false`, `fixtureMutation=false`.
- **Resolution:** completed on source `567c3bc216dd7e018579171257a6d521672b76f5`. The focused SurfaceArrangement witness is owned by `directional_surface_cell_completion_tests`, historical tests remain OFF, source package-membership audit passes, and retry `31837396234 / 94886624691` discovers all five mandatory identities exact-once; the SurfaceArrangement contract passes at runtime.
- **Stable-count rationale:** this package/discovery defect never represented loss of accepted product behavior. Its resolution changes no stable count. The semantic retry is classified separately as `R-B-TB2-R1-CAND-01`; stable totals at that checkpoint remained **34 events / 14 categories / 20 recurrences**.

## Retained R-B-TB2 packaged-witness remediation Code + Build classification — non-runtime history

- **Status:** Code + Build/source-control evidence only; no semantic runtime executed, so this turn creates no stable regression ID/count and does not resolve the existing runtime candidates.
- **Exact final source:** `567c3bc216dd7e018579171257a6d521672b76f5`. The mandatory SurfaceArrangement identity is isolated into a focused default completion-test source; historical tests remain OFF. Production support/chart identity and validators are unchanged.
- **Source-only closure:** `31834855060 / 94878759530` PASS. Row audit self-test PASS with **0 forbidden semantic-row findings**; package-membership audit self-test PASS with exact contract present and one approved default owner. Artifact/log `9232075855 / 9232076284`.
- **Compile/package:** `31834855060 / 94878759748` completed approved targets **119/119**, exit `0`, ccache **108/109**. Result/log `9232100867 / 9232101220`. Package **26 / 25 / 25**, zero symlinks, five clean statuses, exact **536-member** archive `1dbe66ac9d8566ece8aab9b342d1ae480cea97bb867a8a03a7ccc8d3cf63504c`, runtime disabled.
- **Observed non-runtime catch:** first source `77aef16eb83d4d33c7ff799a72f24f09f636e551` wired the entire historical SurfaceArrangement test source into the default completion target. Compilation failed at **118/119** because unrelated historical tests still use retired arrangement/chart APIs. No generated runtime executed. This is a source/build packaging catch in unaccepted remediation lineage, not a semantic regression recurrence.
- **Correction:** package only the required current witness in focused `SurfaceArrangementRowIdentityTests.cpp` and guard exact default ownership source-only. The witness preserves the intended row-invariance and discrimination contract; the current optional resolver API is unwrapped explicitly.
- **Stable-count rationale:** no accepted runtime behavior was lost or executed. `R-B-TB2-CAND-01 / RP-02` and `R-B-TB1-CAND-01` remain pending the immutable semantic retry; stable totals at that checkpoint remained **34 events / 14 categories / 20 recurrences**.

## Current R-B-TB1 remediation Code + Build classification — non-runtime

- **Status:** Code + Build/source-control evidence only; no semantic runtime executed and no stable regression ID/count is created or resolved by this turn.
- **Exact source:** `6e62ee91e041413b8ba596beab11a9bd67940989`. Baseline-green acceptance witnesses now cover PatchDescriptor row identity, direct SurfaceArrangement canonical support/chart identity, direct SurfaceComplexSimplification canonical scope identity with a non-vacuous candidate baseline, strengthened valid HardRail chart row invariance, and typed periodic owner/container reordering before the known M4 materialization blocker.
- **Source-only closure:** `31829422657 / 94861261003` PASS, self-test PASS, **0 forbidden semantic-row findings**; artifact/log `9230079391 / 9230079846`.
- **Compile/package:** `31829482881 / 94861462716` completed approved targets **118/118**, exit `0`, ccache **107/108**; result/log `9230130409 / 9230130756`. Independent inspection `31829747052 / 94862329932` PASS: **26 / 25 / 25**, zero symlinks, five clean statuses, exact **534-member** archive `d76cc034a8b3aed83d834fff3c2cdf419f56497a31343558e4f0bc9a50276aec`.
- **Observed non-runtime catches:** an initial malformed temporary payload failed before source mutation; intermediate source `41d5f795...` compiled only to **102/118** because new test code used stale test-side APIs (`SurfaceSimplificationCandidateSet`, `SourceChartTransitionGraph`, and `DomainResult` ingress); a superseded package-inspection attempt used a stale hardcoded archive-member count. Each was corrected before final evidence and before any generated runtime.
- **Classification:** orchestration/source-build catches in unaccepted remediation lineage, not losses of accepted product behavior and not semantic regression recurrences. `runtimeExecution=false` throughout Code + Build.
- **Stable-count rationale:** no new semantic runtime result exists. `R-B-TB1-CAND-01` remains open until TB2 executes the new package; stable totals at that checkpoint remained **34 events / 14 categories / 20 recurrences**. Immutable TB1 subsequently classified all runtime observations under `R-B-TB1-CAND-01`.

## R-B-TB1-CAND-01 — R-B closure selection uses baseline-red/deferred witnesses and misses direct changed-consumer discrimination

- **Status:** candidate/non-stable test-authority record; R-B remains open. Not included in stable historical event/recurrence totals.
- **Observed:** corrected immutable TB1 run/job `31824473557 / 94845218480` on exact source `d974d7dd378034d74da457b211149f7f052568dd`; preflight/discovery/postflight PASS, R-B **21 unique / 15 pass / 6 fail / 0 orchestration failures**, retained R-A **115/115 PASS**. Result `9228364900` SHA-256 `4b448c70765d0ee9e8a3b131029a7c269213661765bd648a4ba54bd95fb47fb0`; log `9228365456` SHA-256 `b601da218185a7da3c8bc89de3be330c0af22d941e35846eba6c4d055514b27b`.
- **Primary category:** `RP-02 / TEST_AUTHORITY_COVERAGE_GAP`. Unit-test review classification: **invalid acceptance witnesses / missing scenario coverage**, not a demonstrated production regression.
- **Six observations:** `MultiplePeriodicRelationsSurviveRelationReorderingByExplicitOwner` stops at known `InvalidHardRailPairing`; three PatchDescriptor witnesses start from invalid/no-repair authoritative state; the simplification witness produces no candidates; the multi-rail validator witness starts from an invalid source chart.
- **Baseline discrimination:** five of the six fail at the same earliest precondition/assertion on the exact accepted R-A retry-16 package/source before the R-B cutover. The torus relation-order witness reaches existing `G4-B002 InvalidHardRailPairing`, already assigned to revised M4. Therefore none is evidence that R-B lost accepted R-A behavior.
- **Escape mechanism:** the R-B package contains strong new kernel/pipeline/digest evidence, but the closure selector reused old PatchDescriptor/simplification/validator tests without first proving their baseline preconditions and used a later-milestone torus blocker as an ordering oracle. Changed SurfaceArrangement/SurfaceComplexSimplification canonical support/chart serialization is not covered by a clean direct packaged runtime witness starting from valid authority.
- **Correction:** Code + Build remediation is complete on exact source `6e62ee91e041413b8ba596beab11a9bd67940989`. `DomainIdentityIsIndependentOfSourceFaceRowOrder` now establishes a valid PatchDescriptor baseline; new direct arrangement/simplification contracts prove canonical row/order invariance and discrimination with valid/non-vacuous preconditions; the valid HardRail chart witness is strengthened; and `PeriodicRelationOwnersSurviveContainerReorderingBeforeMaterialization` isolates typed relation-owner reordering before `G4-B002`. Production and validators were not weakened. Runtime resolution remains pending immutable TB2.
- **Preservation evidence:** R-B kernel **3/3**, pipeline **5/5**, benchmark digest **2/2**, selected completion/source-support **3/3**, selected validator **2/2**, source-only audit, and the complete retained R-A **115/115** gate are green.
- **Preliminary orchestration note:** run `31823694174 / 94842721246` reached the same R-B semantic **15/21** state and green executed R-A groups, then failed final evidence capture because the temporary harness searched for stale F2 source-token names. Corrected run `31824473557` changed only external evidence-token capture and completed immutable postflight; the preliminary run is orchestration-only evidence.
- **Stable-count rationale:** no previously accepted behavior is shown lost. Five failures predate R-B and one is an existing deferred blocker; stable totals at that checkpoint remained **34 events / 14 categories / 20 recurrences**.

## Retained R-B Code + Build source/build classification — non-runtime history

- **Status:** retained Code + Build source/build history. These catches occurred before R-B runtime and created no stable regression ID/count; current runtime classification is `R-B-TB1-CAND-01` above.
- **Observed during Code + Build:** compile/source-audit iterations exposed incomplete semantic-row migration at remaining consumers, attempts to default-construct strong `SemanticId`-backed `SourceVertexId` arrays, and a benchmark semantic-record serialization typo. Each failure occurred during source-only audit or compilation before generated Directional runtime.
- **Correction:** final exact source `d974d7dd378034d74da457b211149f7f052568dd` passes the source-only R-B audit with **0 forbidden semantic-row findings** and compiles/packages approved targets **118/118**, exit `0`, in run/job `31821301314 / 94834955373`. Package metadata records `runtimeExecution=false`.
- **Classification:** these are implementation/build catches in an unaccepted R-B candidate lineage, not loss of previously accepted runtime behavior. They are excluded from semantic regression recurrence accounting.
- **Stable-count rationale:** this retained Code + Build turn had no semantic runtime evidence and therefore did not change counts. Immutable TB1 subsequently classified all runtime observations under `R-B-TB1-CAND-01`; stable totals at that checkpoint remained **34 events / 14 categories / 20 recurrences**.

## Historical PR-wide authority

- **39 distinct regression events**;
- **14 architectural categories**;
- **25 recurrences**;
- **115 regression-bearing result-document commits**.

T1 artifacts `9040549377 / 9041289209`, accepted M1a artifact `9041930767`, accepted M1b artifact `9042940168`, accepted M1c artifact `9043971772`, accepted M1d artifact `9046308272`, accepted M1e artifact `9049125645`, and accepted M1f artifact `9050850344` create no new production regression event or recurrence. M1f runtime authority is accepted. Accepted M1g artifact `9053047653` likewise creates no stable product regression event or recurrence; M1g semantic acceptance is complete. M1h artifact `9066967620` created no stable product regression event: its sole focused failure was classified as a test-authority witness defect while all entering product/preservation authority remained unchanged. Remediation artifact `9069186973` is now immutable accepted with focused **6/6**, required-green **187/187**, full entering preservation/direct-product authority, unchanged historical-red classes, and exact postflight. M1i implementation `b037157921094604f1b0c17f9c8b7076c7604b3b` is immutable accepted from artifact `9072101943`: focused **6/6**, required-green **193/193**, full entering preservation/direct-product authority, unchanged historical-red classes, bounded Bunny/Vase comparison, and exact postflight. No stable product regression event or recurrence is added. `PR8-R034 / G4-R007` remains active. M1j implementation `d5f681173600dc32dc7617de6105d9e584e593be` is immutable accepted from artifact `9076217893`: producer discovery **214**, focused **6/6**, required-green **199/199**, full entering preservation/direct-product authority, all eight historical-red classes unchanged, strict timing truthfully **0/10**, bounded Bunny/Vase comparison, and exact **67/67** postflight. No stable product regression event or recurrence is added. M1k implementation `b9181364926cea840e9cb50da21fe721f33fd874` is immutable accepted from artifact `9079318682` and runtime evidence `9080245848`: producer **220**, focused **6/6**, required-green **205/205**, full entering preservation/direct-product authority, all eight historical-red classes unchanged, Bunny/Vase dispositions preserved, and exact **68/68** postflight. Strict timing sampled **10/10** but remains the existing nondeterministic microbenchmark classification. The local extraction/harness anomalies and first remote evidence-upload-path failure are infrastructure only. No stable product regression event or recurrence is added. M1l implementation `bd140cff4572412e6f4ecd70a6ce0fe85310932c` is immutable accepted from artifact `9083262395` and runtime evidence `9083913766`: producer **226**, focused **6/6**, required-green **211/211**, full M1k-M1b/validation/M1a/T1/direct-product preservation, all eight historical/deferred red classes unchanged, strict timing truthfully sampled **10/10** while remaining deferred, Bunny/Vase dispositions preserved, and exact **56/56** postflight. The local first-process Cylinder stall did not reproduce remotely and is execution-plane only. No stable product regression event or recurrence is added.

Current R-A semantic runtime note: retry 16 `31808562013 / 94793328201` on exact source `588a58935b481943eea9f8424e9897d6a1a44454` completed **112 unique / 112 pass / 0 fail / 0 skipped / 0 orchestration failures**. Runtime result `9222292493` SHA-256 `fadb19ab943b0da904856a9499c69b6ddd4790528af7d4fc8e12f7a1c56227d3`; log `9222293094` SHA-256 `30449ebca6273ab751c8e6dc19feff1bbdc7defe692f0bf128c9d47af199780c`. Preflight, byte-identical REV-35, discovery, eight mandatory exact-once contracts, F2 **4/4**, and immutable postflight all pass. No semantic regression was observed. Preliminary run `31808413434 / 94792837677` is infrastructure-only: harness transformation failed before artifact download/runtime and is excluded from semantic counts.

Current R-A package-closure note: `R-A-R12-CAND-01 / RP-02` remains **resolved**; mandatory isolation selects exactly **1** and passes **1/1**.

Current R-A production-classification note: `R-A-R11-CAND-01` remains resolved at hard-feature/isolation-sheet classification, and `R-A-R13-CAND-01 / RP-01 + RP-05` remains resolved at aggregate-remap/final-oracle production. Retry-16 authority-contract cutover is **41/41**, feature chain **6/6**, and all strict retained product groups are green.

Current R-A test-authority note: `R-A-R14-CAND-01 / RP-02` remains resolved at its old unrelated phase-front-fixture seam. `R-A-R15-CAND-01 / RP-02` is now **resolved** by immutable retry 16: the repaired direct-remap identity selects exactly once and passes **1/1**, all six produced shared-HardRail-fixture diagnostics select exactly once and pass **6/6**, and the full gate is **112/112**. Product behavior remains strict and historical totals at that checkpoint were **34 / 14 / 20**.

### R-A-R15-CAND-01 — mandatory direct remap witness mixes global source topology with compact component-local topology

- **Status:** **resolved** candidate/non-stable test-authority record; retry-16 reaches and passes the intended direct typed-remap seam; excluded from stable historical event/recurrence totals.
- **Observed:** immutable retry 15 `31799783107 / 94764797160` on exact source `7b125ad318078477b83bb7a24c6dca89943ac724`; **106 unique / 105 pass / 1 fail / 0 skipped / 0 orchestration failures**. Result `9218898728` SHA-256 `9c2b4589e3714cde6eddc43ad56ab8b3fecbf0af09c772647fbab3d63e4fe560`; log `9218898992` SHA-256 `a034de5e60b5fe8bc2c8a39e245fd178a92c8fe104f2fb5fc2ef5d6eaef4f856`.
- **Primary category:** `RP-02 / TEST_AUTHORITY_COVERAGE_GAP`. Unit-test review classification: **invalid fixture / authority-domain mismatch**.
- **Symptom:** `ComponentTypedAuthorityRemapRequiresCapturedHardFeatureChartDomain` selects exactly **1** and reaches direct setup, but fails at `ASSERT_TRUE(hardAwareDomain.has_value())` (`SurfaceCellTransitionQuotientTests.cpp:1686`). The previous `InvalidFrontBoundaryAuthority` producer exception is gone.
- **Root cause:** the test constructs `SourceTopologyRegions` from global `mesh.F` and global HardRail edges `(1,4)/(4,7)`, then supplies `components.front()` from `compact_face_components`. `compact_face_component` assigns local vertex IDs by first source-face encounter and rewrites `component.faces`; for this witness global face row 0 `(0,1,4)` becomes local `(0,1,2)`. `make_component_typed_authority_remap_domain(...)` correctly requires `sourceAuthority.matches_source_faces(component.faces, component.originalVertices.size())` and therefore returns `nullopt` before chart-domain semantics. The intended local HardRail chain is likewise `(local(1), local(4), local(7))`, not the unremapped global keys.
- **Product discrimination:** retry-15 cutover **41/41**, feature chain **6/6**, hard-rail transport **5/5**, direct materializer/local-sheet **2/2**, strict validators, rail authority, and F2 **4/4** all pass. Production aggregation supplies each compact component's own `componentResult.surfaceCellContext.sourceTopologyRegions`, so the helper's local-domain precondition is satisfied in the organically green product path.
- **Correction:** build the direct witness source authority from `component.faces`; derive original→local vertex IDs from `component.originalVertices`; remap original HardRail `(1,4,7)` into local edge keys; explicitly require `sourceAuthority.matches_source_faces(component.faces, component.originalVertices.size())`; then preserve **2 regions / 1 sheet**, barrier-sensitive chart evidence, hard-aware remap success, and explicit-barrierless fail-close. Do not modify production to accept mismatched authority.
- **Coverage amendment:** the six genuine produced consumers of the retry-15 shared `hard_rail_fixture()` were outside the authoritative R-A selection. Supplemental exact-package local diagnostics are **6/6**, but retry 16 must promote those six identities to package-specific mandatory discovery/runtime evidence.
- **Recurrence guard:** REV-35 must structurally pin component-local authority construction, local HardRail remap, exact source-face ownership precondition, mandatory identity uniqueness, and package membership of the six produced shared-fixture contracts.
- **Retry-16 Code + Build correction:** semantic test/static commit `de533350fb39886b21b85aa70ac0a0ddce2bd627` constructs `SourceTopologyRegions` from `component.faces`, remaps original HardRail `(1,4,7)` through `component.originalVertices`, explicitly asserts exact compact topology ownership plus **2 regions / 1 sheet**, and retains the hard-aware/barrierless oracle. REV-35 is **21 / 100 / 410 / PASS** with new guards **14/14**; exact clean source `588a58935b481943eea9f8424e9897d6a1a44454` compiles/packages **118/118**, exit `0`. No production/validator changed and no generated runtime executed.
- **Retry-16 runtime resolution:** authoritative run/job `31808562013 / 94793328201` passes the repaired mandatory remap **1/1**, all six changed produced shared-HardRail diagnostics **6/6**, and the full deduplicated gate **112/112** with zero orchestration failures. Result `9222292493` / log `9222293094`; F2 remains **4/4** and immutable postflight is clean.
- **Stable-count rationale:** this was a non-stable invalid-fixture candidate in unaccepted remediation lineage; retry16 restores the intended test seam without any loss of accepted product behavior. No new stable event or recurrence is created. Stable totals at that checkpoint remained **34 events / 14 categories / 20 recurrences**.

### R-A-R10-CAND-01 — regional `FieldChartId` ordinal published as canonical source-chart identity

- **Status:** candidate/non-stable regression record; mandatory Test + Benchmark classification, not included in stable historical event/recurrence totals.
- **Observed:** R-A retry 10, exact source `b3dc5c3fc6a7d4d9e88873c026021ad955939cab`, runtime `31755283604 / 94629617727`, semantic **95/103 pass, 8 fail**.
- **Primary categories:** `RP-01 / AUTHORITY_DOMAIN_CONFLATION` and `RP-05 / REPRESENTATION_DEPENDENT_IDENTITY`. Detection escaped through `RP-02 / TEST_AUTHORITY_COVERAGE_GAP`.
- **Symptom:** both direct authoritative materializer/local-sheet contracts fail. After the shared ownership closure, HardRail owners expose only one source-chart component/topology region while retaining cross-rail equivalence; strict source-authoritative validation rejects `LocalSheetMismatch`. Dependent feature/final-oracle contracts remain blocked, and the strengthened final-oracle negative correctly reports an unreached callback instead of crediting `mutated=false`.
- **Root cause:** `build_planar_phase_frame` assigns `LocalLatticeState::sourceChart` from a region-local chart ordinal (`legacyFaceChart`), while `SourceChartTransitionGraph` separately owns canonical chart identity over the full source-face domain with hard-feature barriers. Periodic and bounded regional producers also contain a local single-chart semantic writer. `build_authoritative_phase_front_mesh` legitimately treats producer `sourceChart` as semantic lineage, so a local ordinal can collide with a different canonical chart. The shared closure then correctly rejects the mismatched retained chart and exposes the upstream authority split.
- **Escape mechanism:** earlier contracts proved strong `FieldChartId` construction, closure placement, owner/route cardinality, and downstream strict validation, but did not assert at the **producer publication boundary** that each regional cell/segment chart equals the canonical full-source chart for its exact source face. A local ordinal could therefore survive compile/static checks until the direct retry-10 materializer contract exercised a multi-region HardRail collision.
- **Containment/correction:** establish one canonical `SourceChartTransitionGraph` authority domain from exact source faces/topology/hard-feature barriers; regional producers consume that exact face-to-chart identity. Keep branch rotation/parameterization as separate representation state. Remove local semantic chart writers; do not repair downstream, union unrelated charts, infer from output geometry, or renumber for a fixture.
- **Recurrence guard:** REV-30 must structurally forbid local chart writers and require canonical publication; a direct pre-materialization contract must compare every published regional `sourceChart` to `SourceChartTransitionGraph::chart(face)` and prove HardRail-separated regional copies carry distinct canonical identities where required. Existing post-materializer strict positives/negatives remain mandatory.
- **Stable-count rationale:** retry 10 is remediation-candidate evidence, not accepted-lineage evidence. It refines the already-open `LocalSheetMismatch` cluster rather than proving a newly lost accepted M1l behavior; stable totals at that checkpoint remained **34 events / 14 categories / 20 recurrences**.

### R-A-R11-CAND-01 — hard-feature rail barrier reused as isolation-sheet authority

- **Status:** candidate/non-stable regression record; mandatory Test + Benchmark classification, not included in stable historical event/recurrence totals.
- **Observed:** R-A retry 11, exact source `b75a2ee7aabd2478587ac80f2d5b6b671cbbb079`, runtime `31759986180 / 94644068840`, semantic **98/104 pass, 6 fail**.
- **Primary category:** `RP-01 / AUTHORITY_DOMAIN_CONFLATION`. Detection escaped through `RP-02 / TEST_AUTHORITY_COVERAGE_GAP`.
- **Symptom:** the canonical writer contract and both direct materializer/local-sheet contracts pass, but the full rectangular feature-bearing production witness still fails `NotProductionReady:completion:LocalSheetMismatch`. The feature tamper test stops at completion instead of component merge, and three final-oracle feature contracts plus the strict HardRail final-oracle negative never reach their intended callbacks.
- **Root cause:** the full production path calls `classify_source_surface_labels(..., hardFeatureRailEdges, ...)` and publishes its `localSheetByFace` as `sourceFaceSheets`. In that classifier the supplied barrier set terminates local-sheet adjacency. Independently, `build_source_topology_regions(...)` already uses hard features as topology-region barriers, and `SourceChartTransitionGraph` uses them as chart barriers. The same hard rail is therefore incorrectly promoted into `IsolationSheetId` authority. `close_completion_lineage_source_authority(...)` correctly requires retained cross-HardRail charts to stay on the selected isolation sheet, so it rejects the opposite-side chart after production has assigned a different sheet and strict validation reports `LocalSheetMismatch`.
- **Escape mechanism:** the direct rectangular phase-front fixture sets `sourceFaceSheets` to one explicit sheet while supplying hard-feature edges separately. It therefore proves closure semantics under a valid same-sheet HardRail witness but does not exercise production source-label classification, allowing the hard-feature→sheet alias to survive while the direct writer/materializer tests turn green.
- **Containment/correction:** separate isolation-sheet classification from hard-feature rail authority. Hard rails remain topology-region/chart/rail/feature barriers; only actual isolation-sheet authority or an independently declared isolation-barrier set may split `sourceFaceSheets`. Preserve the shared closure's same-sheet requirement and strict `LocalSheetMismatch`; do not broaden closure across sheets or weaken validators. Add a production-path positive proving a hard rail does not automatically create an isolation sheet and a counterexample proving a genuine isolation barrier still does.
- **Code + Build correction:** exact compile source `8ea8dd944eea83fe830a51f68589c213c8f21f14` stops passing the full hard-feature rail set into production sheet classification, compiles a production **2-region / 1-sheet** witness and an explicit independent isolation-barrier sheet-splitting counterexample, and extends REV-31 to **20 / 85 / 388 / PASS** with all **10/10** prior convergence guards. Compile `31762721890 / 94652261378` is **118/118**, exit `0`; no generated runtime executed.
- **Recurrence guard:** REV-31 forbids direct aliasing of the full `hardFeatureRailEdges` set into production isolation-sheet classification and preserves all REV-30 guards. Runtime retry 12 must distinguish hard-feature region/chart separation from independent isolation-sheet separation and require the feature-bearing production witness to reach aggregation/final-oracle seams.
- **Retry-13 runtime proof:** intended seam corrected. Both rectangular feature components are `Produced`, each publishes **2 topology regions / 1 isolation sheet**, and `ComponentFeatureRailTamperRejectsAtAggregationSeam` now passes. The remaining failure is later aggregate chart remap, not `LocalSheetMismatch`.
- **Stable-count rationale:** retry 11 is remediation-candidate evidence, not accepted-lineage evidence. It refines the still-open R-A feature-chain cluster rather than proving newly lost M1l behavior; stable totals at that checkpoint remained **34 events / 14 categories / 20 recurrences**.

### R-A-R12-CAND-01 — required isolation-barrier contract excluded from immutable R-A package

- **Status:** candidate/non-stable package-closure record; excluded from stable totals.
- **Observed:** `31764157297 / 94656475630` on `9205314649` / `8ea8dd944eea83fe830a51f68589c213c8f21f14`. Integrity/REV-31/discovery/postflight passed; semantic bodies were not started.
- **Primary category:** `RP-02 / TEST_AUTHORITY_COVERAGE_GAP`.
- **Root cause:** `SurfaceCellTracingPhase14.SourceClassifierExplicitIsolationBarrierSplitsOtherwiseConnectedSheet` exists in `tests/SurfaceCellTracingPhase14Tests.cpp`, but that source is only in `directional_surface_cell_historical_tests`; the package has `DIRECTIONAL_BUILD_HISTORICAL_TESTS=OFF` and omits the target. Overall compile success was incorrectly used as proxy for contract-specific package membership.
- **Escape:** REV-31 guarded production authority but not newly declared contract → packaged-target closure.
- **Correction/guard:** place one authoritative isolation-barrier counterexample in an approved packaged R-A target and require every package-specific mandatory identity to resolve/select >0 before semantic execution. Prefer surgical producer-target placement over broad historical enablement.
- **Code + Build correction:** exact source `efe3c013b5deff4115b5f84d5c53e8f69163fdcd` moves the unchanged behavioral counterexample into `tests/SurfaceCellsPhase10Tests.cpp`, removes the historical duplicate, and adds REV-32 exactly-one/source-target/outside-historical-gate membership guards. REV-32 is **21 / 89 / 391 / PASS**, **10/10** retained convergence and **4/4** membership; compile `31766052818 / 94662111896` is **118/118**, exit `0`.
- **Retry-13 runtime proof:** **resolved at the package/test-authority seam**. Discovery is **14 / 247 / 180 / 84**; the mandatory identity selects **1** from `directional_surface_cell_producer_tests` and passes **1/1**.
- **Stable-count rationale:** `8ea8dd944eea83fe830a51f68589c213c8f21f14` was never runtime accepted and retry 12 ran no semantic body; no accepted M1l behavior loss is established. Totals at that checkpoint remained **34 / 14 / 20**.

### R-A-R13-CAND-01 — aggregate typed authority remap reconstructs canonical source charts without HardRail barriers

- **Status:** candidate/non-stable production-authority record, **runtime-resolved at its intended aggregate-remap/final-oracle seam by retry 14**; excluded from stable totals because the remediation lineage has not yet achieved full R-A acceptance.
- **Observed:** immutable retry 13 `31767176830 / 94665335666` on exact `efe3c013b5deff4115b5f84d5c53e8f69163fdcd`; **105 unique / 100 pass / 5 fail / 0 skipped / 0 orchestration failures**. Runtime result `9206797766` / log `9206797939`.
- **Primary categories:** `RP-01 / AUTHORITY_DOMAIN_CONFLATION` and `RP-05 / REPRESENTATION_DEPENDENT_IDENTITY`. Detection escaped through `RP-02 / TEST_AUTHORITY_COVERAGE_GAP` because producer/materializer chart convergence was covered before aggregate remap chart reconstruction was independently pinned.
- **Base failure:** `RectangularInternalHardFeatureProducesAuthoritativePhaseFrontPerComponent` organically satisfies its fixture/precondition facts — both components inspected, both producers `Produced`, **2 topology regions / 1 isolation sheet** — then fails `NotProductionReady:component-merge-authority:InvalidFinalValidationAuthorityRemap`.
- **Dependent failures:** `FinalOracleRejectsMissingForeignOrUncertifiedHardRailChartAuthority`, `FinalMergedOracleRejectsMissingRemappedFeatureAuthority`, `FinalMergedOracleRejectsChangedRemappedFeatureRailContent`, and `FeatureBearingFinalMergedOracleAcceptsPresentRemappedFeatureAuthority` all correctly fail their callback/non-empty-authority non-vacuity assertions because the base aggregate never reaches final validation/oracle. They are not four independent root causes and must not be weakened or credited as intended-oracle evidence.
- **Root cause:** component phase-front canonical chart writers construct `SourceChartTransitionGraph` with exact HardRail barriers. The graph otherwise unions incident faces in the same source component. Component final-validation capture retains the same hard-feature edge authority from `authoritativeRails`. Aggregate `make_component_typed_authority_remap_domain(...)`, however, reconstructs `SourceChartTransitionGraph(component.faces, sourceAuthority)` with no barrier set and publishes that second chart domain as `localChartsByFace`. `remap_component_typed_lineage_authority(...)` requires exact captured-lineage chart equality against that reconstructed domain, so valid hard-feature-aware lineage fails closed during final-validation authority remap.
- **Why this is production, not fixture:** the representative fixture now proves the intended component producer, region, and sheet preconditions organically; `ComponentFeatureRailTamperRejectsAtAggregationSeam` passes, proving the aggregation seam is reached; mandatory isolation, hard-rail transport, direct materializer/local-sheet, F2, completion, optimizer, rail, and source-validator groups remain green.
- **Correction:** validate captured component authority/rail equality before remap-domain construction; derive exact local hard-feature barriers from the captured authoritative HardRails; require the aggregate remap domain to build canonical charts with those same barriers. Do not infer from output geometry/options, silently default empty, merge chart domains, or weaken strict validators.
- **Recurrence guard:** REV-33 must require an explicit barrier input on aggregate typed remap, pin `SourceChartTransitionGraph(..., &hardFeatureEdges)`, require the caller's barriers to come from captured authoritative rails, and forbid a barrier-less production call. A focused positive/counterexample pair must validate the aggregate remap seam directly.
- **Retry-14 Code + Build correction:** exact source `fe6d88af0bad157f888c6d7352ea62d0745c626e` validates captured rail authority before remap, derives the aggregate barrier set from captured authoritative HardRails, makes `SourceChartTransitionGraph` barrier authority required by reference, uses explicit empty authority for genuine no-feature sites, and compiles a barrier-sensitive remap counterexample. REV-33 is **21 / 93 / 396 / PASS**, with construction-site closure **6/6**; compile is **118/118**. Runtime proof remains pending retry 14.
- **Retry-14 runtime proof:** exact source `fe6d88af0bad157f888c6d7352ea62d0745c626e`, run/job `31774574854 / 94687254679`: authority-contract cutover **41/41**, feature chain **6/6**, including the former base witness and all four dependent final-oracle contracts. The aggregate HardRail-aware remap correction therefore works organically through final oracle/publication. The sole retry-14 failure is an unrelated mandatory-test fixture defect recorded as `R-A-R14-CAND-01`.
- **Stable-count rationale:** `efe3c013b5deff4115b5f84d5c53e8f69163fdcd` is an R-A remediation candidate, not accepted-lineage authority. The five failures refine the continuous open R-A authority-convergence chain rather than proving a newly lost accepted M1l behavior. Historical totals at that checkpoint remained **34 events / 14 categories / 20 recurrences**.

| Cause category | Pattern | Events | Recurrences |
|---|---|---:|---:|
| `AUTHORITY_DOMAIN_CONFLATION` | `RP-01` | 7 | 6 |
| `TEST_AUTHORITY_COVERAGE_GAP` | `RP-02` | 7 | 6 |
| `POLICY_STAGE_STATE_CONFLATION` | `RP-03` | 4 | 3 |
| `NONTERMINATING_CUMULATIVE_WORK` | `RP-04` | 3 | 2 |
| `REPRESENTATION_DEPENDENT_IDENTITY` | `RP-05` | 2 | 1 |
| `STATE_CARDINALITY_GROWTH` | `RP-06` | 2 | 1 |
| `CYCLIC_TOPOLOGY_LINEARIZATION` | `RP-07` | 2 | 1 |
| `PRODUCER_DISPOSITION_CONFLATION` | `RP-08` | 2 | 1 |
| `LOCAL_CONSUMPTION_OF_GLOBAL_AUTHORITY` | `RP-09` | 2 | 1 |
| five singleton categories | — | 5 | 0 |
| **Total** |  | **34** | **20** |

Singletons: `INTRINSIC_SUPPORT_OVERCONSTRAINT`, `INCOMPLETE_TRANSACTIONAL_ROLLBACK`, `SHARED_EDGE_ORIENTATION_INVERSION`, `INCOMPLETE_ORBIT_PUBLICATION`, `EXACT_SIMPLEX_CANONICALIZATION_LOSS`.


### R-A-R14-CAND-01 — mandatory aggregate-remap contract is blocked by a pre-existing non-producing hard-rail fixture

- **Status:** candidate/non-stable test-authority fixture record; sole retry-14 failure; excluded from stable historical event/recurrence totals.
- **Retry-15 resolution:** resolved at this old producer-fixture seam. The mandatory contract now reaches direct remap-domain construction; the remaining retry-15 failure is separately classified as `R-A-R15-CAND-01`.
- **Observed:** immutable retry 14 `31774574854 / 94687254679` on exact `fe6d88af0bad157f888c6d7352ea62d0745c626e`; **106 unique / 105 pass / 1 fail / 0 skipped / 0 orchestration failures**. Runtime result `9209439245` / log `9209439558`.
- **Primary category:** `RP-02 / TEST_AUTHORITY_COVERAGE_GAP`. Unit-test review classification: **invalid fixture / wrong test level**.
- **Symptom:** `SurfaceCellTransitionQuotient.ComponentTypedAuthorityRemapRequiresCapturedHardFeatureChartDomain` selects exactly **1** but throws `hard-rail rectangle producer failed: InvalidFrontBoundaryAuthority` in `hard_rail_fixture()` before either hard-aware or explicit-barrierless `make_component_typed_authority_remap_domain(...)` assertion executes.
- **Root cause:** the mandatory test is a direct typed-remap contract but obtains `SourceTopologyRegions` by running a full phase-front producer through `hard_rail_fixture()`. The shared 2x1 internal-HardRail helper calls `build_surface_cell_network(...)` and then `require_produced`; that setup does not produce and therefore cannot structurally exercise the remap contract. Exact source history shows the helper implementation predates retry 14 unchanged, so the failure is not introduced by the CB-05/CB-06 production repair.
- **Product discrimination:** retry-14 `SurfaceCellAuthorityContractCutover.*` is **41/41**, the previously red feature chain is **6/6**, direct materializer/local-sheet **2/2**, hard-rail transport **5/5**, and F2 **4/4**. `R-A-R13-CAND-01` is therefore green at the intended production seam while this new test fails earlier in unrelated setup.
- **Correction:** directly build the mandatory remap witness's source mesh, one-component/one-sheet `SourceTopologyRegions`, and explicit HardRail barriers using `build_source_topology_regions(...)`; require a barrier-sensitive chart witness; preserve hard-aware remap success and explicit-barrierless fail-closed semantics. Separately inventory all **9** shared `hard_rail_fixture()` consumers: direct authority tests should not invoke phase-front production, while genuine HardRail transport/materialization tests should use a known production-feasible internal-midline fixture and retain `require_produced`.
- **Code + Build correction:** retry-15 semantic test/static commit `70f7b9e0566f253d35c25517dacf0ced3c81820e` makes the mandatory remap witness direct/self-contained with explicit HardRail-aware source topology and barrierless counterexample, isolates the three direct typed tests from phase-front production, and moves the six genuine produced-network consumers to the known production-feasible 3x3 internal-midline HardRail fixture with explicit authoritative rail and `require_produced`. REV-34 is **21 / 96 / 399 / PASS** with custom guards **15/15**; clean source `7b125ad318078477b83bb7a24c6dca89943ac724` compiles **118/118**, exit `0`, into immutable result `9212050099`. No production implementation/validator changed and no generated runtime executed. Runtime retry 15 is required before resolving this candidate.
- **Recurrence guard:** REV-34/package authority must require the mandatory remap identity exactly once, forbid its coupling to `hard_rail_fixture()`/`build_surface_cell_network`, and keep explicit setup non-vacuity so a mandatory contract cannot be credited when it never reaches its intended seam.
- **Stable-count rationale:** retry 14 is still an unaccepted R-A remediation lineage, the sole failure is test authority rather than lost accepted product behavior, and M1l behavior remains intact. Stable totals at that checkpoint stayed **34 events / 14 categories / 20 recurrences**.
## Repeated coding-pattern catalog

### RP-01 — authority-domain conflation

```text
bad: one bare integer is reused as face/transition/chart/rail/etc.
good: semantic domains use strong IDs/certificates and explicit mappings.
```

Invariant: source face, transition, chart, rail, and stitch identity are never interchangeable.

Counterexample: permute one authority domain while preserving all others; the intended consumer rejects.

### RP-02 — test-authority coverage gap

```text
bad: helper-level green is used as product acceptance.
good: each authority has unit negatives plus representative product and final-oracle evidence.
```

Invariant: representative product verdict dominates focused/helper verdict.

Counterexample: helper passes while a direct product fixture carries the same authority and fails.

### RP-03 — policy/stage-state conflation

```text
bad: fallbackAllowed = stageAvailable;
good: requested policy and observed execution/completion state are separate fields.
```

Invariant: degraded output never reports certified production completion.

Counterexample: request fallback but inject production-stage failure; diagnostics must retain failure and degradation separately.

### RP-04 — cumulative work inside iterative stage

```text
bad:
for step in path:
    solve(all_faces_seen_so_far)

good:
precompute_static_system_once()
for step in path:
    update_incremental_state(step)
```

Invariant: append one equal-complexity step ⇒ measured work grows near-linearly.

Counterexample: doubled path length must not approach quadratic work.

### RP-05 — representation-dependent identity

```text
bad: semantic_id = iteration_index;
good: semantic_id = canonical_topology_key_or_checked_typed_identity;
```

Invariant: equivalent reorderings preserve semantic identity/certificate content.

Counterexample: reverse face/region ordering and compare semantic products, not raw traversal order.

### RP-06 — state/cardinality growth

```text
bad: state.push_back(transient) without retire/merge;
good: bound state by active topology and retire obsolete entries.
```

Invariant: tracked state cardinality is bounded by current active topology, not elapsed steps.

Counterexample: long synthetic trace with fixed active width keeps state bounded.

### RP-07 — cyclic topology linearized incorrectly

```text
bad: infer one terminal/cut from incidental order;
good: represent/verify the closed cycle directly.
```

Invariant: cyclic source topology has no arbitrary terminal unless the contract explicitly selects one.

Counterexample: cyclic permutation/reversal preserves cycle certificate/semantics.

### RP-08 — producer disposition conflation

```text
bad: unsupported/failed producer => empty success or unrelated fallback;
good: ProducerOutcome = Produced | Rejected(reason) | NotApplicable(reason).
```

Invariant: rejected authoritative input cannot be relabeled successful by a later generic path.

Counterexample: inject authoritative producer failure; final disposition remains rejection unless explicit degraded policy is selected.

### RP-09 — local consumption of global authority

```text
bad: component treats global field/region/rail identity as local arrays/indices;
good: explicit local<->global mapping preserves certificate meaning.
```

Invariant: component execution does not change global semantic ownership.

Counterexample: reorder/partition components and compare remapped global certificates.

## Test-authority defects

### TA-05 — indirect or stale helper authority

Current status: **resolved and preserved through accepted M1l**. Tests execute arbitrary extraction, reject injected field-count mismatch, reject invalid tetra topology, and validate direct products from immutable source artifacts. M1h additionally proved one new test-authority failure mode: occurrence coverage was incorrectly treated as producer-domain chart coverage. That assertion was corrected without changing producer behavior and the remediation is accepted.

Do not regress to source-tree symlink dependence, private-helper substitutes, cardinality-derived identity, exact raw numbering/hash assertions when semantic invariants suffice, or accepting regenerated/host source in place of packaged evidence.

## Current immutable migration authority

### M1h immutable accepted record

The initial M1h artifact `9066967620` compiled typed chart-owner source but exposed one test-authority defect. Corrected implementation `23efcc68289244056fe4a766588386bc487feb7f` is immutable accepted from artifact `9069186973`:

- focused: **6/6**;
- required-green: **187/187**;
- M1g/M1f/M1e/M1d/M1c/M1b focused preservation green; validation **77/77**; M1a **14/14**; T1 **29/29**;
- direct products green from arbitrary extraction with no fixture symlink; historical/deferred red classes unchanged;
- diagnosis: fixture samples lattice-corner chart IDs `{0,2}` while producer/segment authority still proves chart domain `{0,1,2}`; test incorrectly equates producer-domain and occurrence coverage;
- disposition: **test-authority defect, not stable product regression**; historical totals remain **34 / 14 / 20**; `PR8-R034 / G4-R007` remains active;
- historical next at this checkpoint was M1i; that consumed plan/report set has since been retired under `CLEAN_UP_POLICY.md`. Current next action is owned by the handoff and `TODO.md`.

### M1g immutable accepted pattern record

M1g implementation `ee1abbd91d8ab39b84b107bba73ebf7aa0acceb2` migrates the periodic canonical-face-cycle whole-route accumulator to checked source vertices, canonical topology keys, checked compact transitions, `TransitionStep`, `CanonicalRoute`, and typed transport composition. It preserves current `PeriodicHolonomyMismatch` rejection for nonzero cycle rotation. `G4-B003` remains unresolved.

Immutable authority:

- build run/job `31362470744 / 93373936472`, **120/120**;
- result artifact `9053047653`, ZIP SHA-256 `296f3ed13f2f09143a14f63555171d013939c2525052a56b807ea7f00cf1bd0c`;
- log artifact `9053048092`, ZIP SHA-256 `c5c3d964d9210982bfb08d0cf46900308a2498cee9ea2e54879dd35e61cacbd9`;
- manifest **64/64**, SHA-256 `89beb0a12c1051a0fd4d55af6a8ee27e897c0f610045efa8b270a42dc09d51ae`;
- M1g **6/6**, required-green producer **181/181**, complete M1f/M1e/M1d/M1c/M1b preservation, validation **77/77**, M1a **14/14**, T1 **29/29**;
- Plane/MultiFaceSeam/CloseSheets/Cylinder independent-oracle clean;
- all eight historical/deferred red classes unchanged;
- Bunny known-red and Vase bounded safety-only under run `31394985769`;
- strict-validator characterization **1/10 pass, 9/10 fail**, retaining the existing nondeterministic performance-test defect;
- exact local and remote postflight passed;
- stale per-turn M1h evidence was subsequently consolidated into `.agents/Directional/CHANGELOG.md` and the tracker; the old report was retired under `CLEAN_UP_POLICY.md`.

No new stable regression event or recurrence is assigned. Historical totals at that checkpoint remained **34 / 14 / 20**.

### Historical M1h RP-01 / RP-05 boundary

Accepted-source inspection selected `build_planar_phase_frame -> UniformPhaseFrame::faceChart -> LocalLatticeState::sourceChart` as the real field-chart owner. The producer created connected equal-orientation charts and carried their identity as bare integers. M1h adopted checked `FieldChartId` there while preserving chart partitioning/numbering and all behavior. The producer/segment authority still carried multiple chart IDs while some output occurrences did not sample every producer chart, which exposed TA-05 rather than a product defect.

## Historical M1h compile/package pattern record

M1h implementation `de4e2ba7c19d2e49931655dc22d758f50656d054` migrated the real field-chart owner `build_planar_phase_frame -> UniformPhaseFrame::faceChart -> LocalLatticeState::sourceChart` from bare semantic integers to checked `FieldChartId`, while numeric projection remained at then-existing leaf accesses. The deterministic chart partition/BFS numbering was unchanged. Missing typed lattice chart authority was fail-closed before aggregate front acceptance. Periodic and bounded-disk single-chart lattice states used checked chart zero. The final M1 cutover removes the stored numeric form.

Compile/package authority:

- run/job `31398571348 / 93487537918`, **120/120**;
- result artifact `9066967620`, ZIP SHA-256 `16d04835f9186b94fbb1ab987c5cd0bebd801daa7f368d01dc58139f67f5fe03`;
- log artifact `9066968049`, ZIP SHA-256 `d6fa10a4b188b5569dfc73008c1a6e8a6f3a4e51f64cf4232a568087b36ac816`;
- manifest **69/69**, SHA-256 `63c7000e00cf8608861d1651d84c02ddf419581dd7763ba25a9b3837162b92c9`;
- six focused M1h contracts compiled and unexecuted;
- all Code + Build runtime flags false;
- packaged sibling `../test-data` resolution correction compiled;
- subsequent test-authority remediation and immutable acceptance are retained in `.agents/Directional/CHANGELOG.md`; the superseded per-turn report was retired under `CLEAN_UP_POLICY.md`.

No new stable regression event or recurrence is assigned. `RP-01 / RP-05` and `RP-02 / TA-05` were subsequently accepted at M1h. `RP-07` remained preservation-only and unchanged.

## Single-authority strategy correction — 2026-08-11

- Review baseline: `fcba2fd9b8905802ca373e0cc88aeccbf38d608a`.
- Reviewed accepted source: M1l `bd140cff4572412e6f4ecd70a6ce0fe85310932c` from artifact `9083262395`.
- The unimplemented one-field follow-up was rejected after source inspection showed that the remaining duplication spans certificate, topology-region, chart, support, route, periodic, rail, occurrence, quotient, and materializer contracts.
- M1 now ends with one Code + Build turn that installs the semantic model across the complete producer-to-materializer path and deletes every displaced numeric semantic field, reconstruction path, helper bridge, and associated test.
- The cutover must preserve G0–G3 invariants, truthful failure and disposition behavior, determinism, and the accepted M1l product evidence. Representation changes are evaluated by semantic invariants and behavior-oriented contracts, not by exact preservation of obsolete numbering, hashes, or iteration order.
- No generated Directional binary runs in the cutover turn. A following immutable Test + Benchmark turn discovers the resulting inventory, runs all entering gates plus the new semantic contracts, and determines acceptance.
- After immutable acceptance, M1 closes and the primary queue returns to G4 production work. Remaining architecture work is introduced only as a complete vertical contract needed by an active production blocker, not as another representation-only campaign.
- This strategy correction changes no historical regression count: totals at that checkpoint remained **34 / 14 / 20**.

### Current R-A closure review after REV-18 through REV-21

- Exact implementation/test source `0580c5c8d7e4b12a41eefb0197f3660a0c7a8fca` was reviewed at branch boundary `922c36b43b8d35af2d2ffdeccb8e0c2ef551c760`; later commits are documentation-only.
- Compile run/job `31625763711 / 94211611771` and artifacts `9153147035 / 9153147459` are authentic partial evidence: Release/static/Ninja/PRE_TEST **118/118**, manifest **25/25**, clean snapshots, and no generated runtime.
- `R-A-REV-22 / RP-02`: final aggregate validation omits strict boundary/feature/chart authority and supplies an empty expected boundary set to an unconditional cycle comparison.
- `R-A-REV-23 / RP-01 / RP-05`: aggregate rebuilding creates a second stitch-key schema, trusts cached kind, and does not prove generated-interior lineages remain consumable.
- `R-A-REV-24 / RP-01 / RP-02`: direct source-authoritative validation can traverse with null typed authority when local-sheet checking is disabled while claiming authority was used.
- `R-A-REV-21 / RP-02`: exact binding code is present, but the required mismatched-authority row-permutation negative and consistent-pair positive are absent.
- These are static migration findings, not stable accepted-product regression events. Totals at that checkpoint remained **34 / 14 / 20** and M1l remains immutable runtime authority.

### Retained prior R-A compile checkpoints and closure-gate review

- Historical REV-01-through-16 findings, remediations, and artifact identities remain in `CHANGELOG.md`.
- Current review inspected exact implementation/test source `1352f3d18eb3821ecda9d74ea5e439adb5bcb875` at branch boundary `356a0bc2733af41e15fad056161e526865c147c5`. The six later commits are documentation-only.
- Bounded REV-17 owner-certificate/canonical-cache remediation and REV-20 compatibility-path removal are retained as compile-valid progress. Run/job `31616904715 / 94181880684` succeeded Release/static/Ninja/PRE_TEST **118/118**; artifacts `9149834162 / 9149834634` remain partial compile evidence with no generated runtime.
- `R-A-REV-18`: the aggregate still has no global owning source-authority product and does not rebuild post-remap vertex/face identity caches. This remains an `RP-01 / RP-05` blocker.
- `R-A-REV-19`: publication remains non-transactional and cached per-component validation substitutes for a final merged-product oracle. This remains an `RP-01 / RP-02 / INCOMPLETE_TRANSACTIONAL_ROLLBACK` blocker.
- `R-A-REV-21`: `complete_for_face_count` and affected consumers accept a foreign same-extent authority because they never compare supplied source-face topology to `topology_for_row`. This is an `RP-01 / RP-02` authority-binding and counterexample-coverage gap.
- These are static review findings, not stable runtime regression events. Overall R-A remains open; M1l remains immutable runtime authority and totals at that checkpoint remained **34 / 14 / 20**.

### Architecture redesign mapping

- Pipeline B is the normative default; Pipeline A is optional and unscheduled.
- New M3 owns the field-aligned curve network.
- Prior M3 becomes M4 global conformity; `G4-B002` is therefore M4-owned.
- Prior M4 becomes M5 certificate-carrying relations.
- Prior M5 becomes M6 occurrence/embedding/verification.
- New M7 owns graded disposition and the declared degraded producer.
- Prior M6 becomes M8 operational hardening.
- Strict product gates require D0 Certified; D1-D3 are explicit product dispositions and never green substitutes.

## Current WU2C stable-ID mapping

| PR event | WU2C ID | Category | Pattern | Status |
|---|---|---|---|---|
| `PR8-R035` | `WU2C-R001` | `AUTHORITY_DOMAIN_CONFLATION` | `RP-01` | **resolved** |
| `PR8-R036` | `WU2C-R002` | `TEST_AUTHORITY_COVERAGE_GAP` | `RP-02` | **resolved** |

## Current M2 stable-ID mapping

| PR event | M2 ID | Category | Pattern | Status |
|---|---|---|---|---|
| `PR8-R037` | `M2-CP4-R001` | `POLICY_STAGE_STATE_CONFLATION` | `RP-03` | **active** |

## Current M3 stable-ID mapping

| PR event | M3 ID | Category | Pattern | Status |
|---|---|---|---|---|
| `PR8-R038` | `M3-CP1-R001` | `AUTHORITY_DOMAIN_CONFLATION` | `RP-01` | resolved |
| `PR8-R039` | `M3-CP2-R001` | `CYCLIC_TOPOLOGY_LINEARIZATION` | `RP-07` | resolved |
| `PR8-R040` | `M3-CP2b-R001` | `REPRESENTATION_DEPENDENT_IDENTITY` | `RP-05` | resolved |
| `PR8-R041` | `M3-CP2b-R002` | `POLICY_STAGE_STATE_CONFLATION` | `RP-03` | resolved |
| `PR8-R042` | `M3-CP4b-R001` | `AUTHORITY_DOMAIN_CONFLATION` | `RP-01` | resolved |

## Current G4 stable-ID mapping

| PR event | G4 ID | Category | Pattern | Status |
|---|---|---|---|---|
| `PR8-R028` | `G4-R001` | `AUTHORITY_DOMAIN_CONFLATION` | `RP-01` | resolved |
| `PR8-R029` | `G4-R002` | `LOCAL_CONSUMPTION_OF_GLOBAL_AUTHORITY` | `RP-09` | resolved |
| `PR8-R030` | `G4-R003` | `TEST_AUTHORITY_COVERAGE_GAP` | `RP-02` | resolved |
| `PR8-R031` | `G4-R004` | `AUTHORITY_DOMAIN_CONFLATION` | `RP-01` | resolved |
| `PR8-R032` | `G4-R005` | `POLICY_STAGE_STATE_CONFLATION` | `RP-03` | resolved |
| `PR8-R033` | `G4-R006` | `AUTHORITY_DOMAIN_CONFLATION` | `RP-01` | test-authority resolved |
| `PR8-R034` | `G4-R007` | `LOCAL_CONSUMPTION_OF_GLOBAL_AUTHORITY` | `RP-09` | **active** |

`G4-R007` authority remains production artifact `9031804178`: direct torus 0/3 with 241 `LocalSheetMismatch` issues after 192 quads, complete lineage, `4/8/4`, `1/0/0`. M1/M2 migration does not repair or reinterpret it.

## Persistent blockers

| ID | Blocker | Required gate |
|---|---|---|
| `G4-B001` | Direct torus final `LocalSheetMismatch`. | strict-valid torus 3/3 |
| `G4-B002` | Exact Phase10 torus `InvalidHardRailPairing`. | shared positive rail schedule; revised M4 |
| `G4-B003` | Nonzero periodic Z4 production capability. | M5 relation certificate + representative product acceptance |
| `G4-B004` | Positive multi-isolation quotient witness. | M5/M6 focused + representative certificate evidence |

## Architecture enforcement register

| ID | State |
|---|---|
| `AR-01` | final M1 cutover installs exhaustive `ProducerOutcome<SurfacePhaseFrontProduct>` |
| `AR-02` | M1a through M1l **accepted**; complete R-A closure rejected; REV-18-through-REV-21 bounded compile progress retained; REV-22-through-REV-24 open |
| `AR-03` | final cutover closes strong identity from producer through materializer, including exact/existing stitch-identity validation and no compatibility bypass |
| `AR-04` | final cutover replaces remaining chart, support, route, periodic, rail, occurrence, quotient, and certificate numeric ownership |
| `AR-05` | after cutover, numeric projection is permitted only at a direct Eigen/vector storage or derived export leaf; it is never semantic authority |
| `AR-06` | final cutover installs the complete typed isolation-seam transport certificate; later relation-registry work must be driven by a production blocker |
| `AR-07` | revised M4 publishes one deterministic positive global conformity/flow plan before regional commits |
| `AR-08` | final cutover publishes one immutable producer-scoped phase-front product |
| `AR-09` | final cutover replaces `SurfacePointSourceSupport` with the typed resolved support contract end to end |
| `AR-10` | revised M3/M4/M5/M6/M7 contracts land vertically; module extraction/hardening closes in M8 |
| `AR-11` | normative architecture/status separation maintained |
| `AR-12` | T1 independent oracle/package accepted; T2–T6 expand authority |

## Test architecture register

| ID | State |
|---|---|
| `TA-01` | topology/lineage partial authority accepted; revised D0-D4 disposition and geometry/field/quality remain later gates |
| `TA-02` | T2 ten-case direct matrix pending |
| `TA-03` | metric definitions/baselines pending |
| `TA-04` | T3/T4 generation/shrinking/fuzz pending |
| `TA-05` | **test authority resolved and preserved through M1l** |
| `TA-06` | T1 mutation suite **29/29** accepted and preserved |
| `TA-07` | exact package/discovery authority accepted and preserved |
| `TA-08` | M1a-M1l entering authority accepted; REV-18-through-REV-21 compiled contracts retained only as bounded progress; strict final-oracle, canonical aggregate-identity, direct missing-authority, and permutation-pair contracts remain open |
| `TA-09` | coherent resource/work gate pending |
| `TA-10` | T2 semantic fixture manifest pending |
| `TA-11` | existing topology/lineage oracle foundation accepted; M3 network, M7 disposition, and T5 quality mutation evidence remain open |
| `TA-12` | `tests/TESTING_STRATEGY.md` normative only |

## Authoritative next step

Latest accepted runtime remains CP4ab **316/316**. Current CP4c-1 build authority is semantic source `2888dbdcf5aaf27fd629a5d29cbd57bc7d63e4f0`, immutable package `9553525746` (`44a2754c674b232b1327e4feef636d374d6fac0b5573212ec184eb7cf3ab35c8`).

Authoritative `M3-CP4c-1-TB-R2` run/job `32851859581 / 97814494564` is **VALID RED 316/318**: accepted prefix 316/316 PASS, C4/C5 0/2, three non-gating diagnostics, 321 fresh processes, zero orchestration errors, every mutation/build flag false. Result/control artifacts are `9564681836 / 9564682452`, SHA-256 `2febb8c314323009853a5cbdcaa8cd1000692f886654da2fba7039173a987df0 / d990338a12c40770fe33a0ef66a55456d74430dadca153643867ffc62e0f44a7`. Stable totals remain **42 / 14 / 28**, debt **5**, M3 packages **38**.

Exact next is independent `M3-CP4c-1-TB-R2-REVIEW-PLAN`, review/planning only. No runtime retry, semantic mutation, or CB is authorized before review.
