# M3-CP4c-3-TB40 — Independent Review Record

**Turn:** `M3-CP4c-3-TB40-REV` — independent review (absorbs REVIEW + PLAN).
**Status:** STATIC / EVIDENCE-ONLY / NO RUNTIME / NO COMPILE / **STABLE — ONE NEW EVENT**.
**Measures:** **EB0–EB7**.
**Adjudicated evidence:** `Architecture_M3_CP4c3_TB40_EXEC_Report.md`, immutable package105 `10057456162` /
source `0f09439893182235c382492583b82aa35f25045c`, selector409 run `34246144235`.

---

## EB0 — TB40 is mechanically valid, semantically RED, and is **NOT** promoted

409/409 identities executed once, zero selection mismatch, zero timeout, `runtime_started/completed=true`,
`orchestration_failure=false`, every mutation/build/benchmark flag false, package/source/execution-view censuses
identical pre/post, selector409 byte-frozen at `eea6d8c2…`.

**Result: 394 PASS / 15 RED, accepted 361/365**, RED
`[311,314,356,357,366,367,368,369,370,374,390,393,398,406,407]`.

**`M3-CP4c-3-TB39` remains the current valid semantic runtime authority.** Package 105 is a build fact only.

---

## EB1 — the census confirms the binding; it does not refute it

The four census rows on ordinals 356/357 are the decisive evidence, and read correctly they are a **permutation**,
not a mismatch:

```text
region 0: derivedOrbit=0  certificateOrbit=1  upstreamMatchCount=1
region 1: derivedOrbit=1  certificateOrbit=0  upstreamMatchCount=1
region 2: derivedOrbit=2  certificateOrbit=2  upstreamMatchCount=1
region 3: derivedOrbit=3  certificateOrbit=3  upstreamMatchCount=1
```

Everything the binding contract actually asserts **holds**:

- **4 regions, 4 face certificates**, and `ASSERT_EQ(plan.regions().size(), cutCertificate.faces.size())` passed;
- **`upstreamMatchCount == 1` on every row** — each region resolves to exactly one upstream face;
- **the map is injective** — `consumedUpstreamOrbits.insert(...)` succeeded on all four;
- **boundary-arc counts match** on every row;
- **`discTopologyEstablished=true` and `fieldRegularity=true`** on every row;
- the complex row published its inputs once, as Part XI-A §A.3 required, and the census is **non-empty and
  non-uniform** — the R7.7 obligation is discharged.

**Only the orbit *label* disagrees, and only on the two rows that swap.** `DEFN-R7.1`'s substance — one region, one
non-exterior actual-embedded face, certified disc — is **runtime confirmed**.

---

## EB2 — the defect: four accepted oracles were re-aimed at a representation-dependent label

`derivedOrbit` and `certificateOrbit` are **indices into two different enumerations of the same partition**.

- **Production** numbers orbits by **dart index**: `EmbeddedGraphTopology.cpp:1742`,
  `for (std::size_t start = 0U; start < dartCount; ++start)`, assigning the next ordinal to each first-unvisited
  dart. Both A2a′ and A2b inherit this numbering from the shared builder, which is why
  `certificateOrbit == owningOrbit` always.
- **The test oracle** numbers orbits by **sorted-incidence order**: `independent_plan_face_orbits` builds
  `std::set<Incidence> all` (`tests/FieldAlignedCurveNetworkTests.cpp:1871`) and iterates
  `for (const auto start : all)` (`:1880`), assigning ordinals in `(NetworkArcId, Orientation)` order.

These two orders are not the same, and the census shows exactly where they differ: orbits 0 and 1 transpose. The
product is **self-consistent**; the oracle is comparing the production ordinal against a **third, foreign label**
of its own construction.

CB45's own binding lookup is correct and matches the frozen contract — it scans for
`faceCertificate.orbit == owningOrbit`, requires exactly one match, and checks arc count and disc establishment.
The error is entirely in the re-aimed assertions:

| Ordinal | Assertion | Why it is false |
|---|---|---|
| **311** | `EXPECT_EQ(orbitIndex, certificate->actualEmbeddedFace.orbit)` (`:3254`) | `orbitIndex` is the oracle's enumeration index |
| **314** | `actualEmbeddedFace.orbit != *matched` inside the independent proof | same foreign label, via `IndependentDiscProofClause::PublishedCertificate` |
| **356/357** | `EXPECT_EQ(derivedOrbit, certificate->actualEmbeddedFace.orbit)` | same |

