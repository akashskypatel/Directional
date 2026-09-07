# M3-CP4c-3-TB36 — Independent Review Record

**Turn:** `M3-CP4c-3-TB36-REV` — independent review (absorbs REVIEW + PLAN).
**Status:** STATIC / EVIDENCE-ONLY / NO RUNTIME / NO COMPILE / NON-STABLE.
**Measures:** **CY0–CY6**.
**Adjudicated evidence:** `Architecture_M3_CP4c3_TB36_EXEC_Report.md`, immutable package101
`10029250324` / source `14aa1368523580444929bc65cab0b65449240ec2`, selector409 run `34153857590`.
**Static-authority gate:** `review_check.py authority 14aa1368523580444929bc65cab0b65449240ec2` — ALL CHECKS
PASSED (source is an ancestor of HEAD, no code drift source..HEAD), so static reading of the working tree is valid
evidence about the executed package.

---

## CY0 — TB36 is mechanically valid and is promoted to current semantic runtime authority

Every mechanical precondition holds on the artifact-only boundary:

- `script_exit=0`; `runtime_started=true`, `runtime_completed=true`, `preflight_completed=true`;
- `execution_view_verified=true`, `orchestration_failure=false`, `selection_integrity=true`, `timeout_count=0`;
- `benchmark_execution=false`; `configure/compile/relink/generated_discovery/package_repair/mode_repair` all false;
- `source_test_fixture_selector_mutation=false`;
- `ledger.tsv`, `identity-map.tsv`, `resource-summary.tsv` each **409 rows**, every row `selected=1`;
- package, source and execution-view censuses **identical before and after**;
- a **failure-detail digest table** is published (`02734fd9…`), so this ledger cannot collide semantically with a
  predecessor the way TB32=TB31 and TB33=TB30 did;
- `SHA256SUMS` 28/28 PASS and the six runtime executables retained mode `0755`.

Selector409 hashes to `eea6d8c2bbc8e9247deb4bfbbe6763042c76002d1894dd62e35f80262403b53e`, identical to the value
`review_check.py boundary` verifies against HEAD, and CB41's static audit records ordinal 312's and ordinal 409's
test blocks as **byte-identical before and after** (`94724bef…`, `ea574dab…`). **CX4 is discharged.**

**Result: 402 PASS / 7 RED, accepted 1–365 = 365/365, RED `[366,367,368,369,370,374,398]`.** Ordinals 312, 390,
393, 404, 406, 407, 408 and 409 PASS; ownership at ordinal 385 is **300 / 0 / 0**; both retired codes stayed
silent.

**`M3-CP4c-3-TB36` is promoted to current valid semantic runtime authority; package count advances to 101.** TB35
is superseded.

**Two procedural misses are recorded and neither invalidates the evidence.** A start-of-turn `READ_MODE` ordering
miss was caught before substantive analysis and corrected by taking snapshot `34153210096`; and the external
`TB-EXEC.md` reference could not be resolved after a bounded retry, with the local plan and project policies
remaining the execution authority. Both are control-plane facts about how the turn was conducted, not about what
the packaged binaries did.

---

## CY1 — DEFN-R5.2 and R5.3 are confirmed at runtime, including the negative Part IX-A predicted

CX8's falsifier was explicit: *a stop at `ClosedBeforeEnd` falsifies DEFN-R5.2/R5.3.* Ordinals 366/367 **advanced
past it**, publishing `regionBoundaryProvenance=FaceWalkOrbit`, so the derived relation resolved a real plan
region to its owning orbit and the scoped reason stopped rejecting it. **DEFN-R5.2 and DEFN-R5.3 are runtime
confirmed.**

The complementary negative also held. Ordinals **312 and 409 remained PASS**, and both construct their boundary by
taking `plan.validation_candidate()` — a **copy of a real plan region** — and then mutating it
(`tests/FieldAlignedCurveNetworkTests.cpp:3247–3253`, `:3276–3279`). Under the derived relation the mutated
boundary matches no authoritative orbit, resolves to `Unguaranteed`, and is still rejected. **This is the exact
outcome Part IX-A §A.1 predicted, and it is the runtime disproof of the construction-time provenance rule** that
the competing DEFN-R5 draft proposed: a stored flag would have survived that copy and suppressed both rejections.
`LESSONS.md` 148 is now runtime-evidenced rather than argued.

