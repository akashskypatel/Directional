# M4-CP3-TB1 Independent Review Record

- **Phase:** `M4-CP3-TB1-REV` / `TB-REVIEW`
- **Status:** **COMPLETE / PACKAGE118 NOT PROMOTED / SEVEN REDS ADJUDICATED AS TWO NON-STABLE TEST-AUTHORITY CANDIDATES**
- **Validated semantic source:** `c8d8fc8ae92c067fce04a365bc8dd3b21ddad8dc`
- **Review-source authority:** `3ec69ffeb88f6378ca8a7a680ef8f3a7e4be64f4`
- **Candidate package:** package118 artifact `10182447649`, SHA-256 `1e7b260b5175b77e161bede7ec791a305d11550dd392a11b56757c864d9544d5`
- **Runtime evidence:** run/job `34557818974 / 103134172994`; result artifact `10183361985`, SHA-256 `9f1b15e00616d487b99edc4f6681c9097dc68ff4091a5432f95f34a5c1ea9cec`; diagnostic artifact `10183362199`, SHA-256 `90f9b68699157351532984c176b1aa0c8943becc54a4c75acde24973346d4eda`
- **Reviewer independence:** same-agent review is user-authorized; independence here is a fresh immutable-artifact reopening plus independent static re-derivation from the exact review-source snapshot. No Directional runtime or compile occurred in this review.

## 1. Evidence reviewed

The review did not rely on the TB report as self-proving authority. It re-opened the raw result artifact and an exact source snapshot.

- source snapshot workflow run `34559829994`, artifact `10183917322`, outer SHA-256 `a3bc151e640b5f89ad08825f694ec13c8e59c3518764429babdb4ff7043909fb`;
- snapshot metadata proves `snapshot_sha=3ec69ffeb88f6378ca8a7a680ef8f3a7e4be64f4`, `runtimeExecution=false`, archive SHA-256 `6219e209fbfb7e601dd3617333e301c37fc0e69a0288d8bd30de33c335c13235`, and **5250/5250** source-manifest files verified;
- frozen production contract: `Architecture_M4_DEFN_Frozen_Definitions.md` §17;
- frozen execution plan and raw execution report: `Architecture_M4_CP3_TB1_Test_Benchmark_Plan.md` and `Architecture_M4_CP3_TB1_Test_Benchmark_Report.md`;
- implementation/test authority: `GlobalConformityBaseline.*`, `GlobalConformityParityGraph.*`, `GlobalConformityBaselineTests.cpp`, `TriMesh.h`, and `DCEL.h` from the exact snapshot;
- accepted predecessor: package117 / selector382 **382/382**.

## 2. Mechanical evidence adjudication

The raw execution evidence is complete and trustworthy for the planned gate:

| Planned item | Reviewed result | Verdict |
|---|---|---|
| package118 identity | artifact/provider/download digest all match `1e7b...44d5`; source commit is `c8d8...d8dc` | PASS |
| immutable pre/post manifest | **28/28** before and after | PASS |
| package/source/execution-view censuses | all three before/after pairs byte-identical | PASS |
| fresh-process accounting | exactly **800** processes; zero timeout, skip or selection mismatch | PASS |
| focused rows 383-394 pass A | **5 PASS / 7 RED** | FAIL |
| focused rows 383-394 pass B | **5 PASS / 7 RED** with identical ordered verdict vector | FAIL, deterministic |
| accepted predecessor selector382 | **382/382 PASS** | PASS |
| cumulative selector394 | **387 PASS / 7 RED** | FAIL |

The seven RED ordinals are **386, 388, 389, 390, 391, 392, 394**. The red pattern is deterministic, not flaky or infrastructure-derived. Package118 therefore cannot be promoted even though the accepted predecessor remains green.

## 3. Finding A — six REDs are blocked by an invalid one-face triangle fixture

**Tracker:** `M4-CP3-TB1-REV-CAND-01`
**Unit-test classification:** invalid fixture / test-authority coverage gap (`RP-02`)
**Affected ordinals:** **386, 388, 389, 390, 391, 394**
**Confidence:** high

