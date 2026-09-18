# M4-CP-SCALE-TB12-R8-REV — Independent Review Record

**Turn:** `M4-CP-SCALE-TB12-R8-REV`
**Type:** independent Review + Plan, runtime-free
**Reviewed predecessor:** `M4-CP-SCALE-TB12-R8-EXEC`
**Accepted runtime authority entering Review:** package `10473134357` / semantic source `e15e83c79a1e1962c0ed8d31ea85187ab6600e47` / selector426 **426/426**
**Candidate under review:** artifact `10542249210` / semantic source `ea7b15f53e5e92cb034c855d52c17eaa2d8928d1`
**Decision:** **rejected and replaced as test authority**. R8 is valid semantic evidence and recovery-proves CB21's direct separating-owner correction at target vertex 8, but the same direct control then fails on a separately hand-authored companion singularity whose matching/effort/singularity authority is inconsistent with its per-face field. The new RED is `RP-02 / TEST_AUTHORITY_COVERAGE_GAP`, non-stable, not a third product root cause. Exact successor is test-only `M4-CP-SCALE-CB22`.

## 1. Primary R8 evidence independently re-derived

Review re-opened the exact R8 result bytes and candidate package rather than accepting the EXEC report as self-proving.

- Authoritative run/job: `35338412117 / 105578569562`.
- Immutable candidate package: artifact `10542249210`, `m4-cp-scale-cb21-result-35334247422`, provider/local ZIP SHA-256 `a64352a9524c4f114865948bb84226a317eaa1affa2e7a7fcfeea62352c7ef6c`, semantic source `ea7b15f53e5e92cb034c855d52c17eaa2d8928d1`, source archive `7a8c8f9c866dfc51580975d64e6dda5001291780e666d1491a6aee2a39a858e7`, root manifest **28/28**.
- R8 result/log artifacts: `10543544280 / 10544295647`, provider SHA-256 `4fbbd1b1163067115b4a738c64b57c6e6a986474302813b6e1c7f3453aaf8db6 / b9d8370ac5b95560e751e6dba64694435149c8dec160d161397476aa1abcff5a`.
- The final ledger independently hashes to `a9aea1a0ba92f6889f2c50268c34b29b71c643e23a3a20ba8ff2844986b573e2` and contains exactly **1 RED + 435 UNEXECUTED** rows. The only executed row is A0/1 `FieldTransportAtlas.SeparatingHardFeatureSingularityOwnsCanonicalBoundaryCycle`, selected once, skipped zero, exit `1`.
- Raw stderr reports singularity id `1`, `sourceVertex=16`, `topologyRegion=1`, `incidences=4`, `classes=4`, `expectedClasses=5`; raw stdout reports `SingularityPortClassCountMismatch` at the test's `ASSERT_TRUE(built)`.
- Package/source/execution-view pre/post files are independently byte-identical with SHA-256 `b1c748ebe6c0df8a47a9b23b15daecab19208dc284885322650869e3790a8838`, `cea2c7e7675197198ce862f4ca6b3586839132fdc8deae15859a084e9f48a31e`, and `7bd6d8f29a9b290eb415c0ff8ef54c0249482d6f2379cc9dbf979d30de39eac1` respectively.
- Execution boundary is valid semantic evidence: `orchestration_failure=false`, `semantic_red=true`, `postflight_complete=true`, `benchmarkExecuted=0`; configure/compile/relink/discovery/package-repair/mode-repair/mutation flags are all zero.

The accepted selector is independently re-hashed from packaged source: selector426 is **426 LF rows**, SHA-256 `41f4d559211375c11c8d1f8c9ccde2581db75819d9409366e8f2695b008b5114`; exact first425 is `e0e0f394faae536ac257ec5409653a34755a8afe0ca437562eb44c9895790e0b`. Joining those 426 identities to the archived owner map re-derives **30 authority-kernel / 280 producer / 75 completion / 41 validation**. Retained genus-two OBJ/rawfield/metadata independently remain `c6bacd981fb0559dc3e290ee1367b9e369f4657b189ce288ce732461d8caeab3 / 7bd71837954ded74461a46d65761b953cbc186978639d41567ad4a4aac4af70e / 22600270cc11b7b421007e10a3861124c4238bc0e5353b2637a9c70005bf1b76`. No selector427 is published.

