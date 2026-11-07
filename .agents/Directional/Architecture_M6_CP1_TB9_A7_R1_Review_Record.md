# `M6-CP1-TB9-A7-R1-REV` — Recovery Review Record

**Turn:** `M6-CP1-TB9-A7-R1-REV`
**Type:** runtime-free Review
**Reviewed candidate:** `11292072930 / 584f80fe27fe3fbe482f3b6db035651a3083257c`
**Reviewed runtime:** `37174573847 / 111354443006`
**Result / log:** `11293546353 / 11293531459`
**Disposition:** **ACCEPT / RECOVERY PROVED / PROMOTE**
**Exact successor:** `M6-CP1-CB10-A5V`

## 1. Independent evidence re-derivation

Review did not accept the EXEC narrative as self-proving. The primary result bytes were reopened and independently checked.

- Result artifact ZIP SHA-256 is `a690ca3992022d7e41d6608062825f5dcf948c74cda8b10a3abe91ddc9d1778e`; log artifact ZIP SHA-256 is `6f9365e9430b97e5f22fd2740443c5cb26dafc408c4b6ac43c2a0b1e9b5b43b7`.
- `SHA256SUMS` SHA-256 is `735dca6e58428f2f8c4234afec61c41d023841d9af8f058f7c5895d11813e008`; all **970/970** listed result files verify.
- Focused ledger independently re-parses to **20 rows / 20 PASS / 0 selection mismatches / 0 skips / exact ordinal order**.
- Selector ledger independently re-parses to **449 rows / 449 PASS / 0 selection mismatches / 0 skips / exact ordinal order**.
- Arithmetic is therefore **20 + 449 = 469**, all **469/469 PASS**.
- `red-ledger.tsv` has no data rows. The execution boundary records runtime complete, orchestration failure false, and configure/compile/relink/generated-discovery/benchmark/package-repair/mode-repair/source-test-fixture-selector mutation/retry-after-runtime-start all false.
- Postflight reports package, source, execution-view and fixture censuses unchanged, selector/routing unchanged, and candidate root manifest still 28/28.

The exact review snapshot is run/job `37176878537 / 111361248778` at control SHA `fbaea32325dbb067e154ad6a3ed07e4e448ff049`; snapshot artifact `11293877329` has provider ZIP digest `sha256:afe0b13427f07a78d21727e7bea0613f7231408a0dbf8dec34ad066930882d3a`, embedded `source.tar.gz` SHA-256 `8167218e777d3d13185469394de322dea571d1613c8b9e753ae3200c0e1e4e7f`, and **5334/5334** source-manifest entries verified.

## 2. Accepted-prefix and authority checks

Review re-hashed the frozen authority bytes:

- focused12: `59a523ae2039e0cb537cee550aab6e54936353b8a60234a3915049dc0c3d571c`;
- focused20: `15d04a2a09eeb678923b0bfcf70bf9c07b79e7ff343ec468316f6510b16827d2`;
- focused20 first 12 lines are byte-identical to focused12;
- selector449: `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`;
- routing449: `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707`;
- counts are 12 / 20 / 449 / 449 respectively.

Focused ordinal 20 is non-vacuous. Its source calls the real `build_authoritative_phase_front_mesh`, requires successful materialization, then calls real `validate_materialized_completion_domain_ownership`. Its raw log selects exactly that one test and records a 72.151-second PASS. The same frozen identity was the sole RED before R1, so the recovery distinguishes the repaired completion predicate from merely reaching an unrelated green branch.

## 3. RA-22 / RA-22a source adjudication

The reviewed source implements the bounded recovery without widening the producer contract:

