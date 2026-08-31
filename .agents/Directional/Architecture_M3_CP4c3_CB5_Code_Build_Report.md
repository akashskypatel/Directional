# M3 CP4c-3 CB5 — Diagnostic Code + Build Report

Date: 2026-08-31 UTC
Turn: `M3-CP4c-3-CB5`
Status: **COMPLETE / BUILD + PACKAGE GREEN / DIAGNOSTIC-ONLY / RUNTIME-FREE**

## Authority

- Starting runtime authority: package **72**, semantic source `93ed2ff50ddad96c9a6aa93f327b3e4d9d93a9b4`, TB3-R1 `33416686424 / 99568970224`.
- Final CB5 semantic/evidence source: `2d22ef293363058cfdca96d01158a93d2c0200f8`.
- Diagnostic implementation commit: `57d68245ddc60b2fd8725e7ff84059f45ff95144`.
- Compile-only type/visibility corrections: `5191f4d31a863af5115de7f9aa7926764ca941af`, then `2d22ef293363058cfdca96d01158a93d2c0200f8`.
- Changed-owner compile proof: `33431349204 / 99617230353`, result/log artifacts `9772889209 / 9772889583`.
- Final eight-target compile: `33433309655 / 99623694545`.
- Full raw result artifact: `9773522237`, SHA-256 `b4b1b6e60aa007e6e4afea242ccf81d173210c1b00198b481f4c6f3cf201f4b9`.
- Full compile log artifact: `9773523017`, SHA-256 `b4ed191852f5a64b90b6bf95b00abb01fe33fb83ea95fd738969cebee73de19d`.
- Package-only retry after a fixture-root orchestration typo: `33433718709 / 99625035344`.
- Immutable mode-preserving package **73**: artifact `9773591345`, Actions SHA-256 `8f3a8f0d6a3ad0931db89cb3e94c33d1d7e8a0d9e1aba27a6ad2690ec9c402a0`.
- Inner `package73.tar.gz`: SHA-256 `fc939abc4110f4a658d80932b395f59c9fd7cecbbcde7caac0ba7b6a41d1aca1`.
- Packaged source archive: SHA-256 `36451a2473a8858225cf9eabb181a58a5397f400f7f0a99995a1b8da37a2cb4f`.
- Frozen selector 373: `b47c269851fad1384b5dc9baaf674b3d4ad80ec6c2b40f7f8eda2055c6f44834`.

No generated Directional binary, test, benchmark, `ctest`, generated discovery, CLI, fuzzer, help/version command, or custom input executed anywhere in CB5. All authoritative compile/package evidence records `runtimeExecution=false`.

## AP0 — frozen selector authority

Committed selector bytes are unchanged. Recomputed prefix hashes:

| Selector | SHA-256 |
|---|---|
| 355 | `e9d88f1196e412e06424294d6be22b32f01c9671ec5e4de119abd3f2fb5afeaa` |
| 357 | `b896d0db7f26aeb0f3513418405efdeccbcf84fb6dc971500c6ddac9e364dc70` |
| 361 | `61918d9fbd7bf757437886f0e86776b60665c58e4d7283b81d42caca03c0288b` |
| 365 | `6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1` |
| 367 | `ef9d082f56f5c8de83124cf2e6257d098408cc597d9147b967cf9c84da4916bf` |
| 370 | `9160ea619afb9e10cbad30012d0bd354c263a2b749e690c271f653db3bf83525` |
| **373** | **`b47c269851fad1384b5dc9baaf674b3d4ad80ec6c2b40f7f8eda2055c6f44834`** |

No gate identity executed.

## AP1–AP2 — typed locus and discriminator

`SurfaceCellFailureLocusDiagnostics` is now the shared surface-cell rejection payload. `fail_surface_cells` retains it in both terminal and first/original failure diagnostics. Four typed producer boundaries adapt their own errors instead of discarding them:

