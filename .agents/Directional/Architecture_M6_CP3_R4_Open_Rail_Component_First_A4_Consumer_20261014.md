# M6-CP3-CB1-ENTRY-R4 — open-rail first A4 component authority (2026-10-14 UTC)

Canonical turn: **M6-CP3-CB1-ENTRY-R4, Code + Build, IN_PROGRESS**. Draft PR #8 remains open/unmerged. No successor, TB497, executable, tests or benchmarks in this checkpoint.

## Source authority and correction

Verified source snapshot `0326e9ac3091b3e1fa0ef62ea8224cc4d218e5e2`, workflow [38505236129](https://github.com/akashskypatel/Directional/actions/runs/38505236129), artifact `11867082482`, ZIP SHA-256 `6ff2b31331904cf84bd95997663872fd30b2ff68b84a1b13c178d718d27951d1`, 5827/5827 file hashes.

The open-rail A4 terminal endpoint certificate previously trusted the producer's `SurfaceHardRailTerminalContact.component` without comparing it to either physical source attachment. The closed-rail first-consumer path already enforced that component comparison. `src/geometry/SurfaceCellTracing.cpp` now rejects a foreign open-contact component **at the first endpoint consumer**, with `a2bProbeFailure=terminal-contact-component-mismatch`, before the checked factory. This does not change matching, topology selection or other predicates.

`tests/SurfaceCellsPhase10Tests.cpp` now contains `SurfaceCellAuthorityContractCutover.ForeignOpenRailComponentRejectsAtFirstA4ConsumerPredicate`: a genuinely produced disconnected-rectangular rail/contact is retained except for a real, foreign component ID. It requires first-consumer `InvalidHardRailRouteCertificate/EndpointAttachment` rejection. The fixture's genuine positive remains unmodified.

Exact-base two-file preservation patch full SHA-256 `30849e26095a45f691eae6d9cf8247b615b36f8db13f3e6837bf772055c3c358`, body SHA-256 `f583cf2d72609e6a801c22628cc56bc75afbd19dd4bb5b8fde5e816ed7b9cfe1`. Local exact-base forward apply, reverse applicability, byte comparisons and whitespace verification succeeded. No local compile.

## Applied GitHub evidence

Drive apply [run 38508173122](https://github.com/akashskypatel/Directional/actions/runs/38508173122), immutable result artifact `11868144048` outer SHA-256 `3ec9f5a4aa8e2fc3c01602578ae84cfa349bfaf28e1015ce4b5c5d1d1e69d3c8`, `job_status=success`, `runtimeExecution=false`, exact semantic commit [43e090c](https://github.com/akashskypatel/Directional/commit/43e090ccb887a87c76f6242f498f78182103cee0). Independent commit comparison: exactly 2 touched files, 9 production + 45 test lines inserted, no deletions. Transient Drive file `1BiV5YZJ5fr3V3Gmu3ZxH_u8oKkEIjoKY` was permanently deleted successfully by owner.

**Pinned eight-target GMP/GMPXX compile GREEN:** request commit [4fab127](https://github.com/akashskypatel/Directional/commit/4fab1273207fa44fdd312193e261f2d868313327), [run 38508335369](https://github.com/akashskypatel/Directional/actions/runs/38508335369), compile job `115670962030`, source SHA `43e090ccb887a87c76f6242f498f78182103cee0`, result artifact `11869275592`, outer ZIP SHA-256 `6da4a5f47c2072e7f0d0216b517ed95299b8a19d5ccdff1d122a32a5dbd75ed2`. Exact artifact `SHA256SUMS` 28/28 hashes passed; all 8/8 required targets packaged, preflight/build exit `0/0`, `DIRECTIONAL_ENABLE_GMP=ON`, link includes both `libgmpxx.so` and `libgmp.so`, five empty source-status files, `exactArithmeticBackend=GMP`, `runtimeExecution=false`. Test/benchmark job skipped. **This proves compilation only; the new regression remains unexecuted.**

## Continuing R4 only

The original patch and pinned eight-target compile are complete and verified; do not re-trigger or relabel them as runtime acceptance. Continue only the nonduplicated R4 producer/germ/source obligations and compile any later semantic source changes before an independently authorized Test + Benchmark turn. All RA-43.1/43.4 organic source/germ, RA-47.12 executed liveness (separate TB), historical 39/34/7/88/six, D1/D2/D3/D5/A6/A7, and real multi-carrier odd-τ remain open. Existing RA-46.5 negative regressions, RA-46.6 typed factory distinctions and RA-49/51 retired disjuncts must not be duplicated. Preserve frozen 497 selector. Never promote compiled regression source to a test PASS; do not begin TB497 or successor.
