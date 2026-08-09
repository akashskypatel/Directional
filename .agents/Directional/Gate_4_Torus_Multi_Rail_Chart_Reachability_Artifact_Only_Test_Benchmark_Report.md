# Gate 4 Torus Multi-Rail Chart Reachability — Artifact-Only Test + Benchmark Report

Status: **completed; focused multi-rail correction rejected by representative direct-torus runtime**  
Turn type: **Test + Benchmark only**  
Active design gate: **G4 topology-distinct completion and singularities**  
Date: **2026-08-09 UTC**  
Review policy: `never`

## Outcome

Artifact `9031804178`, implementation
`6af23d9aeca29e63aa13c4ae49f50d1748939c49`, passed exact artifact preflight
and postflight. The four new multi-rail contracts, seven retained face-chart
contracts, and seven retained canonical contracts all pass individually.
Previously accepted plane, multi-face seam, close-sheets, cylinder, retained
focused groups, and bounded suites remain behaviorally stable.

The production acceptance failed. Direct torus is deterministic **0/3** after
192 completed quads with complete lineage, complete `4/8/4`
region/seam/periodic-relation consumption, and materialized `1/0/0` topology.
Final validation reports **241** `LocalSheetMismatch` issues in every run,
versus **165** under entering runtime artifact `9030700527` and **74** under
pre-regression artifact `9029584083`. The multi-rail correction therefore does
not resolve `G4-R007`; it worsens the same unresolved representative failure by
76 issues relative to the entering runtime authority and by 167 issues relative
to the pre-regression reference.

This is persistence/worsening of the still-open `PR8-R034 / G4-R007`, not a
new recurrence event: the affected direct-torus gate was never restored between
artifacts. Historical PR-wide totals remain **34 events / 14 categories / 20
recurrences**.

No implementation, test, fixture, benchmark, validator, manifest, CMake, or
workflow logic changed. No configure, compile, rebuild, relink, or discovery
regeneration occurred. Prescribed sphere was correctly not run.

## Immutable artifact authority

| Authority | Value |
|---|---|
| Implementation | `6af23d9aeca29e63aa13c4ae49f50d1748939c49` |
| Build/event commit | `32e97ea89cdc4bca629abde38f31eb943f3f11ad` |
| Workflow run/job | `31292116792 / 93190952157` |
| Runtime artifact | `9031804178` |
| Artifact outer SHA-256 | `27d16f485c357a236ffd43ce09c335bd246cb3f276cd9cc85b572ca543d87e9e` |
| Recursive manifest | **49/49**, digest `2fec5670eb81972233c52c9db1afe82e7eb92da812f1ab537a018bb0d31fb7e2` |
| Log artifact / SHA-256 | `9031804382` / `5d0b8d0defa3fc371d71160e1db266d3df8037e14c87cf64181b51637cb8a905` |
| Patch SHA-256 | `b7490fabd6d7490e1f8f24d47126b26d07866939fc8142e8c4ef8edd4b89d300` |
| Source archive SHA-256 | `df6e14e60679ccb25fa832d762fe7d31fdf40de746a5659e20998b72e7232900` |
| Compile database SHA-256 | `60fd05acc3e68a369aacacfa3c24b5582687f7ee6d6b959b9267639dd37fc508` |
| Build closure | Release/static/Ninja **113/113**, GoogleTest `PRE_TEST`, `runtimeExecution=false` |

Preflight independently verified safe ZIP paths, both outer digests, all 49
recursive members, exactly 50 package files, five ELF executables, two static
libraries, 27 fixtures, the seven expected source/CMake Git blobs, the exact
five-path patch, source archive, compile database, toolchain/submodules,
workflow closure, zero compile-log failure markers, and no runtime execution
in the Code + Build artifact.

The package source/CMake blobs are exactly:

- `e82e3088e11f215f030b58be7fb6531a5dbaa99a` — `cmake/DirectionalTests.cmake`;
- `7e6414ba63ab93f29ea1b68ab21a45bdc4a06eb0` — optimizer header;
- `06c6491d545b578fd579235a7c9073dfe1a27a0a` — validator header;
- `d087ceefbdadcbbce82e7bdbe7fba4a3abee3c65` — optimizer implementation;
- `af09d3305c3f76c0611eb82d681237ea33ad573e` — unchanged pipeline implementation;
- `96f2f512df7f0457891581e7a15eda5a43232bdb` — validator implementation;
- `ecb28a1cc97875457a343b766fcb67004269df4b` — focused Phase22 tests.

The exact toolchain/submodules are CMake `3.31.6`, GCC `13.3.0`, Ninja
`1.13.2`, Eigen `769c72fd8019e389810d1de1e7c243521a43b594`, googletest
`3940de91897160fea4815998e08d0fa3c2fb077e`, and polyscope
`59da72df6517cab8379865899bdffdbc96171301`.

## Runtime boundary and evidence

All packaged commands ran from the isolated package `bin` directory with
`LC_ALL=C` and `TZ=UTC`. After preflight, the only intentional locator mutation
was the authorized symlink `bin/test-data -> ../test-data`; benchmark processes
also generated their ordinary `bin/benchmark-results` outputs.

The accepted evidence ledger contains **240 files**. Its manifest SHA-256 is
`5b7c8c7ab6fcf766be40a8706236881f3c16e16ca753441894c825cbf50a3040`.
The downloadable evidence ZIP has SHA-256
`c24976d6c1f977c28a3d5b9d716cf41fb30ed68c8a22b104c21734b537e5430c`.

One orchestration attempt used the container execution wrapper for the bounded
producer and returned control before the child summary. It was not used as
authority. The exact literal producer filter was then executed independently
and completed with a full GoogleTest summary, **154/163**, in 30.63 seconds.
No product timeout/nontermination claim is made from the wrapper behavior.

## Discovery

Each required GoogleTest executable ran `--gtest_list_tests` exactly once.

| Executable | Suites | Tests | Exit |
|---|---:|---:|---:|
| `directional_surface_cell_producer_tests` | 11 | 166 | 0 |
| `directional_surface_cell_completion_tests` | 4 | 164 | 0 |
| `directional_surface_cell_validation_tests` | 5 | 71 | 0 |
| `directional_compiled_api_tests` | 1 | 8 | 0 |

Validation increased from the entering 67 to 71 solely because the four new
multi-rail tests are packaged and independently discoverable.

## Focused acceptance

All **18/18** required focused contracts passed individually.

### Four new multi-rail contracts — validation executable

1. `SurfaceMeshOptimizerPhase22.MultiRailChainReachesSelectedChartWithoutConsumingUnusedRelation`;
2. `SurfaceMeshOptimizerPhase22.MultiRailReciprocityMayBeCarriedOutsideTheSelectedFace`;
3. `SurfaceMeshOptimizerPhase22.MissingMultiRailGraphLinkLeavesSelectedChartUnreachable`;
4. `SurfaceMeshOptimizerPhase22.MultiRailChartReachabilityIsInvariantToSourceFaceRows`.

### Seven retained face-chart contracts — validation executable

1. `SurfaceMeshOptimizerPhase22.ReciprocalHardRailAuthorityResolvesOneExactChartSidePerQuad`;
2. `SurfaceMeshOptimizerPhase22.MissingOrMisalignedHardRailChartAuthorityFailsClosed`;
3. `SurfaceMeshOptimizerPhase22.TamperedHardRailIdentityRouteAndChartAuthorityFailClosed`;
4. `SurfaceMeshOptimizerPhase22.AmbiguousHardRailChartSidesAreRejectedInsteadOfOrdered`;
5. `SurfaceMeshOptimizerPhase22.DisconnectedCloseSheetsRejectInjectedChartAuthority`;
6. `SurfaceMeshOptimizerPhase22.HardRailChartResolutionIsInvariantToSourceFaceRows`;
7. `SurfaceMeshOptimizerPhase22.HardRailChartAuthorityNeverMasksScalarProvenanceFailures`.

