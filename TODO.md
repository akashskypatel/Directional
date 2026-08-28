# Directional Surface-Cell TODO

Last updated: 2026-08-28 UTC

## Purpose

This is the single durable **task index** — open and blocked work only. It is deliberately forward-looking.

Closed milestone/checkpoint history lives in `M1_Closure_Record.md`, `M2_Closure_Record.md`, `M3_CP2_Closure_Record.md`, `M3_CP2b_Closure_Record.md`, `M3_CP3_Closure_Record.md`, and `M3_CP4ab_Closure_Record.md`. Exact runtime evidence lives in `CHANGELOG.md`, the current retained turn report, and `Regression_Root_Cause_Tracker.md`. Normative architecture lives in `DESIGN.md`; the checkpoint map to production-ready lives in `ROADMAP.md`; migration ordering lives in `REORIENTATION_PLAN.md`.

**Do not re-accumulate per-checkpoint, per-retry, or per-partial narrative here.** A closed checkpoint gets one line in `ROADMAP.md` §1 and a closure record; it does not stay in this file.

## Turn workflow — changed 2026-08-25

```
CB  →  TB  →  green?  →  checkpoint CLOSES
                ↓ red
        REVIEW + PLAN  →  CB  →  …
```

**Non-gating diagnostic identities** TB executes and reports them, the
gate count excludes them, each carries a written rationale and an owning corrective measure.

## Current focus — `M3-CP4c-2` — cut-graph authority for A2b, under measures **X0–X9**

**`M3-CP4c-2-DEFN` is COMPLETE / DEFINITION-ONLY.** Record:
`Architecture_M3_CP4c2_DEFN_Frozen_Definitions.md`. CP4c-1's closure was independently re-verified first: all
four selector hashes recomputed identical, `src/`/`include/` frozen across CB4, and W1/W2/W5 confirmed in
source. **The closure claim is upheld.**

**The decision.** CP4c-2 introduces one new authority, **`SurfaceCutGraph` (stage A2a′)**, produced after A2a
and consumed by A2b, whose sole obligation is to guarantee the curve network's complement is a disjoint union
of open discs. **`DESIGN.md` §7.2 is amended (Amendment 12)**: its claim that region-disc topology "holds by
construction" is provably false on closed surfaces, and its stop condition, read literally, forbids the only
viable fix.

**The theorem, from already-measured data.** For a cellular embedding on the torus, `F = E − V + χ = E − V`.
The torus network has `V = 48`, `E = 48`, `χ = 0`, so `F = 0` — impossible, since the complement is non-empty.
At least one component is not a disc. More generally **no disjoint union of closed curves can ever be a cut
graph of the torus**, so this is not a defect of the committed fixture and cannot be fixed by choosing better
feature curves. `UncutFaceComponentOrbitSeedNotUnique` at `GlobalTopologyPlan.cpp:1741` is **correct
behaviour** reporting a missing input — there is no bug at that line.

**The boundary the implementation agent must not cross:** establishing a precondition before a product is
derived is not repairing that product afterward. If the cut decision can be made without ever looking at a
produced `GlobalTopologyPlan` region, it is a precondition; if it needs to see one, it is a repair and a stop.

**Scope.** CP4c-2 owns **C1** (torus regions) and **C6** (disc proof + mandatory preservation). **C3 is
deferred pending measure X2**, because the sphere's `RotationSystemInconsistent` is a *different* failure —
`χ=2`, 24 traces, 56 events, a different code, and unmeasured. Designing for it unmeasured would repeat the
CP4c-0/0b dependency inversion. **The gate is 357 or 358 and X2 decides which; it is not frozen here.**

**Vacuity trap, closed by X7:** C3 and C6 are quantified over "produced witnesses", and today no witness
produces a plan — so both would pass vacuously. C1 is the non-vacuity anchor; a green C6 over zero regions is
a red result.

**CB1 and `M3-CP4c-2-TB-X2-EXEC` are complete. Exact next is `M3-CP4c-2-TB-X2-REV`**; it reviews only the preserved X2 evidence and chooses between the already-frozen 357/358 branches. Accepted runtime authority remains CP4c-1 TB-R5 **355/355**. Stable accounting remains **42 / 14 / 28**, produced-witness debt **5**, M3 packages **58**.

## Superseded focus — `M3-CP4c-1` closure (retained for provenance)

