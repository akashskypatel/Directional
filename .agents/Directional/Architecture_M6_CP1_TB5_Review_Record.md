# M6-CP1-TB5 Review Record

**Turn:** `M6-CP1-TB5-REV`
**Review boundary:** runtime-free; no Directional executable, build, benchmark, test, fixture, selector, or product source mutation
**Reviewed candidate:** artifact/source `10879581622 / 82b86a285292379cfd92cdc4e10d74181b38f1e8`
**Reviewed runtime:** run/job `36172157965 / 108194136911`; result/log `10880392759 / 10880502706`
**Decision:** TB5 recovery **ACCEPTED**; candidate **PROMOTED as current reviewed runtime authority**; `M6-CP1` **REMAINS OPEN** on one static A5-product acceptance precondition
**Exact successor:** `M6-CP1-CB6`

## 1. Independent evidence re-open

Review independently re-opened the immutable CB5 package and TB5 result/log bytes rather than relying on the EXEC summary.

- candidate provider/download ZIP SHA-256: `578845a2135ef2296e982e8bac9a378b7659d2968aa9ab5b2702f841288d57c6`;
- candidate root `SHA256SUMS`: **28/28**, manifest SHA-256 `ca6af967b3abb6002ca0231a97873afef588348b9ed4a299e0eef59e28bf299e`;
- exact packaged source archive: `0015832fb634b100419ac6c30352804152ea4fa2df665b1d059b3b06fab1425c`, source `82b86a285292379cfd92cdc4e10d74181b38f1e8`;
- all five packaged source-status receipts are empty; preflight/build exit `0/0`; package records `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `exactArithmeticBackend=GMP`, and links both GMPXX and GMP;
- selector449: 449 rows, SHA-256 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`;
- routing449: 449 rows, SHA-256 `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707`.

TB5 result artifact `10880392759` re-verifies at SHA-256 `71095935dedf52277df946e05cf181713ecb0ebe0842aa91f35ab9b65dd91216`; its self-excluding manifest is **933/933**, manifest SHA-256 `54f088056d59c0876a068bb8ffa0de997636109500ea829c856286471fa3451e`, and execution-ledger SHA-256 `06c1d0166ac0165d4a931c10d2aa4f95b433b05f7a40217f7c8003de3d460a11`. Diagnostic artifact `10880502706` re-verifies at SHA-256 `0a41be59d2c31138623e770eb6fb30202fa6e511aad691343f40cfee5e3e29df`.

The exact Review snapshot is run/artifact `36175121088 / 10882675366`, source `c54d9a87c35ef69e9ca365004480341edb12057e`, provider SHA-256 `164dd2c61873b890986d15908cb2c1fbf16017c058014f238b70c0dadde23e31`, embedded archive SHA-256 `f4f140fb20982037528c60374630fc311be7d5c4608604bd01d48a67eaf6d714`, **5314/5314** source-manifest rows. The candidate and Review snapshot are byte-identical for `RemeshPipeline.h`, `RemeshPipeline.cpp`, the focused M6 test source, selector449 and routing449; intervening differences are control/documentation only.

## 2. Mechanical result upheld

The EXEC disposition is mechanically exact: **7/7 focused + 449/449 selector = 456/456 PASS**. Every process selected exactly one identity with zero skips, crashes or selection mismatches. Benchmark count is zero. No configure, compile, relink, generated discovery, package/mode repair, source/test/fixture/selector mutation, retry-after-runtime-start or gate watchdog occurred. Pre/post package, source and execution-view byte/mode censuses are equal; the candidate ZIP, packaged source archive, selector and routing hashes are unchanged.

The seven focused identities all PASS. Review additionally checked the full TB4 loss differential directly in the ledger: all 21 newly lost accepted selector ordinals recover, row140 stays green, selector 186/214/239 stay green, and the torus pair-swap plus 444/446/448 all recover. No raw gate log contains `OccurrenceInvalidCornerAuthority`, `MissingIsolationSeamEquivalenceAuthority`, `InvalidIsolationSeamEquivalenceAuthority`, or `QuotientReciprocalSideAuthorityMismatch`.

## 3. Formal regression recovery

TB5 satisfies the previously frozen recovery conditions without repricing history.

