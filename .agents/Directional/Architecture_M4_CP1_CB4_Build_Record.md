# M4-CP1-CB4 Build Record

**Status:** COMPLETE / COMPILE+PACKAGE GREEN / RUNTIME-FREE / CANDIDATE NOT YET ACCEPTED
**Turn:** `M4-CP1-CB4`
**Semantic source / build evidence commit:** `680f9f1573d3c7e56a273366436463e40e196131`
**Corrected-docs inspection snapshot:** `577727925f11b5ecac8cab66dec55f6c9641422d`
**Candidate compile package:** package115, artifact `10159019500`

## Scope and result

CB4 is the package-closure control experiment prescribed by `Architecture_M4_CP1_CB4_Code_Build_Plan.md`. It changes
no M4 A3 product semantics, tests, fixtures, selector membership, CMake test ownership, or exact solver/validator
source. It rebuilds the exact CB3 semantic source while correcting only the package surface and pre-authoring the
successor artifact-only execution view.

The correction compiled successfully. The candidate package now contains every established selector-owner binary,
the package-owned source archive, complete checksums, and mandatory GMP/GMPXX evidence. No Directional binary was
executed in this turn, so package115 is compile/package authority only and is not an accepted runtime package.

The `M4-CP1-TB1-REV` §10.2 multi-coordinate `±2` oracle coverage obligation is deliberately **not** implemented here.
Per the corrected project authority, it is owned by the first later Code + Build turn authorized to change test source,
after CB4/TB2 establish package closure and execution-view integrity on unchanged semantics.

## Fresh source authority and static re-proof

The user-required corrected-docs source snapshot ran after the contradiction was repaired:

- corrected branch authority before trigger: `8359334da7cc1760bd52ee37c654751bc0a9058a`;
- snapshot trigger/source commit: `577727925f11b5ecac8cab66dec55f6c9641422d`;
- source-snapshot workflow run: `34493418743` — **SUCCESS**;
- snapshot artifact: `10158735895`;
- provider/downloaded ZIP SHA-256:
  `86f85fe9b2630343091aa38ebd427970aabaa6747e251c7c75e04e9ebaa91723`;
- embedded `source.tar.gz` SHA-256:
  `ca31e7f639245df1aa5f482d00ff92bfa1ba9311b18aaca5f542ca2a03c1f074`;
- snapshot metadata source: `577727925f11b5ecac8cab66dec55f6c9641422d`;
- file census/checksums: **5233 / 5233 verified**;
- snapshot boundary: `runtimeExecution=false`.

Against that verified snapshot, selector373 remains exactly 373 LF-normalized identities at SHA-256
`6d00cafa939a0e89c4816a6b0e8fec83232c0e7a94a468ae547b1667171e7d8b`. Re-deriving ownership from
`cmake/DirectionalTests.cmake` and the actual test definitions gives exactly:

| Owner executable | Selector rows |
|---|---:|
| `directional_surface_cell_authority_kernel_tests` | 30 |
| `directional_surface_cell_producer_tests` | 227 |
| `directional_surface_cell_completion_tests` | 75 |
| `directional_surface_cell_validation_tests` | 41 |
| **Total** | **373** |

There are **0 missing / 0 duplicate** identities. The first 365 rows partition as **30 / 219 / 75 / 41** and rows
366-373 are all producer-owned. No source was moved between owners.

## Mandatory compile/package evidence

The compile caller used the durable `agent-compile-reusable.yml` on exact semantic source
`680f9f1573d3c7e56a273366436463e40e196131`. The caller supplied no cache epoch, namespace, or compatibility key and
did not alter reusable-workflow permissions.

- caller trigger/control commit: `c08cce7b4f929fa7f4807bc74816f1ffdc16af8d`;
- workflow run: `34493860436` — **SUCCESS**;
- compile job: `102927319825` — **SUCCESS**;
- SchemaStore validation job: `102927218145` — **SUCCESS**;
- compile result artifact: `10159019500`, `m4-cp1-cb4-package-result-34493860436`;
- provider/downloaded artifact SHA-256:
  `de391c44744d83622dee30cf3a78f781c3b9ad95f0b517a866e7285e77a6b45b`;
- compile log artifact: `10159020375`;
- log provider/downloaded SHA-256:
  `5c024e58867b10c32b0e5868e574515b4f89b22893c62645ecbd06e96747d441`;
- build exit: `0`; preflight exit: `0`;
- boundary: `runtimeExecution=false`, `turnBoundary=Code+Build-only`,
  `semanticContracts=compiled-not-executed`;
- exact arithmetic: `DIRECTIONAL_ENABLE_GMP=ON`, linked `libgmpxx` and `libgmp`,
  `exactArithmeticBackend=GMP`;