- `atlas_failure_locus(FieldAtlasBuildError)`;
- `network_failure_locus(FieldAlignedCurveNetworkError, FieldTransportAtlas)`;
- `cut_graph_failure_locus(SurfaceCutGraphError)`;
- `topology_plan_failure_locus(GlobalTopologyPlanError)`.

The field-aligned-network stage no longer hand-encodes its error code into the stage string. Code/detail/locus are separate channels.

For the ordinal-366 vertex-transit red, the network locus can publish source vertex, arrival face, branch, `FaceInterior` versus `EdgeTransit`, candidate cardinality and bounded candidate faces, `BarrierAbsorbed`, barrier incidence and `d_B(v)`, and transport-star component count. The arrival-mode enum is single-authority; the detail namespace aliases it rather than defining a second type.

**CB5 did not measure those values.** Runtime was forbidden, so zero versus multiple candidates and M1/M2/M3 remain unadjudicated.

## AP3–AP9 scope checks

- **AP3/AP4:** no transit/product correction landed and no design was chosen against M3.
- **AP5:** M1/M2/M3 correction sketches remain hypotheses only.
- **AP6:** successor TB adopts a separate frozen non-gating 367–373 pass after the ordinary gate first-red is recorded; zero gate credit, no selector-byte change.
- **AP7:** DEFN-R1, prescribed-sphere, R10 and R8 candidates remain carried; **AL4** still forbids designing the sphere fix.
- **AP8:** the assumption-driven predicate found independent typed-data-loss sites at `surfaceCutGraphBuild.error()` and `globalTopologyBuild.error()`, not only the motivating field-aligned-network site. Both now use the common typed locus.
- **AP9:** no barrier transport, cut-fan closure, traversal widening, first-candidate election, sector tolerance, Amendment 12–16/P2 reopening, error-enum renumbering, or selector change occurred.

## Compile and package verification

Changed-owner run `33431349204 / 99617230353` proved the modified core/pipeline/producer-test owners compile and link with GMP/GMPXX. The final authoritative compile `33433309655 / 99623694545` then compiled and linked all **eight standard targets** at exact source `2d22ef293363058cfdca96d01158a93d2c0200f8`. Its raw package manifest verified and source status stayed clean.

The first packaging job in `33433309655` failed **after** the successful full compile because the temporary packaging caller looked for fixtures under `test-data/benchmarks/fixtures` inside the source archive; tracked source authority is `benchmarks/fixtures`. This was an orchestration-only path typo, no Directional runtime or semantic change. Package-only retry `33433718709 / 99625035344` reused the exact successful full compile artifact, copied the **27** tracked fixtures into package-relative `test-data/benchmarks/fixtures`, rebuilt a self-excluding manifest, created a deterministic mode-preserving tar, clean-extracted it, re-verified the manifest, and verified all six test/benchmark executables as `0755`.

## Accounting and verdict

Stable regression accounting remains **44 events / 14 categories / 30 recurrences**; produced-witness debt remains **5**. CB5 advances semantic M3 package accounting **70 → 71** and creates **+0 stable events / +0 recurrences** because no semantic runtime executed.

`M3-CP4c3-TB3-R1-REV-CAND-01` is **implemented / compile-proved**: the shared failure funnel retains typed loci. Runtime publication is a successor-TB evidence question. `M3-CP4c3-TB3-R1-CAND-01` remains **ACTIVE / GATING / CAUSE NOT ESTABLISHED**.

**CB5 is COMPLETE / BUILD + PACKAGE GREEN / RUNTIME-FREE. CP4c-3 remains OPEN.**

## Mandatory successor

Execute **`M3-CP4c-3-TB4`**, artifact-only on immutable package **73**. Run selector 373 from ordinal 1 with first-red hard stop. After the gate verdict is recorded, execute frozen ordinals **367–373** once as AP6's separate **non-gating diagnostic pass**, with zero gate credit. If ordinal 366 remains red, AP2's measured locus/cardinality determines which M1/M2/M3 branch is supportable and the turn routes to `REVIEW + PLAN`; do not implement a correction inside TB.
