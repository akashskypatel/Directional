# M4-CP2-TB1 Review Record

**Status:** COMPLETE / REJECTED FOR PROMOTION / PACKAGE116 UNPROMOTED / M4-CP2 OPEN / RUNTIME-FREE
**Turn:** `M4-CP2-TB1-REV`
**Review model:** same-agent adversarial review, user-authorized 2026-09-10; evidence/source independence, not personnel separation
**Reviewed semantic source:** `eb23177e6ee9cbb27cf1ee30a299911abc0e1c60`
**Reviewed package:** package116, artifact `10166351695`
**Reviewed TB:** run/job `34515352025 / 102999258938`

## 1. Boundary and disposition

This review executed no Directional runtime, compile, relink, benchmark, generated test discovery, or product/test/fixture/selector mutation. Same-agent review is explicitly authorized; independence was enforced by re-opening the immutable package/TB evidence, independently re-deriving the selector and raw-process receipts, and auditing the compiled source against the frozen M4 contract rather than inheriting the EXEC narrative.

The measured TB1 runtime is genuine: package116 passed every executed gate. **Promotion is nevertheless rejected.** The source audit found three frozen-contract gaps that the seven CP2 identities did not falsify. A full-green gate cannot close CP2 when the gate itself omits required certificate/binding/receipt obligations.

Accepted runtime authority therefore remains **M4-CP1 package115 / selector373**. Package116 and selector380 remain unpromoted candidate evidence. `M4-CP2` remains OPEN. Exact corrective successor is runtime-free **`M4-CP2-CB2`** under `Architecture_M4_CP2_CB2_Code_Build_Plan.md`.

## 2. Review source and primary evidence reopened

Current review source was materialized by exact source-snapshot run `34518939427` from control SHA `c2827fb05b0eec071d5061f69c591f4f39fcff78`; snapshot artifact `10168843554` has SHA-256 `ff9baa0fc1c42b20de074e5322360d0d35efd8d4684bc2013fe8ba034a393470`, and its source archive hashes to `8f8f4944335a08b086eee9c31a1f9f44b627dd67c83c8ab4c9ec1169ac2dc757`. Snapshot runtime execution is false.

The review independently re-opened the exact candidate authorities:

- package116 artifact `10166351695`, provider/downloaded ZIP SHA-256 `c61b9900a2745454594825de81181ce982ec4b7986f40aa3b23c23e12d0e8e61`;
- compile run/job `34512397141 / 102989549611`; compile-log artifact `10166352142`, SHA-256 `3c3e3658d3f3341f108af5397f681061cb6c77be85e9dd1355fb28dba77e2dd0`;
- semantic source `eb23177e6ee9cbb27cf1ee30a299911abc0e1c60`; mandatory GMP/GMPXX evidence, all selector-owner targets, package `SHA256SUMS` **28/28**, and `runtimeExecution=false` are intact;
- TB1 result artifact `10167558308`, SHA-256 `214c854c0274e1de73b73a3e4fab4906729fda453fe090c60792645edee5fa9a`;
- TB1 diagnostic-log artifact `10167558730`, SHA-256 `dceafa9801564d16ba27ca1b12d3e9bc79d648363f725fb78ee4ac54624f2bb7`.

## 3. Independent runtime-evidence re-derivation — upheld

Selector380 contains exactly **380 LF rows** at SHA-256 `512c9ecea76b20ed85f6d74cbbdd9c415504ffc69d37a595d68b2de78bc409c4`. Its first 373 rows hash to `6d00cafa939a0e89c4816a6b0e8fec83232c0e7a94a468ae547b1667171e7d8b`, exactly the accepted selector373. The seven appended CP2 identities occupy ordinals 374-380 in the frozen order.

Independent ledger parsing proves:

- cumulative selector380: **380/380 PASS**;
- accepted predecessor rows 1-373: **373/373 PASS**;
- CP2 rows 374-380: **7/7 PASS**;
- focused phase A: **7/7 PASS**;
- focused phase B: **7/7 PASS**, verdict vector identical to A;
- RED/SKIP/timeout/selection mismatch: **0/0/0/0**;
- owner totals: **30/30 authority-kernel / 234/234 producer / 75/75 completion / 41/41 validation**.

