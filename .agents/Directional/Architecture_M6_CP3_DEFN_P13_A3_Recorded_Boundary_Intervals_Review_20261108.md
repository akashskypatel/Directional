# M6-CP3 step 61 — Recorded A3 source-boundary intervals (runtime-free Review, final decision)

**Turn:** `M6-CP3-DEFN-P13-A3-RECORDED-BOUNDARY-INTERVALS`.
**Authority:** RA-214 §5; TB86 immutable 909/909 MATCH, membership 990, not CP3 acceptance. Source inspection: exact source snapshot `4e398ceaf03f2f602ec0047aa4ccb2278208fca0` (snapshot workflow 42474548804); semantic CB103 is `000752d896aad4e515bcffc23331c26692539830`.
**Boundary:** definition and static source review only; no product/test implementation committed, compiled or executed. The repository holds only a frozen candidate **core code diff as a document** for the separate Code + Build turn, not an executed repair.

## Verified producer defect and minimal contract

- `SurfaceCellTracing.cpp` curved-disk producer uses A3 subdivisions for all accepted rim arcs but guards recording of exact `SurfaceSharedBoundaryInterval` by `hardFeature` at the `append_arc` producer, leaving a physical source boundary (`sourceBoundary=true`, hardFeature=false) unrecorded. `assign_open_front_boundary_authority` classifies physical rims `GenuineSourceBoundary` before HardRail; the producer’s later `HardRail`-only presence check independently rejects newly recorded rim intervals unless updated.
- `SurfacePhaseFrontProduct::make` accepts exact intervals only on `HardRail` and `PeriodicCut`. Extend *permitted* interval carriers to `GenuineSourceBoundary`, provided `exterior=true`, no `oppositeEdge`, exact nonzero unit ordinal extent and orientation consistent with ordinal sign. This is **not** a new global requirement for every source-boundary edge when a conformity receipt exists: legacy rectangular/front producers can legitimately publish source boundaries with no A3 consumption. Keep the existing missing-interval requirement for `HardRail`; the curved-disk producer with `useAcceptedConformity` must itself publish a rim interval on every eligible edge.
- Each recorded source-rim interval retains the exact upstream A3 `NetworkArcId`, `firstOrdinal`, `secondOrdinal`, orientation and optional boundary occurrence. It must not invent a twin, a hard rail, a periodic relation, or use a nearest world position. No A3 count/breakpoint change, no phase-field, selector, disc-domain, or tracing reroute changes. Do not turn report-only A3 coverage into success or failure authority.

## Reader census and impact

| Reader | Source behavior | CB104 contract |
|---|---|---|
| `SurfaceCellTracing.cpp:9386` factory | Present intervals allowed only on HardRail/PeriodicCut, exact unit/orientation check; reciprocal comparison only when `oppositeEdge >= 0` | Admit physically single-sided `GenuineSourceBoundary` with no opposite; preserve all existing paired checks and rail-required presence |
| `SurfaceCellTracing.cpp:~9660` `summarize_a3_span_coverage` | Report-only count of exact lower ordinals by A3 arc and baseline incidence | Newly recorded rim contributes to coverage; source-incidence count and cross-region variants independently checked, not assumed |
| `SurfaceCellTracing.cpp:~17625,~18183` producer | `hardFeature`-only interval storage and `HardRail`-only presence contract | Record physical rim A3 subdivisions and require them only in accepted curved-disk producer |
| `RemeshPipeline.cpp:~2285` digests | Hashes interval presence, arc, exact ordinal endpoints, direction | Only a fixture actually producing new rim records should change this field; verify the *complete* digest matrix independently |
| `RemeshPipeline.cpp:~4832` transport | `periodic_placement_transport` demands both opposite intervals plus periodic endpoint states | Source rim lacks opposite and periodic endpoint states; no new pairing; forbid bypass of relation-kind gates |
| `RemeshPipeline.cpp:~5109` quotient selection | Runs in `Periodic` occurrence relation, then requires reciprocal interval occurrence ownership | Do not interpret new single-sided rims as periodic pairs |
| `SurfaceCellTracing.cpp:~19081-19304` hard-rail pairing | HardRail-id and two-edge reciprocal provenance/contacts | Rim must not be promoted to hard rail or satisfy paired contact with its own interval |
| `SurfaceCellTracing.cpp:~19882,~19950` A2b probe/identity | First-rejection diagnostics and pair qualification, gated by actual relation/rail contact | Rims remain single-sided and cannot be a substitute for a typed A2b trace seam |
| `SurfaceCellTracing.cpp:~20341,~20531` probe | Logs interval presence/ordinals on rejected endpoints | Diagnostic display may gain interval information, never semantic authority |