## 2. R8 recovery-proves the CB21 direct owner correction

The later error is not merely a changed error string. Exact control flow proves the target ownership seam advanced.

`rawSingularity` is a `std::map<int,int>`, so this fixture creates singularity facts in source-vertex order: target vertex `8` is singularity id `0`; companion vertex `16` is singularity id `1`. Before `build_singularity_attachments(...)` can run, every raw singularity must pass exact-one-owner reconciliation. The direct fixture independently established that vertex 8 has no same-region slit/local-barrier owner, so its only admissible owner path is the CB21 separating-feature `BoundaryLoop` owner. CB21 then marks that path `BarrierAbsorbed`.

`build_singularity_attachments(...)` iterates the already reconciled singularity facts and immediately skips every `BarrierAbsorbed` singularity. R8's partition diagnostic is for singularity id `1` / vertex `16`. Therefore vertex 8 already:

1. survived exact-one-owner reconciliation;
2. survived separating-owner kind/region/incidence validation;
3. was published with the separating owner and `BarrierAbsorbed`; and
4. was skipped before emitted-port partitioning.

Restoring CB18's deleted global-index/per-region-boundary-lift equality would stop at vertex 8 before this point, exactly as R7 did. The CB21 mismatch discriminator is therefore non-vacuous and the R7 direct `SingularityMismatch;sourceVertex=8` correction is **RECOVERY PROVED**.

This is direct-control recovery only. The original genus-two S5 path did not execute in R8, so `M4-CP-SCALE-TB12-R4-EXEC-CAND-01 / RP-01` remains open until fresh S5 runtime advances that production witness.

## 3. The new RED is invalid test authority, not evidence against the port classifier

The R8 failure belongs to the test's companion singularity, not the corrected target.

The direct control starts from `make_zero_transport_field(mesh)`, overwrites every face with the **same constant planar cross directions**, then manually edits exactly one radial edge `(8,16)` to `matching = +/-1` and `effort = +/-2*pi`. It copies those values into the edge transition and finally hand-writes `singularCycles = [8,16]` / `singularIndices = [+1,-1]`.

Those authorities are not mutually consistent. For identical cross directions on coplanar adjacent faces, the independent connection measurement is zero matching and zero effort. The test instead supplies a nonzero transition and uses that authored effort to make the source cycle integral report `+1/-1`. In other words, the fixture derives its asserted singularity indices from the same hand-authored transition that disagrees with the field directions; it never proves that an accepted cross-field producer could publish that `CrossFieldResult`.

The product's later check is exactly where that inconsistency becomes observable. Vertex 16 is declared index numerator `-1`, so the existing contract expects `4 - (-1) = 5` emitted port classes. The actual branch-sector/transport authority built from the field exposes four classes. Weakening `SingularityPortClassCountMismatch`, changing `4-index`, or special-casing this fixture would convert an invalid test precondition into product semantics and is prohibited.

The repository already contains the correct fixture pattern. `make_skew_index_one_singularity_field(...)` authors only nondegenerate per-face cross directions, delegates matching/effort/singularities to `CartesianField` + `make_raw_cross_field` + `finalize_cross_field_result`, and then independently re-measures every interior transition and the center cycle index. That producer-consistent helper is accepted by `PublishesCheckedSingularityPortAttachments` and provides the smallest safe basis for repairing the separating-owner control.

## 4. Candidate disposition and root-cause classification

`M4-CP-SCALE-TB12-R8-EXEC-CAND-01` is reclassified:

> **OPEN / TEST-AUTHORITY INVALID COMPANION-SINGULARITY PRECONDITION / `RP-02 TEST_AUTHORITY_COVERAGE_GAP` / NON-STABLE.**

The invalid authority is the manually fabricated matching/effort/singularity pair on a constant planar field. The falsifier is a replacement direct owner control whose `CrossFieldResult` is produced by the accepted field producer and independently re-measured before atlas construction, while preserving the same separating-owner behavior, lift/index mismatch and stable-ID canonicalization contract.

`M4-CP-SCALE-TB12-R7-EXEC-CAND-01` becomes **CLOSED / DIRECT-CONTROL RECOVERY PROVED / NON-STABLE** because R8 reaches the attachment phase past its target vertex. The broader R4/S5 `RP-01` candidate remains **OPEN / PRODUCT / NON-STABLE** because S5 was not reached.

