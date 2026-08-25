# M3-CP4c-0 TB Independent Review / Planning Brief

## Status / Turn

**CLOSED 2026-08-25.** `M3-CP4c-0-TB-REVIEW-PLAN` executed this brief and answered R1–R6. The review
record is `Architecture_M3_CP4c0_TB_Review_Plan_Independent_Review.md`; the corrective series is **E0–E10**
and the exact next turn is **`M3-CP4c-0-CB2`** (Code + Build only).

Answers, in one line each — full argument in the review:

- **R1** — the zero-time state is reconstructed as far as evidence permits; the specific route among
  three candidates is **not decidable from the published payload**, because `sourceFace`, the branch, and
  the exact entry parameter were computed and then dropped by the witness diagnostic emitter. Measure E1
  determines it in one turn. `sourceVertex=0`/`singularity=0` are the trace **seed**, back-filled at
  `SurfaceCellTracing.cpp:818-819`, not the failure locus.
- **R2** — verdict **(3)**: a state that should never have been produced. T6 is correct and unamended.
- **R3** — yes, they disagree, and the disagreement is exact: `alpha = d[next]` and `beta = d[prev]`, so
  the sector test *is* the same sign predicate at `tol = 1e-10`. Two bands are characterized. `direction_in_vertex_sector` is **exactified**, not duplicated; no second rule and no new tolerance.
- **R4** — all three entry-point producers audited; two further defects found (non-exhaustive T1 dispatch;
  a position-blind cycle break that is now unsound as a terminus rule) plus an entirely unasserted
  cross-edge flow invariant.
- **R5** — fixture and oracle are both **valid**; neither is edited and Q8 is not weakened.
- **R6** — one successor: a **generalized production correction** plus a formally justified definition
  amendment. No diagnostic-only turn was needed, because the missing data already exists in the error
  struct and only needs emitting.

The original brief follows unchanged, for provenance.

---

**PROPOSED / PENDING INDEPENDENT REVIEW.** Exact turn: `M3-CP4c-0-TB-REVIEW-PLAN`.
This brief authorizes review and planning only.

## Immutable evidence to review

- implementation/evidence source: `e784e44ce86e458b250b04689288f5f365ca507b`;
- immutable compile package: `9577900736`, SHA-256 `b9c597584177f31fd2d923b622a4b20fbb243c7bd007b37cced8ff128e349f31`;
- authoritative TB run/job: `32891161394 / 97943220460`;
- result artifact: `9579600371`, SHA-256 `fe472587aba74c2face26a2f65c0706439232bec2e5cc594d81711a26773b399`;
- diagnostic log: `9579600958`, SHA-256 `7ddfe4c8e48b1b618c7a60ad6cf900a767ff954309a1c3cc52a8896306d98039`;
- required selector: **328 = accepted 316 + 12 CP4c-0**, SHA-256
  `cf93622ea8807b26037d2fb6305adf721a23724bc519886c455e98c49c5f3600`;
- frozen definitions: `Architecture_M3_CP4c0_DEFN_Frozen_Definitions.md`.

Retry-0 run `32890863928` is infrastructure-only and carries no semantic evidence.

## Facts already settled — do not relitigate

1. Artifact-only integrity held: no configure, compile, relink, repair, source/test/fixture/selector/package
   mutation, or performance benchmark occurred.
2. Required gate **328/328 PASS**: accepted prefix **316/316**, CP4c-0 additions **12/12**.
3. Prior Cartesian `FieldBranchBoundaryPairing.connections` ambiguity is not the current first failure;
   CP4c-0 removed that authority and its dedicated falsifiers are green.
4. Prescribed sphere reaches source topology and A1, then A2a rejects
   `BranchContinuationDegenerateEntry` at `singularity=0`, `sourceVertex=0`, `sourceEdge=6-8`; no network.
5. Therefore Q8's 24 traces, terminal `TraceIntersection`, and face `1-2-5` crossover are unavailable /
   not observed. Q8 is binding RED and CP4c-0 is not accepted.
6. Frozen T6 says exact `t*=0` is typed `BranchContinuationDegenerateEntry`; frozen Q8 says this sphere
   must reach the network. The review must reconcile those contracts, not simply weaken either one.

## Review questions

### R1 — reconstruct the exact zero-time state

Identify as far as evidence permits the failing source face, branch, `FieldBoundaryPoint` edge/exact
parameter, exact barycentric direction, candidate exit-time/minimizer set, and immediately preceding
transition (initial singularity emission, ordinary edge transport, or T2 regular-vertex transit). Record
missing data explicitly; do not infer it from identifiers or geometry coincidence.

### R2 — adjudicate T6 at the observed state

Determine whether exact `t*=0` is (1) genuinely invalid and correctly rejected, (2) a valid boundary/
vertex continuation represented in a form T6 incorrectly rejects, (3) a state that should never have been
produced because point/branch propagation is wrong, or (4) not decidable from current evidence.

### R3 — audit the exact-versus-sector-rule boundary

A2a continuation ordering is exact. T2 deliberately reuses A1's existing `direction_in_vertex_sector`
half-open sector rule, including its established topology tolerance. Determine whether these contracts can
disagree at a vertex in a way that re-emits a branch whose next exact continuation is zero-time. Do not
invent a second sector rule or a new tolerance.

### R4 — audit entry-position and branch propagation

Trace the single-authority state through singularity start, cross-edge transport, and regular-vertex T2
transit (including `incomingCarrier.reset()`). Verify each path publishes the exact point/branch required by
the next continuation and cannot mistake the just-reached boundary for a fresh zero-time exit.

### R5 — adjudicate witness/oracle validity

Separately establish intended sphere contract, actual fixture state, required preconditions, implementation
result, and Q8 oracle. Correct the fixture only if it cannot structurally exercise the intended behavior.
Do not encode current production output or weaken terminal-event/crossover requirements.

### R6 — freeze exactly one smallest successor

Only after R1–R5, choose: a generalized production correction with falsifying tests; a formally justified
CP4c-0 definition correction if definitions are inconsistent; or, if evidence is genuinely insufficient,
the smallest diagnostic-only Code + Build addition needed to expose the missing exact state. Define build
verification and future artifact-only validation before authorizing implementation.

## Stop / scope rules

- No runtime, benchmark, compile, implementation, test-source, fixture, or selector mutation in review.
- No semantic rerun of `M3-CP4c-0-TB`.
- No fixture-specific sphere branch/edge/index special case.
- No weakening T6, Q8, terminal `TraceIntersection`, or crossover without an independently justified
  contract correction.
- No second sector-membership algorithm and no new topological tolerance.
- Do not reopen CP4ab A2b `k>=2` ordering.
- Do not enter C4/C5, torus, mechanical, CP4c-1, CP4c-2, or CP4c-3 implementation scope.

## Required review output

Record the adjudicated failure class/confidence, exact evidence/source support, unresolved gaps, T6/Q8
status, one smallest successor turn and verification plan, and confirmation that review executed no
runtime/build/product/test mutation. Until that record closes, **no Code + Build turn is authorized**.
