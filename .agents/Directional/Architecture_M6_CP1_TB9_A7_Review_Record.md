# `M6-CP1-TB9-A7-REV` — Independent Runtime-Free Review Record

**Disposition:** REJECTED / A7 PRODUCER UPHELD / COMPLETION-CONSUMER AUTHORITY DEFECT PROVED / CANDIDATE UNPROMOTED / BOUNDED RECOVERY AUTHORIZED.

## 1. Authority independently re-opened

Review re-opened the immutable TB9 evidence instead of relying on the EXEC summary.

- Candidate package/source: `11287202960 / b8d27b63425c11c27c45a1e7b9e2b866b0e1e8b8`.
- Runtime run/job: `37165108302 / 111326336924`.
- Result artifact: `11288673996`, SHA-256 `5ebe700d35159c1cd6448314470daa1701ce44f69edd59ada71d7d5a1695fffa`.
- Log artifact: `11288504403`, SHA-256 `60e19895d2c46bad3fb16ef76200f9fbc7cd5024c6e4d37e7f73991f23156f07`.
- Result `SHA256SUMS`: independently verified **970/970**.
- Mechanical gate: focused **19/20**, selector449 **449/449**, aggregate **468/469**; exact-one selection true, zero skips, benchmark 0, immutable pre/postflight.
- Sole RED: focused20 `M6CP1.NonzeroZ4WitnessPassesProductionCompletionOwnership`; production materialization succeeds, then the real `validate_materialized_completion_domain_ownership(...)` returns `CompletionOwnershipInvalidSelectedRelationDestination`.
- Focused13-19 all PASS. Selector449 is fully green. RA-18 diagnostics `SourceSupportKindMismatch`, `SourceSupportIdentityMismatch`, and `SourceSupportPointMismatch` are absent.

Review source authority is exact snapshot event/source `2800d5049150c7499246b74124719761470238bc`, run/job `37168394385 / 111336124857`, artifact `11289673380`. Git history from semantic source `b8d27b63...` to the review snapshot contains documentation/control changes only; `src/`, `include/`, `tests/`, fixtures and selector/routing semantic authority are unchanged.

## 2. Finding A — completion re-promotes a representation-only point into semantic class authority

**Finding: CONFIRMED / corrective action required.**

Frozen A7 authority is class-wide. `SourceAttachedGeometryProduct` publishes, for each A6 quotient class, the complete sorted unions of member occurrence charts, topology regions and isolation sheets. The deterministic representative supplies compatibility `sourcePoint`/position only and is explicitly forbidden from selecting a representative sheet/chart or changing semantic class authority.

CB9 implements that contract. `SourceAttachedGeometryProducer::produce`:

1. derives one deterministic representative only for compatibility geometry;
2. collects `sourceCharts` from every member `cornerWedgeBinding`;
3. collects `sourceTopologyRegions` from every member occurrence;
4. collects `sourceIsolationSheets` from every member wedge-sheet set;
5. rejects classes whose published chart-component evidence spans more than one source component;
6. retains A6-selected relation paths and never consumes placement transport for A7 geometry/lineage.

`close_completion_lineage_source_authority` then violates that ownership split. It derives `selectedRegion`, `selectedSheet` and `selectedComponent` from `lineage.sourcePoint.face`, i.e. the representation-only representative. For A7 lineage (`sourceOccurrences` nonempty), it correctly preserves `retainedSourceCharts`, `retainedSourceRegions` and `retainedSourceSheets`, and each selected relation path already requires both endpoint charts to be retained. But the final destination predicate additionally requires:

```text
candidateSheet == selectedSheet
candidateSourceComponent == selectedComponent
candidateRegion in retainedSourceRegions
```

The region membership clause is class-wide and is already implied by the earlier retained-chart validation. The sheet equality is not: A7 expressly permits a valid quotient class to retain more than one certified isolation sheet. The source-component equality is also expressed through the representative even though A7's semantic component authority is the singleton component induced by the retained class-wide charts.

This is the authority-domain mismatch exposed by focused20: a class-wide A7 relation destination is judged through singleton values selected from representation-only `sourcePoint`. The failure is therefore downstream of successful A7 production, not an A7 support/embedding failure. The frozen artifact does not instrument which individual boolean in the compound destination predicate evaluates false; Review does not fabricate that subclause. It is sufficient and decisive that the predicate itself consumes the wrong authority domain and that the only RED stops there.

## 3. RA-22 — class-wide A7 completion destination authority

The following amendment is normative for recovery and is copied into `Architecture_M6_Frozen_Definitions.md`.

For lineage with A7 occurrence-binding authority (`sourceOccurrences` nonempty):