All six affected identities call `make_topology_fixture(make_triangle_mesh())`. `make_triangle_mesh()` constructs exactly one triangular face. `TriMesh::set_mesh()` calls `compute_edge_quantities()`, which invokes `dcel.check_consistency(..., checkPureBoundary=true)`. `DCEL::check_consistency` explicitly rejects any face with no interior edge as `face is composed entirely of boundary edges`.

The raw log for each of the six identities therefore fails identically before the baseline fixture is returned:

```text
C++ exception with description "compute_edge_quantities(): DCEL consistency check failed"
```

This is not evidence against the §17 parity scheduler, certificate, validator, exterior construction, exhaustive oracle, or production/framed separation. None of those six tests reaches its intended semantic assertion.

The diagnosis is independently discriminated by the same package: square-based baseline identities **384** and **393** reach and pass the production baseline, while graph-only rows **383, 385, 387** also pass. The six failures are specifically tied to the structurally inadmissible one-face `TriMesh` helper.

**Required future correction:** replace the one-face helper with a DCEL-valid triangulated disk that naturally preserves the intended three source-boundary terminals and semantic outer-boundary geometry; keep every existing semantic assertion at equal or stronger strength. Do not relax `TriMesh`/DCEL consistency, skip the failing setup, or special-case the test environment.

## 4. Finding B — ordinal392 assumes a count precondition that the frozen lex scheduler does not guarantee

**Tracker:** `M4-CP3-TB1-REV-CAND-02`
**Unit-test classification:** invalid fixture / incorrect expectation (`RP-02`)
**Affected ordinal:** **392**
**Confidence:** high

`CanonicalPermutationAndReverseOrdinalConsumptionAreInvariant` uses the valid two-face square fixture, successfully builds two baseline plans, proves permutation-invariant semantic digest/counts, and then selects `schedule().front()` before asserting:

```text
ASSERT_GT(entry.count, EInt(1));
```

The authoritative raw run reaches that assertion and reports `actual: 1 vs 1`. That value is permitted by the frozen §17.6 scheduler. For this fixture, the first canonical span uses the unit `(0,1)` support with target size `0.5`, so its preferred count is `d=2`; when a primary-optimal parity flip is selected on such a span, §17.6 requires `x=d-1=1`. Canonical lex refinement explicitly tries the smaller count first when `d>1` and keeps it whenever the primary optimum is preserved.

The failure is therefore not evidence that breakpoint consumption, permutation invariance, or reverse ordinal mapping is wrong. It shows that the test's chosen entry does not structurally guarantee the `count>1` precondition needed for its interior-ordinal assertions.

**Required future correction:** construct/select a span whose final count is independently guaranteed to exceed one under the frozen scheduler, then preserve the existing forward/reverse exact-ordinal assertions. Do not weaken the breakpoint assertions and do not encode the current implementation result as the expected oracle.

## 5. Challenge to the initial semantic-RED diagnosis

The raw TB label `SEMANTIC_RED` correctly distinguishes process-level test failures from orchestration failure, but it does not by itself establish a product regression. Source/fixture review changes the root-cause adjudication:

1. six tests fail before their intended product seam because their shared mesh helper violates the repository's own `TriMesh` admissibility contract;
2. the seventh reaches its semantic setup but asserts an unproved `count>1` fixture precondition contrary to a contract-permitted lex-minimal result;
3. accepted selector382 remains **382/382**, so no accepted behavior loss is demonstrated;
4. package118 is a new unaccepted candidate, so these test-authority defects do not add a stable historical product regression event.

No production implementation defect is established by the seven observed REDs. This finding does **not** assert package118 is production-ready: the intended six semantic contracts and ordinal392 breakpoint contract have not yet been validly runtime-proved.

## 6. Package and regression disposition

