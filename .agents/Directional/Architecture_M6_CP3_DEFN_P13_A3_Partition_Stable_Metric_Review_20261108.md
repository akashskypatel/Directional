# D7 — Partition-stable A3 preferred metric and exact breakpoint contract

**Turn:** `M6-CP3-DEFN-P13-A3-PARTITION-STABLE-METRIC` · 2026-11-08 · independent source Review/definition; no product implementation, test execution, build, or accepted-prefix promotion.

## Authority and scope

TB88's immutable 910/910 MATCH (membership 991) establishes its specific observed-route oracle, **not** A3 producer consumption or correctness of a re-partitioned A3 metric. Accepted CP2 remains 491/491, stable regression accounting 66/17/49, debt 1, deferred ledger v5 81, selector497/CP3 unpromoted. This decision defines D7 only. D5 maximal-chain construction, D4 uniform/annulus consumers, D9c source-rim binding, D8 receipt and A4 construction are later independent work.

## Independent source finding

`src/geometry/GlobalConformityBaselineSupport.cpp:192–239` accumulates per-piece `squaredLength / midpointTarget²`, multiplies by the number of `supportPieces`, and rounds the square root (ties toward the smaller integer). Thus a uniform-size geometric route with normalized piece lengths (0.1, 3.9) yields `round(sqrt(2*(0.01+15.21)))=6`, whereas the same unsplit route yields 4. Subdivision is not geometric progress. Independently, `src/geometry/GlobalConformityBaseline.cpp:739–767` maps ordinal j to piece index using `m*j/count`: it assigns equal ordinal capacity to unequal-length pieces. The validator at `GlobalConformityBaselineValidator.cpp:845–875` mirrors that broken piece-index contract. Exact source-chart binding and positive counts remain valuable but do not fix either defect. These are confirmed source defects, not newly executed runtime regressions.

## Frozen D7 semantic contract (DESIGN §7.4)

1. **Authoritative geometric domain.** Each A3 `ConformitySpan` owns a consistently oriented, source-attached physical polyline with typed source component/sheet and its original source-entity carrier. `supportPieces` are only a representation partition of that path. A real bend, surface discontinuity, barrier, changed carrier or changed source sheet is not a representational split and must not be silently merged. Canonicalize admissible contiguous collinear splits and source-chart transitions, preserve every genuine physical vertex, and reject disconnected, zero-length, or ambiguous support fail closed.
2. **Physical-size density.** For a positive finite source target size h at each source vertex, define `rho_v = 1/h_v` exactly from the published target-size bits. On each source triangle interpolate `rho(p)` with its exact barycentric weights. This is a continuous piecewise-affine scalar over shared, consistent source edges, rather than taking `1/(interpolated h)` or taking midpoint h per arbitrary piece. A source-polyline segment must be split at actual triangle/physical-kink transitions before evaluation; any additional representational split must not affect the result.
3. **Additive metric.** Define the nonnegative integrated metric length `M(P) = integral_P rho(p) ds`. On one straight segment `(a,b)` inside an affine source chart, `M(a,b) = ||b-a|| * (rho(a)+rho(b))/2` (orientation invariant, additive under collinear subdivision). Sum across canonical source-supported segments with exact decisions: rational source coordinates and density with square-root/algebraic length as needed. Do not approximate, quantize, sample by piece index, or replace total length with a root-mean-square weighted by piece count. A mere representational re-split must produce the **identical** metric value.
4. **Preferred integer count.** Let `n_preferred = max(1, nearest_integer(M(P)))`, using the established tie-to-lower convention at exact half integers. This is an *objective* only; the existing positivity, parity, T-join and canonical lex-prefix optimization retain final scheduling authority. Counts must be the same for identical physical paths regardless of the number or ordering of representational support pieces.
5. **Exact physical breakpoints.** For the final scheduled count `n >= 1`, ordinal `j = 0..n` denotes the unique path point with cumulative metric length `j*M(P)/n` from the span's **oriented** start. `j=0,n` are exact physical endpoints. For interior ordinals, select the first canonical geometric segment reaching the measure, invert its strictly monotone integral, and return an exact/certified source-attached point. At an exact segment join, canonicalize by physical source entity rather than choosing an arbitrary preceding/following piece index. Reversal must map ordinal `j` to `n-j` at identical positions. The current rational `ConformityBreakpointLocation` (piece index plus local rational) cannot in general encode this inversion exactly; the CB must extend or replace that representation with a certified algebraic/implicit witness, or prove a logically equivalent exact implementation. An inexact approximation is **not** valid equivalence.
6. **Validation and identity.** The verifier must derive the cumulative measure and breakpoint membership independently of the producer, including the intermediate-ordinal source support, monotonic order, exact tiling, shared identical breakpoint identity, and endpoint ownership. Representation-only re-partitioning must not alter semantic hashes, scheduled count, canonical physical breakpoint identities or A3-supplied downstream authority. Physical path changes may change results. Reject any undecidable/exceeded exact bound with a typed failure; never claim synthetic success.
7. **Boundaries.** Keep all existing A3 single-writer and global parity/positive/T-join obligations. Do not introduce D5 chain grouping, D4 consumption, A4 fill, a new source-grid fallback, selector changes, or runtime execution in this definition.