### Seven retained canonical contracts — producer executable

1. `SurfaceCellTransitionQuotient.SourceWideCompactTransitionIndexIsIndependentOfRegionPartition`;
2. `SurfaceCellTransitionQuotient.FullEfTransitionRowCannotReplaceSourceWideCompactIndex`;
3. `SurfaceCellTransitionQuotient.RegionLocalCompactTransitionIndexCannotReplaceSourceWideIndex`;
4. `SurfaceCellsPhase10.PeriodicPhaseFrontCutAndHolonomyIgnoreFaceRowEnumeration`;
5. `SurfaceCellsPhase10.PeriodicPhaseFrontMalformedHolonomyFailsClosedWithTypedReason`;
6. `SurfaceCellTransitionQuotient.ComponentBoundaryAndEulerFactsAreComputedFromIncidence`;
7. `SurfaceCellTransitionQuotient.DeterministicTracingFailureRetainsAuthorityIfAndOnlyIfRequested`.

## Mandatory test-intent record

The focused tests are strong stage-local contracts, but they are **not an
independent product oracle**. Most of the chart tests invoke the production
source-authoritative validator directly, and several canonical tests exercise
materialization/tracing internals. They therefore cannot by themselves close a
representative production gate. This is exactly the `TA-05 / RP-02` distinction
that the queued T1 oracle work must correct.

