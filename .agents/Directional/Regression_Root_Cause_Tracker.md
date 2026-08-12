# Surface-Cell Regression Root-Cause Tracker

Permanent stable-ID regression, repeated-pattern, architecture, and test-authority index for PR #8. Detailed historical event evidence remains in `.agents/Directional/PR_8_Regression_Audit_Inventory.md`; the current immutable turn report owns current artifact/runtime detail.

Last updated: **2026-08-12 UTC** after the R-A closure-gate review of working-branch implementation `5e023f1a8331c53182cfd296732c37cb7a889b88`.

## Rules

- Assign a stable regression ID only when previously accepted behavior/test/package/public authority is lost.
- Persistence while a gate remains red is not a recurrence; recurrence requires restoration followed by later loss.
- Compile success never resolves runtime or architecture migration work.
- New migration code remains pending until immutable semantic acceptance.
- Known-red/deferred product cases stay explicit and are never relabeled green/expected-failure to close architecture work.
- Focused/helper passes cannot close representative product intent.
- Before every turn review `RP-01` through `RP-09`; every touched pattern needs an exact invariant and counterexample/representative gate.
- Stale per-turn documents are not historical authority. Once their necessary facts are folded into this tracker/current report/audit inventory/changelog, they may be removed under `.agents/Directional/CLEAN_UP_POLICY.md` and `.agents/Directional/RETENTION_POLICY.md`.

## Historical PR-wide authority

- **34 distinct regression events**;
- **14 architectural categories**;
- **20 recurrences**;
- **114 regression-bearing result-document commits**.

T1 artifacts `9040549377 / 9041289209`, accepted M1a artifact `9041930767`, accepted M1b artifact `9042940168`, accepted M1c artifact `9043971772`, accepted M1d artifact `9046308272`, accepted M1e artifact `9049125645`, and accepted M1f artifact `9050850344` create no new production regression event or recurrence. M1f runtime authority is accepted. Accepted M1g artifact `9053047653` likewise creates no stable product regression event or recurrence; M1g semantic acceptance is complete. M1h artifact `9066967620` created no stable product regression event: its sole focused failure was classified as a test-authority witness defect while all entering product/preservation authority remained unchanged. Remediation artifact `9069186973` is now immutable accepted with focused **6/6**, required-green **187/187**, full entering preservation/direct-product authority, unchanged historical-red classes, and exact postflight. M1i implementation `b037157921094604f1b0c17f9c8b7076c7604b3b` is immutable accepted from artifact `9072101943`: focused **6/6**, required-green **193/193**, full entering preservation/direct-product authority, unchanged historical-red classes, bounded Bunny/Vase comparison, and exact postflight. No stable product regression event or recurrence is added. `PR8-R034 / G4-R007` remains active. M1j implementation `d5f681173600dc32dc7617de6105d9e584e593be` is immutable accepted from artifact `9076217893`: producer discovery **214**, focused **6/6**, required-green **199/199**, full entering preservation/direct-product authority, all eight historical-red classes unchanged, strict timing truthfully **0/10**, bounded Bunny/Vase comparison, and exact **67/67** postflight. No stable product regression event or recurrence is added. M1k implementation `b9181364926cea840e9cb50da21fe721f33fd874` is immutable accepted from artifact `9079318682` and runtime evidence `9080245848`: producer **220**, focused **6/6**, required-green **205/205**, full entering preservation/direct-product authority, all eight historical-red classes unchanged, Bunny/Vase dispositions preserved, and exact **68/68** postflight. Strict timing sampled **10/10** but remains the existing nondeterministic microbenchmark classification. The local extraction/harness anomalies and first remote evidence-upload-path failure are infrastructure only. No stable product regression event or recurrence is added. M1l implementation `bd140cff4572412e6f4ecd70a6ce0fe85310932c` is immutable accepted from artifact `9083262395` and runtime evidence `9083913766`: producer **226**, focused **6/6**, required-green **211/211**, full M1k-M1b/validation/M1a/T1/direct-product preservation, all eight historical/deferred red classes unchanged, strict timing truthfully sampled **10/10** while remaining deferred, Bunny/Vase dispositions preserved, and exact **56/56** postflight. The local first-process Cylinder stall did not reproduce remotely and is execution-plane only. No stable product regression event or recurrence is added.

