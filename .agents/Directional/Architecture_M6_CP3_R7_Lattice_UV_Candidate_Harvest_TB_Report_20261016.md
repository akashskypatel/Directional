# M6 CP3 R7 — pre-snap candidate harvest (artifact-only TB7)

**Turn:** `M6-CP3-TB7-R7-LATTICE-UV-CANDIDATE-HARVEST`. Runtime evidence complete; separate independent Review required. No repair authorization or stable regression promotion.

## Immutable evidence

- Semantic source: `cdd6dc4a9ba95a42aace6226194b38e712b53e4b`.
- Exact GMP/GMPXX compile package: artifact `12028682600`, SHA-256 `54b7f5a73ae7a041491fddef64807f71a9ac49f42c1508cea0ce64dfe61095d9`.
- Executor/harness commit: `f3ed82bc5d84953c4150429ee149e514644573d8`, harness SHA-256 `36b1fab3ab9a1b5aa6359df934e355c1f5a02451abf42b04b9e920e56d50a7d4`.
- Workflow [38861867717](https://github.com/akashskypatel/Directional/actions/runs/38861867717), artifact-only job `116846040090` succeeded; result artifact [12030150301](https://github.com/akashskypatel/Directional/actions/runs/38861867717/artifacts/12030150301), independently verified ZIP SHA-256 `de79aed888a2037ef2b2582fbfe68b28589a6a718c5beb70ac3b9bbfee16f9e6`. Internal `SHA256SUMS` all passed, and source/package/execution-view/selectors were byte-stable before and after.
- Execution: 44/44 selected, 44 RED (candidate historical failures, **not** newly accepted-green regressions), 0 missing, 96 endpoint evidence records, 0 parsing errors, final `exit=0`, `postflight=true`, `compile=false`, `relink=false`, `benchmarks=false`, `selector497=false`.

## Pre-snap producer result

| First A2b rejection | Occurrences | Endpoint | Producer | Sampled | Published | Original passing candidates | Published minimum? |
|---|---:|---|---|---:|---:|---|---|
| carrier-orientation | 21 | FirstTo | bounded-disk | 0 | 0 | {0,1,4} | Yes |
| carrier-orientation | 21 | SecondFrom | bounded-disk | 3 | 7 | {3,6,7} | **No** |
| not-same-interior-carrier-point | 27 | FirstTo and SecondFrom | no ambiguous probe | — | — | none | Not measured |

In every measured ambiguous endpoint, the **sampled** face equals the minimum passing candidate, including the 21 SecondFrom endpoints. The **published** face differs from the sampled one in precisely the 21 measured SecondFrom records. The producer code has an accepted-conformity boundary override after `point_on_periodic_chart` and before publication: the original chart-selected sample may be replaced by the already accepted boundary point. The diagnostic records both faces. The measured contradiction of post-snap published 7 versus initially selected 3 thus cannot be attributed to the initial candidate selector. The record does **not** independently prove that the subsequent boundary override is valid under the A2b endpoint/side-carrier authority.

The initial local exploratory run of 44 cases exceeded its separate 60-second execution allowance after only 16 log files, and it is **not** used as the full-set result. The complete result is the successful immutable GitHub Actions run above. An unrelated local Python execution failed before writing output because of file permissions; it was retried via the container and does not affect the remote evidence.

## Disposition and limitations

This is a **diagnostic Test + Benchmark** result, not a production-green gate. The historical 44 RED are a non-stable candidate vintage; no accepted-green loss is proven. Frozen M6 ledger **66/17/49**, debt **1**, CP2 **491/491**, R3 **403/497** rejected, 497-selector remain unchanged; `RP-02` remains UNREACHED. No producer, fixture, selector, compilation, link, or benchmark mutation occurred in TB7. An independent Review must adjudicate the override's source-entity and carrier obligations before a repair implementation is authorized. No automatic successor repair is declared.