**`M3-CP4c-1` is CLOSED / ACCEPTED.** Artifact-only TB-R5 run/job `33161644741 / 98817323175`
consumed immutable CB4 GMP package `9675666067` from semantic/test source
`b1ce8ad65952bd2bd76238f6dfc55523f6a24747` and returned **355/355 PASS**. Prefixes 316/346/353 are green;
C4/C5 ordinals 354/355 are green; all identities selected exactly once; zero C++ exceptions escaped; immutable
package/source postflight passed.

W3 is discharged: the two named terminal-kind membership checks executed and passed, and the observed union is
exactly `{TraceIntersection(2), MandatoryBarrierTermination(3), SingularityTermination(4)}` with contributors
prescribed sphere / two-ring / prescribed sphere. Torus contributes zero kinds; mechanical remains upstream at
`IncompleteCycleBasis`; the explicit two-ring report identity passed. The three frozen historical diagnostics
remain report-only with zero gate credit. Both W5-retired inverted diagnostics are absent, so
`M3-CP4c1-TB-R4-CAND-03` is **RESOLVED / TB CONFIRMED / TEST-SIDE / NON-STABLE**.

Accepted runtime authority is now CP4c-1 TB-R5 **355/355**. Result/log artifacts are
`9681960334 / 9681960615`, digests `b8be035ed728b5d6f8efe65e260f9557a9aa8cad0e82b94d11107aab44187a5d /
55ad320aaf810bb5b02fbfccdd7662f4a47333586bdb30397d624d701710439b`. Stable accounting remains
**42 / 14 / 28**, produced-witness debt **5**, M3 packages **57**.

At CP4c-1 closure the next turn was definition-only `M3-CP4c-2-DEFN`, **now complete**. CP4c-2 owns the closed/higher-genus A2b authority gap:
a closed index-free surface can have no singularity/feature/boundary seeds, so the current architecture has no
seam/cut graph from which region ownership can start. The DEFN turn must settle that contract before any product,
test, fixture, selector, compile, or runtime work. Rebased trajectory arithmetic is **358 = accepted 355 + C1 +
C3 + C6**; that count/order is not frozen until the definition authorizes a successor Code + Build.

- [x] `M3-CP4c-0-DEFN` — COMPLETE.
- [x] `M3-CP4c-0-CB1` — COMPLETE / BUILD GREEN.
- [x] `M3-CP4c-0-TB` — COMPLETE / VALID RED.
- [x] `M3-CP4c-0-TB-REVIEW-PLAN` — COMPLETE.
- [x] `M3-CP4c-0-CB2` — COMPLETE / BUILD GREEN. Package `9586196535`.
- [x] `M3-CP4c-0-TB-R2` — COMPLETE / VALID SEMANTIC RED.
- [x] `M3-CP4c-0-TB-R2-REVIEW-PLAN` — COMPLETE.
- [x] `M3-CP4c-0-CB3` — COMPLETE / BUILD GREEN. Package `9589508430`.
- [x] `M3-CP4c-0-TB-R3` — COMPLETE / VALID SEMANTIC RED. 336/338; F3 2/2.
- [x] `M3-CP4c-0-TB-R3-REVIEW-PLAN` — COMPLETE. Both reds test-side; Amendment 7; G0–G8.
- [x] `M3-CP4c-0-CB4` — COMPLETE / BUILD GREEN. Package `9591540182`; test-side corrections only.
- [x] `M3-CP4c-0-TB-R4` — COMPLETE / VALID SEMANTIC RED. 338/338; Q8 RED criterion 2.
- [x] `M3-CP4c-0-TB-R4-REVIEW-PLAN` — COMPLETE. H0–H7 frozen.
- [x] `M3-CP4c-0-CB5` — COMPLETE / BUILD GREEN. Package `9601160869`.
- [x] `M3-CP4c-0-TB-R5` — COMPLETE / VALID SEMANTIC RED. 338/338; H1 delivered.
- [x] `M3-CP4c-0-TB-R5-REVIEW-PLAN` — COMPLETE. Amendment 8; J0–J7 frozen.
- [x] `M3-CP4c-0-CB6` — COMPLETE / BUILD GREEN. Package `9619352525`.
- [x] `M3-CP4c-0-TB-R6` — **COMPLETE / VALID SEMANTIC RED.** 338/338; F3 2/2; J3 legitimate 524/524 geometry agreement; Q8 RED criterion 2.
- [x] `M3-CP4c-0-TB-R6-REVIEW-PLAN` — **COMPLETE.** Root cause **identified**: the disagreements are a
  **near-tangency discretization phenomenon**, and **Amendment 4 / measure E5's invariant is too strong**
  for a piecewise-constant field. Reproduced the sphere census from the committed fixture alone —
  **exactly 144 directed**, matching runtime — and measured the tangency ratio: disagreeing median
  **0.0218** vs agreeing **0.9233**, every disagreement ≤ **0.2004**. At the live locus **every published
  term is independently verified correct** (matching 0 right with a 42° margin; `0 + 1 − 3 ≡ 2`
  reproduces the lift; both `dbary` triples match to 10 dp; mesh adjacency sound). **One class, not
  two.** Amendment 9 issued. Record:
  `M3_CP4c_Consolidated_Record.md` §3b (retired TB-R6 review).
