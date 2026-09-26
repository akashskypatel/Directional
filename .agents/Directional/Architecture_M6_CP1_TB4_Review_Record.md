# M6-CP1-TB4 Independent Review Record

**Turn:** `M6-CP1-TB4-REV`
**Type:** mandatory runtime-free independent Review
**Disposition:** **COMPLETE / TB4 MECHANICS UPHELD / ONE NEW STABLE ACCEPTED-PREFIX RP-01 RECURRENCE / CANDIDATE UNPROMOTED / CB5 FROZEN**
**Candidate:** artifact/source `10871935178 / 20f60bb1412424a6f1093fc8076884d1ea23f1c5`
**TB4 runtime:** run/job `36157505252 / 108145613689`, result/log `10874311495 / 10873574681`
**Accepted predecessor:** artifact/source `10814505512 / e284fea7c101eb86650d1c87c92d0fefa66050e7`, selector449 **449/449 PASS**
**Exact successor:** `M6-CP1-CB5`

## 1. Independent evidence re-opened

Review re-opened the immutable CB4 package/source, the TB4 result evidence, accepted M5 package/result evidence, the prior TB3 candidate, selector449/routing449 bytes, current R2 definition authority and the exact implementation source instead of accepting the EXEC report as self-proving.

The CB4 package independently re-verifies **28/28** root manifest entries, exact semantic source `20f60bb1412424a6f1093fc8076884d1ea23f1c5`, source archive SHA-256 `db894f3e27d880b4d27a593816df6e521dff01583e320ec198b4fd8401e50065`, mandatory GMP/GMPXX evidence, clean source receipts and `runtimeExecution=false`. TB4 result artifact `10874311495` independently re-verifies **932/932** evidence files. Its execution boundary records `runtime_started=true`, `runtime_completed=true`, `preflight_completed=true`, `orchestration_failure=false`, `selection_integrity=true`, no watchdog, no configure/compile/relink/discovery/repair/mutation and benchmark count zero. Package, packaged source and execution-view byte/mode censuses are identical before/after runtime.

The TB4 ledger has exactly **456** planned fresh exact-filter processes: seven focused identities followed by selector449. Every process selects exactly one test with zero skips. Outcome is focused **6/7 PASS**, selector449 **425/449 PASS**, aggregate **431/456 PASS / 25 RED**.

Accepted M5 result artifact `10815911956` independently re-verifies **911/911** evidence files and selector449 **449/449 PASS**. Accepted package `10814505512` independently re-verifies **28/28**, exact source `e284fea7c101eb86650d1c87c92d0fefa66050e7` and source archive SHA-256 `92af40d8be93f77a44e0a396173c4965a801367bde1424318609b1826931f315`. Every TB4 selector RED ordinal is PASS in that accepted ledger, so the 24 selector losses are accepted-prefix transitions, not unsupported focused-only observations.