1. **TB1 `CROSS_TEMPORARY_ITERATOR_RANGE` — RECOVERY PROVED.** Its iterator-range symptom is absent and the pre-registered full selector449 condition is now **449/449** in one fresh immutable gate. The historical stable event remains counted.
2. **TB2 `VALIDATION_ORDER_SHADOWING` — remains RECOVERY PROVED.** Row140 continues to PASS with the accepted typed failure contract.
3. **TB3 `RP-01 / AUTHORITY_DOMAIN_CONFLATION` recurrence — RECOVERY PROVED.** The direct multi-isolation and accepted 186/214/239 witnesses remain green, while the previously still-blocked pair-swap and 444/446/448 rows are now green as well.
4. **TB4 `RP-01 / AUTHORITY_DOMAIN_CONFLATION` recurrence — RECOVERY PROVED.** All 21 accepted-prefix losses recover under the bounded CB5 support-vs-seam correction, with no residual downstream family requiring a split.

Recovery closes the current mechanisms; it does not delete historical evidence. Stable accounting therefore remains **55 events / 16 categories / 39 recurrences**. Project produced-witness debt remains **1**, the M6-owned closed-complex `G4-B002` subject; CP1 mechanism/runtime recovery cannot discharge the CP3 production-proof obligation.

## 4. Promotion decision

Review promotes CB5/TB5 artifact/source `10879581622 / 82b86a285292379cfd92cdc4e10d74181b38f1e8` as the **current reviewed M6 runtime authority under unchanged selector449 449/449**. This supersedes M5 package `10814505512` as the current runtime package while preserving selector449 membership/order/hash and all M5 closure history.

This promotion is **not** CP1 acceptance. One static public-product obligation remains.

## 5. CP1 acceptance is held by the legacy A5 product surface

Frozen M6 §3.2 publishes complete wedge authority (`CornerWedgeSheetSet`, ordered `(face,sheet,chart)` bindings, labelled placement provenance, exact support/region and wedge isolation evidence). It does not publish an unlabelled representative sheet, first-binding chart, or duplicate unlabelled lattice record as semantic A5 authority.

Exact candidate source still exposes three legacy `SurfaceOccurrence` members:

- `chart`, populated from `wedgeBindings.front().chart`;
- `lattice`, duplicating the lattice already carried in labelled `placement`;
- `isolationSheet`, populated from `wedgeBindings.front().sheet`.

A repository-wide C++ reader audit finds **zero** readers of `occurrence.chart`, `occurrence.lattice`, or `occurrence.isolationSheet`. `point` remains live in representative-position validation; `chartComponent` is legitimate occurrence-wide authority. Leaving the three unread representative fields in the public A5 record contradicts the frozen product boundary and RA-11's labelled-face rule. Therefore **`M6-CP1` cannot close in this Review**.

### Correction to TB4-REV debt B6.2

The earlier note that aggregated lineage `equivalences` were not re-sorted after tuple remap is **withdrawn as a stale static finding**. Exact CB5/TB5 source sorts and de-duplicates `lineage.equivalences` immediately after the complete tuple/route remap in `remap_quotient_lineage_authority`; the same helper feeds validation lineage, output lineage and patch lineage. No code change is required for that debt. This correction changes no runtime result or stable accounting.

## 6. Exact successor — `M6-CP1-CB6`

`M6-CP1-CB6` is a bounded Code + Build turn governed by `Architecture_M6_CP1_CB6_Legacy_Occurrence_Field_Retirement_Code_Build_Plan.md`.

Its only semantic-source action is to retire the unread legacy `SurfaceOccurrence.chart`, `.lattice`, and `.isolationSheet` fields and their constructor/call-site arguments. It must preserve `point`, `support`, `chartComponent`, `topologyRegion`, complete wedge sheets/bindings, labelled placement provenance and wedge isolation evidence exactly. No test, fixture, selector, routing, A5 identity, A6 relation/quotient logic, A7 lineage semantics, HardRail/Periodic authority or frozen definition may change.

Compile/package the standard eight targets with mandatory GMP/GMPXX and `runtimeExecution=false`. Compile-green advances to immutable `M6-CP1-TB6-EXEC`, reusing the unchanged seven focused identities plus selector449 = **456** fresh exact-filter processes, then mandatory `M6-CP1-TB6-REV`. Only that Review may close CP1 after re-proving both the static A5 product surface and the unchanged runtime gate.

## 7. Review closeout matrix

