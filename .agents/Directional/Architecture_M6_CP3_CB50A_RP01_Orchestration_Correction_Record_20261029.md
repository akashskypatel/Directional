# CB50A — TB50 asserted-site preflight contract correction (orchestration only)

**Canonical turn:** `M6-CP3-CB50A-RP01-ORCH`. **Authority:** RA-170 S5 and the TB50 S5 report. Snapshot SHA `fcc8fdac35679c98a0ffa1d96749a8003bf35614`, CI source snapshot run `40937242698` / artifact `12926180188` (success, submodules and archive hashes verified). Source/package baseline for later execution remains CB52 `7cf0857b4818186638ce77e4859adacbeebd288f`, package `12918290481`; no rebuilding or native execution in this turn.

## Root cause and narrow correction

The seven-column harness contract treats `asserted_site` as a **GoogleTest first-failure source-file/line/witness pin**, not as a native product's semantic error label. `GUARD` cases must carry `-`, and passing `POSITIVE` cases without a registered first-failure source location must also carry `-`. TB50 rows 505–508 incorrectly stored expected *inside-test producer rejection reasons* in that field. Keeping them would make the 508-case preflight impossible; loosening the harness to accept arbitrary strings would reduce control first-failure verification.

Only the final `asserted_site` field of rows **505–508** changes to `-`. The identities, binaries, expected PASS verdicts, order, and native test bodies remain **byte-identical**. The semantic predicates remain actively asserted by the native GoogleTests, as independently checked against the frozen source:

| Row | Native test | Retained native checks (not harness first-failure pins) |
|---|---|---|
| 505 | `SurfaceCellsPhase10Tests.cpp` `ProducedRailIntervalReachesNetworkBoundOpenFrontConsumer` | `TypedAuthorityMismatch` with network versus `Valid` without; `InvalidFrontBoundaryAuthority`; actual cell/side receipt |
| 506 | `SurfaceCellsPhase10Tests.cpp` `MissingOpenRailTerminalContactRejectsBeforeClosedRailFallback` | `EndpointAttachment`, `InvalidHardRailRouteCertificate`, `a2bProbeFailure=missing-terminal-or-closed-rail-provenance`; rejects closed-chain forgery |
| 507 | `SurfaceCellsPhase10Tests.cpp` `OrphanHardFeatureEdgeRejectsBeforeA4Consumer` | accepted untampered producer, rejected orphan, `InvalidFrontBoundaryAuthority`, exact `firstPredicate=orphan-hard-feature-edge;edge=...` |
| 508 | `SurfaceCellTransitionQuotientTests.cpp` `ProducedTorusOrphanHardFeatureEdgeRejectsAtCheckedFactoryCover` | untampered factory accepts; orphan factory rejects `InvalidSourceAuthority` at `open-rail-cover` |

`asserted_site` never enforced the listed native rejection reasons for passing rows; the native assertions do. No source-locus first-failure pin is removed, since none of these four fields contained a `<file>.cpp:<line>|<witness>` site. Every existing genuine negative/RED source-locus pin and the exceptional `selector:174` explanatory note remain untouched.

## Non-native verification

- Manifest row count: **508**, seven-column schema preserved; only four expected site fields changed.
- Existing strict harness `--self-check … 508`: `SELF_CHECK_PASS cases=508`.
- Existing harness `--self-test`: exit `0` (12/12 examples); no test binary invoked.
- Independent static inspection of all four named GoogleTest bodies: all listed typed/status/witness checks present. This establishes assertion *presence*, not successful runtime behavior.
- Original manifest SHA-256: `6d5b788671487fa298ff3a3e9656dfda1729612f02c976206d3960a413121149`; corrected exact manifest SHA-256: `eef8855e27df9401545a62afab7aea6c9a882bb4a15c58545f2cb49d62fc7caa`.
- Harness SHA-256 unchanged: `142321061c57d130a9c73548ce93f52147ebeaeb4c45d3d1c48830e72e2ef93d`.
- No native tests, benchmarks, CMake configure, compile, relink, source changes, or selector promotion. `runtimeExecution=false` for this orchestration-only CB; package `12918290481` remains the TB50-R2 execution candidate.

**Authorized successor (separate turn):** `M6-CP3-TB50-RP01-FULL-GATE-EXEC-R2`, artifact-only using the corrected frozen manifest hash and unchanged harness hash. Expected 508/0 is a prediction, **not observed**. Stable 66/17/49, debt 1; CP2 491/491 accepted; TB49 504/0 reviewed candidate.
