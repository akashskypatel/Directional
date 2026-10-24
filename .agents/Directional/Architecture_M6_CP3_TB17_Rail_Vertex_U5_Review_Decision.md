# RA-103 — TB17 reviewed: CB17 (U4) accepted; CB18 (U5, consumer emits R) and TB18 specified (2026-10-19)

**Turn:** `M6-CP3-TB17-R10-FACTORY-RAIL-VERTEX-ENDPOINT-REV`. **Inputs:** HEAD `8f1eab028`; CB17 source `ccc0b00ab6a94d0889ed7c60e4532b6c985ce03e` (HEAD `src/include/tests` identical), package `12214741070` ([run 39306529387](https://github.com/akashskypatel/Directional/actions/runs/39306529387)); TB17 [run 39313027637](https://github.com/akashskypatel/Directional/actions/runs/39313027637), result `12215967774`. **S** = `src/geometry/SurfaceCellTracing.cpp`, **H** = its header, **P10** = `tests/SurfaceCellsPhase10Tests.cpp`. Lines are at `ccc0b00ab`.

## RA-103.1 Re-verification

- **CB17 package:** ZIP SHA-256 `9acb5081…5ca5` matches; manifest 28/28; `source-commit` = `ccc0b00ab`; build exit 0; eight targets; `runtimeExecution=false`, `exactArithmeticBackend=GMP`. The packaged `src`, `include`, `tests` and `CMakeLists.txt` are byte-identical to git `ccc0b00ab`. **The package expires 2026-10-26**; nothing after CB18 depends on it.
- **TB17 result:** ZIP SHA-256 `b32366a1…2ace` matches; manifest 17/17; 13 planned, 13 executed, 0 missing; postflight, package, source, execution view and frozen selectors all true; compile, relink, benchmarks and selector497 false.
- **Harness** `efa91d9b…c7a9` differs from the TB16A harness `20b2ebd8…afea` only in lines 7–9, the appended #13 tuple, the two counts and the two labels.
- **Outcomes:** #1–#7 and #13 PASS (`OK` lines in the raw logs). The #8–#12 ledger `first_failure` fields and the full raw first predicate lines (6,972–9,565 bytes) are byte-identical to TB16A. Every RA-102.5 prediction holds.

## RA-103.2 CB17 conforms to RA-102.4

- **Field:** `railVertex` is the last member (H:1503-1505), so every five-member construction leaves it empty.
- **Interval helper** (S:8249-8296): both tags on one end → false; an R end must be `vertices[start|end]` with the index strictly inside (0, n−1). Defaults keep every existing caller unchanged.
- **Eligibility** (S:8298-8321): exactly one occurrence at 0<k<n−1; both chain edges hard and distinct; no other incident hard edge.
- **Factory** (S:8723-8727, S:8809-8814, S:8884-8985, S:8986): seeds interior chain vertices; passes R anchors; both tags → reject; the T contact clause is guarded by `terminalVertex`, so T is unchanged; the R clauses are not-a-contact, eligibility and opposite-orientation exclusion; the closed branch rejects R. `hardRailOpenChains.at()` is safe because the route check returns first when the chain is missing.
- **Digest** (P:2125-2129): tag plus index only when R is present; every existing digest is unchanged.
- **Design note:** under eligibility, the carrier's two faces fall in different non-hard components of R's star, so the opposite-orientation clause cannot fire when the selected orientation is admissible. It is a parity guard, not a new restriction. The consumer must carry the same guard (RA-103.4.3).

**CB17 (U4) is accepted.** The factory R and I branches still have no real-data coverage; CB18 supplies it.

## RA-103.3 Consumer design facts (read at `ccc0b00ab`)

- `endpoint_certificate` (S:19505-19735) tries T (S:19600-19607), then I (S:19608-19627), then rejects `no-exact-terminal-corner` (S:19628). Its A3 star and orientation selection (S:19630-19734) are keyed to `*terminalVertex` only at S:19637-19638 and S:19726.
- The consumer route check (S:20476-20488) passes only the T anchors.
- No other source reads `terminalVertex` (pipeline A5 uses `attachmentTransport()`, which is generic over the paths).
- `ForeignSourceTerminalContactRejectsAtFirstA4ConsumerPredicate` (P10:7451-7505) requires `no-exact-terminal-corner` for a one-hot chain *terminal* that is not a contact. An ineligible vertex must therefore keep that label; no new predicate label is needed.
- Tests that assume every endpoint is T (TQ:3017, TQ:3257, TQ:8832, `SurfaceCellREPackageTests.cpp:713`, P10:7518) are production-dependent and currently RED. They are fixture debt, not CB18 scope.

## RA-103.4 CB18 specification — `M6-CP3-CB18-R10-CONSUMER-RAIL-VERTEX-ENDPOINT` (U5)

The consumer emits a typed R endpoint exactly where the factory admits one.

1. **R candidate** (S:19608-19628). Declare `std::optional<authority::SourceVertexId> railVertex;` before the `if (!terminalVertex)` block. Keep the T loop and the I branch byte-for-byte. Replace the single `return reject("no-exact-terminal-corner");` with:
   - `railVertex` = the vertex v ∈ {`edge.first()`, `edge.second()`} with v ∉ `contact->second.endpoints`, `exact_corner(fromPoint, v)`, `exact_corner(toPoint, v)`, the rail's chain present in `authoritativeOptions.hardRailOpenChains`, and `open_rail_interior_vertex_valid(v, chain, authoritativeOptions.hardFeatureEdges)`;
   - none → `return reject("no-exact-terminal-corner");` (label unchanged).
2. **Star vertex** (S:19637-19638). After the A3 null check, `const auto starVertex = terminalVertex ? *terminalVertex : *railVertex;` and use it in the spoke filter. `path_to` and the sector test are unchanged.
3. **Orientation parity** (S:19692-19733). Count orientations where both `firstPath` and `secondPath` exist, before the sector test. After the loop, if `railVertex` and the count is 2 → `return reject("ambiguous-carrier-orientation");`. T is unchanged.
4. **Certificate** (S:19725-19727): pass `railVertex` as the sixth positional member.
5. **Route check** (S:20482-20484): pass `firstEndpoint->railVertex, secondEndpoint->railVertex` as the trailing arguments.
6. **Unchanged:** T and I behaviour, the closed branch, the probes (S:19736-20100), the factory, the digest, selectors, harnesses.
7. **Tests** (compiled, not run):
   - P10:7333-7337 (#9's filter): add `!route.endpoints[1].railVertex.has_value()`, so an R endpoint with empty paths cannot stand in for the I endpoint.
   - New `SurfaceCellAuthorityContractCutover.ProducedOpenRailInteriorVertexEndpointRejectsForgedTags`, inserted at P10:7406:
     - build `build_rectangular_hard_rail_phase_front()`; assert `Produced` (with `hard_rail_first_failure_detail`);
     - find a route endpoint with `railVertex`; assert one exists;
     - expect: no `terminalVertex`; R is not a contact endpoint; `open_rail_interior_vertex_valid(R, front.hardRailOpenChains().at(route.rail), front.hardFeatureEdges())`; R is an end of `terminalCarrier.edge`;
     - positive control: `make` with the unmodified routes (the P10:7390-7399 argument list) returns a `SurfacePhaseFrontProduct`;
     - each forgery → `InvalidSourceAuthority`: (i) `terminalVertex = railVertex`; (ii) `railVertex.reset()`; (iii) `railVertex` = the other end of `terminalCarrier.edge`.
8. **Build:** GMP/GMPXX compile and package, the eight CB17 targets. Record ≤25 lines: package ID, ZIP SHA-256, source SHA, `runtimeExecution=false`.
9. **STOP** if any clause cannot be implemented as written or needs a site not listed here.

## RA-103.5 TB18 — `M6-CP3-TB18-R10-RAIL-VERTEX-ENDPOINT` (artifact-only, two parts)

**Part A, focused.** The TB17 harness (`efa91d9b…c7a9`); change only sha, artifact, digest and labels; append #14 = the new test (`diagnostic`), with the matching counts.
- **Predictions:** #1–#7 and #13 PASS. None of #8–#12 or #14 keeps a B2 first failure (`predicate=endpoint-0|1` with an integer `a3ProbeDecodedVertex`, `a3ProbeContactEndpointMember=0`, `a3ProbeContactPublished=1`); each is PASS or has a new first failure.
- **Falsifiers:** any gate RED; any #8–#12 `first_failure` byte-identical to TB17; any checked-factory `InvalidSourceAuthority` on a route the consumer certified with R.
- If a gate is RED, stop: no Part B; TB18-REV.

**Part B, census.** The unchanged census harness `m6_cp3_entry_497_artifact_only_harness.sh` (`947a95ee…79dd`) with `--execute` and the five CB18 values (`CANDIDATE_ARTIFACT_ID`, `EXPECTED_SOURCE_SHA`, `EXPECTED_CANDIDATE_ZIP_SHA256`, `EXPECTED_ROOT_MANIFEST_SHA256`, `EXPECTED_SOURCE_ARCHIVE_SHA256`). Baseline: TB16C result `12207970911` (expires 2026-11-02).
- **Deliverables:** `Architecture_M6_CP3_TB18_Selector_497_Red_Inventory.tsv` (RA-101.4 columns, with TB16C in place of TB14A); classification RA-90.4 with RA-91.2, plus U6; a report of 30 lines or fewer giving totals per phase, counts per class, the TB16C PASS→RED and RED→PASS lists, each of the 30 TB16C B2 identities by name with its TB18 status and class, and the TSV SHA-256. No interpretation.
- **Predictions:** 0 PASS→RED (≥425 PASS); none of the 30 stays B2.
- **Falsifiers:** any PASS→RED; any of the 30 still B2; any B1, B3 or U6.

## RA-103.6 Sequence

CB18 → TB18 (A, then B) → TB18-REV → fixture debt (RA-96.6 order 242 → 174 → 250 → adjacent-sheet → 191 → 442, plus any I/R test-assumption sites TB18-REV assigns) → census → RP-01 Review. Accounting is unchanged: 66/17/49, debt 1, census 425/497, selector 497; `RP-01` open, `RP-02` UNREACHED, Gate C suspended.