1. A7 lineage is detected only by existing occurrence-binding authority (`sourceOccurrences` non-empty).
2. Every retained chart is still resolved and checked against exact support plus retained region/sheet authority.
3. `SourceChartTransitionGraph::source_component` is evaluated for every retained chart; unresolved or non-singleton component authority fails with `CompletionOwnershipInvalidRetainedSourceAuthority:component-singleton`.
4. A7 selected-relation destinations require retained-region membership, retained-sheet membership, and equality to the retained-chart component singleton. They do **not** compare candidate sheet/component against the representation-only `sourcePoint.face` values.
5. Legacy non-A7 closure still initializes and checks `selectedSheet` / `selectedComponent` from the selected face.
6. RA-22a destination diagnostics are split, in order, into `:dest-unresolved`, `:dest-region`, `:dest-sheet`, and `:dest-component`.

This matches RA-22/RA-22a. No A5/A6/A7 producer identity, relation value, placement transport, selected path, source-support rule, fixture, focused list, or selector is changed by Review.

## 4. Regression and promotion disposition

`M6-CP1-TB9-A7-EXEC-CAND-01` is now **RECOVERY PROVED / CLOSED AS A NON-STABLE INSTANCE OF EXISTING `RP-01 / AUTHORITY_DOMAIN_CONFLATION`**. It never entered stable accounting because no previously accepted selector row was lost. R1 restores the production-completion witness without any accepted-prefix loss.

Candidate `11292072930 / 584f80fe27fe3fbe482f3b6db035651a3083257c` is therefore **PROMOTED as the current reviewed M6 runtime authority under unchanged selector449**. Stable accounting remains **60 events / 16 categories / 44 recurrences**, produced-witness debt **1**.

## 5. Prior obligations

- **`τ` single-source obligation — CARRIED to `M6-CP1-CB10-A5V`.** A5 and A7 currently each construct a default `SurfacePointSourceSupportResolver`; A7 reads `barycentric_tolerance()` from its own instance. CB10 must make the accepted RA-18 tolerance one shared constant/accessor used by both A5 and A7, with no numeric tolerance change. The CB10 plan is amended in this Review.
- **A7 cross-sheet certification proxy — CARRIED to `M6-CP1-CLOSE-REV`.** This Review neither weakens nor silently discharges it. CP1 close must either make the A7 check exact for the crossed endpoint sheets or remove the proxy and state A6 as the sole certifier.

No other R1 Review obligation is outstanding.

## 6. Exact successor and stop rules

Review releases exactly one bounded successor: **`M6-CP1-CB10-A5V`** under the amended `Architecture_M6_CP1_CB10_A5_Validation_Code_Build_Plan.md`.

Its pre-build falsifiers remain the four focused identities 21-24 plus the accepted focused1-20 prefix and selector449. CB10 must additionally prove statically that A5 and A7 read one shared `τ` owner while preserving the accepted numeric value. Compile/package only; runtime is forbidden. If implementation requires changing the accepted tolerance value, A7 support semantics, A6/A7 identity/topology, fixtures, selector449, prior focused bytes, or anything outside the bounded A5/thin-adapter plus shared-tolerance plumbing, stop for Review instead of broadening scope. Compile-green successor is `M6-CP1-TB10-A5V-EXEC`, exact gate **24 + 449 = 473**, then mandatory `M6-CP1-TB10-A5V-REV`.