Selector449 is still exactly 449 LF rows at SHA-256 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`; its first448 prefix is `70ff08601bf244fcb4883e5d0601d5e7a3a44f52a8e855544a065c6ca5c75789`; routing449 is `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707`. Routing is identity-equal to selector order, with owner census **32 / 301 / 75 / 41**. Candidate and accepted selector bytes are identical.

The prior TB3 candidate `10840014758 / 660015f2f15359fd426e2c855aea9f4201c70216` was also reopened. Its package verifies 28/28. The TB3→TB4 semantic delta is limited to the six CB4 files already recorded by Code + Build; this gives a bounded differential for the new losses.

## 2. Differential, non-vacuity and candidate envelope

TB4 recovers the direct TB3 multi-isolation witnesses: focused row5 plus selector ordinals **186, 214, 239** are now PASS, and the new seventh identity `M6CP1.SeamEndpointOccurrencesPublishCompleteCornerWedgeSheetAuthority` PASSes. The carried TB3 pair-swap surface remains RED: focused row6 plus selector **444, 446, 448** still stop at `MissingIsolationSeamEquivalenceAuthority`.

The **21 newly RED accepted identities** are selector ordinals:

`115, 116, 122, 130, 132, 134, 137, 141, 143, 150, 176, 201, 217, 218, 231, 232, 238, 246, 436, 437, 438`.

Review independently bins them by observed first failure without double counting:

- **13 direct authority failures:** `115,116,141,143,150,217,218,231,232,246,436,437,438` expose `MissingIsolationSeamEquivalenceAuthority` directly (row150 wraps it as `NotProductionReady:tracing:MissingIsolationSeamEquivalenceAuthority`).
- **5 downstream hard-feature reachability casualties:** `122,130,132,134,137` fail because their unchanged hard-feature fixtures no longer reach the feature/remap/final-oracle state they are intended to mutate or inspect. Those tests use the same disconnected rectangular hard-feature fixture family as row150, which directly exposes the upstream tracing failure. They are therefore non-vacuous downstream casualties of the same gate, not evidence for five new semantic mechanisms.
- **3 earlier-stage downstream casualties:** `176,201,238` terminate at `NotProductionReady`/tracing before the injected-stage or downstream production assertion they previously reached. Current evidence does not establish a distinct first mechanism for them.

The grouping is falsifiable rather than assumed: CB5/TB5 must correct only the proved OrdinaryFront classification error. If the direct family recovers but any downstream row remains RED at a different first failure, TB5 Review must split/classify that residue as a new candidate instead of widening CB5.

Non-vacuity is independently established by the accepted M5 449/449 control, by row150's direct error on the same hard-feature fixture family, and by the fact that the strengthened seam-endpoint identity now PASSes while ordinary production paths newly fail. The new validator is active; the problem is its domain predicate, not an inert assertion.

## 3. Root cause — generic source-edge support is consumed as isolation-seam authority

R2 distinguishes **source-edge-collinear** geometric support from **seam-collinear** semantic authority. R2 §5.1 defines a source-edge-collinear span by exact open-interior `SourceEdgeSupport`. P2 then has two cases for reciprocal OrdinaryFront endpoint spans: non-seam spans require the same mapped interior sheet plus membership in both endpoint wedge sets; seam-collinear spans require the same exact checked seam certificate/span, opposite incident faces/sheets and reciprocal ordered evidence. The terms are not synonyms.

A5 implements that distinction correctly enough to expose the bug:

1. `RemeshPipeline.cpp:3587-3593` sets `SurfaceOccurrenceSideSpan::collinearEdge` whenever the exact midpoint support is *any* `SourceEdgeSupport` whose closure contains both endpoints. This is generic source-edge geometry.
2. `transition_between` at `3469-3498` looks up `(region, edge)` in `isolationCertificateBySeam`. If no certificate exists and the two bindings stay on the same sheet, it returns success with no isolation transition. Thus A5 explicitly admits ordinary same-sheet source-edge-collinear spans with no isolation certificate.
3. A6 reciprocal OrdinaryFront validation at `4887-4944` first checks whether both endpoint spans have `collinearEdge`. If neither does, it applies the P2 same-sheet/wedge-membership rule. But if `collinearEdge` exists, it unconditionally renames that edge `seam`, requires an isolation certificate at `4910-4914`, and returns `MissingIsolationSeamEquivalenceAuthority` when none exists.

That A6 branch was introduced by CB4. It converts the representation/support fact “this span lies exactly on a source edge” into the semantic ownership fact “this source edge is an isolation seam.” A valid ordinary same-sheet span that A5 intentionally published is therefore rejected solely because its support is edge-collinear.

**Classification:** `M6-CP1-TB4-EXEC-CAND-01` is **STABLE** and is **one new recurrence of existing `RP-01 / AUTHORITY_DOMAIN_CONFLATION`**: generic exact source-edge support is consumed as isolation-seam certificate authority. It is not a new category. Twenty-one accepted selector rows newly transition PASS→RED under this one bounded change. Stable accounting advances **54 → 55 events / 16 categories / 38 → 39 recurrences**. Produced-witness debt remains **1**, M6-owned.

## 4. Prior obligations and recovery status

- **`M6-CP1-TB3-EXEC-CAND-01` / RP-01 — FORMAL RECOVERY STILL OPEN.** CB4/TB4 proves the intended relation/wedge repair is active: focused row5 and selectors 186/214/239 recover. But its pre-registered complete-gate recovery criterion is not satisfied because focused row6 and selector 444/446/448 remain RED behind the newly proved A6 overclassification. Do not erase the TB3 event or claim full recovery.
- **`M6-CP1-TB1-EXEC-CAND-01` / `CROSS_TEMPORARY_ITERATOR_RANGE` — MECHANISM CLEARED / FORMAL RECOVERY STILL OPEN.** `OccurrenceInvalidCornerAuthority` remains absent, but the frozen recovery rule required selector449 **449/449**. TB4 is 425/449.
- **`M6-CP1-TB2-REV-CAND-01` / `VALIDATION_ORDER_SHADOWING` — CLOSED / RECOVERY PROVED.** Selector row140 is not in the TB4 RED set and remains PASS; no reopening is justified.
- **Produced-witness debt — CARRIED.** M6 still owns the one outstanding project debt. TB4 is not a promotion or CP1/G4 closure.

Accepted runtime authority remains M5 package/source `10814505512 / e284fea7c101eb86650d1c87c92d0fefa66050e7` under selector449 449/449. CB4 candidate `10871935178` remains unpromoted.

## 5. Bounded successor

Exact successor is runtime-free Code + Build **`M6-CP1-CB5`**, frozen in `Architecture_M6_CP1_CB5_Ordinary_Front_Seam_Classification_Recovery_Code_Build_Plan.md`.

CB5 owns one semantic correction only: in A6 reciprocal `OrdinaryFront` P2 classification, `collinearEdge` is generic exact source-edge support and is **not** sufficient seam authority. For matching endpoint spans:

1. if neither is source-edge-collinear, keep the existing same-sheet + both-wedges membership branch;
2. if both name the same source edge, query the already checked `(region, edge)` isolation-certificate authority;
3. if no certificate exists, apply the same non-seam same-sheet + both-wedges membership rule;
4. only if that exact certificate exists, apply the current seam branch: opposite exact source faces/sheets plus reciprocal span transition evidence.

No A5 span construction, support resolver, collinear interior-face selection, corner-wedge authority, placement provenance, occurrence/relation identity, quotient equality, HardRail/Periodic owner/action/transport semantics, component remap, test, fixture, selector or routing change is authorized. If the distinction cannot be expressed from existing checked isolation-certificate authority without changing frozen R2 semantics or the A5 product schema, CB5 stops for Review/Definition.

Compile-green advances to immutable `M6-CP1-TB5-EXEC` with the **same seven focused + selector449 = 456** processes, then mandatory `M6-CP1-TB5-REV`. Recovery-green requires focused 7/7 and selector449 449/449, row140 PASS, no `OccurrenceInvalidCornerAuthority`, all 21 new TB4 losses recovered, carried focused row6 + selectors444/446/448 recovered, rows5/7 remain PASS, exact-one/zero-skip, benchmark0 and exact immutable postflight. Any RED is Review-owned; no TB5 retry/repair is pre-authorized.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | selector449 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`; first448 `70ff08601bf244fcb4883e5d0601d5e7a3a44f52a8e855544a065c6ca5c75789`; routing449 `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707`; accepted selector result independently re-opened at 449/449. |
| Decisive claims independently re-derived | Candidate package 28/28 + exact source; TB4 result 932/932 + 456-process mechanics; accepted result 911/911 + 449/449; TB3 differential; direct A5/A6 source predicate and R2 P2 contract. |
| Non-vacuity checked | Accepted 449/449 is the control; 13 new rows hit the direct new error; row150 anchors the shared hard-feature fixture family; strengthened focused row7 PASSes while ordinary paths regress. |
| Prior obligations discharged/carried | TB2 validation-order candidate stays closed; TB3 RP-01 formal recovery carried; TB1 iterator formal recovery carried; project produced-witness debt carried to M6. |
| Stable accounting | **55 events / 16 categories / 39 recurrences**, debt **1** M6-owned; accepted runtime package/source `10814505512 / e284fea7...`, selector449 449/449. |
| New candidates/obligations recorded | `M6-CP1-TB4-EXEC-CAND-01` adjudicated STABLE as one `RP-01` recurrence; tracker updated with root, falsifier, owner and prohibitions. |
| ORIENTATION currency line | `M6-CP1-TB4-REV`, 2026-09-25 UTC. |
| ORIENTATION §3 / §4 / §7 / §8 | §3 updated to 55/16/39 and CB5 next; §4 n/a because no accepted witness state changed; §7 stale CB4-next text replaced with CB5→TB5; §8 adds the source-edge-vs-seam RP-01 instance and preserves open formal recovery. |
| CHANGELOG | Root and `.agents/Directional/CHANGELOG.md` updated. |
| ROADMAP | M6 CP1 Review disposition/CB5 successor updated; M6 marked ACTIVE while M7–M8 remain not started. |
| Selector manifest | n/a — no selector was added, modified or accepted. |
| LESSONS | Existing single-authority/domain lessons 22 and 179 cover the pattern; no genuinely new lesson added. |
| Consolidation under CLEAN_UP_POLICY | Folded five superseded TB3/CB4 report/plan/blocker documents into `M6_Consolidated_Record.md`; current TB4 runtime report, this Review, CB5 plan and normative R1/R2 authority retained. |
| Successor frozen | Exactly `M6-CP1-CB5`; falsifiers and stop rules are in §5 and the CB5 plan. |
| Turn boundary held | Runtime-free Review; no product, test, fixture, selector, benchmark or build-source mutation. |
| review_check.py boundary | **PASS — all review boundary and selector integrity checks passed.** |
| `STATUS` lifecycle maintained | Entered `M6-CP1-TB4-REV / IN_PROGRESS` before substantive work; final `COMPLETE / Successor: M6-CP1-CB5` is reserved as the final repository write. |
| Pushed to origin, branch in sync | **Verified after the final push: working branch was re-read with no unexpected source drift; temporary review control state was removed before the final STATUS beacon.** |

