# RA-56 — the first RED is not a new candidate; it is a live reproducer of the 39-identity `A4_ROUTE_CERTIFICATE_REJECTION` carrier

**Turn:** `M6-CP3-R4-WITNESS-REV-ARCH-REV` (Architecture Review only).
**Adjudicates:** `M6-CP3-TB1-R4-WITNESS-EXEC` and `M6-CP3-TB1-R4-WITNESS-REV`.
**Disposition:** the execution and its root-cause localization are **ACCEPTED and independently
re-derived**. The **classification is REJECTED and corrected**. The proposed repair turn
`M6-CP3-CB1-R4-WITNESS-REPAIR` is **RETAINED but DEFERRED** behind two measurement rungs.
**No runtime credit beyond the single executed identity.**

---

## RA-56.1 — the execution held every boundary, and the root cause is CONFIRMED from bytes and geometry

No source, test, fixture, guard, selector or harness changed; first-RED stop honoured; frozen selector
hashes matched; no promotion. The RED was reported with its verbatim assertion rather than smoothed.

I re-derived the localization rather than accepting it. **It is exactly right:**

- `exact_corner` (`src/geometry/SurfaceCellTracing.cpp:19131-19143`) requires a bit-exact one-hot
  barycentric at the corner of `vertex`, for **both** `fromPoint` and `toPoint`, at the **same** terminal
  vertex drawn from `contact->second.endpoints`; otherwise `no-exact-terminal-corner` at `:19152`.
- The fixture mesh (`tests/SurfaceCellsPhase10Tests.cpp:223-264`) is a 3×3 planar grid per component:
  `v1 = (1,0,0)`, `v4 = (1,1,0)`, `v7 = (1,2,0)`, face `0 = (0,1,4)`, face `3 = (1,5,4)`. The hard feature
  is `{1,4} ∪ {4,7}` (`:266-272`), so the rail chain is `1 → 4 → 7` with terminals `{1,7}`.
- The reported probes therefore resolve to **the same 3D point**:
  `face 0, bary (0, 0.75, 0.25) = 0.75·v1 + 0.25·v4 = (1, 0.25, 0)` and
  `face 3, bary (0.75, 0, 0.25) = 0.75·v1 + 0.25·v4 = (1, 0.25, 0)`.
  That point lies at parameter `0.25` **interior to source edge `(1,4)`** and is neither terminal `v1` nor
  terminal `v7`. `corner[1]=0,0; corner[7]=0,0` is correct behaviour, not a defect in the predicate.

**And a co-signal that must not start a false hunt.** `currentFace=0; expectedFace=2` looks like a route
face mismatch. It is not: `failure.face` and `failure.targetFace` (`:18939-18940`) fall back to
`first.from.face` and `second.to.face`, which `faceEnds=0,2|0,3` prints as exactly those values
(`:18948`, `:18951-18952`). The two fields carry **no independent signal**, and in particular this is
**not** an `RP-01` edge/face-namespace recurrence. The report attributed the whole failure to the
exact-corner predicate and was right to.

## RA-56.2 — the classification is WRONG: this is not a new candidate without a baseline

The review records `R4-TB-A-RP02-01` as a new candidate and states *"No comparable accepted runtime
baseline exists for this identity."* That is true of the **new test's own name** and false of the
**failure**. The blast radius was never measured. From the repository:

- **All 21 other uses** of `build_rectangular_hard_rail_phase_front` in `SurfaceCellsPhase10Tests.cpp`
  also open with an assertion that the disposition is `Produced`. If the fixture does not produce, that
  whole family is RED — this is not one witness's precondition failing.
- Two of those identities — `ProductionA4PublishesAcceptedA2bA3ConformityReceipt` and
  `HardRailPairingIsFaceRowOrderInvariant` — are **inside the frozen `selector449`**
  (`.agents/Directional/Architecture_M5_CP4_CB2_Required_Green_Selector_449.txt`, the file the 497 harness
  pins at `tools/m6_cp3_entry_497_artifact_only_harness.sh:16`).
- `Architecture_M6_CP3_TB1_Entry_R3_Red_Classification.tsv` already carries this failure. The 94 R3 RED
  decompose into eight carriers, and the largest is **`A4_ROUTE_CERTIFICATE_REJECTION` at 39**, of which
  **37 are `CP2_ACCEPTED = true`**.
- That set of 39 is **exactly** the long-carried "39 endpoint" backlog item: its identities match
  `Architecture_M6_CP3_R4_Historical_R3_A4_39_Current_Source_Inventory_20261013.tsv` **39/39, with no
  element on either side unmatched**.
- **37 of the 39 lie inside the frozen 497** (26 in `selector449`, 9 in `focused30`, 2 in `focused12`) —
  the same 37 that are CP2-accepted. They are therefore **37 of the 88 carried CP2 losses**.

**Corrected classification.** `R4-TB-A-RP02-01` is **not a new carrier and not baseline-free**. It is a
**new, cheap entry point into the existing `A4_ROUTE_CERTIFICATE_REJECTION` carrier**, which has an
accepted CP2 baseline. Read correctly, this is the most valuable result TB-A could have produced: an 8 ms,
single-test, fully typed reproducer of the carrier that accounts for **~42% of the carried CP2 losses and
~41% of the 94 R3 RED**. The review undersold its own finding.

