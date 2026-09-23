# M5-DEFN-R1 — `G4-B004` M5-Half Exit Reconciliation Definition Record

**Turn:** `M5-DEFN-R1`
**Date:** 2026-09-23 UTC
**Boundary:** runtime-free definition only; no product/test/fixture/selector/CMake/benchmark mutation, compile, or Directional runtime
**Disposition:** **A — ACCEPTED ROWS ALREADY SATISFY THE FOCUSED M5 WITNESS / §13.1 CONJUNCT 8 FROZEN / M5 CLOSURE HELD PENDING `M5-DEFN-R1-REV`**

## 1. Entering authority and exact question

`M5-CP3-TB2-REV` accepted selector448 and §13.1 conjuncts 1-7, but its reviewing-agent addendum correctly held M5 closure because `Architecture_M4_DEFN_Frozen_Definitions.md` §11.2 separately assigns M5 the **focused positive multi-isolation quotient relation/certificate witness**. `REORIENTATION_PLAN.md` §9 repeats that ownership. M4 gives M6 the different, later obligation: representative occurrence/embedding/verifier consumption of the M5-produced authority exactly once with independent verification.

This turn therefore answers one bounded definition question: what is the minimum M5-side meaning of “positive multi-isolation quotient relation/certificate witness”, and does accepted selector448 already prove it?

The entering runtime authority is unchanged: CB20 package/source `10771899191 / cef1c6ee26ca6fb6791f0e80a66f9b0dc441e0f1`; TB2 run/job `35913334490 / 107358491487`; accepted selector448 SHA-256 `70ff08601bf244fcb4883e5d0601d5e7a3a44f52a8e855544a065c6ca5c75789`; exact selector430 prefix SHA-256 `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`; owner census 32/300/75/41; result evidence 917/917. This definition turn executes none of those binaries.

## 2. Frozen meaning of “positive multi-isolation”

### 2.1 Minimum M5 discriminator

For the **focused M5 producer witness**, “multi-isolation” means **multiple isolation-sheet authorities joined by certified isolation relation authority**, not “at least two distinct isolation seams/relations in one representative quotient graph”. The minimum discriminator is:

1. a real `build_surface_cell_network(...)` producer result with `SurfaceCellProducerDisposition::Produced`;
2. one produced topology region whose authoritative support spans **at least two distinct `IsolationSheetId` values**;
3. at least one internal isolation seam joining those distinct sheet authorities;
4. a checked immutable `SurfaceIsolationSeamTransportCertificate` that explicitly binds the owning topology region, seam, transition, source-face pair, distinct endpoint sheets, and reciprocal Forward/Reverse quarter-turn transport;
5. successful materialization that consumes the emitted internal-isolation certificate **exactly once**.

A producer-built focused fixture may supply the source component/sheet labels as input authority. That does not turn the output into a direct/helper construction: the witness still enters the real network producer, requires `Produced`, and credits only the relation/certificate authority emitted by that producer. M4-DEFN §11.2 explicitly calls M5’s half **focused** and assigns the **representative** product path to M6.

### 2.2 Why the minimum is sheets, not seams

The primary authorities separate the two stages:

- M4-DEFN §11.2 says M5 proves **production** of positive multi-isolation authority with explicit owners/certificate, while M6 proves representative occurrence/embedding/verifier consumption.
- `REORIENTATION_PLAN.md` §9 repeats the same M5/M6 split.
- `DESIGN.md` §14 keeps exact selected relation/certificate authority in M5 and occurrence/quotient/embedding/independent verification in M6.
- AR-06 requires producer-owned canonical relation/certificate authority so the downstream verifier verifies a proof instead of reconstructing one.
- `SurfaceIsolationSeamTransportCertificate` itself rejects `SameSheet` and carries both endpoint sheet IDs plus region/seam/transition/face/transport ownership. One valid positive certificate therefore already certifies a relation between two different isolation authorities.
- `tests/TESTING_STRATEGY.md` §8.4 places **multi-isolation relation graphs** under occurrence quotient/materialization. Requiring multiple seams/relations in one graph is therefore representative M6 graph complexity, not the minimum focused M5 production discriminator.
- The repository’s own ungated `MultiIsolationMaterializationRetainsAllLocalSheets` uses the term “multi-isolation” for retained lineage with more than one isolation sheet on the same one-seam `split_isolation_fixture()`.

Accordingly, the ≥2-seam interpretation is not adopted as the M5 minimum. M6 may and should exercise multi-relation/multi-isolation graph complexity on the representative occurrence path; that does not retroactively expand the M5 focused producer requirement.

`SelectedRelationPathCertificate` is not silently redefined to carry an isolation seam. Periodic/hard-rail selected paths and isolation-seam transport certificates remain distinct typed authorities. `G4-B004` is satisfied on the dedicated isolation-seam certificate surface.

## 3. Accepted selector448 census