## Review-agent addendum — `M6-CP1-TB4-REV` (2026-09-25 UTC)

**Disposition:** TB4 mechanics, the accepted-prefix differential, the root cause for the 21 new losses, the classification (one `RP-01` recurrence), accounting **55 / 16 / 39**, debt 1 and the prior-candidate dispositions are **UPHELD**. The review agent adds a stronger proof for the new losses. It **corrects one overclaim** about the carried torus REDs, **amends the CB5 plan with RA-12** (site-qualified failure diagnostics), and records two debts. Exact successor stays **`M6-CP1-CB5`**, as amended.

### B1. Evidence independently re-derived

- **CB4 candidate `10871935178`:** provider digest and download SHA-256 are both `dc6e979a...7998`; manifest **28/28**. The packaged `RemeshPipeline.cpp` is byte-identical to `20f60bb1` (`ef976666...`), and `git diff 20f60bb1 HEAD -- src include tests` is empty.
- **TB4 result `10874311495`:** digest `32dca965...3e24`; **932/932**. The selector ledger lists 449 rows in exact selector order, **425 PASS**, all exact-one/zero-skip. The RED set matches the report exactly. Focused rows 1-5 and 7 PASS; row 6 is RED. The raw logs contain **0** `OccurrenceInvalidCornerAuthority`.