| Cause category | Pattern | Events | Recurrences |
|---|---|---:|---:|
| `AUTHORITY_DOMAIN_CONFLATION` | `RP-01` | 6 | 5 |
| `TEST_AUTHORITY_COVERAGE_GAP` | `RP-02` | 6 | 5 |
| `POLICY_STAGE_STATE_CONFLATION` | `RP-03` | 4 | 3 |
| `NONTERMINATING_CUMULATIVE_WORK` | `RP-04` | 3 | 2 |
| `REPRESENTATION_DEPENDENT_IDENTITY` | `RP-05` | 2 | 1 |
| `STATE_CARDINALITY_GROWTH` | `RP-06` | 2 | 1 |
| `CYCLIC_TOPOLOGY_LINEARIZATION` | `RP-07` | 2 | 1 |
| `PRODUCER_DISPOSITION_CONFLATION` | `RP-08` | 2 | 1 |
| `LOCAL_CONSUMPTION_OF_GLOBAL_AUTHORITY` | `RP-09` | 2 | 1 |
| five singleton categories | — | 5 | 0 |
| **Total** |  | **34** | **20** |

Singletons: `INTRINSIC_SUPPORT_OVERCONSTRAINT`, `INCOMPLETE_TRANSACTIONAL_ROLLBACK`, `SHARED_EDGE_ORIENTATION_INVERSION`, `INCOMPLETE_ORBIT_PUBLICATION`, `EXACT_SIMPLEX_CANONICALIZATION_LOSS`.

## Repeated coding-pattern catalog

### RP-01 — authority-domain conflation

```text
bad: one bare integer is reused as face/transition/chart/rail/etc.
good: distinct semantic type + checked construction at ingress + typed failure.
```

- M1a strong-ID kernel: **accepted**.
- M1b source-face/source-vertex production consumer: **accepted**.
- M1c field-transition source-face/source-vertex consumer: **accepted**.
- M1d phase-front route source-vertex/interior-transition consumer: **accepted**.
- M1e ordered segment-route step identity is accepted. M1f continuation-route steps cross checked source-vertex/interior-transition boundaries before `TransitionStep` construction and immutable runtime acceptance is complete.
- M1g periodic crossings cross checked source-vertex/interior-transition boundaries before `TransitionStep` construction and are **immutable accepted**.
- M1h phase-front field charts cross checked `FieldChartId` boundaries before constructive-front semantic use and are **immutable accepted**. M1i cell-owned source component/sheet state through checked `SourceComponentId` / `IsolationSheetId` is **immutable accepted**. M1j immediately adjacent `SurfaceFrontEdge` component/sheet authority is **immutable accepted**. M1k edge-owned topology-region identity and M1l cell-owned topology-region identity are **immutable accepted** as checked `TopologyRegionId`. The final M1 cutover now removes every remaining stored numeric duplicate and makes the semantic model authoritative from producer through materializer.

M1d accepted invariants:

- packed route endpoint values are range-checked before `SourceVertexId` construction and semantic use;
- supplied and authoritative compact route values are range-checked before `InteriorTransitionId` construction;
- semantic transition equality is `InteriorTransitionId` equality, not raw integer equality;
- malformed IDs remain fail-closed through existing HardRail/PeriodicCut authority failures.

### RP-02 — proxy/incomplete test authority

```text
bad: compile/helper/status/count claimed as product proof.
good: named semantic contract + independent oracle + direct representative evidence.
```

`RP-02 / TA-05` remains **test-authority resolved and preserved through M1g** under immutable artifact execution:

- producer discovery exactly **196**;
- required-green producer segment **181/181**;
- M1d focused **6/6** plus route counterexamples **3/3**;
- M1c focused **6/6** plus transition counterexamples **3/3**;
- M1b focused **6/6**, validation **77/77**;
- M1a exact 14 and **14/14**;
- T1 exact 29 and **29/29**;
- Plane/MultiFaceSeam/CloseSheets/Cylinder green and independent-oracle clean;
- nine historical/deferred producer reds explicitly retained;
- Bunny known-red with independent oracle before fatal product-success assertion;
- Vase bounded 60-second safety-only evidence.

Focused migration tests do not replace this authority. M1h remediation artifact `9069186973` is now immutable accepted: producer discovery **202**, required-green **187/187**, M1h **6/6**, all M1g–M1b focused preservation, validation **77/77**, M1a **14/14**, T1 **29/29**, four direct products independent-oracle clean without a fixture symlink, all eight historical/deferred red classes unchanged, Bunny known-red, Vase bounded safety-only, and exact **72/72** postflight. The prior `MultipleOrientationChartsPreserveEstablishedNumbering` failure remains classified as a test-authority witness defect, not a product regression. Historical totals stay **34 / 14 / 20**.

