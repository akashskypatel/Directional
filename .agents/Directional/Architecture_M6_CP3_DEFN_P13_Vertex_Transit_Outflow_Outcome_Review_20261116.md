# RA-240 — P13-e vertex-transit outflow outcome: H1 at one star, H2 at two (2026-11-16 UTC)

**Turn:** `M6-CP3-DEFN-P13-VERTEX-TRANSIT-OUTFLOW-OUTCOME` (Review only, P13-e.15).

**Authority read:**
- the [TB120 report](M6_Consolidated_Record_Vol_D3_CP3_P13_from_20261109.md#architecture_m6_cp3_tb120_p13_vertex_transit_outflow_receipt_full_gate_execution_report_20261116md);
- [RA-239](Architecture_M6_CP3_DEFN_P13_Obtuse_Edge_Port_Outcome_Review_20261116.md) §§3–5;
- DESIGN Amendments 17 and 22, and `M3_Closure_Record.md` AX1;
- `resolve_field_vertex_transit`, `field_aligned_next_trace_proposal` and `resolve_field_branch_continuation` at HEAD;
- the mesh `benchmarks/fixtures/milestone-g/bunny_1k_random.obj` (502 vertices, 1,000 faces).

HEAD's `src`, `include` and `tests` are identical to the CB139 source `c520674030c76be455111d7c41aae7d5f53ce900`. No runtime was used.

## 1. TB120 accepted

TB120 is accepted as a **scoped MATCH**. Both artifacts were re-downloaded into their own directories and SHA-checked:
- gate `14199814782`: outer `fd52e790…`; 1,902/1,902 internal hashes; no R1 line in any file.
- census `14201142306`: outer `4d680693…`; 9/9 internal hashes.

The 23 R1 and sector lines in the census artifact are identical to the report's records. All three RA-239 predictions hold:
- **P1:** the locus is a vertex entry, with `parameter=0/1 exact=0/1` on edge (137,149).
- **P2:** exactly one R1 line matches the locus: seed vertex 138, singularity 12, trace 51, `step=0 = history − 2`, owner (137,149,162) branch 0.
- **P3:** no R1 line appears in the 947 gate rows or in Cylinder. Vase has none either.

## 2. The three stars

All three R1 lines are `EdgeTransit` arrivals at the far end of an edge-port slide (step 0) on BunnyRandom. Each fan is closed, with the arrival face at sector 0.

**Model.** The model reads the mesh, the 20 logged sector rows, and each face's field as d = Σ wᵢ pᵢ. It develops each fan and elects β = α + Θ/2 with the code's half-open rule.
- It reproduces the logged owner at all three stars.
- Its in-wedge test agrees with the logged `inOwnSector` on all 20 sectors.

The H1 seed is the carrier ray, so α is either the arrival sector's angle (carrier end = previous radial) or 0 (next radial).

| vertex (trace) | Θ | code α → owner | H1 α → owner | sectors whose field leaves the vertex |
|---|---|---|---|---|
| 137 (51, the terminal) | 389.76° | 55.39° → 3 (137,149,162), no outflow | 79.48° → **4** (137,158,162), margin 14.2° | 4 only |
| 349 (99) | 404.48° | 40.16° → 4 (5,102,349), no outflow | 52.66° → **4**, margin 16.5° | 5 only (5,306,349) |
| 48 (24) | 379.97° | 20.05° → 4 (48,271,272), no outflow | 30.84° → **4**, margin 18.8° | **none** |

Field positions in the developed fan (degrees from the arrival sector's next radial):
- **Vertex 349.** Owner 4's field is at 271.8°, which is 0.39° past radial 5, inside sector 5. Sector 5's own field is at 272.3°, inside its wedge.
- **Vertex 48.** Sector 3's field is at 217.5°, inside sector 4. Sector 4's field is at 199.7°, inside sector 3. The two fields point at each other across radial edge (48,271). That is the same configuration the existing rules call `Outflow` (grazing) at an edge crossing.

Traces 24 and 99 would fail exactly as trace 51 did. The network reports its first terminal, and trace 51 failed first.

## 3. Findings

- **F1: H1 holds as a conformance defect, and it explains the terminal.**
  - AX1 says the seed points "from the vertex back along the incoming trace". It defines no separate rule for edge-locus arrivals.
  - After a slide, the trace arrives along the carrier. The code seeds every arrival with the arrival face's negated field.
  - The accepted unit test `FoldedConeRadialArrivalSeedUsesExactHalfOpenArrivalConvention` builds an `EdgeTransit` arrival whose negated field already lies on the radial ray ("EdgeTransit is the admissible arrival mode for that exact radial seed"). The code matches AX1 only in that case.
  - At vertex 137, the carrier-ray seed elects sector 4, which has outflow. The margin is 14.2°, far from a tie.
- **F2: H2 also holds, and H1 cannot fix it.**
  - At vertices 349 and 48, the AX1 seed elects the same owner as the code, and that owner has no outflow.
  - At vertex 48, no sector's field leaves the vertex, so no seed of any kind can elect an outflowing owner.
  - A repair has to consult the fields after the election. Amendment 22 forbids that ("every candidate-local value is demoted to audit data"). It also names only three residual cases, and this is not one of them.
  - So the repair is a user decision. It is recorded as **D12** (§4).
- **F3: firing scope.** The no-outflow predicate (R1) fired 3 times in 950 runs (947 gate rows and 3 census cases), all on BunnyRandom before its terminal.
  - Any D12 rule that runs only on that predicate leaves the 947 gate rows, Cylinder and Vase unchanged, as far as their logs go. A row stops at its first terminal, so nothing after that is observed.
  - The AX1 seed switch is different: it changes every `EdgeTransit` election whose owner moves, including accepted rows' grazing transits (RA-228). How many is not measured.
- **F4: an AX1 switch alone does not make BunnyRandom produce output.** By §2, after the switch traces 24 and 99 still enter at a vertex with exit time 0.

## 4. D12 (named user decision, open)

What should a trace do when the face elected at a vertex (Amendment 22) has no field leaving the vertex? The options were put to the user in this turn:
- **A, follow the field.** Keep the geometric election, then continue from the owner by the existing edge rules. Cross the radial edge the owner's field points across. If two adjacent fields point at each other across one radial edge, slide along that edge, as grazing and edge ports already do. Model outcome: 349 → (5,306,349); 48 → slide along (48,271). Runs only on the R1 predicate.
- **B, fail closed, typed.** Add a fourth named residual state, `VertexTransitOwnerWithoutOutflow`. BunnyRandom stays RED until a conditioning-stage repair (in the style of Amendment 20).
- **C, defer.**

The user gave no answer; they asked to continue the turn. **D12 is pending, not deferred.** Only decision-independent work proceeds (RA-233). The Review after TB121 asks D12 again if it is still open (RA-234), because that Review needs the answer.

## 5. Frozen CB140: `M6-CP3-CB140-P13-EDGE-TRANSIT-SEED-CONFORMANCE-RECEIPT` (compile only)

- **Patch:** [exact diff](Architecture_M6_CP3_CB140_P13_Edge_Transit_Seed_Conformance_Receipt_Exact.diff).
  - SHA-256 `2e135b8cc18c6e59187928779756d429d0c8e2819e9dcfdc21344f71e8b667eb`.
  - 123 lines, standard 3-line context.
  - Numstat `105 0` `src/geometry/SurfaceCellTracing.cpp`.
- **Base:** HEAD at this record's commit, or any descendant that changes only documentation. Precheck: `git diff --quiet c520674030c76be455111d7c41aae7d5f53ce900 HEAD -- src include tests`.
- **What it does (diagnostic only).** `report_field_edge_transit_seed_conformance` runs after the R1 call on the slide-end (`EdgeTransit`) path of `field_aligned_next_trace_proposal`.
  - It re-runs the closed-fan election on the audited sectors with the exact kernel (`vertex_star_compare_angle_sums`), seeded from the carrier ray.
  - It prints `FieldAlignedCurveNetwork.edgeTransitSeedConformance` only when that owner differs from the decision: `modeled=1 codeOwner= carrierOwner= carrierOnRadialRay= codeOwnerLeaves= carrierOwnerLeaves= sectors=`.
  - It also prints when it cannot model the arrival (`modeled=0 reason=fan|carrier|exact`): an open fan, an arrival face that is not sector 0, a carrier that does not bound the arrival sector, or an exact comparison that is unavailable (the exception is caught).
  - The decision is unchanged.
- **Not covered.** The legacy `legacy_canonical_field_aligned_traces` path is not instrumented, and neither are `FaceInterior` arrivals, whose seed already conforms to AX1.
- **Checks.**
  - `git apply --check` passes at HEAD.
  - `-fsyntax-only -Wall -Wextra` (Homebrew clang++, CI defines) returns 0. The warning set is identical to HEAD's: 43.
  - No test is added, so membership stays 1,028.
- **Routes.**
  - Mismatch: `M6-CP3-PLAN-P13-EDGE-TRANSIT-SEED-CONFORMANCE-RECEIPT-STOP`.
  - Infrastructure: `M6-CP3-CB140A-P13-EDGE-TRANSIT-SEED-CONFORMANCE-RECEIPT-ORCH`.

## 6. TB121: `M6-CP3-TB121-P13-EDGE-TRANSIT-SEED-CONFORMANCE-RECEIPT-FULL-GATE-EXEC` (artifact only)

- **Gate.** The TB119/TB120 manifest is reused unchanged: `3aac432b9f466e5ce06601c90a08ad09c1886dfeb97c38b05e9bd46f51a1190b`, 947 rows, membership 1,028.
- **Census.** The three-case manifest `3af1dc0d…`.
- **MATCH requires all of these:**
  - **Gate:** 947/947 PASS, with every TB120 receipt unchanged and no R1 line.
  - **Cylinder:** PASS.
  - **Vase:** terminal line identical to TB120's.
  - **BunnyRandom:** terminal and locus identical to TB120's, the 23 R1 and sector lines unchanged, and the 16 `partition edgePort` and 16 `edgePortDeparture` lines unchanged.
- **Record verbatim, as measurements:**
  - every `edgeTransitSeedConformance` line;
  - the count per row, split into `modeled=1` and `modeled=0` by reason;
  - the gate rows that print at least one line.
- **Predictions.** A miss is a finding, not a mismatch:
  - (Q1) BunnyRandom prints `vertex=137 carrierEnd=138 modeled=1 codeOwner=3 carrierOwner=4 carrierOnRadialRay=0 codeOwnerLeaves=0 carrierOwnerLeaves=1 sectors=6` for trace 51.
  - (Q2) It prints nothing for traces 24 (vertex 48) and 99 (vertex 349).
  - The gate counts are what is being measured, so no prediction is made for them.
- **Routes.**
  - Mismatch: `M6-CP3-TB121-P13-EDGE-TRANSIT-SEED-CONFORMANCE-RECEIPT-FULL-GATE-REV`.
  - Infrastructure: `M6-CP3-TB121A-P13-EDGE-TRANSIT-SEED-CONFORMANCE-RECEIPT-ORCH`.
  - MATCH: Review-only `M6-CP3-DEFN-P13-EDGE-TRANSIT-SEED-CONFORMANCE-OUTCOME` (P13-e.18). From TB121's counts it freezes the AX1 seed switch, or stages it behind an option if accepted rows move (RA-230). It also asks D12 if it is still open, and freezes the D12 CB if D12 is answered.

## 7. Gaps and carry

- **The model uses doubles.** The margins are 14–19° in angle, so rounding cannot change these owners. CB140 uses the exact kernel.
- **CB140 has no unit test.** The receipt reads only the audit and does not decide anything. TB121's prediction Q1 is its check.
- **D12 is pending.** BunnyRandom cannot produce output without D12, whatever happens with the AX1 seed.
- **Carried unchanged:**
  - O42 and O43;
  - D11=A, D10 deferred, D6 pending;
  - CP2 491/491;
  - stable 66/17/49, debt 1, deferred 81;
  - CP3/selector497 unpromoted, `chainRimSchedules=false`;
  - then 65A–65D.
- **New open item: O44, AX1 `EdgeTransit` seed nonconformance (F1).** Its switch waits for TB121's counts.
- **Candidate status.** The terminal stays a **non-stable P13-e candidate**.
  - Cause established: the owner stage, A2a vertex transit.
  - At vertex 137: the AX1 seed nonconformance.
  - At vertices 48 and 349: the Amendment 22 outflow gap (D12).
