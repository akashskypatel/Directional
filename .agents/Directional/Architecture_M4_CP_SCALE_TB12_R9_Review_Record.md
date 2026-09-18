# M4-CP-SCALE-TB12-R9-REV — Independent Review Record

**Turn:** `M4-CP-SCALE-TB12-R9-REV`
**Type:** independent Review + Plan, runtime-free
**Reviewed predecessor:** `M4-CP-SCALE-TB12-R9-EXEC`
**Accepted runtime authority entering Review:** package `10473134357` / semantic source `e15e83c79a1e1962c0ed8d31ea85187ab6600e47` / selector426 **426/426**
**Candidate under review:** artifact `10548849094` / semantic source `ec348a1d13f96764da5674b66a3ce314a4a8c2cb`
**Decision:** **valid product RED / existing `RP-01 AUTHORITY_DOMAIN_CONFLATION` / source-boundary alias versus per-region boundary ownership / NON-STABLE**. CB22 successfully removes R8's invalid hand-authored field authority, so `RP-02` is closed as a test-authority correction, but R9 exposes a different product-domain ambiguity before the target center singularity is published. Exact successor is runtime-free `M4-CP-SCALE-DEFN-R1`.

## 1. Primary R9 evidence independently re-derived

Review re-opened the immutable CB22 package and R9 evidence rather than accepting the EXEC report as self-proving.

- Authoritative R9 run/job: `35353935259 / 105628563418`; event SHA `c5375a4c4c453f23d3d3348d648d8dd76d8e8c11`.
- Candidate package artifact `10548849094` has provider/local ZIP SHA-256 `f63c20ab184e78fa0cabcd89df7844a6fdaeacdba31691f3d51b39fec9bb1aa5`; semantic source is `ec348a1d13f96764da5674b66a3ce314a4a8c2cb`; the root package manifest verifies **28/28**.
- R9 result/log artifacts `10550642712 / 10550482686` have provider/local SHA-256 `8a9bf09e1acc592c179cca2969419da242d44d7a1cba97b3d83410cc5702d650 / 3b953803a573daa7d6abe06f2d9af49b698c13d28ea95594695818ee3817b806`.
- The final ledger independently hashes to `254c0f2a6e89d5ebaad9c4534d5be699a34832dd7081a64c8b6476a9d528a41c` and contains exactly **1 RED + 435 UNEXECUTED** rows. The only executed row is A0/1 `FieldTransportAtlas.SeparatingHardFeatureSingularityOwnsCanonicalBoundaryCycle`, selected once, skipped zero, exit `1`.
- Raw stdout reports `code=SingularityMismatch;sourceVertex=1;topologyRegion=1` at the test's `ASSERT_TRUE(built)`; raw stderr is empty.
- R9 package/source/execution-view pre/post censuses are byte-identical. Their independently re-hashed preflight SHA-256 are `aebb0fc257d38aee38e593c0a207b3292ba36cf8c242c672cbfeee935dc0143e`, `21a4447052bb41f9ec5997e695f576661fc2fd6a25ddaa82d83de44e841040c1`, and `fe6efcc10eb9d07f20c0f6537bbfa43f93bbb18e37c497985d90b48fcaa93813`.
- Execution boundary is valid semantic evidence: `semantic_red=true`, `orchestration_failure=false`, `runtime_started=true`, `postflight_complete=true`; benchmark/configure/compile/relink/discovery/package-repair/mode-repair/mutation are all zero.

The accepted selector is independently re-hashed from packaged source: selector426 is **426 LF rows**, SHA-256 `41f4d559211375c11c8d1f8c9ccde2581db75819d9409366e8f2695b008b5114`; exact first425 is `e0e0f394faae536ac257ec5409653a34755a8afe0ca437562eb44c9895790e0b`. The R9 identity map independently re-derives **30 authority-kernel / 280 producer / 75 completion / 41 validation**. Retained genus-two OBJ/rawfield/metadata independently remain `c6bacd981fb0559dc3e290ee1367b9e369f4657b189ce288ce732461d8caeab3 / 7bd71837954ded74461a46d65761b953cbc186978639d41567ad4a4aac4af70e / 22600270cc11b7b421007e10a3861124c4238bc0e5353b2637a9c70005bf1b76`. No selector427 is published.

