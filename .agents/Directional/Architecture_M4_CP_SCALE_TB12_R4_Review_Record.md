# M4-CP-SCALE-TB12-R4-REV — Independent Review Record

**Turn:** `M4-CP-SCALE-TB12-R4-REV`
**Type:** independent Review + Plan, runtime-free
**Reviewed predecessor:** `M4-CP-SCALE-TB12-R4-EXEC`
**Accepted runtime authority entering Review:** package `10473134357` / semantic source `e15e83c79a1e1962c0ed8d31ea85187ab6600e47` / selector426 **426/426**
**Candidate under review:** artifact `10527625935` / compile source `1b44d2b7b3173590db9837a1386eadbc9ac32981`
**Verdict:** Gate-A repair accepted as test authority; RP-07 recovery proved; S5 RED root-caused to a separating-hard-feature singularity ownership domain mismatch; no promotion or S5 credit.

## 1. Immutable evidence independently re-opened

The Review re-opened the CB17 candidate package and TB12-R4 runtime artifacts rather than treating EXEC prose as evidence.

- Candidate package SHA-256: `88e61b93328ff4617f6810077b9469602466c06e4059b23b7c0402aefbd80e93`.
- Root `SHA256SUMS`: **28/28** entries verified; manifest SHA-256 `d3a1ae00bc214397e23ca7a62b760566207990d108783d7355ca5cdc84224dd4`.
- Exact packaged semantic source: `1b44d2b7b3173590db9837a1386eadbc9ac32981`; packaged source archive SHA-256 `636855d94efdb8cac3898b2f0a2dd020c2ff85c90cd61ee9006d3d0a671b267e`; GMP/GMPXX compile authority retained; six executables are mode `0755`, two static libraries `0644`.
- Frozen selector426 SHA-256: `41f4d559211375c11c8d1f8c9ccde2581db75819d9409366e8f2695b008b5114`; exact first425 prefix SHA-256: `e0e0f394faae536ac257ec5409653a34755a8afe0ca437562eb44c9895790e0b`; owner census **30 / 280 / 75 / 41**; no selector427.
- Retained S5 bytes: `genus_two.obj` `c6bacd981fb0559dc3e290ee1367b9e369f4657b189ce288ce732461d8caeab3`, `.rawfield` `7bd71837954ded74461a46d65761b953cbc186978639d41567ad4a4aac4af70e`, metadata `22600270cc11b7b421007e10a3861124c4238bc0e5353b2637a9c70005bf1b76`.
- Authoritative runtime run/job: `35296853812 / 105451109821`; result/log artifacts `10528172684 / 10527643135`.
- Result ZIP SHA-256: `969857f8ee3a94aac15b62ed6b9fb01723908c2b7df1ec3a865e94237394d06e`; log ZIP SHA-256: `f82a094a27e3ddef02deff71f22b3c51eef9c722b1c1220608b5696e1ea54a72`; result self-manifest **20/20**.
- Execution ledger SHA-256: `939610cfbd015e0cc7f10dbf960b7ab978e5dc7e35a399c9ad3065caed6bf74a`; **431** initialized rows = 4 PASS + 1 RED + 426 explicit UNEXECUTED.
- Postflight package/source/execution-view byte+mode censuses match preflight. No build, repair, source/test/fixture/selector mutation, discovery/list/help/version runtime, or benchmark occurred inside the artifact-only execution.

This establishes an immutable Review basis and leaves accepted TB11 package `10473134357` untouched.

## 2. Gate A — corrected CB17 authority is non-vacuous and accepted

The four frozen Gate-A processes each selected exactly one test, executed exactly once, skipped zero and exited `0`:

1. `FieldTransportAtlas.IndependentCycleOrderingOracleHandlesMultipleClosedComponents` — stdout SHA-256 `64f28a1004c28570b3a1de89c5659d0b5f4a0cfa062d442c7871ee7f5ae51a33`.
2. `FieldTransportAtlas.PreservesSingleComponentCanonicalCycleSequence` — `7c05d2ff10dd84e9bd8b9a6f971d04ccef39cdc710f9c84e4701ebca133d3350`.
3. `FieldTransportAtlas.IndependentOracleRejectsCycleOrderingTamper` — `0e113347bcd71b23891fd60cd0b02c4b5ab6ad298ccfc00eba20c90e3a824c17`.
4. `FieldTransportAtlas.OrdersEveryClosedComponentOfOneAlgebraicBoundaryRow` — `3a89e9c9d27e8d50bd934383fc62dc6f4dc4630516dc9f9b07478a4fdb0527b0`.

The fourth control is the decisive correction. Its test-local subject independently derives an algebraic boundary row with six support steps and two closed successor components before atlas construction; it then checks exact support consumption and independent canonical component order. Its full-component rotation/swap falsifier preserves the same support multiset and each component's internal order but changes component order, and the independent validator rejects it as `IncompleteCycleBasis`. The single-component preservation control prevents the repair from redefining established one-component order.

**Disposition:** `M4-CP-SCALE-TB12-R3-EXEC-CAND-01 / RP-02` is **CLOSED / TEST-AUTHORITY REPAIR PROVED / NON-STABLE**. CB17 repaired the invalid R3 integration gate; it does not by itself prove product or S5 recovery.

## 3. RP-07 — the post-CB16 product boundary advanced strictly past cycle ordering

The unchanged S5 focus in TB12-R4 reaches `SingularityMismatch;sourceVertex=0`. Static source order matters:

- `FieldTransportAtlas.cpp:2189-2194` calls `order_cycle_steps(...)` and immediately returns `IncompleteCycleBasis / CycleOrderingFailed` on an ordering failure.
- Only after ordered-cycle construction, transport composition, cycle partitioning and singularity-cycle reconciliation does the final raw interior-singularity owner XOR execute at `FieldTransportAtlas.cpp:2472-2480`.

The same retained genus-two fixture and S5 call path therefore did not merely rename or bypass the former error at the same seam: the atlas call traversed the corrected ordering gate and reached a later invariant. Together with Gate A's direct multi-component controls, this is the required post-CB16 recovery evidence.

**Disposition:** `M4-CP-SCALE-TB12-R1-EXEC-CAND-01 / RP-07 CYCLIC_TOPOLOGY_LINEARIZATION` is **CLOSED / RECOVERY PROVED / NON-STABLE**. No stable event is priced because the S5 focus was never accepted-green selector authority.

## 4. The retained genus-two field is not falsified by the R4 RED

Review independently re-derived the retained fixture rather than taking the production validator as its oracle.

### 4.1 Geometry / hard-feature census

From the exact OBJ bytes:

- `V=120`, `E=366`, `F=244`, no boundary edges, one connected closed orientable component, `chi=-2`, genus `2`.
- All 366 interior dihedral angles are either `0°` or `90°`: **294** coplanar edges and **72** right-angle crease edges.
- Removing face adjacency across those 72 crease edges yields **14** source topology regions. Every one of the 72 crease edges separates two different source topology regions; none is an intra-region hard-feature slit.
- Source vertex `0` is incident to exactly three topology regions and exactly three hard-feature edges: `(0,1)`, `(0,3)`, `(0,4)`. Their incident faces occupy region pairs `0/1`, `0/2`, and `1/2` respectively.

This is the geometric shape of the observed failure: vertex 0 is globally interior but lies on a hard-feature-created source-region boundary.

### 4.2 Independent singularity census

Using the exact retained raw field and mesh connectivity, Review independently reconstructed the degree-four field singularity indices. There are **24 nonzero singular vertices**; their total index numerator is **-8**, exactly `4*chi` for `chi=-2`. Source vertex `0` is a genuine **+1** singularity. The fixture metadata deliberately labels singularity count/index as runtime-derived and therefore does not conflict with this reconstruction.