- [x] `M3-CP4c-0-CB7` — **COMPLETE / BUILD GREEN.** Semantic source `077462da156c3e2dfbbc6867fc10d3e4442d853c`; package `9625495708`. K0–K7 diagnostic/contract-control only; no production semantics; all eight standard targets compiled/linked; `runtimeExecution=false`.
- [x] `M3-CP4c-0-TB-R7` — **COMPLETE / VALID SEMANTIC RED.** 338/338; F3 2/2; K1 near-tangency reproduced; K2 0/24 reaches grazing (non-decisive); J3 524/524 legitimate; K3 176/176 / 0 mismatches; Q8 RED criterion 2.
- [x] `M3-CP4c-0-DEFN-2` — **COMPLETE.** Closed the `DESIGN.md` §4.5 gap. Chose **grazing edge
  transit** over grazing terminus, refinement precondition, and a general edge-following mode, on a
  continuity proof against Amendment 3 rather than on K2 cost data — K2 measured the retired Cartesian
  rule and is void. Q8 **not amended**; criterion 3 re-homed to CP4c-1 with reasons.
  `Architecture_M3_CP4c0_DEFN_2_Frozen_Definitions.md`; Amendment 10; `DESIGN.md` §4.5.
- [x] `M3-CP4c-0-CB8` — **COMPLETE / BUILD GREEN.** Semantic source `19ba8e9c5e58f9c33c14b309841165d3f0401db5`; package `9628445643`. L0–L9 only; 343 required-green identities; all eight standard targets compiled/linked; `runtimeExecution=false`.
- [x] `M3-CP4c-0-TB-R8` — **INCOMPLETE / BLOCKED.** 342/343 completed; ordinal 338 RED after 853.437 s with `gcd(): while running too long!`; ordinal 343 incomplete at user cancellation; no acceptance credit.
- [x] `M3-CP4c-0-TB-R8-REVIEW-PLAN` + `M3-CP4c-0-CB9` — **COMPLETE.** Combined at user instruction.
  Root cause: non-terminating traces + two inert guards + an exact backend that throws out of a closed
  producer. Measures **N0–N7** implemented and compiled per translation unit; nothing executed.
  Deterministic product-level guard has landed, so the binding stop rule is discharged.
- [x] `M3-CP4c-0b-DEFN` — **COMPLETE.** Split the checkpoint; froze the trace-termination contract,
  the contact predicate, the `ArcLengthFiltered` arrival priority with mutual termination on
  inconclusive or tied arrivals, and the constrained alternatives harness. Amendment 11 moves Q8
  criteria 2 and 3 to CP4c-0b; `DESIGN.md` §4.6's termination guarantee is amended to name its
  condition. Record: `Architecture_M3_CP4c0b_DEFN_Trace_Termination_Frozen_Definitions.md`.
