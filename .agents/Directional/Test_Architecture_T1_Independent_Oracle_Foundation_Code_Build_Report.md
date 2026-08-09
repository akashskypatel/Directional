# T1 Independent Test-Oracle Foundation — Code + Build Report

**Status:** implementation complete; authoritative compile/package pending
**Turn type:** Code + Build only
**Production behavior delta:** none

- Phase: T1 independent test-oracle foundation
- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`
- Starting commit: `ccda7a0c55e38dc0ca7c5c9fa6b5e86bc82bbae8`
- Implementation commit: pending
- Built commit: pending
- Remote synchronization verified: pending

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

- Targets: touched C++ translation units and standalone
  `directional_surface_cell_oracle_tests` locally; authoritative configured
  Release/static/Ninja targets pending
- Commands/workflows: C++20 syntax compilation of both new files and the
  augmented direct-acceptance file, followed by compile/link of the new oracle
  executable; bounded authoritative workflow pending
- Result: local compile/link passed; authoritative result pending
- Artifact identifiers: pending
- Tests or benchmarks executed: none

## Known Risks

- Compilation and package inventory remain unproven until the authoritative
  workflow completes.
- T1 intentionally does not validate self-intersection, field alignment,
  approximation, calibrated element quality, full certificate consumption, or
  the expanded ten-case direct corpus; those remain T2–T5 work.
- `G4-R007` remains the entering known-red representative product baseline.

## Next Turn

Type: Test + Benchmark

### Commands

- Verify the future immutable result/log artifacts and
  `runtimeExecution=false` without rebuild or substitution.
- Discover the new oracle executable exactly once; run every positive/mutation
  contract individually, then the six existing direct acceptance cases.

### Acceptance Criteria

- Every deliberate mutation rejects for its named diagnostic.
- The valid controls and permitted row/cycle/reversal metamorphism pass.
- All six existing direct cases retain every prior assertion and also pass the
  independent oracle.
- Package names, labels, sources, and discovered tests match the immutable
  manifest; no production-validator coupling or assertion weakening appears.
