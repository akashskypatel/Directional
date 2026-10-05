# `M6-CP1-TB12-CLOSE-REV` — Independent Review Record

**Type:** Review only; runtime-free.
**Date:** 2026-10-05.
**Reviewed candidate:** `11324028392 / 02149f1518fc6a753acf3235f7dcdc6fcdf59f24`.
**TB12 runtime:** `37266239234 / 111623615471`; result/log `11326949864 / 11328055226`.
**Disposition:** **REJECT FOR TEST-AUTHORITY RECOVERY**. The production C1 implementation is statically consistent with RA-25/CB12, but identity29 is a false rejection because its chosen fixture does not establish the selected-cross-sheet witness that the test assumes. Candidate remains unpromoted.

## 1. Independent evidence re-derivation

The Review used exact source snapshot `37271313511 / 11328074296` at source/event SHA `08f53f78fd1039f16c026322622516c626ccfe70`; snapshot manifest verifies **5386/5386** files. No Directional runtime was executed in Review.

TB12 evidence independently re-checks as:
- exact immutable candidate `11324028392 / 02149f1518fc6a753acf3235f7dcdc6fcdf59f24`;
- focused30 **29/30**, selector449 **449/449**, aggregate **478/479**;
- exactly **479** fresh exact-filter processes, exact-one selection, zero skips, benchmark 0;
- result self-manifest **979/979** and immutable postflight;
- sole RED focused ordinal29 `M6CP1.A7CrossSheetBindingRequiresConnectingIsolationTransition`; ordinal30 and all prior focused identities are green.

Ordinal29 fails at the pre-tamper assertion `crossSheetEdge != nullptr`; raw evidence says: `split-isolation witness must exercise a selected cross-sheet join`. No transition is rewritten before failure.

## 2. CAND-01 adjudication

### Finding F1 — identity29 assumes a selected-forest witness that the fixture contract does not provide

CB12 C1 is explicitly scoped to a **selected-forest edge** whose endpoint `cornerWedgeSheets` are disjoint. The production code now checks that such an edge has at least one `CornerWedgeIsolationTransition` connecting one endpoint sheet set to the other through `fromSheet/toSheet`; otherwise it returns `UncertifiedCrossSheetBinding` at site `cross-sheet`. Static Review confirms that exact predicate.

Identity29 uses `split_isolation_fixture()`, builds ordinary A5/A6 products, then scans `a6->selected_forest()` for a disjoint-sheet edge and asserts one exists. TB12 proves that assertion false for this fixture. The failure occurs before the C1 tamper and therefore says nothing about the exact production predicate.

A6's selected forest is a deterministic spanning forest constructed by union-find over the sorted owned relations. The frozen contract requires a valid deterministic spanning forest; it does **not** require every valid split-isolation fixture to select a cross-sheet relation rather than leave that relation cycle-closing. Therefore absence of a selected cross-sheet edge in this fixture is not a production-selection defect.

### Finding F2 — production C1 is not disproved, but its new falsifier remains runtime-unproved

The baseline split-isolation A7 product succeeds. Static source matches the required C1 endpoint-sheet connectivity predicate. However, because identity29 never reaches its tamper, the candidate does not yet have runtime evidence that unrelated `fromSheet/toSheet` values are rejected. Review therefore does **not** promote the candidate and does **not** claim C1 runtime closure.

### Candidate disposition

`M6-CP1-TB12-CLOSE-EXEC-CAND-01` is adjudicated **FALSE REJECTION / TEST-FIXTURE WITNESS DEFECT / RECOVERY REQUIRED / NON-STABLE**. This is not a stable event because no accepted-green selector/focused row regressed and no production defect is established. Stable accounting remains **60 events / 16 categories / 44 recurrences**, debt **1**.

## 3. RA-27 recovery rule

Recovery is test-authority only. Identity29 must use a deterministic **valid production-derived A6 product** that contains at least one selected-forest edge with disjoint endpoint sheet sets. The witness may be constructed test-side from a valid A5 publication seam, but A6 must be created by `SurfaceQuotientProducer::produce`; do not forge an impossible quotient product or bypass A6 validation.

