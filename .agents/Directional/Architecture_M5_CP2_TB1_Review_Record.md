# M5-CP2-TB1 Independent Review Record

**Turn:** `M5-CP2-TB1-REV`
**Canonical turn:** Independent Review + Plan / runtime-free
**Reviewed report:** `Architecture_M5_CP2_TB1_Artifact_Only_Test_Benchmark_Report.md`
**Reviewed runtime:** run/job `35504249045 / 106061268740`; result/log artifacts `10603438015 / 10603642400`
**Reviewed candidate:** package `10601978228` / semantic source `0798547dedd8be05f9cd7a096b07e6bd94755316`
**Prior accepted runtime authority:** package `10600353027` / source `8a86710dd33d7b6cb9a077aef738577e4075b5f7` / selector430 **430/430**
**Decision:** **TB1 evidence UPHELD; candidate PROMOTED; `M5-CP2` CLOSED / ACCEPTED as the typed-relation-failure mechanism checkpoint; no produced-witness debt discharged**
**Planning successor:** `M5-CP3-CB1` under `Architecture_M5_CP3_CB1_Direct_Production_Exit_Plan.md`

## 1. Scope and review boundary

This Review independently re-opens the immutable CP2 package/runtime bytes and source rather than inheriting the EXEC report's conclusions. It adjudicates the five typed relation failures, accepted-selector assertion relocation, package promotion and CP2 checkpoint closure. It executes **no Directional binary** and changes no product, test, fixture, selector, benchmark, CMake or build semantics.

M5 milestone closure is not being adjudicated. All four M5 produced-witness debts remain owned by CP3. Direct/draft/factory witnesses receive mechanism credit only.

## 2. Immutable evidence independently re-derived

### 2.1 Compile/package authority

Candidate artifact `10601978228` independently downloads to SHA-256
`ad2e502db60d94c275769616edf5555d12abd87499c6cf3987cdafbd458d2f0b`. Its self-excluding root manifest verifies **28/28**. The packaged source identifies exact semantic source
`0798547dedd8be05f9cd7a096b07e6bd94755316`; its source archive SHA-256 is
`32ea6af52c6bc3e9a626dc7cecb3cec67b8ae46fdfbcacd4385ca2392ba5a308`.
Compile run/job `35500960779 / 106052541163` is successful; package metadata records build/preflight exits `0 / 0`, clean source-status receipts, exact backend **GMP**, explicit GMPXX+GMP linkage, all eight standard targets, and `runtimeExecution=false`.

The prior accepted package `10600353027` independently re-hashes to
`cdc0cb798e6b117727ddde0dbfa5008d2a8140c709eeafb0af66872c5c7ae6b0`; its root manifest verifies **28/28** and its semantic source is `8a86710dd33d7b6cb9a077aef738577e4075b5f7`. Accepted-to-candidate semantic source changes are confined to:

- `include/directional/geometry/SurfaceCellTracing.h` — three appended typed error codes;
- `src/geometry/SurfaceCellTracing.cpp` — checked relation-table/edge invariants;
- `tests/SurfaceCellTransitionQuotientTests.cpp` — focused independent negative oracles and accepted-row assertion updates.

No selector, fixture, benchmark or build-system semantic byte changes in that source transition.

### 2.2 Runtime authority

TB1 run/job `35504249045 / 106061268740` is successful. Review independently downloads and hashes:

- result artifact `10603438015`: `a2b516bd63ea477d22e34631b2714e6c427b92014e86005e605100acaf0657a6`;
- diagnostic artifact `10603642400`: `5ee4edac0b72507522268b825085facdd9ec7cc558168c73e1ba325bd6f824ec`;
- focused ledger: `9dcadb661cadff5e1b523877ba96bd00ad6a67cafa3cce00865404f950d9f2ee`;
- selector ledger: `2ab6db5febdab40606138739a0b01520f6671061ef9420a240fc7d543a342656`;
- semantic summary: `26b6ea33c46305e04c8a5462059accc8182444bf840374a8aae7f784ec80a888`;
- execution boundary: `d2c4d6bd725962669865f53751922df48df292dfa78d1acfe86051d4c08b8947`;
- immutability receipt: `1166472dedb2c70bbcbf591c0808ee5d91176cd03f948015d64311e9e8730de7`.

The focused ledger independently sums to **7/7 PASS / 0 RED**. The selector ledger independently sums to **430/430 PASS / 0 RED**. Every one of the **437** fresh exact-filter processes selected exactly one test and skipped zero. Raw GoogleTest receipts name the intended seven focused identities and show one selected PASS each.

Benchmark execution is exactly **0**. The execution boundary records configure, compile, relink, generated discovery, package repair, mode repair and source/test/fixture/selector mutation all **false**. Candidate-package, packaged-source and execution-view byte+mode censuses are identical before/after, and the package manifest verifies **28/28** after execution.

### 2.3 Cumulative selector authority

Review independently re-hashes selector430 to exactly **430 LF rows** at
`1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`. Its first427 rows independently hash to
`f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`, byte-identical to selector427. Routing is still 430 unique identities in selector order with owner census **31 authority-kernel / 283 producer / 75 completion / 41 validation**.