- [x] `M3-CP4c-0-TB-R9` — initial execution COMPLETE / VALID SEMANTIC RED **344/346** on GMP package `9634245265`; historical evidence retained. Final whole-gate re-proof is recorded below.
- [ ] `M3-CP4c-0-TB-R9-REVIEW-PLAN` — **SKIPPED BY EXPLICIT USER INSTRUCTION; NOT COMPLETED.** Its bypass does not grant acceptance or adjudicate `CAND-02`.
- [x] `M3-CP4c-0-CB-R10` — **COMPLETE / BUILD GREEN.** Test-only GMP-portability correction at semantic source `30ef2792e2915e0016dfd11f5fa2b3727e5503c0`; compile run/job `33067140968 / 98499967674`; immutable GMP package `9644214591`, SHA-256 `b9e7729fb557eddc203e38a1c11564bab3ad180982e10740d4374fe06748a390`; all eight standard targets compile/link; `runtimeExecution=false`.
- [x] `M3-CP4c-0-TB-R10` — **COMPLETE / FOCUSED PASS.** Artifact-only run/job `33067370314 / 98500728780`; `ExactVertexSectorUsesPublishedDirectionAcrossLossyRoundTrip` selected exactly once and PASS in 5 ms; immutable postflight PASS. This resolves `M3-CP4c0-TB-R9-CAND-01` only.
- [x] `M3-CP4c-0-CB-R11` — **COMPLETE / BUILD GREEN.** Test-only CAND-02 fixture correction at semantic source `267272d22f7de67ce7d8e368a53cc78a37ca3e8f`; compile run/job `33077493539 / 98535503386`; immutable GMP package `9648550565`, SHA-256 `1f0275e96fa75b7fc6fb447eaffb79b414c94230823da7897a4f2d91df33615c`; all eight standard targets compile/link; `runtimeExecution=false`.
- [x] `M3-CP4c-0-TB-R11` — **COMPLETE / FOCUSED PASS.** Artifact-only run/job `33077761701 / 98536455697`; `ExactContinuationMagnitudePolicyFailsClosedWithoutTolerance` selected exactly once and PASS in 39 ms; immutable postflight PASS. This resolves `M3-CP4c0-TB-R9-CAND-02`.
- [x] `M3-CP4c0-TB-R9-CAND-02` — **RESOLVED / NON-STABLE / TEST-SIDE FIXTURE-PRECONDITION.** The old positive control was exactly degenerate; the corrected witness proves a positive exact `1/4` edge exit while preserving the oversized-magnitude fail-closed case.
- [x] `M3-CP4c-0-TB-R9-REPROOF` — **COMPLETE / GATE GREEN 346/346 / CP4c-0 CLOSED / ACCEPTED.** Fresh compile run/job `33079499974 / 98542697746`, package `9649395432`; artifact-only TB run/job `33079817998 / 98543736213`; Q8 1/4/5 PASS; immutable pre/postflight PASS.
- [x] `M3-CP4c-0b-P0.3-REVIEW-PLAN` — **COMPLETE / INDEPENDENT REVIEW.** P0.3 withdrawn as false; accepted crash-on-contact defects identified; S0–S8 supersede P0–P9.
- [x] `M3-CP4c-0b-CB1-S1` — **COMPLETE / BUILD GREEN / NON-GATING CENSUS ONLY.** Semantic source `4bb467806df99c70889394a323c17c13bc185ca3`; GMP precompile + eight-target package run `33093440552`; package artifact `9655632444`, SHA-256 `c22e9b020e533ca8fc558bcafc3e138a062702a59bee68a097958b432d70bc5f`; `runtimeExecution=false`. S2–S6 not entered.
- [x] `M3-CP4c-0b-TB-S1-EXEC` — **COMPLETE / EXECUTION GREEN.** Run/job `33097182476 / 98605092984`; unchanged gate **346/346 PASS**; non-gating S1 identity PASS with zero gate credit; no reached included witness required independent review; immutable postflight PASS.
- [x] `M3-CP4c-0b-TB-S1-REV` — **COMPLETE / REVIEW GREEN.** Raw artifact `9656967036` independently re-read; site-B contact set is empty on reached included witnesses, sphere remains correctly unreached at N1, and no S1 stop condition fired. Review authorizes frozen S2-S6 and records the site-A predecessor migration.
- [x] `M3-CP4c-0b-CB1-S2-S6` — **COMPLETE / BUILD GREEN / RUNTIME-FREE.** Semantic source `737f93be10a73db950e2a7f823b96ffb0d59cf4d`; GMP changed-owner precompile `33116158072 / 98671267836`; authoritative eight-target package `9664890562` from `33116774891 / 98673348923`; selectors frozen at predecessor 346 + new 7 = full 353; no Directional runtime.
- [x] `M3-CP4c-0b-DG` — **COMPLETE / VALID SEMANTIC RED 6/7.** Corrected run/job `33120730355 / 98686699036`; immutable package `9664890562`; all seven selected once; sole red was the torus zero-node assertion; postflight PASS; full 353 gate not run. Earlier `33120437486 / 98685729035` was resolved orchestration-only and executed zero Directional identities.
- [x] `M3-CP4c-0b-DG-REV` — **COMPLETE / INDEPENDENT REVIEW.** `CAND-02` adjudicated test-side over-specification conditional on T1; T0-T7 frozen.
- [x] `M3-CP4c-0b-CB2` — **COMPLETE / BUILD GREEN / RUNTIME-FREE.** T1 selected review row 1; T2/T3 corrected only the never-accepted torus contract and census authority labeling. Semantic source `b2629040450c12507367c232f68a4d972b46450f`; GMP compile run `33126178643`; package `9668492827` / `e0661e66...dce0b8`; 28/28 manifest PASS; no Directional runtime.
- [x] `M3-CP4c-0b-DG-T4-EXEC` — **COMPLETE / EXECUTION GREEN 7/7.** Run/job `33128261911 / 98711506300`; result/log `9669229181 / 9669229414`; all seven selected exactly once and PASS; zero exceptions/timeouts/build/repair/discovery/mutation; immutable byte-and-mode postflight PASS.
- [x] `M3-CP4c-0b-DG-T4-REV` — **COMPLETE / INDEPENDENT REVIEW.** T4 verified and T5 authorized; both selector hashes and the 346-line ordered accepted prefix independently re-verified; `DG-CAND-02` RESOLVED via T1; ordinals 7/9/12/13 risk map issued; measures U0-U7 frozen. No runtime executed. Record: `Architecture_M3_CP4c0b_DG_T4_Independent_Review_Record.md`.
- [x] `M3-CP4c-0b-TB-T5` (first attempt) — **PRE-GATE BLOCKED / 353 NOT RUN / STOPPED CORRECTLY.** U0 static authority passed, but immutable package `9668492827` cannot publish U3/U4's required pre-gate census while U7 forbids adding instrumentation or compiling inside the turn. Gate execution 0/353; no runtime, mutation, or weakening of U3/U4. Record: `Architecture_M3_CP4c0b_TB_T5_Preflight_Blocker_Report.md`.
- [x] `M3-CP4c-0b-TB-T5-PREFLIGHT-REV` — **COMPLETE / REVIEW GREEN.** Upheld the blocker and authorized a bounded instrumentation CB under **V0-V7**. Two additive findings: both 353 identities that build the fan discard the result (`(void)build`, lines 6348 and 7044), and **six of the seven non-gating census identities are compiled but selected by nothing** — so part of the gap is selector-side and costs no code. Risk ranking inverted to ordinal 12 first; `T5-CAND-01` adjudicated. Record: `Architecture_M3_CP4c0b_TB_T5_Preflight_Independent_Review_Record.md`.
- [x] `M3-CP4c-0b-CB3-INSTR` — **COMPLETE / BUILD GREEN / RUNTIME-FREE.** Source `93059089881c8715a168a61968a8d6874ee1a670`; compile `33133572290`; immutable GMP package `9671190795` / `2901926c…5c1`; required selector unchanged 353 / `51ff96d7…ac6a5`; non-gating selector 4 / `d4224002…d9ad`; no `src/`/`include/` or accepted-identity change.
- [x] `M3-CP4c-0b-TB-T5` (retry) — **COMPLETE / GATE GREEN 353/353 / CP4c-0b CLOSED / ACCEPTED.** Authoritative run/job `33136084757 / 98736295227`; accepted prefixes 316/316 and 346/346; four non-gating U3/U4 identities PASS with zero credit; immutable postflight PASS. Report: `Architecture_M3_CP4c0b_TB_T5_Artifact_Only_Test_Benchmark_Report.md`.
- [x] `M3-CP4c-1-CB3` — **COMPLETE / BUILD GREEN / RUNTIME-FREE.** Cumulative required selector 355 / `e9d88f11…fb5afeaa`; accepted 353 is the exact ordered prefix; C4/C5 ordinals 354/355; source `66a065b5e07910568a317e24f0fc6b93d890d104`; compile `33139188595 / 98746005796`; GMP package `9673249952`; no Directional runtime.
- [x] `M3-CP4c-1-TB-R4` — **COMPLETE / VALID SEMANTIC RED 354/355.** Run/job `33141046678 / 98751794167`; accepted 353/353 prefix green; C4 PASS; C5 RED; five diagnostics report-only; immutable postflight PASS.
- [x] `M3-CP4c-1-TB-R4-REVIEW-PLAN` — **COMPLETE / REVIEW GREEN.** C5's red is test-side in both clauses; the product meets the frozen contract on every witness that produced a trace. Plan line 131 adjudicated normative over line 101; `M3-CP4c1-TB-R4-CAND-01` **RESOLVED / TEST-SIDE OVER-SPECIFICATION / NON-STABLE**. Clause 1 identified as a recurrence of `M3-CP4c0b-DG-CAND-02`. Measures **W0–W7** issued. Historical review facts are consolidated in `M3_CP4c_Consolidated_Record.md` §4/§5.
- [x] `M3-CP4c-1-CB4` — **COMPLETE / BUILD GREEN / RUNTIME-FREE / TEST-SIDE ONLY.** Semantic/test source `b1ce8ad65952bd2bd76238f6dfc55523f6a24747`; W1/W2 corrected C5 in place; W4 not used; both mandatory W5 inverted diagnostics retired with surviving-cover rationale; W5b publishers unchanged. Required selector remains 355 / `e9d88f11…5afeaa`; non-gating selector is 3 / `537a8010…ffcd6a`; `src/`/`include/` unchanged. Compile run/job `33145657048 / 98766007030` PASS; immutable GMP package `9675666067` / `63b66788…45ec17`; manifest 28/28; `runtimeExecution=false`; no Directional runtime.
- [x] `M3-CP4c-1-TB-R5` — **COMPLETE / GATE GREEN 355/355 / CP4c-1 CLOSED / ACCEPTED.** Run/job `33161644741 / 98817323175`; prefixes 316/346/353 PASS; C4/C5 PASS; W3 exact union/contributor prediction met; three historical diagnostics report-only; explicit two-ring report PASS; W5-retired identities absent; immutable postflight PASS. Report: `Architecture_M3_CP4c1_TB_R5_Artifact_Only_Test_Benchmark_Report.md`; closure: `M3_CP4c1_Closure_Record.md`.
- [x] `M3-CP4c-2-DEFN` — **COMPLETE / DEFINITION-ONLY.** Froze the `SurfaceCutGraph` (A2a′) contract and **Amendment 12** to `DESIGN.md` §7.2/§4.6. Proved from measured data that the torus network (`V=48, E=48, χ=0`) cannot bound discs, and that no disjoint union of closed curves can ever cut a torus — so `UncutFaceComponentOrbitSeedNotUnique` is correct behaviour reporting a missing input. Scoped CP4c-2 to **C1 + C6**; **C3 deferred pending measure X2**. Gate is **357 or 358**, not frozen. Measures **X0–X9**. Record: `Architecture_M3_CP4c2_DEFN_Frozen_Definitions.md`.
- [x] `M3-CP4c-2-CB1` — **COMPLETE / BUILD GREEN / RUNTIME-FREE.** Final semantic/test source `93d9d49f052fa481bd3a8ad8c9bf31eccda7705c`; compile run `33196876096`; changed-owner job `98936191472` PASS; full eight-target GMP package job `98936799976` PASS; immutable package `9696201700` / `af3ebe2e…7c8097`; source archive `8694f0fb…321687`; `runtimeExecution=false`. Both X2-conditioned gates are frozen: 357 / `b896d0db…64dc70`, 358 / `6eda3aad…4fbe62`; non-gating X2 selector 1 / `88af227b…dafc8`. Report: `Architecture_M3_CP4c2_CB1_Code_Build_Report.md`.
- [ ] `M3-CP4c-2-TB` — **IN PROGRESS / ARTIFACT-ONLY / SPLIT EXEC+REV.** `TB-X2-EXEC` is COMPLETE on run/job `33199227974 / 98944212158`, result/log `9697052371 / 9697052810`; exactly one frozen X2 identity ran, immutable pre/postflight passed, and the raw `m3Cp4c2X2` publication is preserved in `Architecture_M3_CP4c2_TB_X2_EXEC_Artifact_Only_Evidence.md`. **Exact next is `M3-CP4c-2-TB-X2-REV`**; it alone selects frozen gate 357 or 358. Only afterward may `TB-GATE-EXEC` run the chosen full gate and `TB-GATE-REV` adjudicate acceptance. CP4c-2 closes only with §8 predictions 1–4 met and X7 reporting a non-zero torus region count — **a green C6 over zero regions is a red result.**
- [ ] `M3-CP4c-3-DEFN` — BLOCKED on CP4c-2 closure.

