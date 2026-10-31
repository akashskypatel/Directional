# RP-02 network-bound open-front rail consumer witness (2026-10-15)

Turn `M6-CP3-CB1-R4-RP02-WITNESS` (Code + Build) implemented one test source in `tests/SurfaceCellsPhase10Tests.cpp`:
`SurfaceCellAuthorityContractCutover.ProducedRailIntervalReachesNetworkBoundOpenFrontConsumer`.

## Source and admission criteria

- Existing actual rectangular hard-rail producer fixture supplies nonempty producer-owned rail `sourceVertices` / `sourceEdges`, the source chart/atlas, and a real `FieldAlignedCurveNetwork`.
- The test requires phase-front `Produced`, a nonempty published cell complex, and a published `HardRail` front side carrying producer rail ID, route steps, valid filled cell and side; `assign_open_front_boundary_authority` alone sets that boundary-ownership evidence after network-bound `rail_interval_refs` verification. Skipping this consumer fails the positive.
- Each consumed source edge is independently checked against the corresponding real network mandatory-edge row and rail owner. No synthetic receipt is inserted.
- A second call uses an authentic producer fixture but substitutes one well-typed hard edge in the actually consumed rail. It requires phase-front rejection with `InvalidFrontBoundaryAuthority` and a named filled cell/side at the same downstream consumer. This is not a direct test call to the interval validator and is not a factory-only rejection.
- The existing helper accepts an optional authoritative-rail override solely for the negative; existing call sites retain the producer fixture's rails by default.
- No algorithm, workflow, frozen 497 selector, benchmark, acceptance ledger or API changed. A passing compile cannot establish liveness, correctness, or regression restoration at runtime.

## Exact source / verification

- Verified source snapshot: `82bc4fb9e6756cf50ab611f70940b5c6350a2e86`, workflow `38663208284`, artifact `11940290107`, 5605/5605 source SHA256SUMS, outer digest `2416729783cfabd57a8acad2f4eb0f50876eb94c5f71be3c5f1a82b6e89f45e2`.
- Work-preservation patch: complete SHA-256 `13ab33bf2086ff59afe7dbdc7214dc6aa037cc21dff2d6019f31f66b782aae82`, body SHA-256 `8a629edf385de7bb0c5a566c510c3cc7d5892bccf89aebfc481095bbf2256cad`; exact-base apply-check and whitespace-check passed.
- Drive patch apply: workflow `38663798810`, result artifact `11939598035`; base and patch digests matched; semantic source `953f812ff1f431e3ad3af3b68a92284a7831c94a`; `runtimeExecution=false`. One intended test file changed; transient staged Drive file was owner-permanently deleted.
- Mandatory eight-target GMP/GMPXX compile: [38664036225](https://github.com/akashskypatel/Directional/actions/runs/38664036225), immutable artifact `11939982141`, outer ZIP SHA-256 `2d5d1fc3f75b573307cae8af3c837da3dde2302ffdb4fe0ef3dd34d2aafeed7a`. Verified 28/28 SHA256SUMS, eight approved targets, preflight/build 0/0, generated GMPXX+GMP link, five clean source-status files, exact semantic source and runtimeExecution=false.
- **No Directional test binary, benchmark or runtime test was executed. The written witness remains unverified by execution and cannot count as a runtime PASS.**

## Disposition

RP-02 source-authored and compiled. Both authoring duties in the frozen handoff are closed, so the canonical R4 **Code + Build authoring work ends here**. All historical runtime acceptance/restoration requirements remain in the separately authorized Test + Benchmark backlog: R4-JCT-01, RA-49.2, 39 endpoint, 34 Phase10, seven DCEL, 88 CP2 restorations, six CP3, organic D1/D2/D3/D5/A6/A7, odd-τ and RP-02. Do not infer TB497 permission. PR #8 remains draft/open, selector 497 and historical ledger 66/17/49, debt 1, CP2 491/491, R3 403/497 unchanged.