| Test | Intent and proved precondition | Production entry/stage | Oracle / earliest assertion | Counterexample or metamorphic case | Evidence identity |
|---|---|---|---|---|---|
| MultiRailChain… | Scalar-rooted multi-edge chart graph reaches the selected chart while unrelated valid relation remains retained. Fixture proves selected chart contains the scalar-side and chained target faces. | source-authoritative validator + chart resolver | accepted + local-sheet compatibility; selected chart valid | paired MissingMultiRailGraphLink… | validation executable, exact discovered name, artifact `9031804178` |
| MultiRailReciprocity… | Reciprocal authority is global and need not be carried by the selected face. Fixture proves peer vertices are off that face. | source-authoritative validator | removing the off-face reciprocal peer is rejected `LocalSheetMismatch` | deleted rail-21 peer | same |
| MissingMultiRailGraphLink… | Missing exact graph link makes target unreachable. Fixture removes both relation endpoints and target chart support. | source-authoritative validator | reject `LocalSheetMismatch` | rail-21 link + chart deletion | same |
| MultiRailChartReachabilityIsInvariantToSourceFaceRows | Semantic selected side is independent of source face enumeration. All provenance/chart face IDs are remapped after row reversal. | chart resolver + source-authoritative validator | same semantic side and accepted result | complete source-face row reversal | same |
| ReciprocalHardRailAuthority… | One exact chart side is selected per quad under reciprocal rail authority. | validator + optimizer chart helpers | accepted; opposite quads select different semantic sides; optimizer label/reference remain consistent | negative cases below | validation executable, exact discovered name, artifact `9031804178` |
| MissingOrMisalignedHardRail… | Missing or cardinality-misaligned authority fails closed. | source-authoritative validator | reject `LocalSheetMismatch` | clear equivalence / drop authority row | same |
| TamperedHardRailIdentity… | Rail ID, route topology, reciprocity, and supported-chart identity are semantic authority. | source-authoritative validator | each corruption rejects `LocalSheetMismatch` | wrong rail, wrong route, nonreciprocal front, unsupported chart | same |
| AmbiguousHardRailChartSides… | Multiple plausible hard-rail chart sides must not be chosen by ordering. | source-authoritative validator | reject ambiguity as `LocalSheetMismatch` | deliberately symmetric four-relation ambiguity | same |
| DisconnectedCloseSheets… | Injected chart authority may not bridge disconnected close sheets. | source-authoritative validator | reject `LocalSheetMismatch` | add chart from other component | same |
| HardRailChartResolutionIsInvariantToSourceFaceRows | Exact chart-side semantics are row-order independent. | validator + chart resolver | original/reversed both accepted; semantic sides equal | full face-row reversal with remapped provenance/charts | same |
| HardRailChartAuthorityNeverMasksScalarProvenanceFailures | Rail authority cannot mask scalar provenance failures. | source-authoritative validator | typed `InvalidProvenance`, `SourcePositionMismatch`, `SourceComponentMismatch`, `SourceSheetMismatch` | one scalar fact corrupted per case | same |
| SourceWideCompactTransitionIndex… | Serialized interior route uses the source-wide compact transition domain and topology-only boundaries carry no invented interior index. Fixture proves full-EF, region-local, and source-wide IDs differ and witnesses an actual serialized route. | phase-front materializer | all serialized routes map through source-wide index; valid materialization succeeds | next two tests substitute alternate domains | producer executable, exact discovered name, artifact `9031804178` |
| FullEfTransitionRowCannotReplace… | Full-EF row cannot masquerade as source-wide compact route authority. | phase-front materializer | fail `InvalidAuthoritativeTransitionSourceEdge` | substitute full-EF row at exact witness | same |
| RegionLocalCompactTransitionIndexCannotReplace… | Region-local compact index cannot masquerade as source-wide authority. | phase-front materializer | fail `InvalidAuthoritativeTransitionSourceEdge` | substitute region-local index | same |
| PeriodicPhaseFrontCutAndHolonomyIgnoreFaceRowEnumeration | Cylinder periodic cut/holonomy and canonical compact route are source-face-row invariant. | cross-field finalization → phase-front network → materializer | both produced; same grid/holonomy/topology/routes; materialized `1/2/0` | reverse all source face and field rows | producer executable, exact discovered name, artifact `9031804178` |
| PeriodicPhaseFrontMalformedHolonomyFailsClosedWithTypedReason | Malformed periodic authority selected by canonical topology must fail closed in the correct identity domain. | phase-front materializer | expected typed malformed-holonomy failure | tamper the matching full-EF transition selected through canonical topology | same |
| ComponentBoundaryAndEulerFactsAreComputedFromIncidence | Component/boundary/Euler facts come from incidence, not fixture labels/count guesses. | materializer | square `1/1/1`, overlap `2/2/2`, cylinder `1/2/0` | three distinct incidence topologies | same |
| DeterministicTracingFailureRetainsAuthorityIfAndOnlyIfRequested | Internal failure-injection lifetime is independent of caller-visible retention. | public `remesh_from_raw_cross_field` | same deterministic tracing failure; retained context iff requested | retain true vs false | same |

The stage-local assertions above are valid for their declared contracts. Their
lack of a separate product-level oracle is explicitly **not** treated as a
reason to weaken them. The representative direct-torus failure demonstrates
why passing them cannot close G4.

## Historical exact torus

`SurfaceCellsPhase10.ExactCommittedTorusDoesNotTreatIsolationSeamAsBoundedDiskBoundary`
ran individually and failed at the unchanged upstream
`NotProductionReady:tracing producer=tracing/phase-front/InvalidHardRailPairing`.
It reported four regions, eight isolation seams, and four periodic relations
available, `0/0/0` consumed, and no materialized component. This remains
`G4-B002`, a target-size-dependent hard-rail scheduling blocker, not a new
multi-rail chart regression.

## Retained groups

These filters overlap and are reported independently.

| Group | Result | Exit | Movement |
|---|---:|---:|---|
| Transition quotient | **29/36** | 1 | unchanged seven deferred contracts |
| Topology / isolation / hard rail | **10/10** | 0 | unchanged |
| Polygonal / curved / mixed | **12/12** | 0 | unchanged |
| Periodic / torus / cylinder | **6/7** | 1 | unchanged historical exact-torus failure |
| Remaining non-overlap Phase10 | **38/39** | 1 | unchanged strict-validator timing assertion |
| Direct G0-G3 GoogleTests | **4/4** | 0 | unchanged |

