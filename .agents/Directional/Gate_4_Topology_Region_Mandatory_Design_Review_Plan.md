# Gate 4 Topology-Region Mandatory Design Review Plan

Status: **authoritative next turn**  
Turn type: **Review — mandatory by no-progress process guard**  
Active design gate: **G4 topology-distinct completion and singularities**

Optional review policy remains `never`; this review is not optional. It is required because two consecutive Code + Build iterations failed to establish accepted material runtime progress under their controlling acceptance conditions.

## Independence requirement

Use an independent reviewer/session/context that did not author the topology-region implementation or primary artifact-only validation report when available. The reviewer must inspect primary source/evidence rather than relying only on handoff summaries.

The review may modify planning/TODO/handoff documentation only. It must not edit production code, tests, fixtures, validators, benchmarks, or build configuration; it must not configure, compile, execute tests/benchmarks, or claim a fix.

## Validated source and evidence

Review exact validated implementation **`3ca89ab55efff461b050fb12033174be70e7464f`** packaged as artifact **`9022061741`**.

Primary records:

- `.agents/Directional/Gate_4_Source_Topology_Region_Isolation_Sheet_Decoupling_Artifact_Only_Test_Benchmark_Report.md`;
- `.agents/Directional/Gate_4_Source_Topology_Region_Isolation_Sheet_Decoupling_Code_Build_Report.md`;
- `.agents/Directional/Gate_4_Topology_Region_Materialization_And_Regressions_Code_Build_Proposal.md` (`proposed_pending_review`);
- `.agents/Directional/DESIGN.md`;
- `tests/TESTING_STRATEGY.md`;
- exact source diff for implementation `3ca89ab5...`;
- artifact evidence archive `directional-g4-topology-region-artifact-only-evidence.tar.gz`, SHA-256 `8f9666620d4fe732bce3319bcaa1a6c47cb85fcc5f453fd52b495100cf952265` when local evidence is available.

Entering accepted runtime baseline is artifact `9021175280`; candidate runtime evidence is artifact `9022061741`.

## Facts the review must preserve

1. Topology-region / isolation-seam focused semantics pass **9/9**.
2. Exact torus no longer fails at `InvalidBoundedDiskBoundaryTurn`.
3. Torus runtime diagnostics show four annular topology regions, eight internal isolation seams, local-isolation cardinalities `[1,1,2,1]`, four periodic relations, and first failure at `tracing/phase-front-materialization / InvalidAuthoritativePhaseFrontCell`.
4. The torus materializer still assumes one `sourceSheet` per cell; multi-isolation cells normalize to `sourceSheet=-1` and are rejected before trace-network context retention.
5. Embedded-relief retained authority regressed: global phase-front returns `NotApplicable` and generic traces instead of prior fail-closed `Rejected` behavior.
6. Close-sheets output remains strict-valid, two-component, and geometry-equivalent to the accepted output, but exact hash changes from `89b052762f52a5af` to `aaec5574aa2e52f9` because component emission order reverses.
7. The torus regression test's first `hasTraceNetwork` assertion aborts before its intended topology/seam diagnostics; classify this independently rather than automatically treating the fixture or product as wrong.
8. Producer suite is **124/127**, completion/simplification **154/164**, validation **60/60**, API **8/8**.
9. No fallback/recovery, validator weakening, Euclidean merging, feature demotion, arbitrary sheet-union search, or fixture-specific branch is permitted.

## Required review questions

### A. Is topology-region decoupling architecturally sound?

Determine whether the new first-class `SurfaceTopologyRegion` model should be retained or whether the producer needs a bounded replacement. Specifically verify:

- exact source adjacency is the correct producer continuity authority;
- local isolation labels remain the correct proximity/capture safety authority;
- hard features/genuine source boundaries remain true topology boundaries;
- internal non-hard isolation seams require exact reciprocal transport;
- topology-region aggregation does not create duplicate ownership or erase local-isolation provenance.

### B. How should embedded relief barriers interact with topology regions?

