# M3-CP4c-3-TB38-EXEC — Artifact-Only Test + Benchmark Execution Report

**Turn:** `M3-CP4c-3-TB38-EXEC`
**Date:** 2026-09-07 UTC
**Scope:** Test + Benchmark EXEC, artifact-only; **benchmarks prohibited and not executed**.
**Semantic source under test:** `2fcde465b1de2e42a348d224f5165ce8b87e4fbe`
**Immutable package:** artifact `10034608071` / `m3-cp4c3-cb43-result-34167182718`
**Selector:** 409 identities, SHA-256 `eea6d8c2bbc8e9247deb4bfbbe6763042c76002d1894dd62e35f80262403b53e`

## Verdict

TB38-EXEC is **mechanically valid artifact-only runtime and semantically RED / REVIEW REQUIRED**. Run `34169783183`
executed all 409 frozen selector identities exactly once through the packaged harness with zero selection mismatch and
zero timeout. Raw aggregate is **395 PASS / 14 RED**, accepted **1–365 = 362/365**, RED
`[356,357,362,366,367,368,369,370,374,390,393,398,406,407]`.

This fails the frozen TB38 hard gate. Relative to TB37, accepted ordinals **356/357/362** and protected ordinals
**390/393/406/407** newly turn RED. Ordinals **312/404/408/409 remain PASS**. Ordinal366 moves from the TB37 Euler
surface to `RegionInteriorDisconnected`; ordinal367 remains `RegionEulerCharacteristicNotOne` but publishes a
*different* torus-region census with `chiFull=0`. Carried 368/369/370/374/398 remain byte-identical to TB37.

The required DEFN-R6.7 accepted-region proof is also **undischarged**: no raw log contains
`M3_CP4AB_FRAGMENT_DIAG record=euler_certificate`, so `accepted-region-euler-certificates.tsv` contains only its
header. The verifier's `accepted_euler_arithmetic_ok=true` is therefore vacuous and is **not evidence of arithmetic
correctness or reduced/full equivalence**.

TB38-EXEC records these raw facts only. It does not assign a corrective implementation, reprice stable regression
history, or promote TB38 as semantic authority. **Independent `M3-CP4c-3-TB38-REV` owns adjudication and planning.**
Current valid semantic runtime authority remains TB37 pending that review.

## Execution provenance and immutable authority

- CB43 compile source: `2fcde465b1de2e42a348d224f5165ce8b87e4fbe`;
- immutable package103: artifact `10034608071`, provider/download SHA-256
  `426622beb03208d2e6b0cc77479942a92f2aca9967e3bf6251f5034ac533008e`;
- packaged source archive SHA-256 `1d4c59d8482ffc240f93119ea04e57541930241a73ff3bb8bdd4154f40fe5a28`;
- packaged harness SHA-256 `aaadab351c0ba28a39c87aff1948f83ab0c4c71520662177e5cdf6fd08b30ed3`;
- selector409 SHA-256 `eea6d8c2bbc8e9247deb4bfbbe6763042c76002d1894dd62e35f80262403b53e`;
- selector408 exact prefix SHA-256 `2a742ba92dba744425fccaf81d5cc7a57885cbff37c779d525218fcd70500af6`;
- test source SHA-256 preflight `913752b8e869b310e2bcb4d0b81a06c4231acdf0470db4427952958de7b3583b`;
- source-snapshot run/artifact `34169322893 / 10035191018` for exact control authority;
- measurement payload commit `54d4ac93d886f2304543450c3f473d40a5ab9268`;
- caller install commit `e6f7751b662678b953acceed5421df3902930c49`;
- execution trigger commit `687e16a5282ca41f1d65722729503cc8d32d594e`;
- workflow run `34169783183`, schema job `101887754558`, execute job `101887783834`, all successful;
- result artifact `10035390901`, SHA-256 `b38ef8ed488e56150599d91542c7a76d034a069b2b726aadaf67e5e43e320a7c`;
- log artifact `10035391184`, SHA-256 `09e8ecf2f9f52b0c30807616116974be0c9ce96e5d57976864442e3217027788`.

`execution-boundary.txt` records `script_exit=0`, `runtime_started=true`, `runtime_completed=true`,
`preflight_completed=true`, `execution_view_verified=true`, `orchestration_failure=false`,
`selection_integrity=true`, `timeout_count=0`; configure/compile/relink/generated discovery/package repair/mode repair/
source-test-fixture-selector mutation/benchmark flags are all false.

Evidence digests:

- ledger SHA-256 `08c0dcd17958806b0b819f7c80604b0e68697d2b959b20928b4f229df8ec7eb6`;
- identity map `f33cd349fd55e962f4bf22918abbccc04c8744205c62ddbe6122d8b50958290f`;
- resource summary `4facd70985569efc35b0824b333d8d8e8e97691fcfdc21a5c85c2af981926394`;
- failure-detail digest table `9e84eb31655cef6cf420daecfaa004a34112580aad852e62912f17c9c61749eb`;
- accepted Euler certificate table `95c1a8fa006ed178f6a020e40c605458b0d747d20458d11c9b0b3a02ad604673`.

