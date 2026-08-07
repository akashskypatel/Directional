# Milestone G Production Readiness TODO

Last updated: 2026-08-07 UTC

## Current gate

G0 truthful authority [passed] → G1 uniform phase-front plane [passed] → G2 cross-chart / close-sheet isolation [passed] → **G3 cylinder / periodic holonomy [active; field-authoritative ring correspondence compile-valid, runtime pending]** → G4 topology/singularities → G5 adaptivity/features → G6 bunny/vase production success → G7 hardening.

## Latest executed G3 runtime authority

Artifact `9004509871`, source `2783ea718ffb15f8fb3868795173472ab8636c1c`:

- focused/retained producer contracts **13/13**;
- plane/seam/close sheets retain direct strict-valid deterministic passed outputs;
- cylinder periodic `Produced`, `r=0`, `t=(32,0)`, route 32, cut four, 2,237 traces, 320 direct quads / 352 provenance vertices, no fallback/recovery, deterministic 3/3;
- completion validation remains red: normal P95 `16.6272734366°`, field P95 `37.9670987281°`, warpage P95 `30.6213792811°`.

The exact field P95 matched the diagonal/sheared source-ring correspondence selected by incidental lexicographic candidate ordering.

## G3 ring-correspondence Code + Build complete

Final source authority:

- source/test commit `c5d2c90fc97ca2ae71bf2e8b50c8e7766c0bdb9a`;
- initial implementation commit `18f2c880f1714d8c41c9e11dadd53169756629fe`;
- initial patch SHA-256 `49cd71bc5aafc33ccdfd5e5104e5a23c7452e72074aac3c7775794f55737d6de`;
- compile-only test correction patch SHA-256 `8c96fa983990ab6c3f3ace5b24b8af59678aa7d6a0b7ed4f57b06f1397d1cd56`;
- final blobs: header `c1b816a584d67a3f74c2d7389962bd92d52244c9`, tracing `6980850bd32d40b1da9350ebbe3f601b8ce5e07b`, Phase10 tests `c4671ef674228d74b96e80499abbb6846bcdf3e3`.

Implemented bounded correction:

1. retain source-topology-compatible adjacent-ring candidate enumeration;
2. remove lexicographic `valid.front()` candidate ownership;
3. propagate branch/family state through each candidate strip using reciprocal `resolve_branch_transition()` authority;
4. score inter-ring edges against the transported field family and circumferential edges against its orthogonal family;
5. require a unique minimum field-authoritative candidate;
6. typed-reject no valid field candidate as `InvalidPeriodicRingCorrespondence`;
7. typed-reject field-equivalent best candidates as `AmbiguousPeriodicRingCorrespondence` instead of source-ID/order tie-breaking;
8. retain annulus applicability, true boundaries/cut, holonomy, artificial-cut ownership, source-strip breakpoints/subdivisions, exact quotient, provenance and one accepted cell → one quad;
9. add compile-valid contracts for exact axial field correspondence and genuinely field-ambiguous fail-closed behavior;
10. change no validator, fallback/recovery, fixture-specific or post-hoc repair behavior.

## Build authority

- successful run/job `31214404170` / `92984429773`;
- artifact `9008118764` (`g3-periodic-ring-correspondence-code-build`);
- artifact SHA-256 `11e9e50e59aaf71149594f791c5f4c6465ab452111427760cb2f0c9065fea562`;
- log artifact `9008117677`, SHA-256 `a4cd22bb4662edc290ad558d76e09af4b34a440f5803a5474af5dc68421a1a77`;
- recursive checksums **44/44**;
- compile/link **111/111**, seven approved targets;
- five executables, two libraries, 27 fixture/input files;
- Release static / Ninja / GNU C++ 13.3.0 / CMake 3.31.6 / `PRE_TEST`;
- `runtimeExecution=false`; no generated Directional binary executed.

The first bounded run `31213727511 / 92982293325` failed only while compiling the newly added Eigen test helpers after production source compiled. The test-source-only correction was applied and the successful build above supersedes it.

## Required next turn

Execute `.agents/Directional/Gate_3_Periodic_Ring_Correspondence_Artifact_Only_Test_Benchmark_Plan.md` against artifact `9008118764`.

Required order:

1. verify artifact/source/patch/blob/checksum/command-boundary authority;
2. execute the two new field-correspondence contracts and the six retained G3 periodic contracts first;
3. execute retained G1/G2 source-fan/close-sheet contracts;
4. revalidate plane, seam and close sheets;
5. execute exact cylinder as active G3 acceptance;
6. require direct periodic `Produced` `CompletedSurfaceCells`, zero validation failures, field/normal P95 <= 15°, warpage P95 <= 30°, correct cut/holonomy/quotient/provenance, no fallback/recovery;
7. run bounded determinism/default suites after the G3 decision;
8. observe bunny/vase afterward only as later-gate evidence.

Historical translation/grid/output counts are not acceptance constants. If cylinder closes G3, advance to G4. If field correspondence is consumed but another exact later G3 failure remains, preserve that failure and address only it next.

Review policy remains `never`. Every completed turn ends with a new top-level PR #8 comment after all other repository writes.