## 3. Typed failure matrix and non-vacuity

The candidate's checked `SurfacePhaseFrontProduct::make(...)` owns all five frozen CP2 classes without repair:

| Class | Independent discriminator | Checked outcome |
|---|---|---|
| missing | independently derive an absent carrier identity, prove it is absent, then replace one periodic edge reference | `MissingPeriodicRelationOwner` |
| duplicate | append an exact relation value duplicate, independently verify carrier identity, repeat under relation-table reversal | `DuplicatePeriodicRelationId` |
| conflicting | preserve canonical carrier ID while changing only action/value, assert same ID and different action, repeat under table reversal | `ConflictingPeriodicRelation` |
| nonreciprocal | prove the reverse carrier/transport relation first, then alter one route-step transport while preserving carrier identity | `NonReciprocalPeriodicRelation` |
| representation-renumbered | append a distinct valid unused relation, prove baseline checked-product construction succeeds, then retarget only the paired periodic-edge relation references; repeat under table reversal | `RepresentationRenumberedPeriodicRelation` |

The negative oracle does not ask production `periodic_relation_id(...)` for the expected route answer. It independently converts canonical-route steps into carrier-step identities, canonicalizes simultaneous reversal, and only then constructs the strong `PeriodicRelationId` from those independently derived carriers. That is the primitive strong-ID operation frozen §6 permits.

The implementation itself rejects relation-table ID/value corruption before edge validation, resolves periodic owners by canonical ID rather than table position, and checks reciprocal paired-edge relation identity, reversed route and lattice/rotation/scale action compatibility. Deleting any one of these checks changes at least one focused negative outcome. The seven green rows are therefore discriminating rather than merely traversal receipts.

## 4. Accepted-row relocation audit — `M5-CP2-CB1-OBS-01`

Review independently compares prior accepted source `8a86710d...` with candidate `0798547d...` and verifies the corrected CB report mapping.

- selector row **221**, `PeriodicRelationOwnersSurviveContainerReorderingBeforeMaterialization`, is positive-only before CP2 and its body is unchanged;
- row **296**, `DuplicatePeriodicRelationIdentityRejectsAtCheckedFactory`, preserves the exact duplicate typed outcome and strengthens the witness with an independent carrier check plus reversed relation-table repetition;
- row **304**, `UnknownPeriodicRelationOwnerRejectsAtCheckedFactory`, narrows broad `InvalidPeriodicRelationOwner` to the frozen exact `MissingPeriodicRelationOwner`, with independently derived absent identity;
- row **226**, `TamperedFullPeriodicTransformIsRejected`, preserves the key discriminator that action/value is altered while canonical relation ID stays equal, but moves rejection from a downstream materializer-string assertion to exact typed `NonReciprocalPeriodicRelation` at the checked phase-front product boundary.

The row226 relocation is **accepted as a strengthening, not a loss of accepted behavior**. The old row passed a malformed draft into `materialize(...)`; that helper first calls checked phase-front construction. Under CP2, the malformed relation/edge pair is no longer constructible through that checked API, so the former downstream `InvalidPeriodicFrontTransport` locus is unreachable for this input. The stable semantic requirement was rejection of an identity-preserving transform tamper; the candidate rejects it earlier, at the newly frozen authority boundary, with a more specific typed outcome. TB1 proves row226 and the dedicated nonreciprocal oracle green together under selector430.

`M5-CP2-CB1-OBS-01` is therefore **DISCHARGED / ACCEPTED-BOUNDARY RELOCATION VERIFIED / NON-STABLE**. No accepted-green loss occurred and no stable regression event is created.

## 5. CP2 adjudication, promotion and accounting

Frozen §6/§9 CP2 requires typed missing / duplicate / conflicting / nonreciprocal / representation-renumbered failure at the named checked authority boundary with independent negative oracles and no repair. Source and runtime evidence satisfy that mechanism checkpoint.

**Decision:** promote package `10601978228` / source `0798547dedd8be05f9cd7a096b07e6bd94755316` as the current accepted runtime authority under the unchanged selector430 **430/430**. `M5-CP2` is **CLOSED / ACCEPTED**.

This promotion grants **no produced-witness debt credit**. The CP2 focused rows use direct/draft/factory authority, not the row408-class produced torus subject required by frozen §8.2. Stable regression accounting remains **49 events / 14 categories / 35 recurrences**; produced-witness debt remains **5** (four M5-owned, one M6-owned).

## 6. Prior obligations

