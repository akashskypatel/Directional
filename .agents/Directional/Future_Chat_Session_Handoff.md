# Future Chat Session Handoff

## Mandatory next turn

Run **artifact-only Test + Benchmark** under:

`.agents/Directional/Gate_4_Torus_Multi_Rail_Chart_Reachability_Artifact_Only_Test_Benchmark_Plan.md`

Consume compile artifact `9031804178` and log artifact `9031804382`
exactly. Do not configure, rebuild, relink, edit implementation/tests/
fixtures/validators/manifests/CMake/workflows, or substitute another
artifact.

Repository:

- `akashskypatel/Directional`;
- branch `agent/surface_cell_quad/p5-recover-bridge-healing`;
- draft PR #8 remains open, draft, and unmerged;
- active gate **G4 topology-distinct completion and singularities**;
- review policy `never`;
- Code + Build cleanup head before documentation closeout:
  `01b80ac65968906a9d871cee81f154653f452270`.

## Mandatory regression-pattern review — every future turn

The review policy `never` controls the optional independent-review default; it
does **not** waive this mandatory regression-pattern review. Before changing
code, running a project executable, or interpreting runtime evidence, every
future turn must:

1. read the repeated coding-pattern catalog in
   `.agents/Directional/Regression_Root_Cause_Tracker.md` and the supporting
   point-in-time evidence in
   `.agents/Directional/PR_8_Regression_Audit_Inventory.md`;
2. map the planned producer, representation, consumer, validator, test, and
   build-authority data flow against `RP-01` through `RP-09`;
3. record the following table in the turn plan or closeout:

| Pattern | Touched? | Exact affected producer/consumer | Evidence the anti-pattern is absent, or corrective invariant | Counterfactual and representative gate |
|---|---|---|---|---|
| `RP-01` … `RP-09` | yes/no | exact symbol, target, or artifact boundary | concrete invariant and inspection evidence | named focused negative and representative positive evidence |

Any touched row that cannot be completed is a stop condition: revise the
design before Code + Build or runtime. If a proposed change resembles a
cataloged anti-pattern, or changes the same data flow as a cataloged event,
use an already accepted design proof or schedule an independent architectural
Review turn before Code + Build. Do not repeat the earlier implementation or
test shape under a new name.

Test + Benchmark turns must map failures to an existing pattern and stable
event ID when applicable, distinguish persistence from a new recurrence, and
update the tracker counts only from direct evidence. Every turn closeout must
keep the tracker, audit inventory, handoff, and milestone status consistent.

For the mandatory next artifact-only turn, review `RP-09` (global authority
consumed as local face authority) and `RP-02` (proxy or incomplete test
authority) before interpreting the face-chart and torus results. This review
does not authorize any artifact substitution, rebuild, or source/test edit.

## Completed Code + Build authority

Implementation `6af23d9aeca29e63aa13c4ae49f50d1748939c49`
changes exactly five allowlisted paths. The conditionally allowlisted
`src/pipeline/RemeshPipeline.cpp` remains byte-identical.

The shared optimizer/validator resolver now:

1. validates every retained source chart and hard-rail relation independently
   of face choice;
2. builds exact per-output-vertex chart-component graphs;
3. derives scalar-rooted reachable components deterministically;
4. validates relation reciprocity against complete output authority;
5. selects the unique face-wide reachable-component intersection;
6. requires a witness only for the selected non-scalar chart;
7. preserves scalar barycentric, position, component, sheet, and source-entity
   checks.

Four focused contracts cover a chained multi-rail witness, an unused valid
relation, an off-face reciprocal peer, a missing graph link, and face-row
invariance. Existing one-relation, tamper, ambiguity, disconnected-sheet, and
scalar typed-failure contracts remain.

## Immutable compile evidence

| Evidence | Value |
|---|---|
| Workflow run/job | `31292116792 / 93190952157` |
| Result artifact | `9031804178` |
| Result outer SHA-256 | `27d16f485c357a236ffd43ce09c335bd246cb3f276cd9cc85b572ca543d87e9e` |
| Log artifact | `9031804382` |
| Log outer SHA-256 | `5d0b8d0defa3fc371d71160e1db266d3df8037e14c87cf64181b51637cb8a905` |
| Recursive manifest | **49/49**, `2fec5670eb81972233c52c9db1afe82e7eb92da812f1ab537a018bb0d31fb7e2` |
| Patch | `b7490fabd6d7490e1f8f24d47126b26d07866939fc8142e8c4ef8edd4b89d300` |
| Source archive | `df6e14e60679ccb25fa832d762fe7d31fdf40de746a5659e20998b72e7232900` |
| Compile database | `60fd05acc3e68a369aacacfa3c24b5582687f7ee6d6b959b9267639dd37fc508` |
| Compile | Release/static/Ninja, **113/113**, `PRE_TEST`, `runtimeExecution=false` |
| Retention | through 2026-08-23 UTC |