`M3-CP4c3-TB35-REV-CAND-01` is therefore **CLOSED / RUNTIME PROVED**.

---

## CY2 — the frozen CX5 measurement cannot decide the question it was frozen to decide

This is the finding of the turn.

DEFN-R5.5 froze a measurement to test the premise stated in the source comment at
`GlobalTopologyPlan.cpp:2099–2100` — *"the validated single boundary walk and no-pinch condition give
`V_boundary == E_boundary`, so the boundary terms cancel from chi."* **The measurement CB41 implemented is taken
over a different object in a different unit, so it cannot bear on that premise at all.**

**The counted complex is a sub-mesh of whole source triangles.** `certificate.faceCount = region.sourceFaces.size()`
(`:1826`), and `owned` assigns each source face to exactly one region because `fragmentOrbits[face]` is rejected
unless `certifiedFaceOrbits.size() == 1` (`:1400–1433`) — so the 300 source faces are **partitioned**, and this
region holds 250 of them. `certificate.edgeCount` counts **source edges** (`authority::SourceEdgeTopologyKey`,
`:1847–1860`) and `interiorVertices` holds **source vertices** (`authority::SourceVertexId`, `:2048–2094`).

**The CX5 census is taken over the network graph.** `distinctBoundaryArcs` is
`std::set<authority::NetworkArcId>` and `distinctBoundaryNodes` is `std::set<authority::NetworkNodeId>`
(`:2122–2123`, filled at `:2132` and `:2136`). A network arc is a mandatory edge, a cut edge, **or a trace segment** (`:1905`, `:1934`, `:1951`),
and a trace segment is a chord through face interiors — **not a source edge at all**.

So `regionBoundaryDistinctArcCount=22` and `regionBoundaryDistinctNodeCount=22` are cardinalities of the network
boundary walk, while the premise concerns the **sub-mesh boundary**: the source edges with exactly one incident
face in the region, and their source vertices. These are two different curves, not two encodings of one curve.
**"22 = 22" is therefore not evidence that the boundary terms cancel**, and DEFN-R5.5's question is still open
after the turn that was frozen to close it.

This is a recurrence of the pattern already recorded as **`RP-01 / AUTHORITY_DOMAIN_CONFLATION`** — the same
network-versus-source domain slip that cost the accepted prefix at CB39. It carries no stable event here because
**no accepted green was lost**, but it is the third turn in this checkpoint in which a measurement was computed on
a neighbouring object rather than the failing one.

### CY2.1 — two of the eight published fields are one number

`regionBoundaryNodeOccurrenceCount` is assigned `region.boundary.size()` (`:2142`) — the **same expression** as
`regionBoundaryArcOccurrenceCount` (`:2120`). Each oriented entry contributes exactly one start node, so the
equality is structural. The census publishes eight fields carrying at most **six** independent values, and the
apparent identity `40 = 40` must not be read as a measured confirmation of anything.

### CY2.2 — 366 and 367 are one datum, not two

Both failures share failure-detail SHA-256 `82548091bd6aeeb2f7d61af73326e7e33ec7d88b7774de9ea5629959981883a6`
and both report `regionBoundaryOrbit=0`. They are two witnesses over the **same region of the same fixture**. The
census is one observation; nothing about it is corroborated by the second identity.

---

## CY3 — what the numbers do establish, and the identity that decides the frontier

The census is not useless. Two things follow from it, and one of them reduces the whole open question to a single
integer identity.

### CY3.1 — the network boundary's shape is now measured

40 arc occurrences over 22 distinct arcs, and 22 distinct nodes. For any graph, `V − E = components − independent
cycles`, so a connected boundary subgraph with 22 nodes and 22 arcs has **exactly one independent cycle**. With 18
arcs traversed twice and 4 traversed once (`18·2 + 4·1 = 40`, and `22 − 4 = 18` matches
`regionBoundaryRepeatedNodeOccurrenceCount=18`), the walk is a **4-arc cycle carrying an 18-arc tree** of
bridges and slits. `regionBoundaryStartRevisitBeforeEndCount=1` is consistent.

This is the first direct measurement of a plan region's boundary shape, and it confirms Part IX's structural
claim — a face-walk orbit over a complex with `terminalSlits=10` revisits nodes because bridges are traversed once
per dart. **DEFN-R5.1 is empirically supported.**

