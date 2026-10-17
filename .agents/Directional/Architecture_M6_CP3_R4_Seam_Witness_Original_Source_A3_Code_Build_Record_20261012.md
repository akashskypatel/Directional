# M6-CP3-CB1-ENTRY-R4 — CP3 source-owned A3 seam witness ingress (2026-10-12)

**Boundary:** same Code + Build turn `M6-CP3-CB1-ENTRY-R4`, still IN_PROGRESS, successor UNKNOWN; PR #8 remains draft/open. This is compile-only candidate work, not any runtime PASS or frozen 497 Test + Benchmark.

## Snapshot/source identity

- Exact verified source snapshot run `38206580646`, event/source `27ad5a1fad7b6544fa744f30497a8b1fb77d95a8`, ZIP artifact `11727856253` SHA-256 `706c8b311a8246d5ed24bb41d22b7abb224c89142948fec978da150797f8718b`; source archive SHA-256 `a7a890e3d0ed86086195d0cee427ae5bc19beb1fcf94e74f2df3958940007bf3`; **6365/6365** recursive SHA256SUMS validated; `runtimeExecution=false`.
- Exact-base intended source-only patch `Directional_M6_CP3_R4_Seam_Witness_Source_A3_Ingress.patch`, SHA-256 `6dc4754f405fa0fc36e1eeb30193354ca8ae399409f8e73bb9a120d32b2662d7`, diff body SHA-256 `b244c71184f04c435b1f9447f894fb4925eb7f40fff777a5648ef57d89e6adeb`, path `tests/SurfaceCellTransitionQuotientTests.cpp` only. Forward and reverse Git application checks and whitespace check passed.
- Drive apply `38207015195`, job `114672698768`, result `11727906867` ZIP SHA-256 `36e2e19ec7f3dc163d925ead798a55688a0276cbf04f1ab1ba98ba0580606510`, exact semantic source `b58314b3c8f024d2e6a3ce6092ad87b85425d40f`; Drive file `1uFWtcnkKM2YyQgeNJisJXXHSkJssEH-L` permanently deleted after verified push.

## Producer/fixture change

`make_axis_aligned_isolation_seam_fixture(targetSize)` previously forwarded a valid `CrossFieldResult` to `build_surface_cell_network` without using the already available `bind_phase_front_fixture_atlas` helper. Its A4 front could therefore reject at the unconditional missing-A3 gate, and `m6cp3_produced_seam_fixture` would discard that source produced candidate before checking its A5/A6/A7 certified ordinary seam. The helper is now called with its original mesh, finalized source field, hard-feature set and unchanged options, before A4; A2 source topology and A3 `FieldTransportAtlas::make` are independent of product under test. All original source vertices, face topology, component/sheet labels, target sizes (0.25, 0.5, 1.0), fields, producer rejection and A5/A6/A7 predicates, existing test identities/assertions and frozen selectors remain unchanged. Source/test change: 3 additions, no deletions.

## Exact-source compile-only verification

Exact-source eight-target GMP/GMPXX compile **GREEN**: workflow `38207150160`, job `114673117668`, result artifact `11727628126` ZIP SHA-256 `59145348b1324241ea596fbcce410c75b016881b9abc2d06917be43d21d045b7`, manifest **28/28**, preflight/build exits **0/0**, `DIRECTIONAL_ENABLE_GMP=ON`, generated link includes GMPXX/GMP, `exactArithmeticBackend=GMP`, clean source, `runtimeExecution=false`. Diagnostic artifact `11727807480` ZIP SHA-256 `36decf1318c952fdb6bfcb222acd7336918ab6aa18540f3a82095db6a960e44d`.

No generated binary/test/benchmark, selector enumeration, frozen 497 gate, CLI, discovery, or runtime execute. The corrected source ingress is not evidence that an A5/A6/A7 seam reaches the success path; remaining first-failure semantics require separately authorized runtime evidence.

## Incomplete R4 authority

The historical accepted CP2 491/491, rejected R3 403/497 (94 RED, 88 accepted CP2 lost) and ledger 66/17/49, debt 1 remain unaltered. The independent overfull-A3 feasibility Review remains open, as do global RA-43.4 untyped-rail retirement, 39 endpoint effects, 34 Phase10 positives, seven DCEL negatives, 88 CP2 restorations, six CP3 positives, and genuine odd-τ/multi-carrier sector/source witnesses. R4 stays IN_PROGRESS; no successor authorized. The frozen TB497 must not start.