## RA-56.3 — the carrier is measurable **now**, with no rebuild, and must be measured before any repair

All **39** carrier identities are owned by `directional_surface_cell_producer_tests` — the binary already
inside the immutable package that ran TB-A — and split
`SurfaceCellTransitionQuotientTests.cpp` 19 / `SurfaceCellsPhase10Tests.cpp` 18 /
`SurfaceCellREPackageTests.cpp` 2. Every one of the 39 carries
`status = "STATIC ONLY — current result unknown"`.

**38 of the 39 carry the first-predicate hint `endpoint-0`. TB-A observed `endpoint-1`.**

So the single observation now driving a proposed producer change is the *minority* endpoint of its own
carrier, while 38 majority instances sit unmeasured and reachable for the cost of one artifact-only run.
Repairing the shared producer on that basis is how the wrong thing gets fixed confidently. **Measure the
carrier first.**

## RA-56.4 — my stop-at-first-RED rule was wrong for a triage run; that is my error, and it is amended

RA-55.8 told the executor to stop at the first RED. That rule is correct **inside a repair loop**, where
its purpose is to stop mass-patching. It is **wrong for a first measurement**, where breadth is the whole
point. The executor followed the instruction exactly and should not be marked down for it; the cost is
mine:

- The **control** — `M6CP3.CheckedFactoryRejectsForgedTerminalA2bSideGerm`, which uses a *different*
  fixture — was not run. Its result is the single most informative bit available: it separates "the
  rectangular hard-rail fixture family is down" from "A4 production is down generally."
- Three further identities executable from the **same artifact with no rebuild** were skipped.

**Amended rule, in force from now on:** stop at the first RED only **within a dependent chain**, where a
later identity cannot be interpreted without the earlier one. **Independent identities are all run**, and
every RED is reported with its verbatim first predicate. A triage run is not a repair loop.

## RA-56.5 — an architectural risk the repair plan does not consider: a third reading

The plan offers two readings — an interior interval needing its own certificate, or a pairing rule that
manufactures a false terminal obligation — and correctly refuses to choose between them. But the dump
admits a **third**, and the plan's prescribed data model would silently exclude it.

`faceEnds = 0,2 | 0,3` decodes (`:18948`) as `first.from.face = 0`, `second.to.face = 2`,
`first.to.face = 0`, `second.from.face = 3`. The first front therefore lies **entirely inside face 0**,
and the second spans faces 3 → 2. Both meet at `(1, 0.25, 0)` on the rail. That is the signature of two
fronts meeting **transversally across** the rail, not of two intervals running **along** it.

The plan prescribes authenticating the admitted case with *"canonical intrinsic parameter on the same
source edge, ordered rail interval/face-side ownership."* That vocabulary presumes along-rail intervals.
**If the event is a transversal crossing, that is the wrong abstraction**, and adopting it would freeze a
mis-shaped certificate into the producer — the same class of mistake as RA-45.2's category error and the
"publish, don't invent" family. **Do not choose the certificate model before the carrier census says
which shape dominates.** The census answers it directly: every failing pair prints its own `faceEnds`.

## RA-56.6 — the repair plan is otherwise sound and is RETAINED, not discarded

It refuses to pick a fix merely to satisfy the assertion, keeps `no-exact-terminal-corner` and the
duplicate-contact, barrier, closed-chain and missing-contact guards fail-closed for genuine terminals,
forbids weakening the RP-02 test's `Produced` precondition or its consumer receipt, forbids fallback and
source-grid recovery, and carries real stop conditions. That is the right shape for a repair turn. It is
deferred, not rewritten, and it must be re-entered **with the census in hand** and with RA-56.5 answered.

## RA-56.7 — what remains true

`RP-02 TEST_AUTHORITY_COVERAGE_GAP` is **still open**: the run died before
`assign_open_front_boundary_authority`, so no consumer receipt exists and the tamper half never ran.
RA-55.3's source-level non-vacuity finding is undisturbed — the positive would still fail if the consumer
were bypassed — but non-vacuity is not liveness. `R4-OHF-02` stays recorded with its guard retained and no
probe. The two Phase14 identities need `DIRECTIONAL_BUILD_HISTORICAL_TESTS`
(`cmake/DirectionalTests.cmake:556-574`) and must be handled by a separate packaging turn, not bundled
into a measurement rung.

## RA-56.8 — accounting

Ledger **66 / 17 / 49**, M6 debt **1**, selector **497** untouched, CP2 **491/491** accepted, R3
**403/497** rejected with 94 RED and 88 carried CP2 losses, PR #8 draft/open — **all unchanged**.
`R4-TB-A-RP02-01` is reclassified as an entry point into the existing `A4_ROUTE_CERTIFICATE_REJECTION`
carrier rather than a new candidate; **no new stable event, category or recurrence is minted**, because a
recurrence requires a reviewed runtime adjudication the census has not yet supplied. No promotion.
A compile is not a restoration (LESSONS 160); a census is not a witness (LESSONS 171); **and one measured
identity is not a measured carrier.**
