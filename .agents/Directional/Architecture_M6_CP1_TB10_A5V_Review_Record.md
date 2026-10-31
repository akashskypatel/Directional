# M6-CP1-TB10-A5V Review Record

**Turn:** `M6-CP1-TB10-A5V-REV`
**Reviewed candidate:** `11295692493 / 7c56845d4fac7ccb28898bbf4c681fc509ff9c3b`
**Reviewed runtime:** `37184301651 / 111382969115`
**Disposition:** **REJECTED / UNPROMOTED / REPAIR REQUIRED**
**Reviewed runtime retained:** `11292072930 / 584f80fe27fe3fbe482f3b6db035651a3083257c`
**Exact successor:** `M6-CP1-CB10-A5V-R1`

## 1. Independent evidence re-derivation

The TB10 execution itself is mechanically sound.

- Result ZIP SHA-256 independently recomputed as `109e98d6be0dc4106889b45645aec7818de0bca0177480ff783e11df77020cae`; log ZIP SHA-256 is `00e640b72e4be6968e2dadeac3af690e30320cb6a6a2de741946acb9b10eebba`.
- Result self-manifest independently verifies **965/965**; manifest SHA-256 is `7b915d5e3056844bdc2f13248b9d34b22b0b0133544e89249c7761f9c62ce1f1`.
- Candidate ZIP independently hashes to `e65cd6ee6b3f883b526207d83718a028b111f7ecc4de89e70e9365f38ea77065`; its root manifest verifies **28/28**; source archive hashes to `2cd6f8acd11cb635b8db40b29f9d902438c820ba8d360306208545506ccaa3bb`; source receipt is exactly `7c56845d4fac7ccb28898bbf4c681fc509ff9c3b`; every source-status receipt is empty.
- Focused24 re-hashes to `6bcc8a544cbc0296df4cdb66dcb0c2dc7f86c88dfb340b795462c8c9544067bf`. Its first 20 lines independently hash to focused20 `15d04a2a09eeb678923b0bfcf70bf9c07b79e7ff343ec468316f6510b16827d2`. Focused12 remains `59a523ae2039e0cb537cee550aab6e54936353b8a60234a3915049dc0c3d571c`.
- Selector449 / routing449 independently re-hash to `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414` / `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707`, each 449 rows.
- Ledgers contain exactly **24 focused + 449 selector = 473** data rows. Raw logs contain exactly 473 `[ RUN ]` and 473 `[ OK ]` lines and no skips. The RED ledger has only its header. Focused 21-24 and the previously sensitive selector rows are PASS.
- Execution boundary records no configure, compile, relink, generated discovery, benchmark, package repair, mode repair, source/test/fixture/selector mutation, orchestration failure, or retry after runtime start. Package/source/execution-view/focused/selector/routing postflight equality is recorded and covered by the self-manifest.

This establishes a mechanically valid 473/473 TB10 run. It does **not** make the candidate acceptable when the implementation/test contract itself is incomplete.

## 2. Finding F1 — RA-19 validation precedence is not implemented as frozen

**Severity: blocking. Candidate stays unpromoted.** Existing category: `VALIDATION_ORDER_SHADOWING`; this candidate is non-stable because no accepted runtime lost green.

RA-19 states that moved category-(a) checks must run inside A5 **after every check A5 performs today**; earlier placement is allowed only with a per-required-test outcome proof in the CB10 report.

The exact candidate violates that ordering:

- `validate_phase_front_authority_after_a5(...)` is invoked at `RemeshPipeline.cpp:4937-4941`.
- Only afterwards does `produce(...)` call `publish_records_for_validation(...)` at `:4943-4945`.
- `publish_records_for_validation(...)` contains the pre-existing A5 ownership/corner/side/relation checks at `:3620-3757`.

The CB10 report instead states that the moved checks are after the pre-existing A5 checks and supplies no RA-19-authorized per-required-test proof for the earlier placement. Focused23 proves one HardRail-before-A6 path, not the full ordering of the pre-existing A5 validation boundary.

**Required correction.** Preserve all existing A5 record validation before the moved phase-front category-(a) helper. Do not rename or weaken any existing failure. The repair must make the dataflow/order evident in source; do not satisfy this finding by accepting multiple failure outcomes.

**Falsifier.** The repair fails Review if any moved category-(a) predicate can still execute before `publish_records_for_validation` has accepted the constructed A5 records, or if any existing A5 failure name/precedence is widened.

## 3. Finding F2 — focused identity 24 does not prove the frozen full-projection contract

**Severity: blocking test-authority gap. Candidate stays unpromoted.** Non-stable; no production regression is claimed.

