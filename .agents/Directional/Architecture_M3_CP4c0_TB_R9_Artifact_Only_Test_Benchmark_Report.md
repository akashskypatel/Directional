# M3-CP4c-0-TB-R9 — GMP Artifact-Only Test + Benchmark Report

**Status:** COMPLETE / VALID SEMANTIC RED — **344/346**
**Turn boundary:** Test + Benchmark, artifact-only. No configure, compile, relink, repair, generated discovery, product/test/fixture/selector mutation, or performance benchmark was permitted or performed.
**Exact next:** independent `M3-CP4c-0-TB-R9-REVIEW-PLAN` only. Do not enter `M3-CP4c-0b-CB1` automatically.

## 1. Immutable authority

| Authority | Value |
|---|---|
| GMP package source | `66325345567106fe7de8560ee2aee5f07ca665de` |
| Immutable package artifact | `9634245265` |
| Package ZIP SHA-256 | `4ef834465ee8db3110f40f7882cde4a39f94821b6bc0daba3ae0b0e04d7e5629` |
| Packaged source archive SHA-256 | `4c7a5585fd0627a7e1aa41cf84181d063bf102c3ab94895169ae54dff27f9110` |
| Exact arithmetic backend | `GMP` |
| TB-R9 control SHA | `43949227e550fde10c8792787697f98ba9089cfc` |
| Authoritative run / workload job | `33048964354 / 98439563813` |
| Result artifact | `9636849182`, ZIP SHA-256 `b485c1cfe5f929600bae382b1a01954b319dd4d1904e1dd1675cb2ad02771c57` |
| Diagnostic artifact | `9636849748`, ZIP SHA-256 `9a23f1e9f8de5bb36086ed2ea1e20900cbb9cf53a940bc7c336a4ab2516d4023` |
| Frozen selector | **346**, SHA-256 `20d3b0b1400d5cab6af4a339a858c56fb7fd0359fb995a395dad215b20f3e46a` |
| Accepted first-316 prefix | **316/316 PASS**, SHA-256 `601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c` |
| First-328 prefix | **328/328 PASS**, SHA-256 `cf93622ea8807b26037d2fb6305adf721a23724bc519886c455e98c49c5f3600` |

The package metadata recorded build/preflight exit code `0`, `runtimeExecution=false`, `turnBoundary=Code+Build-only`, and `exactArithmeticBackend=GMP`; `gmp-evidence.txt` resolves both `libgmpxx.so` and `libgmp.so`. TB-R9 installed the GMP runtime dependency but did not rebuild or relink the package.

## 2. Control-plane pre-run failure — not semantic evidence

Run `33048777701` failed only the temporary payload SHA-256 verification before any Directional binary was executed. Schema validation and GMP installation succeeded; the workload never entered the artifact-only runtime plan. Its tiny status-only result artifact was `9636706461` (ZIP SHA-256 `f13f927524a58c328c47aa74851ab3329fd65c0ff2eebbe692c67ca7558bab7c`) and log artifact `9636706981` (ZIP SHA-256 `0aaf94d62d44c2950ca25cd4315458465f0a9dbb45992fa7eca167f42bad51a0`). The caller digest was corrected once and a new trigger produced the authoritative run above. This orchestration-only attempt consumes no semantic credit and does not change stable regression accounting.

## 3. Frozen gate result

TB-R9 executed all **346** frozen identities as fresh processes:

- **344 PASS / 2 RED / 0 orchestration errors**;
- accepted prefix **316/316 PASS**;
- first-328 prefix **328/328 PASS**;
- no per-identity timeout at the frozen **60 s** stop bound;
- no escaping `C++ exception with description`;
- immutable package/source/fixture/selector/executable pre/postflight: **PASS**;
- Q8 criteria owned by CP4c-0: **criterion 1 PASS, criterion 4 PASS, criterion 5 PASS**; criteria 2 and 3 remain moved together to CP4c-0b by Amendment 11.

