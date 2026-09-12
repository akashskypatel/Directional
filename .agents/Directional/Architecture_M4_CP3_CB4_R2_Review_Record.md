# M4-CP3-CB4-R2-REV Review Record — replace nonexistent producer remap with the real A2b coordinate-basis seam

**Turn:** `M4-CP3-CB4-R2-REV`
**Decision:** `rejected_and_replaced`
**Boundary:** runtime-free Review; documentation/planning only
**Reviewed semantic source:** `190cb56e680dc02a91c743ccad61ca2ef10a6032`
**Review head before documentation:** `9329d6610ffbfbb9fe3f638a2aae7ce3be368fa7`
**Source drift check:** `190cb56e..9329d661` changes only durable docs; no `src/**`, `include/**`, `tests/**`, build, benchmark or selector bytes
**Accepted authority remains:** package119 / selector394 `394/394`

## 1. Verdict

The CB4-R2 STOP-GUARD is correct. The frozen `M4-CP3-CB4-R2` plan is not executable as written because it requires a production raw-row-barycentric -> canonical-barycentric remap at a seam where no such datum exists. A2a forms contact coordinates directly in canonical `SourceFaceTopologyKey` component order and A2b exact-path publication copies that canonical tuple.

The review therefore **rejects and replaces the CB4-R2 recovery plan** rather than weakening its guard or manufacturing a producer mapping solely for a test.

The broader row400 coverage concern is not withdrawn, however. Independent source review finds a real, different raw-row/canonical basis seam in A2b: `EmbeddedGraphTopology::vertex_trace_ray_second_point` returns boundary/vertex second points in `SourceFaceRecord::vertices` raw face-row order, but its terminal-contact branch returns `FieldAlignedTerminalContact::barycentric` directly even though that tuple is canonical topology-key order. `vertex_locus_secondary_parameter` then indexes the returned array by raw-row `corner/next/previous` positions. On a noncanonical face with distinct contact coordinates, that mixes two bases and can reverse the exact within-wedge parameter.

Exact successor: **`M4-CP3-CB4-R3`**, Code + Build only, under `Architecture_M4_CP3_CB4_R3_Code_Build_Plan.md`.

## 2. Independent re-derivation of the STOP-GUARD

The decisive producer path was re-read from source, not copied from the guard record:

1. `SourceFaceTopologyKey::make` sorts the three source vertex IDs (`src/authority/AuthorityKernel.cpp:33-39`). A raw source row can therefore differ from its topology key.
2. A2a `field_boundary_point_barycentric(SourceFaceTopologyKey, ...)` locates edge endpoint vertex identities inside `sourceFace.vertices()` and writes components at those canonical positions (`src/geometry/SurfaceCellTracing.cpp:244-263`). No raw face-row corner index is an input.
3. `classify_field_aligned_barycentric_contact` performs exact coordinate-wise arithmetic on those canonical arrays (`SurfaceCellTracing.cpp:1992-2039`).
4. `field_aligned_publish_contact` stores `event.sourceFace` and `event.barycentric` unchanged (`SurfaceCellTracing.cpp:3311-3393`).
5. A2b `exact_trace_segment_end` passes the same canonical `terminalContact->sourceFace` and tuple directly to `canonical_exact_source_face_point` (`src/geometry/EmbeddedGraphTopology.cpp:259-270`).

This path is canonical **before** face-interior coordinates are formed. There is no raw-row-attached face-interior tuple for CB4-R2 to remap. The plan's required subject therefore does not exist.

The guard's witness search is also upheld: the retained prescribed-sphere tests prove terminal contacts exist but do not independently specify an all-distinct contact tuple, and the explicit exact crossing oracle uses `(1/4,1/4,1/2)`. Inventing an expected all-distinct production contact from the observed result would be circular.

## 3. The actual A2b basis seam

`build_source_index` intentionally preserves the source face row's oriented corner order in `SourceFaceRecord::vertices` while separately storing its sorted `topology` key (`src/geometry/EmbeddedGraphTopology.cpp:53-85`). That raw order is then used for rotation-system angular ranking.

Within the same file:

- `field_boundary_point_barycentric(const SourceFaceRecord&, ...)` writes components at indices of `face.vertices`, i.e. raw oriented row order (`:1028-1045`);
- `source_vertex_barycentric` does the same (`:1048-1060`);
- `vertex_trace_ray_second_point` returns those raw-order arrays for reverse, edge-exit, continuation, terminal-point and vertex-fallback cases, **but returns `trace.terminalContact->barycentric` without conversion** for a terminal contact (`:1064-1117`);
- `vertex_locus_secondary_parameter` finds `corner` in raw `face.vertices`, defines raw `next/previous`, then indexes the returned second-point array with those raw positions (`:1130-1168`).

The terminal-contact branch is therefore the only branch in that helper that can supply canonical-key component positions to a raw-row-oriented consumer.

### Exact falsifier

The existing `make_four_triangle_fan()` fixture contains raw row 3 `[3,0,4]`; its `SourceFaceTopologyKey` is `[0,3,4]`. Take locus vertex `4` and a canonical terminal contact tuple keyed to `[0,3,4]`:

```text
vertex 0 -> 1/6
vertex 3 -> 1/3
vertex 4 -> 1/2
```

The raw oriented face order is `[3,0,4]`, so the same point in raw-corner order is `[1/3,1/6,1/2]`. For locus 4, raw `next=3` and `previous=0`; the frozen exact within-wedge rule therefore gives:

```text
expected = weight(vertex 0) / (weight(vertex 3) + weight(vertex 0))
         = (1/6) / (1/3 + 1/6)
         = 1/3
```

Returning the canonical tuple without remapping makes the raw indices read `1/6` as `next` and `1/3` as `previous`, yielding **2/3** instead. The values are all distinct, so the wrong basis cannot hide behind symmetry. This is a source-level, independently derived discriminator; no runtime was executed in this review.

## 4. Disposition of the prior row400 finding

`M4-CP3-TB2-REV-CAND-01` remains a valid test-authority finding: the old row400's `sourceRow{2,0,1}` is detached and cannot prove its advertised order-sensitive behavior. What changes is the corrective authority:

- **withdrawn:** the requirement that A2a/A2b exact-path publication itself consume a raw-row tuple and remap it; that seam does not exist;
- **retained:** the requirement for a noncanonical real source row, three distinct exact components, an independently derived vertex-identity expectation and a wrong-permutation falsifier;
- **replacement subject:** the actual A2b raw-row/canonical terminal-contact consumer seam above.

The old selector403 remains a historical unpromoted candidate. Its row400 identity must not be accepted as proof merely because it passed mechanically.

## 5. New candidate — `M4-CP3-CB4-R2-REV-CAND-01`

**Classification:** PRODUCT / COORDINATE-BASIS AUTHORITY MISMATCH / NON-STABLE / SOURCE-PROVED, RUNTIME-UNPROVED.

**Root cause:** one untagged three-component exact array is used in two different bases inside `vertex_trace_ray_second_point`: raw `SourceFaceRecord::vertices` order for boundary/vertex cases, canonical `SourceFaceTopologyKey::vertices()` order for terminal contacts. The downstream consumer assumes raw order for all branches.

**Falsifier:** on raw face `[3,0,4]`, canonical face `[0,3,4]`, locus `4`, and canonical contact weights `[1/6,1/3,1/2]`, production must return exact secondary parameter `1/3`; positional use of the canonical tuple returns `2/3` and must fail.

**Corrective owner:** `M4-CP3-CB4-R3`. It must remap only the terminal-contact tuple into the raw oriented `SourceFaceRecord` basis expected by this ranking helper. It must not change `FieldAlignedTerminalContact` storage, `ExactSourceFacePoint` canonical storage, A2a contact construction, A2b exact-path publication, topology keys, other ranking branches, A3 semantics or A4.

**Accounting:** no accepted-green runtime loss was observed. Stable accounting remains **47 events / 14 categories / 33 recurrences**, produced-witness debt **5**. Package119/selector394 remains accepted runtime authority.

## 6. Selector and package disposition

Selector403 was independently re-hashed from source:

```text
selector403 rows      = 403
selector403 SHA-256   = e8f4fe72cfbbd458289779125c7ff65d7344370df6a6fc98749b4ed9007de802
first394 SHA-256      = 6c27b3a0fc7259c5817bc9bbf41d5e2a23b7dd20f41fb75db8789abeb2cfba68
selector394 SHA-256   = 6c27b3a0fc7259c5817bc9bbf41d5e2a23b7dd20f41fb75db8789abeb2cfba68
first394 == selector394 byte-for-byte
```

