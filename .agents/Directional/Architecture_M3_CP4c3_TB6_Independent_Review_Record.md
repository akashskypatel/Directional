# M3-CP4c-3-TB6 Independent Review + Plan Record

**Turn:** `M3-CP4c-3-TB6-REV`
**Type:** independent REVIEW + PLAN only
**Date:** 2026-09-01 UTC
**Verdict:** **TB6 is a valid semantic red. Amendment 17 is still violated in the current vertex-transit election. The next bounded turn is `M3-CP4c-3-CB8`, Code + Build, runtime-free.**

No Directional executable, test, benchmark, compile, link, package, fixture, product, or selector was executed or mutated during this review.

## 1. Executive adjudication

TB6's immutable evidence is valid, but one durable evidence identity in the TB6 report/review-plan/changelog was wrong and is corrected by this review. The authoritative TB6 result artifact is **`9782227361`**, Actions SHA-256 **`e39fcab4ec71c951f9dd7505d052d73fbee7a4f2f66105ae6ff7a47dad672a87`**, not the previously recorded `5748464145 / f084...` pair.

The semantic result itself is unchanged:

- immutable package 75 / semantic source `e926ada023bc51220628be550bbe9a87f98d7067`;
- selector 373 SHA-256 `b47c269851fad1384b5dc9baaf674b3d4ad80ec6c2b40f7f8eda2055c6f44834`;
- ordinals **1–365 PASS**;
- first red **366**, `GlobalTopologyPlan.MechanicalFeatureWitnessDerivesRegionsThroughProductionEntryPath`;
- failure locus: regular source vertex **30**, arrival face `(24,30,32)`, branch 1, `FaceInterior`, two published faces `(25,30,31)` and `(30,31,119)`, no barrier absorption/incidence;
- report-only ordinals 367–373: **1 PASS / 6 RED**, zero gate credit;
- immutable pre/postflight PASS and no build/repair/source/test/fixture/selector mutation.

The review establishes three additional facts from the exact source and committed fixture:

1. **The missing CB7 per-state transit diagnostics are recorded by the resolver and then dropped by the production diagnostic projection.** `resolve_field_vertex_transit` populates `FieldAlignedCurveNetworkError::vertexTransitStates`; `RemeshPipeline.cpp::network_failure_locus` maps only the reduced locus into `SurfaceCellFailureLocusDiagnostics`, whose DTO has no transit-state rows. The production test serializer therefore cannot emit them.
2. **CB7 corrected the floating-point round-trip but did not preserve Amendment 17's single datum.** At each fan transition the code rotates only the branch label by the atlas `signedLift`, then replaces `incomingDirection` with the target face's local `nextPairing->direction`. Consequently `incomingDirection` is again a per-face branch representative. The value is exact, but its semantic authority is wrong.
3. **The two candidate-face representatives are provably distinct regardless of branch label.** In the committed mechanical fixture, face row 41's four cross rays all have `x=0` and nonzero `z`; face row 208's four rays all have `z=0` and nonzero `x`. A gauge change only permutes those four rays. No row-41 branch direction can equal any row-208 branch direction. The prior equal-direction falsifier therefore does not fire; instead the source proves the surviving M4 mechanism: one local representative per candidate cell is being tested.

The accepted 365-prefix remains green. Stable accounting therefore remains **44 events / 14 categories / 30 recurrences**, produced-witness debt **5**, semantic M3 packages **73**.

---

## 2. AV0 — immutable evidence re-established

### Package/source authority

- package 75 Actions artifact: `9781487311`;
- outer artifact SHA-256: `547f2441b026b68d2bef10e7c7694faf994be473a1d2db68a6375d06b1e654b8`;
- inner `package75.tar.gz` SHA-256: `8814b700a5c07290ce099ce1f719f01b2fbd5bcfd80f36037fe5bafc600f7896`;
- packaged source archive SHA-256: `64e5189f3c9f22d648e496c50b4093e842a0fad25a885dca65778d7a110b629a`;
- semantic source: `e926ada023bc51220628be550bbe9a87f98d7067`;
- package records `runtimeExecution=false`, `packageRepair=false`, 27 package-relative fixtures, and six executable files with mode `0755`.

### TB6 authority