1. `sourcePoint` remains representation/compatibility data only. Its face's region, sheet or component may not decide semantic selected-relation destination authority.
2. The selected relation certificate's `startChart` and `endChart` must remain exact members of `sourceCharts`; no search, rebind, substitution or alternate path is permitted.
3. The destination topology region must be a member of `sourceTopologyRegions`.
4. The destination isolation sheet must be a member of `sourceIsolationSheets`. It must **not** be required to equal the representative face's sheet.
5. Source-component authority is derived from the retained A7 charts through `SourceChartTransitionGraph::source_component`. All retained charts must resolve and their unique component set must have cardinality one; otherwise fail closed. The destination component must equal that class-wide singleton.
6. The existing exact support, path endpoint, path continuity, relation-value, composed-transport and no-placement-transport rules remain unchanged.
7. Lineage without A7 occurrence-binding authority retains the established legacy singleton selected-face closure.

RA-22 changes no A5/A6/A7 producer identity, support, topology, selected path, relation-value or transport semantics. It changes only the completion consumer's interpretation of already-published A7 lineage.

## 4. Regression adjudication

`M6-CP1-TB9-A7-EXEC-CAND-01` is adjudicated **CAUSE PROVED / NON-STABLE / existing `RP-01 / AUTHORITY_DOMAIN_CONFLATION` mechanism**.

- Population: new focused20 only; no selector449 accepted-green loss.
- Root mechanism: representation-only representative authority is conflated with class-wide A7 semantic authority in the completion consumer.
- Attribution: the CB9 producer follows frozen R4/RA-18 A7 class-wide publication; the defect is in the pre-existing completion integration seam exposed for the first time by the new production-completion witness.
- Stable accounting: **+0 events / +0 categories / +0 recurrences**. Totals remain **60 events / 16 categories / 44 recurrences**, project debt **1**.
- Candidate `11287202960 / b8d27b63...` remains rejected/unpromoted. Reviewed runtime authority remains TB8 `11265967968 / 8e0818b1...`.

## 5. Recovery scope and stop rules

Review authorizes one bounded recovery turn, `M6-CP1-CB9-A7-R1`, under `Architecture_M6_CP1_CB9_A7_R1_Completion_Ownership_Code_Build_Plan.md`.

Allowed semantic source scope is the completion ownership integration seam, expected to be `src/geometry/PureQuadCompletion.cpp`. The recovery must consume existing class-wide A7 lineage exactly as RA-22 states. It must not change A7 producer semantics, A5/A6 identity/certificates, `canonicalRelationValue`, `canonicalTransport`, RA-18 support rules, fixtures, selector449, focused-20 bytes, or CB10/CB11 reserved identities.

Stop for Review rather than broadening scope if implementation requires changing A7 publication, quotient membership, selected path construction, source-support semantics, fixtures/selectors, or any relation/transport rule.

The recovery Code + Build is compile/package only. If compile-green, `M6-CP1-TB9-A7-R1-EXEC` reruns the **same exact focused20 + selector449 = 469** artifact-only gate. Recovery requires 469/469 and is followed by mandatory `M6-CP1-TB9-A7-R1-REV`. CB10 remains held until that Review accepts recovery.

## 6. Final disposition

TB9 evidence is mechanically authoritative and semantically rejects the CB9 candidate. A7 itself is upheld; completion consumption is amended by RA-22. No runtime, build, source repair or diagnostic rerun occurred in this Review.

Exact successor: **`M6-CP1-CB9-A7-R1`**.

---

## Review-agent addendum (2026-10-04, resumed `M6-CP1-TB9-A7-REV`)

**Disposition:**
- **Rejection and RA-22 confirmed.** The failing subclause is now identified statically (H2).
- **RA-22a added:** site-qualified completion-destination diagnostics.
- **Two A7 fidelity gaps recorded** for CB10 / CP1 closure (H4).
- Accounting unchanged at 60 / 16 / 44, debt 1.
- Successor unchanged: `M6-CP1-CB9-A7-R1`, with its plan amended.

### H1. Independent re-derivation (confirmed)

**Result artifact.**
- I downloaded result `11288673996` again. Its ZIP SHA-256 equals the provider digest `5ebe700d...fffa`.
- `SHA256SUMS` verifies **970/970**.
- The focused and selector ledgers hash to `ccc4c78e...` and `17b27fd3...`.

**Ledgers.**
- The focused ledger is ordered exactly as `Architecture_M6_CP1_Required_Green_Focused_20.txt`. That file's first 12 lines hash to `59a523ae...`, identical to the frozen focused-12 file.
- Focused 13-19 PASS; selector449 is 449/449 PASS.
- The only RED is focused 20. Its raw log shows `validate_materialized_completion_domain_ownership` returning `CompletionOwnershipInvalidSelectedRelationDestination`.

**CB9 source against R4 and RA-18 (verified).**
- Support is read from A5 `occurrence.support`, comparing kind and then identity.
- The same-simplex guard is reject-only: edge parameter `β_b/(β_a+β_b)` or canonical face barycentrics, within `τ` = the resolver barycentric tolerance.
- The adapter's `1e-9` check and `QuotientGeometryConsistencyFailure` are gone from `RemeshPipeline.cpp`.
- The A7 producer region reads no `canonicalTransport` or `relationTransport`.
- Focused 15 asserts both the typed code and the site for each negative.

