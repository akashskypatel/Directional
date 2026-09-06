# M3-CP4c-3-TB33 Independent Review Record

## Status

**COMPLETE / STATIC / NO RUNTIME / NO COMPILE / NON-STABLE / EVERY CT MEASURE DISCHARGED.**

`M3-CP4c-3-TB33-REV` is evidence-only review. It executed no Directional runtime, no compile, no package operation,
and mutated no product, test, fixture, benchmark, build or selector byte.

**TB33 is promoted to current valid semantic runtime authority**: selector **408**, **401 PASS / 7 RED**, accepted
**1–365 = 365/365**, RED `[366, 367, 368, 369, 370, 374, 398]`. All 408 rows selected exactly one test,
`timeout_count=0`, and the run is mechanically valid throughout.

**All five CT measures are discharged, each verified against retained evidence rather than a summary.** Ordinals
**390, 393, 406 and 407 returned to PASS**, so the RED set is now exactly **the frontier pair plus the four
independently owned carried surfaces** — the smallest and cleanest this checkpoint has been.

The frontier remains `RegionBoundaryNotSingleWalk` at **arc 3**, now published with a stage label and complete
frontier evidence. §3 diagnoses it from source, and §7 freezes a minimal correction with its falsifier.

`review_check.py authority 0d03edb07388c56b592a74e2e7fc5f3edde8cea4` — **ALL CHECKS PASSED**.

---

## 1. CU0 — every CT measure discharged, with its evidence

| Measure | Outcome |
|---|---|
| **CT3** stage-labelled evidence | **Discharged.** 366/367 publish `regionFrontierFailureStage=RegionCertification`, and their raw failure-detail bytes contain **no legacy `uncutFaceComponent*` fields**. The back-fill is gone. |
| **CT4** justified cleared-stage outcome | **Discharged.** **390/393/406/407 PASS.** Their detail files are the canonical `PASS` payload. |
| **CT5** failure-detail digest | **Discharged.** `failure-detail-digests.tsv` covers all 408 rows, table SHA-256 `2347c691…57cf479`. |
| **CT6** harness parameterised by turn identity | **Discharged.** The harness is now `tools/m3_cp4c3_artifact_only_harness.sh` — turn-agnostic — and `baseline-authority.txt` records exactly `M3-CP4c-3-TB33-EXEC run=34054234216 artifact=9994997588 source=0d03edb0… selector=408`. |
| **CT7** transcription obligation | **Discharged.** The report transcribes the verbatim retained failure text for **every** RED focused ordinal, with a per-ordinal detail SHA-256. |

**Both standing falsifiers held.** A complete search of all 408 raw logs finds **zero** `TraceArcDoesNotSeparateItsSides`
and **zero** `UncutFaceComponentOrbitSeedNotUnique` emissions, and 366/367 did **not** move to an earlier stage.
Certified ownership is retained at `sourceFaceCount=300; established=300; unavailable=0; conflicting=0`.

### 1.1 CT5 justified itself on the run that introduced it

**TB33's ledger SHA-256 is `974fed9db1958ee7eb07df77097544199deeb61d663b1d366a37b54d64feeab0` — byte-identical to
TB30's.** TB30 was also 401 PASS / 7 RED on the same RED ordinal set, so the pass/fail vector matches exactly while
the product, the package and the failure reasons are entirely different.

That is the **second** ledger-hash collision in three turns — TB32 collided with TB31, TB33 with TB30 — and it
lands on the very run that first published a failure-detail digest. `M3-CP4c3-TB32-REV-CAND-02` did not need
arguing; it needed one more run. **The `failure-detail-digests.tsv` table is now the digest that distinguishes
these runs, and the ledger hash must never again be quoted as a run's semantic identity.**

### 1.2 Ownership is unambiguous everywhere, not just on component 0

The retained fragment-owner evidence publishes **nine** components, all untruncated, and **every one has
`seedCount=1, seedState=Unique`**:

- component 0 — 189 faces, `[0]`; component 4 — 30 faces, `[2]`; seven singleton components on `[0]` or `[2]`.
- `fragmentOwnerOrbitCount=6`, `fragmentOwnerNonExteriorOrbitCount=6`, matching the certificate's `F=6`.

At TB19 this component had three conflicting seeds and 226 of 300 faces unowned. **There is no residual ownership
ambiguity anywhere in the plan's partition.**

---

## 2. CU1 — the four witnesses, and what their recovery proves