**Source-only verification limit:** No runtime build, test or independent new digest is claimed. Source review can freeze a contract and falsifiers, not TB87 outcomes. An extracted archive without its origin `.git` history cannot substantiate `review_check.py boundary` or a remote `git status -sb`; these must be checked by a properly authenticated checkout in a later applicable turn.

**Important uncovered path:** An A2b Trace seam between two source-region discs still lacks an admissible interval edge kind; CB104 does not resolve it (RA-214 step 65). A shared `NetworkArcId` across regions is not itself a same-region twin claim. `sourceTopologyRegion` and exact source attachment are authoritative discriminators. Do not conflate report-only arc coverage with per-region geometric acceptance.

## Frozen CB104 source-only core and discovered candidate-test error

- **Canonical core patch**: [`Architecture_M6_CP3_CB104_P13_A3_Recorded_Boundary_Intervals_Core.diff`](Architecture_M6_CP3_CB104_P13_A3_Recorded_Boundary_Intervals_Core.diff), SHA-256 `916c591adebc3c1ccacffbcc8acbb0a59ef1d0338c18fb93e9c9b3d87ab11bf0`, 3544 bytes. Intended *future implementation* paths: `include/directional/geometry/SurfaceCellTracing.h` and `src/geometry/SurfaceCellTracing.cpp`. `git apply --check` on exact snapshot `4e398ceaf03f2f602ec0047aa4ccb2278208fca0` is required at CB104 entry. This source-only diff is committed as review evidence; applying it to implementation source and authoring corrected tests belong exclusively to CB104. It is not a compiled or verified code change.
- **Superseded draft, do not apply**: `Architecture_M6_CP3_CB104_P13_A3_Recorded_Boundary_Intervals.diff`, SHA-256 `ce24023f5112ea21c112d0fd91670696cc031bbc7378536d69ea40ba81fa6f30` (7,797 bytes), remains downloadable outside the repository for provenance. Its proposed test `A3SourceBoundaryRecordsSingleSidedIntervalsAndDetectsLoss` is **invalid**: `build_rectangular_hard_rail_phase_front` does not establish a curved-disk A3-consuming non-hard rim, and the test expects generic `SurfacePhaseFrontProduct::make` to reject a missing `GenuineSourceBoundary` interval even though that factory must preserve legitimate no-A3 producers. The draft must not be routed as an exact CB104 implementation.
- **Required CB104 test repair and execution boundary**: author a non-vacuous positive produced curved-disk fixture with `useAcceptedConformity` and at least one truly non-hard-feature source-rim A3 span, and separately show a no-A3 plain-rim product remains valid. For missing rim data, the **curved-disk producer** enforces completeness; the generic factory only validates **present** rim intervals, including unit extent, sign/orientation, single-sided exterior status and source attachment. For drop/stretched/foreign/orientation mutations, distinguish source-coverage degradation from factory's typed rejection; never claim an absent optional rim interval fails at the generic factory. The test must demonstrably fail under the pre-change source; compile only in CB104; execute only in TB87.
- **Frozen CB104 scope**: apply only the core two-file code change and the minimum genuine producer test; no new A3 count/breakpoint, cross-region seam, selector, phase, hard-rail, periodic or fallback behavior. If no non-vacuous source-rim fixture can be produced, stop with a review/plan correction rather than claiming CB104 complete. Verify source-only core hash and exact target paths before use. Product-code and test changes only in CB104; TB87 receives immutable package.

### TB87 — pre-registered independent falsifiers (separate artifact-only Test + Benchmark)