- `M5-CP2-CB1-OBS-01` — **DISCHARGED** here by byte-level accepted-row comparison and row226 semantic-boundary adjudication.
- `M5-CP1-TB1-R3-REV-OBS-01` — **DISCHARGED AS A GOVERNANCE GAP** here. Frozen M5 authority now contains the explicit publication sequence in §13: selector430 remains the byte-frozen prefix through CP3 implementation/first execution; CP3-TB1-REV must pre-commit the exact successor selector bytes, SHA-256 and owner census before a separate publication Code + Build turn; publication then receives a complete artifact-only selector run and Review before M5 closure.
- `M5-CP1-TB1-PREFLIGHT-REV-OBS-01` — **CARRIED / owner `M5-CP3`**. The new CP3 plan gives produced tests distinct `M5CP3.Produced...` names, but actual produced runtime must prove the mechanism/produced split and may not borrow direct/helper credit.
- `M5-DEFN-REV-OBS-01` — **CARRIED / owner final M5-CP3 Review**. Frozen §13 now states the reconciled M5 exit theorem, but final closure still must verify every conjunct against direct-production evidence.
- `M5-CP2-TB1-REV-OBS-01` — **NEW / OPEN / owner `M5-CP3-TB1-REV` / NON-STABLE**. Before selector publication, freeze the exact successor selector content/order, LF SHA-256, selector430 prefix hash and complete owner census from reviewed-green CP1/CP2 mechanism plus CP3 production identities. The publication CB may publish only those pre-committed bytes.

Nine already-reviewed CP1/CP2 mechanism identities are currently outside selector430: two `SurfaceCellsPhase10` identity tests, four `M5CP1.*` certificate/aggregation tests, and the three new CP2 conflicting/nonreciprocal/representation-renumbered factory tests. Frozen §13 carries those exact identities into the CP3 pre-publication focused gate.

## 7. Exact successor — `M5-CP3-CB1`

The sole successor is Code + Build `M5-CP3-CB1`, frozen in
`Architecture_M5_CP3_CB1_Direct_Production_Exit_Plan.md`.

It must make the accepted row408-class one-region torus production path publish genuine periodic relation authority and author the direct-production M5 exit witnesses. It is compile/package only with mandatory GMP and `runtimeExecution=false`; selector430 is byte-frozen. Runtime credit, publication pre-commitment and milestone closure remain later turns.

The successor must stop rather than use a direct helper, synthesize the positive production relation in the test, weaken the `>=2` produced relations / `>=2` owned periodic edges discriminator, pull M6 A5 occurrence authority backward, reintroduce ordinal relation identity, or publish a selector before Review pre-commits its exact bytes.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | selector430 `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`; first427 `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`, byte-identical to selector427. |
| Decisive claims independently re-derived | candidate/prior package hashes and manifests, exact semantic diff, compile boundary, 437-process runtime ledger, postflight immutability, five failure classes, accepted rows 221/226/296/304, routing owner census. |
| Non-vacuity checked | every CP2 negative changes one semantic fact with an independently derived precondition; duplicate/conflict/renumbering repeat under storage reversal; nonreciprocal preserves carrier ID while corrupting transport; row226 preserves ID while changing action. |
| Prior obligations discharged/carried | CP2-CB1 observation discharged; selector-publication governance gap discharged into frozen §13; CP1 preflight mechanism/produced split and M5 exit confirmation carried to CP3; new exact publication precommitment observation owned by CP3-TB1-REV. |
| Stable accounting | **49 / 14 / 35**, debt **5**; accepted package `10601978228` / source `0798547d...` under selector430 **430/430**. |
| New candidates/obligations recorded | no regression candidate; `M5-CP2-TB1-REV-OBS-01` records the exact selector-publication precommitment requirement. |
| ORIENTATION currency line | `M5-CP2-TB1-REV`, 2026-09-20 UTC. |
| ORIENTATION §3 / §4 / §7 / §8 | §3 and §7 updated; §4 retains the same torus state because no produced debt is discharged; §8 has no new defect pattern and remains unchanged. |
| CHANGELOG | CP2 Review / promotion / closure entry added. |
| ROADMAP | M5 CP2 marked CLOSED / ACCEPTED; CP3 direct-production exit is next. |
| Selector manifest | selector430 current-package note updated for CP2 promotion; selector bytes/order/census unchanged. |
| LESSONS | existing lesson 171 / RP-02 non-vacuity and accepted-test-authority discipline applied; no new general pattern. |
| Consolidation under CLEAN_UP_POLICY | CP2 CB1 plan/report and consumed TB1 plan folded into `M5_CP2_Closure_Record.md`; superseded CP1 R3 runtime/review records folded into `M5_Consolidated_Record.md` with exact filenames and line counts; CP2 TB1 runtime report retained as current runtime authority. |
| Successor frozen | exactly one: `M5-CP3-CB1`; falsifiers/stop rules are in `Architecture_M5_CP3_CB1_Direct_Production_Exit_Plan.md`. |
| Turn boundary held | runtime-free Review; no product/test/fixture/selector/benchmark/build semantic mutation. |
| review_check.py boundary | **PASS — ALL CHECKS PASSED**; no product/test/fixture/build mutation, no selector mutation, selector430 matched declared hash, durable markers preserved. |
| `STATUS` lifecycle maintained | entry/resume beacon is `M5-CP2-TB1-REV / IN_PROGRESS`; final COMPLETE beacon is the final repository write after durable closeout and cleanup. |
| Pushed to origin, branch in sync | verified Review documentation patch is applied/pushed on the configured working branch; branch authority is re-read after workflow-originated writes and no unapplied Review documentation delta remains before the final STATUS beacon. |
