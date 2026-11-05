# O30 Review/Definition — first cross-platform divergence adjudication (2026-11-05)

> **Reviewed by [RA-204](Architecture_M6_CP3_DEFN_P13_Platform_Split_Review_Arrangement_Cell_Order_20261105.md).** The digest comparison stands. The field branch and the fixed-field replay successor are withdrawn:
> - the atlas digest hashes exact `effort` bits, so it and five later hashes are noise carriers;
> - macOS output does not change across five distinct Vase fields;
> - the split is arrangement cell ids that follow `std::sort`'s unspecified tie order (exact fix CB90).

**Turn:** `M6-CP3-DEFN-P13-PLATFORM-SPLIT`. **Disposition:** the frozen RA-203.4 `fieldBits` branch is selected. This review does **not** establish that the bitwise field difference causes the 45-quad count difference; a controlled fixed-field replay is still necessary. No product/test/fixture/selector/build mutation or runtime execution occurs in this turn.

## Authority and independent method

- Repository `akashskypatel/Directional`, draft PR #8, branch `agent/surface_cell_quad/p5-recover-bridge-healing`. Snapshot source SHA `a8bfcf7e38f693d1915543336aac850c20faba93`, source workflow run `41943529363`, artifact `13377162738`; artifact ZIP SHA-256 `0ef49bb5fe5a6cb07343f515a2cd4bd832f01572c8abae6c513dbb6bc83595f1`, inner source archive SHA-256 `b5262c4a3349c02dce62d1071287b548ab631a9fc929118eae3b7758f9e493f6`. Exact source SHA and archive hash verified in the local container, without building.
- Frozen macOS reference: [Architecture_M6_CP3_CB89_P13_Platform_Digest_macOS_Reference.tsv](Architecture_M6_CP3_CB89_P13_Platform_Digest_macOS_Reference.tsv), 129 data rows, SHA-256 `7e2796fe4991553becf1006d400f288368fe9c9781a6bc0d154faaaa821a167e` (RA-203.7). Linux: [Architecture_M6_CP3_TB79_P13_Platform_Digest_Full_Gate_Execution_Report_20261105.md](Architecture_M6_CP3_TB79_P13_Platform_Digest_Full_Gate_Execution_Report_20261105.md), four gate and three census digest lines. Each Linux line was independently parsed and compared by case/item/hash/count with the TSV; Cylinder's gate and census lines agree. No missing comparison field among the reported items.
- TB79 execution remains **899/899 PASS**, membership **980**, **1,806/1,806** gate hashes, **9/9** census hashes, seven digest lines, registered census **MATCH**. These are inherited TB79 evidence, not tests rerun here. Vase RED `SelfIntersectingFace`, 67,784 Linux completed quads; macOS 67,829. Both failed closed, not accepted output.

## Exact earliest mismatches

| Case | First differing item | Linux | macOS | Other observations |
|---|---|---|---|---|
| MultiFaceSeam | None | — | — | all 24 compared items match |
| Plane | `relief` | `b41394be2321cadb/24` | `0f8d74ab0c245329/24` | `fieldBits` match; six later product hashes differ |
| CloseSheets | `relief` | `14e153b4b075e5d5/40` | `0efc944855dbf4f2/38` | `fieldBits` match; ten later products differ |
| Cylinder (twice) | `relief` | `c66182ca3b9667b4/44` | `7442db60fa6fdc3e/44` | `fieldBits` match; six later hashes differ; eventual PASS retained |
| BunnyRandom | `fieldBits` | `03ee413ed128cbdd` | `76b1646be2449d43` | `source` agrees; both stop before field-transport product |
| **Vase** | **`fieldBits`** | **`5c9a34a47d717fdc`** | **`afdad15a6d246ed2`** | vertex/face/source bits agree; field-transport and later products diverge |

**Vase finer attribution:** The same 2,404 input face rows/vertices and source product are observed. The 2,404-element quantized `cross-field` product hash is **equal** (`8e16b454468fe056`) despite the exact raw-field-bit mismatch. `field-transport-atlas` first differs among **stage product** hashes (`9634dbd00b8015b2` Linux versus `2e362a754c773930` macOS), followed by `field-aligned-network`, topology plan, tracing, embedding, arrangement and completion. Arrangement element counts still both equal 26,817; their hashes do **not** agree. Completion is 67,784 versus 67,829 and its hashes differ. Previous aggregate-count agreement does **not** prove identical arrangements. Product hashes quantize doubles to 1e-9, so matching ones are not bit-exact equivalence.

## Source-level attribution, limits and selected direction

The test in `tests/SurfaceCellDesignAcceptanceTests.cpp` calls `load_benchmark_field` or `generate_benchmark_field`; the manifest sets Vase and BunnyRandom `generated_field: smooth`. `src/bench/BenchmarkCases.cpp::generate_benchmark_field` calls `fields::extract_cross_field` with normalization, combing and matching enabled. In `src/fields/CrossField.cpp`, the field producer creates `PCFaceTangentBundle`, solves a complex weighted sparse power system with Eigen `SimplicialLDLT`, stabilizes its solution, computes complex fourth roots and angle rotations (`std::pow`, `std::exp`), then performs principal matching and combing. **These are candidates, not diagnosed root causes.** The bit digest records generated `field.raw` **before** `remesh_from_raw_cross_field`; it is not a completion-stage digest.

