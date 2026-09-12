# M4-CP3-TB4 Review Record — effective hard-feature authority invalidates the intended torus discriminator

**Turn:** `M4-CP3-TB4-REV`
**Status:** COMPLETE / CANDIDATE REJECTED / TEST-AUTHORITY FIXTURE-PRECONDITION COMPOSITION DRIFT / NON-STABLE
**Reviewed package:** `10292005428`
**Reviewed semantic source:** `9d66fcebe4b91ab74a6d0234c46643a2723ab643`
**Reviewed TB run/job:** `34674553424 / 103501973294`
**Reviewed TB result artifact:** `10292016472`
**Reviewed TB log artifact:** `10291946526`
**Accepted authority retained:** corrected R4 artifact `10289601000` / selector403 `c3f509afc823cd73761bdebea0d072d497acf5587a013cb52b795f273af70cb7` / **403/403**
**Candidate selector408:** `c689c0cd8a51f9a8bd8c9ed3a2e8b603728d5a0359ee2732f776a422744b0484` / NOT PROMOTED
**Stable accounting:** **47 events / 14 categories / 33 recurrences**, produced-witness debt **5**
**Checkpoint:** `G4-B002` OPEN / M4-CP3 OPEN
**Successor:** `M4-CP3-CB7` test-authority-only Code + Build; runtime-free

## 1. Review boundary and source authority

This is a Review + successor-plan turn. No Directional runtime, configure, compile, relink, generated discovery,
benchmark, package repair, product/test/fixture/selector/build-semantic mutation, or package mutation is authorized.
The same agent is permitted to review because `AGENT_POLICY.md` explicitly defines independence as evidence/derivation
independence unless a criterion separately requires personnel separation.

The exact review source snapshot is `dc65e2e5f1383f62e8294ce8561486df4f9d0ab7`, captured by source-snapshot
run `34674677422`, artifact `10291384700`, provider SHA-256
`ec5052b2438e0951a31b866f09d4162860dc2b9400f8327897caa8b0d609e74b`. The internal snapshot manifest verifies
**5264/5264** files. The packaged semantic source was separately materialized from candidate artifact `10292005428`.
Across the complete code surface `src/`, `include/`, `tests/`, `benchmarks/`, `cmake/`, and root `CMakeLists.txt`,
package source and review source contain exactly **387 files / 387 files, zero path differences, zero byte differences**.
Static review of current code is therefore valid evidence about the tested package source.

## 2. Immutable package and selector authority — independently re-derived

The candidate package re-verifies as follows:

```text
artifact                                10292005428
outer SHA-256                           7723188540182f9515b95efd83c13dd1dbc6f0813532a98cd8df0778a12a882f
semantic source                         9d66fcebe4b91ab74a6d0234c46643a2723ab643
package SHA256SUMS SHA-256              26529a4d12434bc737e4952f09f9790dd8f36d4151e1500154fa7a60497101af
manifest entries / verified             28 / 28
source archive SHA-256                  3c82e4778ec4ea4631e25d39ed18f7f7ed68a2a24a1ad08e3ebfe298dfe331a9
runtimeExecution                        false
selector403 SHA-256                     c3f509afc823cd73761bdebea0d072d497acf5587a013cb52b795f273af70cb7
selector408 SHA-256                     c689c0cd8a51f9a8bd8c9ed3a2e8b603728d5a0359ee2732f776a422744b0484
selector408 rows                        408 LF identities
selector408 first403                    byte-identical to selector403
owner partition                         30 / 262 / 75 / 41
missing / ambiguous owners              0 / 0
row408 owner                            directional_surface_cell_producer_tests
```

The 408-way owner partition was independently reconstructed from packaged test definitions and CMake source
membership, not copied from the CB6 record. Row408 remains exactly
`RemeshPipeline.ExactA3ToA4TorusProductionPathPublishesTypedSharedBoundaryIdentity` and is uniquely producer-owned.

## 3. TB4 mechanics — valid semantic RED

