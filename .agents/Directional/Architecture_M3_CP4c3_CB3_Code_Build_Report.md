# M3 CP4c-3 CB3 — Code + Build Report

Date: 2026-08-31 UTC
Turn: `M3-CP4c-3-CB3`
Status: **COMPLETE / BUILD GREEN / RUNTIME-FREE**

## Authority

- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`
- Semantic/evidence source: `93ed2ff50ddad96c9a6aa93f327b3e4d9d93a9b4`
- Source change: `M3-CP4c-3 CB3: absorb slit-bound singularity ports`
- Compile/package run: `33370966957`
- Compile job: `99421816569`
- Package-fixtures job: `99423544681`
- Immutable GMP package **71**: artifact `9750235004`
- Package Actions SHA-256: `bcda529df43e1ddca2de0af8eacaca165c839be01961d6edb36b9b0a5df2b038`
- Package fixture log: artifact `9750235481`, SHA-256 `e628989374fb6b1529ab0a6c8c9a41ff764770aa2e67d64bafeaf580c5c78f8b`
- Raw compile package: artifact `9750227619`, SHA-256 `b1cc9a989af2db84ddd2ad83babf9b2221396e45a165aa84927082e610c351c8`
- Compile log: artifact `9750228106`, SHA-256 `4e65b949c33b3f91531b9293c61cf25f96cdf27bdf8c6f59913d2fc215d8bf01`
- Packaged source archive SHA-256: `fb3080e58f41f7c55790f8a77ad9989ce4a91e212ae323ab71afc9bc061812fb`
- Frozen selector 373: `b47c269851fad1384b5dc9baaf674b3d4ad80ec6c2b40f7f8eda2055c6f44834`

This is compile/package evidence only. No Directional test, benchmark, `ctest`, generated test discovery, CLI, fuzzer, help/version command, or other produced binary was executed.

## Assumptions and decision

The independent TB2 review required AN1 measurement before choosing Amendment 16's port policy. Static source/fixture analysis, without executing Directional, established the mechanical witness has **8 prescribed +1 singularities**, of which **4 are barrier-incident**. Every barrier-incident singularity lies on an interior feature arc: `d_B(v)=2`, its cut transport star has **2 components**, and its class is `InteriorArc`. The mechanical barrier graph is a four-component forest with `n=16`, `m=12`, `c=4`, `χ(B)=4`, and no cycles. The prescribed sphere has no active barrier-incident singularity.

Those facts choose Amendment 16 policy **P2 — boundary-absorbed / no ports**. A singularity already bound to the slit boundary cycle does not emit a second trace-origin representation. Supplying branch transport across a hard-feature barrier remains prohibited.

## Implemented change

### AN1 — publish the full error/census surface

`FieldTransportAtlas` now publishes per-region barrier-incident singularity diagnostics:

- source vertex;
- index numerator;
- barrier degree;
- transport-star component count;
- classification (`Tip`, `InteriorArc`, or `Branch`).

Pipeline diagnostic snapshots retain the complete atlas error and route the existing error locus fields through reporting: source edge, source face, source vertex, topology region, and branch. Mechanical/sphere production diagnostics therefore no longer collapse the atlas failure to only code/stage.

### AN2 — package 69/70 binary identity independently re-proved

The package-69 and fixture-only package-70 binaries were independently hashed side by side. All six binaries are byte-identical:

| Binary | Package 69 SHA-256 | Package 70 SHA-256 | Match |
|---|---|---|---|
| `directional_benchmarks` | `d6f10f8191826ad7839d3d57fcd8601b4d030eee811b008201da87e452795f5e` | same | yes |
| `directional_compiled_api_tests` | `8e7e27af635d90f68c0c36dfe052293bcf1b259871dd1dd045ad73a2f7f10048` | same | yes |
| `directional_surface_cell_authority_kernel_tests` | `df132846b4780483e4f5123c467cfec412af2efc20b8cd69a95fa26e74dabbf3` | same | yes |
| `directional_surface_cell_completion_tests` | `c6a3b371355273985ffd176689722fd2d4fbe8eee16f1881a8165f76ebc8e8c1` | same | yes |
| `directional_surface_cell_producer_tests` | `b4f98718e5959bf2cd4027c23c7556771eff74e9a400ef2688ce890ae59afc96` | same | yes |
| `directional_surface_cell_validation_tests` | `ff3d39fb7f5206058d8d1edd329741edbb9f772b6c8e7f86aafa6cc65236bf8d` | same | yes |

This closes `M3-CP4c3-TB2-REV-CAND-01` as a packaging-only substitution fact; it is not runtime product evidence.

### AN3 — package-relative fixture authority

The compile-time absolute `DIRECTIONAL_TEST_SOURCE_DIR` definitions were removed from test targets. `TestFixturePaths` no longer treats the builder's source directory as a fallback authority. Package 71 carries the immutable fixture tree at `test-data/benchmarks/fixtures`, beside the packaged binaries, with 27 fixture files and explicit `fixture-package-contract.txt` metadata.

Static package verification proved:

- both `mechanical_feature.obj` and `sphere_prescribed.obj` are present;
- the producer binary contains no `DIRECTIONAL_TEST_SOURCE_DIR` string or old absolute fixture-root suffix;
- packaged source contains no active `DIRECTIONAL_TEST_SOURCE_DIR` code reference outside historical documentation;
- binary hashes are unchanged by adding the fixture payload;
- the final package manifest verifies completely.

Package **68** did not ship a sibling `test-data` fixture tree; neither did semantic package 69. Fixture-only package 70 supplied that missing transport externally. Package 71 makes the package-relative root part of the normal artifact contract, resolving the build/packaging defect `M3-CP4c3-TB2-ORCH-01` for the successor package.

### AN4/AN5 — Amendment 16, P2

`FieldSingularityFact` now has an explicit `PortPolicy`. Slit-bound barrier singularities receive `BarrierAbsorbed`; ordinary singularities remain `Emit`. `build_singularity_attachments` does not construct a globally closed fan for `BarrierAbsorbed` singularities, and the field-aligned network producer neither counts nor emits ports for them. This resolves the prior contradiction where the same singularity was both bound to a slit boundary cycle and required to emit ports through a transport ring that cannot legally cross the barrier.

The strengthened compile-only regression contracts require the mechanical census to contain four `InteriorArc`, degree-2, two-star-component, `BarrierAbsorbed` rows, and require a prescribed singularity on a barrier arc to have no singularity-port attachments.

### AN6 — selector frozen; sphere untouched

No selector identity changed. Ordinals 367–373 remain byte-frozen and unexecuted. No sphere-specific correction was designed or implemented; AL4 remains binding until runtime provenance reaches ordinal 368.

### AN7 — successor retry rule corrected

TB3 keys an orchestration restart on whether the prior attempt **produced no semantic verdict**, not whether it executed zero Directional processes. Green processes followed by a harness/control blocker do not become a semantic checkpoint verdict.

### AN8 — assumption audit

The assumption audit was performed by behavior: *"this code assumes the transport neighbourhood is fully traversable."* The immediate closed-ring assumption is in `ordered_incident_fan` / `build_singularity_attachments`. Independently, `canonical_field_aligned_candidate` consumes singularity facts while assuming every singularity contributes `4-index` emitted ports; it does not touch the cut-mesh data structures. CB3 corrects that consumer through the explicit port policy rather than by supplying illegal barrier transport.

## Compile and package verification

Run `33370966957` used Ubuntu 24.04, GCC 13.3.0, CMake 3.31.6, Ninja 1.13.2, and ccache 4.9.1. `libgmp-dev` was `2:6.3.0+dfsg-2ubuntu6.1`. CMake proved `DIRECTIONAL_ENABLE_GMP=ON`, found `gmpxx` and `gmp`, and the generated authority-kernel test link command contained both libraries.

Preflight target `directional_core` compiled with exit 0, then all eight required targets compiled/linked with exit 0:

1. `directional_core`
2. `directional_pipeline`
3. `directional_surface_cell_authority_kernel_tests`
4. `directional_surface_cell_producer_tests`
5. `directional_surface_cell_completion_tests`
6. `directional_surface_cell_validation_tests`
7. `directional_compiled_api_tests`
8. `directional_benchmarks`

The source status was clean before configure, after configure, after build, and at packaging. The raw and final package manifests self-verified. Final package 71 records `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `exactArithmeticBackend=GMP`, and `compileTimeAbsoluteSourceFallback=false`.