> **This is `RP-05 / REPRESENTATION_DEPENDENT_IDENTITY`, and the project already carries the lesson: *never match
> two partitions by index.*** It was recorded from ordinal 390's `censusCorrespondence` and is restated in
> `ORIENTATION.md` §8. CB45 reproduced it while implementing a contract whose whole purpose was to stop A2b
> re-deriving what A2a′ already owns.

**Note the arc-count check did not catch it.** `EXPECT_EQ(upstream->boundaryArcCount, …)` passed on the swapped
rows, which means regions 0 and 1 have equal boundary-arc counts. A check that is insensitive to the very
permutation under test is not a control.

---

## EB3 — the deeper finding: the orbit label is not independently checkable

The oracle cannot be repaired by "look up the right index", because **nothing in
`SurfaceCutGraphFaceCertificate` identifies which face it describes in content terms.** Its four fields are
`orbit`, `boundaryWalkCount`, `boundaryArcCount`, `discTopologyEstablished`
(`include/directional/geometry/SurfaceCutGraph.h:53–63`) — an ordinal that is meaningful only inside the
producer's own enumeration, a constant, a length, and (per Part XI-A §A.1) a complex-level bit.

> **An independent consumer can verify that the binding is a bijection onto certified disc faces with matching arc
> counts. It cannot verify the orbit label, because the producer publishes no content by which that label could be
> confirmed.**

This is the second way in which the bound certificate carries less evidence than its name suggests, after
Part XI-A §A.1 and §A.2. It is **not** a defect in the binding — production derives the orbit by exact boundary
equality, which is content-anchored — but it bounds what any oracle may assert, and the successor must choose
deliberately between two repairs (EB7.1).

---

## EB4 — what else moved

**366/367 advanced, exactly as Part XI §10 prediction 4 required.** They no longer stop at
`RegionEulerCharacteristicNotOne` or `RegionInteriorDisconnected`; both retired proxies are genuinely off the gate.
They now stop at **`RegionSourceFaceOwningFragmentMissing`** during `RegionCertification`. Under the frozen
falsifier this is **a new frontier, not a regression** — but it is now the live A2b frontier and needs an owner.

**390/393/406/407 regress on `regionFrontierComponentCount == 0` for the second consecutive turn.** This is the
same **DEFN-R4 pattern**: frontier evidence is annotated only on particular failure codes, so retiring those codes
silences it. TB38 showed it; TB40 shows it again, now permanently, because the codes are retired by design rather
than bypassed. **It is no longer a side-effect of a broken turn — it is an open defect with no owner**, and it
will break on every future stage change until the annotation is decoupled.

---

## EB5 — the fifteen RED identities, classified

| Ordinal(s) | Classification |
|---|---|
| **311, 314, 356, 357** | **ACCEPTED-GREEN LOSS — the stable event.** Oracles re-aimed at a representation-dependent orbit label (EB2). The binding they test is correct. |
| **390, 393, 406, 407** | **Protected-green loss.** `regionFrontierComponentCount == 0`; DEFN-R4 pattern, second consecutive turn, now permanent (EB4). |
| **366, 367** | **Frontier, advanced.** Off both retired proxies, now `RegionSourceFaceOwningFragmentMissing` at `RegionCertification`. New frontier, not a regression. |
| 368, 369, 370, 374, 398 | Carried, prior owners, not reassigned. |

Preserved: **312 and 409 PASS** — the copy/mutation falsifiers still reject, so no sticky construction-time binding
was introduced. **315 PASS**, and it tampers `actualEmbeddedFace.orbit`, a field that **varies** — Part XI-A §A.3's
tamper-target amendment was honoured. **404/408 PASS**; ownership `300 / 0 / 0`; retired legacy codes absent.

---

## EB6 — accounting: one new stable event

Accepted ordinals **311, 314, 356, 357** were PASS at TB39 and are RED at TB40.

- **Events 46 → 47.**
- **Category: `RP-05 / REPRESENTATION_DEPENDENT_IDENTITY`** — existing, so **categories remain 14**.
- **Recurrences 32 → 33.**

**Totals: 47 events / 14 categories / 33 recurrences.** Produced-witness debt remains **5**. Package count **105**
(build fact only). Accepted authority remains **TB39 at 365/365**. CP4c-3 remains **OPEN**.

**Candidate dispositions.**

- `M3-CP4c3-TB40-EXEC-CAND-01` → **OWNED / STABLE**. Root cause is the re-aimed oracles, **not** the binding.
- `M3-CP4c3-TB40-EXEC-CAND-02` → **OWNED / NON-STABLE / PROMOTED TO GATING**. The frontier-annotation coupling now
  has an owner instead of being a side-effect.
- `M3-CP4c3-TB37-REV-CAND-01` → **CLOSED**. The counted-complex question is resolved by the binding, and the
  binding is runtime confirmed (EB1).