A fresh source snapshot at `dedcce97fe62719e1078cfdd5f73065d742cb0cb` was also materialized under run `35355799755`. Static comparison of `src`, `include`, `tests`, `benchmarks`, `cmake` and root `CMakeLists.txt` against the packaged semantic source shows **no code-surface drift**, so the local static trace below is valid for the exact candidate bytes.

## 2. CB22's producer-consistent replacement is valid; R8 `RP-02` is discharged

CB22 did what R8 Review required. The replacement control authors only nondegenerate per-face cross directions on `make_skew_four_triangle_fan()`, then delegates matching, effort and singularity production to `CartesianField` -> `make_raw_cross_field` -> `finalize_cross_field_result`. The helper independently re-measures every interior edge transition and re-derives the center cycle index. It proves center vertex `4` is the sole **interior** singularity with numerator `+1`; it does not hand-write transition or singularity authority.

The control also independently establishes the intended owner discriminator before atlas construction: hard edges `(1,4)` and `(3,4)` split faces into exactly `{0,3}` and `{1,2}`, both are separating cuts and neither is a same-region slit, and the stable minimum incident owner region is a two-triangle disc with one boundary loop, no local interior vertex and relative `turningLift=4 != +1`.

Therefore the R8 failure mechanism — a constant planar field with an injected nonzero transition and handwritten companion singularity — is absent. `M4-CP-SCALE-TB12-R8-EXEC-CAND-01 / RP-02` is **CLOSED / TEST-AUTHORITY CORRECTION ESTABLISHED / NON-STABLE**. This does **not** make A0 row1 green: the corrected subject now reaches a different legitimate product seam first.

## 3. The R9 locus is a source-boundary alias / regional-boundary ownership collision

The observed locus is statically diagnostic, not ambiguous.

The skew fan's source-boundary vertices are `0,1,2,3`; center `4` is interior. `dual_cycles(...)` maps every vertex of one source boundary loop to the **same** aggregate cycle row. `effort_to_indices(CartesianField&)` then projects that cycle index back through `local2Cycle` and emits one `singularCycles` entry for every vertex whose mapped index is nonzero. Thus a nonzero source-boundary loop fact appears as several vertex-keyed **aliases of one global boundary-cycle index**, an inherited representation already captured by `LESSONS.md` 42.

`FieldTransportAtlas::make(...)` first splits those entries by the **global source mesh** into `rawBoundarySingularity` versus interior `rawSingularity`. During regional atlas construction it then scans each region's local boundary loops. For any globally-boundary vertex present in `rawBoundarySingularity`, it inserts exactly one `(TopologyRegionId, FieldCycleId)` into:

`boundaryCycleByGlobalVertex : source vertex -> one regional BoundaryLoop owner`.

The corrected hard-feature subject makes vertex `1` lie on both regional boundary loops: region `{0,3}` and region `{1,2}` both contain it. The first region inserts one owner; the second region attempts a different owner and the map rejects the second insertion as `SingularityMismatch`, reporting the **current second region**. The observed `sourceVertex=1;topologyRegion=1` is therefore exactly the duplicate-regional-owner branch. The later final boundary-alias check would instead report the retained owner's region, so the region-1 locus distinguishes this earlier collision.

This is a product assumption failure: **one global source-boundary-loop alias is being forced into one per-region boundary-loop owner slot after hard-feature cuts make that alias incident to more than one regional loop**. Vertex-key identity is not sufficient authority for choosing one regional semantic owner.

There is a second reason not to patch the map by merely choosing the minimum region. The current final reconciliation requires the selected regional `BoundaryLoop.turningLift` to equal the raw source-boundary numerator. Those quantities live in different domains once region-level boundary corrections are applied: the raw alias comes from the global source boundary cycle, while each regional loop is a relative cycle of the cut topology. R7 already established the analogous invalid equality for a globally-interior separating singularity. Picking a deterministic regional owner would make the duplicate insertion green while leaving this cross-domain numeric assertion undefined.