| Ordinal | Identity | Classification | Credit |
|---:|---|---|---|
| 183 | `SurfaceCellIsolationSeamCertificateAuthority.DuplicateIsolationSeamCertificateIsRejected` | producer-built split-isolation fixture; negative duplicate-certificate tamper | supporting non-vacuity |
| 184 | `...MissingIsolationSeamCertificateIsRejected` | producer-built; negative missing-certificate/bijection tamper | supporting non-vacuity |
| 185 | `...NonreciprocalIsolationSeamCertificateIsRejected` | producer-built; negative transport tamper | supporting non-vacuity |
| **186** | `...ReciprocalIsolationSeamCertificateMaterializes` | **producer-built positive**; exactly one certificate joins distinct sheets; reciprocal transport; materialization consumes one | **positive conjunct-8 witness** |
| 187 | `...WrongOwnerIsolationSeamCertificateIsRejected` | producer-built; negative region/owner tamper | supporting non-vacuity |
| 188 | `...WrongSheetIsolationSeamCertificateIsRejected` | producer-built; negative sheet-authority tamper | supporting non-vacuity |
| 237 | `SurfaceCellsPhase10.ExactAdjacentCrossSheetEdgeIsInternalTopologyRegionIsolationSeam` | producer-side topology classification; positive seam classification, no materialization proof | support only |
| **239** | `SurfaceCellsPhase10.ExactReciprocalTransportCrossesSourceAdjacentIsolationSeam` | **producer-built positive**; `Produced`; one region spans >1 sheet; explicit owner/seam/transition/distinct-sheet/reciprocal certificate; successful materialization; consumed certificate count equals produced count | **strong positive conjunct-8 witness** |
| 240 | `...HardFeatureCannotBeReinterpretedAsInternalIsolationSeam` | negative classification separation | support only |
| 242 | `...NonReciprocalSourceAdjacentIsolationSeamFailsClosed` | producer-level negative reciprocal-transport control | support only |
| 253 | `...SameSheetInternalEdgeIsNeitherBoundaryNorIsolationSeam` | negative same-sheet classifier control | support only |
| 254 | `...TopologyRegionIsolationSeamIsInvariantToFaceRowEnumeration` | producer-side identity/invariance support | support only |

Rows 186 and 239 were both in accepted selector448 and therefore executed fresh and green in TB2. Row 239 is the strongest single positive because it explicitly checks produced disposition, region/seam ownership, transition, distinct sheets, reciprocal transport, multi-sheet cell scope, materialization, and exact consumed-certificate count. Row 186 independently proves the checked certificate/materializer path on the focused fixture. Rows 183-185 and 187-188 make the certificate authority non-vacuous under missing/duplicate/nonreciprocal/wrong-owner/wrong-sheet corruption.

Two source identities carry **zero acceptance credit** here because they were not executed in the accepted gate:

- `SurfaceCellTransitionQuotient.MultiIsolationMaterializationRetainsAllLocalSheets` — useful terminology corroboration only;
- `SurfaceCellsPhase10.ExactCommittedTorusDoesNotTreatIsolationSeamAsBoundedDiskBoundary` — useful future representative-path census only.

No dormant CB14 identity, direct helper, periodic torus relation, or never-executed source identity is credited.

## 4. Disposition A — §13.1 conjunct 8

Disposition **A** is frozen. Accepted selector448 already proves the M5 half of `G4-B004`.

`Architecture_M5_Frozen_Definitions.md` §13.1 now gains conjunct 8 requiring the exact focused discriminator in §2.1 above. Accepted positive evidence is rows **186 and 239**; rows **183-185 and 187-188** are the typed owner/certificate falsifier family. No `M5-CP4` is required, M4-DEFN §11.2 remains correct and is not amended, and project produced-witness debt remains **1**, the already M6-owned closed-complex `G4-B002` debt.

This turn freezes the conjunct; it does **not** independently Review its own decision. M5 closure remains held until `M5-DEFN-R1-REV` independently re-derives the reading and accepted evidence. If that Review accepts it, the closure record may finally mark M5 CLOSED / ACCEPTED and the exact successor becomes `M6-DEFN`.

## 5. Observation disposition

`M5-CP3-TB2-REV-OBS-01` is **DEFINITION-ADJUDICATED / REVIEW-PENDING**. The semantic gap that created it is resolved by disposition A, but the closure-blocking observation is not marked fully discharged until the independent successor Review confirms the frozen reading and the accepted-row proof.

The partially withdrawn `M5-DEFN-REV-OBS-01` discharge is resolved the same way: its risk was real, and the missing external exit obligation is now explicitly present as §13.1 conjunct 8. Final discharge belongs to `M5-DEFN-R1-REV`, not this definition turn.

Stable accounting remains **51 events / 14 categories / 37 recurrences**. Project produced-witness debt remains **1**, M6-owned. No new stable regression event, category, recurrence, or produced-witness debt is created.

## 6. Exact successor and falsifiers

Exact successor: **`M5-DEFN-R1-REV`** under `Architecture_M5_DEFN_R1_G4_B004_Review_Plan.md`.

The Review must refuse M5 closure if any of these falsifiers holds:

