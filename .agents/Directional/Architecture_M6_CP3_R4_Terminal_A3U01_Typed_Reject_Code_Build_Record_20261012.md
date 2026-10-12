# M6-CP3-CB1-ENTRY-R4 — RA-46 R4-A3U-01 checked-factory typed terminal-path rejection

**Boundary:** Code + Build, no Directional test/benchmark/runtime execution. This is a focused part of the continuing R4 turn, not R4 closeout or permission to start TB497.

## Authority and exact source

- Independent Definition/Review decision: `Architecture_M6_CP3_R4_Terminal_A3_Uniqueness_Review_Decision.md`, RA-46. The two-admissible-path fixture obligation was mathematically retired, **not** the fail-closed `pathCount != 1` guard. Its zero-path branch remains a real first-rejection obligation.
- Exact verified source snapshot: workflow `38186531844`, artifact `11720330413`, SHA `d87d3fc63857b9e1e2e6f041707228c3c2c6021f`, manifest **6277/6277**, `runtimeExecution=false`.
- Production/header/test patch: SHA-256 `6abd02200c374b598df18aae5094f6c6f68e50c87f0b1f7e20addbe70721c3a0`, Drive apply `38186808688`, semantic commit `a384d6bc27f457a7d651aa2574709d7a76c8e7e1`, successful apply, staging owner-deleted.
- Focused test fixture correction: SHA-256 `be678550a7982a87708969b859bc142e17b97c6919a063dd792d5b2f03faf793`, Drive apply `38186915904`, semantic commit `74e74e41a7f040f34798d998dba36677e7ff07d4`, successful apply, staging owner-deleted.

## Changed contract

1. Added `SurfacePhaseFrontSourceAuthorityDetail` with typed `MissingTerminalA3Path` and `AmbiguousTerminalA3Path`, attached optionally to `SurfacePhaseFrontProductError` only when the checked A4 factory's independent terminal-star search rejects a path count. Existing `InvalidSourceAuthority` remains the primary code; malformed/invalid source-star construction retains fail-closed primary rejection without fabricating either path-count subtype.
2. The terminal-star path checker returns `Unique`, `Missing`, `Ambiguous`, or `Invalid`, distinguishing reachable zero-path from the RA-46-unreachable two-path case while preserving the exact adjacency, A3 reciprocity, hard-spoke exclusion, and acceptance predicate.
3. In rejected consumer diagnostics, replace `sourceEdgeFaceCounts.at(spoke)` with a bounds-safe lookup, failing closed on a missing key and retaining the existing overfull-incidence rejection.
4. Extend *existing* `M6CP3.CheckedFactoryRejectsForgedTerminalA2bSideGerm` without renaming it. The initial `74e74e41` regression changed `firstAttachment` alone, which is rejected earlier by the factory's authoritative front-face equality check; thus its claimed typed zero-path oracle was **vacuous**, despite compiling successfully. The correction at `3c1f001fa03dde476222bbad48ae46cfebe12c9a` instead adds a real produced non-hard A3 source-star path spoke to the input hard-feature barrier set, leaving certificate/front face attachments untouched so the unique terminal-star walk loses a required edge. The existing producer baseline and earlier tamper negatives are preserved. This is a static causal argument; runtime first-rejection remains unverified.

## Verification

- Both Google Drive dispatcher `drive_apply` jobs completed successfully; exact result artifact digests were verified.
- Local `git diff --check`, pristine-source `git apply --check` and reverse-apply checks passed. **No local compile was performed**; compilation authority belongs to the pinned GitHub workflow.
- Exact-source GMP/GMPXX eight-target compile: **GREEN**. Durable dispatcher run `38187046419`, job `114611565662`, source `74e74e41a7f040f34798d998dba36677e7ff07d4`, result artifact `11719319676` (outer ZIP SHA-256 `b9b881b7cc820f23b2cf04983f33bbcd9df22d2a9f30a2a5a6eb0b449da2d7f9`), 28/28 packaged hashes verified, 8/8 targets, preflight/build `0/0`, clean source and GMPXX/GMP linker evidence. `runtimeExecution=false`, no tests or benchmarks.
- Follow-up regression correction: Google Drive apply workflow `38188448212` succeeded at source `3c1f001fa03dde476222bbad48ae46cfebe12c9a`; one test file, patch SHA-256 `1b1355b28e9102f611b07484939fe4aa0c82f6835310e92e3b793f4a69c2adcd`. Stage owner-deleted. The exact-source replacement compile request `1b60967136ad863491a2ab15dfb63a491bb07a3e` completed **GREEN**: dispatcher workflow `38188542762`, job `114616135782`, source `3c1f001fa03dde476222bbad48ae46cfebe12c9a`, result artifact `11720182846` (outer ZIP SHA-256 `3ef4c113979d2e861df4d4b30f1c529ba56a408e67c5d250a970bff22823e679`); 28/28 manifest, 8/8 requested targets, preflight/build `0/0`, clean source, both GMPXX/GMP linked, `runtimeExecution=false`. The earlier successful compile for source `74e74e41` remains historical and cannot establish the corrected test's runtime first-rejection.
- **No binary tests, benchmarks, discovery, or frozen 497-case selector were run.** This change provides a regression source, not runtime PASS evidence.

## Remaining R4 authority

- The independent terminal dual-path review is resolved through RA-46, but overfull three-face A3 incidence feasibility review is still open.
- All 39 endpoint / 34 Phase10 / 7 DCEL / 88 CP2 lost-acceptance / six CP3 positive gates and real multi-carrier odd-τ source-witness obligations remain unverified in runtime.
- Do not alter frozen selector/identity, weaken A3/A4 checks or begin TB497 before its separately authorized gate. Resume `M6-CP3-CB1-ENTRY-R4`; successor UNKNOWN.