390, 393, 406 and 407 are green with **selector 408 byte-unchanged** and nothing they legitimately own relaxed.
That confirms the TB32-REV re-scoping: the defect was never that they named a failure code — CB37 had already
removed that — but that **their subject was a stage the plan no longer fails at**. Giving them two admissible
outcomes fixed it in one turn.

**`M3-CP4c3-TB31-REV-CAND-02` is CLOSED / runtime-proved**, on its own falsification condition: they did not still
fail with stage-labelled evidence published.

It is worth recording what the last three turns cost and what ended it. Six identities redded across two forward
steps because they were pinned to the failure the product used to make; two turns were spent removing the code
name, which did not help; the fix that worked was **making "this stage was cleared" a first-class, justified
outcome**. `LESSONS.md` 142 was written from the failure; TB33 is its confirmation.

---

## 3. CU2 — the frontier, diagnosed from source

366/367 publish:

```
RegionBoundaryNotSingleWalk; arc=3; regionFrontierFailureStage=RegionCertification;
embeddedGraphV=22; E=26; F=6; componentCount=1; sourceChi=2; eulerResidual=0;
regionFrontierComponentCount=6; regionFrontierComponentsTruncated=false
```

with every frontier component reporting `censusCorrespondence=Superset`,
`componentSubsetOfCensusComponent=true` against certifier census component 0.

`validate_single_boundary_walk` is:

```cpp
current = firstNodes.second;
for (index = 1; index < region.boundary.size(); ++index) {
  next = oriented_arc_nodes(...);
  if (current == start || next.first != current) { … RegionBoundaryNotSingleWalk, arc = boundary[index].arc; }
  current = next.second;
}
if (current != start) { … RegionBoundaryNotSingleWalk … }
```

`failure.arc = boundary[index].arc` is set only by the **in-loop** branch, so **arc 3 is the arc at which the loop
rejected**, and the rejection is one of two disjuncts.

### 3.1 The `current == start` disjunct rejects a legitimate configuration

The second disjunct, `next.first != current`, is the real chain check: it rejects a boundary whose arcs do not
connect end-to-start. The first disjunct, **`current == start`**, rejects a walk that **reaches the start node
while arcs remain** — that is, a walk that *passes through* its own start node.

A closed boundary walk may legitimately revisit a node. This fixture guarantees it: the retained evidence reports
**`terminalSlits=10`** across twelve traces, and a slit arc appears **twice** in a face's boundary walk, once per
dart — out along the slit and back. A boundary that traverses a slit necessarily returns to the slit's base node
mid-walk, and if that base node happens to be the walk's start, the guard fires on a perfectly good disc.

**The certificate independently contradicts the rejection.** The same failure publishes `F=6`, `componentCount=1`,
`sourceChi=2`, **`eulerResidual=0`** — the actual embedded complex is certified cellular with all six faces
established as discs. A plan region whose faces map into a certified disc face cannot be a non-disc, and the
frontier evidence shows every plan component is a **subset** of certifier census component 0 with explicit
correspondence.

This is the same family as the two guards already retired on this frontier: **a predicate that is correct on a
non-degenerate configuration and rejects the degenerate one that bridges and slits create.** Arc 15's equal dart
orbits, arcs 20/24's equal orbits, and now a boundary walk that revisits its start node.

### 3.2 Removing the disjunct loses nothing

Two genuinely disconnected boundary loops are still caught: after the first loop closes, the next arc starts at a
different node, so `next.first != current` fires. The only case the removed disjunct catches *and the chain check
does not* is two loops meeting **at the start node** — which is a walk pinched at a node, exactly the legitimate
configuration a slit produces.

The trailing `current != start` check still requires the whole boundary to close. **The minimal correction is to
delete the `current == start` disjunct and keep both remaining checks.**

I state this as a source-level derivation, not a measurement: the published `arc=3` does not by itself say which
disjunct fired. **CU5 requires the successor to publish which one**, and CU6's falsifier turns on it.

---

## 4. CU3 — classification of the 7 RED ordinals

| Ordinal | Classification |
|---|---|
| 366, 367 | **The frontier.** `RegionBoundaryNotSingleWalk` at arc 3, stage `RegionCertification`. Diagnosed at §3; corrected by **CU4**. |
| 398 | **Carried sphere surface** — `prescribed sphere: NotProductionReady/CellularityNotEstablished`, ordinal 368's surface. **Not an ownership gate.** Owner: `M3-CP4c2-TB-X2-CAND-04`. Untouched. |
| 368, 369, 370, 374 | **Unchanged carried surfaces** with separate owners — prescribed sphere, saturation, typed-error locus, folded cone. Untouched. |