All **394** raw GoogleTest process logs were checked: 380 full-selector processes plus 7 focused-A plus 7 focused-B. Each contains exactly one intended `[ RUN ]` and one `[ OK ]`; no `[ FAILED ]` or `[ SKIPPED ]` receipt occurs. Package, extracted-source, and execution-view censuses are byte-identical before/after. The TB execution boundary records no compile, relink, generated discovery, repair, or source/test/fixture/selector mutation.

These facts are accepted as accurate runtime evidence. The rejection below is not a claim that TB1 fabricated green output.

## 4. Finding R1 — required multi-coordinate oracle success receipt is absent

**Candidate:** `M4-CP2-TB1-REV-CAND-01`
**Classification:** CONTRACT/OBSERVABILITY GAP / NON-STABLE / CORRECTIVE CB2

The now-folded CB1 contract required the deferred exhaustive oracle to use a multi-coordinate `±2` instance within the frozen `E<=6, x_s<=8` envelope, compare the full exact count vector, and **make the receipt identify coordinate count and `±2` presence**. That obligation is preserved in `M4_Consolidated_Record.md` §2.10 and this review record; the original plan text remains recoverable from git history. The addendum likewise required a published receipt naming coordinate count and whether `±2` is present.

The implementation does construct the intended hard case: `multi_coordinate_bidirected_problem()` has four coordinates and same-row equal-sign pairs that produce coefficient magnitude 2; exhaustive enumeration is full-vector and the solver result is compared exactly. Independent review enumeration found primary optimum deviation 5, twelve primary-optimal feasible vectors, and lexicographic winner `(1,1,2,2)`, so this is a genuine coordination/tie witness rather than a one-degree-of-freedom stand-in.

However the only receipt is:

```cpp
SCOPED_TRACE("coordinateCount=4; containsBidirectedCoefficientMagnitude2=true");
```

GoogleTest emits `SCOPED_TRACE` on failure, not on a successful assertion path. The raw full/focused ordinal-374 logs contain the test filter, `[ RUN ]`, and `[ OK ]`, but **no `coordinateCount=4` or `containsBidirectedCoefficientMagnitude2=true` text**. The runtime report's statement that the focused runs provide a direct receipt for that metadata therefore overstates the raw evidence.

This does not invalidate the mathematical oracle result; it invalidates the mandated **published-success receipt**. CB2 must emit a deterministic success-visible receipt derived from the fixture and the next TB harness must require it in both focused and cumulative ordinal-374 logs.

## 5. Finding R2 — carried WorkLedger assurance/bounds/history are not independently certified

**Candidate:** `M4-CP2-TB1-REV-CAND-02`
**Classification:** SOURCE/CERTIFICATE-CONTRACT GAP / NON-STABLE / CORRECTIVE CB2

Frozen M4 §7.4 requires `GlobalConformityWorkLedger` to record at minimum semantic `V,E`, algorithm identity, assurance class `FiniteExactConvergence(Corollary3.7+Theorem3.8+Corollary3.9,M=2)`, exact `H/U/Q/L` bit widths, target/count/capacity/cost widths, **maximum observed exact-integer width**, initializer dimensions and exact-feasibility receipt, exact refinement count and before/after objective for every committed refinement, each refinement's Bi-MCF/WPbM/WPM dimensions and peak matching dimensions/primitive, and retry/reset count zero. Frozen §8.1 requires the CP2 certificate to carry WorkLedger bounds/observed maxima, and §9 requires the independent oracle to re-evaluate these dimension/bit-width claims. CB1 §3 explicitly required independent WorkLedger-bound validation and rejection of WorkLedger tamper.

The producer carries several of those values, but the public `GlobalConformityWorkLedger` has **no assurance-class field and no maximum-observed-exact-integer-width field**. More importantly, `GlobalConformityCP2Validator.cpp::verify_certificate(...)` checks only:

- algorithm/matching primitive identity + revision;
- semantic row/span counts;
- initializer exact-feasibility boolean;
- `refinementM == 2`;
- terminal non-improvement boolean/non-negative terminal cost change;
- retry/reset count zero.

It does **not** independently validate `initializerNodeCount`, `initializerArcCount`, `refinementCount`, `refinements.size()`, any `H/U/Q/L` bit width, target/count/capacity/cost widths, peak matching node/edge counts, or the per-refinement before/after objective and graph dimensions. The CP2 certificate owns its own WorkLedger object, so validating the optional CP1-compatible `feasiblePlan` later does not validate a tampered certificate ledger; mixed/infeasible outcomes do not carry that plan at all.

The compiled tamper matrix confirms the coverage hole: row 376 tampers only `workLedger.refinementM` from the entire WorkLedger family. Therefore a certificate with, for example, a corrupted `hBitWidth`, initializer dimension, refinement history/count, or peak matching bound can pass the current CP2 verifier if all already-checked fields remain unchanged.

CB2 must carry the missing assurance/max-width authority, independently rederive every frozen WorkLedger field family, and add a dedicated tamper identity covering representative bounds/history/assurance/maxima rather than treating one `refinementM` mutation as coverage of the ledger contract.

## 6. Finding R3 — CP2 outcome has no semantic digest binding certificates/infeasible facts/full supports

**Candidate:** `M4-CP2-TB1-REV-CAND-03`
**Classification:** SOURCE/BINDING-CONTRACT GAP / NON-STABLE / CORRECTIVE CB2

Frozen M4 §3.2 requires every plan to publish, and the independent oracle to rederive, a semantic digest over canonical bindings, **full spans/support paths**, boundary incidences, exact counts, compact breakpoint-generator contracts, **certificates and infeasible-subset facts**.

`GlobalConformityOutcome` publishes only `sourceDigest`, `networkDigest`, `cutGraphDigest`, `topologyPlanDigest`, `targetMetricDigest`, and `normalizedProblemDigest`. There is no CP2 outcome semantic digest. The existing CP1 `GlobalConformityPlan::semantic_digest()` intentionally preserves the accepted CP1 feasible product and does not bind CP2 certificate or infeasibility data; moreover mixed/infeasible CP2 outcomes have no `feasiblePlan` at all.

`normalized_problem_digest(...)` cannot substitute for the missing semantic digest. It hashes topology/metric bindings, canonical row identities, span **network-arc IDs plus preferred counts**, and incidence metadata. It does not hash each span's ordered `supportPieces`, and by definition it contains no produced certificate, theorem/WorkLedger/terminal-witness, or infeasible-subset result.

Thus two CP2 outputs can lack the frozen semantic identity that is supposed to bind exactly the new CP2 material. This is a checkpoint-closure blocker even though the verifier separately validates several member fields.

CB2 must add an **additive CP2 outcome semantic digest** without changing accepted CP1 `GlobalConformityPlan::semantic_digest()` behavior. It must canonically bind full ordered support paths, incidences/counts, scheduled certificate evidence, and infeasible-subset facts; the independent verifier must rederive it by an implementation-independent path. `normalizedProblemDigest` remains the normalized-input/problem binding and must not be overloaded into this role.

## 7. Surfaces independently upheld

The review found no evidence requiring changes to these already-measured surfaces:

- deterministic connected-component partitioning and exactly-once incidence coverage;
- all-feasible CP2 schedule equality with accepted CP1 counts/semantic plan behavior;
- typed deterministic infeasibility through a genuinely infeasible constructed component;
- certificate schedule/preferred/support equality, exact objective, balance, parity, and positivity checks;
- terminal fixed-`M=2` witness reconstruction, WPM graph identity, perfect matching, exact primal/dual equality and dual feasibility, mapping back to residual/b-matching flow, and non-negative terminal semantic cost change;
- the pinned LEMON `MaxWeightedPerfectMatching` source contract used for integer-scaled primal/dual witness extraction.