M1i source-scope migration is immutable accepted: producer discovery **208**, M1i **6/6**, required-green **193/193**, M1h-M1b focused preservation, validation **77/77**, M1a **14/14**, T1 **29/29**, four direct products independent-oracle clean, all eight historical/deferred red classes unchanged, Bunny known-red, Vase bounded safety-only, and exact **72/72** postflight. The initial wrong-working-directory package checksum issue and a later zero-selected M1b executable-mapping mistake are orchestration defects only; neither changes semantic evidence.

M1j edge source-scope migration is immutable accepted: producer discovery **214**, M1j **6/6**, required-green **199/199**, M1i-M1b preservation, validation **77/77**, M1a **14/14**, T1 **29/29**, four direct products independent-oracle clean, all eight historical/deferred red classes unchanged, strict timing **0/10**, Bunny known-red, Vase bounded safety-only, and exact **67/67** postflight. The initial compile mismatch and superseded incomplete-manifest artifact remain Code + Build/orchestration defects only. M1k preserves `RP-02 / TA-05`: producer **220**, M1k **6/6**, required-green **205/205**, validation **77/77**, M1a **14/14**, T1 **29/29**, four direct products oracle-clean, known-red classes unchanged, and exact postflight. M1l now preserves and extends that authority: producer **226**, M1l **6/6**, required-green **211/211**, all M1k-M1b focused authority, validation **77/77**, M1a **14/14**, T1 **29/29**, four direct products oracle-clean, all eight known-red classes unchanged, Bunny/Vase preserved, and exact **56/56** postflight. `RP-01 / RP-05 / RP-09` and `RP-02 / TA-05` are accepted at M1l. The final M1 cutover must preserve this evidence while adding behavior-oriented contracts for the complete semantic producer-to-materializer path; discovery totals are measured from the resulting package rather than predeclared. No new stable regression event or recurrence is assigned. Historical totals remain **34 / 14 / 20**.

### RP-03 — policy/stage state conflation

```text
bad: attempted/succeeded/disposition/debug retention are combined into mutable policy state.
good: closed producer outcome + single-writer stage product + derived diagnostics.
```

Untouched by M1a–M1e. M2 owns migration.

### RP-04 — nonterminating cumulative work

```text
bad: nested retries each have local bounds but total work can grow without one monotone budget.
good: one shared work ledger + monotone progress measure + deterministic exhaustion failure.
```

Untouched by M1a–M1f. Vase remains bounded safety-only evidence. M1e/M1f/M1g added no search/retry loop.

### RP-05 — representation-dependent identity

```text
bad: row/hash/traversal/allocation position becomes semantic identity.
good: semantic strong ID/key is authoritative; numeric projection occurs only at a direct storage or export leaf.
```

- M1a semantic ID/key kernel: **accepted**.
- M1b semantic source identity versus row representation: **accepted**.
- M1c canonical `SourceEdgeTopologyKey` versus raw packed source-edge key: **accepted**.
- M1d route identity versus packed route key/index: **accepted**.
- M1e routes each step through canonical `SourceEdgeTopologyKey` + `InteriorTransitionId`; observed route orientation is preserved through `CanonicalRoute::oriented_steps()` rather than canonical storage order becoming behavioral order. Immutable runtime is accepted.
- M1f applies the same semantic identity/orientation boundary to ordered vertex-continuation routes and is immutable accepted.
- M1g applies the boundary to the ordered periodic face-cycle route and is **immutable accepted**.

### RP-06 — state-cardinality growth

```text
bad: copied mutable authority tables accumulate across stages/regions.
good: one immutable authority product/reference per semantic fact.
```

Untouched by M1a–M1e. M2/M4 own shared authority storage.

### RP-07 — cyclic topology linearization

```text
bad: quarter-turn/cyclic relation handled as unrestricted signed integer arithmetic.
good: exact modulo-4 semantic algebra + explicit inverse/composition; integer projection is confined to a direct output leaf.
```

M1c is accepted at individual edge transport: `QuarterTurn::from_integer`, algebraic reverse `.inverse()`, and a then-existing signed output projection. The final M1 cutover removes stored numeric transport state.

M1d preserved this unchanged.

**M1e is the accepted direct RP-07 migration:** `segment_on_source` now compiles typed zero-shift `GridAutomorphism` per step, `TransitionStep`/`CanonicalRoute` for the observed route, algebraic composition in observed order, and integer matching only at the then-existing output write. Immutable runtime acceptance is complete; the final cutover removes the stored numeric form.

