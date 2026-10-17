# Review decision — the true control answers the question, and it answers it more strongly than reported

**Turn adjudicated:** `M6-CP3-TB1-R4-TRUE-CONTROL` (Test + Benchmark, artifact-only).
**Disposition:** the **measurement is ACCEPTED**; **RA-57.8 is DISCHARGED**; the report's **interpretation
is AMENDED — it understated its own result**; its **classification of identity 3 is CORRECTED**; the
**carrier is now bounded to OPEN hard-rail terminal certification**; the census is **AUTHORIZED to
proceed** with one added column. Frozen as **RA-58**. No promotion, no new stable event, no 497 run, no
gate credit. Ledger **66/17/49**, debt **1**, CP2 **491/491**, R3 **403/497**, selector **497** —
unchanged.

Evidence frozen beside this record:
`Architecture_M6_CP3_R4_True_Control_Ledger_20261015.tsv`,
`Architecture_M6_CP3_R4_True_Control_Measured_Loci_20261015.tsv`.

## RA-58.1 — accepted, re-derived from the artifact

Result artifact `11948572472`; the ZIP I downloaded hashes
`2b6ac34c34ea3f0dd384f5be7a55ca9c9028328639effed3c9cc3e3c9674917f`, matching the report. Receipts:
`executed=4 red=2 missing=0 postflight=true compile=false relink=false benchmarks=false selector497=false
exit=0`; `package=true source=true execution_view=true selector=true`; manifest **28 OK → 28 OK**;
harness SHA-256 `9d471c493b7d3c9c4fa5bf31916e37d9caa470a628da6c0e710f770f0c986162` matching the report
and the dispatch record. `git diff c2b3571bb..HEAD -- src include tests cmake benchmarks` is **empty**.
Each of the four logs contains **exactly one** `: Failure` line, which is what makes the locus analysis
below sound: gtest `ASSERT_*` is fatal, so every assertion preceding the reported one passed.

This turn reported its own result, closed `COMPLETE`, and named a successor. The RA-57.1 reconstruction
problem does not recur.

## RA-58.2 — RA-57.8 is DISCHARGED, and discharged the right way

Verified in `.agents/Directional/tools/m6_cp3_r4_true_control_harness.sh`:

- non-selection now records `NOT_SELECTED`, increments `missing` and **`continue`s** — the `die` that
  aborted every later identity is gone (RA-57.8(ii));
- the final verdict is `[[ "$executed" == 4 && "$missing" == 0 && "$postflight" == true ]] || die` then
  `exit 0`. The bare `[[ "$red" == 0 ]]` tail is gone, so expected REDs no longer forge an orchestration
  failure (RA-57.8(i)), and `die 'incomplete breadth'` is retained exactly as required.

It was done in a **new one-off harness** rather than by editing the previously dispatched one, whose
SHA-256 is pinned in RA-57.8's own evidence. That is the correct call and I record it as such.

## RA-58.3 — the decisive positive: A4 production is not universally down

Both no-interior-hard-rail identities **PASS**, and both are members of the **frozen `selector449`**:

- `SurfacePhaseFrontProductFactoryAuthority.ReorderedCellStoragePreservesTypedEdgeOwnershipAtCheckedFactory`
  — `square_fixture()`, whose builder inserts no `userHardEdges`; 0 ms.
- `SurfaceCellTypedTransportAuthority.ValidPeriodicCutRouteUsesTypedIdentity` — `cylinder_fixture()` →
  `make_committed_fixture("cylinder", false)`, no `userHardEdges`; **613 ms**, a substantial real pipeline
  run, exercising `PeriodicCut` boundary authority rather than `HardRail`.

Neither appears in the 94-row R3 RED classification, so both were among the 403 R3 PASS and **both are
still green on `953f812f`** — a positive `R4-VIN-01` datapoint. **No gate credit is claimed**: the frozen
497 did not run, and two members passing is not 497 acceptance.

## RA-58.4 — the report understated its own result. The closed-chain arm is informative, and POSITIVE.