Accepted runtime authority is `M3-CP4c-1-TB-R5`: **355/355**, run/job `33161644741 / 98817323175`, consuming immutable GMP package `9675666067` from source `b1ce8ad65952bd2bd76238f6dfc55523f6a24747`. Required selector remains `e9d88f1196e412e06424294d6be22b32f01c9671ec5e4de119abd3f2fb5afeaa`, with accepted 353/346/316 prefixes unchanged. Stable accounting remains **42 / 14 / 28**, produced-witness debt **5**, M3 packages **58**. `M3-CP4c-0`, `M3-CP4c-0b`, and `M3-CP4c-1` are **CLOSED / ACCEPTED**. `M3-CP4c-2-CB1` is build-green and X2 report-only execution is preserved, but CP4c-2 remains runtime-unaccepted. **Exact next is `M3-CP4c-2-TB-X2-REV` over run/job `33199227974 / 98944212158`; no cumulative gate runtime is authorized yet.**

**TB-R6 disposition after review — corrected.** Three standing readings are **withdrawn**:

1. **The live locus does not indict `build_branch_transports`.** Its lift composes correctly
   (`0 + 1 − 3 ≡ 2`), its matching is geometrically right (nearest target raw index at 23.7°, next at
   66.3°), both gauges are right, and both published `dbary` triples reproduce from the fixture to 10
   decimal places. The decision-table row it satisfied is withdrawn as a diagnosis.