The R4 evidence therefore does **not** support changing `genus_two.rawfield` merely to make atlas construction pass.

## 5. Root cause — separating hard-feature boundary versus intra-region slit authority

The defect is a domain mismatch between two already-authoritative uses of the same hard-feature set.

1. `SurfaceCellTracing.cpp:8186-8208` constructs source topology adjacency and omits every `options.hardFeatureEdges` edge. Hard features therefore split source topology regions.
2. `FieldTransportAtlas.cpp:1864-1880` publishes every hard feature as a global nontraversable `HardFeature`, regardless of whether it separates source topology regions.
3. `FieldTransportAtlas::make_local_region_mesh`, `:955-969`, adds a hard edge to local `barrierEdges` / `barrierVertices` **only when both incident faces belong to the same topology region**. A hard feature that created the region boundary is thus excluded from every region's local barrier set.
4. Interior singularities get a local-vertex owner only from local cycles (`:2252-2263`). The existing absorbed/slit owner is registered only for a globally interior vertex that is also in `local->barrierVertices` (`:2345-2356`).
5. The final raw singularity reconciliation (`:2472-2480`) requires exactly one of those two owners. A singularity such as vertex 0 on a separating hard-feature boundary has neither and deterministically fails `SingularityMismatch`.
6. Existing downstream semantics already support an explicit incident topology region: `singularity_region_from_source(...)` in `SurfaceCellTracing.cpp:4114-4151` accepts a singularity's explicit region when it is one of the source regions incident to that vertex. `build_singularity_attachments(...)` in `FieldTransportAtlas.cpp:499-520` already suppresses origin ports for `BarrierAbsorbed` singularities.

Existing tests cover both halves separately but not their intersection. `ClassifiesHardFeaturesAsNontraversableCuts` proves separating hard features split transport components. `NonSeparatingBarrierEdgeIsAbsentFromLocalCycleBasis` and `PrescribedSingularityOnABarrierArcRemainsBoundToACycle` exercise a **non-separating intra-region** hard barrier; the latter correctly publishes `BarrierAbsorbed`, one `BoundaryLoop` owner and no singularity port. None binds a singularity lying on a hard feature that itself separates source topology regions.

This is an instance of existing **`RP-01 / AUTHORITY_DOMAIN_CONFLATION`**: “hard-feature boundary” at source-topology partition scope and “local barrier/slit” at per-region atlas scope were treated as if they were the same ownership domain. It is also the concrete form of `LESSONS.md` 150 and 153, with lesson 65's warning that two apparently equivalent obligation paths must be compared by their failure behavior.

**Disposition:** `M4-CP-SCALE-TB12-R4-EXEC-CAND-01` is **OPEN / PRODUCT / SEPARATING-HARD-FEATURE SINGULARITY OWNERSHIP DOMAIN MISMATCH / `RP-01 AUTHORITY_DOMAIN_CONFLATION` / NON-STABLE**. It is not invalid retained-field authority and is not a continuation of the now recovery-proved RP-07 ordering defect.

## 6. Acceptance/accounting consequences

TB12-R4's S5 focus remains RED before atlas publication/A3. Fail-fast therefore remains authoritative:

- selector426: **0/426**, all rows UNEXECUTED;
- benchmark: **0**;
- candidate package `10527625935`: unpromoted;
- S5 / A3 cumulative credit: **zero**;
- selector427: absent.

No accepted-green identity was lost. Stable accounting remains **49 events / 14 categories / 35 recurrences**, produced-witness debt **5**. The new R4 defect is a non-stable instance of existing RP-01 and does not change those totals.

`M4-CP-SCALE-DEFN-OBS-04` remains **OPEN / NARROWED**: the genus-two topology is independently proved and the retained raw field is not falsified by its singularity/index census, but production atlas admissibility and A3 reachability are still unproved.

## 7. Corrective owner frozen — `M4-CP-SCALE-CB18`

