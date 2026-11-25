# CB-207A / CB-207B exact manifest: QF1 quotient-forest cost (2026-11-25 UTC)

**Review artifact only.** No apply, build or runtime is authorized here. **Rescheduled by [TB-REV-185 adversarial](../Architecture_M6_CP3_TB_REV_185_Adversarial_Review_20261125.md) X1: CB-207A/B now precede CB-206, followed by behaviour-preservation gate TB-EXEC-187Q (all 1006 rows N1–N3-equal to TB185V) and TB-REV-187Q; preimage `57c22511…4a02` still equals HEAD.** Originally these turns sat on a separate product track, scheduled after the activation track (see the [adversarial review](../Architecture_M6_CP3_TB_REV_185T_Adversarial_Review_20261125.md) W3/W4). They replace the prose CB-205U.

## CB-207A `M6-CP3-CB-207A-QF1-QUOTIENT-FOREST-ADJACENCY-ONCE-PER-OWNER`

- **Exact diff:** [the diff file](../Architecture_M6_CP3_CB207A_QF1_Quotient_Forest_Adjacency_Once_Per_Owner_Exact.diff).
  - 7,279 B, SHA-256 `afcbe25b77152e29f6221b77053b9d3420dab116555a32376ef28aaaf775cfc7`, one path, +45/−21.
- **`src/pipeline/RemeshPipeline.cpp`:** `57c22511…4a02` → `e52e8dc4ff81fc0ab2fa01c2e6c50020563c6da95d27ed9b98cf42d7839c38d4`.

**What changes.**
- `quotient_forest_path` takes a prebuilt `QuotientForestAdjacency` (a sorted map of traversal records) instead of rebuilding and re-sorting the whole forest on every call.
- `add_quotient_forest_edge` inserts each edge's forward and reverse records at their `upper_bound` position, using the same `(next, relation, orientation)` comparator.
- Each of the three owners keeps its own lifetime:
  - **Producer:** one index, updated only at the `unite` success append. It is queried at the cycle-closing site and again for the final class paths.
  - **Publication validation:** one index built from the supplied forest after its existing edge validation, used by both call sites.
  - **Verifier:** one index built from the supplied forest, used for its path checks.

**Why the result is identical.**
- The comparator covers every field. `SurfaceOccurrenceRelationId` has a defaulted `<=>`, and `OccurrenceId` and `Orientation` are scalar keys. So equivalent records are identical, and a sorted insert produces the same list as appending everything and then sorting.
- The DFS, the reverse iteration, the parent discovery, path reversal, start==target, missing-path behavior, error codes and record order are all unchanged.
- No producer state is shared with the validators.

**Not changed:** class IDs, certificates, A7, tests, fixtures and selectors.

## CB-207B `M6-CP3-CB-207B-QF1-VERIFIER-FOREST-EDGES-BY-CLASS`

- **Preimage:** the CB-207A postimage `e52e8dc4…38d4`.
- **Exact diff:** [the diff file](../Architecture_M6_CP3_CB207B_QF1_Verifier_Forest_Edges_By_Class_Exact.diff).
  - 1,959 B, SHA-256 `523357c9b32633ebe21f9a0c6744b562c7ddf723f745df9a519b16956e53a279`, +17/−9.
- **Postimage:** `5da1fcc98dcb08b21279a3ba59ccd81861bc1f2fc3f2d2bf2ba3acd2c979dd03`.

**What changes.**
- `verify_records` used to rescan the whole forest once per class (K×F map lookups). It now buckets edges in a single pass, keyed by the class that owns both endpoints, preserving forest order.
- An edge lands in class C's bucket exactly when class(first) == class(second) == C. That is the old predicate, so each class sees the same edge list in the same order.
- The cardinality and spanning findings are unchanged.

## Checks done in Review

- `git apply --check` passes in sequence (205V, 207A, 207B).
- Syntax-only: `RemeshPipeline.cpp` at HEAD, 207A and 207B each has 0 errors and the same 31 warnings; no new diagnostics (adversarial review W5).
- No compile and no runtime. The static facts are not evidence of termination.

## Falsifiers

**Each CB:**
- Exact pre/post/diff hashes and a single changed path.
- Eight-target GMP/GMPXX compile, `runtimeExecution=false`.

**The later TB, after CB-207C:**
- Full gate, with no change to any accepted row: A6/A8 controls 8–12, 17, 25–27 and 35–36 must still pass.
- CB-207C must also add one test-only row that:
  - runs close_sheets through the production-default SurfaceCells pipeline (the `produced_network()` options);
  - prints N, K, R, F and the largest class size from the published quotient;
  - requires the run to finish organically.
- If that row still does not finish, the next turn is a bounded diagnostic of class sizes, not more cost fixes. A class with hundreds of members would be a separate semantic question.
