# M3-CP4c-3-TB42 — Independent Review Record

**Turn:** `M3-CP4c-3-TB42-REV` — independent review (absorbs REVIEW + PLAN).
**Status:** STATIC / EVIDENCE-ONLY / NO RUNTIME / NO COMPILE / **NON-STABLE**.
**Measures:** **ED0–ED7**.
**Adjudicated evidence:** `Architecture_M3_CP4c3_TB42_EXEC_Report.md`, immutable package107 `10070788592` /
source `5dacce6019ea34316c48743f3033d2bb5c26281a`, selector409 run `34265561941`.

---

## ED0 — TB42 is mechanically valid and is promoted; packages advance to 107

All 409 identities executed exactly once in a fresh process each: `script_exit=0`,
`orchestration_failure=false`, selection integrity true, zero timeouts, zero nonzero runtime exits, no
configure/compile/relink/generated-discovery/package-repair/mutation/benchmark. Root package `SHA256SUMS` 28/28,
`runtimeExecution=false`, `exactArithmeticBackend=GMP`, selector409 byte-frozen at `eea6d8c2…`, selector408 still
its exact prefix, harness `aaadab35…`. Package immutability held: root digest identical before and after
(`23c687d1…`).

**Result: 398 PASS / 11 RED / 0 SKIP, accepted 1–365 = 365/365**, RED
`[366,367,368,369,370,374,390,393,398,406,407]` — **identical to the promoted TB41 baseline**, and the ledger
SHA-256 `5b1e663e…` is identical too.