### H2. The failing subclause, identified statically

TB9-REV §2 declined to name the false disjunct. It can be deduced from invariants that `close_completion_lineage_source_authority` has already enforced before it reaches the destination predicate (`PureQuadCompletion.cpp:1144-1158`):

- **The end chart is resolved and checked.** It is retained (`:997`), it resolves to an exact source row equal to the certificate chart (`:1020-1028`), and that row is in `support.incidentFaces`. So `topology_region`, `isolation_sheet` and `source_component` are all non-null.
- **Region membership is already proved.** The A7 preflight (`:897-920`) requires every retained chart's region and sheet to be in the retained sets. The `candidateRegion ∈ retainedSourceRegions` clause is therefore implied.
- **Component equality is already implied.** Every retained chart's face is incident to the one published support simplex, so all such faces share the representative face's source component on a manifold source. The witness is the closed `milestone-g/torus.obj`, a single connected component.

The only clause left that can be false is **`candidateSheet != selectedSheet`**: the destination member's isolation sheet differs from the representative's sheet. This matches A6 path direction. A6 paths run root (smallest `OccurrenceId`) → target member. The A7 representative is the min of `(support, bindings, id)`, and the destination is a non-representative member whose sheet legitimately differs. A7's `UncertifiedCrossSheetBinding` gate accepted that crossing.

So RA-22 item 4 (sheet membership) is the operative repair. Items 3 and 5 are fail-closed restatements of invariants the preflight already enforces; they are harmless, and kept.

**Production consequence (not a regression; +0).** The promoted runtime `8e0818b1` already publishes the same lineage, and the authoritative pipeline runs this same check (`RemeshPipeline.cpp`, authoritative completion call). The production path therefore rejects, with `NotProductionReady` at `completion`, any authoritative class whose projected HardRail/Periodic selected path ends on a sheet other than the representative's. That includes the nonzero-Z4 torus. Focused 20 is the first gate to run it. This matters for CP3 (direct torus production); R1 removes it within CP1.

### H3. RA-22a — site-qualified destination diagnostics (lesson 181)

No test or production code compares `CompletionOwnershipInvalidSelectedRelationDestination` exactly; source and tests were searched. R1 must suffix it by subclause:
- `:dest-unresolved`
- `:dest-region`
- `:dest-sheet`
- `:dest-component`

The new RA-22 component-singleton failure gets its own site, `CompletionOwnershipInvalidRetainedSourceAuthority:component-singleton`.

If TB9-R1 is not green, the next Review must be able to attribute the residual without new instrumentation. This does not change any predicate.

### H4. A7 fidelity gaps (not R1 scope; recorded for `M6-CP1-CB10-A5V` / `M6-CP1-CLOSE-REV`)

1. **The cross-sheet certification is a proxy.** For a forest edge whose endpoints share no wedge sheet, A7 accepts the crossing if **any** isolation evidence exists on the relation, **or** either occurrence has **any** `cornerWedgeIsolation` (`RemeshPipeline.cpp:5952-5987`). It does not check that the evidence connects the two sheets being crossed. Yet the certificate publishes `relationEvidenceSufficient = true`.

   Frozen §5.2 says only A6's verified wedge/side evidence may establish each cross-sheet step. A6 does validate isolation-seam evidence (RA-12 `:a6-seam-*` sites), so this is redundancy with an overclaiming bit, not an open hole.

   **Required by `M6-CP1-CLOSE-REV`:** either make the A7 check exact — some certified transition maps one endpoint sheet to the other — or delete the proxy and state that A6 is the certifier.
2. **`τ` is not single-sourced.** A7 builds its own default `SurfacePointSourceSupportResolver` to read `τ` (`:5587-5588`), while A5 uses a separate default instance. RA-18 defines `τ` as A5's tolerance. One shared constant or accessor must own both. Fix in CB10, which touches A5.

### H5. Closeout

| Duty | Result |
|---|---|
| Primary evidence | Digest, 970/970 manifest, ledgers, focused-20 prefix identity, sole-RED raw log re-derived. |
| A7 producer | Upheld against RA-18. Old check removed; no placement-transport read. |
| Root cause | Sheet-equality subclause deduced statically (H2). RA-22 confirmed; RA-22a diagnostics added. |
| Production note | Promoted runtime is production-latent on multi-sheet selected-path classes; R1 recovers. No repricing. |
| Recorded gaps | A7 cross-sheet proxy (CP1 close); `τ` single-source (CB10). |
| Accounting | 60 / 16 / 44, debt 1. |
| Successor | `M6-CP1-CB9-A7-R1` (RA-22 + RA-22a) → TB9-R1 469 → mandatory Review. |