- package118 / selector394: **NOT PROMOTED / CANDIDATE RETAINED**;
- package117 / selector382: remains latest accepted M4 runtime authority at **382/382**;
- stable regression accounting: unchanged at **47 events / 14 categories / 33 recurrences**;
- produced-witness debt: unchanged at **5**;
- new review candidates: **2 non-stable test-authority candidates**, covering all seven RED identities;
- A3→A4 production cutover: remains forbidden until corrected candidate runtime evidence is reviewed and accepted.

## 7. Decision

**Approved with adjudication amendments.** The TB1 raw evidence is upheld exactly, but its seven REDs are classified as test-authority defects rather than production failures. Package118 remains unpromoted because the candidate gate is mechanically red and seven intended contracts lack valid green runtime evidence.

No production source, test source, benchmark source, build configuration, selector, package byte, or runtime state was changed in this review. No Directional test/benchmark/binary was executed.

## 8. Next-turn boundary

Per the turn state machine, this review exits to **`M4-CP3-TB1-PLAN` / `TB-PLAN`**, not directly into implementation. The planning turn must freeze the smallest Code + Build correction that:

1. repairs the shared invalid triangle fixture without weakening the six intended semantic contracts;
2. repairs ordinal392's `count>1` precondition without weakening its exact breakpoint/permutation oracle;
3. preserves selector394 identity names/order and accepted selector382 exactly;
4. limits product-source changes to zero unless the planning review finds new evidence that contradicts this adjudication;
5. compiles/packages under the mandatory GMP workflow and routes a new immutable artifact to artifact-only runtime validation.

TB1-REV itself authorizes **no** implementation/test mutation, compile, rerun, package promotion, or A3→A4 cutover.

## 9. Integrity confirmation

- Production code changed: **no**
- Test/benchmark logic changed: **no**
- Build configuration changed: **no**
- Directional tests/benchmarks executed: **no**
- New runtime evidence created: **no**
- Existing evidence inspected locally: **yes**
- Package118 promoted: **no**

## 10. Live handoff

- evidence commit: `c8d8fc8ae92c067fce04a365bc8dd3b21ddad8dc`
- review-source snapshot: `3ec69ffeb88f6378ca8a7a680ef8f3a7e4be64f4`
- current review record: `.agents/Directional/Architecture_M4_CP3_TB1_Review_Record.md`
- exact next: `M4-CP3-TB1-PLAN`, runtime-free planning only
- next skill state: `turn-based-coding-agent/references/turns/TB-PLAN.md`

---

## 11. Independent verification addendum (reviewing agent)

Runtime-free. Both findings are **upheld** and their partition was re-derived rather than accepted.
The disposition — package118 unpromoted, accepted authority unchanged, accounting unchanged — is
correct. One thing the record does not say is added below, because without it this turn reads as a
near-miss when in fact most of the §17 contract has no runtime evidence at all.

### V1 — Finding A's partition is exactly right

Re-derived from the test source rather than from the logs. `make_triangle_mesh()`
(`tests/GlobalConformityBaselineTests.cpp:67-77`) builds a single face `(0,1,2)` over three
vertices, and calls `mesh.set_mesh(...)` inside the helper — so the throw occurs during helper
construction, *before* any `build_global_conformity_baseline` call. Exactly six identities consume
it, and they are exactly Finding A's six:

| ordinal | identity | site |
|---|---|---|
| 386 | `OneEndedTerminalUsesComponentLocalExterior` | `:324` |
| 388 | `CanonicalLexPrefixChoosesLeastCountVectorAcrossEqualTJoins` | `:359` |
| 389 | `ParityFlipMapsOneToTwoAndLargerToPredecessor` | `:369` |
| 390 | `IndependentTinyExhaustiveOracleMatchesParityOptimumAndLexTie` | `:386` |
| 391 | `IndependentValidatorRejectsParityCertificateTamperMatrix` | `:403` |
| 394 | `ProductionBaselineBinderIsStructurallySeparateFromFramedSolver` | `:513` |

Ordinal 392 does **not** consume it (`:469` uses `make_square_mesh()`), so the two findings are
genuinely disjoint and no RED is double-counted or mis-binned. The passing square-based identities
384 and 393 discriminate the diagnosis, as the record says.

