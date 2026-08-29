# Directional Surface-Cell TODO

Last updated: 2026-08-29 UTC

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

## Current focus — `M3-CP4c-2-TB-X2-R4-REV` — independent evidence review only

**`M3-CP4c-2-TB-X2-R4-EXEC` is COMPLETE / VALID DIAGNOSTIC SEMANTIC RED / D1 EVIDENCE-CONFLICT STOP.**
Authoritative artifact-only run/job `33228460953 / 99036688477` consumed immutable GMP package `9707091209`
from semantic/test source `5ad711e5d4ced95f38e103b993139a6307ba2cee`. Immutable package/source/GMP/selector
preflight and postflight passed; no configure, compile, relink, generated discovery, package/source/test/fixture
mutation, selector gate, or benchmark occurred.

D1 executed exactly once and exited `1`. Torus successfully consumed pipeline products and published the frozen
product-authoritative `barrierV=48`, `barrierE=48`, `sourceChi=0`, `networkOnlyCellular=false`,
`oracleSelfConsistent=true`, with atlas/network/cut-graph/plan snapshots all available. Prescribed sphere emitted
a typed construction failure with every pipeline snapshot unavailable and
`error=pipeline-source-topology-snapshot-unavailable`; two-ring published a successful/self-consistent
`AtlasDerived` record. The final accumulated assertion then repeated the prescribed-sphere Y1 record
byte-identically, so preserved stdout contains four `m3Cp4c2Y1` lines rather than exactly one per witness. The
frozen publication contract therefore stops as `STOP_EVIDENCE_CONFLICT`; D2 was correctly skipped.

Raw evidence: `Architecture_M3_CP4c2_TB_X2_R4_EXEC_Artifact_Only_Evidence.md`. Result/log artifacts
`9707662462 / 9707662682`, digests
`36e5982c152317a56d98d13e58a2ec1233c71b65e9f8570aeabfed373228a76f /
594edbad06c849e12ad52787ec144f08da526c6f25c4449d21a222691daae0eb`.
Recursive package/source byte-and-mode inventories match exactly.

`selected_r2_branch=NONE`; `selected_gate=NONE`; `gate_execution_authorized=false`. Stable accounting remains
**42 / 14 / 28**, produced-witness debt **5**, M3 packages **61**.

Exact next is **`M3-CP4c-2-TB-X2-R4-REV`**. It is evidence review only: adjudicate Z13 witness isolation,
the exactly-once publication conflict, torus 48/48, prescribed-sphere snapshot availability, and existing/new
candidate dispositions. Do **not** rerun D1, run D2/355/357/358, execute a cumulative gate, benchmark, compile,
mutate source/tests/fixtures, start CB3, touch mechanical/C2, or begin CP4c-3 in REV.

## Superseded focus — `M3-CP4c-2-TB-X2-R3-EXEC` stop (retained for provenance)

**`M3-CP4c-2-TB-X2-R3-EXEC` is COMPLETE / VALID DIAGNOSTIC SEMANTIC RED / PLANNED STOP.** Artifact-only run/job
`33222551366 / 99019499929` consumed immutable package `9704935112` from source
`c552a5a4a318063cde2564c40773ec7edaf064f6`. Immutable/GMP/source/selector preflight passed; D1 selected exactly
once and exited `1` before any `m3Cp4c2Y1` publication because torus fixture construction reported
`field-transport-atlas-unavailable` at `tests/FieldAlignedCurveNetworkTests.cpp:5946`. D2 was correctly skipped.
Recursive package/source byte-and-mode postflight matched exactly.

Raw evidence: `Architecture_M3_CP4c2_TB_X2_R3_EXEC_Artifact_Only_Evidence.md`; result/log artifacts
`9705692837 / 9705693025`, digests `ba989d0ddd3bd244f03c8242060ded9f9c58b33679893ab0ddf1cc5fb8d015f5 /
ab653c13ec7b0eec30f2736a17bbf44406afa7c828cb1fddbadea795aa6701a6`.

**That review is complete.** It localized `M3-CP4c2-TB-X2-R3-CAND-01` as test-side and opened
`M3-CP4c2-TB-X2-R3-CAND-02` for the gating defect. **Exact next is `M3-CP4c-2-CB2-DIAG-R2`** under Z10–Z19. Because no D1 publication
exists, R2 CAND-01/CAND-02 remain active and CAND-04 remains active/unlocalized; no Y5 branch or cumulative gate
may be inferred in EXEC. Stable accounting remains **42 / 14 / 28**, produced-witness debt **5**, M3 packages
**60**.

`selected_r2_branch=NONE`; `selected_gate=NONE`; `gate_execution_authorized=false`. Do not rerun unchanged D1,
do not execute D2/355/357/358, cumulative gate, CB3, mechanical/C2, or CP4c-3 before REV completes.