Both ZIPs pass integrity and path-safety checks. The package contains exactly
50 files, five ELF executables, two static libraries, and 27 exact fixtures.
The source archive reproduces all seven recorded source/CMake blobs, the patch
names exactly five implementation/test paths and reverses cleanly, and the
compile log has zero failure markers. No generated project runtime was
executed.

The temporary workflow was deleted before its trigger. Final cleanup at
`01b80ac65968906a9d871cee81f154653f452270` has no tree difference from
the implementation and retains only
`.github/workflows/agent-source-snapshot.yml`.

## Entering runtime baseline

The runtime baseline remains artifact `9030700527`, implementation
`8f37612148f34bac63cf294000c17c7de2e03b41`:

- four prior cases direct strict-valid **3/3**;
- torus **0/3**, 192 completed quads, complete lineage, complete `4/8/4`
  consumption, `1/0/0` topology, then 165 `LocalSheetMismatch` issues;
- pre-regression artifact `9029584083` reported 74 issues;
- focused face-chart **7/7**, canonical **7/7**;
- bounded producer **154/163**, completion **154/164**, validation **67/67**,
  API **8/8**;
- historical exact-torus GoogleTest fails upstream at
  `InvalidHardRailPairing`;
- prescribed sphere was not run.

## Required artifact-only acceptance

1. Verify both artifact ZIPs, all 49 manifest entries, package/source
   closure, toolchain/submodules, and `runtimeExecution=false`.
2. Discover each GoogleTest executable exactly once.
3. Run the four new multi-rail tests, seven existing face-chart tests, and
   seven canonical tests individually.
4. Record the historical exact-torus result separately.
5. Preserve the six focused groups and bounded producer/completion/
   validation/API suites.
6. Repeat plane → seam → close sheets → cylinder → torus in three fresh
   recovery-disabled processes.
7. Require direct torus strict-valid **3/3**, complete lineage, no
   fallback/recovery, complete `4/8/4` consumption, pure quads, and final
   `1/0/0` topology. Reduced mismatch count is not acceptance.
8. Do not run prescribed sphere; the independent exact-torus scheduling
   blocker remains unresolved.

## Regression and architecture tracking

`.agents/Directional/Regression_Root_Cause_Tracker.md` is the permanent
stable-ID regression record. `G4-R007` is `fix_pending_runtime`; compile
success does not resolve it.

An independent documentation-only PR #8 audit through
`027e5194a9013cc1fe9ea18c1b79741301e40f74` identifies **34 distinct
regression events** in **14 architectural categories**, including **20
recurrences**. The evidence inventory is
`.agents/Directional/PR_8_Regression_Audit_Inventory.md`. Only
`PR8-R034` / `G4-R007` remains active, as `fix_pending_runtime`; the audit does
not change the mandatory artifact-only next turn or its immutable inputs.

The expanded point-in-time source/test/build audit catalogs **nine repeated
coding patterns** (`RP-01` through `RP-09`) spanning **29 events** and all
**20 recurrences**. The five remaining events are singletons and are not
misclassified as repeated patterns. The tracker contains pseudocode for each
observed anti-pattern, its required implementation shape, and its review
guard. The mandatory per-turn review above applies even when no production
file is expected to change.

The cause families `AUTHORITY_DOMAIN_CONFLATION` and
`LOCAL_CONSUMPTION_OF_GLOBAL_AUTHORITY` have repeated three and two times,
respectively. Both already require independent architectural review. The
artifact-only closeout must update the existing entry on recurrence rather
than create a duplicate, or add one stable ID only for a genuinely new
regression.

Nonzero periodic rotation, shared hard-rail breakpoint scheduling, positive
multi-isolation lineage, historical completion/timing, sphere, G5/G6,
fallback/recovery, and optimization remain deferred.

After branch records and PR body are updated, the final repository write must
be one new top-level PR #8 conversation comment.

Last updated: 2026-08-09 UTC