This is not a third distinct product root cause. The frozen definition-escalation stop counts product causes on the S5 path; R8 did not reach S5 and the new failure is test-authority divergence. No definition turn is triggered.

Stable accounting remains **49 events / 14 categories / 35 recurrences**, produced-witness debt **5**. No accepted-green row was lost. Accepted runtime authority remains package `10473134357` / selector426 **426/426**; CB21 artifact `10542249210` remains unpromoted; S5/A3 remain uncredited.

## 5. Smallest sufficient replacement fixture

Review rejects another ad-hoc patch to the five-ring synthetic field. The smallest existing producer-consistent subject is the accepted skew four-triangle fan.

CB22 must replace only the field/test authority inside `SeparatingHardFeatureSingularityOwnsCanonicalBoundaryCycle` using this construction:

- source mesh: `make_skew_four_triangle_fan()`;
- target: center source vertex `4`, already independently certified by `make_skew_index_one_singularity_field(...)` as the **only interior singularity** with numerator `+1`;
- separating hard features: radial source edges `(1,4)` and `(3,4)`.

The source face adjacency is then cut into exactly two regions `{0,3}` and `{1,2}`. Both hard edges separate those two regions, center vertex 4 is globally interior and incident to both regions, and neither hard edge is a same-region local slit. Each two-triangle region is a disc with no local interior vertex and one boundary loop; the independent cycle oracle therefore applies the region index correction to that loop, giving relative boundary lift `4`, which is deliberately distinct from the global center numerator `+1`. This retains CB21's decisive mismatch discriminator without fabricating a second singularity.

The source-face-row permutation control must preserve the **same field by source-face topology**, not reassign angle values by new row index. After remapping the baseline per-face primary/secondary directions to the permuted rows, regenerate matching/effort/singularities through the accepted field producer and independently certify the same single center `+1` singularity before invoking the atlas. Reversing rows while calling a row-index-driven angle helper unchanged would change the semantic subject and is not an admissible canonicalization control.

## 6. Authoritative successor — `M4-CP-SCALE-CB22`

The authoritative Code + Build plan is `Architecture_M4_CP_SCALE_CB22_Separating_Owner_Test_Authority_Correction_Code_Build_Plan.md`.

CB22 is **test-authority only**. Production `FieldTransportAtlas.cpp` is frozen. The plan authorizes only `tests/FieldTransportAtlasTests.cpp`, reuses the accepted skew witness support unchanged, compiles/packages all eight standard targets under GMP/GMPXX, and executes no generated Directional runtime.

If compile/package is green, CB22 must freeze a fresh artifact-only R9 plan with the unchanged fail-fast runtime order:

```text
Gate A0 5 -> Gate A 4 -> S5 1 -> selector426 426 only if all ten focused rows are green
benchmark 0
exact immutable postflight required
```

R9 must first prove the corrected direct owner control. Only then may it reach the unchanged production S5 witness. Any valid semantic RED routes to mandatory Review before another correction.

## 7. Carried obligations

- `M4-CP-SCALE-TB12-R4-EXEC-CAND-01 / RP-01` — **OPEN**, production S5 retry still owed.
- `M4-CP-SCALE-DEFN-OBS-04` — **OPEN / NARROWED**; genus-two source/topology/raw-field authority is established, production atlas/A3 remains unproved.
- S1 calibration `TB1-REV-OBS-01`, TB2 zero-transport-helper audit `TB2-REV-OBS-02`, S2 arrival fallback `DEFN-OBS-01`, three M4 `G4-B002` produced-witness debts and existing CP3/audit observations retain their current owners.
- No selector or closure status changes in this Review.

## 8. Consolidation

Review folds the superseded/consumed CP-SCALE per-turn documents into `M4_Consolidated_Record.md` §2.65 after preserving their durable facts. Retained role set is: normative CP-SCALE frozen definitions; accepted TB11 runtime-authority report; this R8 Review record; exactly one CB22 plan; all byte-frozen selectors; M4 consolidated record; tracker/changelog and durable project authority.

