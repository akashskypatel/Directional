# M3-CP4c-3-TB41 — Independent Review Record

**Turn:** `M3-CP4c-3-TB41-REV` — independent review (absorbs REVIEW + PLAN).
**Status:** STATIC / EVIDENCE-ONLY / NO RUNTIME / NO COMPILE / **NON-STABLE**.
**Measures:** **EC0–EC7**.
**Adjudicated evidence:** `Architecture_M3_CP4c3_TB41_EXEC_Report.md`, immutable package106 `10066942690` /
source `4cdffe5514ab9f747da38e74c57663ee8806efa6`, selector409 run `34256568679`.

---

## EC0 — TB41 is mechanically valid, the accepted prefix is restored, and TB41 **is promoted**

409/409 identities executed once in selector order, every row `selected=1`, zero selection mismatch, zero timeout;
`runtime_started/completed=true`, `orchestration_failure=false`, `execution_view_verified=true`, every
mutation/build/benchmark flag false; package root manifest 28/28; selector409 byte-frozen at `eea6d8c2…`.

**Result: 398 PASS / 11 RED, accepted 1–365 = 365/365**, RED `[366,367,368,369,370,374,390,393,398,406,407]`.

**`M3-CP4c-3-TB41` is promoted to current valid semantic runtime authority; package count advances to 106.**

This is a judgement call and the reasoning is recorded. The project's operative promotion rule, applied at TB39 and
withheld at TB38 and TB40, is **mechanical validity plus an intact accepted prefix** — TB39 was promoted at
402 PASS / 7 RED, so promotion has never required an all-green ledger. TB41 satisfies both conditions. Against
that, TB41 carries four protected RED identities that TB39 did not. **Promotion does not close, excuse, or reprice
that loss** — it remains owned by the TB40 stable event and by `M3-CP4c3-TB40-EXEC-CAND-02` (EC2). The deciding
consideration is that TB39's package source no longer exists in the tree, so leaving authority there would make
static review of the working tree invalid evidence about the authority, which is worse than recording a known,
owned, evidence-publication gap.

---

## EC1 — EB7.1 is discharged, and the repair is a good one

Ordinals **311 / 314 / 356 / 357 all PASS**. CB46 replaced the orbit-ordinal comparison with a **content anchor**:
`canonical_cycle_anchor(...)`, the canonical oriented arc of the boundary cycle, carried on the certificate and
independently re-derived by the oracle.

The census now reads:

```text
region 0: independent=(arc 0, Reverse)  certificate=(arc 0, Reverse)  orbit=1  upstream=1  arcs=26/26  disc=true
region 1: independent=(arc 0, Forward)  certificate=(arc 0, Forward)  orbit=0  upstream=1  arcs=50/50  disc=true
region 2: independent=(arc 12, Reverse) certificate=(arc 12, Reverse) orbit=2  upstream=1  arcs=50/50  disc=true
region 3: independent=(arc 24, Reverse) certificate=(arc 24, Reverse) orbit=3  upstream=1  arcs=26/26  disc=true
```

Three things are worth stating explicitly:

1. **The transposition is still there** — region 0 ↔ orbit 1, region 1 ↔ orbit 0 — **and it is now correctly a
   non-event.** That is direct confirmation of the TB40 diagnosis: the product was never mis-bound, and the two
   orbit numberings genuinely differ.
2. **The anchor is non-uniform and discriminating** — four distinct oriented arcs, `(0,Reverse)`, `(0,Forward)`,
   `(12,Reverse)`, `(24,Reverse)`. Note `arc 0` appears twice with **opposite orientations**, so orientation is
   load-bearing, not decorative. **EB7.4 is discharged**: this census can disagree with itself.
3. **Arc counts now differ across rows** — 26/50/50/26 — so the arc-count control is no longer blind the way it
   was at TB40, where regions 0 and 1 happened to share a count.