RA-19 changed identity24 to a behavioral contract: on the hard-rail, split-isolation and produced-torus fixtures, the adapter's **mesh, provenance and lineage** must equal an independent test-side serialization of A5/A6/A7 products.

The exact test at `SurfaceCellTransitionQuotientTests.cpp:3769-3867` checks only a subset:

- vertex position/provenance and selected vertex-lineage fields;
- canonicalized quad cycles;
- only `operationLocalQuad` and `operation` from each face-lineage row.

It does not compare adapter mesh fields such as `sourcePatch`, the complete `vertices` vector, `boundaryVertices`, `boundaryLoops`, `backend`, `usesCenterFan`, or the default/empty fields that are part of `PureQuadMesh`; it also omits vertex-lineage fields including output/local IDs, kind and default stitch/cache fields, and face-lineage fields including `outputQuad`, `sourcePatch`, `completionVariant`, `boundaryOnly` and the cycle hashes. It also does not compare the adapter result's A5/A6/A7-derived summary counters.

A mutation in any omitted serialization field can therefore leave identity24 green. The 473/473 run proves the authored test passed, but the authored test is not yet the frozen pure-projection falsifier.

**Required correction.** Keep the identity name and focused24 file unchanged. Strengthen the test body to construct the complete expected adapter serialization from A5/A6/A7 (plus fixed compatibility/default values where the adapter contract intentionally has them) and compare every adapter-written mesh, provenance, lineage and result-summary field. If a field's expected semantics cannot be derived without inventing new authority, stop for Review rather than guessing.

**Falsifier.** Deliberately changing any adapter-written serialized field or summary field away from the independently derived expectation must make identity24 fail.

## 4. Disposition and bounded recovery

- Shared `tau` single-sourcing is accepted: `SurfacePointSourceSupportResolver::default_barycentric_tolerance() == 1.0e-8` is the canonical owner and both A5 and A7 consume it. No retune is authorized.
- RA-22b is accepted: the A7 representative-face retained region/sheet reject-only guard is restored with exact `CompletionOwnershipInvalidRetainedSourceAuthority:representative-face`, and focused20 contains both positive and negative coverage.
- TB10 execution evidence is accepted as mechanically valid, but candidate `11295692493 / 7c56845d...` is **rejected for promotion** because F1 and F2 leave RA-19 incompletely satisfied.
- Stable accounting remains **60 events / 16 categories / 44 recurrences**, debt 1. No stable event is added because the candidate was never reviewed/accepted runtime authority.
- Reviewed runtime remains TB9-R1 `11292072930 / 584f80fe...`.
- The A7 cross-sheet certification proxy and provenance-face consumer audit remain owned by `M6-CP1-CLOSE-REV`.

Exact successor is runtime-free Code + Build `M6-CP1-CB10-A5V-R1`, governed by `Architecture_M6_CP1_CB10_A5V_R1_Code_Build_Plan.md`. Compile-green then routes to immutable `M6-CP1-TB10-A5V-R1-EXEC` using the unchanged focused24 + selector449 = **473** gate, followed by mandatory `M6-CP1-TB10-A5V-R1-REV`. CB11 remains held.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | focused24 `6bcc8a...067bf`; first20 `15d04a...827d2`; focused12 `59a523...d571c`; selector449 `d4a0d1...d6414`; routing449 `9c88a5...6c5707` |
| Decisive claims independently re-derived | result/log/candidate digests; 965/965 result manifest; 28/28 candidate manifest; 24+449 ledgers/raw logs; exact source; F1 source ordering; F2 field coverage |
| Non-vacuity checked | focused21-23 execute targeted tamper paths; focused24 executes three stage-valid fixtures, but its omitted-field oracle gap is itself blocking F2 |
| Prior obligations discharged/carried | shared `tau` DISCHARGED; RA-22b DISCHARGED; RA-19 ordering/pure-projection NOT DISCHARGED -> R1; A7 cross-sheet proxy + provenance-face audit carried to `M6-CP1-CLOSE-REV` |
| Stable accounting | 60 events / 16 categories / 44 recurrences, debt 1; reviewed runtime remains `11292072930 / 584f80fe...`; selector449 remains accepted |
| New candidates/obligations recorded | `M6-CP1-TB10-A5V-REV-CAND-01` validation-order recurrence; `...-CAND-02` test-authority undercoverage; tracker updated |
| ORIENTATION currency line | `M6-CP1-TB10-A5V-REV`, 2026-10-04 UTC written |
| ORIENTATION §3 / §4 / §7 / §8 | §3, §7, §8 updated; §4 n/a because no witness authority changed and TB9-R1 remains reviewed runtime |
| CHANGELOG | review rejection / R1 route entry added |
| ROADMAP | CB10/TB10 candidate marked rejected; R1 recovery made exact next |
| Selector manifest | n/a: selector449 and all selector bytes unchanged; no new selector accepted |
| LESSONS | lesson 193 added |
| Consolidation under CLEAN_UP_POLICY | n/a: no historical document became redundant in this bounded review |
| Successor frozen | `M6-CP1-CB10-A5V-R1`; falsifiers stated in the R1 plan and Findings F1/F2 above |
| Turn boundary held | runtime-free Review; no product, test, fixture, selector, benchmark or build source mutated |
| review_check.py boundary | PASS — `python3 .agents/Directional/tools/review_check.py boundary`; no product/test/fixture/build mutation, no selector mutation, all selector hashes match baseline, durable markers preserved |
| `STATUS` lifecycle maintained | entry beacon published; final COMPLETE beacon to name `M6-CP1-CB10-A5V-R1` |
| Pushed to origin, branch in sync | documentation patch push will be verified by exact branch-head read; connector environment has no authoritative local tracking checkout, so no fabricated `git status -sb` claim is made |