| Duty | Decision |
|---|---|
| Candidate/package authority | independently re-opened; 28/28, exact source/archive/GMP boundary verified |
| TB5 evidence | 933/933; ledger and targeted differentials independently rechecked |
| Recovery | TB1, TB3 and TB4 formal recovery PROVED; TB2 remains recovery-proved |
| Promotion | `10879581622 / 82b86a28...` promoted as current reviewed runtime authority under selector449 |
| CP1 | **OPEN / acceptance held** only by the three dead legacy public A5 fields |
| B6.2 sort debt | withdrawn; exact source already sorts/deduplicates after remap |
| Stable accounting | **55 / 16 / 39**, unchanged |
| Produced-witness debt | **1**, unchanged; CP3 owns direct-production proof |
| Selector/routing | unchanged `d4a0d1b7...d6414` / `9c88a5ed...c5707` |
| Turn boundary | runtime-free Review; no source/test/fixture/selector/build/runtime mutation |
| Successor | exactly `M6-CP1-CB6` |

## Review-agent addendum — `M6-CP1-TB5-REV` (2026-09-25 UTC)

**Disposition:** TB5 mechanics, the TB1/TB3/TB4 formal recovery, the TB2 status, accounting **55 / 16 / 39**, debt 1, the runtime promotion, and the withdrawal of the B6.2 sort debt are **UPHELD**. §5-§6's CP1 closure scope is **CORRECTED**: CP1 is not one static field-retirement away from closure. `M6-CP1-CB6`, as planned, is **HELD**. Exact next is runtime-free **`M6-DEFN-R3`** (CP1 A6/A7 product-separation definition and sequencing).

### C1. Evidence independently re-derived

- **CB5 candidate `10879581622`:** digest `578845a2...57c6`; **28/28**. The packaged `RemeshPipeline.cpp` is byte-identical to `82b86a28` (`4386e4a7...`), and there is no `src/include/tests` drift since.
- **TB5 result `10880392759`:** digest `71095935...1216`; **933/933**. The ledger (`06c1d016...0a11`) has 456 rows, all PASS, exact-one/zero-skip, with selector order byte-identical to selector449. `red-ledger.tsv` is header-only. **Zero** raw logs contain `OccurrenceInvalidCornerAuthority`, `*IsolationSeamEquivalenceAuthority` or `QuotientReciprocalSideAuthorityMismatch`.
- **The CB5 diff matches the amended plan.** The no-certificate collinear case runs the non-seam P2 rule (`non_seam_span_pair_matches`), the seam branch is unchanged, and the RA-12 suffixes are present. A5 wedge vs side is distinguished by `error.occurrence`, which only wedge failures set.
- **RA-12 precision note:** `:a6-collinear-span` is now unreachable, because that case emits `QuotientReciprocalSideAuthorityMismatch` as specified. The suffix list at the end of the frozen definitions is annotated accordingly.

### C2. Upheld decisions

- **Recovery and accounting:** as §3.
- **Promotion (§4):** consistent with precedent. `M3-CP4c-3-TB39-REV` and the `M4-CP-SCALE` reviews promoted current runtime authority before checkpoint closure. Promotion is runtime authority, not acceptance.
- **B6.2 withdrawal:** correct. `std::sort(lineage.equivalences…)` already existed in the CB4 source (`20f60bb1:RemeshPipeline.cpp:14992`). The review agent's own finding was wrong, and lesson 182 records the pattern.

### C3. Correction: what CP1 still owes (TB5-REV §5-§6 and the CB6 plan understate it)

TB5-REV says CP1 is held "only by the three dead legacy public A5 fields". The CB6 plan lets TB6-REV close CP1 once those fields are gone and TB6 is green. Both contradict the frozen CP1 contract:

- **Frozen §10, M6-CP1 "product separation":** "Establish complete A5 occurrence, **A6 quotient, and A7 geometry products** … semantic occurrence/quotient/embedding decisions must move behind the stage-product APIs … proves no coordinate/position weld."
- **Frozen §8.1, the `G4-B002` CP1 mechanism owner:** "establish the real A5 occurrence product **and A6 stage boundary** from which candidate extraction can consume closed-complex authority without `SurfaceCellPipelineContext::hasArrangement`."
- **Frozen §12:** CB1 was "intentionally limited to the first A5 seam … does **not** implement A6 quotient extraction as a new product, A7 embedding…". The CB3-CB5 recovery plans then said "do not extract A6/A7". That scope was deferred, never discharged, and has since dropped out of ROADMAP, ORIENTATION and the consolidated record.