## 4. Classification and definition-stop adjudication

`M4-CP-SCALE-TB12-R9-EXEC-CAND-01` is classified:

> **OPEN / PRODUCT / SOURCE-BOUNDARY-ALIAS vs PER-REGION BOUNDARY OWNERSHIP DOMAIN CONFLATION / existing `RP-01 AUTHORITY_DOMAIN_CONFLATION` / NON-STABLE.**

This is a new observed locus but **not a third distinct product root cause** on the S5 path. It is another manifestation of the already open RP-01 authority-domain family:

- R4: separating hard-feature region boundary was conflated with same-region slit ownership;
- R7: a global source-vertex singularity numerator was conflated with a region-relative boundary-loop lift;
- R9: a global source-boundary-loop alias is forced to choose one of multiple region-relative boundary loops, and the surviving path still proposes global-numerator == regional-lift equality.

The frozen count-based escalation threshold therefore does **not** fire by cardinality. However, another bounded product CB is still not safely specifiable. The inherited CP2b rule says aliased boundary-vertex entries must be reconciled against their typed boundary-cycle owner before being collapsed, but hard-feature region decomposition introduces several regional boundary loops for one global boundary-loop alias. Current frozen CP-SCALE definitions do not say which object owns that global alias after the cut, whether one regional cycle may be canonical semantic owner, or what exact invariant replaces the invalid global-to-relative lift equality.

That is an **authority-definition gap**, not an implementation detail. Review therefore routes to definition even though the third-distinct-cause counter remains unspent. The next turn must freeze the ownership/reconciliation invariant before any source patch.

Stable accounting remains **49 events / 14 categories / 35 recurrences**, produced-witness debt **5**. No accepted-green selector identity was lost. Candidate `10548849094` remains unpromoted. S5 and all 426 selector rows were unexecuted, so production `M4-CP-SCALE-TB12-R4-EXEC-CAND-01 / RP-01` remains OPEN, `M4-CP-SCALE-DEFN-OBS-04` remains carried, and S5/A3 receive zero credit.

## 5. Exact successor — `M4-CP-SCALE-DEFN-R1`

The exact successor is runtime-free `M4-CP-SCALE-DEFN-R1`, under `Architecture_M4_CP_SCALE_DEFN_R1_Source_Boundary_Alias_Reconciliation_Definition_Plan.md`.

It must freeze, without product/test/runtime mutation:

1. the semantic owner of a producer boundary-index fact when legacy `singularCycles` aliases one global source boundary cycle across several source vertices;
2. the relationship, if any, between that global owner and multiple region-relative `BoundaryLoop` witnesses created when hard-feature cuts meet the source boundary;
3. an exact reconciliation invariant that preserves the original global boundary fact without equating it to an unrelated regional correction;
4. the diagnostic/canonicalization rules needed when one alias vertex is incident to several regional loops, distinguishing deterministic storage identity from semantic ownership;
5. preservation obligations for the accepted uncut boundary-alias negative, CB21's interior separating-owner recovery, cycle-ordering controls, port-class arithmetic and accepted selector426 authority.

The definition turn must stop rather than choose a minimum regional owner by convenience, silently drop aliases, weaken `SingularityMismatch`, or use the source-boundary alias as an independent singularity port. Only after the invariant is frozen may one bounded Code + Build successor be authored.

## 6. Prior obligations discharged or carried