## Superseded focus — `M3-CP4c-2-TB-X2-R2` control stop (retained for provenance)

**`M3-CP4c-2-TB-X2-R2` is COMPLETE / PLANNED CONTROL STOP / NO Y5 BRANCH.** Artifact-only run/job
`33215632118 / 98998526420` consumed immutable CB2-DIAG package `9702321260` from source
`232ac459b13657529e064272a75c5583770a5963`. Package/source/GMP/selector preflight passed; D1 executed exactly
once and published all three required `m3Cp4c2Y1` records. No build, relink, fixture mutation, generated discovery,
or benchmark occurred.

Y4 failed exactly at its fixed control: D1's torus reported `networkV=0`, `networkE=0`, `sourceChi=0`,
`networkOnlyCellular=false`, not the required product theorem `V=48`, `E=48`, `chi=0`, non-cellular. D2 was
therefore correctly skipped. Y2/Y3 are unavailable and Y5 is `selected_r2_branch=NONE`.

Static review identifies a high-confidence test-authority mismatch: D1 reconstructs rails with
`rails_from_atlas(...)`, while the frozen/product torus uses pipeline `authoritativeRails` produced from the
feature map. The raw prescribed-sphere D1 publication also reports all 18 complement components as discs while
its global terms give `18 - 30 + 18 = 6` against source `chi=2`; that aggregate authority must be independently
reviewed before it can drive a branch.

Result/log artifacts: `9703233161 / 9703233545`, digests
`6b13e0bcddc3ffeba93077b6b1115bc8a400b9b9a6051d83df01ac11bec191f7 /
19975ef0fc0e154e02326827287fd60a3a7813b10cda1fe20840e60a072d3c1b`.

New tracker record `M3-CP4c2-TB-X2-R2-CAND-01` is **ACTIVE / TEST-AUTHORITY / STRUCTURALLY INVALID FIXTURE /
NON-STABLE**. Prior X2 CAND-04 remains active/unlocalized because D2 never ran. Stable accounting remains
**42 / 14 / 28**, produced-witness debt **5**, M3 packages **59**.

**That review is complete and has authorized `CB2-DIAG-R1` with amendments under Z0–Z9.** Exact next is
`M3-CP4c-2-CB2-DIAG-R1`, test/diagnostic source only, runtime-free.