The former TB-R8 pathological identity `ResolvedBranchCorrection.AcceptedWitnessesNeverPublishDegenerateOrOutsideOutflowRejections` now passes in **102 ms** under the CB9 deterministic-cost correction, rather than spending 853.437 s and escaping through the legacy `gcd()` backstop.

The two RED identities are:

| Ordinal | Identity | Runtime | Classification |
|---:|---|---:|---|
| 333 | `ResolvedBranchCorrection.ExactVertexSectorUsesPublishedDirectionAcrossLossyRoundTrip` | 51 ms | candidate test-side GMP portability defect |
| 344 | `ResolvedBranchCorrection.ExactContinuationMagnitudePolicyFailsClosedWithoutTolerance` | 2 ms | candidate test-side positive-control fixture/precondition defect |

Because the frozen gate is not 346/346, **CP4c-0 is not accepted or closed by TB-R9** even though all three Q8 criteria it owns are green.

## 4. Candidate R9-01 — legacy lossy-round-trip assumption is not portable to GMP

Ordinal 333 fails at `tests/FieldAlignedCurveNetworkTests.cpp:5726` on `ASSERT_TRUE(found)`, before the test reaches the production vertex-sector predicate it intends to falsify.

The witness search assumes `ENumber::to_double(18)` means “render exactly 18 decimal digits, then parse that text back to binary double.” That is the legacy backend behavior in `include/directional/numerics/ExactNumber.h`. The GMP backend instead implements `ENumberGMP::to_double(int)` as `mpq_class::get_d()` and does not use the `maxDigits` argument. Therefore the test's search for a deliberately lossy digit-limited round trip is backend-specific; with GMP, the `found` precondition can legitimately remain false.

**Classification:** `M3-CP4c0-TB-R9-CAND-01` — **ACTIVE / NON-STABLE / TEST-SIDE GMP PORTABILITY**. Runtime evidence does not show a production predicate regression. Independent review must freeze the smallest backend-independent way to construct or assert the intended lossy-round-trip witness before any test edit.

## 5. Candidate R9-02 — the exact-magnitude positive control is a zero-time exit

Ordinal 344 first proves the oversized exact-width case fails closed as intended, then uses `boundary_point(incoming, 1, 2)` as a supposed narrow positive control and expects a `FieldBranchContinuationDecision`.

`resolve_field_branch_continuation` performs the exact magnitude guard and exact minimum-ratio exit calculation, then deliberately returns `BranchContinuationDegenerateEntry` when the winning exact exit time is zero. The positive-control fixture reaches that zero-time branch, so production is following its frozen fail-closed contract rather than violating the magnitude policy.

**Classification:** `M3-CP4c0-TB-R9-CAND-02` — **ACTIVE / NON-STABLE / TEST-SIDE FIXTURE-PRECONDITION**. Independent review must freeze a genuinely narrow ordinary boundary parameter whose exact winning exit time is positive, or prove a product-contract defect before authorizing any other change.

## 6. Accounting and successor boundary

Neither RED is an accepted-behavior regression: the accepted CP4ab prefix remains **316/316**, CP4c-0 has never been accepted, and the failures are currently localized to test-side preconditions. Stable accounting therefore remains **42 events / 14 categories / 28 recurrences** with produced-witness debt **5**. The GMP-linked compile package advances the M3 package count to **48**.

Latest accepted runtime authority remains CP4ab **316/316**. TB-R9 receives valid diagnostic/semantic evidence but **no CP4c-0 acceptance credit**.

**Exact successor:** `M3-CP4c-0-TB-R9-REVIEW-PLAN`, independent Review + Plan only. It must independently adjudicate both candidate classifications and freeze the smallest corrective test/fixture scope if those classifications survive. No runtime, compile, product/test/fixture/selector mutation, TB-R9 rerun, or automatic entry into `M3-CP4c-0b-CB1` is authorized in that review turn.