The review must resolve the current design ambiguity:

- Are embedded relief barriers topology-region separators, or internal authoritative transport barriers inside one producer region?
- If separators, what fail-closed aggregation rule prevents all-`NotApplicable` subregions from falling through to generic tracing?
- The observable prior contract must remain: non-embedded relief is guidance; embedded relief blocks authoritative traversal and cannot be bypassed through generic tracing.

Do not choose a rule solely to make the fan fixture pass.

### C. Is the close-sheets exact-hash regression a product defect or an invalid baseline assumption?

Inspect old/new outputs and ordering logic. Evidence shows geometry/face-geometry multisets are equal and only component emission order changed.

The reviewer must decide whether:

- the accepted exact hash is part of the deterministic source-authoritative API contract and region ordering must be restored; or
- the hash accidentally encoded incidental component order and the test/baseline should instead use a canonical component-order-independent structural identity.

No baseline may be changed merely because the candidate differs. Any proposed test/baseline correction requires independent contract justification and must preserve deterministic output requirements.

### D. What is the correct multi-isolation materialization model?

Review `build_authoritative_phase_front_mesh()` and related provenance structures. Decide the smallest complete migration from `(component,sheet,lattice)` authority to topology-region-aware materialization that still preserves local isolation provenance.

Questions:

- Should lattice/periodic vertex identity be `(component, topologyRegion, lattice)`?
- How should per-corner actual local sheets be validated against cell/region provenance?
- How is an output vertex represented when incident source corners belong to multiple local isolation labels?
- Does `SurfacePoint` need multi-sheet provenance, or should lineage carry an additional isolation-sheet set while `SurfacePoint` remains one exact source point?
- How does periodic quotient canonicalization select relations without representative single-sheet dependence?
- How are true barriers prevented from being materialized across?

No positional welding or arbitrary provenance choice is allowed.

### E. Is the exact-torus contract test correctly scoped?

Determine whether `ASSERT_TRUE(result.surfaceCellContext.hasTraceNetwork)` is required by a documented `retainIntermediateGeometry` failure-path contract or merely an implementation-detail assertion unrelated to the test name/purpose.

If over-coupled, approve a future correction that checks public topology-region/seam diagnostics and the absence of old partition failures while preserving the deeper materialization failure. If intermediate retention itself is a required public contract, prescribe a separate focused test and production fix rather than conflating it with torus topology advancement.

## Required decision

Publish exactly one of:

1. **Approved with amendments** — retain topology-region architecture and publish one revised authoritative Code + Build plan addressing all accepted regressions and the next torus materialization invariant;
2. **Rejected and replaced** — explain why topology-region architecture is unsound and publish a bounded producer-replacement plan with explicit preserved G0-G3/G4 contracts;
3. **Insufficient evidence** — authorize only bounded instrumentation/evidence work in the following Code + Build and define exact artifact-only validation needed before functional changes.

Do not approve another ordinary Code + Build that addresses only the torus materializer while ignoring accepted retained-authority regressions.

## Mandatory output of the review

The review must produce:

- one review report using the turn-based Review template;
- exactly one authoritative next Code + Build plan or bounded evidence/replacement plan;
- explicit disposition of the pending proposal `.agents/Directional/Gate_4_Topology_Region_Materialization_And_Regressions_Code_Build_Proposal.md`;
- build-only scope and approved targets;
- exact following Test + Benchmark acceptance criteria;
- TODO/MILESTONE/runtime-summary/handoff updates;
- PR #8 remains open, draft, unmerged.

The review turn must end with a new top-level PR #8 conversation comment as the final repository write. No GitHub write may follow it.

## Non-negotiable prohibitions

- no validator weakening;
- no count/order/frequency ownership selection;
- no arbitrary subset search;
- no fallback/recovery substitution;
- no synthetic counters/Euler correction;
- no positional merging across unrelated sheets;
- no Euclidean periodic seam welding;
- no fixture/ID special cases;
- no post-hoc cycle decomposition/cell merging;
- no timeout-as-correctness.
