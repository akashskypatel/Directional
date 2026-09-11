# Future Chat Session Handoff — Directional

**Status:** `M4-CP3-CB4-REV` COMPLETE / APPROVED WITH AMENDMENTS / EXACT NEXT `M4-CP3-CB4-R1`
**Repository:** `akashskypatel/Directional`
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`
**PR:** #8, open / draft / unmerged
**Canonical next turn:** `M4-CP3-CB4-R1`, Code + Build / runtime-free

## Current authority

- M1-M3: CLOSED / ACCEPTED.
- M4 package119 / selector394 **394/394** remains the accepted runtime authority for the §17 production-baseline A3 scheduler/validator proof surface.
- Stable regression accounting: **47 events / 14 categories / 33 recurrences**.
- Produced-witness debt: **5**.
- CP3 remains open.
- `M4-CP3-CB4` correctly halted at its mandatory pre-mutation derivation guard: accepted public A2a′/A2b products did not publish enough exact split-arc path authority to bind all A3 spans without invention.
- `M4-CP3-CB4-REV` independently re-derived that gap from exact source and is **APPROVED WITH AMENDMENTS**. The old CB4 cutover plan is superseded.

## Review decision

The missing information already exists during A2b construction; the defect is where authority is published.

New normative §17.12 freezes the correction:

1. every accepted `GlobalTopologyArc` publishes a non-empty canonical exact ordered source path in `firstNode -> secondNode` orientation;
2. one upstream-neutral exact source-point/support-piece representation is shared by A2b and A3;
3. split `Mandatory` and `Cut` arcs publish their actual exact subintervals, while `Trace` arcs publish their exact ordered segment-support chain;
4. A2b candidate validation reconstructs expected support from source + accepted A2a/A2a′ authority and compares exactly; semantic hashing binds the path;
5. production A3 copies one A2b arc path 1:1 into one `ConformitySpanInput`; it does not reconstruct from parent edge, source faces, synthetic-node numbering, floating geometry or private construction state;
6. A4 remains unchanged until the new A2b→A3 boundary has artifact-only runtime proof.

This is an additive A2b publication/certificate strengthening. It does not change selected cuts, A2b arc IDs/order/topology, rotations, regions, disc certificates or accepted package119 parity-solver semantics. Historical M3 evidence remains valid for those unchanged semantics but does not prove the new support field.

## Exact next — `M4-CP3-CB4-R1`

Execute `Architecture_M4_CP3_CB4_R1_Code_Build_Plan.md` only.

R1 scope is deliberately narrower than the superseded CB4 plan:

- factor/reuse one upstream-neutral exact source path representation;
- publish exact support on every A2b `GlobalTopologyArc` for `Mandatory`, `Trace`, and `Cut`;
- independently validate/digest that support;
- derive exactly one A3 span per A2b arc by exact copy;
- construct and independently validate exactly one production `GlobalConformityBaselinePlan` immediately after A2b and publish it as an immutable stage product/diagnostic snapshot;
- add focused compile-only regression source for split cut/mandatory support, trace support, tamper rejection, canonical face-point mapping, 1:1 binder coverage and single-writer production reachability;
- append new required-green identities after accepted selector394 without rewriting its prefix;
- compile only through approved GitHub workflows with mandatory GMP/GMPXX and `runtimeExecution=false`.

**Do not** change A4 shared-boundary behavior, region-domain mapping, `HardRailPairKey`, floating `support_key`, target-derived shared subdivision, or the exact-torus pairing gate in R1. If A4 must change merely to compile the new boundary, stop and return to Review.

After a green R1 package, freeze/execute artifact-only `M4-CP3-TB2-EXEC` to prove the new A2b publication and production A3 binder. Only after TB2 Review acceptance may a later `M4-CP3-CB5` perform the final A3→A4 exact shared-boundary cutover using the still-valid downstream parts of the superseded CB4 plan.

## Current evidence and planning authority

- normative definition: `.agents/Directional/Architecture_M4_DEFN_Frozen_Definitions.md` §§17 and 17.12
- accepted runtime authority: package119 / selector394 **394/394**
- CB4 guard: `.agents/Directional/Architecture_M4_CP3_CB4_Derivation_Guard_Record.md`
- completed review: `.agents/Directional/Architecture_M4_CP3_CB4_REV_Review_Record.md`
- authoritative next plan: `.agents/Directional/Architecture_M4_CP3_CB4_R1_Code_Build_Plan.md`
- superseded plan: `.agents/Directional/Architecture_M4_CP3_CB4_Code_Build_Plan.md`
- review-entry semantic head: `26c6bbd481debc6f8f6b613aff1bb7e7fae40388`
- review snapshot control head: `0ac90cd1c1c70d15f99393b4f9b84c4d3246ccc3`
- review source snapshot run/artifact: `34635857254 / 10277961550`
- snapshot archive SHA-256: `52d6ea02c7d3936a87ac7362f60bf93e82135fcf51dd08d6f77e177b0f86e5fe`
- Review executed no compile and no Directional runtime.

## Context Load Plan

```yaml
load_next:
  - turn-based-coding-agent/references/turns/CB.md
conditional_modules:
  - trigger: implementation design / exact authority publication
    path: turn-based-coding-agent/modules/engineering-guidelines/MODULE.md
  - trigger: focused regression-source design
    path: turn-based-coding-agent/modules/unit-testing/MODULE.md
  - trigger: GitHub connector / workflow / patch transport / compile evidence
    path: turn-based-coding-agent/modules/github-connector/MODULE.md
deep_references:
  - .agents/Directional/Architecture_M4_CP3_CB4_R1_Code_Build_Plan.md
  - .agents/Directional/Architecture_M4_CP3_CB4_REV_Review_Record.md
  - .agents/Directional/Architecture_M4_DEFN_Frozen_Definitions.md#1712-a2b-must-publish-each-full-arcs-exact-ordered-source-path
  - include/directional/geometry/GlobalTopologyPlan.h
  - src/geometry/EmbeddedGraphTopology.cpp
  - include/directional/geometry/SurfaceCellTracing.h
  - include/directional/geometry/GlobalConformityPlan.h
  - include/directional/geometry/GlobalConformityBaseline.h
  - src/pipeline/RemeshPipeline.cpp
templates_when_producing: []
do_not_preload:
  - superseded CB4 implementation details except when checking a downstream carry-forward invariant
  - historical M3/CP1/CP2 reports
  - unrelated milestone records
```