The strict-validator timing test observed `0.000142752 s` against a five-percent
bound of `0.00007685745 s`. It remains explicit and does not override semantic
correctness authority.

## Bounded suites

| Suite | Result | Exit |
|---|---:|---:|
| Producer, literal `-*BunnyRandom*:*Vase*` filter | **154/163** | 1 |
| Completion / simplification | **154/164** | 1 |
| Validation | **71/71** | 0 |
| Compiled API | **8/8** | 0 |
| Aggregate | **387/406** | — |

The nine producer failures remain the same seven transition-quotient cases,
historical exact torus, and strict-validator timing. Completion retains the
same historical ten failures. The aggregate increase from entering **383/402**
is exactly the four newly packaged passing validation contracts; no existing
bounded test changed disposition.

## Ordered direct fixture matrix

Each benchmark process itself exited zero; semantic success is taken from the
case JSON. All runs requested and executed `SurfaceCells`, used fallback policy
`Fail`, disabled source-grid recovery, did not attempt fallback, did not execute
legacy, and did not return the input mesh.

| Case | Result | Stable output / topology | Wall seconds | Estimated peak owned bytes |
|---|---:|---|---:|---:|
| Plane | **3/3** | 81 V / 64 Q; structural `b243fb3f5f3a3bc4`; semantic `922456fe29a63ba1`; `1/1/1` topology | 0.991990–1.037499 | 672460 |
| Multi-face seam | **3/3** | 81 V / 64 Q; structural `48661113839528d4`; semantic `99c8be7159d05c2f`; `1/1/1` topology | 1.545009–1.562008 | 548900 |
| Close sheets | **3/3** | 242 V / 200 Q; structural `f01bcf687285ee72`; semantic `f40e1aa5f2eb3f92`; `2/2/2` topology | 12.397295–12.640091 | 2104888 |
| Cylinder | **3/3** | 320 V / 288 Q; structural `81b3763254afc476`; semantic `98da73e60a564998`; `1/2/0` topology; `1/1` periodic relation consumed | 6.817263–6.917942 | 3217244 |
| Torus | **0/3** | 192 completed quads; complete lineage; `4/8/4` consumed; `1/0/0` topology; **241** `LocalSheetMismatch` issues | 0.319418–0.329422 | 2355172 |

All four accepted fixtures are strict-valid pure quads with complete provenance,
`CompletedSurfaceCells` origin, and deterministic structural/semantic hashes.
Torus remains `SurfaceCells`/fail-closed with no fallback or recovery, reaches
completion, then fails `completion/output-validation / LocalSheetMismatch` and
therefore keeps output origin `None`.

The direct wall times above are preserved as measurements only. They are not
compared to prior-session wall times as a performance regression because a
same-host/same-load comparison was not established. Estimated owned-byte
figures remain identical to the entering report.

## Regression and test-authority diagnosis

The runtime evidence establishes three facts without requiring a speculative
new root-cause claim:

1. The local multi-relation graph contracts are implemented and pass their
   declared stage-local counterfactuals.
2. The representative direct torus still fails at the same earliest typed
   product boundary and now exposes 241 mismatches.
3. Therefore the current local correction is **insufficient** as a product
   remediation, and the focused fixtures do not span the production state that
   remains invalid.

The exact additional invalid state is not inferred from failure count alone.
No new `G4-R008` is created and no recurrence counter is incremented. The
existing `G4-R007` returns from `fix_pending_runtime` to **`active`** with this
artifact as its latest evidence.

This run also supplies concrete runtime evidence for `AR-12 / TA-05`: focused
relation fixtures can be green while representative production remains red.
It does not invalidate the local tests; it demonstrates that stage-local tests
must not be promoted to complete product proof. The independent test-suite
audit had already scheduled T1 to address this exact authority gap.

## Mandatory regression-pattern review

