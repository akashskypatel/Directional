# CB-214 exact manifest and TB-EXEC-191 contract (2026-11-27 UTC)

**Review artifact only.** Frozen by [`M6-CP3-DEFN-P13-A4-DISC-DOMAIN-CONSTRUCTION`](../Architecture_M6_CP3_DEFN_P13_A4_Disc_Domain_Construction_20261127.md). Nothing here has been applied, built or run.

Review checks, all run in throwaway `CLAUDE_` worktrees that have since been removed:
- `git apply --check`, exact replay and `git diff --check`;
- clang++ `-fsyntax-only` on the preimage and postimage of the three translation units. This is not compile evidence. Results are in the DEFN record.

## `M6-CP3-CB-214-P13-REGION-BOUNDARY-SCHEDULE` — Code + Build, compile only

**Diff:** [the diff file](../Architecture_M6_CP3_CB214_P13_Region_Boundary_Schedule_Exact.diff), 17,530 B, SHA-256 `0fc97ddc4ac033281a1bc6c8ce9eafd379e89a888f5906ccf3c74a1f59b8c02b`. It touches four paths, +316/−0, at source `6b57f90f0` (product bytes identical to the CB-212 source `39253c63…`).

| Path | Preimage SHA-256 | Postimage SHA-256 |
|---|---|---|
| `include/directional/geometry/GlobalConformityBaseline.h` | `4b8bf70125ca51deeba705fca4aa7b7077548f66c6c4b550ff1329731cb0369f` | `8a7e7494bbf2ce0a5a9788aa0e19da4955ea9106dad033c6eb6f33edbcdea4ed` |
| `src/geometry/GlobalConformityBaseline.cpp` | `ed146974fab85efdf176b29088c2a7df018deabe8aef183ae5e4bcad59ea1f44` | `b618379d7650bc7e328c8132a54bc1c972e940b8cdd7f476c835c7600249b63e` |
| `tests/GlobalConformityBaselineTests.cpp` | `90b253a6b26e150d95e4b0d0f0db0e984c34cb2135f233756c0c9994e0748aa5` | `f2af899124229b078bf5d58f3d7b7357e11a58ffe3a15f930708cf66df9df47b` |
| `tests/SurfaceCellTracingDisplayTests.cpp` | `6149b26dc7564342261920c1b669e25dfd61cb3ba323cf844ecff07aa65f16cc` (the CB-212 postimage) | `004b6afb0ed74e9236f21b829b025da25489123d62416cba979289603481d630` |

**Change:**
- **Product (A4 input, behaviour-neutral):** `build_region_boundary_schedules(topology, baseline)` returns, for every A2b region in plan order, each boundary-walk occurrence bound to its A3 span. Each bound occurrence records:
  - the walk-ordered start and end nodes;
  - the incidence;
  - the chain ordinal and its direction;
  - the span count;
  - the region's boundary count, with each incidence counted once.

  Otherwise it returns a typed failure, an enum with a `_name()` function and three reasons:
  - `TopologyPlanMismatch`;
  - `ArcNotScheduled`: the arc's path is not its binding's support slice;
  - `IncidenceNotFound`.

  No pipeline, producer, digest or hashed structure calls it or changes.
- **Tests:**
  - Two new `GlobalConformityBaseline` tests, as gate rows 1007 and 1008:
    - binding on the square fixture under the pipeline's per-arc input;
    - rejection of another plan's baseline and of a foreign-support baseline.
  - Row858 prints one sphere summary, 14 sphere region lines and one genus_two summary after the existing 45 receipt lines. The existing assertions are unchanged.

**CB steps:**
1. Verify the diff hash and the four preimages.
2. Apply.
3. Compile the eight GMP/GMPXX targets (`directional_core`, `directional_pipeline`, `directional_surface_cell_authority_kernel_tests`, `directional_surface_cell_producer_tests`, `directional_surface_cell_completion_tests`, `directional_surface_cell_validation_tests`, `directional_compiled_api_tests`, `directional_benchmarks`) with `runtimeExecution=false`.
4. Require an immutable package and 28/28 checks.

STOP on any hash, path, patch or compile mismatch. Do not adapt the diff, and do not run anything.

## `M6-CP3-TB-EXEC-191` — full gate on the CB-214 package

**Inputs:**
- the CB-214 package;
- the same executor and harness `423f385b73c3825ce9fe18fbd5ca395287620475deb621389f0efbaa601e572c`;
- **manifest [1008 rows](Architecture_M6_CP3_CB214_TB191_Region_Boundary_Schedule_Full_Gate_Case_Manifest.tsv)**, SHA-256 `ca16b66da3cb52e77a3540c79f9357e3e9e59b211bae872f87d58f60c4434081`. Its header plus rows 1–1006 are byte-identical to `a9b8083269ebd0786f0584d66c1f89f43362d884840ab95b95c3d0fa59ca0587`;
- deferred `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce` (81), so membership is 1089 = 1008 + 81.

No rebuild, retry, timeout substitution or V5.

**Comparisons**, under frozen N1–N3 against TB189 result `15171482516`:
- **Every one of the 1008 rows must PASS.** Rows 1007 and 1008 are new GUARD rows.
- **Rows 1–1006 except row858** must be N1–N3-equal to TB189. That includes the controls 393, 648, 669, 843, 844, 963, 968, 971, 972, 978, 979, 1005 and 1006.
- **Row858:**
  - Every byte up to and including the last TB189 receipt line (the 45th new line, `SphereAuditedBridge …`) must equal TB189.
  - Exactly the following 16 lines follow, in order. Then the suffix must be N1/N2-equal to TB189.
- **Recorded predictions.** A mismatch is STOP for review, never a repair.
  - `SphereRegionBoundarySchedules built=1 regions=14 sides=60 arcs=30 pairedArcs=30 otherArcs=0`.
  - 14 `SphereRegionBoundarySchedule` lines, for regions 0 to 13 in order:
    - `sides` = 4, 6, 4, 4, 4, 3, 5, 4, 4, 4, 3, 5, 4, 6;
    - `even=1` on every line;
    - every count ≥ 1.
    - `boundaryCount`, `counts` and `nodes` are measured and recorded verbatim.
  - `GenusRegionBoundarySchedules built=1 … otherArcs=0` (closed and orientable). The region, side and arc totals are measured.
  - `built=0`, `unavailable` or any `otherArcs>0` falsifies the binding claim for trace-bounded discs. Record the failure reason and the occurrence; do not repair.

**Not allowed:**
- gate credit before `M6-CP3-TB-REV-191`;
- any producer or dispatch change, or removing the veto;
- B1 or fallback repair;
- CB-207D;
- promotion of CP3/497/D0/H4.