- run/job: `33458067065 / 99702200466`;
- result artifact: **`9782227361`**, SHA-256 **`e39fcab4ec71c951f9dd7505d052d73fbee7a4f2f66105ae6ff7a47dad672a87`**;
- log artifact: `9782227729`, SHA-256 `394fd045c2f860d79dd76ad22defc0d74430dcf5635da2a5d16927312907ef89`;
- selector 373: `b47c269851fad1384b5dc9baaf674b3d4ad80ec6c2b40f7f8eda2055c6f44834`;
- gate: ordinals 1–365 PASS, 366 RED;
- report-only remainder: every ordinal 367–373 executed once after the gate verdict, 1 PASS / 6 RED, zero gate credit;
- immutable preflight and postflight PASS.

### Documentation-evidence correction

The prior TB6 report, frozen review plan, and agent changelog named result artifact `5748464145` with SHA-256 `f084...`. GitHub run `33458067065` has no such result artifact; its authoritative result artifact is `9782227361 / e39f...`. The semantic stdout/result contents summarized by the report remain consistent with the downloaded authoritative artifact. This is a **documentation evidence-identity defect**, not a runtime invalidation and not a stable regression.

---

## 3. AV1 — exact vertex-30 transit authority after CB7

### 3.1 Source fan remains the TB4 fan

The mechanical fixture gives source vertex 30 one regular six-face, consistently oriented, closed fan:

| fan step | source face row | canonical face | role |
|---:|---:|---|---|
| 0 | 43 | `(24,30,32)` | arrival / excluded for `FaceInterior` |
| 1 | 40 | `(24,25,30)` | traversed state |
| 2 | 41 | `(25,30,31)` | candidate A |
| 3 | 208 | `(30,31,119)` | candidate B |
| 4 | 209 | `(30,119,123)` | traversed state |
| 5 | 218 | `(30,32,123)` | traversed state |

The vertex is not a prescribed singularity, is not barrier-absorbed, is not barrier-incident, and has trivial branch holonomy. Candidate A and B are adjacent and share ray `30→31`; the exact half-open sector convention assigns the shared ray to A and excludes it from B. One geometric ray can therefore elect at most one of them.

### 3.2 What CB7 actually transports

Current `resolve_field_vertex_transit` starts with the arrival face's exact `currentPairing->direction`. For a transition it:

1. reads the mesh/atlas transport adjacency;
2. applies the adjacency's exact quarter-turn `signedLift` to the **branch label**;
3. finds the target face's pairing for that rotated label; and
4. assigns `incomingDirection = nextPairing->direction`.

That fourth step is decisive. `FieldBranchBoundaryPairing.direction` is independently built from each face's local cross-field representative. `FieldBranchTransportAdjacency` supplies branch correspondence (`signedLift`) and a floating effort; it does **not** publish an exact continuous geometric transport of an arbitrary ray. The code therefore preserves an exact branch label while substituting the target face's local representative for the datum.

For an evaluated state, `representativeDirection` and `incomingDirection` consequently describe the same local pairing direction. The two audit columns are exact but are not independent authorities.

### 3.3 Fixture falsifier

The committed raw field makes distinctness independently checkable without relying on a missing runtime row:

- row 41's four branch vectors all satisfy `x = 0` and `z != 0`;
- row 208's four branch vectors all satisfy `z = 0` and `x != 0`.

A face gauge can only permute the four branch representatives. Therefore no branch representative on candidate A can equal any branch representative on candidate B.

This confirms the TB4 reconstruction rather than refuting it: two different local rays were tested against two different fan cells.

---

## 4. AV2 — production diagnostic rows are dropped at a proven projection boundary

The diagnostic chain is:

```text
resolve_field_vertex_transit
  -> FieldAlignedCurveNetworkError::vertexTransitStates
  -> RemeshPipeline.cpp::network_failure_locus(error)
  -> SurfaceCellFailureLocusDiagnostics
  -> production test append_cp4c_failure_locus(...)
```

The resolver records typed state outcomes before suppressing exits and attaches the full vector to its returned network error. Test-only `append_network_error` can serialize those rows, including exact representative/incoming direction, transport edge/path, quarter-turn, eligibility, and sector-membership fields.

