# M4-CP3-CB4-R2 Derivation Guard Record — row400 recovery cannot satisfy frozen pre-mutation witness contract

**Turn:** `M4-CP3-CB4-R2`
**Status:** HALTED / STOP-GUARD / PRE-MUTATION / NO TEST OR PRODUCT CHANGE / NO COMPILE / NO RUNTIME
**Frozen semantic source before snapshot control marker:** `190cb56e680dc02a91c743ccad61ca2ef10a6032`
**Snapshot control head:** `fc5e59e3f52e30087b1a755e67701318d4a5b128`
**Source-snapshot run/artifact:** `34656852303 / 10286151896`
**Snapshot artifact digest:** `sha256:44ee51a6e08500b75d02dd6db31fefd9ed63729cc04084bb86f2be85ca4206ed`
**Inner source archive SHA-256:** `35e341692d8ae9e5478e1c9bba65915ede1ebe1befbf723f2da22c662950ee8f`
**Authority:** `.agents/Directional/Architecture_M4_CP3_CB4_R2_Code_Build_Plan.md` §3 STOP-GUARD

## 1. Outcome

The mandatory derivation guard does **not** close. `M4-CP3-CB4-R2` therefore stops before mutation exactly as its frozen plan requires.

Two facts are source-proved: a real source row can be noncanonical, and the A2a/A2b publication path carries face-point barycentrics in canonical `SourceFaceTopologyKey` order. The required discriminating witness is not source-proved: no existing production fixture/path in the accepted source supplies an independently known face-interior contact with three all-distinct exact components whose values originate in raw `TriMesh::F` row order and are then remapped by the production A2a/A2b path.

The current production contact path is canonical **before** the face-interior coordinates are formed. Adding a raw-row mapping helper to production, deriving the expected tuple from the observed production tuple, or duplicating the production contact-intersection algorithm in the test would manufacture the missing seam rather than test it. All three are outside the frozen correction.

## 2. Guard matrix

| Frozen guard fact | Result | Source evidence |
|---|---|---|
| 1. A real `TriMesh::F` row can differ from canonical face-key order | **PROVED** | `SourceFaceTopologyKey::make` sorts its three vertex IDs (`src/authority/AuthorityKernel.cpp:33-39`). The prescribed-sphere fixture contains zero-based face row 3 as `[1,5,2]`, while its canonical key is `[1,2,5]`. |
| 2. Chosen production fixture/path reaches an all-distinct exact interior point | **NOT PROVED** | The accepted prescribed-sphere test proves contact termini exist but checks only that the three components sum to one (`tests/FieldAlignedCurveNetworkTests.cpp:14621-14650`). The only explicit exact proper-crossing oracle in this owner uses `(1/4,1/4,1/2)`, which repeats two components (`:14460-14471`) and is not a production A2a/A2b publication witness. No retained source-side fixture expectation supplies an independent all-distinct contact tuple. |
| 3. Published A2b face point uses canonical topology-key component order | **PROVED** | `field_boundary_point_barycentric` indexes components by `sourceFace.vertices()` (`src/geometry/SurfaceCellTracing.cpp:244-263`); contact intersection works on those canonical tuples (`:1992-2039`); `field_aligned_publish_contact` stores the canonical `sourceFace` plus that tuple (`:3311-3363`); A2b `exact_trace_segment_end` passes them unchanged to `canonical_exact_source_face_point` (`src/geometry/EmbeddedGraphTopology.cpp:259-270`). |
| 4. Row400 can observe production publication without a product-only test API | **PROVED** | Existing `observe_cp4c_witness` obtains production `FieldAlignedCurveNetwork` / `GlobalTopologyPlan` snapshots through the normal remesh pipeline, and accepted sphere tests already inspect `terminalContact` values. |

Fact 2 is mandatory; the guard therefore fails even before considering implementation of the corrected assertion.

## 3. Deeper authority mismatch exposed by the guard

The intended row400 recovery assumes a production seam of the form:

```text
raw TriMesh::F row order + raw-row barycentric tuple
    -> production remap by vertex identity
    -> canonical ExactSourceFacePoint tuple
```

The accepted A2a/A2b contact path does not have that shape. `FieldBoundaryPoint` is converted to barycentrics only after it is paired with canonical `SourceFaceTopologyKey::vertices()`. Exact contact coordinates are then solved in that canonical coordinate system, stored canonically, and copied into A2b exact paths. Raw source-row component positions are not an input to this conversion.

That distinction matters for test integrity. A test can certainly take a canonical production result, permute it into raw-row order, and permute it back, but such an oracle would be derived from the subject and would stay green even if the alleged upstream remap seam did not exist. Likewise, a test-local reimplementation of the segment-intersection math would violate the frozen rule against duplicating a production algorithm wholesale merely to create the expected value.

## 4. Source/test mutations deliberately not made

No changes were made to:

- `tests/FieldAlignedCurveNetworkTests.cpp` row400 or any other test;
- `src/**` or `include/**`;
- CMake/build logic;
- selector403 or accepted selector394;
- fixtures;
- A3/A4 behavior or public API.

No compile/package workflow was started because §6 is reachable only **after** a valid bounded test correction is committed. No Directional executable, GTest process, benchmark, discovery/listing command, or other runtime was executed.

## 5. Required review question

**Exact next: runtime-free `M4-CP3-CB4-R2-REV`.** The review must independently re-open this source evidence and decide one bounded authority correction:

1. identify an already-existing, non-circular production witness that truly owns raw-row-attached all-distinct coordinates and can satisfy the frozen row400 intent without product mutation; **or**
2. amend/replace the row400 test-authority contract because A2a/A2b canonical coordinates are constructed directly in topology-key order and no raw-row-to-canonical remap seam exists there.

The review must not run tests or compile, must not mutate product/test/selector/build source, and must publish exactly one successor plan. Package119/selector394 remains accepted M4 authority; package120/selector403 remains mechanically green but unpromoted. Stable accounting remains **47 events / 14 categories / 33 recurrences**, produced-witness debt **5**, CP3 open, and A3→A4 cutover unauthorized.