---

## Review-agent addendum (2026-10-04, resumed `M6-CP1-TB10-A5V-REV`)

**Disposition:**
- **Rejection, F1 and F2: CONFIRMED.**
- **Move fidelity verified.** TB10-REV had not checked whether the moved predicates are semantically equivalent; this addendum does (J2).
- **R1 plan amended.** The F2 oracle now has an exact field table derived from the adapter, and the F1 reorder must bind the helper to the published A5 complex (J3).
- Accounting 60 / 16 / 44, debt 1. Successor unchanged: `M6-CP1-CB10-A5V-R1`.

### J1. Independent re-derivation (confirmed)

- I downloaded result `11296687408` again. Its ZIP SHA-256 is `109e98d6...0cae`, and `SHA256SUMS` verifies **965/965**.
- The focused ledger is 24/24 PASS in the exact order of `Architecture_M6_CP1_Required_Green_Focused_24.txt`; its first 20 lines hash to `15d04a2a...`. The selector ledger is 449/449 PASS in exact selector449 file order. No selection or skip anomalies.
- HEAD `src/`, `include/` and `tests/` are byte-identical to candidate `7c56845d`.

**Code checks.**
- **F1 confirmed.** `validate_phase_front_authority_after_a5(...)` (`RemeshPipeline.cpp:4937-4941`) runs before `publish_records_for_validation(...)` (`:4943-4945`).
- **RA-22b confirmed** (`PureQuadCompletion.cpp:901-912`).
- **Shared `τ` confirmed.** A5 and A7 both read `SurfacePointSourceSupportResolver::default_barycentric_tolerance()`, at `RemeshPipeline.cpp:3790` and `:6046`.
- **The adapter is now 252 lines** (`:6843-7095`). It does typed-error mapping, including the A7 `MaterializedMeshInvalid` site → legacy-name table, plus A7 serialization and counters. It has no semantic predicate, selection or tolerance.

### J2. Move fidelity — the 31 category-(a) sites (not checked by TB10-REV; now verified)

A move refactor is safe only if the predicates move unchanged. I normalized the old adapter section (`6c3ae223`, adapter start through the A6 call) and the new helper:
- `result.failure="X"; return result;` and `return fail(Code::X …)` both become `FAIL(X)`;
- whitespace is collapsed;
- the statement-level texts are then diffed.

Results:

1. **28 sites move with identical predicates.** The only differences are renames: `topologyRegionById` → `regionById`, `cellIndexById` → `cellById`, and typed-`auto` loops.
2. **The side-count site changed its authority source.** `edgeByCellSide.size() != occurrenceComplex->certificate().directedSideCount` and the loop over `occurrenceComplex->cells()` became `phaseFront.cells().size() * 4U` and `phaseFront.cells()`, because the helper now runs before A5 publishes.
   - It is semantically equivalent for producer-built records: one A5 cell per phase-front cell, four directed sides each.
   - But it re-binds an A5-product check to the A4 input. The F1 reorder must restore the binding (J3).