The raw TB4 result and log artifacts are internally consistent and satisfy the frozen fail-fast contract.

```text
workflow run / execute job               34674553424 / 103501973294
result artifact                           10292016472
result artifact SHA-256                   6d3992f3faa0f9f925a35f4ed0afcffcfc3ec2910fc48f3c1d88cc1183040a0f
log artifact                              10291946526
log artifact SHA-256                      072fa3127455e6f886e41e91f7465d57601168b13055f26bae900a2cb54abb51
immutable preflight                       PASS
processes executed / frozen maximum       1 / 821
phase A                                   1
phases B/C/D/E                            0 / 0 / 0 / 0
first identity selection                  exactly 1
skip / crash / timeout                    0 / 0 / 0
first identity exit                       1
immutable postflight                      PASS
```

The first process was row408. It reached the production fixture and failed at
`tests/FieldAlignedCurveNetworkTests.cpp:15165` on `fixture.network.has_value()`. The only published terminal code in
that test output is `InvalidFieldTransportAtlas`. The raw evidence does **not** publish the nested
`FieldTransportAtlas` typed error, so this Review does not invent one. Frozen fail-fast correctly stopped all remaining
820 processes. Package manifest, selectors, source archive, executable modes, package census, source census and
execution-view census were byte-identical pre/post.

This is **SEMANTIC RED**, not orchestration RED.

## 4. Non-vacuity and decisive reachability re-derivation

TB3 failed because row408 supplied no explicit `userHardEdges`; CB6 correctly changed that fact. CB6's helper now
adds two explicit source-edge cycles:

```text
minor  0-3-25-37-49-61-0
major  0-1-4-6-8-10-12-14-16-18-20-22-0
```

The Review independently re-proved the static topology of **those 18 user edges themselves** against committed
`torus.obj`:

- source `V/E/F = 72/216/144`, all edges two-sided, connected, `chi=0`, closed genus 1;
- all 18 requested pairs are distinct existing source edges;
- each cycle is simple except closure, the cycles meet only at source vertex 0, and the coordinate parameterization
  makes them independent torus generators;
- the 18-edge barrier graph has `V=17, E=18`, vertex 0 degree 4 and every other barrier vertex degree 2;
- cutting that 18-edge union gives `V/E/F = 91/234/144`, `chi=1`, 36 boundary edges in one degree-2 boundary loop:
  a connected genus-0 disc complement.

So the CB6 **graph-theoretic proof was correct for the 18 explicitly requested edges**. The defect is that those
18 edges are not the complete effective hard-feature authority consumed by production.

## 5. Decisive finding — CB6 proved the additive user set, not the effective production hard set

`AdaptiveFeatureMapBuilder::classify_edges(...)` first honors `userHardEdges` as hard, but for every other manifold
edge it also runs automatic dihedral/relative-strength classification. `surface_cell_feature_edge_is_rail(...)`
then admits every `Boundary` or `Hard` edge. `build_authoritative_surface_cell_rails(...)` and
`hard_feature_edge_keys_from_rails(...)` therefore forward the **union** of explicit hard tags and automatically hard
edges into the topology/A1 authority.

The committed torus under the default `AdaptiveFeatureMapOptions` used by `cp4c_remesh_options()` has independently
re-derived dihedral statistics:

```text
p50  = 26.1286268590 deg
p75  = 58.2948525281 deg
p90  = 60.8525737360 deg
p95  = 60.8525737360 deg
p98  = 60.8525737360 deg
max  = 60.8525737360 deg
cadLike = false
```

Applying the production classifier exactly yields **48 automatically hard edges**. They form four disjoint closed
12-edge curves, so `regularize_automatic_hard_curves(...)` does not demote them: every curve exceeds the organic
minimum hard-curve length. The 48 automatic hard edges have **zero overlap** with the 18 explicit user edges.
Consequently row408's effective production hard-feature authority is **66 edges**, not the 18-edge canonical cut graph
CB6 intended to test.