The recovered identity must prove all of the following in one test:
1. non-vacuity: locate and assert a selected-forest edge with disjoint endpoint sheet sets;
2. positive control: baseline A7 accepts that exact witness;
3. negative discriminator: rewrite all relevant relation/endpoint isolation transitions for that edge to sheet IDs that connect neither endpoint set;
4. exact failure: A7 returns `UncertifiedCrossSheetBinding` at site `cross-sheet`;
5. no weakening: do not replace the selected-forest predicate with “any relation”, do not weaken endpoint-sheet membership, and do not change C1 production semantics.

If constructing such a valid A6 witness requires a production semantic change, **STOP for Review**.

## 4. Recovery routing

Exact next is runtime-free Code + Build **`M6-CP1-CB12-CLOSE-R2`**. It is test-only except for documentation and may change only `tests/SurfaceCellTransitionQuotientTests.cpp` plus focused-authority documentation if strictly needed. The focused identity name/order remains unchanged; selector449/routing449 and production source remain byte-identical.

Compile-green R2 routes to immutable **`M6-CP1-TB12-CLOSE-R1-EXEC`**, unchanged focused30 + selector449 = **479** fresh exact-filter processes, followed by mandatory **`M6-CP1-TB12-CLOSE-R1-REV`**. Only that Review may promote a recovered candidate and release `M6-CP1-CLOSE-REV`.

## 5. Review closeout

| Duty | Result |
|---|---|
| TB12 evidence | PASS mechanically; 478/479 semantic |
| Identity29 root cause | FALSE REJECTION / fixture witness assumption |
| Production C1 | statically consistent; runtime falsifier not yet proved |
| Candidate promotion | NO |
| Stable accounting | 60 / 16 / 44, debt 1 |
| Runtime in Review | none |
| Exact successor | `M6-CP1-CB12-CLOSE-R2` |

---

## Review-agent addendum (2026-10-05, resumed `M6-CP1-TB12-CLOSE-REV`)

**Disposition:**
- **Non-promotion: CONFIRMED.** CAND-01 stays non-stable (+0).
- **F1's root cause: INCORRECT. RA-27's recovery: WITHDRAWN.** It targets an unreachable branch and leaves the reachable one open.
- **C1 is incomplete (High):** the cross-sheet path that production actually exercises still uses the "any transition" proxy.
- **RA-27a** re-scopes `M6-CP1-CB12-CLOSE-R2` to:
  - a bounded production completion of C1;
  - a C4 name fix;
  - an identity-29 witness that runs on a **consistent** A5 → A6 → A7 chain.
- Gate unchanged at 479. Accounting **60 / 16 / 44**, debt 1.

### P1. Independent re-derivation (confirmed)

- Result `11326949864`: ZIP SHA-256 `da42bf2a...`. Log `11328055226`: `70880747...`.
- `SHA256SUMS` (`61499c93...`) verifies **979/979**.
- Focused ledger `602ed882...`: 30 rows in exact focused-30 order. Focused-30 (`1e815443...`) has focused-28 (`9154a986...`) as its exact prefix.
- Selector ledger `7185cff5...`: 449 rows in exact selector449 order (`d4a0d1b7...`).
- Every row has exactly one selection and zero skips. **478/479**; the sole RED is ordinal 29.
- Raw log `3f03a96c...`: `SurfaceCellTransitionQuotientTests.cpp:7397` `ASSERT_NE(crossSheetEdge, nullptr)` fails in 0 ms. Ordinal 30 is OK.
- Candidate source `02149f15` == HEAD source. Its diff from `8dd95821` touches 3 files: `RemeshPipeline.h/.cpp` and the test file.

### P2. C2–C4 code review