2. **There are not two classes.** The unequal-gauge (86/43) and equal-gauge/lift-0 (254/127) populations
   are the same **near-tangency** phenomenon seen through different bookkeeping.
3. **J3's 524/524 does not exclude H-B.** `independent_edge_measurement` re-implements **principal
   matching** — the algorithm H-B suspects — so it is an implementation cross-check, not an aliasing
   test. (H-B *is* excluded, but by direct measurement at the live locus, not by J3.)

**Root cause:** Amendment 4 / measure E5 asserts a **continuum** property that a piecewise-constant field
does not satisfy near edge tangency. The real gap is that **`DESIGN.md` §4.5 does not define what a trace
does at a grazing edge** — a `-DEFN` question, not a patch. **No production change is authorized; there
is nothing in A1 to fix.** Q8 stays red until the model question is settled.

## CP4c documentation — consolidated 2026-08-26

Twenty-four per-turn CP4c execution documents and superseded review briefs were retired into
**`M3_CP4c_Consolidated_Record.md`** under explicit user authorization, preserving every evidence
identifier. Thirty-three CP4c documents became twelve. Retained live: the CP4c-0 DEFN charter and frozen
definitions, the five independent reviews (they carry Amendments 1–7 and measure series E/F/G/H), and
all selector `.txt` authority files. A citation naming a retired document now points at the consolidated
record — **retired provenance, not lost authority**. CP4c-0 and CP4c-1 remain **OPEN**; the record is
historical and closes nothing.
## After M3 exit