**EC7.4 is discharged by artifact.** CB47 was to add diagnostics only; an identical ledger hash beside a *changed*
failure-detail digest (`f2b3cb59…` vs TB41's `82b7a0e8…`) is exactly the "same verdicts, richer evidence" receipt
(`LESSONS.md` 151). The oracle was not re-hidden and 390/393/406/407 remained RED, as ED0's predecessor required.

**`M3-CP4c-3-TB42` is promoted to current valid semantic runtime authority; package count advances to 107.**

---

## ED1 — the measurement, and what it settles

CB47 published the EC7 row on all four protected identities, identically:

```text
unlabeledFaceCount                      = 226
frontierPartitionComponentCount         =   9
ownerConsistencyRowCount                =   9
regionFrontierLocator                   = none
regionFrontierLocatorSurvivedGuard      = none
failure source face in partition        = false
failing-region source faces             =  10
failing-region source faces in partition =  0
```

This settles TB41-REV's EC3 completely.

- **Candidate 1 — "the partition is empty" — is REFUTED.** There are **226** unlabelled faces in **9** components.
  The census subject exists and is substantial.
- **Candidate 2 — "the failing object is outside the partition's domain" — is CONFIRMED, and is stronger than
  stated.** It is not merely that `failure.sourceFace` is absent (`false`). **The entire failing region is
  absent**: all **10** of its source faces are labelled, so **0** are in `componentByFace`.
- **The guard analysis in EC3 is confirmed.** `ownerConsistencyRowCount == frontierPartitionComponentCount == 9`,
  exactly the one-row-per-component relation predicted from
  `CertifiedSourceFaceOwnerConsistency.h:38–44`. The guard is benign and was never reached —
  `regionFrontierLocatorSurvivedGuard = none` because `regionFrontierLocator = none`.
- **No locator resolved.** `uncutFaceComponent` is unset for this failure; `sourceFace` misses because the face is
  labelled; the region sweep misses because all 10 of the region's faces are labelled; and the single-component
  fallback cannot fire because the partition has 9 components, not 1.

> **The census subject exists and is disjoint from the failing object.** This is a **domain mismatch**, not an
> empty set, not a locator bug, and not a guard bug.

---

## ED2 — the identities' own names disclose the domain they were written for

Three of the four are, by name, about the **uncut-component** census:

| Ordinal | Identity |
|---:|---|
| 390 | `GlobalTopologyPlan.UncutFaceComponentBoundaryOrbitAttributionPublishesThroughMechanicalProductionFailure` |
| 393 | `GlobalTopologyPlan.MechanicalProjectionEvidencePublishesMinorityRowsAndFaithfulnessResidual` |
| 406 | `GlobalTopologyPlan.UncutComponentCensusNamesThePartitionItDescribesAndWhetherItMatchesTheFailingComponent` |
| 407 | `SurfaceCutGraph.InteriorArcCensusNamesCrossedFacesAndTheirComponentsInBothPartitions` |

The uncut-component partition covers **unlabelled faces by construction** (`GlobalTopologyPlan.cpp:1341–1353`).
These identities were written to check that this census publishes correctly **when the failure lies inside that
partition** — which is precisely the condition their `regionFrontierFailureStage == "UncutComponent"` early return
tested.

> **The early return was not an accident of control flow. It was the domain guard**, expressed as a stage check
> rather than as a domain check. The pipeline advancing to `RegionCertification` did not remove a guard — it
> removed the **precondition** the guard stood for, and the assertion behind it then demanded evidence about an
> object that has nothing to do with the failure.

Ordinal 407's name — *"…AndTheirComponentsInBothPartitions"* — is a further signal: these identities live squarely
inside the long-open **two-partitions-of-one-mesh** problem, open since TB26 and still carried in `ORIENTATION.md`
§7. That is the frame in which the successor must decide, not as an isolated assertion repair.

---

## ED3 — what the successor must decide, and why it is a definition question

`expect_later_region_frontier_evidence` currently demands `regionFrontierComponentCount > 0` for **any**
non-`UncutComponent` stage. TB42 shows that demand is unsatisfiable for a `RegionCertification` failure in a fully
labelled region, and will remain so for every such failure, because the two objects are disjoint by construction.

There is no measurement left to take. **The remaining question is normative:** what frontier evidence should a
certification-stage failure carry, and about which object? `DEFN-R8` — pre-named at TB41-REV — is that turn, and
its scope is now fully determined:

1. **Is the uncut-component census the right evidence for a certification-stage failure at all?** ED1 says the
   objects are disjoint. If the answer is no, the oracle's domain must be stated explicitly rather than encoded as
   a stage string.
2. **If not, what is?** A failure in a labelled region plausibly wants evidence about *that region's* ownership and
   fragment structure — `regionOwningFragmentOrbit` already exists at the failing site — not about a partition of
   the faces it does not contain.
3. **How is the domain expressed?** A stage-name comparison was a proxy for a domain predicate and silently stopped
   tracking it. The replacement must be a **domain** condition — "the failing object lies in the partition this
   census describes" — so a later stage change cannot re-activate the wrong assertion.
4. **What must the four identities assert instead**, without weakening them into vacuity? Each must still fail if
   the census it names is genuinely broken *within its own domain*.

**No weakening is authorized as a shortcut.** The failure mode to avoid is making all four pass by widening the
early return, which would re-hide the oracle exactly as EC7.4 forbade.

---

## ED4 — the rest of the ledger

**366/367** remain at `RegionSourceFaceOwningFragmentMissing` during `RegionCertification`, publishing
`regionOwningFragmentOrbit` — the live A2b frontier, `M3-CP4c3-TB40-REV-CAND-02`, unchanged and not corrected.

**368/369/370/374/398** are carried on their pre-existing owner surfaces, not reassigned. Retired codes remain
absent, including `RegionEulerCharacteristicNotOne`, `RegionInteriorDisconnected`,
`TraceArcDoesNotSeparateItsSides` and `UncutFaceComponentOrbitSeedNotUnique`.

Preserved: **311, 312, 314, 315, 356, 357, 404, 408, 409 PASS**; ownership **300 / 0 / 0**.

---

## ED5 — classification

| Ordinal(s) | Classification |
|---|---|
| **390, 393, 406, 407** | **Domain mismatch, not a defect in the census.** The uncut-component partition (9 components, 226 faces) is disjoint from the failing region (10 faces, 0 in partition). Owner: **`M3-CP4c-3-DEFN-R8`**. |
| **366, 367** | Live A2b frontier — `RegionSourceFaceOwningFragmentMissing`. `M3-CP4c3-TB40-REV-CAND-02`. |
| 368, 369, 370, 374, 398 | Carried, prior owners, not reassigned. |

---

## ED6 — accounting: no new event

The accepted prefix is **365/365** and the RED set is **identical to the promoted TB41 baseline**. No accepted green
was lost and no identity changed state, so **no stable event is created**.

**Totals remain 47 events / 14 categories / 33 recurrences.** Produced-witness debt **5**. Semantic package count
**107**. CP4c-3 remains **OPEN**.

**Candidate dispositions.**

- `M3-CP4c3-TB40-EXEC-CAND-02` → **MEASURED / DEFINITION PENDING**. The measurement is complete; the remaining
  question is normative and belongs to `DEFN-R8`. **No further CB may be spent measuring this.**
- `M3-CP4c3-TB41-REV-CAND-01` (is a non-empty frontier census legitimate at `RegionCertification`?) → **PROMOTED
  TO THE DECIDING QUESTION**, owned by `DEFN-R8`, now with the numbers that answer it.
- `M3-CP4c3-TB40-REV-CAND-02` (`RegionSourceFaceOwningFragmentMissing`) → **ACTIVE / GATING**, unchanged.
- `M3-CP4c3-TB41-REV-CAND-02` (ordinal 315 tampers only the orbit; an anchor tamper is stronger) → **ACTIVE /
  HARDENING**, unchanged.
- `M3-CP4c3-TB26-REV-CAND-04` / `M3-CP4c3-DEFN-R3-CAND-01` (two partitions of one mesh) → **RE-LINKED**. ED2 shows
  these four identities sit inside that problem; `DEFN-R8` should decide them together rather than in isolation.

---

## ED7 — exact successor: `M3-CP4c-3-DEFN-R8`

**A definition turn** (absorbs REVIEW + PLAN), static: no runtime, no compile, no package, no selector or product
mutation. It appends **Part XII** to `M3_CP4c_Frozen_Definitions.md`.

**It must decide, and no more:**

- **ED7.1 — the domain of the uncut-component frontier census.** State normatively that it describes the
  **unlabelled-face partition** and is meaningful only for a failure whose object lies inside that partition. Cite
  `GlobalTopologyPlan.cpp:1341–1353` and the TB42 numbers (226 / 9 / 9, and 0-of-10).
- **ED7.2 — what a `RegionCertification` failure must publish instead.** Name the object and the fields. If the
  answer is that region-level ownership evidence is the right carrier, say so and name the existing
  `regionOwningFragmentOrbit` publication as its seed.
- **ED7.3 — express the condition as a domain predicate, never a stage string.** The current guard compares
  `regionFrontierFailureStage` to a literal; that is a proxy that stopped tracking what it stood for. Require the
  replacement to test **membership in the census's own domain**, so a future stage change cannot re-activate the
  wrong assertion. This is the general rule, not a local fix.
- **ED7.4 — restate each of the four identities' obligations** so that each still **fails** when the census it
  names is broken within its own domain. **Widening the early return to make all four pass is prohibited** — it
  would re-hide the oracle EC2 exposed.
- **ED7.5 — decide these together with the two-partitions question** (`M3-CP4c3-TB26-REV-CAND-04`,
  `M3-CP4c3-DEFN-R3-CAND-01`), or state explicitly why they are separable. Ordinal 407 spans both partitions by
  name.
- **ED7.6 — what must not change.** Accepted **1–365** stays 365/365; ordinals **311/312/314/315/356/357/404/408/409**
  keep their contracts; selector **409** byte-frozen; the Part XI binding, `region_orbit`, the orbit-keyed lookup
  and the content anchor are untouched; no work on 366/367/368/369/370/374/398; no change to region construction,
  ownership, `fragmentCorners`, the partition's domain, cut selection or A2a′ cellularity semantics.
- **ED7.7 — freeze the implementing turn** `M3-CP4c-3-CB48` with falsifiers stated before the build, and the
  artifact-only `M3-CP4c-3-TB43-EXEC` gate after it.

**Falsification, to carry into `CB48`.**

- **Accepted prefix 365/365 is a stop condition**, as are ordinals 311/312/314/315/356/357/404/408/409 PASS.
- If 390/393/406/407 pass because the assertion no longer runs on **any** input, the oracle was hidden again, not
  repaired — CB48 must publish, per identity, **which branch it took and why**, so "passed" and "did not run"
  remain distinguishable in the ledger (`LESSONS.md` 160).
- If any of the four cannot be made to fail on a deliberately broken census within its own domain, the restatement
  in ED7.4 is vacuous and the turn halts.
- If the repair requires widening `unlabeledFaces` or otherwise changing the partition's domain, ED7.6 is violated
  and the question returns to definition.

**Prohibited:** weakening the four identities into unconditional passes; widening the early return; changing the
frontier partition's domain; correcting `RegionSourceFaceOwningFragmentMissing`; spending another CB measuring what
TB42 has already measured; any accepted-identity or selector byte change; any Directional runtime in the definition
turn.

**Exact next turn: `M3-CP4c-3-DEFN-R8` — definition turn, static, appending Part XII.**