These upheld areas do not cure R1-R3 because the frozen CP2 exit is conjunctive.

## 8. Gate and checkpoint adjudication

The seven CP2 identities are real and all green, but the cumulative gate is **insufficient for promotion in its current source form**. R1 proves one mandated success receipt is silent on PASS. R2 proves required WorkLedger certificate fields/assurance are absent or unchecked. R3 proves the CP2 semantic output digest required to bind the new certificate/infeasibility surface is absent.

Therefore:

- package116 is **NOT PROMOTED**;
- selector380 is **NOT accepted M4 authority**; it remains immutable candidate lineage/evidence and must not shrink;
- package115/TB2 and selector373 remain accepted M4 runtime/required-green authority;
- `M4-CP2` remains **OPEN**;
- no TB1 rerun is useful before source correction;
- no definition turn is required because the frozen requirements are explicit enough to implement directly.

Stable accounting remains **47 events / 14 categories / 33 recurrences**, produced-witness debt **5**, accepted package authority **115**. R1-R3 are review-time contract candidates, not observed runtime product regressions, so each is non-stable and adds **+0** stable event/category/recurrence.

## 9. Corrective successor

Exact next is runtime-free **`M4-CP2-CB2`** under `Architecture_M4_CP2_CB2_Code_Build_Plan.md`.

CB2 must correct only the three review findings while preserving accepted CP1 semantics and the already-proved CP2 behavior. It must extend candidate selector380 append-only to selector382 with two dedicated correction identities, make ordinal 374's success receipt observable, compile/package only through the mandatory GMP/GMPXX reusable workflow, and execute no Directional runtime.

A succeeding artifact-only TB must prove the correction identities plus the cumulative selector without treating package116's earlier 380/380 as promotion evidence.

---

## 10. Independent verification addendum (reviewing agent, M4-CP2-TB1-REV)

Runtime-free. Re-derived from immutable source `eb23177e6ee9cbb27cf1ee30a299911abc0e1c60` and the
frozen definitions. The delegated adjudication is **upheld and extended**: package116 stays
unpromoted, selector380 stays candidate lineage, `M4-CP2` stays OPEN, accounting stays
**47 events / 14 categories / 33 recurrences**, debt **5**, accepted authority **package115 /
selector373**. One new blocking finding (V3) is added to the CB2 scope.

### V1 — R1/R2/R3 and the gate adjudication are sound

R1 is technically exact: GoogleTest emits `SCOPED_TRACE` on the failure path only, so a passing
ordinal 374 publishes nothing. R2's use of the tamper matrix is the correct non-vacuity instrument —
row 376 tampers only `workLedger.refinementM`, so the remaining ledger families are uncovered by
construction. R3 is a genuine frozen §3.2 binding gap. Two procedural calls are also right: no TB
rerun can cure a source-contract gap, and no DEFN is needed because the frozen text is explicit.
§7's closing logic — upheld surfaces do not cure R1-R3 because the CP2 exit is conjunctive — is the
correct standard.

### V2 — R1's site list is complete; harden the receipt from derived facts

Verified in `tests/GlobalConformityPlanTests.cpp`: exactly **one** `SCOPED_TRACE` (line 549) and
**zero** `std::cout` / `RecordProperty` emitters. So no other identity hides a non-emitting receipt,
and R1's scope is complete. The corrective plan's §2 already fixes the mechanism precisely — stdout
text present on PASS, gated as required tokens in focused-A, focused-B and cumulative raw logs — and
that is consistent with how every other gate in this project publishes evidence, so no alternative
mechanism is prescribed here.

One hardening: §2 requirement 4 asks that receipt facts be derived from the constructed fixture
"where practical". That should be **mandatory**, not conditional. A hard-coded receipt string is
exactly the failure V3 documents below — a claim that stays literally true while the fixture it
describes stops backing it. The emitted `coordinateCount` and coefficient-magnitude facts must be
computed from the fixture at runtime and asserted, so the receipt cannot outlive its subject.