`ROADMAP.md` §4 proposes the checkpoint decomposition for **M4–M8** — seventeen checkpoints plus five `-DEFN` planning turns to reach `M8-CP3`, the production-ready exit. That decomposition is a **proposal until each milestone's `-DEFN` turn freezes it**; gate arithmetic beyond 322 is deliberately not fixed.

## Carried forward from M2

- [ ] **3 latent fixture-authority sites** — `PatchDescriptorMilestoneETests.cpp:1220`, `:1260`, `:1811`. Defaulted completion options assert success but pass only because their complexes never reach boundary-ownership resolution; none are in the frozen selector.
- [ ] **Remove the `= {}` default** on the authority-consuming `complete_surface_cell_complex` overload (`PatchDescriptor.h:427`) so omission stops compiling.
- [ ] **Establish authority-carrying completion options as the local idiom.** `SurfaceCellComplexCompletionOptions` remains authority-unset by default across the affected tests.

## Carried forward from M1

**Produced-witness debt — `G4-B002` → revised M4 (3).** A fourth reopens section 14 scheduling.
- [ ] Re-prove `CandidateExtractionBaselineForCanonicalSourceScopeIdentityIsNonVacuous` on a produced closed complex.
- [ ] Re-prove `PeriodicRelationOwnersSurviveContainerReorderingBeforeMaterialization` through the torus pipeline.
- [ ] Re-prove `MissingPeriodicRelationOwnerIsRejected` on produced periodic authority.

**Produced-witness debt — `G4-B003` → M5 (2).** A third reopens M5 scheduling.
- [ ] Re-prove `FullPeriodicRotationAndTranslationMaterialize` on produced nonzero-Z4 authority.
- [ ] Re-prove `TamperedFullPeriodicTransformIsRejected` on produced nonzero-Z4 authority.

**Criterion-5 disposition re-proof → M7.**
- [ ] Re-express M1 criterion 5 in disposition terms and re-run F1/F2/F3 under verifier-assigned `Certified`. M7 does not close until green.

## Deferred hygiene

- [ ] **Repair `.github/workflows/agent-turn-cleanup.yml` comment handling and trigger safety.** The workflow still deletes **all** PR conversation and inline review comments before its observer step, and creating `.agents/connector-triggers/turn-cleanup/manifest.txt` auto-triggers it. Run `32591251950 / 97075340976` demonstrated 27 conversation-comment deletions. User commit `c359ea925b04471500575a9dcc17bdc6e4bb52d1` explicitly superseded the old prohibition by requiring the manifest/workflow at every turn closeout. Until the workflow is repaired, preserve durable repository evidence before publishing the closeout manifest and treat PR comments as non-durable.