3. **Three unpinned legacy literals now map onto existing A5 codes:**
   - `MissingAuthoritativePhaseFront` (empty cells; empty edges now fails later as `IncompleteAuthoritativePhaseFrontSides`) and `InvalidAuthoritativePhaseFrontSource` → A5 `SourceAuthorityMismatch`;
   - `InvalidAuthoritativeSourceChartTransitions` → A5 `InvalidChartAuthority`.

   All stay fail-closed, and R4 §3.4 releases the spelling of unpinned sites. But two distinct causes now share `OccurrenceSourceAuthorityMismatch`, which is a lesson-181 diagnosability loss. Recorded for `M6-CP1-CLOSE-REV`; not blocking.

No moved predicate was weakened or widened.

### J3. R1 plan amendments (binding)

**For R1 (ordering).**
- After `publish_records_for_validation` returns a valid `SurfaceOccurrenceComplex`, the moved helper must take the **published** complex.
- The side-count check uses `complex.certificate().directedSideCount` and `complex.cells()` again, exactly as the pre-CB10 adapter did.
- Validating against the input instead of the A5 product is not permitted after the reorder.

**For R2 (identity 24) — exact oracle, derived from the adapter's own writes at `7c56845d`.** Every expected value is computed test-side from A5/A6/A7 products or the fixed compatibility constant.

| Field | Expected value | Source |
|---|---|---|
| `success` | `true` | — |
| `failure` | empty | — |
| `invalidCell`, `invalidEdge` | `-1` | — |
| `connectedComponents`, `boundaryLoopCount`, `eulerCharacteristic` | A7 `certificate()` | A7 |
| `consumedTopologyRegions` | count of distinct A5 `occurrence.topologyRegion` | A5 |
| `consumedInternalIsolationSeams` | A4 `isolationSeamTransportCertificates().size()` | A4 input |
| `consumedPeriodicHolonomies` | count of distinct `periodicRelation` among A6 `relation_certificates()` | A6 |
| `mesh.sourcePatch` | `0` | fixed |
| `mesh.backend` | `ClosedForm` | fixed |
| `mesh.usesCenterFan` | `false` | fixed |
| `mesh.vertices` | `0..n-1` | — |
| `vertexPositions` row `r` | A7 `vertices()[r].position` | A7 |
| `vertexProvenance[r]` | A7 `sourcePoint` | A7 |
| vertex lineage `outputVertex`, `localVertex` | `r` | — |
| vertex lineage `kind` | `SourceTriangle` | fixed |
| vertex lineage `sourcePatch` | `0` | fixed |
| vertex lineage `sourcePoint`, region/chart/sheet sets, `sourceSupport`, `sourceOccurrences`, `equivalences`, `selectedRelationPaths` | the A7 vertex's fields | A7 |
| vertex lineage `quotientClass` | `QuotientClassId::from_index(r, n)` | — |
| other vertex-lineage fields (`featureInterval`, `stitchIdentity`, `authoritativeIdentity`, …) | value-initialized defaults | — |
| `quads` | A7 `topology()` cells mapped through the class→row map, sorted by lexicographically smallest rotation (canonical cycle) | A7 |
| face lineage `outputQuad` | its index | — |
| face lineage `sourcePatch` | `0` | fixed |
| face lineage `operation` | `ClosedForm` | fixed |
| face lineage `operationLocalQuad` | the source cell's `CellId` index | A7 topology |
| face lineage `completionVariant` | `0` | fixed |
| face lineage `boundaryOnly` | `false` | fixed |
| face lineage cycle hashes | `0` | default |
| `boundaryLoops` | A7 `boundary_loops()` mapped to rows, each rotated to start at its minimum row, then sorted | A7 |
| `boundaryVertices` | concatenation of `boundaryLoops` | — |
| other mesh fields (`domainIdentity`, `boundaryNodeIdentities`, `sourceSideEdgeCounts`, `boundaryProvenance`, `boundaryRailIds`) | defaults | — |

Rules:
- Compare every field with exact equality.
- Use `isApprox` only where the adapter copies a double from A7 by value; these compare equal, so exact equality is preferred.
- A field outside this table found to be adapter-written is a stop for Review.

### J4. Closeout

| Duty | Result |
|---|---|
| Primary evidence | Digest, 965/965 manifest, focused-24 and selector449 ledgers in frozen order, HEAD == `7c56845d`. |
| Findings F1 / F2 | Confirmed in source. |
| Move fidelity | Verified by normalized predicate diff: 28 identical, 1 re-bound to the A4 input (restored in R1), 3 unpinned names consolidated (recorded). |
| R1 plan | Amended: helper bound to the published complex; exact identity-24 field oracle. |
| Accounting | 60 / 16 / 44, debt 1. |
| Lesson | 194 — review a move refactor with a normalized predicate diff. |
| Successor | `M6-CP1-CB10-A5V-R1` → TB10-R1 473 → mandatory Review. |