1. Positive source-rim: use a real curved-disk fixture with an A3 plan and at least one `GenuineSourceBoundary` edge that is not `HardRail`. Verify every A3-scheduled physical-rim subedge publishes a unit ordinal (not merely a nonempty vector), exact source-edge and arc identity, correct orientation, `exterior=true`, no twin, and no generated relation owner. Independently reconstruct full rim tiling from the A3 schedule and source boundary, including both directions and reversed source-face ordering.
2. Negative mutation: delete one **actually produced** rim interval and show per-span A3-coverage loss without accidental factory rejection caused by an unrelated guard; stretch one interval to length 2 and show `InvalidSharedBoundaryInterval`; corrupt orientation, foreign span and source attachment independently. Include a positive HardRail and a positive non-A3 plain-rim producer to prove neither old path regressed. `summarize_a3_span_coverage` is report-only, so an absence classified partial does not by itself force rejection unless the invoking curved-disk producer owns the completeness check.
3. Same-source cross-region: construct independently source-owned rim occurrences in two A2b discs sharing an upstream `NetworkArcId`, verify exact region/source and boundary-occurrence segregation; never obtain `oppositeEdge`, same-region equivalence, hard-rail pairing, or periodic relation solely from shared arc identity. A source-region split and reversed chart enumeration must preserve that conclusion.
4. Digest impact: compare the previous immutable TB86 package against the exact CB104 compile artifact on all pinned fixtures, verify all unchanged products remain byte-identical, and register any changed curved-disk digests as **expected candidate differences**, not silent rebaselines. If a legacy producer or a non-curved-disk case changes, stop and diagnose.
5. Stop on unproved source attachment, missing rim tiling, changed pre-existing rail or periodic matching, added recovery/fallback, or different input/accepted selector; do not repair tests during TB87.

The invalid test hunk was removed from the frozen core. CB104 is responsible for constructing a truly A3-consuming non-hard-feature source-rim test rather than assuming the rectangular hard-rail fixture is that witness. The independent TB87 falsifiers remain mandatory.

## Carried authority

- D9 rim-recording only → CB104 then TB87; D9 trace-seam support remains for step 65.
- D7 partition-stable metric before D5 maximal chains → step 64. D8 consumption-receipt caveat remains.
- D6 Vase expected D1 requires user approval; not assumed here.
- P13-e, O30b, O31 (legacy), O32b–e, O33, O27–O29 remain in their existing owners.
- No new accepted-green loss, no promoted selector, no stable regression event claimed; CP2 remains 491/491, stable 66/17/49, one debt, 81 deferred.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | n/a: no selector edited or accepted by this definition; previous TB86 acceptance is not asserted anew |
| Decisive claims independently re-derived | Reviewed exact C++ producer/factory conditionals, digest and relation consumer gates from verified source snapshot; `git apply --check` succeeded; no runtime re-derivation claimed |
| Non-vacuity checked | Required actual non-hard-feature rim plus negative drop, stretch, direction, foreign-span and no-A3-positive controls in TB87; draft test still requires CB104 verification |
| Prior obligations discharged/carried | D9 rim scoped; D9 seam, D7, D5, D8, D6 and existing P13/O obligations carried above |
| Stable accounting | No accepted-green changes: CP2 491/491; 66/17/49, one debt; TB86 candidate 909/909, membership 990; 81 deferred; selector497 unpromoted |
| New candidates/obligations recorded | Existing D9 updated in tracker; no new stable ID; TB87 controls frozen here |
| ORIENTATION currency line | Step-61 completed review and 2026-11-08 currency written in this document batch |
| ORIENTATION §3 / §4 / §7 / §8 | §3 and §7 advanced to CB104; §4 n/a no witness changed; §8 cites existing false-witness pattern (no new reusable lesson) |
| CHANGELOG | One final Review entry added without deleting prior history |
| ROADMAP | n/a: no milestone/checkpoint status changed |
| Selector manifest | n/a: no selector change or acceptance |
| LESSONS | Existing single-writer and non-vacuity guidance, no new lesson |
| Consolidation under CLEAN_UP_POLICY | n/a: no historical documents retired or replaced |
| Successor frozen | `M6-CP3-CB104-P13-A3-RECORDED-BOUNDARY-INTERVALS` only; CB104 must meet the source-and-test gate above; separate TB87 thereafter |
| Turn boundary held | No production, test, selector, compile, or runtime mutation during this Review |
| review_check.py boundary | Static review boundary checked locally against exact patch path census; full `review_check.py boundary` cannot be run against an original-history Git checkout inside ChatGPT Web snapshot, so **not independently established** |
| `STATUS` lifecycle maintained | Entry/resume beacon retained; final COMPLETE beacon must be direct-write only after verified remote review publication |
| Pushed to origin, branch in sync | Verify connected GitHub remote update/readback; `git status -sb` against remote is unavailable in extracted source snapshot and is not claimed |