The loss happens later:

- `network_failure_locus` copies source vertex/edge/face, branch, region, arrival mode, candidate cardinality/faces, and barrier fields;
- `SurfaceCellFailureLocusDiagnostics` has no field for the transit-state vector;
- therefore the production entry exception has no place to retain or serialize the rows.

**Owner:** `src/pipeline/RemeshPipeline.cpp::network_failure_locus` plus the public diagnostic DTO in `include/directional/diagnostics/RemeshDiagnostics.h`. The resolver is not the owner of this omission.

This gap should be closed in CB8 as **additive observability** because the same rows are required to prove the semantic correction in the next immutable TB. It must not alter selection, failure codes, or topology.

---

## 5. AV3 — Amendment 17 adjudicated

### Finding

**Amendment 17 is still violated.** The current source does not test one continuation datum against a partition. It tests each candidate cell against that cell's exact local branch representative under the name `incomingDirection`.

This is the same semantic M4 family proved at TB4, with a different representation history:

- CB6 introduced one geometric datum but carried it through world-space `double`, violating Amendment 18;
- CB7 removed the float round-trip by carrying branch identity through exact `signedLift`, but then rebound the datum to `nextPairing->direction` in every face;
- the final predicate is exact in CB7, yet the datum is once again **one per cell**.

The correction therefore cannot be "make the comparison more exact," "order the candidates," "change the half-open sector convention," "alter `FaceInterior`," or "choose the nearest branch." Those all preserve or hide the malformed question.

### Representation constraint discovered by review

The current atlas branch transport proves **which branch corresponds** across a source edge. It does not, by `signedLift` alone, prove an exact continuous transport of an arbitrary tangent ray across a non-coplanar fan. CB8 must not silently claim that branch-label transport is geometric-ray transport.

The next implementation must give the continuation one exact, single-writer authority and derive every per-face sector query from that authority. An exact common fan chart or another independently certified equivalent representation is admissible. Rebinding to the target face's field representative is not.

If the existing source/atlas products cannot represent that datum exactly without a float/tolerance, CB8 must stop and report the missing authority rather than manufacture one. That stop is an architectural finding, not permission to restore the CB6 float path.

---

## 6. AV4 — minimal-witness / selector governance

CB7 added and compiled:

`ResolvedBranchCorrection.MinimalExactVertexTransitWitnessPublishesKnownFanState`

TB5-REV AU8 required the minimal transit witness to become a **permanent regression identity**. CB7 intentionally did not mutate selector 373, so TB6 correctly did not execute it. The result is a plan inconsistency, not a TB6 orchestration defect.

**Decision:** CB8 must preserve selector 373 byte-for-byte and create **selector 374** by appending exactly this identity as ordinal 374. No prior identity may move, disappear, or change spelling. The new selector gets a fresh hash in CB8 evidence.

The identity also needs to become a useful Amendment-17 regression, not merely assert that *some* state diagnostic exists. CB8 may strengthen its body while keeping the identity stable so it falsifies the old per-cell-representative mechanism and proves the new single-authority invariant.

Selector 374 is **required-green future authority**, not non-gating support. It does not retroactively change TB6 or accepted selector 365.

---

## 7. AV5 — report-only 367–373 disposition

| ordinal | TB6 result | review disposition |
|---:|---|---|
| 367 | RED | Upstream-blocked by ordinal-366 mechanical transit. Underlying contract remains unmeasured. |
| 368 | RED | Preserve `NoCarrierMatch / SourceEdgeUnavailable` at sphere trace 2/event 30. No sphere semantic fix is authorized. |
| 369 | RED | Intended assertion reached with `saturationUsed=true`; active deferred quality/coverage finding. |
| 370 | RED | **Genuine independent A2a′ product-contract red.** The repaired witness now reaches `SurfaceCutGraph::canonical_candidate`; source has no branch that returns `EmptyNetworkOnClosedSurface`, so the empty closed-network case falls into generic work and ends `CellularityNotEstablished`. Owner is `SurfaceCutGraph::canonical_candidate`. Defer behind the mechanical first red; do not bundle into CB8. |
| 371 | RED | Upstream-blocked by ordinal 366. Underlying contract remains unmeasured. |
| 372 | RED | Upstream-blocked by ordinal 366. Underlying contract remains unmeasured. |
| 373 | PASS | Synthetic-only partial evidence, zero gate credit. Mechanical zero-unbound singularity evidence remains owed. |

