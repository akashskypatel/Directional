# RA-249: face-contact node freeze (2026-11-17 UTC)

Canonical turn `M6-CP3-DEFN-P13-FACE-CONTACT-NODE-FREEZE` (Review only).
- It freezes the code that implements RA-248 FC-1 – FC-5 and the TB128 gate manifest.
- No Directional binary was built or run. Source checks were `-fsyntax-only` only.

## 1. Starting point

- **CB147 landed exactly as frozen.** `git diff 48e6f97d2..43294bde4 -- src include tests` matches the frozen diff byte for byte. The CB147 package is `14309111230`.
- **No source drift since.** `src include tests` have not changed after `43294bde4`.

## 2. Split decision

Implementing FC-1 – FC-5 in one patch gave 741 diff lines in five files. Following the owner's rule of narrow, independently testable turns, I split it into two stacked patches:

| CB | Content | Behaviour |
|---|---|---|
| **CB148** helpers | Additions only:<br>• `TraceCutPosition`, a position on a trace (`(segment, optional exact t)`) whose defaulted order is boundary k < interior (k, t) < boundary k + 1<br>• `trace_segment_canonical_entry` / `trace_segment_canonical_exit`<br>• `trace_segment_contact_parameter`<br>• `trace_cut_segment_range`<br>• `exact_trace_path_between`<br>• `FaceContactNode` and `collect_face_contact_nodes` (FC-1, FC-2)<br>• three rotation reasons, `FaceContactBindingInvalid` = 64, `FaceContactRayDirectionCollision` = 65, `FaceContactRayUnsupported` = 66, with their names<br>• unit test `FaceContactNode.SplitsAStruckSegmentAtAnExactInteriorContactPoint` | Nothing calls the new code yet, so product behaviour is unchanged. |
| **CB149** switch | Wiring only:<br>• `build_arcs` takes positions from `collect_face_contact_nodes` and skips face-contact events in its event-position loop (FC-2, FC-3)<br>• arcs come from `trace_cut_segment_range` / `exact_trace_path_between`<br>• `build_node_loci` skips face-contact events (FC-4)<br>• `build_rotation_system` gains a face-contact branch (FC-5)<br>• the private `TraceCut` struct is removed, since it is no longer used | Changes only networks that contain a face-contact node. All such networks fail today, at `build_arcs`. |

**Why CB149 changes only networks that fail today.**
- Every face-contact event set includes a FirstContact whose incidences are Interior. The current `trace_event_position` rejects an Interior incidence that has no edge, so every network with a face contact fails at `build_arcs` today.
- For a network without face-contact nodes, `collect_face_contact_nodes` returns an empty map. Every position is then a boundary, `trace_cut_segment_range` returns the old `[first, second)`, and `exact_trace_path_between` delegates to the unchanged `exact_trace_path`. So arcs, loci and rotations come out byte-identical.
- The only possible gate change: a gate row that expects a particular failure from a network with a face contact. A Haiku census (RA-247) found no test that names `TraceEventPositionInvalid`, `NoCarrierMatch`, `EventLocusMissingSourceEdge` or `RotationNodeLocusUnsupported`. TB128's ledger-equality check covers whatever remains. **Correction from [TB128 Review](Architecture_M6_CP3_TB128_P13_Face_Contact_Full_Gate_Independent_Review_20261117.md):** literal reason-name scan was insufficient; row858 asserts a specific locus class, not the named reason. Gate equality and all exact assertions remain required.

## 3. Frozen patches

**CB148:** `Architecture_M6_CP3_CB148_P13_Face_Contact_Node_Helpers_Exact.diff`.
- SHA-256 `b4b8248715e04996bcdc22f2146497d9957bb0923f5602dabbac3c4b44dced6e`.
- 475 lines.
- Numstat:
  - `6 0 include/directional/geometry/GlobalTopologyPlan.h`
  - `216 0 src/geometry/EmbeddedGraphTopology.cpp`
  - `73 0 src/geometry/EmbeddedGraphTopology.h`
  - `6 0 src/geometry/GlobalTopologyPlan.cpp`
  - `115 0 tests/FieldAlignedCurveNetworkTests.cpp`