- `M4-CP-SCALE-TB12-R8-EXEC-CAND-01 / RP-02` — **DISCHARGED / CLOSED as test-authority correction**. CB22's field authority is producer-derived and independently re-measured; R9's new RED is product-owned rather than the former handwritten companion defect.
- `M4-CP-SCALE-TB12-R7-EXEC-CAND-01` — remains **CLOSED / DIRECT-CONTROL RECOVERY PROVED / NON-STABLE**. R9 does not reopen the center separating-owner correction; it stops earlier on a source-boundary alias.
- `M4-CP-SCALE-TB12-R4-EXEC-CAND-01 / RP-01` — **CARRIED / OPEN**. Original genus-two production S5 has still not rerun past the owner seam.
- `M4-CP-SCALE-DEFN-OBS-04` — **CARRIED / OPEN / NARROWED**. Source/genus/raw-field authority is supported; production atlas/A3 reachability remains unproved.
- `M4-CP-SCALE-TB2-REV-OBS-02` — **CARRIED / dedicated test-authority audit still owed**. CB22 removes this one invalid-helper use, but the broad `make_zero_transport_field` audit is unrelated to the boundary-alias definition and must not be folded into DEFN-R1.
- Inherited `G4-B002/G4-B003` debt and the separately owned CP3 observations remain unchanged.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | selector426 `41f4d559211375c11c8d1f8c9ccde2581db75819d9409366e8f2695b008b5114`; first425 `e0e0f394faae536ac257ec5409653a34755a8afe0ca437562eb44c9895790e0b`; 426 LF rows; owners 30/280/75/41 |
| Decisive claims independently re-derived | exact 1-RED/435-unexecuted ledger, raw row1 locus, immutable pre/post censuses, producer boundary-alias convention, and the unique sourceVertex1 regional-owner collision path |
| Non-vacuity checked | corrected field is producer-derived and independently measured; hard edges split exactly two regions; the product reaches regional boundary reconciliation and a one-owner map rejects the second real regional owner |
| Prior obligations discharged/carried | R8 `RP-02` discharged; R7 direct recovery remains closed; R4 `RP-01`, `DEFN-OBS-04`, `TB2-REV-OBS-02`, inherited debt/CP3 observations carried |
| Stable accounting | **49 events / 14 categories / 35 recurrences**, debt **5**; accepted package `10473134357` / selector426 **426/426** |
| New candidates/obligations recorded | R9 CAND-01 classified as existing `RP-01 AUTHORITY_DOMAIN_CONFLATION`; tracker updated; definition obligation assigned to `M4-CP-SCALE-DEFN-R1` |
| ORIENTATION currency line | `M4-CP-SCALE-TB12-R9-REV`, 2026-09-18 UTC written |
| ORIENTATION §3 / §4 / §7 / §8 | updated for R9 product classification, genus-two/S5 state, definition-first priority, RP-02 closure and the boundary-alias instance of existing RP-01 |
| CHANGELOG | R9 Review entry added |
| ROADMAP | CP-SCALE row updated; checkpoint still OPEN; exact next DEFN-R1 |
| Selector manifest | n/a — no selector added, replaced or accepted; selector426 remains byte-identical authority |
| LESSONS | no new number — existing lesson 42 (legacy alias collapse/reconcile) and lesson 65 (global/local boundary-domain split) directly cover the pattern |
| Consolidation under CLEAN_UP_POLICY | R8 Review, CB22 plan/report and consumed R9 plan/report folded/indexed in `M4_Consolidated_Record.md` §2.66; accepted TB11 report, frozen definitions, selectors, current R9 Review and one DEFN-R1 plan retained |
| Successor frozen | exactly `M4-CP-SCALE-DEFN-R1`; falsifiers/STOP rules are in its source-boundary-alias reconciliation plan |
| Turn boundary held | yes — runtime-free Review; no product/test/fixture/selector/benchmark/build-source mutation, compile or generated Directional runtime |
| review_check.py boundary | **PASS** on the prepared final Review diff; no product/test/build/fixture/selector mutation and selector bytes match baseline |
| `STATUS` lifecycle maintained | entry `2026-09-18T14:21:30Z`; resume `2026-09-18T14:39:26Z`; final COMPLETE beacon reserved as the last repository mutation |
| Pushed to origin, branch in sync | documentation application/cleanup must verify successful remote push and final branch authority immediately before the direct final `STATUS` write; no commit hash is embedded here |
