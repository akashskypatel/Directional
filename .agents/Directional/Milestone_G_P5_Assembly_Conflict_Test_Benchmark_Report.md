# Milestone G P5 — Assembly Conflict Test + Benchmark Report

**Turn type:** Test and benchmark only  
**Artifact:** `8841726806`  
**Exact compiled source:** `053fe3816f585320e65526824f1107b8ccb1332d`  
**Rebuild performed:** No

## Disposition

This report remains the authoritative runtime input for the completed same-corner code/build turn.

P5-TB7 established:

- source-support remediation reached assembly;
- all 21,297 descriptors completed;
- the deterministic terminal conflict was `firstPatch=8595`, `secondPatch=8573`;
- both claims were closed-form variant zero;
- domain and complete boundary identities differed;
- source support and canonical stitch/authoritative corner cycles matched;
- four prior completion attempts did not remove the claim;
- no recovery, fallback, or partial output occurred.

It also identified two invalid regression scenarios:

1. generated-interior escape used a face still inside patch support;
2. parity fixture had valid DCEL incidence but incomplete authoritative topology/geometry evidence.

Those findings were addressed by P5-CB21 through P5-CB26. The resulting compile-valid artifact is `8842377256`; runtime acceptance now belongs to P5-TB8.

## Original P5-TB7 test result

| Scope | Passed | Failed |
|---|---:|---:|
| Focused intrinsic-support/canonical/parity subset | 5 | 2 |
| `PatchDescriptorMilestoneE.*` | 14 | 1 |
| Phase 16 + Phase 18 | 86 | 1 |
| Phase 14–18 aggregate | 226 | 1 |
| Milestone G P23 + Phase 20 | 52 | 0 |

Authoritative non-overlapping total: **292/294 passed**.

## Original random-bunny conflict

```text
DuplicateStitchedQuad:firstPatch=8595;firstLocalQuad=0;
secondPatch=8573;secondLocalQuad=2;
globalVertices=10764,16938,27456,27459;
classification=completion-template
```

Two independent processes matched on terminal failure, descriptor/endpoint counts, context-product hashes, and all stage structural hashes.

## Original performance means

- Wall time: 26.152199 s.
- Peak working set: 892,315,648 B.
- Completion stage: 6.475303 s.

## Next authority

Use artifact `8842377256` without rebuilding and follow:

- `.agents/Directional/Milestone_G_P5_Assembly_Conflict_Code_Build_Report.md`;
- `TODO`;
- `MILESTONE_G_TODO.md`.

P5 remains open and PR #8 remains draft/unmerged.
