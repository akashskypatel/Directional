# M6-CP1-TB3 Artifact-Only Test + Benchmark Report

**Turn:** `M6-CP1-TB3-EXEC`
**Disposition:** COMPLETE / MECHANICALLY VALID / SEMANTIC NON-GREEN / REVIEW REQUIRED / CANDIDATE UNPROMOTED
**Candidate:** artifact/source `10840014758 / 660015f2f15359fd426e2c855aea9f4201c70216`
**Authoritative runtime:** run/job `36084948588 / 107914657100`
**Result/log:** `10844285398 / 10844020833`
**Exact successor:** `M6-CP1-TB3-REV`

## 1. Immutable preflight

TB3 consumed the CB3 package immutably. The provider and downloaded candidate ZIP both verify SHA-256 `b1117c6efe2cdc8a04e46647fd1bb5af79094234a03348df8ffd6e6ae5ed5c66`; root `SHA256SUMS` verifies **28/28** before and after runtime. The packaged source archive verifies SHA-256 `90c6305132ceca1bcd5f12dfd03a7a3b818fe3e9462128dedb5c3f5788f67ecc` and exact source `660015f2f15359fd426e2c855aea9f4201c70216`. All packaged source-status receipts are empty, GMP/GMPXX evidence is present, and the package records `runtimeExecution=false` for its Code + Build origin.

Selector449 is exactly **449 LF rows** at SHA-256 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`; routing449 is SHA-256 `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707` with owner census **32 / 301 / 75 / 41**. All six focused identities resolve to the packaged producer-test executable. Extraction preserved archived executable modes; no `chmod`, permission repair, configure, compile, relink, generated discovery, source/test/fixture/selector mutation, package repair, or benchmark execution occurred.

## 2. Mechanical execution

The frozen gate executed exactly **455 fresh exact-filter processes** in the required order: six focused identities followed by all 449 selector identities. Every process selected exactly one test and skipped zero. There were **0 selection mismatches, 0 skips, 0 benchmark processes**, and no acceptance-gate timeout/watchdog.

| phase | total | PASS | RED |
|---|---:|---:|---:|
| focused | 6 | 4 | 2 |
| selector449 | 449 | 443 | 6 |
| **total** | **455** | **447** | **8** |

Focused rows 1-4 PASS. Focused rows 5-6 both stop at `MissingIsolationSeamEquivalenceAuthority` before their downstream assertions:

- `SurfaceCellTransitionQuotient.MultiIsolationMaterializationRetainsAllLocalSheets`
- `M5CP3.ProducedTorusPeriodicPairStorageSwapPreservesSemanticDirection`

Selector449 REDs are exactly ordinals **186, 214, 239, 444, 446, 448**. Each also stops at `MissingIsolationSeamEquivalenceAuthority`:

- 186 `SurfaceCellIsolationSeamCertificateAuthority.ReciprocalIsolationSeamCertificateMaterializes`
- 214 `SurfaceCellTransitionQuotient.ComponentTypedAuthorityDomainComesFromPublishedSourceAuthority`
- 239 `SurfaceCellsPhase10.ExactReciprocalTransportCrossesSourceAdjacentIsolationSeam`
- 444 `M5CP3.ProducedTorusPeriodicRelationStoragePermutationPreservesSelectedCertificate`
- 446 `M5CP3.ProducedTorusNonzeroZ4RotationTranslationMaterializes`
- 448 `M5CP3.ProducedTorusUnusedValidRelationDoesNotAlterSelectedCertificate`

Selector449 ordinal **140** now PASSes through its accepted `InvalidHardRailTransport` contract. No process reports `OccurrenceInvalidCornerAuthority` anywhere in the complete raw evidence.

## 3. Regression classification boundary

TB3 proves the CB3 HardRail precedence correction at row140, but the candidate is not recovery-green. The multi-isolation focused identity does not reach its former `foundMultiIsolationLineage=false` assertion; it now stops earlier at `MissingIsolationSeamEquivalenceAuthority`. The retained pair-swap identity, which PASSed in TB2, stops at the same earlier failure. Six accepted selector449 identities also move from accepted PASS to the same failure.

Static source bounds the common activation chain without adjudicating its final ownership: CB3 changes occurrence `isolationSheet` authority to the authoritative outgoing directed-side start. In `RemeshPipeline.cpp`, a relation whose resolved occurrence endpoints now span different sheets requires non-empty relation-owned `equivalence.isolationSeams`; otherwise the materializer returns `MissingIsolationSeamEquivalenceAuthority`. CB3 deliberately removed certificate-inventory seam augmentation, so certificate presence alone does not satisfy this relation-owned equivalence requirement. All eight TB3 REDs terminate at that same guard.

This is recorded as **`M6-CP1-TB3-EXEC-CAND-01`**, one non-stable Review-owned candidate family covering the six accepted-selector losses plus the two focused losses. EXEC does not decide whether the correct disposition is implementation regression, missing test/fixture relation-equivalence authority, or a definition/producer-contract conflict. Stable accounting therefore remains **53 events / 16 categories / 37 recurrences** pending mandatory Review; produced-witness debt remains **1**, M6-owned.

The TB1 `OccurrenceInvalidCornerAuthority` symptom remains absent, but its pre-registered formal recovery rule requires selector449 **449/449**. TB3 is 443/449, so EXEC does not close `M6-CP1-TB1-EXEC-CAND-01`. Candidate `10840014758` remains unpromoted and receives no CP1 closure, G4/debt credit, or accepted-runtime authority.

## 4. Evidence integrity

Result artifact `10844285398` has provider/download SHA-256 `f1eeae6399c8f8560be24c18b4ba65e26da528dda993e41c80356c185538901b`. Its self-excluding `SHA256SUMS` verifies **929/929** evidence files and hashes to `e0072696b647e4a19b65ff186a71238f46a57d9df178a00e8ee54a7013aa9dce`. Focused-ledger SHA-256 is `7e4060319a48b0eb69859b1721a0883d705990dd8c799f8fab8959461bb403a7`; selector-ledger SHA-256 is `811fad03da881b9a0b9d06aa1c9904e4994ab0bc1283b9248beba15385dadc7`.

Diagnostic log artifact `10844020833` has provider/download SHA-256 `c3c99a9dc4ce5d32074f4bd66338a23cdcce5ffc094fbcd75035c1f2e60bb2f9`.

Postflight proves package/source/execution-view byte-and-mode censuses unchanged, candidate ZIP/source archive/selector/routing unchanged, and root package manifest still **28/28**. `execution-boundary.txt` records `runtime_started=true`, `runtime_completed=true`, `orchestration_failure=false`, `selection_integrity=true`, all 455 processes executed, and every prohibited build/mutation/benchmark flag false.

## 5. Stop rule and disposition

TB3 stopped after the one mechanically valid 455-process result. No semantic result was rerun. No source, test, fixture, selector, routing, package, build, or benchmark logic was changed. No candidate was promoted and no corrective implementation is authorized by EXEC.

Exact successor is mandatory runtime-free **`M6-CP1-TB3-REV`**. Review must independently reopen candidate package/result/log evidence, adjudicate `M6-CP1-TB3-EXEC-CAND-01`, determine the formal status of the prior TB1/TB2 candidates, and update stable accounting only if independently justified.