### B2. Stronger proof for the 21 new losses: single-sheet exclusivity

After CB4, `MissingIsolationSeamEquivalenceAuthority` has **four** emission sites, because RA-7 maps several failures to the one legacy name:
- **(a)** A5 `MissingIsolationEvidence`, mapped at the adapter (`RemeshPipeline.cpp:3102-3103`). It is raised by `transition_between` (`:3476-3482`) only when a wedge fan or side crosses an edge between **different** sheets that has no certificate.
- **(b)** Side-evidence certificate lookup (`:4745`). Side evidence exists only where A5 already found a certificate.
- **(c)** The A6 collinear no-certificate branch (`:4908-4914`), which is TB4-REV's root cause.
- **(d)** The seam branch's missing span transition (`:4938-4942`), which requires a certificate to exist.

On a **single-sheet** fixture, (a) cannot occur (there is no sheet change), and (b) and (d) cannot occur (there are no certificates). Only (c) remains. All 21 new losses use single-sheet fixtures: hard-rail rectangles, cylinder/annulus, the committed plane and the REPackage meshes.

The attribution is therefore proved, not inferred from the failure string. This includes the eight downstream casualties. For example, row122 fails with "fixture must expose hard-feature authority to tamper", and rows 176/201/238 fail with `NotProductionReady` at tracing.

### B3. Correction: the carried torus REDs are not proved to be site (c)

TB4-REV §4 says focused row6 and selectors 444/446/448 "remain RED behind the newly proved A6 overclassification". The produced torus is **multi-sheet** (row449 asserts at least two sheets in one region), so sites (a), (c) and (d) are all possible there, and the failure string cannot tell them apart. Their recovery under CB5 is a **prediction, not a consequence**.

- Site (a) is plausible on the torus: a close-sheet boundary that meets a rail-conformal corner or side.
- Site (d) cannot be excluded statically either.

**Falsifier, added to the TB5 pre-registration:** if any torus row remains RED after CB5, TB5-REV must identify the emission site from the RA-12 suffix. It must not assume site (c), and it must not broaden CB5.

### B4. RA-12 — site-qualified isolation-failure diagnostics (amends RA-7; required in CB5)

RA-7, the review agent's own amendment, collapsed four distinguishable failure sites into one legacy string. That is the many-to-one problem B4 removed from A5, reintroduced at the adapter output, and it is exactly why §B3 cannot be settled from TB4 evidence. No test and no production code compares these strings exactly. Tests only assert `success` and print the string; the only source hits are emission sites.