**EB7.3 is preserved.** Ordinals **312 / 315 / 409 PASS**; `region_orbit`, the orbit-keyed lookup and the
derived-not-stored rule are untouched, and 315 still forces `InvalidRegionCertificateBinding` when a region's
`actualEmbeddedFace.orbit` is replaced with a distinct published orbit.

*Hardening note, not a defect:* 315 tampers only the orbit. Now that a content anchor exists, a tamper of the
**anchor** would be the stronger negative. Recorded as `M3-CP4c3-TB41-REV-CAND-02`.

---

## EC2 — the decisive reframe: those four oracles had never run before

**390 / 393 / 406 / 407 are not a behaviour regression.** All four are mechanical-fixture identities with the same
shape (`tests/FieldAlignedCurveNetworkTests.cpp:11910`, `:12122`, `:14943`, `:14987`):

```cpp
if (mechanical.plan.has_value()) { /* guard-cleared */ return; }      // trivially PASS
const auto &locus = mechanical.terminalFailureLocus;
if (locus.regionFrontierFailureStage != "UncutComponent") {
  expect_later_region_frontier_evidence(locus);                        // requires count > 0
  return;
}
```

For every prior turn the mechanical plan terminated at the **`UncutComponent`** stage, so all four took the early
return and `expect_later_region_frontier_evidence` (`:4411`) **never executed**. They were green **by not
asserting**.

TB40/TB41 moved the mechanical terminal failure to the **`RegionCertification`** stage. The oracle therefore ran
**for the first time in this checkpoint** and found `regionFrontierComponentCount = 0`.

> **This is an assertion reaching its subject for the first time and finding nothing there — not evidence that
> something which used to work has broken.** The frontier census at the certification stage has never been shown to
> work at all.

That reframing matters for what CB47 may conclude, and it is why "restore the previous behaviour" is not an
available remedy: there is no previous behaviour of this oracle to restore.

---

## EC3 — why CB46's correction could not have worked

CB46 did what EB7.2 asked in the narrow sense. It changed
`region_frontier_components` (`GlobalTopologyPlan.cpp:667–706`) from an `if / else if / else if` chain into three
independent `if`s, so every available locator is consumed rather than only the first — the DEFN-R4 rule applied to
locator selection. It also began publishing `regionOwningFragmentOrbit` at the failing site (`:2028`).

**But all three locators resolve through one object**: `frontier.partition.componentByFace`, and the guard
`component < frontier.ownerConsistency.components.size()`. Three facts verified from source:

- the guard is **benign** — `check_certified_source_face_owner_consistency`
  (`src/geometry/CertifiedSourceFaceOwnerConsistency.h:38–44`) reserves and fills **one row per partition
  component**, so any index from `componentByFace` passes it;
- the success path **does** carry the real frontier — `RegionBuildSuccess{std::move(regions), frontier, …}`
  (`:1505`) — so it is not a default-constructed copy;
- the annotation **is** applied on the certification path — `annotate_region_frontier_evidence(...,
  RegionFrontierFailureStage::RegionCertification, regionSuccess.frontier, …, &candidate.regions)` (`:2418–2420`),
  and the published stage confirms it ran.

So the annotation executes, the guard admits, and the frontier is real — and the census is still empty. **The
remaining possibilities both concern the censused set, not the locators**:

1. **`frontier.partition` is empty or near-empty.** It is built over `unlabeledFaces` (`:1341–1353`) — faces with
   no `fragmentOrbits` entry at that point. `fragmentOrbits` is already populated for trace/cut chords (`:901`),
   mandatory-edge faces (`:937`) and cut-edge faces (`:985`). The source comment at `:1338` states the partition
   "remains only as a consistency guard" now that ownership is total at **300/300**. If `unlabeledFaces` is empty,
   `partition.components` is empty, every `add_component` is a no-op, and even the single-component fallback
   (`:704–705`) cannot fire.