`M6-CP1-CLOSE-REV` remains owner of the A7 cross-sheet proxy. CB11 and CP1 close are not started in this turn.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | focused12 `59a523ae...3d571c`; focused20 `15d04a2a...827d2`; first 12 byte-identical; selector449 `d4a0d1b7...d6414`; routing449 `9c88a5ed...6c5707`. |
| Decisive claims independently re-derived | 970/970 manifest; 20/20 focused; 449/449 selector; 469/469 arithmetic/order; exact-one/zero-skip; empty RED ledger; immutable postflight; RA-22 source predicates. |
| Non-vacuity checked | focused20 executes real production materialization + completion ownership; exactly one test ran and passed; the same frozen identity was the prior sole RED. |
| Prior obligations discharged/carried | `τ` single-source carried to CB10 with plan amendment; A7 cross-sheet proxy carried to `M6-CP1-CLOSE-REV`. |
| Stable accounting | 60 / 16 / 44, debt 1; promoted package/source `11292072930 / 584f80fe...` under unchanged selector449. |
| New candidates/obligations recorded | none; prior CAND-01 marked recovery-proved/closed non-stable; existing carried obligations retained. |
| ORIENTATION currency line | updated to this Review and 2026-10-04 UTC. |
| ORIENTATION §3 / §4 / §7 / §8 | §3 runtime authority/current gate updated; §4 torus recovery state corrected; §7 R1 removed as open and CB10 made first priority; §8 lesson 191 retained as the governing existing pattern. |
| CHANGELOG | Review acceptance/promotion entry prepended. |
| ROADMAP | CP1 routing advanced to CB10; R1 marked accepted. |
| Selector manifest | updated package/runtime-authority note under unchanged selector449; no selector append. |
| LESSONS | no new lesson; existing lesson 191 governs the recovered anchor/authority-domain defect. |
| Consolidation under CLEAN_UP_POLICY | n/a — no stale standalone review/plan document is eligible for deletion in this recovery chain. |
| Successor frozen | `M6-CP1-CB10-A5V`; falsifiers and stop rules are in §6 and the amended CB10 plan. |
| Turn boundary held | runtime-free Review; no product/test/fixture/selector/build-source mutation. |
| review_check.py boundary | PASS after the final review-document edit set; no product/test/fixture/build-source or selector mutation. |
| `STATUS` lifecycle maintained | entry beacon written directly for this Review; final COMPLETE beacon is written directly only after durable patch/cleanup. |
| Pushed to origin, branch in sync | ChatGPT Web has no local clone; durable Drive-patch workflow is the push plane. Final branch authority and temporary-state cleanup are re-read after the push; `git status -sb` is n/a for this execution environment. |

---

## Review-agent addendum (2026-10-04, resumed `M6-CP1-TB9-A7-R1-REV`)

**Disposition:**
- **Acceptance and promotion: CONFIRMED.** Candidate `11292072930 / 584f80fe...` is the current reviewed runtime authority.
- **One omission found.** R1 deleted a reject-only consistency guard that RA-22 did not authorize removing.
- **RA-22b** restores it, bundled into CB10 as Goal T2. The gate is unchanged (473).
- **One audit obligation added** for `M6-CP1-CLOSE-REV`.
- Accounting 60 / 16 / 44, debt 1. Successor stays `M6-CP1-CB10-A5V`, with its plan amended.

### I1. Independent re-derivation (confirmed)

- I downloaded result `11293546353` again. Its ZIP SHA-256 equals the provider digest `a690ca39...778e`, and `SHA256SUMS` verifies **970/970**.
- The focused ledger is 20/20 PASS in the exact order of `Architecture_M6_CP1_Required_Green_Focused_20.txt`. The selector ledger is 449/449 PASS in exact selector449 file order. No row has a selection or skip anomaly.
- The focused-20 raw log shows `[ OK ]` in 72 s; this is the prior sole RED.
- HEAD `src/`, `include/`, `tests/` and `cmake/` are byte-identical to `584f80fe`.

The RA-22a destination checks fire in the specified order: `:dest-unresolved` → `:dest-region` → `:dest-sheet` → `:dest-component`. The A7 component singleton comes from the retained charts, and the legacy branch keeps its selected-face equalities.

### I2. Finding — R1 removed a reject-only consistency guard RA-22 did not authorize removing (Medium)

**What was deleted.** Before R1, the A7 branch of `close_completion_lineage_source_authority` also required that the representative point's face belong to the class's own authority:

```text
binary_search(retainedSourceRegions, region_for_row(sourcePoint.face))
binary_search(retainedSourceSheets,  sheet_for_row(sourcePoint.face))
```

R1 deleted this check together with `selectedRegion` / `selectedSheet` / `selectedComponent` (diff `a3198ffb..584f80fe`, `PureQuadCompletion.cpp:881-900`).

**Why RA-22 does not cover the deletion.** RA-22 item 1 forbids the representative's face from deciding **selected-relation destination** authority. It does not forbid a reject-only check that the representation leaf is consistent with the class authority it represents.