The report wrote: *"Both closed-chain torus identities fail, but neither raw log proves the previously
measured open-rail `no-exact-terminal-corner` predicate. Do not conflate these failure loci."* The refusal
to conflate is right, and I confirm the premise independently — **zero** occurrences of
`no-exact-terminal-corner`, `InvalidHardRailRouteCertificate` or `endpoint-1` in either torus log.

But stopping at "do not conflate" discards the finding. Read the loci against the source:

**Identity 3** (`tests/SurfaceCellTransitionQuotientTests.cpp:6018`): the sole failure is at `:6023`
`ASSERT_TRUE(run.surfaceCellContext.hasArrangement)`. The immediately preceding fatal assertion,
`:6022 ASSERT_TRUE(run.surfaceCellContext.hasTraceNetwork)`, **passed** — the trace network, which is
where the phase front and the hard-rail route certificates live, **was produced** on a torus carrying
closed-chain hard edges. The failure is downstream, at arrangement.

**Identity 4** (`:2773`): the sole failure is at `:2807` `ASSERT_NE(originalOccurrences, nullptr)`.
Everything before it passed, which includes `fixture.network.phaseFront.product()` being obtained and —
decisively — `:2795 ASSERT_NE(rotated, nullptr) << "uniform Z4 gauge rotation must be accepted"`. That
assertion guards a `SurfacePhaseFrontProduct::make` call fed `front.hardRailRouteCertificates()`,
`front.hardRailTerminalContacts()` (`:2791`) and `front.hardRailClosedChains()` (`:2792`). **The checked
factory ACCEPTED closed-chain hard-rail certificates and terminal contacts under a Z4 gauge rotation.**
The failure is downstream, in A5 `SurfaceOccurrenceComplexProducer::produce`.

So both torus identities **reached and cleared A4**, including its hard-rail certificate machinery. The
closed-chain arm did not come back negative or uninformative; it came back **green where it mattered**.

## RA-58.5 — CONCLUSION: the carrier is bounded to OPEN hard-rail terminal certification

Assembling the measured record:

| path | hard rail | A4 production | result |
|---|---|---|---|
| square, cylinder (RA-58.3) | none | green | **PASS end-to-end**, frozen-497 members |
| torus ×2 (RA-58.4) | **closed chain** | **green, certificates accepted** | RED downstream, at A5 / arrangement |
| 3×3 midline ×4 (RA-57.2) | **open, interior terminals** | **REJECTED** | RED at `no-exact-terminal-corner` |

This is RA-57's reading-grid case 1, established: **the defect is confined to open hard-rail terminal
certification.** It also corroborates RA-57.5 from an independent direction — a **closed chain has no
terminals**, so `exact_corner` and the terminal-contact path are never taken on the torus, and the torus
A4 passes. The defect attaches specifically to the **terminal-closing requirement on an open rail**, which
is exactly the construct RA-57.5 showed is being applied to two fronts meeting **across** the rail at an
interior point.

The three RA-57.7 hypotheses — certificate too strict, pairing wrong, route truncated — all survive. **None
may be chosen.** The bound narrows *where* to look; it does not select *what* is wrong.

## RA-58.6 — classification CORRECTED: one torus RED is already in the 94, the other has no baseline

The report tabulated both torus REDs as plain REDs. The repository says otherwise.

**Identity 3 is already one of the 94 R3 RED.** In
`Architecture_M6_CP3_TB1_Entry_R3_Red_Classification.tsv`: `phase=focused30`, `ordinal=25`,
`first_observable=OTHER_FIRST_PREDICATE`, `R2_RED=true`, **`CP2_ACCEPTED=true`**, candidate
`R2-CAND-04`, and its recorded first diagnostic is
`tests/SurfaceCellTransitionQuotientTests.cpp:5775: Failure | Value of:
run.surfaceCellContext.hasArrangement | Actual: false | Expected: true` — **the same assertion on the
same value** as today's `:6023`, the line having shifted +248 with source evolution. It is the **single**
`OTHER_FIRST_PREDICATE` member of the 94. So this is a **reproduced carried loss inside the frozen 497**,
not news; and usefully, it is now re-measured on `953f812f` and still RED, so no vintage ambiguity
remains for it.

