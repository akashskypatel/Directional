# Mandatory original-arc coverage precondition — local source/test patch WIP

**Canonical Review:** `M6-CP3-DEFN-P13-A3-MANDATORY-CHAIN-SCHEDULING`. This record identifies a **prepared but unapplied** source/test diff. It does **not** close D5, authorize CB, claim executable test success, establish legal joining, or supersede [the independent TB contract](Architecture_M6_CP3_DEFN_P13_A3_Mandatory_Chain_Independent_TB_Contract_WIP_20261109.md).

## Recoverable exact bytes

- Git base: source-snapshot commit `e7091fa999dad6462f4616ec691cc1961a8ca0f3` (source snapshot workflow `42571131202`, artifact `13652529143`, 6,285/6,285 source hashes verified in previous attempt).
- **Unapplied WIP patch:** `d5-mandatory-arc-coverage-WIP.patch`, size **8,709 bytes**, SHA-256 `0c86332c97b1046c0f6b4182d9b9cac916929df10cc7e76199c4c2065ba4e6a8`.
- User-authorized Drive preservation: `My Drive/Directional-CI/d5-mandatory-arc-coverage-WIP-20261109.patch`, raw Drive file ID `1X1-RdhNj2-6Xr09RiZPulgEYWF8Is9DC`, link https://drive.google.com/file/d/1X1-RdhNj2-6Xr09RiZPulgEYWF8Is9DC/view . Drive metadata confirmed `text/x-diff`, 8,709 bytes, intended parent folder. **Drive metadata does not prove content SHA**; compare bytes before any application.
- Local verified patch includes exactly **two intended paths**: new `include/directional/geometry/MandatoryArcChainCoverage.h` (123 lines), and existing `tests/FieldAlignedCurveNetworkTests.cpp` (+58 lines). Generated with `git diff --binary --full-index --no-ext-diff`, `git diff --check` PASS, `git apply --check` PASS against unchanged snapshot. No compiler, binary or test was invoked, and this patch was **not applied to the repository**.

## What the patch does — and does not

The header adds `check_mandatory_arc_chain_coverage(const GlobalTopologyPlan&, const vector<vector<GlobalTopologyOrientedArc>>&)`, a typed **necessary-condition check** over a proposed partition. It rejects empty chains, unknown/non-Mandatory IDs, duplicates, missing Mandatory arcs, invalid orientations, adjacent Trace-split children sharing one `NetworkEdgeId`, disconnected A2b node endpoints, and mismatching exact source-support endpoints. It does **not** claim independently certified chain eligibility or produce the stage-owned topology product.

The test adds a producer-backed Cp3b fixture and assertions for valid all-singleton coverage and empty/missing/duplicate/foreign/non-Mandatory failures. The test is not executed. There are **no independently exercised witnesses yet** for wrong orientation, adjacent same network-edge siblings, disconnected node, disconnected exact point, producer-positive two-distinct-network-edge join, nonmaximal partition, invalid region/exterior side, protected feature corner, or a certified closed-rail cut. These test gaps are **not** passed or waived.

**Known limitation:** `passed()==true` for an all-singleton input says *only* that original Mandatory arc membership is complete. It cannot imply a reduction or prove a legal multi-arc chain. Do not publish a partition or mark D5 complete on this API alone. An independent verifier must reconstruct certified links from existing A2b, network, ordered rails, stage-local oriented source mesh, source sheets/regions, feature-map corners/options, physical side/fan, and Trace/Cut contacts; confirm maximal eligible open paths, exclude uncut/self-returning cycles, and reject mutations at their intended owning stage.

## Exact continuation

1. Continue the **same** runtime-free D5 Review. Recover and rehash the staged raw patch; compare it against current branch head. If the source/test paths changed since snapshot, rebuild deliberately; do not force-apply. The patch stays in Drive and the chat download for safe recovery. Do not submit to production while Review remains open.
2. Extend the proposed patch into **one exact source/test diff** with a checked stage-owned immutable chain partition, independently implemented join verifier, A2b→A3 construction and rejection-path one-way observation copy. The initial checker above is reusable as a narrow coverage precondition but cannot be reused as the independent join oracle. Keep original A2b and A3 unchanged in the first CB.
3. Freeze positive and negative synthetic original network-edge joins, full-cover/nonmaximality, two-sided region ownership, exact support, feature corner, Trace-terminal, cyclic and row-permutation falsifiers. Identify one bounded compile-only successor with the established eight GMP/GMPXX targets, before authorizing a build.
4. Only a separate immutable artifact TB may observe production Vase and establish at least one certified multi-original-arc chain spanning **two different Mandatory `NetworkEdgeId`**; missing witness is `NoCertifiedProductionJoin` RED. Do not derive success from TB92's aggregate census or the 142-edge raw rim.

**Boundary:** source/test/fixture/build/selector/workflows unchanged remotely in this Review; WIP source/test patch is staged externally only. No Google Drive retirement should happen until its exact work has been superseded, safely re-staged, or applied in a separately authorized turn.
