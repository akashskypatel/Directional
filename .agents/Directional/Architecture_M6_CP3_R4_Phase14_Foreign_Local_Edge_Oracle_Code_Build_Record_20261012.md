# M6-CP3-CB1-ENTRY-R4 — Phase14 valid foreign local edge typed-rail negative

**Canonical turn:** `M6-CP3-CB1-ENTRY-R4` still ongoing, successor UNKNOWN; Code + Build only.

## Exact source and change
- Snapshot run `38228270153` SHA `9f341ed03fd4b78e098af9d8f62de284ce9ca1a4`, artifact `11738150091` outer SHA-256 `8d30212c3a9c8ea6ea3922f30ee4260190dcc2ff4af2761f9e8a8558cc75d3ed`; source archive SHA-256 `4c06ef51236672f3936aed3b16337c4351068d944d10dbdd70ff95bce5460cfa`; manifest `6437/6437`, runtimeExecution=false.
- One test file (`tests/SurfaceCellTracingPhase14Tests.cpp`) extended **inside the same test identity** `SurfaceCellTracingPhase14.ProducedRailEndpointsRequireExactSourceVertexIncidence`. Valid original typed rail has vertices `(0,4)` on face row 0 local edge 1. A temporary negative uses face row 0 local edge 0, exact barycentric endpoints vertex `(1,4)`, with true typed chain unchanged `(0,4)`. The accepted baseline is restored before existing mismatched-vertex, near-corner and legacy-untyped controls. Must be rejected as `TypedAuthorityMismatch` at interval 0. This forces the intended first predicate rather than a malformed barycentric, missing edge, or out-of-range rejection.
- Work preservation patch `Directional__M6-CP3-CB1-ENTRY-R4__phase14-foreign-local-edge-negative.patch` at exact base `9f341ed03fd4b78e098af9d8f62de284ce9ca1a4`, outer SHA-256 `eac5243e1def71a503b193eedd87e5e2400276ca3a63f2639bf47ad6cd3bfc0e`, diff-body SHA-256 `9cdb4fd44444875bb26851cec55aa901ff42f2d65fc7974096a23e3087c1855e`; local `git diff --check`, reverse, forward and staged apply checks passed. Backup `/Directional/Evidence/` in ChatGPT Library. Drive apply workflow `38228853566` GREEN; exact semantic `34379d974819be5586e7ef5dfaef00912ad4a343`; staging file owner-deleted. No reusable workflow or permission changed.

## Compile-only evidence
- Code + Build only: source `34379d974819be5586e7ef5dfaef00912ad4a343`; exact eight-target GMP/GMPXX compile **GREEN**, workflow `38228978981`, job `114743570982`, artifact `11737497543` ZIP SHA-256 `bf6500a06082adaab384ee76cf7b72106cebebf0ee7c2103013ce966fd33b50a`; preflight/build 0/0, manifest 28/28, actual GMPXX/GMP linker, `runtimeExecution=false`. No Directional tests, benchmarks, or TB497 executed.
- The regression was **not run**. No runtime PASS, no 497-case promotion, no completed recovery is credited.

## Unresolved gates and precise continuation
- Independent overfull-A3 source-feasibility Review still requested; RA-43.4 legacy untyped rail final cutover still incomplete. Original 39 endpoint, 34 Phase10, seven DCEL, 88 previously accepted CP2 losses, six CP3 positives and genuine odd-tau/multi-carrier source witnesses remain outstanding.
- Historical accepted CP2 remains 491/491; rejected R3 remains 403/497, 94 RED and 88 CP2 accepted losses; ledger 66/17/49 debt1.
- Continue this same Code + Build turn, source-exact, preserve diagnostic first-rejection order; no TB497 tests, benchmark, independent Review amendment or successor in this response.