- Precheck: `git diff --quiet 43294bde49e1f24aa09d10ca7e5ff632a7c28d6b HEAD -- src include tests`.

**CB149:** `Architecture_M6_CP3_CB149_P13_Face_Contact_Node_Switch_Exact.diff`.
- SHA-256 `ddf87b85683e1f34322418ffd5303740822602d845faf3a80ecff9d8d817963c`.
- 270 lines.
- Numstat: `148 27 src/geometry/EmbeddedGraphTopology.cpp`.
- Precheck:
  - `src include tests` equal `43294bde4` plus exactly CB148;
  - `git apply --reverse --check` of the CB148 diff passes;
  - `git apply --check` of the CB149 diff passes.

**Verification (both patches):**
- **Applying.** Each applies at HEAD `7ddaf9972` in order (CB148, then CB149). Together they reproduce the reviewed full state byte for byte.
- **Syntax checks.** `-fsyntax-only -Wall -Wextra -DUSE_GMP_ENABLED` returns 0 for `EmbeddedGraphTopology.cpp`, `FieldAlignedCurveNetworkTests.cpp`, `GlobalTopologyPlan.cpp` and `SurfaceCutGraph.cpp`, both after CB148 and after CB148 + CB149.
- **Warnings.** Identical to HEAD (22 / 42 / 24 / 27).
- **`RemeshPipeline.cpp`.** It has one error that also occurs at HEAD (`std::inserter` without `<iterator>` in `SourceChartTransitions.h`), so this patch adds nothing there.
- **Enum switches.** `rotation_system_inconsistency_reason_name` is the only switch over the reason enum, and it gains the three new cases.

**What the CB148 unit test checks:**
- canonical entry and exit, including the end at the trace's terminal point;
- that an edge-transit segment is rejected;
- the contact parameter 1/3, and rejection of the segment's own exit;
- the position order, including two cuts 2⁻⁶⁰ apart;
- the segment ranges;
- `exact_trace_path_between`:
  - the piece before the split ends at the exact face point;
  - the piece after it starts there;
  - pieces past the split segment equal the whole path;
  - two contacts in one segment give distinct ends;
  - reversed and equal positions are rejected;
- the three new reason names.

The face-node rotation and the collector need a real network, which the tests cannot hand-build (RA-248 fixture limit). Their only runtime witness is BunnyRandom.

**Routes:**
- CB148:
  - mismatch → `M6-CP3-PLAN-P13-FACE-CONTACT-NODE-HELPERS-STOP`;
  - infrastructure failure → `M6-CP3-CB148A-P13-FACE-CONTACT-NODE-HELPERS-ORCH`.
- CB149:
  - mismatch → `M6-CP3-PLAN-P13-FACE-CONTACT-NODE-SWITCH-STOP`;
  - infrastructure failure → `M6-CP3-CB149A-P13-FACE-CONTACT-NODE-SWITCH-ORCH`.
- Both are compile-only and build the eight RA-245 GMP targets.

## 4. TB128 frozen

**Package:** the CB149 package (CB147 + CB148 + CB149).

**Gate manifest:** `gates/Architecture_M6_TB128_P13_Face_Contact_Node_Full_Gate_Case_Manifest.tsv`.
- SHA-256 `941287fa96f3432eb1d67a9ae1e5dc7bc0ca2f3a1775cd5f9fb35482a4fa7962`.
- It is the TB126/TB127 manifest (`44d5a734…`, 951 rows) byte for byte, plus:
  - row 952, `FaceChartExactGeometry.OrdersRaysAndContactsExactlyAroundAFaceInteriorPoint`;
  - row 953, `FaceContactNode.SplitsAStruckSegmentAtAnExactInteriorContactPoint`.
- Self-check: `SELF_CHECK_PASS cases=953 deferred=81`; membership 1,034.