## Scoped successor and falsifier matrix

**Exactly one authorized successor:** `M6-CP3-CB106-P13-A3-PARTITION-STABLE-METRIC` — implement only the D7 metric, exact breakpoint carrier, independent validator/oracles, and prescribed focused tests; compile/package only under the existing GMP/GMPXX workflow. A separate, not-yet-authorized Test + Benchmark turn must consume the immutable binary before any D7 acceptance. If exact algebraic comparison/representation cannot be implemented within existing exact-arithmetic limits without an unreviewed architectural change, **stop** and return to a Review; do not substitute floating/epsilon or coordinate rounding.

| Falsifier / oracle | Required discriminating outcome |
|---|---|
| Same straight route represented as 1, 2, 4 or 7 pieces | Identical exact M, preferred n, final n and canonical breakpoint source identities |
| Unit-target route λ=(0.1,3.9) and its single-piece representation | Preferred 4 in both; mutant old RMS-with-m formula yields 6 and must be rejected |
| Count 4 on short+long pieces | All three interior breakpoints at physical metric positions 1, 2, 3; mutant piece-index spacing detected |
| Varying per-vertex target on an affine source edge; re-split at arbitrary points | Exact integrated rho invariant; midpoint-h or nonadditive `1/interpolated-h` approximations rejected |
| Source-face crossing, different valid triangle row/order and carrier subdivisions | Same metric/canonical physical breakpoints, subject to fixed geometric path and sheet |
| Reversed oriented route and reversed piece order | Identical undirected breakpoint set; ordinal j maps to n-j; correct recorded orientation |
| Genuine kink, different physical route, barrier or source sheet | Not treated as equivalent; cross-sheet points never merged |
| Exact half-integer metric, very short positive span, invalid/nonpositive h, zero-length fragment | Tie down, positive min-one; malformed input typed fail-closed without injecting new interval |
| Two sides sharing one A3 span, odd/even parity-repaired schedules | Identical final scheduled IDs, count and breakpoints; T-join and lex-prefix never bypassed |
| Independent verifier mutant controls | Perturb one exact interior point, ordinal, carrier, density and measure independently; verifier fails for intended reason and is reached |

**Witness priority:** small synthetic exact rational-coordinate straight rail (both uniform and varying rho) first; then multi-face seam / close sheets; only then wider producer gates in a separate TB. Preserve existing frozen selector identities and scope/pinned digests unless independently justified by the later TB.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | n/a for semantic rebaseline: selector not altered; historical accepted CP2 491/491 and current TB88 910/910 membership 991 are retained, not independently rerun in this Review. |
| Decisive claims independently re-derived | Read exact code: m-weighted squared metric, exact tie rule and `m*j/count`; computed (0.1,3.9) case 6 versus 4; identified validator's corresponding broken oracle. |
| Non-vacuity checked | Old formula differs on a concrete two-piece witness and old index breakpoint differs on the same input; independent negative mutation cases frozen for the next CB/TB. No tests executed here. |
| Prior obligations discharged/carried | D7 definition specified, runtime remediation pending CB106/TB; D5 to 64B; D4 uniform/annulus to 64C/64D; D9c 65A; trace 65B; A4 disc 65C; receipt D8 65D; D6 user approval pending; P13-e and other M6 debts carried. |
| Stable accounting | No accepted-green loss or promotion; CP2 491/491, 66/17/49, debt 1, ledger v5 81; selector497/CP3 unpromoted. |
| New candidates/obligations recorded | Existing D7 root cause narrowed to additive physical metric, exact inverse and independent verifier; no new stable defect. |
| ORIENTATION currency line | D7 review-current wording prepared in same patch. |
| ORIENTATION §3 / §4 / §7 / §8 | §3 and §7 updated; §4 n/a because no witness changed runtime state; §8 adds existing piece-index representation pattern instance, no new stable category. |
| CHANGELOG | D7 runtime-free Review entry prepared in same patch. |
| ROADMAP | n/a: M6-CP3 remains active, no milestone promotion. |
| Selector manifest | n/a: no selector/source contract rebaseline. |
| LESSONS | Existing representation-not-breakpoint and producer/validator-oracle rules applied, no new lesson number. |
| Consolidation under CLEAN_UP_POLICY | No historical evidence deleted; one review decision and in-place durable current-state changes only. |
| Successor frozen | CB106 only, D7 metric and exact breakpoint implementation; falsifiers and stop rule above. |
| Turn boundary held | Static source inspection only; no generated Directional runtime/build/test, no implementation/test/selector mutation. |
| review_check.py boundary | Not yet verified on authentic Git history; snapshot excludes `.git`. Cannot claim PASS from a synthetic mirror. |
| `STATUS` lifecycle maintained | Initial in-progress beacon committed; final beacon follows actual durable publication status. |
| Pushed to origin, branch in sync | Not yet verified; patch publication and remote readback pending. No local `git status -sb` against actual origin is claimed. |