| Pattern | Touched? | Evidence anti-pattern is absent / current finding | Corrective invariant | Counterfactual and representative gate |
|---|---|---|---|---|
| `RP-01` authority-domain conflation | Runtime verification only | Canonical seven pass; transition quotient remains 29/36 with the same deferred cases; no new domain or code was introduced. | Keep topology/full-EF/source-wide/region-local domains distinct. | Exact canonical negatives pass; no new claim beyond current artifact. |
| `RP-02` proxy/incomplete test authority | **Yes** | All 18 focused contracts pass while direct torus worsens to 241 mismatches. This is direct evidence that focused stage-local coverage is not product proof. | Product acceptance requires an independent observable oracle and representative case evidence. | Current direct torus rejects closure; T1 independent-oracle mutation suite is next. |
| `RP-03` state/policy conflation | Runtime verification only | Retention counterfactual remains green; no state/policy edit. | Internal lifetime and public retention remain separate. | `DeterministicTracingFailureRetainsAuthorityIfAndOnlyIfRequested`. |
| `RP-04` cumulative work | Runtime verification only | Exact bounded producer completed 163 tests in 30.63 s; no product nontermination inferred from orchestration wrapper behavior. | Global work claims require exact process evidence. | Literal producer filter **154/163**. |
| `RP-05` representation identity | Runtime verification only | Both face-row-invariance chart tests and periodic row-invariance contract pass. | Semantic identity must be row/order independent. | New and retained row-reversal tests pass; green hashes deterministic. |
| `RP-06` state cardinality growth | Runtime verification only | No storage/code edit; estimated owned-byte figures unchanged for the direct matrix. | Shared authority remains referenced rather than multiplied per consumer. | No new memory acceptance claimed. |
| `RP-07` cyclic linearization | Runtime verification only | Periodic group remains 6/7 with only the known scheduling case. | Cyclic topology stays explicit. | Cylinder 3/3; exact torus scheduling blocker remains visible. |
| `RP-08` producer disposition conflation | Runtime verification only | Torus remains fail-closed `SurfaceCells`; no generic fallback, legacy, recovery, or input substitution occurs. | `Rejected` remains terminal and distinct from `NotApplicable`. | Direct matrix backend/fallback diagnostics. |
| `RP-09` global authority consumed locally | **Yes** | Four new multi-rail + seven face-chart tests pass, proving the intended local graph semantics on those fixtures; representative torus still fails, so the correction cannot be declared complete. | Validate complete authority globally and require only an exact selected witness locally. | Focused 11/11 relevant chart contracts plus direct torus **0/3**; `G4-R007` stays active. |

No pattern recurrence count changes. No previously resolved regression reappeared
on an accepted direct fixture.

## Postflight

After runtime:

- both original outer ZIP digests remained exact;
- the recursive package manifest reverified **49/49**;
- all **50/50** original archive regular members matched their original ZIP
  bytes exactly;
- the authorized `bin/test-data` symlink still points to `../test-data`;
- no packaged regular file was altered;
- generated benchmark outputs were kept separate from immutable package
  members.

## Decision and next authority

The multi-rail chart-reachability correction is rejected as a G4 product fix.
`G4-R007` remains **active**; G4 remains open. The historical exact-torus
hard-rail scheduling defect, nonzero periodic `Z4` rotation, positive
multi-isolation lineage, historical completion/simplification ten,
strict-validator timing, sphere, G5/G6, fallback/recovery, and optimization
remain separate blockers.

The already completed independent architecture/test-suite reviews require a
test-authority foundation before another production migration. Review policy is
`never`, so the authoritative next turn is **T1 Independent Test-Oracle
Foundation — Code + Build only** under:

`.agents/Directional/Test_Architecture_T1_Independent_Oracle_Foundation_Code_Build_Plan.md`

T1 is test/build-only and must not change production behavior. It creates an
independent product oracle, mutation adequacy, and default package/discovery
authority. M1 production authority-kernel migration remains blocked until T1
passes immutable Test + Benchmark acceptance.

PR #8 remains open, draft, and unmerged.
