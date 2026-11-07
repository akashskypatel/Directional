# M6-CP3-CB1-ENTRY-R4 — RA-43.4 network-bound typed rail edge-key ingress

**Turn:** continuing R4 Code + Build. No test/benchmark/runtime execution, TB497, or successor authorized.

## Exact source and defect

Verified snapshot workflow `38350344837`, event/source `ea25856980b5ac8b8ddd643151c31affb1ea785b`, artifact `11790327933`, ZIP SHA-256 `2a2aa19b9a34409ec5d26ddcd6f14b69534913c893b95e0fd74af40c7a83fad3`, source archive SHA-256 `4d9b9c3a44d9feec1413039be3374ee285a6c7f9ddee3ac195e8832517ae9801`, 5576/5576 source-file checksums, `runtimeExecution=false`.

`src/geometry/SurfaceCellTracing.cpp::rail_interval_refs` uses sample-derived local source-edge keys to match `FieldAlignedCurveNetwork::mandatory_edges()`, while it previously treated `rail.sourceEdges` as optional whenever typed source vertices were supplied. Therefore a rail with intact typed vertices and source samples but **no producer-published source-edge keys** could pass that particular check even when a real network was supplied. This is an evidenced static ingress weakness, not a demonstrated runtime failure.

## Scoped code and regression

- In the network-bound branch only (`fieldAlignedNetwork != nullptr`), require the producer's `sourceEdges` cardinality to equal the interval count at the existing first typed-source authority guard. Rejection remains `TypedAuthorityMismatch` with rail ID. Preserve existing typed vertex checks, per-interval exact source-edge checks, mandatory network match, standalone/no-network legacy diagnostics and ABI.
- Extend the existing producer-backed Phase10 `StandaloneRailDiagnosticModeCannotBypassProducedNetworkTypedIngress` test instead of altering a frozen selector: validate the whole, unmodified producer-rail list **against the real network** as positive; remove only the first rail's source-edge-key list (retaining typed vertices and samples) and require the named legacy diagnostic mode still rejects `TypedAuthorityMismatch` at the damaged rail. The positive prevents a vacuous failure due to incomplete network coverage.
- This **does not** globally retire the explicit no-network `LegacyStandaloneDiagnostic` opt-out, change the source-owned RA-50 oriented filled-side prohibition, or address independent RA-46.5 consumer predicates.

## Evidence and limits

Exact-base patch application and mandatory eight-target GMP/GMPXX compile evidence must be verified separately; neither preparation nor compilation gives runtime PASS. Continue same canonical R4 turn. Outstanding RA-43.1, global RA-43.4, RA-46.5, RA-47.12 observed liveness, 39 endpoint/34 Phase10/seven DCEL/88 CP2/six CP3 positives and genuine odd-τ multi-carrier proof remain open. Frozen 497 selector and 66/17/49 ledger unchanged; no TB497.

## Applied source and exact eight-target compile (2026-10-13 UTC)

- Standard Drive dispatcher apply workflow [38350787211](https://github.com/akashskypatel/Directional/actions/runs/38350787211) applied full patch SHA-256 `91773aaf7302485c7657d3ee98905dbf6833baf402383741cfeedfd02f437e70` from base `ea25856980b5ac8b8ddd643151c31affb1ea785b` at semantic commit **`c11eb6f4aac75676f864c84aed501dcd38d2aeb6`**. Apply receipt artifact `11790528350` outer SHA-256 `f6029b81db02e8f292d0b945ac36f7ec0e4ffab89808a67aab67852f5d0365bd`, job success and runtime disabled. GitHub independently verified exactly five intended paths. Consumed owner Drive staging file permanently deleted.
- Pinned reusable GMP/GMPXX compile [38350909779](https://github.com/akashskypatel/Directional/actions/runs/38350909779), exact source `c11eb6f4aac75676f864c84aed501dcd38d2aeb6`, package artifact `11790937173`, ZIP SHA-256 `959cab5897c43900d4ec3986ecb4e6b75a74d06401be6eddd0ab24bf23660b36`; log artifact `11790467555` SHA-256 `d9f04c52b74deac08540d2ac940adf02975b9ee1452d5f302b6827ca02709fe7`. Verified **28/28** internal file hashes, **8/8** requested targets, preflight/build exits **0/0**, actual generated `libgmpxx.so` + `libgmp.so` link, all five source-status records empty, `exactArithmeticBackend=GMP`, `runtimeExecution=false`. Workflow validation, compile and mailbox jobs succeeded; Test + Benchmark job skipped.
- This closes only the compile checkpoint. **The positive/negative regression has not run**, no acceptance runtime credit, no frozen 497/TB497, and R4 continues in Code + Build. Global legacy diagnostic disposition and all carried production/first-rejection/odd-τ/multi-carrier gates remain open.
