# M6-CP3-CB1-ENTRY-R4 — D2 odd-carrier versus complete A2b attached transport

**Scope:** incremental Code + Build correction to a previously existing regression, not runtime acceptance, frozen gate authorization, or an architectural redefinition. Source authority: `e3d2a1bcdb6965ec48f11af5add0113c4eae2785`.

## Diagnosis and exact correction

- Independent A5 consumer `src/pipeline/RemeshPipeline.cpp`, `SurfaceOccurrenceComplexProducer::produce`, compares endpoint branch difference with `compose(rigidRotation, endpoint.attachmentTransport())` (current source around line 5008). It does not use `terminalCarrier.firstToSecond` alone.
- Existing D2 regression `M6CP3.HardRailCrossRegionBranchCertificateStripsEndpointFaceGauge` erroneously selected its relational witness and checked its branch identity using carrier-only chi, even though its own fixture demands at least one genuine nonempty terminal A2b source-star path.
- One-test-source correction keeps the odd **carrier** turn as the condition for the A4-owned tampering discriminant, but computes the endpoint's relational `tau` from the full typed `attachmentTransport()` (inverting only for reverse orientation). It compares the local face gauge delta and endpoint branch equation against that actual attached tau, and records both carrier and attached turns in diagnostics. It preserves original test name and frozen selector bytes.
- Patch base `8d6dd1fd1242d494af448a70769260e7ff9d093a`; full patch SHA256 `057d4586554d1b16c6de130c2e857ef0b2fc007c3b78cdf0a06413af8842c3ed`; diff-body SHA256 `89af3ddd97f05092d7b7cbf01acb42825f7932882c1ae0e8e24d1e1f58525610`; sole path `tests/SurfaceCellTransitionQuotientTests.cpp`. `git diff --check`, `git apply --cached --check` against exact captured snapshot both passed. Download and Library backup `/Directional/Evidence/Directional_M6_CP3_R4_D2_AttachedTau_Witness_Correction.patch`.
- Drive apply run `38088012591`, job `114318559371` SUCCESS; applied semantic commit `e3d2a1bcdb6965ec48f11af5add0113c4eae2785` with one test file 17 lines added / 5 removed; result artifact `11682955910` ZIP SHA256 `42a9f78ca2f7efabb15ec756f8efb848fd56376e7fc5e2c3658892d4771786f3`, log artifact `11683500387` ZIP SHA256 `4e583db5d5181783428ca4d76df1eab7115a4834bf70d8c854a30b401e3f8328`; Drive staging `1IT09V9Sx0-4ZddFLY0wDusVZ6En0DI9j` permanently owner-deleted.

## Compile-only evidence

**GREEN compile-only evidence:** durable dispatcher workflow [38088126976](https://github.com/akashskypatel/Directional/actions/runs/38088126976), compile job `114318883131`, exact source `e3d2a1bcdb6965ec48f11af5add0113c4eae2785`, eight of eight requested GMP/GMPXX targets built, preflight exit 0, build exit 0, 28/28 self-excluding `SHA256SUMS` file hashes validated, clean source, `exactArithmeticBackend=GMP`, generated link line contains `libgmpxx.so` and `libgmp.so`, `runtimeExecution=false`. Result artifact `11683325306` ZIP SHA256 `0486bc6e5780ccced5d5dd30a74d83248fbf465ecf2ee34157bf2def0c93a2b8`; dedicated log artifact `11683815002` ZIP SHA256 `cbdbf250a2539f473d310c6e5ab0940e7b330d8c8f35c5ca5e7fe2b7352301e4`. Both artifacts downloaded and outer SHA256 checked; package metadata and all 28 recursive hashes verified. No runtime/test result was obtained.

No Directional executable, benchmark, CLI, ctest, generated test or frozen 497 selector was executed during this turn. Compilation does not prove any runtime result.

## Remain open

- The independent *source-valid two-admissible-simple-path* falsifier is geometrically questionable for a connected two-manifold vertex link cut by a rail spoke: deleting a single link edge leaves a path; deleting two cuts leaves disconnected paths. Each component then has at most one simple nonrail route between two faces. A separate design authority must either exhibit an admissible source-valid counterexample or revise the witness expectation; do not invent a nonmanifold case or silently waive it.
- R4 still owes actual 39 carried endpoint effects, 34 Phase10 positive recoveries, seven DCEL fixture negatives, 88 accepted CP2 restorations, genuine multi-carrier and odd-tau sources, and independently accepted future frozen 497 runtime gate. Historic CP2 491/491 and rejected R3 403/497 with 94 RED, stable 66/17/49 debt 1 remain unchanged. No Test + Benchmark successor.
