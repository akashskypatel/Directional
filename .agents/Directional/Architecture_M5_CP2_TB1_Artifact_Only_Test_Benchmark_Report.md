# M5-CP2-TB1 Artifact-Only Test + Benchmark Report

**Turn:** `M5-CP2-TB1-EXEC`
**Disposition:** **COMPLETE / MECHANICALLY GREEN / SEMANTICALLY UNADJUDICATED**
**Candidate:** artifact `10601978228` / source `0798547dedd8be05f9cd7a096b07e6bd94755316`
**Accepted runtime authority after EXEC:** unchanged pending mandatory Review; package `10600353027` / source `8a86710dd33d7b6cb9a077aef738577e4075b5f7` / selector430 **430/430** remains accepted.
**Exact successor:** `M5-CP2-TB1-REV`

## 1. Outcome

The frozen CP2 artifact-only gate is mechanically green. Focused CP2 coverage is **7/7 PASS**, selector430 is **430/430 PASS**, every one of the **437** fresh exact-filter processes selected exactly one test and skipped zero, benchmark execution is **0**, and immutable postflight is exact. The candidate package is runtime-exercised but remains **unpromoted**; semantic acceptance, the accepted-row boundary-relocation adjudication, and CP2 closure are Review-owned.

No semantic RED and no orchestration failure were observed. No retry, rebuild, configure, compile, relink, generated discovery, package/mode repair, benchmark, or source/test/fixture/selector mutation occurred.

## 2. Immutable candidate authority