- **C2.** Three distinct A5 codes; the empty-front check is now first (as the plan required). The adapter emits the exact legacy names. Identity 30 proves the face-count and chart-transition branches end to end. Its empty-front part only checks the name table, which it states honestly: A4 rejects empty edges, so the A5 branch is defensive and unreachable. **Accepted.**
- **C3.** The count is taken from `isolationCertificateBySeam.size()` after the moved bijection check and is published only when validation passes. It equals the previous input count whenever the result is valid, so the change is provenance only. A complex built through `publish_records_for_validation` reports 0, meaning "not validated". **Accepted.**
- **C4.** It now fails closed when there is not exactly one opposite. **Two gaps:**
  - the name string `"ClosedComplexStripContinuationMismatch"` lacks the `Quotient` prefix that every sibling A6 name has, and the adapter forwards A6 names verbatim (`RemeshPipeline.cpp:7402`, `:7413`);
  - the branch has no executed falsifier. The plan (mine) never asked for one, so identity 28's green only proves it doesn't fire falsely.

### P3. F1 misdiagnoses CAND-01 (High)

F1 says the split-isolation fixture "is not required to place a cross-sheet relation in A6's selected spanning forest", i.e. that a disjoint-sheet relation may exist but be cycle-closing. **The fixture contains no relation with disjoint endpoint wedge-sheet sets at all.** Forest selection plays no part.

- **Fixture** (`make_square_fixture(true, false)`, `SurfaceCellTransitionQuotientTests.cpp:377-417`): a unit square of two triangles split along the diagonal `(0,0)–(1,1)`. Sheets are `{0,1}` per face; the field is constant xy; the target is 0.5. That gives a 2×2 grid of axis-aligned cells, and **the isolation seam crosses cell interiors.**
- **A5 wedge construction** (`RemeshPipeline.cpp:4395-4470`) walks the source faces inside each corner's sector and records an exact `{region, seam, fromSheet, toSheet}` transition for every sheet change.
  - The lower-left and upper-right cells' corners at `(0,0)`, `(0.5,0.5)` and `(1,1)` straddle the diagonal, so they get `cornerWedgeSheets = {0,1}` with exact `cornerWedgeIsolation`.
  - Every other corner has a single sheet.
- **Relations.** Relations join corners that share a front edge. Front edges are axis-aligned and never run along the seam. Around the center: LL{0,1}–UL{1}, UL{1}–UR{0,1}, UR{0,1}–LR{0}, LR{0}–LL{0,1}. **Every pair shares a sheet.** UL and LR are disjoint but have no relation.
- **When a disjoint-sheet relation can exist at all.** Only when a front edge is *collinear* with an isolation seam. **A6 already certifies that case exactly** (`RemeshPipeline.cpp:5292-5310`): a collinear span with different interior sheets must carry the forward and reverse `{region, seam, fromSheet, toSheet}` transitions. No fixture in the gate has such a seam.

**Consequence.** RA-27 §3 demands a production-derived A6 with a selected disjoint-sheet edge, built "from a valid A5 publication seam". No produced fixture has one. The publication seam (`:3628-3766`) validates neither relation nor wedge isolation consistency, so "valid" there guarantees nothing. RA-27 steers R2 toward a hand-built record set that the producers cannot emit, which is the forgery RA-27 itself forbids.

### P4. C1 hardened the unreachable branch and left the reachable one as a proxy (High)

In this fixture, and for every isolation seam that crosses cell interiors, the sheet crossing happens **inside a bridge occurrence** (a corner whose wedge spans both sheets). A7 certifies that case at `RemeshPipeline.cpp:6884-6895`:

```cpp
if (occurrence.cornerWedgeSheets.size() > 1U && !has_isolation_transition(occurrence))  // any non-empty list
  return fail(UncertifiedCrossSheetBinding, ..., "cross-sheet");
```

This is the same "any transition" proxy that RA-22a §3 condemned and C1 removed from the edge branch. Nothing else in the chain checks this case:
- A5 publication does not check that `cornerWedgeIsolation` connects `cornerWedgeSheets`;
- A6 only copies it into equivalence provenance (`:5449-5455`);
- A7 accepts it if it is non-empty.

So a record set with wedge transitions between unrelated sheets passes a **consistent** A5 → A6 → A7 chain. That is fail-open on the path production actually reaches.
- Ownership: the CB12 plan's C1 (mine) described only the edge proxy, so this is a review-agent error, owned. TB12-REV's "static Review confirms that exact predicate" also missed it.
- Gate-neutrality is expected. A5 records one transition per sheet change during the wedge traversal, so produced wedge evidence is connected by construction, and its region is the cell's region.