1. primary authority actually requires two or more distinct isolation seams/relations for the **M5 focused** witness rather than multiple sheet authorities;
2. selector448 ordinals 186 or 239 were not executed and accepted under the immutable TB2 authority;
3. either positive row is direct/helper output rather than a real `build_surface_cell_network` `Produced` product;
4. the positive authority does not bind explicit owner/seam/transition/distinct-sheet/reciprocal certificate data or does not prove exact materializer consumption;
5. selector448/prefix hashes, runtime acceptance, stable accounting, or project debt differ from the stated authority;
6. this turn mutated product/test/fixture/selector/CMake/benchmark semantics, compiled, or executed Directional runtime.

If none fires, Review may mark conjunct 8 accepted, discharge the merged closure observation, finalize M5 closure, and route to `M6-DEFN`. M6 then owns representative multi-relation occurrence/embedding/verifier consumption without reinterpreting M5’s focused minimum.

## 7. Process and boundary evidence

The turn initially performed several small direct authority reads before explicitly declaring the mandatory snapshot read mode. That repeats the existing `LESSONS.md` 152 setup-order process pattern. Piecemeal inspection stopped before substantive adjudication; decisive cross-file analysis used exact source-snapshot run `35924810882`, artifact `10777779431`, event/source SHA `56a6e667c731bc78163b751554d5b8f4148f430f`, artifact digest `sha256:2e68c44c393f8696799c3a6d9e3adbe14c7322a6886a596fc42780cb721e59ec`, and verified all 5,302 snapshot file hashes. This is process-only evidence and creates no product regression.

The tool-call ledger is reported as **partial/unknown** because exact turn-local accounting was not maintained from the first invocation. No calls were spent reconstructing a number after the fact, as required by the conservation policy. This bookkeeping defect does not contribute semantic evidence.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | selector448 `70ff08601bf244fcb4883e5d0601d5e7a3a44f52a8e855544a065c6ca5c75789`; first430 `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`; exact 448-line accepted manifest unchanged |
| Decisive claims independently re-derived | M4-DEFN §11.2, REORIENTATION §9, DESIGN §14 M5/M6, AR-06, current certificate/product contracts, focused fixture path, selector448 candidate census and occurrence-quotient testing boundary |
| Non-vacuity checked | positive rows 186/239 plus missing/duplicate/nonreciprocal/wrong-owner/wrong-sheet rows 183-185/187-188; ungated identities explicitly receive zero acceptance credit |
| Prior obligations discharged/carried | merged `M5-CP3-TB2-REV-OBS-01` / `M5-DEFN-REV-OBS-01` is definition-adjudicated but carried to `M5-DEFN-R1-REV` for independent closure discharge |
| Stable accounting | unchanged 51 events / 14 categories / 37 recurrences; project debt 1 M6-owned; accepted runtime package/source unchanged |
| New candidates/obligations recorded | no stable candidate; no new debt; M6 retains representative `G4-B004` consumption as already assigned |
| ORIENTATION currency line | updated to `M5-DEFN-R1`, 2026-09-23 UTC |
| ORIENTATION §3 / §4 / §7 / §8 | current M5 state and torus wording corrected; §7 makes Review next and M6 deferred; §8 records resolution of the closure-census pattern and repeats the existing setup-order instance without creating a new category |
| CHANGELOG | M5-DEFN-R1 disposition A entry added to agent and root changelogs |
| ROADMAP | M5 `G4-B004` half marked definition-adjudicated by A; M5 closure remains held pending Review; debt unchanged |
| Selector manifest | N/A — no selector bytes/status/order changed by this turn |
| LESSONS | N/A — existing 168 (external-obligation census), 176 (durable-ledger edit discipline), and 152 (snapshot setup order) cover the reusable lessons |
| Consolidation under CLEAN_UP_POLICY | previous TB2 Review (230 lines) and consumed M5-DEFN-R1 plan (60 lines) folded into `M5_Consolidated_Record.md` §4.32/index and removed; current TB2 runtime report, new definition record, new Review plan, closure/frozen authority and selector remain live |
| Successor frozen | exactly `M5-DEFN-R1-REV`; falsifiers are §6 and `Architecture_M5_DEFN_R1_G4_B004_Review_Plan.md` |
| Turn boundary held | runtime-free definition only; no product/test/fixture/selector/CMake/benchmark mutation, compile, package or Directional runtime |
| `review_check.py boundary` | **PASS** on final uncommitted definition diff; no product/test/fixture/build or selector mutation; selector448 and selector430 match declared hashes; durable markers preserved |
| `review_check.py ledgers` | **PASS** for exact snapshot-mirror committed delta against local baseline `5337217f...`; all four append-only ledgers show no >10% shrink |
| `STATUS` lifecycle maintained | entry beacon `M5-DEFN-R1 / IN_PROGRESS` started `2026-09-23T21:48:36Z`; final `COMPLETE -> M5-DEFN-R1-REV` is reserved as the last repository mutation |
| Pushed to origin, branch in sync | durable documentation transport and cleanup must complete before the final `STATUS` write; no unpublished semantic source state is permitted |