### V3 — NEW BLOCKING FINDING: ordinal 374's magnitude-2 coefficient is behaviourally inert

**Candidate:** `M4-CP2-TB1-REV-CAND-04`
**Classification:** SEMANTIC/OBLIGATION-VACUITY — NON-STABLE — CORRECTIVE CB2

`multi_coordinate_bidirected_problem()` (`tests/GlobalConformityPlanTests.cpp:275-282`) is
structurally bidirected — spans 0 and 1 each carry a same-row equal-sign end pair, giving row 0 the
coefficients `+2` and `-2`. But the instance never exercises them. Row 1 forces `x2 = x3`, so row 0
reduces to `2(x0 - x1) = 0`, i.e. `x0 = x1`: the factor 2 divides out.

Exhaustive check over the oracle's own search box confirms it. Replacing both magnitude-2 end pairs
with single ends (the "magnitude-1 twin") leaves the result bit-identical:

| fixture | optimum | primary cost |
|---|---|---|
| shipped `±2` fixture | `(1, 1, 2, 2)` | 5 |
| magnitude-1 twin | `(1, 1, 2, 2)` | 5 |

The `M4-CP1-TB1-REV` §10.2 obligation required a multi-coordinate `±2` instance **so that the
local-fixed-point risk introduced by fixed `M=2` is exhibited**. A fixture whose `±2` cancels cannot
exhibit it, and the receipt R1 mandates — `containsBidirectedCoefficientMagnitude2=true` — would,
even once made observable, attest to a property that is structurally present and does no work.
Making an inert claim observable does not discharge the obligation. **§10.2 is not discharged in
substance**, independently of R1.

**Discriminating criterion for CB2 (falsifiable before the build):** the fixture is adequate only if
its magnitude-1 twin yields a **different** optimum. A `±2` coefficient earns its keep by imposing a
**parity obstruction**; where it merely cancels, it is decoration.

**Satisfiability witness** — such fixtures exist and are not scarce (3328 in the searched
four-span family). One instance, stated so CB2 cannot stop for want of a construction:

    span0: ends {(0,+1),(0,+1)}  preferred 1
    span1: ends {(0,-1),(0,-1)}  preferred 1
    span2: ends {(0,+1),(1,-1)}  preferred 1
    span3: ends {(1,+1)}         preferred 1

Here row 1 gives `x3 = x2` and row 0 gives `x2 = 2(x1 - x0)`, so `x2` is forced **even** — the
obstruction is live. Optimum `(1,2,2,2)`; magnitude-1 twin `(1,2,1,1)`. CB2 is not obliged to adopt
this fixture, only to publish one meeting the criterion.

### V4 — oracle search box is non-truncating, and the tie rule is genuinely exercised

`tiny_exhaustive_count_vector_oracle` brute-forces counts in `[1,8]`. A too-small box fails safe (it
would produce a false RED, never a false green), and here it does not bind at all: the optimum's
largest coordinate is 2. Separately, the minimum primary cost of 5 is attained on a **12-point tie
plateau**, so the canonical lexicographic tie rule is really exercised rather than reached vacuously.
No action; recorded so the box bound is not re-litigated.

### V5 — R2 does not reopen the CP1 closure

R2 concerns `GlobalConformityWorkLedger` fields required by frozen §7.4, which predates CP2. The CP1
exit conjunct requires only that the solver contract is **compiled**
(`Architecture_M4_DEFN_Frozen_Definitions.md:578`), while independent certification of **carried**
algorithm-native evidence is assigned to CP2 (`:580`). The gap is therefore CP2-scoped by
construction and the CP1 closure stands. Recorded explicitly so a reader does not infer a
retroactive defect in a closed checkpoint from R2's wording.

### Amended CB2 scope

CB2 corrects **four** findings (R1, R2, R3, V3). V3 changes the fixture that ordinal 374 consumes,
so ordinal 374's body changes and package116's earlier `380/380` verdict for that row describes a
superseded body — already handled by the successor's refusal to treat it as promotion evidence.
Selector380 remains append-only and must not shrink; the correction identities extend it.