### P5. Test 29's negative uses an input pair the pipeline cannot produce (Medium)

The tamper republishes A5 but passes A7 the **original** A6, which was built from the untampered A5 (`SurfaceCellTransitionQuotientTests.cpp:7424-7428`). A7 matches A5 and A6 only by ID and class bijection (`:6541-6580`), and `QuotientCertificate` carries no binding to its source A5 (`RemeshPipeline.h:1187-1197`). Such a negative therefore tests an input state that the pipeline cannot produce, and it bypasses A6.

**Rule:** every recovery negative re-produces A6 from the tampered A5 with `SurfaceQuotientProducer::produce`. The missing A5 → A6 certificate binding is **`M6-CP1-TB12-REV-OBS-01`**, owner `M6-CP2` (the verifier consumes certificates) through `M6-DEFN-R5`.

### P6. Observation, not blocking

**`M6-CP1-TB12-REV-OBS-02`.** The A7 edge rule ignores relation kind, and isolation-sheet IDs are global flood-fill labels (`SurfaceCellTracing.cpp:7569-7600`).
- With the non-default classifier setting `traverseUnmarkedSharpBends = false`, sheets split at creases.
- A HardRail across such a crease would then have disjoint sheet sets and no isolation transition, and would be falsely rejected.
- This predates CB12 (the old proxy behaved the same), and the default (`true`) avoids it.
- Owner: `M6-DEFN-R5`.

### P7. RA-27a routing (full text in the frozen definitions)

`M6-CP1-CB12-CLOSE-R2` makes two **bounded production changes** and recovers identity 29.

1. **Exact wedge rule.** A class member with `|cornerWedgeSheets| > 1` is certified only if the graph on its `cornerWedgeSheets` is connected. Edges: its own `cornerWedgeIsolation` transitions with `region == occurrence.topologyRegion` and both `fromSheet` and `toSheet` in the set. Otherwise: `UncertifiedCrossSheetBinding`, site `cross-sheet:wedge`. The edge rule stays as is (site `cross-sheet`).
2. **C4 name.** Rename the string to `"QuotientClosedComplexStripContinuationMismatch"`.
3. **Identity 29** (name and order unchanged) runs on `split_isolation_fixture()`:
   1. Non-vacuity: a class member with at least 2 wedge sheets exists.
   2. Baseline A7 accepts.
   3. Tamper only that member's `cornerWedgeIsolation` to a sheet pair that does not connect its set.
   4. Republish A5, then **re-produce A6 from the tampered A5** and require it to succeed.
   5. A7 on (tampered A5, re-produced A6) returns `UncertifiedCrossSheetBinding` at `cross-sheet:wedge`.

   The old proxy accepts this case and the new rule rejects it, so the test discriminates.
4. **The edge rule's executed falsifier** is deferred to the first produced seam-collinear fixture (owner `M6-DEFN-R5` → `M6-CP3`). A6 already certifies that crossing exactly. No hand-built records.

Gate: focused-30 + selector449 = 479. **Stop for Review** if:
- any previously accepted row fails;
- A6 rejects the wedge tamper (that would mean A6 already certifies wedges);
- the wedge rule needs any semantic change beyond item 1.

### P8. Closeout

| Duty | Result |
|---|---|
| Evidence | Re-derived: 979/979, ledgers in frozen order, 478/479, ordinal 29 pre-tamper RED. |
| C2 / C3 | Accepted. |
| C4 | Fail-closed accepted; name prefix fixed in R2; no executed falsifier (noted). |
| F1 / RA-27 | Root cause corrected (no disjoint relation exists in the fixture); RA-27 §2–§3 withdrawn → RA-27a. |
| New High | Reachable wedge proxy (P4) → R2 production item 1. |
| OBS | OBS-01 (A5 → A6 binding, M6-CP2); OBS-02 (relation-kind-agnostic edge rule, DEFN-R5). |
| Accounting | +0 → 60 / 16 / 44, debt 1. |
| Lesson | 199. |
| Successor | `M6-CP1-CB12-CLOSE-R2` under RA-27a. |
