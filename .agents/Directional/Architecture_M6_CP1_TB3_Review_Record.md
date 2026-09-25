# M6-CP1-TB3 Independent Review Record

**Turn:** `M6-CP1-TB3-REV`
**Type:** mandatory runtime-free independent Review
**Disposition:** **COMPLETE / TB3 MECHANICS UPHELD / ONE NEW STABLE ACCEPTED-PREFIX RP-01 EVENT / HARDRAIL RECOVERY PROVED / MULTI-ISOLATION RELATION-OWNER GAP LOCALIZED / CANDIDATE UNPROMOTED**
**Candidate:** artifact/source `10840014758 / 660015f2f15359fd426e2c855aea9f4201c70216`
**TB3 runtime:** run/job `36084948588 / 107914657100`, result/log `10844285398 / 10844020833`
**Accepted predecessor:** artifact/source `10814505512 / e284fea7c101eb86650d1c87c92d0fefa66050e7`, selector449 **449/449 PASS**
**Exact successor:** `M6-CP1-CB4`

## 1. Independent evidence re-opened

Review re-opened the immutable CB3 candidate, TB3 result evidence, the accepted M5 TB2 result, selector449/routing449 bytes, current frozen M6 definitions, and exact current source instead of accepting the EXEC report as proof.

Candidate artifact `10840014758` re-verifies at provider/download SHA-256 `b1117c6efe2cdc8a04e46647fd1bb5af79094234a03348df8ffd6e6ae5ed5c66`; its root manifest is **28/28**, semantic source is `660015f2f15359fd426e2c855aea9f4201c70216`, packaged source archive SHA-256 is `90c6305132ceca1bcd5f12dfd03a7a3b818fe3e9462128dedb5c3f5788f67ecc`, GMP/GMPXX authority is present, build/preflight receipts are zero, source receipts are clean, and the package records `runtimeExecution=false`.

TB3 result `10844285398` independently verifies **929/929** files. Its ledger contains exactly **455** planned processes: six focused identities followed by selector449 in exact order. Totals are focused **4/6 PASS**, selector449 **443/449 PASS**, aggregate **447/455 PASS**; every process selected exactly one test, none skipped, benchmark count is zero, no build/configure/relink/discovery/repair occurred, and package/source/execution-view postflight is byte-exact.

