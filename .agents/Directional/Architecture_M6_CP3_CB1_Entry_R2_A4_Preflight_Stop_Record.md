# M6-CP3-CB1-ENTRY-R2 — A4 authority preflight stop

**Disposition:** Architectural stop at mandatory R2-P1 precondition; no implementation permitted until independent A4 producer-owned Review resolves the missing typed binding. This is not a completed Code + Build turn and is not a runtime failure.

## Frozen authority

- Repository: `akashskypatel/Directional`; branch: `agent/surface_cell_quad/p5-recover-bridge-healing`; PR #8 remains open/draft/unmerged.
- Turn: `M6-CP3-CB1-ENTRY-R2`, released by `M6-DEFN-R5-R2-REV` subject to mandatory stop gates.
- Verified source snapshot: commit `3ebfed421b031eff73d596f735b9f21ab81c273a`, run `37728354339`, source artifact `11528531972`, ZIP SHA-256 `ac2413862c0c27b175203920d412c7ade81a310a716a68316b56933c3107f48f`.
- Governing documents: `Architecture_M6_Frozen_Definitions.md` RA-34; `Architecture_M6_DEFN_R5_R2_Review_Record.md`; `Architecture_M6_CP3_CB1_Entry_R2_Recovery_Code_Build_Plan.md`.

## R2-P1 independent static inspection

1. **A4 creates typed face-to-face isolation certificates, not endpoint-wedge bindings.** `src/geometry/SurfaceCellTracing.cpp:16670-16820` constructs `SurfaceIsolationSeamTransportCertificate` from source-edge, source-face, topology-region/sheet, matching/reciprocal branch evidence. Its output is a vector of seam certificates.
2. **A4 product does not expose an independently owned wedge-to-certificate mapping.** `include/directional/geometry/SurfaceCellTracing.h:1783-1869` publishes source-region authority and certificates separately, along with fronts/cells, but no oriented certificate + independently typed endpoint/corner wedge side binding.
3. **A5 creates the relevant wedge evidence from its own geometry/face choices.** `src/pipeline/RemeshPipeline.cpp:3917-4048,4140-4255` obtains A4 face-region/sheet data but computes selected face, side interval and wedge crossing in the A5 consumer. This is not an independent A4 attestation that the selected wedge belongs to one oriented certificate side.
4. **The A5 certificate helper wrongly gates lookup on raw/global sheet inequality and drops orientation.** `src/pipeline/RemeshPipeline.cpp:4520-4551` returns `nullopt` whenever the two A5 interior sheet labels compare equal; this can deny a valid certificate lookup. Its `forward || reverse` result returns only the certificate, not the selected orientation.
5. **A6's special-case trigger is not independently certified.** `src/pipeline/RemeshPipeline.cpp:5391-5509` classifies the seam case from collinear source edge plus unequal sheet IDs, then selects forward/reverse branch evidence independently. This can grant a special case without a single certificate orientation binding every conjunct. The independent R2 Definition Review already identifies this precise code path but requires producer proof before changes.

**Finding:** On this frozen source, no independently A4-owned relation `(<source endpoint/corner wedge>, <oriented certificate>, <typed sheet/side>)` can be proven from A4 publication. The prerequisite in the released R2 plan is therefore false/unproven. The plan explicitly orders STOP **without source changes** and return to producer-owned independent Review; an A5/A6 self-certified mapping is forbidden.

## Required independent Review before resumption

- Define and authorize the smallest **A4-produced**, stable, source-chart-aware, oriented wedge-to-certificate side binding. Establish the orientation (`Forward`/`Reverse`) once and carry it through selected source face, both endpoint/corner wedges, coordinate/phase/scale, branch quarter-turn, and reciprocal source-chart/isolation side transitions.
- Explicitly prohibit raw/global sheet-label equality **or inequality** from granting or denying certificate lookup; hard-rail and source-chart barriers remain authoritative. Ambiguous/missing/contradictory evidence must reject through typed failure, not silently fall back.
- Independently verify that the producer can create the binding without using A5's own relation verdict, world-space proximity, or a fabricated fixture. Require negative falsifiers for mixed orientations, equal-label certified positives and unequal-label uncertified negatives, reciprocal/sign tamper and source-face/side/phase/scale mismatches.
- Freeze the producer-owned implementation plan or adjudicate an alternate sound authority contract **before** authorizing a Code + Build retry. Do not invent a successor identifier from this stop report.
- Carry the unproved organic D1 periodic, D2/HardRail odd-τ, D4/D7 real seam-collinear OrdinaryFront/A7, and D5 route-bearing ordinary carrier searches unchanged. Runtime existence may be proved only in a separately authorized artifact-only Test + Benchmark turn.

## Work preservation and verification

- Changes to production source, tests, fixtures, selectors, workflow definitions, build scripts: **none**.
- Generated Directional compile, test discovery, runtime, benchmark, or binary execution: **none**; no eight-target compilation or immutable package claimed.
- Existing reviewed CP2 `491/491` and rejected prior CP3 entry `482/497` are historical evidence, not results of this turn; frozen future gate remains `497 = 30 + 12 + 449 + 6`.
- Existing stable accounting stays `63 events / 17 categories / 46 recurrences`; produced-witness debt `1` and `RP-01` remain open. No new stable regression is asserted from a static preflight.
- A known procedural conservation miss occurred at startup: several repository documents were read directly before fully adhering to the mandatory snapshot read-mode gate. Subsequent implementation analysis used the verified snapshot. Do not repeat that pre-read mistake.
- No work-preservation code patch exists because the mandatory stop occurs before source changes. This report is the continuation artifact. The last repository action must update root `STATUS` to architectural `BLOCKED` with no invented successor.