**The RED set is now the frontier pair plus four independently owned carried surfaces, and nothing else.** Every
identity that was ever collateral to diagnostic scaffolding is green. Ordinals **404 and 408 remain PASS**, now
across four consecutive forward steps.

---

## 5. CU4 — stable accounting

**No stable event, category, or recurrence is added.** Totals remain **44 events / 14 categories / 30
recurrences**, produced-witness debt **5**, semantic M3 package count **98** (CB38).

1. accepted **1–365 = 365/365**, no accepted RED ordinal, **no accepted-green loss** — the fourth product change on
   this frontier and the boundary held again;
2. **390/393/406/407 recovered**; recovery is not an event;
3. 366/367 are the carried frontier, unchanged in stage from TB32;
4. 368/369/370/374/398 are already-counted carried surfaces.

---

## 6. CU5 — candidates

**Closing, runtime-proved.**

- `M3-CP4c3-TB31-REV-CAND-02` — the four pinned witnesses. **CLOSED**, §2.
- `M3-CP4c3-TB32-REV-CAND-01` — seed-stage fields back-filled onto later failures. **CLOSED.** The 366/367 detail
  bytes contain no legacy `uncutFaceComponent*` fields and carry an explicit stage label instead.
- `M3-CP4c3-TB32-REV-CAND-02` — the ledger digest. **CLOSED / and vindicated on the same run**, §1.1: TB33's
  ledger hash collided with TB30's, and the new failure-detail table is what separates them.
- `M3-CP4c3-TB32-REV-CAND-03` — harness relabelling. **CLOSED.** The harness is turn-agnostic and
  `baseline-authority.txt` records the executing run.

**Carried, unchanged.** `M3-CP4c3-TB26-REV-CAND-04` / `M3-CP4c3-DEFN-R3-CAND-01` (two partitions — the plan's is
now strictly finer, every component a subset of one census component, so the divergence is measured and benign),
`M3-CP4c3-TB30-REV-CAND-02`, `M3-CP4c3-TB27-REV-CAND-02`, `M3-CP4c3-TB22-REV-CAND-01`,
`M3-CP4c3-TB18-REV-CAND-01`, `M3-CP4c3-TB7-CAND-02`, `M3-CP4c3-DEFN-R2-CAND-01`, `M3-CP4c3-TB6-CAND-01`,
`M3-CP4c2-TB-X2-CAND-04` (also 398), `M3-CP4c2-TB-X2-R10-CAND-01`, `M3-CP4c2-TB-X2-R8-CAND-02`,
finalize/contact fall-through.

**New.**

- `M3-CP4c3-TB33-REV-CAND-01` — **NEW / ACTIVE / GATING / PRODUCT.** `validate_single_boundary_walk`'s
  `current == start` disjunct rejects a boundary walk that passes through its own start node — the configuration a
  terminal slit produces, and this fixture has ten of them. The certificate independently establishes all six faces
  as discs with residual 0. Owner: **CU4/CU5**.

---

## 7. CU4–CU6 — frozen successor: `M3-CP4c-3-CB39`

Code + Build, runtime-free, GMP/GMPXX linked, `runtimeExecution=false`. **One product change.** No topology,
barrier, ownership, or previously retired guard is touched.

### CU4 — the correction

In `validate_single_boundary_walk`, delete the **`current == start`** disjunct from the in-loop test, leaving

```cpp
if (next.first != current) { … RegionBoundaryNotSingleWalk … }
```

and the trailing `if (current != start)` check unchanged.

**Accepted-prefix safety by construction:** the only reachable behaviour change is a boundary whose walk revisits
its start node while arcs remain. Every boundary that closes correctly, and every boundary whose arcs fail to
chain, takes an identical path. Enumerate what differs and show the rest is unchanged.

### CU5 — publish which disjunct fired

`RegionBoundaryNotSingleWalk` must carry a typed reason distinguishing **`ArcChainBroken`** (`next.first != current`),
**`ClosedBeforeEnd`** (the deleted disjunct's condition, retained as *evidence* only), and **`WalkNotClosed`** (the
trailing check). This is publication, not a guard: the `ClosedBeforeEnd` condition may be **recorded** and must not
**reject**.

Without it, §3's derivation stays a derivation. With it, the next runtime says which branch this fixture was on.

