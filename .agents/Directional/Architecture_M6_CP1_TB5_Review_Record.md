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