M1f is immutable accepted with the same typed algebra at `resolve_vertex_continuation`. M1g implementation `ee1abbd91d8ab39b84b107bba73ebf7aa0acceb2` replaces the separate periodic whole-cycle `totalMatching` accumulator with typed `CanonicalRoute` / `GridAutomorphism` composition and is **immutable accepted**. Nonzero periodic Z4 support remains out of scope and rejected through existing `PeriodicHolonomyMismatch` behavior.

### RP-08 — producer-disposition conflation

Untouched. M2 owns migration.

### RP-09 — local consumption of global authority

M1i exposes the next bounded `RP-09` seam: typed cell source scope is currently downgraded and then overwritten on `SurfaceFrontEdge`. M1j owns only the correction that edge publication preserves typed component/sheet authority and region aggregation verifies rather than recreates it. Global conformity/certificate migration remains M3/M4; `G4-R007` stays active.

M1k is immutable accepted at the adjacent edge topology-region seam, and M1l is immutable accepted after removing the raw cell-region mirror so cell/edge ownership agrees as `TopologyRegionId`. The final M1 cutover replaces the remaining raw certificate, materializer, occurrence, route, chart, support, and periodic ownership in one vertical change. The materializer verifies the single producer-authored authority product instead of reconstructing another one. Global topology planning remains outside this cutover.

## M1d immutable pattern record

| Pattern | Result | Evidence |
|---|---|---|
| `RP-01` | **accepted at phase-front route consumer** | checked source vertices + interior transitions; M1d 6/6 |
| `RP-05` | **accepted at route representation boundary** | canonical topology key; mismatch/duplicate fail-closed contracts |
| `RP-07` | **preserved** | M1c 6/6 + three transition counterexamples |
| `RP-02 / TA-05` | **preserved** | producer 178, required-green 163/163, M1b/M1a/T1/direct authority |
| `RP-03/04/06/08/09` | untouched | bounded implementation and unchanged dispositions |

M1d authority:

- implementation `9446fc82d98d336d3bd59c190dd2bbbe94bd2e25`;
- build run/job `31342400614 / 93318225812`;
- result artifact `9046308272`, SHA-256 `6a9dd880e2e7548b8afc88da48e7ed49935e6ce672ba1af208eee8f84678152c`;
- log artifact `9046308461`, SHA-256 `4813676a45370644fce64854d430822b86a0e406e9446a7ea3159c8fb23d315c`;
- manifest **59/59**, SHA-256 `e9859b25bd6d3a721484abdae679fcf898a85e1903b176192696d4b6b9e7eef0`;
- accepted facts retained in this tracker and the durable handoff.

Bunny/Vase M1d comparison run `31343763822` preserved accepted known-red/safety dispositions and exact package postflight. Temporary runtime workflow/trigger files were removed.

Prior M1a/M1b/M1c detailed per-turn reports were cleaned after their accepted facts were folded into this tracker, the PR audit inventory, current live status, and immutable artifact history. Artifact IDs above remain historical authority; deleted stale report paths are not resume dependencies.

## M1e immutable accepted pattern record

| Pattern | Accepted result | Immutable proof |
|---|---|---|
| `RP-01` | **accepted** checked source vertices + compact interior transitions at each observed step | M1e 6/6 + complete producer preservation |
| `RP-05` | **accepted** canonical topology key and semantic route-keyed observations; `oriented_steps()` preserves behavior order | forward/reverse and signed-equivalence contracts passed |
| `RP-07` | **accepted** zero-shift `GridAutomorphism` route composition replaces raw cumulative signed addition | nonzero multi-step/inverse and pre-cutover path contracts passed |
| `RP-02 / TA-05` | **preserved** deterministic hard-authored expected values, independent compact IDs, semantic snapshot keys | producer 184, required-green 169/169, M1d/M1c/M1b/M1a/T1/direct evidence |
| `RP-03/04/06/08/09` | untouched | unchanged dispositions/accounting |

M1e immutable authority:

- implementation `a0330d0107f7d7340e9f8644d26dd6c8b753ff10`;
- build run/job `31351113129 / 93341993183`, **120/120**;
- result artifact `9049125645`, SHA-256 `d16222c62f6f7491eaa830fe22ac4f768b6f426646639f155ccfd8feb9d378f7`;
- log artifact `9049125905`, SHA-256 `fd1d816fd4265f803f6be278941eb7647d056eb6336d05fe98e865621fd5e7be`;
- manifest **61/61**, SHA-256 `36a6377350aa4b58205ccd881a7ee34156800d28e3c5edecf634769289d9e7e5`;
- Code + Build executed no generated Directional binary, discovery, test, or benchmark;
- immutable runtime: M1e **6/6**, required-green producer **169/169**, validation **77/77**, M1a **14/14**, T1 **29/29**, direct Plane/MultiFaceSeam/CloseSheets/Cylinder green;
- strict-validator timing characterization: **6/10 pass, 4/10 fail**, classified nondeterministic and deferred;
- accepted facts retained in this tracker and the durable handoff.

The review-authorized malformed contract targets the reachable predecessor `source_edge_provenance` authority boundary. It does not claim an unreachable typed-constructor failure and does not reinterpret `CrossFieldEdgeTransition::sourceEdge` as semantic transition identity.

## M1f immutable accepted pattern record

| Pattern | Accepted result | Immutable proof |
|---|---|---|
| `RP-01` | checked source vertices + compact interior transitions per continuation step | M1f **6/6** + complete producer preservation |
| `RP-05` | canonical source-edge topology and observed/canonical route-order boundary | forward/reverse and signed-equivalence contracts passed |
| `RP-07` | typed `GridAutomorphism` composition replaces `PathState::matching += transition.matching` | nonzero multi-step/inverse/equivalence/pre-cutover contracts passed |
| `RP-02 / TA-05` | direct production-consumer fixtures plus preserved independent product/oracle authority | producer **190**, required-green **175/175**, validation **77/77**, M1a **14/14**, T1 **29/29**, four direct products green |

M1f immutable authority:

- implementation `baed0f24831c476f45a1b742c12314e3fb03e10e`;
- build run/job `31356131866 / 93356062724`, **120/120**;
- result artifact `9050850344`, ZIP SHA-256 `a2ac9f21cae7f3496a9ffd7cade8b550b5c8e1de57c91d693dde5ece4fcd499f`;
- log artifact `9050850513`, ZIP SHA-256 `3f5595a14d7c2b8c8931772fbdb770c9bc1944b211710ccc4939f2fc1dd54c99`;
- manifest **59/59**, `3607c79873f45d035e6b1339288ed26582007a9068768da167abc603c376059e`;
- M1f **6/6**, required-green **175/175**, M1e/M1d/M1c/M1b preservation, validation **77/77**, M1a **14/14**, T1 **29/29**;
- Plane/MultiFaceSeam/CloseSheets/Cylinder independent-oracle clean;
- Bunny known-red preserved and Vase bounded safety-only under remote run `31357556834`;
- strict-validator characterization **9/10 pass, 1/10 fail**, retaining the existing nondeterministic performance-test defect;
- accepted facts retained in this tracker and the durable handoff.

No new stable regression event or recurrence is assigned. Historical totals remain **34 / 14 / 20**.

### M1h blocked runtime / test-authority record

- implementation: `de4e2ba7c19d2e49931655dc22d758f50656d054`; artifact `9066967620`; manifest **69/69**; producer discovery **202**;
- focused: **5/6**; sole failure `MultipleOrientationChartsPreserveEstablishedNumbering`;
- required-green: **186/187**, same sole failure;
- M1g/M1f/M1e/M1d/M1c/M1b focused preservation green; validation **77/77**; M1a **14/14**; T1 **29/29**;
- direct products green from arbitrary extraction with no fixture symlink; historical/deferred red classes unchanged;
- diagnosis: fixture samples lattice-corner chart IDs `{0,2}` while producer/segment authority still proves chart domain `{0,1,2}`; test incorrectly equates producer-domain and occurrence coverage;
- disposition: **test-authority defect, not stable product regression**; historical totals remain **34 / 14 / 20**; `PR8-R034 / G4-R007` remains active;
- historical next at this checkpoint was M1i; that consumed plan/report set has since been retired under `CLEAN_UP_POLICY.md`. Current next action is owned by the handoff and `TODO.md`.

### M1g immutable accepted pattern record

M1g implementation `ee1abbd91d8ab39b84b107bba73ebf7aa0acceb2` migrates the periodic canonical-face-cycle whole-route accumulator to checked source vertices, canonical topology keys, checked compact transitions, `TransitionStep`, `CanonicalRoute`, and typed transport composition. It preserves current `PeriodicHolonomyMismatch` rejection for nonzero cycle rotation. `G4-B003` remains unresolved.