### CU6 — the falsifiability witness

One new gating identity, appended as **409** with selector 408 as its exact 408-line prefix:

**`GlobalTopologyPlan.RegionBoundaryWithTwoDisjointLoopsIsStillRejected`** — on a constructed region whose boundary
is two node-disjoint closed loops, `RegionBoundaryNotSingleWalk` is still raised with reason `ArcChainBroken`.
This splits *can* from *does* per `LESSONS.md` 116 and proves the correction did not weaken the check into
uselessness. It asserts rejection of a constructed negative, never a value on the production fixture.

### Falsification, stated before the build

- If 366/367 still fail at `RegionBoundaryNotSingleWalk` **with reason `ArcChainBroken`**, §3.1 is wrong: the
  boundary genuinely fails to chain and the defect is upstream in region boundary assembly, not in this predicate.
- If they clear and the plan stops at a **further** stage, the correction is right and the frontier has advanced
  again.
- If ordinal 409 fails, the correction weakened the check and must be reverted.
- If either previously retired code reappears, or 366/367 move to an **earlier** stage, CB39 changed behaviour it
  was forbidden to touch.

### Prohibited in CB39

1. Any change to topology, barriers, ownership, the separating-arc rule, or any previously retired guard.
2. Weakening or re-scoping **ordinal 398** (prescribed sphere), or touching 368/369/370/374.
3. Relaxing anything ordinals 390/393/406/407/404/408 legitimately own — they are green and must stay green.
4. Changing any accepted identity 1–365, or any byte of selector 397–408. Selector 409 appends only.
5. Any new diagnostic contract on source-face ownership. It is closed, and every component now has a unique seed.
6. Executing any Directional runtime.

---

## 8. A note on the state of the checkpoint

For the first time since TB19 the RED ledger contains **no diagnostic scaffolding**: two frontier ordinals and four
carried surfaces with named, independent owners. Ownership is total and unambiguous across all nine plan
components. Both retired guards are absent from 408 logs. The evidence surface now carries stage labels, per-row
failure-detail digests, verbatim failure transcription, and a turn-agnostic harness.

Three of the last four corrections were single-predicate changes whose falsifiers were written before the build and
checked afterwards. The one that was not — DEFN-R4.5 — cost a turn, and its repair is what §2 records as closed.

## 9. Consolidation performed

Per `CLEAN_UP_POLICY.md` §"Document consolidation — every REVIEW turn". Durable facts were verified present in this
record, `Regression_Root_Cause_Tracker.md`, `ORIENTATION.md`, `M3_CP4c_Current_And_Forward.md` and `CHANGELOG.md`
before any fold. **Preserved in §§1–3 above:** the ownership census `300 / 0 / 0`, the nine-component unique-seed
publication, the absence of both retired codes from 408 logs, and the frontier's stage-labelled failure detail.

Folded: `Architecture_M3_CP4c3_TB32_EXEC_Report.md` (superseded runtime authority),
`Architecture_M3_CP4c3_TB32_Artifact_Only_Test_Benchmark_Plan.md` (consumed contract),
`Architecture_M3_CP4c3_TB32_Independent_Review_Record.md` (superseded review authority, CT0–CT7 — **all five CT
measures discharged**), `Architecture_M3_CP4c3_CB38_Code_Build_Report.md` (consumed build report).

Retained as current authority: `Architecture_M3_CP4c3_TB33_EXEC_Report.md` (**the valid semantic runtime
authority, and the first report to carry verbatim failure transcription for every RED focused ordinal**),
`Architecture_M3_CP4c3_TB33_Artifact_Only_Test_Benchmark_Plan.md`, this record,
`M3_CP4c_Current_And_Forward.md`, `M3_CP4c_Frozen_Definitions.md` (**Part VIII operative**),
`Required_Green_Selector_Manifest.md`, `M3_CP4c_Consolidated_Record.md`, and every
`Required_Green_Selector_*.txt`. **Never folded:** `tools/m3_cp4c3_artifact_only_harness.sh` is the instrument, not
a document.

## 10. Lessons added

`LESSONS.md` **143** — a walk may pass through its own start node; "reached the start" is not "closed the loop".

## 11. Exact successor

**`M3-CP4c-3-CB39`** under **CU4–CU6**, Code + Build, runtime-free. One predicate correction, a typed reason so the
next runtime says which branch fired, and a constructed negative proving the check still rejects two disjoint loops.
