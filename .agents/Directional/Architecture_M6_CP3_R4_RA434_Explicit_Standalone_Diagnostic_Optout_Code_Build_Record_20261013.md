# M6-CP3-CB1-ENTRY-R4 — RA-43.4 typed diagnostic opt-out hardening

**Boundary:** continuing Code + Build, without runtime tests or benchmarks. Not full RA-43.4 closure and not TB497 authorization.

## Evidence and narrow change

Source frozen at GitHub snapshot `4128a98182c4af7d0944526c98156a91fffa8003`, workflow `38326684095`, artifact `11780139584`, outer SHA-256 `b0d66651087e2e34950cae1612824de5c12b405056df67b3dd64e6872511623a`; all **6,583/6,583** SHA256SUMS paths verified and source.tar.gz SHA-256 `45ea523b9af4f743a8937263ca39ac2a18a04004d0f9642ecc3eb14665247db1` matched metadata. No Directional executable was run.

`surface_cell_tracing_detail::rail_interval_refs` formerly accepted an unnamed final boolean (`true` strict, `false` legacy) even though it is a source-identity authority boundary. Replace it with the explicit `RailIntervalAuthorityMode` domain (`RequireTypedSource`, `LegacyStandaloneDiagnostic`), retaining the strict default, existing source-vertex/geometry checks, and the unconditional requirement for typed vertices when a field-aligned network is supplied. Migrate every source/test explicit-boolean call site, including producer, tracing and both isolated Phase14 malformed-rail negative diagnostics. Ordinary production calls do not opt out. Test assertions and frozen identities are unchanged; the historical diagnostics stay available only with a name that announces the exception.

This is an **API clarity and misuse-prevention change, not a newly discovered production vulnerability or proof that all legacy diagnostic paths are retired**. Existing standalone untyped geometry diagnostics still require a broader RA-43.4 disposition. It also does not create RA-43.2 producer-owned oriented-side evidence or close RA-46.5, RA-47.12 runtime, 39 endpoint / 34 Phase10 / seven DCEL / 88 CP2-loss / six CP3, or real odd-τ multi-carrier gates. R3 remains rejected 403/497 (94 RED, 88 historical accepted losses); CP2 remains accepted 491/491; ledger 66/17/49, debt 1. No runtime credit, no successor.

## Verification gate

Apply exact-base patch after checksum verification through Drive transport; then compile/package the eight standard targets via pinned GitHub GMP/GMPXX dispatcher. Verify immutable compile artifact, all hashes, linker, and `runtimeExecution=false`. Do not run binaries, tests, benchmarks or TB497 inside this turn.
