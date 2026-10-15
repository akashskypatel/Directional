# Endpoint chart diagnostic — Code + Build record

**Current turn:** `M6-CP3-CB4-R4-ENDPOINT-CHART-PROBE`. Scope is a diagnostic-only extension after A4 route endpoint rejection, followed by exact-source eight-target GMP/GMPXX compilation. No runtime, benchmarks, selector edits, acceptance/predicate changes, or RP-01 repair are authorized.

## Source authority and rationale

- Frozen trigger/source commit `4c114b24811140a8b74e05570ae3e17e4f7e5197`; snapshot workflow [38775481890](https://github.com/akashskypatel/Directional/actions/runs/38775481890), snapshot artifact `11993616345`, outer SHA-256 `ac9694617c3ee648d703502f2dd0436961dd4d97c07d1f340b3d7afc7144bf5e`, source.tar.gz SHA-256 `4456493499d8913f8cd18281bc984f3d883df62b5e60f36746ee855a68ed5151`, 5642 source files (file count, not a checksum-verification ratio). Source manifest verified locally separately.
- Binding decision: `Architecture_M6_CP3_R4_Endpoint_Authority_Spec_Review_Decision.md` RA-65.3 and RA-65.11. The claimed endpoint face pair `{0,7}` was **not measured**; RA-64.6 was withdrawn. A concrete measurement of actual endpoint charts and A3 carrier face keys is required before any mechanism is inferred.
- In `src/geometry/SurfaceCellTracing.cpp`, after `endpoint_certificate` already rejects, extend `endpointEvidence` to emit `a2bProbeFromFace`, `a2bProbeToFace`, `a2bProbeFromAttachment`, `a2bProbeToAttachment`, `a2bProbeCarrierFirstFace`, and `a2bProbeCarrierSecondFace`. The latter four are canonical source-face vertex triples, not guessed row IDs; a key is absent when the corresponding source face or carrier is absent. This distinguishes the precise face charts and carrier-side eligibility without admitting a rejected route.
- The change is deliberately inside the existing `if (!firstEndpoint || !secondEndpoint)` path. It never changes `endpoint_certificate`, the first-rejection ladder, any branch selection, emitted topology, or validators. No test/benchmark executable is run in this Code + Build turn.

## Acceptance and continuation boundary

The existing probe parser and pinned 44-case artifact-only harness remain unchanged; that harness explicitly pins an old immutable package and must **not** be run against it to claim these new fields. A separately authorized Test + Benchmark turn must consume the new verified immutable GMP compile package, select an exact appropriate diagnostic harness, and report the actual face rows and face-key triples for the 21 previously `carrier-orientation` cases and controls. Only independent Review may judge same-sector versus cross-feature chart selection, acceptance, or repairs. No generic star-route gate is authorized: RA-65.5 suspended it because no producer publishes that witness. Ledger 66/17/49, debt 1; accepted CP2 491/491; rejected R3 403/497 and frozen selector 497 unchanged.

## Remote application and compilation

Pending verified patch application and exact-semantic-source eight-target GMP/GMPXX compile at authoring time. Do not claim compile GREEN or runtime evidence until immutable receipts and hashes have been verified.