Re-deriving topology from those effective 66 rails yields **five** source topology regions with face counts
`24 / 24 / 24 / 48 / 24`, rather than one torus region carrying the intended two-generator cut graph. The explicit
user edges that remain internal to those regions occur with counts `1 / 1 / 1 / 2 / 1`; after those internal barriers
are cut, each transport domain is disc-like (`chi=1`, one boundary loop). Independent exact-cycle reconstruction also
finds integral cycle lifts for this effective decomposition. These static facts do **not** identify the nested atlas
error; they do prove that the fixture reaching A1 is not the fixture whose topology CB6 guarded.

This is the decisive falsification of CB6's test-authority premise:

> `userHardEdges == intended hard authority` is false for this production path.

CB6 checked a correct 18-edge cut graph, then production composed in 48 additional hard rails before A1. TB4's early
`InvalidFieldTransportAtlas` is therefore evidence about an uncontrolled **66-edge** feature-map input, not evidence
that the intended 18-edge A3→A4 shared-boundary cutover is defective.

## 6. Classification and candidate disposition

### `M4-CP3-TB4-REV-CAND-01`

**OPEN / TEST-AUTHORITY / FIXTURE-PRECONDITION COMPOSITION + REACHABILITY DRIFT / NON-STABLE.**

- **Root cause:** row408 controls the additive user-hard-edge set but does not control automatic hard-feature
  classification. Its CB6 derivation guard reasons over 18 rails while production consumes 66.
- **Observed effect:** the first frozen TB4 process fails at `fixture.network.has_value()` with top-level
  `InvalidFieldTransportAtlas`, before A2a/A2b/A3/A4 and before every intended shared-boundary assertion.
- **Falsifier for the correction:** under the row408-specific options proposed for CB7, re-run the production
  feature-map classification statically and prove the effective hard-feature set is exactly the 18 frozen user edges,
  with automatic-hard count zero and no other rail-producing class on this closed torus. If any nineteenth effective
  hard rail remains, or the topology is not the one-region two-generator/disc-complement witness, **STOP before
  mutation/build**.
- **Corrective owner:** `M4-CP3-CB7`, test-authority only.
- **Forbidden:** production semantic change, selector change, rows404-407 change, tolerance/fallback weakening,
  ignoring automatic rails downstream, hand-editing rail products, or diagnosing the unreported nested atlas error.

`M4-CP3-TB3-REV-CAND-01` is **resolved as written / superseded**: CB6 did add explicit hard rails and TB4 no longer
fails with `phaseFront=NotApplicable`; however, its broader witness goal remained unmet because the effective
production precondition was still uncontrolled. The new TB4 candidate owns that remaining defect.

## 7. Existing production cutover remains unadjudicated, not disproved

Rows404-407 from TB3 remain valid fresh focused evidence for their own CB5 subjects. TB4 did not execute them because
its corrected row408 was intentionally first and failed. Selector408 was therefore never cumulatively re-proved after
CB6, and package `10292005428` / selector408 cannot be promoted.

Nothing in TB4 demonstrates an accepted-green loss. The accepted R4 package/selector403 stays authoritative at
403/403. Stable accounting remains **47 / 14 / 33**, debt **5**. `G4-B002` and CP3 remain OPEN.

## 8. Bounded correction independently derived

There is already an in-tree test-authority precedent for the needed fixture isolation. In
`AdaptiveFeatureMapPhase11.DensityDoesNotLeakAcrossDisconnectedCloseSheet`, the test preserves a user hard edge while
setting both CAD and organic absolute dihedral bands to `179.0 / 180.0`. Because explicit user hard tags are classified
before automatic scoring, those thresholds do not weaken the explicit rails; on this torus, whose maximum dihedral is
~60.853 degrees, they make automatic strength zero.

The successor may therefore change only `cp4c_torus_hard_rail_remesh_options()` to set:

```cpp
options.surfaceCells.featureMap.cadAbsoluteLowDegrees = 179.0;
options.surfaceCells.featureMap.cadAbsoluteHighDegrees = 180.0;
options.surfaceCells.featureMap.organicAbsoluteLowDegrees = 179.0;
options.surfaceCells.featureMap.organicAbsoluteHighDegrees = 180.0;
```

before adding the existing 18 user hard edges. This is test-fixture control, not a production semantic change.
`M4-CP3-CB7` must nevertheless run the effective-authority falsifier before mutation and compile/package only after it
passes.

## 9. Review obligations / prior observations

- Accepted selector403 and candidate selector408 were re-hashed; prefix preservation is exact.
- The 408 identities were independently repartitioned by packaged owner; totals remain `30 / 262 / 75 / 41`.
- Row408 is non-vacuous as a failure witness: one exact identity selected, it entered production, and it failed on
  retained-network publication. It is **not** non-vacuous for the intended A3→A4 seam because it never reached that
  seam.
- `M4-CP3-TB1-R1-REV-OBS-01` remains carried/non-blocking; this turn did not independently exercise its multiplicity
  locus.
- `M4-CP3-CB4-REV-OBS-02` remains carried/non-blocking; this turn did not touch its path/sourceFaces divergence seam.
- The TB3 provenance warning remains: the constructed torus row408 is not evidence of a historically observed
  `InvalidHardRailPairing` failure. CP3 closure may claim only that a production torus path carrying shared hard-rail
  authority completes without that failure, once actually runtime-proved.

No new general lesson number is needed. This is another instance of the existing authority-divergence/precondition
composition family: proving an input fragment is insufficient when production deterministically composes additional
authority before the tested seam.

## 10. Decision

**REJECT package `10292005428` / selector408 for promotion.** The TB4 RED is a valid semantic observation but its
fixture does not instantiate the guarded 18-edge witness. It therefore does not establish a product regression or
falsify the CB5 exact shared-boundary cutover.

**Exact successor:** `M4-CP3-CB7`, governed by
`Architecture_M4_CP3_CB7_Code_Build_Plan.md`. This Review may freeze that plan but may not enter CB7 implementation.

## 11. Mandatory review closeout

| Review obligation | Disposition |
|---|---|
| Accepted selector prefix re-hashed | PASS — selector403 `c3f509...70cb7`; selector408 `c689c0...484`; first403 byte-identical |
| Decisive claims independently re-derived | PASS — package/source identity, TB mechanics, effective feature classification, topology partition |
| Non-vacuity checked | PASS — row408 selects 1 and fails in production; intended A3→A4 seam not reached |
| Prior obligations discharged/carried | PASS — TB3 candidate superseded; two non-blocking observations and provenance warning carried |
| Stable accounting | UNCHANGED — 47 events / 14 categories / 33 recurrences; debt 5 |
| New candidates/obligations recorded | PASS — `M4-CP3-TB4-REV-CAND-01` owned by CB7 |
| ORIENTATION currency line | UPDATED to TB4-REV |
| ORIENTATION §3/§4/§7/§8 | UPDATED — authority, torus witness, open problem, recurring authority-composition instance |
| CHANGELOG | UPDATED |
| ROADMAP | UPDATED — CP3 remains active; CB7 next |
| Selector manifest | UPDATED — selector408 remains candidate/unpromoted; no selector bytes changed |
| LESSONS | NO NEW NUMBER — existing authority-divergence pattern cited |
| Consolidation | COMPLETE — superseded CP3 per-turn records folded/indexed; accepted TB2-R2 runtime report and selectors retained |
| Successor frozen | PASS — `M4-CP3-CB7` test-only/runtime-free |
| Turn boundary held | PASS — review/planning only; no product/test/fixture/selector/build mutation or Directional runtime |
| `review_check.py boundary` | PASS — `ALL CHECKS PASSED`; no product/test/fixture/build or selector mutation |
| Pushed to origin branch in sync | PASS criterion — this record is published only by verified patch application; final branch sync is re-read during closeout |