No report-only result earns acceptance credit.

---

## 8. AV6 — candidate and accounting reconciliation

- `M3-CP4c3-TB5-CAND-01`: **RESOLVED as the first-failure surface.** TB6 passes the prior regular vertex-11 silent seed drop and reaches vertex 30. This does not close ordinal 366.
- `M3-CP4c3-TB5-REV-CAND-01`: **RESOLVED as an exactness violation.** The CB6 world-space double round-trip is absent from the current decision path. The correction exposed/reintroduced a distinct semantic problem: branch correspondence was substituted for one geometric datum.
- `M3-CP4c3-TB3-R1-CAND-01`: **ACTIVE / CAUSE CONFIRMED.** Current source proves per-cell-representative election; Amendment 17 is not satisfied.
- `M3-CP4c3-TB6-CAND-01`: **ACTIVE / OWNER PROVED.** Diagnostic loss occurs in production failure projection/DTO, not resolver recording.
- `M3-CP4c3-TB4-DIAG-CAND-01`: invalid ordinal-370 witness precondition is **RESOLVED** by CB7/TB6.
- `M3-CP4c2-TB-X2-R8-CAND-02`: **ACTIVE / genuine product red**, now statically localized to the missing closed-empty-network branch in `SurfaceCutGraph::canonical_candidate`.
- `M3-CP4c2-TB-X2-CAND-04`: sphere localization remains active/deferred; no semantic fix.
- `M3-CP4c2-TB-X2-R10-CAND-01`: saturation quality/coverage finding remains active/deferred.
- `M3-CP4c3-DEFN-R1-CAND-01`: remains partial until the mechanical witness publishes zero unbound prescribed singularities.

Accepted ordinals 1–365 remain 365/365 green. CP4c-3 is unaccepted, so no accepted-green regression event or recurrence is added. Stable accounting remains **44 / 14 / 30**; debt **5**; semantic packages **73**.

---

## 9. AV7 — one bounded successor

Freeze exactly one successor:

> **`M3-CP4c-3-CB8` — exact single-authority vertex transit + production transit audit + selector 374; Code + Build only, runtime-free.**

The frozen measures are in `Architecture_M3_CP4c3_CB8_Code_Build_Plan.md`.

The semantic owner is `resolve_field_vertex_transit` in `src/geometry/SurfaceCellTracing.cpp`. The supporting observability owner is `RemeshPipeline.cpp::network_failure_locus` plus `SurfaceCellFailureLocusDiagnostics`. CB8 must not touch the sphere path, `SurfaceCutGraph::canonical_candidate`/ordinal 370 semantics, saturation policy, barrier semantics, `FaceInterior`, tolerance policy, or accepted selectors.

### Expected next-TB discriminator

The next immutable artifact-only TB must use selector 374 and preserve first-red semantics. At ordinal 366:

- success is advancement beyond vertex-30 `VertexTransitSectorUnresolved` with the exact single-datum invariant independently visible; or
- if ordinal 366 remains red, the production failure must serialize enough exact transit-state authority to prove whether every state projection derived from the one datum and why the unique-sector election failed.

After the first-red verdict is fixed, every remaining ordinal through 374 executes once report-only with zero gate credit. No rebuild, repair, fixture/source/test/selector mutation, or benchmark is authorized in that TB.

---

## 10. Prohibited shortcuts retained

- no first/lowest/ordered candidate selection;
- no angular-nearest or field-representative tie-break;
- no tolerance/epsilon/fuzzy sector boundary;
- no world-space float round-trip reaching a topological predicate;
- no substitution of `nextPairing->direction` for the single continuation datum;
- no claim that `signedLift` alone continuously transports an arbitrary geometric ray;
- no `FaceInterior` exclusion/cardinality change;
- no barrier widening or crossing;
- no sphere or ordinal-370 semantic repair in CB8;
- no selector reorder/removal; selector 374 is append-only over byte-frozen 373;
- no acceptance claim from compile or report-only evidence.