Selector449 remains exactly 449 LF rows at SHA-256 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`; routing449 remains `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707`. Freshly reopened accepted M5 result `10815911956` verifies **911/911** evidence files and **449/449 PASS** with exact-one selection and zero skips. Its ordinals 186, 214, 239, 444, 446 and 448 are all PASS, so the six TB3 selector losses are accepted-prefix PASS -> RED transitions.

GitHub compare proves semantic source `660015f2...` is an ancestor of the Review snapshot and that source..Review changes touch only documents/control-plane files: no `src/`, `include/`, `tests/`, `benchmarks/`, CMake or `cmake/` byte drift exists. Static review of the snapshot is therefore evidence about the tested semantic source.

## 2. TB3 mechanics are upheld and the common RED family is non-vacuous

The eight RED processes are organic semantic outcomes from a mechanically valid immutable gate. Focused rows5/6 and selector ordinals **186, 214, 239, 444, 446, 448** all fail first at `MissingIsolationSeamEquivalenceAuthority`. No process reports `OccurrenceInvalidCornerAuthority`. Selector ordinal140 `HardRailPairExplicitRailIdMismatchRejectsStrictTransport` PASSes the unchanged accepted negative, proving CB3 restored its specific `InvalidHardRailTransport` contract.

The common family is not a vacuous assertion change. Accepted row186 independently constructs one checked isolation-seam certificate with distinct sheets and reciprocal transport before materialization; accepted row239 establishes the same cross-sheet source-adjacent condition; the three produced-torus rows were accepted green on the M5 producer authority; focused pair-swap was also PASS at TB2. TB3 reaches the new relation-equivalence guard before those tests' former downstream assertions. Deleting that guard would change the observed outcome, so the mechanism is active rather than report-only.

## 3. Root cause: A5 omits relation-owned isolation-equivalence authority and A6 reconstructs it from representation paths

The frozen A5 contract already requires every `ownedRelations[]` entry to carry a **typed relation owner / certificate reference**; A6 may consume only that published authority and may not search for or synthesize a missing relation. A7 permits a multi-sheet quotient only when A5/A6 relation certificates explicitly establish the equivalence.

Current implementation does not realize that contract for an ordinary cross-sheet relation:

1. CB3 correctly assigns each A5 occurrence's sheet from the start of its authoritative outgoing directed side, while requiring the side-attached representation and canonical corner to resolve the same exact `SourceSupport`.
2. `SurfaceOccurrenceRelation` stores semantic endpoints plus `firstFrontEdge/secondFrontEdge`, explicitly labeled representation projection only. `OrdinaryFront` publishes no isolation-seam certificate reference.
3. The transitional materializer separately scans each owning cell side's boundary-path `entryRoute` into `isolationSeamsByFrontEdge`.
4. For an ordinary reciprocal front pair it unions those front-edge-derived seam lists, then compares the **A5 occurrence endpoint sheets**. If an endpoint pair spans sheets while the reconstructed list is empty, it returns `MissingIsolationSeamEquivalenceAuthority` before quotient union.
5. Final lineage itself is sound with respect to this boundary: `sourceIsolationSheets` is the sorted set of actual quotient-member `occurrence.isolationSheet` values. The failure occurs before the relation can legitimately form that quotient.

This is an authority-domain defect, not a reason to restore CB3's rejected global-certificate augmentation. The semantic datum is **which exact checked isolation certificate owns this cross-sheet occurrence relation**. Current code tries to rediscover that ownership later from front-edge/boundary-path representation traversal. A representation path can be valid while not traversing the seam that explains the relation endpoint sheet change; certificate inventory can also contain valid but unrelated seams. Neither is the A5 relation-owned reference required by the frozen contract.

**Classification:** `M6-CP1-TB3-EXEC-CAND-01` becomes **one stable event / existing `RP-01 AUTHORITY_DOMAIN_CONFLATION` recurrence**. Six accepted selector identities transition PASS -> RED at one common first-failure mechanism; the two focused losses localize the same mechanism and do not add stable events. Stable accounting advances **53 -> 54 events / 16 categories / 37 -> 38 recurrences**. Produced-witness debt remains **1**, M6-owned.

## 4. Prior-candidate dispositions

- **`M6-CP1-TB2-REV-CAND-01` (`VALIDATION_ORDER_SHADOWING`) — CLOSED / RECOVERY PROVED.** Row140 is fresh PASS with the established `InvalidHardRailTransport` outcome. Its historical stable event remains counted; recovery never subtracts an event.
- **`M6-CP1-TB2-REV-CAND-02` (focused multi-isolation) — MERGED INTO TB3 CAND-01 / STILL OPEN.** CB3 made the intended distinct-sheet occurrence authority visible, but the witness now stops earlier at the missing A5 relation-owned isolation certificate. The original downstream `foundMultiIsolationLineage=false` is superseded as first failure, not disproved as a closure obligation.
- **`M6-CP1-TB1-EXEC-CAND-01` (`CROSS_TEMPORARY_ITERATOR_RANGE`) — MECHANISM CLEARED / FORMAL RECOVERY STILL OPEN.** `OccurrenceInvalidCornerAuthority` remains absent, but the frozen recovery rule also requires a fresh selector449 **449/449**. TB3 is 443/449, so Review does not rewrite that pre-registration.

Accepted runtime authority therefore remains M5 package/source `10814505512 / e284fea7c101eb86650d1c87c92d0fefa66050e7` under selector449 **449/449 PASS**. Candidate `10840014758` remains unpromoted and grants no CP1/G4 closure.

## 5. Bounded successor

Exact successor is runtime-free Code + Build **`M6-CP1-CB4`**. It owns one semantic correction only: implement the already-frozen A5 relation-owned isolation-equivalence reference for ordinary relations whose occurrence endpoints span isolation sheets, and make the transitional A6/materializer consume that published reference instead of deriving semantic owner authority from front-edge boundary-path traversal.

CB4 must not change occurrence identity, outgoing-side sheet authority, source support, quotient equality, tests, fixtures, selector449/routing449, periodic/HardRail owner semantics, or revive certificate-inventory substitution. If the exact isolation certificate cannot be derived uniquely from already-accepted A4/M5 typed authority for the relation without inventing a new semantic rule or changing the frozen A5 contract, CB4 stops and returns to Review/Definition.

If compile/package is green, the exact runtime successor is `M6-CP1-TB4-EXEC`: unchanged six focused + selector449 = **455** fresh exact-filter processes, followed by mandatory `M6-CP1-TB4-REV`. Recovery-green requires 6/6 focused, 449/449 selector, row140 still PASS, no `OccurrenceInvalidCornerAuthority`, all six TB3 selector losses recovered, multi-isolation lineage spanning >1 sheet with relation evidence, pair-swap PASS, exact-one/zero-skip, benchmark 0 and immutable postflight.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | selector449 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`; routing449 `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707`; accepted result `10815911956` independently re-opened at 449/449 |
| Decisive claims independently re-derived | candidate 28/28; TB3 result 929/929 and 455-process ledger; accepted 449/449 differential; no code drift from semantic source; A5 relation shape, materializer seam reconstruction/guard, and quotient-lineage sheet derivation |
| Non-vacuity checked | row186 proves a real checked distinct-sheet certificate before the failing call; accepted torus rows and TB2 pair-swap provide prior green controls; all eight TB3 REDs reach the active `MissingIsolationSeamEquivalenceAuthority` guard |
| Prior obligations discharged/carried | TB2 row140 stable event recovery-proved closed; TB2 focused multi-isolation merged into active TB3 RP-01 event; TB1 iterator mechanism cleared but formal 449/449 recovery clause carried |
| Stable accounting | **54 / 16 / 38**, debt **1**; accepted package/source `10814505512 / e284fea7...`, selector449 449/449 |
| New candidates/obligations recorded | `M6-CP1-TB3-EXEC-CAND-01` adjudicated stable existing-RP-01 recurrence; tracker updated; CB4/TB4 recovery obligation frozen |
| ORIENTATION currency line | `M6-CP1-TB3-REV`, 2026-09-25 UTC |
| ORIENTATION §3 / §4 / §7 / §8 | §3, §7 and §8 updated; §4 n/a because accepted witness state did not change |
| CHANGELOG | root and Directional changelogs updated newest-first |
| ROADMAP | M6-CP1 updated to TB3 Review / CB4 next |
| Selector manifest | n/a — no selector was added, changed, published or accepted |
| LESSONS | existing single-authority/representation lessons 22 and 30 cited; no genuinely new lesson added |
| Consolidation under CLEAN_UP_POLICY | CB3 plan/report, TB2 report/Review and consumed TB3 plan folded into `M6_Consolidated_Record.md` and removed; retained TB3 runtime report, this Review, frozen definitions, consolidated record and one CB4 plan |
| Successor frozen | exactly `M6-CP1-CB4`; falsifier and stop rule are in §5 and the CB4 plan |
| Turn boundary held | runtime-free Review; no Directional compile/runtime and no product/test/fixture/selector/benchmark/build-source mutation |
| review_check.py boundary | **PASS** — all boundary, selector-hash and durable-marker checks passed on the complete Review diff |
| `STATUS` lifecycle maintained | entry beacon `M6-CP1-TB3-REV / IN_PROGRESS` published; final COMPLETE beacon is reserved as the final repository write with exact successor `M6-CP1-CB4` |
| Pushed to origin, branch in sync | **CONFIRMED by configured-branch patch application/cleanup authority checks; no alternate ref used.** Final `STATUS` write follows only after cleanup verification. |