Immutable authority:

- build run/job `31362470744 / 93373936472`, **120/120**;
- result artifact `9053047653`, ZIP SHA-256 `296f3ed13f2f09143a14f63555171d013939c2525052a56b807ea7f00cf1bd0c`;
- log artifact `9053048092`, ZIP SHA-256 `c5c3d964d9210982bfb08d0cf46900308a2498cee9ea2e54879dd35e61cacbd9`;
- manifest **64/64**, SHA-256 `89beb0a12c1051a0fd4d55af6a8ee27e897c0f610045efa8b270a42dc09d51ae`;
- M1g **6/6**, required-green producer **181/181**, complete M1f/M1e/M1d/M1c/M1b preservation, validation **77/77**, M1a **14/14**, T1 **29/29**;
- Plane/MultiFaceSeam/CloseSheets/Cylinder independent-oracle clean;
- all eight historical/deferred red classes unchanged;
- Bunny known-red and Vase bounded safety-only under run `31394985769`;
- strict-validator characterization **1/10 pass, 9/10 fail**, retaining the existing nondeterministic performance-test defect;
- exact local and remote postflight passed;
- stale per-turn M1h evidence was subsequently consolidated into `.agents/Directional/CHANGELOG.md` and the tracker; the old report was retired under `CLEAN_UP_POLICY.md`.

No new stable regression event or recurrence is assigned. Historical totals remain **34 / 14 / 20**.

### Historical M1h RP-01 / RP-05 boundary

Accepted-source inspection selected `build_planar_phase_frame -> UniformPhaseFrame::faceChart -> LocalLatticeState::sourceChart` as the real field-chart owner. The producer created connected equal-orientation charts and carried their identity as bare integers. M1h adopted checked `FieldChartId` there while preserving chart partitioning/numbering and all behavior. The M1g runtime-discovered executable-relative fixture lookup defect was corrected in the same bounded migration. `SurfaceTraceSegment::sourceChart`, M2–M6, G4 repair, and nonzero periodic Z4 support remained out of scope.

## Historical M1h compile/package pattern record

M1h implementation `de4e2ba7c19d2e49931655dc22d758f50656d054` migrated the real field-chart owner `build_planar_phase_frame -> UniformPhaseFrame::faceChart -> LocalLatticeState::sourceChart` from bare semantic integers to checked `FieldChartId`, while numeric projection remained at then-existing leaf accesses. The deterministic chart partition/BFS numbering was unchanged. Missing typed lattice chart authority was fail-closed before aggregate front acceptance. Periodic and bounded-disk single-chart lattice states used checked chart zero. The final M1 cutover removes the stored numeric form.

Compile/package authority:

- run/job `31398571348 / 93487537918`, **120/120**;
- result artifact `9066967620`, ZIP SHA-256 `16d04835f9186b94fbb1ab987c5cd0bebd801daa7f368d01dc58139f67f5fe03`;
- log artifact `9066968049`, ZIP SHA-256 `d6fa10a4b188b5569dfc73008c1a6e8a6f3a4e51f64cf4232a568087b36ac816`;
- manifest **69/69**, SHA-256 `63c7000e00cf8608861d1651d84c02ddf419581dd7763ba25a9b3837162b92c9`;
- six focused M1h contracts compiled and unexecuted;
- all Code + Build runtime flags false;
- packaged sibling `../test-data` resolution correction compiled;
- subsequent test-authority remediation and immutable acceptance are retained in `.agents/Directional/CHANGELOG.md`; the superseded per-turn report was retired under `CLEAN_UP_POLICY.md`.

No new stable regression event or recurrence is assigned. `RP-01 / RP-05` and `RP-02 / TA-05` were subsequently accepted at M1h. `RP-07` remained preservation-only and unchanged.

## Single-authority strategy correction — 2026-08-11

