# CB-173 — bounded edge-locus ray helper and controls (compile-only)

> **WITHDRAWN 2026-11-21 (TB-REV-156 adversarial review, [record](Architecture_M6_CP3_TB_REV_156_Adversarial_Review_20261121.md)).** Prose plan replaced by the exact diff [CB-173](Architecture_M6_CP3_CB173_P13_Edge_Locus_Along_Edge_Ray_Key_Exact.diff). Do not implement from this file.

**Canonical turn:** `M6-CP3-CB-173-P13-STOP-SWITCH-RAY-HELPERS` · **Type:** Code + Build, **no runtime**. This is one helper-only code/build turn authorized by [TB156 independent review](Architecture_M6_CP3_TB156_P13_Slide_Carrier_Cut_Admissibility_Full_Gate_Independent_Review_20261121.md). All test and benchmark execution belongs to a separate later turn; no current stop-switch production wiring.

## Situation and background

TB156 confirms ten `TraceSlideCarrier` source edges remain outside cut candidate selections; row858 and gate 972/972 PASS. The sphere remains noncellular (χ6, sourceχ2) with four unowned sliding-wall contacts. RA-281 F3 predicts that a later stop-switch will introduce an edge-locus node whose trace runs along its own source edge; existing CB-171 ray helper would reject it or incorrectly rank into-face rays if the edge-parallel arm is omitted.

## Allowed implementation

1. Inspect existing edge-ray locus and `RayRunsAlongLocusEdge` guard in `src/geometry/EmbeddedGraphTopology.cpp` and `include/directional/geometry/EmbeddedGraphTopology.h` (if the exposed helper is declared there), together with the `GlobalTopologyPlan` consumer, and the existing focused source tests. Reuse the current exact arithmetic and source-entity identity. Do not add a new parallel geometry subsystem.
2. Implement a narrowly scoped **unwired helper** for real rays at an edge-locus node. For each ray along the exact locus edge, represent its *oriented endpoint destination* in the source-edge arc slot: key `0` toward the edge's second endpoint, key `2` toward its first endpoint (subject to the actual existing orientation conventions); into-face rays retain their existing `2*side+1` slots. No-ray is distinct from a real along-edge ray. Include real along-edge rays in `edgeRayCount` and the exact cyclic ordering; do not use geometric epsilon or position-only aliasing.
3. Preserve fail-closed behavior when the ray **coincides with a real existing edge arc**. A trace-along-edge candidate is not by itself permission to merge, discard, cross a hard rail, or forge graph event ownership. Exact same-sheet, source chart and oriented incidence authority remain mandatory.
4. Extend the existing focused source-test compilation set only where necessary to cover both oriented edge-parallel cases, independent rays arriving into both faces, endpoint reversal, duplicate-ray/edge-arc rejection, a no-ray case and chart/sheet isolation. Tests must fail when the new key or incidence count is omitted. Compilation does not establish execution PASS.
5. Build/package only the eight mandated GMP/GMPXX targets through GitHub Actions; publish source SHA, artifact, exact build evidence, byte checksums, and `runtimeExecution=false`. No local build.

## Before-build falsifiers and stop rules

- **F1:** Removing the edge-parallel ray does not change the independent focused expected order or count: the new test is vacuous → STOP and correct test intent in CB, do not weaken an assertion.
- **F2:** Reversing the source edge does not swap the oriented edge slots consistently → STOP; orientation contract unproved.
- **F3:** Into-face rays change order/count solely because a parallel ray was added, except for the required count/slot accounting → STOP; inspect exact order.
- **F4:** Coincidence with an existing real edge arc is accepted, or two chart/sheet-distinct rays merge → STOP; source-authoritative ownership breach.
- **F5:** The helper is wired into production stop switch, slides are subdivided, cut-search behavior changes, fixtures/selectors/benchmark are modified, or tests run in this turn → STOP; wrong turn boundary.
- **F6:** Any GMP/GMPXX target fails to compile/package → keep CB incomplete; no TB successor until a compile-only build succeeds.

## Excluded and future work

A separate stop-switch CB, its immutable TB and independent Review, then source-attached slide-start cut subdivision (RA-281 F1/F2, Amendment14 R2 release), then RA-275 S4a and O48 χ+4. No CP3/497/D0 promotion. Stable ledger 66/17/49, debt1, deferred81 and accepted CP2 491/491 are immutable gates.