The evidence distinguishes field authority from product semantics strongly enough that the Review stop condition does not fire. The smallest safe owner is **`M4-CP-SCALE-CB18`**, a Code+Build-only correction of the atlas ownership seam plus a direct independent regression control. The detailed contract is frozen in `Architecture_M4_CP_SCALE_CB18_Separating_Hard_Feature_Singularity_Ownership_Code_Build_Plan.md`.

The correction must not change source-topology partitioning, cycle ordering, retained genus-two bytes, the S5 focus, selector426, CMake/benchmark semantics, or accepted predecessor behavior. It must establish an explicit deterministic owner for a prescribed singularity on a **separating** hard-feature boundary, publish it as `BarrierAbsorbed`, and emit no singularity origin ports. Multiple incident regions must be resolved canonically by stable authority IDs, never storage/iteration order.

CB18 is compile/package only under GMP/GMPXX with `runtimeExecution=false`. Fresh artifact-only runtime remains a later Test+Benchmark responsibility; this Review authorizes no generated Directional runtime.

## 8. Consolidation

Mandatory Review consolidation indexes every superseded CP-SCALE per-turn document retired since the last retained Review and leaves one current document per role. Five files were already removed by TB12-R4 stale cleanup; their exact line counts were recovered from pre-cleanup git authority. Three additional current-head documents are folded by this Review after their durable facts are preserved here and in `M4_Consolidated_Record.md` §2.63.

| Folded filename | Lines | Disposition / retained home |
|---|---:|---|
| `Architecture_M4_CP_SCALE_CB17_Code_Build_Report.md` | 75 | **SUPERSEDED/FOLDED.** CB17 semantic/compile/package facts live in R4 immutable evidence, this Review and §2.63. |
| `Architecture_M4_CP_SCALE_CB17_Test_Authority_Repair_Code_Build_Plan.md` | 125 | **CONSUMED/FOLDED.** Corrected Gate-A invariants/falsifiers and test-only scope are retained in §2, this Review and §2.63. |
| `Architecture_M4_CP_SCALE_TB12_R3_Artifact_Only_Test_Benchmark_Report.md` | 47 | **SUPERSEDED/FOLDED.** R3 3/4 runtime and fail-fast evidence are retained in §2.62/§2.63, tracker and git history. |
| `Architecture_M4_CP_SCALE_TB12_R3_Review_Record.md` | 152 | **SUPERSEDED/FOLDED.** RP-02 authority divergence and CB17 ownership are retained in §2, §2.62/§2.63 and tracker history. |
| `Architecture_M4_CP_SCALE_TB12_R4_Artifact_Only_Test_Benchmark_Plan.md` | 99 | **CONSUMED/FOLDED.** Frozen Gate order, fail-fast and immutable-postflight contract are realized by §2.63 and this Review. |
| `Architecture_M4_CP_SCALE_TB11_Review_Record.md` | 217 | **SUPERSEDED/FOLDED BY R4 REVIEW.** TB11 selector426 promotion and S4 cumulative acceptance remain in the retained TB11 runtime report, §2.60/§2.63, selector manifest, tracker/changelog and git history. |
| `Architecture_M4_CP_SCALE_TB12_R4_Artifact_Only_Test_Benchmark_Report.md` | 67 | **ADJUDICATED/FOLDED BY R4 REVIEW.** R4 immutable runtime identities, Gate-A/Gate-B receipts, fail-fast and postflight facts are independently retained in §§1–6 and §2.63; the report is not current accepted runtime authority. |
| `Architecture_M4_CP_SCALE_TB12_R4_Review_Plan.md` | 24 | **CONSUMED/FOLDED BY THIS REVIEW.** Adjudication duties and stop conditions are discharged here; exactly one next plan is the CB18 plan. |