### V2 — Finding B's classification is contract-correct

`count == 1` is a legal §17.6 output: positivity requires `x_s >= 1`, not `>= 2`, and the no-flip
branch with `d_s = 1` yields exactly 1. Nothing in the frozen contract guarantees that
`schedule().front()` — here the `twoPieceFirst` span built at `:213-219` — carries a count above
one. A two-piece span with count 1 is also coherent on its own terms: support pieces are the
source-location decomposition and are independent of the subdivision count (§17.3). So
`ASSERT_GT(entry.count, EInt(1))` (`:482`) is an unguaranteed precondition, not a product defect.

Worth recording precisely because the record understates it in one direction: ordinal 392's actual
subject — permutation invariance — **did** pass. `semantic_digest()` equality and `exact_counts`
equality under span reversal both hold at `:478-479` before the failing line. What is lost is only
the breakpoint-consumption half at `:484-492`.

### V3 — the unproven-surface ledger, and an execution obligation on the successor

Neither finding is evidence against §17. But "not evidence against" is not evidence for, and seven
identities produced **no** evidence either way. Recorded explicitly so no later turn cites this TB as
partial CP3 progress:

**Proven by this package (5):** family-free parity semantics across `Mandatory`/`Trace`/`Cut` (383);
boundary-incidence multiplicity (384); same-region double incidence as a zero-effect self-loop (385);
**minimum-cardinality T-join strictly beating a local greedy choice** (387); all-even constructive
witness yielding no infeasibility outcome (393).

**Unproven — zero runtime evidence (7):** component-local exterior construction (386); canonical
lex-prefix selection (388); the parity flip map `1 -> 2` and `d_s -> d_s - 1` (389); the independent
tiny exhaustive oracle (390); the validator tamper matrix (391); reverse-ordinal breakpoint
consumption and `localDenominator` binding (392, partial); structural separation of the production
baseline from the framed solver (394).

Three of those — 390, 391 and 388 — are precisely the non-vacuity instruments §17.7 mandates
(independent recomputation, per-family tamper falsification, per-decision lex receipts). A fourth,
394, is the structural guarantee §17.3/§17.9 rely on to keep accepted selector382 valid; accepted
382/382 passing is welcome empirical evidence that nothing broke, but it is not the separation proof.
The §17 production contract is therefore substantially uncertified, and CP3 is nowhere near closure.

**Obligation on the corrective successor, beyond the record's §8 list.** Repairing a fixture can make
an identity pass while the intended assertion still never executes — a repaired mesh could yield a
degenerate case whose loop body runs zero times, or a `count > 1` span that trivially satisfies its
guard without exercising the breakpoint path. A green rerun alone therefore cannot distinguish
"proved" from "reached a vacuous branch." The successor TB must publish, per previously-blocked
identity, a deterministic success-visible receipt derived at runtime showing the intended assertion
executed and on what — for 391 the tamper-row count actually exercised, for 390 the number of oracle
comparisons performed, for 392 the `entry.count` and both breakpoint ordinals resolved. This is the
same discipline already frozen for ordinal 374's receipt and for §17.7's per-decision receipts;
`LESSONS.md` 160 and 171 are the standing statements of it.

### V4 — lineage and accounting confirmed independently

Hashed directly: selector394's first **382** rows give
`1d59b1f709e51854f8ceaee1a161687ff882a128dabdc79882712c97a15ca84f`, byte-identical to accepted
selector382, and its first **373** rows still give `6d00cafa939a0e89c4816a6b0e8fec83232c0e7a94a468ae547b1667171e7d8b`.
The chain **373 ⊂ 380 ⊂ 382 ⊂ 394** is exact and append-only; rows 383-394 are the only additions.
No accepted-green loss occurred, so no stable event arises: accounting stays **47 / 14 / 33**, debt
**5**, accepted authority **package117 / selector382**.

The record's §8 item 4 — hold product source at zero changes unless new evidence contradicts this
adjudication — is the right call and should be kept: it makes the corrective turn a control
experiment whose green would isolate the fixture repair as the cause.