## Review-agent addendum — `M6-CP1-TB3-REV` (2026-09-25 UTC)

**Disposition of this addendum:** TB3 mechanics, evidence, the accepted-prefix differential, stable accounting **54 / 16 / 38**, debt **1** and all three prior-candidate dispositions are **UPHELD**. The §3 root-cause statement is **CORRECTED**. The §5 successor is **REPLACED**: `M6-CP1-CB4` is **HELD**, and the exact next turn is runtime-free **`M6-DEFN-R1`**. The CB4 plan stays on file as HELD and is re-scoped by the definition.

### A1. Evidence independently re-derived

- **Candidate `10840014758`:** provider digest and download SHA-256 are both `b1117c6e...ed5c66`. Root `SHA256SUMS` verifies **28/28** and hashes to `00b929727e0fdbca25597e06e58bb516c20866bc0384d5e47b22e5936f92ded3`. The packaged source archive is `90c63051...67ecc`, and its `src/pipeline/RemeshPipeline.cpp` is byte-identical to `git show 660015f2:src/pipeline/RemeshPipeline.cpp` (`9436ad68...`).
- **TB3 result `10844285398`:** SHA-256 is `f1eeae63...8901b`. Its self-manifest verifies **929/929** and hashes to `e0072696...a9dce`. The focused and selector ledgers hash to `7e406031...3a7` and `811fad03...dc7a`. Selector-ledger identities equal selector449 byte-order exactly, with 449 rows, 443 PASS and every row exact-one/zero-skip. Focused rows 1-4 PASS and rows 5-6 are RED.
- **Raw RED logs:** all eight carry `MissingIsolationSeamEquivalenceAuthority` at a `*.success` assertion. None of the 455 raw logs contains `OccurrenceInvalidCornerAuthority`, and row140 is `[ OK ]`.
- **Log `10844020833`:** SHA-256 is `c3c99a9d...2f9`.
- **Accepted M5 result `10815911956`:** verifies **911/911** and 449/449 PASS. Ordinals 140, 186, 214, 239, 444, 446 and 448 are all PASS there.
- **No semantic drift:** `git diff 660015f2..HEAD` over `src/ include/ tests/ CMakeLists.txt cmake/` is empty.