Retained current CP-SCALE role set: normative `Architecture_M4_CP_SCALE_Frozen_Definitions.md`; accepted current runtime-authority report `Architecture_M4_CP_SCALE_TB11_Artifact_Only_Test_Benchmark_Report.md`; this R4 Review record; exactly one next plan `Architecture_M4_CP_SCALE_CB18_Separating_Hard_Feature_Singularity_Ownership_Code_Build_Plan.md`; selector426 plus all historical byte-frozen selectors; `M4_Consolidated_Record.md`; tracker/changelog and other durable project authority.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | selector426 = `41f4d559211375c11c8d1f8c9ccde2581db75819d9409366e8f2695b008b5114`; exact first425 = `e0e0f394faae536ac257ec5409653a34755a8afe0ca437562eb44c9895790e0b` |
| Decisive claims independently re-derived | CB17 immutable 28/28 package/GMP/source authority; Gate A 4/4 raw receipts; R4 431-row ledger and fail-fast; exact genus-two topology/crease-region census; independent raw-field singularity census; source ownership call path from topology partition through final singularity XOR |
| Non-vacuity checked | corrected same-row Gate-A control proves 6 support steps / 2 closed components and rejects a whole-component order tamper; R4 S5 reaches the owner XOR strictly after `order_cycle_steps`, so RP-07 recovery is not inferred from a renamed error |
| Prior obligations discharged/carried | R3 `RP-02` CLOSED as test-authority repair proved; R1 `RP-07` CLOSED as recovery proved; R4 candidate OPEN as non-stable product `RP-01`; `DEFN-OBS-04` carried/narrowed; S1/S2 and inherited debts keep existing owners |
| Stable accounting | unchanged **49 events / 14 categories / 35 recurrences**, debt **5**; accepted runtime authority remains package `10473134357` / selector426 **426/426**; CB17 candidate unpromoted |
| New candidates/obligations recorded | `M4-CP-SCALE-TB12-R4-EXEC-CAND-01` root-caused as separating-hard-feature singularity ownership domain mismatch, existing `RP-01`, non-stable; corrective owner `M4-CP-SCALE-CB18` |
| ORIENTATION currency line | `M4-CP-SCALE-TB12-R4-REV`, 2026-09-18 UTC |
| ORIENTATION §3 / §4 / §7 / §8 | §3/§4 record RP-02 closure, RP-07 recovery and current RP-01 seam; §7 freezes CB18 and carried obligations; §8 adds the separating-hard-feature/local-barrier domain mismatch as an existing RP-01 lesson instance |
| CHANGELOG | R4 Review adjudication/root cause/accounting/successor entry added |
| ROADMAP | CP-SCALE current state updated: S5 still unaccepted; R4 root cause owned by CB18; accepted package/selector unchanged |
| Selector manifest | unchanged — selector426 remains accepted current M4 gate; no selector427 |
| LESSONS | no new entry — existing lessons 65, 150 and 153 plus `RP-01` already state the reusable failure pattern |
| Consolidation under CLEAN_UP_POLICY | five files retired by R4 EXEC plus superseded TB11 Review, adjudicated R4 runtime report and consumed R4 Review plan folded/indexed in `M4_Consolidated_Record.md` §2.63; one accepted runtime report, one current Review and one next plan retained |
| Successor frozen | exactly `M4-CP-SCALE-CB18`; bounded semantic/test files, invariants and STOP falsifiers in the CB18 plan |
| Turn boundary held | yes — runtime-free Review; no Directional runtime, compile, package repair, product/test/fixture/selector/benchmark/build-source mutation |
| review_check.py boundary | PASS on the Review diff with selector426 declared hash and all frozen selectors unchanged |
| `STATUS` lifecycle maintained | start beacon `2026-09-18T02:37:27Z`; latest resume beacon `2026-09-18T03:55:11Z`; final COMPLETE beacon is reserved as the last repository mutation after patch/cleanup verification |
| Pushed to origin, branch in sync | durable Review publication is followed by temporary-state cleanup and explicit branch-head synchronization verification before the final COMPLETE beacon; no alternate ref or force push is authorized |
