# T1 Independent Test-Oracle Foundation — Code + Build Report

**Status:** completed
**Turn type:** Code + Build only
**Production behavior delta:** none

**Date:** 2026-08-09 UTC
**Review policy:** `never`

- Phase: T1 independent test-oracle foundation
- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`
- Starting commit: `ccda7a0c55e38dc0ca7c5c9fa6b5e86bc82bbae8`
- Implementation commit: `6d1922dd57db76dcc4c19056fdd3573a713dde61`
- Workflow commit: `ff33afb34efedd5ee3093803d425d8f0025c5b8d`
- Build/event commit: `3c58cce124c72fa1926ffb580a0f04b6a84f373f`
- Workflow/trigger cleanup commit: `8d153ab4720b129a512cf755f3d77e5ab7738e13`
- Remote synchronization verified: yes; PR #8 remains open, draft, and unmerged

## Implemented

- Added one test-only public input/output oracle that independently rebuilds
  output schema, exact directed/undirected incidence, orientability, connected
  components, boundary loops, Euler characteristic, lineage coverage/source
  domains, and strict direct disposition.
- Added a canonical semantic record invariant to source/output row order and
  cyclic/reversed quad representation. It uses exact coordinates and
  reconstructed source-support positions, not raw row IDs, production hashes,
  patch ordinals, retained intermediates, or benchmark decisions.
- Kept the local scale-relative zero-area diagnostic explicitly separate from
  exact combinatorial identity.
- Added hand-authored positive and deliberate single-fact mutation contracts.
  Every test body records intent, proved precondition, stimulus, independent
  oracle, minimal counterexample/metamorphic transformation, and exact expected
  package/discovery identity.
- Augmented all six existing direct acceptance cases without removing or
  weakening any existing assertion.
- Added a default-built `directional_surface_cell_oracle_tests` executable with
  `contract-required;oracle-mutation` labels.

## Files Changed

- `tests/support/SurfaceCellProductOracle.h`
- `tests/support/SurfaceCellProductOracle.cpp`
- `tests/SurfaceCellProductOracleTests.cpp`
- `tests/SurfaceCellDesignAcceptanceTests.cpp`
- `cmake/DirectionalTests.cmake`
- this report and recovery/status records only

Production sources, public headers/API, fixtures, production validators,
tracing, arrangement, completion, optimizer, pipeline behavior, benchmark
quality decisions, and existing assertions are unchanged.

## Mandatory Repeated-Pattern Review

| Pattern | Touched? | Exact affected boundary | Corrective invariant / inspection evidence | Following counterfactual or representative evidence |
|---|---|---|---|---|
| `RP-01` | yes | `DomainIndex<SourceVertexDomain/SourceFaceDomain/OutputVertexDomain/OutputFaceDomain>`, topology count wrappers, lineage coverage maps | Test-side source/output/topology/lineage domains are distinct types; conversions occur only at matrix access. | out-of-range output/source indices and lineage-domain mutations must reject |
| `RP-02` | **yes, primary** | `inspect_surface_cell_product`, `directional_surface_cell_oracle_tests`, direct acceptance call site | The oracle reconstructs observable facts and does not call production success, `SourceAuthoritativeMeshValidator`, benchmark quality, producer helpers, or semantic hashes; target is default-built/labeled. | every named positive/mutation test must be packaged, discovered, and run individually; six direct cases must invoke it |
| `RP-03` | yes, observation only | strict disposition issue codes | Requested backend, executed backend, fallback, recovery, origin, and terminal failure remain independent observations; no production flag or policy changes. | backend/fallback/recovery/origin/terminal mutations reject separately |
| `RP-04` | no algorithmic growth | incidence/topology/canonicalization implementation | Bounded map/sort plus iterative BFS over supplied incidence; no recursion, backtracking, producer calls, or cumulative process state. | static inspection and bounded immutable runtime |
| `RP-05` | yes | `CanonicalProductRecord`, canonical vertex/face identities | Semantic record excludes row IDs, patch/local ordinals, backend operation, raw hashes, and traversal order; faces use cyclic/reversed canonicalization and sorted multisets. | combined source/output row permutation plus global face reversal/cycle must preserve the record |
| `RP-06` | no production storage | local oracle report/incidence | No production object changes and no per-consumer copy of global authority; temporary storage is bounded by supplied input/output incidence. | static inspection and package memory evidence |
| `RP-07` | yes | quad canonicalization and boundary graph | All four cyclic starts and both orientations are considered; boundary closure is rebuilt from undirected incidence, including wraparound edges. | reversed/cyclic duplicate rejects; permitted global reversal/cycle passes |
| `RP-08` | observation only | strict public disposition checks | The oracle records independent disposition facts and never reduces producer state or changes fallback policy. | independent backend/fallback/recovery/origin/terminal mutations reject |
| `RP-09` | no product resolver | public lineage-domain checks | T1 checks only public source-support shape/domains; it does not reconstruct, require, or bless chart/relation authority locally. | prohibited-symbol inspection remains clean; direct torus stays known-red and outside T1 mutation |

## Domain Invariants

- Topology identity is exact combinatorics; tolerances never join vertices,
  edges, faces, components, boundaries, or lineage identities.
- Every accepted output face has four valid distinct corners and a unique
  cyclic/reversed identity.
- Every undirected output edge has at most two incident faces; two-face edges
  are oppositely directed; every boundary vertex has degree two.
- Output topology matches the declared source topology policy.
- Vertex provenance, vertex lineage, and face lineage cover their public output
  domains exactly once and reference valid typed source domains.
- Direct product disposition requires requested/executed `SurfaceCells`, `Fail`
  policy, no fallback/recovery/substitution, completed-surface-cell origin, and
  no terminal failure.
- `result.success` remains an existing production assertion in direct tests but
  is not read by the independent oracle.

## Generalization Review

- Why this is not fixture-specific: no fixture name, expected output count,
  target size, row identity, raw hash, or benchmark path appears in the oracle.
- Valid input classes affected: any finite triangle source and public pure-quad
  result using the existing provenance/lineage schema; direct integration is
  limited to the six already authorized cases in T1.
- Regression risks considered: coincident but topologically distinct output
  vertices are not tolerance-merged; feature-interval and triangle lineage use
  distinct validation branches; nonmanifold and broken-boundary reports remain
  explicit even when topology expectations also fail.

## Test Intent Inventory

The source defines one independently valid minimal-disk control and named
mutations for source/output schema, finiteness, face arity/degree, index domain,
repeated/duplicate/zero-area faces, edge multiplicity, winding, boundary
incidence, topology, provenance, vertex/face lineage, disposition, and canonical
metamorphism. Exact GoogleTest/CTest identities are embedded in each intent
record and will be compared with immutable discovery in the following turn.

## Build

- Workflow run/job:
  [`31322039791 / 93266424347`](https://github.com/akashskypatel/Directional/actions/runs/31322039791)
- Result artifact:
  [`9040549377`](https://github.com/akashskypatel/Directional/actions/runs/31322039791/artifacts/9040549377),
  `t1-independent-test-oracle-foundation-code-build`
- Result artifact SHA-256:
  `06530ff55e63204a7685077862d935cfe24588237391765596a790759eea2097`
- Log artifact: `9040549498`,
  `t1-independent-test-oracle-foundation-code-build-logs`
- Log artifact SHA-256:
  `6b756784b98dc8532d905ef3869067ddf178e18501afd2fc29139c53a82c9a86`
- Recursive manifest: **51/51**, digest
  `9d3660f8764e57b59c890f0c8afb07e4dcf740e970328e1359acd1c48f61b260`
- Implementation patch SHA-256:
  `1447331ecf09660e3acf1fd757729913d62c1024b7771bbc0e9268f962d089a8`
- Source archive SHA-256:
  `9f3e4b845d5d44ee08a4b976ced302706129b958e3b3a5d3dcf84741a4386315`
- Compile database SHA-256:
  `1fa77cb933c96829d3c41fee73e072da6460c7eb9301e24e7865d2c902616885`
- Retention: through **2026-08-23 UTC**

The authoritative workflow configured Release, `BUILD_SHARED_LIBS=OFF`, Ninja,
and GoogleTest `PRE_TEST` with CMake `3.31.6`, GCC `13.3.0`, and Ninja `1.13.2`.
It used Eigen `769c72fd8019e389810d1de1e7c243521a43b594`, googletest
`3940de91897160fea4815998e08d0fa3c2fb077e`, and polyscope
`59da72df6517cab8379865899bdffdbc96171301`.

Exactly eight approved targets compiled and linked:

1. `directional_core`;
2. `directional_pipeline`;
3. `directional_compiled_api_tests`;
4. `directional_surface_cell_producer_tests`;
5. `directional_surface_cell_oracle_tests`;
6. `directional_surface_cell_completion_tests`;
7. `directional_surface_cell_validation_tests`;
8. `directional_benchmarks`.

Ninja completed **117/117** with exit status zero in **8:11.28** wall time
and a peak resident set of **1,836,172 KiB**. Local syntax/link checks also
passed before publication. No generated project binary, discovery command,
test, benchmark, `ctest`, CLI/GUI command, help/list/version command, or custom
input was executed; `runtimeExecution=false`.

## Artifact Verification

- Both downloaded ZIP digests match GitHub, and both ZIPs extracted cleanly.
- All **51/51** recursive checksum entries pass; the package contains 52
  regular files including the checksum manifest.
- Inventory is six valid ELF executables, two valid static libraries, all 27
  exact fixture files, compile database, implementation patch, dependency-free
  source archive, build logs, and authority metadata.
- The source archive reproduces the five recorded T1 source/CMake Git blobs,
  plus the packaged pre-build report/TODO blobs, exactly.
- The patch names exactly the five test/CMake paths plus the report and TODO;
  it contains no production source, public API, validator, fixture, benchmark
  acceptance, or pipeline change.
- The static oracle manifest declares the exact target, both required labels,
  and all **29** expected GoogleTest/CTest identities without discovery.
- The archived implementation tree contains only
  `.github/workflows/agent-source-snapshot.yml`; the temporary workflow and
  trigger were removed atomically after artifact verification.
- The build log ends at **117/117**, every workflow step exits zero, and the
  command boundary records `runtimeExecution=false`.

Compile success establishes only that the bounded source and tests compile and
link. Runtime semantic and mutation adequacy claims remain for the following
immutable Test + Benchmark turn.

## Known Risks

- The new oracle contracts and augmented direct cases have not executed in this
  turn; their runtime acceptance is intentionally unproven.
- T1 intentionally does not validate self-intersection, field alignment,
  approximation, calibrated element quality, full certificate consumption, or
  the expanded ten-case direct corpus; those remain T2–T5 work.
- `G4-R007` remains the entering known-red representative product baseline.

## Next Turn

Type: Test + Benchmark

### Commands

- Consume result artifact `9040549377` and log artifact `9040549498` exactly;
  verify both digests and `runtimeExecution=false` without rebuild or
  substitution.
- Discover the new oracle executable exactly once; run every positive/mutation
  contract individually, then the six existing direct acceptance cases.

### Acceptance Criteria

- Every deliberate mutation rejects for its named diagnostic.
- The valid controls and permitted row/cycle/reversal metamorphism pass.
- All six existing direct cases retain every prior assertion and also pass the
  independent oracle.
- Package names, labels, sources, and discovered tests match the immutable
  manifest; no production-validator coupling or assertion weakening appears.
