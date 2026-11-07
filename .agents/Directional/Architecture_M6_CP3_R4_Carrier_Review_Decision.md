# Independent Review — the 39-identity endpoint census, and selection of the certificate model (RA-59)

**Turn:** `M6-CP3-TB1-R4-CARRIER-REV` (Review only). **Disposition:** the census **measurement is ACCEPTED**; its **interpretation is AMENDED and then CLOSED**. Two of the three RA-57.7 hypotheses are **ELIMINATED from the source bytes**, not from the measurement, and the certificate model is **SELECTED**. No source, test, selector, binary, harness, workflow or ledger change was made in this Review. Ledger **66 events / 17 categories / 49 recurrences**, debt **1**, CP2 **491/491** accepted, R3 **403/497** rejected, frozen selector **30+12+449+6=497** — all unchanged. No promotion, no stable event, no new recurrence, no 497 execution, no gate credit.

## RA-59.1 — The measurement is valid and the execution boundary is clean

Independently re-derived. `M6-CP3-TB1-R4-ENDPOINT39-CENSUS` executed **39/39** identities on the same immutable package (compile run `38664036225`, package artifact `11939982141`, semantic source `953f812ff1f431e3ad3af3b68a92284a7831c94a`), workflow [38687783618](https://github.com/akashskypatel/Directional/actions/runs/38687783618), result artifact `11950303475` (ZIP SHA-256 `3bce344f3a13403a830a2800fea4c47d1e7cdd53f6f3eac6629de57d70788b32`). `executed=39 red=39 missing=0 postflight=true exit=0`; 28/28 manifest checksums before and after; package, source, execution-view and selector bytes identical across execution. No configure, compile, relink, benchmark, or frozen-497 run. The four frozen selector files still hash to their pinned values (`1e815443…`, `2aa57aac…`, `d4a0d1b7…`, `9c88a5ed…`) in the working tree.

Re-derived set membership rather than accepting it: every one of the 39 executed identities is a member of the **94-row R3 RED register** (`Architecture_M6_CP3_TB1_Entry_R3_Red_Classification.tsv`), intersection **39/39**, zero census identities outside it. Cross-validating the census TSV's `R3_CP2_ACCEPTED`, `R3_R2_RED` and `R3_original_first_observable` columns against that register field-by-field yields **zero mismatches** in 117 comparisons. The R3 `phase` distribution of the 39 is `focused30=9, focused12=2, selector=26, cp3entry=2`, matching the TSV's three selector columns exactly.

## RA-59.2 — The harness is the best instrument built in this family, and it fixed a defect class I did not raise

`tools/m6_cp3_r4_endpoint39_census_harness.sh` (SHA-256 `4dd5c605710c65317b2f524d0d3bed83602b7922ceec4bab87062374407c40f6`, 92 lines) is **RA-57.8 compliant**: `:71-74` records `NOT_SELECTED` and `continue`s instead of aborting the loop, `:91` derives the verdict from `executed`/`missing`/`postflight` **only** with no RED-count test, and `:92` is a bare `exit 0`. Four expected REDs can no longer suppress a turn's report.

Beyond the mandate, `:45-51` **derives the census scope from a SHA-256-pinned artifact** rather than transcribing it: `inventory=…Historical_R3_A4_39_Current_Source_Inventory_20261013.tsv`, pinned at `de05a7bd5ca27eb243156ecd38434fbc69d06f4b791bdd3dbcfc5982c273a865` (verified identical in the working tree), then `mapfile` with `[[ "${#tests[@]}" == 39 ]]` and a duplicate check. The executed set equals the pinned inventory set exactly. This eliminates silent census shrinkage — a failure mode the earlier harnesses permitted and that no amendment had named. **Recorded as the correct instrument shape for every future census rung.**

## RA-59.3 — `routeLength` and `step` are not measurements, and `step` is arithmetically forced

RA-57.12 holds: *a signal that never varies is not a measurement.* Across all 39 identities the census reports `routeLength=1`, `step=0`, `closedChainPresent=0`, `locus=3` — four constants — with only `rail` (33×2, 6×1) and `chi` (37×0, 2×3) varying. Two of those constants are now shown to be **non-data**:

- `step` is emitted at `src/geometry/SurfaceCellTracing.cpp:19329-19332` as `firstMissing ? 0 : static_cast<int>(routeSteps.size() - 1U)`. With `routeSteps.size() == 1`, **both** branches yield `0`. `step` is `routeLength-1` here, a derived echo of `routeLength` in the same class as `faceEnds` (RA-56.1). It corroborates nothing.
- `locus=3` is `SurfaceHardRailRouteFailureLocus::EndpointAttachment` (`include/directional/geometry/SurfaceCellTracing.h:1800-1811`). It is implied by the predicate name, not independent of it.

The census TSV is nonetheless correct to have recorded them: a field must be measured before it can be shown to be uninformative. The defect is only in reading them as breadth.

## RA-59.4 — `routeLength=1` is the CORRECT value, and hypothesis (c) route truncation is WITHDRAWN

My own `NEXT_TURN` promoted *route truncation* to a live hypothesis on the strength of `routeLength=1, step=0`. That was wrong, and the source says so.

`first.route` is produced at `src/geometry/SurfaceCellTracing.cpp:12617` by `authority::CanonicalRoute::from_observed_steps(std::move(observedSteps))`, where `observedSteps` is assembled at `:12574-12579` as **one step per contiguous run of the front edge's own retained geometry on one source-edge topology**, with `seenTopology.insert(topology)` forbidding revisits. `CanonicalRoute` (`include/directional/authority/CanonicalRoute.h:64-98`) carries no whole-rail contract; `oriented_steps()` at `:79` returns exactly those steps.

So `routeLength` measures **the front edge's own carrier extent**, not the rail's length. A front edge that crosses one source edge yields `routeLength=1` *correctly*. `routeLength > 1` is representable (a front spanning two topologies publishes two runs), so the field is not a tautology — it is simply **constant at 1 in this census because every measured front lies on a single carrier edge**. Nothing is truncated. **Hypothesis (c) is withdrawn.** This is the third error of this family I have owned — RA-57.3 (a non-discriminating control), RA-58.8 (a grid conditioned on the verdict), and now a hypothesis built on a field whose expected value I never established. The standing rule from RA-58.8 generalizes: **a measured value without its expected value is not a discriminator.**

## RA-59.5 — Hypothesis (b) incorrect pairing is ELIMINATED by the predicate name in all 39 logs

The pairing precondition is checked first, at `:19022-19025`:

```cpp
if (!first.railId.has_value() || first.railId != second.railId ||
    first.route.empty() || first.route != second.route.reversed()) {
  invalid_route(SurfaceHardRailRouteFailureLocus::Pairing, -1, -1, "nonreciprocal-pair");
  return network;
}
```

It returns immediately on failure with predicate `nonreciprocal-pair` and locus `Pairing = 1`. Every one of the 39 reports predicate `endpoint-0`/`endpoint-1` and locus `EndpointAttachment = 3`, emitted later at `:19329-19332`. Therefore in all 39 measurements the rail ids matched, the route was non-empty, and `first.route == second.route.reversed()` — **reciprocal pairing held**. Two independent fields (predicate name and locus enum) agree. **Hypothesis (b) is eliminated.**

## RA-59.6 — What the 38 `endpoint-1` identities actually measured: a half-terminal front

Both certificates are evaluated on the pair's two spatial ends, at `:19264-19269`:

```cpp
const auto firstEndpoint  = endpoint_certificate(first.from, second.to,  routeSteps.front().topology(), &firstEndpointPredicate);
const auto secondEndpoint = endpoint_certificate(first.to,  second.from, routeSteps.back().topology(),  &secondEndpointPredicate);
```

`endpoint-1` means `firstMissing == false`, i.e. **`firstEndpoint` returned a value**. So for 38 of the 39 identities, one end of the paired front — `(first.from, second.to)` — **was certified**: both of its trace points are exact one-hot source corners at a shared vertex of the rail's terminal contact set that also lies on the crossed carrier edge. The other end, `(first.to, second.from)`, failed at `:19152` `no-exact-terminal-corner`, with the retained evidence `corner[1]=0,0;railEnd[1]=1;corner[7]=0,0;railEnd[7]=0` — vertex 1 is an endpoint of the crossed carrier edge but neither trace point sits exactly on it.

**The measured object is a half-terminal front pair: one end exactly at a rail terminal source vertex, the other at an interior parameter of the same carrier edge.** This is reproduced identically across 39 identities, 5 distinct fixture builders, 2 rail ids, two field regimes (`chi=0` and `chi=3`), and both `remesh_from_raw_cross_field` full-pipeline entries. Per RA-56.8 this is now a **measured carrier**, not one measured identity.

## RA-59.7 — The certificate has no admissible shape for an interior endpoint; this is a DOMAIN GAP, not a strictness dial

`endpoint_certificate` (`:19049`) admits exactly two shapes for a hard-rail endpoint:

1. **Open rail with a published terminal contact.** `:19144-19152` loops the rail's terminal endpoints and requires, for one and the same vertex, that it be an endpoint of the crossed carrier edge **and** that **both** paired trace points be exact one-hot barycentric corners at it; otherwise `no-exact-terminal-corner`.
2. **Contact-free rail with an independently published typed closed chain.** `:19072-19079`; absent both, `missing-terminal-or-closed-rail-provenance`.

A front end at an **interior point of the carrier edge of an open rail** satisfies neither. There is no third branch. Consequently:

- **Hypothesis (a) is SELECTED, in an amended form.** The defect is not that the predicate is too strict — it is correct and must stay fail-closed for anything claiming to be a terminal. The defect is that the certificate's **domain is missing the interior-endpoint shape** that the front publisher demonstrably produces. "Contract granularity mismatch" (RA-55) is confirmed and sharpened to a domain gap located at `:19049-19152`.
- **This independently re-explains RA-58.5.** The torus passes because its chain is **closed**, so it takes branch 2 at `:19077-19079` and never reaches `:19152`. The square and cylinder pass because they never enter this block. The open-rail fixtures fail because they are the only ones that reach branch 1 with an interior end. One mechanism now accounts for all four control outcomes and all 39 census outcomes.

## RA-59.8 — The positive acceptance branch has never been reached by any test, green or red

`grep` over the whole test corpus finds **five** identities that assert a published hard-rail route certificate: `SurfaceCellAuthorityContractCutover.{MissingOpenRailTerminalContactRejectsBeforeClosedRailFallback, ForeignOpenRailComponentRejectsAtFirstA4ConsumerPredicate, DuplicateSourceTerminalContactRejectsAtFirstA4ConsumerPredicate, ForeignSourceTerminalContactRejectsAtFirstA4ConsumerPredicate, MissingTerminalA3PathRejectsAtFirstA4ConsumerPredicate}` (`tests/SurfaceCellsPhase10Tests.cpp:6922, :7104, :7148, :7189, :7248`). Each is a **tamper/negative** test whose first assertion demands real production, e.g. `:7150-7152`:

```cpp
const auto fixture = build_rectangular_hard_rail_phase_front();
ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
          fixture.network.phaseFront.disposition()) << hard_rail_first_failure_detail(fixture.network);
const auto &front = fixture.network.phaseFront.product();
ASSERT_FALSE(front.hardRailRouteCertificates().empty());
const auto &firstRoute = front.hardRailRouteCertificates().front();
ASSERT_TRUE(firstRoute.endpoints[0].terminalVertex.has_value());
```

They all fail at the `Produced` gate. **No test anywhere — accepted, frozen, or RED — has ever observed the producer publish an open-hard-rail route certificate from real source geometry.** Therefore the entire positive path downstream of `:19152` is unwitnessed, including the junction loop at `:19335-19338`:

```cpp
junctions.reserve(routeSteps.size() - 1U);
auto previous = firstEndpoint->terminalCarrier;
for (std::size_t index = 1U; index < routeSteps.size(); ++index) {
```

With `routeSteps.size() == 1` this loop body **cannot execute**. This is the mechanical root of RA-41's junction/sector clauses standing frozen UNEXERCISED, and it means **no number of additional `routeLength=1` measurements can ever exercise them.** Exercising them requires a fixture whose front's retained geometry spans **two** rail topologies — i.e. a front crossing both `(1,4)` and `(4,7)`. That is the first actionable construction recipe for those guards; it is **recorded, not authorized** (RA-54.7), and the guards are **not retired** (RA-52.6: a retained guard needs a retained attempt).

It also localizes `RP-02 TEST_AUTHORITY_COVERAGE_GAP` precisely: the gap is not merely that the network-bound consumer was never reached, but that **the acceptance half of the hard-rail certificate model has no witness at all**, so a repair cannot be validated by making existing REDs green.

## RA-59.9 — Selected certificate model, and the one falsifier that would overturn it

**SELECTED (RA-59.9).** The open hard-rail route certificate gains a **second admissible endpoint shape — a source-attested interior carrier endpoint** — authenticated by: the typed carrier key; **both incident source faces of that carrier edge (across-rail, per RA-57.5 — not along-rail interval or face-side ownership)**; the canonical exact intrinsic parameter on the **same** carrier edge, shared by both paired trace points, with equivalent opposite-side barycentric representatives and **no** world-coordinate epsilon merging; source component/sheet agreement; the matching A2a mandatory network edge/rail identity; and the directed A3 transport between those two incident faces.

Constraints that are part of the selection, not commentary:

- `exact_corner` and `no-exact-terminal-corner` at `:19131-19152` are **unchanged and fail-closed**. Any endpoint claiming to be a rail terminal is still held to exact one-hot corner identity on both paired points.
- The closed-chain branch at `:19072-19079` is **unchanged**, preserving the RA-58.5 torus PASS.
- An open rail must still publish **at least one certified terminal endpoint** — satisfied in 38/39 by `firstEndpoint` — so a contact-less open rail and a forged closed-chain token both remain impossible.
- `firstRoute.endpoints[0].terminalVertex.has_value()` (`tests/SurfaceCellsPhase10Tests.cpp:7157`) stays satisfiable, so **no existing test contract is weakened** by this model. Checked before selecting it.
- The single `endpoint-0` identity, `SurfaceCellAuthorityContractCutover.FixedConformityPlanTargetPerturbationPreservesSharedBoundaryIntervals` (historical ordinal **405**, `a2bProbeFailure=missing-terminal-or-closed-rail-provenance`), is a **separate A2b provenance defect** at `:19072-19079` — the rail has neither a published terminal contact nor a closed chain. It must **not** be repaired by the interior-endpoint model, and it must not be merged into the 38. The census was right to refuse the merge; the mechanism is now named.

**The falsifier, which the Code + Build turn must check FIRST and STOP on.** This selection assumes a hard-rail front's extent is determined by where the field-aligned phase front meets the rail, so a front end may legitimately fall interior to a carrier edge. If instead the front publisher is contracted to cut hard-rail fronts **only** at rail terminals, then the half-terminal front is itself the defect, the repair belongs upstream of `:19264`, and this model is wrong. The comment at `:18908-18909` — *"A4 owns the paired-route topology, endpoint attachment and A3 transport. Publish one terminal crossing per spatial endpoint; A5 must not search."* — is evidence for the stricter reading and must be reconciled before any edit. **If the publisher's contract cannot be established from source, STOP and return to Review.** Do not resolve it by whichever choice makes the 38 green.

## RA-59.10 — Classification correction: 37 carried CP2 losses + 2 in-gate R3 REDs, and all 39 are INSIDE the 497

The census TSV sets `reproduced_carried_loss=true` for all 39 and the report describes all 39 as reproducing *"previously observed, **unaccepted** failures."* Both flatten the distinction RA-58.6 exists to keep. On the authoritative register:

| class | count | evidence |
|---|---:|---|
| reproduced **carried CP2 loss** (CP2-accepted, now RED) | **37** | `R3_CP2_ACCEPTED=true`; phases `focused30`/`focused12`/`selector` |
| reproduced **in-gate R3 RED with no accepted CP2 baseline** | **2** | `R3_CP2_ACCEPTED=false`; phase `cp3entry` |
| **baseline-free first measurement** (the RA-58.6 identity-4 class) | **0** | `baseline_free_first_measurement=false` for all 39 |

The two in the second class are `M6CP3.HardRailCrossRegionBranchCertificateStripsEndpointFaceGauge` and `M6CP3.HardRailCrossRegionBindingDoesNotCompareGlobalSheetLabels` — and they are the **same two** that are the only `chi=3` rows and the only `nonconstant_hard_rail_fixture` singleton rows. The report calls them *"in no selector"*, which is true of the three selector **files** but materially misleading: both are `cp3entry`, i.e. members of the **"+6" CP3 group of the frozen 497**. **All 39 census identities are inside the frozen 497.** "In no selector" is the exact phrase under which RA-58.6 classified a baseline-free identity, and it must not be reused for an in-gate one. The TSV's own `baseline_free_first_measurement=false` column already says the right thing; only the prose and the `reproduced_carried_loss` column semantics are wrong. Corrected here, not silently.

## RA-59.11 — RA-58.9 arithmetic, stated as the report declined to

The report states the RA-58.9 merge rule and does not apply it. Applied: `fixture_construction=false — constructor threw` for **19** identities — 17 on the `hard_rail_fixture` singleton (`tests/SurfaceCellTransitionQuotientTests.cpp:585, :771-772`) and 2 on `nonconstant_hard_rail_fixture` (`:776, :855-856`). A throwing singleton means the test body never ran, so those 19 REDs are **2 fixture-construction measurements**, not 19 observations. The upper bound on independent loci in this census is therefore **22**, not 39:

| locus group | identities | independent loci |
|---|---:|---:|
| `hard_rail_fixture` singleton threw | 17 | **1** |
| `nonconstant_hard_rail_fixture` singleton threw | 2 | **1** |
| `build_rectangular_hard_rail_phase_front` per-test helper | 12 | 12 |
| `remesh_from_raw_cross_field` per-test pipeline | 2 | 2 |
| direct test construction | 6 | 6 |
| | **39** | **≤ 22** |

This does not weaken RA-59.6: the carrier still spans 5 builders, 2 rails and 2 field regimes, which is what RA-56.8 requires. It does mean **"39 REDs" must never be cited as 39 corroborations**, and the two singleton rows must never be counted toward breadth.

## RA-59.12 — The fixtures' authored rail is two edges, and that is why the interior end exists

Read from the bytes, not inferred. `make_hard_rail_fixture` (`tests/SurfaceCellTransitionQuotientTests.cpp:585`) inserts `userHardEdges` `{1,4}` at `:617` and `{4,7}` at `:618`. `make_nonconstant_hard_rail_fixture` (`:776`) does the same at `:830-831`. `build_rectangular_hard_rail_phase_front` (`tests/SurfaceCellsPhase10Tests.cpp:6298`) inserts `{offset+1, offset+4}` and `{offset+4, offset+7}` per component at `:6315-6322`. Every measured fixture therefore authors a **two-edge open rail chain `1→4→7`** with interior junction vertex **4** and terminals **{1,7}**, and the measured front lies on the first edge `(1,4)` only.

Two consequences. First, the interior endpoint is not an artifact of a degenerate fixture — it is what a field-determined front does to a rail with interior structure, which is precisely the topology the pipeline must support. Second, **repairing this by changing the fixtures is forbidden** and would be self-defeating: the retained plan already prohibits result-specific fixture filtering, and a one-edge rail would retire the only fixtures that can ever exercise the junction clauses.

## Obligations carried, not retired

`RP-01`, `RP-02` (now localized per RA-59.8, **still open**), `RP-03`; the RA-58.7 A5/A6/A7 loci (recorded, guards retained, **no probe**); `R4-OHF-02` (recorded, guard retained, no probe); the two RA-57.9 guards and RA-41's junction/sector clauses (frozen **UNEXERCISED**, construction recipe now known, **not retired**); the 34 Phase10 / seven DCEL / six CP3 identities; the CP2 restorations outside the 37; organic D1/D2/D3/D5 and A6/A7 witnesses; the odd-τ witness; the two `SurfaceCellTracingPhase14` identities requiring a separately packaged historical executable (`cmake/DirectionalTests.cmake:554-572`), which must **not** be bundled into a measurement rung. The `SurfaceCellPipelinePhase20` suite-name collision across two targets stands; cite tests by fully qualified `Suite.Name`, never a bare `Suite.*` filter (RA-57.10).

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | All four frozen selectors match pinned values in the working tree; no selector added, changed or accepted, so no new prefix comparison applies |
| Decisive claims independently re-derived | 39/39 ∈ 94-row R3 register by set intersection; 117 field comparisons against the register, zero mismatches; inventory SHA-256 re-hashed and matched; harness read line by line; all source and test anchors read from bytes |
| Non-vacuity checked | RA-59.8: the acceptance half of the certificate model has **no** witness, green or red; the junction loop is unreachable at `routeLength=1` |
| Prior obligations discharged / carried | RA-57.7 hypothesis set **closed**: (b) and (c) eliminated, (a) selected and amended; RA-58.9 arithmetic applied; all other obligations carried above |
| Stable accounting | 66/17/49, debt 1, CP2 491/491, R3 403/497, frozen selector 497, no promotion, no stable event, no recurrence |
| New candidates / obligations recorded | `R4-TB-A-RP02-01` carrier mechanism now selected (RA-59.9) and its falsifier frozen; ordinal-405 `endpoint-0` separated as a distinct A2b provenance defect; junction-clause construction recipe recorded |
| ORIENTATION currency line | `M6-CP3-TB1-R4-CARRIER-REV`, 2026-10-15 |
| CHANGELOG | 2026-10-15 root entry; root `CHANGELOG.md` is canonical |
| LESSONS | RA-59.4 mints **a measured value without its expected value is not a discriminator**; LESSONS 160, 171, RA-56.8, RA-57.12 and RA-58.8 all cited and still in force |
| Successor frozen | `M6-CP3-CB1-R4-WITNESS-REPAIR` (Code + Build, compile-only), re-entered under RA-59.9 with its RA-57.5 vocabulary amendment and the RA-59.9 falsifier checked first |
| Turn boundary held | Review only: no source, test, selector, harness, workflow, binary, benchmark or ledger change; no Directional binary executed |
| `review_check.py boundary` | Run after document commit; result recorded with the commit |
| `STATUS` lifecycle maintained | Six fields set, `COMPLETE`, named `Successor` |
