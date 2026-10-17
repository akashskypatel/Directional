# `M6-CP1-TB10-A5V-R1-REV` — Independent Recovery Review Record

**Turn:** `M6-CP1-TB10-A5V-R1-REV`
**Reviewed candidate:** `11299078582 / 96b456f925be00e00bad6645e6eb905a804c14ea`
**Reviewed runtime:** `37194004252 / 111411987330`
**Disposition:** **ACCEPTED / RECOVERY PROVED / CANDIDATE PROMOTED**
**Exact successor:** `M6-CP1-CB11-G4`

## 1. Independent evidence re-derivation

The R1 recovery gate is mechanically sound and independently re-derived from immutable artifacts.

- Compile candidate ZIP SHA-256: `142bac1bb485ff1f2b8017a08c8457053659867716c7b44edcceb117dca75afd`; root manifest `39259613897fa30935ecdb82f8616986bdb3ce544e82768a4aeeec46043ab708`, **28/28**; packaged source archive `f4bd8408880c8e661124f3ff01be33326a32259edb2296dd5bfe4932795c0710`; exact source `96b456f925be00e00bad6645e6eb905a804c14ea`; compile boundary `runtimeExecution=false`, GMP/GMPXX.
- Runtime result/log ZIP SHA-256: `b9f2daedc62d40c6768d3c257f3b720a1fee9e040ffce8e56f5022e216e8b589` / `b06b0a1bc81dafbe12811fa4991e01aab3c6c5de61dbdab84d99058dfb73d275`.
- Result self-manifest SHA-256 `21bec441216fdd829abce6eedc154868c53156cadca5a9dfcbf9540922e419b2`, **965/965**.
- Focused ledger: 24 rows, all PASS; selector ledger: 449 rows, all PASS; aggregate **473/473**. Every process selected exactly one test, zero skips, benchmark 0. Raw logs contain exactly 473 RUN / 473 OK / 0 SKIP records. RED ledger is header-only.
- Postflight proves package/source/execution-view census equality and unchanged focused/selector/routing authority; package manifest remains **28/28**.
- Frozen hashes re-derived: focused24 `6bcc8a544cbc0296df4cdb66dcb0c2dc7f86c88dfb340b795462c8c9544067bf`, focused20 `15d04a2a09eeb678923b0bfcf70bf9c07b79e7ff343ec468316f6510b16827d2`, selector449 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`, routing449 `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707`.

Review source authority is snapshot run/artifact `37197878231 / 11301865187`, event/source `16b85570debf8d3fab83e42458ffe92b116e68ba`, embedded archive SHA-256 `39bfaa8c2a8cf8a03367f6ccc3f8164b5be08b8db43327575accdf5ddddef763`, **5343/5343** source-file manifest checks, `runtimeExecution=false`. The first snapshot-marker create attempt was blocked by connector safety before any repository mutation; the corrected invocation succeeded. No semantic inspection relied on the failed attempt.

## 2. F1 / CAND-01 — RA-19 ordering and A5-product binding

**DISCHARGED.** The exact R1 source now publishes A5 records before any moved category-(a) predicate:

1. `publish_records_for_validation(std::move(cells), std::move(occurrences), std::move(relations))` runs first;
2. a publication error returns unchanged;
3. only a valid published `SurfaceOccurrenceComplex` reaches `validate_phase_front_authority_after_a5(...)`;
4. the helper consumes `complex.occurrences()`, checks side cardinality against `complex.certificate().directedSideCount`, and iterates `complex.cells()`.

The pre-R1-to-R1 production diff is confined to this binding/order repair in `src/pipeline/RemeshPipeline.cpp`; no adapter serialization or unrelated production semantic changed. The prior validation-order-shadowing candidate is therefore recovery-proved and closed as non-stable; append-only stable accounting is unchanged.

## 3. F2 / CAND-02 — identity24 complete pure-projection oracle

**DISCHARGED.** `M6CP1.ThinAdapterOutputIsPureProjectionOfStageProducts` remains the same frozen identity and still exercises the three required fixtures. Its expected values are independently reconstructed from A5/A6/A7 plus fixed/default compatibility rules; it does not call adapter helpers to create the expected result.

Field census against the current type definitions and adapter writes is complete:

- every `AuthoritativePhaseFrontMeshResult` field is asserted: success/failure, invalid loci, three topology summary fields, and all three consumed-authority counters;
- every `PureQuadMesh` field is asserted: fixed/default fields, vertices/positions/provenance, quads, boundary vertices/loops, backend/center-fan state, empty boundary-node/source-side metadata, vertex lineage and face lineage;
- every `PureQuadVertexLineage` field is covered, including all five `PureQuadFeatureIntervalLineage` members, full `SurfacePoint`, both stitch identities, source/local IDs, retained region/chart/sheet/support authority, quotient ID, occurrences, equivalences and selected relation paths;
- every `PureQuadFaceLineage` field is covered, including both cycle hashes;
- quad canonical ordering and boundary-loop rotation/sort are independently reimplemented test-side.

A one-field mutation of any adapter-written result/mesh/lineage field is therefore observable by identity24. Focused identity24 passes in the immutable R1 gate, and the prior test-authority candidate is recovery-proved and closed as non-stable.

## 4. R3 thin-adapter preservation

The adapter itself is unchanged by R1. Static inspection confirms it remains a compatibility projection: A5/A6/A7 producer invocation, typed legacy failure mapping, deterministic serialization/normalization, and diagnostic counters. R1 adds no tolerance, support/region/sheet selector, relation search, route validity, topology repair, merge/acceptance predicate, or legacy authority reconstruction to the adapter.

Within production `src/`, the R1 delta is only `src/pipeline/RemeshPipeline.cpp`; within tests it is only `tests/SurfaceCellTransitionQuotientTests.cpp`. Frozen gate files are byte-identical.

## 5. Regression and authority disposition

- `M6-CP1-TB10-A5V-REV-CAND-01`: **CLOSED / RECOVERY PROVED / NON-STABLE**; existing `VALIDATION_ORDER_SHADOWING` pattern, no stable repricing.
- `M6-CP1-TB10-A5V-REV-CAND-02`: **CLOSED / RECOVERY PROVED / NON-STABLE** test-authority defect, no stable repricing.
- R1 EXEC creates no new candidate. Stable accounting remains **60 events / 16 categories / 44 recurrences**, project debt **1**.
- Candidate `11299078582 / 96b456f925be00e00bad6645e6eb905a804c14ea` is promoted as the current reviewed M6 runtime authority under selector449 449/449 and focused24 24/24.
- Shared `tau`, RA-22b, A6/A7 semantics and the previously accepted thin-adapter failure mapping remain unchanged.

## 6. Successor and carried obligations

`M6-CP1-CB11-G4` is now authorized under `Architecture_M6_CP1_CB11_G4_B002_Boundary_Code_Build_Plan.md`, including RA-20/RA-21. Its compile-green successor is artifact-only TB11, **28+449 = 477**, then mandatory Review.

`M6-CP1-CLOSE-REV` continues to own the A7 cross-sheet certification proxy, provenance-face consumer audit, and the previously recorded merged-diagnostic-name closeout. `M6-DEFN-R5` remains a CP3-entry gate. No CP1 closure or debt discharge occurs in this Review.

## 7. Review closeout checklist

| Duty | Result |
|---|---|
| Immutable compile/runtime evidence independently re-derived | PASS — 28/28 candidate manifest; 965/965 runtime manifest; 473/473 exact-filter gate |
| F1 ordering/product binding | PASS / discharged |
| F2 complete projection oracle | PASS / discharged |
| Static thin-adapter preservation | PASS |
| Regression candidates | both recovery-proved / non-stable; no new candidate |
| Stable accounting | 60 / 16 / 44, debt 1 |
| Runtime authority | promote `11299078582 / 96b456f925be00e00bad6645e6eb905a804c14ea` |
| ORIENTATION / TODO / CHANGELOG / ROADMAP / tracker | updated for accepted R1 Review |
| Turn boundary | runtime-free Review; no source/test/fixture/selector/build mutation |
| Successor | `M6-CP1-CB11-G4` -> TB11 477 -> mandatory Review |

---

## Review-agent addendum (2026-10-04, resumed `M6-CP1-TB10-A5V-R1-REV`)

**Disposition:**
- **Acceptance and promotion: CONFIRMED.** Candidate `11299078582 / 96b456f9...` is the reviewed runtime authority.
- **F1/F2 discharges: CONFIRMED** by independent source and field-census checks.
- **RA-21b added.** A static pre-analysis of the CB11 oracle shows that RA-21 as written would hit its own stop rule on the produced torus. RA-21b fixes the oracle *before* CB11 starts.
- Accounting 60 / 16 / 44, debt 1. Successor unchanged: `M6-CP1-CB11-G4`, with its plan amended.

### K1. Independent re-derivation (confirmed)

- I downloaded result `11300407906` again. Its ZIP SHA-256 is `b9f2daed...b589`, and `SHA256SUMS` verifies **965/965**.
- The focused ledger is 24/24 PASS in the exact order of the focused-24 file (`6bcc8a54...`). The selector ledger is 449/449 PASS in exact selector449 order. No selection or skip anomalies.
- Raw logs: focused 20 `[ OK ]` (72 s), focused 24 `[ OK ]` (87 s).
- HEAD `src/`, `include/`, `tests/` and `cmake/` are byte-identical to `96b456f9`.

### K2. R1 source and oracle (confirmed)

**F1 / RA-19a.** `SurfaceOccurrenceComplexProducer::produce` now works in this order:
1. call `publish_records_for_validation(...)` and return any of its errors unchanged;
2. run `validate_phase_front_authority_after_a5(..., *complex)` on the **published** complex (`RemeshPipeline.cpp:4937-4951`):
   - the side count is checked against `complex.certificate().directedSideCount`, iterating `complex.cells()`;
   - regions come from `complex.occurrences()` (`:3467`, `:3603-3606`);
3. return the published product.

The diff touches nothing else.

**F2 / §J3.** Identity 24 now asserts, with exact equality, every field of:
- `AuthoritativePhaseFrontMeshResult` (11);
- `PureQuadMesh` (14);
- `PureQuadVertexLineage` (17, including all five `PureQuadFeatureIntervalLineage` members and every `SurfacePoint` member);
- `PureQuadFaceLineage` (8).

I checked these against the current struct definitions; no field is unaccounted for. Quads are compared in the A7 corner order, which is stronger than comparing canonicalized cycles, after test-side canonical sorting. Boundary loops are re-derived test-side.

**Observation (not blocking).** `consumedInternalIsolationSeams` is the A4 input's certificate count, and the oracle expects exactly that. It is "consumed" only because A5's moved bijection check passes. `M6-CP1-CLOSE-REV` should source it from A5's validated certificate set.

### K3. CB11 pre-analysis: RA-21 needs a subdivision-equivalence oracle (RA-21b)

CB11 is the next turn. RA-21 requires an exact combinatorial isomorphism between the A6 closed-complex view and the retained arrangement on the produced torus, keyed through `(proposalId, proposalSide)`, and stops for Review if the arrangement subdivides proposal cells. Static facts at `96b456f9`:

1. **The proposal key is positional.**
   - In the authoritative phase-front path, A3 builds `network.proposals` one per `phaseFront.cells()` row, in order. It copies `corners` and `boundaryPaths`, and by design carries **no `CellId`** ("never mirror CellId into seed provenance") (`SurfaceCellTracing.cpp:17901-17916`).
   - So `proposalId` is a row index into the same immutable A4 product.
2. **`halfedge.proposalId` is only the primary provenance** (`SurfaceArrangement.cpp:2426`).
   - Each halfedge carries a `provenance` vector of `(proposalId, proposalSide, proposalBoundarySegment, sourceT0, sourceT1)` entries. The authoritative proposal-cycle rebuild groups halfedges by these entries (`:2701-2709`).
   - Coincident sides of adjacent proposals merge into one halfedge pair with two entries.
3. **Every A4 cell side is a polyline across source faces.**
   - `boundaryPaths[s]` is a vector of per-face `SurfaceTraceSegment`s, and each segment becomes an arrangement arc, so each side becomes a *chain* of halfedges with degree-2 nodes at source-edge crossings.
   - A strict isomorphism therefore **fails by construction**, and RA-21's stop rule would fire on the first CB11 attempt.
4. **No other arc sources on the torus (expected).** The produced torus has no singular separatrices, and its authoritative path builds no seed traces before returning proposals (`:17890-17920`). Authoritative rails are not inserted as extra arcs (`insertBoundaryRails = authoritativeRails.empty()`). So the expected subdivision is pure degree-2 chaining. CB11 must verify this rather than assume it (RA-21b item 4).

**RA-21b** (frozen definitions) therefore replaces RA-21 item 1's key and isomorphism notion with:
- a **provenance-chain** key;
- an equivalence **up to degree-2 contraction**;
- explicit positional preconditions;
- RA-21's stop rule kept for every *other* kind of subdivision.

### K4. Closeout

| Duty | Result |
|---|---|
| Primary evidence | Digest, 965/965 manifest, both ledgers in frozen order, focused 20/24 OK, HEAD == `96b456f9`. |
| F1 / F2 discharges | Confirmed in source and by a full struct-field census. |
| CB11 readiness | RA-21b: provenance-chain key, degree-2 contraction, positional preconditions, stop rule kept for other subdivisions. CB11 plan amended. |
| Observation | `consumedInternalIsolationSeams` source → CP1 close. |
| Accounting | 60 / 16 / 44, debt 1. |
| Lesson | 195 — check an oracle's preconditions statically before the turn that must satisfy them. |
| Successor | `M6-CP1-CB11-G4` (RA-20, RA-21, RA-21b) → TB11 477 → mandatory Review. |
