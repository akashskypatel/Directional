# RA-46.6 — Checked-factory typed subcodes already implemented

Turn: `M6-CP3-CB1-R4-RA466-SUBCODES`. **Disposition: source-verified no-op**; implementation and test source already satisfy the authorized finite list.

## Source authority

Source snapshot `0f2b1822cf3fecd209a610b6055549c561a000c3`, workflow run `38651012007`, artifact `11934885965`; outer ZIP SHA-256 `2f17ae44ddc9a9bd8cec575d33c10643e743cd8b49dc427ac0b42441ccd80f62`, inner source TAR SHA-256 `0d35c203599602bb1aefc3b57c7a21c52bfc0f363e6ec138fafa0e5c2bb7cfd4`. All 5,601 source SHA-256 entries verified.

## Requirement-to-code census

All seven `SurfacePhaseFrontSourceAuthorityDetail` members already exist in `include/directional/geometry/SurfaceCellTracing.h:1873-1881`, carried by `SurfacePhaseFrontProductError::sourceAuthorityDetail` without replacing the stable primary `InvalidSourceAuthority` error.

| Requirement | Existing typed factory branch | Existing static test |
|---|---|---|
| Atlas-source gate | `AtlasSourceMismatch`, `src/geometry/SurfaceCellTracing.cpp:8136-8145` | `tests/SurfaceCellTransitionQuotientTests.cpp:9155-9162` |
| Malformed source-edge key | `MalformedSourceEdgeKey`, `src/geometry/SurfaceCellTracing.cpp:8251-8260` | No claim of executable malformed-source witness |
| Zero hard-feature incidence | `AbsentHardFeatureIncidence`, `src/geometry/SurfaceCellTracing.cpp:8269-8277` | `tests/SurfaceCellTransitionQuotientTests.cpp:9164-9185` |
| Overfull hard-feature incidence | `OverfullHardFeatureIncidence`, same guard `:8269-8277` | Guard retained; no runtime or reachable-branch claim under frozen RA-48/51 topology preconditions |
| Missing terminal contact | `MissingRailTerminalContact`, `src/geometry/SurfaceCellTracing.cpp:8280-8288` | `tests/SurfaceCellTransitionQuotientTests.cpp:9187-9197` |
| Zero terminal-star paths | `MissingTerminalA3Path`, `src/geometry/SurfaceCellTracing.cpp:8623-8634` | `tests/SurfaceCellTransitionQuotientTests.cpp:9226-9246` |
| Multiple terminal-star paths | `AmbiguousTerminalA3Path`, `src/geometry/SurfaceCellTracing.cpp:8623-8634` | No reachable execution claim |

`TerminalStarPathResult::Invalid` remains a separate generic fail-closed case. Frozen RA-51.7 forbids a typed subcode for the dead nonreciprocal-terminal-A3 disjunct; RA-52/RA-53 similarly prohibit new codes for retired predicates. This turn does not broaden the authorized predicate list to every generic factory failure. Earlier `RA-46.6/RA-48.5` implementation and checks were already recorded in `Architecture_M6_CP3_R4_RA47_Typed_Rail_Code_Build_Record_20261012.md` and `Architecture_M6_CP3_R4_RA465_RA434_Static_Coverage_Census_20261014.md`. Reimplementing them would be redundant.

## Verification and boundaries

Only source and existing test assertions were inspected. No implementation/test/build-system change, no compile, runtime test, benchmark, TB497, or new validation claim. The previous historical GMP compilation is not runtime evidence. Frozen 497 selector and acceptance ledger 66/17/49 debt 1, CP2 491/491 and R3 403/497 (94 RED, 88 losses) unchanged. All R4 future witness and historical-gate obligations remain open.

**Next separate turn:** `M6-CP3-CB1-R4-RA434-CENSUS` (other standalone geometry diagnostics; preserve RA-52.6 named opt-out). Do not begin it in this turn.

**Process errors:** The session read several authority files before explicitly selecting `READ_MODE=snapshot`, violating the pre-read gate. Once selected, all substantive static code inspection used the verified snapshot. The first manifest check was run from the wrong directory and failed to find a relative path; the corrected check passed. Initial local Git baseline setup encountered dubious ownership, corrected with an exact-directory safe entry. Neither error is counted as repository or runtime validation.