### CY3.2 — the open question reduces to one identity over two unpublished integers

Every source face is a triangle — `SourceFaceRecord` holds `std::array<…,3> vertices` and `std::array<…,3> edges`
(`src/geometry/EmbeddedGraphTopology.h:25–32`) — so the region's 250 faces contribute exactly **750 face-edge
incidences**. Let

- `E_int = 353` — the published count: edges with both incident faces in the region and **not** a barrier;
- `B_int` — barrier edges (mandatory ∪ cut) with **both** incident faces in the region, skipped at `:1848–1850`;
- `X` — sub-mesh vertices excluded from `interiorVertices`: mesh-boundary vertices, members of
  `boundaryVertices`, and those failing the `allOwned` test.

Counting incidences, edges with exactly one incident face in the region number `44 − 2·B_int`, so
`E_total − E_int = 44 − B_int`, and

> **χ_true = X + B_int − 47.**

The published `χ = V_int − E_int + F = 100 − 353 + 250 = −3` follows from `X + B_int = 44`. Therefore:

- **the reduced formula's premise holds ⟺ `X + B_int = 44`**, in which case χ = −3 is correct and **the region is
  not a disc**;
- **the region is a disc (χ = 1) ⟺ `X + B_int = 48`.**

**These are mutually exclusive.** One of the two claims the certificate currently makes — that the boundary terms
cancel, and that regions are discs — is false, and a **single integer** decides which. Both `B_int` and `X` are
computable inside loops that already exist and neither is published.

### CY3.3 — the likely defect, named but not decided

`B_int` is the suspicious term. A barrier edge with both faces inside the region is **interior to the sub-mesh**,
yet `:1848–1850` excludes it from `E_int` and `:1919`/`:1925`/`:1947` insert its endpoints into `boundaryVertices`, which
`:2048–2051` then excludes from `V_int`. A terminal slit is precisely such an edge — a barrier that dangles into a
region rather than separating two — and this fixture publishes **ten** of them, consistent with the 18 doubly
traversed boundary arcs measured at CY3.1. **This review does not conclude that this is the defect**; it names it
as the first place the successor's measurement will discriminate.

---

## CY4 — the seven RED identities, classified

| Ordinal | Classification | Owner |
|---:|---|---|
| 366 | **Frontier.** Advanced past `ClosedBeforeEnd` to `RegionEulerCharacteristicNotOne` with the full CX5 census. The provenance correction is proved; the Euler census is undecided and its measurement is in the wrong domain (CY2). | `M3-CP4c3-TB34-REV-CAND-03`, re-scoped by **CY6** |
| 367 | **Frontier, same datum as 366** — byte-identical failure detail, same region, same orbit (CY2.2). | as above |
| 368 | Carried. Prescribed sphere stops at `RotationSystemInconsistent → TraceEventPositionInvalid`, trace 2 / event 30, `NoCarrierMatch / SourceEdgeUnavailable`. Unchanged. | AL4 / `M3-CP4c2-TB-X2-CAND-04` |
| 369 | Carried. Trace-crossed edge still reports `saturationUsed=true` where ordinary proposal is required. Unchanged. | prior saturation owner |
| 370 | Carried. Empty closed-surface network returns the wrong typed code and no source-face locus. Unchanged. | prior owner |
| 374 | Carried. Folded-cone AY5 witness stops because `atlasBuild` is false; corrective is test-only. Selector 374 stays byte-frozen. | prior deferred owner |
| 398 | Carried. Owner-map fixture cannot obtain the prescribed-sphere cut graph; publishes the unchanged mechanical map `sourceFaceCount=300; ownerMapCount=300; provesCellularity=true`, torus `144/144`. | `M3-CP4c2-TB-X2-CAND-04` |

No new RED ordinal, no accepted-prefix loss, no re-owning of a carried failure.

---

## CY5 — accounting

TB36 lost no accepted green, so **no stable event is created**: a stable event requires accepted-green loss, and
the accepted prefix stayed at **365/365**. CY2's domain conflation is recorded as a **pattern recurrence without
an event**, which is the correct disposition and must not be inflated into one.

**Totals remain 45 events / 14 categories / 31 recurrences.** Produced-witness debt remains **5**. Semantic M3
package count advances to **101**. CP4c-3 remains **OPEN**. Accepted authority remains **365/365**.

