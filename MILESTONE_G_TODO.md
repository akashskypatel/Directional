# Milestone G Production Readiness TODO

Last updated: 2026-08-01 21:08 PDT
Branch: `surface_cell_quad`
Target fixture: `benchmark-results/bunny_1k_random.obj`

## Active implementation branch

- Phase: P5 — recover and complete bridge/pinch topology healing.
- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`
- Draft recovery PR: `#8` (`agent/surface_cell_quad/p5-recover-bridge-healing` → `surface_cell_quad`).
- Recovery baseline: `92db9c701fb9f0cdba3cd3127ebecccf7c77e410`.
- Encoded checkpoint target: local implementation state represented through `062ed12`.
- Status: all decodable staged checkpoints have been reconstructed locally as actual source/test changes. The next remote checkpoint must commit those files directly to the working branch; no additional encoded patch snapshots are permitted.
- Recovery rule: after interruption, resume from this working branch and this tracker. Merge into `surface_cell_quad` only after focused tests and the real bunny direct-completion benchmark close the phase.

## Success criteria

- Produce a conforming, manifold, source-faithful pure-quad mesh for the random-triangulated bunny.
- Preserve cross-field alignment, authoritative feature rails, source-sheet separation, and singularity ownership.
- Reject unsupported/non-disk topology honestly; do not convert failures into synthetic success.
- Keep focused unit/integration tests representative of their stated contracts.
- Pass focused Milestone G tests, Phase 15–20 integration tests, mesh connectivity validation, and the bunny benchmark locally.

## Work phases

- [x] P0 — Establish reproducible local source and dependency snapshot.
- [x] P1 — Review Milestone G plan, failed-fix notes, current checkpoint patches, and benchmark/test harness.
- [x] P2 — Reproduce the current bunny failure and capture stage/cell diagnostics. Optimized run reaches final validation after successful completion and optimization.
- [x] P3 — Restore required nonempty singular separatrix prefixes with fail-closed termination rules.
- [x] P4 — Implement and validate balanced regular-disk quadrangulation for high-side even boundaries.
- [ ] P5 — Resolve required singular-support endpoints and remaining direct-completion failures without weakening validation. **In progress**
- [x] P5A — Make SurfaceCells fail closed without invoking legacy `setup_integration()`, `integrate()`, or legacy meshing.
- [ ] P6 — Validate topology, provenance, source projection, field alignment, determinism, and quality metrics.
- [ ] P7 — Run focused and broader regression tests; repair only real implementation or fixture defects.
- [ ] P8 — Run final bunny benchmark and document production-readiness evidence and remaining limitations.

## Current checkpoint

- Recovery workflow transition: the previously staged encoded P5 checkpoint chain has been reconstructed into 23 actual source, test, benchmark, plan, and tracker files on the active working branch checkout. These recovered changes are not treated as verified until they compile and pass the focused regressions and real bunny benchmark in the container.
- Production fallback contract changed: a failed SurfaceCells request terminates in SurfaceCells and never invokes `setup_integration()`, `integrate()`, sparse integer factorization, or the LegacyInteger mesher. `TryLegacy` is now a deprecated source-compatible alias of `Fail`, while parser/CLI input `TryLegacy` is rejected.
- New tests use a valid planar field and an injected late SurfaceCells failure that previously allowed a successful legacy fallback. They now require no output, `executedBackend=SurfaceCells`, no fallback attempt, and zero integration/mesher timings, integer iterations, direct factorizations, and numeric-factorization time. This is not a malformed-input shortcut.
- All future SurfaceCells benchmarks use `fallbackPolicy=Fail`. A run only counts as SurfaceCells success when its origin is `CompletedSurfaceCells`; LegacyInteger comparison remains a separately requested benchmark case and never a fallback continuation.
- Validation after the fail-closed fallback change: all 52 focused P23/Phase 20 tests pass. The transition-identity regression was corrected to build a nondegenerate destination chart for each authoritative matching value; it still verifies shuffled source-edge transition records by both matching and unique effort without requiring unrelated second-segment continuation. Evidence: `build/mg-debug/results/p5a-no-legacy-p23-phase20-v3.json`.