RA-203.4 mandates the `fieldBits` branch: investigate inside `extract_cross_field`, not a `PureQuadCompletion` rewrite. Choose a **controlled frozen-input comparison first**, without replacing the existing smooth-field design-acceptance case. Making all floating-point field generation bit-identical across Apple/libc++/Eigen and GNU/libstdc++ stacks is not yet an evidence-supported small fix. A canonical field fixture may be an appropriate deterministic acceptance input, but switching an existing smooth case unconditionally would lose coverage of the actual generator and is prohibited without parallel coverage.

The exact necessary next experiment is: (1) capture one complete, finite, normalized 2,404×12 Vase `field.raw` matrix as exact IEEE-754 binary64 words (or independently verified round-trippable bytes) from one reference build; (2) replay **identical field bits** through the same unchanged `remesh_from_raw_cross_field` path on Linux and macOS, retaining the existing smooth-field case; (3) assert matching source/field bits before interpreting stage hashes; (4) compare all stage hashes, counts, terminal types and determinism over at least two independent processes on each platform. This is a discriminator, **not an acceptance test made easier to pass**. The next DEFN must obtain authoritative field bytes and independently verify which change, if any, actually removes the 45-quad split before specifying a Code + Build fix.

- If fixed-input replay yields equal completed counts and first divergent source stage disappears, the generator is a demonstrated upstream contributor; then choose either an invariant field producer with explicit 4-RoSy/matching contracts or a frozen acceptance field plus an independent generated-field portability gate. Record the remaining raw-field numerical variation separately.
- If fixed input still differs, the field-bit mismatch alone is **not a sufficient cause**; identify the earliest remaining stage divergence, then investigate that producer, not completion by inference.
- If `fieldBits` align but `field-transport-atlas` diverges, audit atlas transport, numerical tie handling and `long double` only with instrumented evidence; do not assume a cause from source inspection.
- If a fixed field changes a test's intended semantics, retain the original generated-field case and add a distinct control case; never silently replace coverage or weaken assertions.
- The separate Plane/CloseSheets/Cylinder relief divergence despite equal input field bits remains a **distinct observed portability issue**; do not claim O30's Vase generator route fixes it or promote global bit-exactness.

**Frozen successor:** `M6-CP3-DEFN-P13-SMOOTH-FIELD-PORTABILITY` (Review/Definition). It owns the raw-field controlled replay design and pinpointed generator stage measurements before an exact Code + Build patch can be authorized. Its falsifier is failure to establish identical replay input bytes or a fixed-input replay that still diverges in downstream topology; either forces a revised producer-specific hypothesis. Do not start P13-l orientation under this O30 turn. P13-l, P13-e and O27–O29 remain separately owned.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | n/a: no selector added or promoted; accepted CP2 491/491 remains unchanged; source snapshot cannot independently establish accepted historical prefix without full Git history |
| Decisive claims independently re-derived | Parsed seven Linux digest lines against 129 macOS TSV rows, compared 24/24 product fields for each complete gate case and 22 Vase items, including counts and first mismatches; verified snapshot and inner archive checksums |
| Non-vacuity checked | `fieldBits` could match (MultiFaceSeam), differ before products (BunnyRandom/Vase), or match with later differences (Plane/Cylinder/CloseSheets); the comparator distinguishes all three |
| Prior obligations discharged/carried | RA-203.4 discriminator discharged; O30 causal fix open; P13-l/P13-e/O27–O29 carried separately; no TB79 execution claimed |
| Stable accounting | 66 events / 17 categories / 49 recurrences, debt 1; accepted CP2 491/491; selector497/CP3 unpromoted |
| New candidates/obligations recorded | O30 root-owner narrowed to generated smooth field and subsequent atlas; fixed-field replay required; no new stable event |
| ORIENTATION currency line | Updated for current Review and next isolated DEFN |
| ORIENTATION §3 / §4 / §7 / §8 | §3 and §7 updated; §4 no witness outcome change; §8 existing platform-split pattern cited, no new rule |
| CHANGELOG | Entry added for this Review |
| ROADMAP | n/a: milestone remains active, no checkpoint change |
| Selector manifest | n/a: none created, revised or accepted |
| LESSONS | Existing RA-203 platform-count registration lesson reused; no new general rule claimed |
| Consolidation under CLEAN_UP_POLICY | Inventory of current RA-203, CB89 and TB79 authorities performed; all are live source/selector/review evidence, no safely superseded per-turn document identified for folding; historical deletion census unavailable in source-only snapshot |
| Successor frozen | `M6-CP3-DEFN-P13-SMOOTH-FIELD-PORTABILITY` with fixed-input falsifiers above |
| Turn boundary held | Review-only docs and external Python digest comparison; no product/test/fixture/selector mutation or build/runtime execution |
| review_check.py boundary | **PASS** exit 0 on genuine full-history checkout `513ae242d597214353e41b73758e9f3d5aa8c103`, [run 41947031233](https://github.com/akashskypatel/Directional/actions/runs/41947031233), artifact `13379501036`: frozen selectors hash-match, rewrite baseline ancestor, durable headings preserved 4/4, 1/1, 0/0, clean checkout; no source/test/selector/build mutation |
| STATUS lifecycle maintained | Entry and resume beacons published; terminal COMPLETE beacon will be the final repository mutation, outside this immutable document |
| Pushed to origin, branch in sync | Review documentation committed as `92e2e9ce81f29fe6f39c02b87494b8666b4c7509`; full-history CI checkout clean and descendant of that commit. Final status beacon is separately maintained as the last repository write |