**Identity 4 is in no selector at all** — 0 hits in `focused30`, `focused12` and `selector449` — and 0
hits in the 94. **There is no accepted baseline, so it is not a regression**, is not ledger-eligible, and
is a first-ever measurement of an unselected identity. Recording it as an ordinary RED alongside identity
3 flattens two very different accounting states.

## RA-58.7 — a new, separate obligation: recorded, not chased

Identity 4 shows **A5 `SurfaceOccurrenceComplexProducer::produce` returning its error alternative for a
front that A4 produced and the checked factory accepted** (`:2797-2799`, failing at `:2807`). Identity 3
shows arrangement absent on a produced torus trace network. Both belong to the **A5/A6/A7 backlog**, not
to the hard-rail carrier, and they must not be folded into it. No probe is authorized: chasing them now
would be an extra Code rung of exactly the kind RA-54.7 forbids. They are recorded here, their guards
untouched and fail-closed.

## RA-58.8 — my reading grid was wrong, and it is the second instance of one error class

RA-57's grid read: *"Torus RED but square/cylinder PASS → the defect is **all** hard-rail routing, open
and closed."* Applied to this run — torus RED, square and cylinder PASS — it yields precisely the
**opposite** of the truth, because both torus REDs sit downstream of a **successful** hard-rail A4.

The grid conditioned on the **verdict**. The question was about the **locus**. This is the same error class
as RA-57.3, where I specified a "control" whose fixture could not discriminate: in both cases the
instrument's output did not answer the question the instrument was built to answer. Recorded under `RP-03`.

**LESSONS, minted:** *condition an instrument on the locus of failure, not on the verdict.* A pass/fail
grid over a staged pipeline is only valid if each branch also names the stage at which the verdict must
appear. The executor's instinct — refusing to conflate loci — was better than my grid, and is upheld.

## RA-58.9 — RA-57.11's blast radius did NOT fire, and that changes the census column

Both torus REDs hang off the same `static` `torus_fixture()` singleton, which is the RA-57.11 shape. But
here **the singleton succeeds**, and the two tests then fail at genuinely different downstream loci. So a
census column recording merely *which* fixture singleton an identity hangs off would have merged these two
as one defect — wrongly. **The column must record whether the singleton itself succeeded, and the stage at
which the first failure appeared**, not just the singleton's name. RA-57.11's merge rule applies only to a
**throwing** singleton.

## RA-58.10 — the census is authorized, scope unchanged, key extended

`M6-CP3-TB1-R4-ENDPOINT39-CENSUS` proceeds as frozen in RA-57.12, with one addition from RA-58.9: for each
identity record **the fixture singleton, whether it constructed successfully, and the pipeline stage of the
first failure** — alongside `routeLength`, `step`, `chi`, probe charts and parameters,
`closedChainPresent`, and the full `faceEnds` (kept for the record, never read as corroboration). Carrier
membership must be stated per identity against the 94-row R3 classification and against all three
selectors, so reproduced carried losses, in-gate REDs and baseline-free first measurements are never
tabulated as one kind of thing again.

## Obligations carried, none retired

`RP-02` still open — the network-bound consumer has never been reached. `R4-OHF-02` recorded, guard
retained, no probe. `RP-01`, `RP-03` standing. RA-41's junction/sector clauses frozen **UNEXERCISED**,
together with the two guards of RA-57.9. The two Phase14 supplementals still need a separately packaged
historical executable (`cmake/DirectionalTests.cmake:554-572`). Backlog: the 39-identity carrier, 34
Phase10, seven DCEL, six CP3, the CP2 restorations outside the 37, organic D1/D2/D3/D5 and A6/A7, odd-τ,
and now the A5/A6/A7 loci of RA-58.7. The retained repair plan stands with the RA-57.5 vocabulary
amendment still outstanding.

Two process exceptions were disclosed by the executor — a bootstrap read-order violation, and a Drive
transport failure that forced direct connector writes with a retained-but-**unapplied** local patch. Both
are correctly excluded from evidence and the unapplied patch is correctly flagged as non-authoritative.
Neither bears on the measurement, which stands on its artifact hashes.

## Successor

**`M6-CP3-TB1-R4-ENDPOINT39-CENSUS`** — unchanged, artifact-only, same package, outside the frozen 497,
with the RA-58.10 key.