*Amendment:* keep the legacy name as a **prefix** and add a site suffix:
- `MissingIsolationSeamEquivalenceAuthority:a5-wedge` / `:a5-side`: the A5 `MissingIsolationEvidence` code, split by whether the wedge fan or the side traversal raised it;
- `:a6-side-evidence` (site b);
- `:a6-collinear-span` (site c, which CB5 makes reachable only for a genuinely uncertified cross-sheet collinear span);
- `:a6-seam-span-transition` (site d);
- the same treatment for `InvalidIsolationSeamEquivalenceAuthority`: `:a5-wedge`, `:a5-side`, `:a6-side-evidence`, `:a6-seam-faces`.

This is diagnostic only: no predicate, ordering or success outcome changes. Pipeline wrappers such as `NotProductionReady:tracing:<failure>` carry the suffix unchanged.

### B5. CB5 fix verified against A5 publication

A5 publishes interior → opposite transitions for a collinear span on a certified seam (`:3664-3702`). The A side carries `(sA→sB)` and the B side `(sB→sA)`, which satisfies both the A6 seam-branch span check and the reciprocal whole-side check. A5 publishes none for a non-seam collinear span. CB5's "no certificate → exact non-seam P2 (same interior sheet in both wedge sets)" rule therefore agrees with A5 and cannot admit different-sheet endpoints.

When the non-seam predicate fails on a collinear no-certificate pair, it emits `QuotientReciprocalSideAuthorityMismatch`, the same as the non-collinear branch today.

### B6. Debts recorded (not CB5 scope)

1. **Legacy single-valued `SurfaceOccurrence` fields.** CB4 still populates `isolationSheet` and `chart` from `wedgeBindings.front()`, `point` from the node's selected face, plus `chartComponent` and `lattice` (`RemeshPipeline.cpp:3938-3946`). No production or test code reads them: every A6/A7 consumer uses wedge bindings, placement provenance and spans. They still publish an unlabelled representative sheet on the public A5 product, which contradicts frozen §3.2 (`CornerWedgeSheetSet`, not `IsolationSheetId`) and RA-11.4.
   - *Obligation, a CP1-acceptance precondition:* remove these fields or explicitly relabel them as representation-only before CP1 closes.
2. **Aggregated lineage `equivalences` are not re-sorted after tuple remap** (`:14830-14850`). `CornerWedgeIsolation` entries share front edges of −1, so remapped region/seam/sheet IDs can reorder them. No consumer checks the order and the hash is deterministic. Minor; re-sort at the next touch of that code.

### Review-agent closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | selector449 `d4a0d1b7...d6414`, ledger order exact; routing449 `9c88a5ed...c5707` |
| Decisive claims independently re-derived | candidate 28/28 and source byte-identity; result 932/932, RED set, row outcomes; four emission sites and the single-sheet exclusivity proof; A5 collinear-span transition publication vs the A6 seam branch; no exact-string consumers |
| Non-vacuity checked | the single-sheet proof makes the 21-loss attribution exact; the torus attribution is explicitly left open with a falsifier |
| Prior obligations discharged/carried | TB2 closed; TB3 and TB1 formal recovery carried (upheld); debts B6.1 (CP1 precondition) and B6.2 added |
| Stable accounting | **55 / 16 / 39**, debt 1; +0 from this addendum |
| New candidates/obligations recorded | RA-12 (CB5 scope); TB5 torus falsifier; B6 debts |
| ORIENTATION currency line | `M6-CP1-TB4-REV` (review-agent addendum), 2026-09-25 UTC |
| ORIENTATION §3 / §4 / §7 / §8 | §3, §7 and §8 amended; §4 n/a |
| CHANGELOG | root and Directional prepended |
| ROADMAP | M6-CP1 row amended (CB5 + RA-12) |
| Selector manifest | n/a |
| LESSONS | 181 added (a compatibility name must not erase which check fired) |
| Consolidation under CLEAN_UP_POLICY | none needed; CB5 plan amended in place |
| Successor frozen | `M6-CP1-CB5` as amended by RA-12 |
| Turn boundary held | runtime-free; no source/test/fixture/selector/benchmark/build mutation |
| review_check.py boundary / ledgers | recorded in the commit message |
| `STATUS` lifecycle maintained | resume `IN_PROGRESS` (`Resumed at` = operator handoff `2026-09-25T17:06:03Z`) → docs → COMPLETE last |
| Pushed to origin, branch in sync | verified after the final push |