| Folded filename | Lines | Disposition / retained home |
|---|---:|---|
| `Architecture_M4_CP_SCALE_CB21_Separating_Hard_Feature_Owner_Eligibility_Code_Build_Plan.md` | 101 | **CONSUMED/FOLDED BY R8 REVIEW.** CB21 bounded product/test contract and STOP rules retained in §2.64/§2.65 and this Review. |
| `Architecture_M4_CP_SCALE_CB21_Code_Build_Report.md` | 129 | **SUPERSEDED/FOLDED BY R8 REVIEW.** Candidate source/package provenance and exact correction retained in §2.65, tracker and changelog. |
| `Architecture_M4_CP_SCALE_TB12_R7_Review_Record.md` | 199 | **SUPERSEDED/FOLDED BY R8 REVIEW.** R7 RP-01 adjudication and CB21 contract retained in §2.64/§2.65, tracker and git history. |
| `Architecture_M4_CP_SCALE_TB12_R8_Artifact_Only_Test_Benchmark_Plan.md` | 177 | **CONSUMED/FOLDED BY R8 REVIEW.** Frozen 436-row fail-fast/postflight contract realized by R8 evidence and retained in §2.65/current Review. |
| `Architecture_M4_CP_SCALE_TB12_R8_Artifact_Only_Test_Benchmark_Report.md` | 133 | **ADJUDICATED/FOLDED BY R8 REVIEW.** Primary R8 semantic evidence independently retained in §§1–4 and §2.65; it is not accepted runtime authority. |

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | selector426 = `41f4d559211375c11c8d1f8c9ccde2581db75819d9409366e8f2695b008b5114`; exact first425 = `e0e0f394faae536ac257ec5409653a34755a8afe0ca437562eb44c9895790e0b`; owner census independently re-derived as **30/280/75/41** |
| Decisive claims independently re-derived | R8 1 RED + 435 UNEXECUTED ledger; raw vertex16 class-count diagnostic; exact owner/attachment control-flow ordering; target8 separating-only owner preconditions; constant-planar-field versus manually authored nonzero transition inconsistency; producer-consistent skew witness construction |
| Non-vacuity checked | R8 proves old CB18 equality cannot be restored because target8 reaches past owner reconciliation; CB22 replacement has two competing incident regions, relative boundary lift `4 != +1`, and must preserve field semantics under row permutation |
| Prior obligations discharged/carried | R7 direct candidate CLOSED recovery-proved; R4/S5 `RP-01` carried OPEN; `DEFN-OBS-04` carried/narrowed; S1/S2/G4-B002/CP3 obligations retain existing owners |
| Stable accounting | unchanged **49 events / 14 categories / 35 recurrences**, debt **5**; accepted package `10473134357` / selector426 **426/426**; CB21 candidate unpromoted |
| New candidates/obligations recorded | R8 candidate classified `RP-02 TEST_AUTHORITY_COVERAGE_GAP`, invalid companion-singularity authority, non-stable; corrective owner `M4-CP-SCALE-CB22` |
| ORIENTATION currency line | `M4-CP-SCALE-TB12-R8-REV`, 2026-09-18 UTC |
| ORIENTATION §3 / §4 / §7 / §8 | §3/§7/§8 updated for direct RP-01 recovery plus new RP-02 test-authority correction; §4 unchanged because no production witness state changed |
| CHANGELOG | R8 Review adjudication, accounting and CB22 successor added |
| ROADMAP | CP-SCALE status updated to R8 Review disposition and CB22 next; checkpoint remains OPEN |
| Selector manifest | n/a — no selector added, replaced or accepted; selector426 remains byte-identical authority |
| LESSONS | no new number — existing invalid-fixture/authority-surface rules plus lessons 145/150/153 and existing `RP-02` cover this recurrence |
| Consolidation under CLEAN_UP_POLICY | CB21 plan/report, superseded R7 Review, consumed R8 plan and adjudicated R8 report folded/indexed in `M4_Consolidated_Record.md` §2.65 |
| Successor frozen | exactly `M4-CP-SCALE-CB22`; test-only producer-consistent skew witness, falsifiers and STOP conditions are in the CB22 plan |
| Turn boundary held | yes — runtime-free Review; no product/test/fixture/selector/benchmark/build-source mutation, compile or generated Directional runtime |
| review_check.py boundary | **PASS** on the prepared final Review diff; no product/test/build/fixture/selector source mutation and durable markers preserved |
| `STATUS` lifecycle maintained | entry beacon `2026-09-18T12:12:14Z`; final COMPLETE beacon reserved as the last repository mutation after publication/cleanup verification |
| Pushed to origin, branch in sync | connector/workflow environment has no persistent local origin checkout; documentation application must verify successful push and final remote branch authority before the direct final `STATUS` write |

