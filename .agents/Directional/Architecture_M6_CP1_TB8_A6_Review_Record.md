# `M6-CP1-TB8-A6-REV` — Independent Runtime-Free Review Record

**Disposition:** ACCEPTED / RECOVERY PROVED / CANDIDATE PROMOTED / CP1 REMAINS OPEN.

## 1. Authority independently re-opened

Review re-opened the immutable TB8 result rather than relying on the EXEC summary.

- Candidate package/source: `11265967968 / 8e0818b1e2f8d12b86c64d8774a3572c5ed5266c`.
- Candidate ZIP SHA-256 independently re-hashed: `022a35378a58463b892f1bf1d5113f726c2cc7cb8939892b24acd1da62259c4b`.
- Candidate root `SHA256SUMS`: 28/28 verified; packaged source archive SHA-256 `7220c197eae6b69957b71d6136eb3fce2b6f875bdc3ed3a298537720fef00296`.
- Candidate metadata still says `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `exactArithmeticBackend=GMP`.
- selector449 independently hashes to `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414` with 449 rows; routing449 independently hashes to `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707` with 449 rows.
- Branch comparison from semantic source `8e0818b1...` to review control SHA `c13d157f...` contains only documentation/control-state changes; no `src/`, `include/`, `tests/`, fixtures or selector/routing semantic file changed.

TB8 runtime authority is run/job `37121395619 / 111198068572`. Result/log artifacts are `11273611682 / 11274345428`, provider digests `sha256:55647d752e97cb71062c23475fe76bb870d0329c5f957ca819ccebc809e6ad05` / `sha256:36f674b7dd8eab84b1ad3c9c2486ce94f8a369f81994da3418b1c41fcb34d98e`.

The downloaded result ZIP independently re-hashes to the provider digest and its self-manifest verifies **954/954**.

## 2. Mechanical gate verification

The result ledgers prove the frozen order and complete coverage:

- focused ledger: 12 rows, ordinals 1-12, **12/12 PASS**;
- selector ledger: 449 rows, ordinals 1-449, **449/449 PASS**;
- aggregate: **461/461 PASS**;
- exact-one selection: true for every process;
- zero skips;
- benchmark execution: 0;
- empty RED ledger.

Independent ledger hashes match the EXEC report: focused vector `534771e30147a0d4791f596c8900b6f41d32633011345f563251c344845c04a7`; focused ledger `d9a3e24a59646d90411fecf99b5bf7617cd2346b2f426acb1df2f054e78019d0`; selector ledger `3baad8ec2a7843551dfa4e1ecf07ea9582a3de13b4d74e9257154012343996b8`; combined ledger `20ea03fa623dd8813a5ccf69ec4d3e26023b4ce2db423dc8e11de48eec177592`; header-only RED ledger `3f685d2b69788508657c64cc1bf398cc9a301dc901974c3bac1fc3f2795a6eae`.

Execution boundary is clean: runtime started/completed, preflight complete, no orchestration failure, selection integrity true, and configure/compile/relink/discovery/benchmark/package-repair/mode-repair/source/test/fixture/selector mutation/retry-after-runtime-start all false. Package/source/execution-view/fixture censuses are equal pre/post; selector/routing remain unchanged; root package manifest remains 28/28.

## 3. Recovery adjudication

TB8 satisfies every recovery condition registered by the TB7 Review addendum.

- **HardRail placement authority / RP-01:** focused12 passes the coordinate-rigid two-endpoint mapping and branch-relabel invariance contract. Prior direct/downstream RED rows `115,116,122,130,132,134,137,141,143,150,176,201,217,231` all recover.
- **HardRail route-validation precedence / VALIDATION_ORDER_SHADOWING:** rows227/230 recover their accepted typed behavior; valid-route reciprocity controls 139/142 and owner control 140 all pass.
- **Lineage value / RP-01:** selector446 passes unchanged, proving the restored M5 selected-step relation value is compatible with production completion while A6 placement transport remains separate. Focused6 and periodic controls 232/444/448/449 remain green.
- Raw diagnostic census is zero for `QuotientHolonomyConflict`, `OccurrenceInvalidCornerAuthority`, `InvalidHardRailTransport`, and `RelationCertificateConflict`.

The three TB7 stable events are therefore **RECOVERY PROVED**. Historical stable accounting is append-only and remains **60 events / 16 categories / 44 recurrences**. Produced-witness debt remains **1**.

## 4. Source review and promotion

Review directly re-opened candidate source. A5 applies the shared `exact_interior_route_valid` predicate to both HardRail sides before owner/region/reversed-route pair predicates; malformed routes map to legacy `InvalidHardRailAuthority`. HardRail placement transport is derived only from the four endpoint occurrence `placement.lattice` states, maps both paired coordinates, and does not compare branch rotations. `canonicalRelationValue` is stored separately from `canonicalTransport`; selected lineage steps consume `canonicalRelationValue` while A6 certificates consume placement transport.

Focused12 independently exercises both HardRail endpoint mappings, face-gauge branch relabel invariance, class-member invariance, and the nonzero-Z4 periodic placement-vs-relation-value split. No static contradiction with RA-16 was found.

Candidate `11265967968 / 8e0818b1e2f8d12b86c64d8774a3572c5ed5266c` is **PROMOTED as current reviewed M6 runtime authority** under unchanged selector449 449/449.

## 5. CP1 disposition and exact next turn

CP1 does **not** close here. Frozen CP1 exit scope still requires the A7 `SourceAttachedGeometryProduct`, a thin semantic-free adapter, and the `G4-B002` A6-derived stage boundary. Those were deliberately deferred from R3.

Exact next is runtime-free **`M6-DEFN-R4`**. R4 must freeze:

1. A7 representation/certificates: one embedded output vertex per A6 semantic class, exact source-support and geometry-embedding certificates, complete wedge-union sheet/chart/equivalence lineage, representation-only representative selection, and no topology mutation/reselection.
2. The A6-derived closed-complex `G4-B002` stage-boundary representation and the CP1 equivalence proof on an existing closed fixture; CP3 retains direct-production eligibility/hard-feature-tamper debt proof.
3. The carried exact-A3 periodic obligation: an unequal-corresponding-corner face-gauge witness and replacement of the face-gauged final check with coordinate and relation-gauge checks.
4. Cross-region branch certification for HardRail and OrdinaryFront coordinate identity across isolation seams.
5. The bounded A7 + thin-adapter Code + Build sequence and its pre-registered focused/selector preservation gate.

`M6-DEFN-R4` is Definition-only and runtime-free; implementation remains held pending its mandatory Review. A7/G4 implementation must not start in this Review turn.

---

## Review-agent addendum (2026-10-03, resumed `M6-CP1-TB8-A6-REV`)

**Disposition.**
- **Acceptance and promotion: CONFIRMED.** Candidate `11265967968 / 8e0818b1...` is current reviewed runtime authority.
- **One overclaim corrected:** the §3 selector446 statement (H2).
- **R4 scope: RE-BOUNDED.** The `M6-DEFN-R4` plan now exists: `Architecture_M6_DEFN_R4_CP1_A7_Thin_Adapter_G4B002_Definition_Plan.md`.
- **Accounting unchanged:** 60 / 16 / 44, debt 1.
- **Successor unchanged:** `M6-DEFN-R4`.

### H1. Independent re-derivation (confirmed)

**Result artifact.**
- I downloaded result `11273611682` again; the ZIP SHA-256 equals the provider digest `55647d75...e6ad05`.
- `SHA256SUMS` verifies **954/954**.
- The focused vector, focused, selector, execution and RED ledgers hash to `534771e3...`, `d9a3e24a...`, `3baad8ec...`, `20ea03fa...` and `3f685d2b...`, matching the report.

**Ledgers.**
- The selector ledger equals selector449 (`d4a0d1b7...`) in exact file order: 449 PASS, and every row has selected=1 / skipped=0.
- The focused ledger is 1-12 in the pre-registered order, 12/12 PASS. The focused-12 raw log shows `[ OK ]` (20 s).
- The boundary file records 461 executed and no repair, mutation or retry.

**Source identity.** HEAD `src/`, `include/`, `tests/`, `cmake/` and `benchmarks/` are byte-identical to `8e0818b1` (empty diff).

**CB8 source against RA-16.**
- HardRail placement transport is derived from the four `publishedOccurrenceById(...).placement.lattice` states:
  - the endpoint pairing matches A5's `endpointPairs`;
  - all four scales must be equal;
  - the edge vector must be nonzero;
  - the rotation must be unique;
  - both coordinate pairs are verified.
- CB7's HardRail `action_matches` (the cross-rail branch comparison) is gone.
- `canonicalRelationValue` reproduces the `a532f803` value for every kind. Its canonical inversion is independent of `canonicalTransport`. It feeds `step.appliedTransport` and the A6 step checks (`:4833-4843`, `:4859-4870`).
- The route predicate is one free function, called by A5 before the HardRail pair predicates and reused by the adapter.
- Nit: the duplicate-rotation branch in the `R` search cannot fire for a nonzero edge vector. It is harmless.

**Tests.**
- Focused 3 discriminates the route-validity order: a tampered transition id fires `HardRailRouteAuthorityInvalid`, not `HardRailRouteMismatch`.
- Focused 12(b) relabels only the opposite region, in cells and edges alike. That changes the branch difference across the rail by ±1 and leaves coordinates fixed, so the RA-14 rule would have failed it. The clause therefore discriminates.

### H2. Overclaim: selector446 does not by itself prove production-completion compatibility

§3 says 446 passing "proves the restored M5 selected-step relation value is compatible with production completion".
- 446 re-implements the periodic half of the completion comparator. It does not call `validate_materialized_completion_domain_ownership`.
- The nonzero-Z4 witness, the only Q≠0 fixture, is still never run through the production check that the authoritative pipeline applies at `RemeshPipeline.cpp:10705-10719`.

The claim is a sound inference (the predicates are identical), but it is not executed evidence.

**Resolution.** R4 pre-registers a focused identity for the first A7 CB: the witness materialization must pass `validate_materialized_completion_domain_ownership` with an empty failure. That CB rewrites the lineage projection, so this is exactly when the check is needed. No repricing.

### H3. Re-bounding R4

The §5 R4 list has five items. Items 3 and 4 are the A5 gauge obligations carried from RA-16 §4 and the TB7 addendum §G5:
- the periodic unequal-face-gauge witness and coordinate rule;
- HardRail cross-region branch certification;
- OrdinaryFront coordinate identity across isolation seams.

None of them is a CP1 exit item:
- they only matter on non-constant fields (CP3, direct production on real data);
- they need witnesses that a runtime-free turn cannot build;
- the first Definition turn that asked for too much (`M6-DEFN-R3`) stalled and needed a recovery amendment (lesson-level evidence in `M6_Consolidated_Record.md`).

So R4 is bounded to CP1 exit plus one architectural guard:

- **Guard.** A7 and the adapter must not consume A6 `canonicalTransport` or `relationTransport` for geometry, lineage or chart re-anchoring. A7 embeds from exact A5 source support only (§5.1-5.3). The lineage projects `canonicalRelationValue` (RA-16 §3).
  - Under this guard, the uncertified gauge components cannot reach geometry. Their only consumer is the A6 strict cycle check, which fails closed.
  - The three gauge obligations therefore move to a new, bounded **`M6-DEFN-R5` (CP3-entry gate)**: they must close before any CP3 direct-production TB, not before CP1 closure.

R4 must also cover three things the §5 list omitted:

- **Census first** (lessons 180, 187): before freezing the A7 representation, enumerate every production and test reader of the outputs A7 extraction will produce:
  - `vertexPositions`, `vertexProvenance`;
  - lineage `sourcePoint`, `sourceSupport`, `sourceCharts`, `sourceIsolationSheets`, `sourceTopologyRegions`, `quotientClass`, `equivalences`, `selectedRelationPaths`;
  - `hash_completion` and the lineage hashes.

  Current count: about 400 references across src and tests. R4 must also state which frozen assertions bound each representation decision.
- **Adapter census.** The adapter is still 955 lines with 55 failure-emission sites (`RemeshPipeline.cpp:5548-6503`). R4 must classify each site:
  - A4-product validation → A5;
  - A6 error projection;
  - materialized-mesh validity (non-manifold, open boundary, degenerate/inverted quad, collapsed edge, unreferenced vertex, boundary loops) → A7 `GeometryEmbeddingCertificate`, or A8 if the check is an independent recomputation;
  - pure projection.

  "Thin" is then a checkable predicate: no semantic predicate, no selection, no floating tolerance.
- **Exact support, not an epsilon.** The adapter's `QuotientGeometryConsistencyFailure` compares member positions under a `1e-9` relative tolerance (`:6118-6127`), and it chooses the representative with a semantic-looking key (`:6103-6113`). §5.3 requires the `SourceSupportCertificate` to prove exact support incidence; nearest-position coincidence is forbidden as recovery.
  - R4 must define the exact incidence predicate over `SourceSupport` (vertex/edge/face support compatibility).
  - It must keep any float comparison as a diagnostic only.
  - It must place the representation-only representative rule in A7.

### H4. Procedural repairs (folded in here, not findings)

TB8-REV left the following stale, so this addendum updates them:
- the live handoff section (still "exact next CB8") — the recurring cause of loop stalls;
- ORIENTATION (currency, §3, §7);
- the frozen-definitions status line.

### H5. Closeout

| Duty | Result |
|---|---|
| Primary evidence | Result digest, 954/954 manifest, ledgers and selector order re-derived; focused-12 raw log checked. |
| Source authority | HEAD == `8e0818b1` for all semantic paths; CB8 diff reviewed line by line against RA-16. |
| Acceptance / promotion | Confirmed. `11265967968 / 8e0818b1...` is reviewed runtime authority, selector449 449/449, plus required-green focused 1-12. |
| Corrections | §3's selector446 "production compatibility" claim downgraded to an inference; witness production check pre-registered for the A7 CB. |
| R4 scope | Re-bounded to CP1 exit plus the no-placement-transport-for-geometry guard, with consumer census, adapter census and exact-support rule added. Gauge obligations moved to `M6-DEFN-R5` (CP3-entry). |
| Plan | `Architecture_M6_DEFN_R4_CP1_A7_Thin_Adapter_G4B002_Definition_Plan.md` written. |
| Accounting | 60 / 16 / 44, debt 1 (unchanged). |
| Turn boundary | Runtime-free; no generated Directional executable run. |
