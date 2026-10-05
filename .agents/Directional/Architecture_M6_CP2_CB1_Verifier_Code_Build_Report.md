# `M6-CP2-CB1-VERIFIER` — Independent Verifier Code + Build Stop Report

**Disposition:** STOP FOR REVIEW / RA-28a §7 CONDITIONAL BLOCKER / NO REPOSITORY IMPLEMENTATION APPLIED / NO BUILD / RUNTIME-FREE.

## Authority

- Exact semantic source reviewed: `8bc1f52b22c1c429e8b5afdd8e3eb1fee67fc886`.
- Source snapshot: run/artifact `37328608018 / 11353700431`; 5,423/5,423 snapshot hashes previously verified.
- Branch changes after that semantic source are control-plane only (`STATUS`, source-snapshot mailbox/trigger history); source/test semantics are unchanged.
- Binding authority: `Architecture_M6_Frozen_Definitions.md` RA-28a §7 and `Architecture_M6_CP2_CB1_Verifier_Code_Build_Plan.md` stop rules.

## Stop condition

RA-28a §7 requires the CB1 report to prove that the representative `sourcePoint.face` belongs to the faces of the class `sourceCharts`, specifically by deriving `CornerPlacementProvenance.selectedFace ∈ cornerWedgeBindings`. If that precondition is unprovable, CB1 must stop for Review.

The precondition is **not derivable from the current A5/A7 contracts**:

1. A5 chooses `selectedFace` directly from `cell.corners[corner].face` (`src/pipeline/RemeshPipeline.cpp:4265-4280`).
2. A5 constructs `cornerWedgeBindings` independently from the incoming/outgoing side-span `interiorBinding` values and, for vertex support, the traversed wedge faces (`:4282-4423`). The selected face is not an input to that construction and no later A5 check requires it to occur in the resulting binding set.
3. Face-interior support is safe because incoming/outgoing bindings are required to equal the face support (`:4298-4307`), but edge and vertex supports have no equivalent selected-face membership invariant (`:4308-4423`).
4. The phase-front closed-boundary validator establishes only geometric endpoint coincidence; `validate_closed_boundary_paths` compares positions within tolerance and does not require the corner and boundary endpoint to use the same source face (`src/geometry/SurfaceCellTracing.cpp:7152-7171`). Therefore phase-front validity does not supply the missing face-identity implication.
5. A7 constructs each class `sourceCharts` only from member `cornerWedgeBindings` (`src/pipeline/RemeshPipeline.cpp:6800-6873`) while its representative `sourcePoint` remains the representative occurrence point. There is no A7 bridge that inserts or validates the representative point face against those chart faces.

Thus the class-wide optimizer predicate proposed by RA-28a §7 can rely on a relation that the currently accepted A5/A7 semantics do not publish or certify. Adding an A5 producer rejection/membership invariant, or changing the optimizer/verifier rule to a different admissibility relation, would change frozen semantics or introduce a new predicate. Both are outside this Code + Build turn.

## Work preservation

An exploratory local WIP patch was prepared while implementing the other CP2 verifier items, but it was **never applied to the repository** and must not be treated as candidate authority. Its preserved chat copy is:

- `Directional__M6-CP2-CB1-VERIFIER__base-8bc1f52b22c1__superseding-wip.patch`
- SHA-256 `2162f2b8b58b197c24dc5ab24d76778158e0d953bae0ed26c62a4a5aa7723713`
- diff-body SHA-256 `48c829c1db4cde54243bda769a90729d46ccd1133b722b5c46784307c87b45a3`

The WIP includes record views/verifier scaffolding, wedge identities 8–10 and the tentative optimizer membership change. Because RA-28a §7 fired, **do not apply or compile it before Review adjudicates the precondition**.

## Boundary

- No A5/A6/A7 semantics were changed in the repository.
- No CP2 focused-12 file was published to the repository.
- No compile/package workflow was started.
- No generated Directional binary, test, benchmark, discovery command, `ctest`, CLI, fuzzer or custom input executed.
- Reviewed runtime authority remains `11330703256 / 3f40f04a0e9d382b2ec82cf37a03c18ad405eb05`, 479/479.
- Accounting remains **60 / 16 / 44**, debt **1**; no runtime regression event exists.

**Routing:** require a runtime-free Review to adjudicate the missing representative-face/chart invariant and freeze a bounded correction or contract amendment. No exact successor ID is currently frozen; successor remains `UNKNOWN` until that Review is authorized by repository authority.