- package `SHA256SUMS`: **all entries verified**;
- packaged source archive SHA-256:
  `169c403e7a559403574ac4cef9a2f30f1aeb8f033547bea168ea64e34548c983`;
- all recorded source-status files are clean.

The reusable default target set compiled successfully:

- `directional_core`;
- `directional_pipeline`;
- `directional_surface_cell_authority_kernel_tests`;
- `directional_surface_cell_producer_tests`;
- `directional_surface_cell_completion_tests`;
- `directional_surface_cell_validation_tests`;
- `directional_compiled_api_tests`;
- `directional_benchmarks`.

The four frozen selector-owner executable receipts are:

| Executable | Mode | Size (bytes) | SHA-256 |
|---|---:|---:|---|
| `directional_surface_cell_authority_kernel_tests` | 755 | 2,999,752 | `5efacc3ad52085a8ab76bad451bfc70c337e44a73a8f81a165f06ab1cd3041b3` |
| `directional_surface_cell_producer_tests` | 755 | 15,324,320 | `5b1064e6025b052aed7aeee66b8e1c3f6218bc73791d55fed4675484f4ea2afd` |
| `directional_surface_cell_completion_tests` | 755 | 6,308,680 | `1701820d85d91fe674cb3dd3496669f0a49ca43e6068a170fb0277227aba094a` |
| `directional_surface_cell_validation_tests` | 755 | 3,579,472 | `303af6ab231bf88b6b618df03315c9999a27595b8b55871922935f5098a4ca5f` |

This statically closes the 146-owner-omission side of the TB1 package defect. Runtime evidence is still required to
show that the corrected execution view also removes the 38 pre-assertion fixture-root failures.

## Successor artifact-only harness

CB4 adds `.agents/Directional/tools/m4_cp1_tb2_artifact_only_harness.sh`, a bounded adaptation of the retained M3
artifact-only pattern. Static checks only were performed in CB4: `bash -n`, `git diff --check`, selector/owner-map
re-proof, and source-path inspection. **The harness itself was not executed.**

Harness SHA-256:
`ddfbda2ff626008d3d2e9f6d117b10c98de159c4f9b8a3a36f99e50e24fd22d9`.

Before any Directional process, the harness is required to:

- bind artifact ID/name/provider digest/downloaded ZIP digest and exact semantic source;
- verify package `SHA256SUMS`, GMP/GMPXX metadata, and source archive;
- re-derive the 373 identity-owner map and require 30/227/75/41 with exact-once ownership;
- require all mapped binaries executable;
- create a fresh execution view only from package-owned binaries and source-archive fixtures;
- reproduce the existing sibling/legacy `TestFixturePaths.h` contract and resolve a known fixture;
- census package, source, and execution view before runtime and require identical postflight censuses;
- fail closed on zero/multiple owners, missing binaries, selection mismatch, missing fixture root, timeout, or mutation.

The execution path then runs rows 366-373 twice, followed by rows 1-373 one identity per fresh process through each
identity's mapped owner. It does not compile, relink, repair the package, mutate fixtures/tests/selector, or use the
runner checkout as semantic source authority.

## Engineering-guideline review

- **Assumption:** CB4 may change only package/harness/control/documentation surfaces. Confirmed by the corrected CB4
  plan and handoff.
- **Simplest sufficient correction:** use the reusable compiler's existing default target set rather than inventing a
  turn-specific owner target bundle, and adapt the already-proven artifact-only execution-view pattern.
- **Why no smaller correction works:** package114 physically lacks three required owner executables and its launch view
  lacks the fixture root; neither can be repaired in place without destroying the control experiment.
- **Scope discipline:** no production, test, fixture, selector, CMake ownership, solver, or reusable-workflow-permission
  change was made; no unrelated refactor or formatting pass was performed.

## Runtime and acceptance authority

No Directional executable, gtest discovery/listing command, test, benchmark, selector run, or CLI ran during CB4.
Therefore:

- package115 is **candidate compile/package evidence only**;
- M3 package113/TB48 remains reviewed semantic runtime authority at selector409 **405 PASS / 4 RED / 0 SKIP**;
- accepted required-green authority remains selector365 **365/365**;
- stable accounting remains **47 events / 14 categories / 33 recurrences**, debt **5**, accepted packages **113**;
- package114 remains immutable unpromoted failed-gate evidence.

## Mandatory successor

Exact next is **`M4-CP1-TB2-EXEC`**, artifact-only, consuming package115 artifact `10159019500` and the exact harness
above under `Architecture_M4_CP1_TB2_Test_Benchmark_Plan.md`.

A complete 373/373 PASS with focused 8/8 PASS twice and all integrity/selection/postflight checks green may close
M4-CP1 under the standing turn policy. Any genuine assertion-level RED routes to independent Review + Plan. A
pre-runtime owner/binary/fixture/integrity failure is orchestration failure and creates no semantic runtime result.