Inherited baseline-red / non-gating fixtures remain frozen in the M1 exclusion register. None may become required-green evidence before its precondition is independently established.

- [ ] `WU2A-TB-CAND-01`: successful-side-subdivision ownership-registry precondition.
- [ ] `WU2B-TB-CAND-01`: hard-rail region-copy valid front-boundary-authority precondition.
- [ ] `WU2B-TB-CAND-02`: side-repair rollback ownership-registry/domain-identity precondition.
- [ ] `WU2B-TB-CAND-03`: authoritative-cell-scope subdivision source-scope reconciliation.
- [ ] `WU2B-TB-CAND-04`: five simplification fixtures need independently proven removable/protected/healing preconditions.
- [ ] `WU2B-TB-CAND-05`: FlowRep mandatory-cycle witness needs `selectionSucceeded=true` before later-cycle evidence is creditable.
- [ ] `RA-REV-23-F3`: dispatch stitch-kind audit through an explicit classifier field rather than probe-name text; add a negative self-test.
- [ ] `RA-REV-22-F6`: remove non-falsifiable validation-used assertions or set them where each gate actually executes.
- [ ] `RA-TB6-H1`: repair repeated `TriMesh::set_mesh` / `DCEL::init` stale halfedge-twin reinitialization outside the R-A fixture path.

## Milestone status

Checkpoint decomposition, per-milestone acceptance mapping, and the path to production-ready are in **`ROADMAP.md`**. Summary only:

- [x] **M0** preserve evidence  ·  [x] **M1** single-authority cutover  ·  [x] **M2** closed stage products
- [ ] **M3 — field-aligned curve network.** CP4ab, CP4c-0, CP4c-0b, and CP4c-1 are accepted; current accepted authority is **355/355**. CP4c-2 CB1 and X2 EXEC are complete; exact next is `M3-CP4c-2-TB-X2-REV`; CP4c-3 remains blocked.
- [ ] **M4** global conformity plan — also discharges the 3 `G4-B002` produced-witness debts.
- [ ] **M5** certificate-carrying chart/quotient relations — also discharges the 2 `G4-B003` debts.
- [ ] **M6** occurrence, embedding, independent verification.
- [ ] **M7** disposition and graded degradation — D0–D4 plus the M1 criterion-5 forward re-proof.
- [ ] **M8** module boundaries and operational hardening — `M8-CP3` is the production-ready exit.
- [ ] **Pipeline A.** Unscheduled until Pipeline B is Certified and evidence shows integration would materially improve quality.

## Active product blockers

- [ ] `G4-B001 / PR8-R034 / G4-R007`: direct torus final `LocalSheetMismatch`; downstream of A2b and not a CP4c witness collision.
- [ ] `G4-B002`: exact torus `InvalidHardRailPairing`; revised M4.
- [ ] `G4-B003`: nonzero periodic Z4 production; M5.
- [ ] `G4-B004`: positive multi-isolation quotient witness; M5/M6.
- [ ] Bunny/Vase representative production and resource acceptance — later product gates.

## Design and calibration backlog

- [ ] Own the closed-rail cardinality contract once at the rail product boundary rather than re-guarding both closed representations at every consumer.
- [ ] Calibrate `T5` quality/resource thresholds from measured baselines before any milestone asserts a quality gate.
- [ ] Correct `DESIGN.md` section 6.7 invariant 2 so D1 `QualityRelaxed` consistently records missed quality gates.
- [ ] Define the M7 degraded producer algorithm and its fixed-boundary completion proof.
- [ ] **Audit every remaining `kBranchTopologyTolerance` comparison for dimensional coherence.**
  `direction_in_incident_vertex_sector` compares a Gram **determinant** — an area-squared quantity — to
  `1e-10`. After E2/E3 the surviving uses are admissibility guards only, but their scale is arbitrary and
  mesh-size dependent. Not a CP4c-0 measure; do not fold it into CB2.
- [ ] **Sweep for other tolerant-selector / exact-consumer seams.** CP4c-0 found the pattern three times
  in one subsystem (flow classification, vertex sector, cross-edge flow). The same audit is owed wherever
  an exact authority was introduced downstream of a `double` decision.

---

Historical stable totals are **42 events / 14 categories / 28 recurrences**. Produced-witness debt remains **5**. M3 package count is **53**. PR #8 remains open, draft, and unmerged.