**Census:** `3af1dc0d…`, unchanged.

**MATCH requires all of the following:**
- 953/953 PASS, 0 skipped, valid postflight.
- Rows 1–951 have the same ledger fields as TB127. Raw logs may differ only in elapsed time and the `M3_CP4AB_FRAGMENT_DIAG` newline framing (newline-free text equal).
- Cylinder is PASS with 288 quads. Cylinder and Vase census logs are identical to TB127 after normalizing ms timings and gtest `GetParam()` byte dumps. `SurfaceCellDesignAcceptanceTests.cpp` is unchanged, so the assertion line numbers must not move.
- BunnyRandom:
  - every receipt line before the terminal, including the four inventory lines, is identical to TB127;
  - the terminal is none of the following: `TraceEventPositionInvalid` at face `(5,104,359)`, any `FaceContact*` reason, `EventLocusMissingSourceEdge` or `RotationNodeLocusUnsupported`.

**Prediction (record it; it does not decide MATCH):**
- **BunnyRandom's new terminal, verbatim.** It is expected at a downstream ownership stage (O46): SurfaceCutGraph ownership or certification, the face walk, or an A2b fragment-corner reason (`SourceFaceCarriesTraceChordAndRays`, `SourceFaceCarriesMultipleTraceCuts`, `SourcePortFaceAlreadyCarriesTraceChord`, `FragmentCornerRayOrdinalDuplicate`).
- **If the terminal is `RotationEdge*` on edge (241,251) or (251,278):** that falsifies CB144's middle-piece direction rule. The outcome Review must reopen that rule first.

**Routes:**
- Mismatch → `M6-CP3-TB128-P13-FACE-CONTACT-FULL-GATE-REV`.
- Infrastructure failure → `M6-CP3-TB128A-P13-FACE-CONTACT-FULL-GATE-ORCH`.
- MATCH → Review-only `M6-CP3-DEFN-P13-FACE-CONTACT-OUTCOME`.

## 5. Turn sequence

| # | Turn | Owner | Status |
|---|---|---|---|
| 1 | `M6-CP3-CB147-P13-FACE-CONTACT-EXACT-HELPERS` | Code + Build | COMPLETE |
| 2 | `M6-CP3-DEFN-P13-FACE-CONTACT-NODE-FREEZE` (RA-249) | Review | COMPLETE |
| 3 | `M6-CP3-CB148-P13-FACE-CONTACT-NODE-HELPERS` | Code + Build (compile only, exact diff) | NEXT |
| 4 | `M6-CP3-CB149-P13-FACE-CONTACT-NODE-SWITCH` | Code + Build (compile only, exact diff) | then |
| 5 | `M6-CP3-TB128-P13-FACE-CONTACT-FULL-GATE-EXEC` | Test + Benchmark | then |
| 6 | `M6-CP3-DEFN-P13-FACE-CONTACT-OUTCOME` | Review | Classifies TB128, then freezes CB150 (FC-6, measured before it is switched on) |
| 7+ | CB150 → TB129 → CB151 (FC-6 switch) → TB130 | — | Staged per RA-230 |
| parked | `M6-CP3-CB145-P13-VERTEX-FOLLOW-BOUNDARY`; O45 | — | — |

**Numbering change against RA-248:**
- RA-248's single "CB148 switch" is now CB148 (helpers) plus CB149 (switch).
- The FC-6 patches move to CB150 and later.

## 6. Carried

- **Open:** C5 (being implemented), O42, O43, O45, O46.
- **Still to do:** the middle-piece direction witness, which is BunnyRandom at TB128 or later.
- **Closed:** narrow C3, O44, C1.
- **Decisions:** D11 = A, D12 = A, D10 deferred, D6 pending.
- **Counts:** stable 66/17/49, debt 1, deferred 81; CP2 491/491.
- **Unchanged:** CP3/selector497 unpromoted; `chainRimSchedules=false`; DESIGN.md unchanged.