**Candidate dispositions.**

- `M3-CP4c3-TB35-REV-CAND-01` — **CLOSED / RUNTIME PROVED** (CY1).
- `M3-CP4c3-TB34-REV-CAND-03` — **ACTIVE / RE-SCOPED**. Its Euler branch is no longer "measure the boundary
  multiplicity"; the multiplicity was measured in the wrong domain. It is now owned by CY6's identity.
- **`M3-CP4c3-TB36-REV-CAND-01`** — new, **ACTIVE / GATING**: the region certificate asserts both that the boundary
  terms cancel and that the region is a disc, and CY3.2 shows those cannot both be true.

---

## CY6 — exact successor: `M3-CP4c-3-CB42`

**Code + Build**, runtime-free, GMP/GMPXX linked, `runtimeExecution=false`. **Measurement only — no correction.**

- **CY6.1 — publish the two integers that decide it.** On the `RegionEulerCharacteristicNotOne` path, publish
  `regionInteriorBarrierEdgeCount` (`B_int`: barrier edges with both incident faces in the region, counted at the
  existing `:1848–1850` skip) and `regionExcludedVertexCount` (`X`), split into its three disjoint causes —
  mesh-boundary, `boundaryVertices` membership, and `allOwned` failure — so the cause is attributable, not just the
  total.
- **CY6.2 — publish the sub-mesh boundary in its own domain.** `regionSubmeshBoundaryEdgeCount` (source edges with
  exactly one incident face in the region) and `regionSubmeshBoundaryVertexCount` (their distinct source
  vertices). These, **not** the network arc/node counts, are the `V_boundary` and `E_boundary` the comment at
  `:2099–2100` refers to.
- **CY6.3 — publish the identity, never a verdict.** Emit `V_total`, `E_total` and
  `chiFull = V_total − E_total + F` alongside the existing reduced value. **Do not change the reduced formula, do
  not force χ to 1, and do not accept or reject any region on the new numbers.** DEFN-R5.5's measurement-only
  disposition still governs.
- **CY6.4 — retire the two redundant fields or mark them derived.** `regionBoundaryNodeOccurrenceCount` is
  `regionBoundaryArcOccurrenceCount` by construction (CY2.1). Keep the network census — it measures the boundary's
  shape and CY3.1 used it — but the report must state that it is a **network-domain** measurement and does not bear
  on the cancellation premise.
- **CY6.5 — protected surface unchanged.** Ordinals **312** and **409** keep byte-identical test blocks; selector
  **409** stays byte-frozen; accepted **1–365** untouched; no work on 368/369/370/374/398; no source-face
  ownership, partition-unification, retired-guard, sphere, saturation, folded-cone or finalize/contact change.
  Before implementing, **grep the corpus for `RegionEulerCharacteristicNotOne`** and name every accepted identity
  that asserts it.
- **CY6.6 — `M3-CP4c-3-TB37` re-executes** selector 409, one identity per fresh process, accepted prefix first.

**Falsification, stated before the build.**

- **Accepted prefix 365/365 and ordinals 312/409 PASS are stop conditions.** Any accepted RED halts the turn.
  CB42 adds diagnostics only, so any behaviour change at all is a defect in the turn.
- If `X + B_int = 44`, the cancellation premise **holds**, χ = −3 is correct, and **the frontier moves to region
  construction** — the plan is building a region that is not a disc, and the certificate is right to reject it.
- If `X + B_int = 48`, the premise is **false by exactly 4**, the reduced formula is wrong for this boundary, and
  the frontier is the certificate's arithmetic.
- If it is neither, one of the three exclusion causes in CY6.1 is miscounting, and the split tells which.
- If `regionSubmeshBoundaryVertexCount − regionSubmeshBoundaryEdgeCount ≠ 0` while `B_int = 0`, the premise fails
  for a reason unrelated to barriers and CY3.3's suspicion is wrong.

**Prohibited:** correcting the Euler formula, region construction or disc acceptance in CB42; deciding the frontier
from the network census; publishing a predicted χ for the mechanical fixture; any accepted-identity or selector
byte change; any Directional runtime in CB42.

**Exact next turn: `M3-CP4c-3-CB42` — Code + Build, runtime-free, GMP/GMPXX linked, under CY6.1–CY6.6.**