**What is now undetected.** With the check gone, an A7 lineage whose `sourcePoint` lies on a support-incident face in a region or sheet *outside* the class's retained sets passes this function. Nothing else catches it:
- `sourceSupport == support.identity` only ties the point to the support simplex, not to a sheet;
- the retained-chart loop checks the retained charts, not the point's face.

No test pins `CompletionOwnershipInvalidRetainedSourceAuthority`, so the deletion was invisible to the gate. TB9-R1-REV §3 does not mention it.

This is lesson 189's pattern again: a reject-only guard removed without proving it redundant. The R1 plan's G1 wording ("keep selectedRegion/Sheet/Component only for the legacy path") invited the broader reading.

**Restoring it is provably gate-neutral.** In TB9 (pre-R1 source `b8d27b63`), all 469 processes either passed this exact preflight or, in focused 20's case, failed *later*, at the destination predicate. So every accepted row and the witness already satisfy the guard.

### I3. RA-22b — restore the representative-face guard as reject-only (bundled into CB10, Goal T2)

1. In the A7 branch only (`sourceOccurrences` non-empty), before the retained-chart loop, require:
   - `region_for_row(sourcePoint.face) ∈ sourceTopologyRegions`;
   - `sheet_for_row(sourcePoint.face) ∈ sourceIsolationSheets`.

   Otherwise fail `CompletionOwnershipInvalidRetainedSourceAuthority:representative-face`.
2. The guard may only reject. It must not feed destination, component, chart or lineage decisions (RA-22 item 1 still holds).
3. Strengthen focused 20's body with one negative, without renaming the identity or editing the focused-20 file:
   - in the materialized witness lineage, take one A7 vertex whose `sourceIsolationSheets` has at least two entries (the witness has such multi-sheet classes; they are what failed in TB9), so the emptiness check cannot fire first, and remove the representative face's sheet from `sourceIsolationSheets`;
   - expect exactly `...:representative-face`.
4. Placement in CB10 is deliberate. CB10 already touches A5/A7 shared plumbing for `τ`, and its TB10 reruns focused 1-20 + 21-24 + selector449 = 473, which includes focused 20. Scope beyond these four items is out of bounds; stop for Review.

### I4. Obligation — finish the lesson-191 consumer audit (owner: `M6-CP1-CLOSE-REV`)

R1 fixed one consumer that assumed the representative's face is the class anchor. Other consumers read `sourcePoint` / `vertexProvenance` faces and have not been re-derived against multi-sheet A7 classes:
- the final source-authority validator, through `resolve_compatible_chart` (`SourceAuthoritativeMeshValidator.cpp:1210-1262`);
- `project_surface_cell_vertex_chart_authority`;
- the optimizer's source-point rebinding (`SurfaceMeshOptimizer.cpp:2576`, `:3020`);
- `BenchmarkQuality` field alignment (`:1490-1503`).

The gate exercises completion ownership on the witness, but not the full production chain (completion → optimizer → final oracle) for a multi-sheet class.

`M6-CP1-CLOSE-REV` must classify each such consumer as one of:
- class-wide (safe);
- representation-only (safe);
- anchor-assuming (defect).

Any anchor-assuming consumer blocks CP1 closure. CP3's direct-production torus proof remains the runtime witness for the full chain.

### I5. Closeout

| Duty | Result |
|---|---|
| Primary evidence | Digest, 970/970 manifest, both ledgers in frozen order, focused-20 OK log, HEAD == `584f80fe` re-derived. |
| R1 source | RA-22/RA-22a implemented. **One unauthorized guard removal** (I2). |
| Amendment | RA-22b: representative-face reject-only guard restored in CB10 Goal T2, with a focused-20 negative. Provably gate-neutral. |
| Obligation | Lesson-191 consumer audit for `M6-CP1-CLOSE-REV` (I4). |
| Accounting | 60 / 16 / 44, debt 1. |
| Lesson | 192 — plans must name the guards that stay when they narrow a variable's scope. |
| Successor | `M6-CP1-CB10-A5V`: RA-19, shared `τ`, and RA-22b T2; gate 473. |
