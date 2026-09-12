# M4-CP3-CB7 Code + Build Plan — isolate row408 effective hard-feature authority

**Turn:** `M4-CP3-CB7`
**Status:** FROZEN BY `M4-CP3-TB4-REV` / NOT STARTED
**Turn type:** test-authority-only Code + Build / runtime-free
**Entering accepted runtime authority:** artifact `10289601000` / selector403 `c3f509afc823cd73761bdebea0d072d497acf5587a013cb52b795f273af70cb7` / 403/403
**Rejected candidate:** artifact `10292005428` / selector408 `c689c0cd8a51f9a8bd8c9ed3a2e8b603728d5a0359ee2732f776a422744b0484`
**Owner:** `M4-CP3-TB4-REV-CAND-01`
**Future runtime successor if build green:** full fresh `M4-CP3-TB5-EXEC`, then mandatory Review

## 1. Problem frozen by Review

CB6 correctly proved that the two explicit user-hard-edge cycles form a one-vertex two-generator torus cut graph with
disc complement. It did **not** prove those 18 edges equal production's effective hard-feature authority.

Production feature classification unions explicit `userHardEdges` with automatically classified `Hard` edges before
`surface_cell_feature_edge_is_rail(...)`, authoritative rail construction and A1. Under the CB6/default options the
committed torus contributes 48 automatic hard edges, disjoint from the 18 explicit edges, so row408 actually enters
production with 66 hard edges and five topology regions. TB4 then fails at network publication with top-level
`InvalidFieldTransportAtlas` before the intended A3→A4 seam.

CB7 exists only to make the test fixture's **effective** production hard-feature authority match the already-proved
18-edge witness. It may not change product semantics.

## 2. Mandatory pre-mutation effective-authority guard — STOP on any failure

Before modifying any repository byte, independently reproduce the committed torus feature-map classification with the
proposed row408-only options and prove all of the following:

1. committed torus remains `V/E/F = 72/216/144`, connected, closed, every edge two-sided, `chi=0`;
2. the two frozen cycles remain exactly:
   - `0-3-25-37-49-61-0`,
   - `0-1-4-6-8-10-12-14-16-18-20-22-0`;
3. all 18 pairs remain distinct actual source edges, cycles simple except closure, intersection only source vertex 0,
   independent generators, and their union has connected disc complement;
4. proposed row408-only options set CAD and organic absolute bands to `179.0 / 180.0` while preserving the existing
   18 `userHardEdges`;
5. production `classify_edges(...)` yields **18 user-tagged Hard edges and 0 automatically Hard edges** on this torus;
6. because the torus is closed, there are no boundary rails; the effective set admitted by
   `surface_cell_feature_edge_is_rail(...)` is therefore exactly the same 18 source edges;
7. production topology-region decomposition under that effective rail set is the intended one-region torus domain,
   and cutting the two internal generator cycles yields the previously proved disc transport domain;
8. no production code, alternate product, tolerance, fallback, local-grid inference, or downstream filtering is
   required to obtain that authority.

**Any failed item is a hard STOP before mutation.** Return to Review. Do not choose different thresholds, remove
automatic rails downstream, weaken A1, or add a second fixture mechanism ad hoc.

## 3. Authorized semantic edit — exactly one helper

If and only if §2 is green, edit only `tests/FieldAlignedCurveNetworkTests.cpp`, only inside
`cp4c_torus_hard_rail_remesh_options()`.

Before inserting the already-frozen two cycles, set exactly:

```cpp
options.surfaceCells.featureMap.cadAbsoluteLowDegrees = 179.0;
options.surfaceCells.featureMap.cadAbsoluteHighDegrees = 180.0;
options.surfaceCells.featureMap.organicAbsoluteLowDegrees = 179.0;
options.surfaceCells.featureMap.organicAbsoluteHighDegrees = 180.0;
```

This exact isolation idiom already exists in
`AdaptiveFeatureMapPhase11.DensityDoesNotLeakAcrossDisconnectedCloseSheet`: user hard tags are classified first and
remain `Hard`, while automatic dihedral scoring is suppressed for geometry well below 179 degrees.

No other test helper, row, assertion, source fixture, production source/header, selector, CMake ownership rule, or
build contract may change.

## 4. Frozen non-vacuity contract

Row408 identity and assertions remain byte-for-byte unchanged:

`RemeshPipeline.ExactA3ToA4TorusProductionPathPublishesTypedSharedBoundaryIdentity`

It must still require:

- authoritative rail snapshot available and non-empty;
- at least one `HardFeature` rail;
- source authority, field-aligned network, topology plan, baseline and trace-network authority retained;
- phase front `Produced`;
- accepted topology/baseline conformity receipt digests;
- at least one `HardRail` front edge;
- exact `sharedBoundaryInterval` on every hard-rail edge;
- terminal detail not `InvalidHardRailPairing`.

Do not weaken or reorder the row to skip an earlier production failure.

## 5. Selector and owner invariants

CB7 must not edit selector bytes. Static re-proof before compile must show:

```text
selector403 = c3f509afc823cd73761bdebea0d072d497acf5587a013cb52b795f273af70cb7
selector408 = c689c0cd8a51f9a8bd8c9ed3a2e8b603728d5a0359ee2732f776a422744b0484
selector408 rows = 408 LF identities
first403 = byte-identical selector403
owners = 30 authority-kernel / 262 producer / 75 completion / 41 validation
missing / ambiguous = 0 / 0
row408 = producer-owned
```

Any selector/owner drift is a STOP.

## 6. Compile/package boundary

After the test-only edit, compile/package only through the mandatory reusable GitHub workflow with GMP/GMPXX.
Changed-owner preflight must compile `directional_surface_cell_producer_tests` first, followed by the existing frozen
eight-target package set used by CB6.

Required compile evidence:

- exact semantic source SHA;
- changed-owner preflight exit 0;
- full package compile exit 0;
- GMP and GMPXX linkage evidence;
- clean source-status snapshots;
- immutable package manifest and source archive hashes;
- selector/owner re-proof from packaged source;
- `runtimeExecution=false`.

**Forbidden in CB7:** GTest discovery/listing, test execution, benchmark execution, `ctest`, generated Directional
binary execution, CLI/help/version execution, fuzzer/custom-input runtime, or any package repair.

## 7. Build RED routing

A compile/package failure caused by the authorized helper edit may receive only bounded compile/orchestration
remediation. A second semantic dependency, product edit, fixture redesign, assertion change, or selector change returns
to Review; do not expand CB7.

## 8. Future TB5 gate — unchanged 821-process restart

If CB7 builds green, the successor TB consumes the new immutable package and restarts the complete gate from process
1. Do not reuse any TB3/TB4 process as current package evidence.

```text
row408 focused A               1
row408 focused B               1
rows404-407 controls A+B       8
accepted selector403         403
candidate selector408        408
                              ---
total                         821 fresh exact-filter processes
```

The immutable preflight/postflight and fail-fast rules remain the TB4 contract. TB5 execution is mechanical only;
mandatory Review owns diagnosis, promotion, `G4-B002`, CP3 and stable accounting.

## 9. Acceptance of CB7

CB7 is complete only when:

- the effective-authority guard proves exactly 18 effective hard rails before mutation;
- only the four row408-helper threshold assignments are added;
- selectors/owners remain frozen;
- GMP/GMPXX compile/package is green;
- no Directional runtime executes;
- a new immutable candidate package is published for TB5.

CB7 compile success alone does not promote selector408, close `G4-B002`, close CP3, or change stable regression
accounting.

## Amendment — assert the effective hard-rail authority inside row408 (CB4-REV reviewer, TB4-REV §12 V3)

Setting the automatic dihedral bands to `179.0 / 180.0` suppresses automatic classification only because this
committed torus has a maximum dihedral of ~60.85 degrees. That is a property of the fixture mesh, not an invariant:
if the mesh is regenerated, refined or replaced, automatic rails can silently return and row408 would again test an
uncontrolled composite input.

The pre-mutation effective-authority falsifier protects this turn. It does not protect later runs. CB7 must
therefore **also** make row408 assert its own effective precondition — that the hard-feature rail authority
actually reaching the topology/A1 stage is exactly the intended 18 explicit edges, by identity and not merely by
count — before it asserts anything about the A3→A4 seam.

CB6's error was proving an input fragment statically while production composed additional authority downstream.
An in-identity assertion on the effective set turns that failure mode into an immediate, self-describing RED
instead of a two-turn diagnosis, and matches the precondition discipline already used by row392
(`preferredCount`) and row400 (pinned raw and canonical orderings).
