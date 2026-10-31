# CB38 selector-250 rail authority — independent static review (2026-10-25)

**Turn:** `M6-CP3-CB38-RP01-SELECTOR250-RAIL-AUTHORITY-REV`.
**Verdict:** ACCEPT the RA-156.3 test-only correction for the purpose of a separately executed TB40. This is *source and compile acceptance only*. Selector 250 has not passed at runtime; CP3, selector497 and any direct-product claim remain unpromoted.

## Re-derived evidence

- Inspected the exact GitHub [CB38 commit](https://github.com/akashskypatel/Directional/commit/41f39ba920eace2dad7b36d2b26c8073ce740239), not just the CB38 report. Its only changed file is `tests/SurfaceCellsPhase10Tests.cpp`, one hunk at `PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`, **50 insertions / 0 deletions**. The eight original hard-edge insertions, original Produced assertion and its CB37 failure stream, later assertions, production paths, fixtures, selector and workflows are unmodified by that commit.
- Independently downloaded [CB38 GMP compile artifact](https://github.com/akashskypatel/Directional/actions/runs/40232132945) `12613073521`. Outer ZIP SHA-256 `ca7358b7de3ff7ce5bc234f69c2b06036a7a5681f96d9a2d6c9e7cd298797ab3`; **28/28** manifest entries match. `metadata/source-commit.txt` equals `41f39ba920eace2dad7b36d2b26c8073ce740239`. Preflight and build exit codes are `0`; eight required compile targets are listed; CMake has `DIRECTIONAL_ENABLE_GMP=ON` and actual link evidence names both `libgmpxx.so` and `libgmp.so`. All five packaged source-status files are empty. Boundary is `runtimeExecution=false`; neither tests nor benchmarks were executed here.
- Verified exact current source snapshot `01d3fce034e7cdb154cbe0cca3b393aaf956b59c` via [run 40233987460](https://github.com/akashskypatel/Directional/actions/runs/40233987460), artifact `12613992683`, ZIP SHA-256 `7a2683c61c9ef44cd9fb48bacbd2e2aae9fa3e6658a5b7424bed899e0dfb0a51`, **5,890/5,890** file hashes and source-archive SHA-256. The packaged CB38 test source is byte-identical to this snapshot's test source; the newer snapshot's control-plane docs/STATUS do not assert runtime behavior.
- Independently enumerated the 3x3 curved-disk fixture triangulation: eight faces, ring `0,1,2,5,8,7,6,3,0` with eight unique source-boundary edges, exactly one incident source face on each. The composed test offsets every disk vertex by `planeVertices+cylinderVertices`, puts disk faces after plane/cylinder faces, and assigns all disk source faces component/sheet `2`. The production `build_authoritative_surface_cell_rails` recomputes source-face connectivity from ascending face order; thus the disk is source component `2`, and the newly constructed feature-map Hard ring has matching component and face support. Its builder must produce one closed HardFeature rail or the test fails before the producer call.
- The test calls the **production** `build_authoritative_surface_cell_rails`, then `hard_rail_source_provenance_from_rails`, and installs all four fields: `authoritativeRails`, `hardRailTerminalContacts`, `hardRailClosedChains`, `hardRailOpenChains`. It explicitly rejects an absent closed chain or `hard_feature_edge_keys_from_rails(...) != hardFeatureEdges`. This fixes the missing authority class identified in RA-156 J1 rather than injecting a dummy contact that bypasses validation.
- Non-vacuity: the new preconditions reject missing/incomplete/incorrect rail authority before `build_phase10_with_source_atlas`; the existing Produced assertion and later three-sheet/periodic-holonomy checks remain capable of failing. This is not proof those later checks will pass; TB40 must measure the real first failure.
- Independently re-hashed accepted selector449: `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414` (449 entries). Re-hashed frozen TB38 case manifest: `b27eecb6b4f6f32fd060b8510a0cabf71f86b8fe1028dbb10c36003867dcf8c2`. No selector source was modified by this review.

## Frozen successor — TB40

**Next:** `M6-CP3-TB40-RP01-SELECTOR250-RAIL-AUTHORITY-VERIFY` (artifact-only Test + Benchmark). The exact **13-row** manifest `Architecture_M6_CP3_TB40_Selector250_Rail_Authority_Verification_Case_Manifest.tsv` has SHA-256 `5dd7d9499918b04a277b907835993beb7829e6d9f52c4cc345faf5e3cd2158e4` (LF). Row 1 is `selector:250`, kind/expect **RED/RED**: a PASS is recorded as `unexpected_pass`, the actual positive success signal, not quietly converted to ordinary expected PASS. GUARD/PASS: selector rows 199, 235, 236, 249, 251, 252; the three independently specified TB36 quarter-turn, half-turn and directed-route witnesses; selector rows 193, 194, 195. Exact names resolve from TB38/TB39 verified case manifests. The existing immutable harness is unchanged.

**Falsifiers:** 250 still rejects `hard-rail-contact-missing`; a different first rejection; a case that fails its historical GUARD assertion; wrong result cardinality/identity; mismatch of source-package/selector/manifest digests; rebuilt/relinked or mutated source; missing GMP evidence; or any postflight/hash failure. Collect unmodified raw logs even when 250 RED. A PASS of 250 is candidate discharge only, not CP3 promotion; a RED requires TB40-REV to bind one new first-failure owner. Stop without repair or rerun-with-edits inside TB40.

**Carried:** O1 (periodic route), O2 (legacy/seam), O3 (polygonal rejection site to CB42), RA-152.5, DEFN-SEAM-NZ, RA-146.2/4, RA-45.4, G4-B002, DIAG-RETAIN, and the subsequent CB39-A/CB40-B/CB41-C/CB42-O3 test-authority turns. None is discharged by compile-only evidence. Stable 66 events / 17 categories / 49 recurrences, debt 1; CP2 accepted 491/491; TB32 candidate 481/500, TB38 candidate 490/504; selector497 frozen; RP-01 open, RP-02 unreached.

Both consumed Drive patches were deleted (404 readback), and the temporary history workflow and trigger were retired. No runtime tests were run.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | 449 entries, `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5f84bd88d6414`; no new accepted selector |
| Decisive claims independently re-derived | Exact CB38 one-file hunk, source/package SHA equality, 28/28 package and 5,890/5,890 snapshot file hashes; disk 8-edge boundary support; production rail/provenance calls |
| Non-vacuity checked | Changed preconditions can reject malformed rails; unchanged Produced and three-sheet/holonomy assertions can fail; no runtime credit |
| Prior obligations discharged/carried | RA-156 J1/J2 static correction accepted; O1/O2/O3, RA-152.5, DEFN-SEAM-NZ, RA-146.2/4, RA-45.4, G4-B002 and DIAG-RETAIN retained |
| Stable accounting | 66 / 17 / 49, debt 1; CP2 491/491; TB38 490/504 candidate; selector497 frozen |
| New candidates/obligations recorded | None created; TB40 outcome remains open |
| ORIENTATION currency line | Updated for CB38-REV, 2026-10-25 |
| ORIENTATION §3 / §4 / §7 / §8 | §3, §7 updated to TB40; §4 n/a: no witness measured; §8 n/a: no new defect pattern |
| CHANGELOG | One CB38-REV entry added |
| ROADMAP | n/a: M6-CP3 still open and milestone states unchanged |
| Selector manifest | n/a: TB40 is an unexecuted case manifest, not an accepted required-green selector |
| LESSONS | Existing evidence/acceptance and independent-oracle sections apply; no genuinely new pattern |
| Consolidation under CLEAN_UP_POLICY | No load-bearing superseded CB38 document deleted; CB38 record retained as immutable current compile authority; existing consolidated index preserved |
| Successor frozen | Exact TB40 13-row manifest; falsifiers and stop rules in this record |
| Turn boundary held | Static review only; no product, test, fixture, benchmark, selector or build source mutation; no runtime execution |
| review_check.py boundary | PASS: [run 40238062726](https://github.com/akashskypatel/Directional/actions/runs/40238062726), full-history checkout; source authority, boundary and ledgers all PASS. Artifact `12615493619`, ZIP SHA-256 `aa2f6a2b5ebd748aa2384837cd7d892fb1c3df280eb67e90187f3528416c6c5c`. |
| `STATUS` lifecycle maintained | Entry beacon written; final beacon publication required after all durable content writes |
| Pushed to origin, branch in sync | Remote comparison and PR head verified the pushed patch. Real-history runner reported `## HEAD (no branch)` with clean checkout; tracking/ahead-behind not inferred. |
