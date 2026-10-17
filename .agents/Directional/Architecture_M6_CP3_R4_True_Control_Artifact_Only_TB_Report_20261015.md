# R4 true-control — artifact-only Test + Benchmark report (2026-10-15)

**Turn:** `M6-CP3-TB1-R4-TRUE-CONTROL` — complete measurement, not full test acceptance.

## Authority and integrity

- Workflow: https://github.com/akashskypatel/Directional/actions/runs/38681907622 — dispatcher request commit `3ebce006d8974119fc661ddf7f0293084ce118b3`; runtime and mailbox jobs both succeeded.
- Harness authority commit `e7208cfc2cbb078be771251f50dac24659c066df`; `.agents/Directional/tools/m6_cp3_r4_true_control_harness.sh` SHA-256 `9d471c493b7d3c9c4fa5bf31916e37d9caa470a628da6c0e710f770f0c986162`.
- Reused existing immutable GMP/GMPXX compile artifact `11939982141` (compile run `38664036225`), ZIP SHA-256 `2d5d1fc3f75b573307cae8af3c837da3dde2302ffdb4fe0ef3dd34d2aafeed7a`, semantic source `953f812ff1f431e3ad3af3b68a92284a7831c94a`.
- Result artifact `11948572472`, ZIP SHA-256 `2b6ac34c34ea3f0dd384f5be7a55ca9c9028328639effed3c9cc3e3c9674917f`. Its internal SHA256SUMS passed. The packaged 28-file manifest is 28/28 OK before and after execution.
- Execution receipt: `executed=4 red=2 missing=0 postflight=true exit=0`; `package=true source=true execution_view=true selector=true`. No compile, relink, benchmarks, frozen-497 execution, or production/test/selector modifications.
- Source snapshot for analysis: run `38681673377`, exact SHA `72000b8765497ff9b88a1a03102523e31216efb8`, artifact `11947932769` ZIP SHA-256 `910476117e4493a8cd9f6dbfbc1d2fff5cb10268cf2208c0180c1fe3f8e8ce70`, all 5618 file checksums verified.

## Measured identities

| Category | Fully qualified gtest | Result | Earliest observed failure |
|---|---|---|---|
| Square, no interior hard rail | `SurfacePhaseFrontProductFactoryAuthority.ReorderedCellStoragePreservesTypedEdgeOwnershipAtCheckedFactory` | PASS | None |
| Cylinder, periodic cut and no interior hard rail | `SurfaceCellTypedTransportAuthority.ValidPeriodicCutRouteUsesTypedIdentity` | PASS | None |
| Torus with closed-chain hard rail | `M6CP1.A6ClosedComplexBoundaryIsCombinatoriallyEquivalentOnProducedTorus` | RED | `run.surfaceCellContext.hasArrangement` is false (`SurfaceCellTransitionQuotientTests.cpp:6023`) |
| Torus with closed-chain hard rail | `M6CP3.A6UniformFaceGaugeRotationPreservesRelationOutcome` | RED | `originalOccurrences == nullptr` (`SurfaceCellTransitionQuotientTests.cpp:2807`) |

**Interpretation:** No-interior-hard-rail A4 control paths pass, so A4 production is not universally down. Both closed-chain torus identities fail, but neither raw log proves the previously measured open-rail `no-exact-terminal-corner` predicate. Do not conflate these failure loci or claim a common root cause. Two torus identities share one fixture family; no mesh-independent generality is established.

## Orchestration correction and next turn

The dedicated one-off harness implements RA-57.8 without modifying the previous frozen harness: it records `NOT_SELECTED` and continues independent identities, and it does **not** turn an expected semantic RED into an orchestration failure. Missing selection or failed postflight still rejects the measurement. All four were selected.

No stable event, regression recurrence, accepted-gate credit, RP-02 runtime proof or repair is claimed. Ledger 66/17/49, debt 1, CP2 491/491, R3 403/497 with 94 RED and 88 carried losses, PR #8 draft/open, frozen selector 497 remain unchanged.

**Successor:** `M6-CP3-TB1-R4-ENDPOINT39-CENSUS`, a separate artifact-only turn on the same package. Execute all 39 fully-qualified identities even if some fail, and capture the exact fixture singleton, first predicate, `a2bProbeFailure`, `routeLength`, `step`, `chi`, probe source charts and edge parameters, `closedChainPresent`, full `faceEnds` and edge/locus/rail details under RA-57.12. Then separate `M6-CP3-TB1-R4-CARRIER-REV`; do not choose certificate semantics, edit test/production code, or run TB497 in this measurement turn.

## Execution-process exceptions (recorded, not acceptance evidence)

- The initial bootstrap read inadvertently combined `STATUS` with the handoff, conservation policy and `TODO.md` before the entry-beacon write and before declaring the required `READ_MODE`. This violated the mandated ordering. The entry beacon was then published, `READ_MODE=snapshot` selected, and a fresh exact snapshot (`38681673377`, 5618/5618 checksums) used for all further substantive source inspection. This process error is not treated as test evidence.
- The intended Google Drive patch transport for multi-file documentation could not ingest the locally verified patch: `files__manage_library` returned `container_session_unavailable`. Documentation was instead written directly via GitHub connector with current per-file blob SHAs, and the modified-file inventory was checked against the branch. A local forward/reverse/whitespace-verified alternative documentation patch was retained in the session but **was not applied**; it must not be mistaken for the authoritative committed content.
