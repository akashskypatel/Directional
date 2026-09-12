# M4-CP3-CB4-R3 Code + Build Plan — correct A2b terminal-contact coordinate basis and replace row400

**Status:** AUTHORITATIVE / FROZEN BY `M4-CP3-CB4-R2-REV` / RUNTIME-FREE PLAN
**Turn:** `M4-CP3-CB4-R3`
**Accepted runtime authority:** package119 / selector394 `394/394`
**Historical blocked candidate:** package120 / old selector403 `e8f4fe72...4206ed802`
**Owner candidate:** `M4-CP3-CB4-R2-REV-CAND-01`
**Future runtime boundary:** artifact-only `M4-CP3-TB2-R2-EXEC`, then `M4-CP3-TB2-R2-REV`

## 1. Objective

Correct one source-proved basis mismatch in A2b rotation ranking and replace the invalid row400 test-authority identity with a non-vacuous regression that exercises the real seam.

A2a terminal contacts remain canonical `SourceFaceTopologyKey` coordinates. A2b exact-path publication remains canonical and unchanged. Only the rotation helper that intentionally works in oriented raw `SourceFaceRecord::vertices` order may remap the canonical terminal-contact tuple into that local raw-corner basis before downstream wedge ranking.

## 2. Frozen semantic correction

### 2.1 Product scope

Only this semantic site may change:

```text
src/geometry/EmbeddedGraphTopology.cpp
  vertex_trace_ray_second_point(...)
  terminalContact branch only
```

The branch currently returns `trace.terminalContact->barycentric` directly. Replace that direct return with a vertex-identity remap from canonical `terminalContact->sourceFace.vertices()` positions into `face.vertices` positions.

Required invariant:

```text
rawSecondPoint[rawCornerOf(v)] == terminalContact.barycentric[canonicalCornerOf(v)]
```

for each of the three face vertices `v`.

Fail closed (`std::nullopt`) if the two vertex sets do not form the same three-vertex face or a mapping is not bijective. Do not add a general abstraction unless the existing function needs more than the direct three-corner loop.

### 2.2 Explicitly forbidden product changes

Do not change:

- A2a `field_boundary_point_barycentric` or contact-intersection arithmetic;
- `FieldAlignedTerminalContact` representation or public API;
- `ExactSourceFacePoint`, `canonical_exact_source_face_point`, or exact-path canonicality rules;
- `exact_trace_segment_end` / `exact_trace_path` publication;
- `SourceFaceTopologyKey` sorting;
- boundary/vertex/edge-exit/continuation/terminal-point/fallback branches of `vertex_trace_ray_second_point` except comments needed to state the shared raw-oriented return basis;
- A3/A4 logic, shared breakpoints, parity, hard-rail pairing, fixtures outside the test owner below, or build configuration.

## 3. Replacement row400 regression

Replace the old test identity

```text
ExactSourcePath.FaceBarycentricCoordinatesUseCanonicalTopologyKeyOrderNotSourceRowOrder
```

with one producer-owner identity whose name reflects the actual subject, e.g.

```text
EmbeddedGraphTopology.TerminalContactCanonicalBarycentricsRemapToOrientedSourceFaceForVertexRayRanking
```

in `tests/FieldAlignedCurveNetworkTests.cpp`.

The exact final test name is frozen by the Code + Build patch and must then be copied into the successor selector; do not rename again during TB.

### 3.1 Required fixture

Use the existing `make_four_triangle_fan()` mesh and its actual row 3:

```text
raw row     = [3,0,4]
canonical   = [0,3,4]
```

No new mesh fixture file is authorized.

Build the normal `SourceTopologyIndex` from that mesh/source authority. Use locus vertex `4` and the canonical face `[0,3,4]`. Construct a valid `FieldAlignedCandidateTrace`/`GlobalTopologyArc` shape already accepted by `vertex_locus_secondary_parameter` and terminate it with an exact face-interior `FieldAlignedTerminalContact` whose canonical vertex weights are:

```text
v0 = 1/6
v3 = 1/3
v4 = 1/2
```

All three components are positive, sum to one, and are pairwise distinct.

### 3.2 Independent oracle and falsifier

Derive expected secondary parameter by vertex identity and the oriented raw face row, not by indexing the production result:

```text
raw next from locus 4     = vertex 3
raw previous from locus 4 = vertex 0
expected                  = w(v0) / (w(v3) + w(v0)) = 1/3
```

The test must also compute/assert the wrong positional result of the current unmapped canonical tuple is `2/3`, proving the discriminator is live. The production call must return `1/3`.

Required assertions:

- raw row `[3,0,4]` is the actual row retained by `SourceFaceRecord::vertices`;
- canonical topology key is `[0,3,4]` and differs positionally from the raw row;
- the terminal contact tuple has three distinct components;
- the independently derived expected parameter is `1/3`;
- direct positional interpretation without remapping yields `2/3` and differs from expected;
- `vertex_locus_secondary_parameter` returns `1/3`;
- no unrelated branch supplies the second point.

The test may use a small test-local helper to look up a weight by vertex identity. It must not duplicate production rotation logic wholesale or derive the expected result from the production return value.

## 4. Selector authority

The historical old selector403 remains immutable:

```text
Architecture_M4_CP3_CB4_R1_Required_Green_Selector_403.txt
SHA-256 e8f4fe72cfbbd458289779125c7ff65d7344370df6a6fc98749b4ed9007de802
```

Create a **new** R3 selector file with exactly 403 LF rows by copying the old selector403 and replacing only row400's old test name with the replacement identity. Requirements:

- rows 1-399 and 401-403 are byte-identical to old selector403;
- first394 remains byte-identical to accepted selector394 at `6c27b3a0fc7259c5817bc9bbf41d5e2a23b7dd20f41fb75db8789abeb2cfba68`;
- owner totals remain `30 authority-kernel / 257 producer / 75 completion / 41 validation` if the replacement stays producer-owned as required;
- compute and record the new full selector SHA-256 after the final test name is frozen;
- update `Required_Green_Selector_Manifest.md` with the new candidate selector; do not rewrite historical old-selector metadata.

A selector edit in place, row-count drift, owner drift or prefix hash drift is a hard stop.

## 5. Scope and surgicality

Allowed semantic files:

```text
src/geometry/EmbeddedGraphTopology.cpp
tests/FieldAlignedCurveNetworkTests.cpp
.agents/Directional/<new R3 selector403 file>
```

Plus Code + Build plan/report/TODO/handoff/manifest/control documentation required by workflow.

No other production/test/fixture/build file may change. In particular do not opportunistically address multiplicity weighting, row399 path/sourceFaces tamper coverage, A3->A4 materialization or the prescribed-sphere blocker.

## 6. Compile/package — no runtime

After the exact patch is committed/pushed, compile only through the mandatory reusable GitHub Actions compile workflow with GMP/GMPXX authority. Do not build locally and do not execute any Directional binary.

Changed-owner preflight:

```text
directional_surface_cell_producer_tests
```

Then compile/package the complete selector-owner surface:

```text
directional_core
directional_pipeline
directional_surface_cell_authority_kernel_tests
directional_surface_cell_producer_tests
directional_surface_cell_completion_tests
directional_surface_cell_validation_tests
directional_compiled_api_tests
directional_benchmarks
```

Require compile/link exit 0, GMP/GMPXX verification, clean exact source provenance, all four selector-owner executables, recursive self-excluding manifest verification, executable modes preserved and `runtimeExecution=false`.

Do not run GTest discovery/listing, `ctest`, benchmarks, produced binaries, help/version commands, fuzzers or custom inputs.

## 7. Future artifact-only runtime gate

If Code + Build succeeds, freeze `M4-CP3-TB2-R2-EXEC` against that immutable package with exactly:

```text
replacement row400 focused A       1
replacement row400 focused B       1
accepted selector394             394
cumulative successor selector403 403
-------------------------------------
total                             799
```

Every process is a fresh exact filter. Require:

- replacement row400 `1/1 PASS` twice;
- byte-identical deterministic receipt/falsifier fields across the two focused processes if a receipt is emitted;
- selector394 `394/394 PASS`;
- successor selector403 `403/403 PASS`;
- zero RED/SKIP/selection mismatch/timeout;
- owner totals `30/257/75/41`;
- immutable package/source/execution-view pre/postflight and full manifest verification.

TB must verify from packaged source that row400 contains the real raw row, distinct canonical weights, independent `1/3` oracle and explicit `2/3` wrong-basis falsifier. Green runtime still requires `M4-CP3-TB2-R2-REV` before package/selector promotion.

## 8. Stop rules

Stop CB4-R3 before semantic commit if any of these becomes necessary:

- changing A2a contact representation or exact-path publication rather than the A2b consumer conversion;
- adding a product-only testing API;
- changing another branch of the ranking helper to make the test pass;
- changing a fixture outside the existing test file;
- weakening/removing the independent `1/3` vs `2/3` discriminator;
- mutating the historical selector403 file;
- selector count/prefix/owner drift;
- combining `TB1-R1-REV-OBS-01`, `CB4-REV-OBS-02`, A3->A4 or unrelated debt into the turn;
- executing runtime during Code + Build.

If the proposed direct three-vertex remap cannot satisfy the test without broader product changes, stop and return to review rather than broadening scope.
