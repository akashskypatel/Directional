# `M6-CP1-CB12-CLOSE-R1` — CP1 Close-Out Code + Build Report

**Disposition:** COMPLETE / COMPILE+PACKAGE GREEN / RUNTIME-FREE / UNPROMOTED CANDIDATE.

This R1 executes the reviewed CB12 close-out plan after `M6-CP1-CB12-CLOSE-REV` discharged C5 under RA-26. C1–C4 and focused identities 29/30 are implemented. C5 is satisfied exclusively by `Architecture_M6_CP1_CB12_Close_Stop_Review_Record.md` §3; this turn made **no** optimizer or final-validator change.

## Source and implementation authority

- Source snapshot used for implementation: `24f8db391284d5731ec7a2c67a26c56e9cfc0294`.
- C1–C4 implementation commit: `1b3944e87001fb915cdedcd708bdab6b50dd20b8`.
- Bounded compile correction commit: `02149f1518fc6a753acf3235f7dcdc6fcdf59f24`.
- Final compile/package source: `02149f1518fc6a753acf3235f7dcdc6fcdf59f24`.
- Focused-30 SHA-256: `1e815443a03c7ef4a1b095e6ea973efa9c74bb0eae4e2f872510c97d057ea1d6`; focused-28 SHA-256 remains `9154a986ce005c53f99faad3551989b05516abe9e4fd02dce585a645d70a011d` and is its exact prefix.
- Selector449 remains byte-frozen at `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`.

## Implemented goals

### C1 — exact A7 cross-sheet certification

A selected cross-sheet A7 binding now requires a `CornerWedgeIsolationTransition` whose endpoint sheets actually connect the two occurrence `cornerWedgeSheets` sets. Mere existence of unrelated isolation evidence is no longer sufficient. Failure remains typed as `UncertifiedCrossSheetBinding` at `cross-sheet`.

### C2 — distinct A5 source diagnostics

A5 now preserves three distinct failure causes through the adapter:
- empty phase-front cells **or edges** → `MissingAuthoritativePhaseFront`;
- source shape/face-count mismatch → `InvalidAuthoritativePhaseFrontSource`;
- unavailable source-chart transitions → `InvalidAuthoritativeSourceChartTransitions`.

The empty-edge predicate was restored to the first missing-front check as required by RA-19a.

### C3 — A5-owned validated isolation count

`SurfaceOccurrenceComplexCertificate` now publishes `validatedIsolationCertificateCount` from the A5-validated certificate set. `AuthoritativePhaseFrontMeshResult::consumedInternalIsolationSeams` projects that A5 value rather than recounting raw phase-front transport certificates. Identity 24 was updated to assert the A5-owned value.

### C4 — RA-25 fail-closed strip continuation

At an interior valence-4 quotient vertex, zero or multiple opposite continuation edges now fail closed with `ClosedComplexStripContinuationMismatch`; the prior silent skip is removed. No other RA-24 strip semantics were changed.

### C5 — discharged by RA-26

Per `Architecture_M6_CP1_CB12_Close_Stop_Review_Record.md` §3, no authority-deciding provenance-face consumer exists. The previously flagged optimizer site is test-only overlay code and not a provenance-face authority consumer. Reference-selecting permutation concerns remain re-homed to `M6-DEFN-R5` / `M6-CP3`. This R1 therefore made no `SurfaceMeshOptimizer` or final-validation change.

## Focused identities

29. `M6CP1.A7CrossSheetBindingRequiresConnectingIsolationTransition`
30. `M6CP1.A5PhaseFrontSourceFailuresKeepDistinctDiagnostics`

`Architecture_M6_CP1_Required_Green_Focused_30.txt` appends exactly these two identities after the frozen focused-28 prefix.

## Compile/package evidence

The first compile-only attempt, run `37259162318`, reached compilation and exposed one bounded source error at `RemeshPipeline.cpp:7588`: pointer `occurrenceComplex` was accessed as `occurrenceComplex.certificate()` instead of `occurrenceComplex->certificate()`. No Directional runtime executed. The same Code + Build turn corrected only that member access and recompiled.

Authoritative retry:
- run/job: `37259524323 / 111603703243`;
- exact source: `02149f1518fc6a753acf3235f7dcdc6fcdf59f24`;
- result artifact: `11324028392`, outer SHA-256 `4e6b208acd328036d849a8d71f12804a6d9e6a34d804e3129953ce7a7e3afba1`;
- log artifact: `11323679468`, outer SHA-256 `82adb1a6c2b87838503c339abdf00b2a9ed03951c85cb5a5e98fad71380c7766`;
- package `SHA256SUMS`: **28/28** verified;
- package manifest SHA-256: `1527cabe67a4d09c8cabd8b117ba0c50d46750554bad6aa247afd2b8675a3e06`;
- source archive SHA-256: `0cd4dc2eaa2778bdc906e06cf854d7b84f5082877fd45e5c99c5c830722e6a5a`;
- preflight exit `0`; build exit `0`; final source status clean;
- mandatory GMP/GMPXX link evidence present;
- all eight standard targets compiled and linked;
- `runtimeExecution=false`.

No generated Directional binary, test, benchmark, discovery/list/help/version command, CLI, `ctest`, fuzzer, or custom input was executed.

## Boundary and successor

This Code + Build turn does **not** claim runtime acceptance or CP1 closure. Stable accounting remains **60 events / 16 categories / 44 recurrences**, debt **1**; no new runtime regression event exists.

Exact successor is immutable artifact-only **`M6-CP1-TB12-CLOSE-EXEC`** over candidate `11324028392 / 02149f1518fc6a753acf3235f7dcdc6fcdf59f24`: focused-30 + selector449 = **479** fresh exact-filter processes, followed by mandatory `M6-CP1-TB12-CLOSE-REV`, then `M6-CP1-CLOSE-REV`.