### A2. Correction to §3: CB3's outgoing-side sheet is a representative choice, and the regressions prove the nodes lie on seams

§3.1 says CB3 "correctly" assigns each occurrence's sheet from its outgoing side. The source does not support that.

1. **All occurrences at a lattice node share one corner point.** Every phase-front builder writes `cell.corners[c] = points[nodeIds[c]]` (`SurfaceCellTracing.cpp:12079`, `:13749`, `:16308`). Before CB3, A5 took the sheet from `cell.corners[c].face`, and accepted M5 used the same rule (`e284fea7:RemeshPipeline.cpp:3450-3468`). Every occurrence at a node therefore carried the same sheet, so no A6 class could span two sheets. The TB2 focused RED was never-green behaviour of the accepted rule, not a CB1 regression.
2. **The TB3 REDs prove each failing fixture has a lattice node on a seam.** `bounded_disk_chart_segment` builds each side from positive-length intervals only (`:12581-12700`). A node strictly inside a face therefore gives every outgoing side a first segment in that face. A node inside a non-seam edge touches two faces of the same sheet. Endpoint sheets can differ only when the node's exact support is a seam edge or seam vertex; before that, support equality is enforced (`AuthoritativeFrontPairSourceSupportMismatch`). All eight REDs thus prove seam-incident nodes exist in the split square, in the row239 fixture and on the produced torus.
3. **At such a node the cell's corner wedge spans the seam, so any single sheet is a representative.** Split square: faces (v0,v1,v2) = sheet 0 and (v0,v2,v3) = sheet 1; seam edge (v0,v2); 2×2 lattice (`:16222`), with nodes v0, the seam-edge midpoint and v2 on the seam. Cell (0,0)'s corner at (½,½) has its incoming side 1 in face 0 and its outgoing side 2 in face 1. "Outgoing" is an orientation convention, not an authority.
4. **The rule already drops a sheet in the witness fixture.** Vertices (0,0) = v0 and (1,1) = v2 are single-occurrence classes. Their supports and quad-corner wedges touch both sheets, but their lineage records {0} and {1} respectively. This is exactly what frozen A7 forbids ("never selects a representative sheet and silently discards the others"). Focused row 5 cannot see it because it only asks for **one** multi-sheet lineage.