Package, source and execution-view byte+mode censuses are identical pre/post. No Directional binary was executed
outside the authorized remote artifact-only workflow. Maximum observed RSS was 18,724 KiB at ordinal147; this is
observational only and no benchmark gate exists.

## Raw semantic delta from TB37

| Surface | TB37 | TB38 raw EXEC |
|---|---|---|
| Aggregate | 402 PASS / 7 RED | **395 PASS / 14 RED** |
| Accepted 1–365 | 365/365 | **362/365**, RED 356/357/362 |
| 312 | PASS | PASS |
| 390/393 | PASS/PASS | **RED/RED** |
| 404 | PASS | PASS |
| 406/407 | PASS/PASS | **RED/RED** |
| 408/409 | PASS/PASS | PASS/PASS |
| 366 | Euler RED | **RegionInteriorDisconnected** |
| 367 | Euler RED, `chiFull=1` | **Euler RED, torus region `chiFull=0`** |
| 368/369/370/374/398 | RED | RED, byte-identical details |

Accepted regressions 356/357/362 have the same failure-detail SHA-256
`d976514dddcc97b35ff68d541be9ead30e53daeb9967232ab939e73bbcf1f55a`. Their torus failure publishes
`RegionEulerCharacteristicNotOne`, boundary orbit 1, arc occurrence/distinct `26/25`, node occurrence/distinct
`26/24`, `B_int=1`, `X=24`, source-submesh boundary `24/24`, `V_total/E_total/F/chiFull=24/48/24/0`, reduced
`V/E/F/chi=0/23/24/0`, and `regionFrontierComponentCount=0`.

Protected 390/393/406/407 all fail the same frozen assertion at
`FieldAlignedCurveNetworkTests.cpp:4364`: `regionFrontierComponentCount > 0`, actual 0. Their failure-detail
SHA-256 is `104512bc90012169377dea766d755bf2eddf3d9c258f5af2dbcadf9743a8227a`.

Ordinal366 now reports `RegionInteriorDisconnected`; it no longer reproduces the TB37 `D=48 / chiFull=1` row.
Ordinal367 reports the same torus Euler detail as 356/357/362 and likewise does not reproduce the TB37 row.
Independent review must decide whether these changed surfaces share one cause, multiple causes, or expose a test/
diagnostic authority issue. EXEC does not decide that question.

## Preserved controls

- selection: 409/409 exactly once, zero mismatch, zero timeout;
- ordinal312 PASS;
- ordinal409 PASS;
- ordinals404/408 PASS;
- ordinal385 retains certified ownership `300 established / 0 unavailable / 0 conflicting`;
- ordinal398 retains `sourceFaceCount=300;ownerMapCount=300;provesCellularity=true`;
- retired `TraceArcDoesNotSeparateItsSides`: absent;
- retired `UncutFaceComponentOrbitSeedNotUnique`: absent;
- 368/369/370/374/398 failure-detail bytes exactly match TB37.

## DEFN-R6.7 proof-obligation status

The frozen plan required every emitted accepted-region `record=euler_certificate` row to prove:

```text
chiReduced = V_int - E_int + F
chiFull = V_total - E_total + F
fullMinusReduced = chiFull - chiReduced
fullMinusReduced = X - E_one - B_int
```

TB38 raw logs emitted **zero** such rows. The generated table therefore has zero data rows. This is not an
arithmetic mismatch; it is an **evidence-emission / test-authority coverage gap** and leaves CZ7.4 runtime discharge
unproved. Independent review owns whether the missing emission is a production diagnostic contract defect, a frozen
plan/test-authority mismatch, or a consequence of earlier rejection before the intended observation site.

## Regression-tracker intake

TB38-EXEC records two non-stable review-pending candidates:

1. `M3-CP4c3-TB38-EXEC-CAND-01` — accepted-prefix and protected-identity regression: accepted 356/357/362 and
   protected 390/393/406/407 were TB37 PASS and are TB38 RED. Raw evidence localizes two exact repeated failure
   byte patterns, but EXEC does not assign root-cause ownership.
2. `M3-CP4c3-TB38-EXEC-CAND-02` — DEFN-R6.7 evidence-emission gap: zero accepted-region Euler certificate rows,
   so the required equivalence proof is undischarged.

Existing 366/367 candidates are updated with raw movement only. 368/369/370/374/398 are exact carried recurrences.
Because semantic adjudication is explicitly deferred to independent review, stable accounting remains
**45 events / 14 categories / 31 recurrences**, debt **5**, packages **103**. TB38-EXEC does not create, merge,
close, or reprice a stable event.

## Exact next boundary

**STOP at independent `M3-CP4c-3-TB38-REV`.** Review must consume the preserved immutable result/log artifacts,
adjudicate the accepted/protected regressions and the missing R6.7 emission, classify movement at 366/367, preserve
or re-own carried RED surfaces only with evidence, update ORIENTATION and durable planning records, and freeze the
successor. It must not compile, run new runtime, or mutate product/test/fixture/selector semantics before review
adjudication.