- Review baseline: `fcba2fd9b8905802ca373e0cc88aeccbf38d608a`.
- Reviewed accepted source: M1l `bd140cff4572412e6f4ecd70a6ce0fe85310932c` from artifact `9083262395`.
- The unimplemented one-field follow-up was rejected after source inspection showed that the remaining duplication spans certificate, topology-region, chart, support, route, periodic, rail, occurrence, quotient, and materializer contracts.
- M1 now ends with one Code + Build turn that installs the semantic model across the complete producer-to-materializer path and deletes every displaced numeric semantic field, reconstruction path, helper bridge, and associated test.
- The cutover must preserve G0–G3 invariants, truthful failure and disposition behavior, determinism, and the accepted M1l product evidence. Representation changes are evaluated by semantic invariants and behavior-oriented contracts, not by exact preservation of obsolete numbering, hashes, or iteration order.
- No generated Directional binary runs in the cutover turn. A following immutable Test + Benchmark turn discovers the resulting inventory, runs all entering gates plus the new semantic contracts, and determines acceptance.
- After immutable acceptance, M1 closes and the primary queue returns to G4 production work. Remaining architecture work is introduced only as a complete vertical contract needed by an active production blocker, not as another representation-only campaign.
- This strategy correction changes no historical regression count: totals remain **34 / 14 / 20**.

### R-A compile checkpoints and closure-gate review

- Reviewed source: `bebac907de814b07a55a770add4c897ab6d22ffd`.
- Compile run/job `31550744314 / 93972723960`, result/log artifacts `9124167871 / 9124168143`, Release/static/Ninja/PRE_TEST **118/118**.
- No generated runtime, discovery, test, benchmark, `ctest`, CLI, fuzzer, or custom input executed.
- R-A established typed region/member authority, private checked factories, exact row coverage, builder-only raw classifier ingress, `SourceEntityId` removal, and owning-product consumer APIs.
- `R-A-REV-01`: materializer occurrences omit required typed sheet/member authority and read `SurfacePoint::sheet` for cross-sheet equivalence and representative ordering. This repeats the `RP-01` and `RP-05` source shape.
- `R-A-REV-02`: completion fallback stitch identity encodes raw provenance component/sheet beside typed lineage authority. This repeats the `RP-01` and `RP-05` source shape.
- These are review findings, not new stable runtime regression events: runtime was not executed and no previously accepted behavior was shown lost. Totals remain **34 / 14 / 20**.
- Later commits `eca1ce1141e4cc8b492e4efbfd2227b0a001a76b` and `df386d1ad819879abbf9d7660c3d586778d7daee` correct the exact R-A-REV-01 materializer paths and remove the exact R-A-REV-02 raw fallback encoding. Source `df386d1...` compiled 118/118 in run/job `31555887046 / 93988102158` with no generated runtime.
- Closure review of implementation `5e023f1...` added `R-A-REV-03`: standalone/patch-local valid stitch identities bypass the typed fallback and can omit typed isolation-sheet authority. This is the same `RP-01 / RP-05` duplicate/compatibility-authority pattern.
- `R-A-REV-04`: validator, optimizer, and rail-constraint decisions still consume raw projection component/sheet labels. This is the same `RP-01 / RP-05` read-back pattern.
- `R-A-REV-05`: required typed positive, distinct-sheet, missing-authority, and raw-projection-tamper contracts are absent, while existing tests still treat raw labels as authority. This is a `RP-02` test-authority coverage gap.
- `R-A-REV-06`: partial artifact `9125984929` has matching outer digest but an internal manifest self-check failure and unclean recorded source status. This is an evidence-package defect, not a product regression.
- R-A remains compile-valid partial implementation. M1l remains immutable runtime authority; artifacts `9105462679`, `9124167871`, and `9125984929` are not M1 acceptance candidates. No runtime evidence changed totals **34 / 14 / 20**.

### Architecture redesign mapping

- Pipeline B is the normative default; Pipeline A is optional and unscheduled.
- New M3 owns the field-aligned curve network.
- Prior M3 becomes M4 global conformity; `G4-B002` is therefore M4-owned.
- Prior M4 becomes M5 certificate-carrying relations.
- Prior M5 becomes M6 occurrence/embedding/verification.
- New M7 owns graded disposition and the declared degraded producer.
- Prior M6 becomes M8 operational hardening.
- Strict product gates require D0 Certified; D1-D3 are explicit product dispositions and never green substitutes.

## Current G4 stable-ID mapping

| PR event | G4 ID | Category | Pattern | Status |
|---|---|---|---|---|
| `PR8-R028` | `G4-R001` | `AUTHORITY_DOMAIN_CONFLATION` | `RP-01` | resolved |
| `PR8-R029` | `G4-R002` | `LOCAL_CONSUMPTION_OF_GLOBAL_AUTHORITY` | `RP-09` | resolved |
| `PR8-R030` | `G4-R003` | `TEST_AUTHORITY_COVERAGE_GAP` | `RP-02` | resolved |
| `PR8-R031` | `G4-R004` | `AUTHORITY_DOMAIN_CONFLATION` | `RP-01` | resolved |
| `PR8-R032` | `G4-R005` | `POLICY_STAGE_STATE_CONFLATION` | `RP-03` | resolved |
| `PR8-R033` | `G4-R006` | `AUTHORITY_DOMAIN_CONFLATION` | `RP-01` | test-authority resolved |
| `PR8-R034` | `G4-R007` | `LOCAL_CONSUMPTION_OF_GLOBAL_AUTHORITY` | `RP-09` | **active** |