---

## Independent verification addendum (reviewing agent)

Runtime-free. **Upheld, no correction.** Accounting and accepted authority unchanged; accepted package
`10473134357` / selector426 **426/426**.

### V1 — the recovery proof is genuine, and honestly scoped

§2 does not argue from a changed error string, which is the weak form of this claim. It argues from control flow:
`rawSingularity` is a `std::map<int,int>` so target vertex 8 is singularity id 0, `build_singularity_attachments`
skips every `BarrierAbsorbed` singularity, and R8's partition diagnostic places vertex 8 past exact-one-owner
reconciliation, past separating-owner kind/region/incidence validation, published with the separating owner, and
skipped before emitted-port partitioning.

The decisive sentence is the counterfactual: restoring CB18's deleted global-index/per-region-lift equality would
halt at vertex 8 *before* that point, **exactly as R7 did**. That is grounded in observed prior behaviour rather
than asserted, so the equality removal is demonstrated rather than inferred.

The scoping is equally correct: this is direct-control recovery only, the genus-two S5 path did not execute in R8,
and `TB12-R4-EXEC-CAND-01 / RP-01` stays OPEN until fresh S5 runtime advances it. Proving a correction is not
proving the path.

### V2 — the stop condition was evaluated a third time, and correctly declined

The handoff threshold — a **third distinct product root cause** on this S5 path routes to a definition turn — is
again addressed head-on and correctly found not to fire. This RED is `RP-02 / TEST_AUTHORITY_COVERAGE_GAP` in the
test's own companion singularity, not a product cause at all. CB22 is test-authority only and production
`FieldTransportAtlas.cpp` is frozen, so the semantic-attempt count at the ownership seam does not advance either.
The threshold remains live and unspent.

§5's refusal to patch the five-ring synthetic again, in favour of the already-certified skew fan where the
singularity is **derived by `make_skew_index_one_singularity_field(...)` rather than hand-authored**, is the right
correction and the same pattern that fixed the S2 winding defect: stop authoring what production must derive. The
permutation control's requirement to preserve the same field *by source-face topology* rather than reassigning
angles by new row index is a real subtlety and worth having stated.

### V3 — `TB2-REV-OBS-02` is now implicated a third time and should be given a turn

The failing direct control is a `make_zero_transport_field` caller
(`tests/FieldTransportAtlasTests.cpp:2494`). §3's diagnosis is that it declares zero matching and zero effort
beneath a hand-authored index numerator of `-1` at vertex 16 — authorities that cannot both hold, since identical
cross directions on coplanar adjacent faces measure zero connection.

That is the **same silent precondition** this reviewer opened `TB2-REV-OBS-02` against: the helper is valid only
where the declared topology requires no transport. Counting the instances:

1. `M3-CP4c3-TB7-CAND-02` — historical invalid folded-cone witness;
2. `M4-CP-SCALE-TB12-R2` — zero effort on a non-flat cone vertex, `K = π/2`;
3. this RED — zero effort beneath a declared index `-1`.

Three failures, each costing a Code + Build plus artifact-only execution round trip, against one assertion inside
one helper. The call-site count has meanwhile grown from **35** when the obligation was opened to **37** today.

The obligation has been carried correctly each time and each deferral was individually right — CB17, CB18, CB21
and now CB22 all had bounded scopes that should not have absorbed it. But "the next legitimate touch" has now
permitted three deferrals, and a phrase that never resolves is not an owner. **Recommend scheduling the helper
audit as its own turn** rather than carrying it against an unspecified future touch.

Explicitly **not** for CB22: its evidential value depends on being a bounded fixture replacement, and widening it
to 37 call sites would forfeit that (`LESSONS.md` 170). CB22 removing one caller is a side benefit, not the audit.
