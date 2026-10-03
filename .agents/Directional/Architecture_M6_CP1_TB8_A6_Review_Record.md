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
