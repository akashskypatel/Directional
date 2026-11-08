# M6-CP3 P13 A4/A2b Review: A3 virtual-chain metric and breakpoint falsifier (2026-11-08)

**Turn:** `M6-CP3-DEFN-P13-A4-A2B-DISC-PRODUCER` (unfinished Review). **Source:** immutable snapshot `c54184c3caab9dfd37eab6653ae923e0a5c733e9`, GitHub Actions `42452191280`, `source.tar.gz` SHA-256 `b3746075d3ee05776a960023a3fa5c74290dfa6810756452bb42f3c1f88ced6a`. All calculations below are independently authored Python scratch, **not production C++ executions**, **not an A3 re-solve**, and **not a Vase A4 output**. Retain the prior [production contract audit](Architecture_M6_CP3_DEFN_P13_A4_A2b_Production_Contract_Audit_20261108.md).

## F1 — The current exact preferred-count formula depends on support-piece partition

In `src/geometry/GlobalConformityBaselineSupport.cpp:192-239`, production A3 calculates exact `E = m × Σ_i(||Δx_i||² / h_i²)`, `m` being the number of support pieces and `h_i` the average target at the two endpoints. It rounds `sqrt(E)` to the nearest positive integer via exact integer arithmetic. In `src/geometry/GlobalConformityBaseline.cpp:739-767`, internal breakpoint `j` for count `N` uses `q=floor(mj/N)`, `r=mj-qN`, giving piece `q` with interpolation fraction `r/N`, *without using physical/metric arc length*. These are the actual production algorithms, not the historical `GlobalConformityPlan` solver.

For one straight source-supported path of geometric length 3, with target size 1 everywhere, the independent exact rational mirror yields:

| Same exact path, support-piece boundary positions | E | Preferred edges | Geometric breakpoint positions |
|---|---:|---:|---|
| 0, 1, 3 | 10 | 3 | 0, 2/3, 5/3, 3 |
| 0, 1/2, 1, 3 | 27/2 | 4 | 0, 3/8, 3/4, 3/2, 3 |
| 0, 1, 2, 3 | 9 | 3 | 0, 1, 2, 3 |

All three are source-supported partitions of **the same line path**, and all are piece-continuous and positive. The count *and/or* its geometric distribution changes solely because the path is partitioned differently. This is a **counterexample to reusing these formulas unchanged in a proposed geometrically invariant maximal-Mandatory-chain scheduler**. It is not a demonstration of a defect against current §7.4, which explicitly schedules separate positive A2b arcs.

A stronger exact control splits only the length-1 portion of the same length-3 path into `k` equal support pieces, while retaining the adjacent length-2 portion as one piece. Then `E=(k+1)(4+1/k)` and the same rounding/interpolation gives:

| k | Preferred count | Internal breakpoints at x≤1 | Internal breakpoints at x>1 |
|---:|---:|---:|---:|
| 1 | 3 | 1 | 1 |
| 2 | 4 | 2 | 1 |
| 4 | 5 | 4 | 0 |
| 8 | 6 | 5 | 0 |
| 16 | 8 | 7 | 0 |
| 64 | 16 | 15 | 0 |
| 256 | 32 | 31 | 0 |

The preferred count grows without bound as `k` increases, despite the fixed path length and target size; eventually all internal breakpoints occupy the short length-1 portion, leaving the remaining length-2 edge without a breakpoint. This is a *mathematical* property of the old formulas on a coalesced chain, not evidence from Vase's actual A3 schedule. The Python scratch asserts path length, positive ordered endpoints, rounding, and the divergence pattern. Files: `Directional_A3_Chain_Invariance_Falsifier_20261108.py` (SHA-256 `2eff14161d30180bb150722907b9652c98adb6234020b9752e204a9fcf2d251b`), `Directional_A3_Chain_Refinement_Falsifier_20261108.py` (SHA-256 `be15bf1b2a34f63009d81871b9e88299f71b1857ecc89bd7d6f9aa1c1fd61e33`).

## F2 — Geometric scale of the phenomenon on the committed Vase boundary

A second source-only Python audit parsed `benchmarks/fixtures/milestone-g/vase.off` directly (1,274 vertices, 2,404 triangles), reconstructed the one 142-edge boundary cycle, and measured exact-input double geometry: perimeter **5.496458697412124**, edge lengths **0.0237357459 to 0.0555964973**, mean **0.0387074556**, coefficient of variation **0.23556**. At the **RA-213 mean target approximation** `h=0.0883`, treating the *entire rim as a hypothetical single open chain* gives geometric length/h **62.24755**, while the production support-piece RMS formula gives **63.95125**, nearest **64**.

A counterfactual split at three **arbitrary**, not A2b-certified, boundary positions (cyclic indices 0, 47, 95) gives candidate counts **20,22,22** under uniform `h`. These geometry checks reproduce the previously reported 142-edge rim and 5.4965 perimeter, but they **cannot** determine the true three A2b trace contact positions, the actual nonuniform target metric, or a true A3 chain solve. Never claim 64 or 20/22/22 as measured production A3 output.

## D5 decision required before any production change

The current §7.4 producer and independent verifier intentionally bind one positive scheduled span to **each original A2b arc**. Changing only the number of spans is not a safe implementation. A candidate chain contract must explicitly specify:

1. Which canonical A2b topological nodes delimit a *maximal Mandatory chain* and how every original directed source-support fragment maps to an ordered chain offset and to region boundary occurrences.
2. Whether per-original-arc positivity is replaced by **per-chain positivity**, with DESIGN §7.4 and the production independent validator revised together; never silently assign zero to original required spans.
3. A geometrically meaningful and representation-stable preferred-count metric, breakpoint coordinates, source-support carriers, and deterministic exact comparison/rounding policy. **Do not reuse** `m×Σl_i²/h_i²` or ordinal piece-index interpolation without first proving the intended invariance; the scratch above falsifies the naive combination.
4. The unchanged T-join parity constraint and canonical lexical tie-breaking on the *new* chain-to-region incidence graph, with a separate exact certificate verifier.
5. A4 consumption of shared Trace arcs with two opposite A2b occurrence owners, and source-boundary arcs with one exterior owner. Neither a digest-only A3 receipt nor a count-only check is adequate.

**Smallest independent next proof:** export the exact produced Vase oriented A2b disc boundary walks, A2a′ face-fragment orbit ownership, A3 original spans with support pieces and target metric, and actual breakpoint locations into a read-only Review scratch archive. Use that input to compare the actual baseline against one explicitly selected chain candidate and independently audit parity, exact source support and region-incidence reciprocity. Only after an admissible chain metric is chosen should an implementation slice be frozen. The retained abstract quad topology is not a source-attached A4 witness and does not validate D1.

**No changes** to product/tests/fixtures/selector/workflow/build logic or to the accepted CP2 491/491, stable 66/17/49, debt 1, or TB85 908/908 candidate. CB102 remains withdrawn. A D1 expected tier remains a recommendation pending user approval; no change to quality gates or boundary targets is authorized by this review.