### A3. Correction to §3/§5: the relation is the wrong owner for the certificate

Take a relation along side *s* of cell A, opposite side *t* of cell B. Its endpoint pairs are `(A[s], B[t+1])` and `(A[s+1], B[t])` (`RemeshPipeline.cpp:3454-3463`). In each pair, one endpoint's sheet comes from the relation's own side and the other from the neighbouring cell's **next** side.

So a cross-sheet endpoint pair means that neighbour's **corner wedge** crosses the seam. The relation itself lies in one face near the node. Front-edge seam evidence is built only from `entryRoute` of the second and later segments (`SurfaceCellTracing.cpp:11515`; scan at `RemeshPipeline.cpp:3898-3933`), so it can never record a crossing located exactly at the node. The M5 traversal guard is not what failed. What failed is that CB3 moved the sheet change into corner wedges while leaving the guard to look for it on relations.

Consequences for the CB4 plan as frozen:

- **The "owning" certificate cannot be derived from the relation.** It can only be found through the endpoints' shared exact support, i.e. a `(region, seam edge)` lookup. Which relation receives it also depends on the incoming/outgoing convention: reversing the A4 cycle moves it from the (0,0)–(1,0) relation to the (0,0)–(0,1) relation.
- **"Exactly one certificate" fails at seam vertices.** `isolationCertificateBySeam` is keyed per seam **edge** (`:3597`, `:3641`). Production sheets come from the close-sheet proximity classifier (`SurfaceCellTracing.cpp:7343+`), so seams are chains of edges. An interior seam vertex has ≥2 incident seam edges with the same sheet pair. The plan's single-owner rule is therefore ambiguous at `SourceVertexSupport` endpoints. It would reject a legitimate configuration or force a representative choice. Which support kinds the torus REDs hit cannot be decided without running the code, so the definition must cover both.
- **The required static trace cannot be done for three of the four fixtures.** CB4 must trace "each TB3 failing subject" runtime-free, but the produced-torus fixtures (and pair-swap) only exist by running the pipeline. Only the split square can be traced analytically.
- **"Already-frozen" is an overclaim.** Frozen §3.2 has no isolation owner for `OrdinaryFront`. The A5 validator requires `OrdinaryFront` to carry **no** owner (`ownerValid`, `:3177`). `OccurrenceRelationId` is built from `(kind, first, second, hardRail, periodicRelation)`. Adding an isolation owner is a new relation-owner type that either changes relation identity or adds an owner field outside identity. That is a definition decision, and it trips CB4's own stop rule: "a frozen A5/A6 semantic statement must be changed rather than merely implemented".
- **3feb24ef is mis-described.** §3 and the CB4 plan call the first CB3 attempt "global certificate-inventory augmentation". It was a keyed lookup: `isolationCertificateBySeam.find({region, edgeSupport->edge})`, applied only when both endpoints share the identical `SourceEdgeSupport` and the certificate's sheet pair equals the endpoint sheet pair. That is the only typed derivation the relation-owned model has. CB4's "do not restore" wording would forbid the only rule CB4 could implement.

### A4. New code finding: CB3 left each occurrence record built from two different faces

At `660015f2`, an occurrence takes its point, support, component and sheet from the outgoing side's first face F_out (`RemeshPipeline.cpp:3330-3368`). Its `lattice.sourceChart`, `branchRotation` and phase still come from the node's representative face F_node (`SurfaceCellTracing.cpp:16308-16335`). `projectionChart` pairs F_node's field chart with F_out's face topology (`RemeshPipeline.cpp:3380-3382`). The quotient domain state then combines F_out's sheet with F_node's `branchRotation` and chart (`:4427-4432`), and the representative key combines `point.face` with `chart.chart` (`:4503-4516`).

