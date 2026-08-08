# Gate 4 Field-Authoritative Polygonal Disk Boundary Phase — Code + Build Report

Date: 2026-08-08 UTC  
Turn type: **Code + Build only**  
Active design gate: **G4 topology-distinct completion and singularities**  
Review policy: `never`

## Compile record

Implementation **`085db9ec23ffaa509b1f5a29e72968229efa103d`** (`feat(surface-cells): model polygonal disk boundary phase`) compiled and packaged successfully. Payload cleanup is **`c3b5dcbcd0c35ee421d5b44273c142aa9f874dcc`**.

Exact artifact:

- ID **`9021175280`**;
- name `g4-polygonal-boundary-phase-code-build`;
- workflow run/job **`31254896323 / 93096734152`**;
- workflow event commit `c24af6c83ab25397df1c2bfc4692b91689502f85`;
- outer ZIP SHA-256 `16191e84bcfcebb2cfc1401b4aae7d5d8de2a02444f189a54d68164c1327a646`;
- internal `SHA256SUMS` SHA-256 `a8161eb579e1c06e63b5c7bc6203f610693f3e6259f56d8ce2c6ba78e424d3b5`;
- recursive checksums **48/48**;
- package 49 files / 27 fixtures / five executables / two project static libraries;
- dedicated log artifact `9021175444`, SHA-256 `170c8d869af4ec737250a1a5ce7dfb532ca76fbef972a696cea85a53c61b0f67`;
- Release/static/Ninja approved build **111/111**;
- GoogleTest discovery `PRE_TEST`;
- artifact metadata `runtimeExecution=false`.

No generated Directional binary, test, benchmark, `ctest`, discovery command, CLI/GUI command, help/list/version command, or custom-input command executed during Code + Build.

Final packaged Git blobs:

| File | Git blob |
|---|---|
| `include/directional/diagnostics/RemeshDiagnostics.h` | `9597c49693a1146e5dac2ac90270348b55a0c91d` |
| `include/directional/geometry/SurfaceCellTracing.h` | `0c1daa94300121df40c923716314ae6b242c7e8c` |
| `src/bench/DirectionalBenchmark.cpp` | `fd74cd39fff73bee7b4db578eb08382bd6ef50cf` |
| `src/geometry/SurfaceCellTracing.cpp` | `c834e8c81db04c39af9ecf1f45044ea107de3291` |
| `src/pipeline/RemeshPipeline.cpp` | `945bbc58bc56cb9838532889c616520cb234aaa3` |
| `tests/SurfaceCellsPhase10Tests.cpp` | `981b0f6e6fc935c1bfe3d1f6871736035d6bdfcb` |

## Implemented boundary-phase contract

The candidate introduced first-class `SurfaceBoundedDiskBoundaryPhase` / run authority with source-attached cyclic ordering, transported branch/family/sign, signed quarter-turn transitions, intrinsic lengths, exact source edge/face provenance, component/local-sheet ownership, source-boundary/hard-feature/cross-sheet provenance, cyclic index, polygon/chart state, structural hashing, and benchmark diagnostics.

The established four-run rectangle remains the fast path. Valid non-rectangular phases develop an intrinsic orthogonal polygon and deterministic positive-weight disk chart without inserting/deleting/merging/splitting runs or adding a synthetic closing edge. Invalid reciprocal turns and cyclic index fail typed. Generalized non-rectangular front pairing remains deliberately fail-closed as `InvalidBoundedDiskFrontPairing` after a valid chart is constructed.

## Runtime postscript — artifact 9021175280 validated

The following artifact-only Test + Benchmark turn has now executed this exact artifact. Detailed authority is in `.agents/Directional/Gate_4_Closed_Genus_One_Field_Authoritative_Polygonal_Disk_Boundary_Phase_Artifact_Only_Test_Benchmark_Report.md`.

Runtime results:

- new generalized polygonal boundary-phase semantics **5/5**;
- source-sheet/isolation semantics **3/3**;
- retained non-torus curved-disk semantics **5/5**;
- sheet coverage **3/3**;
- G4 periodic relations **5/5**;
- retained G0-G3 **17/17**;
- direct plane/seam/close-sheets/cylinder exact hashes unchanged and deterministic 3/3 with no fallback/recovery;
- exact torus deterministic 3/3 as `Rejected / InvalidBoundedDiskBoundaryTurn` before any bounded-disk phase record is retained;
- torus boundary-phase count, run count, polygonal phase count and constructed-chart count are all zero; phase hash list is empty.

Therefore the generalized representation is real, but the Code + Build did **not** meet its exact-torus material-progress condition. A changed reason alone is not progress.

Read-only exact-source reconstruction shows the failure is upstream of the polygon representation: local close/opposing-sheet isolation labels split one exact source-adjacent annular hard-feature region into multiple local labels. Production currently treats those non-hard classifier seams as exterior bounded-disk boundaries. The new turn validator correctly rejects the artificial corner created where such a seam meets a true hard rail.

The next correction is **not** to relax quarter-turn/index/alignment validation. It is to decouple source-topological producer regions from local isolation sheets while preserving exact source-adjacent reciprocal transport and G2 proximity isolation.

## Current next authority

Next Code + Build plan: `.agents/Directional/Gate_4_Source_Topology_Region_Isolation_Sheet_Decoupling_Code_Build_Plan.md`.

No-progress Code + Build count is **1**. If the next Code + Build's following runtime validation also lacks material progress, mandatory design review or bounded producer-replacement proof is required before another ordinary Code + Build iteration.

## Repository hygiene from this build

The six raw patch payloads were removed in cleanup commit `c3b5dcbcd0c35ee421d5b44273c142aa9f874dcc`. After artifact/source/checksum/log authority was verified, the bounded workflow was removed in commit `904c08652b167aac6bd34cfba77c771f2d7e0cc4`, then its trigger in `3d821f2942b9feeacaf169114305df68469686ed`. End-of-turn hygiene must continue to retain only the durable workflow and no temporary trigger/payload directories.