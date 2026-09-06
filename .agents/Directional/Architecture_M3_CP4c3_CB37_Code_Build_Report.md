# M3-CP4c-3-CB37 Code + Build Report

- Phase: `M3-CP4c-3-CB37`
- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`
- Execution mode: canonical Code + Build
- Starting semantic/planning commit: `0be969170ae2f361725c27322e9d22e8eb788038`
- Built evidence commit: `7f63b5f41a0ca72f0b984ec4ee42d11f74775719`
- Runtime executed: **none**
- Review policy: `never`

## Implemented

CB37 implements Part VIII `DEFN-R4` CS1-CS5 and leaves CS6 exclusively to TB32.

1. **Retired `TraceArcDoesNotSeparateItsSides` from emission.** `build_fragment_corner_incidence` no longer rejects a full trace chord merely because its forward and reverse darts have the same certified orbit. The site now records the frozen ownership-map contract: equal-orbit chord sides intentionally accumulate the face corners into the same owning-orbit entry. The enum/string identity remains declared for ledger compatibility.
2. **Published region-frontier evidence independent of terminal error code.** Region construction/certification failures now reuse the existing `GlobalTopologyPlanError` evidence fields to publish the failing plan component, face-set digest/partition identity, the deterministically corresponding certifier census by face-set relation, correspondence/subset state, interior-arc projections, and certified owner observations. The two partitions remain distinct and no new public diagnostic contract was added.
3. **Repaired four pinned witnesses in place.** Ordinals 390, 393, 406 and 407 retain their names, ordinals, gating status, fixtures and semantic evidence assertions, but no longer require the incidental terminal detail code `UncutFaceComponentOrbitSeedNotUnique`.
4. **Selector unchanged.** `Architecture_M3_CP4c3_Required_Green_Selector_408.txt` remains exactly 408 identities with SHA-256 `2a742ba92dba744425fccaf81d5cc7a57885cbff37c779d525218fcd70500af6`; no identity was appended or reordered.

## Engineering-Guideline Review

- Material assumption: `FragmentCornerIncidence` is the frozen certified-face ownership map, not a fragment index; equal-orbit full-chord accumulation is therefore valid ownership aggregation.
- Simplest sufficient approach: remove only the contradictory guard, centralize publication through a small private annotation helper, and change only the four assertions that pinned one failure code.
- No source-face ownership re-open, partition unification, fixture special case, tolerance change, selector mutation, or unrelated refactor was introduced.
- Every production/test change traces directly to CS1-CS3; CS4/CS5 are verified by construction/static diff and build evidence.

## Files Changed

- `src/geometry/GlobalTopologyPlan.cpp`
- `tests/FieldAlignedCurveNetworkTests.cpp`

No build-system, fixture, benchmark, selector or reusable-workflow file is part of the semantic evidence commit.

## Domain Invariants and Accepted-Prefix Safety

For the only behavior removed by CS1, `forwardOrbit == reverseOrbit` on a trace segment:

- the already-existing terminal-slit skip still occurs before this site;
- the unequal-orbit branch is byte-for-byte behaviorally unchanged;
- the ray path remains unchanged and already accepts equal-orbit ownership;
- the full-chord path now performs the same existing ownership writes for both sides, so all corners owned by that certified face accumulate in one `(face, owningOrbit)` entry;
- no source face, source vertex, arc number, fixture identity, or accepted ordinal is recognized specially.

The frontier-evidence helper is observational: it writes only existing diagnostic fields after a region failure is already determined. Certifier correspondence is derived by exact face-set match first, otherwise the smallest deterministic containing census; it never equates independent partition component indices.

## Build

The first compile of changed code was the changed-owner precompile, followed only after its success by the package compile.

- Workflow run: `34014992328`
- Exact source for both compile jobs: `7f63b5f41a0ca72f0b984ec4ee42d11f74775719`
- Changed-owner precompile job: `101437131130` — **SUCCESS**
  - target: `directional_surface_cell_producer_tests`
  - result artifact: `9983635776`
  - provider digest: `sha256:bbca642fed351d149b8ca0f4e16d0746d99938b3e8eb47100a3d8af22c6869ba`
- Package compile job: `101437310546` — **SUCCESS**
  - targets: `directional_surface_cell_producer_tests`, `directional_core`, `directional_pipeline`, `directional_surface_cell_authority_kernel_tests`, `directional_surface_cell_completion_tests`, `directional_surface_cell_validation_tests`, `directional_compiled_api_tests`, `directional_benchmarks`
  - immutable result artifact: `9983643195` / `cb37-package-result-34014992328`
  - provider digest: `sha256:75fcebb299c02b3a10525d935973a8cfca5bf119e3cfc4e54b5591f3cf8f699f`
  - persistent log artifact: `9983643357` / provider digest `sha256:26d733fc358ac22b816e3cfd61ce149d6e404a4db438eb6a51d5eb75cb9d6cb6`
  - packaged source archive SHA-256: `cae8e29946c5e9dfea1a49070e0d8721bc17fb53dba54bb6c66188347560d3fa`
  - root `SHA256SUMS`: all PASS
  - preflight/build exit codes: `0 / 0`
  - source status: clean
  - boundary: `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `exactArithmeticBackend=GMP`
  - GMP evidence: both `libgmpxx.so` and `libgmp.so` are present on the link line.

No generated Directional test, benchmark, discovery/listing command, CLI/GUI binary, or custom runtime input was executed in CB37.

## Known Risks / Runtime Questions Deferred to TB32

CB37 is compile-green only. It does **not** establish that 366/367 advance, that 390/393/406/407 return green, or that the carried credibility surfaces remain unchanged. Those are runtime questions owned by TB32.

The two frozen falsifiers remain:

1. any TB32 stop at `TraceArcDoesNotSeparateItsSides` falsifies DEFN-R4.3;
2. reproduction of `UncutFaceComponentOrbitSeedNotUnique` on the prior 189-face / seedCount 1 / `[0]` component falsifies DEFN-R4.1.

## Mandatory Test + Benchmark Plan

- Plan: `Architecture_M3_CP4c3_TB32_Artifact_Only_Test_Benchmark_Plan.md`
- Evidence commit: `7f63b5f41a0ca72f0b984ec4ee42d11f74775719`
- Immutable package: artifact `9983643195`
- Exact next subturn: `M3-CP4c-3-TB32-EXEC`
- Review successor: `M3-CP4c-3-TB32-REV`
- Benchmark execution: none

## Next Turn

**`M3-CP4c-3-TB32-EXEC` — artifact-only runtime execution.** No source/test/fixture/build mutation or rebuild is permitted. TB32-REV then interprets only the preserved EXEC evidence. Independent review/planning remains a separate boundary and the implementation loop stops there when reached.