This validates only while field-chart IDs happen to coincide across a node's faces, and `branchRotation` is F_node-relative while labelled with F_out. 3feb24ef re-derived chart and branch from the outgoing segment; the "reconcile" commit removed that. The CB4 plan freezes "frozen lattice state" and "CB3 outgoing-side sheet" together, which freezes this inconsistency.

### A5. Row140 recovery: upheld, with two design notes (not events)

1. `surface_occurrence_complex_error_name(HardRailOwnerMismatch)` returns the M5 materializer string `"InvalidHardRailTransport"` (`:3057`). It is the only A5 name outside the `Occurrence*` vocabulary. The M5 compatibility mapping belongs in the adapter (`:3749-3753`).
2. A5's generic `UnownedRelation` still pre-empts three other M5 checks, which are now unreachable duplicates:
   - `MissingHardRailRelationOwner` (`:4211`);
   - the owner-mismatch/missing half of `InvalidPeriodicRelationOwner` (`:4219-4223`);
   - the boundary-kind half of `IncompatibleAuthoritativeFrontPair` (`:4115-4120`).

   No test pins these codes, so nothing is counted. But the single-authority rule CB3 cited has been applied to one of four duplicated checks. The definition turn should record the policy (delete, or keep as commented defence-in-depth), and CB4 should apply it.

### A6. Accounting and root-cause wording

The count stands: one mechanism, six accepted PASS→RED rows, one stable event, existing **`RP-01 AUTHORITY_DOMAIN_CONFLATION`**, **54 / 16 / 38**, debt **1**. The conflation is CB3 promoting a representation choice (the face where the outgoing side starts) to occurrence sheet authority. The CB3 reconcile then removed the dependent keyed certification. "A5 omits a frozen relation-owned certificate" is TB3-REV's proposed repair model, not the proven cause. This addendum adds no events.

### A7. Successor: `M6-DEFN-R1` (runtime-free Definition amendment), then mandatory `M6-DEFN-R1-REV`

The definition must freeze, with worked examples, how isolation sheets are owned at seam-incident corners. The recommended resolution comes first; if the alternative is chosen, the record must say why.

1. **Occurrence sheet authority at seam-incident corners.** *Recommended:* each occurrence carries a sorted, non-empty **corner-wedge sheet set**. It is the sheets of the source faces covered by the cell's corner wedge between the last positive-length segment of the incoming side and the first positive-length segment of the outgoing side, around the exact support. An edge support covers ≤2 faces; a vertex support covers the contiguous fan arc on the cell's interior side. It is a singleton at every corner not on a seam, so all current single-sheet behaviour is unchanged. `OccurrenceId` is unchanged.
2. **Where the certificate lives.** *Recommended:* on the occurrence wedge. Its certificates are exactly the `(region, seam edge)` certificates of the seam edges the wedge fan crosses, each with a matching sheet pair. This is unique by key, needs no search and picks no representative, including at interior seam vertices. A missing certificate is a typed A5 failure. *Alternative (the CB4 model):* relation-owned, which must then define the owner type, whether it enters `OccurrenceRelationId`, the vertex-support rule, and the A7 completeness gap at single-occurrence corners.
3. **Relation check in A6/transitional materializer.** `OrdinaryFront` relations stay owner-less and `OccurrenceRelationId` is unchanged. The endpoint-sheet equality in `crossesSheets` is replaced by: the relation side's near-endpoint face sheet ∈ both endpoints' wedge sets. Mid-side crossings keep their current front-edge certificate evidence.
4. **Sides collinear with a seam edge.** `bounded_disk_chart_segment` breaks ties by the lexicographically smallest triangle (`:12648`), which is a representative face. Define each side's sheet per incident cell, or declare the case unsupported with a typed failure.
5. **A7 lineage completeness.** `sourceIsolationSheets` = union of member wedge sets; equivalence evidence = the wedge certificates. Amend the frozen A7 sentence "relation certificates explicitly establish that equivalence" to name the certificate carrier.
6. **Single-face occurrence record.** An occurrence's point, support, chart, branch and sheet provenance come from one declared face (or are defined per wedge). No mixing (A4).
7. **Worked examples.** Analytic for the split square: all 16 occurrences' wedge sets and certificates; the four-member class at (½,½); the singleton classes at v0 and v2, which must record {0,1}. Plus one interior seam-vertex example showing uniqueness.
8. **Row140 follow-ups.** Record the A5.1 naming/adapter placement and the A5.2 policy for the unreachable duplicate checks.
9. **CB4 re-scope and TB4 pre-registration.** Recommended: one new focused identity asserting that split-square seam-endpoint vertices record both sheets. With it the gate becomes 7 + 449 = 456 processes; the existing six identities and selector449/routing449 bytes are unchanged.

