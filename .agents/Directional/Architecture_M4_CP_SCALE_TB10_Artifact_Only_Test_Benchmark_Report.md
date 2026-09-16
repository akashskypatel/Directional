# M4-CP-SCALE-TB10 Artifact-Only Test + Benchmark Report

**Disposition:** COMPLETE / MECHANICALLY GREEN / SEMANTICALLY UNADJUDICATED / REVIEW REQUIRED
**Authoritative run/job:** `35135187381 / 104925730218`
**Control/event SHA:** `fcefda49e232676e61a89ad30a020c7f2e8ee0b8`
**Immutable candidate:** artifact `10461816370` / source `2adb7b8169a387fcb6db6487768d7bd3d678265c`
**Frozen selector:** 425 rows / SHA-256 `e0e0f394faae536ac257ec5409653a34755a8afe0ca437562eb44c9895790e0b`
**Mandatory successor:** `M4-CP-SCALE-TB10-REV`

## 1. Boundary and immutable candidate

TB10 executed only the immutable CB11 package. No configure, compile, relink, code generation, chmod, package repair, selector mutation, benchmark execution, discovery, `--list_tests`, help, or version operation was performed.

The candidate package is artifact `10461816370`, provider SHA-256 `93f47702e3919eff0b5503acd7506fbdf661477b6b55b91a0f29fc5a98be2358`, semantic source `2adb7b8169a387fcb6db6487768d7bd3d678265c`, source archive SHA-256 `79ea26c2f9faf9499e33db02c65cba04b47f3a64eeb35b0c4c421fcf45c50afe`, and package-manifest SHA-256 `ef128c01e17db2eebb78e7e92722f732af040d8a6862cda9b24f9e5969ca6dbf` over 28 entries. Preflight reverified all 28 package entries, required executable modes, and direct GMP/GMPXX runtime linkage for the producer binary.

Selector425 remained byte-frozen at SHA-256 `e0e0f394faae536ac257ec5409653a34755a8afe0ca437562eb44c9895790e0b`, exact first424 prefix `f202a1720c0a5288471d04836402b8432eb6f4f788da68a12e70dacb875466ca`, 425 rows, owner census **30 authority-kernel / 279 producer / 75 completion / 41 validation**. No selector426 was published.

## 2. Focused S4 product identity

`M4CPScaleS4.IncrementalTopologyRejectorNeverDisagreesWithFinalDiscCertificate` ran first in one fresh producer-test process and passed **1/1** with exit `0`. Exactly one valid `m4CpScaleS4Product` receipt was emitted.

The negative subject was `V=48,E=48,Fobs=4,c=4,s=1,chi=0`, giving `b1=4`, `Freq=3`, `reject=true`. The known-good positive was `V=72,E=76,Fobs=4,c=1,s=1,chi=0`, giving `b1=5`, `Freq=4`, `reject=false`. The adversarial one-edge implication passed, reversed enumeration was invariant, and the product/reference decision remained neutral.

The receipt records `productCandidateEvaluations=2`, `productEarlyRejects=1`, `productFullCertificationAttempts=1`, `referenceFullCertificationAttempts=2`, and `bypassedFinalCertificationAttempts=1`. Thus the focused execution mechanically demonstrates a real early-bypass event while retaining the reference full-certificate path for the non-rejected candidate. TB10-EXEC records those mechanics only; semantic independence/safety and any promotion decision belong to Review.

## 3. Frozen cumulative selector425

Because the focused identity was GREEN, TB10 executed **425 additional fresh exact-filter processes** in exact selector order. Result: **425/425 PASS**, **0 RED / 0 SKIP / 0 crash / 0 timeout / 0 selection mismatch / 0 unexecuted**, contiguous ordinals 1–425. Passing owners exactly matched the frozen census **30 / 279 / 75 / 41**.

The focused process is separate from those 425 selector processes. Total expected/actual Directional runtime processes were therefore **426 / 426**.

## 4. Immutable postflight

Mandatory postflight reverified the candidate artifact/provider hash, 28-entry package manifest, semantic source archive, selector and prefix hashes. Package, semantic-source, execution-view, and fixture byte+mode censuses matched their pre-runtime counterparts exactly. The evidence records `package_census_equal=true`, `source_census_equal=true`, `execution_view_census_equal=true`, `fixtures_equal=true`, and `postflightComplete=true`.

All prohibited execution flags remain false: configure, compile, relink, code generation, chmod, package repair, selector mutation, benchmark execution, and discovery/list/help/version activity.

## 5. Evidence authority

Authoritative result artifact: `10463670805` (`m4-cp-scale-tb10-result-35135187381`), provider SHA-256 `a74e65ef4040d1889212c31da997f0b629d1279913e5ae358ed4846e587e83f9`.
Authoritative workflow log artifact: `10464360210`, provider SHA-256 `09d2e92e649ec7e4dfd868cedeeb0066fa4443cc54fe39400ecc9592a7a38bea`.

The nested evidence archive SHA-256 is `b17c2956d5e6735098a772465922f4d0d620c1c8ddbbbbe1527800a2bf188133`. Its 1304-entry self-manifest SHA-256 is `b7170097b5e665f7228dc23587ac3abe4e05f8a5e584b22c89b8681d6a22e7cb`; all 1304 manifest entries independently reverified after download.

## 6. Regression/accounting disposition

No RED, SKIP, crash, timeout, selection mismatch, orchestration failure, accepted PASS-to-RED transition, or new regression candidate was observed. Stable accounting therefore remains **49 events / 14 categories / 35 recurrences** and produced-witness debt remains **5**.

Accepted runtime authority remains the TB9 Review promotion — package `10455353524` / source `bebb14e32a0ac53dd420acf46bfa34410cf759a1` / selector425 **425/425** — until `M4-CP-SCALE-TB10-REV` independently adjudicates this candidate. TB10-EXEC grants no package promotion, cumulative S4 credit, selector426 publication, or CP-SCALE closure.

## 7. Mandatory Review boundary

`M4-CP-SCALE-TB10-REV` must independently reopen candidate artifact `10461816370`, result/log artifacts `10463670805 / 10464360210`, nested evidence, semantic source, selector425, and the focused product authority. Review must independently adjudicate the counting-domain derivation, negative/positive/adversarial one-way safety, genuine bypass semantics, decision neutrality, selector425 outcomes/ownership, immutable postflight, and regression disposition before deciding whether any selector426 publication is authorized.