- Corrected Milestone G P26 fixture tests so the fieldless random bunny exercises the library-calculated cross-field path instead of passing an empty raw field. Prescribed-field-only tests still cover all eight paired field fixtures.
- Applied the narrow singular-separatrix contract change: nonempty required prefixes terminated by later geometric degeneracy remain explicit completion obligations; invalid field metadata and source-sheet terminations remain unusable.
- Added focused tests for both retained degenerate prefixes and fail-closed metadata/sheet terminations.
- Validation after P3: 6/6 focused tests passed; all 125 Phase 15–18 tests passed.
- Implemented balanced recursive quadrangulation for even regular-disk boundaries with more than six logical sides. It preserves the complete boundary, emits exactly `n/2 - 1` quads, distributes diagonal endpoints, and keeps unsupported non-disk/singular cases fail-closed.
- Validation after P4: 2/2 focused topology tests passed; all 127 Phase 15–18 tests passed.
- Test evidence: `build/mg-debug/p3-focused.json`, `build/mg-debug/p3-phase15-18.json`, `build/mg-debug/p4-focused.json`, `build/mg-debug/p4-phase15-18.json`.
- Optimized random-bunny result after P3–P4: completion emits 2,256 quads, optimization completes 13 iterations, and the pipeline now fails honestly at final validation with 39 counted failures instead of failing during completion.
- Runtime evidence: 258.75 s pipeline time, 364,512 KiB peak RSS. Artifacts are under `benchmark-results/p28-local/`.
- Detailed validation diagnosis: strict topology, manifoldness, source authority, rails, provenance, sheets, orientation, intersections, and warpage all pass. The 39 failures are exactly 33 required singularity-valence mismatches plus six quantitative gates: field median/P95, size P5, angle P5/P95, and aspect P95.
- The final output is the whole-mesh `SourceGridRecovery` fallback (2,256 quads), not the direct arrangement-cell assembly. It therefore does not yet realize the required singular topology or cross-field/size quality on the random bunny.
- Direct completion currently has 68 failures: 66 pinched/non-disk boundary walks and two valid even regular disks with two logical sides.
- The 66 pinched walks contain 132 two-halfedge bridge excursions. Of those, 131 are required `singularitySupport` segments from unresolved separatrix prefixes; one is a hard-feature bridge.
- Endpoint completion sees 88 open tips, resolves 13, adds 30 connector arcs, and leaves 75 unresolved because the pipeline currently sets `requireAllEndpointsResolved=false`.
- These unresolved required tips are the concrete cause of the invalid DCEL face walks; stripping the bridge excursions would erase required singular topology and is not acceptable.
- Current WIP snapshot includes intrinsic endpoint identities, destination-chart transport correction, source-edge split propagation, endpoint diagnostics, balanced completion, and focused regression coverage.
- Removed the optional sub-tolerance-tail pruning experiment after the real bunny proved it invalid: the short terminal segments connect two long support traces, and deleting them changes one bridge into 70 bridges. Independent extension also regressed the arrangement.
- Validation after removing that experiment: all 167 focused Phase 14–18 tracing, FlowRep, arrangement, and completion tests pass. Evidence: `build/mg-debug/results/p5-after-revert.json`.
- Recoverable WIP patch snapshots are published under `.agents/Directional/wip/` before further edits.
- Added structured endpoint-completion diagnostics: per-endpoint resolution class, retry termination reason, segment count, required-support flag, and aggregate termination histogram. Pipeline and benchmark JSON now expose unresolved required endpoint counts and termination counts.
- Canonical endpoint identity now includes source sheet as well as source component, preventing nonmanifold or locally separated source sheets from sharing endpoint ownership.
- Endpoint completion now recognizes a traced terminal point already owned by the retained network through its canonical intrinsic source vertex/edge key, even when the owning arc lies in another source-face chart and cannot be found by same-face segment intersection.
- Added focused same-sheet canonical-vertex capture and cross-sheet non-capture tests. All 193 Phase 14–18 tests pass. Evidence: `build/mg-debug/results/p5-intrinsic-capture-focused.json` and `build/mg-debug/results/p5-intrinsic-capture-phase14-18.json`.
- Optimized random-bunny endpoint result after intrinsic capture: 3,910 open endpoints, 3,892 resolved, 18 unresolved, 13 unresolved required singular supports, and 1,997 added connector arcs. The full pipeline still reaches the same 39 strict validation failures after 261.3 s; evidence: `benchmark-results/p28-local/bunny-intrinsic-capture.json`.
- Added benchmark-stage injection and per-endpoint structured JSON diagnostics so endpoint work can be measured after the strands stage in about 9 seconds instead of paying the 230-second optimizer cost. Evidence: `benchmark-results/p28-local/bunny-endpoint-diagnostics.json`.
- The 18 unresolved endpoints are now concrete: three empty hard-feature retries, two optional traces ending at an unexpected boundary on the closed bunny, and 13 required singular supports. Of the 13 required supports, nine terminate at a feature after 12–128 segments and four exhaust the 128-segment budget.
- Implemented canonical feature-rail interval ownership across adjacent source-face charts. A feature termination is accepted only when its terminal source-edge coordinate lies inside a retained hard-feature rail interval on the same source component and sheet; a `Feature` label alone remains insufficient.
- Added focused positive and cross-sheet fail-closed tests. Validation: 2/2 focused tests and all 195 Phase 14–18 tests pass. Evidence: `build/mg-debug/results/p5-feature-rail-focused.json` and `build/mg-debug/results/p5-feature-rail-phase14-18.json`.
- Fast bunny endpoint benchmark after incident-side sheet ownership is unchanged: 3,910 open, 3,892 resolved, 18 unresolved, 13 unresolved required, and 1,997 added arcs. The nine required feature terminations are therefore not simple adjacent-chart interval matches. Evidence: `benchmark-results/p28-local/bunny-feature-rail-sides-diagnostics.json`.
- Endpoint completion no longer aborts a traced retry when a finite chart-transition segment is at or below the intersection tolerance. It preserves the raw terminal state for ownership diagnostics, skips only the non-representable zero-length segment, and continues processing later valid segments. Non-finite geometry still fails closed.
- Fast random-bunny evidence after this correction: 3,910 open endpoints, 3,894 resolved, 16 unresolved, 13 unresolved required supports, and 2,028 added arcs. Two optional boundary retries now resolve; all 13 required supports remain explicit. Seventeen degenerate transition segments were skipped. Evidence: `benchmark-results/p28-local/bunny-zero-segment-skip-diagnostics.json`.
- Validation after the zero-segment correction: all 45 FlowRep Phase 15 tests and all 196 Phase 14–18 tests pass. Evidence: `build/mg-debug/results/p5-zero-segment-flowrep.json` and `build/mg-debug/results/p5-zero-segment-phase14-18.json`.
- The remaining nine feature terminations still classify their raw terminal nodes as face-interior points with no authoritative rail candidates.
- Corrected another dimensional mismatch in endpoint interception: the intersection guard now converts the spatial tolerance into distance along the current source-triangle segment instead of comparing it directly to a dimensionless trace parameter. A real regression fixture proves that a sub-tolerance crossing at the trace origin is ignored while the later valid network capture is retained.
- Added spatially scaled feature-edge endpoint ownership. A terminal edge point can transfer ownership through an incident source vertex only when its physical distance to that vertex is within the endpoint tolerance and a retained hard-feature rail proves compatible component/sheet ownership. Positive and cross-component fail-closed fixtures pass.
- The last required bunny endpoint was not an unowned feature termination: its first retry segment reached an existing intrinsic network node only `6.8e-11` source units away. The connector was correctly rejected as sub-tolerance, but the original degree-one endpoint remained open. Endpoint completion now reconciles that degree-one endpoint transactionally to the proven same-component/sheet capture point instead of emitting a zero-length arc or dropping the branch.
- Validation after spatial interception and transactional endpoint reconciliation: all 49 FlowRep Phase 15 tests and all 200 Phase 14–18 tests pass. Evidence: `build/mg-debug/results/p5-endpoint-reconciliation-flowrep.json` and `build/mg-debug/results/p5-endpoint-reconciliation-phase14-18.json`.
- Fast random-bunny result after reconciliation: 3,910 open endpoints, 3,905 resolved, five unresolved optional endpoints, **zero unresolved required singular supports**, and 2,000 added arcs. The remaining endpoints are three empty open hard-feature retries plus two optional singular-vertex retries; no required topology is silently discarded. Evidence: `benchmark-results/p28-local/bunny-endpoint-reconciliation-diagnostics.json`.
- Full optimized bunny after endpoint reconciliation remains validation-rejected after 260.27 s (643,000 KiB peak RSS): 2,256 recovery quads and the same 39 strict validation failures. The endpoint contract is improved but the production output is still not direct cell completion. Evidence: `benchmark-results/p28-local/bunny-endpoint-reconciliation-full.json`.
- Added an explicit benchmark diagnostic switch, `--disable-surface-cell-source-grid-recovery`, and direct completion counters so the arrangement path can be measured without the recovery mesh masking its status.
- Direct bunny completion now finishes in about 23 s and identifies exactly 16 rejected descriptors out of 21,289; 21,273 patches complete successfully. All 16 are closed one-boundary-component walks rejected as non-disks before patch completion. Evidence: `benchmark-results/p28-local/bunny-direct-completion-diagnostics-v4.json`.
- Twelve rejected cells contain an immediate twin backtrack on a required singularity-support arc. Two of those cells also contain larger repeated-node pinches. One additional cell contains two optional layout-support backtracks, and three cells contain complex repeated-node pinches without an immediate twin pair. Required endpoint ownership is resolved, but these retained support strands still terminate or overlap topologically inside the DCEL.
- Added final retained-arc, arrangement-halfedge provenance, and per-stage endpoint-degree diagnostics for rejected completion descriptors. This exposed a concrete contract violation: ten connectors were marked `endEmbeddedAnchor=true` after the endpoint-completion tolerance accepted near-parallel source-chart lines that the arrangement's exact intersection predicate correctly did not split.
- Endpoint interception now uses the same strict segment-intersection predicate as arrangement construction and snaps committed connector endpoints to the target-chart intersection. A focused regression includes a false near-parallel candidate followed by a real retained-network crossing and verifies the committed anchor has degree at least three in the rebuilt arrangement.
- Direct random-bunny completion after arrangement-consistent endpoint capture improves from 21,273 to 21,283 completed patches and reduces rejected descriptors from 16 to six. Ten required singularity-support bridge cells are eliminated without deleting support topology. Evidence: `benchmark-results/p28-local/bunny-arrangement-consistent-capture.json` and `build/mg-debug/results/p5-arrangement-consistent-capture-focused.json`.
- The six remaining failures are now isolated: three complex repeated-node pinches, one mixed complex cell with a required bridge, one required support bridge whose claimed embedded anchor still has arrangement degree one, and one cell with two optional support bridges. Next action: record the exact capture target/parameter for the two remaining required bridges and prove whether later connector mutation invalidates ownership or whether a source-chart transition needs canonical target transfer.
- Diagnosed the source-vertex-383 failure as a numerical pre-ring return: required support trace 2369 makes four sub-nanometer source-chart segments back to the same singular vertex and then continues outward. The retained prefix formed a homoclinic loop, producing one pinched cell and one valid four-edge/two-logical-side lens.
- Added a scale-aware pre-ring return contract. A required separatrix that returns within `1e-5` of the minimum transition-ring radius and has a later traced continuation keeps the continuation, deactivates only the local return prefix, and reroots the continuation at the exact intrinsic source vertex. Global/post-ring homoclinic paths are not rewritten.
- Added a tetrahedral regression that deliberately returns just outside the old tolerance before continuing across the transition ring. It verifies the prefix is inactive, the continuation remains authoritative, exactly three radial singular supports remain, and every non-boundary center sector is a disk without twin backtracking.
- Validation after pre-ring rerooting: all 55 FlowRep Phase 15 tests and all 209 Phase 14-18 tests pass. Evidence: `build/mg-debug/results/p5-pre-ring-return-flowrep-v3.json` and `build/mg-debug/results/p5-pre-ring-return-phase14-18-v3.json`.
- Direct random-bunny completion improves from five rejected descriptors to two: 21,293 of 21,295 patches complete, unresolved required endpoints remain zero, and the source-vertex-383 pinch/lens pair is eliminated. Runtime is 22.11 s with 732,880 KiB peak RSS. Evidence: `benchmark-results/p28-local/bunny-pre-ring-return-reroot-v2.json`.
- The remaining production blockers are now exactly two complex repeated-node pinches (cells 6822 and 18113 in this arrangement). Next action: classify their repeated-node paths by final retained-arc provenance and repair the underlying overlapping/support topology rather than accepting or triangulating malformed cells.

- Local archive base was remote commit `92db9c701fb9f0cdba3cd3127ebecccf7c77e410`; the container now contains the WIP commit above.
- Recursive submodules are present.
- Working-tree CRLF archive noise was verified as end-of-line-only and normalized locally.