## Frozen selector authority

The selector was not changed in CB3. Frozen hashes remain:

| Selector | SHA-256 |
|---|---|
| 355 prefix | `e9d88f1196e412e06424294d6be22b32f01c9671ec5e4de119abd3f2fb5afeaa` |
| 357 | `b896d0db7f26aeb0f3513418405efdeccbcf84fb6dc971500c6ddac9e364dc70` |
| 361 | `61918d9fbd7bf757437886f0e86776b60665c58e4d7283b81d42caca03c0288b` |
| 365 | `6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1` |
| 367 | `ef9d082f56f5c8de83124cf2e6257d098408cc597d9147b967cf9c84da4916bf` |
| 370 | `9160ea619afb9e10cbad30012d0bd354c263a2b749e690c271f653db3bf83525` |
| **373** | **`b47c269851fad1384b5dc9baaf674b3d4ad80ec6c2b40f7f8eda2055c6f44834`** |

No gate identity was executed in CB3. Stable regression accounting remains **44 events / 14 categories / 30 recurrences** and produced-witness debt remains **5**. Package 71 is the next semantic package, advancing authoritative semantic M3 package accounting from **69 to 70**.

## Verdict

**CB3 BUILD GREEN / RUNTIME-FREE.** Compilation and package portability are proved; Amendment 16 semantics are only compiled, not runtime-accepted. CP4c-3 remains **OPEN**.

## Mandatory successor

Execute `Architecture_M3_CP4c3_TB3_Artifact_Only_Test_Benchmark_Plan.md` against immutable package 71 exactly. Do not rebuild, relink, repair, regenerate discovery, or mutate the package. A 373/373 green selector plus immutable postflight closes CP4c-3; a valid semantic red keeps it open and routes to independent review/planning.
