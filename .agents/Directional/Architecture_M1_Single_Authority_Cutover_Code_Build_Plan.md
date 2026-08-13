# M1 Single-Authority Cutover — Active Code + Build Plan

## Status

R-A remains **open**, but `R-A-TB3-CB-01` through `R-A-TB3-CB-04` are complete at the Code + Build boundary. Runtime acceptance is deliberately unclaimed until immutable artifact-only retry 4 executes the fresh package below.

Entering runtime authority remains M1l `bd140cff4572412e6f4ecd70a6ce0fe85310932c`.

Retry-3 runtime evidence remains the reason for this remediation:
- tested source `555109796188b318c788ef5777f622705ee0aa94`;
- runtime run/job `31667380356 / 94344731465`;
- semantic result **92 unique selected / 86 passed / 6 failed / 0 orchestration failures**.

## Code + Build result

Semantic implementation commit: `199b5aa85d02d8ef085161e3cdfe49f043e15ee1`  
Exact clean compile source: `aa16449577c48bac72257b7b9915e2b70dad3b82`  
Static inventory: **19 affected paths / 60 probes / 270 matches / PASS**  
Compile run/job: `31674780558 / 94366870676`  
Compile result artifact: `9171125667`, SHA-256 `0190d60057001cc2fdcb56f64e436b7bf4670bb7a571c0ae0f3af8a296594a83`  
Compile log artifact: `9171126075`, SHA-256 `bc54bd79251bc935a171d04cd81994f211096d060904341169ce6e5777442380`

The reusable compile workflow completed the approved Release/static/Ninja/PRE_TEST targets **118/118**, build exit `0`. The result package contains **26 files**, self-excluding recursive manifest **25/25**, exact source archive, and five empty source-status snapshots. Metadata records `runtimeExecution=false` and `semanticContracts=compiled-not-executed`. No generated Directional test, benchmark, discovery/listing command, `ctest`, CLI, fuzzer, help/version command, or custom input executed in this turn.

## Completed scope

### R-A-TB3-CB-01 — same-cardinality boundary-cache counterfactual

**Complete at Code + Build boundary.** The stale-cache counterfactual now explicitly allocates `boundaryNodeIdentities` to exactly `boundaryVertices.size()` before injecting stale valid identities. This makes the zero-rebuild assertion falsifiable for genuine same-cardinality stale content. The contract still requires every published boundary identity to be valid, equal to completion-owned canonical lineage, and free of the stale token. The independent missing-cardinality positive still requires rebuild count equal to completed-patch count. Production canonical cache rebuild logic was not weakened.

### R-A-TB3-CB-02 — feature-bearing completion and final-oracle authority

**Complete at Code + Build boundary; runtime verification pending retry 4.** Source tracing established that the explicit hard feature already reaches authoritative phase-front materialization. The downstream defect was reconstructing output feature sequences geometrically from rail-sample proximity even though phase-front materialization already publishes exact `PureQuadEquivalenceKind::HardRail` quotient-equivalence provenance on the output relation.

The production correction adds exact phase-front hard-feature projection:

1. collect authoritative hard rails by typed rail identity;
2. collect actual materialized output mesh edges;
3. consume `HardRail` equivalence provenance from output vertex lineage;
4. require each exact lineage segment to correspond to an actual output mesh edge;
5. deterministically assemble each rail as an open path or closed cycle;
6. keep malformed/missing relations typed and fail-closed;
7. retain geometric rail samples only for positional optimization rather than semantic feature membership.

The aggregate final-validation authority path applies the same exact projection when materialized quotient lineage is present. Failed component aggregation now preserves the inner producer stage, reason, validation issue, and indexed context. Completion validation records typed `MissingFeatureRail` when authoritative feature-rail validation is the failing invariant. No rail is synthesized in a test callback and no ownership, source-support, completion, or final-validator requirement was relaxed.

### R-A-TB3-CB-03 — guaranteed semantic provenance tamper

**Complete at Code + Build boundary.** The counterfactual no longer replaces barycentrics with `(1,0,0)`, which can be an unchanged valid source-corner certificate. It now preserves the baseline valid barycentric certificate and changes the source-attached `SurfacePoint.position`; a precondition asserts that the certificate actually changed. The expected strict validation issue is `SourcePositionMismatch`, with final-oracle fail-closed and zero semantic aggregate publication. Validator tolerances and coverage remain unchanged.

### R-A-TB3-CB-04 — static closure and fresh package

**Complete.** `R_A_Closure_Inventory.py` gained coverage for the exact materialized hard-feature lineage projection and regenerated its report at **19 / 60 / 270 / PASS**. Unexpected raw-projection leaves, face-count leaves, and pipeline `stitchIdentity` assignments remain zero; stitch-kind classifier self-tests pass. The exact compile source and package authority are recorded above.

## Mandatory next turn

Run immutable artifact-only **R-A retry 4** using `.agents/Directional/Architecture_M1_Single_Authority_Cutover_Artifact_Only_Test_Benchmark_Plan.md` against:

- exact source `aa16449577c48bac72257b7b9915e2b70dad3b82`;
- result artifact `9171125667`, SHA-256 `0190d60057001cc2fdcb56f64e436b7bf4670bb7a571c0ae0f3af8a296594a83`;
- log artifact `9171126075`, SHA-256 `bc54bd79251bc935a171d04cd81994f211096d060904341169ce6e5777442380`;
- compile run/job `31674780558 / 94366870676`.

Retry 4 must use exact immutable preflight/postflight, byte-identical regenerated static inventory, non-vacuous independent discovery, the complete R-A semantic selection, retained F2 completion/stitch reason evidence, and the CB-01/02/03 affected contracts. No rebuild, source/test/fixture mutation, permission/content repair, or package repair is permitted.

R-A closes only on an organic all-pass. Otherwise preserve exact evidence and return to another bounded Code + Build plan. R-B through R-G remain blocked behind R-A, and the full M1 artifact-only acceptance package remains dormant until R-A through R-G are complete.