- **`M3-CP4c3-TB40-REV-CAND-01`** — new, **ACTIVE / ARCHITECTURAL**: a face certificate's orbit ordinal is not
  independently checkable (EB3).
- **`M3-CP4c3-TB40-REV-CAND-02`** — new, **ACTIVE / GATING**: `RegionSourceFaceOwningFragmentMissing` is the live
  A2b frontier at 366/367.

---

## EB7 — exact successor: `M3-CP4c-3-CB46`

**Code + Build**, runtime-free, GMP/GMPXX linked, `runtimeExecution=false`. **Restore the accepted prefix; do not
touch the binding.**

- **EB7.1 — re-aim the four oracles at content, not at an index.** The product is correct; the assertions are not.
  Choose **one** repair and state which:
  - **(a) narrow the assertion** — drop the orbit-label equality and assert what an independent consumer can
    actually establish: a **bijection** from published regions onto `cutCertificate.faces`, each with
    `upstreamMatchCount == 1`, matching `boundaryArcCount`, and `proves_disc_topology()`; **or**
  - **(b) make the label checkable** — publish one content-derived field on `SurfaceCutGraphFaceCertificate` (for
    example the canonical first oriented arc of its boundary, or a boundary digest) so an independent oracle can
    confirm *which* face it holds. This adds evidence; it does **not** change cut selection or cellularity
    semantics, so it is inside Part XI §R7.8's boundary — but it changes a published certificate and its digest,
    so the report must say so explicitly.
  **(b) is preferred**, because (a) permanently gives up the ability to detect a genuinely mis-bound face; but
  either is admissible if the report justifies the choice and the census still discriminates.
- **EB7.2 — decouple frontier annotation from failure code.** `regionFrontierComponentCount` must be published
  whenever the frontier evidence exists, not only on the retired codes' paths, so 390/393/406/407 return to PASS.
  This is the DEFN-R4 rule finally applied to its last site.
- **EB7.3 — do not touch the binding.** `region_orbit`, the `faces` lookup by `orbit`, the derived-not-stored rule,
  and ordinals 312/409/315 stay exactly as they are. **The binding is confirmed** (EB1); changing it now would
  discard the one thing TB40 proved.
- **EB7.4 — the arc-count control must be able to fail.** Regions 0 and 1 have equal `boundaryArcCount`, so that
  check was blind to the permutation under test. Whatever repair EB7.1 chooses, the census must be able to
  **disagree with itself** on the field being tested — the generalized non-vacuity rule from Part XI-A §A.3.
- **EB7.5 — protected surface.** Accepted **1–365 must return to 365/365**; **390/393/406/407 to PASS**; ordinals
  **312/409/315** byte-identical in intent and PASS; selector **409** byte-frozen; no work on 368/369/370/374/398;
  no change to region construction, ownership, `fragmentCorners`, cut selection or A2a′ cellularity semantics.
- **EB7.6 — `RegionSourceFaceOwningFragmentMissing` is measured, not corrected.** Publish, for the failing region,
  the source face and the orbit whose owning fragment is missing, plus the ownership census for that face.
  **CB46 does not correct it** — it is `TB40-REV-CAND-02` and needs its own turn.
- **EB7.7 — `M3-CP4c-3-TB41` re-executes** selector 409, one identity per fresh process, accepted prefix first.

**Falsification, stated before the build.**

- **Accepted prefix must return to 365/365 and 390/393/406/407 to PASS.** Anything less halts the turn.
- **312, 409 and 315 must stay PASS.** If 315 stops failing on a tampered `actualEmbeddedFace.orbit`, EB7.1 has
  weakened the binding rather than the oracle.
- If 356/357's census still shows `derivedOrbit != certificateOrbit` under repair (a), the assertion was narrowed
  but the census was not — the two must agree on what is being claimed.
- If 366/367 move off `RegionSourceFaceOwningFragmentMissing`, CB46 exceeded EB7.6 and changed behaviour it was
  only authorized to measure.
- If any repair requires touching `region_orbit` or the `faces` lookup, EB7.3 is violated and the turn halts.

**Prohibited:** changing the binding, `region_orbit`, or the orbit-keyed lookup; reintroducing a source-support
Euler or connectivity proxy as a topology gate; correcting `RegionSourceFaceOwningFragmentMissing`; weakening
ordinals 312/409/315/398; touching 368/369/370/374; any accepted-identity removal or selector byte change; any
Directional runtime in CB46.

**Exact next turn: `M3-CP4c-3-CB46` — Code + Build, runtime-free, GMP/GMPXX linked, under EB7.1–EB7.7.**
