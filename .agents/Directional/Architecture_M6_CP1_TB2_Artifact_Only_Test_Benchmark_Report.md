# M6-CP1-TB2 Artifact-Only Test + Benchmark Report

**Turn:** `M6-CP1-TB2-EXEC`
**Disposition:** COMPLETE / MECHANICALLY VALID / SEMANTIC NON-GREEN / REVIEW REQUIRED / CANDIDATE UNPROMOTED
**Candidate:** artifact/source `10834642074 / 724316a5b3f49e33dc8e649989bb413b3dc6b7c9`
**Authoritative runtime:** run/job `36063687138 / 107848407035`
**Result/log:** `10835579933 / 10836175636`
**Exact successor:** `M6-CP1-TB2-REV`

## 1. Immutable preflight

TB2 consumed the CB2 package immutably. The provider and downloaded candidate ZIP both verify SHA-256 `754cfeae794da3304b39a572ef6feb6250709f908d5688dcd21f387a071d0cb8`; root `SHA256SUMS` verifies **28/28** at SHA-256 `a0fffc173149d1917ed6ab6a7dbb3c70335dee0b0e4ecb6ce652438d02037c9e`. The packaged source archive verifies SHA-256 `eaf577ccdc534c2e9e48b8b8fed31079849b268c4a6c1b47b0f253ff3ad6034b` and exact source `724316a5b3f49e33dc8e649989bb413b3dc6b7c9`. All five packaged source-status receipts are empty, GMP/GMPXX evidence is present, and the package records `runtimeExecution=false` for its Code + Build origin.

Selector449 is exactly **449 LF rows** at SHA-256 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`; routing449 is SHA-256 `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707` with owner census **32 / 301 / 75 / 41**. All six focused identities resolve to the packaged producer-test executable before runtime. Extraction preserved archived executable modes; no `chmod`, permission repair, configure, compile, relink, discovery, regeneration, fixture/selector mutation, or package repair occurred.

## 2. Mechanical execution

The frozen gate executed exactly **455 fresh exact-filter processes** in the required order: six focused identities, then all 449 selector identities. Every process selected exactly one test and skipped zero. There were **0 crashes, 0 selection mismatches, 0 skips, 0 benchmark processes**, and no acceptance-gate timeout/watchdog.

| phase | total | PASS | RED |
|---|---:|---:|---:|
| focused | 6 | 5 | 1 |
| selector449 | 449 | 448 | 1 |
| **total** | **455** | **453** | **2** |

Focused rows 1-4 PASS. The retained pair-swap identity, `M5CP3.ProducedTorusPeriodicPairStorageSwapPreservesSemanticDirection`, also PASSes in focused row 6. Focused row 5 is RED:

```text
SurfaceCellTransitionQuotient.MultiIsolationMaterializationRetainsAllLocalSheets
SurfaceCellTransitionQuotientTests.cpp:2641
foundMultiIsolationLineage
  Actual: false
Expected: true
```

Selector449 has exactly one RED, ordinal **140** (global process 146):

```text
SurfaceCellAuthorityContractCutover.HardRailPairExplicitRailIdMismatchRejectsStrictTransport
SurfaceCellsPhase10Tests.cpp:6865
Expected: InvalidHardRailTransport
Actual:   OccurrenceUnownedRelation
```

No process reports `OccurrenceInvalidCornerAuthority` anywhere in the complete result evidence.

## 3. Pre-registered classification boundary

The specific TB1 `OccurrenceInvalidCornerAuthority` symptom is absent after CB2, and the previously unclean pair-swap identity is now green. However, the frozen TB2 recovery criterion requires both zero `OccurrenceInvalidCornerAuthority` **and selector449 449/449**. Selector449 is 448/449, so EXEC does not claim formal recovery of `M6-CP1-TB1-EXEC-CAND-01` and does not promote the candidate.

The two remaining REDs have first-failure surfaces different from `OccurrenceInvalidCornerAuthority` and are therefore preserved as **new non-stable candidates for mandatory Review**:

- `M6-CP1-TB2-EXEC-CAND-01`: accepted selector449 row140 transitions from accepted PASS to candidate RED with `OccurrenceUnownedRelation` where the existing assertion expects `InvalidHardRailTransport`. This is an accepted-prefix candidate, but EXEC does not assign a stable category or root cause.
- `M6-CP1-TB2-EXEC-CAND-02`: focused-only multi-isolation lineage witness is false. This has no accepted-prefix stable-accounting effect by itself; exact interpretation is Review-owned.

Stable accounting therefore remains **52 events / 15 categories / 37 recurrences** pending Review. Produced-witness debt remains **1**, M6-owned. Accepted runtime authority remains M5 package/source `10814505512 / e284fea7c101eb86650d1c87c92d0fefa66050e7` under selector449 **449/449 PASS**. Candidate `10834642074` receives no promotion, CP1 closure, or G4/debt credit in EXEC.

## 4. Evidence integrity

Result artifact `10835579933` has provider/download SHA-256 `c42a5b2e2026a1fb59a6692ae615c9f7eacba8c1ef59fc49bace5d0e9360d06b`. Its self-excluding manifest verifies **933/933** files and hashes to `647fbe0b76e3f7754aef36ff47e976b6892cf3e9fc73dada2b80c46a5673cb27`. Execution-ledger SHA-256 is `c0edfd0e1c169364634aec96989e227d000a630465ca9bb779804c3c993988ff`; RED-ledger SHA-256 is `cc5ccbe467e561bc22bc2370bd5db6b2166b99b6697bcbb8bf93a745726258a8`.

Diagnostic log artifact `10836175636` has provider/download SHA-256 `254b7f16dc8de29df74165c3c0c27a6b31107dfd26b4d9fd9e86fd9e692639f2`.

Postflight proves package/source/execution-view byte-and-mode censuses unchanged, pre/post hash inventories equal, selector/routing/source archive unchanged, and root package manifest still **28/28**. `execution-boundary.txt` records `orchestration_failure=false`, `selection_integrity=true`, all 455 processes executed, and every prohibited mutation/build/benchmark counter false.

## 5. Stop rule and disposition

TB2 stopped after the one mechanically valid 455-process result. No semantic result was rerun. No source, test, fixture, selector, routing, package, build, or benchmark logic was changed. No candidate was promoted and no corrective implementation plan is authorized by EXEC.

Exact successor is mandatory runtime-free **`M6-CP1-TB2-REV`**. Review must independently re-open candidate package/result/log evidence, adjudicate the formal disposition of TB1 CAND-01 and the two new TB2 candidates, update stable accounting only if justified, and decide the next CP1 turn.