## Review-agent second pass — `M6-CP1-TB4-REV` (2026-09-25 UTC)

**Origin delta since the first addendum:** STATUS and trigger housekeeping only. No semantic, test or document change. This pass re-examines CB4 code that TB4 could not exercise, and **corrects two overclaims in the first review-agent addendum**. Accounting stays **55 / 16 / 39**, debt 1, and the successor stays `M6-CP1-CB5` (as amended).

### S1. Correction to addendum §B2: the eight downstream rows are bound, not proved

Single-sheet exclusivity proves the site only for the **13 rows whose logs show** `MissingIsolationSeamEquivalenceAuthority`. The eight downstream rows never print their underlying failure string, so exclusivity does not reach them. The first addendum's "this includes the eight downstream casualties" was an overclaim.

What does hold:
- **Hard-feature rows 122/130/132/134/137:** strongly bound. They use `make_disconnected_rectangular_feature_pair_mesh` with the same per-component options as row150's failing components. Row122 passes `producedBeforeTamper`, which means A4 produced. It then finds no HardFeature rail, because `componentProducts->authoritativeRails` is exported only after the component completes (`RemeshPipeline.cpp:11289-11300`). That signature fits any failure after A4, and row150 on the same fixture reports site (c).
- **Rows 176/201/238:** consistent only. They show A4 Produced, then `NotProductionReady` at tracing; row238 prints only `code:stage`. RA-12 cannot help these rows, because their tests never print the reason.

TB4-REV's own downstream falsifier stays the controlling rule. If any of the eight rows is RED in TB5, split it rather than attributing it to site (c).

### S2. Correction to addendum §B6.1: the legacy-field debt, narrowed

`SurfaceOccurrence::point` is **live**: it supplies the vertex position, `vertexProvenance` and lineage `sourcePoint` (`:5305-5307`, `:5440-5445`). It is legitimate representation. The validator requires its face's chart to be in `sourceCharts`, and the member wedges tile the node's fan within the region, so that holds.

`chartComponent` is a legitimate occurrence-wide value (R2 §4.1; A5 enforces one component per wedge) that CB4 simply no longer reads.

The debt is therefore exactly `isolationSheet` (unlabelled representative sheet), `chart` (first-binding chart) and `lattice` (unlabelled duplicate of `placement.lattice`). None has a reader. Remove or relabel them before CP1 acceptance.

### S3. Areas verified with no defect (not observable in TB4 because rows failed upstream)

1. **Selected relation paths.** CB4 derives `startChart/endChart` and components from the first/last selected steps (`:5406-5431`), as R2 §4.4 permits, instead of M5's construction-time anchor to representative/target occurrences. This is not a weakening. Completion-stage validation (`PureQuadCompletion.cpp:990-1045`) re-anchors every certificate to the vertex:
   - start and end charts must be retained lineage charts, incident to the support, with matching components;
   - every step must be continuous and its components retained.

   The relation-side interior face is an RA-8 arc endpoint, so it is always one of the occurrence's wedge bindings, and therefore retained.
2. **Final validator chart authority.** `SourceVertexChartAuthority` requires a sorted, unique `sourceCharts` that contains the provenance point's declared chart and lies in one source component (`SourceAuthoritativeMeshValidator.cpp:795-860`). CB4's `std::set` union of wedge charts satisfies this. `hardRailEquivalences` are explicitly sorted and de-duplicated (`RemeshPipeline.cpp:6344-6349`), so addendum §B6.2 stays cosmetic.
3. **Negative front edges** on `CornerWedgeIsolation` entries are guarded in aggregation and ignored by kind-gated consumers, as previously re-confirmed.

### S4. Net effect

No change to the classification, accounting, CB5 scope, RA-12 or the torus falsifier. The only changes are that the first addendum's proof and debt statements are narrowed to what the evidence supports.

| Duty | Answer |
|---|---|
| Decisive claims re-derived | origin delta; downstream-row evidence limits; `point` consumers; stage-product export timing; completion-stage path validation; validator chart authority |
| Stable accounting | **55 / 16 / 39**, debt 1; +0 |
| Obligations | B6.1 narrowed to `isolationSheet` / `chart` / `lattice`; downstream falsifier reaffirmed |
| Turn boundary held | runtime-free; documents only |
| `STATUS` lifecycle maintained | resume `IN_PROGRESS` (`Resumed at` = operator handoff `2026-09-25T17:22:06Z`) → docs → COMPLETE last |