- compile/package run/job: `35500960779 / 106052541163`;
- candidate artifact: `10601978228`;
- provider/download ZIP SHA-256: `ad2e502db60d94c275769616edf5555d12abd87499c6cf3987cdafbd458d2f0b`;
- exact compiled source: `0798547dedd8be05f9cd7a096b07e6bd94755316`;
- root manifest: **28/28**, SHA-256 `69dc7a8cc5b8fa76b21287a0269edbf98ff0ddf1fc65f3988e4f695055188b54`;
- packaged source archive SHA-256: `32ea6af52c6bc3e9a626dc7cecb3cec67b8ae46fdfbcacd4385ca2392ba5a308`;
- build/preflight exits: **0 / 0**;
- source-status receipts: empty;
- command boundary: `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `exactArithmeticBackend=GMP`, `preflightCompile=true`;
- GMP evidence: `DIRECTIONAL_ENABLE_GMP=ON` with explicit `gmpxx` + `gmp` linkage;
- selector430: **430 LF rows**, SHA-256 `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`;
- first427 prefix SHA-256: `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`;
- routing artifact: `10592987234`, provider/download ZIP SHA-256 `352c8cfc9c9b89cf0d532c8e0836339a31ba35fd6e854a781721cbc76f02afce`, identity-map SHA-256 `7a92e7a3b8a69466423c4a0d2ad5ece2dcd4912f04eeb99e1f32fa70b4a5cf6c`, owners **31 / 283 / 75 / 41**.

Preflight re-derived the seven focused identities from packaged source and verified the independent negative-oracle tokens for missing, duplicate, conflicting, nonreciprocal, and representation-renumbered relation failures. It also verified the accepted tampered-transform identity-preservation discriminator before runtime.

## 3. Execution authority

- authoritative run/job: `35504249045 / 106061268740`;
- event/control SHA: `df4fd2a3ea3cfc1da60a4de69e31a5509a4e54dc`;
- frozen harness SHA-256: `33a94854058f52c07d084591c22d1c277deb9e5bbf190a1669c629114917a8a7`;
- result artifact: `10603438015`, provider/download ZIP SHA-256 `a2b516bd63ea477d22e34631b2714e6c427b92014e86005e605100acaf0657a6`;
- diagnostic artifact: `10603642400`, provider/download ZIP SHA-256 `5ee4edac0b72507522268b825085facdd9ec7cc558168c73e1ba325bd6f824ec`;
- focused ledger SHA-256: `9dcadb661cadff5e1b523877ba96bd00ad6a67cafa3cce00865404f950d9f2ee`;
- selector ledger SHA-256: `2ab6db5febdab40606138739a0b01520f6671061ef9420a240fc7d543a342656`;
- semantic summary SHA-256: `26b6ea33c46305e04c8a5462059accc8182444bf840374a8aae7f784ec80a888`;
- execution-boundary SHA-256: `d2c4d6bd725962669865f53751922df48df292dfa78d1acfe86051d4c08b8947`;
- immutability receipt SHA-256: `1166472dedb2c70bbcbf591c0808ee5d91176cd03f948015d64311e9e8730de7`.

The runtime workflow had no elapsed-time watchdog for the complete gate. It ran from `2026-09-20T10:09:15Z` to `2026-09-20T10:22:03Z`; harness execution completed at `2026-09-20T10:22:01Z` with exit `0`.

## 4. Focused gate

| Ordinal | Identity | Result |
|---:|---|---|
| 1 | `SurfaceCellTransitionQuotient.PeriodicRelationOwnersSurviveContainerReorderingBeforeMaterialization` | **PASS** |
| 2 | `SurfacePhaseFrontProductFactoryAuthority.UnknownPeriodicRelationOwnerRejectsAtCheckedFactory` | **PASS** |
| 3 | `SurfacePhaseFrontProductFactoryAuthority.DuplicatePeriodicRelationIdentityRejectsAtCheckedFactory` | **PASS** |
| 4 | `SurfacePhaseFrontProductFactoryAuthority.ConflictingPeriodicRelationValueRejectsAtCheckedFactory` | **PASS** |
| 5 | `SurfacePhaseFrontProductFactoryAuthority.NonReciprocalPeriodicRelationRejectsAtCheckedFactory` | **PASS** |
| 6 | `SurfacePhaseFrontProductFactoryAuthority.RepresentationRenumberedPeriodicRelationRejectsAtCheckedFactory` | **PASS** |
| 7 | `SurfaceCellTransitionQuotient.TamperedFullPeriodicTransformIsRejected` | **PASS** |

Focused total: **7/7 PASS / 0 RED**. Every process selected exactly one test and skipped zero.

## 5. Accepted selector gate

Selector430: **430/430 PASS / 0 RED**, exact-one selected and zero skipped for all 430 fresh processes. RED ordinals: `[]`.

Benchmark execution count is exactly **0**.

## 6. Immutable postflight and boundary proof

The package root manifest verifies **28/28** both before and after runtime. Candidate-package, packaged-source, and execution-view byte+mode censuses are exactly equal pre/post. Candidate ZIP, packaged source archive, selector430, and routing identity-map hashes are unchanged. The execution boundary records `orchestration_failure=false`, `selection_integrity=true`, `runtime_started=true`, `runtime_completed=true`, and explicitly records no configure, compile, relink, generated discovery, package repair, mode repair, benchmark execution, or source/test/fixture/selector mutation.

## 7. Regression classification and accounting

No semantic regression was observed, so this execution creates **no new regression candidate** and adds **+0 event / +0 category / +0 recurrence**. Stable accounting remains **49 events / 14 categories / 35 recurrences**; produced-witness debt remains **5**. The four M5 production debts remain open because this gate is mechanism/direct-helper evidence and does not satisfy the frozen produced-witness obligations.

`M5-CP2-CB1-OBS-01` remains **CORRECTED / REPORT MAPPING COMPLETE / REVIEW PENDING**. Runtime confirms that accepted row 226 and the focused typed relation matrix are green together, but Review must still independently decide whether moving row 226's rejection from the downstream materializer string to the checked phase-front typed boundary preserves the intended accepted assertion. `M5-CP1-TB1-R3-REV-OBS-01` also remains open: CP1/CP2 authored mechanism identities are still outside selector430 and require a frozen publication sequence before M5 closes.

## 8. Successor boundary

`M5-CP2-TB1-EXEC` is **COMPLETE / MECHANICALLY GREEN / SEMANTICALLY UNADJUDICATED**. Exact next is runtime-free **`M5-CP2-TB1-REV`**. Review must independently reopen the immutable result/log evidence and exact candidate source, verify the seven-row matrix and selector gate, adjudicate `M5-CP2-CB1-OBS-01` including row 226's boundary relocation, decide candidate promotion/CP2 closure, and preserve the selector-publication and production-credit boundaries. No Code + Build work is authorized before Review.