`selected_r2_branch=NONE`; `selected_gate=NONE`; `gate_execution_authorized=false`. Do not run 355/357/358,
do not execute D2 from the invalid package, do not start frozen product `CB3`, and do not touch mechanical/C2 or
CP4c-3.

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
- [x] `M3-CP4c-2-TB-X2-PLAN` — **COMPLETE / PLANNING-ONLY.** Specified the three deliverables — independent network-only cellularity oracle, exact 419/437/474 localization, post-certificate A2b observation — with the branch tree, measures **Y0–Y9**, and five falsifiable predictions. Record: `Architecture_M3_CP4c2_TB_X2_Plan.md`.
- [x] `M3-CP4c-2-CB2-DIAG` — **COMPLETE / BUILD GREEN / RUNTIME-FREE.** Source `232ac459b13657529e064272a75c5583770a5963`; D1 independent network-complement oracle and D2 exact 419/437/474 localization added as non-gating diagnostics only. GMP compile run/job `33212932401 / 98990159075` PASS; immutable package `9702321260` / `05237f10…2035`; no Directional runtime; selectors unchanged. Report: `Architecture_M3_CP4c2_CB2_DIAG_Code_Build_Report.md`.
- [x] `M3-CP4c-2-TB-X2-R2` — **COMPLETE / PLANNED CONTROL STOP / NO Y5 BRANCH.** Run/job `33215632118 / 98998526420`; D1 ran once and published all three Y1 records; Y4 failed on the torus control (`V/E=0/0`, required `48/48`); D2 correctly skipped.
- [x] `M3-CP4c-2-TB-X2-R2-REVIEW-PLAN` — **COMPLETE / REVIEW GREEN.** Upheld the stop and confirmed the `48/48` theorem is untouched. **Adjudicated the second defect R2 declined to judge: D1's sphere publication is self-contradictory by exactly 4** — all 18 components discs requires `E − V = 16`, reported 12 (`M3-CP4c2-TB-X2-R2-CAND-02`). Settled the normative complex as the source-mesh barrier complex; authorized `CB2-DIAG-R1` with amendments under **Z0–Z9**. Record: `Architecture_M3_CP4c2_TB_X2_R2_Independent_Review_Record.md`.
- [x] `M3-CP4c-2-CB2-DIAG-R1` — **COMPLETE / BUILD GREEN / RUNTIME-FREE / TEST-DIAGNOSTIC SOURCE ONLY.** Final source `c552a5a4a318063cde2564c40773ec7edaf064f6`; GMP compile run/job `33220315294 / 99012815358`; immutable package `9704935112`. Z1-Z7/Z9 are compiled; Z6 orders D1 torus -> prescribed sphere -> two-ring. Runtime closure conditions remain deferred to R3. Report: `Architecture_M3_CP4c2_CB2_DIAG_R1_Code_Build_Report.md`.
- [x] `M3-CP4c-2-TB-X2-R3-EXEC` — **COMPLETE / VALID DIAGNOSTIC SEMANTIC RED / PLANNED STOP.** Run/job `33222551366 / 99019499929`; D1 selected once, zero Y1 publications, torus `field-transport-atlas-unavailable`; D2 correctly skipped; immutable postflight green. Evidence: `Architecture_M3_CP4c2_TB_X2_R3_EXEC_Artifact_Only_Evidence.md`.
- [x] `M3-CP4c-2-TB-X2-R3-REV` — **COMPLETE / REVIEW GREEN.** Upheld the stop and **localized** `R3-CAND-01` as test-side: `cp4c_build_rail_authority` diverges from production on the cross field (`finalize_surface_cell_raw_cross_field` vs `products.crossField`) and on the hard-feature edge set (locally rebuilt feature map vs `tracingOptions.hardFeatureEdges`) — and the torus is the one witness where that set is non-empty. Opened `R3-CAND-02` for the abort-in-loop gating that produced zero publications and discarded the sphere. Measures **Z10–Z19**. Record: `Architecture_M3_CP4c2_TB_X2_R3_Independent_Review_Record.md`.
- [x] `M3-CP4c-2-CB2-DIAG-R2` — **COMPLETE / BUILD GREEN / RUNTIME-FREE / TEST-DIAGNOSTIC SOURCE ONLY.** Semantic/test source `5ad711e5d4ced95f38e103b993139a6307ba2cee`; GMP compile run/job `33226609913 / 99031482464`; immutable package `9707091209`. Z10-Z19 implementation is compiled; runtime closure remains deferred to R4. Report: `Architecture_M3_CP4c2_CB2_DIAG_R2_Code_Build_Report.md`.
- [ ] `M3-CP4c-2-TB-X2-R4` — **NEXT / ARTIFACT-ONLY DIAGNOSTIC.** Execute `TB-X2-R4-EXEC` on package `9707091209`, then evidence-only `TB-X2-R4-REV`. Z17 ordering is binding: all three per-witness records first; then torus control; then Z3; only then D2/Y5. Z12 snapshot unavailability is an immediate review stop, not a 48/48 contradiction.
- [x] `M3-CP4c-2-TB-X2-R2` (superseded row) — **COMPLETE / ARTIFACT-ONLY DIAGNOSTIC CONTROL STOP / GATE BLOCKED.** Consume immutable package `9702321260` from source `232ac459b13657529e064272a75c5583770a5963` without rebuild. EXEC runs D1 and D2 separately and preserves complete `m3Cp4c2Y1`/`m3Cp4c2Y2` publications; REVIEW adjudicates Y1–Y4 and selects exactly one frozen Y5 corrective branch or stops. **No selector is selected and `TB-GATE-EXEC` is not authorized.** Plan: `Architecture_M3_CP4c2_TB_X2_R2_Artifact_Only_Test_Benchmark_Plan.md`.
- [ ] `M3-CP4c-3-DEFN` — BLOCKED on CP4c-2 closure.

Accepted runtime authority is `M3-CP4c-1-TB-R5`: **355/355**, run/job `33161644741 / 98817323175`, consuming immutable GMP package `9675666067` from source `b1ce8ad65952bd2bd76238f6dfc55523f6a24747`. Required selector remains `e9d88f1196e412e06424294d6be22b32f01c9671ec5e4de119abd3f2fb5afeaa`, with accepted 353/346/316 prefixes unchanged. Stable accounting remains **42 / 14 / 28**, produced-witness debt **5**, M3 packages **60**. `M3-CP4c-0`, `M3-CP4c-0b`, and `M3-CP4c-1` are **CLOSED / ACCEPTED**. CP4c-2 remains runtime-unaccepted; corrected diagnostic build authority is `5ad711e5d4ced95f38e103b993139a6307ba2cee` / immutable GMP package `9707091209`. **Exact next is `M3-CP4c-2-TB-X2-R4-EXEC`, artifact-only under the R4 plan; no cumulative gate runtime is authorized.**

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
- [ ] **M3 — field-aligned curve network.** CP4ab, CP4c-0, CP4c-0b, and CP4c-1 are accepted; current accepted authority is **355/355**. CP4c-2 corrected diagnostic build is green/runtime-free at `c552a5a4a318063cde2564c40773ec7edaf064f6` with immutable GMP package `9704935112`; no 357/358 gate is selected; exact next is artifact-only `M3-CP4c-2-TB-X2-R3-EXEC`; CP4c-3 remains blocked.
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