State of the exact source (`82b86a28`):
1. **No A6 or A7 product exists.** `SurfaceQuotientProduct` / `SurfaceQuotientProducer`, `QuotientRelationCertificate`, the consumption ledger, `QuotientCertificate`, `MaterializationCertificate`, and `SourceAttachedGeometryProduct` / `Producer`: 0 occurrences in `src/`, `include/` and `tests/`.
2. **The transitional adapter is not thin.** `build_authoritative_phase_front_mesh` is 1,768 lines (`RemeshPipeline.cpp:4043-5811`). It still owns the union-find, the class key and the transitional `QuotientClassId` ordinal, representative selection, selected-path certificates, positions and lineage.
3. **Frozen §4.4 exact-once consumption is not implemented.** At `:5179`, `if (!unite(first, second)) continue;` skips every relation whose endpoints are already joined. There is no certificate, no ledger row and no zero/duplicate-consumption check. A cycle-closing relation's transport is never checked against the path that already joined its endpoints, so a class could close with inconsistent holonomy undetected. This is inherited M5 behaviour, but §4.4 makes a per-relation certificate an M6 A6 obligation.
4. **Frozen §4.3 semantic `QuotientClassId` (sorted member set) is not realized.** RA-10 deferred it explicitly "to A6 extraction, not CB4".
5. **The `G4-B002` CP1 mechanism is not established.** Candidate extraction still consumes the arrangement-era `SurfaceCellComplex` (`SurfaceComplexSimplification.h:418-426`), and `hasArrangement` remains the pipeline flag (`RemeshPipeline.h:405`, `RemeshPipeline.cpp:8618/9930`).
6. The legacy `SurfaceOccurrence` `isolationSheet` / `chart` / `lattice` fields (TB5-REV §5) are **one** item among these, not the last.

**Consequence:** strike the CP1-closure sentences in TB5-REV §5-§6 and in the CB6 plan. CP1 cannot close until items 1-6 are met and a fresh gate is green.

### C4. Successor: `M6-DEFN-R3`, then its review, then bounded extraction CBs

A standalone CB6 would spend a full compile, 456-process and Review cycle on deleting three unread fields. The A6 extraction must reshape how `SurfaceOccurrence` is consumed anyway, so the field retirement is **folded into the first A6 extraction CB**. CB6 as planned is HELD.

The A6/A7 contracts are frozen (§4-§5), but several representation and semantic decisions have compatibility consequences and are not settled. They belong in a runtime-free Definition turn rather than a reviewer amendment; see `Architecture_M6_DEFN_R3_CP1_Product_Separation_Plan.md` for the full scope:
- how `QuotientClassId` as a member set coexists with the lineage ordinal (RA-10);
- ledger semantics and transport/holonomy consistency for cycle-closing relations;
- where selected-relation-path certificates live;
- the `G4-B002` A6 stage boundary;
- CB sequencing and new pre-registered focused identities.

### C5. Accounting

No event; **55 / 16 / 39**, debt 1. Promotion stands. CP1 is **OPEN** with the corrected scope.

### Review-agent closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | selector449 `d4a0d1b7...d6414`, TB5 selector order exact; routing449 `9c88a5ed...c5707` |
| Decisive claims independently re-derived | candidate 28/28 and source identity; TB5 933/933, 456/456, empty RED ledger, zero failure strings; CB5 diff vs plan; B6.2 sort present since CB4; A6/A7 product absence; materializer extent; `:5179` skip; candidate-extraction input type |
| Non-vacuity checked | the CP1 scope correction rests on frozen §8.1/§10/§12 text and source greps, not inference |
| Prior obligations discharged/carried | TB1/TB3/TB4 recovery proved (upheld); CP1 product-separation obligations 1-6 recorded; CB6 folded |
| Stable accounting | **55 / 16 / 39**, debt 1; +0 |
| New candidates/obligations recorded | CP1 exit checklist (restated from the frozen text); `M6-DEFN-R3` scope; tracker +0 entry |
| ORIENTATION currency line | `M6-CP1-TB5-REV` (review-agent addendum), 2026-09-25 UTC |
| ORIENTATION §3 / §4 / §7 / §8 | §3, §7 and §8 amended; §4 n/a |
| CHANGELOG | root and Directional prepended |
| ROADMAP | M6-CP1 row and interlock corrected (A6/A7 product separation outstanding) |
| Selector manifest | unchanged (TB5-REV's promotion note stands) |
| LESSONS | 183 added (deferred checkpoint scope must stay on the ledger) |
| Consolidation under CLEAN_UP_POLICY | CB6 plan kept, marked HELD/folded; new DEFN-R3 plan is the single live successor plan |
| Successor frozen | exactly `M6-DEFN-R3`, then `M6-DEFN-R3-REV` |
| Turn boundary held | runtime-free; documents only |
| review_check.py boundary / ledgers | recorded in the commit message |
| `STATUS` lifecycle maintained | resume `IN_PROGRESS` (`Resumed at` = operator handoff `2026-09-25T20:01:58Z`) → docs → COMPLETE last |