2. **The failing objects are outside the partition's domain.** `RegionSourceFaceOwningFragmentMissing` fires at
   `:2020–2028` only when the face **is** in `fragmentCorners` — i.e. a labelled, trace-cut face, which is
   excluded from `unlabeledFaces` by construction. The `failure.sourceFace` locator therefore misses by
   definition; only the region-wide sweep (`:691–703`) could rescue it, and only if some other face of that region
   is unlabelled.

**This review does not choose between them**, because neither is decidable from static source without the counts.
What it does establish is the shape of the error:

> **CB46 corrected which locator is consulted without first establishing that the set being censused is
> non-empty.** That is the third consecutive turn with this shape — DEFN-R6.7's verifier passing over an empty
> table (`LESSONS.md` 155), Part XI's census publishing one uniform bit N times (`LESSONS.md` 157), and now a
> locator broadening over a possibly-empty partition. `LESSONS.md` 159.

---

## EC4 — the live frontier

**366 / 367** remain RED at **`RegionSourceFaceOwningFragmentMissing`** during `RegionCertification`, now
publishing `regionOwningFragmentOrbit` alongside the source face. This is `M3-CP4c3-TB40-REV-CAND-02`, unchanged
and still the live A2b frontier. CB46 measured it as EB7.6 required and did not correct it.

**368 / 369 / 370 / 374 / 398** are carried on their pre-existing owner surfaces, not reassigned. Ownership
controls hold: ordinals **404 / 408 PASS** with `sourceFaceCount=300; established=300; unavailable=0;
conflicting=0; conflictRowCount=0`.

---

## EC5 — the eleven RED identities, classified

| Ordinal(s) | Classification |
|---|---|
| **390, 393, 406, 407** | **Newly-activated oracle, not a regression** (EC2). The frontier census at `RegionCertification` has never been shown to work. Owner `M3-CP4c3-TB40-EXEC-CAND-02`, measured by CB47. |
| **366, 367** | Live A2b frontier — `RegionSourceFaceOwningFragmentMissing`, now with `regionOwningFragmentOrbit`. `M3-CP4c3-TB40-REV-CAND-02`. |
| 368, 369, 370, 374, 398 | Carried, prior owners, not reassigned. |

Recovered from TB40: **311, 314, 356, 357** (EC1). Preserved: **312, 315, 404, 408, 409 PASS**.

---

## EC6 — accounting: no new event

**The accepted prefix is 365/365, so no stable event is created.** The four protected identities are above the
accepted prefix, they were already inside the TB40 event's scope, and EC2 shows their assertion had never
executed — repricing them now would both double-count the TB40 regression and mis-describe it as a behaviour loss.

**Totals remain 47 events / 14 categories / 33 recurrences.** Produced-witness debt **5**. Semantic package count
**106**. CP4c-3 remains **OPEN**.

**Candidate dispositions.**

- `M3-CP4c3-TB40-EXEC-CAND-01` → **CLOSED / RUNTIME PROVED**. Accepted 311/314/356/357 recovered by the content
  anchor, with the transposition intact and correctly ignored.
- `M3-CP4c3-TB40-EXEC-CAND-02` → **ACTIVE / GATING / RE-SCOPED**. No longer "restore the frontier census" but
  **"establish whether the frontier census has a non-empty subject at the certification stage at all"** (EC2, EC3).
- `M3-CP4c3-TB40-REV-CAND-01` (orbit label not independently checkable) → **CLOSED**. The content anchor makes the
  face identifiable to an independent consumer; that was the repair EB7.1 preferred.
- `M3-CP4c3-TB40-REV-CAND-02` (`RegionSourceFaceOwningFragmentMissing`) → **ACTIVE / GATING**, unchanged.
- **`M3-CP4c3-TB41-REV-CAND-01`** — new, **ACTIVE**: is a non-empty frontier component census even *legitimate* at
  `RegionCertification` once source-face ownership is total? The source comment at `:1338` says the partition is
  now only a consistency guard.