`G4-R007` authority remains production artifact `9031804178`: direct torus 0/3 with 241 `LocalSheetMismatch` issues after 192 quads, complete lineage, `4/8/4`, `1/0/0`. M1 migration does not repair or reinterpret it.

## Persistent blockers

| ID | Blocker | Required gate |
|---|---|---|
| `G4-B001` | Direct torus final `LocalSheetMismatch`. | strict-valid torus 3/3 |
| `G4-B002` | Exact Phase10 torus `InvalidHardRailPairing`. | shared positive rail schedule; revised M4 |
| `G4-B003` | Nonzero periodic Z4 production capability. | M5 relation certificate + representative product acceptance |
| `G4-B004` | Positive multi-isolation quotient witness. | M5/M6 focused + representative certificate evidence |

## Architecture enforcement register

| ID | State |
|---|---|
| `AR-01` | final M1 cutover installs exhaustive `ProducerOutcome<SurfacePhaseFrontProduct>` |
| `AR-02` | M1a through M1l **accepted**; R-A closure gate rejected with `R-A-REV-03` through `R-A-REV-06` open |
| `AR-03` | final cutover closes strong identity from producer through materializer, including exact/existing stitch-identity validation and no compatibility bypass |
| `AR-04` | final cutover replaces remaining chart, support, route, periodic, rail, occurrence, quotient, and certificate numeric ownership |
| `AR-05` | after cutover, numeric projection is permitted only at a direct Eigen/vector storage or derived export leaf; it is never semantic authority |
| `AR-06` | final cutover installs the complete typed isolation-seam transport certificate; later relation-registry work must be driven by a production blocker |
| `AR-07` | revised M4 publishes one deterministic positive global conformity/flow plan before regional commits |
| `AR-08` | final cutover publishes one immutable producer-scoped phase-front product |
| `AR-09` | final cutover replaces `SurfacePointSourceSupport` with the typed resolved support contract end to end |
| `AR-10` | revised M3/M4/M5/M6/M7 contracts land vertically; module extraction/hardening closes in M8 |
| `AR-11` | normative architecture/status separation maintained |
| `AR-12` | T1 independent oracle/package accepted; T2–T6 expand authority |

## Test architecture register

| ID | State |
|---|---|
| `TA-01` | topology/lineage partial authority accepted; revised D0-D4 disposition and geometry/field/quality remain later gates |
| `TA-02` | T2 ten-case direct matrix pending |
| `TA-03` | metric definitions/baselines pending |
| `TA-04` | T3/T4 generation/shrinking/fuzz pending |
| `TA-05` | **test authority resolved and preserved through M1l** |
| `TA-06` | T1 mutation suite **29/29** accepted and preserved |
| `TA-07` | exact package/discovery authority accepted and preserved |
| `TA-08` | M1a route algebra + M1c edge transport + M1d route identity + M1e segment-route + M1f continuation-route + M1g periodic-route + M1h field-chart + M1i/M1j source-scope + M1k edge topology-region + M1l cell topology-region authority accepted; R-A typed positive/missing-authority/raw-tamper contracts remain open |
| `TA-09` | coherent resource/work gate pending |
| `TA-10` | T2 semantic fixture manifest pending |
| `TA-11` | existing topology/lineage oracle foundation accepted; M3 network, M7 disposition, and T5 quality mutation evidence remain open |
| `TA-12` | `tests/TESTING_STRATEGY.md` normative only |

## Authoritative next step

`.agents/Directional/Architecture_M1_Single_Authority_Cutover_Code_Build_Plan.md`.

The next turn is **Code + Build only**. Retain the exact R-A-REV-01/02 edits; close `R-A-REV-03` through `R-A-REV-05`; rerun the full R-A closure inventory; finish R-B through R-G; and close `R-A-REV-06` while packaging the exact self-verifying full cutover. Execute no generated Directional binary. The retained artifact-only plan stays dormant until that fresh package exists. On M1 acceptance, resume the Pipeline B queue under revised M2-M8 ownership; Pipeline A remains unscheduled.
