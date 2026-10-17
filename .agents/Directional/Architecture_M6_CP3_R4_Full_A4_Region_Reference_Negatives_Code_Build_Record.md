# M6 CP3 R4 — complete A4 source authority for region-reference negatives (Code + Build)

Canonical turn: `M6-CP3-CB1-ENTRY-R4` **IN_PROGRESS**. No authorized Test + Benchmark successor; PR #8 remains draft/unmerged.

## Source problem and exact correction

Existing `SurfaceCellAuthorityContractCutover.ConflictingCellRegionFailsBeforeMaterialization` and `SurfaceCellAuthorityContractCutover.ConflictingEdgeRegionFailsBeforeMaterialization` used `SurfacePhaseFrontProduct::make` with the required early arguments but omitted the producer's optional conformity receipt, hard features, source-face branch rotations, hard-rail transitions/routes, terminal contact map, and closed chains. Consequently a missing optional A2b/A3/A4 input could reject before the intended exact `InvalidCellRegion` / `InvalidEdgeRegion` guard, rendering the asserted first failure non-causal.

In `tests/SurfaceCellsPhase10Tests.cpp`, add `rebuild_checked_region_reference_product` which copies the complete product authority and accepts the altered edge/cell vector. Construct the independently source-owned A3 atlas from the original `TriMesh`, `CrossFieldResult`, and produced `hardFeatureEdges` (not default-empty). Both original test identities now require a successful **unmodified** checked-A4 round-trip before changing exactly one source region reference, then continue to require the original typed negative code. No weakening of factory predicates, no selector/name changes and no production-code changes.

## Immutable source and evidence

- Verified exact-source snapshot workflow `38101900925`, job `114359410269`, trigger/source SHA `10634c1a99b11053274edadc1afd93f2114d65fe`, artifact `11687514214`, ZIP SHA-256 `2816258253bea24dbb790e20bea71a4a72b72f12d5035376fb5e1a064a9a44b4`; `source.tar.gz` SHA-256 `03c938396120af60ca5c45166a1a599aa027efafa288be614d2f981a1190bf6a`; 6044/6044 source hashes verified, runtimeExecution=false.
- One-file patch base `a405877cb8baf290df7828535bd7da19bca626bb`, patch SHA-256 `79a6c5e63e45cc952685dd8ea89d26456e3159f0ec5cb510ae3404b0d55af86c`, diff-body SHA-256 `6ba0490035910d30e8c6ec68394266839287096adfe043f012eba47c1fc50748`. Exact patch backed up to ChatGPT Library `/Directional/Evidence/`.
- Drive apply workflow `38102136461`, job `114360116612`, result artifact `11688157178` (`a65fa162378dcdf6ed432aa70ddc9b5c184e19a7b51d41e33774b3e84a9d75fe`), diagnostic artifact `11688062330` (`95d7dbe7cb3409604627b2612316e6f07fd04bc152403d032b768e38c18f5cde`). Exact applied semantic source `e200af8b0e2984ae6a452df9fd8520016043cc7d`, push passed and temporary Drive File ID `1iq18qkHEN_EdXkrlRLKmeqEvxkaHLoV2` owner-deleted.
- **Mandatory eight-target GMP/GMPXX compile GREEN:** dispatcher workflow `38102239838`, compile job `114360426650`, exact semantic source `e200af8b0e2984ae6a452df9fd8520016043cc7d`. Preflight and build exit codes `0/0`; `DIRECTIONAL_ENABLE_GMP=ON`; both `libgmpxx` and `libgmp` verified linked, `exactArithmeticBackend=GMP`; all eight requested targets built, 28/28 recursive package manifest checks verified and final source clean. Result artifact `11688525324`, outer ZIP SHA-256 `509da9e590f598bf262b63e55bd2d10ef59d94e47579d5cbbab3c0cf22aff634`; diagnostic artifact `11687754449`, ZIP SHA-256 `812a2a2fea38cf70d9c60a1b88b1c7dc9b466701e17eec1065567c719d75fa0f`; `runtimeExecution=false`.

## Scope and unresolved obligations

**No tests, benchmarks, discovery, generated executables, or frozen selectors were run.** Compile-only correctness does not prove either expected negative is reached first; they remain runtime-unverified. R4 must still address genuine multi-carrier/odd-τ source witnesses, 39 carried endpoint, 34 Phase10 positive, seven DCEL negative, 88 accepted CP2-regression paths, and independent design adjudication for a purported second nonhard admissible path in a cut two-manifold vertex star. The 497-case frozen gate is not authorized during Code + Build. Do not advance successor until R4 formally completes.