The definition must not change `OccurrenceId`, `CellId`, `QuotientClassId`, relation-only equality, HardRail/Periodic ownership, selector449/routing449, or any existing test or fixture. After `M6-DEFN-R1-REV`, the re-scoped `M6-CP1-CB4` implements the frozen rule, then unchanged immutable TB4 plus mandatory Review.

### A8. New lesson

`LESSONS.md` 179: certify a transition on the object where it happens.

### Review-agent closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | selector449 `d4a0d1b7...d6414`, 449 LF rows, ledger order byte-identical; routing449 `9c88a5ed...c5707` unchanged |
| Decisive claims independently re-derived | candidate 28/28 and packaged source byte-identical to `660015f2`; TB3 929/929, both ledgers, 443/449, eight raw RED strings, zero `OccurrenceInvalidCornerAuthority`; accepted `10815911956` 911/911 and 449/449 with all seven differential rows PASS; zero semantic drift |
| Non-vacuity checked | A2.2 shows the eight REDs require seam-incident lattice nodes; A2.4 shows the focused identity is too weak to see the completeness gap |
| Prior obligations discharged/carried | TB2-CAND-01 closed (recovery proved), TB2-CAND-02 merged/open, TB1-CAND-01 formal 449/449 clause open: all upheld |
| Stable accounting | **54 / 16 / 38**, debt **1**; this addendum adds no events |
| New candidates/obligations recorded | successor replaced: CB4 HELD, `M6-DEFN-R1` scope A7.1-A7.9; findings A2-A5 in tracker |
| ORIENTATION currency line | `M6-CP1-TB3-REV` (review-agent addendum), 2026-09-25 UTC |
| ORIENTATION §3 / §4 / §7 / §8 | §3, §7 and §8 amended; §4 n/a (no witness acceptance change) |
| CHANGELOG | root and Directional prepended newest-first; the misplaced `M6-CP1-TB3-EXEC` heading moved back above its own bullets |
| ROADMAP | status line and M6-CP1 row set to DEFN-R1 next |
| Selector manifest | n/a |
| LESSONS | 179 added |
| Consolidation under CLEAN_UP_POLICY | CB4 plan kept and marked HELD; new `Architecture_M6_DEFN_R1_Seam_Incident_Occurrence_Sheet_Authority_Plan.md` is the single live successor plan; nothing new folded |
| Successor frozen | exactly `M6-DEFN-R1`, then `M6-DEFN-R1-REV` |
| Turn boundary held | runtime-free; no source/test/fixture/selector/benchmark change, no compile, no Directional runtime |
| review_check.py boundary / ledgers | recorded in the final commit message |
| `STATUS` lifecycle maintained | resume IN_PROGRESS (`Resumed at` = operator handoff `2026-09-25T03:19:31Z`) → docs → COMPLETE last, successor `M6-DEFN-R1` |
| Pushed to origin, branch in sync | verified after the final push |
