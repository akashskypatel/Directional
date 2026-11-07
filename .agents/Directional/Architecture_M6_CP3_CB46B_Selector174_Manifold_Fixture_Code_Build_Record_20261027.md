# CB46B selector174 manifold fixture — Code + Build (2026-10-27)

- Canonical turn: `M6-CP3-CB46B-RP01-SELECTOR174-MANIFOLD-FIXTURE`; authorization RA-165.3.
- Test-only correction source: `8f0d4329695de1c7542ea240e30e55761acc3a38`; applied patch base `93c79d98b0791deb3855f6b60ed1418c80e5259f`.
- Exactly one changed source path: `tests/SurfaceCellREPackageTests.cpp`; `git diff --numstat`: **12 12**.
- F174-a: manifold fixture uses four referenced vertices with `ASSERT_NO_THROW`; fifth vertex stays for nonmanifold control.
- F174-b: comment corrected to match source claim/support mismatch.
- F174-c: disconnected components each get two triangles, retaining original face indices 0/1; `ASSERT_NO_THROW` guards `set_mesh`.
- F174-d: comment records all-boundary single-triangle TriMesh restriction.
- Test assertions otherwise unchanged. No helper, harness, manifest, workflow, or production modifications.
- First compile dispatch [40464531197](https://github.com/akashskypatel/Directional/actions/runs/40464531197) was invalid before compile: unsupported `retention_days` request field; corrected dispatch event `57bb0bf6f0a3`.
- [Compile-only run 40466255947](https://github.com/akashskypatel/Directional/actions/runs/40466255947); immutable package `12716018703`; ZIP SHA-256 `0053f63fe9f9449e6f5024cbc2df36ca029c22cd58d75e2710fefb906af1a89f`; log artifact `12716398136`.
- Eight targets: `directional_core`, `directional_pipeline`, authority-kernel, producer, completion, validation and compiled-API tests, and `directional_benchmarks`.
- Exact arithmetic: GMP and GMPXX verified in generated link command; `exactArithmeticBackend=GMP`; `runtimeExecution=false`; no tests or benchmarks executed.
- Next authorized turn: `M6-CP3-TB46-RP01-FULL-GATE` artifact-only on this package, frozen manifest and harness; prediction 498 PASS / 6 RED is **not** acceptance.
- Stable accounting retained: CP2 491/491 accepted; 66/17/49, debt 1; selector497 and CP3 not promoted.