Package120/selector403 remains **UNPROMOTED**. The future R3 selector keeps 403 rows and accepted first394 byte-identical, but replaces old row400's test name with the corrected A2b basis-seam regression. That necessarily gives the successor selector a new full SHA-256; the old selector403 hash remains immutable historical evidence and must not be edited in place.

## 7. Prior obligations

- `M4-CP3-TB2-REV-CAND-01`: **carried to CB4-R3**, with the corrective subject replaced as §4/§5 above.
- `M4-CP3-TB1-R1-REV-OBS-01`: **carried unchanged**; multiplicity weighting still has only `[1,1,1]` runtime evidence and remains outside this one-variable correction.
- `M4-CP3-CB4-REV-OBS-02`: **carried unchanged**; row399 path/`sourceFaces` consistency tamper remains outside row400 replacement.

No other prior review obligation is discharged or silently expired.

## 8. Successor

Exactly one successor is frozen: **`M4-CP3-CB4-R3`**.

Its plan must change only the one A2b terminal-contact basis conversion, replace the old row400 test identity with the exact discriminator above, derive a new 403-row selector from the historical selector403 by one name replacement, compile/package through the mandatory reusable GitHub workflow, and execute no Directional runtime. Future artifact-only validation remains row400 replacement twice + accepted selector394 + cumulative successor selector403 = **799 fresh processes**, followed by review before promotion.

A3->A4 cutover remains unauthorized until this corrected package is runtime-proved and reviewed.

Publication note: first documentation-apply run `34660476095` failed closed at `git diff --check` on Markdown trailing whitespace before any commit/push; the documentation bytes were corrected and the retry used a newly verified patch digest. Corrected documentation apply `34660555840` succeeded and pushed `fefca4c6498a4d147f2af966475fd9356c81c4dc`; cleanup `34660615718` succeeded and produced cleanup head `566b813a435e8d0fb604538445b7f73ee04aa242`. The consumed Drive patch was permanently deleted and temporary caller/marker state was retired. No repository semantic source changed in either publication attempt.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | selector403 first394 = selector394 = `6c27b3a0fc7259c5817bc9bbf41d5e2a23b7dd20f41fb75db8789abeb2cfba68`; selector403 = `e8f4fe72cfbbd458289779125c7ff65d7344370df6a6fc98749b4ed9007de802` |
| Decisive claims independently re-derived | re-read canonical A2a contact formation/A2b copy and independently traced the separate raw-row-oriented rotation helper; exact `1/3` vs `2/3` falsifier derived by vertex identity |
| Non-vacuity checked | all three weights are distinct; raw row `[3,0,4]` differs from canonical `[0,3,4]`; current positional basis mix predicts `2/3` while correct raw-oriented interpretation is `1/3` |
| Prior obligations discharged/carried | `TB2-REV-CAND-01` -> CB4-R3; `TB1-R1-REV-OBS-01` carried; `CB4-REV-OBS-02` carried |
| Stable accounting | `47 / 14 / 33`, debt `5`; accepted package119 / selector394 `394/394` |
| New candidates/obligations recorded | `M4-CP3-CB4-R2-REV-CAND-01`; tracker updated |
| ORIENTATION currency line | `M4-CP3-CB4-R2-REV`, 2026-09-11 |
| ORIENTATION §3 / §4 / §7 / §8 | §3 and §7 updated; §4 unchanged because witness runtime state did not change; §8 amended to distinguish nonexistent producer remap from the real mixed-basis consumer seam |
| CHANGELOG | review entry added |
| ROADMAP | CP3 status and successor updated |
| Selector manifest | n/a — Review may not mutate selector authority; CB4-R3 must add the successor selector entry |
| LESSONS | no new number; existing authority-domain/non-vacuity lessons 118/145/171 cover the defect class |
| Consolidation under CLEAN_UP_POLICY | n/a — no closed historical review document became eligible; this review record and its successor plan are active authority |
| Successor frozen | `M4-CP3-CB4-R3`; falsifier and stop rules in `Architecture_M4_CP3_CB4_R3_Code_Build_Plan.md` |
| Turn boundary held | runtime-free; no product/test/fixture/selector/build mutation |
| review_check.py boundary | **ALL CHECKS PASSED**; no product/test/fixture/build or selector mutation; durable markers preserved |
| Pushed to origin, branch in sync | corrected documentation apply and cleanup succeeded; closeout metadata is documentation-only; final branch authority is the latest PR #8 head verified after this record commit |