- **`M3-CP4c3-TB41-REV-CAND-02`** — new, **ACTIVE / HARDENING**: ordinal 315 tampers only `actualEmbeddedFace.orbit`;
  with a content anchor present, an anchor tamper is the stronger negative.

---

## EC7 — exact successor: `M3-CP4c-3-CB47`

**Code + Build**, runtime-free, GMP/GMPXX linked, `runtimeExecution=false`. **Measure the subject before changing
the census again.**

- **EC7.1 — publish the partition's size before anything else.** On every frontier annotation, publish
  `unlabeledFaceCount`, `frontierPartitionComponentCount`, and `ownerConsistencyRowCount`. **This is the number
  three turns of census repair have never established.**
- **EC7.2 — publish which locator resolved.** For each of the three locators in `region_frontier_components`,
  publish whether it produced a candidate component and whether that component survived the guard: an explicit
  `uncutFaceComponent / sourceFace / regionSweep / singleComponentFallback` outcome per failure. A census that
  cannot say *why* it is empty is not a diagnostic.
- **EC7.3 — publish the failing face's domain membership.** For `RegionSourceFaceOwningFragmentMissing`, publish
  whether `failure.sourceFace` is in `frontier.partition.componentByFace`, and how many of the failing region's
  source faces are. This decides EC3's two candidates directly.
- **EC7.4 — do not change the oracle, the partition, or the census contract.** CB47 is **measurement only**. In
  particular, do not weaken `expect_later_region_frontier_evidence`, do not widen `unlabeledFaces`, and do not make
  the four identities pass by returning early again — that would re-hide the oracle EC2 just exposed.
- **EC7.5 — do not touch the binding.** `region_orbit`, the orbit-keyed lookup, `canonical_cycle_anchor`, the
  derived-not-stored rule, and ordinals 312/315/409 stay exactly as they are.
- **EC7.6 — protected surface.** Accepted **1–365 must remain 365/365**; ordinals 311/314/356/357 must stay PASS;
  selector **409** byte-frozen; no work on 366/367/368/369/370/374/398; no change to region construction,
  ownership, `fragmentCorners`, cut selection or A2a′ cellularity semantics.
- **EC7.7 — `M3-CP4c-3-TB42` re-executes**; the decision turn is pre-named **`M3-CP4c-3-DEFN-R8`** and owns
  `M3-CP4c3-TB41-REV-CAND-01`.

**Falsification, stated before the build.**

- **Accepted prefix must remain 365/365 and 311/314/356/357 must stay PASS.** Any accepted RED halts the turn.
- **CB47 adds diagnostics only, so any change in the RED set other than new evidence fields is a defect in the
  turn** — 390/393/406/407 are expected to remain RED, and a turn that makes them pass has weakened the oracle.
- If `frontierPartitionComponentCount == 0`, EC3 candidate 1 is confirmed: **the census has no subject once
  ownership is total**, and `DEFN-R8` must decide whether the oracle is legitimate rather than whether the
  publication is broken.
- If it is non-zero and no locator resolves, EC3 candidate 2 is confirmed and the fix is a domain question — the
  partition excludes labelled faces by construction.
- If it is non-zero and a locator *does* resolve but the guard rejects it, the guard analysis in EC3 is wrong and
  must be re-derived.

**Prohibited:** weakening `expect_later_region_frontier_evidence` or restoring an early return that re-hides it;
changing the binding, `region_orbit`, the orbit-keyed lookup or the content anchor; widening `unlabeledFaces` or
altering the frontier partition's domain; correcting `RegionSourceFaceOwningFragmentMissing`; weakening ordinals
312/315/409/398; touching 368/369/370/374; any accepted-identity or selector byte change; any Directional runtime
in CB47.

**Exact next turn: `M3-CP4c-3-CB47` — Code + Build, runtime-free, GMP/GMPXX linked, under EC7.1–EC7.7.**
