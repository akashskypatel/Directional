# `M6-CP2-CB1-VERIFIER-R1` — Independent Verifier Code + Build Report

**Disposition:** COMPLETE / COMPILE+PACKAGE GREEN / RUNTIME-FREE / UNPROMOTED CANDIDATE.

This R1 executes the RA-28b-amended verifier plan after `M6-CP2-CB1-VERIFIER-REV` discharged the RA-28a §7 stop. RA-28a §7 remains withdrawn: this turn made **no `SurfaceMeshOptimizer` source change** and retained identity 12 as the RA-28b representative-scope confinement falsifier.

## Source and implementation authority

- Verified implementation snapshot/base: `09ab05dfb34fc4a1f6ae052ef78f2a3ceaae0739` (source-snapshot run/artifact `37347675976 / 11361745113`).
- Applied verifier patch SHA-256: `6d0c4c4083e095c1f87dab341657b42b4d14413459fe1f37c6cf128a6d4dda20`; diff-body SHA-256 `b1732051ad33251cf7c3a6f5101276f8e3c6ae8a16f51a99c2ff406c94ba4e82`.
- Semantic implementation commit: `3cc00697eecc8e20570298653ea7cf8a3887f045`.
- Bounded compile correction commit: `265c8fbb19a66c5c3344a525fdbd43932c3ef829`.
- Final compile/package source: `265c8fbb19a66c5c3344a525fdbd43932c3ef829`.
- Binding authority: RA-28 + RA-28a §1–§6 and §8–§9 + RA-28b; RA-28a §7 is withdrawn.

## Implemented goals

1. A5/A6/A7 publish copy-by-value verification record views; no unchecked production product factory was added.
2. `SurfaceProductVerifier` independently recomputes the frozen A0/A5/A6/A7 predicates with typed, deterministic semantic findings and dependency-gated partitions.
3. A5→A6 and A7→A6/A5 certificate-chain binding is exact: relation ownership is exact-once, Joining relations form the published spanning forest, cycle-closing transport closes strictly, and payload fields bind to their published upstream records.
4. A5 wedge/sheet/seam/support incidence is rechecked against A0; A6 membership/topology/manifoldness and A7 support/certificate payloads are rechecked without repair/search/substitution.
5. `VerifiedSurfaceProducts` is the production type barrier. The verifier stage runs after successful A7 and before adapter projection; verifier failure maps to `VerificationFailed:<code>:<site>`.
6. The three D3 wedge tampers and the independent weld-pinched record-view manifoldness witness are present.
7. `Architecture_M6_CP2_Required_Green_Focused_12.txt` contains exactly the 12 frozen CP2 identities. Identity 12 is `M6CP2.AuthoritativeOptimizerProjectionStaysOnRepresentativeScope`; no optimizer production code changed.

## Static authority checks

- `git diff --check` passed for the implementation candidate.
- selector449 remains byte-frozen at SHA-256 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`.
- focused-30 remained unchanged and was not copied into CP2 focused-12.
- CP2 focused-12 contains exactly 12 identities in frozen order.
- No `SurfaceMeshOptimizer` source hunk from the exploratory WIP was applied.
- The verifier implementation does not invoke producer search/repair/canonicalization/fallback routines.

## Patch-transport evidence

The first Drive-apply attempt (`37354014826`) verified the patch bytes/base/body, applied cleanly, and created the intended local commit, but its push lost a non-fast-forward race because this agent advanced the same branch with an unnecessary recent-runs observer while the apply job was active. This was an orchestration error, not a semantic failure; no force-push was used.

The unchanged patch then applied successfully after branch writes settled:
- run/job: `37355062298 / 111915359845`;
- result artifact: `11363424488`, provider SHA-256 `ab0fbfe0042c59f785ea85dc4236db44bc9e2a7d4d55d80acf97934e87cba7aa`;
- log artifact: `11364421947`, provider SHA-256 `c6b21954f57379f296dd9782cf6c5bc6eb9f2f91541c3fee71cc9bec33a5cdb5`;
- resulting semantic commit: `3cc00697eecc8e20570298653ea7cf8a3887f045`;
- `runtimeExecution=false`.

The consumed Drive file was permanently retired from the owner-authorized Drive control plane after successful application.

## Compile/package evidence

The first compile-only attempt, run `37357362493` / job `111923137508`, reached the producer-test target and exposed one bounded test-source compile error in the new RA-28b confinement identity: `DomainResult<SourceFaceId>` was dereferenced with `operator*`. No Directional runtime executed. The same Code + Build turn corrected only those two test accesses to `.value()` in commit `265c8fbb19a66c5c3344a525fdbd43932c3ef829` and recompiled.

Authoritative retry:
- run/job: `37358279504 / 111926243775`;
- exact source: `265c8fbb19a66c5c3344a525fdbd43932c3ef829`;
- result artifact: `11365308211`, provider SHA-256 `3065e58741b1354e1f94ca04cc6169f0458aa11247443e77fb2914e55fa7b35e`;
- log artifact: `11365537617`, provider SHA-256 `9c0336eea0cb29436249edaa419723ba1145750b736766287cb13aae8086ad6b`;
- package `SHA256SUMS`: **28/28** verified; self-excluding manifest SHA-256 `a9157f0f6ff391abb2ff37e462b5f71f28c6ce8d01da8fa2171271397ee43504`;
- source archive: `source/source-265c8fbb19a66c5c3344a525fdbd43932c3ef829.tar.gz`, SHA-256 `ad9f635c129d5d03fa9505184dda9071526afcae263b8d3cbdad1c9d01a5cb1a`;
- preflight exit `0`; build exit `0`; final source status clean;
- all eight standard targets compiled and linked;
- `DIRECTIONAL_ENABLE_GMP=ON`; authoritative link evidence contains both `libgmpxx.so` and `libgmp.so`; `exactArithmeticBackend=GMP`;
- `runtimeExecution=false`.

Compiled targets: `directional_core`, `directional_pipeline`, `directional_surface_cell_authority_kernel_tests`, `directional_surface_cell_producer_tests`, `directional_surface_cell_completion_tests`, `directional_surface_cell_validation_tests`, `directional_compiled_api_tests`, `directional_benchmarks`.

No generated Directional binary, test, benchmark, discovery/list/help/version command, CLI, `ctest`, fuzzer or custom input was executed.

## Boundary and successor

This Code + Build turn establishes compile-valid candidate authority only. It does **not** claim runtime acceptance or CP2 closure. The previously reviewed runtime remains `11330703256 / 3f40f04a0e9d382b2ec82cf37a03c18ad405eb05` at 479/479 until the CP2 candidate passes Test + Benchmark and mandatory Review.

Stable accounting remains **60 events / 16 categories / 44 recurrences**, debt **1**. The compile-only `DomainResult` typo is not a runtime regression event and does not reprice accounting.

Exact successor is immutable artifact-only **`M6-CP2-TB1-VERIFIER-EXEC`** over candidate `11365308211 / 265c8fbb19a66c5c3344a525fdbd43932c3ef829`: focused-30 + CP2-focused12 + selector449 = **491** fresh exact-filter processes, followed by mandatory **`M6-CP2-TB1-VERIFIER-REV`**. `M6-DEFN-R5` remains after CP2; `G4-B002` debt remains open.
