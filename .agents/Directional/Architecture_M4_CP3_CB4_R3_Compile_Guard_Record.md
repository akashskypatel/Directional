# M4-CP3-CB4-R3 Compile Guard Record — semantic correction preserved; packaged-test contract blocks configure

**Turn:** `M4-CP3-CB4-R3`
**Status:** HALTED / STOP-GUARD / POST-MUTATION / SEMANTIC PATCH PRESERVED / CONFIGURE RED / NO COMPILE / NO RUNTIME
**Frozen plan:** `.agents/Directional/Architecture_M4_CP3_CB4_R3_Code_Build_Plan.md`
**Snapshot authority:** `463bcb9ab35f7b9941e03199c8ca0818b20db84c`
**Source-snapshot run/artifact:** `34662558179 / 10288520129`
**Snapshot artifact digest:** `sha256:c467d2fa754d45fedfbcb89e1b5668b93a41f191784950db2575e7332bfbe709`
**Semantic source commit:** `7fdc3c001de9193f8f94591d3e74d1c94c260195`
**Compile run / failed job:** `34663130547 / 103469632631`
**Failed preflight log artifact:** `10287418994`, provider digest `sha256:53488144ddedfea1d1e7eb98b57cc403ef93a22bd9260af1ea85747fc9b10fe3`

## 1. Outcome

The bounded semantic correction was implemented and preserved, but `M4-CP3-CB4-R3` cannot close under its frozen scope.

Commit `7fdc3c001de9193f8f94591d3e74d1c94c260195` contains exactly the intended semantic surface:

- the terminal-contact branch of `vertex_trace_ray_second_point` remaps canonical `FieldAlignedTerminalContact::barycentric` components by source-vertex identity into the oriented raw `SourceFaceRecord::vertices` basis used by the downstream rotation-ranking consumer, failing closed if the three-vertex mapping is not a bijection;
- row400 is replaced by `EmbeddedGraphTopology.TerminalContactCanonicalBarycentricsRemapToOrientedSourceFaceForVertexRayRanking`, using the real fan row `[3,0,4]`, canonical key `[0,3,4]`, independent correct result `1/3`, and explicit wrong-basis falsifier `2/3`;
- the new successor selector `.agents/Directional/Architecture_M4_CP3_CB4_R3_Required_Green_Selector_403.txt` has 403 LF rows and SHA-256 `c3f509afc823cd73761bdebea0d072d497acf5587a013cb52b795f273af70cb7`; its first394 remains byte-identical to accepted selector394 at `6c27b3a0fc7259c5817bc9bbf41d5e2a23b7dd20f41fb75db8789abeb2cfba68`, rows 1-399 and 401-403 remain byte-identical to historical CB4-R1 selector403, and owner totals remain `30 / 257 / 75 / 41`.

No runtime test, benchmark, produced binary, GTest discovery/listing command, or other Directional runtime was executed.

## 2. Compile STOP-GUARD

The mandatory changed-owner preflight checked out the exact semantic source `7fdc3c001de9193f8f94591d3e74d1c94c260195`, verified GMP/GMPXX authority, and entered the Release/static/PRE_TEST configure path. CMake then failed before any target compilation:

```text
CMake Error at cmake/DirectionalTests.cmake:115 (message):
  Mandatory packaged test contract
  FaceBarycentricCoordinatesUseCanonicalTopologyKeyOrderNotSourceRowOrder
  must have exactly one source definition; found 0
Call Stack (most recent call first):
  cmake/DirectionalTests.cmake:266 (directional_require_default_packaged_test_contract)
  CMakeLists.txt:387 (include)
```

The failure is deterministic and directly caused by replacing the frozen row400 identity while the mandatory packaged-test contract in `cmake/DirectionalTests.cmake` still names the retired test. The package job was therefore skipped and no compile artifact/package was produced.

This dependency is outside the frozen CB4-R3 semantic scope: §2 explicitly excludes build configuration, and §5 limits the intended semantic surface to product source, the owning test file, the new selector, plus bookkeeping/control records. Editing `cmake/DirectionalTests.cmake` now would broaden the frozen plan after its guard has exposed an omitted dependency. The turn therefore stops rather than silently widening scope or rerunning an unchanged compile.

## 3. Authority disposition

- The semantic commit `7fdc3c001de9193f8f94591d3e74d1c94c260195` is **preserved WIP**, not accepted compiled authority.
- The successor selector403 is **static candidate authority only**; it has no package or runtime proof.
- Package119 / selector394 remains accepted M4 runtime authority at **394/394**.
- Package120 / historical CB4-R1 selector403 remains mechanically **403/403** but unpromoted.
- Stable accounting remains **47 events / 14 categories / 33 recurrences**, produced-witness debt **5**.
- CP3 remains open and A3→A4 cutover remains unauthorized.

## 4. Exact next review question

**Exact next: runtime-free `M4-CP3-CB4-R3-REV`.** Review must independently re-open the semantic diff and compile evidence and decide exactly one bounded disposition:

1. amend/replace the successor Code + Build scope so the mandatory packaged-test contract in `cmake/DirectionalTests.cmake` is updated from the retired row400 identity to the replacement identity, with no unrelated build-system change, then recompile the preserved semantic source; or
2. reject/replace the CB4-R3 correction if independent review finds that changing the packaged-test contract would weaken or misstate the required-green ownership contract.

Review must not compile, run tests/benchmarks, mutate product/test/selector/build source, or promote either selector403. It must publish exactly one successor plan. The future 799-process artifact-only gate remains unreachable until a later Code + Build turn compiles and packages successfully.
